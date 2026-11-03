// fallout_shared/teseyes.cpp: TESEyes, Holder (13 functions)

#include <malloc.h>
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00503650_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005fc120.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/RefList.h"
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

class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
};

class TESFile;
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;
    TESTexture();
public:
    static void ReadTextureData(::TESTexture *, ::TESFile *);
};

class TESTextureLoader
{
  public:
};

class TESEyes : public TESForm, public TESFullName, public TESTexture
{
  public:
    char cFlags;
    TESEyes();
    virtual bool Load(TESFile* file);
public:
    void FUN_005fc1b0();
};

// @fnv 0x005fc050
TESEyes::TESEyes()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_EYES_ID)));
    reinterpret_cast<::TESEyes *>(this)->FUN_005fc1b0();
}

struct FUN_005fc4d0_shell
{
    char pad[0x30];
    char cFlags;
    bool IsFlagSet();
};
// @fnv 0x005fc4d0
bool FUN_005fc4d0_shell::IsFlagSet()
{
    return (cFlags & 1) ? true : false;
}

struct FUN_005fc4f0_shell
{
    void SetFlag(bool aFlag);
};

// Sets or clears bit 0 of the byte at offset 0x30 of this object according to aFlag.
// @fnv 0x005fc4f0
void FUN_005fc4f0_shell::SetFlag(bool aFlag)
{
    if (aFlag)
        ((char*)this)[0x30] |= 1;
    else
        ((char*)this)[0x30] &= 0xfffffffe;
}

struct FUN_005fc530_shell
{
    char m[0x31];
    bool IsNotFlag2Set();
};

// @fnv 0x005fc530
bool FUN_005fc530_shell::IsNotFlag2Set()
{
    if (m[0x30] & 2)
        return false;
    return true;
}

struct FUN_005fc590_shell
{
    char pad[0x30];
    char cFlags;
    bool IsFlag4Clear();
};

// @fnv 0x005fc590
bool FUN_005fc590_shell::IsFlag4Clear()
{
    if (cFlags & 4)
        return false;
    return true;
}

struct FUN_005fc420_shell
{
    bool IsNotEqual(TESForm* apCompare);
};

struct FUN_005e79a0_t
{
};

// @fnv 0x005fc420
bool FUN_005fc420_shell::IsNotEqual(TESForm* apCompare)
{
    TESEyes* pcomp = dynamic_cast<TESEyes*>(apCompare);
    if (pcomp == 0)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pcomp))
        return true;
    if (reinterpret_cast<FUN_005fc4d0_shell*>(pcomp)->IsFlagSet() !=
        reinterpret_cast<FUN_005fc4d0_shell*>(this)->IsFlagSet())
        return true;
    if (reinterpret_cast<FUN_005fc530_shell*>(pcomp)->IsNotFlag2Set() !=
        reinterpret_cast<FUN_005fc530_shell*>(this)->IsNotFlag2Set())
        return true;
    if (reinterpret_cast<FUN_005fc590_shell*>(pcomp)->IsFlag4Clear() !=
        reinterpret_cast<FUN_005fc590_shell*>(this)->IsFlag4Clear())
        return true;
    return false;
}

struct Holder
{
    void* ReleaseIfFlagged(unsigned int);
public:
    void FUN_00485680();
};
// Calls FUN_005fc120, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x005fc0f0
void* Holder::ReleaseIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_005fc120 *>(this)->FUN_005fc120::~FUN_005fc120();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004855a0
{
    char _pad[0x18];
};
struct FUN_00485680
{
};
struct S_00487010
{
    char _pad[0x0C];
};
struct FUN_0048e370_obj
{
    char _pad[0x0C];
};
struct FUN_005fc1d0_Obj : FUN_00485680, FUN_004855a0
{
    S_00487010 s;
    FUN_0048e370_obj t;
    char cFlags;
    void FUN_005fc1d0();
};
// @fnv 0x005fc1d0
void FUN_005fc1d0_Obj::FUN_005fc1d0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(&(s))->FUN_00487010();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(&(t))->FUN_0048e370(0x4E4F4349);
    FUN_004858f0(0x41544144, cFlags);
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct FUN_005e78f0_t
{
};
struct FUN_005fc550_shell
{
    void FUN_005fc550(bool flag);
};
struct FUN_005fc5b0_shell
{
    void FUN_005fc5b0(bool flag);
};
struct FUN_005fc3a0_shell
{
    void CopyFromEyes(TESForm* apCopy);
};
// @fnv 0x005fc3a0
void FUN_005fc3a0_shell::CopyFromEyes(TESForm* apCopy)
{
    TESEyes* eyes = dynamic_cast<TESEyes*>(apCopy);
    if (!eyes)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
    ((FUN_005fc4f0_shell*)this)->SetFlag(((FUN_005fc4d0_shell*)eyes)->IsFlagSet());
    ((FUN_005fc550_shell*)this)->FUN_005fc550(((FUN_005fc530_shell*)eyes)->IsNotFlag2Set());
    ((FUN_005fc5b0_shell*)this)->FUN_005fc5b0(((FUN_005fc590_shell*)eyes)->IsFlag4Clear());
}

struct TESNPC;
struct TESHairRaceResult;
struct TESHairCanBeNPCData
{
    TESHairRaceResult* FUN_004ac110();
};
struct LH
{
};
struct TESDataHandler
{
};
struct TESActorBase
{
    int GetSex();
};
struct TESNPC : public TESActorBase
{
    TESHairCanBeNPCData* FUN_004ac110();
};
struct FUN_005fc5f0_shell : public TESEyes
{
    bool CanBeNPC(TESNPC* npc);
};
// @fnv 0x005fc5f0
bool FUN_005fc5f0_shell::CanBeNPC(TESNPC* npc)
{
    bool result = false;
    if (npc && ((::TESHairCanBeNPCData *)(reinterpret_cast<::FUN_004ac110_shell *>((npc))->FUN_004ac110())))
    {
        TESNPC* race = (TESNPC*)this;
        if (reinterpret_cast<::RefList *>((((LH*)((::BSSimpleList< ::TESNPC *> *)(reinterpret_cast<::FUN_00503650_shell *>((((TESDataHandler*)((::TESHairCanBeNPCData *)(reinterpret_cast<::FUN_004ac110_shell *>((npc))->FUN_004ac110())))))->FUN_00503650())))))->FUN_005f65d0((void **)&(race)))
        {
            switch (npc->GetSex())
            {
            case 0:
                if (((FUN_005fc530_shell*)this)->IsNotFlag2Set())
                    result = true;
                break;
            case 1:
                if (((FUN_005fc590_shell*)this)->IsFlag4Clear())
                    result = true;
                break;
            }
        }
    }
    return result;
}

namespace fnv_005fc550 {
struct FUN_005fc550_shell
{
    char pad[0x30];
    char cFlags;
    void FUN_005fc550(bool aFlag);
};

// Sets or clears bit 2 of cFlags depending on aFlag: clears it when aFlag is true, sets it otherwise.
// @fnv 0x005fc550
void FUN_005fc550_shell::FUN_005fc550(bool aFlag)
{
    if (aFlag)
        cFlags &= ~2;
    else
        cFlags |= 2;
}
}  // namespace fnv_005fc550

namespace fnv_005fc5b0 {
struct FUN_005fc5b0_shell
{
    char pad[0x30];
    char cFlags;
    void FUN_005fc5b0(bool aFlag);
};

// Clears bit 4 of cFlags when aFlag is true, otherwise sets bit 4.
// @fnv 0x005fc5b0
void FUN_005fc5b0_shell::FUN_005fc5b0(bool aFlag)
{
    if (aFlag)
        cFlags &= ~4;
    else
        cFlags |= 4;
}
}  // namespace fnv_005fc5b0

struct FUN_005fc220_shell : public TESEyes
{
    bool LoadEyes(TESFile*);
};

struct TESFileX
{
};

// Loads a TESEyes record from the file, handling EDID, OBND, FULL, ICON and DATA chunks, and returns false if the record type is not 0xb.
// @fnv 0x005fc220
bool FUN_005fc220_shell::LoadEyes(TESFile* apFile)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((((TESFileX*)apFile)))->FUN_00472660() != 0xb)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(apFile));
    int chunkid;
    while ((chunkid = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()))) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pEditorId), 0x200);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, apFile);
            break;
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(this, apFile);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&cFlags), 1);
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}
