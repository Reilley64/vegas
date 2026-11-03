// fallout_shared/bgsaddonnode.cpp: BGSAddonNode, BGSAddonNodeSoundHandleExtra (17 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00461930_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00512810_holder.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/NiFixedString.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c8000.h"
#include "bgsaddonnode_types_BGSAddonNode.h"
#include "bgsaddonnode_decls.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x004f8c50
void BGSAddonNode::ResetFormData()
{
    SoundAssetTmp = 0;
    memset(reinterpret_cast<char*>(&this->Data), 0, 4);
    uiFlags = 0;
}

// @fnv 0x004f8c90
void BGSAddonNode::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(reinterpret_cast<TESFormInitFlag*>(this)))->GetInitialized())
        return;

    TESModelTextureSwap::InitItem(this);
    if (SoundAssetTmp)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(SoundAssetTmp);
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        SoundAssetTmp = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!SoundAssetTmp)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}

// @fnv 0x004f8d50
bool BGSAddonNode::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x58)
        return false;

    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {

        switch (chunkID)
        {
        case 0x44494445:  // EDID
        {
            char* data = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(data), 0x200);
            SetEditorID_AtRuntime(data);
            break;
        }
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x44444f4d:  // MODD
        case 0x44534f4d:  // MOSD
        case 0x54444f4d:  // MODT
        {
            TESModel::LoadModelData(this ? static_cast<TESModel *>(this) : 0, file);
            break;
        }
        case 0x53444f4d:  // MODS
        {
            struct MODS_BUFFER
            {
                unsigned int size;
                char* data;
            } buffer;
            buffer.size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            buffer.data = static_cast<char*>(_alloca(buffer.size));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer.data), buffer.size);
            reinterpret_cast<::FUN_0048a7b0_shell *>((static_cast<TESModelTextureSwap *>(this)))->LoadTextureSwapList(buffer.data, buffer.size,
                                       reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570());
            break;
        }
        case 0x41544144:  // DATA
            file->GetChunkData(&iIndex);
            break;
        case 0x4d414e53:  // SNAM
        {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            SoundAssetTmp = reinterpret_cast<TESSound*>(formID);
            break;
        }
        case 0x4d414e44:  // DNAM
        {
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(reinterpret_cast<char*>(&this->Data)), 4);
            if (reinterpret_cast<::TESFile *>((reinterpret_cast<TESFileAccessor*>(file)))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00512810_holder *>((&this->Data))->FUN_00512810();
            if (reinterpret_cast<::BGSAddonNode *>(this)->IsMasterParticleSystem())
            {
                uiFlags = DAT_011c8054;
                ++DAT_011c8054;
            }
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x004f8b00
BGSAddonNode::BGSAddonNode() : iIndex(-1)
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_ADDN_ID)));
    ResetFormData();
}

class BSFadeNode
{
  public:
    int m_unk;
    BSFadeNode(const char* name);
};


// Allocates a BSFadeNode named "ASH" and stores it in DAT_011c8058.
// @fnv 0x004f92e0
void __cdecl FUN_004f92e0()
{
    DAT_011c8058 = new BSFadeNode("ASH");
}

namespace fnv_004f9230 {

// @fnv 0x004f9230
int FUN_004f9230()
{
    return (*reinterpret_cast<int *>(&::DAT_011c8058));
}
}  // namespace fnv_004f9230

struct Proxy_004f8b90
{
    void FUN_004f8bc0();
    void* FUN_004f8b90(unsigned int);
};
struct BGSAddonNodeSoundHandleExtra
{
    void* FUN_004f9240(unsigned int);
};
namespace fnv_004f9360 {
struct BSFadeNode
{
};
// Calls FUN_004b9900(1) on DAT_011c8058 if it is non-null, then sets DAT_011c8058 to null.
// @fnv 0x004f9360
void FUN_004f9360()
{
    BSFadeNode* pFadeNode;
    {
        BSFadeNode* inner = (*reinterpret_cast<::fnv_004f9360::BSFadeNode * *>(&::DAT_011c8058));
        pFadeNode = inner;
        pFadeNode ? ((int)(reinterpret_cast<::NiFixedString *>((pFadeNode))->FUN_004b9900(1))) : 0;
    }
    (*reinterpret_cast<::fnv_004f9360::BSFadeNode * *>(&::DAT_011c8058)) = 0;
}
}  // namespace fnv_004f9360

class TESSound;
struct EffectSetting
{
    TESSound* GetCastSound();
};
struct FUN_004fc940_cls
{
    char _pad[0x4C];
    EffectSetting* fld4C;
    void* GetCastSoundOrEffect();
};
// @fnv 0x004fc940
void* FUN_004fc940_cls::GetCastSoundOrEffect()
{
    if (fld4C == 0 || reinterpret_cast<::TESForm *>((void *)(((TESForm*)this)))->GetInitialized() == 0 || fld4C->GetCastSound() == 0)
        return fld4C;
    return fld4C->GetCastSound();
}

struct S_0048a520
{
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_004f8fe0_shell : public BGSAddonNode
{
    void FUN_004f8fe0();
};
// @fnv 0x004f8fe0
void FUN_004f8fe0_shell::FUN_004f8fe0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<S_0048a520*>(static_cast<TESModelTextureSwap *>(this))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ::FUN_00485910(0x41544144, iIndex);
    if (SoundAssetTmp)
    {
        unsigned int itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((SoundAssetTmp))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, itempint);
    }
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00512810_holder *>((&this->Data))->FUN_00512810();
    ::AppendChunk(0x4d414e44, reinterpret_cast<char*>(&this->Data), 4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00512810_holder *>((&this->Data))->FUN_00512810();
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}


struct FUN_004f9220_shell
{
    void* FUN_004f9220();
};

// @fnv 0x004f9220
void* FUN_004f9220_shell::FUN_004f9220()
{
    return &(*reinterpret_cast<void * *>(&::g_011c806c));
}

struct FUN_005e78f0_t
{
};
struct FUN_004f90a0_shell : BGSAddonNode
{
    void CopyFromAddonNode(TESForm* apCopy);
};
// @fnv 0x004f90a0
void FUN_004f90a0_shell::CopyFromAddonNode(TESForm* apCopy)
{
    BGSAddonNode* pcopy = dynamic_cast<BGSAddonNode*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
    this->iIndex = pcopy->iIndex;
    this->SoundAssetTmp = pcopy->SoundAssetTmp;
    memcpy((char*)&this->Data, (char*)&pcopy->Data, 4);
}

struct FUN_005e79a0_t
{
};

struct FUN_004f9110_shell : BGSAddonNode
{
    bool FUN_004f9110(TESForm* apCompare);
};

// @fnv 0x004f9110
bool FUN_004f9110_shell::FUN_004f9110(TESForm* apCompare)
{
    BGSAddonNode* pcomp;

    pcomp = dynamic_cast<BGSAddonNode*>(apCompare);
    if (!pcomp)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pcomp))
        return true;

    if (this->iIndex !=
        pcomp->iIndex)
        return true;

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x54) !=
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pcomp) + 0x54))
        return true;

    if (memcmp(reinterpret_cast<const void*>(reinterpret_cast<const char*>(&this->Data)),
               reinterpret_cast<const void*>(reinterpret_cast<const char*>(&pcomp->Data)), 4))
        return true;

    return false;
}

struct Base_4f9270
{
    virtual ~Base_4f9270();
    int unk04;
    int unk08;
};

struct Member_4f9270
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~Member_4f9270();
};

class FUN_004f9270_cls : public Base_4f9270
{
  public:
    Member_4f9270 m_0c;

    virtual ~FUN_004f9270_cls();
};
// Calls FUN_004f9270, deletes this with size 24 when bit 0 of flags is set, and returns this.
// @fnv 0x004f9240
void* BGSAddonNodeSoundHandleExtra::FUN_004f9240(unsigned int flags)
{
    reinterpret_cast<::FUN_004f9270_cls *>((this))->FUN_004f9270_cls::~FUN_004f9270_cls();
    if (flags & 1)
        ::FUN_00aa1460(this, 24);
    return this;
}

// Destructor that calls Reset on the m_0c member before the base destructor runs.
// @fnv 0x004f9270
FUN_004f9270_cls::~FUN_004f9270_cls()
{
    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(m_0c))->FUN_00ad88f0();
}

class TESDataHandler
{
  public:
};

class FUN_004f8bc0 : public TESBoundObject, public TESModelTextureSwap
{
  public:
    virtual ~FUN_004f8bc0();
};
// @fnv 0x004f8b90
void* Proxy_004f8b90::FUN_004f8b90(unsigned int flags)
{
    reinterpret_cast<::FUN_004f8bc0 *>(this)->FUN_004f8bc0::~FUN_004f8bc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that, when g_dataHandler is set, passes this object to TESDataHandler::RemoveAddonNode as a BGSAddonNode.
// @fnv 0x004f8bc0
FUN_004f8bc0::~FUN_004f8bc0()
{
    if ((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))
    {
        reinterpret_cast<::FUN_00461930_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->RemoveAddonNode(reinterpret_cast<BGSAddonNode*>(this));
    }
}

class NiFixedString;
class ExtraDataBase
{
  public:
    ExtraDataBase(const NiFixedString& kName);
    ~ExtraDataBase();
    virtual void Slot00();
    int m_iRefCount;
    const char* m_kName;
};
class GlobalObject_0041a250
{
  public:
    GlobalObject_0041a250();
    int m_00;
};
const NiFixedString& FUN_004f9230();
class FUN_004f91b0 : public ExtraDataBase
{
  public:
    FUN_004f91b0();
    virtual void Slot00();
    GlobalObject_0041a250 m_kData;
};
// Constructs an ExtraDataBase-derived object, passing the result of FUN_004f9230() to the base constructor.
// @fnv 0x004f91b0
FUN_004f91b0::FUN_004f91b0() : ExtraDataBase(FUN_004f9230())
{}

#include "generated/data/fallout_shared/bgsaddonnode.inc"
