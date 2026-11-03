#include <cstddef>
// bsshader/bsshaderlightingproperty.cpp: BSShaderLightingProperty, NewObj, LList, FalloffProperty and more (45 functions)

#include <new>
#include <windows.h>
#include "fnv/decl/AlphaList.h"
#include "fnv/decl/B9DBE0Fader.h"
#include "fnv/decl/BA01A0Owner.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a64160_cls.h"
#include "fnv/decl/FUN_00b58570_Class.h"
#include "fnv/decl/FUN_00ba8e50_cls.h"
#include "fnv/decl/FUN_00ba9380_cls.h"
#include "fnv/decl/FUN_00baa0e0.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/FnvShaderProperty.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00ba92c0_Prop.h"
#include "fnv/decl/ShaderPropertyRecord.h"
#include "fnv/decl/TallGrassShader.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00439390__NiObjectNET.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004e2000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b70000.h"
#include "fnv/symbols_00b71000.h"
#include "fnv/symbols_00ba8000.h"
#include "fnv/symbols_00bb9000.h"
#include "fnv/symbols_00bbb000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c9a000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01026000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_01201000.h"
#include "fnv/symbols_01202000.h"
#include "bsshaderlightingproperty_types_BSShaderLightingProperty.h"
#include "bsshaderlightingproperty_globals.h"
#include "fnv/decl/FUN_00700270_class.h"
class BSShaderLightingProperty;
namespace fnv_00b6f540 { struct CloningProcess; }

// @fnv 0x00b70490
ShadowSceneLight* BSShaderLightingProperty::GetFirstAttachedLight(void*& iter)
{
    void* node = *(void**)&this->m_kShadowSceneLights.m_pkHead;
    iter = node;
    if (!node)
        return 0;
    iter = *(void**)node;
    return *(ShadowSceneLight**)((char*)node + 8);
}

// Allocates a node from the pool at this+8, links it after source in the list, and increments the count.
// @fnv 0x00b713c0
void BSShaderLightingProperty::CopyMemberData(BSShaderLightingProperty* source, CloningProcess& process)
{
    bsshaderlightingproperty_NodePool* allocator = (bsshaderlightingproperty_NodePool*)((char*)this + 8);
    void* node = ((void *)(reinterpret_cast<::FUN_0043a010_shell *>((allocator))->FUN_0043a010()));
    *(void**)((char*)node + 8) = *(void**)&process;
    *(void**)node = source;
    *(void**)((char*)node + 4) = *(void**)((char*)source + 4);
    if (*(void**)((char*)source + 4))
    {
        void* next = *(void**)((char*)source + 4);
        *(void**)next = node;
        *(void**)((char*)source + 4) = node;
        ++*(unsigned int*)((char*)this + 8);
        return;
    }
    *(void**)this = node;
    *(void**)((char*)source + 4) = node;
    ++*(unsigned int*)((char*)this + 8);
}

// @fnv 0x00b71300
void BSShaderLightingProperty::ClearLights()
{
    FNVPointerListBase* list = (FNVPointerListBase*)this;
    FNVPointerListItem* item = list->m_pkHead;
    while (item)
    {
        FNVPointerListItem* current = item;
        item = item->m_pkNext;
        current->m_element = 0;
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
        current->m_pkPrev = 0;
        current->m_pkNext = (FNVPointerListItem*)(*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58));
        --DAT_011c5f84;
        (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58)) =
            (PoolAllocatorBase<unsigned int>::LinkedListEntry*)current;
        if (!DAT_011c5f84)
            *(unsigned int*)&(*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80)) = 0;
    }
    list->m_kItemCount.m_uiCount = 0;
    list->m_pkHead = 0;
    list->m_pkTail = 0;
}

// Walks the linked list at this+0x60 via iter, returning the first ShadowSceneLight that IsActive, or null.
// @fnv 0x00b70590
ShadowSceneLight* BSShaderLightingProperty::GetFirstActiveLight(void*& iter)
{
    void* node = *(void**)&this->m_kShadowSceneLights.m_pkHead;
    iter = node;
    if (node)
    {
        iter = *(void**)node;
        ShadowSceneLight* light = *(ShadowSceneLight**)((char*)node + 8);
        while (iter && light)
        {
            if (bsshaderlightingproperty_IsActive(light))
                break;
            void* next = iter;
            iter = *(void**)next;
            light = *(ShadowSceneLight**)((char*)next + 8);
        }
        if (!light || bsshaderlightingproperty_IsActive(light))
            return light;
    }
    return 0;
}

// @fnv 0x00b6fe00
NiObject* BSShaderLightingProperty::MakeClone(CloningProcess& process)
{
    BSShaderLightingProperty* clone = new BSShaderLightingProperty;
    CopyLightingDataTo(clone, process);
    return clone;
}

extern unsigned int _data_011c16bc;

// Allocates and returns a new BSShaderLightingProperty object.
// @fnv 0x00b6fe80
BSShaderLightingProperty* CreateShaderLightingProperty()
{
    return new BSShaderLightingProperty;
}

void FUN_00b6fd30(void* pThis);

struct NiMemObject_DeleteHelper : NiMemObject
{
};


// Calls FUN_00b6fd30 on pThis, then if flags has bit 1 set calls _Dummy_00b6fef0 with pThis and 0x80, and returns pThis.
// @fnv 0x00b6fef0
void* FUN_00b6fef0(void* pThis, int, unsigned int flags)
{
    FUN_00b6fd30(pThis);
    if (flags & 1)
        ::FUN_00aa1460(pThis, 0x80);
    return pThis;
}

struct Dummy_00b70290
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50(int);
};


// @fnv 0x00b70290
void FUN_00b70290(Dummy_00b70290* pThis, int edx_val, int arg)
{
    reinterpret_cast<::FnvShaderProperty *>((pThis))->FUN_00ba8aa0((void *)(edx_val));
    pThis->v50(arg);
}

struct NiRTTI
{
    char* GetName();
    void* GetBaseRTTI();
    char* m_pcName;
    void* m_pBaseRTTI;
};
struct FUN_00b702b0_shell : public NiRTTI
{
    void FUN_00b702b0(char*, void*);
};


// Calls FUN_00ba8b10 with p1 and p2, then invokes the virtual function at offset 0xc8 with this and p1.
// @fnv 0x00b702b0
void FUN_00b702b0_shell::FUN_00b702b0(char* p1, void* p2)
{
    ::FUN_00ba8b10((::BSSP_stub4 *)(this), 0, (::BSSP_stub4 *)(p1), (::CloningProcess *)((p2)));
    typedef void(* VFn)(void*, char*);
    (*(VFn*)((*(int*)this) + 0xc8))(this, p1);
}

struct Node_00b702e0
{
    Node_00b702e0* next;
    Node_00b702e0* prev;
};

struct List_00b702e0
{
    Node_00b702e0* head;
    Node_00b702e0* tail;
};

// Unlinks node from the doubly linked list and reinserts it immediately before target, updating head and tail pointers.
// @fnv 0x00b702e0
void MoveNodeBefore(List_00b702e0* list, int, Node_00b702e0* node, Node_00b702e0* target)
{
    if (node != target)
    {
        if (list->head == node)
            list->head = node->next;
        if (list->head == target)
            list->head = node;
        if (list->tail == node)
            list->tail = node->prev;

        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;

        Node_00b702e0* prev = target->prev;
        node->prev = prev;
        node->next = target;
        if (prev)
            prev->next = node;
        target->prev = node;
    }
}

struct ItemWrap_00b70340
{
    int val;
    const int& Get() const
    {
        return val;
    }
};

struct Node_00b70340
{
    Node_00b70340* next;
    int pad;
    ItemWrap_00b70340 item;
    const ItemWrap_00b70340& GetItem() const
    {
        return item;
    }
    Node_00b70340* GetNext() const
    {
        return next;
    }
};

struct Obj_00b70340
{
    char pad[0x60];
    Node_00b70340* head;
    int pad2;
    unsigned int count;
};

// Searches the linked list for a node whose item value equals target, storing the node in outNode and returning whether it was found.
// @fnv 0x00b70340
bool FindNodeByItemValue(Obj_00b70340* pThis, int, int aiTargetValue, int unused, Node_00b70340** outNode)
{
    *outNode = 0;
    if (pThis->count < 1)
        return false;

    Node_00b70340* pCurrent = pThis->head;
    int item = pCurrent->GetItem().Get();
    Node_00b70340* next = pCurrent->GetNext();

    while (item)
    {
        if (item == aiTargetValue)
        {
            *outNode = pCurrent;
            return true;
        }
        if (!next)
            break;
        const int& r = next->GetItem().Get();
        pCurrent = next;
        next = next->GetNext();
        item = r;
    }
    return false;
}

struct Helper_00b707d0_Obj
{
    char pad[0x30];
    unsigned char flags;
};

struct Helper_00b707d0_Light
{
    char pad0[0xec];
    bool byteEC;
    char pad1[0xf8 - 0xed];
    Helper_00b707d0_Obj* objF8;
    char pad2[0x110 - 0xfc];
    unsigned short word110;
};

struct Helper_00b707d0_Node
{
    Helper_00b707d0_Node* next;
    Helper_00b707d0_Node* prev;
    Helper_00b707d0_Light* element;

    __forceinline Helper_00b707d0_Light* const& GetNext(Helper_00b707d0_Node*& pos)
    {
        Helper_00b707d0_Light* const& elem = pos->element;
        pos = pos->next;
        return elem;
    }
};

// Walks the linked list at thisPtr+0x60 and counts lights whose word110 is not 0xFF, whose objF8 flags bit 0 is clear, and whose byteEC is false.
// @fnv 0x00b707d0
int FUN_00b707d0(void* thisPtr)
{
    int count = 0;
    Helper_00b707d0_Node* pos = *(Helper_00b707d0_Node**)((char*)thisPtr + 0x60);
    while (pos)
    {
        Helper_00b707d0_Light* light = pos->GetNext(pos);
        if (light && light->word110 != 0xFF && !(light->objF8->flags & 1) && !light->byteEC)
            ++count;
    }
    return count;
}

extern int DAT_010ae7b0;

// Sets the vtable, calls the lighting property's cleanup twice on the sub-object at offset 0x60, then calls FUN_00baa0e0 on pThis.
// @fnv 0x00b71410
void FUN_00b71410(void* pThis, int)
{
    BSShaderLightingProperty* pSub = (BSShaderLightingProperty*)((char*)pThis + 0x60);
    *(int**)pThis = &DAT_010ae7b0;
    pSub->ClearLights();
    pSub->ClearLights();
    reinterpret_cast<class ::FUN_00baa0e0 *>((pThis))->FUN_00baa0e0::~FUN_00baa0e0();
}

extern int DAT_010ae7b0;
void FUN_00ba8e50(void*);

// @fnv 0x00b71720
void* FUN_00b71720(char* pThis)
{
    reinterpret_cast<::FUN_00ba8e50_cls *>((pThis))->FUN_00ba8e50();
    char* list = pThis + 0x60;
    *(int**)pThis = &DAT_010ae7b0;
    *(int*)(list + 8) = 0;
    *(int*)(list + 0) = 0;
    *(int*)(list + 4) = 0;
    ((BSShaderLightingProperty*)list)->ClearLights();
    *(float*)(pThis + 0x6c) = 1.0f;
    *(int*)(pThis + 0x70) = 0;
    *(char*)(pThis + 0x74) = 0;
    *(int*)(pThis + 0x78) = 0;
    *(int*)(pThis + 0x1c) = 1;
    return pThis;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    NiPoint3 operator*(float f) const
    {
        return NiPoint3(x * f, y * f, z * f);
    }
    NiPoint3& operator*=(float f);
};
struct NiColor
{
    float r, g, b;
    NiColor()
    {}
    NiColor(float fR, float fG, float fB) : r(fR), g(fG), b(fB)
    {}
    NiColor operator*(float fScalar) const
    {
        NiColor kResult = *this;
        kResult.r *= fScalar;
        kResult.g *= fScalar;
        kResult.b *= fScalar;
        return kResult;
    }
    NiColor& operator*=(float fScalar)
    {
        r *= fScalar;
        g *= fScalar;
        b *= fScalar;
        return *this;
    }
};
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor()
    {}
    RgbaColor(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}
};
struct WaterTintRecord
{
    float r, g, b, a;
    WaterTintRecord(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}
};
struct WaterShaderStub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual float GetFloat10c();
    char pad04[0x18];
    int iType;
};
struct GeomStub
{
    char pad00[0xa8];
    WaterShaderStub* pShader;
};
struct WaterDataStub
{
    char pad00[0x8c];
    NiPoint3 kTint;  // +0x8c
    char pad98[0x2c];
    float fC4;             // +0xc4
    NiColor kColor;        // +0xc8
    NiColor m_kDeepColor;  // +0xd4
    NiPoint3 kE0;          // +0xe0
    char padEC[4];
    NiPoint3 kWorldPosition;  // +0xf0
};
struct WaterStub
{
    float GetD0() const
    {
        return fD0;
    }
    char pad00[0xd0];
    float fD0;  // +0xd0
    float fD4;  // +0xd4
    char padD8[0x1c];
    bool bF4;  // +0xf4
    bool bF5;  // +0xf5
    char padF6[2];
    WaterDataStub* pData;  // +0xf8
};
extern unsigned int DAT_011fa070[8];
extern bool DAT_011f91de;
extern bool DAT_011f91a6;
extern const double DAT_010784d0;
extern const double DAT_01026998;

// @fnv 0x00b70820
void UpdateWaterTint(unsigned int uiIndex, WaterStub* apWater, float fScale)
{
    if (uiIndex >= 8)
        return;
    if (!apWater)
    {
        (*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[uiIndex] = (*reinterpret_cast<::RgbaColor *>(&::DAT_011a9bd0));
        return;
    }
    bool bF5 = apWater->bF5;
    WaterDataStub* pData = apWater->pData;
    bool bF4 = apWater->bF4;
    WaterShaderStub* pProp = (*(*reinterpret_cast<::GeomStub ** *>(&::DAT_011f91e0)))->pShader;
    WaterShaderStub* pShader = (pProp && pProp->iType >= 8 && pProp->iType <= 12) ? pProp : 0;

    if (!bF4)
    {
        if (pData)
        {
            NiPoint3 kWorldPosition = pData->kWorldPosition;
            reinterpret_cast<::FUN_004a0c10_s *>(&(kWorldPosition))->FUN_004a0c10();
            float f = pShader ? pShader->GetFloat10c() : 1.0f;
            SetWaterTintRecord(uiIndex + 0x13,
                               WaterTintRecord(kWorldPosition.x, kWorldPosition.y, kWorldPosition.z, f));
        }
    }
    else if (pData)
    {
        NiPoint3 kTint = pData->kTint;
        SetWaterTintRecord(uiIndex + 0xb, WaterTintRecord(kTint.x, kTint.y, kTint.z, 1.0f));
    }
    if (!bF4 && (!DAT_011f91de || bF5))
    {
        float fA = pData->fC4;
        if (!DAT_011f941e)
            fA = FUN_0040ebd0(1.0f, fA);
        NiColor kColor = pData->kColor * fA;
        float fLimit = DAT_011f947c;
        if (fLimit > 0.0f)
        {
            float fLum = kColor.r * DAT_01026998 + kColor.g * DAT_010784d0 + kColor.b + DAT_01026998;
            if (fLum <= 0.0f)
            {
                kColor = NiColor(fLimit, fLimit, fLimit);
            }
            else
            {
                float fScaleFactor = (fLum > fLimit) ? 1.0f : fLimit / fLum;
                kColor = NiColor((kColor.r + 0.10000000149011612) * fScaleFactor,
                                 (kColor.g + 0.10000000149011612) * fScaleFactor,
                                 (kColor.b + 0.10000000149011612) * fScaleFactor);
            }
        }
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiColor &)(kColor))->FUN_00439180(fScale);
        (*reinterpret_cast<::RgbaColor *>((void *)&::DAT_011FA0C0)) = RgbaColor(kColor.r, kColor.g, kColor.b, 1.0f);
    }

    float fV = pData->fC4;
    if (!DAT_011f941e && 1.0 < fV)
        fV = 1.0f;
    NiColor kColor = pData->m_kDeepColor * fV * fScale * apWater->GetD0();
    if (bF4)
    {
        if (fScale < 1.0f)
            kColor = DAT_011f4998;
    }
    else if (DAT_011f941e && !(*reinterpret_cast<bool *>(&::DAT_011f9427)))
    {
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiColor &)(kColor))->FUN_00439180(DAT_011f9190);
    }
    float fAlpha = apWater->fD4;
    unsigned short usId = (unsigned short)DAT_011f91e4;
    if (usId >= 0x154 && usId <= 0x177 && pShader)
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiColor &)(kColor))->FUN_00439180(pShader->GetFloat10c());
    (*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[uiIndex] = RgbaColor(kColor.r, kColor.g, kColor.b, fAlpha);
    if (bF4)
    {
        NiPoint3 kE0 = pData->kE0;
        (*reinterpret_cast<RgbaColor (*)[8]>(&::DAT_011fa1f0))[uiIndex] = RgbaColor(kE0.x, 0.0f, 0.0f, 1.0f);
    }
    DAT_011f91a6 = bF4;
    DAT_011fa070[uiIndex] = bF4 ? 2 : 1;
}

namespace fnv_00b6f540 {
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
struct FUN_00b6f540_shell : public BSShaderLightingProperty
{
    void CopyShaderLightingProperty(BSShaderLightingProperty*, CloningProcess*);
};

struct _Helper_00ba8b10
{
};

struct _RCObj
{
    virtual void _v0();
    virtual void _dtor();
};

struct _Vec4
{
    int x;
    int y;
    int z;
    int w;
};

// @fnv 0x00b6f540
void FUN_00b6f540_shell::CopyShaderLightingProperty(BSShaderLightingProperty* pDest, CloningProcess* arCloneData)
{
    ::FUN_00ba8b10((::BSSP_stub4 *)(this), 0, (::BSSP_stub4 *)(reinterpret_cast<char*>(pDest)), (::CloningProcess *)((void *)(static_cast<void*>(arCloneData))));

    _RCObj* oldVal = *reinterpret_cast<_RCObj**>(&pDest->m_kShadowSceneLights.m_pkHead);
    if (oldVal != *reinterpret_cast<_RCObj**>(&this->m_kShadowSceneLights.m_pkHead))
    {
        if (oldVal)
        {
            if (InterlockedDecrement(reinterpret_cast<long*>(reinterpret_cast<char*>(oldVal) + 4)) == 0)
                oldVal->_dtor();
        }
        _RCObj* newVal = *reinterpret_cast<_RCObj**>(&this->m_kShadowSceneLights.m_pkHead);
        *reinterpret_cast<_RCObj**>(&pDest->m_kShadowSceneLights.m_pkHead) = newVal;
        if (newVal)
            InterlockedIncrement(reinterpret_cast<long*>(reinterpret_cast<char*>(newVal) + 4));
    }

    int val = *reinterpret_cast<int*>(&this->m_fForcedDarkness);
    *reinterpret_cast<int*>(&pDest->m_fForcedDarkness) = val;

    *reinterpret_cast<_Vec4*>(reinterpret_cast<char*>(pDest) + 0x70) =
        *reinterpret_cast<_Vec4*>(reinterpret_cast<char*>(this) + 0x70);
}
}  // namespace fnv_00b6f540

struct RefObject
{
    virtual void Unk0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct SmartPtr
{
    RefObject* m_pObject;
    void Release()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
            m_pObject = 0;
        }
    }
    ~SmartPtr()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
};

struct MemoryManager
{
};

struct MyArray
{
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usGrowBy;
    ~MyArray()
    {
        if (m_pBase)
        {
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(m_pBase);
        }
        m_pBase = 0;
        m_usGrowBy = 0;
        m_usMaxSize = 0;
    }
};


struct __declspec(novtable) Base_00b6fd30
{
    virtual void VTableAnchor();
    char pad[0x5c];
    ~Base_00b6fd30()
    {
        reinterpret_cast<class ::FUN_00baa0e0 *>((this))->FUN_00baa0e0::~FUN_00baa0e0();
    }
};

struct FUN_00b6fd30 : Base_00b6fd30
{
    SmartPtr m_pReferencedObject;
    MyArray m_kArray;
    virtual ~FUN_00b6fd30();
};

// Destructor that releases the smart pointer member, decrementing its reference count and clearing the pointer.
// @fnv 0x00b6fd30
FUN_00b6fd30::~FUN_00b6fd30()
{
    m_pReferencedObject.Release();
}

// @fnv 0x00b70270
bool FUN_00b70270(void* p)
{
    if (FUN_00c9a420(p))
        return true;
    return false;
}

struct FUN_00b70600_flags
{
    char pad[0x30];
    unsigned char flags;
};
struct FUN_00b70600_obj
{
    char pad0[0xec];
    char state;
    char pad1[0xb];
    FUN_00b70600_flags* info;
    char pad2[0x14];
    unsigned short id;
};
struct FUN_00b70600_node
{
    FUN_00b70600_node* next;
    int pad;
    FUN_00b70600_obj* data;
};
struct FUN_00b70600_list
{
    char pad[0x60];
    FUN_00b70600_node* head;
};

// @fnv 0x00b70600
FUN_00b70600_obj* FUN_00b70600(FUN_00b70600_list* self, int unused, FUN_00b70600_node** it)
{
    FUN_00b70600_node* n = self->head;
    *it = n;
    if (!n)
        return 0;
    *it = n->next;
    FUN_00b70600_obj* o = n->data;
    while (*it && o)
    {
        if (o->id != 0xff && !(o->info->flags & 1) && o->state != 1)
            break;
        FUN_00b70600_node* c = *it;
        *it = c->next;
        o = c->data;
    }
    if (o && (o->id == 0xff || (o->info->flags & 1) || o->state == 1))
        o = 0;
    return o;
}

struct FUN_00b70790_flags
{
    char pad[0x30];
    unsigned char flags;
};
struct FUN_00b70790_light
{
    char pad[0xf8];
    FUN_00b70790_flags* m_pMenuLight;
    char pad2[0x110 - 0xfc];
    unsigned short cull;
};
struct FUN_00b70790_node
{
    FUN_00b70790_node* next;
    int pad;
    FUN_00b70790_light* item;
};
struct FUN_00b70790_owner
{
    char p0[0x60];
    FUN_00b70790_node* head;
};
// @fnv 0x00b70790
unsigned int FUN_00b70790(FUN_00b70790_owner* self)
{
    unsigned int n = 0;
    FUN_00b70790_node* it = self->head;
    while (it)
    {
        FUN_00b70790_node* cur = it;
        FUN_00b70790_light*& r = cur->item;
        it = it->next;
        FUN_00b70790_light* l = r;
        if (l && l->cull != 0xff && !(l->m_pMenuLight->flags & 1))
            ++n;
    }
    return n;
}

struct GeomStub;
struct FUN_00b71360_water
{
    char pad[0xf4];
    bool flag;
};
struct FUN_00b71360_inner
{
    char pad[0x68];
    int type;
};
struct FUN_00b71360_geom
{
    char pad[0xc0];
    FUN_00b71360_inner* inner;
};
// @fnv 0x00b71360
void __cdecl FUN_00b71360(unsigned int id, FUN_00b71360_water* w, float fValue)
{
    FUN_00b71360_geom* g = (FUN_00b71360_geom*)*(*reinterpret_cast<::GeomStub ** *>(&::DAT_011f91e0));
    if (g->inner->type == 0x11)
    {
        if (w->flag)
            ::fnv_00b71130::SetLightColor(id, (::fnv_00b71130::LProp *)(w), fValue);
        else
            ::fnv_00b70de0::ApplyWaterLighting(id, (::fnv_00b70de0::WaterStub *)(w), fValue);
    }
    else
    {
        ::UpdateWaterTint(id, (::WaterStub *)(w), fValue);
    }
}

// @fnv 0x00b71440
const char* FUN_00b71440(void* self)
{
    return (*reinterpret_cast<const char (*)[]>(&::g_011fa560));
}

extern int DAT_010ae7b0;
// @fnv 0x00b71760
BSShaderLightingProperty* DestroyShaderLightingProperty(BSShaderLightingProperty* self, int edx,
                                                                   unsigned int flags)
{
    BSShaderLightingProperty* list = (BSShaderLightingProperty*)((char*)self + 0x60);
    *(int**)self = &DAT_010ae7b0;
    list->ClearLights();
    list->ClearLights();
    reinterpret_cast<class ::FUN_00baa0e0 *>((self))->FUN_00baa0e0::~FUN_00baa0e0();
    if (flags & 1)
        ::FUN_00aa1460(self, 0x7c);
    return self;
}

namespace fnv_00b71800 {
struct _Helper_00ba8b10
{
};
struct BSFadeNode
{
};
struct FUN_00ba8e50 : BSFadeNode
{
    FUN_00ba8e50();
    virtual void vf();
    char p0[0x18];
    int f1c;
    char p1[0x40];
    int l0, l4, l8;
    float f6c;
    int f70;
    char f74;
    char p2[3];
    int f78;
};
struct NewObj : FUN_00ba8e50
{
    NewObj();
    virtual void vf();
};
NewObj::NewObj()
{
    int* q = &l0;
    q[2] = 0;
    q[0] = 0;
    q[1] = 0;
    reinterpret_cast<BSShaderLightingProperty*>(q)->ClearLights();
    f6c = 1.0f;
    f70 = 0;
    f74 = 0;
    f1c = 1;
    f78 = 0;
}
struct Owner;
typedef void(* OwnerFn)(Owner*, void*);

// @fnv 0x00b71800
NewObj* FUN_00b71800(_Helper_00ba8b10* self, int unused, void* arg)
{
    NewObj* o = new NewObj;
    ::FUN_00ba8b10((::BSSP_stub4 *)(self), 0, (::BSSP_stub4 *)(reinterpret_cast<char*>(o)), (::CloningProcess *)((arg)));
    (*reinterpret_cast<OwnerFn**>(self))[0xc8 / 4](reinterpret_cast<Owner*>(self), o);
    return o;
}
}  // namespace fnv_00b71800

struct BSFadeNode
{
};
struct FUN_00b71720 : BSFadeNode
{
    FUN_00b71720();
    virtual void vf();
    char p0[0x18];
    int f1c;
    char p1[0x38];
    int f58;
    char p2[0x20];
    int f7c;
    char p3[0x54];
};
struct NewObj : FUN_00b71720
{
    NewObj();
    virtual void vf();
};
NewObj::NewObj()
{
    f7c = 0;
    f58 = 0x10;
    f1c = 3;
}
struct SelfStub
{
};

// Allocates a NewObj, passes it with arg to FUN_00b702b0, and returns the new object.
// @fnv 0x00bb4140
NewObj* FUN_00bb4140(SelfStub* self, int unused, int aiValue)
{
    NewObj* o = new NewObj;
    reinterpret_cast<::FUN_00b702b0_shell *>((self))->FUN_00b702b0((char *)(o), (void *)(aiValue));
    return o;
}

struct FUN_00bb95b0_entry
{
    int a, b, c, d, e, f, g, h;
};
// Stores the four arguments into the first four fields of the DAT_01201c80 entry at index i.
// @fnv 0x00bb95b0
void __cdecl FUN_00bb95b0(int aiIndex, int aiValue0, int aiValue1, int aiValue2, int aiValue3)
{
    FUN_00bb95b0_entry* p = &DAT_01201c80[aiIndex];
    p->a = aiValue0;
    p->b = aiValue1;
    p->c = aiValue2;
    p->d = aiValue3;
}

namespace fnv_00bb95e0 {
struct FUN_00bb95e0_entry
{
    int a, b, c, d, e, f, g, h;
};

// Stores the eight arguments into the fields of the DAT_01201c80 entry at index i, writing e,f,g,h then a,b,c,d.
// @fnv 0x00bb95e0
void FUN_00bb95e0(int aiIndex, int aiE, int aiF, int aiG, int aiH, int aiA, int aiB, int aiC, int aiD)
{
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].e = aiE;
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].f = aiF;
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].g = aiG;
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].h = aiH;
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].a = aiA;
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].b = aiB;
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].c = aiC;
    (*reinterpret_cast<fnv_00bb95e0::FUN_00bb95e0_entry (*)[]>(&::DAT_01201c80))[aiIndex].d = aiD;
}
}  // namespace fnv_00bb95e0

struct Light_b70700;
struct ListItem_b70700
{
    ListItem_b70700* m_pkNext;
    ListItem_b70700* m_pkPrev;
    Light_b70700* m_element;
};

static inline Light_b70700* GetNext_b70700(ListItem_b70700*& kPos)
{
    if (kPos == 0)
        return 0;
    Light_b70700*& element = kPos->m_element;
    kPos = kPos->m_pkNext;
    return element;
}

static inline bool Skip_b70700(Light_b70700* p)
{
    char* l = reinterpret_cast<char*>(p);
    return *reinterpret_cast<unsigned short*>(l + 0x110) == 0xff ||
           (*reinterpret_cast<unsigned int*>(*reinterpret_cast<char**>(l + 0xf8) + 0x30) & 1) ||
           *reinterpret_cast<bool*>(l + 0xec) == true;
}

// @fnv 0x00b70700
Light_b70700* FUN_00b70700(ListItem_b70700*& kPos)
{
    Light_b70700* p = 0;
    if (kPos)
    {
        p = GetNext_b70700(kPos);
        while (p && kPos && Skip_b70700(p))
            p = GetNext_b70700(kPos);
        if (p && Skip_b70700(p))
            return 0;
    }
    return p;
}

namespace fnv_00b71130 {
struct LColor
{
    float r, g, b;
};
struct LColorA
{
    float r, g, b, a;
    LColorA()
    {}
    LColorA(float fr, float fg, float fb, float fa)
    {
        r = fr;
        g = fg;
        b = fb;
        a = fa;
    }
};
struct LMat
{
    char pad0[0x8c];
    LColor kAmbient;
    char pad98[0xc4 - 0x98];
    float fScale;
    char padc8[0xd4 - 0xc8];
    LColor kColor;
    LColor kOther;
};
struct LProp
{
    char pad0[0xd0];
    float fMult;
    float fAlpha;
    char padd8[0xf8 - 0xd8];
    LMat* pMatrix;
};

// @fnv 0x00b71130
void SetLightColor(unsigned int uiLightIndex, LProp* pLightProp, float fIntensity)
{
    if (uiLightIndex >= 20)
        return;
    if (!pLightProp)
    {
        ::FUN_00bb95b0(uiLightIndex, (*(int *)&(const ::fnv_00b71130::LColorA &)((*reinterpret_cast<::fnv_00b71130::LColorA *>(&::DAT_011a9bd0)))), {}, {}, {});
        return;
    }
    LMat* pMatrix = pLightProp->pMatrix;
    LColor kAmb = pMatrix->kAmbient;
    LColor kOther = pMatrix->kOther;
    LColorA kA(kAmb.r, kAmb.g, kAmb.b, kOther.r);
    LColorA kB;
    if (fIntensity < 1.0f)
    {
        kB = (*reinterpret_cast<::fnv_00b71130::LColorA *>(&::DAT_011a9bd0));
    }
    else
    {
        float fScale = pMatrix->fScale;
        if (!::DAT_011f941e)
            fScale = ::FUN_0040ebd0(1.0f, fScale);
        fScale = fScale * fIntensity;
        fScale = fScale * pLightProp->fMult;
        LColor kC = pMatrix->kColor;
        kB.r = kC.r * fScale;
        kB.g = kC.g * fScale;
        kB.b = kC.b * fScale;
    }
    kB.a = pLightProp->fAlpha;
    ::fnv_00bb95e0::FUN_00bb95e0(uiLightIndex, (*(int *)&(const ::fnv_00b71130::LColorA &)(kA)), (*(int *)&(const ::fnv_00b71130::LColorA &)(kB)), {}, {}, {}, {}, {}, {});
}
}  // namespace fnv_00b71130

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*> CharPtrList;
typedef PoolAllocatorBase<unsigned int>::LinkedListEntry PoolNode;

struct LightingElem
{
    unsigned char pad[0xec];
    bool bFlag;
};
struct LItem
{
    LItem* m_pkNext;
    LItem* m_pkPrev;
    LightingElem* m_element;
};
struct LList
{
    LItem* m_pkHead;
    LItem* m_pkTail;
    unsigned int m_uiCount;
    void RemoveItem(LItem* cur);
};
static inline void FreeNode(LItem* item)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
    item->m_pkPrev = 0;
    item->m_pkNext = (LItem*)(*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58));
    (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58)) = (PoolNode*)item;
    if (--DAT_011c5f84 == 0)
        (*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80)).m_lock = 0;
}
__forceinline void LList::RemoveItem(LItem* cur)
{
    if (cur == m_pkHead)
    {
        LItem* head = m_pkHead;
        m_pkHead = head->m_pkNext;
        if (m_pkHead)
            m_pkHead->m_pkPrev = 0;
        else
            m_pkTail = 0;
        head->m_element = 0;
        FreeNode(head);
        m_uiCount--;
    }
    else if (cur == m_pkTail)
    {
        ((CharPtrList*)this)->RemoveTail();
    }
    else
    {
        LItem* prev = cur->m_pkPrev;
        LItem* next = cur->m_pkNext;
        if (prev)
            prev->m_pkNext = next;
        if (next)
            next->m_pkPrev = prev;
        cur->m_element = 0;
        FreeNode(cur);
        m_uiCount--;
    }
}

struct FUN_00b71600_S
{
    unsigned char pad0[0x38];
    int iField38;
    unsigned char pad3c[0x24];
    LList kList;
    unsigned char pad6c[8];
    bool bField74;
    unsigned char pad75[3];
    LItem* pkPos;
    void RemoveItemsAfterPos(void* arg);
};

// Removes every list item after pkPos, calls FUN_00ba01a0 on each element, resets iField38 when bFlag is set, then removes pkPos itself.
// @fnv 0x00b71600
void FUN_00b71600_S::RemoveItemsAfterPos(void* arg)
{
    if (pkPos != kList.m_pkTail)
    {
        bField74 = true;
        LItem* it = pkPos->m_pkNext;
        while (it)
        {
            LItem* cur = it;
            LightingElem* elem = it->m_element;
            it = it->m_pkNext;
            kList.RemoveItem(cur);
            reinterpret_cast<::BA01A0Owner *>((elem))->FUN_00ba01a0((::BA01A0Item *)(arg), (void *)(0));
            if (elem->bFlag)
                iField38 = 0;
        }
    }
    ((CharPtrList*)&kList)->RemovePos(*(void**)&pkPos);
    pkPos = 0;
}

class B6FC20BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(B6FC20BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(B6FC20BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n)
    {
        unsigned int size = n;
        return BinaryWrite(p, n, &size, 1);
    }
};

class B6FC20Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    B6FC20BinaryStream* m_pBackingStream;

};

template <class T> inline void B6FC20SaveBinary(B6FC20Stream& kStream, const T& value)
{
    kStream.m_pBackingStream->Write(&value, sizeof(T));
}

struct B6FC20Color
{
    float r;
    float g;
    float b;
    float a;
};

class B6FC20Base
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;

};

class B6FC20Object : public B6FC20Base
{
  public:
    const char* m_pcName;
    int unk68;
    unsigned int m_uiType;
    B6FC20Color m_kFogTint;

    void SaveToStream(B6FC20Stream& kStream);
};

// SaveBinary
// Serializes the base data, type, name string and color to the given stream.
// @fnv 0x00b6fc20
void B6FC20Object::SaveToStream(B6FC20Stream& kStream)
{
    reinterpret_cast<::FUN_00ba9380_cls *>(this)->FUN_00ba9380((void *)&(kStream));
    B6FC20SaveBinary(kStream, m_uiType);
    reinterpret_cast<::FUN_00a64160_cls *>(&(kStream))->FUN_00a64160(m_pcName);
    B6FC20SaveBinary(kStream, m_kFogTint);
}

struct NiViewerStringsArray
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
    unsigned int Add(char* const& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct ViewerRTTI
{
    const char* m_pcName;
    void* m_pBaseRTTI;
};

struct ViewerTexture;

struct TexPtr
{
    void* m_pObject;
    operator void*() const
    {
        return m_pObject;
    }
};
struct ViewerBaseProperty
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiValue1;
};

struct FalloffProperty : ViewerBaseProperty
{
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
    TexPtr m_pkTexture;
    int unk64;
    int unk68;
    int unk6C;
    float m_fFalloffStartAngle;
    float m_fFalloffStopAngle;
    float m_fFalloffStartOpacity;
    float m_fFalloffStopOpacity;
    void FUN_00b6ff20(NiViewerStringsArray* pkStrings);
};

// Appends the falloff RTTI name, base texture and, when flag 0x40 is set, the falloff angle and opacity values to pkStrings.
// @fnv 0x00b6ff20
void FalloffProperty::FUN_00b6ff20(NiViewerStringsArray* pkStrings)
{
    reinterpret_cast<::ShaderPropertyRecord *>(this)->WriteToSettingArray((::SettingArray *)(pkStrings));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d330((*reinterpret_cast<::ViewerRTTI *>(&::g_011fa05c)).m_pcName)));
    ViewerTexture* pkTex = ((::ViewerTexture *)(::FUN_00c4bb40((::NiObjectC4BB *)(void *)(m_pkTexture))));
    if (pkTex)
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::fnv_00a7d5e0::FUN_00a7d5e0("base texture", (const char *)(pkTex))));
    else
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d5a0("base texture", m_pkTexture)));
    if ((m_uiValue1 & 0x40) > 0)
    {
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d550("falloff start angle", m_fFalloffStartAngle)));
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d550("falloff stop angle", m_fFalloffStopAngle)));
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d550("falloff start opacity", m_fFalloffStartOpacity)));
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d550("falloff stop opacity", m_fFalloffStopOpacity)));
    }
}

struct C4
{
    unsigned int r, g, b, a;
};
// Clears DAT_011fa070 from idx to 7 and copies the default color into slots i+18 and DAT_011a9bd0's color into slots i.
// @fnv 0x00b704c0
void __cdecl ResetColorSlots(int aiStartIndex)
{
    static RgbaColor kDef(::AngularDashpotApplyD4DCB0::DAT_01017d00, 0.0f, 0.0f, 0.0f);
    for (int iIndex = aiStartIndex; iIndex < 8; iIndex++)
    {
        DAT_011fa070[iIndex] = 0;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex + 18]).r = ((C4&)kDef).r;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex]).r = ((C4&)(*reinterpret_cast<::RgbaColor *>(&::DAT_011a9bd0))).r;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex]).g = ((C4&)(*reinterpret_cast<::RgbaColor *>(&::DAT_011a9bd0))).g;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex + 18]).g = ((C4&)kDef).g;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex + 18]).b = ((C4&)kDef).b;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex]).b = ((C4&)(*reinterpret_cast<::RgbaColor *>(&::DAT_011a9bd0))).b;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex + 18]).a = ((C4&)kDef).a;
        ((C4&)(*reinterpret_cast<RgbaColor (*)[8]>((void *)&::DAT_011FA0D0))[iIndex]).a = ((C4&)(*reinterpret_cast<::RgbaColor *>(&::DAT_011a9bd0))).a;
    }
}

template <class T> class ViewerArray
{
  public:
    void FUN_0096ad30(unsigned int uiMaxSize);                  // SetSize
    void FUN_0096ae90(unsigned int uiIndex, const T& element);  // SetAt

    unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }

    void* m_pvVtable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
typedef ViewerArray<char*> ViewerStringArray;


class LightingPropertyBase
{
  public:
      // base GetViewerStrings
};

class LightingProperty : public LightingPropertyBase
{
  public:
    int GetNumLights() const
    {
        return m_iNumLights;
    }
    unsigned int GetReferenceID() const
    {
        return m_uiReferenceID;
    }
    void FUN_00b71450(ViewerStrings* pkStrings);

    char unk00[0x68];
    int m_iNumLights;  // +0x68
    int unk6c;
    unsigned int m_uiReferenceID;  // +0x70
};

// Appends the base strings plus the class name, light counts and reference ID to the given string array.
// @fnv 0x00b71450
void LightingProperty::FUN_00b71450(ViewerStrings* pkStrings)
{
    reinterpret_cast<::ShaderPropertyRecord *>(this)->WriteToSettingArray((::SettingArray *)(pkStrings));
    reinterpret_cast<ViewerStringArray*>(pkStrings)->Add(FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011fa560))));
    reinterpret_cast<ViewerStringArray*>(pkStrings)->Add(::FUN_00a7d490("number of lights", GetNumLights()));
    reinterpret_cast<ViewerStringArray*>(pkStrings)->Add(::FUN_00a7d490("active lights", ((unsigned short)(::FUN_00b70790((::FUN_00b70790_owner *)this)))));
    reinterpret_cast<ViewerStringArray*>(pkStrings)->Add(FUN_00a7d510("Reference ID", GetReferenceID()));
}

struct GeometryState;
struct AlphaPropertyData
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
    float alpha;
};
struct GeometryProperties
{
    GeometryState* state;
    unsigned int unk04;
    AlphaPropertyData* alphaProperty;
};
struct GeometryData
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
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char skinMode;
};
struct GeometryState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char flags;
};
class NiGeometry
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const void* GetRTTI();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void* GetSpecialGeometry();
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
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    GeometryProperties properties;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    GeometryData* data;
};
struct ShaderPassEntry
{
    unsigned int unk00;
    unsigned short unk04;
    unsigned char mode;
};
class BSShaderProperty__RenderPassArray
{
  public:
    unsigned int unk00;
    ShaderPassEntry** passes;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int count;
    void Add(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*,
             ShadowSceneLight*);
};
struct FUN_00ba8ab0_shell
{
    void FUN_00ba8ab0(float);
};
struct Fake_FUN_004a2020
{
    bool GetFlag(unsigned int) const;
};
struct PassRenderer
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
    unsigned int mode;
};
class RenderProperty : public BSShaderProperty
{
  public:
    void* texture;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int variant;
    bool GetFlag(unsigned int index) const
    {
        return ((const Fake_FUN_004a2020*)this)->GetFlag(index);
    }
    BSShaderProperty__RenderPassArray* BuildRenderPassList(NiGeometry* geometry, int state, unsigned int unused,
                                                           int type, PassRenderer* renderer, unsigned int unused2);
};
// Selects a shader index from geometry type, texture and flags, adds a render pass, sets its mode, and caches the state in iLastRenderPassState.
// @fnv 0x00b6f5c0
BSShaderProperty__RenderPassArray* RenderProperty::BuildRenderPassList(NiGeometry* geometry, int state,
                                                                       unsigned int unused, int type,
                                                                       PassRenderer* renderer, unsigned int unused2)
{
    GeometryProperties* properties = &geometry->properties;
    int fullState = (type << 8) | state;
    state = fullState;
    bool special = false;
    if (type == 7)
        return 0;
    if (properties)
    {
        float alpha;
        if (properties->alphaProperty)
            alpha = properties->alphaProperty->alpha * fFadeAlpha;
        else
            alpha = fFadeAlpha;
        ((FUN_00ba8ab0_shell*)this)->FUN_00ba8ab0(alpha);
    }
    if (iLastRenderPassState == fullState)
        return pRenderPassList;

    reinterpret_cast<::TallGrassShader *>(this)->InitializeConstants(true);
    pRenderPassList->count = 0;
    unsigned int shader;
    bool isSkin = false;
    if (geometry)
        isSkin = (geometry->GetRTTI() == &(*reinterpret_cast<const char *>(&::g_01202560)));
    if (isSkin)
    {
        shader = geometry->data->skinMode > 0 ? 87 : 86;
    }
    else if (geometry->GetSpecialGeometry())
    {
        if (geometry->data->skinMode > 0)
            shader = GetFlag(51) ? 85 : 83;
        else
            shader = GetFlag(51) ? 84 : 82;
    }
    else
    {
        bool flag = (ulFlags[1] & 0x20) > 0;
        if ((ulFlags[0] & 0x40) > 0)
        {
            if (texture != 0)
            {
                if (!GetFlag(3) && !flag)
                    shader = GetFlag(1) ? 78 : 74;
                else
                    shader = GetFlag(1) ? 80 : 76;
            }
            else
            {
                if (flag)
                    shader = GetFlag(1) ? 79 : 75;
                else
                    shader = GetFlag(1) ? 81 : 77;
            }
            special = true;
        }
        else
        {
            if (texture != 0)
            {
                if (!GetFlag(3) && !flag)
                    shader = GetFlag(1) ? 70 : 66;
                else
                    shader = GetFlag(1) ? 72 : 68;
            }
            else
            {
                if (flag)
                    shader = GetFlag(1) ? 71 : 67;
                else
                    shader = GetFlag(1) ? 73 : 69;
            }
        }
    }
    pRenderPassList->Add(geometry, (unsigned short)shader, true, 0, 0, 0, 0, 0);
    ShaderPassEntry* pass = pRenderPassList->passes[pRenderPassList->count - 1];
    bool alphaBlend = (geometry->properties.state->flags & 1) != 0;
    if (!alphaBlend && (renderer->mode == 2 || (ulFlags[1] & 4) > 0 || GetFlag(33)))
        pass->mode = 10;
    else if ((ulFlags[0] & 0x04000000) > 0)
        pass->mode = 4;
    else if ((ulFlags[0] & 0x08000000) > 0)
        pass->mode = 5;
    else if (m_iShaderType == 17 && variant == 8)
        pass->mode = 3;
    else if (fAlpha < 1.0f || alphaBlend || geometry->GetSpecialGeometry() || special)
        pass->mode = 1;
    iLastRenderPassState = state;
    return pRenderPassList;
}

// @fnv 0x00b70260
void FUN_00b70260()
{
    static_cast<::S_00ba92c0_Prop *>(nullptr)->FUN_00ba92c0(*(::S_00ba92c0_Stream *)nullptr);
}

struct FUN_00b704b0_t
{
    unsigned short get68();
};
// @fnv 0x00b704b0
unsigned short FUN_00b704b0_t::get68()
{
    return *(unsigned short*)((char*)this + 0x68);
}

struct S00b700d0_RTTI;

class S00b700d0_Alpha : public NiProperty
{
  public:
    S00b700d0_Alpha();

    unsigned short m_usFlags;
    unsigned char m_ucAlphaThreshold;
    unsigned char m_ucPad1B;
};

struct S00b700d0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short usFlags;
    unsigned char ucThreshold;
    unsigned char ucPad1B;
};

struct S00b700d0_B8;
struct S00b700d0_B8Ptr
{
    S00b700d0_B8* m_p;
    S00b700d0_B8* operator->() const
    {
        return m_p;
    }
};
struct S00b700d0_B8
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
    void* ptr28;
};

class S00b700d0_Geom : public NiObjectNET
{
  public:
    virtual const S00b700d0_RTTI* GetRTTI() const;
    virtual void virt0C();
    virtual void virt10();
    virtual void virt14();
    virtual void virt18();
    virtual void virt1C();
    virtual void virt20();
    virtual void virt24();
    virtual void virt28();
    virtual void virt2C();
    virtual int virt30();

    bool IsExactKindOf(const S00b700d0_RTTI* r) const
    {
        return GetRTTI() == r;
    }


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
    S00b700d0_Data* m_pData;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    S00b700d0_B8Ptr m_pkB8;
    void* m_pkBC;
};

class S00b700d0_Shader : public BSShaderProperty
{
  public:
    static __forceinline void SetBit(unsigned long& bits, int& cache, unsigned int flag)
    {
        if (!(bits & flag))
            cache = 0;
        bits |= flag;
    }
    bool ApplyAlphaProperty(S00b700d0_Geom* pGeom);
};

// Sets shader flags, checks geometry kind and data flags, then creates and applies an S00b700d0_Alpha property from pData fields.
// @fnv 0x00b700d0
bool S00b700d0_Shader::ApplyAlphaProperty(S00b700d0_Geom* apGeom)
{
    void* ptr28 = apGeom->m_pkB8->ptr28;
    if (ptr28 && !((ulFlags[1] & 0x20) > 0))
    {
        SetBit(ulFlags[1], iLastRenderPassState, 0x20);
    }
    if (apGeom->m_pkBC)
    {
        SetBit(ulFlags[0], iLastRenderPassState, 2);
    }
    if (!apGeom->virt30())
    {
        return true;
    }
    bool bExactKind = apGeom->IsExactKindOf(&(*reinterpret_cast<::S00b700d0_RTTI *>(&::g_01202560)));
    if (bExactKind)
    {
        return true;
    }
    S00b700d0_Data* pData = apGeom->m_pData;
    if (!pData)
    {
        return true;
    }
    if ((pData->usFlags & 0x1E) != 0xC || (pData->usFlags & 0x1E0))
    {
        return true;
    }
    NiProperty* pProp = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((apGeom))->FUN_00a59d30(0)));
    if (pProp)
    {
        reinterpret_cast<::ExtraOwnerB *>((apGeom))->FUN_00a5b230(0);
    }
    S00b700d0_Alpha* pAlpha = new S00b700d0_Alpha;
    reinterpret_cast<::FUN_0049ed90_shell *>((pAlpha))->FUN_0049ed90(pData->usFlags & 1);
    reinterpret_cast<::Flag512Receiver *>((pAlpha))->SetFlag512((pData->usFlags >> 9) & 1);
    reinterpret_cast<::fnv_00439390::NiObjectNET *>((pAlpha))->FUN_00439390((pData->usFlags >> 5) & 0xF);
    pAlpha->m_usFlags &= 0xFFE1;
    reinterpret_cast<::NiObjectNET *>((pAlpha))->SetFlags((pData->usFlags >> 10) & 7);
    pAlpha->m_ucAlphaThreshold = pData->ucThreshold;
    reinterpret_cast<::FUN_00439410_cls *>((apGeom))->FUN_00439410((::ArgObject *)(pAlpha));
    reinterpret_cast<::FUN_00a5a040_Class *>((apGeom))->FUN_00a5a040();
    SetBit(ulFlags[1], iLastRenderPassState, 0x80000);
    return true;
}

class ShadowSceneLight
{
  public:
};

class NiTListItem_ShadowSceneLight___
{
  public:
    NiTListItem_ShadowSceneLight___* m_pkNext;
    NiTListItem_ShadowSceneLight___* m_pkPrev;
    ShadowSceneLight* m_element;
};

typedef void* NiTListIterator;

class ShadowSceneLightList
{
  public:
    NiTListItem_ShadowSceneLight___* m_pkHead;
    NiTListItem_ShadowSceneLight___* m_pkTail;

    NiTListIterator GetHeadPos() const
    {
        return m_pkHead;
    }
    ShadowSceneLight* GetNext(NiTListIterator& kPos) const
    {
        ShadowSceneLight* const& element = ((NiTListItem_ShadowSceneLight___*)kPos)->m_element;
        kPos = ((NiTListItem_ShadowSceneLight___*)kPos)->m_pkNext;
        return element;
    }
};

class LightSortOwner
{
  public:
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
    int iLastRenderPassState;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    ShadowSceneLightList m_kShadowSceneLights;
    void SortShadowSceneLights(int aiMemoryContext);
};

// Reorders m_kShadowSceneLights by ComputeFade's result and resets iLastRenderPassState to 0 if any node moves.
// @fnv 0x00b70390
void LightSortOwner::SortShadowSceneLights(int aiMemoryContext)
{
    NiTListIterator kIter = m_kShadowSceneLights.GetHeadPos();
    bool bChanged = false;
    while (kIter)
    {
        NiTListItem_ShadowSceneLight___* pkNode = (NiTListItem_ShadowSceneLight___*)kIter;
        ShadowSceneLight* pkLight = m_kShadowSceneLights.GetNext(kIter);
        NiTListIterator kTestIter = m_kShadowSceneLights.GetHeadPos();
        float fKey = reinterpret_cast<::B9DBE0Fader *>((pkLight))->ComputeFade((const ::B9DBE0Bound *)(aiMemoryContext));
        while (kTestIter != pkNode && kTestIter)
        {
            NiTListItem_ShadowSceneLight___* pkTest = (NiTListItem_ShadowSceneLight___*)kTestIter;
            if (fKey < reinterpret_cast<::B9DBE0Fader *>((m_kShadowSceneLights.GetNext(kTestIter)))->ComputeFade((const ::B9DBE0Bound *)(aiMemoryContext)))
            {
                if (pkNode != pkTest)
                {
                    if (m_kShadowSceneLights.m_pkHead == pkNode)
                        m_kShadowSceneLights.m_pkHead = pkNode->m_pkNext;
                    if (m_kShadowSceneLights.m_pkHead == pkTest)
                        m_kShadowSceneLights.m_pkHead = pkNode;
                    if (m_kShadowSceneLights.m_pkTail == pkNode)
                        m_kShadowSceneLights.m_pkTail = pkNode->m_pkPrev;
                    if (pkNode->m_pkNext)
                        pkNode->m_pkNext->m_pkPrev = pkNode->m_pkPrev;
                    if (pkNode->m_pkPrev)
                        pkNode->m_pkPrev->m_pkNext = pkNode->m_pkNext;
                    pkNode->m_pkPrev = pkTest->m_pkPrev;
                    pkNode->m_pkNext = pkTest;
                    if (pkNode->m_pkPrev)
                        pkNode->m_pkPrev->m_pkNext = pkNode;
                    pkTest->m_pkPrev = pkNode;
                }
                kTestIter = 0;
                bChanged = true;
            }
        }
    }
    if (bChanged)
        iLastRenderPassState = 0;
}

namespace fnv_00b70de0 {
struct NiPoint3
{
    float x, y, z;
};
struct NiColor
{
    float r, g, b;
    NiColor operator*(float s) const
    {
        NiColor res = {r * s, g * s, b * s};
        return res;
    }
    NiColor& operator*=(float s)
    {
        r *= s;
        g *= s;
        b *= s;
        return *this;
    }
};
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor()
    {}
    RgbaColor(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a)
    {}
};
struct Lighting30Packet4
{
    float r, g, b, a;
};

struct WaterShaderStub
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual float GetFloat10c();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int iType;
};

struct GeomStub
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    WaterShaderStub* pShader;
};

struct WaterDataStub
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    float fC4;
    NiColor kColor;
    NiColor m_kDeepColor;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    NiPoint3 kWorldPosition;
};

struct WaterStub
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    float fD0;
    float fD4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    WaterDataStub* pData;
};

extern double DAT_010784d0;
extern double DAT_01026998;

// Computes water surface and deep colors from WaterStub data and shader, then emits a lighting packet via ApplyLighting30Packet and FUN_00bb95e0.
// @fnv 0x00b70de0
void __cdecl ApplyWaterLighting(unsigned int id, WaterStub* water, float scale)
{
    WaterStub* w = water;
    if (!w)
    {
        ::FUN_00bb95b0(id, (*(int *)&(const ::fnv_00b70de0::RgbaColor &)((*reinterpret_cast<::fnv_00b70de0::RgbaColor *>(&::DAT_011a9bd0)))), {}, {}, {});
        return;
    }
    WaterShaderStub* p = (*reinterpret_cast<::fnv_00b70de0::GeomStub ** *>(&::DAT_011f91e0))[0]->pShader;
    WaterDataStub* data = w->pData;
    WaterShaderStub* shader = (p && p->iType >= 8 && p->iType <= 12) ? p : 0;
    NiPoint3 direction = data->kWorldPosition;
    RgbaColor first;
    first.r = direction.x;
    first.g = direction.y;
    first.b = direction.z;
    first.a = shader ? shader->GetFloat10c() : 1.0f;
    float brightness = ::DAT_011f947c;
    bool flag = false;
    RgbaColor kLightRgba = (*reinterpret_cast<::fnv_00b70de0::RgbaColor *>(&::DAT_011a9bd0));
    float multiplier = data->fC4;
    if (!(*reinterpret_cast<unsigned char *>(&::DAT_011f941e)) && 1.0 < multiplier)
        multiplier = 1.0f;
    NiColor color = data->kColor;
    color.r *= multiplier;
    color.g *= multiplier;
    color.b *= multiplier;
    if (brightness > 0.0f)
    {
        float grey = (double)0.34f * color.g + (double)0.33f * color.r + color.b + (double)0.33f;
        if (grey <= 0.0f)
            color.b = color.g = color.r = brightness;
        else
        {
            float f = brightness < grey ? 1.0f : brightness / grey;
            color.r = (color.r + double(0.1f)) * f;
            color.g = (color.g + double(0.1f)) * f;
            color.b = (color.b + double(0.1f)) * f;
        }
    }
    color *= scale;
    if (scale < 1.0f)
        flag = true;
    kLightRgba.r = color.r;
    kLightRgba.g = color.g;
    kLightRgba.b = color.b;
    kLightRgba.a = 1.0f;
    ::ApplyLighting30Packet((const ::Lighting30Packet4 *)(const ::fnv_00b70de0::Lighting30Packet4 *)(reinterpret_cast<const Lighting30Packet4*>(&kLightRgba)), flag);
    multiplier = multiplier * scale;
    multiplier *= w->fD0;
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011f941e)) && !::DAT_011f9427)
        multiplier *= ::DAT_011f9190;
    color = data->m_kDeepColor;
    ::fnv_00bb95e0::FUN_00bb95e0(id, (*(int *)&(const ::fnv_00b70de0::RgbaColor &)(first)), (*(int *)&(const ::fnv_00b70de0::RgbaColor &)(RgbaColor(color.r * multiplier, color.g * multiplier, color.b * multiplier, w->fD4))), {}, {}, {}, {}, {}, {});
}
}  // namespace fnv_00b70de0

namespace fnv_00bdf3e0 {
struct Bdf3e0_v3
{
    float x;
    float y;
    float z;
    bool isDef() const;
};


struct Bdf3e0_info
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    Bdf3e0_v3 vec;
};

struct Bdf3e0_node
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    Bdf3e0_info* info;
};

struct Bdf3e0_ent
{
    int unk00;
    int unk04;
    char unk08;
    char unk09;
    char unk0a;
    char unk0b;
};

struct Bdf3e0_list
{
    int unk00;
    Bdf3e0_ent** arr;
    int unk08;
    int unk0c;
    int count;
    void FUN_00ba9ee0(int a, int b, int c, int d, int e, int f, int g, int h);
};

struct Bdf3e0_cls;

struct Bdf3e0_vt
{
    void* v00;
    void* v04;
    void* v08;
    void* v0c;
    void* v10;
    void* v14;
    void* v18;
    void* v1c;
    void* v20;
    void* v24;
    void* v28;
    void* v2c;
    void* v30;
    void* v34;
    void* v38;
    void* v3c;
    void* v40;
    void* v44;
    void* v48;
    void* v4c;
    void* v50;
    void* v54;
    void* v58;
    void* v5c;
    void* v60;
    void* v64;
    void* v68;
    void* v6c;
    void* v70;
    void* v74;
    void* v78;
    void* v7c;
    void* v80;
    void* v84;
    void* v88;
    void* v8c;
    void* v90;
    void* v94;
    void* v98;
    void* v9c;
    void* va0;
    void* va4;
    void* va8;
    void* vac;
    void* vb0;
    void* vb4;
    void* vb8;
    void* vbc;
    void* vc0;
    void* vc4;
    void* vc8;
    void* vcc;
    void* vd0;
    void* vd4;
    void* vd8;
    void* vdc;
    void* ve0;
    void* ve4;
    void* ve8;
    unsigned short(* vEC)(Bdf3e0_cls*);
};

struct Bdf3e0_cls
{
    Bdf3e0_vt* vt;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int flags;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    Bdf3e0_list* list;
    void FUN_00bdf3e0(int a0, int a1, unsigned short* a2, char a3, char* a4, int a5, char a6);
};

// Walks three node iterators past defined vectors, computes an id from vt->vEC and flags, and appends a list entry via FUN_00ba9ee0 or increments *a2.
// @fnv 0x00bdf3e0
void Bdf3e0_cls::FUN_00bdf3e0(int a0, int a1, unsigned short* apCount, char acMode, char* apFlag, int a5, char acAdjust)
{
    ::FUN_00b70600_node* it = 0;
    Bdf3e0_node* p = ((::fnv_00bdf3e0::Bdf3e0_node *)(::FUN_00b70600((::FUN_00b70600_list *)this, 0, &it)));
    while (p && p->info->vec.isDef())
        p = ((::fnv_00bdf3e0::Bdf3e0_node *)(::FUN_00b70700(reinterpret_cast<::ListItem_b70700 *&>(it))));
    Bdf3e0_node* q = ((::fnv_00bdf3e0::Bdf3e0_node *)(::FUN_00b70700(reinterpret_cast<::ListItem_b70700 *&>(it))));
    while (q && q->info->vec.isDef())
        q = ((::fnv_00bdf3e0::Bdf3e0_node *)(::FUN_00b70700(reinterpret_cast<::ListItem_b70700 *&>(it))));
    Bdf3e0_node* r = ((::fnv_00bdf3e0::Bdf3e0_node *)(::FUN_00b70700(reinterpret_cast<::ListItem_b70700 *&>(it))));
    while (r && r->info->vec.isDef())
        r = ((::fnv_00bdf3e0::Bdf3e0_node *)(::FUN_00b70700(reinterpret_cast<::ListItem_b70700 *&>(it))));
    unsigned short s = vt->vEC(this);
    int n = s < 7 ? s : 7;
    bool f = (flags & 0x100000) > 0;
    if (p == 0)
    {
        int id = n * 8 + 0x1f7;
        if (acAdjust)
            id++;
        if (f)
            id += 2;
        if (acMode == 1)
            list->FUN_00ba9ee0(a0, id, 1, 1, a1, 0, 0, 0);
        else
            ++*apCount;
    }
    else
    {
        int id = n * 8 + 0x1fb;
        if (acAdjust)
            id++;
        if (f)
            id += 2;
        if (acMode == 1)
            list->FUN_00ba9ee0(a0, id, 1, 4, a1, (int)p, (int)q, (int)r);
        else
            ++*apCount;
    }
    *apFlag = 0;
    if (acMode == 1 && (*reinterpret_cast<char *>(&::fnv_00454450::reloadHasWorld)) != 0 && !((flags & 0x4000) > 0))
    {
        list->FUN_00ba9ee0(a0, 0x230, 0, 1, a1, 0, 0, 0);
        list->arr[list->count - 1]->unk0b = 9;
    }
    else
    {
        ++*apCount;
    }
}

bool Bdf3e0_v3::isDef() const
{
    return x == (*reinterpret_cast<float *>(&::DAT_011f4998)) && y == (*reinterpret_cast<float *>(&::DAT_011f499c)) && z == (*reinterpret_cast<float *>(&::DAT_011f49a0));
}
}  // namespace fnv_00bdf3e0

struct S00b70680_Helper
{
    static bool Active(ShadowSceneLight* l)
    {
        return *(unsigned short*)((char*)l + 0x110) != 0xff &&
               (*(unsigned char*)(*(char**)((char*)l + 0xf8) + 0x30) & 1) == 0;
    }
};
// Advances the iterator past inactive ShadowSceneLight entries and returns the next active light or null.
// @fnv 0x00b70680
ShadowSceneLight* FUN_00b70680(NiTListItem<ShadowSceneLight*>*& iter)
{
    NiTListItem<ShadowSceneLight*>* node = iter;
    ShadowSceneLight* light = 0;
    if (node)
    {
        NiTListItem<ShadowSceneLight*>* next = node->m_pkNext;
        iter = next;
        light = node->m_element;
        while (light && next && !S00b70680_Helper::Active(light))
        {
            ShadowSceneLight** pe = &next->m_element;
            next = next->m_pkNext;
            iter = next;
            light = *pe;
        }
        if (light && !S00b70680_Helper::Active(light))
            return 0;
    }
    return light;
}


namespace sb717a0 {

struct Watcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    bool m_bHasAccumulation;
};

template <class T> struct PointerList
{
    struct Node
    {
        Node* m_pkNext;
        Node* m_pkPrev;
        T m_element;
    };

    Node* m_pkHead;

    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos)
    {
        T& element = ((Node*)pos)->m_element;
        pos = ((Node*)pos)->m_pkNext;
        return element;
    }
    void FUN_00e7db70(const T& element);
};

struct WatchSet
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int m_iTimer;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    PointerList<Watcher*> m_kWatchers;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    bool m_bValueAt0C;
    unsigned char unk075;
    unsigned char unk076;
    unsigned char unk077;
    int m_iLocked;

    __forceinline void CheckDuplicate(Watcher* pkWatcher)
    {
        if (!m_iLocked)
        {
            void* pos = m_kWatchers.GetHeadPos();
            while (pos)
            {
                if (m_kWatchers.GetNext(pos) == pkWatcher)
                    DebugBreak();
            }
        }
    }

    void AddWatcher(Watcher* pkWatcher);
};

// Adds pkWatcher to m_kWatchers, sets m_bValueAt0C, resets m_iTimer if the watcher has accumulation, then checks for duplicates.
// @fnv 0x00b717a0
void WatchSet::AddWatcher(Watcher* pkWatcher)
{
    Watcher* light = pkWatcher;
    if (!m_iLocked)
    {
        reinterpret_cast<::AlphaList *>(&(m_kWatchers))->FUN_00e7db70((unsigned int *)&(pkWatcher));
        m_bValueAt0C = true;
        if (light->m_bHasAccumulation)
            m_iTimer = 0;
    }
    CheckDuplicate(light);
}

}

namespace fnv_00b718b0 {
struct LItem
{
    LItem* next;
    LItem* prev;
    void* elem;
};
struct LPool
{
    unsigned int count;
    LItem* FUN_0043a010();
};
struct LList
{
    LItem* head;
    LItem* tail;
    LPool alloc;
    LItem* NewItem()
    {
        return ((::fnv_00b718b0::LItem *)(reinterpret_cast<::FUN_0043a010_shell *>(&(alloc))->FUN_0043a010()));
    }
    void AddNodeHead(LItem* n)
    {
        n->prev = 0;
        n->next = head;
        if (head)
            head->prev = n;
        else
            tail = n;
        alloc.count++;
        head = n;
    }
    LItem* GetHeadPos() const
    {
        return head;
    }
    void AddHead(void* const& e)
    {
        LItem* n = NewItem();
        n->elem = e;
        AddNodeHead(n);
    }
};
struct S
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    LList list60;
    int unk6c;
    int unk70;
    int unk74;
    LItem* unk78;
    void FUN_00b718b0();
};
// Calls FUN_00e7db70 and AddHead with DAT_011fa310, then stores the resulting list head in unk78.
// @fnv 0x00b718b0
void S::FUN_00b718b0()
{
    void* key = &(*reinterpret_cast<char *>(&::g_011fa310));
    reinterpret_cast<::AlphaList *>(&(list60))->FUN_00e7db70((unsigned int *)&(key));
    list60.AddHead(&(*reinterpret_cast<char *>(&::g_011fa310)));
    unk78 = list60.GetHeadPos();
}
}  // namespace fnv_00b718b0

struct Light_b71560
{
    int unk00;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    bool byteEC;
};

struct Node_b71560
{
    Node_b71560* next;
    Node_b71560* prev;
    Light_b71560* item;
};
struct Pool_b71560
{
    unsigned int count;
    Node_b71560* FUN_0043a010();
};
struct List_b71560
{
    Node_b71560* head;
    Node_b71560* tail;
    Pool_b71560 pool;
    Node_b71560* FUN_00b713c0(Node_b71560* node, Light_b71560* const& item);
    Node_b71560* FUN_00b58570(Light_b71560* const& item);
};

struct Obj_b71560
{
    int unk00;
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
    int unk34;
    int m_38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    List_b71560 m_list60;
    int unk6c;
    int unk70;
    bool m_b74;
    Node_b71560* m_p78;
    void InsertOrMoveNode(Light_b71560* item, void* a2);
};

// Moves or inserts list nodes; on the no-p78 path, sets m_b74 and clears m_38 if item->byteEC is set.
// @fnv 0x00b71560
void Obj_b71560::InsertOrMoveNode(Light_b71560* item, void* a2)
{
    Node_b71560* p78 = m_p78;
    if (p78)
    {
        if (::FindNodeByItemValue((::Obj_00b70340 *)this, 0, (int)((item)), (int)((a2)), (::Node_00b70340 **)((&a2))))
        {
            if (a2)
                ::MoveNodeBefore((::List_00b702e0 *)&(m_list60), 0, (::Node_00b702e0 *)((static_cast<Node_b71560*>(a2))), (::Node_00b702e0 *)((p78)));
            else
                ::MoveNodeBefore((::List_00b702e0 *)&(m_list60), 0, (::Node_00b702e0 *)((m_list60.tail)), (::Node_00b702e0 *)((p78)));
            return;
        }
        reinterpret_cast<::BSShaderLightingProperty *>(&(m_list60))->CopyMemberData((::BSShaderLightingProperty *)(p78), (::CloningProcess &)(item));
        m_b74 = true;
        return;
    }
    void* key = a2;
    Light_b71560* light = item;
    if (!::FindNodeByItemValue((::Obj_00b70340 *)this, 0, (int)((light)), (int)((key)), (::Node_00b70340 **)((&a2))))
    {
        reinterpret_cast<::FUN_00b58570_Class *>(&(m_list60))->FUN_00b58570((void *)&(item));
    }
    m_b74 = true;
    if (light->byteEC)
    {
        m_38 = 0;
    }
}

Node_b71560* List_b71560::FUN_00b58570(Light_b71560* const& item)
{
    Node_b71560* node = pool.FUN_0043a010();
    node->item = item;
    node->next = 0;
    node->prev = tail;
    if (tail)
        tail->next = node;
    else
        head = node;
    ++pool.count;
    tail = node;
    return node;
}

Node_b71560* List_b71560::FUN_00b713c0(Node_b71560* pos, Light_b71560* const& item)
{
    Node_b71560* node = pool.FUN_0043a010();
    node->item = item;
    node->next = pos;
    node->prev = pos->prev;
    if (pos->prev)
        pos->prev->next = node;
    else
        head = node;
    pos->prev = node;
    ++pool.count;
    return node;
}

struct FUN_0076a3d0_Class
{
    void FUN_0076a3d0(int);
};

// @fnv 0x0076a3d0
void FUN_0076a3d0_Class::FUN_0076a3d0(int a)
{
    reinterpret_cast<::FUN_00700270_class *>(this)->operator==(a);
}

#include "generated/data/bsshader/bsshaderlightingproperty.inc"
