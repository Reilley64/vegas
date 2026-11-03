// fallout_shared/magic/effectsettingcollection.cpp: EffectSettingCollection (3 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_004078a0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004ee4b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00409000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "TESForm.h"

class TESSound;
class EffectSetting : public TESForm
{
    unsigned char layoutPadding18[0x98];

  public:
    EffectSetting();
    void UpdateEffectName(const char* name);
public:
    ::TESSound *GetHitSound();
};

class TargetDoorController;
class Date;

class LowProcess
{
  public:
    void SetPackageObjectType(intptr_t value);
};

class TargetDoorController;
class MiddleHighProcess
{
  public:
    void AddDeferredHideLimb(TargetDoorController* value);
public:
    void SetFaceAnimationData(::TargetDoorController *);
};

class PlayerQuestData
{
  public:
};


typedef int ActorValueIndex;

class EffectSettingCollection
{
  public:
    unsigned char layoutPadding0[0x3E8];
    unsigned int uiFlags;

    void InitializeCollection(bool initialize);
    static void InitializeEffectSettings();
    static EffectSetting* CreateEffectSetting(unsigned int formID, char* editorID, char* fullName, ActorValueIndex item,
                                              float cost, ActorValueIndex skill, unsigned int count,
                                              ActorValueIndex resist, int flags);
};


// @fnv 0x00471D00
void EffectSettingCollection::InitializeCollection(bool initialize)
{
    if (initialize)
        uiFlags |= 4;
    else
    {
        uiFlags &= ~4;
        uiFlags &= ~8;
    }
}

// @fnv 0x00408E40
EffectSetting* EffectSettingCollection::CreateEffectSetting(unsigned int formID, char* editorID, char* fullName,
                                                            ActorValueIndex item, float cost, ActorValueIndex skill,
                                                            unsigned int count, ActorValueIndex resist, int flags)
{
    if (::FUN_004839c0(formID))
        return 0;

    EffectSetting* effect = new EffectSetting();
    effect->SetRefID(formID, true);
    effect->SetEditorID_AtRuntime(editorID);
    ((LowProcess*)effect)->SetPackageObjectType(count);
    effect->UpdateEffectName(fullName);
    reinterpret_cast<::FUN_004ee4b0_shell *>((effect))->FUN_004ee4b0(cost);
    reinterpret_cast<::FUN_00810570_shell *>((effect))->SetAssociatedActorValue(skill);
    ((MiddleHighProcess*)effect)->AddDeferredHideLimb((TargetDoorController*)(std::uintptr_t)item);
    reinterpret_cast<::MiddleHighProcess *>((((PlayerQuestData*)effect)))->SetFaceAnimationData((::TargetDoorController *)(::Date *)((Date*)(std::uintptr_t)resist));
    reinterpret_cast<::FUN_004078a0_shell *>((effect))->SetEffectID(flags);
    ::RegisterEffectSetting((int *)(effect));
    return effect;
}

// @fnv 0x00408F60
void EffectSettingCollection::InitializeEffectSettings()
{
    CreateEffectSetting(0x14A, "ScriptEffect", "Script Effect", -1, 0.0f, -1, 0x170, -1, 1);
    CreateEffectSetting(0x14B, "FireDamage", "Fire Damage", -1, 0.0f, 0x10, 0x20000475, 0x34, 0);
    CreateEffectSetting(0x14C, "FrostDamage", "Frost Damage", -1, 0.0f, 0x10, 0x20000475, -1, 0);
    CreateEffectSetting(0x14D, "ShockDamage", "Shock Damage", -1, 0.0f, 0x10, 0x20000475, -1, 0);
    CreateEffectSetting(0x14E, "RestoreHealth", "Restore Health", -1, 0.0f, 0x10, 0x70, -1, 0);
    DAT_011c33f4 = CreateEffectSetting(0x14F, "UMON", "Usage Monitor Effect", -1, 0.0f, -1, 0x12, -1, 1);
}

struct G2
{
    void AddHead(int**);
};
struct GlobalObject_00680890 : public G2
{
};
// @fnv 0x00409060
void RegisterEffectSetting(int* pEffect)
{
    if (pEffect)
        ::g_011c3400.AddHead(&pEffect);
}

struct FUN_00408b60
{
    void DestroyAllItems(void);
};

// @fnv 0x00408de0
void __cdecl FUN_00408de0()
{
    ((FUN_00408b60*)&::g_011c3400)->DestroyAllItems();
}

// Save-game header of the form being sized: formID, change type byte, then (packed) change flags.
struct ChangedForm
{
    unsigned int formID;
    unsigned char changeType;
};

struct EffectSettingFlags
{
};

struct TESSaveLoadGame
{
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};


// Computes the save size of the effect setting collection, adding 4/2 bytes for save-load state and 4 bytes per flagged EffectSetting, then logs the result.
// @fnv 0x00408c30
unsigned int FUN_00408c30()
{
    unsigned int size = 0;
    EffectSetting* mgef;
    unsigned short uiStart = (unsigned short)size;
    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        size += 4;
        size += 2;
    }
    size += 4;
    for (BSSimpleList<EffectSetting*>* node = (BSSimpleList<EffectSetting*>*)&::g_011c3400;
         node && (mgef = (node->m_item)) != 0; node = ((::BSSimpleList< ::EffectSetting *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        if (reinterpret_cast<::S3e60 *>((((EffectSettingFlags*)mgef)))->FUN_00403e60(0x200000))
            size += 4;
    }
    if (*::g_011de4e8.Bool())
    {
        ChangedForm* changed = ((::ChangedForm *)(reinterpret_cast<::EffectSetting *>((g_TESSaveLoadGame))->GetHitSound()));
        if (changed)
        {
            TESForm* form = FUN_004839c0(changed->formID);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return size;
}

#include "generated/data/fallout_shared/magic/effectsettingcollection.inc"
