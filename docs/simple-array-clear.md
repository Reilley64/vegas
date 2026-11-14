# Simple array clear binding

VEGAS-67 removes the global `GlobalObject_00869f00::Clear(bool)`. It was a
placeholder name with four different definitions and no type of its own. Its
two callers now call the clear the rest of the array family already uses,
`fnv_008454f0::FUN_008454f0::Clear` (008454f0), which has one definition in
`src/unmapped/bssimplearray.cpp`.

This is the binding only. It is not the complete repair of either array; see
"Not covered".

## The clear

008454f0 is the clear of a simple array whose elements need no destruction.
The array is a table pointer, a native buffer pointer, a 32-bit count and a
32-bit capacity. With a null buffer it does nothing. Otherwise it runs the
element entry 0072ba80 over the live count, and when asked to free storage it
calls 006a8500, which passes the buffer to the array's own table entry 2 and
clears the pointer, and then zeroes the capacity. It zeroes the count either
way. The storage therefore always returns through the allocator the array was
built with.

## The two callers

At the accepted tip 300f702dc, `build/units.json`, in the unit that defines
both callers (`src/unmapped/bssimplearray.cpp`), bound the retired name
`GlobalObject_00869f00::Clear(bool)` to `0x008454f0`, the address of
`fnv_008454f0::FUN_008454f0::Clear`. The table and sibling-destructor argument
below corroborates this binding. The recipe entry is removed with the name; the
same table already binds the canonical name to that address.

**006cfaa0** is the destructor body of the array whose table is `0x0106c9e0`.
It stores the table and clears with storage release.

- The table's entries are 006cfda0, 00844fc0, 006db090 and 006a28b0. The tables
  `0x0106cc8c` and `0x0106cca0` have the same last three entries.
- The constructors of all three tables, 006d04e0, 006dc370 and 006db9e0, run
  006dc440, which constructs `TwoUIntRecord` elements: two 32-bit words.
- The destructor bodies of the other two tables, 006db930 and 006dba10, call
  008454f0.

The array at `0x0106c9e0` is therefore the same kind of array with the same
element, and 006cfaa0 calls the same clear. `FUN_006cfaa0` is now declared as
that array, so the call needs no cast.

Producer: 006d04e0 in `pathfind.cpp`. No object requires it yet.
Retirers: 006cfaa0, reached only from the deleting entry 006cfda0 in
`blk_006c0000_od.cpp`, which is entry 0 of the table.

**006cf440** is the destructor of the links array that `PathHandler::FindPath`
(006ce8b0) keeps as an automatic variable. FindPath passes it to 006b8c50,
which passes it to 006b8f40 and on to 00996ae0. That function sizes it through
006f2290 and stores one 32-bit value per element. The elements need no
destruction, so its destructor calls the same clear.

Producer: the three-argument constructor called by FindPath. It has no
definition yet.
Retirers: 006cf440, required only by FindPath's unit, and the deleting entry
006cfce0, which no object requires.

## The retired definitions

`blk_00640000_od.cpp`, `blk_00720000_od.cpp`, `blk_007a0000_od.cpp` and
`blk_00900000_od.cpp` each defined the placeholder. Three bodies were empty and
one deleted the object's first word as an array. None was called in its own
unit: 006442e0, 0072ce90, 007ab670 and 00905910 each call 008454f0 directly.
`bssimplearray.cpp` was the only unit that required the name, so a link that
needed it had four candidates. No definition is kept, because none described
either caller.

## Not covered

These were open before this change and remain open.

- The 006cf440 class declares only its virtual destructor. Its table has no
  allocate, free and reallocate entries, it has no allocator member, and its
  constructor and its base destructor have no definition. Until the real class
  exists no object of it can be built, and one built from the present
  declaration could not free its buffer through entry 2.
- 008454f0 calls the element entry under the name
  `fnv_008454f0::FUN_0072ba80_shell::FUN_0072ba80`, which has no definition.
  The `TwoUIntRecord` constructor has none either.
- `bssimplearray.cpp` and the units that supply 0072ba80 and 006a8500 do not
  build for a host test, so no test executes this path. The evidence is the
  rebuilt objects and the complete links.
