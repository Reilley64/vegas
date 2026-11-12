# The data pack stage of main (VEGAS-52)

## Scope

This is increment 2 of `data-pack-catalogue.md`, complete: `main` reads the
data pack, validates it, publishes C1, the four strings of the
single-instance and remote-session checks, to their native owner, and runs
C1's consumer, the composed first statements of `0x0086a850`. It follows
ADR 0001 and the decisions D1 to D10 of that page. Under D3 the pack stage
enters `main` only together with that consumer.

## What main does

`main` in `src/main.cpp`, the entry of the `FalloutNV` executable, runs:

1. `fnv::memory::StartProcessMemory`. A refusal returns 1, as before.
2. `fnv::timer::Start`, as before.
3. The folder of the running executable, from `GetModuleFileNameW`. ADR 0001
   resolves the pack there, never in the working directory. If the folder
   cannot be found, `main` writes one line to the standard error stream and
   returns 2.
4. `fnv::startup::LoadDataPack` of that folder. On a failure it writes the
   line the stage returns to the standard error stream and returns 2.
5. On the strings the stage returns, the first statements of `WinMain`
   (`0x0086a850`): `CreateMutexA` with no attributes, not owned, named by
   the mutex name, then `fnv::startup::CheckSingleInstance` on the last
   error, with `GetSystemMetrics(SM_REMOTESESSION)` as the remote-session
   query and `MessageBoxA` with no owner window as the message box.
6. It returns 0: after either message box, as `WinMain` does, and otherwise
   because nothing of `WinMain` after the checks is composed in `main`.

No failure of the pack stage shows a message box. The pack is read only in
`main`, after memory startup, so no pack is read before `main` (D2). No pack
value is read before validation succeeds.

`main` never closes the mutex handle, as `WinMain` never closes it, so the
process holds the mutex until it ends.

An allocation failure inside the stage throws `std::bad_alloc`. Neither the
stage nor `main` catches it, so the C++ runtime calls `std::terminate`, which
ends the process abnormally with no line from the stage. No test covers it.

## The stage

`fnv::startup::LoadDataPack` in `include/fnv/data_pack_startup.h` takes the
executable's folder only. It reads `vegas-data.pack` there with
`fileformat::OpenAndValidatePack` and publishes C1 with
`fnv::startup::PublishSingleInstanceStrings`. On success it returns the
published strings, read back through `PublishedSingleInstanceStrings`. Their
consumer gets them only from that result, so it cannot read them before
they are published. A missing, unreadable or invalid pack is normal
validation, not a fault: the stage publishes nothing and returns one line
that names the failure and ends with the validator's message:

| Error | The line starts with |
| --- | --- |
| `PackOpenError`, `Missing` | `vegas-data.pack is missing beside the executable:` |
| `PackOpenError`, `Unreadable` | `vegas-data.pack beside the executable cannot be read:` |
| `FormatError`: a structure or catalogue problem | `vegas-data.pack beside the executable is not a valid data pack:` |
| `UnsupportedOriginalError` | `vegas-data.pack beside the executable was not prepared from a supported original release:` |

There is no interface that can only fail: a complete pack that records the
supported original succeeds.

## C1's owner

`fnv::startup::PublishSingleInstanceStrings` and
`fnv::startup::PublishedSingleInstanceStrings`, in
`include/fnv/single_instance_strings.h`, are the native owner of C1. Its
storage is one `fileformat::SingleInstanceStrings`, the declaration whose
four capacities fix the entry's size (D6 and D8), so no second layout of the
strings exists. The one writer takes a `ValidatedPack`, which holds decoded
values and no raw bytes. A read before any publication terminates the
process. `main` cannot make such a read, since it takes the strings from the
stage's result; the check stays as a backstop.

## C1's consumer

`WinMain`'s first statements, as `FUN_0086a850` in
`src/fallout/misc/main.cpp` transcribes them:

1. `CreateMutexA(0, 0, mutex name)`.
2. If `GetLastError()` is `0xb7`, `ERROR_ALREADY_EXISTS`:
   `MessageBoxA(0, first message text, caption, 0)`, then return 0.
3. If `GetSystemMetrics(0x1000)`, `SM_REMOTESESSION`, is non-zero:
   `MessageBoxA(0, second message text, caption, 0)`, then return 0.
4. Otherwise the statements after the checks.

`main` composes them. The decision is
`fnv::startup::CheckSingleInstance` in `include/fnv/single_instance_check.h`,
a member of the game archive. It takes the strings, the last error after
`CreateMutexA`, the remote-session query and the message box function, and
returns `Continue`, `AlreadyRunning` or `RemoteSession`. It makes no system
call itself: `main` makes `CreateMutexA` and `GetLastError` and passes the
two calls the decision may make. The query is a function, not a value, so
that `GetSystemMetrics` runs only when the mutex is new, as in `WinMain`.
Both boxes have type 0, `MB_OK`, and no owner window; the result of
`MessageBoxA` is not read. The texts, caption and mutex name are those of
the pack.

`FUN_0086a850` itself also reads the four strings from
`PublishedSingleInstanceStrings` instead of the legacy definitions
`str_01082ab8`, `str_01082a7c`, `str_0104df38` and `str_01082a48`; its calls,
their order and its branches are unchanged. No program that links contains
it: `main` does not call it, and the `FalloutNV` link loads only the members
`main` reaches. The binding admissions of `winmain-boot-names.md` depend on
that, and it still holds.

The four legacy definitions stay in
`src/generated/data/fallout/misc/main.inc`, which the unit includes; nothing
in the unit names them any more. They are retired later under VEGAS-52, in a
commit of their own. The recipe binds `0x0104df38`, the caption's address,
under four other names in four other units: `??_C@_05NAOIJFC@Error?$AA@` in
`hkdefaulterror.cpp`, `$SG3723` in `havokstream.cpp`, `$SG27252` in
`blk_00ac0000_od.cpp` and `_s_acError` in `cuassembler.cpp`. Each keeps its
own literal; this stage does not touch them.

## Unattended runs and message boxes

On a runner nobody answers a message box, so a run that shows one waits
until it is ended. The Windows documentation of `MessageBox` displays a box
on the caller's desktop; for a process without a visible desktop, such as a
service, only `MB_SERVICE_NOTIFICATION` moves it to the active desktop, and
`main` does not set it. `GetSystemMetrics(SM_REMOTESESSION)` is non-zero
only in a Remote Desktop Services client session and 0 in the console
session. Whether a hosted Windows runner runs its jobs in a client session,
the console session or a service session was not settled here.

The tests do not depend on it. The decision's tests record the box. Before
`falloutnv.process_exit` runs `FalloutNV.exe`, the fixture makes the same
calls as `main`, in the same session, on a mutex name new to the run, with
the box recorded. When `main` would show a box there, the test does not run
the executable and is reported as skipped. Each run of the executable also
has 60 seconds, so a run that waits fails instead of holding the runner.

## Tests

`runtime.single_instance_strings` publishes two packs that the writer makes
and reads back each field with zeros after its string, and checks that a
publication keeps the owner's storage in place. It states at compile time
that the owner's storage is `SingleInstanceStrings` and that the writer takes
a `ValidatedPack` and neither the strings nor bytes.
`runtime.single_instance_strings.unpublished_read` expects a read before any
publication to abort.

`runtime.single_instance_check` runs the decision on every branch with the
box and the query recorded: a new mutex in a local and in a remote session,
an existing mutex in both, and another error of `CreateMutexA` in both. It
checks the outcome, the text, caption and type of the one box, that no box
is shown when the outcome is `Continue`, and that the session is not asked
about when the mutex exists. On Windows it also checks that the two
constants are `ERROR_ALREADY_EXISTS` and `MB_OK`, and runs a second process:
the test holds a mutex, the second process makes `main`'s `CreateMutexA` on
its name and must decide `AlreadyRunning` with the first text; after the
test closes its handle, another process on the same name must decide
`Continue`. Both processes record the box and report the session as local.

`runtime.data_pack_startup` writes its packs into folders of its own under the
temporary folder. It accepts a complete pack, publishes its strings and
returns the owner's published strings. It refuses a missing pack, a missing
folder, a pack only in a folder below, a folder in place of the file, an
empty file, a corrupt and a truncated pack, a pack that records another
digest, a pack without the catalogue's entry and a field without a zero
byte. Each refusal returns one line naming its class. Each refused pack
holds other strings than the published ones, and the published strings stay
unchanged, so no value of a refused pack is used. Last it accepts a second
complete pack and publishes its strings.
`runtime.data_pack_startup.refused_publishes_nothing` expects a read after a
refused stage, with nothing published before, to abort.

On Windows, `falloutnv.process_exit` copies the built `FalloutNV.exe` alone
into a folder of the test's own, writes a complete synthetic pack beside it
with `falloutnv_pack_fixture`, runs the copy from another working directory
and requires exit code 0. The fixture uses the production writer and records
the supported release's identity, so the pack claims that identity: it is
compared, not proved. Its strings are made up, and its mutex name is new to
the run. No original executable is in the folder, so the run can read values
only from the pack. Exit code 0 does not tell a refusal from `Continue`;
the fixture's check before the run shows that the decision is `Continue`.
`falloutnv.process_exit.missing_pack` writes the pack only in the working
directory and requires exit code 2 and the missing pack reported on the
standard error stream. Neither test shows the engine link, startup or boot.

The tests of the decision, the stage and the owner link the game archive on
Windows. On other hosts they compile the units themselves; that form runs
under AddressSanitizer and UndefinedBehaviorSanitizer.

## Build

`single_instance_strings.cpp`, `single_instance_check.cpp` and
`data_pack_startup.cpp` are appended to the `game` archive after `pack_open`,
in that order, so the stage is the first member listed. The `FalloutNV`
link loads seven members more than before: `data_pack_startup`,
`single_instance_check`, `single_instance_strings`, `pack_open`,
`pack_validation`, `pack_structure` and `pack_container`. It does not load
`pack_writer`, `original_identity`, `pe_file` or `main`. `USER32.dll` is new
among its imports, for `GetSystemMetrics` and `MessageBoxA`; the target links
`user32` for them.

`src/main.cpp` now uses standard strings and paths, so its object defines the
scalar deleting destructors of `std::exception` and `std::bad_alloc`, and the
`FalloutNV` link keeps those copies instead of the ones in
`src/runtime/new.cpp`. Both free the object through the replaceable
`operator delete` of `new.cpp`: the kept copies call its sized form, the
others had it inlined. The archive already held both forms.

## Not verified

- No Windows executable was run here. The two `falloutnv` tests and the
  Windows forms of the other tests run in CI only.
- No real pack, no pack prepared by setup and no original executable was
  used.
- Whether a hosted Windows runner reports a remote session, and so whether
  CI runs or skips `falloutnv.process_exit`, is not known.
