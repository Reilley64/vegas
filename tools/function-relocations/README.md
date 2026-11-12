# Function relocations check

Checks, function by function, which names the code of a function refers to
in the windows-x64 object of its unit. For every function of a table it finds
the COMDAT code section that defines the function's name, counts that
section's relocations by target name, and fails when:

- the section has a relocation to a name the table forbids, or
- the section has no relocation to a name the table requires of that function.

It looks at the function's own section, not at the whole object. An object
may keep a forbidden name in other functions.

It needs Go 1.24.11 or newer and no other module. It reads objects with the
standard library's `debug/pe`.

```text
go test -race ./...
go vet ./...
go run . --table d3dx-call-arguments.tsv --objects OBJECT_LIST [--batch NAME]
```

`OBJECT_LIST` is a file with one object path per line. Each function's object
is the one path that ends in `/UNIT.obj`, where `UNIT` is the table's unit,
such as `src/fallout_shared/teswater.cpp`.

## Where it runs

CTest runs it in the windows-x64 cross build only, like
`archive.differing_definitions`: `objects.d3dx_call_arguments_BATCH`, one test
per batch of `d3dx-call-arguments.tsv`,
`objects.hacking_array_retirement` for `hacking-array-retirement.tsv`,
`objects.navmesh_pointer_result` for `navmesh-pointer-result.tsv`, and
`objects.mask_constants`, one test for all of `mask-constants.tsv`. CMake
writes the object list of the game archive to `game-objects.txt` in the
build's `tests` folder.

## The table

Tab-separated. Blank lines and lines that start with `#` are skipped.

```text
forbid<TAB>NAME
function<TAB>BATCH<TAB>UNIT<TAB>NAME<TAB>REQUIRED[ REQUIRED...]
```

Every `forbid` name is forbidden in every function. `REQUIRED` names are
separated by spaces. A `REQUIRED` field of `-` requires no name.

`d3dx-call-arguments.tsv` lists the 12 functions whose calls of the D3DX
matrix inverse (`0x00ee6dda`), transpose (`0x00ee6dd4`) and vector normal
transform (`0x00ee6df2`) got their arguments back (VEGAS-90). It forbids the
three argument-less names and requires the native names each function calls.
`0x00bbef90` stands for the frustum update that it inlines. With the unit's
own flags the optimizer may merge equal calls, so the check counts names, not
calls.

`hacking-array-retirement.tsv` lists the function at `0x007687d0`, which
deletes the hacking menu's array of `HackingArrayElement` (VEGAS-72). It
forbids the transcribed vector deleting destructor at `0x007021b0` and the
three names its array path calls, and requires the element's destructor and
the sized array delete, which `delete[]` of the element type calls. The count
before the array, the element size and the size passed to the array delete
are not relocations; docs/hacking-element-release.md records them from the
instructions.

`navmesh-pointer-result.tsv` lists the function at `0x005436e0` in
`tesobjectcell.cpp`, which calls `MakeNavMeshPointer` (`0x00464fc0`)
(VEGAS-96). It requires that name and the destructor of the
`NiPointer<NavMesh>` it returns. A caller that sees that class as trivial
never calls the destructor, and on windows-x64 it is also the caller that
expects the result in a register instead of passing its address: a class with
a destructor of its own is always returned through that address. The table
forbids the name under which the unit's recipe symbols name the callee, with
a `NavMeshPtr` result; no object defines it. Which register carries which
argument is not a relocation; docs/navmesh-pointer-result.md records it from
the instructions.

`mask-constants.tsv` lists the 18 functions whose numeric masks, flags,
counts and limits were spelled as the addresses of data names (VEGAS-93,
docs/mask-constants.md). It forbids the six names and requires none.

## Exit status

| Status | Meaning |
| --- | --- |
| 0 | Every function of the batch passes. Each prints an `ok` line. |
| 1 | A function fails. It prints a `FAIL` line with each forbidden name's relocation count and each missing required name. |
| 2 | The check could not be completed: bad arguments or table; no batch function; a unit with no object or several; an object that is not an x64 COFF object; a function name that is not defined, defined twice, or not in a COMDAT code section; a section whose relocation count overflows. |

## What it does not see

- Calls through a pointer. They have no relocation to the callee's name.
- How many calls a relocation stands for, and what their arguments are. The
  arguments were checked at source and in objects built with `/Od /Ob0`
  (docs/d3dx-replacement.md).
- Unwind records and other sections associated with the function.
- A call through another argument-less declaration of the same address under a
  different mangled name (another namespace or signature). Only the three
  global names in the table are forbidden.
- A restored call deleted outright while the function keeps another call to the
  required native name. The check counts names, not calls, so exact relocation
  counts are not compared (the optimizer merges calls).
