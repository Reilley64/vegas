
// src/fallout/ai/middlehighprocess_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/middlehighprocess.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include <new>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DurationData.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00922000.h"
#include "fnv/symbols_0092a000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f6000.h"
#include "middlehighprocess_decls.h"

struct AcquireSortItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int sortKey;
};

struct AcquireSortNode
{
    int FUN_005ae380();
    void FUN_00726c60(AcquireSortItem** slot);
};

struct AcquireSortProcess : MiddleHighProcess
{
    void FUN_0091b640();
};

// @fnv 0x0091b640
void AcquireSortProcess::FUN_0091b640()
{
    AcquireSortNode* outer2 = (AcquireSortNode*)&ReferenceListNode;
    AcquireSortNode* inner5 = 0;
    if (outer2 != 0)
    {
        unsigned int count4 = outer2->FUN_005ae380();
        bool changed3 = true;
        while (count4 != 0 && changed3)
        {
            changed3 = false;
            inner5 = outer2;
            while (inner5 != 0)
            {
                AcquireSortItem* first2 = *((::AcquireSortItem **)(new ((void *)(outer2)) ::Vec3()));
                AcquireSortItem* second3 = *((::AcquireSortItem **)(new ((void *)(inner5)) ::Vec3()));
                if (first2->sortKey > second3->sortKey)
                {
                    outer2->FUN_00726c60(&second3);
                    inner5->FUN_00726c60(&first2);
                    changed3 = true;
                }
                inner5 = ((::AcquireSortNode *)(reinterpret_cast<::Callees *>((inner5))->FUN_00726070()));
            }
            outer2 = ((::AcquireSortNode *)(reinterpret_cast<::Callees *>((outer2))->FUN_00726070()));
            count4--;
        }
    }
}

namespace FurnitureSearchDetail {
using ::TESObjectREFR;
using ::TESForm;
using ::TESObjectCELL;
using ::Actor;
using ::NiPoint3;
using ::MiddleHighProcess;

struct FurnitureLocation
{
};
struct FurniturePackage
{
    ::NiPoint3 FUN_00675de0(::Actor*);
};
struct FurnitureCell
{
};
struct FurnitureRef : ::TESObjectREFR
{
};
struct FurnitureList
{
    void FUN_005ae3d0(::TESObjectREFR*&);
    unsigned int FUN_005ae380();
    void FUN_00726c60(::TESObjectREFR* const&);
};
struct FurnitureSetting
{
};
struct FurnitureSearchManager
{
};
struct FurnitureTime
{
};
struct SearchFurnitureProcess : ::MiddleHighProcess
{
    void FUN_00922670(::Actor*, bool, ::TESObjectREFR*);
};
// @fnv 0x00922670
void SearchFurnitureProcess::FUN_00922670(::Actor* actor, bool flag, ::TESObjectREFR* target)
{
    DAT_011e040c = flag;
    ::TESObjectCELL* a = actor->GetParentCell();
    ::NiPoint3 p = *actor->GetPos();
    FurniturePackage* f = reinterpret_cast<FurniturePackage*>(GetOneTimePackage());
    if (!f || !actor)
        return;
    FurnitureLocation* s = ((::FurnitureSearchDetail::FurnitureLocation *)(reinterpret_cast<::BGSMessageInitAccess *>((f))->GetIconFormID()));
    float i = 0.0f;
    if (reinterpret_cast<struct ::FUN_0041ca90 *>((f))->get() == 3)
    {
        if (s && reinterpret_cast<::DurationData *>((s))->FUN_00678ca0() == 1 && reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<FurnitureCell*>(reinterpret_cast<::LocationDescriptor *>((s))->GetLocationCellReference())))->IsCellInterior())
            i = 3.402823466e38f;
        else
            i = static_cast<float>(reinterpret_cast<::HighProcess *>((f))->UpdateHighProcessState(actor));
    }
    else if (!reinterpret_cast<::TESPackage *>((f))->GetPackageSearchRadius((::MobileObject *)(actor), (*(float *)(&i))))
    {
        if (s && reinterpret_cast<::DurationData *>((s))->FUN_00678ca0() == 1 && reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<FurnitureCell*>(reinterpret_cast<::LocationDescriptor *>((s))->GetLocationCellReference())))->IsCellInterior())
            i = 3.402823466e38f;
        else
            i = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FurnitureSearchDetail::FurnitureSetting *>(&::originalRuntimeFloatSetting133))))));
    }
    if (target)
    {
        ::NiPoint3* targetPosition = target->GetPos();
        reinterpret_cast<::TESDataHandler *>((reinterpret_cast<FurnitureSearchManager*>((*reinterpret_cast<::FurnitureSearchDetail::FurnitureSearchManager * *>(&::g_dataHandler)))))->GetReferencesInArea(target->GetParentCell(), *targetPosition, i, *targetPosition, i, (bool (*)(TESObjectREFR *, long))(((void (&)(TESObjectREFR *, Actor *))::fnv_00922960::FUN_00922960)), (long)(actor));
    }
    else
    {
        reinterpret_cast<::TESDataHandler *>((reinterpret_cast<FurnitureSearchManager*>((*reinterpret_cast<::FurnitureSearchDetail::FurnitureSearchManager * *>(&::g_dataHandler)))))->GetReferencesInArea(a, p, i, f->FUN_00675de0(actor), i, (bool (*)(TESObjectREFR *, long))(((void (&)(TESObjectREFR *, Actor *))::fnv_00922960::FUN_00922960)), (long)(actor));
    }
    reinterpret_cast<::FileMatchList *>((reinterpret_cast<FurnitureList*>(&m_kSecondaryReferenceList)))->RemoveAll();
    FurnitureList* cf = &(*reinterpret_cast<::FurnitureSearchDetail::FurnitureList *>(&::g_011e0424));
    while (cf && ((::TESObjectREFR *)(new ((void *)(cf)) ::Vec3())))
    {
        reinterpret_cast<FurnitureList*>(&m_kSecondaryReferenceList)->FUN_005ae3d0(((::TESObjectREFR *)(new ((void *)(cf)) ::Vec3())));
        cf = ((::FurnitureSearchDetail::FurnitureList *)(reinterpret_cast<::Callees *>((cf))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::FurnitureSearchDetail::FurnitureList *>(&::g_011e0424))))->RemoveAll();
    FurnitureList* eb = reinterpret_cast<FurnitureList*>(&m_kSecondaryReferenceList);
    FurnitureList* h = 0;
    if (eb)
    {
        unsigned int item2 = eb->FUN_005ae380();
        bool first = true;
        while (item2 && first)
        {
            first = false;
            h = eb;
            while (h)
            {
                ::TESObjectREFR* barterA = ((::TESObjectREFR *)(new ((void *)(eb)) ::Vec3()));
                ::TESObjectREFR* found = ((::TESObjectREFR *)(new ((void *)(h)) ::Vec3()));
                if (!reinterpret_cast<::OwnerLookupView *>((static_cast<FurnitureRef*>(barterA)))->FUN_00567790() &&
                    reinterpret_cast<::OwnerLookupView *>((static_cast<FurnitureRef*>(found)))->FUN_00567790())
                {
                    eb->FUN_00726c60(found);
                    h->FUN_00726c60(barterA);
                    first = true;
                }
                h = ((::FurnitureSearchDetail::FurnitureList *)(reinterpret_cast<::Callees *>((h))->FUN_00726070()));
            }
            eb = ((::FurnitureSearchDetail::FurnitureList *)(reinterpret_cast<::Callees *>((eb))->FUN_00726070()));
            --item2;
        }
    }
    m_uiFaceGenDataFlags = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::FurnitureSearchDetail::FurnitureTime *>(&::g_timeGlobal))))->FUN_00825c00();
}

}

class TESClass
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

template <> class BSSimpleList<TESClass*>
{
  public:
    void SetItem(TESClass*& item);
    int GetSize();
};

struct Holder91b580
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
    BSSimpleList<TESClass*> m_kNode;
    void FUN_0091b580();
};

// @fnv 0x0091b580
void Holder91b580::FUN_0091b580()
{
    BSSimpleList<TESClass*>* pOuter = &m_kNode;
    BSSimpleList<TESClass*>* pInner3 = 0;
    if (pOuter)
    {
        int iCount2 = pOuter->GetSize();
        bool bSwapped3 = true;
        TESClass* itemA;
        TESClass* itemB;
        while (iCount2 != 0 && bSwapped3)
        {
            bSwapped3 = false;
            pInner3 = pOuter;
            while (pInner3 != 0)
            {
                itemA = ((::TESClass *)(new ((void *)(pOuter)) ::Vec3()));
                itemB = ((::TESClass *)(new ((void *)(pInner3)) ::Vec3()));
                if (itemA->unk18 > itemB->unk18)
                {
                    pOuter->SetItem(itemB);
                    pInner3->SetItem(itemA);
                    bSwapped3 = true;
                }
                pInner3 = ((::BSSimpleList< ::TESClass *> *)(reinterpret_cast<::Callees *>((pInner3))->FUN_00726070()));
            }
            pOuter = ((::BSSimpleList< ::TESClass *> *)(reinterpret_cast<::Callees *>((pOuter))->FUN_00726070()));
            iCount2--;
        }
    }
}
