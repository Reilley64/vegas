
// src/fallout_shared/tesworldspace_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectCELL, TESWorldSpace). The skeleton of src/fallout_shared/tesworldspace.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/CPMap00993a80.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/CombatThreatMap.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00484150_shell.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_00586280_shell.h"
#include "fnv/decl/FUN_00588070_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/SomeClass.h"
#include "fnv/decl/TESFormSortProxy.h"
#include "fnv/decl/Unk00586340.h"
#include "fnv/decl/UpdateOwner.h"
#include "fnv/decl/fnv_0054db50__FUN_0054db50_cls.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "tesworldspace_packet_rtti_variant.h"

struct GROUP_HEADER
{
    unsigned int uiType;
    unsigned int uiSize;
    unsigned int uiLabel;
    int iGroupType;
};
class FormGroupOwner
{
  public:
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
    virtual bool IsParentForm(TESForm* pkForm);
    bool FUN_00584d40(GROUP_HEADER* pkGroup);
};
// @fnv 0x00584d40
bool FormGroupOwner::FUN_00584d40(GROUP_HEADER* pkGroup)
{
    bool bResult = false;
    if (pkGroup && pkGroup->uiType == ::fnv_00543df0::kGroupFormType)
    {
        switch (pkGroup->iGroupType)
        {
        case 0:
            bResult = reinterpret_cast<::FUN_00484150_shell *>(this)->IsFormTypeBelowThreshold((::FormRecordHeader *)(pkGroup));
            break;
        case 2:
        case 3:
            bResult = false;
            break;
        case 6: {
            TESObjectCELL* pkCell = dynamic_cast<TESObjectCELL*>(FUN_004839c0(pkGroup->uiLabel));
            if (pkCell)
                bResult = IsParentForm((TESForm*)pkCell);
        }
        break;
        case 4:
        case 5:
            break;
        case 1: {
            TESWorldSpace* pkWorld = dynamic_cast<TESWorldSpace*>(FUN_004839c0(pkGroup->uiLabel));
            if (pkWorld)
                bResult = IsParentForm((TESForm*)pkWorld);
        }
        break;
        case 7:
            bResult = true;
            break;
        }
    }
    return bResult;
}

class MobileObject : public TESObjectREFR
{
};
class Actor : public MobileObject
{
};
struct MapPosition532;
struct FUN_00993820
{
    virtual ~FUN_00993820();
    unsigned int bucketCount;
    MapPosition532** buckets;
    unsigned int size;
    FUN_00993820(int);
    void SetValue(Actor*, unsigned __int64);
};
struct Child532
{
};
struct Tail532
{
};
struct ReferenceArray532
{
    virtual ~ReferenceArray532();
    Child532** data;
    unsigned short capacity, size, effectiveSize, grow;
    Child532*& FUN_00877a30(unsigned int);
};
struct CombatGroup532 : ReferenceArray532
{
    FUN_00993820* map;
    Tail532* tail;
    void FUN_00993600(void* stream);
};
// @fnv 0x00993600
void CombatGroup532::FUN_00993600(void* stream)
{
    FUN_00993820* oldMapX = map;
    map = new FUN_00993820(0x25);
    MapPosition532* position = ((::MapPosition532 *)(reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((oldMapX))->GetFirstPos()));
    Actor* actor_;
    unsigned __int64 valueTmp;
    unsigned int index;
    Child532* child2;
    while (position)
    {
        reinterpret_cast<::CPMap00993a80 *>((oldMapX))->GetNextEntry((::CPMapItem00993a80 *&)(position), (unsigned int *)&(actor_), (unsigned long long *)&(valueTmp));
        // Persisted pointer-map keys hold a 32-bit form identifier until fixup.
        actor_ = actor_ ? dynamic_cast<Actor*>(FUN_004839c0((unsigned int)actor_)) : 0;
        if (actor_)
            map->SetValue(actor_, valueTmp);
    }
    reinterpret_cast<::FUN_00438af0_Class *>((oldMapX))->FUN_00438af0();
    delete oldMapX;
    for (index = 0; index < reinterpret_cast<::FUN_00658930_class *>(this)->GetShortAtOffsetA(); ++index)
    {
        child2 = FUN_00877a30(index);
        if (child2)
            reinterpret_cast<::UpdateOwner *>((child2))->UpdateElements((unsigned int)(stream));
    }
    reinterpret_cast<::CombatThreatMap *>((tail))->ApplyLoadBuffer((::BGSLoadGameBuffer *)(stream));
}

class TESClimate : public TESForm
{
};
class TESImageSpace : public TESForm
{
};
class BGSEncounterZone : public TESForm
{
};
class TESWaterForm : public TESForm
{
};
class BGSMusicType : public TESForm
{
};


class TESObjectCELL5845
{
  public:
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
    virtual void LinkPersistent();
};

class CellMap5845
{
  public:
};

class WorldSpaceOwner5845;
class WorldSpaceLOD5845
{
  public:
    WorldSpaceLOD5845(WorldSpaceOwner5845* pkWorld);
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
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
};

class WorldSpaceRegion5845
{
  public:
};

class WorldSpaceOwner5845
{
  public:
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
    virtual const char* GetEditorID() const;

    void FUN_005845e0();

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
    CellMap5845* m_pkCellMap;
    unsigned int unk34;
    unsigned int unk38;
    WorldSpaceLOD5845* m_pkLOD;
    unsigned int m_uiClimate;
    unsigned int m_uiImageSpace;
    WorldSpaceRegion5845* m_pkRegion;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int m_uiParentWorld;
    unsigned int m_uiWater;
    unsigned int m_uiLODWater;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int m_uiMusicType;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int m_uiEncounterZone;
};

// @fnv 0x005845e0
void WorldSpaceOwner5845::FUN_005845e0()
{
    if (!reinterpret_cast<::TESForm *>(this)->GetInitialized())
    {
        unsigned int uiFormIDA;
        uiFormIDA = m_uiClimate;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESClimate* pkClimate = dynamic_cast<TESClimate*>(FUN_004839c0(uiFormIDA));
            if (!pkClimate)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(pkClimate));
        }
        uiFormIDA = m_uiImageSpace;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESImageSpace* pkImageSpace2 = dynamic_cast<TESImageSpace*>(FUN_004839c0(uiFormIDA));
            if (!pkImageSpace2)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((::TESObjectREFR *)(pkImageSpace2));
        }
        uiFormIDA = m_uiEncounterZone;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            BGSEncounterZone* pkEncounterZone = dynamic_cast<BGSEncounterZone*>(FUN_004839c0(uiFormIDA));
            if (!pkEncounterZone)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESWorldSpace *>(this)->SetFieldD0((unsigned int)(pkEncounterZone));
        }
        uiFormIDA = m_uiWater;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESWaterForm* pkWaterType4 = dynamic_cast<TESWaterForm*>(FUN_004839c0(uiFormIDA));
            if (!pkWaterType4)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESObjectACTI *>(this)->SetLoopingSound((::TESSound *)(pkWaterType4));
        }
        uiFormIDA = m_uiLODWater;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESWaterForm* pkLODWaterType3 = dynamic_cast<TESWaterForm*>(FUN_004839c0(uiFormIDA));
            if (!pkLODWaterType3)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound((::TESSound *)(pkLODWaterType3));
        }
        uiFormIDA = m_uiMusicType;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            BGSMusicType* kPkMusicType = dynamic_cast<BGSMusicType*>(FUN_004839c0(uiFormIDA));
            if (!kPkMusicType)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::FUN_00810570_shell *>(this)->SetAssociatedActorValue((int)(kPkMusicType));
        }
        uiFormIDA = m_uiParentWorld;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESWorldSpace* pkParentWorldVal = dynamic_cast<TESWorldSpace*>(FUN_004839c0(uiFormIDA));
            if (!pkParentWorldVal)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESWorldSpace *>(this)->SetParent(pkParentWorldVal);
        }
        if (m_pkRegion)
            reinterpret_cast<::SomeClass *>((m_pkRegion))->RemapImpactData((::TESForm *)(::WorldSpaceOwner5845 *)(this));
        reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
    }
    TESObjectCELL5845* pkPersistent4;
    void* pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((m_pkCellMap))->GetFirstPos();
    while (pos2)
    {
        unsigned int uiKey3;
        TESObjectCELL5845* pkCell = 0;
        reinterpret_cast<::C6b7f20_Map *>((m_pkCellMap))->FUN_006b7f20((::C6b7f20_Node **)&(pos2), (unsigned int *)&(uiKey3), (void **)&(pkCell));
        if (pkCell)
            pkCell->LinkPersistent();
    }
    pkPersistent4 = ((::TESObjectCELL5845 *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (pkPersistent4)
        pkPersistent4->LinkPersistent();
    m_pkLOD = new WorldSpaceLOD5845(this);
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long off, void* src, void* dst, int isRef);
struct FormX
{
    int FUN_00401170();
    bool IsLessThan(FormX* pkForm);
};
struct WorldX;
struct ChildX
{
    virtual WorldX* GetParentWorld();
};
struct WorldX;
struct CellX
{
};
struct WorldX
{
    bool IsLessThan(FormX* pkForm);
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c(), v20(), v24(), v28(), v2c(), v30(), v34(),
        v38();
    virtual bool IsChildOf(WorldX* pkWorld);
    bool FUN_00584be0(FormX* pkForm);
};
// @fnv 0x00584be0
bool WorldX::FUN_00584be0(FormX* pkForm)
{
    bool bResult = false;
    switch (pkForm->FUN_00401170())
    {
    case 0x39: {
        CellX* pkCell = (CellX*)dynamic_cast<::TESObjectCELL *>(reinterpret_cast<::TESForm *>(pkForm));
        WorldX* pkWorld = pkCell ? ((::WorldX *)(reinterpret_cast<::TESObjectCELL *>((pkCell))->GetParentWorldSpace())) : 0;
        if (pkWorld == this)
            bResult = true;
        else if (pkWorld)
            bResult = IsChildOf(pkWorld);
        break;
    }
    case 0x41:
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkForm))->FUN_0084e3a0())))
            bResult = true;
        break;
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x69: {
        ChildX* pkChild = (ChildX*)FUN_00ec43fb(pkForm, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_0118ac2c, 0);
        bResult = IsChildOf(pkChild->GetParentWorld());
        break;
    }
    default:
        bResult = reinterpret_cast<::TESFormSortProxy *>(this)->IsLessThan((::TESForm *)(pkForm));
        break;
    }
    return bResult;
}
