#!/usr/bin/env python3
"""Step 2 of the interior-alias scan: join the recipe's data names with the objects' definitions and references.

usage: scan_families.py UNITS_JSON OBJECTS_JSONL I686_JSONL OUT_DIR [OWNERS_TSV]
OWNERS_TSV lists the native owners that replace recipe names: recipe address, tab, the owner's symbol. An owner
is not a recipe name, so its address has to be given. A family is 'one owner' when its container is such an
owner and no object defines or refers to any other name of the family.
Writes OUT_DIR/names.tsv (every data name), families.tsv (one row per family), members.tsv (one row per
family member), other_manglings.tsv (recipe data symbols left out because their mangling has no plain name),
counts.txt.

Extent rules. The recipe gives 32-bit addresses and no sizes. The extent of a definition is the size of its
section in a 32-bit object of the same unit built with one section per global (I686_JSONL, exact). Only for a
definition whose unit does not compile for 32-bit, it is measured in the windows-x64 object (distance to the next
symbol of its section) and converted by its mangled type:
  arithmetic scalar        exact: the size of the type
  pointer or function ptr  exact: 4
  array of pointers        (x64 size / 8) * 4
  array of arithmetic      the x64 size (padding to the next symbol can add up to 7 bytes)
  class, struct, union     not measurable: between half the x64 size and the x64 size
A name is inside another when its address is above the container's and below container + extent. With a class
container, names above the half size are reported as class 'unknown'.
An under-declared container (declared as a scalar or as one element, indexed by the code) has no extent in its
definition. It is found from the references instead: an access with an index register, or at a constant offset
at or past the definition's end. Its family is every name up to the next address that the same evidence does not
reach, and is reported with the basis 'indexed'.
"""
import collections, json, os, re, sys

units_json, objects_jsonl, i686_jsonl, out = sys.argv[1:5]
owners_tsv = sys.argv[5] if len(sys.argv) > 5 else None
os.makedirs(out, exist_ok=True)
recipe = json.load(open(units_json))["units"]

FUND = {"C": 1, "D": 1, "E": 1, "F": 2, "G": 2, "H": 4, "I": 4, "J": 4, "K": 4, "M": 4, "N": 8, "O": 8,
        "_N": 1, "_J": 8, "_K": 8, "_W": 2, "_S": 2, "_U": 4, "_Q": 1}


def key(sym):
    """Identity of a data name that does not depend on the target's pointer mangling."""
    if sym.startswith("?"):
        m = re.match(r"\?([^?]\w*(?:@\w+)*)@@([23])", sym)
        if m:
            return m.group(1)
        return None
    if sym.startswith("_"):
        return sym[1:]
    return sym


def type_code(sym):
    m = re.match(r"\?[^?]\w*(?:@\w+)*@@[23](.*)$", sym)
    return m.group(1) if m else None


def classify(code):
    """(kind, element bytes on x64, element bytes on 32-bit) from the mangled type of a data symbol."""
    if code is None:
        return ("c-symbol", None, None)
    if code[:1] in "PQRS":
        rest = code[1:]
        if rest[:1] == "E":
            rest = rest[1:]
        if rest[:1] in "6789":
            return ("function pointer", 8, 4)
        pointee = rest[1:] if rest[:1] in "ABCD" else rest
        if pointee[:1] in "PQRS":
            return ("pointer or array of pointers", 8, 4)
        for c in ("_N", "_J", "_K", "_W", "_S", "_U", "_Q"):
            if pointee.startswith(c):
                return ("pointer or array of arithmetic", FUND[c], FUND[c])
        if pointee[:1] in FUND:
            return ("pointer or array of arithmetic", FUND[pointee[:1]], FUND[pointee[:1]])
        if pointee[:1] == "X":
            return ("pointer", 8, 4)
        return ("pointer or array of class", None, None)
    for c in ("_N", "_J", "_K", "_W", "_S", "_U", "_Q"):
        if code.startswith(c):
            return ("arithmetic", FUND[c], FUND[c])
    if code[:1] in FUND:
        return ("arithmetic", FUND[code[:1]], FUND[code[:1]])
    if code[:1] == "W":
        return ("arithmetic", 4, 4)
    if code[:1] in "TUV":
        return ("class", None, None)
    return ("other", None, None)


# ---- recipe: data names ----
text_end = 0
functions = set()
for u in recipe:
    for f in u["functions"]:
        a = int(f["address"], 16)
        functions.add(a)
        text_end = max(text_end, a + f["size"])
by_addr = collections.defaultdict(lambda: collections.defaultdict(set))   # address -> recipe symbol -> units
unit_key_addr = collections.defaultdict(dict)                            # unit -> key -> address
key_addrs = collections.defaultdict(set)
skipped = collections.Counter()
other_mangling = collections.defaultdict(set)                            # (address, symbol) -> units
for u in recipe:
    for s, a in u["symbols"].items():
        a = int(a, 16)
        if a < text_end or a in functions:
            continue
        if s.startswith(("__imp_", "??_C@", "__real@", "__xmm@", "??_7", "??_8", "??_R", "??_E", "??_G", "$SG", "_$SG")):
            skipped[{"__imp": "imports", "??_C@": "string literals", "__rea": "float literals", "__xmm": "float literals",
                     "??_7?": "vtables", "$SG": "string literals", "_$SG": "string literals"}.get(
                         s[:3] if s.startswith("$SG") else s[:4] if s.startswith("_$SG") else s[:5],
                         "vtables" if s.startswith(("??_7", "??_8")) else "type information")] += 1
            continue
        k = key(s)
        if k is None:
            skipped["no key"] += 1
            other_mangling[(a, s)].add(u["source"])
            continue
        by_addr[a][s].add(u["source"])
        unit_key_addr[u["source"]][k] = a
        key_addrs[k].add(a)

owners = {}
if owners_tsv:
    for line in open(owners_tsv):
        if line.strip() and not line.startswith("#"):
            a, sym = line.split()[:2]
            owners[key(sym)] = int(a, 16)
            key_addrs[key(sym)].add(int(a, 16))

# ---- objects ----
defs = {}                                    # key -> (x64 symbol, size, object)
refs = collections.defaultdict(list)         # address -> [unit, key, disp, kind, width, scale]
unmatched_refs = collections.Counter()
objects = 0
for line in open(objects_jsonl):
    rec = json.loads(line)
    objects += 1
    unit = rec["object"][:-4] if rec["object"].endswith(".obj") else rec["object"]
    for s, (sec, value, size) in rec["defs"].items():
        k = key(s)
        if k is None or k not in key_addrs:
            continue
        if k in defs and defs[k][2] != rec["object"]:
            defs[k] = (s, min(size or 0, defs[k][1] or 0) or size, defs[k][2] + " " + rec["object"])
        else:
            defs[k] = (s, size, rec["object"])
    local = unit_key_addr.get(unit, {})
    for s, disp, kind, width, scale, func in rec["refs"]:
        k = key(s)
        if k is None:
            continue
        a = local.get(k)
        if a is None:
            if len(key_addrs.get(k, ())) == 1:
                a = next(iter(key_addrs[k]))
            else:
                if k in key_addrs:
                    unmatched_refs[k] += 1
                continue
        refs[a].append((unit, k, disp, kind, width, scale))

defs32 = {}                                  # key -> (size, object)
objects32 = 0
for line in open(i686_jsonl):
    rec = json.loads(line)
    objects32 += 1
    for s, (sec, value, size) in rec["defs"].items():
        k = key(s)
        if k is None or k not in key_addrs or size is None:
            continue
        if k in defs32 and defs32[k][0] != size:
            defs32[k] = (max(size, defs32[k][0]), defs32[k][1] + " " + rec["object"])
        else:
            defs32[k] = (size, rec["object"])

owner_units = collections.defaultdict(set)
for a, rs in refs.items():
    for r in rs:
        if r[1] in owners:
            owner_units[r[1]].add(r[0])
for k, a in owners.items():
    sym = defs[k][0] if k in defs else k
    by_addr[a][sym] |= owner_units[k]

# ---- per name ----
Name = collections.namedtuple("Name", "addr keys symbols units kind x64 lo hi basis defined")
names = {}
for a in sorted(by_addr):
    syms = by_addr[a]
    keys = sorted({key(s) for s in syms})
    units = set().union(*syms.values())
    kinds = []
    lo = hi = None
    x64 = None
    defined = []
    basis = "undefined in every object"
    for k in keys:
        if k not in defs:
            continue
        s, size, obj = defs[k]
        defined.append(k)
        kind, e64, e32 = classify(type_code(s))
        kinds.append(kind)
        x64 = size
        if k in defs32:
            l = h = defs32[k][0]
            basis = "32-bit object"
            lo = l if lo is None else max(lo, l)
            hi = h if hi is None else max(hi, h)
            continue
        if size is None:
            continue
        if kind in ("arithmetic", "function pointer", "pointer"):
            l = h = e32
            basis = "type"
        elif kind == "pointer or array of pointers":
            l = h = max(1, size // 8) * 4
            basis = "x64 size / 8 * 4"
        elif kind == "pointer or array of arithmetic":
            wide = any(r[1] == k and r[4] == 8 and r[2] == 0 and r[5] == 0 and r[3] in ("r", "w") for r in refs.get(a, ()))
            if size == 8 and wide:
                l = h = 4
                basis = "pointer (8-byte accesses)"
            else:
                l, h = max(e32, size - 7), size
                basis = "x64 size (array of arithmetic)"
        elif kind == "class":
            l, h = (size + 1) // 2, size
            basis = "class: half to all of the x64 size"
        else:
            l, h = 1, size
            basis = "x64 size (%s)" % kind
        lo = l if lo is None else max(lo, l)
        hi = h if hi is None else max(hi, h)
    if not kinds:
        kinds = sorted({classify(type_code(s))[0] for s in syms})
    names[a] = Name(a, keys, sorted(syms), units, "/".join(sorted(set(kinds))), x64, lo, hi, basis, defined)

addrs = sorted(names)


def access_summary(a):
    c = collections.Counter()
    for unit, k, disp, kind, width, scale in refs.get(a, ()):
        c[(kind, width, scale)] += 1
    parts = []
    for (kind, width, scale), n in sorted(c.items()):
        label = {"r": "read", "w": "write", "rw": "read-write", "a": "address", "c": "address passed on"}[kind]
        if width:
            label += " %d" % width
        if scale:
            label += " indexed*%d" % scale
        parts.append("%s x%d" % (label, n))
    return "; ".join(parts)


# ---- indexed reach of each name ----
reach = {}   # addr -> (max constant offset reached in 32-bit terms or None, indexed by register)
for a in addrs:
    n = names[a]
    if not refs.get(a):
        continue
    kind_el = None
    for s in n.symbols:
        kind_el = classify(type_code(s))
    reg = False
    far = 0
    for unit, k, disp, kind, width, scale in refs[a]:
        if kind in ("r", "w", "rw", "c") and scale:
            reg = True
        if kind in ("r", "w", "rw") and disp > 0:
            far = max(far, disp)
    if n.x64 is not None and far >= n.x64:
        # convert an x64 offset into pointer slots to the 32-bit offset when the accesses are 8 bytes wide
        widths = {r[4] for r in refs[a] if r[2] == far}
        far32 = far // 2 if widths == {8} else far
        reach[a] = [far32, reg]
    elif reg:
        reach[a] = [None, reg]

# ---- families ----
unknown = []
families = []      # (container addr, basis, classification, [member addrs], note)
member_of = {}
for i, a in enumerate(addrs):
    n = names[a]
    if a in member_of:
        continue
    sure, maybe = [], []
    if n.hi:
        for b in addrs[i + 1:]:
            if b >= a + n.hi:
                break
            (sure if b < a + n.lo else maybe).append(b)
    indexed = []
    r = reach.get(a)
    if r and not sure:
        declared_one = n.hi is not None and n.hi <= 8
        if declared_one or r[0] is not None:
            if r[0] is not None:
                indexed = [b for b in addrs[i + 1:] if a < b <= a + r[0]]
            if r[1]:
                # an index register reaches an unknown distance: take the run of names that the family's own
                # declarations do not end, i.e. up to the next name that is itself a class object or is defined
                # with a different arithmetic element
                own = {x[4] for x in refs[a] if x[5] and x[4]}
                for b in addrs[i + 1:]:
                    m = names[b]
                    other = {x[4] for x in refs.get(b, ()) if x[5] and x[4]}
                    if m.kind.startswith("class") or b - a > 0x1000 or (other and not other & own):
                        break
                    if b not in indexed:
                        indexed.append(b)
    if sure:
        cls = "interior of a declared aggregate"
        families.append([a, n.basis, cls, sure, ""])
        for b in sure:
            member_of[b] = a
        if maybe:
            families[-1][4] = "%d more names lie in the part of the extent that depends on the class layout" % len(maybe)
    elif indexed:
        families.append([a, "indexed past its definition", "type or size disagreement", sorted(indexed),
                         "upper bound: run to the next class object or the next name indexed with another access width" if r[1] else "bounded by the largest constant offset"])
        for b in indexed:
            member_of.setdefault(b, a)
    elif maybe:
        unknown.append([a, n.basis, "unknown", maybe, "32-bit extent not measurable from x64 objects"])

def live(a, skip=()):
    """Keys of an address that some object defines or refers to."""
    ks = {k for k in names[a].defined if k not in skip}
    ks |= {r[1] for r in refs.get(a, ()) if r[1] not in skip}
    return ks


def state(a, members):
    own = [k for k in names[a].keys if k in owners]
    if own and not live(a, own) and not any(live(b) for b in members):
        return "one owner"
    return "open"


two_names = [a for a in addrs if len([k for k in names[a].keys if k not in owners]) > 1
             or len([x for x in names[a].symbols if key(x) not in owners]) > 1]

with open(os.path.join(out, "names.tsv"), "w") as fh:
    fh.write("address\tnames\tsymbols\tunits\tkind\tx64_size\textent_low\textent_high\tbasis\taccesses\n")
    for a in addrs:
        n = names[a]
        fh.write("0x%08x\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n" % (
            a, " ".join(n.keys), " ".join(n.symbols), len(n.units), n.kind, n.x64, n.lo, n.hi, n.basis, access_summary(a)))
with open(os.path.join(out, "families.tsv"), "w") as fh:
    fh.write("container\tname\tkind\textent_low\textent_high\tbasis\tclass\tmembers\tunits\tstate\tnote\n")
    for a, basis, cls, members, note in families:
        n = names[a]
        units = set(n.units)
        for b in members:
            units |= names[b].units
        fh.write("0x%08x\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\n" % (
            a, " ".join(n.keys), n.kind, n.lo, n.hi, basis, cls, len(members), len(units), state(a, members), note))
with open(os.path.join(out, "unknown.tsv"), "w") as fh:
    fh.write("container\tname\tkind\textent_low\textent_high\tbasis\tnames_in_uncertain_part\n")
    for a, basis, cls, members, note in unknown:
        n = names[a]
        fh.write("0x%08x\t%s\t%s\t%s\t%s\t%s\t%d\n" % (a, " ".join(n.keys), n.kind, n.lo, n.hi, basis, len(members)))
with open(os.path.join(out, "members.tsv"), "w") as fh:
    fh.write("container\taddress\toffset\tnames\tkind\tunits\taccesses\tunit_list\n")
    for a, basis, cls, members, note in families:
        for b in [a] + members:
            n = names[b]
            fh.write("0x%08x\t0x%08x\t%d\t%s\t%s\t%d\t%s\t%s\n" % (
                a, b, b - a, " ".join(n.keys), n.kind, len(n.units), access_summary(b), " ".join(sorted(n.units))))
with open(os.path.join(out, "two_names.tsv"), "w") as fh:
    fh.write("address\tsymbols\tunits\tdefined\tclass\n")
    for a in two_names:
        n = names[a]
        types = {type_code(s) for s in n.symbols}
        cls = "same object under two names" if len(n.keys) > 1 else "type disagreement"
        if len(n.keys) > 1 and len(types) > 1:
            cls += " and type disagreement"
        fh.write("0x%08x\t%s\t%d\t%s\t%s\n" % (a, " ".join(n.symbols), len(n.units), " ".join(n.defined), cls))

with open(os.path.join(out, "other_manglings.tsv"), "w") as fh:
    fh.write("address\tsymbol\tunits\n")
    for (a, s), units in sorted(other_mangling.items()):
        fh.write("0x%08x\t%s\t%d\n" % (a, s, len(units)))

c = collections.Counter(f[2] for f in families)
m = collections.Counter()
for f in families:
    m[f[2]] += len(f[3])
with open(os.path.join(out, "counts.txt"), "w") as fh:
    fh.write("recipe units\t%d\nobjects read\t%d\n32-bit objects read\t%d\n" % (len(recipe), objects, objects32))
    fh.write("extent basis\t%s\n" % dict(collections.Counter(names[a].basis for a in addrs)))
    fh.write("data addresses in the recipe\t%d\n" % len(addrs))
    fh.write("data names defined in an object\t%d\n" % sum(1 for a in addrs if names[a].defined))
    fh.write("data names defined in no object\t%d\n" % sum(1 for a in addrs if not names[a].defined))
    fh.write("addresses with code references\t%d\n" % sum(1 for a in addrs if refs.get(a)))
    fh.write("references not matched to one address\t%d names\n" % len(unmatched_refs))
    fh.write("recipe symbols left out\t%s\n" % dict(skipped))
    fh.write("distinct symbols with another mangling\t%d\n" % len(other_mangling))
    for k in sorted(c):
        fh.write("families: %s\t%d\tmembers\t%d\n" % (k, c[k], m[k]))
    st = collections.Counter(state(f[0], f[3]) for f in families)
    fh.write("families by state\t%s\n" % dict(st))
    fh.write("containers whose 32-bit extent is not measurable and may reach the next name\t%d\tnames\t%d\n" % (
        len(unknown), sum(len(f[3]) for f in unknown)))
    ku = collections.Counter(names[f[0]].kind for f in unknown)
    fh.write("  by kind\t%s\n" % dict(ku))
    fh.write("families total\t%d\n" % len(families))
    fh.write("addresses with more than one symbol\t%d\n" % len(two_names))
    fh.write("  of which different names\t%d\n" % sum(1 for a in two_names if len(names[a].keys) > 1))
    fh.write("  of which one name with different types\t%d\n" % sum(1 for a in two_names if len(names[a].keys) == 1))
print(open(os.path.join(out, "counts.txt")).read())
