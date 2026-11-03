// fallout_shared/testerrainlodmanager.cpp: free functions (11 functions)

#include <cstdint>
#include <new>
#include <cmath>
#include "fnv/decl/B3CA80Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/FNv53b450_Source.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00451900_shell.h"
#include "fnv/decl/FUN_004572e0_shell.h"
#include "fnv/decl/FUN_004573f0_shell.h"
#include "fnv/decl/FUN_0045c9a0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_0053a510.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_0099e040_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FrustumPlanes__Planes.h"
#include "fnv/decl/GlobalObject_0045cf30.h"
#include "fnv/decl/GraphicsRenderer.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TerrainOwner.h"
#include "fnv/decl/ThisC.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0053fa10__TESObjectLAND.h"
#include "fnv/decl/xLand.h"
#include "fnv/decl/xWorldC.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0057c000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_0057e000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00b60000.h"
#include "fnv/symbols_00b61000.h"
#include "fnv/symbols_00b62000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01200000.h"
#include "testerrainlodmanager_unit.h"

// @fnv 0x0057d090
NiFixedString* FUN_0057d090()
{
    return DAT_011c6224;
}


// @fnv 0x0057ce70
void __cdecl SetWindMagnitudeRange(float afWindMagMin, float afWindMagMax)
{
    DAT_01200500 = afWindMagMin;
    DAT_01200504 = afWindMagMax;
}

float FUN_0057dd90(float value);

// @fnv 0x0057dd70
float FUN_0057dd70(float value)
{
    return FUN_0057dd90(value);
}


// @fnv 0x0057dd90
float FUN_0057dd90(float value)
{
    return static_cast<float>(std::tan(value));
}

extern int DAT_011ca444;

struct FUN_0057ce90_shell
{
    ~FUN_0057ce90_shell();
};

// Decrements DAT_011ca444; when it reaches zero, deletes DAT_011ca43c and DAT_011ca440 and clears both pointers.
// @fnv 0x0057ce90
FUN_0057ce90_shell::~FUN_0057ce90_shell()
{
    if (--DAT_011ca444 == 0)
    {
        if ((*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca43c)))
        {
            void* p = (*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca43c));
            ::FUN_00401030(p);
            (*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca43c)) = 0;
        }
        if ((*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca440)))
        {
            void* q = (*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca440));
            ::FUN_00401030(q);
            (*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca440)) = 0;
        }
    }
}

// Truncates p[0] and p[1] to ints via FUN_00404040 and packs x into the high 16 bits and y into the low 16 bits.
// @fnv 0x0057ddb0
int __cdecl PackFloatPairToInt(float* afValues)
{
    int x;
    int y;
    x = (int)FUN_00404040(afValues[0]);
    y = (int)FUN_00404040(afValues[1]);
    return (x << 16) | (y & 0xffff);
}

struct Setting_S
{
};
struct GlobalObject_0045cfe0
{
};
struct TallGrassShaderProperty
{
    static int __cdecl GetCacheIdentifier();
public:
    static void ClearCacheData();
};
struct B006815c0
{
    char d[12];
    B006815c0();
};
void __cdecl SetWindMagnitudeRange(float, float);
extern int DAT_011ca444;

struct FUN_0057cd10
{
    char _pad_0[1];
    FUN_0057cd10();
};

// @fnv 0x0057cd10
FUN_0057cd10::FUN_0057cd10()
{
    if (!DAT_011ca444)
    {
        int isizecap = (TallGrassShaderProperty::GetCacheIdentifier() << 8) / *((int *)&(::FUN_0043d4d0((int *)&(::g_011ca524))));
        if (!(*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca43c)))
            (*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca43c)) = new B006815c0[isizecap * isizecap];
        if (!(*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca440)))
            (*reinterpret_cast<void * *>(&::fnv_0057de00::DAT_011ca440)) = new int[isizecap * isizecap];
    }
    DAT_011ca444++;
    SetWindMagnitudeRange(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011ca48c)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011ca510)))))));
}

namespace fnv_0057cf00 {
struct AutoMemHelper
{
    AutoMemHelper(int a, bool b, const char* file, int line);
    ~AutoMemHelper();
    int iOld;
};
struct Setting_S
{
};
struct GlobalObject_0045cfe0
{
};
struct NiAVObject
{
};
struct NiNode : public NiAVObject
{
    NiNode(unsigned short count);
    char pad[0xac];
};
struct BaseNodeV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void SetAt(unsigned int index, NiAVObject* child);
};
struct NiAdditionalGeometryData
{
};
extern double DAT_01011588;
extern float DAT_011ca434;

// Computes a clamped max range from settings and stores it, then creates a named NiNode, attaches it at index 6, and sets a flag.
// @fnv 0x0057cf00
void UpdateTerrainLODMaxRange()
{
    AutoMemHelper tempMemContext(
        0x1c, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESTerrainLODManager.cpp", 0x90);
    float fmaxrange = 0.0f;
    if (::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0057cf00::Setting_S *>(&::fnv_007d1fb0::DAT_011ca450)))) >= ::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0057cf00::Setting_S *>(&::g_011ca4ac)))) + 0.5f)
        fmaxrange = ::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0057cf00::Setting_S *>(&::fnv_007d1fb0::DAT_011ca450)))) + ::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0057cf00::Setting_S *>(&::g_011ca498))));
    if (fmaxrange > (float)(unsigned int)(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0057cf00::GlobalObject_0045cfe0 *>(&::g_011c63cc)))) << 12))
        fmaxrange = (float)(unsigned int)(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0057cf00::GlobalObject_0045cfe0 *>(&::g_011c63cc)))) << 12);
    DAT_011ca434 = fmaxrange;
    BaseNodeV* pbasenode = ((::fnv_0057cf00::BaseNodeV *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
    (*reinterpret_cast<::fnv_0057cf00::NiNode * *>(&::DAT_011ca438)) = new NiNode(0);
    ::AssignFixedString((char *)((*reinterpret_cast<::fnv_0057cf00::NiNode * *>(&::DAT_011ca438))), (int)&(*FUN_0057d090()), {});
    pbasenode->SetAt(6, (*reinterpret_cast<::fnv_0057cf00::NiNode * *>(&::DAT_011ca438)));
    reinterpret_cast<::FUN_00a5a040_Class *>(((*reinterpret_cast<::fnv_0057cf00::NiNode * *>(&::DAT_011ca438))))->FUN_00a5a040();
    ::TerrainLOD::DAT_011ca430 = true;
}
}  // namespace fnv_0057cf00

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

namespace fnv_0057de00 {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float fX, float fY, float fZ);
    NiPoint3 operator+(const NiPoint3& kPoint) const;
    NiPoint3 operator-(const NiPoint3& kPoint) const;
      // Unitize
};
}  // namespace fnv_0057de00

namespace TerrainLOD {
struct AutoMemContext
{
    int context;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
extern const char DAT_010310d8[];
struct Point3
{
    float x, y, z;
};
struct TwoComponentVector
{
    float x, y;
    TwoComponentVector(float, float);
};
struct UpdateData
{
    float time;
    unsigned int flags, unk08;
    UpdateData(float, bool, bool);
};
struct FixedName;
struct TerrainNode
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual TerrainNode* Find(FixedName*);
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void Attach(TerrainNode*, bool);
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    TerrainNode(unsigned short);
};
struct Cell
{
};
struct World
{
};
struct Setting
{
    bool* FUN_00408d60();
};
// @fnv 0x0057d0a0
void FUN_0057d0a0(Point3 position, Point3 direction, float scale)
{
    AutoMemContext contextSlot1(28, true, DAT_010310d8, 177);
    if (((void *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TerrainLOD::World * *>(&::g_TES))))->GetPrevPath())) || !*(*reinterpret_cast<::TerrainLOD::Setting *>(&::g_011ca4f0)).FUN_00408d60() || !DAT_0118c000)
    {
        ::TallGrassShaderProperty::ClearCacheData();
        return;
    }
    if (!DAT_011ca430)
        ::fnv_0057cf00::UpdateTerrainLODMaxRange();
    ::DAT_011f9ef0 = *(*reinterpret_cast<::TerrainLOD::Setting *>(&::g_011ca480)).FUN_00408d60();
    float farDistanceSlot0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TerrainLOD::Setting *>(&::fnv_007d1fb0::DAT_011ca450)))))) + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TerrainLOD::Setting *>(&::g_011ca498))))));
    float nearDistanceSlot2 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TerrainLOD::Setting *>(&::fnv_007d1fb0::DAT_011ca450))))));
    if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TerrainLOD::Setting *>(&::fnv_007d1fb0::DAT_011ca450)))))) < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TerrainLOD::Setting *>(&::g_011ca4ac)))))) + 0.5f)
        return;
    if (!(*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438)))
    {
        TerrainNode* rootSlot0 = ((::TerrainLOD::TerrainNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
        TerrainNode* foundSlot8 = rootSlot0->Find(((::TerrainLOD::FixedName *)(::FUN_0057d090())));
        (*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438)) = foundSlot8;
        if (!(*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438)))
        {
            (*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438)) = new TerrainNode(0);
            ::AssignFixedString((char *)((*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438))), (std::intptr_t)(((::TerrainLOD::FixedName *)(::FUN_0057d090()))), {});
            rootSlot0->Attach((*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438)), true);
        }
    }
    ::FUN_00b60120(0, 0, nearDistanceSlot2, farDistanceSlot0);
    if (true)
    {
        int cellXSlot13 = 0;
        int cellYSlot13 = 0;
        cellXSlot13 = (int)position.x / 4096;
        cellYSlot13 = (int)position.y / 4096;
        if (position.x < 0.0)
            --cellXSlot13;
        if (position.y < 0.0)
            --cellYSlot13;
        Cell* cellSlot17 = ((::TerrainLOD::Cell *)(reinterpret_cast<::FUN_00451900_shell *>(((*reinterpret_cast<::TerrainLOD::World * *>(&::g_TES))))->FUN_00451900(cellXSlot13, cellYSlot13)));
        TwoComponentVector relativeSlot42(position.x, position.y);
        relativeSlot42.x -= float(cellXSlot13 << 12);
        relativeSlot42.y -= float(cellYSlot13 << 12);
        for (int row = 0; row < 5; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                cellSlot17 = ((::TerrainLOD::Cell *)(reinterpret_cast<::FUN_00451900_shell *>(((*reinterpret_cast<::TerrainLOD::World * *>(&::g_TES))))->FUN_00451900(cellXSlot13 + row - 2, cellYSlot13 + column - 2)));
                if (cellSlot17)
                {
                    bool skip = true;
                    if (row != 0 && row != 4 && column != 0 && column != 4 &&
                        farDistanceSlot0 > reinterpret_cast<::ThisC *>((cellSlot17))->FUN_0054fb70((::Pt2 *)(::TerrainLOD::Point3 *)(&position)))
                    {
                        ::FUN_0057d4f0((::Mgr *)(cellSlot17), (std::intptr_t)((*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438))), (*(::NiPoint3 *)&(const ::TerrainLOD::Point3 &)(position)), (*(::NiPoint3 *)&(const ::TerrainLOD::Point3 &)(direction)), nearDistanceSlot2, farDistanceSlot0,
                                     scale);
                        skip = false;
                    }
                    if (skip)
                        ::FUN_00b61570(reinterpret_cast<::TESObjectCELL *>((cellSlot17))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((cellSlot17))->GetCellGridY());
                }
            }
        }
    }
    if (((bool)(reinterpret_cast<::GlobalObject_0045cf30 *>(&((*reinterpret_cast<::TerrainLOD::Setting *>(&::g_011ca480))))->GetBoolValue())))
        reinterpret_cast<::S00b5d9f0_Owner *>((((::TerrainLOD::TerrainNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5d9f0((::S00b5d9f0_Obj *)((*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438))), 0);
    if ((*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438)))
    {
        UpdateData update(0, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>(((*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438))))->FUN_00a59c60((std::intptr_t)(&update));
        reinterpret_cast<::FUN_00a5a040_Class *>(((*reinterpret_cast<::TerrainLOD::TerrainNode * *>(&::DAT_011ca438))))->FUN_00a5a040();
    }
}
}

// Terrain LOD grass/object sampling pass: builds a culling frustum from the camera, then walks the
// loaded cells' height samples and dispatches matching object records.
struct CellForm
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c();
    virtual void v020(), v024(), v028(), v02c(), v030(), v034(), v038(), v03c();
    virtual void v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c();
    virtual void v060(), v064(), v068(), v06c(), v070(), v074(), v078(), v07c();
    virtual void v080(), v084(), v088(), v08c(), v090(), v094(), v098();
    virtual unsigned char IsInFrustum(void* apPlanes);
    virtual void v0a0(), v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc();
    virtual void v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(), v0dc();
    virtual void v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc();
    virtual void v100(), v104(), v108(), v10c(), v110(), v114(), v118(), v11c();
    virtual void v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c();
    virtual void v140(), v144(), v148(), v14c(), v150(), v154(), v158(), v15c();
    virtual void v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c();
    virtual void v180(), v184();
    virtual unsigned char Get188();
    virtual void v18c();
    virtual unsigned char Get190();
    virtual void v194(), v198(), v19c();
    virtual unsigned short Get1a0();
    virtual void v1a4();
    virtual int Get1a8();
};
struct NiBound
{
    float x, y, z, radius;
};
struct NiPlaneX
{
    float x, y, z, d;
};
struct FUN_0045c620
{
    NiPlaneX m_akPlanes[6];
    unsigned int m_uiActive;
    unsigned int m_uiPad;
    FUN_0045c620();
};
struct Tmp53a510
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct NiFrustum
{
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
    NiFrustum(bool abOrtho);
};
struct NiRenderer
{
};
struct CamNode
{
};
struct ModelOps
{
};
struct Node45
{
};
struct CellObj
{
};
struct Obj30
{
};
struct NiNodeHelper
{
};
struct FormKind
{
};
struct Mgr
{
};
extern unsigned char DAT_011ca534;
int FUN_0057ce60();
bool FUN_00b617b0(const char*, const char*);
float __cdecl FUN_0057dd70(float);
int __cdecl PackFloatPairToInt(float*);

// @fnv 0x0057d4f0
void __cdecl FUN_0057d4f0(Mgr* apMgr, std::intptr_t aiParam, NiPoint3 akPos, NiPoint3 akDir, float afParam1, float afRadius,
                          float afFov)
{
    int iQuad;
    if (DAT_011ca534)
        return;
    int** ppEntries = 0;
    int iEntry;
    BSSimpleList<const char*> kModelList;
    CellForm* pBase = 0;
    Tmp53a510 kHelper;
    new ((void *)&(kHelper)) ::FUN_0053a510();
    unsigned short usW = 0;
    unsigned char bFlagA6 = 0;
    unsigned char bFlagB = 0;
    NiPoint3 kTmpPt;
    int iSampleIdx;
    NiPoint3 kPosB;
    NiPoint3 kPos;
    int iStart4 = FUN_0057ce60();
    int iDelta = iStart4 * 2;
    int iCount2 = 8;
    if (apMgr == 0 || ((std::intptr_t)(reinterpret_cast<::TESObjectCELL *>((apMgr))->GetParentWorldSpace())) == 0 || ((::Obj30 *)(reinterpret_cast<::S00546fb0_Cell *>((apMgr))->FUN_00546fb0())) == 0)
        return;
    float fScaleF4 = reinterpret_cast<::FUN_005471e0_shell *>((apMgr))->FUN_005471e0();
    Obj30* pData30 = ((::Obj30 *)(reinterpret_cast<::S00546fb0_Cell *>((apMgr))->FUN_00546fb0()));
    int m_iGridPositionX = reinterpret_cast<::TESObjectCELL *>((apMgr))->GetCellGridX();
    int iLodLevel5 = reinterpret_cast<::TESObjectCELL *>((apMgr))->GetCellGridY();
    iSampleIdx = 0;
    akDir.z = 0.0f;
    reinterpret_cast<::FUN_004a0c10_s *>(&(akDir))->FUN_004a0c10();
    afFov = afFov * 2.0f;
    NiFrustum kFrust(false);
    float fW = (float)reinterpret_cast<::GraphicsRenderer *>((::FUN_0043c4b0()))->GetRenderTargetHeight();
    float fScreenH4 = (float)reinterpret_cast<::GraphicsRenderer *>((::FUN_0043c4b0()))->GetRenderTargetWidth();
    float kFAspectRatio = fW / fScreenH4;
    float fFactorB = 0.75 / (fW / fScreenH4);
    float fTheta = reinterpret_cast<::FUN_0099e040_shell *>((((::Node45 *)(::FUN_0045c670()))))->FUN_0099e040() * 0.01745329238474369 * 0.5 + afFov;
    kFrust.m_fLeftBound = -FUN_0057dd70(fTheta) * fFactorB;
    kFrust.m_fRightBound = FUN_0057dd70(fTheta) * fFactorB;
    kFrust.m_fBottomBound = -FUN_0057dd70(fTheta) * kFAspectRatio * fFactorB;
    kFrust.m_fTopBound = FUN_0057dd70(fTheta) * kFAspectRatio * fFactorB;
    NiFrustum kViewFrustum_2 = reinterpret_cast<::NiCamera *>((((CamNode*)((::ModelOps *)(reinterpret_cast<::BSFaceGenNiNode *>((((::Node45 *)(::FUN_0045c670()))))->GetAnimationData())))))->GetViewFrustum();
    kFrust.m_fFarPlane = kViewFrustum_2.m_fFarPlane;
    kFrust.m_fNearPlane = kViewFrustum_2.m_fNearPlane;
    FUN_0045c620 kTester;
    reinterpret_cast<::FrustumPlanes::Planes *>(&(kTester))->SetFromFrustum((const ::FrustumPlanes::Frustum *)(const void *)(&kFrust), (const ::FrustumPlanes::Transform *)(void *)(((void *)(::FUN_00461130((std::intptr_t)(((CamNode*)((::ModelOps *)(reinterpret_cast<::BSFaceGenNiNode *>((((::Node45 *)(::FUN_0045c670()))))->GetAnimationData())))))))));
    for (iQuad = 0; iQuad < 4; iQuad++)
    {
        CellObj* pCell = ((::CellObj *)(reinterpret_cast<::FUN_0045c9a0_shell *>((apMgr))->GetCellNodeAt(iQuad)));
        if (pCell)
        {
            NiPoint3 kStartPt = (*(::NiPoint3 *)(reinterpret_cast<::FNv53b450_Source *>((pData30))->FUN_0053b450((::FNv53b450_Point *)(0), 0, 0, (const int *)(0), {})));
            std::intptr_t iV1b8 = 0;
            NiBound kBounds = (*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((pCell))->FUN_0043d450()));
            NiPoint3 kNone = ::NiPoint3::ZERO;
            float fDist = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((akPos - (*(const ::NiPoint3 *)((void *)&(kBounds))))))->ComputeMagnitude() - reinterpret_cast<::Twin_0084d030 *>((void *)&(kBounds))->GetStoredFloatValue();
            Node45* pAt = ((::Node45 *)(reinterpret_cast<::NiNode *>((((::NiNodeHelper *)(reinterpret_cast<::TESObjectCELL *>((apMgr))->GetCellChildAt(2)))))->GetAt({})));
            std::intptr_t eState = ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((FormKind*)((::CellForm *)(::fnv_0043b230::FUN_0043b230((const char *)(((::ModelOps *)(reinterpret_cast<::BSFaceGenNiNode *>((pAt))->GetAnimationData())))))))))->GetName()));
            unsigned char bProjectedOnScreen = ((::CellForm *)(::fnv_0043b230::FUN_0043b230((const char *)(((::ModelOps *)(reinterpret_cast<::BSFaceGenNiNode *>((pAt))->GetAnimationData()))))))->IsInFrustum(&kTester);
            if ((eState == 1 || eState == 0 || bProjectedOnScreen) && fDist < afRadius)
            {
                for (int iX = iStart4; iX < 0x10; iX += iDelta)
                {
                    for (int iY = iStart4; iY < 0x10; iY += iDelta)
                    {
                        iSampleIdx = iY * 0x11 + iX;
                        kPos = (*(::NiPoint3 *)(reinterpret_cast<::FNv53b450_Source *>((pData30))->FUN_0053b450((::FNv53b450_Point *)((unsigned char)iQuad), (unsigned short)iSampleIdx, 0, (const int *)(0), {})));
                        kPos.z = akPos.z;
                        kPos.x = kPos.x - 256.0;
                        kPos.y = kPos.y - 256.0;
                        iV1b8 = PackFloatPairToInt(&kPos.x);
                        ppEntries = ((int **)(reinterpret_cast<::B3CA80Owner *>((pData30))->FUN_0053ca80(iQuad, iSampleIdx)));
                        iEntry = 0;
                        while (ppEntries != 0 && ppEntries[iEntry] != 0 && iEntry < 0x10 && ppEntries[iEntry][0] != 0)
                        {
                            if (ppEntries[iEntry] != 0)
                            {
                                if (!FUN_00b617b0((const char*)ppEntries[iEntry][1], (const char*)iV1b8))
                                {
                                    pBase = ((::CellForm *)(::FUN_004839c0(ppEntries[iEntry][1])));
                                    if (pBase != 0)
                                    {
                                        usW = pBase->Get1a0();
                                        iCount2 = pBase->Get1a8();
                                        bFlagB = pBase->Get190();
                                        bFlagA6 = pBase->Get188();
                                    }
                                    ::fnv_0057de00::GenerateGrassPositions(m_iGridPositionX, iLodLevel5, iQuad, (::fnv_0057de00::LODLand *)(pData30), (void *)(iV1b8), (*(const ::fnv_0057de00::NiPoint3 *)(&kPos)), aiParam,
                                                           (*(::fnv_0057de00::NiPoint3 *)&(const ::NiPoint3 &)(akPos)), (::fnv_0057de00::LODSettings *)(ppEntries[iEntry]), (float *)(int *)(ppEntries[iEntry] + 8), afParam1,
                                                           afRadius, usW, iCount2, fScaleF4, bFlagA6, bFlagB);
                                }
                            }
                            iEntry++;
                        }
                    }
                }
            }
            else
            {
                for (int iX2 = iStart4; iX2 < 0x10; iX2 += iDelta)
                {
                    for (int iY2 = iStart4; iY2 < 0x10; iY2 += iDelta)
                    {
                        iSampleIdx = iY2 * 0x11 + iX2;
                        kPos = (*(::NiPoint3 *)(reinterpret_cast<::FNv53b450_Source *>((pData30))->FUN_0053b450((::FNv53b450_Point *)((unsigned char)iQuad), (unsigned short)iSampleIdx, 0, (const int *)(0), {})));
                        kPos.x = kPos.x - 256.0;
                        kPos.y = kPos.y - 256.0;
                        std::intptr_t iSample = PackFloatPairToInt(&kPos.x);
                        ::fnv_00b61370::FUN_00b61370((const char *)(iSample));
                    }
                }
            }
        }
        reinterpret_cast<::FileMatchList *>((void *)&(kModelList))->RemoveAll();
    }
}

namespace fnv_0057de00 {
enum MEM_CONTEXT
{
    MEM_CONTEXT_MEM_CONTEXT_GRASS = 28,
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* pObject = 0);
    ~NiPointer();
};

class AutoMemContext
{
  public:
    int iPrevious;
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bOverride, const char* pcFile, int iLine);
    ~AutoMemContext();
};

class BSFogProperty
{
  public:
    void IncRefCount();
    void DecRefCount();
};


class FUN_00414430_Color
{
  public:
    float r, g, b, a;
    FUN_00414430_Color(float fR, float fG, float fB, float fA);
};

class FUN_0053a510_LandData
{
  public:
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
    FUN_0053a510_LandData();
};

class LODLand
{
  public:
};

class LODWorld
{
  public:
};

struct LODSettings
{
    int unk00;
    int unk04;
    float m_fHorizontalSpacing;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    bool bSlopeOnly;
    bool unk1d;
    bool bUseSlope;
};

struct LODIntSetting
{
};

int FUN_0057ce60();
float FUN_004dfea0();

// Samples a grid over the land, tests density and height/slope filters, and stores accepted positions and luminance values for the owner.
// @fnv 0x0057de00
void GenerateGrassPositions(int iA, int iB, int iUnused08, LODLand* pkLand, void* pvOwner, const NiPoint3& kBase,
                            std::intptr_t iC, NiPoint3 akStart, LODSettings* pkSettings, float* afDensityGrid, int iUnused34,
                            float fRadius, unsigned short usRange, int iMode, float afHeight, unsigned char ucMinAngle,
                            unsigned char ucMaxAngle)
{
    AutoMemContext kMemContextRef(MEM_CONTEXT_MEM_CONTEXT_GRASS, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESTerrainLODManager.cpp",
                                  522);
    NiPointer<BSFogProperty> spProperty;
    NiPoint3 kUnusedRef;
    float fMinSlopeRes = ::FUN_0057e960(ucMinAngle * 0.017453292f);
    float fMaxSlopeValue = ::FUN_0057e960(ucMaxAngle * 0.017453292f);
    fRadius *= fRadius;
    void* pvLandOwnerPos = pvOwner;
    bool bNotLoadedNew = !::FUN_00b61940(pkSettings, (const char *)(pvLandOwnerPos));
    if (!bNotLoadedNew || !reinterpret_cast<::TESPackage *>((pkLand))->FUN_005394a0())
        return;

    float fLodSize = FUN_0057ce60() << 8;
    unsigned short usSteps = (int)(fLodSize / pkSettings->m_fHorizontalSpacing);
    unsigned short usMaxStepsNew = (FUN_0057ce60() << 8) / *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0057de00::LODIntSetting *>(&::g_011ca524))))));
    if (usSteps > usMaxStepsNew)
        usSteps = usMaxStepsNew;
    FUN_0053a510_LandData kTheLandData;
    unsigned short usCountOld = 0;
    for (int i = 0; i < usSteps; i++)
    {
        for (int j = 0; j < usSteps; j++)
        {
            NiPoint3 kPosPos = kBase + NiPoint3(i * (fLodSize / usSteps), j * (fLodSize / usSteps), 0.0f);
            float fNewV = j * (3.0 / usSteps);
            float fTextureCoordinateU = i * (3.0 / usSteps);
            int iColEntry = ::FUN_00406d90(fTextureCoordinateU);
            int iRowNew = ::FUN_00406d90(fNewV);
            fTextureCoordinateU -= iColEntry;
            fNewV -= iRowNew;
            float fDensityAtRowColumn = 0.0f;
            float fAdjacentDensityGridValue = 0.0f;
            float fH01Out = 0.0f;
            float fH11Info = 0.0f;
            fDensityAtRowColumn = afDensityGrid[iRowNew * 3 + iColEntry];
            if (fTextureCoordinateU > 0.01)
            {
                if (iColEntry < 2)
                    fAdjacentDensityGridValue = afDensityGrid[iRowNew * 3 + iColEntry + 1];
                else
                    fAdjacentDensityGridValue = afDensityGrid[iRowNew * 3 + iColEntry];
                if (fNewV > 0.01)
                {
                    if (iRowNew < 2)
                    {
                        if (iColEntry < 2)
                            fH11Info = afDensityGrid[(iRowNew + 1) * 3 + iColEntry + 1];
                        else
                            fH11Info = afDensityGrid[(iRowNew + 1) * 3 + iColEntry];
                    }
                    else
                    {
                        if (iColEntry < 2)
                            fH11Info = afDensityGrid[iRowNew * 3 + iColEntry + 1];
                        else
                            fH11Info = afDensityGrid[iRowNew * 3 + iColEntry];
                    }
                }
            }
            if (fNewV > 0.01)
            {
                if (iRowNew < 2)
                    fH01Out = afDensityGrid[(iRowNew + 1) * 3 + iColEntry];
                else
                    fH01Out = afDensityGrid[iRowNew * 3 + iColEntry];
            }
            float fDensityIn =
                ((1.0f - fTextureCoordinateU) * fDensityAtRowColumn + fAdjacentDensityGridValue * fTextureCoordinateU) *
                    (1.0f - fNewV) +
                ((1.0f - fTextureCoordinateU) * fH01Out + fH11Info * fTextureCoordinateU) * fNewV;
            int iChanceRes = (unsigned int)(fDensityIn * 32768.0);
            if (iChanceRes && ((int)(::GetRandomNumberInRange(0, 0x7fff))) < iChanceRes)
            {
                float fGroundZ = 0.0f;
                float fRandTmp = FUN_004dfea0();
                kPosPos.x += fRandTmp * pkSettings->m_fHorizontalSpacing;
                fRandTmp = FUN_004dfea0();
                kPosPos.y += fRandTmp * pkSettings->m_fHorizontalSpacing;
                kPosPos.x = ::FUN_00404040(kPosPos.x);
                kPosPos.y = ::FUN_00404040(kPosPos.y);
                kPosPos.z = 0.0f;
                bool bOnLand = reinterpret_cast<::xLand *>((pkLand))->FUN_0053b550((*(::xCoordData *)(&kTheLandData)), (*(const ::xPoint3 *)(&kPosPos)), 0);
                reinterpret_cast<::FUN_004572e0_shell *>(((*reinterpret_cast<::fnv_0057de00::LODWorld * *>(&::g_TES))))->GetLandHeightAt((*(const ::NiPoint3 *)(&kPosPos)), (*(float *)(&fGroundZ)));
                switch (iMode)
                {
                case 0:
                    if (afHeight - usRange > fGroundZ)
                        continue;
                    break;
                case 1:
                    if (fGroundZ < afHeight || afHeight + usRange < fGroundZ)
                        continue;
                    break;
                case 2:
                    if (afHeight - usRange < fGroundZ)
                        continue;
                    break;
                case 3:
                    if (fGroundZ > afHeight || afHeight - usRange > fGroundZ)
                        continue;
                    break;
                case 4:
                    if (afHeight + usRange > fGroundZ && afHeight - usRange < fGroundZ)
                        continue;
                    break;
                case 5:
                    if (afHeight + usRange < fGroundZ || afHeight - usRange > fGroundZ)
                        continue;
                    break;
                }
                NiPoint3 kOffsetOld = kPosPos - akStart;
                kPosPos.z = ::FUN_00404040(fGroundZ);
                NiPoint3 kNormal;
                NiPoint3 kSlopeValue;
                if (bOnLand)
                    reinterpret_cast<::TerrainOwner *>((pkLand))->ComputeTerrainNormalAndTangent((::TerrainInput *)(::fnv_0057de00::FUN_0053a510_LandData *)(&kTheLandData), (::NiPoint3 *)(::fnv_0057de00::NiPoint3 *)(&kNormal), (::NiPoint3 *)(::fnv_0057de00::NiPoint3 *)(&kSlopeValue));
                else
                    reinterpret_cast<::FUN_004573f0_shell *>(((*reinterpret_cast<::fnv_0057de00::LODWorld * *>(&::g_TES))))->FUN_004573f0((const ::NiPoint3 *)(::fnv_0057de00::NiPoint3 *)(&kPosPos), (::NiPoint3 *)(::fnv_0057de00::NiPoint3 *)(&kNormal), (int)(&kSlopeValue));
                if (pkSettings->bUseSlope && pkSettings->bSlopeOnly)
                    kNormal = kSlopeValue;
                else if (pkSettings->bUseSlope && !pkSettings->bSlopeOnly)
                {
                    kNormal = kNormal + kSlopeValue;
                    reinterpret_cast<::FUN_004a0c10_s *>(&(kNormal))->FUN_004a0c10();
                }
                if (kNormal.z < fMaxSlopeValue || kNormal.z > fMinSlopeRes)
                    continue;
                kNormal.x = kNormal.x * 0.5 + 0.5;
                if (kNormal.x >= 0.97f)
                    kNormal.x = 0.97f;
                kNormal.y = kNormal.y * 0.5 + 0.5;
                if (kNormal.y >= 0.97f)
                    kNormal.y = 0.97f;
                kNormal.z = kNormal.z * 0.5 + 0.5;
                if (kNormal.z >= 0.97f)
                    kNormal.z = 0.97f;
                kPosPos.x += kNormal.x;
                kPosPos.y += kNormal.y;
                kPosPos.z += kNormal.z;
                FUN_00414430_Color kColor(0.0f, 0.0f, 0.0f, 0.0f);
                if (bOnLand)
                    reinterpret_cast<::fnv_0053fa10::TESObjectLAND *>((pkLand))->FUN_0053fa10((const ::fnv_0053fa10::LandscapeColorData *)(::fnv_0057de00::FUN_0053a510_LandData *)(&kTheLandData), (::fnv_0053fa10::RgbaColor *)(::fnv_0057de00::FUN_00414430_Color *)(&kColor));
                else
                    reinterpret_cast<::xWorldC *>(((*reinterpret_cast<::fnv_0057de00::LODWorld * *>(&::g_TES))))->FUN_00457520((const ::xPt3C *)(::fnv_0057de00::NiPoint3 *)(&kPosPos), (int)(&kColor));
                float fLuminanceNum = kColor.r * 0.31 + kColor.g * 0.37 + kColor.b * 0.32;
                kOffsetOld = kPosPos - akStart;
                DAT_011ca43c[usCountOld] = kPosPos;
                DAT_011ca440[usCountOld] = fLuminanceNum;
                usCountOld++;
            }
        }
    }
    if (usCountOld > 0)
        ::PopulateGrassInstances(pvLandOwnerPos, iA, iB, (::NiNodeStub *)(iC), (::GrassParamF *)(pkSettings), (float (*)[3])(DAT_011ca43c), DAT_011ca440, usCountOld);
}
}  // namespace fnv_0057de00

#include "generated/data/fallout_shared/testerrainlodmanager.inc"
