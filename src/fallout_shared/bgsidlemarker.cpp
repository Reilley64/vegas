// fallout_shared/bgsidlemarker.cpp: BGSIdleMarker, FakeMarker, BGSIdleMarkerImpl, IdleMarkerComparison (9 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0067ffa0_cls.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0067ff10__FUN_0067ff10_Class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_005e9000.h"
#include "bgsidlemarker_decls.h"

// Calls FUN_005e9530, installs the BGSQuestPerkEntry_vtbl vtable pointer, and zeroes the fields at offsets 8 and 12.
// @fnv 0x005e9800
BGSIdleMarker::BGSIdleMarker()
{
    ::FUN_005e9530((::FUN_005e9530_Obj *)this);
    *reinterpret_cast<std::uintptr_t*>(this) = reinterpret_cast<std::uintptr_t>(&BGSQuestPerkEntry_vtbl);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 8) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 12) = 0;
}

// If the form is not yet initialized, initializes the BGSIdleCollection at offset 0x30 and marks the form as initialized.
// @fnv 0x005e7bb0
void BGSIdleMarker::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(reinterpret_cast<TESFormInitFlag*>(this)))->GetInitialized())
    {
    }
    else
    {
        reinterpret_cast<BGSIdleCollection*>(reinterpret_cast<char*>(this) + 0x30)
            ->InitItem(reinterpret_cast<TESForm*>(this));
        reinterpret_cast<TESForm*>(this)->SetInitializationState(true);
    }
}

struct TESBoundObject
{
    TESBoundObject();
    ~TESBoundObject();
    virtual void vfn_0();
    char pad[0x2c];
};
struct FUN_00479790
{
    FUN_00479790();
    ~FUN_00479790();
    virtual void vfn_1();
    int pad2[2];
};
struct SoundPlaybackHandle
{
};
struct FUN_005e7a90 : public TESBoundObject, public FUN_00479790
{
    FUN_005e7a90();
};
// Constructs the object and sets its form type to 0x30.
// @fnv 0x005e7a90
FUN_005e7a90::FUN_005e7a90()
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((SoundPlaybackHandle*)this)))->FUN_004f15a0(0x30);
}

struct FakeMarker
{
    void FUN_005e7b40();
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_004799f0_shell
{
    void FUN_004799f0();
};
struct FUN_005e7ed0_shell
{
    void FUN_005e7ed0();
};
// @fnv 0x005e7ed0
void FUN_005e7ed0_shell::FUN_005e7ed0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    ((FUN_004799f0_shell*)((char*)this + 0x30))->FUN_004799f0();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e78f0_t
{
};
struct FUN_005e7f00_t
{
    void CopyFrom(TESForm* apCopy);
};
// Casts apCopy to BGSIdleMarker and, if the cast succeeds, forwards it to FUN_004851b0 on this object.
// @fnv 0x005e7f00
void FUN_005e7f00_t::CopyFrom(TESForm* apCopy)
{
    BGSIdleMarker* pcopy = dynamic_cast<BGSIdleMarker*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0((TESForm*)pcopy);
}

struct FUN_005e7b40 : public TESBoundObject, public FUN_00479790
{
    ~FUN_005e7b40();
};
// @fnv 0x005e7b10
void* FakeMarker::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_005e7b40 *>(this)->FUN_005e7b40::~FUN_005e7b40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Empty destructor for a TESBoundObject-derived type; performs no work.
// @fnv 0x005e7b40
FUN_005e7b40::~FUN_005e7b40()
{}


struct IdlePayloadWrapper : public ChunkPayloadWrapper16
{
    IdlePayloadWrapper(ChunkPayload16* payload);
    ~IdlePayloadWrapper() throw();
};

struct BGSIdleMarkerImpl : public TESForm
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned char unk34;
    unsigned char unk35;
    unsigned short unk36;
    TESIdleForm** unk38;
    unsigned int unk3c;

    bool FUN_005e7bf0(TESFile* file);
};

// Reads record chunks from the file, updates fields for handled chunks, and constructs a wrapper for the payload chunk.
// @fnv 0x005e7bf0
bool BGSIdleMarkerImpl::FUN_005e7bf0(TESFile* file)
{
    reinterpret_cast<::S00485110 *>((this))->CallWithThis((::T00485110 *)(file));
    this->SetInitializationState(false);
    while (int chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunkID)
        {
        case 0x44494445: {  // 'EDID'
            char* pEditorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEditorID), 0x200);
            this->SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F: {  // 'OBND'
            this->readOBNDSubRecord(file);
            break;
        }
        case 0x464C4449: {  // 'IDLF'
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&this->unk34), 1);
            break;
        }
        case 0x434C4449: {  // 'IDLC'
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 1)
            {
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&this->unk35), 1);
            }
            else
            {
                unsigned int val = 0;
                file->GetChunkData(&val);
                this->unk35 = (unsigned char)val;
            }
            if (this->unk35 != 0)
            {
                if (this->unk38 != 0)
                {
                    delete[] this->unk38;
                }
                this->unk38 = new TESIdleForm*[this->unk35];
                memset(this->unk38, 0, this->unk35 * sizeof(TESIdleForm*));
            }
            break;
        }
        case 0x414C4449: {  // 'IDLA'
            if (this->unk38 != 0)
            {
                unsigned int size = this->unk35 * sizeof(TESIdleForm*);
                if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == size)
                {
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(this->unk38), size);
                    if (file->IsEndianConversionRequired())
                    {
                        for (int i = 0; i < this->unk35; ++i)
                        {
                            ::FUN_00401080((int*)&this->unk38[i]);
                        }
                    }
                }
            }
            break;
        }
        case 0x544C4449: {  // 'IDLT'
            file->GetChunkData(&this->unk3c);
            goto def_label;
            goto def_label;
            goto def_label;
        }
        case 0x54445450: {  // 'PTDT'
            ChunkPayload16 payload;
            memset(&payload, 0, sizeof(payload));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&payload), sizeof(payload));
            if (file->IsEndianConversionRequired())
            {
                reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>(&(payload))->FUN_0067ff10();
            }
            IdlePayloadWrapper wrapper(&payload);
            break;
        }
        default:
        def_label:
            break;
        }
        if (!file->NextChunk())
        {
            break;
        }
    }

    return true;
}

class FormComponentComparison : public TESForm
{
  public:
};

class IdleMarkerComparison : public BGSIdleMarker
{
  public:
    bool FUN_005e7f40(TESForm* apCompare);
};

// Returns true if apCompare is not a BGSIdleMarker or if the base form component comparison against it succeeds.
// @fnv 0x005e7f40
bool IdleMarkerComparison::FUN_005e7f40(TESForm* apCompare)
{
    BGSIdleMarker* pIdleMarker = dynamic_cast<BGSIdleMarker*>(apCompare);
    if (!pIdleMarker)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FormComponentComparison*)this)))->FUN_00485270((TESForm*)pIdleMarker))
        return true;
    return false;
}
