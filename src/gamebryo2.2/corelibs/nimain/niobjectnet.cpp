// gamebryo2.2/corelibs/nimain/niobjectnet.cpp: NiObjectNET, ShortArray, MorphTarget, bhkSphereShape and more (26 functions)

#include <cstdint>
#include <windows.h>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045cec0_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00a5b790_cls.h"
#include "fnv/decl/FUN_00a5b870_cls.h"
#include "fnv/decl/FUN_00a5d430_Class.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a62660_cls.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/NiAccumulator.h"
#include "fnv/decl/NiGPUProgramOwner.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0056e000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a6c000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01268000.h"
#include "niobjectnet_decls.h"

// @fnv 0x00a5bba0
bool NiObjectNET::ResizeExtraData(unsigned short usCapacity)
{
    if (usCapacity == 0)
        return false;

    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));

    if (m_usMaxSize == 0)
    {
        m_usMaxSize = usCapacity;
        m_ppExtraData = (NiExtraData**)::FUN_00aa1070(usCapacity * sizeof(NiExtraData*));
        m_usExtraDataCount = 0;
        LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
        return true;
    }

    m_usMaxSize = usCapacity;
    NiExtraData** pNewExtraData = (NiExtraData**)::FUN_00aa1070(usCapacity * sizeof(NiExtraData*));
    std::memmove(pNewExtraData, m_ppExtraData, m_usExtraDataCount * sizeof(NiExtraData*));
    ::FUN_00aa10f0(m_ppExtraData);
    m_ppExtraData = pNewExtraData;
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
    return true;
}

// @fnv 0x00a5c080
void NiObjectNET::LoadBinary(NiStream& kStream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(kStream));

    if (kStream.m_uiNifVersion < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kName));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kName));

    if (kStream.m_uiNifVersion < 0x0500000B)
    {
        reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
        reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    }
    else
    {
        reinterpret_cast<::S_00a64670_Foo *>(&(kStream))->FUN_00a64670();
        reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    }
}

#pragma optimize("", off)
// @fnv 0x0043b480
void NiObjectNET::GetNumChildren()
{
    reinterpret_cast<::FUN_00658930_class *>(&(m_kArray))->GetShortAtOffsetA();
}
#pragma optimize("", on)

// Calls NiObject::ProcessClone, then ProcessClone on each extra data entry and on the time controller.
// @fnv 0x00a5b8f0
void NiObjectNET::ProcessClone(CloningProcess& kProcess)
{
    reinterpret_cast<::FUN_00a5d430_Class *>(this)->FUN_00a5d430((uintptr_t)&(kProcess));

    for (unsigned short i = 0; i < m_usExtraDataCount; ++i)
    {
        NiExtraData* pExtraData = m_ppExtraData[i];
        if (pExtraData)
            pExtraData->ProcessClone(kProcess);
    }

    NiTimeController* pController = m_pControllers;
    if (pController)
        pController->ProcessClone(kProcess);
}

// Assigns pInterpolator to the interpolator field, releasing the old one and adding a reference to the new one.
// @fnv 0x00a5c000
void NiMorphData::MorphTarget::SetTargetInterpolator(NiInterpolator* pInterpolator)
{
    if (m_spTargetInterpolator != pInterpolator)
    {
        if (m_spTargetInterpolator)
            m_spTargetInterpolator->DecRefCount();

        m_spTargetInterpolator = pInterpolator;

        if (m_spTargetInterpolator)
            m_spTargetInterpolator->IncRefCount();
    }
}

#pragma optimize("", off)
// Sets the flags on this object by calling FUN_00439360 with mask 0x1c00 and shift 10.
// @fnv 0x004393e0
void NiObjectNET::SetFlags(unsigned short flags)
{
    FUN_00439360(flags, 0x1c00, 10);
}
#pragma optimize("", on)

// @fnv 0x00a5c400
void NiObjectNET::AddController(NiTimeController* controller)
{
    if (controller)
    {
        NiTimeController* next = m_pControllers;
        if (controller->m_spNextController != next)
        {
            if (controller->m_spNextController)
                controller->m_spNextController->DecRefCount();
            controller->m_spNextController = next;
            if (controller->m_spNextController)
                controller->m_spNextController->IncRefCount();
        }
        if (m_pControllers != controller)
        {
            if (m_pControllers)
                m_pControllers->DecRefCount();
            m_pControllers = controller;
            if (m_pControllers)
                m_pControllers->IncRefCount();
        }
    }
}

#pragma optimize("", off)
// Increments DAT_01268280 and passes the radius, converted via FUN_004a3e90 when convert is set, to FUN_0056ea00.
// @fnv 0x0056e950
bhkSphereShape::bhkSphereShape(float radius, bool convert)
{
    (*reinterpret_cast<unsigned int *>(&::DAT_01268280)) = (*reinterpret_cast<unsigned int *>(&::DAT_01268280)) + 1;
    ::FUN_0056ea00((::_bhkSphereShape_vtbl_helper *)this, convert ? FUN_004a3e90(radius) : radius);
}
#pragma optimize("", on)

// @fnv 0x00a5c050
void NiObjectNET::FUN_00a5c050()
{
    if (m_pControllers)
    {
        m_pControllers->DecRefCount();
        m_pControllers = NULL;
    }
}

// Looks up extra data by name on the target NiAVObject and updates the cached reference, adjusting ref counts when it changes.
// @fnv 0x00a57240
void NiObjectNET::RefreshExtraData()
{
    NiAVObject* target = *(NiAVObject**)((char*)this + 0x2c);
    NiFixedString& name = *(NiFixedString*)((char*)this + 0x38);
    NiExtraData*& cached = *(NiExtraData**)((char*)this + 0x3c);
    NiExtraData* data = target->GetExtraData(name);
    if (cached != data)
    {
        if (cached)
            cached->DecRefCount();
        cached = data;
        if (cached)
            cached->IncRefCount();
    }
}


// @fnv 0x00a5b950
void AssignFixedString(char* pThis, intptr_t, char** ppkName)
{
    char* pcNewName = *ppkName;
    if (*reinterpret_cast<char**>(pThis + 8) != pcNewName)
    {
        if (pcNewName != *reinterpret_cast<char**>(&(*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220))))
            InterlockedIncrement(reinterpret_cast<volatile long*>(pcNewName - 8));
        char* pcOldName = *reinterpret_cast<char**>(pThis + 8);
        if (pcOldName != *reinterpret_cast<char**>(&(*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220))))
            InterlockedDecrement(reinterpret_cast<volatile long*>(pcOldName - 8));
        *reinterpret_cast<char**>(pThis + 8) = pcNewName;
    }
}

struct FUN_00a5bfa0_shell : public NiObjectNET
{
    void ClearExtraData();
};


struct NiExtraDataDeleteProxy : public NiObjectNET
{
};

// Under the extra-data lock, deletes all extra data entries, frees the extra data array, and resets the count and max size.
// @fnv 0x00a5bfa0
void FUN_00a5bfa0_shell::ClearExtraData()
{
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
    for (short i = static_cast<short>(m_usExtraDataCount) - 1; i >= 0; --i)
    {
        reinterpret_cast<::NiObjectNET *>((reinterpret_cast<NiExtraDataDeleteProxy*>(this)))->DeleteExtraData(static_cast<unsigned short>(i));
    }
    ::FUN_00aa10f0(m_ppExtraData);
    m_ppExtraData = 0;
    m_usMaxSize = 0;
    m_usExtraDataCount = 0;
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
}

extern int DAT_0109b23c;

// @fnv 0x00a5c760
void FUN_00a5c760(void** pThis)
{
    *pThis = &DAT_0109b23c;
    ::FUN_00aa10f0(pThis[1]);
}

// @fnv 0x00a57290
char const* const* __cdecl FUN_00a57290()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f4218));
}

struct VStream
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual bool RegisterFixedString(NiFixedString*);
};
struct VExtra
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void RegisterStreamables(VStream*);
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual bool IsGeometryController();
};
struct NiObjectBase
{
    bool RegisterStreamables(NiStream*);
};
// @fnv 0x00a5c180
bool FUN_00a5c180(void* thisp, int, NiStream* kStream)
{
    char* self = reinterpret_cast<char*>(thisp);
    VStream* stream = reinterpret_cast<VStream*>(kStream);
    if (!reinterpret_cast<NiObjectBase*>(thisp)->RegisterStreamables(kStream))
        return false;
    if (!stream->RegisterFixedString(reinterpret_cast<NiFixedString*>(self + 8)))
        return false;
    for (unsigned short i = 0; i < *reinterpret_cast<unsigned short*>(self + 0x14); i++)
    {
        VExtra* pkExtra = (*reinterpret_cast<VExtra***>(self + 0x10))[i];
        if (pkExtra && pkExtra->IsGeometryController())
            pkExtra->RegisterStreamables(stream);
    }
    VExtra* pController = *reinterpret_cast<VExtra**>(self + 0xc);
    if (pController)
        pController->RegisterStreamables(stream);
    return true;
}

namespace fnv_00a5c5b0 {
struct VExtra
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual bool IsGeometryController();
};
struct VCtrl
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual bool IsStreamableC();
    char pad[0x2c - 0];
    VCtrl* next;
};
struct VOut
{
    char p0[4];
    unsigned int pos;
    char p1[4];
    unsigned int(__cdecl* write)(VOut*, void*, unsigned int, const unsigned int&, unsigned int);
};
struct VStream
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void SaveLinkID(void*);
    char pad[0x250 - 4];
    VOut* out;
};
struct NiObjSave
{
    void SaveBinaryX();
};
// @fnv 0x00a5c5b0
void SaveNiObjectLinks(char* self, int, VStream* kStream)
{
    ::FUN_00a89af0((intptr_t)(reinterpret_cast<NiObject*>(self)));
    reinterpret_cast<::FUN_00a641f0_cls *>((kStream))->WriteObjectLink(reinterpret_cast<NiFixedString*>(self + 8));
    unsigned int uiStreamableExtraCount = 0;
    unsigned short i;
    for (i = 0; i < *reinterpret_cast<unsigned short*>(self + 0x14); i++)
    {
        VExtra* pkExtra = (*reinterpret_cast<VExtra***>(self + 0x10))[i];
        if (pkExtra->IsGeometryController())
            uiStreamableExtraCount++;
    }
    VOut* out = kStream->out;
    out->pos += out->write(out, &uiStreamableExtraCount, 4, 4, 1);
    unsigned short j;
    for (j = 0; j < *reinterpret_cast<unsigned short*>(self + 0x14); j++)
    {
        VExtra* pkExtra = (*reinterpret_cast<VExtra***>(self + 0x10))[j];
        if (pkExtra->IsGeometryController())
            kStream->SaveLinkID(pkExtra);
    }
    VCtrl* pkController = *reinterpret_cast<VCtrl**>(self + 0xc);
    while (pkController && !pkController->IsStreamableC())
        pkController = pkController->next;
    kStream->SaveLinkID(pkController);
}
}  // namespace fnv_00a5c5b0

namespace fnv_00a5c290 {
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
struct FUN_00a5c290_shell : public NiObjectNET
{
    void FUN_00a5c290(NiObjectNET*, CloningProcess*);
};



struct NiGlobalStringTable
{
};
class NiBinaryExtraData;
struct FUN_00a5d450_holder
{
};
struct FSH
{
    char* m_kHandle;
};
struct FUN_00a5b950_holder
{
};
struct RefView_a5c290
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};
struct VObj
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
    virtual VObj* MakeClone(CloningProcess&);
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
    virtual bool IsCloneable();
};

// Clones the object's name, extra data and time controller onto pkDest according to the cloning flags in kCloning.
// @fnv 0x00a5c290
void FUN_00a5c290_shell::FUN_00a5c290(NiObjectNET* pkDest, CloningProcess* kCloning)
{
    char* pcSuffixedName;
    int iNameLen;
    reinterpret_cast<::FUN_00a5d450_class *>((((FUN_00a5d450_holder*)this)))->CreateVertexBufferSet((uintptr_t)((NiBinaryExtraData*)pkDest), kCloning);

    if (kCloning->m_eCloneCopyMode == 1)
    {
        char* pcName = m_kName.m_kHandle;
        if (pkDest->m_kName.m_kHandle != pcName)
        {
            if (pcName != ::DAT_0109b220)
                InterlockedIncrement((long*)(pcName - 8));
            if (pkDest->m_kName.m_kHandle != ::DAT_0109b220)
                InterlockedDecrement((long*)(pkDest->m_kName.m_kHandle - 8));
            pkDest->m_kName.m_kHandle = pcName;
        }
    }
    else if (kCloning->m_eCloneCopyMode == 2)
    {
        if (m_kName.m_kHandle)
        {
            iNameLen = strlen(m_kName.m_kHandle) + 2;
            pcSuffixedName = (char*)::FUN_00aa1070(iNameLen);
            fnv::crt::strcpy_s(pcSuffixedName, iNameLen, m_kName.m_kHandle);
            pcSuffixedName[iNameLen - 2] = kCloning->m_bExactType;
            pcSuffixedName[iNameLen - 1] = 0;
            FSH kName;
            if (!pcSuffixedName)
                kName.m_kHandle = ::DAT_0109b220;
            else
                kName.m_kHandle = ::NiGlobalStringTable::AddString(pcSuffixedName);
            FSH kArg = kName;
            ::AssignFixedString((char *)(((FUN_00a5b950_holder*)pkDest)), (intptr_t)&(kArg), {});
            if (kName.m_kHandle != ::DAT_0109b220)
                InterlockedDecrement((long*)(kName.m_kHandle - 8));
            ::FUN_00aa10f0(pcSuffixedName);
        }
    }

    for (unsigned short i = 0; i < m_usExtraDataCount; i++)
    {
        NiExtraData* pkExtra = m_ppExtraData[i];
        if (pkExtra && ((VObj*)pkExtra)->IsCloneable())
            pkDest->AddExtraData((NiExtraData*)((VObj*)pkExtra)->MakeClone(*kCloning));
    }

    NiTimeController* pkCtrl = m_pControllers;
    if (pkCtrl)
    {
        NiTimeController* pkNew = (NiTimeController*)((VObj*)pkCtrl)->MakeClone(*kCloning);
        if (pkDest->m_pControllers != pkNew)
        {
            RefView_a5c290* pkOld = (RefView_a5c290*)pkDest->m_pControllers;
            if (pkOld && InterlockedDecrement(&pkOld->m_uiRefCount) == 0)
                pkOld->DeleteThis();
            pkDest->m_pControllers = pkNew;
            if (pkNew)
                InterlockedIncrement(&((RefView_a5c290*)pkNew)->m_uiRefCount);
        }
    }
}
}  // namespace fnv_00a5c290

struct ControllerPointerProxy
{
    NiTimeController* m_pObject;
    void FUN_00a5f860(NiTimeController* replacement);
};
struct ControllerLinkProxy
{
};
struct ControllerOwner : NiObjectNET
{
    void FUN_00a5c480(NiTimeController* controller);
};
// Removes controller from the owner's controller list, unlinking it and releasing references, or does nothing if it is not present.
// @fnv 0x00a5c480
void ControllerOwner::FUN_00a5c480(NiTimeController* controller)
{
    if (!controller || !m_pControllers)
        return;
    NiTimeController* current = m_pControllers;
    if (current == controller)
    {
        volatile long* refCount = reinterpret_cast<volatile long*>(&controller->m_uiRefCount);
        InterlockedIncrement(refCount);
        reinterpret_cast<ControllerPointerProxy*>(&m_pControllers)->FUN_00a5f860(controller->m_spNextController);
        NiTimeController* following = controller->m_spNextController;
        if (following)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&following->m_uiRefCount)) == 0)
                following->DeleteThis();
            controller->m_spNextController = 0;
        }
        if (InterlockedDecrement(refCount) == 0)
            controller->DeleteThis();
        return;
    }
    NiTimeController* following = current->m_spNextController;
    while (following && following != controller)
    {
        current = following;
        following = following->m_spNextController;
    }
    if (following)
    {
        ControllerPointerProxy retainedProxy = {controller};
        InterlockedIncrement(reinterpret_cast<volatile long*>(&controller->m_uiRefCount));
        reinterpret_cast<::NiGPUProgramOwner *>((reinterpret_cast<ControllerLinkProxy*>(current)))->SetProgram((::NiGPUProgram *)(controller->m_spNextController));
        NiTimeController* tail = controller->m_spNextController;
        if (tail)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&tail->m_uiRefCount)) == 0)
                tail->DeleteThis();
            controller->m_spNextController = 0;
        }
        reinterpret_cast<::FUN_0045cec0_Class *>(&(retainedProxy))->FUN_0045cec0();
    }
}

// Deleting destructor of an NiObjectNET-style object: drop extra data, the controller and the name, then free.



class C7B0RefObject
{
  public:
    virtual void Unk00();
    virtual void DeleteThis();

    long m_lRefCount;

    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class C7B0Pointer
{
  public:
    __forceinline ~C7B0Pointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};

class C7B0FixedString
{
  public:
    __forceinline ~C7B0FixedString()
    {
        if (m_pcHandle != ::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_pcHandle - 8));
    }

    char* m_pcHandle;
};

class C7B0Object
{
  public:
    virtual ~C7B0Object() throw();

    int unk04;
};

class C7B0ObjectNET : public C7B0Object
{
  public:
    __forceinline virtual ~C7B0ObjectNET() throw()
    {
        reinterpret_cast<::FUN_00a5bfa0_shell *>(this)->ClearExtraData();
    }

    static void operator delete(void* pvMem, size_t uiSize);

    C7B0ObjectNET* DestroyObject(unsigned int uiFlags);

    C7B0FixedString m_kName;
    C7B0Pointer<C7B0RefObject> m_spController;
    int unk10;
    int unk14;
};

// Runs the C7B0ObjectNET destructor and, when uiFlags has bit 0 set, frees the object, returning this.
// @fnv 0x00a5c7b0
C7B0ObjectNET* C7B0ObjectNET::DestroyObject(unsigned int uiFlags)
{
    this->C7B0ObjectNET::~C7B0ObjectNET();
    if (uiFlags & 1)
        ::FUN_00aa1460(this, sizeof(C7B0ObjectNET));
    return this;
}

namespace fnv_00a5c820 {
void* FUN_00aa1070(unsigned int);

struct ShortArray
{
    void* m_ppVirtualMethodTable;
    unsigned short* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    ShortArray()
    {
        m_usMaxSize = 0;
        m_usGrowBy = 1;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_ppVirtualMethodTable = &(*reinterpret_cast<int *>(&::indexVtable));
    }
    void FUN_00a5b790(unsigned int);
    void SetEntry(unsigned int, const unsigned short&);
    unsigned short GetAt(unsigned int u) const
    {
        return m_pBase[u];
    }
    void Add(const unsigned short& x)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            reinterpret_cast<::FUN_00a5b790_cls *>(this)->FUN_00a5b790(index + m_usGrowBy);
        reinterpret_cast<::FUN_00a5b870_cls *>(this)->SetEntry(index, (unsigned short *)&(x));
    }
};

void ShortArray::FUN_00a5b790(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;
    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != 0)
            {
                m_pBase[i] = 0;
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }
    unsigned short* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = (unsigned short*)FUN_00aa1070(m_usMaxSize * sizeof(unsigned short));
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = 0;
    }
    else
    {
        m_pBase = 0;
    }
    ::FUN_00aa10f0(pSaveBase);
}
void ShortArray::SetEntry(unsigned int uiIndex, const unsigned short& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != 0)
            m_usESize++;
    }
    else
    {
        if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}
struct EqObject
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool Equal(EqObject*);
};

struct VExtra : NiExtraData
{
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool IsGeometryController();
};
struct NetEqual : NiObjectNET
{
    bool FUN_00a5c820(NiObjectNET*);
};
struct CountController : NiTimeController
{
};

// Compares two NiObjectNET objects by checking name handle, geometry controller extra data, and time controller lists for equality.
// @fnv 0x00a5c820
bool NetEqual::FUN_00a5c820(NiObjectNET* other)
{
    if (!reinterpret_cast<::A5d470Class *>(this)->IsSameAs((::A5d470Object *)(other)))
        return false;
    if (m_kName.m_kHandle != other->m_kName.m_kHandle)
        return false;
    ShortArray first, second;
    unsigned short countA;
    for (countA = 0; countA < m_usExtraDataCount; ++countA)
        if (((VExtra*)m_ppExtraData[countA])->IsGeometryController())
            first.Add(countA);
    for (countA = 0; countA < other->m_usExtraDataCount; ++countA)
        if (((VExtra*)other->m_ppExtraData[countA])->IsGeometryController())
            second.Add(countA);
    if (first.m_usSize != second.m_usSize)
    {
        ::FUN_00aa10f0(second.m_pBase);
        ::FUN_00aa10f0(first.m_pBase);
        return false;
    }
    for (unsigned short j = 0; j < first.m_usSize; ++j)
    {
        EqObject* o1 = (EqObject*)m_ppExtraData[first.m_pBase[j]];
        EqObject* o2 = (EqObject*)other->m_ppExtraData[second.m_pBase[j]];
        if (!o1->Equal(o2))
        {
            ::FUN_00aa10f0(second.m_pBase);
            ::FUN_00aa10f0(first.m_pBase);
            return false;
        }
    }
    NiTimeController* pOtherController = other->m_pControllers;
    NiTimeController* pController = m_pControllers;
    unsigned int i = pController ? ::FUN_00a6cd00((::TCChain *)(((CountController*)pController)), {}) : 0;
    unsigned int uiOtherControllerCount = pOtherController ? ::FUN_00a6cd00((::TCChain *)(((CountController*)pOtherController)), {}) : 0;
    if (i != uiOtherControllerCount)
        goto fail;
    while (pController && pOtherController)
    {
        if (!((EqObject*)pController)->Equal((EqObject*)pOtherController))
        {
            ::FUN_00aa10f0(second.m_pBase);
            ::FUN_00aa10f0(first.m_pBase);
            return false;
        }
        pController = pController->m_spNextController;
        pOtherController = pOtherController->m_spNextController;
    }
    ::FUN_00aa10f0(second.m_pBase);
    ::FUN_00aa10f0(first.m_pBase);
    return true;
fail:
    ::FUN_00aa10f0(second.m_pBase);
    ::FUN_00aa10f0(first.m_pBase);
    return false;
}
}  // namespace fnv_00a5c820

struct LinkExtraA5
{
    virtual ~LinkExtraA5();
    virtual void DeleteThis();
    virtual const void* GetRTTI() const;
};
struct LinkBaseA5
{
    virtual ~LinkBaseA5();
    unsigned int m_iObjectReferenceCount;
};
struct LinkObjectA5 : LinkBaseA5
{
    void* m_name;
    void* m_controllers;
    LinkExtraA5** m_extra;
    unsigned short m_iElementCount;
    unsigned short m_pRayCursor;
    void RemoveExtraDataByName(unsigned short index)
    {
        void(* leaveLock)(void*) = LeaveCriticalSection;
        void(* enterLock)(void*) = EnterCriticalSection;
        enterLock(&(*reinterpret_cast<char *>(&::DAT_011f4380)));
        if (index < m_iElementCount)
            reinterpret_cast<::NiObjectNET *>(this)->DeleteExtraData(index);
        leaveLock(&(*reinterpret_cast<char *>(&::DAT_011f4380)));
    }
    void FUN_00a5c6a0(NiStream& stream);
};
inline bool IsExactTypeA5(const void* type, const LinkExtraA5* object)
{
    bool result = false;
    if (object)
        result = object->GetRTTI() == type;
    return result;
}
struct StrArray
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
    }
    void Add(char*& element)
    {
        SetAtGrow(m_usSize, element);
    }
};
struct S
{
    void* vtbl;
    int unk04;
    int unk08;
    intptr_t GetUnk08() const
    {
        return unk08;
    }
    void FUN_00a5ca80(StrArray* arr);
};
// Appends camera path entries, a string from DAT_011f4304, and a formatted m_kName string to the given StrArray.
// @fnv 0x00a5ca80
void S::FUN_00a5ca80(StrArray* apArray)
{
    reinterpret_cast<::A5D6E0This *>(this)->AppendCameraPathEntries((::NiTArray< ::BGSCameraPath *, ::NiTMallocInterface< ::BGSCameraPath *>> *)(apArray));
    char* str = ::FUN_00a7d330((const char *)((*reinterpret_cast<intptr_t *>(&::g_011f4304))));
    apArray->Add(str);
    str = ::fnv_00a7d5e0::FUN_00a7d5e0("m_kName", (const char *)(GetUnk08()));
    apArray->Add(str);
}

#include <string.h>
struct FUN_00a5bca0_shell : public NiObjectNET
{
    bool SetExtraDataName(NiExtraData*);
};
// Links the object's extra data list and time controller from the stream, handling both legacy and current stream versions.
// @fnv 0x00a5c0e0
void NiObjectNET::LinkObject(NiStream& kStream)
{
    ::FUN_00a89af0((intptr_t)this);

    if (kStream.m_uiNifVersion < 0x0500000B)
    {
        m_ppExtraData = (NiExtraData**)kStream.GetLoadedObject();
    }
    else
    {
        unsigned int ItemUpdateArray = reinterpret_cast<::FUN_00a63460_shell *>(&(kStream))->FUN_00a63460();
        ResizeExtraData((unsigned short)ItemUpdateArray);

        while (ItemUpdateArray > 0)
        {
            reinterpret_cast<::FUN_00a5bca0_shell *>(this)->SetExtraDataName((NiExtraData*)kStream.GetLoadedObject());
            --ItemUpdateArray;
        }
    }

    NiTimeController* pController = (NiTimeController*)kStream.GetLoadedObject();
    if (m_pControllers != pController)
    {
        if (m_pControllers)
            m_pControllers->DecRefCount();

        m_pControllers = pController;

        if (m_pControllers)
            m_pControllers->IncRefCount();
    }
}
// Links the object from the stream, transfers the old-version extra-data chain, and removes entries whose RTTI pointer equals g_ExtraTypeA5.
// @fnv 0x00a5c6a0
void LinkObjectA5::FUN_00a5c6a0(NiStream& stream)
{
    ::FUN_00a89af0((intptr_t)this);
    if (stream.m_uiNifVersion < 0x0500000b)
    {
        LinkExtraA5* extra = reinterpret_cast<LinkExtraA5*>(m_extra);
        if (extra)
        {
            m_extra = 0;
            while (extra)
            {
                LinkExtraA5* next = ((::LinkExtraA5 *)&(reinterpret_cast<::FUN_00a62660_cls *>((extra))->FUN_00a62660()));
                reinterpret_cast<::NiAccumulator *>((extra))->ClearCamera();
                reinterpret_cast<::FUN_00a5bca0_shell *>(this)->SetExtraDataName((::NiExtraData *)(extra));
                extra = next;
            }
        }
    }
    for (unsigned int i = 0; i < m_iElementCount; ++i)
    {
        LinkExtraA5* extra = m_extra[(unsigned short)i];
        if (IsExactTypeA5(&(*reinterpret_cast<char *>(&::g_011f5b78)), extra))
        {
            RemoveExtraDataByName((unsigned short)i);
            i = (unsigned int)-1;
        }
    }
}


struct BSFadeNode
{
    BSFadeNode(const char*);
    ~BSFadeNode()
    {
        if (m_kHandle != ::DAT_0109b220)
            InterlockedDecrement((long*)(m_kHandle - 8));
    }
    char* m_kHandle;
};
struct NamedObj
{
};
struct NiShader
{
};
class NiTexture;
struct Holder
{
    bool FUN_00a5ba40(NiTexture*);
};
struct RTTIName
{
    const char* m_pcName;
};
struct RTTISource
{
    virtual void V0();
    virtual void V1();
    virtual const RTTIName* GetRTTI() const;
};
char* CopyFilePath(char*, unsigned int, const char*, unsigned int);

// When the shader filename is empty, derives a name from RTTI and an index, sets it, then returns FUN_00a5ba40's result.
// @fnv 0x00a5bca0
bool FUN_00a5bca0_shell::SetExtraDataName(NiExtraData* pkExtra)
{
    if (!pkExtra)
        return false;
    if (!(*(const ::NiFixedString *)&(reinterpret_cast<::FUN_00a62660_cls *>((void *)(((NiShader*)pkExtra)))->FUN_00a62660())).m_kHandle)
    {
        const char* pcRTTI = ((RTTISource*)pkExtra)->GetRTTI()->m_pcName;
        if (pcRTTI && strlen(pcRTTI))
        {
            char pcSuffix[6];
            NiSprintf(pcSuffix, 6, "ED%03d", this->m_usExtraDataCount);
            const char* pcSubstr = std::strstr((char *)(pcRTTI), "ExtraData");
            unsigned int uiStrLength = 0;
            if (pcSubstr > pcRTTI)
                uiStrLength = pcSubstr - pcRTTI;
            unsigned int uiLen = uiStrLength + strlen(pcSuffix) + 1;
            char* pcGeneratedKey = (char*)::FUN_00aa1070(uiLen);
            CopyFilePath(pcGeneratedKey, uiLen, pcRTTI, uiStrLength);
            fnv::crt::strcat_s(pcGeneratedKey, uiLen, pcSuffix);
            ::AssignFixedString((char *)(((NamedObj*)pkExtra)), (intptr_t)&(const ::BSFadeNode &)(BSFadeNode(pcGeneratedKey)), {});
            ::FUN_00aa10f0(pcGeneratedKey);
        }
    }
    return ((Holder*)this)->FUN_00a5ba40((NiTexture*)pkExtra);
}

inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

struct FUN_00a5be90_shell : public NiObjectNET
{
    bool DeleteExtraDataByKey(const NiFixedString& kKey);
};

// Binary-searches m_ppExtraData using filename pointer ordering and deletes an entry when its filename pointer equals kKey.
// @fnv 0x00a5be90
bool FUN_00a5be90_shell::DeleteExtraDataByKey(const NiFixedString& kKey)
{
    if (m_usExtraDataCount == 0)
        return false;

    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));

    if (kKey == ::DAT_0109b220)
    {
        LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
        return false;
    }

    short sLow = 0;
    short sHigh = m_usExtraDataCount - 1;
    short sMiddle;
    int dtCompare;

    while (sLow <= sHigh)
    {
        sMiddle = (sLow + sHigh) >> 1;
        dtCompare = (const char*)kKey - (const char*)(*(const ::NiFixedString *)&(reinterpret_cast<::FUN_00a62660_cls *>((void *)(((NiShader*)m_ppExtraData[sMiddle])))->FUN_00a62660()));
        if (dtCompare == 0)
        {
            reinterpret_cast<::NiObjectNET *>((((NiExtraDataDeleteProxy*)this)))->DeleteExtraData(sMiddle);
            LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
            return true;
        }
        if (dtCompare > 0)
        {
            sLow = sMiddle + 1;
        }
        else
        {
            sHigh = sMiddle - 1;
        }
    }

    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&(*reinterpret_cast<char *>(&::DAT_011f4380))));
    return false;
}

struct MemoryManager
{
};
struct FUN_00a5c780
{
    void* m_pData;
    virtual ~FUN_00a5c780();
    static void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(p);
    }
};
// Frees the m_pData buffer held by the object via NiFree.
// @fnv 0x00a5c780
FUN_00a5c780::~FUN_00a5c780()
{
    ::FUN_00aa10f0(m_pData);
}
