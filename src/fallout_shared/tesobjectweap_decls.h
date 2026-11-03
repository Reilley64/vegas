// fallout_shared/tesobjectweap_decls.h: declares TESFullName, TESTexture, TESIcon, TESScriptableForm, TESHealthForm and more
#ifndef TESOBJECTWEAP_DECLS_H
#define TESOBJECTWEAP_DECLS_H

#include <cstring>
#include <malloc.h>
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004ad010_shell.h"
#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/FUN_0051f4b0_shell.h"
#include "fnv/decl/FUN_0051f4d0_class.h"
#include "fnv/decl/FUN_0051f4f0_Class.h"
#include "fnv/decl/FUN_0051f530_class.h"
#include "fnv/decl/FUN_00524b60_shell.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0067ff10__FUN_0067ff10_Class.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "layout_support.h"
class SpellItem;
class Script;
class MagicItem;
class BSFileEntry;
class TESLandTexture;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
class NiAVObject;
class QueuedFile;
enum ActorValue__Index
{
    ActorValue__Index_None = -1
};
#include "BaseFormComponent.h"
#include "TESForm.h"

#include "layout_support.h"
class BGSAmmoForm;
class BGSBipedModelList;
class BGSClipRoundsForm;
class BGSDestructibleObjectForm;
class BGSEquipType;
class BGSImpactDataSet;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BGSPreloadable;
class BGSProjectile;
class BGSRepairItemList;
class BSFileEntry;
class CollisionComponent;
class EnchantmentItem;
class ShortPoint3;
class WeaponProperties;
class WeaponCriticalData;
class WeaponVATSData;
class TESAttackDamageForm;
class TESBoundObject__BOUND_DATA;
class TESEffectShader;
class TESEnchantableForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectIMOD;
class TESFormList;
class TESObjectSTAT;
class TESObjectWEAP;
class FileEntryList;
class TESValueForm;
class TESWeightForm;
class DistantTreeTextureInfo;
enum MagicSystem__CastingType
{
    MagicSystem__CastingType_CAST_ONCE = 0,
    MagicSystem__CastingType_WHEN_USED = 1,
    MagicSystem__CastingType_WHEN_STRIKES = 2,
    MagicSystem__CastingType_CONSTANT_EFFECT = 3,
    MagicSystem__CastingType_CASTING_COUNT = 4
};
enum BGSEquipType__EQUIP_TYPE
{
    BGSEquipType__EQUIP_TYPE_ET_NONE = -1,
    BGSEquipType__EQUIP_TYPE_ET_BIG_GUN = 0,
    BGSEquipType__EQUIP_TYPE_ET_ENERGY_WEAPON = 1,
    BGSEquipType__EQUIP_TYPE_ET_SMALL_GUN = 2,
    BGSEquipType__EQUIP_TYPE_ET_MELEE_WEAPON = 3,
    BGSEquipType__EQUIP_TYPE_ET_UNARMED_WEAPON = 4,
    BGSEquipType__EQUIP_TYPE_ET_THROWN_WEAPON = 5,
    BGSEquipType__EQUIP_TYPE_ET_MINE = 6,
    BGSEquipType__EQUIP_TYPE_ET_BODY_WEAR = 7,
    BGSEquipType__EQUIP_TYPE_ET_HEAD_WEAR = 8,
    BGSEquipType__EQUIP_TYPE_ET_HAND_WEAR = 9,
    BGSEquipType__EQUIP_TYPE_ET_CHEMS = 10,
    BGSEquipType__EQUIP_TYPE_ET_STIMPACK = 11,
    BGSEquipType__EQUIP_TYPE_ET_FOOD = 12,
    BGSEquipType__EQUIP_TYPE_ET_ALCOHOL = 13,
    BGSEquipType__EQUIP_TYPE_ET_COUNT = 14
};
enum WEAPONHITBEHAVIOR
{
    WEAPONHITBEHAVIOR_WHB_NORMAL = 0,
    WEAPONHITBEHAVIOR_WHB_DISMEMBER_ONLY = 1,
    WEAPONHITBEHAVIOR_WHB_EXPLODE_ONLY = 2,
    WEAPONHITBEHAVIOR_WHB_NO_DISMEMBER_OR_EXPLODE = 3
};
enum WEAPON_RUMBLE_PATTERN
{
    WEAPON_RUMBLE_PATTERN_RUMBLE_CONSTANT = 0,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SQUARE = 1,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_TRIANGLE = 2,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SAWTOOTH = 3,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PATTERN_COUNT = 4
};
enum WEAPON_MOD_EFFECT
{
    WEAPON_MOD_EFFECT_WEAPON_MOD_NONE = 0,
    WEAPON_MOD_EFFECT_WEAPON_MOD_INCREASE_WEAPON_DAMAGE = 1,
    WEAPON_MOD_EFFECT_WEAPON_MOD_INCREASE_CLIP_SIZE = 2,
    WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_SPREAD = 3,
    WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_WEIGHT = 4,
    WEAPON_MOD_EFFECT_WEAPON_MOD_AMMO_REGEN_SHOT = 5,
    WEAPON_MOD_EFFECT_WEAPON_MOD_AMMO_REGEN_SECONDS = 6,
    WEAPON_MOD_EFFECT_WEAPON_MOD_EQUIP_SPEED = 7,
    WEAPON_MOD_EFFECT_WEAPON_MOD_FIRE_SPEED = 8,
    WEAPON_MOD_EFFECT_WEAPON_MOD_PROJECTILE_SPEED = 9,
    WEAPON_MOD_EFFECT_WEAPON_MOD_MAX_HEALTH = 10,
    WEAPON_MOD_EFFECT_WEAPON_MOD_SILENCE = 11,
    WEAPON_MOD_EFFECT_WEAPON_MOD_SPLIT_BEAM = 12,
    WEAPON_MOD_EFFECT_WEAPON_MOD_VATS_BONUS = 13,
    WEAPON_MOD_EFFECT_WEAPON_MOD_IRON_SITES = 14,
    WEAPON_MOD_EFFECT_WEAPON_MOD_VATS_SPECIAL_ATTACK = 15,
    WEAPON_MOD_EFFECT_WEAPON_MOD_EFFECT_COUNT = 16
};
enum SOUND_LEVEL
{
    SOUND_LEVEL_SOUND_LEVEL_LOUD = 0,
    SOUND_LEVEL_SOUND_LEVEL_NORMAL = 1,
    SOUND_LEVEL_SOUND_LEVEL_SILENT = 2,
    SOUND_LEVEL_SOUND_LEVEL_COUNT = 3
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
    ~TESFullName();
};
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char padding[3];
    TESScriptableForm();
    void InitItem(TESForm*);
};
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;
    TESHealthForm();
    ~TESHealthForm();
};
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;
    TESObject* m_pPreviousObject;
    TESObject* m_pNextObject;
};
class ShortPoint3
{
  public:
    short x;
    short y;
    short z;
};
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;
    ShortPoint3 m_kBoundMax;
};
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject();
    ~TESBoundObject();
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;
};
class TESModel : public BaseFormComponent
{
  public:
    TESModel();
    ~TESModel();
    virtual void vfn_10(int, class QueuedFile*);
    virtual void vfn_14();
    virtual void SetModelFilePath(const char*);
    unsigned int GetModelLength() const;
    static void LoadModelData(TESModel*, TESFile*);
    BSStringT<char> m_kModelFilePath;
    FileEntryList m_pTextureSwapData;
    unsigned char cFlags;
    unsigned char layoutPadding15[3];
};
class TESModelTextureSwap : public TESModel
{
  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void InitItem(TESForm*);
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;
};
class TESEnchantableForm : public BaseFormComponent
{
  public:
    TESEnchantableForm();
    void InitItem(TESForm*);
    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    unsigned char layoutPaddingA[2];
    MagicSystem__CastingType m_eCastingType;
public:
    void SetFormEnchantmentAmount(unsigned short);
};
class TESValueForm : public BaseFormComponent
{
  public:
    TESValueForm();
    ~TESValueForm();
    unsigned int iValue;
};
class TESWeightForm : public BaseFormComponent
{
  public:
    TESWeightForm();
    ~TESWeightForm();
    float fWeight;
};
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    TESAttackDamageForm();
    ~TESAttackDamageForm();
    unsigned short m_usAttackDamage;
    unsigned char layoutPadding6[2];
};
class BGSAmmoForm : public BaseFormComponent
{
  public:
    BGSAmmoForm();
    void InitItem(TESForm*);
    TESForm* m_pAmmo;
};
class BGSClipRoundsForm : public BaseFormComponent
{
  public:
    BGSClipRoundsForm();
    ~BGSClipRoundsForm();
    unsigned char m_ucClipRounds;
    unsigned char layoutPadding5[3];
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    void InitItem(TESForm*);
    CollisionComponent* pData;
};
class BGSRepairItemList : public BaseFormComponent
{
  public:
    BGSRepairItemList();
    ~BGSRepairItemList();
    void InitItem(TESForm*);
    BGSListForm* pListForm;
};
class BGSEquipType : public BaseFormComponent
{
  public:
    BGSEquipType();
    BGSEquipType__EQUIP_TYPE m_eEquipType;
};
class BGSPreloadable : public BaseFormComponent
{
  public:
    BGSPreloadable();
    virtual void QueueResourceLoad(int, class QueuedFile*);
};
class BGSMessageIcon : public BaseFormComponent
{
  public:
    BGSMessageIcon();
    ~BGSMessageIcon();
    TESIcon Icon;
};
class BGSBipedModelList : public BaseFormComponent
{
  public:
    BGSBipedModelList();
    ~BGSBipedModelList();
    void InitItem(TESForm*);
    BGSListForm* pListForm;
};
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm*);
    TESSound* m_pPickupSound;
    TESSound* m_pPutdownSound;
};
class WeaponProperties
{
  public:
    char eType;
    unsigned char layoutPadding1[3];
    float fSpeed;
    float ActorTypeValueEntry;
    unsigned char cFlags;
    unsigned char m_ucGripAnimation;
    unsigned char m_ucAmmoUse;
    unsigned char m_ucReloadAnimation;
    float m_fMinimumSpread;
    float fBodyPartChance;
    float m_fUnknownFloat;
    float AmmunitionData;
    unsigned char m_ucSubtype;
    unsigned char layoutPadding21[3];
    BGSProjectile* pProjectile;
    unsigned char m_ucBaseVATSChance;
    unsigned char m_ucAttackAnimation;
    unsigned char m_ucProjectileCount;
    unsigned char m_ucFourthByte;
    float m_fMinimumRange;
    float m_fMaximumRange;
    WEAPONHITBEHAVIOR m_eHitBehavior;
    unsigned int WeaponAttackData;
    float m_fAnimationAttackMultiplier;
    float m_fOverrideActionPoints;
    float m_fLeftRumbleMotorStrength;
    float m_fRightRumbleMotorStrength;
    float m_fRumbleDuration;
    float m_fOverrideDamageToWeaponMultiplier;
    float m_fAttackShotsPerSecond;
    float fWeaponDamageMultiplier;
    float WeaponCombatData;
    float WeaponHandlingData;
    float WeaponFiringData;
    ActorValue__Index m_eWeaponSkill;
    WEAPON_RUMBLE_PATTERN m_eRumblePattern;
    float WeaponFiringParameters;
    float m_fLimbDamageMultiplier;
    ActorValue__Index m_eResistanceType;
    float m_fSightUsage;
    float m_fMinimumSemiAutomaticFireDelay;
    float m_fMaximumSemiAutomaticFireDelay;
    float m_fFourthModifierValue;
    WEAPON_MOD_EFFECT m_eFirstWeaponModEffect;
    WEAPON_MOD_EFFECT m_eSecondWeaponModEffect;
    WEAPON_MOD_EFFECT m_eThirdWeaponModEffect;
    float m_fModValueA1;
    float m_fModValueA2;
    float m_fModValueA3;
    unsigned char m_ucPowerAttackAnimationOverride;
    unsigned char layoutPaddingA5[3];
    unsigned int m_uiStrengthRequirement;
    char m_cUnknownByte;
    char m_cReloadAnimationMod;
    unsigned char layoutPaddingAE[2];
    float FlaggedFloatData;
    float m_fKillImpulse;
    float m_fModValueB1;
    float m_fModValueB2;
    float m_fModValueB3;
    float FourFloatsAndUnsignedInteger;
    unsigned int m_uiSkillRequirement;
};
class WeaponCriticalData
{
  public:
    unsigned short m_usCriticalDamage;
    unsigned char layoutPadding2[2];
    float m_fCriticalChanceMultiplier;
    bool m_bEffectOnDeath;
    unsigned char layoutPadding9[3];
    SpellItem* pEffect;
};
class WeaponVATSData
{
  public:
    SpellItem* m_pVATSAttackSpell;
    float m_fSkill;
    float m_fDamageMultiplier;
    float m_fActionPointCost;
    bool bSilent;
    bool m_bModRequired;
    unsigned char cFlags;
    unsigned char layoutPadding13[1];
};
class TESObjectIMOD;
class TESObjectWEAP : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESAttackDamageForm,
                      public BGSAmmoForm,
                      public BGSClipRoundsForm,
                      public BGSDestructibleObjectForm,
                      public BGSRepairItemList,
                      public BGSEquipType,
                      public BGSPreloadable,
                      public BGSMessageIcon,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds
{
  public:
    TESObjectWEAP();
    virtual ~TESObjectWEAP();
    void ResetFormData();
    virtual void ClearData();
    virtual void InitItem();
    bool Load(TESFile*);
    void QueueResourceLoad(int, class QueuedFile*, bool);
    unsigned char GetDamageForActor(bool, bool, Actor*);
    ActorValue__Index GetResistance();
    int GetReloadAnim(bool);
    void SetMeleeBlockSound(TESSound*);
    WeaponProperties data;
    WeaponCriticalData m_kCriticalData;
    TESModel m_kModel;
    TESModel m_kModel1stPerson;
    TESModel m_kModel3rdPerson;
    TESEffectShader* m_pWeaponEffectShader;
    TESSound* m_pWeaponSound1;
    TESSound* m_pWeaponSound2;
    TESSound* m_pWeaponSound3;
    TESSound* m_pWeaponSound4;
    TESSound* m_pWeaponSound5;
    TESSound* m_pWeaponSound6;
    TESSound* m_pWeaponSound7;
    TESSound* m_pWeaponSound8;
    TESSound* m_pWeaponUnequipSound;
    TESSound* m_pWeaponEquipSound;
    TESSound* m_pWeaponPickupSound;
    TESSound* m_pWeaponDropSound;
    BGSImpactDataSet* m_pImpactDataSet;
    TESObjectSTAT* p1stPersonObject;
    TESObjectSTAT* p1stPersonMod1Object;
    TESObjectSTAT* p1stPersonMod2Object;
    TESObjectSTAT* p1stPersonMod3Object;
    TESObjectSTAT* p1stPersonMod12Object;
    TESObjectSTAT* p1stPersonMod23Object;
    TESObjectSTAT* p1stPersonMod13Object;
    TESObjectSTAT* p1stPersonMod123Object;
    TESModelTextureSwap m_kWeaponModTextureSwap1;
    TESModelTextureSwap m_kWeaponModTextureSwap2;
    TESModelTextureSwap m_kWeaponModTextureSwap3;
    TESModelTextureSwap m_kWeaponModTextureSwap4;
    TESModelTextureSwap m_kWeaponModTextureSwap5;
    TESModelTextureSwap m_kWeaponModTextureSwap6;
    TESModelTextureSwap m_kWeaponModTextureSwap7;
    TESObjectIMOD* m_pWeaponMod1;
    TESObjectIMOD* m_pWeaponMod2;
    TESObjectIMOD* m_pWeaponMod3;
    BSStringT<char> m_kEmbeddedWeaponNodeName;
    SOUND_LEVEL m_eSoundLevel;
    BSStringT<char> VATSAttackName;
    WeaponVATSData m_kVATSData;
    bool m_bHasReloadAnimation;
    unsigned char layoutPadding385[3];
public:
    void SetModItem(unsigned int, ::TESObjectIMOD *);
};
class TESFileFormVersion : public TESFile
{
  public:
};
class TESFileChunkData16 : public TESFile
{
  public:
};

class TESAmmo : public TESBoundObject
{
  public:
};
class BGSProjectile : public TESBoundObject, public TESFullName, public TESModel, public BGSPreloadable
{
};
class BGSImpactDataSet : public TESForm, public BGSPreloadable
{
};
class TESEffectShader : public TESForm
{
};
class SpellItem : public TESForm
{
};
class TESSound : public TESBoundObject
{
};
class TESObjectSTAT : public TESBoundObject
{
};
class TESObjectIMOD : public TESBoundObject
{
};
class ModelLoader
{
  public:
};
class TES
{
  public:
};
class TESFormInitFlag : public TESForm
{
  public:
};
class BGSImpactData : public TESForm
{
  public:
};
class ActorValue
{
  public:
};
bool FUN_0066eba0(ActorValue__Index);
union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    char* s;
};
class INISettingCollection;
template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
#endif
