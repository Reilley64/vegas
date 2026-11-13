# Object proof

Tools for showing that a change leaves the compiled objects as they were, or
exactly how it changes them. Python 3, standard library only.

- `objcmp.py` compares two COFF objects with the header timestamp masked.
- `proof.py` compiles one unit three ways in a configured build and compares
  the base's and the head's objects and warnings.

## The proof of one unit

The export path enters the objects (anonymous-namespace hashes, `__FILE__`),
so build base and head from one export path. When the change touches only
the unit's own file, compile both from one export with `--source`:

```sh
T=tools/object-proof
git show BASE:src/fallout/misc/main.cpp > OUT/base.cpp
git show HEAD:src/fallout/misc/main.cpp > OUT/head.cpp
python3 $T/proof.py compile --target game --source OUT/base.cpp BUILD src/fallout/misc/main.cpp OUT/base
python3 $T/proof.py compile --target game --source OUT/head.cpp BUILD src/fallout/misc/main.cpp OUT/head
python3 $T/proof.py compare OUT/base OUT/head [--map renames.txt] [--expect-kept kept.txt] [OLD=NEW ...]
```

When the change touches a header or a CMake file, bring the export to each
commit instead and compile without `--source`; configure again before the
head compile if a CMake file changed (the command is read from
compile_commands.json at compile time).

- `compile` runs the unit's command from `BUILD/compile_commands.json` as it
  is (`flags`), with `/Ob0` (`ob0`) and with `/Od /Gy` (`od`), and writes
  `OUT/base.VARIANT.obj` and `.log`. The extra flags go last before `--`, so
  they override the unit's own. `--target` picks the entry of
  `CMakeFiles/NAME.dir` when a source builds in several targets. It parses
  the POSIX-quoted commands of the cross build; on a Windows host it reads
  only an `arguments` array and refuses a `command` string (exit 2). A
  compiler that cannot start exits 2. It first removes the three objects of
  an earlier run.
- `--source FILE` compiles FILE's content at the unit's path: it writes
  `OUT/base.vfs.json`, a clang `-vfsoverlay` file that maps the unit's path
  to FILE with the unit's own name kept, and passes it to every variant. The
  export is never written, so a failed compile cannot leave it dirty.
  Headers still come from the export. It exits 2 with one line, and
  compiles nothing, when FILE is not a file, when the compiler is not
  clang (`clang`, `clang-cl` or `clang++`, maybe with a version), or when
  the command does not name the unit exactly as the entry's `file` spells
  it (a symlink against its real path, a relative path against an absolute
  one). Before the variants it runs a canary: the `flags` command with the
  unit mapped to `OUT/base.canary.cpp`, one `#error` line. Unless that
  compile fails with that error (`OUT/base.canary.log`), the overlay does
  not reach the compiler, and it exits 2.
- Every compile writes `OUT/base.commands.json`: the compile_commands.json
  `entry`, the `source` override, `overlay` and `canary` command (or null),
  and per variant the full command (`commands`). The commands run in the
  entry's `directory`. The `.commands.json`, `.vfs.json` and canary files
  hold absolute paths of the machine: keep OUT outside the checkout and
  never commit them.
- `compare` prints, per variant, `objcmp.py`'s report and the warnings
  comparison. It passes `--map`, `--expect-kept` and renames on; for JSON,
  run `objcmp.py --json` per variant.

## Comparing objects

```sh
python3 tools/object-proof/objcmp.py BASE.obj HEAD.obj [--map FILE] [--expect-kept FILE] [--json] [OLD=NEW ...]
```

The first line is the verdict:

| Verdict | Exit | Meaning |
| --- | --- | --- |
| `identical: the bytes are equal ...` | 0 | equal bytes, whatever the map says |
| `identical: ... once the renames are applied` | 0 | equal structure with a rename applied to the base |
| `kept: ... except the N expected kept site(s)` | 0 | equal except exactly the `--expect-kept` sites |
| `refused: A holds both spellings of a rename ...` | 1 | nothing compared; the RENAME- lines follow |
| `differs: N difference(s)[, M RENAME- line(s)][, K kept-site mismatch(es)]` | 1 | N counts the difference lines below, not the RENAME- lines |
| `differs: the bytes differ, but no section ...` | 1 | no rename applies and the structure is equal |

The lines after it name what differs, keyed by the symbol that leads each
section (a COMDAT function's own name; `#name/N` for other sections; an
associative section as `parent|name`). Then the summary.

| Line | Meaning |
| --- | --- |
| `RENAME-MERGES`, `RENAME-KEPT` | an object holds both spellings of a rename; B still holds a rename's OLD |
| `NOTE` | a rename whose OLD name the base does not have |
| `HEADER` | machine, flags or the bigobj format differ |
| `SECTION-ONLY-A`, `SECTION-ONLY-B` | a section only one object has |
| `SECTION-DIFFERS` | what differs (bytes, size, flags, COMDAT selection, relocations), then `equal:` what does not; changed characteristics also in hexadecimal, then `alignment A -> B` in bytes when it changed; `-reloc`/`+reloc` give offset, type and target |
| `-addrsig`, `+addrsig` | under a differing `.llvm_addrsig`: each name removed, added or moved, with its position in the table |
| `SECTION-ORDER` | the shared sections are in another order; `-order`/`+order` give the moved ones |
| `SYMBOL-ONLY-A`, `SYMBOL-ONLY-B` | name, value, section, type, storage class |
| `SYMBOL-SHIFT` | section, count, distance: symbols that differ only by value, by that distance, in that section, in place of their `SYMBOL-ONLY` lines (as when an array before them grew) |
| `BESIDE-KEPT` | under `--expect-kept`, when the kept sites are the listed ones: what still differs once they are undone (a difference line, `B still holds OLD`, or OLD's address-significance count) |
| `RETARGET` | summary: A's target as A spells it `->` B's target at one offset of a section both hold, count, `by the map` or `not by the map`, the sections |
| `KEPT-SITE` | summary: section, offset, OLD, NEW of a relocation where B still targets OLD and the respelled A targets NEW |
| `KEPT-MISSING`, `KEPT-UNEXPECTED` | an expected kept site (section, OLD) not found; a kept site (section, offset, OLD) not expected |

A refused comparison prints no summary. For the instructions of a differing
function, disassemble it in both objects with
`llvm-objdump -d -r --disassemble-symbols=NAME`.

### Renames

A rename `OLD=NEW` (mangled names; in `--map FILE` one per line, `#`
comments) is a respelling of the base: the base's `OLD` compares as `NEW`,
and a C++ name embedded in another of its names too, such as a renamed
function's `$cppxdata$` or static locals. The head is compared as it is.
When a rename applies to the base, equal structure counts as identical;
otherwise only equal bytes do. The `RENAME-` lines print only when the bytes
differ.

A base that already holds NEW as well as OLD, as when a second commit is
compared to a first with the first's map, is refused: respelled, it would
hold one name twice. Compare it without that rename, where the moved calls
show as `RETARGET ... not by the map`, or compare the second commit to the
commit before the first.

### Kept sites

A unit whose head keeps some calls of `OLD` (a mixed unit) differs with
`RENAME-KEPT`, and with `RENAME-MERGES` for B when it holds both spellings.
Each kept site shows as a `-reloc` to `NEW` and a `+reloc` to `OLD` at one
offset, and as a `KEPT-SITE` line. To prove such a unit, list the expected
sites in a file, one `FUNCTION OLD` per line, one line per site, and pass
it with `--expect-kept`. FUNCTION is the section key that the `KEPT-SITE`
line shows: a COMDAT function's own name, or `#name/N` or `parent|name`
for a section no symbol leads, such as a table in `.rdata`. A line of two
fields whose second is a rename's OLD is a site even when it starts with
`#`; other lines that start with `#` are comments. The verdict is `kept`
and the exit 0 only when:

- the kept sites found are exactly the listed ones (a missing, extra or
  other-function site is a `KEPT-MISSING` or `KEPT-UNEXPECTED` line);
- the head, with each kept relocation respelled `NEW`, equals the respelled
  base once each `OLD` that has a kept site is undone: an undefined external
  symbol of value 0 is dropped with its address-significance entries when
  the head also holds `NEW` (then of `NEW`'s symbol type, and marked
  address-significant as often as the base marks it), or respelled `NEW`
  when it does not;
- that head holds `OLD` in no other name.

Any other difference exits 1 and, when the kept sites are the listed ones,
also prints as a `BESIDE-KEPT` line. An expected site whose OLD is not a
rename, or another line that is not two fields, is a usage error (exit 2).
The difference lines print as without the option. A list with no site
expects none and acts exactly as no option: any kept site then differs
through `RENAME-KEPT`. Byte-identical objects still look for kept sites
when the list names some, so a listed site they keep is no
`KEPT-MISSING`.

What `--expect-kept` does not check:

- which of several kept sites of one OLD in one function is kept: sites
  match by FUNCTION and OLD, not offset. Read the offsets of the `KEPT-SITE`
  lines; a batch tool records `kept_sites[].offset` per variant.
- where the head's OLD symbol stands in its symbol table: it is dropped
  before the comparison.
- a kept call before the first moved call: clang orders undefined symbols
  by first use, so the head holds `NEW` after OLD's place, the symbol order
  differs (`BESIDE-KEPT\tSYMBOL-ORDER`) and the unit differs (exit 1). The
  order is not relaxed; prove such a unit from the `KEPT-SITE` lines.

### JSON

`--json` prints one JSON object in place of the text, with these keys:
`verdict` (the first line), `result` (`identical`, `kept`, `refused` or
`differs`), `exit`, `differences` (N; null when refused), `rename_lines`
(M), `notes`, `lines` (the RENAME-, difference and BESIDE-KEPT lines as
printed, but with every `SYMBOL-ONLY` line in place of the `SYMBOL-SHIFT`
lines), `retargets`
(`old`, `new`, `count`, `by_map`, `functions`), `kept_sites` (`function`,
`offset`, `old`, `new`), `kept_missing` (`function`, `old`) and
`kept_unexpected` (`function`, `offset`, `old`). Usage errors and
unreadable input print to stderr and exit 2, with no JSON.

## Comparing warnings

```sh
python3 tools/object-proof/proof.py warnings [--strip PREFIX ...] A.log B.log
```

Any compiler or ninja log. It keeps the lines with `warning:`, turns `\` into
`/`, removes each `PREFIX` (such as two export roots) and the `(line,col)` or
`:line:col` position, and compares them as counted lines. A difference lists
the classes whose counts changed and the lines only in A (`-`) or B (`+`).

## Exit status

All three commands: 0 identical, kept (or compiled), 1 differs, refused (or
a compile failed), 2 usage error, unreadable input, a compiler that cannot
start or a `--source` that compile refuses.

## Blind spots

- A rename is refused as a difference when an object holds both spellings
  (RENAME-MERGES) or the head still holds OLD (RENAME-KEPT). An unmatched
  rename does not relax the comparison.
- With a rename that applies, these are not compared: the string-table
  layout and any bytes after it; where the section bytes sit in the file;
  the section headers' virtual size, virtual address and line-number
  fields; and the COMDAT record's checksum (the bytes it sums are compared).
- Exit 0 does not mean a rename took place: equal bytes exit 0 whatever the
  map says. Only the verdict line that says the renames were applied means
  structural equality under an applied rename.
- `RENAME-MERGES` and `RENAME-KEPT` match a C++ name anywhere inside another
  name, so a base that already holds NEW, a chain (`a=b`, `b=c`) or a NEW that
  embeds OLD always differs. A name that does not start with `?` is respelled
  and checked only as a whole symbol. Of two map lines for one OLD the last
  wins. Two statics of one name at one address are one target.
- Bytes are compared raw, except `.llvm_addrsig`, which is compared as the
  names it indexes; an index with a padding byte or cut short makes the
  object unreadable (exit 2). A name inside section bytes, such as CodeView in
  `.debug$S` or a `.drectve` directive, is not respelled and shows as a
  difference.
- `RETARGET` and `KEPT-SITE` pair relocations by offset and type inside the
  sections both objects hold; a section only one object has is not paired. A
  kept site is a relocation to the whole name OLD. `--expect-kept` matches
  sites by section and OLD, not offset, and does not compare the
  address-significance table's byte size (the head's holds other indices).
- `SYMBOL-SHIFT` pairs a symbol of A with one of B of the same name,
  section, type and storage class; a static of one name in two places may
  pair with the other. The relocations to statics that moved still print
  one `-reloc`/`+reloc` pair each.
- One object at a time: which COMDAT copy a link selects, and inlined copies
  in other units, are not seen.
- The warnings comparison ignores notes, errors and cl.exe-style lines
  (`warning C4996:`), and a warning that only moved lines compares equal.
- One export path for base and head is the caller's duty; the tools do not
  verify it. `--source` needs clang's `-vfsoverlay` and overlays only the
  unit's own file; the canary shows that the overlay reaches the `flags`
  command, and the variants differ from it only by their extra flags.
- The tests (`tools.object_proof.*`, `test_object_proof.py`) use small
  hand-made objects and a fake compiler named `clang-cl` (a `.cmd` file on
  Windows), not compiler output. They read the tools' output with `\r\n` as
  `\n`.
