# The result of MakeNavMeshPointer

VEGAS-96. `MakeNavMeshPointer` (`0x00464fc0`, function row in
`src/fallout_shared/pathfinding/navmesh_util.cpp`) wraps a `NavMesh*` in a
`NiPointer<NavMesh>` and returns it by value. One caller saw that class
differently from the callee and misread the result. This change repairs
that caller. The callee is unchanged.

## How windows-x64 returns the class

In the callee's unit `NiPointer<NavMesh>` is 8 bytes, with a constructor
from `NavMesh*`, a copy constructor and a destructor. A class with a
destructor or copy constructor of its own is returned through a hidden
result address: the caller passes the address of an 8-byte temporary in
`rcx` and the first argument in `rdx`, and destroys the temporary after
use. The callee constructs the result at `rcx`:

```text
movq  %rcx, %rsi
callq NiPointer<NavMesh>::NiPointer(NavMesh*)   ; this = rcx, mesh = rdx
movq  %rsi, %rax
```

A caller that sees a trivially copyable class of 1, 2, 4 or 8 bytes, with
no constructor of its own, as the earlier views here did, expects the
result in `al`, `ax`, `eax` or `rax` instead, and passes the first
argument in `rcx`.

## Every unit that requires the name

These units define or require the name in the windows-x64 objects. No test
object refers to it. Measured with each unit's own command line: the
compiler's traits of the type the call returns, and the call in the unit's
LLVM IR.

| Unit | Result type at the call | Size | Trivially copyable | Trivial destructor | Call | Before |
| --- | --- | --- | --- | --- | --- | --- |
| `navmesh_util.cpp` (the callee; line 2911 is inlined) | `NiPointer<NavMesh>` | 8 | no | no | defines it with a result address | agrees |
| `tesobjectcell.cpp` | `NiPointer<NavMesh>`, the unit's copy | 8 | no | no | result address | **1 byte, trivial, result in `al`** |
| `tesdatahandler.cpp` | `NiPointer<NavMesh>` | 8 | no | no | result address | agrees |
| `navmesh.cpp` | `NiPointer<NavMesh>`, the unit's copy | 8 | no | no | result address | agrees |
| `navmesharray_h_unit.cpp` (`navmesharray.h`) | `NiPointer<NavMesh>` | 8 | no | no | result address, its own | agrees |
| `navmeshobstacletask.cpp` | `NavMeshPtr`, through a cast of the function pointer | 8 | no | no | result address | agrees |

`navmeshobstacletask.cpp` calls through
`reinterpret_cast<NavMeshPtr(__cdecl*)(NavMesh*)>(&MakeNavMeshPointer)`.
Its own `NiPointer<NavMesh>` (`navmeshobstacletask_decls.h`) is trivially
copyable, so a direct call would expect the result in `rax`. The type the
cast gives the call agrees with the callee. This change leaves that call
as it is; see "Not covered".

## The repair

`FUN_005436e0_shell::FUN_005436e0` (`0x005436e0`, `tesobjectcell.cpp`)
duplicates a cell and wraps each duplicated `NavMesh`:

```cpp
spmesh = *(NavMeshPtr*)&ResultSlot(::MakeNavMeshPointer((::NavMesh *)(pdupMesh)));
```

The unit's copy of the primary template had no field and declared only
`operator=(T*)`, so `NiPointer<NavMesh>` was a 1-byte trivial class there.
Before, at `+0x1ab` in the function:

- `rcx` held the new mesh. The callee took it as the result address and
  wrote the new pointer over the mesh's first 8 bytes, its table pointer.
  `rdx`, which the callee took as the mesh, held what the previous call
  left in it.
- The byte in `al` was dropped. `NavMeshPtr::operator=` was passed
  `rbp-8`, the slot of the `GetNavMeshAt` result that the loop had already
  destroyed, and read 8 bytes from it.
- The result was never destroyed.

The unit's copy now has the field `T* m_pObject` and declares
`NiPointer(const NiPointer<T>&)` and `~NiPointer()`, the members that make
the callee's view of the class non-trivial. Neither has a body; no recipe
row names either in this unit. `operator=(T*)` is unchanged. After:

```text
movq  %r15, %rcx      ; r15 = rbp-8, the 8-byte result
movq  %rax, %rdx      ; the new mesh
callq MakeNavMeshPointer
movq  %r14, %rcx      ; spmesh
movq  %r15, %rdx
callq NavMeshPtr::operator=(const NavMeshPtr&)
movq  %r15, %rcx
callq NiPointer<NavMesh>::~NiPointer()
```

One unwind funclet is added; it destroys the result at `rbp-8` if the
assignment throws. The other four funclets keep their bodies; three are
renumbered. No other function of the object changes. The function grows
from 1,108 to 1,188 bytes with its funclets.

`~NiPointer<NavMesh>()` has one definition in the archive, in
`pathbuilder.cpp.obj`: the body in the class of `include/layout_support.h`,
select-any, 84 bytes. `navmesh.cpp`, `navmesh_util.cpp`,
`tesdatahandler.cpp` and four other units already required it.

The shared header `include/fnv/ni_pointer.h` was tried and not used. With
it `NiPointer<NavMesh>` is 8 bytes but trivially copyable, and the unit
expects the result in `rax` and passes the mesh in `rcx`, as before.

The cast `*(NavMeshPtr*)&ResultSlot(...)` and the assignment into
`spmesh` are older than this change and unchanged. Both classes are 8 bytes
with the pointer at offset 0 in this unit.

## Check

`objects.navmesh_pointer_result` runs `tools/function-relocations` with
`navmesh-pointer-result.tsv`. The function must refer to
`MakeNavMeshPointer` and to `~NiPointer<NavMesh>()`. A trivial view of the
class has no destructor to call, and only a trivial view returns the class
in a register, so the check fails on every form that expects the result in a register.
Run on the objects:

| Object | Result |
| --- | --- |
| before | fails: no relocation to the destructor |
| with the shared header | fails: no relocation to the destructor |
| after | passes |

The check does not see which register carries which argument; the
instructions above record that.

## What changed in the link

Forced link of every archive member, windows-x64, measured on 9b20188c2
and on this change built from the same path:

| | 9b20188c2 | This change |
| --- | --- | --- |
| Undefined names | 35,139 | 35,139 |
| Left / entered | | 0 / 0 |
| Duplicate symbols | 0 | 0 |
| Imports | 137 | the same |
| Members | 2,229, same order | the same |
| Names with differing definitions | 519 | 519 |

One object differs, `tesobjectcell.cpp.obj`, in the function above. It
now requires `~NiPointer<NavMesh>()`, which was defined before. Every
COMDAT definition in the archive has the same members, selection, size and
content as before, except that function's, which has one definition.

## Not covered

- Receivers and lifetimes. The check shows the call shape and the
  destruction of the result, not that the duplicated mesh is a counted
  object or that `NavMeshPtr::operator=` and `~NiPointer<NavMesh>()` act
  on the count the way the original does. Nothing executes this function.
- `navmeshobstacletask.cpp`'s call through a cast of the function pointer.
  It agrees with the callee on size and on how the result is returned, but
  it calls through a type that is not the callee's.
- The symbols of `tesobjectcell.cpp` in `build/units.json` name the callee
  with a `NavMeshPtr` result (`?MakeNavMeshPointer@@YA?AUNavMeshPtr@@PAVNavMesh@@@Z`)
  and do not list the name the object requires. That entry is older than
  this change and unchanged.
- `NiPointer<NiNode>::operator=`: `tesobjectcell.cpp` now declares that
  instance as 8 bytes with the field at offset 0, but the name is not
  emitted here (`docs/shared-ni-pointer.md`).
- Windows execution: not run.
