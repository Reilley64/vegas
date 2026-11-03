// fallout/ai/character.cpp: Character, Self, XObj, ActorBF and more (36 functions)

#include "fnv/form_fields.h"
#include <cstdint>
#include <new>
#include "fnv/decl/ActorData.h"
#include "fnv/decl/ActorLinkDetail__FUN_008d3380_shell.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0041c930_shell.h"
#include "fnv/decl/FUN_0042e060_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_00516bf0_shell.h"
#include "fnv/decl/FUN_0055f5b0_Class.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00672fc0_shell.h"
#include "fnv/decl/FUN_0067f140_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008808f0_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_00934250_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00950340_Class.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_009c8d60_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89b0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/P164Actor.h"
#include "fnv/decl/PackageEx.h"
#include "fnv/decl/PackageTargetRecord.h"
#include "fnv/decl/PlayerNearbyRefs.h"
#include "fnv/decl/Ref3.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SaveActor.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/StealWarningState.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESRace.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThisC1.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042e110__FUN_0042e110.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0057ace0__FUN_0057ace0_shell.h"
#include "fnv/decl/fnv_0057ad20__FUN_0057ad20_shell.h"
#include "fnv/decl/fnv_00671d30__FUN_00671d30_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00895110__PickActor.h"
#include "fnv/decl/fnv_0089f580__ActorStub.h"
#include "fnv/decl/fnv_008a9020__FUN_008d32b0_shell.h"
#include "fnv/decl/fnv_008a9380__ActorSave.h"
#include "fnv/decl/fnv_008a9940__FUN_008d3310_shell.h"
#include "fnv/decl/fnv_008aa210__ActorResetView.h"
#include "fnv/decl/fnv_008abc40__FUN_008abc40_shell.h"
#include "fnv/decl/fnv_008abfe0__FUN_008abfe0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00adbfd0__FUN_00adbfd0_cls.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/s5cc7a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_008a8000.h"
#include "fnv/symbols_008c1000.h"
#include "fnv/symbols_00935000.h"
#include "fnv/symbols_00936000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00ad8000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "character_decls.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00491180_shell.h"
#include "fnv/decl/FUN_00933150_shell.h"
#include "fnv/decl/FUN_009dcc80_cls.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeValueShell.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/UAMActor.h"
#include "fnv/decl/fnv_00567050__FUN_00567050_shell.h"
#include "fnv/decl/fnv_008b28c0__This8b.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011f6000.h"

// @fnv 0x008d1e70
bool Character_GetTrespassing(Character* self)
{
    return self->m_bTrespassing;
}

// @fnv 0x008d34b0
void Character::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_008abc40::FUN_008abc40_shell *>((reinterpret_cast<CharacterActorCalls*>(this)))->FUN_008abc40(buffer);
}

// @fnv 0x008d34d0
void Character::ApplyLoadBuffer(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_008abfe0::FUN_008abfe0_shell *>((reinterpret_cast<CharacterActorCalls*>(this)))->FUN_008abfe0((::fnv_008abfe0::BGSLoadFormBuffer *)(buffer));
}

// Returns a MagicTarget pointer at offset 0x94 of this object, or null if this is null.
// @fnv 0x0087d720
MagicTarget* Character::GetMagicTarget()
{
    return this ? static_cast<MagicTarget *>(this) : 0;
}

// @fnv 0x008d34f0
void Character::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::ThisC1 *>((reinterpret_cast<CharacterActorCalls*>(this)))->FUN_008ac1e0((::Arg *)(buffer));
    m_fFirstResetValue = -1.0f;
    m_fSecondValue = -1.0f;
    m_fThirdValue = -1.0f;
    m_bTrespassing = false;
    m_bActorGuard = false;
}

// @fnv 0x009698a0
void* Character::GetCurrentMusicMarker()
{
    if (*(void**)(reinterpret_cast<char*>(this) + 0x7dc) != 0 &&
        *(void**)((char*)*(void**)(reinterpret_cast<char*>(this) + 0x7dc) + 4) != 0)
    {
        return ((void *)(reinterpret_cast<::TESRace *>((reinterpret_cast<AudioMarkerDataCalls*>(
                   *(void**)((char*)*(void**)(reinterpret_cast<char*>(this) + 0x7dc) + 4))))->FUN_00969910()));
        goto return_zero;
    }

    MusicMarkerReference* marker = ((::MusicMarkerReference *)(reinterpret_cast<::PlayerNearbyRefs *>((reinterpret_cast<PlayerCharacter*>(this)))->FUN_00969930()));
    if (marker && *(void**)(reinterpret_cast<char*>(marker) + 4) != 0)
        return ((void *)(reinterpret_cast<::TESRace *>((reinterpret_cast<AudioMarkerDataCalls*>(*(void**)(reinterpret_cast<char*>(marker) + 4))))->FUN_00969910()));
return_zero:
    return 0;
}

// @fnv 0x008d33f0
void Character::LoadGame(BGSLoadFormBuffer* buffer)
{
    struct OldData
    {
        int word;
        char pad1;
        char pad2;
        char pad3;
        char byte;
    } oldData;
    struct NewData
    {
        int word2;
        int word1;
        char pad1;
        char pad2;
        char pad3;
        char byte;
    } newData;

    reinterpret_cast<::P164Actor *>((reinterpret_cast<CharacterActorCalls*>(this)))->FUN_008ab3a0((::P164Buffer *)(buffer));
    if (buffer->GetVersion() < 9)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&oldData.byte), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&oldData.word), 4);
    }
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bTrespassing), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bActorGuard), 1);
    if (buffer->GetVersion() < 9)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&newData.byte), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&newData.word1), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&newData.word2), 4);
    }
}

// @fnv 0x008d1e90
void FUN_008d1e90(Character* this_ptr, float value)
{
    this_ptr->m_fThirdValue = value;
}

struct FUN_008d34b0_shell : public Character
{
    void FUN_008d34b0(BGSLoadFormBuffer*);
};

// @fnv 0x008d34b0
void FUN_008d34b0_shell::FUN_008d34b0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_008abc40::FUN_008abc40_shell *>((((CharacterActorCalls*)this)))->FUN_008abc40(apLoadGameBuffer);
}

struct FUN_008d34d0_shell : public Character
{
    void FUN_008d34d0(BGSLoadFormBuffer*);
};

// @fnv 0x008d34d0
void FUN_008d34d0_shell::FUN_008d34d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_008abfe0::FUN_008abfe0_shell *>((((CharacterActorCalls*)this)))->FUN_008abfe0((::fnv_008abfe0::BGSLoadFormBuffer *)(apLoadGameBuffer));
}

struct FUN_008d34f0_shell : public Character
{
    void RevertAndResetFields(BGSLoadFormBuffer*);
};

// Calls Revert on the character, then sets three floats at offsets 0x1b8/0x1bc/0x1c4 to -1.0 and clears bytes at 0x1c0/0x1c1.
// @fnv 0x008d34f0
void FUN_008d34f0_shell::RevertAndResetFields(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::ThisC1 *>((((CharacterActorCalls*)this)))->FUN_008ac1e0((::Arg *)(apLoadGameBuffer));
    (&this->m_fFirstResetValue)[0] = -1.0f;
    (&this->m_fSecondValue)[0] = -1.0f;
    (&this->m_fThirdValue)[0] = -1.0f;
    ((unsigned char*)&this->m_bTrespassing)[0] = 0;
    ((unsigned char*)&this->m_bActorGuard)[0] = 0;
}

struct FUN_009dcc80_target
{
    NiPoint3 GetVec(float);
};
struct FUN_008b3b30_shell
{
    NiPoint3 FUN_008b3b30(float f);
};
// Returns the stored point when f is not above _gModifierZero, otherwise delegates to the object at offset 0x190 with f.
// @fnv 0x008b3b30
NiPoint3 FUN_008b3b30_shell::FUN_008b3b30(float f)
{
    if (f <= ::_DAT_01012060)
    {
        return *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
    }
    return (*(FUN_009dcc80_target**)((char*)this + 0x190))->GetVec(f);
}

struct FUN_008d1e70_t
{
    unsigned char GetByteAtOffset1C0();
};
// @fnv 0x008d1e70
unsigned char FUN_008d1e70_t::GetByteAtOffset1C0()
{
    return *((unsigned char*)this + 0x1c0);
}

struct FUN_008d1f10_shell : public Character
{
    void FUN_008d2060();
    FUN_008d1f10_shell* FUN_008d1f10(unsigned int aiFlags);
};
struct FUN_008d24a0_shell : public Character
{
    int FUN_008d24a0();
};
// Calls FUN_00646310 on the object at offset 0xa4 to fill fx and fy, then returns fx as an int.
// @fnv 0x008d24a0
int FUN_008d24a0_shell::FUN_008d24a0()
{
    float fx = 0.0f;
    float fy = 0.0f;
    ::FUN_00646310(this ? (char*)static_cast<ActorValueOwner *>(this) : 0, 0, &fx, &fy);
    return (int)fx;
}

struct FUN_008d32b0_shell : public Character
{
    unsigned short FUN_008d32b0(unsigned int aiFlags);
};
// @fnv 0x008d32b0
unsigned short FUN_008d32b0_shell::FUN_008d32b0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::fnv_008a9020::FUN_008d32b0_shell *>(this)->FUN_008a9020(aiFlags);
    return isize;
}

struct FUN_008a9380_target
{
};
struct FUN_008d32f0_shell
{
    void FUN_008d32f0(unsigned int aiFlags);
};
// @fnv 0x008d32f0
void FUN_008d32f0_shell::FUN_008d32f0(unsigned int aiFlags)
{
    reinterpret_cast<::fnv_008a9380::ActorSave *>((((FUN_008a9380_target*)this)))->SaveActorData(aiFlags);
}

struct FUN_008d3310_shell : public Character
{
    void FUN_008d3310(unsigned int aiFlags, unsigned int aiCurrentFlags);
};
// @fnv 0x008d3310
void FUN_008d3310_shell::FUN_008d3310(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<::fnv_008a9940::FUN_008d3310_shell *>(this)->FUN_008a9940(aiFlags, aiCurrentFlags);
}

struct TESSaveLoadGame
{
};
struct FUN_008d3330_shell : public Character
{
    void FUN_008d3330(unsigned int aiFlags);
};
// Calls FUN_008aa210 with aiFlags, then if g_TESSaveLoadGame->FUN_0055f5b0() succeeds, sets two floats to -1.0f.
// @fnv 0x008d3330
void FUN_008d3330_shell::FUN_008d3330(unsigned int aiFlags)
{
    reinterpret_cast<::fnv_008aa210::ActorResetView *>(this)->FUN_008aa210(aiFlags);
    if (reinterpret_cast<::FUN_0055f5b0_Class *>((g_TESSaveLoadGame))->FUN_0055f5b0())
    {
        m_fFirstResetValue = -1.0f;
        m_fSecondValue = -1.0f;
    }
}

struct FUN_008d3380_shell : public Character
{
    void FUN_008d3380(uintptr_t, uintptr_t);
};
// @fnv 0x008d3380
void FUN_008d3380_shell::FUN_008d3380(uintptr_t a, uintptr_t b)
{
    reinterpret_cast<::ActorLinkDetail::FUN_008d3380_shell *>(this)->FUN_008aa4c0(a, b);
}

struct BGSSaveFormBuffer
{
};
struct FUN_008d33a0_shell : public Character
{
    void SaveFormData(BGSSaveFormBuffer*);
};
// Calls FUN_008aaf40, then saves the two bytes at offsets 0x1c0 and 0x1c1 of this into the save buffer.
// @fnv 0x008d33a0
void FUN_008d33a0_shell::SaveFormData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::SaveActor *>(this)->FUN_008aaf40((::SaveBuffer *)(apSaveGameBuffer));
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((char*)&this->m_bTrespassing, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((char*)&this->m_bActorGuard, 1, 0);
}

struct FUN_009396f0_shell
{
    void SetFieldD64(int value);
};
// @fnv 0x009396f0
void FUN_009396f0_shell::SetFieldD64(int value)
{
    *(int*)((char*)this + 0xd64) = value;
}

struct FUN_00950ad0_shell : public PlayerCharacter
{
    BipedAnim* FUN_00950ad0();
};
// Returns the BipedAnim for the player, choosing the variant based on the result of FUN_00524d10(this).
// @fnv 0x00950ad0
BipedAnim* FUN_00950ad0_shell::FUN_00950ad0()
{
    return ((::BipedAnim *)(reinterpret_cast<::PlayerCharacter *>(this)->FUN_00950b00(!FUN_00524d10((bool*)this))));
}

struct MediaLocation;
struct MediaLocationController;
struct MusicMarkerReference
{
    TESObjectREFR* m_pMarkerReference;
    MediaLocation* m_pAudioMarkerData;
};
struct FUN_009698a0_shell : public PlayerCharacter
{
    MediaLocationController* GetMediaLocationController();
};

// @fnv 0x009698a0
MediaLocationController* FUN_009698a0_shell::GetMediaLocationController()
{
    if (*(MusicMarkerReference**)((char*)this + 0x7dc) && *(AudioMarkerDataCalls**)(*(char**)((char*)this + 0x7dc) + 4))
    {
        return (MediaLocationController*)((void *)(reinterpret_cast<::TESRace *>(((*(AudioMarkerDataCalls**)(*(char**)((char*)this + 0x7dc) + 4))))->FUN_00969910()));
    }
    else
    {
        MusicMarkerReference* pMarkerInfo = ((::MusicMarkerReference *)(reinterpret_cast<::PlayerNearbyRefs *>(this)->FUN_00969930()));
        if (pMarkerInfo && *(AudioMarkerDataCalls**)&pMarkerInfo->m_pAudioMarkerData)
        {
            return (MediaLocationController*)((void *)(reinterpret_cast<::TESRace *>(((*(AudioMarkerDataCalls**)&pMarkerInfo->m_pAudioMarkerData)))->FUN_00969910()));
        }
    }
    return 0;
}

struct BGSTalkingActivator
{
};

struct TESObject
{
};

struct ExtraDataList_Accessor
{
};

struct Slot12cHolder
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void Method12c(TESObjectREFR*);
};

struct FUN_008b1910_shell
{
    TESObjectREFR* FUN_008b1910(TESObjectREFR* apRefr, TESObjectREFR*& apOutRefr);
};

// @fnv 0x008b1910
TESObjectREFR* FUN_008b1910_shell::FUN_008b1910(TESObjectREFR* apRefr, TESObjectREFR*& apOutRefr)
{
    BGSTalkingActivator* m_pLinkedReference = ((::BGSTalkingActivator *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject*)apRefr)))->FUN_007af430()));
    reinterpret_cast<::FUN_0042e060_class *>((((ExtraDataList_Accessor*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((apRefr))->FUN_005d43c0())))))->FUN_0042e060((uintptr_t)(m_pLinkedReference), (uintptr_t)(apRefr));
    apRefr->MarkAsModified(0x80000000);
    void* extra9 = ((void *)(reinterpret_cast<::fnv_0042e110::FUN_0042e110 *>((((ExtraDataList_Accessor*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((apRefr))->FUN_005d43c0())))))->GetExtraData()));
    if (extra9)
    {
        apRefr = *(TESObjectREFR**)((char*)extra9 + 0xc);
        apOutRefr = *(TESObjectREFR**)((char*)extra9 + 0xc);
        if (((::TESObjectREFR *)(reinterpret_cast<::FUN_00516bf0_shell *>((void *)(m_pLinkedReference))->FUN_00516bf0())))
        {
            apRefr = ((::TESObjectREFR *)(reinterpret_cast<::FUN_00516bf0_shell *>((void *)(m_pLinkedReference))->FUN_00516bf0()));
        }
    }
    (*(Slot12cHolder**)((char*)this + 0x68))->Method12c(apRefr);
    return apRefr;
}

struct TopicH
{
};

struct bhkCharacterController
{
};
struct MobileObject_Standin
{
};

struct HolderFUN
{
    void FUN_0066ca00(void*);
};

struct Point3 : public NiPoint3
{
    Point3 operator*(float) const;
    Point3& operator+=(const Point3&);
};

struct FUN_00968690_shell : public Character
{
    NiPoint3 FUN_00968690(float f);
};

// @fnv 0x00968690
NiPoint3 FUN_00968690_shell::FUN_00968690(float f)
{
    Point3 kPos = *(Point3*)((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((((TopicH*)this)))->GetAddTopicList()));
    Point3 kMotionVelocity;
    if (f > 0.0 && ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((((MobileObject_Standin*)this)))->FUN_009306d0())))
    {
        reinterpret_cast<::HolderFUN *>((((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((((MobileObject_Standin*)this)))->FUN_009306d0()))))->FUN_0066ca00(&kMotionVelocity);
        reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Point3 &)(kPos))->FUN_0063c8a0((void *)&(const ::Point3 &)(kMotionVelocity * f));
    }
    return kPos;
}

struct SoundPlaybackHandle
{
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
public:
    void SetCompletionCallback(void (*)(void *, bool), void *);
};

struct FUN_0087d4a0
{
    FUN_0087d4a0(bool value);
    ~FUN_0087d4a0();
};

struct FUN_008d1f40_t : public FUN_0087d4a0
{
    FUN_008d1f40_t(bool abadd);
};

struct CharacterCallStandin
{
};

extern int DAT_0108695c;
extern int DAT_010869a4;
extern int DAT_010869d4;
extern int DAT_01086a0c;
extern int DAT_01086a60;
extern int DAT_01086a6c;

// @fnv 0x008d1f40
FUN_008d1f40_t::FUN_008d1f40_t(bool abadd) : FUN_0087d4a0(abadd)
{
    *reinterpret_cast<intptr_t*>(this) = reinterpret_cast<intptr_t>(&DAT_01086a6c);
    *reinterpret_cast<intptr_t*>(reinterpret_cast<char*>(this) + 0x18) = reinterpret_cast<intptr_t>(&DAT_01086a60);
    *reinterpret_cast<intptr_t*>(reinterpret_cast<char*>(this) + 0x88) = reinterpret_cast<intptr_t>(&DAT_01086a0c);
    *reinterpret_cast<intptr_t*>(reinterpret_cast<char*>(this) + 0x94) = reinterpret_cast<intptr_t>(&DAT_010869d4);
    *reinterpret_cast<intptr_t*>(reinterpret_cast<char*>(this) + 0xA4) = reinterpret_cast<intptr_t>(&DAT_010869a4);
    *reinterpret_cast<intptr_t*>(reinterpret_cast<char*>(this) + 0xA8) = reinterpret_cast<intptr_t>(&DAT_0108695c);

    reinterpret_cast<::FUN_004f15a0_shell *>((reinterpret_cast<SoundPlaybackHandle*>(this)))->FUN_004f15a0(0x3B);

    *reinterpret_cast<BipedAnim**>(reinterpret_cast<char*>(this) + 0x1B4) = 0;

    reinterpret_cast<::Character *>((reinterpret_cast<CharacterCallStandin*>(this)))->FUN_008d4e80();

    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1C1) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1C4) = -1.0f;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1C0) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x134) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x138) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x13C) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x140) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x144) = 0;
}

struct FUN_00573150_shell
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void v72()
    {}
    virtual void v73()
    {}
    virtual void v74()
    {}
    virtual void v75()
    {}
    virtual void v76()
    {}
    virtual void v77()
    {}
    virtual void v78()
    {}
    virtual void v79()
    {}
    virtual void v80()
    {}
    virtual void v81()
    {}
    virtual void v82()
    {}
    virtual void v83()
    {}
    virtual void v84()
    {}
    virtual void v85()
    {}
    virtual void v86()
    {}
    virtual void v87()
    {}
    virtual void v88()
    {}
    virtual void v89()
    {}
    virtual void v90()
    {}
    virtual void v91()
    {}
    virtual void v92()
    {}
    virtual void v93()
    {}
    virtual void v94()
    {}
    virtual void v95()
    {}
    virtual void v96()
    {}
    virtual void v97()
    {}
    virtual void v98()
    {}
    virtual void v99()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114()
    {}
    virtual void v115()
    {}
    virtual void v116()
    {}
    virtual void v117()
    {}
    virtual void v118()
    {}
    virtual void v119()
    {}
    virtual void v120()
    {}
    virtual void v121()
    {}
    virtual void v122()
    {}

    void CallLastVirtualMethod();
};

// @fnv 0x00573150
void FUN_00573150_shell::CallLastVirtualMethod()
{
    v122();
}

struct Str
{
    void* a;
    int b;
    int c;
    Str();
    Str(const Str&);
    ~Str();
    Str& operator=(const Str&);
    Str& Fn7480();
};
struct Named
{
};
struct Obj
{
    unsigned int GetID();
    Named* GetName();
};
struct Obj2
{
};
struct Sub
{
};
struct Proc
{
    ~Proc();
};
struct Arg
{
};
struct Mgr
{
    void Add(const char*, void (*)(), unsigned int);
};
struct Audio
{
    Str GetHandle(const char*, int, int);
};
struct Setting
{
};
struct BoolSetting
{
    bool* Get();
};

void __cdecl Spawn(const char*, Str, NiPoint3, int, int);
struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void Play(int, Str);
};
struct Self
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* Get1d0();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual NiPoint3* GetPos();
    char pad04[0x64];
    Inner* inner;
    char pad6c[0x13];
    bool flag7f;
    bool flag80;
    unsigned int GetID();
    Str MakeStr(Obj*, int, int, int);
    Str PlaySoundOnObject(Arg* arg, intptr_t p2, bool p3, bool p4, int p5, bool p6);
};

// Creates a Proc from arg, registers a callback or builds an audio handle from the sub-object's name, plays it, and optionally spawns it.
// @fnv 0x008a1bd0
Str Self::PlaySoundOnObject(Arg* arg, intptr_t p2, bool p3, bool abSkipSpawn, int aiUnused, bool abWithCallback)
{
    Str result;
    Proc* proc = ((::Proc *)(reinterpret_cast<::FUN_0061b320_shell *>((arg))->FUN_0061b320((::TESObjectREFR *)(void *)(this), (::TESObjectREFR *)(p2), (::TESTopic *)(0), (void *)(0), 0)));
    float fResult = 0.0f;
    reinterpret_cast<::FUN_00934250_shell *>(this)->FUN_00934250();
    reinterpret_cast<::fnv_0057ad20::FUN_0057ad20_shell *>(this)->FUN_0057ad20((::fnv_0057ad20::TESTopic *)(arg));
    if (proc)
    {
        Obj* sub = ((::Obj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((proc))->FUN_0084e3a0()));
        reinterpret_cast<::fnv_0057ace0::FUN_0057ace0_shell *>(this)->FUN_0057ace0((::fnv_0057ace0::TESTopicInfo *)(sub));
        if (sub)
        {
            reinterpret_cast<::TESTopicInfo *>((sub))->AddTopicList();
            reinterpret_cast<::FUN_0061f170_cls *>((sub))->FUN_0061f170((void *)(0), (::ArgObj *)(void *)(this));
        }
        reinterpret_cast<::DialogueItem *>((proc))->SelectDefaultResponseList();
        Sub* obj = ((::Sub *)(reinterpret_cast<::DialogueItem *>((proc))->GetActiveResponse()));
        if (obj)
        {
            bool bPending = true;
            if (((::Obj2 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((obj))->FUN_007af430())) && flag7f)
            {
                Obj* tmp = ((::Obj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::Obj2 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((obj))->FUN_007af430()))))->FUN_0084e3a0()));
                Str target = MakeStr(tmp, 0, 0x40000102, 1);
                Mgr* mgr = ((::Mgr *)(::FUN_00ad9060()));
                reinterpret_cast<::fnv_00adbfd0::FUN_00adbfd0_cls *>((mgr))->FUN_00adbfd0((intptr_t)(((const char *)(::FUN_00559450((int *)&(target))))), (intptr_t)(((void (&)())::fnv_00935cc0::FUN_00935cc0)), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())));
                flag7f = false;
                bPending = false;
            }
            if (bPending && flag7f)
            {
                if (((const char *)(::FUN_00559450((int *)(((::Named *)(::FUN_00460140((intptr_t)(obj)))))))))
                {
                    char buf[0x200];
                    ::TaskQueueInterface::CopyStringToBuffer(buf, 0x200, ((const char *)(::FUN_00559450((int *)(((::Named *)(::FUN_00460140((intptr_t)(obj)))))))));
                    if (p3)
                    {
                        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Str &)(result))->operator=((const ::SoundPlaybackHandle &)((const ::Str &)(((::Audio *)(::FUN_00453a70()))->GetHandle(buf, 0x105, 0))));
                    }
                    else
                    {
                        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Str &)(result))->operator=((const ::SoundPlaybackHandle &)((const ::Str &)(((::Audio *)(::FUN_00453a70()))->GetHandle(buf, 0x106, 0))));
                    }
                    if (!p3)
                    {
                        NiPoint3 pos = *GetPos();
                        reinterpret_cast<::FUN_00ad8b60_h *>(&(result))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                        reinterpret_cast<::FUN_00ad8f20_shell *>(&(result))->FUN_00ad8f20((::NiAVObject *)(void *)(Get1d0()));
                    }
                    else
                    {
                        reinterpret_cast<::FUN_00ad89b0_shell *>(&(result))->SetStaticAttenuation((int)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::g_011e060c)))))) * ::g_d100));
                    }
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(result))->FUN_00ad8830(0);
                    if (abWithCallback)
                    {
                        reinterpret_cast<::SoundPlaybackHandle *>(&(result))->SetCompletionCallback((void (*)(void *, bool))(((void (&)(unsigned int, int))::HandleMobileObjectResult)), (void *)(std::uintptr_t)(reinterpret_cast<::FormFields *>(this)->iFormID));
                    }
                    flag80 = false;
                    inner->Play(0, result);
                    fResult = (float)::FUN_00ad8b30((unsigned int *)&(result));
                }
                else if (sub && abWithCallback)
                {
                    ::HandleMobileObjectResult((void *)(std::uintptr_t)(reinterpret_cast<::FormFields *>(this)->iFormID), 1);
                }
            }
            if (*(*reinterpret_cast<::BoolSetting *>(&::g_011d8928)).Get() || ::FUN_008c1bc0((intptr_t)this))
            {
                if (!abSkipSpawn)
                {
                    Spawn(((const char *)(::FUN_00559450((int *)(((::Named *)(((::Vec3 *)(void *)(obj)))))))), result, *GetPos(), p2, 1);
                }
            }
        }
        if (proc)
            delete proc;
    }
    return result;
}

struct FUN_008ac850_object
{
};

struct FUN_008ac850_owner
{
    virtual void* f0000();
    virtual void* f0001();
    virtual void* f0002();
    virtual void* f0003();
    virtual void* f0004();
    virtual void* f0005();
    virtual void* f0006();
    virtual void* f0007();
    virtual void* f0008();
    virtual void* f0009();
    virtual void* f0010();
    virtual void* f0011();
    virtual void* f0012();
    virtual void* f0013();
    virtual void* f0014();
    virtual void* f0015();
    virtual void* f0016();
    virtual void* f0017();
    virtual void* f0018();
    virtual void* f0019();
    virtual void* f0020();
    virtual void* f0021();
    virtual void* f0022();
    virtual void* f0023();
    virtual void* f0024();
    virtual void* f0025();
    virtual void* f0026();
    virtual void* f0027();
    virtual void* f0028();
    virtual void* f0029();
    virtual void* f0030();
    virtual void* f0031();
    virtual void* f0032();
    virtual void* f0033();
    virtual void* f0034();
    virtual void* f0035();
    virtual void* f0036();
    virtual void* f0037();
    virtual void* f0038();
    virtual void* f0039();
    virtual void* f0040();
    virtual void* f0041();
    virtual void* f0042();
    virtual void* f0043();
    virtual void* f0044();
    virtual void* f0045();
    virtual void* f0046();
    virtual void* f0047();
    virtual void* f0048();
    virtual void* f0049();
    virtual void* f0050();
    virtual void* f0051();
    virtual void* f0052();
    virtual void* f0053();
    virtual void* f0054();
    virtual void* f0055();
    virtual void* f0056();
    virtual void* f0057();
    virtual void* f0058();
    virtual void* f0059();
    virtual void* f0060();
    virtual void* f0061();
    virtual void* f0062();
    virtual void* f0063();
    virtual void* f0064();
    virtual void* f0065();
    virtual void* f0066();
    virtual void* f0067();
    virtual void* f0068();
    virtual void* f0069();
    virtual void* f0070();
    virtual void* f0071();
    virtual void* f0072();
    virtual void* f0073();
    virtual void* f0074();
    virtual void* f0075();
    virtual void* f0076();
    virtual void* f0077();
    virtual void* f0078();
    virtual void* f0079();
    virtual void* f0080();
    virtual void* f0081();
    virtual void* f0082();
    virtual void* f0083();
    virtual void* f0084();
    virtual void* f0085();
    virtual void* f0086();
    virtual void* f0087();
    virtual void* f0088();
    virtual void* f0089();
    virtual void* f0090();
    virtual void* f0091();
    virtual void* f0092();
    virtual void* f0093();
    virtual void* f0094();
    virtual void* f0095();
    virtual void* f0096();
    virtual void* f0097();
    virtual void* f0098();
    virtual void* f0099();
    virtual void* f0100();
    virtual void* f0101();
    virtual void* f0102();
    virtual void* f0103();
    virtual void* f0104();
    virtual void* f0105();
    virtual void* f0106();
    virtual void* f0107();
    virtual void* f0108();
    virtual void* f0109();
    virtual void* f0110();
    virtual void* f0111();
    virtual void* f0112();
    virtual void* f0113();
    virtual void* f0114();
    virtual void* f0115();
    virtual void* f0116();
    virtual void* f0117();
    virtual void* f0118();
    virtual void* f0119();
    virtual void* f0120();
    virtual void* f0121();
    virtual void* f0122();
    virtual void* f0123();
    virtual void* f0124();
    virtual void* f0125();
    virtual void* f0126();
    virtual void* f0127();
    virtual void* f0128();
    virtual void* f0129();
    virtual void* f0130();
    virtual void* f0131();
    virtual void* f0132();
    virtual void* f0133();
    virtual void* f0134();
    virtual void* f0135();
    virtual void* f0136();
    virtual void* f0137();
    virtual void* f0138();
    virtual void* f0139();
    virtual void* f0140();
    virtual void* f0141();
    virtual void* f0142();
    virtual void* f0143();
    virtual void* f0144();
    virtual void* f0145();
    virtual void* f0146();
    virtual void* f0147();
    virtual void* f0148();
    virtual void* f0149();
    virtual void* f0150();
    virtual void* f0151();
    virtual void* f0152();
    virtual void* f0153();
    virtual void* f0154();
    virtual void* f0155();
    virtual void* f0156();
    virtual void* f0157();
    virtual void* f0158();
    virtual void* f0159();
    virtual void* f0160();
    virtual void* f0161();
    virtual void* f0162();
    virtual void* f0163();
    virtual void* f0164();
    virtual void* f0165();
    virtual void* f0166();
    virtual void* f0167();
    virtual void* f0168();
    virtual void* f0169();
    virtual void* f0170();
    virtual void* f0171();
    virtual void* f0172();
    virtual void* f0173();
    virtual void* f0174();
    virtual void* f0175();
    virtual void* f0176();
    virtual void* f0177();
    virtual void* f0178();
    virtual void* f0179();
    virtual void* f0180();
    virtual void* f0181();
    virtual void* f0182();
    virtual void* f0183();
    virtual void* f0184();
    virtual void* f0185();
    virtual void* f0186();
    virtual void* f0187();
    virtual void* f0188();
    virtual void* f0189();
    virtual void* f0190();
    virtual void* f0191();
    virtual void* f0192();
    virtual void* f0193();
    virtual void* f0194();
    virtual void* f0195();
    virtual void* f0196();
    virtual void* f0197();
    virtual void* f0198();
    virtual void* f0199();
    virtual void* f0200();
    virtual void* f0201();
    virtual void* f0202();
    virtual void* f0203();
    virtual void* f0204();
    virtual void* f0205();
    virtual void* f0206();
    virtual void* f0207();
    virtual void* f0208();
    virtual void* f0209();
    virtual void* f0210();
    virtual void* f0211();
    virtual void* f0212();
    virtual void* f0213();
    virtual void* f0214();
    virtual void* f0215();
    virtual void* f0216();
    virtual void* f0217();
    virtual void* f0218();
    virtual void* f0219();
    virtual void* f0220();
    virtual void* f0221();
    virtual void* f0222();
    virtual void* f0223();
    virtual void* f0224();
    virtual void* f0225();
    virtual void* f0226();
    virtual void* f0227();
    virtual void* f0228();
    virtual void* f0229();
    virtual void* f0230();
    virtual void* f0231();
    virtual void* f0232();
    virtual void* f0233();
    virtual void* f0234();
    virtual void* f0235();
    virtual void* f0236();
    virtual void* f0237();
    virtual void* f0238();
    virtual void* f0239();
    virtual void* f0240();
    virtual void* f0241();
    virtual void* f0242();
    virtual void* f0243();
    virtual void* f0244();
    virtual void* f0245();
    virtual void* f0246();
    virtual void* f0247();
    virtual void* f0248();
    virtual void* f0249();
    virtual void* f0250();
    virtual void* f0251();
    virtual void* f0252();
    virtual void* f0253();
    virtual void* f0254();
    virtual void* f0255();
    virtual void* f0256();
    virtual void* f0257();
    virtual void* f0258();
    virtual void* f0259();
    virtual void* f0260();
    virtual void* f0261();
    virtual void* f0262();
    virtual void* f0263();
    virtual void* f0264();
    virtual void* f0265();
    virtual FUN_008ac850_object* f0266();

    void FUN_008ac850(void* value);
};

// Retrieves the object via f0266 and, if non-null, forwards value to its SetWaterForm method.
// @fnv 0x008ac850
void FUN_008ac850_owner::FUN_008ac850(void* value)
{
    FUN_008ac850_object* object = f0266();
    if (object != 0)
        reinterpret_cast<::FUN_008ac890_shell *>((object))->SetWaterForm((::TESWaterForm *)(value));
}

// Pool of 1000 entry pointers (all null) plus three 4-slot tables, all cleared on construction.

struct PoolEntry;

class PoolEntryArray
{
  public:
    void* m_pVtbl;
    PoolEntry** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    PoolEntryArray(unsigned int uiMaxSize, unsigned int uiGrowBy);
    ~PoolEntryArray();
};

class FUN_0096a850 : public PoolEntryArray
{
  public:
    void* m_apActive[4];
    void* m_apPending[4];
    void* m_apFree[4];

    FUN_0096a850();
};

// Constructs a PoolEntryArray with size 1000, nulls all 1000 entries, and clears the four active, pending and free slots.
// @fnv 0x0096a850
FUN_0096a850::FUN_0096a850() : PoolEntryArray(0, 1)
{
    reinterpret_cast<::ViewerStrings *>(this)->SetSize(1000);
    for (unsigned int i = 0; i < 1000; i++)
    {
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(i, (char *&)((const ::PoolEntry *const &)(0)));
    }
    for (int j = 0; j < 4; j++)
    {
        m_apActive[j] = 0;
        m_apPending[j] = 0;
        m_apFree[j] = 0;
    }
}

struct ActorAVVtbl
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a00a();
    virtual void a00b();
    virtual void a00c();
    virtual void a00d();
    virtual void a00e();
    virtual void a00f();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a01a();
    virtual void a01b();
    virtual void a01c();
    virtual void a01d();
    virtual void a01e();
    virtual void a01f();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a02a();
    virtual void a02b();
    virtual void a02c();
    virtual void a02d();
    virtual void a02e();
    virtual void a02f();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a03a();
    virtual void a03b();
    virtual void a03c();
    virtual void a03d();
    virtual void a03e();
    virtual void a03f();
    virtual void a040();
    virtual void a041();
    virtual void a042();
    virtual void a043();
    virtual void a044();
    virtual void a045();
    virtual void a046();
    virtual void a047();
    virtual void a048();
    virtual void a049();
    virtual void a04a();
    virtual void a04b();
    virtual void a04c();
    virtual void a04d();
    virtual void a04e();
    virtual void a04f();
    virtual void a050();
    virtual void a051();
    virtual void a052();
    virtual void a053();
    virtual void a054();
    virtual void a055();
    virtual void a056();
    virtual void a057();
    virtual void a058();
    virtual void a059();
    virtual void a05a();
    virtual void a05b();
    virtual void a05c();
    virtual void a05d();
    virtual void a05e();
    virtual void a05f();
    virtual void a060();
    virtual void a061();
    virtual void a062();
    virtual void a063();
    virtual void a064();
    virtual void a065();
    virtual void a066();
    virtual void a067();
    virtual void a068();
    virtual void a069();
    virtual void a06a();
    virtual void a06b();
    virtual void a06c();
    virtual void a06d();
    virtual void a06e();
    virtual void a06f();
    virtual void a070();
    virtual void a071();
    virtual void a072();
    virtual void a073();
    virtual void a074();
    virtual void a075();
    virtual void a076();
    virtual void a077();
    virtual void a078();
    virtual void a079();
    virtual void a07a();
    virtual void a07b();
    virtual void a07c();
    virtual void a07d();
    virtual void a07e();
    virtual void a07f();
    virtual void a080();
    virtual void a081();
    virtual void a082();
    virtual void a083();
    virtual void a084();
    virtual void a085();
    virtual void a086();
    virtual void a087();
    virtual void a088();
    virtual void a089();
    virtual void a08a();
    virtual void a08b();
    virtual void a08c();
    virtual void a08d();
    virtual void a08e();
    virtual void a08f();
    virtual void a090();
    virtual void a091();
    virtual void a092();
    virtual void a093();
    virtual void a094();
    virtual void a095();
    virtual void a096();
    virtual void a097();
    virtual void a098();
    virtual void a099();
    virtual void a09a();
    virtual void a09b();
    virtual void a09c();
    virtual void a09d();
    virtual void a09e();
    virtual void a09f();
    virtual void a0a0();
    virtual void a0a1();
    virtual void a0a2();
    virtual void a0a3();
    virtual void a0a4();
    virtual void a0a5();
    virtual void a0a6();
    virtual void a0a7();
    virtual void a0a8();
    virtual void a0a9();
    virtual void a0aa();
    virtual void a0ab();
    virtual void a0ac();
    virtual void a0ad();
    virtual void a0ae();
    virtual void a0af();
    virtual void a0b0();
    virtual void a0b1();
    virtual void a0b2();
    virtual void a0b3();
    virtual void a0b4();
    virtual void a0b5();
    virtual void a0b6();
    virtual void a0b7();
    virtual void a0b8();
    virtual void a0b9();
    virtual void a0ba();
    virtual void a0bb();
    virtual void a0bc();
    virtual void a0bd();
    virtual void a0be();
    virtual void a0bf();
    virtual void a0c0();
    virtual void a0c1();
    virtual void a0c2();
    virtual void a0c3();
    virtual void a0c4();
    virtual void a0c5();
    virtual void a0c6();
    virtual void a0c7();
    virtual void a0c8();
    virtual void a0c9();
    virtual void a0ca();
    virtual void a0cb();
    virtual void a0cc();
    virtual void a0cd();
    virtual void a0ce();
    virtual void a0cf();
    virtual void a0d0();
    virtual void a0d1();
    virtual void a0d2();
    virtual void a0d3();
    virtual void a0d4();
    virtual void a0d5();
    virtual void a0d6();
    virtual void a0d7();
    virtual void a0d8();
    virtual void a0d9();
    virtual void a0da();
    virtual void a0db();
    virtual void a0dc();
    virtual void a0dd();
    virtual void a0de();
    virtual void a0df();
    virtual void a0e0();
    virtual void a0e1();
    virtual void a0e2();
    virtual void a0e3();
    virtual void a0e4();
    virtual void a0e5();
    virtual void a0e6();
    virtual void a0e7();
    virtual void a0e8();
    virtual void a0e9();
    virtual void a0ea();
    virtual void a0eb();
    virtual void a0ec();
    virtual void a0ed();
    virtual void a0ee();
    virtual void a0ef();
    virtual void a0f0();
    virtual void a0f1();
    virtual void a0f2();
    virtual void a0f3();
    virtual void a0f4();
    virtual void a0f5();
    virtual void a0f6();
    virtual void a0f7();
    virtual void a0f8();
    virtual void a0f9();
    virtual void a0fa();
    virtual void a0fb();
    virtual void a0fc();
    virtual void a0fd();
    virtual void a0fe();
    virtual void a0ff();
    virtual void a100();
    virtual void a101();
    virtual void a102();
    virtual void a103();
    virtual void a104();
    virtual void a105();
    virtual void a106();
    virtual void a107();
    virtual void a108();
    virtual void a109();
    virtual void a10a();
    virtual void a10b();
    virtual void a10c();
    virtual void a10d();
    virtual void a10e();
    virtual void a10f();
    virtual void a110();
    virtual void a111();
    virtual void a112();
    virtual void a113();
    virtual void a114();
    virtual void a115();
    virtual void a116();
    virtual void a117();
    virtual void a118();
    virtual void a119();
    virtual void a11a();
    virtual void a11b();
    virtual void a11c();
    virtual void a11d();
    virtual void a11e();
    virtual void a11f();
    virtual void a120();
    virtual void a121();
    virtual void a122();
    virtual float GetAVModifierEntry(int aiAV, bool* abFound);
    virtual void SetAVModifierEntry(int aiAV, float afValue);
};

struct ActorBaseAVVtbl
{
    virtual void b000();
    virtual void b001();
    virtual void b002();
    virtual void b003();
    virtual void b004();
    virtual void b005();
    virtual void b006();
    virtual void b007();
    virtual void b008();
    virtual void b009();
    virtual void b00a();
    virtual void b00b();
    virtual void b00c();
    virtual void b00d();
    virtual void b00e();
    virtual void b00f();
    virtual void b010();
    virtual void b011();
    virtual void b012();
    virtual void b013();
    virtual void b014();
    virtual void b015();
    virtual void b016();
    virtual void b017();
    virtual void b018();
    virtual void b019();
    virtual void b01a();
    virtual void b01b();
    virtual void b01c();
    virtual void b01d();
    virtual void b01e();
    virtual void b01f();
    virtual void b020();
    virtual void b021();
    virtual void b022();
    virtual void b023();
    virtual void b024();
    virtual void b025();
    virtual void b026();
    virtual void b027();
    virtual void b028();
    virtual void b029();
    virtual void b02a();
    virtual void b02b();
    virtual void b02c();
    virtual void b02d();
    virtual void b02e();
    virtual void b02f();
    virtual void b030();
    virtual void b031();
    virtual void b032();
    virtual void b033();
    virtual void b034();
    virtual void b035();
    virtual void b036();
    virtual void b037();
    virtual void b038();
    virtual void b039();
    virtual void b03a();
    virtual void b03b();
    virtual void b03c();
    virtual void b03d();
    virtual void b03e();
    virtual void b03f();
    virtual void b040();
    virtual void b041();
    virtual void b042();
    virtual void b043();
    virtual void b044();
    virtual void b045();
    virtual void b046();
    virtual void b047();
    virtual void b048();
    virtual void b049();
    virtual void b04a();
    virtual void b04b();
    virtual void b04c();
    virtual void b04d();
    virtual void b04e();
    virtual void b04f();
    virtual void b050();
    virtual void b051();
    virtual void b052();
    virtual void b053();
    virtual void b054();
    virtual void b055();
    virtual void b056();
    virtual void b057();
    virtual void b058();
    virtual void b059();
    virtual void b05a();
    virtual void b05b();
    virtual void b05c();
    virtual void b05d();
    virtual void b05e();
    virtual void b05f();
    virtual void b060();
    virtual void b061();
    virtual void b062();
    virtual void b063();
    virtual void b064();
    virtual void b065();
    virtual void b066();
    virtual void ModBaseAV(int aiAV, int aiAmount);
};


struct ActorAVUpdater
{
};

struct FUN_0093a8f0_shell : public Actor
{
    void FUN_0093a8f0(int aiAV, int aiAmount);
};

// @fnv 0x0093a8f0
void FUN_0093a8f0_shell::FUN_0093a8f0(int aiAV, int aiAmount)
{
    float fOld = ::ActorValue::HasActorValueChangedCallback((::ActorValue::Index)(aiAV)) ? GetCurrentActorValue((ActorValue::Index)aiAV) : 0.0f;
    bool bFound4 = false;
    float fEntry5 = reinterpret_cast<ActorAVVtbl*>(this)->GetAVModifierEntry(aiAV, &bFound4);
    if (bFound4)
    {
        reinterpret_cast<ActorAVVtbl*>(this)->SetAVModifierEntry(aiAV, aiAmount + fOld);
    }
    else
    {
        reinterpret_cast<ActorBaseAVVtbl*>(GetActorBase())->ModBaseAV(aiAV, aiAmount);
    }
    ::FUN_00704e10(aiAV);
    reinterpret_cast<::FUN_008808f0_shell *>((reinterpret_cast<ActorAVUpdater*>(this)))->FUN_008808f0(aiAV, true);
    ::ActorValue::NotifyActorValueChanged(this, (::ActorValue::Index)(aiAV), fOld, (float)aiAmount, (::ActorValueOwner *)(0));
}


struct XA8a
{
};
struct XAObj
{
};
struct XPObj
{
    XPObj();
    ~XPObj();
    void* unk00;
    void* unk04;
    void* unk08;
};
struct XVObj
{
    XVObj();
    ~XVObj();
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
};
struct XTmpObj
{
};
struct XMember
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void Attach(int, void*);
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void Detach(int);
};
struct XUpdatable
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void Update();
};
struct XObj
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void Finish(XAObj*, int, int);
    void FUN_009694d0(void* arg0);
    void* unk04[25];
    XMember* member68;
};

// @fnv 0x009694d0
void XObj::FUN_009694d0(void* arg0)
{
    if (::GetExtraDataVersion((::TESObjectREFR *)(((XA8a*)arg0))))
        return;
    reinterpret_cast<::s5cc7a0::Owner *>(this)->FUN_005cc7a0(1);
    reinterpret_cast<::FUN_00950340_Class *>(this)->FUN_00950340(1);
    member68->Attach(0, this);
    member68->Detach(0);
    XAObj* A5 = (XAObj*)((void *)(::CreatePackageByType(0x26)));
    reinterpret_cast<::TESPackage *>((A5))->SetMustReachLocation(1);
    reinterpret_cast<::TESPackage *>((A5))->SetMustComplete(1);
    XPObj* P = new XPObj;
    reinterpret_cast<::FUN_0067f140_shell *>((P))->FUN_0067f140(0);
    reinterpret_cast<::LocationDescriptor *>((P))->FUN_0067f3c0((::TESObjectREFR *)(void *)(this));
    reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((A5))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(P));
    delete P;
    XVObj* X = new XVObj;
    reinterpret_cast<::FUN_00672fc0_shell *>((A5))->FUN_00672fc0((::PackageTargetRecord *)(X));
    delete X;
    reinterpret_cast<::TESPackage *>((A5))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(0x2F));
    reinterpret_cast<::PackageTargetRecord *>((((XTmpObj*)((void *)(reinterpret_cast<::Script *>((A5))->GetData())))))->SetTargetKind({});
    reinterpret_cast<::PackageTargetRecord *>((((XTmpObj*)((void *)(reinterpret_cast<::Script *>((A5))->GetData())))))->SetTargetObjectReference({});
    reinterpret_cast<::TESRegionGrassObject *>((((XTmpObj*)((void *)(reinterpret_cast<::Script *>((A5))->GetData())))))->AssignLandTexture({});
    ((::XUpdatable *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Update();
    Finish(A5, 0, 1);
}

template <int N, class B> struct TagBF
{
};
struct EmptyBF
{
};
template <int N, class B> struct SlotsBF : SlotsBF<N - 1, B>
{
    virtual void filler(TagBF<N, B>*);
};
template <class B> struct SlotsBF<0, B> : B
{
};
struct ProcBF0 : SlotsBF<10, EmptyBF>
{
    virtual void clear();
};
struct ProcBF1 : SlotsBF<128, ProcBF0>
{
    virtual void* get();
};
struct ProcBF2 : SlotsBF<261, ProcBF1>
{
    virtual void set(bool);
};
struct ProcBF : SlotsBF<50, ProcBF2>
{
    virtual void update(void*);
};
struct OtherBF : SlotsBF<133, EmptyBF>
{
    virtual void reset();
};
struct TargetBF
{
};
struct LocBF
{
    char data[12];
    LocBF();
    ~LocBF();
};
struct DataBF
{
    char data[16];
    DataBF();
    ~DataBF();
};
struct PackBF
{
};
struct GlobalBF
{
};
struct ActorBF0 : SlotsBF<162, EmptyBF>
{
    virtual void stop();
};
struct ActorBF : SlotsBF<26, ActorBF0>
{
    virtual void apply(PackBF*, int, bool);
    char pad[0x64];
    OtherBF* other;
    void FUN_008bf7b0(void*, int);
};
// @fnv 0x008bf7b0
void ActorBF::FUN_008bf7b0(void* arg, int unused)
{
    if (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0())))
        return;
    other->reset();
    ((::ProcBF *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->set(true);
    void* old3 = ((::ProcBF *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->get();
    if (((::TargetBF *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0())) && reinterpret_cast<::TESPackage *>((((::TargetBF *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()))))->IsPackageBlockingGreeting())
        stop();
    PackBF* pack = (PackBF*)((void *)(::CreatePackageByType(0x22)));
    reinterpret_cast<::PackageEx *>((pack))->SetPackageType(0x22);
    reinterpret_cast<::TESPackage *>((pack))->SetMustReachLocation(true);
    reinterpret_cast<::TESPackage *>((pack))->SetMustComplete(true);
    LocBF* loc = new LocBF;
    reinterpret_cast<::LocationDescriptor *>((loc))->FUN_0067f3c0((::TESObjectREFR *)(arg));
    reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((pack))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(loc));
    delete loc;
    DataBF* kDat = new DataBF;
    reinterpret_cast<::FUN_00672fc0_shell *>((pack))->FUN_00672fc0((::PackageTargetRecord *)(kDat));
    delete kDat;
    reinterpret_cast<::TESPackage *>((pack))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(0x2a));
    reinterpret_cast<::PackageTargetRecord *>((((::DataBF *)(reinterpret_cast<::Script *>((pack))->GetData()))))->SetTargetKind((::PACK_TARG_TYPE)(0));
    reinterpret_cast<::PackageTargetRecord *>((((::DataBF *)(reinterpret_cast<::Script *>((pack))->GetData()))))->SetTargetObjectReference((::TESObjectREFR *)(arg));
    reinterpret_cast<::TESRegionGrassObject *>((((::DataBF *)(reinterpret_cast<::Script *>((pack))->GetData()))))->AssignLandTexture((::TESLandTexture *)(0));
    ((::ProcBF *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->clear();
    ((::ProcBF *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->update(this);
    apply(pack, 0, true);
    reinterpret_cast<::StealWarningState *>(((*(GlobalBF**)&(*reinterpret_cast<char *>(&::_g_thePlayer)))))->FUN_00966e00();
}

struct AssignedProcess
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void Update();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual bool State11c();
    virtual void slot120();
    virtual void slot124();
    virtual unsigned int State128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void Attach(int, void*);
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void* GetTarget();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual unsigned int State23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual void slot438();
    virtual void slot43c();
    virtual void slot440();
    virtual void slot444();
    virtual void slot448();
    virtual void slot44c();
    virtual void slot450();
    virtual void slot454();
    virtual void slot458();
    virtual void slot45c();
    virtual void slot460();
    virtual void slot464();
    virtual void slot468();
    virtual void slot46c();
    virtual void slot470();
    virtual void slot474();
    virtual void slot478();
    virtual void slot47c();
    virtual void slot480();
    virtual void slot484();
    virtual void slot488();
    virtual void slot48c();
    virtual void slot490();
    virtual void slot494();
    virtual void slot498();
    virtual void slot49c();
    virtual void slot4a0();
    virtual void slot4a4();
    virtual void slot4a8();
    virtual void slot4ac();
    virtual void slot4b0();
    virtual void slot4b4();
    virtual void slot4b8();
    virtual void slot4bc();
    virtual void slot4c0();
    virtual void slot4c4();
    virtual void slot4c8();
    virtual void slot4cc();
    virtual void slot4d0();
    virtual void slot4d4();
    virtual void slot4d8();
    virtual void slot4dc();
    virtual void slot4e0();
    virtual void slot4e4();
    virtual bool State4e8();
    virtual void slot4ec();
    virtual void slot4f0();
    virtual void slot4f4();
    virtual void slot4f8();
    virtual void slot4fc();
    virtual void slot500();
    virtual void slot504();
    virtual void slot508();
    virtual void slot50c();
    virtual void slot510();
    virtual void slot514();
    virtual void slot518();
    virtual void slot51c();
    virtual void slot520();
    virtual void slot524();
    virtual void slot528();
    virtual void slot52c();
    virtual void slot530();
    virtual void slot534();
    virtual void slot538();
    virtual void slot53c();
    virtual void slot540();
    virtual void slot544();
    virtual void slot548();
    virtual void slot54c();
    virtual void slot550();
    virtual void slot554();
    virtual void slot558();
    virtual void slot55c();
    virtual void slot560();
    virtual void slot564();
    virtual void slot568();
    virtual void slot56c();
    virtual void slot570();
    virtual void slot574();
    virtual void slot578();
    virtual void slot57c();
    virtual void slot580();
    virtual void slot584();
    virtual void slot588();
    virtual void slot58c();
    virtual void slot590();
    virtual void slot594();
    virtual void slot598();
    virtual void slot59c();
    virtual void slot5a0();
    virtual bool State5a4();
    virtual void slot5a8();
    virtual void slot5ac();
    virtual void slot5b0();
    virtual void slot5b4();
    virtual void slot5b8();
    virtual void slot5bc();
    virtual void slot5c0();
    virtual void slot5c4();
    virtual void slot5c8();
    virtual void slot5cc();
    virtual void slot5d0();
    virtual void slot5d4();
    virtual void slot5d8();
    virtual void slot5dc();
    virtual void slot5e0();
    virtual void slot5e4();
    virtual void slot5e8();
    virtual void slot5ec();
    virtual void slot5f0();
    virtual void slot5f4();
    virtual void slot5f8();
    virtual void slot5fc();
    virtual void slot600();
    virtual void slot604();
    virtual void slot608();
    virtual void slot60c();
    virtual void slot610();
    virtual void slot614();
    virtual void slot618();
    virtual void slot61c();
    virtual void slot620();
    virtual void slot624();
    virtual void slot628();
    virtual void slot62c();
    virtual void slot630();
    virtual void slot634();
    virtual void slot638();
    virtual void slot63c();
    virtual void slot640();
    virtual void Detach(int);
};
struct AssignedActorView
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void Reset();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void Finish(XAObj*, int, int);
};
struct AssignedPackageView
{
};
struct AssignedTargetView;
struct AssignedPackageDataView
{
};
struct AssignedTargetView
{
};
struct AssignedExtraView
{
};
struct AssignedArgument
{
};
struct AssignedCharacter : Character
{
    void FUN_008d2a80(AssignedArgument* argument);
};
// @fnv 0x008d2a80
void AssignedCharacter::FUN_008d2a80(AssignedArgument* argument)
{
    if (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0())))
        return;
    ((AssignedProcess*)m_pBaseProcess)->Attach(0, this);
    ((AssignedProcess*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))->Detach(0);
    void* previousTarget = ((AssignedProcess*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))->GetTarget();
    if (((::AssignedPackageView *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0())) && reinterpret_cast<::TESPackage *>((((::AssignedPackageView *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0()))))->IsPackageBlockingGreeting())
        ((AssignedActorView*)this)->Reset();
    // Location data installed into the travel package.
    XPObj* package;
    // AI package for travel to the supplied location.
    XAObj* location = (XAObj*)((void *)(::CreatePackageByType(38)));
    reinterpret_cast<::TESPackage *>((location))->SetMustReachLocation(1);
    reinterpret_cast<::TESPackage *>((location))->SetMustComplete(1);
    package = new XPObj;
    reinterpret_cast<::FUN_0067f140_shell *>((package))->FUN_0067f140(0);
    reinterpret_cast<::LocationDescriptor *>((package))->FUN_0067f3c0((::TESObjectREFR *)(void *)(this));
    reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((location))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(package));
    delete package;
    XVObj* target = new XVObj;
    reinterpret_cast<::FUN_00672fc0_shell *>((location))->FUN_00672fc0((::PackageTargetRecord *)(target));
    delete target;
    reinterpret_cast<::TESPackage *>((location))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(47));
    reinterpret_cast<::PackageTargetRecord *>((((::AssignedTargetView *)(reinterpret_cast<::Script *>((((AssignedPackageDataView*)location)))->GetData()))))->SetTargetKind((::PACK_TARG_TYPE)(0));
    reinterpret_cast<::PackageTargetRecord *>((((::AssignedTargetView *)(reinterpret_cast<::Script *>((((AssignedPackageDataView*)location)))->GetData()))))->SetTargetObjectReference((::TESObjectREFR *)(argument));
    reinterpret_cast<::TESRegionGrassObject *>((((::AssignedTargetView *)(reinterpret_cast<::Script *>((((AssignedPackageDataView*)location)))->GetData()))))->AssignLandTexture((::TESLandTexture *)(0));
    ((AssignedProcess*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))->Update();
    if (((AssignedProcess*)m_pBaseProcess)->GetTarget())
    {
        reinterpret_cast<::FUN_0041c930_shell *>((((::AssignedExtraView *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041c930(
            (::Package_0041c930 *)(void *)(((AssignedProcess*)m_pBaseProcess)->GetTarget()), ((AssignedProcess*)m_pBaseProcess)->State23c(),
            ((AssignedProcess*)m_pBaseProcess)->State128(), ((AssignedProcess*)m_pBaseProcess)->State11c(),
            ((AssignedProcess*)m_pBaseProcess)->State4e8(), ((AssignedProcess*)m_pBaseProcess)->State5a4());
    }
    ((AssignedActorView*)this)->Finish(location, 0, 1);
    reinterpret_cast<::ActorData *>((argument))->EnableActionResourceIfLowState();
}

struct FormStandin
{
    virtual ~FormStandin();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct ChildCellStandin
{
    virtual void* GetPersistentCell();
};
struct RefStandin : public FormStandin, public ChildCellStandin
{
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    virtual void Set3D(void* apNode, bool abUnloadArt);
};
struct MagicCasterStandin
{
    virtual void CastSpell();
    int unk04;
    int unk08;
};
struct MagicTargetStandin
{
    virtual void AddEffectToTarget();
    int unk04;
    int unk08;
    int unk0C;
};
struct ValueOwnerStandin
{
    virtual int GetBaseActorValue();
};
struct CachedOwnerStandin
{
    virtual float GetRadius();
};
struct ActorStandin : public RefStandin,
                      public MagicCasterStandin,
                      public MagicTargetStandin,
                      public ValueOwnerStandin,
                      public CachedOwnerStandin
{
    virtual ~ActorStandin();
};
struct FUN_008d2060 : public ActorStandin
{
    virtual ~FUN_008d2060();
};
// Calls FUN_008d2060, then deallocates this if bit 0 of aiFlags is set, and returns this.
// @fnv 0x008d1f10
FUN_008d1f10_shell* FUN_008d1f10_shell::FUN_008d1f10(unsigned int aiFlags)
{
    reinterpret_cast<::FUN_008d2060 *>(this)->FUN_008d2060::~FUN_008d2060();
    if (aiFlags & 1)
    {
        ::FUN_00401030(this);
    }
    return this;
}

// @fnv 0x008d2060
FUN_008d2060::~FUN_008d2060()
{
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
        Set3D(0, false);
}

#define PlayerCharacter PlayerCharacter_ActorHeader
#define FNV_NIPOINT3_H
class ActiveEffect;
template <class T> class BSSimpleList;

class Actor;
class Animation;
class NiNode;
class ParentSpaceNode;
class GameSettingCollection;
extern GlobalObject_0045d260 g_011df69c;
enum ACTOR_LIFE_STATE;
#undef PlayerCharacter

class MusicMarkerReference;
struct Biped;
bool Character_GetTrespassing(Character* self);
void FUN_008d1e90(Character* this_ptr, float value);

class TESObjectARMO : public TESBoundObject
{
};
struct FUN_004bc5f0
{
    void* extraData;
    int count;
    TESBoundObject* object;
    ~FUN_004bc5f0();
};
struct EquipmentList536
{
};
struct ExtraList536
{
};
struct Character536 : Character
{
    float FUN_008d2110();
};
// @fnv 0x008d2110
float Character536::FUN_008d2110()
{
    int count = 0;
    TESObjectARMO* forms3[20];
    forms3[0] = 0;
    if (m_fSecondValue < ::_DAT_01012060)
    {
        m_fSecondValue = 0.0f;
        EquipmentList536* list6 = ((::EquipmentList536 *)(reinterpret_cast<::ExtraDataList *>((((::ExtraList536 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->GetContainerChangeData()));
        FUN_004bc5f0* item7 = 0;
        if (list6)
        {
            for (int index = 0; index < 20; ++index)
            {
                item7 = ((::FUN_004bc5f0 *)(reinterpret_cast<::Target *>((list6))->FUN_004c8c10(index, false)));
                if (item7)
                {
                    TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item7))->GetName())));
                    if (armor)
                    {
                        bool found4 = false;
                        if (count != 0)
                        {
                            for (int scan5 = 0; scan5 < count && !found4; ++scan5)
                                found4 = forms3[scan5] == armor;
                        }
                        if (!found4)
                        {
                            m_fSecondValue += reinterpret_cast<::InventoryStackRecord *>((item7))->GetArmorDamageThreshold((::Actor *)(::ActorValueOwner *)(static_cast<ActorValueOwner*>(this)));
                            forms3[count] = armor;
                            ++count;
                        }
                    }
                    delete item7;
                    item7 = 0;
                }
            }
        }
    }
    return m_fSecondValue;
}


// Adapted from an unverified 2026-10-23 contribution by another contributor.

struct InventoryEntry_8d22b0
{
    ~InventoryEntry_8d22b0();
    float GetEntryWeight(ActorValueOwner* owner);
};
struct InventoryData_8d22b0
{
};
struct ContainerChanges_8d22b0
{
};

union SETTING_VALUE
{
    float f;
    int i;
    unsigned int u;
    char* str;
};
template <> class SettingT<GameSettingCollection>
{
  public:
};

struct FUN_008d22b0_shell : public Actor
{
    int unk1b4;
    float m_kEighthUnshownMember;
    float FUN_008d22b0();
};

// @fnv 0x008d22b0
float FUN_008d22b0_shell::FUN_008d22b0()
{
    int iCount = 0;
    TESObjectARMO* armors[20];
    armors[0] = 0;
    if (m_kEighthUnshownMember < 0.0)
    {
        m_kEighthUnshownMember = 0.0f;
        InventoryData_8d22b0* items = ((::InventoryData_8d22b0 *)(reinterpret_cast<::ExtraDataList *>((((::ContainerChanges_8d22b0 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->GetContainerChangeData()));
        InventoryEntry_8d22b0* entry = 0;
        if (items)
        {
            for (int i = 0; i < 20; i++)
            {
                entry = ((::InventoryEntry_8d22b0 *)(reinterpret_cast<::Target *>((items))->FUN_004c8c10(i, 0)));
                if (entry)
                {
                    TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())));
                    if (armor)
                    {
                        bool found = false;
                        if (iCount)
                        {
                            for (int j = 0; j < iCount && !found; j++)
                            {
                                found = armors[j] == armor;
                            }
                        }
                        if (!found)
                        {
                            m_kEighthUnshownMember += entry->GetEntryWeight(this);
                            armors[iCount++] = armor;
                        }
                    }
                    delete entry;
                    entry = 0;
                }
            }
        }
    }
    return ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1016))))->f > 0.0
               ? FUN_0040ebd0(m_kEighthUnshownMember, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1016))))->f)
               : m_kEighthUnshownMember;
}

class TESObjectCLOT : public TESBoundObject
{
};
struct InventoryEntryWeight534
{
};
struct EquipmentList534
{
};
struct ExtraList534
{
};
struct Character534 : Character
{
    float FUN_008d3110();
};
// @fnv 0x008d3110
float Character534::FUN_008d3110()
{
    float weight = 0.0f;
    EquipmentList534* list = ((::EquipmentList534 *)(reinterpret_cast<::ExtraDataList *>((((::ExtraList534 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->GetContainerChangeData()));
    FUN_004bc5f0* item9 = 0;
    int index2;
    TESObjectARMO* armor7;
    TESObjectCLOT* clothing;
    if (list)
    {
        for (index2 = 0; index2 < 20; ++index2)
        {
            item9 = ((::FUN_004bc5f0 *)(reinterpret_cast<::Target *>((list))->FUN_004c8c10(index2, false)));
            if (item9)
            {
                armor7 = dynamic_cast<TESObjectARMO*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item9))->GetName())));
                clothing = dynamic_cast<TESObjectCLOT*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item9))->GetName())));
                if (armor7)
                    weight +=
                        ((double)(reinterpret_cast<::ItemChangeValueShell *>((((InventoryEntryWeight534*)item9)))->FUN_004bd400())) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting999)))))) + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::g_011d1104))))));
                else if (clothing)
                    weight +=
                        ((double)(reinterpret_cast<::ItemChangeValueShell *>((((InventoryEntryWeight534*)item9)))->FUN_004bd400())) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting998)))))) + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::g_011d043c))))));
                // GetEquippedItem returns an owned temporary inventory entry.
                delete item9;
                item9 = 0;
            }
        }
    }
    if (weight > 100.0)
        weight = 100.0f;
    return weight;
}
#include "generated/data/fallout/ai/character.inc"
