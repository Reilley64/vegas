// fallout_shared/bgsbodypart_decls.h: declares TESFileFormVersion, TESFile, TESForm, BGSExplosion, BGSDebris and more
#ifndef FNV_BGSBODYPART_DECLS_H
#define FNV_BGSBODYPART_DECLS_H


#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_005e3fe0_class.h"
#include "fnv/decl/FUN_00994ef0_Class.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
class TESFileFormVersion
{
  public:
};
class TESFile
{
  public:
    bool NextChunk();
    bool IsEndianConversionRequired();
};
class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();
    bool GetInitialized() const;
    TESFile* GetFile(int);
};
class BGSExplosion : public TESForm
{
};
class BGSDebris : public TESForm
{
};
class BGSImpactDataSet : public TESForm
{
};
class TESObjectREFR;
class DialogueItem
{
  public:
    TESObjectREFR* SelectDefaultResponseList();
};
class BaseProcess;
class Actor
{
  public:
};
class TESSound;
class TESEffectShader;
class EffectSetting
{
  public:
    TESSound* GetCastSound();
};
class Tile;
class InterfaceManager
{
  public:
    void FUN_00500a20(Tile*);
};
enum IO_TASK_PRIORITY
{
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_CRITICAL = 0,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_VERY_HIGH = 1,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_HIGH = 2,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_MID = 3,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_LOW = 4,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_VERY_LOW = 5,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_COUNT = 6,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_INVALID = 7
};

class QueuedFile;
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
public:
    static const ::NiPoint3 ZERO;
};

class BodyPartInfo
{
  public:
    BodyPartInfo();
    float m_fDamageMultiplier;
    unsigned char cFlags;
    unsigned char cType;
    unsigned char m_ucPartID;
    char m_cActorValue;
    unsigned char m_ucHealthPercent;
    unsigned char m_ucHitChance;
    unsigned char m_ucLimbReplacementType;
    unsigned char layoutPaddingB;
    void* m_pExplosion;
    void* m_pDebrisObject;
    float m_fExplosionChance;
    float m_fDebrisScale;
    unsigned char m_ucSeverable;
    unsigned char layoutPadding1D[3];
    void* m_pRelatedObject1;
    void* m_pRelatedObject2;
    float m_fValue3;
    NiPoint3 m_kPoint1;
    NiPoint3 m_kPoint2;
    void* m_pRelatedObject3;
    void* m_pRelatedObject4;
    unsigned char m_ucByte1;
    unsigned char m_ucByte2;
    unsigned char layoutPadding4E[2];
    float m_fValue4;

    void Initialize();
};

class TESModel
{
  public:
    unsigned char storage[20];
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18(const char*);
    static void LoadModelData(TESModel*, TESFile*);
    TESModel();
    ~TESModel();
    unsigned int GetModelLength() const;
};

class ModelLoader
{
  public:
};

template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    bool Set(const T*, unsigned int);
};
class FUN_005e3be0
{
  public:
    unsigned char storage[24];
    FUN_005e3be0();
    ~FUN_005e3be0();
};
extern "C" void* memset(void*, int, unsigned int);

class BGSBodyPart
{
  public:
    BSStringT<char> NodeName;
    BSStringT<char> TargetName;
    BSStringT<char> m_kVATSNodeName;
    BSStringT<char> m_kPartName;
    BSStringT<char> m_kGoreName;
    TESModel m_kModel;
    FUN_005e3be0 m_kRagdollModel;
    BodyPartInfo Data;

    BGSBodyPart();
    void InitItem(TESForm*);
    bool Load(TESFile*);
    virtual void vfn_00();
    void QueueResourceLoad(IO_TASK_PRIORITY, QueuedFile*);
};

class Queueable18
{
  public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void QueueResourceLoad(IO_TASK_PRIORITY, QueuedFile*) = 0;
};

#endif
