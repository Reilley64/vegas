
// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00a31730
#include <cstdint>
#include "fnv/ni_allocator.h"
#include "fnv/symbols_00aa1000.h"
#include <windows.h>
#include <new>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/BSMultiTargetTreadTransfController.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/Controller.h"
#include "fnv/decl/ControllerOwner.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a30540_cls.h"
#include "fnv/decl/FUN_00a30700_T.h"
#include "fnv/decl/FUN_00a311e0_s.h"
#include "fnv/decl/FUN_00a31260_StandIn.h"
#include "fnv/decl/FUN_00a32290_Cls.h"
#include "fnv/decl/FUN_00a35910_shell.h"
#include "fnv/decl/FUN_00a35f70_struct.h"
#include "fnv/decl/FUN_00a35fe0_shell.h"
#include "fnv/decl/FUN_00a36070.h"
#include "fnv/decl/FUN_00a41410_cls.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a5d430_Class.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00c663d0.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiD3DShaderProgram.h"
#include "fnv/decl/NiGPUProgramOwner.h"
#include "fnv/decl/NiInterpController.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a34000.h"
#include "fnv/symbols_00a47000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_01014000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01044000.h"
#include "fnv/symbols_01047000.h"
#include "fnv/symbols_0105a000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/decl/FUN_00a5d2f0_class.h"
#include "fnv/symbols_00a32000.h"
#include "fnv/symbols_01096000.h"
#include <cstddef>
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/NiControllerSequence__IDTag.h"
#include "fnv/symbols_00a35000.h"
#include "fnv/symbols_01023000.h"
const char* const* __cdecl FUN_00a31730()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f36dc));
}

struct BaseH
{
    virtual ~BaseH();
};

class NiControllerSequence : public BaseH
{
  public:
    void* FUN_00a35820(unsigned int);
public:
    NiControllerSequence();
};

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct FUN_00a30580_shell
{
    bool IsNotInChain(void* arg);
};

// Walks the linked list at offset 0x58 from arg and returns false if this is found in it, true otherwise.
// @fnv 0x00a30580
bool FUN_00a30580_shell::IsNotInChain(void* pStart)
{
    void* next = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(pStart) + 0x58);
    if (next == 0)
        return true;
    do
    {
        if (next == this)
            return false;
        next = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(next) + 0x58);
    } while (next != 0);
    return true;
}

struct MM_00a34450
{
};
extern int DAT_01096620;
struct FUN_00a34450_shell
{
    void* FUN_00a34450(unsigned int);
};
// @fnv 0x00a34450
void* FUN_00a34450_shell::FUN_00a34450(unsigned int auiFlags)
{
    void* p = *(void**)((char*)this + 4);
    *(void**)this = (void*)&DAT_01096620;
    ::ReleaseObjectArray((::Obj00a47600 **)(p));
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM_00a34450 *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

struct NiBinaryStream
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pv, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = uiBytes;
        m_uiStreamFlags += m_pfnWrite(this, pv, uiBytes, &uiComponentSize, 1);
    }
};
struct NiObject;
struct NiStream
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void SaveLinkID(const void* pkObject);
    unsigned char m_auiShapeKeys[0x24c];
    NiBinaryStream* m_pBackingStream;
public:
    ::NiObject *GetLoadedObject();
public:
    ::NiObject *DeserializeObject();
};
struct NiRTTI;
struct NiObject
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
struct SeqInterpArrayItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};
struct SeqIDTag
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
};
struct FUN_00a33bf0_s : NiObject
{
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    SeqInterpArrayItem* m_pInterpArray;
    SeqIDTag* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    unsigned char m_pad34[0xc];
    void* m_pkOwnerManager;
    unsigned char m_pad44[0x18];
    char* m_kAccumulationRootName;
    unsigned char m_pad60[0xc];
    void** m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    void SaveToStream(NiStream& kStream);
};
// Links the object to the stream, then writes the name, interpolation array items with their ID tags, scalar fields and the linked object list.
// @fnv 0x00a33bf0
void FUN_00a33bf0_s::SaveToStream(NiStream& kStream)
{
    ::FUN_00a89af0((intptr_t)this);
    reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((const char*)&m_kName));
    kStream.m_pBackingStream->Write(&m_uiNumControlledBlocks, 4);
    kStream.m_pBackingStream->Write(&m_uiNumIDTags, 4);
    unsigned int ui;
    for (ui = 0; ui < m_uiNumControlledBlocks; ui++)
    {
        SeqInterpArrayItem& kItem = m_pInterpArray[ui];
        kStream.SaveLinkID(kItem.m_spControllerInterpolator);
        kStream.SaveLinkID(kItem.m_pkController);
        kStream.m_pBackingStream->Write(&kItem.m_ucArrayItemID, 1);
        SeqIDTag& kTag = m_pkIDTags[ui];
        reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((const char*)&kTag.m_kAVObjectName));
        reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((const char*)&kTag.m_kPropertyType));
        reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((const char*)&kTag.m_kCtlrType));
        reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((const char*)&kTag.m_kCtlrID));
        reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((const char*)&kTag.m_kInterpolatorID));
    }
    kStream.m_pBackingStream->Write(&m_fWeight, 4);
    kStream.SaveLinkID(m_spTextKeyData);
    kStream.m_pBackingStream->Write(&m_eAnimationCycleType, 4);
    kStream.m_pBackingStream->Write(&m_fFrequency, 4);
    kStream.m_pBackingStream->Write(&m_fFirstKeyTime, 4);
    kStream.m_pBackingStream->Write(&m_fLastKeyTime, 4);
    kStream.SaveLinkID(m_pkOwnerManager);
    reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((const char*)&m_kAccumulationRootName));
    kStream.m_pBackingStream->Write(&m_usNumAnimNotes, 2);
    for (unsigned short usIndex = 0; usIndex < m_usNumAnimNotes; usIndex++)
        kStream.SaveLinkID(m_pkAnimNotes[usIndex]);
}

struct FUN_00a2e420_shell
{
    unsigned char FUN_00a2e420(float);
};
struct FUN_00a30540_shell
{
};
struct FUN_00a35030_shell : NiControllerSequence
{
    unsigned char SetEaseOut(float fEaseOutTime, bool bTransition);
};
// Starts an ease-out with the given time and transition flag, or finishes it by updating the accumulated time and resetting state.
// @fnv 0x00a35030
unsigned char FUN_00a35030_shell::SetEaseOut(float fEaseOutTime, bool bTransition)
{
    if (!*(void**)((char*)this + 0x44))
        return 0;
    if (fEaseOutTime > 0.0f)
    {
        *(float*)((char*)this + 0x4c) = DAT_01015f5c;
        *(float*)((char*)this + 0x50) = fEaseOutTime;
        *(unsigned int*)((char*)this + 0x44) = bTransition ? 4 : 3;
        return 1;
    }
    if (*(float*)((char*)this + 0x34) != ::DAT_010241b0)
        *(float*)((char*)this + 0x48) = *(float*)((char*)this + 0x38) / *(float*)((char*)this + 0x28) -
                                        *(float*)((char*)this + 0x34) + *(float*)((char*)this + 0x48);
    if (*(unsigned int*)((char*)this + 0x44) == 5 && *(void**)((char*)this + 0x40))
        ((FUN_00a2e420_shell*)*(void**)((char*)this + 0x40))->FUN_00a2e420(0.0f);
    *(float*)((char*)this + 0x54) = DAT_01015f5c;
    *(unsigned int*)((char*)this + 0x44) = 0;
    *(void**)((char*)this + 0x58) = 0;
    reinterpret_cast<::FUN_00a30540_cls *>((((FUN_00a30540_shell*)this)))->FUN_00a30540();
    return 1;
}

struct FUN_00a30900_shell
{
    void FUN_00a30900(char m_ucRegionPriority);
};

// @fnv 0x00a30900
void FUN_00a30900_shell::FUN_00a30900(char cDefaultPriority)
{
    unsigned int ui;
    SeqInterpArrayItem* kItem;

    for (ui = 0; ui < *(unsigned int*)((char*)this + 0xc); ++ui)
    {
        kItem = (SeqInterpArrayItem*)(*(uintptr_t*)((char*)this + 0x14) + ui * 0x10);
        if (kItem->m_spControllerInterpolator && kItem->m_pkBlendInterpolator)
        {
            unsigned int ucPriority;
            if (kItem->m_ucArrayItemID == 0xff)
                ucPriority = (unsigned int)cDefaultPriority;
            else
                ucPriority = kItem->m_ucArrayItemID;
            kItem->m_ucBlendIndex = ((unsigned char(*)(void*, void*, float, unsigned int, float)) *
                                     (void**)(*(uintptr_t*)kItem->m_pkBlendInterpolator + 0xdc))(
                kItem->m_pkBlendInterpolator, kItem->m_spControllerInterpolator, *(float*)((char*)this + 0x1c),
                ucPriority, 1.0f);
        }
    }
}

struct A51BF0Base
{
};

struct FUN_00a316a0_shell
{
};

// @fnv 0x00a326c0
void* __cdecl FUN_00a326c0()
{
    void* p = ::operator new(0x74);
    if (p)
        return ((void *)(new ((void *)(reinterpret_cast<FUN_00a316a0_shell*>(p))) ::NiControllerSequence()));
    return 0;
}

extern char DAT_01096584;
extern int(* DAT_00fdf1c4)(void*);

class NiRefObject
{
  public:
    ~NiRefObject();
};

struct FUN_00a31500_shell
{
};

struct FUN_00a315b0_shell
{
};

struct FUN_00a31740_shell
{
};

struct FUN_00a35640_shell
{
    void FUN_00a35640();
};
// @fnv 0x00a35820
void* NiControllerSequence::FUN_00a35820(unsigned int flags)
{
    reinterpret_cast<::FUN_00a35640_shell *>(this)->FUN_00a35640();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x74);
    return this;
}

struct RefBase
{
    virtual void First()
    {}
    virtual void Release()
    {}
};


struct FUN_00a307c0_entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_00a307c0_item
{
    const char* name;
    const char* ctrl;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};

struct FUN_00a307c0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00a307c0_entry* m_14;
    FUN_00a307c0_item* m_18;
    void GetEntryText(unsigned int idx, char* out);
};

// @fnv 0x00a307c0
void FUN_00a307c0_cls::GetEntryText(unsigned int uiIndex, char* out)
{
    if (out == 0)
    {
        return;
    }
    if (m_14[uiIndex].unk00 == 0)
    {
        *out = 0;
    }
    else
    {
        FUN_00a307c0_item* item = &m_18[uiIndex];
        const char* name = item->name;
        unsigned int nameLen = strlen(name) + 1;
        const char* ctrl = item->ctrl;
        if (ctrl != 0)
        {
            const char* propStr = ctrl ? "PROP\n" : 0;
            unsigned int propLen = strlen(propStr);
            unsigned int ctrlLen = strlen(ctrl);
            unsigned int total = ctrlLen + propLen + nameLen + 1;
            ::NiSprintf(out, total, "%s\n%s%s", name, "PROP\n", ctrl);
        }
        else
        {
            fnv::crt::strcpy_s(out, nameLen, name);
        }
    }
}


struct S_00a30880_RefObject
{
    virtual ~S_00a30880_RefObject()
    {}
    virtual void V01()
    {}

    long m_lRefCount;
};

struct S_00a30880_Base
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}

    virtual void Target(float fValue, unsigned int uiFlags)
    {}
};

struct S_00a30880_Item
{
    void* m_spControllerInterpolator;
    S_00a30880_RefObject* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};

struct S_00a30880_Foo : S_00a30880_Base
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    S_00a30880_Item* m_pInterpArray;
    void* unk18;
    float unk1c;
    void* unk20;
    unsigned int unk24;
    float unk28;
    float unk2c;
    float unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;

    void ReleaseItems();
};

// Calls Target(0,0) when unk44 is set, then releases each item's reference-counted object and clears its pointer.
// @fnv 0x00a30880
void S_00a30880_Foo::ReleaseItems()
{
    if (unk44 != 0)
    {
        S_00a30880_Base* pBase = this;
        pBase->Target(0.0f, 0u);
    }

    unsigned int uiIndex = 0;

    if (m_uiNumControlledBlocks > uiIndex)
    {
        do
        {
            S_00a30880_RefObject** ppRefObject = &m_pInterpArray[uiIndex].m_pkController;
            S_00a30880_RefObject* pRefObject = *ppRefObject;

            if (pRefObject != 0)
            {
                if (InterlockedDecrement(&pRefObject->m_lRefCount) == 0)
                    pRefObject->V01();

                *ppRefObject = 0;
            }

            m_pInterpArray[uiIndex].m_pkBlendInterpolator = 0;
        } while (++uiIndex < m_uiNumControlledBlocks);
    }
}

struct SequenceA30970 : NiObject
{
    char* name08;
    unsigned int arraySize0c;
    unsigned int arrayGrow10;
    SeqInterpArrayItem* interpolators14;
    SeqIDTag* tags18;
    float weight1c;
    void* textKeys20;
    int cycleType24;
    float frequency28;
    float begin2c;
    float end30;
    float lastTime34;
    float accumulated38;
    float scaled3c;
    float FUN_00a30970(float time, bool update);
};
// Advances the sequence's accumulated time by frequency times the delta, wraps it into [begin,end] when cycleType is 0, and optionally stores the new state.
// @fnv 0x00a30970
float SequenceA30970::FUN_00a30970(float time, bool update)
{
    float accumulated = accumulated38;
    float delta;
    if (lastTime34 == ::DAT_010241b0)
    {
        accumulated = 0.0f;
        delta = time;
    }
    else
    {
        delta = time - lastTime34;
    }
    accumulated += frequency28 * delta;
    float scaled = accumulated;
    if (cycleType24 == 0)
    {
        float duration = end30 - begin2c;
        if (duration != 0.0f)
        {
            scaled -= begin2c;
            if (scaled == duration)
                scaled = end30;
            else
                scaled = (float)fmod(scaled, duration) + begin2c;
            if (scaled < begin2c)
                scaled += duration;
        }
        else
        {
            scaled = begin2c;
        }
    }
    if (scaled > end30)
        scaled = end30;
    else if (scaled < begin2c)
        scaled = begin2c;
    if (update)
    {
        accumulated38 = accumulated;
        lastTime34 = time;
        scaled3c = scaled;
    }
    return scaled;
}

struct FUN_00a30c80_shell
{
    bool FUN_00a30c80(void* arg);
};
struct FUN_00a30cc0_target
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual bool V23(void* pOther);
};

struct FUN_00a30cc0_cls
{
    FUN_00a30cc0_target* m_pKey0;
    FUN_00a30cc0_target* m_pKey4;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char m_bFlag0D;

    unsigned char Equals(FUN_00a30cc0_cls* other);
};

// Compares two objects' key pointers via V23 and returns whether both keys match and m_bFlag0D is equal.
// @fnv 0x00a30cc0
unsigned char FUN_00a30cc0_cls::Equals(FUN_00a30cc0_cls* other)
{
    if ((m_pKey0 != 0 && other->m_pKey0 == 0) || (m_pKey0 == 0 && other->m_pKey0 != 0) ||
        (m_pKey0 != 0 && other->m_pKey0 != 0 && !m_pKey0->V23(other->m_pKey0)))
        return false;
    FUN_00a30cc0_target* a = m_pKey4;
    if ((a != 0 && other->m_pKey4 == 0) || (m_pKey4 == 0 && other->m_pKey4 != 0) ||
        (a != 0 && other->m_pKey4 != 0 && !a->V23(other->m_pKey4)))
        return false;
    return m_bFlag0D == other->m_bFlag0D;
}

struct StreamView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(char*&);
};
struct RefView
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
    virtual bool v21(StreamView&);
};
struct ObjectView
{
    int vtable;
    int refs;
    bool FUN_00a5d2f0(StreamView&);
};
struct ItemView
{
    RefView* interpolator;
    RefView* controller;
    void* blend;
    unsigned int settings;
};
struct TagView
{
    char* object;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
};
struct SequenceView : ObjectView
{
    char* name;
    unsigned int count;
    unsigned int grow;
    ItemView* items;
    TagView* tags;
    float weight;
    RefView* text;
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
    char* root;
    int unk60;
    int unk64;
    int unk68;
    RefView** notes;
    unsigned short noteCount;
    bool FUN_00a30ea0(StreamView&);
};
// @fnv 0x00a30ea0
bool SequenceView::FUN_00a30ea0(StreamView& stream)
{
    if (!FUN_00a5d2f0(stream))
        return false;
    for (unsigned int i = 0; i < count; i++)
    {
        ItemView& item = items[i];
        if (item.interpolator)
            item.interpolator->v21(stream);
        RefView* controller = item.controller;
        if (controller)
            controller->v21(stream);
        TagView& tag = tags[i];
        stream.v8(tag.object);
        stream.v8(tag.property);
        stream.v8(tag.type);
        stream.v8(tag.controller);
        stream.v8(tag.interpolator);
    }
    RefView* textKeys = text;
    if (textKeys)
        textKeys->v21(stream);
    stream.v8(name);
    stream.v8(root);
    for (unsigned short j = 0; j < noteCount; j++)
        notes[j]->v21(stream);
    return true;
}



struct FixedStr
{
    char* m_handle;
    FixedStr() : m_handle((char*)(*reinterpret_cast<void * *>(&::DAT_0109b220)))
    {}
    static void AcquireReference(char* h)
    {
        if (h != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedIncrement((long*)(h - 8));
    }
    static void DecRef(char* h)
    {
        if (h != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedDecrement((long*)(h - 8));
    }
    FixedStr& operator=(const FixedStr& o)
    {
        char* h = o.m_handle;
        if (m_handle != h)
        {
            AcquireReference(h);
            DecRef(m_handle);
            m_handle = h;
        }
        return *this;
    }
};

struct FUN_00a312d0
{
    FixedStr m_kAVObjectName;
    FixedStr m_kPropertyType;
    FixedStr m_kCtlrType;
    FixedStr m_kCtlrID;
    FixedStr m_kInterpolatorID;
    void ClearIdentifiers();
    FUN_00a312d0(const FixedStr& a, const FixedStr& b, const FixedStr& c, const FixedStr& d, const FixedStr& e);
};

// @fnv 0x00a312d0
FUN_00a312d0::FUN_00a312d0(const FixedStr& akAVObjectName, const FixedStr& akPropertyType, const FixedStr& akCtlrType,
                           const FixedStr& akCtlrID, const FixedStr& akInterpolatorID)
{
    ClearIdentifiers();
    m_kAVObjectName = akAVObjectName;
    m_kPropertyType = akPropertyType;
    m_kCtlrType = akCtlrType;
    m_kCtlrID = akCtlrID;
    m_kInterpolatorID = akInterpolatorID;
}

extern int(* DAT_00fdf1c4)(void*);

struct S_00aa4060_Class
{
};

struct FUN_00a315b0_Elem
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;
};

class FUN_00a315b0_Base
{
  public:
};

class FUN_00a315b0_cls
{
  public:
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;

    FUN_00a315b0_cls* FUN_00a315b0(unsigned char acFlags);
};

struct a31740_Ref
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

struct a31740_Mem
{
};


struct FUN_00a31740_cls
{
    a31740_Ref* m_pReference;

    void* FUN_00a31740(unsigned char acFlags);
};

// Releases the referenced objects (decrementing refcounts and calling Release at zero) and optionally deallocates this or the array block based on acFlags.
// @fnv 0x00a31740
void* FUN_00a31740_cls::FUN_00a31740(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)this - 4;
        int i = *(int*)base;
        a31740_Ref** p = (a31740_Ref**)this + i;
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = p - 1;
                a31740_Ref* e = *p;
                if (e != 0 && InterlockedDecrement((long volatile*)&e->refCount) == 0)
                {
                    e->Release();
                }
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::a31740_Mem *>(&::g_memoryManager))))->FUN_00aa4060(base);
        }
        return base;
    }

    a31740_Ref* e = m_pReference;
    if (e != 0 && InterlockedDecrement((long volatile*)&e->refCount) == 0)
    {
        e->Release();
    }
    if (acFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::a31740_Mem *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}

extern int(* DAT_00fdf1c0)(void*);
extern int(* DAT_00fdf1c4)(void*);

struct FUN_00a317e0_ref
{
    virtual ~FUN_00a317e0_ref();
    virtual void DeleteThis();
    int m_uiRefCount;
};

struct FUN_00a317e0_interp
{
    void* m_spControllerInterpolator;
    void* unk04;
    void* unk08;
    void* unk0C;
};

struct FUN_00a317e0_tag
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct FUN_00a317e0_t
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    FUN_00a317e0_interp* m_pInterpArray;
    FUN_00a317e0_tag* m_pkIDTags;

    void AssignInterpolatorRef(int index, FUN_00a317e0_ref** output);
};

namespace fnv_00a30640 {
struct NiStringPtr
{
    char* m_kHandle;
};
}  // namespace fnv_00a30640
namespace fnv_00a30640 {
class NiControllerSequence
{
  public:
    NiStringPtr m_kName;
    NiStringPtr m_kParentName;
    NiStringPtr m_kSourceName;
    NiStringPtr m_kTargetName;
    NiStringPtr m_kControllerName;
    void ResetStrings();
};
}  // namespace fnv_00a30640
// @fnv 0x00a317e0
void FUN_00a317e0_t::AssignInterpolatorRef(int index, FUN_00a317e0_ref** output)
{
    FUN_00a317e0_ref* pNewRef = reinterpret_cast<FUN_00a317e0_ref*>(
        reinterpret_cast<FUN_00a317e0_interp*>(m_pInterpArray + index)->m_spControllerInterpolator);

    if (pNewRef)
        DAT_00fdf1c0(&pNewRef->m_uiRefCount);

    reinterpret_cast<::FUN_00a31260_StandIn *>((reinterpret_cast<FUN_00a317e0_interp*>(m_pInterpArray + index)))->FUN_00a31260();

    reinterpret_cast<::fnv_00a30640::NiControllerSequence*>(m_pkIDTags + index)->ResetStrings();

    FUN_00a317e0_ref* old = *output;
    int(* pfnDecrementRef)(void*) = DAT_00fdf1c4;

    if (old != pNewRef)
    {
        if (old)
        {
            if (pfnDecrementRef(&old->m_uiRefCount) == 0)
                old->DeleteThis();
        }

        *output = pNewRef;

        if (pNewRef)
            DAT_00fdf1c0(&pNewRef->m_uiRefCount);
    }

    if (pNewRef)
    {
        if (pfnDecrementRef(&pNewRef->m_uiRefCount) == 0)
            pNewRef->DeleteThis();
    }
}

namespace fnv_00a328b0 {

struct SeqExt : FUN_00a33bf0_s
{
    void FUN_00a328b0(float time, bool setControllerTimes);
};

// Computes time plus an offset, optionally writes time to each controller's time field, and stores the result in m_pad44[4].
// @fnv 0x00a328b0
void SeqExt::FUN_00a328b0(float time, bool setControllerTimes)
{
    float currentTime = time + m_fFirstKeyTime;
    if (setControllerTimes)
    {
        unsigned int index = 0;
        if (index < m_uiNumControlledBlocks)
        {
            do
            {
                SeqIDTag& tag = m_pkIDTags[index];
                void* controller = m_pInterpArray[index].m_pkController;
                if (controller && tag.m_kCtlrType != ::DAT_0109b220 &&
                    (!tag.m_kCtlrType || tag.m_kCtlrType[2] != 'T' || tag.m_kCtlrType[7] != 'f'))
                {
                    *reinterpret_cast<float*>(static_cast<char*>(controller) + 0x10) = time;
                }
                ++index;
            } while (index < m_uiNumControlledBlocks);
        }
    }
    *reinterpret_cast<float*>(&m_pad44[4]) = currentTime;
}
}  // namespace fnv_00a328b0


struct RefObj
{
    virtual void V00();
    virtual void Release();
    long m_iObjectReferenceCount;
};

struct SlotEntry
{
    RefObj* m_pEntryObject;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned char m_unk0c;
    unsigned char m_flag0d;
    unsigned char m_unk0e;
    unsigned char m_unk0f;
};

struct SlotInfo
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
};

struct FUN_00a32bc0_cls
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_uiItemCount;
    unsigned int m_unk10;
    SlotEntry* m_pSlots;
    SlotInfo* m_pInfos;

    int AssignSlot(RefObj* p1, uintptr_t p2, unsigned char p3);
};

struct FUN_00a34480_obj
{
    virtual void V00();
    virtual void V01();
    virtual FUN_00a34480_obj* V02();
    FUN_00a34480_obj* m_pNext;
    unsigned short m_word08;
    unsigned short unk0a;
    float m_f0c;
};


struct FUN_00a34480_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned short m_word24;
    unsigned short unk26;
    float m_f28;

    bool AssignControllers(void* a1, FUN_00a34480_obj* a2);
    bool FUN_00a34480(void* a1, FUN_00a34480_obj* a2);
};

// Walks the linked list from a2's V02() looking for DAT_011f36b4; if found, merges m_word24 into a2->m_word08, copies m_f28 to a2->m_f0c and calls AssignControllers.
// @fnv 0x00a34480
bool FUN_00a34480_cls::FUN_00a34480(void* a1, FUN_00a34480_obj* pNode)
{
    FUN_00a34480_obj* cur = 0;
    if (a1 != 0)
    {
        if (pNode != 0)
        {
            cur = pNode->V02();
            if (cur != 0)
            {
                do
                {
                    if (cur == (FUN_00a34480_obj*)&(*reinterpret_cast<int *>(&::g_011f36b4)))
                    {
                        goto found;
                    }
                    cur = cur->m_pNext;
                } while (cur != 0);
            }
        }
    }
    return false;

found:
    unsigned short flags = (unsigned short)(m_word24 + m_word24);
    flags = (unsigned short)(flags | (pNode->m_word08 & 0xfff9));
    pNode->m_word08 = flags;
    pNode->m_f0c = m_f28;
    pNode->m_word08 = (unsigned short)(pNode->m_word08 & 0xffef);
    return AssignControllers(a1, pNode);
}

extern char DAT_01096678, DAT_0109666c;
extern char DAT_01096664, DAT_01044c94, DAT_01044c90, DAT_0109665c;
extern char DAT_01096654, DAT_01096648, DAT_0109663c;
extern char DAT_01096630, DAT_01096624;

struct OutputArray
{
    void* unk00;
    void** data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short growth;
    void Append(void* value)
    {
        unsigned int index = length;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, (*(char * *)(&value)));
    }
};

struct ControlItem
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned char unk0c;
    unsigned char priority;
    unsigned short unk0e;
};
struct TagItem
{
    const char* first;
    const char* second;
    const char* third;
    const char* fourth;
    const char* fifth;
};

void* __cdecl FormatStringWithType(const char*, void*);

struct Position
{
    unsigned int i;
    unsigned int tagOffset;
};
struct Sequence
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int itemCount;
    void* unk10;
    ControlItem* controls;
    TagItem* tags;
    float mainWeight;
    void* unk20;
    void* interp;
    float fadeIn;
    float fadeOut;
    float duration;
    float offset;
    float rate;
    float extra3c;
    void* unk40;
    void* name;
    float start;
    float end;
    float total;
    void FUN_00a34540(OutputArray* output);
};

// Appends the sequence's base data and per-item key/value entries built from each tag and control priority to the output array.
// @fnv 0x00a34540
void Sequence::FUN_00a34540(OutputArray* output)
{
    reinterpret_cast<::A5D6E0This *>(this)->AppendCameraPathEntries((::NiTArray< ::BGSCameraPath *, ::NiTMallocInterface< ::BGSCameraPath *>> *)(output));
    output->Append(((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_011f36dc)))))));
    output->Append(FormatStringWithType(&DAT_01044a7c, name));
    output->Append(((void *)(::FUN_00a7d510(&DAT_01096678, itemCount))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_0105ac84, mainWeight))));
    output->Append(((void *)(::FUN_00a6d190(&DAT_0109666c, (intptr_t)(interp)))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_01096664, fadeIn))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_01044c94, fadeOut))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_01044c90, duration))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_0109665c, offset))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_01096654, start))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_010477f4, end))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_01044c90, total))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_01096648, rate))));
    output->Append(((void *)(::FUN_00a7d550(&DAT_0109663c, extra3c))));
    Position pos;
    pos.i = 0;
    if (pos.i < itemCount)
    {
        char key[128];
        char val[256];
        unsigned int controlOffset = 0;
        pos.tagOffset = 0;
        do
        {
            TagItem* tag = (TagItem*)((char*)tags + pos.tagOffset);
            ControlItem* ctrl = (ControlItem*)((char*)controls + controlOffset);
            ::NiSprintf(key, sizeof(key), &DAT_01096630, pos.i);
            ::NiSprintf(val, sizeof(val), &DAT_01096624, tag->first, tag->third, ctrl->priority);
            void* entry = ((void *)(::fnv_00a7d5e0::FUN_00a7d5e0(key, val)));
            unsigned int index = output->length;
            if (index >= output->capacity)
                reinterpret_cast<::ViewerStrings *>((output))->SetSize(index + output->growth);
            if (index >= output->length)
            {
                output->length = index + 1;
                if (entry)
                    output->populated++;
            }
            else if (entry)
            {
                if (!output->data[index])
                    output->populated++;
            }
            else if (output->data[index])
            {
                output->populated--;
            }
            output->data[index] = entry;
            pos.tagOffset += sizeof(TagItem);
            controlOffset += sizeof(ControlItem);
            ++pos.i;
        } while (pos.i < itemCount);
    }
}

static const float g_fSeqNegInfinity = -3.402823466e+38f;

struct SeqA34f20;

struct SeqPtrArray
{
    unsigned int AddSeq(SeqA34f20* const& pkSeq);
};

struct SeqOwner
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
    SeqPtrArray m_kPlayingSequences;
};

struct SeqA34f20
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    void* m_pInterpArray;
    void* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    SeqOwner* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    SeqA34f20* m_pkTimeSyncSequence;


    __forceinline bool SetState(int eState)
    {
        bool bWasInactive = m_eAnimationState == 0;
        m_eAnimationState = eState;
        if (bWasInactive)
        {
            m_pkOwnerManager->m_kPlayingSequences.AddSeq(this);
        }
        return bWasInactive;
    }

    bool StartSequence(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime,
                       SeqA34f20* pkTimeSyncSeq, bool bTransition);
};

namespace fnv_00a351d0 {
static float NEG_FLT_MAX = -3.402823466e+38f;

struct SeqSet
{
    void Add(void* const& item);
};
struct SeqOwner
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
    SeqSet m_kActive;
};
struct CtlrSeq : BaseH
{
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual bool Deactivate(float fEaseOutTime, bool bTransition);
    unsigned int m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float m_fDestWeight;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    float m_fWeightAdjustedLastTime;
    int unk38;
    int unk3C;
    SeqOwner* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    int unk54;
    int m_pkTimeSyncSequence;

    void SetState(int eState)
    {
        bool bWasInactive = (m_eAnimationState == 0);
        m_eAnimationState = eState;
        if (bWasInactive)
        {
            m_pkOwnerManager->m_kActive.Add((void* const&)(void*)this);
        }
    }
    bool CrossFadeTo(CtlrSeq* pkDestSequence, float fDuration, int iPriority, float fSourceWeight, float fDestWeight);
};

// @fnv 0x00a351d0
bool CtlrSeq::CrossFadeTo(CtlrSeq* pkDestSequence, float fDuration, int iPriority, float fSourceWeight,
                          float fDestWeight)
{
    Deactivate(0.0f, true);
    if (reinterpret_cast<::SeqA34f20 *>(this)->StartSequence((char)iPriority, false, fSourceWeight, fDuration, (::SeqA34f20 *)(pkDestSequence), true) &&
        pkDestSequence->m_eAnimationState == 0)
    {
        pkDestSequence->m_fDestWeight = fDestWeight;
        pkDestSequence->m_pkTimeSyncSequence = 0;
        reinterpret_cast<::FUN_00a30900_shell *>((pkDestSequence))->FUN_00a30900((char)iPriority);
        if (fDuration > 0.0f)
        {
            pkDestSequence->SetState(5);
            pkDestSequence->m_fStartTime = NEG_FLT_MAX;
            pkDestSequence->m_fEndTime = fDuration;
        }
        else
        {
            pkDestSequence->SetState(1);
            pkDestSequence->m_fStartTime = 0.0f;
        }
        pkDestSequence->m_fSequenceOffset = NEG_FLT_MAX;
        pkDestSequence->m_fWeightAdjustedLastTime = NEG_FLT_MAX;
        SetState(6);
        return true;
    }
    return false;
}
}  // namespace fnv_00a351d0


// @fnv 0x00aa10f0
void __cdecl FUN_00aa10f0(void* pv)
{
    if (pv != 0)
    {
        DAT_011f6080->allocator->Deallocate(pv, 9, (unsigned int)-1);
    }
}

struct FUN_00a30750_shell
{
    char* m_kPointA[5];
    void FUN_00a30750();
};
// @fnv 0x00a315b0
FUN_00a315b0_cls* FUN_00a315b0_cls::FUN_00a315b0(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        int i = ((int*)this)[-1];
        FUN_00a315b0_Elem* e = (FUN_00a315b0_Elem*)((char*)this + i * 20);
        i = i - 1;
        char* base = (char*)this - 4;
        if (i >= 0)
        {
            int(* pRelease)(void*) = DAT_00fdf1c4;
            do
            {
                e = (FUN_00a315b0_Elem*)((char*)e - 20);
                if ((intptr_t)e->m_10 != (*reinterpret_cast<int *>(&::DAT_0109b220)))
                {
                    pRelease(e->m_10 - 8);
                }
                if ((intptr_t)e->m_0c != (*reinterpret_cast<int *>(&::DAT_0109b220)))
                {
                    pRelease(e->m_0c - 8);
                }
                if ((intptr_t)e->m_08 != (*reinterpret_cast<int *>(&::DAT_0109b220)))
                {
                    pRelease(e->m_08 - 8);
                }
                if ((intptr_t)e->m_04 != (*reinterpret_cast<int *>(&::DAT_0109b220)))
                {
                    pRelease(e->m_04 - 8);
                }
                if ((intptr_t)e->m_00 != (*reinterpret_cast<int *>(&::DAT_0109b220)))
                {
                    pRelease(e->m_00 - 8);
                }
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::S_00aa4060_Class *>(&::g_memoryManager))))->FUN_00aa4060(base);
        }
        return (FUN_00a315b0_cls*)base;
    }

    reinterpret_cast<::FUN_00a30750_shell *>((((FUN_00a315b0_Base*)this)))->FUN_00a30750();
    if (acFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::S_00aa4060_Class *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}


// @fnv 0x00a30750
void FUN_00a30750_shell::FUN_00a30750()
{
    char* p;
    p = m_kPointA[4];
    if (p != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[3];
    if (p != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[2];
    if (p != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[1];
    if (p != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[0];
    if (p != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
        InterlockedDecrement((long*)(p - 8));
}

struct EqObj
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
    virtual bool equal(EqObj* other);
};
struct TCEq
{
};
struct SeqTagCmp
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    bool equal(const SeqTagCmp& x) const
    {
        return a == x.a && b == x.b && c == x.c && d == x.d && e == x.e;
    }
};
extern "C" int __cdecl FUN_00aa1360(const char* a, const char* b);
struct SeqTK
{
    EqObj* p;
    operator EqObj*() const
    {
        return p;
    }
    EqObj* operator->() const
    {
        return p;
    }
};
struct SeqEqStand : SequenceA30970
{
    SeqTK& textKeys()
    {
        return *(SeqTK*)&textKeys20;
    }
    EqObj* owner40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    void* root5c;
    unsigned char FUN_00a30fb0(SeqEqStand* other);
};
// Compares this sequence with another field by field, including interpolators, tags, text keys and owner, returning true only if all match.
// @fnv 0x00a30fb0
unsigned char SeqEqStand::FUN_00a30fb0(SeqEqStand* other)
{
    if (!reinterpret_cast<::A5d470Class *>((((TCEq*)this)))->IsSameAs((::A5d470Object *)(::NiObject *)((NiObject*)other)))
        return false;
    if (name08 != other->name08 && FUN_00aa1360(name08, other->name08))
        return false;
    if (arraySize0c != other->arraySize0c || arrayGrow10 != other->arrayGrow10)
        return false;
    for (unsigned int i = 0; i < arraySize0c; ++i)
    {
        if (!((FUN_00a30cc0_cls*)&interpolators14[i])->Equals((FUN_00a30cc0_cls*)&other->interpolators14[i]))
            return false;
        if (!((SeqTagCmp*)tags18)[i].equal(((SeqTagCmp*)other->tags18)[i]))
            return false;
    }
    if (weight1c != other->weight1c)
        return false;
    if ((textKeys() && !other->textKeys()) || (!textKeys() && other->textKeys()))
        return false;
    if (textKeys() && other->textKeys() && !textKeys()->equal(other->textKeys()))
        return false;
    if (cycleType24 != other->cycleType24)
        return false;
    if (frequency28 != other->frequency28 || begin2c != other->begin2c || end30 != other->end30)
        return false;
    if ((owner40 && !other->owner40) || (!owner40 && other->owner40))
        return false;
    if (owner40 && other->owner40 && !owner40->equal(other->owner40))
        return false;
    return root5c == other->root5c;
}

extern const char str_01020fd4[];
extern const char str_01020fc8[];
extern const char str_01020fc0[];
extern const char str_01020fb8[];
extern const char str_01020fac[];
extern const char str_01020fa0[];
extern const char str_01020f94[];
extern const char str_0109655c[];
struct S_00a31140_Allocator
{
};
// @fnv 0x00a31140
void* __cdecl FormatStringWithType(const char* pcText, void* arg2)
{
    void* esi = reinterpret_cast<::MemoryManagerStandIn *>(&(((S_00a31140_Allocator&)(*reinterpret_cast<::S_00aa4060_Class *>(&::g_memoryManager)))))->FUN_00aa3e40((unsigned int)strlen(pcText) + 0x20);
    const char* eax = 0;
    switch ((uintptr_t)arg2)
    {
    case 0:
        eax = str_01020fd4;
        break;
    case 1:
        eax = str_01020fc8;
        break;
    case 2:
        eax = str_01020fc0;
        break;
    case 3:
        eax = str_01020fb8;
        break;
    case 4:
        eax = str_01020fac;
        break;
    case 5:
        eax = str_01020fa0;
        break;
    case 6:
        eax = str_01020f94;
        break;
    default:
        break;
    }
    std::sprintf((char *)(esi), str_0109655c, pcText, eax);
    return esi;
}

// Copy a group of five ref-counted fixed strings (the ref count sits 8 bytes before the text).



class A1400FixedString
{
  public:
    A1400FixedString& operator=(const A1400FixedString& kOther)
    {
        if (m_pcHandle != kOther.m_pcHandle)
        {
            char* pcNew = kOther.m_pcHandle;
            if (pcNew != ::DAT_0109b220)
                InterlockedIncrement((long volatile*)(pcNew - 8));
            if (m_pcHandle != ::DAT_0109b220)
                InterlockedDecrement((long volatile*)(m_pcHandle - 8));
            m_pcHandle = pcNew;
        }
        return *this;
    }

    char* m_pcHandle;
};

class A1400StringGroup
{
  public:
    A1400FixedString m_kName0;
    A1400FixedString m_kName1;
    A1400FixedString m_kName2;
    A1400FixedString m_kName3;
    A1400FixedString m_kName4;

    A1400StringGroup& FUN_00a31400(const A1400StringGroup& kOther);
};
namespace fnv_00a32330
{
struct InterpArrayItem;
struct IDTag;
struct SequenceArrays
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    InterpArrayItem* m_pInterpArray;
    IDTag* m_pkIDTags;

    bool FUN_00a32330();
};
}
// @fnv 0x00a32bc0
int FUN_00a32bc0_cls::AssignSlot(RefObj* apRef, uintptr_t auiValue, unsigned char aucFlag)
{
    unsigned int count = m_uiItemCount;
    unsigned int idx = 0;
    for (; idx < count; ++idx)
    {
        if (m_pSlots[idx].m_pEntryObject == 0)
        {
            break;
        }
    }
    if (idx == count)
    {
        if (!reinterpret_cast<::fnv_00a32330::SequenceArrays *>(this)->FUN_00a32330())
        {
            return -1;
        }
    }
    SlotEntry* slot = &m_pSlots[idx];
    if (slot->m_pEntryObject != apRef)
    {
        RefObj* old = slot->m_pEntryObject;
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Release();
            }
        }
        slot->m_pEntryObject = apRef;
        if (apRef != 0)
        {
            InterlockedIncrement(&apRef->m_iObjectReferenceCount);
        }
    }
    reinterpret_cast<::A1400StringGroup *>(&(m_pInfos[idx]))->FUN_00a31400((*(const ::A1400StringGroup *)(auiValue)));
    m_pSlots[idx].m_flag0d = aucFlag;
    return idx;
}

// Assigns each of the five fixed-string members from kOther and returns *this.
// @fnv 0x00a31400
A1400StringGroup& A1400StringGroup::FUN_00a31400(const A1400StringGroup& kOther)
{
    m_kName0 = kOther.m_kName0;
    m_kName1 = kOther.m_kName1;
    m_kName2 = kOther.m_kName2;
    m_kName3 = kOther.m_kName3;
    m_kName4 = kOther.m_kName4;
    return *this;
}

struct IStreamA33a50
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(IStreamA33a50*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* pv, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = uiBytes;
        m_uiStreamFlags += m_pfnRead(this, pv, uiBytes, &uiComponentSize, 1);
    }
};
struct StreamA33a50
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
    unsigned int m_uiNifVersion;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    IStreamA33a50* m_pUnderlyingStream;
};
struct IDTagA33a50
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
    void ReadFromStream(StreamA33a50& kStream, unsigned int& uiPaletteLink);
};

// @fnv 0x00a33a50
void IDTagA33a50::ReadFromStream(StreamA33a50& kStream, unsigned int& uiPaletteLink)
{
    if (kStream.m_uiNifVersion < 0x0A010071)
    {
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kAVObjectName));
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kPropertyType));
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kCtlrType));
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kCtlrID));
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kInterpolatorID));
    }
    else if (kStream.m_uiNifVersion < 0x14010001)
    {
        uiPaletteLink = ((uintptr_t)(reinterpret_cast<::NiStream *>(&(kStream))->DeserializeObject()));
        uintptr_t uiAVObjectNameOffset = 0;
        uintptr_t uiPropertyTypeOffset = 0;
        uintptr_t uiCtlrTypeOffset = 0;
        uintptr_t uiCtlrIDOffset = 0;
        uintptr_t uiInterpolatorIDOffset = 0;
        kStream.m_pUnderlyingStream->Read(&uiAVObjectNameOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiPropertyTypeOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiCtlrTypeOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiCtlrIDOffset, 4);
        kStream.m_pUnderlyingStream->Read(&uiInterpolatorIDOffset, 4);
        m_kAVObjectName = (char*)uiAVObjectNameOffset;
        m_kPropertyType = (char*)uiPropertyTypeOffset;
        m_kCtlrType = (char*)uiCtlrTypeOffset;
        m_kCtlrID = (char*)uiCtlrIDOffset;
        m_kInterpolatorID = (char*)uiInterpolatorIDOffset;
    }
    else
    {
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kAVObjectName));
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kPropertyType));
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kCtlrType));
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kCtlrID));
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kInterpolatorID));
    }
}

struct AnimationSequence;
struct UpdateActiveArray
{
    void FindOrAdd(AnimationSequence* const& sequence);
};
struct UpdateNote
{
    int unk00;
    int unk04;
    int unk08;
    float time;
};
struct UpdateNoteManager
{
};
struct UpdateOwner
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
    UpdateActiveArray active;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    UpdateNoteManager* noteManager;
};
struct AnimationSequence : S_00a30880_Base
{
    unsigned int refs;
    char* name;
    unsigned int count;
    unsigned int grow;
    void* interpolators;
    void* tags;
    float weight;
    void* keys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float lastTime;
    float weightedTime;
    float scaledTime;
    UpdateOwner* owner;
    int state;
    float offset;
    float startTime;
    float endTime;
    float destFrame;
    AnimationSequence* partner;
    char* root;
    int unk60;
    int unk64;
    short noteIndex;
    unsigned short unk6a;
    UpdateNote** notes;
    unsigned short noteCount;
    float GetMorphedTime(AnimationSequence*, float);
    void FUN_00a34ba0(float time, bool update);
    __forceinline bool SetState(int value)
    {
        bool inactive = state == 0;
        state = value;
        if (inactive)
        {
            AnimationSequence* self = this;
            owner->active.FindOrAdd(self);
        }
        return inactive;
    }
};
// @fnv 0x00a34ba0
void AnimationSequence::FUN_00a34ba0(float time, bool update)
{
    if (state == 0)
    {
        noteIndex = -1;
        return;
    }
    if (offset == g_fSeqNegInfinity)
        offset = -time;
    if (startTime == g_fSeqNegInfinity)
    {
        startTime = time;
        endTime += time;
    }
    float ease = 1.0f;
    float transition = 1.0f;
    switch (state)
    {
    case 2:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            ease = (time - startTime) / (endTime - startTime);
        }
        else
        {
            state = 1;
            startTime = 0.0f;
        }
        break;
    case 5:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            transition = (time - startTime) / (endTime - startTime);
        }
        else
        {
            if (destFrame != g_fSeqNegInfinity)
            {
                offset = destFrame - time;
                destFrame = DAT_01015f5c;
            }
            state = 1;
            startTime = 0.0f;
        }
        break;
    case 3:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            ease = (endTime - time) / (endTime - startTime);
        }
        else
        {
            Target(0.0f, false);
            return;
        }
        break;
    case 6: {
        float partnerTime = partner->GetMorphedTime(this, time + offset);
        partnerTime /= partner->frequency;
        partner->offset = partnerTime - time;
        SetState(4);
    }
    case 4:
        if (endTime > time)
        {
            if (startTime > time)
                time = startTime;
            transition = (endTime - time) / (endTime - startTime);
        }
        else
        {
            Target(0.0f, true);
            return;
        }
        break;
    case 1:
        startTime = scaledTime;
        break;
    }
    float fOldScaledTime = scaledTime;
    if (update)
    {
        float localTime;
        if (destFrame != g_fSeqNegInfinity)
            localTime = destFrame;
        else if (partner)
        {
            if (partner->lastTime != time + partner->offset)
                partner->FUN_00a34ba0(time, false);
            localTime = GetMorphedTime(partner, time + partner->offset);
            localTime /= frequency;
        }
        else
            localTime = time + offset;
        reinterpret_cast<::FUN_00a32290_Cls *>(this)->FUN_00a32290(weight * transition, ease, reinterpret_cast<::SequenceA30970 *>(this)->FUN_00a30970(localTime, true));
        if (notes)
        {
            if (fOldScaledTime > scaledTime)
                noteIndex = -1;
            for (short i = noteIndex + 1; i < noteCount; ++i)
            {
                if (!(notes[i]->time < localTime))
                    break;
                noteIndex = i;
                reinterpret_cast<::FUN_00a41410_cls *>((owner->noteManager))->DispatchByKey((::HandlerArg *)(notes[i]));
            }
        }
    }
}

struct RefObject
{
    virtual void Virtual0();
    virtual void Release();
    volatile long referenceCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
};

struct NiPointerRef
{
    RefObject* m_pObject;
    void operator=(RefObject* p)
    {
        RefObject* pOld = m_pObject;
        RefObject* pNew = p;
        if (pOld != pNew)
        {
            if (pOld)
                pOld->DecRefCount();
            m_pObject = pNew;
            if (pNew)
                pNew->IncRefCount();
        }
    }
};

struct NiItem
{
    unsigned int m0;
    NiPointerRef object4;
    unsigned int m8;
    unsigned int mc;
};

struct NiSequenceSource
{
    unsigned int unk00;
    unsigned int type04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int versionD8;
};

struct SequenceLink : NiObject
{
    unsigned int unk08;
    unsigned int count0c;
    unsigned int unk10;
    NiItem* items14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPointerRef object20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    RefObject* object40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    NiPointerRef* objects6c;
    unsigned short count70;
    void LinkSequenceSource(NiSequenceSource*);
};

// @fnv 0x00a326e0
void SequenceLink::LinkSequenceSource(NiSequenceSource* source)
{
    ::FUN_00a89af0((intptr_t)this);
    if (source->versionD8 < 0x0a010068)
    {
        object20 = ((::RefObject *)(reinterpret_cast<::NiStream *>((source))->GetLoadedObject()));
        unsigned int i = 0;
        if (i < count0c)
        {
            do
            {
                items14[i].object4 = ((::RefObject *)(reinterpret_cast<::NiStream *>((source))->GetLoadedObject()));
                ++i;
            } while (i < count0c);
        }
    }
    else
    {
        object20 = ((::RefObject *)(reinterpret_cast<::NiStream *>((source))->GetLoadedObject()));
        object40 = ((::RefObject *)(reinterpret_cast<::NiStream *>((source))->GetLoadedObject()));
        if (source->type04 > 0x15 && source->type04 < 0x1d)
        {
            reinterpret_cast<::NiStream *>((source))->GetLoadedObject();
            objects6c = 0;
            count70 = 0;
        }
        if (source->type04 > 0x1c)
        {
            unsigned short i = 0;
            if (i < count70)
            {
                do
                {
                    objects6c[i] = ((::RefObject *)(reinterpret_cast<::NiStream *>((source))->GetLoadedObject()));
                    ++i;
                } while (i < count70);
            }
        }
    }
}

extern int(* DAT_00fdf1c0)(void*);

struct A33950RefObject
{
    virtual void Unused();
    virtual void Release();
    volatile long refCount;
};

struct A33950BinaryInput
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* readFn)(A33950BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* destination, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        position += readFn(this, destination, bytes, &componentSize, 1);
    }
};

struct A33950Stream
{
    unsigned int& Version()
    {
        return *(unsigned int*)((char*)this + 0xd8);
    }
    unsigned int& Count()
    {
        return *(unsigned int*)((char*)this + 4);
    }
    A33950BinaryInput* Input()
    {
        return *(A33950BinaryInput**)((char*)this + 0x24c);
    }
};

struct A33950Object
{
    A33950RefObject* first;
    A33950RefObject* second;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char flag0d;
    void LoadFromStream(A33950Stream* stream);
};

// @fnv 0x00a33950
void A33950Object::LoadFromStream(A33950Stream* stream)
{
    A33950RefObject* next = ((::A33950RefObject *)(reinterpret_cast<::NiStream *>((stream))->DeserializeObject()));
    A33950RefObject* previous = first;
    if (previous != next)
    {
        if (previous && InterlockedDecrement(&previous->refCount) == 0)
            previous->Release();
        first = next;
        if (next)
            DAT_00fdf1c0((void*)&next->refCount);
    }

    next = ((::A33950RefObject *)(reinterpret_cast<::NiStream *>((stream))->DeserializeObject()));
    previous = second;
    if (previous != next)
    {
        if (previous && InterlockedDecrement(&previous->refCount) == 0)
            previous->Release();
        second = next;
        if (next)
            DAT_00fdf1c0((void*)&next->refCount);
    }

    if (stream->Version() < 0x0a01006f)
    {
        unsigned short oldValue;
        reinterpret_cast<::NiStream *>((stream))->DeserializeObject();
        stream->Input()->Read(&oldValue, 2);
    }
    if (stream->Count() > 0)
        stream->Input()->Read(&flag0d, 1);
}



struct FUN_00a344f0_cls
{
    void* FUN_00a344f0(uintptr_t param);
};


struct FUN_00a350d0_seq : SeqA34f20
{
    bool FUN_00a350d0(SeqA34f20* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                      float fTargetWeight, SeqA34f20* pkPartner);
};

// @fnv 0x00a350d0
bool FUN_00a350d0_seq::FUN_00a350d0(SeqA34f20* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                                    float fTargetWeight, SeqA34f20* pkPartner)
{
    ((S_00a30880_Base*)this)->Target(0.0f, 1);

    if (fTime <= 0.0f)
        fTime = DAT_010141cc;

    if (pkTarget->m_eAnimationState != 0 || m_eAnimationState != 0)
        return false;

    m_fWeight = fSeqWeight;
    m_pkTimeSyncSequence = 0;

    reinterpret_cast<::FUN_00a30900_shell *>(this)->FUN_00a30900((char)iPriority);
    SetState(1);

    m_fStartTime = 0.0f;
    m_fLastTime = DAT_01015f5c;

    if (!pkTarget->StartSequence((char)iPriority, false, fTargetWeight, fTime, pkPartner, true))
        return false;

    ((S_00a30880_Base*)this)->Target(fTime, 1);

    m_fDestinationFrame = m_fScaledLastTime / m_fFrequency;
    pkTarget->m_fDestinationFrame = m_fTimeout / pkTarget->m_fFrequency;
    return true;
}

struct NiGlobalStringTable
{
    static char* AddString(const char* pcString);
};

struct NiStringPalette
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_pString;
};

struct OffsetString
{
    char* m_kHandle;
    static void DecRefHandle(char* h)
    {
        if (h != ::DAT_0109b220)
            InterlockedDecrement((long volatile*)(h - 8));
    }
    OffsetString& operator=(const char* pcString)
    {
        if (m_kHandle != pcString)
        {
            char* pcOld = m_kHandle;
            m_kHandle = NiGlobalStringTable::AddString(pcString);
            DecRefHandle(pcOld);
        }
        return *this;
    }
};

struct SeqIDTagOffsets
{
    OffsetString m_kAVObjectName;
    OffsetString m_kPropertyType;
    OffsetString m_kCtlrType;
    OffsetString m_kCtlrID;
    OffsetString m_kInterpolatorID;
    void LoadFromPalette(NiStringPalette* pkPalette, int iUnused);
};

// Resolves five string offsets against pkPalette->m_pString, assigning each to the matching OffsetString field when the offset is not -1.
// @fnv 0x00a30d40
void SeqIDTagOffsets::LoadFromPalette(NiStringPalette* pkPalette, int iUnused)
{
    intptr_t iAVObjectNameOffset = (intptr_t)m_kAVObjectName.m_kHandle;
    intptr_t iPropertyTypeOffset = (intptr_t)m_kPropertyType.m_kHandle;
    intptr_t iCtlrTypeOffset = (intptr_t)m_kCtlrType.m_kHandle;
    intptr_t iCtlrIDOffset = (intptr_t)m_kCtlrID.m_kHandle;
    intptr_t iInterpolatorIDOffset = (intptr_t)m_kInterpolatorID.m_kHandle;
    char* pcNullHandle = ::DAT_0109b220;
    OffsetString* apkOffsets[5] = {&m_kAVObjectName, &m_kPropertyType, &m_kCtlrType, &m_kCtlrID, &m_kInterpolatorID};
    for (int i = 0; i < 5; i++)
        apkOffsets[i]->m_kHandle = pcNullHandle;

    if (iAVObjectNameOffset != -1)
        m_kAVObjectName = pkPalette->m_pString + iAVObjectNameOffset;
    if (iPropertyTypeOffset != -1)
        m_kPropertyType = pkPalette->m_pString + iPropertyTypeOffset;
    if (iCtlrTypeOffset != -1)
        m_kCtlrType = pkPalette->m_pString + iCtlrTypeOffset;
    if (iCtlrIDOffset != -1)
        m_kCtlrID = pkPalette->m_pString + iCtlrIDOffset;
    if (iInterpolatorIDOffset != -1)
        m_kInterpolatorID = pkPalette->m_pString + iInterpolatorIDOffset;

    OffsetString::DecRefHandle(pcNullHandle);
}


struct A31500Ref
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};

struct A31500Item
{
    A31500Ref* m_spControllerInterpolator;
    A31500Ref* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned int m_uiValue1;

    static void Release(A31500Ref* pkObject)
    {
        if (pkObject && InterlockedDecrement(&pkObject->m_uiRefCount) == 0)
            pkObject->DeleteThis();
    }

    A31500Item* FUN_00a31500(unsigned char m_ucEntryType);
};
// @fnv 0x00a35640
void FUN_00a35640_shell::FUN_00a35640()
{
    *reinterpret_cast<void**>(this) = &DAT_01096584;

    if (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x44) != 0)
    {
        reinterpret_cast<FUN_00a35030_shell*>(this)->SetEaseOut(0.0f, false);
    }

    if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x14) != 0)
    {
        reinterpret_cast<::A31500Item *>((reinterpret_cast<FUN_00a31500_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x14))))->FUN_00a31500(3);
    }

    if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18) != 0)
    {
        reinterpret_cast<::FUN_00a315b0_cls *>((reinterpret_cast<FUN_00a315b0_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18))))->FUN_00a315b0(3);
    }

    if (*reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(this) + 0x70) > 0 &&
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x6c) != 0)
    {
        reinterpret_cast<::FUN_00a31740_cls *>((reinterpret_cast<FUN_00a31740_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x6c))))->FUN_00a31740(3);
    }

    int(* pDecrementRef)(void*) = DAT_00fdf1c4;

    void* p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x64);
    if (p != 0)
    {
        if (pDecrementRef(reinterpret_cast<char*>(p) + 4) == 0)
        {
            reinterpret_cast<RefBase*>(p)->Release();
        }
    }

    void* pString = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x5c);
    if (pString != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
    {
        pDecrementRef(reinterpret_cast<char*>(pString) - 8);
    }

    p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x20);
    if (p != 0)
    {
        if (pDecrementRef(reinterpret_cast<char*>(p) + 4) == 0)
        {
            reinterpret_cast<RefBase*>(p)->Release();
        }
    }

    pString = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x8);
    if (pString != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
    {
        pDecrementRef(reinterpret_cast<char*>(pString) - 8);
    }

    reinterpret_cast<class ::FUN_00a5d3d0 *>((reinterpret_cast<NiRefObject*>(this)))->FUN_00a5d3d0::~FUN_00a5d3d0();
}

// Releases references for this item or preceding items, conditionally calls another function, and returns this or the count address.
// @fnv 0x00a31500
A31500Item* A31500Item::FUN_00a31500(unsigned char m_ucEntryType)
{
    if (m_ucEntryType & 2)
    {
        int* piItemCount = reinterpret_cast<int*>(this) - 1;
        int iItemCount = *piItemCount;
        A31500Item* pkItem = this + iItemCount;
        while (--iItemCount >= 0)
        {
            --pkItem;
            Release(pkItem->m_pkController);
            Release(pkItem->m_spControllerInterpolator);
        }
        if (m_ucEntryType & 1)
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::S_00aa4060_Class *>(&::g_memoryManager))))->FUN_00aa4060(piItemCount);
        return reinterpret_cast<A31500Item*>(piItemCount);
    }
    reinterpret_cast<::FUN_00a30700_T *>(this)->ReleaseRefs();
    if (m_ucEntryType & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::S_00aa4060_Class *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

struct Rtti31910
{
    const char* name;
    Rtti31910* parent;
};
struct Node31910;
struct Blend31910
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags;
};
struct BlendTransform31910
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct MorphItem31910
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
    const char* name;
};
struct Morph31910
{
    int unk00;
    int unk04;
    int unk08;
    MorphItem31910* items;
    unsigned int count;
};
struct Node31910
{
    virtual void V00();
    virtual void V01();
    virtual Rtti31910* GetRTTI();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual Node31910* FindObject(const void*);
    virtual void V36();
    virtual void V37();
    virtual void SetTarget(Node31910*);
    long refCount;
    union
    {
        const char* name;
        unsigned short flags08;
    };
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    uintptr_t flags30;

};
struct NiSingleInterpControllerBase : Node31910
{
    NiSingleInterpControllerBase();
};
struct Controller31910 : NiSingleInterpControllerBase
{
    BlendTransform31910* blends;
    Node31910** targets;
    unsigned short count;
    unsigned short unk3e;
};
struct Owner31910
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
    Node31910* root;
    Node31910* controller;
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
    unsigned char skipAccum;
};
struct Entry31910
{
    Morph31910* interpolator;
    Node31910* controller;
    Blend31910* blend;
    unsigned char index;
    unsigned char priority;
    unsigned short unk0e;
};
struct Sequence31910
{
    void* vtable;
    int refs;
    const char* name;
    unsigned int count;
    unsigned int grow;
    Entry31910* entries;
    TagItem* tags;
    float weight;
    void* keys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float last;
    float weighted;
    float scaled;
    Owner31910* owner;
    int state;
    float offset;
    float start;
    float stop;
    float dest;
    void* partner;
    const char* rootName;
    Node31910* accum;
    bool FUN_00a31910(Node31910*, Node31910*, int);
};
extern unsigned int DAT_011f36c8, DAT_011f36d0;
extern const char* DAT_011f36c4;
extern const char* DAT_011f36cc;
extern const char DAT_01096564;
extern void* DAT_01096444;
void __cdecl FUN_00fdad60();
void __cdecl FUN_00fdad80();

struct NiMultiTargetTransformController : Controller31910
{
    virtual void V00();
    NiMultiTargetTransformController(unsigned short n)
    {
        count = 0;
        blends = 0;
        targets = 0;
        reinterpret_cast<::Controller *>(this)->FUN_00a2feb0(n);
    }
};
static bool IsKind31910(Node31910* node, Rtti31910* type)
{
    Rtti31910* rtti = node->GetRTTI();
    while (rtti)
    {
        if (rtti == type)
            return true;
        rtti = rtti->parent;
    }
    return false;
}
static void Retain31910(Node31910* p)
{
    if (p)
        InterlockedIncrement(&p->refCount);
}
static void Release31910(Node31910* p)
{
    if (p && !InterlockedDecrement(&p->refCount))
        p->V01();
}
struct ControllerPtr31910
{
    Controller31910* p;
    ControllerPtr31910(Controller31910* v) : p(v)
    {
        Retain31910(p);
    }
    operator Controller31910*() const
    {
        return p;
    }
    Controller31910* operator->() const
    {
        return p;
    }
    ControllerPtr31910& operator=(Controller31910* v)
    {
        if (p != v)
        {
            Release31910(p);
            p = v;
            Retain31910(p);
        }
        return *this;
    }
};
static void Assign31910(Node31910*& dst, Node31910* src)
{
    if (dst != src)
    {
        Release31910(dst);
        dst = src;
        Retain31910(src);
    }
}
static const char* MorphType31910()
{
    if (!(DAT_011f36c8 & 1))
    {
        DAT_011f36c8 |= 1;
        DAT_011f36c4 = ::NiGlobalStringTable::AddString(&DAT_01096564);
        std::atexit(FUN_00fdad60);
    }
    return DAT_011f36c4;
}
static __forceinline unsigned short FindTarget31910(Controller31910* c, Node31910* node)
{
    for (unsigned short i = 0; i < c->count; ++i)
        if (c->targets[i] == node)
            return i;
    return ::NiInterpController::INVALID_INDEX;
}
static __forceinline unsigned short AddTarget31910(Controller31910* c, Node31910* node)
{
    for (unsigned short i = 0; i < c->count; ++i)
        if (!c->targets[i])
        {
            c->targets[i] = node;
            node->flags30 |= 0x80;
            return i;
        }
    return ::NiInterpController::INVALID_INDEX;
}
// @fnv 0x00a31910
bool Sequence31910::FUN_00a31910(Node31910* target, Node31910* root, int unused)
{
    bool spMorphController;
    spMorphController = false;
    Controller31910* ctrl = (Controller31910*)((::Node31910 *)(reinterpret_cast<::MyHost *>((target))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<::Rtti31910 *>(&::g_011f36bc))))));
    Retain31910(ctrl);
    Controller31910* pMorphCtrl = (Controller31910*)((::Node31910 *)(reinterpret_cast<::MyHost *>((target))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<::Rtti31910 *>(&::g_011f36e4))))));
    Retain31910(pMorphCtrl);
    unsigned short uiMorphEntries = 0, usMorphTargetCount = 0;
    for (unsigned int i = 0; i < count; i++)
    {
        TagItem& v = tags[i];
        if (v.third != (const char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)) && MorphType31910() == v.third)
        {
            usMorphTargetCount += (unsigned short)entries[i].interpolator->count;
            ++uiMorphEntries;
        }
    }
    if (!ctrl || (!pMorphCtrl && uiMorphEntries))
    {
        unsigned short usExistingTargets = 0;
        Node31910* morphIndex = 0;
        if (root)
        {
            morphIndex = IsKind31910(root, &(*reinterpret_cast<::Rtti31910 *>(&::g_011f4a04))) ? root : 0;
        }
        if (morphIndex)
            usExistingTargets = (unsigned short)(reinterpret_cast<::NiD3DShaderProgram *>((morphIndex))->GetCodeSize() - usMorphTargetCount);
        else
            for (unsigned int i = 0; count > i; i++)
            {
                const char* cnt;
                cnt = tags[i].third;
                if (cnt != (const char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)) && cnt && cnt[2] == 'T' && cnt[7] == 'f')
                    usExistingTargets++;
            }
        if (!usExistingTargets && !uiMorphEntries)
        {
            Release31910(pMorphCtrl);
            Release31910(ctrl);
            return false;
        }
        if (usExistingTargets && !ctrl)
        {
            Controller31910* tag;
            tag = (Controller31910*)FUN_00aa13e0(0x40);
            if (tag)
            {
                ctrl = new (tag) NiMultiTargetTransformController(usExistingTargets);
                Retain31910(ctrl);
            }
            ctrl->SetTarget(target);
            ctrl->flags08 |= 0x20;
            spMorphController = true;
            if (target == owner->root)
            {
                reinterpret_cast<::ControllerOwner *>((target))->FUN_00a5c480((::NiTimeController *)(ctrl));
                Assign31910((Node31910*&)ctrl->flags30, owner->controller);
                Assign31910(owner->controller, ctrl);
            }
        }
        if (uiMorphEntries && !pMorphCtrl)
        {
            Controller31910* tag = (Controller31910*)FUN_00aa13e0(0x44);
            if (tag)
            {
                tag = ((::Controller31910 *)(new ((void *)(tag)) ::FUN_00a36070(uiMorphEntries, usMorphTargetCount)));
                if (tag)
                {
                    pMorphCtrl = tag;
                    Retain31910(pMorphCtrl);
                }
            }
            pMorphCtrl->SetTarget(target);
            pMorphCtrl->flags08 |= 0x20;
            spMorphController = true;
            if (target == owner->root)
            {
                reinterpret_cast<::ControllerOwner *>((target))->FUN_00a5c480((::NiTimeController *)(pMorphCtrl));
                Assign31910((Node31910*&)pMorphCtrl->flags30, owner->controller);
                Assign31910(owner->controller, pMorphCtrl);
            }
        }
    }
    int idx = 0;
    if (!(DAT_011f36d0 & 1))
    {
        DAT_011f36d0 |= 1;
        DAT_011f36cc = ::NiGlobalStringTable::AddString(&::DAT_0101e460);
        std::atexit(FUN_00fdad80);
    }
    for (unsigned int i = 0; i < count; i++)
    {
        Entry31910& entry = entries[i];
        TagItem& v = tags[i];
        if (v.third != (const char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)) && v.third && v.third[2] == 'T' && v.third[7] == 'f')
        {
            Node31910* spTransformController = root->FindObject(&v);
            if (!spTransformController || (accum == spTransformController && owner->skipAccum))
                continue;
            Node31910* z = ((::Node31910 *)(reinterpret_cast<::MyHost *>((spTransformController))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<::Rtti31910 *>(&::g_011f36ec))))));
            unsigned short s = FindTarget31910(ctrl, spTransformController);
            if (s == ::NiInterpController::INVALID_INDEX)
            {
                s = AddTarget31910(ctrl, spTransformController);
                if (s == ::NiInterpController::INVALID_INDEX)
                    continue;
            }
            else
            {
                ctrl->targets[s] = spTransformController;
                spTransformController->flags30 |= 0x80;
            }
            if (spTransformController->name != DAT_011f36cc)
                reinterpret_cast<::ControllerOwner *>((spTransformController))->FUN_00a5c480((::NiTimeController *)(z));
            Assign31910(entry.controller, ctrl);
            entry.blend = (Blend31910*)&ctrl->blends[s];
            entry.blend->flags |= 1;
        }
        else if (v.third != (const char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)) && MorphType31910() == v.third)
        {
            Morph31910* interp = entry.interpolator;
            volatile unsigned int s;
            for (unsigned int j = 0; j < interp->count; j++)
            {
                MorphItem31910* item = &interp->items[j];
                Node31910* spTransformController = root->FindObject(&item->name);
                unsigned short usMorphSlot = reinterpret_cast<::FUN_00a35910_shell *>((pMorphCtrl))->FindIndexByValue((::NiAVObject *)(spTransformController));
                if (usMorphSlot == ::NiInterpController::INVALID_INDEX)
                    s = reinterpret_cast<::FUN_00a35fe0_shell *>((pMorphCtrl))->FUN_00a35fe0((::Target_00a35fe0 *)(spTransformController), idx, item);
                else
                    reinterpret_cast<::FUN_00a35f70_struct *>((pMorphCtrl))->SetSlotEntry(usMorphSlot, spTransformController, idx, item);
            }
            Assign31910(entry.controller, pMorphCtrl);
            entry.blend = ((::Blend31910 *)(reinterpret_cast<::BSMultiTargetTreadTransfController *>((pMorphCtrl))->GetInterpolator(idx)));
            entry.blend->flags |= 1;
            idx += 1;
        }
    }
    Release31910(pMorphCtrl);
    Release31910(ctrl);
    return spMorphController;
}

struct TimedTextEntry
{
    float m_fTime;
    char* m_kText;

    float GetTime() const
    {
        return m_fTime;
    }
    const char* GetText() const
    {
        return m_kText;
    }
};

struct NiTextKeyExtraData
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumKeys;
    TimedTextEntry* m_pKeys;

    TimedTextEntry* GetKeys(unsigned int& uiNumKeys) const
    {
        uiNumKeys = m_uiNumKeys;
        return m_pKeys;
    }
};

int __cdecl FUN_00aa1370(const char*, const char*, unsigned int);
int __cdecl FUN_00aa1360(const char*, const char*);

// Interpolates between matching key times in this sequence using surrounding morph-key times from the partner sequence.
// @fnv 0x00a32010
float AnimationSequence::GetMorphedTime(AnimationSequence* pkPartnerSequence, float fFrameTime)
{
    TimedTextEntry* pkNextKey = 0;
    float fPartnerTime = reinterpret_cast<::SequenceA30970 *>((pkPartnerSequence))->FUN_00a30970(fFrameTime, false);

    unsigned int uiNumPartnerKeys;
    TimedTextEntry* pkPartnerKeys = ((NiTextKeyExtraData*)pkPartnerSequence->keys)->GetKeys(uiNumPartnerKeys);

    TimedTextEntry* pkFirstKey = 0;
    TimedTextEntry* pkPrevKey = 0;
    TimedTextEntry* pkLastKey = 0;
    unsigned int ui;
    for (ui = 0; ui < uiNumPartnerKeys; ui++)
    {
        const char* pcText = pkPartnerKeys[ui].GetText();
        if (pcText && FUN_00aa1370(pcText, ::g_kTextKeyA, (*reinterpret_cast<int *>((void *)&::g_kTextKeyB))) == 0)
        {
            pkLastKey = &pkPartnerKeys[ui];
            if (!pkFirstKey)
                pkFirstKey = &pkPartnerKeys[ui];

            if (pkPartnerKeys[ui].GetTime() < fPartnerTime)
                pkPrevKey = &pkPartnerKeys[ui];
            else if (!pkNextKey)
                pkNextKey = &pkPartnerKeys[ui];
        }
    }

    bool bHasKeyPair = false;
    float fRatio;
    if (pkNextKey && pkPrevKey)
    {
        float fPriorKeyTime = pkPrevKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (pkNextKey->GetTime() - fPriorKeyTime);
    }
    else if (!pkNextKey)
    {
        float fPriorKeyTime = pkPrevKey->GetTime();
        float fNextTime = pkPartnerSequence->end - pkPartnerSequence->begin + pkFirstKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (fNextTime - fPriorKeyTime);
        pkNextKey = pkFirstKey;
        bHasKeyPair = true;
    }
    else
    {
        float fPriorKeyTime = pkPartnerSequence->begin - pkPartnerSequence->end + pkLastKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (pkNextKey->GetTime() - fPriorKeyTime);
        pkPrevKey = pkLastKey;
    }

    unsigned int uiNumKeys;
    TimedTextEntry* pkKeys = ((NiTextKeyExtraData*)keys)->GetKeys(uiNumKeys);

    bool bFoundPrev = (pkPrevKey == 0);
    bool bFoundNext = (pkNextKey == 0);
    TimedTextEntry* pkMatchPrev = 0;
    TimedTextEntry* pkMatchNext = 0;
    for (ui = 0; ui < uiNumKeys; ui++)
    {
        if (bFoundPrev && bFoundNext)
            break;

        if (!bFoundPrev && FUN_00aa1360(pkKeys[ui].GetText(), pkPrevKey->GetText()) == 0)
        {
            pkMatchPrev = &pkKeys[ui];
            bFoundPrev = true;
        }
        if (!bFoundNext && FUN_00aa1360(pkKeys[ui].GetText(), pkNextKey->GetText()) == 0)
        {
            pkMatchNext = &pkKeys[ui];
            bFoundNext = true;
        }
    }

    float fNextTime = 0.0f;
    float fPriorKeyTime = 0.0f;
    if (pkMatchPrev == pkMatchNext)
    {
        fPriorKeyTime = pkMatchPrev->GetTime();
        fNextTime = pkMatchNext->GetTime();
        if (bHasKeyPair)
            fNextTime += end - begin;
        else
            fPriorKeyTime -= end - begin;
    }
    else
    {
        if (pkMatchNext)
            fNextTime = pkMatchNext->GetTime();
        if (pkMatchPrev)
            fPriorKeyTime = pkMatchPrev->GetTime();
        if (fPriorKeyTime > fNextTime)
            fNextTime += end - begin;
    }

    float fTime = fPriorKeyTime + (fNextTime - fPriorKeyTime) * fRatio;
    if (fTime < begin)
        fTime += end - begin;
    else if (fTime > end)
        fTime -= end - begin;
    return fTime;
}

struct CloneObject;
struct CloneMap
{
};
struct CloneContext
{
    CloneMap* map;
};
struct CloneObject
{
    virtual void v00();
    virtual void Release();
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
    virtual void ProcessClone(CloneContext&);
    long refs;
};
struct ClonePointer
{
    CloneObject* object;
    operator CloneObject*() const
    {
        return object;
    }
    bool operator==(const CloneObject* other) const
    {
        return object == other;
    }
    CloneObject* operator->() const
    {
        return object;
    }
    void Assign(CloneObject* other)
    {
        CloneObject* old = object;
        if (old != other)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->Release();
            object = other;
            if (other)
                InterlockedIncrement(&other->refs);
        }
    }
    void Assign(const ClonePointer& ptr)
    {
        CloneObject* old = object;
        if (old != ptr.object)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->Release();
            CloneObject* next = ptr.object;
            object = next;
            if (next)
                InterlockedIncrement(&next->refs);
        }
    }
    void AssignRef(CloneObject* const& other)
    {
        CloneObject* old = object;
        if (old != other)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->Release();
            CloneObject* next = other;
            object = next;
            if (next)
                InterlockedIncrement(&next->refs);
        }
    }
};
struct CloneItem
{
    ClonePointer interpolator;
    ClonePointer controller;
    void* blend;
    unsigned char index, priority, unk0e, unk0f;
    void FUN_00a5f860(void*);
};
struct CloneSequence
{
    void* vtable;
    unsigned int refs;
    void* name;
    unsigned int count, grow;
    CloneItem* items;
    void* tags;
    float weight;
    void* text;
    int cycle;
    float frequency, begin, end, last, accumulated, scaled;
    void* owner;
    int state;
    float offset, startTime, endTime, destFrame;
    void* partner;
    void* root;
    void* object60;
    void FUN_00a32470(CloneContext&);
public:
    void FUN_00a33570(::CloneSequence *, void *);
};
// @fnv 0x00a344f0
void* FUN_00a344f0_cls::FUN_00a344f0(uintptr_t param)
{
    void* p = FUN_00aa13e0(0x74);
    void* result = p ? ((void *)(new ((void *)(((FUN_00a316a0_shell*)p))) ::NiControllerSequence())) : 0;
    reinterpret_cast<::CloneSequence *>((this))->FUN_00a33570((::CloneSequence *)(result), (void *)(param));
    return result;
}
// Calls FUN_00a5d430, processes or looks up item objects, then assigns mapped or original pointers to the copy's fields.
// @fnv 0x00a32470
void CloneSequence::FUN_00a32470(CloneContext& context)
{
    reinterpret_cast<::FUN_00a5d430_Class *>(this)->FUN_00a5d430((uintptr_t)&(context));
    CloneObject* clone = 0;
    reinterpret_cast<::A54440Hash *>((void *)(context.map))->FUN_00a53c30(reinterpret_cast<::A54440Manager *>(((CloneObject*)this)), (::A54440Manager **)&(clone));
    CloneSequence* copy = (CloneSequence*)clone;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (items[i].interpolator == 0)
            continue;
        CloneItem& item = items[i];
        if (!owner)
        {
            items[i].interpolator->ProcessClone(context);
            CloneObject* controller = items[i].controller;
            if (controller)
                controller->ProcessClone(context);
        }
        else
        {
            CloneObject* interp = item.interpolator;
            if (!state)
                interp->ProcessClone(context);
            else
            {
                bool found = reinterpret_cast<::A54440Hash *>((void *)(context.map))->FUN_00a53c30((*(::A54440Manager * *)&(interp)), (::A54440Manager **)&(clone));
                CloneItem& dest = copy->items[i];
                if (found)
                    dest.FUN_00a5f860(clone);
                else
                    reinterpret_cast<::FUN_00c663d0 *>(&(dest))->operator=((const ::FUN_00c663d0 &)(items[i]));
            }
            if (reinterpret_cast<::A54440Hash *>((void *)(context.map))->FUN_00a53c30(reinterpret_cast<::A54440Manager *>((CloneObject*)(items[i].controller)), (::A54440Manager **)&(clone)))
            {
                CloneObject* old = copy->items[i].controller;
                ClonePointer* volatile dest = &copy->items[i].controller;
                CloneObject* next = *(CloneObject* volatile*)&clone;
                if (old != next)
                {
                    if (old)
                    {
                        if (!InterlockedDecrement(&old->refs))
                            old->Release();
                        next = *(CloneObject* volatile*)&clone;
                    }
                    dest->object = next;
                    if (next)
                        InterlockedIncrement(&next->refs);
                }
            }
            else
                copy->items[i].controller.Assign(items[i].controller);
            if (reinterpret_cast<::A54440Hash *>((void *)(context.map))->FUN_00a53c30(reinterpret_cast<::A54440Manager *>(((CloneObject*)items[i].blend)), (::A54440Manager **)&(clone)))
                copy->items[i].blend = clone;
            else
                copy->items[i].blend = items[i].blend;
        }
    }
    if (reinterpret_cast<::A54440Hash *>((void *)(context.map))->FUN_00a53c30(reinterpret_cast<::A54440Manager *>(((CloneObject*)owner)), (::A54440Manager **)&(clone)))
        copy->owner = clone;
    else
        copy->owner = owner;
    if (reinterpret_cast<::A54440Hash *>((void *)(context.map))->FUN_00a53c30(reinterpret_cast<::A54440Manager *>(((CloneObject*)partner)), (::A54440Manager **)&(clone)))
        copy->partner = clone;
    else
        copy->partner = partner;
    if (reinterpret_cast<::A54440Hash *>((void *)(context.map))->FUN_00a53c30(reinterpret_cast<::A54440Manager *>(((CloneObject*)object60)), (::A54440Manager **)&(clone)))
        copy->object60 = clone;
    else
        copy->object60 = object60;
}

struct Ref43c
{
    virtual void v00();
    virtual void DeleteThis();
    unsigned int m_lRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_lRefCount) == 0)
            DeleteThis();
    }
};
struct Ctl43c
{
};
struct Src43c
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int m_uiCount;
    void* unk10;
    Ctl43c* m_pA;
    Ctl43c* m_pB;
};
struct Base43c
{
};
struct Obj43c : Base43c
{
    void ClearInterpolatorRefs(Src43c* pkSrc, intptr_t iArg);
};

// Releases each ref returned by pkSrc->AssignInterpolatorRef, calls both controller methods, then invokes the base handler.
// @fnv 0x00a343c0
void Obj43c::ClearInterpolatorRefs(Src43c* pkSrc, intptr_t iArg)
{
    for (unsigned int i = 0; i < pkSrc->m_uiCount; i++)
    {
        Ref43c* pObj = 0;
        reinterpret_cast<::FUN_00a317e0_t *>((pkSrc))->AssignInterpolatorRef(i, (::FUN_00a317e0_ref **)&(pObj));
        if (pObj)
            pObj->DecRefCount();
    }
    if (pkSrc->m_pA)
        reinterpret_cast<::A31500Item *>((pkSrc->m_pA))->FUN_00a31500(3);
    if (pkSrc->m_pB)
        reinterpret_cast<::FUN_00a315b0_cls *>((pkSrc->m_pB))->FUN_00a315b0(3);
    reinterpret_cast<::CloneSequence *>(this)->FUN_00a33570((::CloneSequence *)(pkSrc), (void *)(iArg));
}


class GlobalObjectO2_00a7b610
{
};

struct DynCastHelper : RefBase
{
    long count;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&count);
    }
    void DecRefCount() throw()
    {
        if (!InterlockedDecrement(&count))
            Release();
    }
};

class NiNode : public DynCastHelper
{
};

template <class T> class NiPointer
{
  public:
    T* p;
    NiPointer(T* object = 0) throw()
    {
        p = object;
        if (p)
            p->IncRefCount();
    }
    ~NiPointer() throw()
    {
        if (p)
            p->DecRefCount();
    }
    NiPointer& operator=(T* object) throw()
    {
        if (p != object)
        {
            if (p)
                p->DecRefCount();
            p = object;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
    NiPointer& operator=(const NiPointer& other) throw()
    {
        if (p != other.p)
        {
            if (p)
                p->DecRefCount();
            p = other.p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};

typedef NiPointer<NiNode> NiPtrNode;
typedef NiPointer<DynCastHelper> LegacyPtr;

struct BinaryDataRecord
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int version;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    DynCastHelper** objects;
    unsigned int unk224;
    unsigned int count;
};

struct S00a35700_NodeRef
{
    NiNode* p;
    S00a35700_NodeRef& operator=(NiNode* object);
};


// Retrieves a NiNode by index from a BinaryDataRecord, using version-specific lookup, and assigns it to the output pointer with a reference count adjustment.
// @fnv 0x00a35700
void __cdecl FUN_00a35700(BinaryDataRecord* stream, unsigned int index, NiPtrNode& out)
{
    if (index >= stream->count)
    {
        out = 0;
        return;
    }
    NiNode* const null = 0;
    S00a35700_NodeRef a;
    a.p = null;
    if (stream->version < 0x5000000)
    {
        LegacyPtr b = null;
        ::GetGPUProgram(stream, index, (*(::NiPointer< ::NiGPUProgram> *)(&b)), (void *)(0));
        ::ConvertOldSequence((::OldSequence *)(b.p), (*(::SeqPtr< ::NewSequence> *)(&a)));
    }
    else
    {
        DynCastHelper* value = stream->objects[index];
        a = value == null ? null : (NiNode*)((::DynCastHelper *)(reinterpret_cast<::NiObject *>((value))->DynamicCast((const ::NiRTTI *)(const ::GlobalObjectO2_00a7b610 *)(&g_011f36dc))));
    }
    NiNode* p = a.p;
    out = p;
    if (p)
        p->DecRefCount();
}

struct ActiveArray
{
    void** items;
    unsigned int capacity;
    unsigned int size;
    unsigned int Find(void* const& key) const
    {
        for (unsigned int i = 0; i < size; ++i)
            if (items[i] == key)
                return i;
        return (unsigned int)-1;
    }
    unsigned int FindOrAdd(void* const& key);
};
// Returns the index of key in items, or appends it (growing the array if full) and returns the new index.
// @fnv 0x00e7ec00
unsigned int ActiveArray::FindOrAdd(void* const& key)
{
    unsigned int i = Find(key);
    if (i != (unsigned int)-1)
        return i;
    if (size == capacity)
        reinterpret_cast<::FUN_00a311e0_s *>(this)->FUN_00a311e0(capacity > 0 ? capacity * 2 : 1);
    unsigned int index = size;
    items[index] = key;
    ++size;
    return index;
}

#include <windows.h>
namespace fnv_00a30640 {
struct NiGlobalStringTable
{
};




// For each non-null handle, assigns AddString(0)'s result and decrements the old handle's count when it differs from a global handle.
// @fnv 0x00a30640
void NiControllerSequence::ResetStrings()
{
    char* old = m_kName.m_kHandle;
    if (old != 0)
    {
        m_kName.m_kHandle = ::NiGlobalStringTable::AddString(0);
        if (old != ::DAT_0109b220)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kParentName.m_kHandle;
    if (old != 0)
    {
        m_kParentName.m_kHandle = ::NiGlobalStringTable::AddString(0);
        if (old != ::DAT_0109b220)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kSourceName.m_kHandle;
    if (old != 0)
    {
        m_kSourceName.m_kHandle = ::NiGlobalStringTable::AddString(0);
        if (old != ::DAT_0109b220)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kTargetName.m_kHandle;
    if (old != 0)
    {
        m_kTargetName.m_kHandle = ::NiGlobalStringTable::AddString(0);
        if (old != ::DAT_0109b220)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kControllerName.m_kHandle;
    if (old != 0)
    {
        m_kControllerName.m_kHandle = ::NiGlobalStringTable::AddString(0);
        if (old != ::DAT_0109b220)
            InterlockedDecrement((LONG*)(old - 8));
    }
}
}  // namespace fnv_00a30640

int __cdecl FUN_00aa1370(const char*, const char*, const char*);

struct NiControllerSequenceT
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    void* m_pInterpArray;
    void* m_pkIDTags;
    float m_fWeight;
    NiTextKeyExtraData* m_spTextKeyData;
    bool MatchesTextKeys(NiControllerSequenceT* pkOther);
};
// @fnv 0x00a30c80
bool FUN_00a30c80_shell::FUN_00a30c80(void* arg)
{
    if (arg)
    {
        void* linked = *reinterpret_cast<void**>(static_cast<char*>(arg) + 0x58);
        if (linked)
        {
            if (linked == this)
                goto failure;
            unsigned __int64 result = ((unsigned long long)(reinterpret_cast<::FUN_00a30580_shell *>(this)->IsNotInChain(linked)));
            if (!static_cast<unsigned char>(result))
                goto failure;
            arg = reinterpret_cast<void*>(static_cast<unsigned int>(result >> 32));
        }
        if (reinterpret_cast<::NiControllerSequenceT *>((arg))->MatchesTextKeys({}))
            return true;
    }
failure:
    return false;
}
// @fnv 0x00a34f20
bool SeqA34f20::StartSequence(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime,
                              SeqA34f20* pkTimeSyncSeq, bool bTransition)
{
    if (m_eAnimationState != 0)
        return false;

    m_pkTimeSyncSequence = 0;
    if (pkTimeSyncSeq)
    {
        SeqA34f20* pkPartner = pkTimeSyncSeq->m_pkTimeSyncSequence;
        if (pkPartner)
        {
            if (pkPartner == this || !reinterpret_cast<::FUN_00a30580_shell *>(this)->IsNotInChain(pkPartner))
                return false;
        }
        if (reinterpret_cast<::NiControllerSequenceT *>(this)->MatchesTextKeys((::NiControllerSequenceT *)(pkTimeSyncSeq)))
            m_pkTimeSyncSequence = pkTimeSyncSeq;
        else
            return false;
    }

    m_fWeight = fWeight;
    reinterpret_cast<::FUN_00a30900_shell *>(this)->FUN_00a30900(m_ucRegionPriority);

    if (fEaseInTime > 0.0f)
    {
        if (bTransition)
            SetState(5);
        else
            SetState(2);
        m_fStartTime = g_fSeqNegInfinity;
        m_fEndTime = fEaseInTime;
    }
    else
    {
        SetState(1);
        m_fStartTime = 0.0f;
    }

    if (bStartOver)
        m_fSequenceOffset = g_fSeqNegInfinity;
    m_fLastTime = g_fSeqNegInfinity;
    return true;
}

// Returns true when both sequences have eligible text keys and each eligible key occurs in the other sequence.
// @fnv 0x00a30ab0
bool NiControllerSequenceT::MatchesTextKeys(NiControllerSequenceT* pkOther)
{
    NiTextKeyExtraData* pkKeys = m_spTextKeyData;
    NiTextKeyExtraData* pkOtherKeys;
    if (!pkKeys || !(pkOtherKeys = pkOther->m_spTextKeyData))
        return false;

    unsigned int uiNumOther = pkOtherKeys->m_uiNumKeys;
    TimedTextEntry* pOther = pkOtherKeys->m_pKeys;
    unsigned int uiNumKeys = pkKeys->m_uiNumKeys;
    TimedTextEntry* pKeys = pkKeys->m_pKeys;

    bool bFound = false;
    unsigned int i;
    for (i = 0; i < uiNumOther; i++)
    {
        const char* pcText = pOther[i].m_kText;
        if (!FUN_00aa1370(pcText, g_kTextKeyA, g_kTextKeyB))
        {
            bFound = true;
            bool bMatch = false;
            for (unsigned int j = 0; j < uiNumKeys; j++)
            {
                if (strcmp(pcText, pKeys[j].m_kText) == 0)
                {
                    bMatch = true;
                    break;
                }
            }
            if (!bMatch)
                goto fail;
        }
    }
    if (!bFound)
        goto fail;
    bFound = false;
    for (i = 0; i < uiNumKeys; i++)
    {
        const char* pcText = pKeys[i].m_kText;
        if (!FUN_00aa1370(pcText, g_kTextKeyA, g_kTextKeyB))
        {
            bFound = true;
            bool bMatch = false;
            for (unsigned int j = 0; j < uiNumOther; j++)
            {
                if (strcmp(pcText, pOther[j].m_kText) == 0)
                {
                    bMatch = true;
                    break;
                }
            }
            if (!bMatch)
                goto fail;
        }
    }
    if (!bFound)
        goto fail;
    return true;
fail:
    return false;
}

struct StaticKeyB5652
{
    StaticKeyB5652(int v) throw()
    {
        m_00 = v;
    }
    ~StaticKeyB5652() throw()
    {}
    unsigned int m_00;
};

class NiRefStubB5652
{
  public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefStubB5652** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void SetEntry(unsigned int idx, NiRefStubB5652** a2);
};

// Stores a NiRefStubB5652 pointer at index idx in m_04, updating m_0a, m_0c and reference counts as needed.
// @fnv 0x00a32940
void FUN_00a32940_cls::SetEntry(unsigned int uiIndex, NiRefStubB5652** apNewStub)
{
    static StaticKeyB5652 key(0);
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if ((uintptr_t)*apNewStub == key.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if ((uintptr_t)*apNewStub != key.m_00)
        {
            if ((uintptr_t)m_04[uiIndex] == key.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if ((uintptr_t)m_04[uiIndex] != key.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefStubB5652** slot = &m_04[uiIndex];
    NiRefStubB5652* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            {
                old->Destroy();
            }
        }
        NiRefStubB5652* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement(&pNewStub->m_iObjectReferenceCount);
        }
    }
}

struct BindObj;
struct BindCtrl;
struct Blend;
struct ObjPtr
{
    BindObj* ptr;
    operator BindObj*() const
    {
        return ptr;
    }
    BindObj* operator->() const
    {
        return ptr;
    }
};
struct PropLink
{
    PropLink* next;
    int unk04;
    ObjPtr object;
};
inline ObjPtr& NextProperty(PropLink*& pos)
{
    ObjPtr& value = pos->object;
    pos = pos->next;
    return value;
}
struct BindObj
{
    virtual void V0();
    virtual void V1();
    virtual const char** GetType();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual BindObj* Find(const char** name);
    virtual void V36();
    virtual void V37();
    virtual void SetTarget(BindObj* obj);
    virtual void V39();
    virtual void Update(bool*, int, bool*);
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual unsigned short FindIndex(const char*);
    virtual void V48();
    virtual Blend* GetBlend(unsigned short);
    virtual void SetBlend(Blend*, unsigned short);
    virtual bool Supports(BindObj*);
    virtual const char* GetID();
    virtual void V53();
    virtual void V54();
    virtual Blend* MakeBlend(unsigned short, bool, bool, float, int);
    int refs;
    unsigned short flags;
    unsigned short unk0a;
    BindCtrl* controllers;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    PropLink* properties;
    int unk28;
    int unk2c;
    BindCtrl* next;
};
struct BindCtrl : BindObj
{
};
struct Blend
{
};

struct BindOwner
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
    BindObj* target;
    BindCtrl* program;
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
    bool managerFlag;
    int unk6c;
    int unk70;
    int unk74;
    BindObj* root;
};
struct CtrlPtr
{
    BindCtrl* ptr;
    void FUN_0066b0d0(BindCtrl*);
};
struct BindItem
{
    BindObj* interpolator;
    CtrlPtr controller;
    Blend* blend;
    unsigned int settings;
};
struct BindTag
{
    const char* object;
    const char* property;
    const char* type;
    const char* id;
    const char* interpolator;
};
struct BindSequence
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int count;
    int unk10;
    BindItem* items;
    BindTag* tags;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    BindOwner* owner;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    const char* rootName;
    BindObj* accumRoot;
    int unk64;
    int unk68;
    int unk6c;
    unsigned short unk70;
    bool missing;
    bool FUN_00a32c70(bool arg);
};
// Resolves interpolators, objects, and controllers for each BindItem, creating blends and updating the owner's target.
// @fnv 0x00a32c70
bool BindSequence::FUN_00a32c70(bool abUpdate)
{
    BindObj* root = owner->root;
    if (rootName != (const char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
        accumRoot = root->Find(&rootName);
    abUpdate = reinterpret_cast<::Sequence31910 *>(this)->FUN_00a31910((::Node31910 *)(abUpdate), (::Node31910 *)(root), false);
    for (unsigned int index = 0; index < count; ++index)
    {
        BindObj* interpolator = items[index].interpolator;
        if (!interpolator)
            continue;
        BindTag& tag = tags[index];
        if (!interpolator->Supports(root) || items[index].blend)
            continue;
        BindObj* object = root->Find(&tag.object);
        if (object && tag.property)
        {
            PropLink* link = object->properties;
            while (link)
            {
                BindObj* property = NextProperty(link);
                const char* propertyType = tag.property;
                if (!strcmp(*property->GetType(), propertyType))
                {
                    object = property;
                    break;
                }
            }
        }
        if (!object)
        {
            if (*(const unsigned short*)tag.object == 0x2323)
                missing = true;
            continue;
        }
        BindCtrl* controller = object->controllers;
        while (controller)
        {
            const char* controllerType = tag.type;
            if (!strcmp(*controller->GetType(), controllerType))
            {
                const char* id = controller->GetID();
                if ((!id && !tag.id) || (id && tag.id && !strcmp(id, tag.id)))
                    break;
            }
            controller = controller->next;
        }
        if (!controller)
        {
            controller = items[index].controller.ptr;
            if (!controller)
                continue;
            controller->SetTarget(object);
            abUpdate = true;
            if (object == owner->target)
            {
                reinterpret_cast<::ControllerOwner *>((object))->FUN_00a5c480((::NiTimeController *)(controller));
                reinterpret_cast<::NiGPUProgramOwner *>((controller))->SetProgram((::NiGPUProgram *)(owner->program));
                reinterpret_cast<::NiGPUProgramOwner *>((((BindCtrl*)owner)))->SetProgram((::NiGPUProgram *)(controller));
            }
        }
        const char* interpolatorName = tag.interpolator;
        unsigned short interpIndex = controller->FindIndex(interpolatorName);
        if (interpIndex == ::NiInterpController::INVALID_INDEX)
            continue;
        {
            Blend* blend = controller->GetBlend(interpIndex);
            if (!blend)
                blend = 0;
            else
                blend = ((::Blend *)(reinterpret_cast<::NiObject *>((blend))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const int *>(&::g_011f36fc))))));
            bool special = false;
            if (accumRoot == object && owner->managerFlag)
                special = true;
            if (!blend)
            {
                blend = controller->MakeBlend(interpIndex, true, special, 0.0f, 2);
                controller->SetBlend(blend, interpIndex);
                if (!blend)
                    continue;
            }
            controller->flags |= 0x20;
            items[index].controller.FUN_0066b0d0(controller);
            items[index].blend = blend;
        }
    }
    if (abUpdate)
    {
        bool result;
        owner->target->Update(&result, 1, &abUpdate);
    }
    return true;
}

extern char DAT_01096614;

struct Controller33130
{
    virtual void V00();
    virtual void V01();
    virtual const char** V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual unsigned short V45();
    virtual const char* V46(unsigned int);
    virtual void V47();
    virtual void V48();
    virtual RefObj* V49(unsigned int);
    virtual void V50();
    virtual void V51();
    virtual const char* V52();
    int refs;
};
static void Release33130(char* h)
{
    if (h != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
        InterlockedDecrement((long*)(h - 8));
}
static void Assign33130(FixedStr& dst, const char* value)
{
    char* h = !value ? (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)) : NiGlobalStringTable::AddString(value);
    if (dst.m_handle != h)
    {
        char* old = dst.m_handle;
        if (h != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
            InterlockedIncrement((long*)(h - 8));
        Release33130(old);
        dst.m_handle = h;
    }
    Release33130(h);
}
static void Clear33130(FUN_00a312d0& tag)
{
    Release33130(tag.m_kInterpolatorID.m_handle);
    Release33130(tag.m_kCtlrID.m_handle);
    Release33130(tag.m_kCtlrType.m_handle);
    Release33130(tag.m_kPropertyType.m_handle);
    Release33130(tag.m_kAVObjectName.m_handle);
}
// Parses objectName into property and controller IDs, then for each controller slot assigns an interpolator and stores a reference to the controller.
// @fnv 0x00a33130
bool FUN_00a34480_cls::AssignControllers(void* apObjectName, FUN_00a34480_obj* apController)
{
    char objectName[260];
    char propertyName[260];
    char controllerID[260];
    fnv::crt::strcpy_s(objectName, 260, (const char*)apObjectName);
    propertyName[0] = 0;
    controllerID[0] = 0;
    char* split = strchr(objectName, '\n');
    if (split)
    {
        fnv::crt::strcpy_s(propertyName, 260, split + 1);
        *split = 0;
        split = strchr(propertyName, '\n');
        fnv::crt::strcpy_s(controllerID, 260, split + 1);
        *split = 0;
    }
    Controller33130* controller = (Controller33130*)apController;
    for (unsigned int i = 0; (unsigned short)i < controller->V45(); ++i)
    {
        const FixedStr& empty = *(const FixedStr*)&(*reinterpret_cast<int *>(&::DAT_011f49e0));
        FUN_00a312d0 tag(empty, empty, empty, empty, empty);
        Assign33130(tag.m_kAVObjectName, objectName);
        if (strcmp(propertyName, "PROP") == 0)
            Assign33130(tag.m_kPropertyType, controllerID);
        Assign33130(tag.m_kCtlrType, *controller->V02());
        Assign33130(tag.m_kCtlrID, controller->V52());
        Assign33130(tag.m_kInterpolatorID, controller->V46(i));
        RefObj* interpolator = controller->V49(i);
        int index = ((FUN_00a32bc0_cls*)this)->AssignSlot(interpolator, (uintptr_t)&tag, 255);
        if (index == -1)
        {
            Clear33130(tag);
            return false;
        }
        RefObj*& slot = *(RefObj**)&((FUN_00a32bc0_cls*)this)->m_pSlots[index].m_unk04;
        if (slot != (RefObj*)controller)
        {
            RefObj* old = slot;
            if (old && !InterlockedDecrement(&old->m_iObjectReferenceCount))
                old->Release();
            slot = (RefObj*)controller;
            InterlockedIncrement(&slot->m_iObjectReferenceCount);
        }
        Clear33130(tag);
    }
    return true;
}






struct SeqFixedString
{

    char* m_kHandle;

    SeqFixedString() : m_kHandle(::DAT_0109b220)
    {}
    SeqFixedString(const char* pcString)

    {

        if (pcString == 0)

            m_kHandle = ::DAT_0109b220;

        else

            m_kHandle = NiGlobalStringTable::AddString(pcString);
    }

    operator const char*() const
    {
        return m_kHandle;
    }

    ~SeqFixedString()

    {

        if (m_kHandle != ::DAT_0109b220)

            InterlockedDecrement((long*)(m_kHandle - 8));
    }

    SeqFixedString& operator=(const SeqFixedString& kString)

    {

        if (m_kHandle != kString.m_kHandle)
        {

            char* kHandle = kString.m_kHandle;

            if (kHandle != ::DAT_0109b220)

                InterlockedIncrement((long*)(kHandle - 8));

            if (m_kHandle != ::DAT_0109b220)

                InterlockedDecrement((long*)(m_kHandle - 8));

            m_kHandle = kHandle;
        }

        return *this;
    }
};

namespace a3 {
}

struct SeqRefObject
{

    virtual ~SeqRefObject();

    virtual __declspec(nothrow) void DeleteThis() throw();

    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }

    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct SeqPtr
{

    T* m_pObject;

    SeqPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }

    ~SeqPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    SeqPtr& operator=(T* p)

    {

        if (m_pObject != p)
        {

            if (m_pObject)
                m_pObject->DecRefCount();

            m_pObject = p;

            if (m_pObject)
                m_pObject->IncRefCount();
        }

        return *this;
    }

    SeqPtr& operator=(const SeqPtr& p)
    {
        return operator=(p.m_pObject);
    }

    T* operator->() const
    {
        return m_pObject;
    }

    operator T*() const
    {
        return m_pObject;
    }
};

struct SeqTextKeys : SeqRefObject
{
};

struct SeqController
{

    void* vtbl;

    int unk04;

    unsigned short m_uiObjectFlags;

    unsigned short unk0A;

    float m_fFrequency;

    float m_fPhase;

    float m_fLoKeyTime;

    float m_fHiKeyTime;
};

struct OldSequence
{

    void* vtbl;

    int unk04;

    const char* m_pcName;

    int unk0C;

    void** m_ppObjects;

    unsigned short unk14;

    unsigned short m_usElementCount;

    int unk18;

    int unk1C;

    SeqController** m_ppControllers;

    int unk24;

    int unk28;

    SeqPtr<SeqTextKeys> m_spTextKeyData;
};

struct NewSequence : SeqRefObject
{



    __declspec(noalias)
        NewSequence(const char* const& kName, unsigned int uiArraySize, unsigned int uiArrayGrowBy) throw();


    int unk08;

    int unk0C;

    int unk10;

    int unk14;

    int unk18;

    int unk1C;

    SeqPtr<SeqTextKeys> m_spTextKeyData;

    int m_eAnimationCycleType;

    float m_fFrequency;

    float m_fFirstKeyTime;

    float m_fLastKeyTime;

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

    SeqFixedString m_kAccumulationRootName;

    int unk60;

    int unk64;

    int unk68;

    int unk6C;

    int unk70;
};

// Allocates a NewSequence, copies name and controller data from pkOld, and assigns the result to spOut.
// @fnv 0x00a349e0
void __cdecl ConvertOldSequence(OldSequence* pkOld, SeqPtr<NewSequence>& spOut) throw()

{

    void* pvRaw = FUN_00aa13e0(0x74);

    unsigned int ItemUpdateArray = pvRaw != 0 ? pkOld->m_usElementCount : 0;

    SeqPtr<NewSequence> spSeq = new (pvRaw) NewSequence(SeqFixedString(pkOld->m_pcName), ItemUpdateArray, ItemUpdateArray);

    bool bFirst = true;

    for (unsigned int i = 0; i < pkOld->m_usElementCount; i++)
    {

        void* pkObject = pkOld->m_ppObjects[i];

        SeqController* pkCtlr = pkOld->m_ppControllers[i];

        if (pkObject && pkCtlr)
        {

            if (bFirst)
            {

                int eType = (pkCtlr->m_uiObjectFlags >> 1) & 3;

                if (eType != 2 && eType != 0)

                    eType = 0;

                spSeq->m_eAnimationCycleType = eType;

                spSeq->m_fFrequency = pkCtlr->m_fFrequency;

                bFirst = false;

                spSeq->m_fFirstKeyTime = pkCtlr->m_fLoKeyTime;

                spSeq->m_fLastKeyTime = pkCtlr->m_fHiKeyTime;
            }

            reinterpret_cast<::FUN_00a34480_cls *>(((spSeq).operator->()))->FUN_00a34480(pkObject, (::FUN_00a34480_obj *)(pkCtlr));
        }
    }

    spSeq->m_spTextKeyData = pkOld->m_spTextKeyData;

    spSeq->m_kAccumulationRootName = (*reinterpret_cast<::SeqFixedString *>(&::DAT_011f49e0));

    spOut = spSeq;
}

struct S00a32fa0_Ctl
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual unsigned short GetTargetIndex(const FUN_00a312d0& tag);
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual RefObj* GetInterpolator(unsigned short index);
};
struct S00a32fa0_RO : RefObj
{
    void DecRef()
    {
        if (!InterlockedDecrement(&m_iObjectReferenceCount))
            Release();
    }
};
struct S00a32fa0_SP
{
    RefObj* m_p;
    S00a32fa0_SP& operator=(const S00a32fa0_SP& o)
    {
        if (m_p != o.m_p)
        {
            RefObj* old = m_p;
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->Release();
            m_p = o.m_p;
            if (m_p)
                InterlockedIncrement(&m_p->m_iObjectReferenceCount);
        }
        return *this;
    }
    S00a32fa0_SP& operator=(RefObj* p)
    {
        if (m_p != p)
        {
            if (m_p)
                ((S00a32fa0_RO*)m_p)->DecRef();
            m_p = p;
            if (m_p)
                InterlockedIncrement(&m_p->m_iObjectReferenceCount);
        }
        return *this;
    }
    void Drop()
    {
        RefObj* old = m_p;
        _ReadWriteBarrier();
        if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
            old->Release();
    }
};
struct S00a32fa0_Item
{
    RefObj* interpolator;
    S00a32fa0_SP controller;
    void* blend;
    unsigned char blendIndex;
    unsigned char priority;
    unsigned char pad0e;
    unsigned char pad0f;
};
struct S00a32fa0_Tag
{
    char* m_kPointA[5];
};
struct S00a32fa0_Arr
{
};
struct S00a32fa0_Seq : FUN_00a32bc0_cls
{
    float weight;
    void* textKeys;
    int cycleType;
    float frequency;
    float beginTime;
    float endTime;
    void FUN_00a32fa0(S00a32fa0_Seq* destination, int, int, bool remove);
};

// Copies cycleType, frequency, beginTime, endTime and interpolator slots from this sequence into destination, optionally clearing destination slots first.
// @fnv 0x00a32fa0
void S00a32fa0_Seq::FUN_00a32fa0(S00a32fa0_Seq* destination, int, int, bool remove)
{
    if (remove)
    {
        for (unsigned int i = 0; i < destination->m_uiItemCount; ++i)
        {
            S00a32fa0_SP object = {0};
            reinterpret_cast<::FUN_00a317e0_t *>((((S00a32fa0_Arr*)destination)))->AssignInterpolatorRef(i, (::FUN_00a317e0_ref **)(::RefObj **)(&object.m_p));
            object.Drop();
            _ReadWriteBarrier();
        }
    }
    if (cycleType == 2 || cycleType == 0)
        destination->cycleType = cycleType;
    destination->frequency = frequency;
    destination->beginTime = beginTime;
    destination->endTime = endTime;
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        S00a32fa0_Item& item = ((S00a32fa0_Item*)m_pSlots)[i];
        S00a32fa0_Ctl* controller = (S00a32fa0_Ctl*)item.controller.m_p;
        if (item.interpolator && controller)
        {
            const FUN_00a312d0* info = (FUN_00a312d0*)&m_pInfos[i];
            unsigned short index = controller->GetTargetIndex(*info);
            if (index != ::NiInterpController::INVALID_INDEX)
            {
                RefObj* interpolator = controller->GetInterpolator(index);
                S00a32fa0_Tag tag;
                unsigned int newIndex = destination->AssignSlot(
                    interpolator,
                    (uintptr_t)new (&tag)
                        FUN_00a312d0((FixedStr&)(*reinterpret_cast<int *>(&::DAT_011f49e0)), (FixedStr&)(*reinterpret_cast<int *>(&::DAT_011f49e0)), (FixedStr&)(*reinterpret_cast<int *>(&::DAT_011f49e0)),
                                     (FixedStr&)(*reinterpret_cast<int *>(&::DAT_011f49e0)), (FixedStr&)(*reinterpret_cast<int *>(&::DAT_011f49e0))),
                    0xff);
                ((FUN_00a30750_shell*)&tag)->FUN_00a30750();
                S00a32fa0_Item& newItem = ((S00a32fa0_Item*)destination->m_pSlots)[newIndex];
                newItem.blend = item.blend;
                newItem.controller = item.controller;
                newItem.priority = item.priority;
            }
        }
    }
}


class S00a31880_RefObj
{
  public:
    virtual ~S00a31880_RefObj();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class S00a31880_FUN_00a31880_cls
{
  public:
    S00a31880_RefObj* m_00;
    S00a31880_RefObj* m_04;
    unsigned int m_08;
    unsigned char m_0c;
    unsigned char m_0d;

    S00a31880_FUN_00a31880_cls* FUN_00a31880(S00a31880_FUN_00a31880_cls* src);
};

// Copies reference-counted pointers and plain fields from src, managing ref counts for the two RefObj pointers.
// @fnv 0x00a31880
S00a31880_FUN_00a31880_cls* S00a31880_FUN_00a31880_cls::FUN_00a31880(S00a31880_FUN_00a31880_cls* src)
{
    S00a31880_RefObj* pOldRef0 = m_00;
    if (pOldRef0 != src->m_00)
    {
        if (pOldRef0 != 0)
        {
            pOldRef0->DecRefCount();
        }
        m_00 = src->m_00;
        if (m_00 != 0)
        {
            m_00->IncRefCount();
        }
    }
    S00a31880_RefObj* pOldRef1 = m_04;
    if (pOldRef1 != src->m_04)
    {
        if (pOldRef1 != 0)
        {
            pOldRef1->DecRefCount();
        }
        m_04 = src->m_04;
        if (m_04 != 0)
        {
            m_04->IncRefCount();
        }
    }
    m_08 = src->m_08;
    m_0c = src->m_0c;
    m_0d = src->m_0d;
    return this;
}

const char* const* __cdecl FUN_00a31730();
void __cdecl FUN_00ec65a6(char* c, unsigned int b, const char* a);
extern "C" void __cdecl FUN_00ec623a(void*, const char*, const char*, const char*);
void* __cdecl FormatStringWithType(const char* arg1, void* arg2);


struct MemoryManager
{
};



struct SeqFixedHandle
{
    char* m_kHandle;
};

struct SeqNiObject
{
    SeqNiObject();
    virtual ~SeqNiObject();
    unsigned int m_uiRefCount;
};

struct SeqInterpItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned short m_usFlags;

    SeqInterpItem();
    ~SeqInterpItem();
};

struct SeqTag
{
    SeqFixedString m_kAVObjectName;
    SeqFixedString m_kPropertyType;
    SeqFixedString m_kCtlrType;
    SeqFixedString m_kCtlrID;
    SeqFixedString m_kInterpolatorID;

    SeqTag();
    ~SeqTag();
};

struct SeqRefObj
{
    void* vt;
    unsigned int m_uiRefCount;
};
struct SeqPtr_fpfast_noehsc
{
    SeqRefObj* m_pObject;
    SeqPtr_fpfast_noehsc(SeqRefObj* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            InterlockedIncrement((long volatile*)&m_pObject->m_uiRefCount);
    }
};
struct ControllerSequence : SeqNiObject
{
    SeqFixedString m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    SeqInterpItem* m_pInterpArray;
    SeqTag* m_pkSeqTagArray;
    float m_fWeight;
    SeqPtr_fpfast_noehsc m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    void* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    void* m_pkTimeSyncSequence;
    SeqFixedHandle m_kAccumulationRootName;
    void* m_pkAccumulationRoot;
    void* m_spStringPalette;
    short m_sCurAnimNIdx;
    void* m_spAnimNotes;
    unsigned short m_usNumNotes;
    bool m_bRemoveActivatorsOnDeactivate;

    ControllerSequence(const SeqFixedString& kName, unsigned int uiArraySize, unsigned int uiArrayGrowBy);
    virtual ~ControllerSequence();
};

// @fnv 0x00a32a10
ControllerSequence::ControllerSequence(const SeqFixedString& kName, unsigned int uiArraySize,
                                       unsigned int uiArrayGrowBy)
    : m_uiNumControlledBlocks(uiArraySize), m_uiNumIDTags(uiArrayGrowBy), m_pInterpArray(0), m_pkSeqTagArray(0),
      m_fWeight(1.0f), m_fFrequency(1.0f), m_fFirstKeyTime(DAT_01096548)
{
    m_eAnimationCycleType = 0;
    m_pkOwnerManager = 0;
    float fInvalid = DAT_01015f5c;
    m_eAnimationState = 0;
    m_fLastKeyTime = fInvalid;
    m_fLastTime = fInvalid;
    m_fWeightAdjustedLastTime = fInvalid;
    m_fScaledLastTime = fInvalid;
    m_fSequenceOffset = fInvalid;
    m_fStartTime = fInvalid;
    m_fEndTime = fInvalid;
    m_fDestinationFrame = fInvalid;
    m_pkTimeSyncSequence = 0;
    m_kAccumulationRootName.m_kHandle = (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220));
    m_pkAccumulationRoot = 0;
    m_spStringPalette = 0;
    m_sCurAnimNIdx = -1;
    m_spAnimNotes = 0;
    m_usNumNotes = 0;
    m_bRemoveActivatorsOnDeactivate = false;
    m_kName = kName;
    if (m_uiNumControlledBlocks > 0)
    {
        m_pInterpArray = new SeqInterpItem[m_uiNumControlledBlocks];
        m_pkSeqTagArray = new SeqTag[m_uiNumControlledBlocks];
    }
}

struct CloneObject_noehsc : RefObj
{
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual CloneObject_noehsc* Clone(void*);
};
template <class T> struct ClonePtr
{
    T* ptr;
    bool operator!=(T* value) const
    {
        return ptr != value;
    }
    operator T*() const
    {
        return ptr;
    }
    T* operator->() const
    {
        return ptr;
    }
    ClonePtr& operator=(T* value)
    {
        if (ptr != value)
        {
            T* old = ptr;
            if (old && !InterlockedDecrement(&old->m_iObjectReferenceCount))
                old->Release();
            ptr = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
        return *this;
    }
    ClonePtr& operator=(const ClonePtr& other)
    {
        if (ptr != other.ptr)
        {
            T* old = ptr;
            if (old && !InterlockedDecrement(&old->m_iObjectReferenceCount))
                old->Release();
            ptr = other.ptr;
            if (ptr)
                InterlockedIncrement(&ptr->m_iObjectReferenceCount);
        }
        return *this;
    }
    static void* operator new[](std::size_t size, MemoryManager& memory = ::g_memoryManager) throw()
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(memory))->FUN_00aa3e40(size);
    }
    ClonePtr() : ptr(0)
    {}
    ~ClonePtr()
    {
        if (ptr && !InterlockedDecrement(&ptr->m_iObjectReferenceCount))
            ptr->Release();
    }
};
struct FUN_00a31240
{
    ClonePtr<CloneObject_noehsc> interpolator;
    ClonePtr<CloneObject_noehsc> controller;
    void* blend;
    unsigned char blendIndex, priority, unk0e, unk0f;
    FUN_00a31240() throw();
    static void* operator new[](std::size_t size, MemoryManager& memory = ::g_memoryManager) throw()
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(memory))->FUN_00aa3e40(size);
    }
};
struct FUN_00a31680
{
    FixedStr object, property, type, controller, interpolator;
    FUN_00a31680() throw();
    ~FUN_00a31680();
    static void* operator new[](std::size_t size, MemoryManager& memory = ::g_memoryManager) throw()
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(memory))->FUN_00aa3e40(size);
    }
};
struct CloneString
{
    char* handle;
    CloneString& operator=(const CloneString& other)
    {
        char* value = other.handle;
        if (handle != value)
        {
            if (value != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
                InterlockedIncrement((long*)(value - 8));
            if (handle != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
                InterlockedDecrement((long*)(handle - 8));
            handle = value;
        }
        return *this;
    }
};
struct CloneSequence_noehsc
{
    void* vtable;
    unsigned int refs;
    CloneString name;
    unsigned int count, growth;
    FUN_00a31240* controls;
    FUN_00a31680* tags;
    float weight;
    ClonePtr<RefObj> textKeys;
    int cycle;
    float frequency, begin, end, lastTime, weightedTime, scaledTime;
    void* owner;
    int state;
    float offset, start, stop, destination;
    CloneSequence_noehsc* partner;
    CloneString rootName;
    unsigned int unk60, unk64;
    unsigned short unk68, unk6a;
    ClonePtr<RefObj>* notes;
    unsigned short noteCount;
    void FUN_00a33570(CloneSequence_noehsc*, void*);
};
// @fnv 0x00a33570
void CloneSequence_noehsc::FUN_00a33570(CloneSequence_noehsc* dest, void* context)
{
    reinterpret_cast<::FUN_00a5d450_class *>(this)->CreateVertexBufferSet((uintptr_t)(dest), context);
    dest->name = name;
    dest->count = count;
    dest->growth = growth;
    dest->controls = new FUN_00a31240[count];
    dest->tags = new FUN_00a31680[count];
    for (unsigned int i = 0; i < count; ++i)
    {
        if (controls[i].interpolator != 0)
        {
            if (!owner)
            {
                dest->controls[i].interpolator = controls[i].interpolator->Clone(context);
                if (controls[i].controller != 0)
                    dest->controls[i].controller = controls[i].controller->Clone(context);
            }
            else
            {
                dest->controls[i].interpolator = ((::CloneObject_noehsc *)&(reinterpret_cast<::NiControllerSequence__IDTag *>(((controls[i].interpolator).operator->()))->operator=((*(const ::NiControllerSequence__IDTag *)(context)))));
                dest->controls[i].blendIndex = controls[i].blendIndex;
            }
        }
        dest->controls[i].priority = controls[i].priority;
        reinterpret_cast<::A1400StringGroup *>(&(dest->tags[i]))->FUN_00a31400((const ::A1400StringGroup &)(tags[i]));
    }
    dest->weight = weight;
    dest->textKeys = textKeys;
    dest->cycle = cycle;
    dest->frequency = frequency;
    dest->begin = begin;
    dest->end = end;
    dest->rootName = rootName;
    dest->unk68 = unk68;
    dest->noteCount = noteCount;
    if (noteCount > 0)
        dest->notes = new ClonePtr<RefObj>[noteCount];
    for (unsigned short j = 0; j < noteCount; ++j)
        dest->notes[j] = notes[j];
}

namespace fnv_00a32330 {
struct MemoryManager
{
    void Deallocate(void* pvMem);
};

struct NiRefObj
{
    virtual ~NiRefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct InterpArrayItem
{
    NiRefObj* m_spControllerInterpolator;
    NiRefObj* m_pkInterpCtlr;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned short m_usFlags;

    InterpArrayItem();
    ~InterpArrayItem()
    {
        if (m_pkInterpCtlr)
            m_pkInterpCtlr->DecRefCount();
        if (m_spControllerInterpolator)
            m_spControllerInterpolator->DecRefCount();
    }
    InterpArrayItem& operator=(const InterpArrayItem& kItem);
};

struct IDTag
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;

    IDTag();
    ~IDTag()
    {
        ReleaseStr(m_kInterpolatorID);
        ReleaseStr(m_kCtlrID);
        ReleaseStr(m_kCtlrType);
        ReleaseStr(m_kPropertyType);
        ReleaseStr(m_kAVObjectName);
    }
    static void ReleaseStr(char* pc)
    {
        if (pc)
            InterlockedDecrement((long volatile*)(pc - 8));
    }
    IDTag& operator=(const IDTag& kTag);
};


// @fnv 0x00a32330
bool SequenceArrays::FUN_00a32330()
{
    if (m_uiNumIDTags == 0)
        return false;

    unsigned int uiNewArraySize = m_uiNumControlledBlocks + m_uiNumIDTags;
    InterpArrayItem* pkNewInterpArray = new InterpArrayItem[uiNewArraySize];
    IDTag* pkNewIDTagArray = new IDTag[uiNewArraySize];
    for (unsigned int ui = 0; ui < uiNewArraySize; ui++)
    {
        if (ui < m_uiNumControlledBlocks)
        {
            reinterpret_cast<::S00a31880_FUN_00a31880_cls *>((void *)&(const ::fnv_00a32330::InterpArrayItem &)(pkNewInterpArray[ui]))->FUN_00a31880((::S00a31880_FUN_00a31880_cls *)&(m_pInterpArray[ui]));
            reinterpret_cast<::A1400StringGroup *>((void *)&(const ::fnv_00a32330::IDTag &)(pkNewIDTagArray[ui]))->FUN_00a31400((const ::A1400StringGroup &)(m_pkIDTags[ui]));
        }
    }
    delete[] m_pInterpArray;
    delete[] m_pkIDTags;

    m_uiNumControlledBlocks = uiNewArraySize;
    m_pInterpArray = pkNewInterpArray;
    m_pkIDTags = pkNewIDTagArray;

    return true;
}
}  // namespace fnv_00a32330

struct Stream71;
struct Memory71
{
};
struct Array71
{
};
struct Interp71 : Array71
{
    void* interpolator;
    void* controller;
    void* blend;
    unsigned char index, priority;
    short unk0e;
    Interp71() throw();
    ~Interp71()
    {}
};
struct String71
{
    char* ptr;
    String71() : ptr((char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
    {}
    void Release()
    {
        if (ptr != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
            DAT_00fdf1c4(ptr - 8);
    }
    String71& operator=(const String71& other)
    {
        if (ptr != other.ptr)
        {
            char* replacement = other.ptr;
            if (replacement != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
                DAT_00fdf1c0(replacement - 8);
            if (ptr != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
                DAT_00fdf1c4(ptr - 8);
            ptr = replacement;
        }
        return *this;
    }
};
struct Tag71 : Array71
{
    String71 object, property, controller, controllerID, interpolatorID;
    Tag71() throw();
    ~Tag71()
    {}
};
struct Ref71
{
    virtual void v0();
    virtual void Destroy();
    int count;
};
struct Smart71 : Array71
{
    Ref71* ptr;
    Smart71() throw();
    ~Smart71()
    {}
    Smart71& operator=(Ref71* other)
    {
        if (ptr != other)
        {
            Ref71* old = ptr;
            if (old && !DAT_00fdf1c4(&old->count))
                old->Destroy();
            ptr = other;
            if (other)
                DAT_00fdf1c0(&other->count);
        }
        return *this;
    }
};
struct Binary71
{
    void* vtbl;
    unsigned int pos;
    unsigned int(__cdecl* read)(Binary71*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* dest, unsigned int bytes)
    {
        unsigned int component = bytes;
        pos += read(this, dest, bytes, &component, 1);
    }
};
struct Stream71
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int version;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    Binary71* input;
};
struct Sequence71
{
    void* vtbl;
    unsigned int refs;
    String71 name;
    unsigned int count, grow;
    Interp71* interpolators;
    Tag71* tags;
    float weight;
    Smart71 text;
    int cycle;
    float frequency, begin, end;
    int unk34, unk38, unk3c;
    void* owner;
    int unk44, unk48, unk4c, unk50, unk54, unk58;
    String71 root;
    int unk60;
    Smart71 oldNotes;
    int unk68;
    Smart71* notes;
    unsigned short noteCount;
    void FUN_00a33e40(Stream71&);
};
// @fnv 0x00a33e40
void Sequence71::FUN_00a33e40(Stream71& stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream));
    if (stream.version < 0x0a010068)
    {
        reinterpret_cast<::Cls_a64ea0 *>(&(stream))->FUN_00a64ea0((char **)&(name));
        reinterpret_cast<::Cls_a64ea0 *>(&(stream))->FUN_00a64ea0((char **)&(root));
        reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
        stream.input->Read(&count, 4);
        grow = 12;
        interpolators = new Interp71[count];
        tags = new Tag71[count];
        for (unsigned int index = 0; index < count; ++index)
        {
            String71 objectName;
            reinterpret_cast<::Cls_a64ea0 *>(&(stream))->FUN_00a64ea0((char **)&(objectName));
            tags[index].object = objectName;
            reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
            objectName.Release();
        }
        return;
    }
    if (stream.version < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(stream))->FUN_00a64ea0((char **)&(name));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(stream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(name));
    stream.input->Read(&count, 4);
    stream.input->Read(&grow, 4);
    interpolators = new Interp71[count];
    tags = new Tag71[count];
    {
        unsigned int needsConversion = 0;
        for (unsigned int index = 0; index < count; ++index)
        {
            reinterpret_cast<::A33950Object *>(&(interpolators[index]))->LoadFromStream((::A33950Stream *)&(stream));
            reinterpret_cast<::IDTagA33a50 *>(&(tags[index]))->ReadFromStream((::StreamA33a50 &)(stream), needsConversion);
        }
    }
    stream.input->Read(&weight, 4);
    reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    {
        int cycleValue;
        stream.input->Read(&cycleValue, 4);
        cycle = cycleValue;
    }
    stream.input->Read(&frequency, 4);
    if (stream.version < 0x0a030001)
    {
        float phase;
        stream.input->Read(&phase, 4);
    }
    stream.input->Read(&begin, 4);
    stream.input->Read(&end, 4);
    if (stream.version < 0x0a01006b)
    {
        bool backward;
        stream.input->Read(&backward, 1);
    }
    reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    if (stream.version < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(stream))->FUN_00a64ea0((char **)&(root));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(stream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(root));
    if (stream.version >= 0x0a010071 && stream.version < 0x14010001)
        oldNotes = ((::Ref71 *)(reinterpret_cast<::NiStream *>(&(stream))->DeserializeObject()));
    else
        oldNotes = 0;
    if (stream.unk04 > 21 && stream.unk04 < 29)
        reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    if (stream.unk04 > 28)
    {
        stream.input->Read(&noteCount, 2);
        if (noteCount > 0)
            notes = new Smart71[noteCount];
        for (unsigned short index = 0; index < noteCount; ++index)
            reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
    }
}

void* __cdecl FormatStringWithType(const char* pcText, void* arg2);

extern unsigned char DAT_01096968;
extern unsigned int DAT_01096688;
struct LegacyStream
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int version;
};
struct LegacyTag
{
    char* name;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
};
struct LegacyController : RefObj
{
    unsigned short flags;
    unsigned short unk0a;
    float frequency;
    float phase;
    volatile float begin;
    volatile float end;
};
struct LegacyItem
{
    RefObj* interpolator;
    LegacyController* controller;
    void* blend;
    unsigned char index;
    unsigned char priority;
    unsigned short unk0e;
    void Clear()
    {
        if (interpolator)
        {
            RefObj* saved = interpolator;
            if (!InterlockedDecrement(&saved->m_iObjectReferenceCount))
                saved->Release();
            interpolator = 0;
        }
        if (controller)
        {
            LegacyController* saved = controller;
            if (!InterlockedDecrement(&saved->m_iObjectReferenceCount))
                saved->Release();
            controller = 0;
        }
        blend = 0;
        index = DAT_01096968;
        priority = 255;
    }
};
struct ReferenceAllocation;
struct LegacyRef
{
    LegacyController* pointer;
    ~LegacyRef() throw()
    {}
    static void* operator new[](std::size_t bytes, ReferenceAllocation*& allocation) throw();
};
struct ReferenceAllocation
{
    unsigned int count;
    LegacyRef elements[1];
};
__forceinline void* LegacyRef::operator new[](std::size_t bytes, ReferenceAllocation*& allocation) throw()
{
    allocation = (ReferenceAllocation*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(bytes);
    return allocation;
}
static __forceinline void MakeRefs(unsigned int n, LegacyRef*& result)
{
    ReferenceAllocation* allocation;
    new (allocation) LegacyRef[n];
    if (allocation)
    {
        LegacyRef* data = allocation->elements;
        LegacyRef* current = data;
        for (int remaining = (int)n - 1; remaining >= 0; --remaining, ++current)
            current->pointer = 0;
        result = data;
    }
    else
        result = 0;
}
struct S00a352f0_Hold
{
    LegacyController* p;
    S00a352f0_Hold(LegacyController* c) : p(c)
    {
        if (p)
            InterlockedIncrement(&p->m_iObjectReferenceCount);
    }
};
struct LegacyArray
{
    unsigned int* vtable;
    LegacyRef* data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short grow;
};
struct NamesArray
{
    unsigned int* vtable;
    char** data;
    unsigned short capacity, length, populated, grow;
};
struct LegacySequence : ::NiObject
{
    char* name;
    unsigned int count;
    unsigned int grow;
    LegacyItem* items;
    LegacyTag* tags;
    float weight;
    RefObj* textKeys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float last;
    float weightedLast;
    float scaledLast;
    void* owner;
    int state;
    float offset;
    float start;
    float finish;
    float dest;
    void* partner;
    char* rootName;
    unsigned int unk60;
    RefObj* stringPalette;
    void FUN_00a352f0(NiStream& stream);
};
// @fnv 0x00a352f0
void LegacySequence::FUN_00a352f0(NiStream& stream)
{
    ::FUN_00a89af0((intptr_t)this);
    if (stringPalette)
    {
        for (unsigned int i = 0; i < count; ++i)
            reinterpret_cast<::SeqIDTagOffsets *>(&(tags[i]))->LoadFromPalette((::NiStringPalette *)(stringPalette), (intptr_t)&(stream));
        if (stringPalette)
        {
            RefObj* palette = stringPalette;
            if (!InterlockedDecrement(&palette->m_iObjectReferenceCount))
                palette->Release();
            stringPalette = 0;
        }
    }
    if (((LegacyStream*)&stream)->version < 0x0a010068)
    {
        begin = DAT_01096548;
        unsigned int n = count;
        end = DAT_01015f5c;
        unsigned int rangeIndex = 0;
        if (rangeIndex < n)
        {
            LegacyController** sourceControllers = &items[0].controller;
            do
            {
                LegacyController* controller = *sourceControllers;
                if (controller->begin < begin)
                    begin = controller->begin;
                if (controller->end > end)
                    end = controller->end;
                sourceControllers += sizeof(LegacyItem) / sizeof(*sourceControllers);
                ++rangeIndex;
            } while (rangeIndex < n);
        }
        if (begin == ::_DAT_010231b0 && end == ::DAT_010241b0)
            begin = end = 0.0f;
        NamesArray names;
        names.capacity = (unsigned short)n;
        names.length = 0;
        if (names.capacity > 0)
            names.data = (char**)FUN_00aa1070(names.capacity * 4);
        else
            names.data = 0;
        LegacyArray controllers;
        controllers.capacity = (unsigned short)count;
        controllers.grow = 1;
        controllers.length = 0;
        controllers.populated = 0;
        if (controllers.capacity > 0)
            MakeRefs(controllers.capacity, controllers.data);
        else
            controllers.data = 0;
        controllers.vtable = &DAT_01096688;
        for (unsigned int i = 0; i < count; ++i)
        {
            {
                const char* name = tags[i].name;
                unsigned int bytes = strlen(name) + 1;
                char* copy = (char*)FUN_00aa1070(bytes);
                fnv::crt::strcpy_s(copy, bytes, name);
                if (i >= names.length)
                    names.length = (unsigned short)(i + 1);
                names.data[i] = copy;
            }
            reinterpret_cast<::fnv_00a30640::NiControllerSequence *>(&(tags[i]))->ResetStrings();
            LegacyController* retained = items[i].controller;
            reinterpret_cast<::FUN_00a32940_cls *>(&(controllers))->SetEntry(i, (::NiRefStubB5652 **)&(const ::S00a352f0_Hold &)(S00a352f0_Hold(retained)));
            if (retained && !InterlockedDecrement(&retained->m_iObjectReferenceCount))
                retained->Release();
            items[i].Clear();
        }
        unsigned int controllerCount = controllers.length;
        for (unsigned int i = 0; i < controllerCount; ++i)
        {
            LegacyController* controller = controllers.data[i].pointer;
            if (i == 0)
            {
                cycle = (controller->flags >> 1) & 3;
                if (cycle != 2 && cycle != 0)
                    cycle = 0;
                frequency = controller->frequency;
            }
            reinterpret_cast<::FUN_00a34480_cls *>(this)->FUN_00a34480(names.data[i], (::FUN_00a34480_obj *)(controller));
        }
        for (unsigned int i = 0; i < names.length; ++i)
            FUN_00aa10f0(names.data[i]);
        ::ReleaseObjectArray((::Obj00a47600 **)(controllers.data));
        FUN_00aa10f0(names.data);
    }
}
#include "generated/data/gamebryo2.2/corelibs/nianimation/nicontrollersequence.inc"
