// fallout_shared/region_system/tesregiongrassobject.cpp: TESRegionGrassObject, PlcPlacer (8 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00461bc0_cls.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_0053a5e0_cls.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00740940_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/RegionCell.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESObjectLAND.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004f6000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "TESRegionGrassObject.h"

// @fnv 0x00403550
void TESRegionGrassObject::AssignLandTexture(TESLandTexture* apParent)
{
    pParent = apParent;
}

struct blob12
{
    char b[12];
};
struct RegionPoint
{
    void SetX(float);
    void SetY(float);
    void* GetAsNiPoint2();
    struct blob12 GetAsNiPoint3();
    RegionPoint* Copy(RegionPoint*);
    float GetDistance(void*);
    float GetDistanceToOtherPoint(void*);
    bool Collide(RegionPoint*, unsigned int);
    static float XIntercept(RegionPoint*, RegionPoint*, float);
    static bool LineSegmentsIntersect(RegionPoint*, RegionPoint*, RegionPoint*, RegionPoint*);
    static bool PointLiesOnLine(RegionPoint*, RegionPoint*, RegionPoint*, float);
    char Point[8];
};
struct FUN_0052ce20_shell : public RegionPoint
{
    void FUN_0052ce20(float);
};

// @fnv 0x0052ce20
void FUN_0052ce20_shell::FUN_0052ce20(float afX)
{
    *(float*)this = afX;
}

struct FUN_004f5600_shell
{
    int m_vftable;
    FUN_004f5600_shell();
};

extern int DAT_01023ee4;

// @fnv 0x004f5600
FUN_004f5600_shell::FUN_004f5600_shell()
{
    m_vftable = (int)&DAT_01023ee4;
}

extern int DAT_01023ec4;

struct FUN_004f5920_shell
{
    void FUN_004f5920();
};

// @fnv 0x004f5920
void FUN_004f5920_shell::FUN_004f5920()
{
    *reinterpret_cast<int**>(this) = &DAT_01023ec4;
}

namespace fnv_004f55d0 {
struct FUN_004f5920_shell
{
};
struct FUN_004f55d0_shell
{
    void* FUN_004f55d0(unsigned int);
};
// Calls FUN_004f5920 on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004f55d0
void* FUN_004f55d0_shell::FUN_004f55d0(unsigned int flags)
{
    reinterpret_cast<::FUN_004f5920_shell *>((((FUN_004f5920_shell*)this)))->FUN_004f5920();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_004f55d0

struct FUN_004f5590
{
    int first;
    int second;
    int third;
    FUN_004f5590(int a, int b);
};
struct FUN_004f5940_factory
{
    virtual void v0();
    virtual int GetFirst();
    virtual void v2();
    virtual int GetSecond();
    FUN_004f5590* FUN_004f5940(FUN_004f5590* existing);
};
// @fnv 0x004f5940
FUN_004f5590* FUN_004f5940_factory::FUN_004f5940(FUN_004f5590* existing)
{
    FUN_004f5590* result = existing != 0 ? existing : new FUN_004f5590(GetFirst(), GetSecond());
    return result;
}

struct PlcPoint2
{
    float x;
    float y;
};

struct PlcPoint3
{
    float x;
    float y;
    float z;

    PlcPoint3();
};

struct PlcModifier
{
    float fValueA;
    float fValueB;

    PlcModifier();
};

struct PlcSound
{
};

struct PlcWater
{
    PlcSound* GetSoundByEditorID(PlcPoint2* apPos);
    void GetHeight(PlcPoint2* apPos, float* apHeight);
};

struct PlcWorldSpace;

struct PlcCell
{
};

struct PlcDataHandler
{
};

struct PlcObject
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual unsigned char GetChance();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual float GetFirstFloat();
    virtual float GetSecondFloat();
    virtual unsigned short GetHeight();
    virtual void v1A4();
    virtual int GetPlacement();
};

struct PlcSoundHolder
{
    PlcSound* GetSoundByEditorID();
};



struct PlcPlacer
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual PlcSound* GetSoundByEditorID();
    PlcObject* pObject;

    float GetPlacementChance(PlcPoint2* apPos, PlcWorldSpace* apWorld, bool abApplyModifier);
};

// @fnv 0x004f59f0
float PlcPlacer::GetPlacementChance(PlcPoint2* apPos, PlcWorldSpace* apWorld, bool abApplyModifier)
{
    PlcModifier kModifier;
    float fResult = 0.0f;
    if (!pObject)
        return 0.0f;

    PlcObject* pObj8 = pObject;
    PlcCell* pCell8 = ((::PlcCell *)(reinterpret_cast<::FUN_00461bc0_cls *>(((*reinterpret_cast<::PlcDataHandler * *>(&::g_dataHandler))))->FUN_00461bc0(apPos->x, apPos->y, (::TESWorldSpace *)(apWorld), false)));
    if (!pCell8 || reinterpret_cast<::TESObjectCELL *>((pCell8))->IsCellInterior())
        return 0.0f;

    fResult = pObj8->GetChance() / 100.0;
    reinterpret_cast<::FUN_0052ce20_shell *>(&(kModifier))->FUN_0052ce20(apPos->x);
    reinterpret_cast<::FUN_004f5d90_shell *>(&(kModifier))->FUN_004f5d90(apPos->y);

    if (GetSoundByEditorID())
    {
        PlcSound* pSoundA = ((::PlcSound *)(reinterpret_cast<::FUN_0053a5e0_cls *>((((::PlcWater *)(reinterpret_cast<::S00546fb0_Cell *>((pCell8))->FUN_00546fb0()))))->FUN_0053a5e0((int)(apPos))));
        if (!pSoundA || ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSoundA))->FUN_0084e3a0())) != ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((GetSoundByEditorID()))->FUN_0084e3a0())))
            return 0.0f;
    }
    {

        float fHeightVal = pObject->GetHeight();
        float fWaterZ5 = reinterpret_cast<::FUN_005471e0_shell *>((pCell8))->FUN_005471e0();
        float fZ;
        reinterpret_cast<::TESObjectLAND *>((((::PlcWater *)(reinterpret_cast<::S00546fb0_Cell *>((pCell8))->FUN_00546fb0()))))->FUN_0053f180((*(const ::LandscapeColorData *)(apPos)), (*(float *)(&fZ)));

        switch (pObject->GetPlacement())
        {
        case 0:
            if (fWaterZ5 + fHeightVal > fZ)
                return 0.0f;
            break;
        case 1:
            if (fZ < fWaterZ5 || fWaterZ5 + fHeightVal < fZ)
                return 0.0f;
            break;
        case 2:
            if (fWaterZ5 - fHeightVal < fZ)
                return 0.0f;
            break;
        case 3:
            if (fZ > fWaterZ5 || fWaterZ5 - fHeightVal > fZ)
                return 0.0f;
            break;
        case 4: {
            float fDiff = ::FUN_00408860(fWaterZ5 - fZ);
            if (fDiff < fHeightVal)
                return 0.0f;
            break;
        }
        case 5: {
            float fDiff = ::FUN_00408860(fWaterZ5 - fZ);
            if (fDiff > fHeightVal)
                return 0.0f;
            break;
        }
        case 6:
            if (fWaterZ5 + fHeightVal < fZ)
                return 0.0f;
            break;
        case 7:
            if (fWaterZ5 - fHeightVal > fZ)
                return 0.0f;
            break;
        default:
            return 0.0f;
        }
    }

    {
        float fSlope_;
        {
            PlcPoint3 kA7;
            PlcPoint3 kB3;
            if (reinterpret_cast<::Owner *>((((::PlcWater *)(reinterpret_cast<::S00546fb0_Cell *>((pCell8))->FUN_00546fb0()))))->FUN_0053d2e0((std::intptr_t)(apPos), (std::intptr_t)(&kA7), (std::intptr_t)(&kB3)))
            {
                fSlope_ = ::FUN_004f6e00((*(int *)&(const ::PlcPoint3 &)(kA7)), {}, {});
                if (fSlope_ > pObject->GetSecondFloat() || fSlope_ < pObject->GetFirstFloat())
                    return 0.0f;
            }
        }
    }

    if (abApplyModifier)
        fResult *= reinterpret_cast<::RegionCell *>((pCell8))->FUN_0054fd70(&kModifier, 6, (::RegionQuery *)(void *)(this));
    return fResult;
}

struct RegionForm
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
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* Name();
    int Type();
};
struct RegionManager
{
    virtual RegionForm* Current();
};
struct Handler
{
};
struct BaseGrass
{
    BaseGrass();
    virtual void slot0();
};
struct GrassIds
{
    unsigned int object;
    unsigned int parent;
};
struct FUN_004f5620 : BaseGrass
{
    RegionForm* object;
    RegionForm* parent;
    FUN_004f5620(GrassIds* ids);
};
// Resolves the object and parent form IDs from GrassIds, validates their types, and assigns them to the object and parent fields with warnings on mismatch.
// @fnv 0x004f5620
FUN_004f5620::FUN_004f5620(GrassIds* apGrassIds)
{
    RegionForm* texture;
    RegionForm* grass;
    if ((*reinterpret_cast<::Handler * *>(&::g_dataHandler)) && ((::RegionManager *)(reinterpret_cast<::FUN_00740940_shell *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->GetRegionDataManager())) && ((::RegionManager *)(reinterpret_cast<::FUN_00740940_shell *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->GetRegionDataManager()))->Current())
    {
        RegionForm* pRegion = ((::RegionManager *)(reinterpret_cast<::FUN_00740940_shell *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->GetRegionDataManager()))->Current();
        unsigned int formId = apGrassIds->object;
        void* region = ((void *)(reinterpret_cast<::TESForm *>((pRegion))->GetFile(-1)));
        ::ResolveFormID(&formId, (::TESFile *)(region));
        texture = ((::RegionForm *)(::FUN_004839c0(formId)));
        formId = apGrassIds->parent;
        ::ResolveFormID(&formId, (::TESFile *)(region));
        grass = ((::RegionForm *)(::FUN_004839c0(formId)));
    }
    else
    {
        texture = ((::RegionForm *)(::FUN_004839c0(apGrassIds->object)));
        grass = ((::RegionForm *)(::FUN_004839c0(apGrassIds->parent)));
    }
    object = 0;
    if (texture)
    {
        if (texture->Type() == 0x24)
            object = texture;
        else
        {
            if (((::RegionManager *)(reinterpret_cast<::FUN_00740940_shell *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->GetRegionDataManager()))->Current())
                ::FUN_005b5e40();
            else
                ::FUN_005b5e40();
        }
    }
    else
    {
        if (((::RegionManager *)(reinterpret_cast<::FUN_00740940_shell *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->GetRegionDataManager()))->Current())
            ::FUN_005b5e40();
        else
            ::FUN_005b5e40();
    }
    parent = 0;
    if (object && grass)
    {
        if (grass->Type() == 0x12)
            parent = grass;
        else
            ::FUN_005b5e40();
    }
}
