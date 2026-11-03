// fallout_shared/pathfinding/navmesh_util.cpp: NavMesh, std, CircularArc, ASC and more (100 functions)

#include <new>
#include <cmath>
#include "fnv/decl/AdjBuilder.h"
#include "fnv/decl/B120Array.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BuildProcess.h"
#include "fnv/decl/Builder.h"
#include "fnv/decl/D2d0Cls.h"
#include "fnv/decl/EdgeUpdater120.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0049c250_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_004a3d40_class.h"
#include "fnv/decl/FUN_004a3d80_Class.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00519270_shell.h"
#include "fnv/decl/FUN_005582d0_shell.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_005a8040_class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_0068f0a0_shell.h"
#include "fnv/decl/FUN_0068f1d0_shell.h"
#include "fnv/decl/FUN_0068f200_shell.h"
#include "fnv/decl/FUN_0068f230_shell.h"
#include "fnv/decl/FUN_0068f2c0_shell.h"
#include "fnv/decl/FUN_00690df0_shell.h"
#include "fnv/decl/FUN_00690e10_shell.h"
#include "fnv/decl/FUN_00691040_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_00691570_shell.h"
#include "fnv/decl/FUN_00691820_arr.h"
#include "fnv/decl/FUN_00692290_class.h"
#include "fnv/decl/FUN_006927d0_cls.h"
#include "fnv/decl/FUN_00693d30_shell.h"
#include "fnv/decl/FUN_00694890_shell.h"
#include "fnv/decl/FUN_0069add0_class.h"
#include "fnv/decl/FUN_0069d790_class.h"
#include "fnv/decl/FUN_0069d800_class.h"
#include "fnv/decl/FUN_0069dec0_class.h"
#include "fnv/decl/FUN_006a0840_shell.h"
#include "fnv/decl/FUN_006ad2f0_cls.h"
#include "fnv/decl/FUN_006bc940_class.h"
#include "fnv/decl/FUN_006bde50.h"
#include "fnv/decl/FUN_006be660_class.h"
#include "fnv/decl/FUN_006be770_class.h"
#include "fnv/decl/FUN_006bec20_Class.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_006de490_cls.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Graph006bdf50.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/Host120.h"
#include "fnv/decl/HostB60.h"
#include "fnv/decl/Map00694c50.h"
#include "fnv/decl/Map00694d30.h"
#include "fnv/decl/NLLocation.h"
#include "fnv/decl/NavInfo.h"
#include "fnv/decl/NavMeshGen_6be830.h"
#include "fnv/decl/NavMeshGridX.h"
#include "fnv/decl/NavMeshInfo.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/Pathing.h"
#include "fnv/decl/PlacementRange.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Processor74.h"
#include "fnv/decl/S006beb80.h"
#include "fnv/decl/S2f850.h"
#include "fnv/decl/S5460.h"
#include "fnv/decl/S6907D0.h"
#include "fnv/decl/S6bdcb0Owner.h"
#include "fnv/decl/SetupPathingLocation.h"
#include "fnv/decl/StandInSearch.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk00690e30.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaitableObject.h"
#include "fnv/decl/fnv_00547250__FUN_00547250_shell.h"
#include "fnv/decl/fnv_0068f0c0__FUN_0068f0c0_shell.h"
#include "fnv/decl/fnv_00690e90__FUN_00690e90_shell.h"
#include "fnv/decl/fnv_006949d0__S5460.h"
#include "fnv/decl/fnv_006bc8e0__Host006bc8e0.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_00990a60__FUN_00990a60_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_006ba000.h"
#include "fnv/symbols_006c3000.h"
#include "fnv/symbols_006d9000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01025000.h"
#include "fnv/symbols_0106a000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_011de000.h"
#include "navmesh_util_decls.h"

// @fnv 0x006971e0
NiPoint3 NavMesh::GetPlaneNormal(unsigned short triangleIndex)
{
    NavMeshTriangle* triangle = GetTriangle(triangleIndex);
    struct LineSegment
    {
        NiPoint3 first, second;
    } edges = {(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triangle))->FUN_005582d0(1)))) - (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triangle))->FUN_005582d0(0)))),
               (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triangle))->FUN_005582d0(2)))) - (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triangle))->FUN_005582d0(0))))};
    return edges.first.CrossProduct(edges.second);
}

// Wraps a NavMesh pointer in a NiPointer<NavMesh> and returns it.
// @fnv 0x00464fc0
NiPointer<NavMesh> MakeNavMeshPointer(NavMesh* mesh)
{
    return NiPointer<NavMesh>(mesh);
}

// Scans the closed-door info list for an entry whose triangle index matches triangleIndex and returns a pointer to it, or null if none matches.
// @fnv 0x00699af0
NavMeshClosedDoorInfo* NavMesh::GetClosedDoorInfo(unsigned short triangleIndex)
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kClosedDoorInfo))->GetName())); i++)
    {
        if (m_kClosedDoorInfo.GetElement(i).m_usTriangleID == triangleIndex)
            return &m_kClosedDoorInfo.GetElement(i);
    }
    return 0;
}

// Computes the arc length from the angle between Start and End, wrapping negative angles by 2*pi and inverting when Dir is nonzero, scaled by radius.
// @fnv 0x006a07a0
float CircularArc::GetLength(float radius)
{
    SineCosine difference = End - Start;
    float angle = reinterpret_cast<::FUN_006a0840_shell *>((void *)&(difference))->FUN_006a0840();
    if (Dir == 0)
    {
        if (angle < 0.0)
            return (angle + 6.2831854820251465) * radius;
        else
            return angle * radius;
    }
    else
    {
        if (angle < 0.0)
            return -angle * radius;
        else
            return (6.2831854820251465 - angle) * radius;
    }
}

// Gets the triangle's three vertices, converts them, and tests the point against them to compute height within the above/below range.
// @fnv 0x00697730
bool NavMesh::FindHeightOnTriangle(unsigned short triangleIndex, const NiPoint3& point, float& height, float above,
                                   float below)
{
    NiPoint3 first, second, third;
    NavMeshTriangle* pNavTriangle;
    pNavTriangle = GetTriangle(triangleIndex);
    first = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pNavTriangle))->FUN_005582d0(0))));
    second = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pNavTriangle))->FUN_005582d0(1))));
    third = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pNavTriangle))->FUN_005582d0(2))));
    return FUN_006b9cf0(first, second, third, point, height, above, below);
}


// @fnv 0x004a3d20
void* FUN_004a3d20(void* pThis)
{
    reinterpret_cast<::FUN_004a3d40_class *>((pThis))->FUN_004a3d40();
    reinterpret_cast<::FUN_004a3d80_Class *>((pThis))->FUN_004a3d80();
    return pThis;
}

struct FUN_005eeda0_this
{
    int pad0;
    unsigned short* pBuffer;
    unsigned short& GetBufferEntry(unsigned int aiIndex);
};

// @fnv 0x005eeda0
unsigned short& FUN_005eeda0_this::GetBufferEntry(unsigned int aiIndex)
{
    return pBuffer[aiIndex];
}


struct Dummy0042f800
{
};

// @fnv 0x006917d0
void* FUN_006917d0(int** pThis)
{
    *pThis = &::DAT_0106abe4;
    reinterpret_cast<::FUN_00692290_class *>((reinterpret_cast<Dummy0042f800*>(pThis)))->FUN_00692290(0, 0);
    return pThis;
}

struct FUN_006969e0_shell : public NavMesh
{
    bool FUN_006969e0(NiPoint3*, NiPoint3*);
};

struct DummyA8
{
};

struct V3
{
    float x, y, z;
};
struct FUN_00698580_S
{
    V3 a;
    V3 b;
    FUN_00698580_S* FUN_00698580(const V3* p, const V3* q);
};
// @fnv 0x00698580
FUN_00698580_S* FUN_00698580_S::FUN_00698580(const V3* p, const V3* q)
{
    a = *p;
    b = *q;
    return this;
}

void compiler_vector_constructor_iterator(void*, unsigned int, int, void*);
void FUN_006d5320();

// @fnv 0x006985c0
void* ConstructWithVector(void* apObject)
{
    compiler_vector_constructor_iterator((char*)apObject + 4, 0x10, 2, &FUN_006d5320);
    return apObject;
}

struct FUN_006985f0_shell : public SineCosine
{
    SineCosine* CopyFloatPair(void*);
};

// Copies the first two floats from p into this object and returns this.
// @fnv 0x006985f0
SineCosine* FUN_006985f0_shell::CopyFloatPair(void* apSource)
{
    reinterpret_cast<float*>(this)[0] = static_cast<const float*>(apSource)[0];
    this->cosine = static_cast<const float*>(apSource)[1];
    return this;
}

struct ASC
{
    float s, c;
    ASC& operator=(const ASC&);
    ASC* Multiply(ASC* out, const ASC* o);
};
// Computes the product of this ASC and another ASC into out, combining s and c with the given formulas, and returns out.
// @fnv 0x00698620
ASC* ASC::Multiply(ASC* out, const ASC* apOther)
{
    ASC ret;
    new ((void *)&(ret)) ::Vec3();
    ret.s = s * apOther->s + c * apOther->c;
    ret.c = c * apOther->s - s * apOther->c;
    reinterpret_cast<::FUN_006985f0_shell *>((out))->CopyFloatPair=((void *)&(ret));
    return out;
}

// @fnv 0x00698680
int GetSignFlags(float* afValues)
{
    int res = 0;
    if (afValues[1] < 0.0)
        res ^= 3;
    if (afValues[0] < 0.0)
        res ^= 1;
    return res;
}

struct Sub
{
    int z[4];
    Sub();
    ~Sub();
};
struct FUN_00699450_S
{
    Sub a;
    Sub b;
    FUN_00699450_S();
};
// Constructs the object by default-constructing its two Sub members.
// @fnv 0x00699450
FUN_00699450_S::FUN_00699450_S()
{}

struct FUN_0069af60
{
    int pad[4];
    ~FUN_0069af60();
};

struct FUN_006994b0
{
    FUN_0069af60 a;
    FUN_0069af60 b;
    ~FUN_006994b0();
};

// @fnv 0x006994b0
FUN_006994b0::~FUN_006994b0()
{}

struct Dummy_0069a660
{
    int a;
    short b;
    Dummy_0069a660* SetValues(int p1, short p2);
};

// Stores the two arguments into the object's fields and returns the object.
// @fnv 0x0069a660
Dummy_0069a660* Dummy_0069a660::SetValues(int aiValue, short asValue)
{
    a = aiValue;
    b = asValue;
    return this;
}

struct FUN_0069a6c0_S
{
    void* nav;
    unsigned short tri;
    int edge;
    FUN_0069a6c0_S* FUN_0069a6c0(void* n, unsigned short t, int e);
};
// Calls _ref_006815c0, then stores the nav pointer, triangle index and edge value into this object and returns it.
// @fnv 0x0069a6c0
FUN_0069a6c0_S* FUN_0069a6c0_S::FUN_0069a6c0(void* apNav, unsigned short ausTri, int aiEdge)
{
    new ((void *)this) ::Vec3();
    nav = apNav;
    tri = ausTri;
    edge = aiEdge;
    return this;
}

struct FUN_0069a700_shell : public NavMeshTriangleHandle
{
    void FUN_0069a700(void*);
};

// Builds a 16-bit value from bits 0-13 of the word at aEdge+4 and bits 0-1 of the word at aEdge+8 shifted left 14, storing it at this.
// @fnv 0x0069a700
void FUN_0069a700_shell::FUN_0069a700(void* aEdge)
{
    *(unsigned short*)this =
        ((*(unsigned short*)((char*)aEdge + 4) & 0x3fff) | ((*(unsigned short*)((char*)aEdge + 8) & 3) << 14));
}

extern int DAT_0106b1b8;

struct Dummy_0069af30
{
    void* vtable;
    void ResetAndWrite(int, int);
};

// Sets the vtable pointer and calls ResetAndWrite with 0, 0, then returns pThis.
// @fnv 0x0069af30
Dummy_0069af30* FUN_0069af30(Dummy_0069af30* pThis)
{
    pThis->vtable = &DAT_0106b1b8;
    pThis->ResetAndWrite(0, 0);
    return pThis;
}

extern int DAT_0106b1b8;

class GlobalObject_00869f00
{
  public:
};

// @fnv 0x0069af60
void FUN_0069af60(GlobalObject_00869f00* apObject)
{
    *(int**)apObject = &DAT_0106b1b8;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((apObject))->Clear(true);
}

struct VH
{
    int a[2];
    void TwoIntRecord(const VH&);
};
struct FUN_0069b030_S
{
    int pad;
    VH* data;
    unsigned int Append(const VH* v);
};
struct EH
{
    char b[12];
    EH& operator=(const EH&);
};
struct FUN_0069b310_S
{
    int pad;
    EH* data;
    unsigned int AppendElement(const EH* v);
};

struct FUN_006a04e0_helper : public SineCosine
{
    void* SetFromAngle(float afAngle);
};

// Stores cos(afAngle) and FUN_004e44b0(afAngle) into the first two floats of this object and returns this.
// @fnv 0x006a04e0
void* FUN_006a04e0_helper::SetFromAngle(float afAngle)
{
    ((float*)this)[0] = cos(afAngle);
    this->cosine = FUN_004e44b0(afAngle);
    return this;
}

struct FUN_006bc870_shell : public NavMeshEdgeData
{
    NavMeshEdgeData* CopyFromNavMeshEdge(void*);
};
// Gets the current count, grows the data array by one element, copies the given element into the new slot, and returns its index.
// @fnv 0x0069b310
unsigned int FUN_0069b310_S::AppendElement(const EH* apElement)
{
    unsigned int i = reinterpret_cast<::S5460 *>(this)->FUN_00978bc0();
    reinterpret_cast<::PlacementRange *>(this)->ConstructBounds((::NiBound *)(::EH *)(&data[i]), 1);
    reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::EH &)(data[i]))->CopyFromNavMeshEdge((void *)&(*apElement));
    return i;
}

// Copies an int, a short and an int from aNavMeshEdgeHandle into this object at offsets 0, 4 and 8, then returns this.
// @fnv 0x006bc870
NavMeshEdgeData* FUN_006bc870_shell::CopyFromNavMeshEdge(void* aNavMeshEdgeHandle)
{
    *(int*)((char*)this + 0) = *(int*)((char*)aNavMeshEdgeHandle + 0);
    *(short*)&this->m_usTriangleID = *(short*)((char*)aNavMeshEdgeHandle + 4);
    this->m_iEdgeIndex = *(int*)((char*)aNavMeshEdgeHandle + 8);
    return this;
}

struct NiP2
{
    float x, y;
    NiP2();
};
struct USW
{
    unsigned short v;
};
struct IW
{
    int v;
};
bool __cdecl FUN_006b9e90(NiP2*, NiP2*, int, int, int);
// Builds the triangle's three 2D vertices and returns the first edge index (skipping edge) for which FUN_006b9e90 succeeds, else -1.
// @fnv 0x00698060
int FindTriangleEdge(NavMesh* self, USW usTri, IW iSkipEdge, IW a3, IW a4, IW a5)
{
    NiP2 verts[3];
    NiPoint3 pt;
    for (int i = 0; i < 3; i++)
    {
        pt = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((self))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((self->GetTriangle(usTri.v)))->FUN_005582d0(i))));
        verts[i].x = pt.x;
        verts[i].y = pt.y;
    }
    for (int j = 0; j < 3; j++)
    {
        if (j == iSkipEdge.v)
            continue;
        int k = j + 1;
        if (k == 3)
            k = 0;
        if (FUN_006b9e90(&verts[j], &verts[k], a3.v, a4.v, a5.v))
            return j;
    }
    return -1;
}

struct S0069a690
{
    int a;
    unsigned short b;
    S0069a690* FUN_0069a690(const S0069a690* o);
};
// @fnv 0x0069b030
unsigned int FUN_0069b030_S::Append(const VH* apValue)
{
    unsigned int i = reinterpret_cast<::S5460 *>(this)->FUN_00845460();
    reinterpret_cast<::FUN_006927d0_cls *>(this)->ConstructPairCells((::PairCell *)(::VH *)(&data[i]), 1);
    reinterpret_cast<::S0069a690 *>(&(data[i]))->FUN_0069a690((const ::S0069a690 *)&(*apValue));
    return i;
}
// Copies the int and unsigned short members from another S0069a690 into this one and returns this.
// @fnv 0x0069a690
S0069a690* S0069a690::FUN_0069a690(const S0069a690* apOther)
{
    a = apOther->a;
    b = apOther->b;
    return this;
}

extern unsigned int _data_011c16bc;
struct B006815c0
{
    char p[8];
    B006815c0();
};
struct FUN_0069b2c0
{
    char p[0x10];
    FUN_0069b2c0();
    ~FUN_0069b2c0();
};
struct FUN_0069a730 : public B006815c0
{
    FUN_0069b2c0 a;
    FUN_0069b2c0 b;
    FUN_0069a730();
};
// Default constructor for FUN_0069a730 that initializes its two FUN_0069b2c0 members and base B006815c0.
// @fnv 0x0069a730
FUN_0069a730::FUN_0069a730()
{}

struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    virtual void SetValue(IT*, TwoIntRecord, void*);
    virtual void v4();
    virtual IT* NewItem();
    unsigned int cnt;
    IT** table;
    unsigned int count;
};
struct VW
{
    void* p;
};
// Looks up key in the hash table; if found, overwrites its value, otherwise allocates a new item, inserts it at the bucket head and increments count.
// @fnv 0x0069b3d0
void SetKeyValue(MP* self, TwoIntRecord key, VW val)
{
    IT* pkItem;
    unsigned int uiIndex;
    unsigned int uiDepth;
    uiIndex = self->KeyToHashIndex(key);
    pkItem = self->table[uiIndex];
    uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (self->IsKeyEqual(key, pkItem->key))
        {
            pkItem->val = val.p;
            return;
        }
        pkItem = pkItem->next;
    }
    pkItem = self->NewItem();
    self->SetValue(pkItem, key, val.p);
    pkItem->next = self->table[uiIndex];
    self->table[uiIndex] = pkItem;
    self->count++;
}

namespace fnv_0069b4d0 {
struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    unsigned int cnt;
    IT** table;
};
struct VW
{
    void** p;
};
// Looks up key in the hash table and, if an equal entry is found, stores its value through val.p and returns true; otherwise returns false.
// @fnv 0x0069b4d0
bool FUN_0069b4d0(MP* self, TwoIntRecord key, VW aOutValue)
{
    IT* pkItem;
    unsigned int uiIndex = self->KeyToHashIndex(key);
    pkItem = self->table[uiIndex];
    while (pkItem)
    {
        if (self->IsKeyEqual(key, pkItem->key))
        {
            *aOutValue.p = pkItem->val;
            return true;
        }
        pkItem = pkItem->next;
    }
    return false;
}
}  // namespace fnv_0069b4d0

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0069a7a0(unsigned int flags);
};
// Calls the destructor on this object, frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0069a7a0
void* DelStandIn::FUN_0069a7a0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float afX, float afY, float afZ);
    NiPoint3 operator+(const NiPoint3& arPt) const;
};

struct ObstacleDataEx : public ObstacleData
{
    NiPoint3Ex WorldMin;
    NiPoint3Ex WorldMax;
};

struct ObstacleDataPtr
{
    ObstacleDataEx* object;
    ObstacleDataEx* operator->() const;
};


struct NavMeshTriList : public BSSimpleArray<unsigned short>
{
};

struct NavMeshGrid
{
};

struct NavMeshTriangleEx : public NavMeshTriangle
{
};

bool __cdecl FUN_00696540(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);

struct NavMeshOverlap : public NavMesh
{
    NavMeshGrid Grid;
    void FUN_006987d0(const ObstacleDataPtr& apObstacle, const NiPoint3& afFudge, NavMeshTriList* apRetTriangles);
};
// Computes an offset from the obstacle extent, gathers triangles via FUN_006987d0, and marks each triangle closed for the given door unless already recorded.
// @fnv 0x006997e0
bool NavMesh::AddDoorObstacle(unsigned int doorID, ObstacleData* obstacle)
{
    struct DoorBounds
    {
        NiPoint3 extent, offset;
    } geometry = {obstacle->m_kBoundsMax - obstacle->m_kBoundsMin, NiPoint3::ZERO};
    if (std::abs(geometry.extent.x) < std::abs(geometry.extent.y))
    {
        if (std::abs(geometry.extent.x) < std::abs(geometry.extent.z))
            geometry.offset.x = -std::abs(geometry.extent.x) * 0.49000000953674316;
        else
            geometry.offset.z = -std::abs(geometry.extent.z) * 0.49000000953674316;
    }
    else
    {
        if (std::abs(geometry.extent.y) < std::abs(geometry.extent.z))
            geometry.offset.y = -std::abs(geometry.extent.y) * 0.49000000953674316;
        else
            geometry.offset.z = -std::abs(geometry.extent.z) * 0.49000000953674316;
    }
    BSSimpleArray<unsigned short> triangles;
    reinterpret_cast<::NavMeshOverlap *>(this)->FUN_006987d0((const ::ObstacleDataPtr &)((const ::NiPointer< ::ObstacleData> &)(obstacle)), geometry.offset, (::NavMeshTriList *)(::BSSimpleArray<unsigned short> *)(&triangles));
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(triangles))->GetName())); i++)
    {
        NavMeshClosedDoorInfo* existing = GetClosedDoorInfo(reinterpret_cast<::FUN_005eeda0_this *>(&(triangles))->GetBufferEntry(i));
        if (!existing || existing->iDoorID != doorID)
        {
            reinterpret_cast<::FUN_00691570_shell *>((GetTriangle(reinterpret_cast<::FUN_005eeda0_this *>(&(triangles))->GetBufferEntry(i))))->FUN_00691570(0x1000);
            NavMeshClosedDoorInfo entry;
            entry.iDoorID = doorID;
            entry.m_usTriangleID = reinterpret_cast<::FUN_005eeda0_this *>(&(triangles))->GetBufferEntry(i);
            reinterpret_cast<::FUN_0069b030_S *>(&(m_kClosedDoorInfo))->Append((const ::VH *)&(entry));
        }
    }
    return true;
}

struct NavMeshVertexEdgeData;

struct VertMapItem
{
    VertMapItem* m_pkNext;
    TwoIntRecord m_key;
    NavMeshVertexEdgeData* m_val;
};

struct VertMap
{
    virtual unsigned int GetPad();
    virtual unsigned int KeyToHashIndex(TwoIntRecord key) const;
    unsigned int m_uiHashSize;
    VertMapItem** m_ppkHashTable;
    void GetNextEntry(void*& pos, TwoIntRecord& key, NavMeshVertexEdgeData*& val) const;
};

// Reads the key and value from the item at pos, then advances pos to the next item in the chain or the next non-empty hash bucket, or null.
// @fnv 0x0069b560
void VertMap::GetNextEntry(void*& pos, TwoIntRecord& arKey, NavMeshVertexEdgeData*& val) const
{
    VertMapItem* pkItem = (VertMapItem*)pos;
    reinterpret_cast<::S0069a690 *>((void *)&(const ::TwoIntRecord &)(arKey))->FUN_0069a690((const ::S0069a690 *)&(pkItem->m_key));
    val = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        pos = pkItem->m_pkNext;
        return;
    }
    unsigned int i = KeyToHashIndex(pkItem->m_key);
    for (++i; i < m_uiHashSize; ++i)
    {
        pkItem = m_ppkHashTable[i];
        if (pkItem)
        {
            pos = pkItem;
            return;
        }
    }
    pos = 0;
}

struct FUN_0069b120_stub
{
};

struct FUN_00699590_shell
{
    void ForwardToStub(int arg);
};

// Calls FUN_0069b120 on the stub at this+0xd0 with arg and 1.
// @fnv 0x00699590
void FUN_00699590_shell::ForwardToStub(int arg)
{
    reinterpret_cast<::B120Array *>((((FUN_0069b120_stub*)((char*)this + 0xd0))))->FUN_0069b120(arg, 1);
}

struct Flt
{
    operator unsigned int() const;
};

struct Arr
{
    Flt* GetAt(int);
};

struct FUN_00699630_shell
{
    int FindEntryIndex(int);
    Arr arr;
    int FUN_00699630(int param1, unsigned int* out);
};

// @fnv 0x00699630
int FUN_00699630_shell::FUN_00699630(int param1, unsigned int* apuiValue)
{
    int idx = this->FindEntryIndex(param1);
    if (idx != -1)
    {
        *apuiValue = ((Arr*)((char*)this + 0xd0))->GetAt(idx)->operator unsigned int();
        return idx;
    }
    *apuiValue = 0;
    return -1;
}

struct FUN_00699790_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    unsigned int m_iFourthElementInteger;  // offset 0xc
    int GetBits13To15();
};

// @fnv 0x00699790
int FUN_00699790_shell::GetBits13To15()
{
    return (m_iFourthElementInteger & 0xe000) >> 13;
}

struct FUN_0069af80_shell
{
    void* FUN_0069af80(int count);
};
// Allocates a new byte array of count * 12 bytes and returns a pointer to it.
// @fnv 0x0069af80
void* FUN_0069af80_shell::FUN_0069af80(int count)
{
    return new unsigned char[count * 12];
}

struct FUN_00699b60_shell : public NavMesh
{
    void BuildPortalPOVs();
};

namespace std {
float __cdecl abs(float);
}


// Builds per-vertex edge lists from triangle edges, pairs edges into portals, and assigns each triangle the nearest portal vertex within a radius.
// @fnv 0x00699b60
void FUN_00699b60_shell::BuildPortalPOVs()
{
    reinterpret_cast<::FUN_00438af0_Class *>(&(POVPointerArray))->FUN_00438af0();
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_kAdditionalIndexList))->Clear(true);
    NavMeshVertexMap kNavMeshVertexLookup(37);
    unsigned int itriCount = ::FUN_00558200((char *)this);
    void* it;
    for (unsigned int i = 0; i < itriCount; ++i)
    {
        NavMeshTriangle* ptri = GetTriangle(i);
        for (int e = 0; e < 3; ++e)
        {
            if (reinterpret_cast<::FUN_0068f2c0_shell *>((ptri))->FUN_0068f2c0(e) == 0xFFFF)
            {
                NavMeshEdgeData hedge(this, i, e);
                TwoIntRecord hvert1(this, reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(e));
                NavMeshVertexEdgeData* pdata1;
                if (!::fnv_0069b4d0::FUN_0069b4d0((::fnv_0069b4d0::MP *)&(kNavMeshVertexLookup), hvert1, (*(::fnv_0069b4d0::VW *)&(pdata1))))
                {
                    pdata1 = new NavMeshVertexEdgeData;
                    reinterpret_cast<::S0069a690 *>((void *)&(const ::TwoIntRecord &)(pdata1->m_kVertexKey))->FUN_0069a690((const ::S0069a690 *)&(hvert1));
                    ::SetKeyValue((::MP *)&(kNavMeshVertexLookup), hvert1, (::VW)(pdata1));
                }
                reinterpret_cast<::FUN_0069b310_S *>(&(pdata1->Edges))->AppendElement((const ::EH *)&(hedge));
                TwoIntRecord hvert2(this, reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0((e + 1) % 3));
                NavMeshVertexEdgeData* pdata2;
                if (!::fnv_0069b4d0::FUN_0069b4d0((::fnv_0069b4d0::MP *)&(kNavMeshVertexLookup), hvert2, (*(::fnv_0069b4d0::VW *)&(pdata2))))
                {
                    pdata2 = new NavMeshVertexEdgeData;
                    reinterpret_cast<::S0069a690 *>((void *)&(const ::TwoIntRecord &)(pdata2->m_kVertexKey))->FUN_0069a690((const ::S0069a690 *)&(hvert2));
                    ::SetKeyValue((::MP *)&(kNavMeshVertexLookup), hvert2, (::VW)(pdata2));
                }
                reinterpret_cast<::FUN_0069b310_S *>(&(pdata2->Edges))->AppendElement((const ::EH *)&(hedge));
            }
            else if (reinterpret_cast<::FUN_0068f1d0_shell *>((ptri))->IsEdgeFlagSet(e))
            {
                NavMeshEdgeData hedge(this, i, e);
                TwoIntRecord hvert1(this, reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(e));
                NavMeshVertexEdgeData* pdata1;
                if (!::fnv_0069b4d0::FUN_0069b4d0((::fnv_0069b4d0::MP *)&(kNavMeshVertexLookup), hvert1, (*(::fnv_0069b4d0::VW *)&(pdata1))))
                {
                    pdata1 = new NavMeshVertexEdgeData;
                    reinterpret_cast<::S0069a690 *>((void *)&(const ::TwoIntRecord &)(pdata1->m_kVertexKey))->FUN_0069a690((const ::S0069a690 *)&(hvert1));
                    ::SetKeyValue((::MP *)&(kNavMeshVertexLookup), hvert1, (::VW)(pdata1));
                }
                reinterpret_cast<::FUN_0069b310_S *>(&(pdata1->m_kOutgoingEdges))->AppendElement((const ::EH *)&(hedge));
                TwoIntRecord hvert2(this, reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0((e + 1) % 3));
                NavMeshVertexEdgeData* pdata2;
                if (!::fnv_0069b4d0::FUN_0069b4d0((::fnv_0069b4d0::MP *)&(kNavMeshVertexLookup), hvert2, (*(::fnv_0069b4d0::VW *)&(pdata2))))
                {
                    pdata2 = new NavMeshVertexEdgeData;
                    reinterpret_cast<::S0069a690 *>((void *)&(const ::TwoIntRecord &)(pdata2->m_kVertexKey))->FUN_0069a690((const ::S0069a690 *)&(hvert2));
                    ::SetKeyValue((::MP *)&(kNavMeshVertexLookup), hvert2, (::VW)(pdata2));
                }
                reinterpret_cast<::FUN_0069b310_S *>(&(pdata2->m_kOutgoingEdges))->AppendElement((const ::EH *)&(hedge));
            }
        }
    }

    it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(kNavMeshVertexLookup))->GetFirstPos();
    while (it)
    {
        TwoIntRecord hvert;
        NavMeshVertexEdgeData* pdata;
        reinterpret_cast<::VertMap *>(&(kNavMeshVertexLookup))->GetNextEntry(it, hvert, pdata);
        unsigned int iedgeCount = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pdata->Edges))->GetName()));
        unsigned int iportalEdgeCount = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pdata->m_kOutgoingEdges))->GetName()));
        if (iedgeCount + iportalEdgeCount == 2)
        {
            NavMeshEdgeData hdataEdge0;
            NavMeshEdgeData hdataEdge1;
            if (iedgeCount == 2)
            {
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hdataEdge0))->CopyFromNavMeshEdge((void *)&(pdata->Edges.FUN_006a1440(0)));
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hdataEdge1))->CopyFromNavMeshEdge((void *)&(pdata->Edges.FUN_006a1440(1)));
            }
            else if (iedgeCount == 1)
            {
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hdataEdge0))->CopyFromNavMeshEdge((void *)&(pdata->Edges.FUN_006a1440(0)));
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hdataEdge1))->CopyFromNavMeshEdge((void *)&(pdata->m_kOutgoingEdges.FUN_006a1440(0)));
            }
            else
            {
                continue;
            }
            NavMeshEdgeData hedge1;
            NavMeshEdgeData hedge2;
            const NiPoint3* pverts[3];
            NavMeshEdgeVertexPair verts1 = FUN_0068f040(hdataEdge0.m_usTriangleID, hdataEdge0.m_iEdgeIndex);
            NavMeshEdgeVertexPair verts2 = FUN_0068f040(hdataEdge1.m_usTriangleID, hdataEdge1.m_iEdgeIndex);
            if (verts1.first == verts2.second)
            {
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hedge1))->CopyFromNavMeshEdge((void *)&(hdataEdge0));
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hedge2))->CopyFromNavMeshEdge((void *)&(hdataEdge1));
                pverts[0] = verts1.second;
                pverts[1] = verts1.first;
                pverts[2] = verts2.first;
            }
            else if (verts1.second == verts2.first)
            {
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hedge1))->CopyFromNavMeshEdge((void *)&(hdataEdge1));
                reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::NavMeshEdgeData &)(hedge2))->CopyFromNavMeshEdge((void *)&(hdataEdge0));
                pverts[0] = verts2.second;
                pverts[1] = verts2.first;
                pverts[2] = verts1.first;
            }
            else
            {
                continue;
            }
            NiPoint3 edge1 = *pverts[0] - *pverts[1];
            NiPoint3 edge2 = *pverts[2] - *pverts[1];
            edge1.z = 0;
            edge2.z = 0;
            reinterpret_cast<::FUN_004a0c10_s *>(&(edge1))->FUN_004a0c10();
            reinterpret_cast<::FUN_004a0c10_s *>(&(edge2))->FUN_004a0c10();
            NiPoint3 cross = edge1.Cross(edge2);
            float fdot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(edge1))->DotProduct((void *)&(edge2));
            bool badd = false;
            if (fdot > ::_DAT_01012060)
            {
                if (cross.z < (double)0.1f)
                {
                    badd = true;
                    if (cross.z > ::_DAT_01012060)
                    {
                        NiPoint3 temp = edge1;
                        edge1 = edge2;
                        edge2 = temp;
                    }
                }
            }
            else if (cross.z < -(double)0.1f)
            {
                badd = true;
            }
            if (badd || iedgeCount == 1)
            {
                NavMeshPOVData pov;
                reinterpret_cast<::FUN_0069a700_shell *>(&(pov.m_kFirstEdge))->FUN_0069a700((void *)&(hedge1));
                reinterpret_cast<::FUN_0069a700_shell *>(&(pov.m_kSecondEdge))->FUN_0069a700((void *)&(hedge2));
                reinterpret_cast<::Map00694c50 *>(&(POVPointerArray))->InsertOrUpdate(hvert.m_usVertexId, (*(unsigned int *)&(const ::NavMeshPOVData &)(pov)));
            }
        }
    }

    it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(kNavMeshVertexLookup))->GetFirstPos();
    while (it)
    {
        TwoIntRecord hvert;
        NavMeshVertexEdgeData* pdata;
        reinterpret_cast<::VertMap *>(&(kNavMeshVertexLookup))->GetNextEntry(it, hvert, pdata);
        delete pdata;
    }

    const float afValueAfterThirdFloat = 128.0f;
    for (unsigned int i = 0; i < itriCount; ++i)
    {
        NiPoint3 circumCenter = FUN_00697290(i);
        NiPoint3 vertLoc = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(i)))->FUN_005582d0(0))));
        float fradius = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::NiPoint3 &)((vertLoc - circumCenter)))->FUN_00589850();
        float fmaxRadius = fradius + afValueAfterThirdFloat;
        float fmaxRadiusSqr = fmaxRadius * fmaxRadius;
        unsigned short iClosestPOV = 0xFFFF;
        float fclosestPOVSqrDist = fmaxRadiusSqr * fmaxRadiusSqr;
        void* it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(POVPointerArray))->GetFirstPos();
        while (it)
        {
            unsigned short usCurrentVertexIndex;
            NavMeshPOVData data;
            reinterpret_cast<::Map00694d30 *>(&(POVPointerArray))->FUN_00694d30((::Item00694d30 **)&(it), (unsigned short *)&(usCurrentVertexIndex), (::POV00694d30 *)&(data));
            NiPoint3 delta = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(usCurrentVertexIndex))) - circumCenter;
            float fsqrDist = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(delta))->GetSquaredXYLength();
            if (fsqrDist < fclosestPOVSqrDist && std::abs(delta.z) < 180.0)
            {
                fclosestPOVSqrDist = fsqrDist;
                iClosestPOV = usCurrentVertexIndex;
            }
        }
        reinterpret_cast<::FUN_00691820_arr *>(&(m_kAdditionalIndexList))->Append((const unsigned short *)&(iClosestPOV));
    }
}

struct NiPoint2
{
    float x;
    float y;
    NiPoint2(float fx, float fy);
};


// @fnv 0x00696540
void FUN_00696540(const NiPoint3* aSegment1Start, const NiPoint3* aSegment2Start, const NiPoint3* aSegment1End,
                  const NiPoint3* aSegment2End)
{
    ::FUN_006ba010((const ::NiPoint3 *)&(const ::NiPoint2 &)(NiPoint2(aSegment1Start->x, aSegment1Start->y)), (const ::NiPoint3 *)&(const ::NiPoint2 &)(NiPoint2(aSegment2Start->x, aSegment2Start->y)),
                 (const ::NiPoint3 *)&(const ::NiPoint2 &)(NiPoint2(aSegment1End->x, aSegment1End->y)), (const ::NiPoint3 *)&(const ::NiPoint2 &)(NiPoint2(aSegment2End->x, aSegment2End->y)));
}

struct FUN_006967c0_shell
{
    int f0;
    char pad[32];
    intptr_t f24;
    intptr_t FUN_006967c0(int a, int b);
};
// @fnv 0x006967c0
intptr_t FUN_006967c0_shell::FUN_006967c0(int a, int b)
{
    int t = b * f0 + a;
    return (t << 4) + f24;
}

struct Vec00696a10
{
    int v0;
    int v1;
    int v2;
};
struct Obj00696a10
{
    char pad[12];
    Vec00696a10 m1;
    Vec00696a10 m2;
    void GetVectors(Vec00696a10*, Vec00696a10*);
};
// @fnv 0x006969e0
bool FUN_006969e0_shell::FUN_006969e0(NiPoint3* aRetMin, NiPoint3* aRetMax)
{
    reinterpret_cast<::Obj00696a10 *>((reinterpret_cast<DummyA8*>(reinterpret_cast<char*>(this) + 0xa8)))->GetVectors((::Vec00696a10 *)(aRetMin), (::Vec00696a10 *)(aRetMax));
    return true;
}
// Copies the object's two Vec00696a10 members into the caller-supplied output vectors.
// @fnv 0x00696a10
void Obj00696a10::GetVectors(Vec00696a10* pVec1, Vec00696a10* pVec2)
{
    *pVec1 = m1;
    *pVec2 = m2;
}

struct Holder
{
    Holder* FUN_00696ca0(Holder*);
};
// Copies the float at offset 0x10, the int at 0x14 and the 64-bit value at 0x18 from p into this after calling FUN_004a3c90, then returns this.
// @fnv 0x00696ca0
Holder* Holder::FUN_00696ca0(Holder* apSource)
{
    new ((void *)(this)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(apSource)));
    *(float*)((char*)this + 0x10) = *(float*)((char*)apSource + 0x10);
    *(int*)((char*)this + 0x14) = *(int*)((char*)apSource + 0x14);
    *(__int64*)((char*)this + 0x18) = *(__int64*)((char*)apSource + 0x18);
    return this;
}

struct FindTriangleForLocationFilter;
struct FUN_00697670_StandIn : NavMesh
{
    unsigned short FindTriangleForLocation(const NiPoint3&, FindTriangleForLocationFilter*);
    bool IsLocationOnNavMesh(const NiPoint3&, FindTriangleForLocationFilter*);
};
// Returns true if FindTriangleForLocation finds a triangle (result not 0xFFFF) for the given position and filter.
// @fnv 0x00697670
bool FUN_00697670_StandIn::IsLocationOnNavMesh(const NiPoint3& aPos, FindTriangleForLocationFilter* apFilter)
{
    if (FindTriangleForLocation(aPos, apFilter) != 0xFFFF)
        return true;
    else
        return false;
}

struct Dummy698030
{
    int _p[3];
    unsigned int f12;
    unsigned int FUN_00698030(unsigned short a1);
};
// Shifts f12 right by a1*6+0x10 and returns the low 4 bits of the result.
// @fnv 0x00698030
unsigned int Dummy698030::FUN_00698030(unsigned short ausIndex)
{
    unsigned int result;
    {
        unsigned int shift = ausIndex * 6 + 0x10;
        result = f12 >> shift;
    }
    return result & 0xF;
}

struct FUN_00698300_shell
{
    FUN_00698300_shell* FUN_00698300();
};
// @fnv 0x00698300
FUN_00698300_shell* FUN_00698300_shell::FUN_00698300()
{
    new ((void *)(((FUN_00698300_shell*)((char*)this + 8)))) ::Vec3();
    return this;
}

namespace fnv_00698fc0 {
struct FUN_00699630_shell
{
};
struct FUN_00698fc0_shell : public FUN_00699630_shell
{
    bool UndoToPosition(int, int);
    bool FUN_00698fc0(int, int);
};
// Looks up an index for a via FUN_00699630 and, if found, forwards it with b to UndoToPosition and returns the result.
// @fnv 0x00698fc0
bool FUN_00698fc0_shell::FUN_00698fc0(int a, int b)
{
    int idx;
    {
        unsigned int tmp;
        idx = reinterpret_cast<::FUN_00699630_shell *>(this)->FUN_00699630(a, &tmp);
    }
    if (idx == -1)
        return false;
    return UndoToPosition(idx, b);
}
}  // namespace fnv_00698fc0

// Returns the larger of the two unsigned arguments.
// @fnv 0x00699760
unsigned int MaxUnsigned(unsigned int auiValue, unsigned short ausValue)
{
    unsigned int c;
    if (auiValue > ausValue)
        c = auiValue;
    else
        c = ausValue;
    return c;
}

struct S0069afb0
{
};
struct S006997b0
{
    char _pad[0xE0];
    S0069afb0* p;
    int FUN_006997b0(unsigned short, intptr_t);
};
struct ArrSI
{
};
struct ActorAvoidanceDataArray
{
    void FUN_00983720(unsigned int, unsigned int);
};
struct BSXFlags_shell
{
};
struct S006950d0
{
    NavMeshClosedDoorInfo* GetElement(unsigned int);
};

struct FUN_00699a30_shell
{
    bool FUN_00699a30(unsigned int doorID);
};

// @fnv 0x00699a30
bool FUN_00699a30_shell::FUN_00699a30(unsigned int doorID)
{
    unsigned int i = 0;
    for (; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x68))))->GetName())); ++i)
    {
        if (((S006950d0*)((char*)this + 0x68))->GetElement(i)->iDoorID == doorID)
        {
            if (((S006950d0*)((char*)this + 0x68))->GetElement(i)->m_usTriangleID < ::FUN_00558200((char *)(((NavMesh*)this))))
            {
                reinterpret_cast<::FUN_00519270_shell *>((((BSXFlags_shell*)((NavMesh*)this)
                     ->GetTriangle(((S006950d0*)((char*)this + 0x68))->GetElement(i)->m_usTriangleID))))->ClearFlags(0x1000);
            }
            ((ActorAvoidanceDataArray*)((char*)this + 0x68))->FUN_00983720(i, 1);
            --i;
        }
    }
    return true;
}

struct FUN_0069b2f0
{
    int _d[4];
    ~FUN_0069b2f0();
};
struct FUN_0069a7d0
{
    int _pad[2];
    FUN_0069b2f0 m1;
    FUN_0069b2f0 m2;
    ~FUN_0069a7d0();
};
// Destructor for the object; it destroys the two embedded members and returns.
// @fnv 0x0069a7d0
FUN_0069a7d0::~FUN_0069a7d0()
{}

namespace fnv_0069a940 {

struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
};

struct GlobalObject_00869f00
{
    BSSimpleArray<unsigned short> m_kAdditionalIndexList;
};

struct FUN_0069a940_shell : NavMesh
{
    unsigned int FUN_0069a940(unsigned short, GlobalObject_00869f00*);
};

// Clears object, then for each of the triangle's three vertices appends it to object's array if found in the tri list, returning the count.
// @fnv 0x0069a940
unsigned int FUN_0069a940_shell::FUN_0069a940(unsigned short triangle, GlobalObject_00869f00* object)
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((object))->Clear(false);
    unsigned int count4 = 0;
    NavMeshTriangle* navMeshTriangle = GetTriangle(triangle);
    for (int i3 = 0; i3 < 3; ++i3)
    {
        unsigned short vertex3 = reinterpret_cast<::FUN_005582d0_shell *>((navMeshTriangle))->FUN_005582d0(i3);
        if (((NavMeshTriList*)((char*)this + 0xe4))->FindMatchingIndex(vertex3, 0, ((bool (&)(const unsigned short &, const unsigned short &))::AreWideCharsEqual)) != -1)
        {
            reinterpret_cast<::FUN_00691820_arr *>(&(object->m_kAdditionalIndexList))->Append((const unsigned short *)&(vertex3));
            ++count4;
        }
    }
    return count4;
}
}  // namespace fnv_0069a940

class SoundPlaybackHandle;
template <> class NiTPointerMap<unsigned int, SoundPlaybackHandle*>
{
  public:
};
struct FUN_0069b0a0_shell
{
};
struct FUN_0069a9d0_shell : NavMesh
{
    void FUN_0069a9d0(unsigned short, unsigned int);
};
struct FUN_0069b240_Holder
{
    int field_0;
    unsigned short* field_4;
    unsigned int field_8;
    int FindMatchingIndex(intptr_t, unsigned int, bool(__cdecl*)(unsigned short*, intptr_t));
};
// @fnv 0x006987d0
void NavMeshOverlap::FUN_006987d0(const ObstacleDataPtr& apObstacle, const NiPoint3& afFudge,
                                  NavMeshTriList* apRetTriangles)
{
    unsigned int istartRow = 0;
    unsigned int istartCol = 0;
    unsigned int iendRow = 0;
    unsigned int iendCol = 0;

    reinterpret_cast<::NavMeshGridX *>(&(Grid))->GetCellCoords(apObstacle->WorldMin, istartRow, istartCol);
    reinterpret_cast<::NavMeshGridX *>(&(Grid))->GetCellCoords(apObstacle->WorldMax, iendRow, iendCol);

    NiPoint3 cornersLocalSpace[4];
    cornersLocalSpace[0] = NiPoint3Ex(apObstacle->m_kBoundsMin.x - afFudge.x, apObstacle->m_kBoundsMin.y - afFudge.y,
                                      apObstacle->m_kBoundsMin.z);
    cornersLocalSpace[1] = NiPoint3Ex(apObstacle->m_kBoundsMin.x - afFudge.x, apObstacle->m_kBoundsMax.y + afFudge.y,
                                      apObstacle->m_kBoundsMin.z);
    cornersLocalSpace[2] = NiPoint3Ex(apObstacle->m_kBoundsMax.x + afFudge.x, apObstacle->m_kBoundsMax.y + afFudge.y,
                                      apObstacle->m_kBoundsMin.z);
    cornersLocalSpace[3] = NiPoint3Ex(apObstacle->m_kBoundsMax.x + afFudge.x, apObstacle->m_kBoundsMin.y - afFudge.y,
                                      apObstacle->m_kBoundsMin.z);

    float fzheight = apObstacle->WorldMax.z - apObstacle->WorldMin.z;

    for (unsigned int r = istartRow; r <= iendRow; r++)
    {
        for (unsigned int c = istartCol; c <= iendCol; c++)
        {
            NavMeshTriList* parray = ((::NavMeshTriList *)(reinterpret_cast<::FUN_006967c0_shell *>(&(Grid))->FUN_006967c0(c, r)));
            if (parray)
            {
                for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((void *)(parray))->GetName())); i++)
                {
                    if (reinterpret_cast<::FUN_0069b240_Holder *>((apRetTriangles))->FindMatchingIndex((intptr_t)&(reinterpret_cast<::FUN_0069dec0_class *>((void *)(parray))->FUN_0069dec0(i)), 0, (bool (*)(unsigned short *, intptr_t))(((bool (&)(const unsigned short &, const unsigned short &))::AreWideCharsEqual))) != -1)
                        continue;
                    NavMeshTriangleEx* ptri = (NavMeshTriangleEx*)GetTriangle(reinterpret_cast<::FUN_0069dec0_class *>((void *)(parray))->FUN_0069dec0(i));
                    if (reinterpret_cast<::FUN_00691140_shell *>((ptri))->FUN_00691140(0x20))
                        continue;

                    NiPoint3Ex wtriMin(3.402823466e+38f, 3.402823466e+38f, 3.402823466e+38f);
                    NiPoint3Ex wtriMax(::DAT_01015f5c, ::DAT_01015f5c, ::DAT_01015f5c);
                    for (int v = 0; v < 3; v++)
                    {
                        const NiPoint3* vertLocation = &(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(v))));
                        wtriMin.x = FUN_0040ebd0(wtriMin.x, vertLocation->x);
                        wtriMin.y = FUN_0040ebd0(wtriMin.y, vertLocation->y);
                        wtriMin.z = FUN_0040ebd0(wtriMin.z, vertLocation->z);
                        wtriMax.x = FUN_00404010(wtriMax.x, vertLocation->x);
                        wtriMax.y = FUN_00404010(wtriMax.y, vertLocation->y);
                        wtriMax.z = FUN_00404010(wtriMax.z, vertLocation->z);
                    }
                    wtriMax.z += 128.0;

                    if (!::DoBoundsOverlap((const ::NiPoint3 *)&(const ::NiPoint3 &)(apObstacle->WorldMin - afFudge), (const ::NiPoint3 *)&(const ::NiPoint3 &)(apObstacle->WorldMax + afFudge), (const ::NiPoint3 *)&(wtriMin),
                                         (const ::NiPoint3 *)&(wtriMax)))
                        continue;

                    bool bOverlap = false;
                    float fdontCare;
                    if (::fnv_006c3570::FUN_006c3570((::fnv_006c3570::NiPoint3 *)&(const ::NiPoint3 &)(reinterpret_cast<::NavMesh *>(this)->GetNavMeshData(reinterpret_cast<::FUN_0069dec0_class *>((void *)(parray))->FUN_0069dec0(i))), (::fnv_006c3570::Flt *)&(apObstacle), fzheight, 128.0f))
                    {
                        bOverlap = true;
                    }
                    else if (FindHeightOnTriangle(reinterpret_cast<::FUN_0069dec0_class *>((void *)(parray))->FUN_0069dec0(i),
                                                  *(const NiPoint3*)(apObstacle->prefix + 0x10), fdontCare, fzheight,
                                                  128.0f))
                    {
                        bOverlap = true;
                    }
                    else
                    {
                        for (unsigned int triv = 0; triv < 3; triv++)
                        {
                            unsigned int triw = triv + 1;
                            if (triw == 3)
                                triw = 0;
                            NiPoint3 vert1 = (*(::NiPoint3 *)(::FUN_004b3ae0((::NiPoint3 *)&(const ::NiPoint3 &)((*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(triv)))) -
                                                              *(const NiPoint3*)(apObstacle->prefix + 0x10)),
                                                          (*(const ::NiPoint3 *)((const float*)(apObstacle->prefix + 0x1c))), {})));
                            NiPoint3 vert2 = (*(::NiPoint3 *)(::FUN_004b3ae0((::NiPoint3 *)&(const ::NiPoint3 &)((*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(triw)))) -
                                                              *(const NiPoint3*)(apObstacle->prefix + 0x10)),
                                                          (*(const ::NiPoint3 *)((const float*)(apObstacle->prefix + 0x1c))), {})));
                            for (unsigned int boxv = 0; boxv < 4; boxv++)
                            {
                                unsigned int boxw = boxv + 1;
                                if (boxw == 4)
                                    boxw = 0;
                                NiPoint3 box1 = cornersLocalSpace[boxv];
                                NiPoint3 box2 = cornersLocalSpace[boxw];
                                if (FUN_00696540(vert1, vert2, box1, box2))
                                {
                                    bOverlap = true;
                                    break;
                                }
                            }
                            if (bOverlap)
                                break;
                        }
                    }
                    if (bOverlap)
                        reinterpret_cast<::FUN_00691820_arr *>((apRetTriangles))->Append((const unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((void *)(parray))->FUN_0069dec0(i)));
                }
            }
        }
    }
}
// Scans field_4 from start to field_8, calling func on each element with a, and returns the first matching index or -1.
// @fnv 0x0069b240
int FUN_0069b240_Holder::FindMatchingIndex(intptr_t aiValue, unsigned int start, bool(__cdecl* func)(unsigned short*, intptr_t))
{
    unsigned int i;
    for (i = start; i < field_8; ++i)
    {
        if (field_4 && func(field_4 + i, aiValue))
            return (int)i;
    }
    return -1;
}

namespace fnv_006b39a0 {
struct EH
{
    int a;
    int b;
    int c;
    EH& operator=(EH const&);
};
struct C006b39a0
{
    C006b39a0& FUN_006b39a0(C006b39a0 const&);
};
// Copies the first field, an EH at offset 8, and three ints at offsets 0x14, 0x18 and 0x1c from rhs into this, returning *this.
// @fnv 0x006b39a0
C006b39a0& C006b39a0::FUN_006b39a0(C006b39a0 const& rhs)
{
    reinterpret_cast<::S0069a690 *>((void *)&(const ::TwoIntRecord &)(*(TwoIntRecord*)this))->FUN_0069a690((const ::S0069a690 *)&(*(TwoIntRecord*)&rhs));
    reinterpret_cast<::FUN_006bc870_shell *>((void *)&(const ::fnv_006b39a0::EH &)(*(EH*)((char*)this + 8)))->CopyFromNavMeshEdge((void *)&(*(EH*)((char*)&rhs + 8)));
    *(int*)((char*)this + 0x14) = *(int*)((char*)&rhs + 0x14);
    *(int*)((char*)this + 0x18) = *(int*)((char*)&rhs + 0x18);
    *(int*)((char*)this + 0x1c) = *(int*)((char*)&rhs + 0x1c);
    return *this;
}
}  // namespace fnv_006b39a0

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct FindTriangleForLocationFilter;
struct NavMeshPtr;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct PathingLocation
{
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadGameBuffer*);
    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    struct blob12 GetLocation();
    TESObjectCELL* GetContainingCell();
    TESWorldSpace* GetParentWorldspace();
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    unsigned short GetTriangle();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool HasPathingLocation();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    void* __vecDelDtor(unsigned int);
    NiPoint3 Location;
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    char _pad_27[1];
};
struct FUN_006dcee0_shell : public NavMesh
{
    bool FUN_006dcee0(void*, FindTriangleForLocationFilter*);
};

struct Sub6815c0
{
};
struct FUN_006dcee0_t
{
    int* vfptr;
    Sub6815c0 s;
    FUN_006dcee0_t* FUN_006dcee0(void*, TESObjectCELL*, TESWorldSpace*);
};
// @fnv 0x006dcee0
FUN_006dcee0_t* FUN_006dcee0_t::FUN_006dcee0(void* a1, TESObjectCELL* apCell, TESWorldSpace* apWorldspace)
{
    vfptr = &DAT_0102583c;
    new ((void *)&(s)) ::Vec3();
    reinterpret_cast<::SetupPathingLocation *>((((PathingLocation*)this)))->FUN_006dd280((*(const ::NiPoint3 *)(a1)), apCell, apWorldspace);
    return this;
}

struct S696500
{
    int m0;
    char _pad[32];
    BSSimpleArray<unsigned short, 1024>* m24;
    void FUN_00696500(unsigned short, int, int);
};
// Computes index as c * m0 + b and calls the array element's method with a.
// @fnv 0x00696500
void S696500::FUN_00696500(unsigned short ausValue, int b, int c)
{
    int index = c * m0 + b;
    reinterpret_cast<::FUN_00691820_arr *>(&(m24[index]))->Append((const unsigned short *)&(ausValue));
}

struct Out_0069d4b0;
struct Pt_0069d4b0;
struct Sub0069d4b0
{
public:
    void FUN_0069d4b0(::Pt_0069d4b0 *, ::Pt_0069d4b0 *, ::Out_0069d4b0 *);
};
struct Obj00696c00
{
    char _pad[0xA8];
    Sub0069d4b0 sub;
    void ForwardToSub(int a, int b, int c);
};
// Calls FUN_0069d4b0 on the sub object at offset 0xA8, passing the three arguments through.
// @fnv 0x00696c00
void Obj00696c00::ForwardToSub(int aiArg1, int aiArg2, int aiArg3)
{
    reinterpret_cast<::Sub0069d4b0 *>(&(sub))->FUN_0069d4b0((::Pt_0069d4b0 *)(aiArg1), (::Pt_0069d4b0 *)(aiArg2), (::Out_0069d4b0 *)(aiArg3));
}

struct S50
{
    char _pad[0x50];
    int f50;
    S50* FUN_00696c30(S50* p);
};
struct MidCopy
{
    char _pad[32];
    struct Inner
    {
        unsigned int d[8];
    } inner;
    unsigned int tail;
    MidCopy& AssignFrom(const MidCopy&);
};
// Calls AssignFrom on p, copies p->f50 into this->f50, and returns this.
// @fnv 0x00696c30
S50* S50::FUN_00696c30(S50* apSource)
{
    reinterpret_cast<::MidCopy *>(this)->AssignFrom((*(const ::MidCopy *)(apSource)));
    f50 = apSource->f50;
    return this;
}
// @fnv 0x00696c60
MidCopy& MidCopy::AssignFrom(const MidCopy& other)
{
    reinterpret_cast<::Holder *>(this)->FUN_00696ca0((::Holder *)&(other));
    inner = other.inner;
    tail = other.tail;
    return *this;
}


struct FUN_0069b360_shell
{
    void* ConstructBuffer(unsigned int a);
};

// @fnv 0x0069b360
void* FUN_0069b360_shell::ConstructBuffer(unsigned int a)
{
    *(void**)this = &(*reinterpret_cast<void * *>(&::fnv_0069b730::DAT_0106b1f4));
    *(unsigned int*)((char*)this + 4) = a;
    *(unsigned int*)((char*)this + 0xc) = 0;
    unsigned int uiSize = *(unsigned int*)((char*)this + 4) * 4;
    *(void**)((char*)this + 8) = ::FUN_00aa1070(uiSize);
    ::FUN_00403d30(*(void**)((char*)this + 8), 0, *(unsigned int*)((char*)this + 4) * 4);
    return this;
}

namespace fnv_00697810 {
struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct FUN_00697810_t;
struct NavCallback_00697810
{
    virtual bool Test(const NiPoint3&, NavMesh*, unsigned short, B006815c0&);
};
struct FUN_00697810_t : public NavMesh
{
    bool TestPointOnTriangle(unsigned short ausTri, const NiPoint3& arPoint, float& arZ,
                             NavCallback_00697810* apCallback);
};
// Tests arPoint against triangle ausTri, computes arZ, and if a callback is given calls its Test with the point raised by arZ.
// @fnv 0x00697810
bool FUN_00697810_t::TestPointOnTriangle(unsigned short ausTri, const NiPoint3& arPoint, float& arZ,
                                         NavCallback_00697810* apCallback)
{
    if (!apCallback)
        return FindHeightOnTriangle(ausTri, arPoint, arZ, 3.4028234663852886e+38f, 3.4028234663852886e+38f);
    B006815c0 v1;
    bool bResult;
    {
        B006815c0 v0;
        B006815c0 v2;
        NavMeshTriangle* ptri = GetTriangle(ausTri);
        v1 = *(const B006815c0*)&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(0))));
        v0 = *(const B006815c0*)&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(1))));
        v2 = *(const B006815c0*)&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(2))));
        bResult = FUN_006b9cf0(*(const NiPoint3*)&v1, *(const NiPoint3*)&v0, *(const NiPoint3*)&v2, arPoint, arZ,
                               3.4028234663852886e+38f, 3.4028234663852886e+38f);
    }
    if (bResult && apCallback)
    {
        B006815c0 p = *(const B006815c0*)&arPoint;
        p.z += arZ;
        return apCallback->Test(arPoint, this, ausTri, p);
    }
    else
    {
        return bResult;
    }
}
}  // namespace fnv_00697810

struct FUN_00697980_t : public NavMesh
{
    bool GetTriangleHeightAtPoint(unsigned short ausTriangle, const NiPoint3& arPoint, float afAbove, float afBelow,
                                  float* apfZ);
};

// Tests whether arPoint lies inside triangle ausTriangle in XY, writes the interpolated Z to apfZ, and checks the Z offset against afAbove/afBelow.
// @fnv 0x00697980
bool FUN_00697980_t::GetTriangleHeightAtPoint(unsigned short ausTriangle, const NiPoint3& arPoint, float afAbove,
                                              float afBelow, float* apfHeight)
{
    float fY0;
    {
        float fY2;
        {
            const NiPoint3* pVertex0;
            {
                float fWeight0;
                {
                    float fInvDet;
                    {
                        float fWeight1;
                        {
                            float fDZ;
                            {
                                float fC;
                                {
                                    float fDet;
                                    {
                                        float fX0;
                                        {
                                            const NiPoint3* pVertex2;
                                            {
                                                float fX2;
                                                {
                                                    float fX1;
                                                    {
                                                        float fY1;
                                                        {
                                                            NavMeshTriangle* pTri;
                                                            {
                                                                const NiPoint3* pVertex1;
                                                                pTri = GetTriangle(ausTriangle);
                                                                pVertex0 = &(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pTri))->FUN_005582d0(0))));
                                                                pVertex1 = &(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pTri))->FUN_005582d0(1))));
                                                                pVertex2 = &(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pTri))->FUN_005582d0(2))));
                                                                fDet = (pVertex1->x - pVertex0->x) *
                                                                           (pVertex2->y - pVertex0->y) -
                                                                       (pVertex2->x - pVertex0->x) *
                                                                           (pVertex1->y - pVertex0->y);
                                                                if (fDet == 0.0)
                                                                    return false;
                                                                fX1 = pVertex1->x - arPoint.x;
                                                                fX2 = pVertex2->x - arPoint.x;
                                                                fY1 = pVertex1->y - arPoint.y;
                                                                fY2 = pVertex2->y - arPoint.y;
                                                                fInvDet = 1.0f / fDet;
                                                                fWeight0 = (fX1 * fY2 - fX2 * fY1) * fInvDet;
                                                                if (fWeight0 < 0.0)
                                                                    return false;
                                                                fX0 = pVertex0->x - arPoint.x;
                                                                fY0 = pVertex0->y - arPoint.y;
                                                                fWeight1 = (fX2 * fY0 - fX0 * fY2) * fInvDet;
                                                                if (fWeight1 < 0.0)
                                                                    return false;
                                                                fC = (fX0 * fY1 - fX1 * fY0) * fInvDet;
                                                                if (fC < 0.0)
                                                                    return false;
                                                                *apfHeight = fWeight0 * pVertex0->z +
                                                                             fWeight1 * pVertex1->z + fC * pVertex2->z;
                                                                fDZ = arPoint.z - *apfHeight;
                                                                if (fDZ > afAbove)
                                                                    return false;
                                                                else if (-afBelow > fDZ)
                                                                    return false;
                                                                return true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

namespace NavCircum {
struct NiPoint3
{
    float x, y, z;
};
}
// Computes the circumcenter of the triangle's three vertices in the XY plane and returns it with Z set to the highest vertex Z.
// @fnv 0x00697290
NiPoint3 NavMesh::FUN_00697290(unsigned short apTriangle)
{
    float xdo;
    float a2;
    NavCircum::NiPoint3 circumcenter;
    NavCircum::NiPoint3 p1;
    float denominator;
    NavCircum::NiPoint3 p2;
    float ydo;
    float xao;
    float b2;
    NavCircum::NiPoint3 p0;
    float yao;
    float numerator;
    float Z;
    p0 = *(const NavCircum::NiPoint3*)&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(apTriangle)))->FUN_005582d0(0))));
    p1 = *(const NavCircum::NiPoint3*)&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(apTriangle)))->FUN_005582d0(1))));
    p2 = *(const NavCircum::NiPoint3*)&(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(apTriangle)))->FUN_005582d0(2))));
    xdo = p1.x - p0.x;
    ydo = p1.y - p0.y;
    xao = p2.x - p0.x;
    yao = p2.y - p0.y;
    a2 = xdo * xdo + ydo * ydo;
    b2 = xao * xao + yao * yao;
    numerator = xdo * yao - xao * ydo;
    denominator = DAT_01011588 / numerator;
    Z = p2.z;
    if (p0.z >= p1.z && p0.z >= p2.z)
        Z = p0.z;
    else if (p1.z >= p2.z)
        Z = p1.z;
    reinterpret_cast<::FUN_00416870_t *>(&(circumcenter))->FUN_00416870(p0.x - (ydo * b2 - yao * a2) * denominator, (xdo * b2 - xao * a2) * denominator + p0.y, Z);
    return *(NiPoint3*)&circumcenter;
}

struct FUN_00698320_t : public NavMesh
{
    int FindCrossedEdge(unsigned short, int, const NiPoint3*, const NiPoint3*);
};

// Tests each triangle edge except aIgnoreEdge for intersection with the segment aStartPoint-aEndPoint and returns the first crossing edge index, or -1.
// @fnv 0x00698320
int FUN_00698320_t::FindCrossedEdge(unsigned short ausTri, int aIgnoreEdge, const NiPoint3* aStartPoint,
                                    const NiPoint3* aEndPoint)
{
    NiPoint3 edgeVerts[3];
    NavMeshTriangle* ptri = GetTriangle(ausTri);
    edgeVerts[0] = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(0))));
    edgeVerts[1] = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(1))));
    edgeVerts[2] = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((ptri))->FUN_005582d0(2))));
    for (int i = 0; i < 3; i++)
    {
        if (i == aIgnoreEdge)
            continue;
        int j = i + 1;
        if (j == 3)
            j = 0;
        float fa1 = (edgeVerts[i].x - aEndPoint->x) * (edgeVerts[j].y - aEndPoint->y) -
                    (edgeVerts[i].y - aEndPoint->y) * (edgeVerts[j].x - aEndPoint->x);
        float fa2 = (edgeVerts[i].x - aStartPoint->x) * (edgeVerts[j].y - aStartPoint->y) -
                    (edgeVerts[i].y - aStartPoint->y) * (edgeVerts[j].x - aStartPoint->x);
        float fa3 = (aStartPoint->x - edgeVerts[i].x) * (aEndPoint->y - edgeVerts[i].y) -
                    (aStartPoint->y - edgeVerts[i].y) * (aEndPoint->x - edgeVerts[i].x);
        float fa4 = (aStartPoint->x - edgeVerts[j].x) * (aEndPoint->y - edgeVerts[j].y) -
                    (aStartPoint->y - edgeVerts[j].y) * (aEndPoint->x - edgeVerts[j].x);
        if (fa1 * fa2 <= 0.0 && fa3 * fa4 <= 0.0)
        {
            if (fa1 == 0.0)
                continue;
            if (fa4 == 0.0)
                continue;
            return i;
        }
    }
    return -1;
}

namespace fnv_0069a830 {
struct ArrSI
{
};
struct DA00694f80
{
};
struct FUN_0069b0a0_shell
{
    bool LookupValue(unsigned short, unsigned int);
};
namespace S {
struct NiTPointerMap
{
};
}
struct GlobalObject_00869f00
{
};
struct FUN_0069a830_shell : NavMesh
{
    int CollectTrianglePOVs(unsigned short triangle, BSSimpleArray<unsigned short, 1024>* povs);
};

// @fnv 0x0069a830
int FUN_0069a830_shell::CollectTrianglePOVs(unsigned short triangle, BSSimpleArray<unsigned short, 1024>* povs)
{
    if (::IsFieldCZero((::Dummy_0069b080 *)(((S::NiTPointerMap*)&POVPointerArray))))
        reinterpret_cast<::FUN_00699b60_shell *>(this)->BuildPortalPOVs();
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)povs)))->Clear(false);
    int iAddedCount = 0;
    NavMeshTriangle* pNavTriangle = GetTriangle(triangle);
    for (int i = 0; i < 3; i++)
    {
        unsigned short m_usVertexId = reinterpret_cast<::FUN_005582d0_shell *>((pNavTriangle))->FUN_005582d0(i);
        unsigned int uiPOV;
        if (((FUN_0069b0a0_shell*)&POVPointerArray)->LookupValue(m_usVertexId, (unsigned int)&uiPOV))
        {
            reinterpret_cast<::FUN_00691820_arr *>((povs))->Append((const unsigned short *)&(m_usVertexId));
            iAddedCount++;
        }
    }
    if (triangle < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&m_kAdditionalIndexList)))->GetName())) &&
        reinterpret_cast<::FUN_005eeda0_this *>((((DA00694f80*)&m_kAdditionalIndexList)))->GetBufferEntry(triangle) != 0xFFFF)
    {
        reinterpret_cast<::FUN_00691820_arr *>((povs))->Append((const unsigned short *)&(reinterpret_cast<::FUN_005eeda0_this *>((((DA00694f80*)&m_kAdditionalIndexList)))->GetBufferEntry(triangle)));
        iAddedCount++;
    }
    return iAddedCount;
}
}  // namespace fnv_0069a830

struct Helper62d0
{
    void* operator=(const void*);
};

struct FUN_0069afb0_shell
{
    virtual void v0();
    virtual void* v1(unsigned short a);
    virtual bool v2(unsigned short a, unsigned short b);
    void* p;
    void** list;
    bool FUN_0069afb0(unsigned short a, Helper62d0& out);
};
// @fnv 0x006997b0
int S006997b0::FUN_006997b0(unsigned short a, intptr_t b)
{
    return ((int)(reinterpret_cast<::FUN_0069afb0_shell *>((p))->FUN_0069afb0(a, (*(::Helper62d0 *)(b)))));
}

// @fnv 0x0069afb0
bool FUN_0069afb0_shell::FUN_0069afb0(unsigned short a, Helper62d0& out)
{
    void* item = v1(a);
    void* node = list[*(unsigned int*)&item];
    while (node)
    {
        if (v2(a, *(unsigned short*)((char*)node + 4)))
        {
            out = (const char*)node + 8;
            return true;
        }
        node = *(void**)node;
    }
    return false;
}

namespace fnv_006be6f0 {
struct ArrSI
{
};
struct DA00694f80
{
};
struct NavMeshTriList
{
};
struct FUN_006be6f0_shell
{
    void MarkNavMeshTriangles();
};
// @fnv 0x006be6f0
void FUN_006be6f0_shell::MarkNavMeshTriangles()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)*(unsigned int**)((char*)this + 8) + 0x60))))->GetName())); i++)
    {
        int idx = reinterpret_cast<::FUN_0069b240_Holder *>((((NavMeshTriList*)((char*)*(unsigned int**)((char*)this + 0) + 0xe4))))->FindMatchingIndex((intptr_t)&(reinterpret_cast<::FUN_005eeda0_this *>((((DA00694f80*)((char*)*(unsigned int**)((char*)this + 8) + 0x60))))->GetBufferEntry(i)),
                                          0, (bool (*)(unsigned short *, intptr_t))(((bool (&)(const unsigned short &, const unsigned short &))::AreWideCharsEqual)));
        if (idx != -1)
            reinterpret_cast<::FUN_0069add0_class *>((((NavMeshTriList*)((char*)*(unsigned int**)((char*)this + 0) + 0xe4))))->FUN_0069add0(idx, true);
    }
}
}  // namespace fnv_006be6f0

namespace fnv_00697590 {
class ArrSI
{
  public:
};

struct _Mem_20a4
{
};

struct HArr
{
};

struct BSSimpleArrayActor
{
};

struct FUN_00690e10_shell
{
};

struct FUN_00693d30_shell
{
};

struct FUN_00697590_shell
{
    bool CollectTrianglesForDoor(unsigned int, BSSimpleArrayActor*);
};

// Clears the array, then adds each triangle index that has an edge whose linked door ID equals doorID, and returns whether any were added.
// @fnv 0x00697590
bool FUN_00697590_shell::CollectTrianglesForDoor(unsigned int doorID, BSSimpleArrayActor* array)
{
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((reinterpret_cast<_Mem_20a4*>(array)))->FUN_006f2290(0, true);
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>((reinterpret_cast<HArr*>(array)))->FUN_0084b5c0(100);

    for (unsigned int triangleIndex = 0;
         triangleIndex < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x38)))->GetName()));
         ++triangleIndex)
    {
        NavMeshTriangle* triangle =
            reinterpret_cast<NavMesh*>(this)->GetTriangle(static_cast<unsigned short>(triangleIndex));

        if (reinterpret_cast<::FUN_00690e10_shell *>((reinterpret_cast<FUN_00690e10_shell*>(triangle)))->FUN_00690e10())
        {
            for (int edgeIndex = 0; edgeIndex < 3; ++edgeIndex)
            {
                if (reinterpret_cast<::FUN_0068f1d0_shell *>((triangle))->IsEdgeFlagSet(edgeIndex))
                {
                    if (reinterpret_cast<unsigned int*>(reinterpret_cast<::FUN_00693d30_shell *>((reinterpret_cast<FUN_00693d30_shell*>(this)))->GetEdge(
                            reinterpret_cast<::FUN_0068f2c0_shell *>((triangle))->FUN_0068f2c0(edgeIndex)))[1] == doorID)
                    {
                        void* value;
                        value = reinterpret_cast<void*>(triangleIndex);
                        reinterpret_cast<::FUN_00438690 *>((array))->FUN_007cb2e0((unsigned int *)&(value));
                        break;
                    }
                }
            }
        }
    }

    return 0 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(array)))->GetName()));
}
}  // namespace fnv_00697590

namespace fnv_006995c0 {
struct ArrSI
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct GO
{
    operator unsigned int() const;
};
struct NiPointerStandIn
{
    bool operator==(void*) const;
};

struct FUN_006995c0_shell
{
    int FindEntryIndex(void* arg);
};

// Scans the array at offset 0xd0 and returns the index whose entry pointer at offset 0xc equals arg, or -1 if none matches.
// @fnv 0x006995c0
int FUN_006995c0_shell::FindEntryIndex(void* apTarget)
{
    unsigned int i = 0;
    for (; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0xd0))))->GetName())); ++i)
    {
        if (reinterpret_cast<::FUN_004b0460_class *>((void *)(((NiPointerStandIn*)(((GO*)((char*)((Arr*)((char*)this + 0xd0))->GetAt(i)))->operator unsigned int() + 0xc))))->FUN_004b0460==((const void **)(apTarget)))
            return i;
    }
    return -1;
}
}  // namespace fnv_006995c0

namespace fnv_006bbb80 {
extern int _data_011c16bc;

struct GO
{
    int value;

    GO(int);
    ~GO();
};

struct FUN_006bbc30
{
    int padding[4];

    FUN_006bbc30();
    ~FUN_006bbc30();

};

struct FUN_006bf7d0
{
    int padding[5];

    FUN_006bf7d0(int, int, int);
    ~FUN_006bf7d0();
};

struct FUN_006bfa10
{
    int padding[5];

    FUN_006bfa10(int, int, int);
};

struct FUN_006bbb80
{
    int base;
    GO go;
    int gap;
    FUN_006bbc30 memberC;
    FUN_006bf7d0 member1C;
    FUN_006bfa10 member30;

    FUN_006bbb80();
};

// Initializes the object's members, constructing go with 0 and member1C and member30 with 0x100, 0, and the result of memberC._ref_006815c0().
// @fnv 0x006bbb80
FUN_006bbb80::FUN_006bbb80()
    : go(0), memberC(), member1C(0x100, 0, ((int)(new ((void *)&(memberC)) ::Vec3()))), member30(0x100, 0, ((int)(new ((void *)&(memberC)) ::Vec3())))
{}
}  // namespace fnv_006bbb80

struct SwapTriangle : NavMeshTriangle
{
};

struct SwapMesh
{
    void SwapTriangleEdges(unsigned short triangle);
};

struct FUN_006957d0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
    bool FUN_006957d0();
};
// @fnv 0x00695660
void SwapMesh::SwapTriangleEdges(unsigned short triangle)
{
    SwapTriangle* tri5 = ((::SwapTriangle *)(reinterpret_cast<::NavMesh *>(this)->GetTriangle(triangle)));
    unsigned short vertex8 = reinterpret_cast<::FUN_005582d0_shell *>((tri5))->FUN_005582d0(1);
    reinterpret_cast<::FUN_00690df0_shell *>((tri5))->SetArrayElement(1, reinterpret_cast<::FUN_005582d0_shell *>((tri5))->FUN_005582d0(0));
    reinterpret_cast<::FUN_00690df0_shell *>((tri5))->SetArrayElement(0, vertex8);
    bool firstExternal3 = reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(0);
    bool secondExternalX = reinterpret_cast<::FUN_0068f1d0_shell *>((tri5))->IsEdgeFlagSet(1);
    unsigned short neighbor;
    if (secondExternalX)
        neighbor = reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(1);
    else
        neighbor = reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(1);
    if (firstExternal3)
        reinterpret_cast<::Unk00690e30 *>((tri5))->SetSlotValue(1, reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(0));
    else
        reinterpret_cast<::S6907D0 *>((tri5))->SetArrayValue(1, reinterpret_cast<::FUN_0068f2c0_shell *>((tri5))->FUN_0068f2c0(0));
    if (secondExternalX)
        reinterpret_cast<::Unk00690e30 *>((tri5))->SetSlotValue(0, neighbor);
    else
        reinterpret_cast<::S6907D0 *>((tri5))->SetArrayValue(0, neighbor);
    if (reinterpret_cast<::FUN_006957d0_Class *>((tri5))->FUN_006957d0())
    {
        unsigned short aFirstLink;
        unsigned short secondLinkB;
        unsigned char firstEdge8;
        unsigned char secondEdge9;
        unsigned char firstFlags;
        unsigned char secondFlags;
        reinterpret_cast<::FUN_00691040_shell *>((tri5))->GetPackedFlags(0, &aFirstLink, (bool *)(unsigned char *)(&firstEdge8), (bool *)(unsigned char *)(&firstFlags));
        reinterpret_cast<::FUN_00691040_shell *>((tri5))->GetPackedFlags(1, &secondLinkB, (bool *)(unsigned char *)(&secondEdge9), (bool *)(unsigned char *)(&secondFlags));
        reinterpret_cast<::FUN_006ad2f0_cls *>((tri5))->SetPackedField(0, secondLinkB, secondFlags, secondEdge9);
        reinterpret_cast<::FUN_006ad2f0_cls *>((tri5))->SetPackedField(1, aFirstLink, firstFlags, firstEdge8);
    }
}

// @fnv 0x006957d0
bool FUN_006957d0_Class::FUN_006957d0()
{
    return 0u < (unk0C & 0xFFF0000);
}

struct TriangleArrayLocal
{
};
struct Candidate
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    TriangleArrayLocal triangles;
    void ComputeBounds(NiPoint3& outMin, NiPoint3& outMax);
};
// @fnv 0x006957f0
void Candidate::ComputeBounds(NiPoint3& outMin, NiPoint3& outMax)
{
    if (reinterpret_cast<::FUN_0076b610_Class *>(&(triangles))->FUN_0076b610())
        return;
    NiPoint3 kMinimum;
    NiPoint3 _maximum;
    NiPoint3 _point;
    NavMeshTriangle* triangle5 = reinterpret_cast<::NavMesh *>(this)->GetTriangle(0);
    _maximum = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triangle5))->FUN_005582d0(0))));
    kMinimum = _maximum;
    for (unsigned int i = 0; i < ::FUN_00558200((char *)this); ++i)
    {
        triangle5 = reinterpret_cast<::NavMesh *>(this)->GetTriangle(static_cast<unsigned short>(i));
        for (int j = 0; j < 3; ++j)
        {
            _point = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triangle5))->FUN_005582d0(j))));
            if (_point.x < kMinimum.x)
                kMinimum.x = _point.x;
            else if (_point.x > _maximum.x)
                _maximum.x = _point.x;
            if (_point.y < kMinimum.y)
                kMinimum.y = _point.y;
            else if (_point.y > _maximum.y)
                _maximum.y = _point.y;
            if (_point.z < kMinimum.z)
                kMinimum.z = _point.z;
            else if (_point.z > _maximum.z)
                _maximum.z = _point.z;
        }
    }
    outMin = kMinimum;
    outMax = _maximum;
}

class Pt3
{
  public:
    float x, y, z;
    Pt3 operator+(const Pt3&) const;
    Pt3 operator*(float) const;
    Pt3 operator-(const Pt3&) const;
};

struct NavEdgeVerts
{
    const Pt3* first;
    const Pt3* second;
};

class NavTri
{
  public:
};

class NavTriArray
{
  public:
};

class NavMeshA
{
  public:
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
    NavTriArray Triangles;
    NavTri* GetTriangle(unsigned short);
    NavEdgeVerts FUN_0068f040(unsigned short, int);
    bool FUN_00697010(const Pt3& arPoint, float afRadius, unsigned short* apTri, int* apEdge, bool abFlip);
};

// @fnv 0x00697010
bool NavMeshA::FUN_00697010(const Pt3& arPoint, float afRadius, unsigned short* apTri, int* apEdge, bool abFlip)
{
    unsigned short usBestTri5 = 0;
    int iBestEdge = -1;
    float fBest2 = 3.402823466e+38f;
    float fRadiusSq2 = afRadius * afRadius;
    float fMinZ8 = arPoint.z - 64.0;
    float fMaxZ7 = arPoint.z + 180.0;
    if (abFlip)
    {
        fMinZ8 = arPoint.z - 180.0;
        fMaxZ7 = arPoint.z + 64.0;
    }
    unsigned int uiCount5 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(Triangles))->GetName()));
    for (unsigned int i5 = 0; i5 < uiCount5; i5++)
    {
        NavTri* pTri_ = ((::NavTri *)(reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)i5)));
        for (int jTmp = 0; jTmp < 3; jTmp++)
        {
            if (!reinterpret_cast<::FUN_0068f200_shell *>((pTri_))->FUN_0068f200(jTmp))
            {
                NavEdgeVerts verts8 = FUN_0068f040((unsigned short)i5, jTmp);
                Pt3 mid3 = (*verts8.first + *verts8.second) * 0.5f;
                Pt3 diff = mid3 - arPoint;
                float fDist2D = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(diff))->GetSquaredXYLength();
                float fDZ = diff.z * diff.z;
                float fDist_2 = fDist2D + fDZ;
                if (fDist2D < fBest2 && ((mid3.z < fMaxZ7 && mid3.z > fMinZ8) || fDist_2 <= fRadiusSq2 - fDZ))
                {
                    usBestTri5 = (unsigned short)i5;
                    iBestEdge = jTmp;
                    fBest2 = fDist_2;
                }
            }
        }
    }
    if (iBestEdge == -1)
        return false;
    *apTri = usBestTri5;
    *apEdge = iBestEdge;
    return true;
}

struct FUN_00697440_t : public NavMesh
{
    void FUN_00697440(unsigned short ausTriangle, NiPoint3* apCenter);
};

// Computes the 2D circumcenter of the triangle's three vertices and writes it into apCenter with z set to 0.
// @fnv 0x00697440
void FUN_00697440_t::FUN_00697440(unsigned short ausTriangle, NiPoint3* apCenter)
{
    NiPoint3 kA = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(ausTriangle)))->FUN_005582d0(0))));
    NiPoint3 kB9 = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(ausTriangle)))->FUN_005582d0(1))));
    NiPoint3 kC2 = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(ausTriangle)))->FUN_005582d0(2))));
    float fDX = kB9.x - kA.x;
    float fB8 = kB9.y - kA.y;
    float fC = kC2.x - kA.x;
    float fCy3 = kC2.y - kA.y;
    float fLenB = fDX * fDX + fB8 * fB8;
    float fLen8 = fC * fC + fCy3 * fCy3;
    float fDenom = fDX * fCy3 - fC * fB8;
    float fScale = 0.5 / fDenom;
    apCenter->x = kA.x - (fB8 * fLen8 - fCy3 * fLenB) * fScale;
    apCenter->y = (fDX * fLen8 - fC * fLenB) * fScale + kA.y;
    apCenter->z = 0.0f;
}

// NavMesh: get the extra info for a triangle edge, creating and linking a fresh record when missing,
// then reset its link fields.

struct D76A0EdgeExtraInfo
{
    int m_iType;
    void* m_pkPortal;
    unsigned short m_usLinkedTriangle;
    D76A0EdgeExtraInfo();
};

struct D76A0Triangle
{
};

struct D76A0TriangleArray
{
    D76A0Triangle& GetAt(int iIndex) const;
};

class D76A0NavMesh
{
  public:
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
    D76A0TriangleArray m_kTriangles;

    unsigned short AddEdgeInfo(const D76A0EdgeExtraInfo& kInfo);
    D76A0EdgeExtraInfo* GetOrCreateEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber);
};

// Returns the edge extra info for a triangle edge, creating it if missing, then clears its portal and linked triangle.
// @fnv 0x006976a0
D76A0EdgeExtraInfo* D76A0NavMesh::GetOrCreateEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber)
{
    D76A0EdgeExtraInfo* pkInfo = ((::D76A0EdgeExtraInfo *)(reinterpret_cast<::FUN_0068f230_shell *>(this)->FUN_0068f230(m_usTriangleID, m_iEdgeNumber)));
    if (!pkInfo)
    {
        D76A0EdgeExtraInfo kNewInfo;
        reinterpret_cast<::Unk00690e30 *>(&(m_kTriangles.GetAt(m_usTriangleID)))->SetSlotValue(m_iEdgeNumber, AddEdgeInfo(kNewInfo));
        pkInfo = ((::D76A0EdgeExtraInfo *)(reinterpret_cast<::FUN_0068f230_shell *>(this)->FUN_0068f230(m_usTriangleID, m_iEdgeNumber)));
    }
    pkInfo->m_pkPortal = 0;
    pkInfo->m_usLinkedTriangle = 0xffff;
    return pkInfo;
}

struct TriangleList
{
};
struct TriangleGrid
{
    void GetTriListAtPosition(const NiPoint3& point, TriangleList*& triangles);
};
struct Target : NavMesh
{
    TriangleGrid grid;
    bool FindTriangleZ(const NiPoint3& point, float above, float below, float* z);
};
struct FUN_006986d0_cls;


struct b9_big
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58;
    b9_big();
};

struct b9_nav
{
};

struct b9_tab
{
};


struct FUN_006986d0_cls
{
    bool FUN_006986d0();
};

// @fnv 0x006986d0
bool FUN_006986d0_cls::FUN_006986d0()
{
    b9_nav* r = ((::b9_nav *)(reinterpret_cast<::Pathing *>((((::b9_nav *)(reinterpret_cast<::Owner45A *>((((b9_tab*)::g_TES)))->FUN_0045af00()))))->FindReferenceByFormId({})));
    if (((int)(reinterpret_cast<::FUN_0068efb0_shell *>((this))->FUN_0068efb0())) == 0)
    {
        b9_big* q = new b9_big();
        reinterpret_cast<::NavInfo *>((q))->InitializeFromMeshSource((::MeshSource *)(::FUN_006986d0_cls *)(this));
        reinterpret_cast<::HX *>((this))->FUN_006d3100((::CombatCoverPointData *)(q));
        reinterpret_cast<::FUN_005a8040_class *>((q))->SetField54((int)(this));
        reinterpret_cast<::StandInSearch *>((((::b9_nav *)(reinterpret_cast<::Owner45A *>((((b9_tab*)::g_TES)))->FUN_0045af00()))))->RegisterNavMeshInfo({});
        return true;
    }
    else
    {
        reinterpret_cast<::NavInfo *>((r))->InitializeFromMeshSource((::MeshSource *)(::FUN_006986d0_cls *)(this));
        return false;
    }
}

struct SearchContext
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    SearchContext();
    ~SearchContext();
};
struct NavMeshSearch
{
    bool Search(int first, int second);
};
struct FUN_006993c0_sub
{
    int unk00, unk04, unk08, unk0c;
    ~FUN_006993c0_sub();
};

struct FUN_006993c0_local
{
    FUN_006993c0_sub a;
    FUN_006993c0_sub b;
    FUN_006993c0_local();
    ~FUN_006993c0_local();
};

struct Dummy0044ddc0_sub
{
};

struct FUN_006993c0_cls
{
    unsigned char unk00[0xd0];
    Dummy0044ddc0_sub unkD0;

    void FUN_006993c0();
};

unsigned int __cdecl MaxUnsigned(unsigned int uiHash, unsigned short usValue);

class B99690Triangle
{
  public:
};

class B99690IndexArray
{
  public:

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B99690Edge
{
    unsigned short m_usTriangle;
};

class B99690EdgeArray
{
  public:
    B99690Edge* GetAt(unsigned int uiIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B99690Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    B99690IndexArray m_kTriangles;
    B99690EdgeArray m_kEdges;
};

class B99690NavMesh
{
  public:
    B99690Triangle* GetTriangle(unsigned short usIndex);
    unsigned int ComputeTriangleHash(B99690Info* pkInfo);
};

// Hashes the triangle values of all triangles and edge triangles referenced by pkInfo and returns the accumulated hash.
// @fnv 0x00699690
unsigned int B99690NavMesh::ComputeTriangleHash(B99690Info* pkInfo)
{
    unsigned int uiHash = 0;
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkInfo->m_kTriangles))->GetName())); i++)
        uiHash = MaxUnsigned(uiHash, ((unsigned short)(reinterpret_cast<::FUN_00699790_shell *>((((::B99690Triangle *)(reinterpret_cast<::NavMesh *>(this)->GetTriangle(reinterpret_cast<::FUN_005eeda0_this *>(&(pkInfo->m_kTriangles))->GetBufferEntry(i))))))->GetBits13To15())));
    for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkInfo->m_kEdges))->GetName())); j++)
        uiHash = MaxUnsigned(uiHash, ((unsigned short)(reinterpret_cast<::FUN_00699790_shell *>((((::B99690Triangle *)(reinterpret_cast<::NavMesh *>(this)->GetTriangle(pkInfo->m_kEdges.GetAt(j)->m_usTriangle)))))->GetBits13To15())));
    return uiHash;
}

struct FUN_0069b0a0_item
{
    FUN_0069b0a0_item* next;
    unsigned short key;
    unsigned char pad[2];
    unsigned int val;
};
struct U4v
{
    unsigned int v;
};
class FUN_0069b0a0_cls
{
  public:
    virtual unsigned int GetPad();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeyEqual(unsigned short a, unsigned short b);
    unsigned int m_uiHashSize;
    FUN_0069b0a0_item** m_ppkHashTable;
    unsigned int m_uiCount;
    bool LookupValue(unsigned short key, unsigned int* out);
};
// @fnv 0x0069a9d0
void FUN_0069a9d0_shell::FUN_0069a9d0(unsigned short a1, unsigned int a2)
{
    if (::IsFieldCZero((::Dummy_0069b080 *)(((NiTPointerMap<unsigned int, SoundPlaybackHandle*>*)((char*)this + 0x88)))))
        reinterpret_cast<::FUN_00699b60_shell *>(this)->BuildPortalPOVs();
    reinterpret_cast<::FUN_0069b0a0_cls *>((((FUN_0069b0a0_shell*)((char*)this + 0x88))))->LookupValue(a1, (unsigned int *)(a2));
}
// Hashes key, walks the bucket chain comparing keys, and on a match copies the item's value to out and returns true; otherwise returns false.
// @fnv 0x0069b0a0
bool FUN_0069b0a0_cls::LookupValue(unsigned short key, unsigned int* puiOut)
{
    unsigned int uiBucketIndex = KeyToHashIndex(key);
    FUN_0069b0a0_item* pItem = m_ppkHashTable[uiBucketIndex];
    while (pItem != 0)
    {
        if (IsKeyEqual(key, pItem->key))
        {
            *(U4v*)puiOut = *(U4v*)((char*)pItem + 6);
            return true;
        }
        pItem = pItem->next;
    }
    return false;
}

struct ItemResource
{
};

struct ResourceHolder
{
};

struct Item
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    ResourceHolder resource;
};

struct ItemPointer
{
    Item* item;
};

struct FUN_0045cec0
{
    int first;
    int second;
    ~FUN_0045cec0();
};

struct FUN_00982610
{
    int first;
    int second;
    int third;
    int fourth;
    ~FUN_00982610();
};

struct FUN_006bf890
{
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    ~FUN_006bf890();
};

struct FUN_006bfad0
{
    ItemPointer* entries;
    unsigned int count;
    unsigned int capacity;
    unsigned int flags;

    ItemPointer* FUN_00877a30(unsigned int index);
    ~FUN_006bfad0();
};

struct FUN_006bbc50
{
    int identifier;
    FUN_0045cec0 first;
    FUN_00982610 second;
    FUN_006bf890 third;
    FUN_006bfad0 fourth;
    ~FUN_006bbc50();
};

// Iterates the fourth container's entries and calls FUN_00401970 on each item's resource when FUN_00559450 returns non-null.
// @fnv 0x006bbc50
FUN_006bbc50::~FUN_006bbc50()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(fourth))->GetName())); ++i)
    {
        if (((::ItemResource *)(::FUN_00559450((int *)&(fourth.FUN_00877a30(i)->item->resource)))))
        {
            reinterpret_cast<::WaitableObject *>((((::ItemResource *)(::FUN_00559450((int *)&(fourth.FUN_00877a30(i)->item->resource))))))->FUN_00401970();
        }
    }
}


struct FUN_006bf220_owner
{
};

struct FUN_006bf220_sub
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    BSSimpleArray<unsigned short> Items;
};

struct FUN_006bf220_cls
{
    FUN_006bf220_owner* m_00;
    int unk04;
    FUN_006bf220_sub* m_08;
    bool FUN_006bf220(void* a1);
};

// @fnv 0x006bf220
bool FUN_006bf220_cls::FUN_006bf220(void* a1)
{
    float local;
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_08->Items))->GetName())); i++)
    {
        if (reinterpret_cast<::NavMesh *>((m_00))->FindHeightOnTriangle(reinterpret_cast<::FUN_005eeda0_this *>(&(m_08->Items))->GetBufferEntry(i), (*(const ::NiPoint3 *)(a1)), local, ::DAT_0106b158, ::DAT_0106b158))
        {
            return true;
        }
    }
    return false;
}

class TESForm
{
  public:
    virtual void v0();
};
struct P507Array
{
    void* table;
    void* data;
    unsigned int size, capacity;
    void** FUN_00877a30(unsigned int);
};
class SA0 : public P507Array
{
  public:
    SA0();
    ~SA0();
};
struct P507Info
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    P507Array first, second;
};
struct P507Manager
{
    void FUN_006b7910();
};
struct P507Global
{
};

struct P507Edge
{
    int unk00;
    unsigned int owner;
};
struct P507Mesh
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void SetChanged(bool);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    P507Array edges;
};
struct NavMeshPtr
{
    NavMesh* object;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NiPointer<NavMesh>&);
    void* FUN_00458b50();
public:
    ::NavMeshPtr &operator=(const ::NavMeshPtr &);
};
// @fnv 0x006953b0
void __cdecl RemoveNavMeshId(unsigned int id)
{
    if (!id)
        return;
    SA0 infos;
    ((::P507Manager *)(reinterpret_cast<::Owner45A *>((((P507Global*)::g_TES)))->FUN_0045af00()))->FUN_006b7910();
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(infos))->GetName())); ++i)
    {
        P507Info* firstCount = (P507Info*)*infos.FUN_00877a30(i);
        int info = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(firstCount->first))->GetName()));
        int secondCount = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(firstCount->second))->GetName()));
        for (int j = 0; j < info + secondCount; ++j)
        {
            unsigned int entry;
            if (j < info)
                entry = (unsigned int)*firstCount->first.FUN_00877a30(j);
            else
                entry = (unsigned int)*firstCount->second.FUN_00877a30(j - info);
            if (entry == id)
            {
                NavMeshPtr mesh;
                if (!reinterpret_cast<::NavMeshInfo *>((firstCount))->AcquireNavMesh(mesh))
                {
                    TESForm* nav = FUN_004839c0(((unsigned int)(::FUN_00559450((int *)(firstCount)))));
                    NavMesh* form = dynamic_cast<NavMesh*>(nav);
                    reinterpret_cast<::NavMeshPtr *>((void *)&(const ::NavMeshPtr &)(mesh))->operator=((const ::NavMeshPtr &)((const ::NiPointer< ::NavMesh> &)(MakeNavMeshPointer(form))));
                }
                if (mesh.FUN_00458b50())
                {
                    ((::P507Mesh *)(::FUN_00559450((int *)&(mesh))))->SetChanged(true);
                    for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::P507Mesh *)(::FUN_00559450((int *)&(mesh))))->edges))->GetName())); ++k)
                    {
                        P507Edge* edge = ((::P507Edge *)(reinterpret_cast<::FUN_00693d30_shell *>((((::P507Mesh *)(::FUN_00559450((int *)&(mesh))))))->GetEdge((unsigned short)k)));
                        if (edge->owner == id)
                        {
                            reinterpret_cast<::fnv_00690e90::FUN_00690e90_shell *>((((::P507Mesh *)(::FUN_00559450((int *)&(mesh))))))->UpdateTriangleExtraInfo((unsigned short)k);
                            --k;
                        }
                    }
                }
                if (j < info)
                {
                    reinterpret_cast<::FUN_006bf8f0_Class *>(&(firstCount->first))->FUN_006bf8f0(j, true);
                    --info;
                }
                else
                {
                    reinterpret_cast<::FUN_006bf8f0_Class *>(&(firstCount->second))->FUN_006bf8f0(j - info, true);
                    --secondCount;
                }
                --j;
            }
        }
    }
}


struct NavMeshTriListAdd
{
};
struct NavMeshGridR
{
};
struct NiPoint3R : public NiPoint3
{
    NiPoint3R(float afX, float afY, float afZ);
};
struct NavMeshGridOwner : public NavMesh
{
    NavMeshGridR Grid;
    bool AddTrianglesToGrid(unsigned short ausStart, unsigned short ausEnd);
};

// For each triangle index in [ausStart, ausEnd], computes its XY bounds, maps them to grid rows/columns and adds the index to every overlapping cell list.
// @fnv 0x006965d0
bool NavMeshGridOwner::AddTrianglesToGrid(unsigned short ausStart, unsigned short ausEnd)
{
    for (unsigned int i = ausStart; i <= ausEnd; i++)
    {
        NavMeshTriangle* pTri_ = GetTriangle((unsigned short)i);
        NiPoint3R kMinBoundsCur(::DAT_01016970, ::DAT_01016970, 0.0f);
        NiPoint3R kMaxB(::DAT_01015f5c, ::DAT_01015f5c, 0.0f);
        for (int jVal = 0; jVal < 3; jVal++)
        {
            const NiPoint3& _kPt = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pTri_))->FUN_005582d0(jVal))));
            if (_kPt.x < kMinBoundsCur.x)
                kMinBoundsCur.x = _kPt.x;
            if (_kPt.x > kMaxB.x)
                kMaxB.x = _kPt.x;
            if (_kPt.y < kMinBoundsCur.y)
                kMinBoundsCur.y = _kPt.y;
            if (_kPt.y > kMaxB.y)
                kMaxB.y = _kPt.y;
        }
        unsigned int uiMinRow = 0;
        unsigned int kUiMinCol = 0;
        unsigned int uiMaxRow = 0;
        unsigned int uiMaxCol3 = 0;
        reinterpret_cast<::NavMeshGridX *>(&(Grid))->GetCellCoords(kMinBoundsCur, uiMinRow, kUiMinCol);
        reinterpret_cast<::NavMeshGridX *>(&(Grid))->GetCellCoords(kMaxB, uiMaxRow, uiMaxCol3);
        for (unsigned int uiRow = uiMinRow; uiRow <= uiMaxRow; uiRow++)
        {
            for (unsigned int uiCol9 = kUiMinCol; uiCol9 <= uiMaxCol3; uiCol9++)
            {
                NavMeshTriListAdd* pList5 = ((::NavMeshTriListAdd *)(reinterpret_cast<::FUN_006967c0_shell *>(&(Grid))->FUN_006967c0(uiCol9, uiRow)));
                if (!pList5)
                    continue;
                reinterpret_cast<::FUN_00691820_arr *>((pList5))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)i));
            }
        }
    }
    return true;
}

struct TriList2 : public NavMeshTriList
{
};
struct Ov2 : public NavMeshOverlap
{
    bool FUN_006967f0(unsigned short ausStart, unsigned short ausEnd);
};
// For each triangle index from ausStart to ausEnd, computes its XY bounds, finds the grid cells it spans and marks the triangle in each cell's list.
// @fnv 0x006967f0
bool Ov2::FUN_006967f0(unsigned short ausStart, unsigned short ausEnd)
{
    unsigned int i;
    for (i = ausStart; i <= ausEnd; i++)
    {
        NavMeshTriangle* pTri = GetTriangle((unsigned short)i);
        NiPoint3Ex fStack_14(::DAT_01016970, ::DAT_01016970, 0.0f);
        NiPoint3Ex f(::DAT_01015f5c, ::DAT_01015f5c, 0.0f);
        for (int j = 0; j < 3; j++)
        {
            const NiPoint3* pV = &(*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((pTri))->FUN_005582d0(j))));
            if (pV->x < fStack_14.x)
                fStack_14.x = pV->x;
            if (pV->x > f.x)
                f.x = pV->x;
            if (pV->y < fStack_14.y)
                fStack_14.y = pV->y;
            if (pV->y > f.y)
                f.y = pV->y;
        }
        unsigned int j = 0, cf = 0, b = 0, p = 0;
        reinterpret_cast<::NavMeshGridX *>(&(Grid))->GetCellCoords(fStack_14, j, cf);
        reinterpret_cast<::NavMeshGridX *>(&(Grid))->GetCellCoords(f, b, p);
        for (unsigned int r = j; r <= b; r++)
        {
            for (unsigned int c = cf; c <= p; c++)
            {
                int idx;
                TriList2* pList = (TriList2*)((::NavMeshTriList *)(reinterpret_cast<::FUN_006967c0_shell *>(&(Grid))->FUN_006967c0(c, r)));
                idx = reinterpret_cast<::FUN_0069b240_Holder *>((pList))->FindMatchingIndex((intptr_t)&(*(unsigned short*)&i), 0, (bool (*)(unsigned short *, intptr_t))(((bool (&)(const unsigned short &, const unsigned short &))::FUN_0069b2a0)));
                reinterpret_cast<::FUN_0069add0_class *>((pList))->FUN_0069add0(idx, 1);
            }
        }
    }
    return true;
}

namespace fnv_00696a50 {
struct S006949d0
{
};
struct FUN_00696a50_Grid
{
    void GetTriListAtPosition(const NiPoint3* apPos, NavMeshTriList** appList);
};
struct FUN_00696a50_HeightSource
{
};
struct FUN_00696a50_View
{
    char pad00[0x24];
    FUN_00696a50_HeightSource* pHeightSource;
    char pad28[0x10];
    S006949d0 kTriangles;
};
struct FUN_00696a50_shell : public NavMesh
{
    FUN_00696a50_Grid kGrid;
    unsigned short FUN_00696a50(const NiPoint3* apPos, int aiArg);
};
// @fnv 0x00696a50
unsigned short FUN_00696a50_shell::FUN_00696a50(const NiPoint3* apPos, int aiArg)
{
    NavMeshTriList* pCell = 0;
    kGrid.GetTriListAtPosition(apPos, &pCell);
    unsigned short usBestTmp = 0xffff;
    if (!pCell)
        return 0xffff;
    unsigned int uiEntries = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((void *)(pCell))->GetName()));
    float fPointHeight = ::DAT_01016970;
    float m_fGlyphExtent = ::DAT_01015f5c;
    if (((FUN_00696a50_View*)this)->pHeightSource)
        reinterpret_cast<::fnv_00547250::FUN_00547250_shell *>((((FUN_00696a50_View*)this)->pHeightSource))->CheckWaterHeight((void *)(apPos), &m_fGlyphExtent);
    bool bBelowGround = apPos->z < (float)(m_fGlyphExtent + 50.0);
    for (unsigned int i = 0; i < uiEntries; i++)
    {
        unsigned short usTri = reinterpret_cast<::FUN_0069dec0_class *>((void *)(pCell))->FUN_0069dec0(i);
        if (reinterpret_cast<::FUN_00691140_shell *>((((NavMeshTriangleEx*)((void *)(reinterpret_cast<::FUN_00558dd0_class *>(&(((FUN_00696a50_View*)this)->kTriangles))->FUN_00558dd0(usTri))))))->FUN_00691140(0x20))
            continue;
        float fDistance;
        if (reinterpret_cast<::fnv_00697810::FUN_00697810_t *>(this)->TestPointOnTriangle(usTri, (*(const ::NiPoint3 *)(apPos)), (*(float *)(&fDistance)), (::fnv_00697810::NavCallback_00697810 *)(aiArg)))
        {
            if (!bBelowGround && fDistance < -180.0)
                continue;
            if (fDistance > ::DAT_010240c0)
                continue;
            fDistance = std::abs(fDistance);
            if (fDistance < fPointHeight)
            {
                if (fDistance < 40.0)
                    return usTri;
                usBestTmp = usTri;
                fPointHeight = fDistance;
            }
        }
    }
    return usBestTmp;
}
}  // namespace fnv_00696a50

namespace fnv_00696cf0 {
struct TriArr696
{
    void* m_00;
    void* m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct Len696 : public NiPoint3
{
};
struct Host696
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c, m_30, m_34;
    TriArr696 m_38;
    int m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64;
    int m_68, m_6c, m_70, m_74, m_78, m_7c, m_80, m_84;
    int m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    TriangleGrid m_a8;
    bool FUN_00696cf0(const NiPoint3& point, unsigned short* outTri, bool* outFlag);
};

// @fnv 0x00696cf0
bool Host696::FUN_00696cf0(const NiPoint3& point, unsigned short* outTri, bool* outFlag)
{
    unsigned short d2;
    unsigned short i;
    {
        float bestSq;
        TriangleList* q;
        bestSq = ::DAT_01016970;
        d2 = 0xffff;
        i = 0xffff;
        q = 0;
        m_a8.GetTriListAtPosition(point, q);
        if (q)
        {
            unsigned int triSq = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((q))->GetName()));
            float bestD = ::DAT_01016970;
            float f;
            unsigned int e;
            for (e = 0; e < (int)triSq; e++)
            {
                unsigned short pObj = reinterpret_cast<::FUN_0069dec0_class *>((q))->FUN_0069dec0(e);
                if (reinterpret_cast<::FUN_00691140_shell *>((((::NavMeshTriangleEx *)(reinterpret_cast<::FUN_00558dd0_class *>(&(m_38))->FUN_00558dd0(pObj)))))->FUN_00691140(0x20))
                    continue;
                if (reinterpret_cast<::NavMesh *>(this)->FindHeightOnTriangle(pObj, (*(const ::NiPoint3 *)((void*)&point)), f, 180.0f, 64.0f))
                {
                    f = std::abs(f);
                    if (f < bestD)
                    {
                        if (f < 40.0)
                        {
                            *outTri = pObj;
                            *outFlag = true;
                            return true;
                        }
                        i = pObj;
                        bestD = f;
                    }
                }
                else
                {
                    NiPoint3 bestD2 = reinterpret_cast<::NavMesh *>(this)->GetNavMeshData(pObj) - point;
                    float list = reinterpret_cast<::TESCombatStyle *>((void *)(((Len696*)&bestD2)))->UpdateCombatStyle();
                    if (list < bestSq)
                    {
                        d2 = pObj;
                        bestSq = list;
                    }
                }
            }
            if (i != 0xffff)
            {
                *outTri = i;
                *outFlag = true;
                return true;
            }
        }
        else
        {
            unsigned int nn = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_38))->GetName()));
            unsigned int t;
            float n = ::DAT_01016970;
            float s;
            for (t = 0; t < (int)nn; t++)
            {
                if (reinterpret_cast<::NavMesh *>(this)->FindHeightOnTriangle((unsigned short)t, (*(const ::NiPoint3 *)((void*)&point)), s, 180.0f, 64.0f))
                {
                    s = std::abs(s);
                    if (s < n)
                    {
                        if (s < 40.0)
                        {
                            *outTri = (unsigned short)t;
                            *outFlag = true;
                            return true;
                        }
                        i = (unsigned short)t;
                        n = s;
                    }
                }
                else
                {
                    NiPoint3 count2 = reinterpret_cast<::NavMesh *>(this)->GetNavMeshData((unsigned short)t) - point;
                    float sq2;
                    sq2 = reinterpret_cast<::TESCombatStyle *>((void *)(((Len696*)&count2)))->UpdateCombatStyle();
                    if (sq2 < bestSq)
                    {
                        d2 = (unsigned short)t;
                        bestSq = sq2;
                    }
                }
            }
        }
        if (i != 0xffff)
        {
            *outTri = i;
            *outFlag = true;
            return true;
        }
    }
    if (d2 == 0xffff)
    {
        *outTri = 0xffff;
        *outFlag = false;
        return false;
    }
    *outTri = d2;
    *outFlag = false;
    return true;
}
}  // namespace fnv_00696cf0

struct AdjustPointOps : NiPoint3
{
    NiPoint3 ApplyScaled(float scale) const;
};
float __cdecl FUN_006b9940(const NiPoint3& point, const NiPoint3& first, const NiPoint3& second);
struct NavMeshAdjust : FUN_00697670_StandIn
{
    NiPoint3 AdjustPointToNavMesh(const NiPoint3& point, float radius);
};
// @fnv 0x00697d40
NiPoint3 NavMeshAdjust::AdjustPointToNavMesh(const NiPoint3& point, float radius)
{
    NiPoint3 adjusted = point;
    unsigned short triangle = reinterpret_cast<::fnv_00696a50::FUN_00696a50_shell *>(this)->FUN_00696a50((const ::NiPoint3 *)&(point), (int)(0));
    if (triangle != 0xffff)
    {
        unsigned short neighbours[3];
        NavMeshTriangle* triangleData;
        {
            unsigned short count = 0;
            triangleData = GetTriangle(triangle);
            for (int edge = 0; edge < 3; ++edge)
            {
                unsigned short neighbour = 0xffff;
                if (!reinterpret_cast<::FUN_0068f1d0_shell *>((triangleData))->IsEdgeFlagSet(edge))
                    neighbour = reinterpret_cast<::FUN_0068f2c0_shell *>((triangleData))->FUN_0068f2c0(edge);
                if (neighbour != 0xffff)
                {
                    neighbours[count] = neighbour;
                    ++count;
                }
                else
                {
                    NavMeshEdgeVertexPair vertices = FUN_0068f040(triangle, edge);
                    float distance = FUN_006b9940(point, *vertices.first, *vertices.second);
                    if (distance < radius)
                    {
                        NiPoint3 normal = reinterpret_cast<::NavMesh *>(this)->GetPlaneNormal(triangle);
                        NiPoint3 direction = normal.Cross(*vertices.first - *vertices.second);
                        reinterpret_cast<::FUN_004a0c10_s *>(&(((AdjustPointOps&)direction)))->FUN_004a0c10();
                        reinterpret_cast<::FUN_0063c8a0_shell *>(&(((AdjustPointOps&)adjusted)))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(((AdjustPointOps&)direction).ApplyScaled(radius - distance)));
                    }
                }
            }
            for (unsigned int index = 0; index < count; ++index)
            {
                NavMeshTriangle* triangleData = GetTriangle(neighbours[index]);
                for (int edge = 0; edge < 3; ++edge)
                {
                    if (!reinterpret_cast<::FUN_0068f1d0_shell *>((triangleData))->IsEdgeFlagSet(edge) && reinterpret_cast<::FUN_0068f2c0_shell *>((triangleData))->FUN_0068f2c0(edge) == 0xffff)
                    {
                        NavMeshEdgeVertexPair vertices = FUN_0068f040(neighbours[index], edge);
                        float distance = FUN_006b9940(point, *vertices.first, *vertices.second);
                        if (distance < radius)
                        {
                            NiPoint3 normal = reinterpret_cast<::NavMesh *>(this)->GetPlaneNormal(neighbours[index]);
                            NiPoint3 direction = normal.Cross(*vertices.first - *vertices.second);
                            reinterpret_cast<::FUN_004a0c10_s *>(&(((AdjustPointOps&)direction)))->FUN_004a0c10();
                            reinterpret_cast<::FUN_0063c8a0_shell *>(&(((AdjustPointOps&)adjusted)))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(((AdjustPointOps&)direction).ApplyScaled(radius - distance)));
                        }
                    }
                }
            }
        }
    }
    return adjusted;
}

struct NiPoint3Cmp : public NiPoint3
{
};

struct NavEdgeHit
{
    int iType;
    int m_iEdgeNumber;
    NiPoint3 kPoint;
    NavEdgeHit();
};


struct FUN_00698160_t : public NavMesh
{
    NavEdgeHit FindEdgeIntersection(unsigned short ausTriangle, int aiSkipEdge, const NiPoint3& arFrom,
                                    const NiPoint3& arTo);
};

// Tests the triangle's edges (skipping aiSkipEdge) for an intersection with the segment arFrom-arTo and returns the hit edge index and point, or a type-0 miss.
// @fnv 0x00698160
NavEdgeHit FUN_00698160_t::FindEdgeIntersection(unsigned short ausTriangle, int aiSkipEdge, const NiPoint3& arFrom,
                                                const NiPoint3& arTo)
{
    NiPoint3 verts[3];
    NiPoint3 flat = arTo;
    flat.z = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        verts[i] = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((GetTriangle(ausTriangle)))->FUN_005582d0(i))));
    }
    for (int j = 0; j < 3; j++)
    {
        if (j == aiSkipEdge)
            continue;
        int next = j + 1;
        if (next == 3)
            next = 0;
        if (reinterpret_cast<::NiPoint3 *>((void *)&(((NiPoint3Cmp&)verts[j])))->FUN_004390c0(verts[next]))
            continue;
        NavEdgeHit hit;
        if (::FUN_006ba240((const ::ThreeDimensionalVector *)&(verts[j]), (const ::ThreeDimensionalVector *)&(verts[next]), (const ::ThreeDimensionalVector *)&(arFrom), (const ::ThreeDimensionalVector *)&(arTo), (::ThreeDimensionalVector *)(::NiPoint3 *)(&hit.kPoint)))
        {
            hit.iType = 3;
            hit.m_iEdgeNumber = j;
            return hit;
        }
    }
    NavEdgeHit none;
    none.iType = 0;
    none.m_iEdgeNumber = -1;
    return none;
}

struct UndoOwner;
struct SavedMesh
{
    void* object;
    SavedMesh();
    ~SavedMesh();
    SavedMesh& operator=(const SavedMesh&);
};
struct UndoEntry
{
    int unk00, unk04;
    int type;
    SavedMesh mesh;
};
struct UndoPtr
{
};
struct UndoArray
{
    UndoPtr& At(unsigned int);
};
struct UndoContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    UndoContext();
    ~UndoContext();
};
struct UndoOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    UndoArray entries;
    bool UndoToPosition(unsigned int position, void* output);
};
class ObstacleRegistry
{
  public:
};

class ObstacleOwner
{
  public:
    int unk00[0x34];
    ObstacleRegistry m_kRegistry;  // +0xd0

    unsigned int FUN_00699510(ObstacleData* pkObstacle);
};

// @fnv 0x00699510
unsigned int ObstacleOwner::FUN_00699510(ObstacleData* pkObstacle)
{
    unsigned int uiResult;
    {
        NiPointer<ObstacleData> m_spRegisteredObstacle(pkObstacle);
        uiResult = reinterpret_cast<::S2f850 *>(&(m_kRegistry))->FUN_006c61b0((const ::NavMeshPtr &)(m_spRegisteredObstacle));
    }
    return uiResult;
}

namespace fnv_0069aa20 {
class EdgePoint
{
  public:
    float x, y, z;
    EdgePoint();
    EdgePoint operator-(const EdgePoint&) const;
};
struct LinkedMesh;
struct NavMeshPtr
{
    LinkedMesh* mesh;
    NavMeshPtr();
    ~NavMeshPtr();
};
struct MeshInfo
{
};
struct LinkInfo
{
    int type;
    MeshInfo* mesh;
    unsigned short triangle;
};
struct LinkedTriangle : NavMeshTriangle
{
};
struct LinkedMesh
{
    bool LinkMatchingEdges();
};
// @fnv 0x0069aa20
bool LinkedMesh::LinkMatchingEdges()
{
    for (unsigned int triangleIndex = 0; triangleIndex < ::FUN_00558200((char *)this); ++triangleIndex)
    {
        LinkedTriangle* triangle = ((::fnv_0069aa20::LinkedTriangle *)(reinterpret_cast<::NavMesh *>(this)->GetTriangle((unsigned short)triangleIndex)));
        if (!triangle || !reinterpret_cast<::FUN_00690e10_shell *>((triangle))->FUN_00690e10())
            continue;
        for (int edge = 0; edge < 3; ++edge)
        {
            if (!reinterpret_cast<::FUN_0068f1d0_shell *>((triangle))->IsEdgeFlagSet(edge))
                continue;
            int edgeCount;
            int matchingEdge;
            {
                LinkInfo* link = ((::fnv_0069aa20::LinkInfo *)(reinterpret_cast<::FUN_00693d30_shell *>(this)->GetEdge(reinterpret_cast<::FUN_0068f2c0_shell *>((triangle))->FUN_0068f2c0(edge))));
                {
                    NavMeshPtr otherMesh;
                    if (!reinterpret_cast<::NavMeshInfo *>((link->mesh))->ResolveNavMesh((::NavMeshPtr &)(otherMesh)))
                        continue;
                    LinkedTriangle* otherTriangle = ((::fnv_0069aa20::LinkedTriangle *)(reinterpret_cast<::NavMesh *>((((::fnv_0069aa20::LinkedMesh *)(::FUN_00559450((int *)&(otherMesh))))))->GetTriangle(link->triangle)));
                    if (!otherTriangle)
                        continue;
                    edgeCount = 0;
                    matchingEdge = -1;
                    for (int otherEdge = 0; otherEdge < 3; ++otherEdge)
                    {
                        if (reinterpret_cast<::FUN_0068f1d0_shell *>((otherTriangle))->IsEdgeFlagSet(otherEdge))
                        {
                            ++edgeCount;
                            matchingEdge = otherEdge;
                        }
                    }
                    if (edgeCount != 0)
                    {
                        EdgePoint edgeStart;
                        {
                            EdgePoint edgeEnd;
                            reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>(this)->FUN_0068f0c0((unsigned short)triangleIndex, edge, (::NiPoint3 *)&(edgeStart), (::NiPoint3 *)&(edgeEnd));
                            for (int candidateEdge = 0; candidateEdge < 3; ++candidateEdge)
                            {
                                EdgePoint start, end;
                                reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((((::fnv_0069aa20::LinkedMesh *)(::FUN_00559450((int *)&(otherMesh))))))->FUN_0068f0c0(link->triangle, candidateEdge, (::NiPoint3 *)&(start), (::NiPoint3 *)&(end));
                                if (reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_0069aa20::EdgePoint &)((edgeStart - end)))->UpdateCombatStyle() < 400.0 &&
                                    reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_0069aa20::EdgePoint &)((edgeEnd - start)))->UpdateCombatStyle() < 400.0)
                                {
                                    matchingEdge = candidateEdge;
                                    edgeCount = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (edgeCount == 1)
                    {
                        LinkInfo* reverse = ((::fnv_0069aa20::LinkInfo *)(reinterpret_cast<::D76A0NavMesh *>((((::fnv_0069aa20::LinkedMesh *)(::FUN_00559450((int *)&(otherMesh))))))->GetOrCreateEdgeInfo(link->triangle, matchingEdge)));
                        reverse->mesh = ((::fnv_0069aa20::MeshInfo *)(reinterpret_cast<::FUN_0068efb0_shell *>(this)->FUN_0068efb0()));
                        reverse->triangle = (unsigned short)triangleIndex;
                        reverse->type = 3;
                    }
                }
            }
        }
    }
    return true;
}
}  // namespace fnv_0069aa20

struct NavMeshTriList;

struct NavMeshGridView
{
    unsigned int uiCellCount;
    float fCellWidth;
    float fCellHeight;
    float m_fGridOriginX;
    float afWorldOriginY;
    float fMinZ;
    float kPointArrayBench;
    float m_fWorldTransformCoefficient4;
    void GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList);
};
// Looks up the triangle list at point, tests each triangle with GetTriangleHeightAtPoint, and returns true on the first hit, writing z.
// @fnv 0x00697b70
bool Target::FindTriangleZ(const NiPoint3& point, float above, float below, float* z)
{
    TriangleList* triangles = 0;
    reinterpret_cast<::NavMeshGridView *>(&(grid))->GetTriListAtPosition(point, (::NavMeshTriList **)&(triangles));
    if (!triangles)
        return false;
    unsigned int count = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((triangles))->GetName()));
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned short triangle = reinterpret_cast<::FUN_0069dec0_class *>((triangles))->FUN_0069dec0(index);
        if (reinterpret_cast<::FUN_00697980_t *>(this)->GetTriangleHeightAtPoint(triangle, point, above, below, z))
            return true;
    }
    return false;
}

// If arPos lies inside the grid bounds, computes the cell column and row from the cell size and stores the cell's tri list in *appList; otherwise stores null.
// @fnv 0x0069d370
void NavMeshGridView::GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList)
{
    if (arPos.x < m_fGridOriginX || arPos.x > kPointArrayBench || arPos.y < afWorldOriginY ||
        arPos.y > m_fWorldTransformCoefficient4)
    {
        *appList = 0;
    }
    else
    {
        float fDX2 = arPos.x - m_fGridOriginX;
        float fDYVal = arPos.y - afWorldOriginY;
        float fCol = fDX2 / fCellWidth;
        float fRow = fDYVal / fCellHeight;
        unsigned int uiCol = (unsigned int)FUN_00406ce0(fCol);
        unsigned int uiRowA = (unsigned int)FUN_00406ce0(fRow);
        if (uiCol >= uiCellCount)
        {
            uiCol = uiCellCount - 1;
        }
        if (uiRowA >= uiCellCount)
        {
            uiRowA = uiCellCount - 1;
        }
        *appList = ((::NavMeshTriList *)(reinterpret_cast<::FUN_006967c0_shell *>(this)->FUN_006967c0(uiCol, uiRowA)));
    }
}

// Projects a point onto a triangle in the XY plane via barycentric coordinates; if it lies inside,
// interpolates the triangle height there and accepts it when the height difference to the point
// is within [-fBelow, fAbove], returning the difference.
// @fnv 0x006b9cf0
bool FUN_006b9cf0(const NiPoint3& kP0, const NiPoint3& kP1, const NiPoint3& kP2, const NiPoint3& akPoint,
                  float& fHeightDiff, float fAbove, float fBelow)
{
    float fInvDenom;
    float fBary0;
    float fY2;
    float fDeltaY0;
    {
        float fY1;
        float fX1;
        float fX2Off;
        float fDeltaX0;
        float m_fGlyphExtent;
        float fDenom;
        float fW;
        float fProjectionAlongAim;
        float fV;

        fDenom = (kP1.x - kP0.x) * (kP2.y - kP0.y) - (kP2.x - kP0.x) * (kP1.y - kP0.y);
        if (fDenom == 0.0)
            return false;

        fX1 = kP1.x - akPoint.x;
        fX2Off = kP2.x - akPoint.x;
        fY1 = kP1.y - akPoint.y;
        fY2 = kP2.y - akPoint.y;
        fInvDenom = 1.0f / fDenom;

        fBary0 = (fX1 * fY2 - fX2Off * fY1) * fInvDenom;
        if (fBary0 < 0.0)
            return false;

        fDeltaX0 = kP0.x - akPoint.x;
        fDeltaY0 = kP0.y - akPoint.y;
        fV = (fX2Off * fDeltaY0 - fDeltaX0 * fY2) * fInvDenom;
        if (fV < 0.0)
            return false;

        fW = (fDeltaX0 * fY1 - fX1 * fDeltaY0) * fInvDenom;
        if (fW < 0.0)
            return false;

        m_fGlyphExtent = fBary0 * kP0.z + fV * kP1.z + fW * kP2.z;
        fProjectionAlongAim = m_fGlyphExtent - akPoint.z;
        if (fProjectionAlongAim > fAbove)
            return false;
        else if (fProjectionAlongAim < -fBelow)
            return false;

        fHeightDiff = fProjectionAlongAim;
        return true;
    }
}

struct NavObstacleObject
{
};
struct NavObstaclePtr
{
    NavObstacleObject* object;
    NavObstaclePtr(int);
    NavObstaclePtr(const NavObstaclePtr&);
    ~NavObstaclePtr();
    void FUN_006e5cc0(const NavObstaclePtr&);
};
struct NavMap
{
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_006946a0(unsigned short, NavObstaclePtr);
};
struct NavIndexArray
{
    unsigned int unk00, unk04, unk08, unk0C;
};
struct NavResetVertices
{
    unsigned int unk00, unk04, unk08, unk0C;
};
struct NavResetTriangles
{
    unsigned int unk00, unk04, unk08, unk0C;
};
struct NavTolerance
{
    float x, y, z;
    NavTolerance(float, float, float);
};
struct NavChange;
struct NavMeshOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    NavResetVertices vertices;
    NavResetTriangles triangles;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    NavMap* obstacles;
};
struct NavChange
{
    virtual ~NavChange();
    unsigned int unk04, state;
    NavObstaclePtr obstacle;
    unsigned int oldVertices, newVertices, oldTriangles, newTriangles;
    NavIndexArray affected;
    float centerX, centerY, centerZ;
    unsigned int unk3C;
    NavMap obstacleMap;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    NavChange();
};
struct NavItem
{
    unsigned int unk00;
    unsigned short unk04;
    bool enabled;
    char unk07;
    unsigned int unk08, unk0C, unk10, unk14, unk18;
    NavObstaclePtr obstacle;
};
struct NavItemArray
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    NavItem*& FUN_00877a30(unsigned int);
};
struct NavChangeBuilder
{
    NavMeshOwner* mesh;
    NavObstaclePtr obstacle;
    NavChange* change;
    unsigned int unk0C, unk10, unk14, unk18;
    NavItemArray items, previousItems;
    unsigned int count;
    bool FUN_006bf2a0(NavItem*);
    bool FUN_006bbd30(NavMeshOwner*, const NavObstaclePtr&, int);
};
// Builds a SearchContext and forwards the two ints and this to SearchContext::FUN_006bbd30, returning its result.
// @fnv 0x00698f40
bool NavMeshSearch::Search(int first, int second)
{
    SearchContext searchContext;
    bool result = reinterpret_cast<::NavChangeBuilder *>(&(searchContext))->FUN_006bbd30((::NavMeshOwner *)(void *)(this), (*(const ::NavObstaclePtr *)(first)), second);
    return result;
}
// Iterates indices from unkD0.FUN_0044ddc0() - 1 down to 0, calling UndoToPosition with each index and a local object.
// @fnv 0x006993c0
void FUN_006993c0_cls::FUN_006993c0()
{
    FUN_006993c0_local local;
    for (int i = ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(unkD0))->GetName())) - 1; i != -1; i--)
    {
        reinterpret_cast<::UndoOwner *>(this)->UndoToPosition(i, &local);
    }
}
// @fnv 0x00699000
bool UndoOwner::UndoToPosition(unsigned int position, void* output)
{
    UndoEntry* entry7 = ((::UndoEntry *)(::FUN_00559450((int *)&(entries.At(position)))));
    if (position == ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries))->GetName())) - 1)
    {
        UndoContext context;
        if (entry7->type == 1)
            reinterpret_cast<::BuildProcess *>(&(context))->Build((::BuildOutput *)(::UndoOwner *)(this), (::BuildInput *)(entry7), (::BuildCatalog *)(output));
        reinterpret_cast<::fnv_006bc8e0::Host006bc8e0 *>(&(context))->FUN_006bc8e0((::fnv_006bc8e0::InnerA006bc8e0 *)(::UndoOwner *)(this), (::fnv_006bc8e0::InnerB006bc8e0 *)(entry7));
        reinterpret_cast<::FUN_00699590_shell *>(this)->ForwardToStub(position);
    }
    else if (!reinterpret_cast<::B99690NavMesh *>(this)->ComputeTriangleHash((::B99690Info *)(entry7)))
    {
        UndoContext context;
        if (entry7->type == 1)
            reinterpret_cast<::BuildProcess *>(&(context))->Build((::BuildOutput *)(::UndoOwner *)(this), (::BuildInput *)(entry7), (::BuildCatalog *)(output));
    }
    else
    {
        SavedMesh saved2[100];
        unsigned int count3 = 0;
        UndoContext context;
        unsigned int index2;
        for (index2 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries))->GetName())) - 1; index2 != position - 1; --index2)
        {
            if (((::UndoEntry *)(::FUN_00559450((int *)&(entries.At(index2)))))->type == 1)
            {
                reinterpret_cast<::BuildProcess *>(&(context))->Build((::BuildOutput *)(::UndoOwner *)(this), (::BuildInput *)(::UndoEntry *)(((::UndoEntry *)(::FUN_00559450((int *)&(entries.At(index2)))))), (::BuildCatalog *)(output));
                if (index2 > position)
                {
                    saved2[count3] = ((::UndoEntry *)(::FUN_00559450((int *)&(entries.At(index2)))))->mesh;
                    ++count3;
                }
            }
            reinterpret_cast<::fnv_006bc8e0::Host006bc8e0 *>(&(context))->FUN_006bc8e0((::fnv_006bc8e0::InnerA006bc8e0 *)(::UndoOwner *)(this), (::fnv_006bc8e0::InnerB006bc8e0 *)(::UndoEntry *)(((::UndoEntry *)(::FUN_00559450((int *)&(entries.At(index2)))))));
            reinterpret_cast<::FUN_00699590_shell *>(this)->ForwardToStub(index2);
        }
        for (; index2 != -1; --index2)
        {
            if (((::UndoEntry *)(::FUN_00559450((int *)&(entries.At(index2)))))->type == 3)
            {
                reinterpret_cast<::fnv_006bc8e0::Host006bc8e0 *>(&(context))->FUN_006bc8e0((::fnv_006bc8e0::InnerA006bc8e0 *)(::UndoOwner *)(this), (::fnv_006bc8e0::InnerB006bc8e0 *)(::UndoEntry *)(((::UndoEntry *)(::FUN_00559450((int *)&(entries.At(index2)))))));
                reinterpret_cast<::FUN_00699590_shell *>(this)->ForwardToStub(index2);
            }
            else
                break;
        }
        for (unsigned int next3 = 0; next3 < count3; ++next3)
            reinterpret_cast<::NavChangeBuilder *>(&(context))->FUN_006bbd30((::NavMeshOwner *)(::UndoOwner *)(this), (const ::NavObstaclePtr &)(saved2[next3]), (int)(output));
    }
    return true;
}
// @fnv 0x006bbd30
bool NavChangeBuilder::FUN_006bbd30(NavMeshOwner* apMesh, const NavObstaclePtr& apObstacle, int flags)
{
    mesh = apMesh;
    obstacle.FUN_006e5cc0(apObstacle);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(items))->Clear(0);
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(previousItems))->GetName())); ++i)
    {
        if (((::NavObstacleObject *)(::FUN_00559450((int *)&(previousItems.FUN_00877a30(i)->obstacle)))))
            reinterpret_cast<::WaitableObject *>((((::NavObstacleObject *)(::FUN_00559450((int *)&(previousItems.FUN_00877a30(i)->obstacle))))))->FUN_00401970();
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(previousItems))->Clear(0);
    change = new NavChange;
    reinterpret_cast<::NavMeshOverlap *>((mesh))->FUN_006987d0((const ::ObstacleDataPtr &)(apObstacle), (const ::NiPoint3 &)((const ::NavTolerance &)(NavTolerance(5.0f, 5.0f, 5.0f))), (::NavMeshTriList *)(::NavIndexArray *)(&change->affected));
    if (reinterpret_cast<::FUN_0076b610_Class *>(&(change->affected))->FUN_0076b610())
    {
        delete change;
        return false;
    }
    change->state = 1;
    change->obstacle.FUN_006e5cc0(apObstacle);
    change->oldVertices = reinterpret_cast<::fnv_00990a60::FUN_00990a60_shell *>((mesh))->GetArrFlags();
    change->oldTriangles = ::FUN_00558200((char *)(mesh));
    count = reinterpret_cast<::FUN_006bc940_class *>(this)->FUN_006bc940();
    reinterpret_cast<::AdjBuilder *>(this)->CollectLinkedTriangles((::AdjEntryArray *)(float *)(&change->centerX));
    for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(change->affected))->GetName())); ++j)
        reinterpret_cast<::FUN_00691570_shell *>((reinterpret_cast<::NavMesh *>((mesh))->GetTriangle(reinterpret_cast<::FUN_005eeda0_this *>(&(change->affected))->GetBufferEntry(j))))->FUN_00691570(0x20);
    reinterpret_cast<::HostB60 *>(this)->BuildNavMeshEdges();
    for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(change->affected))->GetName())); ++k)
    {
        unsigned short index = reinterpret_cast<::FUN_005eeda0_this *>(&(change->affected))->GetBufferEntry(k);
        NavObstaclePtr entry(0);
        if (reinterpret_cast<::FUN_0069afb0_shell *>((mesh->obstacles))->FUN_0069afb0(index, (::Helper62d0 &)(entry)))
        {
            change->obstacleMap.FUN_006946a0(index, entry);
            reinterpret_cast<::FUN_0049c250_shell *>((mesh->obstacles))->FUN_0049c250(index);
        }
    }
    reinterpret_cast<::Builder *>(this)->BuildQuad();
    reinterpret_cast<::Processor74 *>(this)->SplitCrossingEdges();
    for (unsigned int n = 0; n < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(items))->GetName())); ++n)
    {
        if (FUN_006bf2a0(items.FUN_00877a30(n)))
            items.FUN_00877a30(n)->enabled = true;
    }
    reinterpret_cast<::S6bdcb0Owner *>(this)->FUN_006bdcb0();
    reinterpret_cast<::FUN_006bde50 *>(this)->DoWork();
    if (!reinterpret_cast<::Host120 *>(this)->BuildTrianglesFromEdgePairs())
    {
        reinterpret_cast<::FUN_00694890_shell *>(&(mesh->vertices))->FUN_00694890(change->oldVertices, true);
        reinterpret_cast<::fnv_006949d0::S5460 *>(&(mesh->triangles))->FUN_006949d0(change->oldTriangles, true);
        delete change;
        return false;
    }
    reinterpret_cast<::Graph006bdf50 *>(this)->JoinAdjacentEdges();
    reinterpret_cast<::Host120 *>(this)->BuildTrianglesFromEdgePairs();
    reinterpret_cast<::NavMeshGen_6be830 *>(this)->ApplyEdgeSplits();
    reinterpret_cast<::EdgeUpdater120 *>(this)->UpdateEdgeRecords((::RecordArray120 *)(flags));
    change->newVertices = reinterpret_cast<::fnv_00990a60::FUN_00990a60_shell *>((mesh))->GetArrFlags() - change->oldVertices;
    change->newTriangles = ::FUN_00558200((char *)(mesh)) - change->oldTriangles;
    reinterpret_cast<::FUN_006be770_class *>(this)->FUN_006be770();
    for (unsigned int t = change->oldTriangles; t < change->oldTriangles + change->newTriangles; ++t)
        mesh->obstacles->FUN_006946a0((unsigned short)t, obstacle);
    reinterpret_cast<::S006beb80 *>(this)->FUN_006beb80();
    reinterpret_cast<::FUN_006bec20_Class *>(this)->FUN_006bec20();
    reinterpret_cast<::FUN_006be660_class *>(this)->FUN_006be660();
    reinterpret_cast<::ObstacleOwner *>((mesh))->FUN_00699510((::ObstacleData *)(change));
    return true;
}

struct FindTriangleForLocationFilter;

struct NiPoint3Ops697
{
};

struct NavFinder697
{
    bool FUN_00697c10(const NiPoint3& kTargetCenter, float fRadius, NiPoint3* pkOut);
};

// @fnv 0x00697c10
bool NavFinder697::FUN_00697c10(const NiPoint3& aPosition, float aRadius, NiPoint3* pkOut)
{
    bool bFound = false;
    NiPoint3 kIntersectionOffset = NiPoint3::ZERO;
    for (unsigned int i = 0; i < 8 && !bFound; i++)
    {
        float fX = RandomFloat(-aRadius, aRadius);
        float fY = FUN_004019b0(aRadius * aRadius - fX * fX);
        fY = RandomFloat(-fY, fY);
        kIntersectionOffset.x = fX;
        kIntersectionOffset.y = fY;
        bFound = reinterpret_cast<::FUN_00697670_StandIn *>(this)->IsLocationOnNavMesh((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(((NiPoint3Ops697*)&kIntersectionOffset)))->ProjectileLaunched((::NiPoint3 *)&(aPosition), {}))), 0);
    }
    if (!bFound)
    {
        pkOut = 0;
        return false;
    }
    reinterpret_cast<::FUN_0063c8a0_shell *>((((NiPoint3Ops697*)&kIntersectionOffset)))->FUN_0063c8a0((void *)&(aPosition));
    *pkOut = reinterpret_cast<::NavMeshAdjust *>(this)->AdjustPointToNavMesh(kIntersectionOffset, ::DAT_0101e6ec);
    return true;
}

bool __cdecl FUN_00696540(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);

struct TriangleGridBuildReceiver
{
    unsigned int dimensionB_;
    float width8, heightSquared9;
};
struct GridCell
{
    unsigned int x, y;
};
struct GridMesh : NavMesh
{
    TriangleGridBuildReceiver Grid;
    void FUN_006959b0();
};

// Adds each triangle to grid cells containing its vertices, containing cell corners, or intersecting its edges.
// @fnv 0x006959b0
void GridMesh::FUN_006959b0()
{
    int count2 = ::FUN_00558200((char *)this);
    reinterpret_cast<::D2d0Cls *>(&(Grid))->FUN_0069d2d0();
    if (count2 == 0)
        return;
    NiPoint3 boundsMin5, boundsMaxX;
    reinterpret_cast<::Candidate *>(this)->ComputeBounds(boundsMin5, boundsMaxX);
    reinterpret_cast<::FUN_0069d800_class *>(&(Grid))->InitFromPoints((const ::P3 *)&(boundsMin5), (const ::P3 *)&(boundsMaxX), count2);
    unsigned int dimensionB_ = ((unsigned int)(::FUN_00559450((int *)&(Grid))));
    float width8 = Grid.width8;
    float heightSquared9 = Grid.heightSquared9;
    NiPoint3 corner1, right3, upper3, upperRight4, point12;
    NiPoint3 verticesCheck6[3];
    int triangle;
    NavMeshTriangle* triA4;
    float minX7, minYA, maxx6, maxy3;
    GridCell cellsVal[3];
    unsigned int maxX2, minCellX4, maxCellYVal, minY2;
    bool addedX;
    for (triangle = 0; triangle < count2; triangle++)
    {
        triA4 = GetTriangle((unsigned short)triangle);
        minX7 = minYA = ::DAT_01016970;
        maxx6 = maxy3 = ::DAT_01015f5c;
        for (int vertex = 0; vertex < 3; vertex++)
        {
            point12 = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triA4))->FUN_005582d0(vertex))));
            verticesCheck6[vertex] = point12;
            if (point12.x < minX7)
                minX7 = point12.x;
            if (point12.x > maxx6)
                maxx6 = point12.x;
            if (point12.y < minYA)
                minYA = point12.y;
            if (point12.y > maxy3)
                maxy3 = point12.y;
            cellsVal[vertex].x = (unsigned int)FUN_00406ce0((point12.x - boundsMin5.x) / width8);
            cellsVal[vertex].y = (unsigned int)FUN_00406ce0((point12.y - boundsMin5.y) / heightSquared9);
            if (cellsVal[vertex].x >= dimensionB_)
                cellsVal[vertex].x = dimensionB_ - 1;
            if (cellsVal[vertex].y >= dimensionB_)
                cellsVal[vertex].y = dimensionB_ - 1;
        }
        minCellX4 = maxX2 = cellsVal[0].x;
        minY2 = maxCellYVal = cellsVal[0].y;
        for (int vertex2 = 1; vertex2 < 3; vertex2++)
        {
            if (cellsVal[vertex2].x < minCellX4)
                minCellX4 = cellsVal[vertex2].x;
            if (cellsVal[vertex2].x > maxX2)
                maxX2 = cellsVal[vertex2].x;
            if (cellsVal[vertex2].y < minY2)
                minY2 = cellsVal[vertex2].y;
            if (cellsVal[vertex2].y > maxCellYVal)
                maxCellYVal = cellsVal[vertex2].y;
        }
        addedX = false;
        if (minCellX4 == maxX2 && minY2 == maxCellYVal)
        {
            reinterpret_cast<::S696500 *>(&(Grid))->FUN_00696500((unsigned short)triangle, minCellX4, minY2);
            addedX = true;
        }
        else
        {
            for (unsigned int x = minCellX4; x <= maxX2; x++)
            {
                for (unsigned int y = minY2; y <= maxCellYVal; y++)
                {
                    if ((cellsVal[0].x == x && cellsVal[0].y == y) || (cellsVal[1].x == x && cellsVal[1].y == y) ||
                        (cellsVal[2].x == x && cellsVal[2].y == y))
                    {
                        reinterpret_cast<::S696500 *>(&(Grid))->FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    corner1 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0069d790_class *>(&(Grid))->FUN_0069d790((::NiPoint3 *)(x), y, {})));
                    right3 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0069d790_class *>(&(Grid))->FUN_0069d790((::NiPoint3 *)(x + 1), y, {})));
                    upper3 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0069d790_class *>(&(Grid))->FUN_0069d790((::NiPoint3 *)(x), y + 1, {})));
                    upperRight4 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0069d790_class *>(&(Grid))->FUN_0069d790((::NiPoint3 *)(x + 1), y + 1, {})));
                    if ((verticesCheck6[0].x <= upperRight4.x && verticesCheck6[0].y <= upperRight4.y &&
                         verticesCheck6[0].x >= corner1.x && verticesCheck6[0].y >= corner1.y) ||
                        (verticesCheck6[1].x <= upperRight4.x && verticesCheck6[1].y <= upperRight4.y &&
                         verticesCheck6[1].x >= corner1.x && verticesCheck6[2].y >= corner1.y) ||
                        (verticesCheck6[2].x <= upperRight4.x && verticesCheck6[2].y <= upperRight4.y &&
                         verticesCheck6[2].x >= corner1.x && verticesCheck6[2].y >= corner1.y))
                    {
                        reinterpret_cast<::S696500 *>(&(Grid))->FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    float zl;
                    if (reinterpret_cast<::NavMesh *>(this)->FindHeightOnTriangle((unsigned short)triangle, corner1, zl, ::DAT_01016970, 180.0f) ||
                        reinterpret_cast<::NavMesh *>(this)->FindHeightOnTriangle((unsigned short)triangle, right3, zl, ::DAT_01016970, 180.0f) ||
                        reinterpret_cast<::NavMesh *>(this)->FindHeightOnTriangle((unsigned short)triangle, upper3, zl, ::DAT_01016970, 180.0f) ||
                        reinterpret_cast<::NavMesh *>(this)->FindHeightOnTriangle((unsigned short)triangle, upperRight4, zl, ::DAT_01016970, 180.0f))
                    {
                        reinterpret_cast<::S696500 *>(&(Grid))->FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                        continue;
                    }
                    NiPoint3 cellStart3, cellEnd5, triStart6, triEndX;
                    bool intersects3 = false;
                    for (int edge = 0; edge < 4 && !intersects3; edge++)
                    {
                        switch (edge)
                        {
                        case 0:
                            cellStart3 = corner1;
                            cellEnd5 = right3;
                            break;
                        case 1:
                            cellStart3 = right3;
                            cellEnd5 = upperRight4;
                            break;
                        case 2:
                            cellStart3 = upperRight4;
                            cellEnd5 = upper3;
                            break;
                        case 3:
                            cellStart3 = upper3;
                            cellEnd5 = corner1;
                            break;
                        }
                        for (int triEdge = 0; triEdge < 3; triEdge++)
                        {
                            switch (triEdge)
                            {
                            case 0:
                                triStart6 = verticesCheck6[0];
                                triEndX = verticesCheck6[1];
                                break;
                            case 1:
                                triStart6 = verticesCheck6[1];
                                triEndX = verticesCheck6[2];
                                break;
                            case 2:
                                triStart6 = verticesCheck6[2];
                                triEndX = verticesCheck6[0];
                                break;
                            }
                            if (FUN_00696540(cellStart3, cellEnd5, triStart6, triEndX))
                            {
                                intersects3 = true;
                                break;
                            }
                        }
                    }
                    if (intersects3)
                    {
                        reinterpret_cast<::S696500 *>(&(Grid))->FUN_00696500((unsigned short)triangle, x, y);
                        addedX = true;
                    }
                }
            }
        }
    }
}

#include "generated/data/fallout_shared/pathfinding/navmesh_util.inc"
