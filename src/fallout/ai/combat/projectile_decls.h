// fallout/ai/combat/projectile_decls.h: declares PlayerCharacter, TESObjectREFR_LoadProxy, TESForm, TESChildCell, MobileObject and more
#ifndef PROJECTILE_DECLS_H
#define PROJECTILE_DECLS_H


#include "fnv/decl/RefLoad.h"
#include "fnv/decl/fnv_00ae5a50__Mgr_00ae5a50.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
class TESFile;

class PlayerCharacter
{
  public:
    bool IsSleepingOrResting();
};

class TESObjectREFR_LoadProxy
{
  public:
};

class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char padding[3];
    int eState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
public:
    bool SetPositionFromArray(float *);
public:
    bool IsValid() const;
public:
    bool Release();
public:
    bool StopWithFade(unsigned int);
};

class TESForm
{
  public:
    virtual void Primary();
    char primaryData[0x14];
    void SetInitializationState(bool);
public:
    void ClearData();
public:
    void SetDestructible(bool);
};
class TESChildCell
{
  public:
    virtual void Secondary();
};
class BGSLoadFormBuffer;
class MobileObject : public TESForm, public TESChildCell
{
  public:
    MobileObject();
    ~MobileObject();
    char mobilePad[0x4c];
    unsigned int word68;
    char mobileTail[0x1c];
public:
    float GetLooking() const;
public:
    void Revert(::BGSLoadFormBuffer *);
};
class InventoryStackRecord;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    ~BSSimpleList();
    unsigned int items[2];
};
class NiTransform
{
  public:
    NiTransform();
    void ResetToIdentity();
    char storage[0x34];
};
class NiPoint2
{
  public:
    NiPoint2();
    unsigned int data[2];
};
class NiPoint3
{
  public:
    static const NiPoint3 ZERO;
    unsigned int data[3];
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float GetLengthSquared();
public:
    float ComputeMagnitude() const;
};
class NiAVObject;
template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    T* value;
};
class ActorCause;
class Projectile : public MobileObject
{
  public:
    Projectile(bool);
    bool Load(TESFile*);
    bool IsProximityDetonationTriggered();
    virtual void Primary();
    virtual void Secondary();
    BSSimpleList<InventoryStackRecord*> list;
    unsigned char byte90;
    char pad91[3];
    NiTransform transform;
    unsigned int wordC8;
    float floatCC, floatD0, floatD4, floatD8, floatDC, floatE0;
    float floatE4, floatE8, floatEC, floatF0, floatF4;
    unsigned int wordF8, wordFC, word100;
    NiPoint2 position;
    float positionZ;
    float float110;
    NiPointer<NiAVObject> visualA;
    unsigned char byte118;
    char pad119[3];
    NiPointer<NiAVObject> visualB;
    NiPointer<ActorCause> cause;
    float float124;
    SoundPlaybackHandle soundA, soundB;
    unsigned int word140, word144;
    unsigned char byte148;
    char pad149[3];
    float float14C;
public:
    void FUN_009bc8f0();
};
class FlameProjectile : public Projectile
{
  public:
    bool IsProximityDetonationTriggered();
};

class BSAudioManager
{
  public:
};

#endif
