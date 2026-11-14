#!/usr/bin/env python3
"""Check a function-level link: no kept section refers to an unresolved name.

usage: check.py --exe EXE --map MAP --inputs FILE

EXE is the executable that lld-link wrote with /OPT:REF /FORCE:UNRESOLVED
and MAP the /MAP file of that link. FILE lists, one path per line, the
objects of the target and the static libraries that the build made for it.

lld-link replaces every name it cannot resolve by an absolute symbol of
value zero, and its map lists each of them with the address zero. When it
has done so for X before it reaches __imp_X, it makes __imp_X an import
slot of its own that holds zero: the map lists that slot with an address
and no object, and the check counts it as unresolved too. A section is in
the executable when its leading symbol is listed with its own object: the
map lists only symbols of live sections, and an external name with the
object whose copy the link selected. Every relocation of every object read
that targets an unresolved name must be in a COMDAT section that the map
does not list, or in an associative section whose parent is not kept and
that no kept section refers to directly. A section that is not a COMDAT is
never discarded, so a reference from one is live when its object was
loaded. The map may name members only of the libraries read and of the
system libraries listed below, whose objects are not read: references from
those are not checked.

Exit status: 0 accepted; 1 refused (a live reference, or something the check
cannot classify); 2 usage error or unreadable input.
"""
import argparse
import os
import re
import struct
import sys

BIGOBJ_CLASSID = bytes.fromhex("c7a1bad1eebaa94baf20faf66aa4dcb8")
COMDAT = 0x1000
REMOVE = 0x800
NRELOC_OVFL = 0x01000000
STATIC, LABEL = 3, 6
ASSOCIATIVE = 5
# Sections that lld-link drops when it reads an object (lld/COFF/InputFiles.cpp,
# ObjFile::readSection), besides those flagged LNK_REMOVE and those named .debug*:
# the map never lists a symbol of one.
DROPPED = {".drectve", ".llvm_addrsig", ".llvm.call-graph-profile"}

# Names the map lists at address zero that are not unresolved: what lld-link
# defines as absolute zero for x64 (lld/COFF/Driver.cpp) and what the C
# runtime's loadcfg.obj defines or aliases to zero.
KNOWN_ZERO = {
    "__guard_fids_count", "__guard_fids_table", "__guard_flags",
    "__guard_iat_count", "__guard_iat_table", "__guard_longjmp_count",
    "__guard_longjmp_table", "__guard_eh_cont_count", "__guard_eh_cont_table",
    "__enclave_config", "__AbsoluteZero", "__volatile_metadata",
}

# lld-link turns the resource files of a link (on Windows, the manifest that
# CMake embeds) into one object of its own. It holds resource data only, and
# its relocations target its own $R symbols, so it cannot refer to a name of
# the project. The map lists those symbols under this description.
RESOURCE_OBJECT = "internal .obj file created from .res files"
RESOURCE_SYMBOL = re.compile(r"^\$R[0-9A-F]{6}$")

# Libraries the build does not make whose members the map may name, though
# the check does not read them, each with where it was seen: the maps of
# FalloutNV.exe and of the test programs compiled /MT (the cross build) and
# /MD (CMake's default, the Windows CI job), and of a scratch composition of
# WinMain's skipped statements. The map names a library by the file name the
# link used, so the names are compared in lower case.
SYSTEM_LIBRARIES = {
    "libcmt": "the C runtime's startup code, /MT: FalloutNV and the test programs",
    "libcpmt": "the C++ standard library, /MT: FalloutNV",
    "libvcruntime": "the compiler's runtime support, /MT: FalloutNV and the test programs",
    "libucrt": "the Universal C runtime, /MT: FalloutNV and the test programs",
    "msvcrt": "the C runtime's startup code, /MD: FalloutNV and the test programs",
    "msvcprt": "the import library of the C++ standard library, /MD: FalloutNV",
    "vcruntime": "the import library of the compiler's runtime, /MD: FalloutNV, the test programs",
    "ucrt": "the import library of the Universal C runtime, /MD: FalloutNV and the test programs",
    "kernel32": "an import library, both runtimes: FalloutNV and the test programs",
    "user32": "an import library that FalloutNV links, both runtimes: FalloutNV",
    "advapi32": "an import library, both runtimes: the scratch composition (GetUserNameA)",
}


class Unreadable(Exception):
    pass


class Refused(Exception):
    pass


def base_name(path):
    return re.split(r"[\\/]", path)[-1]


def read_pe(data):
    try:
        if data[:2] != b"MZ":
            raise Unreadable("not a PE executable")
        at = struct.unpack_from("<I", data, 0x3C)[0]
        if data[at:at + 4] != b"PE\0\0":
            raise Unreadable("not a PE executable")
        _, count, timestamp, _, _, optional, _ = struct.unpack_from("<HHIIIHH", data, at + 4)
        opt = at + 24
        if struct.unpack_from("<H", data, opt)[0] != 0x20B:
            raise Unreadable("not a PE32+ executable")
        entry = struct.unpack_from("<I", data, opt + 16)[0]
        image_base = struct.unpack_from("<Q", data, opt + 24)[0]
        sections = []
        raw = []
        for i in range(count):
            vsize, va, rawsize = struct.unpack_from("<III", data, opt + optional + 40 * i + 8)
            sections.append((va, max(vsize, rawsize)))
            raw.append((va, rawsize, struct.unpack_from("<I", data, opt + optional + 40 * i + 20)[0]))

        def at_rva(rva):
            for va, size, pointer in raw:
                if va <= rva < va + size:
                    return pointer + rva - va
            raise Unreadable("export table outside the executable's sections")

        exports = []  # the address of each exported function, relative to the load address
        if struct.unpack_from("<I", data, opt + 108)[0] and struct.unpack_from("<I", data, opt + 112)[0]:
            table = at_rva(struct.unpack_from("<I", data, opt + 112)[0])
            functions, _, addresses = struct.unpack_from("<III", data, table + 20)
            exports = list(struct.unpack_from("<%dI" % functions, data, at_rva(addresses)))
    except struct.error as error:
        raise Unreadable("truncated PE executable (%s)" % error)
    return dict(timestamp=timestamp, image_base=image_base, entry=entry, sections=sections,
                exports=exports)


SECTION_LINE = re.compile(r"^ ([0-9a-f]{4}):([0-9a-f]{8}) ([0-9a-f]{8})H \S+ +(CODE|DATA)$")
SYMBOL_LINE = re.compile(r"^ ([0-9a-f]{4}):([0-9a-f]{8}) {7}(\S+) +([0-9a-f]{16})(?: {5}(.+))?$")
EXPECTED = [
    re.compile(r"^ \S.*$"),
    re.compile(r"^$"),
    re.compile(r"^ Timestamp is ([0-9a-f]{8}) \((.*)\)$"),
    re.compile(r"^$"),
    re.compile(r"^ Preferred load address is ([0-9a-f]{16})$"),
    re.compile(r"^$"),
    re.compile(r"^ Start +Length +Name +Class$"),
]
PUBLICS = re.compile(r"^  Address +Publics by Value +Rva\+Base +Lib:Object$")
ENTRY = re.compile(r"^ entry point at +([0-9a-f]{4}):([0-9a-f]{8})$")


def read_map(text):
    """Reads lld-link's /MAP file. Any line out of its place is refused."""
    lines = text.split("\n")
    if lines and lines[-1] == "":
        lines.pop()
    out = dict(sections=[], publics=[], statics=[])

    def fail(number, why):
        line = lines[number] if number < len(lines) else "(end of file)"
        raise Refused("map line %d: %s: %r" % (number + 1, why, line[:120]))

    for number, pattern in enumerate(EXPECTED):
        m = pattern.match(lines[number]) if number < len(lines) else None
        if not m:
            fail(number, "not the line of the map header expected here")
        if number == 0:
            out["app"] = lines[0][1:]
        elif number == 2:
            out["timestamp"] = None if m.group(2) == "Repro mode" else int(m.group(1), 16)
        elif number == 4:
            out["base"] = int(m.group(1), 16)
    number = len(EXPECTED)

    def table(number, pattern, target):
        while number < len(lines) and lines[number] != "":
            m = pattern.match(lines[number])
            if not m:
                fail(number, "not a line of this table")
            target.append(m.groups())
            number += 1
        return number

    number = table(number, SECTION_LINE, out["sections"])
    for pattern in (re.compile("^$"), PUBLICS, re.compile("^$")):
        if number >= len(lines) or not pattern.match(lines[number]):
            fail(number, "not the line expected before the public symbols")
        number += 1
    number = table(number, SYMBOL_LINE, out["publics"])
    m = ENTRY.match(lines[number + 1]) if number + 1 < len(lines) else None
    if number >= len(lines) or not m:
        fail(number + 1, "not the entry point line")
    out["entry"] = (int(m.group(1), 16), int(m.group(2), 16))
    number += 2
    for pattern in (re.compile("^$"), re.compile("^ Static symbols$"), re.compile("^$")):
        if number >= len(lines) or not pattern.match(lines[number]):
            fail(number, "not the line expected before the static symbols")
        number += 1
    number = table(number, SYMBOL_LINE, out["statics"])
    if number != len(lines):
        fail(number, "unexpected line after the static symbols")
    return out


def tie(pe, m, exe_path):
    """Refuses a map that is not the map of this executable."""
    if os.path.splitext(base_name(exe_path))[0].lower() != m["app"].lower():
        raise Refused("the map names %s, not %s" % (m["app"], base_name(exe_path)))
    if m["timestamp"] is not None and m["timestamp"] != pe["timestamp"]:
        raise Refused("map timestamp %08x is not the executable's %08x: a map of another link"
                      % (m["timestamp"], pe["timestamp"]))
    if m["base"] != pe["image_base"]:
        raise Refused("map load address %x is not the executable's %x" % (m["base"], pe["image_base"]))

    def inside(index, offset, length=0):
        return 0 < index <= len(pe["sections"]) and offset + length <= pe["sections"][index - 1][1]

    index, offset = m["entry"]
    if not inside(index, offset) or pe["sections"][index - 1][0] + offset != pe["entry"]:
        raise Refused("map entry point %04x:%08x is not the executable's entry point" % (index, offset))
    # lld-link writes the export of a name it could not resolve as an address
    # outside every section; the map does not list a name only /export names.
    for rva in pe["exports"]:
        if rva and not any(va <= rva < va + size for va, size in pe["sections"]):
            raise Refused("the executable exports the address %08x, which is outside its sections: "
                          "an exported name is unresolved" % rva)
    for index, start, length, _ in m["sections"]:
        if not inside(int(index, 16), int(start, 16), int(length, 16)):
            raise Refused("map section %s:%s of %s bytes is outside the executable's sections"
                          % (index, start, int(length, 16)))


class Coff:
    """Sections, symbols and relocations of one COFF object."""

    def __init__(self, data, desc):
        self.desc = desc
        try:
            self._read(data)
        except (struct.error, IndexError, ValueError, UnicodeDecodeError) as error:
            raise Unreadable("%s: truncated or malformed COFF object (%s)" % (desc, error))

    def _read(self, data):
        if data[0:4] == b"\0\0\xff\xff" and data[12:28] == BIGOBJ_CLASSID:
            count, symptr, nsym = struct.unpack_from("<III", data, 44)
            header, symsize, symfmt = 56, 20, "<IiHBB"
        else:
            machine, count, _, symptr, nsym, optional, _ = struct.unpack_from("<HHIIIHH", data, 0)
            if machine != 0x8664:
                raise ValueError("machine 0x%x is not x64" % machine)
            header, symsize, symfmt = 20 + optional, 18, "<IhHBB"
        strings = data[symptr + nsym * symsize:]

        def string(offset):
            return strings[offset:strings.index(b"\0", offset)].decode("latin1")

        self.sections = []
        for i in range(count):
            at = header + 40 * i
            name = data[at:at + 8].rstrip(b"\0").decode("latin1")
            if name.startswith("/"):
                name = string(int(name[1:]))
            _, _, _, _, relptr, _, nrel, _, flags = struct.unpack_from("<IIIIIIHHI", data, at + 8)
            first = relptr
            if flags & NRELOC_OVFL and nrel == 0xFFFF:
                nrel = struct.unpack_from("<I", data, relptr)[0] - 1
                first = relptr + 10
            targets = {struct.unpack_from("<I", data, first + 10 * r + 4)[0] for r in range(nrel)}
            self.sections.append(dict(name=name, flags=flags, targets=targets, selection=None,
                                      associated=None, leader=None))
        self.symbols = {}  # index -> (name, section), section definitions left out
        self.defined = []  # (name, section) of each symbol the map can list
        self.undefined = set()
        home = {}  # symbol index -> number of its section, section definitions too
        index = 0
        while index < nsym:
            at = symptr + index * symsize
            raw = data[at:at + 8]
            name = string(struct.unpack_from("<I", raw, 4)[0]) if raw[:4] == b"\0\0\0\0" \
                else raw.rstrip(b"\0").decode("latin1")
            value, section, _, storage, naux = struct.unpack_from(symfmt, data, at + 8)
            if 0 < section <= count:
                home[index] = section
            if storage == STATIC and naux and 0 < section <= count:
                s = self.sections[section - 1]
                if s["flags"] & COMDAT:
                    aux = data[at + symsize:at + 2 * symsize]
                    number, selection = struct.unpack_from("<HB", aux, 12)
                    high = struct.unpack_from("<H", aux, 16)[0] if symsize == 20 else 0
                    s["selection"] = selection
                    s["associated"] = number | (high << 16)
            else:
                self.symbols[index] = (name, section)
                if section > 0 and storage != LABEL:
                    self.defined.append((name, section))
                    s = self.sections[section - 1]
                    if s["selection"] is not None and s["leader"] is None:
                        s["leader"] = name  # the COMDAT symbol: the first after the section's
                elif section == 0 and value == 0:
                    self.undefined.add(name)
            index += 1 + naux
        self.refs = {}  # undefined name -> numbers of the sections whose relocations target it
        self.inbound = {}  # section number -> numbers of the other sections that refer into it
        for number, s in enumerate(self.sections, 1):
            for target in s["targets"]:
                if home.get(target, number) != number:
                    self.inbound.setdefault(home[target], set()).add(number)
                name, section = self.symbols.get(target, (None, None))
                if section == 0 and name in self.undefined:
                    self.refs.setdefault(name, []).append(number)


def read_inputs(paths):
    objects = []
    stems = set()
    for path in paths:
        try:
            with open(path, "rb") as f:
                data = f.read()
        except OSError as error:
            raise Unreadable("cannot read %s (%s)" % (path, error))
        if data.startswith(b"!<arch>\n"):
            stem = os.path.splitext(base_name(path))[0]
            stems.add(stem)
            for member, body in read_archive(data, path):
                if body[:4] == b"\0\0\xff\xff" and body[12:28] != BIGOBJ_CLASSID:
                    continue  # a short import object: no sections
                objects.append(Coff(body, "%s:%s" % (stem, base_name(member))))
        else:
            objects.append(Coff(data, base_name(path)))
    return objects, stems


def read_archive(data, path):
    members = []
    longnames = b""
    at = 8
    while at + 60 <= len(data):
        name = data[at:at + 16].decode("latin1").rstrip()
        try:
            size = int(data[at + 48:at + 58].decode("latin1").strip())
        except ValueError:
            raise Unreadable("%s: malformed archive member header" % path)
        body = data[at + 60:at + 60 + size]
        if len(body) != size or data[at + 58:at + 60] != b"`\n":
            raise Unreadable("%s: truncated archive" % path)
        if name == "//":
            longnames = body
        elif name.startswith("/") and name[1:].isdigit():
            start = int(name[1:])
            end = min(i for i in (longnames.find(b"\0", start), longnames.find(b"/\n", start),
                                  len(longnames)) if i >= 0)
            members.append((longnames[start:end].decode("latin1"), body))
        elif name != "/" and name != "/<ECSYMBOLS>/":
            members.append((name[:-1] if name.endswith("/") else name, body))
        at += 60 + size + (size & 1)
    return members


def check(exe_path, map_path, input_paths, out):
    try:
        with open(exe_path, "rb") as f:
            pe = read_pe(f.read())
        with open(map_path, encoding="latin1", newline="\n") as f:
            text = f.read()
    except OSError as error:
        raise Unreadable(str(error))
    m = read_map(text.replace("\r\n", "\n"))
    tie(pe, m, exe_path)
    objects, stems = read_inputs(input_paths)

    count = {}
    for o in objects:
        count[o.desc] = count.get(o.desc, 0) + 1
    kept = {}
    zero = set()
    for _, _, name, va, desc in m["publics"] + m["statics"]:
        if desc == "<absolute>":
            if int(va, 16) == 0:
                zero.add(name)
        elif desc == RESOURCE_OBJECT and RESOURCE_SYMBOL.match(name):
            continue
        elif desc not in (None, "<linker-defined>", "<common>"):
            lib, _, obj = desc.partition(":") if ":" in desc else ("", "", desc)
            key = "%s:%s" % (lib, base_name(obj)) if lib else base_name(obj)
            kept.setdefault(key, set()).add(name)
            if lib and lib not in stems and lib.lower() not in SYSTEM_LIBRARIES:
                raise Refused("the map lists %s from %s, a member of a library the check did not "
                              "read and that is not on its list of system libraries" % (name, desc))
            if (lib in stems or not lib) and key not in count:
                raise Refused("the map lists %s from %s, an object the check did not read"
                              % (name, desc))
    # An import slot that lld-link made for an unresolved X holds zero: the map
    # lists it with an address and no object.
    located = {name for _, _, name, va, desc in m["publics"] + m["statics"]
               if desc is not None and not (desc == "<absolute>" and int(va, 16) == 0)}
    slots = {name for _, _, name, _, desc in m["publics"] + m["statics"]
             if desc is None and name.startswith("__imp_")
             and name[len("__imp_"):] not in located}
    zero |= slots

    referenced = set()
    for o in objects:
        referenced |= o.undefined
    unknown = sorted(zero - referenced - KNOWN_ZERO)
    if unknown:
        raise Refused("absolute zero name %s (of %d, import slots that hold zero included): no "
                      "object read refers to it, so the check cannot tell an unresolved name from "
                      "a defined one" % (unknown[0], len(unknown)))
    unresolved = sorted(zero & referenced)

    owners = {}  # (map name of an object, symbol name) -> objects of that map name defining it
    for o in objects:
        for name in {name for name, _ in o.defined}:
            owners[(o.desc, name)] = owners.get((o.desc, name), 0) + 1

    def listed(o, name):
        """False when the map does not list NAME with O's map name; True when it does and no other
        object of that map name defines NAME; None when another one does too."""
        if name not in kept.get(o.desc, ()):
            return False
        return True if owners[(o.desc, name)] == 1 else None

    def loaded(o):
        if ":" not in o.desc:
            return True  # an object of the target itself
        if any(listed(o, name) is True for name, _ in o.defined):
            return True
        if any(not o.sections[s - 1]["flags"] & (COMDAT | REMOVE) and listed(o, name) is False
               and not o.sections[s - 1]["name"].startswith(".debug")
               and o.sections[s - 1]["name"] not in DROPPED for name, s in o.defined):
            return False  # a symbol of a section that is never discarded is not listed
        return None

    def state(o, number, seen=()):
        """True kept, False discarded, None cannot tell."""
        s = o.sections[number - 1]
        if not s["flags"] & COMDAT:
            return loaded(o)
        if s["selection"] == ASSOCIATIVE:
            parent = s["associated"]
            seen += (number,)
            if parent in seen or not 0 < parent <= len(o.sections):
                return None
            # A kept section can refer to an associative section directly, and
            # lld-link then keeps it whatever became of its parent: the map lists
            # its own symbols, and a reference through its section definition
            # comes from another section of the same object.
            own = {listed(o, name) for name, n in o.defined if n == number}
            if True in own:
                return True
            verdict = state(o, parent, seen)
            if verdict is not False:
                return verdict
            referrers = {state(o, other, seen) for other in o.inbound.get(number, ())
                         if other not in seen}
            if True in referrers:
                return True
            return None if None in own | referrers else False
        if s["leader"] is None:
            return None
        return listed(o, s["leader"])

    problems = 0
    total = 0
    for name in unresolved:
        found = 0
        for o in objects:
            for number in o.refs.get(name, ()):
                found += 1
                verdict = state(o, number)
                where = "%s section %d %s%s" % (o.desc, number, o.sections[number - 1]["name"],
                                                " (" + o.sections[number - 1]["leader"] + ")"
                                                if o.sections[number - 1]["leader"] else "")
                if verdict is True:
                    out.write("LIVE %s from kept %s\n" % (name, where))
                    problems += 1
                elif verdict is None:
                    out.write("UNCLASSIFIED %s from %s: cannot tell whether the section is kept\n"
                              % (name, where))
                    problems += 1
        if not found:
            out.write("UNCLASSIFIED %s: no section of the objects read refers to it\n" % name)
            problems += 1
        total += found
        out.write("unresolved %s: %d references%s\n"
                  % (name, found, ", an import slot that holds zero" if name in slots else ""))
    return problems, len(unresolved), total


def main(argv):
    parser = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    parser.add_argument("--exe", required=True)
    parser.add_argument("--map", required=True)
    parser.add_argument("--inputs", required=True)
    args = parser.parse_args(argv)
    try:
        with open(args.inputs, encoding="utf-8") as f:
            paths = [line.strip() for line in f if line.strip()]
        problems, names, references = check(args.exe, args.map, paths, sys.stdout)
    except Unreadable as error:
        print("function-level link: unreadable input: %s" % error)
        return 2
    except OSError as error:
        print("function-level link: unreadable input: %s" % error)
        return 2
    except Refused as error:
        print("REFUSED %s" % error)
        print("function-level link: refused")
        return 1
    if problems:
        print("function-level link: refused: %d of %d references to %d unresolved names are "
              "live or cannot be classified" % (problems, references, names))
        return 1
    print("function-level link: accepted: %d unresolved names, %d references, all from "
          "discarded sections" % (names, references))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
