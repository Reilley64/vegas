
// src/fallout/ai/patrolpackage_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR, TESPackage). The skeleton of src/fallout/ai/patrolpackage.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_009f2ba0_shell.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0042f300__FUN_0042f300_shell.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/decl/fnv_009f30d0__FUN_009f30d0_shell.h"
#include "fnv/decl/fnv_009f31c0__PatrolData2.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_009f2000.h"
class TESObjectREFR;
class Actor;
class TESPackage;
class TESPatrolPackageData;
class NiPoint3;
class BGSLoadFormBuffer;
class TESForm;
class TESObjectWEAP;
class NavMeshInfo;
class BSSimpleArray_TESObjectWEAP___1024_
{
  public:
};
class BSSimpleArray_NavMeshInfo___1024_
{
  public:
};
class LocationDescriptor
{
  public:
    TESObjectREFR* GetLocationReference();
};
class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // the original class is polymorphic (rtti_variants.py)
  public:
};
class ArchiveManager
{
  public:
};
class TESPackage
{
  public:
    virtual ~TESPackage();  // the original class is polymorphic (rtti_variants.py)
  public:
    const TESPatrolPackageData* GetPackagePatrolData();
};
class BGSLoadGameBuffer
{
  public:
};
class BGSLoadFormBuffer
{
  public:
};
class TESForm
{
  public:
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
  public:
};
class PatrolActorPackageData
{
  public:
    void* vtable;
    bool flag;

    bool IsPatrolling();
};

// Adapted from another contributor's unverified prior attempt; credit retained.

class NavMeshInfo;
class LoadBuf
{
  public:
};
class NavInfoArray
{
  public:
};
struct PatrolLoadShell
{
    void* vtable;
    int iState;
    int unk08;
    bool bFlag0C;
    int unk10;
    TESPackage* pPackage;
    int unk18;
    NavInfoArray kArray;
    int unk20;
    int unk24;
    int unk28;
    bool bFlag2C;
    int unk30;
    int unk34;
    void FUN_009f34e0(LoadBuf* apBuffer);
};
// @fnv 0x009f34e0
void PatrolLoadShell::FUN_009f34e0(LoadBuf* apBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iState), 4);
    iState = (iState >= 0 && iState <= 2) ? iState : 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk08), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk34), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bFlag0C), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bFlag2C), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk30), 4);
    pPackage = dynamic_cast<TESPackage*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apBuffer))->FUN_008648a0()));
    unsigned int ItemUpdateArray = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apBuffer))->FUN_00864a60()));
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(kArray))->FUN_006f2290(ItemUpdateArray, true);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        NavMeshInfo*& rEntry = ((::NavMeshInfo *)(reinterpret_cast<::S3e60 *>(&(kArray))->FUN_006a7ad0(i)));
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apBuffer))->FUN_008648e0((unsigned int *)(void *)(&rEntry));
    }
}

struct ExtraHolder;

struct PatrolRef : public TESObjectREFR
{
};
struct ExtraHolder
{
};
struct PatrolActor
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
    virtual void* GetPatrolTarget();
};
struct PatrolPackage
{
};
struct PatrolLoadBuf
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual PatrolActor* GetActor();
};
struct PatrolRefArray
{
    void* vtbl;
    PatrolRef** pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    PatrolRef*& GetAt(unsigned int);
};
struct PatrolData9f3610
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    PatrolActor* pActor;
    PatrolPackage* pPackage;
    void* pPatrolRefData;
    PatrolRefArray kRefs;
    bool bRepeat;
    int unk30;
    unsigned int uiIndex;

    void FUN_009f3610(PatrolLoadBuf* apBuf);
};

// @fnv 0x009f3610
void PatrolData9f3610::FUN_009f3610(PatrolLoadBuf* apBuf)
{
    bool bAnyRemoved = false;
    unsigned int ItemUpdateArray = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kRefs))->GetName()));
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        bool bRemove = false;
        PatrolRef*& rRef = ((::PatrolRef *)(reinterpret_cast<::S3e60 *>(&(kRefs))->FUN_006a7ad0(i)));
        rRef =
            rRef ? reinterpret_cast<PatrolRef*>(dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)rRef)))
                 : 0;
        if (rRef)
        {
            reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((rRef))->FUN_00564db0(true);
        }
        else
        {
            bAnyRemoved = true;
            bRemove = true;
            uiIndex = uiIndex > 0 ? uiIndex - 1 : 0;
        }
        if (bRemove)
        {
            reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(kRefs))->FUN_009a4320(i, 1);
            i--;
            ItemUpdateArray--;
        }
    }
    pActor = apBuf->GetActor();
    if (pPackage)
    {
        if (!pPatrolRefData)
        {
            pPatrolRefData = ((void *)(reinterpret_cast<::TESPackage *>((pPackage))->GetPackagePatrolData()));
        }
        if (!reinterpret_cast<::fnv_009f30d0::FUN_009f30d0_shell *>(this)->SetPatrolRefIndex(uiIndex))
        {
            reinterpret_cast<::fnv_009f31c0::PatrolData2 *>(this)->SelectClosestPatrolPoint((*(const ::fnv_009f31c0::NiPoint3 *)(pActor->GetPatrolTarget())));
        }
        if (!reinterpret_cast<::FUN_0076b610_Class *>((void *)&(kRefs))->FUN_0076b610() && bRepeat)
        {
            PatrolRef* pRef = kRefs.GetAt(uiIndex);
            ExtraHolder* pExtraList = pRef ? ((::ExtraHolder *)(reinterpret_cast<::FUN_005d43c0_ *>((pRef))->FUN_005d43c0())) : 0;
            if (pExtraList)
            {
                reinterpret_cast<::fnv_0042f300::FUN_0042f300_shell *>((pExtraList))->FUN_0042f300((::TESObjectREFR *)(pActor));
            }
        }
    }
}
