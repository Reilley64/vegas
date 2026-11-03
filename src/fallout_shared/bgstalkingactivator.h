// Unit-local PC header for fallout_shared/bgstalkingactivator.cpp.
//   TESObjectACTI base (144 bytes), m_pTempRef +0x90, m_kFactionList +0x94
//   (152 bytes total).
// TESObject/TESBoundObject/TESBoundAnimObject are scaffolds flattened to
// member, no virtuals). TESMagicTargetForm (1-byte empty base) is omitted;
// the first field lands at +0x74 either way. Only sizes and polymorphism
// matter for this unit's codegen.
// TESSound/BGSVoiceType are minimal polymorphic derivations sufficient for
// the InitItem dynamic_cast and the SNAM/INAM/VNAM setters; their real
// definitions live in other units.
// The TESFormInitFlag / TESFileFormVersion / TESFullNameLoader shims follow
// the accepted bgsacousticspace.cpp / tescasinochips.h / tesrecipe.h
// precedents (canonical TESForm.h / TESFile.h / TESFullName.h do not declare
// other names at the same addresses):
//   TESScriptableForm::SetScript -> 0x006ecd40 (shared bytes with
//   TESModelTextureSwap::LoadTextureSwapChunk -> 0x0048a7b0,
//   BGSDestructibleObjectForm::LoadDestructibleData -> 0x004781e0,
//   BGSTalkingActivator::SetLoopSound -> 0x004febb0 (SNAM, writes +0x74),
//   BGSTalkingActivator::SetRadioTemplate -> 0x004febd0 (INAM, writes +0x7C),
//   BGSTalkingActivator::SetVoiceType -> 0x004febf0 (VNAM, writes +0x94).
#ifndef FNV_BGSTALKINGACTIVATOR_UNIT_H
#define FNV_BGSTALKINGACTIVATOR_UNIT_H

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c8000.h"
#include "layout_support.h"
#include "bgstalkingactivator_form.h"
#include "TESFullName.h"

class Script;
class TESObjectREFR;
class TESWaterForm;
class BGSTalkingActivator;

// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it, so
// it is declared on this shim, following the accepted tessound.cpp precedent.
struct TESFormInitFlag : public TESForm
{
};

// TESFile::GetFormVersion is not declared in the bundled TESFile.h; its
// mangled name (TESFileFormVersion::GetFormVersion, 0x00403570) shows the
// canonical declaration site, so it is declared on this shim, following the
// accepted tescasinochips.h precedent.
struct TESFileFormVersion : public TESFile
{
};

// TESFullName::LoadFullNameChunk is not declared in the bundled TESFullName.h;
// declared here on a shim following the accepted tesrecipe.h precedent.

class TESSound : public TESForm
{
};

class BGSVoiceType : public TESForm
{
};

class TESModel : public BaseFormComponent
{
  public:
    unsigned char modelData[0x14];
    static void LoadModelData(TESModel* apModel, TESFile* apFile);
};

class TESModelTextureSwap : public TESModel
{
  public:
    unsigned char swapData[8];
};

class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9[3];
    void InitItem(TESForm* apForm);
};

class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    void* pData;
};

class BGSOpenCloseForm
{
  public:
    void* m_ppVirtualMethodTable;  // +0x0
};

class TESObject : public TESForm
{
  public:
    unsigned char layoutPadding18[0xC];  // +0x18 parent list, prev, next
};

class TESBoundObject : public TESObject
{
  public:
    unsigned char layoutPadding24[0xC];  // +0x24 bound min/max
};

class TESBoundAnimObject : public TESBoundObject
{
};

class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm
{
  public:
    // base TESBoundAnimObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESScriptableForm at +0x5C, size 12
    // base BGSDestructibleObjectForm at +0x68, size 8
    // base BGSOpenCloseForm at +0x70, size 4
    TESSound* m_pSoundEffect;                  // +0x74
    TESSound* m_pLoopSound;                    // +0x78
    TESSound* pRadioTemplate;                  // +0x7C
    TESWaterForm* m_pWaterForm;                // +0x80
    BGSTalkingActivator* m_pTalkingActivator;  // +0x84
    BSStringT<char> cActivateTextOverride;     // +0x88
    void ResetFormData();
    virtual void InitItem();
    void SetLoopingSound(TESSound* apSound);
};


class BGSTalkingActivator : public TESObjectACTI
{
  public:
    TESObjectREFR* m_pTempRef;     // +0x90
    BGSVoiceType* m_kFactionList;  // +0x94
    virtual void ResetFormData();
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    void SetRadioTemplate(TESSound* apSound);
    void SetVoiceType(BGSVoiceType* apVoice);
    bool IsRadioStation();
    static bool IsRadioStation(TESForm*, unsigned int);
    static void AddRadioStation(TESObjectREFR*);
    static void FindRadioStations(TESObjectREFR*, BSSimpleList<TESObjectREFR*>*, BSSimpleList<float>*);
};
#endif
