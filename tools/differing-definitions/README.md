# Differing-definitions check

The linker keeps one definition of a COMDAT name and discards the others
without comparing them. This command reads the windows-x64 game archive and
finds every external name whose definitions differ between members. It fails
when one of them is not in the recorded list, `allowlist.tsv`.

It needs Go 1.24.11 or newer and no other module.

```text
go test -race ./...
go vet ./...
go run . --archive GAME_LIB --allowlist allowlist.tsv
go run . --archive GAME_LIB --allowlist allowlist.tsv --strict
go run . --archive GAME_LIB --allowlist allowlist.tsv --prune
go run . --archive GAME_LIB --list
```

## Where it runs

The set of names depends on the compiler and on the standard library. The
allowlist was measured on the cross build: clang-cl on a host that is not
Windows, with the Windows SDK and CRT that `xwin` downloads.

- CTest runs the check as `archive.differing_definitions` in every
  windows-x64 build: the cross build, and a build on a Windows host such as
  the Windows CI job, whose test suite fails the job with it. Configuring the
  cross build fails when Go is not found; on a Windows host `objects.tools`
  fails instead (`tests/CMakeLists.txt`).
- The Windows CI job builds with clang-cl 20.1.8 and the standard library of
  Visual Studio. At `891a44f50` its archive had the same 519 names as the
  allowlist, 0 new and 0 stale, so one list holds for both toolchains
  (`docs/windows-ci-object-checks.md`). When a change makes them part, the
  check fails on one of them, and the list cannot match both.

## What is compared

Every definition of every external name in every member, for every COMDAT
selection. Two definitions are equal when their sections have the same size,
the same bytes and the same relocations: offset, type and target.

- A target is compared by name. The per-file hash in the name of an anonymous
  namespace is set aside.
- A unit-local target in a COMDAT section of its own is compared by what that
  section holds and not by its name. So two equal bodies that call same-named
  unit-local helpers with different bodies differ. This goes one level deep:
  the helper's own targets are compared by name.
- An uninitialised section has no bytes. Its size is compared.
- Two definitions outside COMDAT sections always differ.
- A COMDAT section is one definition, under its first external symbol.

## What is not compared

- **Unit-local targets in a section that holds several objects** (`.rdata`,
  `.data`, `.bss`, `.tls$`). Nothing in the object says where such a target
  ends, so its name stands for it. Hashing the whole section instead reports
  four names, all base class arrays of the standard library:
  `??_R2?$_Func_base@XPEAX@std@@8`, `??_R2?$_Func_base@XPEAXH@std@@8`,
  `??_R2?$_Ref_count_obj2@UCompletionLedger@serialize@havok@@@std@@8` and
  `??_R2_Ref_count_base@std@@8`. Each refers to a base class descriptor that
  some units emit unit-local in `.rdata` and others as an external COMDAT.
- **Sections associated with another section** (COMDAT selection 5). With this
  compiler these are the `.pdata` and `.xdata` unwind records and the
  `.debug$S` records of a COMDAT function. They belong to that function's
  definition and are skipped. Two definitions with equal code and different
  unwind records are not reported.
- **A second external symbol in one COMDAT section.** The section is compared
  once, under its first external symbol.
- **The offset of the name within its section.** Two equal sections that place
  the name at different offsets compare equal. With this compiler the name
  is at offset 0 of its section, or at offset 8 in a virtual table's section,
  after the pointer to the complete object locator. In the archive no name
  has definitions at two offsets.
- **Names with one definition.** A unit that requires a name which no member
  defines is the forced link's business, not this command's.

## What it reads, and what stops it

An `ar` archive whose members are x64 COFF objects, ordinary or bigobj, with
member names in the header, in a GNU long-name table or in a COFF one. Two
members may have the same name. Relocation counts above 65,534, stored in the
first relocation record, are read.

The command stops with exit status 2, and passes over nothing, when it meets
a member that is not an x64 COFF object (an import member, a bitcode member,
an object for another machine), a BSD-style member name, a COMDAT section
without a section definition record or with a selection the format does not
define, or a relocation whose target is not a symbol.

## Exit status

| Status | Meaning |
| --- | --- |
| 0 | Every name that differs is recorded. `STALE` lines may have been printed. |
| 1 | A `NEW` line was printed; or, with `--strict`, a `STALE` line. |
| 2 | The arguments are not a valid use of the command; the archive or the allowlist could not be read; an allowlist line is malformed or repeats a name; or `--prune` could not rewrite the allowlist. |

- `NEW`: a name differs and is not recorded, or is recorded under another
  kind. The line has its kind, selection, counts and first defining member.
  It always fails.
- `STALE`: a recorded name no longer differs. It is printed and passes, so a
  change that resolves a conflict does not have to edit the list.
- `--strict` makes a `STALE` line fail.
- `--prune` rewrites the allowlist without its stale lines and prints each as
  `PRUNED`. It removes lines and does nothing else: order, comments and blank
  lines stay, and no line is ever added. A `NEW` name still fails.
- `--list` prints every name that differs with its kind, selection, counts and
  first defining member, and exits 0. It is a report for reading.

## The allowlist

One `kind<TAB>name` per line. Blank lines and lines that start with `#` are
kept. The kind is `function` for a name defined in a code section. For data it
follows the compiler's prefix: `vtable`, `rtti-...`, `throw-info`,
`catchable-type-array`, `catchable-type`, `string`, `constant`, `guard` or
`data`.

A recorded name is an open conflict, not an accepted one. VEGAS-89 owns the
list, and `docs/differing-definitions.md` has the cause of each function name
and the data names counted by cause.

- **A `NEW` name is repaired at its source.** The command has no way to add a
  line. A line is added only by hand, in a change of its own that states the
  reason and is reviewed.
- **A change that resolves a conflict leaves the list alone.** It reports the
  `STALE` lines it produces.
- **Stale lines are removed when changes are integrated**: `--prune`, then
  `--strict`, and the shorter list is committed with the integration.
