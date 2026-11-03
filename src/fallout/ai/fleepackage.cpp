
// src/fallout/ai/fleepackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/fleepackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/A90Cls.h"
#include "fnv/decl/ActorInventoryQueryViews__ActorQuery.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSSimpleArray_PathingAvoidNode_1024.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00484d20_Class.h"
#include "fnv/decl/FUN_00484d40_Host.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00672fc0_shell.h"
#include "fnv/decl/FUN_00678fd0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00953c50_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LockExtraData.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/Package679120.h"
#include "fnv/decl/Package6798c0.h"
#include "fnv/decl/PackageEx.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00568fa0__Fn568fa0.h"
#include "fnv/decl/fnv_00575d10__FUN_00575d10_shell.h"
#include "fnv/decl/fnv_00671d30__FUN_00671d30_shell.h"
#include "fnv/decl/fnv_00679340__Package679.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006d6000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
struct FUN_009f1090_shell
{
    void FUN_009f10c0();
    void* DestroyIfFlagged(unsigned int flags);
};

struct PC7d;
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct PlayerCharacter
{
};
struct FUN_009f1990_shell
{
    bool FUN_009f1990();
};
// Returns true if the list at offset 0x98 has one entry that is the player and FUN_00953c50 fails; otherwise false.
// @fnv 0x009f1990
bool FUN_009f1990_shell::FUN_009f1990()
{
    if (((BSSimpleListTESRaceSize*)((char*)this + 0x98))->GetSize() == 1)
    {
        bool flag = false;
        {
            PC7d* item = *((::PC7d **)(((::Vec3 *)(void *)(((BSSimpleListTESRaceSize*)((char*)this + 0x98))))));
            if (item == (*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)))
            {
                if (!((bool)(reinterpret_cast<::FUN_00953c50_Class *>((((PlayerCharacter*)(*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)))))->FUN_00953c50((char *)(bool *)(&flag)))))
                    return true;
            }
        }
    }
    return false;
}

class ExtraRadioData;
struct TESObjectREFR
{
public:
    ::ExtraRadioData *GetExtraRadioData();
};
struct BSSimpleList_TESObjectREFR
{
    void AddHead(TESObjectREFR*&);
};
struct FleePackage
{
    char _pad[0x98];
    BSSimpleList_TESObjectREFR AvoidedRefList;
    void FUN_009f1310(TESObjectREFR* apRef);
};

// Adds apRef to AvoidedRefList if it is not already present.
// @fnv 0x009f1310
void FleePackage::FUN_009f1310(TESObjectREFR* apRef)
{
    if (!reinterpret_cast<::RefList *>(&(AvoidedRefList))->FUN_005f65d0((void **)&(apRef)))
        AvoidedRefList.AddHead(apRef);
}


enum PACKAGE_PROCEDURE_TYPE
{
    PACKAGE_PROCEDURE_TYPE_NONE = -1
};

class TESObjectREFR;
enum PACK_TARG_TYPE;
class PackageTargetRecord
{
  public:
    char pad[0x10];
    PackageTargetRecord();
    ~PackageTargetRecord();
    void SetTargetObjectReference(TESObjectREFR*);
public:
    ::TESObjectREFR *GetReferenceTarget();
public:
    void SetTargetKind(::PACK_TARG_TYPE);
};

class LocationDescriptor
{
  public:
    char pad[0xc];
    LocationDescriptor();
    ~LocationDescriptor();
    void FUN_0067f3c0(TESObjectREFR*);
};

struct TESObjectREFR_Flags
{
};

struct TESPackage
{
    char pad[0x7c];
    TESPackage();
    virtual ~TESPackage();
    void SetMustReachLocation(bool);
    void SetMustComplete(bool);
    void SetProcedureType(PACKAGE_PROCEDURE_TYPE);
};

struct FUN_009f9250 : public TESPackage
{
    float m_fPackageValue;
    int iUnk84;
    int iUnk88;
    int iUnk8c;
    int iUnk90;
    int iUnk94;
    int iUnk98;
    FUN_009f9250(TESObjectREFR* apRef, int a2, int a3, int a4);
    virtual ~FUN_009f9250();
};

struct Script
{
    char* GetData();
};
// Initializes the package fields, sets reach/complete flags and procedure type, and configures the target from apRef.
// @fnv 0x009f9250
FUN_009f9250::FUN_009f9250(TESObjectREFR* apRef, int aiUnk88, int aiUnk8c, int aiUnk94)
{
    m_fPackageValue = 0.0f;
    iUnk84 = 0;
    iUnk88 = aiUnk88;
    iUnk8c = aiUnk8c;
    reinterpret_cast<::PackageEx *>(this)->SetPackageType(0x17);
    SetMustReachLocation(true);
    SetMustComplete(true);
    PackageTargetRecord* pTarget;
    LocationDescriptor* ploc;
    ploc = new LocationDescriptor;
    ploc->FUN_0067f3c0(apRef);
    reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>(this)->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(ploc));
    delete ploc;
    pTarget = new PackageTargetRecord;
    reinterpret_cast<::FUN_00672fc0_shell *>(this)->FUN_00672fc0(pTarget);
    delete pTarget;
    SetProcedureType((PACKAGE_PROCEDURE_TYPE)0x14);
    ((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()))->SetTargetKind((::PACK_TARG_TYPE)(0));
    ((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()))->SetTargetObjectReference(apRef);
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR_Flags*)((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData())))))->AssignLandTexture((::TESLandTexture *)(0x80));
    iUnk90 = -1;
    iUnk94 = aiUnk94;
    iUnk98 = 0;
}
struct PTHelper
{
    void SetTargetObjectReference(TESObjectREFR*);
};
struct BSSimpleList_TESObjectREFR_Helper
{
    bool FUN_008256d0();
};

struct FUN_009f1350_shell
{
    void RemoveRef(TESObjectREFR* apRef);
};

// @fnv 0x009f1350
void FUN_009f1350_shell::RemoveRef(TESObjectREFR* apRef)
{
    reinterpret_cast<::ItemChangeListNode *>((((BSSimpleList_TESObjectREFR_Helper*)((char*)this + 0x98))))->FUN_00905330((::InventoryStackRecord *const &)(apRef));
    TESObjectREFR* pref = 0;
    if (((Script*)this)->GetData())
        pref = reinterpret_cast<::PackageTargetRecord *>((((PTHelper*)((Script*)this)->GetData())))->GetReferenceTarget();
    if (pref && pref == apRef)
    {
        if (!((BSSimpleList_TESObjectREFR_Helper*)((char*)this + 0x98))->FUN_008256d0())
        {
            ((PTHelper*)((Script*)this)->GetData())
                ->SetTargetObjectReference(*(((::TESObjectREFR **)(((::Vec3 *)(void *)(((BSSimpleList_TESObjectREFR_Helper*)((char*)this + 0x98))))))));
            ((LocationDescriptor*)((int)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)this)))->GetIconFormID())))
                ->FUN_0067f3c0(*(((::TESObjectREFR **)(((::Vec3 *)(void *)(((BSSimpleList_TESObjectREFR_Helper*)((char*)this + 0x98))))))));
        }
        else
        {
            ((PTHelper*)((Script*)this)->GetData())->SetTargetObjectReference(0);
            ((LocationDescriptor*)((int)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)this)))->GetIconFormID())))->FUN_0067f3c0(0);
        }
    }
    if (apRef == *(TESObjectREFR**)((char*)this + 0xa4))
        *(TESObjectREFR**)((char*)this + 0xa4) = 0;
}

struct TESObjectCELL;
struct NiPoint3
{
    float x;
    float y;
    float z;
};

extern const float runtimeFloatSettingDefault132;
extern int DAT_011f2f10;
extern TESObjectREFR* DAT_011f2f1c;

extern bool __cdecl CanActorReachReference(TESObjectREFR*, long);

struct TESObjectREFR_GetRefPersists
{
};

struct BSOcclusionPlane
{
};

struct TESDataHandler
{
    void GetReferencesInArea(TESObjectCELL*, NiPoint3 const&, float, NiPoint3 const&, float,
                             bool(__cdecl*)(TESObjectREFR*, long), long);
};

struct DH : public TESDataHandler
{
};


struct FUN_009f1140_VirtualTarget
{
    virtual int M000()
    {
        return 0;
    }
    virtual int M001()
    {
        return 0;
    }
    virtual int M002()
    {
        return 0;
    }
    virtual int M003()
    {
        return 0;
    }
    virtual int M004()
    {
        return 0;
    }
    virtual int M005()
    {
        return 0;
    }
    virtual int M006()
    {
        return 0;
    }
    virtual int M007()
    {
        return 0;
    }
    virtual int M008()
    {
        return 0;
    }
    virtual int M009()
    {
        return 0;
    }
    virtual int M010()
    {
        return 0;
    }
    virtual int M011()
    {
        return 0;
    }
    virtual int M012()
    {
        return 0;
    }
    virtual int M013()
    {
        return 0;
    }
    virtual int M014()
    {
        return 0;
    }
    virtual int M015()
    {
        return 0;
    }
    virtual int M016()
    {
        return 0;
    }
    virtual int M017()
    {
        return 0;
    }
    virtual int M018()
    {
        return 0;
    }
    virtual int M019()
    {
        return 0;
    }
    virtual int M020()
    {
        return 0;
    }
    virtual int M021()
    {
        return 0;
    }
    virtual int M022()
    {
        return 0;
    }
    virtual int M023()
    {
        return 0;
    }
    virtual int M024()
    {
        return 0;
    }
    virtual int M025()
    {
        return 0;
    }
    virtual int M026()
    {
        return 0;
    }
    virtual int M027()
    {
        return 0;
    }
    virtual int M028()
    {
        return 0;
    }
    virtual int M029()
    {
        return 0;
    }
    virtual int M030()
    {
        return 0;
    }
    virtual int M031()
    {
        return 0;
    }
    virtual int M032()
    {
        return 0;
    }
    virtual int M033()
    {
        return 0;
    }
    virtual int M034()
    {
        return 0;
    }
    virtual int M035()
    {
        return 0;
    }
    virtual int M036()
    {
        return 0;
    }
    virtual int M037()
    {
        return 0;
    }
    virtual int M038()
    {
        return 0;
    }
    virtual int M039()
    {
        return 0;
    }
    virtual int M040()
    {
        return 0;
    }
    virtual int M041()
    {
        return 0;
    }
    virtual int M042()
    {
        return 0;
    }
    virtual int M043()
    {
        return 0;
    }
    virtual int M044()
    {
        return 0;
    }
    virtual int M045()
    {
        return 0;
    }
    virtual int M046()
    {
        return 0;
    }
    virtual int M047()
    {
        return 0;
    }
    virtual int M048()
    {
        return 0;
    }
    virtual int M049()
    {
        return 0;
    }
    virtual int M050()
    {
        return 0;
    }
    virtual int M051()
    {
        return 0;
    }
    virtual int M052()
    {
        return 0;
    }
    virtual int M053()
    {
        return 0;
    }
    virtual int M054()
    {
        return 0;
    }
    virtual int M055()
    {
        return 0;
    }
    virtual int M056()
    {
        return 0;
    }
    virtual int M057()
    {
        return 0;
    }
    virtual int M058()
    {
        return 0;
    }
    virtual int M059()
    {
        return 0;
    }
    virtual int M060()
    {
        return 0;
    }
    virtual int M061()
    {
        return 0;
    }
    virtual int M062()
    {
        return 0;
    }
    virtual int M063()
    {
        return 0;
    }
    virtual int M064()
    {
        return 0;
    }
    virtual int M065()
    {
        return 0;
    }
    virtual int M066()
    {
        return 0;
    }
    virtual int M067()
    {
        return 0;
    }
    virtual int M068()
    {
        return 0;
    }
    virtual int M069()
    {
        return 0;
    }
    virtual int M070()
    {
        return 0;
    }
    virtual int M071()
    {
        return 0;
    }
    virtual int M072()
    {
        return 0;
    }
    virtual int M073()
    {
        return 0;
    }
    virtual int M074()
    {
        return 0;
    }
    virtual int M075()
    {
        return 0;
    }
    virtual int M076()
    {
        return 0;
    }
    virtual int M077()
    {
        return 0;
    }
    virtual int M078()
    {
        return 0;
    }
    virtual int M079()
    {
        return 0;
    }
    virtual int M080()
    {
        return 0;
    }
    virtual int M081()
    {
        return 0;
    }
    virtual int M082()
    {
        return 0;
    }
    virtual int M083()
    {
        return 0;
    }
    virtual int M084()
    {
        return 0;
    }
    virtual int M085()
    {
        return 0;
    }
    virtual int M086()
    {
        return 0;
    }
    virtual int M087()
    {
        return 0;
    }
    virtual int M088()
    {
        return 0;
    }
    virtual int M089()
    {
        return 0;
    }
    virtual int M090()
    {
        return 0;
    }
    virtual int M091()
    {
        return 0;
    }
    virtual int M092()
    {
        return 0;
    }
    virtual int M093()
    {
        return 0;
    }
    virtual int M094()
    {
        return 0;
    }
    virtual int M095()
    {
        return 0;
    }
    virtual int M096()
    {
        return 0;
    }
    virtual int M097()
    {
        return 0;
    }
    virtual int M098()
    {
        return 0;
    }
    virtual int M099()
    {
        return 0;
    }
    virtual int M100()
    {
        return 0;
    }
    virtual int M101()
    {
        return 0;
    }
    virtual int M102()
    {
        return 0;
    }
    virtual int M103()
    {
        return 0;
    }
    virtual int M104()
    {
        return 0;
    }
    virtual int M105()
    {
        return 0;
    }
    virtual int M106()
    {
        return 0;
    }
    virtual int M107()
    {
        return 0;
    }
    virtual int M108()
    {
        return 0;
    }
    virtual int M109()
    {
        return 0;
    }
    virtual int M110()
    {
        return 0;
    }
    virtual int M111()
    {
        return 0;
    }
    virtual int M112()
    {
        return 0;
    }
    virtual int M113()
    {
        return 0;
    }
    virtual int M114()
    {
        return 0;
    }
    virtual int M115()
    {
        return 0;
    }
    virtual int M116()
    {
        return 0;
    }
    virtual int M117()
    {
        return 0;
    }
    virtual int M118()
    {
        return 0;
    }
    virtual int M119()
    {
        return 0;
    }
    virtual int M120()
    {
        return 0;
    }
    virtual int M121()
    {
        return 0;
    }
    virtual int M122()
    {
        return 0;
    }
    virtual int M123()
    {
        return 0;
    }
    virtual int M124()
    {
        return 0;
    }
    virtual NiPoint3* Target()
    {
        return 0;
    }
};

struct FUN_009f1140_shell
{
    char pad_000[0x80];
    unsigned char flag_080;
    char pad_081[0x1F];
    int result_0A0;

    bool FUN_009f1140(TESObjectREFR* apRef, TESObjectREFR* apContext);
};

// @fnv 0x009f1140
bool FUN_009f1140_shell::FUN_009f1140(TESObjectREFR* apRef, TESObjectREFR* apContext)
{
    if (!flag_080)
        return false;

    if (!apContext)
        return false;

    DAT_011f2f1c = apContext;

    if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((reinterpret_cast<TESObjectREFR_GetRefPersists*>(apRef)))->FUN_005653d0())
    {
        g_dataHandler->GetReferencesInArea(
            reinterpret_cast<TESObjectCELL*>(((int)(reinterpret_cast<::LowProcess *>((void *)(reinterpret_cast<BSOcclusionPlane*>(apRef)))->GetTarget()))),
            *reinterpret_cast<FUN_009f1140_VirtualTarget*>(apRef)->Target(), runtimeFloatSettingDefault132,
            *reinterpret_cast<FUN_009f1140_VirtualTarget*>(apRef)->Target(), runtimeFloatSettingDefault132,
            CanActorReachReference, reinterpret_cast<long>(apRef));
    }

    result_0A0 = DAT_011f2f10;
    DAT_011f2f1c = 0;
    DAT_011f2f10 = 0;

    return result_0A0 != 0;
}

struct Saver
{
};

struct TESSaveLoadGame
{
};

struct SaveManager;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct TESFormVirtualBase
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
};

struct TESForm : public TESFormVirtualBase
{
    virtual char* FUN_0130();
public:
    bool GetDisabled() const;
};

char* TESForm::FUN_0130()
{
    return 0;
}


struct Interface
{
};

extern const char str_01093344[];
extern const char $SG7035[];
extern const char $SG7038[];

struct HitSound
{
    unsigned int formID;
    unsigned char padding;
    unsigned int flags;
};

struct FUN_009f19f0_shell
{
    char _pad[0x98];
    BSSimpleList_TESObjectREFR AvoidedRefList;

    unsigned short GetSaveSize();
};

// @fnv 0x009f19f0
unsigned short FUN_009f19f0_shell::GetSaveSize()
{
    unsigned short usSize = 0;
    unsigned short usOldSize;

    usSize += reinterpret_cast<::FUN_00678fd0_shell *>((reinterpret_cast<Saver*>(this)))->FUN_00678fd0();
    usOldSize = usSize;

    if (reinterpret_cast<::FUN_00862110_cls *>((reinterpret_cast<TESSaveLoadGame*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        usSize += 4;
        usSize += 2;
    }

    usSize += reinterpret_cast<BSSimpleListTESRaceSize*>(&AvoidedRefList)->GetSize() * 4 + 2;
    usSize += 4;
    usSize += 4;
    usSize += 1;
    usSize += 1;
    usSize += 1;
    usSize += 4;
    usSize += 12;
    usSize += 1;
    usSize += 1;

    if (*::g_011de4e8.Bool())
    {
        HitSound* m_pContactSound =
            reinterpret_cast<HitSound*>(((void *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<TESSaveLoadGame*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->GetHitSound())));

        if (m_pContactSound)
        {
            TESForm* pForm = ::FUN_004839c0(m_pContactSound->formID);

            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }

    return usSize;
}

struct FUN_006797c0_arg;
struct FUN_006797c0_shell
{
public:
    void FUN_006797c0(::FUN_006797c0_arg *);
};

struct SaveFormIDHelper
{
};

struct BGSSaveFormBuffer : public SaveFormIDHelper
{
};

struct BSSimpleList
{
};

struct FUN_009f2380_shell : public FUN_006797c0_shell
{
    void SaveExtraData(BGSSaveFormBuffer*);
};

// Serializes the object's extra fields and its reference list into the save buffer, then writes the reference count and a form value.
// @fnv 0x009f2380
void FUN_009f2380_shell::SaveExtraData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    BSSimpleList* isaveGameBufferPos;
    unsigned int pForm;
    unsigned int isaveGameCount;
    TESObjectREFR* pCurrentElementNext;

    this->FUN_006797c0((::FUN_006797c0_arg *)(apSaveGameBuffer));

    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x80), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x81), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x84), 0xc, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x90), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x94), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0xa8), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0xa9), 1, 0);

    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0xa0)), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0xa4)), 0);

    isaveGameCount = 0;
    pForm = reinterpret_cast<::FUN_00865f20_shell *>((apSaveGameBuffer))->FUN_00865f20();
    isaveGameBufferPos = (BSSimpleList*)((char*)this + 0x98);

    while (isaveGameBufferPos != 0)
    {
        pCurrentElementNext = *((::TESObjectREFR **)(((::Vec3 *)(void *)(isaveGameBufferPos))));
        if (pCurrentElementNext != 0)
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pCurrentElementNext), 0);
            ++isaveGameCount;
        }
        isaveGameBufferPos = ((::BSSimpleList *)(reinterpret_cast<::Callees *>((isaveGameBufferPos))->FUN_00726070()));
    }

    reinterpret_cast<::FUN_00865ff0_shell *>((apSaveGameBuffer))->FUN_00865ff0(isaveGameCount, pForm);
}

struct BGSLoadFormBuffer
{
};

struct G2
{
    void AddHead(int*);
};

struct TESPackage_LoadGameHelper
{
};

struct FUN_009f24d0_shell
{
    void FUN_009f24d0(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Calls LoadGame, reads several fields from the buffer, then reads a count and loads that many TESObjectREFR forms into the list at offset 0x98.
// @fnv 0x009f24d0
void FUN_009f24d0_shell::FUN_009f24d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::Package6798c0 *>((reinterpret_cast<TESPackage_LoadGameHelper*>(this)))->LoadPackage((::LoadBuffer6798c0 *)(apLoadGameBuffer));

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x80)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x81)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x84)), 0x0c);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x90)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x94)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa8)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa9)), 1);

    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa0)));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa4)));

    unsigned int isaveGameCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
    {
        unsigned int uiIndex;
        for (uiIndex = 0; uiIndex < isaveGameCount; uiIndex++)
        {
            TESObjectREFR* pForm = 0;
            reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&pForm));
            reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x98)->AddHead(reinterpret_cast<int*>(&pForm));
        }
    }
}

// FindNearestRef: flee-package helper: scan avoided-ref list, pick nearest candidate.
struct FUN_009f1210_ref;
struct FUN_009f1210_node
{
};
struct FUN_009f1210_ref
{
    virtual void M000();
    virtual void M001();
    virtual void M002();
    virtual void M003();
    virtual void M004();
    virtual void M005();
    virtual void M006();
    virtual void M007();
    virtual void M008();
    virtual void M009();
    virtual void M010();
    virtual void M011();
    virtual void M012();
    virtual void M013();
    virtual void M014();
    virtual void M015();
    virtual void M016();
    virtual void M017();
    virtual void M018();
    virtual void M019();
    virtual void M020();
    virtual void M021();
    virtual void M022();
    virtual void M023();
    virtual void M024();
    virtual void M025();
    virtual void M026();
    virtual void M027();
    virtual void M028();
    virtual void M029();
    virtual void M030();
    virtual void M031();
    virtual void M032();
    virtual void M033();
    virtual void M034();
    virtual void M035();
    virtual void M036();
    virtual void M037();
    virtual void M038();
    virtual void M039();
    virtual void M040();
    virtual void M041();
    virtual void M042();
    virtual void M043();
    virtual void M044();
    virtual void M045();
    virtual void M046();
    virtual void M047();
    virtual void M048();
    virtual void M049();
    virtual void M050();
    virtual void M051();
    virtual void M052();
    virtual void M053();
    virtual void M054();
    virtual void M055();
    virtual void M056();
    virtual void M057();
    virtual void M058();
    virtual void M059();
    virtual void M060();
    virtual void M061();
    virtual void M062();
    virtual void M063();
    virtual void M064();
    virtual void M065();
    virtual void M066();
    virtual void M067();
    virtual void M068();
    virtual void M069();
    virtual void M070();
    virtual void M071();
    virtual void M072();
    virtual void M073();
    virtual void M074();
    virtual void M075();
    virtual void M076();
    virtual void M077();
    virtual void M078();
    virtual void M079();
    virtual void M080();
    virtual void M081();
    virtual void M082();
    virtual void M083();
    virtual void M084();
    virtual void M085();
    virtual void M086();
    virtual void M087();
    virtual void M088();
    virtual void M089();
    virtual void M090();
    virtual void M091();
    virtual void M092();
    virtual void M093();
    virtual void M094();
    virtual void M095();
    virtual void M096();
    virtual void M097();
    virtual void M098();
    virtual void M099();
    virtual void M100();
    virtual void M101();
    virtual void M102();
    virtual void M103();
    virtual void M104();
    virtual void M105();
    virtual void M106();
    virtual void M107();
    virtual void M108();
    virtual void M109();
    virtual void M110();
    virtual void M111();
    virtual void M112();
    virtual void M113();
    virtual void M114();
    virtual void M115();
    virtual void M116();
    virtual void M117();
    virtual void M118();
    virtual void M119();
    virtual void M120();
    virtual void M121();
    virtual void M122();
    virtual void M123();
    virtual void M124();
    virtual void M125();
    virtual void M126();
    virtual void M127();
    virtual void M128();
    virtual void M129();
    virtual void M130();
    virtual void M131();
    virtual void M132();
    virtual void M133();
    virtual void M134();
    virtual void M135();
    virtual void M136();
    virtual void M137();
    virtual void M138();
    virtual bool M139(int a);
};
struct FUN_009f1210_cls
{
    char pad_000[0x80];
    unsigned char flag_080;
    char pad_081[0x17];
    FUN_009f1210_node list_098;
    FUN_009f1210_ref* FindNearestRef(FUN_009f1210_ref* apRef);
};

// @fnv 0x009f1210
FUN_009f1210_ref* FUN_009f1210_cls::FindNearestRef(FUN_009f1210_ref* apRef)
{
    if (flag_080 == 0 || !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((apRef))->FUN_005653d0())
    {
        return 0;
    }
    FUN_009f1210_node* nodeB = &list_098;
    float best = ::DAT_01016970;
    FUN_009f1210_ref* result2 = 0;
    float d2;
    FUN_009f1210_ref* cand;
    while (nodeB != 0 && *((::FUN_009f1210_ref **)(((::Vec3 *)(void *)(nodeB)))) != 0)
    {
        cand = *((::FUN_009f1210_ref **)(((::Vec3 *)(void *)(nodeB))));
        nodeB = ((::FUN_009f1210_node *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
        d2 = reinterpret_cast<::RefS *>((cand))->FUN_005723b0((::RefS *)(apRef), 0, 0);
        if (reinterpret_cast<::TESForm *>((cand))->GetDisabled() || cand->M139(0))
        {
            reinterpret_cast<::FUN_009f1350_shell *>(this)->RemoveRef((::TESObjectREFR *)(cand));
            nodeB = &list_098;
        }
        else if (best > d2)
        {
            best = d2;
            result2 = cand;
        }
    }
    return result2;
}

struct AvoidedReference
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
    virtual bool IsActor();
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
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool IsDead(int);
};
struct AvoidedList
{
    AvoidedReference* value;
    AvoidedList* next;
    void FUN_0063f7b0();
};
struct AvoidanceSetting
{
};
struct AvoidanceContext
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual double GetLastTime(AvoidedReference*, int);
};
struct AvoidancePackage
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
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
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
    unsigned char unk80;
    bool timed;
    unsigned short unk82;
    unsigned int unk84, unk88, unk8C, unk90, unk94;
    AvoidedList avoided;
    void RemoveInvalidAvoidedReferences(AvoidanceContext*);
};
// @fnv 0x009f1830
void AvoidancePackage::RemoveInvalidAvoidedReferences(AvoidanceContext* context)
{
    AvoidedList* current = &avoided;
    float limit2 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AvoidanceSetting *>(&::originalRuntimeFloatSetting234))))));
    while (current && ((::AvoidedReference *)(((::Vec3 *)(void *)(current)))))
    {
        AvoidedReference* reference6 = ((::AvoidedReference *)(((::Vec3 *)(void *)(current))));
        AvoidedReference* actor = reference6->IsActor() ? reference6 : 0;
        bool remove4 = reference6->IsDead(0) || reinterpret_cast<::FUN_00440d80_shell *>((reference6))->FUN_00440d80();
        if (!remove4 && actor && timed)
        {
            remove4 = (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((actor))->FUN_00493bb0())) && actor != (*reinterpret_cast<::AvoidedReference * *>(&::_g_thePlayer))) ||
                      (context && ((double)(::FUN_00435dd0())) - context->GetLastTime(actor, 0) > limit2);
        }
        if (remove4)
        {
            current->FUN_0063f7b0();
            current = &avoided;
            continue;
        }
        current = ((::AvoidedList *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
    }
}

// Destructor: empty the owned list explicitly, then the list member and the base clean up.

class F10C0List
{
  public:
    ~F10C0List();

    void* m_pkHead;
    void* m_pkTail;
};

class F10C0Base
{
  public:
    virtual ~F10C0Base();
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
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
};

class FUN_009f10c0 : public F10C0Base
{
  public:
    virtual ~FUN_009f10c0();

    F10C0List m_kList;
};
// Calls FUN_009f10c0, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009f1090
void* FUN_009f1090_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_009f10c0 *>(this)->FUN_009f10c0::~FUN_009f10c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that removes all entries from m_kList.
// @fnv 0x009f10c0
FUN_009f10c0::~FUN_009f10c0()
{
    reinterpret_cast<::FileMatchList *>(&(m_kList))->RemoveAll();
}

struct PathingAvoidanceNode
{
    unsigned int a, b, c, d, e, f, g, h, i;
    PathingAvoidanceNode(NiPoint3 const&, float, float);
};

struct PathingAvoidNodeArray
{
    PathingAvoidanceNode** nodes;
    unsigned int size;
    unsigned int capacity;
    unsigned int flags;
    unsigned int growth;
    unsigned int ownership;

    PathingAvoidNodeArray();
};

struct FUN_00672930_flags
{
};

struct ActorView
{
};

struct AvoidedRefTarget
{
    virtual void m000();
    virtual void m001();
    virtual void m002();
    virtual void m003();
    virtual void m004();
    virtual void m005();
    virtual void m006();
    virtual void m007();
    virtual void m008();
    virtual void m009();
    virtual void m010();
    virtual void m011();
    virtual void m012();
    virtual void m013();
    virtual void m014();
    virtual void m015();
    virtual void m016();
    virtual void m017();
    virtual void m018();
    virtual void m019();
    virtual void m020();
    virtual void m021();
    virtual void m022();
    virtual void m023();
    virtual void m024();
    virtual void m025();
    virtual void m026();
    virtual void m027();
    virtual void m028();
    virtual void m029();
    virtual void m030();
    virtual void m031();
    virtual void m032();
    virtual void m033();
    virtual void m034();
    virtual void m035();
    virtual void m036();
    virtual void m037();
    virtual void m038();
    virtual void m039();
    virtual void m040();
    virtual void m041();
    virtual void m042();
    virtual void m043();
    virtual void m044();
    virtual void m045();
    virtual void m046();
    virtual void m047();
    virtual void m048();
    virtual void m049();
    virtual void m050();
    virtual void m051();
    virtual void m052();
    virtual void m053();
    virtual void m054();
    virtual void m055();
    virtual void m056();
    virtual void m057();
    virtual void m058();
    virtual void m059();
    virtual void m060();
    virtual void m061();
    virtual void m062();
    virtual void m063();
    virtual void m064();
    virtual void m065();
    virtual void m066();
    virtual void m067();
    virtual void m068();
    virtual void m069();
    virtual void m070();
    virtual void m071();
    virtual void m072();
    virtual void m073();
    virtual void m074();
    virtual void m075();
    virtual void m076();
    virtual void m077();
    virtual void m078();
    virtual void m079();
    virtual void m080();
    virtual void m081();
    virtual void m082();
    virtual void m083();
    virtual void m084();
    virtual void m085();
    virtual void m086();
    virtual void m087();
    virtual void m088();
    virtual void m089();
    virtual void m090();
    virtual void m091();
    virtual void m092();
    virtual void m093();
    virtual void m094();
    virtual void m095();
    virtual void m096();
    virtual void m097();
    virtual void m098();
    virtual void m099();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual void m115();
    virtual void m116();
    virtual void m117();
    virtual void m118();
    virtual void m119();
    virtual void m120();
    virtual void m121();
    virtual void m122();
    virtual void m123();
    virtual void m124();
    virtual NiPoint3* GetPos();
};



struct AvoidancePackage_1440 : public AvoidancePackage
{
    PathingAvoidNodeArray* BuildAvoidNodeArray();
};

// @fnv 0x009f1440
PathingAvoidNodeArray* AvoidancePackage_1440::BuildAvoidNodeArray()
{
    PathingAvoidNodeArray* pNodes_ = new PathingAvoidNodeArray;
    float fRadius3 = ((::PackageTargetRecord *)(reinterpret_cast<::Script *>((((TESPackage*)this)))->GetData()))
                         ? (float)((int)(reinterpret_cast<::Twin_0044ddc0 *>((((FUN_00672930_flags*)((::PackageTargetRecord *)(reinterpret_cast<::Script *>((((TESPackage*)this)))->GetData())))))->GetName()))
                         : ::DAT_010231a0;
    fRadius3 = FUN_00404010(fRadius3, ::DAT_01032adc);
    AvoidedList* pNode;
    float fRadius4;
    AvoidedReference* pRef;
    unsigned int iSize;
    for (pNode = &avoided; pNode != 0; pNode = ((::AvoidedList *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))
    {
        pRef = ((::AvoidedReference *)(((::Vec3 *)(void *)(pNode))));
        if (!pRef || reinterpret_cast<::TESForm *>((((ActorView*)pRef)))->GetDisabled() || pRef->IsDead(0))
            continue;

        iSize = ((int)(reinterpret_cast<::Twin_0044ddc0 *>((((FUN_00672930_flags*)pNodes_)))->GetName()));
        reinterpret_cast<::BSSimpleArray_PathingAvoidNode_1024 *>((pNodes_))->SetSize(iSize + 1, true);
        fRadius4 = FUN_00404010(fRadius3 * fRadius3, ::DAT_01016410);
        *((::PathingAvoidanceNode *)(reinterpret_cast<::S3e60 *>((pNodes_))->FUN_006a1400(iSize))) = PathingAvoidanceNode(*((AvoidedRefTarget*)pRef)->GetPos(), fRadius3, fRadius4);
    }
    return pNodes_;
}

struct DoorAccess
{
    unsigned int flags;
    TESObjectREFR* destination;
};
struct ReferenceAccess
{
};
class PathingLocation
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int unk14, unk18, unk1c, unk20, unk24;
    PathingLocation(TESObjectREFR*);
    PathingLocation(NiPoint3 const&, TESObjectREFR*);
    ~PathingLocation();
};

// @fnv 0x009f1600
bool __cdecl CanActorReachReference(TESObjectREFR* reference, long context)
{
    float fDistance;
    {
        ReferenceAccess* pActor;
        {
            float m_fUnknownValue2;
            {
                float fTargetDistance;
                {
                    int iAccessResult;
                    if (!reference || reinterpret_cast<::FUN_00440d80_shell *>((((ReferenceAccess*)reference)))->FUN_00440d80() ||
                        reinterpret_cast<::FUN_004077c0_shell *>((((ReferenceAccess*)reference)))->FUN_004077c0() || reinterpret_cast<::TESForm *>((((ReferenceAccess*)reference)))->GetDisabled())
                        return false;
                    iAccessResult = 0;
                    pActor = (ReferenceAccess*)context;
                    if (!pActor)
                        return false;
                    if (((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((ReferenceAccess*)reference)))->FUN_007af430())) == (*reinterpret_cast<void * *>(&::DAT_011ca258)))
                        return false;
                    if (!((void *)(reinterpret_cast<::TESObjectREFR *>((((ReferenceAccess*)reference)))->GetExtraRadioData())))
                        return false;
                    m_fUnknownValue2 = DAT_011f2f1c && reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((ReferenceAccess*)DAT_011f2f1c)))->FUN_00575d10()
                                           ? ::DAT_0101e704
                                           : ::g_011c7344_arg1;
                    fDistance = reinterpret_cast<::RefS *>((((ReferenceAccess*)reference)))->FUN_005723b0((::RefS *)(pActor), 0, 0);
                    fTargetDistance = reinterpret_cast<::RefS *>((((ReferenceAccess*)reference)))->FUN_005723b0((::RefS *)(::ReferenceAccess *)((ReferenceAccess*)DAT_011f2f1c), 0, 0);
                    if (fTargetDistance > m_fUnknownValue2 || fTargetDistance > fDistance)
                    {
                        DoorAccess* door = ((::DoorAccess *)(reinterpret_cast<::FUN_00569160_shell *>((((ReferenceAccess*)reference)))->FUN_00569160()));
                        if (door && reinterpret_cast<::LockExtraData *>((door))->IsLocked() && !reinterpret_cast<::OwnershipReferenceView *>((((ReferenceAccess*)reference)))->FUN_005785e0((::Actor *)(pActor), true))
                        {
                            if (!door->destination || !reinterpret_cast<::ActorInventoryQueryViews::ActorQuery *>((pActor))->FUN_00891db0((::TESBoundObject *)(door->destination), 0, 1, 0, (*(int *)(&iAccessResult))))
                                return false;
                        }
                        PathingLocation actorLocation((TESObjectREFR*)pActor);
                        PathingLocation referenceLocation((*(const ::NiPoint3 *)&(reinterpret_cast<::fnv_00568fa0::Fn568fa0 *>((((ReferenceAccess*)reference)))->FUN_00568fa0())), reference);
                        if (!((bool)(::CallWithNullArgs(&actorLocation, &referenceLocation, (void *)(0)))))
                            return false;
                        DAT_011f2f10 = (int)reference;
                        return true;
                    }
                    return false;
                }
            }
        }
    }
}

struct SavedReference
{
};
struct SavedReferenceList
{
    SavedReference* value;
    SavedReferenceList* next;
    bool FUN_008256d0();
};
struct SaveDebugRecord
{
    unsigned int formID;
    unsigned char state;
    unsigned char flags;
};
struct SaveStream
{
};
struct FleeSavePackage
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned char flag80, flag81;
    unsigned short unk82;
    NiPoint3 position;
    float timer;
    unsigned char flag94;
    SavedReferenceList avoided;
    SavedReference* referenceA;
    SavedReference* referenceB;
    unsigned char flagA8, flagA9;
    void SaveFleePackage();
};
// @fnv 0x009f1b70
void FleeSavePackage::SaveFleePackage()
{
    reinterpret_cast<::Package679120 *>(this)->SavePackage();
    unsigned short sizeVal = 0;   // Serialized block length.
    unsigned char* position = 0;  // Address of the block length field.
    unsigned char* aPosition = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (*::g_011de4e8.Bool())
        aPosition = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (reinterpret_cast<::FUN_00862110_cls *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int tag = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&tag, 4);
        position = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&sizeVal, 2);
    }
    unsigned short kCount = 0;  // Number of avoided references.
    unsigned char* _position = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    reinterpret_cast<::FUN_008579b0_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&kCount, 2);
    SavedReferenceList* node = &avoided;
    while (node && !node->FUN_008256d0())
    {
        SavedReference* reference = ((::SavedReference *)(((::Vec3 *)(void *)(node))));
        unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reference))->FUN_0084e3a0()));
        reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((int)(&formID), 4);
        ++kCount;
        node = ((::SavedReferenceList *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    *reinterpret_cast<unsigned short*>(_position) = kCount;
    unsigned int formB = 0;
    if (referenceB)
        formB = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((referenceB))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((int)(&formB), 4);
    unsigned int form = 0;
    if (referenceA)
        form = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((referenceA))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((int)(&form), 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&flag81, 1);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&flagA8, 1);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&flag94, 1);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&timer, 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&this->position, 12);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&flag80, 1);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&flagA9, 1);
    if (*::g_011de4e8.Bool())
    {
        unsigned char* end = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        SaveDebugRecord* reference = ((::SaveDebugRecord *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->GetHitSound()));
        if (reference)
        {
            TESForm* form = ::FUN_004839c0(reference->formID);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned char* end = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<SaveStream*>((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        unsigned char* data = position;
        if (end > data + 65535)
            ::FUN_005b5e40();
        *reinterpret_cast<unsigned short*>(position) = static_cast<unsigned short>(end - data);
    }
}

struct FleeLoadFormInfo
{
    unsigned int auiFormId;
    unsigned char m_ucTimeSettings[6];
};

struct FleeLoadManager
{
};



struct FleeLoadRef;

struct FleeLoadRefList
{
    void AddHead(FleeLoadRef* const& arRef);
};

struct FleeLoadPackage
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
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
    unsigned char ucFlag80;
    unsigned char ucFlag81;
    unsigned char ucPad82;
    unsigned char ucPad83;
    float fPos84[3];
    int iValue90;
    unsigned char ucFlag94;
    unsigned char ucPad95;
    unsigned char ucPad96;
    unsigned char ucPad97;
    FleeLoadRefList kAvoidedRefs;
    int unk9C;
    unsigned int uiTargetA0;
    unsigned int uiTargetA4;
    unsigned char ucFlagA8;
    unsigned char ucFlagA9;

    void FUN_009f1e80();
};

// Loads the package's avoided-ref list, targets, flags, value and position from the save buffer, validating the BLOK header and block size.
// @fnv 0x009f1e80
void FleeLoadPackage::FUN_009f1e80()
{
    unsigned short usCount4;
    unsigned int uiRefA7;
    unsigned int uiRefA9;
    unsigned int uiBlockStart7;
    unsigned short usBlockSize2;
    int i3;

    reinterpret_cast<::fnv_00679340::Package679 *>(this)->FUN_00679340();
    usBlockSize2 = 0;
    uiBlockStart7 = 0;

    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        int iMarker;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&iMarker, 4);
        if (iMarker != 'BLOK')
        {
            FleeLoadFormInfo* pInfo = ((::FleeLoadFormInfo *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))));
            if (pInfo)
            {
                TESForm* pForm = ::FUN_004839c0(pInfo->auiFormId);
                ::FUN_005b5e40();
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
        uiBlockStart7 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&usBlockSize2, 2);
    }

    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&usCount4, 2);
    for (i3 = 0; i3 < usCount4; i3++)
    {
        unsigned int auiFormId;
        reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&auiFormId, 4);
        unsigned int uiRef = auiFormId;
        kAvoidedRefs.AddHead((FleeLoadRef*)uiRef);
    }

    reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&uiRefA9, 4);
    uiTargetA4 = uiRefA9;
    reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&uiRefA7, 4);
    uiTargetA0 = uiRefA7;
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&ucFlag81, 1);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&ucFlagA8, 1);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&ucFlag94, 1);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&iValue90, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(fPos84, 0xc);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&ucFlag80, 1);
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x71)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&ucFlagA9, 1);

    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int uiBlockEndA = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        FleeLoadFormInfo* pEndInfo = ((::FleeLoadFormInfo *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::FleeLoadManager * *>(&::g_TESSaveLoadGame))))));
        if (pEndInfo)
        {
            TESForm* pEndForm = ::FUN_004839c0(pEndInfo->auiFormId);
            if (uiBlockEndA > usBlockSize2 + uiBlockStart7)
                ::FUN_005b5e40();
            else if (uiBlockEndA < usBlockSize2 + uiBlockStart7)
                ::FUN_005b5e40();
        }
        else
        {
            if (uiBlockEndA > usBlockSize2 + uiBlockStart7)
                ::FUN_005b5e40();
            else if (uiBlockEndA < usBlockSize2 + uiBlockStart7)
                ::FUN_005b5e40();
        }
    }
}


struct RefListNode
{
    TESObjectREFR* item;
    RefListNode* next;
    bool IsEmpty();
    void SetItem(TESObjectREFR* const& apItem);
    void RemoveHead();
};

struct FleePackageBase
{
};

struct FleePackageLG : public FleePackageBase
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
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
    RefListNode AvoidedRefList;
    TESObjectREFR* pRefA0;
    TESObjectREFR* pRefA4;

    void FUN_009f25f0(void* apBuffer);
};

// Calls the base InitLoadGame, re-resolves pRefA0/pRefA4 and the AvoidedRefList entries via _ref_004839c0, removing entries that no longer resolve.
// @fnv 0x009f25f0
void FleePackageLG::FUN_009f25f0(void* apBuffer)
{
    reinterpret_cast<::A90Cls *>(this)->DispatchToSubobjects((int)(apBuffer));
    pRefA0 = pRefA0 ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)pRefA0)) : 0;
    pRefA4 = pRefA4 ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)pRefA4)) : 0;

    RefListNode* pNode = &AvoidedRefList;
    RefListNode* pPrev = 0;
    while (pNode && !pNode->IsEmpty())
    {
        TESObjectREFR* pRef = *((::TESObjectREFR **)(((::Vec3 *)(void *)(pNode))));
        bool bRemove = false;
        if (pRef)
        {
            pRef = pRef ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)pRef)) : 0;
            if (pRef)
                pNode->SetItem(pRef);
            else
                bRemove = true;
        }
        else
        {
            bRemove = true;
        }
        if (bRemove)
        {
            if (pPrev)
            {
                reinterpret_cast<::ItemChangeListNode *>((pPrev))->FUN_00905330((::InventoryStackRecord *const &)(*((::TESObjectREFR **)(((::Vec3 *)(void *)(pNode))))));
                pNode = ((::RefListNode *)(reinterpret_cast<::Callees *>((pPrev))->FUN_00726070()));
            }
            else
            {
                pNode->RemoveHead();
            }
        }
        else
        {
            pPrev = pNode;
            pNode = ((::RefListNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
    }
}

#include "generated/data/fallout/ai/fleepackage.inc"
