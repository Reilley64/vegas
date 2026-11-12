# Data values check

Checks the initial bytes of named data in the windows-x64 object of its
unit. For every row of a table it finds the one external symbol that defines
the name in the object compiled from the row's unit, and fails when:

- the symbol lies in a section without initialised contents, such as `.bss`,
  so the value is zero,
- the bytes at the symbol differ from the row's bytes, or
- a relocation of the section may patch one of those bytes.

It reads the object only. It does not see a store to the name at run time,
a second definition in another object, or the bytes past the row's length.

It needs Go 1.24.11 or newer and no other module. It reads objects with the
standard library's `debug/pe`.

```text
go test -race ./...
go vet ./...
go run . --table TABLE --objects OBJECT_LIST
```

`OBJECT_LIST` is a file with one object path per line. A row's object is the
one path that ends in `/UNIT.obj`, where `UNIT` is the row's unit, such as
`src/speedtree/frondengine.cpp`.

## The table

Tab-separated. Blank lines and lines that start with `#` are skipped.

```text
value<TAB>UNIT<TAB>NAME<TAB>HEX
```

`HEX` is the bytes the name starts with, in the order they lie in the
object, two hex digits each.

`string-npos.tsv` holds the npos of the string library at `0x010173f0`,
defined in `src/speedtree/frondengine.cpp` (VEGAS-100). Its users read a
32-bit unsigned int, so the row requires the four bytes `ffffffff`. The
definition was zero-initialised before, and the row fails on that form.

## Where it runs

CTest runs it in the windows-x64 cross build only, like the function
relocation checks: `objects.string_npos` for `string-npos.tsv`, on the object
list of the game archive that CMake writes to `game-objects.txt` in the
build's `tests` folder.

## Exit status

| Status | Meaning |
| --- | --- |
| 0 | Every row passes. Each prints an `ok` line. |
| 1 | A row fails. It prints a `FAIL` line with the reason. |
| 2 | The check could not be completed: bad arguments or table; a unit with no object or several; an object that is not an x64 COFF object; a name that is not defined as an external symbol, or defined twice; bytes that lie outside the section; a section whose relocation count overflows. |
