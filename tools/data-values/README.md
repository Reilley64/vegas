# Data values check

Checks the initial bytes or the extent of named data in the windows-x64
object of its unit. For every row of a table it finds the one external symbol
that defines the name in the object compiled from the row's unit. A `value`
row fails when:

- the symbol lies in a section without initialised contents, such as `.bss`,
  so the value is zero,
- the bytes at the symbol differ from the row's bytes, or
- a relocation of the section may patch one of those bytes.

An `extent` row fails when the symbol reaches fewer bytes than the row gives:
the distance from the symbol to the nearest symbol of its section that lies
further on, or to the section's end.

It reads the object only. It does not see a store to the name at run time,
a second definition in another object, or the bytes past the row's length.
A COFF symbol has no size, so an extent row measures the most the definition
can occupy, padding before the next symbol included: a definition a few bytes
short of the row that the compiler pads up to the next symbol's alignment
passes.

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
extent<TAB>UNIT<TAB>NAME<TAB>BYTES
```

`HEX` is the bytes the name starts with, in the order they lie in the
object, two hex digits each. `BYTES` is a decimal count above zero.

`string-npos.tsv` holds the npos of the string library at `0x010173f0`,
defined in `src/speedtree/frondengine.cpp` (VEGAS-100). Its users read a
32-bit unsigned int, so the row requires the four bytes `ffffffff`. The
definition was zero-initialised before, and the row fails on that form.

`path-buffer-extents.tsv` holds `DAT_01202b48`, the destination of the
log-path builder at `0x00c3bbe0` (VEGAS-112), defined in
`src/fallout/misc/log_paths.cpp` since VEGAS-127. The builder writes up to
260 characters there, so the row requires an extent of 260 bytes. Generated data defined it
as one byte, and the row fails on that form. It also holds
`?DAT_01202e98@@3PADA`, the buffer that `FUN_0086d480` returns, defined in
`src/fallout/misc/app_data_folder.cpp` (VEGAS-112, VEGAS-128).
`GetSaveDirectory` copies a folder of up to 260 characters there, so the row
requires 260 bytes. Generated data defined it as a 4-byte `int`,
`?DAT_01202e98@@3HA`; on that form the object defines no array of the row's
name, and the check stops with exit status 2.

## Where it runs

CTest runs it in every windows-x64 build, the cross build and the Windows CI
job's, like the function relocation checks: `objects.string_npos` for
`string-npos.tsv` and `objects.path_buffer_extents` for
`path-buffer-extents.tsv`, on the object list of the game archive that CMake writes to `game-objects.txt` in the
build's `tests` folder.

## Exit status

| Status | Meaning |
| --- | --- |
| 0 | Every row passes. Each prints an `ok` line. |
| 1 | A row fails. It prints a `FAIL` line with the reason. |
| 2 | The check could not be completed: bad arguments or table; a unit with no object or several; an object that is not an x64 COFF object; a name that is not defined as an external symbol, or defined twice; bytes, or the symbol of an extent row, that lie outside the section; a section whose relocation count overflows. |
