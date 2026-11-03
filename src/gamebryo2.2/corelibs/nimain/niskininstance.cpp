// gamebryo2.2/corelibs/nimain/niskininstance.cpp: NiSkinInstance, SkinGraph, NiSkinInstanceStub, SkinInstanceW and more (8 functions)

#include <cstdint>
#include <cstdlib>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/CloneObject.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/NiSkinData.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a86000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f5000.h"
#include "niskininstance_decls.h"
// @fnv 0x00a86340
void NiSkinInstance::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream));
    reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    if (stream.m_uiNifVersion >= 0x0a010065)
        reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    reinterpret_cast<::S_00a64670_Foo *>(&(stream))->FUN_00a64670();
}
// @fnv 0x00a86380
void NiSkinInstance::LinkObject(NiStream& stream)
{
    ::FUN_00a89af0((intptr_t)this);
    m_pSkinData = stream.GetLoadedObject();
    if (stream.m_uiNifVersion >= 0x0a010065)
        m_pkSkinMeshPartition = stream.GetLoadedObject();
    m_pRootParent = stream.GetLoadedObject();
    unsigned int count = reinterpret_cast<::FUN_00a63460_shell *>(&(stream))->FUN_00a63460();
    m_ppBones = (NiObject**)::FUN_00aa1070(count * sizeof(NiObject*));
    for (unsigned int i = 0; i < count; ++i)
        m_ppBones[i] = stream.GetLoadedObject();
}

struct A46BB0Object
{
};

struct FUN_00a864d0_Class
{
    char pad[8];
    void* m_pSkinData;            // +0x08
    void* m_pkSkinMeshPartition;  // +0x0c
    bool FUN_00a864d0(A46BB0Object* pkObject);
};

// @fnv 0x00a864d0
bool FUN_00a864d0_Class::FUN_00a864d0(A46BB0Object* pkObject)
{
    FUN_00a864d0_Class* pkSkinInstance = (FUN_00a864d0_Class*)pkObject;
    if (!reinterpret_cast<::A5d470Class *>((((A46BB0Object*)this)))->IsSameAs((::A5d470Object *)(pkObject)))
        return false;
    void* pData = this->m_pSkinData;
    void* pOtherData = pkSkinInstance->m_pSkinData;
    if (!((bool(*)(void*, void*))((void**)*(void**)pData)[0x5c / 4])(pData, pOtherData))
        return false;
    void* pThisPart = this->m_pkSkinMeshPartition;
    if (pThisPart)
    {
        void* pOtherPart = pkSkinInstance->m_pkSkinMeshPartition;
        if (!((bool(*)(void*, void*))((void**)*(void**)pThisPart)[0x5c / 4])(pThisPart, pOtherPart))
            return false;
    }
    if (this->m_pkSkinMeshPartition == 0 && pkSkinInstance->m_pkSkinMeshPartition != 0)
        return false;
    return true;
}

class NiStream;
struct SkinGraph
{
    void* vtable;
    unsigned int refCount;
    NiObject* skinData;
    NiObject* skinPartition;
    NiObject* rootParent;
    NiObject** bones;
    bool FUN_00a5d2f0(NiStream&);
    bool VisitSkinGraphLinks(NiStream& stream);
};
typedef void(* VisitStreamable)(NiObject*, NiStream&);
__forceinline void VisitLinkedObject(NiObject* object, NiStream& stream)
{
    void** methods = *reinterpret_cast<void***>(object);
    reinterpret_cast<VisitStreamable>(methods[21])(object, stream);
}
// @fnv 0x00a86460
bool SkinGraph::VisitSkinGraphLinks(NiStream& stream)
{
    if (!FUN_00a5d2f0(stream))
        return false;
    VisitLinkedObject(skinData, stream);
    if (skinPartition)
        VisitLinkedObject(skinPartition, stream);
    VisitLinkedObject(rootParent, stream);
    unsigned int count = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(skinData) + 0x44);
    for (unsigned int index = 0; index < count; ++index)
    {
        VisitLinkedObject(bones[index], stream);
    }
    return true;
}

class NiSkinDataLink : public NiObject
{
  public:
    NiPointer<NiObject> m_spLink;
};

class NiPtrAssignHelper
{
  public:
    NiObject* p;
    void Assign(NiObject* value);
};

class FUN_00a86740_cls : public NiSkinInstance
{
  public:
    void ClearSkinDataLink(NiStream& stream);
};

// @fnv 0x00a86740
void FUN_00a86740_cls::ClearSkinDataLink(NiStream& stream)
{
    if (stream.m_uiNifVersion >= 0xa010065)
    {
        return;
    }
    if (m_pSkinData.p == 0)
    {
        return;
    }
    NiSkinDataLink* data = (NiSkinDataLink*)m_pSkinData.p;
    reinterpret_cast<NiPtrAssignHelper*>(&m_pkSkinMeshPartition)->Assign(data->m_spLink.p);
    NiPointer<NiObject>& rSkinLink = ((NiSkinDataLink*)m_pSkinData.p)->m_spLink;
    if (rSkinLink.p != 0)
    {
        rSkinLink = 0;
    }
}


struct NiAVObjectStub;

struct NiCloneMapStub
{
};

struct NiCloningProcessStub
{
    NiCloneMapStub* m_pCloneMap;
};

struct NiSkinDataStub
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned int m_uiBoneCount;
};

struct NiObjectBaseStub
{
    NiObjectBaseStub() throw();
    virtual ~NiObjectBaseStub();
    unsigned int m_uiRefCount;
};

struct NiSkinInstanceStub : NiObjectBaseStub
{
    NiSkinInstanceStub()
        : m_pkSkinData(0), m_pkSkinPartition(0), m_pRootParent(0), m_ppBones(0), m_uiRendererFlags(0xffffffff),
          PopulateViewerStrings(0), unk20(0), unk24(0), unk28(0), unk30(0)
    {}
    virtual ~NiSkinInstanceStub();
    static void* operator new(size_t uiSize);

    NiSkinDataStub* m_pkSkinData;
    void* m_pkSkinPartition;
    NiAVObjectStub* m_pRootParent;
    NiAVObjectStub** m_ppBones;
    unsigned int m_uiRendererFlags;
    void* PopulateViewerStrings;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;

    NiSkinInstanceStub* FUN_00a86830(NiCloningProcessStub& kCloning);
};

// Clones the skin instance when cloneable, remapping the skin root and bone objects through the cloning map and copying the bone pointer array.
// @fnv 0x00a86830
NiSkinInstanceStub* NiSkinInstanceStub::FUN_00a86830(NiCloningProcessStub& kCloning)
{
    if (!reinterpret_cast<::NiSkinData *>(this)->MapSkinData((::SkinMapContext &)(kCloning)))
        return this;

    NiSkinInstanceStub* pkClone = new NiSkinInstanceStub;
    reinterpret_cast<::CloneObject *>(this)->CopyRefCountedPointers((::CloneObject *)(pkClone), (void *)&(kCloning));

    NiAVObjectStub* pkClonedObject = 0;
    pkClone->m_pRootParent =
        reinterpret_cast<::A54440Hash *>((void *)(kCloning.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)(m_pRootParent), (::A54440Manager **)&(pkClonedObject)) ? pkClonedObject : m_pRootParent;

    unsigned int uiBones = m_pkSkinData->m_uiBoneCount;
    pkClone->m_ppBones = (NiAVObjectStub**)::FUN_00aa1070(uiBones * sizeof(NiAVObjectStub*));
    for (unsigned int i = 0; i < uiBones; i++)
    {
        pkClone->m_ppBones[i] =
            reinterpret_cast<::A54440Hash *>((void *)(kCloning.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)(m_ppBones[i]), (::A54440Manager **)&(pkClonedObject)) ? pkClonedObject : m_ppBones[i];
    }
    return pkClone;
}

class NiBinaryStreamW
{
  public:
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStreamW*, const void*, unsigned int, unsigned int*, unsigned int);

    void Write(const void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = uiBytes;
        BinaryWrite(pvBuffer, uiBytes, &uiSize, 1);
    }
    void BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                     unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
    }
};

class NiStreamW
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual void Vf18();
    virtual void Vf1c();
    virtual void Vf20();
    virtual void Vf24();
    virtual void Vf28();
    virtual void Vf2c();
    virtual void SaveLinkID(const NiObject* pkObject);
    char m_pad04[0x250 - 4];
    NiBinaryStreamW* m_pBackingStream;
};

inline void SerializeValue(NiStreamW& kStream, const unsigned int& uiValue)
{
    kStream.m_pBackingStream->Write(&uiValue, sizeof(unsigned int));
}

struct NiSkinDataW
{
    char m_pad00[0x44];
    unsigned int m_uiBoneCount;
};

class SkinInstanceW
{
  public:
    void SaveSkinInstance(NiStreamW& kStream);

    void* m_pvVtbl;
    unsigned int m_uiRefCount;
    NiSkinDataW* m_pSkinData;
    NiObject* m_pkSkinMeshPartition;
    NiObject* m_pRootParent;
    NiObject** m_ppBones;
};

// Writes the skin instance's link IDs, bone count and each bone's link ID to the stream.
// @fnv 0x00a867a0
void SkinInstanceW::SaveSkinInstance(NiStreamW& kStream)
{
    ::FUN_00a89af0((intptr_t)this);
    kStream.SaveLinkID((NiObject*)m_pSkinData);
    kStream.SaveLinkID(m_pkSkinMeshPartition);
    kStream.SaveLinkID(m_pRootParent);
    unsigned int uiBones = m_pSkinData->m_uiBoneCount;
    SerializeValue(kStream, uiBones);
    for (unsigned int i = 0; i < uiBones; i++)
        kStream.SaveLinkID(m_ppBones[i]);
}

#include <string.h>
#include <stdio.h>
struct Strings
{
    void* vtable;
    char** data;
    unsigned short capacity, size, count, grow;
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + grow);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
    __forceinline void AddInline(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + grow);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (value)
                ++count;
        }
        else if (value)
        {
            if (!data[index])
                ++count;
        }
        else
        {
            if (data[index])
                --count;
        }
        data[index] = value;
    }
};
struct Named
{
    void* vtable;
    unsigned int refs;
    char* name;
    char* GetName()
    {
        return name;
    }
};
struct Partition : Named
{
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    unsigned int bones;
};
struct Root
{
    unsigned int refs;
    char* name;
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void Describe(Strings*);
};
struct BonePtr
{
    Named* p;
    operator Named*&()
    {
        return p;
    }
    Named*& operator->()
    {
        return p;
    }
};
struct Skin
{
    void* vtable;
    unsigned int refs;
    Partition* skin;
    Root* partition;
    Named* parent;
    BonePtr* bones;
    void FUN_00a86920(Strings*);
};
// Adds skin and parent labels, hardware partition and bone count values, sorted bone labels, then calls partition->Describe.
// @fnv 0x00a86920
void Skin::FUN_00a86920(Strings* apStrings)
{
    reinterpret_cast<::A5D6E0This *>((apStrings))->AppendCameraPathEntries({});
    apStrings->Add(::FUN_00a7d330((*reinterpret_cast<char * *>(&::g_011f5b2c))));
    if (parent)
        apStrings->Add(::fnv_00a7d5e0::FUN_00a7d5e0("Root Parent", parent->GetName()));
    Partition* pPartition = skin;
    if (pPartition)
    {
        uintptr_t partitions = (uintptr_t)partition;
        if (partitions)
            partitions = (uintptr_t)partition->name;
        apStrings->Add(FUN_00a7d510("Hardware partitions", partitions));
        unsigned int uiBoneCount = pPartition->bones;
        apStrings->Add(FUN_00a7d510("Bone Count", uiBoneCount));
        char** ppBoneNames = (char**)::FUN_00aa1070(uiBoneCount * sizeof(char*));
        char szBoneName[1000];
        for (unsigned int index = 0; index < uiBoneCount; ++index)
        {
            sprintf(szBoneName, "%s (%08X)", bones[index]->GetName(), bones[index]);
            ppBoneNames[index] = (char*)::FUN_00aa1070(strlen(szBoneName) + 1);
            strcpy(ppBoneNames[index], szBoneName);
        }
        std::qsort(ppBoneNames, uiBoneCount, 4, ((int (&)(const void *, const void *))::FUN_00a86280));
        for (unsigned int index = 0; index < uiBoneCount; ++index)
        {
            char szIndex[10];
            ::NiSprintf(szIndex, 10, "  %3d", index);
            apStrings->AddInline(::fnv_00a7d5e0::FUN_00a7d5e0(szIndex, ppBoneNames[index] ? ppBoneNames[index] : "<noname>"));
        }
        for (unsigned int index = 0; index < uiBoneCount; ++index)
            ::FUN_00aa10f0(ppBoneNames[index]);
        ::FUN_00aa10f0(ppBoneNames);
        partition->Describe(apStrings);
    }
}
