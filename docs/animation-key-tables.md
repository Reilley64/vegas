# NiAnimationKey tables (VEGAS-51)

Each NiAnimationKey class registers its functions and its key size once, and
the key data classes look them up by key content and key type. The original
release keeps them in one block of static storage. This document covers the
native owner of that block. It is the first family repaired from
`docs/interior-alias-scan.md`.

## The object in the original release

| Recipe addresses | Holds |
| --- | --- |
| `0x011f3758` to `0x011f377b` | 36 key sizes, one byte each |
| `0x011f3780` to `0x011f3e3f` | twelve tables of 36 function pointers, `0x90` bytes each |

The recipe names 241 addresses inside this block: 21 in the key sizes and 220
in the function tables. The generated data defined every one of the 241 names
as its own variable. That was separate storage on windows-x64:

- A key class registered through one name, such as `DAT_011f3db8`, and a
  reader indexed another, such as `DAT_011f3db0[2]`. The reader saw zero.
- 44 stores went through names declared `int` and wrote 4 bytes of an 8-byte
  slot. Ten of them stored a function address narrowed to 32 bits.
- Two registration helpers computed a byte offset of 4 per slot and stored
  8-byte pointers at it, so neighbouring slots overlapped.
- Readers indexed definitions of one element, such as
  `unsigned char DAT_011f3758[1]`, up to index 35.
- Twelve names that start eight slots into a table were declared with 36
  elements, so each declaration ran 8 slots past the end of its table.

## The owner

`include/NiAnimationKeyTables.h` declares the storage and
`nianimationkey_tables.cpp` defines it:

| Name | Type | Replaces |
| --- | --- | --- |
| `g_functions` | `Function[12][36]` | the twelve function tables |
| `g_keySizes` | `unsigned char[36]` | the key sizes |

Both are zero until a key class registers, as the block is in the original
release. `Index(content, type)` is `content * 6 + type`. A table is named for
the recipe address it starts at, `kAt011f3780` to `kAt011f3db0`. The code shows
what each table is called with, not a name for it, so none is invented.

`Set` stores a function and `Get<Signature>` returns it as the signature the
caller names. A slot holds a plain function pointer, `void (*)()`, because the
units do not agree on one signature per table. They call the same table with
their own spelling of the key class, for example `TimedRotationKey *`,
`PositionKeyInterpolator *` and `void *` for the first parameter of
`kAt011f38a0`. Choosing one of them would be an arbitrary winner.

Two readers of `kAt011f3810` disagree in more than spelling, and are left as
they were: `nianimationkey.cpp` calls it as `void (*)(float, void **, int *)`
and `blk_00a20000_o2.cpp` as `bool (*)(float, int *, int *)`.
`nirotdata.cpp` only holds its `kAt011f3ae0` function in a variable of type
`void (*)(TimedRotationKey *)`. It casts it back and calls it as
`bool (*)(TimedRotationKey *, TimedRotationKey *)`: two arguments and a
`bool` result, as the other readers of that table call it.

## How the extent was established

Nothing about the size is assumed from outside the tree.

- Rows of six: six registration helpers take `(content, type)` and index
  `[content][type]` with a second dimension of six, or compute
  `type + content * 6`.
- 36 slots: the 21 registration functions fill 21 distinct pairs. The largest
  is `(5, 5)`, which is slot 35.
- Twelve tables: the registration functions write twelve table starts, each
  `0x90` bytes after the one before. `0x90` is 36 pointers of the original
  release.
- The end: the next recipe name after the last table is at `0x011f3e40`,
  exactly twelve tables after `0x011f3780`. The recipe names nothing between
  the key sizes and the first table except the four bytes that pad it.

The generated definitions were not used as evidence of the extent. Their
declared sizes ranged from one element to the 36 elements above.

Each registration function fills the same pair in every table it touches. For
example `0x00a273a0` fills `(0, 2)` in all twelve tables and the key sizes.

## Users

All 21 registration functions and every reader index the owner. They are in 21
units: the 19 functions of `nianimationkey_registration.cpp`, one each in
`nifloatkey.cpp` and `nicontrollermanager.cpp`, six helpers and seven readers
in `blk_00a20000_o2.cpp`, and the key data units of `nianimation` and
`niparticle`. No unit declares one of the 241 names.

A reader that holds the content of its key data adds the type to that
content's first slot, as `Index(2, 0) + type`. A reader that indexed a table
from its start keeps its index expression unchanged.

The generated definitions of the 241 names are retired through the audited
composition in `docs/native-data-ownership.md`. The values are not in a
prepared data pack: the block is zero at start and filled by registration.

## Tests and limits

`tests/runtime/animation_key_tables_test.cpp` links the owner. It checks that
the storage starts empty, that a function registered at `Index(content, type)`
is found through a content's first slot plus the type in each of the twelve
tables, that one registration fills exactly one slot, that two signatures are
called through one table, and the same for key sizes.

The test does not run the registration functions or the readers themselves.
On a host they do not link into a test. On windows-x64 a program that
calls the registration function at `0x00a28680` and the reader at
`0x00a3d630` does not link against the game archive. Through
`blk_00a20000_o2.cpp` it pulls in at least 1,395 of the 2,230 members, and
the link reports 34,833 names that no member defines. A test of registration through to the
readers waits for the archive to link.

What stands in for it is measured in the windows-x64 archive by
`archive.animation_key_tables`, `tools/animation-key-tables/README.md`: no
member defines or refers to one of the 241 names, the owner is defined once,
nothing stores 4 or 2 bytes through it, and every indexed access to a function
table steps one 8-byte slot.

Not done here:

- One signature per table. It needs the key classes of the reading units to
  be one set of types first.
- Bounds checks. The original release has none, and a reader's type comes
  from loaded data.
