// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramfactory.cpp: NiD3DShaderProgramFactory, ProgFactoryDirs, ShaderEntryOwner (26 functions)

#include <cstdint>
#include <new>
#include <windows.h>
#include <cctype>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/list_node.h"
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/AlphaList.h"
#include "fnv/decl/BSShaderLightingProperty.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_00e93540_Map.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/decl/Tbl00b57f20.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e93000.h"
#include "fnv/symbols_00e98000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "nid3dshaderprogramfactory_packet.h"
#include "fnv/symbols_00e92000.h"
// @fnv 0x00e93000
const char* NiD3DShaderProgramFactory::GetNextName(void*& apPosition)
{
    DirectoryEntry* entry = static_cast<DirectoryEntry*>(apPosition);
    if (entry)
    {
        apPosition = entry->next;
        return entry->value;
    }
    return 0;
}
// @fnv 0x00e93e70
bool NiD3DShaderProgramFactory::RegisterCreator(const char* pcName, NiD3DShaderProgramCreator* creator)
{
    char lower[256];
    if (!pcName || ((const char *)(std::strchr((char *)(pcName), '.'))))
        return false;
    for (unsigned int i = 0; i < 256; ++i)
    {
        lower[i] = (char)tolower(pcName[i]);
        if (!pcName[i])
            break;
    }
    if (!(*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)))
        ::CreateCreatorMap();
    (*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14))->SetAt(lower, reinterpret_cast<NiShader*>(creator));
    return true;
}

struct Program;
// @fnv 0x00e92eb0
Program* FUN_00e92eb0()
{
    return DAT_0126fa10;
}

struct Program
{
    virtual void Destroy(int);
};
// @fnv 0x00e92ec0
void DestroyProgram()
{
    if (DAT_0126fa10)
        DAT_0126fa10->Destroy(1);
    DAT_0126fa10 = 0;
}

struct Nd
{
    Nd* next;
    int b;
    int data;
};
struct Lst
{
    int a;
    int b;
    Nd* head;
};
// @fnv 0x00e92fe0
int FUN_00e92fe0(Lst* l, int, Nd** apNext)
{
    Nd* n = l->head;
    *apNext = n;
    if (n)
    {
        *apNext = n->next;
        return n->data;
    }
    return 0;
}

// @fnv 0x00e93df0
void FUN_00e93df0()
{
    if ((*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)) == 0)
        ::CreateCreatorMap();
}


struct FUN_00e93f30_shell
{
    void* DestroyShaderProgramFactory(unsigned int flags);
};

struct ShaderBufferRecord;

struct NiTStringPointerMap_00e93060
{
};

struct NiD3DShaderProgramFactory_00e93060
{
    int m_auiShapeKeys[6];
    NiTStringPointerMap_00e93060* m_pShaderBufferMap;
    ShaderBufferRecord* FUN_00e93060(const char* pcShaderName);
};

// @fnv 0x00e93060
ShaderBufferRecord* NiD3DShaderProgramFactory_00e93060::FUN_00e93060(const char* pcShaderName)
{
    NiTStringPointerMap_00e93060* map = m_pShaderBufferMap;
    if (!map)
        return 0;
    ShaderBufferRecord* pkVertexShader = 0;
    if (reinterpret_cast<::A54440Hash *>((map))->FUN_00a53c30((::A54440Manager *)(pcShaderName), (::A54440Manager **)&(pkVertexShader)))
        return pkVertexShader;
    return 0;
}

struct P03MM
{
};
extern int DAT_010f0eb0;
extern int DAT_010f0f50;

// @fnv 0x00e93d80
void CreateCreatorMap()
{
    int* p = (int*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(0x14);
    if (p)
    {
        p[0] = (intptr_t)&DAT_010f0eb0;
        p[1] = 0x25;
        p[3] = 0;
        int* data = (int*)::FUN_00aa1070(0x94);
        p[2] = (intptr_t)data;
        std::memset((void*)data, 0, 4 * p[1]);
        *(char*)(p + 4) = 1;
        p[0] = (intptr_t)&DAT_010f0f50;
        (*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)) = (CreatorMap*)p;
    }
    else
    {
        (*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)) = 0;
    }
}

namespace fnv_00e92ee0 {
struct NiD3DVertexShader;
struct NiD3DShaderProgramCreator
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool Recreate(NiD3DVertexShader* pkVertexShader);
};
struct NiD3DVertexShader
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual int IsRecreated();
};
// If a global flag is set and pkVertexShader is non-null, returns true when already recreated, otherwise asks its creator to recreate it.
// @fnv 0x00e92ee0
bool __cdecl FUN_00e92ee0(NiD3DVertexShader* pkVertexShader)
{
    NiD3DShaderProgramCreator* pkCreator;
    if (DAT_0126fa10 && pkVertexShader)
    {
        if (pkVertexShader->IsRecreated())
            return true;
        pkCreator = pkVertexShader->GetCreator();
        if (pkCreator)
            return pkCreator->Recreate(pkVertexShader);
    }
    return false;
}
}  // namespace fnv_00e92ee0

struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93020
{
};
struct NiD3DShaderProgramFactory_00e93020
{
    int m_auiShapeKeys[5];
    NiTStringPointerMap_00e93020* m_pShaderBufferMap;
    ShaderBufferRecord* FUN_00e93020(const char* pcShaderName);
};
// @fnv 0x00e93020
ShaderBufferRecord* NiD3DShaderProgramFactory_00e93020::FUN_00e93020(const char* pcShaderName)
{
    if (!m_pShaderBufferMap)
        return 0;
    ShaderBufferRecord* pkPixelShader = 0;
    return reinterpret_cast<::A54440Hash *>((m_pShaderBufferMap))->FUN_00a53c30((::A54440Manager *)(pcShaderName), (::A54440Manager **)&(pkPixelShader)) ? pkPixelShader : 0;
}

struct FakeShader_00e93820
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual const char* GetName();
};
struct FUN_00e93820_shell
{
    int m_auiShapeKeys[6];
    NiTStringTemplateMap<NiTPointerMap<char const*, NiShader*>, NiShader*>* m_map;
    void RegisterShader(FakeShader_00e93820* p);
};
// If p and m_map are non-null, inserts p into m_map keyed by p->GetName().
// @fnv 0x00e93820
void FUN_00e93820_shell::RegisterShader(FakeShader_00e93820* apShader)
{
    if (apShader && m_map)
        m_map->SetAt(apShader->GetName(), (NiShader*)apShader);
}

struct Dealloc_00e93ab0
{
};
struct Owner_00e93ab0
{
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00e93ab0
void* Owner_00e93ab0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00e93540_Map *>(this)->FUN_00e93540();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((Dealloc_00e93ab0*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00e92f30 {
struct NiD3DPixelShader;
struct NiD3DShaderProgramCreator
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual bool Recreate(NiD3DPixelShader* pkPixelShader);
};
struct NiD3DPixelShader
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual int CanRecreate();
};
// Returns true if the pixel shader can be recreated or its creator successfully recreates it, otherwise false.
// @fnv 0x00e92f30
bool FUN_00e92f30(NiD3DPixelShader* pkPixelShader)
{
    NiD3DShaderProgramCreator* pkCreator;
    if (DAT_0126fa10 && pkPixelShader)
    {
        if (pkPixelShader->CanRecreate())
            return true;
        pkCreator = pkPixelShader->GetCreator();
        if (pkCreator)
            return pkCreator->Recreate(pkPixelShader);
    }
    return false;
}
}  // namespace fnv_00e92f30

struct ShaderArg
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual const char* GetKey();
};
struct FUN_00e937f0_shell
{
    int m_auiShapeKeys[5];
    NiTStringTemplateMap<NiTPointerMap<char const*, NiShader*>, NiShader*>* m_pTaskMap;
    void AddShader(ShaderArg* pkShader);
};
// If pkShader and the map are non-null, inserts pkShader into the map keyed by pkShader->GetKey().
// @fnv 0x00e937f0
void FUN_00e937f0_shell::AddShader(ShaderArg* pkShader)
{
    if (pkShader && m_pTaskMap)
        m_pTaskMap->SetAt(pkShader->GetKey(), (NiShader*)pkShader);
}

extern intptr_t DAT_0126fa18;
extern intptr_t DAT_0126fa1c;
extern intptr_t DAT_0126fa20;

// @fnv 0x00e92f70
void FUN_00e92f70(intptr_t param_1)
{
    DAT_0126fa1c = param_1;
    if (param_1 != 0)
    {
        int* piVar1 = *(int**)(param_1 + 0x288);
        if (DAT_0126fa18 != 0)
        {
            (**(void(**)(int))(*(void***)DAT_0126fa18 + 2))(DAT_0126fa18);
        }
        DAT_0126fa18 = (intptr_t)piVar1;
        if (piVar1 != 0)
        {
            (**(void(**)(int*))(*(intptr_t*)piVar1 + 4))(piVar1);
        }
        DAT_0126fa20 = *(int*)(DAT_0126fa1c + 0x8b8);
        return;
    }
    DAT_0126fa20 = 0;
    if (DAT_0126fa18 != 0)
    {
        (**(void(**)(int))(*(void***)DAT_0126fa18 + 2))(DAT_0126fa18);
    }
    DAT_0126fa18 = 0;
}

struct DirNode
{
    DirNode* m_pkNext;
    DirNode* m_pkPrev;
    char* m_element;
};
struct NodePoolView
{
    unsigned int m_uiCount;
    void* AddHead();
};
struct DirList
{
    void* vtbl;
    DirNode* m_pkHead;
    DirNode* m_pkTail;
    NodePoolView m_kItemCount;
    char*& GetNext(DirNode*& pos)
    {
        char*& e = pos->m_element;
        pos = pos->m_pkNext;
        return e;
    }
    void AddHead(char* e)
    {
        DirNode* n = (DirNode*)((void *)(reinterpret_cast<::FUN_0043a010_shell *>(&(m_kItemCount))->FUN_0043a010()));
        n->m_element = e;
        n->m_pkPrev = 0;
        n->m_pkNext = m_pkHead;
        if (m_pkHead)
            m_pkHead->m_pkPrev = n;
        else
            m_pkTail = n;
        m_kItemCount.m_uiCount++;
        m_pkHead = n;
    }
};
struct ProgFactoryDirs
{
    void* vtbl;
    DirList m_kDirs;
    void AddDirectory(const char* pcDir);
};
// Normalizes '/' to '\\' in pcDir, returns if it already exists in m_kDirs, otherwise allocates a copy and adds it to the head of the list.
// @fnv 0x00e93960
void ProgFactoryDirs::AddDirectory(const char* pcDir)
{
    if (!pcDir || strcmp(pcDir, "") == 0)
        return;
    char acDir[260];
    fnv::crt::strcpy_s(acDir, 260, pcDir);
    for (unsigned int i = 0; i < strlen(acDir); i++)
    {
        if (acDir[i] == '/')
            acDir[i] = '\\';
    }
    DirNode* pos = m_kDirs.m_pkHead;
    while (pos)
    {
        char* e = m_kDirs.GetNext(pos);
        if (e && ::NiStricmp(e, acDir) == 0)
            return;
    }
    unsigned int len = strlen(acDir) + 1;
    char* p = (char*)::FUN_00aa1070(len);
    fnv::crt::strcpy_s(p, len, acDir);
    m_kDirs.AddHead(p);
}

namespace fnv_00e93bb0 {
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" size_t __cdecl strlen(const char*);

struct BSBatchRenderer__GeometryGroup;

struct DirectoryEntryNode
{
    DirectoryEntryNode* next;
    DirectoryEntryNode* prev;
    const char* value;
};

struct BSBatchRenderer__AlphaList
{
    DirectoryEntryNode* head;
    DirectoryEntryNode* tail;
    unsigned int count;

    inline BSBatchRenderer__GeometryGroup* const& GetNext(DirectoryEntryNode*& pos) const
    {
        const char* const& item = pos->value;
        pos = pos->next;
        return (BSBatchRenderer__GeometryGroup* const&)item;
    }

};

struct NiD3DShaderProgramFactory_Shell
{
    int unk00;
    int unk04;
    BSBatchRenderer__AlphaList m_directories;

    void RemoveDirectoryEntry(const char* pcDirectory);
};

// Copies pcDirectory into a path buffer, converts '/' to '\\', then removes the matching entry from m_directories if found.
// @fnv 0x00e93bb0
void NiD3DShaderProgramFactory_Shell::RemoveDirectoryEntry(const char* pcDirectory)
{
    if (!pcDirectory || strcmp(pcDirectory, "") == 0)
        return;

    char acPath[260];
    fnv::crt::strcpy_s(acPath, 260, pcDirectory);

    for (unsigned int i = 0; i < strlen(acPath); i++)
    {
        if (acPath[i] == '/')
            acPath[i] = '\\';
    }

    DirectoryEntryNode* kPos = m_directories.head;
    while (kPos)
    {
        BSBatchRenderer__GeometryGroup* pcSearchDir = m_directories.GetNext(kPos);
        if (pcSearchDir && ::NiStricmp((const char*)pcSearchDir, acPath) == 0)
        {
            reinterpret_cast<::AlphaList *>(&(m_directories))->FUN_00e7db70((void *const *)&(pcSearchDir));
            break;
        }
    }
}
}  // namespace fnv_00e93bb0

extern int DAT_010f0f70;
extern int DAT_011f4400;
extern int(* DAT_00fdf1c4)(void*);

struct ShaderProgramStandIn_00e93e00
{
    virtual void vf00(int);
};

struct FUN_00e93cc0_Obj
{
    virtual void vf00();
};

struct FUN_00b71300_Obj
{
    virtual void vf00();
    int unk04;
};

struct FUN_00e93e00_Obj : public FUN_00e93cc0_Obj
{
    int unk04;
    FUN_00b71300_Obj unk08;
    int unk10;
    ShaderProgramStandIn_00e93e00* unk14;
    ShaderProgramStandIn_00e93e00* unk18;

    void FUN_00e93e00();
};
// @fnv 0x00e93f30
void* FUN_00e93f30_shell::DestroyShaderProgramFactory(unsigned int flags)
{
    NiD3DShaderProgramFactory* self = (NiD3DShaderProgramFactory*)this;
    static_cast<::FUN_00e93e00_Obj *>(nullptr)->FUN_00e93e00();
    if (flags & 1)
    {
        ::FUN_00aa1460(self, 0x1c);
    }
    return self;
}

class NiTMapBase
{
  public:
    void* m_pvVtbl;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;

    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    bool RemoveAt(const char* pcKey);
};

// Removes pkCreator from the global NiTMapBase at DAT_0126fa14 if found, iterating entries and calling RemoveAt on a matching key.
// @fnv 0x00e93260
void __cdecl FUN_00e93260(NiD3DShaderProgramCreator* pkCreator)
{
    if ((*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)) == 0)
        return;

    void* pvIter = ((NiTMapBase*)(*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)))->GetFirstPos();
    while (pvIter)
    {
        const char* pcExt = 0;
        NiD3DShaderProgramCreator* pkTestCreator = 0;
        reinterpret_cast<::Tbl00b57f20 *>((void *)(((NiTMapBase*)(*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)))))->AdvanceToNextEntry((::Ent00b57f20 **)&(pvIter), (int *)&(pcExt), (int *)&(pkTestCreator));
        if (pkCreator == pkTestCreator)
            ((NiTMapBase*)(*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)))->RemoveAt(pcExt);
    }
}

class NiShaderLibraryE93
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual FakeShader_00e93820* CreateShader(void* pkDesc, void* pkRenderer, const char* pcName, void* pvArg4,
                                              void* pvArg5, void* pvArg6);
};


// Returns the cached entry for pcName, or creates a shader with pkLibrary, registers it, and returns it.
// @fnv 0x00e938e0
void* __cdecl FUN_00e938e0(void* pkDesc, void* pkRenderer, const char* pcLibName, const char* pcName, void* pvArg4,
                           void* pvArg5, void* pvArg6)
{
    if (!DAT_0126fa10)
        return 0;
    if (!pkDesc || !pkRenderer)
        return 0;
    ShaderBufferRecord* pkEntry =
        reinterpret_cast<NiD3DShaderProgramFactory_00e93060*>(DAT_0126fa10)->FUN_00e93060(pcName);
    if (pkEntry)
        return pkEntry;
    NiShaderLibraryE93* pkLibrary = ((::NiShaderLibraryE93 *)(::fnv_00e932f0::FUN_00e932f0(pcLibName)));
    if (!pkLibrary)
        return 0;
    FakeShader_00e93820* pkShader = pkLibrary->CreateShader(pkDesc, pkRenderer, pcName, pvArg4, pvArg5, pvArg6);
    reinterpret_cast<FUN_00e93820_shell*>(DAT_0126fa10)->RegisterShader(pkShader);
    return pkShader;
}


class NiRefObject
{
  public:
    NiRefObject() throw()
    {
        m_uiRefCount = 0;
        InterlockedIncrement((long volatile*)&DAT_011f4400);
    }
    virtual ~NiRefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;
public:
    static unsigned int ms_lObjectCount;
};

class NiMemObject_00e93ad0
{
  public:
};

template <class TVAL> class ShaderMapBase : public NiMemObject_00e93ad0
{
  public:
    ShaderMapBase(unsigned int uiHashSize) throw()
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = (void**)::FUN_00aa1070(uiSize);
        std::memset(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
    }
    virtual ~ShaderMapBase();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

template <class TVAL> class ShaderStringTemplateMap : public ShaderMapBase<TVAL>
{
  public:
    ShaderStringTemplateMap(unsigned int uiHashSize, bool bCopy) throw() : ShaderMapBase<TVAL>(uiHashSize)
    {
        m_bCopy = bCopy;
    }
    virtual ~ShaderStringTemplateMap();

    bool m_bCopy;
};

template <class TVAL> class ShaderStringMap : public ShaderStringTemplateMap<TVAL>
{
  public:
    ShaderStringMap(unsigned int uiHashSize, bool bCopy) throw() : ShaderStringTemplateMap<TVAL>(uiHashSize, bCopy)
    {}
    virtual ~ShaderStringMap();
};

struct DirAllocator_00e93ad0
{
    unsigned int m_uiCount;
};

struct DirListItem_00e93ad0;

class DirList_00e93ad0
{
  public:
    DirList_00e93ad0() throw()
    {
        m_kItemCount.m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }

    DirListItem_00e93ad0* m_pkHead;
    DirListItem_00e93ad0* m_pkTail;
    DirAllocator_00e93ad0 m_kItemCount;
};

class NiD3DVertexShaderEntry;
class NiD3DPixelShaderEntry;

class FUN_00e93ad0 : public NiRefObject
{
  public:
    FUN_00e93ad0() throw();
    virtual ~FUN_00e93ad0();

    DirList_00e93ad0 m_kDirectoryList;
    ShaderStringMap<NiD3DVertexShaderEntry*>* m_pVertexShaderMap;
    ShaderStringMap<NiD3DPixelShaderEntry*>* m_pShaderBufferMap;
};

// Allocates string maps for NiD3DVertexShaderEntry and NiD3DPixelShaderEntry pointers, each with hash size 59 and copying disabled.
// @fnv 0x00e93ad0
FUN_00e93ad0::FUN_00e93ad0() throw()
{
    m_pVertexShaderMap = new ShaderStringMap<NiD3DVertexShaderEntry*>(59, false);
    m_pShaderBufferMap = new ShaderStringMap<NiD3DPixelShaderEntry*>(59, false);
}

struct ShaderEntryNode
{
    ShaderEntryNode* next;
    ShaderEntryNode* previous;
    void* element;
};
struct ShaderEntryList
{
    ShaderEntryNode* head;
    ShaderEntryNode* tail;
    unsigned int count;
    void*& GetNext(ShaderEntryNode*& position)
    {
        void*& element = position->element;
        position = position->next;
        return element;
    }
    void FUN_00b602d0();
    void FUN_00e7d5b0();
};
struct ShaderEntryNodePool
{
    void* first;
};
struct ShaderEntryOwner
{
    int unknown00;
    int unknown04;
    ShaderEntryList entries;
    void FUN_00e93cc0();
};
// @fnv 0x00e93e00
void FUN_00e93e00_Obj::FUN_00e93e00()
{
    *reinterpret_cast<intptr_t*>(this) = reinterpret_cast<intptr_t>(&DAT_010f0f70);

    if (unk14 != 0)
        reinterpret_cast<::S_00b601a0_Map *>((unk14))->FUN_00b601a0();

    if (unk14 != 0)
        unk14->vf00(1);

    if (unk18 != 0)
        reinterpret_cast<::S_00b601a0_Map *>((unk18))->FUN_00b601a0();

    if (unk18 != 0)
        unk18->vf00(1);

    reinterpret_cast<::ShaderEntryOwner *>(this)->FUN_00e93cc0();
    reinterpret_cast<::BSShaderLightingProperty *>(&(unk08))->ClearLights();

    *reinterpret_cast<intptr_t*>(this) = reinterpret_cast<intptr_t>(&DAT_0101dce4);
    DAT_00fdf1c4(&(*reinterpret_cast<int *>(&::NiRefObject::ms_lObjectCount)));
}
// Iterates nonnull elements, searches for matching list nodes, removes matches, and passes each element to FUN_00aa10f0.
// @fnv 0x00e93cc0
void ShaderEntryOwner::FUN_00e93cc0()
{
    ShaderEntryList* pEntries = &entries;
    ShaderEntryNode* pNode = pEntries->head;
    if (pNode)
    {
        do
        {
            void* element = pEntries->GetNext(pNode);
            if (!element)
                continue;
            ShaderEntryNode* head = pEntries->head;
            ShaderEntryNode* candidate;
            ShaderEntryNode* position = pEntries->head;
            if (!position)
                goto release;
            do
            {
                candidate = position;
                if (element == pEntries->GetNext(position))
                    goto found;
            } while (position);
            goto release;
        found:
            if (candidate)
            {
                if (candidate == head)
                    pEntries->FUN_00b602d0();
                else if (candidate == pEntries->tail)
                    pEntries->FUN_00e7d5b0();
                else
                {
                    ShaderEntryNode* pPrev = candidate->previous;
                    ShaderEntryNode* pNext = candidate->next;
                    if (pPrev)
                        pPrev->next = pNext;
                    if (pNext)
                        pNext->previous = pPrev;
                    candidate->element = 0;
                    candidate->previous = 0;
                    fnv::list::RecycleStorage(candidate);
                    --pEntries->count;
                }
            }
        release:
            ::FUN_00aa10f0(element);
        } while (pNode);
    }
}

namespace fnv_00e93850 {
class NiD3DShaderProgramCreator
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual ShaderArg* CreateShader(const char* p0, const char* p1, const char* p3, unsigned int p4, unsigned int p5,
                                    unsigned int p6, unsigned int p7, unsigned int p8, unsigned int p9);
};


// Returns a cached ShaderArg for p3, or creates one via the NiD3DShaderProgramCreator for p2 and registers it with the factory.
// @fnv 0x00e93850
ShaderArg* FUN_00e93850(const char* p0, const char* p1, const char* apCreatorName, const char* apShaderName,
                        unsigned int aiParam0, unsigned int aiParam1, unsigned int aiParam2, unsigned int aiParam3,
                        unsigned int aiParam4, unsigned int aiParam5)
{
    if (!DAT_0126fa10)
        return 0;

    if (!p0 || !p1)
        return 0;

    ShaderArg* pkShader = (ShaderArg*)((NiD3DShaderProgramFactory_00e93020*)DAT_0126fa10)->FUN_00e93020(apShaderName);
    if (pkShader)
        return pkShader;

    NiD3DShaderProgramCreator* pkCreator = ((::fnv_00e93850::NiD3DShaderProgramCreator *)(::fnv_00e932f0::FUN_00e932f0(apCreatorName)));
    if (!pkCreator)
        return (ShaderArg*)pkCreator;

    ShaderArg* pkNewShader =
        pkCreator->CreateShader(p0, p1, apShaderName, aiParam0, aiParam1, aiParam2, aiParam3, aiParam4, aiParam5);
    ((FUN_00e937f0_shell*)DAT_0126fa10)->AddShader(pkNewShader);
    return pkNewShader;
}
}  // namespace fnv_00e93850

bool __cdecl FUN_00aa1a30(const char* pcName, int eMode);
struct ShPF_Node
{
    ShPF_Node* m_pkNext;
    ShPF_Node* m_pkPrev;
    const char* m_element;
};
struct ShPF_Factory
{
    void* vt;
    int m4;
    ShPF_Node* m_pkHead;
    ShPF_Node* GetHeadPos() const
    {
        return m_pkHead;
    }
    const char*& GetNext(ShPF_Node*& kPos) const
    {
        const char*& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
    const char* GetFirstDir(ShPF_Node*& kIter) const
    {
        kIter = GetHeadPos();
        if (kIter)
            return GetNext(kIter);
        return 0;
    }
    const char* GetNextDir(ShPF_Node*& kIter) const
    {
        if (kIter)
            return GetNext(kIter);
        return 0;
    }
};
inline ShPF_Factory* ShPF_Get()
{
    return (ShPF_Factory*)DAT_0126fa10;
}
// Resolves a shader program file path by checking registered directories and returns true if the file exists.
// @fnv 0x00e930a0
bool FindShaderProgramFile(const char* pcShaderName, char* pcResolvedPath, unsigned int uiBufferLength)
{
    if (FUN_00aa1a30(pcShaderName, 0))
    {
        fnv::crt::strcpy_s(pcResolvedPath, uiBufferLength, pcShaderName);
        return true;
    }
    if (!ShPF_Get())
    {
        ::FUN_00aa0020(1, false, "No valid shader program factory\n");
        return false;
    }
    char acDrive[4];
    char acDir[260];
    char acFileName[260];
    char acExt[256];
    ::FUN_00e983f0(pcShaderName, acDrive, acDir, acFileName, acExt);
    ShPF_Node* kIter;
    const char* pcDir = ShPF_Get()->GetFirstDir(kIter);
    while (pcDir)
    {
        char valid = pcDir[0];
        if (valid)
        {
            if (pcDir[strlen(pcDir) - 1] != '/' && pcDir[strlen(pcDir) - 1] != '\\')
                ::NiSprintf(pcResolvedPath, uiBufferLength, "%s\\%s%s", pcDir, acFileName, acExt);
            else
                ::NiSprintf(pcResolvedPath, uiBufferLength, "%s%s%s", pcDir, acFileName, acExt);
        }
        else
        {
            ::FUN_00aa0020(1, false, "Invalid or no shader program directory\n");
        }
        if (valid)
        {
            if (FUN_00aa1a30(pcResolvedPath, 0))
                return true;
            ::FUN_00aa0020(1, true, "Shader program file not found %s in directory %s\n", pcShaderName, pcDir);
        }
        pcDir = ShPF_Get()->GetNextDir(kIter);
    }
    return false;
}

namespace fnv_00e932f0 {
struct FUN_00a53c30_Map
{
};


// Looks up a value in DAT_0126fa14 using the lowercased extension, or the filename when no extension is extracted.
// @fnv 0x00e932f0
void* __cdecl FUN_00e932f0(const char* pcFilename)
{
    char acFileExt[256];
    void* creator;
    const char* source;
    unsigned int index;

    if ((*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)) == 0)
        return 0;

    if (pcFilename == 0 || *pcFilename == 0)
        return 0;

    ::FUN_00e98430(pcFilename, acFileExt, 0x100);
    source = acFileExt + 1;
    if (acFileExt[1] == 0)
        source = pcFilename;
    for (index = 0; index < 0x100; ++index)
    {
        char converted = std::tolower(source[index]);
        acFileExt[index] = converted;

        if (converted == 0)
            break;
    }

    creator = 0;
    if (reinterpret_cast<::A54440Hash *>((((FUN_00a53c30_Map*)(*reinterpret_cast<::NiTStringTemplateMap< ::NiTPointerMap<const char *, ::NiShader *>, ::NiShader *> * *>(&::DAT_0126fa14)))))->FUN_00a53c30((::A54440Manager *)(acFileExt), (::A54440Manager **)&(creator)))
        return creator;

    return 0;
}
}  // namespace fnv_00e932f0

void DestroyProgram();
extern "C" void* __cdecl _fnv_zlib_memset(void* dst, int value, unsigned int size);

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
        int m_iData;
    };
    static LinkedListEntry* ms_pFreeList;
};
struct FUN_0045cee0_shell
{
    void FUN_0045cee0(void*);
};
// @fnv 0x0045cee0
void FUN_0045cee0_shell::FUN_0045cee0(void* pkItem)
{
    auto* node = static_cast<PoolAllocatorBase<unsigned int>::LinkedListEntry*>(pkItem);
    node->m_iData = 0;
    fnv::list::RecycleStorage(node);
}
#include "generated/data/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramfactory.inc"
