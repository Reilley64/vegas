# The shared MemoryPool declaration

VEGAS-17 owns the `bscore` units. `MemoryPool` is the original release's pool
of equal blocks. At f0ed64652 six definitions of a class of that name existed
and sixteen stand-in classes carried its member bodies, ten of them with the
32-bit offsets of the fields. This change gives the units that own the
class's members one shared declaration, defines eighteen bodies on it, and
replaces every fixed offset in them by the declared member. The declaration
uses the lock's shared declaration, so on windows-x64 it has the layout of
`include/MemoryPool.h`, the copy `memorymanager.cpp` still uses.

In eleven stand-ins this removes 27 accesses of a field by a fixed offset. 24
of them read or wrote the wrong bytes on windows-x64. The other 3 were right
only because of alignment.

The class is not used by the game as built: see "Not constructed". The repair
makes the bodies agree with the class they receive. It does not make the
legacy pool usable, and it was not executed: see "No test" and "Not covered".

## Not constructed

No code constructs a `MemoryPool`.

- The constructor is the function at `0x00aa66a0`. No object of the
  windows-x64 archive requires its symbol, before or after this change.
- The recipe binds that address in one other unit, `memorymanager.cpp`, under
  the name of `MemoryPool`'s constructor. That is the unit of the original
  caller, `CreateMemoryPool` at `0x00aa3cc0`.
- The native body of `0x00aa3cc0` is `MemoryManager::CreateMemoryPool` in
  `src/fallout/misc/native_memory_pools.cpp`. It builds a
  `fnv::memory::FixedPool`, as `docs/native-engine-heaps.md` describes, and
  never names `MemoryPool`.

So the two pool tables stay zero, and every function that walks them finds
nothing: `FUN_00aa7030`, `FUN_00aa7290`, `FUN_00aa7370` and
`DestroyMemoryPools` in `blk_00aa0000_od.cpp`. The native heap and pool
owners of VEGAS-79 and VEGAS-57 are not touched by this change.

## Where the declaration lives

`include/fnv/memory_pool.h`, by the method of `docs/shared-simple-list.md`:
the fields, and the members that `build/units.json` gives a function row.
The header has no body. The unit that holds a member's row defines it. The
lock is the one in `include/RecursiveSpinLock.h`, which the header includes.

| Address | Member | Recipe size | Owning unit |
| --- | --- | --- | --- |
| `0x00aa66a0` | `MemoryPool(unsigned int, unsigned int, const char*)` | 350 | `bscore/memorypool.cpp` |
| `0x00aa6800` | `~MemoryPool()` | 61 | `bscore/memorypool.cpp` |
| `0x00aa6980` | `RegisterInPools()` | 134 | `bscore/memorypool.cpp` |
| `0x00aa6a10` | `ClearPoolSlots()` | 136 | `bscore/memorypool.cpp` |
| `0x00aa6aa0` | `FUN_00aa6aa0(unsigned int)` | 462 | `bscore/memorypool.cpp` |
| `0x00aa6c70` | `FUN_00aa6c70(void*)` | 138 | `bscore/memorypool.cpp` |
| `0x00aa6d00` | `GetPoolInfo()` | 161 | `bscore/memorypool.cpp` |
| `0x00aa6db0` | `FUN_00aa6db0()` | 72 | `bscore/memorypool.cpp` |
| `0x00aa6e00` | `PushFreeBlock(void*)` | 86 | `bscore/memorypool.cpp` |
| `0x00aa6e60` | `UnlinkNode(MemoryPool__FreePoolBlock*)` | 72 | `bscore/memorypool.cpp` |
| `0x00aa6eb0` | `FUN_00aa6eb0(unsigned int, bool)` | 209 | `bscore/memorypool.cpp` |
| `0x00aa6f90` | `FUN_00aa6f90()` | 157 | `bscore/memorypool.cpp` |
| `0x00aa7260` | `FUN_00aa7260()` | 41 | `bscore/memorypool.cpp` |
| `0x00aa6610` | `CommitPage(unsigned int, char*&)` | 60 | `bscore/console/memorypool_console_h_unit.cpp` |
| `0x00aa65b0` | `FUN_00aa65b0()` | 86 | `staging/blk_00aa0000_od.cpp` |
| `0x00aa6650` | `FreeMemory(unsigned int, void*)` | 39 | `staging/blk_00aa0000_od.cpp` |
| `0x00aa6680` | `FreeAllocation()` | 31 | `staging/blk_00aa0000_od.cpp` |
| `0x00aa7300` | `FUN_00aa7300()` | 106 | `staging/blk_00aa0000_od.cpp` |

`PushFreeBlock` and `CommitPage` carried the class's name before. The other
sixteen rows were respelled, one address per commit: address, size and unit
unchanged, and every `symbols` key of the old name respelled with the row.
A member keeps its identifier; only the class changes. Three names change in
more than the class:

- `0x00aa6db0` was a free function taking the pool as its parameter.
- `0x00aa6e60` took a stand-in for the free block as its parameter. It takes
  `MemoryPool__FreePoolBlock` now, which has the same two pointers.
- `0x00aa66a0` and `0x00aa6800` were the constructor and destructor of
  stand-ins, so the whole name is new. The recipe already had the
  constructor's new name as a key, in `memorymanager.cpp`.

The free block's type is spelled `MemoryPool__FreePoolBlock`, and that
spelling is in the recipe key of `UnlinkNode`. It is a nested name
flattened into one identifier with a reserved double underscore. A real
nested type would mangle as `FreePoolBlock@MemoryPool`. This is recorded
against the naming work of VEGAS-11 and is not changed here.

## The layout the declaration implies

Measured by the compiler in `memorypool.cpp`, `memorypool_console_h_unit.cpp`
and `blk_00aa0000_od.cpp`: 192 bytes, alignment 32, on windows-x64. The
32-bit column was measured from the header alone, compiled for 32-bit
Windows: 128 bytes (`0x80`), alignment 32.

| 32-bit | windows-x64 | Field | Status |
| --- | --- | --- | --- |
| `0x00` | `0x00` | `const char* pDescription` | established |
| `0x04` | `0x08` | `char* m_pPoolBase` | established |
| `0x08` | `0x10` | `MemoryPool__FreePoolBlock* m_pFreeBlockHead` | established |
| `0x0c` | `0x18` | `unsigned char layoutPaddingC[20]` | open |
| `0x20` | `0x40` | `RecursiveSpinLock m_kCriticalSection`: owner, then count 4 bytes on, then 24 bytes of padding | fields established, padding open |
| `0x40` | `0x60` | `unsigned int m_uiAllocationSize` | established |
| `0x44` | `0x64` | `unsigned int m_uiPeakPageCount` | established |
| `0x48` | `0x68` | `unsigned short* m_pPageBlockCounts` | established |
| `0x4c` | `0x70` | `unsigned int m_uiPageCount` | established |
| `0x50` | `0x74` | `unsigned int m_uiPoolSize` | established |
| `0x54` | `0x78` | `unsigned int m_uiFreeBlockCount` | established |
| `0x58` | `0x7c` | `unsigned int m_uiAllocatedPageCount` | established |
| `0x5c` | `0x80` | `unsigned int iFirstReserve` | established, written only |
| `0x60` | `0x84` | `unsigned int iSecondReserve` | established, written only |
| `0x64` | `0x88` | `unsigned char layoutPadding64[28]` | open |

On windows-x64 the compiler adds 20 bytes after `layoutPaddingC` to align
the lock, and 28 at the end.

"Established" means that the declared types and their order give the offset,
and every body that uses the field names it. No body uses a fixed offset any
more. The windows-x64 offsets are those of this build target and nothing
depends on their values.

The two reserve fields were declared by the constructor's own struct, right
after `m_uiAllocatedPageCount`. The header declares them in the first eight
bytes of what was the trailing padding, so no offset and no size changed.

`include/MemoryPool.h` gives the same offsets and the same size, in the
32-bit layout and on windows-x64. It writes the gap before the lock as five `unsigned int` and has
no reserve fields: its trailing padding starts at `0x5c` (32-bit).

### Why the shared lock

In the 32-bit layout there are three gaps: 20 bytes from the three pointers
to the lock, 24 bytes after the lock's two fields, and 28 bytes from the
last field to the size of `0x80`. A lock aligned to 32 bytes produces all
three, and the size, with nothing chosen by hand. A probe of the fields
without any padding array, with a lock of two 4-byte fields aligned to 32
bytes, puts the lock at `0x20` and the next field at `0x40`, and is `0x80`
bytes. That is the evidence for using the lock's shared declaration,
`include/RecursiveSpinLock.h`, which is aligned to 32 bytes as the lock's own
unit, `src/bscore/bsspinlock.h`, declares it.

The series first carried `memorypool.cpp`'s copy of the lock, aligned to 4
bytes. That copy gives the same 32-bit offsets, but on windows-x64 put the
lock at `0x2c` and made the class 152 bytes. A shared header must not carry
a second definition of a real class with another layout, so the last code
commit includes the shared lock instead. The 32-bit offsets and size did not
change. The padding arrays stay as they were. They change no 32-bit offset,
and on windows-x64 they give the offsets of `include/MemoryPool.h`.

## What the stand-ins read

Each stand-in was a struct of its own, written with the 32-bit offsets. The
compiler laid it out for 64 bits, and its member was called with a
`MemoryPool`. The table gives what the body then touched. Offsets are those
of windows-x64, in the 152-byte layout of the commits that repaired each
stand-in, before the lock commit. The layout table above gives the members'
offsets now.

| Address | Stand-in | Offset the body used | What is there in `MemoryPool` | Member it uses since, at its offset then |
| --- | --- | --- | --- | --- |
| `0x00aa6db0` | `DummyClass_00aa6db0` | `0x48` page counts | the lock's padding | `m_pPageBlockCounts`, `0x58` |
| | | `0x50` page count | `m_uiPeakPageCount` | `m_uiPageCount`, `0x60` |
| `0x00aa6e60` | `FUN_00aa6e60_shell` | `0x54` free block count | padding | `m_uiFreeBlockCount`, `0x68` |
| `0x00aa7260` | `FUN_00aa7260_holder` | `0x58` count, 4 bytes | lower half of `m_pPageBlockCounts` | `m_uiFreeBlockCount`, `0x68` |
| | | `0x08` list head, read and written | `m_pPoolBase` | `m_pFreeBlockHead`, `0x10` |
| `0x00aa6980`, `0x00aa6a10` | `FUN_00aa6980_stub`, `FUN_00aa6a10_shell` | `0x40` block size | the lock's padding | `m_uiAllocationSize`, `0x4c` |
| | | `0x50` pool size | `m_uiPeakPageCount` | `m_uiPoolSize`, `0x64` |
| | | `0x04` base as a 32-bit integer, its top byte at `0x07` | upper half of `pDescription` | `m_pPoolBase`, `0x08`, as a pointer |
| `0x00aa6800` | `FUN_00aa6800` | `0x50` block to release | `m_uiPeakPageCount` and padding | `m_pPageBlockCounts`, `0x58` |
| `0x00aa6d00` | `FUN_00aa6d00_holder` | `0x00`, `0x40`, `0x44`, `0x4c`, `0x50`, `0x54`, `0x58`, 4 bytes each | lower half of `pDescription`, the lock's padding twice, `m_uiAllocationSize`, `m_uiPeakPageCount`, padding, lower half of `m_pPageBlockCounts` | `pDescription`, `m_uiAllocationSize`, `m_uiPeakPageCount`, `m_uiPageCount`, `m_uiPoolSize`, `m_uiFreeBlockCount`, `m_uiAllocatedPageCount` |
| `0x00aa65b0` | `VirtualReservationSearch` | `0x58` size to reserve | lower half of `m_pPageBlockCounts`, null at that point | `m_uiPoolSize`, `0x64` |
| `0x00aa7300` | `FUN_00aa7300_cls` | `0x24` lock, `0x28` its count | `layoutPaddingC` | `m_kCriticalSection`, `0x2c` and `0x30` |
| `0x00aa7290` | the staging unit's `MemoryPool` of 40 bytes | `0x20` lock, `0x24` its count | `layoutPaddingC` | `m_kCriticalSection`, `0x2c` and `0x30` |

In the 192-byte layout each of the wrong offsets from `0x20` to `0x58` lies
in `layoutPaddingC`, in the 20 bytes before the lock, or in the lock: owner
at `0x40`, count at `0x44`, padding from `0x48`. The wrong offsets below
`0x20` fall in the same pointer fields in both layouts. So each of them is
wrong there too.

Three stand-ins were right by alignment only: `FUN_00aa6800` and
`VirtualReservationSearch` read the pool base at `0x08`, and
`FUN_00aa6680_class` read it there too. `FUN_00aa7300_cls` also declared the
free list at `0x08` and the block size at `0x44`; the compiler removes the
loop that reads them, which has no effect.

Four stand-ins derived from `MemoryPool` and used its members:
`FUN_00aa6aa0_shell`, `FUN_00aa6c70_shell`, `FUN_00aa6eb0_shell` and
`FUN_00aa6f90_shell`. The constructor's struct repeated the fields in the
same order. `FUN_00aa6650_Class` reads no field.

Together the defects meant that a pool could not have worked on this build
target: the reservation asked for zero bytes, so the constructor left the
pool empty; the free list was sorted from the pool base and the result
stored over the pool base; and the destructor released the peak page count
as a pointer.

## Functions whose code changed

Per commit, the object of each changed unit was compared with its parent's.
The offsets in the table below are those of the 152-byte layout that each
commit was measured in. The lock commit, after it, moves them. Seven of the
eighteen commits change no instruction: the declaration move,
and the six respellings whose stand-in already agreed with the class
(`0x00aa6aa0`, `0x00aa6c70`, `0x00aa6eb0`, `0x00aa6f90`, `0x00aa6680`,
`0x00aa6650`). For those the objects are identical, or equal once the old
name is respelled.

| Address | Functions that change | What changes |
| --- | --- | --- |
| `0x00aa7290` (staging copy) | `FUN_00aa7290` | lock at `0x2c`, count at `0x30`, were `0x20` and `0x24` |
| `0x00aa6db0` | `FUN_00aa6db0`; `FUN_00aa6aa0`, which expands it | loads `0x60` and `0x58`, were `0x50` and `0x48`; the caller loads the block size from `0x4c`, where it reused the upper half of the eight bytes at `0x48` |
| `0x00aa6e60` | `UnlinkNode`; `FUN_00aa6aa0` | decrements `0x68`, was `0x54` |
| `0x00aa7260` | `FUN_00aa7260`; `FUN_00aa6eb0`, `FUN_00aa6f90` | compares `0x68`, was `0x58`; passes and stores `0x10`, was `0x08`; `FUN_00aa6f90` reloads the pool base after the sort |
| `0x00aa66a0` | the constructor | the lock is cleared by two 4-byte stores at `0x2c` and `0x30` after the member initialisers, was one 8-byte store at `0x2c` among them |
| `0x00aa6980` | `RegisterInPools`; the constructor | loads `0x4c`, `0x64` and the 8 bytes at `0x08`, were `0x40`, `0x50` and the byte at `0x07` |
| `0x00aa6800` | the destructor | loads the block to release from `0x58`, was `0x50` |
| `0x00aa6a10` | `ClearPoolSlots`; the destructor | as `RegisterInPools` |
| `0x00aa6d00` | `GetPoolInfo` | every load, and every store into the result |
| `0x00aa65b0` | `FUN_00aa65b0` | loads the size to reserve from `0x64`, was `0x58` |
| `0x00aa7300` | `FUN_00aa7300`; `FUN_00aa7370`, which expands it | lock at `0x2c`, count at `0x30`, were `0x24` and `0x28` |

Five bodies change in more than the type of their receiver:

- `UnlinkNode` (`0x00aa6e60`) takes a `MemoryPool__FreePoolBlock*`; its
  parameter was a stand-in for the free block.
- The constructor (`0x00aa66a0`) clears the lock by two stores, below.
- `RegisterInPools` and `ClearPoolSlots` (`0x00aa6980`, `0x00aa6a10`) shift
  the pool base as a `uintptr_t`, not as a 32-bit integer. The 4 GB bound
  this implies is in "The pool tables and the 256 slots".
- `GetPoolInfo` (`0x00aa6d00`) stores the description as a `const char*`, in
  `PoolInfo::f0`, so the record grows from 40 to 48 bytes, below.

The lock commit changes seventeen functions, and in each only the
displacements of member accesses: the owner from `0x2c` to `0x40`, the count
from `0x30` to `0x44`, and every field after the lock up by `0x14` (for
example the pool size from `0x64` to `0x74`). In `memorypool.cpp` they are
the thirteen members it defines. In `blk_00aa0000_od.cpp` they are
`FUN_00aa65b0`, `FUN_00aa7300`, and `FUN_00aa7290` and `FUN_00aa7370`, which
expand the lock in line. The console unit's object is identical. No
immediate changes: the `0x80` in `GetPoolInfo` stays.

The constructor's lock: its struct gave the lock a constructor of its own.
The shared lock has none and its owner field is volatile, so the body clears
the two fields itself. The order of the stores differs and nothing else.

`PoolInfo`, the record `GetPoolInfo` returns, kept the description in a
32-bit integer. Its first field is a `const char*` now, so the record is 48
bytes, was 40, and its nine counters move up by four. It is declared in
`memorypool.cpp` only and nothing reads it. Its second field adds `0x80`,
the size of the class in the 32-bit layout, to twice the page count. The
constant is kept: it is an addend in a statistic that nothing reads. When
something reads `PoolInfo`, it should become `sizeof(MemoryPool)` plus twice
the page count.

## The pool tables and the 256 slots

`ms_pPoolAddressMap`, 256 pointers at `0x011f63b8`, maps an address to its
pool by `address >> 24`: one slot per 16 MB, which covers addresses below
4 GB only. VEGAS-44 records that assumption. `DAT_011f67b8`, at `0x011f67b8`,
maps a block size to its pool by `size >> 2`.

- Both are defined by the generated data of
  `bscore/console/memorymanager_console.cpp`. Nothing allocates them.
- `ClearMemoryPoolTables` at `0x00aa6840` clears them, and is not part of
  the native startup. `RegisterInPools` and `ClearPoolSlots` write them.
- No object of the archive reads `ms_pPoolAddressMap`. The readers are the
  copies of the manager's free that `blk_00aa0000_od.cpp` and
  `bsmenu/menu.cpp` expand in line, through pool structs of their own and
  under the name `DAT_011f63b8`; the compiler emits none of them.
- The generated `DAT_011f67b8` has 144 entries where the original has 256:
  the entry for a block size of 576 is a separate global, `DAT_011f69f8`.
  `RegisterInPools` would write past the array for the two largest of the 37
  pool sizes, 576 and 596. Generated files are not edited here.

`RegisterInPools` and `ClearPoolSlots` now shift the pool base as a
pointer-sized integer. An address at or above 4 GB would index past the 256
slots, where before its upper bits were dropped. `FUN_00aa65b0` asks for the
addresses `1 << 24` to `255 << 24` in turn, as recorded, so a pool it
reserved lies below 4 GB. The native pools do not use the map.

## Storage

- The pool object: no allocation site exists. `DestroyMemoryPools` at
  `0x00aa68a0` runs the destructor and releases the object to the memory
  manager through `FUN_00aa4060`.
- The page counts: the constructor allocates `m_pPageBlockCounts` with the
  array form of global `new`, two bytes per page. The destructor releases
  them through `FUN_00aa4060`. Whether those two are one allocation domain
  depends on which global `new` the program links, and is open.
- The pages: `FUN_00aa65b0` reserves `m_uiPoolSize` bytes, `CommitPage`
  commits one page, `FreeMemory` decommits one and `FreeAllocation` releases
  the range. All four are Windows calls.

## Units that did not move

| Unit | Its copy | Why it stays |
| --- | --- | --- |
| `bscore/memorymanager.cpp` | `include/MemoryPool.h`: lock aligned to 32 bytes, 192 bytes, alignment 32 | The unit derives `PoolView` from it and deletes pools through `PoolView`, whose destructor nothing defines. It requires no member of `MemoryPool`. It requires two names that involve the class: the table `?DAT_011f67b8@@3PAPEAVMemoryPool@@A` and `PoolView`'s destructor `??1PoolView@@QEAA@XZ`. Since the lock commit its copy has the shared header's layout, so it can move next. |
| `bsmenu/menu.cpp` | `fnv_00a1cb80::MemoryPool`, 84 bytes of 32-bit fields, with `Free(void*)` | A copy of the manager's free, expanded in line, that keeps addresses in 32-bit integers. |
| `staging/blk_00aa0000_od.cpp` | `MatrixPool`, `DeallocPool`, `PoolStandIn` | Further in-line copies of the manager's allocate and free. The unit's own `MemoryPool` of 40 bytes is gone. |

Every object that requires a member of `MemoryPool` is built on the shared
header: `memorypool.cpp` and `blk_00aa0000_od.cpp`.

Left on stand-ins, with no field access:

- Two members: `RegisterInPool` at `0x00aa6920` and `ClearPoolSlot` at
  `0x00aa6950`, on empty classes in the staging unit. They touch no field
  and nothing calls them.
- `NodeSorter::SortList` at `0x00aa70c0`, called with the pool as receiver.
  It uses no field of its receiver.
- The lock's acquire at `0x0040fbf0`, on a stand-in derived from the lock in
  `fallout_shared/extradatalist.cpp`.
- The manager's release at `0x00aa4060`, which is the native owner's entry.

## No test

A test of the pool through its own functions needs the constructor. From
`memorypool.cpp`, the console unit and the unit of the tables, seven names
are missing: four functions whose rows are in `blk_00aa0000_od.cpp`
(`FUN_00aa65b0`, `FreeMemory`, `FreeAllocation`, `SortList`), the lock's
acquire in `extradatalist.cpp`, and the manager and its release.

- The staging unit cannot be linked into a program: with these objects it
  still needs 417 names, and a link that takes what it needs from the game
  archive leaves 34,905 undefined. These counts were measured at f0ed64652,
  before the lock commit.
- Supplying the missing functions from the test would test the test.

Moving a function row to the unit that holds its body has accepted
precedent (1504ae0ae, 12dd7a908, fa7abb6f1). It is a separate kind of
commit from a respelling, and this series does not make it. Even with the
four staging rows moved, a host test is not possible: three of the four,
and `CommitPage`, call `VirtualAlloc` or `VirtualFree`, which need Windows.

So no test was added and no body was executed. The repairs of the wrong
offsets are accepted without a test for that reason, and because nothing
constructs the class. What stands in for a test is per function: the
instructions before and after, in the tables above.

## Not covered

- **Execution.** Nothing here was run, on Windows or elsewhere.
- **The padding.** Three arrays in the class and the lock's own padding.
- **The lock.** The receiver of its acquire.
- **`memorymanager.cpp` and `menu.cpp`.** The first keeps its own
  definition, with the shared header's layout since the lock commit; the
  second keeps a differing copy.
- **Lifetimes.** Who would allocate a pool object, and the allocation
  domain of the page counts.
- **The 32-bit address assumption** of the map, and the 144 entries of the
  generated size table. Both belong to VEGAS-44 and to the generated data.
- **`0x80` in `GetPoolInfo`** and the layout of `PoolInfo` for a reader.
- **Leftovers in `memorypool.cpp`:** an empty `struct MemoryManager` and a
  forward declaration `struct MemoryPool;` that were there before.
