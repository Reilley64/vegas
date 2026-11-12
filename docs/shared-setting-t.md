# SettingT::Bool on the shared template

VEGAS-70. The recipe has one function row at `0x00408d60`, 53 bytes, in
`src/fallout/ai/processlists.cpp`:
`SettingT<INISettingCollection>::Bool`. It returns the address of the
setting's value. The unit defined it on a copy of `SettingT` of its own: a
class with a pointer field where the vtable of `Setting` is, and a copy of
`SETTING_VALUE`. The shared template in `include/SettingT.h` declared no
`Bool`.

The decision of 2026-11-12, recorded on the ticket: `Bool` is declared on
the shared `SettingT<Collection>` template, and the unit with the row
defines it there. The `SpectatorPackage` item of the ticket waits for a
shared `TESPackage` declaration and is not part of this change.

Everything below was measured on the windows-x64 cross build of 89377df96
and of the two code commits, built from one source path.

## What changed

1. `SettingT` moves from `include/SettingT.h` to `include/fnv/setting_t.h`,
   which needs only `Setting.h`. `SettingT.h` includes it. The template is
   unchanged.

   The move is needed because `SettingT.h` declares
   `template <class T> class NiTPrimitiveArray;` with one template
   parameter. `processlists.cpp` declares the class with two, the second
   with a default, and cannot include `SettingT.h`. Correcting that
   declaration would change the mangled names of `GetViewerStrings` that
   the object of `src/unmapped/setting.cpp` holds, so it was left alone.
2. `setting_t.h` declares `SETTING_VALUE* Bool();` on the template, next to
   the address. `processlists_decls.h` drops its `SETTING_VALUE` and its
   `SettingT` and includes `fnv/setting_t.h`. The definition in
   `processlists.cpp` is unchanged: an explicit specialisation for
   `INISettingCollection`.

The unit's `SettingT<INISettingCollection>`, by the compiler's record
layout:

| | Size | Fields |
| --- | --- | --- |
| Before | 16 | `void* vptr_` at 0, `uValue` at 8 |
| After, the shared template | 24 | the vtable pointer of `Setting` at 0, `uValue` at 8, `pKey` at 16 |

`uValue` is at 8 in both, so the body does not change.

## The body

Both objects hold the same two instructions under
`?Bool@?$SettingT@VINISettingCollection@@@@QEAAPEATSETTING_VALUE@@XZ`:

```text
lea rax, [rcx+8]
ret
```

The source returns a static default, set to false, when `this` is null. The
compiler drops that branch because `this` cannot be null in a member
function. This was so before the change too. Whether a caller can pass
null is not shown here.

## Objects

At each of the two commits, all 2,322 objects of the build are
byte-identical to those of 89377df96 once the COFF timestamp is masked. The
first commit recompiles the seven units that include `SettingT.h`; the
second recompiles those seven and `processlists.cpp`. Their warnings are the
same once line and column are removed. Every record layout that the
compiler dumps for `processlists.cpp` is the same before and after, its 535
lines that name `BSSimpleList` among them.

Forced link of every archive member, windows-x64, 2,230 members in the same
order at every commit:

| | 89377df96 | Header move | Bool on the template |
| --- | --- | --- | --- |
| Undefined names | 35,139 | 35,139 | 35,139 |
| Duplicate symbols | 0 | 0 | 0 |
| Imports | 137 | the same | the same |
| Names with differing definitions in the archive | 519 | 519 | 519 |

The undefined, duplicate and import lists of all four link cells are the
same at the three commits. `src/generated` and `build/units.json` are
untouched.

## The units that call it

16 units require the name; each of them has a recipe symbols key that binds
it to `0x00408d60`. They call `processlists.cpp`'s definition, before this
change and after it. None of them is on the shared template:

| Copy of `SettingT<INISettingCollection>` in the unit | Units |
| --- | --- |
| Member declarations only, no field, 1 byte | 15 |
| One field `char pad[12]`, 12 bytes (`mapmenu.cpp`) | 1 |

Each copy differs from the shared class, so each unit stays on its copy.
The binding needs no field of the copy: the body reads offset 8 of the
object it is given. That object, at each of the 29 calls of the template's
`Bool` in the units' text:

| What the unit passes | Calls |
| --- | --- |
| A global of `GlobalObject_0045cf30`, which derives from `SettingT<INISettingCollection>` | 23 |
| A global of `GlobalObject_004de2f0`, which derives from `SettingT<SettingCollection_011f35a4>` | 3 (`teswater.cpp`) |
| A global of `GlobalObject_00709f00`, which derives from `SettingT<INIPrefSettingCollection>` | 2 (`dialogmenu.cpp`, `mapmenu.cpp`) |
| The integer `0x11de0a4`, cast to a pointer | 1 (`bgssaveloadhistory.cpp:127`) |

The 22 globals of these calls are defined in
`src/generated/global_object_initializers.cpp` from the shared template,
where the compiler puts `uValue` at 8 in all three classes.

- The 23 calls pass an object of a class derived from the class whose
  member they call.
- The 5 calls on the other two collections pass an object with `uValue` at
  8, but call the member of `SettingT<INISettingCollection>`. Their own
  identities, `Bool` of `SettingT<SettingCollection_011f35a4>` and of
  `SettingT<INIPrefSettingCollection>`, would be emitted by the owner of
  the address under the naming page's addendum of 2026-11-11. Not done
  here.
- The call in `bgssaveloadhistory.cpp` passes a 32-bit address of the
  original release as a pointer. On x64 that is not the setting. It is a
  defect, older than this change, and not repaired here.

The table counts calls through a cast to the template and direct calls on a
global whose class has no `Bool` of its own. Five direct calls in
`taskqueueinterface.cpp`, `pathbuilder.cpp` and `teswater.cpp` call
`GlobalObject_0045cf30::Bool`, a name of another class, and are not counted.

## Open

- 206 undefined names of the forced link are bound to `0x00408d60` by a
  recipe symbols key: names of stand-in classes, of other collections and
  of scoped identities. One of them is
  `fnv_00877730::SettingT<fnv_00877730::INISettingCollection>::Bool` in
  `main.cpp`. They leave when the owner emits the restored identities or
  the units move onto the shared template, each with an object proof.
- The 16 calling units stay on their copies.
- `processlists.cpp` itself still reaches `0x00408d60` through two
  stand-in classes whose receivers are `SettingT<INISettingCollection>`
  objects (`g_011f126c`, `g_011f127c`): `SettingBoolStub::Bool`, returning
  `bool*`, and `EffectThreadSetting::Bool`, returning `unsigned char*`. Both
  names are undefined; they are the next respelling, each with an object
  proof under the 2026-11-11 (3) rule.
- `processlists.cpp` keeps a second fake-table-pointer stand-in,
  `SettingT_GameSettingCollection_` (`void* vptr_; SETTING_VALUE uValue;`),
  for `SettingT<GameSettingCollection>`; it is outside this step.
- The null branch of the source is not in the object.
- Nothing executes this function. No host test compiles
  `processlists.cpp`, so none reaches the body. Windows execution: not
  run.
