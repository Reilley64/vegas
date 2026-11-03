
// src/gamebryo2.2/corelibs/nimain/ninifimagereader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/ninifimagereader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00a8ad80
#include <windows.h>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/NiStream.h"
#include "fnv/symbols_00a65000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109f000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
char IsNifExtension(const char* pcFileExtension)
{
    return ::NiStricmp(pcFileExtension, ".nif") == 0;
}


struct A8AE50CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct A8AE50Stream
{
    A8AE50Stream();
};

class A8AE50ImageReader
{
  public:
    virtual void vfunc00();
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
    A8AE50CriticalSection m_kCriticalSection;
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

    A8AE50ImageReader()
    {
        InitializeCriticalSection(&m_kCriticalSection);
    }
};

class FUN_00a8ae50 : public A8AE50ImageReader
{
  public:
    A8AE50Stream m_kVertexStream;

    FUN_00a8ae50();
    virtual void vfunc00();
};

// Constructs the object, initializing its critical section via the base A8AE50ImageReader constructor.
// @fnv 0x00a8ae50
FUN_00a8ae50::FUN_00a8ae50()
{}

#include <windows.h>

struct A8NiStream
{
};

struct A8Class
{
    void* unk00;
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
    CRITICAL_SECTION unk80;
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
    A8NiStream unk100;

    void FUN_00a8ada0();
};

// Sets unk00 to DAT_0109f3e4, calls unk100.FUN_00a65300, sets unk00 to DAT_0109f3d0, and deletes the critical section at unk80.
// @fnv 0x00a8ada0
void A8Class::FUN_00a8ada0()
{
    unk00 = DAT_0109f3e4;
    ::FUN_00a65300((::FUN_00a65300_holder *)&(unk100));
    unk00 = DAT_0109f3d0;
    DeleteCriticalSection(&unk80);
}

struct FUN_00a8add0_blob
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
};

class FUN_00a8add0_cls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual FUN_00a8add0_cls* v2(const char* pcFileExtension, int iFlag);

    bool FUN_00a8add0(const char* pcFileExtension, unsigned int* pOut0, unsigned int* pOut1, FUN_00a8add0_blob* pBlob,
                      bool* pFlag, unsigned int* pOut2);

    long m_04;
    FUN_00a8add0_blob m_08;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int* m_54;
    unsigned int* m_58;
    unsigned int unk5C;
    unsigned int m_60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int m_6c;
};

// Calls v2 with pcFileExtension, then copies fields from the returned object to the output parameters.
// @fnv 0x00a8add0
bool FUN_00a8add0_cls::FUN_00a8add0(const char* pcFileExtension, unsigned int* pOut0, unsigned int* pOut1,
                                    FUN_00a8add0_blob* pBlob, bool* pFlag, unsigned int* pOut2)
{
    FUN_00a8add0_cls* obj = this->v2(pcFileExtension, 0);
    if (obj != 0)
    {
        InterlockedIncrement(&obj->m_04);
        *pOut0 = *obj->m_54;
        *pOut1 = *obj->m_58;
        *pBlob = obj->m_08;
        *pFlag = obj->m_60 > 1;
        *pOut2 = obj->m_6c;
        if (InterlockedDecrement(&obj->m_04) == 0)
        {
            obj->v1();
        }
        return true;
    }
    return false;
}

namespace fnv_00a8ae80 {

struct FUN_00a8ae80_member
{
    int unk00;
};

struct FUN_00a8ae80_pool
{
};

struct FUN_00a8ae80_cls
{
    int m_vptr;
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
    CRITICAL_SECTION m_cs;
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
    FUN_00a8ae80_member m_100;

    FUN_00a8ae80_cls* FUN_00a8ae80(unsigned char acFlags);
};

// Calls Cleanup, updates m_vptr twice, deletes m_cs, and passes this to DAT_011f6238.Free when acFlags bit 0 is set.
// @fnv 0x00a8ae80
FUN_00a8ae80_cls* FUN_00a8ae80_cls::FUN_00a8ae80(unsigned char acFlags)
{
    FUN_00a8ae80_member* pMember = &m_100;
    m_vptr = (int)&(*reinterpret_cast<int *>(&::DAT_0109f3e4));
    ::FUN_00a65300((::FUN_00a65300_holder *)(pMember));
    m_vptr = (int)&(*reinterpret_cast<int *>(&::DAT_0109f3d0));
    DeleteCriticalSection(&m_cs);
    if (acFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a8ae80::FUN_00a8ae80_pool *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00a8ae80


struct Node
{
    int unk00;
    Node* next;
};

struct Obj
{
    virtual void v00();
    virtual void v04(const char* name);
    virtual Node* v08();
};

struct SubObj
{
    virtual void v00();
    virtual void v04(const char* name);
};

struct FnvMgr
{
    Obj* FUN_00a8aec0(const char* name, int unused);
};

// Calls sub->v04 with name, then returns the object if its node list contains DAT_011f4a90.
// @fnv 0x00a8aec0
Obj* FnvMgr::FUN_00a8aec0(const char* name, int unused)
{
    CRITICAL_SECTION* cs = (CRITICAL_SECTION*)((char*)this + 0x80);
    EnterCriticalSection(cs);
    SubObj* pSubObj = (SubObj*)((char*)this + 0x100);
    reinterpret_cast<::NiStream *>((pSubObj))->ClearTopLevelObjects();
    pSubObj->v04(name);
    if (*(int*)((char*)this + 0x328) == 1)
    {
        Obj* pObj = **(Obj***)((char*)this + 0x320);
        if (pObj != 0)
        {
            Node* pHead = pObj->v08();
            if (pHead != 0)
            {
                for (Node* pNode = pHead; pNode != 0; pNode = pNode->next)
                {
                    if (pNode == (Node*)&(*reinterpret_cast<int *>(&::g_011f4a90)))
                    {
                        LeaveCriticalSection(cs);
                        return pObj;
                    }
                }
            }
        }
    }
    LeaveCriticalSection(cs);
    return 0;
}
