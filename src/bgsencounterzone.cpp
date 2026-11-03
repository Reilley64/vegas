// bgsencounterzone.cpp: BGSEncounterZone, TESObjectREFR, ZoneComparison, EncounterZoneCopy (24 functions)

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00526000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00663000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "bgsencounterzone_decls.h"
// Sets the form type to 0x61 and then runs the constructor's initialization routine.
// @fnv 0x00525c40
BGSEncounterZone::BGSEncounterZone()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x61)));
    ResetFormData();
}

// Clears the Data and GameData members by zeroing their memory.
// @fnv 0x00525d00
void BGSEncounterZone::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
    memset(&GameData, 0, sizeof(GameData));
}

#include "bgsencounterzone_TESFile.h"
#include <malloc.h>
class DataHandler
{
  public:
};

// Creates the NoZoneZone BGSEncounterZone once, sets its ref ID and editor ID, and adds it to the data handler.
// @fnv 0x00526340
void BGSEncounterZone::CreateDefaultEncounterZone()
{
    if (!::DAT_011c9520)
    {
        ::DAT_011c9520 = new BGSEncounterZone;
        ::DAT_011c9520->SetRefID(0x1e, true);
        ::DAT_011c9520->SetEditorID_AtRuntime("NoZoneZone");
        reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->AddFormToDataHandler(::DAT_011c9520);
    }
}

// Reads an encounter zone record from file: checks form type 0x61, loads the header, then handles EDID, OBND and DATA chunks.
// @fnv 0x00525d40
bool BGSEncounterZone::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x61)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    unsigned int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), sizeof(Data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>(&(Data))->FUN_00503210();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the encounter zone's owner form ID to a TESForm pointer, warns if it is missing, then marks the zone initialized.
// @fnv 0x00525f00
void BGSEncounterZone::InitItem()
{
    if (GetInitialized())
        return;
    if (Data.m_pOwnerForm)
    {
        struct OwnerResolution
        {
            unsigned int formID;
            TESForm* owner;
        } ownerResolution;
        ownerResolution.formID = (unsigned int)Data.m_pOwnerForm;
        ::ResolveFormID((unsigned int *)&(ownerResolution.formID), GetFile(-1));
        ownerResolution.owner = ::FUN_004839c0(ownerResolution.formID);
        if (!ownerResolution.owner)
            ::FUN_005b5e40();
        Data.m_pOwnerForm = ownerResolution.owner;
    }
    SetInitializationState(true);
}

// API-only declarations: layouts are not used by this member.
class ExtraDataList
{
  public:
};
class TESWorldSpace
{
  public:
};
class TESObjectREFR
{
  public:
    BGSEncounterZone* FindEncounterZone();
};

// Returns the encounter zone from the extra data list, falling back to the parent cell's and then the worldspace's encounter zone.
// @fnv 0x00567d20
BGSEncounterZone* TESObjectREFR::FindEncounterZone()
{
    BGSEncounterZone* zone = reinterpret_cast<::FUN_00421c30_shell *>((void *)(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00421c30();
    if (!zone)
    {
        if (((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())))
            zone = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))->FindEncounterZone();
        if (!zone)
        {
            if (((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(this)->FUN_00575d70())))
                zone = ((::BGSEncounterZone *)(reinterpret_cast<::FUN_00458400_cls *>((void *)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(this)->FUN_00575d70()))))->GetFieldD0()));
        }
    }
    return zone;
}

class Actor
{
  public:
};
class PlayerCharacter : public Actor
{
};
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
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting36;

// @fnv 0x00526190
unsigned short BGSEncounterZone::GetCalculatedLevel()
{
    unsigned short level = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((::_g_thePlayer))->FUN_0087f9f0();
    if (level < ((unsigned char)(::GetByteAt1D((char *)this))))
    {
        if (!QMatchPCBelowMin())
            level = ((unsigned char)(::GetByteAt1D((char *)this)));
    }
    else
    {
        level = (unsigned short)(((unsigned char)(::GetByteAt1D((char *)this))) + (level - ((unsigned char)(::GetByteAt1D((char *)this)))) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting36))))->f);
    }
    return level;
}

// @fnv 0x00526250
bool BGSEncounterZone::QMatchPCBelowMin()
{
    return (bool)(Data.cFlags & 2);
}

struct FUN_00525cb0_shell
{
    void FUN_00525ce0();
    FUN_00525cb0_shell* Destroy(unsigned int flags);
};
struct Base5a
{
    virtual ~Base5a();
};
struct FUN_00525ce0 : Base5a
{
    virtual ~FUN_00525ce0();
};
// Calls FUN_00525ce0, deletes this when bit 0 of flags is set, and returns this.
// @fnv 0x00525cb0
FUN_00525cb0_shell* FUN_00525cb0_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00525ce0 *>(this)->FUN_00525ce0::~FUN_00525ce0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00525ce0
FUN_00525ce0::~FUN_00525ce0()
{}

struct S004855a0
{
};
struct S00485680
{
};
struct FUN_00525e70 : BGSEncounterZone
{
    void Save();
};
// @fnv 0x00525e70
void FUN_00525e70::Save()
{
    TESForm* powner;
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<S004855a0*>(this)))->FUN_004855a0();
    powner = this->Data.m_pOwnerForm;
    if (powner)
    {
        *(unsigned int*)((char*)this + 0x18) = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((powner))->FUN_0084e3a0()));
    }
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>(&(Data))->FUN_00503210();
    ::AppendChunk(0x41544144, &Data, 8);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>(&(Data))->FUN_00503210();
    this->Data.m_pOwnerForm = powner;
    reinterpret_cast<::Holder *>((reinterpret_cast<S00485680*>(this)))->FUN_00485680();
}

struct FUN_00526070_shell
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
    virtual void v18(unsigned int f);
    void FUN_00526070(unsigned int arg);
};
// @fnv 0x00526070
void FUN_00526070_shell::FUN_00526070(unsigned int arg)
{
    *(unsigned int*)((char*)this + 0x20) = arg;
    v18(0x80000000);
}

struct FUN_005260a0_shell
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
    virtual void v18(unsigned int f);
    void FUN_005260a0(unsigned int arg);
};
// @fnv 0x005260a0
void FUN_005260a0_shell::FUN_005260a0(unsigned int uiValue)
{
    *(unsigned int*)((char*)this + 0x24) = uiValue;
    if (*(unsigned int*)((char*)this + 0x20) != 0)
    {
        if (*(unsigned int*)((char*)this + 0x24) - *(unsigned int*)((char*)this + 0x20) > ((unsigned int)(::fnv_00526100::FUN_00526100())))
            *(unsigned int*)((char*)this + 0x28) = uiValue;
    }
    v18(0x80000000);
}

namespace fnv_00526100 {
struct GlobalObject2_0040c150
{
};

GlobalObject2_0040c150 g_011ca160;

// @fnv 0x00526100
int __cdecl FUN_00526100()
{
    return *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00526100::GlobalObject2_0040c150 *>(&::g_011ca160))))));
}
}  // namespace fnv_00526100

struct FUN_00546af0_shell
{
    unsigned int FUN_00546af0();
};
struct FUN_00526120_shell
{
    bool FUN_00526120(FUN_00546af0_shell* other);
};
// Returns false if the value at offset 0x28 is zero, otherwise returns whether other's FUN_00546af0() result is below that value.
// @fnv 0x00526120
bool FUN_00526120_shell::FUN_00526120(FUN_00546af0_shell* other)
{
    if (*(unsigned int*)((char*)this + 0x28) == 0)
        return false;
    unsigned int v = other->FUN_00546af0();
    if (v < *(unsigned int*)((char*)this + 0x28))
        return true;
    return false;
}

struct FUN_00526160_shell
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
    virtual void v18(unsigned int f);
    void FUN_00526160(unsigned short arg);
};
// @fnv 0x00526160
void FUN_00526160_shell::FUN_00526160(unsigned short arg)
{
    *(unsigned short*)((char*)this + 0x2c) = arg;
    v18(0x80000000);
}

struct FUN_00526160_s
{
};
struct FUN_00526270_shell : BGSEncounterZone
{
    void FUN_00526270();
};
// @fnv 0x00526270
void FUN_00526270_shell::FUN_00526270()
{
    if (this->GameData.m_usDetachRecordValue == 0)
        reinterpret_cast<::FUN_00526160_shell *>((reinterpret_cast<FUN_00526160_s*>(this)))->FUN_00526160(GetCalculatedLevel());
}

struct Zone81
{
    bool FUN_00526320();
};
struct TESObject
{
};
struct Calendar
{
    unsigned int GetGameHoursPassed();
};
// @fnv 0x005262a0
bool FUN_005262a0(BGSEncounterZone* apZone)
{
    bool result = true;
    if (apZone != ::DAT_011c9520 && apZone->GameData.m_usDetachRecordValue)
    {
        if (reinterpret_cast<Zone81*>(apZone)->FUN_00526320())
        {
            result = false;
        }
        else
        {
            unsigned int next = ((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<TESObject*>(apZone)))->FUN_007af430()));
            if (next)
            {
                unsigned int now = (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameHoursPassed();
                if (now - next <= ((unsigned int)(::fnv_00526100::FUN_00526100())))
                    result = false;
            }
            else
            {
                result = false;
            }
        }
    }
    return result;
}

struct FUN_00526320_shell
{
    bool FUN_00526320();
};
// @fnv 0x00526320
bool FUN_00526320_shell::FUN_00526320()
{
    return (*(signed char*)((char*)this + 0x1e) & 1) ? true : false;
}

struct FormChangeMask
{
    unsigned int f;
    FormChangeMask();
    operator bool() const;
};
struct BGSSaveFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
struct S00484d60
{
};
struct FUN_00526410 : BGSEncounterZone
{
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x00526410
void FUN_00526410::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned char ctempFlags;
    reinterpret_cast<::FakeForm *>((reinterpret_cast<S00484d60*>(this)))->SaveIfChanged(apSaveGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags(2)))->FUN_004280f0(2))
    {
        ctempFlags = *(signed char*)&this->Data.cFlags & 1;
        reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&ctempFlags, 1, 0);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags(0x80000000)))->FUN_004280f0(static_cast<int>(0x80000000)))
    {
        reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((char*)&this->GameData, 0x10, 0);
    }
}

namespace fnv_00526570 {
struct FormChangeMask
{
    unsigned int flags;
    FormChangeMask();
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int f);
};
struct FUN_00526570_shell : BGSEncounterZone
{
    void RevertAndClearIfChanged(BGSLoadFormBuffer* buf);
};
// @fnv 0x00526570
void FUN_00526570_shell::RevertAndClearIfChanged(BGSLoadFormBuffer* pLoadBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(reinterpret_cast<unsigned int>(pLoadBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00526570::FormChangeMask &)(pLoadBuffer->GetOldChangeFlags(0x80000000)))->FUN_004280f0(static_cast<int>(0x80000000)))
        memset((char*)&this->GameData, 0, 0x10);
}
}  // namespace fnv_00526570

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    FormChangeMask GetChangeFlags(unsigned int);
};

struct FUN_005264a0_shell : public BGSEncounterZone
{
    void FUN_005264a0(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Loads the encounter zone from the buffer, reading a flag byte and, for version 8+, a 16-byte field at offset 0x20.
// @fnv 0x005264a0
void FUN_005264a0_shell::FUN_005264a0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ctempFlags;

    TESForm::LoadGame(apLoadGameBuffer);

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(2)))->FUN_004280f0(2))
    {
        ctempFlags = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ctempFlags), 1);
        this->Data.cFlags = (this->Data.cFlags & ~1) | (this->Data.cFlags & 1);
    }

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x80000000)))->FUN_004280f0(static_cast<int>(0x80000000)))
    {
        if (apLoadGameBuffer->GetVersion() >= 8)
        {
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->GameData), 0x10);
        }
        else
        {
            char acTempData[8];
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(acTempData), 8);
        }
    }
}

struct ZoneBaseComparison
{
};
struct ZoneComparison : BGSEncounterZone
{
    bool FUN_00526000(TESForm* other);
};
// Returns true when other is not a BGSEncounterZone, the base comparison returns true, or the Data bytes differ.
// @fnv 0x00526000
bool ZoneComparison::FUN_00526000(TESForm* other)
{
    BGSEncounterZone* zone = dynamic_cast<BGSEncounterZone*>(other);
    if (!zone)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<ZoneBaseComparison*>(this)))->FUN_00485270(zone))
        return true;
    if (memcmp(&Data, &zone->Data, sizeof(Data)))
        return true;
    return false;
}


struct FormComponentCopy
{
};

struct EncounterZoneCopy : BGSEncounterZone
{
    void FUN_00525fa0(TESForm* source);
};

// Copies encounter zone data from another BGSEncounterZone into this instance via FormComponentCopy and a raw memcpy of Data.
// @fnv 0x00525fa0
void EncounterZoneCopy::FUN_00525fa0(TESForm* source)
{
    BGSEncounterZone* other = dynamic_cast<BGSEncounterZone*>(source);
    if (!other)
        return;
    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FormComponentCopy*>(this)))->FUN_004851b0(other);
    ::__memcpy(&Data, &other->Data, sizeof(Data));
}

#include "generated/data/bgsencounterzone.inc"
