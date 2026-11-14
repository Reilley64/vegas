// fallout/magic/magicshaderhiteffect_decls.h: declares NiPoint3, NiBound, NiUpdateData, NiFixedString, CloningProcess and more
#ifndef MAGICSHADERHITEFFECT_DECLS_H
#define MAGICSHADERHITEFFECT_DECLS_H

#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/B8C4890Actor.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/EffectShaderShell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_004aaf30_Holder.h"
#include "fnv/decl/FUN_00506370Class.h"
#include "fnv/decl/FUN_00506390Class.h"
#include "fnv/decl/FUN_005063b0Class.h"
#include "fnv/decl/FUN_00507040Class.h"
#include "fnv/decl/FUN_005077c0Class.h"
#include "fnv/decl/FUN_00507810Class.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d00_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00ba8560_cls.h"
#include "fnv/decl/ParticleInitializer.h"
#include "fnv/decl/ParticleUpdater.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/ShaderSource.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087ac00__Owner0087ac00.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00490000.h"
#include "fnv/symbols_00567000.h"
#include "fnv/symbols_00820000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
class NiNode;
class NiAVObject;
class ActiveEffect;
class TESBoundObject;
class BaseProcess;
class MagicShaderHitEffect;
class BipedAnim;
class NiSourceTexture;
class NiTimeController;
class BGSDebris;
class BSShaderPPLightingProperty;
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
};
struct NiBound
{
    NiPoint3 center;
    float radius;
};
struct NiUpdateData
{
    float time;
    unsigned int flags;
    unsigned int unused;
    NiUpdateData(float, bool, bool);
};
template <class T> class NiPointer
{
  public:
    T* object;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
    bool operator==(T*) const;
};
template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    T& GetAt(int);
    void FUN_006c61b0(const T&);
    void RemoveAll(bool);
};
template <class T> class NiTArray
{
  public:
    unsigned int GetSize();
    T& GetAt(unsigned int);
};
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList* GetNext();
    bool IsEmpty();
};
#include "fnv/native_fixed_string.h"
struct CloningProcess
{
  public:
    unsigned int data[7];
    CloningProcess(float);
    ~CloningProcess();
};
class NiMemObject
{
  public:
};
struct NiObjectNET : public NiMemObject
{
  public:
    virtual void vfn_0();
};
class NiAVObject : public NiObjectNET
{
  public:
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void AddObject(NiAVObject*, bool);
    unsigned char layout[0xa8];
    const NiPoint3& FUN_0045bb80();
};
class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short);
};
class NiTimeController : public NiAVObject
{
  public:
};
class TESForm
{
  public:
    virtual void vfn_0();
};
class TESBoundObject : public TESForm
{
};
class TESObjectACTI : public TESBoundObject
{
};
class TESObjectWEAP : public TESBoundObject
{
};
class TESObjectREFR
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
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
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
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
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode_v();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual BipedAnim* GetBipedAnim();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual const NiPoint3& GetPos();
};
class BaseProcess
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
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
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
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
    virtual bool vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
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
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
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
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
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
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
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
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual bool vfn_454();
};
class Actor : public TESObjectREFR
{
  public:
    void UpdateActorPresentation();
};
struct Biped;
class PlayerCharacter : public Actor
{
  public:
public:
    ::Biped *FUN_00950b00(bool);
};
struct BipedObject
{
    unsigned int unknown[2];
    NiAVObject* object;
};
class BipedAnim
{
  public:
};
class EffectSetting
{
  public:
};
class EffectSetting;
class ActiveEffect
{
  public:
    virtual void vfn_0();
    bool HasFlag(unsigned int);
public:
    ::EffectSetting *GetEffectSetting() const;
};
class InventoryItem
{
  public:
};
class DisintegrateArmorEffect : public ActiveEffect
{
  public:
    InventoryItem* GetItem();
};
class BGSTESTexture
{
  public:
    unsigned int GetModelLength() const;
};
struct ParticleShaderProperty
{
  public:
};
class ParticleShader
{
  public:
    static unsigned int GetShaderParticleCount();
};
class BSShaderPPLightingProperty
{
  public:
    class TextureEffectData
    {
      public:
        unsigned char data[0x6c];
        NiPointer<NiSourceTexture> spTexture;
    };
};
class TESEffectShader : public TESForm
{
  public:
    BGSDebris* GetAddonModels();
    char _pdbpad_4[20];
    char Data[308];
    char m_kFillTexture[12];
    char m_kParticleShaderTexture[12];
    char m_kHolesTexture[12];
};
class DebrisModelEntry
{
  public:
    signed char chance;
    const char* filename;
};
class DebrisModelEntry;
template <class> class BSSimpleList;
class BGSDebris
{
  public:
public:
    ::BSSimpleList< ::DebrisModelEntry *> *GetDataList();
};
template <class T> class WeightedResultList
{
  public:
    unsigned int data[9];
    WeightedResultList();
    ~WeightedResultList();
    void AddWeightedItem(T, unsigned int);
    T FindFirstItemExceedingRemaining();
};
class Model : public NiObjectNET
{
};
struct ModelLoader
{
  public:
};
class TES
{
  public:
};
struct SoundPlaybackHandle
{
  public:
    unsigned int id;
    bool assumeSuccess;
    unsigned int state;
    ~SoundPlaybackHandle();
};
struct BSAudio
{
  public:
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int);
};
struct TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
};
class MagicShaderHitEffect
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    unsigned int refCount;
    float m_fParticleParameter5;
    void* pCell;
    float tempAge;
    bool bInitialized;
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    float m_fFirstFloatValue;
    bool bWasPlaying;
    unsigned char layoutPadding25[3];
    bool m_bUseActorParticleEffects;
    TESBoundObject* m_pAffectedArmorObject;
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    BSSimpleArray<NiPointer<ParticleShaderProperty> > m_kParticleShaderProperties;
    NiPointer<NiNode> m_pParticleShaderNode;
    bool b3rdPerson;
    BSSimpleArray<NiPointer<NiAVObject> > m_kAddonModelObjects;
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;
    bool Init();
    void GetSceneGraphData(bool&, bool&, float&, NiAVObject*&, NiAVObject*&);
};
#endif
