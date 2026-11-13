# The data pack stage of main (VEGAS-52)

## Scope

This is increment 2 of `data-pack-catalogue.md`, complete, with catalogue
version 2 of increment 4: `main` reads the data pack, validates it,
publishes C1, the four strings of the single-instance and remote-session
checks, and the main window class to their native owners, and runs their
consumers, the composed first statements of `0x0086a850` and its
second-window check. It follows ADR 0001, the decisions D1 to D10 of that
page and the rulings of 2026-11-13 on catalogue version 2. Under D3 the
pack stage entered `main` only together with C1's consumer.

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
   query and `MessageBoxA` with no owner window as the message box. After
   either message box it returns 0, as `WinMain` does.
6. On the class name the stage returns, the second-window check of
   `WinMain`: `fnv::startup::CheckSecondWindow` with `FindWindowA` and no
   window name as the search and `SetForegroundWindow` as the foreground
   call. When a window of the class exists, it returns 0 after bringing it
   to the foreground, as `WinMain` does. The eight statements that
   `WinMain` runs between the two checks are skipped ("Skipped
   statements").
7. Otherwise it returns 0, because nothing of `WinMain` after the
   second-window check is composed in `main`.

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
`fileformat::OpenAndValidatePack`, publishes C1 with
`fnv::startup::PublishSingleInstanceStrings` and the main window class with
`fnv::startup::PublishMainWindowClass`. On success it returns
`PublishedPackValues`, the published values read back through
`PublishedSingleInstanceStrings` and `PublishedMainWindowClass`. Their
consumers get them only from that result, so they cannot read them before
they are published. Validation succeeds for the whole pack before either
value is published. A missing, unreadable or invalid pack is normal
validation, not a fault: the stage publishes nothing and returns one line
that names the failure and ends with the validator's message:

| Error | The line starts with |
| --- | --- |
| `PackOpenError`, `Missing` | `vegas-data.pack is missing beside the executable:` |
| `PackOpenError`, `Unreadable` | `vegas-data.pack beside the executable cannot be read:` |
| `FormatError`: a structure or catalogue problem | `vegas-data.pack beside the executable is not a valid data pack:` |
| `UnsupportedOriginalError` | `vegas-data.pack beside the executable was not prepared from a supported original release:` |

There is no interface that can only fail: a complete pack that records the
supported original succeeds. A pack of catalogue version 1, which has no
main window class, is refused for its catalogue version, so setup must
prepare the pack again.

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

## The main window class's owner

`fnv::startup::PublishMainWindowClass` and
`fnv::startup::PublishedMainWindowClass`, in
`include/fnv/main_window_class.h`, are the native owner of the main window
class, the `WNDC` entry. Its storage is one `fileformat::MainWindowClass`,
the declaration whose 256-byte field fixes the entry's size (D6). The one
writer takes a `ValidatedPack`, and a read before any publication
terminates the process, as for C1.

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

The checks now exist twice: in `FUN_0086a850` and in `main`. Exactly one
of them may run in a process. `main` keeps its mutex handle open, so a
second `CreateMutexA` on the same name in the same process returns
`ERROR_ALREADY_EXISTS`, and a second check would show the first message box
and return. No program runs both today, since none contains
`FUN_0086a850`. A program that does, and calls it from `main`, must first
drop the checks from one of the two.

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

## The second-window check

`WinMain`, as `FUN_0086a850` transcribes it, runs after the checks above
and the eight statements that `main` skips:

1. `FindWindowA(class name, 0)`.
2. If it returns a window: `SetForegroundWindow` on it, then return 0.
3. Otherwise the statements after the check.

`main` composes it. The decision is `fnv::startup::CheckSecondWindow` in
`include/fnv/second_window_check.h`, a member of the game archive. It takes
the main window class, the window search and the foreground call, makes no
system call itself, and returns `Continue` or `AlreadyOpen`. It searches
once, for the field's own storage, and calls the foreground call only on
the window found. The result of `SetForegroundWindow` is not read.

`FUN_0086a850` reads the class name from `PublishedMainWindowClass` where
its second-window check reads it, and passes it to the same five places as
before: `FindWindowA`, `FUN_004b4a30`, `RegisterClassA` and both name
arguments of `CreateWindowExA`. Its calls, their order and its branches are
unchanged. It no longer names the legacy pointer `_DAT_011a2fe8`. Two other
units read that pointer, `filefinder.cpp` for `SetWindowTextA` and
`renderer.cpp` for `CreateWindowExA`; they keep the legacy data until their
consumers move to the owner (D1). The pointer's legacy definition is
unchanged.

The second-window check now exists twice too, in `FUN_0086a850` and in
`main`, and no program runs both, for the reason given for C1's checks.

## Skipped statements

Under ruling A of 2026-11-13, `main` composes the statements of
`0x0086a850` in their order among those it composes, and may skip a
statement whose closure cannot link yet. Between the remote-session check
and the second-window check, `FUN_0086a850` runs eight statements, and
`main` skips all of them. The order is the transcription's: the original's
code section is encrypted in the stored file, so it was not compared with
instructions.

| | Statement | Prerequisite |
| --- | --- | --- |
| S1 | `FUN_00c3bd30(1, ...)`, the crash-log configuration, with the values of three `Setting` objects and the callback `FUN_0086a580` | the stand-in `Setting86::FUN_00408d60`, which no object defines; a native `MessageHandler` in place of the legacy virtual table `DAT_010c14a8` that its callee `0x00c3c460` stores; the closure of `blk_00c20000_od.cpp` |
| S2 to S5 | `FUN_00c3bb90`, `fnv_00c3bbe0::FUN_00c3bbe0`, `FUN_00c3bc30` and `fnv_00c3bc80::FUN_00c3bc80`, the four log paths | VEGAS-109, the defect of the `DAT_01202fa0` buffer; a later catalogue entry for their four suffix strings; the closure of `blk_00c20000_od.cpp` |
| S6 | `GetSystemInfo`, then the processor count into the setting `g_011c3ea4` through `FUN_0043d4d0` | the owner of that setting, which a generated dynamic initializer builds (D2); the closure of `magicitem.cpp` |
| S7 | `BGSSaveLoadManager::GetSaveDirectory` | the closure of `bgssaveloadmanager.cpp`, `_DAT_011a2ff0` and `FUN_0086d480` of `main.cpp`, and catalogue entries for its strings |
| S8 | a processor count of 1 set to 2 | as S6 |

At `891a44f50`, a link of `main` with any one of them composed, made as
`FalloutNV` links, loaded most of the game archive and left names
undefined. With the second-window check alone composed, no name was left
undefined.

When a window of the class exists, `WinMain` returns 0 at the second-window
check after these side effects of the skipped statements, which a process
that `main` starts does not have:

- S1 allocates a `MessageHandler` and sets the crash-log options.
- S2 to S5 write four log paths, the user folder with a suffix each, into
  their buffers.
- S6 and S8 write the processor count into its setting.
- S7 reads the INI path's settings with `GetPrivateProfileIntA`, creates the
  "My Games" folders, and writes a folder into each of the buffers that
  `FUN_0086d480` and `FUN_004dc110` return, `DAT_01202e98` and
  `DAT_01202fa0`, in both of its branches: the folders it created, or the
  string `g_011dece4_arg1` when a setting turns them off. It then deletes
  three log files that S2 to S4 named, and copies the default INI when the
  INI is missing.

When no window of the class exists, the original also has those effects
before the statements after the check, and `main` returns there.

## Unattended runs and message boxes

On a runner nobody answers a message box, so a run that shows one waits
until it is ended. The Windows documentation of `MessageBox` displays a box
on the caller's desktop; for a process without a visible desktop, such as a
service, only `MB_SERVICE_NOTIFICATION` moves it to the active desktop, and
`main` does not set it. `GetSystemMetrics(SM_REMOTESESSION)` is non-zero
only in a Remote Desktop Services client session and 0 in the console
session. Whether a hosted Windows runner runs its jobs in a client session,
the console session or a service session was not settled here. The CI runs
under "Not verified" show only that it was not a client session.

The tests do not depend on it. The decision's tests record the box. Before
`falloutnv.process_exit` runs `FalloutNV.exe`, the fixture makes the same
calls as `main`, in the same session, on a mutex name new to the run, with
the box recorded, and writes one line that names the decision. Only when it
names a remote session, with exit code 3, is the executable not run; the
test is then reported as skipped. A mutex that already exists under the
new name fails the test, and so does any result other than `Continue` with
exit code 0, such as an abnormal end with exit code 3. After `Continue`
the fixture also makes the second-window check, with the real
`FindWindowA` and the foreground call recorded, on the pack's class name,
which is the same name new to the run. A window of that class fails the
test, so a window on the runner cannot make `main` return early unnoticed.
Without a pack, `main` returns before `CreateMutexA` and can show no box, so
`falloutnv.process_exit.missing_pack` makes no such check. Each run of the
executable also has 60 seconds, so a run that waits fails instead of holding
the runner.

## Tests

`runtime.single_instance_strings` publishes two packs that the writer makes
and reads back each field with zeros after its string, and checks that a
publication keeps the owner's storage in place. It states at compile time
that the owner's storage is `SingleInstanceStrings` and that the writer takes
a `ValidatedPack` and neither the strings nor bytes.
`runtime.single_instance_strings.unpublished_read` expects a read before any
publication to abort.

`runtime.main_window_class` does the same for the main window class's
owner, and `runtime.main_window_class.unpublished_read` expects a read
before any publication to abort.

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

`runtime.second_window_check` runs the decision on both branches with the
search and the foreground call recorded. It checks the outcome, that the
search ran once for the field's own storage and its class name, that the
foreground call is made once on the window found, and that it is not made
when no window is found. It looks for and touches no real window.

`runtime.data_pack_startup` writes its packs into folders of its own under the
temporary folder. It accepts a complete pack, publishes its values and
returns the owners' published values. It refuses a missing pack, a missing
folder, a pack only in a folder below, a folder in place of the file, an
empty file, a corrupt and a truncated pack, a pack that records another
digest, a pack without C1's entry, a field without a zero byte, a pack
without the main window class and a class name without a zero byte. It
also refuses a pack of catalogue version 1 as setup prepared it before
version 2, packs of the catalogue versions next to the source's, a pack
whose C1 entry has version 2, and packs made for another build: envelope
version 2, native data contract 0 and build target 2, each with its CRC-32
stored again so that only the field is wrong. Each refusal returns one line
naming its class; for the versions and the build the line also names the
field the validator refused. `main` returns 2 for every refusal of the
stage. Each refused pack holds other values than the published ones, and
the published values stay unchanged, so no value of a refused pack is used.
Last it accepts a second complete pack and publishes its values.
`runtime.data_pack_startup.refused_publishes_nothing` and
`runtime.data_pack_startup.refused_publishes_no_window_class` expect a read
of either owner after a refused stage, with nothing published before, to
abort.

On Windows, `falloutnv.process_exit` copies the built `FalloutNV.exe` alone
into a folder of the test's own, writes a complete synthetic pack beside it
with `falloutnv_pack_fixture`, runs the copy from another working directory
and requires exit code 0. The fixture uses the production writer and records
the supported release's identity, so the pack claims that identity: it is
compared, not proved. Its strings are made up, and its mutex name and class
name are one name new to the run. No original executable is in the folder,
so the run can read values only from the pack. Exit code 0 does not tell a
refusal from `Continue`; the fixture's checks before the run show that both
decisions are `Continue`.
When that check reports a remote session, the test is skipped and `main`
does not run.
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

Catalogue version 2 appends `main_window_class.cpp` and then
`second_window_check.cpp` to the `game` archive, after
`data_pack_startup.cpp`, so the decision is now the first member listed and
the archive has 2,237 members. The `FalloutNV` link loads both, 24 game
members in all, and imports `FindWindowA` and `SetForegroundWindow` from
`USER32.dll` as well.

The standard link cells of the integration checks have no `user32.lib` on
their command line, so their lazy cells show `GetSystemMetrics`,
`MessageBoxA`, `FindWindowA` and `SetForegroundWindow` undefined; the
build's own link names `user32` and links.
Moving the cells to a command line with `user32.lib`, which at
`18b38af61` takes the forced unlimited cell from 35,079 to 35,039
undefined names, is a separate decision and is not taken here.

`src/main.cpp` now uses standard strings and paths, so its object defines the
scalar deleting destructors of `std::exception` and `std::bad_alloc`, and the
`FalloutNV` link keeps those copies instead of the ones in
`src/runtime/new.cpp`. Both free the object through the replaceable
`operator delete` of `new.cpp`. The copy that inlines it, 102 bytes, exists
only in the object of `new.cpp` that `FalloutNV` links directly; every copy
in the game archive is the 59-byte form that calls its sized form. The kept
copies are that form, so the content `FalloutNV` keeps now equals the
archive's. Removing the divergent copy of `new.cpp` is follow-up work outside
VEGAS-52.

## Not verified

- No Windows executable was run here. The two `falloutnv` tests and the
  Windows forms of the other tests run in CI only.
- No test uses a real pack, a pack prepared by setup or an original
  executable. The owner's private runs of 2026-11-13 (`setup.md`) ran this
  stage on packs setup prepared. The first, at catalogue version 1, gave
  status 0 beside its pack, and status 2 with no pack and with a corrupted
  copy. The second, at catalogue version 2, gave status 0 beside its pack,
  and status 2 with no pack, with a corrupted copy and beside a pack of
  catalogue version 1, which it refused for its catalogue version.
- Windows CI ran `falloutnv.process_exit` at `c7abe570e`, on 2026-11-12,
  and at `891a44f50`, `1b3b79d69`, `534a1d77c` and `d5d1d60ec`, on
  2026-11-13. Each time it passed and CTest did not report it as skipped,
  so the fixture's check did not name a remote session on those runners.
  Which kind of session a hosted Windows runner gives its jobs is still
  not known, and a later runner may report a remote session.
- No run has found a window of the class, so the `AlreadyOpen` branch of
  `main` has run only as the decision's test, with the calls recorded.
