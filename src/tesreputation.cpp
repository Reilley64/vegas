// tesreputation.cpp: TESReputation, ReputationTracker, Reputation, ReputationUpdate and more (25 functions)

#include <cstring>
#include "fnv/decl/B616890Menu.h"
#include "fnv/decl/B616A20Meter.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_00616a40_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00953c50_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/PackedByteIntRecord.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESSkill.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011de000.h"
#include "tesreputation_decls.h"
#include <malloc.h>

// @fnv 0x00615560
void TESReputation::ResetFormData()
{
    m_fFirstReputationValue = 0.0f;
    m_fSecondReputationValue = 0.0f;
}

// @fnv 0x00616290
bool TESReputation::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            ::ReadFullName(this, file);
            break;
        case 'NOCI':
            ::TESTexture::ReadTextureData(this, file);
            break;
        case 'OCIM':
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case 'ATAD':
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>(&(data))->FUN_00503210();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x007dc0a0
unsigned int* TESReputation::GetUnsignedIntegerPointer(unsigned int* puiValue)
{
    ++*puiValue;
    return puiValue;
}

// @fnv 0x006155c0
float TESReputation::GetUnsignedIntegerPointer(ReputationType type)
{
    if (type == ReputationType_REPUTATION_POSITIVE)
    {
        return m_fFirstReputationValue;
    }
    else
    {
        return m_fSecondReputationValue;
    }
}

struct FUN_006153c0 : public TESForm, public TESFullName, public TESIcon, public BGSMessageIcon
{
    FUN_006153c0();
    ~FUN_006153c0();
};

// @fnv 0x006153c0
FUN_006153c0::FUN_006153c0()
{
    ((TESReputation*)this)->TESReputation::ResetFormData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x68)));
}

extern char DAT_0119a0bc;

// @fnv 0x00615720
void __cdecl FUN_00615720(void)
{
    DAT_0119a0bc = ConsumeByteAtE4();
}

struct FUN_006159e0_shell
{
    char pad[0xe0c];
    TESReputation* m_pLastChangedReputation;
    void SetValue(TESReputation* apReputation);
};

// @fnv 0x006159e0
void FUN_006159e0_shell::SetValue(TESReputation* apReputation)
{
    m_pLastChangedReputation = apReputation;
}

struct FNStub
{
};
class TESModel
{
  public:
    unsigned int GetModelLength(void) const;
};
extern const char $SG5812[];

struct FUN_006166e0_shell
{
    char pad[0x24];
    TESModel m_Model;
    const char* GetReputationName(void);
};

// @fnv 0x006166e0
const char* FUN_006166e0_shell::GetReputationName()
{
    if (m_Model.GetModelLength())
        return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)&this->m_Model)))->FUN_00408da0()));
    return $SG5812;
}

struct FUN_00484bf0
{
    unsigned short GetSaveSize(unsigned int);
};

struct FUN_006165f0_shell
{
    unsigned short FUN_006165f0(unsigned int aiFlags);
};

// Returns the save size: the result of GetSaveSize(aiFlags) plus 8 bytes.
// @fnv 0x006165f0
unsigned short FUN_006165f0_shell::FUN_006165f0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00484bf0_shell *>((((FUN_00484bf0*)this)))->FUN_00484bf0(aiFlags);
    isize += 4;
    isize += 4;
    return isize;
}

struct BGSLoadFormBuffer
{
};

struct FUN_006166a0_shell : public TESReputation
{
    void FUN_006166a0(BGSLoadFormBuffer* buffer);
};

// @fnv 0x006166a0
void FUN_006166a0_shell::FUN_006166a0(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fFirstReputationValue), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fSecondReputationValue), 4);
}

struct FUN_00615480_shell
{
    void* FUN_00615480(unsigned int);
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct FUN_00485680
{
};
struct FUN_00616470_shell : public TESReputation
{
    void FUN_00616470(void);
};
// @fnv 0x00616470
void FUN_00616470_shell::FUN_00616470()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(static_cast<TESForm*>(this))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(static_cast<TESFullName*>(this))->FUN_00487010();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(static_cast<TESIcon*>(this))->FUN_0048e370(0x4e4f4349);
    reinterpret_cast<FUN_0047a240_shell*>(static_cast<BGSMessageIcon*>(this))->FUN_0047a240(0x4f43494d);
    if (FUN_00401500())
        reinterpret_cast<::fnv_00503210::Unk *>(&data)->FUN_00503210();
    reinterpret_cast<::SDSaveForm *>(static_cast<TESForm*>(this))->FUN_00485e20(&data, 4);
    if (FUN_00401500())
        reinterpret_cast<::fnv_00503210::Unk *>(&data)->FUN_00503210();
    reinterpret_cast<::Holder *>(static_cast<TESForm*>(this))->FUN_00485680();
}

struct FUN_00615580_shell
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18(int) = 0;
    char _pad[0x40];
    float m44;
    float m48;
    void FUN_00615580(int, float);
};
// Stores b into m44 when a equals 1, otherwise into m48, then calls v18 with 2.
// @fnv 0x00615580
void FUN_00615580_shell::FUN_00615580(int a, float afValue)
{
    if (a == 1)
        m44 = afValue;
    else
        m48 = afValue;
    v18(2);
}

struct FUN_00484d60_holder
{
};

struct BGSSaveFormBuffer
{
};

struct FUN_00616660_shell
{
    char pad[0x44];
    unsigned int f0;
    unsigned int f1;
    void SaveToBuffer(BGSSaveFormBuffer* buffer);
};

// Calls SaveIfChanged on this, then saves the two 4-byte fields f0 and f1 to the buffer.
// @fnv 0x00616660
void FUN_00616660_shell::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FakeForm *>((((FUN_00484d60_holder*)this)))->SaveIfChanged((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&f0, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&f1, 4, 0);
}

struct StartMenu
{
    const char* GetMenuTitle(void);
};


struct FUN_006155f0_shell
{
    char pad_00[0x18];
    FNStub mFNStub;
    char pad_1c[0x30];
    int mField_4c;

    void ShowMessageBox(void);
};



class Sub18_b9216
{
  public:
    virtual ~Sub18_b9216();
    unsigned int m_04;
    unsigned int m_08;
};

class Sub24_b9216
{
  public:
    virtual ~Sub24_b9216();
    unsigned int m_04;
    unsigned int m_08;
};

class Sub30_b9216
{
  public:
    virtual ~Sub30_b9216();
    unsigned int m_04;
    unsigned int m_08;
};

class Base_b9216
{
  public:
    virtual ~Base_b9216();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
};

class FUN_006154b0_cls : public Base_b9216, public Sub18_b9216, public Sub24_b9216, public Sub30_b9216
{
  public:
    virtual ~FUN_006154b0_cls();
};
// Calls FUN_006154b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00615480
void* FUN_00615480_shell::FUN_00615480(unsigned int flags)
{
    reinterpret_cast<::FUN_006154b0_cls *>(this)->FUN_006154b0_cls::~FUN_006154b0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006154b0
FUN_006154b0_cls::~FUN_006154b0_cls()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

Base_b9216::~Base_b9216()
{}
Sub18_b9216::~Sub18_b9216()
{}
Sub24_b9216::~Sub24_b9216()
{}
Sub30_b9216::~Sub30_b9216()
{}

struct ReputationLimit
{
};
struct ReputationTracker
{
    unsigned char GetReputationRank(int kind);
};
// @fnv 0x00616950
unsigned char ReputationTracker::GetReputationRank(int kind)
{
    float value = 0.0f;
    unsigned char rank = 0;
    if (kind == 1)
    {
        value = reinterpret_cast<::B616A20Meter *>(this)->FUN_00616a20();
    }
    else
    {
        value = reinterpret_cast<::FUN_00616a40_cls *>(this)->FUN_00616a40();
    }
    if (value >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ReputationLimit *>(&::originalRuntimeFloatSetting56)))))) && value < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ReputationLimit *>(&::originalRuntimeFloatSetting57)))))))
    {
        rank = 1;
    }
    else if (value >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ReputationLimit *>(&::originalRuntimeFloatSetting57)))))) && value < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ReputationLimit *>(&::g_011cbd68)))))))
    {
        rank = 2;
    }
    else if (value >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ReputationLimit *>(&::g_011cbd68)))))))
    {
        rank = 3;
    }
    return rank;
}

// Multiple-inheritance constructor: base A (0x18 bytes, out-of-line ctor),
// base B (4 bytes, vptr only, also the element type of the member array),
// base C (16 bytes, 8-aligned, out-of-line ctor), then an array of eight B
// members, a member call with 15, and a second member call.
struct BaseComponentA
{
    BaseComponentA();
    virtual void unk00();
    ~BaseComponentA();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct BaseComponentB
{
    BaseComponentB();
    virtual void unk00();
    int unk04;
};

struct BaseComponentC
{
    BaseComponentC();
    virtual void unk00();
    ~BaseComponentC();
    __int64 unk08;
};

struct FUN_00617da0 : public BaseComponentA, public BaseComponentB, public BaseComponentC
{
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    BaseComponentB unk40[4];
    FUN_00617da0();
};

// Initializes the object by calling unk60 with 15 and then unk64.
// @fnv 0x00617da0
FUN_00617da0::FUN_00617da0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(15);
    reinterpret_cast<::TESSkill *>(this)->FUN_00617e80();
}

struct FUN_00617f40_Primary
{
    virtual ~FUN_00617f40_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_00617f40_Base18
{
    virtual void unk00();
    unsigned int unk04;
};

struct FUN_00617f40_Base20
{
    virtual ~FUN_00617f40_Base20();
    unsigned int unk04;
};

struct FUN_00617f40 : FUN_00617f40_Primary, FUN_00617f40_Base18, FUN_00617f40_Base20
{
    virtual ~FUN_00617f40();
};

// @fnv 0x00617f40
FUN_00617f40::~FUN_00617f40()
{}

struct NamePart
{
};
struct Setting
{
    const char* FUN_00403df0();
};
struct Player
{
};
struct Reputation
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
    virtual void Mark(int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NamePart name;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    float positive;
    float negative;
    int sound;
    void FUN_00615a00(int kind, float amount);
};
// @fnv 0x00615a00
void Reputation::FUN_00615a00(int kind, float amount)
{
    bool changed = false;
    char oldRank = 0;
    char newRank = 0;
    char message3[250];
    oldRank = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(kind)));
    if (kind == 1)
    {
        positive -= amount;
        positive = positive < 0.0 ? 0.0f : positive;
        ::FUN_00406d00(message3, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(name))->FUN_00408da0())), (*reinterpret_cast<::Setting *>(&::g_011cbb98)).FUN_00403df0());
        newRank = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(1)));
        if (newRank != oldRank)
        {
            sound = 0;
            changed = true;
        }
        ::DispatchMessageToSink((const char *)(message3), 0, (const char *)((*reinterpret_cast<::Setting *>(&::g_011cbc34)).FUN_00403df0()), (const char *)(0), 2.0f, false);
    }
    else
    {
        negative -= amount;
        negative = negative < 0.0 ? 0.0f : negative;
        ::FUN_00406d00(message3, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(name))->FUN_00408da0())), (*reinterpret_cast<::Setting *>(&::g_011cba94)).FUN_00403df0());
        newRank = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(0)));
        if (newRank != oldRank)
        {
            sound = 1;
            changed = true;
        }
        ::DispatchMessageToSink((const char *)(message3), 0, (const char *)((*reinterpret_cast<::Setting *>(&::g_011cba00)).FUN_00403df0()), (const char *)(0), 2.0f, false);
    }
    if (changed && !((bool)(reinterpret_cast<::FUN_00953c50_Class *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_00953c50((char *)(bool *)(0)))) && !::fnv_007050d0::FUN_007050d0())
        reinterpret_cast<::FUN_006155f0_shell *>(this)->ShowMessageBox();
    else if (changed)
        reinterpret_cast<::FUN_006159e0_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->SetValue(reinterpret_cast<TESReputation*>(this));
    Mark(2);
}

struct ReputationSetting
{
    const char* FUN_00403df0();
};
struct ReputationPlayer
{
};
struct ReputationFullName : TESFullName
{
};
struct ReputationUpdate : TESForm, ReputationFullName, TESIcon, BGSMessageIcon
{
    ReputationLimitData data;
    float m_fFirstReputationValue;
    float m_fSecondReputationValue;
    ReputationType m_eReputationType;
    void ApplyReputationChange(int type, int amount);
};
// @fnv 0x00615c90
void ReputationUpdate::ApplyReputationChange(int iReputationType, int amount)
{
    if (amount <= 0 || amount >= 6)
        return;
    bool p = false;
    char j = 0;
    char c = 0;
    ReputationSetting* e[5] = {&(*reinterpret_cast<::ReputationSetting *>(&::g_011cbc88)), &(*reinterpret_cast<::ReputationSetting *>(&::originalRuntimeFloatSetting52)), &(*reinterpret_cast<::ReputationSetting *>(&::originalRuntimeFloatSetting53)), &(*reinterpret_cast<::ReputationSetting *>(&::originalRuntimeFloatSetting54)), &(*reinterpret_cast<::ReputationSetting *>(&::originalRuntimeFloatSetting55))};
    char l[250];
    j = ((ReputationTracker*)this)->GetReputationRank(iReputationType);
    if (iReputationType == 1)
    {
        m_fFirstReputationValue += *((float *)&(::FUN_00403e20((float *)(e[amount - 1]))));
        m_fFirstReputationValue =
            m_fFirstReputationValue > data.m_fMaximumReputation ? data.m_fMaximumReputation : m_fFirstReputationValue;
        ::FUN_00406d00(l, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(this)->FUN_00408da0())), (*reinterpret_cast<::ReputationSetting *>(&::g_011cbac0)).FUN_00403df0());
        c = ((ReputationTracker*)this)->GetReputationRank(1);
        if (c != j)
        {
            m_eReputationType = ReputationType_REPUTATION_POSITIVE;
            p = true;
        }
        ::DispatchMessageToSink((const char *)(l), 0, (const char *)((*reinterpret_cast<::ReputationSetting *>(&::g_011cbd5c)).FUN_00403df0()), (const char *)(0), 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue += *((float *)&(::FUN_00403e20((float *)(e[amount - 1]))));
        m_fSecondReputationValue =
            m_fSecondReputationValue > data.m_fMaximumReputation ? data.m_fMaximumReputation : m_fSecondReputationValue;
        ::FUN_00406d00(l, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(this)->FUN_00408da0())), (*reinterpret_cast<::ReputationSetting *>(&::g_011cba58)).FUN_00403df0());
        c = ((ReputationTracker*)this)->GetReputationRank(0);
        if (c != j)
        {
            m_eReputationType = ReputationType_REPUTATION_NEGATIVE;
            p = true;
        }
        ::DispatchMessageToSink((const char *)(l), 0, (const char *)((*reinterpret_cast<::ReputationSetting *>(&::g_011cbad0)).FUN_00403df0()), (const char *)(0), 2.0f, false);
    }
    if (p && !((bool)(reinterpret_cast<::FUN_00953c50_Class *>(((*reinterpret_cast<::ReputationPlayer * *>(&::_g_thePlayer))))->FUN_00953c50((char *)(bool *)(0)))) && !::fnv_007050d0::FUN_007050d0())
        ((FUN_006155f0_shell*)this)->ShowMessageBox();
    else if (p)
        reinterpret_cast<::FUN_006159e0_shell *>(((*reinterpret_cast<::ReputationPlayer * *>(&::_g_thePlayer))))->SetValue(reinterpret_cast<TESReputation*>(this));
    MarkAsModified(2);
}

namespace fnv_00615fa0 {
struct RepSetting
{
    const char* String();
};
struct RepName
{
};
struct RepPlayer
{
};
struct RepObject
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
    virtual void Update(int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RepName name;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    float positive;
    float negative;
    int sound;
    void FUN_00615fa0(int kind, int amount);
};
// @fnv 0x00615fa0
void RepObject::FUN_00615fa0(int kind, int amount)
{
    bool changed = false;
    char oldRank = 0;
    char newRank = 0;
    char message3[250];
    if (amount <= 0 || amount >= 6)
        return;
    RepSetting* settings3[5] = {&(*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::g_011cbc88)), &(*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::originalRuntimeFloatSetting52)), &(*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::originalRuntimeFloatSetting53)),
                                &(*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::originalRuntimeFloatSetting54)), &(*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::originalRuntimeFloatSetting55))};
    oldRank = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(kind)));
    if (kind == 1)
    {
        positive -= *((float *)&(::FUN_00403e20((float *)(settings3[amount - 1]))));
        positive = positive < 0.0 ? 0.0f : positive;
        ::FUN_00406d00(message3, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(name))->FUN_00408da0())), (*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::g_011cbb98)).String());
        newRank = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(1)));
        if (newRank != oldRank)
        {
            sound = 0;
            changed = true;
        }
        ::DispatchMessageToSink((const char *)(message3), 0, (const char *)((*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::g_011cbc34)).String()), (const char *)(0), 2.0f, false);
    }
    else
    {
        negative -= *((float *)&(::FUN_00403e20((float *)(settings3[amount - 1]))));
        negative = negative < 0.0 ? 0.0f : negative;
        ::FUN_00406d00(message3, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(name))->FUN_00408da0())), (*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::g_011cba94)).String());
        newRank = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(0)));
        if (newRank != oldRank)
        {
            sound = 1;
            changed = true;
        }
        ::DispatchMessageToSink((const char *)(message3), 0, (const char *)((*reinterpret_cast<::fnv_00615fa0::RepSetting *>(&::g_011cbad0)).String()), (const char *)(0), 2.0f, false);
    }
    if (changed && !((bool)(reinterpret_cast<::FUN_00953c50_Class *>(((*reinterpret_cast<::fnv_00615fa0::RepPlayer * *>(&::_g_thePlayer))))->FUN_00953c50((char *)(bool *)(0)))) && !::fnv_007050d0::FUN_007050d0())
        reinterpret_cast<::FUN_006155f0_shell *>(this)->ShowMessageBox();
    else if (changed)
        reinterpret_cast<::FUN_006159e0_shell *>(((*reinterpret_cast<::fnv_00615fa0::RepPlayer * *>(&::_g_thePlayer))))->SetValue(reinterpret_cast<TESReputation*>(this));
    Update(2);
}
}  // namespace fnv_00615fa0

struct SettingT_GameSettingCollection_
{
    const char* String();
};
class GlobalObject_0040c150 : public SettingT_GameSettingCollection_
{
public:
    const char *FUN_006167d0();
};
struct InterfaceManagerTutorialView
{
    char pad[0x4d4];
    ::TutorialMessageGate718 m_kTutorialGate;
};

// @fnv 0x006155f0
void FUN_006155f0_shell::ShowMessageBox(void)
{
    char buffer[0x200];

    ::FUN_00406d00(buffer, 0x200, "%s\n%s", reinterpret_cast<::TESReputation *>(this)->FUN_00616710(), reinterpret_cast<::B616890Menu *>(this)->GetSelectedSettingString());

    reinterpret_cast<InterfaceManagerTutorialView*>(::fnv_004b7210::FUN_004b7210())->m_kTutorialGate.FUN_00718630(0x27, 0, 0x1f4);

    if (mField_4c == 1)
    {
        ::FUN_00703f10((const char *)(buffer), (const char *)(reinterpret_cast<::GlobalObject_0040c150 *>(this)->FUN_006167d0()), (const char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(mFNStub))->FUN_00408da0()))),
                     (const char *)(reinterpret_cast<StartMenu*>(&(*reinterpret_cast<char *>(&::g_011cbcb0)))->GetMenuTitle()), (void *)(FUN_00615720), 1, 0x17, 0.0f, 0.0f,
                     (const char *)(reinterpret_cast<StartMenu*>(&(*reinterpret_cast<char *>(&::g_011d38b8)))->GetMenuTitle()), 0);
    }
    else
    {
        ::FUN_00703f10((const char *)(buffer), (const char *)(reinterpret_cast<::GlobalObject_0040c150 *>(this)->FUN_006167d0()), (const char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(mFNStub))->FUN_00408da0()))),
                     (const char *)(reinterpret_cast<StartMenu*>(&(*reinterpret_cast<char *>(&::g_011cba30)))->GetMenuTitle()), (void *)(FUN_00615720), 1, 0x17, 0.0f, 0.0f,
                     (const char *)(reinterpret_cast<StartMenu*>(&(*reinterpret_cast<char *>(&::g_011d38b8)))->GetMenuTitle()), 0);
    }
}
struct TESSoundFile
{
};
struct Interface
{
};
class PlayerCharacter
{
};

struct Host615730
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
    virtual void v18(int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float m_fMaximumReputation;
    float m_fFirstReputationValue;
    float m_fSecondReputationValue;
    int m_eReputationType;
    void FUN_00615730(int kind, float delta);
};

// @fnv 0x00615730
void Host615730::FUN_00615730(int kind, float delta)
{
    signed char val;
    bool changed;
    char i[250];
    signed char after;
    changed = false;
    val = 0;
    after = 0;
    val = (char)((ReputationTracker*)this)->GetReputationRank(kind);
    if (kind == 1)
    {
        m_fFirstReputationValue += delta;
        m_fFirstReputationValue = (m_fFirstReputationValue > m_fMaximumReputation) ? (float)m_fMaximumReputation
                                                                                   : (float)m_fFirstReputationValue;
        ::FUN_00406d00(i, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((TESSoundFile*)&this->unk18)))->FUN_00408da0())), g_011cbac0.String());
        after = (char)((ReputationTracker*)this)->GetReputationRank(1);
        if (after != val)
        {
            m_eReputationType = 1;
            changed = true;
        }
        ::DispatchMessageToSink((const char *)(i), 0, (const char *)(g_011cbd5c.String()), (const char *)(0), 2.0f, false);
    }
    else
    {
        m_fSecondReputationValue += delta;
        m_fSecondReputationValue = (m_fSecondReputationValue > m_fMaximumReputation) ? (float)m_fMaximumReputation
                                                                                     : (float)m_fSecondReputationValue;
        ::FUN_00406d00(i, 250, "%s\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((TESSoundFile*)&this->unk18)))->FUN_00408da0())), g_011cba58.String());
        after = (char)((ReputationTracker*)this)->GetReputationRank(0);
        if (after != val)
        {
            changed = true;
            m_eReputationType = 0;
        }
        ::DispatchMessageToSink((const char *)(i), 0, (const char *)(g_011cbad0.String()), (const char *)(0), 2.0f, false);
    }
    if (changed && !((bool)(reinterpret_cast<::FUN_00953c50_Class *>((::_g_thePlayer))->FUN_00953c50((char *)(bool *)(0)))) && !::fnv_007050d0::FUN_007050d0())
    {
        ((FUN_006155f0_shell*)this)->ShowMessageBox();
    }
    else if (changed)
    {
        ((FUN_006159e0_shell*)::_g_thePlayer)->SetValue(reinterpret_cast<TESReputation*>(this));
    }
    v18(2);
}


struct ReputationCompareEntry : TESReputation
{
    bool FUN_00616570(TESForm* other);
};

// @fnv 0x00616570
bool ReputationCompareEntry::FUN_00616570(TESForm* other)
{
    TESReputation* pOtherReputation = dynamic_cast<TESReputation*>(other);
    if (!pOtherReputation)
        return true;
    if (std::memcmp(&data, ((::ReputationLimitData *)(reinterpret_cast<::PackedByteIntRecord *>((static_cast<ReputationCompareEntry*>(pOtherReputation)))->Endian())),
                sizeof(ReputationLimitData)) != 0)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pOtherReputation))
        return true;
    return false;
}


struct ReputationComponentCopy
{
};

struct ReputationCopyReceiver : TESReputation
{
    void FUN_00616500(TESForm* source);
};

// Copies the two reputation values and the data block from source (cast to TESReputation) into this object, then calls FUN_004851b0 with source.
// @fnv 0x00616500
void ReputationCopyReceiver::FUN_00616500(TESForm* source)
{
    TESReputation* reputation = dynamic_cast<TESReputation*>(source);
    if (!reputation)
        return;

    m_fSecondReputationValue = reputation->m_fSecondReputationValue;
    m_fFirstReputationValue = reputation->m_fFirstReputationValue;
    ::__memcpy(&data, &reputation->data, sizeof(data));
    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<ReputationComponentCopy*>(this)))->FUN_004851b0(source);
}

#include "generated/data/tesreputation.inc"
