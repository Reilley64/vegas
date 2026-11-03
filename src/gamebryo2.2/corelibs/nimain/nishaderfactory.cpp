// gamebryo2.2/corelibs/nimain/nishaderfactory.cpp: NiShaderFactory, NiRefObject (11 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa00d0.h"
#include "fnv/decl/FUN_00e89760_Class.h"
#include "fnv/decl/HashTableBase.h"
#include "fnv/decl/Map.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "nishaderfactory_types.h"

// @fnv 0x00a9fff0
NiShaderFactory* __cdecl NiShaderFactory::GetInstance()
{
    return (*reinterpret_cast<::NiShaderFactory * *>(&::DAT_011f6044));
}

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct FUN_00aa06c0
{
    void FUN_00aa05a0();
    FUN_00aa06c0* FUN_00aa06c0_impl(unsigned int flags);
};
struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct Direct3DDeviceInterface;
struct NiD3DShaderProgramCreator;
struct NiGeometry;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiShaderConstantMapEntry;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct ShaderPassRenderer;
struct GraphicsRenderer;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;
struct NiGPUProgram : public NiRefObject
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiNode* IsSceneNode();
    virtual BSFadeNode* IsFadeNode();
    virtual BSMultiBoundNode* IsMultiBoundNode();
    virtual NiGeometry* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    virtual NiTriStrips* IsTriStrips();
    virtual NiTriShape* IsTriShape();
    virtual BSSegmentedTriShape* IsSegmentedTriShape();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual NiParticles* IsParticlesGeom();
    virtual NiLines* IsLineGeometry();
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();
    virtual bhkRigidBody* IsBhkRigidBody();
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();
    virtual unsigned int GetNumberOfVariables();
    virtual char* GetVariableName(unsigned int);
    bool IsExactKindOf(void*);
    static bool IsExactKindOf(void*, void*);
    bool IsKindOfType(void*);
    static bool IsKindOfType(void*, void*);
    NiGPUProgram* DynamicCast(void*);
    static NiGPUProgram* DynamicCast(void*, void*);
    int GetProgramType();
    int m_iProgramType;
};
struct NiD3DShaderProgram : public NiGPUProgram
{
    virtual void __vslot_0();
    virtual char* GetName();
    virtual void SetName(char*);
    virtual char* GetProgramProfile();
    virtual void SetShaderProfile(char*);
    virtual unsigned int GetCodeSize();
    virtual void* GetCode();
    virtual void SetProgramCode(unsigned int, void*);
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void SetCreator(NiD3DShaderProgramCreator*);
    virtual bool SetShaderConstant(NiShaderConstantMapEntry*, void*, unsigned int);
    virtual bool SetShaderConstantArray(NiShaderConstantMapEntry*, void*, unsigned int, unsigned int, unsigned short*);
    virtual void* GetRTTI();
    void SetD3DDevice(Direct3DDeviceInterface*);
    void SetD3DRenderState(ShaderPassRenderer*);
    void SetShaderObject(GraphicsRenderer*);
    void SetVertexShaderConstant(int, int, float*);
    void SetPixelShaderConstant(int, int, float*);
    char* m_pcProgramName;
    char* m_pcProfile;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};
struct FUN_00e89830_shell : public NiD3DShaderProgram
{
    void* FUN_00e89830();
};

// @fnv 0x00e89830
void* FUN_00e89830_shell::FUN_00e89830()
{
    return (void*)&(*reinterpret_cast<const char *const *>(&::g_0126f9a4));
}

struct NiFileHack
{
};
int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);
// @fnv 0x00aa19e0
unsigned int __cdecl FUN_00aa19e0(NiFile* apFile, void* apBuffer, unsigned int auiSize, void* apArg4, void* apArg5)
{
    if (auiSize <= 0)
        return 0;
    unsigned int r = reinterpret_cast<::NiFile *>((((NiFileHack*)apFile)))->FileRead(apBuffer, auiSize);
    SwapBufferBySizes(apBuffer, auiSize, apArg4, apArg5);
    return r;
}


struct ShaderConstantMap : NiTFixedStringMap_NiGlobalConstantEntry___
{
};

struct ShaderFactorySlot : NiShaderFactory
{
    static NiShaderFactory*& Get()
    {
        return (*reinterpret_cast<::NiShaderFactory * *>(&::DAT_011f6044));
    }
};

struct NiGlobalConstantEntryView : NiRefObject
{
    unsigned int unk08;
    unsigned int unk0C;
};

struct NiGlobalConstantEntryStub
{
};

void* __cdecl FUN_00aa13e0(unsigned int uiSize);

// @fnv 0x00aa0400
bool __cdecl AcquireGlobalConstantEntry(const NiFixedString* pkName, unsigned int a2, unsigned int a3, uintptr_t a4)
{
    if (ShaderFactorySlot::Get() == 0)
        return false;
    NiShaderFactory* pkFactory = ShaderFactorySlot::Get();
    NiFixedString kLocal;
    NiTMapItem<NiFixedString, NiGlobalConstantEntry*>* pkItem =
        pkFactory->m_kGlobalConstantEntryMap
            .m_ppkHashTable[(uintptr_t)pkName->m_kHandle % pkFactory->m_kGlobalConstantEntryMap.m_uiHashSize];
    while (pkItem != 0)
    {
        if ((uintptr_t)pkName->m_kHandle == (uintptr_t)pkItem->m_key.m_kHandle)
        {
            NiGlobalConstantEntryView* pkEntry = (NiGlobalConstantEntryView*)pkItem->m_val;
            if (pkEntry == 0)
                break;
            if (pkEntry->unk0C != a2)
                return false;
            InterlockedIncrement((long*)&pkEntry->m_uiRefCount);
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }

    void* pvMem = FUN_00aa13e0(0x18);
    if (pvMem == 0)
        return false;
    uintptr_t uiKey = (uintptr_t)pkName->m_kHandle;
    NiGlobalConstantEntry* pkNew = ((::NiGlobalConstantEntry *)(new ((void *)(((NiGlobalConstantEntryStub*)pvMem))) ::FUN_00aa00d0((const char *)(uiKey), a2, a3, (const void *)(a4))));
    if (pkNew == 0)
        return false;

    InterlockedIncrement((long*)&((NiRefObject*)pkNew)->m_uiRefCount);
    if (pkName->m_kHandle != ::DAT_0109b220)
        InterlockedIncrement((long*)(pkName->m_kHandle - 8));

    char* pcHandle = pkName->m_kHandle;
    NiShaderFactory* pkMapOwner = ShaderFactorySlot::Get();
    kLocal.m_kHandle = pcHandle;
    reinterpret_cast<::Map *>((((ShaderConstantMap*)&pkMapOwner->m_kGlobalConstantEntryMap)))->FUN_00a6e980((*(const ::Key *)(&kLocal)), pkNew);

    if (pcHandle != ::DAT_0109b220)
        InterlockedDecrement((long*)(pcHandle - 8));
    return true;
}

struct SpawnedArgBase : public NiRefObject
{
    int m_iArg08;
    SpawnedArgBase(int a2) throw()
    {
        m_iArg08 = a2;
    }
};

struct FUN_00e897d0 : public SpawnedArgBase
{
    virtual ~FUN_00e897d0() throw();
    virtual void DeleteThis();
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    FUN_00e897d0(intptr_t a1, int a2) throw();
};

// Constructs the object from a base argument and a1, zeroes eight fields, then calls Init(a1).
// @fnv 0x00e897d0
FUN_00e897d0::FUN_00e897d0(intptr_t a1, int aiArg) throw() : SpawnedArgBase(aiArg)
{
    m_unk0C = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    reinterpret_cast<::FUN_00e89760_Class *>(this)->FUN_00e89760((::NiConsoleRendererStub *)(a1));
}

inline NiRefObject::~NiRefObject()
{
    NiAtomicSubtract(ms_lObjectCount);
}

void NiFree(void* p) throw();


struct FixedStr
{
    char* m_kHandle;
    FixedStr()
    {
        m_kHandle = ::DAT_0109b220;
    }
    ~FixedStr()
    {
        if (m_kHandle != ::DAT_0109b220)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }
};

struct GlobalConstantEntry;
struct GlobalConstantItem
{
    GlobalConstantItem* m_pkNext;
    FixedStr m_key;
    GlobalConstantEntry* m_val;
};

struct GlobalConstantMapBase
{
    unsigned int m_uiHashSize;
    GlobalConstantItem** m_ppkHashTable;
    unsigned int m_uiCount;

    virtual ~GlobalConstantMapBase()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    void RemoveAll() throw();
    void GetNext(void*& rkPos, FixedStr& rkKey, GlobalConstantEntry*& rkVal) const throw();
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
};

struct GlobalConstantMap : public GlobalConstantMapBase
{
    virtual ~GlobalConstantMap()
    {
        RemoveAll();
    }
};


struct FUN_00aa05a0 : public NiRefObject
{
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void ReleaseAllLibraries() throw();
    virtual void v9() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void ClearLibraries() throw();

    GlobalConstantMap m_kGlobalConstantEntryMap;
    void* m_pFindGlobalConstantEntry;
    void* GlobalConstantEntryRegistry;
    void* GlobalConstantMapContext;


    virtual ~FUN_00aa05a0() throw();
};
// @fnv 0x00aa06c0
FUN_00aa06c0* FUN_00aa06c0::FUN_00aa06c0_impl(unsigned int flags)
{
    reinterpret_cast<::FUN_00aa05a0 *>(this)->FUN_00aa05a0::~FUN_00aa05a0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x24);
    return this;
}

// @fnv 0x00aa05a0
FUN_00aa05a0::~FUN_00aa05a0() throw()
{
    if ((*reinterpret_cast<::FUN_00aa05a0 * *>(&::DAT_011f6044)))
        (*reinterpret_cast<::FUN_00aa05a0 * *>(&::DAT_011f6044))->ReleaseAllLibraries();
    if ((*reinterpret_cast<::FUN_00aa05a0 * *>(&::DAT_011f6044)))
        (*reinterpret_cast<::FUN_00aa05a0 * *>(&::DAT_011f6044))->ClearLibraries();

    void* pos = m_kGlobalConstantEntryMap.GetFirstPos();
    while (pos)
    {
        FixedStr kName;
        GlobalConstantEntry* pkEntry = 0;
        m_kGlobalConstantEntryMap.GetNext(pos, kName, pkEntry);
        if (pkEntry)
            ::RemoveGlobalConstant((const ::NiFixedString *)(char **)(&kName.m_kHandle));
    }

    if ((*reinterpret_cast<::FUN_00aa05a0 * *>(&::DAT_011f6044)) == this)
        (*reinterpret_cast<::FUN_00aa05a0 * *>(&::DAT_011f6044)) = 0;
}

// @fnv 0x00a38de0
int FUN_00a38de0(int unk08)
{
    return 0;
}

extern int DAT_010a2148;

typedef int(* FUN_00aa0190_Decrement)(void*);
extern FUN_00aa0190_Decrement DAT_00fdf1c4;

void __cdecl FUN_00aa10f0(void* p);
void __cdecl FUN_00aa1460(void* p, unsigned int size);

struct FUN_00aa0190_Obj
{
    int* vptr;
    int unk04;
    void* unk08;
    int unk0C;
    int unk10;
    void* unk14;

    void* Destroy(int flag);
};

// @fnv 0x00aa0190
void* FUN_00aa0190_Obj::Destroy(int aiFlags)
{
    void* saved = unk14;
    vptr = &DAT_010a2148;
    FUN_00aa10f0(saved);

    void* head = unk08;
    FUN_00aa0190_Decrement decrement = DAT_00fdf1c4;
    if (head != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
    {
        decrement(static_cast<char*>(head) - 8);
    }

    vptr = &DAT_0101dce4;
    decrement(&(*reinterpret_cast<int *>(&::NiRefObject::ms_lObjectCount)));

    if ((aiFlags & 1) != 0)
    {
        FUN_00aa1460(this, 0x18);
    }

    return this;
}

// Returns 0 regardless of its three arguments.
// @fnv 0x00b57fc0
int FUN_00b57fc0(int arg0, int arg1, int arg2)
{
    return 0;
}


struct Stub
{
};

// Finds the global constant entry for pkName in the shader factory, decrements its ref count, and deletes it when it reaches zero.
// @fnv 0x00aa04e0
bool RemoveGlobalConstant(const NiFixedString* pkName)
{
    NiShaderFactory* pkFactory = ShaderFactorySlot::Get();
    if (pkFactory == 0)
        return false;

    uintptr_t uiKey = (uintptr_t)pkName->m_kHandle;
    ShaderConstantMap* pkMap = (ShaderConstantMap*)&pkFactory->m_kGlobalConstantEntryMap;
    NiTMapItem<NiFixedString, NiGlobalConstantEntry*>* pkItem = pkMap->m_ppkHashTable[uiKey % pkMap->m_uiHashSize];
    NiRefObject* pkEntry = 0;
    while (pkItem != 0)
    {
        if (uiKey == (uintptr_t)pkItem->m_key.m_kHandle)
        {
            pkEntry = (NiRefObject*)pkItem->m_val;
            break;
        }
        pkItem = pkItem->m_pkNext;
    }
    if (pkEntry == 0)
        return false;

    if (pkName->m_kHandle != ::DAT_0109b220)
        InterlockedIncrement((long*)(pkName->m_kHandle - 8));
    pkFactory = ShaderFactorySlot::Get();

    NiFixedString kLocal;
    char* pcHandle = pkName->m_kHandle;
    kLocal.m_kHandle = pcHandle;
    if (pkEntry->m_uiRefCount == 1)
    {
        reinterpret_cast<::HashTableBase *>((((Stub*)&pkFactory->m_kGlobalConstantEntryMap)))->FUN_00aa0250((const unsigned int *)(::NiFixedString *)(&kLocal));
        if (InterlockedDecrement((long*)&pkEntry->m_uiRefCount) == 0)
            pkEntry->DeleteThis();
    }
    else
    {
        if (InterlockedDecrement((long*)&pkEntry->m_uiRefCount) == 0)
            pkEntry->DeleteThis();
    }

    if (pcHandle != ::DAT_0109b220)
        InterlockedDecrement((long*)(pcHandle - 8));
    return true;
}
