// fallout_shared/tescombatstyle.cpp: TESCombatStyle (10 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005050b0.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00505000.h"
#include "tescombatstyle_decls.h"
// @fnv 0x00505010
TESCombatStyle::TESCombatStyle()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x4a)));
    ResetFormData();
}
// Copies 0x5c, 0x54 and 0x40 bytes from the combat style returned by FUN_00505000 into Data and two other members, or zeroes them if none.
// @fnv 0x005050d0
void TESCombatStyle::ResetFormData()
{
    TESCombatStyle* style = ((::TESCombatStyle *)(::FUN_00505000()));
    if (style)
    {
        memcpy(&Data, &((NiAVObject*)style)->FUN_0043c490(), 0x5c);
        memcpy(&m_kUInt32ChunkData, ((::UInt32ChunkData *)(reinterpret_cast<::BSMultiBoundRoom *>((((CombatStyleAccess*)style)))->FUN_006ab360())), 0x54);
        memcpy(&m_kUnsignedIntArray16, ((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((((BGSHungerStage*)style)))->GetConditions())), 0x40);
    }
    else
    {
        memset(&Data, 0, 0x5c);
        memset(&m_kUInt32ChunkData, 0, 0x54);
        memset(&m_kUnsignedIntArray16, 0, 0x40);
    }
}
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

class TESForm;
class TESCombatStyle;

struct FUN_00505550_shell
{
    bool IsCombatStyleDifferent(TESForm* apCompare);
};

// @fnv 0x00505550
bool FUN_00505550_shell::IsCombatStyleDifferent(TESForm* apCompare)
{
    TESCombatStyle* pcomp = dynamic_cast<TESCombatStyle*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(pcomp)))
        return true;
    if (memcmp(&((NiAVObject*)this)->FUN_0043c490(), &((NiAVObject*)pcomp)->FUN_0043c490(), 0x5c))
        return true;
    if (memcmp(((::UInt32ChunkData *)(reinterpret_cast<::BSMultiBoundRoom *>((((CombatStyleAccess*)this)))->FUN_006ab360())), ((::UInt32ChunkData *)(reinterpret_cast<::BSMultiBoundRoom *>((((CombatStyleAccess*)pcomp)))->FUN_006ab360())), 0x54))
        return true;
    if (memcmp(((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((((BGSHungerStage*)this)))->GetConditions())), ((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((((BGSHungerStage*)pcomp)))->GetConditions())), 0x40))
        return true;
    return false;
}

struct FUN_00505080_shell
{
    void* FUN_00505080(unsigned int);
};
// Calls FUN_005050b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00505080
void* FUN_00505080_shell::FUN_00505080(unsigned int flags)
{
    reinterpret_cast<::FUN_005050b0 *>(this)->FUN_005050b0::~FUN_005050b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00485680_shell
{
};

struct FUN_004855a0_shell
{
};

struct FUN_005053c0_shell : FUN_004855a0_shell
{
    void FUN_005053c0();
};


struct FUN_005054b0_shell : public NiAVObject
{
    void CopyFromCombatStyle(TESForm* apCopy);
};

// Casts apCopy to TESCombatStyle, calls FUN_004851b0, then memcpy's three sub-objects (0x5c, 0x54, 0x40 bytes) from the copy into this.
// @fnv 0x005054b0
void FUN_005054b0_shell::CopyFromCombatStyle(TESForm* apCopy)
{
    TESForm* pcopy = dynamic_cast<TESForm*>(dynamic_cast<TESCombatStyle*>(apCopy));
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pcopy);
    ::__memcpy(&FUN_0043c490(), &reinterpret_cast<NiAVObject*>(pcopy)->FUN_0043c490(), 0x5c);
    ::__memcpy(((::UInt32ChunkData *)(reinterpret_cast<::BSMultiBoundRoom *>((reinterpret_cast<CombatStyleAccess*>(this)))->FUN_006ab360())),
             ((::UInt32ChunkData *)(reinterpret_cast<::BSMultiBoundRoom *>((reinterpret_cast<CombatStyleAccess*>(pcopy)))->FUN_006ab360())), 0x54);
    ::__memcpy(((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<BGSHungerStage*>(this)))->GetConditions())),
             ((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<BGSHungerStage*>(pcopy)))->GetConditions())), 0x40);
}

template <int N> struct EndianSizeTag
{
};

typedef EndianSizeTag<0> BSIntToType0;


struct FUN_005057a0_shell
{
    void FUN_005057a0();
};
// Reads a combat style record from the file, loading its editor ID, OBND, and CSDT/CSAD/CSSD chunks, then applies version-dependent defaults.
// @fnv 0x00505180
bool TESCombatStyle::Load(TESFile* file)
{
    unsigned char type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (type != 0x4a)
        return false;
    ClearData();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0x200);
            SetEditorID_AtRuntime(name);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x44545343:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), 0x5c);
            if (reinterpret_cast<::TESFile *>((((TESFileExtra*)file)))->IsEndianConversionRequired())
                Data.SwapEndianFields();
            break;
        case 0x44415343:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kUInt32ChunkData), 0x54);
            if (reinterpret_cast<::TESFile *>((((TESFileExtra*)file)))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_005057a0_shell *>(&(m_kUInt32ChunkData))->FUN_005057a0();
            break;
        case 0x44535343:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kUnsignedIntArray16), 0x40);
            if (reinterpret_cast<::TESFile *>((((TESFileExtra*)file)))->IsEndianConversionRequired())
            {
                UnsignedIntArray16 saved;
                unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
                if (size < 0x40)
                    memcpy(&saved, &m_kUnsignedIntArray16, 0x40);
                m_kUnsignedIntArray16.FUN_00505610();
                if (size < 0x40)
                    memcpy((char*)&m_kUnsignedIntArray16 + size, (char*)&saved + size, 0x40 - size);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 12)
    {
        ((float*)&m_kUnsignedIntArray16)[8] = 1.0f;
        ((float*)&m_kUnsignedIntArray16)[11] = 1.0f;
    }
    return true;
}
// @fnv 0x005053c0
void __thiscall FUN_005053c0_shell::FUN_005053c0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    if (((bool)(::FUN_00401500())))
        ((StatsChunkData*)((char*)this + 0x58))->SwapEndianFields();
    ::AppendChunk(0x44545343, (char*)this + 0x58, 0x5c);
    if (((bool)(::FUN_00401500())))
        ((StatsChunkData*)((char*)this + 0x58))->SwapEndianFields();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005057a0_shell *>((((UInt32ChunkData*)((char*)this + 0xb4))))->FUN_005057a0();
    ::AppendChunk(0x44415343, (char*)this + 0xb4, 0x54);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005057a0_shell *>((((UInt32ChunkData*)((char*)this + 0xb4))))->FUN_005057a0();
    if (((bool)(::FUN_00401500())))
        ((UnsignedIntArray16*)((char*)this + 0x18))->FUN_00505610();
    ::AppendChunk(0x44535343, (char*)this + 0x18, 0x40);
    if (((bool)(::FUN_00401500())))
        ((UnsignedIntArray16*)((char*)this + 0x18))->FUN_00505610();
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

// @fnv 0x005057a0
void FUN_005057a0_shell::FUN_005057a0()
{
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x00));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x04));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x08));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x0C));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x10));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x14));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x18));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x1C));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x20));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x24));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x28));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x2C));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x30));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x34));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x38));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x3C));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x40));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x48));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x44));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x4C));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 0x50));
}

namespace fnv_005059c0 {
template <int N> struct EndianSizeTag
{
    unsigned char value;
};


struct FUN_005059c0_shell
{
    void* vptr;

    void SwapEndianFields();
};

// @fnv 0x005059c0
void FUN_005059c0_shell::SwapEndianFields()
{
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x04));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x08));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x0c));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x10));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x14));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x18));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x1c));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x20));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x28));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x2c));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x30));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x38));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x3c));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x48));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x4c));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x58));
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this) + 0x50));
}
}  // namespace fnv_005059c0


// Byte-swaps each of the 15 data words in place via BSEndianUInt.
// @fnv 0x00505610
void UnsignedIntArray16::FUN_00505610()
{
    ::FUN_00401080((int *)(unsigned int *)(&data[0]));
    ::FUN_00401080((int *)(unsigned int *)(&data[1]));
    ::FUN_00401080((int *)(unsigned int *)(&data[2]));
    ::FUN_00401080((int *)(unsigned int *)(&data[3]));
    ::FUN_00401080((int *)(unsigned int *)(&data[4]));
    ::FUN_00401080((int *)(unsigned int *)(&data[5]));
    ::FUN_00401080((int *)(unsigned int *)(&data[6]));
    ::FUN_00401080((int *)(unsigned int *)(&data[7]));
    ::FUN_00401080((int *)(unsigned int *)(&data[8]));
    ::FUN_00401080((int *)(unsigned int *)(&data[11]));
    ::FUN_00401080((int *)(unsigned int *)(&data[9]));
    ::FUN_00401080((int *)(unsigned int *)(&data[12]));
    ::FUN_00401080((int *)(unsigned int *)(&data[13]));
    ::FUN_00401080((int *)(unsigned int *)(&data[14]));
    ::FUN_00401080((int *)(unsigned int *)(&data[15]));
}
