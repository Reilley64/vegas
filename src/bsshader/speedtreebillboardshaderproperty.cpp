#include <cstdint>
#include <cstddef>

// src/bsshader/speedtreebillboardshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/speedtreebillboardshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00b67380.h"
#include "fnv/decl/SelfStub.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00b66000.h"
#include "fnv/symbols_01200000.h"
extern int DAT_010b8330;

struct FUN_00ba8690
{
    void* m_p;
    FUN_00ba8690(int flags);
};

// @fnv 0x00ba8690
FUN_00ba8690::FUN_00ba8690(int flags)
{
    m_p = (void*)&DAT_010b8330;
    reinterpret_cast<struct ::FUN_00b67380 *>((this))->FUN_00b67380::~FUN_00b67380();
    if (flags & 1)
        operator delete((void*)this, 0x104);
}

struct S_00ba8630_Base
{
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    S_00ba8630_Base();
    virtual ~S_00ba8630_Base();
};

struct FUN_00ba8630 : S_00ba8630_Base
{
    int unk58;
    FUN_00ba8630();
    virtual ~FUN_00ba8630();
};

// Initializes the object: sets unk58 to 1 and unk1C to 0xb.
// @fnv 0x00ba8630
FUN_00ba8630::FUN_00ba8630() : unk58(1)
{
    unk1C = 0xb;
}


// @fnv 0x00ba8680
int* __cdecl FUN_00ba8680()
{
    return &(*reinterpret_cast<int *>(&::g_0120043c));
}


// @fnv 0x00ba8670
bool FUN_00ba8670(void* apValue)
{
    ::FUN_00b665c0((std::intptr_t)(apValue));
    return false;
}

struct ACS00bac
{
    void* m_p;
};

struct A5A040Cls
{
};

struct BA86C0Owner
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int* unkAC;

    int FUN_00ba86c0(A5A040Cls* pArg, int arg2, int arg3);
};

// Calls FUN_00a5a040 when pArg+0x9c is null and clears unk58 when *unkAC is zero, then returns 0.
// @fnv 0x00ba86c0
int BA86C0Owner::FUN_00ba86c0(A5A040Cls* pArg, int arg2, int arg3)
{
    if ((char*)pArg + 0x9c == 0)
        reinterpret_cast<::FUN_00a5a040_Class *>((pArg))->FUN_00a5a040();
    if (*unkAC == 0)
        unk58 = 0;
    return 0;
}

extern int DAT_010b8330;
void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedBase
{
    virtual ~SpawnedBase();
    SpawnedBase();
};

struct SpawnedObject : SpawnedBase
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    SpawnedObject()
    {
        unk58 = 1;
        unk1C = 0xb;
    }
};

struct SpawnerHost
{
    int* CreateSpawnedObject(void* a1);
};

// Allocates a SpawnedObject, passes it with a1 to FUN_00b665d0, and returns the object as an int pointer.
// @fnv 0x00ba86f0
int* SpawnerHost::CreateSpawnedObject(void* aiFlags)
{
    SpawnedObject* p = new SpawnedObject();
    reinterpret_cast<::SelfStub *>((this))->FUN_00b665d0((char *)(p), aiFlags);
    return (int*)p;
}


struct ObjHdr
{
    int unk0;
    int unk4;
    unsigned short unk8;
    unsigned short unkA;
    unsigned short unkC;
    unsigned short unkE;
};

// @fnv 0x00ba8780
void FUN_00ba8780(ObjHdr* apObj)
{
    ObjHdr* pObj = apObj;
    reinterpret_cast<::Target *>((pObj))->FUN_00b690d0({});
    void* pValue = ((void *)(::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_0120043c)))));
    unsigned int count = pObj->unkA;
    if (count >= pObj->unk8)
    {
        reinterpret_cast<::ViewerStrings *>((pObj))->SetSize((int)(pObj->unkE + count));
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pObj))->SetAt(count, (*(char * *)(&pValue)));
}

struct S_00b68ed0_Stream;
struct S_00b68ed0_Obj
{
    void ReadFromStream(S_00b68ed0_Stream*);
};
struct FUN_00ba8660_S
{
    void FUN_00ba8660(S_00b68ed0_Stream*);
};
// @fnv 0x00ba8660
void FUN_00ba8660_S::FUN_00ba8660(S_00b68ed0_Stream* p)
{
    ((S_00b68ed0_Obj*)this)->ReadFromStream(p);
}
