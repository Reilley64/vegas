// fallout_shared/tesobjectstat.cpp: TESObjectSTAT, TESGlobal, Standin, StatCopy (9 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0046dce0_class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
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
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tesobjectstat_load.h"
#include "tesobjectstat_global.h"
#include "tesobjectstat_types_TESObjectSTAT.h"
#include <new>
#include "fnv/symbols_00472000.h"

// Initializes a TESGlobal: sets cType to 's', fValue to 0.0f, and the form type to 6.
// @fnv 0x005a6320
TESGlobal::TESGlobal()
{
    cType = 's';
    fValue = 0.0f;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)6)));
}

// Sets the form type to 0x20, initializes a byte field to 0xFF and a second field to 0.
// @fnv 0x0051b140
TESObjectSTAT::TESObjectSTAT()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x20)));
    m_cType = (char)0xFF;
    m_pSoundForm = 0;
}

// @fnv 0x0051b280
bool TESObjectSTAT::Load(TESFile* file)
{
    unsigned char ucFormType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    unsigned int uiChunkID;
    while ((uiChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch ((int)uiChunkID)
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
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            void* pChunkData;
            {
                unsigned int uiChunkSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
                pChunkData = _alloca(uiChunkSize);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkData), uiChunkSize);
                reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(pChunkData, uiChunkSize, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570());
            }
            break;
        }
        case 0x53555242: {
            unsigned int soundIndex = 0;
            file->GetChunkData(&soundIndex);
            m_cType = (char)(soundIndex > 10 ? 255 : soundIndex);
            break;
        }
        case 0x4d414e52: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            m_pSoundForm = (TESSound*)(std::uintptr_t)sound;
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct Standin
{
    void FUN_0051b200();
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_004855a0_shell
{
};
struct FUN_00485680_shell
{
};
struct S_0048a520_shell
{
};

struct FUN_0051b4b0_shell : public FUN_004855a0_shell
{
    void FUN_0051b4b0();
};

// @fnv 0x0051b4b0
void FUN_0051b4b0_shell::FUN_0051b4b0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520_shell*)((char*)this + 0x30))))->ProcessAndFreeData(0x4C444F4D, 0x54444F4D, 0x53444F4D);
    FUN_004858f0(0x53555242, *(unsigned char*)((char*)this + 0x50));
    if (*(unsigned int*)((char*)this + 0x54))
    {
        unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)(*(std::uintptr_t*)((char*)this + 0x54)))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4D414E52, id);
    }
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

struct FUN_005e79a0_t : ::TESObjectSTAT
{
    bool FUN_0051b650(TESForm* form);
};
// Casts form to TESObjectSTAT and returns true if it is null, passes FUN_00485270, or differs in the byte at 0x50 or the TESSound pointer at 0x54.
// @fnv 0x0051b650
bool FUN_005e79a0_t::FUN_0051b650(TESForm* form)
{
    TESObjectSTAT* other = dynamic_cast<TESObjectSTAT*>(form);
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(other))
        return true;
    if (this->m_cType != other->m_cType)
        return true;
    if (this->m_pSoundForm != other->m_pSoundForm)
        return true;
    return false;
}

class TESSound : public TESForm
{
  public:
    virtual ~TESSound()
    {}
};

extern char str_0102bbb0[];


struct TESObjectSTAT_shell : ::TESObjectSTAT
{
    void FUN_0051b530();
};

// @fnv 0x0051b530
void TESObjectSTAT_shell::FUN_0051b530()
{
    std::uintptr_t itempint;

    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;

    reinterpret_cast<::TESModelTextureSwap *>((reinterpret_cast<TESObjectSTAT_shell*>(reinterpret_cast<unsigned char*>(this) + 0x30)))->InitItem(this);

    itempint =
        reinterpret_cast<std::uintptr_t>(this->m_pSoundForm);

    if (itempint)
    {
        ::ResolveFormID((unsigned int *)&(itempint), GetFile(-1));

        (&this->m_pSoundForm)[0] =
            dynamic_cast<TESSound*>(::FUN_004839c0(itempint));

        if (!(&this->m_pSoundForm)[0])
        {
            ::FUN_005b5e40();
        }
    }

    SetInitializationState(true);
}

struct ObjectFormBase
{
    virtual ~ObjectFormBase();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
};
struct ModelTextureBase
{
    virtual ~ModelTextureBase();
};
struct FUN_0051b200 : ObjectFormBase, ModelTextureBase
{
    virtual ~FUN_0051b200();
};
// Calls FUN_0051b200, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0051b1d0
void* Standin::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0051b200 *>(this)->FUN_0051b200::~FUN_0051b200();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x0051b200
FUN_0051b200::~FUN_0051b200()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

struct FUN_005e78f0_t
{
};

struct StatCopy : public TESObjectSTAT
{
    void FUN_0051b5f0(TESForm* apCopy);
};

// @fnv 0x0051b5f0
void StatCopy::FUN_0051b5f0(TESForm* apCopy)
{
    TESObjectSTAT* pcopy = dynamic_cast<TESObjectSTAT*>(apCopy);
    if (!pcopy)
    {
        return;
    }
    this->m_pSoundForm = pcopy->m_pSoundForm;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
    this->m_cType = pcopy->m_cType;
}

struct Primary231
{
    virtual void* DestroyIfFlagged(unsigned int);
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
};

struct Secondary231
{
    virtual void* DestroyIfFlagged(unsigned int) = 0;
};

struct FUN_0051b6d0 : Primary231, Secondary231
{
// @fnv 0x0051b6d0
    FUN_0051b6d0();
    void* DestroyIfFlagged(unsigned int);
};

struct Complete231 : FUN_0051b6d0
{
};

void* Make231(void* storage)
{
    return new (storage) Complete231;
}
