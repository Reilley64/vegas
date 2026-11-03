// fallout_shared/pathfinding/navmesh.cpp: NavMesh, ActorMover, BGSCameraPath, TESEffectShader and more (97 functions)

#include <cstdint>
#include "generated/data/vtables.h"
#include <new>
#include <cmath>
#include <cstring>
#include "fnv/decl/B42FA60Allocator.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_005582d0_shell.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_005a8040_class.h"
#include "fnv/decl/FUN_005eeda0_this.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00644400_Class.h"
#include "fnv/decl/FUN_00644490_Class.h"
#include "fnv/decl/FUN_00691820_arr.h"
#include "fnv/decl/FUN_006918c0_class.h"
#include "fnv/decl/FUN_00691c10_class.h"
#include "fnv/decl/FUN_00691c90_shell.h"
#include "fnv/decl/FUN_00692000_class.h"
#include "fnv/decl/FUN_006923f0_class.h"
#include "fnv/decl/FUN_00692740_class.h"
#include "fnv/decl/FUN_006927d0_cls.h"
#include "fnv/decl/FUN_0069da10_C.h"
#include "fnv/decl/FUN_006b8310_class.h"
#include "fnv/decl/FUN_006c6200_cls.h"
#include "fnv/decl/FUN_006dcfe0_shell.h"
#include "fnv/decl/FUN_006df760_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Falloff6dc.h"
#include "fnv/decl/InteriorCellLookup.h"
#include "fnv/decl/NavigationOwner.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/PlacementRange.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/SwapMesh.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaitableObject.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d4000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_0068f000.h"
#include "fnv/symbols_00690000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006f3000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0106a000.h"
#include "fnv/symbols_011de000.h"
class ActorMover
{
  public:
    char _pad24[0x24];
    unsigned int preferredMoveMode;
    unsigned int GetCurrentMoveModeType();
};

class BGSCameraPath
{
  public:
    char _pad34[0x34];
    BGSCameraPath* previousPath;
    BGSCameraPath* GetPrevPath();
};

class BGSDebris;
class TESEffectShader
{
  public:
    char _pad10c[0x10c];
    BGSDebris* addonModels;
    BGSDebris* GetAddonModels();
};

class InventoryStackRecord;
class MiddleHighProcess
{
  public:
    char _pad114[0x114];
    InventoryStackRecord* currentWeapon;
    InventoryStackRecord* GetActiveWeapon();
};

class EdgeExtraInfo;
class NavMeshStaticAvoidNode
{
  public:
    char _pad24[0x24];
    unsigned short triangle;
};
class NavMeshTriangle;
class NavMeshInfo;
class TESForm;
class TESObjectCELL;
class TESWorldSpace;

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
};

class CoordinateTriple
{
  public:
    NiPoint3 Point;
    TESForm* m_pPathingCell;
};

template <class T> class BSSimpleList
{
  public:
    T item;
    T& GetItem();
};

template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** vtable;
    T* buffer;
    unsigned int size;
    unsigned int reserved;
    unsigned int GetSize();
    T& GetAt(int);
    unsigned int Add(T&);
    EdgeExtraInfo* FUN_00558dd0(unsigned short, int);
    EdgeExtraInfo* FUN_006a1440(unsigned short);
    NavMeshStaticAvoidNode* FUN_00691750(int);
    bool FUN_0076b610();
};

class EdgeExtraInfo
{
  public:
    int type;
    int portal;
    int reserved;
};

class PathingLocation
{
  public:
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const BSSimpleArray<const NavMeshInfo*, 1024>* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    unsigned char _pad27;
    PathingLocation(const CoordinateTriple&, NavMeshInfo*, unsigned short);
};

class NavMeshPtr;
class NavMeshInfo
{
  public:
    char _pad0c[0x4];
    unsigned int unk04;
    unsigned int unk08;
    unsigned int locationKey;
public:
    bool AcquireNavMesh(::NavMeshPtr &);
};

class NavMeshTriangle;
class NiPoint3;
class NavMesh
{
  public:
    char _pad38[0x38];
    BSSimpleArray<NavMeshTriangle, 1024> Triangles;
    BSSimpleArray<EdgeExtraInfo, 1024> m_kEdgeExtraInfo;
    char _pad58_f4[0x9c];
    BSSimpleArray<NavMeshStaticAvoidNode, 1024> m_kStaticAvoidNodes;
    NavMeshStaticAvoidNode* GetStaticAvoidNodeData();
    bool GetStaticAvoidNodesForTriangle(unsigned short, BSSimpleArray<NavMeshStaticAvoidNode*, 1024>&);
public:
    ::NavMeshTriangle *GetTriangle(unsigned short);
public:
    ::NiPoint3 GetPlaneNormal(unsigned short);
};

// @fnv 0x0059bb30
unsigned int ActorMover::GetCurrentMoveModeType()
{
    return preferredMoveMode;
}

// @fnv 0x005f36f0
BGSCameraPath* BGSCameraPath::GetPrevPath()
{
    return previousPath;
}

// @fnv 0x005a29b0
BGSDebris* TESEffectShader::GetAddonModels()
{
    return addonModels;
}

// @fnv 0x008d81e0
InventoryStackRecord* MiddleHighProcess::GetActiveWeapon()
{
    return currentWeapon;
}

// @fnv 0x00691660
bool NavMesh::GetStaticAvoidNodesForTriangle(unsigned short triangle,
                                             BSSimpleArray<NavMeshStaticAvoidNode*, 1024>& arOutput)
{
    unsigned int i = 0;
    for (; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((BSSimpleArray<NavMeshInfo*, 1024>&)m_kStaticAvoidNodes)))->GetName())); ++i)
    {
        if (reinterpret_cast<::FUN_006df760_shell *>((m_kStaticAvoidNodes.FUN_00691750(i)))->GetShortValueAtOffset24() == triangle)
        {
            NavMeshStaticAvoidNode* node = m_kStaticAvoidNodes.FUN_00691750(i);
            reinterpret_cast<::FUN_00438690 *>(&(((BSSimpleArray<NavMeshInfo*, 1024>&)arOutput)))->FUN_007cb2e0((unsigned int *)&(*(NavMeshInfo**)&node));
        }
    }
    return !reinterpret_cast<::FUN_0076b610_Class *>(&(arOutput))->FUN_0076b610();
}

// Initializes a PathingLocation from a location, NavMeshInfo and triangle index, storing the navmesh's cell or location key and marking all meshes reachable.
// @fnv 0x006dd010
PathingLocation::PathingLocation(const CoordinateTriple& location, NavMeshInfo* navMesh, unsigned short triangle)
{
    m_ppVirtualMethodTable = (void**)fnv_vftable_DAT_0102583c;
    Location = location.Point;
    uiFlags = 0;
    m_pLocationNavMesh = navMesh;
    pNavMeshInfoArray = 0;
    m_pContainingWorldspace = ::FUN_00690800((const ::NavMeshInfo *)(navMesh));
    if (m_pContainingWorldspace)
    {
        pCell = 0;
        m_uiPathingFlags = navMesh->locationKey;
    }
    else
    {
        pCell = reinterpret_cast<::InteriorCellLookup *>((navMesh))->FUN_006b77b0();
        m_uiPathingFlags = 0xdeaddead;
    }
    reinterpret_cast<::FUN_006dcfe0_shell *>(this)->FUN_006dcfe0(true);
    m_usTriangleID = triangle;
}

struct BSExtraData
{
    virtual void vb();
    char pad[8];
    BSExtraData(unsigned char);
    ~BSExtraData();
};
struct TwoIntRecord
{
    int h[2];
    TwoIntRecord(const TwoIntRecord&);
};
extern int DAT_01014618;
struct FUN_00416ad0 : public BSExtraData
{
    TwoIntRecord vh;
    FUN_00416ad0(TwoIntRecord v);
};
// @fnv 0x00416ad0
FUN_00416ad0::FUN_00416ad0(TwoIntRecord v) : BSExtraData(0x5a), vh(v)
{}

class NiAVObject
{
  public:
};

// If the stored object pointer is non-null, calls FUN_00401970 on the NiAVObject at offset 0x1c within it.
// @fnv 0x0042fda0
void FUN_0042fda0(char** pObjectPtr)
{
    if (*pObjectPtr != 0)
    {
        reinterpret_cast<::WaitableObject *>((((NiAVObject*)(*pObjectPtr + 0x1c))))->FUN_00401970();
    }
}

struct FUN_0068ed30_shell : public NavMesh
{
    void DestroyNavMesh();
};

struct NavMeshDestructView
{
    void FUN_0068ed70();
};

class NiMemObject
{
  public:
};

struct FUN_0068ed30_impl : public FUN_0068ed30_shell
{
    void* DestroyNavMesh(unsigned int flags);
};

// Calls the NavMesh destructor and, when bit 0 of flags is set, frees this with NiMemObject::operator delete; returns this.
// @fnv 0x0068ed30
void* FUN_0068ed30_impl::DestroyNavMesh(unsigned int flags)
{
    reinterpret_cast<NavMeshDestructView*>(this)->FUN_0068ed70();
    if (flags & 1)
    {
        ::FUN_00aa1460(this, 0x108);
    }
    return this;
}

struct NavMeshInfo;
struct FUN_0068efb0_shell : public NavMesh
{
    NavMeshInfo* FUN_0068efb0();
};

// @fnv 0x0068efb0
NavMeshInfo* FUN_0068efb0_shell::FUN_0068efb0()
{
    return *(NavMeshInfo**)((char*)this + 0x104);
}

struct EdgeT
{
    unsigned short a;
    unsigned short b;
};
struct EdgeV
{
    const NiPoint3* a;
    const NiPoint3* b;
};
struct NH
{
};
struct FloatValueProvider : public NavMesh
{
    EdgeV FUN_0068f040(unsigned short tri, int idx);
};
struct FUN_0068f0a0_shell : public NavMesh
{
    void* FUN_0068f0a0(unsigned short);
};

// @fnv 0x0068f0a0
void* FUN_0068f0a0_shell::FUN_0068f0a0(unsigned short asVertexIndex)
{
    return ((BSSimpleArray<EdgeExtraInfo, 1024>*)((char*)this + 0x28))->FUN_006a1440(asVertexIndex);
}

struct EdgeExtraInfo;
struct FUN_0068f230_shell : public NavMesh
{
    EdgeExtraInfo* FUN_0068f230(unsigned short, int);
};

// @fnv 0x0068f320
bool FUN_0068f320(const NavMeshInfo* apNavMeshInfo)
{
    return (*(const unsigned int*)&apNavMeshInfo->unk08 & 0x10) != 0;
}

class TESForm
{
  public:
    virtual ~TESForm();
};
class TESObjectCELL;
class TESWorldSpace : public TESForm
{
public:
    ::TESObjectCELL *GetCellAtGridPosition(int, int);
};

TESForm* FUN_00690830(const NavMeshInfo*);

// Casts the result of FUN_00690830(_this) to TESWorldSpace* and returns it.
// @fnv 0x00690800
TESWorldSpace* FUN_00690800(const NavMeshInfo* apNavMeshInfo)
{
    return dynamic_cast<TESWorldSpace*>(FUN_00690830(apNavMeshInfo));
}


// @fnv 0x00690830
TESForm* FUN_00690830(const NavMeshInfo* pThis)
{
    if (*(TESForm**)((char*)pThis + 0x1c))
        return *(TESForm**)((char*)pThis + 0x1c);
    else
        return ::FUN_004839c0(*(unsigned int*)&pThis->unk04);
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct PathingAvoidanceNode
{
    float GetAvoidanceAtPoint(NiPoint3*);
    int GetType();
    void* GetPoint1();
    void* GetPoint2();
    float GetRadius();
    float GetCost();
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    NiPoint3 m_kLocation;
    NiPoint3 TwoComponentVector;
    float fRadius;
    float m_fPathingCostCur;
    int eType;
};
struct FUN_006915d0_shell : public PathingAvoidanceNode
{
    void FUN_006915d0(void*, void*, float, float);
};


struct FUN_006915d0_helper : public PathingAvoidanceNode
{
    PathingAvoidanceNode* FUN_006915d0(const NiPoint3& arPoint, float afRadius, float afCost);
};

// @fnv 0x006915d0
PathingAvoidanceNode* FUN_006915d0_helper::FUN_006915d0(const NiPoint3& arPoint, float afRadius, float afCost)
{
    m_kLocation = arPoint;
    (void *)(&TwoComponentVector);
    fRadius = afRadius;
    m_fPathingCostCur = afCost;
    eType = 0;
    return this;
}

extern int DAT_01031fac;

struct FUN_006916f0_arg
{
    unsigned int val;
};


// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006916f0
int* FUN_006916f0(int* self, FUN_006916f0_arg a)
{
    new ((void *)(self)) ::FUN_006918c0_class((*(unsigned int *)&(const ::FUN_006916f0_arg &)(a)));
    *reinterpret_cast<void**>(self) = &DAT_01031fac;
    return self;
}

namespace fnv_00691720 {
extern int DAT_01031fac;

struct FUN_00691720_arg
{
    unsigned int val;
};

void FUN_005890c0(int* self, FUN_00691720_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00691720
int* FUN_00691720(int* self, FUN_00691720_arg a)
{
    FUN_005890c0(self, a);
    *reinterpret_cast<void**>(self) = &DAT_01031fac;
    return self;
}
}  // namespace fnv_00691720

// @fnv 0x00691750
template <class T, unsigned int Growth> NavMeshStaticAvoidNode* BSSimpleArray<T, Growth>::FUN_00691750(int aiIndex)
{
    return reinterpret_cast<NavMeshStaticAvoidNode*>(reinterpret_cast<char*>(buffer) + aiIndex * 0x28);
}

template NavMeshStaticAvoidNode* BSSimpleArray<NavMeshStaticAvoidNode, 1024>::FUN_00691750(int);

class GlobalObject_00869f00
{
  public:
    void* vtable;
};


// @fnv 0x00691800
void FUN_00691800(GlobalObject_00869f00* pThis)
{
    pThis->vtable = &(*reinterpret_cast<void * *>(&::DAT_0106abe4));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((pThis))->Clear(true);
}


struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// @fnv 0x00691a60
void* FUN_00691a60(int** pThis)
{
    *pThis = &(*reinterpret_cast<int *>(&::fnv_00691a90::DAT_010159d4));
    reinterpret_cast<Dummy0042f800*>(pThis)->FUN_0042fcb0(0, 0);
    return pThis;
}

struct Helper_00644400
{
};

// Sets the vtable pointer and calls FUN_00644400 with 0, 0, then returns the object.
// @fnv 0x00691b10
void* FUN_00691b10(BSSimpleArray<NavMeshTriangle, 1024>* apArray)
{
    apArray->vtable = &DAT_0106ac2c;
    reinterpret_cast<::FUN_00644400_Class *>((reinterpret_cast<Helper_00644400*>(apArray)))->FUN_00644400(0, 0);
    return apArray;
}


struct FUN_006923f0_Caller
{
};

// Sets the vtable of pThis and calls FUN_006923f0 with 0, 0, then returns pThis.
// @fnv 0x00691bc0
BSSimpleArray<EdgeExtraInfo, 1024>* FUN_00691bc0(BSSimpleArray<EdgeExtraInfo, 1024>* apArray)
{
    apArray->vtable = &DAT_0106ac40;
    reinterpret_cast<::FUN_006923f0_class *>((reinterpret_cast<FUN_006923f0_Caller*>(apArray)))->FUN_006923f0(0, 0);
    return apArray;
}


struct Dummy_00691d40
{
    void FUN_00692520(int, int);
};

// Sets *thisPtr to point at DAT_0106ac54, then calls FUN_00692520 with 0, 0 and returns thisPtr.
// @fnv 0x00691d40
void* FUN_00691d40(void** thisPtr)
{
    *thisPtr = &DAT_0106ac54;
    reinterpret_cast<Dummy_00691d40*>(thisPtr)->FUN_00692520(0, 0);
    return thisPtr;
}

struct Helper_00692520
{
    void FUN_00692520(int, int);
};

// Stores the string "@!i" at *_this, then calls FUN_00692520 with 0 and 0, and returns _this.
// @fnv 0x00691d90
const char** FUN_00691d90(const char** _this)
{
    *_this = "@!i";
    reinterpret_cast<Helper_00692520*>(_this)->FUN_00692520(0, 0);
    return _this;
}

class NiAVObject;
template <class T> class NiPointer;
extern void* DAT_0106ac9c;
template <> class BSSimpleArray<NiPointer<NiAVObject>, 1024>
{
  public:
    void** vtable;
    void FUN_00822860(unsigned int, bool);
};

// Sets the vtable pointer and calls FUN_00822860 with 0 and false, then returns the array.
// @fnv 0x00691f60
BSSimpleArray<NiPointer<NiAVObject>, 1024>* FUN_00691f60(BSSimpleArray<NiPointer<NiAVObject>, 1024>* _this)
{
    _this->vtable = &DAT_0106ac9c;
    _this->FUN_00822860(0, false);
    return _this;
}

namespace fnv_00691fb0 {

struct Dummy0042f800
{
};

// @fnv 0x00691fb0
void* FUN_00691fb0(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<::FUN_00692740_class *>((reinterpret_cast<Dummy0042f800*>(pThis)))->FUN_00692740(0, 0);
    return pThis;
}
}  // namespace fnv_00691fb0

struct NavMeshClosedDoorInfo
{
    unsigned int m_uiDoorFormID;
    unsigned short m_usDoorTriangleIndex;
    char _pad_6[2];
};
struct FUN_00692870_shell : public NavMeshClosedDoorInfo
{
    void InitNavMeshClosedDoorInfo(void*);
};

// @fnv 0x00692870
NavMeshClosedDoorInfo* InitNavMeshClosedDoorInfo(NavMeshClosedDoorInfo* pThis)
{
    pThis->m_uiDoorFormID = 0;
    pThis->m_usDoorTriangleIndex = 0xFFFF;
    return pThis;
}

struct G00559a40
{
};
struct Holder42
{
    char* p;
    Holder42* FUN_0042fd70(char*);
};
// @fnv 0x0042fb00
NavMeshStaticAvoidNode* NavMesh::GetStaticAvoidNodeData()
{
    reinterpret_cast<::Holder42 *>(this)->FUN_0042fd70((char *)(0));
    return (NavMeshStaticAvoidNode*)this;
}
// Stores v in p and, when v is non-null, calls FUN_0040f6e0 on the object at v+0x1c; returns this.
// @fnv 0x0042fd70
Holder42* Holder42::FUN_0042fd70(char* v)
{
    p = v;
    if (p)
    {
        reinterpret_cast<::FUN_0040f6e0_class *>((((G00559a40*)(p + 0x1c))))->FUN_0040f6e0();
    }
    return this;
}

namespace fnv_0068f0c0 {
struct NavMeshTriangleVertexIndices
{
    char Vertices[4];
};
struct NavMeshEdgeVertexPair
{
    char Vertices[8];
};
struct FUN_0068f0c0_shell : public NavMesh
{
    bool FUN_0068f0c0(unsigned short, int, NiPoint3*, NiPoint3*);
};

struct NavMeshTriangle
{
};
struct NavMesh_GetTriangle_h
{
};
struct NH
{
};

// Looks up the two vertex indices of the given triangle edge and writes their positions into p0 and p1, returning true.
// @fnv 0x0068f0c0
bool FUN_0068f0c0_shell::FUN_0068f0c0(unsigned short ausTriIndex, int aiEdgeIndex, NiPoint3* pStartVertex,
                                      NiPoint3* pEndVertex)
{
    int iNext;
    unsigned short v1;
    unsigned short v0;
    v1 = reinterpret_cast<::FUN_005582d0_shell *>((((::fnv_0068f0c0::NavMeshTriangle *)(reinterpret_cast<::NavMesh *>((((NavMesh_GetTriangle_h*)this)))->GetTriangle(ausTriIndex)))))->FUN_005582d0(aiEdgeIndex);
    iNext = (aiEdgeIndex + 1) % 3;
    v0 = reinterpret_cast<::FUN_005582d0_shell *>((((::fnv_0068f0c0::NavMeshTriangle *)(reinterpret_cast<::NavMesh *>((((NavMesh_GetTriangle_h*)this)))->GetTriangle(ausTriIndex)))))->FUN_005582d0(iNext);
    *pStartVertex = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((((NH*)this)))->FUN_0068f0a0(v1)));
    *pEndVertex = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((((NH*)this)))->FUN_0068f0a0(v0)));
    return true;
}
}  // namespace fnv_0068f0c0

struct FUN_00690e10_shell
{
    char _pad0c[0x0c];
    unsigned int flags;
    bool FUN_00690e10();
};

// @fnv 0x00690e10
bool FUN_00690e10_shell::FUN_00690e10()
{
    return (flags & 7) != 0;
}

struct FUN_00691000_shell
{
    char _pad38[0x38];
    void FUN_00691000(std::intptr_t arg);
};

struct FUN_00691020_shell
{
    char _pad48[0x48];
    void FUN_00691020(std::intptr_t a);
};

// @fnv 0x00691020
void FUN_00691020_shell::FUN_00691020(std::intptr_t a)
{
    reinterpret_cast<::FUN_00691c10_class *>((((FUN_00691020_shell*)((char*)this + 0x48))))->FUN_00691c10((*(const ::S00691c60 *)(a)));
}

struct ArrSI
{
};

struct FUN_00691620_shell
{
    char _padf4[0xf4];
    ArrSI* pArrSI;
    unsigned int GetFlags();
};

// @fnv 0x00691620
unsigned int FUN_00691620_shell::GetFlags()
{
    return ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0xf4))))->GetName()));
}

struct FUN_00691640_shell : NavMesh
{
    NavMeshStaticAvoidNode* FUN_00691640(int index);
};

// @fnv 0x00691640
NavMeshStaticAvoidNode* FUN_00691640_shell::FUN_00691640(int index)
{
    return m_kStaticAvoidNodes.FUN_00691750(index);
}

namespace fnv_00691a90 {
struct GlobalObject_00869f00
{
    void* vtable;
    void FUN_00691a90();
};


// @fnv 0x00691a90
void GlobalObject_00869f00::FUN_00691a90()
{
    this->vtable = &DAT_010159d4;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this))->Clear(true);
}
}  // namespace fnv_00691a90

namespace fnv_00691d70 {

struct GlobalObject_00869f00
{
    void* vtable;
    void FUN_00691d70();
};

// @fnv 0x00691d70
void GlobalObject_00869f00::FUN_00691d70()
{
    vtable = &::DAT_0106ac54;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_00691d70

struct FUN_00691e50_shell
{
    bool IsEqual(unsigned short a, unsigned short b);
};

// @fnv 0x00691e50
bool FUN_00691e50_shell::IsEqual(unsigned short ausLeft, unsigned short ausRight)
{
    return ausLeft == ausRight;
}

struct NiTPointerMap
{
};

struct FUN_00691f00_shell : NiTPointerMap
{
    char _pad8[8];
    void* _member8;
    void FUN_00691f00();
};

// Sets the vtable pointer to "p!i", removes all entries from the map, and frees the member pointer.
// @fnv 0x00691f00
void FUN_00691f00_shell::FUN_00691f00()
{
    *reinterpret_cast<void**>(this) = (void*)"p!i";
    reinterpret_cast<::FUN_00438af0_Class *>((this))->FUN_00438af0();
    ::FUN_00aa10f0(_member8);
}

extern void* DAT_0106ac9c;

struct Arr3520
{
    void* vtable;
    void FUN_00691f90();
};

// @fnv 0x00691f90
void Arr3520::FUN_00691f90()
{
    vtable = (void*)&DAT_0106ac9c;
    reinterpret_cast<::FUN_006c6200_cls *>(this)->FUN_006c6200(true);
}

namespace fnv_0042fd40 {
struct G00559a40
{
};

struct FUN_0042fd40_shell
{
    void* FUN_0042fd40(void* arg);
};

// Copies the value from arg into this and, if non-zero, calls FUN_0040f6e0 on the object at offset 0x1c of that value; returns this.
// @fnv 0x0042fd40
void* FUN_0042fd40_shell::FUN_0042fd40(void* apSource)
{
    *reinterpret_cast<unsigned int*>(this) = *reinterpret_cast<unsigned int*>(apSource);
    if (*reinterpret_cast<unsigned int*>(this) != 0)
    {
        reinterpret_cast<::FUN_0040f6e0_class *>((reinterpret_cast<G00559a40*>(*reinterpret_cast<unsigned int*>(this) + 0x1c)))->FUN_0040f6e0();
    }
    return this;
}
}  // namespace fnv_0042fd40

namespace fnv_0068f160 {
struct NavMeshTriangle
{
};

struct NavMeshWithGetTriangle
{
};

class NH : public NavMesh
{
  public:
    void GetTriangleVertexPositions(unsigned short, const void**, const void**, const void**);
};

// Looks up the triangle for a1 and writes pointers to the positions of its three vertices into a2, a3 and a4.
// @fnv 0x0068f160
void NH::GetTriangleVertexPositions(unsigned short ausTriangleIndex, const void** pVertex0, const void** pVertex1,
                                    const void** pVertex2)
{
    NavMeshTriangle* tri = ((::fnv_0068f160::NavMeshTriangle *)(reinterpret_cast<::NavMesh *>((reinterpret_cast<NavMeshWithGetTriangle*>(this)))->GetTriangle(ausTriangleIndex)));
    *pVertex0 = (&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((this))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((tri))->FUN_005582d0(0)))));
    *pVertex1 = (&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((this))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((tri))->FUN_005582d0(1)))));
    *pVertex2 = (&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((this))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((tri))->FUN_005582d0(2)))));
}
}  // namespace fnv_0068f160

struct FUN_00690df0_shell
{
    unsigned short pArray[1];
    void SetArrayElement(unsigned int index, unsigned short value);
};

// @fnv 0x00690df0
void FUN_00690df0_shell::SetArrayElement(unsigned int index, unsigned short value)
{
    pArray[index] = value;
}

struct FUN_00691160_shell
{
    unsigned short a[6];
    int b;
    void FUN_00691160();
};

// Sets all six elements of the array a to 0xffff and clears b to 0.
// @fnv 0x00691160
void FUN_00691160_shell::FUN_00691160()
{
    a[0] = 0xffff;
    a[1] = 0xffff;
    a[2] = 0xffff;
    a[3] = 0xffff;
    a[4] = 0xffff;
    a[5] = 0xffff;
    b = 0;
}

namespace fnv_00691b40 {
class GlobalObject_00869f00
{
  public:
};


class FUN_00691b40_shell
{
  public:
    void FUN_00691b40();
};

// @fnv 0x00691b40
void FUN_00691b40_shell::FUN_00691b40()
{
    *(void**)((char*)this + 0) = &::DAT_0106ac2c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_00691b40

namespace fnv_00691dc0 {
class GlobalObject_00869f00
{
  public:
    void FUN_00691dc0();
};

void* $SG3320;

// @fnv 0x00691dc0
void GlobalObject_00869f00::FUN_00691dc0()
{
    *reinterpret_cast<void**>(this) = &$SG3320;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_00691dc0

struct FUN_00691e70_shell
{
    void FUN_00691e70(unsigned char* param1, unsigned short param2, unsigned int param3);
};

// Stores a 16-bit value at offset 4 and a 32-bit value at offset 6 of the given buffer.
// @fnv 0x00691e70
void FUN_00691e70_shell::FUN_00691e70(unsigned char* pBuffer, unsigned short usValue, unsigned int uiValue)
{
    *reinterpret_cast<unsigned short*>(pBuffer + 4) = usValue;
    *reinterpret_cast<unsigned int*>(pBuffer + 6) = uiValue;
}

struct Unk42ffa0
{
    int dummy;
};
struct Unk42fb20
{
    void FUN_0042fb20(Unk42ffa0*, unsigned int);
};
struct NavMeshSearchLOSArray
{
};
struct FUN_0042fc00_shell
{
    void** vtable;
    void* m_pCurrent;
    unsigned int m_iKey;
    unsigned int m_uiCapacity;
    void FUN_0042fc00(void* p, unsigned int key);
};
struct S2f850
{
    void* a;
    unsigned int b;
    unsigned int c;
    virtual void v0();
    virtual void* v1(unsigned int);
    void FUN_0042fcb0(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x0042fcb0
void S2f850::FUN_0042fcb0(unsigned int requested, unsigned int savedSize)
{
    a = 0;
    b = 0;
    c = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        a = v1(requested);
        c = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::B42FA60Allocator *>(this)->FUN_0042fa60((::B42FA60Entry *)(a), savedSize);
        b = savedSize;
    }
}

class EdgeExtraInfo;
struct FUN_0068f2c0_shell
{
    unsigned short FUN_0068f2c0(int index);
};
// @fnv 0x0068f2c0
unsigned short FUN_0068f2c0_shell::FUN_0068f2c0(int index)
{
    return ((unsigned short*)((char*)this + 6))[index];
}

struct NavMesh_MatchHelper
{
};
struct In670
{
    int _f0;
    unsigned short _f4;
    short _pad6;
    int _f8;
};
struct Out670
{
    NavMesh* _f0;
    unsigned short _f4;
    short _pad6;
    int _f8;
};
struct Holder670
{
    bool MatchNavMesh(In670*, Out670*);
};
void __cdecl AddPoint(unsigned int);
struct FUN_00690fe0_shell
{
    void FUN_00690fe0(unsigned int state);
};
// @fnv 0x00690fe0
void FUN_00690fe0_shell::FUN_00690fe0(unsigned int state)
{
    ((void(*)(void*, unsigned int))AddPoint)(this + 0x28, state);
}

struct FUN_00691040_shell
{
    void GetPackedFlags(unsigned short, unsigned short*, bool*, bool*);
};
// Extracts a 4-bit value and two flag bits from the 32-bit field at offset 0xc, shifted by a1*6+16, writing them to a2, a3 and a4.
// @fnv 0x00691040
void FUN_00691040_shell::GetPackedFlags(unsigned short ausIndex, unsigned short* a2, bool* pbFlag16, bool* pbFlag32)
{
    unsigned int shift = ausIndex * 6 + 16;
    unsigned int uiBits = *(unsigned int*)((char*)this + 0xc) >> shift;
    *a2 = uiBits & 15;
    *pbFlag16 = 0 < (uiBits & 16);
    *pbFlag32 = 0 < (uiBits & 32);
}

struct Flt
{
    operator unsigned int();
};
struct S006911c0
{
    char _pad[0xA8];
    Flt _f;
    unsigned int FUN_006911c0();
};
// Returns the product of the float member converted to unsigned int with itself.
// @fnv 0x006911c0
unsigned int S006911c0::FUN_006911c0()
{
    return (unsigned int)_f * (unsigned int)_f;
}

struct FUN_006911f0_shell
{
    void FUN_006911f0(int a);
};
struct NavMeshGrid
{
    int gridWidth;
    int GetCellIndex(NiPoint3 const&);
};
struct Dummy914e0
{
    int fld0;
    void FUN_006914e0(unsigned short, int, int);
};
// Calls FUN_0069da10 with a and b plus c multiplied by fld0.
// @fnv 0x006914e0
void Dummy914e0::FUN_006914e0(unsigned short a, int b, int c)
{
    reinterpret_cast<::FUN_0069da10_C *>(this)->FUN_0069da10(a, c * fld0 + b);
}

struct EH;
struct S5460
{
    unsigned int FUN_00978bc0();
};
struct FUN_0069b310_S
{
    int _pad0;
    NiPoint3* pElementBuffer;
    unsigned int AddPoint(const NiPoint3&);
};
// @fnv 0x00691ab0
unsigned int FUN_0069b310_S::AddPoint(const NiPoint3& aPoint)
{
    unsigned int index = ((S5460*)this)->FUN_00978bc0();
    reinterpret_cast<::PlacementRange *>(this)->ConstructBounds((::NiBound *)(::EH *)((EH*)&pElementBuffer[index]), 1);
    pElementBuffer[index] = aPoint;
    return index;
}

struct Elem16
{
    int a0;
    int a1;
    int a2;
    int a3;
};
struct Arr16
{
    int _pad0;
    Elem16* buffer;
    unsigned int FUN_00691b60(Elem16*);
};
// @fnv 0x00691000
void FUN_00691000_shell::FUN_00691000(std::intptr_t arg)
{
    reinterpret_cast<::Arr16 *>((((FUN_00691000_shell*)((char*)this + 0x38))))->FUN_00691b60((::Elem16 *)(arg));
}
// @fnv 0x00691b60
unsigned int Arr16::FUN_00691b60(Elem16* apElement)
{
    unsigned int idx = ::FUN_006f31f0((::S5460 *)this);
    reinterpret_cast<::FUN_00644490_Class *>(this)->FUN_00644490((char *)(void *)(&buffer[idx]), 1);
    buffer[idx] = *apElement;
    return idx;
}

extern const char $SG3635[];

struct FUN_00691de0_shell
{
    void** vtable;
    unsigned int count;
    void* buffer;
    unsigned int reserved;
    FUN_00691de0_shell* FUN_00691de0(unsigned int count);
};

// @fnv 0x00691de0
FUN_00691de0_shell* FUN_00691de0_shell::FUN_00691de0(unsigned int count)
{
    vtable = (void**)$SG3635;
    this->count = count;
    reserved = 0;
    unsigned int byteCount = this->count * 4;
    buffer = ::FUN_00aa1070(byteCount);
    memset(buffer, 0, this->count * 4);
    return this;
}

struct Unk65
{
    void FUN_0065de30(int);
};
struct Unk6b
{
};
struct UnkParam
{
    char _pad[6];
    Unk65 f;
};
struct UnkHost
{
    char _pad[12];
    Unk6b f2;
    void FUN_00691f30(UnkParam*);
};
// Calls FUN_0065de30(0) on a1->f, then passes a1 to f2.FreeMemory.
// @fnv 0x00691f30
void UnkHost::FUN_00691f30(UnkParam* pParam)
{
    pParam->f.FUN_0065de30(0);
    reinterpret_cast<::FUN_006b8310_class *>(&(f2))->FreeMemory(pParam);
}

namespace fnv_006dc990 {
struct ArrSI
{
};
struct Node680
{
};
struct S3e60
{
};
struct Sdc990
{
    float SumNodeValues(std::intptr_t);
};
// Sums the values returned by EvaluateFalloff(a1) over all nodes obtained from FUN_006a1400 up to GetFlags() count.
// @fnv 0x006dc990
float Sdc990::SumNodeValues(std::intptr_t a1)
{
    float fSum = 0.0f;
    unsigned int cnt = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName()));
    unsigned int idx = 0;
    Node680* pNode;
    for (; idx < cnt; idx++)
    {
        pNode = ((::fnv_006dc990::Node680 *)(reinterpret_cast<::S3e60 *>((((S3e60*)this)))->FUN_006a1400(idx)));
        fSum += reinterpret_cast<::Falloff6dc *>((pNode))->EvaluateFalloff((*(const ::Pt6dc *)(a1)));
    }
    return fSum;
}
}  // namespace fnv_006dc990

struct DoorH
{
};
struct NavMeshProxy
{
    char _pad[0x24];
    DoorH* m_pOwningCell;
    TESForm* GetDoorForm();
};
// @fnv 0x0068ef70
TESForm* NavMeshProxy::GetDoorForm()
{
    if (m_pOwningCell)
    {
        if (((::TESForm *)(reinterpret_cast<::TESObjectCELL *>((m_pOwningCell))->GetParentWorldSpace())))
            return ((::TESForm *)(reinterpret_cast<::TESObjectCELL *>((m_pOwningCell))->GetParentWorldSpace()));
        else
            return (TESForm*)m_pOwningCell;
    }
    else
    {
        return 0;
    }
}

struct NavMeshInfoProxy
{
    char _pad[0x54];
    void* field54;
    bool FUN_0068f2e0(void**);
};
// If FUN_0068f320() is true, sets *p to null and returns false; otherwise stores field54 in *p and returns whether field54 is non-null.
// @fnv 0x0068f2e0
bool NavMeshInfoProxy::FUN_0068f2e0(void** apOut)
{
    if (::FUN_0068f320((const ::NavMeshInfo *)this))
    {
        *apOut = 0;
        return false;
    }
    *apOut = field54;
    return field54 != 0;
}

struct FUN_00844160_shell
{
    FUN_00844160_shell* FUN_00844160(int);
public:
    uintptr_t FUN_00844160(unsigned int);
};

FUN_00844160_shell* FUN_00844160_shell::FUN_00844160(int index)
{
    return this;
}

struct FUN_0068f6b0_shell
{
    char _pad58[0x58];
    FUN_00844160_shell* FUN_0068f6b0(unsigned short index);
};

// @fnv 0x0068f6b0
FUN_00844160_shell* FUN_0068f6b0_shell::FUN_0068f6b0(unsigned short index)
{
    return ((::FUN_00844160_shell *)(((FUN_00844160_shell*)((char*)this + 0x58))->FUN_00844160(index)));
}

struct TriHack
{
    char _pad0[6];
    unsigned short field6[3];
    int fieldC;
    void ClearFlag(int);
};
// Clears bit idx in fieldC and sets the corresponding entry of field6 to 0xffff.
// @fnv 0x00690790
void TriHack::ClearFlag(int aiIndex)
{
    fieldC &= ~(1 << aiIndex);
    field6[aiIndex] = 0xffff;
}

struct S6907D0
{
    char _pad[6];
    unsigned short arr[64];
    void SetArrayValue(int, unsigned short);
};
// Calls ClearFlag with a, then stores b into arr at index a.
// @fnv 0x006907d0
void S6907D0::SetArrayValue(int aiIndex, unsigned short ausValue)
{
    reinterpret_cast<::TriHack *>(this)->ClearFlag(aiIndex);
    arr[aiIndex] = ausValue;
}

struct Unk00690e30
{
    char _pad[6];
    unsigned short arr[3];
    unsigned int flags;
    void SetSlotValue(int, unsigned short);
};
// Sets bit a in flags and stores b into arr[a].
// @fnv 0x00690e30
void Unk00690e30::SetSlotValue(int aiIndex, unsigned short ausValue)
{
    flags |= (1 << aiIndex);
    arr[aiIndex] = ausValue;
}

struct FUN_00690e70_shell
{
    char _pad0c[0x0c];
    unsigned int field_c;
    bool IsFlag400Set();
};

// @fnv 0x00690e70
bool FUN_00690e70_shell::IsFlag400Set()
{
    return 0 < (field_c & 0x400);
}

struct S691210
{
    unsigned int m0;
    char _pad[32];
    int mBase;
    int FUN_00691210(unsigned int);
};
// @fnv 0x006911f0
void FUN_006911f0_shell::FUN_006911f0(int a)
{
    reinterpret_cast<::S691210 *>((((FUN_006911f0_shell*)((char*)this + 0xa8))))->FUN_00691210(a);
}
// Returns 0 if idx is outside m0*m0, otherwise returns idx*16 plus mBase.
// @fnv 0x00691210
int S691210::FUN_00691210(unsigned int uiIndex)
{
    if (uiIndex >= m0 * m0)
    {
        return 0;
        goto done;
    }
    return uiIndex * 16 + mBase;
done:;
}

struct FUN_00691240_shell
{
    char _pad_a8[0xa8];
    struct Inner
    {
    };
    Inner inner;
    void ForwardToInner(std::intptr_t arg);
};

// @fnv 0x00691240
void FUN_00691240_shell::ForwardToInner(std::intptr_t arg)
{
    reinterpret_cast<::NavMeshGrid *>(&(inner))->GetCellIndex((*(const ::NiPoint3 *)(arg)));
}

namespace fnv_00691590 {
class PathingAvoidanceNode;
struct FUN_006915d0_helper
{
    char _pad[36];
    unsigned short field24;
    PathingAvoidanceNode* FUN_006915d0(NiPoint3 const&, float, float);
    FUN_006915d0_helper* FUN_00691590(NiPoint3 const&, unsigned short, float, float);
};
// Calls FUN_006915d0 with the position and two floats, stores the unsigned short in field24, and returns this.
// @fnv 0x00691590
FUN_006915d0_helper* FUN_006915d0_helper::FUN_00691590(NiPoint3 const& akPosition, unsigned short ausValue, float c,
                                                       float d)
{
    reinterpret_cast<::FUN_006915d0_helper *>(this)->FUN_006915d0(akPosition, c, d);
    field24 = ausValue;
    return this;
}
}  // namespace fnv_00691590

namespace fnv_0068ed70 {
struct GlobalObject_00869f00
{
};
struct TESRecipe
{
};
struct Base5a
{
    virtual ~Base5a();
    char pad04[0x14];
};
struct FUN_0068ed70_ChildCell
{
    virtual void vf00();
};
struct EBase
{
    virtual ~EBase();
    char pad04[0x8];
};
}  // namespace fnv_0068ed70
template <> class BSSimpleArray<unsigned short, 1024>
{
  public:
    virtual ~BSSimpleArray();
    unsigned short* buffer;
    unsigned int size;
    unsigned int reserved;
};
namespace fnv_0068ed70 {
struct FUN_00691a90
{
    char pad[0x10];
    ~FUN_00691a90();
};
struct FUN_00691b40
{
    char pad[0x10];
    ~FUN_00691b40();
};
struct FUN_00691bf0
{
    char pad[0x10];
    ~FUN_00691bf0();
};
struct FUN_00691d70
{
    char pad[0x10];
    ~FUN_00691d70();
};
struct FUN_00691dc0
{
    char pad[0x10];
    ~FUN_00691dc0();
};
struct FUN_00691ea0
{
    char pad[0x10];
    ~FUN_00691ea0();
};
struct FUN_00691f90
{
    char pad[0x10];
    ~FUN_00691f90();
};
struct FUN_00691fe0
{
    char pad[0x10];
    ~FUN_00691fe0();
};
struct FUN_0069d2d0_shell
{
    char pad[0x28];
    void FUN_0069d2d0();
};
struct FUN_0068ed70_Owned
{
    virtual ~FUN_0068ed70_Owned();
};

struct FUN_0068ed70 : public Base5a, public FUN_0068ed70_ChildCell, public EBase
{
    FUN_00691a90 m28;
    FUN_00691b40 m38;
    FUN_00691bf0 m48;
    FUN_00691d70 m58;
    FUN_00691dc0 m68;
    BSSimpleArray<unsigned short, 1024> m78;
    FUN_00691ea0 m88;
    BSSimpleArray<unsigned short, 1024> m98;
    FUN_0069d2d0_shell ma8;
    FUN_00691f90 md0;
    FUN_0068ed70_Owned* pe0;
    BSSimpleArray<unsigned short, 1024> me4;
    FUN_00691fe0 mf4;
    TESRecipe* p104;
    virtual ~FUN_0068ed70();
};

// @fnv 0x0068ed70
FUN_0068ed70::~FUN_0068ed70()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&m28)))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&m38)))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&m48)))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&m58)))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&m78)))->Clear(true);
    ma8.FUN_0069d2d0();
    if (p104)
        reinterpret_cast<::FUN_005a8040_class *>((p104))->SetField54(0);
    if (pe0)
        delete pe0;
}
}  // namespace fnv_0068ed70


struct FUN_0042fb60_shell
{
    void FUN_0042fb60(char* a, char* b, unsigned int n);
};
// @fnv 0x0042fc00
void FUN_0042fc00_shell::FUN_0042fc00(void* p, unsigned int key)
{
    if (m_pCurrent)
    {
        if (key == m_uiCapacity)
        {
            m_pCurrent = ((void*(*)(void*, void*, void*))vtable[3])(this, m_pCurrent, p);
        }
        else
        {
            void* result = ((void*(*)(void*, void*))vtable[1])(this, p);
            reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(result), (char *)(m_pCurrent), key);
            ::FUN_006a8500((::DummyClass_006a8500 *)(((NavMeshSearchLOSArray*)this)));
            m_pCurrent = result;
        }
    }
    else
    {
        m_pCurrent = ((void*(*)(void*, void*))vtable[1])(this, p);
        // p carries the element count (callers pass the new size as a pointer).
        m_uiCapacity = (unsigned int)reinterpret_cast<std::uintptr_t>(p);
    }
}

// Copies n 4-byte elements from b to a, choosing forward or backward iteration based on the relative addresses of a and b.
// @fnv 0x0042fb60
void FUN_0042fb60_shell::FUN_0042fb60(char* pDst, char* pSrc, unsigned int n)
{
    if (n <= 0)
        return;
    if ((std::uintptr_t)pDst < (std::uintptr_t)pSrc)
    {
        for (unsigned int i = 0; i < n; ++i)
            std::memmove(pDst + i * 4, pSrc + i * 4, 4);
    }
    else if ((std::uintptr_t)pDst > (std::uintptr_t)pSrc)
    {
        for (int i = (int)n - 1; i >= 0; --i)
            std::memmove(pDst + i * 4, pSrc + i * 4, 4);
    }
}

namespace fnv_00690d50 {
struct GlobalObject_00869f00
{
};
struct Arr3520
{
};
struct FUN_0069d2d0_s
{
    void FUN_0069d2d0();
};
struct FUN_006b6a00_s
{
};
struct FUN_0084e3a0_s
{
};
struct TES
{
};
struct FUN_00690d50_shell
{
    void FUN_00690d50(bool abCheckout);
};
// @fnv 0x00690d50
void FUN_00690d50_shell::FUN_00690d50(bool abCheckout)
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x28))))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x38))))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x48))))->Clear(true);
    ((FUN_0069d2d0_s*)((char*)this + 0xa8))->FUN_0069d2d0();
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x78))))->Clear(true);
    reinterpret_cast<::FUN_006c6200_cls *>((((Arr3520*)((char*)this + 0xd0))))->FUN_006c6200(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x58))))->Clear(true);
    if (*(void**)((char*)this + 0x104))
    {
        reinterpret_cast<::NavigationOwner *>((((FUN_006b6a00_s*)((void *)(reinterpret_cast<::Owner45A *>((((TES*)::g_TES)))->FUN_0045af00())))))->ActivateNavigationEntry({});
    }
}
}  // namespace fnv_00690d50

namespace fnv_006910a0 {
struct ArrSI
{
};
struct GlobalObject_00869f00
{
};
struct NavMeshTriangle
{
    bool GetFlag(int);
    bool HasFlags();
};
struct NavMeshTriangleArr
{
};
struct BSSimpleArrayUS
{
};
struct FUN_006910a0_shell : NavMesh
{
    void RebuildTriangleList();
};

// Clears the array at offset 0x78, then appends each triangle index whose flag 0x20 is unset and whose HasFlags check passes.
// @fnv 0x006910a0
void FUN_006910a0_shell::RebuildTriangleList()
{
    unsigned int i;
    unsigned int isize2;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x78))))->Clear(false);
    isize2 = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x38))))->GetName()));
    for (i = 0; i < isize2; i++)
    {
        if (!((::fnv_006910a0::NavMeshTriangle *)(reinterpret_cast<::NavMesh *>((((NavMeshTriangleArr*)this)))->GetTriangle(i)))->GetFlag(0x20) &&
            ((::fnv_006910a0::NavMeshTriangle *)(reinterpret_cast<::NavMesh *>((((NavMeshTriangleArr*)this)))->GetTriangle(i)))->HasFlags())
        {
            reinterpret_cast<::FUN_00691820_arr *>((((BSSimpleArrayUS*)((char*)this + 0x78))))->Append((const unsigned short *)&(i));
        }
    }
}
}  // namespace fnv_006910a0

struct FUN_0069b030_S
{
    virtual ~FUN_0069b030_S();
    virtual void* Write(unsigned int);
    void* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void FUN_00692520(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x00692520
void FUN_0069b030_S::FUN_00692520(unsigned int requested, unsigned int savedSize)
{
    m_pBuffer = 0;
    m_uiSize = 0;
    m_uiCapacity = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        m_pBuffer = Write(requested);
        m_uiCapacity = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::FUN_006927d0_cls *>(this)->ConstructPairCells((::PairCell *)(m_pBuffer), savedSize);
        m_uiSize = savedSize;
    }
}

namespace fnv_00690e90 {
struct ArrSI
{
};

struct S006949d0
{
};

struct FUN_00691c90_shell
{
};

struct FUN_00690e10_shell
{
};

struct S6907D0
{
};

struct Unk00690e30
{
};

class NavMeshTriangle
{
  public:
    bool IsEdgeFlagSet(int);
};

class FUN_00690e90_shell
{
  public:
    void UpdateTriangleExtraInfo(unsigned short aiExtraInfo);
};

// @fnv 0x00690e90
void FUN_00690e90_shell::UpdateTriangleExtraInfo(unsigned short aiExtraInfo)
{
    unsigned int i;
    unsigned int itriSize4;
    unsigned int t;

    reinterpret_cast<::FUN_00691c90_shell *>((reinterpret_cast<FUN_00691c90_shell*>(reinterpret_cast<unsigned char*>(this) + 0x48)))->FUN_00691c90(aiExtraInfo, 1);

    itriSize4 = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->GetName()));

    for (i = 0; i < itriSize4; ++i)
    {
        if (reinterpret_cast<::FUN_00690e10_shell *>((reinterpret_cast<FUN_00690e10_shell*>(
                ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>((reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->FUN_00558dd0(i))))))->FUN_00690e10())
        {
            for (t = 0; t < 3; ++t)
            {
                if (reinterpret_cast<NavMeshTriangle*>(
                        ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>((reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->FUN_00558dd0(i))))
                        ->IsEdgeFlagSet(t))
                {
                    if (reinterpret_cast<::FUN_0068f2c0_shell *>((reinterpret_cast<NavMeshTriangle*>(
                            ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>((reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->FUN_00558dd0(i))))))->FUN_0068f2c0(t) == aiExtraInfo)
                    {
                        reinterpret_cast<::TriHack *>((reinterpret_cast<S6907D0*>(
                            ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>((reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->FUN_00558dd0(i))))))->ClearFlag(t);
                    }
                    else if (reinterpret_cast<::FUN_0068f2c0_shell *>((reinterpret_cast<NavMeshTriangle*>(
                                 ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>((reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->FUN_00558dd0(i))))))->FUN_0068f2c0(t) ==
                             ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x48)))->GetName())))
                    {
                        reinterpret_cast<::Unk00690e30 *>((reinterpret_cast<Unk00690e30*>(
                            ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>((reinterpret_cast<S006949d0*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->FUN_00558dd0(i))))))->SetSlotValue(t, aiExtraInfo);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00690e90

class StrMem
{
  public:
    StrMem();
    ~StrMem();
    char* m_str;
    unsigned short m_len;
    unsigned short m_cap;
};

struct InfoView
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void FillCellName(StrMem*);
};

class NavMeshTriangle
{
  public:
};

class NavMeshPtr
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
    void* m_ptr;
public:
    ::NavMeshPtr &operator=(const ::NavMeshPtr &);
public:
    void *FUN_0042ffa0(unsigned int);
};
// Calls FUN_0042ffa0(0) on each of the count elements of arr.
// @fnv 0x0042fb20
void Unk42fb20::FUN_0042fb20(Unk42ffa0* apItems, unsigned int count)
{
    for (int i = 0; i < count; ++i)
        reinterpret_cast<::NavMeshPtr *>(&(apItems[i]))->FUN_0042ffa0(0);
}

struct MeshView
{
};

struct VertArr
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
    NiPoint3* FUN_006a1440(unsigned int);
};
struct TriArr
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
};
struct ArrView
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
};
struct CoverArr
{
    void* vtbl;
    void* buffer;
    unsigned int size;
    unsigned int reserved;
};
struct EdgeInfoView
{
    int m_00;
    MeshView* m_04;
    unsigned short m_08;
    unsigned short m_0a;
};

extern double DAT_0106ab98;
extern const char DAT_0106ab40[];
extern const char DAT_0106aae8[];
extern const char DAT_0106aa90[];
extern const char DAT_0106aa28[];
extern const char DAT_0106a9c0[];
extern const char DAT_0106a960[];
extern const char DAT_0106a8f0[];
extern const char DAT_0106a860[];
extern const char DAT_0106a7d8[];
extern const char DAT_0106a770[];
extern const char DAT_0106a708[];
extern const char DAT_0106a6a0[];
extern const char DAT_0106a640[];
extern const char DAT_0106a5e0[];
extern const char DAT_0106a580[];
extern const char DAT_0106a520[];
extern const char DAT_0106a480[];
extern const char DAT_0106a418[];
extern const char DAT_0106a3b0[];
extern const char DAT_0106a330[];
extern const char DAT_0106a2c8[];
extern const char DAT_0106a260[];
extern const char DAT_0106a1f0[];

double __cdecl FUN_00408840(float);

struct NavMeshView
{
    char _pad24[0x24];
    int m_24;
    VertArr verts;
    TriArr tris;
    ArrView arr48;
    char _pad58[0x20];
    CoverArr cover;
    bool Validate(int);
};

class B690770Object
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiValue1;

    bool HasFlags();
};

// @fnv 0x00690770
bool B690770Object::HasFlags()
{
    return (m_uiValue1 & 0xfbe0000) > 0;
}

struct ProbeResult
{
    void* value;
    ~ProbeResult();
    void* FUN_00458b50();
};

struct ProbeArray
{
    ProbeResult FUN_00464f60(unsigned int index);
};

struct ProbeHolder
{
};

struct ProbeCell
{
};

struct ProbeGrid
{
};


struct Searcher
{
    bool CheckNeighborCells();
};

// @fnv 0x006908f0
bool Searcher::CheckNeighborCells()
{
    if (reinterpret_cast<::TESObjectCELL *>((((::ProbeGrid *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->IsCellInterior())
    {
        return true;
    }

    bool result = true;
    int cellX2 = reinterpret_cast<::TESObjectCELL *>((((::ProbeGrid *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->GetCellGridX();
    int cellY8 = reinterpret_cast<::TESObjectCELL *>((((::ProbeGrid *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->GetCellGridY();

    float xWorld = (float)(cellX2 << 12);
    ProbeHolder* kWest = ((::ProbeHolder *)(reinterpret_cast<::TESWorldSpace *>((((::ProbeCell *)(reinterpret_cast<::TESObjectCELL *>((((::ProbeGrid *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->GetParentWorldSpace()))))->GetCellAtGridPosition({}, {})));
    if (kWest != 0 && ((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(kWest)))) != 0)
    {
        for (unsigned int westIdx = 0; westIdx < reinterpret_cast<::FUN_00620b80_shell *>((((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(kWest))))))->GetReferenceFlags(); ++westIdx)
        {
            if (!((bool)(::fnv_005d4a40::FUN_005d4a40())))
            {
                result = false;
            }
        }
    }

    xWorld = (float)(cellX2 << 12) + 4096.0;
    ProbeHolder* east = ((::ProbeHolder *)(reinterpret_cast<::TESWorldSpace *>((((::ProbeCell *)(reinterpret_cast<::TESObjectCELL *>((((::ProbeGrid *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->GetParentWorldSpace()))))->GetCellAtGridPosition({}, {})));
    if (east != 0 && ((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(east)))) != 0)
    {
        for (unsigned int eastIdx = 0; eastIdx < reinterpret_cast<::FUN_00620b80_shell *>((((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(east))))))->GetReferenceFlags(); ++eastIdx)
        {
            if (!((bool)(::fnv_005d4a40::FUN_005d4a40())))
            {
                result = false;
            }
        }
    }

    float yWorld = (float)(cellY8 << 12);
    ProbeHolder* southVal = ((::ProbeHolder *)(reinterpret_cast<::TESWorldSpace *>((((::ProbeCell *)(reinterpret_cast<::TESObjectCELL *>((((::ProbeGrid *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->GetParentWorldSpace()))))->GetCellAtGridPosition({}, {})));
    if (southVal != 0 && ((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(southVal)))) != 0)
    {
        for (unsigned int southIdx = 0; southIdx < reinterpret_cast<::FUN_00620b80_shell *>((((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(southVal))))))->GetReferenceFlags(); ++southIdx)
        {
            if (!((bool)(::fnv_005d4a40::FUN_005d4a40())))
            {
                result = false;
            }
        }
    }

    yWorld = (float)(cellY8 << 12) + 4096.0;
    ProbeHolder* north2 = ((::ProbeHolder *)(reinterpret_cast<::TESWorldSpace *>((((::ProbeCell *)(reinterpret_cast<::TESObjectCELL *>((((::ProbeGrid *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->GetParentWorldSpace()))))->GetCellAtGridPosition({}, {})));
    if (north2 != 0 && ((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(north2)))) != 0)
    {
        for (unsigned int northIdx = 0; northIdx < reinterpret_cast<::FUN_00620b80_shell *>((((::ProbeArray *)(std::uintptr_t)(::FUN_0070ec90((char *)(north2))))))->GetReferenceFlags(); ++northIdx)
        {
            if (!((bool)(::fnv_005d4a40::FUN_005d4a40())))
            {
                result = false;
            }
        }
    }

    return result;
}

struct FUN_00691140_shell : public NavMeshTriangle
{
    bool FUN_00691140(int);
};

// @fnv 0x00691140
bool FUN_00691140_shell::FUN_00691140(int aFlag)
{
    return (aFlag & *(unsigned int*)((char*)this + 0xc)) != 0;
}

struct NavMeshGridX
{
    int gridWidth;
    float cellSizeX;
    float cellSizeY;
    float originX;
    float originY;
    void GetCellCoords(NiPoint3 const& point, unsigned int& outRow, unsigned int& outCol);
};
// Converts a point to grid coordinates via GetCellCoords and returns the linear cell index x * gridWidth + y.
// @fnv 0x00691260
int NavMeshGrid::GetCellIndex(NiPoint3 const& aPoint)
{
    unsigned int x = 0;
    {
        unsigned int y = 0;
        reinterpret_cast<::NavMeshGridX *>(this)->GetCellCoords(aPoint, x, y);
        return x * gridWidth + y;
    }
}


// @fnv 0x006912a0
void NavMeshGridX::GetCellCoords(NiPoint3 const& point, unsigned int& outRow, unsigned int& outCol)
{
    float dxH = point.x - this->originX;
    float dY0 = point.y - this->originY;
    float gx1 = dxH / this->cellSizeX;
    float gY = dY0 / this->cellSizeY;

    int nCol = (int)FUN_00406ce0(gx1);
    ClampInt(&nCol, 0, this->gridWidth - 1);
    outCol = nCol;

    int row = (int)FUN_00406ce0(gY);
    ClampInt(&row, 0, this->gridWidth - 1);
    outRow = row;
}

struct NavMeshTriangle;
struct NiPoint3;
struct TriLike
{
};
struct TriArrStub
{
    void* vt;
    void* buf;
    unsigned int sz;
    unsigned int cap;
};
struct GridStub
{
    int gridWidth;
    bool EmptyStructPlaceholder(unsigned short tri, int y, int x);
};
struct OutArr
{
};
struct NavMeshStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    TriArrStub tris;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    GridStub grid;
    unsigned int CollectTriangleCells(unsigned short tri, OutArr& out);
};
// @fnv 0x00691350
unsigned int NavMeshStub::CollectTriangleCells(unsigned short tri, OutArr& out)
{
    TriLike* pTri6 = ((::TriLike *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(tris))->FUN_00558dd0(tri)));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(out))->Clear(false);
    unsigned int maxX2 = 0;
    unsigned int minX7 = 0xFFFFFFFF;
    unsigned int maxY8 = 0;
    unsigned int minY7 = 0xFFFFFFFF;
    for (unsigned int i = 0; i < 3; i++)
    {
        const NiPoint3& pt2 = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pTri6))->FUN_005582d0(i))));
        unsigned int x9 = 0;
        unsigned int y6 = 0;
        reinterpret_cast<::NavMeshGridX *>(&(grid))->GetCellCoords(pt2, x9, y6);
        maxX2 = ::FUN_00403940(maxX2, x9);
        minX7 = ::FUN_0042f5a0(minX7, x9);
        maxY8 = ::FUN_00403940(maxY8, y6);
        minY7 = ::FUN_0042f5a0(minY7, y6);
    }
    for (unsigned int xi2 = minX7; xi2 < maxX2 + 1; xi2++)
    {
        for (unsigned int yi = minY7; yi < maxY8 + 1; yi++)
        {
            if (grid.EmptyStructPlaceholder(tri, yi, xi2))
            {
                int cell = ::FUN_00559450((int *)&(grid)) * xi2 + yi;
                reinterpret_cast<::FUN_00438690 *>(&(out))->FUN_007cb2e0((unsigned int *)&(cell));
            }
        }
    }
    return ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(out))->GetName()));
}

struct AvoidNodeDescription
{
    NiPoint3 point1, point2;
    float radius, cost;
    unsigned int type, flags;
    void FUN_00691590(void* source, unsigned short triangle, float radius, float cost);
};
struct EdgeInfoOps : EdgeExtraInfo
{
};
struct StaticAvoidOps : BSSimpleArray<NavMeshStaticAvoidNode, 1024>
{
};
struct NavMeshOps : NavMesh
{
    void AddAvoidNode(void* source, unsigned short triangle, float radius, float cost);
};
struct FUN_00691570_shell : public NavMeshTriangle
{
    void FUN_00691570(int);
};
// @fnv 0x00691510
void NavMeshOps::AddAvoidNode(void* source, unsigned short triangle, float radius, float cost)
{
    AvoidNodeDescription avoidNode;
    avoidNode.FUN_00691590(source, triangle, radius, cost);
    reinterpret_cast<::FUN_00691570_shell *>((static_cast<EdgeInfoOps*>(((::EdgeExtraInfo *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(Triangles))->FUN_00558dd0(triangle))))))->FUN_00691570({});
    reinterpret_cast<::FUN_00692000_class *>((static_cast<StaticAvoidOps*>(&m_kStaticAvoidNodes)))->AddData((::FUN_00692000_data *)(::AvoidNodeDescription *)(&avoidNode));
}

// @fnv 0x00691570
void FUN_00691570_shell::FUN_00691570(int aFlag)
{
    *(unsigned int*)((char*)this + 0xc) |= aFlag;
}

struct NHc_b9119;
struct NHc2_b9119
{
};
struct NHc_b9119
{
};

struct FUN_0068efd0_cls
{
    EdgeT* FUN_0068efd0(EdgeT* out, unsigned short tri, int idx);
};
// Fetches the edge indices for a triangle via FUN_0068efd0 and returns pointers to the two edge vertices from FUN_0068f0a0.
// @fnv 0x0068f040
EdgeV FloatValueProvider::FUN_0068f040(unsigned short ausTriIndex, int aiEdgeIndex)
{
    EdgeT edge;
    EdgeV ev;
    reinterpret_cast<::FUN_0068efd0_cls *>((((NH*)this)))->FUN_0068efd0(&edge, ausTriIndex, aiEdgeIndex);
    ev.a = &(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((((NH*)this)))->FUN_0068f0a0(edge.a)));
    ev.b = &(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((((NH*)this)))->FUN_0068f0a0(edge.b)));
    return ev;
}

// @fnv 0x0068efd0
EdgeT* FUN_0068efd0_cls::FUN_0068efd0(EdgeT* out, unsigned short tri, int idx)
{
    EdgeT r;
    r.a = reinterpret_cast<::FUN_005582d0_shell *>((((::NHc_b9119 *)(reinterpret_cast<::NavMesh *>((((NHc2_b9119*)this)))->GetTriangle(tri)))))->FUN_005582d0({});
    int m2 = (idx + 1) % 3;
    r.b = reinterpret_cast<::FUN_005582d0_shell *>((((::NHc_b9119 *)(reinterpret_cast<::NavMesh *>((((NHc2_b9119*)this)))->GetTriangle(tri)))))->FUN_005582d0({});
    *out = r;
    return out;
}

struct FUN_0068f1d0_shell : public NavMeshTriangle
{
    bool IsEdgeFlagSet(int);
};
// @fnv 0x0068f230
EdgeExtraInfo* FUN_0068f230_shell::FUN_0068f230(unsigned short ausTriangleIndex, int aiEdgeIndex)
{
    if (reinterpret_cast<::FUN_0068f1d0_shell *>((((::EdgeExtraInfo *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(Triangles))->FUN_00558dd0(ausTriangleIndex)))))->IsEdgeFlagSet({}) &&
        reinterpret_cast<::FUN_0068f2c0_shell *>((((::EdgeExtraInfo *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(Triangles))->FUN_00558dd0(ausTriangleIndex)))))->FUN_0068f2c0({}) != 0xFFFF)
        return m_kEdgeExtraInfo.FUN_006a1440(reinterpret_cast<::FUN_0068f2c0_shell *>((((::EdgeExtraInfo *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(Triangles))->FUN_00558dd0(ausTriangleIndex)))))->FUN_0068f2c0({}));
    else
        return 0;
}

// Returns true if the bit at aiEdgeIndex is set in the 32-bit flags word at offset 0xc of this NavMeshTriangle.
// @fnv 0x0068f1d0
bool FUN_0068f1d0_shell::IsEdgeFlagSet(int aiEdgeIndex)
{
    return ((1 << aiEdgeIndex) & *(unsigned int*)((char*)this + 0xc)) != 0;
}

struct FUN_0068f200_shell : public NavMeshTriangle
{
    bool FUN_0068f200(int);
};
// @fnv 0x0068f6d0
bool NavMeshView::Validate(int a0)
{
    bool hadError = false;
    StrMem p;
    ((::InfoView *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))->FillCellName(&p);

    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(verts))->GetName())); i++)
    {
        if (std::isfinite(verts.FUN_006a1440(i)->x) == 0 || FUN_00408840(verts.FUN_006a1440(i)->x) > DAT_0106ab98)
        {
            ::FUN_005b5e40();
            hadError = true;
            break;
        }
        if (std::isfinite(verts.FUN_006a1440(i)->y) == 0 || FUN_00408840(verts.FUN_006a1440(i)->y) > DAT_0106ab98)
        {
            ::FUN_005b5e40();
            hadError = true;
            break;
        }
        if (std::isfinite(verts.FUN_006a1440(i)->z) == 0 || FUN_00408840(verts.FUN_006a1440(i)->z) > DAT_0106ab98)
        {
            ::FUN_005b5e40();
            hadError = true;
            break;
        }
    }

    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())) >= 0x7d0)
    {
        ::FUN_005b5e40();
    }

    for (unsigned int j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())); j++)
    {
        NavMeshTriangle* triA = ((::NavMeshTriangle *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(tris))->FUN_00558dd0(j)));
        for (long k = 0; k < 3; k++)
        {
            if (!reinterpret_cast<::FUN_0068f1d0_shell *>((triA))->IsEdgeFlagSet(k) && ((unsigned char)(reinterpret_cast<::FUN_0068f200_shell *>((triA))->FUN_0068f200(k))) != 0 && reinterpret_cast<::FUN_0068f2c0_shell *>((triA))->FUN_0068f2c0(k) >= ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())))
            {
                ::FUN_005b5e40();
                reinterpret_cast<::S6907D0 *>((triA))->SetArrayValue(k, 0xffff);
                hadError = true;
            }
        }
        NiPoint3 normal = reinterpret_cast<::NavMesh *>(this)->GetPlaneNormal((unsigned short)j);
        if (normal.z < 0.0f)
        {
            ::FUN_005b5e40();
            reinterpret_cast<::SwapMesh *>(this)->SwapTriangleEdges((unsigned short)j);
            hadError = true;
        }
    }

    for (unsigned int b = 0; b < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())); b++)
    {
        NavMeshTriangle* sh = reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)b);
        for (long tri7 = 0; tri7 < 3; tri7++)
        {
            if (reinterpret_cast<::FUN_0068f1d0_shell *>((sh))->IsEdgeFlagSet(tri7))
            {
                if (reinterpret_cast<::FUN_0068f2c0_shell *>((sh))->FUN_0068f2c0(tri7) >= ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr48))->GetName())))
                {
                    ::FUN_005b5e40();
                    reinterpret_cast<::TriHack *>((sh))->ClearFlag(tri7);
                    hadError = true;
                    continue;
                }
                EdgeInfoView* pRetrievedObject = ((::EdgeInfoView *)(reinterpret_cast<::FUN_0068f230_shell *>(this)->FUN_0068f230((unsigned short)b, tri7)));
                if (pRetrievedObject->m_04 == 0)
                {
                    reinterpret_cast<::fnv_00690e90::FUN_00690e90_shell *>(this)->UpdateTriangleExtraInfo(reinterpret_cast<::FUN_0068f2c0_shell *>((sh))->FUN_0068f2c0(tri7));
                    hadError = true;
                    continue;
                }
                else if (pRetrievedObject->m_08 == 0xffff)
                {
                    reinterpret_cast<::fnv_00690e90::FUN_00690e90_shell *>(this)->UpdateTriangleExtraInfo(reinterpret_cast<::FUN_0068f2c0_shell *>((sh))->FUN_0068f2c0(tri7));
                    hadError = true;
                    continue;
                }
                else
                {
                    NavMeshPtr pTri;
                    if (reinterpret_cast<::NavMeshInfo *>((pRetrievedObject->m_04))->AcquireNavMesh((*(::NavMeshPtr *)(&pTri))))
                    {
                        if (pRetrievedObject->m_08 >= ::FUN_00558200((char *)(((MeshView*)((char *)(::FUN_00559450((int *)&(pTri))))))))
                        {
                            ::FUN_005b5e40();
                            reinterpret_cast<::fnv_00690e90::FUN_00690e90_shell *>(this)->UpdateTriangleExtraInfo(reinterpret_cast<::FUN_0068f2c0_shell *>((sh))->FUN_0068f2c0(tri7));
                            hadError = true;
                            continue;
                        }
                    }
                    if (((std::uintptr_t)(reinterpret_cast<::TESObjectCELL *>((((::InfoView *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->GetParentWorldSpace())) != ((std::uintptr_t)(::FUN_00690800((const ::NavMeshInfo *)(pRetrievedObject->m_04)))))
                    {
                        ::FUN_005b5e40();
                        reinterpret_cast<::fnv_00690e90::FUN_00690e90_shell *>(this)->UpdateTriangleExtraInfo(reinterpret_cast<::FUN_0068f2c0_shell *>((sh))->FUN_0068f2c0(tri7));
                        hadError = true;
                        continue;
                    }
                }
            }
        }
    }

    for (unsigned int t4 = 0; t4 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())); t4++)
    {
        NavMeshTriangle* tri4 = reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)t4);
        if (reinterpret_cast<::FUN_005582d0_shell *>((tri4))->FUN_005582d0(0) == reinterpret_cast<::FUN_005582d0_shell *>((tri4))->FUN_005582d0(1))
        {
            ::FUN_005b5e40();
            hadError = true;
        }
        if (reinterpret_cast<::FUN_005582d0_shell *>((tri4))->FUN_005582d0(0) == reinterpret_cast<::FUN_005582d0_shell *>((tri4))->FUN_005582d0(2))
        {
            ::FUN_005b5e40();
            hadError = true;
        }
        if (reinterpret_cast<::FUN_005582d0_shell *>((tri4))->FUN_005582d0(1) == reinterpret_cast<::FUN_005582d0_shell *>((tri4))->FUN_005582d0(2))
        {
            ::FUN_005b5e40();
            hadError = true;
        }
    }

    for (unsigned int e7 = 0; e7 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())); e7++)
    {
        NavMeshTriangle* tri5 = reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)e7);
        if (reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(0) == reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(1) && reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(0) != 0xffff &&
            reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(0) == reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(1))
        {
            ::FUN_005b5e40();
            hadError = true;
        }
        if (reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(0) == reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(2) && reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(0) != 0xffff &&
            reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(0) == reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(2))
        {
            ::FUN_005b5e40();
            hadError = true;
        }
        if (reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(1) == reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(2) && reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(1) != 0xffff &&
            reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(1) == reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(2))
        {
            ::FUN_005b5e40();
            hadError = true;
        }
    }

    for (unsigned int t6 = 0; t6 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())); t6++)
    {
        NavMeshTriangle* tri6 = reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)t6);
        for (long e6 = 0; 3 > e6; e6++)
        {
            int edge = e6;
            unsigned int e = edge + 1;
            if (e == 3)
                e = 0;
            unsigned short vA = reinterpret_cast<::FUN_005582d0_shell *>((tri6))->FUN_005582d0(edge);
            unsigned short pForm = reinterpret_cast<::FUN_005582d0_shell *>((tri6))->FUN_005582d0(e);
            for (int tri3 = 0; tri3 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())); tri3++)
            {
                if (tri3 == t6)
                    continue;
                NavMeshTriangle* tri = reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)tri3);
                for (int t5 = 0; t5 < 3; t5++)
                {
                    if (reinterpret_cast<::FUN_005582d0_shell *>((tri))->FUN_005582d0(t5) != pForm)
                        continue;
                    unsigned short tIn = (unsigned short)(t5 + 1);
                    if (tIn == 3)
                        tIn = 0;
                    for (int e8 = 0; 3 > e8; e8++)
                    {
                        if (e8 == t5)
                            continue;
                        if (reinterpret_cast<::FUN_005582d0_shell *>((tri))->FUN_005582d0(e8) != vA)
                            continue;
                        if (e8 != tIn)
                        {
                            ::FUN_005b5e40();
                            hadError = true;
                        }
                        if (!reinterpret_cast<::FUN_0068f1d0_shell *>((tri6))->IsEdgeFlagSet(e6))
                        {
                            if (reinterpret_cast<::FUN_0068f2c0_shell *>((tri6))->FUN_0068f2c0(e6) != 0xffff)
                            {
                                if (reinterpret_cast<::FUN_0068f1d0_shell *>((tri))->IsEdgeFlagSet(t5))
                                {
                                    ::FUN_005b5e40();
                                    hadError = true;
                                }
                                if (reinterpret_cast<::FUN_0068f2c0_shell *>((tri6))->FUN_0068f2c0(e6) != tri3)
                                {
                                    ::FUN_005b5e40();
                                    hadError = true;
                                }
                                if (reinterpret_cast<::FUN_0068f2c0_shell *>((tri))->FUN_0068f2c0(t5) != t6)
                                {
                                    ::FUN_005b5e40();
                                    hadError = true;
                                }
                            }
                        }
                        else
                        {
                            if (!reinterpret_cast<::FUN_0068f1d0_shell *>((tri))->IsEdgeFlagSet(t5))
                            {
                                ::FUN_005b5e40();
                                hadError = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for (unsigned int e10 = 0; e10 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(tris))->GetName())); e10++)
    {
        NavMeshTriangle* tri8 = reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)e10);
        for (int e9 = 0; 3 > e9; e9++)
        {
            if (!reinterpret_cast<::FUN_0068f1d0_shell *>((tri8))->IsEdgeFlagSet(e9) && reinterpret_cast<::FUN_0068f2c0_shell *>((tri8))->FUN_0068f2c0(e9) != 0xffff)
            {
                NavMeshTriangle* h = reinterpret_cast<::NavMesh *>(this)->GetTriangle(reinterpret_cast<::FUN_0068f2c0_shell *>((tri8))->FUN_0068f2c0(e9));
                bool s = false;
                int a;
                for (a = 0; 3 > a; a++)
                {
                    if (!reinterpret_cast<::FUN_0068f1d0_shell *>((h))->IsEdgeFlagSet(a) && reinterpret_cast<::FUN_0068f2c0_shell *>((h))->FUN_0068f2c0(a) != 0xffff && reinterpret_cast<::FUN_0068f2c0_shell *>((h))->FUN_0068f2c0(a) == e10)
                    {
                        s = true;
                        break;
                    }
                }
                if (!s)
                {
                    ::FUN_005b5e40();
                    hadError = true;
                }
                if (a < 3)
                {
                    int bIdx = e9;
                    long c = e9 + 1;
                    if (c == 3)
                        c = 0;
                    int c2 = a;
                    int q = a + 1;
                    if (q == 3)
                        q = 0;
                    if (reinterpret_cast<::FUN_005582d0_shell *>((tri8))->FUN_005582d0(bIdx) != reinterpret_cast<::FUN_005582d0_shell *>((h))->FUN_005582d0(q) || reinterpret_cast<::FUN_005582d0_shell *>((tri8))->FUN_005582d0(c) != reinterpret_cast<::FUN_005582d0_shell *>((h))->FUN_005582d0(c2))
                    {
                        ::FUN_005b5e40();
                        hadError = true;
                    }
                }
            }
        }
    }

    for (unsigned int ci = 0; ci < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(cover))->GetName())); ci++)
    {
        unsigned short triC = reinterpret_cast<::FUN_005eeda0_this *>(&(cover))->GetBufferEntry(ci);
        NavMeshTriangle* coverTri = reinterpret_cast<::NavMesh *>(this)->GetTriangle(triC);
        if (coverTri == 0)
        {
            ::FUN_005b5e40();
            hadError = true;
        }
        else if (!reinterpret_cast<::B690770Object *>((coverTri))->HasFlags())
        {
            ::FUN_005b5e40();
            hadError = true;
        }
    }

    reinterpret_cast<::Searcher *>(this)->CheckNeighborCells();
    return !hadError;
}

// Returns true if the triangle's edge entry at aiEdgeIndex is not 0xFFFF.
// @fnv 0x0068f200
bool FUN_0068f200_shell::FUN_0068f200(int aiEdgeIndex)
{
    return ((unsigned short*)((char*)this + 6))[aiEdgeIndex] != 0xFFFF;
}

class D2d0Elem
{
  public:
    virtual ~D2d0Elem();
    int m_04;
};
struct D2d0Cls
{
    int m_00;
    int m_04, m_08;
    float m_0c;
    int m_10, m_14, m_18, m_1c, m_20;
    D2d0Elem* m_24;
    void FUN_0069d2d0();
};
// Deletes the m_24 array and clears it, resets m_00 to 0 and sets m_0c to DAT_01016970.
// @fnv 0x0069d2d0
void D2d0Cls::FUN_0069d2d0()
{
    if (m_24)
    {
        delete[] m_24;
        m_24 = 0;
    }
    m_00 = 0;
    m_0c = DAT_01016970;
}

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer();
    NiPointer<T>& operator=(const NiPointer<T>& ptr);
};
class NavMeshEdgeQuery
{
  public:
    bool FUN_0068f3b0(unsigned short usTri, int m_iEdgeNumber, NiPointer<NavMesh>& pFoundNavMesh, std::intptr_t a4, std::intptr_t a5);
};
struct ProxyX
{
};

struct EInfoX
{
    int type;
    ProxyX* portal;
    unsigned short tri;
    unsigned short pad;
};

struct TriX
{
};

struct MeshX
{
    bool FindAdjacentEdge(unsigned short, int, MeshX**, unsigned short*, int*);
};
// Calls the match helper with the input's _f4 and _f8, writing the resulting NavMesh pointer, _f4 and _f8 into the output.
// @fnv 0x0068f670
bool Holder670::MatchNavMesh(In670* pIn, Out670* pOut)
{
    return reinterpret_cast<::MeshX *>((((NavMesh_MatchHelper*)this)))->FindAdjacentEdge(pIn->_f4, pIn->_f8, (::MeshX **)&(pOut->_f0), (unsigned short *)&(pOut->_f4), (int *)&(pOut->_f8));
}
// @fnv 0x0068f3b0
bool NavMeshEdgeQuery::FUN_0068f3b0(unsigned short usTri, int m_iEdgeNumber, NiPointer<NavMesh>& apMeshOut, std::intptr_t a4,
                                    std::intptr_t a5)
{
    NavMesh* pMesh = 0;
    if (reinterpret_cast<::MeshX *>(this)->FindAdjacentEdge(usTri, m_iEdgeNumber, (::MeshX **)(::NavMesh **)(&pMesh), (unsigned short *)(a4), (int *)(a5)))
    {
        reinterpret_cast<::NavMeshPtr *>((void *)&(const ::NiPointer< ::NavMesh> &)(apMeshOut))->operator=((const ::NavMeshPtr &)((const ::NiPointer< ::NavMesh> &)(MakeNavMeshPointer(pMesh))));
        return true;
    }
    else
    {
        return false;
    }
}

// Finds the mesh, triangle and edge adjacent to aTri/aEdge, following a portal or the triangle's neighbour, and writes them to the out parameters.
// @fnv 0x0068f460
bool MeshX::FindAdjacentEdge(unsigned short aTri, int aEdge, MeshX** appOutMesh, unsigned short* apTri, int* apEdge)
{
    if (aTri >= ::FUN_00558200((char *)(this)))
        return false;
    TriX* pTri = ((::TriX *)(reinterpret_cast<::NavMesh *>((this))->GetTriangle(aTri)));
    if (((unsigned char)(reinterpret_cast<::FUN_0068f200_shell *>((pTri))->FUN_0068f200(aEdge))))
    {
        if (reinterpret_cast<::FUN_0068f1d0_shell *>((pTri))->IsEdgeFlagSet(aEdge))
        {
            EInfoX* pEdgeInfo = ((::EInfoX *)(reinterpret_cast<::FUN_0068f230_shell *>((this))->FUN_0068f230(aTri, aEdge)));
            if (!pEdgeInfo->portal)
            {
                return false;
            }
            else
            {
                MeshX* pMesh;
                if (reinterpret_cast<::NavMeshInfoProxy *>((pEdgeInfo->portal))->FUN_0068f2e0((void**)&pMesh))
                {
                    unsigned short usPortalTri = pEdgeInfo->tri;
                    if (usPortalTri >= ::FUN_00558200((char *)(pMesh)))
                        return false;
                    TriX* pAdjTriangle = ((::TriX *)(reinterpret_cast<::NavMesh *>((pMesh))->GetTriangle(usPortalTri)));
                    int q;
                    for (q = 0; q < 3; q++)
                    {
                        if (reinterpret_cast<::FUN_0068f1d0_shell *>((pAdjTriangle))->IsEdgeFlagSet(q))
                        {
                            EInfoX* pE = ((::EInfoX *)(reinterpret_cast<::FUN_0068f230_shell *>((pMesh))->FUN_0068f230(usPortalTri, q)));
                            if (!pE)
                                continue;
                            if (pE->portal == ((::ProxyX *)(reinterpret_cast<::FUN_0068efb0_shell *>((this))->FUN_0068efb0())) && pE->tri == aTri)
                                break;
                        }
                    }
                    if (q == 3)
                    {
                        return false;
                    }
                    else
                    {
                        *appOutMesh = pMesh;
                        *apTri = usPortalTri;
                        *apEdge = q;
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            *appOutMesh = this;
            *apTri = reinterpret_cast<::FUN_0068f2c0_shell *>((pTri))->FUN_0068f2c0(aEdge);
            TriX* pAdjTriangle = ((::TriX *)(reinterpret_cast<::NavMesh *>((this))->GetTriangle(*apTri)));
            int r;
            for (r = 0; r < 3; r++)
            {
                if (!reinterpret_cast<::FUN_0068f1d0_shell *>((pAdjTriangle))->IsEdgeFlagSet(r) && reinterpret_cast<::FUN_0068f2c0_shell *>((pAdjTriangle))->FUN_0068f2c0(r) == aTri)
                    break;
            }
            if (r >= 3)
                return false;
            *apEdge = r;
            return true;
        }
    }
    else
    {
        return false;
    }
}

class NavMesh68F3
{
  public:
};

struct NavMeshEdgeRef68F3
{
    int unk00;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int m_iEdgeNumber;
};

struct NavMeshEdgeOut68F3
{
    const NavMeshInfo* m_pNavigationMesh;
    unsigned short m_usTriangleID;
    unsigned short unk06;
    int m_iEdgeNumber;
};

class NavMeshPortalMgr68F3
{
  public:
    bool FUN_0068f340(const NavMeshEdgeRef68F3* pkRef, NavMeshEdgeOut68F3* pkOut);
};

// On success, stores the adjacent mesh's navigation info, triangle ID, and edge number in pkOut.
// @fnv 0x0068f340
bool NavMeshPortalMgr68F3::FUN_0068f340(const NavMeshEdgeRef68F3* pkRef, NavMeshEdgeOut68F3* pkOut)
{
    NavMesh68F3* m_pLocationNavMesh = 0;
    int edgeIndex = -1;
    unsigned short triangle;
    if (reinterpret_cast<::MeshX *>(this)->FindAdjacentEdge(pkRef->m_usTriangleID, pkRef->m_iEdgeNumber, (::MeshX **)(::NavMesh68F3 **)(&m_pLocationNavMesh), &triangle, &edgeIndex))
    {
        pkOut->m_pNavigationMesh = reinterpret_cast<::FUN_0068efb0_shell *>((m_pLocationNavMesh))->FUN_0068efb0();
        pkOut->m_usTriangleID = triangle;
        pkOut->m_iEdgeNumber = edgeIndex;
        return true;
    }
    else
    {
        return false;
    }
}

class FUN_00691f00
{
  public:
    virtual ~FUN_00691f00();

};

class FUN_00691ea0 : public FUN_00691f00
{
  public:
    virtual ~FUN_00691ea0();
};

// @fnv 0x00691ea0
FUN_00691ea0::~FUN_00691ea0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

#include "generated/data/fallout_shared/pathfinding/navmesh.inc"
