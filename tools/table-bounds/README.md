# Table bounds check

Checks that no relocation of any object of the game archive addresses a
generated table at or past its end, or before its start (VEGAS-30,
docs/table-slot-reads.md). The tables are the arrays that the fifteen
generated vtable units define. Each unit puts its tables one after another,
so a read past the end of one reads the next, and with one section per table
it would read whatever the linker places next.

It needs Go 1.24.11 or newer and no other module. It reads objects with the
standard library's `debug/pe`.

```text
go test -race ./...
go vet ./...
go run . --sources SOURCE_LIST [--root DIR] --objects OBJECT_LIST --allow allow.tsv
```

`SOURCE_LIST` is a file with one generated vtable unit per line, as the build
compiles it. Relative paths start from `DIR`. `OBJECT_LIST` is a file with one
object path per line.

## What it reads

- The tables and their lengths, from the sources. A table is an array
  `void* NAME[] = {` up to its `};`, and its length is 8 bytes for each line
  between that is not blank and not a comment. Its symbol name is the asm
  label of `NAME` in the `vtables.h` beside the unit, the header the unit
  includes, or `NAME` when the declaration has no label.
- Every relocation of every section of every object whose target is one of
  those names, with the addend stored at it. For the `REL32` types the stored
  addend leaves out the bytes of an immediate that follows the displacement,
  up to 4, so the check takes the addend plus 4 as the offset used: it fails
  when that is negative or at least the length.
- The holder of each such relocation: the last external or static symbol of
  its section at or before the relocation's offset, such as the function or
  the funclet that holds the code.

## Where it runs

CTest runs it in every windows-x64 build, the cross build and the Windows CI
job's, as `objects.table_bounds`. CMake writes the vtable units of the game target to
`vtable-sources.txt` in the build's `tests` folder, after the four composed
units have replaced their originals (docs/native-data-ownership.md), and
fails at configure time when there are not fifteen. The object list is the
`game-objects.txt` of the other object checks.

## The allow file

Tab-separated. Blank lines and lines that start with `#` are skipped.

```text
allow<TAB>HOLDER<TAB>TABLE
```

Each line is a read past a table's end that is known and still open. A
relocation of that holder to that table is reported as `allowed` and does
not fail the check. A line that matches no relocation fails the check, so the
line goes with the repair.

## Exit status

| Status | Meaning |
| --- | --- |
| 0 | Every relocation to a table lies inside it or is allowed, and every allowed read is found. |
| 1 | A relocation may lie outside its table and is not allowed, or an allowed read is not found. Each prints a `FAIL` line. |
| 2 | The check could not be completed: bad arguments, sources or allow file; an object that is not an x64 COFF object; a table that the objects define other than once; a table whose length in the source does not fit before the next symbol of its section in the object; a relocation to a table of a type whose addend the command does not read (it reads `ADDR64`, `ADDR32`, `ADDR32NB` and the `REL32` types). |

## What it does not see

- A read through a table pointer loaded from memory, such as a call through
  an object's table pointer that the same function did not store. It has no
  relocation to the table, and which table the object holds is only known at
  run time.
- A relocation to another name of the same storage: an `/alternatename`
  target, or a name defined at an offset inside a table.
- Which slot a read inside a table means. A read inside the table's length
  passes even when the original read another slot.
