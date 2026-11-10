// fallout_shared/pathfinding/navmeshrender.cpp: NavMeshObstacleManager, ObstacleTask, NavRenderX, RenderTask and more (12 functions)

#include <cstdint>
#include <new>
#include <cstring>
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C006c6030.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_0049f990_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0068f1d0_shell.h"
#include "fnv/decl/FUN_0068f230_shell.h"
#include "fnv/decl/FUN_00690e70_shell.h"
#include "fnv/decl/FUN_00691040_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_00691620_shell.h"
#include "fnv/decl/FUN_00691640_shell.h"
#include "fnv/decl/FUN_00693b70_shell.h"
#include "fnv/decl/FUN_00699790_shell.h"
#include "fnv/decl/FUN_0069dfb0_class.h"
#include "fnv/decl/FUN_006c6400_Node.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/Map62d0.h"
#include "fnv/decl/Map6920.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NavMesh.h"
#include "fnv/decl/NavMeshInfo.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/S00693b90.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/TriHack.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00457070__FUN_00457070_shell.h"
#include "fnv/decl/fnv_00631540__TargetClass.h"
#include "fnv/decl/fnv_0069cea0__FUN_0069cea0_class.h"
#include "fnv/decl/fnv_006a6660__FUN_006a69b0_Class.h"
#include "fnv/decl/fnv_00990a60__FUN_00990a60_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00552000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_006a5000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c55000.h"
#include "fnv/symbols_00c56000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "navmeshrender_decls.h"

// The PC spans supplied for this unit are obstacle-management methods. The
// legacy PaddedBooleanState labels disagree with their member layouts and lifetimes.

// Iterates the obstacle list, looks up each rigid body's ObstacleData, skips ones already in the active list, and adds the rest to its head.
// @fnv 0x006c49e0
void NavMeshObstacleManager::ProcessActivatedObstacles()
{
    unsigned int count = m_kActivatedRigidBodies.GetCount();
    for (unsigned int uiIndex = 0; uiIndex < count; ++uiIndex)
    {
        bhkRigidBody* body;
        reinterpret_cast<::C006c6030 *>(&(m_kActivatedRigidBodies))->FUN_006c6030((void *)&(body));
        NiPointer<ObstacleData> obstacle;
        if (reinterpret_cast<::Map62d0 *>((void *)&(RigidBodyObstacleLookup))->FUN_006c62d0((std::uintptr_t)(body), (void **)&(obstacle)))
        {
            if (reinterpret_cast<::FUN_006c6400_Node *>(&(m_kActiveObstacles))->Contains((const ::NiPointer< ::NiAVObject> &)(obstacle)))
                continue;
            reinterpret_cast<::fnv_00631540::TargetClass *>(&(m_kActiveObstacles))->FUN_00631540((const ::NiPointer< ::NiNode> &)(obstacle));
        }
    }
}

// Stores the obstacle pointer, task type and navmesh pointer into the object's fields.
// @fnv 0x006c7d70
ObstacleTask::ObstacleTask(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type, const NavMeshPtr& navMesh)
{
    m_spRegisteredObstacle = obstacle;
    eType = type;
    apSearchNavMesh = navMesh;
}

extern int DAT_010159d4;

struct Dummy0042f800
{
};

// @fnv 0x0049f1c0
void* FUN_0049f1c0(int** pThis)
{
    *pThis = &DAT_010159d4;
    reinterpret_cast<::FUN_0049f990_class *>((reinterpret_cast<Dummy0042f800*>(pThis)))->FUN_0049f990(0, 0);
    return pThis;
}

class NavMeshTriangle
{
  public:
    void Clear();
    bool HasEdgeExtraInfo();
    bool IsPreferred();
    void TogglePreferred();
    bool IsWaterTriangle();
    void ToggleWater();
    bool IsNoLargeCreature();
    void ToggleNoLargeCreature();
    void GetVerts(unsigned short*, unsigned short*, unsigned short*);
    void GetTris(unsigned short*, unsigned short*, unsigned short*);
    void SetVerts(unsigned short, unsigned short, unsigned short);
    void SetTris(unsigned short, unsigned short, unsigned short);
    void SetFlag(int);
    unsigned int GetTriangleFlags();
    void SetTriangleFlags(unsigned int);
    unsigned short GetVert(unsigned int);
    void SetVert(unsigned int, unsigned short);
    unsigned short GetTri(unsigned int);
    void SetTri(unsigned int, unsigned short);
    bool EdgeHasExtraInfo(int);
    unsigned short GetEdgeExtraInfoValue(int);
    void SetEdgeExtraInfo(int, unsigned short);
    void ClearEdgeExtraInfo(int);
    bool HasDoorPortal();
    bool IsEdgeConnected(int);
    unsigned short GetTriOrExtraInfo(int);
    void SetTriOrExtraInfo(int, unsigned short);
    unsigned short GetObjectCount();
    void SetObjectCount(unsigned short);
    void ClearObjectCount();
    static bool HasCover(unsigned int);
    bool HasCover();
    bool HasCoverEdge0();
    bool HasCoverEdge1();
    static bool HasCoverOrWallFlags(unsigned int);
    bool HasCoverOrWallFlags();
    bool HasCoverOrWallEdge0();
    bool HasCoverOrWallEdge1();
    bool IsWall(unsigned short);
    bool IsEdgeOpen(unsigned short);
    unsigned short GetEdgeCover(unsigned short);
    bool GetEdgeSides(unsigned short, bool*, bool*);
    static void GetEdgeCoverData(unsigned int, unsigned short, unsigned short*, bool*, bool*);
    void GetEdgeCoverData(unsigned short, unsigned short*, bool*, bool*);
    void ClearCover();
    static void SetEdgeCover(unsigned int*, unsigned short, unsigned short, bool, bool);
    void SetEdgeCover(unsigned short, unsigned short, bool, bool);
    int Rotate(int);
    bool ConvertCoverEdgeFormat();
    static unsigned int GetCoverLevel(float, bool, bool);
    static float GetCoverHeight(unsigned int);
    void Endian();
    char Vertices[6];
    char Triangles[6];
    unsigned int m_uiTriangleFlags;
};
struct FUN_006a5ec0_shell : public NavMeshTriangle
{
    bool FUN_006a5ec0();
};

// @fnv 0x006a5ec0
bool FUN_006a5ec0_shell::FUN_006a5ec0()
{
    return reinterpret_cast<::FUN_00691140_shell *>(this)->FUN_00691140(0x200);
}

struct FUN_006a5b30_shell
{
    short m_uiX;
    short m_uiY;
    short m_uiZ;
    void GetTripleShorts(short* a, short* b, short* c);
};

// Copies the three short fields of this object into the three output pointers.
// @fnv 0x006a5b30
void FUN_006a5b30_shell::GetTripleShorts(short* pFirst, short* pSecond, short* pThird)
{
    *pFirst = this->m_uiX;
    *pSecond = this->m_uiY;
    *pThird = this->m_uiZ;
}

struct FUN_006a5b70_shell
{
    short m_00;
    short m_02;
    short m_04;
    short m_06;
    short m_08;
    short m_0A;
    void FUN_006a5b70(short* a, short* b, short* c);
};

// Copies the shell's m_06, m_08 and m_0A shorts into the three output pointers.
// @fnv 0x006a5b70
void FUN_006a5b70_shell::FUN_006a5b70(short* a, short* b, short* c)
{
    *a = m_06;
    *b = m_08;
    *c = m_0A;
}

extern float runtimeInitializationFloat369;
// Clamps a to 0xF and returns it multiplied by runtimeInitializationFloat369.
// @fnv 0x006a5af0
float ScaleClampedValue(unsigned int auiValue)
{
    if (auiValue > 0xF)
        auiValue = 0xF;
    return auiValue * runtimeInitializationFloat369;
}

struct NiUpdateData
{
    unsigned int value0;
    unsigned int value1;
    unsigned int value2;

    NiUpdateData(float, bool, bool);
};

class NiNode
{
};

class NiAVObject : public NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
};

struct GO
{
    operator unsigned int() const;
};

struct GlobalObject_00633c90 : public GO
{
};


struct PaddedBooleanState
{
    unsigned char padding[0x210];
    bool m_bState;

    void FUN_006a36e0(bool);
};

// @fnv 0x006a36e0
void PaddedBooleanState::FUN_006a36e0(bool abDraw)
{
    if (abDraw)
    {
        reinterpret_cast<::FUN_00a5a040_Class *>((reinterpret_cast<NiAVObject*>(::g_011d6e5c.operator unsigned int())))->FUN_00a5a040();

        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NiNode*>(::g_011d6e5c.operator unsigned int())))->FUN_00a59c60((std::intptr_t)&(UpdateData));
    }
    else
    {
        reinterpret_cast<::FUN_004def90_Class *>((reinterpret_cast<NiNode*>(::g_011d6e5c.operator unsigned int())))->FUN_004def90();
        reinterpret_cast<::FUN_00a5a040_Class *>((reinterpret_cast<NiAVObject*>(::g_011d6e5c.operator unsigned int())))->FUN_00a5a040();

        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NiNode*>(::g_011d6e5c.operator unsigned int())))->FUN_00a59c60((std::intptr_t)&(UpdateData));

        reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<NiTPointerMap<NiNode*, NiNode*>*>(reinterpret_cast<char*>(this) + 0x200)))->FUN_00438af0();
    }

    m_bState = abDraw;
}

namespace fnv_006a5ca0 {
struct CellH
{
};

struct DoorH
{
};

class TESWorldSpace
{
};

struct TES
{
};

struct GlobalObject_0045cfe0
{
};

struct PaddedBooleanState
{
    void FUN_006a37a0(TESObjectCELL* cell, bool value);
    void FUN_006a5ca0();
};


GlobalObject_0045cfe0 g_011c63cc;

// @fnv 0x006a5ca0
void PaddedBooleanState::FUN_006a5ca0()
{
    TESObjectCELL* pcellVal;
    int d8;
    int x9;
    int y3;
    TESObjectCELL* pgridCell4;

    reinterpret_cast<::PaddedBooleanState *>(this)->FUN_006a36e0(false);
    pcellVal = ((::TESObjectCELL *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>((reinterpret_cast<TES*>(::g_TES)))->FUN_00457070()));
    if (pcellVal)
    {
        if (!reinterpret_cast<::TESObjectCELL *>((pcellVal))->IsCellInterior())
        {
            d8 = (((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_006a5ca0::GlobalObject_0045cfe0 *>(&::g_011c63cc))))))[0] - 1) / 2;
            x9 = reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(pcellVal)))->GetCellGridX() - d8;
            for (; x9 <= reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(pcellVal)))->GetCellGridX() + d8; ++x9)
            {
                y3 = reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(pcellVal)))->GetCellGridY() - d8;
                for (; y3 <= reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(pcellVal)))->GetCellGridY() + d8; ++y3)
                {
                    pgridCell4 = reinterpret_cast<::TESWorldSpace *>((reinterpret_cast<TESWorldSpace*>(((void *)(reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<DoorH*>(pcellVal)))->GetParentWorldSpace())))))->GetCellAtGridPosition(x9, y3);
                    FUN_006a37a0(pgridCell4, false);
                }
            }
        }
        else
        {
            reinterpret_cast<PaddedBooleanState*>(::FUN_00552ba0())->FUN_006a37a0(pcellVal, false);
        }
    }
    reinterpret_cast<::PaddedBooleanState *>(this)->FUN_006a36e0(true);
}
}  // namespace fnv_006a5ca0

struct Pt3X
{
    float x, y, z;
    Pt3X();
    Pt3X operator*(float afScale) const;
    Pt3X operator+(const Pt3X& arPt) const;
    Pt3X operator-(const Pt3X& arPt) const;
    Pt3X& operator*=(float afScale);
};
struct EmptyX
{
};
struct Pt3PodX : public EmptyX
{
    float x, y, z;
};
struct ColorX
{
    float r, g, b, a;
    ColorX();
    ColorX(float afR, float afG, float afB, float afA);
};
struct UpdateDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    short sPad;
    int iActionIndex;
    UpdateDataX(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};
struct FixedStrX
{
    const char* pString;
    FixedStrX(const char* apString);
    ~FixedStrX();
};
struct AVObjX;
struct ObjX
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
    virtual void AttachChildInAvailableSlot(AVObjX* apChild, bool abFirstAvail);
};
struct AVObjX : public ObjX
{
    void AttachProperty(AVObjX* apProperty);
    void SetFlags(int aiFlags, int aiArg);
};
struct NodeX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    NodeX(unsigned short ausChildren);
};
struct LinesX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    LinesX(unsigned short ausVerts, Pt3X* apVerts, ColorX* apColors, int a, int b, int c, bool* apFlags);
};
struct TriShapeX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    TriShapeX(unsigned short ausVerts, Pt3X* apVerts, Pt3X* apNormals, ColorX* apColors, void* apUV,
              unsigned short ausUV, int aiFlags, unsigned short ausTris, unsigned short* apusList);
};
struct PropX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    PropX();
};
struct AlphaX : public AVObjX
{
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    AlphaX();
};
template <class T> struct SpX
{
    T* m_pObject;
    SpX(T* apObject);
    SpX(const SpX& arPtr);
    ~SpX();
    void operator=(T* apObject);
    operator T*() const;
};
struct Pt3ArrX
{
    Pt3X* pData;
    int iSize, iAlloc, iGrow;
    Pt3ArrX(int aiSize);
    ~Pt3ArrX();
    Pt3X& GetAt(unsigned int auiIndex);
};
struct ColorArrX
{
    ColorX* pData;
    int iSize, iAlloc, iGrow;
    ColorArrX(int aiSize);
    ~ColorArrX();
    ColorX& GetAt(int aiIndex);
};
struct BoolArrX
{
    bool* pData;
    int iSize, iAlloc, iGrow;
    BoolArrX(int aiSize);
    ~BoolArrX();
    bool& GetAt(int aiIndex);
};
struct NavTriX
{
    void GetVerts(unsigned short* apA, unsigned short* apB, unsigned short* apC);
    void GetTris(unsigned short* apA, unsigned short* apB, unsigned short* apC);
    bool EdgeHasExtraInfo(int aiEdge);
    void GetEdgeCoverData(unsigned short ausEdge, unsigned short* apusCover, bool* apbLeft, bool* apbRight);
};
struct SphereX
{
};
struct NavMeshX;
struct NavMeshPtrX
{
    NavMeshX* m_pObject;
    NavMeshPtrX();
    NavMeshPtrX(const NavMeshPtrX& arPtr);
    ~NavMeshPtrX();
    NavMeshPtrX& operator=(const NavMeshPtrX& arPtr);
    operator NavMeshX*() const;
    bool Equals(const NavMeshPtrX& arPtr);
};
struct NavInfoX
{
};
struct EdgeInfoX
{
    int iActionIndex;
    NavInfoX* pTarget;
    unsigned short usTri;
};
struct NavMeshX
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    Pt3ArrX kVerts;
};
struct NavArrX
{
    NavMeshPtrX GetAt(unsigned int auiIndex);
};
struct CellX
{
};
struct CellMapX
{
    bool GetAt(CellX* apCell, SpX<NodeX>& arNode);
};
struct NavRenderX
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    SpX<AVObjX> spWireframe;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    SpX<AVObjX> spVertexColor;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    ColorX aColors[11];
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    SpX<AVObjX> spZBuffer;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    CellMapX kMap;
    void FUN_006a37a0(CellX* apCell, bool abUpdate);
};
extern float xfCoverWidth, xfCoverScale, xfCoverOffset, xfCoverWidth2;
struct WorldObject : public NiAVObject
{
    virtual void DeleteThis();
    virtual void GetRTTI();
    virtual void AsNode();
    virtual void AsSwitchNode();
    virtual void AsFadeNode();
    virtual void AsMultiBoundNode();
    virtual void AsGeometry();
    virtual void AsTriStrips();
    virtual void AsTriShape();
    virtual void AsSegmentedTriShape();
    virtual void AsSubIndexTriShape();
    virtual void AsDynamicTriShape();
    virtual void AsNiGeometry();
    virtual void AsNiTriBasedGeom();
    virtual void AsNiTriShape();
    virtual void AsParticlesGeom();
    virtual void AsLinesGeom();
    virtual void AsCollisionObject();
    virtual void AsBlendCollisionObject();
    virtual void AsAttachmentCollisionObject();
    virtual void AsRigidBody();
    virtual void AsLimitedHingeConstraint();
    virtual void MakeClone();
    virtual void LoadBinary();
    virtual void LinkObject();
    virtual void RegisterStreamables();
    virtual void SaveBinary();
    virtual void IsEqual();
    virtual void ProcessClone();
    virtual void PostLinkObject();
    virtual void StreamCanSkip();
    virtual void GetStreamableRTTI();
    virtual void GetBlockAllocationSize();
    virtual void GetGroup();
    virtual void SetGroup();
    virtual void AsControllerManager();
    virtual void UpdateControllers();
    virtual void PerformOperation();
    virtual void AttachProperty();
    virtual void SetMaterialNeedsUpdate();
    virtual void SetDefaultMaterialNeedsUpdateFlag();
    virtual void GetObjectByName();
    virtual void SetSelectiveUpdateFlags();
    virtual void UpdateDownwardPass();
    virtual void UpdateSelectedDownwardPass();
    virtual void UpdateRigidDownwardPass();
    virtual void UpdateWorldBound();
    virtual void UpdateWorldData();
    virtual void UpdateTransformAndBounds();
    virtual void PreAttachUpdate();
    virtual void CompleteAttachUpdate();
    virtual void OnVisible();
    virtual void UpdateWorldTransform();
    virtual void UpdateEffects();
    virtual void CalculateWorldBound();
    virtual void PropagateControllers();
    virtual void GetWorldTransform();
    virtual void GetLocalTransform();
    virtual void AttachChildInAvailableSlot(WorldObject* child);
};
struct WorldPointer : public GO
{
    WorldObject* object;
    WorldPointer(WorldObject* object = 0);
    ~WorldPointer();
};
struct QueryQueue
{
};
struct RenderTask
{
    void UpdateChildByKey(int key);
};
// @fnv 0x006a5bb0
void RenderTask::UpdateChildByKey(int key)
{
    WorldPointer child(0);
    if (reinterpret_cast<::Map62d0 *>((reinterpret_cast<QueryQueue*>(reinterpret_cast<char*>(this) + 0x200)))->FUN_006c62d0(key, (void **)(::WorldPointer *)(&child)))
    {
        reinterpret_cast<WorldObject*>(static_cast<unsigned int>(::g_011d6e5c))
            ->AttachChildInAvailableSlot(reinterpret_cast<WorldObject*>(static_cast<unsigned int>(child)));
        NiUpdateData updateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(::g_011d6e5c))))->FUN_00a59c60((std::intptr_t)&(updateData));
        reinterpret_cast<::FUN_00a5a040_Class *>((reinterpret_cast<NiAVObject*>(static_cast<unsigned int>(::g_011d6e5c))))->FUN_00a5a040();
        reinterpret_cast<::NiTMap_S *>((reinterpret_cast<QueryQueue*>(reinterpret_cast<char*>(this) + 0x200)))->RemoveKey(key);
    }
}

struct NavTriStub
{
};

struct NavRenderStub
{
    int GetNavTriColor(NavTriStub* pTri);
};
// Builds and attaches a navmesh debug render node for the cell: lines, cover lines, triangles and spheres, then updates the nav root if requested.
// @fnv 0x006a37a0
void NavRenderX::FUN_006a37a0(CellX* apCell, bool abUpdate)
{
    NavArrX* qfTOqo;
    unsigned int qQMZREG;
    if (!apCell)
        return;
    qfTOqo = ((::NavArrX *)(std::uintptr_t)(::FUN_0070ec90((char *)(apCell))));
    if (!qfTOqo)
        return;
    qQMZREG = reinterpret_cast<::FUN_00620b80_shell *>((qfTOqo))->GetReferenceFlags();
    SpX<NodeX> qAhbO(0);
    if (!reinterpret_cast<::Map62d0 *>(&(kMap))->FUN_006c62d0((std::uintptr_t)(apCell), (void **)&(qAhbO)))
    {
        qAhbO = new NodeX(qQMZREG * 2);
        ((NodeX*)(*reinterpret_cast<::SpX< ::NodeX> *>(&::g_011d6e5c)))->AttachChildInAvailableSlot(qAhbO, true);
        reinterpret_cast<::Map6920 *>(&(kMap))->FUN_006c6920((std::uintptr_t)(apCell), (*(::NiPointer< ::NiAVObject> *)&(const ::SpX< ::NodeX> &)(qAhbO)));
    }
    else
    {
        return;
    }
    NavMeshPtrX qsSDDgz;
    for (unsigned int qbfQdhM = 0; qbfQdhM < qQMZREG; qbfQdhM++)
    {
        unsigned int qXMUYT;
        unsigned int qpia;
        ColorX* qJDuOZ;
        bool* qxQHW;
        unsigned int qIpA;
        unsigned int qArxcFu;
        unsigned int qMBds;
        unsigned short* qaGEwZ;
        Pt3X* qFffvLe;
        ColorX* qZAdkzg;
        bool qfCsmZ;
        unsigned int qVduN;
        Pt3X* qbXcw;
        unsigned int qBCzzXA;
        reinterpret_cast<::NavMeshPtr *>((void *)&(const ::NavMeshPtrX &)(qsSDDgz))->operator=((const ::NavMeshPtr &)((const ::NavMeshPtrX &)(qfTOqo->GetAt(qbfQdhM))));
        qMBds = ::FUN_00558200((char *)(((NavMeshX*)qsSDDgz)));
        qBCzzXA = reinterpret_cast<::fnv_00990a60::FUN_00990a60_shell *>((((NavMeshX*)qsSDDgz)))->GetArrFlags();
        if (!qMBds)
            continue;
        qfCsmZ = reinterpret_cast<::TESForm *>((((NavMeshX*)qsSDDgz)))->GetDisabled();
        Pt3ArrX qkJsUdT(qBCzzXA);
        ColorArrX qrEZrs(qBCzzXA);
        if (qfCsmZ)
        {
            for (unsigned int qAXSCg = 0; qAXSCg < qBCzzXA; qAXSCg++)
            {
                qkJsUdT.GetAt(qAXSCg) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qAXSCg);
                qrEZrs.GetAt(qAXSCg) = aColors[10];
            }
        }
        else
        {
            for (unsigned int qBLsiu = 0; qBLsiu < qBCzzXA; qBLsiu++)
            {
                qkJsUdT.GetAt(qBLsiu) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qBLsiu);
                qrEZrs.GetAt(qBLsiu) = aColors[0];
            }
        }
        qaGEwZ = (unsigned short*)::FUN_00aa1070(qMBds * 3 * sizeof(unsigned short));
        qXMUYT = qBCzzXA;
        qVduN = 0;
        qIpA = qMBds * 6;
        Pt3ArrX qDdzMIp(qIpA);
        BoolArrX qHXYKT(qIpA);
        ColorArrX qGfbX(qIpA);
        qpia = 0;
        Pt3ArrX qZWI(qIpA);
        BoolArrX qrKBG(qIpA);
        ColorArrX qpqRa(qIpA);
        qArxcFu = 0;
        for (unsigned int qrUCJDN = 0; qrUCJDN < qMBds; qrUCJDN++)
        {
            NavTriX* qidnYUK = ((::NavTriX *)(reinterpret_cast<::NavMesh *>((((NavMeshX*)qsSDDgz)))->GetTriangle(qrUCJDN)));
            if (reinterpret_cast<::FUN_00691140_shell *>((qidnYUK))->FUN_00691140(0x20))
                continue;
            unsigned short qxWmVch[3];
            reinterpret_cast<::FUN_006a5b30_shell *>((qidnYUK))->GetTripleShorts((short *)(unsigned short *)(&qxWmVch[0]), (short *)(unsigned short *)(&qxWmVch[1]), (short *)(unsigned short *)(&qxWmVch[2]));
            if (qfCsmZ)
            {
                qaGEwZ[qVduN] = qxWmVch[0];
                qVduN++;
                qaGEwZ[qVduN] = qxWmVch[1];
                qVduN++;
                qaGEwZ[qVduN] = qxWmVch[2];
                qVduN++;
            }
            else
            {
                int qhQRuW = reinterpret_cast<::NavRenderStub *>(this)->GetNavTriColor((::NavTriStub *)(qidnYUK));
                if (qhQRuW)
                {
                    reinterpret_cast<::fnv_0069cea0::FUN_0069cea0_class *>(&(qkJsUdT))->FUN_0069cea0(qXMUYT + 3, 1);
                    reinterpret_cast<::fnv_006a6660::FUN_006a69b0_Class *>(&(qrEZrs))->FUN_006a6660(qXMUYT + 3, 1);
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[0]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[1]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                    qkJsUdT.GetAt(qXMUYT) = qkJsUdT.GetAt(qxWmVch[2]);
                    qrEZrs.GetAt(qXMUYT) = aColors[qhQRuW];
                    qaGEwZ[qVduN] = qXMUYT;
                    qVduN++;
                    qXMUYT++;
                }
                else
                {
                    qaGEwZ[qVduN] = qxWmVch[0];
                    qVduN++;
                    qaGEwZ[qVduN] = qxWmVch[1];
                    qVduN++;
                    qaGEwZ[qVduN] = qxWmVch[2];
                    qVduN++;
                }
            }
            unsigned short qpydTG[3];
            reinterpret_cast<::FUN_006a5b70_shell *>((qidnYUK))->FUN_006a5b70((short *)(unsigned short *)(&qpydTG[0]), (short *)(unsigned short *)(&qpydTG[1]), (short *)(unsigned short *)(&qpydTG[2]));
            for (unsigned short qOFvKuu = 0; qOFvKuu < 3; qOFvKuu++)
            {
                unsigned int qxDeKK = qpia + 1;
                bool qZNIZJV = reinterpret_cast<::FUN_0068f1d0_shell *>((qidnYUK))->IsEdgeFlagSet(qOFvKuu);
                if (::DAT_011d6e29 && qpydTG[qOFvKuu] != 0xffff)
                {
                    NavMeshPtrX qfpzU(qsSDDgz);
                    NavTriX* qYdAnhh = 0;
                    bool qoPB = false;
                    unsigned short qQGWBE = 0xffff;
                    if (qZNIZJV)
                    {
                        EdgeInfoX* qXSF = ((::EdgeInfoX *)(reinterpret_cast<::FUN_0068f230_shell *>((((NavMeshX*)qsSDDgz)))->FUN_0068f230(qrUCJDN, qOFvKuu)));
                        if (qXSF && qXSF->pTarget && reinterpret_cast<::FUN_0069dfb0_class *>((void *)(qXSF->pTarget))->HasNonZeroAtOffset54())
                        {
                            reinterpret_cast<::NavMeshInfo *>((qXSF->pTarget))->AcquireNavMesh((::NavMeshPtr &)(qfpzU));
                            unsigned int qgqKr = qXSF->usTri;
                            qYdAnhh = ((::NavTriX *)(reinterpret_cast<::NavMesh *>((((NavMeshX*)qfpzU)))->GetTriangle(qgqKr)));
                            unsigned short qGTHx[3];
                            reinterpret_cast<::FUN_006a5b70_shell *>((qYdAnhh))->FUN_006a5b70((short *)(unsigned short *)(&qGTHx[0]), (short *)(unsigned short *)(&qGTHx[1]), (short *)(unsigned short *)(&qGTHx[2]));
                            for (int qBMjHz = 0; qBMjHz < 3; qBMjHz++)
                            {
                                if (reinterpret_cast<::FUN_0068f1d0_shell *>((qYdAnhh))->IsEdgeFlagSet(qBMjHz))
                                {
                                    EdgeInfoX* qoqcoe = ((::EdgeInfoX *)(reinterpret_cast<::FUN_0068f230_shell *>((((NavMeshX*)qfpzU)))->FUN_0068f230(qgqKr, qBMjHz)));
                                    if (qoqcoe)
                                    {
                                        NavMeshPtrX qVCM;
                                        reinterpret_cast<::NavMeshInfo *>((qoqcoe->pTarget))->AcquireNavMesh((::NavMeshPtr &)(qVCM));
                                        if (qVCM.Equals(qsSDDgz) && qoqcoe->usTri == qrUCJDN)
                                        {
                                            qoPB = true;
                                            qQGWBE = qBMjHz;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        qYdAnhh = ((::NavTriX *)(reinterpret_cast<::NavMesh *>((((NavMeshX*)qsSDDgz)))->GetTriangle(qpydTG[qOFvKuu])));
                        unsigned short qRBAdC[3];
                        reinterpret_cast<::FUN_006a5b70_shell *>((qYdAnhh))->FUN_006a5b70((short *)(unsigned short *)(&qRBAdC[0]), (short *)(unsigned short *)(&qRBAdC[1]), (short *)(unsigned short *)(&qRBAdC[2]));
                        for (int qQirx = 0; qQirx < 3; qQirx++)
                        {
                            if (qRBAdC[qQirx] == qrUCJDN)
                            {
                                qoPB = true;
                                qQGWBE = qQirx;
                            }
                        }
                    }
                    if (qoPB)
                    {
                        unsigned int qdmSnI = qArxcFu + 1;
                        unsigned short qSuoDt = qxWmVch[qOFvKuu];
                        unsigned short qbGYp = qxWmVch[(qOFvKuu + 1) % 3];
                        Pt3X qzzQr = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qSuoDt);
                        Pt3X qsAu = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qbGYp);
                        Pt3X qArJcY = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qxWmVch[(qOFvKuu + 2) % 3]);
                        float qnuVZg = 0.37f;
                        float qqtISP = 0.33f;
                        float qdbVTq = 0.3f;
                        Pt3X qHVMR = qsAu * qnuVZg + qzzQr * qqtISP + qArJcY * qdbVTq;
                        unsigned short qhxpxJd[3];
                        reinterpret_cast<::FUN_006a5b30_shell *>((qYdAnhh))->GetTripleShorts((short *)(unsigned short *)(&qhxpxJd[0]), (short *)(unsigned short *)(&qhxpxJd[1]), (short *)(unsigned short *)(&qhxpxJd[2]));
                        if (false && qQGWBE > 2)
                        {
                        }  // release build: index assert compiled out
                        Pt3X qyFp = ((NavMeshX*)qfpzU)->kVerts.GetAt(qhxpxJd[qQGWBE]);
                        Pt3X qVar = ((NavMeshX*)qfpzU)->kVerts.GetAt(qhxpxJd[(qQGWBE + 1) % 3]);
                        Pt3X qOqnE = ((NavMeshX*)qfpzU)->kVerts.GetAt(qhxpxJd[(qQGWBE + 2) % 3]);
                        Pt3X qkbsJ = qyFp * qnuVZg + qVar * qqtISP + qOqnE * qdbVTq;
                        qZWI.GetAt(qArxcFu) = qHVMR;
                        qZWI.GetAt(qdmSnI) = qkbsJ;
                        qrKBG.GetAt(qArxcFu) = true;
                        qrKBG.GetAt(qdmSnI) = false;
                        qpqRa.GetAt(qArxcFu) = aColors[2];
                        qpqRa.GetAt(qdmSnI) = aColors[9];
                        qArxcFu += 2;
                    }
                }
                if (qpydTG[qOFvKuu] > qrUCJDN || qZNIZJV)
                {
                    qDdzMIp.GetAt(qpia) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qxWmVch[qOFvKuu]);
                    qDdzMIp.GetAt(qxDeKK) = ((NavMeshX*)qsSDDgz)->kVerts.GetAt(qxWmVch[(qOFvKuu + 1) % 3]);
                    qHXYKT.GetAt(qpia) = true;
                    qHXYKT.GetAt(qxDeKK) = false;
                    if (qpydTG[qOFvKuu] != 0xffff)
                    {
                        if (qZNIZJV)
                        {
                            qGfbX.GetAt(qpia) = aColors[0];
                            qGfbX.GetAt(qxDeKK) = aColors[0];
                        }
                        else
                        {
                            qGfbX.GetAt(qpia) = aColors[0];
                            qGfbX.GetAt(qxDeKK) = aColors[0];
                        }
                    }
                    else
                    {
                        unsigned short qXGDO = 0;
                        bool qnEqwa = false;
                        bool qtOMjSX = false;
                        if (qOFvKuu < 2u)
                            reinterpret_cast<::FUN_00691040_shell *>((qidnYUK))->GetPackedFlags(qOFvKuu, &qXGDO, &qnEqwa, &qtOMjSX);
                        switch (qXGDO)
                        {
                        case 0:
                            qGfbX.GetAt(qpia) = aColors[6];
                            qGfbX.GetAt(qxDeKK) = aColors[6];
                            break;
                        case 1:
                            qGfbX.GetAt(qpia) = aColors[10];
                            qGfbX.GetAt(qxDeKK) = aColors[10];
                            break;
                        case 2:
                            qGfbX.GetAt(qpia) = aColors[5];
                            qGfbX.GetAt(qxDeKK) = aColors[5];
                            break;
                        case 0xf:
                            qGfbX.GetAt(qpia) = aColors[9];
                            qGfbX.GetAt(qxDeKK) = aColors[9];
                            break;
                        default:
                            qGfbX.GetAt(qpia) = aColors[7];
                            qGfbX.GetAt(qxDeKK) = aColors[7];
                            break;
                        }
                        if (::DAT_011d6e28 && qXGDO > 1u)
                        {
                            float qObI = ::ScaleClampedValue(qXGDO);
                            AVObjX* qYePyBl = ((::AVObjX *)(::FUN_00c55d50((::Point3 *)&(qDdzMIp.GetAt(qpia)), (::Point3 *)&(qDdzMIp.GetAt(qxDeKK)), xfCoverWidth,
                                                        xfCoverWidth, qObI, 0.0f, (::FilterData *)&(qGfbX.GetAt(qpia)), (::FilterData *)(0))));
                            ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qYePyBl, true);
                            Pt3X qZgNzZy = qDdzMIp.GetAt(qpia) - qDdzMIp.GetAt(qxDeKK);
                            reinterpret_cast<::FUN_004a0c10_s *>(&(qZgNzZy))->FUN_004a0c10();
                            reinterpret_cast<::MyPoint439180 *>((void *)&(const ::Pt3X &)(qZgNzZy))->FUN_00439180(xfCoverScale);
                            if (qnEqwa)
                            {
                                Pt3X qqrLNms = qDdzMIp.GetAt(qxDeKK) - qZgNzZy;
                                Pt3X qYvz = qDdzMIp.GetAt(qxDeKK) + qZgNzZy;
                                AVObjX* qrBzVM = ((::AVObjX *)(::FUN_00c55d50((::Point3 *)&(qqrLNms), (::Point3 *)&(qYvz), xfCoverWidth2, xfCoverWidth2,
                                                           qObI + xfCoverOffset, 0.0f, (::FilterData *)&(aColors[10]), (::FilterData *)(0))));
                                ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qrBzVM, true);
                            }
                            if (qtOMjSX)
                            {
                                Pt3X qCVSV = qDdzMIp.GetAt(qpia) - qZgNzZy;
                                Pt3X qOPw = qDdzMIp.GetAt(qpia) + qZgNzZy;
                                AVObjX* qjThF = ((::AVObjX *)(::FUN_00c55d50((::Point3 *)&(qCVSV), (::Point3 *)&(qOPw), xfCoverWidth2, xfCoverWidth2,
                                                          qObI + xfCoverOffset, 0.0f, (::FilterData *)&(aColors[10]), (::FilterData *)(0))));
                                ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qjThF, true);
                            }
                        }
                    }
                    qpia += 2;
                }
            }
        }
        qbXcw = new Pt3X[qpia];
        qJDuOZ = new ColorX[qpia];
        qxQHW = new bool[qpia];
        memcpy(qbXcw, &qDdzMIp.GetAt(0), qpia * sizeof(Pt3X));
        memcpy(qJDuOZ, &qGfbX.GetAt(0), qpia * sizeof(ColorX));
        memcpy(qxQHW, &qHXYKT.GetAt(0), qpia);
        SpX<AVObjX> qrzAir(new LinesX(qpia, qbXcw, qJDuOZ, 0, 0, 0, qxQHW));
        SpX<AVObjX> qdqWL(new PropX());
        ((AVObjX*)qdqWL)->SetFlags(0x20, 0);
        reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qrzAir)))->FUN_00439410((::ArgObject *)(::AVObjX *)(qdqWL));
        reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qrzAir)))->FUN_00439410((::ArgObject *)(::AVObjX *)(spWireframe));
        reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qrzAir)))->FUN_00439410((::ArgObject *)(::AVObjX *)(spZBuffer));
        reinterpret_cast<::FUN_00440460_S *>((((AVObjX*)qrzAir)))->FUN_00440460((const ::V3 *)(const ::Pt3PodX *)(((::Pt3PodX *)(reinterpret_cast<::FUN_00416870_t *>((void *)&(const ::Pt3PodX &)(Pt3PodX()))->FUN_00416870(0.0f, 0.0f, 1.0f)))));
        SpX<AVObjX> qvyWyw(0);
        if (qArxcFu > 0)
        {
            Pt3X* qOHwfb = new Pt3X[qArxcFu];
            ColorX* qkPflib = new ColorX[qArxcFu];
            bool* qEXZLB = new bool[qArxcFu];
            memcpy(qOHwfb, &qZWI.GetAt(0), qArxcFu * sizeof(Pt3X));
            memcpy(qkPflib, &qpqRa.GetAt(0), qArxcFu * sizeof(ColorX));
            memcpy(qEXZLB, &qrKBG.GetAt(0), qArxcFu);
            qvyWyw = new LinesX(qArxcFu, qOHwfb, qkPflib, 0, 0, 0, qEXZLB);
            qdqWL = new PropX();
            ((AVObjX*)qdqWL)->SetFlags(0x20, 0);
            reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qvyWyw)))->FUN_00439410((::ArgObject *)(::AVObjX *)(qdqWL));
            reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qvyWyw)))->FUN_00439410((::ArgObject *)(::AVObjX *)(spZBuffer));
            reinterpret_cast<::FUN_00440460_S *>((((AVObjX*)qvyWyw)))->FUN_00440460((const ::V3 *)(const ::Pt3PodX *)(((::Pt3PodX *)(reinterpret_cast<::FUN_00416870_t *>((void *)&(const ::Pt3PodX &)(Pt3PodX()))->FUN_00416870(0.0f, 0.0f, 3.0f)))));
        }
        qFffvLe = new Pt3X[qXMUYT];
        qZAdkzg = new ColorX[qXMUYT];
        memcpy(qFffvLe, &qkJsUdT.GetAt(0), qXMUYT * sizeof(Pt3X));
        memcpy(qZAdkzg, &qrEZrs.GetAt(0), qXMUYT * sizeof(ColorX));
        SpX<AVObjX> qpTd(new TriShapeX(qXMUYT, qFffvLe, 0, qZAdkzg, 0, 0, 0, qMBds, qaGEwZ));
        ::AssignFixedString((char *)(((AVObjX*)qpTd)), (std::intptr_t)&(const ::FixedStrX &)(FixedStrX("NavMesh Triangles")), {});
        SpX<AVObjX> qSVM(new PropX());
        ((AVObjX*)qSVM)->SetFlags(0x20, 0);
        reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qpTd)))->FUN_00439410((::ArgObject *)(::AVObjX *)(spVertexColor));
        reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qpTd)))->FUN_00439410((::ArgObject *)(::AVObjX *)(spZBuffer));
        reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qpTd)))->FUN_00439410((::ArgObject *)(::AVObjX *)(qSVM));
        reinterpret_cast<::FUN_00440460_S *>((((AVObjX*)qpTd)))->FUN_00440460((const ::V3 *)(const ::Pt3PodX *)(((::Pt3PodX *)(reinterpret_cast<::FUN_00416870_t *>((void *)&(const ::Pt3PodX &)(Pt3PodX()))->FUN_00416870(0.0f, 0.0f, 1.0f)))));
        for (unsigned int qMFd = 0; qMFd < reinterpret_cast<::FUN_00691620_shell *>((((NavMeshX*)qsSDDgz)))->GetFlags(); qMFd++)
        {
            SphereX* qsCroYH = &(*(::SphereX *)(reinterpret_cast<::FUN_00691640_shell *>((((NavMeshX*)qsSDDgz)))->FUN_00691640(qMFd)));
            ColorX qODE(0.25f, 0.0f, 0.0f, 0.5f);
            SpX<AVObjX> qFwpo(((::AVObjX *)(::FUN_00c56680(reinterpret_cast<::BSMultiBoundSphere *>((void *)(qsCroYH))->GetRadius(), 10, 10, (const ::Color4 *)(::ColorX *)(&qODE)))));
            SpX<AVObjX> qmgeiw(new AlphaX());
            reinterpret_cast<::FUN_0049ed90_shell *>((((AVObjX*)qmgeiw)))->FUN_0049ed90(true);
            reinterpret_cast<::FUN_00439410_cls *>((((AVObjX*)qFwpo)))->FUN_00439410((::ArgObject *)(::AVObjX *)(qmgeiw));
            reinterpret_cast<::FUN_00440460_S *>((((AVObjX*)qFwpo)))->FUN_00440460((const ::V3 *)(const ::Pt3PodX *)(((::Pt3PodX *)((void *)(qsCroYH)))));
            ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qFwpo, true);
        }
        ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qrzAir, true);
        ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qpTd, true);
        if (qArxcFu > 0)
            ((NodeX*)qAhbO)->AttachChildInAvailableSlot(qvyWyw, true);
        ::fnv_004b6e90::AttachLightingPropertyRecursive((::NiAVObject *)(::NodeX *)(qAhbO));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::NodeX *)(qAhbO), 0, 0);
    }
    if (abUpdate)
    {
        UpdateDataX qBQkjNg(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NodeX*)(*reinterpret_cast<::SpX< ::NodeX> *>(&::g_011d6e5c)))))->FUN_00a59c60((std::intptr_t)&(qBQkjNg));
        reinterpret_cast<::FUN_00a5a040_Class *>((((NodeX*)(*reinterpret_cast<::SpX< ::NodeX> *>(&::g_011d6e5c)))))->FUN_00a5a040();
    }
}

// Returns a color code chosen from the triangle's object count and its flags/checks, defaulting to 0.
// @fnv 0x006a5da0
int NavRenderStub::GetNavTriColor(NavTriStub* pNavTri)
{
    int iColorCode = 0;
    if (((unsigned short)(reinterpret_cast<::FUN_00699790_shell *>((pNavTri))->GetBits13To15())) > 0)
    {
        if (reinterpret_cast<::FUN_00691140_shell *>((pNavTri))->FUN_00691140(0x100))
        {
            iColorCode = 12;
        }
        else
        {
            iColorCode = 11;
        }
    }
    else if (reinterpret_cast<::FUN_00693b70_shell *>((pNavTri))->HasFlag40())
    {
        if (reinterpret_cast<::FUN_00690e70_shell *>((pNavTri))->IsFlag400Set())
        {
            iColorCode = 5;
        }
        else if (reinterpret_cast<::FUN_006a5ec0_shell *>((pNavTri))->FUN_006a5ec0())
        {
            iColorCode = 8;
        }
        else
        {
            iColorCode = 13;
        }
    }
    else if (reinterpret_cast<::FUN_006a5ec0_shell *>((pNavTri))->FUN_006a5ec0())
    {
        iColorCode = 7;
    }
    else if (reinterpret_cast<::S00693b90 *>((pNavTri))->FUN_00693b90())
    {
        iColorCode = 14;
    }
    else if (reinterpret_cast<::FUN_00690e70_shell *>((pNavTri))->IsFlag400Set())
    {
        iColorCode = 4;
    }
    else if (reinterpret_cast<::FUN_00691140_shell *>((pNavTri))->FUN_00691140(0x1000))
    {
        iColorCode = 9;
    }
    else if (reinterpret_cast<::FUN_00691140_shell *>((pNavTri))->FUN_00691140(0x80000000))
    {
        iColorCode = 16;
    }
    return iColorCode;
}

#include "generated/data/fallout_shared/pathfinding/navmeshrender.inc"
