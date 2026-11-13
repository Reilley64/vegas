# The function-level link of FalloutNV.exe (VEGAS-126)

The owner admitted it on 2026-11-13 (recorded on VEGAS-30): FalloutNV.exe,
and only it, may link with unresolved names tolerated, on condition that a
standing check on every build fails unless every unresolved name is
referenced only from sections the linker discarded. No stub is written.

The strict link stays the gate of VEGAS-30: its criterion 1, FalloutNV.exe
links with no unresolved symbol, is unchanged. The forced link of every
archive member stays the yardstick of VEGAS-11.

## The rule

`vegas_function_level_link` in `CMakeLists.txt` gives one target three
lld-link options:

- `/OPT:REF`: discard every COMDAT section that no kept section reaches.
  lld-link already does this without `/DEBUG`; the option keeps it if debug
  information is ever added.
- `/FORCE:UNRESOLVED`: link although names stay unresolved. Duplicate
  definitions are still errors.
- `/MAP:<build>/<target>.map`: the map the check reads.

FalloutNV calls it, and so do the check's own test programs. Every other
program, `vegas-setup` and the game archive keep the strict link. The rule
applies only when `CMAKE_LINKER` is lld-link; with another linker the target
keeps the strict link, `link.function_level` fails and the programs with a
live reference fail to link.

Both builds use lld-link: the cross build takes it from the toolchain file,
and the Windows CI job uses the lld-link of LLVM 20.1.8 beside clang-cl. In
both, CMake runs the link through `cmake -E vs_link_exe`, which drops the
output of a link that succeeds, so the check reads files the link writes and
never the linker's messages.

## The check

`link.function_level` (`tests/checks/link_function_level.cmake`) runs
`tools/function-level-link/check.py` in every windows-x64 build. It reads
FalloutNV.exe, the map of its link, the target's objects and the static
libraries the build made for it (`game` and `zlibstatic`, followed through
their link interfaces).

What lld-link does, which the check relies on (lld/COFF, the same in LLVM 20
and 23):

1. It replaces every name it cannot resolve by an absolute symbol of value
   zero. The map lists the symbols of every loaded object, so each such name
   is listed at absolute address zero.
2. The map lists a symbol only when its section is in the executable, and an
   external name with the object whose copy the link selected.
3. `/OPT:REF` discards only COMDAT sections. A section that is not a COMDAT
   is in the executable whenever its object is loaded.

One more case follows from point 1. When lld-link has replaced X by zero
before it reaches `__imp_X`, it makes `__imp_X` an import slot of its own
that holds zero, which the map lists with an address and no object, so a
call through that slot is a call through a zero pointer. The check counts
such a slot as unresolved; which of the two forms a link takes depends on
the order of lld-link's symbol table.

From these, a section of an object read is in the executable when:

- it is a COMDAT and its COMDAT symbol (the first symbol after its section
  definition) is listed with its own object;
- it is associative and the section it is associated with is in the
  executable, or a kept section refers to it directly: the map lists one of
  its own symbols, or a kept section of its object refers to it;
- it is not a COMDAT and its object is loaded: always for the target's own
  objects; for an archive member when the map lists one of its symbols, and
  not when a symbol of one of its sections that are not COMDATs is missing.

Every relocation of every object read that targets an unresolved name must
be in a section that is not in the executable. The check also fails when:

- it cannot tell whether a referencing section is kept: two members of one
  file name both define the listed symbol, or a member has no symbol that
  settles whether it was loaded;
- no relocation targets an unresolved name;
- the map lists a name at absolute zero that no object read refers to,
  except the linker's own (`__guard_*`, `__enclave_config`) and the C
  runtime's `__AbsoluteZero` and `__volatile_metadata`;
- the map names an object of the target or of a library it read that it did
  not read;
- the map names a member of a library that it neither read nor lists as a
  system library (`SYSTEM_LIBRARIES` in `check.py`, each with its reason:
  the C runtime and the Windows import libraries seen in the maps of both C
  runtime flavours the builds use);
- a line of the map is out of its place, or the map is missing;
- the map is not the one of this executable: another file name, header
  timestamp (unless the link was in repro mode), load address, entry point,
  or a section range outside the executable's sections.

Five test programs link with the same rule and are never run:
`link.function_level.live_code`, `.live_data`, `.live_vtable` and
`.live_import` each hold one live reference to a name nothing defines, from
a call in `main`, from initialized data, from the virtual table of a class
that `main` constructs, and from a call in `main` through an import slot
whose name another unit also refers to plainly from dead code; each passes
only when the check reports that reference as LIVE and prints no
UNCLASSIFIED or REFUSED line. `.live_import` passes on either form of the
import slot. `link.function_level.dead_function` refers to such a name
only from a function nothing calls, in a static library member that the
link loads; it passes only when the check accepts it.
`tools.function_level_link.*` test the check on hand-made objects, archives,
maps and executables.

## Limits

- The objects of the listed system libraries, the C runtime and the
  Windows import libraries, are not read, and references from them are not
  checked: one to a name that nothing defines fails the check only when no
  object read refers to that name too. A map that names a member of any
  other library the check did not read is refused.
- A reference that a linker option makes (/include, /export) is not
  checked, and a name that only an option names is not in the map. Two
  cases are still caught. A call through the import slot of such a name is
  reported, because the slot is listed without an object. For an exported
  name that nothing defines, lld-link writes an export address outside the
  executable's sections, and the check refuses an executable with such an
  export. No source of this repository passes either option, and
  FalloutNV.exe has no export table.
- In repro mode or with SOURCE_DATE_EPOCH the timestamp does not tie the map
  to the executable.
- The check proves that no unresolved name is referenced from the
  executable. It proves nothing about names that resolved: their layouts,
  receivers and lifetimes stay as open as before, and it does not show that
  a kept section is ever reached at run time.
- It trusts lld-link's map. Points 1 to 3 above are read from lld-link's
  source, not proved by the check; the tests cover them on real links of the
  test programs.
- Identical-code folding keeps one of several equal sections. The map lists
  the symbols of a folded section at the address of the kept one, so the
  check counts both as in the executable; they have the same relocations to
  the same names.
- A member whose file name another member shares is told apart only by the
  symbols the other does not define.

## Reading a failure

- `LIVE NAME from kept OBJECT section N NAME (LEADER)`: a section in the
  executable refers to NAME, which nothing defines. NAME is a real
  prerequisite of what the target composes: give it its definition, or do
  not compose the statement that reaches it. Never add a stub.
- `UNCLASSIFIED ...`: the check cannot tell; treat it as LIVE until the
  reason it gives is removed.
- `REFUSED ...`: the map or the inputs cannot be read as described above.
  Configure and build again; if it stays, the link or the map changed form
  and the check must be brought up to it before the target is trusted.

lld-link writes a code reference to an unresolved name as an address
0x40000000 below the load address and a 64-bit data reference as zero.
Nothing guarantees a crash: that address can be mapped once the executable is
loaded at another address, and code that tests a pointer against null runs on. The check is
the only guard; it does not disassemble the executable.

## FalloutNV.exe today

With today's `main` the link leaves no name unresolved, and FalloutNV.exe is
the strict link's byte for byte apart from the header timestamp (cross
build, measured on `1a4404c01`).
