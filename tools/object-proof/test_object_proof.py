#!/usr/bin/env python3
"""Tests of objcmp.py and proof.py, on small COFF objects, compiler logs and
a fake compiler that the tests write into a temporary folder whose name
holds a space."""
import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
OBJCMP = os.path.join(HERE, "objcmp.py")
PROOF = os.path.join(HERE, "proof.py")
BIGOBJ_CLASSID = bytes.fromhex("c7a1bad1eebaa94baf20faf66aa4dcb8")
CODE = 0x60500020
RDATA = 0x40300040
COMDAT = 0x1000


def obj(sections, symbols, bigobj=False, timestamp=0, machine=0x8664):
    """A COFF object. sections: (name, data, characteristics, relocations),
    each relocation (offset, symbol, type) with the symbol's position in
    symbols. symbols: (name, value, section, type, storage, selection); a
    selection other than None gives the symbol the aux record of its section
    with that COMDAT selection."""
    symsize = 20 if bigobj else 18
    strings = bytearray(b"\0\0\0\0")

    def name(text):
        raw = text.encode("latin1")
        if len(raw) <= 8:
            return raw.ljust(8, b"\0")
        offset = len(strings)
        strings.extend(raw + b"\0")
        return b"\0\0\0\0" + struct.pack("<I", offset)

    indices, index = [], 0
    for symbol in symbols:
        indices.append(index)
        index += 1 if symbol[5] is None else 2
    header = 56 if bigobj else 20
    at = header + 40 * len(sections)
    heads, blobs = b"", b""
    for text, data, characteristics, relocations in sections:
        raw_at = at + len(blobs)
        if len(text) > 8:  # a long section name is /OFFSET into the string table
            text = "/%d" % len(strings)
            strings.extend(sections[len(heads) // 40][0].encode() + b"\0")
        heads += text.encode().ljust(8, b"\0") + struct.pack(
            "<IIIIIIHHI", 0, 0, len(data), raw_at, raw_at + len(data) if relocations else 0, 0,
            len(relocations), 0, characteristics)
        blobs += data + b"".join(struct.pack("<IIH", va, indices[s], typ) for va, s, typ in relocations)
    table = b""
    for text, value, section, typ, storage, selection in symbols:
        aux = b""
        if selection is not None:
            data, relocations = sections[section - 1][1], sections[section - 1][3]
            aux = struct.pack("<IHHIHB", len(data), len(relocations), 0, 0, 0, selection).ljust(symsize, b"\0")
        fmt = "<IiHBB" if bigobj else "<IhHBB"
        table += name(text) + struct.pack(fmt, value, section, typ, storage, 1 if aux else 0) + aux
    symbols_at = at + len(blobs)
    if bigobj:
        head = struct.pack("<HHHHI", 0, 0xFFFF, 2, machine, timestamp) + BIGOBJ_CLASSID
        head += struct.pack("<IIIIIII", 0, 0, 0, 0, len(sections), symbols_at, index)
    else:
        head = struct.pack("<HHIIIHH", machine, len(sections), timestamp, symbols_at, index, 0, 0)
    strings[0:4] = struct.pack("<I", len(strings))
    return head + heads + blobs + table + bytes(strings)


def coff(caller="?caller@@YAXXZ", callee="?callee@@YAXXZ", code=b"\xe8\x00\x00\x00\x00\xc3", timestamp=0, bigobj=False):
    """One .text$mn section, defining the caller, whose call is relocated to
    the undefined callee."""
    return obj([(".text$mn", code, CODE, [(1, 2, 4)])],
               [(".text$mn", 0, 1, 0, 3, 0), (caller, 0, 1, 0x20, 2, None), (callee, 0, 0, 0x20, 2, None)],
               bigobj, timestamp)


def calls():
    """A COMDAT .text$mn whose caller calls ?x then ?y, and an .rdata
    section with a static symbol, as lists to change before obj()."""
    sections = [[".text$mn", b"\xe8\0\0\0\0\xe8\0\0\0\0\xc3", CODE | COMDAT, [(1, 3, 4), (6, 4, 4)]],
                [".rdata", b"\1\2\3\4\5\6\7\x08", RDATA, []]]
    symbols = [[".text$mn", 0, 1, 0, 3, 2], [".rdata", 0, 2, 0, 3, 0], ["?caller@@YAXXZ", 0, 1, 0x20, 2, None],
               ["?x@@YAXXZ", 0, 0, 0x20, 2, None], ["?y@@YAXXZ", 0, 0, 0x20, 2, None], ["local", 4, 2, 0, 3, None]]
    return sections, symbols


ADDRSIG = 0x00100800


def with_addrsig(sections, symbols, *names):
    """Appends an .llvm_addrsig section that indexes the named symbols of
    calls()'s lists (each index one byte, so below 128)."""
    index, at = 0, {}
    for symbol in symbols:
        at.setdefault(symbol[0], index)
        index += 1 if symbol[5] is None else 2
    sections.append([".llvm_addrsig", bytes(at[name] for name in names), ADDRSIG, []])


def three_calls(names, targets, addrsig=(), code=b"\xe8\0\0\0\0" * 3 + b"\xc3"):
    """A COMDAT ?caller@@YAXXZ whose three calls, at 0x1, 0x6 and 0xb, go to
    the named targets; names lists the undefined symbols in table order."""
    sections = [[".text$mn", code, CODE | COMDAT,
                 [(1 + 5 * i, 2 + names.index(name), 4) for i, name in enumerate(targets)]]]
    symbols = [[".text$mn", 0, 1, 0, 3, 2], ["?caller@@YAXXZ", 0, 1, 0x20, 2, None]]
    symbols += [[name, 0, 0, 0x20, 2, None] for name in names]
    if addrsig:
        with_addrsig(sections, symbols, *addrsig)
    return obj(sections, symbols)


def calls_to(names, targets, addrsig=None, types=None):
    """Like three_calls(), one call per target at 0x1, 0x6, 0xb and on. A
    name may be a whole symbol (name, value, section, type, storage); types
    gives each call's relocation type; addrsig, when not None, adds the
    address-significance table even when it is empty."""
    names = [[name, 0, 0, 0x20, 2] if isinstance(name, str) else list(name) for name in names]
    positions = [name[0] for name in names]
    code = b"\xe8\0\0\0\0" * max(len(targets), 3) + b"\xc3"
    sections = [[".text$mn", code, CODE | COMDAT,
                 [(1 + 5 * i, 2 + positions.index(name), (types or [4] * len(targets))[i])
                  for i, name in enumerate(targets)]]]
    symbols = [[".text$mn", 0, 1, 0, 3, 2], ["?caller@@YAXXZ", 0, 1, 0x20, 2, None]]
    symbols += [name + [None] for name in names]
    if addrsig is not None:
        with_addrsig(sections, symbols, *addrsig)
    return obj(sections, symbols)


OLD, NEW = "?old@@YAXXZ", "?new@@YAXXZ"


def merge_unit(targets, undefined, new_defined=True, addrsig=None, types=None, code=None, extra=(), new_body=b"\xc3",
               order=None):
    """A COMDAT ?caller@@YAXXZ whose calls, at 0x1, 0x6 and on, go to the named
    targets; with new_defined, NEW's body in a COMDAT section of its own;
    undefined lists the undefined symbols in table order; extra adds symbols
    (name, value, section, type, storage) after them; order permutes the
    caller's relocation records."""
    sections = [[".text$mn", code or b"\xe8\0\0\0\0" * max(len(targets), 2) + b"\xc3", CODE | COMDAT, []]]
    symbols = [[".text$mn", 0, 1, 0, 3, 2], ["?caller@@YAXXZ", 0, 1, 0x20, 2, None]]
    if new_defined:
        sections.append([".text$mn", new_body, CODE | COMDAT, []])
        symbols += [[".text$mn", 0, 2, 0, 3, 2], [NEW, 0, 2, 0x20, 2, None]]
    symbols += [[name, 0, 0, 0x20, 2, None] for name in undefined]
    symbols += [list(name) + [None] for name in extra]
    positions = [symbol[0] for symbol in symbols]
    sections[0][3] = [(1 + 5 * i, positions.index(target), (types or [4] * len(targets))[i])
                      for i, target in enumerate(targets)]
    if order:
        sections[0][3] = [sections[0][3][i] for i in order]
    if addrsig is not None:
        with_addrsig(sections, symbols, *addrsig)
    return obj(sections, symbols)


def order_unit(specs, undefined=(), addrsig=None, labels=()):
    """An object of the sections in SPECS, in that order: (name, leader, data,
    comdat, targets), with leader the external symbol at its offset 0 (or
    None), comdat None, "any" or the leader of its associative parent, and
    one call per target at 0x1, 0x6 and on. undefined lists the undefined
    symbols; labels adds static symbols (name, value, leader of the section)."""
    sections, symbols, parents = [], [], []
    for number, (name, leader, data, comdat, targets) in enumerate(specs, 1):
        characteristics = (CODE if name.startswith(".text") else RDATA) | (COMDAT if comdat else 0)
        sections.append([name, data, characteristics, []])
        symbols.append([name, 0, number, 0, 3, 0 if not comdat else 2 if comdat == "any" else 5])
        if comdat not in (None, "any"):
            parents.append((len(symbols) - 1, [spec[1] for spec in specs].index(comdat) + 1))
        if leader:
            symbols.append([leader, 0, number, 0x20, 2, None])
    leaders = [spec[1] for spec in specs]
    symbols += [[name, value, leaders.index(leader) + 1, 0, 3, None] for name, value, leader in labels]
    symbols += [[name, 0, 0, 0x20, 2, None] for name in undefined]
    positions = [symbol[0] for symbol in symbols]
    for section, spec in zip(sections, specs):
        section[3] = [(1 + 5 * i, positions.index(target), 4) for i, target in enumerate(spec[4])]
    if addrsig is not None:
        with_addrsig(sections, symbols, *addrsig)
    data = bytearray(obj(sections, symbols))
    # obj() writes no associative section number: set it in each such aux record.
    table = struct.unpack_from("<I", data, 8)[0]
    for position, number in parents:
        index = sum(1 if symbol[5] is None else 2 for symbol in symbols[:position])
        struct.pack_into("<H", data, table + 18 * (index + 1) + 12, number)
    return bytes(data)


FAKE_COMPILER = """import json, shutil, sys
template, source = sys.argv[1], sys.argv[-1]
print(json.dumps(sys.argv[1:]))
with open(source) as f:
    text = f.read()
print(text)
if "fail" in text:
    sys.exit(1)
shutil.copyfile(template, [a[3:] for a in sys.argv if a.startswith("/Fo")][0])
"""


# FAKE_COMPILER that also reads its source through a -vfsoverlay file root,
# which names the source as it resolves from the working folder, and fails
# on an #error line.
FAKE_VFS_COMPILER = """import json, os, shutil, sys
template, source = sys.argv[1], sys.argv[-1]
print(json.dumps(sys.argv[1:]))
if "-vfsoverlay" in sys.argv:
    with open(sys.argv[sys.argv.index("-vfsoverlay") + 1]) as f:
        root = json.load(f)["roots"][0]
    if os.path.normcase(os.path.normpath(root["name"])) == os.path.normcase(os.path.abspath(source)):
        source = root["external-contents"]
with open(source) as f:
    text = f.read()
print(text)
if "fail" in text or text.startswith("#error"):
    sys.exit(1)
shutil.copyfile(template, [a[3:] for a in sys.argv if a.startswith("/Fo")][0])
"""


class ObjectProofTest(unittest.TestCase):
    def setUp(self):
        self.root = tempfile.mkdtemp()
        self.dir = os.path.join(self.root, "with space")
        os.mkdir(self.dir)

    def tearDown(self):
        shutil.rmtree(self.root)

    def write(self, name, data):
        path = os.path.join(self.dir, name)
        with open(path, "wb") as f:
            f.write(data)
        return path

    def clang(self, script, folder="bin"):
        """A command named clang-cl, in its own folder, that runs the Python
        script."""
        os.makedirs(os.path.join(self.dir, folder), exist_ok=True)
        if os.name == "nt":
            return self.write(os.path.join(folder, "clang-cl.cmd"),
                              ('@"%s" "%s" %%*\r\n' % (sys.executable, script)).encode())
        with open(script, "rb") as f:
            path = self.write(os.path.join(folder, "clang-cl"), ("#!%s\n" % sys.executable).encode() + f.read())
        os.chmod(path, 0o755)
        return path

    def run_tool(self, tool, *args):
        result = subprocess.run([sys.executable, "-B", tool] + list(args),
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        # A tool on Windows writes \r\n; the tests compare \n.
        return (result.returncode, result.stdout.decode("utf-8", "replace").replace("\r\n", "\n"),
                result.stderr.decode("utf-8", "replace").replace("\r\n", "\n"))

    def objcmp(self, a, b, *args):
        return self.run_tool(OBJCMP, self.write("a.obj", a), self.write("b.obj", b), *args)

    def test_identical(self):
        code, out, _ = self.objcmp(coff(), coff())
        self.assertEqual(code, 0, out)
        self.assertTrue(out.startswith("identical"), out)

    def test_timestamp(self):
        for bigobj in (False, True):
            code, out, _ = self.objcmp(coff(timestamp=1, bigobj=bigobj), coff(timestamp=0x5F5E100, bigobj=bigobj))
            self.assertEqual(code, 0, out)
            self.assertTrue(out.startswith("identical: the bytes are equal"), out)

    def test_rename(self):
        a, b = coff(), coff(callee="?other_callee@@YAXXZ")
        code, out, _ = self.objcmp(a, b)
        self.assertEqual(code, 1, out)
        self.assertIn("SYMBOL-ONLY-A\t?callee@@YAXXZ", out)
        self.assertIn("-reloc\t0x1\ttype 4\t?callee@@YAXXZ", out)
        code, out, _ = self.objcmp(a, b, "?callee@@YAXXZ=?other_callee@@YAXXZ")
        self.assertEqual(code, 0, out)
        self.assertTrue(out.startswith("identical: equal with the timestamp masked once"), out)
        renames = self.write("renames file.txt",
                             b"\xef\xbb\xbf# respelled\r\n?callee@@YAXXZ=?other_callee@@YAXXZ\r\n\r\n")
        code, out, _ = self.objcmp(a, b, "--map", renames)
        self.assertEqual(code, 0, out)
        code, out, _ = self.objcmp(coff(bigobj=True), coff(callee="?other_callee@@YAXXZ", bigobj=True),
                                   "?callee@@YAXXZ=?other_callee@@YAXXZ")
        self.assertEqual(code, 0, out)
        code, out, _ = self.objcmp(a, b, "?callee@@YAXXZ=?third@@YAXXZ")
        self.assertEqual(code, 1, out)
        # The renames respell the base only: a head that still calls the old
        # spelling differs there.
        kept = coff(caller="?new_caller@@YAXXZ")
        code, out, _ = self.objcmp(a, kept, "?caller@@YAXXZ=?new_caller@@YAXXZ", "?callee@@YAXXZ=?other_callee@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertIn("RENAME-KEPT\tB still holds ?callee@@YAXXZ", out)
        self.assertIn("+reloc\t0x1\ttype 4\t?callee@@YAXXZ", out)

    def test_refused_renames(self):
        # The call sites of ?x and ?y swap places: respelling ?x as ?y would
        # make both objects call ?y twice.
        sections, symbols = calls()
        a = obj(sections, symbols)
        sections[0][3] = [(1, 4, 4), (6, 3, 4)]
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?y@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertIn("RENAME-MERGES\tA holds both ?x@@YAXXZ and ?y@@YAXXZ", out)
        self.assertIn("RENAME-KEPT\tB still holds ?x@@YAXXZ", out)
        self.assertIn("RENAME-MERGES\tB holds both ?x@@YAXXZ and ?y@@YAXXZ", out)
        # Equal bytes stay identical whatever the map, with no RENAME- line.
        code, out, _ = self.objcmp(a, a, "?x@@YAXXZ=?y@@YAXXZ")
        self.assertEqual(code, 0, out)
        self.assertNotIn("RENAME-", out)
        # A rename that only an embedded name of A matches applies, without a NOTE.
        sections, symbols = calls()
        symbols[3][0] = "?l@?1??x@@YAXXZ@4HA"
        embedded = obj(sections, symbols)
        symbols[3][0] = "?l@?1??x2@@YAXXZ@4HA"
        code, out, _ = self.objcmp(embedded, obj(sections, symbols), "?x@@YAXXZ=?x2@@YAXXZ")
        self.assertEqual(code, 0, out)
        self.assertNotIn("NOTE", out)
        sections, symbols = calls()
        # The call of ?y moves to ?x.
        sections[0][3] = [(1, 3, 4), (6, 3, 4)]
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?y@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertIn("RENAME-MERGES\tA holds both ?x@@YAXXZ and ?y@@YAXXZ", out)
        # A already holds ?y: respelled, its two callees become one.
        sections, symbols = calls()
        a = obj(sections, symbols)
        symbols[3][0] = "?y@@YAXXZ"
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?y@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertEqual(out.splitlines()[1:], ["RENAME-MERGES\tA holds both ?x@@YAXXZ and ?y@@YAXXZ"], out)
        # A name that embeds ?x is respelled in A, and kept in B.
        sections, symbols = calls()
        symbols.append(["$unwind$?x@@YAXXZ", 0, 2, 0, 3, None])
        a = obj(sections, symbols)
        symbols[3][0] = "?x2@@YAXXZ"
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?x2@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertIn("RENAME-KEPT\tB still holds ?x@@YAXXZ", out)
        symbols[6][0] = "$unwind$?x2@@YAXXZ"
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?x2@@YAXXZ")
        self.assertEqual(code, 0, out)
        # A relocation moves between two statics of one name.
        sections, symbols = calls()
        symbols += [["dup", 0, 2, 0, 3, None], ["dup", 4, 2, 0, 3, None]]
        sections[0][3] = [(1, 6, 4), (6, 4, 4)]
        a = obj(sections, symbols)
        sections[0][3] = [(1, 7, 4), (6, 4, 4)]
        symbols[3][0] = "?x2@@YAXXZ"
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?x2@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertIn("-reloc\t0x1\ttype 4\tdup@dup+0x0", out)
        self.assertIn("+reloc\t0x1\ttype 4\tdup@dup+0x4", out)

    def test_unmatched_rename(self):
        # A rename that does not apply to A leaves the bytes to decide.
        for args in ((), ("?nothere@@YAXXZ=?callee@@YAXXZ",)):
            code, out, _ = self.objcmp(coff(), coff() + b"\0", *args)
            self.assertEqual(code, 1, (args, out))
            self.assertTrue(out.startswith("differs: the bytes differ, but no section"), out)
        code, out, _ = self.objcmp(coff(), coff(callee="?other_callee@@YAXXZ"), "?other_callee@@YAXXZ=?callee@@YAXXZ")
        self.assertEqual(code, 1, out)

    def test_structural_differences(self):
        def selection(sections, symbols):
            symbols[0][5] = 4

        def characteristics(sections, symbols):
            sections[1][2] |= 0x80000000

        def order(sections, symbols):
            sections.reverse()
            for symbol in symbols:
                symbol[2] = {1: 2, 2: 1}.get(symbol[2], symbol[2])

        def storage(sections, symbols):
            symbols[5][4] = 2

        cases = (
            (selection, {}, {}, "SECTION-DIFFERS\t?caller@@YAXXZ\t.text$mn\tselection 2 -> 4", 2),
            (characteristics, {}, {}, "SECTION-DIFFERS\t#.rdata/1\t.rdata\tcharacteristics 1076887616 -> 3224371264", 1),
            (order, {}, {}, "SECTION-ORDER", 1),
            (storage, {}, {}, "SYMBOL-ONLY-A\tlocal\t4\t#.rdata/1\t0\t3", 1),
            (None, {}, dict(machine=0x14C), "HEADER\tmachine\t34404 -> 332", 1),
            (None, {}, dict(bigobj=True), "HEADER\tbigobj\tFalse -> True", 1),
            (selection, dict(bigobj=True), dict(bigobj=True), "SECTION-DIFFERS\t?caller@@YAXXZ\t.text$mn\tselection 2 -> 4", 2),
        )
        for change, options_a, options_b, line, count in cases:
            sections, symbols = calls()
            a = obj(sections, symbols, **options_a)
            if change:
                change(sections, symbols)
            b = obj(sections, symbols, **options_b)
            symbols[4][0] = "?y2@@YAXXZ"
            renamed = obj(sections, symbols, **options_b)
            for head, args in ((b, ()), (renamed, ("?y@@YAXXZ=?y2@@YAXXZ",))):
                code, out, _ = self.objcmp(a, head, *args)
                self.assertEqual(code, 1, (line, args, out))
                self.assertTrue(out.startswith("differs: %d difference(s)" % count), (line, args, out))
                self.assertIn(line, out, args)

    def test_difference(self):
        code, out, _ = self.objcmp(coff(), coff(code=b"\xe8\x00\x00\x00\x00\xcc"))
        self.assertEqual(code, 1, out)
        self.assertTrue(out.startswith("differs: 1 difference(s)"), out)
        self.assertIn("SECTION-DIFFERS\t?caller@@YAXXZ\t.text$mn\tsize 6 -> 6, 1 bytes differ, first at 0x5", out)

    def test_compile_source(self):
        compiler, template = self.write("compiler.py", FAKE_VFS_COMPILER.encode()), self.write("template.obj", coff())
        source = self.write("unit.cpp", b"unit.cpp(1,1): warning: one [-Wone]\n")
        build = os.path.join(self.dir, "build")
        os.mkdir(build)
        clang = self.clang(compiler)
        entry = dict(directory=build, file=source, output="CMakeFiles/game.dir/unit.cpp.obj",
                     arguments=[clang, template, "/c", "--", source])
        with open(os.path.join(build, "compile_commands.json"), "w") as f:
            json.dump([entry], f)

        def prefix(name):
            return os.path.join(self.dir, name)

        def log(name, variant):
            with open(prefix("%s.%s.log" % (name, variant))) as f:
                return f.readline(), f.read()

        # Without --source the log names the entry and each command it ran.
        code, out, err = self.run_tool(PROOF, "compile", build, "unit.cpp", prefix("plain"))
        self.assertEqual(code, 0, out + err)
        with open(prefix("plain.commands.json")) as f:
            commands = json.load(f)
        self.assertEqual((commands["entry"], commands["source"], commands["overlay"]), (entry, None, None))
        for variant in ("flags", "ob0", "od"):
            words = json.loads(log("plain", variant)[0])
            self.assertEqual(commands["commands"][variant], [clang] + words)
        # --source compiles another file's content at the unit's path, and
        # leaves the unit's file as it was, also when the compile fails.
        other = self.write("other.cpp", b"unit.cpp(1,1): warning: two [-Wtwo]\n")
        code, out, err = self.run_tool(PROOF, "compile", "--source", other, "--target", "game", build, "unit.cpp",
                                       prefix("over"))
        self.assertEqual(code, 0, out + err)
        with open(prefix("over.commands.json")) as f:
            commands = json.load(f)
        self.assertEqual((commands["source"], commands["overlay"]), (other, prefix("over.vfs.json")))
        with open(prefix("over.vfs.json")) as f:
            overlay = json.load(f)
        # The compiler must see the unit's own path, not the override's.
        self.assertIs(overlay["use-external-names"], False)
        root = overlay["roots"][0]
        self.assertEqual((root["name"], root["external-contents"]), (source, other))
        for variant in ("flags", "ob0", "od"):
            words, text = log("over", variant)
            self.assertEqual(commands["commands"][variant], [clang] + json.loads(words))
            self.assertIn("warning: two", text)
            self.assertIn("-vfsoverlay", commands["commands"][variant])
            self.assertTrue(os.path.exists(prefix("over.%s.obj" % variant)))
        code, out, _ = self.run_tool(PROOF, "compare", prefix("plain"), prefix("over"))
        self.assertEqual(code, 1, out)
        self.assertIn("class\t-Wtwo\t0 -> 1", out)
        self.write("failing.cpp", b"fail\n")
        code, out, err = self.run_tool(PROOF, "compile", "--source", prefix("failing.cpp"), build, "unit.cpp",
                                       prefix("bad"))
        self.assertEqual(code, 1, out + err)
        with open(source, "rb") as f:
            self.assertEqual(f.read(), b"unit.cpp(1,1): warning: one [-Wone]\n")
        code, out, err = self.run_tool(PROOF, "compile", "--source", prefix("missing.cpp"), build, "unit.cpp",
                                       prefix("none"))
        self.assertEqual(code, 2, out + err)
        self.assertEqual(len(err.strip().splitlines()), 1, err)

    def test_source_fails_closed(self):
        # --source compiles nothing and exits 2 with one line unless the
        # compiler is clang, the command names the unit as the entry's file
        # spells it, the override is a file and the canary (the unit read as
        # one #error line) fails with that error.
        template, source = self.write("template.obj", coff()), self.write("unit.cpp", b"int unit;\n")
        other = self.write("other.cpp", b"int other;\n")
        build = os.path.join(self.dir, "build")
        os.mkdir(build)
        # A relative path resolves from the folder as the system names it.
        build = os.path.realpath(build)
        vfs = self.clang(self.write("vfs.py", FAKE_VFS_COMPILER.encode()), "vfs")
        relative = os.path.relpath(os.path.realpath(source), build)
        warns = self.clang(self.write("warns.py", FAKE_VFS_COMPILER.replace(' or text.startswith("#error")', "")
                                      .encode()), "warns")
        cases = [
            ("compiled", source, [vfs, template, "/c", "--", source], other),
            ("compiled", relative, [vfs, template, "/c", "--", relative], other),
            ("needs clang", source, [sys.executable, self.write("vfs2.py", FAKE_VFS_COMPILER.encode()), template,
                                     "/c", "--", source], other),
            ("does not name", source, [vfs, template, "/c", "--", relative], other),
            ("does not name", relative, [vfs, template, "/c", "--", source], other),
            ("did not replace", source, [self.clang(self.write("plain.py", FAKE_COMPILER.encode()), "plain"),
                                         template, "/c", "--", source], other),
            ("did not replace", source, [self.clang(self.write("broken.py", b"import sys\nsys.exit(1)\n"), "broken"),
                                         template, "/c", "--", source], other),
            ("did not replace", source, [warns, template, "/c", "--", source], other),
            ("is not a file", source, [vfs, template, "/c", "--", source], self.dir)]
        if os.name != "nt":
            os.symlink(source, os.path.join(self.dir, "link.cpp"))
            cases.append(("does not name", os.path.join(self.dir, "link.cpp"), [vfs, template, "/c", "--", source],
                          other))
        for name, file, arguments, override in cases:
            with open(os.path.join(build, "compile_commands.json"), "w") as f:
                json.dump([dict(directory=build, file=file, output="CMakeFiles/game.dir/unit.cpp.obj",
                                arguments=arguments)], f)
            out_prefix = os.path.join(self.dir, "out")
            for variant in ("flags", "ob0", "od"):
                self.write("out.%s.obj" % variant, b"stale")
            code, out, err = self.run_tool(PROOF, "compile", "--source", override, build, os.path.basename(file),
                                           out_prefix)
            objects = [os.path.exists("%s.%s.obj" % (out_prefix, variant)) for variant in ("flags", "ob0", "od")]
            if name == "compiled":
                self.assertEqual((code, objects), (0, [True] * 3), (name, out, err))
            else:
                self.assertEqual((code, out, objects), (2, "", [False] * 3), (name, err))
                self.assertEqual(len(err.splitlines()), 1, (name, err))
                self.assertIn(name, err)

    def test_kept_symbol(self):
        # --expect-kept undoes only an undefined OLD symbol and refuses a head
        # that still holds OLD in a name the renames do not respell.
        x, x2, y, y2 = "?x@@YAXXZ", "?x2@@YAXXZ", "?y@@YAXXZ", "?y2@@YAXXZ"
        code = b"\xe8\0\0\0\0" * 3 + b"\xc3"

        def unit(names, targets, extra=()):
            symbols = [[".text$mn", 0, 1, 0, 3, 2], ["?caller@@YAXXZ", 0, 1, 0x20, 2, None]]
            symbols += [list(symbol) for symbol in names] + [list(symbol) for symbol in extra]
            positions = [symbol[0] for symbol in symbols]
            relocations = [(1 + 5 * i, positions.index(name), 4) for i, name in enumerate(targets)]
            return obj([[".text$mn", code, CODE | COMDAT, relocations]], symbols)

        def undefined(name):
            return (name, 0, 0, 0x20, 2, None)

        label = ("lbl" + x, 15, 1, 0, 6, None)  # a label, which no rename respells
        expected = self.write("one.txt", ("?caller@@YAXXZ %s\n" % x).encode())
        base = unit([undefined(x)], [x, x, x], [label])
        for extra, status in (((), 0), ((label,), 1)):
            head = unit([undefined(x), undefined(x2)], [x, x2, x2], extra)
            got, out, _ = self.objcmp(base if extra else unit([undefined(x)], [x, x, x]), head,
                                      "%s=%s" % (x, x2), "--expect-kept", expected)
            self.assertEqual(got, status, out)
        # The head keeps the definition of OLD (at 0xf, so it leads no
        # section) as well as two calls of it: that is no kept call site.
        defined = (x, 15, 1, 0x20, 2, None)
        base = unit([defined, undefined(y)], [x, x, y])
        head = unit([defined, undefined(y2)], [x, x, y2])
        two = self.write("two.txt", ("?caller@@YAXXZ %s\n" % x * 2).encode())
        got, out, _ = self.objcmp(base, head, "%s=%s" % (x, x2), "%s=%s" % (y, y2), "--expect-kept", two)
        self.assertEqual(got, 1, out)
        self.assertEqual(out.count("KEPT-SITE"), 2, out)

    def test_refusal_alone(self):
        # B still holds OLD in a label, which no rename respells: with no
        # other difference, the RENAME- lines alone still make it differ.
        def unit(callee):
            return obj([(".text$mn", b"\xe8\0\0\0\0\xc3", CODE, [(1, 2, 4)])],
                       [(".text$mn", 0, 1, 0, 3, 0), ("?caller@@YAXXZ", 0, 1, 0x20, 2, None),
                        (callee, 0, 0, 0x20, 2, None), ("lbl?callee@@YAXXZ", 5, 1, 0, 6, None)])

        code, out, _ = self.objcmp(unit("?callee@@YAXXZ"), unit("?other_callee@@YAXXZ"),
                                   "?callee@@YAXXZ=?other_callee@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertEqual(out.splitlines()[:3], ["differs: 0 difference(s), 2 RENAME- line(s)",
                                                "RENAME-MERGES\tB holds both ?callee@@YAXXZ and ?other_callee@@YAXXZ",
                                                "RENAME-KEPT\tB still holds ?callee@@YAXXZ"], out)

    def test_counts(self):
        # RENAME- lines are counted apart from the differences.
        code, out, _ = self.objcmp(coff(), coff(caller="?new_caller@@YAXXZ"),
                                   "?caller@@YAXXZ=?new_caller@@YAXXZ", "?callee@@YAXXZ=?other_callee@@YAXXZ")
        self.assertEqual(code, 1, out)
        self.assertEqual(out.splitlines()[0], "differs: 2 difference(s), 1 RENAME- line(s)", out)
        self.assertEqual(sum(line.startswith("RENAME-") for line in out.splitlines()), 1, out)
        code, out, _ = self.objcmp(coff(), coff(callee="?other_callee@@YAXXZ"))
        self.assertEqual(out.splitlines()[0], "differs: 2 difference(s)", out)

    def test_section_equal(self):
        # A changed section says what is equal as well as what differs.
        sections, symbols = calls()
        a = obj(sections, symbols)
        sections[0][3] = [(1, 3, 4), (6, 3, 4)]
        code, out, _ = self.objcmp(a, obj(sections, symbols))
        self.assertEqual(code, 1, out)
        self.assertIn("SECTION-DIFFERS\t?caller@@YAXXZ\t.text$mn\trelocations 2 -> 2\t"
                      "equal: characteristics 1615859744, selection 2, bytes, size 11\n", out)
        code, out, _ = self.objcmp(coff(), coff(code=b"\xe8\x00\x00\x00\x00\xcc"))
        self.assertIn("\tsize 6 -> 6, 1 bytes differ, first at 0x5\t"
                      "equal: characteristics 1615855648, selection None, size 6, relocations 1\n", out)
        # An address-significance difference names every added, removed or
        # moved entry, also when only the order or a count changes.
        for names_a, names_b, lines in (
                (("?x@@YAXXZ", "?y@@YAXXZ"), ("?y@@YAXXZ", "?x@@YAXXZ"),
                 ["\t+addrsig\t0\t?y@@YAXXZ", "\t-addrsig\t1\t?y@@YAXXZ"]),
                (("?x@@YAXXZ",), ("?x@@YAXXZ", "?x@@YAXXZ"), ["\t+addrsig\t1\t?x@@YAXXZ"]),
                (("?x@@YAXXZ",), ("?y@@YAXXZ",), ["\t-addrsig\t0\t?x@@YAXXZ", "\t+addrsig\t0\t?y@@YAXXZ"])):
            sections, symbols = calls()
            with_addrsig(sections, symbols, *names_a)
            a = obj(sections, symbols)
            sections, symbols = calls()
            with_addrsig(sections, symbols, *names_b)
            code, out, _ = self.objcmp(a, obj(sections, symbols))
            self.assertEqual(code, 1, out)
            self.assertIn("SECTION-DIFFERS\t#.llvm_addrsig/1\t.llvm_addrsig\t"
                          "address-significance names differ, %d -> %d" % (len(names_a), len(names_b)), out)
            self.assertEqual([line for line in out.splitlines() if line.startswith(("\t-addrsig", "\t+addrsig"))],
                             lines, out)

    def test_alignment(self):
        # Changed characteristics print in hexadecimal too, and a changed
        # alignment says so in bytes.
        for characteristics, text in (
                (0x40400040, "characteristics 1076887616 -> 1077936192 (0x40300040 -> 0x40400040); alignment 4 -> 8\t"),
                (0x40000040, "characteristics 1076887616 -> 1073741888 (0x40300040 -> 0x40000040); alignment 4 -> "
                             "default\t"),
                (0xC0300040, "characteristics 1076887616 -> 3224371264 (0x40300040 -> 0xc0300040)\t")):
            sections, symbols = calls()
            a = obj(sections, symbols)
            sections[1][2] = characteristics
            code, out, _ = self.objcmp(a, obj(sections, symbols))
            self.assertEqual(code, 1, out)
            self.assertIn("SECTION-DIFFERS\t#.rdata/1\t.rdata\t" + text + "equal: selection None, bytes, size 8, "
                          "relocations 0\n", out)

    def test_addrsig_encoding(self):
        # An address-significance index is a ULEB128 number with no padding
        # byte and none cut short; otherwise the object is unreadable.
        def unit(raw):
            sections, symbols = calls()
            sections.append([".llvm_addrsig", raw, ADDRSIG, []])
            return obj(sections, symbols)

        code, out, err = self.objcmp(unit(b"\x80\x01\x03"), unit(b"\x80\x01\x03"))
        self.assertEqual(code, 0, out + err)
        for raw in (b"\x83\x00", b"\x83\x80\x00", b"\x03\x83", b"\x80"):
            for a, b in ((unit(raw), unit(b"\x03")), (unit(b"\x03"), unit(raw)), (unit(raw), unit(raw))):
                code, out, err = self.objcmp(a, b)
                self.assertEqual((code, out), (2, ""), (raw, out, err))
                self.assertEqual(len(err.splitlines()), 1, err)

    def test_base_holds_both(self):
        # A second commit compared to a first: A calls ?x and ?x2, B only ?x2.
        # Respelling A would merge its two names, so the comparison is refused
        # with one line that names the rename, and no artefact line.
        def pair(code=b"\xe8\0\0\0\0\xe8\0\0\0\0\xc3"):
            sections, symbols = calls()
            symbols.append(["?x2@@YAXXZ", 0, 0, 0x20, 2, None])
            sections[0][3] = [(1, 3, 4), (6, 6, 4)]
            with_addrsig(sections, symbols, "?x@@YAXXZ", "?x2@@YAXXZ")
            a = obj(sections, symbols)
            sections, symbols = calls()
            symbols[3][0] = "?x2@@YAXXZ"
            sections[0][1] = code
            sections[0][3] = [(1, 3, 4), (6, 3, 4)]
            with_addrsig(sections, symbols, "?x2@@YAXXZ")
            return a, obj(sections, symbols)

        refusal = ["refused: A holds both spellings of a rename; compare without that rename, or with the "
                   "commit before A as the base", "RENAME-MERGES\tA holds both ?x@@YAXXZ and ?x2@@YAXXZ"]
        for code in (b"\xe8\0\0\0\0\xe8\0\0\0\0\xc3", b"\xe8\0\0\0\0\xe8\0\0\0\0\xcc"):
            a, b = pair(code)
            code, out, _ = self.objcmp(a, b, "?x@@YAXXZ=?x2@@YAXXZ")
            self.assertEqual(code, 1, out)
            self.assertEqual(out.splitlines(), refusal, out)
        # Without the rename, the moved call is an ordinary difference.
        a, b = pair()
        code, out, _ = self.objcmp(a, b)
        self.assertEqual(code, 1, out)
        self.assertIn("\t-reloc\t0x1\ttype 4\t?x@@YAXXZ\n\t+reloc\t0x1\ttype 4\t?x2@@YAXXZ\n", out)

    def test_summary(self):
        renamed = "?callee@@YAXXZ=?other_callee@@YAXXZ"
        code, out, _ = self.objcmp(coff(), coff(callee="?other_callee@@YAXXZ"), renamed)
        self.assertEqual(code, 0, out)
        self.assertEqual(out.splitlines()[1:], ["RETARGET\t?callee@@YAXXZ -> ?other_callee@@YAXXZ\t1 site(s)\t"
                                                "by the map\t?caller@@YAXXZ"], out)
        code, out, _ = self.objcmp(coff(), coff(callee="?other_callee@@YAXXZ"))
        self.assertEqual(code, 1, out)
        self.assertIn("\nRETARGET\t?callee@@YAXXZ -> ?other_callee@@YAXXZ\t1 site(s)\tnot by the map\t"
                      "?caller@@YAXXZ\n", out)
        kept = (coff(), coff(caller="?new_caller@@YAXXZ"), "?caller@@YAXXZ=?new_caller@@YAXXZ", renamed)
        code, out, _ = self.objcmp(*kept)
        self.assertEqual(code, 1, out)
        self.assertEqual(out.splitlines()[-1], "KEPT-SITE\t?new_caller@@YAXXZ\t0x1\t?callee@@YAXXZ\t"
                                               "?other_callee@@YAXXZ", out)
        # --json gives the same facts under stable keys.
        keys = {"verdict", "result", "exit", "differences", "rename_lines", "notes", "lines", "retargets",
                "kept_sites", "kept_missing", "kept_unexpected"}
        code, out, _ = self.objcmp(*kept + ("--json",))
        self.assertEqual(code, 1, out)
        report = json.loads(out)
        self.assertEqual(set(report), keys)
        self.assertEqual((report["result"], report["exit"], report["differences"], report["rename_lines"]),
                         ("differs", 1, 2, 1), out)
        self.assertEqual(report["verdict"], "differs: 2 difference(s), 1 RENAME- line(s)")
        self.assertIn("RENAME-KEPT\tB still holds ?callee@@YAXXZ", report["lines"])
        self.assertEqual(report["kept_sites"], [dict(function="?new_caller@@YAXXZ", offset=1, old="?callee@@YAXXZ",
                                                      new="?other_callee@@YAXXZ")])
        self.assertEqual(report["retargets"], [])
        code, out, _ = self.objcmp(coff(), coff(callee="?other_callee@@YAXXZ"), "--json", renamed)
        report = json.loads(out)
        self.assertEqual((code, report["result"], report["exit"], report["differences"]), (0, "identical", 0, 0), out)
        self.assertEqual(report["retargets"], [dict(old="?callee@@YAXXZ", new="?other_callee@@YAXXZ", count=1,
                                                     by_map=True, functions=["?caller@@YAXXZ"])])
        code, out, _ = self.objcmp(coff(), coff(callee="?other_callee@@YAXXZ"), "--json", "?nothere@@YAXXZ=?x@@YAXXZ")
        report = json.loads(out)
        self.assertEqual((code, report["exit"], report["notes"]), (1, 1, ["NOTE\trename ?nothere@@YAXXZ is not a "
                                                                          "symbol of A"]), out)
        self.assertFalse(report["retargets"][0]["by_map"], out)
        # A refused comparison compares nothing: no difference count, no summary.
        sections, symbols = calls()
        a = obj(sections, symbols)
        symbols[3][0] = "?y@@YAXXZ"
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?y@@YAXXZ", "--json")
        report = json.loads(out)
        self.assertEqual((code, report["result"], report["exit"], report["differences"], report["retargets"]),
                         (1, "refused", 1, None, []), out)

    def test_symbol_shift(self):
        # A grown .bss moves the symbols after it: one SYMBOL-SHIFT line per
        # section and distance in place of their SYMBOL-ONLY lines; --json
        # keeps the per-symbol lines.
        def unit(size, values):
            sections, symbols = calls()
            sections.append([".bss", b"\0" * size, 0xC0300080, []])
            symbols += [[".bss", 0, 3, 0, 3, 0], ["?buf@@3PADA", 0, 3, 0, 2, None]]
            symbols += [[name, value, 3, 0, storage, None] for name, value, storage in values]
            return obj(sections, symbols)

        a = unit(0x40, [("?a@@3HA", 0x10, 2), ("?b@@3HA", 0x14, 2), ("s", 0x18, 3), ("?c@@3HA", 0x20, 2),
                        ("?d@@3HA", 0x24, 2)])
        b = unit(0x140, [("?a@@3HA", 0x110, 2), ("?b@@3HA", 0x114, 2), ("s", 0x118, 3), ("?c@@3HA", 0x8, 2),
                         ("?e@@3HA", 0x24, 2)])
        code, out, _ = self.objcmp(a, b)
        self.assertEqual(code, 1, out)
        self.assertEqual([line for line in out.splitlines() if line.startswith("SYMBOL-")],
                         ["SYMBOL-SHIFT\t?buf@@3PADA\t3 symbol(s)\tby +0x100\tfrom ?a@@3HA at 0x10",
                          "SYMBOL-SHIFT\t?buf@@3PADA\t1 symbol(s)\tby -0x18\tfrom ?c@@3HA at 0x20",
                          "SYMBOL-ONLY-A\t?d@@3HA\t36\t?buf@@3PADA\t0\t2",
                          "SYMBOL-ONLY-B\t?e@@3HA\t36\t?buf@@3PADA\t0\t2"], out)
        code, out, _ = self.objcmp(a, b, "--json")
        report = json.loads(out)
        self.assertEqual(code, 1, out)
        self.assertEqual([line for line in report["lines"] if line.startswith("SYMBOL-")],
                         ["SYMBOL-ONLY-A\t%s\t?buf@@3PADA\t0\t%s" % fields for fields in (
                             ("?a@@3HA\t16", "2"), ("?b@@3HA\t20", "2"), ("s\t24", "3"), ("?c@@3HA\t32", "2"),
                             ("?d@@3HA\t36", "2"))] +
                         ["SYMBOL-ONLY-B\t%s\t?buf@@3PADA\t0\t%s" % fields for fields in (
                             ("?a@@3HA\t272", "2"), ("?b@@3HA\t276", "2"), ("s\t280", "3"), ("?c@@3HA\t8", "2"),
                             ("?e@@3HA\t36", "2"))], out)
        self.assertEqual(report["differences"], 2, out)
        # A symbol that moves to another section is no shift, and two
        # sections that shift by one distance print a line each.
        def two(first, second, moved):
            sections, symbols = calls()
            sections += [[".bss", b"\0" * 0x40, 0xC0300080, []], [".data", b"\0" * 0x40, 0xC0300040, []]]
            symbols += [[".bss", 0, 3, 0, 3, 0], ["?buf@@3PADA", 0, 3, 0, 2, None], ["?a@@3HA", first, 3, 0, 2, None],
                        [".data", 0, 4, 0, 3, 0], ["?tab@@3PADA", 0, 4, 0, 2, None], ["?b@@3HA", second, 4, 0, 2, None],
                        ["?c@@3HA"] + moved + [0, 2, None], ["@feat.00", first, -1, 0, 3, None]]
            return obj(sections, symbols)

        code, out, _ = self.objcmp(two(0x10, 0x10, [0x20, 3]), two(0x18, 0x18, [0x28, 4]))
        self.assertEqual(code, 1, out)
        self.assertEqual([line for line in out.splitlines() if line.startswith("SYMBOL-")],
                         ["SYMBOL-SHIFT\t?buf@@3PADA\t1 symbol(s)\tby +0x8\tfrom ?a@@3HA at 0x10",
                          "SYMBOL-SHIFT\t?tab@@3PADA\t1 symbol(s)\tby +0x8\tfrom ?b@@3HA at 0x10",
                          "SYMBOL-ONLY-A\t?c@@3HA\t32\t?buf@@3PADA\t0\t2",
                          "SYMBOL-ONLY-A\t@feat.00\t16\t(absolute)\t0\t3",
                          "SYMBOL-ONLY-B\t?c@@3HA\t40\t?tab@@3PADA\t0\t2",
                          "SYMBOL-ONLY-B\t@feat.00\t24\t(absolute)\t0\t3"], out)

    def test_expect_kept(self):
        x, x2, y, y2 = "?x@@YAXXZ", "?x2@@YAXXZ", "?y@@YAXXZ", "?y2@@YAXXZ"
        rename = "%s=%s" % (x, x2)
        base = three_calls([x, y], [x, x, x], addrsig=(x,))
        # The head keeps the call at 0x1: B holds both spellings, and OLD is
        # address-significant there too.
        mixed = three_calls([x, x2, y], [x, x2, x2], addrsig=(x, x2))
        one = self.write("one kept.txt", ("\ufeff# kept\r\n?caller@@YAXXZ \t%s\r\n" % x).encode("utf-8"))

        def check(head, expected, code, verdict, *lines, renames=(rename,)):
            args = list(renames) + (["--expect-kept", expected] if expected else [])
            status, out, err = self.objcmp(base, head, *args)
            self.assertEqual(status, code, out + err)
            self.assertTrue(out.startswith(verdict), out)
            for line in lines:
                self.assertIn(line, out.splitlines())
            return out

        check(mixed, one, 0, "kept: equal with the timestamp masked once the renames are applied, except the 1 "
              "expected kept site(s)\n", "KEPT-SITE\t?caller@@YAXXZ\t0x1\t%s\t%s" % (x, x2))
        check(mixed, None, 1, "differs: 3 difference(s), 2 RENAME- line(s)\n")
        # An extra kept site.
        check(three_calls([x, x2, y], [x, x, x2], addrsig=(x, x2)), one, 1,
              "differs: 3 difference(s), 2 RENAME- line(s), 1 kept-site mismatch(es)\n",
              "KEPT-UNEXPECTED\t?caller@@YAXXZ\t0x6\t%s" % x)
        # A missing one: the head moved every call.
        moved = three_calls([x2, y], [x2, x2, x2], addrsig=(x2,))
        check(moved, None, 0, "identical: equal with the timestamp masked once the renames are applied\n")
        check(moved, one, 1, "differs: 0 difference(s), 1 kept-site mismatch(es)\n",
              "KEPT-MISSING\t?caller@@YAXXZ\t%s" % x)
        # The base itself keeps all three calls: the listed one is no mismatch.
        check(base, one, 1, "differs: 0 difference(s), 2 kept-site mismatch(es)\n",
              "KEPT-UNEXPECTED\t?caller@@YAXXZ\t0x6\t%s" % x, "KEPT-UNEXPECTED\t?caller@@YAXXZ\t0xb\t%s" % x)
        # A kept site in another function than the one expected.
        other = self.write("other.txt", ("?other@@YAXXZ %s\n" % x).encode())
        check(mixed, other, 1, "differs: 3 difference(s), 2 RENAME- line(s), 2 kept-site mismatch(es)\n",
              "KEPT-MISSING\t?other@@YAXXZ\t%s" % x, "KEPT-UNEXPECTED\t?caller@@YAXXZ\t0x1\t%s" % x)
        # A real change beside the kept site: a byte, a call target, an
        # address-significance entry, a symbol.
        for head in (three_calls([x, x2, y], [x, x2, x2], addrsig=(x, x2), code=b"\xe8\0\0\0\0" * 3 + b"\xcc"),
                     three_calls([x, x2, y], [x, x2, y], addrsig=(x, x2)),
                     three_calls([x, x2, y], [x, x2, x2], addrsig=(x, x2, y)),
                     three_calls([x, x2, y, y2], [x, x2, x2], addrsig=(x, x2))):
            out = check(head, one, 1, "differs: ")
            self.assertNotIn("kept-site mismatch", out)
        # The head keeps every call of OLD: B holds only OLD, which the kept
        # sites respell in place.
        both = self.write("both.txt", ("?caller@@YAXXZ %s\n" % x * 3).encode())
        check(three_calls([x, y2], [x, x, x], addrsig=(x,)), both, 0, "kept: ", renames=(rename, "%s=%s" % (y, y2)))
        check(three_calls([x, y2], [x, x, x], addrsig=(y2,)), both, 1, "differs: ", renames=(rename, "%s=%s" % (y, y2)))
        # --json carries the result and the mismatches.
        code, out, _ = self.objcmp(base, mixed, rename, "--expect-kept", other, "--json")
        report = json.loads(out)
        self.assertEqual((code, report["result"], report["exit"]), (1, "differs", 1), out)
        self.assertEqual(report["kept_missing"], [dict(function="?other@@YAXXZ", old=x)])
        self.assertEqual(report["kept_unexpected"], [dict(function="?caller@@YAXXZ", offset=1, old=x)])
        code, out, _ = self.objcmp(base, mixed, rename, "--expect-kept", one, "--json")
        self.assertEqual((code, json.loads(out)["result"]), (0, "kept"), out)
        # An expected site whose OLD is not a rename, or a malformed line, is a usage error.
        for text in ("?caller@@YAXXZ %s\n" % y, "?caller@@YAXXZ\n"):
            code, out, err = self.objcmp(base, mixed, rename, "--expect-kept", self.write("bad.txt", text.encode()))
            self.assertEqual(code, 2, out + err)

    def test_kept_holes(self):
        # Beside the kept sites, --expect-kept undoes only an undefined
        # external OLD with value 0 and NEW's symbol type, only for a rename
        # with a kept site, and only when B marks OLD address-significant as
        # often as A does.
        x, x2, y, y2 = "?x@@YAXXZ", "?x2@@YAXXZ", "?y@@YAXXZ", "?y2@@YAXXZ"
        one = self.write("one.txt", ("?caller@@YAXXZ %s\n" % x).encode())
        renames = ("%s=%s" % (x, x2), "%s=%s" % (y, y2))
        base = calls_to([x, y], [x, x, y], addrsig=(x,))
        cases = (
            ("control", base, calls_to([x, x2, y2], [x, x2, y2], addrsig=(x, x2)), 0, ()),
            ("OLD's type is not NEW's", base, calls_to([(x, 0, 0, 0, 2), x2, y2], [x, x2, y2], addrsig=(x, x2)), 1,
             ("BESIDE-KEPT\tB still holds %s in a name that is not a kept site's" % x,)),
            ("OLD's value is 4", base, calls_to([(x, 4, 0, 0x20, 2), x2, y2], [x, x2, y2], addrsig=(x, x2)), 1,
             ("BESIDE-KEPT\tB still holds %s in a name that is not a kept site's" % x,)),
            ("OLD is weak", base, calls_to([(x, 0, 0, 0x20, 105), x2, y2], [x, x2, y2], addrsig=(x, x2)), 1,
             ("BESIDE-KEPT\tB still holds %s in a name that is not a kept site's" % x,)),
            ("another rename's OLD, with no kept site", base,
             calls_to([x, x2, y, y2], [x, x2, y2], addrsig=(x, x2)), 1,
             ("BESIDE-KEPT\tB still holds %s in a name that is not a kept site's" % y,)),
            ("A does not mark OLD, B does", calls_to([x, y], [x, x, y], addrsig=()),
             calls_to([x, x2, y2], [x, x2, y2], addrsig=(x,)), 1,
             ("BESIDE-KEPT\tB marks %s address-significant 1 time(s), A 0" % x,)),
            ("A marks OLD, B marks only NEW", base, calls_to([x, x2, y2], [x, x2, y2], addrsig=(x2,)), 1,
             ("BESIDE-KEPT\tB marks %s address-significant 0 time(s), A 1" % x,)),
            ("B marks OLD twice", base, calls_to([x, x2, y2], [x, x2, y2], addrsig=(x, x, x2)), 1,
             ("BESIDE-KEPT\tB marks %s address-significant 2 time(s), A 1" % x,)),
            ("another relocation type at the kept site", base,
             calls_to([x, x2, y2], [x, x2, y2], addrsig=(x, x2), types=[3, 4, 4]), 1,
             ("KEPT-MISSING\t?caller@@YAXXZ\t%s" % x,)))
        for name, a, b, status, lines in cases:
            code, out, err = self.objcmp(a, b, *renames + ("--expect-kept", one))
            self.assertEqual(code, status, (name, out, err))
            for line in lines:
                self.assertIn(line, out.splitlines(), name)
            self.assertEqual(out.startswith("kept: "), status == 0, (name, out))
        # Two OLD symbols are not undone as one, and a call of OLD that is no
        # kept site stays a call of OLD in the BESIDE-KEPT lines.
        code, out, _ = self.objcmp(base, calls_to([x, x2, y2, x], [x, x2, y2, x], addrsig=(x, x2)),
                                   *renames + ("--expect-kept", one))
        self.assertEqual(code, 1, out)
        self.assertEqual(out.count("BESIDE-KEPT\tSYMBOL-ONLY-B\t%s\t" % x), 2, out)
        self.assertIn("BESIDE-KEPT\t\t+reloc\t0x10\ttype 4\t%s" % x, out.splitlines())
        # Each address-significance table is counted by itself.
        def tables(names, targets, first, second):
            sections = [[".text$mn", b"\xe8\0\0\0\0" * 3 + b"\xc3", CODE | COMDAT,
                         [(1 + 5 * i, 2 + names.index(name), 4) for i, name in enumerate(targets)]]]
            symbols = [[".text$mn", 0, 1, 0, 3, 2], ["?caller@@YAXXZ", 0, 1, 0x20, 2, None]]
            symbols += [[name, 0, 0, 0x20, 2, None] for name in names]
            with_addrsig(sections, symbols, *first)
            with_addrsig(sections, symbols, *second)
            return obj(sections, symbols)

        code, out, _ = self.objcmp(tables([x, y], [x, x, y], (x,), ()), tables([x, x2, y2], [x, x2, y2], (x, x2), (x,)),
                                   *renames + ("--expect-kept", one))
        self.assertEqual(code, 1, out)
        self.assertIn("BESIDE-KEPT\tB marks %s address-significant 1 time(s), A 0" % x, out.splitlines())

    def test_expect_kept_file(self):
        # A section key that starts with # can be listed; other lines that
        # start with # are comments, and a list with no site is no option.
        x, x2 = "?x@@YAXXZ", "?x2@@YAXXZ"

        def table(names, targets):
            symbols = [[".rdata", 0, 1, 0, 3, 0]] + [[name, 0, 0, 0x20, 2, None] for name in names]
            return obj([[".rdata", b"\0" * 16, RDATA, [(8 * i, 1 + names.index(name), 1)
                                                       for i, name in enumerate(targets)]]], symbols)

        listed = self.write("listed.txt", ("# kept %s\n#.rdata/1 %s\n# a comment\n" % (x, x)).encode())
        code, out, err = self.objcmp(table([x], [x, x]), table([x, x2], [x, x2]), "%s=%s" % (x, x2),
                                     "--expect-kept", listed)
        self.assertEqual(code, 0, out + err)
        self.assertIn("KEPT-SITE\t#.rdata/1\t0x0\t%s\t%s" % (x, x2), out.splitlines())
        base = three_calls([x], [x, x, x], addrsig=(x,))
        for head in (three_calls([x, x2], [x, x2, x2], addrsig=(x, x2)), three_calls([x2], [x2, x2, x2], addrsig=(x2,)),
                     base, three_calls([x], [x, x, x], addrsig=(x,), code=b"\xe8\0\0\0\0" * 3 + b"\xcc")):
            plain = self.objcmp(base, head, "%s=%s" % (x, x2))
            for text in (b"", b"# nothing\r\n\r\n"):
                self.assertEqual(self.objcmp(base, head, "%s=%s" % (x, x2), "--expect-kept",
                                             self.write("none.txt", text)), plain)
        # An option without its file is a usage error.
        for option in ("--expect-kept", "--map"):
            code, out, err = self.objcmp(base, base, "%s=%s" % (x, x2), option)
            self.assertEqual((code, out), (2, ""), err)
            self.assertTrue(err.startswith("usage: objcmp.py"), err)

    def test_kept_identical(self):
        # Byte-identical objects still say which listed sites the head keeps.
        x, x2 = "?x@@YAXXZ", "?x2@@YAXXZ"
        base = three_calls([x], [x, x, x], addrsig=(x,))
        three = self.write("three.txt", ("?caller@@YAXXZ %s\n" % x * 3).encode())
        code, out, _ = self.objcmp(base, base, "%s=%s" % (x, x2), "--expect-kept", three)
        self.assertEqual(code, 0, out)
        self.assertEqual(out.splitlines(), ["identical: the bytes are equal with the timestamp masked"] +
                         ["KEPT-SITE\t?caller@@YAXXZ\t%s\t%s\t%s" % (at, x, x2) for at in ("0x1", "0x6", "0xb")], out)
        other = self.write("other.txt", ("?other@@YAXXZ %s\n" % x).encode())
        code, out, _ = self.objcmp(base, base, "%s=%s" % (x, x2), "--expect-kept", other)
        self.assertEqual(code, 1, out)
        self.assertEqual(out.splitlines()[0], "differs: 0 difference(s), 4 kept-site mismatch(es)", out)
        self.assertIn("KEPT-MISSING\t?other@@YAXXZ\t%s" % x, out.splitlines())
        # A refused comparison lists no kept-site mismatch.
        both = three_calls([x, x2], [x, x2, x2], addrsig=(x, x2))
        code, out, _ = self.objcmp(both, three_calls([x2], [x2, x2, x2], addrsig=(x2,)), "%s=%s" % (x, x2),
                                   "--expect-kept", other)
        self.assertEqual(code, 1, out)
        self.assertNotIn("KEPT-", out)

    def test_beside_kept(self):
        # When the listed sites are the kept ones, what else differs prints as
        # BESIDE-KEPT lines. As clang-cl orders undefined symbols by first
        # use, a kept call before the first moved call puts NEW after OLD's
        # place: a symbol order that --expect-kept does not accept.
        old, new = "?old_fn@@YAHPEAH@Z", "?new_fn@@YAHPEAH@Z"
        g1, g2, other = "?g1@@3HA", "?g2@@3HA", "?other@@YAHH@Z"
        expected = self.write("f.txt", ("?caller@@YAXXZ %s\n" % old).encode())
        base = calls_to([g1, old, g2, other], [g1, old, g2, old, other])
        for names, targets, status in (([g1, old, g2, new, other], [g1, old, g2, new, other], 1),
                                       ([g1, new, g2, old, other], [g1, new, g2, old, other], 0)):
            code, out, _ = self.objcmp(base, calls_to(names, targets), "%s=%s" % (old, new), "--expect-kept", expected)
            self.assertEqual(code, status, out)
            beside = [line for line in out.splitlines() if line.startswith("BESIDE-KEPT")]
            self.assertEqual(beside, ["BESIDE-KEPT\tSYMBOL-ORDER\tthe same symbols in a different order"] if status
                             else [], out)
        # B still holds OLD in a label beside the kept site.
        x, x2 = "?x@@YAXXZ", "?x2@@YAXXZ"
        label = ("lbl" + x, 15, 1, 0, 6)
        one = self.write("one.txt", ("?caller@@YAXXZ %s\n" % x).encode())
        code, out, _ = self.objcmp(calls_to([x, label], [x, x, x]), calls_to([x, x2, label], [x, x2, x2]),
                                   "%s=%s" % (x, x2), "--expect-kept", one)
        self.assertEqual(code, 1, out)
        self.assertEqual(out.splitlines()[0], "differs: 2 difference(s), 2 RENAME- line(s)", out)
        self.assertIn("BESIDE-KEPT\tB still holds %s in a name that is not a kept site's" % x, out.splitlines())

    def test_base_holds_new(self):
        # With --base-holds-new, a rename whose NEW the base already holds is a
        # merge: into the base's own definition of NEW, or into its existing
        # reference to NEW. Without the option the comparison stays refused.
        rename, caller = "%s=%s" % (OLD, NEW), "?caller@@YAXXZ"
        a, b = merge_unit([OLD], [OLD], addrsig=(OLD, NEW)), merge_unit([NEW], [], addrsig=(NEW,))
        code, out, _ = self.objcmp(a, b, rename)
        self.assertEqual((code, out.splitlines()[0].split(":")[0]), (1, "refused"), out)
        code, out, _ = self.objcmp(a, b, rename, "--base-holds-new")
        self.assertEqual(code, 0, out)
        self.assertEqual(out.splitlines(), [
            "merged: equal with the timestamp masked once the renames are applied, 1 OLD name(s) merged into the NEW "
            "that the base holds: 1 into its own definition, 0 into its existing reference",
            "RETARGET\t%s -> %s\t1 site(s)\tby the map\t%s" % (OLD, NEW, caller),
            "MERGED\t%s -> %s\tinto the base's own definition\t1 relocation(s)" % (OLD, NEW)], out)
        code, out, _ = self.objcmp(a, b, rename, "--base-holds-new", "--json")
        report = json.loads(out)
        self.assertEqual((code, report["result"], report["exit"], report["differences"]), (0, "merged", 0, 0), out)
        self.assertEqual(report["merges"], [dict(old=OLD, new=NEW, into="definition", relocations=1)], out)
        # Into an existing reference: B's one NEW may stand at OLD's place or
        # at NEW's, nowhere else.
        x, y = "?x@@YAXXZ", "?y@@YAXXZ"
        a = merge_unit([OLD, NEW], [OLD, x, NEW, y], new_defined=False)
        for undefined, status in (([NEW, x, y], 0), ([x, NEW, y], 0), ([x, y, NEW], 1)):
            code, out, _ = self.objcmp(a, merge_unit([NEW, NEW], undefined, new_defined=False), rename,
                                       "--base-holds-new")
            self.assertEqual(code, status, (undefined, out))
            if status:
                self.assertIn("SYMBOL-ORDER\tthe same symbols in a different order", out.splitlines(), out)
            else:
                self.assertIn("1 into its existing reference", out.splitlines()[0], out)
                self.assertIn("MERGED\t%s -> %s\tinto the base's existing reference\t1 relocation(s)" % (OLD, NEW),
                              out.splitlines(), out)
        # A merge beside an ordinary rename, which still respells the base.
        p, q = "?p@@YAXXZ", "?q@@YAXXZ"
        code, out, _ = self.objcmp(merge_unit([OLD, p], [OLD, p]), merge_unit([NEW, q], [q]), rename,
                                   "%s=%s" % (p, q), "--base-holds-new")
        self.assertEqual(code, 0, out)
        self.assertTrue(out.startswith("merged: "), out)
        # The address-significance entries merge: one NEW, anywhere in the
        # table; every other entry in A's order.
        for addrsig_b, status in (((caller, NEW), 0), ((NEW, caller), 0), ((caller,), 1), ((caller, NEW, NEW), 1),
                                  ((NEW,), 1)):
            code, out, _ = self.objcmp(merge_unit([OLD], [OLD], addrsig=(caller, OLD, NEW)),
                                       merge_unit([NEW], [], addrsig=addrsig_b), rename, "--base-holds-new")
            self.assertEqual(code, status, (addrsig_b, out))
        # The option does not combine with --expect-kept.
        kept = self.write("kept.txt", ("%s %s\n" % (caller, OLD)).encode())
        code, out, err = self.objcmp(a, b, rename, "--base-holds-new", "--expect-kept", kept)
        self.assertEqual(code, 2, out + err)

    def test_merge_attacks(self):
        # Each head differs from a legitimate merge by one thing, and differs.
        rename, caller, x, y = "%s=%s" % (OLD, NEW), "?caller@@YAXXZ", "?x@@YAXXZ", "?y@@YAXXZ"

        def check(a, b, *expected):
            code, out, _ = self.objcmp(a, b, rename, "--base-holds-new")
            self.assertEqual(code, 1, out)
            self.assertTrue(out.startswith("differs: "), out)
            for line in expected:
                self.assertIn(line, out.splitlines(), out)
            return out

        a = merge_unit([OLD, x], [OLD, x], addrsig=(caller,))
        # Byte-identical objects are "identical", never "merged".
        code, out, _ = self.objcmp(a, a, rename, "--base-holds-new")
        self.assertEqual((code, out.splitlines()[0]), (0, "identical: the bytes are equal with the timestamp masked"))
        # No difference line: B equals A but for a byte past the string table.
        check(a, a + b"\0", "RENAME-KEPT\tB still holds %s" % OLD)
        # A lone address-significance entry of NEW added or removed.
        check(a, merge_unit([NEW, x], [x], addrsig=(caller, NEW)), "\t+addrsig\t1\t%s" % NEW)
        check(merge_unit([OLD, x], [OLD, x], addrsig=(NEW, caller)), merge_unit([NEW, x], [x], addrsig=(caller,)),
              "\t-addrsig\t0\t%s" % NEW)
        # The same relocations in another order: relocations N -> N, no -reloc or +reloc line.
        out = check(a, merge_unit([NEW, x], [x], addrsig=(caller,), order=[1, 0]))
        self.assertIn("relocations 2 -> 2", out)
        self.assertNotIn("reloc\t", out)
        # The head still references OLD: beside the moved call, as a symbol
        # alone, or in an assembler label.
        check(merge_unit([OLD, OLD], [OLD], addrsig=(caller,)), merge_unit([NEW, OLD], [OLD], addrsig=(caller,)),
              "RENAME-KEPT\tB still holds %s" % OLD, "RENAME-MERGES\tB holds both %s and %s" % (OLD, NEW))
        check(a, merge_unit([NEW, x], [x, OLD], addrsig=(caller,)), "RENAME-KEPT\tB still holds %s" % OLD)
        check(a, merge_unit([NEW, x], [x], addrsig=(caller,), extra=[("lbl" + OLD, 0, 1, 0, 6)]),
              "RENAME-KEPT\tB still holds %s" % OLD)
        # Other symbols, or other address-significance entries, in another order.
        check(merge_unit([OLD, x], [OLD, x, y]), merge_unit([NEW, x], [y, x]),
              "SYMBOL-ORDER\tthe same symbols in a different order")
        check(merge_unit([OLD, x], [OLD, x], addrsig=(caller, x)), merge_unit([NEW, x], [x], addrsig=(x, caller)))
        # No relocation of A targets OLD; OLD defined, or embedded in another name; NEW held twice.
        check(merge_unit([x], [x, OLD]), merge_unit([x], [x]), "MERGE-NO-CALL\tno relocation of A targets %s" % OLD)
        check(merge_unit([OLD], [], extra=[(OLD, 0, 1, 0x20, 2)]), merge_unit([NEW], []),
              "MERGE-OLD\tA holds %s other than as one undefined external symbol" % OLD)
        check(merge_unit([OLD], [OLD], extra=[("$unwind$" + OLD, 0, 1, 0, 3)]),
              merge_unit([NEW], [], extra=[("$unwind$" + OLD, 0, 1, 0, 3)]),
              "MERGE-OLD\tA holds %s other than as one undefined external symbol" % OLD)
        check(merge_unit([OLD], [OLD], extra=[(NEW, 0, 0, 0x20, 2)]), merge_unit([NEW], []),
              "MERGE-NEW\tA holds %s other than as one external symbol" % NEW)
        # OLD's call retargeted to another name the base holds, a second call
        # retargeted, the relocation's type or the code changed, the owner's body changed.
        check(a, merge_unit([x, x], [x], addrsig=(caller,)), "\t+reloc\t0x1\ttype 4\t%s" % x)
        check(merge_unit([OLD, x], [OLD, x, y]), merge_unit([NEW, y], [x, y]), "\t+reloc\t0x6\ttype 4\t%s" % y)
        check(a, merge_unit([NEW, x], [x], addrsig=(caller,), types=[5, 4]), "\t+reloc\t0x1\ttype 5\t%s" % NEW)
        check(a, merge_unit([NEW, x], [x], addrsig=(caller,), code=b"\xe8\0\0\0\0\xe8\0\0\0\0\xcc"))
        check(a, merge_unit([NEW, x], [x], addrsig=(caller,), new_body=b"\xcc"))
        # A reference merge whose head's NEW is another kind of symbol.
        check(merge_unit([OLD, NEW], [OLD, NEW], new_defined=False),
              merge_unit([NEW, NEW], [], new_defined=False, extra=[(NEW, 0, 0, 0, 2)]))

    def test_function_order(self):
        # With --function-order, the listed functions' COMDAT sections and
        # their associative children may change place; nothing else may.
        owner, caller, other, x = "?owner@@YAXXZ", "?caller@@YAXXZ", "?other@@YAXXZ", "?x@@YAXXZ"
        listed = self.write("order.txt", ("# moved\n%s\n" % owner).encode())
        text = (".text$mn", None, b"", None, [])
        call = (".text$mn", caller, b"\xe8\0\0\0\0\xc3", "any", [owner])
        rest = (".text$mn", other, b"\xc3", "any", [x])
        body = (".text$mn", owner, b"\xc3", "any", [])
        pdata = (".pdata", None, b"\0" * 4, owner, [])
        base = order_unit([text, call, rest, body, pdata], [x])
        head = order_unit([text, body, pdata, call, rest], [x])
        code, out, _ = self.objcmp(base, head)
        self.assertEqual(code, 1, out)
        self.assertIn("SECTION-ORDER\tthe sections both objects hold are in a different order", out.splitlines())
        code, out, _ = self.objcmp(base, head, "--function-order", listed)
        self.assertEqual(code, 0, out)
        self.assertEqual(out.splitlines(), [
            "reordered: equal with the timestamp masked, but 2 section(s) of the listed function(s) changed place",
            "MOVED\t%s\tplace 3 -> 1" % owner, "MOVED\t%s|.pdata\tplace 4 -> 2" % owner], out)
        code, out, _ = self.objcmp(base, head, "--function-order", listed, "--json")
        report = json.loads(out)
        self.assertEqual((code, report["result"]), (0, "reordered"), out)
        self.assertEqual(report["moved"], [dict(section=owner, a=3, b=1), dict(section=owner + "|.pdata", a=4, b=2)])
        # A merge into the base's own definition whose body is now emitted first.
        rename = "%s=%s" % (OLD, owner)
        merge_base = order_unit([text, (".text$mn", caller, b"\xe8\0\0\0\0\xc3", "any", [OLD]), rest, body, pdata],
                                [x, OLD], addrsig=(caller, OLD, owner))
        merge_head = order_unit([text, body, pdata, call, rest], [x], addrsig=(owner, caller))
        code, out, _ = self.objcmp(merge_base, merge_head, rename, "--base-holds-new", "--function-order", listed)
        self.assertEqual(code, 0, out)
        self.assertEqual(out.splitlines()[0], "merged and reordered: equal with the timestamp masked once the renames "
                         "are applied, 1 OLD name(s) merged into the NEW that the base holds: 1 into its own "
                         "definition, 0 into its existing reference; 2 section(s) of the listed function(s) changed "
                         "place", out)
        code, out, _ = self.objcmp(merge_base, merge_head, rename, "--base-holds-new")
        self.assertEqual(code, 1, out)

        def differs(a, b, *expected):
            code, out, _ = self.objcmp(a, b, "--function-order", listed)
            self.assertEqual(code, 1, out)
            self.assertTrue(out.startswith("differs: "), out)
            for line in expected:
                self.assertIn(line, out.splitlines(), out)
            return out
        # Nothing moved: the verdict stays "identical".
        renamed = order_unit([text, call, (".text$mn", other, b"\xc3", "any", ["?y@@YAXXZ"]), body, pdata],
                             ["?y@@YAXXZ"])
        code, out, _ = self.objcmp(base, renamed, "--function-order", listed, "%s=?y@@YAXXZ" % x)
        self.assertEqual((code, out.splitlines()[0]),
                         (0, "identical: equal with the timestamp masked once the renames are applied"), out)
        # A non-COMDAT section that the listed function leads, a non-COMDAT
        # section, or a COMDAT section of an unlisted function changes place.
        plain = (".text$mn", owner, b"\xc3", None, [])
        differs(order_unit([text, call, rest, plain], [x]), order_unit([text, plain, call, rest], [x]),
                "ORDER-FIXED\t%s\tchanged place; only the listed functions' sections may" % owner)
        rdata = (".rdata", None, b"\1\2\3\4", None, [])
        out = differs(order_unit([text, rdata, call, body], [x]), order_unit([text, call, rdata, body], [x]))
        self.assertTrue(out.splitlines()[1].startswith("ORDER-FIXED\t"), out)
        differs(base, order_unit([text, rest, call, body, pdata], [x]),
                "ORDER-FIXED\t%s\tchanged place; only the listed functions' sections may" % other)
        # Initializer order: two .CRT$XCU entries swapped, and one that is the
        # listed function's associative child moved with it.
        crt1, crt2 = (".CRT$XCU", None, b"\0" * 8, None, [caller]), (".CRT$XCU", None, b"\0" * 8, None, [other])
        differs(order_unit([text, call, rest, crt1, crt2], [x, owner]),
                order_unit([text, call, rest, crt2, crt1], [x, owner]), "\t+reloc\t0x1\ttype 4\t%s" % other)
        crt = (".CRT$XCU", None, b"\0" * 8, owner, [])
        differs(order_unit([text, call, rest, body, crt], [x]), order_unit([text, body, crt, call, rest], [x]),
                "ORDER-FIXED\t%s|.CRT$XCU\tchanged place; only the listed functions' sections may" % owner)
        # The listed functions' sections may change order among themselves too.
        code, out, _ = self.objcmp(base, order_unit([text, pdata, body, call, rest], [x]), "--function-order", listed)
        self.assertEqual((code, out.splitlines()[0].split(":")[0]), (0, "reordered"), out)
        # An extra section; a byte changed in a moved section.
        differs(base, order_unit([text, body, pdata, call, rest, rdata], [x]),
                "SECTION-ONLY-B\t#.rdata/1\t.rdata\t4 bytes")
        differs(base, order_unit([text, (".text$mn", owner, b"\xcc", "any", []), pdata, call, rest], [x]))
        # Symbols equal as a multiset but a relocation retargeted; a label in another section.
        out = differs(order_unit([text, call, rest, body, pdata], [x, "?y@@YAXXZ"]),
                      order_unit([text, body, pdata, (".text$mn", caller, b"\xe8\0\0\0\0\xc3", "any", ["?y@@YAXXZ"]),
                                  rest], [x, "?y@@YAXXZ"]), "\t+reloc\t0x1\ttype 4\t?y@@YAXXZ")
        out = differs(order_unit([text, call, rest, body, pdata], [x], labels=[("lab", 1, caller)]),
                      order_unit([text, body, pdata, call, rest], [x], labels=[("lab", 1, owner)]))
        self.assertNotIn("SYMBOL-ORDER", out)
        # The listed function's address-significance entry may move; another entry may not.
        a = order_unit([text, call, rest, body, pdata], [x], addrsig=(caller, other, owner))
        code, out, _ = self.objcmp(a, order_unit([text, body, pdata, call, rest], [x], addrsig=(owner, caller, other)),
                                   "--function-order", listed)
        self.assertEqual(code, 0, out)
        differs(a, order_unit([text, body, pdata, call, rest], [x], addrsig=(other, caller, owner)))
        differs(a, order_unit([text, body, pdata, call, rest], [x], addrsig=(caller, other)))
        # The option does not combine with --expect-kept.
        kept = self.write("kept.txt", ("%s %s\n" % (caller, OLD)).encode())
        code, out, err = self.objcmp(base, head, "--function-order", listed, "--expect-kept", kept, rename)
        self.assertEqual(code, 2, out + err)

    def test_function_order_keeps_symbol_order(self):
        # Under --function-order the symbols compare as a multiset only when a listed
        # function's section moved; otherwise in order, as without the option.
        rename, caller, x, y = "%s=%s" % (OLD, NEW), "?caller@@YAXXZ", "?x@@YAXXZ", "?y@@YAXXZ"
        listed = self.write("order.txt", (NEW + "\n").encode())
        for args in ((rename, "--base-holds-new"), (rename, "--base-holds-new", "--function-order", listed)):
            # A merge into the base's own definition, other symbols reordered.
            code, out, _ = self.objcmp(merge_unit([OLD, x], [OLD, x, y]), merge_unit([NEW, x], [y, x]), *args)
            self.assertEqual((code, out.splitlines()[0].split(":")[0]), (1, "differs"), (args, out))
            self.assertIn("SYMBOL-ORDER\tthe same symbols in a different order", out.splitlines(), out)
            # A merge into an existing reference whose NEW stands at a third place.
            code, out, _ = self.objcmp(merge_unit([OLD, NEW, x], [OLD, x, NEW, y], new_defined=False),
                                       merge_unit([NEW, NEW, x], [x, y, NEW], new_defined=False), *args)
            self.assertEqual((code, out.splitlines()[0].split(":")[0]), (1, "differs"), (args, out))
        # No merge: a rename that applies and two symbols swapped, nothing moved.
        sections, symbols = calls()
        a = obj(sections, symbols)
        symbols[3], symbols[4] = symbols[4], symbols[3]
        symbols[4][0] = "?z@@YAXXZ"
        sections[0][3] = [(1, 4, 4), (6, 3, 4)]
        code, out, _ = self.objcmp(a, obj(sections, symbols), "?x@@YAXXZ=?z@@YAXXZ", "--function-order", listed)
        self.assertEqual((code, out.splitlines()[0].split(":")[0]), (1, "differs"), out)
        self.assertIn("SYMBOL-ORDER\tthe same symbols in a different order", out.splitlines(), out)

    def test_symbol_order_only_when_equal(self):
        # SYMBOL-ORDER is reported only when the symbol multisets are equal.
        sections, symbols = calls()
        a = obj(sections, symbols)
        symbols[3], symbols[4] = symbols[4], symbols[3]
        sections[0][3] = [(1, 4, 4), (6, 3, 4)]
        code, out, _ = self.objcmp(a, obj(sections, symbols))
        self.assertEqual(code, 1, out)
        self.assertIn("SYMBOL-ORDER\tthe same symbols in a different order", out.splitlines(), out)
        symbols[5][0] = "local2"
        code, out, _ = self.objcmp(a, obj(sections, symbols))
        self.assertEqual(code, 1, out)
        self.assertNotIn("SYMBOL-ORDER", out)
        self.assertIn("SYMBOL-ONLY-B\tlocal2\t4\t#.rdata/1\t0\t3", out.splitlines(), out)

    def test_unreadable(self):
        good = self.write("good.obj", coff())
        missing = os.path.join(self.dir, "missing.obj")
        garbage = self.write("garbage.obj", b"not an object\r\n" * 4)
        truncated = self.write("truncated.obj", coff()[:70])
        machine = self.write("machine.obj", b"\x34\x12" + coff()[2:])
        for args in ([good, missing], [garbage, good], [good, truncated], [good], [good, good, "no-equals-sign"],
                     [good, machine]):
            code, out, err = self.run_tool(OBJCMP, *args)
            self.assertEqual(code, 2, (args, out, err))

    def test_warnings(self):
        base = self.write("base.log", (
            "C:\\work\\src\\a.cpp(10,5): warning: unused variable 'x' [-Wunused-variable]\r\n"
            "[2/9] Building CXX object a.cpp.obj\r\n"
            "C:\\work\\src\\b.h:3:1: warning: no newline [-Wnewline-eof]\r\n").encode())
        head = self.write("head.log", (
            "D:/other/src/a.cpp(12,7): warning: unused variable 'x' [-Wunused-variable]\n"
            "D:/other/src/b.h:4:1: warning: no newline [-Wnewline-eof]\n").encode())
        code, out, _ = self.run_tool(PROOF, "warnings", "--strip", "C:\\work\\", "--strip", "D:/other/", base, head)
        self.assertEqual(code, 0, out)
        self.assertTrue(out.startswith("warnings equal: 2 lines, 2 classes"), out)
        with open(head, "rb") as f:
            more = self.write("more.log", f.read() + b"D:/other/src/c.cpp(1,1): warning: shadow [-Wshadow]\n")
        code, out, _ = self.run_tool(PROOF, "warnings", "--strip", "C:\\work\\", "--strip", "D:/other/", base, more)
        self.assertEqual(code, 1, out)
        self.assertIn("class\t-Wshadow\t0 -> 1", out)
        code, out, _ = self.run_tool(PROOF, "warnings", base, os.path.join(self.dir, "missing.log"))
        self.assertEqual(code, 2, out)

    def test_proof_compile(self):
        compiler, template = self.write("compiler.py", FAKE_COMPILER.encode()), self.write("template.obj", coff())
        source = self.write("unit.cpp", b"unit.cpp(1,1): warning: one [-Wone]\n")
        build = os.path.join(self.dir, "build")
        os.mkdir(build)

        def commands(entry):
            entry = dict(dict(directory=build, file=source, output="CMakeFiles/game.dir/unit.cpp.obj"), **entry)
            with open(os.path.join(build, "compile_commands.json"), "w") as f:
                json.dump([entry], f)

        def prefix(name):
            return os.path.join(self.dir, name)

        commands(dict(arguments=[sys.executable, compiler, template, "/c", "/Foold.obj", "--", source]))
        code, out, err = self.run_tool(PROOF, "compile", build, "unit.cpp", prefix("base"))
        self.assertEqual(code, 0, out + err)
        for name, extra in (("flags", []), ("ob0", ["/Ob0"]), ("od", ["/Od", "/Gy"])):
            self.assertTrue(os.path.exists(prefix("base.%s.obj" % name)), name)
            with open(prefix("base.%s.log" % name)) as f:
                words = json.loads(f.readline())
            at = words.index("--")
            self.assertEqual(words[at - len(extra) - 1:at], extra + ["/Fo" + prefix("base.%s.obj" % name)], words)
            self.assertNotIn("/Foold.obj", words)
        self.run_tool(PROOF, "compile", build, "unit.cpp", prefix("same"))
        code, out, _ = self.run_tool(PROOF, "compare", prefix("base"), prefix("same"))
        self.assertEqual(code, 0, out)
        self.write("unit.cpp", b"unit.cpp(1,1): warning: two [-Wtwo]\n")
        self.run_tool(PROOF, "compile", build, "unit.cpp", prefix("other"))
        code, out, _ = self.run_tool(PROOF, "compare", prefix("base"), prefix("other"))
        self.assertEqual(code, 1, out)
        self.assertIn("warnings differ", out)
        # A failing compile exits 1 and leaves no object of an earlier run.
        for name in ("flags", "ob0", "od"):
            self.write("bad.%s.obj" % name, b"stale")
        self.write("unit.cpp", b"fail\n")
        code, out, err = self.run_tool(PROOF, "compile", build, "unit.cpp", prefix("bad"))
        self.assertEqual(code, 1, out + err)
        for name in ("flags", "ob0", "od"):
            self.assertFalse(os.path.exists(prefix("bad.%s.obj" % name)), name)
        commands(dict(arguments=[os.path.join(self.dir, "no compiler"), "--", source]))
        code, out, err = self.run_tool(PROOF, "compile", build, "unit.cpp", prefix("none"))
        self.assertEqual(code, 2, out + err)
        self.assertEqual(len(err.strip().splitlines()), 1, err)
        if os.name == "nt":
            commands(dict(command="cl.exe /c -- unit.cpp"))
            code, out, err = self.run_tool(PROOF, "compile", build, "unit.cpp", prefix("string"))
            self.assertEqual(code, 2, out + err)


if __name__ == "__main__":
    unittest.main()
