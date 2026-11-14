# Interior-alias scan (VEGAS-51)

The original release often reaches one array or struct through several names,
each at its own address inside it. Where this tree defines those names as
separate variables, a write through one name does not reach a read through
another. This scan lists every such family so that each can be given one
definition. It is a measurement of the tree, repeated after each repair.

## Inputs

- The recipe, `build/units.json`: every name a unit refers to and its address
  in the original release. The recipe has no sizes.
- The windows-x64 objects of the game archive: which object defines each name,
  and every instruction that refers to one.
- 32-bit objects of the same units, built only for this scan with one section
  per variable. The size of a definition there is its extent in the recipe's
  address space.

The scripts are in `tools/interior-alias-scan/`. Its README gives the command
that repeats the scan and writes the tables below.

## Method

A data name is a recipe name whose address lies after the last function and
which is a variable. Imports, string and float literals, virtual tables and
type information are left out. So are 552 symbols whose mangling has no plain
name, mostly function-local statics and their guards. They are listed in
`interior-alias-scan/other-manglings.tsv`.

A name is inside another when its address is above the other's and below the
other's address plus extent. The other is the container, and the container
with the names inside it is a family.

| Class | Meaning |
| --- | --- |
| aggregate | The container is defined with an extent that covers the names inside. They are interior pointers into a real aggregate, and still separate storage here unless the state says otherwise. |
| disagreement | The container is defined smaller than the code uses it: an instruction indexes it with a register, or reads or writes at or past the end of its definition. Its declared type or size disagrees with its use. |

A disagreement family has no extent in its definition. Its names are the run
that follows the container, up to the next class object or the next name
indexed with another access width. That count is marked "at most".

Two further tables stand beside the families:

- `interior-alias-scan/same-address.tsv`: addresses the recipe gives more than
  one symbol. Either units use different names for one object, or one name
  with different types.
- "Unmeasured containers" below: definitions in the 26 units that do not
  compile for 32-bit. Their extent is bounded from the windows-x64 object, and
  the next name may or may not be inside.

`interior-alias-scan/members.tsv` has one row per family name: its offset in
the container, its kind, the number of recipe units that name it, and how the
windows-x64 code accesses it. An access is a read or a write with the operand
size in bytes, `indexed*N` when an index register scales by N, `address` when
the address is taken and not followed, and `address passed on` when it goes to
a call or into memory. An instruction that only pads code, such as
`nop word ptr cs:[rax + rax]`, is not an access. The units that name an
address are in the recipe.

## Counts

| | Before the first repair | Now |
| --- | ---: | ---: |
| Data addresses in the recipe | 32,751 | 32,751 |
| Defined by an object | 32,065 | 31,826 |
| Defined by no object | 686 | 925 |
| Families | 323 | 323 |
| of class aggregate | 239 | 241 |
| of class disagreement | 84 | 82 |
| Names inside families | 4,320 | 4,320 |
| Families with one owner | 0 | 2 |
| Open families | 323 | 321 |
| Unmeasured containers | 109 | 109 |
| Addresses with more than one symbol | 601 | 601 |

Of the 601 addresses, 518 have different names, 451 of those with different
types as well, and 83 have one name with different types.

The two families with one owner are NiAnimationKey's key sizes and function
tables, described in `docs/animation-key-tables.md`. Their 239 inner names and
two container names are the 241 names no object defines any more. Both were
of class disagreement before: `0x011f3758` was defined as one byte and
`0x011f3780` as one `int`, and both were indexed.

A family has one owner when its container is a native definition that
replaces the recipe names, and no object defines or refers to any other name
of the family. The native owners and their recipe addresses:

| Recipe address | Owner |
| --- | --- |
| `0x011f3758` | `NiAnimationKeyTables::g_keySizes` |
| `0x011f3780` | `NiAnimationKeyTables::g_functions` |

## Limits

- An extent is the size of this tree's definition built for 32-bit, not a
  size read from the original release. A definition with the wrong type has
  the wrong extent, and a family behind it is missed or misjudged.
- A name defined by no object has no extent and contains nothing.
- The run of a disagreement family is an upper bound, not a member list.
- An address that is taken is followed for 60 instructions in the same
  function. Uses after that, or in a callee, are not seen.
- The scan compares definitions and instructions. It does not decide which
  families code writes through one name and reads through another.
- The 552 symbols in `interior-alias-scan/other-manglings.tsv` are in no
  family. A function-local static that lies inside another name's extent, or
  contains one, is not seen.
- Some containers are likely constants, not data. The family at
  `0x00ffffff`, with `DAT_01000000` inside it, is only ever an address that
  is taken. Units use those addresses as the masks `0xffffff` and
  `0x1000000`, for example `formID & (std::uintptr_t)&::DAT_00ffffff` in
  `tesfile.cpp`. The family is listed as the scan finds it.

## Families

"Extent" is in bytes of the original release. "Units" counts the recipe units
that name the container or a name inside it.

| Container | Name | Extent | Class | Names inside | Units | State |
| --- | --- | ---: | --- | ---: | ---: | --- |
| `0x00ffffff` | `DAT_00ffffff` | 4 | aggregate | 2 | 16 | open |
| `0x01090e78` | `DAT_01090e78` | 70 at most | aggregate | 5 | 6 | open |
| `0x01095cec` | `DAT_01095cec` and 1 more | 26 | aggregate | 1 | 1 | open |
| `0x010ade18` | `DAT_010ade18` | 140 | aggregate | 2 | 1 | open |
| `0x010adfbc` | `DAT_010adfbc` | 56 | aggregate | 1 | 2 | open |
| `0x010b17d8` | `DAT_010b17d8` | 372 | aggregate | 1 | 1 | open |
| `0x010b1c70` | `DAT_010b1c70` | 372 | aggregate | 1 | 1 | open |
| `0x010b3788` | `DAT_010b3788` | 372 | aggregate | 1 | 1 | open |
| `0x010b3ad0` | `DAT_010b3ad0` | 372 | aggregate | 1 | 1 | open |
| `0x010b3c58` | `vftable_ImageSpaceShaderHDRBrightPassFilter` | 372 | aggregate | 1 | 1 | open |
| `0x010b3f88` | `vftable_ImageSpaceShaderHDRDownSample9_2` | 372 | aggregate | 1 | 1 | open |
| `0x010bcf6c` | `g_01202510_arg0` and 1 more | 21 | aggregate | 1 | 2 | open |
| `0x010bcfac` | `g_012026a8_arg0` and 1 more | 33 | aggregate | 1 | 2 | open |
| `0x010bcfe0` | `g_012026b8_arg0` and 1 more | 26 | aggregate | 1 | 2 | open |
| `0x010bd048` | `g_01202500_arg0` and 1 more | 23 | aggregate | 1 | 2 | open |
| `0x010bd0d4` | `g_012026f8_arg0` and 1 more | 34 | aggregate | 1 | 2 | open |
| `0x010bd124` | `g_01202548_arg0` and 1 more | 27 | aggregate | 1 | 2 | open |
| `0x010bd264` | `g_01202760_arg0` and 1 more | 35 | aggregate | 1 | 2 | open |
| `0x010bd290` | `g_01202768_arg0` and 1 more | 31 | aggregate | 1 | 2 | open |
| `0x010bd2bc` | `g_01202558_arg0` and 1 more | 27 | aggregate | 1 | 2 | open |
| `0x010bd2f4` | `g_01202780_arg0` and 1 more | 27 | aggregate | 1 | 2 | open |
| `0x010bd350` | `g_01202798_arg0` and 1 more | 29 | aggregate | 1 | 2 | open |
| `0x010bd384` | `g_012027a8_arg0` and 1 more | 26 | aggregate | 1 | 2 | open |
| `0x010bd3e0` | `g_012024e0_arg0` and 1 more | 24 | aggregate | 1 | 2 | open |
| `0x010c4db8` | `DAT_010c4db8` | indexed | disagreement | 1 | 3 | open |
| `0x010c53b4` | `DAT_010c53b4` | indexed | disagreement | 1 | 2 | open |
| `0x010c7310` | `DAT_010c7310` | indexed | disagreement | 1 | 2 | open |
| `0x010c7d48` | `DAT_010c7d48` | indexed | disagreement | 34 at most | 12 | open |
| `0x010c8d14` | `DAT_010c8d14` | indexed | disagreement | 1 | 1 | open |
| `0x010c9288` | `DAT_010c9288` | 136 at most | aggregate | 5 | 18 | open |
| `0x010cb438` | `DAT_010cb438` | indexed | disagreement | 6 at most | 7 | open |
| `0x010cb7a8` | `DAT_010cb7a8` | indexed | disagreement | 24 at most | 11 | open |
| `0x010cbf90` | `DAT_010cbf90@ApplyAccumulatorsPrivate` | 64 | aggregate | 1 | 4 | open |
| `0x010d33c0` | `DAT_010d33c0` | indexed | disagreement | 3 at most | 2 | open |
| `0x010d33d8` | `DAT_010d33d8` | indexed | disagreement | 48 at most | 11 | open |
| `0x010d3ef4` | `str_010d3ef4` | 36 at most | aggregate | 1 | 2 | open |
| `0x010d4d90` | `str_010d4d90@fnv_00da2840` | 24 at most | aggregate | 1 | 1 | open |
| `0x010d52d0` | `DAT_010d52d0` | indexed | disagreement | 14 at most | 8 | open |
| `0x010eb4d4` | `DAT_010eb4d4` | indexed | disagreement | 27 at most | 14 | open |
| `0x010ececc` | `DAT_010ececc` | indexed | disagreement | 34 at most | 8 | open |
| `0x01183320` | `DAT_01183320` | indexed | disagreement | 49 at most | 41 | open |
| `0x0118869c` | `g_akA8F70Slots` | 20 | aggregate | 1 | 1 | open |
| `0x01188b74` | `DAT_01188b74` | 20 | aggregate | 1 | 3 | open |
| `0x01189fa0` | `g_ppFurnitureMarkerOffsetSettings` | 16 | aggregate | 1 | 1 | open |
| `0x0118ae90` | `DAT_0118ae90` | indexed | disagreement | 6 at most | 4 | open |
| `0x0118cad0` | `DAT_0118cad0` | 128 | aggregate | 2 | 2 | open |
| `0x01190900` | `DAT_01190900` | 40 | aggregate | 1 | 6 | open |
| `0x011977a4` | `DAT_011977a4` | indexed | disagreement | 2 at most | 11 | open |
| `0x011977e0` | `DAT_011977e0` and 2 more | indexed | disagreement | 3 at most | 6 | open |
| `0x01199e8c` | `DAT_01199e8c` | 8 at most | aggregate | 1 | 4 | open |
| `0x01199fbc` | `DAT_01199fbc` | indexed | disagreement | 6 at most | 3 | open |
| `0x0119b35c` | `DAT_0119b35c` | indexed | disagreement | 2 at most | 2 | open |
| `0x0119b4a0` | `DAT_0119b4a0` | indexed | disagreement | 2 at most | 2 | open |
| `0x0119b734` | `DAT_0119b734` | indexed | disagreement | 20 at most | 22 | open |
| `0x011a00c4` | `DAT_011a00c4@fnv_0077eaf0` | indexed | disagreement | 9 | 2 | open |
| `0x011a216c` | `DAT_011a216c` | 4000 | aggregate | 18 | 17 | open |
| `0x011a3780` | `DAT_011a3780` | 8 | aggregate | 2 | 1 | open |
| `0x011a55b0` | `DAT_011a55b0` | 8 | aggregate | 1 | 2 | open |
| `0x011a5650` | `MoveModes` | 8 | aggregate | 1 | 3 | open |
| `0x011a8400` | `DAT_011a8400` | 12 | aggregate | 2 | 14 | open |
| `0x011a9424` | `DAT_011a9424` | 12 | aggregate | 2 | 3 | open |
| `0x011a946c` | `DAT_011a946c` | indexed | disagreement | 2 | 21 | open |
| `0x011a9490` | `DAT_011a9490` | 12 | aggregate | 2 | 9 | open |
| `0x011a9bd0` | `DAT_011a9bd0` | 16 | aggregate | 3 | 24 | open |
| `0x011a9be0` | `DAT_011a9be0` | 16 | aggregate | 3 | 13 | open |
| `0x011ac3b0` | `DAT_011ac3b0` | indexed | disagreement | 20 at most | 13 | open |
| `0x011ad830` | `DAT_011ad830@fnv_004da670` | 4 | aggregate | 1 | 4 | open |
| `0x011ad840` | `DAT_011ad840` | indexed | disagreement | 3 | 11 | open |
| `0x011adbd8` | `g_afBlurKernel` | 240 | aggregate | 1 | 2 | open |
| `0x011adf18` | `g_afBlurWeights` | 1920 | aggregate | 25 | 20 | open |
| `0x011afe88` | `DAT_011afe88` | indexed | disagreement | 30 at most | 14 | open |
| `0x011b37a4` | `DAT_011b37a4` | indexed | disagreement | 2 at most | 1 | open |
| `0x011b3b4c` | `DAT_011b3b4c` | indexed | disagreement | 3 at most | 2 | open |
| `0x011b5a90` | `DAT_011b5a90` | indexed | disagreement | 25 at most | 12 | open |
| `0x011b6ab0` | `DAT_011b6ab0` | indexed | disagreement | 2 at most | 3 | open |
| `0x011b7b88` | `DAT_011b7b88` and 1 more | 4 | aggregate | 1 | 12 | open |
| `0x011b9434` | `DAT_011b9434` | 128 | aggregate | 1 | 3 | open |
| `0x011c3c0e` | `g_011c3c0e` | 4 | aggregate | 2 | 3 | open |
| `0x011c52a8` | `DAT_011c52a8` | indexed | disagreement | 5 at most | 1 | open |
| `0x011c52c1` | `g_011c52c1` | 4 | aggregate | 1 | 2 | open |
| `0x011c5cb5` | `g_011c5cb5` | 4 | aggregate | 1 | 2 | open |
| `0x011c70f9` | `g_011c70f9` | 4 | aggregate | 1 | 2 | open |
| `0x011c7b78` | `g_011c7b78` | 4 | aggregate | 1 | 2 | open |
| `0x011c8fa2` | `g_011c8fa2` | 4 | aggregate | 1 | 2 | open |
| `0x011c9355` | `g_011c9355` | 4 | aggregate | 1 | 2 | open |
| `0x011ca091` | `g_011ca091` | 4 | aggregate | 1 | 5 | open |
| `0x011cab25` | `g_011cab25` | 4 | aggregate | 1 | 2 | open |
| `0x011caf37` | `g_011caf37` | 4 | aggregate | 1 | 2 | open |
| `0x011cb6a9` | `g_011cb6a9` | 4 | aggregate | 1 | 2 | open |
| `0x011cb9e4` | `g_011cb9e4` | 4 | aggregate | 1 | 1 | open |
| `0x011d5128` | `DAT_011d5128@fnv_0086c880` | 56 | aggregate | 1 | 2 | open |
| `0x011d5160` | `DAT_011d5160` | indexed | disagreement | 11 at most | 10 | open |
| `0x011d6124` | `g_011d6124` | indexed | disagreement | 2 | 6 | open |
| `0x011d6155` | `g_011d6155` | 4 | aggregate | 1 | 2 | open |
| `0x011d61c8` | `g_011d61c8` | indexed | disagreement | 1 at most | 4 | open |
| `0x011d6ae5` | `g_011d6ae5` | 4 | aggregate | 1 | 2 | open |
| `0x011d85d0` | `g_011d85d0` | indexed | disagreement | 1 | 2 | open |
| `0x011d8828` | `s_faders` | 84 | aggregate | 1 | 3 | open |
| `0x011d8a54` | `DAT_011d8a54@fnv_0070c4a0` | 16 | aggregate | 6 | 3 | open |
| `0x011d8a6c` | `DAT_011d8a6c@fnv_0070c4a0` | 16 | aggregate | 5 | 2 | open |
| `0x011d8c4c` | `DAT_011d8c4c` and 1 more | 12 | aggregate | 1 | 5 | open |
| `0x011d8fc1` | `g_011d8fc1` | 4 | aggregate | 1 | 2 | open |
| `0x011d9185` | `g_011d9185` | 4 | aggregate | 1 | 2 | open |
| `0x011d947d` | `g_011d947d` | 4 | aggregate | 1 | 2 | open |
| `0x011d96c6` | `g_011d96c6` | 4 | aggregate | 1 | 2 | open |
| `0x011da0ca` | `g_011da0ca` | 4 | aggregate | 1 | 2 | open |
| `0x011da53c` | `g_011da53c` | indexed | disagreement | 1 | 3 | open |
| `0x011da689` | `g_011da689` | 4 | aggregate | 1 | 2 | open |
| `0x011daacf` | `g_011daacf` | 4 | aggregate | 1 | 2 | open |
| `0x011db379` | `g_011db379` | 4 | aggregate | 1 | 4 | open |
| `0x011dbe11` | `g_011dbe11` | 4 | aggregate | 1 | 2 | open |
| `0x011dbe52` | `g_011dbe52` | 4 | aggregate | 1 | 2 | open |
| `0x011dbf7d` | `g_011dbf7d` | 4 | aggregate | 1 | 2 | open |
| `0x011dc036` | `g_011dc036` | 4 | aggregate | 1 | 2 | open |
| `0x011dc33d` | `g_011dc33d` | 4 | aggregate | 1 | 2 | open |
| `0x011dc60c` | `g_011dc60c` | 4 | aggregate | 1 | 1 | open |
| `0x011dc999` | `g_011dc999` | 4 | aggregate | 1 | 2 | open |
| `0x011dcb0d` | `g_011dcb0d` | 4 | aggregate | 1 | 3 | open |
| `0x011dcb89` | `g_011dcb89` | 4 | aggregate | 1 | 2 | open |
| `0x011dcd81` | `g_011dcd81` | 4 | aggregate | 1 | 2 | open |
| `0x011dce51` | `g_011dce51` | 4 | aggregate | 1 | 2 | open |
| `0x011dcee5` | `g_011dcee5` | 4 | aggregate | 1 | 3 | open |
| `0x011dd650` | `DAT_011dd650` | 40 | aggregate | 1 | 1 | open |
| `0x011dd878` | `DAT_011dd878` | indexed | disagreement | 27 | 8 | open |
| `0x011de23d` | `g_011de23d` | 4 | aggregate | 1 | 2 | open |
| `0x011de360` | `DAT_011de360` | indexed | disagreement | 8 at most | 5 | open |
| `0x011df69c` | `g_011df69c` | 4 | aggregate | 3 | 3 | open |
| `0x011df71c` | `g_011df71c` | 4 | aggregate | 2 | 2 | open |
| `0x011dfa1a` | `g_011dfa1a` | 4 | aggregate | 1 | 2 | open |
| `0x011e0244` | `g_011e0244` | 4 | aggregate | 3 | 2 | open |
| `0x011e0361` | `g_011e0361` | 4 | aggregate | 2 | 3 | open |
| `0x011e0460` | `g_011e0460` | 4 | aggregate | 1 | 2 | open |
| `0x011e0528` | `g_011e0528` | 4 | aggregate | 1 | 2 | open |
| `0x011e0551` | `g_011e0551` | 4 | aggregate | 1 | 2 | open |
| `0x011e0784` | `DAT_011e0784` | 8 | aggregate | 1 | 3 | open |
| `0x011e0e80` | `g_011e0e80` | indexed | disagreement | 14 at most | 80 | open |
| `0x011f1388` | `g_011f1388` | 4 | aggregate | 1 | 1 | open |
| `0x011f15cc` | `g_011f15cc` | 4 | aggregate | 1 | 2 | open |
| `0x011f1a60` | `g_011f1a60` | 4 | aggregate | 3 | 2 | open |
| `0x011f1c7c` | `g_011f1c7c` | 4 | aggregate | 1 | 2 | open |
| `0x011f1d6c` | `g_011f1d6c` | 4 | aggregate | 1 | 1 | open |
| `0x011f20a5` | `g_011f20a5` | 4 | aggregate | 1 | 2 | open |
| `0x011f24e4` | `g_011f24e4` | 4 | aggregate | 1 | 2 | open |
| `0x011f308f` | `DAT_011f308f` and 1 more | indexed | disagreement | 95 at most | 18 | open |
| `0x011f3508` | `DAT_011f3508` and 1 more | indexed | disagreement | 2 | 4 | open |
| `0x011f35a8` | `DAT_011f35a8` | 16 | aggregate | 7 | 2 | open |
| `0x011f35b8` | `DAT_011f35b8` | 16 | aggregate | 3 | 1 | open |
| `0x011f3638` | `g_011f3638` | 12 | aggregate | 1 | 2 | open |
| `0x011f3704` | `DAT_011f3704` | indexed | disagreement | 1 | 14 | open |
| `0x011f3758` | `DAT_011f3758` and 1 more | 36 | aggregate | 20 | 15 | one owner |
| `0x011f3780` | `DAT_011f3780` and 1 more | 1728 | aggregate | 219 | 21 | one owner |
| `0x011f4208` | `DAT_011f4208` | 16 | aggregate | 3 | 3 | open |
| `0x011f426c` | `DAT_011f426c` and 41 more | indexed | disagreement | 2 | 188 | open |
| `0x011f4288` | `DAT_011f4288` and 1 more | 16 | aggregate | 1 | 45 | open |
| `0x011f42a0` | `DAT_011f42a0` | indexed | disagreement | 1 | 3 | open |
| `0x011f4480` | `g_spinLock` | 32 | aggregate | 1 | 4 | open |
| `0x011f474c` | `DAT_011f474c` | 12 | aggregate | 2 | 12 | open |
| `0x011f4980` | `DAT_011f4980` | 8 | aggregate | 1 | 8 | open |
| `0x011f4998` | `DAT_011f4998` | 12 | aggregate | 2 | 21 | open |
| `0x011f49b0` | `ms_kTextureMapNames@NiTexturingProperty` | 40 | aggregate | 9 | 2 | open |
| `0x011f49e0` | `DAT_011f49e0` | indexed | disagreement | 3 | 21 | open |
| `0x011f5f7c` | `DAT_011f5f7c` | indexed | disagreement | 8 at most | 2 | open |
| `0x011f5f90` | `DAT_011f5f90` | indexed | disagreement | 45 at most | 9 | open |
| `0x011f6238` | `DAT_011f6238` and 14 more | 21524 | aggregate | 708 | 388 | open |
| `0x011fc0a0` | `DAT_011fc0a0` | indexed | disagreement | 561 at most | 6 | open |
| `0x011fda48` | `DAT_011fda48` | 832 | aggregate | 189 | 4 | open |
| `0x011fdd88` | `DAT_011fdd88@fnv_00b79de0` | 624 | aggregate | 140 | 4 | open |
| `0x011fdff8` | `DAT_011fdff8@fnv_00b7a730` | 3036 | aggregate | 298 | 5 | open |
| `0x011febd8` | `DAT_011febd8` | indexed | disagreement | 21 | 4 | open |
| `0x011fec30` | `DAT_011fec30` | indexed | disagreement | 17 | 4 | open |
| `0x011ff110` | `DAT_011ff110` | indexed | disagreement | 4 | 2 | open |
| `0x011ff118` | `DAT_011ff118` | indexed | disagreement | 2 | 2 | open |
| `0x011ff120` | `DAT_011ff120` | indexed | disagreement | 78 at most | 3 | open |
| `0x011ff3a8` | `DAT_011ff3a8` | 16 | aggregate | 3 | 3 | open |
| `0x011ff4a0` | `DAT_011ff4a0` | indexed | disagreement | 2 | 2 | open |
| `0x011ff4ac` | `DAT_011ff4ac` | indexed | disagreement | 5 | 2 | open |
| `0x011ff4c8` | `g_akVertexConstantsB824B0` | 176 | aggregate | 3 | 2 | open |
| `0x011ff578` | `g_akPixelConstantsB824B0` | 496 | aggregate | 20 | 2 | open |
| `0x011ff9d8` | `DAT_011ff9d8` | indexed | disagreement | 51 at most | 15 | open |
| `0x011ffe48` | `DAT_011ffe48` | indexed | disagreement | 12 | 3 | open |
| `0x01200004` | `DAT_01200004` | indexed | disagreement | 3 | 3 | open |
| `0x01200014` | `DAT_01200014` | indexed | disagreement | 3 | 4 | open |
| `0x01200024` | `DAT_01200024@fnv_004e8ec0` | indexed | disagreement | 1 | 2 | open |
| `0x0120007c` | `g_0120007c` | 12 | aggregate | 1 | 2 | open |
| `0x012003d4` | `DAT_012003d4` | indexed | disagreement | 2 | 3 | open |
| `0x01200540` | `DAT_01200540` | 16 | aggregate | 1 | 2 | open |
| `0x012005e4` | `g_afEyePos_012005e4` | 16 | aggregate | 1 | 1 | open |
| `0x01200638` | `DAT_01200638` | indexed | disagreement | 3 | 2 | open |
| `0x01200648` | `DAT_01200648` | indexed | disagreement | 3 | 2 | open |
| `0x01200800` | `DAT_01200800` | indexed | disagreement | 3 | 4 | open |
| `0x01200848` | `DAT_01200848` | indexed | disagreement | 9 | 1 | open |
| `0x01200854` | `DAT_01200854` | indexed | disagreement | 1 | 2 | open |
| `0x01200868` | `DAT_01200868` | indexed | disagreement | 234 at most | 4 | open |
| `0x01200c48` | `DAT_01200c48` | 200 | aggregate | 48 | 3 | open |
| `0x01200dd8` | `DAT_01200dd8` | 228 | aggregate | 56 | 3 | open |
| `0x01200ec0` | `DAT_01200ec0` | 448 | aggregate | 111 | 4 | open |
| `0x01201080` | `DAT_01201080` | 68 | aggregate | 16 | 3 | open |
| `0x012010c4` | `DAT_012010c4` | 40 | aggregate | 9 | 2 | open |
| `0x012010f0` | `DAT_012010f0@fnv_00bbce70` | 2624 | aggregate | 20 | 1 | open |
| `0x01201b30` | `DAT_01201b30` | indexed | disagreement | 14 at most | 2 | open |
| `0x01201c80` | `DAT_01201c80` | 32 | aggregate | 1 | 2 | open |
| `0x01201f30` | `DAT_01201f30` | indexed | disagreement | 3 | 3 | open |
| `0x01202198` | `DAT_01202198` | 16 | aggregate | 3 | 1 | open |
| `0x01202230` | `DAT_01202230` | indexed | disagreement | 32 | 2 | open |
| `0x012022c0` | `g_aiPassIndex_fd20` | 104 | aggregate | 25 | 2 | open |
| `0x01202350` | `DAT_01202350` | indexed | disagreement | 29 | 2 | open |
| `0x012023d0` | `g_012023d0` | 12 | aggregate | 1 | 2 | open |
| `0x0120249c` | `g_0120249c` | 12 | aggregate | 1 | 2 | open |
| `0x01202e20` | `DAT_01202e20` | indexed | disagreement | 3 | 1 | open |
| `0x01203120` | `g_01203120` | 12 | aggregate | 1 | 3 | open |
| `0x0120312c` | `g_0120312c` | 12 | aggregate | 1 | 3 | open |
| `0x01203138` | `g_01203138` | 12 | aggregate | 1 | 3 | open |
| `0x01267b1c` | `g_01267b1c` | 12 | aggregate | 1 | 3 | open |
| `0x01267b28` | `g_01267b28` | 12 | aggregate | 1 | 3 | open |
| `0x01267b40` | `g_01267b40` | 12 | aggregate | 1 | 2 | open |
| `0x01267b80` | `DAT_01267b80` | 8 | aggregate | 1 | 4 | open |
| `0x01267c24` | `g_01267c24` and 1 more | 12 | aggregate | 1 | 4 | open |
| `0x01267c30` | `g_01267c30` | 12 | aggregate | 1 | 4 | open |
| `0x01267c3c` | `g_01267c3c` | 12 | aggregate | 1 | 3 | open |
| `0x01267c48` | `g_01267c48` | 12 | aggregate | 1 | 3 | open |
| `0x01267c54` | `g_01267c54` | 12 | aggregate | 1 | 2 | open |
| `0x01267c60` | `g_01267c60` | 12 | aggregate | 1 | 2 | open |
| `0x01267dc8` | `g_01267dc8` | 12 | aggregate | 1 | 2 | open |
| `0x01267e30` | `DAT_01267e30` | indexed | disagreement | 2 | 61 | open |
| `0x01267e70` | `DAT_01267e70@fnv_00c828f0` | 172 | aggregate | 3 | 3 | open |
| `0x01268334` | `DAT_01268334` | indexed | disagreement | 1 | 1 | open |
| `0x01268370` | `DAT_01268370` and 1 more | indexed | disagreement | 3 at most | 38 | open |
| `0x012683b0` | `DAT_012683b0` | indexed | disagreement | 3 | 8 | open |
| `0x01268460` | `DAT_01268460` | indexed | disagreement | 2 at most | 10 | open |
| `0x01268778` | `g_01268778` | 168 | aggregate | 7 | 13 | open |
| `0x012688f8` | `g_012688f8` | 168 | aggregate | 3 | 16 | open |
| `0x01268a78` | `g_01268a78` | 168 | aggregate | 6 | 18 | open |
| `0x01268b84` | `g_01268b84` | 168 | aggregate | 4 | 5 | open |
| `0x01268c44` | `g_01268c44` | 168 | aggregate | 3 | 5 | open |
| `0x01268cec` | `g_01268cec` | 168 | aggregate | 4 | 4 | open |
| `0x01268e54` | `g_01268e54` | 168 | aggregate | 4 | 4 | open |
| `0x01268f5c` | `g_01268f5c` | 168 | aggregate | 25 | 18 | open |
| `0x012690bc` | `g_012690bc` | 168 | aggregate | 5 | 5 | open |
| `0x01269544` | `g_01269544` | 168 | aggregate | 3 | 4 | open |
| `0x012696ac` | `g_012696ac` | 168 | aggregate | 4 | 3 | open |
| `0x01269784` | `g_01269784` | 168 | aggregate | 3 | 3 | open |
| `0x01269a3c` | `g_01269a3c` | 168 | aggregate | 7 | 6 | open |
| `0x01269b58` | `g_01269b58` | 168 | aggregate | 8 | 9 | open |
| `0x01269c74` | `g_01269c74` | 168 | aggregate | 14 | 31 | open |
| `0x0126a3e0` | `DAT_0126a3e0` | 64 | aggregate | 3 | 3 | open |
| `0x0126a460` | `g_0126a460` | 168 | aggregate | 3 | 3 | open |
| `0x0126aa48` | `g_0126aa48` | 168 | aggregate | 3 | 3 | open |
| `0x0126ac40` | `g_0126ac40` | 168 | aggregate | 4 | 3 | open |
| `0x0126adc0` | `g_0126adc0` | 168 | aggregate | 3 | 3 | open |
| `0x0126ae68` | `g_0126ae68` | 168 | aggregate | 3 | 3 | open |
| `0x0126af70` | `g_0126af70` | 168 | aggregate | 4 | 3 | open |
| `0x0126b060` | `g_0126b060` | 168 | aggregate | 3 | 3 | open |
| `0x0126b168` | `g_0126b168` | 168 | aggregate | 4 | 3 | open |
| `0x0126b318` | `g_0126b318` | 168 | aggregate | 4 | 3 | open |
| `0x0126b408` | `g_0126b408` | 168 | aggregate | 4 | 3 | open |
| `0x0126b4c8` | `g_0126b4c8` | 168 | aggregate | 4 | 3 | open |
| `0x0126b5b8` | `g_0126b5b8` | 168 | aggregate | 4 | 3 | open |
| `0x0126b798` | `g_0126b798` | 168 | aggregate | 3 | 3 | open |
| `0x0126b840` | `g_0126b840` | 168 | aggregate | 4 | 3 | open |
| `0x0126b930` | `g_0126b930` | 168 | aggregate | 4 | 3 | open |
| `0x0126ba20` | `g_0126ba20` | 168 | aggregate | 4 | 3 | open |
| `0x0126bb10` | `g_0126bb10` | 168 | aggregate | 4 | 3 | open |
| `0x0126bc00` | `g_0126bc00` | 168 | aggregate | 4 | 3 | open |
| `0x0126bcf0` | `g_0126bcf0` | 168 | aggregate | 4 | 3 | open |
| `0x0126bde0` | `g_0126bde0` | 168 | aggregate | 4 | 3 | open |
| `0x0126bf30` | `g_0126bf30` | 168 | aggregate | 4 | 3 | open |
| `0x0126c050` | `g_0126c050` | 168 | aggregate | 4 | 3 | open |
| `0x0126c140` | `g_0126c140` | 168 | aggregate | 4 | 3 | open |
| `0x0126c290` | `g_0126c290` | 168 | aggregate | 3 | 3 | open |
| `0x0126c3f8` | `g_0126c3f8` | 168 | aggregate | 4 | 3 | open |
| `0x0126c4e8` | `g_0126c4e8` | 168 | aggregate | 4 | 3 | open |
| `0x0126c5d8` | `g_0126c5d8` | 168 | aggregate | 4 | 4 | open |
| `0x0126c758` | `g_0126c758` | 168 | aggregate | 3 | 3 | open |
| `0x0126c8f0` | `g_0126c8f0` | 168 | aggregate | 3 | 3 | open |
| `0x0126cb78` | `g_0126cb78` | 168 | aggregate | 4 | 3 | open |
| `0x0126cc50` | `g_0126cc50` | 168 | aggregate | 4 | 3 | open |
| `0x0126cd28` | `g_0126cd28` | 168 | aggregate | 4 | 3 | open |
| `0x0126ce00` | `g_0126ce00` | 168 | aggregate | 4 | 3 | open |
| `0x0126ced8` | `g_0126ced8` | 168 | aggregate | 4 | 3 | open |
| `0x0126cfb0` | `g_0126cfb0` | 168 | aggregate | 4 | 3 | open |
| `0x0126d088` | `g_0126d088` | 168 | aggregate | 4 | 3 | open |
| `0x0126d160` | `g_0126d160` | 168 | aggregate | 4 | 3 | open |
| `0x0126d208` | `g_0126d208` | 168 | aggregate | 4 | 3 | open |
| `0x0126d2c8` | `g_0126d2c8` | 168 | aggregate | 4 | 3 | open |
| `0x0126d3a0` | `g_0126d3a0` | 168 | aggregate | 4 | 3 | open |
| `0x0126d478` | `g_0126d478` | 168 | aggregate | 4 | 3 | open |
| `0x0126d538` | `g_0126d538` | 168 | aggregate | 5 | 3 | open |
| `0x0126d5f8` | `g_0126d5f8` | 168 | aggregate | 4 | 4 | open |
| `0x0126d6b8` | `g_0126d6b8` | 168 | aggregate | 4 | 3 | open |
| `0x0126d790` | `g_0126d790` | 168 | aggregate | 4 | 3 | open |
| `0x0126d868` | `g_0126d868` | 168 | aggregate | 4 | 3 | open |
| `0x0126d940` | `g_0126d940` | 168 | aggregate | 4 | 4 | open |
| `0x0126da18` | `g_0126da18` | 168 | aggregate | 4 | 3 | open |
| `0x0126daf0` | `g_0126daf0` | 168 | aggregate | 4 | 3 | open |
| `0x0126dbc8` | `g_0126dbc8` | 168 | aggregate | 4 | 3 | open |
| `0x0126dca0` | `g_0126dca0` | 168 | aggregate | 4 | 3 | open |
| `0x0126dd78` | `g_0126dd78` | 168 | aggregate | 4 | 3 | open |
| `0x0126de50` | `g_0126de50` | 168 | aggregate | 4 | 3 | open |
| `0x0126df28` | `g_0126df28` | 168 | aggregate | 4 | 3 | open |
| `0x0126e000` | `g_0126e000` | 168 | aggregate | 4 | 3 | open |
| `0x0126e0d8` | `g_0126e0d8` | 168 | aggregate | 4 | 3 | open |
| `0x0126e1b0` | `g_0126e1b0` | 168 | aggregate | 4 | 3 | open |
| `0x0126e288` | `g_0126e288` | 168 | aggregate | 4 | 3 | open |
| `0x0126e360` | `g_0126e360` | 168 | aggregate | 4 | 3 | open |
| `0x0126e438` | `g_0126e438` | 168 | aggregate | 4 | 3 | open |
| `0x0126e510` | `g_0126e510` | 168 | aggregate | 4 | 4 | open |
| `0x0126e5e8` | `g_0126e5e8` | 168 | aggregate | 4 | 4 | open |
| `0x0126e6c0` | `g_0126e6c0` | 168 | aggregate | 4 | 3 | open |
| `0x0126e798` | `g_0126e798` | 168 | aggregate | 4 | 3 | open |
| `0x0126e870` | `g_0126e870` | 168 | aggregate | 4 | 3 | open |
| `0x0126e948` | `g_0126e948` | 168 | aggregate | 4 | 3 | open |
| `0x0126ea20` | `g_0126ea20` | 168 | aggregate | 4 | 4 | open |
| `0x0126eaf8` | `g_0126eaf8` | 168 | aggregate | 4 | 4 | open |
| `0x0126ebd0` | `g_0126ebd0` | 168 | aggregate | 6 | 8 | open |
| `0x0126f050` | `DAT_0126f050` | indexed | disagreement | 41 at most | 12 | open |
| `0x0126f5c8` | `DAT_0126f5c8` | 24 at most | aggregate | 2 | 2 | open |
| `0x0126f6d0` | `DAT_0126f6d0` | indexed | disagreement | 12 | 1 | open |
| `0x0126f738` | `DAT_0126f738` | indexed | disagreement | 6 at most | 25 | open |
| `0x0126f7c4` | `g_0126f7c4` | indexed | disagreement | 5 at most | 3 | open |
| `0x0126f918` | `DAT_0126f918` | indexed | disagreement | 4 | 1 | open |
| `0x0126fa7c` | `DAT_0126fa7c` | indexed | disagreement | 13 at most | 4 | open |
| `0x0126fae0` | `g_0126fae0` | 12 | aggregate | 1 | 2 | open |
| `0x01272000` | `g_renderTLS` and 6 more | 712 | aggregate | 25 | 90 | open |

## Unmeasured containers

| Container | Name | Kind | Extent between | Names in the uncertain part |
| --- | --- | --- | --- | ---: |
| `0x00fdf050` | `DAT_0fdf050` | c-symbol | 1 and 8 | 1 |
| `0x01016f1c` | `DAT_01016f1c@fnv_00566970` | pointer or array of arithmetic | 25 and 32 | 1 |
| `0x01016f58` | `DAT_01016f58@fnv_00566970` | pointer or array of arithmetic | 25 and 32 | 1 |
| `0x0102cb10` | `DAT_0102cb10` and 1 more | arithmetic/c-symbol | 1 and 64 | 2 |
| `0x01076e68` | `xg_ExeVersion` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x0108b050` | `DAT_0108b050` | pointer or array of arithmetic | 17 and 24 | 1 |
| `0x0108b064` | `DAT_0108b064` | pointer or array of arithmetic | 17 and 24 | 1 |
| `0x0108b3bc` | `str_0108b3bc@fnv_0095ee80` | pointer or array of arithmetic | 25 and 32 | 1 |
| `0x01090d70` | `DAT_01090d70` | pointer or array of arithmetic | 25 and 32 | 1 |
| `0x01090d8c` | `DAT_01090d8c` | pointer or array of arithmetic | 41 and 48 | 1 |
| `0x01090dc8` | `DAT_01090dc8` | pointer or array of arithmetic | 33 and 40 | 1 |
| `0x01090dec` | `DAT_01090dec` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x01090df8` | `DAT_01090df8` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x01090e04` | `DAT_01090e04` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x01090e40` | `DAT_01090e40` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x01090e6c` | `DAT_01090e6c` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x010a3524` | `str_010a3524` | pointer or array of arithmetic | 5 and 12 | 1 |
| `0x010a353c` | `str_010a353c` | pointer or array of arithmetic | 33 and 40 | 1 |
| `0x010a3608` | `str_010a3608` | pointer or array of arithmetic | 25 and 32 | 1 |
| `0x010a3624` | `str_010a3624` | pointer or array of arithmetic | 17 and 24 | 1 |
| `0x010a3670` | `str_010a3670` | pointer or array of arithmetic | 17 and 24 | 1 |
| `0x010a3694` | `str_010a3694` | pointer or array of arithmetic | 17 and 24 | 1 |
| `0x010a36a8` | `str_010a36a8` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x010a36b4` | `str_010a36b4` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x010c1e28` | `str_010c1e28` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x010c99f8` | `DAT_010c99f8` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x010d4c60` | `str_010d4c60@fnv_00da2840` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x010d4c84` | `str_010d4c84@fnv_00da2840` | pointer or array of arithmetic | 17 and 24 | 1 |
| `0x010d4c98` | `str_010d4c98@fnv_00da2840` | pointer or array of arithmetic | 25 and 32 | 1 |
| `0x010d4cb4` | `str_010d4cb4@fnv_00da2840` | pointer or array of arithmetic | 9 and 16 | 1 |
| `0x010d4cc0` | `str_010d4cc0@fnv_00da2840` | pointer or array of arithmetic | 17 and 24 | 1 |
| `0x011977dc` | `DAT_011977dc` | pointer or array of class | 1 and 40 | 2 |
| `0x01199a50` | `PTR_s_Start_01199a50` | pointer or array of class | 1 and 448 | 3 |
| `0x011a9418` | `DAT_011a9418` | pointer or array of class | 1 and 8 | 1 |
| `0x011aa210` | `DAT_011aa210` | class | 40 and 80 | 1 |
| `0x011aa408` | `DAT_011aa408` | class | 40 and 80 | 1 |
| `0x011aa498` | `DAT_011aa498` | class | 40 and 80 | 1 |
| `0x011aa4e0` | `DAT_011aa4e0` | class | 40 and 80 | 1 |
| `0x011aa528` | `DAT_011aa528` | class | 40 and 80 | 1 |
| `0x011aa570` | `DAT_011aa570` | class | 40 and 80 | 1 |
| `0x011aa5b8` | `DAT_011aa5b8` | class | 40 and 80 | 1 |
| `0x011aa600` | `DAT_011aa600` | class | 40 and 80 | 1 |
| `0x011aa648` | `DAT_011aa648` | class | 40 and 80 | 1 |
| `0x011aa690` | `DAT_011aa690` | class | 40 and 80 | 1 |
| `0x011aa6d8` | `DAT_011aa6d8` | class | 40 and 80 | 1 |
| `0x011aa768` | `DAT_011aa768` | class | 40 and 80 | 1 |
| `0x011aa7b0` | `DAT_011aa7b0` | class | 40 and 80 | 1 |
| `0x011aa960` | `DAT_011aa960` | class | 40 and 80 | 1 |
| `0x011aa9a8` | `DAT_011aa9a8` | class | 40 and 80 | 1 |
| `0x011aa9f0` | `DAT_011aa9f0` | class | 40 and 80 | 1 |
| `0x011aaa38` | `DAT_011aaa38` | class | 40 and 80 | 1 |
| `0x011aaa80` | `DAT_011aaa80` | class | 40 and 80 | 1 |
| `0x011aaac8` | `DAT_011aaac8` | class | 40 and 80 | 1 |
| `0x011aab58` | `DAT_011aab58` | class | 40 and 80 | 1 |
| `0x011aaba0` | `DAT_011aaba0` | class | 40 and 80 | 1 |
| `0x011aabe8` | `DAT_011aabe8` | class | 40 and 80 | 1 |
| `0x011aacc0` | `DAT_011aacc0` | class | 40 and 80 | 1 |
| `0x011aad08` | `DAT_011aad08` | class | 40 and 80 | 1 |
| `0x011aad50` | `DAT_011aad50` | class | 40 and 80 | 1 |
| `0x011aad98` | `DAT_011aad98` | class | 40 and 80 | 1 |
| `0x011aade0` | `DAT_011aade0` | class | 40 and 80 | 1 |
| `0x011aae28` | `DAT_011aae28` | class | 40 and 80 | 1 |
| `0x011aae70` | `DAT_011aae70` | class | 40 and 80 | 1 |
| `0x011aaeb8` | `DAT_011aaeb8` | class | 40 and 80 | 1 |
| `0x011aaf00` | `DAT_011aaf00` | class | 40 and 80 | 1 |
| `0x011aaf48` | `DAT_011aaf48` | class | 40 and 80 | 1 |
| `0x011ab020` | `DAT_011ab020` | class | 53 and 105 | 1 |
| `0x011ab068` | `DAT_011ab068` | class | 40 and 80 | 1 |
| `0x011ab0b0` | `DAT_011ab0b0` | class | 40 and 80 | 1 |
| `0x011ab0f8` | `DAT_011ab0f8` | class | 40 and 80 | 1 |
| `0x011ab140` | `DAT_011ab140` | class | 40 and 80 | 1 |
| `0x011ab188` | `DAT_011ab188` | class | 40 and 80 | 1 |
| `0x011ab1d0` | `DAT_011ab1d0` | class | 40 and 80 | 1 |
| `0x011ab2a8` | `DAT_011ab2a8` | class | 40 and 80 | 1 |
| `0x011b1750` | `DAT_011b1750` | pointer or array of arithmetic | 4 and 8 | 1 |
| `0x011b6c4c` | `DAT_011b6c4c` | pointer or array of class | 1 and 16 | 1 |
| `0x011c54c0` | `DAT_011c54c0@fnv_00483370` | pointer or array of class | 1 and 8 | 1 |
| `0x011c61a8` | `DAT_011c61a8` | pointer or array of class | 1 and 8 | 1 |
| `0x011c61b0` | `DAT_011c61b0` | pointer or array of class | 1 and 8 | 1 |
| `0x011c61b8` | `DAT_011c61b8` | pointer or array of class | 1 and 8 | 1 |
| `0x011c623c` | `DAT_011c623c` | pointer or array of class | 1 and 8 | 1 |
| `0x011c6264` | `DAT_011c6264` | pointer or array of class | 1 and 8 | 1 |
| `0x011c626c` | `DAT_011c626c` | pointer or array of class | 1 and 8 | 1 |
| `0x011c6270` | `DAT_011c6270` | pointer or array of class | 1 and 8 | 1 |
| `0x011c6274` | `DAT_011c6274` | pointer or array of class | 1 and 8 | 1 |
| `0x011c7804` | `g_spDebrisNormalMap` | class | 4 and 8 | 1 |
| `0x011c7808` | `g_spDebrisTexture` | class | 4 and 8 | 1 |
| `0x011c780c` | `g_spDebrisShadowTexture` | class | 4 and 8 | 1 |
| `0x011c9618` | `DAT_011c9618` | pointer or array of class | 1 and 8 | 1 |
| `0x011de134` | `DAT_011de134` | pointer or array of class | 1 and 8 | 1 |
| `0x011e0760` | `DAT_011e0760` | pointer or array of class | 1 and 8 | 1 |
| `0x011e07a4` | `DAT_011e07a4@fnv_00953ff0` | pointer or array of class | 1 and 8 | 4 |
| `0x011e07cc` | `DAT_011e07cc@fnv_0094e1d0` | pointer or array of class | 1 and 8 | 1 |
| `0x011e07d8` | `DAT_011e07d8@fnv_0094ae40` | pointer or array of class | 1 and 8 | 1 |
| `0x011e07ec` | `DAT_011e07ec` | pointer or array of class | 1 and 8 | 1 |
| `0x011e09ec` | `DAT_011e09ec` | class | 20 and 40 | 1 |
| `0x011e0be0` | `DAT_011e0be0` | pointer or array of class | 1 and 8 | 2 |
| `0x011e0d3c` | `xLastActor@fnv_00953060` | pointer or array of class | 1 and 8 | 1 |
| `0x01202d98` | `DAT_01202d98` | pointer or array of class | 1 and 8 | 1 |
| `0x01202ddc` | `DAT_01202ddc` | pointer or array of class | 1 and 8 | 1 |
| `0x01202e14` | `DAT_01202e14` | pointer or array of class | 1 and 8 | 1 |
| `0x01203328` | `DAT_01203328` | class | 20 and 40 | 2 |
| `0x01269af0` | `DAT_01269af0` | class | 28 and 56 | 4 |
| `0x0126f0fc` | `DAT_0126f0fc` | c-symbol | 1 and 8 | 1 |
| `0x0126f718` | `DAT_0126f718` and 1 more | pointer or array of class | 1 and 8 | 1 |
| `0x0126f71c` | `DAT_0126f71c` and 1 more | pointer or array of class | 1 and 8 | 1 |
| `0x0126fa10` | `DAT_0126fa10` | pointer or array of class | 1 and 16 | 3 |
| `0x0126fa54` | `DAT_0126fa54` | pointer or array of class | 1 and 8 | 1 |
| `0x0126fac4` | `DAT_0126fac4` | pointer or array of class | 1 and 8 | 1 |
