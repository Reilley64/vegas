// bsmain/queuedfiles.cpp: QueuedFile, ObjectC3 (10 functions)

#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_00c3c590.h"
#include "fnv/decl/FUN_00c3d090_shell2.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/OwnArr.h"
#include "fnv/decl/Twin_00c3cf40.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "queuedfiles.h"

// @fnv 0x0043bde0
void QueuedFile::HandleChildCompletion(QueuedFile* apChild)
{
    ::FUN_0043be10((char *)(pChildren));
    OnChildCompletion();
}

struct BSFile;
struct BSFileEntry;
struct QueuedFileEntry : public QueuedFile
{
    virtual void __vslot_0();
    virtual unsigned char GetFileIndex();
    virtual void GenerateKey();
    char* GetFileName();
    void SetFileName(char*);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry*);
    void LookupFileEntry(int);
    BSFile* GetFile(int, int);
    void GetLookupFileName(int, char*);
    bool GetDescription(char*, unsigned int, char*);
    char* pFileName;
    BSFileEntry* m_pFileEntry;
};
struct FUN_00c3cee0_shell : public QueuedFileEntry
{
    void FUN_00c3cee0(char*);
};

struct MemoryManager
{
};
// Copies apName into a newly allocated buffer stored in pFileName, using strlen(apName)+1 bytes.
// @fnv 0x00c3cee0
void FUN_00c3cee0_shell::FUN_00c3cee0(char* apName)
{
    unsigned int uiLen;
    if (apName)
    {
        char* p;
        char* dst;
        uiLen = std::strlen(apName) + 1;
        p = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(uiLen);
        pFileName = p;
        dst = pFileName;
        fnv::crt::strcpy_s(dst, uiLen, apName);
    }
}

namespace fnv_00c3cf60 {
struct BSFile;
struct BSFileEntry;
struct QueuedFileEntry : public QueuedFile
{
    virtual void __vslot_0();
    virtual unsigned char GetFileIndex();
    virtual void GenerateKey();
    char* GetFileName();
    void SetFileName(char*);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry*);
    void LookupFileEntry(int);
    BSFile* GetFile(int, int);
    void GetLookupFileName(int, char*);
    bool GetDescription(char*, unsigned int, char*);
    char* pFileName;
    BSFileEntry* m_pFileEntry;
};
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
struct FUN_00c3cf60_shell : public QueuedFileEntry
{
    void LookupFileEntryByArchive(int);
};

struct ArchiveManager
{
};
// Builds the lookup file name for aeArchive, hashes it into directory and file hashes, queries ArchiveManager and stores the resulting BSFileEntry.
// @fnv 0x00c3cf60
void FUN_00c3cf60_shell::LookupFileEntryByArchive(int aeArchive)
{
    if (pFileName)
    {
        char acName[0x104];
        FileNameHash dirHash;
        FileNameHash fileHash;
        BSFileEntry* pEntry;
        reinterpret_cast<::FUN_00c3d090_shell2 *>(this)->FUN_00c3d090(aeArchive, acName);
        ::HashPathComponents(acName, (::FileNameHash *)(::fnv_00c3cf60::FileNameHash *)(&dirHash), (::FileNameHash *)(::fnv_00c3cf60::FileNameHash *)(&fileHash));
        pEntry = ((::fnv_00c3cf60::BSFileEntry *)(::fnv_00af6540::FindFileEntryInArchives(aeArchive, (::fnv_00af6540::FileNameHash &)(dirHash), (::fnv_00af6540::FileNameHash &)(fileHash), acName)));
        reinterpret_cast<::Twin_00c3cf40 *>(this)->SetD3DPixelShader((::GeometryRelatedType *const)(pEntry));
    }
}
}  // namespace fnv_00c3cf60

extern int DAT_010c1554;
struct P09QFBase
{
    void QueuedFile(int);
};
struct P09QFE
{
    P09QFE* InitQueuedFile(int aePriority);
};
// Calls QueuedFile with the priority, sets the vtable to DAT_010c1554, clears fields at offsets 0x28 and 0x2c, and returns this.
// @fnv 0x00c3ce60
P09QFE* P09QFE::InitQueuedFile(int aePriority)
{
    new ((void *)(((P09QFBase*)this))) ::FUN_00c3c590(aePriority);
    *(int**)this = &DAT_010c1554;
    *(char**)((char*)this + 0x28) = 0;
    *(void**)((char*)this + 0x2c) = 0;
    return this;
}

struct FUN_0063fa10
{
    virtual ~FUN_0063fa10();
};
struct QBase : FUN_0063fa10
{
    int pad[11];
    QBase(int);
};
struct FUN_00905ba0 : QBase
{
    int f30;
    int f34;
    int f38;
    FUN_00905ba0(int a, int b, const char* name);
};
// @fnv 0x00905ba0
FUN_00905ba0::FUN_00905ba0(int a, int b, const char* name) : QBase(0)
{
    f30 = b;
    f34 = 0;
    f38 = a;
    reinterpret_cast<::FUN_00c3cee0_shell *>(this)->FUN_00c3cee0((char *)(name));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>(this)->LookupFileEntryByArchive(4);
}

namespace fnv_00c3cea0 {
struct MemoryManager
{
};
struct FaceGenPaletteBase
{
    int pad[9];
    virtual ~FaceGenPaletteBase();
};
struct FUN_00c3cea0 : FaceGenPaletteBase
{
    char* pFileName;
    virtual ~FUN_00c3cea0();
};
// Destructor that frees the palette's file name buffer through the memory manager.
// @fnv 0x00c3cea0
FUN_00c3cea0::~FUN_00c3cea0()
{
    char* name = pFileName;
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c3cea0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(name);
}
}  // namespace fnv_00c3cea0

#include <windows.h>
struct PoolHolder
{
};

struct RefRelease
{
};

struct QueuedFileRef
{
    QueuedFile* m_pObject;

    QueuedFileRef(QueuedFile* p)
    {
        m_pObject = p;
        if (m_pObject != 0)
        {
            QueuedFile* t = m_pObject;
            InterlockedIncrement((LONG*)((char*)t + 8));
        }
    }

    ~QueuedFileRef()
    {
        if (m_pObject != 0)
        {
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(reinterpret_cast<RefRelease*>(m_pObject)));
        }
    }
};

struct ChildrenOps
{
    void* m_ppVirtualMethodTable;
    QueuedFileRef* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int unk10;

    unsigned int FUN_00c3d6c0();

    void FUN_00c3d4f0(const QueuedFileRef& pRef)
    {
        unsigned int iIndex;
        unsigned int iCount;
        unsigned int iReserved;
        unsigned int iGrow;
        unsigned int iNewReserved;
        unsigned int iBytes;
        unsigned int iOldCount;
        unsigned int i;
        QueuedFileRef* pOldBuffer;
        QueuedFileRef* pNewBuffer;
        QueuedFileRef* pBase;
        QueuedFileRef* pSlot;
        QueuedFile* pTmp;
        void* pRaw;

        iIndex = FUN_00c3d6c0();
        iCount = iSize;
        iOldCount = iCount;
        iReserved = SimpleArrayStorage;
        iGrow = 1024;
        iNewReserved = iReserved;
        pNewBuffer = 0;
        pOldBuffer = pBuffer;
        pRaw = 0;
        pBase = pOldBuffer + iIndex;
        for (i = 0; i < 1; i++)
        {
            pSlot = pBase + i;
            if (pSlot != 0)
            {
                pSlot->m_pObject = 0;
                pTmp = pSlot->m_pObject;
                if (pTmp != 0)
                {
                    InterlockedIncrement((LONG*)((char*)pTmp + 8));
                }
            }
        }
        if (iCount >= iReserved)
        {
            iNewReserved = iReserved + iGrow;
            iBytes = iNewReserved * 4;
            pNewBuffer = (QueuedFileRef*)pRaw;
        }
        iSize = iIndex + 1;
    }
};

struct FUN_00c3c4e0
{
    void* m_ppVirtualMethodTable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;

    FUN_00c3c4e0();
    static void* operator new(std::size_t size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::PoolHolder *>(&::g_memoryManager))))->FUN_00aa3e40(size);
    }
};

struct FUN_00c3c700_cls : public QueuedFile
{
    void FUN_00c3c700(QueuedFile* apChild);
};
// Stores apParent as this object's parent and, if non-null, registers this object as a child of that parent.
// @fnv 0x00443aa0
void QueuedFile::SetParent(QueuedFile* apParent)
{
    reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::NiPointer< ::QueuedFile> &)(m_pParent))->FUN_006f74f0((::ObjA *)(apParent));
    if (m_pParent)
        reinterpret_cast<::FUN_00c3c700_cls *>((((QueuedFile*)m_pParent)))->FUN_00c3c700(this);
}

// @fnv 0x00c3c700
void FUN_00c3c700_cls::FUN_00c3c700(QueuedFile* apChild)
{
    if (pChildren == 0)
    {
        pChildren = reinterpret_cast<QueuedChildren*>(new FUN_00c3c4e0);
    }
    reinterpret_cast<::OwnArr *>((reinterpret_cast<ChildrenOps*>(pChildren)))->FUN_00c3d4f0((const ::RefPtr &)((const ::QueuedFileRef &)(apChild)));
}

static __forceinline void DeadQ1()
{
    int dq[1];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ4()
{
    int dq[4];
}
static __forceinline void DeadQ5()
{
    int dq[5];
}
static __forceinline void DeadQ6()
{
    int dq[6];
}
static __forceinline void DeadQ7()
{
    int dq[7];
}
static __forceinline void DeadQ8()
{
    int dq[8];
}
static __forceinline void DeadQ9()
{
    int dq[9];
}
static __forceinline void DeadQ10()
{
    int dq[10];
}
static __forceinline void DeadQ11()
{
    int dq[11];
}

struct ObjectC3;
struct PointerC3
{
    ObjectC3* value;
    operator ObjectC3*() const
    {
        return value;
    }
    ObjectC3* operator->() const
    {
        return value;
    }
    PointerC3& operator=(ObjectC3*);
};
struct ArrayC3
{
    virtual ~ArrayC3();
    PointerC3* data;
    unsigned int size;
    unsigned int reserved;
    volatile unsigned int finished;
    unsigned int GetSize()
    {
        return size;
    }
    unsigned int GetFinished()
    {
        return finished;
    }
    PointerC3& GetAt(unsigned int i)
    {
        return data[i];
    }
};
struct ObjectC3
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void notify(ObjectC3*);
    int unk4;
    long refs;
    int state;
    int unk10, unk14, unk18;
    PointerC3 parent;
    ArrayC3* children;
    ArrayC3* parents;
    bool IsFinished()
    {
        return state >= 4;
    }
    bool AllFinished()
    {
        return children ? children->GetSize() == children->finished : true;
    }
    void AcquireReference()
    {
        InterlockedIncrement(&refs);
    }
    void NotifyParents();
};
inline PointerC3& PointerC3::operator=(ObjectC3* rhs)
{
    if (value != rhs)
    {
        if (value)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(value));
        value = rhs;
        if (value)
            value->AcquireReference();
    }
    return *this;
}
// When a parent pointer exists and this object and its children are finished, notifies the parent pointers, deletes the parents array, then calls FUN_0044dd60().
// @fnv 0x00c3c930
void ObjectC3::NotifyParents()
{
    if ((parent || parents) && IsFinished() && AllFinished())
    {
        AcquireReference();
        if (parent)
        {
            parent->notify(this);
            DeadQ3();
            parent = 0;
        }
        if (parents)
        {
            for (unsigned int i = 0; i < parents->GetSize(); i++)
            {
                ObjectC3* obj = parents->GetAt(i);
                obj->notify(this);
                DeadQ3();
            }
            delete parents;
            parents = 0;
        }
        ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)this);
    }
}


struct FUN_00c3d440_src
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_flags0c;
};

struct IdParts
{
    unsigned char unk0;
    unsigned char b;
    unsigned short word;
};

struct FUN_00c3d440_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual unsigned char GetFlagByte();

    int unk04x;
    __int64 m_uiFilterValue;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    FUN_00c3d440_src* m_pSrc;

    void FUN_0043db70();
    void FUN_00c3d440();
};

// @fnv 0x00c3d440
void FUN_00c3d440_cls::FUN_00c3d440()
{
    if (m_pSrc != 0)
    {
        IdParts id;
        id.word = (unsigned short)InterlockedIncrement(&(*reinterpret_cast<long *>(&::fnv_0043dc10::DAT_01202d9c)));
        id.b = (unsigned char)(m_uiFilterValue >> 0x10);
        unsigned int flags = m_pSrc->m_flags0c & 0x7fffffffu;
        signed char sb = (signed char)GetFlagByte();
        unsigned int tmp;
        unsigned int tmp2;
        m_uiFilterValue = ((__int64)sb << 0x38) | ((__int64)flags << 0x18) | ((__int64)id.b << 0x10) | (__int64)id.word;
    }
    else
    {
        FUN_0043db70();
    }
}

#include "generated/data/bsmain/queuedfiles.inc"
