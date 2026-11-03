// fallout_shared/bgsmenuicon.cpp: BGSMenuIcon (6 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "TESForm.h"
#include "TESFile.h"
#include "TESIcon.h"
#include <malloc.h>

class BGSMenuIcon : public TESForm
{
  public:
    TESIcon icon;
    bool Load(TESFile* file);
};

class TESTextureLoader
{
  public:
};

struct ChunkLoadState
{
    char* chunkData;
    unsigned int chunkID;
};

// Checks the form type is 5, loads the record header, then reads EDID, OBND and ICON chunks until no chunk remains.
// @fnv 0x00590350
bool BGSMenuIcon::Load(TESFile* file)
{
    unsigned char formType;
    ChunkLoadState chunkState;

    formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 5)
        return false;

    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    while ((chunkState.chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkState.chunkID)
        {
        case 0x44494445:
            chunkState.chunkData = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(chunkState.chunkData), 0x200);
            SetEditorID_AtRuntime(chunkState.chunkData);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(this ? static_cast<TESTexture*>(&icon) : 0, file);
            break;
        }

        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_005902a0_Class
{
    void FUN_005902d0();
    void* Release(unsigned int flags);
};


struct FUN_00483630_holder
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    virtual ~FUN_00483630_holder();
};

struct FUN_005902d0 : FUN_00483630_holder, TESIcon
{
    virtual ~FUN_005902d0();
};
// Calls FUN_005902d0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x005902a0
void* FUN_005902a0_Class::Release(unsigned int flags)
{
    reinterpret_cast<::FUN_005902d0 *>(this)->FUN_005902d0::~FUN_005902d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for FUN_005902d0 that calls FUN_00483710 on this.
// @fnv 0x005902d0
FUN_005902d0::~FUN_005902d0()
{
    reinterpret_cast<::TESForm *>((this))->ClearData();
}

struct FUN_004855a0_shell
{
};
struct FUN_00485680_shell
{
};
struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};
struct FUN_00509280_obj : ::BGSMenuIcon
{
    void FUN_0048e370(unsigned int);
    void FUN_00590470();
};
// @fnv 0x00590470
void FUN_00509280_obj::FUN_00590470()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)&this->icon)))->FUN_0048e370(0x4e4f4349);
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

extern const void* DAT_01183028;
struct FUN_005e78f0_t
{
};
struct FUN_005904a0_shell
{
    void FUN_005904a0(TESForm* form);
};
// Casts the TESForm to BGSMenuIcon and calls FUN_004851b0 on it if the cast succeeds.
// @fnv 0x005904a0
void FUN_005904a0_shell::FUN_005904a0(TESForm* form)
{
    BGSMenuIcon* icon = dynamic_cast<BGSMenuIcon*>(form);
    if (!icon)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(icon);
}

struct FUN_005e79a0_t
{
};
struct FUN_005904e0_s
{
    bool FUN_005904e0(TESForm* apCompare);
};
// Returns true if apCompare is not a BGSMenuIcon or the base comparison returns true.
// @fnv 0x005904e0
bool FUN_005904e0_s::FUN_005904e0(TESForm* apCompare)
{
    BGSMenuIcon* pcomp = dynamic_cast<BGSMenuIcon*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcomp))
        return true;
    return false;
}
