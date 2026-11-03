// fallout_shared/tesobjectrefr_decls.h: declares TESObjectREFR, DurationData
#ifndef FNV_TESOBJECTREFR_DECLS_H
#define FNV_TESOBJECTREFR_DECLS_H

// Private declarations for fallout_shared/tesobjectrefr.cpp (unit army-glm-5257).
// Signatures follow the canonical bindings from IDENTITIES.md / lookup sym;
// layouts here are minimal and private to this translation unit.

#include "fnv/decl/NiTMap_S.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011f6000.h"
union SETTING_VALUE
{
    float f;
};

class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

class GlobalObject_00559cc0
{
  public:
};
extern GlobalObject_00559cc0 g_011ca304;

class GlobalObject_00593240
{
  public:
    char storage[4];
};
extern GlobalObject_00593240 g_011ca8b4;

class GlobalObject_00878030
{
  public:
    char storage[4];
};
extern GlobalObject_00878030 g_011deffc;

class GarbageCollectorUpdateState;

class BGSEncounterZone;
extern unsigned char DAT_011dd435;

class BSExtraData;
class ExtraRadioData;
class TESObjectCELL;
class TESModel;
class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    unsigned char pad[0x14];
    void* kChildCell;      // +0x18, the TESChildCell base
    void* pLoopSound;      // +0x1C
    void* unk20;
    float unk24;
    float fRotY;           // +0x28
    float unk2c;
    float afPosition[3];   // +0x30
    float m_fObjectScale;  // +0x3C
    TESObjectCELL* pParentCell;     // +0x40
    unsigned char kExtraList[0x20];  // +0x44, an ExtraDataList
    void* pLoadedData;              // +0x64
    static BGSEncounterZone* FindEncounterZone();
    float GetScale();
public:
    ::BSExtraData *GetExtraData(unsigned char) const;
public:
    ::ExtraRadioData *GetExtraRadioData();
public:
    const char *GetModelFilePath();
public:
    ::TESModel *GetTESModel();
};

class DurationData
{
  public:
    char month;  // +0x0
    int FUN_00678ca0();
};

#endif
