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
            self.assertIn("SECTION-DIFFERS\t#.llvm_addrsig/1\t.llvm_addrsig\taddress-significance names differ, %d -> %d"
                          % (len(names_a), len(names_b)), out)
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
                "kept_sites"}
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
                         ["SYMBOL-SHIFT\t?buf@@3PADA\t3 symbol(s)\tby +0x100",
                          "SYMBOL-SHIFT\t?buf@@3PADA\t1 symbol(s)\tby -0x18",
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
