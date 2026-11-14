// fallout_shared/tesglobal.cpp: TESGlobal, TESImageSpace (8 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00529ea0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "tesglobal_layout.h"
#include "tesglobal_decls.h"
#include <malloc.h>

#define FNV_FOURCC(a, b, c, d)                                                                                         \
    ((unsigned int)(a) | ((unsigned int)(b) << 8) | ((unsigned int)(c) << 16) | ((unsigned int)(d) << 24))

// Reads a TESGlobal record from the file, handling EDID, OBND, FNAM and FLTV chunks until the chunk list ends.
// @fnv 0x005a64b0
bool TESGlobal::Load(TESFile* file)
{
    if (((unsigned int)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660())) != 6)
        return false;

    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));

    int chunkID;
    while ((chunkID = (int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case FNV_FOURCC('E', 'D', 'I', 'D'): {
            char* buffer = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case FNV_FOURCC('O', 'B', 'N', 'D'):
            readOBNDSubRecord(file);
            break;
        case FNV_FOURCC('F', 'N', 'A', 'M'):
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&cType), 1);
            break;
        case FNV_FOURCC('F', 'L', 'T', 'V'):
            file->GetChunkData((unsigned int*)&fValue);
            break;
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

#include "tesglobal_imagespace.h"

// @fnv 0x0052b310
TESImageSpace::TESImageSpace()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x53)));
    TESImageSpace::ResetFormData();
}

struct BSStr
{
};

struct FUN_005a63a0_shell : ::TESGlobal
{
    bool SetString(char const* a1);
};

// Calls Set on the BSStr at offset 0x18 with the given string and a length of 0, then returns true.
// @fnv 0x005a63a0
bool FUN_005a63a0_shell::SetString(char const* apString)
{
    reinterpret_cast<::TextString *>((((BSStr*)&this->cGlobalEditorID)))->FUN_004037f0(apString, 0);
    return 1;
}

struct S_5a63c0
{
    void FUN_005a63f0();
    void* Destroy(unsigned int flags);
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_005a6460_standin
{
    char _p0[32];
    unsigned char _b20;
    char _p1[3];
    float _f24;
    void FUN_005a6460();
};
// Calls M on this, then passes the byte at offset 0x20 and the float at offset 0x24 to FUN_004858f0 and _FUN_00485910, then calls M again.
// @fnv 0x005a6460
void FUN_005a6460_standin::FUN_005a6460()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    FUN_004858f0(0x4D414E46, _b20);
    ::FUN_00485910(0x56544C46, _f24);
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e78f0_t
{
};
struct BSFaceGenModelMap
{
};
struct TESGlobalValueReader
{
};
struct FUN_005a65e0_shell : TESGlobal
{
    void FUN_005a65e0(TESForm* apCopy);
};
// @fnv 0x005a65e0
void FUN_005a65e0_shell::FUN_005a65e0(TESForm* apCopy)
{
    TESGlobal* pCopy = dynamic_cast<TESGlobal*>(apCopy);
    if (!pCopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005e78f0_t*>(this)))->FUN_004851b0(apCopy);
    cType = ((bool)(reinterpret_cast<::FUN_00529ea0_shell *>((reinterpret_cast<BSFaceGenModelMap*>(pCopy)))->FUN_00529ea0()));
    fValue = reinterpret_cast<::FUN_00526ac0_shell *>((reinterpret_cast<TESGlobalValueReader*>(pCopy)))->FUN_00526ac0();
}

struct FUN_005e79a0_t
{
};
struct FUN_005a6640_shell : TESGlobal
{
    bool IsNotEqual(TESForm* apCompare);
};
// Compares this global with apCompare: returns true if apCompare is not a TESGlobal or differs by FUN_00485270, FUN_00529ea0 or GetValue; false otherwise.
// @fnv 0x005a6640
bool FUN_005a6640_shell::IsNotEqual(TESForm* apCompare)
{
    TESGlobal* pComp = dynamic_cast<TESGlobal*>(apCompare);
    if (!pComp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pComp))
        return true;
    if (((char)((bool)(reinterpret_cast<::FUN_00529ea0_shell *>((((BSFaceGenModelMap*)this)))->FUN_00529ea0()))) != ((char)((bool)(reinterpret_cast<::FUN_00529ea0_shell *>((((BSFaceGenModelMap*)pComp)))->FUN_00529ea0()))))
        return true;
    if (reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)this)))->FUN_00526ac0() != reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)pComp)))->FUN_00526ac0())
        return true;
    return false;
}

struct FUN_00483710_t
{
};

struct FUN_004037d0
{
    ~FUN_004037d0();
};

struct FUN_00483630
{
    virtual void Vb();
    char _p4[0x14];
    ~FUN_00483630();
};

struct FUN_005a63f0 : FUN_00483630
{
    virtual ~FUN_005a63f0();
    FUN_004037d0 m_18;
};
// Calls FUN_005a63f0, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x005a63c0
void* S_5a63c0::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_005a63f0 *>(this)->FUN_005a63f0::~FUN_005a63f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x005a63f0
FUN_005a63f0::~FUN_005a63f0()
{
    reinterpret_cast<::TESForm *>((((FUN_00483710_t*)this)))->ClearData();
}
