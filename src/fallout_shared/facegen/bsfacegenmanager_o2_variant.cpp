
// src/fallout_shared/facegen/bsfacegenmanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/facegen/bsfacegenmanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FR2MatrixVTCData.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011c5000.h"
#include "bsfacegenmanager_decls.h"

struct BSFaceGenModel
{
    virtual void _v00();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0c();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1c();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28();
    virtual void _v2c();
    virtual void _v30();
    virtual void _v34();
    virtual void _v38();
    virtual void _v3c();
    virtual void _v40();
    virtual void _v44();
    virtual void _v48();
    virtual void _v4c();
    virtual void _v50();
    virtual void _v54();
    virtual void _v58();
    virtual void _v5c();
    virtual void _v60();
    virtual void _v64();
    virtual void _v68();
    virtual void _v6c();
    virtual void _v70();
    virtual void _v74();
    virtual void _v78();
    virtual void _v7c();
    virtual void _v80();
    virtual void _v84();
    virtual void _v88();
    virtual bool HasMorphs();  // 0x8c

};

struct BSFaceGenMorphData
{
    void* m_pData;
    unsigned int m_uiSize;
    unsigned char m_bFlag;
};

struct S00a67410
{
    char _pad0[0x20];
    void* m_pDefaultData;  // +0x20
    char _pad24[0xc];
    BSFaceGenModel* m_pModel;  // +0x30
    char _pad34[6];
    unsigned char m_bModifierActive;  // +0x3a

    void FUN_00a67410(BSFaceGenMorphData* outData);
};

struct RecursiveSpinLock
{
    unsigned int value;
};


template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* next;
        LinkedListEntry* prev;
        void* data;
    };

    static LinkedListEntry* ms_pFreeList;
};

struct FUN_00a68e30_shell
{
    char m_auiShapeKeys[0xb8];
    PoolAllocatorBase<unsigned int>::LinkedListEntry* m_pkHead;
    PoolAllocatorBase<unsigned int>::LinkedListEntry* m_pkTail;
    unsigned int m_uiCount;

    void FUN_00a68e30();
};

// @fnv 0x00a68e30
void FUN_00a68e30_shell::FUN_00a68e30()
{
    while (m_uiCount)
    {
        PoolAllocatorBase<unsigned int>::LinkedListEntry* node = m_pkHead;
        m_pkHead = node->next;
        if (m_pkHead)
            m_pkHead->prev = 0;
        else
            m_pkTail = 0;

        node->data = 0;
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
        node->prev = 0;
        node->next = (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58));
        --DAT_011c5f84;
        (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58)) = node;
        if (!DAT_011c5f84)
            (*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80)).value = 0;

        --m_uiCount;
    }
}

struct A72720Buffer
{
    int unk00;
    unsigned int m_uiSize;
    char* m_pcData;
};

struct A72720Record
{
    int unk00;
    void* m_pvStream;
    int m_iArrayCapacity;
    int m_iFormat;
    int m_iUsage;
    unsigned int m_uiBuffer;
    unsigned int m_uiValueBeforeCount;
};

class A72720StreamSet
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usVertexCount;
    unsigned short unk0E;
    unsigned int m_uiRecordCount;
    A72720Record* m_pkRecords;
    int unk18;
    int unk1C;
    A72720Buffer** m_ppkBuffers;
    unsigned short unk24;
    unsigned short m_usBufferCount;

    bool FUN_00a72720(unsigned int uiIndex, char** ppcData, void** ppvStream, unsigned short* pusVertexCount,
                      int* piFormat, int* piStride, int* piUsage);
};
// @fnv 0x00a67410
void S00a67410::FUN_00a67410(BSFaceGenMorphData* outData)
{
    if (!m_bModifierActive)
        return;

    BSFaceGenModel* model = m_pModel;
    void* vars[6];
    vars[1] = 0;
    vars[3] = 0;
    vars[0] = 0;

    if (model && model->HasMorphs())
    {
        vars[2] = 0;
        reinterpret_cast<::A72720StreamSet *>((model))->FUN_00a72720(0, (char **)(void *)(&vars[0]), (void **)(void *)(&vars[5]), (unsigned short *)(void *)(&vars[3]), (int *)(void *)(&vars[4]), (int *)(void *)(&vars[2]), (int *)(void *)(&vars[1]));
    }

    void* data;
    unsigned int size;
    if (!vars[0])
    {
        data = m_pDefaultData;
        size = 12;
    }
    else
    {
        data = vars[0];
        size = (unsigned int)vars[1];
    }

    outData->m_pData = data;
    outData->m_uiSize = size;
    outData->m_bFlag = 0;
}

// @fnv 0x00a72720
bool A72720StreamSet::FUN_00a72720(unsigned int uiIndex, char** ppcData, void** ppvStream,
                                   unsigned short* pusVertexCount, int* piFormat, int* piStride, int* piUsage)
{
    if (uiIndex >= m_uiRecordCount)
        return false;
    if (!m_pkRecords)
        return false;

    A72720Record& kRecord = m_pkRecords[uiIndex];
    void* pvStream = kRecord.m_pvStream;
    *ppvStream = pvStream;
    if (!pvStream)
        return false;

    *pusVertexCount = m_usVertexCount;
    *piFormat = kRecord.m_iFormat;
    *piStride = kRecord.m_iArrayCapacity;
    *piUsage = kRecord.m_iUsage;

    if (kRecord.m_uiBuffer > m_usBufferCount)
        return false;
    A72720Buffer* pkBuffer = m_ppkBuffers[kRecord.m_uiBuffer];
    if (!pkBuffer || pkBuffer->m_uiSize < kRecord.m_uiValueBeforeCount)
        return false;

    *ppcData = pkBuffer->m_pcData + kRecord.m_uiValueBeforeCount;
    return true;
}
