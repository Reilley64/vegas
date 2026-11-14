# One shared declaration of BSAudioDefinition

VEGAS-17 owns the `bsaudio` units. `docs/inline-recipe-bodies.md` recorded a
storage defect: the constructor of `BSAudioDefinition` writes 584 bytes, and
`bsaudiomanager.cpp` constructed the class in place in records of its own
that were smaller. This change gives `BSAudioDefinition` and `BSSoundInfo`
one declaration, moves the two units that use them onto it, and makes every
in-place construction in `bsaudiomanager.cpp` provide the storage the body
writes.

It is a bounded change. What stays open is under "Not covered".

## Where the declaration lives

`include/fnv/bs_audio_definition.h`, beside the other native declarations
that several units share. It declares the fields of both classes and the five
members that `build/units.json` gives an address under the class's name:

| Address | Member | Recipe size | Owning unit |
| --- | --- | --- | --- |
| `0x00ae8770` | `BSAudioDefinition::BSAudioDefinition()` | 189 | `src/bsaudio/bsaudiodefines_h_unit.cpp` |
| `0x00ae8830` | `BSAudioDefinition::~BSAudioDefinition()` | 129 | the same |
| `0x00ae88c0` | `BSAudioDefinition::operator=(const BSAudioDefinition&)` | 304 | the same |
| `0x00ae8a40` | `BSSoundInfo::BSSoundInfo(BSSoundInfo*)` | 173 | the same |
| `0x00ae8af0` | `BSSoundInfo::~BSSoundInfo()` | 74 | the same |

The header has no body. The owning unit defines the five members, in
`src/bsaudio/bsaudiodefinition.inl`, which it includes. The copy constructor
of `BSSoundInfo` was the last one still defined in the class body; it is
defined out of line now, with the same text.

Two functions of these classes have a function row under another name, in
`bsaudiomanager.cpp`, and are not declared: `FUN_00ae89f0::FUN_00ae89f0()` at
`0x00ae89f0`, which is the default constructor of `BSSoundInfo`, and
`S::AssignFrom(const S*)` at `0x00ae7920`, which copies one. This change
respells no recipe key, so both stay.

The header also declares `NiPoint3`, with three floats and the static
`ZERO`, as both audio units declared it at global scope. `NiPoint3` has no
shared declaration yet. A unit that declares another `NiPoint3` at global
scope cannot include the header, and fails to compile if it does.

The two declarations without fields, `include/fnv/decl/BSAudioDefinition.h`
and `include/fnv/decl/BSSoundInfo.h`, are removed. One unit included the
second and none the first.

## The layout

The owning unit's fields are the transcription of the original's: two
`char*`, two buffers of 260 characters, floats, a point and unsigned
integers. The offsets follow from the pointer size.

| Field | 32-bit original | windows-x64 |
| --- | --- | --- |
| `pName` | `0x0` | `0x0` |
| `Name[260]` | `0x4` | `0x8` |
| `pFileName` | `0x108` | `0x110` |
| `FileName[260]` | `0x10c` | `0x118` |
| `fFirstValue`, `fSecondValue` | `0x210`, `0x214` | `0x21c`, `0x220` |
| `Location` | `0x218` | `0x224` |
| `uiSoundFlags` | `0x224` | `0x230` |
| `m_fMinimumDistance`, `m_fMaximumDistance` | `0x228`, `0x22c` | `0x234`, `0x238` |
| `m_uiSoundParameterA`, `B`, `6` | `0x230`, `0x234`, `0x238` | `0x23c`, `0x240`, `0x244` |
| size of `BSAudioDefinition` | 572 | 584 |
| `BSSoundInfo::m_kAudioDefinition` | `0x18` | `0x18` |
| size of `BSSoundInfo` | 596 | 608 |

The first pointer grows by four bytes, and the second pointer needs eight
bytes of alignment after a buffer that ends at `0x10c`, so it sits at `0x110`
and every later field is 12 bytes further than in the original.

What establishes the windows-x64 column:

- The compiler, in both units. The header asserts the offsets and sizes, so
  a unit that includes it does not compile under another layout.
- The owning unit's object. The constructor stores the address of
  `this + 0x8` at `this` and of `this + 0x118` at `this + 0x110`, a zero byte
  at `0x8` and at `0x118`, and its last store covers `[0x240, 0x248)`.
  `operator=` reads both pointers at `0x0` and `0x110`.
- The allocation the recipe's functions make. `FUN_00ae5a50` allocates its
  record with `sizeof`, 608 bytes, and passes the block plus `0x18` to the
  constructor.

The 32-bit column is the comment the owning header carried, and the sizes of
572 and 596 bytes that the header and `docs/inline-recipe-bodies.md` record.
It was not measured against the original here.

### Why the manager used 0x108

`bsaudiomanager.cpp` declared the class four more times under other names.
Two of them, `DebugInfo` and `DebugPlain`, were written from 32-bit offsets:
264 bytes of padding, then a pointer, a buffer and the fields. With an
eight-byte pointer that puts the pointer at `0x108`, the buffer at `0x110`
and every later field 8 bytes before the owning unit's, in a record of 576
bytes. `0x108` is the offset of `pFileName` in the 32-bit original. The other
two, `Sub18_00ae5a50` and `SoundDebugDescription`, declare both pointers and
agree with the owning unit at every offset.

So `0x110` is right on windows-x64 and `0x108` was a 32-bit offset kept as
padding.

## The construction sites

Measured by the compiler in `bsaudiomanager.cpp`, before and after:

| Record | Before | After |
| --- | --- | --- |
| `BSAudioDefinition`, the unit's own | 1 byte, no fields | the shared class, 584 |
| `FUN_00ae89f0` | 28, alignment 4, the definition at `0x18` | 608, alignment 8, the definition at `0x18` |
| `SoundInfoWrap` | 596 | 608 |
| `DebugInfo`, `DebugPlain` | 576, second pointer at `0x108` | removed; the class is used |
| `TempInfo` | 600, the definition at `0x18` | 608, the definition at `0x18` |
| `BSSoundInfoC` | 600, the definition at `0x18` | 608, the definition at `0x18` |
| `Msg_00ae5a50` | 608, a `Sub18_00ae5a50` at `0x18` | 608, the class at `0x18` |
| `Sub18_00ae5a50` | 584 | removed; the class is used |

The unit's object has six relocations to the constructor, before and after.
The constructor writes 584 bytes from the address it is given.

| Site | Storage | Before: provided, short by | After: provided |
| --- | --- | --- | --- |
| `FUN_00ae89f0::FUN_00ae89f0()`, out of line | `this + 0x18` | 28-byte record, the caller decides | 608-byte record |
| `Mgr_00ae5a50::FUN_00ae5a50`, `new Msg_00ae5a50` | `0x18` of the heap block | 608, fits | 608 |
| `ThisClsAda::FUN_00ada5d0`, local `info15` | `0x18` of `SoundInfoWrap` | 596, 12 | 608 |
| the same, local `descB_` | the local | 576, 8 | 584 |
| the same, local `debug4` | the local | 576, 8 | 584 |
| the same, temporary `TempInfo` | its member at `0x18` | 600, 8 | 608 |

One more allocation was short and is not a call of this constructor.
`FUN_00ada5d0` allocates a `BSSoundInfoC` and passes it to
`BSSoundInfoC::BSSoundInfoC(SoundInfoWrap*)`, which the recipe binds to
`0x00ae8a40`, the copy constructor of `BSSoundInfo`. That body writes 608
bytes. The allocation was 600 bytes and is 608. The name is still undefined:
it is a stand-in name.

## Functions whose code changes

Each commit was compared with the one before, object by object and function
by function. Three objects differ from the tip's:
`bsaudiodefines_h_unit.cpp.obj`, `bsaudiomanager.cpp.obj` and the new test's
object.

### The owning unit

No function changes. `BSSoundInfo::BSSoundInfo(BSSoundInfo*)` has the same
instructions and relocations. Its section was select-any, because the body
was in the class, and refuses a second definition now.

### The manager, the class name

`bsaudiomanager.cpp` spelled the class `struct BSAudioDefinition`, and the
owning unit `class`. The unit required
`BSAudioDefinition::operator=` under a name with the struct key, which no
object defines, in six calls:

| Function | Calls of `operator=` |
| --- | --- |
| `S::AssignFrom(const S*)` | 1 |
| `ThisClsAda::FUN_00ada5d0` | 3 |
| `AudioSystem::FUN_00ae5ff0` | 2 |

On the shared declaration the six relocations name the owning unit's
definition. Nothing else changes in `S::AssignFrom` and in `FUN_00ae5ff0`.
The constructor and the destructor have no class key in their names and
were bound before.

### The manager, FUN_00ada5d0

`ThisClsAda::FUN_00ada5d0` and its eight cleanup blocks are the only other
functions that change. They have 546 lines of instructions and relocations
before and after, each at the same address. 82 differ besides the six names
above:

| Kind | Lines | What |
| --- | --- | --- |
| The same local and the same offset in it, at another frame address | 65 | The frame grows from `0xe08` to `0xe48` bytes because five definitions in it grow by 8 bytes and `info15` by 12. |
| Size of the frame | 2 | `0xe08` to `0xe48`, on entry and on return. |
| A field of `descB_` at another offset | 10 | Table below. |
| Bytes copied for the argument of `SetDebug`, twice | 2 | `0x240` to `0x248`: the definition is passed by value. |
| Bytes allocated for `BSSoundInfoC`, and released if its constructor throws | 2 | `0x258` to `0x260`. |
| Bytes cleared in `descB_` | 1 | `0x23c` to `0x248`. See below. |

The ten field accesses, as offsets inside `descB_`:

| Instruction at | Source | Before | After |
| --- | --- | --- | --- |
| `0x1ea` | address of `FileName` | `0x110` | `0x118` |
| `0x1f1` | store to `pFileName` | `0x108` | `0x110` |
| `0x24e`, `0x2d1` | store to `Location.z` | `0x224` | `0x22c` |
| `0x26e` | store to `Location.x` | `0x21c` | `0x224` |
| `0x28f` | store to `Location.y` | `0x220` | `0x228` |
| `0x2bb`, `0x2c9` | store to `fFirstValue` and `fSecondValue` | `0x214` | `0x21c` |
| `0x2df` | store to `m_uiSoundParameterA` | `0x234` | `0x23c` |
| `0x2f2` | store to `m_uiSoundParameterB` and `6` | `0x238` | `0x240` |

Before, the function stored the buffer's address at `0x108` and then passed
the local to `operator=`, which reads the pointer at `0x110`: the first
eight characters of the file name. After, both use `0x110`.

The length cleared in `descB_` is a separate commit. The function called
`memset` with `0x23c`, 572, which is the size of the class in the 32-bit
original, where the call covers the whole object. It passes the size of the
class now. The 12 bytes the old length left out hold the three parameters,
which the function stores into after the call on every path, so the result
is the same.

`Mgr_00ae5a50::FUN_00ae5a50` has the same instructions: its record held a
584-byte copy before.

`TempInfo` constructs its definition by hand and destroys it through
`BSSoundInfo::~BSSoundInfo()`, as before. Its member sits in an anonymous
union, so the compiler adds no constructor or destructor call for it.

The compiler's warning on that `memset` call names the type of its argument,
so its text changes from `DebugInfo` to `BSAudioDefinition`. It is the same
warning at the same call.

## The destructors

Both destructors are a single return in the windows-x64 object. Nothing is
missing from them, and they were not changed.

- Their source bodies store into the object being destroyed and do nothing
  else. Compiled without optimisation, the owning unit's
  `~BSAudioDefinition` is ten stores, and `~BSSoundInfo` is six stores and a
  call of `~BSAudioDefinition` on `this + 0x18`, which the compiler adds for
  the member. With optimisation the stores are removed, because nothing can
  read the object afterwards, and the member's destructor is expanded to
  nothing.
- No field of `BSAudioDefinition` has a destructor: pointers, character
  arrays, floats, integers and a point of three floats.
- INFERENCE from the recipe sizes, not from the original's bytes: ten stores
  with a frame are 129 bytes in 32-bit code without optimisation, and six
  stores, a member destructor call and a frame are 74. Those are the recipe
  sizes of `0x00ae8830` and `0x00ae8af0`.

## Measured links

Windows-x64, the tip and every commit built from one export path into one
build path. 2,223 archive members in the same order at every commit.

Forced link of every archive member:

| | f0ed64652 | Copy out of line | Header | Manager on the header | Records replaced | Length cleared | Bodies in the inl | Test | Records asserted |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Undefined names | 35,224 | 35,224 | 35,224 | 35,223 | 35,223 | 35,223 | 35,223 | 35,223 | 35,223 |
| Left / entered | | 0 / 0 | 0 / 0 | 1 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 0 / 0 |
| Duplicate symbols | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Imports | 137 | the same | the same | the same | the same | the same | the same | the same | the same |
| Objects that differ from the column before | | 1 | 0 | 1 | 1 | 1 | 0 | 1, new | 0 |
| Names with differing definitions in the archive | 525 | 525 | 525 | 525 | 525 | 525 | 525 | 525 | 525 |
| Linked | yes | yes | no | yes | yes | yes | no | no | no |

The change was first measured on 2277431b8, with the same numbers; the three
commits between the two tips change documents only.

Four commits were not linked on their own. Every object of the archive is
byte-identical to the column before, apart from the COFF timestamp, so the
link has the same inputs and the cells of the column before stand for them.
The last column adds the assertions on the records of `bsaudiomanager.cpp`
that stand for the two classes; the unit's object is byte-identical with and
without them.

Each commit was built incrementally. A full build of the last commit from an
emptied build path has 2,318 steps, none failed, and its 2,300 objects are
byte-identical to the incremental ones. It has 20,788 warning lines; the
tip's build has 20,786, in 2,317 steps. The two added lines are the new
test's object, which compiles `bsaudiodefinition.inl` and so repeats the two
`strcpy` warnings of the owning unit. Three lines of the tip change their
text: one names the type of a `memset` argument (below), and two name the
file the bodies moved to.

One name leaves the undefined list, at the commit that moves the manager
onto the header, and none enters:

- `BSAudioDefinition::operator=` with the struct key, returning and taking
  `struct BSAudioDefinition&`.

Its requirer now requires the name with the class key, which has one
definition, in `bsaudiodefines_h_unit.cpp.obj`, the unit with the function
row at `0x00ae88c0`. The other four names of the two classes have one
definition each, in the same object, at every commit.

The other three cells, lazy ordinary, lazy unlimited and forced ordinary,
have the tip's exit codes, undefined names, imports and other diagnostics at
every commit. `build/units.json` and `src/generated` are unchanged.

## The test

`runtime.audio_definition` compiles `bsaudiodefinition.inl` against the
header, with no game archive. It constructs, assigns and destroys
definitions in heap blocks of exactly `sizeof(BSAudioDefinition)`. Built with
the address sanitizer, the same program with blocks of 576 bytes stops in the
constructor, on a write past the block.

What it guards: what the constructor and the assignment do, and the two
string copies, in blocks of the exact size under the sanitizers. What it
does not guard: the callers. It cannot see a site in `bsaudiomanager.cpp`
that provides too little storage, and it never executes
`BSSoundInfo::BSSoundInfo(BSSoundInfo*)`; that the body at `0x00ae8a40`
writes 608 bytes rests on the disassembly of the owning unit's object. The
layout guard is the header's `static_assert`s, and for the records of
`bsaudiomanager.cpp` that still stand for the two classes, the unit's own.

It does not link the owning unit's object, which requires names the archive
does not define. It defines `NiPoint3::ZERO` itself, with the empty
initializer the library's composed data has. It does not construct a
`BSSoundInfo`: the default constructor is `FUN_00ae89f0`, in
`bsaudiomanager.cpp`.

No program links `bsaudiomanager`. Windows execution: not run.

## Integration checks

Run these on every change to the header, to `bsaudiodefinition.inl` or to a
record in `bsaudiomanager.cpp` that holds a definition.

(a) Storage per site. For every relocation to the constructor in an object
other than the owning unit's, the record that holds the constructed storage,
measured by the compiler in that unit, has 584 bytes from the address
passed. Result: six sites in one object, all pass.

(b) One definition. Each of the five names has exactly one definition in the
archive, in the owning unit's object, and the count of names with differing
definitions in the archive does not rise. Result: one each; 525 names with
differing definitions before and after.

(c) The header's assertions compile in every unit that includes it, and so
do the assertions in `bsaudiomanager.cpp` that each record standing for
`BSSoundInfo` has its size and the definition at its offset.

## Not covered

- Receivers. `bsaudiomanager.cpp` still reaches the two classes through
  other names: `FUN_00ae89f0`, `SoundInfoWrap`, `TempInfo`, `BSSoundInfoC`,
  `Msg_00ae5a50`, `EntryInfo`, `S` and `BSSoundInfo70` for `BSSoundInfo`.
  Each of the first five now has the size of `BSSoundInfo` and the
  definition at `0x18`, and the unit asserts both against the class; their
  head fields are still the unit's. `EntryInfo` and `S` are 28 bytes with a
  member without fields at `0x18`, and `BSSoundInfo70` is 8 bytes. The unit
  only points at those three. Seven statements still cast to
  `BSAudioDefinition*` or `BSSoundInfo*`.
- `SoundDebugDescription`, the local of `AudioSystem::FUN_00ae5ff0`. It
  agrees with the class at every offset and is 584 bytes, so its storage
  fits. The unit asserts the size, not the offsets. It has its own inline
  bodies of the constructor, the destructor and the assignment, and the
  recipe binds its constructor to `0x00ae8770`. So `FUN_00ae5ff0` expands a
  second copy of the constructor where the original calls the owner's.
  Replacing it by the class was tried and not kept: the function gains the
  constructor call, two destructor calls and unwind state, and the compiler
  lays the whole function out again, so no instruction-level comparison of
  it was made. One recipe key,
  `SoundDebugDescription::SoundDebugDescription()`, would merge into the
  class's.
- The two default-constructor names. `FUN_00ae89f0::FUN_00ae89f0()` and
  `BSSoundInfoC::BSSoundInfoC(SoundInfoWrap*)` are stand-in names for
  members of `BSSoundInfo`. The second is still undefined.
- The anonymous union in `TempInfo`. It is debt, kept so that this change
  adds no call: the record constructs its definition with a placement new,
  and destroys it by casting itself to `SoundDtor` and calling
  `~BSSoundInfo`. The end state: once the recipe key of `FUN_00ae89f0` is
  respelled to the default constructor of `BSSoundInfo`, the temporary is a
  `BSSoundInfo` with a plain member, and the union, the placement new and
  the `SoundDtor` cast go.
- Double destruction of `info15`. `SoundInfoWrap`'s destructor calls
  `~BSSoundInfo` and then, for its member, `~BSAudioDefinition`. The
  original's `~BSSoundInfo` destroys the definition itself. It was so before
  this change. Both bodies only store into the object. It goes when `info15`
  is a `BSSoundInfo`.
- Release size. `AudioMgr70::FUN_00ad9870` deletes records through
  `BSSoundInfo70` and passes 8 as the size of a block that was allocated
  with 608 bytes. Whether the engine's release function uses the size was
  not examined.
- Every other layout in `bsaudiomanager.cpp`. The unit has 64 character
  arrays named as padding, such as the 116 bytes before the map in
  `ThisClsAda`. They were not examined.
- `NiPoint3` has no shared declaration. The header declares the audio
  units' own, and that declaration is transitional. The existing
  `include/NiPoint3.h` brings `layout_support.h` with it. A minimal shared
  `NiPoint3` header that compiles on the host needs a census of the global
  declarations first.
- `layoutPadding15[3]` in `BSSoundInfo` names bytes the compiler pads anyway.
  It is to be dropped in a follow-up.
- The three character arrays this change removed from `bsaudiomanager.cpp`
  (264 bytes twice, 568 bytes once): whether they were entries of the
  VEGAS-38 list is unverified.
- Nothing executes `bsaudiomanager`. The test executes the bodies of
  `BSAudioDefinition` only.

## The 8-byte lists

A defect of the same kind, recorded and not repaired here. Two units declare
`BSSimpleList` as 8 bytes and require the list's default constructor, which
the owning unit defines for a 16-byte list
(`docs/shared-simple-list.md`). Measured by the compiler in each unit:

| Unit | The list | Where it sits | What the 16-byte constructor writes |
| --- | --- | --- | --- |
| `src/fallout_shared/facegen/bsfacegenanimationdata.cpp` | `BSSimpleList<Actor*>`: two `int` members, 8 bytes, alignment 4 | member `unk1a0` at `0x264` of `FUN_00649680`, the last member; the record is 624 bytes | `[0x264, 0x274)`: 4 bytes past the record |
| `src/fallout/ai/combat/projectile.cpp`, from `projectile_decls.h` | `BSSimpleList<InventoryStackRecord*>`: `unsigned int items[2]`, 8 bytes, alignment 4 | member `list` at `0xa0` of `Projectile` | `[0xa0, 0xb0)`: over `byte90` at `0xa8` and the first 4 bytes of `transform` at `0xac` |

Both enclosing records are written from 32-bit offsets, so giving the list
its 16 bytes moves every later member. That needs the real layout of the
enclosing class first. `projectile.cpp` also requires the list's destructor.

## Acceptance criteria

No acceptance criterion of VEGAS-17 closes.

- Criterion 5, no access by a fixed byte offset. Three character arrays
  that stood for fields leave `bsaudiomanager.cpp`: 264 bytes in `DebugInfo`
  and in `DebugPlain`, and 568 bytes in `SoundInfoWrap`. The 13 fields each
  of the two debug records declared after its padding are the class's named
  fields now. Whether these were entries of the VEGAS-38 list was not
  checked. 64 character arrays named as padding remain in the unit.
- Criterion 2, one definition per function. Not advanced. The unit's second
  inline copy of the constructor, in `SoundDebugDescription`, remains.
- Credited: every construction of `BSAudioDefinition` in the archive is
  given 584 bytes; the fields of the local definition in `FUN_00ada5d0` are
  at the owning unit's offsets; `operator=` is bound.
