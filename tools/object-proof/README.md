# Object proof

Tools for showing that a change leaves the compiled objects as they were, or
exactly how it changes them. Python 3, standard library only.

- `objcmp.py` compares two COFF objects with the header timestamp masked.
- `proof.py` compiles one unit three ways in a configured build and compares
  the base's and the head's objects and warnings.

## The proof of one unit

The export path enters the objects (anonymous-namespace hashes, `__FILE__`),
so build base and head from one export path: bring the same export to the
base, compile, bring it to the head, compile. If the head changes a CMake
file, configure again before the head compile: the command is read from
compile_commands.json at compile time.

```sh
T=tools/object-proof
python3 $T/proof.py compile --target game BUILD src/fallout/misc/main.cpp OUT/base   # export at the base
python3 $T/proof.py compile --target game BUILD src/fallout/misc/main.cpp OUT/head   # same export at the head
python3 $T/proof.py compare OUT/base OUT/head [--map renames.txt] [OLD=NEW ...]
```

- `compile` runs the unit's command from `BUILD/compile_commands.json` as it
  is (`flags`), with `/Ob0` (`ob0`) and with `/Od /Gy` (`od`), and writes
  `OUT/base.VARIANT.obj` and `.log`. The extra flags go last before `--`, so
  they override the unit's own. `--target` picks the entry of
  `CMakeFiles/NAME.dir` when a source builds in several targets. It parses
  the POSIX-quoted commands of the cross build; on a Windows host it reads
  only an `arguments` array and refuses a `command` string (exit 2). A
  compiler that cannot start exits 2.
- `compare` prints, per variant, `objcmp.py`'s report and the warnings
  comparison.

## Comparing objects

```sh
python3 tools/object-proof/objcmp.py BASE.obj HEAD.obj [--map FILE] [OLD=NEW ...]
```

The first line is the verdict: `identical: ...` or `differs: N difference(s)`.
The lines after it name what differs, keyed by the symbol that leads each
section (a COMDAT function's own name; `#name/N` for other sections; an
associative section as `parent|name`):

| Line | Meaning |
| --- | --- |
| `SECTION-ONLY-A`, `SECTION-ONLY-B` | a section only one object has |
| `SECTION-DIFFERS` | bytes, size, flags, COMDAT selection or relocations differ; `-reloc`/`+reloc` give offset, type and target |
| `SECTION-ORDER` | the shared sections are in another order; `-order`/`+order` give the moved ones |
| `SYMBOL-ONLY-A`, `SYMBOL-ONLY-B` | name, value, section, type, storage class |
| `RENAME-MERGES` | an object holds both spellings of a rename |
| `RENAME-KEPT` | the head still holds a rename's OLD spelling |
| `NOTE` | a rename whose OLD name the base does not have |

For the instructions of a differing function, disassemble it in both objects
with `llvm-objdump -d -r --disassemble-symbols=NAME`.

A rename `OLD=NEW` (mangled names; in `--map FILE` one per line, `#`
comments) is a respelling of the base: the base's `OLD` compares as `NEW`,
and a C++ name embedded in another of its names too, such as a renamed
function's `$cppxdata$` or static locals. The head is compared as it is.
When a rename applies to the base, equal structure counts as identical;
otherwise only equal bytes do. The `RENAME-` lines print only when the bytes
differ.

A unit whose head keeps some calls of `OLD` (a mixed unit) differs with
`RENAME-KEPT`, and with `RENAME-MERGES` for B when it holds both spellings:
that is the expected result. Each kept site shows as a `-reloc` to `NEW`
and a `+reloc` to `OLD` at one offset. Prove such a unit by comparing with
the map and listing each kept site from those lines, or with a per-site
check table.

## Comparing warnings

```sh
python3 tools/object-proof/proof.py warnings [--strip PREFIX ...] A.log B.log
```

Any compiler or ninja log. It keeps the lines with `warning:`, turns `\` into
`/`, removes each `PREFIX` (such as two export roots) and the `(line,col)` or
`:line:col` position, and compares them as counted lines. A difference lists
the classes whose counts changed and the lines only in A (`-`) or B (`+`).

## Exit status

All three commands: 0 identical (or compiled), 1 differs (or a compile
failed), 2 usage error, unreadable input or a compiler that cannot start.

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
  names it indexes. A name inside section bytes, such as CodeView in
  `.debug$S` or a `.drectve` directive, is not respelled and shows as a
  difference.
- One object at a time: which COMDAT copy a link selects, and inlined copies
  in other units, are not seen.
- The warnings comparison ignores notes, errors and cl.exe-style lines
  (`warning C4996:`), and a warning that only moved lines compares equal.
- One export path for base and head is the caller's duty; the tools do not
  verify it.
- The tests (`tools.object_proof.*`, `test_object_proof.py`) use small
  hand-made objects, not compiler output.
