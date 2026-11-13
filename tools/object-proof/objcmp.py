#!/usr/bin/env python3
"""Compare two COFF objects with the header timestamp masked.

usage: objcmp.py A.obj B.obj [--map FILE] [OLD=NEW ...]

A is the base object, B the head object. Each OLD=NEW pair (from the command
line, or one per line of FILE) is a respelling of the base: a symbol of A
named OLD, and a name of A that embeds a C++ OLD name, is compared as spelled
with NEW. B is compared as it is. The objects are identical when their bytes
are equal with the timestamp masked, or, when a rename applies to A, when the
header, every section (bytes, relocations by target name) and the symbol
table are equal once respelled. A rename is refused as a difference when an
object holds both spellings (RENAME-MERGES) or B still holds OLD
(RENAME-KEPT). Otherwise it prints the sections, relocations and symbols that
differ.

Exit status: 0 identical, 1 differs, 2 usage error or unreadable input.
"""
import difflib
import struct
import sys

BIGOBJ_CLASSID = bytes.fromhex("c7a1bad1eebaa94baf20faf66aa4dcb8")
MACHINES = {0x14C, 0x8664, 0xAA64, 0x1C4}
NRELOC_OVFL = 0x01000000
UNINITIALIZED = 0x80
COMDAT = 0x1000
EXTERNAL, STATIC, WEAK_EXTERNAL = 2, 3, 105


class Unreadable(Exception):
    pass


def timestamp_offset(data):
    if len(data) >= 28 and data[0:4] == b"\0\0\xff\xff" and data[12:28] == BIGOBJ_CLASSID:
        return 8
    return 4


def masked(data):
    data = bytearray(data)
    at = timestamp_offset(data)
    data[at:at + 4] = b"\0\0\0\0"
    return bytes(data)


class Coff:
    """The parts of a COFF object that the comparison reads."""

    def __init__(self, data, renames):
        try:
            self._read(data, renames)
        except (struct.error, IndexError, ValueError) as error:
            raise Unreadable("truncated or malformed COFF object (%s)" % error)

    def _read(self, data, renames):
        if len(data) >= 28 and data[0:4] == b"\0\0\xff\xff" and data[12:28] == BIGOBJ_CLASSID:
            self.bigobj = True
            self.machine = struct.unpack_from("<H", data, 6)[0]
            count, symptr, nsym = struct.unpack_from("<III", data, 44)
            self.flags = 0
            header, symsize, secfmt = 56, 20, "<IiHBB"
        else:
            self.bigobj = False
            self.machine, count, _, symptr, nsym, optional, self.flags = struct.unpack_from("<HHIIIHH", data, 0)
            header, symsize, secfmt = 20 + optional, 18, "<IhHBB"
        if self.machine not in MACHINES:
            raise Unreadable("not a COFF object (machine 0x%x)" % self.machine)
        strings = data[symptr + nsym * symsize:]

        def string(offset):
            end = strings.index(b"\0", offset)
            return strings[offset:end].decode("latin1")

        def short_name(raw):
            if raw[:4] == b"\0\0\0\0":
                return string(struct.unpack_from("<I", raw, 4)[0])
            return raw.rstrip(b"\0").decode("latin1")

        sections = []
        for index in range(count):
            at = header + 40 * index
            raw = data[at:at + 8]
            if len(raw) < 8:
                raise ValueError("section header %d past the end" % (index + 1))
            name = raw.rstrip(b"\0").decode("latin1")
            if name.startswith("/"):
                name = string(int(name[1:]))
            _, _, size, rawptr, relptr, _, nrel, _, characteristics = struct.unpack_from("<IIIIIIHHI", data, at + 8)
            body = b"" if characteristics & UNINITIALIZED else data[rawptr:rawptr + size]
            if len(body) != (0 if characteristics & UNINITIALIZED else size):
                raise ValueError("section %d past the end" % (index + 1))
            first = relptr
            if characteristics & NRELOC_OVFL and nrel == 0xFFFF:
                nrel = struct.unpack_from("<I", data, relptr)[0] - 1
                first = relptr + 10
            relocations = [struct.unpack_from("<IIH", data, first + 10 * r) for r in range(nrel)]
            sections.append(dict(name=name, characteristics=characteristics, size=size, body=body,
                                 relocations=relocations, selection=None, associated=None))

        self.names = set()
        symbols = []  # (index, name, value, section, type, storage, aux bytes)
        index = 0
        while index < nsym:
            at = symptr + index * symsize
            raw = data[at:at + 8]
            value, section, typ, storage, naux = struct.unpack_from(secfmt, data, at + 8)
            aux = data[at + symsize:at + symsize * (1 + naux)]
            if len(aux) != symsize * naux:
                raise ValueError("symbol %d past the end" % index)
            name = short_name(raw)
            self.names.add(name)
            if storage in (EXTERNAL, STATIC, WEAK_EXTERNAL):
                name = rename(name, renames)
            symbols.append((index, name, value, section, typ, storage, aux))
            if (storage == STATIC and naux and 0 < section <= count and value == 0
                    and name == sections[section - 1]["name"]):
                s = sections[section - 1]
                s["is_section_symbol"] = index
                if s["characteristics"] & COMDAT:
                    number, selection = struct.unpack_from("<HB", aux, 12)
                    high = struct.unpack_from("<H", aux, 16)[0] if self.bigobj else 0
                    s["selection"] = selection
                    if selection == 5:
                        s["associated"] = number | (high << 16)
            index += 1 + naux
        self.symbols = symbols
        self.by_index = {s[0]: s for s in symbols}
        self.sections = sections
        self._name_sections()

    def _name_sections(self):
        """A section is named by the symbol that leads it: the external (or
        failing that the static, non-section) symbol defined at offset 0.
        Other sections are named by their name and ordinal; an associative
        section by its parent's key and its own name."""
        leaders = {}
        for preference in ((EXTERNAL, WEAK_EXTERNAL), (STATIC,)):
            for index, name, value, section, _, storage, aux in self.symbols:
                if storage not in preference or section <= 0 or value != 0 or section in leaders:
                    continue
                if self.sections[section - 1].get("is_section_symbol") == index:
                    continue
                leaders[section] = name
        seen = {}
        keys = []
        for number, s in enumerate(self.sections, 1):
            if number in leaders:
                key = leaders[number]
            else:
                seen[s["name"]] = seen.get(s["name"], 0) + 1
                key = "#%s/%d" % (s["name"], seen[s["name"]])
            keys.append(key)
        for number, s in enumerate(self.sections, 1):
            if s["associated"] and number not in leaders and 0 < s["associated"] <= len(keys):
                keys[number - 1] = "%s|%s" % (keys[s["associated"] - 1], s["name"])
        used = {}
        for i, key in enumerate(keys):
            used[key] = used.get(key, 0) + 1
            if used[key] > 1:
                keys[i] = "%s#%d" % (key, used[key])
        self.keys = keys

    def section_key(self, number):
        if 0 < number <= len(self.keys):
            return self.keys[number - 1]
        return {0: "(undefined)", -1: "(absolute)", -2: "(debug)"}.get(number, "(section %d)" % number)

    def target(self, index):
        if index not in self.by_index:
            return "(symbol %d)" % index
        _, name, value, section, _, storage, _ = self.by_index[index]
        if storage == STATIC and 0 < section <= len(self.sections) and \
                self.sections[section - 1].get("is_section_symbol") == index:
            return "[%s]" % self.section_key(section)
        if storage == STATIC:
            return "%s@%s+0x%x" % (name, self.section_key(section), value)
        return name

    def compared(self):
        """Every section and symbol with indices replaced by names."""
        sections = {}
        order = []
        for number, s in enumerate(self.sections, 1):
            key = self.keys[number - 1]
            body = s["body"]
            if s["name"] == ".llvm_addrsig":
                body = tuple(self.target(i) for i in uleb128s(body))
            relocations = tuple((va, typ, self.target(i)) for va, i, typ in s["relocations"])
            sections[key] = dict(name=s["name"], characteristics=s["characteristics"], size=s["size"],
                                 selection=s["selection"], body=body, relocations=relocations)
            order.append(key)
        symbols = []
        for index, name, value, section, typ, storage, aux in self.symbols:
            if self.sections and 0 < section <= len(self.sections) and \
                    self.sections[section - 1].get("is_section_symbol") == index:
                # The section comparison covers the aux record's size,
                # relocation count and checksum of the bytes; the associated
                # section is compared by its key.
                aux = (aux[6:8], aux[14:15], self.section_key(self.sections[section - 1]["associated"] or 0))
            elif storage == WEAK_EXTERNAL and len(aux) >= 4:
                aux = (self.target(struct.unpack_from("<I", aux, 0)[0]), aux[4:])
            symbols.append((name, value, self.section_key(section), typ, storage, aux))
        header = dict(machine=self.machine, flags=self.flags, bigobj=self.bigobj)
        return header, sections, order, symbols


def rename(name, renames):
    """Renames a symbol. A C++ name (one that starts with "?") is also
    renamed where it is embedded in another name, as in the unwind tables
    and static locals of a renamed function; other names only as a whole."""
    if name in renames:
        return renames[name]
    for old in sorted(renames, key=len, reverse=True):
        if old.startswith("?") and old in name:
            name = name.replace(old, renames[old])
    return name


def spelled(name, names):
    """The names that are the given name or, for a C++ name, embed it."""
    return [n for n in names if n == name or (name.startswith("?") and name in n)]


def uleb128s(data):
    out, value, shift = [], 0, 0
    for byte in data:
        value |= (byte & 0x7F) << shift
        shift += 7
        if not byte & 0x80:
            out.append(value)
            value, shift = 0, 0
    return out


def describe(item):
    return "\t".join(str(x) for x in item[:5])


def compare(a, b, out):
    """Prints the differences of two Coff objects; returns their count."""
    ha, sa, oa, ya = a.compared()
    hb, sb, ob, yb = b.compared()
    found = 0
    for field in ("machine", "flags", "bigobj"):
        if ha[field] != hb[field]:
            out("HEADER\t%s\t%s -> %s" % (field, ha[field], hb[field]))
            found += 1
    for key in oa:
        if key not in sb:
            out("SECTION-ONLY-A\t%s\t%s\t%d bytes" % (key, sa[key]["name"], sa[key]["size"]))
            found += 1
    for key in ob:
        if key not in sa:
            out("SECTION-ONLY-B\t%s\t%s\t%d bytes" % (key, sb[key]["name"], sb[key]["size"]))
            found += 1
    for key in oa:
        if key not in sb or sa[key] == sb[key]:
            continue
        x, y = sa[key], sb[key]
        found += 1
        parts = []
        for field in ("name", "characteristics", "selection"):
            if x[field] != y[field]:
                parts.append("%s %s -> %s" % (field, x[field], y[field]))
        if x["body"] != y["body"]:
            if isinstance(x["body"], tuple):
                parts.append("address-significance names differ")
            else:
                differing = [i for i in range(min(len(x["body"]), len(y["body"]))) if x["body"][i] != y["body"][i]]
                where = (", first at 0x%x" % differing[0]) if differing else ""
                parts.append("size %d -> %d, %d bytes differ%s" % (x["size"], y["size"], len(differing), where))
        if x["relocations"] != y["relocations"]:
            parts.append("relocations %d -> %d" % (len(x["relocations"]), len(y["relocations"])))
        out("SECTION-DIFFERS\t%s\t%s\t%s" % (key, x["name"], "; ".join(parts)))
        if x["relocations"] != y["relocations"]:
            rx, ry = set(x["relocations"]), set(y["relocations"])
            for va, typ, target in sorted(rx - ry):
                out("\t-reloc\t0x%x\ttype %d\t%s" % (va, typ, target))
            for va, typ, target in sorted(ry - rx):
                out("\t+reloc\t0x%x\ttype %d\t%s" % (va, typ, target))
        if isinstance(x["body"], tuple) and x["body"] != y["body"]:
            for name in sorted(set(x["body"]) - set(y["body"])):
                out("\t-addrsig\t%s" % name)
            for name in sorted(set(y["body"]) - set(x["body"])):
                out("\t+addrsig\t%s" % name)
    common_a = [k for k in oa if k in sb]
    common_b = [k for k in ob if k in sa]
    if common_a != common_b:
        out("SECTION-ORDER\tthe sections both objects hold are in a different order")
        matcher = difflib.SequenceMatcher(None, common_a, common_b, autojunk=False)
        for op, a1, a2, b1, b2 in matcher.get_opcodes():
            for key in common_a[a1:a2] if op != "equal" else ():
                out("\t-order\t%d\t%s" % (common_a.index(key), key))
            for key in common_b[b1:b2] if op != "equal" else ():
                out("\t+order\t%d\t%s" % (common_b.index(key), key))
        found += 1
    if ya != yb:
        only_a, only_b = list(ya), list(yb)
        for item in ya:
            if item in only_b:
                only_b.remove(item)
                only_a.remove(item)
        for item in only_a:
            out("SYMBOL-ONLY-A\t%s" % describe(item))
        for item in only_b:
            out("SYMBOL-ONLY-B\t%s" % describe(item))
        if not only_a and not only_b:
            out("SYMBOL-ORDER\tthe same symbols in a different order")
        found += 1
    return found


def read_renames(pairs, path):
    lines = list(pairs)
    if path is not None:
        with open(path, encoding="utf-8-sig") as f:
            lines += [line.strip() for line in f]
    renames = {}
    for line in lines:
        if not line or line.startswith("#"):
            continue
        old, sep, new = line.partition("=")
        if not sep or not old or not new:
            raise ValueError("a rename is OLD=NEW, not %r" % line)
        renames[old] = new
    return renames


def main(argv):
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(errors="backslashreplace")
    args = list(argv)
    map_path = None
    if "--map" in args:
        at = args.index("--map")
        map_path = args[at + 1] if at + 1 < len(args) else None
        args = args[:at] + args[at + 2:]
        if map_path is None:
            args = []
    if len(args) < 2 or any(a.startswith("-") for a in args[:2]):
        print(__doc__.strip().split("\n\n")[1], file=sys.stderr)
        return 2
    path_a, path_b = args[:2]
    try:
        renames = read_renames(args[2:], map_path)
        with open(path_a, "rb") as f:
            data_a = f.read()
        with open(path_b, "rb") as f:
            data_b = f.read()
        coff_a = Coff(data_a, renames)
        coff_b = Coff(data_b, {})
    except (OSError, ValueError, Unreadable) as error:
        print("objcmp.py: %s" % error, file=sys.stderr)
        return 2
    notes = ["NOTE\trename %s is not a symbol of A" % old for old in sorted(renames)
             if not spelled(old, coff_a.names)]
    lines = []
    refused = 0
    for old, new in sorted(renames.items()):
        for label, coff in (("A", coff_a), ("B", coff_b)):
            if spelled(old, coff.names) and spelled(new, coff.names):
                lines.append("RENAME-MERGES\t%s holds both %s and %s" % (label, old, new))
                refused += 1
        if spelled(old, coff_b.names):
            lines.append("RENAME-KEPT\tB still holds %s" % old)
            refused += 1
    applied = any(spelled(old, coff_a.names) for old in renames)
    if masked(data_a) == masked(data_b):
        verdict, status = "identical: the bytes are equal with the timestamp masked", 0
        lines = []
    else:
        found = refused + compare(coff_a, coff_b, lines.append)
        if found == 0 and applied:
            verdict, status = "identical: equal with the timestamp masked once the renames are applied", 0
        elif found == 0:
            verdict, status = "differs: the bytes differ, but no section, relocation or symbol does", 1
        else:
            verdict, status = "differs: %d difference(s)" % found, 1
    for line in [verdict] + notes + lines:
        print(line)
    return status


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
