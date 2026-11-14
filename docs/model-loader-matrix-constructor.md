# The model-loader matrix value: its constructor, its declaration and its clear

VEGAS-61 asks for one native matrix and name value with genuine construction,
copy and retirement. Three bounded parts of that are in the tree:

1. The global `FUN_00aade20::FUN_00aade20()` has one definition.
2. The class has one declaration, and the two places that give the
   constructor storage give it the size the constructor is compiled for.
3. The constructor clears its float vector with that class's own `clear()`,
   which erases with real iterators. The constructor reaches its end and
   builds the name string. The folded default clear at `0x0044a0a0`, which
   the constructor called before, is unchanged and still ends in a trap for
   every other caller.

Everything else on the ticket is listed under "Not covered".

## The constructor

`FUN_00aade20::FUN_00aade20()` is the function at `0x00aade20`.
`build/units.json` lists it once as a function, 142 bytes, in the unit of
`src/fallout_shared/modelloader.cpp` that holds eight functions. The same
unit's symbol table binds the constructor's exception handler name to
`0x00f1f490`. The class there is a float vector, a column count, a row count
and a name string.

`src/staging/blk_00aa0000_od.cpp` used to define the same name a second time,
inside its own class declaration. That body summed the integers 0 to 67 in a
local array and stored the total in the first word. It had no address tag.
The recipe gives that unit 99 functions; none is at `0x00aade20`. The unit's
symbol table binds the constructor's name to `0x00aade20`, as a name the unit
requires. The body was a placeholder for the callee of `0x00aadde0`, not a
second constructor. It was removed.

The recipe records no call edges. That the function at `0x00aadde0` calls
`0x00aade20` is inferred from the unit's symbol row for the constructor's name
and from the body tagged `0x00aadde0`, which default-constructs the value and
passes it to `0x00aadf50`.

## Names the recipe binds to these addresses

| Address | Unit | Row | Name |
| --- | --- | --- | --- |
| `0x00aade20` | `modelloader.cpp` | function, 142 bytes | `FUN_00aade20::FUN_00aade20()` |
| `0x00aade20` | `blk_00aa0000_od.cpp` | symbol | `FUN_00aade20::FUN_00aade20()` |
| `0x00f1f490` | `modelloader.cpp` | symbol | exception handler of that constructor |
| `0x0044a0a0` | `modelloader.cpp`, the unit of 492 functions | function, 87 bytes | `VecStandIn::FUN_0044a0a0()`, the default clear |
| `0x0044a0a0` | `modelloader.cpp`, the unit of eight functions | symbol | the same name |
| `0x0044a0a0` | `bsfacegenmanager.cpp`, `frondengine.cpp`, `speedtreert.cpp` | symbol | the same name |

There is no other row for `0x00aade20` and no other spelling of the
constructor's name. No object emits the handler name: it belongs to the
original release's 32-bit exception tables.

## Requirers

Measured from the relocations of all 2,223 objects of the windows-x64 archive.

| Object | State | Where |
| --- | --- | --- |
| `modelloader.cpp` | defines | the constructor |
| `blk_00aa0000_od.cpp` | requires, one relocation | `FUN_00aadde0_cls::FUN_00aadde0` (`0x00aadde0`) |
| `blk_00aa0000_od.cpp` | requires, one relocation | `AAOwner::FUN_00aaac10` (`0x00aaac10`), which has `0x00aadde0` inlined |

No other object names the constructor. No object requires `0x00aadde0` by
name. `tile.cpp` requires `AAOwner::FUN_00aaac10`. No generated data names
any of the three functions.

## The declaration

`include/fnv/model_loader_matrix_value.h` declares the class and its parts.
`modelloader.cpp` and `blk_00aa0000_od.cpp` include it. The header has no
body: `modelloader.cpp` defines the members that have one.

It is the declaration `modelloader.cpp` had, moved, with one kind of change.
The float vector, the string, the string's traits and the allocator stood in
that unit's own `namespace std`, as `std::vector<float>`,
`std::basic_string`, `std::char_traits` and `std::allocator`. They are now
`Aade20FloatVector`, `Aade20BasicString`, `Aade20CharTraits` and
`Aade20Allocator`. Two things forced this:

- `blk_00aa0000_od.cpp` includes the C++ library's `<stdexcept>`, which
  defines the library's own `std::basic_string` and `std::allocator`. A
  second definition of those names cannot be included there.
- The unit's private `std::vector<float>` had the mangled name of the
  library's `std::vector<float>`. `bsfacegenmanager.cpp` uses the library's
  vector and its object defines `std::vector<float>::~vector()`. The
  constructor's unwind path requires the float vector's destructor, so every
  link bound it to that body. That body is for another class: 24 bytes, with
  the first-element pointer at `+0x00`, released through the sized
  `operator delete`. The model-loader vector is 40 bytes with that pointer at
  `+0x10`.

Layout on windows-x64, measured in both units with each unit's own command
line. Both give the same record. The status column applies the 2026-11-11
rule for fields of transcribed classes: the order and size come from the
declaration `modelloader.cpp` had, the offset is what the compiler gives
that declaration in both units, and the 32-bit bodies that disagree,
`0x0044a170` and `0x0065f550`, read the first and last pointers at exactly
`+0x0c` and `+0x10`, their offsets in the same declaration at 32-bit widths;
they are recorded as defects under "The default clear". A field is marked
established when, in addition, code of the tree reads or stores it there:
the constructor, `Aade20FloatVector::clear()`, or those two suppliers. The
constructor and the clear are compiled from this same declaration, so they
are not independent evidence; they only show that the field is used as that
member. A field that no code reads or stores is marked open.

| Offset | Bytes | Member | Status |
| --- | --- | --- | --- |
| `+0x00` | 8 | float vector: `auxiliary`, the owner word | established: the clear copies it into each iterator |
| `+0x08` | 4 | float vector: `allocatorAuxiliary` | open |
| `+0x0c` | 4 | float vector: `allocatorElements` | open |
| `+0x10` | 8 | float vector: `first` | established: the clear; `0x0044a170` at 32-bit `+0x0c` |
| `+0x18` | 8 | float vector: `last` | established: the clear; `0x0065f550` at 32-bit `+0x10` |
| `+0x20` | 8 | float vector: `end` | open: nothing reads or stores it |
| `+0x28` | 4 | `columns` | established as a count: the constructor zeroes eight bytes here |
| `+0x2c` | 4 | `rows` | established as a count, as `columns` |
| `+0x30` | 1, then 7 of padding | name string: the allocator | open: empty, nothing reads or stores it |
| `+0x38` | 16 | name string: sixteen characters, or a pointer to longer text | established: the constructor stores the zero character |
| `+0x48` | 4 | name string: `length` | established: the constructor stores 0 |
| `+0x4c` | 4 | name string: `capacity` | established: the constructor stores 15 |

The order of the two counts is open. `AAItem` in `blk_00aa0000_od.cpp`
names the count at `+0x18` of the 32-bit object `rows` and the one at
`+0x1c` `columns`, the other way round from the header. The constructor
zeroes both with one store, so it does not tell them apart.

The class is `0x50` bytes, aligned to 8. The header asserts the sizes of the
iterator (`0x10`), the float vector (`0x28`), the matrix (`0x30`) and the
class (`0x50`).

Three declarations in the header have no definition anywhere in the archive:

- `Aade20FloatVector::Aade20FloatVector()` and
  `Aade20FloatVector::~Aade20FloatVector()`. The constructor calls the first
  and its unwind path the second.
- `FUN_00aade20::~FUN_00aade20()`. `blk_00aa0000_od.cpp` declared it in its
  own copy of the class and calls it for the temporary. The recipe has no row
  under this name. The header keeps the declaration so that the two staging
  functions call what they called before.

Every member that `modelloader.cpp` defines inline is declared `inline` in
the header: the allocator's two constructors and `deallocate`, the string
allocator's constructor, the string's `data`, `setLength`, `_Tidy`,
constructor and destructor, the two iterator constructors, the vector's
`begin`, `finish`, `makeIterator`, `erase` and `clear`, and
`Aade20Matrix()`. The iterator's `operator!=` is defined out of line and is
not. Writing `inline` in the header changes no byte of either object.

The class has no user-declared copy constructor. The staging unit's copy
declared `FUN_00aade20(const FUN_00aade20&)` and defined it nowhere; the
header does not, so the copy constructor is the implicit one, a shallow copy
of the members. No object of the archive requires or defines a copy
constructor of `FUN_00aade20`. A copy of the value would need the real one,
which deep-copies the vector and the string; that is part of the copy that
VEGAS-61 leaves open.

`build/units.json`: one symbols key of the unit of eight functions is
respelled, at the same address, because it named the string by its old name.
`_Tidy` of `std::basic_string<char, ...>` at `0x0044a730` is now `_Tidy` of
`Aade20BasicString<char, Aade20CharTraits<char>, Aade20Allocator<char>>`.
No function row, address, flag or order changes.

## Storage the callers give the constructor

Measured on windows-x64, from the objects.

| Site | Unit | Type of the storage | Bytes before | Bytes now |
| --- | --- | --- | --- | --- |
| The temporary in `0x00aadde0` | `blk_00aa0000_od.cpp` | `FUN_00aade20` | `0x3c` | `0x50` |
| The temporary in `0x00aaac10`, which has `0x00aadde0` inlined | `blk_00aa0000_od.cpp` | `FUN_00aade20` | `0x3c` | `0x50` |

These are the only two places that call the constructor. Before, the staging
unit declared the class as fifteen 32-bit words, the size its own comment
gives for the original release's object. The constructor's class extended 20
bytes past each temporary:

- In `0x00aadde0` the temporary was at `-0x1c` from the frame pointer and
  ended at `+0x20`, where the function's exception state slot begins. It is
  now at `-0x20` and ends at `+0x30`, where the slot is. The frame grows from
  `0xa8` to `0xb8` bytes.
- In `0x00aaac10` the temporary was at `-0x4c` and ended at `-0x10`, where the
  copy temporary began. It is now at `-0x10` and ends at `+0x40`; the copy
  temporary is at `-0x4c`.

In both functions the instructions count and the sequence of relocation
targets are the same as before. `0x00aadde0` keeps its 135 bytes with its
unwind code; `0x00aaac10` goes from 1,159 to 1,175.

## Which size is right on windows-x64

`0x50` is the size of storage that this constructor needs: it is the size of
the class the constructor is compiled for, and the constructor now stores up
to its last byte (see "What the constructor does").

`0x50` is what the declaration gives when a pointer has its native width and a
count keeps its 32-bit width. Laid out at 32-bit widths the same declaration
is the `0x3c`-byte object of the original release: the float vector's four
pointers add 16 bytes, and the pointer in the string's storage union adds 4
bytes of alignment padding in front of it.

That `0x50` is the final layout of the value is not established. Other
functions in the tree see the same value through their own declarations, and
those do not agree with it or with each other:

| Address | What it is | Unit | Its type for the value | Bytes on windows-x64 |
| --- | --- | --- | --- | --- |
| `0x00aadf50` | resize; takes the value as an argument | `blk_00aa0000_od.cpp` | `FUN_006593e0` | `0x3c` |
| `0x00aae3a0` | insert | `blk_00aa0000_od.cpp` | `Entry`, `OutlinedEntry`, `FinalEntry` | `0x3c` each |
| `0x00aae200` | erase | `blk_00aa0000_od.cpp` | `ElQ` | `0x3c` |
| `0x00aaf6f0` | fill | `blk_00aa0000_od.cpp` | `Element_00aaf6f0` | `0x3c` |
| `0x00aaf750` | copy | `blk_00aa0000_od.cpp` | `fnv_00aaf750::Elem` | `0x40` |
| `0x00aafa80` | uninitialized copy | `blk_00aa0000_od.cpp` | `fnv_00aafa80::FUN_00aaec10` | `0x3c`, aligned to 1 |
| `0x00aaf7e0` | move | `blk_00aa0000_od.cpp` | `ElemMOVE` | 8 |
| `0x00aaac10` | loader; indexes the elements | `blk_00aa0000_od.cpp` | `AAItem` | `0x48` |
| `0x00658c10` | allocation of an array of the value | `blk_00640000_od.cpp` | none: the element count times the literal 60 | `0x3c` an element |
| `0x006593e0` | destructor | `blk_00640000_od.cpp` | `FUN_006593e0_Class` | `0x28` |
| `0x00aaec10` | copy constructor | `tesobject.cpp` | `S00aaec10_Obj` | `0x24` |

The float vector alone has four more declarations in `modelloader.cpp`:
`Fg_aaed70_Vec`, `0x30` bytes, used by `0x00aaed70` in the same recipe unit
as the constructor; `fnv_00449fd0::FUN_00449fd0`, `0x20` bytes, the class of
the function at `0x00449fd0`; the global `FUN_00449fd0`, `0x18` bytes; and
`_Dummy_0044a170`, `0x10` bytes. `AAItem` names the count at `+0x18` of the
32-bit object `rows` and the one at `+0x1c` `columns`; the header has
`columns` first.

Each of those units stays on its own copy. None of them calls the
constructor, so none gives it storage.

## The default clear

The function at `0x0044a0a0` erases a float vector from its first element to
its last. Two bodies in the tree show that: `Vector64D::FUN_0064db70` in
`blk_00640000_od.cpp` is commented as erase with begin and end and makes the
same two supplier calls, and `speedtreert.cpp` has a class whose member
`FUN_0044a0a0` is `Erase(Begin(), End())`.

Its body, `VecStandIn::FUN_0044a0a0` in `modelloader.cpp`, asks the two
suppliers at `0x0044a170` and `0x0065f550` for the begin and end iterators
and gives each a null pointer as the place for the result. The compiler ends
the function in a trap instruction after the second call, and with it the
constructor at `0x00449610`, which has it inlined. Until this change the
matrix value's constructor ended there too.

Giving the two suppliers a local pair each, as `Vector64D::FUN_0064db70`
does, would not repair it. Measured in the objects:

- `_Dummy_0044a170::FUN_0044a170` (`0x0044a170`) reads the begin pointer as
  32 bits at `+0x0c`. In the matrix value's vector that is the second
  allocator word; the pointer is 8 bytes at `+0x10`.
- `FUN_0065f550_Class::CallWithSelf` (`0x0065f550`) reads the end pointer as
  32 bits at `+0x10`: the low half of the begin pointer.
- Both pass the value to `FUN_0065e000_class::FUN_0065e000`, which requires
  `FUN_0065e000_class::FUN_0065da80(int, int)`. No archive member defines a
  function of that name and signature.
- `ModelLoaderStandIn::FUN_0044a1a0` (`0x0044a1a0`), the erase the body
  calls, takes the first word of each iterator as a pointer to result
  storage.

### The constructor's own clear

The matrix value's default constructor, `Aade20Matrix::Aade20Matrix()`,
used to reach the vector through a cast to `VecStandIn` and call
`FUN_0044a0a0`. It now calls `clear()`: `Aade20FloatVector::clear()`, its
own base class's clear, on its own members. `modelloader.cpp` already
defined that clear beside the class and did not call it. It is
`erase(begin(), finish())`; the begin and end iterators are objects of
`Aade20ConstIterator`, an owner word and an element pointer, 16 bytes, made
on the stack of the clear.

The recipe row of the unit of eight functions records that the original
constructor calls `0x0044a0a0`. The constructor now calls its own class's
clear instead. For this receiver it is the same operation, erase from the
first element to the last, on the members the layout table marks
established. The folded body at `0x0044a0a0` stays as it is until the
vector layouts of the units below share one float vector type.

`VecStandIn::FUN_0044a0a0` and `FUN_00449610::FUN_00449610()` are
byte-identical to the tip in the object. The recipe is unchanged by this
step.

### Who runs the folded clear

Six callers in four units reach `0x0044a0a0`. The relocations of all 2,223
objects of the archive name it in five functions of three other units. The
sixth, `0x00449610` in `modelloader.cpp`, has it inlined: its code makes the
same two supplier calls and ends in the same trap. Offsets are measured on
windows-x64 with each unit's own command line. "First" and "last" are where
the receiver's own declaration keeps the vector's first and last pointers.

| Caller | Unit | Receiver | Bytes | First, last |
| --- | --- | --- | --- | --- |
| `FUN_00449610::FUN_00449610()` (`0x00449610`) | `modelloader.cpp` | `FUN_00449610`: a 24-byte `FUN_00449fd0` base, then `p18` at `+0x18` and `p1c` at `+0x20` | `0x28` | `+0x10` is inside the base's 24 bytes; `+0x18` is `p18` |
| `FUN_00652e00` (`0x00652e00`) | `bsfacegenmanager.cpp` | an element of `MatrixProxy[2][2]`: eight 32-bit words | `0x20` | 32-bit view: `+0x0c`, `+0x10` |
| `FUN_00652af0` (`0x00652af0`) | `bsfacegenmanager.cpp` | an element of `CoordArray[2][2]`: 32 bytes | `0x20` | 32-bit view: `+0x0c`, `+0x10` |
| `C00b1d5d0::FUN_00b1d5d0` (`0x00b1d5d0`) | `frondengine.cpp` | `C00b1d5d0`: three words, then `first`, `last`, `limit` | `0x28` | `+0x10`, `+0x18` |
| `OwnerB087::ClearLists`, inlined in `ListOwnerRefB087::FUN_00b08780` (`0x00b08780`) | `speedtreert.cpp` | the `vectorS<PT*>` member of `OwnerB087` at `+0x160` | `0x30` | `+0x18`, `+0x20` |
| `TreeGeomQ::Release`, inlined twice in `TreeRuntimeQ::FUN_00b087d0` (`0x00b087d0`) | `speedtreert.cpp` | the `TreeFloatVector` member of `TreeGeomQ` at `+0x148` | `0x30` | `+0x18`, `+0x20` |

A clear written for the matrix value's vector reads the owner word at
`+0x00` and the first and last pointers at `+0x10` and `+0x18`, and stores
the new last pointer at `+0x18`. On these receivers:

- The two `speedtreert.cpp` vectors have two empty allocator members, at
  `+0x08` and `+0x10`, in front of their pointers. It would read the second
  allocator's padding at `+0x10` as the first pointer and the real first
  pointer as the last one, and could overwrite the real first pointer.
- The two `bsfacegenmanager.cpp` receivers are 32-bit views. At `+0x10` and
  `+0x18` it would read two 32-bit word pairs as pointers, and a store at
  `+0x18` would overwrite the words at `+0x18` and `+0x1c`, which a 32-bit
  matrix of this layout holds the column and row counts in.
- `C00b1d5d0` keeps its pointers at `+0x10` and `+0x18`; it is compatible.
- `FUN_00449610` has zeroed `p18` just before the call. The clear would read
  the base's padding at `+0x10` as the first pointer and the zero at `+0x18`
  as the last: it would store nothing, or end the process through
  `_invalid_parameter_noinfo`.

So no one body repairs the folded clear for all six. It is left as it is and
keeps failing closed, in the trap, for each of them. The repair for all
receivers is to put them on one float vector type first.

## What the constructor does

In the windows-x64 object, in order:

1. It calls `Aade20FloatVector::Aade20FloatVector()`, which no archive member
   defines.
2. It stores eight zero bytes at `+0x28`: the two counts.
3. It calls `Aade20FloatVector::clear()`. The clear checks that the begin and
   end pointers are in order, calls `_invalid_parameter_noinfo` when they are
   not, compares the two iterators and, when they differ, moves the tail and
   stores the new end pointer. On a vector whose three pointers are null it
   stores nothing.
4. It stores the name string: `capacity` 15 and `length` 0 as eight bytes at
   `+0x48`, and a zero character at `+0x38`.
5. It returns. If step 3 throws, the unwind path calls
   `Aade20FloatVector::~Aade20FloatVector()`.

The highest byte it stores is `+0x4f`, the last byte of the class. The
function's code is 77 bytes; it was 67 and ended in the trap.

## Names the objects define and require

Against the tip, the declaration step changes the undefined names of the
forced link of every member by one leaving and two entering:

- leaves: `std::vector<float>::vector()`, which only this constructor
  required;
- enters: `Aade20FloatVector::Aade20FloatVector()`, the same requirement
  under the new name;
- enters: `Aade20FloatVector::~Aade20FloatVector()`, the constructor's
  unwind path. Under the old name it was bound to the destructor of the
  C++ library's 24-byte vector that `bsfacegenmanager.cpp` defines.

The clear step changes no undefined name. In `modelloader.cpp.obj` one
name enters, the select-any definition of `Aade20FloatVector::clear()`, and
the constructor's local unwind funclet is numbered `dtor$2` instead of
`dtor$3`. The object still requires
`FUN_0065f550_Class::CallWithSelf` and `FUN_0065e000_class::FUN_0065e000`:
the folded clear and `0x00449610` call them, as at the tip.

## No program reaches these functions

- The game executable links with lazy extraction. Its map has no row from
  `modelloader.cpp`, `blk_00aa0000_od.cpp` or `tile.cpp`.
- A program that contains `modelloader.cpp` or `blk_00aa0000_od.cpp` does not
  link without forcing: each requires hundreds of names that no object
  defines. They include the float vector's constructor and destructor, the
  value's destructor and the copy constructor and destructor of
  `FUN_006593e0`.

So nothing executes the constructor, the clear or the two staging functions.
Neither unit compiles for the host. The evidence is the rebuilt windows-x64
objects, the composed archive and the complete links. Windows execution: not
run.

## One body per name

| Name | Definitions in the archive |
| --- | --- |
| `FUN_00aade20::FUN_00aade20()` | one, `modelloader.cpp` |
| `VecStandIn::FUN_0044a0a0()` | one, `modelloader.cpp` |
| `Aade20FloatVector::clear()` | one, `modelloader.cpp`, select-any |
| `Aade20FloatVector::Aade20FloatVector()`, `~Aade20FloatVector()` | none |
| `FUN_00aadde0_cls::FUN_00aadde0` | one, `blk_00aa0000_od.cpp` |
| `AAOwner::FUN_00aaac10` | one, `blk_00aa0000_od.cpp` |

The number of names in the archive whose select-any definitions differ in
content is 525 before and after, with the same names.

## Not covered

These were open before and remain open.

- One native value declaration. The table under "Which size is right on
  windows-x64" lists eleven functions that see the value through twelve other
  types of six sizes. The resize `0x00aadf50` still takes its argument as a
  `0x3c`-byte `FUN_006593e0`, so both staging functions copy the `0x50`-byte
  temporary through a `0x3c`-byte view. That copy constructor has no
  definition.
- The float vector's constructor and destructor. The recipe binds the
  constructor's address `0x00449fd0` in the unit of eight functions under two
  other names, `Fg_aaed70_Vec` and `fnv_00449fd0::FUN_00449fd0`; the second
  has a body in `modelloader.cpp` on a 32-byte declaration. Which declaration
  the vector takes is the work of the single float vector type that
  `docs/float-vector-destructor.md` leaves open.
- The value's destructor. `0x006593e0` in `blk_00640000_od.cpp` is its body by
  the staging unit's symbol row; it is declared on another type, and
  `FUN_00aade20::~FUN_00aade20()` has no definition.
- The folded default clear `0x0044a0a0`. It still gives its suppliers null
  result storage and ends in the trap, for each of its six callers, and so
  does `0x00449610`. The criterion "the default clear passes null result
  storage" stays open on both. The next step is the single float vector type
  of `docs/float-vector-destructor.md`, with the `speedtreert.cpp` and
  `bsfacegenmanager.cpp` receivers on it. Expected, not measured: the
  vector's constructor and destructor get a definition, so two names stop
  being undefined, and a host test of the constructor becomes possible.
  Then the folded clear can be repaired for every receiver at once.
- The three 32-bit suppliers at `0x0044a170`, `0x0065f550` and `0x0044a1a0`,
  which the folded clear and other units still require.
- The resize `0x00aadf50`, its iterator supplier and the loader
  `0x00aaac10`: argument and return widths, partial-read cleanup and retry
  are unchanged and untested.
- Copy, move and assignment of the value, and the cleanup of partly built
  elements on failure.
- Tests. A test that ran the constructor would have to supply the float
  vector's constructor itself.

No archive member is added, removed or reordered.
