// Unit-private declarations with layouts verified against the packet PC disassembly.
#ifndef FNV_ACTIVEFFECT_LOCAL_H
#define FNV_ACTIVEFFECT_LOCAL_H

#include "fnv/decl/BGSDebris.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/FUN_004044d0_shell.h"
#include "fnv/decl/FUN_00408680_shell.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_00693d50_shell.h"
#include "fnv/decl/FUN_007df210_shell.h"
#include "fnv/decl/FUN_00833c20_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_00804000.h"
#include "fnv/symbols_00806000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_011e0000.h"
#include "layout_support.h"
#include "magichiteffect_classes.h"
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char layoutPadding5[3];
    BSSoundHandle__ASSUMED_STATE eState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
public:
    bool IsValid() const;
public:
    bool Release();
};
class EffectSetting;
class EffectItem;
class MagicHitEffect;
class MagicCaster;
class MagicTarget;
class MagicItem;
class TESBoundObject;
class Actor;
class BGSLoadFormBuffer;
class BGSPerkEntry;
class BGSSaveFormBuffer;
template <typename T> class BSSimpleList;
enum MagicSystem__SpellType
{
    MagicSystem__SpellType_SPELL = 0,
    MagicSystem__SpellType_DISEASE = 1,
    MagicSystem__SpellType_POWER = 2,
    MagicSystem__SpellType_LESSER_POWER = 3,
    MagicSystem__SpellType_ABILITY = 4,
    MagicSystem__SpellType_POISON = 5,
    MagicSystem__SpellType_ENCHANTMENT = 6,
    MagicSystem__SpellType_POTION = 7,
    MagicSystem__SpellType_WORTCRAFT = 8,
    MagicSystem__SpellType_LEVELED_SPELL = 9,
    MagicSystem__SpellType_ADDICTION = 10,
    MagicSystem__SpellType_SPELL_TYPE_COUNT = 11
};
class EffectSetting;
class ActiveEffect
{
  public:
    virtual ~ActiveEffect();                                    // v00
    virtual ActiveEffect* Copy();                               // v04
    virtual void Finalize();                                    // v08
    virtual void Update(float afElapsedSeconds);                // v0C
    virtual unsigned short GetSaveSize(Actor* apActor);         // v10
    virtual void SaveGame(Actor* apActor);                      // v18
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);         // v14
    virtual void LoadGame(Actor* apActor);                      // v20
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);         // v1C
    virtual void InitLoadGame(Actor* apActor);                  // v28
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);     // v24
    virtual void FinishLoadGameTES(Actor* apActor);             // v2C
    virtual void Revert(Actor* apActor);                        // v34
    virtual void Revert(BGSLoadFormBuffer* apBuffer);           // v30
    virtual bool CanApply(MagicCaster* apCaster);               // v38
    virtual bool CanFinish();                                   // v3C
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);  // v40
    virtual void CopyData(ActiveEffect* apOther);               // v44
    virtual bool CanCast(MagicCaster* apCaster);                // v48
    virtual bool IsEffectValid(MagicTarget* apTarget);          // v4C
    virtual void Start();                                       // v50
    virtual void Continue();                                    // v54
    virtual void Finish();                                      // v58
    ActiveEffect(MagicCaster*, MagicItem*, EffectItem*);
    void AddFlags(unsigned int);
    bool IsFlagged();
    bool HasFlag(unsigned int);
    float m_fEffectMagnitude;
    MagicItem* pSpell;
    EffectItem* pEffect;
    bool bActive;
    bool bEffectFlag;
    bool bWasPlaying;
    bool bPickResultFound;
    bool m_bEffectState;
    unsigned char layoutPadding15[3];
    int iFlags;
    float m_fElapsedTime;
    float fDuration;
    MagicTarget* pTarget;
    MagicCaster* m_pEffectInstance;
    MagicSystem__SpellType m_eSpellType;
    SoundPlaybackHandle m_kSoundHandle;
    TESBoundObject* pSource;
    BSSimpleList<MagicHitEffect*>* pHitEffectList;
    MagicItem* pMagicItem;
    void AdvanceEffect(float, bool);
    void SetEffectiveness(float);
    static void LoadActiveEffectList(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);
    static ActiveEffect* ReadActiveEffect(BGSLoadFormBuffer*);
    static void WriteActiveEffectList(BGSLoadFormBuffer* pBuffer, BSSimpleList<ActiveEffect*>* pList);
public:
    ::EffectSetting *GetEffectSetting() const;
public:
    float GetDuration() const;
};
template <> class BSSimpleList<BGSPerkEntry*>
{
  public:
    BGSPerkEntry*& GetItem();
};
template <> class BSSimpleList<MagicHitEffect*>
{
  public:
    MagicHitEffect* m_item;
    BSSimpleList<MagicHitEffect*>* m_pkNext;
    MagicHitEffect*& GetItem();
    bool IsEmpty();
    void RemoveAll();
};

class TESSound;
class EffectSetting
{
  public:
    char data[0x98];
    int archetype;
    int GetArchetype();
public:
    ::TESSound *GetHitSound();
};
class BGSLoadGameBuffer
{
  public:
};
class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
};
template <> class BSSimpleList<ActiveEffect*>
{
  public:
};
void InitLoadGameForEffects(Actor*, BSSimpleList<ActiveEffect*>*);
class BSTempEffect;
class ProcessLists
{
  public:
};
class GlobalObject_0096d020 : public ProcessLists
{
};
class PerkEntryConditionSet;
class EffectItem
{
  public:
};
class TESObjectREFR;
class PerkEntryConditionSet
{
  public:
    BGSPerkEntry*& GetItem();
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*);
};
class EffectItemList
{
  public:
};
class MagicEffectSystem
{
  public:
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
class ActorPackageContext
{
  public:
};
extern const char DAT_010794a8[];
template <> class BSSimpleList<const char*>
{
  public:
    bool IsEmpty();
};
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
};
class GlobalObject_0040e0b0 : public SettingT_GameSettingCollection_
{
};
extern GlobalObject_0040e0b0 g_011d17dc;
extern "C" double floor(float);
class ActiveEffectCasterDispatch
{
  public:
    virtual void vfn_00();
    virtual TESObjectREFR* GetCasterReference();
    virtual BSSimpleList<BGSPerkEntry*>* GetActiveEffectList();
};
class ActorPrimary
{
  public:
    virtual void vfn_00();
    char data[0x90];
};
class ActorValueOwner
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int GetActorValue(int);
};
#endif
