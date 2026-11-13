#!/usr/bin/env python3
"""Tests of check.py on hand-made objects, archives, maps and executables."""
import io
import os
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import check  # noqa: E402

TEXT = 0x60000020
DATA = 0xC0000040
COMDAT = 0x1000


def section(name, flags, comdat=None, defines=(), refs=(), overflow=False):
    """comdat: None, a selection number, or ("assoc", parent section number). overflow: write
    the relocation count in the first relocation, as for more than 65,534 relocations."""
    return dict(name=name, flags=flags | (COMDAT if comdat else 0), comdat=comdat,
                defines=list(defines), refs=list(refs), overflow=overflow)


def coff(*sections, bigobj=False, undefined=()):
    """A COFF object. Each section gets its definition symbol, then the
    symbols it defines (external, or static with "s:", or a label with "l:");
    the names it refers to are undefined externals that one relocation each
    targets, a weak external with "w:", or with a number the definition symbol
    of that section. UNDEFINED names are undefined externals that no
    relocation targets."""
    strings = bytearray(4)
    symbols = []
    index_of = {}

    def name_field(name):
        raw = name.encode("latin1")
        if len(raw) <= 8:
            return raw.ljust(8, b"\0")
        offset = len(strings)
        strings.extend(raw + b"\0")
        return b"\0\0\0\0" + struct.pack("<I", offset)

    symsize = 20 if bigobj else 18
    symfmt = "<IiHBB" if bigobj else "<IhHBB"

    section_symbol = {}
    for number, s in enumerate(sections, 1):
        section_symbol[number] = len(symbols)
        if s["comdat"]:
            selection, parent = (5, s["comdat"][1]) if isinstance(s["comdat"], tuple) else (s["comdat"], 0)
        else:
            selection, parent = 0, 0
        aux = struct.pack("<IHHIHBBH", 8, 0, 0, 0, parent & 0xFFFF, selection, 0, parent >> 16)
        symbols.append(name_field(s["name"]) + struct.pack(symfmt, 0, number, 0, 3, 1))
        symbols.append(aux.ljust(symsize, b"\0"))
        for name in s["defines"]:
            storage = {"s:": 3, "l:": 6}.get(name[:2], 2)
            symbols.append(name_field(name[2:] if storage != 2 else name)
                           + struct.pack(symfmt, 0, number, 0x20, storage, 0))
    for s in sections + ({"refs": list(undefined)},):
        for name in s["refs"]:
            if isinstance(name, int):
                index_of[name] = section_symbol[name]
            elif name.startswith("w:") and name not in index_of:
                # a weak external whose default is an undefined external of its own
                index_of[name] = len(symbols)
                symbols.append(name_field(name[2:]) + struct.pack(symfmt, 0, 0, 0, 105, 1))
                symbols.append(struct.pack("<II", len(symbols) + 1, 3).ljust(symsize, b"\0"))
                symbols.append(name_field(name[2:] + "_default") + struct.pack(symfmt, 0, 0, 0x20, 2, 0))
            elif name not in index_of:
                index_of[name] = len(symbols)
                symbols.append(name_field(name) + struct.pack(symfmt, 0, 0, 0x20, 2, 0))
    header = 56 if bigobj else 20
    raw_at = header + 40 * len(sections)
    heads, bodies = [], bytearray()
    for s in sections:
        relocations = b"".join(struct.pack("<IIH", 0, index_of[n], 1) for n in s["refs"])
        count, flags = len(s["refs"]), s["flags"]
        if s["overflow"]:
            relocations = struct.pack("<IIH", count + 1, 0, 0) + relocations
            count, flags = 0xFFFF, flags | check.NRELOC_OVFL
        data_at = raw_at + len(bodies)
        bodies.extend(b"\0" * 8)
        rel_at = raw_at + len(bodies)
        bodies.extend(relocations)
        raw = s["name"].encode()
        if len(raw) > 8:  # a long section name: "/" and its offset in the string table
            raw = b"/%d" % len(strings)
            strings.extend(s["name"].encode() + b"\0")
        heads.append(raw.ljust(8, b"\0")
                     + struct.pack("<IIIIIIHHI", 0, 0, 8, data_at, rel_at if relocations else 0, 0,
                                   count, 0, flags))
    symptr = raw_at + len(bodies)
    nsym = len(symbols)
    strings[0:4] = struct.pack("<I", len(strings))
    if bigobj:
        top = struct.pack("<HHHHI16sIIIIIII", 0, 0xFFFF, 2, 0x8664, 0, check.BIGOBJ_CLASSID,
                          0, 0, 0, 0, len(sections), symptr, nsym)
    else:
        top = struct.pack("<HHIIIHH", 0x8664, len(sections), 0, symptr, nsym, 0, 0)
    return top + b"".join(heads) + bytes(bodies) + b"".join(symbols) + bytes(strings)


def archive(members):
    """An archive in the MS format with a long-name table."""
    longnames = b"".join(name.encode() + b"\0" for name, _ in members)
    out = bytearray(b"!<arch>\n")

    def add(name, body):
        out.extend(name.encode().ljust(16) + b"0".ljust(12) + b"".ljust(6) + b"".ljust(6)
                   + b"644".ljust(8) + str(len(body)).encode().ljust(10) + b"`\n" + body)
        if len(body) & 1:
            out.extend(b"\n")

    add("/", b"\0\0\0\0")
    add("//", longnames)
    offset = 0
    for name, body in members:
        add("/%d" % offset, body)
        offset += len(name) + 1
    return bytes(out)


def pe(timestamp=0x1234, base=0x140000000, entry=0x1010, sections=((0x1000, 0x2000), (0x3000, 0x1000))):
    optional = bytearray(240)
    struct.pack_into("<H", optional, 0, 0x20B)
    struct.pack_into("<I", optional, 16, entry)
    struct.pack_into("<Q", optional, 24, base)
    heads = b"".join(b".sec\0\0\0\0" + struct.pack("<III", size, va, size) + b"\0" * 20
                     for va, size in sections)
    head = bytearray(0x40)
    head[0:2] = b"MZ"
    struct.pack_into("<I", head, 0x3C, 0x40)
    return bytes(head) + b"PE\0\0" + struct.pack("<HHIIIHH", 0x8664, len(sections), timestamp, 0, 0,
                                                240, 0x22) + bytes(optional) + heads


def symbol_line(name, va, desc, section=1, offset=0x10):
    return " %04x:%08x       %s %016x%s" % (section, offset, name.ljust(26), va,
                                            "     " + desc if desc else "")


def zero_line(name):
    return symbol_line(name, 0, "<absolute>", section=0, offset=0)


def make_map(publics=(), statics=(), app="t", timestamp="00001234 (Sat Nov 14 06:38:39 2026)",
             base="0000000140000000", entry="0001:00000010",
             sections=(" 0001:00000000 00000100H .text$mn                CODE",)):
    lines = [" " + app, "", " Timestamp is " + timestamp, "", " Preferred load address is " + base,
             "", " Start         Length     Name                   Class", *sections, "",
             "  Address         Publics by Value              Rva+Base               Lib:Object",
             "", *publics, "", " entry point at         " + entry, "", " Static symbols", "",
             *statics]
    return "\n".join(lines) + "\n"


class CheckTest(unittest.TestCase):
    def run_check(self, inputs, publics=(), statics=(), exe=None, map_text=None):
        """inputs: (file name, bytes) pairs. Returns (exit status, output)."""
        with tempfile.TemporaryDirectory() as folder:
            paths = []
            for name, body in inputs:
                paths.append(os.path.join(folder, name))
                with open(paths[-1], "wb") as f:
                    f.write(body)
            with open(os.path.join(folder, "t.exe"), "wb") as f:
                f.write(pe() if exe is None else exe)
            if map_text is not False:
                with open(os.path.join(folder, "t.map"), "w", newline="\n") as f:
                    f.write(make_map(publics, statics) if map_text is None else map_text)
            with open(os.path.join(folder, "inputs.txt"), "w", encoding="utf-8") as f:
                f.write("\n".join(paths) + "\n")
            out = io.StringIO()
            saved = sys.stdout
            sys.stdout = out
            try:
                status = check.main(["--exe", os.path.join(folder, "t.exe"), "--map",
                                     os.path.join(folder, "t.map"), "--inputs",
                                     os.path.join(folder, "inputs.txt")])
            finally:
                sys.stdout = saved
            return status, out.getvalue()

    def main_obj(self, *extra):
        return coff(section(".text$mn", TEXT, comdat=2, defines=["main"]), *extra)

    def test_dead_comdat_accepted(self):
        obj = self.main_obj(section(".text$mn", TEXT, comdat=2, defines=["dead"], refs=["missing"]))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 0, out)
        self.assertIn("accepted: 1 unresolved names, 1 references", out)

    def test_unresolved_export_refused(self):
        def exporting(address):
            # One exported function at the given address, with the table in the second section.
            data = bytearray(pe())
            optional = 0x40 + 4 + 20
            struct.pack_into("<II", data, optional + 108, 16, 0x3000)
            struct.pack_into("<I", data, optional + 240 + 40 + 20, len(data))
            table = bytearray(44)
            struct.pack_into("<III", table, 20, 1, 0, 0x3028)
            struct.pack_into("<I", table, 40, address)
            return bytes(data + table)

        obj = self.main_obj(section(".text$mn", TEXT, comdat=2, defines=["dead"], refs=["missing"]))
        publics = [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")]
        status, out = self.run_check([("a.obj", obj)], publics, exe=exporting(0x1010))
        self.assertEqual(status, 0, out)
        # lld-link writes the export of an unresolved name as an address outside every section.
        status, out = self.run_check([("a.obj", obj)], publics, exe=exporting(0xC0000000))
        self.assertNotEqual(status, 0, out)
        self.assertIn("exports the address c0000000", out)

    def test_kept_comdat_live(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["missing"]))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 1 .text$mn (main)", out)

    def test_static_leader_kept_live(self):
        obj = self.main_obj(section(".text$mn", TEXT, comdat=2, defines=["s:helper"], refs=["missing"]))
        status, out = self.run_check([("a.obj", obj)], [symbol_line("main", 0x140001010, "a.obj"),
                                                        zero_line("missing")],
                                     [symbol_line("helper", 0x140001020, "a.obj")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 2", out)

    def test_non_comdat_section_live(self):
        obj = self.main_obj(section(".data", DATA, defines=["table"], refs=["missing"]))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 2 .data", out)

    def test_associative_follows_parent(self):
        kept = self.main_obj(section(".xdata", DATA, comdat=("assoc", 1), refs=["missing"]))
        status, out = self.run_check([("a.obj", kept)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 2 .xdata", out)
        dead = self.main_obj(section(".text$mn", TEXT, comdat=2, defines=["dead"]),
                             section(".xdata", DATA, comdat=("assoc", 2), refs=["missing"]))
        status, out = self.run_check([("a.obj", dead)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 0, out)

    def test_member_not_loaded_accepted(self):
        lib = archive([("dir/m.obj", coff(section(".data", DATA, defines=["g"], refs=["missing"])))])
        status, out = self.run_check([("a.obj", self.main_obj(section(".text$mn", TEXT, comdat=2,
                                                                       defines=["d"], refs=["missing"]))),
                                      ("parts.lib", lib)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 0, out)
        self.assertIn("2 references", out)

    def test_member_loaded_live(self):
        lib = archive([("dir/m.obj", coff(section(".data", DATA, defines=["g"], refs=["missing"])))])
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("g", 0x140003000, "parts:m.obj", section=2, offset=0),
                                      zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept parts:m.obj section 1 .data", out)

    def test_member_with_only_comdats_unclassified(self):
        member = coff(section(".text$mn", TEXT, comdat=2, defines=["f"]),
                      section(".CRT$XCU", DATA, refs=["missing"]))
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", archive([("m.obj", member)]))],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("UNCLASSIFIED missing from parts:m.obj section 2 .CRT$XCU", out)

    def test_backslash_member_name(self):
        lib = archive([("CMakeFiles\\parts.dir\\m.obj",
                        coff(section(".text$mn", TEXT, comdat=2, defines=["f"], refs=["missing"])))])
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("f", 0x140001020, "parts:CMakeFiles\\parts.dir\\m.obj"),
                                      zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept parts:m.obj", out)

    def test_two_objects_one_name_unclassified(self):
        one = coff(section(".text$mn", TEXT, comdat=2, defines=["f"], refs=["missing"]))
        lib = archive([("x/m.obj", one), ("y/m.obj", coff(section(".text$mn", TEXT, comdat=2,
                                                                    defines=["f"])))])
        publics = [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing"),
                   symbol_line("f", 0x140001020, "parts:m.obj")]
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)], publics)
        self.assertEqual(status, 1, out)
        self.assertIn("UNCLASSIFIED missing from parts:m.obj", out)

    def test_two_objects_one_name_told_apart(self):
        one = coff(section(".text$mn", TEXT, comdat=2, defines=["f"], refs=["missing"]),
                   section(".text$mn", TEXT, comdat=2, defines=["h"], refs=["missing"]))
        lib = archive([("x/m.obj", one), ("y/m.obj", coff(section(".text$mn", TEXT, comdat=2,
                                                                    defines=["g"])))])
        publics = [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing"),
                   symbol_line("f", 0x140001020, "parts:m.obj"),
                   symbol_line("g", 0x140001030, "parts:m.obj")]
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)], publics)
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept parts:m.obj section 1", out)
        self.assertNotIn("section 2", out)
        self.assertIn("unresolved missing: 2 references", out)

    def test_other_copy_selected_accepted(self):
        mine = self.main_obj(section(".text$mn", TEXT, comdat=2, defines=["inl"], refs=["missing"]))
        other = coff(section(".text$mn", TEXT, comdat=2, defines=["inl"]))
        status, out = self.run_check([("a.obj", mine), ("b.obj", other)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("inl", 0x140001020, "b.obj"), zero_line("missing")])
        self.assertEqual(status, 0, out)

    def test_no_relocation_unclassified(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"]), undefined=["missing"])
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("UNCLASSIFIED missing: no section of the objects read refers to it", out)

    def test_zero_name_without_reference_refused(self):
        status, out = self.run_check([("a.obj", self.main_obj())],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("other")])
        self.assertEqual(status, 1, out)
        self.assertIn("REFUSED absolute zero name other", out)

    def test_known_zero_names_accepted(self):
        status, out = self.run_check([("a.obj", self.main_obj())],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      zero_line("__guard_fids_table"), zero_line("__AbsoluteZero")])
        self.assertEqual(status, 0, out)
        self.assertIn("accepted: 0 unresolved names", out)

    def test_unread_project_object_refused(self):
        lib = archive([("m.obj", coff(section(".text$mn", TEXT, comdat=2, defines=["f"])))])
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("h", 0x140001020, "parts:n.obj")])
        self.assertEqual(status, 1, out)
        self.assertIn("an object the check did not read", out)
        status, out = self.run_check([("a.obj", self.main_obj())],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("h", 0x140001020, "b.obj")])
        self.assertEqual(status, 1, out)

    def test_system_library_object_not_read(self):
        status, out = self.run_check([("a.obj", self.main_obj())],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("mainCRTStartup", 0x140001020,
                                                  "libcmt:D:\\a\\objr\\amd64\\exe_main.obj")])
        self.assertEqual(status, 0, out)

    def test_unknown_map_line_refused(self):
        text = make_map([symbol_line("main", 0x140001010, "a.obj")]).replace(
            " Static symbols", " Static symbols\n Exports")
        status, out = self.run_check([("a.obj", self.main_obj())], map_text=text)
        self.assertEqual(status, 1, out)
        self.assertIn("REFUSED map line", out)
        text = make_map(["0001:00000010 main 0000000140001010 a.obj"])
        status, out = self.run_check([("a.obj", self.main_obj())], map_text=text)
        self.assertEqual(status, 1, out)
        text = make_map([symbol_line("main", 0x140001010, "a.obj")]).split(" entry point")[0]
        status, out = self.run_check([("a.obj", self.main_obj())], map_text=text)
        self.assertEqual(status, 1, out)

    def test_missing_map_unreadable(self):
        status, out = self.run_check([("a.obj", self.main_obj())], map_text=False)
        self.assertEqual(status, 2, out)

    def test_map_of_another_link_refused(self):
        publics = [symbol_line("main", 0x140001010, "a.obj")]
        for exe in (pe(timestamp=0x9999), pe(base=0x400000), pe(entry=0x1020),
                    pe(sections=((0x1000, 0x80),))):
            status, out = self.run_check([("a.obj", self.main_obj())], publics, exe=exe)
            self.assertEqual(status, 1, out)
            self.assertIn("REFUSED", out)
        status, out = self.run_check([("a.obj", self.main_obj())],
                                     map_text=make_map(publics, app="other"))
        self.assertEqual(status, 1, out)

    def test_repro_mode_timestamp_not_compared(self):
        text = make_map([symbol_line("main", 0x140001010, "a.obj")],
                        timestamp="00000000 (Repro mode)")
        status, out = self.run_check([("a.obj", self.main_obj())], exe=pe(timestamp=0x5678),
                                     map_text=text)
        self.assertEqual(status, 0, out)

    def test_bigobj_read(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["missing"]), bigobj=True)
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 1", out)

    def test_truncated_object_unreadable(self):
        status, out = self.run_check([("a.obj", self.main_obj()[:30])],
                                     [symbol_line("main", 0x140001010, "a.obj")])
        self.assertEqual(status, 2, out)

    def test_truncated_member_unreadable(self):
        lib = archive([("m.obj", self.main_obj()[:30])])
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)],
                                     [symbol_line("main", 0x140001010, "a.obj")])
        self.assertEqual(status, 2, out)
        self.assertIn("unreadable input: parts:m.obj", out)

    def test_import_slot_live(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["__imp_missing"]),
                   section(".text$mn", TEXT, comdat=2, defines=["dead"], refs=["missing"]))
        publics = [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing"),
                   symbol_line("__imp_missing", 0x140003000, None, section=2, offset=0)]
        status, out = self.run_check([("a.obj", obj)], publics)
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE __imp_missing from kept a.obj section 1 .text$mn (main)", out)
        self.assertIn("unresolved __imp_missing: 1 references, an import slot that holds zero", out)
        self.assertIn("unresolved missing: 1 references\n", out)
        # A slot that no object read refers to is refused, not passed over.
        unused = coff(section(".text$mn", TEXT, comdat=2, defines=["main"]),
                      section(".text$mn", TEXT, comdat=2, defines=["dead"], refs=["missing"]))
        status, out = self.run_check([("a.obj", unused)], publics)
        self.assertEqual(status, 1, out)
        self.assertIn("REFUSED absolute zero name __imp_missing", out)

    def test_import_slot_of_defined_name_accepted(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["__imp_f"]),
                   section(".text$mn", TEXT, comdat=2, defines=["f"]))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("f", 0x140001020, "a.obj"),
                                      symbol_line("__imp_f", 0x140003000, None, section=2, offset=0)])
        self.assertEqual(status, 0, out)
        self.assertIn("accepted: 0 unresolved names", out)

    def test_associative_kept_by_direct_reference(self):
        named = self.main_obj(section(".text$mn", TEXT, comdat=2, defines=["dead"]),
                              section(".rdata", DATA, comdat=("assoc", 2), defines=["child"],
                                      refs=["missing"]))
        status, out = self.run_check([("a.obj", named)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("child", 0x140003000, "a.obj", section=2, offset=0),
                                      zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 3 .rdata", out)
        through_section = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=[3]),
                               section(".text$mn", TEXT, comdat=2, defines=["dead"]),
                               section(".rdata", DATA, comdat=("assoc", 2), refs=["missing"]))
        status, out = self.run_check([("a.obj", through_section)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 3 .rdata", out)

    def test_associative_of_two_members_unclassified(self):
        def member(*extra):
            return coff(section(".text$mn", TEXT, comdat=2, defines=["dead"]),
                        section(".rdata", DATA, comdat=("assoc", 1), defines=["child"], refs=["missing"]),
                        *extra)
        lib = archive([("x/m.obj", member()), ("y/m.obj", member())])
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("child", 0x140003000, "parts:m.obj", section=2, offset=0),
                                      zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("UNCLASSIFIED missing from parts:m.obj section 2 .rdata", out)
        # The parent's leading symbol is listed and both members define it:
        # the parent cannot be classified, so neither can its child.
        status, out = self.run_check([("a.obj", self.main_obj()), ("parts.lib", lib)],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("dead", 0x140001020, "parts:m.obj"),
                                      zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("UNCLASSIFIED missing from parts:m.obj section 2 .rdata", out)

    def test_target_object_always_loaded(self):
        other = coff(section(".text$mn", TEXT, comdat=2, defines=["f"]),
                     section(".CRT$XCU", DATA, refs=["missing"]))
        status, out = self.run_check([("a.obj", self.main_obj()), ("b.obj", other)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept b.obj section 2 .CRT$XCU", out)

    def test_import_of_unresolved_name_from_library_accepted(self):
        # An import library that exports X as data defines only __imp_X: its
        # slot holds X's address in the DLL, so a reference to it is resolved.
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["__imp_value"]),
                   section(".text$mn", TEXT, comdat=2, defines=["dead"], refs=["value"]))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("value"),
                                      symbol_line("__imp_value", 0x140003000, "kernel32:KERNEL32.dll",
                                                  section=2, offset=0)])
        self.assertEqual(status, 0, out)
        self.assertIn("accepted: 1 unresolved names, 1 references", out)

    def test_unread_library_refused(self):
        status, out = self.run_check([("a.obj", self.main_obj())],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("helper", 0x140001020, "other:x.obj")])
        self.assertEqual(status, 1, out)
        self.assertIn("REFUSED the map lists helper from other:x.obj, a member of a library", out)
        status, out = self.run_check([("a.obj", self.main_obj())],
                                     [symbol_line("main", 0x140001010, "a.obj"),
                                      symbol_line("GetUserNameA", 0x140001020, "Advapi32:ADVAPI32.dll")])
        self.assertEqual(status, 0, out)

    def test_leaderless_comdat_unclassified(self):
        obj = self.main_obj(section(".text$mn", TEXT, comdat=2, refs=["missing"]))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("UNCLASSIFIED missing from a.obj section 2", out)

    def test_bad_associative_parent_unclassified(self):
        for parent in (0, 9, 2):  # none, past the last section, and itself
            obj = self.main_obj(section(".xdata", DATA, comdat=("assoc", parent), refs=["missing"]))
            status, out = self.run_check([("a.obj", obj)],
                                         [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
            self.assertEqual(status, 1, out)
            self.assertIn("UNCLASSIFIED missing from a.obj section 2", out)

    def test_bigobj_associative_parent_high_part(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"]),
                   section(".text$mn", TEXT, comdat=2, defines=["dead"]),
                   section(".xdata", DATA, comdat=("assoc", 0x10002), refs=["missing"]), bigobj=True)
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("UNCLASSIFIED missing from a.obj section 3", out)

    def test_relocation_count_overflow_read(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["missing"], overflow=True))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 1", out)
        self.assertIn("unresolved missing: 1 references", out)

    def test_weak_external_unresolved(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["w:missing"]))
        status, out = self.run_check([("a.obj", obj)],
                                     [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 1", out)

    def test_symbols_never_listed_are_no_evidence(self):
        # A label, and a symbol of a section that lld-link drops, are never in
        # the map, so neither shows that the member was not loaded.
        for extra in (section(".text", TEXT, defines=["l:$LN1"]),
                      section(".debug$S", DATA, defines=["s:dbg"]),
                      section(".pdata", DATA | 0x800, defines=["s:removed"]),
                      section(".llvm_addrsig", DATA, defines=["s:marker"]),
                      section(".drectve", DATA, defines=["s:directive"]),
                      section(".llvm.call-graph-profile", DATA, defines=["s:profile"])):
            member = coff(section(".text$mn", TEXT, comdat=2, defines=["f"]),
                          section(".CRT$XCU", DATA, refs=["missing"]), extra)
            status, out = self.run_check([("a.obj", self.main_obj()),
                                          ("parts.lib", archive([("m.obj", member)]))],
                                         [symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
            self.assertEqual(status, 1, out)
            self.assertIn("UNCLASSIFIED missing from parts:m.obj section 2 .CRT$XCU", out)

    def test_map_line_after_static_symbols_refused(self):
        text = make_map([symbol_line("main", 0x140001010, "a.obj")]) + "\n Exports\n"
        status, out = self.run_check([("a.obj", self.main_obj())], map_text=text)
        self.assertEqual(status, 1, out)
        self.assertIn("REFUSED map line", out)

    def test_symbol_line_with_other_tail_refused(self):
        line = symbol_line("main", 0x140001010, None) + "   a.obj"
        status, out = self.run_check([("a.obj", self.main_obj())], map_text=make_map([line]))
        self.assertEqual(status, 1, out)
        self.assertIn("REFUSED map line", out)

    def test_crlf_map_read(self):
        obj = coff(section(".text$mn", TEXT, comdat=2, defines=["main"], refs=["missing"]))
        text = make_map([symbol_line("main", 0x140001010, "a.obj"), zero_line("missing")])
        status, out = self.run_check([("a.obj", obj)], map_text=text.replace("\n", "\r\n"))
        self.assertEqual(status, 1, out)
        self.assertIn("LIVE missing from kept a.obj section 1", out)


if __name__ == "__main__":
    unittest.main()
