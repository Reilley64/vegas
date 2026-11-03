// fallout_shared/bgsstaticcollection.cpp: BGSStaticCollection, StaticCollectionComparison (8 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0052d240_shell.h"
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
#include "bgsstaticcollection_decls.h"
#include <malloc.h>

// Reads the record header and iterates chunks, handling EDID, OBND, model and texture-swap subrecords until no chunk remains, then returns true.
// @fnv 0x004fe390
bool BGSStaticCollection::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    CHUNK_ID chunk;
    while ((chunk = static_cast<CHUNK_ID>(((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))) != CHUNK_ID_NO_CHUNK)
    {
        switch (chunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_MODL_ID:
        case CHUNK_ID_MODD_ID:
        case CHUNK_ID_MOSD_ID:
        case CHUNK_ID_MODT_ID:
            TESModel::LoadModelData(this, file);
            break;
        case CHUNK_ID_MODS_ID: {
            struct TextureSwapChunk
            {
                unsigned int size;
                void* data;
            } textureSwapChunk;
            textureSwapChunk.size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            textureSwapChunk.data = _alloca(textureSwapChunk.size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureSwapChunk.data), textureSwapChunk.size);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureSwapChunk.data, textureSwapChunk.size,
                                 reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570());
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Returns early if the item is already initialized; otherwise calls TESModelTextureSwap::InitItem and marks the item initialized.
// @fnv 0x004fe560
void BGSStaticCollection::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    TESModelTextureSwap::InitItem(this);
    SetInitializationState(true);
}

struct B1_4fe
{
    char d[0x2c];
    B1_4fe();
    ~B1_4fe();
    virtual void v1();
};
struct B2_4fe
{
    char d[0x10];
    B2_4fe();
    ~B2_4fe();
    virtual void v2();
};
struct FUN_004fe260 : B1_4fe, B2_4fe
{
    FUN_004fe260();
};
// Constructs the object and sets its form type to 0x21 via SetFormType.
// @fnv 0x004fe260
FUN_004fe260::FUN_004fe260()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x21);
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct S_0048a520
{
};

struct FUN_004fe520_shell
{
    void FUN_004fe520(void);
};

// Calls M on this, then ProcessAndFreeData on the object at offset 0x30 with three tags, then M on this again.
// @fnv 0x004fe520
void FUN_004fe520_shell::FUN_004fe520(void)
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)((char*)this + 0x30))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct Dummy
{
    void FUN_004fe310();
    void* FUN_004fe2e0(unsigned int);
};
struct FUN_005e78f0_t
{
};
struct FUN_004fe5a0_t
{
    void FUN_004fe5a0(TESForm*);
};
// Casts apCopy to BGSStaticCollection and, if the cast succeeds, forwards it to FUN_004851b0.
// @fnv 0x004fe5a0
void FUN_004fe5a0_t::FUN_004fe5a0(TESForm* apCopy)
{
    BGSStaticCollection* pcopy = dynamic_cast<BGSStaticCollection*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
}

struct FUN_004fe310 : B1_4fe, B2_4fe
{
    ~FUN_004fe310();
};
// Calls FUN_004fe310, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004fe2e0
void* Dummy::FUN_004fe2e0(unsigned int flags)
{
    reinterpret_cast<::FUN_004fe310 *>(this)->FUN_004fe310::~FUN_004fe310();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004fe310
FUN_004fe310::~FUN_004fe310()
{
    reinterpret_cast<::FUN_0052d240_shell *>(this)->FUN_0052d240();
}

class FormComponentComparison : public TESForm
{
  public:
};

class StaticCollectionComparison : public BGSStaticCollection
{
  public:
    bool FUN_004fe5e0(TESForm* other);
};

// Returns true if other is not a BGSStaticCollection or FUN_00485270 returns true for the collection.
// @fnv 0x004fe5e0
bool StaticCollectionComparison::FUN_004fe5e0(TESForm* other)
{
    BGSStaticCollection* collection = dynamic_cast<BGSStaticCollection*>(other);
    if (!collection)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((static_cast<FormComponentComparison*>(static_cast<TESForm*>(this))))->FUN_00485270(collection))
        return true;
    return false;
}
