# Object and archive checks in Windows CI

VEGAS-95. The 18 CTest checks that read the windows-x64 game archive or its
objects, `objects.*` and `archive.*`, were registered only when the host is
not Windows. The Windows CI job built the archive and never ran them. They
now run in every windows-x64 build.

## Why they were cross-only

Each check runs on the build host and reads the target's files there. None
runs a Windows executable. The guard came from the first one,
`archive.differing_definitions`, whose allowlist was measured on the cross
build. The others copied the guard, and the tools they need were looked up
only for the cross build:

| Tool | Checks |
| --- | --- |
| Go | `archive.differing_definitions`, the `tools/function-relocations` checks, `objects.string_npos`, `objects.table_bounds` |
| `llvm-objdump` beside clang-cl | `archive.empty_import_slots`, the four instruction checks, `archive.animation_key_tables` |
| Python 3 | `archive.animation_key_tables` |

The four instruction checks are `objects.release_and_destroy_slot_call`,
`objects.memory_free_forwarder`, `objects.anim_group_sound_entry_size` and
`objects.cell_reference_radii_result`. Their patterns are specific to
clang-cl at `/O2`.

## The Windows CI job's toolchain

Run 43346960889 at `891a44f50` configured with
`C:/Program Files/LLVM/bin/clang-cl.exe`, Clang 20.1.8, and the standard
library of Visual Studio 14.51. The LLVM 20.1.8 Windows installer puts
`llvm-objdump.exe` in the same folder. The job installs Go 1.27.2, and its
configure found Python 3.15.2 on the runner's `PATH`. Its report step of
`tools/differing-definitions` printed 2,235 members, 519 names, 0 new and 0
stale against the allowlist.

The cross build uses Homebrew's clang-cl 23.1.5 and the standard library
14.44 that `xwin` downloads.

## What changed

- `tests/CMakeLists.txt` finds Go, `llvm-objdump` beside clang-cl and Python
  3 once for every windows-x64 build, and registers the 18 checks when all
  three are found. A cross build stops when one is missing. A build on a
  Windows host warns and registers `objects.tools`, which fails with the
  same reason, as `setup.recipe_ranges` does for Python 3.
- The workflow's report-only step of `tools/differing-definitions` is
  removed: CTest runs the same command and fails the job.
- A Windows checkout writes the checks' tables and the generated vtable
  units with CRLF line ends: the attribute fixes of VEGAS-86 and VEGAS-102
  found this for the pinned inputs. `tools/function-relocations`,
  `tools/data-values` and `tools/table-bounds` read such lines with the
  carriage return. A forbidden name then matched no relocation, a `-`
  REQUIRED field became a name, every value line was refused, and the
  eleven vtable units without an LF attribute gave no table. Each tool now
  drops one trailing carriage return per line.

## Measured at 891a44f50

A cross build of `891a44f50` with the official LLVM 20.1.8 release, the CI
job's compiler version, passes all 18 checks, as the cross build with
clang-cl 23.1.5 does. Its archive has the same 519 names as the allowlist,
0 new and 0 stale.

Each check fails on its broken form on that clang-cl 20.1.8 build. A broken
form reverse-applies the source changes of the fix the check guards,
recompiles the affected units with the build's own command, and runs the
registered test on the object list and a game archive built from it.

| Check | Broken form | Failure |
| --- | --- | --- |
| `archive.empty_import_slots` | `59e085967` reversed | relocations to the empty slot names |
| `objects.d3dx_call_arguments_fallout_shared` | `3b9ed3e3e` reversed | argument-less D3DX names, no native callee |
| `objects.d3dx_call_arguments_shader_constants` | `56ce8ab3a` reversed | the same |
| `objects.d3dx_call_arguments_lighting` | `69d5deaeb` reversed | the same |
| `objects.mask_constants` | `1783882f1` reversed | relocations to `?DAT_00ffffff@@3HA` |
| `objects.hacking_array_retirement` | `0a5e4e9b2` and `e697767cb` reversed | the vector deleting destructor's callees, not the element's destructor and sized array delete |
| `objects.navmesh_pointer_result` | `58b7b0025` reversed | no call of the result's destructor |
| `objects.winmain_boot_calls` | `54c52298b` reversed | the main loop under its former name |
| `objects.integer_width_calls` | `1c38a5b37` reversed | the requirers' former names |
| `objects.string_npos` | `acb1c766e` reversed | the npos in `.bss` |
| `objects.table_slot_reads` | `a34145a3c` reversed | reads 16 bytes into two 16-byte tables |
| `objects.table_bounds` | `a34145a3c` reversed | the same two reads |
| `objects.release_and_destroy_slot_call` | `eb03d5780` reversed | the data pointer loaded into `rdx` |
| `objects.memory_free_forwarder` | `ddb8a96da` reversed | no definition under the one-pointer name |
| `objects.anim_group_sound_entry_size` | `d72f787d8` reversed | `shll $0x4` |
| `objects.cell_reference_radii_result` | `5c988e0b9` reversed | the result's x and z not loaded before the constructor |
| `archive.animation_key_tables` | a member that defines `DAT_011f3758` | check a |
| `archive.differing_definitions` | the allowlist without its first name | that name is new |

Two rows need more than the reversal:

- The broken form of `5c988e0b9` discards GetRadii's result, which
  `-Werror=unused-result` (`89ae56d87`) refuses. It was compiled with that
  one error turned back into a warning.
- The broken form of `ddb8a96da` takes no parameter, so it has another
  name. Run on that name, the check's own patterns report its
  `xorl %edx, %edx`.

`hacking_array_retirement` reverses `0a5e4e9b2` too, because that later
commit retired the body the broken form calls.

## Not verified

- No Windows host ran the checks. What the first CI run must show: the
  configure finds Go, `llvm-objdump` and Python 3 and prints no warning
  about them; CTest lists the 18 checks and no `objects.tools`; each of the
  18 passes.
- The compiler was matched, the standard library was not: the clang-cl
  20.1.8 build used 14.44 from `xwin`, the CI job uses 14.51. The CI job's
  report of the allowlist covers the names, not the four instruction
  checks.
- `$<TARGET_OBJECTS:game>` is assumed to give paths with forward slashes on
  Windows, as the tools match a unit by its `/UNIT.obj` suffix. With other
  separators the tools stop with "0 objects of UNIT" and fail.
- When the runner's LLVM changes version, an instruction check may stop
  matching. It then fails the job and the patterns need review.
