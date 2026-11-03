
// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglevarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotanglevarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c2a080
#include <new>
#include "fnv/decl/FUN_00c32d80.h"
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_010be000.h"
#include "fnv/symbols_01202000.h"
void* __cdecl FUN_00c2a080()
{
    return &(*reinterpret_cast<void * *>(&::g_012026e8));
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int uiSize);

struct Item
{
    void* m_pkVtbl;
};

struct Creator
{
    Item* CreateItem(int iArg);
};

// Allocates a 0x40-byte Item, initialises it, sets its vtable, passes it to FUN_00c32de0 with iArg, and returns it.
// @fnv 0x00c2a0c0
Item* Creator::CreateItem(int iArg)
{
    Item* pkItem = (Item*)FUN_00aa13e0(0x40);
    if (pkItem)
    {
        new ((void *)(pkItem)) ::FUN_00c32d80();
        pkItem->m_pkVtbl = &DAT_010beebc;
    }
    else
    {
        pkItem = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>(this)->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(pkItem), (*(::CloningProcess *)(iArg)));
    return pkItem;
}

struct C2A110RTTI
{
    const char* m_pcName;
    const C2A110RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};

struct C2A110StringArray
{
    virtual ~C2A110StringArray();

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;


    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int Add(char*& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};


struct C2A110Base
{
};

struct C2A110Object : C2A110Base
{

    int unk00;
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
    float m_fFrequency;

    void AppendRTTIName(C2A110StringArray* pkStrings);
};

// @fnv 0x00c2a110
void C2A110Object::AppendRTTIName(C2A110StringArray* pkStrings)
{
    ::FUN_00c32f60((::StrArr *)this);
    char* pcString = ::FUN_00a7d330((*reinterpret_cast<::C2A110RTTI *>(&::g_012026e8)).GetName());
    pkStrings->Add(pcString);
}
