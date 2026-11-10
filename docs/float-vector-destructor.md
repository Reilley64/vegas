# Float vector destructor names

VEGAS-74 gives two classes their own names. Until now
`src/speedtree/frondengine.cpp` and `src/speedtree/leafgeometry.cpp` each
declared a different class under the global stand-in name `FUN_00449fd0`, and
each defined its destructor inline. The two destructor bodies differ, and they
shared one symbol, so a link kept whichever object it loaded first for every
caller and reported nothing.

The classes are now `fnv_00b1b000::FUN_00449fd0` (frond) and
`fnv_00b27910::FUN_00449fd0` (leaf). The global name keeps one destructor
definition, the empty placeholder in `src/staging/blk_00b20000_od.cpp`.

This is the naming only. It is not the single vector type the ticket asks for;
see "Not covered".

## The two destructors

| | Frond | Leaf |
| --- | --- | --- |
| Declared in | `frondengine.cpp`, base `FrondFloatStorage` | `leafgeometry.cpp`, base `VectorStorage` |
| Used by | 00b1b000: two automatic vectors. Also the type of two members of `Geometry` and the element type of `FUN_00b31270` | 00b27910: one automatic vector |
| Clear | `FUN_0065f240::Clear` (0065f240) | `FUN_0065f240::Clear` (0065f240) |
| Release of the first word | `FUN_0065d6e0_class::~FUN_0065d6e0_class` (0065d6e0), which calls `FUN_0064df10_helper::deallocate` (0064df10) with a count of 1 and then `Date::~Date()` | `Allocator::~Allocator`, which calls 00401030 |
| windows-x64 body | 117 bytes | 101 bytes |

What separates them:

- The source. The two bases end in different destructors, as the table shows.
- The recipe. The frond unit binds `0x0065d6e0`, a 94-byte function of the
  other `frondengine.cpp` unit, which in turn binds `0x0064df10`. The leaf unit
  binds neither; it binds `0x00401030`.
- The objects. At 714f4a53f both objects defined
  `FUN_00449fd0::~FUN_00449fd0()` as an inline function with different bytes
  and different callees. After this change the same two bodies carry two names.

Inference, not established here: the two classes are probably two views of one
type of the original release. Both units bind the constructor to `0x00449fd0`
and the clear to `0x0065f240`, and 0064df10 as recovered in `tesobject.cpp`
only calls 00401030. Whether one declaration can produce both bodies is the
work of the single type, not of this change.

`build/units.json` has no function and no symbol binding for either
destructor, before or after. That is a statement about the recipe only. It
does not show whether the original release has a separate destructor function.

## The names

The recipe already names a function's own view of a shared address by the
namespace `fnv_<address>`. `0x00449fd0` is bound that way as
`fnv_00449fd0::FUN_00449fd0` and `fnv_00b25e20::ElemQ`. The new names follow
the same form and say nothing about the type beyond the two addresses.

- `fnv_00b1b000::FUN_00449fd0`: the class of 00b1b000,
  `B1FrondBuilder::FUN_00b1b000`. In the frond unit's symbol table the
  constructor row sits with the rows of that function. The unit already binds
  `0x00449fd0` as `FrondFloatList::FrondFloatList` for 00b19ad0.
  `FrondFloatList` is a separate class whose destructor is spelled differently,
  so its name was not reused.
- `fnv_00b27910::FUN_00449fd0`: the class of 00b27910,
  `LeafGeometry::FUN_00b27910`, its only user.

Three recipe rows change name. No address, function, flag or order changes.

| Unit | Address | Old name | New name |
| --- | --- | --- | --- |
| `frondengine.cpp` (114 functions) | `0x00449fd0` | `??0FUN_00449fd0@@QAE@XZ` | `??0FUN_00449fd0@fnv_00b1b000@@QAE@XZ` |
| `frondengine.cpp` (114 functions) | `0x00b319a0` | `?FUN_00b319a0@FUN_00b31270@@QAEAAUFUN_00449fd0@@I@Z` | `?FUN_00b319a0@FUN_00b31270@@QAEAAUFUN_00449fd0@fnv_00b1b000@@I@Z` |
| `leafgeometry.cpp` | `0x00449fd0` | `??0FUN_00449fd0@@QAE@XZ` | `??0FUN_00449fd0@fnv_00b27910@@QAE@XZ` |

No other unit shares either class. `idvspline.cpp`, `modelloader.cpp` and
`blk_00b20000_od.cpp` declare a third shape under the global name, 24 bytes
without pointers, and are not touched. Their recipe rows keep the global name.

## What each requirer binds

Six unwind paths call a destructor by name. The normal paths of 00b1b000 and
00b27910 contain their own destructor body and call nothing by name.

The table gives the object whose definition each link kept. "Forced" is the
link of every archive member. "Worker pool" is the link of
`tests/runtime_havok_worker_pool_test`. Both need `/force` to finish, at
714f4a53f and now.

| Requirer | Forced, before | Forced, after | Worker pool, before | Worker pool, after |
| --- | --- | --- | --- | --- |
| `frondengine.cpp` 00b1b000, two paths | placeholder | frond body | frond body | frond body |
| `leafgeometry.cpp` 00b27910 | placeholder | leaf body | frond body | leaf body |
| `idvspline.cpp` constructor 00b377c0 | placeholder | placeholder | frond body | placeholder |
| `idvspline.cpp` constructor 00b37660 | placeholder | placeholder | frond body | placeholder |
| `modelloader.cpp` constructor 00449610 | placeholder | placeholder | frond body | placeholder |

- The game executable's ordinary link loads none of the five objects, before
  or after. Nothing in it changes.
- Before, the forced link reported two duplicates of the destructor and the
  worker pool link one. The choice between the placeholder and an inline body
  followed load order. The choice between the two inline bodies was never
  reported.
- After, each name has one definition in the archive, and each requirer binds
  the same definition in every link.
- For the three constructors in `idvspline.cpp` and `modelloader.cpp` the
  forced link is unchanged. The worker pool link changes from the frond body to
  the placeholder. Their receivers are the 24-byte shape built by the empty
  placeholder constructor, so the frond body was a release of memory that was
  never set up. These paths run only when a constructor exits by exception.
- `blk_00b20000_od.cpp` declares the destructor for the member at `+0x3c` of
  the type that 00b37590 constructs and has no reference to it.

No program that loads these objects links without `/force`, so there is no
working behaviour to keep or to lose.

## The frond constructor

`frondengine.cpp` declares the constructor of its class and does not define
it. The recipe binds it to `0x00449fd0`, a 101-byte function of the
`modelloader.cpp` unit, recovered there as
`fnv_00449fd0::FUN_00449fd0::FUN_00449fd0()` on a different declaration.

Before, the frond object took the constructor from the empty placeholder in
`blk_00b20000_od.cpp`, because the two shared the global name. The placeholder
initializes nothing and is not the function at `0x00449fd0`. After,
`fnv_00b1b000::FUN_00449fd0::FUN_00449fd0()` has no definition, and the
complete links list it as undefined. The frond class has no real constructor
yet under either name. The leaf class defines its constructor inline.

## Not covered

These were open before this change and remain open.

- One full-width vector type for the frond and leaf classes and for the
  24-byte declarations in `idvspline.cpp`, `modelloader.cpp` and
  `blk_00b20000_od.cpp`, with the 32-bit middle word of `FUN_0065f240` in
  `blk_00640000_od.cpp`.
- The placeholder destructor in `blk_00b20000_od.cpp`. It goes when the three
  external requirers have that type.
- `Date::~Date()`, which the frond destructor body calls. It has no
  definition.
- The placeholders that are sole providers: `FUN_00449fd0::FUN_00449fd0()`,
  `FUN_00b31270::FUN_00b31270()` and `FUN_00b31270::~FUN_00b31270()` in
  `blk_00b20000_od.cpp`. The frond constructor above joins this list as an
  undefined name.
- `FUN_00b31270::FUN_00b319a0` as `frondengine.cpp` declares it. It was
  undefined before and is undefined now under its new return type. The recipe
  binds it to `0x00b319a0`, which the other `frondengine.cpp` unit defines
  under another name.
- Whether the base of the type that 00449610 constructs is this float vector.
  The recipe does not bind its constructor name.
- None of the units named here builds for a host test, and no Windows test
  that needs them links yet. The evidence is the rebuilt objects and the
  complete links.
