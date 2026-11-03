// fallout_shared/tesammoeffect.cpp: TESAmmoEffect, AmmoEffectDesc (8 functions)

#include <new>
#include <cstring>
#include <malloc.h>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00474920_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00599d00.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011ca000.h"
enum ENUM_FORM_ID
{
    kAmmoEffectForm = 0x72
};

class TESFile;
class TESFullName;

class TESForm
{
  public:
    TESForm();
    virtual ~TESForm()
    {}
    virtual void UnknownForm()
    {}
    void SetInitializationState(bool);

  private:
    unsigned char baseData[20];
};

class TESAmmoEffectMap
{
  public:
    TESAmmoEffectMap();
    virtual ~TESAmmoEffectMap()
    {}
    virtual void UnknownMap()
    {}

  private:
    unsigned char mapData[8];
};

class TESAmmoEffect : public TESForm, public TESAmmoEffectMap
{
  public:
    TESAmmoEffect();
    virtual void UnknownForm()
    {}
    virtual void UnknownMap()
    {}
    virtual bool Load(TESFile*);
    unsigned char effectData[12];
};

class TESFile
{
  public:
    bool IsEndianConversionRequired();
    bool NextChunk();
};

class TESFullNameLoader
{
  public:
};

class ContainerItemExtraFileData
{
  public:
};


// Constructs a TESAmmoEffect: zeroes effectData and sets the form type to kAmmoEffectForm.
// @fnv 0x00599c40
TESAmmoEffect::TESAmmoEffect() : TESForm(), TESAmmoEffectMap()
{
    memset(effectData, 0, 12);
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(kAmmoEffectForm)));
}

class Actor;
class TESAmmo;
class NiTexture;
class BGSMusicType;

class TESObjectWEAP
{
  public:
};

class BSShaderNoLightingProperty
{
  public:
    NiTexture* GetBaseTexture();
};

class BGSAmmoForm
{
  public:
};

class TESRegionDataSound
{
  public:
};

class GetCurrentAmmoVTable
{
  public:
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void* GetMusicSource();
    virtual void* GetMusicSource2();
};


struct FUN_00599d70_shell : public TESAmmoEffect
{
    bool LoadAmmoEffect(TESFile*);
};

struct TESFormVtbl
{
    char pad0[0xE0];
    void(* readOBND)(TESForm*, TESFile*);
    char pad1[0x134 - 0xE4];
    void(* setEditorID)(TESForm*, char*);
};

// @fnv 0x00599d70
bool FUN_00599d70_shell::LoadAmmoEffect(TESFile* apFile)
{
    unsigned char formid = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((apFile))->FUN_00472660()));
    if (formid != 0x72)
        return false;

    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(apFile));
    SetInitializationState(false);

    int chunkid;
    while ((chunkid = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()))) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pMessage), 0x200);
            (*(TESFormVtbl**)this)->setEditorID(this, pMessage);
            break;
        }
        case 0x444e424f:
            (*(TESFormVtbl**)this)->readOBND(this, apFile);
            break;
        case 0x4c4c5546:
            ::ReadFullName((TESFullName*)((TESAmmoEffectMap*)this), apFile);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(apFile, effectData, 0xc);
            if (apFile->IsEndianConversionRequired())
                reinterpret_cast<::Class005a6b10 *>((((ContainerItemExtraFileData*)effectData)))->FUN_005a6b10();
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

struct FUN_00599cd0_StandIn
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00599d00, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x00599cd0
void* FUN_00599cd0_StandIn::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00599d00 *>(this)->FUN_00599d00::~FUN_00599d00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004855a0
{
};
struct S_00487010
{
};
struct FUN_00485680
{
};
struct FUN_00485e00_shell
{
};
struct FUN_00599ef0_shell
{
    void FUN_00599ef0();
};
// @fnv 0x00599ef0
void FUN_00599ef0_shell::FUN_00599ef0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)((char*)this + 0x18))))->FUN_00487010();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>((((ContainerItemExtraFileData*)((char*)this + 0x24))))->FUN_005a6b10();
    reinterpret_cast<::SDSaveForm *>((((FUN_00485e00_shell*)this)))->FUN_00485e20((const void *)((int)((char*)this + 0x24)), 0xc);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>((((ContainerItemExtraFileData*)((char*)this + 0x24))))->FUN_005a6b10();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e78f0_t
{
};
struct FUN_00599f60_t : TESAmmoEffect
{
    void CopyFromAmmoEffect(TESForm*);
};
// @fnv 0x00599f60
void FUN_00599f60_t::CopyFromAmmoEffect(TESForm* apCopy)
{
    TESAmmoEffect* pmisc = dynamic_cast<TESAmmoEffect*>(apCopy);
    if (pmisc == 0)
        return;
    __memcpy(effectData, pmisc->effectData, 12);
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
}

struct AmmoEffectValue
{
};
struct AmmoEffectList
{
    AmmoEffectValue* value;
    AmmoEffectList* next;
    AmmoEffectList();
    ~AmmoEffectList();
    void FUN_005ae3d0(AmmoEffectValue*&);
};
// @fnv 0x0059a030
float ComputeAmmoEffectValue(int iEffectType, AmmoEffectList* pEffectList, float fBaseValue)
{
    float fResult = fBaseValue;
    if (!pEffectList)
        return fResult;
    AmmoEffectList* sorted = new AmmoEffectList;
    while (pEffectList && ((::AmmoEffectValue *)((void *)(pEffectList))))
    {
        if (((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::AmmoEffectValue *)((void *)(pEffectList)))))->FUN_0045cd60())) == 1)
            sorted->FUN_005ae3d0(((::AmmoEffectValue *)((void *)(pEffectList))));
        else
            reinterpret_cast<::Callees *>((sorted))->FUN_00905820((void *)&(((::AmmoEffectValue *)((void *)(pEffectList)))));
        pEffectList = ((::AmmoEffectList *)(reinterpret_cast<::Callees *>((pEffectList))->FUN_00726070()));
    }
    while (sorted && ((::AmmoEffectValue *)((void *)(sorted))))
    {
        AmmoEffectValue* effect = ((::AmmoEffectValue *)((void *)(sorted)));
        sorted = ((::AmmoEffectList *)(reinterpret_cast<::Callees *>((sorted))->FUN_00726070()));
        int effectType = ((int)(reinterpret_cast<::ActorMover *>((effect))->GetCurrentMoveModeType()));
        int iOperation = ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((effect))->FUN_0045cd60()));
        float magnitude = reinterpret_cast<::FUN_00759450_shell *>((effect))->FUN_00759450();
        if (effectType != iEffectType)
            continue;
        switch (iOperation)
        {
        case 0:
            fResult += magnitude;
            break;
        case 1:
            fResult *= magnitude;
            break;
        case 2:
            fResult -= magnitude;
            break;
        }
    }
    delete sorted;
    return fResult;
}

struct FUN_00599fc0_shell : public TESAmmoEffect
{
    bool FUN_00599fc0(TESForm* pkForm);
};

// @fnv 0x00599fc0
bool FUN_00599fc0_shell::FUN_00599fc0(TESForm* pkForm)
{
    TESAmmoEffect* pkOther = dynamic_cast<TESAmmoEffect*>(pkForm);
    if (!pkOther)
        return true;
    if (memcmp(effectData, pkOther->effectData, sizeof(effectData)))
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pkOther))
        return true;
    return false;
}


class AmmoEffectSetting
{
  public:
};


class AmmoEffectDesc
{
  public:
    void FormatDescription(char* buffer, int bufferSize);
};

// Formats the ammo effect description into buffer using the effect name, operation symbol, and value.
// @fnv 0x0059a1e0
void AmmoEffectDesc::FormatDescription(char* buffer, int bufferSize)
{
    char nameText_2[64];
    char opText[2];

    opText[0] = 0;
    switch (((unsigned int)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())))
    {
    case 0:
        ::TaskQueueInterface::CopyStringToBuffer(opText, 2, "+");
        break;
    case 1:
        ::TaskQueueInterface::CopyStringToBuffer(opText, 2, "x");
        break;
    case 2:
        ::TaskQueueInterface::CopyStringToBuffer(opText, 2, "-");
        break;
    }
    switch (reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType())
    {
    case 0:
        ::TaskQueueInterface::CopyStringToBuffer(nameText_2, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::AmmoEffectSetting *>(&::g_011caa94))))->GetMenuTitle())));
        break;
    case 1:
        ::TaskQueueInterface::CopyStringToBuffer(nameText_2, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::AmmoEffectSetting *>(&::g_011caa84))))->GetMenuTitle())));
        break;
    case 2:
        ::TaskQueueInterface::CopyStringToBuffer(nameText_2, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::AmmoEffectSetting *>(&::g_011caaa0))))->GetMenuTitle())));
        break;
    case 3:
        ::TaskQueueInterface::CopyStringToBuffer(nameText_2, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::AmmoEffectSetting *>(&::g_011caa78))))->GetMenuTitle())));
        break;
    case 4:
        ::TaskQueueInterface::CopyStringToBuffer(nameText_2, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::AmmoEffectSetting *>(&::g_011caaac))))->GetMenuTitle())));
        break;
    case 5:
        ::TaskQueueInterface::CopyStringToBuffer(nameText_2, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::AmmoEffectSetting *>(&::g_011caab8))))->GetMenuTitle())));
        break;
    }
    ::FUN_00406d00(buffer, bufferSize, "%s %s %.2f", nameText_2, opText, (double)reinterpret_cast<::FUN_00759450_shell *>(this)->FUN_00759450());
}
