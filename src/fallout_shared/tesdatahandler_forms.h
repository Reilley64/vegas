// fallout_shared/tesdatahandler_forms.h: declares TESForm, NiMemObject, TESFullName, BGSDestructibleObjectForm, TESProduceForm and more
#ifndef FNV_TESDATAHANDLER_FORMS_H
#define FNV_TESDATAHANDLER_FORMS_H

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/EffectItemList_6140.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00409700_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_0045afb0_cls.h"
#include "fnv/decl/FUN_0046dcc0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005102b0_shell.h"
#include "fnv/decl/FUN_005516c0.h"
#include "fnv/decl/FUN_00587670_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005fd460_shell.h"
#include "fnv/decl/FUN_00617ea0_shell.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FloatSettings.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/StubRef565.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/WORLD_SHELL.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00483720__FUN_00483720_shell.h"
#include "fnv/decl/fnv_00483870__FUN_00483870_shell.h"
#include "fnv/decl/fnv_005340e0__TESObjectLAND.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_00564eb0__TESObjectREFR_Flags.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00565480__RefPersistsStandin.h"
#include "fnv/decl/fnv_00587550__FUN_00587550_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s54da20__Owner.h"
#include "fnv/symbols_00409000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00564000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_011de000.h"
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class NiNode;
class TESFile;
enum ENUM_FORM_ID
{
    ENUM_FORM_ID_NONE = 0
};
class TESFile;
template <class> class NiTLargePrimitiveArray;
class TESForm
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(TESForm*);
    virtual bool CompareWithBase(TESForm*);
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool LoadForm(TESFile*);
    virtual void vfn_24(TESFile*);
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
    virtual void InitItem();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void SetAltered(bool);
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual bool vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void SetRefID(unsigned int, bool);
    virtual void vfn_12c();
    virtual const char* GetEditorID();
    virtual bool SetEditorID_AtRuntime(const char*);
    unsigned char formType;
    unsigned int flags;
    unsigned int formID;
    void* sourceFiles[2];
    void SetFile(TESFile*);
    void SetMasterFile(bool);
    ENUM_FORM_ID GetFormType() const;
    void SetInitializationState(bool);
public:
    static ::TESForm *LookupFormByEditorID(const char *);
public:
    void SetDestructible(bool);
public:
    static bool IsReservedFormID(unsigned int);
public:
    ::TESFile *GetFile(int);
public:
    static ::NiTLargePrimitiveArray< ::TESForm *> *ms_pAllForms;
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class TESFullName
{
  public:
    virtual ~TESFullName();
    void SetFullName(const char*);
    char* fullName;
    unsigned short length, capacity;
};
class BGSDestructibleObjectForm
{
  public:
    virtual ~BGSDestructibleObjectForm();
    void* data;
};
class TESProduceForm
{
  public:
    virtual ~TESProduceForm();
    void* ingredient;
    unsigned char chance[4];
};
class TESSound;

class TESObject : public TESForm
{
  public:
    void* parentList;
    TESObject* prev;
    TESObject* next;
};
class TESBoundObject : public TESObject
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
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    short bounds[6];
};
class TESModel
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    virtual void SetModelFilePath(const char*);
    char* model;
    unsigned char data[16];
};
class TESReactionForm
{
  public:
    virtual void vfn_0();
    void SetReactionValue(TESForm*, int);
    unsigned char data[8];
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    void AddHead(T&);
    T& GetItem();
    void Remove(T const&);
    BSSimpleList* GetNext();
    void AddTail(T&);
    int GetSize();
    void SetItem(T&);
    bool IsEmpty();
    void RemoveHead();
};
class TESFormInitFlag
{
  public:
};
class TESFormList
{
  public:
};

class TESObjectACTI : public TESBoundObject
{
  public:
    TESObjectACTI();
    TESFullName fullName;
    unsigned char layout_3c[0x54];
};
class BGSTalkingActivator : public TESBoundObject
{
  public:
    BGSTalkingActivator();
    unsigned char formData[0x68];
};
class BGSTerminal : public TESBoundObject
{
  public:
    BGSTerminal();
    unsigned char formData[0x78];
};
class TESObjectARMO : public TESBoundObject
{
  public:
    TESObjectARMO();
    unsigned char formData[0x160];
};
class TESObjectARMA : public TESBoundObject
{
  public:
    TESObjectARMA();
    unsigned char formData[0x160];
};
class TESObjectBOOK : public TESBoundObject
{
  public:
    TESObjectBOOK();
    unsigned char formData[0x94];
};
class TESObjectCLOT : public TESBoundObject
{
  public:
    TESObjectCLOT();
    unsigned char formData[0x124];
};
class TESObjectCONT : public TESBoundObject
{
  public:
    TESObjectCONT();
    unsigned char layout_30[0x18];
    TESModel model;
    unsigned char layout_60[0x3c];
};
class TESObjectDOOR : public TESBoundObject
{
  public:
    TESObjectDOOR();
    unsigned char layout_30[0xc];
    TESModel model;
    unsigned char layout_54[0x3c];
};
class IngredientItem : public TESBoundObject
{
  public:
    IngredientItem();
    unsigned char formData[0x74];
};
class TESObjectLIGH : public TESBoundObject
{
  public:
    TESObjectLIGH();
    unsigned char formData[0x98];
};
class TESObjectMISC : public TESBoundObject
{
  public:
    TESObjectMISC();
    unsigned char formData[0x7c];
};
class TESObjectIMOD : public TESBoundObject
{
  public:
    TESObjectIMOD();
    unsigned char formData[0x80];
};
class BGSConstructibleObject : public TESBoundObject
{
  public:
    BGSConstructibleObject();
    unsigned char formData[0x84];
};
class TESKey : public TESBoundObject
{
  public:
    TESKey();
    unsigned char formData[0x7c];
};
class TESObjectSTAT : public TESBoundObject
{
  public:
    TESObjectSTAT();
    TESModel model;
    unsigned char layout_48[0x10];
};
class BGSStaticCollection : public TESBoundObject
{
  public:
    BGSStaticCollection();
    unsigned char formData[0x20];
};
class BGSPlaceableWater : public TESBoundObject
{
  public:
    BGSPlaceableWater();
    unsigned char formData[0x20];
};
class TESGrass : public TESBoundObject
{
  public:
    TESGrass();
    unsigned char formData[0x38];
};
class TESIdleForm : public TESForm
{
  public:
    TESIdleForm();
    unsigned char formData[0x3c];
};
class BGSCameraShot;
class PerkEntryConditionSet;
template <class> class BSSimpleList;
class BGSCameraPath : public TESForm
{
  public:
    BGSCameraPath();
    unsigned char formData[0x20];
public:
    ::PerkEntryConditionSet *GetConditions();
public:
    ::BGSCameraPath *GetPrevPath();
public:
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
class BGSIdleMarker : public TESBoundObject
{
  public:
    BGSIdleMarker();
    unsigned char formData[0x10];
};
class TESPackage : public TESForm
{
  public:
    TESPackage();
    unsigned char formData[0x68];
};
class TreeRecordData;
class TESObjectTREE : public TESBoundObject
{
  public:
    TESObjectTREE();
    unsigned char formData[0x64];
public:
    ::TreeRecordData *GetData();
};
class TESFurniture : public TESBoundObject
{
  public:
    TESFurniture();
    unsigned char formData[0x64];
};
class TESObjectWEAP : public TESBoundObject
{
  public:
    TESObjectWEAP();
    TESFullName fullName;
    unsigned char layout_3c[0x34c];
};
class TESAmmo : public TESBoundObject
{
  public:
    TESAmmo();
    unsigned char formData[0xac];
};
class ActorBaseData
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10(bool);
};
class TESNPC : public TESBoundObject, public ActorBaseData
{
  public:
    TESNPC();
    unsigned char formData[0x1d8];
public:
    void UpdateActorBaseData(bool);
};
class TESCreature : public TESBoundObject, public ActorBaseData
{
  public:
    TESCreature();
    unsigned char formData[0x12c];
};
class TESLevCreature : public TESBoundObject
{
  public:
    TESLevCreature();
    unsigned char formData[0x40];
};
class TESLevCharacter : public TESBoundObject
{
  public:
    TESLevCharacter();
    unsigned char formData[0x40];
};
class SpellItem : public TESForm
{
  public:
    SpellItem();
    unsigned char formData[0x2c];
};
class EffectItemList
{
  public:
    unsigned char data[0x10];
};
class TESBipedModelForm
{
  public:
    virtual ~TESBipedModelForm();
};
class EnchantmentItem : public TESForm
{
  public:
    EnchantmentItem();
    bool IsValidObject(TESForm*);
    unsigned char magicData[0xc];
    EffectItemList effects;
    unsigned int enchantmentType;
    unsigned char enchantmentData[0xc];
};
class AlchemyItem : public TESBoundObject
{
  public:
    AlchemyItem();
    unsigned char formData[0xa8];
};
class TESLevItem : public TESBoundObject
{
  public:
    TESLevItem();
    unsigned char formData[0x1c];
};
class TESObjectCELL;
class TESWorldSpace;
class TESObjectLAND;
class NavMeshCollection;
class ExtraDataList;
struct NiPoint3
{
    float x, y, z;
};
class TESObjectREFR : public TESForm
{
  public:
    TESObjectREFR();
    unsigned int GetFlags();
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
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
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
    virtual void Set3D(NiNode*, bool);
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPosition();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void SetParentCell(TESObjectCELL*);
    struct ParentCellData
    {
        virtual TESObjectCELL* GetContainingCell();
        unsigned char data[0x18];
    } parentCellData;
    unsigned char formData[0x34];
};
class BGSNote : public TESBoundObject
{
  public:
    BGSNote();
    unsigned char formData[0x50];
};
class BGSMenuIcon : public TESForm
{
  public:
    BGSMenuIcon();
    unsigned char formData[0xc];
};
class BGSListForm : public TESForm
{
  public:
    BGSListForm();
    unsigned char formData[0xc];
};
class BGSHeadPart : public TESForm
{
  public:
    BGSHeadPart();
    unsigned char formData[0x38];
};
class TESHair : public TESForm
{
  public:
    TESHair();
    unsigned char formData[0x34];
};
class TESEyes : public TESForm
{
  public:
    TESEyes();
    TESFullName fullName;
    unsigned char layout_24[0x10];
};
class TESRace : public TESForm
{
  public:
    TESRace();
    TESFullName fullName;
    unsigned char formData[0x500];
};
class BGSEncounterZone : public TESForm
{
  public:
    BGSEncounterZone();
    static void CreateDefaultEncounterZone();
    unsigned char formData[0x18];
};
class TESClass : public TESForm
{
  public:
    TESClass();
    TESFullName fullName;
    unsigned char formData[0x3c];
};
// Keep the verified faction RTTI identity separate from the conflicting shared binding.
namespace TESDataHandlerTypes {
class TESFaction : public TESForm
{
  public:
    TESFaction();
    unsigned char layout_18[0xc];
    TESReactionForm reaction;
    unsigned char layout_30[0x1c];
};
}
using TESDataHandlerTypes::TESFaction;
class TESReputation : public TESForm
{
  public:
    TESReputation();
    unsigned char formData[0x38];
};
class TESChallenge : public TESForm
{
  public:
    TESChallenge();
    unsigned char formData[0x64];
};
class TESSound : public TESForm
{
  public:
    TESSound();
    static void InitializeMagicSystem();
    unsigned char formData[0x54];
};
class BGSAcousticSpace : public TESForm
{
  public:
    BGSAcousticSpace();
    unsigned char formData[0x3c];
};
class TESGlobal : public TESForm
{
  public:
    TESGlobal();
    void SetValue(float);
    unsigned char formData[0x10];
};
class BGSVoiceType : public TESForm
{
  public:
    BGSVoiceType();
    unsigned char formData[0xc];
};
class BGSImpactData : public TESForm
{
  public:
    BGSImpactData();
    unsigned char formData[0x60];
};
class BGSImpactDataSet : public TESForm
{
  public:
    BGSImpactDataSet();
    static void CacheImpactDataSet();
    unsigned char formData[0x34];
};
class TESSound;
class EffectSetting : public TESForm
{
  public:
    EffectSetting();
    unsigned char layout_18[0x20];
    TESFullName fullName;
    unsigned char layout_44[0x6c];
public:
    ::TESSound *GetHitSound();
};
class TESClimate : public TESForm
{
  public:
    TESClimate();
    void MakeDefault();
    unsigned char formData[0x40];
};
class TESImageSpace : public TESForm
{
  public:
    TESImageSpace();
    unsigned char formData[0x98];
};
class TESImageSpaceModifier : public TESForm
{
  public:
    TESImageSpaceModifier();
    void InitializeModifierData();
    unsigned char formData[0x718];
};
class TESWeather : public TESForm
{
  public:
    TESWeather();
    void MakeDefault();
    unsigned char formData[0x354];
};
class TESObjectREFR;
class TESWorldSpace : public TESForm
{
  public:
    TESWorldSpace();
    TESObjectCELL* GetCellAtGridPosition(int, int);
    unsigned char formData[0xd4];
public:
    void AddPersistentReference(::TESObjectREFR *);
};
class TESObjectCELL : public TESForm
{
  public:
    TESObjectCELL();
    int GetCellGridX();
    int GetCellGridY();
    TESWorldSpace* GetParentWorldSpace();
    void SetLandscape(TESObjectLAND*);
    unsigned char formData[0xc8];
public:
    bool IsCellInterior() const;
public:
    void RemoveNonPersistentRefs();
public:
    bool HasCellExtraData();
};
class TESSkill : public TESForm
{
  public:
    TESSkill();
    unsigned char formData[0x48];
};
class TESLandTexture : public TESForm
{
  public:
    TESLandTexture();
    unsigned char formData[0x10];
};
class BGSCameraShot : public TESForm
{
  public:
    BGSCameraShot();
    unsigned char formData[0x60];
};
class TESQuest : public TESForm
{
  public:
    TESQuest();
    unsigned char formData[0x54];
};
class TESRegion : public TESForm
{
  public:
    TESRegion();
    unsigned char formData[0x20];
};
class Script : public TESForm
{
  public:
    Script();
    unsigned char formData[0x3c];
};
class TESCombatStyle : public TESForm
{
  public:
    TESCombatStyle();
    unsigned char formData[0xf0];
};
class TESLoadScreen : public TESForm
{
  public:
    TESLoadScreen();
    unsigned char formData[0x28];
};
class TESWaterForm : public TESForm
{
  public:
    TESWaterForm();
    unsigned char formData[0x17c];
};
class TESLevSpell : public TESForm
{
  public:
    TESLevSpell();
    unsigned char formData[0x34];
};
class TESObjectANIO : public TESForm
{
  public:
    TESObjectANIO();
    unsigned char formData[0x24];
};
class TESObjectLAND : public TESForm
{
  public:
    TESObjectLAND();
    unsigned char formData[0x14];
};
class TESEffectShader : public TESForm
{
  public:
    TESEffectShader();
    unsigned char formData[0x158];
};
class BGSProjectile : public TESBoundObject
{
  public:
    BGSProjectile();
    unsigned char formData[0xa0];
};
class BGSExplosion : public TESBoundObject
{
  public:
    BGSExplosion();
    TESFullName fullName;
    unsigned char layout_3c[0x6c];
};
class BGSDebris : public TESForm
{
  public:
    BGSDebris();
    unsigned char formData[0xc];
};
class BGSTextureSet : public TESForm, public NiMemObject
{
  public:
    BGSTextureSet();
    static void InitializeNullTextureSet();
    unsigned char formData[0x88];
};
class NavMesh : public TESForm, public NiMemObject
{
  public:
    NavMesh();
    unsigned char formData[0xf0];
};
class BGSPerk : public TESForm
{
  public:
    BGSPerk();
    unsigned char formData[0x38];
};
class BGSBodyPartData : public TESForm
{
  public:
    BGSBodyPartData();
    static void InitializeBodyPartData();
    unsigned char formData[0x5c];
};
class BGSAddonNode : public TESBoundObject
{
  public:
    BGSAddonNode();
    void SetIndex(unsigned int);
    unsigned char formData[0x30];
};
class ActorValueInfo : public TESForm
{
  public:
    ActorValueInfo(int, const char*);
    unsigned char formData[0xac];
};
class BGSRadiationStage : public TESForm
{
  public:
    BGSRadiationStage();
    unsigned char formData[0x8];
};
class BGSDehydrationStage : public TESForm
{
  public:
    BGSDehydrationStage();
    unsigned char formData[0x8];
};
class BGSHungerStage : public TESForm
{
  public:
    BGSHungerStage();
    unsigned char formData[0x8];
};
class BGSSleepDeprivationStage : public TESForm
{
  public:
    BGSSleepDeprivationStage();
    unsigned char formData[0x8];
};
class BGSMessage : public TESForm
{
  public:
    BGSMessage();
    unsigned char formData[0x28];
};
class BGSRagdoll : public TESForm
{
  public:
    BGSRagdoll();
    unsigned char formData[0x130];
};
class BGSLightingTemplate : public TESForm
{
  public:
    BGSLightingTemplate();
    unsigned char formData[0x2c];
};
class BGSMusicType : public TESForm
{
  public:
    BGSMusicType();
    unsigned char formData[0x1c];
};
class BGSRecipe : public TESForm
{
  public:
    BGSRecipe();
    unsigned char formData[0x44];
};
class BGSRecipeCategory : public TESForm
{
  public:
    BGSRecipeCategory();
    unsigned char formData[0x10];
};
class TESAmmoEffect : public TESForm
{
  public:
    TESAmmoEffect();
    unsigned char formData[0x18];
};
class TESCasinoChips : public TESBoundObject
{
  public:
    TESCasinoChips();
    unsigned char formData[0x6c];
};
class TESLoadScreenType : public TESForm
{
  public:
    TESLoadScreenType();
    unsigned char formData[0x58];
};
class TESCasino : public TESBoundObject
{
  public:
    TESCasino();
    unsigned char formData[0x1f0];
};
class MediaSet : public TESForm
{
  public:
    MediaSet();
    unsigned char formData[0xac];
};
class MediaLocationController : public TESForm
{
  public:
    MediaLocationController();
    unsigned char formData[0xa0];
};
class TESCaravanCard : public TESBoundObject
{
  public:
    TESCaravanCard();
    unsigned char formData[0x8c];
};
class TESCaravanMoney : public TESBoundObject
{
  public:
    TESCaravanMoney();
    unsigned char formData[0x9c];
};
class TESCaravanDeck : public TESForm
{
  public:
    TESCaravanDeck();
    unsigned char formData[0x14];
};
class BGSMovableStatic : public TESFullName, public BGSDestructibleObjectForm, public TESObjectSTAT
{
  public:
    BGSMovableStatic();
    TESSound* soundLoop;
    unsigned char data;
};
class TESFlora : public TESProduceForm, public TESObjectACTI
{
  public:
    TESFlora();
};
const char* GetStringForByte(unsigned char);
template <class T> class NiTMallocInterface
{
};
template <class T> class NiTPointerList
{
  public:
    unsigned int data[3];
    void* Find(const T&, void*);
    void* GetHeadPos();
    T& GetNext(void*&);
    void AddTail(const T&);
};
template <class T, class A> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* data;
    unsigned short capacity, size, count, grow;
    T& GetAt(unsigned int);
    unsigned int GetSize();
    void SetAt(unsigned int, T&);
    unsigned int Add(T&);
};
class TESRegionList : public BSSimpleList<TESRegion*>
{
  public:
    virtual ~TESRegionList();
};
class TES
{
  public:
    void ProcessCellQueues(bool, bool);
    void ResetCachedValues();
};
class MobileObject : public TESObjectREFR
{
};
#endif
