// fallout_shared/tesnpc_pc_decls.h: declares TESFullNameLoader, TESForm, TESBoundObject, TESObjectREFR, MobileObject and more
#ifndef TESNPC_PC_DECLS_H
#define TESNPC_PC_DECLS_H

// PC call-site declarations for this translation unit.
// Shared classes come from the canonical include/ headers (explicit ../../include/ paths: src/fallout_shared has
// case-insensitive look-alike stubs): layout_support, BaseFormComponent, BaseProcess (all 493 PC virtuals),
// ActorValueOwner, AutoMemContext, SETTING_VALUE, BSAudio, TESFile.
// Unit-local on purpose (canonical headers lack members the matched functions call; listed for the header owner):
//     GetDataSizeAdjustment/ReadTypedData; TESObjectREFR/Actor lack the non-virtual helpers and typed slots used here.
//   NiPointer, BSSimpleArray: out-of-line ctor/operator= calls (canonical versions are inline or have no ctor).
#include "fnv/decl/ActorSpellView.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/B441420Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BipedAnimWeap.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0041c930_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041cb70_shell.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0047bdd0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_0047ded0_shell.h"
#include "fnv/decl/FUN_0047fb50_shell.h"
#include "fnv/decl/FUN_00480000_shell.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004870f0_shell.h"
#include "fnv/decl/FUN_00487240_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004bfe50_t.h"
#include "fnv/decl/FUN_004c8220_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00503240_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FUN_0060b370_shell.h"
#include "fnv/decl/FUN_00613870_Class.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_00634890_shell.h"
#include "fnv/decl/FUN_006727b0_shell.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00c748d0_C.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/Header47cb90.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/ModelCopyView.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Thing575.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk_0097fa10.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_0047d220__ABD_47d220.h"
#include "fnv/decl/fnv_0047f500__FUN_0047f500_shell.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048cce0__FUN_0048cce0_shell.h"
#include "fnv/decl/fnv_0048d290__FUN_0048d290_shell.h"
#include "fnv/decl/fnv_0048d630__SpellListAccess.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0057b7c0__Actor57.h"
#include "fnv/decl/fnv_00613c50__FUN_00613c50_C.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0088c830__ThisC.h"
#include "fnv/decl/fnv_008a7a90__ActorAnimView.h"
#include "fnv/decl/fnv_008a8e50__ActorP_S.h"
#include "fnv/decl/fnv_008b3c30__FUN_008b3c30_shell.h"
#include "fnv/decl/fnv_008bb520__TES.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_00505000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00754000.h"
#include "fnv/symbols_008f2000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#define NiPointer FNV_NiPointer_Canonical
#define BSSimpleArray FNV_BSSimpleArray_Canonical
#include "../../include/layout_support.h"
#undef BSSimpleArray
#undef NiPointer
template <class T> class NiPointer;
#include "../../include/BaseFormComponent.h"
#include "../../include/BaseProcess.h"
#include "../../include/ActorValueOwner.h"
#include "../../include/AutoMemContext.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/BSAudio.h"
#include "../../include/TESFile.h"
class TESFullName;
class TESFullNameLoader
{
  public:
};
class TESObjectWEAP;
class QuestDialogueInfo;
class TESPackage;
class TESTopic;
class ExtraDataList;
class TESObjectARMO;
class TESDialoguePackage;
namespace ActorValue {
enum Section
{
    Attributes = 0,
    Skills = 2
};
}
class TESForm;
class TESFile;
class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;             // +0x4
    unsigned int m_uiFormFlags;             // +0x8
    unsigned int iFormID;                   // +0xC
    BSSimpleList<TESFile*> m_kSourceFiles;  // +0x10
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool Load(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    ENUM_FORM_ID GetFormType() const;
    TESForm();
    TESFile* GetFile(int fileIndex);
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
public:
    bool GetInitialized() const;
public:
    ::TESFile *GetOwnerMaster();
};

#include "../../include/NiPoint3.h"
class ExtraDismemberedLimbs;
class InventoryStackRecord;
class TESBipedModelForm;
class BSFaceGenAnimationData;
class ActorAnimData;
class NiDefaultAVObjectPalette;
class NiAVObject;
class TESActorBase;
class TESNPC;
class TESRace;
class TESHair;
class TESEyes;
class TESCombatStyle;
class BGSHeadPart;
class BSFaceGenNiNode;
class BipedAnim;
class BaseProcess;
class CombatController;
class TESClass;
class BGSLoadFormBuffer;
class PlayerQuestData;
enum SEX
{
    MALE,
    FEMALE
};
class TESBoundObject : public TESForm
{
  public:
    unsigned char boundData[24];
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160(InventoryStackRecord*, int, bool);
    virtual void vfn_164(int);
    virtual void vfn_168(int);
    virtual void vfn_16c(int);
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual TESObjectREFR* RemoveItem(TESForm*, void*, int, bool, int, Actor*, void*, void*, bool, bool);
    virtual void vfn_180();
    virtual void EquipItem(TESBoundObject*, int, ExtraDataList*, bool);
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual ActorAnimData* GetAnimData();
    virtual BipedAnim* GetBipedAnim();
    virtual void vfn_1ec();
    virtual void SetBipedAnim(BipedAnim*);
    virtual NiPoint3* GetPos();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual int GetSitSleepState();
    virtual bool IsCharacter();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool HasHealth(bool);
    virtual bool GetHasKnockedState();
    virtual bool GetIsParalyzed();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual bool vfn_280(Actor*, int, int, int, int, int, int, int, int);
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void SetExtraRunOncePacks(TESPackage*, unsigned char);
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual Actor* GetCurrentTarget();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual bool GetIsDying();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual unsigned char IsGuard();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void InitGetUpPackage();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual CombatController* GetCombatController();
    unsigned char refrData[0x68 - 0x18];
    bool GetIsUnconscious();
    int IsFleeing();
    bool IsBlocking();
    bool SetReferenceHeading(NiPoint3, bool);
};
class MobileObject : public TESObjectREFR
{
  public:
    unsigned char mobileData[32];
    bool IsCombatStateActive() const;
};
class MagicCaster
{
  public:
    virtual void vfn_0();
    unsigned char casterData[8];
    void RemoveCastingArt();
};
class TESActorBase;
class TESObjectREFR;
class Actor : public MobileObject, public MagicCaster
{
  public:
    TESPackage* GetCurrentPackage();
    TESObjectWEAP* GetActiveWeapon();
    bool IsSneaking();
    unsigned char actorData[0xac - 0x94];
    BSFaceGenAnimationData* pFaceGenAnimationData;
    unsigned char actorTail[0x20c - 0xb0];
    bool bPreventActivation;
public:
    ::TESActorBase *GetActorBase();
public:
    void FUN_008c00e0(::TESObjectREFR *, int, int);
};
struct Biped;
class PlayerCharacter : public Actor
{
  public:
    TESActorBase* GetActorBase();
    BipedAnim* GetBipedAnim(bool);
public:
    ::Biped *FUN_00950b00(bool);
};
class TESObjectARMO : public TESBoundObject
{
};
class TESObjectWEAP : public TESBoundObject
{
};
class TESDialoguePackage;
class TESPackage
{
  public:
    virtual ~TESPackage();
    unsigned char packageData[0xa];
    unsigned char m_cEventActionValue;
    unsigned char packageTail[0x8c - 0xf];
    TESTopic* pTopic;
    bool IsMustReachLocation();
    bool IsPackageBlockingGreeting();
    bool RunPackage();
public:
    bool GetForceUnequipWeapon() const;
};
class TESDialoguePackage : public TESPackage
{
};
class CombatController
{
  public:
    bool SetActive(Actor*);
};
class ExtraDataList
{
  public:
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
class Calendar
{
  public:
    unsigned char GetDayOfMonth();
    float GetGameTime();
};
class SettingActivationText
{
  public:
};
class ActivationMenuState
{
  public:
};
class DialogueItem
{
  public:
    ~DialogueItem();
    bool SelectDefaultResponseList();
};
class TESTopic
{
  public:
};
BSAudio* GetAudioSystem();
extern "C" int sprintf(char*, const char*, ...);
class ContainerItemExtra
{
  public:
    TESForm* m_pForm;
    int m_cRank;
    float m_fHealth;
    ContainerItemExtra();
    bool Load(TESFile*);
};
struct InventoryItemEntry
{
    int iCount;
    TESForm* pForm;
    ContainerItemExtra* pExtra;
    void FUN_00462230();
};
struct ContainerItem
{
    int iCount;
    unsigned int iFormID;
    void FUN_00462230();
};
extern InventoryItemEntry* DAT_011cb7d8;
struct ActorBaseAttributes
{
    int m_uiActorFlags;
    unsigned short m_usField04, m_usField06, sLevel, m_usField0A, m_usField0C, m_usField0E;
    float m_fField10;
    unsigned short m_usField14, m_usField16;
};
struct PackedRecordData
{
    unsigned char m_ucField00, m_ucField01, m_ucField02, m_ucField03;
    unsigned char m_ucField04;
    unsigned int m_uiField08;
    unsigned char m_ucField0C, m_ucField0D, m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
};
struct FactionReaction
{
    TESFaction* pFaction;
    char m_ucRank;
};
class TESActorBaseData : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual bool vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual unsigned int vfn_58();
    virtual void vfn_5c(unsigned int);
    ActorBaseAttributes actorData;
    TESForm* m_pBaseTemplateForm;
    TESForm* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    BSSimpleList<FactionReaction*> m_pVoiceType;
    bool GetFlag(unsigned int) const;
public:
    void SetMatchesPCLevel(bool);
};
class BaseFormComponent;
class TESContainer : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    unsigned int count;
    InventoryItemEntry** objects;
public:
    void CopyFromBase(::BaseFormComponent *);
};
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    unsigned int pSpell;
    unsigned short usValue, pad;
};
class TESSpellList : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    unsigned char listData[16];
};
struct PackedRecordData;
class TESAIForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    PackedRecordData m_kAIData;
    unsigned char packages[8];
    void SetServiceFlags(unsigned int, bool);
public:
    void SetAggression(unsigned char, bool);
public:
    void SetConfidence(unsigned char, bool);
public:
    void SetEnergy(unsigned char, bool);
public:
    void SetResponsibility(unsigned char, bool);
public:
    void CopyAIDataFromAIDATA(::PackedRecordData *);
public:
    void CopyAISettings(::TESAIForm *);
public:
    void CopyAIPackageList(const ::TESAIForm *);
};
class TESHealthForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    int health;
};
class TESAttributes : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    unsigned char attributes[8];
};
class TESFile;
class TESForm;
class TESAnimation : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSSimpleList<const char*> m_kKFFileList;
    void BaseFormRecord(TESAnimation*, TESFile*);
public:
    void LoadComponent(::TESForm *, ::TESFile *);
};
class TESFullName : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    BSStringT<char> m_kName;
};

class TESModel : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    unsigned char modelData[20];
    static void LoadModelData(TESModel*, TESFile*);
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    unsigned int script;
    unsigned char data[4];
    void InitItem(TESForm*);
};
class BaseFormComponent;
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    void* pData;
public:
    void FUN_004786e0(::BaseFormComponent *);
};
class TESRaceForm : public BaseFormComponent
{
  public:
    void BaseFormRecord(BaseFormComponent*);
    void InitItem(TESForm*);
    TESRace* m_pRace;
    TESRaceForm();
};
enum SEX;
class TESActorBase : public TESBoundObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
  public:
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual bool vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160(InventoryStackRecord*, int, bool);
    virtual void vfn_164(int);
    virtual void vfn_168(int);
    virtual void vfn_16c(int);
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void EquipItem(TESBoundObject*, int, ExtraDataList*, bool);
    virtual TESCombatStyle* GetCombatStyle();
    virtual void SetCombatStyle(TESCombatStyle*);
    TESActorBase();
    ~TESActorBase();
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void Copy(TESForm*);
    void InitItem();
    bool ShouldUseDefaultAppearance(TESObjectREFR*);
public:
    ::SEX GetSex() const;
public:
    void FUN_005f20a0(bool);
};
struct FaceGenCoordinateValue
{
    float* value;
    unsigned int offset;
    const float* FUN_00629ab0();
};
class FaceGenCoordinateBasis
{
  public:
    FaceGenCoordinateValue FUN_0060b370(unsigned int, unsigned int);
};
template <class T> class FaceGenMatrix : public FaceGenCoordinateBasis
{
  public:
    unsigned char vectorData[24];
    unsigned int m_uiRowCount, m_uiColumnCount;
    FaceGenMatrix();
    ~FaceGenMatrix();
    void SetDimensions(unsigned int, unsigned int);
    void FUN_0060b3b0();
    unsigned int FUN_009611e0();
    unsigned int FUN_00441110();
    FaceGenMatrix& operator=(const FaceGenMatrix&);
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    NiPointer& operator=(NiPointer&);
    operator T*() const;
};
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    virtual void vfn_0();
    T* pBuffer;
    unsigned int iSize, SimpleArrayStorage;
    BSSimpleArray();
    BSSimpleArray(unsigned int, bool);
    ~BSSimpleArray();
    unsigned int Add(T&);
    unsigned int Find(T&, unsigned int, bool(__cdecl*)(T&, T&));
    void RemoveAt(unsigned int, bool);
    unsigned int GetSize();
};
class NiTexture;
class FaceGenUndo;
class TESRace : public TESForm
{
  public:
    float GetHeight(SEX);
    float GetWeight(SEX);
};
namespace ActorValue { enum Index; }
class TESClass : public TESForm
{
  public:
    unsigned char classData[0x38 - 0x18];
    TESAttributes classAttributes;
public:
    bool IsTagSkill(::ActorValue::Index) const;
};
class TESHair : public TESForm
{
};
class TESEyes : public TESForm
{
};
class BGSHeadPart : public TESForm
{
};
class TESCombatStyle : public TESForm
{
};
struct ActorSkillData
{
    unsigned char skills[14];
    unsigned char skillOffsets[14];
};
struct TESNPCFaceCoordinates
{
    FaceGenMatrix<float> matrices[2][2];
};
class TESObjectREFR;
class TESNPC : public TESActorBase, public TESRaceForm
{
  public:
    ActorSkillData data;
    TESClass* m_pClass;
    FaceGenMatrix<float> m_kFaceGenCoordinates[2][2];
    FaceGenMatrix<float> (*m_pOffsetFaceCoordinates)[2];
    TESHair* m_pHair;
    float m_fHairLength;
    TESEyes* m_pEyes;
    NiPointer<BSFaceGenNiNode> m_pkPrimaryFaceGenNode, m_pkSecondaryFaceGenNode;
    NiPointer<NiTexture> m_pkFaceGenTexture;
    unsigned short m_usLastRace;
    unsigned short lastRacePadding;
    TESCombatStyle* m_pCombatStyle;
    unsigned int iHairColor;
    BSSimpleList<BGSHeadPart*> m_kHeadPartList;
    int m_eImpactMaterial;
    unsigned int m_ulTopicFlags;
    TESRace* m_pAssignedRace;
    TESNPC* m_pTemplateNPC;
    float m_fGlyphExtent, fWeight;
    BSSimpleArray<FaceGenUndo*, 1024> undoStates;
    TESNPC();
    ~TESNPC();
    bool Activate(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int);
    bool Load(TESFile*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void UpdateActorFaceGen(TESObjectREFR*, BipedAnim*, BSFaceGenNiNode*, BSFaceGenNiNode*);
    void UpdateModel3D(TESObjectREFR*, bool, bool, bool, bool);
    void UpdateActorBaseData(bool);
    void RebuildHeadModel(TESObjectREFR*, BipedAnim*, bool);
    void InitItem();
    void AttachHeadParts(TESObjectREFR*, NiNode*);
    void ResetFormData();
    void ClearData();
    void Copy(TESForm*);
    void CopyActorBaseData(TESNPC*);
    void CollectNPCsByRaceAndSex(TESRace*, SEX, BSSimpleArray<TESNPC*, 1024>*);
    void SetField1F0(TESNPC*);
    BipedAnim* GetBipedAnimationForReference(TESObjectREFR*);
    bool InitWornObject(TESObjectREFR*, BipedAnim*, TESBoundObject*);
    void GetFaceGenNodes(BSFaceGenNiNode*&, BSFaceGenNiNode*&);
    TESHair* GetHair();
    float GetWeight();
    float GetDefaultHeight();
    void GetFaceGenCoords(FaceGenMatrix<float> (&)[2][2]);
    TESRace* GetRace();
    TESCombatStyle* GetCombatStyle();
    void SetCombatStyle(TESCombatStyle*);
    void SetActorValue(ActorValue::Index, int);
    BSSimpleList<BGSHeadPart*>* FUN_00602170();
    void SetHair(TESHair*);
    void SetEyes(TESEyes*);
    void FUN_00601c10(float);
    void ResetFaceGen();
public:
    void FUN_006047c0(::TESObjectREFR *, bool, bool, bool, bool);
};
FNV_STATIC_ASSERT(sizeof(TESActorBase) == 0x10c);
FNV_STATIC_ASSERT(offsetof(TESNPC, m_pClass) == 0x130);
FNV_STATIC_ASSERT(offsetof(TESNPC, m_pHair) == 0x1b8);
FNV_STATIC_ASSERT(offsetof(TESNPC, fWeight) == 0x1f8);
class TESFileChunkData16 : public TESFile
{
  public:
};
class TESFileFormVersion : public TESFile
{
  public:
};
// The shared TESFile declaration lacks these methods, so use a private extension.
class TESNPCFileAccess : public TESFileFormVersion
{
  public:
};

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
template <int N> struct EndianSizeTag
{
};

class FormChangeMask
{
  public:
    unsigned int flags;
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    virtual unsigned char GetVersion();
    FormChangeMask GetOldChangeFlags(unsigned int);
    FormChangeMask GetChangeFlags(unsigned int);
    bool FUN_0042ce90();
};

struct FaceGenCoordinates
{
    FaceGenMatrix<float> values[2][2];
};
struct FaceGenCoordinates;
class BSFaceGenManager
{
  public:
    static FaceGenCoordinates* GetFaceGenCoordinates();
    static char* BuildFaceGenPartPath(char*, int);
public:
    static ::BSFaceGenManager *GetFaceGenManager();
public:
    static void InitializeFaceGenCoordinates(::FaceGenCoordinates *);
};
class NiUpdateData
{
  public:
    float fTime;
    unsigned int flags;
    bool updateControllers;
    NiUpdateData(float, bool, bool);
};
class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    ThreeByThreeMatrix();
};
class NiExtraData;
class NiFixedString;
class NiAVObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* IsSceneNode();
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
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4(float, bool, bool, bool, bool, bool);
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0(bool);
    virtual void vfn_d4();
    virtual void vfn_d8(bool, bool);
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual BSFaceGenAnimationData* GetFaceGenAnimationData();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114(bool);
    virtual void vfn_118();
    virtual void vfn_11c(bool);
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128(NiNode*, bool);
    void Update(const NiUpdateData&);
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};
class NiAVObject;
class NiNode : public NiAVObject
{
public:
    ::NiAVObject *GetAt(unsigned int);
};
class BSFaceGenNiNode : public NiNode
{
};
class ActorAnimData
{
  public:
};
class NiControllerManager
{
  public:
};
class BSFaceGenAnimationData : public NiAVObject
{
  public:
    void FUN_00607830(float);
    void SetBoneMaxAngle(int, float);
};
struct BIPED_OBJECT_DATA
{
    TESBoundObject* pObject;
    void* pItem;
    NiAVObject* p3D;
    NiNode* pBone;
};
enum BIPED_BONE
{
    BIPED_BONE_HEAD = 0
};
class BipedAnim
{
  public:
    BipedAnim(TESObjectREFR*, bool);
    unsigned char bipedData[0x2b4];
    NiNode* GetBoneNode(BIPED_BONE);
    void UpdateRaceSex(TESRace*, SEX);
public:
    static bool CanLoadHiddenBipedObjects();
public:
    void AttachFaceGenNode();
};
void ComputeAngleRange(float*, float*);
void FUN_00649fe0(float*, float*);
void GetEyeAngleLimits(float*, float*);

class BGSSaveLoadGame
{
  public:
};
class InventoryStackRecord
{
  public:
    ~InventoryStackRecord();
};
class TESObjectREFR;
class InventoryChanges
{
  public:
public:
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
};
class BGSBipedModelList;
class BipedAnim;
class TESForm;
enum BIPED_OBJECT;
enum SEX;
class TESBipedModelForm : public BaseFormComponent
{
  public:
public:
    bool HasBipedModel(::BIPED_OBJECT, bool, ::BGSBipedModelList *);
public:
    void SetBipedModel(::BipedAnim *, ::SEX, ::BIPED_OBJECT);
public:
    static ::TESBipedModelForm *GetFormAsBipedModel(const ::TESForm *);
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting327;
class AIFormulas
{
  public:
    static float CalculateSkillValue(float, float, float);
};
struct NPCDefaultSelection
{
    bool useClassDefaults;
    bool isPlayer;
};
struct DismembermentPart
{
    bool bIsBody, bDismembered;
};
class ExtraDismemberedLimbs
{
  public:
    unsigned char extraData[0x20];
    BSSimpleArray<DismembermentPart*, 1024> parts;
};
class SceneObjectLookup
{
  public:
};
class TESSaveLoadGame
{
  public:
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
class BGSListForm
{
  public:
};
class BGSBipedModelList
{
  public:
    static BGSBipedModelList* GetBipedModelList(TESForm*);
};
extern const char* DAT_01188b98[];
class TESHairRaceResult
{
  public:
};
class TESHairCanBeNPCData
{
  public:
};
#endif
