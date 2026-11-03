
// src/fallout_shared/tesobjectcell_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectCELL, TESObjectREFR, TESWorldSpace). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00450fd0_class.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_004523c0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_005194d0_shell_base.h"
#include "fnv/decl/FUN_00519500_class.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_005455c0_cls.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00548700_Class.h"
#include "fnv/decl/FUN_005495a0Class.h"
#include "fnv/decl/FUN_005516c0.h"
#include "fnv/decl/FUN_00557aa0_Class.h"
#include "fnv/decl/FUN_00557d10_Class.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_00564e60_shell.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00569580_shell.h"
#include "fnv/decl/FUN_005725f0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_0063c690_shell.h"
#include "fnv/decl/FUN_00644950_shell.h"
#include "fnv/decl/FUN_0087abb0_shell.h"
#include "fnv/decl/FUN_0087b400_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00885a30_Class.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/InventoryMove.h"
#include "fnv/decl/KillActor.h"
#include "fnv/decl/LodGrid.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/ML.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WorldSpaceRefShell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_00545560__FUN_00545560Class.h"
#include "fnv/decl/fnv_00548880__FNV_Cell.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_005656d0__Thing.h"
#include "fnv/decl/fnv_005692a0__FUN_005692a0_shell.h"
#include "fnv/decl/fnv_0056a250__FUN_0056a250_shell.h"
#include "fnv/decl/fnv_005728c0__FUN_005728c0_shell.h"
#include "fnv/decl/fnv_0063b630__SkyHelper.h"
#include "fnv/decl/fnv_0063bab0__FUN_0063bab0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087aad0__FUN_0087aad0_s.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_00548000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_00552000.h"
#include "fnv/symbols_00555000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_0118b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f6000.h"
#include "tesobjectcell_packet_rtti_variant.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

class CellView;

struct BSExtraData
{
    virtual ~BSExtraData();
    unsigned char type;
    unsigned char unknown05, unknown06, unknown07;
    BSExtraData* next;
};
struct FUN_0040f410 : BSExtraData
{
    unsigned int references;
    FUN_0040f410();
};
struct ExtraListAccess548 : ExtraDataList
{
};
class BaseProcess;
class MobileObject : public TESObjectREFR
{
  public:
    int FUN_00931850();
};
struct RefList548
{
    TESObjectREFR* item;
    RefList548* next;
};
class GlobalObject_0096d020
{
  public:
};
struct Cell548 : TESObjectCELL
{
    void FUN_00551480(bool RetainReference);
};

class RefView : public TESObjectREFR
{
  public:
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
    virtual bool IsActor();  // +0x100
    virtual void v0x41();
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
    virtual void Unk_1c4();  // +0x1c4
    virtual void v072();
    virtual void Unk_1cc(int iA, int iB);  // +0x1cc
    virtual void* GetNode3D();             // +0x1d0
    virtual void v0x75();
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
    virtual void SetParentCell(CellView* pkCell);  // +0x228
    virtual void v0x8b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void Unk_240();  // +0x240
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();  // +0x24c

      // GetDisabled
      // GetParentCell
};

class RefExtra
{
  public:
};

struct RefList
{
    void FUN_005ae3d0(RefView*& rpkRef);  // AddHead
      // IsInList
public:
    bool FUN_005f65d0(void **);
};

class CellNavHandler
{
  public:
};
class CellDataHandler
{
  public:
};
class CellTES
{
  public:
};
class CellPlayer
{
  public:
};  // IsSleepingOrResting
class CellSaveLoad
{
  public:
};
class CellModelLoader
{
  public:
};
class CellProcessLists
{
  public:
};
class CellNodeMap
{
  public:
};
class CellTaskQueue
{
  public:
};
class CellView
{
  public:
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
    virtual void Unk_0c8(int iValue);  // +0xc8
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
    unsigned short m_usPersistentCount;  // +0xa8
    unsigned short unkaa;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    void* m_pkNavMeshes;  // +0xc4

      // CellRefLockEnter
      // CellRefLockLeave
      // RemoveReference
      // IsInterior
    void FUN_00548230(RefView* pkRef, bool bArg);
};

class TESForm
{
  public:
    virtual ~TESForm();
    int GetFormType();
public:
    bool GetDisabled() const;
};
// @fnv 0x00548230
void CellView::FUN_00548230(RefView* pkRef, bool bArg)
{
    if (!pkRef || !((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkRef))->FUN_007af430())))
        return;
    if (reinterpret_cast<::FUN_00564e60_shell *>((pkRef))->FUN_00564e60() && !reinterpret_cast<::TESForm *>((pkRef))->GetDisabled())
        m_usPersistentCount++;
    if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
    {
        reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
        ((::RefList *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))->FUN_005ae3d0(pkRef);
        ::FUN_00541ae0((char *)this);
        reinterpret_cast<::FUN_0041d390_shell *>((((::RefExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((pkRef))->FUN_005d43c0()))))->FUN_0041d390((::TESObjectCELL *)(::CellView *)(this));
        CellNavHandler* pkHandler = ((::CellNavHandler *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()));
        if (pkHandler)
            reinterpret_cast<::WorldSpaceRefShell *>((pkHandler))->FUN_00587d10((::TESObjectREFR *)(pkRef));
        if (!reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::CellDataHandler * *>(&::g_dataHandler))))->FUN_004516b0())
            Unk_0c8(1);
        return;
    }
    CellView* pkOldCell = ((::CellView *)(reinterpret_cast<::LowProcess *>((pkRef))->GetTarget()));
    if (pkOldCell)
        reinterpret_cast<::fnv_0054ca90::Cell *>((pkOldCell))->FUN_0054ca90((::fnv_0054ca90::Ref *)(pkRef));
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    ((::RefList *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))->FUN_005ae3d0(pkRef);
    pkRef->SetParentCell(this);
    ::FUN_00541ae0((char *)this);
    if (::FUN_00450ff0((void *)this))
        reinterpret_cast<::CollectionView *>((DAT_011c95c8))->FUN_00526f20((::ReferenceView *)(::BGSPerkEntry *)((BGSPerkEntry*)pkRef));
    if (m_pkNavMeshes)
    {
        if ((!pkRef->IsActor() || reinterpret_cast<::TESForm *>((pkRef))->GetDisabled()) && reinterpret_cast<::fnv_005656d0::Thing *>((pkRef))->FUN_005656d0())
            reinterpret_cast<::fnv_00545560::FUN_00545560Class *>(this)->FUN_00545560((int)(pkRef));
        if (reinterpret_cast<::fnv_0056a250::FUN_0056a250_shell *>((pkRef))->FUN_0056a250())
            reinterpret_cast<::FUN_005455c0_cls *>(this)->FUN_005455c0((::FUN_005455c0_ref *)(pkRef));
    }
    if (!reinterpret_cast<::TESForm *>((pkRef))->GetDisabled() && pkRef->GetNode3D())
    {
        MobileObject* pkMobile = dynamic_cast<MobileObject*>(static_cast<TESObjectREFR*>(pkRef));
        if (!pkMobile)
            pkRef->Unk_1c4();
    }
    bool bHandled = false;
    if (!reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::CellDataHandler * *>(&::g_dataHandler))))->FUN_004516b0() && !bHandled && !reinterpret_cast<::FUN_00437b90_shell *>((pkRef))->FUN_00437b90())
    {
        void* pvNode = pkRef->GetNode3D();
        if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::CellTES * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(::CellView *)(this), 0))
        {
            bool bQueue = false;
            if (pvNode)
                reinterpret_cast<::fnv_00548880::FNV_Cell *>(this)->FUN_00548880((::fnv_00548880::FNV_Ref *)(pkRef), bArg);
            else
            {
                if (!pkRef->IsActor())
                    bQueue = true;
                else if (!reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::CellPlayer * *>(&::_g_thePlayer))))->IsSleepingOrResting() && !::FUN_00548720((void *)this))
                    bQueue = true;
                if (bQueue)
                {
                    if (pkRef->IsActor() && (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellSaveLoad * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() || reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellSaveLoad * *>(&::g_TESSaveLoadGame))))->EvaluateCondition()))
                    {
                        if (::FUN_00450ff0((void *)this) || reinterpret_cast<::FUN_004523c0_shell *>(this)->FUN_004523c0())
                            pkRef->Unk_240();
                        else
                            pkRef->Unk_24c();
                    }
                    reinterpret_cast<::ML *>(((*reinterpret_cast<::CellModelLoader * *>(&::g_modelLoader))))->FUN_00444850((::Ref *)(pkRef), reinterpret_cast<::LodGrid *>(((*reinterpret_cast<::CellTES * *>(&::g_TES))))->FUN_00458be0((::LodCell *)(::CellView *)(this), (::LodPoint *)(0)), {});
                }
            }
            if (!bQueue && pkRef->IsActor())
                reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::CellProcessLists *>(&::g_011e0e80))))->AddMobileObjectToList((::MobileObject *)(pkRef));
        }
        else
        {
            reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::CellNodeMap *>(&::g_011ca0f4))))->RemoveKey((unsigned int)(pkRef->GetNode3D()));
            if (pkRef->IsActor() && !reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::CellPlayer * *>(&::_g_thePlayer))))->IsSleepingOrResting() && !reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellSaveLoad * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
            {
                if (!FUN_008c7aa0())
                    pkRef->Unk_1cc(0, 0);
                else
                    reinterpret_cast<::FUN_0087b400_shell *>((((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b400((::TESObjectREFR *)(pkRef));
            }
        }
    }
    reinterpret_cast<::fnv_005728c0::FUN_005728c0_shell *>((pkRef))->FUN_005728c0(0);
    if (!reinterpret_cast<::TESObjectCELL *>((((::CellView *)(reinterpret_cast<::LowProcess *>((pkRef))->GetTarget()))))->IsCellInterior())
    {
        if (reinterpret_cast<::FUN_00548700_Class *>((pkRef))->FUN_00548700() && !reinterpret_cast<::RefList *>(&((*reinterpret_cast<::RefList *>(&::g_011ca13c))))->FUN_005f65d0((void **)&(pkRef)))
            (*reinterpret_cast<::RefList *>(&::g_011ca13c)).FUN_005ae3d0(pkRef);
        if (reinterpret_cast<::FUN_00885a30_Class *>((pkRef))->IsFlag20000000Set() && !reinterpret_cast<::RefList *>(&((*reinterpret_cast<::RefList *>(&::g_011ca144))))->FUN_005f65d0((void **)&(pkRef)))
            (*reinterpret_cast<::RefList *>(&::g_011ca144)).FUN_005ae3d0(pkRef);
    }
}
class TESObject : public TESForm
{
};
class TESBoundObject : public TESObject
{
};
class TESObjectDOOR : public TESBoundObject
{
  public:
};
class ReferenceList
{
  public:
    TESObjectREFR* item;
    ReferenceList* next;
    ReferenceList();
    ~ReferenceList();
    bool IsEmpty();
    TESObjectREFR*& GetItem();
    ReferenceList* GetNext();
    void Append(TESObjectREFR*& reference);
};
// Verified native methods use only their typed receiver in ECX.
// @fnv 0x0054afb0
TESObjectREFR* __cdecl FUN_0054afb0(TESForm* source, TESForm* destination, void* context)
{
    TESObjectREFR* result = 0;
    if (source && destination && context && source != destination)
    {
        unsigned int countB = 0;
        ReferenceList candidatesVal;
        ReferenceList* cursor4 = 0;
        TESWorldSpace* world = 0;
        TESObjectCELL* cellVal = dynamic_cast<TESObjectCELL*>(source);
        TESObjectCELL* lockedCellVal = 0;
        if (cellVal)
        {
            cursor4 = ((::ReferenceList *)(reinterpret_cast<::FUN_009604f0_shell *>((cellVal))->FUN_009604f0()));
            lockedCellVal = cellVal;
        }
        else
        {
            world = dynamic_cast<TESWorldSpace*>(source);
            if (world && ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((world))->GetPrevPath())))
            {
                cursor4 = ((::ReferenceList *)(reinterpret_cast<::FUN_009604f0_shell *>((((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((world))->GetPrevPath()))))->FUN_009604f0()));
                lockedCellVal = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((world))->GetPrevPath()));
            }
        }
        lockedCellVal->CellRefLockEnter();
        while (cursor4 && !cursor4->IsEmpty())
        {
            TESObjectREFR* reference = ((::TESObjectREFR *)(new ((void *)(cursor4)) ::Vec3()));
            if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->GetFormType() == 28 && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(reference))->FUN_00440d80() && !reinterpret_cast<::TESForm *>((reference))->GetDisabled() &&
                !reinterpret_cast<::FUN_00477ba0_shell *>((reference))->FUN_00477ba0())
            {
                TESObjectDOOR* door = dynamic_cast<TESObjectDOOR*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())));
                if (door && reinterpret_cast<::FUN_005194d0_shell_base *>((door))->FUN_005194d0() && reinterpret_cast<::FUN_00519500_class *>((door))->HasEntry((int)(destination)) && !((void *)(reinterpret_cast<::TESObjectREFR *>((reference))->GetExtraRadioData())))
                {
                    candidatesVal.Append(reference);
                    ++countB;
                }
            }
            cursor4 = ((::ReferenceList *)(reinterpret_cast<::Callees *>((cursor4))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)(lockedCellVal));
        if (countB > 0 && !candidatesVal.IsEmpty())
        {
            unsigned int selectedX = GetRandomNumberInRange(0, countB);
            unsigned int index2 = 0;
            cursor4 = &candidatesVal;
            while (cursor4 && !cursor4->IsEmpty())
            {
                if (index2 == selectedX)
                {
                    result = ((::TESObjectREFR *)(new ((void *)(cursor4)) ::Vec3()));
                    break;
                }
                else
                {
                    ++index2;
                    cursor4 = ((::ReferenceList *)(reinterpret_cast<::Callees *>((cursor4))->FUN_00726070()));
                }
            }
            reinterpret_cast<::FileMatchList *>(&(candidatesVal))->RemoveAll();
        }
    }
    return result;
}

class Actor : public MobileObject
{
  public:
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13c();
    virtual void slot_140();
    virtual void slot_144();
    virtual void slot_148();
    virtual void slot_14c();
    virtual void slot_150();
    virtual void slot_154();
    virtual void slot_158();
    virtual void slot_15c();
    virtual void slot_160();
    virtual void slot_164();
    virtual void slot_168();
    virtual void slot_16c();
    virtual void slot_170();
    virtual void slot_174();
    virtual void slot_178();
    virtual void slot_17c();
    virtual void slot_180();
    virtual void slot_184();
    virtual void slot_188();
    virtual void slot_18c();
    virtual void slot_190();
    virtual void slot_194();
    virtual void slot_198();
    virtual void slot_19c();
    virtual void slot_1a0();
    virtual void slot_1a4();
    virtual void slot_1a8();
    virtual void slot_1ac();
    virtual void slot_1b0();
    virtual void slot_1b4();
    virtual void slot_1b8();
    virtual void slot_1bc();
    virtual void slot_1c0();
    virtual void slot_1c4();
    virtual void slot_1c8();
    virtual void slot_1cc();
    virtual void slot_1d0();
    virtual void slot_1d4();
    virtual void slot_1d8();
    virtual void slot_1dc();
    virtual void slot_1e0();
    virtual void slot_1e4();
    virtual void slot_1e8();
    virtual void slot_1ec();
    virtual void slot_1f0();
    virtual void slot_1f4();
    virtual void slot_1f8();
    virtual void slot_1fc();
    virtual void slot_200();
    virtual void slot_204();
    virtual void slot_208();
    virtual void slot_20c();
    virtual void slot_210();
    virtual void slot_214();
    virtual void slot_218();
    virtual void slot_21c();
    virtual void slot_220();
    virtual void slot_224();
    virtual void slot_228();
    virtual bool FUN_virtual22c(int);
    virtual void slot_230();
    virtual void slot_234();
    virtual void slot_238();
    virtual void slot_23c();
    virtual void slot_240();
    virtual void slot_244();
    virtual void slot_248();
    virtual void slot_24c();
    virtual void slot_250();
    virtual void slot_254();
    virtual void slot_258();
    virtual void slot_25c();
    virtual void slot_260();
    virtual void slot_264();
    virtual void slot_268();
    virtual void slot_26c();
    virtual void slot_270();
    virtual void slot_274();
    virtual void slot_278();
    virtual void slot_27c();
    virtual void slot_280();
    virtual void slot_284();
    virtual void slot_288();
    virtual void slot_28c();
    virtual void slot_290();
    virtual void slot_294();
    virtual void slot_298();
    virtual void slot_29c();
    virtual void slot_2a0();
    virtual void slot_2a4();
    virtual void slot_2a8();
    virtual void slot_2ac();
    virtual void slot_2b0();
    virtual void slot_2b4();
    virtual void slot_2b8();
    virtual void slot_2bc();
    virtual void slot_2c0();
    virtual void slot_2c4();
    virtual void slot_2c8();
    virtual void slot_2cc();
    virtual void slot_2d0();
    virtual void slot_2d4();
    virtual void slot_2d8();
    virtual void slot_2dc();
    virtual void slot_2e0();
    virtual void slot_2e4();
    virtual void slot_2e8();
    virtual void slot_2ec();
    virtual void slot_2f0();
    virtual void slot_2f4();
    virtual void slot_2f8();
    virtual void slot_2fc();
    virtual void slot_300();
    virtual void slot_304();
    virtual void slot_308();
    virtual void slot_30c();
    virtual void slot_310();
    virtual void slot_314();
    virtual void slot_318();
    virtual void slot_31c();
    virtual void slot_320();
    virtual void slot_324();
    virtual void slot_328();
    virtual void slot_32c();
    virtual void slot_330();
    virtual void slot_334();
    virtual void slot_338();
    virtual void slot_33c();
    virtual void slot_340();
    virtual void slot_344();
    virtual void slot_348();
    virtual void slot_34c();
    virtual void slot_350();
    virtual void slot_354();
    virtual void slot_358();
    virtual void slot_35c();
    virtual void slot_360();
    virtual void slot_364();
    virtual void slot_368();
    virtual void slot_36c();
    virtual void slot_370();
    virtual void slot_374();
    virtual void slot_378();
    virtual void slot_37c();
    virtual void slot_380();
    virtual void slot_384();
    virtual void slot_388();
    virtual void slot_38c();
    virtual void slot_390();
    virtual void slot_394();
    virtual void slot_398();
    virtual void slot_39c();
    virtual void slot_3a0();
    virtual void slot_3a4();
    virtual void slot_3a8();
    virtual void slot_3ac();
    virtual void slot_3b0();
    virtual void slot_3b4();
    virtual void slot_3b8();
    virtual void slot_3bc();
    virtual void slot_3c0();
    virtual void slot_3c4();
    virtual void slot_3c8();
    virtual void slot_3cc();
    virtual void slot_3d0();
    virtual void slot_3d4();
    virtual void slot_3d8();
    virtual void slot_3dc();
    virtual void slot_3e0();
    virtual void slot_3e4();
    virtual void slot_3e8();
    virtual void slot_3ec();
    virtual void slot_3f0();
    virtual void slot_3f4();
    virtual void slot_3f8();
    virtual void slot_3fc();
    virtual void slot_400();
    virtual void slot_404();
    virtual void slot_408();
    virtual void slot_40c();
    virtual void slot_410();
    virtual void slot_414();
    virtual void slot_418();
    virtual void slot_41c();
    virtual void slot_420();
    virtual void FUN_virtual424(TESObjectREFR*, int, int, int, int, int, int, int);
    virtual void slot_428();
    virtual void slot_42c();
    virtual void slot_430();
    virtual void slot_434();
    virtual void slot_438();
    virtual void slot_43c();
    virtual void slot_440();
    virtual void slot_444();
    virtual void slot_448();
    virtual void slot_44c();
    virtual void slot_450();
    virtual void slot_454();
    virtual void slot_458();
    virtual void slot_45c();
    virtual void FUN_virtual460(TESObjectREFR*, float);
};
struct ContainerChanges550
{
};
struct ExtraListAccess550 : ExtraDataList
{
};
struct ReferenceAccess550 : TESObjectREFR
{
};
struct RefList550
{
    TESObjectREFR* item;
    RefList550* next;
};
struct Cell550 : TESObjectCELL
{
    void FUN_0054b5b0();
};
// @fnv 0x0054b5b0
void Cell550::FUN_0054b5b0()
{
    CellRefLockEnter();
    RefList550* position = ((::RefList550 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (position)
    {
        TESObjectREFR* reference = ((::TESObjectREFR *)(new ((void *)(position)) ::Vec3()));
        if (reference && reference != (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))
        {
            Actor* actor = dynamic_cast<Actor*>(reference);
            ContainerChanges550* changes =
                ((::ContainerChanges550 *)(reinterpret_cast<::ExtraDataList *>((static_cast<ExtraListAccess550*>(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((static_cast<ReferenceAccess550*>(reference)))->FUN_005d43c0())))))->GetContainerChangeData()));
            if (changes)
                reinterpret_cast<::InventoryMove *>((changes))->FUN_004ce380((::MoveOwner *)(reference), (::MoveOwner *)((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer))), false, false, true, false, -1, (::MoveFilter *)(0));
            if (actor && !reinterpret_cast<::TESForm *>((actor))->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((actor))->FUN_00440d80())
                actor->FUN_virtual460((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)), 10.0f);
            if (actor && !reinterpret_cast<::FUN_0087f3d0_shell *>((actor))->FUN_0087f3d0() && !reinterpret_cast<::TESForm *>((actor))->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((actor))->FUN_00440d80() &&
                !actor->FUN_virtual22c(0))
            {
                actor->FUN_virtual424((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)), 0, 0, 0, 0, 0, 1, 0);
                reinterpret_cast<::KillActor *>((actor))->FUN_0089d900(0, 0.0f);
            }
            if (((void *)(reinterpret_cast<::FUN_00569160_shell *>((static_cast<ReferenceAccess550*>(reference)))->FUN_00569160())))
                reinterpret_cast<::fnv_005692a0::FUN_005692a0_shell *>((static_cast<ReferenceAccess550*>(reference)))->FUN_005692a0();
            ::fnv_00555c20::FUN_00555c20();
        }
        position = ((::RefList550 *)(reinterpret_cast<::Callees *>((position))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}

void* __cdecl operator new(unsigned int);

// ExtraCell3D owns the reference count associated with the cell's loaded 3D.


// @fnv 0x00551480
void Cell548::FUN_00551480(bool RetainReference)
{
    FUN_0040f410* extra = static_cast<FUN_0040f410*>(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(&(extraDataList))->FUN_00410220(9));
    if (!extra && RetainReference)
    {
        extra = new FUN_0040f410;
        reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>((static_cast<ExtraListAccess548*>(&extraDataList)))->FUN_0040ff60(extra);
        CellRefLockEnter();
        RefList548* position = ((::RefList548 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (position && ((::TESObjectREFR *)(new ((void *)(position)) ::Vec3())))
        {
            MobileObject* mobile = dynamic_cast<MobileObject*>(((::TESObjectREFR *)(new ((void *)(position)) ::Vec3())));
            position = ((::RefList548 *)(reinterpret_cast<::Callees *>((position))->FUN_00726070()));
            if (mobile && !reinterpret_cast<::TESForm *>((mobile))->GetDisabled() && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture())) && mobile->FUN_00931850() == 3)
                reinterpret_cast<::ProcessLists *>(&(g_011e0e80))->AddMobileObjectToList(mobile);
        }
        ::FUN_00541ae0((char *)this);
    }
    if (extra)
    {
        if (RetainReference)
            extra->references++;
        else
            extra->references--;
        if (!extra->references)
            reinterpret_cast<::FUN_00410020_t *>((static_cast<ExtraListAccess548*>(&extraDataList)))->FUN_00410020(extra, true);
    }
}

class TESWeather : public TESForm
{
};

class NiUpdateData
{
  public:
    float m_fTime;
    unsigned short unk04;
    bool m_bQueueShadow;
    bool m_bQueueAnim;
    bool m_bUpdateShadow;
    unsigned char unk09;
    unsigned short unk0a;
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bThreaded);
};

class NodeView
{
  public:
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
    virtual void UpdateDownwardPass(NiUpdateData& kData, unsigned int uiFlags);  // +0xa8
};

class SceneRoot
{
  public:
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
    virtual void Unk_0c4();  // +0xc4
};

class RefNodeView
{
  public:
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
    virtual NodeView* GetNode3D();  // +0x1d0
};

struct RefNodeList
{
    RefNodeView* m_pkItem;
    RefNodeList* m_pkNext;
    bool FUN_008256d0();           // IsEmpty
      // GetItem
       // GetNext
};

class FormTypeView
{
  public:
    int FUN_00401170();
};  // GetFormType
class KeyRefView
{
  public:
};

struct NiColor
{
    float r, g, b;
};

class LightForm
{
  public:
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
    virtual NiColor* GetColor();  // +0xc0
    int FUN_00401170();           // GetFormType
      // packed RGB
};

class BaseLight
{
  public:
    int FUN_00401170();
};

struct SkyColorData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

class Sky
{
  public:
public:
    static ::Sky *GetInstance();
};

class PointLightNode
{
  public:
};
class PointLightPtr
{
  public:
};

class MapRefView
{
  public:
};

class PlayerLightView
{
  public:
};

template <class K, class V> struct CellRefMap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* FUN_004b9ba0();                                    // GetFirstPos
    void FUN_006b7f20(void*& rpvPos, K& rkKey, V& rkValue);  // GetNext
};

struct CellLoadedData
{
    int unk00;
    RefNodeList kRefs;                              // +0x04
    CellRefMap<KeyRefView*, NodeView*> kActors;     // +0x0c
    CellRefMap<LightForm*, NiColor*> kColors;       // +0x1c
    CellRefMap<MapRefView*, void*> kMapReferences;  // +0x2c
};

struct CellIntSetting
{
};
struct CellFloatSetting
{
};
struct CellTimer
{
};
extern float DAT_0118b698;
extern float DAT_0102f0e4;

class ManagedTaskQueue : public CellTaskQueue
{
  public:
};
class CellShadowScene
{
  public:
};

class CellWaterView
{
  public:
};
class CellWaterOwner
{
  public:
};

class CellUpdateView
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
    short unka8;
    short m_sRefCount;  // +0xaa
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    CellLoadedData* m_pkLoaded;  // +0xc4
    float m_fWaterTimer;         // +0xc8
    unsigned short unkcc;
    bool m_bWaterCE;  // +0xce
    bool m_bWaterCF;  // +0xcf
    bool m_bWaterD0;  // +0xd0
    bool unkd1;
    bool m_bWaterD2;  // +0xd2

    void FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded);
};
// @fnv 0x00551890
void CellUpdateView::FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded)
{
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && ::FUN_00450ff0((void *)this))
    {
        SceneRoot* pkRoot = ((::SceneRoot *)(reinterpret_cast<::FUN_004543c0_cls *>(this)->FUN_004543c0()));
        if (pkRoot)
            pkRoot->Unk_0c4();
    }
    bool bThreaded = false;
    if (FUN_008c7aa0())
        bThreaded = true;
    NodeView* pkDynamic = ((::NodeView *)(reinterpret_cast<::TESObjectCELL *>(this)->GetDynamicNode()));
    if (pkDynamic && !bSkipLoaded)
    {
        NiUpdateData kData(fTimeSinceScaleStart, false, bThreaded);
        pkDynamic->UpdateDownwardPass(kData, 0);
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CellIntSetting *>(&::g_011c3ea4)))))) > 1)
        {
            reinterpret_cast<::fnv_0087aad0::FUN_0087aad0_s *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087aad0((int)(pkDynamic));
            if (bThreaded && kData.m_bQueueShadow)
                ::RunWithLock(pkDynamic);
            if (bThreaded && kData.m_bQueueAnim)
                reinterpret_cast<::FUN_0087abb0_shell *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087abb0((::G00559a40 *)(pkDynamic));
        }
    }
    if (m_sRefCount > 0 && reinterpret_cast<::FUN_005495a0Class *>(this)->FUN_005495a0() && reinterpret_cast<::FUN_00557d10_Class *>(this)->FUN_00557d10())
        reinterpret_cast<::FUN_00557aa0_Class *>(this)->FUN_00557aa0();
    if (m_bWaterD2 && ((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())) && ((int)(reinterpret_cast<::FUN_00450fd0_class *>(this)->GetByteAtOffset38())) == 6)
    {
        m_bWaterD0 = true;
        m_bWaterCE = false;
        m_bWaterCF = false;
        if (((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())))
            reinterpret_cast<::MiddleHighProcess *>((((::CellWaterView *)(reinterpret_cast<::TESWorldSpace *>((((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->GetWorldTerrainManager()))))->FUN_00929260(1);
        m_bWaterD2 = false;
    }
    if (m_bWaterCE)
    {
        if (DAT_0118b698 * DAT_0118b694 <= m_fWaterTimer)
        {
            if (((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())) && !m_bWaterD0)
                reinterpret_cast<::MiddleHighProcess *>((((::CellWaterView *)(reinterpret_cast<::TESWorldSpace *>((((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->GetWorldTerrainManager()))))->FUN_00929260(1);
            m_bWaterD0 = true;
            m_bWaterCE = false;
            m_bWaterCF = false;
        }
        m_fWaterTimer += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::CellTimer *>(&::g_timeGlobal))))->GetStoredFloatValue();
    }
    if (m_pkLoaded)
    {
        if (bSkipLoaded)
        {
            RefNodeList* pkIter = &m_pkLoaded->kRefs;
            while (pkIter && !pkIter->FUN_008256d0())
            {
                RefNodeView* pkRef = *((::RefNodeView **)(new ((void *)(pkIter)) ::Vec3()));
                NodeView* pkNode = pkRef->GetNode3D();
                pkIter = ((::RefNodeList *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
                if (pkNode)
                {
                    NiUpdateData kNodeData(fTimeSinceScaleStart, false, bThreaded);
                    pkNode->UpdateDownwardPass(kNodeData, 0);
                    if (kNodeData.m_bUpdateShadow)
                        reinterpret_cast<::S00b5d9f0_Owner *>((((::CellShadowScene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(pkNode), 1);
                    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CellIntSetting *>(&::g_011c3ea4)))))) > 1)
                    {
                        reinterpret_cast<::fnv_0087aad0::FUN_0087aad0_s *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087aad0((int)(pkNode));
                        if (bThreaded && kNodeData.m_bQueueShadow)
                            ::RunWithLock(pkNode);
                        if (bThreaded && kNodeData.m_bQueueAnim)
                            reinterpret_cast<::FUN_0087abb0_shell *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087abb0((::G00559a40 *)(pkNode));
                    }
                }
            }
        }
        else
        {
            void* pvPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_pkLoaded->kActors))->GetFirstPos();
            while (pvPos)
            {
                KeyRefView* pkKeyNew = 0;
                NodeView* pkActorNode = 0;
                reinterpret_cast<::C6b7f20_Map *>(&(m_pkLoaded->kActors))->FUN_006b7f20((::C6b7f20_Node **)&(pvPos), (unsigned int *)&(pkKeyNew), (void **)&(pkActorNode));
                if (pkActorNode && ((::NodeView *)(reinterpret_cast<::FUN_009611e0_shell *>((pkActorNode))->FUN_009611e0())) != pkDynamic)
                {
                    if (((::FormTypeView *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkKeyNew))->FUN_007af430()))->FUN_00401170() == 0x25 && !::FUN_004b5fc0((::NiAVObject *)(pkActorNode), (::NiCamera *)(FUN_00552380())))
                        continue;
                    NiUpdateData kActorData(fTimeSinceScaleStart, false, bThreaded);
                    pkActorNode->UpdateDownwardPass(kActorData, 0);
                    if (kActorData.m_bUpdateShadow)
                        reinterpret_cast<::S00b5d9f0_Owner *>((((::CellShadowScene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(pkActorNode), 1);
                    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CellIntSetting *>(&::g_011c3ea4)))))) > 1)
                    {
                        reinterpret_cast<::fnv_0087aad0::FUN_0087aad0_s *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087aad0((int)(pkActorNode));
                        if (bThreaded && kActorData.m_bQueueShadow)
                            ::RunWithLock(pkActorNode);
                        if (bThreaded && kActorData.m_bQueueAnim)
                            reinterpret_cast<::FUN_0087abb0_shell *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087abb0((::G00559a40 *)(pkActorNode));
                    }
                }
            }
            pvPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_pkLoaded->kColors))->GetFirstPos();
            while (pvPos)
            {
                LightForm* pkForm = 0;
                NiColor* pkUnused = 0;
                reinterpret_cast<::C6b7f20_Map *>(&(m_pkLoaded->kColors))->FUN_006b7f20((::C6b7f20_Node **)&(pvPos), (unsigned int *)&(pkForm), (void **)&(pkUnused));
                if (pkForm)
                {
                    NiColor* pkColorPos = pkForm->GetColor();
                    switch (pkForm->FUN_00401170())
                    {
                    case 0x1e: {
                        LightForm* pkLightTmp = pkForm;
                        unsigned int uiColor = reinterpret_cast<::FUN_005e3fc0_shell *>((pkLightTmp))->Get();
                        float fScale = DAT_0102f0e4;
                        pkColorPos->r = (unsigned char)(uiColor & 0xff) * fScale;
                        pkColorPos->g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                        pkColorPos->b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                        break;
                    }
                    case 0x37: {
                        LightForm* pkRegion = pkForm;
                        TESWeather* pkWeather = ((::TESWeather *)(reinterpret_cast<::ActorMover *>((pkRegion))->GetCurrentMoveModeType()));
                        if (!pkWeather)
                            pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                        if (pkWeather)
                        {
                            Sky* pkSky = ::Sky::GetInstance();
                            SkyColorData kSkyDataOut;
                            float fBlendRes;
                            int iIndexNew;
                            reinterpret_cast<::fnv_0063b630::SkyHelper *>((pkSky))->FUN_0063b630((::fnv_0063b630::SkyInterpolationData *)(::SkyColorData *)(&kSkyDataOut), pkWeather, 1.0f, (int *)(float *)(&fBlendRes), &iIndexNew);
                            reinterpret_cast<::fnv_0063bab0::FUN_0063bab0_shell *>((pkSky))->FUN_0063bab0(&kSkyDataOut, pkWeather, (::TESWeather *)(0), 4, (int *)(float *)(&fBlendRes), &iIndexNew);
                            float fValue = reinterpret_cast<::FUN_00644950_shell *>((pkSky))->FUN_00644950() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellFloatSetting *>(&::g_011ccccc))))));
                            reinterpret_cast<::FUN_0063c690_shell *>((pkSky))->FUN_0063c690((float *)(pkColorPos), (::SkyColors *)(::SkyColorData *)(&kSkyDataOut), fValue);
                        }
                        break;
                    }
                    }
                }
            }
            pvPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_pkLoaded->kMapReferences))->GetFirstPos();
            while (pvPos)
            {
                MapRefView* pkLightRefTmp = 0;
                void* pvLightData = 0;
                reinterpret_cast<::C6b7f20_Map *>(&(m_pkLoaded->kMapReferences))->FUN_006b7f20((::C6b7f20_Node **)&(pvPos), (unsigned int *)&(pkLightRefTmp), (void **)&(pvLightData));
                if (pvLightData)
                {
                    NiColor kColor = DAT_011a9b7c;
                    LightForm* pkSource = ((::LightForm *)(reinterpret_cast<::FUN_00569580_shell *>((pkLightRefTmp))->GetOwnerForm()));
                    if (!pkSource)
                        pkSource = ((::LightForm *)(reinterpret_cast<::TESObjectCELL *>((((PlayerLightView*)(*reinterpret_cast<::CellPlayer * *>(&::_g_thePlayer)))))->FUN_005454d0()));
                    if (pkSource)
                    {
                        switch (pkSource->FUN_00401170())
                        {
                        case 0x1e: {
                            LightForm* pkLightTmp = pkSource;
                            unsigned int uiColor = reinterpret_cast<::FUN_005e3fc0_shell *>((pkLightTmp))->Get();
                            float fScale = DAT_0102f0e4;
                            kColor.r = (unsigned char)(uiColor & 0xff) * fScale;
                            kColor.g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                            kColor.b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                            break;
                        }
                        case 0x37: {
                            LightForm* pkRegion = pkSource;
                            TESWeather* pkWeather = ((::TESWeather *)(reinterpret_cast<::ActorMover *>((pkRegion))->GetCurrentMoveModeType()));
                            if (!pkWeather)
                                pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                            if (pkWeather)
                            {
                                Sky* pkSky = ::Sky::GetInstance();
                                SkyColorData kSkyDataOut;
                                float fBlendRes;
                                int iIndexNew;
                                reinterpret_cast<::fnv_0063b630::SkyHelper *>((pkSky))->FUN_0063b630((::fnv_0063b630::SkyInterpolationData *)(::SkyColorData *)(&kSkyDataOut), pkWeather, 1.0f, (int *)(float *)(&fBlendRes), &iIndexNew);
                                reinterpret_cast<::fnv_0063bab0::FUN_0063bab0_shell *>((pkSky))->FUN_0063bab0(&kSkyDataOut, pkWeather, (::TESWeather *)(0), 4, (int *)(float *)(&fBlendRes), &iIndexNew);
                                float fValue = reinterpret_cast<::FUN_00644950_shell *>((pkSky))->FUN_00644950() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellFloatSetting *>(&::g_011ccccc))))));
                                reinterpret_cast<::FUN_0063c690_shell *>((pkSky))->FUN_0063c690((float *)(::NiColor *)(&kColor), (::SkyColors *)(::SkyColorData *)(&kSkyDataOut), fValue);
                            }
                            break;
                        }
                        }
                    }
                    if (((::BaseLight *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkLightRefTmp))->FUN_007af430()))->FUN_00401170() == 0x1e)
                    {
                        BaseLight* pkBaseRes = ((::BaseLight *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkLightRefTmp))->FUN_007af430()));
                        unsigned int uiBaseColor = reinterpret_cast<::FUN_005e3fc0_shell *>((pkBaseRes))->Get();
                        float m_fThirdCreatureStatCur = DAT_0102f0e4;
                        kColor.r *= (unsigned char)(uiBaseColor & 0xff) * m_fThirdCreatureStatCur;
                        kColor.g *=
                            (unsigned char)(((unsigned short)uiBaseColor >> 8) & 0xff) * m_fThirdCreatureStatCur;
                        kColor.b *= (unsigned char)((uiBaseColor >> 16) & 0xff) * m_fThirdCreatureStatCur;
                        PointLightPtr* pkLightPtrCur = ((::PointLightPtr *)(reinterpret_cast<::FUN_005725f0_shell *>((pkLightRefTmp))->FUN_005725f0()));
                        if (pkLightPtrCur && ((::PointLightNode *)(::FUN_00559450((int *)(pkLightPtrCur)))))
                            reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((::PointLightNode *)(::FUN_00559450((int *)(pkLightPtrCur))))))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(kColor));
                    }
                }
            }
        }
    }
}

#include "generated/data/fallout_shared/tesobjectcell_rtti_variant.inc"
