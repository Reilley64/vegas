// fallout_shared/tesclass.cpp: TESClass, ActorValue, ClassComparison (15 functions)

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00480130_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tesclass_decls.h"
// Stores skill into data.skills[index] and marks the class modified when skill is a skill or None.
// @fnv 0x005f6e80
void TESClass::SetClassSkillAtIndex(int index, ActorValue::Index skill)
{
    if (::FUN_0047f060((*(int *)&(skill))) || skill == ActorValue::None)
    {
        data.skills[index] = skill;
        MarkAsModified(2);
    }
}
// Clears the 28-byte data block and sets all four actor value slots to ActorValue::None.
// @fnv 0x005f67c0
void TESClass::ResetFormData()
{
    memset(&data, 0, 28);
    for (int i = 0; i < 4; ++i)
        SetClassSkillAtIndex(i, ActorValue::None);
}
// Loads the base form data, then reads four skill values from the buffer when change flag 2 is set.
// @fnv 0x005f71c0
void TESClass::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(2)))->FUN_004280f0())
    {
        for (unsigned int i = 0; i < 4; ++i)
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&data.skills[i]), 4);
    }
}
struct FUN_005f6e20_shell : public TESClass
{
    bool ValidateSkillActorValue();
};

struct TESClass_Helper
{
    ActorValue::Index FUN_005f6dd0();
};

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<4>);
void __cdecl BSEndian(int*, EndianSizeTag<3>);
void __cdecl BSEndian(float*, EndianSizeTag<3>);

struct FUN_005f68d0_shell
{
    void SwapEndian();
};
// Reads a TESClass record from the file, handling EDID, OBND, FULL, DESC, ICON, DATA and ATTR chunks, then warns if the class data is invalid.
// @fnv 0x005f6930
bool TESClass::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((((TESFileFormInt*)file)))->FUN_00472660() != 7)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x41544144:
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == reinterpret_cast<::FUN_00486620_shell *>(this)->FUN_00486620() + 28)
            {
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file, &data, 28);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_005f68d0_shell *>(&(data))->SwapEndian();
            }
            else if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 24 || reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == reinterpret_cast<::FUN_00486620_shell *>(this)->FUN_00486620() + 24)
            {
                LegacyActorBaseData oldData;
                if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == reinterpret_cast<::FUN_00486620_shell *>(this)->FUN_00486620() + 24)
                    reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file, &oldData, 24);
                else
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&oldData), 24);
                if (file->IsEndianConversionRequired())
                    oldData.SwapEndianData();
                data.flags = oldData.flags;
                data.services = oldData.services;
                data.trainingLevel = oldData.trainingLevel;
                data.trainingSkill = oldData.trainingSkill;
                for (int i = 0; i < 3; ++i)
                    data.skills[i] = oldData.skills[i];
            }
            else
            {
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), 28);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_005f68d0_shell *>(&(data))->SwapEndian();
            }
            break;
        case 0x52545441: {
            unsigned char attributes[7];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(attributes), 7);
            reinterpret_cast<::FUN_00480130_shell *>(this)->FUN_00480130(attributes);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    if (!reinterpret_cast<::FUN_005f6e20_shell *>(this)->ValidateSkillActorValue())
        ::FUN_005b5e40();
    return true;
}

// Byte-swaps the four 3-byte values at the start of this object and the 4-byte value at offset 0x14.
// @fnv 0x005f68d0
void FUN_005f68d0_shell::SwapEndian()
{
    ::FUN_00401080((int*)(this + 0x14));
    for (int i = 0; i < 4; ++i)
        ::FUN_00401080((int*)this + i);
}

namespace fnv_005f6c90 {
template <int N> class EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<3>);

struct FUN_005f6c90_shell
{
    int m_data[4];
    void SwapEndianData();
};

// @fnv 0x005f6c90
void FUN_005f6c90_shell::SwapEndianData()
{
    ::FUN_00401080(&m_data[4]);
    for (int i = 0; i < 3; ++i)
    {
        ::FUN_00401080(&m_data[i]);
    }
}
}  // namespace fnv_005f6c90

struct FUN_005f6dd0_shell
{
    int FUN_005f6dd0();
};

// @fnv 0x005f6dd0
int FUN_005f6dd0_shell::FUN_005f6dd0()
{
    int result = *(unsigned char*)((char*)this + 0x5c) + 0x20;
    return result;
}

struct FUN_005f6df0_shell
{
    void SetSkillIndex(ActorValue::Index index);
};
// @fnv 0x005f6e20
bool FUN_005f6e20_shell::ValidateSkillActorValue()
{
    bool bIsSkill = true;
    if (!::FUN_0047f060((*(int *)&(const ::ActorValue::Index &)(((TESClass_Helper*)this)->FUN_005f6dd0()))))
    {
        reinterpret_cast<::FUN_005f6df0_shell *>((((TESClass_Helper*)this)))->SetSkillIndex((::ActorValue::Index)(0x20));
        bIsSkill = false;
    }
    return bIsSkill;
}

// If index is a skill, stores index minus 0x20 into the byte at offset 0x5c of this object.
// @fnv 0x005f6df0
void FUN_005f6df0_shell::SetSkillIndex(ActorValue::Index aeSkillIndex)
{
    if (::FUN_0047f060((*(int *)&(aeSkillIndex))))
    {
        ((unsigned char*)this)[0x5c] = (unsigned char)(aeSkillIndex - 0x20);
    }
}

struct BGSSaveFormBuffer
{
};

struct FUN_00484d60_holder
{
};

struct FUN_005f7150_shell
{
    void SaveForm(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x005f7150
void FUN_005f7150_shell::SaveForm(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int i;
    reinterpret_cast<::FakeForm *>((((FUN_00484d60_holder*)this)))->SaveIfChanged((::BGSSaveFormBuffer *)((unsigned int)apSaveGameBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(((BGSLoadFormBuffer*)apSaveGameBuffer)->GetChangeFlags(2)))->FUN_004280f0())
    {
        for (i = 0; i < 4; ++i)
        {
            reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x44 + i * 4), 4, 0);
        }
    }
}

extern "C"
{
}

struct FUN_004855a0
{
};
struct S_00487010
{
};
struct FUN_00482cb0_shell
{
    void FUN_00482cb0(void);
};
struct FUN_00480100_shell
{
    unsigned int FUN_00480100(void*);
};
struct FUN_00485680
{
};

struct FUN_0048e370_obj
{
};

struct FUN_005f6810_shell
{
    void FUN_005f6810(void);
};

// @fnv 0x005f6810
void FUN_005f6810_shell::FUN_005f6810(void)
{
    char cAttribData[7];
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x18)))->FUN_00487010();
    reinterpret_cast<FUN_00482cb0_shell*>(reinterpret_cast<char*>(this) + 0x24)->FUN_00482cb0();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x2c)))->FUN_0048e370(0x4e4f4349);
    if (::FUN_00401500())
    {
        reinterpret_cast<::FUN_005f68d0_shell *>((reinterpret_cast<TESClassData*>(reinterpret_cast<char*>(this) + 0x44)))->SwapEndian();
    }
    ::AppendChunk(0x41544144, reinterpret_cast<char*>(this) + 0x44, 0x1c);
    if (::FUN_00401500())
    {
        reinterpret_cast<::FUN_005f68d0_shell *>((reinterpret_cast<TESClassData*>(reinterpret_cast<char*>(this) + 0x44)))->SwapEndian();
    }
    reinterpret_cast<FUN_00480100_shell*>(reinterpret_cast<char*>(this) + 0x38)->FUN_00480100(cAttribData);
    ::FUN_004856f0((void *)(0x52545441), cAttribData, (void *)(7));
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct S_005f66e0
{
    void FUN_005f6710();
    void* DestroyIfFlagged(unsigned int);
};
struct ShellH;
struct XActor
{
};
struct FUN_005e78f0_t
{
    void CopyFromTESClass(TESForm* apCopy);
};
// @fnv 0x005f6d70
void FUN_005e78f0_t::CopyFromTESClass(TESForm* apCopy)
{
    TESClass* cl = dynamic_cast<TESClass*>(apCopy);
    if (!cl)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apCopy);
    __memcpy((void*)((char*)this + 0x44), ((::ShellH *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(((XActor*)cl)))->FUN_005d43c0())), 0x1c);
}

struct FUN_005f6710_Primary
{
    virtual ~FUN_005f6710_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_005f6710_Base18
{
    virtual ~FUN_005f6710_Base18();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_005f6710_Base24
{
    virtual void unk00();
    unsigned int unk04;
};

struct FUN_005f6710_Base2c
{
    virtual ~FUN_005f6710_Base2c();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_005f6710_Base38
{
    virtual ~FUN_005f6710_Base38();
    unsigned int unk04;
};

struct FUN_005f6710 : FUN_005f6710_Primary,
                      FUN_005f6710_Base18,
                      FUN_005f6710_Base24,
                      FUN_005f6710_Base2c,
                      FUN_005f6710_Base38
{
    virtual ~FUN_005f6710();
};
// Calls FUN_005f6710, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x005f66e0
void* S_005f66e0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_005f6710 *>(this)->FUN_005f6710::~FUN_005f6710();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for FUN_005f6710; it has an empty body and only tears down the base subobjects.
// @fnv 0x005f6710
FUN_005f6710::~FUN_005f6710()
{}


class ClassDataAccess : public TESClass
{
  public:
};

class ClassComparison : public TESClass
{
  public:
    bool FUN_005f6cf0(TESForm* other);
};

// Returns true if the cast fails, FUN_00485270 returns true, or the two TESClassData byte ranges differ.
// @fnv 0x005f6cf0
bool ClassComparison::FUN_005f6cf0(TESForm* other)
{
    TESClass* pClass = dynamic_cast<TESClass*>(other);
    if (!pClass)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pClass))
        return true;
    if (std::memcmp(&data, ((::TESClassData *)(reinterpret_cast<::FUN_005d43c0_ *>((static_cast<ClassDataAccess*>(pClass)))->FUN_005d43c0())), sizeof(TESClassData)))
        return true;
    return false;
}


