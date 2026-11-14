#!/usr/bin/env python3
"""Batch binding of stand-in calls to the recipe's row owners (README.md).

usage:
  bind_batch.py gate CANDIDATES BUILD_DIR OUT_DIR --recipe UNITS_JSON --differing FILE --undefined FILE
                [--jobs N]
  bind_batch.py prove OUT_DIR BUILD_DIR [--only NAMES] [--jobs N]
  bind_batch.py apply OUT_DIR ROOT --stage moves [--only NAMES]
  bind_batch.py apply OUT_DIR ROOT --stage bind --table FILE --batch NAME [--only NAMES] [--recipe UNITS_JSON]

gate reads each requiring unit's declarations with clang's JSON AST dump
(the unit's compile command, syntax only) and decides ADMIT or REFUSE per
call site, from the declarations, the recipe, the differing-definitions
names and the tip's forced-unlimited undefined names only. It writes
OUT_DIR/gate.tsv and OUT_DIR/gate.json, with the sha256 of each unit's text,
and deletes the proof files and proof/ folder of an earlier gate.

prove compiles each admitted name's rewrite with tools/object-proof at the
unit's flags, /Ob0 and /Od /Gy, one name at a time and then all of a unit's
proved names together, reads objcmp.py's verdict, and compares the unit's
record layouts on windows-x64 and i686. It writes OUT_DIR/proof.tsv,
OUT_DIR/proved.txt and OUT_DIR/rows.tsv. It writes nothing when a unit's
text no longer has the gate's sha256.

apply writes the rewrite of the names in OUT_DIR/proved.txt (and --only)
into ROOT: the verbatim moves (--stage moves), or the moves and the call
edits with the recipe keys and the check rows (--stage bind). It writes
nothing unless every text, key and row is ready and every unit's text has the
gate's sha256.

Exit status: 0 done, 1 a write was refused, prove has not run or a unit's
text changed since the gate, 2 usage error or unreadable input.
"""
import collections
import hashlib
import json
import os
import re
import shlex
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

HERE = os.path.dirname(os.path.abspath(__file__))
PROOF = os.path.join(HERE, "..", "object-proof", "proof.py")
OBJCMP = os.path.join(HERE, "..", "object-proof", "objcmp.py")
FUNCS = {"FunctionDecl", "CXXMethodDecl", "CXXConstructorDecl", "CXXDestructorDecl", "CXXConversionDecl"}
RECORDS = {"CXXRecordDecl", "ClassTemplateSpecializationDecl", "ClassTemplatePartialSpecializationDecl"}
TEMPLATES = {"FunctionTemplateDecl", "ClassTemplateDecl", "ClassTemplatePartialSpecializationDecl",
             "ClassTemplateSpecializationDecl", "VarTemplateDecl"}
CASTS = {"CStyleCastExpr", "CXXStaticCastExpr", "CXXReinterpretCastExpr"}
TYPES = {"CXXRecordDecl", "EnumDecl", "TypedefDecl", "TypeAliasDecl"}
MOVE_DEPENDENCIES = 3
INTEGERS = {"int", "unsigned int", "char", "signed char", "unsigned char", "short", "unsigned short",
            "long", "unsigned long", "__int64", "unsigned __int64"}
VARIANTS = ("flags", "ob0", "od")
PROOF_FILES = ("proof.tsv", "proved.txt", "rows.tsv")


# ---------------------------------------------------------------- signatures

def demangle(names, undname):
    """Microsoft names -> llvm-undname text (None when it cannot)."""
    names = sorted(set(names))
    if not names:
        return {}
    out = subprocess.run([undname], input="\n".join(names) + "\n", capture_output=True, text=True).stdout
    result = dict.fromkeys(names)
    for block in (b.strip("\n").split("\n") for b in out.split("\n\n") if b.strip()):
        if block[0] in result and len(block) > 1 and not block[1].startswith("error"):
            result[block[0]] = block[1]
    return result


def strict_key(text):
    """A demangled name without calling convention and __ptr64: the census's key that joins a
    32-bit recipe spelling with its windows-x64 spelling."""
    text = re.sub(r"\b(__cdecl|__thiscall|__stdcall|__fastcall|__vectorcall)\b ?", "", text)
    return re.sub(r"\s+", " ", text.replace(" __ptr64", "")).strip()


def depth_split(text, sep):
    parts, depth, cur, i = [], 0, "", 0
    while i < len(text):
        ch = text[i]
        if ch in "<([":
            depth += 1
        elif ch in ">)]":
            depth -= 1
        if depth == 0 and text.startswith(sep, i):
            parts.append(cur)
            cur, i = "", i + len(sep)
            continue
        cur += ch
        i += 1
    parts.append(cur)
    return parts


def depth0(text, pattern):
    """The first match of PATTERN that starts outside every (), <> and [] of TEXT, or None."""
    depth = 0
    for i, ch in enumerate(text):
        if ch in "<([":
            depth += 1
        elif ch in ">)]":
            depth -= 1
        elif depth == 0:
            m = pattern.match(text, i)
            if m and (i == 0 or not (text[i - 1].isalnum() or text[i - 1] == "_")):
                return m
    return None


CALLING_CONVENTION = re.compile(r"(__cdecl|__vectorcall|__stdcall|__fastcall|__thiscall|__clrcall)\b")


def signature(dem):
    """Parse a demangled windows-x64 function name. Types keep their full spelling, so two
    declarations of one translation unit have equal strings exactly when the types are equal.
    None unless the function's own calling convention stands outside every bracket, as it does
    for any function that returns no function pointer."""
    s = dem.replace(" __ptr64", "")
    m = re.match(r"^(?:(public|protected|private): )?(static )?(virtual )?(.*)$", s)
    access, static, virtual, rest = m.groups()
    cc = depth0(rest, CALLING_CONVENTION)
    if not cc:
        return None
    ret, tail = rest[:cc.start()].strip(), rest[cc.end():].strip()
    close = tail.rfind(")")
    depth, open_ = 0, -1
    for i in range(close, -1, -1):
        depth += {")": 1, "(": -1}.get(tail[i], 0)
        if depth == 0:
            open_ = i
            break
    if close < 0 or open_ < 0:
        return None
    params = tail[open_ + 1:close].strip()
    parts = depth_split(tail[:open_], "::")
    scope, base = parts[:-1], parts[-1]
    last = scope[-1].split("<")[0] if scope else ""
    special = base == last or base.startswith("~") or base.startswith("operator")
    return dict(member=bool(access) and not static, static=bool(static), virtual=bool(virtual),
                cc=cc.group(1), ret=ret, scope="::".join(scope), base=base, special=special,
                params=[] if params in ("", "void") else [p.strip() for p in depth_split(params, ",")],
                quals=tail[close + 1:].strip())


# ---------------------------------------------------------------- the recipe

def load_recipe(path):
    with open(path, encoding="utf-8") as f:
        return json.load(f)


def recipe_index(recipe):
    """Every entry of a source merged: source -> {key: address}; address -> function row symbol."""
    syms, rows = collections.defaultdict(dict), {}
    for unit in recipe["units"]:
        for key, address in unit["symbols"].items():
            syms[unit["source"]].setdefault(key, set()).add(int(address, 16))
        for row in unit["functions"]:
            rows.setdefault(int(row["address"], 16), (unit["source"], row["symbol"]))
    return syms, rows


def respell_keys(recipe, source, address, old, new):
    """Respell the symbols key OLD of SOURCE as NEW at ADDRESS, in place and in order, in every
    entry of the source that holds it; drop it instead where the source (any entry) already has
    NEW. Raises ValueError, changing nothing, when no entry holds OLD, or an entry holds OLD or
    NEW at another address."""
    a = int(address, 16)
    entries = [u for u in recipe["units"] if u["source"] == source]
    holders = [u for u in entries if old in u["symbols"]]
    has_new = [u for u in entries if new in u["symbols"]]
    if not holders or any(int(u["symbols"][old], 16) != a for u in holders) \
            or any(int(u["symbols"][new], 16) != a for u in has_new):
        raise ValueError("%s: key %s is not held at %s alone, or %s is bound elsewhere" % (source, old, address, new))
    for u in holders:
        if has_new:
            del u["symbols"][old]
        else:
            u["symbols"] = {(new if k == old else k): v for k, v in u["symbols"].items()}


def recipe_check(syms, rowsyms, dem32, dem64, unit, n, d, address):
    """(refusal, detail) or (None, (key, row symbol)): the requiring unit's merged symbols keys
    must hold exactly one key whose demangled name is the stand-in's (calling convention and
    __ptr64 aside) and whose addresses, over every entry of the source, are exactly ADDRESS; the
    function row at ADDRESS must be the owner, compared the same way."""
    if not re.fullmatch(r"0x[0-9a-fA-F]+", address):
        return "recipe:address", address
    a = int(address, 16)
    nk = [k for k, v in syms.get(unit, {}).items() if v == {a} and dem32.get(k)
          and dem64.get(n) and strict_key(dem32[k]) == strict_key(dem64[n])]
    row = rowsyms.get(a)
    if len(nk) != 1:
        return "recipe:no-key", "%d keys of the name at %s" % (len(nk), address)
    if not row or not dem32.get(row[1]) or not dem64.get(d) or strict_key(dem32[row[1]]) != strict_key(dem64[d]):
        return "recipe:no-row", "the row at %s is %s" % (address, row[1] if row else "none")
    return None, (nk[0], row[1])


# ---------------------------------------------------------------- extraction

def compile_entry(build_dir, unit):
    with open(os.path.join(build_dir, "compile_commands.json"), encoding="utf-8") as f:
        entries = json.load(f)
    found = [e for e in entries if e["file"].replace("\\", "/").endswith("/" + unit)
             and "/game.dir/" in e.get("output", e.get("command", ""))]
    return found[0] if len(found) == 1 else None


def dump_command(entry):
    words = entry["arguments"] if "arguments" in entry else shlex.split(entry["command"])
    at = words.index("--")
    keep = [w for w in words[:at] if not w.startswith(("/Fo", "/Fd", "-Fo")) and w != "-c"]
    return keep + ["/Zs", "-w", "-Xclang", "-ast-dump=json"] + words[at:]


def is_main(loc):
    """A location in the unit's own file: an offset, not a macro and not an included file."""
    return bool(loc) and "offset" in loc and "includedFrom" not in loc and "spellingLoc" not in loc


def is_macro(loc):
    return bool(loc) and ("spellingLoc" in loc or "expansionLoc" in loc)


def span(node):
    """(begin, end) byte offsets of a node in the unit's file, end past the last token; None
    when either end is elsewhere."""
    r = node.get("range", {})
    b, e = r.get("begin", {}), r.get("end", {})
    if not (is_main(b) and is_main(e)):
        return None
    return b["offset"], e["offset"] + e.get("tokLen", 0)


def strip_implicit(node, kinds=("ImplicitCastExpr", "ParenExpr")):
    casts = []
    while node.get("kind") in kinds:
        if node["kind"] == "ImplicitCastExpr":
            casts.append(node.get("castKind"))
        node = node["inner"][0]
    return node, casts


def chain_of(path):
    """The declaration context of a node: [(kind, name, id, span)] of its namespace, linkage
    and record ancestors, outermost first."""
    out = []
    for n in path[:-1]:
        k = n.get("kind")
        if k == "NamespaceDecl" or k == "LinkageSpecDecl" or k in RECORDS or k in TEMPLATES or k in FUNCS:
            out.append((k, n.get("name", ""), n.get("id"), span(n)))
    return out


def extract(entry, names, owners, item_texts=None):
    """Read a unit's JSON AST dump and keep what the gate needs about the declarations of NAMES
    and OWNERS (windows-x64 mangled) and the references to NAMES. The dump's top-level items
    are split by their indentation; only items that mention a wanted simple name are parsed."""
    simple = {re.match(r"^\?+([^@]+)@", n).group(1) for n in names | owners if re.match(r"^\?+[^@]+@", n)}
    decls, refs, types, funcs, items = collections.defaultdict(list), [], [], [], 0
    if item_texts is None:
        proc = subprocess.Popen(dump_command(entry), cwd=entry["directory"], stdout=subprocess.PIPE,
                                stderr=subprocess.DEVNULL, text=True, errors="replace")
        lines = proc.stdout
    else:
        proc, lines = None, iter(item_texts)
    buf = None
    for line in lines:
        if buf is None:
            if line.rstrip("\n") == "    {":
                buf = [line]
            continue
        buf.append(line)
        if line.rstrip("\n").rstrip(",") == "    }":
            text = "".join(buf).rstrip().rstrip(",")
            buf = None
            items += 1
            if any(('"' + s + '"') in text for s in simple):
                walk(json.loads(text), items, names, owners, simple, decls, refs, types, funcs)
            else:
                # Only the item's own attributes: enough to list a type it declares.
                cut = text.find('\n      "inner": [')
                head = json.loads(text if cut < 0 else text[:cut].rstrip().rstrip(",") + "\n}")
                if head.get("kind") in TYPES:
                    types.append(type_decl(head, [head], items))
    if proc is not None:
        proc.stdout.close()
        if proc.wait() != 0:
            return None
    return dict(decls=decls, refs=refs, types=[t for t in types if t["span"] and t["name"]], funcs=funcs)


def type_decl(node, path, index):
    return dict(name=node.get("name", ""), kind=node["kind"], span=span(node), item=index,
                complete=bool(node.get("completeDefinition")),
                chain=[(k, n, None, None) for k, n, _, _ in chain_of(path)])


def walk(item, index, names, owners, simple, decls, refs, types, funcs):
    stack, path = [(item, 0)], []
    while stack:
        node, depth = stack.pop()
        del path[depth:]
        path.append(node)
        kind = node.get("kind")
        if kind in FUNCS and node.get("mangledName") in names | owners:
            parent_kinds = [n.get("kind") for n in path[:-1]]
            decls[node["mangledName"]].append(dict(
                id=node["id"], kind=kind, item=index, span=span(node), chain=chain_of(path),
                scoped=not any(k in FUNCS or k == "FriendDecl" for k in parent_kinds),
                body=any(c.get("kind") == "CompoundStmt" for c in node.get("inner", [])),
                virtual=bool(node.get("virtual")), implicit=bool(node.get("isImplicit")),
                record=next(({"id": n["id"], "name": n.get("name"), "kind": n["kind"], "span": span(n),
                              "complete": bool(n.get("completeDefinition")), "chain": chain_of(path[:i + 1]),
                              "item": index}
                             for i, n in reversed(list(enumerate(path[:-1]))) if n.get("kind") in RECORDS), None)))
        if (kind in FUNCS or kind == "FunctionTemplateDecl") and node.get("name") in simple \
                and not node.get("isImplicit"):
            # Every declaration of a wanted simple name, to find an owner overloaded in its scope.
            rec = next((n for n in reversed(path[:-1]) if n.get("kind") in RECORDS), None)
            funcs.append(dict(name=node["name"], mangled=node.get("mangledName"), template=kind not in FUNCS,
                              record=rec["id"] if rec else None,
                              namespace=[n.get("name", "") for n in path[:-1] if n.get("kind") == "NamespaceDecl"],
                              scoped=not any(n.get("kind") in FUNCS or n.get("kind") == "FriendDecl"
                                             for n in path[:-1])))
        if kind in TYPES and (depth == 0 or path[-2].get("kind") == "NamespaceDecl"):
            types.append(type_decl(node, path, index))
        if kind == "MemberExpr" and node.get("name") in simple:
            refs.append(reference(node, node.get("referencedMemberDecl"), path, index))
        elif kind == "DeclRefExpr" and node.get("referencedDecl", {}).get("name") in simple:
            refs.append(reference(node, node["referencedDecl"].get("id"), path, index))
        for child in reversed(node.get("inner", [])):
            if isinstance(child, dict):
                stack.append((child, depth + 1))


def arg_facts(arg):
    core, casts = strip_implicit(arg)
    return dict(kind=core.get("kind"), casts=casts, value=core.get("value"),
                type=core.get("type", {}).get("desugaredQualType", core.get("type", {}).get("qualType")),
                default=arg.get("kind") == "CXXDefaultArgExpr")


def reference(node, target, path, index):
    """Facts of one reference: the call it is the callee of, the call's arguments and use, the
    receiver, the enclosing function and the ancestors used to place a move."""
    kind = node["kind"]
    r = node.get("range", {})
    ref = dict(target=target, kind=kind, item=index, macro=is_macro(r.get("begin")) or is_macro(r.get("end")),
               header=not (is_main(r.get("begin")) and is_main(r.get("end"))))
    call = None
    if kind == "MemberExpr" and len(path) >= 2 and path[-2].get("kind") == "CXXMemberCallExpr" \
            and path[-2]["inner"][0] is node:
        call, up = path[-2], len(path) - 2
        end = r.get("end", {})
        ref["name_span"] = (end["offset"], end["offset"] + end.get("tokLen", 0)) if is_main(end) else None
        base = node["inner"][0]
        core, casts = strip_implicit(base)
        ref["receiver"] = dict(kind=core.get("kind"), implicit=casts, arrow=bool(node.get("isArrow")),
                               span=span(core), type=core.get("type", {}).get("qualType"),
                               operand=span(core["inner"][0]) if core.get("kind") in CASTS else None)
    elif kind == "DeclRefExpr" and len(path) >= 3 and path[-2].get("kind") == "ImplicitCastExpr" \
            and path[-2].get("castKind") == "FunctionToPointerDecay" and path[-3].get("kind") == "CallExpr" \
            and path[-3]["inner"][0] is path[-2]:
        call, up = path[-3], len(path) - 3
        ref["name_span"] = span(node)
    if call is not None:
        ref["args"] = [arg_facts(a) for a in call.get("inner", [])[1:]]
        parent = up - 1
        while parent > 0 and path[parent].get("kind") in ("ExprWithCleanups", "ParenExpr"):
            parent -= 1
        p = path[parent]
        ref["used"] = not (p.get("kind") == "CompoundStmt" or (p.get("kind") == "CStyleCastExpr"
                                                               and p.get("castKind") == "ToVoid"))
        ref["call"] = True
    else:
        ref["call"] = False
    fns = [n for n in path[:-1] if n.get("kind") in FUNCS]
    ref["function"] = fns[-1].get("mangledName") if fns else None
    ref["template"] = any(n.get("kind") in TEMPLATES for n in path[:-1]) or any(n.get("kind") == "LambdaExpr"
                                                                                 for n in path[:-1])
    ref["ancestors"] = [(n.get("kind"), n.get("name", ""), span(n)) for n in path[:-1]
                        if n.get("kind") == "NamespaceDecl" or n.get("kind") == "LinkageSpecDecl"
                        or n.get("kind") in RECORDS or n.get("kind") in FUNCS or n.get("kind") in TEMPLATES]
    b = r.get("begin", {})
    ref["offset"] = b.get("offset") if is_main(b) else None
    return ref


# ---------------------------------------------------------------- the gate

def qualified(chain, name):
    """'::ns::Class::name' from a declaration chain of namespaces and records; None when a part
    has no name or is a template."""
    parts = []
    for kind, part, _, _ in chain:
        if kind == "LinkageSpecDecl":
            continue
        if kind not in ("NamespaceDecl", "CXXRecordDecl") or not part:
            return None
        parts.append(part)
    return "::" + "::".join(parts + [name])


def written_type(text, cast_kind, stand_in):
    """The span, inside the cast's text up to its operand, of the stand-in class's name as
    written (with any qualifier before it); None unless the written type is that one class
    name with cv-qualifiers and one * or &."""
    if cast_kind == "CStyleCastExpr":
        m = re.fullmatch(rb"\(\s*(.*?)\s*\)\s*", text, re.S)
    else:
        m = re.fullmatch(rb"(?:static_cast|reinterpret_cast)\s*<\s*(.*?)\s*>\s*\(\s*", text, re.S)
    if not m:
        return None
    inner, at = m.group(1), m.start(1)
    q = re.fullmatch(rb"((?:const|volatile|struct|class)\s+)*((?:::)?(?:[A-Za-z_]\w*\s*::\s*)*)"
                     + re.escape(stand_in.encode()) + rb"\s*((?:const|volatile)\s*)*[*&]", inner)
    if not q:
        return None
    return at + q.start(2), at + q.end(2) + len(stand_in.encode())


def visible_before(decl, ref):
    """True when DECL is visible at REF: an earlier top-level item, or earlier in the same item
    of the unit's file."""
    if decl["item"] < ref["item"]:
        return True
    if decl["item"] == ref["item"] and decl["span"] and ref["offset"] is not None:
        return decl["span"][1] <= ref["offset"]
    return False


def placeholder(part, address):
    """True when an identifier carries the row's own address (docs/symbol-naming-batches.md)."""
    a, part = int(address, 16), part.lower()
    return ("%08x" % a) in part or ("%06x" % a) in part


def naming(nsig, dsig, address):
    """(refusal, detail) or (None, label) under the naming rule of 2026-11-13: a descriptive
    function name is never replaced by a placeholder, and two different descriptive names are an
    open question; both are refused, for the reviewed override table. A member or static member
    whose class (its full scope, namespaces included) differs is admitted and labelled class-only
    when its name is the same on both sides, name+class when a placeholder becomes another name:
    its receiver stays open."""
    a, b = nsig["base"], dsig["base"]
    if a != b and not placeholder(a, address):
        if placeholder(b, address):
            return "naming:descriptive-function", "%s -> %s" % (a, b)
        return "naming:descriptive-differs", "%s -> %s" % (a, b)
    if (nsig["member"] or nsig["static"]) and nsig["scope"] != dsig["scope"]:
        return None, "class-only" if a == b else "name+class"
    return None, ""


def gate_site(ref, n, d, nsig, dsig, ndecl, ddecls, text, address="0x0"):
    """(refusal kind, detail), or (None, the admitted labels joined by +), for one reference of
    N, to bind to D."""
    if ref["macro"]:
        return "site:macro", ""
    if ref["header"]:
        return "site:header", ""
    if ref["template"]:
        return "site:template", ""
    if not ref["call"]:
        return "site:not-a-call", ref["kind"]
    if nsig["special"] or dsig["special"]:
        return "call-form:special-member", ""
    if nsig["virtual"] or dsig["virtual"] or any(x["virtual"] for x in ddecls):
        return "virtual", ""
    if nsig["member"] != dsig["member"] or (ref["kind"] == "MemberExpr") != dsig["member"]:
        return "call-form:member-free", ""
    if nsig["static"] != dsig["static"]:
        return "call-form:static-free", ""
    if nsig["cc"] != dsig["cc"]:
        return "conversion:calling-convention", ""
    if nsig["ret"] != dsig["ret"]:
        if dsig["ret"] == "void" and ref["used"]:
            return "void-result-used", "%s -> void" % nsig["ret"]
        return "conversion:result", "%s -> %s" % (nsig["ret"], dsig["ret"])
    admitted = []
    if nsig["quals"] != dsig["quals"]:
        if not (nsig["quals"] == "" and dsig["quals"] == "const"):
            return "conversion:this", "%r -> %r" % (nsig["quals"], dsig["quals"])
        admitted.append("const-this")
    if len(nsig["params"]) != len(dsig["params"]):
        return "conversion:parameter-count", "%d -> %d" % (len(nsig["params"]), len(dsig["params"]))
    if any(a["default"] for a in ref["args"]):
        return "conversion:default-argument", ""
    for i, (a, b) in enumerate(zip(nsig["params"], dsig["params"])):
        if a == b:
            continue
        arg = ref["args"][i] if i < len(ref["args"]) else None
        if b == "void *" and arg and re.fullmatch(r"(class |struct |union |enum )?[\w:<>, ]+ \*", a) \
                and "const" not in a.split() and "volatile" not in a.split() and a != "void *" \
                and set(arg["casts"]) <= {"LValueToRValue", "NoOp"}:
            admitted.append("R5a")
            continue
        if b == "bool" and a in INTEGERS and arg and arg["kind"] == "IntegerLiteral" and arg["value"] in ("0", "1"):
            # The object differs (2026-11-13): a per-address step, not a batch.
            return "conversion:literal-bool", "%d: %s -> %s" % (i + 1, a, b)
        return "conversion:parameter", "%d: %s -> %s" % (i + 1, a, b)
    if ref["kind"] == "MemberExpr":
        rec = ref["receiver"]
        if rec["kind"] not in CASTS or not rec["span"] or not rec["operand"]:
            return "receiver:not-a-cast", rec["kind"] or ""
        if set(rec["implicit"]) - {"NoOp", "LValueToRValue"}:
            return "receiver:conversion", ",".join(rec["implicit"])
        stand_in = nsig["scope"].split("::")[-1]
        if not stand_in or "<" in nsig["scope"] or written_type(
                text[rec["span"][0]:rec["operand"][0]], rec["kind"], stand_in) is None:
            return "receiver:cast-text", rec["type"] or ""
        if not ndecl or not ndecl.get("record") or ndecl["record"]["name"] != stand_in:
            return "receiver:cast-text", "stand-in class"
    refusal, label = naming(nsig, dsig, address)
    if refusal:
        return refusal, label
    if label:
        admitted.append(label)
    if not ref.get("name_span"):
        return "site:name-text", ""
    got = text[ref["name_span"][0]:ref["name_span"][1]].decode("utf-8", "replace")
    if ref["kind"] == "MemberExpr":
        if got != nsig["base"]:
            return "site:name-text", got
    elif not re.fullmatch(r"(::)?(\w+\s*::\s*)*" + re.escape(nsig["base"]), got):
        return "site:name-text", got
    return None, "+".join(admitted)


def overloaded(dsig, scoped, funcs):
    """The owner's other declarations of its simple name in its own scope (its class, or its
    namespace for a free function), as mangled names ("template" for a function template):
    a call spelled with that name could pick another overload."""
    if not scoped:
        return set()
    if dsig["member"] or dsig["static"]:
        rec = next((x["record"]["id"] for x in scoped if x["record"]), None)
        same = [f for f in funcs if f["record"] is not None and f["record"] == rec]
    else:
        ns = [name for kind, name, _, _ in scoped[0]["chain"] if kind == "NamespaceDecl"]
        same = [f for f in funcs if f["record"] is None and f["scoped"] and f["namespace"] == ns]
    return {"template" if f["template"] or not f["mangled"] else f["mangled"] for f in same
            if f["name"] == dsig["base"]}


def listed_undefined(n, dem, undefined):
    """True when the tip's forced-unlimited link lists N as undefined: by its mangled name or as
    llvm-undname prints it (lld-link prints the same text)."""
    return n in undefined or (dem.get(n) is not None and dem[n] in undefined)


def gate_unit(job):
    """Extract one unit and decide its candidates. JOB: (unit, rows, entry, ctx), ctx holding
    the recipe check, the signatures and demangled names, the differing-definitions names and the
    tip's undefined names."""
    unit, rows, entry, ctx = job
    names = {r["name"] for r in rows}
    owners = {r["owner"] for r in rows}
    path = entry["file"]
    with open(path, "rb") as f:
        text = f.read()
    facts = extract(entry, names, owners)
    out, plan = [], dict(unit=unit, file=path, sha256=hashlib.sha256(text).hexdigest(), names={},
                         refused=sorted(names))
    if facts is None:
        for r in rows:
            out.append(dict(r, line="", col="", decision="REFUSE", kind="extract:failed", detail=""))
        return out, plan
    plan["refused"] = []
    for r in rows:
        n, d = r["name"], r["owner"]
        base = dict(r, line="", col="")

        def refuse(kind, detail=""):
            plan["refused"].append(n)
            out.append(dict(base, decision="REFUSE", kind=kind, detail=detail))
        recipe_problem, recipe_names = ctx["recipe"](unit, n, d, r["address"])
        nsig, dsig = ctx["sig"].get(n), ctx["sig"].get(d)
        ndecls = [x for x in facts["decls"].get(n, []) if not x["implicit"]]
        ddecls = [x for x in facts["decls"].get(d, []) if not x["implicit"]]
        nids = {x["id"] for x in ndecls}
        every = [x for x in facts["refs"] if x["target"] in nids]
        sites = [x for x in every if r["site"] == "*" or (x["offset"] is not None
                                                           and "%d:%d" % position(text, x["offset"]) == r["site"])]
        if recipe_problem:
            refuse(recipe_problem, recipe_names)
            continue
        if ctx["differing"] & {n, d}:
            refuse("differing-definitions", "")
            continue
        if not listed_undefined(n, ctx["dem"], ctx["undefined"]):
            refuse("defined:not-listed", "the tip's forced-unlimited link does not list it as undefined")
            continue
        if listed_undefined(d, ctx["dem"], ctx["undefined"]):
            refuse("defined:owner-undefined", "the tip's forced-unlimited link lists the owner as undefined")
            continue
        if nsig is None or dsig is None:
            refuse("signature:unreadable", "")
            continue
        if not ndecls:
            refuse("not-declared:name", "")
            continue
        if not ddecls:
            refuse("not-declared:owner", "")
            continue
        if any(x["body"] for x in ndecls):
            refuse("defined:name", "the unit defines the stand-in")
            continue
        scoped = [x for x in ddecls if x["scoped"]]
        others = overloaded(dsig, scoped, facts["funcs"])
        if others - {d}:
            refuse("overload:owner", " ".join(sorted(others - {d})))
            continue
        if not sites:
            refuse("site:none", "")
            continue
        ndecl = ndecls[0]
        entry_plan = plan["names"].setdefault(n, dict(owner=d, address=r["address"], key=recipe_names[0],
                                                      row=recipe_names[1], sites=[], moves=[], removals=[],
                                                      kept=[x["function"] for x in every if x not in sites],
                                                      defined_here=any(x["body"] for x in ddecls)))
        for s in sites:
            kind, detail = gate_site(s, n, d, nsig, dsig, ndecl, ddecls, text, r["address"])
            if kind is None and owner_name(dsig, scoped, ddecls) is None:
                kind, detail = "not-declared:owner-name", ""
            move = []
            if kind is None:
                move, why = placement(s, dsig, scoped, text, facts["types"])
                if why:
                    kind, detail = why, ""
                else:
                    entry_plan["moves"] += move
            line, col = position(text, s["offset"])
            if kind:
                out.append(dict(base, line=line, col=col, decision="REFUSE", kind=kind, detail=detail))
                entry_plan["kept"].append(s["function"])
                continue
            out.append(dict(base, line=line, col=col, decision="ADMIT", kind=detail or "same-type",
                            detail="move" if move else ""))
            entry_plan["sites"].append(site_edits(s, nsig, dsig, ddecls, scoped, text))
        if not entry_plan["kept"]:
            entry_plan["removals"] = removals(ndecls, nsig, text)
            rec = ndecl.get("record")
            cut = rec and rec["span"] and whole_lines(text, rec["span"])
            entry_plan["stand_in"] = dict(name=rec["name"], cut=cut, qualified=(qualified(rec["chain"], rec["name"])
                                                                                or "").lstrip(":")) if cut else None
    return out, plan


def position(text, offset):
    if offset is None:
        return "", ""
    line = text.count(b"\n", 0, offset) + 1
    return line, offset - (text.rfind(b"\n", 0, offset) + 1) + 1


def placement(ref, dsig, scoped, text, types):
    """(moves, refusal or None): what makes the owner visible at the site. A member needs its
    class defined before the site; a free function needs a declaration before it. Otherwise the
    class definition, or the earliest namespace-scope declaration, moves verbatim to before the
    site's outermost declaration in the deepest namespace they share, with at most
    MOVE_DEPENDENCIES types it names that are declared between the two places."""
    if dsig["member"] or dsig["static"]:
        recs = [x["record"] for x in scoped if x["record"] and x["record"]["complete"]]
        if not recs:
            return None, "not-declared:owner-class"
        rec = recs[0]
        if rec["kind"] != "CXXRecordDecl":
            return None, "move:template"
        if visible_before(rec, ref):
            return [], None
        what, chain = rec, rec["chain"]
    else:
        if any(visible_before(x, ref) for x in scoped):
            return [], None
        cands = sorted((x for x in scoped if x["span"]), key=lambda x: x["span"][0])
        if not cands:
            return None, "move:header"
        what, chain = cands[0], cands[0]["chain"]
    if not what["span"] or ref["offset"] is None:
        return None, "move:header"
    if what["span"][0] <= ref["offset"] < what["span"][1]:
        return [], None
    if any(k != "NamespaceDecl" or not name for k, name, _, _ in chain):
        return None, "move:nested"
    lines = whole_lines(text, what["span"])
    if lines is None:
        return None, "move:not-whole-lines"
    anc = ref["ancestors"]
    common = 0
    while common < len(chain) and common < len(anc) and anc[common][0] == "NamespaceDecl" \
            and anc[common][1] == chain[common][1]:
        common += 1
    if common >= len(anc) or anc[common][2] is None or any(k == "LinkageSpecDecl" for k, _, _ in anc[:common + 1]):
        return None, "move:context"  # no declaration to place it before, or a linkage block
    at = leading_comments(text, line_start(text, anc[common][2][0]))
    if lines[0] < at:
        return None, "move:order"
    prefix = [name for _, name, _, _ in chain[:common]]
    moves = [dict(cut=lines, at=at, wrap=[name for _, name, _, _ in chain[common:]])]
    pending, own = [lines], what.get("name")
    while pending:
        b, e = pending.pop()
        ids = set(re.findall(rb"[A-Za-z_]\w*", text[b:e]))
        for t in types:
            between = at <= t["span"][0] and t["span"][1] <= lines[0]
            if t["name"].encode() not in ids or t["name"] == own or not between:
                continue
            cut = whole_lines(text, t["span"])
            path = [name for _, name, _, _ in t["chain"]]
            if cut is None or any(k != "NamespaceDecl" for k, _, _, _ in t["chain"]) or path[:common] != prefix:
                return None, "move:dependency"
            if all(m["cut"] != cut for m in moves):
                moves.append(dict(cut=cut, at=at, wrap=path[common:]))
                pending.append(cut)
    if len(moves) > 1 + MOVE_DEPENDENCIES:
        return None, "move:dependencies"
    return sorted(moves, key=lambda m: m["cut"]), None


def line_start(text, offset):
    return text.rfind(b"\n", 0, offset) + 1


def whole_lines(text, sp):
    """The lines of a declaration and its ';', with its comment lines just above; None when
    other text shares a line."""
    begin, end = sp
    m = re.match(rb"[ \t]*;?[ \t]*(\r?\n|$)", text[end:])
    if not m or text[line_start(text, begin):begin].strip():
        return None
    return leading_comments(text, line_start(text, begin)), end + m.end()


def leading_comments(text, start):
    """Move START up over the // comment lines directly above it."""
    while start > 0:
        prev = line_start(text, start - 1)
        if not text[prev:start].strip().startswith(b"//"):
            break
        start = prev
    return start


def owner_name(dsig, scoped, ddecls):
    """The owner's fully qualified spelling at a call: its class for a member, else its name."""
    if dsig["member"] or dsig["static"]:
        rec = next((x["record"] for x in scoped if x["record"] and x["record"]["complete"]), None)
        name = rec and qualified(rec["chain"], rec["name"])
        return name and (name + "::" + dsig["base"] if dsig["static"] else name)
    return qualified((scoped or ddecls)[0]["chain"], dsig["base"])


def site_edits(ref, nsig, dsig, ddecls, scoped, text):
    """The byte edits of one admitted site: the callee's spelling and, for a member call, the
    stand-in's name in the receiver's cast."""
    edits = []
    dname = dsig["base"]
    if ref["kind"] == "MemberExpr":
        edits.append((ref["name_span"][0], ref["name_span"][1], dname))
        rec = ref["receiver"]
        cast = text[rec["span"][0]:rec["operand"][0]]
        b, e = written_type(cast, rec["kind"], nsig["scope"].split("::")[-1])
        edits.append((rec["span"][0] + b, rec["span"][0] + e, owner_name(dsig, scoped, ddecls)))
    else:
        edits.append((ref["name_span"][0], ref["name_span"][1], owner_name(dsig, scoped, ddecls)))
    return dict(function=ref["function"], offset=ref["offset"], edits=edits)


def removals(ndecls, nsig, text):
    """Byte ranges of the stand-in's own declarations that no reference needs once every site is
    bound: non-defining, not virtual, alone on their lines in the unit's file."""
    out = []
    for x in ndecls:
        if x["body"] or x["virtual"] or not x["span"]:
            continue
        lines = whole_lines(text, x["span"])
        if lines:
            begin = line_start(text, x["span"][0])
            out.append((begin, lines[1]))
    return out


def read_names(path):
    """The first tab-separated field of each line, # comments and blank lines aside."""
    with open(path, encoding="utf-8") as f:
        return {l.rstrip("\r\n").split("\t")[0].strip() for l in f if l.strip() and not l.startswith("#")}


def gate(args):
    opts = parse_opts(args, ("--recipe", "--differing", "--undefined", "--jobs"))
    if opts is None or len(opts["args"]) != 3 or not all(opts.get(o) for o in ("--recipe", "--differing",
                                                                                 "--undefined")):
        return usage()
    candidates, build_dir, out_dir = opts["args"]
    try:
        rows = read_tsv(candidates)
        recipe = load_recipe(opts["--recipe"])
        differing, undefined = read_names(opts["--differing"]), read_names(opts["--undefined"])
    except (OSError, ValueError) as error:
        print("bind_batch.py: %s" % error, file=sys.stderr)
        return 2
    os.makedirs(out_dir, exist_ok=True)
    for stale in PROOF_FILES:  # an earlier gate's proof does not hold for this plan
        if os.path.exists(os.path.join(out_dir, stale)):
            os.remove(os.path.join(out_dir, stale))
    if os.path.isdir(os.path.join(out_dir, "proof")):
        shutil.rmtree(os.path.join(out_dir, "proof"))
    syms, rowsyms = recipe_index(recipe)
    by_unit = collections.defaultdict(list)
    for r in rows:
        by_unit[r["unit"]].append(r)
    entries = {u: compile_entry(build_dir, u) for u in by_unit}
    entry0 = next((e for e in entries.values() if e), None)
    if entry0 is None:
        print("bind_batch.py: no compile command for any unit", file=sys.stderr)
        return 2
    undname = os.path.join(os.path.dirname(dump_command(entry0)[0]), "llvm-undname")
    names64 = {r["name"] for r in rows} | {r["owner"] for r in rows}
    dem64 = demangle(names64, undname)
    sig = {k: (signature(v) if v else None) for k, v in dem64.items()}
    all32 = {k for s in syms.values() for k in s} | {s for _, s in rowsyms.values()}
    dem32 = demangle([k for k in all32 if k.startswith("?")], undname)
    ctx = dict(recipe=lambda unit, n, d, a: recipe_check(syms, rowsyms, dem32, dem64, unit, n, d, a), sig=sig,
               dem=dem64, differing=differing, undefined=undefined)
    jobs, out, plans = [], [], []
    for u, rs in by_unit.items():
        if entries[u] is None:
            out += [dict(r, line="", col="", decision="REFUSE", kind="extract:no-command", detail="") for r in rs]
            plans.append(dict(unit=u, file=None, names={}, refused=sorted({r["name"] for r in rs})))
        else:
            jobs.append((u, rs, entries[u], ctx))
    with ThreadPoolExecutor(int(opts.get("--jobs") or 1)) as ex:
        for res, plan in ex.map(gate_unit, jobs):
            out += res
            plans.append(plan)
    cols = ["unit", "line", "col", "name", "owner", "address", "decision", "kind", "detail"]
    out.sort(key=lambda r: (r["unit"], r["name"], int(r["line"] or 0), int(r["col"] or 0)))
    with open(os.path.join(out_dir, "gate.tsv"), "w", encoding="utf-8") as f:
        f.write("\t".join(cols) + "\n")
        for r in out:
            f.write("\t".join(str(r[c]) for c in cols) + "\n")
    with open(os.path.join(out_dir, "gate.json"), "w", encoding="utf-8") as f:
        json.dump(dict(build=os.path.abspath(build_dir), units=plans), f, indent=1)
    counts = collections.Counter((r["decision"], r["kind"].split(":")[0] if r["decision"] == "REFUSE" else "")
                                 for r in out)
    for (dec, kind), c in sorted(counts.items()):
        print("%s\t%s\t%d" % (dec, kind, c))
    return 0


# ---------------------------------------------------------------- rewriting

def whole_names(plans):
    """Names whose every site in every unit is admitted."""
    ok, bad = set(), set()
    for plan in plans:
        bad.update(plan.get("refused", []))
        for n, p in plan["names"].items():
            (bad if p["kept"] or not p["sites"] else ok).add(n)
    return ok - bad


def render(text, plan, names, stage):
    """The unit's text with the moves of NAMES (stage 'moves') or the moves, call edits and
    removals (stage 'bind'); in stage 'bind' a stand-in class left empty and named nowhere else
    goes too. Raises ValueError when edits overlap."""
    out = edit(text, plan, names, stage, [])
    if stage != "bind":
        return out
    gone = []
    for n in sorted(names):
        si = plan["names"][n].get("stand_in")
        if not si or si["cut"] in gone:
            continue
        b, e = si["cut"]
        rest = text[b:e]
        for rb, re_ in sorted((r for p in names for r in plan["names"][p]["removals"] if b <= r[0] and r[1] <= e),
                              reverse=True):
            rest = rest[:rb - b] + rest[re_ - b:]
        empty = re.fullmatch(rb"\s*(//[^\n]*\n\s*)*(struct|class)\s+" + re.escape(si["name"].encode())
                             + rb"\s*\{\s*\}\s*;\s*", rest)
        if empty and len(re.findall(rb"\b" + re.escape(si["name"].encode()) + rb"\b", out)) == 1:
            gone.append(si["cut"])
    return edit(text, plan, names, stage, gone) if gone else out


def edit(text, plan, names, stage, gone):
    edits, moved = [], {}
    for n in sorted(names):
        p = plan["names"][n]
        for m in p["moves"]:
            key = (m["cut"][0], m["cut"][1])
            if key not in moved or m["at"] < moved[key]["at"]:
                moved[key] = m
    inserts = collections.defaultdict(list)
    for (b, e), m in sorted(moved.items()):
        body = text[b:e]
        if not body.endswith(b"\n"):
            body += b"\n"
        for ns in reversed(m["wrap"]):
            body = b"namespace %s {\n%s}  // namespace %s\n" % (ns.encode(), body, ns.encode())
        inserts[m["at"]].append(body)
        edits.append((b, e, b""))
    for at, bodies in inserts.items():
        edits.append((at, at, b"".join(bodies)))
    if stage == "bind":
        for n in sorted(names):
            p = plan["names"][n]
            for s in p["sites"]:
                edits += [(b, e, t.encode()) for b, e, t in s["edits"]]
            edits += [(b, e, b"") for b, e in p["removals"] if not any(g[0] <= b and e <= g[1] for g in gone)]
        edits += [(b, e, b"") for b, e in gone]
    edits.sort(key=lambda x: (x[0], x[1]))
    for (b1, e1, _), (b2, e2, _) in zip(edits, edits[1:]):
        if b2 < e1 or (b1 == e1 == b2 == e2):
            raise ValueError("edits overlap at byte %d" % b2)
    for (b, e, _) in edits:
        for (mb, me) in moved:
            if mb < b < me or mb < e < me:
                if (b, e) != (mb, me):
                    raise ValueError("an edit falls inside moved text at byte %d" % b)
    out = text
    for b, e, t in sorted(edits, key=lambda x: (x[0], x[1]), reverse=True):
        out = out[:b] + t + out[e:]
    return out


def load_plans(out_dir):
    with open(os.path.join(out_dir, "gate.json"), encoding="utf-8") as f:
        return json.load(f)


def selected(plans, only):
    names = whole_names(plans["units"])
    if only:
        with open(only, encoding="utf-8") as f:
            want = {l.split("\t")[0].strip() for l in f if l.strip() and not l.startswith("#")}
        names &= want
    return names


def changed_units(plans, names):
    """The units holding a name of NAMES whose text no longer has the sha256 the gate recorded."""
    out = []
    for plan in plans["units"]:
        if not any(n in names for n in plan["names"]):
            continue
        try:
            with open(plan["file"], "rb") as f:
                same = hashlib.sha256(f.read()).hexdigest() == plan.get("sha256")
        except (OSError, TypeError):
            same = False
        if not same:
            out.append(plan["unit"])
    return out


def refuse_changed(plans, names):
    """Prints and returns True when a unit's text is not the text the gate read."""
    changed = changed_units(plans, names)
    for unit in changed:
        print("bind_batch.py: %s is not the text the gate read; gate again" % unit, file=sys.stderr)
    return bool(changed)


# ---------------------------------------------------------------- proving

def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, errors="replace", **kw)


def compile_text(build_dir, unit, text, prefix):
    src = prefix + ".cpp"
    with open(src, "wb") as f:
        f.write(text)
    r = run([sys.executable, PROOF, "compile", "--target", "game", "--source", src, build_dir, unit, prefix])
    if r.returncode != 0:
        errors = []
        for v in VARIANTS:
            log = "%s.%s.log" % (prefix, v)
            if os.path.exists(log):
                with open(log, encoding="utf-8", errors="replace") as f:
                    errors += [re.sub(r"^.*?(error:)", r"\1", l.strip()) for l in f if "error:" in l]
        return "compile-failed: " + (errors[0] if errors else (r.stderr.strip().splitlines() or ["?"])[-1])
    return None


def objcmp(a, b, renames, prefix):
    """objcmp.py --json of two objects; with RENAMES, as a map, with --base-holds-new and with
    --function-order of the renames' new names, so that each mode gives its own verdict."""
    extra = []
    if renames:
        with open(prefix + ".map", "w", encoding="utf-8") as f:
            f.write("".join("%s=%s\n" % kv for kv in sorted(renames.items())))
        with open(prefix + ".order", "w", encoding="utf-8") as f:
            f.write("".join(n + "\n" for n in sorted(set(renames.values()))))
        extra += ["--map", prefix + ".map", "--base-holds-new", "--function-order", prefix + ".order"]
    r = run([sys.executable, OBJCMP, a, b, "--json"] + extra)
    try:
        return json.loads(r.stdout)
    except ValueError:
        return dict(result="error", verdict="objcmp: " + (r.stderr.strip().splitlines() or ["?"])[-1], lines=[],
                    retargets=[])


def proof_mode(rep):
    """The mode in which a binding's report passes, read from objcmp.py's verdict, or None:
    strict (equal once renamed), merge-definition and merge-reference (the old name merged into
    the owner's definition in the unit, or into the unit's existing reference to it), and
    function-order (the owner's body emitted elsewhere)."""
    result, verdict = rep.get("result"), rep.get("verdict", "")
    if result == "identical":
        return "strict" if verdict.startswith("identical: equal with the timestamp masked once the renames are "
                                              "applied") else None
    if result not in ("merged", "reordered", "merged and reordered") or rep.get("exit") != 0:
        return None
    modes = ["merge-" + m for m in sorted({m["into"] for m in rep.get("merges", [])})]
    if "reordered" in result:
        modes.append("function-order")
    return "+".join(modes) or None


def compare(base, head, renames, out_prefix):
    """Per variant: (ok, detail, report, mode) from objcmp.py --json and proof.py warnings. Without
    RENAMES the bytes must be equal; with them, objcmp.py's verdict must name a proof mode."""
    results = {}
    for v in VARIANTS:
        a, b = "%s.%s.obj" % (base, v), "%s.%s.obj" % (head, v)
        rep = objcmp(a, b, renames, out_prefix)
        with open("%s.%s.json" % (out_prefix, v), "w", encoding="utf-8") as f:
            json.dump(rep, f, indent=1)
        if renames:
            mode = proof_mode(rep)
        else:
            mode = "bytes" if rep.get("verdict", "").startswith("identical: the bytes are equal") else None
        ok = mode is not None
        detail = "" if ok else rep.get("verdict", "") + (" | " + rep["lines"][0] if rep.get("lines") else "")
        w = run([sys.executable, PROOF, "warnings", "%s.%s.log" % (base, v), "%s.%s.log" % (head, v)])
        if ok and w.returncode != 0:
            ok, detail = False, "warnings differ"
        results[v] = (ok, detail, rep, mode or "")
    return results


def drop_reason(stage, res, defined_here):
    """A label for the reports: the kind of the first difference. The decision does not use it."""
    bad = [v for v in VARIANTS if not res[v][0]]
    kind = "differs"
    if stage == "bind" and bad == ["flags"] and defined_here:
        kind = "inlinable-at-unit-flags"
    elif all(res[v][1] == "warnings differ" for v in bad):
        kind = "warnings"
    return "%s %s[%s]: %s" % (stage, kind, ",".join(bad), res[bad[0]][1])


def remove_objects(prefix):
    for v in VARIANTS:
        p = "%s.%s.obj" % (prefix, v)
        if os.path.exists(p):
            os.remove(p)


LAYOUT_TARGETS = ("x86_64-pc-windows-msvc", "i686-pc-windows-msvc")
# An unnamed record's dump names it by its place, which a move or a removal shifts.
LAYOUT_PLACE = re.compile(r" at [^()]+?:\d+:\d+\)")


def layouts(build_dir, unit, source, prefix, target):
    """The record layouts of SOURCE's text compiled at UNIT's path for TARGET, syntax only, as a
    Counter of blocks (each from '*** Dumping AST Record Layout' to its blank line, an unnamed
    record's file, line and column left out); None when the command names no windows-x64 target or
    the dump fails."""
    entry = compile_entry(build_dir, unit)
    if entry is None:
        return None
    words = entry["arguments"] if "arguments" in entry else shlex.split(entry["command"])
    at = words.index("--") if "--" in words else len(words) - 1
    keep = [w for w in words[:at] if not w.startswith(("/Fo", "/Fd", "-Fo")) and w != "-c"]
    if "--target=x86_64-pc-windows-msvc" not in keep:
        return None
    keep = [("--target=" + target) if w == "--target=x86_64-pc-windows-msvc" else w for w in keep]
    overlay = prefix + ".%s.vfs.json" % target
    with open(overlay, "w", encoding="utf-8") as f:
        json.dump({"version": 0, "use-external-names": False, "roots": [{
            "type": "file", "name": os.path.join(entry["directory"], entry["file"]),
            "external-contents": os.path.abspath(source)}]}, f)
    r = run(keep + ["/Zs", "-w", "-Xclang", "-fdump-record-layouts-complete", "-vfsoverlay", overlay] + words[at:],
            cwd=entry["directory"])
    if r.returncode != 0:
        return None
    blocks, cur = [], []
    for line in LAYOUT_PLACE.sub(" at <place>)", r.stdout).splitlines():
        if line.startswith("*** Dumping AST Record Layout"):
            if cur:
                blocks.append("\n".join(cur))
            cur = [line]
        elif cur and not line.strip() and len(cur) > 1:
            blocks.append("\n".join(cur))
            cur = []
        elif cur:
            cur.append(line)
    if cur:
        blocks.append("\n".join(cur))
    return collections.Counter(blocks)


def removed_stand_in(block, stand_ins):
    """True when BLOCK is the layout of an empty stand-in class of STAND_INS (qualified names)."""
    lines = block.split("\n")
    m = len(lines) > 1 and re.fullmatch(r"\s*0 \| (?:struct|class) (\S+) \(empty\)", lines[1])
    return bool(m) and m.group(1) in stand_ins and "[sizeof=1," in block


def layout_check(build_dir, unit, base_source, head_source, prefix, stand_ins):
    """None when the record layouts of both sources are equal on windows-x64 and on i686, but for
    the removed empty stand-in classes of STAND_INS; else the reason. A failed dump fails."""
    for target in LAYOUT_TARGETS:
        a = layouts(build_dir, unit, base_source, prefix + ".base", target)
        b = layouts(build_dir, unit, head_source, prefix + ".head", target)
        if a is None or b is None:
            return "layout: the %s record-layout dump failed" % target
        only_b = sum((b - a).values())
        only_a = [x for x in (a - b).elements() if not removed_stand_in(x, stand_ins)]
        if only_b or only_a:
            return "layout: %s: %d record layout(s) only in the head, %d other than a removed empty stand-in " \
                   "only in the base" % (target, only_b, len(only_a))
    return None


def prove_unit(job):
    build_dir, plan, names, work, defined_here = job
    unit = plan["unit"]
    os.makedirs(work, exist_ok=True)
    with open(plan["file"], "rb") as f:
        base = f.read()
    verdicts, rows = {}, []
    bp = os.path.join(work, "base")
    err = compile_text(build_dir, unit, base, bp)
    if err:
        return {n: ("base " + err, "") for n in names}, rows

    def attempt(group, tag):
        """(None, results) when GROUP's moves are byte-identical and its binding passes in one
        proof mode at every variant; else (the reason, None)."""
        try:
            moved, bound = render(base, plan, group, "moves"), render(base, plan, group, "bind")
        except ValueError as e:
            return "apply-failed: %s" % e, None
        prev = bp
        if moved != base:
            mp = os.path.join(work, tag + ".moves")
            err = compile_text(build_dir, unit, moved, mp)
            if err:
                return "moves " + err, None
            res = compare(bp, mp, {}, mp)
            if not all(res[v][0] for v in VARIANTS):
                return drop_reason("moves", res, False), None
            prev = mp
        hp = os.path.join(work, tag + ".bind")
        err = compile_text(build_dir, unit, bound, hp)
        if err:
            return "bind " + err, None
        res = compare(prev, hp, {n: plan["names"][n]["owner"] for n in group}, hp)
        if prev != bp:
            remove_objects(prev)
        remove_objects(hp)
        if not all(res[v][0] for v in VARIANTS):
            return drop_reason("bind", res, any(defined_here.get(n) for n in group)), None
        return None, res

    modes = {}
    for i, n in enumerate(sorted(names)):
        why, res = attempt([n], "n%03d" % i)
        verdicts[n] = why
        if res:
            modes[n] = "/".join(res[v][3] for v in VARIANTS)
    good = sorted(n for n in names if verdicts[n] is None)
    while good:
        why, res = attempt(good, "all")
        if why:
            for n in good:
                verdicts[n] = "together: " + why
            break
        # A check row names a function that holds the call at the unit's flags and at /Od: a
        # function that holds it at the unit's flags only holds an inlined copy, which another
        # compiler may not inline.
        held = {v: collections.defaultdict(set) for v in ("flags", "od")}
        for v in held:
            for t in res[v][2]["retargets"]:
                if t["old"] in good and t["new"] == plan["names"][t["old"]]["owner"]:
                    held[v][t["old"]] |= set(t["functions"])
        found = {n: held["flags"][n] & held["od"][n] for n in good}
        bad = [n for n in good if not found[n] or any(f.startswith("#") or "|" in f for f in found[n])]
        for n in bad:
            verdicts[n] = "row: no COMDAT function holds the call at the unit's flags and at /Od (%s)" % (
                ", ".join(sorted(found[n])) or "none")
        if not bad:
            stand_ins = {plan["names"][n]["stand_in"]["qualified"] for n in good if plan["names"][n].get("stand_in")}
            why = layout_check(build_dir, unit, bp + ".cpp", os.path.join(work, "all.bind.cpp"),
                               os.path.join(work, "layout"), stand_ins)
            if why:
                for n in good:
                    verdicts[n] = why
                break
            rows = [(unit, f, plan["names"][n]["owner"], n) for n in good for f in sorted(found[n])]
            break
        good = [n for n in good if n not in bad]
    remove_objects(bp)
    return {n: (why, modes.get(n, "")) for n, why in verdicts.items()}, rows


def prove(args):
    opts = parse_opts(args, ("--only", "--jobs"))
    if opts is None or len(opts["args"]) != 2:
        return usage()
    out_dir, build_dir = opts["args"]
    plans = load_plans(out_dir)
    names = selected(plans, opts.get("--only"))
    if refuse_changed(plans, names):
        return 1
    jobs = []
    for i, plan in enumerate(plans["units"]):
        mine = sorted(n for n in plan["names"] if n in names)
        if mine:
            here = {n: plan["names"][n]["defined_here"] for n in mine}
            jobs.append((build_dir, plan, mine, os.path.join(out_dir, "proof", "u%03d" % i), here))
    verdict, rows = {}, []
    with ThreadPoolExecutor(int(opts.get("--jobs") or 1)) as ex:
        for (v, r), job in zip(ex.map(prove_unit, jobs), jobs):
            for n, why in v.items():
                verdict[(job[1]["unit"], n)] = why
            rows += r
    by_name = collections.defaultdict(list)
    for (u, n), (why, _) in verdict.items():
        by_name[n].append(why)
    with open(os.path.join(out_dir, "proof.tsv"), "w", encoding="utf-8") as f:
        f.write("unit\tname\towner\tverdict\tmode\treason\n")
        for (u, n), (why, mode) in sorted(verdict.items()):
            owner = next(p["names"][n]["owner"] for p in plans["units"] if p["unit"] == u)
            f.write("%s\t%s\t%s\t%s\t%s\t%s\n" % (u, n, owner, "PROVED" if why is None else "DROPPED", mode,
                                                  (why or "").replace("\t", " ")))
    with open(os.path.join(out_dir, "rows.tsv"), "w", encoding="utf-8") as f:
        f.write("unit\tfunction\towner\tname\n")
        for r in sorted(set(rows)):
            f.write("\t".join(r) + "\n")
    proved = sorted(n for n, w in by_name.items() if all(x is None for x in w))
    with open(os.path.join(out_dir, "proved.txt"), "w", encoding="utf-8") as f:
        f.write("".join(n + "\n" for n in proved))
    print("proved %d of %d names" % (len(proved), len(by_name)))
    return 0


# ---------------------------------------------------------------- applying

TABLE_HEAD = """# Calls bound by tools/bind-batch to the body at the recipe's row (VEGAS-125).
# Generated by bind_batch.py apply; format: README.md. Each forbid line is a
# stand-in name no object defines once every call of it is bound; each
# function line requires the row owner's name of a function whose call was
# respelled, as the object proof's retargets at the unit's flags list it.
"""


def apply(args):
    """Writes nothing until every unit's text, every recipe key and every check row is ready."""
    opts = parse_opts(args, ("--only", "--stage", "--table", "--batch", "--recipe"))
    if opts is None or len(opts["args"]) != 2 or opts.get("--stage") not in ("moves", "bind") \
            or (opts["--stage"] == "bind" and not (opts.get("--table") and opts.get("--batch"))):
        return usage()
    out_dir, root = opts["args"]
    stage = opts["--stage"]
    for name in PROOF_FILES:
        if not os.path.exists(os.path.join(out_dir, name)):
            print("bind_batch.py: %s has no %s; run prove first" % (out_dir, name), file=sys.stderr)
            return 1
    plans = load_plans(out_dir)
    names = selected(plans, opts.get("--only")) & read_names(os.path.join(out_dir, "proved.txt"))
    if refuse_changed(plans, names):
        return 1
    texts, done = [], []
    for plan in plans["units"]:
        mine = sorted(n for n in plan["names"] if n in names)
        if not mine:
            continue
        with open(plan["file"], "rb") as f:
            base = f.read()
        target = os.path.join(root, plan["unit"])
        try:
            with open(target, "rb") as f:
                now = f.read()
            if now not in (base, render(base, plan, mine, "moves")):
                print("bind_batch.py: %s differs from the gate's export; gate again" % plan["unit"], file=sys.stderr)
                return 1
            texts.append((target, render(base, plan, mine, stage)))
        except (OSError, ValueError) as error:
            print("bind_batch.py: %s: %s" % (plan["unit"], error), file=sys.stderr)
            return 1
        done.append((plan, mine))
    if not done:
        print("%s: no proved name to apply" % stage)
        return 0
    if stage == "bind":
        recipe_path = opts.get("--recipe") or os.path.join(root, "build", "units.json")
        try:
            recipe = load_recipe(recipe_path)
            for plan, mine in done:
                for n in mine:
                    p = plan["names"][n]
                    respell_keys(recipe, plan["unit"], p["address"], p["key"], p["row"])
            table = table_text(opts["--table"], opts["--batch"], done, read_tsv(os.path.join(out_dir, "rows.tsv")))
        except (OSError, ValueError) as error:
            print("bind_batch.py: %s" % error, file=sys.stderr)
            return 1
    for target, text in texts:
        with open(target, "wb") as f:
            f.write(text)
    if stage == "bind":
        with open(recipe_path, "w", encoding="utf-8") as f:
            f.write(json.dumps(recipe, indent=1) + "\n")
        with open(opts["--table"], "w", encoding="utf-8") as f:
            f.write(table)
    print("%s: %d names in %d units" % (stage, sum(len(m) for _, m in done), len(done)))
    return 0


def table_text(table, batch, done, proved):
    """The check table with a forbid line per bound name and a function line per function that
    the proof's rows (PROVED, rows.tsv) give; ValueError when a bound name has no row."""
    rows, forbid = collections.defaultdict(set), set()
    for plan, mine in done:
        for n in mine:
            forbid.add(n)
            fns = {r["function"] for r in proved if r["unit"] == plan["unit"] and r["name"] == n}
            if not fns:
                raise ValueError("%s: %s has no check row in rows.tsv" % (plan["unit"], n))
            for fn in fns:
                rows[(plan["unit"], fn)].add(plan["names"][n]["owner"])
    old = TABLE_HEAD
    if os.path.exists(table):
        with open(table, encoding="utf-8") as f:
            old = f.read()
    have = set(old.splitlines())
    lines = [l for l in ("forbid\t%s" % n for n in sorted(forbid)) if l not in have]
    lines += ["function\t%s\t%s\t%s\t%s" % (batch, u, fn, " ".join(sorted(o))) for (u, fn), o in sorted(rows.items())]
    return old + "".join(l + "\n" for l in lines)


# ---------------------------------------------------------------- command line

def read_tsv(path):
    with open(path, encoding="utf-8") as f:
        head = f.readline().rstrip("\n").split("\t")
        return [dict(zip(head, l.rstrip("\n").split("\t"))) for l in f if l.strip()]


def parse_opts(args, known):
    opts, rest = {}, []
    i = 0
    while i < len(args):
        if args[i] in known and i + 1 < len(args):
            opts[args[i]] = args[i + 1]
            i += 2
        elif args[i].startswith("--"):
            return None
        else:
            rest.append(args[i])
            i += 1
    opts["args"] = rest
    return opts


def usage():
    print(__doc__.strip().split("\n\n")[1], file=sys.stderr)
    return 2


def main(argv):
    commands = dict(gate=gate, prove=prove, apply=apply)
    if not argv or argv[0] not in commands:
        return usage()
    return commands[argv[0]](argv[1:])


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
