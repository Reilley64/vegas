#!/usr/bin/env python3
"""Compare two COFF objects with the header timestamp masked.

usage: objcmp.py A.obj B.obj [--map FILE] [--expect-kept FILE] [--base-holds-new] [--json] [OLD=NEW ...]

A is the base object, B the head object. Each OLD=NEW pair (from the command
line, or one per line of FILE) is a respelling of the base: a symbol of A
named OLD, and a name of A that embeds a C++ OLD name, is compared as spelled
with NEW. B is compared as it is. The objects are identical when their bytes
are equal with the timestamp masked, or, when a rename applies to A, when the
header, every section (bytes, relocations by target name) and the symbol
table are equal once respelled. A rename is refused as a difference when an
object holds both spellings (RENAME-MERGES) or B still holds OLD
(RENAME-KEPT); when A holds both, the comparison is refused and prints only
the RENAME- lines. Otherwise it prints the sections, relocations and symbols
that differ, with one SYMBOL-SHIFT line per section and distance for the
symbols that only moved. A summary follows: each relocation target that
changed at one offset (RETARGET) and each site where B still targets a
rename's OLD (KEPT-SITE). With --expect-kept FILE (one FUNCTION OLD per
line), a comparison whose only differences are exactly those kept sites
and the undefined-symbol and address-significance entries of their OLD
names is "kept" and exits 0; any other difference, or a kept site missing
or not listed, exits 1, and what differs beside the listed sites prints as
BESIDE-KEPT lines. A FILE with no site acts as no option. With
--base-holds-new, a rename whose NEW A already holds as a symbol is a
merge: A's OLD must be one undefined external symbol that some relocation
targets, B must hold no OLD, and B must equal A once OLD is respelled NEW
and its symbol and address-significance entries merge into NEW's; that is
"merged" and exits 0. --json prints the same facts as one JSON object,
with the per-symbol lines.

Exit status: 0 identical, kept or merged, 1 differs or refused, 2 usage
error or unreadable input.
"""
import difflib
import json
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
            if name == ".llvm_addrsig":
                uleb128s(body)  # a padded or truncated index makes the object unreadable
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
    """The address-significance indices, each a ULEB128 number as LLVM
    writes it: no padding byte, none cut short."""
    out, value, shift = [], 0, 0
    for byte in data:
        if shift and byte == 0:
            raise ValueError("a padded address-significance index")
        value |= (byte & 0x7F) << shift
        shift += 7
        if not byte & 0x80:
            out.append(value)
            value, shift = 0, 0
    if shift:
        raise ValueError("a truncated address-significance index")
    return out


def alignment(characteristics):
    """The alignment that a section's characteristics give, in bytes."""
    bits = (characteristics >> 20) & 0xF
    return 1 << (bits - 1) if bits else "default"


def describe(item):
    return "\t".join(str(x) for x in item[:5])


def compare(a, b, out, shifts=False):
    """Prints the differences of two objects as Coff.compared() gives them;
    returns their count. With shifts, a SYMBOL-SHIFT line per section and
    distance replaces the SYMBOL-ONLY lines of the symbols that only moved."""
    ha, sa, oa, ya = a
    hb, sb, ob, yb = b
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
        parts, equal = [], []
        for field in ("name", "characteristics", "selection"):
            if x[field] != y[field]:
                parts.append("%s %s -> %s" % (field, x[field], y[field]))
                if field == "characteristics":
                    parts[-1] += " (0x%08x -> 0x%08x)" % (x[field], y[field])
                    if alignment(x[field]) != alignment(y[field]):
                        parts.append("alignment %s -> %s" % (alignment(x[field]), alignment(y[field])))
            elif field != "name":
                equal.append("%s %s" % (field, x[field]))
        if x["body"] != y["body"]:
            if isinstance(x["body"], tuple):
                parts.append("address-significance names differ, %d -> %d" % (len(x["body"]), len(y["body"])))
            else:
                differing = [i for i in range(min(len(x["body"]), len(y["body"]))) if x["body"][i] != y["body"][i]]
                where = (", first at 0x%x" % differing[0]) if differing else ""
                parts.append("size %d -> %d, %d bytes differ%s" % (x["size"], y["size"], len(differing), where))
        else:
            equal.append("names" if isinstance(x["body"], tuple) else "bytes")
        if x["size"] == y["size"] is not None:
            equal.append("size %s" % x["size"])
        elif x["body"] == y["body"]:
            parts.append("size %d -> %d" % (x["size"], y["size"]))
        if x["relocations"] != y["relocations"]:
            parts.append("relocations %d -> %d" % (len(x["relocations"]), len(y["relocations"])))
        else:
            equal.append("relocations %d" % len(x["relocations"]))
        out("SECTION-DIFFERS\t%s\t%s\t%s\tequal: %s"
            % (key, x["name"], "; ".join(parts), ", ".join(equal) or "nothing"))
        if x["relocations"] != y["relocations"]:
            rx, ry = set(x["relocations"]), set(y["relocations"])
            for va, typ, target in sorted(rx - ry):
                out("\t-reloc\t0x%x\ttype %d\t%s" % (va, typ, target))
            for va, typ, target in sorted(ry - rx):
                out("\t+reloc\t0x%x\ttype %d\t%s" % (va, typ, target))
        if isinstance(x["body"], tuple) and x["body"] != y["body"]:
            # Every name that is added, removed or moved, by position in the table.
            matcher = difflib.SequenceMatcher(None, x["body"], y["body"], autojunk=False)
            for op, a1, a2, b1, b2 in matcher.get_opcodes():
                for at in range(a1, a2) if op != "equal" else ():
                    out("\t-addrsig\t%d\t%s" % (at, x["body"][at]))
                for at in range(b1, b2) if op != "equal" else ():
                    out("\t+addrsig\t%d\t%s" % (at, y["body"][at]))
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
        if not only_a and not only_b:
            out("SYMBOL-ORDER\tthe same symbols in a different order")
        moved = {}
        for item in list(only_a) if shifts else ():
            # The same symbol at another value of the same section.
            match = [other for other in only_b if other[0] == item[0] and other[2:] == item[2:]]
            if match and not item[2].startswith("("):
                moved.setdefault((item[2], match[0][1] - item[1]), []).append((item[1], item[0]))
                only_a.remove(item)
                only_b.remove(match[0])
        for (key, delta), group in moved.items():
            out("SYMBOL-SHIFT\t%s\t%d symbol(s)\tby %+#x\tfrom %s at 0x%x"
                % (key, len(group), delta, min(group)[1], min(group)[0]))
        for item in only_a:
            out("SYMBOL-ONLY-A\t%s" % describe(item))
        for item in only_b:
            out("SYMBOL-ONLY-B\t%s" % describe(item))
        found += 1
    return found


def sites(raw_a, coff_a, coff_b, renames):
    """Pairs the relocations of each section both objects hold by offset and
    type. Returns the retargets, {(A's target as A spells it, B's target):
    [count, section keys, whether the renames explain it]}, and the kept
    sites, [(section key, offset, type, OLD)] where A's OLD is respelled NEW
    and B still targets OLD."""
    retargets, kept = {}, []
    numbers_b = {key: number for number, key in enumerate(coff_b.keys, 1)}
    for number, key in enumerate(coff_a.keys, 1):
        if key not in numbers_b:
            continue
        targets = {}
        for va, index, typ in raw_a.sections[number - 1]["relocations"]:
            targets.setdefault((va, typ), []).append((raw_a.target(index), coff_a.target(index)))
        for va, index, typ in coff_b.sections[numbers_b[key] - 1]["relocations"]:
            if not targets.get((va, typ)):
                continue
            raw, respelled = targets[(va, typ)].pop(0)
            target = coff_b.target(index)
            if raw != target:
                entry = retargets.setdefault((raw, target), [0, [], respelled == target])
                entry[0] += 1
                if key not in entry[1]:
                    entry[1].append(key)
            elif raw in renames and respelled == renames[raw]:
                kept.append((key, va, typ, raw))
    return retargets, kept


def only_kept(a, b, kept, renames, shifts):
    """The BESIDE-KEPT lines of what still differs once B's kept sites are
    respelled as the renames say: each kept relocation targets NEW again,
    and OLD's undefined symbol and address-significance entries are dropped
    (when B also holds NEW, with OLD's symbol type and as many entries as A
    marks) or respelled NEW. No line means B equals A but for the kept sites.
    The address-significance table's byte size is not compared: B's holds
    other indices."""
    header, sections, order, symbols = b
    sections = {key: dict(s) for key, s in sections.items()}
    beside = []
    for key, va, typ, old in kept:
        relocations = list(sections[key]["relocations"])
        relocations[relocations.index((va, typ, old))] = (va, typ, renames[old])
        sections[key]["relocations"] = tuple(relocations)
    symbols = list(symbols)
    for old in sorted({site[3] for site in kept}):
        new = renames[old]
        at = [i for i, symbol in enumerate(symbols) if symbol[0] == old]
        if len(at) != 1 or symbols[at[0]][1:3] != (0, "(undefined)") or symbols[at[0]][4:] != (EXTERNAL, b""):
            continue
        holds_new = any(symbol[0] == new for symbol in symbols)
        if holds_new and symbols[at[0]][3] not in {symbol[3] for symbol in symbols if symbol[0] == new}:
            continue
        if holds_new:
            del symbols[at[0]]
        else:
            symbols[at[0]] = (new,) + symbols[at[0]][1:]
        for key, s in sections.items():
            if s["name"] == ".llvm_addrsig":
                marked = a[1][key]["body"].count(new) if a[1].get(key, {}).get("name") == ".llvm_addrsig" else 0
                if holds_new and s["body"].count(old) != marked:
                    beside.append("BESIDE-KEPT\tB marks %s address-significant %d time(s), A %d"
                                  % (old, s["body"].count(old), marked))
                s["body"] = tuple(n for n in s["body"] if n != old) if holds_new else \
                    tuple(new if n == old else n for n in s["body"])
    names = {symbol[0] for symbol in symbols}
    beside += ["BESIDE-KEPT\tB still holds %s in a name that is not a kept site's" % old
               for old in sorted(renames) if spelled(old, names)]

    def sized(c):
        return c[0], {k: dict(s, size=None) if s["name"] == ".llvm_addrsig" else s for k, s in c[1].items()}, c[2], c[3]
    compare(sized(a), sized((header, sections, order, symbols)), lambda line: beside.append("BESIDE-KEPT\t" + line),
            shifts)
    return beside


def merge_checks(raw_a, merges):
    """The MERGE- lines of the merges (OLD: NEW, A holding NEW): A's OLD must be
    one undefined external symbol, embedded in no other name, that at least
    one relocation targets; A's NEW one external symbol. Returns the lines,
    {OLD: "definition" or "reference"} by what A's NEW is, and {OLD: the
    number of A's relocations to OLD}."""
    lines, into, calls = [], {}, {}
    for old, new in sorted(merges.items()):
        olds = [s for s in raw_a.symbols if s[1] == old]
        if spelled(old, raw_a.names) != [old] or len(olds) != 1 or olds[0][2:4] != (0, 0) \
                or olds[0][5:] != (EXTERNAL, b""):
            lines.append("MERGE-OLD\tA holds %s other than as one undefined external symbol" % old)
        news = [s for s in raw_a.symbols if s[1] == new]
        if len(news) != 1 or news[0][5] != EXTERNAL:
            lines.append("MERGE-NEW\tA holds %s other than as one external symbol" % new)
        else:
            into[old] = "reference" if news[0][3] == 0 else "definition"
        calls[old] = sum(1 for s in raw_a.sections for _, index, _ in s["relocations"]
                         if raw_a.by_index.get(index, (None, None))[1] == old)
        if not calls[old]:
            lines.append("MERGE-NO-CALL\tno relocation of A targets %s" % old)
    return lines, into, calls


def merged_sequence(seq_a, seq_b, news, name, entry=None, anywhere=False):
    """seq_a as B may show it once the entries of each name in NEWS merge: seq_b
    when B keeps every other entry in A's order and, of each NEW that seq_a
    holds, exactly one entry (equal to entry[NEW] when ENTRY is given) at the
    place of one of seq_a's entries of it, or anywhere with ANYWHERE; else
    seq_a with each NEW's first entry kept (with ENTRY, A's own NEW entry), so
    that compare() shows the difference. NAME gives an entry's name."""
    def rest(seq):
        return [x for x in seq if name(x) not in news]

    def slot(seq, at):
        return sum(1 for x in seq[:at] if name(x) not in news)
    ok = rest(seq_a) == rest(seq_b)
    for new in news:
        in_a = [i for i, x in enumerate(seq_a) if name(x) == new]
        in_b = [i for i, x in enumerate(seq_b) if name(x) == new]
        if len(in_b) != min(1, len(in_a)) or (in_b and entry is not None and seq_b[in_b[0]] != entry[new]):
            ok = False
        elif in_b and not anywhere and slot(seq_b, in_b[0]) not in {slot(seq_a, i) for i in in_a}:
            ok = False
    if ok:
        return list(seq_b)
    out, seen = [], set()
    for x in seq_a:
        if name(x) in news:
            if name(x) in seen:
                continue
            seen.add(name(x))
            x = entry[name(x)] if entry is not None else x
        out.append(x)
    return out


def merge_view(a, b, raw_a, merges):
    """A's comparison (the renames applied, so that each merged OLD is spelled
    NEW) with the merges done as B shows them, when B shows them as allowed,
    and both address-significance tables' byte sizes left out (their indices
    differ once a symbol goes). B's one symbol of NEW stands at the place of
    A's OLD or NEW; its one address-significance entry anywhere, as the table
    lists symbols in symbol-table order and is a set to the linker."""
    news = set(merges.values())
    header, sections, order, symbols = a
    entry = {s[1]: symbols[i] for i, s in enumerate(raw_a.symbols) if s[1] in news}
    if set(entry) != news:
        return a, b  # MERGE-NEW names it
    symbols = merged_sequence(symbols, b[3], news, lambda s: s[0], entry)
    sections, sections_b = dict(sections), dict(b[1])
    for key, s in sections.items():
        if s["name"] == ".llvm_addrsig":
            body_b = sections_b[key]["body"] if sections_b.get(key, {}).get("name") == ".llvm_addrsig" else ()
            sections[key] = dict(s, size=None, body=tuple(merged_sequence(s["body"], body_b, news, lambda n: n,
                                                                           anywhere=True)))
    for key, s in sections_b.items():
        if s["name"] == ".llvm_addrsig":
            sections_b[key] = dict(s, size=None)
    return (header, sections, order, symbols), (b[0], sections_b, b[2], b[3])


def read_lines(path):
    with open(path, encoding="utf-8-sig") as f:
        return [line.strip() for line in f]


def read_kept(path, renames):
    """The expected kept sites: one FUNCTION OLD per line, # comments. A
    line of two fields whose second is a rename's OLD is a site even when it
    starts with #, as a section key such as #.rdata/1 does."""
    kept = []
    for line in read_lines(path):
        fields = line.split()
        if len(fields) == 2 and fields[1] in renames:
            kept.append(tuple(fields))
        elif line and not line.startswith("#"):
            raise ValueError("an expected kept site is FUNCTION OLD, OLD a rename's, not %r" % line)
    return kept


def read_renames(pairs, path):
    lines = list(pairs)
    if path is not None:
        lines += read_lines(path)
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
    as_json = "--json" in args
    base_holds_new = "--base-holds-new" in args
    args = [a for a in args if a not in ("--json", "--base-holds-new")]
    paths = {}
    for option in ("--map", "--expect-kept"):
        if option in args:
            at = args.index(option)
            paths[option] = args[at + 1] if at + 1 < len(args) else None
            args = args[:at] + args[at + 2:]
            if paths[option] is None:
                args = []
    if len(args) < 2 or any(a.startswith("-") for a in args[:2]):
        print(__doc__.strip().split("\n\n")[1], file=sys.stderr)
        return 2
    if base_holds_new and "--expect-kept" in paths:
        print("objcmp.py: --expect-kept does not combine with --base-holds-new", file=sys.stderr)
        return 2
    path_a, path_b = args[:2]
    try:
        renames = read_renames(args[2:], paths.get("--map"))
        expected = read_kept(paths["--expect-kept"], renames) if "--expect-kept" in paths else None
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
    # With --base-holds-new, a rename whose NEW is a symbol of A merges OLD into it.
    merges = {old: new for old, new in renames.items() if base_holds_new and new in coff_a.names}
    lines = []
    refused = 0
    merged = False
    for old, new in sorted(renames.items()):
        for label, coff in (("A", coff_a), ("B", coff_b)):
            if label == "A" and old in merges:
                continue
            if spelled(old, coff.names) and spelled(new, coff.names):
                lines.append("RENAME-MERGES\t%s holds both %s and %s" % (label, old, new))
                refused += 1
                merged = merged or label == "A"
        if spelled(old, coff_b.names):
            lines.append("RENAME-KEPT\tB still holds %s" % old)
            refused += 1
    applied = any(spelled(old, coff_a.names) for old in renames)
    found, retargets, kept, into, calls = 0, {}, [], {}, {}
    if masked(data_a) == masked(data_b):
        verdict, status = "identical: the bytes are equal with the timestamp masked", 0
        lines = []
        if expected:
            # A listed site that the head keeps is not missing.
            kept = sites(Coff(data_a, {}), coff_a, coff_b, renames)[1]
    elif merged:
        # Respelled, A would hold one name twice: every line after it would be an artefact.
        verdict, status = ("refused: A holds both spellings of a rename; compare without that rename, or with "
                           "the commit before A as the base"), 1
        found = None
    elif merges:
        raw_a = Coff(data_a, {})
        merge_problems, into, calls = merge_checks(raw_a, merges)
        lines += merge_problems
        view_a, view_b = merge_view(coff_a.compared(), coff_b.compared(), raw_a, merges)
        found = compare(view_a, view_b, lines.append, shifts=not as_json) + len(merge_problems)
        retargets, kept = sites(raw_a, coff_a, coff_b, renames)
        if found == 0 and refused == 0:
            own = sum(1 for old in merges if into.get(old) == "definition")
            verdict, status = ("merged: equal with the timestamp masked once the renames are applied, %d OLD "
                               "name(s) merged into the NEW that the base holds: %d into its own definition, %d "
                               "into its existing reference" % (len(merges), own, len(merges) - own)), 0
        else:
            verdict = "differs: %d difference(s)%s" % (found, ", %d RENAME- line(s)" % refused if refused else "")
            status = 1
    else:
        found = compare(coff_a.compared(), coff_b.compared(), lines.append, shifts=not as_json)
        retargets, kept = sites(Coff(data_a, {}) if renames else coff_a, coff_a, coff_b, renames)
        beside = None
        if expected and sorted((key, old) for key, _, _, old in kept) == sorted(expected):
            beside = only_kept(coff_a.compared(), coff_b.compared(), kept, renames, not as_json)
            lines += beside
        if found == 0 and refused == 0 and applied:
            verdict, status = "identical: equal with the timestamp masked once the renames are applied", 0
        elif beside == []:
            verdict, status = ("kept: equal with the timestamp masked once the renames are applied, except the %d "
                               "expected kept site(s)" % len(kept)), 0
        elif found == 0 and refused == 0:
            verdict, status = "differs: the bytes differ, but no section, relocation or symbol does", 1
        else:
            verdict = "differs: %d difference(s)%s" % (found, ", %d RENAME- line(s)" % refused if refused else "")
            status = 1
    missing, unexpected = [] if found is None else list(expected or ()), []
    for site in kept if expected else ():  # a list with no site acts as no option
        # Each expected (FUNCTION, OLD) takes one kept site; the rest are mismatches.
        if (site[0], site[3]) in missing:
            missing.remove((site[0], site[3]))
        else:
            unexpected.append(site)
    if missing or unexpected:
        verdict = verdict if status else "differs: %d difference(s)" % found
        verdict, status = verdict + ", %d kept-site mismatch(es)" % (len(missing) + len(unexpected)), 1
    retargets = sorted((old, new, count, by_map, keys) for (old, new), (count, keys, by_map) in retargets.items())
    merge_rows = [(old, merges[old], into[old], calls[old]) for old in sorted(merges)
                  if status == 0 and verdict.startswith("merged")]
    if as_json:
        report = dict(
            verdict=verdict, result=verdict.split(":")[0], exit=status, differences=found, rename_lines=refused,
            notes=notes, lines=lines,
            retargets=[dict(old=old, new=new, count=count, by_map=by_map, functions=keys)
                       for old, new, count, by_map, keys in retargets],
            kept_sites=[dict(function=key, offset=va, old=old, new=renames[old]) for key, va, _, old in kept],
            kept_missing=[dict(function=key, old=old) for key, old in missing],
            kept_unexpected=[dict(function=key, offset=va, old=old) for key, va, _, old in unexpected])
        if base_holds_new:
            report["merges"] = [dict(old=old, new=new, into=where, relocations=count)
                                for old, new, where, count in merge_rows]
        print(json.dumps(report, indent=1, sort_keys=True))
        return status
    summary = ["RETARGET\t%s -> %s\t%d site(s)\t%s\t%s"
               % (old, new, count, "by the map" if by_map else "not by the map", " ".join(keys))
               for old, new, count, by_map, keys in retargets]
    summary += ["KEPT-SITE\t%s\t0x%x\t%s\t%s" % (key, va, old, renames[old]) for key, va, _, old in kept]
    summary += ["KEPT-MISSING\t%s\t%s" % site for site in missing]
    summary += ["KEPT-UNEXPECTED\t%s\t0x%x\t%s" % (key, va, old) for key, va, _, old in unexpected]
    summary += ["MERGED\t%s -> %s\tinto the base's %s\t%d relocation(s)"
                % (old, new, "own definition" if where == "definition" else "existing reference", count)
                for old, new, where, count in merge_rows]
    for line in [verdict] + notes + lines + summary:
        print(line)
    return status


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
