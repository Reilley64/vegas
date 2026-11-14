#!/usr/bin/env python3
"""Host tests of bind_batch.py on hand-made AST fragments, texts and reports, with a fake
compiler named clang-cl and a fake objcmp.py that the tests write into a temporary folder."""
import copy
import hashlib
import json
import os
import shutil
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import bind_batch as bb  # noqa: E402

N = "?FUN_00401000@S@@QEAAHH@Z"
D = "?g@R@@QEAAHH@Z"
NDEM = "public: int __cdecl S::FUN_00401000(int) __ptr64"
N32 = "?FUN_00401000@S@@QAEHH@Z"
DDEM = "public: int __cdecl R::g(int) __ptr64"
CALLER = "?caller@@YAXPEAX@Z"

TEXT = (b"struct S {\n"
        b"    int FUN_00401000(int);\n"
        b"};\n"
        b"// the caller\n"
        b"void caller(void* p) {\n"
        b"    ((S*)p)->FUN_00401000(1);\n"
        b"}\n"
        b"// the owner\n"
        b"struct R {\n"
        b"    int g(int);\n"
        b"};\n")


def at(token, nth=0):
    i = -1
    for _ in range(nth + 1):
        i = TEXT.index(token, i + 1)
    return i


def loc(offset, tok=1):
    return {"offset": offset, "col": 1, "tokLen": tok}


def rng(begin, end, tok=1):
    return {"begin": loc(begin), "end": loc(end, tok)}


def method(ident, name, mangled, begin, end):
    return {"id": ident, "kind": "CXXMethodDecl", "loc": loc(begin), "range": rng(begin, end),
            "name": name, "mangledName": mangled, "type": {"qualType": "int (int)"}}


def record(ident, name, begin, end, inner):
    return {"id": ident, "kind": "CXXRecordDecl", "loc": loc(begin), "range": rng(begin, end),
            "name": name, "tagUsed": "struct", "completeDefinition": True, "inner": inner}


def items(used=False, owner_extra=(), stand_in_body=False):
    """Three top-level items: the stand-in S, the caller, the owner R."""
    f = method("0x2", "FUN_00401000", N, at(b"int FUN_"), at(b")", 0))
    if stand_in_body:
        f["inner"] = [{"id": "0x2b", "kind": "CompoundStmt"}]
    s = record("0x1", "S", at(b"struct S"), at(b"}"), [f])
    cast = {"id": "0x10", "kind": "CStyleCastExpr", "range": rng(at(b"(S*)"), at(b"p)->")),
            "type": {"qualType": "S *"}, "castKind": "BitCast", "inner": [
                {"id": "0x11", "kind": "ImplicitCastExpr", "range": rng(at(b"p)->"), at(b"p)->")),
                 "type": {"qualType": "void *"}, "castKind": "LValueToRValue", "inner": [
                     {"id": "0x12", "kind": "DeclRefExpr", "range": rng(at(b"p)->"), at(b"p)->")),
                      "type": {"qualType": "void *"}, "referencedDecl": {"id": "0x20", "name": "p"}}]}]}
    member = {"id": "0x13", "kind": "MemberExpr", "range": rng(at(b"((S*)"), at(b"FUN_00401000(1)"), 12),
              "name": "FUN_00401000",
              "isArrow": True, "referencedMemberDecl": "0x2", "inner": [
                  {"id": "0x14", "kind": "ParenExpr", "range": rng(at(b"((S*)"), at(b")->")), "inner": [cast]}]}
    call = {"id": "0x15", "kind": "CXXMemberCallExpr", "range": rng(at(b"((S*)"), at(b");")),
            "type": {"qualType": "int"}, "inner": [member, {
                "id": "0x16", "kind": "IntegerLiteral", "range": rng(at(b"1)"), at(b"1)")),
                "type": {"qualType": "int"}, "value": "1"}]}
    if used in (False, True):
        stmt = {"id": "0x17", "kind": "ReturnStmt" if used else "CompoundStmt", "inner": [call]}
    else:  # a cast of the call: ("CStyleCastExpr", castKind)
        stmt = {"id": "0x17", "kind": used[0], "castKind": used[1], "inner": [call]}
    body = stmt if used is False else {"id": "0x18", "kind": "CompoundStmt", "inner": [stmt]}
    caller = {"id": "0x3", "kind": "FunctionDecl", "loc": loc(at(b"caller")),
              "range": rng(at(b"void caller"), at(b"}", 1)), "name": "caller",
              "mangledName": CALLER, "inner": [body]}
    r = record("0x4", "R", at(b"struct R"), at(b"}", 2), [
        method("0x5", "g", D, at(b"int g"), at(b")", 3))] + list(owner_extra))
    return [s, caller, r]


def dump_lines(nodes):
    """The JSON dump's form: one top-level item per block of lines at four spaces."""
    lines = []
    for n in nodes:
        text = json.dumps(n, indent=2)
        lines += ["    " + l + "\n" for l in text.split("\n")]
        lines[-1] = lines[-1].rstrip("\n") + ",\n"
    return lines


def facts(used=False):
    return bb.extract(None, {N}, {D}, dump_lines(items(used)))


# A fake clang-cl: reads the unit (through a -vfsoverlay root when one maps it), prints an AST dump
# file named on its command line, prints record layouts from "// layout name size" lines (of the
# class NAME in capitals, while the text defines it) and "// layout-unnamed" lines (an unnamed
# union named by its line), or writes the unit's text and the variant as its object.
FAKE_COMPILER = r"""import json, os, sys
args = sys.argv[1:]
source = args[-1]
for i, a in enumerate(args):
    if a == "-vfsoverlay":
        with open(args[i + 1]) as f:
            root = json.load(f)["roots"][0]
        if os.path.normcase(os.path.normpath(root["name"])) == os.path.normcase(os.path.abspath(source)):
            source = root["external-contents"]
with open(source) as f:
    text = f.read()
if text.startswith("#error") or "fail-compile" in text:
    print(text)
    sys.exit(1)
if "-ast-dump=json" in args:
    ast = [a for a in args if a.endswith(".ast")]
    if not ast:
        sys.exit(1)
    with open(ast[0]) as f:
        sys.stdout.write(f.read())
    sys.exit(0)
if "-fdump-record-layouts-complete" in args:
    target = [a for a in args if a.startswith("--target=")][0][len("--target="):]
    if "layout-fail " + target in text:
        sys.exit(1)
    for number, line in enumerate(text.splitlines(), 1):
        if line.startswith("// layout-unnamed"):
            print("*** Dumping AST Record Layout")
            print("         0 | union U::(unnamed at %s:%d:5)" % (args[-1], number))
            print("           | [sizeof=8, align=8,")
            print("")
        if line.startswith("// layout ") and "struct %s {" % line.split()[2].upper() in text:
            name, size = line.split()[2].upper(), line.split()[3]
            print("*** Dumping AST Record Layout")
            print("         0 | struct %s%s" % (name, " (empty)" if size == "1" else ""))
            print("           | [sizeof=%s, align=1," % size)
            print("           |  nvsize=0, nvalign=1]")
            print("")
    sys.exit(0)
variant = "od" if "/Od" in args else "ob0" if "/Ob0" in args else "flags"
with open([a[3:] for a in args if a.startswith("/Fo")][0], "w") as f:
    json.dump({"text": text, "variant": variant}, f)
"""

# A fake objcmp.py: logs its arguments; without a map, the head's "// moves-report {json}" line
# gives the report, else equal texts are "identical: the bytes are equal" unless the head says
# "moves-differ"; with a map, the head's "// report VARIANT {json}"
# line gives the report (VARIANT or *), else "identical ... once the renames are applied" with
# one retarget per rename from CALLER.
FAKE_OBJCMP = r"""import json, os, sys
args = sys.argv[1:]
with open(os.environ["FAKE_OBJCMP_LOG"], "a") as f:
    f.write(json.dumps(args) + "\n")
with open(args[0]) as f:
    a = json.load(f)
with open(args[1]) as f:
    b = json.load(f)
renames = {}
if "--map" in args:
    with open(args[args.index("--map") + 1]) as f:
        renames = dict(l.strip().split("=", 1) for l in f if l.strip())
report = None
for line in b["text"].splitlines():
    for variant in (b["variant"], "*"):
        if renames and line.startswith("// report %s " % variant):
            report = json.loads(line[len("// report %s " % variant):])
for line in b["text"].splitlines():
    if not renames and line.startswith("// moves-report "):
        report = json.loads(line[len("// moves-report "):])
if report is None and not renames:
    if a["text"] == b["text"] or "moves-differ" not in b["text"]:
        report = dict(verdict="identical: the bytes are equal with the timestamp masked", result="identical", exit=0)
    else:
        report = dict(verdict="differs: 1 difference(s)", result="differs", exit=1, lines=["SECTION-DIFFERS\tx"])
if report is None:
    report = dict(verdict="identical: equal with the timestamp masked once the renames are applied",
                  result="identical", exit=0)
report.setdefault("lines", [])
report.setdefault("retargets", [dict(old=o, new=n, count=1, by_map=True, functions=["CALLER_NAME"])
                                for o, n in renames.items()])
print(json.dumps(report))
sys.exit(report["exit"])
""".replace("CALLER_NAME", CALLER)


class Folder(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.mkdtemp()
        self.dir = os.path.join(self.root, "with space")
        os.mkdir(self.dir)

    def tearDown(self):
        shutil.rmtree(self.root)

    def write(self, name, data):
        path = os.path.join(self.dir, name)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, "wb") as f:
            f.write(data.encode() if isinstance(data, str) else data)
        return path

    def clang(self):
        """A command named clang-cl, in its own folder, that runs FAKE_COMPILER."""
        script = self.write("bin/compiler.py", FAKE_COMPILER)
        if os.name == "nt":
            return self.write("bin/clang-cl.cmd", '@"%s" "%s" %%*\r\n' % (sys.executable, script))
        path = self.write("bin/clang-cl", "#!%s\n%s" % (sys.executable, FAKE_COMPILER))
        os.chmod(path, 0o755)
        return path

    def build(self, text, unit="src/u.cpp"):
        """A build folder whose compile_commands.json holds UNIT, compiled by the fake clang-cl."""
        source = self.write(unit, text)
        build = os.path.join(self.dir, "build")
        os.makedirs(build, exist_ok=True)
        entry = dict(directory=build, file=source, output="CMakeFiles/game.dir/%s.obj" % unit,
                     arguments=[self.clang(), "--target=x86_64-pc-windows-msvc", "/O2", "-c", "--", source])
        with open(os.path.join(build, "compile_commands.json"), "w") as f:
            json.dump([entry], f)
        return build, source, entry


class SignatureTest(unittest.TestCase):
    def test_member(self):
        s = bb.signature(NDEM)
        self.assertEqual((s["member"], s["scope"], s["base"], s["ret"], s["params"], s["quals"]),
                         (True, "S", "FUN_00401000", "int", ["int"], ""))

    def test_free_static_virtual_const(self):
        s = bb.signature("void __cdecl ns::h(class A * __ptr64,void (__cdecl*)(int,int))")
        self.assertEqual((s["member"], s["scope"], s["params"]),
                         (False, "ns", ["class A *", "void (__cdecl*)(int,int)"]))
        self.assertTrue(bb.signature("public: static int __cdecl X::k(void)")["static"])
        self.assertTrue(bb.signature("public: virtual void __cdecl X::v(void) __ptr64")["virtual"])
        self.assertEqual(bb.signature("public: int __cdecl X::c(void) const __ptr64")["quals"], "const")
        self.assertTrue(bb.signature("public: __cdecl X::X(void) __ptr64")["special"])

    def test_calling_convention_at_depth_0(self):
        # A function returning a function pointer spells its own convention inside the brackets.
        self.assertIsNone(bb.signature("public: void (__cdecl * __cdecl S::f(int))(int) __ptr64"))
        self.assertIsNone(bb.signature("void (__cdecl *__cdecl f(int))(long)"))
        s = bb.signature("class Q<void (__cdecl*)(int)> * __cdecl f(int)")
        self.assertEqual((s["cc"], s["ret"], s["base"]), ("__cdecl", "class Q<void (__cdecl*)(int)> *", "f"))
        self.assertEqual(bb.signature("int __vectorcall f(int)")["cc"], "__vectorcall")

    def test_strict_key_joins_32_and_64(self):
        self.assertEqual(bb.strict_key("public: int __thiscall S::FUN_00401000(int)"), bb.strict_key(NDEM))


class ExtractTest(unittest.TestCase):
    def test_declarations_and_site(self):
        f = facts()
        self.assertEqual([d["id"] for d in f["decls"][N]], ["0x2"])
        self.assertEqual(f["decls"][D][0]["record"]["name"], "R")
        [ref] = f["refs"]
        self.assertEqual((ref["target"], ref["call"], ref["used"], ref["function"]),
                         ("0x2", True, False, CALLER))
        self.assertEqual(ref["receiver"]["kind"], "CStyleCastExpr")
        self.assertEqual(TEXT[ref["name_span"][0]:ref["name_span"][1]], b"FUN_00401000")

    def test_unparsed_items_list_their_types(self):
        nodes = items()
        nodes.insert(1, {"id": "0x9", "kind": "CXXRecordDecl", "loc": loc(at(b"// the caller")),
                         "range": rng(at(b"// the caller"), at(b"// the caller") + 3), "name": "T",
                         "inner": [{"id": "0xa", "kind": "FieldDecl"}]})
        f = bb.extract(None, {N}, {D}, dump_lines(nodes))
        self.assertIn("T", [t["name"] for t in f["types"]])

    def test_header_locations_are_not_main(self):
        self.assertTrue(bb.is_main({"offset": 3}))
        self.assertFalse(bb.is_main({"offset": 3, "includedFrom": {"file": "x.cpp"}}))
        self.assertFalse(bb.is_main({"offset": 3, "spellingLoc": {}, "expansionLoc": {}}))
        self.assertTrue(bb.is_macro({"spellingLoc": {}, "expansionLoc": {}}))

    def test_lambda_site(self):
        nodes = items()
        nodes[1]["inner"] = [{"id": "0x30", "kind": "LambdaExpr", "inner": nodes[1]["inner"]}]
        f = bb.extract(None, {N}, {D}, dump_lines(nodes))
        self.assertTrue(f["refs"][0]["template"])
        self.assertFalse(facts()["refs"][0]["template"])

    def test_use_of_the_result(self):
        self.assertFalse(facts(("CStyleCastExpr", "ToVoid"))["refs"][0]["used"])
        self.assertTrue(facts(("CStyleCastExpr", "IntegralCast"))["refs"][0]["used"])
        self.assertTrue(facts(True)["refs"][0]["used"])

    def test_declarations_of_the_owner_name(self):
        other = method("0x6", "g", "?g@R@@QEAAH_J@Z", at(b"int g"), at(b")", 3))
        f = bb.extract(None, {N}, {D}, dump_lines(items(owner_extra=[other])))
        self.assertEqual(sorted(x["mangled"] for x in f["funcs"] if x["name"] == "g"), ["?g@R@@QEAAHH@Z",
                                                                                         "?g@R@@QEAAH_J@Z"])
        self.assertEqual({x["record"] for x in f["funcs"] if x["name"] == "g"}, {"0x4"})


class GateTest(unittest.TestCase):
    def decide(self, ndem=NDEM, ddem=DDEM, used=False, edit=None, address="0x00401000"):
        f = facts(used)
        ref = f["refs"][0]
        if edit:
            edit(ref, f)
        return bb.gate_site(ref, N, D, bb.signature(ndem), bb.signature(ddem), f["decls"][N][0], f["decls"][D], TEXT,
                            address)

    def test_same_type_admits(self):
        # The fixture's placeholder member becomes another name in another class.
        self.assertEqual(self.decide(), (None, "name+class"))
        self.assertEqual(self.decide(ddem=DDEM.replace("R::", "S::")), (None, ""))

    def test_void_result_used(self):
        void = DDEM.replace("int __cdecl", "void __cdecl")
        self.assertEqual(self.decide(ddem=void, used=True)[0], "void-result-used")
        self.assertEqual(self.decide(ddem=void)[0], "conversion:result")
        self.assertEqual(self.decide(ddem=void, used=("CStyleCastExpr", "ToVoid"))[0], "conversion:result")
        self.assertEqual(self.decide(ddem=void, used=("CStyleCastExpr", "IntegralCast"))[0], "void-result-used")
        self.assertEqual(self.decide(ddem=DDEM.replace("int __cdecl", "short __cdecl"))[0], "conversion:result")

    def test_parameter_conversions(self):
        self.assertEqual(self.decide(ddem=DDEM.replace("(int)", "(bool)")),
                         ("conversion:literal-bool", "1: int -> bool"))
        self.assertEqual(self.decide(ddem=DDEM.replace("(int)", "(short)"))[0], "conversion:parameter")

        def literal(value, kind="IntegerLiteral"):
            def edit(ref, f):
                ref["args"][0].update(value=value, kind=kind)
            return edit
        for edit in (literal("2"), literal("1", "DeclRefExpr")):
            self.assertEqual(self.decide(ddem=DDEM.replace("(int)", "(bool)"), edit=edit)[0], "conversion:parameter")
        self.assertEqual(self.decide(NDEM.replace("(int)", "(float)"), DDEM.replace("(int)", "(bool)"))[0],
                         "conversion:parameter")

    def test_object_pointer_to_void_pointer(self):
        ndem, ddem = NDEM.replace("(int)", "(class A * __ptr64)"), DDEM.replace("(int)", "(void * __ptr64)")
        self.assertEqual(self.decide(ndem, ddem), (None, "R5a+name+class"))

        def derived_to_base(ref, f):
            ref["args"][0]["casts"] = ["DerivedToBase"]
        self.assertEqual(self.decide(ndem, ddem, edit=derived_to_base)[0], "conversion:parameter")
        for cv in ("const", "volatile"):
            self.assertEqual(self.decide(NDEM.replace("(int)", "(class A %s * __ptr64)" % cv), ddem)[0],
                             "conversion:parameter")
        self.assertEqual(self.decide(NDEM, ddem)[0], "conversion:parameter")
        self.assertEqual(self.decide(ndem, DDEM.replace("(int)", "(class B * __ptr64)"))[0], "conversion:parameter")

    def test_call_form_virtual_this_count(self):
        self.assertEqual(self.decide(ddem="int __cdecl g(int)")[0], "call-form:member-free")

        def free_call(ref, f):
            ref["kind"] = "DeclRefExpr"
        self.assertEqual(self.decide(edit=free_call)[0], "call-form:member-free")
        self.assertEqual(self.decide(ndem="public: __cdecl S::S(int) __ptr64")[0], "call-form:special-member")
        self.assertEqual(self.decide(ddem="public: __cdecl R::R(int) __ptr64")[0], "call-form:special-member")
        self.assertEqual(self.decide(ddem=DDEM.replace("public: ", "public: virtual "))[0], "virtual")
        self.assertEqual(self.decide(ndem=NDEM.replace("public: ", "public: virtual "))[0], "virtual")

        def owner_virtual(ref, f):
            f["decls"][D][0]["virtual"] = True
        self.assertEqual(self.decide(edit=owner_virtual)[0], "virtual")
        self.assertEqual(self.decide(ndem=NDEM.replace(") __ptr64", ") const __ptr64"))[0], "conversion:this")
        self.assertEqual(self.decide(ddem=DDEM.replace(") __ptr64", ") volatile __ptr64"))[0], "conversion:this")
        self.assertEqual(self.decide(ddem=DDEM.replace(") __ptr64", ") const __ptr64")),
                         (None, "const-this+name+class"))
        self.assertEqual(self.decide(ddem=DDEM.replace("(int)", "(int,int)"))[0], "conversion:parameter-count")
        self.assertEqual(self.decide(ddem=DDEM.replace("__cdecl", "__vectorcall"))[0],
                         "conversion:calling-convention")

    def test_static_against_free(self):
        def free_call(ref, f):
            ref["kind"] = "DeclRefExpr"
        self.assertEqual(self.decide("public: static int __cdecl S::f(int)", "int __cdecl ns::g(int)",
                                     edit=free_call)[0], "call-form:static-free")
        self.assertEqual(self.decide("int __cdecl f(int)", "public: static int __cdecl R::g(int)",
                                     edit=free_call)[0], "call-form:static-free")

    def test_site_and_receiver_refusals(self):
        def flag(key, value):
            return lambda ref, f: ref.__setitem__(key, value)
        self.assertEqual(self.decide(edit=flag("macro", True))[0], "site:macro")
        self.assertEqual(self.decide(edit=flag("header", True))[0], "site:header")
        self.assertEqual(bb.position(TEXT, None), ("", ""))
        self.assertEqual(self.decide(edit=flag("template", True))[0], "site:template")
        self.assertEqual(self.decide(edit=flag("call", False))[0], "site:not-a-call")

        def receiver(key, value):
            return lambda ref, f: ref["receiver"].__setitem__(key, value)
        self.assertEqual(self.decide(edit=receiver("kind", "CXXThisExpr"))[0], "receiver:not-a-cast")
        self.assertEqual(self.decide(edit=receiver("implicit", ["UncheckedDerivedToBase"]))[0], "receiver:conversion")
        self.assertEqual(self.decide(edit=receiver("operand", (at(b"S*)") + 1, at(b"p)->"))))[0],
                         "receiver:cast-text")

        def other_record(ref, f):
            f["decls"][N][0]["record"]["name"] = "T"
        self.assertEqual(self.decide(edit=other_record)[0], "receiver:cast-text")

        def default_arg(ref, f):
            ref["args"][0]["default"] = True
        self.assertEqual(self.decide(edit=default_arg)[0], "conversion:default-argument")

        def other_name(ref, f):
            ref["name_span"] = (at(b"S*)"), at(b"S*)") + 1)
        self.assertEqual(self.decide(edit=other_name)[0], "site:name-text")

    def test_naming(self):
        def naming(stand, owner, address="0x00410020"):
            return bb.naming(bb.signature(stand), bb.signature(owner), address)
        place = "public: int __cdecl FUN_00410020_t::FUN_00410020(int) __ptr64"
        # A descriptive function name never becomes a placeholder; two descriptive names differ.
        self.assertEqual(naming("public: int __cdecl S::Remove(int) __ptr64", place),
                         ("naming:descriptive-function", "Remove -> FUN_00410020"))
        self.assertEqual(naming("public: int __cdecl S::f(int) __ptr64", DDEM),
                         ("naming:descriptive-differs", "f -> g"))
        self.assertEqual(naming("void * __cdecl NiMallocB58(unsigned int)", "void * __cdecl FUN_00aa1070(unsigned int)",
                                "0x00aa1070"), ("naming:descriptive-function", "NiMallocB58 -> FUN_00aa1070"))
        # The member is the row's placeholder on both sides, only the class differs: class-only.
        self.assertEqual(naming("public: int __cdecl S::FUN_00410020(int) __ptr64", place), (None, "class-only"))
        self.assertEqual(naming(place, place), (None, ""))
        # The class is compared by its full scope: one class name in two namespaces differs.
        self.assertEqual(naming("public: int __cdecl a::S::FUN_00410020(int) __ptr64",
                                "public: int __cdecl b::S::FUN_00410020(int) __ptr64"), (None, "class-only"))
        self.assertEqual(naming("public: static int __cdecl a::S::FUN_00410020(int)",
                                "public: static int __cdecl b::S::FUN_00410020(int)"), (None, "class-only"))
        self.assertEqual(naming("public: int __cdecl a::S::FUN_00410020(int) __ptr64",
                                "public: int __cdecl a::S::FUN_00410020(int) __ptr64"), (None, ""))
        # A placeholder may become a descriptive name: in another class it is labelled name+class;
        # free functions carry no class.
        self.assertEqual(naming("public: int __cdecl S::FUN_00410020_x(int) __ptr64", DDEM), (None, "name+class"))
        self.assertEqual(naming("public: int __cdecl R::FUN_00410020_x(int) __ptr64", DDEM), (None, ""))
        self.assertEqual(naming("public: static int __cdecl S::FUN_00410020_x(int)",
                                "public: static int __cdecl R::g(int)"), (None, "name+class"))
        self.assertEqual(naming("int __cdecl a::FUN_00410020(int)", "int __cdecl b::FUN_00410020(int)"), (None, ""))
        # At a site, the refusal comes before the name text and the label joins the others.
        self.assertEqual(self.decide(ndem="public: int __cdecl S::f(int) __ptr64"), ("naming:descriptive-differs",
                                                                                      "f -> g"))
        self.assertEqual(self.decide(ddem="public: int __cdecl R::FUN_00401000(int) const __ptr64"),
                         (None, "const-this+class-only"))

    def test_written_type(self):
        self.assertEqual(bb.written_type(b"(S*)", "CStyleCastExpr", "S"), (1, 2))
        self.assertEqual(bb.written_type(b"( ::ns::S const *)", "CStyleCastExpr", "S"), (2, 9))
        self.assertEqual(bb.written_type(b"reinterpret_cast<S &>(", "CXXReinterpretCastExpr", "S"), (17, 18))
        self.assertIsNone(bb.written_type(b"(T<S>*)", "CStyleCastExpr", "S"))
        self.assertIsNone(bb.written_type(b"(S**)", "CStyleCastExpr", "S"))


class GateUnitTest(Folder):
    """gate_unit on a unit whose AST the fake compiler prints."""

    def run_gate(self, nodes=None, ctx=None, ast=True, rows=None):
        build, source, entry = self.build(TEXT)
        if ast:
            entry["arguments"].insert(1, self.write("u.ast", "{\n" + "".join(dump_lines(nodes or items())) + "}\n"))
        dem = {N: NDEM, D: DDEM}
        full = dict(recipe=lambda unit, n, d, a: (None, (N32, "?g@R@@QAEHH@Z")),
                    sig={k: bb.signature(v) for k, v in dem.items()}, dem=dem, differing=set(), undefined={NDEM})
        full.update(ctx or {})
        rows = rows or [dict(unit="src/u.cpp", site="*", name=N, owner=D, address="0x00401000")]
        return bb.gate_unit(("src/u.cpp", rows, entry, full))

    def kinds(self, out):
        return [(r["decision"], r["kind"]) for r in out]

    def placeholder(self):
        return {}

    def test_admit(self):
        out, plan = self.run_gate(ctx=self.placeholder())
        self.assertEqual(self.kinds(out), [("ADMIT", "name+class")])
        p = plan["names"][N]
        self.assertEqual((p["key"], p["row"], p["kept"], len(p["sites"])), (N32, "?g@R@@QAEHH@Z", [], 1))
        self.assertEqual(p["stand_in"]["qualified"], "S")
        self.assertEqual(bb.whole_names([plan]), {N})

    def test_refusals_per_candidate(self):
        ph = self.placeholder()
        cases = [
            (dict(ph, recipe=lambda *a: ("recipe:no-key", "0 keys")), "recipe:no-key"),
            (dict(ph, differing={N}), "differing-definitions"),
            (dict(ph, differing={D}), "differing-definitions"),
            (dict(ph, undefined=set()), "defined:not-listed"),
            (dict(ph, undefined={NDEM, DDEM}), "defined:owner-undefined"),
            (dict(ph, undefined={NDEM, D}), "defined:owner-undefined"),
            (dict(ph, sig={N: None, D: bb.signature(DDEM)}), "signature:unreadable"),
        ]
        for ctx, kind in cases:
            out, plan = self.run_gate(ctx=ctx)
            self.assertEqual(self.kinds(out), [("REFUSE", kind)], kind)
            self.assertEqual(plan["refused"], [N], kind)
            self.assertEqual(bb.whole_names([plan]), set(), kind)
        # The tip's list names the stand-in mangled or as llvm-undname prints it.
        self.assertEqual(self.kinds(self.run_gate(ctx=dict(ph, undefined={N}))[0]), [("ADMIT", "name+class")])
        self.assertEqual(self.kinds(self.run_gate(ctx=dict(ph, undefined={NDEM}))[0]), [("ADMIT", "name+class")])

    def test_defined_overloaded_and_unreadable(self):
        ph = self.placeholder()
        out, _ = self.run_gate(items(stand_in_body=True), ph)
        self.assertEqual(self.kinds(out), [("REFUSE", "defined:name")])
        other = method("0x6", "g", "?g@R@@QEAAH_J@Z", at(b"int g"), at(b")", 3))
        out, _ = self.run_gate(items(owner_extra=[other]), ph)
        self.assertEqual(self.kinds(out), [("REFUSE", "overload:owner")])
        self.assertEqual(out[0]["detail"], "?g@R@@QEAAH_J@Z")
        template = {"id": "0x7", "kind": "FunctionTemplateDecl", "name": "g", "range": rng(0, 1)}
        out, _ = self.run_gate(items(owner_extra=[template]), ph)
        self.assertEqual(self.kinds(out), [("REFUSE", "overload:owner")])
        out, plan = self.run_gate(ctx=ph, ast=False)
        self.assertEqual(self.kinds(out), [("REFUSE", "extract:failed")])
        self.assertEqual(plan["refused"], [N])

    def test_a_refused_site_keeps_the_name(self):
        ph = self.placeholder()
        nodes = items()
        nodes[1]["inner"][0]["inner"][0]["inner"][0]["isArrow"] = True
        nodes[1]["inner"][0]["inner"][0]["inner"][0]["inner"][0]["inner"][0]["kind"] = "CXXStaticCastExpr"
        out, plan = self.run_gate(nodes, ph)
        self.assertEqual(self.kinds(out), [("REFUSE", "receiver:cast-text")])
        self.assertEqual(plan["names"][N]["kept"], [CALLER])
        self.assertEqual(bb.whole_names([plan]), set())


class RecipeTest(unittest.TestCase):
    def recipe(self):
        return {"units": [{"source": "u.cpp", "functions": [], "symbols": {"a": "0x1", "old": "0x2", "z": "0x3"}},
                          {"source": "u.cpp", "functions": [], "symbols": {"x": "0x9"}},
                          {"source": "v.cpp", "functions": [{"address": "0x2", "symbol": "new"}], "symbols": {}}]}

    def test_respell_in_place(self):
        r = self.recipe()
        bb.respell_keys(r, "u.cpp", "0x2", "old", "new")
        self.assertEqual(list(r["units"][0]["symbols"]), ["a", "new", "z"])
        self.assertEqual(r["units"][0]["symbols"]["new"], "0x2")

    def test_every_entry_that_holds_the_key(self):
        r = self.recipe()
        r["units"][1]["symbols"] = {"old": "0x00000002", "x": "0x9"}
        bb.respell_keys(r, "u.cpp", "0x00000002", "old", "new")
        self.assertEqual([list(u["symbols"]) for u in r["units"][:2]], [["a", "new", "z"], ["new", "x"]])

    def test_merge_into_existing_key_of_another_entry(self):
        r = self.recipe()
        r["units"][1]["symbols"]["new"] = "0x2"
        bb.respell_keys(r, "u.cpp", "0x2", "old", "new")
        self.assertNotIn("old", r["units"][0]["symbols"])
        self.assertEqual(r["units"][1]["symbols"]["new"], "0x2")

    def test_conflicts_change_nothing(self):
        for change in (lambda r: r["units"][1]["symbols"].__setitem__("new", "0x7"),
                       lambda r: r["units"][1]["symbols"].__setitem__("old", "0x7"),
                       lambda r: r["units"][0]["symbols"].pop("old")):
            r = self.recipe()
            change(r)
            before = copy.deepcopy(r)
            with self.assertRaises(ValueError):
                bb.respell_keys(r, "u.cpp", "0x2", "old", "new")
            self.assertEqual(r, before)

    def test_index_merges_entries(self):
        syms, rows = bb.recipe_index(self.recipe())
        self.assertEqual(sorted(syms["u.cpp"]), ["a", "old", "x", "z"])
        self.assertEqual(rows[2], ("v.cpp", "new"))

    def test_recipe_check(self):
        dem32 = {N32: "public: int __thiscall S::FUN_00401000(int)",
                 "?f2@S@@QAEHH@Z": "public: int __thiscall S::FUN_00401000(int)",
                 "?g@R@@QAEHH@Z": "public: int __thiscall R::g(int)",
                 "?h@Q@@QAEHH@Z": "public: int __thiscall Q::h(int)"}
        dem64 = {N: NDEM, D: DDEM}
        rows = {0x401000: ("o.cpp", "?g@R@@QAEHH@Z")}

        def check(keys, rowsyms=rows, address="0x00401000"):
            return bb.recipe_check({"u.cpp": keys}, rowsyms, dem32, dem64, "u.cpp", N, D, address)
        self.assertEqual(check({N32: {0x401000}}), (None, (N32, "?g@R@@QAEHH@Z")))
        self.assertEqual(check({})[0], "recipe:no-key")
        self.assertEqual(check({N32: {0x402000}})[0], "recipe:no-key")
        self.assertEqual(check({N32: {0x401000, 0x402000}})[0], "recipe:no-key")
        self.assertEqual(check({N32: {0x401000}, "?f2@S@@QAEHH@Z": {0x401000}})[0], "recipe:no-key")
        self.assertEqual(check({"?h@Q@@QAEHH@Z": {0x401000}})[0], "recipe:no-key")
        self.assertEqual(check({N32: {0x401000}}, {0x401000: ("o.cpp", "?h@Q@@QAEHH@Z")})[0],
                         "recipe:no-row")
        self.assertEqual(check({N32: {0x401000}}, {})[0], "recipe:no-row")
        self.assertEqual(check({N32: {0x401000}}, address="401000")[0], "recipe:address")


class RewriteTest(unittest.TestCase):
    def plan(self):
        f = facts()
        ref = f["refs"][0]
        nsig, dsig = bb.signature(NDEM), bb.signature(DDEM)
        scoped = [x for x in f["decls"][D] if x["scoped"]]
        moves, why = bb.placement(ref, dsig, scoped, TEXT, f["types"])
        self.assertIsNone(why)
        rec = f["decls"][N][0]["record"]
        site = bb.site_edits(ref, nsig, dsig, f["decls"][D], scoped, TEXT)
        return dict(names={N: dict(owner=D, moves=moves, sites=[site],
                                   removals=bb.removals(f["decls"][N], nsig, TEXT), kept=[],
                                   stand_in=dict(name="S", cut=bb.whole_lines(TEXT, rec["span"]), qualified="S"))})

    def test_move_then_bind(self):
        plan = self.plan()
        moved = bb.render(TEXT, plan, [N], "moves")
        self.assertEqual(sorted(moved.split(b"\n")), sorted(TEXT.split(b"\n")))
        self.assertLess(moved.index(b"struct R"), moved.index(b"// the caller"))
        bound = bb.render(TEXT, plan, [N], "bind")
        self.assertIn(b"((::R*)p)->g(1);", bound)
        self.assertNotIn(b"int FUN_00401000(int);", bound)
        self.assertNotIn(b"struct S", bound)
        self.assertIn(b"// the owner\nstruct R {", bound)

    def test_stand_in_named_elsewhere_stays(self):
        plan = self.plan()
        text = TEXT + b"S* keep;\n"
        bound = bb.render(text, plan, [N], "bind")
        self.assertIn(b"struct S {\n};\n", bound)

    def test_no_move_when_visible(self):
        f = facts()
        ref = dict(f["refs"][0], item=99, offset=len(TEXT))
        scoped = [x for x in f["decls"][D] if x["scoped"]]
        self.assertEqual(bb.placement(ref, bb.signature(DDEM), scoped, TEXT, f["types"]), ([], None))

    def test_wrapped_move(self):
        plan = self.plan()
        plan["names"][N]["moves"][0]["wrap"] = ["ns"]
        self.assertIn(b"namespace ns {\n// the owner\nstruct R {\n    int g(int);\n};\n}  // namespace ns\n",
                      bb.render(TEXT, plan, [N], "moves"))

    def test_overlapping_edits_refused(self):
        plan = self.plan()
        cut = plan["names"][N]["moves"][0]["cut"]
        plan["names"][N]["removals"].append((cut[0] + 1, cut[0] + 3))
        with self.assertRaises(ValueError):
            bb.render(TEXT, plan, [N], "bind")

    def test_whole_names(self):
        plans = [dict(names={"a": dict(sites=[1], kept=[]), "b": dict(sites=[1], kept=["f"])}),
                 dict(names={"a": dict(sites=[1], kept=[]), "c": dict(sites=[], kept=[]),
                             "d": dict(sites=[1], kept=[])}),
                 dict(names={}, refused=["d"])]
        self.assertEqual(bb.whole_names(plans), {"a"})


def report(result, verdict, merges=None, code=0, lines=()):
    rep = dict(result=result, verdict=verdict, exit=code, lines=list(lines))
    if merges is not None:
        rep["merges"] = [dict(old=N, new=D, into=m, relocations=1) for m in merges]
    return rep


RENAMED = "identical: equal with the timestamp masked once the renames are applied"


class ProofModeTest(unittest.TestCase):
    def test_modes(self):
        self.assertEqual(bb.proof_mode(report("identical", RENAMED)), "strict")
        self.assertIsNone(bb.proof_mode(report("identical",
                                               "identical: the bytes are equal with the timestamp masked")))
        self.assertEqual(bb.proof_mode(report("merged", "merged: ...", ["definition"])), "merge-definition")
        self.assertEqual(bb.proof_mode(report("merged", "merged: ...", ["reference"])), "merge-reference")
        self.assertEqual(bb.proof_mode(report("reordered", "reordered: ...", [])), "function-order")
        self.assertEqual(bb.proof_mode(report("merged and reordered", "merged and reordered: ...", ["definition"])),
                         "merge-definition+function-order")
        for rep in (report("merged", "merged: ...", ["definition"], code=1), report("differs", "differs: 1"),
                    report("kept", "kept: ..."), report("refused", "refused: ..."), report("merged", "merged", [])):
            self.assertIsNone(bb.proof_mode(rep), rep)


class ProveTest(Folder):
    """compare and prove_unit with the fake compiler and the fake objcmp.py."""

    def setUp(self):
        super().setUp()
        self.objcmp_log = os.path.join(self.dir, "objcmp.log")
        os.environ["FAKE_OBJCMP_LOG"] = self.objcmp_log
        self.saved = bb.OBJCMP
        bb.OBJCMP = self.write("objcmp.py", FAKE_OBJCMP)

    def tearDown(self):
        bb.OBJCMP = self.saved
        del os.environ["FAKE_OBJCMP_LOG"]
        super().tearDown()

    def prove(self, extra=b"", defined_here=False, moves=True):
        text = TEXT + extra
        build, source, _ = self.build(text)
        plan = RewriteTest.plan(self) if moves else None
        if not moves:
            plan = RewriteTest.plan(self)
            plan["names"][N]["moves"] = []
        plan.update(unit="src/u.cpp", file=source)
        work = os.path.join(self.dir, "work")
        return bb.prove_unit((build, plan, [N], work, {N: defined_here})), work

    def test_compare_reads_the_verdict(self):
        build, source, _ = self.build(TEXT)
        base, head = os.path.join(self.dir, "base"), os.path.join(self.dir, "head")
        self.assertIsNone(bb.compile_text(build, "src/u.cpp", TEXT, base))
        self.assertIsNone(bb.compile_text(build, "src/u.cpp", TEXT + b"// x\n", head))
        res = bb.compare(base, head, {N: D}, head)
        self.assertEqual({v: (r[0], r[3]) for v, r in res.items()}, {v: (True, "strict") for v in bb.VARIANTS})
        with open(self.objcmp_log) as f:
            args = json.loads(f.readline())
        self.assertIn("--base-holds-new", args)
        with open(args[args.index("--function-order") + 1]) as f:
            self.assertEqual(f.read(), D + "\n")
        # Without renames only equal bytes pass.
        self.assertTrue(all(r[0] for r in bb.compare(base, head, {}, head).values()))
        self.assertIsNone(bb.compile_text(build, "src/u.cpp", TEXT + b"// moves-differ\n", head))
        self.assertFalse(any(r[0] for r in bb.compare(base, head, {}, head).values()))
        renamed = json.dumps(report("identical", RENAMED))
        self.assertIsNone(bb.compile_text(build, "src/u.cpp", TEXT + b"// moves-report " + renamed.encode() + b"\n",
                                          head))
        self.assertFalse(any(r[0] for r in bb.compare(base, head, {}, head).values()))
        # A head whose warnings differ fails.
        self.assertIsNone(bb.compile_text(build, "src/u.cpp", TEXT + b"// x\n", head))
        with open(head + ".od.log", "a") as f:
            f.write("u.cpp(1,1): warning: new [-Wnew]\n")
        res = bb.compare(base, head, {N: D}, head)
        self.assertEqual((res["od"][0], res["od"][1], res["flags"][0]), (False, "warnings differ", True))

    def test_prove_unit_modes_and_rows(self):
        merged = json.dumps(report("merged", "merged: x", ["definition"]))
        (verdicts, rows), work = self.prove(b"// report * " + merged.encode() + b"\n// layout s 1\n")
        self.assertEqual(verdicts, {N: (None, "merge-definition/merge-definition/merge-definition")})
        self.assertEqual(rows, [("src/u.cpp", CALLER, D, N)])
        (verdicts, rows), _ = self.prove()
        self.assertEqual(verdicts, {N: (None, "strict/strict/strict")})

    def test_prove_unit_drops(self):
        differs = json.dumps(report("differs", "differs: 1 difference(s)", code=1, lines=["SECTION-DIFFERS\tx"]))
        bytes_equal = json.dumps(report("identical", "identical: the bytes are equal with the timestamp masked"))
        for extra, label in ((b"// report od " + differs.encode(), "bind differs[od]"),
                             (b"// report flags " + differs.encode(), "bind differs[flags]"),
                             (b"// report * " + bytes_equal.encode(), "bind differs[flags,ob0,od]"),
                             (b"// moves-differ", "moves differs[flags,ob0,od]")):
            (verdicts, rows), _ = self.prove(extra + b"\n")
            self.assertTrue(verdicts[N][0].startswith(label), (label, verdicts))
            self.assertEqual(rows, [])
        (verdicts, _), _ = self.prove(b"// report flags " + differs.encode() + b"\n", defined_here=True)
        self.assertTrue(verdicts[N][0].startswith("bind inlinable-at-unit-flags[flags]"), verdicts)
        no_row = json.dumps(dict(report("identical", RENAMED), retargets=[]))
        (verdicts, _), _ = self.prove(b"// report * " + no_row.encode() + b"\n")
        self.assertTrue(verdicts[N][0].startswith("row: no COMDAT function"), verdicts)

    def test_layouts(self):
        # The removed empty stand-in S may be only in the base; any other layout difference, or a
        # failed dump on either target, drops the name.
        (verdicts, rows), work = self.prove(b"// layout s 1\n// layout r 4\n// layout-unnamed\n")
        self.assertEqual(verdicts[N][0], None)
        bound = os.path.join(work, "all.bind.cpp")
        base = os.path.join(work, "base.cpp")
        self.write("other.cpp", TEXT + b"// layout r 8\n")
        build = os.path.join(self.dir, "build")
        self.assertEqual(bb.layout_check(build, "src/u.cpp", base, bound, os.path.join(work, "l"), {"S"}), None)
        self.assertTrue(bb.layout_check(build, "src/u.cpp", base, bound, os.path.join(work, "l"), set()))
        self.assertTrue(bb.layout_check(build, "src/u.cpp", base, os.path.join(self.dir, "other.cpp"),
                                        os.path.join(work, "l"), {"S"}).startswith("layout: x86_64"))
        for target in ("x86_64-pc-windows-msvc", "i686-pc-windows-msvc"):
            (verdicts, rows), _ = self.prove(("// layout-fail %s\n" % target).encode())
            self.assertEqual(verdicts[N][0], "layout: the %s record-layout dump failed" % target)
            self.assertEqual(rows, [])


class ApplyTest(Folder):
    def setUp(self):
        super().setUp()
        build, self.source, _ = self.build(TEXT)
        self.out = os.path.join(self.dir, "out")
        os.mkdir(self.out)
        self.repo = os.path.join(self.dir, "repo")
        shutil.copytree(os.path.dirname(self.source), os.path.join(self.repo, "src"))
        os.makedirs(os.path.join(self.repo, "build"))
        self.recipe = os.path.join(self.repo, "build", "units.json")
        with open(self.recipe, "w") as f:
            json.dump({"units": [{"source": "src/u.cpp", "functions": [], "symbols": {N32: "0x00401000"}},
                                 {"source": "src/o.cpp", "functions": [{"address": "0x00401000",
                                                                        "symbol": "?g@R@@QAEHH@Z"}],
                                  "symbols": {}}]}, f, indent=1)
        plan = RewriteTest.plan(self)
        plan["names"][N].update(address="0x00401000", key=N32, row="?g@R@@QAEHH@Z", defined_here=False)
        with open(os.path.join(self.out, "gate.json"), "w") as f:
            json.dump(dict(build=build, units=[dict(plan, unit="src/u.cpp", file=self.source, refused=[],
                                                    sha256=hashlib.sha256(TEXT).hexdigest())]), f)
        self.table = os.path.join(self.repo, "batch.tsv")
        self.build_dir = build

    def proved(self, names=(N,), rows=((CALLER, N),)):
        self.write("out/proof.tsv", "unit\tname\towner\tverdict\tmode\treason\n")
        self.write("out/proved.txt", "".join(n + "\n" for n in names))
        self.write("out/rows.tsv", "unit\tfunction\towner\tname\n" + "".join(
            "src/u.cpp\t%s\t%s\t%s\n" % (fn, D, n) for fn, n in rows))

    def apply(self, *extra):
        return bb.main(["apply", self.out, self.repo, "--stage", "bind", "--table", self.table, "--batch", "b1"]
                       + list(extra))

    def state(self):
        out = []
        for path in (os.path.join(self.repo, "src", "u.cpp"), self.recipe, self.table):
            out.append(open(path, "rb").read() if os.path.exists(path) else None)
        return out

    def test_needs_the_proof(self):
        before = self.state()
        for missing in ("proof.tsv", "proved.txt", "rows.tsv"):
            self.proved()
            os.remove(os.path.join(self.out, missing))
            self.assertEqual(self.apply(), 1, missing)
            self.assertEqual(bb.main(["apply", self.out, self.repo, "--stage", "moves"]), 1, missing)
            self.assertEqual(self.state(), before, missing)
        self.assertEqual(bb.main(["apply", self.out, self.repo, "--stage", "bind"]), 2)

    def test_binds_the_proved_names(self):
        self.proved()
        self.assertEqual(self.apply(), 0)
        text, recipe, table = self.state()
        self.assertIn(b"((::R*)p)->g(1);", text)
        self.assertEqual(json.loads(recipe)["units"][0]["symbols"], {"?g@R@@QAEHH@Z": "0x00401000"})
        self.assertEqual([l for l in table.decode().splitlines() if not l.startswith("#")],
                         ["forbid\t" + N, "function\tb1\tsrc/u.cpp\t%s\t%s" % (CALLER, D)])

    def test_unproved_names_stay(self):
        before = self.state()
        self.proved(names=())
        self.assertEqual(self.apply(), 0)
        self.assertEqual(self.state()[:2], before[:2])
        self.proved()
        only = self.write("only.txt", "?other@@YAXXZ\n")
        self.assertEqual(self.apply("--only", only), 0)
        self.assertEqual(self.state()[:2], before[:2])

    def test_nothing_written_unless_everything_is_ready(self):
        before = self.state()
        self.proved(rows=())  # no check row
        self.assertEqual(self.apply(), 1)
        self.assertEqual(self.state(), before)
        self.proved()
        with open(self.recipe) as f:
            recipe = json.load(f)
        recipe["units"][0]["symbols"]["?g@R@@QAEHH@Z"] = "0x00409999"  # the row's key bound elsewhere
        with open(self.recipe, "w") as f:
            json.dump(recipe, f)
        before = self.state()
        self.assertEqual(self.apply(), 1)
        self.assertEqual(self.state(), before)
        with open(os.path.join(self.repo, "src", "u.cpp"), "ab") as f:
            f.write(b"// edited\n")
        before = self.state()
        self.assertEqual(self.apply(), 1)
        self.assertEqual(self.state(), before)


    def test_a_changed_export_refuses_prove_and_apply(self):
        # The gate recorded the export's text; once it changes, prove and apply write nothing.
        with open(self.source, "ab") as f:
            f.write(b"// changed after the gate\n")
        self.assertEqual(bb.main(["prove", self.out, self.build_dir]), 1)
        self.assertEqual(sorted(os.listdir(self.out)), ["gate.json"])
        self.proved()
        before = self.state()
        self.assertEqual(self.apply(), 1)
        self.assertEqual(bb.main(["apply", self.out, self.repo, "--stage", "moves"]), 1)
        self.assertEqual(self.state(), before)
        # A plan without the hash, from a gate before it, is refused too.
        with open(self.source, "wb") as f:
            f.write(TEXT)
        with open(os.path.join(self.out, "gate.json")) as f:
            plans = json.load(f)
        del plans["units"][0]["sha256"]
        with open(os.path.join(self.out, "gate.json"), "w") as f:
            json.dump(plans, f)
        self.assertEqual(self.apply(), 1)
        self.assertEqual(self.state(), before)


class GateRunTest(Folder):
    """bind_batch.py gate end to end, with the fake compiler's AST dump and the names demangled
    from a table."""

    DEMANGLED = {N: NDEM, D: DDEM, N32: "public: int __thiscall S::FUN_00401000(int)",
                 "?g@R@@QAEHH@Z": "public: int __thiscall R::g(int)"}

    def setUp(self):
        super().setUp()
        self.saved = bb.demangle
        bb.demangle = lambda names, undname: {n: self.DEMANGLED.get(n) for n in names}

    def tearDown(self):
        bb.demangle = self.saved
        super().tearDown()

    def gate(self, undefined=NDEM, text=TEXT):
        build, self.source, entry = self.build(text)
        entry["arguments"].insert(1, self.write("u.ast", "{\n" + "".join(dump_lines(items())) + "}\n"))
        with open(os.path.join(build, "compile_commands.json"), "w") as f:
            json.dump([entry], f)
        recipe = self.write("units.json", json.dumps({"units": [
            {"source": "src/u.cpp", "functions": [], "symbols": {N32: "0x00401000"}},
            {"source": "src/o.cpp", "functions": [{"address": "0x00401000", "symbol": "?g@R@@QAEHH@Z"}],
             "symbols": {}}]}))
        candidates = self.write("c.tsv", "unit\tsite\tname\towner\taddress\nsrc/u.cpp\t*\t%s\t%s\t0x00401000\n"
                                % (N, D))
        self.out = os.path.join(self.dir, "out")
        return bb.main(["gate", candidates, build, self.out, "--recipe", recipe, "--differing",
                        self.write("d.txt", ""), "--undefined", self.write("u.txt", undefined + "\n")])

    def test_gate_drops_an_earlier_proof_and_hashes_the_unit(self):
        os.makedirs(os.path.join(self.dir, "out"))
        for stale in ("proof.tsv", "proved.txt", "rows.tsv"):
            self.write(os.path.join("out", stale), "stale\n")
        self.assertEqual(self.gate(), 0)
        self.assertEqual(sorted(os.listdir(self.out)), ["gate.json", "gate.tsv"])
        with open(os.path.join(self.out, "gate.json")) as f:
            plan = json.load(f)["units"][0]
        self.assertEqual(plan["sha256"], hashlib.sha256(TEXT).hexdigest())
        self.assertEqual(sorted(plan["names"]), [N])


class TableTest(unittest.TestCase):
    def test_rows_from_proof_and_forbid_once(self):
        with tempfile.TemporaryDirectory() as d:
            table = os.path.join(d, "t.tsv")
            plan = dict(unit="u.cpp", names={N: dict(owner=D, sites=[dict(function="?ast@@YAXXZ")])})
            rows = [dict(unit="u.cpp", function="?caller@@YAXXZ", owner=D, name=N)]
            for batch in ("b1", "b2"):
                text = bb.table_text(table, batch, [(plan, [N])], rows)
                with open(table, "w", encoding="utf-8") as f:
                    f.write(text)
            lines = [l for l in text.splitlines() if not l.startswith("#")]
            self.assertEqual(lines, ["forbid\t" + N, "function\tb1\tu.cpp\t?caller@@YAXXZ\t" + D,
                                     "function\tb2\tu.cpp\t?caller@@YAXXZ\t" + D])
            with self.assertRaises(ValueError):  # no row from the proof: no fallback to the AST's sites
                bb.table_text(table, "b3", [(plan, [N])], [])

    def test_usage(self):
        self.assertEqual(bb.main([]), 2)
        self.assertEqual(bb.main(["gate", "--bogus", "x"]), 2)
        with tempfile.TemporaryDirectory() as d:
            def path(name, text):
                with open(os.path.join(d, name), "w", encoding="utf-8") as f:
                    f.write(text)
                return os.path.join(d, name)
            c, r = path("c.tsv", "unit\tsite\tname\towner\taddress\n"), path("r.json", '{"units": []}')
            names = path("n.txt", "")
            for option in ("--differing", "--undefined"):
                self.assertEqual(bb.main(["gate", c, d, os.path.join(d, "out"), "--recipe", r, option, names]), 2)
            self.assertFalse(os.path.exists(os.path.join(d, "out")))


if __name__ == "__main__":
    unittest.main()
