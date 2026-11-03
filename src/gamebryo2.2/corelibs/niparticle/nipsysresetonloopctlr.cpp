
// src/gamebryo2.2/corelibs/niparticle/nipsysresetonloopctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysresetonloopctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00a6d220.h"
#include "fnv/decl/FUN_00a6d730_shell.h"
#include "fnv/decl/NiTimeControllerA362.h"
#include "fnv/decl/NiTimeControllerCM.h"
#include "fnv/decl/NiTimeController_Luna.h"
#include "fnv/decl/TCController.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a6c000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01202000.h"
extern "C"
{
}

// @fnv 0x00c28400
void* __cdecl FUN_00c28400()
{
    return &(*reinterpret_cast<void * *>(&::g_012026a8));
}

void __cdecl FUN_00a6d290();

struct NiPSysResetOnLoopCtlr
{
    NiPSysResetOnLoopCtlr* Destroy(unsigned int flags);
};

// Calls FUN_00a6d290, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00c28410
NiPSysResetOnLoopCtlr* NiPSysResetOnLoopCtlr::Destroy(unsigned int flags)
{
    FUN_00a6d290();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x38);
    return this;
}

struct RTTI_00c284f0
{
    int _00;
    RTTI_00c284f0* m_pkBase;
};
struct Obj_00c284f0
{
    virtual void _u0();
    virtual void _u1();
    virtual RTTI_00c284f0* GetRTTI();
};
struct Cls_00c284f0
{
    bool IsTargetOfType();
};
// Checks whether the object at offset 0x2c exists and its RTTI chain contains g_01202538_arg1, returning true if found.
// @fnv 0x00c284f0
bool Cls_00c284f0::IsTargetOfType()
{
    Obj_00c284f0* pkTarget = *(Obj_00c284f0**)((char*)this + 0x2c);
    if (!pkTarget)
        return false;
    RTTI_00c284f0* pkRTTI = pkTarget->GetRTTI();
    for (; pkRTTI; pkRTTI = pkRTTI->m_pkBase)
    {
        if (pkRTTI == (RTTI_00c284f0*)&(*reinterpret_cast<const char *const *>(&::g_012024e0)))
            return true;
    }
    return false;
}

struct StrArr
{
    unsigned char _pad0[8];
    unsigned short _s8;
    unsigned short _sA;
    unsigned short _sC;
    unsigned short _sE;
};
// Appends the string returned by _FUN_00a7d330(g_012026a8) to pkStrings, growing the array if the position is at or past its size.
// @fnv 0x00c28520
void FUN_00c28520(StrArr* pkStrings)
{
    reinterpret_cast<::TCController *>((pkStrings))->FUN_00a6d830({});
    char* pcString = ::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_012026a8))));
    unsigned int uiPos = pkStrings->_sA;
    unsigned int uiSize = pkStrings->_s8;
    if (uiPos >= uiSize)
    {
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiPos + pkStrings->_sE);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiPos, pcString);
}

struct NiMemObject
{
};
extern int DAT_010be8e4;

struct CloningProcess
{
};
struct CloneableObj
{
    void* vtable;
};
struct FUN_00c28430_Object : CloneableObj
{
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
    int unk30;
    float value34;
};
struct FUN_00c28430_class : CloneableObj
{
    FUN_00c28430_Object* CreateCloneableObject(void* volatile argument);
};
// @fnv 0x00c28430
FUN_00c28430_Object* FUN_00c28430_class::CreateCloneableObject(void* volatile argument)
{
    FUN_00c28430_Object* object = (FUN_00c28430_Object*)::operator new(0x38);
    if (object)
    {
        new ((void *)(object)) class ::FUN_00a6d220();
        object->value34 = DAT_01015f5c;
        object->vtable = &DAT_010be8e4;
        reinterpret_cast<::NiTimeControllerCM *>(this)->FUN_00a6cfe0((::NiTimeController *)(object), (*(::CloningProcess *)(argument)));
    }
    else
    {
        object = 0;
        void* copy = argument;
        reinterpret_cast<::NiTimeControllerCM *>(this)->FUN_00a6cfe0((::NiTimeController *)(object), (*(::CloningProcess *)(copy)));
    }
    return object;
}

struct FUN_00c28490_shell
{
    int unk00;
    int unk04;
    unsigned short flags;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float unk28;
    char* unk2c;
    int unk30;
    float unk34;
    void FUN_00c28490(float* p);
};
// Clears two flags, and if unk2c is set and FUN_00a36250(*p) returns 0, resets unk34 to unk28 and sets unk2c[0xd8] when unk34 exceeds unk28.
// @fnv 0x00c28490
void FUN_00c28490_shell::FUN_00c28490(float* pfValue)
{
    flags &= 0xfff9;
    if (unk2c != 0)
    {
        if (((char)(reinterpret_cast<::NiTimeControllerA362 *>(this)->FUN_00a36250(*pfValue))) == 0)
        {
            if ((double)unk34 == ::DAT_010241b0)
                unk34 = unk28;
            if (unk34 > unk28)
                unk2c[0xd8] = 1;
            unk34 = unk28;
        }
    }
}


// @fnv 0x00a2f8b0
void __cdecl FUN_00a2f8b0()
{
    ::FUN_00a6d0f0({}, {}, *(::NiStream *)nullptr);
}

struct NiStream
{
    int unk00;
};

struct BaseHack
{
};

struct C27120Class : BaseHack
{
    void FUN_00c27120(NiStream& s);
};

// @fnv 0x00c27120
void C27120Class::FUN_00c27120(NiStream& s)
{
    reinterpret_cast<::FUN_00a6d730_shell *>(this)->FUN_00a6d730((::Stream_a6d730 &)(s));
}

struct NiStream;

struct SubNiPSysResetOnLoopCtlr : NiPSysResetOnLoopCtlr
{
    void FUN_00c283e0(NiStream& stream);
};

// @fnv 0x00c283e0
void SubNiPSysResetOnLoopCtlr::FUN_00c283e0(NiStream& stream)
{
    reinterpret_cast<::NiTimeController_Luna *>(this)->FUN_00a6d5e0(stream);
}

// @fnv 0x00c283f0
void __cdecl FUN_00c283f0()
{
    ::FUN_00a6cc80({}, {}, {});
}
