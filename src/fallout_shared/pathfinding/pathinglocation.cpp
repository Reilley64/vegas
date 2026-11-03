// fallout_shared/pathfinding/pathinglocation.cpp: PathingLocation, PathingLocationProxy, PathingLocationArray, StandInShell and more (34 functions)

#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cbc0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0069ccf0_class.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/FUN_006ed7a0_Class.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/InteriorCellLookup.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00587550__FUN_00587550_shell.h"
#include "fnv/decl/fnv_00696a50__FUN_00696a50_shell.h"
#include "fnv/decl/fnv_00696cf0__Host696.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_0068f000.h"
#include "fnv/symbols_00690000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_006dd000.h"
#include "fnv/symbols_006df000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01025000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_011de000.h"
#include "pathinglocation_decls.h"

// @fnv 0x004ff7e0
bool PathingLocation::HasValidTriangle()
{
    m_ppVirtualMethodTable = (void**)0x0102583c;
    __assume(0);
}

static const int kClearTriangleDataValue1 = 65535;

// @fnv 0x006ddbe0
void PathingLocation::ResetLocation()
{
    m_usTriangleID = kClearTriangleDataValue1;
}

// Copies Location, the Id fields, pCell and uiFlags from other into this PathingLocation and returns *this.
// @fnv 0x006dcce0
PathingLocation& PathingLocation::operator=(const PathingLocation& other)
{
    Location = other.Location;
    m_pLocationNavMesh = other.m_pLocationNavMesh;
    pNavMeshInfoArray = other.pNavMeshInfoArray;
    pCell = other.pCell;
    m_pContainingWorldspace = other.m_pContainingWorldspace;
    m_uiPathingFlags = other.m_uiPathingFlags;
    m_usTriangleID = other.m_usTriangleID;
    uiFlags = other.uiFlags;
    return *this;
}

// @fnv 0x006dd4f0
TESObjectCELL* PathingLocation::GetContainingCell()
{
    if (pCell)
        return pCell;
    else if (m_pContainingWorldspace)
    {
        TESObjectCELL* cell = m_pContainingWorldspace->GetCellByKey(m_uiPathingFlags);
        if (cell)
            return cell;
    }
    return 0;
}

// @fnv 0x006dd610
bool PathingLocation::ResolveNavMesh(NavMeshPtr& navMesh)
{
    if (m_pLocationNavMesh)
        return const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(navMesh);
    else
        return false;
}

// If a NavMeshInfo is set and its triangle index is valid, checks it against navMesh, writes the triangle index to triangle and returns true.
// @fnv 0x006dd640
bool PathingLocation::FindNavMeshTriangle(NavMeshPtr& navMesh, unsigned short& triangle)
{
    if (m_pLocationNavMesh)
    {
        if (m_usTriangleID == 0xFFFF)
            return false;
        if (!const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(navMesh))
            return false;
        triangle = m_usTriangleID;
        return true;
    }
    else
        return false;
}

// @fnv 0x006dd540
const NavMeshInfo* PathingLocationProxy::GetAssociatedNavMesh()
{
    if (m_pLocationNavMesh)
        return m_pLocationNavMesh;
    else if (!pNavMeshInfoArray)
        return 0;
    else if (((bool)(::IsPathingLocationFlagSet((::PathingLocation *)this))))
        return (const NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(0)));
    else
        return 0;
}

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
// Placement-constructs count PathingLocation objects in the items array.
// @fnv 0x006d00a0
void PathingLocationArray::ConstructItems(PathingLocation* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
        new (items + i) PathingLocation;
}

// Reads a PathingLocation from a load-game buffer: location, navmesh id, cell/worldspace, flags and optional mesh data.
// @fnv 0x006df010
void PathingLocation::LoadGame(BGSLoadGameBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&Location), 12);
    unsigned int navMeshID = 0;
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_008648e0((unsigned int *)(void *)(&navMeshID));
    m_pLocationNavMesh = ((::NavMeshInfo *)(((::Pathing *)(reinterpret_cast<::Owner45A *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_0045af00()))->FindReferenceByFormId({})));
    pCell = dynamic_cast<TESObjectCELL*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
    m_pContainingWorldspace = dynamic_cast<TESWorldSpace*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_uiPathingFlags), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_usTriangleID), 2);
    m_usTriangleID = kClearTriangleDataValue1;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&uiFlags), 1);
    bool hasMeshes = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hasMeshes), 1);
    if (hasMeshes)
    {
        if (m_pContainingWorldspace)
            pNavMeshInfoArray = ForwardToPathing(m_pContainingWorldspace, m_uiPathingFlags);
        else if (pCell)
            pNavMeshInfoArray = FUN_006d6f40(pCell);
    }
}

struct FUN_006dcfe0_shell : public PathingLocation
{
    void FUN_006dcfe0(int);
};

// Clears bit 0 of the byte at offset 0x26 and sets it to the low bit of aiVal.
// @fnv 0x006dcfe0
void FUN_006dcfe0_shell::FUN_006dcfe0(int aiVal)
{
    *((unsigned char*)this + 0x26) &= ~1;
    *((unsigned char*)this + 0x26) |= aiVal;
}

// @fnv 0x006dd5a0
int __fastcall IsPathingLocationFlagSet(PathingLocation* pThis)
{
    return *((unsigned char*)pThis + 0x26) & 1;
}

// @fnv 0x006df160
TESForm*& __fastcall GetFirstForm(NiFormArray* pThis)
{
    return pThis->FUN_00877a30(0);
}


struct StandIn6815c0
{
};

struct Point3_12
{
    int a, b, c;
};

struct StandInShell
{
    StandInShell* FUN_006dcc40(void* other);
};

// @fnv 0x006dcc40
StandInShell* StandInShell::FUN_006dcc40(void* other)
{
    *(int*)this = (int)&DAT_0102583c;
    new ((void *)(((StandIn6815c0*)((char*)this + 4)))) ::Vec3();
    *(Point3_12*)((char*)this + 4) = *(Point3_12*)((char*)other + 4);
    *(int*)((char*)this + 0x10) = *(int*)((char*)other + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)((char*)other + 0x14);
    *(int*)((char*)this + 0x18) = *(int*)((char*)other + 0x18);
    *(int*)((char*)this + 0x1c) = *(int*)((char*)other + 0x1c);
    *(int*)((char*)this + 0x20) = *(int*)((char*)other + 0x20);
    *(short*)((char*)this + 0x24) = *(short*)((char*)other + 0x24);
    *(char*)((char*)this + 0x26) = *(char*)((char*)other + 0x26);
    return this;
}

namespace fnv_006dcf20 {
struct PtrLoc
{
    const NiPoint3* p;
};
struct PtrNav
{
    const NavMeshInfo* p;
};
struct FUN_006dcfe0_shell : public PathingLocation
{
};

// Initialises a PathingLocation from a point and navmesh info: sets vtable, location, flags, worldspace/cell and clears triangle data.
// @fnv 0x006dcf20
PathingLocation* __fastcall FUN_006dcf20(PathingLocation* self, PtrLoc aLocation, PtrNav apNavMeshInfo)
{
    self->m_ppVirtualMethodTable = (void**)&::DAT_0102583c;
    new ((void *)(&self->Location)) ::Vec3();
    self->Location = *aLocation.p;
    self->uiFlags = 0;
    self->m_pLocationNavMesh = apNavMeshInfo.p;
    self->pNavMeshInfoArray = 0;
    self->m_pContainingWorldspace = ::FUN_00690800(apNavMeshInfo.p);
    if (self->m_pContainingWorldspace)
    {
        self->pCell = 0;
        self->m_uiPathingFlags = *(unsigned int*)((const char*)apNavMeshInfo.p + 0xc);
    }
    else
    {
        self->pCell = reinterpret_cast<::InteriorCellLookup *>((void *)(apNavMeshInfo.p))->FUN_006b77b0();
        self->m_uiPathingFlags = 0xdeaddead;
    }
    reinterpret_cast<::FUN_006dcfe0_shell *>((((FUN_006dcfe0_shell*)self)))->FUN_006dcfe0(1);
    self->m_usTriangleID = kClearTriangleDataValue1;
    return self;
}
}  // namespace fnv_006dcf20

struct FUN_006dce60_shell : PathingLocation
{
    PathingLocation* FUN_006dce60(NiPoint3 const&, TESObjectCELL*);
};
struct FUN_006dd4d0_shell
{
    char _pad[0x24];
    unsigned short m_0x24;
    void SetField(unsigned short value);
};

// @fnv 0x006dd4d0
void FUN_006dd4d0_shell::SetField(unsigned short value)
{
    m_0x24 = value;
}

struct FUN_006dd5c0_Cls
{
    char _pad[16];
    void* f10;
    BSSimpleArray<unsigned int, 1024>* f14;
    bool FUN_006dd5c0(BSSimpleArray<void*, 1024>* arr);
};
// Appends f10 to arr if set, otherwise copies f14 into arr; returns whether either source was available.
// @fnv 0x006dd5c0
bool FUN_006dd5c0_Cls::FUN_006dd5c0(BSSimpleArray<void*, 1024>* arr)
{
    if (f10)
    {
        reinterpret_cast<::FUN_00438690 *>((arr))->FUN_007cb2e0((unsigned int *)&(f10));
        return true;
    }
    else
    {
        if (f14)
        {
            f14->CopyTo((BSSimpleArray<unsigned int, 1024>*)arr);
            return true;
        }
        else
        {
            return false;
        }
    }
}

class TESObjectREFR;
struct _ref_006815c0_t
{
};
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct SandboxProcedureData
{
};
struct SetupData_t
{
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
};
struct FUN_006dd0d0
{
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const void* m_pLocationNavMesh;
    const void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    FUN_006dd0d0(const NiPoint3* aLocation, PathingLocation* aHintLoc);
};
class TESObjectCELL;
struct NavMeshInfoStandIn : NavMeshInfo
{
    unsigned int GetCellKey();
public:
    ::TESObjectCELL *FUN_006b7770();
};

struct FUN_006dd3e0_shell : PathingLocation
{
    void FUN_006dd3e0(const NavMeshInfo* mesh);
};

// @fnv 0x006dd3e0
void FUN_006dd3e0_shell::FUN_006dd3e0(const NavMeshInfo* mesh)
{
    pNavMeshInfoArray = 0;
    m_pLocationNavMesh = mesh;
    m_pContainingWorldspace = ::FUN_00690800((const ::NavMeshInfo *)(((NavMeshInfoStandIn*)mesh)));
    if (m_pContainingWorldspace)
    {
        pCell = 0;
        m_uiPathingFlags = *(unsigned int*)((char*)mesh + 0xc);
    }
    else
    {
        pCell = reinterpret_cast<::InteriorCellLookup *>((((NavMeshInfoStandIn*)mesh)))->FUN_006b77b0();
        m_uiPathingFlags = 0xdeaddead;
    }
    reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
    m_usTriangleID = 65535;
}

struct WsH
{
};
struct PathingLocationSetup
{
    void SetLocationData(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
};
struct FUN_006dd460 : PathingLocation
{
    void FUN_006dd460_1(const NiPoint3& pos);
};
namespace fnv_006def40 {
class TESObjectREFR;

struct SandboxProcedureData
{
};

struct FUN_00865db0_shell
{
};

struct SaveFormIDHelper : public FUN_00865db0_shell
{
};

struct BGSSaveFormBuffer : public SaveFormIDHelper
{
};

struct FUN_006def40_shell
{
    unsigned char pad0[4];
    unsigned char data[12];
    SandboxProcedureData* m_pLocationNavMesh;
    const void* pNavMeshInfoArray;
    void* pCell;
    void* m_pContainingWorldspace;

    void FUN_006def40(BGSSaveFormBuffer*);
};

// @fnv 0x006def40
void FUN_006def40_shell::FUN_006def40(BGSSaveFormBuffer* buffer)
{
    bool bhadNavMeshesArray;

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(data, 12, 0);
    reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(reinterpret_cast<unsigned int>(m_pLocationNavMesh ? ((::fnv_006def40::TESObjectREFR *)(::FUN_00559450((int *)(m_pLocationNavMesh)))) : 0), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pCell), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pContainingWorldspace), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&data[0x1c], 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&data[0x20], 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&data[0x22], 1, 0);

    bhadNavMeshesArray = pNavMeshInfoArray;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&bhadNavMeshesArray, 1, 0);
}
}  // namespace fnv_006def40

struct PathingCellAccess : TESObjectCELL
{
};
const BSSimpleArray<NavMeshInfo_const*, 1024>* ForwardToPathing(TESWorldSpace*, unsigned int);
const BSSimpleArray<NavMeshInfo_const*, 1024>* FUN_006d6f40(TESObjectCELL*);
struct SetupPathingLocation : PathingLocation
{
    void FUN_006dd280(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
};
// @fnv 0x006dce10
PathingLocation::PathingLocation(const NiPoint3& location, TESObjectREFR* reference)
{
    m_ppVirtualMethodTable = (void**)0x0102583c;
    new ((void *)(reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(&Location))) ::Vec3();
    reinterpret_cast<::SetupPathingLocation *>(this)->FUN_006dd280(location, reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(reference)->GetTarget()),
                    ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((reference))->FUN_00575d70())));
}
// @fnv 0x006dce60
PathingLocation* FUN_006dce60_shell::FUN_006dce60(NiPoint3 const& a, TESObjectCELL* b)
{
    m_ppVirtualMethodTable = (void**)&DAT_0102583c;
    new ((void *)(&Location)) ::Vec3();
    reinterpret_cast<::SetupPathingLocation *>(this)->FUN_006dd280(a, b, 0);
    return this;
}
// Initializes a pathing location from a point, using the hint location's navmesh triangle if found, otherwise setting up from the point and cell/worldspace.
// @fnv 0x006dd0d0
FUN_006dd0d0::FUN_006dd0d0(const NiPoint3* aLocation, PathingLocation* aHintLoc)
{
    m_ppVirtualMethodTable = (void**)&DAT_0102583c;
    new ((void *)(((_ref_006815c0_t*)&Location))) ::Vec3();
    Location = *aLocation;
    uiFlags = 0;
    m_usTriangleID = kClearTriangleDataValue1;
    NavMeshPtr pFoundNavMesh;
    if (aHintLoc->ResolveNavMesh(pFoundNavMesh))
    {
        m_usTriangleID =
            reinterpret_cast<::fnv_00696a50::FUN_00696a50_shell *>((((NavMesh*)((::TESObjectREFR *)(::FUN_00559450((int *)(((SandboxProcedureData*)&pFoundNavMesh))))))))->FUN_00696a50((const ::NiPoint3 *)&(*aLocation), (int)(0));
        if (m_usTriangleID != kClearTriangleDataValue1)
        {
            m_pLocationNavMesh = aHintLoc->m_pLocationNavMesh;
            pNavMeshInfoArray = 0;
            pCell = aHintLoc->pCell;
            m_pContainingWorldspace = aHintLoc->m_pContainingWorldspace;
            m_uiPathingFlags = aHintLoc->m_uiPathingFlags;
            return;
        }
    }
    reinterpret_cast<::SetupPathingLocation *>((((SetupData_t*)this)))->FUN_006dd280((*(const ::NiPoint3 *)((void*)aLocation)), aHintLoc->GetContainingCell(),
                          (TESWorldSpace*)((BGSTerrainManager*)aHintLoc)->GetMinLevel());
}
// @fnv 0x006dd460
void FUN_006dd460::FUN_006dd460_1(const NiPoint3& pos)
{
    Location = pos;
    m_usTriangleID = 65535;
    if (m_pContainingWorldspace)
    {
        int key = ::FUN_00587440((const ::NiPoint3 *)&(Location));
        if (key != m_uiPathingFlags)
            reinterpret_cast<::SetupPathingLocation *>(this)->FUN_006dd280(pos, 0, m_pContainingWorldspace);
    }
}
// Stores the position, resolves the nav-mesh array from the world or cell, marks all meshes reachable when exactly one mesh exists, and sets flags.
// @fnv 0x006dd280
void SetupPathingLocation::FUN_006dd280(const NiPoint3& position, TESObjectCELL* cell, TESWorldSpace* world)
{
    Location = position;
    uiFlags = 0;
    if (world)
    {
        m_pContainingWorldspace = world;
        m_uiPathingFlags = ((unsigned int)(::FUN_00587440((const ::NiPoint3 *)&(Location))));
        pCell = 0;
        pNavMeshInfoArray = ForwardToPathing(m_pContainingWorldspace, m_uiPathingFlags);
    }
    else
    {
        pNavMeshInfoArray = FUN_006d6f40(cell);
        if (cell && !reinterpret_cast<::TESObjectCELL *>((static_cast<PathingCellAccess*>(cell)))->IsCellInterior())
        {
            m_pContainingWorldspace = reinterpret_cast<::TESObjectCELL *>((static_cast<PathingCellAccess*>(cell)))->GetParentWorldSpace();
            m_uiPathingFlags = ((unsigned int)(::PackShortPair(reinterpret_cast<::TESObjectCELL *>((static_cast<PathingCellAccess*>(cell)))->GetCellGridX(),
                                             reinterpret_cast<::TESObjectCELL *>((static_cast<PathingCellAccess*>(cell)))->GetCellGridY())));
            pCell = 0;
        }
        else
        {
            pCell = cell;
            m_pContainingWorldspace = 0;
            m_uiPathingFlags = 0xDEADDEAD;
        }
    }
    if (pNavMeshInfoArray && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((const_cast<BSSimpleArray<NavMeshInfo_const*, 1024>*>(pNavMeshInfoArray)))->GetName())) == 1)
    {
        reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
        m_pLocationNavMesh = reinterpret_cast<const NavMeshInfo*>(
            ((::NavMeshInfo_const *)(reinterpret_cast<::S3e60 *>((const_cast<BSSimpleArray<NavMeshInfo_const*, 1024>*>(pNavMeshInfoArray)))->FUN_006a7ad0(0))));
        pNavMeshInfoArray = 0;
    }
    else
    {
        reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(false);
        m_pLocationNavMesh = 0;
    }
    m_usTriangleID = 0xFFFF;
}

struct NiPointOps : NiPoint3
{
};

struct FUN_006deeb0_cls : PathingLocation
{
    bool IsWithinDistanceOfSameLocation(const PathingLocation* other, float dist);
};

// @fnv 0x006deeb0
bool FUN_006deeb0_cls::IsWithinDistanceOfSameLocation(const PathingLocation* other, float dist)
{
    if (other->m_pContainingWorldspace != m_pContainingWorldspace)
    {
        return false;
    }
    if (m_pContainingWorldspace != 0)
    {
        if (other->m_uiPathingFlags != m_uiPathingFlags)
        {
            return false;
        }
    }
    else
    {
        if (other->pCell != pCell)
        {
            return false;
        }
    }
    if (reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(static_cast<const NiPointOps&>(other->Location)))->FUN_00439ef0((::NiPoint3 *)&(Location), *(const ::NiPoint3 *)nullptr)))))->UpdateCombatStyle() > dist * dist)
    {
        return false;
    }
    return true;
}

struct FUN_006dcf20
{
    void** vtable;
    NiPoint3 location;
    const NavMeshInfo* navMesh;
    const BSSimpleArray<NavMeshInfo_const*, 1024>* navMeshes;
    TESObjectCELL* cell;
    TESWorldSpace* worldSpace;
    unsigned int cellKey;
    unsigned short triangle;
    unsigned char flags;
    unsigned char reserved;
    FUN_006dcf20(const NiPoint3& position, TESObjectREFR* reference);
    ~FUN_006dcf20();
};
struct PathingLocationOwner
{
    void FUN_006ed730(const NiPoint3& position, TESObjectREFR* reference);
};
// Constructs a pathing location from a position and reference, then passes it to the owner's location setter.
// @fnv 0x006ed730
void PathingLocationOwner::FUN_006ed730(const NiPoint3& position, TESObjectREFR* reference)
{
    FUN_006dcf20 location(position, reference);
    reinterpret_cast<::FUN_006ed7a0_Class *>(this)->FUN_006ed7a0((*(const ::PathingLocation *)(&location)));
}

struct FUN_006dcbb0 : public PathingLocation
{
    FUN_006dcbb0();
    ~FUN_006dcbb0();
};

struct FUN_006f4da0
{
    unsigned int flags;
    FUN_006dcbb0 path;
    int context;
    FUN_006f4da0(int, int);
};

// Initialises the path from source, stores contextValue, sets flags to 6 and adds bit 1 when the path check for 0 succeeds.
// @fnv 0x006f4da0
FUN_006f4da0::FUN_006f4da0(int source, int contextValue) : path()
{
    reinterpret_cast<::PathingLocation *>(&(path))->operator=((*(const ::PathingLocation *)(source)));
    context = contextValue;
    flags = 6;
    if (reinterpret_cast<::PathingLocationProxy *>(&(path))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
        flags |= 1;
}

struct MeshPoint
{
    float x;
    float y;
    float z;
};
struct MeshTriangle
{
    unsigned short v0;
    unsigned short v1;
    unsigned short v2;
};
class MeshTriangleArray
{
  public:
                     // GetSize
      // GetAt
};
class MeshVertexArray
{
  public:
                          // IsEmpty
    MeshPoint* FUN_006a1440(unsigned int i);  // GetAt
};

class MeshBounds
{
  public:
    MeshPoint m_kMin;           // +0x00
    MeshPoint m_kMax;           // +0x0c
    MeshTriangleArray m_kTris;  // +0x18
    int unk1c[3];
    MeshVertexArray m_kVerts;  // +0x28

    bool ContainsPoint(const MeshPoint* pkPoint);
};

// @fnv 0x0069bea0
bool MeshBounds::ContainsPoint(const MeshPoint* pkPoint)
{
    if (pkPoint->x >= m_kMin.x && pkPoint->x <= m_kMax.x && pkPoint->y >= m_kMin.y && pkPoint->y <= m_kMax.y &&
        m_kMin.z - 180.0 <= pkPoint->z && m_kMax.z + 180.0 >= pkPoint->z)
    {
        if (!reinterpret_cast<::FUN_0076b610_Class *>(&(m_kVerts))->FUN_0076b610())
        {
            float m_fGlyphExtent = m_kMax.z - m_kMin.z;
            float fOut;
            for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kTris))->GetName())); i++)
            {
                MeshPoint kA = *m_kVerts.FUN_006a1440(((::MeshTriangle *)(reinterpret_cast<::FUN_0069ccf0_class *>(&(m_kTris))->FUN_0069ccf0(i)))->v0);
                MeshPoint kB = *m_kVerts.FUN_006a1440(((::MeshTriangle *)(reinterpret_cast<::FUN_0069ccf0_class *>(&(m_kTris))->FUN_0069ccf0(i)))->v1);
                MeshPoint kC = *m_kVerts.FUN_006a1440(((::MeshTriangle *)(reinterpret_cast<::FUN_0069ccf0_class *>(&(m_kTris))->FUN_0069ccf0(i)))->v2);
                if (::FUN_006b9cf0((*(const ::NiPoint3 *)(&kA)), (*(const ::NiPoint3 *)(&kB)), (*(const ::NiPoint3 *)(&kC)), (*(const ::NiPoint3 *)(pkPoint)), (*(float *)(&fOut)), m_fGlyphExtent, m_fGlyphExtent))
                    return true;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

extern const char DAT_0106cdec[];
extern const char DAT_0106cdd8[];
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
struct DebugForm
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* editorName();
};
struct DebugWorld : DebugForm
{
};
struct DebugMesh
{
};
struct DebugMeshes
{
};
struct DebugLocation
{
    void* unk00;
    NiPoint3 location;
    DebugMesh* mesh;
    DebugMeshes* meshes;
    DebugForm* cell;
    DebugWorld* world;
    int cellKey;
    unsigned short triangle;
    void FormatDebugString(char*, unsigned int);
};
// Writes a formatted description of the location's cell, world, mesh or mesh list and coordinates into out up to capacity.
// @fnv 0x006de790
void DebugLocation::FormatDebugString(char* acBuffer, unsigned int capacity)
{
    if (!mesh || (meshes && !((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((meshes))->GetName()))))
    {
        if (!world)
        {
            ::FUN_00406d00(acBuffer, capacity, "Cell %s, %.2f %.2f %.2f", cell ? cell->editorName() : "NONE", location.x,
                         location.y, location.z);
        }
        else
        {
            int cellX2 = (int)location.x >> 12;
            int y8 = (int)location.y >> 12;
            DebugForm* found8 = ((::DebugForm *)(reinterpret_cast<::fnv_00587550::FUN_00587550_shell *>((world))->FUN_00587550((const ::fnv_00587550::NiPoint3 &)(location))));
            if (found8)
                ::FUN_00406d00(acBuffer, capacity, "Cell %s[%d,%d] %s,  %.2f %.2f %.2f", world->editorName(), cellX2, y8,
                             found8->editorName(), location.x, location.y, location.z);
            else
                ::FUN_00406d00(acBuffer, capacity, "Cell %s[%d,%d], %.2f %.2f %.2f", world->editorName(), cellX2, y8,
                             location.x, location.y, location.z);
        }
    }
    else
    {
        char meshName2[256];
        if (mesh)
        {
            if (triangle != 65535)
                ::FUN_00406d00(acBuffer, capacity, DAT_0106cdec, meshName2, triangle, location.x, location.y, location.z);
            else
                ::FUN_00406d00(acBuffer, capacity, DAT_0106cdd8, meshName2, location.x, location.y, location.z);
        }
        else
        {
            char list7[256];
            ::FUN_00406d00(list7, capacity, "[");
            {
                unsigned int i3;
                for (i3 = 0; i3 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((meshes))->GetName())); i3++)
                {
                    char entry2[64];
                    ::FUN_00406d00(entry2, 64, "%08x", ((unsigned int)(::FUN_00559450((int *)(((::DebugMesh *)(reinterpret_cast<::S3e60 *>((meshes))->FUN_006a7ad0(i3))))))));
                    FUN_00406d50(list7, 256, entry2);
                    if (i3 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((meshes))->GetName())) - 1)
                        FUN_00406d50(list7, 256, ", ");
                }
                FUN_00406d50(list7, 256, "]");
                DebugWorld* listWorld4 = ((::DebugWorld *)(::FUN_00690800((const ::NavMeshInfo *)(((::DebugMesh *)(reinterpret_cast<::S3e60 *>((meshes))->FUN_006a7ad0(0)))))));
                DebugForm* listCell3 = ((::DebugForm *)(reinterpret_cast<::NavMeshInfoStandIn *>((((::DebugMesh *)(reinterpret_cast<::S3e60 *>((meshes))->FUN_006a7ad0(0)))))->FUN_006b7770()));
                if (!listWorld4)
                {
                    ::FUN_00406d00(acBuffer, capacity, "%s Cell %s, %.2f %.2f %.2f", list7, listCell3->editorName(),
                                 location.x, location.y, location.z);
                }
                else
                {
                    int gx = (int)location.x >> 12;
                    int gy2 = (int)location.y >> 12;
                    if (listCell3 && FUN_00408b20(listCell3->editorName(), ""))
                        ::FUN_00406d00(acBuffer, capacity, "%s Cell %s[%d, %d](%s), %.2f %.2f %.2f", list7,
                                     listWorld4->editorName(), gx, gy2, listCell3->editorName(), location.x, location.y,
                                     location.z);
                    else
                        ::FUN_00406d00(acBuffer, capacity, "%s Cell %s[%d, %d], %.2f %.2f %.2f", list7,
                                     listWorld4->editorName(), gx, gy2, location.x, location.y, location.z);
                }
            }
        }
    }
}

struct PathingLocationCheck : PathingLocation
{
    bool FUN_006ded70(float fRadius);
};

bool __cdecl PathingLocationTestPoint(PathingLocation* pLoc, NiPoint3* pPoint, int a, int b);


// @fnv 0x006ded70
bool PathingLocationCheck::FUN_006ded70(float afRadius)
{
    reinterpret_cast<::PathingLocationProxy *>(this)->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
    if (!reinterpret_cast<::PathingLocation *>(this)->HasValidTriangle_006dd6a0())
        return false;
    if (afRadius <= ::_DAT_01012060)
        return true;
    NiPoint3 kLoc4 = reinterpret_cast<::TaskQueueInterface *>((void *)this)->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
    NiPoint3 kMinX2 = kLoc4;
    kMinX2.x -= afRadius;
    if (!PathingLocationTestPoint(this, &kMinX2, 0, 0))
        return false;
    NiPoint3 kMaxX7 = kLoc4;
    kMaxX7.x += afRadius;
    if (!PathingLocationTestPoint(this, &kMaxX7, 0, 0))
        return false;
    NiPoint3 kMinY = kLoc4;
    kMinY.y -= afRadius;
    if (!PathingLocationTestPoint(this, &kMinY, 0, 0))
        return false;
    NiPoint3 kMaxY6 = kLoc4;
    kMaxY6.y += afRadius;
    if (!PathingLocationTestPoint(this, &kMaxY6, 0, 0))
        return false;
    return true;
}

class Node_cls;

class NodeArr_cls
{
  public:
    void* unk00;
    Node_cls** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    Node_cls*& GetAt(unsigned int index);
    int Find(Node_cls** item, unsigned int start, int (*pred)());
};

class Node_cls
{
  public:
    unsigned char unk00[0x24];
    NodeArr_cls m_24;
    NodeArr_cls m_34;
};

class Owner_cls : public NodeArr_cls
{
  public:
};

class Snap_cls : public NodeArr_cls
{
  public:
    Snap_cls();
    ~Snap_cls();
    void Add(Node_cls** item);
};


class FUN_006de490_cls
{
  public:
    unsigned char unk00[0x10];
    int m_10;
    Owner_cls* m_14;
    bool HasAllNodes();
};
// Checks whether the location is reachable via its nav mesh or mesh array, pruning invalid meshes and updating reachability state.
// @fnv 0x006de250
bool PathingLocation::HasPathingLocation()
{
    if (reinterpret_cast<::FUN_006a9520_Class *>(this)->FUN_006a9520())
        return false;
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    else if (m_pLocationNavMesh)
    {
        if (::FUN_0068f320((const ::NavMeshInfo *)(m_pLocationNavMesh)))
            return false;
        else
            return true;
    }
    else
    {
        PathBuilderDetailedPathInfos meshes;
        ((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)->CopyTo(&meshes);
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)&meshes)->GetSize(); ++i)
        {
            struct
            {
                NavMeshBounds* bounds;
                NavMeshInfo* info;
            } meshEntry;
            meshEntry.info = (NavMeshInfo*)((NiFormArray*)&meshes)->FUN_00877a30(i);
            meshEntry.bounds = (NavMeshBounds*)((LowProcess*)meshEntry.info)->GetPackageObjectType();
            if (meshEntry.bounds)
            {
                if (reinterpret_cast<::MeshBounds *>((meshEntry.bounds))->ContainsPoint((const ::MeshPoint *)&(Location)))
                {
                    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((BSSimpleArray<unsigned short, 1024>*)&meshes)))->Clear(false);
                    reinterpret_cast<::FUN_00438690 *>((((BSSimpleArray<NavMeshInfo*, 1024>*)&meshes)))->FUN_007cb2e0((unsigned int *)&(meshEntry.info));
                    break;
                }
                else
                {
                    reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>((((BSSimpleArray<TESLoadScreen*, 1024>*)&meshes)))->FUN_009a4320(i, 1);
                    --i;
                }
            }
            else
            {
                NavMeshPtr mesh;
                if (meshEntry.info->ResolveNavMesh(mesh) && reinterpret_cast<::FUN_00440d80_shell *>((void *)(((NiPointer<NiNode>*)&mesh)->operator->()))->FUN_00440d80())
                {
                    reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>((((BSSimpleArray<TESLoadScreen*, 1024>*)&meshes)))->FUN_009a4320(i, 1);
                    --i;
                }
            }
        }
        if (((BSSimpleArray<SandboxProcedureData, 1024>*)&meshes)->GetSize() == 1)
        {
            m_pLocationNavMesh = ((::NavMeshInfo *)&(::GetFirstForm((::NiFormArray *)&(meshes))));
            pNavMeshInfoArray = 0;
            reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
            return true;
        }
        else
        {
            reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(reinterpret_cast<::FUN_006de490_cls *>(this)->HasAllNodes());
            return ((bool)(::IsPathingLocationFlagSet((::PathingLocation *)this)));
        }
    }
}

// @fnv 0x006de490
bool FUN_006de490_cls::HasAllNodes()
{
    Snap_cls list;
    Node_cls* itemB;
    Node_cls* fCur;
    Node_cls* item2;
    unsigned int aJ;
    unsigned int b;
    unsigned int iG;
    unsigned int j6;
    unsigned int k;
    bool changed2;
    int unk2C;

    if (m_10 != 0)
    {
        return true;
    }
    else
    {
        if (m_14 != 0 && !reinterpret_cast<::FUN_0076b610_Class *>((m_14))->FUN_0076b610())
        {
            reinterpret_cast<::FUN_00438690 *>(&(list))->FUN_007cb2e0((unsigned int *)(::Node_cls **)(((::Node_cls **)(reinterpret_cast<::S3e60 *>((m_14))->FUN_006a7ad0(0)))));
            aJ = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*((::Node_cls **)(reinterpret_cast<::S3e60 *>((m_14))->FUN_006a7ad0(0))))->m_24))->GetName()));
            b = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*((::Node_cls **)(reinterpret_cast<::S3e60 *>((m_14))->FUN_006a7ad0(0))))->m_34))->GetName()));
            for (iG = 0; iG < aJ + b; iG++)
            {
                if (iG < aJ)
                {
                    itemB = (*((::Node_cls **)(reinterpret_cast<::S3e60 *>((m_14))->FUN_006a7ad0(0))))->m_24.GetAt(iG);
                }
                else
                {
                    itemB = (*((::Node_cls **)(reinterpret_cast<::S3e60 *>((m_14))->FUN_006a7ad0(0))))->m_34.GetAt(iG - aJ);
                }
                if (m_14->Find(&itemB, 0, ((int (&)())::FUN_009a3830)) != -1)
                {
                    reinterpret_cast<::FUN_00438690 *>(&(list))->FUN_007cb2e0((unsigned int *)(::Node_cls **)(&itemB));
                }
            }
            if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(list))->GetName())) == ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((m_14))->GetName())))
            {
                return true;
            }
            do
            {
                changed2 = false;
                for (k = 1; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(list))->GetName())); k++)
                {
                    fCur = list.GetAt(k);
                    aJ = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(fCur->m_24))->GetName()));
                    b = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(fCur->m_34))->GetName()));
                    for (j6 = 0; j6 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(fCur->m_24))->GetName())); j6++)
                    {
                        if (j6 < aJ)
                        {
                            item2 = fCur->m_24.GetAt(j6);
                        }
                        else
                        {
                            item2 = fCur->m_34.GetAt(j6 - aJ);
                        }
                        if (m_14->Find(&item2, 0, ((int (&)())::FUN_009a3830)) != -1)
                        {
                            if (list.Find(&item2, 0, ((int (&)())::FUN_009a3830)) == -1)
                            {
                                reinterpret_cast<::FUN_00438690 *>(&(list))->FUN_007cb2e0((unsigned int *)(::Node_cls **)(&item2));
                                changed2 = true;
                            }
                        }
                    }
                }
            } while (changed2);
            if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(list))->GetName())) == ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((m_14))->GetName())))
            {
                return true;
            }
        }
    }
    return false;
}

struct NLPoint
{
    float x, y, z;
    NLPoint ApplyScaled(float fScale) const;            // operator*
      // operator+
      // operator-
                       // horizontal length
};

struct NLEdgeHit
{
    int m_iEdgeNumber;
    int unk04;
    NLPoint kPoint;
};

class NLMesh
{
  public:
    NLPoint FUN_00558220(unsigned short m_usTriangleID);  // triangle center
    NLEdgeHit FindEdgeIntersection(unsigned short m_usTriangleID, int m_iEdgeNumber, const NLPoint& kFrom,
                                   const NLPoint& kTo);
};

class NLMeshPtrView
{
  public:
      // operator->
    NLMesh* FUN_00458b50();  // get
};

class NLMeshInfo
{
  public:
      // ResolveNavMesh
};

class NLMeshInfoArray
{
  public:
                          // GetSize
      // GetAt
};

class NLTES
{
  public:
};
  // FLT_MAX

class NLLocation
{
  public:
    void** m_ppVirtualMethodTable;
    NLPoint Location;
    NLMeshInfo* m_pLocationNavMesh;
    NLMeshInfoArray* pNavMeshInfoArray;
    void* pCell;
    void* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;

    bool UpdateMeshLocation();
};
// @fnv 0x006dd6f0
bool PathingLocationProxy::FindContainingTriangle(FindTriangleForLocationFilter* filter)
{
    if (reinterpret_cast<::FUN_006a9520_Class *>(this)->FUN_006a9520())
        return false;
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    else if (m_pLocationNavMesh)
    {
        if (::FUN_0068f320((const ::NavMeshInfo *)(m_pLocationNavMesh)))
            return false;
        if (m_usTriangleID == 0xffff)
        {
            NavMeshPtr mesh;
            if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(mesh))
                m_usTriangleID =
                    reinterpret_cast<::fnv_00696a50::FUN_00696a50_shell *>((((NavMesh*)((NiPointer<NiNode>*)&mesh)->operator->())))->FUN_00696a50((const ::NiPoint3 *)&(Location), (int)(filter));
        }
        return true;
    }
    else if (reinterpret_cast<::PathingLocation *>(this)->GetContainingCell() && ::FUN_00450ff0((void *)(reinterpret_cast<::PathingLocation *>(this)->GetContainingCell())))
    {
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            NavMeshPtr mesh;
            if (((NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(i))))
                    ->ResolveNavMesh(mesh) &&
                !((NiPointer<NiNode>*)&mesh)->operator->()->GetDisabled())
            {
                unsigned short triangle =
                    reinterpret_cast<::fnv_00696a50::FUN_00696a50_shell *>((((NavMesh*)((NiPointer<NiNode>*)&mesh)->operator->())))->FUN_00696a50((const ::NiPoint3 *)&(Location), (int)(filter));
                if (triangle != 0xffff)
                {
                    m_pLocationNavMesh =
                        (NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(i)));
                    pNavMeshInfoArray = 0;
                    m_usTriangleID = triangle;
                    reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
                    return true;
                }
            }
        }
        NiPoint3 savedLocation = Location;
        bool resolved = reinterpret_cast<::NLLocation *>(this)->UpdateMeshLocation();
        m_usTriangleID = kClearTriangleDataValue1;
        Location = savedLocation;
        if (resolved)
            reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
        else
            reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(((bool)(::IsPathingLocationFlagSet((::PathingLocation *)this))));
        return resolved;
    }
    else
    {
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            const NavMeshInfo* info = (NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(i)));
            if (!::FUN_0068f320((const ::NavMeshInfo *)(info)))
            {
                NavMeshBounds* bounds = (NavMeshBounds*)((LowProcess*)info)->GetPackageObjectType();
                if (bounds && reinterpret_cast<::MeshBounds *>((bounds))->ContainsPoint((const ::MeshPoint *)&(Location)))
                {
                    m_pLocationNavMesh =
                        (NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(i)));
                    pNavMeshInfoArray = 0;
                    NavMeshPtr mesh;
                    if (const_cast<NavMeshInfo*>(m_pLocationNavMesh)->ResolveNavMesh(mesh))
                        m_usTriangleID = reinterpret_cast<::fnv_00696a50::FUN_00696a50_shell *>((((NavMesh*)((NiPointer<NiNode>*)&mesh)->operator->())))->FUN_00696a50((const ::NiPoint3 *)&(Location), (int)(filter));
                    reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
                    return true;
                }
            }
        }
        struct
        {
            int noBoundsIndex;
            float minimumDistance;
            int closestIndex;
        } nearest;
        nearest.noBoundsIndex = -1;
        nearest.minimumDistance = 3.402823466e+38F;
        nearest.closestIndex = -1;
        for (unsigned int i = 0; i < ((BSSimpleArray<SandboxProcedureData, 1024>*)pNavMeshInfoArray)->GetSize(); ++i)
        {
            const NavMeshInfo* info = (NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(i)));
            if (!::FUN_0068f320((const ::NavMeshInfo *)(info)))
            {
                NavMeshBounds* bounds = (NavMeshBounds*)((LowProcess*)info)->GetPackageObjectType();
                if (bounds)
                {
                    NiPoint3 delta = bounds->FUN_0069c070(Location);
                    float distance = reinterpret_cast<::TESCombatStyle *>((void *)&(delta))->UpdateCombatStyle();
                    if (distance < nearest.minimumDistance)
                    {
                        nearest.minimumDistance = distance;
                        nearest.closestIndex = i;
                    }
                }
                else
                    nearest.noBoundsIndex = i;
            }
        }
        if (nearest.minimumDistance < ::DAT_0106cd60)
        {
            m_pLocationNavMesh =
                (NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(nearest.closestIndex)));
            pNavMeshInfoArray = 0;
            m_usTriangleID = kClearTriangleDataValue1;
            reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
            return true;
        }
        else
        {
            m_pLocationNavMesh =
                (NavMeshInfo*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)pNavMeshInfoArray)))->FUN_006a7ad0(nearest.noBoundsIndex)));
            pNavMeshInfoArray = 0;
            reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(reinterpret_cast<::FUN_006de490_cls *>(this)->HasAllNodes());
            return ((bool)(::IsPathingLocationFlagSet((::PathingLocation *)this)));
        }
    }
}

// @fnv 0x006ddc00
bool NLLocation::UpdateMeshLocation()
{
    reinterpret_cast<::SetupPathingLocation *>(this)->FUN_006dd280((const ::NiPoint3 &)(Location), (::TESObjectCELL *)(pCell), (::TESWorldSpace *)(m_pContainingWorldspace));
    if (!m_pLocationNavMesh && !pNavMeshInfoArray)
        return false;
    if (m_pLocationNavMesh && m_usTriangleID != kClearTriangleDataValue1)
        return true;

    if (m_pLocationNavMesh)
    {
        bool bInside = false;
        NavMeshPtr kMeshPtr;
        if (reinterpret_cast<::NavMeshInfo *>((m_pLocationNavMesh))->ResolveNavMesh(kMeshPtr))
        {
            if (reinterpret_cast<::fnv_00696cf0::Host696 *>((((::NLMesh *)(::FUN_00559450((int *)(((NLMeshPtrView*)&kMeshPtr)))))))->FUN_00696cf0((const ::NiPoint3 &)(Location), (unsigned short *)&(m_usTriangleID), (bool *)&(bInside)))
            {
                if (!bInside)
                {
                    NLPoint kTriCenter = ((::NLMesh *)(::FUN_00559450((int *)(((NLMeshPtrView*)&kMeshPtr)))))->FUN_00558220(m_usTriangleID);
                    NLEdgeHit kResult = ((::NLMesh *)(::FUN_00559450((int *)(((NLMeshPtrView*)&kMeshPtr)))))
                                            ->FindEdgeIntersection(m_usTriangleID, -1, kTriCenter, Location);
                    if (kResult.m_iEdgeNumber)
                        Location = (*(::NLPoint *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NLPoint &)(kResult.kPoint.ApplyScaled(0.9f)))->ProjectileLaunched((::NiPoint3 *)&(const ::NLPoint &)(kTriCenter.ApplyScaled(0.1f)), {})));
                }
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
    {
        float fNearest = ::DAT_01016970;
        int iClosest = -1;
        unsigned short usBestTri = kClearTriangleDataValue1;
        bool bValidFound = false;
        unsigned int uiNumMeshes = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((pNavMeshInfoArray))->GetName()));
        bool bClose = false;
        if (reinterpret_cast<::FUN_0045cbc0_shell *>(((*reinterpret_cast<::NLTES * *>(&::g_TES))))->GetCellHeightAtPosition((const ::NiPoint3 *)&(Location), (::CellView *)(pCell)) + 25.0 > Location.z)
            bClose = true;
        for (unsigned int i = 0; i < uiNumMeshes; i++)
        {
            unsigned short usTri = kClearTriangleDataValue1;
            bool bInTri = false;
            NavMeshPtr pFoundNavMesh;
            NLMeshInfo* pInfo = ((::NLMeshInfo *)(reinterpret_cast<::S3e60 *>((pNavMeshInfoArray))->FUN_006a7ad0(i)));
            if (!::FUN_0068f320((const ::NavMeshInfo *)(pInfo)) && reinterpret_cast<::NavMeshInfo *>((pInfo))->ResolveNavMesh(pFoundNavMesh) &&
                !reinterpret_cast<::fnv_00696cf0::Host696 *>((((::NLMesh *)(::FUN_00559450((int *)(((NLMeshPtrView*)&pFoundNavMesh)))))))->FUN_00696cf0((const ::NiPoint3 &)(Location), (unsigned short *)&(usTri), (bool *)&(bInTri)))
                continue;
            if (bInTri)
            {
                m_pLocationNavMesh = ((::NLMeshInfo *)(reinterpret_cast<::S3e60 *>((pNavMeshInfoArray))->FUN_006a7ad0(i)));
                pNavMeshInfoArray = 0;
                m_usTriangleID = usTri;
                return true;
            }
            else if (((NLMeshPtrView*)&pFoundNavMesh)->FUN_00458b50())
            {
                NLPoint kToCenter =
                    (*(::NLPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(Location))->FUN_00439ef0((::NiPoint3 *)&(const ::NLPoint &)(((::NLMesh *)(::FUN_00559450((int *)(((NLMeshPtrView*)&pFoundNavMesh)))))->FUN_00558220(usTri)), *(const ::NiPoint3 *)nullptr)));
                float fDist = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(kToCenter))->GetSquaredXYLength();
                float m_fGlyphExtent = kToCenter.z;
                bool bGood = false;
                if ((bClose || m_fGlyphExtent < 180.0) && m_fGlyphExtent > -64.0)
                    bGood = true;
                if (bValidFound)
                {
                    if (bGood && fDist < fNearest)
                    {
                        fNearest = fDist;
                        usBestTri = usTri;
                        iClosest = i;
                    }
                }
                else if (bGood)
                {
                    fNearest = fDist;
                    usBestTri = usTri;
                    iClosest = i;
                    bValidFound = true;
                }
                else if (fDist < fNearest)
                {
                    fNearest = fDist;
                    usBestTri = usTri;
                    iClosest = i;
                }
            }
        }
        if (iClosest != -1)
        {
            m_pLocationNavMesh = ((::NLMeshInfo *)(reinterpret_cast<::S3e60 *>((pNavMeshInfoArray))->FUN_006a7ad0(iClosest)));
            pNavMeshInfoArray = 0;
            m_usTriangleID = usBestTri;
            NavMeshPtr spBest;
            if (reinterpret_cast<::NavMeshInfo *>((m_pLocationNavMesh))->ResolveNavMesh(spBest))
            {
                NLPoint kTriCenter = ((::NLMesh *)(::FUN_00559450((int *)(((NLMeshPtrView*)&spBest)))))->FUN_00558220(usBestTri);
                NLEdgeHit kResult = ((::NLMesh *)(::FUN_00559450((int *)(((NLMeshPtrView*)&spBest)))))
                                        ->FindEdgeIntersection(usBestTri, -1, kTriCenter, Location);
                if (kResult.m_iEdgeNumber)
                    Location = (*(::NLPoint *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::NLPoint &)(kTriCenter.ApplyScaled(0.1f)))->ProjectileLaunched((::NiPoint3 *)&(const ::NLPoint &)(kResult.kPoint.ApplyScaled(0.9f)), {})));
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
}

class PathingRequest;
class PathingSolution;

class FUN_006d0b80
{
  public:
    ~FUN_006d0b80();

    int unk00[13];
};

class PathBuilder : public FUN_006d0b80
{
  public:
    PathBuilder(PathingRequest* pRequest, PathingSolution* m_pOutputSolution);
    bool BuildPath();
};

// Creates a PathBuilder from pRequest and m_pOutputSolution, calls BuildPath, and returns its result.
// @fnv 0x006d0b10
bool __cdecl FUN_006d0b10(PathingRequest* pRequest, PathingSolution* m_pOutputSolution)
{
    PathBuilder kBuilder(pRequest, m_pOutputSolution);
    bool bResult = kBuilder.BuildPath();
    return bResult;
}
