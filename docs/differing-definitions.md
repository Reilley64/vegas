# Names with differing definitions

VEGAS-89. An external name of the windows-x64 game archive can have a
definition in several members. For a COMDAT name the linker keeps one and
discards the others without comparing them. Where the definitions differ, the
kept one serves every unit, and no link reports it.

This change adds a check that fails when such a name appears, records the
names that differ today, and gives six of them one content. It is a first
increment. What stays open is under "Function names that remain", "Data
names" and "Not covered".

All numbers are measured on the cross build of a4452a9c3 and of the commits
of this change, built from one source path. The cause of each remaining
function name and the counts of the data names by cause were read on an
earlier build of the same commits on f0ed64652. Every definition of this
change's archive has the same name, selection, size and content as in that
build, except definitions in units that later commits of the accepted line
changed. Among the names that differ, those are the virtual tables of
`TESObject`, `TESBoundObject`, `TESBoundAnimObject` and `TESObjectACTI`
(its `TESBoundAnimObject` part). Each keeps its number of definitions and
contents and still differs in a target at a slot every definition has. And
`std::string`'s destructor has one more definition, in a new unit that uses
the toolchain's class, with the toolchain's content.

## The count

2,224 members define 141,551 external names. 525 of them have definitions
that differ. Every COMDAT selection is compared, not only select-any.

| Kind | Selection | a4452a9c3 | After this change |
| --- | --- | --- | --- |
| Function | any | 51 | 47 |
| Virtual table | largest | 47 | 46 |
| RTTI base class descriptor | any | 160 | 160 |
| RTTI base class array | any | 127 | 127 |
| RTTI class hierarchy descriptor | any | 113 | 113 |
| RTTI complete object locator | any | 20 | 19 |
| Throw information | any | 3 | 3 |
| Catchable type array | any | 4 | 4 |
| Total | | 525 | 519 |

No string, constant or guard differs.

## Which definition a link keeps

Read from the linker's map, not predicted.

- The link of every archive member keeps, for a select-any name, the
  definition of the first member in archive order, and for a largest name
  the first of the largest. That held for each of the 340 names of the 525
  that its output contains, and for each of the 336 of the 519 after this
  change. The others are not in the output: the link discards a section
  nothing refers to.
- The lazy link is the one that produces an executable today. 11 of the
  names are in its output, before and after, and all 11 belong to
  `std::length_error`, `std::logic_error` or `std::string`. It keeps the
  toolchain's definition of each: ten from `canonical_memory_manager.cpp`,
  one from the toolchain's own library. No unit with a private copy of those
  classes contributes to its output.

So the executable that links today is not affected. The hazard is in every
link that loads more members.

## The check

`tools/differing-definitions` reads the archive and compares every
definition of every external name. Its README has the comparison rule, what
it does not compare, the exit codes and the rules of the allowlist.

`tools/differing-definitions/allowlist.tsv` holds the 519 names as kind and
name. A recorded name is an open conflict, not an accepted one.

- A name that differs and is not recorded fails, always.
- A recorded name that no longer differs is printed as `STALE` and passes.
  A change that resolves a conflict leaves the list alone and reports its
  `STALE` lines.
- `--prune` removes stale lines and nothing else. `--strict` makes a stale
  line fail. Both are run when changes are integrated, and the shorter list
  is committed with the integration.
- A line is added only by hand, in a reviewed change that states the reason.
  No option of the command adds one.

Where it runs. The set of names depends on the compiler and the standard
library, and the list was measured on the cross build.

- CTest runs the check as `archive.differing_definitions` in the cross build
  only. Configuring that build fails with a message when Go is not found.
- The windows-x64 workflow builds natively with another clang and the MSVC
  standard library. It runs the command on its own archive in a step that
  reports and cannot fail the job. Its `NEW` and `STALE` lines are what the
  next increment compares with the list, to decide between one list per
  toolchain and a common subset.

On this machine `find_program(go)` also finds Go in CMake's own system
prefixes, so removing Go from `PATH` alone does not show the failure. The
README's wording holds: configuring fails when CMake finds no Go.

The allowlist is keyed by kind and name, not by content. A name that is
recorded and diverges further, with another body or in another unit,
still passes. That is a known limit of the check.

Measured: the check passes on the archive of this change, with and without
`--strict`, and fails on the archive of a4452a9c3, where it reports the six
names below as new. `--prune` on the archive of this change removes no
line: the commits on the accepted line since the list was measured resolved
none of its names, and no name is new.

## What this change repaired

Four stand-in names that different units used for different classes. Each
class had only inline members. The recipe has no function row for any of
the six names that differed, and one symbol key: `??_7BaseObj@@6B@`, which
binds the table of `blk_00c20000_od.cpp`, the definition that keeps the
name.

| Name that differed | Units | Now |
| --- | --- | --- |
| `RefPtr::~RefPtr()`, 4 contents | `blk_00c60000_o2.cpp`, `blk_00c20000_od.cpp`, `blk_00bc0000_o2.cpp`, `bsshaderaccumulator.cpp` | `fnv_00c6da50::RefPtr`, `fnv_00c3c7e0::RefPtr`, `fnv_00bc4830::RefPtr`, `fnv_00b660d0::RefPtr` |
| `StagePtr::~StagePtr()`, 2 contents in 5 units | `blk_00c00000_o2.cpp` against four units with one content | `fnv_00c0d200::StagePtr`; the four keep the global name |
| `StageReturnPtr::~StageReturnPtr()`, 2 contents | `blk_00c00000_o2.cpp`, `globalfunc.cpp` | `fnv_00c04310::StageReturnPtr`, `fnv_00ba59e0::StageReturnPtr` |
| `BaseObj`: deleting destructor, virtual table, complete object locator, 2 contents each | `hkmemorymeshshape.cpp` against `blk_00c20000_od.cpp` | `fnv_00cf3ea0::BaseObj` in `hkmemorymeshshape.cpp` |

### The member whose parameter names `RefPtr`

`blk_00c20000_od.cpp` passes its `RefPtr` to an inline member,
`OwnArr::FUN_00c3d4f0`, and the recipe has a symbol key for that member:
`?FUN_00c3d4f0@OwnArr@@QAEIABURefPtr@@@Z` at `0x00c3d4f0`, under
`queuedfiles.cpp`. The member has four spellings, and all four follow the
struct so that it keeps one signature:

- its inline definition in `blk_00c20000_od.cpp`;
- the shared declaration `include/fnv/decl/OwnArr.h`: the forward
  declaration and the parameter. No script in the repository writes the
  headers under `include/fnv/decl`; they are edited by hand;
- the cast at its one call, in `queuedfiles.cpp`;
- that recipe key, now `?FUN_00c3d4f0@OwnArr@@QAEIABURefPtr@fnv_00c3c7e0@@@Z`.
  No other recipe key or row changes.

No object emits the member. It is undefined in the link of every member
before and after, under its new spelling after.

### Global names that stay

Other declarations keep the global names and are not part of any repaired
conflict. Each was found by a search of the recipe for the mangled forms
(`URefPtr@@`, `UStagePtr@@`, `UStageReturnPtr@@`, `VBaseObj@@`, `UBaseObj@@`
and the constructor, destructor and table prefixes) and of `include/` and
`src/` for the plain names.

- `RefPtr`: `modelloader.cpp` declares a global `RefPtr` and its recipe key
  `??0RefPtr@@QAE@PAX@Z` binds the constructor to `0x00528cb0`.
  `blk_00c40000_od.cpp` has a function row and key for
  `?FUN_00c42560@NodeQueue@@QAE_NHPAUNodeKey@@PAURefPtr@@@Z`, whose
  parameter is that unit's own global `RefPtr`. `niswitchnode.cpp` has a
  function row for `?FUN_00a93ca0@Target@@QAEXPAURefObj@@AAURefPtr@@@Z`, over
  its own global `RefPtr`. `include/fnv/decl/NodeQueue.h` declares a global
  `RefPtr` and no unit includes it. Other units declare a global `RefPtr`
  and emit no definition under the name.
- `StagePtr`: four units keep a global `StagePtr` (below).
- `BaseObj`: three units still define names under the global `BaseObj`, and
  they are three different classes. `blk_00620000_od.cpp` has an inline
  virtual destructor and one `int`. `blk_00c20000_od.cpp` has an inline
  virtual destructor and a virtual `vfunc0`, and the recipe key
  `??_7BaseObj@@6B@` binds its table to `0x01017458`.
  `blk_00c60000_od.cpp` declares a constructor of thirteen arguments, which
  the key `??0BaseObj@@QAE@HHMMMMMMUQuad16@@MMMM@Z` binds to `0x00c31bd0`,
  and a destructor it never defines. Their RTTI hierarchy and base class
  array records are equal in content. Their base class descriptor,
  `??_R1A@?0A@EA@BaseObj@@8`, still differs: 3 definitions, 2 contents.
  `blk_00620000_od.cpp` declares `class BaseObj` and the other two
  `struct BaseObj`, and the descriptor names the type descriptor, whose
  name has the class-key. The name stays on the allowlist.
  `blk_008a0000_od.cpp` declares a fourth `BaseObj` and emits nothing under
  it.

### The rules that were applied

- **Every member of a set of differing definitions moves**, unless a group
  of them is byte-equal in compiled content and no recipe key distinguishes
  its classes; that group keeps the global name. All four `RefPtr` bodies
  differ, so all four move. The two `StageReturnPtr` bodies differ, so both
  move. Four `StagePtr` bodies are equal, so only the fifth moves.
- **A class that a recipe key binds keeps the global name.** The recipe binds
  `BaseObj`'s table at `0x01017458` for `blk_00c20000_od.cpp`. It has no row
  or key for the class in `hkmemorymeshshape.cpp`, which moves.
- **The namespace** is `fnv_<address>` of the first recipe function of the
  unit, in source order, that uses the class: through a class that holds or
  derives from it, or through a call. Each of the eight addresses is a
  function row of that unit. The namespace claims nothing else about the
  class.
- Only the definition and the spellings that named it change. Uses in the
  units were found by the compiler: after the definition moved, each
  "unknown name" diagnostic named one position. Spellings outside the units,
  in a shared header, another unit or the recipe, were found by the search
  above.

The four global `StagePtr` structs, in `blk_00ba0000_o2.cpp`,
`blk_00bc0000_o2.cpp`, `skyshader.cpp` and `geometrydecalshader.cpp`, are
four textually different unit-local declarations: their members and the
release functions they name differ. They agree only in compiled bytes. They
are views of one helper of the original release, a smart pointer to the pass
stage, and their end state is one shared declaration with the `NiD3DPass`
family (VEGAS-16, VEGAS-11), not four names. Until then the check sees them
only when they diverge.

`StagePtr` and `StageReturnPtr` in `blk_00c00000_o2.cpp` differ from the
other definitions only in the offset of the count they decrement: 0x64
against 0x60. Every definition calls the same release function,
`FUN_00e7ecd0_cls::FUN_00e7ecd0`. The cause is that unit's view of the
pointee, `BeamStage`: `pad00[8]`, a pointer `m_p08`, `pad0c[0x54]`, then the
count. The pad's name says the pointer is 4 bytes; on x64 it is 8, so the
count moves 4 bytes up. That is layout evidence about the pointee, and the
rename takes it out of the check's sight. It is recorded here instead.

### Proof

Per object: the object after the change equals the object before once names
are respelled into the namespace. Same sections, same bytes, same
relocations, same symbol records; a name differs only by the namespace, and
for `BaseObj` the type name string in its RTTI type descriptor as well.
The four commits change eight objects, `blk_00c00000_o2.cpp` twice; all nine
comparisons pass. No instruction changed. The rebuilt steps have the same
warnings as the same steps of the build before, once positions are removed.

Link of every archive member, 2,224 members in the same order at every
commit:

| | a4452a9c3 | `RefPtr` | `StagePtr` | `StageReturnPtr` | `BaseObj` |
| --- | --- | --- | --- | --- | --- |
| Undefined names | 35,187 | 35,188 | 35,188 | 35,188 | 35,189 |
| Left / entered | | 1 / 2 | 0 / 0 | 0 / 0 | 0 / 1 |
| Duplicate symbols | 0 | 0 | 0 | 0 | 0 |
| Imports | 137 | the same | the same | the same | the same |
| Objects that differ from the column before | | 5 | 1 | 2 | 1 |
| Names with differing definitions | 525 | 524 | 523 | 522 | 519 |

The lazy link is unchanged at every commit: no undefined name, 78 imports,
and a map that is identical apart from its name and timestamp lines.

What leaves and enters:

- `OwnArr::FUN_00c3d4f0(RefPtr const &)` leaves and
  `OwnArr::FUN_00c3d4f0(fnv_00c3c7e0::RefPtr const &)` enters: the same
  member under its new spelling, undefined before and after.
- `RefPtr::~RefPtr()` enters. `modelloader.cpp` declares a fifth `RefPtr`,
  with a destructor it never defines, and calls it. Until now the link of
  every member bound that call to the first of the four bodies above, the
  one of `blk_00c60000_o2.cpp`, which belongs to another class.
- `fnv_00cf3ea0::BaseObj::~BaseObj()` enters. `hkmemorymeshshape.cpp`
  declares the destructor and never defines it. It required
  `BaseObj::~BaseObj()` before, which no object defines and which
  `blk_00c60000_od.cpp` still requires. One undefined name stood for two
  classes; now there are two.

## Function names that remain: 47

None of the 47 has a function row in the recipe under its own name, so for
46 of them no recipe row names an owner and removing a copy is not
available. The rulings leave two repairs: one declaration that every unit
uses, or a record of the disagreement. The 47th is the destructor of
`NiPointer<NiRefObject>`: one unit's symbol key binds it to `0x00b66f20`, a
function row of `nismartpointer_h_unit.cpp`. That is the route of
`docs/shared-simple-list.md`, a shared `NiPointer` whose owner emits it, and
it was not taken here.

By the work that removes them:

| Work | Names |
| --- | --- |
| The shared `NiPointer` | 2: the destructors of `NiPointer<NiGeometryData>` and `NiPointer<NiRefObject>` |
| Units on `include/fnv/ni_ref_object.h` | 2: the deleting destructors of `NiRefObject` and `NiRefObject2` |
| Gamebryo classes, VEGAS-16 | 7: `NiD3DShader`, `NiTexturingProperty::Map`, `NiAlphaProperty`, `NiD3DVertexShader`, `NiFile`, `NiFloatInterpolator`, `NiSingleInterpController` |
| Bethesda classes, VEGAS-17 | 7: both destructors of `BSShader`, `BSFile`, `BSStream`, `FUN_00ac5490`, `Tile__Extra`, `bhkLiquidAction` |
| The `TESForm` and `TESObject` family, VEGAS-18 | 5: `TESObject`, `TESBoundObject`, `TESBoundAnimObject`, `TESObjectACTI`, `TESObjectREFR` |
| SpeedTree, VEGAS-73 with VEGAS-17 | 5: both of `IdvFileError`, `FUN_00b09480`, `FUN_00b096a0`, `FUN_00ec78e0` |
| `std` names, VEGAS-23 with VEGAS-48 | 10: the eight toolchain names below, `std::bad_alloc_ob1`, `basic_filebufDEB0` |
| Havok, VEGAS-14 and VEGAS-15 | 8: `hkBaseObject`, `hkReferencedObject`, both of `hkpCdPointCollector`, `hkpConvexShape`, `hkpMoppCode`, `hkpShape`, `hkpShapeContainer` |
| The `SpawnedObject` helpers, VEGAS-80 | 1 |

By cause:

| Category | Names | What repairs it |
| --- | --- | --- |
| A real engine class that units declare differently | 28 | The units move to one declaration. Until then the disagreement is layout evidence. |
| One class of the original release seen by two units under a stand-in name; the recipe binds one constructor or table address for both | 10 | One declaration of that class. Separate names would give one class two identities. |
| A class of the toolchain's standard library against a private copy in namespace `std` | 8 | The unit uses the standard library, which is VEGAS-23. |
| Different classes under a stand-in name | 1 | VEGAS-80 separates the `SpawnedObject` helpers. |

31 of the 47 are classed wrong-body-possible: the bodies call different
functions or free differently. 16 are layout evidence: the bodies differ
only in a size, an offset or the base whose destructor they call. None is
shown to be benign.

### Two named hazards

- **`hkpCdPointCollector`'s deleting destructor** (VEGAS-15). Four units
  define it. `hkpcharacterproxy.cpp` and `hkpbvagent.cpp` compile it to a
  trap, 2 bytes. `hkpcpuworldlinearcastjob.cpp` and
  `hkpcpuworldgetclosestpointsjob.cpp` compile a 35-byte body that calls the
  sized delete of 0x10 bytes. In archive order the first definer is
  `hkpcharacterproxy.cpp`, so the trap is the predicted pick for every unit.
  The name is not in the output of any link today, lazy or of every
  member, so the prediction is not observed: nothing in that output refers
  to the name or to the class's table. The class's virtual functions are also in another order between
  units: `reset` is the second virtual function in two units and the third
  in two others, and `reset` itself differs (below).
- **`TESObjectREFR`'s deleting destructor** (the `TESForm` family under
  VEGAS-18). `inventorychanges.cpp` deletes 0x98 bytes, `tesscript.cpp`
  0x28 bytes, each after `TESForm`'s destructor.

### Two views of one class: 10

| Name | Definitions / contents | Cause | Hazard | Owning work |
| --- | --- | --- | --- | --- |
| copy constructor of `IdvFileError` | 2 / 2 | projectedshadow.cpp derives IdvFileError from the toolchain's std::exception; frondengine.cpp derives it from its own frondstd::runtime_error over dtorb181::BxException with a string member. The recipe binds one constructor address, 0x00b09480, for both units | wrong-body-possible | VEGAS-73, VEGAS-17 |
| deleting destructor of `IdvFileError` | 2 / 2 | same two declarations as the copy constructor: one destroys through __std_exception_destroy, the other through BxException's destructor and a second operator delete | wrong-body-possible | VEGAS-73, VEGAS-17 |
| deleting destructor of `std::bad_alloc_ob1` | 2 / 2 | tesobject.cpp declares the destructor of std::bad_alloc_ob1 and calls it; bsfacegenmodel.cpp defines it in the class and calls std::exception_ob1's. The name stands for the original release's std::bad_alloc | wrong-body-possible | VEGAS-23, VEGAS-48 |
| deleting destructor of `basic_filebufDEB0` | 2 / 2 | blk_00ac0000_od.cpp and tesobject.cpp each declare basic_filebufDEB0 with another destructor body; the recipe binds one table address, 0x010a3138, for both | wrong-body-possible | VEGAS-23 |
| deleting destructor of `FUN_00ac5490` | 2 / 2 | blk_00aa0000_od.cpp expands the destructor in line; tile.cpp declares the class over S00ac5490_Base and calls that destructor. The recipe binds one table address, 0x010a2c38, for both | wrong-body-possible | VEGAS-17, VEGAS-11 |
| deleting destructor of `FUN_00b09480` | 6 / 2 | native_string.cpp uses include/fnv/decl/FUN_00b09480.h and defines the destructors, defaulted, so its deleting destructor expands them; five SpeedTree units declare the class themselves and call a destructor they only declare | wrong-body-possible | VEGAS-73, VEGAS-17 |
| deleting destructor of `FUN_00b096a0` | 6 / 2 | as FUN_00b09480, its base | wrong-body-possible | VEGAS-73, VEGAS-17 |
| deleting destructor of `FUN_00ec78e0` | 7 / 2 | as FUN_00b09480; throw.cpp is a sixth unit with a private declaration | wrong-body-possible | VEGAS-73, VEGAS-17 |
| deleting destructor of `NiRefObject2` | 3 / 2 | blk_00e80000_o2.cpp expands the destructor, with the object count, in line; blk_00b60000_o2.cpp and niimageconverter.cpp call a declared one. The recipe binds one table address, 0x0101dce4, for all three | wrong-body-possible | VEGAS-16, VEGAS-11 |
| deleting destructor of `Tile__Extra` | 2 / 2 | sized delete of 0x28 bytes after its own destructor in tilerect.cpp, of 0x20 bytes after NiExtraData's in tile3d.cpp; the recipe binds one constructor address, 0x00a1f610, for both | layout-evidence | VEGAS-17, VEGAS-11 |

### Toolchain class against a private copy: 8

| Name | Definitions / contents | Cause | Hazard | Owning work |
| --- | --- | --- | --- | --- |
| copy constructor of `std::length_error` | 13 / 2 | 12 units use the toolchain's std::length_error. bsfacegenmodel.cpp declares its own std::length_error over std::exception_ob1 with a String member, the 32-bit runtime class of the original release | wrong-body-possible | VEGAS-23, VEGAS-48 |
| deleting destructor of `std::length_error` | 13 / 2 | as the copy constructor: the private copy's destructor is declared and calls std::logic_error's | wrong-body-possible | VEGAS-23, VEGAS-48 |
| copy constructor of `std::logic_error` | 26 / 3 | 24 units use the toolchain's std::logic_error. bsfacegenmodel.cpp declares its own over std::exception_ob1; idvspline.cpp declares its own over the toolchain's std::exception with a member of its own std::basic_string specialisation | wrong-body-possible | VEGAS-23, VEGAS-48 |
| deleting destructor of `std::logic_error` | 28 / 2 | as the copy constructor; the two private copies declare the destructor and call it out of line | wrong-body-possible | VEGAS-23, VEGAS-48 |
| copy constructor of `std::out_of_range` | 4 / 2 | 3 units use the toolchain's std::out_of_range. idvspline.cpp declares its own over its own std::logic_error | wrong-body-possible | VEGAS-23 |
| deleting destructor of `std::out_of_range` | 4 / 2 | as the copy constructor | wrong-body-possible | VEGAS-23 |
| destructor of `std::string` | 14 / 3 | 12 units use the toolchain's std::string. idvspline.cpp declares an explicit specialisation whose destructor calls fnv_0044a730::FUN_0044a730_cls::FUN_0044a730; tileimage.cpp declares its own std::basic_string template whose destructor calls FUN_00401030 | wrong-body-possible | VEGAS-23 |
| destructor of `std::vector<unsigned short>` | 2 / 2 | native_packfile_loader.cpp uses the toolchain's std::vector. indexedgeometry.cpp declares its own std::vector template, whose destructor calls std::_Destroy and the unsized operator delete | wrong-body-possible | VEGAS-23 |

### Real class declared differently: 28

| Name | Definitions / contents | Cause | Hazard | Owning work |
| --- | --- | --- | --- | --- |
| destructor of `NiPointer<NiGeometryData>` | 2 / 2 | blk_00640000_od.cpp sees NiGeometryData with NiRefObject as a base at offset 8 and calls NiRefObject::DecRefCount; blk_00440000_od.cpp sees a NiGeometryData with its own DecRefCount at offset 0 | layout-evidence | the shared NiPointer; VEGAS-16, VEGAS-11 |
| destructor of `NiPointer<NiRefObject>` | 9 / 2 | 8 units expand the release in line: a locked decrement of the count and a virtual call. mtrenderingsystem.cpp declares NiRefObject::DecRefCount without a body and calls it | wrong-body-possible | the shared NiPointer; VEGAS-16, VEGAS-11 |
| destructor of `BSShader` | 5 / 3 | three declarations of BSShader and NiD3DShader: members held as NiPointer, released through NiD3DPass::DecRefCount, or released in line | layout-evidence | VEGAS-17, VEGAS-11 |
| deleting destructor of `BSShader` | 6 / 3 | as the destructor: one unit group calls it, two expand different bodies | layout-evidence | VEGAS-17, VEGAS-11 |
| deleting destructor of `NiD3DShader` | 4 / 2 | watershader.cpp and debugshader.cpp release three members in line; speedtreeleafshader.cpp and bsshaderbloodsplatter.cpp hold them as NiPointer members | layout-evidence | VEGAS-16, VEGAS-11 |
| deleting destructor of `BSFile` | 2 / 2 | bsfile.cpp expands the destructor in line: flush, fclose, buffer release, NiFile's destructor. archive.cpp calls NiBinaryStream's destructor and nothing of BSFile or NiFile | wrong-body-possible | VEGAS-17, VEGAS-11 |
| deleting destructor of `BSStream` | 3 / 2 | sized delete of 0x5d8 bytes in distantlodshaderproperty.cpp and bsstream_h_unit.cpp, of 0x5d0 bytes in queuedfiles.cpp | layout-evidence | VEGAS-17, VEGAS-11 |
| deleting destructor of `NiTexturingProperty::Map` | 2 / 2 | nitexturingproperty.cpp expands the destructor in line and frees through the memory manager; nitarray.cpp declares it and calls it | wrong-body-possible | VEGAS-16, VEGAS-11 |
| deleting destructor of `NiAlphaProperty` | 2 / 2 | blk_00ba0000_o2.cpp declares NiAlphaProperty without a destructor and calls NiObject's; bsfadenode.cpp declares one and calls it | layout-evidence | VEGAS-16, VEGAS-11 |
| deleting destructor of `NiD3DVertexShader` | 2 / 2 | sized delete of 0x70 bytes after NiRefObject's destructor in nid3dvertexshader_h_unit.cpp, of 0x48 bytes after NiD3DShaderProgramStub's in nid3dshaderprogramcreatorasm.cpp | layout-evidence | VEGAS-16, VEGAS-11 |
| deleting destructor of `NiFile` | 2 / 2 | nifile_console.cpp declares NiFile's destructor and calls it; archive.cpp declares NiFile without one and calls NiBinaryStream's | layout-evidence | VEGAS-16, VEGAS-11 |
| deleting destructor of `NiFloatInterpolator` | 2 / 2 | sized delete of 0x28 bytes after NiKeyBasedInterpolator's destructor in blk_00a20000_o2.cpp, of 0x30 bytes after its own in nifloatinterpolator.cpp | layout-evidence | VEGAS-16, VEGAS-11 |
| deleting destructor of `NiRefObject` | 7 / 3 | three bodies: the destructor with the object count expanded in line (nirefobject_lifetime.cpp, the native owner, and two more units), no destructor call (niloddata.cpp), and a call of the declared destructor (three units) | wrong-body-possible | include/fnv/ni_ref_object.h; VEGAS-16, VEGAS-11 |
| deleting destructor of `NiSingleInterpController` | 2 / 2 | nitexturetransformcontroller.cpp releases the interpolator in the destructor; nitransformcontroller.cpp does not | wrong-body-possible | VEGAS-16, VEGAS-11 |
| deleting destructor of `TESBoundAnimObject` | 3 / 2 | sized delete of 0x50 bytes in tesobjectcont.cpp and teslevcharacter.cpp, of 0x48 bytes in bgstalkingactivator.cpp | layout-evidence | VEGAS-18, VEGAS-11 |
| deleting destructor of `TESBoundObject` | 4 / 2 | sized delete of 0x50 bytes in three units, of 0x48 bytes in bgstalkingactivator.cpp | layout-evidence | VEGAS-18, VEGAS-11 |
| deleting destructor of `TESObject` | 4 / 2 | sized delete of 0x40 bytes in three units, of 0x38 bytes in bgstalkingactivator.cpp | layout-evidence | VEGAS-18, VEGAS-11 |
| deleting destructor of `TESObjectACTI` | 2 / 2 | tesfurniture.cpp declares the destructor and calls it; bgstalkingactivator.cpp expands a destructor over five bases in line | layout-evidence | VEGAS-18, VEGAS-11 |
| deleting destructor of `TESObjectREFR` | 2 / 2 | sized delete of 0x98 bytes in inventorychanges.cpp, of 0x28 bytes in tesscript.cpp | layout-evidence | VEGAS-18, VEGAS-11 |
| deleting destructor of `bhkLiquidAction` | 2 / 2 | sized delete of 0x28 bytes after bhkRefObjectBase's destructor in bhkrigidbody.cpp, of 0x20 bytes after its own in bhkliquidaction_h_unit.cpp | layout-evidence | VEGAS-17, VEGAS-11 |
| deleting destructor of `hkBaseObject` | 4 / 2 | two units call a declared destructor; native_referenced_object.cpp and hkpmoppcompiler.cpp call none | wrong-body-possible | VEGAS-14, VEGAS-15 |
| deleting destructor of `hkReferencedObject` | 7 / 6 | six bodies in seven units. They differ in the destructor they call (hkBaseObject's, hkReferencedObject's or none) and in how they free the block (the global sized delete, the class's operator delete, an allocation record found through thread-local state, or the allocator FUN_00c85750 returns) | wrong-body-possible | VEGAS-14, VEGAS-15 |
| deleting destructor of `hkpCdPointCollector` | 4 / 2 | hkpcharacterproxy.cpp and hkpbvagent.cpp compile the deleting destructor to a trap, 2 bytes; the two world-query units compile a 35-byte body with a sized delete | wrong-body-possible | VEGAS-15 |
| `hkpCdPointCollector::reset` | 3 / 2 | hkpcharacterproxy.cpp stores the value of DAT_0104da48; the two world-query units store the literal 3.40282e+38f. The class also has another virtual function order in each | wrong-body-possible | VEGAS-15 |
| deleting destructor of `hkpConvexShape` | 3 / 2 | blk_00cc0000_od.cpp calls hkReferencedObject's destructor and the sized class operator delete; two native shape units call hkBaseObject's destructor and the unsized one | wrong-body-possible | VEGAS-15 |
| deleting destructor of `hkpMoppCode` | 2 / 2 | hkpmoppcompiler.cpp calls a declared destructor; native_mopp_construction.cpp expands the destructor in line | wrong-body-possible | VEGAS-15 |
| deleting destructor of `hkpShape` | 7 / 2 | as hkpConvexShape: one staging unit against six physics units | wrong-body-possible | VEGAS-15 |
| deleting destructor of `hkpShapeContainer` | 3 / 2 | two native shape units call a declared destructor; native_mopp_construction.cpp calls none | wrong-body-possible | VEGAS-15 |

### Distinct classes under a stand-in name: 1

| Name | Definitions / contents | Cause | Hazard | Owning work |
| --- | --- | --- | --- | --- |
| deleting destructor of `SpawnedObject` | 2 / 2 | nigpuprogramcache.cpp and speedtreebillboardshaderproperty.cpp declare different classes named SpawnedObject over SpawnedBase | wrong-body-possible | VEGAS-80 |

## Layout evidence

What the differing bodies show about the units' declarations. Each row is
read from the instructions of the two definitions.

| Class | Evidence |
| --- | --- |
| `TESObjectREFR` | sized delete of 0x98 bytes in `inventorychanges.cpp`, of 0x28 in `tesscript.cpp` |
| `TESBoundObject`, `TESBoundAnimObject` | 0x50 bytes in `tesobjectcont.cpp` and others, 0x48 in `bgstalkingactivator.cpp` |
| `TESObject` | 0x40 bytes against 0x38, the same units |
| `BSStream` | 0x5d8 bytes in two units, 0x5d0 in `queuedfiles.cpp` |
| `NiD3DVertexShader` | 0x70 bytes against 0x48, with another base destructor |
| `NiFloatInterpolator` | 0x28 bytes against 0x30 |
| `Tile::Extra` (`Tile__Extra`) | 0x28 bytes against 0x20 |
| `bhkLiquidAction` | 0x28 bytes against 0x20 |
| `NiGeometryData` | `NiRefObject` at offset 8 in `blk_00640000_od.cpp`, at offset 0 in `blk_00440000_od.cpp` |
| The pointee of `StagePtr` and `StageReturnPtr` | reference count at offset 0x64 in `blk_00c00000_o2.cpp`, at 0x60 in five other units; no longer seen by the check (above) |
| `hkpCdPointCollector` | `reset` is the second virtual function in two units and the third in two others |

The repaired helpers are evidence too: `RefPtr` in `blk_00c20000_od.cpp` is
passed to `0x00c3d4f0`, and `RefPtr` in `blk_00bc0000_o2.cpp` is a member of
`FUN_00be2200`, a class named after the address of `BSShader`'s constructor.
Neither was renamed to a real class here.

## Data names: 472

Every one is a record the compiler derives from a class declaration, so
every one is a second view of a class. By the fields that differ:

| Cause | Names |
| --- | --- |
| Base-class list: another number of bases, other bases or other attributes | 334 |
| Class-key: `class` in one unit, `struct` in another, which changes the type descriptor's name | 52 |
| Both | 33 |
| Virtual table: another target in a slot that every definition has | 32 |
| Virtual table: another length only | 14 |
| Catchable type array: other types | 4 |
| Throw information: another destructor | 3 |

39 are classed wrong-body-possible. In the 32 tables with another target in
a common slot, a call through the kept table reaches another function than
the unit declared. The 3 throw information records name another destructor
and the 4 catchable type arrays other catchable types with their copy
constructors, so a throw or a catch through the kept record runs another
destructor or copy constructor than the unit's. The other 433 are layout
evidence.

None is silenced. Each stays in the allowlist until its class has one
declaration. By the work that removes it:

| Owning work | Names |
| --- | --- |
| VEGAS-11, one declaration and one name per class | 453 |
| VEGAS-23, the standard library replaces private copies of `std` classes | 12 |
| VEGAS-80, the `SpawnedObject` and `SpawnedBase` helpers | 7 |

The units that define the 472 are in the folders of VEGAS-18 (226 names),
VEGAS-20 and VEGAS-21 (174), VEGAS-16 (106), VEGAS-17 (96), VEGAS-22 (80),
VEGAS-19 (72), VEGAS-15 (62) and VEGAS-14 (24). A name counts once for each
folder that defines it. This assignment is a proposal: no ticket was edited.

## Against the criteria of VEGAS-89

- **Every function name classified, including the 56 of the 714f4a53f
  baseline**: open. The 47 that remain and the six repaired names are
  classified above. The 56 functions of the 714f4a53f inventory have not been
  reconciled with the 51 function names measured before this change.
- **No function name differs, and a check fails when one appears**: the
  check is in place for the cross build. 47 function names still differ.
- **Every data family explained by cause and assigned to its work**: met in
  aggregate only. The 472 names are counted by cause and by owning work
  above; the table of the cause of each name is not committed.
- **Affected units rebuild, links measured, names that become undefined
  accounted for**: met for the units of this change ("Proof").

## Not covered

- 47 function names and 472 data names still differ.
- The four `StagePtr` structs that keep the global name agree only in
  compiled bytes (above). So may other helpers that share a name. The check
  sees them when they diverge.
- The count offset of `blk_00c00000_o2.cpp`'s `StagePtr` and
  `StageReturnPtr` is out of the check's sight after the rename, and is
  recorded here only.
- The comparison names a unit-local relocation target by its symbol when the
  target sits in a section with other objects. Hashing such a section whole
  reports 4 more names, all RTTI base class arrays of `std` templates. The
  tool's README lists them.
- Unwind records and other sections associated with a definition are not
  compared.
- The allowlist records kind and name. A recorded name whose definitions
  diverge further passes.
- The allowlist was measured on the cross build. Whether the native
  windows-x64 build yields the same 519 names is not established: the
  workflow was not run.
- The repaired helpers got names, not real classes. Their bodies, receivers,
  layouts and lifetimes are as before and stay open.
- Nothing executes these functions. Windows execution: not run.
