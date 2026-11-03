// fallout_shared/bgsvoicetype.cpp: BGSVoiceType (6 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_01183000.h"
#include "bgsvoicetype_decls.h"
// Loads a BGSVoiceType record from a TESFile, handling EDID, OBND and DATA chunks, and returns false if the form type is not 0x5d.
// @fnv 0x005f01a0
bool BGSVoiceType::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660() != 0x5d)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    unsigned int chunk;
    char* buffer;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445:
            buffer = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 512);
            SetEditorID(buffer);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e44:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), 1);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct B1_4fe
{
};
struct FUN_005f0140_obj : TESForm
{
    B1_4fe unk18;
    void FUN_005f0140();
};
// @fnv 0x005f0140
void FUN_005f0140_obj::FUN_005f0140()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>(&(unk18))->ClearData();
    ::AppendChunk(0x4d414e44, &unk18, 1);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>(&(unk18))->ClearData();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

// ---------------------------------------------------------------------------
// BGSVoiceType::~BGSVoiceType  (FUN_005f00d0)
//
// The real class chain behind this destructor is
//
//     TESForm  <-  BGSDehydrationStage  <-  BGSVoiceType
//
// The pack header only carries the flattened "BGSVoiceType : public TESForm"
// form (and without any destructor on TESForm), so the missing intermediate
// base is restored here.  The intermediate base owns the non trivial
// destructor that the compiler emits as the tail call of this function, and
// carries the TESForm::ClearData() helper that the destructor body invokes.
//
// Layout of the reconstructed object:
//     +0x00  vptr
//     +0x04  TESForm::formFields[20]
//     +0x18  char Data
//     +0x1c  BSS unk1c          (non trivial destructor -> compiler cleanup)
// ---------------------------------------------------------------------------

struct BGSDehydrationStage : public TESForm
{
    ~BGSDehydrationStage();
};

struct BSS
{
    char* unk00;
    ~BSS();
};

struct FUN_005f00d0 : public BGSDehydrationStage
{
    char Data;
    BSS unk1c;
    ~FUN_005f00d0();
};

// @fnv 0x005f00d0
FUN_005f00d0::~FUN_005f00d0()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

struct FUN_005f00a0
{
    virtual ~FUN_005f00a0();
};
// The destructor body is empty.
// @fnv 0x005f00a0
FUN_005f00a0::~FUN_005f00a0()
{}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long vf, void* src, void* tgt, int isRef);
extern char DAT_01186318;
struct FUN_004851b0_call
{
};
struct FUN_005f02a0_shell : BGSDehydrationStage
{
    void FUN_005f02a0(TESForm* form);
};
// If FUN_00ec43fb resolves a source from form, copies its Data member to this and calls FUN_004851b0(form).
// @fnv 0x005f02a0
void FUN_005f02a0_shell::FUN_005f02a0(TESForm* form)
{
    FUN_005f00d0* src = (FUN_005f00d0*)FUN_00ec43fb(form, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_01186318, 0);
    if (!src)
    {
        return;
    }
    ((FUN_005f00d0*)this)->Data = src->Data;
    reinterpret_cast<::FormCloneOperation *>((((FUN_004851b0_call*)this)))->FUN_004851b0(form);
}

struct BGSVoiceType_shell : BGSVoiceType
{
    bool FUN_005f02f0(TESForm* form);
};

// Returns true if form is not a BGSVoiceType, its Data differs, or FUN_00485270(voice) is true; otherwise false.
// @fnv 0x005f02f0
bool BGSVoiceType_shell::FUN_005f02f0(TESForm* form)
{
    BGSVoiceType* voice = dynamic_cast<BGSVoiceType*>(form);
    if (!voice)
        return true;
    if (Data != voice->Data)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(voice))
        return true;
    return false;
}
