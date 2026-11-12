# Numeric constants spelled as data addresses

VEGAS-93. Some units used the address of a data name where the original
code has an integer: `formID & (std::uintptr_t)&::DAT_00ffffff` for the mask
`0x00ffffff`. The recipe, `build/units.json`, binds such a name to the
address that equals the constant, so in the 32-bit original release the
immediate and the address are the same number. In the windows-x64 build the
expression is the address of a variable, and the mask, flag or count is
wrong at run time. This page records how such uses were found, which were
repaired, and which stay open.

## How the uses were found

Two scans ran at `cffde2737`. Their scripts are kept with the review
evidence, outside the repository.

The source scan ran `clang-query` over the 2,229 windows-x64 compile
commands of the game archive. Every unit parsed without an error. It lists
every conversion of a pointer to an integer whose operand is the address of a
variable of static storage: `&X`, an array `X`, or an expression that names
such a variable and neither loads a value nor calls a function, such as
`&X.m`, `&X[2]` or `&*(T *)&X`. It marks a conversion that is an operand of
an integer `&`, `|`, `^`, shift, comparison, `*`, `/`, `%`, `+` or `-` whose
operands are both integers, or of `~`, `!` or unary minus. A place in a
header counts once. It found 484 conversions of the addresses of 342 names
in 200 files. 28 of them are operands of an integer operator.

The recipe scan lists every name of the units' `symbols` maps that is not a
function row and whose address is unlikely to be a datum:

- below `0x00400000`, the address at which the original release is loaded;
- a variable name in the code, below the first import slot `0x00fdf000`, at
  an address that is no function row's;
- above `0x012722c0`, where the recipe's run of data addresses ends: the
  next address it binds is 1.8 MiB further on;
- a 4-byte scalar at an address that is not a multiple of 4.

Every use of those names in `src` and `include` was then read.

Between the last import slot, `0x00fdf49c`, and `0x0101143c` the recipe
binds five addresses and nothing else: `0x00ff0000`, `0x00ffdead`,
`0x00ffffff`, `0x01000000` and `0x01000001`. Three of them are not
multiples of 4.

## Evidence

| Class | Meaning |
| --- | --- |
| operator | The address is an operand of an integer operator whose other operand is a value, such as a form ID or a pixel mask. |
| consumer | The address is passed where the receiving code uses an integer: the callee ANDs or ORs the argument, and other callers pass literals. |
| literal | The same function or unit spells the neighbouring case with a literal, such as the green mask `0xff00`. |
| region | The recipe address is one of the five addresses above. |
| below base | The recipe address is below `0x00400000`, where the original release is loaded, so it is in no datum of it. |
| comment | The source states the original instruction. |

## Repaired

Each function now uses the integer. In the windows-x64 object of each
changed function the relocation to the name is gone, and the constant is an
immediate operand or is folded into a narrower operation, such as a test of
one byte. The other differences are register choice, block order, padding
and, in `ConvertRgbToRgba`, one saved register fewer, which drops that
function's unwind record. The functions marked "inlined" contain an inlined
copy of the repaired function and change the same way.

| Unit | Function | Name | Constant | Evidence |
| --- | --- | --- | --- | --- |
| `fallout_shared/tesfile.cpp` | `FUN_00471400` (`0x00471400`), `ReadFormHeader` (`0x00472bc0`) | `DAT_00ffffff` | `0x00ffffff` | operator, region; the six other units the recipe binds the name in spell the literal |
| `fallout_shared/tes.cpp` | `FUN_00452370` (`0x00452370`); inlined in `FUN_00451ef0` (`0x00451ef0`) | `DAT_01000000` | `0x01000000` | operator, region |
| `fallout/audio/impactmixer.cpp` | `FUN_00838750` (`0x00838750`); inlined in `FUN_00838780` (`0x00838780`) and `PlayFootstepSound` (`0x00837cc0`) | `DAT_01000000` | `0x01000000` | consumer, region |
| `fallout/interface/menus/startmenu.cpp` | `FUN_007d69f0` (`0x007d69f0`) | `DAT_01000000` | `0x01000000` | consumer, region |
| `gamebryo2.2/corelibs/nimain/nidevimageconverter.cpp` | `Convert4BitPalettedTo24Bit` (`0x00a78f70`), `FUN_00a7a160` (`0x00a7a160`), `FUN_00a7a1f0` (`0x00a7a1f0`) | `DAT_00ff0000` | `0x00ff0000` | operator, literal, region |
| `staging/blk_00a20000_od.cpp` | `FUN_00a24f60` (`0x00a24f60`); inlined in `LoadControlsFromIni` (`0x00a22ef0`) | `DAT_00ff0000` | `0x00ff0000` | operator, literal, region |
| `staging/blk_00a60000_o2.cpp` | `FUN_00a77110` (`0x00a77110`), `ConvertRgbToRgba` (`0x00a77460`) | `DAT_00ff0000` | `0x00ff0000` | operator, literal, region |
| `havok/.../collide/hkptoicountviewer.cpp` | `FUN_00d67c30` (`0x00d67c30`) | `DAT_01000001` | `0x01000001` | consumer, region |
| `gamebryo2.2/corelibs/nicollision/niunionbv.cpp` | `FUN_00e9ecc0` (`0x00e9ecc0`) | `g_fnv_00e9ecc0_value_anchor`, plus 4 | `4` | operator, below base, comment |

For `DAT_01000000`, four other units the recipe binds the name in spell the
literal `0x01000000`: `memorypool.cpp`, `tescreature.cpp`,
`blk_00920000_od.cpp` and `blk_00ae0000_od.cpp`.

The callee of `impactmixer.cpp`, `bhkCharacterListener::FUN_00621270`,
returns its argument ANDed with a flags field; other callers pass `0x400`,
`0x20000` or `0x2000000`. The callee of `startmenu.cpp`, `FUN_0075f6f0`,
sets or clears its argument in a flags field; another caller passes
`0x20000000`. `FUN_00d67c30` keeps two counters in one map value, the high
byte and the low 24 bits; `0x01000001` sets both to one, and other callers of
the same map insert pass `1`.

### Left in place

The repairs leave these definitions and bindings without a referrer. None is
removed here: generated files may not be edited, and the recipe changes only
under the rulings.

- `DAT_00ffffff` is defined by hand in `staging/blk_00840000_od.cpp`.
- `DAT_01000000` is defined by the generated data of `bscore/memorypool.cpp`.
  The recipe of `fallout_shared/tesactorbasedata.cpp` also binds the string
  names `$SG5186`, `$SG5187` and `$SG5189` to `0x01000000`; that unit's
  source uses none of them.
- `DAT_00ff0000` is defined by the generated data of
  `nidevimageconverter.cpp`.
- `DAT_01000001` is defined by the generated data of `hkptoicountviewer.cpp`.
  The unit keeps its `extern "C"` declaration of the name, which gives that
  definition its C name.
- Every recipe binding of these names stays.

## Not repaired

| Name and recipe address | Uses | Why it stays open |
| --- | --- | --- |
| `g_011c5bbc_arg1`, `0x00500000` | `blk_00860000_od.cpp`, `FUN_00878360` (`0x00878360`): an unsigned difference is compared with its address. | Both uses are the number 0x500000 (5 MiB): `global_object_initializers2.cpp` passes it as the default of the unsigned setting `uGeometryMemory:BudgetCaps`, and `0x00500000` is the entry of a function row, `BGSTerminal::Load`, so it is not storage. Left for a follow-up repair (coordinator, 2026-11-12); the generated initializer stays under its own ruling. |
| `DAT_01400000`, `0x01400000` | `niconsolerenderer.cpp` and `niunsharedgeometrygroup.cpp` store its address in integer fields; `nistaticgeometrygroup.cpp`, `nidynamicgeometrygroup.cpp` and `blk_00860000_od.cpp` (`FUN_00878030`) in pointer fields. | The repository cannot show that the address lies outside the original release as loaded, and the fields that receive it disagree in type. No unit defines the name. |
| `FUN_00a00000`, `0x00a00000` | `blk_00860000_od.cpp`, `FUN_00878030`: stored in a pointer field beside the sizes `0xf00000` and `0x200000`. | Its uses are the number 0xa00000 (10 MiB budgets): `global_object_initializers2.cpp` passes it as the default of three INI settings. Left open because the fields it is stored in are typed as pointers; deciding their type is a separate step. |
| `g_target_00cc74d0`, `0x00000014` | `blk_00cc0000_o2.cpp`, `FUN_00cc74d0`: returns its address as `void *`. | Below base, but the value is returned as a pointer, not used as an integer here, and the recipe gives the function a pointer result. No unit defines the name. |
| `g_target_00d53c90`, `0x00000065` | `hkpballsocketchaindata.cpp`, `FUN_00d53c90`: the same. | The same. |
| `DAT_00ffdead`, `0x00ffdead` | `tallgrassshader.cpp`: a destructor stores its address in a pointer field. | Region, but the value is stored as a pointer, not used as an integer. |
| `g_011d36b4_arg1` and five more, `0x00416a81` to `0x007e7e7e` | `global_object_initializers.cpp` passes them as values of INI settings. | Generated data, which may not be edited. |

`__tls_array` (`0x0000002c`, 90 units) and the function name
`??1GlobalObjectO2_00d107b0@@QAE@XZ` (`0x0200c612`) are not data names and
were not examined.

## Uses that are addresses

The other 14 operator uses compare or subtract real addresses and are not
changed: the end of a table or array as a loop bound or search limit
(`str_010c7d44`, `DAT_010c7948`, `g_01202328`, `DAT_011f91d8`,
`DAT_011fec30`, `DAT_011fec34` twice, `DAT_011fec8c` twice,
`g_aiPassIndex_fd20`), and identity comparisons with a returned pointer
(`g_012030b0`, `g_01203340`, `g_0126cae8` twice).

The other 17 names of scalars or pointers at addresses that are not
multiples of 4 are indexed as arrays or read as strings, except
`DAT_010a47b3`, whose address `blk_00b00000_od.cpp` returns as a pointer.
None is used as an integer. `UNK_00fdd3b0` and
`FUN_00fde2a0`, variable names in the code, are passed to `atexit`, so they
are code addresses.

## The check

`objects.mask_constants` runs `tools/function-relocations` with
`mask-constants.tsv`. It forbids a relocation to any of the five names in
each of the 17 changed functions, and fails at `cffde2737`. CTest registers
it in the windows-x64 cross build only, like the other relocation checks.

No host test links any of these functions, so no behavioural test was added.
Windows execution was not available.

What the check does not see:

- The same address under another name, or another mangled spelling of the
  same name.
- A wrong constant. It checks that the relocation is gone, not the value of
  the immediate; the instruction-level differences were read by hand.
- Functions that are not in the table.
