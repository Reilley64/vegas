// fallout_shared/package.cpp: TESPackage, TESFormStub, Package, PHost and more (140 functions)

#include <cstdint>
#include <new>
#include <cmath>
#include <cstdio>
#include <malloc.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDehydrationStage.h"
#include "fnv/decl/BGSIdleCollection.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C680590Target.h"
#include "fnv/decl/C80720Target.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00418b70_shell.h"
#include "fnv/decl/FUN_0041c8d0_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00454b70.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004799f0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00568680_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_0056ad30_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0060ce80_Obj.h"
#include "fnv/decl/FUN_00671a70_Class.h"
#include "fnv/decl/FUN_00671ad0_Class.h"
#include "fnv/decl/FUN_00671b30_Class.h"
#include "fnv/decl/FUN_00671b90_Class.h"
#include "fnv/decl/FUN_00671bf0_Class.h"
#include "fnv/decl/FUN_00671c50_Class.h"
#include "fnv/decl/FUN_00671cb0_Class.h"
#include "fnv/decl/FUN_00672d10_Class.h"
#include "fnv/decl/FUN_0067ac70_Class.h"
#include "fnv/decl/FUN_0067ad20_Class.h"
#include "fnv/decl/FUN_0067b100_Class.h"
#include "fnv/decl/FUN_0067ca10_cls.h"
#include "fnv/decl/FUN_0067dad0_shell.h"
#include "fnv/decl/FUN_0067dbf0_shell.h"
#include "fnv/decl/FUN_0067dc80.h"
#include "fnv/decl/FUN_0067eff0_Class.h"
#include "fnv/decl/FUN_0067f110_shell.h"
#include "fnv/decl/FUN_0067f1c0_shell.h"
#include "fnv/decl/FUN_0067f220_cls.h"
#include "fnv/decl/FUN_0067f430_shell.h"
#include "fnv/decl/FUN_0067f480_shell.h"
#include "fnv/decl/FUN_0067f990_C.h"
#include "fnv/decl/FUN_0067fa00_shell.h"
#include "fnv/decl/FUN_0067fb60_shell.h"
#include "fnv/decl/FUN_0067fbe0_cls.h"
#include "fnv/decl/FUN_0067fc50_shell.h"
#include "fnv/decl/FUN_0067fec0_shell.h"
#include "fnv/decl/FUN_00680220_shell.h"
#include "fnv/decl/FUN_006802f0_shell.h"
#include "fnv/decl/FUN_00680520_cls.h"
#include "fnv/decl/FUN_00680830_shell.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_00680a70_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009727c0_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/PackageEventActionData.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_006807b0_Target.h"
#include "fnv/decl/SaveDataStub.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00405f30__EILStandIn.h"
#include "fnv/decl/fnv_00405fe0__EffectItemList.h"
#include "fnv/decl/fnv_00406090__EffectItemList.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004797c0__FUN_004797c0_shell.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0055d3b0__FUN_0055d3b0.h"
#include "fnv/decl/fnv_00568fa0__Fn568fa0.h"
#include "fnv/decl/fnv_0056ad80__Thing.h"
#include "fnv/decl/fnv_0056add0__Obj.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_006751a0__Pkg.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
#include "fnv/decl/fnv_0067faa0__OwnQ.h"
#include "fnv/decl/fnv_0067fd40__FUN_0067fd40_shell.h"
#include "fnv/decl/fnv_0067ff10__FUN_0067ff10_Class.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008be940__FloatValueProvider.h"
#include "fnv/decl/fnv_00962620__FUN_00962620_cls.h"
#include "fnv/decl/fnv_00970810__Menu75x.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/decl/s54cee0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00678000.h"
#include "fnv/symbols_0067a000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01068000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "package_decls.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_0067f140_shell.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00833c20_shell.h"
#include "fnv/decl/FUN_008a08c0_Class.h"
#include "fnv/decl/FUN_008bf4e0_cls.h"
#include "fnv/decl/FUN_009ec830_t.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/TESClass.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/ZOwner.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_00884350__FUN_00884350_shell.h"
#include "fnv/decl/fnv_009eb9c0__Crime.h"
#include "fnv/decl/fnv_009ec810__FUN_009ec810_t.h"
// @fnv 0x006e25d0
float TESPackage::GetPackageDefaultFloat()
{
    return gPackageLocationRadius;
}
// @fnv 0x00670f90
bool TESPackage::IsMustReachLocation()
{
    if (flags & 0x400)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00674dd0
bool TESPackage::UsesPackageAnimation()
{
    if (flags & 0x4000)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00674e40
bool TESPackage::IsFlag10000Set()
{
    if (flags & 0x8000)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Returns data as a TESPatrolPackageData pointer when GetPackType() equals 13, otherwise returns null.
// @fnv 0x00675920
const TESPatrolPackageData* TESPackage::GetPackagePatrolData()
{
    if (GetPackType() == 13)
        return data;
    return 0;
}
// Sets or clears bit 0 of flags according to value.
// @fnv 0x005bbd60
void ImageSpaceModifierInstanceDOF::FUN_005bbd60(bool value)
{
    if (value)
        flags |= 1;
    else
        flags &= ~1;
}
// Returns true when GetPackType() is one of the package types 18-25, 27-29 or 31-36, otherwise false.
// @fnv 0x00678610
bool TESPackage::IsPackageBlockingGreeting()
{
    bool result = false;
    switch (GetPackType())
    {
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
    case 29:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
        result = true;
        break;
    }
    return result;
}
// Copies the schedule from source into this package's schedule, or copies an empty schedule when source is null.
// @fnv 0x00673180
void TESPackage::CopyScheduleFrom(DurationData* source)
{
    if (source)
        reinterpret_cast<::fnv_0067fd40::FUN_0067fd40_shell *>(&(schedule))->FUN_0067fd40((::fnv_0067fd40::DurationData *)(source));
    else
    {
        DurationData empty;
        reinterpret_cast<::fnv_0067fd40::FUN_0067fd40_shell *>(&(schedule))->FUN_0067fd40((::fnv_0067fd40::DurationData *)(::DurationData *)(&empty));
    }
}
// @fnv 0x00673890
bool TESPackage::FUN_00673890()
{
    return f24 & 0x40;
}
// @fnv 0x00674d20
bool TESPackage::FUN_00674d20()
{
    return f24 & 0x2;
}
// @fnv 0x00670ed0
bool TESPackage::FUN_00670ed0()
{
    if (flags & 0x40)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00670ef0
bool TESPackage::IsFlag10Set()
{
    if (flags & 0x10)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00670f40
bool TESPackage::FUN_00670f40()
{
    if (flags & 0x20)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00670f10
bool TESPackage::IsFlag80Set()
{
    if (flags & 0x80)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00670f60
bool TESPackage::FUN_00670f60()
{
    if (flags & 0x100)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00674d40
bool TESPackage::IsMustComplete()
{
    if (flags & 0x800)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct FUN_00671a20_shell : public TESPackage
{
    void FUN_00671a20(bool);
};

// @fnv 0x00671a20
void FUN_00671a20_shell::FUN_00671a20(bool enabled)
{
    enabled ? this->flags |= 0x800000 : this->flags &= ~0x800000;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct LocationDescriptor;
struct TESForm;
struct TESPackageData;
struct TESTopic;
struct FUN_006727b0_shell : public TESPackage
{
    bool FUN_006727b0();
};

// Returns the bool at offset 0x11 of data when the package type is 0xf or 0x1c, otherwise false.
// @fnv 0x006727b0
bool FUN_006727b0_shell::FUN_006727b0()
{
    bool bControl = false;
    if (GetPackType() == 0xf || GetPackType() == 0x1c)
    {
        char* pdata = reinterpret_cast<char*>(data);
        if (pdata)
        {
            bControl = *reinterpret_cast<bool*>(pdata + 0x11);
        }
    }
    return bControl;
}

struct FUN_00672930_flags
{
};
struct FUN_00672930_cls
{
    PackageTargetRecord* GetTarget();
    int FUN_00672930();
};
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct LocationDescriptor;
struct TESForm;
struct TESPackageData;
struct TESTopic;
struct FUN_00672dd0_shell : public TESPackage
{
    LocationDescriptor* FUN_00672dd0();
};

// Returns a pointer stored inside the package data at an offset that depends on GetPackType(), or null when data is absent or the type is unhandled.
// @fnv 0x00672dd0
LocationDescriptor* FUN_00672dd0_shell::FUN_00672dd0()
{
    if (data && (GetPackType() == 0xF || GetPackType() == 0x1C))
    {
        struct Data0C
        {
            int pad[3];
            LocationDescriptor* loc;
        };
        Data0C* pdata = (Data0C*)data;
        return pdata->loc;
    }
    else if (data && GetPackType() == 3)
    {
        struct Data04
        {
            int pad;
            LocationDescriptor* loc;
        };
        Data04* pdata = (Data04*)data;
        return pdata->loc;
    }
    else if (data && GetPackType() == 2)
    {
        struct Data04
        {
            int pad;
            LocationDescriptor* loc;
        };
        Data04* pdata = (Data04*)data;
        return pdata->loc;
    }
    else if (data && GetPackType() == 9)
    {
        struct Data04
        {
            int pad;
            LocationDescriptor* loc;
        };
        Data04* pdata = (Data04*)data;
        return pdata->loc;
    }
    else if (data && GetPackType() == 8)
    {
        struct Data04
        {
            int pad;
            LocationDescriptor* loc;
        };
        Data04* pdata = (Data04*)data;
        return pdata->loc;
    }
    else if (data && GetPackType() == 1)
    {
        struct Data04
        {
            int pad;
            LocationDescriptor* loc;
        };
        Data04* pdata = (Data04*)data;
        return pdata->loc;
    }
    else if (data && GetPackType() == 0x10)
    {
        struct Data08
        {
            int pad[2];
            LocationDescriptor* loc;
        };
        Data08* pdata = (Data08*)data;
        return pdata->loc;
    }
    return 0;
}

struct BoundHolder
{
};
struct BGSMessageInitAccess
{
    BoundHolder* GetIconFormID();
};
struct RefArg
{
    TESObjectREFR* p;
};
// @fnv 0x006737a0
bool FUN_006737a0(TESPackage* self, RefArg aRefArg)
{
    switch (self->GetPackType())
    {
    case 6:
        return (reinterpret_cast<::DurationData *>((((BGSMessageInitAccess*)self)->GetIconFormID()))->FUN_00678ca0() == 6 && !reinterpret_cast<::FUN_00569b80_shell *>((aRefArg.p))->FUN_00569b80())
                   ? 0
                   : 1;
    case 13:
        return (reinterpret_cast<::DurationData *>((((BGSMessageInitAccess*)self)->GetIconFormID()))->FUN_00678ca0() == 6 && !reinterpret_cast<::FUN_00569b80_shell *>((aRefArg.p))->FUN_00569b80())
                   ? 0
                   : 1;
    case 12:
        return ((self->FUN_00673890() || (((BGSMessageInitAccess*)self)->GetIconFormID() &&
                                          reinterpret_cast<::DurationData *>((((BGSMessageInitAccess*)self)->GetIconFormID()))->FUN_00678ca0() == 6)) &&
                !reinterpret_cast<::FUN_00569b80_shell *>((aRefArg.p))->FUN_00569b80())
                   ? 0
                   : 1;
    }
    return true;
}

struct FUN_00674d70_shell : public TESPackage
{
    void SetFlag800(bool);
};
// @fnv 0x006709d0
void TESPackage::ResetFormData()
{
    flags = 0;
    f24 = 0;
    f22 = 0;
    pPackageLocation = 0;
    pPackageTarget = 0;
    f34 = 0;
    pCombatStyle = 0;
    data = 0;
    CopyScheduleFrom(0);
    flags18 = ~0u;
    type = 255;
    reinterpret_cast<::FUN_00674d70_shell *>(this)->SetFlag800(false);
}

class TESObjectCELL;
class TESObjectREFR;
struct NiPoint3;
struct TESDataHandler
{
public:
    void GetReferencesInArea(::TESObjectCELL *, const ::NiPoint3 &, float, const ::NiPoint3 &, float, bool (*)(TESObjectREFR *, long), long);
};

// @fnv 0x00674d70
void FUN_00674d70_shell::SetFlag800(bool abVal)
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()))))
    {
        if (abVal)
            this->flags |= 0x800;
        else
            this->flags &= ~0x800;
    }
}

struct FUN_00674e00_cls
{
    char pad[0x1c];
    unsigned int flags;
    void SetFlag4000(bool set);
};
// Sets or clears bit 0x4000 in the flags field depending on set.
// @fnv 0x00674e00
void FUN_00674e00_cls::SetFlag4000(bool set)
{
    if (set)
        flags |= 0x4000;
    else
        flags &= ~0x4000;
}

struct ActiveEffect;
struct Actor;
struct AlchemyItem;
struct EffectItem;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NiNode;
struct SpellItem;
struct TESBoundObject;
struct TESForm;
struct TESObjectCELL;
struct hkpRigidBody;
struct blob12
{
    char b[12];
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
struct FUN_00677760_shell : public TESPackage
{
    bool FUN_00677760(Actor*);
};

struct Sky;
struct TES
{
};

struct VTable0x11c
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual bool v71();
};

// Returns true when apActor is non-null and its log date object's v71 virtual call returns true; otherwise false.
// @fnv 0x00677760
bool FUN_00677760_shell::FUN_00677760(Actor* apActor)
{
    bool bHasResultObj = false;
    if (apActor && ((::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<TES*>(apActor)))->GetBaseTexture())))
    {
        bHasResultObj = reinterpret_cast<VTable0x11c*>(((::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<TES*>(apActor)))->GetBaseTexture())))->v71();
    }
    return bHasResultObj;
}

namespace fnv_00678670 {
struct ActiveEffect;
struct Actor;
struct AlchemyItem;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct EffectItem;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NiNode;
struct SpellItem;
struct TESBoundObject;
struct TESForm;
struct TESObjectCELL;
struct hkpRigidBody;
struct blob12
{
    char b[12];
};
struct LocationDescriptor
{
    int GetLocType();
    void SetLocationType(int);
    void SetRadius(unsigned int);
    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
    TESForm* GetLocationObject();
    int GetSearchRadius();
    void SetLocRef(TESObjectREFR*);
    void SetLocCell(TESObjectCELL*);
    void SetLocObject(TESForm*);
    void SetLocObjectType(int);
    void Copy(LocationDescriptor*, bool);
    bool Compare(LocationDescriptor*);
    void Save(int);
    void InitItem(TESForm*);
    bool IsLocationGeneric();
    bool GetIsValidLocation(TESForm*);
    bool IsRadiusNonZero();
    TESObjectREFR* ResolveLocationReference(MobileObject*);
    bool IsRefAtLocationTrigger(MobileObject*, TESObjectREFR*, bool*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    unsigned int GetRadius();
    void* __vecDelDtor(unsigned int);
    char m_ucLocationType;
    char _pad_1[3];
    unsigned int m_pLocationData;
    int eObjType;
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
struct FUN_00678670_shell : public TESPackage
{
    float FUN_00678670(MobileObject*, bool);
};

struct TESObjectSTAT;
struct GlobalObject2_0040c150
{
};
struct BGSMessageInitAccess
{
    unsigned int GetIconFormID();
};


struct TESPackage_ext
{
    LocationDescriptor* GetPackageSecondLocation();
};

struct TESObjectREFR_v
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool IsActor_v100();
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
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual int GetSitSleepState_v214();
};


// @fnv 0x00678670
float FUN_00678670_shell::FUN_00678670(MobileObject* apMobileObject, bool abSecondLoc)
{
    LocationDescriptor* ploc = abSecondLoc ? ((::fnv_00678670::LocationDescriptor *)(reinterpret_cast<::FUN_00672dd0_shell *>((this))->FUN_00672dd0()))
                                           : (LocationDescriptor*)(std::uintptr_t)((BGSMessageInitAccess*)this)->GetIconFormID();
    int m_iSearchRadius = 0;
    if (ploc)
    {
        m_iSearchRadius = reinterpret_cast<::FUN_0067f1c0_shell *>((ploc))->FUN_0067f1c0();
        m_iSearchRadius = reinterpret_cast<::FUN_0067f1c0_shell *>((ploc))->FUN_0067f1c0();
        if (m_iSearchRadius == 0 && ploc)
        {
            TESObjectREFR* pRef = ploc->ResolveLocationReference(apMobileObject);
            if (pRef)
            {
                if (reinterpret_cast<::FUN_00568680_shell *>((pRef))->FUN_00568680())
                {
                    m_iSearchRadius = 10;
                }
                else if (((TESObjectREFR_v*)pRef)->IsActor_v100())
                {
                    TESObjectREFR_v* pact = (TESObjectREFR_v*)pRef;
                    if (pact->GetSitSleepState_v214() == 9)
                    {
                        m_iSearchRadius = 90;
                    }
                    else
                    {
                        m_iSearchRadius = (int)reinterpret_cast<::TESObjectREFR *>((pRef))->GetBoundingRadius() + 20;
                    }
                }
                else if (((::fnv_00678670::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) == (*reinterpret_cast<::fnv_00678670::TESObjectSTAT * *>(&::DAT_011ca248)) || ((::fnv_00678670::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) == (*reinterpret_cast<::fnv_00678670::TESObjectSTAT * *>(&::DAT_011ca244)))
                {
                    m_iSearchRadius = 20;
                }
                else
                {
                    m_iSearchRadius = (int)reinterpret_cast<::TESObjectREFR *>((pRef))->GetBoundingRadius() + 20;
                }
                if (m_iSearchRadius < 0)
                {
                    m_iSearchRadius = 0;
                }
            }
            else if (reinterpret_cast<::DurationData *>((ploc))->FUN_00678ca0() == 3)
            {
                m_iSearchRadius = 10;
            }
        }
        if (m_iSearchRadius == 0)
        {
            m_iSearchRadius = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00678670::GlobalObject2_0040c150 *>(&::g_011cde98))))));
        }
    }
    return (float)m_iSearchRadius;
}
}  // namespace fnv_00678670

struct FUN_00678cc0_shell : public DurationData
{
    int GetSecondByte();
};

// @fnv 0x00678cc0
int FUN_00678cc0_shell::GetSecondByte()
{
    return cDayOfWeek;
}

struct FUN_00678ce0_shell : public DurationData
{
    char FUN_00678ce0();
};

// @fnv 0x00678ce0
char FUN_00678ce0_shell::FUN_00678ce0()
{
    return cDate;
}

struct FUN_00678d00_shell : public TESPackage
{
    bool FUN_00678d00();
};

class Calendar
{
  public:
};

// Returns true when GetDaysPassed() is 2-5 or 26, false otherwise.
// @fnv 0x00678d00
bool FUN_00678d00_shell::FUN_00678d00()
{
    switch ((int)((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<Calendar*>(this)))->FUN_009611e0())))
    {
    case 2:
    case 3:
    case 4:
    case 5:
    case 26:
        return true;
    default:
        return false;
    }
}

namespace fnv_00678d40 {
struct FUN_00678d40_shell : public TESPackage
{
    bool IsPackageScheduledForDay(bool);
};

class EnchantmentItem;
template <class T> class BSSimpleList;

class TESDataHandler
{
  public:
};

class Calendar
{
  public:
    int GetGameDayOfWeek();
};


struct PackageSchedule_Caller : public DurationData
{
};

// @fnv 0x00678d40
bool FUN_00678d40_shell::IsPackageScheduledForDay(bool bTestPreviousDay)
{
    DurationData* pSchedule = (DurationData*)((::fnv_00678d40::BSSimpleList< ::fnv_00678d40::EnchantmentItem *> *)(reinterpret_cast<::FUN_0041d8a0_shell *>((((TESDataHandler*)this)))->FUN_0041d8a0()));
    char cDayToCheck = (*reinterpret_cast<::fnv_00678d40::Calendar *>(&::g_011de7b8)).GetGameDayOfWeek();
    if (bTestPreviousDay)
    {
        cDayToCheck -= 1;
        if (cDayToCheck < 0)
            cDayToCheck = 6;
    }
    int ecurrentday = reinterpret_cast<::FUN_00678cc0_shell *>((((PackageSchedule_Caller*)pSchedule)))->GetSecondByte();
    bool abflag = false;
    switch (ecurrentday)
    {
    case 0:
        if (cDayToCheck == 0)
            abflag = true;
        break;
    case 1:
        if (cDayToCheck == 1)
            abflag = true;
        break;
    case 2:
        if (cDayToCheck == 2)
            abflag = true;
        break;
    case 3:
        if (cDayToCheck == 3)
            abflag = true;
        break;
    case 4:
        if (cDayToCheck == 4)
            abflag = true;
        break;
    case 5:
        if (cDayToCheck == 5)
            abflag = true;
        break;
    case 6:
        if (cDayToCheck == 6)
            abflag = true;
        break;
    case 7:
        abflag = true;
        if (cDayToCheck == 0 || cDayToCheck == 6)
            abflag = false;
        break;
    case 8:
        if (cDayToCheck == 0 || cDayToCheck == 6)
            abflag = true;
        break;
    case 9:
        if (cDayToCheck == 1 || cDayToCheck == 3 || cDayToCheck == 5)
            abflag = true;
        break;
    case 10:
        if (cDayToCheck == 2 || cDayToCheck == 4)
            abflag = true;
        break;
    }
    return abflag;
}
}  // namespace fnv_00678d40

struct FUN_00678ec0_shell : public TESPackage
{
    bool FUN_00678ec0(MobileObject*);
};

class TESForm;
enum PACKAGE_OBJECT_TYPE
{
    POT_DUMMY
};

unsigned char _FNV_GetFormType(TESForm*);

struct PackageTarget_ext
{
};

struct TESObjectREFR_vtbl
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
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
};

class TESObjectWEAP
{
  public:
};

int _FNV_GetFormType(void*);

struct DummyForm3C
{
    struct Sub3C
    {
        virtual void v0();
        virtual bool v1();
    };
    char pad[0x3c];
    Sub3C sub;
};

// @fnv 0x00679ba0
int __cdecl FUN_00679ba0(void* pForm)
{
    int res = 0;
    if (pForm)
    {
        switch (_FNV_GetFormType(pForm))
        {
        case 0x15:
            res = 1;
            break;
        case 0x19:
            res = 3;
            break;
        case 0x1b:
            res = 5;
            break;
        case 0x1c:
            res = 6;
            break;
        case 0x1e:
            res = 8;
            break;
        case 0x1f:
        case 0x32:
        case 0x67:
            res = 9;
            break;
        case 0x26:
            res = 0xa;
            break;
        case 0x27:
            res = 0xb;
            break;
        case 0x2a:
            res = 0xe;
            break;
        case 0x2b:
            res = 0xf;
            break;
        case 0x2e:
            res = 0x10;
            break;
        case 0x2f: {
            DummyForm3C* pAlchemyForm = (DummyForm3C*)pForm;
            if (pAlchemyForm->sub.v1())
                res = 0x12;
            else
                res = 0x11;
            break;
        }
        case 0x1d: {
            DummyForm3C* pIngredientForm = (DummyForm3C*)pForm;
            if (pIngredientForm->sub.v1())
                res = 0x12;
            else
                res = 7;
            break;
        }
        case 0x1a:
            res = 4;
            break;
        case 0x18:
            res = 2;
            break;
        case 0x28: {
            res = 0xc;
            TESObjectWEAP* pWeapon = (TESObjectWEAP*)pForm;
            if (pWeapon)
            {
                if (FUN_006450c0(pWeapon))
                    res = 0x16;
                else if (::FUN_004c0c30((char *)(pWeapon)))
                    res = 0x17;
            }
            break;
        }
        case 0x29:
            res = 0xd;
            break;
        case 0x6c:
        case 0x73:
        case 0x74:
            res = 9;
            break;
        case 0x14:
            res = 0x18;
            break;
        }
    }
    return res;
}

struct FUN_0067a380_shell : public TESPackage
{
    bool FUN_0067a380();
};

// @fnv 0x0067a380
bool FUN_0067a380_shell::FUN_0067a380()
{
    return (this->flags & 0x1000) ? true : false;
}

struct FUN_0067a3a0_shell : public TESPackage
{
    void FUN_0067a3a0(bool);
};

// Sets or clears bit 0x1000 in the flags field at offset 0x1c according to enabled.
// @fnv 0x0067a3a0
void FUN_0067a3a0_shell::FUN_0067a3a0(bool enabled)
{
    enabled ? this->flags |= 0x1000 : this->flags &= ~0x1000;
}

struct FUN_0067a3f0_shell : public TESPackage
{
    bool HasFlag400000();
};

// @fnv 0x0067a3f0
bool FUN_0067a3f0_shell::HasFlag400000()
{
    return (this->flags & 0x400000) ? true : false;
}

struct FUN_0067a460_shell : public TESPackage
{
    bool FUN_0067a460();
};

// @fnv 0x0067a460
bool FUN_0067a460_shell::FUN_0067a460()
{
    return (this->flags & 0x800000) ? true : false;
}

struct FUN_0067a480_shell : public TESPackage
{
    bool FUN_0067a480();
};

// @fnv 0x0067a480
bool FUN_0067a480_shell::FUN_0067a480()
{
    return (this->flags & 0x2000) ? true : false;
}

struct FUN_0067a4f0_shell : public TESPackage
{
    bool FUN_0067a4f0();
};

// @fnv 0x0067a4f0
bool FUN_0067a4f0_shell::FUN_0067a4f0()
{
    return (this->flags & 0x20000) ? true : false;
}

struct FUN_0067a690_shell : public TESPackage
{
    bool HasFlag100000();
};

// @fnv 0x0067a690
bool FUN_0067a690_shell::HasFlag100000()
{
    return (this->flags & 0x100000) ? true : false;
}

struct FUN_0067a700_shell : public TESPackage
{
    bool FUN_0067a700();
};

// @fnv 0x0067a700
bool FUN_0067a700_shell::FUN_0067a700()
{
    return (this->flags & 0x4000000) ? true : false;
}

struct FUN_0067a720_shell : public TESPackage
{
    void SetFlag4000000(bool);
};

// @fnv 0x0067a720
void FUN_0067a720_shell::SetFlag4000000(bool abVal)
{
    abVal ? this->flags |= 0x4000000
          : this->flags &= ~0x4000000;
}

struct FUN_0067a770_shell : public TESPackage
{
    bool IsNotFlag8000000();
};

// @fnv 0x0067a770
bool FUN_0067a770_shell::IsNotFlag8000000()
{
    return (this->flags & 0x8000000) ? false : true;
}

struct FUN_0067a850_shell : public TESPackage
{
    bool FUN_0067a850();
};

// @fnv 0x0067a850
bool FUN_0067a850_shell::FUN_0067a850()
{
    return (this->f22 & 1) ? true : false;
}

struct FUN_0067a8d0_shell : public TESPackage
{
    bool FUN_0067a8d0();
};

// @fnv 0x0067a8d0
bool FUN_0067a8d0_shell::FUN_0067a8d0()
{
    return (this->f22 & 2) ? true : false;
}

struct FUN_0067a950_shell : public TESPackage
{
    bool FUN_0067a950();
};

// @fnv 0x0067a950
bool FUN_0067a950_shell::FUN_0067a950()
{
    return (this->f22 & 4) ? true : false;
}

struct FUN_0067aa50_shell : public TESPackage
{
    bool FUN_0067aa50();
};

// @fnv 0x0067aa50
bool FUN_0067aa50_shell::FUN_0067aa50()
{
    return (this->f22 & 0x10) ? true : false;
}

struct FUN_0067aad0_shell : public TESPackage
{
    bool FUN_0067aad0();
};

// @fnv 0x0067aad0
bool FUN_0067aad0_shell::FUN_0067aad0()
{
    return (this->f22 & 0x20) ? true : false;
}

struct FUN_0067ab50_shell : public TESPackage
{
    bool HasFlag40();
};

// @fnv 0x0067ab50
bool FUN_0067ab50_shell::HasFlag40()
{
    return (this->f22 & 0x40) ? true : false;
}

// @fnv 0x0067abd0
unsigned char IsPackageFlag80Set(TESPackage* pThis)
{
    return (pThis->f22 & 0x80) != 0;
}

struct FUN_0067ac50_shell : public TESPackage
{
    bool FUN_0067ac50();
};

// @fnv 0x0067ac50
bool FUN_0067ac50_shell::FUN_0067ac50()
{
    return (this->f22 & 0x100) ? true : false;
}

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct Crime;
struct TESForm;
struct FUN_00670a50_shell : public TESPackage
{
    void DestroyPackage();
};

struct Date
{
    ~Date();
};
class TESFile;
struct PerkEntryConditionSet
{
    void InitializeConditionItems();
    void InitItem(::TESForm *);
public:
    void Load(::TESFile *);
public:
    bool Compare(::PerkEntryConditionSet *);
};
struct PackedByteIntRecord
{
    void* Endian();
};
struct FUN_00670b30
{
    ~FUN_00670b30();
};
struct FUN_00670b60
{
    ~FUN_00670b60();
};
struct FUN_00670a50_VObj
{
    virtual ~FUN_00670a50_VObj();
};
struct FUN_00670a50_View
{
    char pad[0x28];
    FUN_00670a50_VObj* p28;
    FUN_00670b30* p2c;
    Date* p30;
    FUN_00670b60* p34;
};
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_00670b30(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x00670b30
void* DelStandIn::FUN_00670b30(unsigned int flags)
{
    reinterpret_cast<::FUN_0067f110_shell *>((((DtorStandIn*)this)))->FUN_0067f110();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct FUN_00672fc0_shell : public TESPackage
{
    void FUN_00672fc0(PackageTargetRecord*);
};

struct FUN_006801a0_shell
{
    void FUN_006801a0(PackageTargetRecord*);
};
struct PackageTargetObj
{
    unsigned char data[0x10];
    PackageTargetObj();
    ~PackageTargetObj();
};

// @fnv 0x00672fc0
void FUN_00672fc0_shell::FUN_00672fc0(PackageTargetRecord* apPackTarg)
{
    PackageTargetObj*& rpTarget = reinterpret_cast<PackageTargetObj*&>(pPackageTarget);
    if (apPackTarg)
    {
        if (!rpTarget)
            rpTarget = new PackageTargetObj;
        ((FUN_006801a0_shell*)rpTarget)->FUN_006801a0(apPackTarg);
    }
    else
    {
        delete rpTarget;
        rpTarget = 0;
    }
}

namespace fnv_006768d0 {
struct ActiveEffect;
struct Actor;
struct AlchemyItem;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct Crime;
struct CellRecord;
struct ExteriorData;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct hkpRigidBody;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_006768d0_shell : public TESPackage
{
    bool CheckPackageLocation(MobileObject*, MobileObject*, bool, float, bool);
};

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
};
struct VT
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual bool IsActor();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual NiPoint3* f1f4();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual int f214();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual bool f290();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual bool f2cc(NiPoint3*, float, bool, bool);
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p200();
    virtual void p201();
    virtual void p202();
    virtual void p203();
    virtual void p204();
    virtual void p205();
    virtual void p206();
    virtual void p207();
    virtual void p208();
    virtual void p209();
    virtual void p210();
    virtual void p211();
    virtual void p212();
    virtual void p213();
    virtual void p214();
    virtual void p215();
    virtual void p216();
    virtual void p217();
    virtual void p218();
    virtual void p219();
    virtual void p220();
    virtual void p221();
    virtual void p222();
    virtual void p223();
    virtual void p224();
    virtual void p225();
    virtual void p226();
    virtual void p227();
    virtual void p228();
    virtual void p229();
    virtual void p230();
    virtual void p231();
    virtual void p232();
    virtual void p233();
    virtual void p234();
    virtual void p235();
    virtual void p236();
    virtual void p237();
    virtual void p238();
    virtual void p239();
    virtual void p240();
    virtual void p241();
    virtual void p242();
    virtual void p243();
    virtual void p244();
    virtual void p245();
    virtual void p246();
    virtual void p247();
    virtual void p248();
    virtual void p249();
    virtual void p250();
    virtual void p251();
    virtual void p252();
    virtual void p253();
    virtual void p254();
    virtual void p255();
    virtual void p256();
    virtual void p257();
    virtual void p258();
    virtual void p259();
    virtual void p260();
    virtual void p261();
    virtual void p262();
    virtual void p263();
    virtual void p264();
    virtual void p265();
    virtual void p266();
    virtual void p267();
    virtual void p268();
    virtual void p269();
    virtual void p270();
    virtual void p271();
    virtual void p272();
    virtual void p273();
    virtual void p274();
    virtual void p275();
    virtual void p276();
    virtual void p277();
    virtual void p278();
    virtual void p279();
    virtual void p280();
    virtual void p281();
    virtual void p282();
    virtual void p283();
    virtual void p284();
    virtual void p285();
    virtual void p286();
    virtual void p287();
    virtual void p288();
    virtual void p289();
    virtual void p290();
    virtual void p291();
    virtual void p292();
    virtual void p293();
    virtual void p294();
    virtual void p295();
    virtual void p296();
    virtual void p297();
    virtual void p298();
    virtual void p299();
    virtual void p300();
    virtual void p301();
    virtual void p302();
    virtual void p303();
    virtual void p304();
    virtual void p305();
    virtual void p306();
    virtual void p307();
    virtual void p308();
    virtual NiPoint3* f4d4();
};

struct LocationDescriptor
{
};
struct TESObjectSTAT;
struct BoundHolder
{
};
struct TES
{
};
class GlobalObject2_0040c150
{
  public:
};
int _FNV_GetFormType(TESForm*);
struct TESObjectCELL
{
    bool IsInterior();
};
struct Proc_S
{
};
struct Script
{
    char* GetText();
};
struct RefH
{
};
struct PathingPoint
{
};
struct TESObjectREFR_H
{
    TESObjectCELL* GetTarget();
};
struct Frame
{
    Actor* apActor;
    int m_iSearchRadius;
    char pad0_0;
    char pad0_1;
    bool bsamespace;
    bool bGoodPt;
    TESObjectREFR* pRef;
    TESObjectCELL* pactorintcell;
    char pad1_0;
    char pad1_1;
    char pad1_2;
    bool btriggered;
    TESObjectCELL* plocintcell;
    char pad2_0;
    char pad2_1;
    char pad2_2;
    bool bexactpos;
    TESWorldSpace* plocworld;
    LocationDescriptor* pLoc;
    NiPoint3 loccoord;
    TESWorldSpace* pactorworld;
    char pad3_0;
    char pad3_1;
    char pad3_2;
    bool boverride;
};
struct TESPackageX : public TESPackage
{
    bool CheckPackageLocation(MobileObject* apMobileObject, bool bignoredistance, float afOtherRadius,
                              bool bInfurniture);
    TESWorldSpace* GetPackageWorldSpace(MobileObject*);
    TESObjectCELL* GetPackageLocationCell(MobileObject*);
    void* GetPackageLocationPosition(NiPoint3*, MobileObject*);
    TESObjectREFR* FUN_00676140(MobileObject*);
};
// @fnv 0x006768d0
bool TESPackageX::CheckPackageLocation(MobileObject* apMobileObject, bool bignoredistance, float afOtherRadius,
                                       bool bInfurniture)
{
    Frame frame;

    if (!apMobileObject)
        return false;
    frame.apActor = 0;
    if (((VT*)apMobileObject)->IsActor())
        frame.apActor = (Actor*)apMobileObject;
    if (!bInfurniture && frame.apActor)
    {
        if (((VT*)frame.apActor)->f214() == 4 || ((VT*)frame.apActor)->f214() == 9)
            bInfurniture = true;
    }
    frame.pLoc = (LocationDescriptor*)((Script*)this)->GetText();
    if (frame.pLoc && reinterpret_cast<::DurationData *>((((BoundHolder*)frame.pLoc)))->FUN_00678ca0() == 3 && !((VT*)apMobileObject)->f290())
        return true;
    frame.plocworld = GetPackageWorldSpace(apMobileObject);
    frame.plocintcell = GetPackageLocationCell(apMobileObject);
    if (frame.plocintcell && !frame.plocintcell->IsInterior())
        frame.plocintcell = 0;
    frame.pactorworld = ((::fnv_006768d0::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((TESObjectREFR_H*)apMobileObject)))->FUN_00575d70()));
    frame.pactorintcell = ((::fnv_006768d0::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((((TESObjectREFR_H*)apMobileObject)))->GetTarget()));
    if (frame.pactorintcell && !frame.pactorintcell->IsInterior())
        frame.pactorintcell = 0;
    frame.bsamespace = false;
    if (frame.pactorintcell || frame.plocintcell)
    {
        if (frame.pactorintcell == frame.plocintcell)
        {
            frame.bsamespace = true;
            if (frame.pLoc && reinterpret_cast<::DurationData *>((((BoundHolder*)frame.pLoc)))->FUN_00678ca0() == 1)
                return true;
        }
    }
    else if (frame.pactorworld == frame.plocworld)
    {
        frame.bsamespace = true;
    }
    if (!frame.bsamespace)
        return false;
    frame.btriggered = false;
    if (frame.pLoc && (double)reinterpret_cast<::FUN_0067f1c0_shell *>((frame.pLoc))->FUN_0067f1c0() == ::_DAT_01012060)
    {
        if (reinterpret_cast<::FUN_0067f220_cls *>((frame.pLoc))->LookupAndStore((std::intptr_t)(apMobileObject), (std::intptr_t)(apMobileObject), (unsigned char *)(bool *)(&frame.btriggered)))
            return frame.btriggered;
    }
    frame.m_iSearchRadius = reinterpret_cast<::HighProcess *>((this))->UpdateHighProcessState((::Actor *)(apMobileObject));
    if (bignoredistance)
    {
        frame.m_iSearchRadius = 0;
    }
    else if (afOtherRadius != -1.0)
    {
        frame.m_iSearchRadius += (int)afOtherRadius;
    }
    if (frame.m_iSearchRadius > 0)
        bInfurniture = false;
    frame.boverride = false;
    GetPackageLocationPosition(&frame.loccoord, (MobileObject*)frame.apActor);
    frame.pRef = 0;
    if (frame.pLoc)
        frame.pRef = FUN_00676140(apMobileObject);
    if (frame.m_iSearchRadius == 0 && frame.pLoc)
    {
        if (frame.pRef)
        {
            TESObjectSTAT* pBase;
            pBase = 0;
            if (reinterpret_cast<::FUN_00568680_shell *>((((RefH*)frame.pRef)))->FUN_00568680())
                pBase = ((::fnv_006768d0::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((frame.pRef))->FUN_007af430()));
            if (pBase && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apMobileObject)))->GetBaseTexture())) && ((VT*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apMobileObject)))->GetBaseTexture())))->f4d4())
            {
                if (!((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apMobileObject)))->GetBaseTexture())))))->FUN_0045cd60())))
                    frame.loccoord = *((VT*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apMobileObject)))->GetBaseTexture())))->f4d4();
                frame.m_iSearchRadius = 20;
                frame.boverride = true;
            }
            else if (((::fnv_006768d0::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((frame.pRef))->FUN_007af430())) == (*reinterpret_cast<::fnv_006768d0::TESObjectSTAT * *>(&::DAT_011ca248)) ||
                     ((::fnv_006768d0::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((frame.pRef))->FUN_007af430())) == (*reinterpret_cast<::fnv_006768d0::TESObjectSTAT * *>(&::DAT_011ca244)))
            {
                frame.m_iSearchRadius = 20;
                frame.boverride = true;
            }
            else if (((VT*)frame.pRef)->IsActor())
            {
                Actor* pact;
                pact = (Actor*)frame.pRef;
                if (((VT*)pact)->f214() == 9)
                {
                    frame.m_iSearchRadius = 90;
                    frame.boverride = true;
                }
                else
                {
                    frame.m_iSearchRadius = (int)reinterpret_cast<::TESObjectREFR *>((((TESObjectREFR_H*)frame.pRef)))->GetBoundingRadius() + 20;
                }
            }
            else
            {
                float ffudge;
                ffudge = 20.0f;
                switch (_FNV_GetFormType((TESForm*)((::fnv_006768d0::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((frame.pRef))->FUN_007af430()))))
                {
                case 0x15:
                case 0x1b:
                case 0x20:
                case 0x21:
                    ffudge = 0.0f;
                    break;
                }
                frame.m_iSearchRadius = (int)reinterpret_cast<::TESObjectREFR *>((((TESObjectREFR_H*)frame.pRef)))->GetBoundingRadius() + (int)ffudge;
                if (frame.m_iSearchRadius < 0)
                    frame.m_iSearchRadius = 0;
            }
        }
        else if (reinterpret_cast<::DurationData *>((((BoundHolder*)frame.pLoc)))->FUN_00678ca0() == 3)
        {
            frame.boverride = true;
            frame.m_iSearchRadius = 10;
        }
    }
    if (reinterpret_cast<::HighProcess *>((this))->UpdateHighProcessState((::Actor *)(apMobileObject)) <= 0x14 && frame.pRef)
    {
        if (((::fnv_006768d0::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((frame.pRef))->FUN_007af430())) == (*reinterpret_cast<::fnv_006768d0::TESObjectSTAT * *>(&::DAT_011ca248)) || ((::fnv_006768d0::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((frame.pRef))->FUN_007af430())) == (*reinterpret_cast<::fnv_006768d0::TESObjectSTAT * *>(&::DAT_011ca244)))
            frame.boverride = true;
    }
    if (frame.m_iSearchRadius == 0)
        frame.m_iSearchRadius = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_006768d0::GlobalObject2_0040c150 *>(&::g_011cde98))))));
    frame.bexactpos = false;
    frame.bGoodPt = false;
    if (bInfurniture && frame.pRef && reinterpret_cast<::FUN_00568680_shell *>((((RefH*)frame.pRef)))->FUN_00568680() && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apMobileObject)))->GetBaseTexture())) &&
        ((VT*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apMobileObject)))->GetBaseTexture())))->f4d4())
    {
        NiPoint3 dist = frame.loccoord - *((VT*)frame.apActor)->f1f4();
        if ((reinterpret_cast<::FUN_00589850_Class *>((((PathingPoint*)&dist)))->FUN_00589850() < ::g_d100 && ((VT*)apMobileObject)->f214() == 4) ||
            ((VT*)apMobileObject)->f214() == 9)
            frame.bexactpos = true;
    }
    else
    {
        if (((VT*)apMobileObject)->f2cc(&frame.loccoord, (float)frame.m_iSearchRadius, !frame.boverride, true) &&
            !frame.bGoodPt)
            frame.bexactpos = true;
    }
    return frame.bexactpos;
}
}  // namespace fnv_006768d0

namespace fnv_006777b0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESForm;
struct TESObjectCELL;
struct LocationDescriptor
{
    int GetLocType();
    void SetLocationType(int);
    void SetRadius(unsigned int);
    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
    TESForm* GetLocationObject();
    int GetSearchRadius();
    void SetLocRef(TESObjectREFR*);
    void SetLocCell(TESObjectCELL*);
    void SetLocObject(TESForm*);
    void SetLocObjectType(int);
    void Copy(LocationDescriptor*, bool);
    bool Compare(LocationDescriptor*);
    void Save(int);
    void InitItem(TESForm*);
    bool IsLocationGeneric();
    bool GetIsValidLocation(TESForm*);
    bool IsRadiusNonZero();
    TESObjectREFR* ResolveLocationReference(MobileObject*);
    bool IsRefAtLocationTrigger(MobileObject*, TESObjectREFR*, bool*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    unsigned int GetRadius();
    void* __vecDelDtor(unsigned int);
    char m_ucLocationType;
    char _pad_1[3];
    unsigned int m_pLocationData;
    int eObjType;
};
struct FUN_006777b0_shell : public TESPackage
{
    void ComputePackageFlags(TESObjectREFR*);
};

int _FNV_GetFormType(TESForm*);
struct BoundHolder
{
};
struct BGSTerrainManager
{
};
struct PackageLocationEx
{
};
struct TESPackageEx
{
    LocationDescriptor* GetPackageSecondLocation();
    void SetPackageType(int);
};
struct PackageTargetEx
{
    int GetTargetObjectType();
};
struct TESPackageVt
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetEditorID();
};

// @fnv 0x006777b0
void FUN_006777b0_shell::ComputePackageFlags(TESObjectREFR* apLinkedRef)
{
    switch (GetPackType())
    {
    case 5:
        flags18 = 1;
        break;
    case 6:
        flags18 = 0;
        break;
    case 0:
        if (!GetTarget())
        {
            if (pPackageLocation && reinterpret_cast<::FUN_00454b70 *>(pPackageLocation)->GetHasLOD())
                flags18 = 1;
            else
                flags18 = 0;
        }
        else
        {
            bool bHasResultObj = false;
            if (GetTarget() && (GetTarget()->GetReferenceTarget() || ((::fnv_006777b0::TESForm *)(reinterpret_cast<::PackageTargetRecord *>((((PackageTargetEx*)GetTarget())))->GetTargetForm())) ||
                                ((PackageTargetEx*)GetTarget())->GetTargetObjectType()))
            {
                int etype = GetTarget()->GetTargetKind();
                switch (etype)
                {
                case 0:
                    switch (_FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((GetTarget()->GetReferenceTarget()))->FUN_007af430()))))
                    {
                    case 0x2a:
                        flags18 = 0x16;
                        return;
                        break;
                    case 0x15:
                    case 0x1b:
                    case 0x1c:
                    case 0x20:
                    case 0x21:
                    case 0x25:
                    case 0x26:
                    case 0x27:
                    case 0x2b:
                        bHasResultObj = true;
                    }
                    break;
                case 3:
                    if (apLinkedRef)
                    {
                        switch (_FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apLinkedRef))->FUN_007af430()))))
                        {
                        case 0x2a:
                            flags18 = 0x16;
                            return;
                            break;
                        case 0x15:
                        case 0x1b:
                        case 0x1c:
                        case 0x20:
                        case 0x21:
                        case 0x25:
                        case 0x26:
                        case 0x27:
                        case 0x2b:
                            bHasResultObj = true;
                        }
                    }
                    break;
                case 1:
                    switch (_FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::PackageTargetRecord *>((((PackageTargetEx*)GetTarget())))->GetTargetForm()))))
                    {
                    case 0x2a:
                        flags18 = 0x16;
                        return;
                        break;
                    case 0x15:
                    case 0x1c:
                    case 0x20:
                    case 0x21:
                    case 0x25:
                    case 0x26:
                    case 0x27:
                    case 0x2b:
                        bHasResultObj = true;
                        break;
                    default:
                        flags18 = 0x1a;
                        return;
                    }
                    break;
                case 2:
                    switch (((PackageTargetEx*)GetTarget())->GetTargetObjectType())
                    {
                    case 0xe:
                        flags18 = 0x16;
                        return;
                        break;
                    case 1:
                    case 6:
                    case 10:
                    case 11:
                    case 0xf:
                        bHasResultObj = true;
                        break;
                    default:
                        flags18 = 0x1a;
                        return;
                    }
                }
                if (bHasResultObj)
                    flags18 = 2;
                else
                    flags18 = 3;
            }
        }
        break;
    case 3:
        flags18 = 5;
        break;
    case 4:
        flags18 = 4;
        break;
    case 1:
        if (GetTarget())
        {
            LocationDescriptor* ploc = ((::fnv_006777b0::LocationDescriptor *)(reinterpret_cast<::FUN_00672dd0_shell *>((((TESPackageEx*)this)))->FUN_00672dd0()));
            if (ploc && (reinterpret_cast<::DurationData *>((((BoundHolder*)ploc)))->FUN_00678ca0() == 6 || ploc->GetLocationReference() ||
                         ((void *)(reinterpret_cast<::FUN_0067f430_shell *>((((PackageLocationEx*)ploc)))->GetLocationObject())) || reinterpret_cast<::FUN_0067f480_shell *>((((PackageLocationEx*)ploc)))->GetObjectType()))
                flags18 = 7;
            else
                flags18 = 0x2d;
        }
        else
            flags18 = 0xffffffff;
        break;
    case 15:
        flags18 = 0xa;
        break;
    case 2: {
        bool bHasResultObj = false;
        if (GetTarget())
        {
            int etype = GetTarget()->GetTargetKind();
            switch (etype)
            {
            case 0:
                if (GetTarget()->GetReferenceTarget() && ((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((GetTarget()->GetReferenceTarget()))->FUN_007af430())) &&
                    (_FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((GetTarget()->GetReferenceTarget()))->FUN_007af430()))) == 0x2a ||
                     _FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((GetTarget()->GetReferenceTarget()))->FUN_007af430()))) == 0x2b))
                    bHasResultObj = true;
                break;
            case 3:
                if (apLinkedRef && ((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apLinkedRef))->FUN_007af430())) &&
                    (_FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apLinkedRef))->FUN_007af430()))) == 0x2a ||
                     _FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apLinkedRef))->FUN_007af430()))) == 0x2b))
                    bHasResultObj = true;
                break;
            case 1:
                if ((((::fnv_006777b0::TESForm *)(reinterpret_cast<::PackageTargetRecord *>((((PackageTargetEx*)GetTarget())))->GetTargetForm())) &&
                     _FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::PackageTargetRecord *>((((PackageTargetEx*)GetTarget())))->GetTargetForm()))) == 0x2a) ||
                    _FNV_GetFormType(((::fnv_006777b0::TESForm *)(reinterpret_cast<::PackageTargetRecord *>((((PackageTargetEx*)GetTarget())))->GetTargetForm()))) == 0x2b)
                    bHasResultObj = true;
                break;
            case 2:
                if (((PackageTargetEx*)GetTarget())->GetTargetObjectType() == 0xe ||
                    ((PackageTargetEx*)GetTarget())->GetTargetObjectType() == 0xf)
                    bHasResultObj = true;
            }
            if (bHasResultObj)
                flags18 = 8;
            else
                flags18 = 9;
        }
        else
            flags18 = 0xffffffff;
    }
    break;
    case 18:
        flags18 = 0xc;
        break;
    case 28:
        flags18 = 0xa;
        break;
    case 20:
        flags18 = 0xd;
        break;
    case 21:
        flags18 = 0xb;
        break;
    case 23:
        flags18 = 0x14;
        break;
    case 26:
        flags18 = 0x15;
        break;
    case 27:
        flags18 = 0x19;
        break;
    case 7:
        flags18 = 0x1b;
        break;
    case 8:
        flags18 = 0x1c;
        break;
    case 16:
        flags18 = 0x2c;
        break;
    case 9:
        flags18 = 0x1e;
        break;
    case 29:
        flags18 = 0x1f;
        break;
    case 22:
        flags18 = 0x13;
        break;
    case 10:
        flags18 = 0x20;
        break;
    case 24:
        flags18 = 0xf;
        break;
    case 30:
        flags18 = 0x21;
        break;
    case 31:
        flags18 = 0x24;
        break;
    case 12:
        flags18 = 0x25;
        break;
    case 13:
        flags18 = 0x26;
        break;
    case 32:
        flags18 = 0x27;
        break;
    case 33:
        flags18 = 0x28;
        break;
    case 14:
        flags18 = 0x29;
        break;
    case 34:
        flags18 = 0x2a;
        break;
    case 35:
        flags18 = 0x2b;
        break;
    case 36:
        flags18 = 0x2e;
        break;
    default:
        flags18 = 0xffffffff;
    }
    if (flags18 == 0xffffffff)
    {
        char message[260];
        ::std::sprintf(message, "Package '%s' is not a valid package because it is missing necessary Target Or Location Info.",
                ((const char *)(::FUN_00464f30((std::intptr_t)(((TESPackageVt*)this)->GetEditorID())))));
        flags18 = 0;
        ((TESPackageEx*)this)->SetPackageType(6);
    }
}
}  // namespace fnv_006777b0

struct TESFormBase
{
    TESFormBase();
    virtual ~TESFormBase();
    int pad[13];
};
struct CondS
{
    CondS();
    ~CondS();
    int pad[3];
};
struct FUN_0067da40
{
    FUN_0067da40();
    ~FUN_0067da40();
    int pad[4];
};
struct SFTX
{
};
struct FUN_006707c0 : public TESFormBase
{
    DurationData m_kSchedule;
    CondS m_kConditions;
    FUN_0067da40 OnBegin;
    FUN_0067da40 OnEnd;
    FUN_0067da40 OnChange;
    unsigned int m_uiRefCount;
    FUN_006707c0();
    virtual ~FUN_006707c0();
};
// @fnv 0x006707c0
FUN_006707c0::FUN_006707c0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)this)))->FUN_004f15a0(0x49);
    ((TESPackage*)this)->ResetFormData();
    m_uiRefCount = 0;
}

namespace fnv_00676e40 {
struct ActiveEffect;
struct Actor;
struct AlchemyItem;
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSTerrainManager;
struct BSPortalGraph;
struct BaseFormComponent;
struct CHUNK;
struct Crime;
struct EffectItem;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct ImpactSwap;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NiColor;
struct NiNode;
struct NiPoint3;
struct SpellItem;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESFullName;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESTerrainLODManager;
struct TESTexture;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct hkpRigidBody;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00676e40_shell : public TESPackage
{
    bool FUN_00676e40(MobileObject*, int);
};

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& kPt) const;
};

struct TESObjectCELL
{
    bool IsCellInterior() const;
};

namespace FO {

class TESForm
{
  public:
    int GetFormType() const;
};

class BaseProcess
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual void Unk_7D();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual void Unk_AF();
    virtual void Unk_B0();
    virtual void Unk_B1();
    virtual void Unk_B2();
    virtual void Unk_B3();
    virtual void Unk_B4();
    virtual void Unk_B5();
    virtual void Unk_B6();
    virtual void Unk_B7();
    virtual void Unk_B8();
    virtual void Unk_B9();
    virtual void Unk_BA();
    virtual void Unk_BB();
    virtual void Unk_BC();
    virtual void Unk_BD();
    virtual void Unk_BE();
    virtual void Unk_BF();
    virtual void Unk_C0();
    virtual void Unk_C1();
    virtual void Unk_C2();
    virtual void Unk_C3();
    virtual void Unk_C4();
    virtual void Unk_C5();
    virtual void Unk_C6();
    virtual void Unk_C7();
    virtual void Unk_C8();
    virtual void Unk_C9();
    virtual void Unk_CA();
    virtual void Unk_CB();
    virtual void Unk_CC();
    virtual void Unk_CD();
    virtual void Unk_CE();
    virtual void Unk_CF();
    virtual void Unk_D0();
    virtual void Unk_D1();
    virtual void Unk_D2();
    virtual void Unk_D3();
    virtual void Unk_D4();
    virtual void Unk_D5();
    virtual void Unk_D6();
    virtual void Unk_D7();
    virtual void Unk_D8();
    virtual void Unk_D9();
    virtual void Unk_DA();
    virtual void Unk_DB();
    virtual void Unk_DC();
    virtual void Unk_DD();
    virtual void Unk_DE();
    virtual void Unk_DF();
    virtual void Unk_E0();
    virtual void Unk_E1();
    virtual void Unk_E2();
    virtual void Unk_E3();
    virtual void Unk_E4();
    virtual void Unk_E5();
    virtual void Unk_E6();
    virtual void Unk_E7();
    virtual void Unk_E8();
    virtual void Unk_E9();
    virtual void Unk_EA();
    virtual void Unk_EB();
    virtual void Unk_EC();
    virtual void Unk_ED();
    virtual void Unk_EE();
    virtual void Unk_EF();
    virtual void Unk_F0();
    virtual void Unk_F1();
    virtual void Unk_F2();
    virtual void Unk_F3();
    virtual void Unk_F4();
    virtual void Unk_F5();
    virtual void Unk_F6();
    virtual void Unk_F7();
    virtual void Unk_F8();
    virtual void Unk_F9();
    virtual void Unk_FA();
    virtual void Unk_FB();
    virtual void Unk_FC();
    virtual void Unk_FD();
    virtual void Unk_FE();
    virtual void Unk_FF();
    virtual void Unk_100();
    virtual void Unk_101();
    virtual void Unk_102();
    virtual void Unk_103();
    virtual void Unk_104();
    virtual void Unk_105();
    virtual void Unk_106();
    virtual void Unk_107();
    virtual void Unk_108();
    virtual void Unk_109();
    virtual void Unk_10A();
    virtual void Unk_10B();
    virtual void Unk_10C();
    virtual void Unk_10D();
    virtual void Unk_10E();
    virtual void Unk_10F();
    virtual void Unk_110();
    virtual void Unk_111();
    virtual void Unk_112();
    virtual void Unk_113();
    virtual void Unk_114();
    virtual void Unk_115();
    virtual void Unk_116();
    virtual void Unk_117();
    virtual void Unk_118();
    virtual void Unk_119();
    virtual void Unk_11A();
    virtual void Unk_11B();
    virtual void Unk_11C();
    virtual void Unk_11D();
    virtual void Unk_11E();
    virtual void Unk_11F();
    virtual void Unk_120();
    virtual void Unk_121();
    virtual void Unk_122();
    virtual void Unk_123();
    virtual void Unk_124();
    virtual void Unk_125();
    virtual void Unk_126();
    virtual void Unk_127();
    virtual void Unk_128();
    virtual void Unk_129();
    virtual void Unk_12A();
    virtual void Unk_12B();
    virtual void Unk_12C();
    virtual void Unk_12D();
    virtual void Unk_12E();
    virtual void Unk_12F();
    virtual void Unk_130();
    virtual void Unk_131();
    virtual void Unk_132();
    virtual void Unk_133();
    virtual void Unk_134();
    virtual NiPoint3* GetPackageLocation();
};

class TESObjectREFR
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual bool IsActor();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual NiPoint3* GetPos();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual int GetSitSleepState();
};

class MobileObject : public TESObjectREFR
{
  public:
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual void Unk_AF();
    virtual void Unk_B0();
    virtual void Unk_B1();
    virtual TESObjectREFR* GetPackageTargetRef();
    virtual bool IsWithinDistance(NiPoint3* apPoint, float afRadius, bool abCheckZ, bool abExact);
};

class Actor : public MobileObject
{
};

class PlayerCharacter : public Actor
{
};

}

struct SettingFloat
{
};

struct Interface
{
};

namespace std {
double abs(float afValue);
}


class FUN_00676e40_Package : public TESPackage
{
  public:
    float GetPackageLocationRadius(FO::MobileObject* apMobileObject, bool abUseDefault);
    bool IsActorInPackageRadius(FO::MobileObject* apMobileObject, int aiExtraRadius);
};

// @fnv 0x00676e40
bool FUN_00676e40_Package::IsActorInPackageRadius(FO::MobileObject* apMobileObject, int aiExtraRadius)
{
    FO::Actor* apActor;
    int m_iSearchRadius;
    TESWorldSpace* ptargworld;
    FO::TESObjectREFR* ptargref;
    bool bsamespace;
    bool boverride;
    char message[300];
    TESObjectCELL* pactorintcell;
    bool bGoodPt;
    bool bexactpos;
    TESWorldSpace* pactorworld;
    NiPoint3 targloc;
    TESObjectCELL* ptargintcell;

    if (!apMobileObject || !apMobileObject->GetPackageTargetRef())
        return false;

    apActor = 0;
    if (apMobileObject->IsActor())
        apActor = static_cast<FO::Actor*>(apMobileObject);
    bexactpos = false;
    ptargref = apMobileObject->GetPackageTargetRef();
    targloc = *ptargref->GetPos();
    if (((void *)(reinterpret_cast<::TESObjectREFR *>((ptargref))->GetExtraRadioData())))
        targloc = *((::fnv_00676e40::NiPoint3 *)&(reinterpret_cast<::fnv_00568fa0::Fn568fa0 *>((ptargref))->FUN_00568fa0()));
    ptargworld = ((::fnv_00676e40::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((ptargref))->FUN_00575d70()));
    ptargintcell = ((::fnv_00676e40::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ptargref))->GetTarget()));
    if (ptargintcell && !ptargintcell->IsCellInterior())
        ptargintcell = 0;
    pactorworld = ((::fnv_00676e40::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((apMobileObject))->FUN_00575d70()));
    pactorintcell = ((::fnv_00676e40::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((apMobileObject))->GetTarget()));
    if (pactorintcell && !pactorintcell->IsCellInterior())
        pactorintcell = 0;

    bsamespace = false;
    if (pactorintcell || ptargintcell)
    {
        if (pactorintcell == ptargintcell)
            bsamespace = true;
    }
    else
    {
        if (pactorworld == ptargworld)
            bsamespace = true;
    }
    if (!bsamespace)
        return false;

    m_iSearchRadius = (int)GetPackageLocationRadius(apMobileObject, false);
    bGoodPt = false;
    NiPoint3 dist = targloc - *apMobileObject->GetPos();

    if (reinterpret_cast<::FUN_00568680_shell *>((ptargref))->FUN_00568680() && ((::fnv_00676e40::FO::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apMobileObject))->GetBaseTexture())) &&
        ((::fnv_00676e40::FO::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apMobileObject))->GetBaseTexture()))->GetPackageLocation())
    {
        if (!((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_00676e40::FO::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apMobileObject))->GetBaseTexture()))))->FUN_0045cd60())))
            targloc = *((::fnv_00676e40::FO::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apMobileObject))->GetBaseTexture()))->GetPackageLocation();
        m_iSearchRadius = 10;
        bexactpos = true;
    }
    else if (((::fnv_00676e40::FO::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ptargref))->FUN_007af430()))->GetFormType() == 48)
    {
        m_iSearchRadius = 10;
        bexactpos = true;
    }
    else if (m_iSearchRadius <= 20 && ptargref->IsActor() && ptargref != (*reinterpret_cast<::fnv_00676e40::FO::PlayerCharacter * *>(&::_g_thePlayer)))
    {
        FO::Actor* pact = static_cast<FO::Actor*>(ptargref);
        if (pact->GetSitSleepState() == 9)
        {
            m_iSearchRadius = 90;
            bexactpos = true;
        }
        else if (apMobileObject->GetSitSleepState() == 4)
        {
            m_iSearchRadius = 200;
            bexactpos = true;
        }
        else if (m_iSearchRadius <= 20)
        {
            m_iSearchRadius = (int)reinterpret_cast<::TESObjectREFR *>((ptargref))->GetBoundingRadius() + 20;
        }
    }
    else if (((::fnv_00676e40::FO::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ptargref))->FUN_007af430())) == (*reinterpret_cast<::fnv_00676e40::FO::TESForm * *>(&::DAT_011ca248)) || ((::fnv_00676e40::FO::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ptargref))->FUN_007af430())) == (*reinterpret_cast<::fnv_00676e40::FO::TESForm * *>(&::DAT_011ca244)))
    {
        m_iSearchRadius = 20;
        bexactpos = true;
    }

    m_iSearchRadius += aiExtraRadius;
    if (std::abs(dist.z) < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00676e40::SettingFloat *>(&::originalRuntimeFloatSetting804)))))))
        dist.z = 0.0f;

    boverride = false;
    if (apMobileObject->IsWithinDistance(&targloc, (float)m_iSearchRadius, !bexactpos, false) && !boverride)
        bGoodPt = true;

    if (ptargref && reinterpret_cast<::FUN_00568680_shell *>((ptargref))->FUN_00568680() && ((::fnv_00676e40::FO::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apMobileObject))->GetBaseTexture())) &&
        ((::fnv_00676e40::FO::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apMobileObject))->GetBaseTexture()))->GetPackageLocation())
    {
        NiPoint3 dist = targloc - *apMobileObject->GetPos();
        if ((reinterpret_cast<::FUN_00589850_Class *>((void *)&(dist))->FUN_00589850() < 100.0 && apActor->GetSitSleepState() == 4) || apActor->GetSitSleepState() == 9)
            bGoodPt = true;
    }

    if (((::fnv_00676e40::FO::Actor *)(::fnv_00703180::FUN_00703180())) == apActor)
    {
        float fdist = reinterpret_cast<::FUN_00589850_Class *>((void *)&(dist))->FUN_00589850();
        if (::std::isfinite(fdist))
        {
            ::std::sprintf(message, "radius %d distance %.02f", m_iSearchRadius, fdist);
            ::FUN_0040fbe0();
        }
    }

    return bGoodPt;
}
}  // namespace fnv_00676e40

namespace fnv_00671e10 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESForm;
struct TESObjectCELL;
struct TESPackageData;
struct TESTopic;
struct LocationDescriptor
{
    int GetLocType();
    void SetLocationType(int);
    void SetRadius(unsigned int);
    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
    TESForm* GetLocationObject();
    int GetSearchRadius();
    void SetLocRef(TESObjectREFR*);
    void SetLocCell(TESObjectCELL*);
    void SetLocObject(TESForm*);
    void SetLocObjectType(int);
    void Copy(LocationDescriptor*, bool);
    bool Compare(LocationDescriptor*);
    void Save(int);
    void InitItem(TESForm*);
    bool IsLocationGeneric();
    bool GetIsValidLocation(TESForm*);
    bool IsRadiusNonZero();
    TESObjectREFR* ResolveLocationReference(MobileObject*);
    bool IsRefAtLocationTrigger(MobileObject*, TESObjectREFR*, bool*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    unsigned int GetRadius();
    void* __vecDelDtor(unsigned int);
    char m_ucLocationType;
    char _pad_1[3];
    unsigned int m_pLocationData;
    int eObjType;
};
struct FUN_00671e10_shell : public TESPackage
{
    void FUN_00671e10(LocationDescriptor*);
};

// LocationDescriptor constructor / deleting destructor (missing from the prelude struct)
struct FUN_0067f030 : LocationDescriptor
{
    FUN_0067f030();
};
struct FUN_00670b30 : LocationDescriptor
{
    ~FUN_00670b30();
};

struct TESPackageData
{
    virtual ~TESPackageData();
};
// TESDialoguePackageData
struct FUN_0067b170 : TESPackageData
{
    FUN_0067b170();
    TESTopic* pTopic;
    unsigned int uiFlags;
    LocationDescriptor* pLoc;
    unsigned int data[4];
};
// TESEatPackageData
struct FUN_0067b950 : TESPackageData
{
    FUN_0067b950();
    LocationDescriptor* pLoc;
};
// TESEscortPackageData
struct FUN_0067bbf0 : TESPackageData
{
    FUN_0067bbf0();
    LocationDescriptor* pLoc;
    float fDistance;
};
// TESAmbushPackageData
struct FUN_0067acf0 : TESPackageData
{
    FUN_0067acf0();
    LocationDescriptor* pLoc;
};
// TESFollowPackageData
struct FUN_0067bfd0 : TESPackageData
{
    FUN_0067bfd0();
    LocationDescriptor* pLoc;
    float fDistance;
};
// TESUseItemPackageData
struct FUN_0067c770 : TESPackageData
{
    FUN_0067c770();
    LocationDescriptor* pLoc;
};
struct TESUseWeaponPackageData : TESPackageData
{
    unsigned int uiFlags;
    LocationDescriptor* pLoc;
};
struct FUN_00672d10_shell
{
};

// Sets the package location data for the package type, creating the type-specific data and copying or clearing its location.
// @fnv 0x00671e10
void FUN_00671e10_shell::FUN_00671e10(LocationDescriptor* apPackLoc)
{
    if (GetPackType() == 0xf || GetPackType() == 0x1c)
    {
        FUN_0067b170* pdata = 0;
        if (!data)
        {
            pdata = new FUN_0067b170;
            data = (TESPatrolPackageData*)pdata;
        }
        else
            pdata = (FUN_0067b170*)data;
        if (!apPackLoc)
        {
            delete (FUN_00670b30*)pdata->pLoc;
            pdata->pLoc = 0;
        }
        else
        {
            if (!pdata->pLoc)
                pdata->pLoc = new FUN_0067f030;
            pdata->pLoc->Copy(apPackLoc, false);
        }
    }
    else if (GetPackType() == 3)
    {
        FUN_0067b950* pdata = 0;
        if (!data)
        {
            pdata = new FUN_0067b950;
            data = (TESPatrolPackageData*)pdata;
        }
        else
            pdata = (FUN_0067b950*)data;
        if (!apPackLoc)
        {
            delete (FUN_00670b30*)pdata->pLoc;
            pdata->pLoc = 0;
        }
        else
        {
            if (!pdata->pLoc)
                pdata->pLoc = new FUN_0067f030;
            pdata->pLoc->Copy(apPackLoc, false);
        }
    }
    else if (GetPackType() == 2)
    {
        FUN_0067bbf0* pdata = 0;
        if (!data)
        {
            pdata = new FUN_0067bbf0;
            data = (TESPatrolPackageData*)pdata;
        }
        else
            pdata = (FUN_0067bbf0*)data;
        if (!apPackLoc)
        {
            delete (FUN_00670b30*)pdata->pLoc;
            pdata->pLoc = 0;
        }
        else
        {
            if (!pdata->pLoc)
                pdata->pLoc = new FUN_0067f030;
            pdata->pLoc->Copy(apPackLoc, false);
        }
    }
    else if (GetPackType() == 9)
    {
        FUN_0067acf0* pdata = 0;
        if (!data)
        {
            pdata = new FUN_0067acf0;
            data = (TESPatrolPackageData*)pdata;
        }
        else
            pdata = (FUN_0067acf0*)data;
        if (!apPackLoc)
        {
            delete (FUN_00670b30*)pdata->pLoc;
            pdata->pLoc = 0;
        }
        else
        {
            if (!pdata->pLoc)
                pdata->pLoc = new FUN_0067f030;
            pdata->pLoc->Copy(apPackLoc, false);
        }
    }
    else if (GetPackType() == 1)
    {
        FUN_0067bfd0* pdata = 0;
        if (!data)
        {
            pdata = new FUN_0067bfd0;
            data = (TESPatrolPackageData*)pdata;
        }
        else
            pdata = (FUN_0067bfd0*)data;
        if (!apPackLoc)
        {
            delete (FUN_00670b30*)pdata->pLoc;
            pdata->pLoc = 0;
        }
        else
        {
            if (!pdata->pLoc)
                pdata->pLoc = new FUN_0067f030;
            pdata->pLoc->Copy(apPackLoc, false);
        }
    }
    else if (GetPackType() == 8)
    {
        FUN_0067c770* pdata = 0;
        if (!data)
        {
            pdata = new FUN_0067c770;
            data = (TESPatrolPackageData*)pdata;
        }
        else
            pdata = (FUN_0067c770*)data;
        if (!apPackLoc)
        {
            delete (FUN_00670b30*)pdata->pLoc;
            pdata->pLoc = 0;
        }
        else
        {
            if (!pdata->pLoc)
                pdata->pLoc = new FUN_0067f030;
            pdata->pLoc->Copy(apPackLoc, false);
        }
    }
    else if (GetPackType() == 0x10)
    {
        TESUseWeaponPackageData* pdata = ((::fnv_00671e10::TESUseWeaponPackageData *)(reinterpret_cast<::FUN_00672d10_Class *>((((FUN_00672d10_shell*)this)))->FUN_00672d10()));
        if (apPackLoc)
        {
            if (!pdata->pLoc)
                pdata->pLoc = new FUN_0067f030;
            pdata->pLoc->Copy(apPackLoc, false);
        }
        else
        {
            delete (FUN_00670b30*)pdata->pLoc;
            pdata->pLoc = 0;
        }
    }
}
}  // namespace fnv_00671e10

class FUN_00675980_shell : public TESPackage
{
  public:
    TESObjectREFR* FUN_00675980();
};

// Returns the reference stored at offset 0x28 when the package type is 0xe, otherwise returns null.
// @fnv 0x00675980
TESObjectREFR* FUN_00675980_shell::FUN_00675980()
{
    if (GetPackType() == (PTYPE)0xe)
        return reinterpret_cast<TESObjectREFR*>(data);
    return 0;
}

// @fnv 0x0067a560
bool FUN_0067a560(std::intptr_t pObject)
{
    return (*(int*)(pObject + 0x1c) & 0x40000) ? true : false;
}

struct FUN_0067a5d0_shell
{
    int _0, _4, _8, _c, _10, _14, _18;
    unsigned int flags;  // +0x1c
};

struct FUN_0067a5d0_class
{
    int _0, _4, _8, _c, _10, _14, _18;
    unsigned int flags;  // +0x1c
    bool FUN_0067a5d0();
};

// @fnv 0x0067a5d0
bool FUN_0067a5d0_class::FUN_0067a5d0()
{
    return (flags & 0x80000) ? true : false;
}

// @fnv 0x0067a9d0
bool FUN_0067a9d0(void* pObject)
{
    return (reinterpret_cast<TESPackage*>(pObject)->f22 & 8) ? true : false;
}

struct TESUseWeaponPackageData
{
};

struct TESPackageShell : TESPackage
{
    const TESUseWeaponPackageData* FUN_006758f0();
};

// Returns the package data cast to TESUseWeaponPackageData when the pack type is 0x10, otherwise returns null.
// @fnv 0x006758f0
const TESUseWeaponPackageData* TESPackageShell::FUN_006758f0()
{
    if (GetPackType() == 0x10)
        return (const TESUseWeaponPackageData*)data;
    return 0;
}

struct TESFormStub : public TESPackage
{
    void FUN_00484c50(unsigned int, unsigned int);
    void ApplyFormFlags(unsigned int, unsigned int);
};

void TESFormStub::FUN_00484c50(unsigned int, unsigned int)
{}

// @fnv 0x00679700
void TESFormStub::ApplyFormFlags(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>(this)->FUN_00484c50(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x80000000)
        flags |= 0x8000;
    if (aiFlags & 0x40000000)
        flags |= 0x10000;
}

struct FUN_0067a410_shell : public TESPackage
{
    void SetFlag400000(bool enabled);
};

// @fnv 0x0067a410
void FUN_0067a410_shell::SetFlag400000(bool enabled)
{
    enabled ? flags |= 0x400000 : flags &= ~0x400000;
}

struct FUN_0067a510_shell
{
    unsigned int _pad0;
    unsigned int _pad1;
    unsigned int _pad2;
    unsigned int _pad3;
    unsigned int _pad4;
    unsigned int _pad5;
    unsigned int _pad6;
    unsigned int m_flags;  // +0x1c
    void SetFlag20000(bool enabled);
};

// @fnv 0x0067a510
void FUN_0067a510_shell::SetFlag20000(bool enabled)
{
    enabled ? m_flags |= 0x20000 : m_flags &= ~0x20000;
}

struct FUN_0067a580_shell
{
    int mPad[7];
    int mFlags;  // +0x1c
    void SetFlag40000(bool enabled);
};

// @fnv 0x0067a580
void FUN_0067a580_shell::SetFlag40000(bool enabled)
{
    enabled ? mFlags |= 0x40000 : mFlags &= ~0x40000;
}

struct FUN_0067a5f0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void SetFlag80000(bool enabled);
};

// @fnv 0x0067a5f0
void FUN_0067a5f0_shell::SetFlag80000(bool enabled)
{
    enabled ? m_1c |= 0x80000 : m_1c &= ~0x80000;
}

struct FUN_0067a640_shell
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    void SetFlag200000(bool param_2);
};

// @fnv 0x0067a640
void FUN_0067a640_shell::SetFlag200000(bool abSet)
{
    abSet ? m_001c |= 0x200000 : m_001c &= ~0x200000;
}

struct FUN_0067a6b0_shell : public TESPackage
{
    void SetFlag100000(bool flag);
};

// @fnv 0x0067a6b0
void FUN_0067a6b0_shell::SetFlag100000(bool abSet)
{
    abSet ? flags |= 0x100000 : flags &= ~0x100000;
}

struct FUN_0067a7e0_shell
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    int m_pad3;
    int m_pad4;
    int m_pad5;
    int m_pad6;
    int m_flags;  // +0x1c
    bool IsFlag28Clear();
};

// @fnv 0x0067a7e0
bool FUN_0067a7e0_shell::IsFlag28Clear()
{
    return (m_flags & 0x10000000) ? false : true;
}

struct FUN_0067a8f0_shell : public TESPackage
{
    void SetFlag2(bool bFlag);
};

// Sets or clears bit 2 of the 16-bit field at offset 0x22 based on bFlag.
// @fnv 0x0067a8f0
void FUN_0067a8f0_shell::SetFlag2(bool abSet)
{
    abSet ? f22 |= 2 : f22 &= ~2;
}

struct FUN_0067a970_shell : public TESPackage
{
    void SetFlag4(bool value);
};

// Sets or clears bit 4 of the 16-bit field at offset 0x22 based on the value argument.
// @fnv 0x0067a970
void FUN_0067a970_shell::SetFlag4(bool abSet)
{
    abSet ? f22 |= 4 : f22 &= ~4;
}

struct FUN_0067a9f0_shell : public TESPackage
{
    void SetFlag8(bool bFlag);
};

// @fnv 0x0067a9f0
void FUN_0067a9f0_shell::SetFlag8(bool abSet)
{
    abSet ? f22 |= 8 : f22 &= ~8;
}

struct FUN_0067aa70_shell
{
    unsigned char m_00[0x22];
    unsigned short m_22;
    void FUN_0067aa70(bool show);
};

// Sets or clears bit 0x10 in m_22 according to show.
// @fnv 0x0067aa70
void FUN_0067aa70_shell::FUN_0067aa70(bool show)
{
    show ? m_22 |= 0x10 : m_22 &= ~0x10;
}

struct FUN_0067ab70_shell
{
    unsigned char mPad0[0x22];
    unsigned short mFlags;
    void FUN_0067ab70(bool flag);
};

// Sets or clears bit 0x40 in mFlags according to flag.
// @fnv 0x0067ab70
void FUN_0067ab70_shell::FUN_0067ab70(bool abSet)
{
    abSet ? mFlags |= 0x40 : mFlags &= ~0x40;
}

namespace fnv_00671d30 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESForm;
struct TESObjectCELL;
struct LocationDescriptor
{
    int GetLocType();
    void SetLocationType(int);
    void SetRadius(unsigned int);
    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
    TESForm* GetLocationObject();
    int GetSearchRadius();
    void SetLocRef(TESObjectREFR*);
    void SetLocCell(TESObjectCELL*);
    void SetLocObject(TESForm*);
    void SetLocObjectType(int);
    void Copy(LocationDescriptor*, bool);
    bool Compare(LocationDescriptor*);
    void Save(int);
    void InitItem(TESForm*);
    bool IsLocationGeneric();
    bool GetIsValidLocation(TESForm*);
    bool IsRadiusNonZero();
    TESObjectREFR* ResolveLocationReference(MobileObject*);
    bool IsRefAtLocationTrigger(MobileObject*, TESObjectREFR*, bool*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    unsigned int GetRadius();
    void* __vecDelDtor(unsigned int);
    char m_ucLocationType;
    char _pad_1[3];
    unsigned int m_pLocationData;
    int eObjType;
};
struct FUN_00671d30_shell : public TESPackage
{
    void FUN_00671d30(LocationDescriptor*);
};


struct FUN_00670b30 : LocationDescriptor
{
    FUN_00670b30();
    ~FUN_00670b30();
};

// Copies apPackLoc into the package's location object, allocating it if null, or deletes and clears it when apPackLoc is null.
// @fnv 0x00671d30
void FUN_00671d30_shell::FUN_00671d30(LocationDescriptor* apPackLoc)
{
    LocationDescriptor*& rpLocation = reinterpret_cast<LocationDescriptor*&>(pPackageLocation);
    if (apPackLoc)
    {
        if (!rpLocation)
        {
            rpLocation = new FUN_00670b30;
        }
        rpLocation->Copy(apPackLoc, false);
    }
    else
    {
        delete (FUN_00670b30*)rpLocation;
        rpLocation = 0;
    }
}
}  // namespace fnv_00671d30

template <int N> struct EndianSizeTag
{
};
struct S
{
    unsigned int flags;
    unsigned char type;
    char pad5;
    unsigned short f22;
    unsigned short f24;
    void FUN_00670760();
};
// @fnv 0x00670760
void S::FUN_00670760()
{
    ::FUN_00401080((int *)&flags);
    ::FUN_00407a90((short *)&f22);
    ::FUN_00407a90((short *)&f24);
}

struct FUN_006708b0
{
    ~FUN_006708b0();
};


struct FUN_00670880_shell : FUN_006708b0
{
    void* FUN_00670880(unsigned int flags);
};

// Runs the destructor, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00670880
void* FUN_00670880_shell::FUN_00670880(unsigned int flags)
{
    this->FUN_006708b0::~FUN_006708b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Holder
{
    void* FUN_00670b60(unsigned int flags);
public:
    void FUN_00485680();
};
// @fnv 0x00670b60
void* Holder::FUN_00670b60(unsigned int flags)
{
    reinterpret_cast<::fnv_004797c0::FUN_004797c0_shell *>(this)->FUN_004797c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00675670 {
struct LocationDescriptor
{
};
struct FUN_00672dd0_shell
{
};
struct FUN_00675670_shell : FUN_00672dd0_shell
{
    unsigned int FUN_00675670();
};
// Calls FUN_00672dd0 to get an object and, if non-null, returns the result of its FUN_0067f1c0; otherwise returns 0.
// @fnv 0x00675670
unsigned int FUN_00675670_shell::FUN_00675670()
{
    LocationDescriptor* loc = ((::fnv_00675670::LocationDescriptor *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
    if (loc)
        return reinterpret_cast<::FUN_0067f1c0_shell *>((loc))->FUN_0067f1c0();
    else
        return 0;
}
}  // namespace fnv_00675670

struct Script
{
    int GetText();
public:
    char *GetData();
};
// @fnv 0x006759e0
TESObjectREFR* TESPackage::GetResolvedTargetReference(MobileObject* actor)
{
    TESObjectREFR* result = 0;
    if (((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData())))
    {
        switch (((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()))->GetTargetKind())
        {
        case 0:
            result = ((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()))->GetReferenceTarget();
            break;
        case 3:
            result = reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80();
            break;
        }
    }
    return result;
}
// @fnv 0x006728a0
bool TESPackage::GetPackageSearchRadius(MobileObject* actor, float& radius)
{
    radius = 0.0f;
    if (GetPackType() == 12)
    {
        radius = (float)reinterpret_cast<::HighProcess *>(this)->UpdateHighProcessState((::Actor *)(actor));
        return true;
    }
    PackageTargetRecord* target = ((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()));
    if (!target)
        return false;
    float value = reinterpret_cast<::Twin_0084d030 *>((((TimeGlobal*)target)))->GetStoredFloatValue();
    if (value <= 0.0)
        return false;
    radius = value;
    return true;
}
// @fnv 0x00672930
int FUN_00672930_cls::FUN_00672930()
{
    PackageTargetRecord* ptarget = ((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()));
    std::intptr_t count;
    if (!ptarget)
        return 0;
    if (ptarget->GetTargetKind() == 0 || ptarget->GetTargetKind() == 3)
        return 1;
    count = ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((FUN_00672930_flags*)ptarget)))->GetName()));
    if (count > 0)
        return count;
    if (((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0())) == 0x1c)
        return 1;
    if (((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0())) == 2 || ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0())) == 3 || ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0())) == 0x1a)
        return 0x7fffffff;
    return 0;
}
// @fnv 0x00678ec0
bool FUN_00678ec0_shell::FUN_00678ec0(MobileObject* apActor)
{
    bool bHasResultObj = false;
    PackageTargetRecord* pTarget = ((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()));
    if (!pTarget)
        return false;

    switch (pTarget->GetTargetKind())
    {
    case 0:
        if (pTarget->GetReferenceTarget() && ((TESObjectREFR_vtbl*)pTarget->GetReferenceTarget())->IsActor())
            bHasResultObj = true;
        break;
    case 3:
        if (reinterpret_cast<::FUN_00569b80_shell *>((apActor))->FUN_00569b80())
            bHasResultObj = ((TESObjectREFR_vtbl*)reinterpret_cast<::FUN_00569b80_shell *>((apActor))->FUN_00569b80())->IsActor();
        break;
    case 1: {
        unsigned char etype = _FNV_GetFormType(reinterpret_cast<::PackageTargetRecord *>((((PackageTarget_ext*)pTarget)))->GetTargetForm());
        if (etype == 0x2A || etype == 0x2B)
            bHasResultObj = true;
    }
    break;
    case 2: {
        PACKAGE_OBJECT_TYPE etype = reinterpret_cast<::PackageTargetRecord *>((((PackageTarget_ext*)pTarget)))->GetTargetObjectType();
        switch (etype)
        {
        case 14:
        case 15:
            bHasResultObj = true;
            break;
        }
    }
    break;
    }
    return bHasResultObj;
}
struct PkgProxy
{
};
struct F5670
{
};
struct Proxy758a0
{
    unsigned int FUN_006758a0(MobileObject*);
};
struct FUN_00675950_host : public TESPackage
{
    TESPatrolPackageData* GetPatrolData();
};
// Returns the package's patrol data when the pack type is 1, otherwise returns null.
// @fnv 0x00675950
TESPatrolPackageData* FUN_00675950_host::GetPatrolData()
{
    if (GetPackType() == 1)
        return data;
    return 0;
}

struct StandIn006759b0
{
    TESPatrolPackageData* FUN_006759b0();
};
// Returns the package's data pointer when GetPackType() is 2, otherwise returns 0.
// @fnv 0x006759b0
TESPatrolPackageData* StandIn006759b0::FUN_006759b0()
{
    if (((TESPackage*)this)->GetPackType() == 2)
        return ((TESPackage*)this)->data;
    return 0;
}

struct TESEscortPackageData
{
    char _0[8];
    int m_iValue;
};
struct FUN_006784c0_shell
{
    int FUN_006784c0();
};
// @fnv 0x006784c0
int FUN_006784c0_shell::FUN_006784c0()
{
    TESEscortPackageData* pdata;
    if (reinterpret_cast<TESPackage*>(this)->GetPackType() != 2)
        return 0x100;
    pdata = reinterpret_cast<TESEscortPackageData*>(reinterpret_cast<TESPackage*>(this)->data);
    return pdata->m_iValue;
}

struct TESForm
{
    virtual void Revert(unsigned int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    void RevertWithFlagClear(unsigned int aiFlags);
public:
    void ClearData();
};
// @fnv 0x00670a50
void FUN_00670a50_shell::DestroyPackage()
{
    delete ((FUN_00670a50_View*)this)->p2c;
    delete ((FUN_00670a50_View*)this)->p30;
    delete ((FUN_00670a50_View*)this)->p34;
    delete ((FUN_00670a50_View*)this)->p28;
    ((PerkEntryConditionSet*)((PackedByteIntRecord*)this)->Endian())->InitializeConditionItems();
    reinterpret_cast<::TESForm *>((((Date*)this)))->ClearData();
}
// Calls Revert(aiFlags), then clears bit 15 of unk1C if bit 31 is set and bit 16 if bit 30 is set.
// @fnv 0x00679760
void TESForm::RevertWithFlagClear(unsigned int aiFlags)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(aiFlags);
    if (aiFlags & 0x80000000)
        unk1C &= 0xFFFF7FFF;
    if (aiFlags & 0x40000000)
        unk1C &= 0xFFFEFFFF;
}

struct Struct_067A4A0
{
    int _pad[7];
    unsigned int uiFlags;
    void FUN_0067a4a0(bool);
};
// Sets or clears bit 0x2000 in uiFlags according to enabled.
// @fnv 0x0067a4a0
void Struct_067A4A0::FUN_0067a4a0(bool enabled)
{
    enabled ? uiFlags |= 0x2000 : uiFlags &= ~0x2000;
}

struct Fake067a790
{
    unsigned char _pad[0x1C];
    unsigned int uiFlags;
    void FUN_0067a790(bool);
};
// @fnv 0x0067a790
void Fake067a790::FUN_0067a790(bool enabled)
{
    !enabled ? uiFlags |= 0x8000000 : uiFlags &= ~0x8000000;
}

namespace fnv_0067a800 {
struct S
{
    unsigned char pad[0x1C];
    unsigned int flags;
    void FUN_0067a800(bool);
};
// @fnv 0x0067a800
void S::FUN_0067a800(bool b)
{
    !b ? flags |= 0x10000000 : flags &= ~0x10000000;
}
}  // namespace fnv_0067a800

struct FUN_0067aaf0_Holder : public TESPackage
{
    void FUN_0067aaf0(bool);
};
// Sets or clears bit 0x20 in the 16-bit flags field at offset 0x22 based on show.
// @fnv 0x0067aaf0
void FUN_0067aaf0_Holder::FUN_0067aaf0(bool show)
{
    show ? f22 |= 0x20 : f22 &= ~0x20;
}

struct FUN_0067abf0_shell : public TESPackage
{
    void FUN_0067abf0(bool);
};
// Sets or clears bit 0x80 in the 16-bit flags field at offset 0x22 according to show.
// @fnv 0x0067abf0
void FUN_0067abf0_shell::FUN_0067abf0(bool show)
{
    show ? f22 |= 0x80 : f22 &= ~0x80;
}

extern int DAT_01068860;
struct FUN_0067acf0
{
    void* _0;
    int _4;
    FUN_0067acf0();
};
// Calls FUN_0067ad20, then sets _0 to point at DAT_01068860 and _4 to 0.
// @fnv 0x0067acf0
FUN_0067acf0::FUN_0067acf0()
{
    new ((void *)this) ::FUN_0067ad20_Class();
    _0 = &DAT_01068860;
    _4 = 0;
}

struct FUN_0067ad20_Base
{
};
extern int DAT_01068938;
struct FUN_0067b950 : FUN_0067ad20_Base
{
    void* _0;
    int _4;
    FUN_0067b950();
};
// Calls the base constructor, stores the address of DAT_01068938 in _0 and sets _4 to 0.
// @fnv 0x0067b950
FUN_0067b950::FUN_0067b950()
{
    new ((void *)this) ::FUN_0067ad20_Class();
    _0 = (void*)&DAT_01068938;
    _4 = 0;
}

namespace fnv_0067bbf0 {
struct TESEscortPackageData
{
    const void* pVtable;
    unsigned int unk04;
    int m_iValue;
    TESEscortPackageData* FUN_0067bbf0();
};
// @fnv 0x0067bbf0
TESEscortPackageData* TESEscortPackageData::FUN_0067bbf0()
{
    new ((void *)this) ::FUN_0067ad20_Class();
    pVtable = &::DAT_01068960;
    unk04 = 0;
    m_iValue = 0xC8;
    return this;
}
}  // namespace fnv_0067bbf0

extern int DAT_01068988;
struct S0067bfd0
{
    const void* pVtable;
    unsigned int unk04;
    float unk08;
    S0067bfd0* FUN_0067bfd0();
};
// @fnv 0x0067bfd0
S0067bfd0* S0067bfd0::FUN_0067bfd0()
{
    new ((void *)this) ::FUN_0067ad20_Class();
    pVtable = &DAT_01068988;
    unk04 = 0;
    unk08 = 0.0f;
    return this;
}

extern int DAT_01068a0c;
struct FUN_0067c770
{
    void* vtable;
    int field4;
    FUN_0067c770();
};
// Calls FUN_0067ad20, sets the vtable to DAT_01068a0c and initializes field4 to 0.
// @fnv 0x0067c770
FUN_0067c770::FUN_0067c770()
{
    new ((void *)this) ::FUN_0067ad20_Class();
    vtable = &DAT_01068a0c;
    field4 = 0;
}

struct FUN_0085a290_t
{
    void DeleteFormById(unsigned int);
    TESPackage* FUN_0085a240(unsigned int, unsigned char);
};
struct Helper
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74(unsigned int, int);
};
// Calls DeleteFormById with a1, creates a package from a2, sets its field via f74(a1, 1), and returns the package.
// @fnv 0x0085a240
TESPackage* FUN_0085a290_t::FUN_0085a240(unsigned int a1, unsigned char ucPackageType)
{
    DeleteFormById(a1);
    TESPackage* p = ::CreatePackageByType((*(int *)&(const ::PTYPE &)((PTYPE)ucPackageType)));
    ((Helper*)p)->f74(a1, 1);
    return p;
}

struct TESDialoguePackageData
{
    char pad[24];
    bool m_bThirdFlag;
};
struct TESPackageStandIn
{
    bool FUN_00672710();
};
// @fnv 0x00672710
bool TESPackageStandIn::FUN_00672710()
{
    bool bsayto = 0;
    TESDialoguePackageData* pdata;
    if (((TESPackage*)this)->GetPackType() == 0xF || ((TESPackage*)this)->GetPackType() == 0x1C)
    {
        pdata = (TESDialoguePackageData*)((TESPackage*)this)->data;
        if (pdata)
            bsayto = pdata->m_bThirdFlag;
    }
    return bsayto;
}

struct Dummy0067a870
{
    unsigned char _pad[0x22];
    unsigned short flag;
    void SetFlag(bool show);
};
// Sets or clears bit 0 of flag according to show.
// @fnv 0x0067a870
void Dummy0067a870::SetFlag(bool show)
{
    show ? flag |= 1 : flag &= ~1;
}

namespace fnv_006708b0 {
struct DH
{
};
struct BGSSaveLoadGame
{
};
struct S_00970810
{
};
struct FUN_00670a50_shell
{
};
struct Base5a
{
    virtual ~Base5a();
    char pad04[0x34];
};
struct Date
{
    ~Date();
    unsigned int a, b;
};
struct PerkEntryConditionSet
{
    ~PerkEntryConditionSet();
    unsigned int a, b;
};
struct FUN_0067da80
{
    ~FUN_0067da80();
    unsigned int a[4];
};

struct FUN_006708b0 : Base5a
{
    Date m_kSchedule;
    PerkEntryConditionSet m_kConditions;
    unsigned int m_pCombatStyle;
    FUN_0067da80 OnBegin;
    FUN_0067da80 OnEnd;
    FUN_0067da80 OnChange;
    unsigned int m_uiRefCount;
    virtual ~FUN_006708b0();
};

// @fnv 0x006708b0
FUN_006708b0::~FUN_006708b0()
{
    if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::fnv_006708b0::DH * *>(&::g_dataHandler))))->FUN_004226e0())
    {
        m_uiRefCount++;
        if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_006708b0::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() || ((TESPackage*)this)->GetPackType() == 0x15 ||
            ((TESPackage*)this)->GetPackType() == 0x17)
            reinterpret_cast<::fnv_00970810::Menu75x *>(&((*reinterpret_cast<::fnv_006708b0::S_00970810 *>(&::g_011e0e80))))->FUN_00970810((std::intptr_t)(this));
        m_uiRefCount--;
    }
    reinterpret_cast<::FUN_00674d70_shell *>((((TESPackage*)this)))->SetFlag800(false);
    reinterpret_cast<::FUN_00670a50_shell *>((((FUN_00670a50_shell*)this)))->DestroyPackage();
}
}  // namespace fnv_006708b0

namespace fnv_00675a50 {
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSTerrainManager;
struct BSPortalGraph;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct ImpactSwap;
struct NiColor;
struct NiPoint3;
struct LocationDescriptor;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
struct FUN_00675a50_shell : public TESPackage
{
    TESWorldSpace* FUN_00675a50(MobileObject*);
};

struct VActor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual TESWorldSpace* GetPackageWorld();
};
struct VLog
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void* GetAssignedPackage();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v12a();
    virtual void v12b();
    virtual void v12c();
    virtual void v12d();
    virtual void v12e();
    virtual void v12f();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v13a();
    virtual void v13b();
    virtual void v13c();
    virtual void v13d();
    virtual void v13e();
    virtual void v13f();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual TESObjectREFR* GetRef();
};

struct Script
{
    int GetText();
};
struct BoundHolder
{
};
struct LocationDescriptor
{
    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
};
struct DoorH
{
    void* GetParentWorldSpace();
};
struct ActorS
{
};
struct TES
{
};
struct FUN_0056ad30_shell
{
};
struct FUN_009316c0_shell
{
};

// @fnv 0x00675a50
TESWorldSpace* FUN_00675a50_shell::FUN_00675a50(MobileObject* apActor)
{
    TESWorldSpace* pretworld = 0;
    LocationDescriptor* ploc;
    ploc = ploc = (LocationDescriptor*)(std::uintptr_t)((Script*)this)->GetText();
    if (ploc && reinterpret_cast<::DurationData *>((((BoundHolder*)ploc)))->FUN_00678ca0() != 2)
    {
        switch (reinterpret_cast<::DurationData *>((((BoundHolder*)ploc)))->FUN_00678ca0())
        {
        case 1:
            if (ploc->GetLocationCellReference())
                pretworld = (TESWorldSpace*)((DoorH*)ploc->GetLocationCellReference())->GetParentWorldSpace();
            break;
        case 0:
            if (ploc->GetLocationReference())
                pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((ActorS*)ploc->GetLocationReference())))->FUN_00575d70()));
            else if (apActor)
                pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((ActorS*)apActor)))->FUN_00575d70()));
            break;
        case 6:
            if (apActor && reinterpret_cast<::FUN_00569b80_shell *>((apActor))->FUN_00569b80())
                pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((ActorS*)reinterpret_cast<::FUN_00569b80_shell *>((apActor))->FUN_00569b80())))->FUN_00575d70()));
            else if (apActor)
                pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((ActorS*)apActor)))->FUN_00575d70()));
            break;
        case 3:
            if (apActor)
                pretworld = ((VActor*)apActor)->GetPackageWorld();
            break;
        case 4:
        case 5:
            if (apActor && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apActor)))->GetBaseTexture())) &&
                ((VLog*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apActor)))->GetBaseTexture())))->GetAssignedPackage() == this)
            {
                TESObjectREFR* pref = ((VLog*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apActor)))->GetBaseTexture())))->GetRef();
                if (pref)
                    pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((ActorS*)pref)))->FUN_00575d70()));
                else
                    pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((ActorS*)apActor)))->FUN_00575d70()));
            }
            break;
        }
    }
    else if (apActor)
    {
        pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::FUN_0056ad30_shell *>((((FUN_0056ad30_shell*)apActor)))->FUN_0056ad30()));
        if (!pretworld)
        {
            reinterpret_cast<::MobileObject *>((((FUN_009316c0_shell*)apActor)))->ProcessAnimation();
            pretworld = ((::fnv_00675a50::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((ActorS*)apActor)))->FUN_00575d70()));
        }
    }
    return pretworld;
}
}  // namespace fnv_00675a50

namespace fnv_00676140 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct TESForm;
struct TESObjectCELL;
struct LocationDescriptor
{
    int GetLocType();
    void SetLocationType(int);
    void SetRadius(unsigned int);
    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
    TESForm* GetLocationObject();
    int GetSearchRadius();
    void SetLocRef(TESObjectREFR*);
    void SetLocCell(TESObjectCELL*);
    void SetLocObject(TESForm*);
    void SetLocObjectType(int);
    void Copy(LocationDescriptor*, bool);
    bool Compare(LocationDescriptor*);
    void Save(int);
    void InitItem(TESForm*);
    bool IsLocationGeneric();
    bool GetIsValidLocation(TESForm*);
    bool IsRadiusNonZero();
    TESObjectREFR* ResolveLocationReference(MobileObject*);
    bool IsRefAtLocationTrigger(MobileObject*, TESObjectREFR*, bool*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    unsigned int GetRadius();
    void* __vecDelDtor(unsigned int);
    char m_ucLocationType;
    char _pad_1[3];
    unsigned int m_pLocationData;
    int eObjType;
};
struct FUN_00676140_shell : public TESPackage
{
    TESObjectREFR* FUN_00676140(MobileObject*);
};

struct Script
{
    int GetText();
};
struct BoundHolder
{
};
struct VProc
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void* V27C();
    virtual void w160();
    virtual void w161();
    virtual void w162();
    virtual void w163();
    virtual void w164();
    virtual void w165();
    virtual void w166();
    virtual void w167();
    virtual void w168();
    virtual void w169();
    virtual void w170();
    virtual void w171();
    virtual void w172();
    virtual void w173();
    virtual void w174();
    virtual void w175();
    virtual void w176();
    virtual void w177();
    virtual void w178();
    virtual void w179();
    virtual void w180();
    virtual void w181();
    virtual void w182();
    virtual void w183();
    virtual void w184();
    virtual void w185();
    virtual void w186();
    virtual void w187();
    virtual void w188();
    virtual void w189();
    virtual void w190();
    virtual void w191();
    virtual void w192();
    virtual void w193();
    virtual void w194();
    virtual void w195();
    virtual void w196();
    virtual void w197();
    virtual void w198();
    virtual void w199();
    virtual void w200();
    virtual void w201();
    virtual void w202();
    virtual void w203();
    virtual void w204();
    virtual void w205();
    virtual void w206();
    virtual void w207();
    virtual void w208();
    virtual void w209();
    virtual void w210();
    virtual void w211();
    virtual void w212();
    virtual void w213();
    virtual void w214();
    virtual void w215();
    virtual void w216();
    virtual void w217();
    virtual void w218();
    virtual void w219();
    virtual void w220();
    virtual void w221();
    virtual void w222();
    virtual void w223();
    virtual void w224();
    virtual void w225();
    virtual void w226();
    virtual void w227();
    virtual void w228();
    virtual void w229();
    virtual void w230();
    virtual void w231();
    virtual void w232();
    virtual void w233();
    virtual void w234();
    virtual void w235();
    virtual void w236();
    virtual void w237();
    virtual void w238();
    virtual void w239();
    virtual void w240();
    virtual void w241();
    virtual void w242();
    virtual void w243();
    virtual void w244();
    virtual void w245();
    virtual void w246();
    virtual void w247();
    virtual void w248();
    virtual void w249();
    virtual void w250();
    virtual void w251();
    virtual void w252();
    virtual void w253();
    virtual void w254();
    virtual void w255();
    virtual void w256();
    virtual void w257();
    virtual void w258();
    virtual void w259();
    virtual void w260();
    virtual void w261();
    virtual void w262();
    virtual void w263();
    virtual void w264();
    virtual void w265();
    virtual void w266();
    virtual void w267();
    virtual void w268();
    virtual void w269();
    virtual void w270();
    virtual void w271();
    virtual void w272();
    virtual void w273();
    virtual void w274();
    virtual void w275();
    virtual void w276();
    virtual void w277();
    virtual void w278();
    virtual void w279();
    virtual void w280();
    virtual void w281();
    virtual void w282();
    virtual void w283();
    virtual void w284();
    virtual void w285();
    virtual void w286();
    virtual void w287();
    virtual void w288();
    virtual void w289();
    virtual void w290();
    virtual void w291();
    virtual void w292();
    virtual void w293();
    virtual void w294();
    virtual void w295();
    virtual void w296();
    virtual void w297();
    virtual void w298();
    virtual void w299();
    virtual void w300();
    virtual void w301();
    virtual void w302();
    virtual void w303();
    virtual void w304();
    virtual void w305();
    virtual void w306();
    virtual void w307();
    virtual void w308();
    virtual void w309();
    virtual void w310();
    virtual void w311();
    virtual void w312();
    virtual void w313();
    virtual void w314();
    virtual void w315();
    virtual void w316();
    virtual void w317();
    virtual void w318();
    virtual void w319();
    virtual void w320();
    virtual void w321();
    virtual void w322();
    virtual void w323();
    virtual void w324();
    virtual TESObjectREFR* V514();
};
struct TES
{
};

// @fnv 0x00676140
TESObjectREFR* FUN_00676140_shell::FUN_00676140(MobileObject* apActor)
{
    TESObjectREFR* pRef;
    LocationDescriptor* pLoc = (LocationDescriptor*)(std::uintptr_t)((Script*)this)->GetText();
    pRef = 0;
    if (pLoc && reinterpret_cast<::DurationData *>((((BoundHolder*)pLoc)))->FUN_00678ca0() != 2)
    {
        switch (reinterpret_cast<::DurationData *>((((BoundHolder*)pLoc)))->FUN_00678ca0())
        {
            break;
        case 0:
            if (pLoc->GetLocationReference())
                pRef = pLoc->GetLocationReference();
            break;
        case 6:
            if (apActor && reinterpret_cast<::FUN_00569b80_shell *>((((TESObjectREFR*)apActor)))->FUN_00569b80())
                pRef = reinterpret_cast<::FUN_00569b80_shell *>((((TESObjectREFR*)apActor)))->FUN_00569b80();
            break;
        case 3:
            if (apActor)
                pRef = (TESObjectREFR*)apActor;
            break;
        case 4:
        case 5:
            if (apActor && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apActor)))->GetBaseTexture())) &&
                ((VProc*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apActor)))->GetBaseTexture())))->V27C() == (void*)this)
            {
                TESObjectREFR* pref = ((VProc*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apActor)))->GetBaseTexture())))->V514();
                if (pref)
                    pRef = pref;
                else
                    pRef = (TESObjectREFR*)apActor;
            }
            break;
        }
    }
    else
    {
        if (apActor)
            pRef = (TESObjectREFR*)apActor;
    }
    return pRef;
}
}  // namespace fnv_00676140

namespace fnv_00674f30 {
struct DataHandler
{
};
struct FUN_00674f30_shell
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48(unsigned int);
    virtual void vfn_4c(unsigned int);
    void SetFlag10000(bool b);
};
// @fnv 0x00674f30
void FUN_00674f30_shell::SetFlag10000(bool abSet)
{
    if (abSet)
    {
        reinterpret_cast<TESPackage*>(this)->flags |= 0x10000;
        if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::fnv_00674f30::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))
            vfn_48(0x40000000);
    }
    else
    {
        reinterpret_cast<TESPackage*>(this)->flags &= 0xfffeffff;
        if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::fnv_00674f30::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))
            vfn_4c(0x40000000);
    }
}
}  // namespace fnv_00674f30

namespace fnv_0067a1b0 {
struct FUN_0067a1b0_shell : public TESPackage
{
    void FUN_0067a1b0(TESPackage*);
};

struct TESQuest;
struct TESRegion;
struct FUN_0067a380_shell
{
};
struct FUN_0067a3a0_shell
{
};
struct FUN_0067a850_shell
{
};
struct Dummy0067a870
{
};
struct FUN_0067a8d0_shell
{
};
struct FUN_0067a8f0_shell
{
};
struct FUN_0067a950_shell
{
};
struct FUN_0067a970_shell
{
};
struct Get0067a9d0_r1b0
{
};
struct FUN_0067a9f0_shell
{
};
struct FUN_0067aa50_shell
{
};
struct FUN_0067aa70_shell
{
};
struct FUN_0067aad0_shell
{
};
struct FUN_0067aaf0_Holder
{
};
struct FUN_0067ab50_shell
{
};
struct FUN_0067ab70_shell
{
};
struct Get0067abd0_r1b0
{
};
struct FUN_0067abf0_shell
{
};
struct FUN_0067ac50_shell
{
};
struct FUN_0067ac70_shell
{
};
struct FUN_0067a460_shell
{
};
struct FUN_00671a20_shell
{
};
struct FUN_0067a690_shell
{
};
struct FUN_0067a6b0_shell
{
};
struct FUN_00441b00_shell
{
};
struct FUN_0067a640_shell
{
};
struct FUN_0067a480_shell
{
};
struct Struct_067A4A0
{
};
struct FUN_0067a4f0_shell
{
};
struct FUN_0067a510_shell
{
};
struct FUN_0067a770_shell
{
};
struct Fake067a790
{
};
struct TESTopicInfo
{
    TESQuest* GetParentQuest();
};
struct BGSAcousticSpace
{
};
struct FUN_0067a700_shell
{
};
struct FUN_0067a720_shell
{
};
struct FUN_0067a3f0_shell
{
};
struct FUN_0067a410_shell
{
};
struct FUN_0067a5d0_class
{
};
struct FUN_0067a5f0_shell
{
};
struct FUN_0067a580_shell
{
};
struct FUN_0067a7e0_shell
{
};
struct FUN_0067a800_shell
{
};

// @fnv 0x0067a1b0
void FUN_0067a1b0_shell::FUN_0067a1b0(TESPackage* apCopy)
{
    reinterpret_cast<::FUN_0067a3a0_shell *>((((FUN_0067a3a0_shell*)this)))->FUN_0067a3a0(reinterpret_cast<::FUN_0067a380_shell *>((((FUN_0067a380_shell*)apCopy)))->FUN_0067a380());
    reinterpret_cast<::Dummy0067a870 *>((((Dummy0067a870*)this)))->SetFlag(reinterpret_cast<::FUN_0067a850_shell *>((((FUN_0067a850_shell*)apCopy)))->FUN_0067a850());
    reinterpret_cast<::FUN_0067a8f0_shell *>((((FUN_0067a8f0_shell*)this)))->SetFlag2(reinterpret_cast<::FUN_0067a8d0_shell *>((((FUN_0067a8d0_shell*)apCopy)))->FUN_0067a8d0());
    reinterpret_cast<::FUN_0067a970_shell *>((((FUN_0067a970_shell*)this)))->SetFlag4(reinterpret_cast<::FUN_0067a950_shell *>((((FUN_0067a950_shell*)apCopy)))->FUN_0067a950());
    reinterpret_cast<::FUN_0067a9f0_shell *>((((FUN_0067a9f0_shell*)this)))->SetFlag8(::FUN_0067a9d0((void *)(((Get0067a9d0_r1b0*)apCopy))));
    reinterpret_cast<::FUN_0067aa70_shell *>((((FUN_0067aa70_shell*)this)))->FUN_0067aa70(reinterpret_cast<::FUN_0067aa50_shell *>((((FUN_0067aa50_shell*)apCopy)))->FUN_0067aa50());
    reinterpret_cast<::FUN_0067aaf0_Holder *>((((FUN_0067aaf0_Holder*)this)))->FUN_0067aaf0(reinterpret_cast<::FUN_0067aad0_shell *>((((FUN_0067aad0_shell*)apCopy)))->FUN_0067aad0());
    reinterpret_cast<::FUN_0067ab70_shell *>((((FUN_0067ab70_shell*)this)))->FUN_0067ab70(reinterpret_cast<::FUN_0067ab50_shell *>((((FUN_0067ab50_shell*)apCopy)))->HasFlag40());
    reinterpret_cast<::FUN_0067abf0_shell *>((((FUN_0067abf0_shell*)this)))->FUN_0067abf0(((bool)(::IsPackageFlag80Set((::TESPackage *)(((Get0067abd0_r1b0*)apCopy))))));
    reinterpret_cast<::FUN_0067ac70_Class *>((((FUN_0067ac70_shell*)this)))->SetFlag100(reinterpret_cast<::FUN_0067ac50_shell *>((((FUN_0067ac50_shell*)apCopy)))->FUN_0067ac50());
    reinterpret_cast<::FUN_00671a20_shell *>((((FUN_00671a20_shell*)this)))->FUN_00671a20(reinterpret_cast<::FUN_0067a460_shell *>((((FUN_0067a460_shell*)apCopy)))->FUN_0067a460());
    reinterpret_cast<::FUN_0067a6b0_shell *>((((FUN_0067a6b0_shell*)this)))->SetFlag100000(reinterpret_cast<::FUN_0067a690_shell *>((((FUN_0067a690_shell*)apCopy)))->HasFlag100000());
    reinterpret_cast<::FUN_0067a640_shell *>((((FUN_0067a640_shell*)this)))->SetFlag200000(reinterpret_cast<::TESPackage *>((void *)(((FUN_00441b00_shell*)apCopy)))->GetForceUnequipWeapon());
    reinterpret_cast<::Struct_067A4A0 *>((((Struct_067A4A0*)this)))->FUN_0067a4a0(reinterpret_cast<::FUN_0067a480_shell *>((((FUN_0067a480_shell*)apCopy)))->FUN_0067a480());
    reinterpret_cast<::FUN_0067a510_shell *>((((FUN_0067a510_shell*)this)))->SetFlag20000(reinterpret_cast<::FUN_0067a4f0_shell *>((((FUN_0067a4f0_shell*)apCopy)))->FUN_0067a4f0());
    reinterpret_cast<::Fake067a790 *>((((Fake067a790*)this)))->FUN_0067a790(reinterpret_cast<::FUN_0067a770_shell *>((((FUN_0067a770_shell*)apCopy)))->IsNotFlag8000000());
    reinterpret_cast<::TESPackage *>(this)->pCombatStyle = (TESCombatStyle*)((TESTopicInfo*)apCopy)->GetParentQuest();
    reinterpret_cast<::FUN_0067a720_shell *>((((FUN_0067a720_shell*)this)))->SetFlag4000000(reinterpret_cast<::FUN_0067a700_shell *>((((FUN_0067a700_shell*)apCopy)))->FUN_0067a700());
    reinterpret_cast<::FUN_0067a410_shell *>((((FUN_0067a410_shell*)this)))->SetFlag400000(reinterpret_cast<::FUN_0067a3f0_shell *>((((FUN_0067a3f0_shell*)apCopy)))->HasFlag400000());
    reinterpret_cast<::FUN_0067a5f0_shell *>((((FUN_0067a5f0_shell*)this)))->SetFlag80000(reinterpret_cast<::FUN_0067a5d0_class *>((((FUN_0067a5d0_class*)apCopy)))->FUN_0067a5d0());
    reinterpret_cast<::FUN_0067a580_shell *>((((FUN_0067a580_shell*)this)))->SetFlag40000(::FUN_0067a560((std::intptr_t)apCopy));
    reinterpret_cast<::fnv_0067a800::S *>((((FUN_0067a800_shell*)this)))->FUN_0067a800(reinterpret_cast<::FUN_0067a7e0_shell *>((((FUN_0067a7e0_shell*)apCopy)))->IsFlag28Clear());
}
}  // namespace fnv_0067a1b0

struct ExtraFollower;
struct ShellH;
struct FUN_00422700_shell
{
    ExtraFollower* FUN_00422700();
};
struct XActor
{
};
struct _ref_006815c0
{
};
struct ExtraFollowerView
{
    char pad[0xc];
    _ref_006815c0* pFollowers;
};
struct FUN_00962720_shell
{
    bool HasExtraFollowerForm(char* apForm);
};
// Checks whether the player's extra follower list contains the given form pointer, walking the linked list and returning true on a match.
// @fnv 0x00962720
bool FUN_00962720_shell::HasExtraFollowerForm(char* apForm)
{
    ExtraFollower* pkFollower = ((FUN_00422700_shell*)((::ShellH *)(reinterpret_cast<::FUN_005d43c0_ *>(((*reinterpret_cast<::XActor * *>(&::_g_thePlayer))))->FUN_005d43c0())))->FUN_00422700();
    if (pkFollower && reinterpret_cast<ExtraFollowerView*>(pkFollower)->pFollowers)
    {
        _ref_006815c0* pkNode = reinterpret_cast<ExtraFollowerView*>(pkFollower)->pFollowers;
        while (pkNode && *((char **)((void *)(pkNode))))
        {
            char* pkEntry = *((char **)((void *)(pkNode)));
            if (pkEntry == apForm)
                return true;
            pkNode = (_ref_006815c0*)((char *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        }
    }
    return false;
}

namespace fnv_006730a0 {
struct FUN_00670b60
{
    virtual void First();
    virtual void Second();
    virtual void Call(void* value);

    ~FUN_00670b60();
};

FUN_00670b60::~FUN_00670b60()
{}

void FUN_00670b60::First()
{}

void FUN_00670b60::Second()
{}

void FUN_00670b60::Call(void* value)
{
    (void)value;
}

struct FUN_00479790 : public FUN_00670b60
{
    int m_data[3];

    FUN_00479790();
};

FUN_00479790::FUN_00479790()
{}

struct FUN_006730a0_shell
{
    unsigned char m_auiShapeKeys[0x34];
    FUN_00670b60* m_object;

    void CallOrResetObject(void* value);
};

// If value is non-null, lazily creates m_object and calls its Call method with value; otherwise deletes m_object and sets it to null.
// @fnv 0x006730a0
void FUN_006730a0_shell::CallOrResetObject(void* value)
{
    if (value)
    {
        if (!m_object)
            m_object = new FUN_00479790();

        m_object->Call(value);
    }
    else
    {
        delete m_object;
        m_object = 0;
    }
}
}  // namespace fnv_006730a0

namespace fnv_00673200 {
struct PerkEntryConditionSet
{
    virtual ~PerkEntryConditionSet();
};

struct CondS : public PerkEntryConditionSet
{
    int value;

    CondS();
};

struct BGSIdleCollection
{
};

struct FUN_00680a70_shell
{
};

struct FUN_00673200_shell
{
    unsigned char padding[0x40];
    FUN_00680a70_shell member;

    void FUN_00673200(BGSIdleCollection*);
};

// If apIdles is non-null, passes it to CopyConditions with null; otherwise passes a default-constructed CondS and null.
// @fnv 0x00673200
void FUN_00673200_shell::FUN_00673200(BGSIdleCollection* apIdles)
{
    if (apIdles)
    {
        reinterpret_cast<::FUN_00680a70_shell *>(&(member))->CopyConditions((::PerkEntryConditionSet *)(::fnv_00673200::PerkEntryConditionSet *)(reinterpret_cast<PerkEntryConditionSet*>(apIdles)), (::PerkEntryConditionSet *)(::fnv_00673200::PerkEntryConditionSet *)(0));
    }
    else
    {
        CondS condition;
        reinterpret_cast<::FUN_00680a70_shell *>(&(member))->CopyConditions((::PerkEntryConditionSet *)(::fnv_00673200::PerkEntryConditionSet *)(&condition), (::PerkEntryConditionSet *)(::fnv_00673200::PerkEntryConditionSet *)(0));
    }
}
}  // namespace fnv_00673200

namespace fnv_006738b0 {
class Script
{
  public:
    int GetText();
};

class LocationDescriptor
{
  public:
    void Save(int);
};

class TESQuest
{
  public:
    int _ref_0084e3a0()
    {
        return 0;
    }
};

class FUN_004799f0_shell
{
  public:
};

class FUN_006802f0_shell
{
  public:
};

class FUN_0067fec0_shell
{
  public:
    void Save();
};

class FUN_0067dc80
{
  public:
    void Save(int);
};

class FUN_004855a0
{
  public:
};

class FUN_00485680
{
  public:
};

class S
{
  public:
};

class FUN_00672dd0_shell
{
  public:
};

class CP_008c48d0
{
  public:
};

class TESTopicInfo
{
  public:
    TESQuest* GetParentQuest();
};

class PackedByteIntRecord
{
  public:
};

class TESConditionSave
{
  public:
};

class EnchantmentItem
{
};

template <class T> class BSSimpleList
{
};

class TESDataHandler
{
  public:
};

class PACKAGE_PROCEDURE_TYPE
{
  public:
    virtual void FUN_1()
    {}
    virtual void FUN_2()
    {}
    virtual void FUN_3()
    {}
    virtual void FUN_4()
    {}
};


struct PackageEventActionData
{
    unsigned char data[0x10];
};
struct FUN_006738b0_shell : public ::TESPackage
{
    PackageEventActionData kOnBegin;
    PackageEventActionData kOnEnd;
    PackageEventActionData kOnChange;

    void FUN_006738b0();
};

// Calls M, then saves the package data block, the begin, end and change event actions and the script, package, condition and topic data under their chunk tags.
// @fnv 0x006738b0
void FUN_006738b0_shell::FUN_006738b0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::S *>(&flags)->FUN_00670760();

    ::AppendChunk(0x54444B50, reinterpret_cast<void*>(&flags), 0x0C);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::S *>(&flags)->FUN_00670760();

    if (reinterpret_cast<Script*>(this)->GetText())
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((reinterpret_cast<LocationDescriptor*>(reinterpret_cast<Script*>(this)->GetText())))->FUN_0067f6c0(0x54444C50);

    if (((::fnv_006738b0::LocationDescriptor *)(reinterpret_cast<::FUN_00672dd0_shell *>((reinterpret_cast<FUN_00672dd0_shell*>(this)))->FUN_00672dd0())))
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((((::fnv_006738b0::LocationDescriptor *)(reinterpret_cast<::FUN_00672dd0_shell *>((reinterpret_cast<FUN_00672dd0_shell*>(this)))->FUN_00672dd0()))))->FUN_0067f6c0(0x32444C50);

    if (((::fnv_006738b0::BSSimpleList< ::fnv_006738b0::EnchantmentItem *> *)(reinterpret_cast<::FUN_0041d8a0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->FUN_0041d8a0())))
        reinterpret_cast<::FUN_0067fec0_shell *>((reinterpret_cast<FUN_0067fec0_shell*>(((::fnv_006738b0::BSSimpleList< ::fnv_006738b0::EnchantmentItem *> *)(reinterpret_cast<::FUN_0041d8a0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->FUN_0041d8a0())))))->Save();

    if (((::PackageTargetRecord *)(reinterpret_cast<::Script *>((reinterpret_cast<TESPackage*>(this)))->GetData())))
        reinterpret_cast<::FUN_006802f0_shell *>((reinterpret_cast<FUN_006802f0_shell*>(((::PackageTargetRecord *)(reinterpret_cast<::Script *>((reinterpret_cast<TESPackage*>(this)))->GetData())))))->FUN_006802f0(0x54445450);

    if (((char *)(reinterpret_cast<::PackedByteIntRecord *>((reinterpret_cast<PackedByteIntRecord*>(this)))->Endian())))
        reinterpret_cast<::FUN_00680910_shell *>((reinterpret_cast<TESConditionSave*>(((char *)(reinterpret_cast<::PackedByteIntRecord *>((reinterpret_cast<PackedByteIntRecord*>(this)))->Endian())))))->ProcessItems();

    if (((int)(std::intptr_t)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath())))
        reinterpret_cast<::FUN_004799f0_shell *>((reinterpret_cast<FUN_004799f0_shell*>(((std::intptr_t)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath())))))->FUN_004799f0();

    if (reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest())
        ::FUN_00485910(0x4D414E43, reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest()))->FUN_0084e3a0());

    if (data)
        reinterpret_cast<PACKAGE_PROCEDURE_TYPE*>(data)->FUN_4();

    reinterpret_cast<::FUN_0067dc80 *>(reinterpret_cast<FUN_0067dc80*>(&kOnBegin))->Save(0x41424F50);
    reinterpret_cast<::FUN_0067dc80 *>(reinterpret_cast<FUN_0067dc80*>(&kOnEnd))->Save(0x41454F50);
    reinterpret_cast<::FUN_0067dc80 *>(reinterpret_cast<FUN_0067dc80*>(&kOnChange))->Save(0x41434F50);

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}
}  // namespace fnv_006738b0

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};


struct TESSaveLoadGame
{
};

struct SaveManager : public TESSaveLoadGame
{
};


struct FUN_0067f990_object
{
};

struct FUN_00680520_object
{
};

struct HitSoundData
{
    unsigned int id;
    unsigned char padding[5];
};

struct FormBase
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
    virtual const char* GetName() = 0;
};

struct TESFormStandIn : public FormBase
{
};


struct Interface
{
};

extern char str_010685dc[];
extern char $SG7035[];
extern char $SG7038[];

struct FUN_00678fd0_shell
{
    unsigned char padding[0x2c];
    void* pObject2c;
    void* pObject30;

    unsigned short FUN_00678fd0();
};

// @fnv 0x00678fd0
unsigned short FUN_00678fd0_shell::FUN_00678fd0()
{
    unsigned short size = 0;
    {
        unsigned short start = size;

        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            size += 4;
            size += 2;
        }

        size += 0x0c;
        size += 1;

        if (pObject2c)
        {
            size += reinterpret_cast<::FUN_0067f990_C *>((reinterpret_cast<FUN_0067f990_object*>(pObject2c)))->FUN_0067f990();
        }

        if (pObject30)
        {
            size += reinterpret_cast<::FUN_00680520_cls *>((reinterpret_cast<FUN_00680520_object*>(pObject30)))->FUN_00680520();
        }

        size += 4;

        if (*::g_011de4e8.Bool())
        {
            HitSoundData* hitSound;
            {
                hitSound = reinterpret_cast<HitSoundData*>(((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->GetHitSound())));
                if (hitSound)
                {
                    TESFormStandIn* form;
                    {
                        form = ((::TESFormStandIn *)(::FUN_004839c0(hitSound->id)));
                        ::FUN_0040fbe0(
                            );
                    }
                }
                else
                {
                    ::FUN_0040fbe0();
                }
            }
        }
    }
    return size;
}

namespace fnv_00679b10 {
struct FormChangeMask
{
    unsigned int value;
    FormChangeMask(const FormChangeMask&);
    operator bool() const;
};

struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int);
};

class DataHandler
{
  public:
};

typedef DataHandler DH;

struct FUN_00679b10_shell
{
    unsigned char padding[0x1c];
    unsigned int flags;

    void FUN_00679b10(BGSLoadFormBuffer* buffer);
};

// @fnv 0x00679b10
void FUN_00679b10_shell::FUN_00679b10(BGSLoadFormBuffer* buffer)
{
    if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::fnv_00679b10::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))
    {
        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00679b10::FormChangeMask &)(buffer->GetOldChangeFlags(0x80000000)))->FUN_004280f0(0x80000000))
        {
            flags &= 0xffff7fff;
        }

        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00679b10::FormChangeMask &)(buffer->GetOldChangeFlags(0x40000000)))->FUN_004280f0(0x40000000))
        {
            flags &= 0xfffeffff;
        }
    }
}
}  // namespace fnv_00679b10

struct PackageEx : public TESPackage
{
    void SetPackageType(int);
};

struct PackageType15 : public PackageEx
{
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    PackageType15();
};

struct PackageType18 : public PackageEx
{
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    PackageType18(int, int, int);
};

struct PackageType21 : public PackageEx
{
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
    PackageType21();
};

struct PackageType22 : public PackageEx
{
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
    int unkA8;
    PackageType22(int, int, int);
};

struct PackageType23 : public PackageEx
{
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
    PackageType23();
};

struct PackageType24 : public PackageEx
{
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
    int unkA8;
    int unkAC;
    int unkB0;
    PackageType24();
};

struct PackageType39 : public PackageEx
{
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
    PackageType39();
};

struct PackageDefault : public PackageEx
{
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
    PackageDefault();
};

// Allocates a package object matching the given type via a switch, initializes it with the type, and returns it.
// @fnv 0x00670b90
TESPackage* CreatePackageByType(int type)
{
    PackageEx* package = 0;
    switch (type)
    {
    case 15:
    case 28:
        package = new PackageType15();
        break;
    case 18:
        package = new PackageType18(0, 0, 0);
        break;
    case 21:
        package = new PackageType21();
        break;
    case 22:
        package = new PackageType22(0, 0, 0);
        break;
    case 23:
        package = new PackageType23();
        break;
    case 24:
        package = new PackageType24();
        break;
    case -1:
    case 40:
        break;
    case 17:
        type = 0;
        break;
    case 9:
        type = 9;
        break;
    case 39:
        package = new PackageType39();
        break;
    default:
        package = new PackageDefault();
        break;
    }
    if (package)
        package->SetPackageType(type);
    return package;
}

struct FUN_006757e0_shell : TESPackage
{
    int FUN_0055b980();
    int FUN_00675c20(MobileObject* actor);
    int FUN_006757e0(MobileObject* actor);
};

struct PackValue12
{
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
struct FUN_00675830_shell : TESPackage
{
    int FUN_0055b980();
    PackValue12* FUN_00675de0(PackValue12* destination, void* actor);
    PackValue12* FUN_00675360(PackValue12* destination, void* actor);
    PackValue12* FUN_00675830(PackValue12* output, void* actor);
};
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    static const ::NiPoint3 ZERO;
};
class TESWorldSpace;
struct TESObjectCELL
{
    bool IsInterior();
public:
    bool IsCellInterior() const;
public:
    int GetCellGridX();
public:
    int GetCellGridY();
public:
    ::TESWorldSpace *GetParentWorldSpace();
};
struct TESWorldSpace;
struct Reference
{
    virtual void virtual_0();
    virtual void virtual_1();
    virtual void virtual_2();
    virtual void virtual_3();
    virtual void virtual_4();
    virtual void virtual_5();
    virtual void virtual_6();
    virtual void virtual_7();
    virtual void virtual_8();
    virtual void virtual_9();
    virtual void virtual_10();
    virtual void virtual_11();
    virtual void virtual_12();
    virtual void virtual_13();
    virtual void virtual_14();
    virtual void virtual_15();
    virtual void virtual_16();
    virtual void virtual_17();
    virtual void virtual_18();
    virtual void virtual_19();
    virtual void virtual_20();
    virtual void virtual_21();
    virtual void virtual_22();
    virtual void virtual_23();
    virtual void virtual_24();
    virtual void virtual_25();
    virtual void virtual_26();
    virtual void virtual_27();
    virtual void virtual_28();
    virtual void virtual_29();
    virtual void virtual_30();
    virtual void virtual_31();
    virtual void virtual_32();
    virtual void virtual_33();
    virtual void virtual_34();
    virtual void virtual_35();
    virtual void virtual_36();
    virtual void virtual_37();
    virtual void virtual_38();
    virtual void virtual_39();
    virtual void virtual_40();
    virtual void virtual_41();
    virtual void virtual_42();
    virtual void virtual_43();
    virtual void virtual_44();
    virtual void virtual_45();
    virtual void virtual_46();
    virtual void virtual_47();
    virtual void virtual_48();
    virtual void virtual_49();
    virtual void virtual_50();
    virtual void virtual_51();
    virtual void virtual_52();
    virtual void virtual_53();
    virtual void virtual_54();
    virtual void virtual_55();
    virtual void virtual_56();
    virtual void virtual_57();
    virtual void virtual_58();
    virtual void virtual_59();
    virtual void virtual_60();
    virtual void virtual_61();
    virtual void virtual_62();
    virtual void virtual_63();
    virtual void virtual_64();
    virtual void virtual_65();
    virtual void virtual_66();
    virtual void virtual_67();
    virtual void virtual_68();
    virtual void virtual_69();
    virtual void virtual_70();
    virtual void virtual_71();
    virtual void virtual_72();
    virtual void virtual_73();
    virtual void virtual_74();
    virtual void virtual_75();
    virtual void virtual_76();
    virtual void virtual_77();
    virtual void virtual_78();
    virtual void virtual_79();
    virtual void virtual_80();
    virtual void virtual_81();
    virtual void virtual_82();
    virtual void virtual_83();
    virtual void virtual_84();
    virtual void virtual_85();
    virtual void virtual_86();
    virtual void virtual_87();
    virtual void virtual_88();
    virtual void virtual_89();
    virtual void virtual_90();
    virtual void virtual_91();
    virtual void virtual_92();
    virtual void virtual_93();
    virtual void virtual_94();
    virtual void virtual_95();
    virtual void virtual_96();
    virtual void virtual_97();
    virtual void virtual_98();
    virtual void virtual_99();
    virtual void virtual_100();
    virtual void virtual_101();
    virtual void virtual_102();
    virtual void virtual_103();
    virtual void virtual_104();
    virtual void virtual_105();
    virtual void virtual_106();
    virtual void virtual_107();
    virtual void virtual_108();
    virtual void virtual_109();
    virtual void virtual_110();
    virtual void virtual_111();
    virtual void virtual_112();
    virtual void virtual_113();
    virtual void virtual_114();
    virtual void virtual_115();
    virtual void virtual_116();
    virtual void virtual_117();
    virtual void virtual_118();
    virtual void virtual_119();
    virtual void virtual_120();
    virtual void virtual_121();
    virtual void virtual_122();
    virtual void virtual_123();
    virtual void virtual_124();
    virtual const NiPoint3& GetPosition();
    virtual void virtual_126();
    virtual void virtual_127();
    virtual void virtual_128();
    virtual void virtual_129();
    virtual void virtual_130();
    virtual void virtual_131();
    virtual void virtual_132();
    virtual void virtual_133();
    virtual void virtual_134();
    virtual void virtual_135();
    virtual void virtual_136();
    virtual void virtual_137();
    virtual void virtual_138();
    virtual void virtual_139();
    virtual void virtual_140();
    virtual void virtual_141();
    virtual void virtual_142();
    virtual void virtual_143();
    virtual void virtual_144();
    virtual void virtual_145();
    virtual void virtual_146();
    virtual void virtual_147();
    virtual void virtual_148();
    virtual void virtual_149();
    virtual void virtual_150();
    virtual void virtual_151();
    virtual void virtual_152();
    virtual void virtual_153();
    virtual void virtual_154();
    virtual void virtual_155();
    virtual void virtual_156();
    virtual void virtual_157();
    virtual void virtual_158();
    virtual void virtual_159();
    virtual void virtual_160();
    virtual void virtual_161();
    virtual void virtual_162();
    virtual void virtual_163();
    virtual void virtual_164();
    virtual void virtual_165();
    virtual void virtual_166();
    virtual void virtual_167();
    virtual void virtual_168();
    virtual void virtual_169();
    virtual void virtual_170();
    virtual void virtual_171();
    virtual void virtual_172();
    virtual void virtual_173();
    virtual void virtual_174();
    virtual void virtual_175();
    virtual void virtual_176();
    virtual void virtual_177();
    virtual Reference* GetPackageTarget();
};
struct Actor : Reference
{
};
struct Location
{
};
struct Setting
{
};
struct Package
{
    TESObjectCELL* FUN_00675c20(Actor*);
    Location* FUN_0055b980();
    NiPoint3 FUN_00675de0(Actor*);
    bool IsTargetWithinRadius(Actor*, int);
};
// @fnv 0x006773a0
bool Package::IsTargetWithinRadius(Actor* actor, int extra)
{
    if (!actor || !actor->GetPackageTarget())
        return false;
    Reference* target2 = actor->GetPackageTarget();
    TESWorldSpace* targetWorld = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((target2))->FUN_00575d70()));
    TESObjectCELL* targetCell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((target2))->GetTarget()));
    if (targetCell && !targetCell->IsCellInterior())
        targetCell = 0;
    TESWorldSpace* world7 = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00675a50::FUN_00675a50_shell *>(this)->FUN_00675a50((::MobileObject *)(actor))));
    TESObjectCELL* kCell = FUN_00675c20(actor);
    if (kCell && !kCell->IsCellInterior())
        kCell = 0;
    bool same3 = false;
    if (kCell || targetCell)
    {
        if (kCell == targetCell)
            same3 = true;
    }
    else
    {
        if (world7 == targetWorld)
            same3 = true;
    }
    if (!same3)
        return false;
    Location* location4 = FUN_0055b980();
    bool answer8 = false;
    if (location4 && reinterpret_cast<::FUN_0067f220_cls *>((location4))->LookupAndStore((std::intptr_t)(actor), (std::intptr_t)(target2), (unsigned char *)&(answer8)))
        return answer8;
    int radius = ((int)(reinterpret_cast<::HighProcess *>(this)->UpdateHighProcessState(actor)));
    if (radius == 0 && location4)
    {
        Reference* reference2 = ((::Reference *)(reinterpret_cast<::fnv_00676140::FUN_00676140_shell *>(this)->FUN_00676140((::MobileObject *)(actor))));
        if (reference2)
            radius = (int)reinterpret_cast<::TESObjectREFR *>((reference2))->GetBoundingRadius();
    }
    if (radius == 0 || radius < 0)
        radius = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011cde98))))));
    radius += extra;
    bool result4 = false;
    NiPoint3 delta7 = FUN_00675de0(actor) - target2->GetPosition();
    if ((int)reinterpret_cast<::FUN_00589850_Class *>((void *)&(delta7))->FUN_00589850() <= radius)
        result4 = true;
    return result4;
}

namespace fnv_00677570 {
struct TESWorldSpace;
struct CellStandIn
{
    bool IsInterior();
};
struct Point3
{
    float x;
    float y;
    float z;
    Point3 operator-(const Point3& other) const;
};
struct RefStandIn
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Point3* GetPos();
};
struct ActorStandIn
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual RefStandIn* GetPackageTargetRef();
};
struct LocStandIn
{
};
struct RadiusSource
{
    float GetRadius();
};
struct IntSetting
{
};

struct FUN_00677570_shell : public TESPackage
{
    CellStandIn* GetActorCell(ActorStandIn*);
    LocStandIn* GetLocation();
    RadiusSource* GetRadiusSource(ActorStandIn*);
    Point3 GetLocationPos(ActorStandIn*);
    bool IsTargetInRange(ActorStandIn* actor, float radius);
};

// @fnv 0x00677570
bool FUN_00677570_shell::IsTargetInRange(ActorStandIn* actor, float radius)
{
    RefStandIn* target = actor->GetPackageTargetRef();
    if (!actor || !target)
        return false;
    TESWorldSpace* kTargetWorld = ((::fnv_00677570::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((target))->FUN_00575d70()));
    CellStandIn* targetCell = ((::fnv_00677570::CellStandIn *)(reinterpret_cast<::LowProcess *>((target))->GetTarget()));
    if (targetCell && !reinterpret_cast<::TESObjectCELL *>((targetCell))->IsCellInterior())
        targetCell = 0;
    TESWorldSpace* actorWorld8 = ((::fnv_00677570::TESWorldSpace *)(reinterpret_cast<::fnv_00675a50::FUN_00675a50_shell *>(this)->FUN_00675a50((::MobileObject *)(actor))));
    CellStandIn* actorCell3 = GetActorCell(actor);
    if (actorCell3 && !reinterpret_cast<::TESObjectCELL *>((actorCell3))->IsCellInterior())
        actorCell3 = 0;
    bool sameSpace = false;
    if (actorCell3 || targetCell)
    {
        if (actorCell3 == targetCell)
            sameSpace = true;
    }
    else if (actorWorld8 == kTargetWorld)
    {
        sameSpace = true;
    }
    if (!sameSpace)
        return false;
    LocStandIn* location4 = ((::fnv_00677570::LocStandIn *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
    bool inRange2 = false;
    if (location4 && reinterpret_cast<::FUN_0067f220_cls *>((location4))->LookupAndStore((std::intptr_t)(actor), (std::intptr_t)(target), (unsigned char *)&(inRange2)))
        return inRange2;
    if (radius < 0.0)
    {
        int packRadius2 = ((int)(reinterpret_cast<::fnv_00675670::FUN_00675670_shell *>(this)->FUN_00675670()));
        int unusedRadius5;
        if (!packRadius2)
            unusedRadius5 = ((int)(reinterpret_cast<::fnv_00675670::FUN_00675670_shell *>(this)->FUN_00675670()));
        if (!packRadius2 && location4)
        {
            RadiusSource* source = GetRadiusSource(actor);
            if (source)
                packRadius2 = (int)reinterpret_cast<::TESObjectREFR *>((source))->GetBoundingRadius();
        }
        if (!packRadius2 || packRadius2 < 0)
            packRadius2 = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00677570::IntSetting *>(&::g_011cde98))))));
        radius = (float)packRadius2;
    }
    bool result4 = false;
    Point3 delta9 = GetLocationPos(actor) - *target->GetPos();
    if (radius >= (int)reinterpret_cast<::FUN_00589850_Class *>((void *)&(delta9))->FUN_00589850())
        result4 = true;
    return result4;
}
}  // namespace fnv_00677570

// FUN_0067b170 : thiscall; calls the base initialiser, stores the class
// vtable pointer, sets a float and several zero-initialised members, returns this.


struct FUN_0067b170_cls
{
    void* m_pVTable;
    float m_fValue04;
    int m_iValue08;
    int m_iValue0c;
    unsigned char m_bValue10;
    unsigned char m_bValue11;
    unsigned char pad12[2];
    float m_fValue14;
    unsigned char m_bValue18;
    unsigned char pad19[3];
    int m_iValue1c;

    FUN_0067b170_cls* FUN_0067b170();
};

// Calls FUN_0067ad20, sets the vtable and m_fValue04 from globals, and zeroes the remaining fields before returning this.
// @fnv 0x0067b170
FUN_0067b170_cls* FUN_0067b170_cls::FUN_0067b170()
{
    new ((void *)this) ::FUN_0067ad20_Class();
    m_pVTable = (void*)&(*reinterpret_cast<int *>(&::UNK_010688ac));
    m_fValue04 = DAT_01016410;
    m_iValue08 = 0;
    m_iValue0c = 0;
    m_bValue10 = 0;
    m_bValue11 = 0;
    m_bValue18 = 0;
    m_iValue1c = 0;
    m_fValue14 = 0.0f;
    return this;
}

struct FUN_0067f030
{
    int kind;
    int object;
    int radius;
    FUN_0067f030();
};
struct FUN_0067bbf0
{
    int kind;
    int value;
    int count;
    FUN_0067bbf0();
};
struct FUN_0067b170
{
    int vtable;
    float value;
    int mode;
    int object;
    int state;
    float radius;
    int flags;
    int count;
    FUN_0067b170();
};
struct FUN_0067bfd0
{
    int vtable;
    int value;
    int flags;
    FUN_0067bfd0();
};
struct FUN_0067caa0
{
    int vtable;
    int value;
    int object;
    int kind;
    int flags;
    int count;
    int state;
    int amount;
    int limit;
    FUN_0067caa0();
};
struct FUN_0067c3f0_Class
{
    int vtable;
    int value;
    FUN_0067c3f0_Class();
};
struct PackageDataDeletion
{
    virtual ~PackageDataDeletion();
};
struct PackageResetOps
{
    void* FUN_0055b980();
};
struct TargetResetOps
{
};
// @fnv 0x00670fc0
void PackageEx::SetPackageType(int newType)
{
    if (newType == 17)
        newType = 0;
    if (newType != (signed char)type)
    {
        if (data)
            delete reinterpret_cast<PackageDataDeletion*>(data);
        data = 0;
        switch (newType)
        {
        case 4:
        case 5:
        case 6:
        case 13:
            reinterpret_cast<::FUN_00672fc0_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00672fc0((::PackageTargetRecord *)(void *)(0));
            break;
        case 12:
            reinterpret_cast<::FUN_00672fc0_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00672fc0((::PackageTargetRecord *)(void *)(0));
            reinterpret_cast<::fnv_00671e10::FUN_00671e10_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671e10((::fnv_00671e10::LocationDescriptor *)(void *)(0));
            break;
        case 0:
        case 1:
        case 2:
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
        case 16:
            reinterpret_cast<::fnv_00671e10::FUN_00671e10_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671e10((::fnv_00671e10::LocationDescriptor *)(void *)(0));
            break;
        case 7:
            reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(void *)(0));
            break;
        }
        switch (newType)
        {
        case 9:
            if (!reinterpret_cast<PackageResetOps*>(this)->FUN_0055b980())
                pPackageLocation = reinterpret_cast<::LocationDescriptor*>(new FUN_0067f030);
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067acf0);
            break;
        case 2:
            if (!((void *)(reinterpret_cast<::Script *>((reinterpret_cast<PackageResetOps*>(this)))->GetData())))
                pPackageTarget = reinterpret_cast<::PackageTargetRecord*>(new PackageTargetObj);
            if (!reinterpret_cast<PackageResetOps*>(this)->FUN_0055b980())
                pPackageLocation = reinterpret_cast<::LocationDescriptor*>(new FUN_0067f030);
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067bbf0);
            break;
        case 15:
        case 28:
            if (!((void *)(reinterpret_cast<::Script *>((reinterpret_cast<PackageResetOps*>(this)))->GetData())))
                pPackageTarget = reinterpret_cast<::PackageTargetRecord*>(new PackageTargetObj);
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067b170);
            break;
        case 1:
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067bfd0);
            if (!((void *)(reinterpret_cast<::Script *>((reinterpret_cast<PackageResetOps*>(this)))->GetData())))
                pPackageTarget = reinterpret_cast<::PackageTargetRecord*>(new PackageTargetObj);
            break;
        case 0:
        case 7:
        case 14:
        case 17:
            if (!((void *)(reinterpret_cast<::Script *>((reinterpret_cast<PackageResetOps*>(this)))->GetData())))
                pPackageTarget = reinterpret_cast<::PackageTargetRecord*>(new PackageTargetObj);
            break;
        case 8:
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067c770);
            if (!reinterpret_cast<PackageResetOps*>(this)->FUN_0055b980())
                pPackageLocation = reinterpret_cast<::LocationDescriptor*>(new FUN_0067f030);
            if (!((void *)(reinterpret_cast<::Script *>((reinterpret_cast<PackageResetOps*>(this)))->GetData())))
                pPackageTarget = reinterpret_cast<::PackageTargetRecord*>(new PackageTargetObj);
            break;
        case 16:
            reinterpret_cast<::FUN_00671a20_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671a20(true);
            if (!((void *)(reinterpret_cast<::Script *>((reinterpret_cast<PackageResetOps*>(this)))->GetData())))
                pPackageTarget = reinterpret_cast<::PackageTargetRecord*>(new PackageTargetObj);
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067caa0);
            break;
        case 13:
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067c3f0_Class);
            break;
        case 3:
            if (!((void *)(reinterpret_cast<::Script *>((reinterpret_cast<PackageResetOps*>(this)))->GetData())))
                pPackageTarget = reinterpret_cast<::PackageTargetRecord*>(new PackageTargetObj);
            if (!reinterpret_cast<::PackageTargetRecord *>((reinterpret_cast<TargetResetOps*>(pPackageTarget)))->GetTargetKind())
                reinterpret_cast<::PackageTargetRecord *>((reinterpret_cast<TargetResetOps*>(pPackageTarget)))->SetTargetKind((::PACK_TARG_TYPE)(2));
            data = reinterpret_cast<TESPatrolPackageData*>(new FUN_0067b950);
        case 4:
        case 5:
        case 6:
        case 12:
            if (!reinterpret_cast<PackageResetOps*>(this)->FUN_0055b980())
                pPackageLocation = reinterpret_cast<::LocationDescriptor*>(new FUN_0067f030);
            break;
        }
        f24 = 0;
        switch (newType)
        {
        case 12:
            reinterpret_cast<::FUN_00671ad0_Class *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671ad0(true);
            reinterpret_cast<::FUN_00671b30_Class *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671b30(true);
            reinterpret_cast<::FUN_00671b90_Class *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671b90(true);
            reinterpret_cast<::FUN_00671bf0_Class *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671bf0(true);
            reinterpret_cast<::FUN_00671c50_Class *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671c50(true);
            reinterpret_cast<::FUN_00671cb0_Class *>((reinterpret_cast<PackageResetOps*>(this)))->SetFlag20(true);
            reinterpret_cast<::FUN_00671a70_Class *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671a70(false);
        }
        type = (char)newType;
        switch (newType)
        {
        case 9:
            if (!((void *)(reinterpret_cast<::FUN_00672dd0_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00672dd0())))
            {
                FUN_0067f030* location = new FUN_0067f030;
                reinterpret_cast<::fnv_00671e10::FUN_00671e10_shell *>((reinterpret_cast<PackageResetOps*>(this)))->FUN_00671e10((::fnv_00671e10::LocationDescriptor *)(location));
                delete reinterpret_cast<FUN_00670b30*>(location);
            }
        }
    }
}

class TESPatrolPackageData
{
  public:
    virtual void Unused();
    virtual void Copy(TESPatrolPackageData*);
};
struct PackageAccessor
{
    int FUN_0055b980();
    int FUN_006733e0();
};
struct CopyItem
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct PackageCopy : TESPackage
{
    CopyItem item4c, item5c, item6c;
    void CopyFromPackage(TESForm*);
};
// Copies package data from another TESPackage into this one, including accessor values, fields, data, items and flags.
// @fnv 0x00673290
void PackageCopy::CopyFromPackage(TESForm* form)
{
    TESPackage* p = dynamic_cast<TESPackage*>(form);
    if (!p)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(p);
    reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>(this)->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(std::uintptr_t)(((PackageAccessor*)p)->FUN_0055b980()));
    reinterpret_cast<::FUN_00672fc0_shell *>(this)->FUN_00672fc0((::PackageTargetRecord *)(((reinterpret_cast<::Script *>((((PackageAccessor*)p)))->GetData()))));
    reinterpret_cast<::TESPackage *>(this)->CopyScheduleFrom((::DurationData *)(((reinterpret_cast<::FUN_0041d8a0_shell *>((((PackageAccessor*)p)))->FUN_0041d8a0()))));
    reinterpret_cast<::BGSDehydrationStage *>(this)->FUN_0050f9a0((::SpellItem *)(((reinterpret_cast<::BGSTerrainManager *>((((PackageAccessor*)p)))->GetMinLevel()))));
    f22 = p->f22;
    reinterpret_cast<::fnv_00673200::FUN_00673200_shell *>(this)->FUN_00673200((::fnv_00673200::BGSIdleCollection *)(((reinterpret_cast<::PackedByteIntRecord *>((((PackageAccessor*)p)))->Endian()))));
    reinterpret_cast<::fnv_006730a0::FUN_006730a0_shell *>(this)->CallOrResetObject((void *)(((std::intptr_t)(reinterpret_cast<::BGSCameraPath *>((((PackageAccessor*)p)))->GetPrevPath()))));
    reinterpret_cast<::ValueModifierEffect *>(this)->SetActorValue((::ActorValue::Index)(((PackageAccessor*)p)->FUN_006733e0()));
    reinterpret_cast<::PackageEx *>(this)->SetPackageType((*(int *)&(const ::PTYPE &)(p->GetPackType())));
    f24 = p->f24;
    if (data)
        data->Copy(p->data);
    reinterpret_cast<::FUN_0067dad0_shell *>(&(item4c))->FUN_0067dad0((::PackageEventActionData *)(::CopyItem *)(&((PackageCopy*)form)->item4c));
    reinterpret_cast<::FUN_0067dad0_shell *>(&(item5c))->FUN_0067dad0((::PackageEventActionData *)(::CopyItem *)(&((PackageCopy*)form)->item5c));
    reinterpret_cast<::FUN_0067dad0_shell *>(&(item6c))->FUN_0067dad0((::PackageEventActionData *)(::CopyItem *)(&((PackageCopy*)form)->item6c));
    flags18 = reinterpret_cast<::FUN_009611e0_shell *>((((PackageAccessor*)p)))->FUN_009611e0();
}

struct PkgFile
{
    void ReadChunkInt(unsigned int*);
};
struct PkgGeneral
{
    unsigned int flags;
    char type;
    char unk05;
    short unk06;
    int unk08;
};
struct PkgLocationRecord
{
    int type, id, radius;
};
struct PkgDialogueRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
};
struct PkgFindRecord
{
    int value;
};
struct PkgEscortRecord
{
    int value;
};
struct PkgWanderRecord2
{
    int unk00, unk04, unk08, unk0c, unk10;
};
struct PkgWanderRecord3
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
};
struct PkgPatrolRecord
{
    unsigned short value;
};
struct PkgTargetRecord
{
    int type, id, count, unk0c;
};
struct PkgScheduleRecord
{
    int time, duration;
};
struct PkgLocation
{
    int type, id, radius;
    PkgLocation(const PkgLocationRecord&);
    ~PkgLocation();
};
struct PkgTarget
{
    int type, id, count, unk0c;
    PkgTarget(const PkgTargetRecord&);
    ~PkgTarget();
};
struct PkgSchedule
{
    int time, duration;
    PkgSchedule(const PkgScheduleRecord&);
    ~PkgSchedule();
};
struct PkgData
{
    virtual ~PkgData();
    int unk04;
};
struct PkgDialogue : PkgData
{
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    PkgDialogue(PkgDialogueRecord);
};
struct PkgFind : PkgData
{
    int unk08;
    PkgFind(PkgFindRecord);
};
struct PkgEscort : PkgData
{
    int unk08;
    PkgEscort(const PkgEscortRecord&);
};
struct PkgWander : PkgData
{
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    PkgWander(PkgWanderRecord2);
    PkgWander(PkgWanderRecord3);
};
struct PkgPatrol : PkgData
{
    PkgPatrol(unsigned short);
};
struct PkgLocationData
{
    int unk00, unk04, unk08;
    PkgLocation* location;
};
struct PkgTravelData
{
    int unk00;
    PkgTarget* target;
    PkgLocation* location;
};
struct PkgIdle
{
    int unk00, unk04, unk08, unk0c;
    PkgIdle();
};
struct PkgConditions
{
};
struct PkgEvent
{
    int unk00, unk04, unk08, unk0c;
};
struct PkgLoad
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
    virtual void LoadBounds(PkgFile*);
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void SetEditorID(const char*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    PkgGeneral general;
    PkgData* data;
    int unk2c, unk30;
    PkgIdle* idle;
    int unk38, unk3c, unk40, unk44, unk48;
    PkgEvent onBegin, onEnd, onChange;
    bool LoadFromFile(PkgFile*);
};
// @fnv 0x00673a40
bool PkgLoad::LoadFromFile(PkgFile* file)
{
    unsigned char type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (type != 0x49)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        switch (reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())
        {
        case 0x44494445: {
            char* editor = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editor), 512);
            SetEditorID(editor);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x54444b50: {
            PkgGeneral record;
            ::FUN_00403d30(&record, 0, 12);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 12);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::S *>(&(record))->FUN_00670760();
            reinterpret_cast<::PackageEx *>(this)->SetPackageType(record.type);
            general = record;
            break;
        }
        case 0x54444c50: {
            PkgLocationRecord locationRecord2;
            ::FUN_00403d30(&locationRecord2, 0, 12);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&locationRecord2), 12);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_0067eff0_Class *>(&(locationRecord2))->FUN_0067eff0();
            PkgLocation location2(locationRecord2);
            reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>(this)->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)&(location2));
            break;
        }
        case 0x44444b50: {
            PkgDialogueRecord record;
            ::FUN_00403d30(&record, 0, 24);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 24);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_0067b100_Class *>(&(record))->FUN_0067b100();
            delete data;
            data = 0;
            data = new PkgDialogue(record);
            break;
        }
        case 0x44464b50: {
            PkgFindRecord record;
            ::FUN_00403d30(&record, 0, 4);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 4);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>(&(record))->FUN_00503210();
            delete data;
            data = 0;
            data = new PkgFind(record);
            break;
        }
        case 0x32454b50: {
            PkgEscortRecord record;
            ::FUN_00403d30(&record, 0, 4);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 4);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>(&(record))->FUN_00503210();
            delete data;
            data = 0;
            data = new PkgEscort(record);
            break;
        }
        case 0x32574b50: {
            PkgWanderRecord2 record;
            ::FUN_00403d30(&record, 0, 20);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 20);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_0067ca10_cls *>(&(record))->FUN_0067ca10();
            delete data;
            data = new PkgWander(record);
            break;
        }
        case 0x33574b50: {
            PkgWanderRecord3 record;
            ::FUN_00403d30(&record, 0, 24);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 24);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_0067ca10_cls *>(&(record))->FUN_0067ca10();
            delete data;
            data = new PkgWander(record);
            break;
        }
        case 0x54504b50: {
            PkgPatrolRecord record;
            ::FUN_00403d30(&record, 0, 2);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 2);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::TESForm *>(&(record))->ClearData();
            delete data;
            data = new PkgPatrol(record.value);
            break;
        }
        case 0x32444c50: {
            PkgLocationRecord record;
            ::FUN_00403d30(&record, 0, 12);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 12);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_0067eff0_Class *>(&(record))->FUN_0067eff0();
            switch (reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get())
            {
            case 15:
            case 28: {
                PkgLocationData* other = (PkgLocationData*)data;
                other->location = new PkgLocation(record);
                break;
            }
            case 16: {
                PkgTravelData* other = (PkgTravelData*)data;
                other->location = new PkgLocation(record);
                break;
            }
            default:
                PkgLocation location(record);
                reinterpret_cast<::fnv_00671e10::FUN_00671e10_shell *>(this)->FUN_00671e10((::fnv_00671e10::LocationDescriptor *)&(location));
                break;
            }
            break;
        }
        case 0x32445450: {
            PkgTargetRecord record;
            ::FUN_00403d30(&record, 0, 16);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 16);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>(&(record))->FUN_0067ff10();
            switch (reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get())
            {
            case 16: {
                PkgTravelData* other = (PkgTravelData*)data;
                delete other->target;
                other->target = new PkgTarget(record);
                break;
            }
            }
            break;
        }
        case 0x54445350: {
            PkgScheduleRecord scheduleRecord;
            ::FUN_00403d30(&scheduleRecord, 0, 8);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&scheduleRecord), 8);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_0060ce80_Obj *>(&(scheduleRecord))->FUN_0060ce80();
            PkgSchedule aSchedule(scheduleRecord);
            reinterpret_cast<::TESPackage *>(this)->CopyScheduleFrom((::DurationData *)&(aSchedule));
            break;
        }
        case 0x54445450: {
            PkgTargetRecord record;
            ::FUN_00403d30(&record, 0, 16);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&record), 16);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>(&(record))->FUN_0067ff10();
            PkgTarget target(record);
            reinterpret_cast<::FUN_00672fc0_shell *>(this)->FUN_00672fc0((::PackageTargetRecord *)&(target));
            break;
        }
        case 0x4d414e43: {
            unsigned int combat = 0;
            file->ReadChunkInt(&combat);
            reinterpret_cast<::ValueModifierEffect *>(this)->SetActorValue((::ActorValue::Index)(combat));
            break;
        }
        case 0x41445443:
            reinterpret_cast<::PerkEntryConditionSet *>((((::PkgConditions *)(reinterpret_cast<::PackedByteIntRecord *>(this)->Endian()))))->Load((::TESFile *)(file));
            break;
        case 0x414c4449:
        case 0x424c4449:
        case 0x434c4449:
        case 0x464c4449:
        case 0x4e4c4449:
        case 0x544c4449:
            if (!idle)
                idle = new PkgIdle;
            reinterpret_cast<::BGSIdleCollection *>((idle))->Load((::TESFile *)(file));
            break;
        case 0x41424f50:
            reinterpret_cast<::TESFile *>((file))->NextChunk();
            reinterpret_cast<::PackageEventActionData *>(&(onBegin))->Load((::TESFile *)(file));
            break;
        case 0x41454f50:
            reinterpret_cast<::TESFile *>((file))->NextChunk();
            reinterpret_cast<::PackageEventActionData *>(&(onEnd))->Load((::TESFile *)(file));
            break;
        case 0x41434f50:
            reinterpret_cast<::TESFile *>((file))->NextChunk();
            reinterpret_cast<::PackageEventActionData *>(&(onChange))->Load((::TESFile *)(file));
            break;
        }
    } while (reinterpret_cast<::TESFile *>((file))->NextChunk());
    return true;
}

struct World74;
struct Package74;
struct Ref74;
struct Process74
{
    virtual void virtual_0();
    virtual void virtual_1();
    virtual void virtual_2();
    virtual void virtual_3();
    virtual void virtual_4();
    virtual void virtual_5();
    virtual void virtual_6();
    virtual void virtual_7();
    virtual void virtual_8();
    virtual void virtual_9();
    virtual void virtual_10();
    virtual void virtual_11();
    virtual void virtual_12();
    virtual void virtual_13();
    virtual void virtual_14();
    virtual void virtual_15();
    virtual void virtual_16();
    virtual void virtual_17();
    virtual void virtual_18();
    virtual void virtual_19();
    virtual void virtual_20();
    virtual void virtual_21();
    virtual void virtual_22();
    virtual void virtual_23();
    virtual void virtual_24();
    virtual void virtual_25();
    virtual void virtual_26();
    virtual void virtual_27();
    virtual void virtual_28();
    virtual void virtual_29();
    virtual void virtual_30();
    virtual void virtual_31();
    virtual void virtual_32();
    virtual void virtual_33();
    virtual void virtual_34();
    virtual void virtual_35();
    virtual void virtual_36();
    virtual void virtual_37();
    virtual void virtual_38();
    virtual void virtual_39();
    virtual void virtual_40();
    virtual void virtual_41();
    virtual void virtual_42();
    virtual void virtual_43();
    virtual void virtual_44();
    virtual void virtual_45();
    virtual void virtual_46();
    virtual void virtual_47();
    virtual void virtual_48();
    virtual void virtual_49();
    virtual void virtual_50();
    virtual void virtual_51();
    virtual void virtual_52();
    virtual void virtual_53();
    virtual void virtual_54();
    virtual void virtual_55();
    virtual void virtual_56();
    virtual void virtual_57();
    virtual void virtual_58();
    virtual void virtual_59();
    virtual void virtual_60();
    virtual void virtual_61();
    virtual void virtual_62();
    virtual void virtual_63();
    virtual void virtual_64();
    virtual void virtual_65();
    virtual void virtual_66();
    virtual void virtual_67();
    virtual void virtual_68();
    virtual void virtual_69();
    virtual void virtual_70();
    virtual void virtual_71();
    virtual void virtual_72();
    virtual void virtual_73();
    virtual void virtual_74();
    virtual void virtual_75();
    virtual void virtual_76();
    virtual void virtual_77();
    virtual void virtual_78();
    virtual void virtual_79();
    virtual void virtual_80();
    virtual void virtual_81();
    virtual void virtual_82();
    virtual void virtual_83();
    virtual void virtual_84();
    virtual void virtual_85();
    virtual void virtual_86();
    virtual void virtual_87();
    virtual void virtual_88();
    virtual void virtual_89();
    virtual void virtual_90();
    virtual void virtual_91();
    virtual void virtual_92();
    virtual void virtual_93();
    virtual void virtual_94();
    virtual void virtual_95();
    virtual void virtual_96();
    virtual void virtual_97();
    virtual void virtual_98();
    virtual void virtual_99();
    virtual void virtual_100();
    virtual void virtual_101();
    virtual void virtual_102();
    virtual void virtual_103();
    virtual void virtual_104();
    virtual void virtual_105();
    virtual void virtual_106();
    virtual void virtual_107();
    virtual void virtual_108();
    virtual void virtual_109();
    virtual void virtual_110();
    virtual void virtual_111();
    virtual void virtual_112();
    virtual void virtual_113();
    virtual void virtual_114();
    virtual void virtual_115();
    virtual void virtual_116();
    virtual void virtual_117();
    virtual void virtual_118();
    virtual void virtual_119();
    virtual void virtual_120();
    virtual void virtual_121();
    virtual void virtual_122();
    virtual void virtual_123();
    virtual void virtual_124();
    virtual void virtual_125();
    virtual void virtual_126();
    virtual void virtual_127();
    virtual void virtual_128();
    virtual void virtual_129();
    virtual void virtual_130();
    virtual void virtual_131();
    virtual void virtual_132();
    virtual void virtual_133();
    virtual void virtual_134();
    virtual void virtual_135();
    virtual void virtual_136();
    virtual void virtual_137();
    virtual void virtual_138();
    virtual void virtual_139();
    virtual void virtual_140();
    virtual void virtual_141();
    virtual void virtual_142();
    virtual void virtual_143();
    virtual void virtual_144();
    virtual void virtual_145();
    virtual void virtual_146();
    virtual void virtual_147();
    virtual void virtual_148();
    virtual void virtual_149();
    virtual void virtual_150();
    virtual void virtual_151();
    virtual void virtual_152();
    virtual void virtual_153();
    virtual void virtual_154();
    virtual void virtual_155();
    virtual void virtual_156();
    virtual void virtual_157();
    virtual void virtual_158();
    virtual Package74* m_kProcessData();
    virtual void virtual_160();
    virtual void virtual_161();
    virtual void virtual_162();
    virtual void virtual_163();
    virtual void virtual_164();
    virtual void virtual_165();
    virtual void virtual_166();
    virtual void virtual_167();
    virtual void virtual_168();
    virtual void virtual_169();
    virtual void virtual_170();
    virtual void virtual_171();
    virtual void virtual_172();
    virtual void virtual_173();
    virtual void virtual_174();
    virtual void virtual_175();
    virtual void virtual_176();
    virtual void virtual_177();
    virtual void virtual_178();
    virtual void virtual_179();
    virtual void virtual_180();
    virtual void virtual_181();
    virtual void virtual_182();
    virtual void virtual_183();
    virtual void virtual_184();
    virtual void virtual_185();
    virtual void virtual_186();
    virtual void virtual_187();
    virtual void virtual_188();
    virtual void virtual_189();
    virtual void virtual_190();
    virtual void virtual_191();
    virtual void virtual_192();
    virtual void virtual_193();
    virtual void virtual_194();
    virtual void virtual_195();
    virtual void virtual_196();
    virtual void virtual_197();
    virtual void virtual_198();
    virtual void virtual_199();
    virtual void virtual_200();
    virtual void virtual_201();
    virtual void virtual_202();
    virtual void virtual_203();
    virtual void virtual_204();
    virtual void virtual_205();
    virtual void virtual_206();
    virtual void virtual_207();
    virtual void virtual_208();
    virtual void virtual_209();
    virtual void virtual_210();
    virtual void virtual_211();
    virtual void virtual_212();
    virtual void virtual_213();
    virtual void virtual_214();
    virtual void virtual_215();
    virtual void virtual_216();
    virtual void virtual_217();
    virtual void virtual_218();
    virtual void virtual_219();
    virtual void virtual_220();
    virtual void virtual_221();
    virtual void virtual_222();
    virtual void virtual_223();
    virtual void virtual_224();
    virtual void virtual_225();
    virtual void virtual_226();
    virtual void virtual_227();
    virtual void virtual_228();
    virtual void virtual_229();
    virtual void virtual_230();
    virtual void virtual_231();
    virtual void virtual_232();
    virtual void virtual_233();
    virtual void virtual_234();
    virtual void virtual_235();
    virtual void virtual_236();
    virtual void virtual_237();
    virtual void virtual_238();
    virtual void virtual_239();
    virtual void virtual_240();
    virtual void virtual_241();
    virtual void virtual_242();
    virtual void virtual_243();
    virtual void virtual_244();
    virtual void virtual_245();
    virtual void virtual_246();
    virtual void virtual_247();
    virtual void virtual_248();
    virtual void virtual_249();
    virtual void virtual_250();
    virtual void virtual_251();
    virtual void virtual_252();
    virtual void virtual_253();
    virtual void virtual_254();
    virtual void virtual_255();
    virtual void virtual_256();
    virtual void virtual_257();
    virtual void virtual_258();
    virtual void virtual_259();
    virtual void virtual_260();
    virtual void virtual_261();
    virtual void virtual_262();
    virtual void virtual_263();
    virtual void virtual_264();
    virtual void virtual_265();
    virtual void virtual_266();
    virtual void virtual_267();
    virtual void virtual_268();
    virtual void virtual_269();
    virtual void virtual_270();
    virtual void virtual_271();
    virtual void virtual_272();
    virtual void virtual_273();
    virtual void virtual_274();
    virtual void virtual_275();
    virtual void virtual_276();
    virtual void virtual_277();
    virtual void virtual_278();
    virtual void virtual_279();
    virtual void virtual_280();
    virtual void virtual_281();
    virtual void virtual_282();
    virtual void virtual_283();
    virtual void virtual_284();
    virtual void virtual_285();
    virtual void virtual_286();
    virtual void virtual_287();
    virtual void virtual_288();
    virtual void virtual_289();
    virtual void virtual_290();
    virtual void virtual_291();
    virtual void virtual_292();
    virtual void virtual_293();
    virtual void virtual_294();
    virtual void virtual_295();
    virtual void virtual_296();
    virtual void virtual_297();
    virtual void virtual_298();
    virtual void virtual_299();
    virtual void virtual_300();
    virtual void virtual_301();
    virtual void virtual_302();
    virtual void virtual_303();
    virtual void virtual_304();
    virtual void virtual_305();
    virtual void virtual_306();
    virtual void virtual_307();
    virtual void virtual_308();
    virtual void virtual_309();
    virtual void virtual_310();
    virtual void virtual_311();
    virtual void virtual_312();
    virtual void virtual_313();
    virtual void virtual_314();
    virtual void virtual_315();
    virtual void virtual_316();
    virtual void virtual_317();
    virtual void virtual_318();
    virtual void virtual_319();
    virtual void virtual_320();
    virtual void virtual_321();
    virtual void virtual_322();
    virtual void virtual_323();
    virtual void virtual_324();
    virtual void virtual_325();
    virtual void virtual_326();
    virtual Ref74* CurrentTarget();
};
struct Ref74
{
    virtual void virtual_0();
    virtual void virtual_1();
    virtual void virtual_2();
    virtual void virtual_3();
    virtual void virtual_4();
    virtual void virtual_5();
    virtual void virtual_6();
    virtual void virtual_7();
    virtual void virtual_8();
    virtual void virtual_9();
    virtual void virtual_10();
    virtual void virtual_11();
    virtual void virtual_12();
    virtual void virtual_13();
    virtual void virtual_14();
    virtual void virtual_15();
    virtual void virtual_16();
    virtual void virtual_17();
    virtual void virtual_18();
    virtual void virtual_19();
    virtual void virtual_20();
    virtual void virtual_21();
    virtual void virtual_22();
    virtual void virtual_23();
    virtual void virtual_24();
    virtual void virtual_25();
    virtual void virtual_26();
    virtual void virtual_27();
    virtual void virtual_28();
    virtual void virtual_29();
    virtual void virtual_30();
    virtual void virtual_31();
    virtual void virtual_32();
    virtual void virtual_33();
    virtual void virtual_34();
    virtual void virtual_35();
    virtual void virtual_36();
    virtual void virtual_37();
    virtual void virtual_38();
    virtual void virtual_39();
    virtual void virtual_40();
    virtual void virtual_41();
    virtual void virtual_42();
    virtual void virtual_43();
    virtual void virtual_44();
    virtual void virtual_45();
    virtual void virtual_46();
    virtual void virtual_47();
    virtual void virtual_48();
    virtual void virtual_49();
    virtual void virtual_50();
    virtual void virtual_51();
    virtual void virtual_52();
    virtual void virtual_53();
    virtual void virtual_54();
    virtual void virtual_55();
    virtual void virtual_56();
    virtual void virtual_57();
    virtual void virtual_58();
    virtual void virtual_59();
    virtual void virtual_60();
    virtual void virtual_61();
    virtual void virtual_62();
    virtual void virtual_63();
    virtual void virtual_64();
    virtual void virtual_65();
    virtual void virtual_66();
    virtual void virtual_67();
    virtual void virtual_68();
    virtual void virtual_69();
    virtual void virtual_70();
    virtual void virtual_71();
    virtual void virtual_72();
    virtual void virtual_73();
    virtual void virtual_74();
    virtual void virtual_75();
    virtual void virtual_76();
    virtual void virtual_77();
    virtual void virtual_78();
    virtual void virtual_79();
    virtual void virtual_80();
    virtual void virtual_81();
    virtual void virtual_82();
    virtual void virtual_83();
    virtual void virtual_84();
    virtual void virtual_85();
    virtual void virtual_86();
    virtual void virtual_87();
    virtual void virtual_88();
    virtual void virtual_89();
    virtual void virtual_90();
    virtual void virtual_91();
    virtual void virtual_92();
    virtual void virtual_93();
    virtual void virtual_94();
    virtual void virtual_95();
    virtual void virtual_96();
    virtual void virtual_97();
    virtual void virtual_98();
    virtual void virtual_99();
    virtual void virtual_100();
    virtual void virtual_101();
    virtual void virtual_102();
    virtual void virtual_103();
    virtual void virtual_104();
    virtual void virtual_105();
    virtual void virtual_106();
    virtual void virtual_107();
    virtual void virtual_108();
    virtual void virtual_109();
    virtual void virtual_110();
    virtual void virtual_111();
    virtual void virtual_112();
    virtual void virtual_113();
    virtual void virtual_114();
    virtual void virtual_115();
    virtual void virtual_116();
    virtual void virtual_117();
    virtual void virtual_118();
    virtual void virtual_119();
    virtual void virtual_120();
    virtual void virtual_121();
    virtual void virtual_122();
    virtual void virtual_123();
    virtual void virtual_124();
    virtual void virtual_125();
    virtual void virtual_126();
    virtual void virtual_127();
    virtual void virtual_128();
    virtual void virtual_129();
    virtual void virtual_130();
    virtual void virtual_131();
    virtual void virtual_132();
    virtual void virtual_133();
    virtual void virtual_134();
    virtual void virtual_135();
    virtual void virtual_136();
    virtual void virtual_137();
    virtual void virtual_138();
    virtual void virtual_139();
    virtual void virtual_140();
    virtual void virtual_141();
    virtual void virtual_142();
    virtual void virtual_143();
    virtual void virtual_144();
    virtual void virtual_145();
    virtual void virtual_146();
    virtual void virtual_147();
    virtual void virtual_148();
    virtual void virtual_149();
    virtual void virtual_150();
    virtual void virtual_151();
    virtual void virtual_152();
    virtual void virtual_153();
    virtual void virtual_154();
    virtual void virtual_155();
    virtual void virtual_156();
    virtual void virtual_157();
    virtual void virtual_158();
    virtual void virtual_159();
    virtual void virtual_160();
    virtual void virtual_161();
    virtual void virtual_162();
    virtual void virtual_163();
    virtual void virtual_164();
    virtual World74* ParentWorld();
};

struct Other74
{
};
struct Location74
{
};
struct Package74
{
    World74* FUN_00674fd0(Ref74* actor);
};
struct PlayerPackage74 : Package74
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
    Ref74* target;
};
struct Vec
{
    float x, y, z;
};
struct PHost;
struct Proc;
struct Ref
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual Vec Center();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const Vec& Position();
};
struct Proc
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual PHost* Package();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual Ref* Target();
};
struct Cell
{
    Ref* FUN_0054cee0();
    bool IsInterior();
    int FUN_00544c30();
    int FUN_00544c60();
};
struct Loc
{
};
struct PHost
{
    Vec FUN_00675360(Ref* actor);
};
struct Special : PHost
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
    Ref* target;
};

struct PkgProcStub
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual TESPackage* GetCurrentPackage();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual TESObjectREFR* GetTargetRef();
};
struct PkgActorStub : public TESObjectREFR
{
};
struct PkgLocStub
{
    int GetLocType();
};
struct PkgLocShell : public TESPackage
{
    TESObjectREFR* FUN_006756a0(PkgActorStub* actor);
};

// Prior C++ reconstruction credited to another contributor, 2026-10-23; unverified when retrieved.
struct P070Process;
struct P070Base
{
    int FUN_00401170();
};
struct P070Ref
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
    virtual NiPoint3* GetPosition();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual int GetState();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual bool IsReady();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual bool IsNear(NiPoint3*, float, bool, int);
};
struct P070Process
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
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void slot304();
    virtual void slot305();
    virtual P070Ref* GetTarget();
    virtual void slot307();
    virtual void slot308();
    virtual NiPoint3* GetLocation();
};
struct P070Location
{
};
struct P070Package
{
    NiPoint3 FUN_00675360(P070Ref*);
    bool IsWithinPackageLocation(P070Ref*, P070Ref*, bool, float, bool);
};
// @fnv 0x00676390
bool P070Package::IsWithinPackageLocation(P070Ref* object, P070Ref* actor, bool ignoreRadius, float customRadius,
                                          bool useProcess)
{
    if (!object)
        return false;
    P070Ref* sevenA = 0;
    if (object->IsActor())
        sevenA = object;
    P070Location* loc3 = ((::P070Location *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
    if (!loc3)
        return true;
    if (loc3 && reinterpret_cast<::DurationData *>((loc3))->FUN_00678ca0() == 3 && !actor->IsReady())
        return true;
    TESWorldSpace* aWorld = ((::TESWorldSpace *)(reinterpret_cast<::Package74 *>(this)->FUN_00674fd0((::Ref74 *)(actor))));
    TESObjectCELL* pCell9 = ((::TESObjectCELL *)(reinterpret_cast<::fnv_006751a0::Pkg *>(this)->FUN_006751a0((::fnv_006751a0::Ref *)(actor))));
    if (pCell9 && !pCell9->IsCellInterior())
        pCell9 = 0;
    TESWorldSpace* targetWorld5 = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((object))->FUN_00575d70()));
    TESObjectCELL* objectCell4 = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((object))->GetTarget()));
    if (objectCell4 && !objectCell4->IsCellInterior())
        objectCell4 = 0;
    bool aSame = false;
    if (objectCell4 || pCell9)
    {
        if (objectCell4 == pCell9)
        {
            aSame = true;
            if (loc3 && reinterpret_cast<::DurationData *>((loc3))->FUN_00678ca0() == 1)
                return true;
        }
    }
    else if (targetWorld5 == aWorld)
        aSame = true;
    if (!aSame)
        return false;
    bool locationResult3 = false;
    if (loc3 && reinterpret_cast<::FUN_0067f220_cls *>((loc3))->LookupAndStore((std::intptr_t)(actor), (std::intptr_t)(object), (unsigned char *)&(locationResult3)))
        return locationResult3;
    int radius2 = ((int)(reinterpret_cast<::fnv_00675670::FUN_00675670_shell *>(this)->FUN_00675670()));
    if (radius2 > 0)
        useProcess = false;
    if (ignoreRadius)
        radius2 = 0;
    else if (customRadius != -1.0)
        radius2 = (int)customRadius;
    bool exact2 = false;
    NiPoint3 position = FUN_00675360(actor);
    P070Ref* target8 = 0;
    P070Ref* targetActor;
    float extra6;
    if (loc3)
        target8 = ((::P070Ref *)(reinterpret_cast<::PkgLocShell *>(this)->FUN_006756a0((::PkgActorStub *)(actor))));
    if (radius2 == 0 && loc3)
    {
        if (target8)
        {
            if (reinterpret_cast<::FUN_00568680_shell *>((target8))->FUN_00568680() && ((::P070Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((object))->GetBaseTexture())) && ((::P070Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((object))->GetBaseTexture()))->GetLocation())
            {
                if (!((std::intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((::P070Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))))->FUN_0045cd60())))
                    position = *((::P070Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetLocation();
                radius2 = 20;
                exact2 = true;
            }
            else if (((::P070Base *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target8))->FUN_007af430())) == (*reinterpret_cast<::P070Base * *>(&::DAT_011ca248)) || ((::P070Base *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target8))->FUN_007af430())) == (*reinterpret_cast<::P070Base * *>(&::DAT_011ca244)))
            {
                radius2 = 20;
                exact2 = true;
            }
            else if (target8->IsActor())
            {
                targetActor = target8;
                if (targetActor->GetState() == 9)
                {
                    radius2 = 90;
                    exact2 = true;
                }
                else
                    radius2 = (int)reinterpret_cast<::TESObjectREFR *>((target8))->GetBoundingRadius() + 20;
            }
            else
            {
                extra6 = 20.0f;
                switch (((::P070Base *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target8))->FUN_007af430()))->FUN_00401170())
                {
                case 21:
                case 27:
                case 32:
                case 33:
                    extra6 = 0.0f;
                }
                radius2 = (int)reinterpret_cast<::TESObjectREFR *>((target8))->GetBoundingRadius() + (int)extra6;
                if (radius2 < 0)
                    radius2 = 0;
            }
        }
        else if (reinterpret_cast<::DurationData *>((loc3))->FUN_00678ca0() == 3)
        {
            exact2 = true;
            radius2 = 10;
        }
    }
    if (radius2 == 0)
        radius2 = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011cde98))))));
    bool result3 = false;
    if (reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get() == 5 && objectCell4)
    {
        if (std::abs(object->GetPosition()->z - FUN_00675360(actor).z) > 100.0)
            return false;
    }
    bool excluded = false;
    if (useProcess && target8 && reinterpret_cast<::FUN_00568680_shell *>((target8))->FUN_00568680() && ((::P070Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((object))->GetBaseTexture())) &&
        ((::P070Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((object))->GetBaseTexture()))->GetLocation())
    {
        NiPoint3 direction = position - *object->GetPosition();
        if (sevenA && (sevenA->GetState() == 4 || sevenA->GetState() == 9))
        {
            if (((::P070Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((sevenA))->GetBaseTexture()))->GetTarget() == target8)
                result3 = true;
        }
    }
    else
    {
        if (object->IsNear(&position, (float)radius2, !exact2, 1) && !excluded)
            result3 = true;
    }
    return result3;
}

struct PickPackage
{
};

struct PickForm;

struct PickSource
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
    virtual bool IsUsable();
};

struct PickForm
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
    virtual bool IsActor();
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
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool IsDead(bool);
    PickPackage* GetCurrentPackage();
    bool HasPickTarget(PickForm* target);
};

struct PickContext
{
    PickSource* source;
    PickForm* caller;
    bool checkPackage;
};


// @fnv 0x006784f0
bool IsValidPickTarget(PickForm* form, PickContext* pContext)
{
    if (!pContext)
        return false;
    PickContext* ctx5 = pContext;
    PickSource* source7 = ctx5->source;
    PickForm* caller2 = ctx5->caller;
    bool checkPackage = ctx5->checkPackage;
    if (!source7->IsUsable())
        return false;
    PickSource* src_2 = source7;
    if (reinterpret_cast<::fnv_0055d3b0::FUN_0055d3b0 *>((form))->IsOfType(src_2) && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(form))->FUN_00440d80())
    {
        if (form->IsActor())
        {
            PickForm* actor = form;
            if (actor == caller2)
                return false;
            if (actor->IsDead(true))
                return false;
            if (checkPackage)
            {
                PickPackage* pkg3 = ((::PickPackage *)(reinterpret_cast<::FUN_009344a0_shell *>((actor))->FUN_009344a0()));
                if (pkg3 && reinterpret_cast<struct ::FUN_0041ca90 *>((pkg3))->get() == 1)
                    return false;
                if (caller2->HasPickTarget(actor))
                    return false;
            }
        }
        (*reinterpret_cast<::PickForm * *>(&::fnv_006780e0::DAT_011d6580)) = form;
        return true;
    }
    return false;
}

struct SaveStream679120 : SaveManager
{
};
struct Location679120
{
};
struct Target679120
{
};
struct Record679120
{
    unsigned int id;
    unsigned char type;
    unsigned char sizeLow;
    unsigned char sizeByte1;
    unsigned char sizeByte2;
    unsigned char sizeByte3;
};
struct Package679120 : TESPackage
{
    void SavePackage();
};
// Writes the package's flags, location and target presence to the save stream, then back-patches the BLOCK length when saving.
// @fnv 0x00679120
void Package679120::SavePackage()
{
    unsigned short blockLength = 0;
    std::uintptr_t start = 0;
    unsigned int blockStart = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
    if (*::g_011de4e8.Bool())
        blockStart = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int tag = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&tag, 4);
        start = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&blockLength, 2);
    }
    reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&flags, 12);
    unsigned char presence = 0;
    if (pPackageLocation)
        presence |= 1;
    if (pPackageTarget)
        presence |= 2;
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&presence, 1);
    if (pPackageLocation)
        reinterpret_cast<::FUN_0067fa00_shell *>((((Location679120*)pPackageLocation)))->FUN_0067fa00();
    if (pPackageTarget)
        reinterpret_cast<::C680590Target *>((((Target679120*)pPackageTarget)))->SaveLoad();
    reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&flags18, 4);
    if (*::g_011de4e8.Bool())
    {
        unsigned int end = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        Record679120* record = (Record679120*)((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (record)
        {
            TESFormStandIn* form = ((::TESFormStandIn *)(::FUN_004839c0(record->id)));
            ::FUN_0040fbe0(::DAT_010153a0, end - blockStart, record->id, form->GetName(), *(unsigned int*)&record->sizeLow,
                         0x1d6e, str_010685dc);
        }
        else
        {
            ::FUN_0040fbe0(::DAT_0101536c, end - blockStart, 0x1d6e, str_010685dc);
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int begin = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveStream679120*)(*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        unsigned int end = start;
        if (begin > end + 0xffff)
            ::FUN_005b5e40();
        *(unsigned short*)start = (unsigned short)(begin - end);
    }
}

struct FUN_006797c0_arg
{
};

struct FUN_006797c0_sub
{
};

struct FUN_006797c0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(FUN_006797c0_arg* a);
};

struct FUN_006797c0_shell : public TESPackage
{
    void FUN_006797c0(FUN_006797c0_arg* a);
};

// @fnv 0x006797c0
void FUN_006797c0_shell::FUN_006797c0(FUN_006797c0_arg* a)
{
    if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()))))
    {
        return;
    }
    {
        reinterpret_cast<::FUN_00865e50_shell *>((a))->FUN_00865e50(&flags, 12, 0);
        unsigned char bits = 0;
        if (pPackageLocation != 0)
        {
            bits |= 1;
        }
        if (pPackageTarget != 0)
        {
            bits |= 2;
        }
        if (data != 0)
        {
            bits |= 4;
        }
        reinterpret_cast<::FUN_00865e50_shell *>((a))->FUN_00865e50(&bits, 1, 0);
        if (pPackageLocation != 0)
        {
            reinterpret_cast<::FUN_0067fb60_shell *>((((FUN_006797c0_sub*)pPackageLocation)))->FUN_0067fb60((::LocationInputStream *)(a));
        }
        if (pPackageTarget != 0)
        {
            reinterpret_cast<::C80720Target *>((((FUN_006797c0_sub*)pPackageTarget)))->SaveToBuffer((::C80720SaveBuffer *)(a));
        }
        if (data != 0)
        {
            ((FUN_006797c0_vt*)data)->v5(a);
        }
        reinterpret_cast<::FUN_00865e50_shell *>((a))->FUN_00865e50(&flags18, 4, 0);
    }
}

struct ChangeFlags6798c0
{
    unsigned int flags;
};

struct LoadBuffer6798c0
{
    ChangeFlags6798c0 GetChangeFlags();
};

struct PackageDataA6798c0
{
    PackageDataA6798c0();
    int unk00;
    int unk04;
    int unk08;
};

struct PackageDataB6798c0
{
    PackageDataB6798c0();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct PackageData6798c0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void LoadGame(LoadBuffer6798c0* buf);
};

struct Package6798c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int flags;
    int unk20;
    int unk24;
    PackageData6798c0* data;
    PackageDataA6798c0* dataA;
    PackageDataB6798c0* dataB;

    void LoadPackage(LoadBuffer6798c0* buf);
};

// @fnv 0x006798c0
void Package6798c0::LoadPackage(LoadBuffer6798c0* pBuffer)
{
    if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))
    {
        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::ChangeFlags6798c0 &)(pBuffer->GetChangeFlags()))->FUN_004280f0(0x80000000))
            flags |= 0x8000;
        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::ChangeFlags6798c0 &)(pBuffer->GetChangeFlags()))->FUN_004280f0(0x40000000))
            flags |= 0x10000;
    }
    else
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flags), 0xc);
        unsigned char loadFlags = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&loadFlags), 1);
        if (loadFlags & 1)
        {
            dataA = new PackageDataA6798c0;
            reinterpret_cast<::FUN_0067fbe0_cls *>((dataA))->FUN_0067fbe0((::PackageLoadStream *)(pBuffer));
        }
        if (loadFlags & 2)
        {
            dataB = new PackageDataB6798c0;
            reinterpret_cast<::S_006807b0_Target *>((dataB))->FUN_006807b0((::S_006807b0_Stream *)(pBuffer));
        }
        if (loadFlags & 4)
            data->LoadGame(pBuffer);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk18), 4);
    }
}

struct FUN_00401170_s
{
    int FUN_00401170();
};
struct ConsumableTraits
{
};
struct ConsumableForm
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    ConsumableTraits traits;
};
// Returns true when the form's type code maps to the given object type, with extra checks for armor, clothing, weapons and consumables.
// @fnv 0x00679e00
bool __cdecl MatchesObjectType(TESForm* form, int objectType)
{
    bool matches = false;
    if (form && objectType)
    {
        switch (((FUN_00401170_s*)form)->FUN_00401170())
        {
        case 21:
            if (objectType == 1)
                matches = true;
            break;
        case 25:
            if (objectType == 3)
                matches = true;
            break;
        case 27:
            if (objectType == 5)
                matches = true;
            break;
        case 28:
            if (objectType == 6)
                matches = true;
            break;
        case 30:
            if (objectType == 8)
                matches = true;
            break;
        case 31:
        case 50:
        case 103:
            if (objectType == 9)
                matches = true;
            break;
        case 38:
            if (objectType == 10)
                matches = true;
            break;
        case 39:
            if (objectType == 11)
                matches = true;
            break;
        case 42:
            if (objectType == 14 || objectType == 28)
                matches = true;
            break;
        case 43:
            if (objectType == 15 || objectType == 28)
                matches = true;
            break;
        case 46:
            if (objectType == 16)
                matches = true;
            break;
        case 47:
            if (objectType == 17)
                matches = true;
            else if (objectType == 18)
            {
                DummyForm3C* armor = (DummyForm3C*)form;
                if (armor->sub.v1())
                    matches = true;
            }
            break;
        case 29:
            if (objectType == 7)
                matches = true;
            else if (objectType == 18)
            {
                DummyForm3C* clothing = (DummyForm3C*)form;
                if (clothing->sub.v1())
                    matches = true;
            }
            break;
        case 26:
            switch (objectType)
            {
            case 4:
            case 20:
                matches = true;
                break;
            }
            break;
        case 108:
        case 115:
        case 116:
            if (objectType == 9)
                matches = true;
            break;
        case 24:
            switch (objectType)
            {
            case 2:
            case 19:
            case 20:
                matches = true;
                break;
            }
            break;
        case 40:
            switch (objectType)
            {
            case 12:
            case 19:
            case 20:
                matches = true;
                break;
            case 22:
            case 23: {
                TESObjectWEAP* weapon = (TESObjectWEAP*)form;
                if (weapon)
                {
                    if ((FUN_006450c0(weapon) && objectType == 22) || (::FUN_004c0c30((char *)(weapon)) && objectType == 23))
                        matches = true;
                }
                break;
            }
            }
            break;
        case 41:
            switch (objectType)
            {
            case 13:
            case 19:
            case 20:
                matches = true;
                break;
            }
            break;
        case 20:
            switch (objectType)
            {
            case 24:
                matches = true;
                break;
            case 25:
            case 26:
            case 27: {
                ConsumableForm* consumable = (ConsumableForm*)form;
                if (consumable)
                {
                    switch (objectType)
                    {
                    case 25:
                        if (reinterpret_cast<::fnv_00405f30::EILStandIn *>(&(consumable->traits))->HasNonDetrimentalEffect())
                            matches = true;
                        break;
                    case 26:
                        if (reinterpret_cast<::fnv_00405fe0::EffectItemList *>(&(consumable->traits))->FUN_00405fe0())
                            matches = true;
                        break;
                    case 27:
                        if (reinterpret_cast<::fnv_00406090::EffectItemList *>(&(consumable->traits))->FUN_00406090())
                            matches = true;
                        break;
                    }
                }
                break;
            }
            }
            break;
        }
    }
    return matches;
}

struct A90Mgr
{
};
struct A90Sub1
{
};
struct A90Sub2
{
};
class A90Virt
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(int a);
};
struct A90Cls
{
    char pad[0x28];
    A90Virt* m_28;
    A90Sub1* m_2c;
    A90Sub2* m_30;
    void DispatchToSubobjects(std::intptr_t a);
};
// If the manager check on FUN_0084e3a0() passes, forwards a to m_2c, m_30 and m_28 via their respective methods.
// @fnv 0x00679a90
void A90Cls::DispatchToSubobjects(std::intptr_t aiValue)
{
    if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::A90Mgr * *>(&::g_dataHandler))))->IsRenderTargetId((unsigned int)(std::uintptr_t)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())))))
        return;
    if (m_2c)
        reinterpret_cast<::FUN_0067fc50_shell *>((m_2c))->ResolveObject(aiValue);
    if (m_30)
        reinterpret_cast<::FUN_00680830_shell *>((m_30))->FUN_00680830((void *)(aiValue));
    if (m_28)
        m_28->v1c(aiValue);
}

struct PackageScheduleF20
{
};
struct FUN_00672f20_cls
{
    void* FUN_0055b980();
    void* FUN_00672f20();
};
// @fnv 0x006758a0
unsigned int Proxy758a0::FUN_006758a0(MobileObject* apMobile)
{
    std::intptr_t loc = ((std::intptr_t)(reinterpret_cast<::FUN_00672f20_cls *>((((PkgProxy*)this)))->FUN_00672f20()));
    return loc == ((Script*)this)->GetText() ? reinterpret_cast<::HighProcess *>((((TESPackage*)this)))->UpdateHighProcessState((::Actor *)(apMobile))
                                             : reinterpret_cast<::fnv_00675670::FUN_00675670_shell *>((((F5670*)this)))->FUN_00675670();
}
// Calls FUN_00672f20 and FUN_0055b980; if equal, calls FUN_00675c20(actor), otherwise FUN_006751a0(actor), returning that result.
// @fnv 0x006757e0
int FUN_006757e0_shell::FUN_006757e0(MobileObject* actor)
{
    std::intptr_t firstResult = ((std::intptr_t)(reinterpret_cast<::FUN_00672f20_cls *>(this)->FUN_00672f20()));
    return firstResult == FUN_0055b980() ? FUN_00675c20(actor) : ((std::intptr_t)(reinterpret_cast<::fnv_006751a0::Pkg *>(this)->FUN_006751a0((::fnv_006751a0::Ref *)(actor))));
}
// @fnv 0x00675830
PackValue12* FUN_00675830_shell::FUN_00675830(PackValue12* output, void* actor)
{
    std::intptr_t packageType = ((std::intptr_t)(reinterpret_cast<::FUN_00672f20_cls *>(this)->FUN_00672f20()));
    PackValue12 successful;
    PackValue12 fallback;
    const PackValue12* sourceValue =
        packageType == FUN_0055b980() ? FUN_00675de0(&successful, actor) : FUN_00675360(&fallback, actor);
    *output = *sourceValue;
    return output;
}
// @fnv 0x00672f20
void* FUN_00672f20_cls::FUN_00672f20()
{
    PackageScheduleF20* pkSchedule;
    switch (reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get())
    {
    case 0:
    case 12:
    case 17:
    case 28:
        return FUN_0055b980();
        break;
    case 2:
    case 3:
    case 8:
    case 16:
        pkSchedule = ((::PackageScheduleF20 *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
        if (pkSchedule && reinterpret_cast<::DurationData *>((pkSchedule))->FUN_00678ca0() == 7)
            return FUN_0055b980();
        else
            return ((::PackageScheduleF20 *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
    }
    return 0;
}

namespace fnv_006787e0 {
struct Vec
{
    float x, y, z;
};
struct Form
{
    int FUN_00401170();
};
struct Data
{
};
struct Package;
struct Extra
{
};
struct Slots16
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
};
struct Slots32 : Slots16
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
};
struct Slots48 : Slots32
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
};
struct Slots64 : Slots48
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
};
struct Obj : Slots64
{
    virtual bool isRef();
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual Vec getVec();
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual Vec* getPos();
    virtual void j0();
    virtual void j1();
    virtual void j2();
    virtual void j3();
    virtual void j4();
    virtual void j5();
    virtual void j6();
    virtual void j7();
    virtual void j8();
    virtual void j9();
    virtual void j10();
    virtual void j11();
    virtual void j12();
    virtual void j13();
    virtual void j14();
    virtual void j15();
    virtual void k0();
    virtual void k1();
    virtual void k2();
    virtual void k3();
    virtual void k4();
    virtual void k5();
    virtual void k6();
    virtual void k7();
    virtual void k8();
    virtual void k9();
    virtual void k10();
    virtual void k11();
    virtual void k12();
    virtual void k13();
    virtual void k14();
    virtual void k15();
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
    virtual void l8();
    virtual void l9();
    virtual void l10();
    virtual void l11();
    virtual void l12();
    virtual void l13();
    virtual void l14();
    virtual void l15();
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual Obj* getObj();
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual void n4();
    virtual void n5();
    virtual void n6();
    virtual void n7();
    virtual void n8();
    virtual void n9();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual float getHeight();
};
struct Setting
{
};
struct Package
{
    char pad[24];
    int type;
    void* FUN_0055b980();
    float GetPackageResult(Obj*, bool);
};
// Computes an integer result from the target object's type, reference status and position, falling back to a setting value, and returns it as a float.
// @fnv 0x006787e0
float Package::GetPackageResult(Obj* obj, bool flag)
{
    std::intptr_t result = 0;
    void* ref = flag ? ((void *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0())) : FUN_0055b980();
    Obj* unused = 0;
    if (obj->isRef())
        unused = obj;
    Obj* target = obj->getObj();
    if (target)
    {
        if (reinterpret_cast<::FUN_00568680_shell *>((target))->FUN_00568680())
            result = 10;
        else if (((::fnv_006787e0::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target))->FUN_007af430())) == *(Form**)&(*reinterpret_cast<char *>(&::DAT_011ca248)) || ((::fnv_006787e0::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target))->FUN_007af430())) == *(Form**)&(*reinterpret_cast<char *>(&::DAT_011ca244)))
            result = 20;
        else
        {
            Package* pPackage = ((::fnv_006787e0::Package *)(reinterpret_cast<::FUN_0041cb10_shell *>((((::fnv_006787e0::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((unused))->FUN_005d43c0()))))->FUN_0041cb10()));
            if (reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get() == 28 && pPackage && ((::fnv_006787e0::Data *)(reinterpret_cast<::Script *>((pPackage))->GetData())))
                result = ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((::fnv_006787e0::Data *)(reinterpret_cast<::Script *>((pPackage))->GetData()))))->GetName()));
            else if (((::fnv_006787e0::Data *)(reinterpret_cast<::Script *>(this)->GetData())) && type != 26)
                result = ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((::fnv_006787e0::Data *)(reinterpret_cast<::Script *>(this)->GetData()))))->GetName()));
            if (!result && !target->isRef())
            {
                result = (int)reinterpret_cast<::TESObjectREFR *>((target))->GetBoundingRadius();
                switch (((::fnv_006787e0::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target))->FUN_007af430()))->FUN_00401170())
                {
                case 21:
                case 27:
                case 32:
                case 33:
                    break;
                default:
                    if (unused)
                    {
                        float top = unused->getHeight();
                        result += (int)top;
                        float height = reinterpret_cast<::fnv_008be940::FloatValueProvider *>((unused))->FUN_008be940() + unused->getPos()->z - top;
                        float z = target->getPos()->z;
                        if (height > z)
                        {
                            if (height - z < obj->getVec().z / 2.0)
                                result += (int)(obj->getVec().z / 2.0);
                        }
                    }
                }
            }
        }
    }
    if (!result)
        result = *((int *)&(::FUN_0043d4d0((int *)(((Setting*)&(*reinterpret_cast<char *>(&::g_011cde98)))))));
    return (float)result;
}
}  // namespace fnv_006787e0

class xPt3
{
  public:
    float x, y, z;
    xPt3();
};
class xRefP
{
  public:
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetName();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual xPt3 GetPosV();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const xPt3& GetPos();
};
class xProc
{
  public:
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual class xPkg* GetAssignedPackage();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual xRefP* GetTarget();
};
struct xExtraL
{
};
struct xCell
{
    bool IsInterior();
};
struct xLoc
{
    xRefP* GetRef();
};

class xPkg
{
  public:
    xLoc* GetLocation();
    xPt3 FUN_00675de0(xRefP* pActor);
};

namespace fnv_006780e0 {
class Script
{
  public:
};
class V
{
  public:
    virtual void f000();
    virtual void f001();
    virtual void f002();
    virtual void f003();
    virtual void f004();
    virtual void f005();
    virtual void f006();
    virtual void f007();
    virtual void f008();
    virtual void f009();
    virtual void f00a();
    virtual void f00b();
    virtual void f00c();
    virtual void f00d();
    virtual void f00e();
    virtual void f00f();
    virtual void f010();
    virtual void f011();
    virtual void f012();
    virtual void f013();
    virtual void f014();
    virtual void f015();
    virtual void f016();
    virtual void f017();
    virtual void f018();
    virtual void f019();
    virtual void f01a();
    virtual void f01b();
    virtual void f01c();
    virtual void f01d();
    virtual void f01e();
    virtual void f01f();
    virtual void f020();
    virtual void f021();
    virtual void f022();
    virtual void f023();
    virtual void f024();
    virtual void f025();
    virtual void f026();
    virtual void f027();
    virtual void f028();
    virtual void f029();
    virtual void f02a();
    virtual void f02b();
    virtual void f02c();
    virtual void f02d();
    virtual void f02e();
    virtual void f02f();
    virtual void f030();
    virtual void f031();
    virtual void f032();
    virtual void f033();
    virtual void f034();
    virtual void f035();
    virtual void f036();
    virtual void f037();
    virtual void f038();
    virtual bool f039();
    virtual void f03a();
    virtual void f03b();
    virtual void f03c();
    virtual void f03d();
    virtual void f03e();
    virtual void f03f();
    virtual bool f040();
    virtual void f041();
    virtual void f042();
    virtual void f043();
    virtual void f044();
    virtual void f045();
    virtual void f046();
    virtual void f047();
    virtual void f048();
    virtual void f049();
    virtual void f04a();
    virtual void f04b();
    virtual void f04c();
    virtual void f04d();
    virtual void f04e();
    virtual void f04f();
    virtual void f050();
    virtual void f051();
    virtual void f052();
    virtual void f053();
    virtual void f054();
    virtual void f055();
    virtual void f056();
    virtual void f057();
    virtual void f058();
    virtual void f059();
    virtual void f05a();
    virtual void f05b();
    virtual void f05c();
    virtual void f05d();
    virtual void f05e();
    virtual void f05f();
    virtual void f060();
    virtual void f061();
    virtual void f062();
    virtual void f063();
    virtual void f064();
    virtual void f065();
    virtual void f066();
    virtual void f067();
    virtual void f068();
    virtual void f069();
    virtual void f06a();
    virtual void f06b();
    virtual void f06c();
    virtual void f06d();
    virtual void f06e();
    virtual void f06f();
    virtual void f070();
    virtual void f071();
    virtual void f072();
    virtual void f073();
    virtual void f074();
    virtual void f075();
    virtual void f076();
    virtual void f077();
    virtual void f078();
    virtual void f079();
    virtual void f07a();
    virtual void f07b();
    virtual void f07c();
    virtual std::uintptr_t f07d();
    virtual void f07e();
    virtual void f07f();
    virtual void f080();
    virtual void f081();
    virtual void f082();
    virtual void f083();
    virtual void f084();
    virtual void f085();
    virtual void f086();
    virtual void f087();
    virtual void f088();
    virtual void f089();
    virtual void f08a();
    virtual void f08b();
    virtual void f08c();
    virtual void f08d();
    virtual void f08e();
    virtual void f08f();
    virtual void f090();
    virtual void f091();
    virtual void f092();
    virtual void f093();
    virtual void f094();
    virtual void f095();
    virtual void f096();
    virtual void f097();
    virtual void f098();
    virtual void f099();
    virtual void f09a();
    virtual void f09b();
    virtual void f09c();
    virtual void f09d();
    virtual void f09e();
    virtual void f09f();
    virtual void f0a0();
    virtual void f0a1();
    virtual unsigned int f0a2(V*, int);
    virtual void f0a3();
    virtual void f0a4();
    virtual void f0a5();
    virtual void f0a6();
    virtual void f0a7();
    virtual void f0a8();
    virtual void f0a9();
    virtual void f0aa();
    virtual void f0ab();
    virtual void f0ac();
    virtual void f0ad();
    virtual void f0ae();
    virtual void f0af();
    virtual void f0b0();
    virtual void f0b1();
    virtual void f0b2();
    virtual void f0b3();
    virtual void f0b4();
    virtual void f0b5();
    virtual void f0b6();
    virtual void f0b7();
    virtual void f0b8();
    virtual void f0b9();
    virtual void f0ba();
    virtual void f0bb();
    virtual void f0bc();
    virtual void f0bd();
    virtual void f0be();
    virtual void f0bf();
    virtual void f0c0();
    virtual void f0c1();
    virtual void f0c2();
    virtual void f0c3();
    virtual void f0c4();
    virtual void f0c5();
    virtual void f0c6();
    virtual void f0c7();
    virtual void f0c8();
    virtual void f0c9();
    virtual void f0ca();
    virtual void f0cb();
    virtual void f0cc();
    virtual void f0cd();
    virtual void f0ce();
    virtual void f0cf();
    virtual void f0d0();
    virtual void f0d1();
    virtual void f0d2();
    virtual void f0d3();
    virtual void f0d4();
    virtual void f0d5();
    virtual void f0d6();
    virtual void f0d7();
    virtual void f0d8();
    virtual void f0d9();
    virtual void f0da();
    virtual void f0db();
    virtual void f0dc();
    virtual void f0dd();
    virtual void f0de();
    virtual void f0df();
    virtual void f0e0();
    virtual void f0e1();
    virtual void f0e2();
    virtual void f0e3();
    virtual void f0e4();
    virtual void f0e5();
    virtual void f0e6();
    virtual void f0e7();
    virtual void f0e8();
    virtual void f0e9();
    virtual void f0ea();
    virtual void f0eb();
    virtual void f0ec();
    virtual void f0ed();
    virtual void f0ee();
    virtual void f0ef();
    virtual void f0f0();
    virtual void f0f1();
    virtual void f0f2();
    virtual void f0f3();
    virtual void f0f4();
    virtual void f0f5();
    virtual void f0f6();
    virtual void f0f7();
    virtual void f0f8();
    virtual void f0f9();
    virtual void f0fa();
    virtual void f0fb();
    virtual void f0fc();
    virtual void f0fd();
    virtual void f0fe();
    virtual void f0ff();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f10a();
    virtual void f10b();
    virtual void f10c();
    virtual void f10d();
    virtual void f10e();
    virtual void f10f();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f11a();
    virtual void f11b();
    virtual void f11c();
    virtual void f11d();
    virtual void f11e();
    virtual void f11f();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f12a();
    virtual void f12b();
    virtual void f12c();
    virtual void f12d();
    virtual void f12e();
    virtual void f12f();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f13a();
    virtual void f13b();
    virtual void f13c();
    virtual void f13d();
    virtual void f13e();
    virtual void f13f();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f14a();
    virtual unsigned int f14b();
};
struct Pkg_006780e0_Ctx
{
    V* found;
    V* ref;
    bool opt;
};
class Data
{
  public:
    V* FUN_00680080();
};
class Setting
{
  public:
};
class Handler
{
  public:
};
class MessageSetting
{
  public:
};
class NumberSingleton
{
  public:
};
class BSOcclusionPlane
{
  public:
};
class BSShaderNoLightingProperty
{
  public:
};
class TESPackageExt : public TESPackage
{
  public:
    V* FUN_006780e0(V* targetObj, bool option);
};
// @fnv 0x006780e0
V* TESPackageExt::FUN_006780e0(V* targetObj, bool option)
{
    if (!((::fnv_006780e0::Data *)(reinterpret_cast<::Script *>((((Script*)this)))->GetData())))
        return 0;
    int ref = reinterpret_cast<::PackageTargetRecord *>((((::fnv_006780e0::Data *)(reinterpret_cast<::Script *>((((Script*)this)))->GetData()))))->GetTargetKind();
    V* secondary7 = 0;
    V* targType2 = 0;
    if (secondary7 == 0)
    {
        switch (ref)
        {
        case 0: {
            secondary7 = ((::fnv_006780e0::V *)(reinterpret_cast<::PackageTargetRecord *>((((::fnv_006780e0::Data *)(reinterpret_cast<::Script *>((((Script*)this)))->GetData()))))->GetReferenceTarget()));
            if (secondary7)
            {
                if (reinterpret_cast<::FUN_00440d80_shell *>((secondary7))->FUN_00440d80() && ((::fnv_006780e0::V *)(reinterpret_cast<::FUN_005d43c0_ *>((secondary7))->FUN_005d43c0())))
                    secondary7 = ((::fnv_006780e0::V *)(reinterpret_cast<::FUN_0041c8d0_shell *>((((::fnv_006780e0::V *)(reinterpret_cast<::FUN_005d43c0_ *>((secondary7))->FUN_005d43c0()))))->FUN_0041c8d0()));
            }
            break;
        }
        case 3: {
            secondary7 = ((::fnv_006780e0::V *)(reinterpret_cast<::FUN_00569b80_shell *>((targetObj))->FUN_00569b80()));
            if (secondary7)
            {
                if (reinterpret_cast<::FUN_00440d80_shell *>((secondary7))->FUN_00440d80() && ((::fnv_006780e0::V *)(reinterpret_cast<::FUN_005d43c0_ *>((secondary7))->FUN_005d43c0())))
                    secondary7 = ((::fnv_006780e0::V *)(reinterpret_cast<::FUN_0041c8d0_shell *>((((::fnv_006780e0::V *)(reinterpret_cast<::FUN_005d43c0_ *>((secondary7))->FUN_005d43c0()))))->FUN_0041c8d0()));
            }
            break;
        }
        case 1: {
            Pkg_006780e0_Ctx ctx;
            ctx.ref = targetObj;
            ctx.opt = option;
            V* acoustic_ = 0;
            if (((::fnv_006780e0::V *)(reinterpret_cast<::PackageTargetRecord *>((((::fnv_006780e0::Data *)(reinterpret_cast<::Script *>((((Script*)this)))->GetData()))))->GetTargetForm())))
            {
                if (((::fnv_006780e0::V *)(reinterpret_cast<::PackageTargetRecord *>((((::fnv_006780e0::Data *)(reinterpret_cast<::Script *>((((Script*)this)))->GetData()))))->GetTargetForm()))->f039())
                {
                    acoustic_ = ((::fnv_006780e0::V *)(reinterpret_cast<::PackageTargetRecord *>((((::fnv_006780e0::Data *)(reinterpret_cast<::Script *>((((Script*)this)))->GetData()))))->GetTargetForm()));
                    ctx.found = acoustic_;
                }
            }
            if ((*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer)) && acoustic_ == ((::fnv_006780e0::V *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer))))->FUN_007af430())))
            {
                secondary7 = (*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer));
            }
            else
            {
                reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_006780e0::Handler * *>(&::g_dataHandler))))->GetReferencesInArea((::TESObjectCELL *)(((reinterpret_cast<::LowProcess *>((((BSOcclusionPlane*)targetObj)))->GetTarget()))), (*(const ::NiPoint3 *)(targetObj->f07d())),
                                            *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_006780e0::Setting *>(&::originalRuntimeFloatSetting1307)))))), (*(const ::NiPoint3 *)(targetObj->f07d())),
                                            *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_006780e0::Setting *>(&::originalRuntimeFloatSetting1307)))))), (bool (*)(TESObjectREFR *, long))(void (*)())(&((void (&)())::IsValidPickTarget)), (std::intptr_t)(&ctx));
                secondary7 = DAT_011d6580;
                DAT_011d6580 = 0;
            }
            break;
        }
        case 2: {
            Pkg_006780e0_Ctx ctx3;
            ctx3.ref = targetObj;
            ctx3.opt = option;
            targType2 = ((::fnv_006780e0::Data *)(reinterpret_cast<::Script *>((((Script*)this)))->GetData()))->FUN_00680080();
            reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_006780e0::Handler * *>(&::g_dataHandler))))->GetReferencesInArea((::TESObjectCELL *)(((reinterpret_cast<::LowProcess *>((((BSOcclusionPlane*)targetObj)))->GetTarget()))), (*(const ::NiPoint3 *)(targetObj->f07d())),
                                        *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_006780e0::Setting *>(&::originalRuntimeFloatSetting1307)))))), (*(const ::NiPoint3 *)(targetObj->f07d())),
                                        *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_006780e0::Setting *>(&::originalRuntimeFloatSetting1307)))))), (bool (*)(TESObjectREFR *, long))(void (*)())(&((void (&)())::IsValidPickTarget)), (std::intptr_t)(&ctx3));
            secondary7 = DAT_011d6580;
            DAT_011d6580 = 0;
            break;
        }
        }
    }
    if (secondary7 && secondary7->f040() && !reinterpret_cast<::TESPackage *>(this)->IsMustComplete())
    {
        V* saved3 = secondary7;
        if (GetPackType() == (PTYPE)1 || GetPackType() == (PTYPE)7)
        {
            if (secondary7 == (*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer)) &&
                ((::fnv_006780e0::V *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((BSShaderNoLightingProperty*)targetObj)))->GetBaseTexture()))->f14b() != (unsigned int)(std::uintptr_t)(*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer)) &&
                !reinterpret_cast<::FUN_00962720_shell *>(((*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer))))->HasExtraFollowerForm((char *)(targetObj)) &&
                reinterpret_cast<::fnv_00962620::FUN_00962620_cls *>(((*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer))))->FUN_00962620() > *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_006780e0::NumberSingleton *>(&::g_011cdad0)))))))
            {
                ((::fnv_006780e0::V *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((BSShaderNoLightingProperty*)targetObj)))->GetBaseTexture()))->f0a2(targetObj, -1);
                ::DispatchMessageToSink(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_006780e0::MessageSetting *>(&::g_011d3d54))))->GetMenuTitle())), 0, 0, 0, ::DAT_010162c0, 0);
            }
            else
                reinterpret_cast<::FUN_008bc790_shell *>((saved3))->FUN_008bc790((::Actor *)(targetObj));
        }
        else if (GetPackType() == (PTYPE)2)
        {
            if (saved3 != (*reinterpret_cast<::fnv_006780e0::V * *>(&::_g_thePlayer)))
                reinterpret_cast<::FUN_008bc790_shell *>((targetObj))->FUN_008bc790((::Actor *)(saved3));
        }
    }
    return secondary7;
}
}  // namespace fnv_006780e0

namespace fnv_009ecbe0 {
struct FormX
{
    virtual void v0();
};
struct NamedX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c();
    virtual void v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(), v06c(), v070(),
        v074(), v078(), v07c();
    virtual void v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(), v0a4(), v0a8(), v0ac(), v0b0(),
        v0b4(), v0b8(), v0bc();
    virtual void v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(), v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(),
        v0f4(), v0f8(), v0fc();
    virtual void v100(), v104(), v108(), v10c(), v110(), v114(), v118(), v11c(), v120(), v124(), v128(), v12c();
    virtual const char* GetName();
};
struct ChangeRecX
{
    unsigned int auiFormId;
    char c4, c5, c6, c7, c8;
    unsigned char ucVersion;
};
struct SaveX
{
};
struct ListX
{
};
struct PackX
{
    void FUN_00679340();
    void FUN_009ecbe0();
};
// Reads a save block header, looks up each listed type and ID, and reports whether the consumed size differs from the block size.
// @fnv 0x009ecbe0
void PackX::FUN_009ecbe0()
{
    int i_f;
    unsigned short usBlockSize_yfuyr;
    unsigned int uiBlockStart_u;
    unsigned short usCount_qu;
    FUN_00679340();
    usBlockSize_yfuyr = 0;
    uiBlockStart_u = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        int iHeader;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&iHeader, 4);
        if (iHeader != 'BLOK')
        {
            ChangeRecX* pkRec = ((::fnv_009ecbe0::ChangeRecX *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))));
            if (pkRec)
            {
                NamedX* pkForm = ((::fnv_009ecbe0::NamedX *)(::FUN_004839c0(pkRec->auiFormId)));
                ::FUN_005b5e40(
                    );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
        }
        uiBlockStart_u = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&usBlockSize_yfuyr, 2);
    }
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&usCount_qu, 2);
    for (i_f = 0; i_f < usCount_qu; i_f++)
    {
        signed char cType;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&cType, 1);
        unsigned short usID;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&usID, 2);
        std::intptr_t iResult = ((std::intptr_t)(reinterpret_cast<::FUN_009727c0_shell *>(&((*reinterpret_cast<::fnv_009ecbe0::ListX *>(&::g_011e0e80))))->FUN_009727c0(cType, usID)));
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int uiBlockEnd_etwkfv = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        ChangeRecX* pkRec_z = ((::fnv_009ecbe0::ChangeRecX *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_009ecbe0::SaveX * *>(&::g_TESSaveLoadGame))))));
        if (pkRec_z)
        {
            NamedX* pkForm2 = ((::fnv_009ecbe0::NamedX *)(::FUN_004839c0(pkRec_z->auiFormId)));
            if (uiBlockEnd_etwkfv > usBlockSize_yfuyr + uiBlockStart_u)
                ::FUN_005b5e40(
                    );
            else if (uiBlockEnd_etwkfv < usBlockSize_yfuyr + uiBlockStart_u)
                ::FUN_005b5e40(
                    );
        }
        else
        {
            if (uiBlockEnd_etwkfv > usBlockSize_yfuyr + uiBlockStart_u)
                ::FUN_005b5e40(
                    );
            else if (uiBlockEnd_etwkfv < usBlockSize_yfuyr + uiBlockStart_u)
                ::FUN_005b5e40(
                    );
        }
    }
}
}  // namespace fnv_009ecbe0

namespace fnv_00675c20 {
struct Cell;
struct PHost;
struct Proc;
struct Ref
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual Cell* ParentCell();
};
struct Proc
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual PHost* Package();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual Ref* Target();
};
struct Cell
{
    Ref* FUN_0054cee0();
    bool IsInterior();
    int FUN_00544c30();
    int FUN_00544c60();
};
struct Loc
{
    Cell* FUN_0067f3e0();
    Ref* FUN_0067f390();
};
struct PHost
{
    Loc* FUN_0055b980();
    Cell* FUN_00675c20(Ref* actor);
};

// Selects a cell using the location descriptor and actor; absent locations or type 2 use actor-based lookups.
// @fnv 0x00675c20
Cell* PHost::FUN_00675c20(Ref* actor)
{
    Cell* cell = 0;
    Loc* location = FUN_0055b980();
    location = (Loc*)location;
    if (location && ((unsigned int)(reinterpret_cast<::DurationData *>((location))->FUN_00678ca0())) != 2)
    {
        switch (((unsigned int)(reinterpret_cast<::DurationData *>((location))->FUN_00678ca0())))
        {
        case 1:
            cell = location->FUN_0067f3e0();
            break;
        case 0:
            if (location->FUN_0067f390())
                cell = ((::fnv_00675c20::Cell *)(reinterpret_cast<::LowProcess *>((location->FUN_0067f390()))->GetTarget()));
            else if (actor)
                cell = ((::fnv_00675c20::Cell *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()));
            break;
        case 6:
            if (actor && ((::fnv_00675c20::Ref *)(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80())))
                cell = ((::fnv_00675c20::Cell *)(reinterpret_cast<::LowProcess *>((((::fnv_00675c20::Ref *)(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80()))))->GetTarget()));
            else if (actor)
                cell = ((::fnv_00675c20::Cell *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()));
            break;
        case 3:
            if (actor)
                cell = actor->ParentCell();
            break;
        case 4:
        case 5:
            if (actor && ((::fnv_00675c20::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::fnv_00675c20::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Package() == this)
            {
                Ref* target = ((::fnv_00675c20::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Target();
                if (target)
                    cell = ((::fnv_00675c20::Cell *)(reinterpret_cast<::LowProcess *>((target))->GetTarget()));
                else
                    cell = ((::fnv_00675c20::Cell *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()));
            }
            break;
        }
    }
    else if (actor)
    {
        cell = ((::fnv_00675c20::Cell *)(std::uintptr_t)(reinterpret_cast<::fnv_0056ad80::Thing *>((actor))->FUN_0056ad80()));
        if (!cell)
        {
            reinterpret_cast<::MobileObject *>((actor))->ProcessAnimation();
            cell = ((::fnv_00675c20::Cell *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()));
        }
    }
    return cell;
}
}  // namespace fnv_00675c20

namespace fnv_00679340 {
static const char packageSourcePath[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Package.cpp";
struct UnalignedFlags679
{
    unsigned char byte0, byte1, byte2, byte3;
};
struct SaveRecord679
{
    unsigned int formID;
    unsigned char recordType;
    UnalignedFlags679 flags;
    unsigned char version;
};
class Form679
{
  public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual const char* GetDebugName();
};
class SaveLoad679
{
  public:
};
class FUN_0067f030
{
  public:
    unsigned int type;
    unsigned int value;
    float radius;
    FUN_0067f030();
};
class FUN_0067ff70
{
  public:
    unsigned int type;
    unsigned int target;
    unsigned int count;
    unsigned int unknown;
    FUN_0067ff70();
};
class Package679
{
  public:
    unsigned int form00, form04, form08, form0c, form10, form14;
    unsigned int flags18;
    unsigned int packageFlags;
    unsigned char packageType;
    unsigned char typeFlags;
    unsigned short behavior;
    unsigned int schedule;
    unsigned int packageData;
    FUN_0067f030* location;
    FUN_0067ff70* target;
    void FUN_00679340();
};
// @fnv 0x00679340
void Package679::FUN_00679340()
{
    unsigned char flags;
    unsigned short blockSize = 0;
    {
        unsigned int blockStart = 0;
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int marker;
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&marker, 4);
            if (marker != 0x424c4f4b)
            {
                SaveRecord679* record = ((::fnv_00679340::SaveRecord679 *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))));
                if (record)
                {
                    Form679* form = ((::fnv_00679340::Form679 *)(::FUN_004839c0(record->formID)));
                    ::FUN_005b5e40(
                        );
                }
                else
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            blockStart = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&blockSize, 2);
        }
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&packageFlags, 12);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&flags, 1);
        if (flags & 1)
        {
            location = new FUN_0067f030;
            reinterpret_cast<::fnv_0067faa0::OwnQ *>((location))->FUN_0067faa0();
        }
        if (flags & 2)
        {
            target = new FUN_0067ff70;
            reinterpret_cast<::SaveDataStub *>((target))->FUN_00680640();
        }
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&flags18, 4);
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int end = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            SaveRecord679* record2 = ((::fnv_00679340::SaveRecord679 *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_00679340::SaveLoad679 * *>(&::g_TESSaveLoadGame))))));
            if (record2)
            {
                Form679* form2 = ((::fnv_00679340::Form679 *)(::FUN_004839c0(record2->formID)));
                if (end > blockStart + blockSize)
                    ::FUN_005b5e40(
                        );
                else if (end < blockStart + blockSize)
                    ::FUN_005b5e40(
                        );
            }
            else
            {
                if (end > blockStart + blockSize)
                    ::FUN_005b5e40(
                        );
                else if (end < blockStart + blockSize)
                    ::FUN_005b5e40(
                        );
            }
        }
    }
}
}  // namespace fnv_00679340

class DataHandler
{
  public:
};

class DH : public DataHandler
{
};


struct FUN_00674e70_Virtuals
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18(unsigned int)
    {}
    virtual void f19(unsigned int)
    {}
};

struct FUN_00674e70_Shell : public TESPackage
{
    void FUN_00674e70(TESObjectREFR* pref, bool abVal);
};

// When the target reference matches pref, sets or clears flag 0x8000 and calls a virtual method if the data-handler check fails.
// @fnv 0x00674e70
void FUN_00674e70_Shell::FUN_00674e70(TESObjectREFR* pref, bool abVal)
{
    if (((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData())) && ((::PackageTargetRecord *)(reinterpret_cast<::Script *>(this)->GetData()))->GetReferenceTarget() == pref)
    {
        if (abVal)
        {
            flags |= 0x8000;
            if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()))))
            {
                ((FUN_00674e70_Virtuals*)this)->f18(0x80000000);
            }
        }
        else
        {
            flags &= 0xffff7fff;
            if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()))))
            {
                ((FUN_00674e70_Virtuals*)this)->f19(0x80000000);
            }
        }
    }
}

__if_not_exists(TESForm::TESForm)
{
    class TESForm
    {
      public:
        virtual void PackageCompareFormSlot0();
    };
}

struct PackageComparisonNode
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual bool Differs(PackageComparisonNode*);
};
class TESObjectCELL;
class TESObjectREFR;
struct LocationDescriptor
{
public:
    ::TESObjectREFR *GetLocationReference();
public:
    ::TESObjectCELL *GetLocationCellReference();
    void FUN_0067f3c0(::TESObjectREFR *);
    void InitItem(::TESForm *);
};
// @fnv 0x00674fd0
World74* Package74::FUN_00674fd0(Ref74* actor)
{
    World74* world = 0;
    Location74* loc3 = ((::Location74 *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
    if (loc3 && ((unsigned int)(reinterpret_cast<::DurationData *>((loc3))->FUN_00678ca0())) != 2)
    {
        switch (((unsigned int)(reinterpret_cast<::DurationData *>((loc3))->FUN_00678ca0())))
        {
        case 1:
            if (((::Other74 *)(reinterpret_cast<::LocationDescriptor *>((loc3))->GetLocationCellReference())))
                world = ((::World74 *)(reinterpret_cast<::TESObjectCELL *>((((::Other74 *)(reinterpret_cast<::LocationDescriptor *>((loc3))->GetLocationCellReference()))))->GetParentWorldSpace()));
            break;
        case 0:
            if (((::Ref74 *)(reinterpret_cast<::LocationDescriptor *>((loc3))->GetLocationReference())))
                world = ((::World74 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((::Ref74 *)(reinterpret_cast<::LocationDescriptor *>((loc3))->GetLocationReference()))))->FUN_00575d70()));
            break;
        case 6:
            if (actor && ((::Ref74 *)(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80())))
                world = ((::World74 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((::Ref74 *)(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80()))))->FUN_00575d70()));
            break;
        case 3:
            if (actor)
                world = actor->ParentWorld();
            break;
        case 4:
        case 5:
            if (actor && ((::Process74 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::Process74 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->m_kProcessData() == this)
            {
                Ref74* target = ((::Process74 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->CurrentTarget();
                if (target)
                    world = ((::World74 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((target))->FUN_00575d70()));
                else
                    world = ((::World74 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor))->FUN_00575d70()));
            }
            else if (actor == reinterpret_cast<Ref74*>((*reinterpret_cast<::XActor * *>(&::_g_thePlayer))) && reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get() == 28)
            {
                PlayerPackage74* playerPackage = static_cast<PlayerPackage74*>(this);
                if (playerPackage->target)
                    world = ((::World74 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((playerPackage->target))->FUN_00575d70()));
            }
            break;
        }
    }
    else if (actor)
        world = ((::World74 *)(reinterpret_cast<::FUN_0056ad30_shell *>((actor))->FUN_0056ad30()));
    return world;
}
// @fnv 0x00675360
Vec PHost::FUN_00675360(Ref* actor)
{
    Loc* location = ((::Loc *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
    Vec position = (*reinterpret_cast<const ::Vec *>((void *)&::NiPoint3::ZERO));
    if (location && ((unsigned int)(reinterpret_cast<::DurationData *>((location))->FUN_00678ca0())) != 2)
    {
        switch (((unsigned int)(reinterpret_cast<::DurationData *>((location))->FUN_00678ca0())))
        {
        case 1: {
            Cell* cell = ((::Cell *)(reinterpret_cast<::LocationDescriptor *>((location))->GetLocationCellReference()));
            if (cell)
            {
                Ref* reference = ((::Ref *)(std::uintptr_t)(reinterpret_cast<::s54cee0::Owner *>((cell))->FUN_0054cee0()));
                if (reference)
                    position = reference->Position();
                else if (!reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
                {
                    position.x = float(reinterpret_cast<::TESObjectCELL *>((((::Cell *)(reinterpret_cast<::LocationDescriptor *>((location))->GetLocationCellReference()))))->GetCellGridX() << 12);
                    position.y = float(reinterpret_cast<::TESObjectCELL *>((((::Cell *)(reinterpret_cast<::LocationDescriptor *>((location))->GetLocationCellReference()))))->GetCellGridY() << 12);
                    position.z = 0;
                }
            }
            break;
        }
        case 0:
            if (((::Ref *)(reinterpret_cast<::LocationDescriptor *>((location))->GetLocationReference())))
                position = ((::Ref *)(reinterpret_cast<::LocationDescriptor *>((location))->GetLocationReference()))->Position();
            break;
        case 6:
            if (actor && ((::Ref *)(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80())))
                position = ((::Ref *)(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80()))->Position();
            break;
        case 3:
            if (actor)
                position = actor->Center();
            break;
        case 4:
        case 5:
            if (actor && ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Package() == this)
            {
                Ref* target = ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Target();
                if (target)
                    position = target->Position();
                else
                    position = actor->Position();
            }
            else if (actor == (*reinterpret_cast<::Ref * *>(&::_g_thePlayer)) && reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get() == 28)
            {
                Special* special = (Special*)this;
                if (special->target)
                    position = special->target->Position();
            }
            break;
        }
    }
    else if (actor)
        position = (*(const ::Vec *)(reinterpret_cast<::fnv_0056add0::Obj *>((actor))->FUN_0056add0()));
    return position;
}
// @fnv 0x006756a0
TESObjectREFR* PkgLocShell::FUN_006756a0(PkgActorStub* actor)
{
    PkgLocStub* loc = ((::PkgLocStub *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()));
    TESObjectREFR* result = 0;
    if (loc && reinterpret_cast<::DurationData *>((loc))->FUN_00678ca0() != 2)
    {
        switch (reinterpret_cast<::DurationData *>((loc))->FUN_00678ca0())
        {
            break;
        case 0:
            if (reinterpret_cast<::LocationDescriptor *>((loc))->GetLocationReference())
                result = reinterpret_cast<::LocationDescriptor *>((loc))->GetLocationReference();
            break;
        case 6:
            if (actor && reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80())
                result = reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80();
            break;
        case 3:
            if (actor)
                result = actor;
            break;
        case 4:
        case 5:
            if (actor && ((::PkgProcStub *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::PkgProcStub *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetCurrentPackage() == this)
            {
                TESObjectREFR* target = ((::PkgProcStub *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetTargetRef();
                if (target)
                    result = target;
                else
                    result = actor;
            }
            break;
        }
    }
    else if (actor)
    {
        result = actor;
    }
    return result;
}
// Computes and returns the target position for a package based on its location type, falling back to the actor's position or start position when needed.
// @fnv 0x00675de0
xPt3 xPkg::FUN_00675de0(xRefP* pActor)
{
    xLoc* qsSDDgz = GetLocation();
    xPt3 qfTOqo = (*reinterpret_cast<::xPt3 *>((void *)&::NiPoint3::ZERO));
    if (qsSDDgz && reinterpret_cast<::DurationData *>((qsSDDgz))->FUN_00678ca0() != 2)
    {
        switch (reinterpret_cast<::DurationData *>((qsSDDgz))->FUN_00678ca0())
        {
        case 1: {
            xCell* qxQHW = ((::xCell *)(reinterpret_cast<::LocationDescriptor *>((qsSDDgz))->GetLocationCellReference()));
            if (qxQHW)
            {
                xRefP* qAhbO = ((::xRefP *)(std::uintptr_t)(reinterpret_cast<::s54cee0::Owner *>((qxQHW))->FUN_0054cee0()));
                if (qAhbO)
                    qfTOqo = qAhbO->GetPos();
                else if (!reinterpret_cast<::TESObjectCELL *>((qxQHW))->IsCellInterior())
                {
                    qfTOqo.x = (float)(reinterpret_cast<::TESObjectCELL *>((((::xCell *)(reinterpret_cast<::LocationDescriptor *>((qsSDDgz))->GetLocationCellReference()))))->GetCellGridX() << 12);
                    qfTOqo.y = (float)(reinterpret_cast<::TESObjectCELL *>((((::xCell *)(reinterpret_cast<::LocationDescriptor *>((qsSDDgz))->GetLocationCellReference()))))->GetCellGridY() << 12);
                    qfTOqo.z = 0.0f;
                }
            }
        }
        break;
        case 0:
            if (((::xRefP *)(reinterpret_cast<::LocationDescriptor *>((qsSDDgz))->GetLocationReference())))
                qfTOqo = ((::xRefP *)(reinterpret_cast<::LocationDescriptor *>((qsSDDgz))->GetLocationReference()))->GetPos();
            else if (pActor)
            {
                ::FUN_005b5e40();
                qfTOqo = pActor->GetPosV();
            }
            break;
        case 6:
            if (pActor && ((::xRefP *)(reinterpret_cast<::FUN_00569b80_shell *>((pActor))->FUN_00569b80())))
                qfTOqo = ((::xRefP *)(reinterpret_cast<::FUN_00569b80_shell *>((pActor))->FUN_00569b80()))->GetPos();
            else if (pActor)
            {
                ::FUN_005b5e40();
                qfTOqo = pActor->GetPosV();
            }
            break;
        case 3:
            if (pActor)
                qfTOqo = pActor->GetPosV();
            break;
        case 4:
        case 5:
            if (pActor && ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture())) && ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture()))->GetAssignedPackage() == this)
            {
                xRefP* qJDuOZ = ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture()))->GetTarget();
                if (qJDuOZ)
                    qfTOqo = qJDuOZ->GetPos();
                else
                    qfTOqo = pActor->GetPos();
            }
            break;
        }
    }
    else
    {
        if (pActor && !((void *)(reinterpret_cast<::FUN_00418b70_shell *>((((::xExtraL *)(reinterpret_cast<::FUN_005d43c0_ *>((pActor))->FUN_005d43c0()))))->FUN_00418b70())))
            reinterpret_cast<::MobileObject *>((pActor))->ProcessAnimation();
        if (pActor)
            qfTOqo = *((const ::xPt3 *)(reinterpret_cast<::fnv_0056add0::Obj *>((pActor))->FUN_0056add0()));
    }
    return qfTOqo;
}
struct PackageTargetComparison
{
};
struct PackageListComparison
{
    bool FUN_0067fe10(PackageListComparison*);
};
struct PackageSpellComparison
{
};
struct PackageQuestComparison
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual bool Differs(PackageQuestComparison*);
};
class PackagePatrolComparison
{
  public:
    virtual void Slot0();
    virtual void Slot1();
    virtual bool Differs(PackagePatrolComparison*);
};
struct PackageEventComparison
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};
struct PackageComparison : TESPackage
{
    PackageEventComparison onBegin;
    PackageEventComparison onEnd;
    PackageEventComparison onChange;
    LocationDescriptor* FUN_0055b980();
    PackageQuestComparison* FUN_006733e0();
    bool FUN_00673420(TESForm* form);
};
// Returns true when form is not a TESPackage or when checked package values or comparison objects differ.
// @fnv 0x00673420
bool PackageComparison::FUN_00673420(TESForm* form)
{
    PackageComparison* other = static_cast<PackageComparison*>(dynamic_cast<TESPackage*>(form));
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(other)))
        return true;
    if (GetPackType() != other->GetPackType())
        return true;
    if (reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel() != reinterpret_cast<::BGSTerrainManager *>((other))->GetMinLevel())
        return true;
    if (f22 != other->f22)
        return true;
    if (f24 != other->f24)
        return true;
    if (((::PackageComparisonNode *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
    {
        if (((::PackageComparisonNode *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))->Differs(((::PackageComparisonNode *)(reinterpret_cast<::BGSCameraPath *>((other))->GetPrevPath()))))
            return true;
    }
    else if (((::PackageComparisonNode *)(reinterpret_cast<::BGSCameraPath *>((other))->GetPrevPath())))
    {
        return true;
    }
    if (FUN_0055b980())
    {
        if (reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((FUN_0055b980()))->IsDifferentFrom(other->FUN_0055b980()))
            return true;
    }
    else if (other->FUN_0055b980())
    {
        return true;
    }
    if (reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0())
    {
        if (reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()))->IsDifferentFrom(reinterpret_cast<::FUN_00672dd0_shell *>((other))->FUN_00672dd0()))
            return true;
    }
    else if (reinterpret_cast<::FUN_00672dd0_shell *>((other))->FUN_00672dd0())
    {
        return true;
    }
    if (((::PackageTargetComparison *)(reinterpret_cast<::Script *>(this)->GetData())))
    {
        if (reinterpret_cast<::FUN_00680220_shell *>((((::PackageTargetComparison *)(reinterpret_cast<::Script *>(this)->GetData()))))->Compare((::PackageTargetRecord *)(::PackageTargetComparison *)(((::PackageTargetComparison *)(reinterpret_cast<::Script *>((other))->GetData())))))
            return true;
    }
    else if (((::PackageTargetComparison *)(reinterpret_cast<::Script *>((other))->GetData())))
    {
        return true;
    }
    if (((::PackageListComparison *)(reinterpret_cast<::FUN_0041d8a0_shell *>(this)->FUN_0041d8a0())))
    {
        if (((::PackageListComparison *)(reinterpret_cast<::FUN_0041d8a0_shell *>(this)->FUN_0041d8a0()))->FUN_0067fe10(((::PackageListComparison *)(reinterpret_cast<::FUN_0041d8a0_shell *>((other))->FUN_0041d8a0()))))
            return true;
    }
    else if (((::PackageListComparison *)(reinterpret_cast<::FUN_0041d8a0_shell *>((other))->FUN_0041d8a0())))
    {
        return true;
    }
    if (((::PackageSpellComparison *)(reinterpret_cast<::PackedByteIntRecord *>(this)->Endian())))
    {
        if (reinterpret_cast<::PerkEntryConditionSet *>((((::PackageSpellComparison *)(reinterpret_cast<::PackedByteIntRecord *>(this)->Endian()))))->Compare((::PerkEntryConditionSet *)(::PackageSpellComparison *)(((::PackageSpellComparison *)(reinterpret_cast<::PackedByteIntRecord *>((other))->Endian())))))
            return true;
    }
    else if (((::PackageSpellComparison *)(reinterpret_cast<::PackedByteIntRecord *>((other))->Endian())))
    {
        return true;
    }
    if (FUN_006733e0())
    {
        if (FUN_006733e0()->Differs(other->FUN_006733e0()))
            return true;
    }
    else if (other->FUN_006733e0())
    {
        return true;
    }
    if (data && other->data)
    {
        if (reinterpret_cast<PackagePatrolComparison*>(data)->Differs(
                reinterpret_cast<PackagePatrolComparison*>(other->data)))
            return true;
    }
    else if (data || other->data)
    {
        return true;
    }
    if (reinterpret_cast<::FUN_0067dbf0_shell *>(&(onBegin))->FUN_0067dbf0((::TESObjectREFR_GetFlags_caller *)(&other->onBegin)))
        return true;
    if (reinterpret_cast<::FUN_0067dbf0_shell *>(&(onEnd))->FUN_0067dbf0((::TESObjectREFR_GetFlags_caller *)(&other->onEnd)))
        return true;
    if (reinterpret_cast<::FUN_0067dbf0_shell *>(&(onChange))->FUN_0067dbf0((::TESObjectREFR_GetFlags_caller *)(&other->onChange)))
        return true;
    return false;
}

class PackageInit;

class FUN_00670b30_ctx
{
  public:
    ~FUN_00670b30_ctx();
};

class FUN_0067f030_ctx : public FUN_00670b30_ctx
{
  public:
    unsigned int type, value;
    float radius;
    FUN_0067f030_ctx();
    ~FUN_0067f030_ctx();
};

class FUN_0067ff70
{
  public:
    unsigned int type, target, count, unknown;
    FUN_0067ff70();
    ~FUN_0067ff70();
};

struct ConditionInit
{
};

struct IdleInit
{
};

struct ProcedureInit
{
    unsigned int unk00, unk04, unk08, unk0c;
};

struct PackageDataInit
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Init(PackageInit*);
    unsigned char unk04, flag05;
};

class TESForm_ctx
{
  public:
    virtual void unused();
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
public:
    ::TESFile *GetFile(int);
};

class TESCombatStyle : public TESForm_ctx
{
};

void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);

extern int DAT_0118627c;

class PackageInit
{
  public:
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetDebugName();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int flags18, packageFlags;
    unsigned char type, unk21;
    unsigned short unk22;
    unsigned int unk24;
    PackageDataInit* data;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    ProcedureInit begin, end, change;
    unsigned int FUN_006733e0();
    void FUN_00674930();
};

// @fnv 0x00674930
void PackageInit::FUN_00674930()
{
    if (reinterpret_cast<::TESForm_ctx *>(this)->GetInitialized())
        return;
    int warningsA = FUN_0046e8a0();
    if (((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
        reinterpret_cast<::LocationDescriptor *>((((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0())))
        reinterpret_cast<::LocationDescriptor *>((((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData())))
        reinterpret_cast<::PackageTargetRecord *>((((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((::ConditionInit *)(reinterpret_cast<::PackedByteIntRecord *>(this)->Endian())))
        reinterpret_cast<::PerkEntryConditionSet *>((((::ConditionInit *)(reinterpret_cast<::PackedByteIntRecord *>(this)->Endian()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((::IdleInit *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        reinterpret_cast<::BGSIdleCollection *>((((::IdleInit *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (data)
        data->Init(this);
    unsigned int kCombatStyle = FUN_006733e0();
    if (kCombatStyle)
    {
        ::ResolveFormID(&kCombatStyle, (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm_ctx *>(this)->GetFile(-1)))));
        reinterpret_cast<::TESPackage *>(this)->pCombatStyle = dynamic_cast<TESCombatStyle*>(FUN_004839c0(kCombatStyle));
        if (!FUN_006733e0())
            ::FUN_005b5e40();
    }
    reinterpret_cast<::FUN_0041fd00_shell *>(&(begin))->FUN_0041fd00(0);
    reinterpret_cast<::FUN_0041fd00_shell *>(&(end))->FUN_0041fd00(1);
    reinterpret_cast<::FUN_0041fd00_shell *>(&(change))->FUN_0041fd00(2);
    reinterpret_cast<::PackageEventActionData *>(&(begin))->InitItem((::TESForm *)(::PackageInit *)(this));
    reinterpret_cast<::PackageEventActionData *>(&(end))->InitItem((::TESForm *)(::PackageInit *)(this));
    reinterpret_cast<::PackageEventActionData *>(&(change))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (warningsA != FUN_0046e8a0())
    {
        ::FUN_005b5e40(
            );
        packageFlags |= 0x8000;
    }
    switch (reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get())
    {
    case 9:
        if (reinterpret_cast<::TESPackage *>(this)->FUN_00674d20())
            reinterpret_cast<::FUN_0067f140_shell *>((((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->FUN_0067f140(6);
        break;
    case 14:
        if (reinterpret_cast<::TESPackage *>(this)->FUN_00674d20())
        {
            if (!((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData())))
                reinterpret_cast<::FUN_00672fc0_shell *>(this)->FUN_00672fc0((::PackageTargetRecord *)(class ::FUN_0067ff70 *)(new FUN_0067ff70));
            reinterpret_cast<::PackageTargetRecord *>((((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData()))))->SetTargetKind((::PACK_TARG_TYPE)(3));
        }
        break;
    case 13: {
        PackageDataInit* packageData_2 = data;
        if (packageData_2->flag05)
            reinterpret_cast<::FUN_0067f140_shell *>((((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->FUN_0067f140(6);
        if (!((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
        {
            FUN_0067f030_ctx* location = new FUN_0067f030_ctx;
            reinterpret_cast<::FUN_0067f140_shell *>((location))->FUN_0067f140(6);
            reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>(this)->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(location));
            delete static_cast<FUN_00670b30_ctx*>(location);
        }
        break;
    }
    case 12:
        if (reinterpret_cast<::TESPackage *>(this)->FUN_00673890())
            reinterpret_cast<::FUN_0067f140_shell *>((((struct ::FUN_0067f030_ctx *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->FUN_0067f140(6);
        break;
    }
    reinterpret_cast<::TESForm_ctx *>(this)->SetInitializationState(1);
}



struct A;

struct P;

struct Proc_rtti;

struct Target;

struct Loc_rtti;

struct P : TESPackage
{
};

struct TESObjectREFR;

class FleePackage : public P
{
  public:
public:
    void FUN_009f1310(::TESObjectREFR *);
};

struct Created : P
{
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
    Created(A*);
};

struct Loc_rtti
{
    int unk00, unk04, unk08;
    Loc_rtti();
    ~Loc_rtti();
};

struct Target
{
    int unk00, unk04, unk08, unk0c;
    Target();
    ~Target();
};

struct Cls
{
};

struct List
{
    int GetSize();
};

struct Lists
{
};

struct SettingLocal
{
};

struct Proc_rtti
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void Reset();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual A* GetTarget();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual void unused125();
    virtual void unused126();
    virtual void unused127();
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void Prepare();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void unused138();
    virtual P* GetAssignedPackage();
    virtual void unused140();
    virtual void unused141();
    virtual void unused142();
    virtual void unused143();
    virtual void unused144();
    virtual void unused145();
    virtual void unused146();
    virtual void unused147();
    virtual void unused148();
    virtual void unused149();
    virtual void unused150();
    virtual void unused151();
    virtual void unused152();
    virtual void unused153();
    virtual void unused154();
    virtual void unused155();
    virtual void unused156();
    virtual void unused157();
    virtual void unused158();
    virtual void unused159();
    virtual void unused160();
    virtual void SetValue(int);
    virtual void unused162();
    virtual void unused163();
    virtual void unused164();
    virtual void unused165();
    virtual void unused166();
    virtual void unused167();
    virtual void unused168();
    virtual void unused169();
    virtual void unused170();
    virtual void unused171();
    virtual void unused172();
    virtual void unused173();
    virtual void unused174();
    virtual void unused175();
    virtual void unused176();
    virtual void unused177();
    virtual void unused178();
    virtual void unused179();
    virtual void unused180();
    virtual void unused181();
    virtual void unused182();
    virtual void unused183();
    virtual void unused184();
    virtual void unused185();
    virtual void unused186();
    virtual void unused187();
    virtual void unused188();
    virtual void unused189();
    virtual void unused190();
    virtual void unused191();
    virtual void unused192();
    virtual void unused193();
    virtual void unused194();
    virtual void unused195();
    virtual void unused196();
    virtual void unused197();
    virtual void unused198();
    virtual void unused199();
    virtual void unused200();
    virtual void unused201();
    virtual void unused202();
    virtual void unused203();
    virtual void unused204();
    virtual void unused205();
    virtual void unused206();
    virtual void Respond(A*, A*, int, int, int, int, int, int, int, int, int, int, int);
    virtual void unused208();
    virtual void React(A*, A*, A*);
    virtual void SetCount(int);
    virtual void unused211();
    virtual void unused212();
    virtual void unused213();
    virtual void unused214();
    virtual void unused215();
    virtual void unused216();
    virtual void unused217();
    virtual void unused218();
    virtual void unused219();
    virtual void unused220();
    virtual void unused221();
    virtual void unused222();
    virtual void unused223();
    virtual void unused224();
    virtual void unused225();
    virtual void unused226();
    virtual void unused227();
    virtual void unused228();
    virtual void unused229();
    virtual void unused230();
    virtual void unused231();
    virtual void unused232();
    virtual void unused233();
    virtual void unused234();
    virtual void unused235();
    virtual void unused236();
    virtual void unused237();
    virtual void unused238();
    virtual void unused239();
    virtual void unused240();
    virtual void unused241();
    virtual void unused242();
    virtual void unused243();
    virtual void unused244();
    virtual void unused245();
    virtual void unused246();
    virtual void unused247();
    virtual void unused248();
    virtual void unused249();
    virtual void unused250();
    virtual void unused251();
    virtual void unused252();
    virtual void unused253();
    virtual void unused254();
    virtual void unused255();
    virtual void unused256();
    virtual void unused257();
    virtual void unused258();
    virtual void unused259();
    virtual void unused260();
    virtual void unused261();
    virtual void unused262();
    virtual void unused263();
    virtual void unused264();
    virtual void unused265();
    virtual void unused266();
    virtual void unused267();
    virtual void unused268();
    virtual void unused269();
    virtual void unused270();
    virtual void unused271();
    virtual void unused272();
    virtual void unused273();
    virtual void unused274();
    virtual void unused275();
    virtual void unused276();
    virtual void unused277();
    virtual void unused278();
    virtual void unused279();
    virtual void unused280();
    virtual void unused281();
    virtual void unused282();
    virtual void unused283();
    virtual void unused284();
    virtual void unused285();
    virtual void unused286();
    virtual void unused287();
    virtual void unused288();
    virtual void unused289();
    virtual void unused290();
    virtual void unused291();
    virtual void unused292();
    virtual void unused293();
    virtual void unused294();
    virtual void unused295();
    virtual void unused296();
    virtual void unused297();
    virtual void unused298();
    virtual void unused299();
    virtual void unused300();
    virtual void unused301();
    virtual void unused302();
    virtual void unused303();
    virtual void unused304();
    virtual void unused305();
    virtual void unused306();
    virtual void unused307();
    virtual void unused308();
    virtual void unused309();
    virtual void unused310();
    virtual void unused311();
    virtual void unused312();
    virtual void unused313();
    virtual void unused314();
    virtual void unused315();
    virtual void unused316();
    virtual void unused317();
    virtual void unused318();
    virtual void unused319();
    virtual void unused320();
    virtual void unused321();
    virtual void unused322();
    virtual void unused323();
    virtual void unused324();
    virtual void unused325();
    virtual void unused326();
    virtual void unused327();
    virtual void unused328();
    virtual void unused329();
    virtual void unused330();
    virtual void unused331();
    virtual void unused332();
    virtual void unused333();
    virtual void unused334();
    virtual void unused335();
    virtual void unused336();
    virtual void unused337();
    virtual void unused338();
    virtual void unused339();
    virtual void unused340();
    virtual void unused341();
    virtual void unused342();
    virtual void unused343();
    virtual void unused344();
    virtual void unused345();
    virtual void unused346();
    virtual void unused347();
    virtual void unused348();
    virtual void unused349();
    virtual void unused350();
    virtual void unused351();
    virtual void unused352();
    virtual void unused353();
    virtual void unused354();
    virtual void unused355();
    virtual void unused356();
    virtual void unused357();
    virtual void unused358();
    virtual void unused359();
    virtual void unused360();
    virtual void unused361();
    virtual void unused362();
    virtual void unused363();
    virtual void unused364();
    virtual void unused365();
    virtual void unused366();
    virtual void unused367();
    virtual int GetCount();
    virtual void SetFlag(int);
    virtual void unused370();
    virtual void unused371();
    virtual void unused372();
    virtual void unused373();
    virtual void unused374();
    virtual void unused375();
    virtual void unused376();
    virtual void unused377();
    virtual void unused378();
    virtual void unused379();
    virtual void unused380();
    virtual void unused381();
    virtual void unused382();
    virtual void unused383();
    virtual void unused384();
    virtual void unused385();
    virtual void unused386();
    virtual void unused387();
    virtual void unused388();
    virtual void unused389();
    virtual void unused390();
    virtual void unused391();
    virtual void unused392();
    virtual void unused393();
    virtual void unused394();
    virtual void unused395();
    virtual void unused396();
    virtual void unused397();
    virtual void unused398();
    virtual void unused399();
    virtual void unused400();
    virtual void unused401();
    virtual void unused402();
    virtual void unused403();
    virtual void unused404();
    virtual void unused405();
    virtual void unused406();
    virtual void unused407();
    virtual void unused408();
    virtual void unused409();
    virtual void unused410();
    virtual void unused411();
    virtual void unused412();
    virtual void unused413();
    virtual void unused414();
    virtual void unused415();
    virtual void unused416();
    virtual void unused417();
    virtual void unused418();
    virtual void unused419();
    virtual void unused420();
    virtual void unused421();
    virtual void unused422();
    virtual void unused423();
    virtual void unused424();
    virtual void unused425();
    virtual void unused426();
    virtual void unused427();
    virtual void unused428();
    virtual void unused429();
    virtual void unused430();
    virtual void unused431();
    virtual void unused432();
    virtual void unused433();
    virtual void unused434();
    virtual void unused435();
    virtual void unused436();
    virtual void unused437();
    virtual void unused438();
    virtual void unused439();
    virtual void unused440();
    virtual void unused441();
    virtual void unused442();
    virtual void unused443();
    virtual void unused444();
    virtual void unused445();
    virtual void unused446();
    virtual void unused447();
    virtual void unused448();
    virtual void unused449();
    virtual void unused450();
    virtual void unused451();
    virtual void Notify(A*);
};

struct A
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual void unused125();
    virtual void unused126();
    virtual void unused127();
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual int GetType();
    virtual bool IsActor();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void unused138();
    virtual bool IsState(int);
    virtual void unused140();
    virtual void unused141();
    virtual void unused142();
    virtual void unused143();
    virtual void unused144();
    virtual void unused145();
    virtual void unused146();
    virtual void unused147();
    virtual void unused148();
    virtual void unused149();
    virtual void unused150();
    virtual void unused151();
    virtual void unused152();
    virtual void unused153();
    virtual void unused154();
    virtual void unused155();
    virtual void unused156();
    virtual void unused157();
    virtual void unused158();
    virtual void unused159();
    virtual void unused160();
    virtual void unused161();
    virtual void unused162();
    virtual void unused163();
    virtual void unused164();
    virtual void unused165();
    virtual void unused166();
    virtual void unused167();
    virtual void unused168();
    virtual void unused169();
    virtual void unused170();
    virtual void unused171();
    virtual void unused172();
    virtual void unused173();
    virtual void unused174();
    virtual void unused175();
    virtual void unused176();
    virtual void unused177();
    virtual void unused178();
    virtual void unused179();
    virtual void unused180();
    virtual void unused181();
    virtual void unused182();
    virtual void unused183();
    virtual void unused184();
    virtual void unused185();
    virtual void unused186();
    virtual void unused187();
    virtual void unused188();
    virtual void SetPackage(P*, int, int);
    virtual void unused190();
    virtual void unused191();
    virtual void unused192();
    virtual bool IsSpecial();
    virtual void unused194();
    virtual void unused195();
    virtual void unused196();
    virtual void unused197();
    virtual void unused198();
    virtual void unused199();
    virtual void unused200();
    virtual void unused201();
    virtual void unused202();
    virtual void unused203();
    virtual void unused204();
    virtual void unused205();
    virtual void unused206();
    virtual void unused207();
    virtual void unused208();
    virtual void unused209();
    virtual void unused210();
    virtual void unused211();
    virtual void unused212();
    virtual void unused213();
    virtual void unused214();
    virtual void unused215();
    virtual void unused216();
    virtual void unused217();
    virtual void unused218();
    virtual void unused219();
    virtual void unused220();
    virtual void unused221();
    virtual void unused222();
    virtual void unused223();
    virtual void unused224();
    virtual void unused225();
    virtual void unused226();
    virtual void unused227();
    virtual void unused228();
    virtual void unused229();
    virtual void unused230();
    virtual void unused231();
    virtual void unused232();
    virtual void unused233();
    virtual void unused234();
    virtual void unused235();
    virtual void unused236();
    virtual void unused237();
    virtual void unused238();
    virtual void unused239();
    virtual void unused240();
    virtual void unused241();
    virtual void unused242();
    virtual void unused243();
    virtual void unused244();
    virtual void unused245();
    virtual void unused246();
    virtual void unused247();
    virtual void unused248();
    virtual void unused249();
    virtual void unused250();
    virtual void unused251();
    virtual void unused252();
    virtual void unused253();
    virtual void unused254();
    virtual void unused255();
    virtual void unused256();
    virtual void unused257();
    virtual void unused258();
    virtual void unused259();
    virtual void Flee(A*, int, int, int, int, int, float, float);
    virtual void unused261();
    virtual void ResetState();
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
    Proc_rtti* process;
    void FUN_008bed50(A*, int, bool, A*);
};

struct Extra
{
};

// @fnv 0x008bed50
void A::FUN_008bed50(A* source, int value, bool react, A* target)
{
    if (process && process->GetAssignedPackage() && reinterpret_cast<struct ::FUN_0041ca90 *>((process->GetAssignedPackage()))->get() == 21)
        return;
    if (IsSpecial())
    {
        if (source && !target)
            target = ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()));
        List* val;
        val = ((::List *)(reinterpret_cast<::ZOwner *>(&((*reinterpret_cast<::Lists *>(&::g_011e0e80))))->CollectActorsByPackage((std::intptr_t)(target), 21, 0)));
        if (!val)
            ((::Proc_rtti *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->SetCount(0);
        else
            ((::Proc_rtti *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->SetCount(val->GetSize());
        if (target && ((::Proc_rtti *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->GetCount() >= *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingLocal *>(&::g_011cd808)))))))
        {
            return;
        }
        else if (target)
        {
            if (target == (*reinterpret_cast<::A * *>(&::_g_thePlayer)) && ((unsigned char)(reinterpret_cast<::FUN_008a08c0_Class *>(((*reinterpret_cast<::A * *>(&::_g_thePlayer))))->GetByteAt7C4())))
            {
                process->Respond(this, target, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
                return;
            }
            else
                ((::Proc_rtti *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->SetFlag(1);
        }
    }
    if (GetType() == 9)
        ResetState();
    P* v = 0;
    P* package2;
    package2 = ((::P *)(reinterpret_cast<::Thing *>(this)->FUN_00881510()));
    if (package2 && reinterpret_cast<::TESPackage *>((package2))->IsPackageBlockingGreeting())
        package2 = ((::P *)(reinterpret_cast<::FUN_0041cb10_shell *>((((Extra*)((::P *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0())))))->FUN_0041cb10()));
    if ((((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0())) || IsState(0) || reinterpret_cast<::FleeActorEntry *>(this)->FUN_008a6650(0) ||
         (package2 && reinterpret_cast<::FUN_0067a3f0_shell *>((package2))->HasFlag400000() && source &&
          ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((source))->GetName())) != (unsigned int)(std::uintptr_t)process->GetTarget())) &&
        react)
    {
        if (!IsState(0) && !((bool)(reinterpret_cast<::FUN_00833c20_shell *>((source))->FUN_00833c20())))
            process->React(this, ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0())), source);
        return;
    }
    process->Prepare();
    if (((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0())))
    {
        if (reinterpret_cast<struct ::FUN_0041ca90 *>((((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()))))->get() == 21)
            v = ((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()));
        else if (reinterpret_cast<::TESPackage *>((((::P *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()))))->IsPackageBlockingGreeting())
            reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>(this)->FUN_00881680(0);
    }
    if (source && reinterpret_cast<::TESClass *>((((::Cls *)(reinterpret_cast<::fnv_00884350::FUN_00884350_shell *>(this)->FUN_00884350()))))->IsGuard())
    {
        reinterpret_cast<::FUN_008bf4e0_cls *>((source))->set(1);
        if (((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))->IsActor() && ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0())) != (*reinterpret_cast<::A * *>(&::_g_thePlayer)) &&
            !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))))->FUN_00493bb0())) && reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))))->FUN_005653d0())
        {
            A* locationX;
            locationX = ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()));
            if (!reinterpret_cast<::FleeActorEntry *>((locationX))->FUN_008a6650(0))
                locationX->Flee(this, 0, 1, 1, 0, 0, -1.0f, -1.0f);
            FleePackage* flee;
            flee = dynamic_cast<FleePackage*>(static_cast<TESPackage*>(((::P *)(reinterpret_cast<::FUN_009344a0_shell *>((locationX))->FUN_009344a0()))));
            if (flee)
                flee->FUN_009f1310((::TESObjectREFR *)(::A *)(this));
        }
    }
    if (!v)
    {
        P* tmp = ((::Proc_rtti *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->GetAssignedPackage();
        Created* current;
        current = new Created(source);
        reinterpret_cast<::PackageEx *>((current))->SetPackageType(21);
        if (tmp)
        {
            reinterpret_cast<::FUN_00671a20_shell *>((current))->FUN_00671a20(reinterpret_cast<::FUN_0067a460_shell *>((tmp))->FUN_0067a460());
            reinterpret_cast<::FUN_0067a640_shell *>((current))->SetFlag200000(reinterpret_cast<::TESPackage *>((tmp))->GetForceUnequipWeapon());
        }
        reinterpret_cast<::TESPackage *>((current))->SetMustReachLocation(true);
        reinterpret_cast<::TESPackage *>((current))->SetMustComplete(true);
        Loc_rtti* s = new Loc_rtti;
        if (source)
            reinterpret_cast<::LocationDescriptor *>((s))->FUN_0067f3c0((::TESObjectREFR *)(::A *)(((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))));
        else
            reinterpret_cast<::LocationDescriptor *>((s))->FUN_0067f3c0((::TESObjectREFR *)(target));
        reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((current))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(s));
        delete s;
        Target* created;
        created = new Target;
        reinterpret_cast<::FUN_00672fc0_shell *>((current))->FUN_00672fc0((::PackageTargetRecord *)(created));
        delete created;
        reinterpret_cast<::TESPackage *>((current))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(11));
        reinterpret_cast<::PackageTargetRecord *>((((::Target *)(reinterpret_cast<::Script *>((current))->GetData()))))->SetTargetKind((::PACK_TARG_TYPE)(0));
        if (source)
            reinterpret_cast<::PackageTargetRecord *>((((::Target *)(reinterpret_cast<::Script *>((current))->GetData()))))->SetTargetObjectReference((::TESObjectREFR *)(::A *)(((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()))));
        else
            reinterpret_cast<::PackageTargetRecord *>((((::Target *)(reinterpret_cast<::Script *>((current))->GetData()))))->SetTargetObjectReference((::TESObjectREFR *)(target));
        ((::Proc_rtti *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Reset();
        ((::Proc_rtti *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Notify(this);
        SetPackage(current, 0, 1);
        if (source)
            reinterpret_cast<::fnv_009eb9c0::Crime *>((source))->AddActor((::Actor *)(::A *)(this));
        process->SetValue(value);
    }
    else if (source && process->GetTarget() == ((::A *)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0())) && !reinterpret_cast<::fnv_009ec810::FUN_009ec810_t *>((v))->IsSpellInList((::fnv_009ec810::SpellItem *)(source)))
        reinterpret_cast<::FUN_009ec830_t *>((v))->AddHeadAtOffset((int *)(source));
}

#include "generated/data/fallout_shared/package.inc"
