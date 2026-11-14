# The data pack stage of main (VEGAS-52)

## Scope

This is increment 2 of `data-pack-catalogue.md`, complete, with catalogue
version 3 of increment 5: `main` reads the data pack, validates it,
publishes C1, the four strings of the single-instance and remote-session
checks, the four log path suffixes and the main window class to their
native owners, and runs their consumers, the composed first statements of
`0x0086a850`, its statements S2 to S5, the log paths, and its second-window
check. It follows ADR 0001, the decisions D1 to D10 of that page and the
rulings of 2026-11-13 on catalogue version 2. Under D3 the pack stage
entered `main` only together with C1's consumer.

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
6. On the log path suffixes the stage returns, `WinMain`'s statements S2
   to S5: the four log-path builders `FUN_00c3bb90`,
   `fnv_00c3bbe0::FUN_00c3bbe0`, `FUN_00c3bc30` and
   `fnv_00c3bc80::FUN_00c3bc80`, each passed its suffix's field, in
   `WinMain`'s order ("The log paths"). Of the eight statements that
   `WinMain` runs between the checks of step 5 and the next one, these four
   are composed and S1, S6, S7 and S8 are skipped ("Skipped statements").
7. On the class name the stage returns, the second-window check of
   `WinMain`: `fnv::startup::CheckSecondWindow` with `FindWindowA` and no
   window name as the search and `SetForegroundWindow` as the foreground
   call. When a window of the class exists, it returns 0 after bringing it
   to the foreground, as `WinMain` does.
8. Otherwise it returns 0, because nothing of `WinMain` after the
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
`fnv::startup::PublishSingleInstanceStrings`, the log path suffixes with
`fnv::startup::PublishLogPathSuffixes` and the main window class with
`fnv::startup::PublishMainWindowClass`. On success it returns
`PublishedPackValues`, the published values read back through
`PublishedSingleInstanceStrings`, `PublishedLogPathSuffixes` and
`PublishedMainWindowClass`. Their
consumers get them only from that result, so they cannot read them before
they are published. Validation succeeds for the whole pack before any
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
supported original succeeds. A pack of catalogue version 1 or 2, which has
no log path suffixes, is refused for its catalogue version, so setup must
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

## The log path suffixes' owner

`fnv::startup::PublishLogPathSuffixes` and
`fnv::startup::PublishedLogPathSuffixes`, in
`include/fnv/log_path_suffixes.h`, are the native owner of the log path
suffixes, the `LOGS` entry. Its storage is one `fileformat::LogPathSuffixes`,
the declaration whose four capacities fix the entry's size (D6). The one
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
and the eight statements S1 to S8, of which `main` composes S2 to S5:

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

## The log paths

`WinMain`, as `FUN_0086a850` transcribes it, runs S1, the crash-log
configuration, after the remote-session check, and then S2 to S5, each on
the string the original stores at one address:

1. `FUN_00c3bb90`, the string at `0x01082a38`
2. `fnv_00c3bbe0::FUN_00c3bbe0`, the string at `0x01082a28`
3. `FUN_00c3bc30`, the string at `0x01082a10`
4. `fnv_00c3bc80::FUN_00c3bc80`, the string at `0x01082a00`

`main` makes the same four calls in that order, each on the field of
`PublishedLogPathSuffixes` that holds the string at that address (VEGAS-127):
`firstSuffix`, `secondSuffix`, `thirdSuffix` and `fourthSuffix`. Each
builder, in `src/fallout/misc/log_paths.cpp`, copies the user folder buffer
`DAT_01202fa0` into its own buffer of 260 characters with `strcpy_s` and
appends its suffix with `strcat_s`: `DAT_01202c50`, `DAT_01202b48`,
`DAT_01202a40` and `DAT_01202938`, in that order. Since VEGAS-130 all four
call the functions of `fnv::crt` (`src/runtime/crt.cpp`), which leave the
buffer empty when a string does not fit ("Log path rulings"); none can
here. The builders call nothing else: no file is opened, written or
deleted. The user folder is still empty when `main` calls them, as it is in `WinMain`
at this point: S7, which fills it, runs after S2 to S5, and nothing before it
writes the buffer. So each buffer holds its suffix alone, and a suffix takes
at most 24 bytes with its zero byte. `FUN_0086a850` makes S1 and the four
calls a second time after the second-window check, once the user folder is
set; `main` does not compose that second run, so the paths with the user
folder are not built yet.

S2 to S5 read nothing that S1 writes: S1 sets the crash-log options and the
message handler, and the builders read only the user folder and their
argument. Nothing in the process reads the four buffers yet.

Since VEGAS-130 `FUN_0086a850` passes the same four fields of
`PublishedLogPathSuffixes` in both of its call groups, as it reads C1's
strings and the class name from their owners. It reads the owner once,
where the first group passes the first suffix, and the second group uses
the same reference; its calls, their order and its branches are
unchanged. It passed the addresses of the legacy one-byte definitions
`UNK_01082a38`, `UNK_01082a28`, `UNK_01082a10` and `UNK_01082a00` of
`fallout/misc/main.inc`. The native data composition retires those four
lines (`native-data-ownership.md`), and no object of the build defines or
refers to the four names. The recipe keeps their keys in `main.cpp`'s
entry, under which setup reads the strings. `FUN_0086a850` still links
into no program.

## Skipped statements

Under ruling A of 2026-11-13, `main` composes the statements of
`0x0086a850` in their order among those it composes, and may skip a
statement whose closure cannot link yet. Between the remote-session check
and the second-window check, `FUN_0086a850` runs eight statements. `main`
composes S2 to S5 ("The log paths") and skips the other four. The order is
the transcription's: the original's code section is encrypted in the stored
file, so it was not compared with instructions.

| | Statement | Prerequisite |
| --- | --- | --- |
| S1 | `FUN_00c3bd30(1, ...)`, the crash-log configuration, with the values of three `Setting` objects and the callback `FUN_0086a580` | the stand-in `Setting86::FUN_00408d60`, which no object defines; a native `MessageHandler` in place of the legacy virtual table `DAT_010c14a8` that its callee `0x00c3c460` stores; the closure of `blk_00c20000_od.cpp` |
| S2 to S5 | `FUN_00c3bb90`, `fnv_00c3bbe0::FUN_00c3bbe0`, `FUN_00c3bc30` and `fnv_00c3bc80::FUN_00c3bc80`, the four log paths | composed since VEGAS-127, not skipped |
| S6 | `GetSystemInfo`, then the processor count into the setting `g_011c3ea4` through `FUN_0043d4d0` | a native owner of that setting: generated data defines it, and its unit's one startup initializer builds it and reads original data (D2); for a native setting, `INISettingCollection`'s constructor, which no object defines (the row at `0x0044f600` is a stand-in that stores a legacy table address); since VEGAS-129 the accessor with `DAT_01202800`, `Setting::IsPrefSetting`, and Setting's constructors with its destructor are each in a unit of their own (below) |
| S7 | `BGSSaveLoadManager::GetSaveDirectory` | the closure of `bgssaveloadmanager.cpp` and `_DAT_011a2ff0` of `main.cpp`, and catalogue entries for its strings; `FUN_0086d480`, `TaskQueueInterface::CopyStringToBuffer` and `FUN_00406d00` are in units of their own since VEGAS-128; since VEGAS-131 `FUN_00406d00` reads its variable arguments with `va_start` (`docs/variadic-lists.md`) |
| S8 | a processor count of 1 set to 2 | as S6 |

When S7 is composed, S2 to S5 stay before it, in the order of
`WinMain`'s first call group (VEGAS-130). S7 passes three of the buffers
that S2 to S4 fill to `DeleteFileA`, so composed before them it would get
empty buffers in place of the paths `WinMain` deletes. S7 also creates
folders, which the `falloutnv` tests' folder check now sees ("Tests").

The coordinator named four prerequisites for S6 and S8 (VEGAS-52): a
native owner of the setting, the members a native setting needs, a native
`DAT_01202800`, and the accessor's offset. `DAT_01202800` is met (below),
and so is the offset. The
accessor read 4 bytes into the setting, the value's offset in the 32-bit
layout, which on windows-x64 is the upper half of the setting's table
pointer. Since VEGAS-111 it reads the value at 8. Since VEGAS-115 S6's
call, which writes the processor count, and S8's two, which read it and
write 2, take the shared `Setting` (docs/setting-value-offset.md). S6 and
S8 stay skipped for a native owner of the setting and, for a native
setting, the constructor of `INISettingCollection`.

VEGAS-129 moved the accessor and what S6 and S8 reach of `Setting` into
small units, so that a link that reaches them no longer loads
`magicitem.cpp`, `bsaudio.cpp`, `tesactorbasedata.cpp` or `setting.cpp`
for them:

- `src/fallout_shared/setting_value_accessor.cpp` defines the accessor
  `FUN_0043d4d0` and `DAT_01202800`, the `int` it returns for a null
  setting. They were defined by `magicitem.cpp` and, through the native
  data composition, by generated data (docs/setting-value-offset.md).
- `src/fallout_shared/setting_is_pref_setting.cpp` holds the row at
  `0x0047c850`, a function that returns false, moved from
  `tesactorbasedata.cpp`, and defines `Setting::IsPrefSetting` with the
  same body. Slot 1 of Setting's table in generated data,
  `?vftable_SettingBase_01012120`, holds that address, and
  `include/fnv/setting_class.h` declares `IsPrefSetting` at that slot,
  after the destructor. The recipe keys `?IsPrefSetting@Setting@@UAE_NXZ`
  to the address in that unit's entry only, as the owner of a folded
  address keys its other identities. No object defined it before; it
  was an undefined name of the forced link.
  `objects.setting_is_pref_setting` fails unless one member defines it
  and its body clears `eax`.

  30 virtual tables of the archive name `IsPrefSetting` at slot 1 and
  now reach this body: Setting's own table and the six `SettingT` tables
  of `src/unmapped/setting.cpp`; 21 tables of generated global objects
  in `src/generated/`, 14 in `global_object_initializers.cpp`, three in
  `global_object_initializers2.cpp` and four in
  `global_object_initializers_o2.cpp`; and two of
  `setting_eh_initializers.cpp`. Generated data confirms slot 1 at
  `0x0047c850` for two of them: Setting's table at `0x01012120` and the
  one at `0x01012114`, which it names after `0x00404a00`, the destructor
  of `SettingT<GameSettingCollection>`. The others are unconfirmed, among
  them the tables the recipe keys to `0x01017720` and `0x01022738`
  (`SettingT<INISettingCollection>` and
  `SettingT<INIPrefSettingCollection>`), where generated data holds no
  table. Whether the original's `INIPrefSetting` overrides
  `IsPrefSetting` is an open question (VEGAS-133), and nothing composed
  may rely on its value for a pref setting.
- `src/unmapped/setting_lifetime.cpp` defines Setting's five
  constructors and its destructor, moved from `src/unmapped/setting.cpp`.
  They move together because the unit that defines them emits Setting's
  table and `??_GSetting`; that function keeps one definition, of the
  same 118 bytes. In `setting.cpp` 29 `SettingT` members, at the unit's
  flags, now call the constructor or the destructor where they inlined
  its body, with the same other calls in the same order and no new
  unwind funclet.

Measured on the windows-x64 cross build of `087a5a0c1` and of each move,
built from one source path; nothing was run on Windows. Each moved
section is identical with the unit's flags, with `/Ob0` and with
`/Od /Gy`. The forced unlimited link cell with `user32.lib` goes from
35,014 undefined names to 35,013, without `Setting::IsPrefSetting`;
every other list of the four cells is unchanged, no name gains a second
content, and 519 names of the archive and 521 of `FalloutNV`'s link
inputs have differing definitions, as before. `link.function_level`
accepts `FalloutNV` with no name unresolved after each move.

At `891a44f50`, a link of `main` with any one of them composed, made as
`FalloutNV` links, loaded most of the game archive and left names
undefined. With the second-window check alone composed, no name was left
undefined.

Since VEGAS-126 `FalloutNV` links at function level, with a check that
every name left unresolved is referenced only from discarded sections
(docs/function-level-link.md). A scratch composition of S2 to S8, not
committed and never run, linked that way on `1a4404c01` leaves 1,294 names
live: the check reports 1,290 as LIVE and four that it cannot classify, and
a strict relink that gave each unresolved name a distinct value writes the
values of all 1,294 into its executable. The check counts 34,719 names
unresolved, three of them import slots that hold zero, whose four
references are all discarded. A trace of the kept sections, a model built
from the map and the objects, assigns 869 + 56 of the 1,294 to the startup
initializers of `src/generated` units. The 56 are among 77 that a first
trace left untraced: they are reached through `??_E`, a weak external that
falls back to the deleting destructor `??_G`, which that trace did not
follow. By the unit that reaches them, 30 come through
`aggregate_initializers_o2.cpp`, 26 through
`global_object_initializers.cpp`, 19 through `tesscriptrunmanager.cpp` and
2 through `bgsentrypointfunction.cpp`. Giving the statements' data native
owners alone removes none of the 1,294: by the member model,
`magicitem.cpp`, `blk_00c20000_od.cpp` and `bgssaveloadmanager.cpp` each
load 2,011 of the 2,020 members that the link loads. By the section model
of the trace, the composed statements' own section closure is 805 sections
in 41 objects and needs one unresolved name, `SHGetFolderPathA`. So M1
needs either the 1,294 names, or new small owners for the functions and
data that the statements reach plus the link libraries their imports need.
VEGAS-127 took the second route for S2 to S5, which `main` now composes:
the link loads 28 game members and leaves no name unresolved ("Build").

When a window of the class exists, `WinMain` returns 0 at the second-window
check after these side effects of the skipped statements, which a process
that `main` starts does not have:

- S1 allocates a `MessageHandler` and sets the crash-log options.
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

## The user folder buffer

`DAT_01202fa0` is the user folder buffer (VEGAS-109's log-path buffer).
S7 writes it through `FUN_004dc110`, which returns it, and S2 to S5 and the
two functions that build the Controls INI path,
`ControlsIniLoader::LoadControlsFromIni` and `FUN_00a22e10`, copy it. The
recipe binds the next address 260 bytes after it, and its users copy at
most 260 bytes into or out of it. It was defined as an 8-byte pointer:
`FUN_00c3bb90`, `FUN_00c3bc30` and `LoadControlsFromIni` passed the
pointer's value, null, to `strcpy_s` as the source, and the others read or
wrote up to 260 bytes at the 8-byte object.

Since VEGAS-109 it is one array of 260 characters, declared in
`include/fnv/symbols_01202000.h` and defined, with `FUN_004dc110`, in
`src/fallout/misc/user_folder.cpp` since VEGAS-127 (before, in
`blk_004c0000_od.cpp`), and
every user reads it as that array without a cast, as each reader's
declaration gave it before `3f0599801` (the definer excepted). `FUN_004dc110`
returns it as `char *`, the type its callers declared then, so its recipe
name is respelled. The buffer's recipe name is unchanged: the 32-bit
spelling of a character pointer and of a character array is the same.
`objects.log_path_buffer` fails when one of the seven functions again
refers to the pointer, addresses the buffer past its 260 bytes or no longer
refers to it. It does not catch a smaller array under the same name; a
`static_assert` in `FUN_004dc110` holds the definition at 260 bytes.

VEGAS-112 covers two other buffers of S2 to S7 with the same defect.
Generated data defined both, so each repair goes through the audited
composition (`native-data-ownership.md`). Both are repaired:

- `DAT_01202b48`, the destination of S3, was defined as one byte by
  `staging/blk_00c20000_od.inc`. S3 writes up to 260 bytes there, and the
  recipe binds the next address 264 bytes after it. In the object of
  `blk_00c20000_od.cpp` at `c3ad69b43` the byte lay at the start of `.bss`
  and `DAT_01202a40`, the buffer of S4, began 16 bytes after it, so a write
  of 260 bytes would have run over the first 244 bytes of S4's buffer. This
  is read from the object, not from a linked image. It is now one
  array of 260 characters, declared in `include/fnv/symbols_01202000.h` and
  defined beside `FUN_00c3bbd0`, which holds the definition at 260 bytes
  with a `static_assert`: by `blk_00c20000_od.cpp`, and since VEGAS-127 by
  `src/fallout/misc/log_paths.cpp`. The composition retires
  the generated line. The name keeps C linkage, so its recipe key
  `_DAT_01202b48` is unchanged. S3 writes the array without a cast.
  `FUN_00c3bbd0` returns it as `char *`, the type its caller
  `GetSaveDirectory` declared before `3f0599801`, instead of `void *`, so
  its recipe name is respelled, and the caller passes it to `DeleteFileA`
  without a cast. `objects.path_buffer_extents` fails when the definition
  reaches fewer than 260 bytes before the next symbol of its section, as the
  byte did.
- `DAT_01202e98`, which `FUN_0086d480` returns, was defined as a 4-byte
  `int` by `fallout/misc/main.inc`, which `main.cpp` includes. S7 copies a
  folder of up to 260 characters there in both of its branches,
  `BootInit::FUN_0086cf20` passes it to the plugin list reader, which
  copies up to 260 characters out of it, and the recipe binds the next
  address, the user folder buffer, 264 bytes after it. In the object of
  `main.cpp` at `4567abc37` the `int` lay 80 bytes into a `.bss` of 257
  bytes, so a write of 260 bytes would have run over the 44 symbols after
  it and 83 bytes past the end of that section. This is read from the
  object, not from a linked executable. It is now one array of 260
  characters, defined by `main.cpp` beside `FUN_0086d480`, which holds the
  definition at 260 bytes with a `static_assert`. The composition retires
  the generated line. The name has C++ linkage, so its recipe key is
  respelled from `?DAT_01202e98@@3HA` to `?DAT_01202e98@@3PADA`.
  `FUN_0086d480` returns it as `char *`, the type `GetSaveDirectory`'s
  unit declared before `3f0599801`, instead of `int *`, so its recipe name
  is respelled. S7's two copies and the plugin list call pass it without a
  cast. `objects.path_buffer_extents` fails when the definition reaches
  fewer than 260 bytes before the next symbol of its section; on the `int`
  form the object defines no array of that name, and the check stops with
  exit status 2. In the object of `main.cpp` the array starts at the same
  offset, and the 44 symbols after it lie 256 bytes further on.
  Since VEGAS-128 the array and `FUN_0086d480` are defined in
  `src/fallout/misc/app_data_folder.cpp`, a unit of their own, and the
  `.bss` of `main.cpp` is 257 bytes. `FUN_0086d480` calls nothing and is
  declared `noexcept`, so `BootInit::FUN_0086cf20` in `main.cpp` still
  compiles its call as one that cannot throw.

S5's builder wrote `DAT_01202938`, an array of 260 characters, through a
cast to an array of 256; it now passes the array.
`FUN_00c3bb80` in `tesfile.cpp` returned `DAT_01202c50`, the buffer of S2,
an array of 260 characters, through a cast to `int *`, and its two callers
cast the result back: `GetSaveDirectory` to `char *` for `DeleteFileA`,
and the destructor at `0x00c3bda0` in `blk_00c20000_od.cpp` to
`const char *`. It now returns the array as `char *`, so its recipe name
is respelled, and both callers pass it without a cast. The destructor also
passes it to `GetFileSize`, a stand-in of that unit that no object
defines; its first parameter became `char *` with it, and its recipe key
is respelled. The objects of the three units are the same as before once
the two names are respelled.

A scratch composition of S2 to S5 into `main`, not committed, was linked
as `FalloutNV` links, on `11d59dc97` with and without this repair. Both
links loaded 2,011 members of the game archive and left the same 34,719
names undefined, because a lazy link loads whole members: the builders were
in `blk_00c20000_od.cpp`, the user folder in `blk_004c0000_od.cpp` and
`DAT_01202c50` in `tesfile.cpp`.

VEGAS-127 moved them into two small units: `DAT_01202fa0` and
`FUN_004dc110` into `src/fallout/misc/user_folder.cpp`, and the four
builders, `FUN_00c3bb80`, `FUN_00c3bbd0`, `FUN_00c3bc20` and the four
buffers into `src/fallout/misc/log_paths.cpp`, their names, types and
bodies unchanged and each moved section the same in bytes and relocations.
The recipe's function rows moved with the bodies to entries for the new
sources. Generated data defined `DAT_01202938`, `DAT_01202a40` and
`DAT_01202c50`; the native data composition retires those lines
(`native-data-ownership.md`), and `log_paths.cpp` defines the three arrays.
`FalloutNV` now composes S2 to S5 ("The log paths") and loads four game
members more than before: `user_folder`, `log_paths`, `crt` and the
suffixes' owner.

## Log path rulings

VEGAS-130 asked for two rulings before the log paths are used. The
coordinator made both on 2026-11-14; this section records them, the
evidence they rest on and what changed. Measured on the windows-x64 cross
build, built from one source path. Nothing was run on Windows here except
the private run of setup below.

### Overflow once the user folder is not empty

Ruling: the four builders behave alike and call `fnv::crt::strcpy_s` and
`fnv::crt::strcat_s`, which leave the buffer empty and never truncate. It is
the project's recorded treatment of `0x00ec65a6` and `0x00ec6bd2`
(`runtime-library-map.md`, VEGAS-23) and the one S7 already uses. S7's own
appends follow the same ruling.

| Statement | Builder | Its object calls | Linked from |
| --- | --- | --- | --- |
| S2 | `FUN_00c3bb90` | `fnv::crt::strcpy_s`, `fnv::crt::strcat_s` | `crt.cpp` of the game archive |
| S3 | `fnv_00c3bbe0::FUN_00c3bbe0` | `fnv::crt::strcpy_s`, `fnv::crt::strcat_s` | `crt.cpp` of the game archive |
| S4 | `FUN_00c3bc30` | `fnv::crt::strcpy_s`, `fnv::crt::strcat_s` | `crt.cpp` of the game archive |
| S5 | `fnv_00c3bc80::FUN_00c3bc80` | `fnv::crt::strcpy_s`, `fnv::crt::strcat_s` | `crt.cpp` of the game archive |

Before VEGAS-130, S2 and S4 called the C runtime's `strcpy_s` and
`strcat_s`, declared at global scope by the Windows SDK's `ucrt/string.h`
through `<cstring>`, and linked from `libucrt`; S3 and S5 already called
`fnv::crt`. The split came from the transcription, which declared a
stand-in `strcpy_s` for S2 and S4 and stand-ins named `_strcpy_s` for S3
and S5: `d328ed42c` moved the `_strcpy_s` calls to `fnv::crt`, and
`42a7e4c28` removed the other stand-in declarations, which left S2 and S4
on the runtime's functions. The global functions do not exist on the
macos-arm64 and linux-x64 build targets, and a host build on macOS
failed to compile `log_paths.cpp` for that reason; it now compiles there.

Now S2 and S4 call `fnv::crt` and `log_paths.cpp` no longer includes
`<cstring>`. In each of the three variants of the object proof the bytes
of the two builders are unchanged and their two calls change only their
target. `FalloutNV`'s link no longer loads `strcat_s.obj` of `libucrt`; it
still loads `strcpy_s.obj`, which four members of the C runtime that it
loads call. Its imports are unchanged. `objects.log_path_copies`
(`tests/checks/objects_log_path_copies.cmake`,
`tools/function-relocations/log-path-copies.tsv`) fails when a builder
calls the C runtime's `strcpy_s` or `strcat_s` again, or no longer calls
both `fnv::crt` functions.

When the path does not fit in its 260 characters, `fnv::crt::strcpy_s`
stores a zero byte at the start of the buffer and returns `ERANGE`, and
`fnv::crt::strcat_s` does the same for the whole buffer. The builders
ignore the result, so the buffer holds an empty path and the process goes
on. `runtime/crt.h` states this as the project's rule: where the Microsoft
function would call the invalid parameter handler, the project's returns
the error code. By the ruling, the consumers of the paths, `DeleteFileA`
and the opening of a log, treat an empty path as a failure; no consumer is
composed yet, so this was not observed.

No overflow can happen in the first call group: the user folder is still
empty and a suffix holds at most 23 characters. In the second group,
after S7, the folder holds what S7 copied there, at most 259 characters,
and the path overflows when the folder and the suffix together reach 260.
Which folder lengths real profiles give was not measured. S7 copies with
`TaskQueueInterface::CopyStringToBuffer`, which calls
`fnv::crt::strcpy_s`, and appends with `fnv::crt::strcat_s` in
`bgssaveloadmanager.cpp`, so its copies and appends already follow the
ruling.

The recorded difference from the inferred original: the original most
plausibly ends the process on such an overflow, and this source leaves
an empty path. The inference: the recipe binds the copy and the append of
all four builders to `0x00ec65a6` and `0x00ec6bd2` (the keys of
`log_paths.cpp`'s entry), which `runtime-library-map.md` identifies as
`strcpy_s` and `strcat_s` of Microsoft's C runtime, linked statically.
Microsoft documents that these functions invoke the invalid parameter
handler when the destination is too small, and the default handler ends
the process; the SDK objects this build uses store a zero byte, set
`errno` to `ERANGE` and call `_invalid_parameter_noinfo`, which ends the
process through `_invoke_watson`. The recipe binds
`__invalid_parameter_noinfo` (`0x00ec7c56`) and no name of
`_set_invalid_parameter_handler`, so no handler is known to be installed.
The original's code section is encrypted in the stored file and none of
its instructions were read.

### Path separators in a pack suffix

Ruling: `ValidatePack` refuses a log path suffix that holds a path
separator, a drive colon or a control character, or a `..` part, and
setup inherits the refusal through `PrepareDataPack`. Its precondition was
a private run that records, as yes or no per suffix only, whether the supported
original's four strings hold one of these; had one held one, the rule
would have narrowed to refusing a drive colon, a leading separator and any
`..` part.

Why it matters: each builder appends the suffix to the user folder as it
is and adds no separator, so the suffix decides where the path points. In
`WinMain`, as transcribed, S7 runs after the first call group and passes
three of the four buffers to `DeleteFileA`; those buffers then hold the
first group's paths, built from an empty user folder, so each is its
suffix alone, relative to the working directory, where `..\b`, a leading
`\` or `C:\b` would name a file outside it.

`DecodeLogPathSuffixes` (`fileformat/pack_validation.cpp`) checks each
suffix right after its zero byte and refuses it, with the problem
`SuffixPath` of `PackCatalogueError`, when it holds `\` or `/`, a colon
anywhere (a drive or a stream), or a byte below 0x20, or when it is `..`:
with the separators refused, a `..` part is the whole suffix. The message
names the field and the reason, never the suffix. An empty suffix, one of
dots and spaces other than `..`, such as `.`, `...` or `. .`, and any
other byte value are accepted. `FalloutNV`'s stage turns every
`FormatError` of the validator into its line and status 2, so it refuses
such a pack as any other invalid pack; no test runs the stage on one.

Setup copies each suffix as it is stored and does not look at its
characters. Step 6 of `PrepareDataPack`, the validator, refuses its pack
with `StagedPackError`, status 7; the step is
`setup::staged::CheckWrittenPack`, so that `setup.prepare_pack` can run it
on packs it writes. `fileformat.pack_catalogue` and `setup.prepare_pack`
hold the crafted cases (`data-pack-validation.md`).

Private run, 2026-11-14: setup built from `fe8d02602`, the commit that
added the rule, ran once on a copy of the supported original in a new
empty folder. It ended with status 0 and printed
`vegas-data.pack was written beside FalloutNV.exe`; the pack existed and
was 628 bytes. Since setup validates the pack it writes, and then the
installed file, with the rule, none of the original's four suffixes
holds a separator, a colon, a control character or is `..`. Nothing of the
strings was recorded.

What the rule leaves: a suffix still decides the file name that the
builder appends to the user folder. Windows' path normalisation trims
trailing periods and spaces from the last part of a path, so an accepted
name of dots and spaces, such as `...` or `.. `, may not name the file it
spells; what each resolves to was not checked. A pack made by hand or by a
test can hold such a name. The consumers that open, write or delete a file
at these paths are composed later and must be read against this.

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
before any publication to abort. `runtime.log_path_suffixes` and
`runtime.log_path_suffixes.unpublished_read`
(`tests/checks/runtime_log_path_suffixes.cmake`) do the same for the log
path suffixes' owner.

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
without the main window class, a class name without a zero byte, a pack
without the log path suffixes and a suffix without a zero byte. It also
refuses a pack of catalogue version 1 as setup prepared it before version
2, and one of catalogue version 2 as setup prepared it before version 3,
each for its catalogue version, packs of the catalogue versions next to the
source's, a pack
whose C1 entry has version 2, and packs made for another build: envelope
version 2, native data contract 0 and build target 2, each with its CRC-32
stored again so that only the field is wrong. Each refusal returns one line
naming its class; for the versions and the build the line also names the
field the validator refused. `main` returns 2 for every refusal of the
stage. Each refused pack holds other values than the published ones, and
the published values stay unchanged, so no value of a refused pack is used.
Last it accepts a second complete pack and publishes its values.
`runtime.data_pack_startup.refused_publishes_nothing`,
`runtime.data_pack_startup.refused_publishes_no_window_class` and
`runtime.data_pack_startup.refused_publishes_no_log_path_suffixes` expect a
read of any of the three owners after a refused stage, with nothing
published before, to abort.

On Windows, `falloutnv.process_exit` copies the built `FalloutNV.exe` alone
into a folder of the test's own, writes a complete synthetic pack beside it
with `falloutnv_pack_fixture`, runs the copy from another working directory
and requires exit code 0. The fixture uses the production writer and records
the supported release's identity, so the pack claims that identity: it is
compared, not proved. Its strings, the log path suffixes among them, are
made up, and its mutex name and class name are one name new to the run. No
original executable is in the folder,
so the run can read values only from the pack. Exit code 0 does not tell a
refusal from `Continue`; the fixture's checks before the run show that both
decisions are `Continue`.
When that check reports a remote session, the test is skipped and `main`
does not run.
`falloutnv.process_exit.missing_pack` writes the pack only in the working
directory and requires exit code 2 and the missing pack reported on the
standard error stream. Since VEGAS-127 both tests also require that the
test's folder holds only the copy and the pack after the run, so a
statement of `main` that wrote a file beside the executable or in the
working directory would fail them. Since VEGAS-130 the check lists folders
too and expects only the two the test makes, `executable` and `working`,
so an empty folder left in the test's folder fails them as well; files and
folders elsewhere are not looked for.
Neither test shows the engine link, startup or boot, and neither reads the
four log path buffers: nothing reports them.

`falloutnv.pack_folder_listing`
(`tests/checks/falloutnv_pack_folder_listing.cmake`) runs the check script
on a stand-in program and fixture, POSIX shell scripts, in both modes. A
run that leaves nothing must pass; an empty folder beside the executable,
in the working directory or inside a new folder, and a file, must each
fail with the check's message. The check before VEGAS-130 passed the three
empty folders, so the test fails on it. It is registered on hosts other than Windows only, so no CI job runs it
(the only CI job runs on Windows), and it runs no `FalloutNV.exe`.

Plan for files outside the test's folder, for when S7 is composed; not
implemented. S7, as transcribed, reads the setting that turns the My Games
folders on or off from INI files named relative to the working directory,
and then either creates folders under the user's Documents folder or takes
a folder from a setting; it deletes three files named by the first call
group's paths, which are relative to the working directory
("Log path rulings"), and copies the default INI when the INI is missing.

1. The fixture writes an INI into the working folder that turns the My
   Games folders off, so what S7 creates, deletes and copies falls under
   the test's folder, which the check lists. Whether the folder the
   setting then names lies inside the working folder is to be read from
   the composed code first.
2. A second run with the folders on lists the My Games folder that S7
   creates under Documents before and after the run, requires only the
   entries S7 is expected to create, and removes only what the run
   created. On a hosted runner the profile is discarded after the job.
3. Any other path the composed statements reach (the default INI's
   source, the INI files) is listed before and after the run in the same
   way, or the test states it as a blind spot.

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

Catalogue version 3 appends `log_path_suffixes.cpp` to the `game` archive
after `second_window_check.cpp`, so the suffixes' owner is now the first
member listed. With the two units of VEGAS-127's moves,
`src/fallout/misc/user_folder.cpp` and `src/fallout/misc/log_paths.cpp`,
listed in `src/fallout/sources.cmake`, the archive has 2,240 members. The
`FalloutNV` link loads 28 game members: the 24 before, `log_path_suffixes`,
`log_paths`, `user_folder` and `crt`. Its imports are unchanged: the C
runtime is linked statically, and `strcpy_s` and `strcat_s` come from it.
`link.function_level` accepts it with no name unresolved, and a strict link
of the same inputs, without `/FORCE:UNRESOLVED` and `/OPT:REF`, succeeds
with no undefined name and writes the same executable apart from the
header timestamp and checksum (cross build, measured at VEGAS-127's head).

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
  executable. The owner's private runs of 2026-11-13 and 2026-11-14
  (`setup.md`) ran this stage on packs setup prepared. The first, at
  catalogue version 1, gave
  status 0 beside its pack, and status 2 with no pack and with a corrupted
  copy. The second, at catalogue version 2, gave status 0 beside its pack,
  and status 2 with no pack, with a corrupted copy and beside a pack of
  catalogue version 1, which it refused for its catalogue version. The
  third, at catalogue version 3 on 2026-11-14, gave status 0 beside its
  pack, and status 2 with no pack, with a corrupted copy and beside a pack
  of catalogue version 2, which it refused for its catalogue version.
- Windows CI ran `falloutnv.process_exit` at `c7abe570e`, on 2026-11-12,
  and at `891a44f50`, `1b3b79d69`, `534a1d77c` and `d5d1d60ec`, on
  2026-11-13. Each time it passed and CTest did not report it as skipped,
  so the fixture's check did not name a remote session on those runners.
  Which kind of session a hosted Windows runner gives its jobs is still
  not known, and a later runner may report a remote session.
- No run has found a window of the class, so the `AlreadyOpen` branch of
  `main` has run only as the decision's test, with the calls recorded.
- No Windows executable was run here. The two `falloutnv` tests in CI run
  S2 to S5 on made-up suffixes, and they do not read the buffers. The
  owner's third private run (`setup.md`) is inferred to have run them on
  the suffixes setup read from an original executable. It shows only that
  `main` then returned status 0 and that no file appeared in the
  executable's folder or the working folder. Nothing has read the four
  paths.
- The other repaired users of the user folder buffer, of `DAT_01202b48`, of
  `DAT_01202e98` and of `DAT_01202c50` have not run: `FalloutNV` does not
  load their members and no test calls them. Their checks read the objects
  only.
- `FUN_0086a850` has not run with the owner's suffixes: it links into no
  program. Its change and the retirement of the four one-byte definitions
  were measured on the windows-x64 cross build only (VEGAS-130).
- The folder check that lists folders has not run on Windows here; its
  test, `falloutnv.pack_folder_listing`, runs on other hosts with stand-in
  scripts only.
- No run has built a log path that does not fit, and none has passed an
  empty path to a consumer. That the builders leave the buffer empty
  rests on `fnv::crt`'s functions, whose test `runtime.crt` runs on
  Windows only, and on the object proof of VEGAS-130.
- The refusal of a suffix that holds a separator, a colon or a control
  character, or is `..`, ran only in the host tests of the validator and
  of setup's step 6, on crafted packs. The private run of 2026-11-14 shows
  that setup accepts the supported original's suffixes under the rule;
  `FalloutNV.exe` was not run on the pack it wrote.
