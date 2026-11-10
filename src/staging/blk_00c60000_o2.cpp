
// src/staging/blk_00c60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include "havok/PhysicsMemory.h"
#include <exception>
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <new>
#include <cmath>
#include <cstring>
#include "havok/hkpCollidable.h"

// The byte before an aligned block holds the distance back to the start of its allocation.
struct AlignedBlockPrefix
{
    unsigned char m_ucOffset;
};
inline AlignedBlockPrefix* GetAlignedBlockPrefix(void* apBlock)
{
    return static_cast<AlignedBlockPrefix*>(apBlock) - 1;
}

// The global string table stores a reference count and the length before each string.
struct GlobalStringHeader
{
    volatile long m_lRefCount;
    unsigned int m_uiLength;
};
inline GlobalStringHeader* GetGlobalStringHeader(const void* apString)
{
    return const_cast<GlobalStringHeader*>(static_cast<const GlobalStringHeader*>(apString) - 1);
}
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/AttributeFormatter.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C.h"
#include "fnv/decl/C68E30Owner.h"
#include "fnv/decl/C89AC0_Owner.h"
#include "fnv/decl/CAC300Owner.h"
#include "fnv/decl/CAC680Object.h"
#include "fnv/decl/CCA1B0Level3.h"
#include "fnv/decl/ClaimCls.h"
#include "fnv/decl/ContactQuery.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00553540.h"
#include "fnv/decl/FUN_005545f0.h"
#include "fnv/decl/FUN_005ef6a0Class.h"
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c67aa0_Class.h"
#include "fnv/decl/FUN_00c6aca0.h"
#include "fnv/decl/FUN_00c6b980_cls.h"
#include "fnv/decl/FUN_00c6ffc0_Class.h"
#include "fnv/decl/FUN_00c7f970_cls.h"
#include "fnv/decl/FUN_00c81ae0_cls.h"
#include "fnv/decl/FUN_00c84f10_cls.h"
#include "fnv/decl/FUN_00c878c0_cls.h"
#include "fnv/decl/FUN_00c87c50_cls.h"
#include "fnv/decl/FUN_00c899d0_Class.h"
#include "fnv/decl/FUN_00c8adf0_cls.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c93e50.h"
#include "fnv/decl/FUN_00c97f50_Class.h"
#include "fnv/decl/FUN_00c984a0_Class.h"
#include "fnv/decl/FUN_00c9bff0_Class.h"
#include "fnv/decl/FUN_00cabfd0_Obj.h"
#include "fnv/decl/FUN_00cac110_Class.h"
#include "fnv/decl/FUN_00cac980_class.h"
#include "fnv/decl/FUN_00cad6f0_class.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cbe880_Class.h"
#include "fnv/decl/FUN_00cbf1a0_cls.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cc2350.h"
#include "fnv/decl/FUN_00cdea20_cls.h"
#include "fnv/decl/FUN_00cdea80_cls.h"
#include "fnv/decl/FUN_00cdeaa0_cls.h"
#include "fnv/decl/FUN_00cdf230_cls.h"
#include "fnv/decl/FUN_00cdf290_cls.h"
#include "fnv/decl/FloatArgStream.h"
#include "fnv/decl/HostClass.h"
#include "fnv/decl/HostWorld_00c951b0.h"
#include "fnv/decl/InversePositionVector.h"
#include "fnv/decl/MalleableGetterStandIn.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Mgr.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/MyColl.h"
#include "fnv/decl/Owner62B.h"
#include "fnv/decl/P064Controller.h"
#include "fnv/decl/PickSelf.h"
#include "fnv/decl/PoseState.h"
#include "fnv/decl/PropertyOwner.h"
#include "fnv/decl/RigidBodyOwnerL.h"
#include "fnv/decl/S00cbe9f0_cls.h"
#include "fnv/decl/S00cc2530_Owner306.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/decl/S_00c81b40_Owner.h"
#include "fnv/decl/S_00c85c10.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/S_Owner.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/ShapeOwner.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/SkeletonPoseData.h"
#include "fnv/decl/Src_00c91c50.h"
#include "fnv/decl/T_00a81060.h"
#include "fnv/decl/This676.h"
#include "fnv/decl/TransformedPosDAD.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/WorldC92C.h"
#include "fnv/decl/bhkListOwner_c8b090.h"
#include "fnv/decl/fnv_00561580__FUN_00561580_Class.h"
#include "fnv/decl/fnv_00a59e20__NiAVObject.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00cada30__FUN_00cada30_cls.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkaPoseCDA.h"
#include "fnv/decl/hkpCharacterStateManager.h"
#include "fnv/decl/hkpWorldC97.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0049e000.h"
#include "fnv/symbols_0056d000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b4d000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c66000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6b000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_00c6d000.h"
#include "fnv/symbols_00c7a000.h"
#include "fnv/symbols_00c7b000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00ca9000.h"
#include "fnv/symbols_00cab000.h"
#include "fnv/symbols_00cac000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb8000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_00cda000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010a4000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_011b0000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/tls.h"
#include "fnv/symbols_01272000.h"
#include "../../include/layout_support.h"
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"

struct P03MM
{
    void* Allocate(unsigned int);
};
// Allocates a block of a * 56 bytes from g_memoryManager and returns the pointer.
// @fnv 0x00c7a5d0
void* FUN_00c7a5d0(unsigned int a)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(a * 56);
}

// Allocates a+n bytes from g_memoryManager, aligns the returned pointer to 16 bytes and stores the alignment offset in the byte before it.
// @fnv 0x00c66170
void* FUN_00c66170(unsigned int uiSize)
{
    unsigned char n = 0x10;
    unsigned char* p = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize + n);
    n -= (unsigned char)((uintptr_t)p & 0xf);
    p += n;
    GetAlignedBlockPrefix(p)->m_ucOffset = n;
    return p;
}

struct MemoryManager
{
public:
    void *Reallocate(void *, unsigned int);
};
// @fnv 0x00c661a0
void FUN_00c661a0(void* apBlock, void* apUnused)
{
    if (apBlock)
    {
        unsigned char* q = static_cast<unsigned char*>(apBlock);
        reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<MemoryManager*>(&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(q - GetAlignedBlockPrefix(q)->m_ucOffset);
    }
}

extern float DAT_012677c4;
extern int DAT_012677c8;

// @fnv 0x00c66210
void __cdecl FUN_00c66210()
{
    DAT_012677c8 = 0;
    DAT_012677c4 = 0.0f;
}

// @fnv 0x00c66260
void SetFlagFromField(unsigned short* pFlags, unsigned int* pSource)
{
    if (pSource[3])
        pFlags[6] |= 1;
    else
        pFlags[6] &= 0xfffe;
}

struct FUN_00c662b0_vtable
{
    void* m_apSlots[48];
    bool (*SetFlag)(void*, bool);
};

struct FUN_00c662b0_object
{
    FUN_00c662b0_vtable* m_pVtbl;
};

struct FUN_00c662b0_request
{
    int m_iZero;
    unsigned char m_ucFlag;
    int m_iType;
    int m_iValue;
};

// @fnv 0x00c662b0
bool __cdecl FUN_00c662b0(void* pObject, void* pOther)
{
    return static_cast<FUN_00c662b0_object*>(pObject)->m_pVtbl->SetFlag(pObject, static_cast<FUN_00c662b0_request*>(pOther)->m_iValue != 0);
}

namespace fnv_00c66480 {
struct MemoryManager
{
};
struct FUN_00c66480_cls
{
    void* p;
    FUN_00c66480_cls* FUN_00c66480(bool f);
};
// Sets p to point at DAT_010c3b98 and, when f has bit 0 set, deallocates this via g_memoryManager, then returns this.
// @fnv 0x00c66480
FUN_00c66480_cls* FUN_00c66480_cls::FUN_00c66480(bool abFree)
{
    p = (void*)&::DAT_010c3b98;
    if (abFree & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00c66480

namespace fnv_00c664b0 {
struct MemoryManager
{
};
struct FUN_00c664b0_cls
{
    int* m_p;
    FUN_00c664b0_cls* FUN_00c664b0(int flag);
};
// @fnv 0x00c664b0
FUN_00c664b0_cls* FUN_00c664b0_cls::FUN_00c664b0(int aiFlags)
{
    m_p = &::DAT_010c3bac;
    if (aiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00c664b0

namespace fnv_00c664e0 {
struct MemoryManager
{
};
struct FUN_00c664e0
{
    void* vft;
    FUN_00c664e0(int);
};
// Sets the vtable pointer and, when bit 0 of f is set, deallocates this object through the memory manager.
// @fnv 0x00c664e0
FUN_00c664e0::FUN_00c664e0(int aiFlags)
{
    vft = &(*reinterpret_cast<char *>(&::DAT_010c3bb8));
    if (aiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
}
}  // namespace fnv_00c664e0

extern int DAT_010c3af8;
struct FUN_00c66540_class
{
    intptr_t InitVtableAndCall(int);
};
// @fnv 0x00c66540
intptr_t FUN_00c66540_class::InitVtableAndCall(int aiUnused)
{
    *(void**)this = (void*)&DAT_010c3af8;
    static_cast<::FUN_00cbf1a0_cls *>(nullptr)->FUN_00cbf1a0();
    return reinterpret_cast<intptr_t>(this);
}

namespace fnv_00c66600 {


struct MemoryManager
{
};

struct FUN_00c66600
{
    void* m_p;
    FUN_00c66600(void* p);
};

// Stores the address of DAT_010a47b8 in m_p and, when the low bit of p is set, deallocates this object through g_memoryManager.
// @fnv 0x00c66600
FUN_00c66600::FUN_00c66600(void* p)
{
    m_p = &::DAT_010a47b8;
    if ((uintptr_t)p & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
}
}  // namespace fnv_00c66600


struct FUN_00c66fb0_Class
{
    char pad[0x80];
    void* m_pObject;
    void* FUN_00c66fb0();
};

// @fnv 0x00c66fb0
void* FUN_00c66fb0_Class::FUN_00c66fb0()
{
    void* p = m_pObject;
    if (p)
        return ((void *)(::FUN_00c7fa90((::S_Obj *)(p))));
    return 0;
}

// @fnv 0x00c66fd0
struct BhkPickData
{
    char pad[0x80];
    hkpCollidable* m_pCollidable;
};

char* FUN_00c66fd0(struct BhkPickData* self)
{
    hkpCollidable* p = self->m_pCollidable;
    if (p && p->m_kBroadPhaseHandle.m_type == 1)
        return reinterpret_cast<char*>(p) + p->m_iOwnerOffset;
    return 0;
}

struct FUN_005533f0_cls
{
    void FUN_005533f0(uintptr_t);
};
struct FUN_00c6a620_cls
{
    void* m_auiShapeKeys[9];
    void* m_field;
    void SetField(void* a);
};
// @fnv 0x00c6a620
void FUN_00c6a620_cls::SetField(void* pValue)
{
    ((FUN_005533f0_cls*)this)->FUN_005533f0((uintptr_t)pValue);
    m_field = pValue;
}

struct FUN_00c6c870_collidable
{
    char pad[0x1c];
    unsigned int m_collisionFilterInfo;
};

struct FUN_00c6c870_source
{
    char pad[0x48];
    FUN_00c6c870_collidable* m_48;
};

struct FUN_00c6c870_class
{
    char pad[0x6c];
    unsigned int m_6c;
    void FUN_00c6c870(unsigned int a, uintptr_t b);
};

// @fnv 0x00c6c870
void FUN_00c6c870_class::FUN_00c6c870(unsigned int auiUnused, uintptr_t auiSource)
{
    FUN_00c6c870_collidable* p = reinterpret_cast<FUN_00c6c870_source*>(auiSource)->m_48;
    if ((p->m_collisionFilterInfo & 0x7f) == 0x1e && m_6c > 0)
        m_6c = m_6c - 1;
}

struct FUN_00c6cba0_class
{
    char pad[0x3f0];
    int m_iPreviousState;
    char pad3f4[0x520 - 0x3f4];
    int m_iState;
    void FUN_00c6cba0();
};

// @fnv 0x00c6cba0
void FUN_00c6cba0_class::FUN_00c6cba0()
{
    if (m_iState != 0xb)
    {
        m_iPreviousState = m_iState;
        m_iState = 0xb;
    }
}

class hkReferencedObject
{
};

struct FUN_00c6cca0
{
    hkReferencedObject* ref;
    void release();
};

// @fnv 0x00c6cca0
void FUN_00c6cca0::release()
{
    if (ref)
        reinterpret_cast<::hkReferencedObjectC905 *>((ref))->FUN_00c905b0();
    ref = 0;
}


struct FUN_00c6d120_cls
{
    char pad[0x3e0];
    char m_kStateObject;
    int FUN_00c6d120();
};

// Calls FUN_00ca9600 on m_kStateObject and returns 1 if the result is 4, 5 or 6, otherwise 0.
// @fnv 0x00c6d120
int FUN_00c6d120_cls::FUN_00c6d120()
{
    int r = FUN_00ca9600(&m_kStateObject);
    if (r == 5 || r == 6 || r == 4)
        return 1;
    return 0;
}


struct FUN_00c6d4b0_Class
{
    char pad[0x520];
    int m_iState;
    char pad524[0x540 - 0x524];
    float m_f540;
    void FUN_00c6d4b0(float f);
};

// @fnv 0x00c6d4b0
void FUN_00c6d4b0_Class::FUN_00c6d4b0(float afValue)
{
    m_f540 = DAT_01267bcc * afValue;
    m_iState = 1;
}

struct FUN_00c6e2e0_cls
{
    char pad[0x4e8];
    float f_4e8;
    char pad2[0x5c];
    float f_548;
    void FUN_00c6e2e0();
};
// @fnv 0x00c6e2e0
void FUN_00c6e2e0_cls::FUN_00c6e2e0()
{
    f_548 = f_4e8 + f_548;
}

// hkpShape and hkpMoppBvTreeShape as this function reads them.
struct GetValidatedPointer_shape
{
    void* m_pVtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    uintptr_t m_ulUserData;
    unsigned int m_uiType;
};

struct GetValidatedPointer_mopp : GetValidatedPointer_shape
{
    unsigned char m_ucBvTreeType;
    void* m_pMoppCode;
    void* m_pMoppData;
    unsigned int m_uiMoppDataSize;
    hkVector4 m_kMoppCodeInfo;
    void* m_pContainerVtbl;
    GetValidatedPointer_shape* m_pChildShape;
};

// @fnv 0x00c6ead0
void* __cdecl GetValidatedPointer(void* apObject)
{
    void* r = 0;
    if (apObject)
    {
        unsigned int t = static_cast<GetValidatedPointer_shape*>(apObject)->m_uiType;
        if (t == 10)
        {
            GetValidatedPointer_shape* child = static_cast<GetValidatedPointer_mopp*>(apObject)->m_pChildShape;
            apObject = child;
            t = child->m_uiType;
        }
        if (t == 0x17 || t == 0x1e || t == 0x1f)
            r = apObject;
    }
    return r;
}

struct FUN_00c6fd40_holder
{
    void* m_pVtbl;
    int m_04;
    int m_08;
    int* m_pValue;
};

struct FUN_00c6fd40_class
{
    char pad[0x630];
    FUN_00c6fd40_holder* m_pHolder;
    int* FUN_00c6fd40();
};

// @fnv 0x00c6fd40
int* FUN_00c6fd40_class::FUN_00c6fd40()
{
    FUN_00c6fd40_holder* p = m_pHolder;
    if (p)
        return p->m_pValue;
    return 0;
}

struct FUN_00c6fd60_holder
{
    char pad[0xc0];
    void* m_pObject;
};

struct FUN_00c6fd60_Class
{
    char pad[0x638];
    FUN_00c6fd60_holder* m_pHolder;
    void* FUN_00c6fd60();
};
// @fnv 0x00c6fd60
void* FUN_00c6fd60_Class::FUN_00c6fd60()
{
    FUN_00c6fd60_holder* p = m_pHolder;
    if (p)
        return p->m_pObject;
    return 0;
}

extern float DAT_011b02dc;
extern float DAT_01267c14;
extern float DAT_01267c18;

// @fnv 0x00c74550
void FUN_00c74550(float afScale, float afValue)
{
    DAT_01267c14 = DAT_011b02dc * afScale;
    DAT_01267c18 = afValue;
}

struct FUN_00c74870_slot
{
    int m_iValue;
    float m_fValue;
    char pad08[0x28];
};

struct FUN_00c74870_Class
{
    char pad[0x1b0];
    FUN_00c74870_slot m_akSlots[1];
    void FUN_00c74870(int a, float b);
};

// @fnv 0x00c74870
void FUN_00c74870_Class::FUN_00c74870(int aiSlotIndex, float afValue)
{
    m_akSlots[aiSlotIndex].m_fValue = afValue;
}

struct FUN_00c74890_Class
{
    void FUN_00c74890(int a, intptr_t b);
};

// @fnv 0x00c74890
void FUN_00c74890_Class::FUN_00c74890(int aiSlot, intptr_t aiValue)
{
    reinterpret_cast<FUN_00c74870_Class*>(this)->m_akSlots[aiSlot].m_iValue = aiValue;
}

struct FUN_00c748b0_class
{
    char pad[0x181];
    unsigned char m_uc181;
    char pad182[0x194 - 0x182];
    int m_i194;
    void SetFlagIfUnset();
};

// @fnv 0x00c748b0
void FUN_00c748b0_class::SetFlagIfUnset()
{
    if (!m_i194)
    {
        m_uc181 = 1;
        m_i194 = 1;
    }
}

struct FUN_00c748d0_C
{
    void SetSlotFloats(int a, float b, float c);
};
// Writes two floats at offsets 0x134 and 0x138 of the 80-byte element selected by a.
// @fnv 0x00c748d0
void FUN_00c748d0_C::SetSlotFloats(int aiIndex, float afValue1, float afValue2)
{
    char* p = (char*)this + aiIndex * 80;
    *(float*)(p + 0x134) = afValue1;
    *(float*)(p + 0x138) = afValue2;
}

extern void* DAT_010c4c64;
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00c75cc0_Class
{
    void* m_p;
    int m_uiX;
    void* m_q;
    void FUN_00c75cc0();
};
// @fnv 0x00c75cc0
void FUN_00c75cc0_Class::FUN_00c75cc0()
{
    m_p = &DAT_010c4c64;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    ::FUN_00aa10f0(m_q);
}

namespace fnv_00c75e00 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00c75e00
{
    void* m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void Init();
};
// @fnv 0x00c75e00
void FUN_00c75e00::Init()
{
    m_iWordAt00 = &::DAT_010c4ca4;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    ::FUN_00aa10f0(m_8);
}
}  // namespace fnv_00c75e00

// @fnv 0x00c75f60
void FUN_00c75f60(int* pData, int iValue, short sValue)
{
    pData[1] = iValue;
    *(short*)(pData + 2) = sValue;
}

namespace fnv_00c75f80 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00c75f80
{
    int* m_p;
    int m_auiShapeKeys;
    void* pAudioItems;
    void Init();
};
// @fnv 0x00c75f80
void FUN_00c75f80::Init()
{
    m_p = &DAT_010c4cf8;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    ::FUN_00aa10f0(pAudioItems);
}
}  // namespace fnv_00c75f80

struct FUN_00c76220_Class
{
    char pad[8];
    int* m_piValues;
    char pad0c[0x20 - 0x0c];
    int* m_piIndices;
    intptr_t FUN_00c76220(int idx);
};

// @fnv 0x00c76220
intptr_t FUN_00c76220_Class::FUN_00c76220(int aiIndex)
{
    int v = m_piIndices[aiIndex];
    if (v < 0)
        return 0;
    return m_piValues[v];
}

struct FUN_00c76320_leaf
{
    char pad[0x350];
    int m_iValue;
};

struct FUN_00c76320_node
{
    char pad[8];
    FUN_00c76320_leaf* m_pLeaf;
};

struct FUN_00c76320_link
{
    FUN_00c76320_node* m_pNode;
};

struct FUN_00c76320_head
{
    char pad[8];
    FUN_00c76320_link* m_pLink;
};

struct FUN_00c76320_class
{
    char pad[0x48];
    FUN_00c76320_head* m_pHead;
    intptr_t GetNestedValue();
};

// Follows m_pHead->m_pLink->m_pNode->m_pLeaf and returns the leaf's m_iValue, or 0 if any link is null.
// @fnv 0x00c76320
intptr_t FUN_00c76320_class::GetNestedValue()
{
    FUN_00c76320_head* p = m_pHead;
    if (p)
    {
        FUN_00c76320_node* r = p->m_pLink->m_pNode;
        if (r)
        {
            FUN_00c76320_leaf* s = r->m_pLeaf;
            if (s)
                return s->m_iValue;
        }
    }
    return 0;
}

namespace fnv_00c7a570 {
void __cdecl FUN_00c75d90();
struct MemoryManager
{
};
struct FUN_00c7a570
{
    void* Deallocate(bool);
};
// Calls FUN_00c75d90, then if flag has bit 0 set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00c7a570
void* FUN_00c7a570::Deallocate(bool abFree)
{
    FUN_00c75d90();
    if (abFree & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00c7a570

namespace fnv_00c7a590 {
struct MemoryManager
{
};
struct FUN_00c7a590
{
    void FUN_00c75ed0();
    void* DeallocateSelf(bool);
    bool m_bFlag;
};
// Calls FUN_00c75ed0, then if bFlag has bit 0 set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00c7a590
void* FUN_00c7a590::DeallocateSelf(bool abFree)
{
    FUN_00c75ed0();
    if (abFree & 1)
        reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<MemoryManager*>(&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00c7a590

void FUN_00c76240();


struct FUN_00c7a8b0_class
{
    void* FUN_00c7a8b0(unsigned int a);
};

// Calls FUN_00c76240, deletes this with size 0x20 when bit 0 of a is set, and returns this.
// @fnv 0x00c7a8b0
void* FUN_00c7a8b0_class::FUN_00c7a8b0(unsigned int uiFlags)
{
    FUN_00c76240();
    if (uiFlags & 1)
        ::FUN_00aa1460(this, 0x20);
    return this;
}

// @fnv 0x00c7fc20
void* FUN_00c7fc20(unsigned int a)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(a * 8);
}

struct FUN_00c66560_class
{
    void* FUN_00c66560(int a);
};
// @fnv 0x00c66560
void* FUN_00c66560_class::FUN_00c66560(int a)
{
    reinterpret_cast<::FUN_00cbf1a0_cls *>(this)->FUN_00cbf1a0();
    return this;
}

void __cdecl ProcessPendingItems();
struct bhkWorld
{
    void FUN_00c68a00(bool a);
};
struct FUN_00c75ad0_T
{
    float f_0;
    float f_4;
    float f_8;
    float f_c;
    float f_10;
    float f_14;
    float f_18;
    float f_1c;
    float f_20;
    float f_24;
    float f_28;
    float f_2c;
    float f_30;
    float f_34;
};
struct FUN_00c75ad0_slot
{
    char pad[0x18];
    FUN_00c75ad0_T* m_pInput;
};
struct FUN_00c75ad0_Class
{
    char pad[0x4c];
    FUN_00c75ad0_T** m_ppOutput;
    char pad50[0x28c - 0x50];
    char m_cHasInput;
    char m_cInputFirstByte;
    char pad28e[0x2a4 - 0x28e];
    FUN_00c75ad0_slot* m_pSlot;
    void FUN_00c75ad0(FUN_00c75ad0_T* p);
};
// @fnv 0x00c75ad0
void FUN_00c75ad0_Class::FUN_00c75ad0(FUN_00c75ad0_T* p)
{
    m_pSlot->m_pInput = p;
    m_cHasInput = 1;
    m_cInputFirstByte = *(char*)p;
    FUN_00c75ad0_T* d = *m_ppOutput;
    d->f_0 = p->f_8;
    d->f_4 = p->f_1c;
    d->f_8 = p->f_14;
    d->f_c = p->f_10;
    d->f_10 = p->f_c;
    d->f_14 = p->f_30;
    d->f_18 = p->f_34;
    d->f_1c = p->f_18;
    d->f_20 = p->f_20;
    d->f_24 = p->f_24;
    d->f_28 = p->f_28;
    d->f_2c = p->f_2c;
}

struct FUN_00c7a630_vtable
{
    void* slot0;
    void* slot1;
    void (*Free)(void*);
};

struct FUN_00c7a630_class
{
    int* vtbl;
    int* m_p;
    int* m_kPointA;
    int* m_kPointB;
    void FUN_00c7a630();
};
// @fnv 0x00c7a630
void FUN_00c7a630_class::FUN_00c7a630()
{
    vtbl = (int*)&(*reinterpret_cast<int *>(&::DAT_010c4db8));
    if (m_p)
    {
        reinterpret_cast<FUN_00c7a630_vtable*>(&::DAT_010c4db8)->Free(m_p);
        m_p = 0;
        m_kPointB = 0;
        m_kPointA = 0;
    }
}

extern int DAT_0108ffb4;
struct FUN_009ba5f0_shell
{
};
struct FUN_00c7fb40
{
    int* p;
    void FUN_00c7fb40_init();
};
// @fnv 0x00c7fb40
void FUN_00c7fb40::FUN_00c7fb40_init()
{
    p = &DAT_0108ffb4;
    reinterpret_cast<::C89AC0_Owner *>((((FUN_009ba5f0_shell*)this)))->SetChildObject((::C89AC0_Child *)(0));
}

struct NiPoint3
{
    float x, y, z;
public:
    static const ::NiPoint3 ZERO;
};

// Checks each of three consecutive point pairs with AreVectorsEqual and returns false as soon as one pair fails, otherwise true.
// @fnv 0x00c6b5f0
bool __cdecl FUN_00c6b5f0(NiPoint3 const* apPointsA, NiPoint3 const* apPointsB, float c)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        NiPoint3 pointA;
        NiPoint3 pointB;
        pointA.x = apPointsA[i].x;
        pointA.y = apPointsA[i].y;
        pointA.z = apPointsA[i].z;
        pointB.x = apPointsB[i].x;
        pointB.y = apPointsB[i].y;
        pointB.z = apPointsB[i].z;
        if (!::AreVectorsEqual((const float *)&(pointA), (const float *)&(pointB), c))
            return false;
    }
    return true;
}

struct FUN_00c663d0_Ref
{
    virtual void v0();
    virtual void v1();
    volatile long m_uiRefCount;
};
struct FUN_00c663d0
{
    FUN_00c663d0_Ref* m_pObject;
    FUN_00c663d0& operator=(const FUN_00c663d0& kSrc);
};
// Copy-assigns a ref-counted pointer: releases the old object when its count drops to zero, then retains the new one.
// @fnv 0x00c663d0
FUN_00c663d0& FUN_00c663d0::operator=(const FUN_00c663d0& kSrc)
{
    FUN_00c663d0_Ref* pOld = m_pObject;
    if (pOld != kSrc.m_pObject)
    {
        if (pOld)
        {
            if (InterlockedDecrement(&pOld->m_uiRefCount) == 0)
                pOld->v1();
        }
        m_pObject = kSrc.m_pObject;
        if (m_pObject)
            InterlockedIncrement(&m_pObject->m_uiRefCount);
    }
    return *this;
}

struct FUN_00c66e20_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float);
};
struct FUN_00c66e20_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    char pad0c[0x70 - 0x0c];
    FUN_00c66e20_vtbl** m_ppObjects;
    int m_iObjectCount;
    void FUN_00c66e20(float a);
};
// If m_8 is set, iterates the m_iObjectCount objects in m_ppObjects and calls v6(a) on each non-null object when a is non-zero.
// @fnv 0x00c66e20
void FUN_00c66e20_Class::FUN_00c66e20(float afValue)
{
    if (m_8)
    {
        for (int i = 0; i < m_iObjectCount; ++i)
        {
            FUN_00c66e20_vtbl* obj = m_ppObjects[i];
            if (obj && afValue != 0.0f)
                obj->v6(afValue);
        }
    }
}

struct NiPoint3_ZERO_s
{
    int x, y, z;
};

struct FUN_00c6d9f0_s
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    FUN_00c6d9f0_s();
};

// Initialises the object's fields: f0 to 0 and three groups of f4/f8/fc, f10/f14/f18, f1c/f20/f24 to NiPoint3_ZERO.x, DAT_011f4270 and DAT_011f4274.
// @fnv 0x00c6d9f0
FUN_00c6d9f0_s::FUN_00c6d9f0_s()
{
    f0 = 0;
    f4 = (*reinterpret_cast<::NiPoint3_ZERO_s *>((void *)&::NiPoint3::ZERO)).x;
    f8 = ::_DAT_011f4270;
    fc = ::_DAT_011f4274;
    f10 = (*reinterpret_cast<::NiPoint3_ZERO_s *>((void *)&::NiPoint3::ZERO)).x;
    f14 = ::_DAT_011f4270;
    f18 = ::_DAT_011f4274;
    f1c = (*reinterpret_cast<::NiPoint3_ZERO_s *>((void *)&::NiPoint3::ZERO)).x;
    f20 = ::_DAT_011f4270;
    f24 = ::_DAT_011f4274;
}

struct FUN_00c7a690_class
{
    int* vtbl;
    int* m_p;
    int* m_kPointA;
    int* m_kPointB;
    void* FUN_00c7a690(int a);
};
// Sets the vtable, frees m_p via DAT_010c4dc0 and clears the pointers, then deallocates this if bit 0 of a is set.
// @fnv 0x00c7a690
void* FUN_00c7a690_class::FUN_00c7a690(int aiFlags)
{
    void* old = m_p;
    vtbl = &(*reinterpret_cast<int *>(&::DAT_010c4db8));
    if (old)
    {
        ((void(*)(void*)) * (void**)(void*)&(*reinterpret_cast<int *>(&::DAT_010c4dc0)))(old);
        m_p = 0;
        m_kPointB = 0;
        m_kPointA = 0;
    }
    if (aiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

struct FUN_00c747d0_Class
{
    char pad[0x43];
    char m_43;
    char pad2[0x220 - 0x44];
    char m_220;
    char pad3[0x222 - 0x221];
    unsigned char m_222;
    char m_223;
    void FUN_00c747d0(bool abActive);
};

// @fnv 0x00c747d0
void FUN_00c747d0_Class::FUN_00c747d0(bool abActive)
{
    unsigned char bprevActive = m_222;
    int bNewActive;
    if (m_43 == 0)
    {
        if (m_220 != 0 && abActive)
            bNewActive = 1;
        else
            bNewActive = 0;
    }
    else
    {
        bNewActive = bprevActive;
    }
    m_222 = (unsigned char)bNewActive;
    if (bprevActive != 0 && (unsigned char)bNewActive == 0)
        m_223 = 1;
}

extern int DAT_010c4ce4;
extern void* DAT_010c4cec;

struct FUN_00c7a6e0_class
{
    int* vtbl;
    int* m_p;
    int* m_kPointA;
    int* m_kPointB;
    FUN_00c7a6e0_class* FUN_00c7a6e0(unsigned int flags);
};

// Sets the vtable, frees m_p via DAT_010c4cec and clears the pointers, then deallocates this if flags bit 0 is set.
// @fnv 0x00c7a6e0
FUN_00c7a6e0_class* FUN_00c7a6e0_class::FUN_00c7a6e0(unsigned int flags)
{
    int* p = this->m_p;
    this->vtbl = &DAT_010c4ce4;
    if (p)
    {
        ((void(*)(void*))DAT_010c4cec)(p);
        this->m_p = 0;
        this->m_kPointB = 0;
        this->m_kPointA = 0;
    }
    if (flags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    }
    return this;
}

struct FUN_00c66420
{
    int* vtbl;
    intptr_t Init(int a);
};
// Sets the object's vtbl to DAT_010c3b80 and, if bit 0 of a is set, deallocates this via the memory manager; returns this.
// @fnv 0x00c66420
intptr_t FUN_00c66420::Init(int aiFlags)
{
    vtbl = &DAT_010c3b80;
    if (aiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return reinterpret_cast<intptr_t>(this);
}


struct FUN_00c66450
{
    int* vtbl;
    FUN_00c66450(char a);
};

// Sets the object's vtbl to DAT_010c3b8c and, if bit 0 of a is set, deallocates the object via _g_memoryManager.
// @fnv 0x00c66450
FUN_00c66450::FUN_00c66450(char acFlags)
{
    vtbl = &DAT_010c3b8c;
    if (acFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
}

struct FUN_00c66be0_class
{
    char pad[0x60];
    hkVector4 m_kVector;
    void FUN_00c66be0(uintptr_t a);
};
// @fnv 0x00c66be0
void FUN_00c66be0_class::FUN_00c66be0(uintptr_t auiVectorAddress)
{
    ::SetNiPoint3FromHkVector4((::NiPoint3 &)(*(const hkVector4*)auiVectorAddress), m_kVector);
}

struct FUN_00c67110_v
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
};
struct FUN_00c67110_s
{
    int p0;
    int p4;
    int p8;
    int pc;
    FUN_00c67110_v* pv;
};
// @fnv 0x00c67110
void FUN_00c67110(FUN_00c67110_s* pObject)
{
    FUN_00c67110_v* v = pObject->pv;
    if (v)
        v->v40();
}

struct FUN_00c671f0_Owner;

struct FUN_00c671f0_Ref
{
    virtual void v0();
    virtual void v1();
    volatile long m_uiRefCount;
    FUN_00c671f0_Owner* m_pOwner;
};

struct FUN_00c671f0_RefVtable
{
    void* m_apSlots[35];
    void (*Detach)(FUN_00c671f0_Ref*, FUN_00c671f0_Owner*);
};

struct FUN_00c671f0_Owner
{
    char pad[0x1c];
    FUN_00c671f0_Ref* m_pRef;
};

struct FUN_00c671f0_Obj
{
    char pad[8];
    FUN_00c671f0_Owner* m_pSharedOwner;
};

// @fnv 0x00c671f0
void __cdecl ReleaseOwnerReference(FUN_00c671f0_Obj* pObj)
{
    FUN_00c671f0_Owner* pOwner = pObj->m_pSharedOwner;
    if (pOwner)
    {
        FUN_00c671f0_Ref* pOld = pOwner->m_pRef;
        if (pOld)
        {
            if (InterlockedDecrement(&pOld->m_uiRefCount) == 0)
                pOld->v1();
            pOwner->m_pRef = 0;
        }

        FUN_00c671f0_Ref* pCurRef = pOwner->m_pRef;
        if (pCurRef && pCurRef->m_pOwner != pOwner)
            (*reinterpret_cast<FUN_00c671f0_RefVtable**>(pCurRef))->Detach(pCurRef, pOwner);
    }
}

struct NineIntegerRecord
{
    NineIntegerRecord();
};

struct FUN_00c67fc0
{
    int m_field;
    NineIntegerRecord m_router;

    FUN_00c67fc0();
};

// @fnv 0x00c67fc0
FUN_00c67fc0::FUN_00c67fc0() : m_field(0)
{}

struct AddReferenceHelper
{
    void RetainReference();
};

struct S_Item;
struct FUN_00c68a40_Class
{
    char pad[0x2c];
    S_Item** m_ppItems;
    unsigned int m_uiItemCount;
    void FUN_00c68a40();
};

struct FUN_00c676e0_Class
{
};

struct FUN_00c6aac0_Class
{
    void FUN_00c6aac0();
};

struct FUN_00c67850_Class
{
    void ProcessConstraints();
};

struct FUN_00c97d30_Class
{
};

struct FUN_00c6b320_Base
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void* v37()
    {
        return 0;
    }
};

// hkpEntity and hkpConstraintInstance as the constraint queue reads them.
struct EntityWithCC
{
    char pad[0xcc];
    void* m_pSimulationIsland;
};

struct ConstraintItem : public hkReferencedObject
{
    void* m_pVtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwner;
    void* m_pData;
    void* m_pConstraintModifier;
    EntityWithCC* m_14;
    EntityWithCC* m_18;
};

struct FUN_00c6b320_Class : FUN_00c6b320_Base
{
    unsigned char pad_04[0x14];
    unsigned int m_18;
    unsigned char pad_1c[0x28];
    void** m_ppData;
    unsigned int m_uiItemCount;

    void FUN_00c6b320(hkReferencedObject* a);
};

// @fnv 0x00c6b320
void FUN_00c6b320_Class::FUN_00c6b320(hkReferencedObject* a)
{
    if (this == 0)
        return;

    void* world = this->v37();
    if (world == 0)
        return;

    if (this->m_18 > 0)
    {
        if (this->m_uiItemCount >= 0xc8)
        {
            ((FUN_00c68a40_Class*)this)->FUN_00c68a40();
            reinterpret_cast<::This676 *>((((FUN_00c676e0_Class*)this)))->ClearIndexedValues();
            ((FUN_00c6aac0_Class*)this)->FUN_00c6aac0();
            ((FUN_00c67850_Class*)this)->ProcessConstraints();
        }

        reinterpret_cast<::FUN_00c90510_class *>((((AddReferenceHelper*)a)))->FUN_00c90510();

        unsigned int count = this->m_uiItemCount;
        void** array = this->m_ppData;
        array[count] = a;
        ++this->m_uiItemCount;
    }
    else
    {
        if (a == 0)
            return;

        ConstraintItem* item = static_cast<ConstraintItem*>(a);
        if (item->m_pOwner != 0)
            return;

        EntityWithCC* p = item->m_14;
        if (p != 0 && p->m_pSimulationIsland == 0)
            return;

        p = item->m_18;
        if (p != 0 && p->m_pSimulationIsland == 0)
            return;

        reinterpret_cast<::Mgr *>((((FUN_00c97d30_Class*)world)))->FUN_00c97d30((::Item *)(a));
    }
}

extern int DAT_010c4314;
class NiAVObject;
struct NiStream;
struct NiCollisionObject
{
    NiCollisionObject(void*);
public:
    void LoadBinary(::NiStream &);
public:
    void LinkObject(::NiStream &);
public:
    void SetSceneObject(::NiAVObject *);
};
struct FUN_00c6b950 : NiCollisionObject
{
    void* m_pObject;
    int m_iWordAt04;
    int m_8;
    unsigned short m_iThirdValue;
    int m_10;
    FUN_00c6b950(void* a);
};
// @fnv 0x00c6b950
FUN_00c6b950::FUN_00c6b950(void* a) : NiCollisionObject(a)
{
    *(void**)this = (void*)&DAT_010c4314;
    m_10 = 0;
    ++DAT_01267b60;
    m_iThirdValue = 0x41;
}

namespace fnv_00c6bb70 {
struct NiStream
{
    void* GetLoadedObject();
};
class NiAVObject
{
  public:
    char pad[0x30];
    unsigned int m_uFlags;
};
struct NiCollisionObject
{
    void* m_pVtbl;
    unsigned int m_uiRefCount;
    NiAVObject* m_pkSceneObject;
};
struct bhkNiCollisionObject : NiCollisionObject
{
    void FUN_00c6bb70(NiStream& a);
};
// @fnv 0x00c6bb70
void bhkNiCollisionObject::FUN_00c6bb70(NiStream& aStream)
{
    reinterpret_cast<::NiCollisionObject *>(this)->LinkObject((::NiStream &)(aStream));
    NiAVObject* p = m_pkSceneObject;
    if (p)
        p->m_uFlags = (p->m_uFlags & 0xffffffef) | 6;
    reinterpret_cast<::FUN_00c6b980_cls *>(this)->FUN_00c6b980((::World_c6b *)(void *)(aStream.GetLoadedObject()));
}
}  // namespace fnv_00c6bb70


// Saves the thread-local value, sets it to b, calls FUN_00c6c110(a, 0), then restores the saved value.
// @fnv 0x00c6c3d0
void __cdecl SetTlsValueAndReset(intptr_t aiArg, int aiValue)
{
    struct TLSData
    {
        unsigned char pad[0x2c0];
        int value;
    };
    static __declspec(thread) TLSData tls;

    int oldValue = tls.value;
    tls.value = aiValue;
    ::FUN_00c6c110((::Node_c6c1 *)(aiArg), 0);
    tls.value = oldValue;
}

struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};
struct FUN_00c6c410_cls : FUN_00c6c290_holder
{
    void* FUN_00c6c410(unsigned int a);
};

struct FUN_00c6c720_class
{
    char pad[0x50];
    float m_afValues[1];
    void AccumulateValue(int index, float value);
};

// If m_afValues[index] equals FLT_MIN it stores value there, otherwise adds value to it and stores the sum scaled by DAT_01011588.
// @fnv 0x00c6c720
void FUN_00c6c720_class::AccumulateValue(int index, float value)
{
    float* p = m_afValues;
    if (p[index] == 1.1754943508222875e-38f)
        p[index] = value;
    else
    {
        value += p[index];
        p[index] = value * DAT_01011588;
    }
}

extern int DAT_010c446c;
struct FUN_00c6c770_Class
{
    int* vtbl;
    FUN_00c6c770_Class* FUN_00c6c770(unsigned int a);
};
// Sets the vtable pointer and, when bit 0 of a is set, frees this object through the memory manager; returns this.
// @fnv 0x00c6c770
FUN_00c6c770_Class* FUN_00c6c770_Class::FUN_00c6c770(unsigned int auiFlags)
{
    vtbl = &DAT_010c446c;
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

extern int DAT_010c446c;
struct FUN_00c6cb70_class
{
    int* vtbl;
    void* FUN_00c6cb70(int a);
};
// Sets the vtable pointer and, when bit 0 of a is set, frees the object via the memory manager, then returns this.
// @fnv 0x00c6cb70
void* FUN_00c6cb70_class::FUN_00c6cb70(int aiFlags)
{
    vtbl = &DAT_010c446c;
    if (aiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060((char*)this - GetAlignedBlockPrefix(this)->m_ucOffset);
    return this;
}

struct FUN_00cd2de0
{
    int m_iWordAt00;
public:
    ~FUN_00cd2de0();
};
struct FUN_00c6cda0_cls : FUN_00cd2de0
{
    FUN_00c6cda0_cls* FUN_00c6cda0(int ab);
};
// Calls Init, then if bit 0 of ab is set deletes this with size 0x14 and returns this.
// @fnv 0x00c6cda0
FUN_00c6cda0_cls* FUN_00c6cda0_cls::FUN_00c6cda0(int abDelete)
{
    reinterpret_cast<::FUN_00cd2de0 *>(this)->FUN_00cd2de0::~FUN_00cd2de0();
    if (abDelete & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

struct FUN_00cc2350_s
{
};
struct FUN_00c6d100_s : FUN_00cc2350_s
{
    FUN_00c6d100_s* FUN_00c6d100(bool a);
};
// Calls FUN_00cc2350, then deletes this with size 0x18 when a is set, and returns this.
// @fnv 0x00c6d100
FUN_00c6d100_s* FUN_00c6d100_s::FUN_00c6d100(bool abFree)
{
    reinterpret_cast<::FUN_00cc2350 *>(this)->FUN_00cc2350::~FUN_00cc2350();
    if (abFree & 1)
        ::FUN_00aa1460(this, 0x18);
    return this;
}

struct S_00c85ce0
{
    void FUN_00c85ce0(unsigned int);
};
struct FUN_00c6d770_class
{
    char pad[0x594];
    void* m_594;
    void* m_598;
    void FUN_00c6d770(unsigned int a);
};
// Forwards a to FUN_00c85ce0 on m_594 and m_598 when each pointer is non-null.
// @fnv 0x00c6d770
void FUN_00c6d770_class::FUN_00c6d770(unsigned int auiValue)
{
    if (m_594)
        ((S_00c85ce0*)m_594)->FUN_00c85ce0(auiValue);
    if (m_598)
        ((S_00c85ce0*)m_598)->FUN_00c85ce0(auiValue);
}

struct FUN_008d1160_Class
{
    void FUN_00c705c0();
};
struct FUN_00c70c60_Class : FUN_008d1160_Class
{
    char* FUN_00c70c60(unsigned char abFree);
};
// Calls FUN_00c705c0, then if abFree bit 0 is set and this is non-null, frees the block at this minus its aligned-block prefix byte; returns this.
// @fnv 0x00c70c60
char* FUN_00c70c60_Class::FUN_00c70c60(unsigned char abFree)
{
    FUN_00c705c0();
    if ((abFree & 1) && this)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(reinterpret_cast<char*>(this) - GetAlignedBlockPrefix(this)->m_ucOffset);
    return reinterpret_cast<char*>(this);
}

extern int DAT_010c4b2c;
struct FUN_00c74760
{
    int* vtbl;
    int m_uiRefCount;
    unsigned char m_bFlag;
    int m_iFadeIndex;
    int m_iState2;
    FUN_00c74760();
};

// @fnv 0x00c74760
FUN_00c74760::FUN_00c74760()
{
    m_iFadeIndex = 0;
    m_iState2 = 0;
    m_uiRefCount = 1;
    m_bFlag = 1;
    vtbl = &DAT_010c4b2c;
}

struct Heap : MemoryManager
{
    void* Allocate(unsigned int);
};

// Allocates a+0x10 bytes from _g_memoryManager, aligns the returned pointer to 16 bytes and stores the alignment offset in the byte before it.
// @fnv 0x00c74ea0
void* FUN_00c74ea0(unsigned int uiSize)
{
    unsigned char* p = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>((((Heap*)&::g_memoryManager)))->FUN_00aa3e40(uiSize + 0x10);
    unsigned char n = (unsigned char)(0x10 - ((unsigned char)(uintptr_t)p & 0xf));
    p += n;
    GetAlignedBlockPrefix(p)->m_ucOffset = n;
    return p;
}

// @fnv 0x00c74f90
void __cdecl FUN_00c74f90(void* a)
{
    if (a)
    {
        hkMemoryRouter::getInstance().heap().blockFree(a, 0x30);
    }
}


struct FUN_00c76070_Class
{
    int* vtbl;
    int* m_kPointA;
    int* m_kPointB;
    void* FUN_00c76070(unsigned int flags);
};

// @fnv 0x00c76070
void* FUN_00c76070_Class::FUN_00c76070(unsigned int flags)
{
    vtbl = (int*)&DAT_010c4ca4;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    ::FUN_00aa10f0(m_kPointB);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00c75fa0_Class
{
    void FUN_00c75fa0();
    void* FUN_00c7a5b0(unsigned int flags);
};
struct FUN_00c7fb20
{
    int* m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00c7fb20();
};
// @fnv 0x00c7fb20
FUN_00c7fb20::FUN_00c7fb20()
{
    m_iWordAt04 = 0;
    m_8 = 1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_vtbl = &DAT_010c5398;
}


// Maps param_1 (0, 1, 4, or other) to 1, 2, 3, or 2 and stores it in DAT_011afe5c.
// @fnv 0x00c661d0
void __cdecl FUN_00c661d0(int aiCode)
{
    switch (aiCode)
    {
    case 0:
        DAT_011afe5c = 1;
        break;
    case 1:
        DAT_011afe5c = 2;
        break;
    case 4:
        DAT_011afe5c = 3;
        break;
    default:
        DAT_011afe5c = 2;
        break;
    }
}


// @fnv 0x00c66230
void __cdecl FUN_00c66230(unsigned char a)
{
    (*reinterpret_cast<unsigned char *>(&::DAT_012677a3)) = a;
}

struct FUN_00c66250_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

// @fnv 0x00c66250
void FUN_00c66250(FUN_00c66250_cls* p)
{
    p->m_0c |= 0x40;
}

class FUN_00c66280_obj
{
  public:
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
    virtual int v2c(void* p, int zero, bool flag);
};

struct FUN_00c66280_arg
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
    int m_10;
};

// Calls the virtual method v2c on a1, passing a2->m_0c, zero, and whether a2->m_10 is nonzero, and returns its result.
// @fnv 0x00c66280
int CallVirtualWithArg(FUN_00c66280_obj* pObj, FUN_00c66280_arg* a2)
{
    return pObj->v2c(a2->m_0c, 0, a2->m_10 != 0);
}

struct FUN_00c662d0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void* vf3C();
};

struct FUN_00c81b40_Tgt
{
};

struct FUN_00c81ae0_Tgt
{
};

struct Param2Struct
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

// If param_1 is non-null, gets its vf3C result and calls UpdateCountdown or InitOnce on it depending on whether param_2->unk0C is zero.
// @fnv 0x00c662d0
void __cdecl DispatchOnParamFlag(FUN_00c662d0_Obj* pObj, Param2Struct* pParams)
{
    if (pObj != NULL)
    {
        void* pResult = pObj->vf3C();

        if (pResult != NULL)
        {
            if (pParams->unk0C == 0)
            {
                reinterpret_cast<::S_00c81b40_Owner *>((((FUN_00c81b40_Tgt*)pResult)))->UpdateCountdown();
            }
            else
            {
                reinterpret_cast<::FUN_00c81ae0_cls *>((((FUN_00c81ae0_Tgt*)pResult)))->InitOnce();
            }
        }
    }
}

extern int DAT_010c3bc4;

struct FUN_00c66510_cls
{
    void* m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;

    FUN_00c66510_cls* FUN_00c66510(unsigned char acFlags);
};

// Sets the vtable pointer, calls BaseRelease, and if bit 0 of acFlags is set frees this through the Havok heap allocator using m_uSize.
// @fnv 0x00c66510
FUN_00c66510_cls* FUN_00c66510_cls::FUN_00c66510(unsigned char acFlags)
{
    m_vptr = &DAT_010c3bc4;
    reinterpret_cast<::FUN_00c93e50 *>(this)->FUN_00c93e50::~FUN_00c93e50();
    if (acFlags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, m_uSize);
    }
    return this;
}


struct ThreadMemoryScope
{
    int previous;
    ThreadMemoryScope() : previous(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }
    ~ThreadMemoryScope()
    {
        g_tlsBlock.memoryContext = previous;
    }
};

struct ThreadObserver
{
    virtual void onInit();
    virtual void onShutdown();
    virtual void notify(int enabled);
};

extern ThreadObserver* DAT_01268450;

// Creates a ThreadMemoryScope and, if DAT_01268450 is non-null, calls its notify with 1.
// @fnv 0x00c66570
void __cdecl NotifyThreadObserverEnabled()
{
    ThreadMemoryScope scope;
    if (DAT_01268450 != 0)
    {
        DAT_01268450->notify(1);
    }
}


struct FUN_00c665f0_cls
{
    void* m_vptr00;

    void FUN_00c665f0();
};

// @fnv 0x00c665f0
void FUN_00c665f0_cls::FUN_00c665f0()
{
    m_vptr00 = &DAT_010c3bb8;
}

class FUN_00c66de0_cls;

class FUN_00c66de0_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual FUN_00c66de0_cls* v94();
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    FUN_00c66de0_cls* m_350;
    void FUN_00c66de0(bool flag);
};

// If this is non-null, stores this (or null when flag is false) into the m_350 field of the object returned by v94, then calls Reset(flag).
// @fnv 0x00c66de0
void FUN_00c66de0_cls::FUN_00c66de0(bool flag)
{
    if (this != 0)
    {
        FUN_00c66de0_cls* p = this->v94();
        if (p != 0)
            p->m_350 = flag ? this : 0;
    }
    reinterpret_cast<::FUN_00c899d0_Class *>((this))->ReleaseReference(flag);
}


struct HavokOwner
{
    virtual void release(unsigned int flag);
};

struct HavokThreadStateScope
{
    int previousState;

    HavokThreadStateScope() : previousState(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }

    ~HavokThreadStateScope()
    {
        g_tlsBlock.memoryContext = previousState;
    }
};

struct FUN_00c66e70_Class
{
    int unk00;
    int unk04;
    int unk08;
    char* objectData;

    void FUN_00c66e70(char destroy);
};

// If destroy is set, releases the HavokOwner stored before objectData and clears objectData.
// @fnv 0x00c66e70
void FUN_00c66e70_Class::FUN_00c66e70(char destroy)
{
    HavokThreadStateScope scope;
    if (destroy)
    {
        if (objectData)
        {
            HavokOwner* owner = reinterpret_cast<HavokOwner*>(objectData - 0xf0);
            if (owner)
                owner->release(1);
        }
        objectData = 0;
    }
}

struct FUN_00c66f90_Result
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
};

struct FUN_00c66f90_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual FUN_00c66f90_Result* vf94();

    bool FUN_00c66f90();
};

// @fnv 0x00c66f90
bool FUN_00c66f90_Class::FUN_00c66f90()
{
    bool result = false;
    FUN_00c66f90_Result* object = vf94();

    if (object)
        result = object->unk2C != 0;

    return result;
}

struct UpdateParams
{
    float fTime;
    bool b0;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
    UpdateParams() : fTime(0.0f), b0(false), b1(false), b2(false), b3(false), b4(false)
    {}
};

struct SubObj
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short usFlags;
};

struct Target
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
    virtual int GetID();  // 0x94
    virtual void v38();
    virtual void SetSource(Target* p);  // 0x9c
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    int unk0c;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char bEnabled;
};

struct Updater
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
    virtual void Update(UpdateParams* p);  // 0xb8
};

struct ControlledObj
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
    virtual SubObj* GetSub();  // 0x3c
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
    virtual void Activate(bool b);  // 0xc0
    int unk04;
    Updater* pUpdater;
    unsigned short usFlags;
    Target* pTarget;
};

struct UpdateData
{
    Target* pSource;
    int unk04;
    int unk08;
    unsigned int bPending : 1;
    int unk10;
    int iCount;
    int iMode;
};

extern bool DAT_011afe58;

// Updates the controlled object's sub-object and flags from the update data, syncs the target source, runs the updater, and increments the data count.
// @fnv 0x00c66ff0
void __cdecl FUN_00c66ff0(ControlledObj* pControlledObj, UpdateData* data)
{
    Target* target = pControlledObj->pTarget;
    if (target)
    {
        SubObj* sub = pControlledObj->GetSub();
        if (sub)
        {
            if (data->iCount == 0)
                sub->usFlags |= 0x100;
            else
                sub->usFlags &= ~0x100;
        }
        bool bPending = data->bPending;
        if (bPending)
            pControlledObj->usFlags |= 4;
        else
            pControlledObj->usFlags &= ~4;
        if (bPending)
            pControlledObj->usFlags |= 8;
        if (DAT_011afe58)
            ::AssignSystemGroup((::BC66F10RefObject *)(target), (::BC66F10Entry *)(data));
        int iSourceID = data->pSource->GetID();
        if (target->GetID() != iSourceID)
        {
            if (data->iMode)
                pControlledObj->usFlags |= 0x40;
            else
                pControlledObj->usFlags &= ~0x40;
            target->SetSource(data->pSource);
        }
        UpdateParams params;
        pControlledObj->pUpdater->Update(&params);
        if (data->pSource->bEnabled)
            pControlledObj->Activate(true);
    }
    data->bPending = 0;
    data->iCount++;
}

struct FUN_00c85d20_Class
{
};

struct FUN_00c67130_First
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00c85d20_Class* unk10;
};

struct FUN_00c67130_Second
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

// If first->unk10 is set, calls its FUN_00c85d20 with whether second->unk0c is non-zero.
// @fnv 0x00c67130
void __cdecl SetEnabledFromFlag(FUN_00c67130_First* first, FUN_00c67130_Second* second)
{
    if (first->unk10)
    {
        reinterpret_cast<::C *>((first->unk10))->FUN_00c85d20(second->unk0c != 0);
    }
}

// SetBodyFloat94
//
// Copies a float that arrives in a parameter record into the physics body that
// is reachable through the object stored in a world record:
//
//   record->m_pObject->vtable[16]()  ->  holder
//   holder->m_pPhysicsBody->m_f94           =  param->m_f0c
//
// The call goes through the object's slot table (slot 16, offset 0x40) and the
// slot is invoked with the object as its "this" argument.

struct BhkPhysBody
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
    float m_f94;
};

// Result handed back by the slot call; m_pPhysicsBody points at the physics body.
struct BhkPhysResult
{
    int unk00;
    int unk04;
    BhkPhysBody* m_pPhysicsBody;
};

struct BhkPhysObject;

// Slot 16 of the object's slot table: takes the object, returns the holder.
typedef BhkPhysResult*(* BhkPhysGetResult)(BhkPhysObject* pSelf);

struct BhkPhysSlotTable
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
    BhkPhysGetResult m_fnGetResult;
};

struct BhkPhysObject
{
    BhkPhysSlotTable* m_pSlots;
};

// World record: the physics object it refers to sits at offset 0x10.
struct BhkPhysRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BhkPhysObject* m_pObject;
};

// Parameter record: the float to copy sits at offset 0xc.
struct BhkPhysParam
{
    int unk00;
    int unk04;
    int unk08;
    float m_f0c;
};

// Gets the physics result from the record's object and writes pParam->m_f0c into the body's m_f94, returning early if the object or result is null.
// @fnv 0x00c67150
void SetBodyFloat94(BhkPhysRecord* pRecord, BhkPhysParam* pParam)
{
    BhkPhysObject* pObject = pRecord->m_pObject;
    if (pObject == 0)
        return;

    BhkPhysGetResult fnGetResult = pObject->m_pSlots->m_fnGetResult;
    BhkPhysResult* pResult = fnGetResult(pObject);
    if (pResult == 0)
        return;

    pResult->m_pPhysicsBody->m_f94 = pParam->m_f0c;
}

struct FUN_00c67180_Target
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
    float m_90;
};

struct FUN_00c67180_Holder
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00c67180_Target* m_pFlagTarget;
};

struct FUN_00c67180_Node
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
    virtual FUN_00c67180_Holder* GetHolder();
};

struct FUN_00c67180_Arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float m_0c;
};

struct FUN_00c67180_Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00c67180_Node* m_pReferencedNode;
};

// Gets the holder from owner's node and copies arg's m_0c float into the holder target's m_90, returning early if node or holder is null.
// @fnv 0x00c67180
void __cdecl SetTargetFloat(FUN_00c67180_Owner* owner, FUN_00c67180_Arg* volatile arg)
{
    FUN_00c67180_Node* node = owner->m_pReferencedNode;
    if (node == 0)
        return;
    FUN_00c67180_Holder* holder = node->GetHolder();
    if (holder == 0)
        return;
    FUN_00c67180_Target* target = holder->m_pFlagTarget;
    target->m_90 = arg->m_0c;
}

struct FUN_00561580_class
{
};
struct FUN_00c671b0_dispatch
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual FUN_00561580_class* vf40();
};
struct FUN_00c671b0_source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00c671b0_dispatch* dispatcher;
};
struct FUN_00c671b0_state
{
    int unk00;
    int unk04;
    int unk08;
    int enabled;
};
// @fnv 0x00c671b0
void __cdecl SetEnabledOnDispatcherObject(FUN_00c671b0_source* source, FUN_00c671b0_state* state)
{
    if (source)
    {
        FUN_00c671b0_dispatch* dispatcher = source->dispatcher;
        if (dispatcher)
        {
            FUN_00561580_class* object = dispatcher->vf40();
            if (object)
                reinterpret_cast<::fnv_00561580::FUN_00561580_Class *>((object))->FUN_00561580(state->enabled != 0);
        }
    }
}

class C67240RefObject
{
  public:
};

struct C67240WorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67240RefObject* m_pPointer;
};

struct C67240Params
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiLayer;
};

// @fnv 0x00c67240
void ApplyLayerToRefObject(C67240WorldObject* pkWorldObject, C67240Params* pkParams)
{
    if (pkWorldObject->m_pPointer)
        reinterpret_cast<::S_00c85ce0 *>((pkWorldObject->m_pPointer))->FUN_00c85ce0(pkParams->m_uiLayer);
}

struct C67260Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct C67260Entity
{
};

struct C67260Shape
{
    int unk00;
    int unk04;
    C67260Entity* m_pkEntity;
};

class C67260Body
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual C67260Shape* GetShape();
};

struct C67260CollisionObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67260Body* m_pkBody;
};

struct C67260Context
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
};

// If the object's body shape has an entity whose check returns true, increments pkContext->iCount, then clears pkContext->bRecurse.
// @fnv 0x00c67260
void CountEntityAndClearRecurse(C67260CollisionObject* pkObject, C67260Context* pkContext)
{
    C67260Body* pkBody = pkObject->m_pkBody;
    if (!pkBody)
        return;
    C67260Shape* pkShape = pkBody->GetShape();
    if (!pkShape)
        return;
    C67260Entity* pkEntity = pkShape->m_pkEntity;
    if (pkEntity ? (bool)(*(::C67260Bool *)(reinterpret_cast<::FUN_00c9bff0_Class *>((void *)(pkEntity))->FUN_00c9bff0({}))) : false)
        pkContext->iCount++;
    pkContext->bRecurse = false;
}

struct BodyView : hkReferencedObject
{
    int unk00;
    int unk04;
    void* world;
};
struct SpaceView
{
};
struct ContextGuard
{
    int previous;
    ContextGuard() : previous(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }
    ~ContextGuard()
    {
        g_tlsBlock.memoryContext = previous;
    }
};
struct WorldView
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual SpaceView* vfn37();
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
    BodyView** bodies;
    unsigned int count;
    void ReleaseBodies();
};
// @fnv 0x00c67cd0
void WorldView::ReleaseBodies()
{
    ContextGuard guard;
    if (count > 0)
    {
        if (count >= 100)
            count = 100;
        SpaceView* space = vfn37();
        if (space)
        {
            for (unsigned int i = 0; i < count; ++i)
            {
                if (bodies[i] && bodies[i]->world)
                    reinterpret_cast<::FUN_00c97f50_Class *>((space))->DispatchOrQueue(bodies[i]);
                if (bodies[i])
                    reinterpret_cast<::hkReferencedObjectC905 *>((bodies[i]))->FUN_00c905b0();
            }
            std::memset(bodies, 0, count * sizeof(BodyView*));
            count = 0;
        }
    }
}

namespace fnv_00c67df0 {
extern unsigned int DAT_0126fd98;
struct ContextGuard
{
    unsigned int saved;
    ContextGuard(unsigned int value)
    {
        saved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = value;
    }
    ~ContextGuard()
    {
        g_tlsBlock.memoryContext = saved;
    }
};
struct PendingItem
{
    int unk00, unk04;
    void* owner;
};
struct PendingQuery
{
    void FUN_00c97e80(char*, PendingItem*);
};
struct PendingWorld : FUN_00c6b320_Base
{
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
    PendingItem** items;
    unsigned int count;
    void ProcessPendingItems();
};
// @fnv 0x00c67df0
void PendingWorld::ProcessPendingItems()
{
    ContextGuard guard(16);
    if (count)
    {
        if (count >= 200)
            count = 200;
        PendingQuery* query = (PendingQuery*)v37();
        if (query)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                if (items[index] && items[index]->owner)
                {
                    char status;
                    query->FUN_00c97e80(&status, items[index]);
                }
                if (items[index])
                    reinterpret_cast<::hkReferencedObjectC905 *>((((hkReferencedObject*)items[index])))->FUN_00c905b0();
            }
            std::memset(items, 0, count * sizeof(PendingItem*));
            count = 0;
        }
    }
}
}  // namespace fnv_00c67df0

class C67F20RefObject
{
  public:
    virtual ~C67F20RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

struct C67F20Heap
{
};


struct C67F20Node
{
    int unk00;
    C67F20Node* m_pkNext;

    ~C67F20Node();

};

class C67F20List
{
  public:
    NiPointer<C67F20RefObject> m_spOwner;
    C67F20Node* m_pkHead;

    void FUN_00c67f20();
};

// Deletes every node in the list, unlinking each one, then releases the owner pointer.
// @fnv 0x00c67f20
void C67F20List::FUN_00c67f20()
{
    while (m_pkHead)
    {
        C67F20Node* pkNext = m_pkHead->m_pkNext;
        m_pkHead->m_pkNext = 0;
        delete m_pkHead;
        m_pkHead = pkNext;
    }
    m_spOwner = NiPointer<C67F20RefObject>(0);
}

struct CriticalSection : CRITICAL_SECTION
{
    CriticalSection()
    {
        InitializeCriticalSection(this);
    }
    ~CriticalSection()
    {
        DeleteCriticalSection(this);
    }
};
struct LifoAllocator
{
    void* current;
    void* end;
    void* firstNonLifoEnd;
    unsigned int slabSize;
    void* buffer;
    void* backingAllocator;
    int allocationCount;
};
struct HavokRouter
{
    void* temporaryAllocator;
    void* heapAllocator;
    void* debugAllocator;
    LifoAllocator stackAllocator;
};
struct RouterSlot
{
    int state;
    HavokRouter memory;
    RouterSlot();
    ~RouterSlot();
};
struct FUN_00c67fe0
{
    CriticalSection lock;
    RouterSlot routers[16];
    int state;
    FUN_00c67fe0();
};
// @fnv 0x00c67fe0
FUN_00c67fe0::FUN_00c67fe0() : state(0)
{}


struct FNVEntryKey
{
    unsigned int lo;
    unsigned int hi;
};

class FNVEntryTarget
{
  public:
};

class FUN_00c688b0_cls
{
  public:
    unsigned int unk00[4];
    unsigned int m_0x10;
    unsigned char unk14[0x68];
    FNVEntryKey* m_0x7c;
    unsigned int m_0x80;

    void FUN_00c688b0();
};

// If m_0x10 is nonzero, calls FUN_00c984a0 on each of the m_0x80 entries in m_0x7c in reverse order, then resets m_0x80 to 0.
// @fnv 0x00c688b0
void FUN_00c688b0_cls::FUN_00c688b0()
{
    if (m_0x10 == 0)
        goto done;
    {
        unsigned int n = m_0x80;
        if (n != 0)
        {
            do
            {
                --n;
                FNVEntryKey* item = &m_0x7c[n];
                FNVEntryTarget* target = *reinterpret_cast<FNVEntryTarget**>(&(*reinterpret_cast<int *>(&::DAT_012681e0)));
                reinterpret_cast<::FUN_00c984a0_Class *>((target))->FUN_00c984a0(item->hi, item->lo, 0);
            } while (n != 0);
        }
    }
done:
    m_0x80 = 0;
}

struct S_00c68900_Node;

struct S_00c68900_Ref
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void* v14()
    {
        return 0;
    }
};

struct S_00c68900_Items
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
    S_00c68900_Node** m_pItems;
    unsigned short unk_a4;
    unsigned short m_uiItemCount;
    unsigned char unk_a8;
};

struct S_00c68900_Node
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual S_00c68900_Items* v3()
    {
        return 0;
    }

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00c68900_Ref* m_pReference;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_flags;
};

struct S_00c68900_Context
{
    int unk00;
    unsigned char m_bEnableState;
    unsigned int unk08;
};

typedef void(__cdecl* S_00c68900_Callback)(void* object, S_00c68900_Context* context);


// @fnv 0x00c68900
void __cdecl FUN_00c68900(S_00c68900_Node* node, S_00c68900_Context* context, S_00c68900_Callback callback)
{
    if (!node)
        return;

    void* object;
    if (node->m_pReference)
        object = node->m_pReference->v14();
    else
        object = 0;

    if (!context->unk08)
        node->m_flags = (node->m_flags & 0xffffffef) | 6;

    if (object)
        callback(object, context);

    if (context->m_bEnableState)
    {
        S_00c68900_Items* items = node->v3();
        if (items)
        {
            unsigned int index = 0;
            while (index < items->m_uiItemCount)
            {
                S_00c68900_Node* child = items->m_pItems[index];
                ::FUN_00c68900(child, context, callback);
                ++index;
            }
        }
    }
}

class Fnv68990Flagged
{
  public:
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int m_flags;
};

class Fnv68990Inner
{
  public:
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual Fnv68990Flagged* GetFlagged();
};

class Fnv68990Holder
{
  public:
    unsigned int unk00, unk04, unk08, unk0C;
    Fnv68990Inner* m_pInner;
};

class Fnv68990Arg
{
  public:
    unsigned int unk00, unk04, unk08;
    unsigned int m_flag0C;
};

// If the holder's inner object and its flagged object exist, sets or clears bit 0x40 in the flagged object's m_flags based on arg->m_flag0C.
// @fnv 0x00c68990
void SetFlaggedBit40(Fnv68990Holder* holder, Fnv68990Arg* arg)
{
    Fnv68990Inner* inner = holder->m_pInner;
    if (inner == 0)
    {
        return;
    }
    Fnv68990Flagged* f = inner->GetFlagged();
    if (f == 0)
    {
        return;
    }
    if (arg->m_flag0C != 0)
    {
        f->m_flags |= 0x40;
    }
    else
    {
        f->m_flags &= 0xffffffbf;
    }
}

// Physics shape bookkeeping: fetch the body that owns the shape and ask it
// to re-create the shape when the shape is missing or has the "static" type.
struct PhysShape
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCc;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDc;
    int unkE0;
    int unkE4;
    unsigned char m_nShapeType;
};

struct PhysBody
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
    virtual PhysBody* v16();
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
    virtual void v57(int a);
    int m_iWordAt04;
    PhysShape* m_pShape;
};

struct PhysOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    PhysBody* m_pPhysicsBody;
};

// Gets the body from pOwner, resolves its shape body, and calls v57(4) when the shape is missing or its m_nShapeType is 5.
// @fnv 0x00c689c0
void __cdecl FUN_00c689c0(PhysOwner* pOwner)
{
    PhysBody* pBody = pOwner->m_pPhysicsBody;
    if (pBody != 0)
    {
        PhysBody* pShapeBody = pBody->v16();
        if (pShapeBody != 0)
        {
            PhysShape* pShape = pShapeBody->m_pShape;
            unsigned int uiShapeType = 0;
            if (pShape != 0)
                uiShapeType = pShape->m_nShapeType;
            if (pShape == 0 || uiShapeType == 5)
            {
                pShapeBody->v57(4);
            }
        }
    }
}


struct ScopedHavokThreadMode
{
    unsigned int oldMode;
    ScopedHavokThreadMode() : oldMode(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }
    ~ScopedHavokThreadMode()
    {
        g_tlsBlock.memoryContext = oldMode;
    }
};

struct FUN_00c674d0_Call
{
};

// Clamps the count at offset 0x30 to 3000, passes it with the resource at 0x2c to FUN_00c674d0, then resets the count to 0.
// @fnv 0x00c68a40
void FUN_00c68a40_Class::FUN_00c68a40()
{
    ScopedHavokThreadMode threadMode;
    unsigned int& count = m_uiItemCount;
    if (count > 0)
    {
        if (count >= 3000)
            count = 3000;
        reinterpret_cast<::S_Owner *>((reinterpret_cast<FUN_00c674d0_Call*>(this)))->FUN_00c674d0(
            m_ppItems, count);
        count = 0;
    }
}


class RefObj_b5063
{
  public:
    virtual void Reserved_b5063();
    virtual void DeleteThis();
    volatile long m_refs;
};

class Owner_b5063
{
  public:
    RefObj_b5063* m_pEntryObject;
    void LockOwnerAndRelease();
};

struct Holder_b5063
{
    Owner_b5063* m_pOwnerObject;
    Holder_b5063(Owner_b5063* owner) : m_pOwnerObject(owner)
    {}
    ~Holder_b5063()
    {
        RefObj_b5063* obj = m_pOwnerObject->m_pEntryObject;
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->m_refs) == 0)
            {
                obj->DeleteThis();
            }
        }
    }
};

// Creates a Holder_b5063 for this owner, then calls LockOwner; the holder releases the owner's reference on destruction.
// @fnv 0x00c68ae0
void Owner_b5063::LockOwnerAndRelease()
{
    Holder_b5063 holder(this);
    reinterpret_cast<::C67F20List *>(this)->FUN_00c67f20();
}

namespace fnv_00c68bc0 {
// FUN_00c68bc0 (42 bytes)
//
// The first virtual of bhkWorldCinfo (its vftable lives at 0x010c3c44 and its
// slot 0 points here; the sibling hkpWorldCinfo::FUN_005535c0 at 0x005535c0
// is the same routine built with /Od).
//
//   push esi / mov esi,ecx     `this` is parked in a callee-saved register
//   call 0x00553540            hkpWorldCinfo's initialiser, called on `this`
//   test byte ptr [esp+8],1    the caller's flag, only its low bit matters
//   je    <end>
//   call 0x00c85750            the global audio/system manager
//   movzx edx,word ptr [esi+4] this->unk04
//   mov   ecx,[eax+0x10]       the manager's sink object
//   mov   eax,[ecx] / mov eax,[eax+8]   its vtable slot 2
//   push  edx / push esi / call eax
//   mov   eax,esi / pop esi / ret 4      the function returns `this`

struct BhkWorldCinfo;

struct BhkWorldCinfo
{
    void* vtbl;            // +0x00 (the real vtable pointer)
    unsigned short unk04;  // +0x04
    BhkWorldCinfo* FUN_00c68bc0(int flag);
};


// Calls FUN_00553540, and if flag bit 0 is set frees this as an unk04-byte block through the Havok heap allocator, then returns this.
// @fnv 0x00c68bc0
BhkWorldCinfo* BhkWorldCinfo::FUN_00c68bc0(int flag)
{
    reinterpret_cast<struct ::FUN_00553540 *>((this))->FUN_00553540::~FUN_00553540();

    if (flag & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, this->unk04);
    }

    return this;
}
}  // namespace fnv_00c68bc0

struct FUN_00c68f50_cls;

struct FUN_00aa4060_cls
{
};


struct FUN_00c68f50_cls
{
    FUN_00c663d0 m_key;
    FUN_00c68f50_cls* m_next;

    void RemoveKey(FUN_00c663d0_Ref** pKey);
};

// @fnv 0x00c68f50
void FUN_00c68f50_cls::RemoveKey(FUN_00c663d0_Ref** pKey)
{
    FUN_00c663d0_Ref* key = *pKey;
    if (key == 0)
    {
        return;
    }
    FUN_00c68f50_cls* head_next = m_next;
    if (head_next == 0 && m_key.m_pObject == 0)
    {
        return;
    }
    FUN_00c68f50_cls* cur = this;
    FUN_00c68f50_cls* prev = this;
    do
    {
        if (cur->m_key.m_pObject == key)
        {
            goto found;
        }
        prev = cur;
        cur = cur->m_next;
    } while (cur != 0);
    return;

found:
    if (cur == this)
    {
        if (head_next != 0)
        {
            m_next = head_next->m_next;
            m_key = head_next->m_key;
            head_next->m_next = 0;
            reinterpret_cast<::Owner_b5063 *>((head_next))->LockOwnerAndRelease();
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(head_next);
            return;
        }
        FUN_00c663d0_Ref* obj = m_key.m_pObject;
        if (obj == 0)
        {
            return;
        }
        if (InterlockedDecrement(&obj->m_uiRefCount) == 0)
        {
            obj->v1();
        }
        m_key.m_pObject = 0;
        return;
    }
    prev->m_next = cur->m_next;
    cur->m_next = 0;
    reinterpret_cast<::Owner_b5063 *>((cur))->LockOwnerAndRelease();
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(cur);
}

struct CpuOpaque;
// @fnv 0x00c69220
CpuOpaque* __cdecl FUN_00c69220()
{
    return &(*reinterpret_cast<::CpuOpaque *>(&::g_01267824));
}

// @fnv 0x00c69230
int __cdecl FUN_00c69230()
{
    return 240;
}

extern void* DAT_011afe90;

struct S_00c69f50_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};


// @fnv 0x00c69f50
bool FUN_00c69f50(S_00c69f50_Obj* obj, unsigned char ucValue, unsigned char ucForce)
{
    bool result = false;
    if (obj)
    {
        S_00c69f50_Obj* info;
        if (ucForce || ((info = ((::S_00c69f50_Obj *)(::GetExtraDataChecked((::NiAVObjectX *)(obj))))) ? (info->unk0c & 2) : 0))
        {
            int ctx[7];
            result = true;
            *(unsigned char*)&ctx[1] = ucValue;
            void* g = DAT_011afe90;
            ctx[0] = 0;
            ctx[2] = 2;
            if (g)
            {
                ::FUN_00c68900((::S_00c68900_Node *)(obj), (::S_00c68900_Context *)(int *)(&ctx[0]), (void (*)(void *, S_00c68900_Context *))(g));
            }
        }
    }
    return result;
}

struct DispatchState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
};

struct DispatchPacket
{
    unsigned int status;
    unsigned char mode;
    unsigned int opcode;
    unsigned int selection;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

extern "C" S_00c68900_Callback DAT_011afe94;

// @fnv 0x00c6a040
unsigned char __cdecl FUN_00c6a040(intptr_t object, unsigned char selection, unsigned char mode, unsigned char overrideCheck)
{
    unsigned char result = 0;
    if (object)
    {
        if (!overrideCheck)
        {
            DispatchState* state = ((::DispatchState *)(::GetExtraDataChecked((::NiAVObjectX *)(object))));
            if (!state)
                goto exit;

            unsigned int value = state->flags;
            unsigned int& flags = value;
            if (!(flags &= 2))
                goto exit;
        }

        DispatchPacket packet;
        packet.mode = mode;
        result = 1;
        packet.status = 0;
        packet.opcode = 3;
        packet.selection = selection;

        if (DAT_011afe94)
            ::FUN_00c68900((::S_00c68900_Node *)(object), (::S_00c68900_Context *)(::DispatchPacket *)(&packet), DAT_011afe94);
    }
exit:
    return result;
}

class C6A2E0AVObject;
class C6A2E0CollisionObject;

struct C6A2E0Context
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
    void* pUserData;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};

typedef void (*C6A2E0Callback)(C6A2E0CollisionObject*, C6A2E0Context*);

struct C6A2E0Properties
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiValue1;
};

extern C6A2E0Callback g_pfnC6A2E0Callback;

static inline unsigned int C6A2E0IsEnabled(C6A2E0AVObject* pkObject)
{
    C6A2E0Properties* pkProps = ((::C6A2E0Properties *)(::GetExtraDataChecked((::NiAVObjectX *)(pkObject))));
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}

// @fnv 0x00c6a2e0
bool FUN_00c6a2e0(C6A2E0AVObject* pkObject, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A2E0IsEnabled(pkObject)))
    {
        C6A2E0Context kContext;
        kContext.bRecurse = bRecurse;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.uiTraversalFlags = 4;
        if (g_pfnC6A2E0Callback)
            ::FUN_00c68900((::S_00c68900_Node *)(pkObject), (::S_00c68900_Context *)(::C6A2E0Context *)(&kContext), (void (*)(void *, S_00c68900_Context *))(g_pfnC6A2E0Callback));
    }
    return bResult;
}

class FUN_00c6a810_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned char m_16;
    void FUN_00c6a810(void* target, unsigned char value);
};

struct FlagRequestB3610
{
    unsigned char flag;
    int type;
    int value;
    int unk0C;
    int unk10;
    int unk14;
};

struct FlagFrameB3610
{
    int zero;
    FlagRequestB3610 req;
};

extern void* DAT_011afea0;

// Stores value into m_16 and, if target is non-null and DAT_011afea0 is set, sends a flag request with type 6 and the stored flag's boolean value.
// @fnv 0x00c6a810
void FUN_00c6a810_cls::FUN_00c6a810(void* target, unsigned char value)
{
    if (m_16 != value)
    {
        m_16 = value;
    }
    if (target != 0)
    {
        FlagFrameB3610 frame;
        frame.zero = 0;
        frame.req.flag = 1;
        frame.req.type = 6;
        frame.req.value = m_16 != 0;
        if (DAT_011afea0 != 0)
        {
            ::FUN_00c68900((::S_00c68900_Node *)(target), (::S_00c68900_Context *)(::FlagRequestB3610 *)((FlagRequestB3610*)&frame), (void (*)(void *, S_00c68900_Context *))(DAT_011afea0));
        }
    }
}

// Deleting destructor of FUN_00c6b070: runs the base cleanup, then optionally
// releases the block (the allocator stores the block size just below the object).
struct FUN_00c6aca0_holder
{
};

struct FUN_00c6b070_cls : public FUN_00c6aca0_holder
{
    FUN_00c6b070_cls* FUN_00c6b070(unsigned char auFlags);
};

// @fnv 0x00c6b070
FUN_00c6b070_cls* FUN_00c6b070_cls::FUN_00c6b070(unsigned char auFlags)
{
    reinterpret_cast<::FUN_00c6aca0 *>((this))->FUN_00c6aca0::~FUN_00c6aca0();

    if (auFlags & 1)
    {
        if (this != 0)
        {
            unsigned char* pBlock = (unsigned char*)this;
            reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<MemoryManager*>(&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(pBlock - GetAlignedBlockPrefix(pBlock)->m_ucOffset);
        }
    }

    return this;
}

struct FUN_00c6b670_helper
{
};

struct FUN_00c6b670_obj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual bool v2D();
    unsigned int unk04;
    FUN_00c6b670_helper* m_08;
    unsigned short m_0c;
};

struct FUN_00c6b670_cls : FUN_00c6b670_obj
{
    void UpdateState(int a1);
};

struct FUN_00c6b730_target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(intptr_t a1);
};

struct FUN_00c6b730_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00c6b730_target* m_pFlagTarget;
    void DispatchToTarget(intptr_t a1);
};

// If the target pointer is non-null, calls its v15 with a1, then calls Helper with a1.
// @fnv 0x00c6b730
void FUN_00c6b730_cls::DispatchToTarget(intptr_t a1)
{
    FUN_00c6b730_target* target = m_pFlagTarget;
    if (target != 0)
        target->v15(a1);
    reinterpret_cast<::MyColl *>(this)->FUN_00a81010((*(::NiStream *)(a1)));
}

struct S_00c6b760_Obj
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
    virtual bool v5c(S_00c6b760_Obj* other);
};

struct S_00c6b760_Cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_0c;
    unsigned short unk0e;
    S_00c6b760_Obj* m_10;
    bool FUN_00c6b760(S_00c6b760_Cls* other);
};

// Compares this object with another: first via FUN_00a81060, then compares m_10 (via v5c or null check) and m_0c.
// @fnv 0x00c6b760
bool S_00c6b760_Cls::FUN_00c6b760(S_00c6b760_Cls* other)
{
    bool r = reinterpret_cast<::T_00a81060 *>(this)->FUN_00a81060((::NiObject *)(other));
    if (r)
    {
        S_00c6b760_Obj* p = m_10;
        if (p != 0)
        {
            S_00c6b760_Obj* a = other->m_10;
            r = p->v5c(a);
        }
        else
        {
            r = other->m_10 == 0;
        }
        r = r & (other->m_0c == m_0c);
    }
    return r;
}

// candidate for FUN_00c6b7b0
extern "C" void* FUN_00a5b690(void* p);

class FnvProbeObj
{
  public:
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
    virtual void* v39(FnvProbeObj** out);
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    int m_i80;
    float m_f84;
};

class FnvHolder_cls
{
  public:
    FnvProbeObj* m_p;
    FnvHolder_cls(void* p)
    {
        m_p = (FnvProbeObj*)p;
    }
    ~FnvHolder_cls()
    {
        if ((char*)m_p != DAT_0109b220)
        {
            InterlockedDecrement(&GetGlobalStringHeader(m_p)->m_lRefCount);
        }
    }
};

// If a is non-null, resolves a target object from b (or falls back to a) and returns whether its m_f84 is greater than zero.
// @fnv 0x00c6b7b0
bool FUN_00c6b7b0(FnvProbeObj* pObj, void* b)
{
    bool result = false;
    if (pObj)
    {
        FnvProbeObj* obj = pObj;
        FnvProbeObj* target = 0;
        if (b)
        {
            FnvHolder_cls h(FUN_00a5b690(b));
            target = (FnvProbeObj*)obj->v39(&h.m_p);
        }
        if (!target)
            target = obj;
        result = target->m_f84 > 0.0f;
    }
    return result;
}

namespace fnv_00c6b860 {
void* __cdecl FUN_00a5b690(unsigned int value);
class NiFixedString
{
  public:
    void* m_data;
    NiFixedString(unsigned int value) : m_data(FUN_00a5b690(value))
    {}
    ~NiFixedString()
    {
        if (m_data != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedDecrement(&GetGlobalStringHeader(m_data)->m_lRefCount);
    }
};
struct FUN_00c6b860_Object
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
    virtual FUN_00c6b860_Object* Find(NiFixedString*);
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
    float unk88;
};
// @fnv 0x00c6b860
bool __cdecl FUN_00c6b860(FUN_00c6b860_Object* object, unsigned int key)
{
    bool result = false;
    if (object)
    {
        FUN_00c6b860_Object* selected = 0;
        if (key)
        {
            NiFixedString name(key);
            selected = object->Find(&name);
        }
        if (!selected)
            selected = object;
        result = selected->unk88 > 0.0f;
    }
    return result;
}
}  // namespace fnv_00c6b860


// @fnv 0x00c6b940
void* __cdecl FUN_00c6b940()
{
    return &(*reinterpret_cast<int *>(&::g_01267b70));
}

struct CloneProcess;
class NiInterpolator
{
  public:
    virtual void v0();
    virtual void DeleteThis();
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
    virtual NiInterpolator* Clone(CloneProcess*);
    volatile long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
struct MapProxy
{
};
struct CloneProcess
{
    MapProxy* map;
};
struct OwnerProxy
{
    int unk00, unk04, unk08;
    unsigned short unk0c, unk0e;
    NiInterpolator* object;
    void FUN_00c6ba30(OwnerProxy*, CloneProcess*);
};
// @fnv 0x00c6ba30
void OwnerProxy::FUN_00c6ba30(OwnerProxy* dest, CloneProcess* process)
{
    ::FUN_00aa1000();
    dest->unk0c = unk0c;
    NiPointer<NiInterpolator> source = object;
    if (source)
    {
        NiPointer<NiInterpolator> clone;
        NiInterpolator* result;
        if (reinterpret_cast<::A54440Hash *>((process->map))->FUN_00a53c30((::A54440Manager *)(::NiInterpolator *)(source), (::A54440Manager **)&(result)))
            clone = result;
        else
            clone = source->Clone(process);
        reinterpret_cast<::FUN_00c6b980_cls *>((dest))->FUN_00c6b980((::World_c6b *)(::NiInterpolator *)(clone));
        clone = 0;
        source = 0;
    }
}

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    NiTransform operator*(const NiTransform& xform) const;
public:
    void CalculateInverse(::NiTransform &);
};

bool __cdecl FUN_00c6b5f0(NiPoint3 const* a, NiPoint3 const* b, float c);

struct NiNodeStub;
struct NiAVObjectStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiNodeStub* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
};
struct NiNodeStub : NiAVObjectStub
{
};

struct bhkNiCollisionObjectStub;
typedef void(__cdecl* TransformCallback)(bhkNiCollisionObjectStub*, int);
extern bool DAT_01267b6c;

struct bhkNiCollisionObjectStub
{
    int unk00;
    int unk04;
    NiAVObjectStub* m_pPointer;
    unsigned short m_ucFlags;
    bool GetFlag(unsigned int ucBit) const
    {
        return (m_ucFlags >> ucBit) & 1;
    }
    void UpdateWorldTransform(const NiTransform& kWorld);
};

// @fnv 0x00c6bbb0
void bhkNiCollisionObjectStub::UpdateWorldTransform(const NiTransform& kWorld)
{
    NiAVObjectStub* pkObject = m_pPointer;
    if (!pkObject)
        return;

    NiNodeStub* pkParent = pkObject->m_pParentNode;
    if ((unsigned char)(m_ucFlags >> 3) & 1)
    {
        NiTransform kLocal;
        if (pkParent)
        {
            reinterpret_cast<::NiTransform *>((void *)&(pkParent->m_kWorldSpaceTransform))->CalculateInverse(kLocal);
            kLocal = kLocal * kWorld;
        }
        else
        {
            kLocal = kWorld;
        }
        pkObject->m_kLocalTransform.m_kOrientation = kLocal.m_kOrientation;
        pkObject->m_kLocalTransform.m_kTranslation = kLocal.m_kTranslation;
    }

    int iResult = 0;
    if (DAT_01267b6c)
    {
        iResult = 3;
    }
    else
    {
        if (!FUN_00c6b5f0((const NiPoint3*)&pkObject->m_kWorldSpaceTransform.m_kOrientation, (const NiPoint3*)&kWorld.m_kOrientation,
                          0.001f))
            iResult = 2;
        if (!::AreVectorsEqual((const float *)&(pkObject->m_kWorldSpaceTransform.m_kTranslation), (const float *)&(kWorld.m_kTranslation), 0.01f))
            iResult |= 1;
        if (!iResult)
            return;
    }

    pkObject->m_kWorldSpaceTransform.m_kOrientation = kWorld.m_kOrientation;
    pkObject->m_kWorldSpaceTransform.m_kTranslation = kWorld.m_kTranslation;
    if ((*reinterpret_cast<void (**)(bhkNiCollisionObjectStub *, int)>(&::DAT_01267b68)) && (unsigned char)(m_ucFlags >> 2) & 1)
        (*reinterpret_cast<void (**)(bhkNiCollisionObjectStub *, int)>(&::DAT_01267b68))(this, iResult);
}

struct TreeFlagged_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct TreeHost_cls
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
    virtual TreeFlagged_cls* v14();
};

struct TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual TreeNode_cls* v03();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TreeHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

// @fnv 0x00c6bd00
void FUN_00c6bd00(TreeNode_cls* node, bool recurse)
{
    if (node == 0)
    {
        return;
    }

    TreeHost_cls* host = node->m_1c;
    if (host != 0)
    {
        TreeFlagged_cls* flagged = host->v14();
        if (flagged != 0)
        {
            flagged->m_0c |= 0x40;
        }
    }

    if (recurse)
    {
        TreeNode_cls* child = node->v03();
        if (child != 0)
        {
            unsigned int n = child->m_a6;
            if (n != 0)
            {
                do
                {
                    --n;
                    TreeNode_cls* item = child->m_a0[n];
                    FUN_00c6bd00(item, true);
                } while (n != 0);
            }
        }
    }
}

class C6C0E0RefObject
{
  public:
};

struct C6C0E0WorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C6C0E0RefObject* m_pPointer;
};

class C6C0E0CollisionObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual C6C0E0WorldObject* GetWorldObject();
};

class C6C0E0AVObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C6C0E0CollisionObject* m_spCollisionObject;
};

// If the object has a collision object with a world object and ref object, forwards the flag to the ref object's SetFlag.
// @fnv 0x00c6c0e0
void SetCollisionRefFlag(C6C0E0AVObject* pkObject, int aiFlag)
{
    C6C0E0CollisionObject* pkCollision = pkObject->m_spCollisionObject;
    if (pkCollision)
    {
        C6C0E0WorldObject* pkWorldObject = pkCollision->GetWorldObject();
        C6C0E0RefObject* pkRefObject;
        if (pkWorldObject && (pkRefObject = pkWorldObject->m_pPointer) != 0)
            reinterpret_cast<::C *>((pkRefObject))->FUN_00c85d20(aiFlag);
    }
}

struct C6C210RTTI;

class C6C210StringPtr
{
  public:
    void operator=(const char* pcString);
};

struct C6C210HavokEntity
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
    C6C210StringPtr m_name;
};

class C6C210RefObject
{
  public:
    C6C210RefObject* DynamicCast(const C6C210RTTI* pkRTTI);
};

class C6C210Entity : public C6C210RefObject
{
  public:
    int unk00;
    int unk04;
    C6C210HavokEntity* m_pkHavokEntity;
};

struct C6C210WorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C6C210RefObject* m_pPointer;
};

class C6C210CollisionObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual C6C210WorldObject* GetWorldObject();
};

class C6C210Node;

class C6C210AVObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual C6C210Node* IsSceneNode();

    int unk04;
    const char* m_pcName;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C6C210CollisionObject* m_spCollisionObject;
};

class C6C210Node : public C6C210AVObject
{
  public:
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
    C6C210AVObject** m_ppkChildren;
    unsigned short unkA4;
    unsigned short m_usChildCount;
};

// @fnv 0x00c6c210
void PropagateNameToHavokEntity(C6C210AVObject* pkObject)
{
    if (!pkObject)
        return;

    C6C210CollisionObject* pkCollision = pkObject->m_spCollisionObject;
    if (pkCollision)
    {
        C6C210WorldObject* pkWorldObject = pkCollision->GetWorldObject();
        C6C210RefObject* pkRefObject;
        if (pkWorldObject && (pkRefObject = pkWorldObject->m_pPointer) != 0)
        {
            C6C210Entity* pkEntity = (C6C210Entity*)pkRefObject->DynamicCast(&(*reinterpret_cast<const ::C6C210RTTI *>(&::g_012681c0)));
            if (pkEntity)
                reinterpret_cast<::SStringPtr *>((void *)&(const ::C6C210StringPtr &)(pkEntity->m_pkHavokEntity->m_name))->FUN_00cb0c10(pkObject->m_pcName);
        }
    }

    C6C210Node* pkNode = pkObject->IsSceneNode();
    if (pkNode)
    {
        int iCount = pkNode->m_usChildCount;
        for (int i = 0; i < iCount; i++)
            PropagateNameToHavokEntity(pkNode->m_ppkChildren[i]);
    }
}

class C6C290Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void Detach();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            vfunc01();
    }
};


class C6C290Base
{
  public:
    virtual ~C6C290Base();
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00c6c290 : public C6C290Base
{
  public:
    NiPointer<C6C290Object> m_pReferencedObject;

    virtual ~FUN_00c6c290();
};
// Calls the base cleanup, then frees this object with operator delete when bit 0 of a is set, and returns this.
// @fnv 0x00c6c410
void* FUN_00c6c410_cls::FUN_00c6c410(unsigned int auiFlags)
{
    reinterpret_cast<::FUN_00c6c290 *>(this)->FUN_00c6c290::~FUN_00c6c290();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

// Decrements g_iC6C290Count, detaches the held C6C290Object if present, then calls FUN_00c6b980(0).
// @fnv 0x00c6c290
FUN_00c6c290::~FUN_00c6c290()
{
    ::DAT_01267b60--;
    if (m_pReferencedObject)
        m_pReferencedObject->Detach();
    reinterpret_cast<::FUN_00c6b980_cls *>(this)->FUN_00c6b980((::World_c6b *)(0));
}

class BC6C330BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BC6C330BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BC6C330Stream
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
    unsigned int m_uiFileVersion;
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
    BC6C330BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void BC6C330BinaryStreamLoad(BC6C330BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BC6C330LoadBinary(BC6C330Stream& kStream, T& value)
{
    BC6C330BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

class BC6C330CollisionObject
{
  public:
    virtual void LoadBinary(BC6C330Stream& kStream);
};

class BC6C330HavokCollision : public BC6C330CollisionObject
{
  public:
    virtual void LoadBinary(BC6C330Stream& kStream);
    void FUN_00c6c330(BC6C330Stream& kStream);

    int unk04;
    int unk08;
    unsigned short m_usFlags;
};

// @fnv 0x00c6c330
void BC6C330HavokCollision::FUN_00c6c330(BC6C330Stream& kStream)
{
    reinterpret_cast<::NiCollisionObject *>(this)->LoadBinary((::NiStream &)(kStream));
    BC6C330LoadBinary(kStream, m_usFlags);
    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
}

extern int DAT_010c446c;

struct FUN_00c6c830_cls
{
    void* m_vptr00;

    void FUN_00c6c830();
};

// @fnv 0x00c6c830
void FUN_00c6c830_cls::FUN_00c6c830()
{
    m_vptr00 = &DAT_010c446c;
}

struct S_00c6c840_Param
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char unk34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    unsigned char unk3b;
    unsigned char unk3c;
    unsigned char unk3d;
    unsigned char unk3e;
    unsigned char unk3f;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    void* m_pObject_48;
};

struct S_00c6c840_Value
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    int m_value_1c;
};

struct S_00c6c840_Base
{
    void FUN_00926980(void* a);
};

struct S_00c6c840_class
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char unk34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    unsigned char unk38;
    unsigned char unk39;
    unsigned char unk3a;
    unsigned char unk3b;
    unsigned char unk3c;
    unsigned char unk3d;
    unsigned char unk3e;
    unsigned char unk3f;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    unsigned char unk48;
    unsigned char unk49;
    unsigned char unk4a;
    unsigned char unk4b;
    unsigned char unk4c;
    unsigned char unk4d;
    unsigned char unk4e;
    unsigned char unk4f;
    unsigned char unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
    unsigned char unk54;
    unsigned char unk55;
    unsigned char unk56;
    unsigned char unk57;
    unsigned char unk58;
    unsigned char unk59;
    unsigned char unk5a;
    unsigned char unk5b;
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char unk5e;
    unsigned char unk5f;
    unsigned char unk60;
    unsigned char unk61;
    unsigned char unk62;
    unsigned char unk63;
    unsigned char unk64;
    unsigned char unk65;
    unsigned char unk66;
    unsigned char unk67;
    unsigned char unk68;
    unsigned char unk69;
    unsigned char unk6a;
    unsigned char unk6b;
    int unk6c;

    void FUN_00c6c840(int a, S_00c6c840_Param* b);
};

struct S_00c6c840_Pad
{
    unsigned char pad000;
    unsigned char pad001;
    unsigned char pad002;
    unsigned char pad003;
    unsigned char pad004;
    unsigned char pad005;
    unsigned char pad006;
    unsigned char pad007;
    unsigned char pad008;
    unsigned char pad009;
    unsigned char pad00a;
    unsigned char pad00b;
    unsigned char pad00c;
    unsigned char pad00d;
    unsigned char pad00e;
    unsigned char pad00f;
    unsigned char pad010;
    unsigned char pad011;
    unsigned char pad012;
    unsigned char pad013;
    unsigned char pad014;
    unsigned char pad015;
    unsigned char pad016;
    unsigned char pad017;
    unsigned char pad018;
    unsigned char pad019;
    unsigned char pad01a;
    unsigned char pad01b;
    unsigned char pad01c;
    unsigned char pad01d;
    unsigned char pad01e;
    unsigned char pad01f;
    unsigned char pad020;
    unsigned char pad021;
    unsigned char pad022;
    unsigned char pad023;
    unsigned char pad024;
    unsigned char pad025;
    unsigned char pad026;
    unsigned char pad027;
    unsigned char pad028;
    unsigned char pad029;
    unsigned char pad02a;
    unsigned char pad02b;
    unsigned char pad02c;
    unsigned char pad02d;
    unsigned char pad02e;
    unsigned char pad02f;
    unsigned char pad030;
    unsigned char pad031;
    unsigned char pad032;
    unsigned char pad033;
    unsigned char pad034;
    unsigned char pad035;
    unsigned char pad036;
    unsigned char pad037;
    unsigned char pad038;
    unsigned char pad039;
    unsigned char pad03a;
    unsigned char pad03b;
    unsigned char pad03c;
    unsigned char pad03d;
    unsigned char pad03e;
    unsigned char pad03f;
    unsigned char pad040;
    unsigned char pad041;
    unsigned char pad042;
    unsigned char pad043;
    unsigned char pad044;
    unsigned char pad045;
    unsigned char pad046;
    unsigned char pad047;
    unsigned char pad048;
    unsigned char pad049;
    unsigned char pad04a;
    unsigned char pad04b;
    unsigned char pad04c;
    unsigned char pad04d;
    unsigned char pad04e;
    unsigned char pad04f;
    unsigned char pad050;
    unsigned char pad051;
    unsigned char pad052;
    unsigned char pad053;
    unsigned char pad054;
    unsigned char pad055;
    unsigned char pad056;
    unsigned char pad057;
    unsigned char pad058;
    unsigned char pad059;
    unsigned char pad05a;
    unsigned char pad05b;
    unsigned char pad05c;
    unsigned char pad05d;
    unsigned char pad05e;
    unsigned char pad05f;
    unsigned char pad060;
    unsigned char pad061;
    unsigned char pad062;
    unsigned char pad063;
    unsigned char pad064;
    unsigned char pad065;
    unsigned char pad066;
    unsigned char pad067;
    unsigned char pad068;
    unsigned char pad069;
    unsigned char pad06a;
    unsigned char pad06b;
    unsigned char pad06c;
    unsigned char pad06d;
    unsigned char pad06e;
    unsigned char pad06f;
    unsigned char pad070;
    unsigned char pad071;
    unsigned char pad072;
    unsigned char pad073;
    unsigned char pad074;
    unsigned char pad075;
    unsigned char pad076;
    unsigned char pad077;
    unsigned char pad078;
    unsigned char pad079;
    unsigned char pad07a;
    unsigned char pad07b;
    unsigned char pad07c;
    unsigned char pad07d;
    unsigned char pad07e;
    unsigned char pad07f;
    unsigned char pad080;
    unsigned char pad081;
    unsigned char pad082;
    unsigned char pad083;
    unsigned char pad084;
    unsigned char pad085;
    unsigned char pad086;
    unsigned char pad087;
    unsigned char pad088;
    unsigned char pad089;
    unsigned char pad08a;
    unsigned char pad08b;
    unsigned char pad08c;
    unsigned char pad08d;
    unsigned char pad08e;
    unsigned char pad08f;
    unsigned char pad090;
    unsigned char pad091;
    unsigned char pad092;
    unsigned char pad093;
    unsigned char pad094;
    unsigned char pad095;
    unsigned char pad096;
    unsigned char pad097;
    unsigned char pad098;
    unsigned char pad099;
    unsigned char pad09a;
    unsigned char pad09b;
    unsigned char pad09c;
    unsigned char pad09d;
    unsigned char pad09e;
    unsigned char pad09f;
    unsigned char pad0a0;
    unsigned char pad0a1;
    unsigned char pad0a2;
    unsigned char pad0a3;
    unsigned char pad0a4;
    unsigned char pad0a5;
    unsigned char pad0a6;
    unsigned char pad0a7;
    unsigned char pad0a8;
    unsigned char pad0a9;
    unsigned char pad0aa;
    unsigned char pad0ab;
    unsigned char pad0ac;
    unsigned char pad0ad;
    unsigned char pad0ae;
    unsigned char pad0af;
    unsigned char pad0b0;
    unsigned char pad0b1;
    unsigned char pad0b2;
    unsigned char pad0b3;
    unsigned char pad0b4;
    unsigned char pad0b5;
    unsigned char pad0b6;
    unsigned char pad0b7;
    unsigned char pad0b8;
    unsigned char pad0b9;
    unsigned char pad0ba;
    unsigned char pad0bb;
    unsigned char pad0bc;
    unsigned char pad0bd;
    unsigned char pad0be;
    unsigned char pad0bf;
    unsigned char pad0c0;
    unsigned char pad0c1;
    unsigned char pad0c2;
    unsigned char pad0c3;
    unsigned char pad0c4;
    unsigned char pad0c5;
    unsigned char pad0c6;
    unsigned char pad0c7;
    unsigned char pad0c8;
    unsigned char pad0c9;
    unsigned char pad0ca;
    unsigned char pad0cb;
    unsigned char pad0cc;
    unsigned char pad0cd;
    unsigned char pad0ce;
    unsigned char pad0cf;
    unsigned char pad0d0;
    unsigned char pad0d1;
    unsigned char pad0d2;
    unsigned char pad0d3;
    unsigned char pad0d4;
    unsigned char pad0d5;
    unsigned char pad0d6;
    unsigned char pad0d7;
    unsigned char pad0d8;
    unsigned char pad0d9;
    unsigned char pad0da;
    unsigned char pad0db;
    unsigned char pad0dc;
    unsigned char pad0dd;
    unsigned char pad0de;
    unsigned char pad0df;
    unsigned char pad0e0;
    unsigned char pad0e1;
    unsigned char pad0e2;
    unsigned char pad0e3;
    unsigned char pad0e4;
    unsigned char pad0e5;
    unsigned char pad0e6;
    unsigned char pad0e7;
    unsigned char pad0e8;
    unsigned char pad0e9;
    unsigned char pad0ea;
    unsigned char pad0eb;
    unsigned char pad0ec;
    unsigned char pad0ed;
    unsigned char pad0ee;
    unsigned char pad0ef;
    unsigned char pad0f0;
    unsigned char pad0f1;
    unsigned char pad0f2;
    unsigned char pad0f3;
    unsigned char pad0f4;
    unsigned char pad0f5;
    unsigned char pad0f6;
    unsigned char pad0f7;
    unsigned char pad0f8;
    unsigned char pad0f9;
    unsigned char pad0fa;
    unsigned char pad0fb;
    unsigned char pad0fc;
    unsigned char pad0fd;
    unsigned char pad0fe;
    unsigned char pad0ff;
    unsigned char pad100;
    unsigned char pad101;
    unsigned char pad102;
    unsigned char pad103;
    unsigned char pad104;
    unsigned char pad105;
    unsigned char pad106;
    unsigned char pad107;
    unsigned char pad108;
    unsigned char pad109;
    unsigned char pad10a;
    unsigned char pad10b;
    unsigned char pad10c;
    unsigned char pad10d;
    unsigned char pad10e;
    unsigned char pad10f;
    unsigned char pad110;
    unsigned char pad111;
    unsigned char pad112;
    unsigned char pad113;
    unsigned char pad114;
    unsigned char pad115;
    unsigned char pad116;
    unsigned char pad117;
    unsigned char pad118;
    unsigned char pad119;
    unsigned char pad11a;
    unsigned char pad11b;
    unsigned char pad11c;
    unsigned char pad11d;
    unsigned char pad11e;
    unsigned char pad11f;
    unsigned char pad120;
    unsigned char pad121;
    unsigned char pad122;
    unsigned char pad123;
    unsigned char pad124;
    unsigned char pad125;
    unsigned char pad126;
    unsigned char pad127;
    unsigned char pad128;
    unsigned char pad129;
    unsigned char pad12a;
    unsigned char pad12b;
    unsigned char pad12c;
    unsigned char pad12d;
    unsigned char pad12e;
    unsigned char pad12f;
    unsigned char pad130;
    unsigned char pad131;
    unsigned char pad132;
    unsigned char pad133;
    unsigned char pad134;
    unsigned char pad135;
    unsigned char pad136;
    unsigned char pad137;
    unsigned char pad138;
    unsigned char pad139;
    unsigned char pad13a;
    unsigned char pad13b;
    unsigned char pad13c;
    unsigned char pad13d;
    unsigned char pad13e;
    unsigned char pad13f;
    unsigned char pad140;
    unsigned char pad141;
    unsigned char pad142;
    unsigned char pad143;
    unsigned char pad144;
    unsigned char pad145;
    unsigned char pad146;
    unsigned char pad147;
    unsigned char pad148;
    unsigned char pad149;
    unsigned char pad14a;
    unsigned char pad14b;
    unsigned char pad14c;
    unsigned char pad14d;
    unsigned char pad14e;
    unsigned char pad14f;
    unsigned char pad150;
    unsigned char pad151;
    unsigned char pad152;
    unsigned char pad153;
    unsigned char pad154;
    unsigned char pad155;
    unsigned char pad156;
    unsigned char pad157;
    unsigned char pad158;
    unsigned char pad159;
    unsigned char pad15a;
    unsigned char pad15b;
    unsigned char pad15c;
    unsigned char pad15d;
    unsigned char pad15e;
    unsigned char pad15f;
    unsigned char pad160;
    unsigned char pad161;
    unsigned char pad162;
    unsigned char pad163;
    unsigned char pad164;
    unsigned char pad165;
    unsigned char pad166;
    unsigned char pad167;
    unsigned char pad168;
    unsigned char pad169;
    unsigned char pad16a;
    unsigned char pad16b;
    unsigned char pad16c;
    unsigned char pad16d;
    unsigned char pad16e;
    unsigned char pad16f;
    unsigned char pad170;
    unsigned char pad171;
    unsigned char pad172;
    unsigned char pad173;
    unsigned char pad174;
    unsigned char pad175;
    unsigned char pad176;
    unsigned char pad177;
    unsigned char pad178;
    unsigned char pad179;
    unsigned char pad17a;
    unsigned char pad17b;
    unsigned char pad17c;
    unsigned char pad17d;
    unsigned char pad17e;
    unsigned char pad17f;
    unsigned char pad180;
    unsigned char pad181;
    unsigned char pad182;
    unsigned char pad183;
    unsigned char pad184;
    unsigned char pad185;
    unsigned char pad186;
    unsigned char pad187;
    unsigned char pad188;
    unsigned char pad189;
    unsigned char pad18a;
    unsigned char pad18b;
    unsigned char pad18c;
    unsigned char pad18d;
    unsigned char pad18e;
    unsigned char pad18f;
    unsigned char pad190;
    unsigned char pad191;
    unsigned char pad192;
    unsigned char pad193;
    unsigned char pad194;
    unsigned char pad195;
    unsigned char pad196;
    unsigned char pad197;
    unsigned char pad198;
    unsigned char pad199;
    unsigned char pad19a;
    unsigned char pad19b;
    unsigned char pad19c;
    unsigned char pad19d;
    unsigned char pad19e;
    unsigned char pad19f;
    unsigned char pad1a0;
    unsigned char pad1a1;
    unsigned char pad1a2;
    unsigned char pad1a3;
    unsigned char pad1a4;
    unsigned char pad1a5;
    unsigned char pad1a6;
    unsigned char pad1a7;
    unsigned char pad1a8;
    unsigned char pad1a9;
    unsigned char pad1aa;
    unsigned char pad1ab;
    unsigned char pad1ac;
    unsigned char pad1ad;
    unsigned char pad1ae;
    unsigned char pad1af;
    unsigned char pad1b0;
    unsigned char pad1b1;
    unsigned char pad1b2;
    unsigned char pad1b3;
    unsigned char pad1b4;
    unsigned char pad1b5;
    unsigned char pad1b6;
    unsigned char pad1b7;
    unsigned char pad1b8;
    unsigned char pad1b9;
    unsigned char pad1ba;
    unsigned char pad1bb;
    unsigned char pad1bc;
    unsigned char pad1bd;
    unsigned char pad1be;
    unsigned char pad1bf;
    unsigned char pad1c0;
    unsigned char pad1c1;
    unsigned char pad1c2;
    unsigned char pad1c3;
    unsigned char pad1c4;
    unsigned char pad1c5;
    unsigned char pad1c6;
    unsigned char pad1c7;
    unsigned char pad1c8;
    unsigned char pad1c9;
    unsigned char pad1ca;
    unsigned char pad1cb;
    unsigned char pad1cc;
    unsigned char pad1cd;
    unsigned char pad1ce;
    unsigned char pad1cf;
    unsigned char pad1d0;
    unsigned char pad1d1;
    unsigned char pad1d2;
    unsigned char pad1d3;
    unsigned char pad1d4;
    unsigned char pad1d5;
    unsigned char pad1d6;
    unsigned char pad1d7;
    unsigned char pad1d8;
    unsigned char pad1d9;
    unsigned char pad1da;
    unsigned char pad1db;
    unsigned char pad1dc;
    unsigned char pad1dd;
    unsigned char pad1de;
    unsigned char pad1df;
    unsigned char pad1e0;
    unsigned char pad1e1;
    unsigned char pad1e2;
    unsigned char pad1e3;
    unsigned char pad1e4;
    unsigned char pad1e5;
    unsigned char pad1e6;
    unsigned char pad1e7;
    unsigned char pad1e8;
    unsigned char pad1e9;
    unsigned char pad1ea;
    unsigned char pad1eb;
    unsigned char pad1ec;
    unsigned char pad1ed;
    unsigned char pad1ee;
    unsigned char pad1ef;
    unsigned char pad1f0;
    unsigned char pad1f1;
    unsigned char pad1f2;
    unsigned char pad1f3;
    unsigned char pad1f4;
    unsigned char pad1f5;
    unsigned char pad1f6;
    unsigned char pad1f7;
    unsigned char pad1f8;
    unsigned char pad1f9;
    unsigned char pad1fa;
    unsigned char pad1fb;
    unsigned char pad1fc;
    unsigned char pad1fd;
    unsigned char pad1fe;
    unsigned char pad1ff;
    unsigned char pad200;
    unsigned char pad201;
    unsigned char pad202;
    unsigned char pad203;
    unsigned char pad204;
    unsigned char pad205;
    unsigned char pad206;
    unsigned char pad207;
    unsigned char pad208;
    unsigned char pad209;
    unsigned char pad20a;
    unsigned char pad20b;
    unsigned char pad20c;
    unsigned char pad20d;
    unsigned char pad20e;
    unsigned char pad20f;
    unsigned char pad210;
    unsigned char pad211;
    unsigned char pad212;
    unsigned char pad213;
    unsigned char pad214;
    unsigned char pad215;
    unsigned char pad216;
    unsigned char pad217;
    unsigned char pad218;
    unsigned char pad219;
    unsigned char pad21a;
    unsigned char pad21b;
    unsigned char pad21c;
    unsigned char pad21d;
    unsigned char pad21e;
    unsigned char pad21f;
    unsigned char pad220;
    unsigned char pad221;
    unsigned char pad222;
    unsigned char pad223;
    unsigned char pad224;
    unsigned char pad225;
    unsigned char pad226;
    unsigned char pad227;
    unsigned char pad228;
    unsigned char pad229;
    unsigned char pad22a;
    unsigned char pad22b;
    unsigned char pad22c;
    unsigned char pad22d;
    unsigned char pad22e;
    unsigned char pad22f;
    unsigned char pad230;
    unsigned char pad231;
    unsigned char pad232;
    unsigned char pad233;
    unsigned char pad234;
    unsigned char pad235;
    unsigned char pad236;
    unsigned char pad237;
    unsigned char pad238;
    unsigned char pad239;
    unsigned char pad23a;
    unsigned char pad23b;
    unsigned char pad23c;
    unsigned char pad23d;
    unsigned char pad23e;
    unsigned char pad23f;
    unsigned char pad240;
    unsigned char pad241;
    unsigned char pad242;
    unsigned char pad243;
    unsigned char pad244;
    unsigned char pad245;
    unsigned char pad246;
    unsigned char pad247;
    unsigned char pad248;
    unsigned char pad249;
    unsigned char pad24a;
    unsigned char pad24b;
    unsigned char pad24c;
    unsigned char pad24d;
    unsigned char pad24e;
    unsigned char pad24f;
    unsigned char pad250;
    unsigned char pad251;
    unsigned char pad252;
    unsigned char pad253;
    unsigned char pad254;
    unsigned char pad255;
    unsigned char pad256;
    unsigned char pad257;
    unsigned char pad258;
    unsigned char pad259;
    unsigned char pad25a;
    unsigned char pad25b;
    unsigned char pad25c;
    unsigned char pad25d;
    unsigned char pad25e;
    unsigned char pad25f;
    unsigned char pad260;
    unsigned char pad261;
    unsigned char pad262;
    unsigned char pad263;
    unsigned char pad264;
    unsigned char pad265;
    unsigned char pad266;
    unsigned char pad267;
    unsigned char pad268;
    unsigned char pad269;
    unsigned char pad26a;
    unsigned char pad26b;
    unsigned char pad26c;
    unsigned char pad26d;
    unsigned char pad26e;
    unsigned char pad26f;
    unsigned char pad270;
    unsigned char pad271;
    unsigned char pad272;
    unsigned char pad273;
    unsigned char pad274;
    unsigned char pad275;
    unsigned char pad276;
    unsigned char pad277;
    unsigned char pad278;
    unsigned char pad279;
    unsigned char pad27a;
    unsigned char pad27b;
    unsigned char pad27c;
    unsigned char pad27d;
    unsigned char pad27e;
    unsigned char pad27f;
    unsigned char pad280;
    unsigned char pad281;
    unsigned char pad282;
    unsigned char pad283;
    unsigned char pad284;
    unsigned char pad285;
    unsigned char pad286;
    unsigned char pad287;
    unsigned char pad288;
    unsigned char pad289;
    unsigned char pad28a;
    unsigned char pad28b;
    unsigned char pad28c;
    unsigned char pad28d;
    unsigned char pad28e;
    unsigned char pad28f;
    unsigned char pad290;
    unsigned char pad291;
    unsigned char pad292;
    unsigned char pad293;
    unsigned char pad294;
    unsigned char pad295;
    unsigned char pad296;
    unsigned char pad297;
    unsigned char pad298;
    unsigned char pad299;
    unsigned char pad29a;
    unsigned char pad29b;
    unsigned char pad29c;
    unsigned char pad29d;
    unsigned char pad29e;
    unsigned char pad29f;
    unsigned char pad2a0;
    unsigned char pad2a1;
    unsigned char pad2a2;
    unsigned char pad2a3;
    unsigned char pad2a4;
    unsigned char pad2a5;
    unsigned char pad2a6;
    unsigned char pad2a7;
    unsigned char pad2a8;
    unsigned char pad2a9;
    unsigned char pad2aa;
    unsigned char pad2ab;
    unsigned char pad2ac;
    unsigned char pad2ad;
    unsigned char pad2ae;
    unsigned char pad2af;
    unsigned char pad2b0;
    unsigned char pad2b1;
    unsigned char pad2b2;
    unsigned char pad2b3;
    unsigned char pad2b4;
    unsigned char pad2b5;
    unsigned char pad2b6;
    unsigned char pad2b7;
    unsigned char pad2b8;
    unsigned char pad2b9;
    unsigned char pad2ba;
    unsigned char pad2bb;
    unsigned char pad2bc;
    unsigned char pad2bd;
    unsigned char pad2be;
    unsigned char pad2bf;
    unsigned char pad2c0;
    unsigned char pad2c1;
    unsigned char pad2c2;
    unsigned char pad2c3;
    unsigned char pad2c4;
    unsigned char pad2c5;
    unsigned char pad2c6;
    unsigned char pad2c7;
    unsigned char pad2c8;
    unsigned char pad2c9;
    unsigned char pad2ca;
    unsigned char pad2cb;
    unsigned char pad2cc;
    unsigned char pad2cd;
    unsigned char pad2ce;
    unsigned char pad2cf;
    unsigned char pad2d0;
    unsigned char pad2d1;
    unsigned char pad2d2;
    unsigned char pad2d3;
    unsigned char pad2d4;
    unsigned char pad2d5;
    unsigned char pad2d6;
    unsigned char pad2d7;
    unsigned char pad2d8;
    unsigned char pad2d9;
    unsigned char pad2da;
    unsigned char pad2db;
    unsigned char pad2dc;
    unsigned char pad2dd;
    unsigned char pad2de;
    unsigned char pad2df;
    unsigned char pad2e0;
    unsigned char pad2e1;
    unsigned char pad2e2;
    unsigned char pad2e3;
    unsigned char pad2e4;
    unsigned char pad2e5;
    unsigned char pad2e6;
    unsigned char pad2e7;
    unsigned char pad2e8;
    unsigned char pad2e9;
    unsigned char pad2ea;
    unsigned char pad2eb;
    unsigned char pad2ec;
    unsigned char pad2ed;
    unsigned char pad2ee;
    unsigned char pad2ef;
    unsigned char pad2f0;
    unsigned char pad2f1;
    unsigned char pad2f2;
    unsigned char pad2f3;
    unsigned char pad2f4;
    unsigned char pad2f5;
    unsigned char pad2f6;
    unsigned char pad2f7;
    unsigned char pad2f8;
    unsigned char pad2f9;
    unsigned char pad2fa;
    unsigned char pad2fb;
    unsigned char pad2fc;
    unsigned char pad2fd;
    unsigned char pad2fe;
    unsigned char pad2ff;
    unsigned char pad300;
    unsigned char pad301;
    unsigned char pad302;
    unsigned char pad303;
    unsigned char pad304;
    unsigned char pad305;
    unsigned char pad306;
    unsigned char pad307;
    unsigned char pad308;
    unsigned char pad309;
    unsigned char pad30a;
    unsigned char pad30b;
    unsigned char pad30c;
    unsigned char pad30d;
    unsigned char pad30e;
    unsigned char pad30f;
    unsigned char pad310;
    unsigned char pad311;
    unsigned char pad312;
    unsigned char pad313;
    unsigned char pad314;
    unsigned char pad315;
    unsigned char pad316;
    unsigned char pad317;
    unsigned char pad318;
    unsigned char pad319;
    unsigned char pad31a;
    unsigned char pad31b;
    unsigned char pad31c;
    unsigned char pad31d;
    unsigned char pad31e;
    unsigned char pad31f;
    unsigned char pad320;
    unsigned char pad321;
    unsigned char pad322;
    unsigned char pad323;
    unsigned char pad324;
    unsigned char pad325;
    unsigned char pad326;
    unsigned char pad327;
    unsigned char pad328;
    unsigned char pad329;
    unsigned char pad32a;
    unsigned char pad32b;
    unsigned char pad32c;
    unsigned char pad32d;
    unsigned char pad32e;
    unsigned char pad32f;
    unsigned char pad330;
    unsigned char pad331;
    unsigned char pad332;
    unsigned char pad333;
    unsigned char pad334;
    unsigned char pad335;
    unsigned char pad336;
    unsigned char pad337;
    unsigned char pad338;
    unsigned char pad339;
    unsigned char pad33a;
    unsigned char pad33b;
    unsigned char pad33c;
    unsigned char pad33d;
    unsigned char pad33e;
    unsigned char pad33f;
    unsigned char pad340;
    unsigned char pad341;
    unsigned char pad342;
    unsigned char pad343;
    unsigned char pad344;
    unsigned char pad345;
    unsigned char pad346;
    unsigned char pad347;
    unsigned char pad348;
    unsigned char pad349;
    unsigned char pad34a;
    unsigned char pad34b;
    unsigned char pad34c;
    unsigned char pad34d;
    unsigned char pad34e;
    unsigned char pad34f;
    unsigned char pad350;
    unsigned char pad351;
    unsigned char pad352;
    unsigned char pad353;
    unsigned char pad354;
    unsigned char pad355;
    unsigned char pad356;
    unsigned char pad357;
    unsigned char pad358;
    unsigned char pad359;
    unsigned char pad35a;
    unsigned char pad35b;
    unsigned char pad35c;
    unsigned char pad35d;
    unsigned char pad35e;
    unsigned char pad35f;
    unsigned char pad360;
    unsigned char pad361;
    unsigned char pad362;
    unsigned char pad363;
    unsigned char pad364;
    unsigned char pad365;
    unsigned char pad366;
    unsigned char pad367;
    unsigned char pad368;
    unsigned char pad369;
    unsigned char pad36a;
    unsigned char pad36b;
    unsigned char pad36c;
    unsigned char pad36d;
    unsigned char pad36e;
    unsigned char pad36f;
    unsigned char pad370;
    unsigned char pad371;
    unsigned char pad372;
    unsigned char pad373;
    unsigned char pad374;
    unsigned char pad375;
    unsigned char pad376;
    unsigned char pad377;
    unsigned char pad378;
    unsigned char pad379;
    unsigned char pad37a;
    unsigned char pad37b;
    unsigned char pad37c;
    unsigned char pad37d;
    unsigned char pad37e;
    unsigned char pad37f;
    unsigned char pad380;
    unsigned char pad381;
    unsigned char pad382;
    unsigned char pad383;
    unsigned char pad384;
    unsigned char pad385;
    unsigned char pad386;
    unsigned char pad387;
    unsigned char pad388;
    unsigned char pad389;
    unsigned char pad38a;
    unsigned char pad38b;
    unsigned char pad38c;
    unsigned char pad38d;
    unsigned char pad38e;
    unsigned char pad38f;
    unsigned char pad390;
    unsigned char pad391;
    unsigned char pad392;
    unsigned char pad393;
    unsigned char pad394;
    unsigned char pad395;
    unsigned char pad396;
    unsigned char pad397;
    unsigned char pad398;
    unsigned char pad399;
    unsigned char pad39a;
    unsigned char pad39b;
    unsigned char pad39c;
    unsigned char pad39d;
    unsigned char pad39e;
    unsigned char pad39f;
    unsigned char pad3a0;
    unsigned char pad3a1;
    unsigned char pad3a2;
    unsigned char pad3a3;
    unsigned char pad3a4;
    unsigned char pad3a5;
    unsigned char pad3a6;
    unsigned char pad3a7;
    unsigned char pad3a8;
    unsigned char pad3a9;
    unsigned char pad3aa;
    unsigned char pad3ab;
    unsigned char pad3ac;
    unsigned char pad3ad;
    unsigned char pad3ae;
    unsigned char pad3af;
    unsigned char pad3b0;
    unsigned char pad3b1;
    unsigned char pad3b2;
    unsigned char pad3b3;
    unsigned char pad3b4;
    unsigned char pad3b5;
    unsigned char pad3b6;
    unsigned char pad3b7;
    unsigned char pad3b8;
    unsigned char pad3b9;
    unsigned char pad3ba;
    unsigned char pad3bb;
    unsigned char pad3bc;
    unsigned char pad3bd;
    unsigned char pad3be;
    unsigned char pad3bf;
    unsigned char pad3c0;
    unsigned char pad3c1;
    unsigned char pad3c2;
    unsigned char pad3c3;
    unsigned char pad3c4;
    unsigned char pad3c5;
    unsigned char pad3c6;
    unsigned char pad3c7;
    unsigned char pad3c8;
    unsigned char pad3c9;
    unsigned char pad3ca;
    unsigned char pad3cb;
    unsigned char pad3cc;
    unsigned char pad3cd;
    unsigned char pad3ce;
    unsigned char pad3cf;
    unsigned char pad3d0;
    unsigned char pad3d1;
    unsigned char pad3d2;
    unsigned char pad3d3;
    unsigned char pad3d4;
    unsigned char pad3d5;
    unsigned char pad3d6;
    unsigned char pad3d7;
    unsigned char pad3d8;
    unsigned char pad3d9;
    unsigned char pad3da;
    unsigned char pad3db;
    unsigned char pad3dc;
    unsigned char pad3dd;
    unsigned char pad3de;
    unsigned char pad3df;
    unsigned char pad3e0;
    unsigned char pad3e1;
    unsigned char pad3e2;
    unsigned char pad3e3;
    unsigned char pad3e4;
    unsigned char pad3e5;
    unsigned char pad3e6;
    unsigned char pad3e7;
    unsigned char pad3e8;
    unsigned char pad3e9;
    unsigned char pad3ea;
    unsigned char pad3eb;
    unsigned char pad3ec;
    unsigned char pad3ed;
    unsigned char pad3ee;
    unsigned char pad3ef;
    unsigned char pad3f0;
    unsigned char pad3f1;
    unsigned char pad3f2;
    unsigned char pad3f3;
    unsigned char pad3f4;
    unsigned char pad3f5;
    unsigned char pad3f6;
    unsigned char pad3f7;
    unsigned char pad3f8;
    unsigned char pad3f9;
    unsigned char pad3fa;
    unsigned char pad3fb;
    unsigned char pad3fc;
    unsigned char pad3fd;
    unsigned char pad3fe;
    unsigned char pad3ff;
    unsigned char pad400;
    unsigned char pad401;
    unsigned char pad402;
    unsigned char pad403;
    unsigned char pad404;
    unsigned char pad405;
    unsigned char pad406;
    unsigned char pad407;
    unsigned char pad408;
    unsigned char pad409;
    unsigned char pad40a;
    unsigned char pad40b;
    unsigned char pad40c;
    unsigned char pad40d;
    unsigned char pad40e;
    unsigned char pad40f;
};

struct S_00c6c840_Outer : S_00c6c840_Pad, S_00c6c840_class
{
    void FUN_00926980(void* a);
};


// Checks whether the value's low 7 bits equal 0x1e; if so increments unk6c and, when unk69 is set, calls FUN_00926980 with DAT_011f426c.
// @fnv 0x00c6c840
void S_00c6c840_class::FUN_00c6c840(int a, S_00c6c840_Param* b)
{
    S_00c6c840_Value* value = reinterpret_cast<S_00c6c840_Value*>(b->m_pObject_48);

    if ((value->m_value_1c & 0x7f) == 0x1e)
    {
        ++unk6c;

        if (unk69 != 0)
        {
            reinterpret_cast<::RigidBodyOwnerL *>((static_cast<S_00c6c840_Outer*>(this)))->FUN_00926980((*(const ::NiPoint3 *)(&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO)))));
        }
    }
}


// @fnv 0x00c6cd90
void* FUN_00c6cd90()
{
    return &(*reinterpret_cast<int *>(&::g_012686d4));
}

namespace fnv_00c6cdc0 {

// If pObject is non-null, frees it as a 0x80-byte block through the Havok heap allocator.
// @fnv 0x00c6cdc0
void __cdecl FUN_00c6cdc0(void* pObject)
{
    if (pObject != 0)
    {
        hkMemoryRouter::getInstance().heap().blockFree(pObject, 0x80);
    }
}
}  // namespace fnv_00c6cdc0


struct SpawnBase
{
    SpawnBase();
    virtual ~SpawnBase();
    int unk04;
    int unk08;
};

struct SpawnField
{
    SpawnField(int a1);
    ~SpawnField();
    int unk00;
};

struct SpawnSlot
{
    int m_00;
    SpawnSlot() : m_00(0)
    {}
};

struct FUN_00c6ce80_cls : SpawnBase, SpawnSlot
{
    virtual ~FUN_00c6ce80_cls();
    SpawnField m_10;

    FUN_00c6ce80_cls();
};

// Increments g_spawnCount and initializes the SpawnField member m_10 with 0.
// @fnv 0x00c6ce80
FUN_00c6ce80_cls::FUN_00c6ce80_cls() : m_10(0)
{
    ++::DAT_01268340;
}

// @fnv 0x00c6cee0
int __cdecl FUN_00c6cee0()
{
    return 0x80;
}

struct FUN_00c6cef0_target
{
};

struct FUN_00c6cef0_cls
{
    int unk00;
    int unk04;
    FUN_00c6cef0_target* m_08;
    void CallTargetWithArgs(intptr_t a, uintptr_t b);
};

// If this and m_08 are non-null, calls FUN_00cac110 before and after forwarding a and b to m_08's FUN_00cafd00.
// @fnv 0x00c6cef0
void FUN_00c6cef0_cls::CallTargetWithArgs(intptr_t a, uintptr_t b)
{
    if (this != 0)
    {
        FUN_00c6cef0_target* target = m_08;
        if (target != 0)
        {
            reinterpret_cast<::FUN_00cac110_Class *>(this)->FUN_00cac110();
            reinterpret_cast<::ContactQuery *>((target))->FUN_00cafd00((void *)(a), b);
            reinterpret_cast<::FUN_00cac110_Class *>(this)->FUN_00cac110();
        }
    }
}

extern void __cdecl FUN_00cabf50();

struct FUN_00c6d010_Class
{
    FUN_00c6d010_Class* FUN_00c6d010(unsigned char flags);
};

// Calls FUN_00cabf50, then frees this with operator delete when bit 0 of flags is set, and returns this.
// @fnv 0x00c6d010
FUN_00c6d010_Class* FUN_00c6d010_Class::FUN_00c6d010(unsigned char flags)
{
    FUN_00cabf50();

    if (flags & 1)
    {
        ::FUN_00aa1460(this, 0x3e0);
    }

    return this;
}


// @fnv 0x00c6d0e0
intptr_t __cdecl FUN_00c6d0e0()
{
    return reinterpret_cast<intptr_t>(&::g_012685a4);
}

// @fnv 0x00c6d0f0
int FUN_00c6d0f0()
{
    return 0x60;
}

class C6D1E0Base
{
  public:
    C6D1E0Base();
    virtual ~C6D1E0Base();
};

class FUN_00c6d1e0 : public C6D1E0Base
{
  public:
    FUN_00c6d1e0(int a, intptr_t b);
    virtual ~FUN_00c6d1e0();

};

// Constructs the object and forwards both arguments to Init.
// @fnv 0x00c6d1e0
FUN_00c6d1e0::FUN_00c6d1e0(int a, intptr_t b)
{
    reinterpret_cast<::S00cbe9f0_cls *>(this)->FUN_00cbe9f0(a, (::FUN_00cbe9f0_Target *)(b));
}


// @fnv 0x00c6d250
void* __cdecl FUN_00c6d250()
{
    return &(*reinterpret_cast<int *>(&::g_01268444));
}

namespace fnv_00c6d260 {
struct FUN_00aa4060_class
{
};


struct FUN_00c6d260_class
{
    FUN_00c6d260_class* ScalarDeletingDestructor(unsigned int flags);
};

// @fnv 0x00c6d260
FUN_00c6d260_class* FUN_00c6d260_class::ScalarDeletingDestructor(unsigned int flags)
{
    reinterpret_cast<::FUN_00cbe880_Class *>(this)->FUN_00cbe880();
    if ((flags & 1) && this)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c6d260::FUN_00aa4060_class *>(&::g_memoryManager))))->FUN_00aa4060((char*)this - GetAlignedBlockPrefix(this)->m_ucOffset);
    }
    return this;
}
}  // namespace fnv_00c6d260


struct FUN_00c87c30_owner
{
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct FUN_00c8b090_owner
{
};

struct ChainA_cls : public FUN_00c87c30_owner
{
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012686d0 += 1;
    }
};

struct FUN_00c6d290 : public ChainB_cls
{
    virtual void unkC2();
    FUN_00c6d290(uintptr_t a);
};

// Calls the base SetListShape with a, then increments DAT_012681a0.
// @fnv 0x00c6d290
FUN_00c6d290::FUN_00c6d290(uintptr_t a)
{
    reinterpret_cast<::bhkListOwner_c8b090 *>((((FUN_00c8b090_owner*)this)))->SetListShape((::ListInfo_c8b090 *)(a));
    DAT_012681a0 += 1;
}


// @fnv 0x00c6d310
void* __cdecl FUN_00c6d310()
{
    return &(*reinterpret_cast<int *>(&::g_012681a8));
}


struct FUN_00c6d320_class
{
    void* FUN_00c6d320(char flags);
};

// Calls FUN_00c8adf0, then frees this with operator delete when bit 0 of flags is set, and returns this.
// @fnv 0x00c6d320
void* FUN_00c6d320_class::FUN_00c6d320(char flags)
{
    reinterpret_cast<::FUN_00c8adf0_cls *>(this)->FUN_00c8adf0_cls::~FUN_00c8adf0_cls();
    if (flags & 1)
    {
        ::FUN_00aa1460(this, 0x14);
    }
    return this;
}

__declspec(thread) unsigned int hkThreadModeSlots[174];

struct CallbackTarget
{
};
extern CallbackTarget* DAT_01267bb8;

struct ScopedThreadMode
{
    unsigned int previous;

    __forceinline ScopedThreadMode() : previous(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }

    __forceinline ~ScopedThreadMode()
    {
        g_tlsBlock.memoryContext = previous;
    }
};

// Sets thread mode slot 173 to 16 for the scope, then calls FUN_00c905b0 on DAT_01267bb8 if it is non-null.
// @fnv 0x00c6d340
void __cdecl RunCallbackIfPresent()
{
    ScopedThreadMode scope;
    if (DAT_01267bb8)
        reinterpret_cast<::hkReferencedObjectC905 *>((DAT_01267bb8))->FUN_00c905b0();
}

// A counted, polymorphic object: the vtable pointer sits at object offset 0,
// the reference counter at object offset 4, and the release handler is the
// second virtual of the class (vtable slot 1, i.e. vtable offset 4).
struct FNV_RefCounted
{
    virtual void v0();
    virtual void v1();
    volatile long m_iObjectReferenceCount;
};

// The global that owns the object; it is cleared once the object is released.

// Decrements the global ref-counted object's reference count and calls its v1() when it reaches zero, then clears the global pointer.
// @fnv 0x00c6d3c0
void FUN_00c6d3c0()
{
    if ((*reinterpret_cast<::FNV_RefCounted * *>(&::DAT_01267be0)))
    {
        FNV_RefCounted* pObject = (*reinterpret_cast<::FNV_RefCounted * *>(&::DAT_01267be0));
        if (InterlockedDecrement(&(*reinterpret_cast<::FNV_RefCounted * *>(&::DAT_01267be0))->m_iObjectReferenceCount) == 0)
        {
            pObject->v1();
        }
        (*reinterpret_cast<::FNV_RefCounted * *>(&::DAT_01267be0)) = 0;
    }
}

inline float BC6D6B0Sqrtf(float fValue)
{
    return (float)sqrt(fValue);
}

inline float BC6D6B0Sqrt(float fValue)
{
    return BC6D6B0Sqrtf(fValue);
}

class BC6D6B0Point3
{
  public:
    float x;
    float y;
    float z;

    BC6D6B0Point3 operator-(const BC6D6B0Point3& kPt) const
    {
        BC6D6B0Point3 kResult;
        kResult.x = x - kPt.x;
        kResult.y = y - kPt.y;
        kResult.z = z - kPt.z;
        return kResult;
    }

    float Length() const
    {
        return BC6D6B0Sqrt(x * x + y * y + z * z);
    }
};

struct BC6D6B0Bound
{
    BC6D6B0Point3 m_kCenter;
    float m_fBoundRadius;
};


class BC6D6B0AVObject
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
    BC6D6B0Bound* m_pkWorldBound;
};

class BC6D6B0Tracker
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    float m_fHitDistance;

    void UpdateDistance(const BC6D6B0Point3& kPos, BC6D6B0AVObject* pkObject);
};

// @fnv 0x00c6d6b0
void BC6D6B0Tracker::UpdateDistance(const BC6D6B0Point3& kPos, BC6D6B0AVObject* pkObject)
{
    if (!pkObject)
        return;
    const BC6D6B0Bound* pkBound = pkObject->m_pkWorldBound ? pkObject->m_pkWorldBound : &(*reinterpret_cast<::BC6D6B0Bound *>(&::g_defaultBound));
    float fDist = (kPos - pkBound->m_kCenter).Length() - pkBound->m_fBoundRadius;
    m_fHitDistance = fDist > 0.0f ? fDist : 0.0f;
}

struct S_00c6d7a0_Handler
{
};

struct S_00c6d7a0_Obj
{
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c, unk130, unk134,
        unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c, unk170, unk174,
        unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4,
        unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4,
        unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c, unk230, unk234,
        unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c, unk270, unk274,
        unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4,
        unk2b8, unk2bc;
    int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4,
        unk2f8, unk2fc;
    int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c, unk330, unk334,
        unk338, unk33c;
    int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c, unk360, unk364, unk368, unk36c, unk370, unk374,
        unk378, unk37c;
    int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4,
        unk3b8, unk3bc;
    int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4,
        unk3f8, unk3fc;
    int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c, unk420, unk424, unk428, unk42c, unk430, unk434,
        unk438, unk43c;
    int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c, unk470, unk474,
        unk478, unk47c;
    int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4,
        unk4b8, unk4bc;
    int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc, unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4,
        unk4f8, unk4fc;
    int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c, unk530, unk534,
        unk538, unk53c;
    int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c, unk570, unk574,
        unk578, unk57c;
    int unk580, unk584, unk588, unk58c, unk590;
    S_00c6d7a0_Handler* unk594;
    S_00c6d7a0_Handler* unk598;
    void FUN_00c6d7a0(intptr_t arg);
};

// Forwards arg to the handler objects at unk594 and unk598, calling each with a default of 0 when present.
// @fnv 0x00c6d7a0
void S_00c6d7a0_Obj::FUN_00c6d7a0(intptr_t arg)
{
    if (unk594)
        reinterpret_cast<::S_00c85c10 *>((unk594))->FUN_00c85c10((int *)(arg), (int *)(0));
    if (unk598)
        reinterpret_cast<::S_00c85c10 *>((unk598))->FUN_00c85c10((int *)(arg), (int *)(0));
}


class RefObject
{
  public:
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
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

template <class T> class SmartPtr
{
  public:
    SmartPtr(T* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    SmartPtr(const SmartPtr& o)
    {
        m_pObject = o.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SmartPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

class Holder
{
  public:
    char m_00[0x59c];
    int m_iIndex;
    int m_5a0;
    SmartPtr<RefObject> m_aspObj[2];
    RefObject* GetCurrentObject();
};

// @fnv 0x00c6d960
RefObject* Holder::GetCurrentObject()
{
    return m_iIndex < 2 ? m_aspObj[m_iIndex] : SmartPtr<RefObject>(0);
}

class C6DE10NiObject
{
  public:
    virtual ~C6DE10NiObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

class C6DE10ReferencedObject
{
  public:
    void RetainReference();
};

template <class T> class C6DE10RefPtr
{
  public:
    C6DE10RefPtr() : m_pRetainedObject(0)
    {}
    ~C6DE10RefPtr()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }

    C6DE10RefPtr& operator=(T* e)
    {
        if (e)
            e->RetainReference();
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = e;
        return *this;
    }

    T* m_pRetainedObject;
};

class FUN_00c6de10
{
  public:
    ~FUN_00c6de10();

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
    NiPointer<C6DE10NiObject> m_spNode;
    C6DE10RefPtr<C6DE10ReferencedObject> m_spShape;
};

// Destructor that releases the referenced shape by assigning null to m_spShape, dropping its reference.
// @fnv 0x00c6de10
FUN_00c6de10::~FUN_00c6de10()
{
    m_spShape = 0;
}

// LookupFirstByKey - lookup helper.
//
//   0x00c6dec0  mov ecx, [esp+8]        ; the container (this for the inner call)
//   0x00c6dec4  sub esp, 8              ; 8-byte result block
//   0x00c6dec7  xor eax, eax            ; the shared zero (result + 3rd argument)
//   0x00c6dec9  test ecx, ecx
//   0x00c6decb  je   0x00c6dee0
//   0x00c6decd  push eax                ; third argument = 0
//   0x00c6dece  mov eax, [esp+0x10]     ; first argument
//   0x00c6ded2  push eax
//   0x00c6ded3  lea edx, [esp+8]        ; &result
//   0x00c6ded7  push edx
//   0x00c6ded8  call 0x00c6d840         ; container->Find(&result, key, 0)
//   0x00c6dedd  mov eax, [esp]          ; result.m_pFirst
//   0x00c6dee0  add esp, 8
//   0x00c6dee3  ret

struct FnvLookup_Result
{
    void* m_pFirst;
    void* m_pSecond;
};

struct FnvLookup_Container
{
    void FnvLookup_Find(FnvLookup_Result* pOut, unsigned int uiKey, void* pExtra);
};

// Looks up uiKey in pContainer and returns the first pointer of the result, or null if pContainer is null.
// @fnv 0x00c6dec0
void* __cdecl LookupFirstByKey(unsigned int uiKey, FnvLookup_Container* pContainer)
{
    FnvLookup_Result result;
    void* pRes = 0;
    if (pContainer)
    {
        pContainer->FnvLookup_Find(&result, uiKey, 0);
        pRes = result.m_pFirst;
    }
    return pRes;
}

struct C6E030State
{
    int unk00;
    int m_iArrayLength;
};

struct C6E030Body
{
};

struct C6E030Holder
{
    int unk00;
    int unk04;
    C6E030Body* m_pkBody;

    void ResetState();
};

// @fnv 0x00c6e030
void C6E030Holder::ResetState()
{
    if (this && m_pkBody)
        ((::C6E030State *)(::FUN_00cac900((::SomeClass *)(m_pkBody))))->m_iArrayLength = 0;
}

struct SettingHolder
{
    void* FUN_00653290(const void* key);
};
struct FUN_00c6e280_setting
{
    char pad[0x10];
    float m_fValue;
};
struct FUN_00c6e280_extra
{
    void* m_pVtbl;
    unsigned int m_uiRefCount;
    FUN_00c6e280_setting* m_pSetting;
};
struct FUN_00c6e280_cls
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
    unsigned int unk0d8;
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
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    SettingHolder* m_5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    float m_5f0;
    float GetSettingFloat();
};

// @fnv 0x00c6e280
float FUN_00c6e280_cls::GetSettingFloat()
{
    volatile float result;
    SettingHolder* h = m_5a4;
    if (h != 0)
    {
        FUN_00c6e280_extra* r = static_cast<FUN_00c6e280_extra*>(h->FUN_00653290(&(*reinterpret_cast<char *>(&::g_0126832c))));
        if (r != 0)
        {
            FUN_00c6e280_setting* p = r->m_pSetting;
            if (p != 0)
            {
                result = p->m_fValue;
            }
            else
            {
                result = DAT_010c72bc;
            }
            result = result;
            return result;
        }
    }
    result = m_5f0;
    return result;
}

struct ControllerShell
{
    void* m_pVtbl;
    char pad04[0x414 - 0x04];
    unsigned int m_uiFlags;
    char pad418[0x59c - 0x418];
    int m_iSelectedMode;
    int m_i5a0;
    int m_aiAvailableModes[1];

    int& selectedMode()
    {
        return m_iSelectedMode;
    }
    int& availableMode(int index)
    {
        return m_aiAvailableModes[index];
    }
    unsigned int& flags()
    {
        return m_uiFlags;
    }
    void SetMode(int);
    void CallVirtualReset(int value)
    {
        typedef void(* VirtualFunc)(ControllerShell*, int);
        VirtualFunc* methods = *reinterpret_cast<VirtualFunc**>(this);
        methods[0x34](this, value);
    }
};

class FUN_00c708a0_cls
{
  public:
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
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned char m_414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    int m_59c;
    int m_5a0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    float m_5f0;
    float m_5f4;
    float m_5f8;
    unsigned int unk5FC;
    int m_600;
    void FUN_00c708a0(float a1);
};

// @fnv 0x00c708a0
void FUN_00c708a0_cls::FUN_00c708a0(float afValue)
{
    if ((m_414 & 1) != 0)
    {
        return;
    }
    double scaled = (double)m_5f4 * DAT_01011588;
    double d = (afValue > scaled) ? (double)(float)scaled : (double)afValue;
    if (d <= 0.0)
    {
        d = m_5f0;
    }
    afValue = (float)d;
    if (afValue != m_5f8)
    {
        if (m_5a0 == 2)
        {
            m_5a0 = m_59c;
            reinterpret_cast<::ControllerShell *>(this)->SetMode(0);
        }
        m_600 = 2;
        m_5f8 = afValue;
    }
}

struct C70B60Point3
{
    float x;
    float y;
    float z;
};



struct C70B60UpdateData
{
    float m_fTime;
    int unk04;
    int unk08;
    int unk0C;
    C70B60Point3 m_kValue;
};

class C70B60Character
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void ApplyUpdate(C70B60UpdateData* pkData);

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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    char m_acState[4];

    void FUN_00c70b60(C70B60UpdateData* pkData, bool bForce);
};

namespace fnv_00c70bd0 {
struct RefCountedObj_b4889
{
    virtual void v0();
    virtual void Destroy();
    long m_iRef;
};

struct PoolNode_b4889
{
    RefCountedObj_b4889* m_pEntryObject;
    PoolNode_b4889* m_pNext;
};

struct ListNode_b4889
{
    PoolNode_b4889* m_pInventoryEntryData;
    ListNode_b4889* m_pNext;
};

struct PoolAllocator_b4889
{
    void Free(void* apPtr);
};


class FUN_00c70bd0_cls
{
  public:
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int unk02B4;
    unsigned int unk02B8;
    unsigned int unk02BC;
    unsigned int unk02C0;
    unsigned int unk02C4;
    unsigned int unk02C8;
    unsigned int unk02CC;
    unsigned int unk02D0;
    unsigned int unk02D4;
    unsigned int unk02D8;
    unsigned int unk02DC;
    unsigned int unk02E0;
    unsigned int unk02E4;
    unsigned int unk02E8;
    unsigned int unk02EC;
    unsigned int unk02F0;
    unsigned int unk02F4;
    unsigned int unk02F8;
    unsigned int unk02FC;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030C;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031C;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032C;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033C;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034C;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035C;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036C;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037C;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038C;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039C;
    unsigned int unk03A0;
    unsigned int unk03A4;
    unsigned int unk03A8;
    unsigned int unk03AC;
    unsigned int unk03B0;
    unsigned int unk03B4;
    unsigned int unk03B8;
    unsigned int unk03BC;
    unsigned int unk03C0;
    unsigned int unk03C4;
    unsigned int unk03C8;
    unsigned int unk03CC;
    unsigned int unk03D0;
    unsigned int unk03D4;
    unsigned int unk03D8;
    unsigned int unk03DC;
    unsigned int unk03E0;
    unsigned int unk03E4;
    unsigned int unk03E8;
    unsigned int unk03EC;
    unsigned int unk03F0;
    unsigned int unk03F4;
    unsigned int unk03F8;
    unsigned int unk03FC;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040C;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041C;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042C;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043C;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044C;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045C;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046C;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047C;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048C;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049C;
    unsigned int unk04A0;
    unsigned int unk04A4;
    unsigned int unk04A8;
    unsigned int unk04AC;
    unsigned int unk04B0;
    unsigned int unk04B4;
    unsigned int unk04B8;
    unsigned int unk04BC;
    unsigned int unk04C0;
    unsigned int unk04C4;
    unsigned int unk04C8;
    unsigned int unk04CC;
    unsigned int unk04D0;
    unsigned int unk04D4;
    unsigned int unk04D8;
    unsigned int unk04DC;
    unsigned int unk04E0;
    unsigned int unk04E4;
    unsigned int unk04E8;
    unsigned int unk04EC;
    unsigned int unk04F0;
    unsigned int unk04F4;
    unsigned int unk04F8;
    unsigned int unk04FC;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050C;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051C;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052C;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053C;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054C;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055C;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056C;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057C;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058C;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059C;
    unsigned int unk05A0;
    unsigned int unk05A4;
    unsigned int unk05A8;
    unsigned int unk05AC;
    unsigned int unk05B0;
    unsigned int unk05B4;
    unsigned int unk05B8;
    unsigned int unk05BC;
    unsigned int unk05C0;
    unsigned int unk05C4;
    unsigned int unk05C8;
    unsigned int unk05CC;
    unsigned int unk05D0;
    unsigned int unk05D4;
    unsigned int unk05D8;
    unsigned int unk05DC;
    unsigned int unk05E0;
    unsigned int unk05E4;
    unsigned int unk05E8;
    unsigned int unk05EC;
    unsigned int unk05F0;
    unsigned int unk05F4;
    unsigned int unk05F8;
    unsigned int unk05FC;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060C;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061C;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062C;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063C;
    unsigned int unk0640;
    unsigned int unk0644;
    PoolNode_b4889* m_648;
    ListNode_b4889* m_64c;

    void ClearList();
};

// Releases and frees all pooled nodes and list nodes until both m_648 and m_64c are empty, decrementing object refcounts and destroying them at zero.
// @fnv 0x00c70bd0
void FUN_00c70bd0_cls::ClearList()
{
    for (;;)
    {
        if (m_64c == 0 && m_648 == 0)
        {
            break;
        }
        PoolNode_b4889* cur = m_648;
        if (cur != 0)
        {
            RefCountedObj_b4889* obj = cur->m_pEntryObject;
            if (obj != 0)
            {
                if (InterlockedDecrement(&obj->m_iRef) == 0)
                {
                    obj->Destroy();
                }
            }
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c70bd0::PoolAllocator_b4889 *>(&::g_memoryManager))))->FUN_00aa4060(cur);
        }
        ListNode_b4889* head = m_64c;
        if (head != 0)
        {
            m_64c = head->m_pNext;
            m_648 = head->m_pInventoryEntryData;
            head->m_pNext = 0;
            ::FUN_00b4df30((void *)(head));
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c70bd0::PoolAllocator_b4889 *>(&::g_memoryManager))))->FUN_00aa4060(head);
        }
        else
        {
            m_648 = 0;
        }
    }
}
}  // namespace fnv_00c70bd0

struct FUN_00c747b0_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual intptr_t vfB4(char* value);
    intptr_t FUN_00c747b0();
};

// @fnv 0x00c747b0
intptr_t FUN_00c747b0_Class::FUN_00c747b0()
{
    char value;
    intptr_t result = this->vfB4(&value);

    if (result != 0)
        return result - 4;

    return 0;
}

struct C74820Slot
{
    bool m_bModifierActive;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
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
};

class C74820Controller
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
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    bool m_bFlagAt0x43;
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
    C74820Slot m_akSlots[2];
    unsigned char unk21C;
    bool m_bDefault;
    bool m_bEnableState;

    void SetSlotActive(int iSlot, bool bActive);
};

// @fnv 0x00c74820
void C74820Controller::SetSlotActive(int iSlot, bool bActive)
{
    if (bActive)
        m_bEnableState = !m_bFlagAt0x43 ? m_bDefault != 0 : m_bEnableState;
    if (m_bEnableState)
        m_akSlots[iSlot].m_bModifierActive = bActive;
}

struct MapEntry
{
    MapEntry* next;
    unsigned int key;
    unsigned short value;
};

struct MapTable
{
    virtual void Destroy();
    virtual unsigned int Hash(unsigned int key);
    virtual bool Equal(unsigned int lhs, unsigned int rhs);
    virtual void Initialize(MapEntry* entry, unsigned int key, unsigned int value);
    virtual void OnResize();
    virtual MapEntry* AllocateEntry();

    unsigned int bucketCount;
    MapEntry** buckets;
    unsigned int count;

    void InsertOrUpdate(uintptr_t key, unsigned int value);
};

// Looks up key in the hash bucket, updates the entry's value if found, otherwise allocates, initializes and prepends a new entry and increments count.
// @fnv 0x00c74910
void MapTable::InsertOrUpdate(uintptr_t key, unsigned int value)
{
    unsigned int bucket = Hash(key);
    MapEntry* entry = buckets[bucket];
    while (entry)
    {
        if (Equal(key, entry->key))
        {
            entry->value = (unsigned short)value;
            return;
        }
        entry = entry->next;
    }

    MapEntry* newEntry = AllocateEntry();
    Initialize(newEntry, key, value);
    newEntry->next = buckets[bucket];
    buckets[bucket] = newEntry;
    ++count;
}

struct FUN_00c74990_node
{
    FUN_00c74990_node* next;
    uintptr_t key;
    unsigned short value;
};

class FUN_00c74990_cls
{
  public:
    virtual void GetPad();
    virtual unsigned int KeyToHashIndex(uintptr_t key);
    virtual bool IsKeyEqual(uintptr_t a, uintptr_t b);
    unsigned int m_uiHashSize;
    FUN_00c74990_node** m_ppkHashTable;
    unsigned int m_uiCount;
    bool LookupValue(uintptr_t key, unsigned short* out);
};

// Hashes the key, walks the bucket chain comparing keys, and writes the matching node's value to out, returning whether a match was found.
// @fnv 0x00c74990
bool FUN_00c74990_cls::LookupValue(uintptr_t key, unsigned short* pusValue)
{
    unsigned int idx = KeyToHashIndex(key);
    FUN_00c74990_node* cur = m_ppkHashTable[idx];
    while (cur != 0)
    {
        if (IsKeyEqual(key, cur->key))
        {
            *pusValue = cur->value;
            return true;
        }
        cur = cur->next;
    }
    return false;
}


struct C749F0Entry
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
};

// Overlap-safe element move.
// @fnv 0x00c749f0
void CopyEntries(C749F0Entry* pkDst, const C749F0Entry* pkSrc, unsigned int ItemUpdateArray)
{
    if (ItemUpdateArray > 0)
    {
        if (pkDst < pkSrc)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                std::memmove(&pkDst[i], &pkSrc[i], sizeof(C749F0Entry));
        }
        else if (pkDst > pkSrc)
        {
            for (int i = ItemUpdateArray - 1; i >= 0; i--)
                std::memmove(&pkDst[i], &pkSrc[i], sizeof(C749F0Entry));
        }
    }
}

namespace fnv_00c74f50 {

// If pBlock is not null, frees it as a 0x38-byte block through the Havok heap allocator.
// @fnv 0x00c74f50
void __cdecl FUN_00c74f50(void* pBlock)
{
    if (pBlock)
    {
        hkMemoryRouter::getInstance().heap().blockFree(pBlock, 0x38);
    }
}
}  // namespace fnv_00c74f50

namespace fnv_00c74f70 {
// @fnv 0x00c74f70
void __cdecl FUN_00c74f70(void* p)
{
    if (p)
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, 0x48);
    }
}
}  // namespace fnv_00c74f70


struct RoutingModeScope
{
    int previousMode;

    RoutingModeScope() : previousMode(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }
    ~RoutingModeScope()
    {
        g_tlsBlock.memoryContext = previousMode;
    }
};

struct RouteTarget
{
    virtual void Run(int mode);
};

struct RouteWrapper
{
    RouteTarget* target;
    void RunTargetWithMode();
};

// Saves the thread routing mode, sets it to 16, and if target is non-null calls target->Run(1), then restores the previous mode.
// @fnv 0x00c75100
void RouteWrapper::RunTargetWithMode()
{
    RoutingModeScope modeScope;
    if (target)
        target->Run(1);
}

class C75850Shape
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual int GetType();

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
    void* m_pResource;

};

struct C75850Entry
{
    int unk00;
    int unk04;
    int unk08;
    C75850Shape* m_pkShape;
};

struct C75850Group
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    C75850Entry** m_ppkEntries;
    int m_iArrayLength;
};

class C75850Body
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
    C75850Group* m_pkActorGroup;

    int IsBodyValid();
};

// @fnv 0x00c75850
int C75850Body::IsBodyValid()
{
    bool bValid = true;
    C75850Group* pkGroup = m_pkActorGroup;
    if (pkGroup)
    {
        for (int i = 0; i < pkGroup->m_iArrayLength && bValid; i++)
        {
            C75850Shape* pkShape = pkGroup->m_ppkEntries[i]->m_pkShape;
            if (pkShape->GetType() == 0xd || pkShape->GetType() == 0xc)
            {
                bValid = false;
            }
            else
            {
                switch (pkShape->GetType())
                {
                case 2:
                    if (!pkShape->m_pResource)
                        bValid = false;
                    break;
                case 7:
                    if (!reinterpret_cast<::FUN_00cdea20_cls *>((pkShape))->FUN_00cdea20() || !reinterpret_cast<::FUN_00cdea80_cls *>((pkShape))->FUN_00cdea80() || !((int)(reinterpret_cast<::FUN_00cdeaa0_cls *>((pkShape))->FUN_00cdeaa0())))
                        bValid = false;
                    break;
                }
            }
        }
    }
    if (bValid && m_pkActorGroup)
        return 1;
    return 0;
}

template <class T> static T& member_at(void* object, unsigned int offset)
{
    return *reinterpret_cast<T*>(reinterpret_cast<unsigned char*>(object) + offset);
}


struct FUN_00c759f0_Class
{
    void FUN_00c759f0();
};

// @fnv 0x00c759f0
void FUN_00c759f0_Class::FUN_00c759f0()
{
    void* sourceOwner = member_at<void*>(this, 0x2a4);
    void* source = member_at<void*>(sourceOwner, 0x18);
    if (source)
    {
        void* destination = *member_at<void**>(this, 0x4c);
        member_at<float>(destination, 0x0c) = member_at<float>(source, 0x10);
        member_at<float>(destination, 0x10) =
            member_at<float>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x0c);
        member_at<float>(destination, 0x1c) =
            member_at<float>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x18);
        member_at<float>(this, 0x290) = member_at<float>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x04);
        double scale = 0.25;
        member_at<unsigned int>(this, 0x29c) = static_cast<unsigned int>(
            static_cast<float>(member_at<unsigned int>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x38)) *
            scale);
        member_at<unsigned int>(this, 0x298) = static_cast<unsigned int>(
            static_cast<float>(member_at<unsigned int>(member_at<void*>(member_at<void*>(this, 0x2a4), 0x18), 0x3c)) *
            scale);
    }
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
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

class FUN_00c75ce0_cls
{
  public:
    unsigned int unk00;
    unsigned int m_uiCurrentValue;
    NiPointer<NiRefObject> m_pReferencedObject;
};

// @fnv 0x00c75ce0
void FUN_00c75ce0(FUN_00c75ce0_cls* self, unsigned int value, NiPointer<NiRefObject> obj)
{
    self->m_uiCurrentValue = value;
    self->m_pReferencedObject = obj;
}

namespace fnv_00c75e20 {
class NiRefObject
{
  public:
    virtual ~NiRefObject();
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

class FUN_00c75e20_cls
{
  public:
    unsigned int unk00;
    unsigned int m_uiCurrentValue;
    NiPointer<NiRefObject> m_pReferencedObject;
};

// @fnv 0x00c75e20
void SetValueAndObject(FUN_00c75e20_cls* self, unsigned int value, NiPointer<NiRefObject> obj)
{
    self->m_uiCurrentValue = value;
    self->m_pReferencedObject = obj;
}
}  // namespace fnv_00c75e20


struct EventBase
{
    virtual __forceinline ~EventBase()
    {
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        ::FUN_00aa10f0(resource);
    }
    int state;
    void* resource;
};

struct FUN_00c75ed0 : EventBase
{
    ~FUN_00c75ed0();
};

// @fnv 0x00c75ed0
FUN_00c75ed0::~FUN_00c75ed0()
{
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
}

class FUN_00c75f40_cls
{
  public:
};


// @fnv 0x00c75f40
void AllocCountedBytes(unsigned int count)
{
    unsigned int size = count * 4;
    reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::FUN_00c75f40_cls *>(&::g_memoryManager))))->FUN_00aa3e40(size);
}

namespace fnv_00c76010 {
struct S_00c76010_rec
{
    int unk00;
    int unk04;
    unsigned short unk08;
};

struct S_00aa4060_cls
{
};


// @fnv 0x00c76010
void FUN_00c76010(S_00c76010_rec* pRecord)
{
    pRecord->unk08 = 0;
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c76010::S_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(pRecord);
}
}  // namespace fnv_00c76010

namespace fnv_00c760b0 {

struct FUN_00c760b0_pool
{
};

struct FUN_00c760b0_cls
{
    void* m_vptr;
    int m_04;
    void* m_08;


    FUN_00c760b0_cls* FUN_00c760b0(unsigned int acFlags);
};

// @fnv 0x00c760b0
FUN_00c760b0_cls* FUN_00c760b0_cls::FUN_00c760b0(unsigned int acFlags)
{
    m_vptr = &::fnv_00c75f80::DAT_010c4cf8;
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
    ::FUN_00aa10f0(m_08);
    if (acFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c760b0::FUN_00c760b0_pool *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00c760b0

struct FUN_00c76180_cls
{
    int m_04;
    int unk08;
    int m_0c;
    virtual int v0();
    virtual int v1(int a);
    virtual void v2(int a);
    virtual int v3(int a, int b);
    void Helper0(int a, int b, int c);
    void SetValue(int a1, int a2);
};

// @fnv 0x00c76180
void FUN_00c76180_cls::SetValue(int aiValue, int a2)
{
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v3(m_04, aiValue);
        }
        else
        {
            int t = v1(aiValue);
            Helper0(t, m_04, a2);
            v2(m_04);
            m_04 = t;
        }
    }
    else
    {
        m_04 = v1(aiValue);
        m_0c = aiValue;
    }
}

class C761F0Bool
{
  public:
    C761F0Bool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

class C761F0Character
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
    unsigned char m_uiContentCount;

    C761F0Bool FUN_00c761f0() const;
};

// @fnv 0x00c761f0
C761F0Bool C761F0Character::FUN_00c761f0() const
{
    return m_uiContentCount == 5 || m_uiContentCount == 4;
}

struct RefTarget_b5394
{
    unsigned int m_iRefCount;
    void DecRefCount();
    void IncRefCount();
};

struct VirtTarget_b5394
{
    virtual ~VirtTarget_b5394();
};

struct StrTarget_b5394
{
};

struct Heap_b5394
{
    void Free(void* p);
};


class Base_b5394
{
  public:
    virtual ~Base_b5394();
};

class FUN_00c76240_cls : public Base_b5394
{
  public:
    unsigned int m_04;
    RefTarget_b5394* m_08;
    VirtTarget_b5394* m_0c;
    RefTarget_b5394* m_10;
    RefTarget_b5394* m_14;
    unsigned int m_18;
    char* m_1c;
    virtual ~FUN_00c76240_cls();
};

// Destructor that decrements reference counts on m_08, m_10 and m_14, deletes m_0c, and releases and frees the string at m_1c.
// @fnv 0x00c76240
FUN_00c76240_cls::~FUN_00c76240_cls()
{
    if (m_08)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_08))->FUN_00c905b0();
    delete m_0c;
    if (m_10)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_10))->FUN_00c905b0();
    if (m_14)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_14))->FUN_00c905b0();
    char* str = m_1c;
    if (str)
    {
        reinterpret_cast<::RouteWrapper *>((((StrTarget_b5394*)str)))->RunTargetWithMode();
        char* base = str - GetAlignedBlockPrefix(str)->m_ucOffset;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::Heap_b5394 *>(&::g_memoryManager))))->FUN_00aa4060(base);
    }
}

struct FUN_00c762f0_Data
{
    int unk00;
    int unk04;
    int* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* unk20;
};

struct FUN_00c762f0_Prefix00
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
};

struct FUN_00c762f0_Prefix4C
{
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};

struct FUN_00c762f0_Owner : public FUN_00c762f0_Prefix00
{
    FUN_00c762f0_Data* unk48;
    FUN_00c762f0_Prefix4C unk4C;
    int unk2B8;

    intptr_t FUN_00c762f0();
};

// Looks up data->unk20[unk2B8]; if non-negative, returns data->unk08 at that index, otherwise 0.
// @fnv 0x00c762f0
intptr_t FUN_00c762f0_Owner::FUN_00c762f0()
{
    FUN_00c762f0_Data* data = unk48;
    if (data != 0)
    {
        int index = unk2B8;
        int value = data->unk20[index];
        if (value >= 0)
        {
            return data->unk08[value];
        }
    }
    return 0;
}

struct C78090Vertex
{
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
    unsigned int m_uiValue1;

    bool IsHidden() const
    {
        return (m_uiValue1 >> 1) & 1;
    }
};

struct C78090Triangle
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    short m_asVertex0;
    short m_asVertex1;
    short m_asVertex2;
    short unk1A;
};

struct C78090TriangleEntry
{
    C78090Triangle* m_pkTriangle;
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
};

struct C78090Mesh
{
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
    C78090Vertex** m_ppkVertices;
    unsigned int m_uiVertexCount;
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
    C78090TriangleEntry* m_pkTriangles;
    int m_iTriangleCount;

    C78090Vertex* GetVertex(unsigned int uiIndex) const
    {
        return m_uiVertexCount > uiIndex ? m_ppkVertices[uiIndex] : 0;
    }

    bool HasVisibleVertex();
};

// Scans the mesh's triangles and returns true as soon as any of a triangle's three vertices exists and is not hidden.
// @fnv 0x00c78090
bool C78090Mesh::HasVisibleVertex()
{
    bool bFound = false;
    for (int i = 0; i < m_iTriangleCount && !bFound; i++)
    {
        C78090Triangle& kTri = *m_pkTriangles[i].m_pkTriangle;
        C78090Vertex* pkVertex2 = GetVertex(kTri.m_asVertex2);
        C78090Vertex* pkVertex1 = GetVertex(kTri.m_asVertex1);
        C78090Vertex* pkVertex0 = GetVertex(kTri.m_asVertex0);
        bFound = (pkVertex2 && !pkVertex2->IsHidden()) || (pkVertex1 && !pkVertex1->IsHidden()) ||
                 (pkVertex0 && !pkVertex0->IsHidden());
    }
    return bFound;
}

struct FUN_00c79d60_R
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
    unsigned int m_30;
};

struct FUN_00c79d60_Q
{
    FUN_00c79d60_R* m_00;
    FUN_00c79d60_R* m_04;
    FUN_00c79d60_R* m_08;
};

struct FUN_00c79d60_P
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
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
    FUN_00c79d60_Q* m_a0;
};

struct FUN_00c79d60_W
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
    virtual void v37(FUN_00c79d60_P* p, int flag);
    virtual void v38();
    virtual void v39();
    virtual void v3a(FUN_00c79d60_P* p);
};

struct FUN_00c79d60_V
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c79d60_W* v03();
};

class FUN_00c79d60_cls
{
  public:
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
    FUN_00c79d60_V* m_58;
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
    FUN_00c79d60_P* m_84;
    void FUN_00c79d60(bool a1, bool a2, bool a3);
};

// Sets or clears bit 0 of the m_30 flags on the three entries in m_84->m_a0 based on a1/a2/a3, then calls v3a or v37 on the object from m_58->v03().
// @fnv 0x00c79d60
void FUN_00c79d60_cls::FUN_00c79d60(bool abFlag1, bool abFlag2, bool abFlag3)
{
    FUN_00c79d60_Q* q = m_84->m_a0;
    FUN_00c79d60_R* r = q->m_00;
    if (!abFlag1)
    {
        r->m_30 |= 1u;
    }
    else
    {
        r->m_30 &= 0xfffffffeu;
    }
    r = m_84->m_a0->m_04;
    if (!abFlag2)
    {
        r->m_30 |= 1u;
    }
    else
    {
        r->m_30 &= 0xfffffffeu;
    }
    r = m_84->m_a0->m_08;
    if (!abFlag3)
    {
        r->m_30 |= 1u;
    }
    else
    {
        r->m_30 &= 0xfffffffeu;
    }
    FUN_00c79d60_W* w = m_58->v03();
    if (w != 0)
    {
        if (!abFlag1 && !abFlag2 && !abFlag3)
        {
            w->v3a(m_84);
        }
        else if (m_84->m_18 == 0)
        {
            w->v37(m_84, 1);
        }
    }
}

// FUN_00c7a230: thiscall, 1 bool arg, /MT /O2 /GS /EHsc /Gy
struct ListItem
{
    int unk00;
    int unk04;
    int m_08;
};

struct ListMgr
{
};

struct ListLevel3
{
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    ListMgr* m_350;
};

struct ListLevel2
{
    int unk00;
    int unk04;
    ListLevel3* m_08;
};

struct ListLevel1
{
    ListLevel2* m_00;
};

struct ListOwner
{
    int unk00;
    int unk04;
    ListLevel1* m_08;
    int unk0C;
    int unk10;
    ListItem** m_14;
    int m_18;
};

class FUN_00c7a230_cls
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    ListOwner* m_48;
    void FUN_00c7a230(bool abActive);
};

struct Behavior;
struct Record
{
    unsigned int unk00, unk04, unk08;
    Behavior* behavior;
};
struct CountBlock
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int count;
};
struct InputMap
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    Record** records;
    unsigned int unk18, unk1c;
    int* indices;
    unsigned int unk24, unk28;
    CountBlock* counts;
};
struct StateFlag
{
    bool enabled;
    StateFlag(bool value) : enabled(value)
    {}
};
struct Behavior
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetKind();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    float valueAC;
};
// @fnv 0x00c7a2d0
void __cdecl EnableBehaviorsByKind(InputMap* input)
{
    int count = input->counts->count;
    for (int i = 0; i < count; ++i)
    {
        int index = input->indices[i] - 1;
        if (index < 0)
            continue;
        Record* item = input->records[index];
        if (!item)
            continue;
        Behavior* behavior = item->behavior;
        if (behavior->GetKind() == 13)
            behavior = ((::Behavior *)(reinterpret_cast<::MalleableGetterStandIn *>((behavior))->FUN_00cdf6c0()));
        if (!behavior)
            continue;
        switch (behavior->GetKind())
        {
        case 2:
            ::FUN_00cb8fe0((char *)(behavior), (void *)(item), true);
            behavior->valueAC = 0.0f;
            break;
        case 7:
            reinterpret_cast<::FUN_00cdf290_cls *>((behavior))->SetFlagAndClearFloats((intptr_t)(item), (*(char *)&(const ::StateFlag &)(true)));
            reinterpret_cast<::FUN_00cdf230_cls *>((behavior))->FUN_00cdf230((intptr_t)(&DAT_01268370));
            break;
        }
    }
}

struct UpdateOptions
{
    unsigned char enabled;
    UpdateOptions(bool value) : enabled(value)
    {}
};

struct ObjectView
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual int GetKind();

};

struct ComponentEntry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ObjectView* view;
};

struct ObjectCount
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int count;
};

struct ObjectContext
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    ComponentEntry** entries;
    void* unk18;
    void* unk1c;
    int* indices;
    void* unk24;
    void* unk28;
    ObjectCount* length;
};

// @fnv 0x00c7a380
void __cdecl UpdateEntriesByKind(ObjectContext* context)
{
    const int count = context->length->count;
    for (int index = 0; index < count; ++index)
    {
        int entryIndex = context->indices[index] - 1;
        if (entryIndex >= 0)
        {
            ComponentEntry* entry = context->entries[entryIndex];
            if (entry != 0)
            {
                ObjectView* view = entry->view;
                if (view->GetKind() == 13)
                    view = ((::ObjectView *)(reinterpret_cast<::MalleableGetterStandIn *>((view))->FUN_00cdf6c0()));
                if (view != 0)
                {
                    int kind = view->GetKind();
                    switch (kind)
                    {
                    case 2:
                        ::FUN_00cb8fe0((char *)(view), (void *)(entry), false);
                        break;
                    case 7:
                        reinterpret_cast<::FUN_00cdf290_cls *>((view))->SetFlagAndClearFloats((intptr_t)(entry), (*(char *)&(const ::UpdateOptions &)(false)));
                        break;
                    }
                }
            }
        }
    }
}

struct ReallocationManager : P03MM
{
};

// Calls the memory manager's reallocation routine with the given memory block and a byte size of count * 56.
// @fnv 0x00c7a600
void* FUN_00c7a600(void* memory, unsigned int count)
{
    return reinterpret_cast<::MemoryManager *>((static_cast<ReallocationManager*>(&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->Reallocate(memory, count * 56);
}

struct S_00c7a660_Foo
{
    int* vtbl;
    void* m_p;
    void* m_kPointA;
    void* m_kPointB;

    void FUN_00c7a660();
};

// Sets the vtable, and if m_p is non-null calls DAT_010c4cec on it then clears m_p and the two following pointers.
// @fnv 0x00c7a660
void S_00c7a660_Foo::FUN_00c7a660()
{
    vtbl = &DAT_010c4ce4;

    void* p = m_p;
    if (p)
    {
        (*(void(**)(void*)) & DAT_010c4cec)(p);

        m_p = 0;
        m_kPointB = 0;
        m_kPointA = 0;
    }
}

struct S_c7a730
{
    virtual void* unk_v0(unsigned int n);
    virtual void* unk_v1(unsigned int n);
    void* unk04;
    int unk08;
    unsigned int unk0c;
    int AppendSlot();
};

// Grows the buffer when full (doubling up to 0x400, then +0x400) and returns the index of the next appended slot.
// @fnv 0x00c7a730
int S_c7a730::AppendSlot()
{
    if (unk08 == unk0c)
    {
        if (unk0c == 0)
        {
            unk04 = unk_v1(4);
            unk0c = 4;
        }
        else
        {
            unsigned int newCap = unk0c + 0x400;
            if (unk0c <= 0x400)
                newCap = unk0c * 2;
            reinterpret_cast<::FUN_00c76180_cls *>(this)->SetValue(newCap, unk08);
            unk0c = newCap;
        }
    }
    unk08++;
    return unk08 - 1;
}

struct U16Array
{
    virtual void v0();
    virtual unsigned short* Allocate(unsigned int n);
    virtual void Free(unsigned short* p);
    unsigned short* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;


    __forceinline void SetSize(unsigned int n)
    {
        if (n == 0)
        {
            if (m_data)
            {
                Free(m_data);
                m_data = 0;
                m_pRayCursor = 0;
                m_iElementCount = 0;
            }
        }
        else if (n > m_pRayCursor)
        {
            if (m_pRayCursor == 0)
                m_data = Allocate(n);
            else
                reinterpret_cast<::FUN_005ef6a0Class *>(this)->SetOrReplace(n, m_iElementCount);
            m_pRayCursor = n;
            m_iElementCount = n;
        }
        else if (n < m_iElementCount)
        {
            unsigned int quarter = m_pRayCursor >> 2;
            m_iElementCount = n;
            if (n <= quarter)
            {
                reinterpret_cast<::FUN_005ef6a0Class *>(this)->SetOrReplace(n, n);
                m_pRayCursor = n;
            }
        }
        else
        {
            m_iElementCount = n;
        }
    }
};

struct FUN_00c7a790_Data
{
    char m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    int m_38;
    int m_3c;
    U16Array m_ppData;

    void CopyFrom(const FUN_00c7a790_Data& src);
};

// Copies the U16Array contents and all scalar fields from src into this object.
// @fnv 0x00c7a790
void FUN_00c7a790_Data::CopyFrom(const FUN_00c7a790_Data& src)
{
    m_ppData.SetSize(src.m_ppData.m_iElementCount);
    for (unsigned int i = 0; i < src.m_ppData.m_iElementCount; i++)
        m_ppData.m_data[i] = src.m_ppData.m_data[i];
    m_00 = src.m_00;
    m_04 = src.m_04;
    m_08 = src.m_08;
    m_0c = src.m_0c;
    m_10 = src.m_10;
    m_14 = src.m_14;
    m_18 = src.m_18;
    m_1c = src.m_1c;
    m_20 = src.m_20;
    m_24 = src.m_24;
    m_28 = src.m_28;
    m_2c = src.m_2c;
    m_30 = src.m_30;
    m_34 = src.m_34;
    m_38 = src.m_38;
    m_3c = src.m_3c;
}

namespace fnv_00c7a990 {

struct S_arr
{
    int* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiValue1;
};

struct S_node
{
    virtual void* v0();
    virtual void* v1();
    virtual S_node* Query();
    int m_unk04;
    int m_unk08;
};

struct S_listentry
{
    S_node* m_pReferencedNode;
    S_listentry* m_pNext;
};

struct S_item
{
    int m_unk00;
    int m_unk04;
    int m_value08;
    int m_unk0C;
    int m_unk10;
    S_listentry m_list14;
};


// NiRTTI: a name and the base class's RTTI.
struct S_rtti
{
    const char* m_pcName;
    S_rtti* m_pkBaseRTTI;
};

static __forceinline bool S_IsKind(S_node* apNode)
{
    S_rtti* r = reinterpret_cast<S_rtti*>(apNode);
    while (r)
    {
        if ((void*)r == (void*)&(*reinterpret_cast<int *>(&::g_0126818c)))
            return true;
        r = r->m_pkBaseRTTI;
    }
    return false;
}

// Appends item->m_value08 to arr, then walks item->m_list14 and appends each matching node's m_value08 to arr2, growing both arrays as needed.
// @fnv 0x00c7a990
void CollectItemValues(S_item* item, S_arr* pValues, S_arr* pLinkedValues)
{
    if (item == 0)
    {
        return;
    }
    int value = item->m_value08;
    if (pValues->m_uiSize == (pValues->m_uiValue1 & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(hkMemoryRouter::getInstance().m_heap), (::AudioStream *)(pValues), 4);
    }
    int* slot = pValues->m_pBuffer + pValues->m_uiSize;
    for (int k = 0; k < 1; k++)
        slot[k] = value;
    unsigned int uiIncrement = 1;
    pValues->m_uiSize += uiIncrement;

    S_listentry* entry = &item->m_list14;
    while (entry != 0)
    {
        S_node* node = entry->m_pReferencedNode;
        if (node == 0)
        {
            break;
        }
        S_node* r = node->Query();
        bool found = S_IsKind(r);
        S_node* pSelectedNode = found ? node : 0;
        if (pSelectedNode != 0)
        {
            S_item* obj = (S_item*)pSelectedNode;
            int v = obj->m_value08;
            if (pLinkedValues->m_uiSize == (pLinkedValues->m_uiValue1 & 0x3fffffff))
            {
                ::ResizeAudioStream((::AudioAllocator *)(hkMemoryRouter::getInstance().m_heap), (::AudioStream *)(pLinkedValues), 4);
            }
            int* piLinkedSlot = pLinkedValues->m_pBuffer + pLinkedValues->m_uiSize;
            for (int k = 0; k < 1; k++)
                piLinkedSlot[k] = v;
            pLinkedValues->m_uiSize += uiIncrement;
        }
        entry = entry->m_pNext;
    }
}
}  // namespace fnv_00c7a990

namespace fnv_00c7b0b0 {


struct FUN_00c7b0b0_class
{
    void* volatile unk00;
    volatile int unk04;
    volatile int unk08;

    void FUN_00c7b0b0();
};

// @fnv 0x00c7b0b0
void FUN_00c7b0b0_class::FUN_00c7b0b0()
{
    hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();

    int value = unk08;
    unk04 = 0;

    if ((value & 0x80000000) == 0)
    {
        int count = value & 0x3fffffff;
        count *= 0xd0;
        heap.bufFree(unk00, count);
    }

    unk08 = 0x80000000;
    unk00 = 0;
}
}  // namespace fnv_00c7b0b0

namespace fnv_00c7b130 {


struct FUN_00c7b130_cls
{
    char* m_stackSaved;
    void FUN_00c7b130();
};

// @fnv 0x00c7b130
void FUN_00c7b130_cls::FUN_00c7b130()
{
    hkMemoryRouter::getInstance().deallocateStack(m_stackSaved);
}
}  // namespace fnv_00c7b130

struct NiRTTI;


struct C7B140Object
{
    C7B140Object* DynamicCast(const NiRTTI* pkRTTI);
};

struct C7B140Collision : C7B140Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C7B140Object* m_pkWorldObject;
};

struct C7B140AVObject : C7B140Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C7B140Object* m_spCollisionObject;
};

struct C7B140Node : C7B140AVObject
{
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
    C7B140AVObject** m_ppkChildren;
    unsigned short unkA4;
    unsigned short m_usArraySize;
};


// Recursively visits the object's collision body (skipping filter collisions) and calls CollectItemValues on it, then recurses into child nodes.
// @fnv 0x00c7b140
void __cdecl ApplyToCollisionBodies(C7B140AVObject* pkObject, void* pArg1, void* pArg2)
{
    if (!pkObject)
        return;
    if (pkObject->m_spCollisionObject)
    {
        C7B140Collision* pkCollision =
            (C7B140Collision*)pkObject->m_spCollisionObject->DynamicCast(&(*reinterpret_cast<const ::NiRTTI *>(&::g_01267e64)));
        if (pkCollision)
        {
            C7B140Object* pkFilter = pkCollision->DynamicCast(&(*reinterpret_cast<const ::NiRTTI *>(&::g_0126817c)));
            if (pkCollision->m_pkWorldObject)
            {
                C7B140Object* pkBody = pkCollision->m_pkWorldObject->DynamicCast(&(*reinterpret_cast<const ::NiRTTI *>(&::g_012681c0)));
                if (pkBody && !pkFilter)
                    ::fnv_00c7a990::CollectItemValues((::fnv_00c7a990::S_item *)(pkBody), (::fnv_00c7a990::S_arr *)(pArg1), (::fnv_00c7a990::S_arr *)(pArg2));
            }
        }
    }
    C7B140Node* pkNode = (C7B140Node*)pkObject->DynamicCast(&(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4428)));
    if (pkNode)
    {
        for (unsigned int i = 0; i < pkNode->m_usArraySize; i++)
            ApplyToCollisionBodies(pkNode->m_ppkChildren[i], pArg1, pArg2);
    }
}

namespace fnv_00c7bf50 {

struct FUN_00c7bf50_cls
{
    void* m_pData;
    int m_04;
    unsigned int m_08;

    void FUN_00c7bf50();
};

// @fnv 0x00c7bf50
void FUN_00c7bf50_cls::FUN_00c7bf50()
{
    hkMemoryAllocator* alloc = &hkMemoryRouter::getInstance().heap();
    unsigned int flags = m_08;
    m_04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->bufFree(m_pData, int((flags & 0x3fffffffu) * 2));
    }
    m_pData = 0;
    m_08 = 0x80000000u;
}
}  // namespace fnv_00c7bf50

namespace fnv_00c7bf90 {

struct FUN_00c7bf90_cls
{
    void* m_pData;
    int m_04;
    unsigned int m_08;

    void ReleaseBuffer();
};

// @fnv 0x00c7bf90
void FUN_00c7bf90_cls::ReleaseBuffer()
{
    hkMemoryAllocator* alloc = &hkMemoryRouter::getInstance().heap();
    unsigned int flags = m_08;
    m_04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->bufFree(m_pData, int((flags & 0x3fffffffu) * 48));
    }
    m_pData = 0;
    m_08 = 0x80000000u;
}
}  // namespace fnv_00c7bf90

namespace fnv_00c7fc40 {
struct FNVHeapAllocator
{
};

// @fnv 0x00c7fc40
void* AllocateDoubleArray(void* address, unsigned int elementCount)
{
    return reinterpret_cast<::MemoryManager *>(&((*reinterpret_cast<::fnv_00c7fc40::FNVHeapAllocator *>(&::g_memoryManager))))->Reallocate(address, elementCount * sizeof(double));
}
}  // namespace fnv_00c7fc40

struct FUN_00c7fc60_cls
{
    virtual void* Slot0();
    virtual void* Alloc(unsigned int count);
    int* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int PushSlot();
};

// Ensures capacity by allocating or growing the buffer, then increments iSize and returns the index of the newly added slot.
// @fnv 0x00c7fc60
unsigned int FUN_00c7fc60_cls::PushSlot()
{
    if (iSize == SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = (int*)Alloc(4);
            SimpleArrayStorage = 4;
            goto tail;
        }
        unsigned int newCap = (SimpleArrayStorage > 0x400) ? SimpleArrayStorage + 0x400 : SimpleArrayStorage * 2;
        reinterpret_cast<::FUN_00c7f970_cls *>(this)->FUN_00c7f970(newCap, iSize);
        SimpleArrayStorage = newCap;
    }
tail:
    ++iSize;
    return iSize - 1;
}

extern float DAT_011afe68;
extern float DAT_011afe6c;
extern float DAT_011afe70;
extern float DAT_012677b0;
extern float DAT_012677ac;
extern unsigned int DAT_012677b4;
extern bool DAT_01267b4c;
struct SettingFloat
{
};
extern SettingFloat DAT_01267b34;

// Accumulates elapsed time, clamps it, and computes the number of simulation steps and step size according to the current time mode.
// @fnv 0x00c66760
void __cdecl FUN_00c66760(float elapsed, bool singleStep, bool force)
{
    DAT_011afe68 = elapsed;
    bool forced = force || DAT_01267b4c;
    DAT_011afe64 = elapsed + DAT_012677b0;
    if (DAT_011afe64 > 166.6666717529296875f)
        DAT_011afe64 = 166.6666717529296875f;
    if (DAT_011afe64 <= 0.0f)
    {
        DAT_012677b4 = 0;
        DAT_012677ac = 0.0f;
        return;
    }
    unsigned int maxSteps = singleStep ? 1 : 3;
    switch ((*reinterpret_cast<unsigned int *>(&::DAT_012677b8)))
    {
    case 10:
        DAT_011afe6c += (DAT_011afe64 - DAT_011afe6c) * DAT_011afe70;
        DAT_012677ac = DAT_011afe6c;
        DAT_012677b4 = 1;
        DAT_012677b0 = 0.0f;
        break;
    case 0:
        DAT_012677ac = DAT_011ac3a0 * DAT_01267b38;
        DAT_012677b4 = (unsigned int)(DAT_011afe64 / DAT_012677ac);
        if (DAT_012677b4 > maxSteps)
            DAT_012677b4 = maxSteps;
        if (DAT_012677b4)
        {
            DAT_012677b0 = DAT_011afe64 - DAT_012677b4 * DAT_012677ac;
            DAT_011afe64 -= DAT_012677b0;
            DAT_012677b0 = FUN_0040ebd0(DAT_012677b0, *((float *)&(::FUN_00403e20((float *)&(DAT_01267b34)))));
        }
        else if (!forced && DAT_011afe64 < DAT_012677ac * 0.5)
        {
            DAT_012677b0 = DAT_011afe64;
            DAT_012677ac = DAT_011afe64 = 0.0f;
        }
        else
        {
            DAT_012677ac = DAT_011afe64;
            DAT_012677b4 = 1;
            DAT_012677b0 = 0.0f;
        }
        break;
    case 2:
        DAT_012677b4 = 1;
        DAT_012677ac = elapsed;
        break;
    case 1:
    adaptive:
        if (!forced && DAT_011afe64 < 0.008333333767950534820556640625f)
        {
            DAT_012677b4 = 0;
            DAT_012677b0 = DAT_011afe64;
            DAT_012677ac = DAT_011afe64 = 0.0f;
        }
        else
        {
            DAT_012677b0 = 0.0f;
            DAT_012677b4 = (unsigned int)(DAT_011afe64 / DAT_01267b38);
            if (DAT_012677b4 > maxSteps)
                DAT_012677b4 = maxSteps;
            if (DAT_012677b4 == 0)
            {
                DAT_012677b4 = 1;
                DAT_012677ac = DAT_011afe64;
            }
            else
            {
                DAT_012677ac = DAT_011afe64 / DAT_012677b4;
            }
        }
        break;
    default:
        goto adaptive;
    }
}

struct hkBoolArg
{
    char m_cBooleanValue;
    hkBoolArg(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct OwnerA
{
    virtual void a00();
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
};
struct OwnerB
{
    virtual void b00();
};
struct Owner : OwnerA, OwnerB
{
public:
    void ClearReferences();
};

struct WorldEntry
{
    int unk00;
};

struct ChildBase
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    ChildBase(Owner* owner, int id);
    virtual ~ChildBase();
    void Attach(WorldEntry* w, hkBoolArg b, int a, int c);
    static void* operator new(std::size_t n)
    {
        ChildBase* p = (ChildBase*)hkMemoryRouter::getInstance().heap().blockAlloc(int(n));
        p->m_usMemSizeAndFlags = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p, std::size_t n);
};

struct Child : ChildBase
{
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    void* m_350;
    int unk354;
    int unk358;
    int unk35C;
    Child(Owner* owner, int id) : ChildBase(owner, id)
    {
        m_350 = 0;
    }
    virtual ~Child();
};

struct SimObject
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
    void* m_80;
};

struct Controller
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void AddChild(Child* c);
    virtual void v90();
    virtual SimObject* GetSim();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void SetOwner(OwnerB* p);
    void CreateChildAndNotifySim(OwnerB* p);
};

// @fnv 0x00c66c90
void Controller::CreateChildAndNotifySim(OwnerB* p)
{
    ThreadMemoryScope scope;
    Owner* owner = static_cast<Owner*>(p);
    Child* child = new Child(owner, 0x111d4);
    if ((*reinterpret_cast<::WorldEntry * *>(&::g_pkWorldListenerC68)))
        child->Attach((*reinterpret_cast<::WorldEntry * *>(&::g_pkWorldListenerC68)), true, 0, 1);
    AddChild(child);
    reinterpret_cast<::hkReferencedObjectC905 *>((child))->FUN_00c905b0();
    SetOwner(p);
    SimObject* sim = GetSim();
    if (sim)
        ::InitializeWorld((::WorldCBFD *)(sim->m_80));
}

struct BC66F10FilterBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiFilterInfo;
};

struct BC66F10Pad
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct BC66F10WorldObject : public BC66F10Pad, public BC66F10FilterBase
{
};

class BC66F10RefObject
{
  public:

    int unk00;
    int unk04;
    BC66F10WorldObject* m_pkWorldObject;
};

struct BC66F10Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiSystemGroup;
};


// Resolves a system group from the object's filter info or the entry's group, stores it on the entry and applies it via SetSystemGroup.
// @fnv 0x00c66f10
bool __cdecl AssignSystemGroup(BC66F10RefObject* pkObject, BC66F10Entry* pkEntry)
{
    bool bAssigned = false;
    BC66F10FilterBase* pkFilter = pkObject->m_pkWorldObject;
    unsigned int uiFilterInfo = pkFilter ? pkFilter->m_uiFilterInfo : 0;
    unsigned int uiRenderPassIndex = uiFilterInfo >> 16;
    if (pkEntry->m_uiSystemGroup == 0)
    {
        if (uiRenderPassIndex == 0)
        {
            uiRenderPassIndex = (*reinterpret_cast<unsigned int (*)[]>(&::fnv_00c828f0::DAT_01267e70))[uiFilterInfo & 0x7f];
            if (uiRenderPassIndex == 0)
            {
                ::DAT_011b0808 = (::DAT_011b0808 + 1) & 0xffff;
                if (::DAT_011b0808 == 0)
                    ::DAT_011b0808 = 10;
                uiRenderPassIndex = ::DAT_011b0808;
            }
            bAssigned = true;
        }
        pkEntry->m_uiSystemGroup = uiRenderPassIndex;
    }
    else
    {
        bAssigned = true;
    }
    if (bAssigned)
        reinterpret_cast<::S_00c85ce0 *>((pkObject))->FUN_00c85ce0(pkEntry->m_uiSystemGroup);
    return bAssigned;
}

__declspec(thread) int g_tlsMemContext_00c67850 = 0x3b;

struct ScopedMemContext_00c67850
{
    int m_old;
    ScopedMemContext_00c67850(int val)
    {
        m_old = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = val;
    }
    ~ScopedMemContext_00c67850()
    {
        g_tlsBlock.memoryContext = m_old;
    }
};


struct WorldImpl : public FUN_00c6b320_Base
{
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
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    ConstraintItem** m_ppData;
    unsigned int m_uiItemCount;

    ConstraintItem*& GetAt(unsigned int i)
    {
        return m_ppData[i];
    }
};

// @fnv 0x00c67850
void FUN_00c67850_Class::ProcessConstraints()
{
    WorldImpl* self = (WorldImpl*)this;
    ScopedMemContext_00c67850 ctx(16);
    if (self->m_uiItemCount > 0 && self->m_30 == 0)
    {
        if (self->m_uiItemCount >= 200)
        {
            self->m_uiItemCount = 200;
        }
        FUN_00c97d30_Class* pWorld = (FUN_00c97d30_Class*)self->v37();
        if (pWorld)
        {
            for (unsigned int i = 0; i < self->m_uiItemCount; ++i)
            {
                if (self->GetAt(i))
                {
                    ConstraintItem* item = self->GetAt(i);
                    if (item->m_pOwner == 0 && (!item->m_14 || item->m_14->m_pSimulationIsland != 0) &&
                        (!item->m_18 || item->m_18->m_pSimulationIsland != 0))
                    {
                        reinterpret_cast<::Mgr *>((pWorld))->FUN_00c97d30((::Item *)(item));
                    }
                }
                if (self->GetAt(i))
                {
                    reinterpret_cast<::hkReferencedObjectC905 *>((self->GetAt(i)))->FUN_00c905b0();
                }
            }
            std::memset(self->m_ppData, 0, self->m_uiItemCount * sizeof(ConstraintItem*));
            self->m_uiItemCount = 0;
        }
    }
}

struct C687B0AllocTagScope
{
    int m_iSaved;

    C687B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = aiAllocationTag;
    }
    ~C687B0AllocTagScope()
    {
        g_tlsBlock.memoryContext = m_iSaved;
    }
};

class C687B0ObjectBase
{
  public:
    virtual ~C687B0ObjectBase();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};

class C687B0Listener
{
};

class C687B0Object : public C687B0ObjectBase, public C687B0Listener
{
  public:
    C687B0Object();

    static void* operator new(std::size_t uiSize)
    {
        void* p = hkMemoryRouter::getInstance().heap().blockAlloc(int(uiSize));
        static_cast<C687B0Object*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);
};

struct C687B0World
{
};

class C687B0Owner
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual C687B0World* GetWorld();

    int unk04;
    void* m_pkActive;
    C687B0Listener* m_pkListener;

    C687B0Listener* GetOrCreateListener(bool* pbCreated);
};

// @fnv 0x00c687b0
C687B0Listener* C687B0Owner::GetOrCreateListener(bool* pbCreated)
{
    C687B0AllocTagScope kScope(0x10);
    *pbCreated = (m_pkListener == 0);
    if (*pbCreated)
    {
        m_pkListener = new C687B0Object();
        if (m_pkActive)
        {
            C687B0Object* pkObject = static_cast<C687B0Object*>(m_pkListener);
            C687B0World* pkWorld = GetWorld();
            if (pkWorld)
                reinterpret_cast<::Src_00c91c50 *>((pkWorld))->FUN_00c91c50((::Dst_00c91c50 *)(pkObject));
        }
    }
    return m_pkListener;
}


class CC68B50Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};


class CC68B50Object
{
  public:
    virtual ~CC68B50Object();

    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }

    volatile long m_lRefCount;
};

class CC68B50Pointer
{
  public:
    CC68B50Pointer(const CC68B50Pointer& kOther) throw()
    {
        m_pPointer = kOther.m_pPointer;
        if (m_pPointer)
            m_pPointer->IncRefCount();
    }

    CC68B50Pointer& operator=(const CC68B50Pointer& kOther);
    operator CC68B50Object*() const
    {
        return m_pPointer;
    }

    CC68B50Object* m_pPointer;
};

struct CC68B50Node
{

    CC68B50Node(const CC68B50Pointer& spRetainedObject) throw() : m_pReferencedObject(spRetainedObject), m_pkNext(0)
    {}

    CC68B50Pointer m_pReferencedObject;
    CC68B50Node* m_pkNext;
};

class CC68B50Stack
{
  public:
    CC68B50Pointer m_spTop;
    CC68B50Node* m_pkNext;

    void Push(const CC68B50Pointer& spRetainedObject);
};

// @fnv 0x00c68b50
void CC68B50Stack::Push(const CC68B50Pointer& apObject)
{
    if (apObject)
    {
        if (m_spTop)
        {
            CC68B50Node* pkNode = new CC68B50Node(m_spTop);
            pkNode->m_pkNext = m_pkNext;
            m_pkNext = pkNode;
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::CC68B50Pointer &)(m_spTop))->operator=((const ::FUN_00c663d0 &)(apObject));
        }
        else
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::CC68B50Pointer &)(m_spTop))->operator=((const ::FUN_00c663d0 &)(apObject));
        }
    }
}

struct C68CB0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char m_ucFlags;
};

class C68CB0Phantom
{
  public:
    void RetainReference();

    int unk00;
    int unk04;
    int unk08;
    C68CB0Collidable* m_pkCollidable;
};

struct C68CB0Result
{
    C68CB0Result(const C68CB0Result& kOther);

    int m_iValue;
};

class C68CB0HavokWorld
{
  public:
};

class C68CB0World
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual C68CB0HavokWorld* GetHavokWorld();


    bool FUN_00c68cb0(C68CB0Phantom* pkPhantom);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchLock;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    C68CB0Phantom** m_ppkPendingPhantoms;
    unsigned int m_uiNumPendingPhantoms;
};

// @fnv 0x00c68cb0
bool C68CB0World::FUN_00c68cb0(C68CB0Phantom* pkPhantom)
{
    bool bResult = false;
    C68CB0HavokWorld* pkWorld = GetHavokWorld();
    if (pkWorld && pkPhantom)
    {
        bResult = true;
        if (m_uiBatchLock > 0)
        {
            C68CB0Collidable* pkCollidable = pkPhantom->m_pkCollidable;
            if (pkCollidable && !(pkCollidable->m_ucFlags & 0x30))
            {
                pkCollidable->m_ucFlags |= 0x20;
                if (m_uiNumPendingPhantoms >= 200)
                {
                    reinterpret_cast<::fnv_00c67df0::PendingWorld *>(this)->ProcessPendingItems();
                    reinterpret_cast<::WorldView *>(this)->ReleaseBodies();
                    reinterpret_cast<::Owner *>(this)->ClearReferences();
                    reinterpret_cast<::FUN_00c67aa0_Class *>(this)->FlushEntries();
                }
                reinterpret_cast<::FUN_00c90510_class *>((pkPhantom))->FUN_00c90510();
                m_ppkPendingPhantoms[m_uiNumPendingPhantoms++] = pkPhantom;
                return bResult;
            }
        }
        else
        {
            C68CB0Collidable* pkCollidable = pkPhantom->m_pkCollidable;
            if (pkCollidable && !(pkCollidable->m_ucFlags & 0x30))
                reinterpret_cast<::WorldC92C *>((pkWorld))->FUN_00c92c70((::ActionC92C *)(pkPhantom));
        }
    }
    return bResult;
}

class C68D50Entity
{
  public:
    void RetainReference();
};

struct C68D50Result
{
    C68D50Result(const C68D50Result& kOther);

    int m_iValue;
};

class C68D50HavokWorld
{
  public:
    C68D50Result RegisterEntity(C68D50Entity* pkEntity);
};

class C68D50World
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual C68D50HavokWorld* GetHavokWorld();


    bool FUN_00c68d50(C68D50Entity* pkEntity);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchLock;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    C68D50Entity** m_ppkPendingEntities;
    unsigned int m_uiNumPendingEntities;
};
// @fnv 0x00c7a230
void FUN_00c7a230_cls::FUN_00c7a230(bool abActive)
{
    ListOwner* owner = m_48;
    int firstFlag = (owner->m_14[0] != 0) ? owner->m_14[0]->m_08 : 0;
    ListLevel1* lv = owner->m_08;
    ListLevel2* l2 = lv->m_00;
    if (l2 == 0)
    {
        return;
    }
    ListLevel3* d = l2->m_08;
    if (d == 0)
    {
        return;
    }
    if (abActive)
    {
        if (firstFlag != 0)
        {
            return;
        }
    }
    else
    {
        if (firstFlag == 0)
        {
            return;
        }
    }
    ListMgr* mgr = d->m_350;
    if (abActive)
    {
        for (int i = 0; i < owner->m_18; ++i)
        {
            ListItem* item = owner->m_14[i];
            if (item->m_08 == 0)
            {
                reinterpret_cast<::FUN_00c6b320_Class *>((mgr))->FUN_00c6b320((::hkReferencedObject *)(item));
            }
        }
    }
    else
    {
        for (int i = 0; i < owner->m_18; ++i)
        {
            ListItem* item = owner->m_14[i];
            if (item->m_08 != 0)
            {
                reinterpret_cast<::C68D50World *>((mgr))->FUN_00c68d50((::C68D50Entity *)(item));
            }
        }
    }
}

// @fnv 0x00c68d50
bool C68D50World::FUN_00c68d50(C68D50Entity* pkEntity)
{
    bool bResult = false;
    C68D50HavokWorld* pkWorld = GetHavokWorld();
    if (pkWorld && pkEntity)
    {
        if (m_uiBatchLock > 0)
        {
            if (m_uiNumPendingEntities >= 200)
            {
                reinterpret_cast<::fnv_00c67df0::PendingWorld *>(this)->ProcessPendingItems();
                reinterpret_cast<::WorldView *>(this)->ReleaseBodies();
                reinterpret_cast<::Owner *>(this)->ClearReferences();
                reinterpret_cast<::FUN_00c67aa0_Class *>(this)->FlushEntries();
            }
            reinterpret_cast<::FUN_00c90510_class *>((pkEntity))->FUN_00c90510();
            m_ppkPendingEntities[m_uiNumPendingEntities++] = pkEntity;
        }
        else
        {
            pkWorld->RegisterEntity(pkEntity);
        }
        bResult = true;
    }
    return bResult;
}

struct StrArr
{
    int vtable;
    char** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short count;
    unsigned short grow;
    void SetSize(unsigned int);
    void Append(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + grow);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
};
extern int DAT_01268238;
struct ReportBool
{
    bool value;
    ReportBool(bool b) : value(b)
    {}
};
struct ReportOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* debug;
    unsigned char unk14;
    bool enabled;
    void AppendReport(StrArr*);
};
// @fnv 0x00c69240
void ReportOwner::AppendReport(StrArr* result)
{
    ThreadMemoryScope scope;
    reinterpret_cast<::FUN_00c878c0_cls *>(this)->FUN_00c878c0((::BC878C0StringArray *)(result));
    result->Append(FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_01267824))));
    ReportBool enabledValue(enabled);
    result->Append(::FUN_00a7d370("Enabled", (*(bool *)&(const ::ReportBool &)(enabledValue))));
    ReportBool debugValue(debug != 0);
    result->Append(::FUN_00a7d370("Vis Debug", (*(bool *)&(const ::ReportBool &)(debugValue))));
    result->Append(FUN_00a7d510("Worlds", (*reinterpret_cast<unsigned int *>(&::DAT_012677a4))));
    result->Append(FUN_00a7d510("Actions", (*reinterpret_cast<unsigned int *>(&::DAT_01268154))));
    result->Append(FUN_00a7d510("Contraints", DAT_01268188));
    result->Append(FUN_00a7d510("Entities", (*reinterpret_cast<unsigned int *>(&::DAT_012681fc))));
    result->Append(FUN_00a7d510("RigidBodies", (*reinterpret_cast<unsigned int *>(&::DAT_012681bc))));
    result->Append(FUN_00a7d510("Shapes", DAT_012680f8));
    result->Append(FUN_00a7d510("Phantoms", DAT_01268238));
    result->Append(FUN_00a7d510("MoppBVTreeShapes", ::CCA1B0Level3::ms_uiInstances));
}

class NiAVObject;
class NiCollisionObject;

struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    float fValue;
    int unk;
    int unkCur;
    int unkValue;
};

typedef void (*CollisionObjectCountCallback)(NiCollisionObject*, CollisionObjectCountContext*);
extern CollisionObjectCountCallback DAT_011afec8;

// If pkObject is non-null and enabled (or bForce), fills a context with fValue and traversal flags and runs the collision-object callback over it.
// @fnv 0x00c6a190
bool ApplyCollisionObjectCount(NiAVObject* pkObject, float fValue, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A2E0IsEnabled((C6A2E0AVObject*)pkObject)))
    {
        CollisionObjectCountContext kContext;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 0x10;
        kContext.fValue = fValue;
        if (DAT_011afec8)
            ::FUN_00c68900((::S_00c68900_Node *)(pkObject), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(&kContext), (void (*)(void *, S_00c68900_Context *))(DAT_011afec8));
    }
    return bResult;
}

template <class T, class Allocator> class NiTPrimitiveArray
{
  public:
    virtual ~NiTPrimitiveArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, T& value);
    void Add(T value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
};
typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > ViewerStringArray;

struct ViewerSceneObject
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
    float m_vScale;
};
class ViewerCollision
{
  public:
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
    virtual bool IsKeyframed();
    unsigned int m_iObjectReferenceCount;
    ViewerSceneObject* m_sceneObject;
    unsigned short m_flags;
    void* m_pEntity;
    bool GetActive() const
    {
        return (m_flags & 1) != 0;
    }
    bool GetReset() const
    {
        return (m_flags & 64) != 0;
    }
    bool GetNotify() const
    {
        return (m_flags & 4) != 0;
    }
    bool GetSetLocal() const
    {
        return (m_flags & 8) != 0;
    }
    bool GetFaceDown() const
    {
        bool faceDown = false;
        if (m_sceneObject)
            faceDown = m_sceneObject->m_vScale < 0.0f;
        return faceDown;
    }
    void AppendDebugInfo(ViewerStringArray* strings);
};
// Appends collision debug strings: base info, bhkWorldObject pointer, and the active/reset/notify/setlocal/keyframe/facedown flags.
// @fnv 0x00c6c430
void ViewerCollision::AppendDebugInfo(ViewerStringArray* strings)
{
    ThreadMemoryScope memoryScope;
    reinterpret_cast<::ClaimCls *>(this)->WriteToStream((*(::StreamShell *)(strings)));
    strings->Add(FUN_00a7d330(reinterpret_cast<const char*>((*reinterpret_cast<int *>(&::g_01267b70)))));
    char buffer[32];
    FUN_00406d00(buffer, 32, "0x%8X", m_pEntity);
    strings->Add(::fnv_00a7d5e0::FUN_00a7d5e0("bhkWorldObject", buffer));
    strings->Add(FUN_00a7d370("bActive", GetActive()));
    strings->Add(FUN_00a7d370("bReset", GetReset()));
    strings->Add(FUN_00a7d370("bNotify", GetNotify()));
    strings->Add(FUN_00a7d370("bSetLocal", GetSetLocal()));
    strings->Add(FUN_00a7d370("bKeyframe", IsKeyframed()));
    strings->Add(FUN_00a7d370("bFaceDown", GetFaceDown()));
}

// Whether the world's constraint list contains an entry for the given object (checked under the world lock).

struct D8A0Entry
{
    void* m_pvObject;
    int unk04;
    int unk08;
    int unk0C;
};

struct D8A0World
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
    D8A0Entry* m_pkEntryArray;
    int m_iArrayLength;

    bool Contains(void* pvObject) const
    {
        for (int i = 0; i < m_iArrayLength; i++)
        {
            if (m_pkEntryArray[i].m_pvObject == pvObject)
                return true;
        }
        return false;
    }
};

class D8A0Wrapper
{
  public:
    int unk00;
    int unk04;
    D8A0World* m_pkWorld;

    bool ContainsObject(void* pvObject);
};

// Locks the wrapper, checks whether m_pkWorld contains pvObject, unlocks, and returns whether it was found.
// @fnv 0x00c6d8a0
bool D8A0Wrapper::ContainsObject(void* pvObject)
{
    D8A0World* pkWorld = m_pkWorld;
    bool bFound = false;
    if (pkWorld)
    {
        ::FUN_00a29680();
        bFound = pkWorld->Contains(pvObject);
        ::FUN_00a29680();
    }
    return bFound;
}


struct BC6DF60AllocTagScope
{
    int m_iSaved;

    BC6DF60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = aiAllocationTag;
    }
    ~BC6DF60AllocTagScope()
    {
        g_tlsBlock.memoryContext = m_iSaved;
    }
};

class BC6DF60Phantom
{
  public:
    void* operator new(std::size_t uiNumBytes) throw()
    {
        return hkMemoryRouter::getInstance().heap().blockAlloc(int(uiNumBytes));
    }
    void operator delete(void* pvMem)
    {
        hkMemoryRouter::getInstance().heap().blockFree(pvMem, sizeof(BC6DF60Phantom));
    }

    BC6DF60Phantom(bool bFlag);

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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
};

class BC6DF60Wrapper
{
  public:
    BC6DF60Phantom* GetOrCreatePhantom(bool* pbCreated);

    int unk00;
    int unk04;
    void* m_pkWorld;
    BC6DF60Phantom* m_pkPhantom;
};

// Returns m_pkPhantom, creating it and linking it to m_pkWorld when absent, and stores whether it was created in *pbCreated.
// @fnv 0x00c6df60
BC6DF60Phantom* BC6DF60Wrapper::GetOrCreatePhantom(bool* pbCreated)
{
    BC6DF60AllocTagScope kScope(0x10);
    bool bCreate = m_pkPhantom == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        m_pkPhantom = new BC6DF60Phantom(true);
        if (m_pkWorld)
            reinterpret_cast<::FUN_00cabfd0_Obj *>(this)->FUN_00cabfd0((intptr_t)(m_pkPhantom));
    }
    return m_pkPhantom;
}

// Apply the current water settings: scaled shader parameters and the quarter-size reflection dimensions.


struct C75910Settings
{
    int unk00;
    int unk04;
    int unk08;
    float m_fAmplitude;
    float m_fEmissionSpeed;
    int unk14;
    float m_fFogDepth;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
};

struct C75910Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    C75910Settings* m_pkSettings;
};

struct C75910ShaderParams
{
    int unk00;
    int unk04;
    int unk08;
    float m_fEmissionSpeed;
    float m_fAmplitude;
    int unk14;
    int unk18;
    float m_fFogDepth;
};

class C75910Water
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    C75910ShaderParams** m_ppkParams;
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    unsigned int m_uiReflectHeight;
    unsigned int m_uiReflectWidth;
    int unk2A0;
    C75910Source* m_pkSource;

    void UpdateShaderParams();
};

// Copies scaled settings from m_pkSource->m_pkSettings into the shader params and computes reflection width/height as a quarter of the settings values.
// @fnv 0x00c75910
void C75910Water::UpdateShaderParams()
{
    if (!m_pkSource->m_pkSettings)
        return;

    C75910ShaderParams* pkParams = *m_ppkParams;
    pkParams->m_fEmissionSpeed = (float)(m_pkSource->m_pkSettings->m_fEmissionSpeed * ::DAT_010290d0);
    pkParams->m_fAmplitude = (float)(m_pkSource->m_pkSettings->m_fAmplitude * 0.10000000149011612);
    pkParams->m_fFogDepth = (float)(m_pkSource->m_pkSettings->m_fFogDepth * ::_DAT_01012060);
    m_uiReflectWidth = (unsigned int)((float)m_pkSource->m_pkSettings->m_uiImageWidth * 0.25);
    m_uiReflectHeight = (unsigned int)((float)m_pkSource->m_pkSettings->m_uiImageHeight * 0.25);
}

struct MapBase_StandIn
{
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    virtual ~MapBase_StandIn()
    {
        reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
};

struct FUN_00c75d90 : MapBase_StandIn
{
    virtual ~FUN_00c75d90();
};

// Destructor that calls RemoveAll on the map base to clear all entries.
// @fnv 0x00c75d90
FUN_00c75d90::~FUN_00c75d90()
{
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
}


class MemberC76
{
  public:
    MemberC76();
    ~MemberC76();

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30;
};

class ElementC76
{
  public:
    ElementC76() : m_iValue(0)
    {}

    int m_iValue;
    MemberC76 m_kMember;
};

// @fnv 0x00c760f0
void ConstructElementArray(ElementC76* pkArray, uintptr_t ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) ElementC76;
}

struct NiRTTI;
struct FilterInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int flags;
};
struct PhysicsWorldObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FilterInfo collidable;
};
struct PhysicsBody
{
    int unk00;
    int unk04;
    PhysicsWorldObject* world;
    FilterInfo* GetCollidable()
    {
        return world ? &world->collidable : 0;
    }
};
struct NiObject
{
  public:
    NiObject* DynamicCast(const NiRTTI*);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    PhysicsBody* body;
public:
    void *FUN_00621a40();
};
// @fnv 0x00c70830
void ControllerShell::SetMode(int mode)
{
    if (selectedMode() != mode && mode < 2 && availableMode(mode) != 0)
    {
        bool paused = (flags() >> 15) & 1;
        if (paused)
            static_cast<::FUN_00c6ffc0_Class *>(nullptr)->FUN_00c6ffc0();
        selectedMode() = mode;
        // FUN_00c6d3f0 ignores its second argument; the release passes the FUN_00621a40 result there.
        void* pkUnused = reinterpret_cast<::NiObject *>(this)->FUN_00621a40();
        reinterpret_cast<::HostClass *>(this)->FUN_00c6d3f0((::ArgClass *)reinterpret_cast<::Holder *>(this)->GetCurrentObject(), (int)(std::intptr_t)pkUnused);
        if (paused)
            CallVirtualReset(0);
    }
}
struct SearchNode;
struct SearchObject
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual SearchNode* GetNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiObject* collision;
};
struct SearchNode : SearchObject
{
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
    SearchObject** children;
    unsigned short capacity;
    unsigned short count;
};
// Recursively searches object and its child nodes for a PhysicsBody whose collidable layer field equals layer, returning it or null.
// @fnv 0x00c7ff40
PhysicsBody* __cdecl FindPhysicsBodyByLayer(SearchObject* object, unsigned int layer)
{
    PhysicsBody* result = 0;
    if (object)
    {
        if (object->collision)
        {
            NiObject* collision = object->collision->DynamicCast((const NiRTTI*)(*reinterpret_cast<const char (*)[]>(&::g_012043f8)));
            if (collision)
            {
                PhysicsBody* body = collision->body;
                if (body)
                {
                    FilterInfo* collidable = body->GetCollidable();
                    unsigned int flags = collidable ? collidable->flags : 0;
                    if (((flags >> 8) & 31) == layer)
                        return body;
                }
            }
        }
        SearchNode* node = object->GetNode();
        if (node)
        {
            unsigned int i = 0;
            while (!result)
            {
                if (i >= node->count)
                    break;
                SearchObject* child = node->children[i];
                result = FindPhysicsBodyByLayer(child, layer);
                ++i;
            }
        }
    }
    return result;
}

extern char DAT_012677a1;
extern CollisionObjectCountCallback DAT_011afeb0;
struct S_00c69e10_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_00c69e10_Ctx
{
    void* owner;
    bool kind;
    int type;
    int flag;
    int value;
    int unk14;
    int one;
};
static inline unsigned int C69E10IsEnabled(S_00c69e10_Obj* o)
{
    C6A2E0Properties* info = ((::C6A2E0Properties *)(::GetExtraDataChecked((::NiAVObjectX *)(::C6A2E0AVObject *)((C6A2E0AVObject*)o))));
    return info ? (info->m_uiValue1 & 2) : 0;
}
struct S_00c69e10_This
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    char unk14;
    bool SetCollisionObjectFlag(S_00c69e10_Obj* obj, bool kind, bool f, int value, bool force);
};
// If obj is non-null and enabled (or force is set), builds a context from kind, f and value and dispatches it through the collision-object callbacks.
// @fnv 0x00c69e10
bool S_00c69e10_This::SetCollisionObjectFlag(S_00c69e10_Obj* obj, bool kind, bool abFlag, int value, bool force)
{
    bool ret = false;
    if (obj != 0)
    {
        bool ok = force;
        if (!ok)
        {
            if (C69E10IsEnabled(obj) != 0)
                ok = true;
        }
        if (ok)
        {
            S_00c69e10_Ctx r;
            unk14 = 1;
            r.owner = this;
            r.kind = kind;
            if (DAT_012677a1)
            {
                r.type = 10;
                if (DAT_011afeb0)
                    ::FUN_00c68900((::S_00c68900_Node *)(::NiAVObject *)((NiAVObject*)obj), (::S_00c68900_Context *)(::CollisionObjectCountContext *)((CollisionObjectCountContext*)&r), (void (*)(void *, S_00c68900_Context *))(DAT_011afeb0));
            }
            int fl = abFlag != 0;
            if (obj->unk1c == 0)
                fl = 0;
            r.flag = fl;
            r.type = 0;
            r.value = value;
            r.unk14 = 0;
            r.one = 1;
            if ((*reinterpret_cast<void (**)(NiCollisionObject *, CollisionObjectCountContext *)>(&::DAT_011afe88)))
                ::FUN_00c68900((::S_00c68900_Node *)(::NiAVObject *)((NiAVObject*)obj), (::S_00c68900_Context *)(::CollisionObjectCountContext *)((CollisionObjectCountContext*)&r), (void (*)(void *, S_00c68900_Context *))((*reinterpret_cast<void (**)(NiCollisionObject *, CollisionObjectCountContext *)>(&::DAT_011afe88))));
            ret = true;
        }
    }
    return ret;
}

struct S_c6c1d0_Target
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
    unsigned char m_type;
};

struct S_c6c1d0_Link
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_offset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_kind;
};

struct S_c6c1d0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_c6c1d0_Link m_link;
};

struct S_c6c1d0_Holder
{
    int unk00;
    int unk04;
    S_c6c1d0_Node* m_node;
};

struct S_c6c1d0_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_c6c1d0_Holder* m_holder;

    __forceinline static S_c6c1d0_Target* FindTarget(S_c6c1d0_Holder* holder)
    {
        S_c6c1d0_Node* node = holder->m_node;
        S_c6c1d0_Link* link = 0;
        if (node != 0)
            link = &node->m_link;
        if (link->m_kind != 1)
            return 0;
        return (S_c6c1d0_Target*)((char*)link + link->m_offset);
    }

    bool FUN_00c6c1d0();
};

// Finds the target via m_holder and returns true when its m_type is 4 or 5, otherwise false (true when no target).
// @fnv 0x00c6c1d0
bool S_c6c1d0_Cls::FUN_00c6c1d0()
{
    bool result = true;
    S_c6c1d0_Target* target = this->m_holder ? FindTarget(this->m_holder) : 0;
    if (target)
    {
        unsigned int type = target->m_type;
        if (type == 4 || type == 5)
            result = true;
        else
            result = false;
    }
    return result;
}

struct Group148;
struct Scene148
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Group148* AsGroup();
    int unk04;
    char* name;
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
    Group148* FUN_00653290(const void* rtti);
};
struct Group148 : Scene148
{
    Scene148** children;
    unsigned short capacity, count;
};
struct Container148
{
};
struct FUN_00c6e0b0_Class
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    Container148* m_594;

    void* FUN_00c6e0b0();
};

struct Owner134
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual intptr_t Query(void**);
};
struct Entry134
{
    int unk00, unk04;
    Owner134* owner;
};
struct List134
{
    int unk00, unk04, unk08, unk0c;
    Entry134* head;
};
struct State134
{
    int unk00, unk04;
    List134* list;
};
struct Input134
{
};
struct Node134
{
    int unk00, unk04, unk08, unk0c;
    State134* state;
};
__forceinline Owner134* Resolve134(Input134* input)
{
    Node134* node;
    State134* state;
    List134* list;
    Entry134** slot;
    Entry134* first;
    if (!input)
        goto absent;
    node = ((::Node134 *)(::FUN_00c802d0((::MyNode *)(input))));
    if (!node)
        goto absent;
    state = node->state;
    if (!state)
        goto absent;
    list = state->list;
    if (!list)
        goto absent;
    ::FUN_00a29680();
    slot = &list->head;
    ::FUN_00a29680();
    if (!slot)
        goto absent;
    first = *slot;
    return first ? first->owner : 0;
absent:
    return 0;
}
// @fnv 0x00c75180
intptr_t FUN_00c75180(Input134* input)
{
    Owner134* owner = Resolve134(input);
    intptr_t result = 0;
    if (owner)
        result = owner->Query((void**)&input);
    return result;
}

namespace fnv_00c66240 {
class NiAVObject
{
  public:
    void FUN_00c66240(NiObject* a);
};
// Calls FUN_00c87c50 with the given NiObject.
// @fnv 0x00c66240
void NiAVObject::FUN_00c66240(NiObject* a)
{
    reinterpret_cast<::FUN_00c87c50_cls *>(this)->FUN_00c87c50(a);
}
}  // namespace fnv_00c66240

// 0x00c66300  inc dword [ecx+0x18]; ret
struct C00c66300
{
    char pad00[0x18];
    int m18;
    void FUN_00c66300();
};

// @fnv 0x00c66300
void C00c66300::FUN_00c66300()
{
    ++m18;
}

struct FUN_00c66310_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void FUN_00c66310();
};

// @fnv 0x00c66310
void FUN_00c66310_class::FUN_00c66310()
{
    ++unk1c;
}

extern "C" S_00c68900_Callback DAT_011afec4;

static inline unsigned int C6A120IsEnabled(intptr_t object)
{
    DispatchState* pkState = ((::DispatchState *)(::GetExtraDataChecked((::NiAVObjectX *)(object))));
    return pkState ? (pkState->flags & 2) : 0;
}

// @fnv 0x00c6a120
bool __cdecl SetSelectionValue(intptr_t object, float value, unsigned char mode, unsigned char overrideCheck)
{
    bool bResult = false;
    if (object)
    {
        if (overrideCheck || C6A120IsEnabled(object))
        {
            bResult = true;
            DispatchPacket kPacket;
            kPacket.status = 0;
            kPacket.mode = mode;
            kPacket.opcode = 0xf;
            *(float*)&kPacket.selection = value;
            if (DAT_011afec4)
                ::FUN_00c68900((::S_00c68900_Node *)(object), (::S_00c68900_Context *)(::DispatchPacket *)(&kPacket), DAT_011afec4);
        }
    }
    return bResult;
}

// @fnv 0x00c6b5e0
void __cdecl FUN_00c6b5e0()
{
    static_cast<::NiCollisionObject *>(nullptr)->SetSceneObject({});
}

inline float AH_fabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float AH_acosf(float _X)
{
    return ((float)acos((double)_X));
}
inline float AH_fabs(float _X)
{
    return (AH_fabsf(_X));
}
inline float AH_acos(float _X)
{
    return (AH_acosf(_X));
}

namespace AHMath {
inline float fabs(float r)
{
    return AH_fabs(r);
}
inline float acos(float r)
{
    if (AHMath::fabs(r) >= 1.0f)
    {
        r = (r > 0) ? 0 : 3.14159265358979f;
        return r;
    }
    return AH_acos(r);
}
}

struct C74C20Quat
{
    float m_vec[4];
    float GetAngle() const;
};

// Returns twice the arc-cosine of the absolute value of m_vec[3], clamped by AHMath::acos.
// @fnv 0x00c74c20
float C74C20Quat::GetAngle() const
{
    float angle = AHMath::fabs(m_vec[3]);
    angle = AHMath::acos(angle);
    angle *= 2.0f;
    return angle;
}

struct MM
{
    void* Allocate(unsigned int);
};
struct FUN_00c7be90_obj
{
    int unk00;
    int unk04;
    int m_08;
};
// @fnv 0x00c7be90
void* FUN_00c7be90()
{
    void* p = reinterpret_cast<::MemoryManagerStandIn *>(&(((MM&)(*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager)))))->FUN_00aa3e40(sizeof(FUN_00c7be90_obj));
    if (p)
        static_cast<FUN_00c7be90_obj*>(p)->m_08 = 0;
    else
        p = 0;
    return p;
}

struct FUN_00c7bf10_cls
{
    void* m_obj;
    int m_flags;
    int m_uiContentCount;
    void FUN_00c7bf10();
};

// @fnv 0x00c7bf10
void FUN_00c7bf10_cls::FUN_00c7bf10()
{
    hkMemoryAllocator* obj = &hkMemoryRouter::getInstance().heap();
    int state = m_uiContentCount;
    m_flags = 0;
    if ((state & 0x80000000) == 0)
    {
        obj->bufFree(m_obj, (state & 0x3fffffff) * 8);
    }
    m_obj = 0;
    m_uiContentCount = 0x80000000;
}

// If pkObject is enabled, calls FUN_00c68900 with pkContext and pfnCallback and returns true; otherwise returns false.
// @fnv 0x00c68ec0
bool FUN_00c68ec0(C6A2E0AVObject* pkObject, CollisionObjectCountContext* pkContext,
                  CollisionObjectCountCallback pfnCallback)
{
    bool bHandled = false;
    if (pkObject)
    {
        if (C6A2E0IsEnabled(pkObject))
        {
            bHandled = true;
            ::FUN_00c68900((::S_00c68900_Node *)(::NiAVObject *)((NiAVObject*)pkObject), (::S_00c68900_Context *)(pkContext), (void (*)(void *, S_00c68900_Context *))(pfnCallback));
        }
    }
    return bHandled;
}

struct S69580_Scope
{
    int old;
    S69580_Scope() : old(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }
    ~S69580_Scope()
    {
        g_tlsBlock.memoryContext = old;
    }
};
struct S69580_Ref
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
    void AcquireReference()
    {
        InterlockedIncrement(&refs);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct S69580_Ptr
{
    S69580_Ref* p;
    S69580_Ptr(S69580_Ref* o) : p(o)
    {
        if (p)
            p->AcquireReference();
    }
    ~S69580_Ptr()
    {
        if (p)
            p->DecRef();
    }
};
struct S69580_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S69580_Ref* owner;
};
struct S69580_Queue
{
    S69580_Ref* last;
    int num;
    void RemoveKey(S69580_Ptr* key);
};
void S69580_Insert(S69580_Queue* q, S69580_Ref* r);
__declspec(noinline) void S69580_Queue::RemoveKey(S69580_Ptr* key)
{
    S69580_Insert(this, key->p);
}
struct S69580_Access
{
};
struct S69580_World
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
    virtual S69580_Access* GetAccess();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S69580_Item** items;
    unsigned int count;
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
    S69580_Queue queue;
    bool AddItem(S69580_Item* item);
};
// Adds an item to the world's pending list, flushing it when full, or dispatches it via the access object.
// @fnv 0x00c69580
bool S69580_World::AddItem(S69580_Item* item)
{
    S69580_Scope scope;
    bool result = false;
    S69580_Access* access = GetAccess();
    if (access && item)
    {
        S69580_Ref* owner = item->owner;
        if (owner)
        {
            S69580_Ptr key(owner);
            reinterpret_cast<::FUN_00c68f50_cls *>(&(queue))->RemoveKey((::FUN_00c663d0_Ref **)(::S69580_Ptr *)(&key));
        }
        if (unk1c > 0)
        {
            if (count >= 100)
            {
                reinterpret_cast<::fnv_00c67df0::PendingWorld *>(this)->ProcessPendingItems();
                reinterpret_cast<::WorldView *>(this)->ReleaseBodies();
                reinterpret_cast<::Owner *>(this)->ClearReferences();
                reinterpret_cast<::FUN_00c67aa0_Class *>(this)->FlushEntries();
            }
            reinterpret_cast<::FUN_00c90510_class *>((item))->FUN_00c90510();
            items[count++] = item;
        }
        else
        {
            reinterpret_cast<::FUN_00c97f50_Class *>((access))->DispatchOrQueue(item);
        }
        result = true;
    }
    return result;
}

struct Form
{
    int unk0, unk4, unk8;
    unsigned int flags;
};
struct Info
{
    int unk0;
    volatile char unk4;
    int unk8, unk12, unk16, unk20, unk24;
};
extern void* DAT_011afea4;
// @fnv 0x00c6a3d0
bool __cdecl FUN_00c6a3d0(void* p, int b, char c, char abForce)
{
    bool r = false;
    if (p)
    {
        Form* f = 0;
        unsigned int bits = 0;
        if (!abForce)
        {
            f = ((::Form *)(::GetExtraDataChecked((::NiAVObjectX *)(p))));
            if (f)
            {
                bits = f->flags;
                bits &= 2;
            }
        }
        if (abForce || (f && bits))
        {
            Info info;
            unsigned char cc = *(volatile unsigned char*)&c;
            int bb = b;
            info.unk4 = cc;
            void* g = DAT_011afea4;
            r = true;
            info.unk0 = 0;
            info.unk8 = 7;
            info.unk12 = bb;
            if (g)
                ::FUN_00c68900((::S_00c68900_Node *)(p), (::S_00c68900_Context *)(::Info *)(&info), (void (*)(void *, S_00c68900_Context *))(g));
        }
    }
    return r;
}

class NameEntry16
{
  public:
    unsigned int m_key;
    char unk04[0xC];
};

class SearchOwner
{
  public:
    char unk00[0x78];
    NameEntry16* m_pEntries;
    int m_uiItemCount;
    char unk80[0x40];
    uintptr_t* FindEntry(uintptr_t* out, unsigned int key, unsigned int zero);
};

class LookupTarget
{
  public:
    char unk00[0xC0];
    uintptr_t m_val0xc0;
};

// If an entry with key 0x1300 exists, returns m_val0xc0 of the object FindEntry returns for that key; otherwise returns 0.
// @fnv 0x00c6d900
uintptr_t FUN_00c6d900(SearchOwner* owner)
{
    if (owner != 0)
    {
        for (int i = 0; i < owner->m_uiItemCount; ++i)
        {
            if (owner->m_pEntries[i].m_key == 0x1300)
            {
                uintptr_t out[2];
                uintptr_t* r = owner->FindEntry(out, 0x1300, 0);
                return reinterpret_cast<LookupTarget*>(*r)->m_val0xc0;
            }
        }
    }
    return 0;
}


struct FUN_00c747a0_Class
{
    int* vtbl;
    void FUN_00c747a0();
};

// @fnv 0x00c747a0
void FUN_00c747a0_Class::FUN_00c747a0()
{
    vtbl = &::DAT_010c4b60;
}

void __cdecl FUN_00cc00e0();

// @fnv 0x00c74900
void __cdecl FUN_00c74900()
{
    FUN_00cc00e0();
}

struct Motion_c672
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int m_uiMotionFlags;
};

struct BodyBase_c672
{
    int unk00, unk04, unk08, unk0c;
};

struct Body_c672 : public BodyBase_c672, public Motion_c672
{
};

class Entity_c672
{
  public:
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
    virtual void UpdateMotion();

    int unk04;
    Body_c672* m_pkBody;

    Motion_c672* GetMotion()
    {
        return m_pkBody ? static_cast<Motion_c672*>(m_pkBody) : 0;
    }
};

struct EntityRef_c672
{
    int unk00, unk04, unk08, unk0c;
    Entity_c672* m_pkEntity;
};

struct MotionParams_c672
{
    int unk00, unk04, unk08;
    int m_iRequired;
    int m_iMotionType;
};

// Updates the motion type on the entity's body when the new type differs from the current one and matches the required type, then calls UpdateMotion.
// @fnv 0x00c672a0
void __cdecl FUN_00c672a0(EntityRef_c672* pkRef, MotionParams_c672* pkParams)
{
    Entity_c672* pkEntity = pkRef->m_pkEntity;
    int iNewType = pkParams->m_iMotionType;
    int iRequired = pkParams->m_iRequired;
    Body_c672* pkBody = pkEntity->m_pkBody;
    Motion_c672* pkMotion = pkBody ? static_cast<Motion_c672*>(pkBody) : 0;
    unsigned int uiFlags = pkMotion ? pkMotion->m_uiMotionFlags : 0;
    unsigned int uiType = uiFlags & 0x7f;
    if (iNewType != uiType && (iRequired == 0 || iRequired == uiType))
    {
        unsigned int uiNew = ((uiFlags ^ iNewType) & 0x7f) ^ uiFlags;
        if (pkBody)
        {
            ::FUN_00a29680();
            Motion_c672* pkWrite = static_cast<Motion_c672*>(pkBody);
            ::FUN_00a29680();
            if (pkWrite)
                pkWrite->m_uiMotionFlags = uiNew;
        }
        pkEntity->UpdateMotion();
    }
}

struct OwnerFlags
{
    int unk00, unk04, unk08, unk0c;
    unsigned int flags;
};
struct OwnerBinding
{
    int unk00, unk04, unk08;
    OwnerFlags* owner;
};
struct OffsetKindRecord
{
    int unk00, unk04, unk08, unk0c;
    signed char offset;
    char unk11, unk12, unk13;
    int unk14;
    unsigned char kind;
};
struct EntityRecord
{
    int unk00, unk04, unk08, unk0c;
    OffsetKindRecord link;
};
struct Processor
{
};
struct World
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
    virtual Processor* GetProcessor();
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
    EntityRecord** entries;
    unsigned int count;
    void ClearEntries();
};
// @fnv 0x00c68a00
void bhkWorld::FUN_00c68a00(bool a)
{
    ProcessPendingItems();
    reinterpret_cast<::WorldView *>(this)->ReleaseBodies();
    reinterpret_cast<::Owner *>(this)->ClearReferences();
    if (a)
        reinterpret_cast<::FUN_00c67aa0_Class *>(this)->FlushEntries();
    else
        reinterpret_cast<::World *>(this)->ClearEntries();
}
struct WorldObjectC67
{
    int unk00, unk04, unk08;
    uintptr_t m_ulUserData;
    uintptr_t getUserData() const
    {
        return m_ulUserData;
    }
};
struct BhkObjectC67
{
    int unk00, unk04, unk08, unk0c;
    unsigned int m_uiValue1;
};
inline WorldObjectC67* GetEntityC67(const OffsetKindRecord* c)
{
    if (c->kind == 1)
        return (WorldObjectC67*)((char*)c + c->offset);
    return 0;
}
// Processes up to 3000 entity entries via the processor, clears a flag on each entry's user data, releases references, and zeroes the entry array.
// @fnv 0x00c679a0
void World::ClearEntries()
{
    ContextGuard context;
    if (count > 0)
    {
        if (count >= 3000)
            count = 3000;
        Processor* processor = GetProcessor();
        if (processor)
        {
            reinterpret_cast<::HostWorld_00c951b0 *>((processor))->RemoveEntities((void *const *)(entries), count);
            for (unsigned int i = 0; i < count; ++i)
            {
                WorldObjectC67* pWorldObject = GetEntityC67(&entries[i]->link);
                if (pWorldObject)
                {
                    BhkObjectC67* obj = (BhkObjectC67*)pWorldObject->getUserData();
                    if (obj)
                        obj->m_uiValue1 &= ~32u;
                }
                reinterpret_cast<::hkReferencedObjectC905 *>((((hkReferencedObject*)entries[i])))->FUN_00c905b0();
            }
            std::memset(entries, 0, count * 4);
            count = 0;
        }
    }
}

struct FUN_00c6a270_Context
{
    int m_00;
    unsigned char m_04;
    unsigned int m_08;
    unsigned int m_0C;
    int unk10;
    int unk14;
    int unk18;
};

extern "C" unsigned int DAT_011afea8;
extern "C" unsigned int DAT_011afeb8;

// Unless param_4 is set, requires bit 2 of the extra-data flags, then calls the DAT_011afeb8 callback on param_1 with a context built from param_2 and param_3.
// @fnv 0x00c6a270
bool __cdecl FUN_00c6a270(intptr_t param_1, unsigned char param_2, unsigned char param_3, char abForce)
{
    bool result = false;
    if (param_1 != 0)
    {
        int iFlag = 0;
        if (abForce == 0)
        {
            DispatchState* state = ((::DispatchState *)(::GetExtraDataChecked((::NiAVObjectX *)(param_1))));
            if (state != 0)
                iFlag = state->flags & 2;
        }
        else
            iFlag = 1;
        if (iFlag != 0)
        {
            FUN_00c6a270_Context context;
            result = true;
            context.m_04 = param_3;
            context.m_00 = 0;
            context.m_08 = 0xC;
            context.m_0C = param_2;
            if (DAT_011afeb8 != 0)
                ::FUN_00c68900((::S_00c68900_Node *)(::NiAVObject *)(reinterpret_cast<NiAVObject*>(param_1)),
                             (::S_00c68900_Context *)(::CollisionObjectCountContext *)(reinterpret_cast<CollisionObjectCountContext*>(&context)),
                             (void (*)(void *, S_00c68900_Context *))(void (*)(NiCollisionObject *, CollisionObjectCountContext *))(reinterpret_cast<CollisionObjectCountCallback>(DAT_011afeb8)));
        }
    }
    return result;
}

struct FUN_00c6a440_Context
{
    int m_00;
    unsigned char m_04;
    unsigned int m_08;
    unsigned int m_0C;
    int unk10;
    int unk14;
    int unk18;
};

extern "C" unsigned int DAT_011afea8;

// Unless param_3 is set, requires bit 2 of the extra-data flags; calls the DAT_011afea8 callback and returns whether the context's m_0C ends up nonzero.
// @fnv 0x00c6a440
bool __cdecl HasCollisionObject(intptr_t param_1, unsigned char param_2, char param_3)
{
    bool result = false;
    if (param_1 != 0)
    {
        int iFlag = 0;
        if (param_3 == 0)
        {
            DispatchState* state = ((::DispatchState *)(::GetExtraDataChecked((::NiAVObjectX *)(param_1))));
            if (state != 0)
                iFlag = state->flags & 2;
        }
        else
            iFlag = 1;
        if (iFlag != 0)
        {
            FUN_00c6a440_Context context;
            context.m_04 = param_2;
            context.m_00 = 0;
            context.m_08 = 8;
            context.m_0C = 0;
            if (DAT_011afea8 != 0)
                ::FUN_00c68900((::S_00c68900_Node *)(::NiAVObject *)(reinterpret_cast<NiAVObject*>(param_1)),
                             (::S_00c68900_Context *)(::CollisionObjectCountContext *)(reinterpret_cast<CollisionObjectCountContext*>(&context)),
                             (void (*)(void *, S_00c68900_Context *))(void (*)(NiCollisionObject *, CollisionObjectCountContext *))(reinterpret_cast<CollisionObjectCountCallback>(DAT_011afea8)));
            result = context.m_0C != 0;
        }
    }
    return result;
}

struct Tmp_c6c1
{
    float m_f00;
    unsigned char m_b04;
    unsigned char m_b05;
    unsigned char m_b06;
    unsigned char m_b07;
    unsigned char m_b08;
};
class Node_c6c1
{
  public:
    virtual Node_c6c1* v00();
    virtual void v01();
    virtual void v02();
    virtual Node_c6c1* v03();
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
    virtual int v0e();
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
    virtual void v2e(Tmp_c6c1* p);
    virtual void v2f();
    void m_a68bf0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    Node_c6c1* m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    Node_c6c1** m_a0;
    unsigned short m_a4;
    unsigned short m_a6;
};

// If m_1c->v0e() is nonzero or bForce, calls m_a68bf0 and v2e with a zeroed struct, then recurses into child nodes and finally calls v2f.
// @fnv 0x00c6c110
void FUN_00c6c110(Node_c6c1* apNode, bool bForce)
{
    if (apNode)
    {
        Node_c6c1* p = apNode->m_1c;
        int r = 0;
        if (p)
            r = p->v0e();
        if (r || bForce)
        {
            apNode->m_a68bf0();
            Tmp_c6c1 t;
            t.m_f00 = 0.0f;
            t.m_b04 = 0;
            t.m_b05 = 0;
            t.m_b06 = 0;
            t.m_b07 = 0;
            t.m_b08 = 0;
            apNode->v2e(&t);
            bForce = true;
        }
        Node_c6c1* c = apNode->v03();
        if (c)
        {
            for (unsigned int i = 0; i < c->m_a6; ++i)
                FUN_00c6c110(c->m_a0[i], bForce);
        }
        apNode->v2f();
    }
}

struct NiStream;

struct CBinaryStream
{
    void* m_ppVirtualMethodTable;                                                                                      // +0x00
    unsigned int m_uiStreamFlags;                                                                        // +0x04
    void* m_pvUnk08;                                                                                     // +0x08
    unsigned int(__cdecl* m_pfnRead)(CBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);  // +0x0c

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void BinLoad(CBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

class FakeThis00a81040
{
  public:
    void FUN_00a81040(NiStream& kStream);
};

struct NiStream
{
  public:
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
    virtual void v30(int iValue);  // vtable +0x30
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
    CBinaryStream* m_pUnderlyingStream;  // +0x250
};

class CollisionLoad : public FakeThis00a81040
{
  public:
    int unk00;              // +0x00
    int unk04;              // +0x04
    int unk08;              // +0x08
    unsigned short m_us0c;  // +0x0c
    unsigned short unk0e;   // +0x0e
    int m_i10;              // +0x10

    void FUN_00c6c380(NiStream& kStream);
};

// Calls the base routine FUN_00a81040, then loads m_us0c from the stream with BinLoad and passes m_i10 to kStream.v30.
// @fnv 0x00c6c380
void CollisionLoad::FUN_00c6c380(NiStream& kStream)
{
    FUN_00a81040(kStream);
    BinLoad(*kStream.m_pUnderlyingStream, &m_us0c);
    kStream.v30(m_i10);
}

static inline float Min(float a, float b)
{
    return b < a ? b : a;
}
struct FUN_00c6cc10_cls
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    float m_f528;
    float m_f52c;
    float Evaluate(float p, float q);
};
// Adds m_f528 times the lesser of m_f52c and q to p, decrements m_f52c by q, and steps m_f528 down by DAT_0103c7c8 or zeroes it when m_f52c is not positive.
// @fnv 0x00c6cc10
float FUN_00c6cc10_cls::Evaluate(float afBase, float afAmount)
{
    float result = afBase;
    if (m_f52c > 0.0f)
    {
        float consumed = Min(m_f52c, afAmount);
        result += m_f528 * consumed;
        m_f52c -= afAmount;
        m_f528 = (float)(m_f528 - ::DAT_0103c7c8);
    }
    else
        m_f528 = 0.0f;
    return result;
}


struct bhkRefInitBase
{
    bhkRefInitBase();
    ~bhkRefInitBase();
    void* m_vft;
    unsigned int m_04;
    unsigned int m_08;
};

struct S00c6d040_A : public bhkRefInitBase
{
    unsigned int m_0c;
    unsigned int m_10;
    S00c6d040_A()
    {
        m_0c = 0;
        m_10 = 0;
        m_vft = &(*reinterpret_cast<unsigned int *>(&::DAT_01030394));
        (*reinterpret_cast<unsigned int *>(&::DAT_0126810c)) += 1;
    }
};

struct S00c6d040_B : public S00c6d040_A
{
    S00c6d040_B()
    {
        m_vft = &(*reinterpret_cast<unsigned int *>(&::DAT_0103078c));
        DAT_01268238 += 1;
    }
};

struct S00c6d040_C : public S00c6d040_B
{
    unsigned char m_14;
    S00c6d040_C()
    {
        m_vft = &(*reinterpret_cast<unsigned int *>(&::DAT_010306b4));
        (*reinterpret_cast<unsigned int *>(&::DAT_01268208)) += 1;
        m_14 = 0;
    }
};

struct FUN_00c6d040 : public S00c6d040_C
{
    FUN_00c6d040(uintptr_t a);
};

// Constructs the object by setting the vft, calling FUN_00cc2530 with a, incrementing DAT_012685a0, and zeroing m_14.
// @fnv 0x00c6d040
FUN_00c6d040::FUN_00c6d040(uintptr_t a)
{
    m_vft = &(*reinterpret_cast<unsigned int *>(&::DAT_010c4694));
    reinterpret_cast<::S00cc2530_Owner306 *>(this)->FUN_00cc2530((::S00cc2530_Source306 *)(a));
    (*reinterpret_cast<unsigned int *>(&::DAT_012685a0)) += 1;
    m_14 = 0;
}

struct FUN_00c6d7e0_Child
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiValue1;
};

struct FUN_00c6d7e0_Parent
{
    int unk00;
    int unk04;
    FUN_00c6d7e0_Child* m_pChildObject;
};


// With a set and a child object, returns whether DAT_01267bc8 gave 0 for c (or child m_uiValue1 & 0x1f); otherwise 1 if a or b is set, else 0.
// @fnv 0x00c6d7e0
char __cdecl FUN_00c6d7e0(FUN_00c6d7e0_Parent* apParent, bool abFlag1, bool abFlag2, int aiValue)
{
    if (!abFlag1 && abFlag2 != abFlag1)
        return 1;
    try
    {
        if (abFlag1 == 0)
            goto RETA;
    }
    catch (...)
    {
        throw;
    }
    if (apParent != 0 && apParent->m_pChildObject != 0)
    {
        unsigned int t;
        if (aiValue != -1)
        {
            t = ((unsigned int)(reinterpret_cast<::FUN_00c84f10_cls *>((aiValue))->FUN_00c84f10({})));
        }
        else
        {
            t = apParent->m_pChildObject->m_uiValue1 & 0x1f;
        }
        unsigned char r = 0;
        if (::DAT_01267bc8)
        {
            r = reinterpret_cast<unsigned char(__cdecl*)(unsigned int)>(::DAT_01267bc8)(t);
        }
        return !r;
    }
RETA:
    return abFlag1;
}

class FUN_00c6def0_obj;
class FUN_00c6def0_sub
{
  public:
};
class FUN_00c6def0_obj
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    FUN_00c6def0_sub m_e0;
    int m_e4;
    unsigned char m_e8;
};

extern float DAT_01267bc0;
// Returns true if p is non-null and either FUN_00c8cce0 accepts m_e8 and m_e0.FUN_00c86430() exceeds DAT_01267bc0, or (m_2c & 0x7f) == 6.
// @fnv 0x00c6def0
bool __cdecl FUN_00c6def0(FUN_00c6def0_obj* p)
{
    bool result = false;
    if (p != 0)
    {
        unsigned int v = p->m_e8;
        if (((bool)(::FUN_00c8cce0((int *)(unsigned int *)(&v)))))
        {
            float f = reinterpret_cast<::MotionMassView *>(&(p->m_e0))->FUN_00c86430();
            if (f > DAT_01267bc0)
                result = true;
        }
        if (!result)
        {
            if ((p->m_2c & 0x7f) == 6)
                result = true;
        }
    }
    return result;
}

struct S00c6e050_Sub
{
    void AddEntry(intptr_t a, long long b);
};
struct S00c6e050_Ptr
{
    int unk00;
    int unk04;
    S00c6e050_Sub* m_08;
};
struct S00c6e050_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    S00c6e050_Ptr* m_594;
    void FUN_00c6e050(volatile intptr_t a, volatile int b);
};
// Unless m_594->ContainsObject(a), calls FUN_00a29680, then m_594->m_08->AddEntry(a, b), then FUN_00a29680 again.
// @fnv 0x00c6e050
void S00c6e050_Obj::FUN_00c6e050(volatile intptr_t a, volatile int b)
{
    S00c6e050_Ptr* p = m_594;
    if (!p)
        return;
    if (reinterpret_cast<::D8A0Wrapper *>((p))->ContainsObject((void *)(a)))
        return;
    S00c6e050_Sub* s = p->m_08;
    long long v = (long long)b;
    if (!s)
        return;
    ::FUN_00a29680();
    s->AddEntry(a, v);
    ::FUN_00a29680();
}

struct NiPoint3_c75
{
    float x, y, z;
};
struct NiMatrix3_c75
{
    float m[3][3];
};
struct NiTransform_c75
{
    NiTransform_c75()
    {}
    NiMatrix3_c75 m_kOrientation;
    NiPoint3_c75 m_kTranslation;
    float m_fScale;
};
struct Bone_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    NiTransform_c75 m_kLocalTransform;
};
struct Rec_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
};
struct Info_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    int m_iArrayLength;
};
struct Holder_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    Info_c75* m_pkInfo;
};
struct Skel_c75
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    float m_fScale;
};
extern NiTransform_c75 __cdecl FUN_00c74d50(Rec_c75* pkRec);
class FUN_00c75b40_cls
{
  public:
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    Skel_c75* m_58;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    Rec_c75* m_94;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    Bone_c75** m_a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    Holder_c75* m_2a4;
    void UpdateBoneLocalTransforms();
};
// @fnv 0x00c75b40
void FUN_00c75b40_cls::UpdateBoneLocalTransforms()
{
    int iCount = m_2a4->m_pkInfo->m_iArrayLength;
    float fInv = 1.0f / m_58->m_fScale;
    for (int i = 0; i < iCount; i++)
    {
        Bone_c75* pkBone = m_a4[i];
        NiTransform_c75 kXform = FUN_00c74d50(&m_94[i]);
        kXform.m_kTranslation.x *= fInv;
        int* __restrict px = (int*)&pkBone->m_kLocalTransform.m_kTranslation.x;
        *px = *(int*)&kXform.m_kTranslation.x;
        kXform.m_kTranslation.y *= fInv;
        *(int*)&pkBone->m_kLocalTransform.m_kTranslation.y = *(int*)&kXform.m_kTranslation.y;
        kXform.m_kTranslation.z *= fInv;
        *(int*)&pkBone->m_kLocalTransform.m_kTranslation.z = *(int*)&kXform.m_kTranslation.z;
        pkBone->m_kLocalTransform.m_kOrientation = kXform.m_kOrientation;
    }
}


class RefObject_c7be
{
  public:
    virtual ~RefObject_c7be();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
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

template <class T> class Pointer_c7be
{
  public:
    ~Pointer_c7be()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    Pointer_c7be& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

struct PooledEntry_c7be
{
    int unk00;
    int unk04;
    Pointer_c7be<RefObject_c7be> m_pReferencedObject;
};

// Releases the reference held by pkEntry->m_pReferencedObject and deletes the PooledEntry_c7be instance.
// @fnv 0x00c7beb0
void ReleasePooledEntry(PooledEntry_c7be* pkEntry)
{
    pkEntry->m_pReferencedObject = 0;
    delete pkEntry;
}

namespace fnv_00c69010 {
struct ConstructorPhysics;
struct ConstructorParent : FUN_00c87c30_owner
{
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
    virtual ConstructorPhysics* v25();
    ConstructorPhysics* GetPhysics()
    {
        return v25();
    }
    NiPointer<C67F20RefObject> object;
};
struct ConstructorArray
{
    void* data;
    int size;
    unsigned int capacity;
    ConstructorArray() : data(0), size(0), capacity(0x80000000)
    {}
    ~ConstructorArray();
};
struct ConstructorList : C67F20List
{
    ConstructorList()
    {
        m_pkHead = 0;
    }
};
struct ConstructorArgument
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
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int context;
};
struct ConstructorPhysics
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
    unsigned int unk0d8;
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
    float value1;
    float value2;
};
struct FUN_00c69010 : ConstructorParent
{
    unsigned int unk10;
    bool flag14, flag15, flag16;
    unsigned int unk18, unk1c, unk20, unk24, unk28;
    void* buffer2c;
    unsigned int unk30;
    void* buffer34;
    unsigned int unk38;
    void* buffer3c;
    unsigned int unk40;
    void* buffer44;
    unsigned int unk48;
    void* buffer4c;
    unsigned int unk50, unk54, unk58, unk5c;
    __m128 vector60;
    ConstructorArray array70;
    ConstructorArray array7c;
    float value88, value8c;
    ConstructorList list90;
    FUN_00c69010(ConstructorArgument*);
};
inline float MinValue(float value, float limit)
{
    return value < limit ? value : limit;
}
// Allocates and zeroes five buffers, caps DAT_01267b38 at 1.0, calls list90.FUN_00c67f20 and CreateChildAndNotifySim, and copies two floats from GetPhysics().
// @fnv 0x00c69010
FUN_00c69010::FUN_00c69010(ConstructorArgument* argument)
    : unk10(0), flag14(false), flag15(false), flag16(false), unk18(0), unk1c(0), unk20(0), unk24(0), unk28(0), unk30(0),
      unk38(0), unk40(0), unk48(0), unk50(0), vector60((*reinterpret_cast<__m128 *>(&::DAT_01267e30)))
{
    ThreadMemoryScope scope;
    ++::DAT_012677a4;
    buffer2c = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(12000);
    std::memset(buffer2c, 0, 12000);
    buffer34 = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(800);
    std::memset(buffer34, 0, 800);
    buffer3c = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(400);
    std::memset(buffer3c, 0, 400);
    buffer44 = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(800);
    std::memset(buffer44, 0, 800);
    buffer4c = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(12000);
    std::memset(buffer4c, 0, 12000);
    float minimum = MinValue(::DAT_01267b38, 1.0f);
    ::DAT_01267b38 = minimum;
    list90.FUN_00c67f20();
    reinterpret_cast<::Controller *>(this)->CreateChildAndNotifySim((::OwnerB *)(void *)(argument ? &argument->context : 0));
    value88 = GetPhysics()->value1;
    value8c = GetPhysics()->value2;
}
}  // namespace fnv_00c69010

#include <math.h>
struct FUN_00c6cbc0_class
{
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    float unk528;
    float unk52C;

    void FUN_00c6cbc0(float threshold, float value);
};

// Stores threshold and value into unk528 and unk52C when the absolute value of threshold exceeds the absolute value of unk528.
// @fnv 0x00c6cbc0
void FUN_00c6cbc0_class::FUN_00c6cbc0(float threshold, float value)
{
    if (fabs(threshold) > fabs(unk528))
    {
        unk528 = threshold;
        unk52C = value;
    }
}


__declspec(align(16)) struct C_00c6cde0
{
    __m128 m00;
    __m128 m10;
    float m20;
    float m24;
    float m28;
    unsigned int unk2c;
    __m128 m30;
    float m40;
    float m44;
    unsigned int m48;
    float m4c;
    float m50;
    unsigned int m54;
    float m58;
    float m5c;
    float m60;
    float m64;
    float m68;
    unsigned int m6c;
    unsigned char m70;
    void FUN_00c6cde0();
};

// Sets defaults: two zeroed vectors, a (0,1,0,0) vector, and fixed float and integer values including one read from DAT_0104da48.
// @fnv 0x00c6cde0
void C_00c6cde0::FUN_00c6cde0()
{
    __m128 v1 = _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f);
    this->m00 = v1;
    this->m10 = v1;
    this->m20 = 1.0f;
    this->m24 = 0.0f;
    this->m28 = 0.1f;
    this->m48 = 0;
    this->m54 = 4;
    this->m40 = 0.0f;
    this->m44 = 0.0f;
    this->m6c = 10;
    this->m4c = 0.05f;
    this->m50 = 10.0f;
    this->m58 = 10.0f;
    this->m5c = ::DAT_0104da48;
    this->m70 = 0;
    this->m60 = 0.0f;
    this->m64 = 1.5707964f;
    this->m68 = 1.0f;
    this->m30 = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
}

struct FUN_00c6d150_class
{
    char pad[0x580];
    __m128 m_v580;
    int m_i590;
    void FUN_00c6d150();
};

// If m_i590 is nonzero, zeroes m_v580 and sets m_i590 to 0.
// @fnv 0x00c6d150
void FUN_00c6d150_class::FUN_00c6d150()
{
    if (m_i590 != 0)
    {
        m_v580 = _mm_setzero_ps();
        m_i590 = 0;
    }
}

struct S_00c6d5c0
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int m_414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    __m128 m_4f0;
    __m128 m_500;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    float m_524;
    void FUN_00c6d5c0();
};
// If m_524 is positive, adds m_500 scaled by m_524 to m_4f0 when m_414 lacks 0x1800; otherwise resets m_500 from DAT_01267e30.
// @fnv 0x00c6d5c0
void S_00c6d5c0::FUN_00c6d5c0()
{
    if (m_524 > 0.0f)
    {
        __m128 v = _mm_load_ss(&m_524);
        if ((m_414 & 0x1800) == 0)
        {
            m_4f0 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_500), m_4f0);
        }
    }
    else
        m_500 = *(__m128*)&DAT_01267e30;
}

namespace fnv_00c6fd80 {
struct NiGlobalStringTable
{
    static char* AddString(const char*);
};
class NiFixedString
{
  public:
    char* data;
    NiFixedString(const char* text) : data(NiGlobalStringTable::AddString(text))
    {}
    ~NiFixedString()
    {
        if (data != DAT_0109b220)
            InterlockedDecrement(&GetGlobalStringHeader(data)->m_lRefCount);
    }
};
class NiMemObject
{
  public:
};
class FUN_00a5ecb0 : public NiMemObject
{
  public:
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
    NiPoint3 position;
    float scale;
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
    FUN_00a5ecb0(unsigned int);
};
struct Scene047
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Scene047* asNode();
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
    virtual void attach(FUN_00a5ecb0*, const void*);
    virtual void v36();
    virtual void clone(FUN_00a5ecb0*, int);
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
    float scale;
    int unk09c;
    int unk0a0;
    unsigned short unk0a4;
    unsigned short count;
};
struct Handler047
{
};
struct Controller047
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
    unsigned int unk0d8;
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
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    NiPoint3 offset;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    Handler047* handler;
    void AttachSceneNode(Scene047* node);
};
// Clones node into a new object, sets its position to offset times 1/node->scale and its scale to |1/node->scale|, then attaches it to the current object.
// @fnv 0x00c6fd80
void Controller047::AttachSceneNode(Scene047* node)
{
    ThreadMemoryScope memoryScope;
    if (((intptr_t)(reinterpret_cast<::FUN_00c6e0b0_Class *>(this)->FUN_00c6e0b0())))
        return;
    if (!node)
    {
        if (!handler)
            goto done;
        Scene047* object = ((::fnv_00c6fd80::Scene047 *)(reinterpret_cast<::PropertyOwner *>((handler))->FUN_00c85c80((void *)(0))));
        if (!object)
            goto done;
        node = object->asNode();
        if (!node)
            goto done;
        if (node->count)
        {
            SettingHolder* child = ((::SettingHolder *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
            if (!child)
                goto done;
            node = (Scene047*)child->FUN_00653290(&(*reinterpret_cast<char *>(&::g_011f4428)));
        }
        if (!node)
            goto done;
    }
    if (!((::fnv_00c6fd80::Scene047 *)(reinterpret_cast<::Holder *>(this)->GetCurrentObject())))
        goto done;
    {
        FUN_00a5ecb0* created = new FUN_00a5ecb0(0);
        node->clone(created, 1);
        ::AssignFixedString((char *)(created), (intptr_t)&(const ::fnv_00c6fd80::NiFixedString &)(NiFixedString(&(*reinterpret_cast<char *>((void *)&::DAT_010c43d8)))), {});
        float inverse = 1.0f / node->scale;
        NiPoint3 buffer;
        const NiPoint3* result = ((::NiPoint3 *)&(::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&buffer)), (*(const ::hkVector4 *)(&offset)))));
        NiPoint3 scaled;
        scaled.x = result->x * inverse;
        scaled.y = result->y * inverse;
        scaled.z = result->z * inverse;
        created->position = scaled;
        if (node->scale != 0.0f)
        {
            float value = 1.0f / node->scale;
            value = fabs(value);
            created->scale = value;
        }
        ((::fnv_00c6fd80::Scene047 *)(reinterpret_cast<::Holder *>(this)->GetCurrentObject()))->attach(created, &(*reinterpret_cast<char *>(&::DAT_011a9b7c)));
        unk414 |= 0x8000;
    }
done:;
}
}  // namespace fnv_00c6fd80

namespace fnv_00c74ed0 {
struct __declspec(align(16)) FUN_00c74ed0
{
    short channel0, channel1, channel2, channel3, channel4, channel5, channel6, channel7;
    __m128 initialVector;
    float initialValue, factor0, factor1, factor2, factor3, unk34, unk38, unk3c;
    __m128 currentPosition, currentScale, previousPosition, previousScale;
    unsigned char enabled, dirty;
    FUN_00c74ed0();
};
// Sets channel0-4 to -1, factor0-3 to 1.0, the vector fields from DAT_01267e30 and DAT_012683b0, enabled to 1 and dirty to 0.
// @fnv 0x00c74ed0
FUN_00c74ed0::FUN_00c74ed0()
{
    double initial = ::DAT_01012054;
    channel0 = -1;
    channel1 = -1;
    channel2 = -1;
    channel3 = -1;
    channel4 = -1;
    _mm_store_ps(reinterpret_cast<float*>(&initialVector), (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
    initialValue = (float)initial;
    factor3 = factor2 = factor1 = factor0 = 1.0f;
    currentPosition = (*reinterpret_cast<__m128 *>(&::DAT_01267e30));
    currentScale = (*reinterpret_cast<__m128 *>(&::DAT_012683b0));
    previousPosition = (*reinterpret_cast<__m128 *>(&::DAT_01267e30));
    previousScale = (*reinterpret_cast<__m128 *>(&::DAT_012683b0));
    enabled = 1;
    dirty = 0;
}
}  // namespace fnv_00c74ed0

// @fnv 0x00c657f0
void __cdecl FUN_00c657f0()
{
    static_cast<::OwnerProxy *>(nullptr)->FUN_00c6ba30({}, {});
}

// @fnv 0x00c65810
void __cdecl FUN_00c65810()
{
    static_cast<::fnv_00c6bb70::bhkNiCollisionObject *>(nullptr)->FUN_00c6bb70(*(::fnv_00c6bb70::NiStream *)nullptr);
}

// @fnv 0x00c65820
void __cdecl FUN_00c65820()
{
    static_cast<::CollisionLoad *>(nullptr)->FUN_00c6c380(*(::NiStream *)nullptr);
}

struct Key
{
    int a;
    int b;
    int c;
    Key(int v);
    ~Key();
};
struct Tag
{
    char b;
    Tag() : b(0)
    {}
    Tag(const Tag& o);
};
struct Pair
{
    void* p;
    int c;
    Pair(void* a, int b) : p(a), c(b)
    {}
};
struct Result
{
    bool ok;
    Result(const Result& o);
};
Result FUN_00cc0d60(Pair pc, Tag t, int x, int y);

struct Owner67430
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
    virtual void* GetTarget();
    bool FUN_00c67430(int v);
};

// Builds a Key from v and returns the ok flag of FUN_00cc0d60 called with GetTarget() and the key's c field.
// @fnv 0x00c67430
bool Owner67430::FUN_00c67430(int aiKey)
{
    Key key(aiKey);
    Result r = FUN_00cc0d60(Pair(GetTarget(), key.c), Tag(), 0, 0);
    return r.ok != 0;
}

namespace sc68e90 {

struct Handler;

struct Event
{
    int unk00;
    int unk04;
    int m_iType;
};



// Looks up the handler for pkEvent->m_iType in DAT_011afe88 and calls FUN_00c68900 with pvContext, pkEvent, and the handler if found.
// @fnv 0x00c68e90
void FUN_00c68e90(void* pvContext, Event* pkEvent)
{
    Handler* pkHandler = (*reinterpret_cast<sc68e90::Handler * (*)[]>(&::DAT_011afe88))[pkEvent->m_iType];
    if (pkHandler)
        ::FUN_00c68900((::S_00c68900_Node *)(pvContext), (::S_00c68900_Context *)(pkEvent), (void (*)(void *, S_00c68900_Context *))(pkHandler));
}

}

extern C6A2E0Callback DAT_011afeac;

struct ObjectProperties
{
    unsigned int unk00, unk04, unk08, flags;
};

// If object is non-null and enabled (or skipFlagCheck), fills a C6A2E0Context and calls FUN_00c68900 when DAT_011afeac is set; returns 1 if enabled, else 0.
// @fnv 0x00c6a4c0
unsigned char __cdecl TraverseObject(C6A2E0AVObject* object, void* userData, unsigned int count, bool recurse,
                                     bool skipFlagCheck)
{
    unsigned char result = 0;
    C6A2E0Context context;
    if (object != 0)
    {
        unsigned int enabled = skipFlagCheck ? 1 : C6A2E0IsEnabled(object);
        if (enabled)
        {
            result = 1;
            context.bRecurse = recurse;
            context.pCurrentObject = 0;
            context.uiTraversalFlags = 9;
            context.iCount = count;
            context.pUserData = userData;
            C6A2E0Callback callback = DAT_011afeac;
            if (callback != 0)
                ::FUN_00c68900((::S_00c68900_Node *)(object), (::S_00c68900_Context *)(::C6A2E0Context *)(&context), (void (*)(void *, S_00c68900_Context *))(callback));
        }
    }
    return result;
}


struct Owner274
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    __m128 velocity;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    float selectedDuration;

    void UpdateMaxVelocity(const float* param_1, float param_2);
};

static inline float Len2(__m128 v)
{
    __m128 s = _mm_mul_ps(v, v);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(s, s, 0xaa), _mm_add_ss(_mm_shuffle_ps(s, s, 0x55), s)));
    return r;
}
// @fnv 0x00c6d4d0
void Owner274::UpdateMaxVelocity(const float* param_1, float afDuration)
{
    __m128 values;
    float* p = (float*)&values;
    p[0] = param_1[0] * DAT_01267bcc;
    p[1] = param_1[1] * DAT_01267bcc;
    p[2] = param_1[2] * DAT_01267bcc;
    p[3] = 0.0f;
    float scale = 1.0f / afDuration;
    __m128 s4 = _mm_load_ss(&scale);
    __m128 scaled = _mm_mul_ps(_mm_shuffle_ps(s4, s4, 0), values);
    if (Len2(scaled) > Len2(velocity))
    {
        selectedDuration = afDuration;
        velocity = scaled;
    }
}

struct FUN_00c74780_StandIn
{
    intptr_t FUN_00c74780(unsigned char param_2);
};

// Calls FUN_005545f0, conditionally calls DAT_011f6238.FUN_00aa4060 when param_2 has bit 0 set, and returns this as an int.
// @fnv 0x00c74780
intptr_t FUN_00c74780_StandIn::FUN_00c74780(unsigned char param_2)
{
    reinterpret_cast<::FUN_005545f0 *>((this))->FUN_005545f0::~FUN_005545f0();

    if (param_2 & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(reinterpret_cast<FUN_00c68f50_cls*>(this));

    return reinterpret_cast<intptr_t>(this);
}

struct QuatResult
{
    __m128 value;

    void FUN_00c74b70(const float* a, const float* b);
};

// Combines the two 4-float vectors a and b with SSE (cross terms, w-scaled terms, 4-component dot in w) and stores the result in value.
// @fnv 0x00c74b70
void QuatResult::FUN_00c74b70(const float* a, const float* b)
{
    __m128 xmm1 = _mm_load_ps(a);
    __m128 xmm0 = _mm_load_ps(b);

    __m128 xmm3 = _mm_mul_ps(_mm_shuffle_ps(xmm0, xmm0, 201), _mm_shuffle_ps(xmm1, xmm1, 210));
    __m128 xmm2;

    xmm2 = _mm_shuffle_ps(xmm0, xmm0, _MM_SHUFFLE(3, 1, 0, 2));
    __m128 xmm4 = _mm_shuffle_ps(xmm1, xmm1, _MM_SHUFFLE(3, 0, 2, 1));
    xmm2 = _mm_mul_ps(xmm2, xmm4);
    xmm3 = _mm_sub_ps(xmm3, xmm2);

    xmm2 = _mm_shuffle_ps(xmm1, xmm1, _MM_SHUFFLE(3, 3, 3, 3));
    xmm2 = _mm_shuffle_ps(xmm2, xmm2, 0);
    xmm2 = _mm_mul_ps(xmm2, xmm0);
    xmm2 = _mm_add_ps(xmm2, xmm3);

    xmm3 = _mm_shuffle_ps(xmm0, xmm0, _MM_SHUFFLE(3, 3, 3, 3));
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    xmm4 = _mm_shuffle_ps(xmm3, xmm3, 0);
    xmm4 = _mm_mul_ps(xmm4, xmm1);

    xmm2 = _mm_sub_ps(xmm2, xmm4);
    xmm1 = _mm_shuffle_ps(xmm0, xmm0, 78);
    xmm1 = _mm_add_ps(xmm1, xmm0);

    xmm0 = _mm_shuffle_ps(xmm1, xmm1, _MM_SHUFFLE(2, 3, 0, 1));
    xmm0 = _mm_add_ps(xmm0, xmm1);

    xmm1 = xmm2;
    xmm0 = _mm_shuffle_ps(xmm0, xmm0, 0);
    xmm2 = _mm_unpackhi_ps(xmm2, xmm0);
    xmm1 = _mm_shuffle_ps(xmm1, xmm2, 0xc4);

    QuatResult result;
    result.value = xmm1;
    *this = result;
}

struct NiUpdateData
{
  public:
    float time;
    bool updateControllers, isMultiThreaded, updateGeomorphs, updateShadowScene, updateTransforms;
    NiUpdateData()
        : time(0.0f), updateControllers(false), isMultiThreaded(false), updateGeomorphs(false),
          updateShadowScene(false), updateTransforms(false)
    {}
};
class NiAVObject : public NiAVObjectStub
{
  public:
    void Update(NiUpdateData& data);
public:
    void UpdateWorldLoc();
};
// Checks the TLS state and m_0c flags, calls v2B/v2A/v29 or v2D as needed, then invokes m_08->Call() if m_08 is set.
// @fnv 0x00c6b670
void FUN_00c6b670_cls::UpdateState(int a1)
{
    int state = g_tlsBlock.collisionUpdateMode;
    if (state == 3)
        goto L_a2;
    if (((unsigned char)(m_0c >> 6)) & 1)
    {
        if (state == 2)
            goto L_a2;
        v2B();
        v2A();
        m_0c &= 0xffbf;
        return;
    }
    if (!((unsigned char)m_0c & 1))
        goto L_a2;
    if (v2D())
    {
        if (g_tlsBlock.collisionUpdateMode != 2)
        {
            v2A();
            return;
        }
        goto L_a2;
    }
    if (g_tlsBlock.collisionUpdateMode != 1)
    {
        v29();
        return;
    }
L_a2:
    if (m_08)
        reinterpret_cast<::NiAVObject *>((m_08))->UpdateWorldLoc();
}
class NiNode : public NiAVObject
{
};
struct SavedNodeTransform
{
    NiAVObjectStub* object;
    ThreeByThreeMatrix rotation;
    NiPoint3 translation;
    float scale;
};
struct SavedNodeArray
{
    int unk00;
    SavedNodeTransform* data;
    unsigned int size;
};
// @fnv 0x00c75c00
void __cdecl RestoreNodeTransforms(NiNode* root, SavedNodeArray* saved, int flags, int mode)
{
    for (unsigned int i = 0; i < saved->size; ++i)
    {
        saved->data[i].object->m_kLocalTransform.m_kTranslation = saved->data[i].translation;
        saved->data[i].object->m_kLocalTransform.m_kOrientation = saved->data[i].rotation;
    }
    NiUpdateData update;
    reinterpret_cast<::FUN_00a59c60_cls *>((root))->FUN_00a59c60((std::intptr_t)&(update));
    if (mode != 4 && mode != 0)
        ::FUN_00c6a350((::NiAVObject *)(root), mode, true, false, true);
    if ((unsigned char)flags)
        ::SetFlagRecursive(flags, (::WalkNode_cls *)(root));
}

struct XBase0
{
    int a0;
    int a4;
    intptr_t a8;
    int ac;
};
struct XBase1
{
    int b0;
};
struct XDerived : XBase0, XBase1
{
};
struct XObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual XBase1* v4();
    int m_iWordAt04;
    intptr_t m_8;
    int m_iThirdValue;
};
struct XRef
{
    int f0;
    int f4;
    int f8;
    XObj** p;
};

// @fnv 0x00c7ffd0
intptr_t __cdecl FUN_00c7ffd0(XRef* apRef)
{
    XObj** ppObj = apRef->p;
    if (!ppObj)
        ppObj = (XObj**)apRef;
    intptr_t r = 0;
    if (ppObj)
    {
        XObj* o = *ppObj;
        if (o->m_iThirdValue == 8 || o->m_iThirdValue == 10)
        {
            XDerived* d = static_cast<XDerived*>(o->v4());
            r = d ? d->a8 : 0;
        }
        else
        {
            XObj* o2 = *ppObj;
            if (o2 && o2->m_iThirdValue == 9)
                r = o2->m_8;
        }
    }
    return r;
}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase_00c66630
{
    virtual void FUN_00c66630();
    int unk04;
};

struct SecondaryBase_00c66630
{
    virtual void FUN_00c66630();
};

struct Derived_00c66630 : PrimaryBase_00c66630, SecondaryBase_00c66630
{
    Derived_00c66630();
// @fnv 0x00c66630
    virtual void FUN_00c66630();
};

Derived_00c66630::Derived_00c66630()
{}

namespace fnv_00c66640 {
// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00c66640();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00c66640();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c66640
    virtual void FUN_00c66640();
};

Derived::Derived()
{}
}  // namespace fnv_00c66640

// FUN_00c66650 : MSVC this-adjusting thunk  (sub ecx, 0x10 ; jmp <impl>)
struct A1_00c66650
{
    A1_00c66650();
    virtual void FUN_00c66650();
    char pad[0x0c];
};
struct A2_00c66650
{
    A2_00c66650();
    virtual void FUN_00c66650();
};
struct Own_00c66650 : A1_00c66650, A2_00c66650
{
    Own_00c66650();
    virtual void key_fn();
// @fnv 0x00c66650
    void FUN_00c66650();
};
Own_00c66650::Own_00c66650()
{}
void Own_00c66650::key_fn()
{}
Own_00c66650* make_00c66650()
{
    static Own_00c66650 o;
    return &o;
}

namespace fnv_00c66660 {
// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void FUN_00c66660();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00c66660();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c66660
    virtual void FUN_00c66660();
};

Derived::Derived()
{}
}  // namespace fnv_00c66660

namespace fnv_00c70810 {
// 'sub ecx,0x410; jmp FUN_00c70c60' == MSVC adjustor thunk (11 bytes, thiscall).
// Derived overrides a virtual that both bases declare; the second base's vtable gets a thunk
// that moves `this` back by the first base's size (0x410).
struct PrimaryBase
{
    virtual void FUN_00c70810();
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
};

struct SecondaryBase
{
    virtual void FUN_00c70810();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c70810
    virtual void FUN_00c70810();
};

Derived::Derived()
{}
}  // namespace fnv_00c70810

namespace fnv_00c70820 {
// sub ecx,0x3e0; jmp FUN_00c70c60
// MSVC this-adjusting (adjustor) thunk: a derived class overrides a virtual
// declared by both of its bases, so the secondary base's vtable slot holds a
// thunk that walks `this` back to the derived object (the size of the primary
// base, 0x3e0) and tail-jumps to the derived override.
struct PrimaryBase
{
    virtual void FUN_00c70820();
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
};

struct SecondaryBase
{
    virtual void FUN_00c70820();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00c70820
    virtual void FUN_00c70820();
};

Derived::Derived()
{}
}  // namespace fnv_00c70820

namespace fnv_00c76030 {
struct MM
{
};
struct FUN_00c76030
{
    unsigned int unk04;
    void* m_pData;
    virtual ~FUN_00c76030();
};
// Destructor that calls FUN_00b601a0, then passes m_pData to FUN_00aa10f0.
// @fnv 0x00c76030
FUN_00c76030::~FUN_00c76030()
{
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
    ::FUN_00aa10f0(m_pData);
}
}  // namespace fnv_00c76030

extern volatile float DAT_01267b50;
extern float DAT_012677ac, DAT_011afe68, DAT_01267b14, DAT_01267b20;
inline float ceilf_(float _X)
{
    return ((float)std::ceil((double)_X));
}
struct C66A00Res
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    float f1e4;
    float f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    float f230;
    float f234;
    int f238;
    int f23c;
    int f240;
    int f244;
    int f248;
    int f24c;
    int f250;
    int f254;
    int f258;
    int f25c;
    int f260;
    int f264;
    int f268;
    int f26c;
    int f270;
    int f274;
    int f278;
    int f27c;
    int f280;
    int f284;
    int f288;
    int f28c;
    int f290;
    int f294;
    int f298;
    int f29c;
    int f2a0;
    int f2a4;
    int f2a8;
    int f2ac;
    int f2b0;
    int f2b4;
    int f2b8;
    int f2bc;
    int f2c0;
    int f2c4;
    int f2c8;
    int f2cc;
    int f2d0;
    int f2d4;
    int f2d8;
    int f2dc;
    int f2e0;
    int f2e4;
    int f2e8;
    int f2ec;
    int f2f0;
    int f2f4;
    int f2f8;
    int f2fc;
    float f300;
};

struct C66A00This
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
    virtual C66A00Res* Unk_25();
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    float f088;
    float f08c;
    void FUN_00c66a00();
};

// Depending on whether DAT_012677b8 is 2, computes a step count, its reciprocal and interval values from DAT globals and stores them in the Unk_25() object.
// @fnv 0x00c66a00
void C66A00This::FUN_00c66a00()
{
    C66A00Res* world = this ? Unk_25() : 0;
    if ((*reinterpret_cast<unsigned int *>(&::DAT_012677b8)) != 2)
    {
        double ratio = (float)(DAT_012677ac / DAT_01267b38);
        float scaled = (float)(4.0 * ratio);
        float clamped = scaled < ::DAT_01011590 ? ::DAT_010162c0 : scaled;
        int steps = (int)clamped;
        world->f2f4 = steps;
        world->f300 = 1.0f / steps;
        DAT_01267b50 = DAT_011afe60;
        const float& blend = const_cast<const float&>(DAT_01267b50);
        float interval = (float)((1.0 - blend) * DAT_010290b8 + ratio * blend * DAT_010290b8);
        world->f1e4 = interval;
        world->f230 = world->f1e8 / interval;
        world->f234 = interval / world->f1e8;
    }
    else
    {
        float ratio = DAT_011afe68 / DAT_01267b14;
        float steps = ceilf_(ratio);
        float interval = DAT_01267b14;
        if (steps < DAT_01267b20)
        {
            steps = DAT_01267b20;
            interval = DAT_011afe68 / DAT_01267b20;
        }
        float first = world->f1e4;
        f088 = first;
        float adjustedFirst = (float)(first + (DAT_011afe68 / (interval * steps) - 1.0));
        float second = world->f1e8;
        f08c = second;
        float adjustedSecond = (float)(second + (DAT_011afe68 / (interval * steps) - 1.0));
        world->f1e4 = adjustedFirst;
        world->f1e8 = adjustedSecond;
        int count = FUN_00cbfef0(steps);
        world->f2f4 = count;
        world->f300 = 1.0f / count;
    }
}

struct C67320Vec4
{
    __m128 v;
    void operator=(const C67320Vec4& rhs)
    {
        v = rhs.v;
    }
    __forceinline void Scale(__m128 s)
    {
        v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), v);
    }
    bool Near(const C67320Vec4& rhs, float epsilon) const;
};
struct C67320Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float amount;
    float scale;
};
struct C67320Node
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void GetPosition(C67320Vec4*);
    virtual void v54();
    virtual void SetPosition(const C67320Vec4*);
};
struct C67320Root
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
    virtual C67320Node* GetNode();
};
struct C67320Source
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
    virtual C67320Info* GetInfo();
    int unk04;
    int unk08;
    int unk0c;
    C67320Root* root;
};
struct C67320Params
{
    int unk00;
    int unk04;
    int unk08;
    C67320Vec4* vector;
};

__forceinline bool C67320Vec4::Near(const C67320Vec4& rhs, float epsilon) const
{
    C67320Vec4 diff;
    diff.v = _mm_sub_ps(v, rhs.v);
    diff.v = _mm_and_ps(diff.v, *reinterpret_cast<const __m128*>(&(*reinterpret_cast<float *>((void *)&::DAT_01017d10))));
    __m128 eps = _mm_set_ps1(epsilon);
    return (_mm_movemask_ps(_mm_cmple_ps(diff.v, eps)) & 7) == 7;
}
// Adds params->vector to the node position; if info->amount < 1 it scales by info->scale first and skips when amount is 0 or the scaled vector is near zero.
// @fnv 0x00c67320
void __cdecl FUN_00c67320(C67320Source* source, C67320Params* params)
{
    C67320Info* info = source->GetInfo();
    C67320Root* root = source->root;
    if (!root)
        return;
    C67320Node* __restrict node = root->GetNode();
    if (!node || !params->vector)
        return;
    C67320Vec4 delta;
    delta.v = params->vector->v;
    if (info && info->amount < 1.0f)
    {
        if (info->amount == 0.0f)
            return;
        float scale = info->scale;
        delta.Scale(_mm_load_ss(&scale));
        if (delta.Near(*reinterpret_cast<const C67320Vec4*>(&DAT_01267e30), ::AngularDashpotApplyD4DCB0::DAT_01017d00))
            return;
    }
    C67320Vec4 position;
    node->GetPosition(&position);
    position.v = _mm_add_ps(position.v, delta.v);
    node->SetPosition(&position);
}

class hkReferencedObject;
struct AddRefT
{
};
extern CallbackTarget* DAT_01267bb8;
extern int DAT_010c4944;
extern int DAT_010c496c;
struct Vec4f
{
    __m128 v;
};
struct ThreadScope
{
    int previous;
    ThreadScope() : previous(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }
    ~ThreadScope()
    {
        g_tlsBlock.memoryContext = previous;
    }
};
struct AllocHeader
{
    void* m_ppVirtualMethodTable;
    unsigned short m_iElementCount;
    unsigned short m_refs;
};
struct EntryBase
{
    static void* operator new(std::size_t n)
    {
        void* p = hkMemoryRouter::getInstance().heap().blockAlloc(int(n));
        ((AllocHeader*)p)->m_iElementCount = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p, std::size_t n);
};
struct FUN_00cbc460 : EntryBase
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    FUN_00cbc460();
};
struct FUN_00cd47e0 : EntryBase
{
    int unk00, unk04, unk08;
    FUN_00cd47e0();
};
struct FUN_00cd44c0 : EntryBase
{
    int unk00, unk04;
    FUN_00cd44c0();
};
struct FUN_00cd4260 : EntryBase
{
    int unk00, unk04;
    FUN_00cd4260();
};
struct FUN_00cd3f90 : EntryBase
{
    int unk00, unk04, unk08;
    FUN_00cd3f90();
};
struct FUN_00cd3c90 : EntryBase
{
    int unk00, unk04;
    FUN_00cd3c90();
};
static void* AllocEntry(unsigned int size)
{
    void* p = hkMemoryRouter::getInstance().heap().blockAlloc(int(size));
    ((AllocHeader*)p)->m_iElementCount = (unsigned short)size;
    return p;
}
struct RefPtr
{
    CallbackTarget* p;
    RefPtr() : p(0)
    {}
    ~RefPtr()
    {
        if (p)
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)p)))->FUN_00c905b0();
    }
    RefPtr& operator=(CallbackTarget* mgr)
    {
        if (mgr)
            reinterpret_cast<::FUN_00c90510_class *>((((AddRefT*)mgr)))->FUN_00c90510();
        if (p)
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)p)))->FUN_00c905b0();
        p = mgr;
        return *this;
    }
};
struct FUN_00c6cde0
{
    FUN_00c6cde0();
    ~FUN_00c6cde0();
};
struct InitialDefaults
{
    int m_80;
    int m_84;
    int m_88;
    volatile float m_8c;
    volatile float m_90;
    char m_94;
    char m_95;
    char m_96;
    char m_97;
    char m_98;
    char m_99;
    char m_9a;
    char m_9b;
    int m_9c;
    int m_a0;
    InitialDefaults()
    {
        m_80 = 0;
        m_84 = 0;
        m_8c = 0.0f;
        m_90 = 1.0f;
        m_88 = 0;
        m_95 = 0;
        m_96 = 0;
        m_97 = 0;
        m_98 = 0;
        m_9c = 0;
        m_a0 = 0;
    }
};
struct FUN_00c6da50 : FUN_00c6cde0
{
    Vec4f m_00;
    Vec4f m_10;
    float m_20;
    float m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    float m_40;
    float m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    float m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    InitialDefaults defaults;
    RefPtr m_a4;
    float m_a8;
    float m_ac;
    int m_b0;
    int m_b4;
    FUN_00c6da50(bool a1);
};
// Initializes fields and a wrapping counter; if a1, creates the global DAT_01267bb8 with seven entries on first use and stores it in m_a4.
// @fnv 0x00c6da50
FUN_00c6da50::FUN_00c6da50(bool a1)
{
    m_a8 = (float)(DAT_01267bcc * 31.0);
    m_b0 = 1;
    m_b4 = 0;
    m_ac = 1.0f;
    ThreadScope scope;
    int cnt = DAT_011b0808 + 1;
    cnt &= 0xffff;
    DAT_011b0808 = cnt;
    if (cnt == 0)
    {
        DAT_011b0808 = 10;
        cnt = 10;
    }
    m_58 = 100.0f;
    defaults.m_84 = (cnt << 16) | 0x1e;
    m_54 = 4;
    m_00.v = *(const __m128*)&DAT_01267e30;
    m_10.v = *(const __m128*)&DAT_01267e30;
    m_24 = 0.0f;
    m_40 = 0.0f;
    m_44 = 0.0f;
    m_48 = 0;
    m_20 = 1.0f;
    if (a1)
    {
        if (DAT_01267bb8 == 0)
        {
            FUN_00cbc460* sm = new FUN_00cbc460();
            DAT_01267bb8 = (CallbackTarget*)sm;
            FUN_00cd47e0* pEntry0 = new FUN_00cd47e0();
            reinterpret_cast<::hkpCharacterStateManager *>((((FUN_00cbc460*)DAT_01267bb8)))->FUN_00cbc4e0((hkReferencedObject*)pEntry0, 0);
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)pEntry0)))->FUN_00c905b0();
            FUN_00cd44c0* pEntry5 = new FUN_00cd44c0();
            reinterpret_cast<::hkpCharacterStateManager *>((((FUN_00cbc460*)DAT_01267bb8)))->FUN_00cbc4e0((hkReferencedObject*)pEntry5, 5);
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)pEntry5)))->FUN_00c905b0();
            FUN_00cd4260* pEntry1 = new FUN_00cd4260();
            reinterpret_cast<::hkpCharacterStateManager *>((((FUN_00cbc460*)DAT_01267bb8)))->FUN_00cbc4e0((hkReferencedObject*)pEntry1, 1);
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)pEntry1)))->FUN_00c905b0();
            FUN_00cd3f90* pEntry2 = new FUN_00cd3f90();
            reinterpret_cast<::hkpCharacterStateManager *>((((FUN_00cbc460*)DAT_01267bb8)))->FUN_00cbc4e0((hkReferencedObject*)pEntry2, 2);
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)pEntry2)))->FUN_00c905b0();
            char* pEntry3 = (char*)AllocEntry(8);
            ((AllocHeader*)pEntry3)->m_refs = 1;
            ((AllocHeader*)pEntry3)->m_ppVirtualMethodTable = &DAT_010c4944;
            reinterpret_cast<::hkpCharacterStateManager *>((((FUN_00cbc460*)DAT_01267bb8)))->FUN_00cbc4e0((hkReferencedObject*)pEntry3, 3);
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)pEntry3)))->FUN_00c905b0();
            char* pEntry4 = (char*)AllocEntry(8);
            ((AllocHeader*)pEntry4)->m_refs = 1;
            ((AllocHeader*)pEntry4)->m_ppVirtualMethodTable = &DAT_010c496c;
            reinterpret_cast<::hkpCharacterStateManager *>((((FUN_00cbc460*)DAT_01267bb8)))->FUN_00cbc4e0((hkReferencedObject*)pEntry4, 4);
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)pEntry4)))->FUN_00c905b0();
            FUN_00cd3c90* pEntry6 = new FUN_00cd3c90();
            reinterpret_cast<::hkpCharacterStateManager *>((((FUN_00cbc460*)DAT_01267bb8)))->FUN_00cbc4e0((hkReferencedObject*)pEntry6, 6);
            reinterpret_cast<::hkReferencedObjectC905 *>((((CallbackTarget*)pEntry6)))->FUN_00c905b0();
        }
        m_a4 = DAT_01267bb8;
    }
}

struct __declspec(align(16)) C6E180Vec4
{
    __m128 vector;
};

struct C6E180Transform
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_vScale;
    int unk14;
    int unk18;
    int unk1c;
    C6E180Vec4 m_translate;
    C6E180Vec4 m_rotate;
};

struct C6E180Cast
{
    int unk00;
    int unk04;
    C6E180Transform* m_kMotionTransform;
};

class GlobalObjectO2_00a7b610
{
  public:
    int unk00;
};

struct C6E180Object
{
    C6E180Cast* FUN_00653290(const GlobalObjectO2_00a7b610* pType);
};


struct C6E180Owner
{
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
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    C6E180Object* m_pkNode;

    void FUN_00c6e180(float fNewScale);
};

// Sets the motion transform's scale to fNewScale, adding (old - new scale) to the translate Z component and subtracting it from the rotate Z component.
// @fnv 0x00c6e180
void C6E180Owner::FUN_00c6e180(float fNewScale)
{
    if (m_pkNode)
    {
        C6E180Cast* pkCast = m_pkNode->FUN_00653290(&g_0126832c);
        if (pkCast)
        {

            float delta =
                (pkCast->m_kMotionTransform ? pkCast->m_kMotionTransform->m_vScale : DAT_010c72bc) - fNewScale;
            C6E180Vec4 kPos;
            kPos.vector = (pkCast->m_kMotionTransform ? pkCast->m_kMotionTransform->m_translate
                                                      : *(const C6E180Vec4*)&DAT_01267e30)
                              .vector;
            C6E180Vec4 kRot;
            kRot.vector =
                (pkCast->m_kMotionTransform ? pkCast->m_kMotionTransform->m_rotate : *(const C6E180Vec4*)&DAT_01267e30)
                    .vector;
            kPos.vector[2] = kPos.vector[2] + delta;
            kRot.vector[2] = kRot.vector[2] - delta;

            if (pkCast->m_kMotionTransform)
            {
                C6E180Transform* t = pkCast->m_kMotionTransform;
                C6E180Vec4 value = kPos;
                t->m_translate.vector = value.vector;
                t->m_translate.vector[3] = t->m_vScale;
            }
            if (pkCast->m_kMotionTransform)
            {
                C6E180Transform* t = pkCast->m_kMotionTransform;
                C6E180Vec4 value = kRot;
                t->m_rotate.vector = value.vector;
                t->m_rotate.vector[3] = t->m_vScale;
            }
            if (pkCast->m_kMotionTransform)
            {
                pkCast->m_kMotionTransform->m_vScale = fNewScale;
            }
        }
    }
}

namespace fnv_00c705c0 {
extern "C" void _ReadWriteBarrier();
extern int DAT_010c49c4, DAT_010c49b4, DAT_010c4998, DAT_010c446c;
struct TargetWorld
{
    unsigned int unk000;
    unsigned int unk004;
    struct Data* m_data;
};
struct Data
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
    unsigned int unk0d8;
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
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    void* m_350;
};
struct FUN_00cac980_Holder
{
};
struct DtorBase
{
    virtual void baseMethod();
    unsigned int unk004;
    FUN_00cac980_Holder* m_object;
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
    unsigned int unk0d8;
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
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    void FUN_00cabf50();
    ~DtorBase();
};
struct SecondaryBase
{
    virtual void secondaryMethod();
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
    void FUN_00ca95e0();
    ~SecondaryBase();
};
struct ListenerBase
{
    virtual void listenerMethod();
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
    unsigned int unk0d8;
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
    ~ListenerBase()
    {}
};
struct RefPointer
{
    NiRefObject* p;
    ~RefPointer()
    {
        if (p)
            p->DecRefCount();
    }
};
class NiD3DPixelShader;
}  // namespace fnv_00c705c0
template <> class NiPointer<fnv_00c705c0::NiD3DPixelShader>
{
  public:
    fnv_00c705c0::NiD3DPixelShader* p;
    ~NiPointer();
};
namespace fnv_00c705c0 {
struct HavokPointer
{
    hkReferencedObject* p;
    void reset()
    {
        if (p)
            reinterpret_cast<::hkReferencedObjectC905 *>((p))->FUN_00c905b0();
        p = 0;
    }
    ~HavokPointer()
    {
        reset();
    }
};
struct Array705
{
    void* data;
    unsigned int count;
    unsigned int capacity;
    ~Array705()
    {
        hkMemoryAllocator* allocator = hkMemoryRouter::getInstance().m_heap;
        _ReadWriteBarrier();
        count = 0;
        if (!(capacity & 0x80000000))
        {
            void* memory = data;
            allocator->bufFree(memory, int((capacity & 0x3fffffff) * 0x70));
        }
        data = 0;
        capacity = 0x80000000;
    }
};
struct Last705
{
    unsigned int value;
    ~Last705()
    {
        ::FUN_00b4df30(this);
    }
};
struct Scope705
{
    unsigned int previous;
    Scope705(Array705& a) : previous(g_tlsBlock.memoryContext)
    {
        _ReadWriteBarrier();
        g_tlsBlock.memoryContext = 16;
        a.count = 0;
    }
    ~Scope705()
    {
        g_tlsBlock.memoryContext = previous;
    }
};
struct FUN_00c705c0 : DtorBase, SecondaryBase, ListenerBase
{
    virtual void baseMethod();
    virtual void secondaryMethod();
    virtual void listenerMethod();
    RefPointer ref594;
    RefPointer ref598;
    unsigned int unk59c, unk5a0;
    NiPointer<NiD3DPixelShader> shaders[2];
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    HavokPointer ref60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    HavokPointer ref630;
    unsigned int unk634;
    HavokPointer ref638;
    Array705 array;
    Last705 last;
    ~FUN_00c705c0();
};
// Destructor that, if world data's m_350 is set, removes this from m_object, then resets the ref630, ref638 and ref60c Havok pointers.
// @fnv 0x00c705c0
FUN_00c705c0::~FUN_00c705c0()
{
    Scope705 mode(array);
    TargetWorld* world = m_object ? ((::fnv_00c705c0::TargetWorld *)(reinterpret_cast<::FUN_00cac980_class *>((m_object))->FUN_00cac980())) : 0;
    Data* data = world->m_data;
    if (data && data->m_350)
    {
        FUN_00cac980_Holder* object = m_object;
        if (object)
        {
            reinterpret_cast<::FUN_00cac110_Class *>(this)->FUN_00cac110();
            reinterpret_cast<::FUN_00cad6f0_class *>((object))->RemoveItem(static_cast<ListenerBase*>(this));
            reinterpret_cast<::FUN_00cac110_Class *>(this)->FUN_00cac110();
        }
    }
    ref630.reset();
    ref638.reset();
    ref60c.reset();
}
}  // namespace fnv_00c705c0

extern "C" void _ReadWriteBarrier(void);
struct GlobalObjectO2_00a7b610;
struct C70940Vec
{
    __m128 q;
};
struct C70940Node
{
    int unk00, unk04, unk08, unk0c;
    float scale;
    int unk14, unk18, unk1c;
    C70940Vec vecA, vecB;
    __forceinline void SetA(const C70940Vec& value)
    {
        vecA = value;
        vecA.q[3] = scale;
    }
    __forceinline void SetB(const C70940Vec& value)
    {
        vecB = value;
        vecB.q[3] = scale;
    }
};
struct C70940Cast
{
    int unk00, unk04;
    C70940Node* node;
    __forceinline float GetScale() const
    {
        return node ? node->scale : DAT_010c72bc;
    }
};
struct C70940Src
{
    C70940Cast* FUN_00653290(GlobalObjectO2_00a7b610 const*);
};
struct C70940Obj
{
    void FUN_00c70940(float delta);
    __forceinline unsigned char GetFlags() const
    {
        return flags414 >> 20;
    }
    __forceinline float GetCurrent() const
    {
        return current5f8;
    }
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    unsigned int flags414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int state5a0;
    C70940Src* src5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    float target5f0;
    int unk5f4;
    float current5f8;
    int unk5fc;
    int mode600;
};
// @fnv 0x00c70b60
void C70B60Character::FUN_00c70b60(C70B60UpdateData* pkData, bool bForce)
{
    bool bStatic = FUN_00ca9600(m_acState) == 2;
    if (bForce && bStatic)
    {
        pkData->m_kValue = (*reinterpret_cast<const ::C70B60Point3 *>((void *)&::NiPoint3::ZERO));
        ApplyUpdate(pkData);
        return;
    }
    reinterpret_cast<::C70940Obj *>(this)->FUN_00c70940(pkData->m_fTime);
}
// While mode600 is 2, moves the cast scale toward GetCurrent() by delta*5.0, shifts vecA and vecB Z, then updates mode600 and state5a0 on arrival.
// @fnv 0x00c70940
void C70940Obj::FUN_00c70940(float delta)
{
    if (mode600 != 2)
        return;
    float value;
    C70940Cast* cast;
    if (src5a4 && (cast = src5a4->FUN_00653290(&g_0126832c)) != 0)
    {
        if (GetFlags() & 1)
            delta = ::DAT_01016410;
        C70940Node* node = cast->node;
        float step = cast->GetScale();
        value = step;
        step = delta * 5.0;
        if (value > GetCurrent())
        {
            float candidate = value - step;
            if (candidate <= GetCurrent())
            {
                step = GetCurrent() - value;
                value = GetCurrent();
            }
            else
            {
                step = -step;
                value = candidate;
            }
        }
        else
        {
            _ReadWriteBarrier();
            float candidate = *static_cast<volatile float*>(&step) + value;
            if (candidate >= GetCurrent())
            {
                step = GetCurrent() - value;
                value = GetCurrent();
            }
            else
            {
                value = candidate;
            }
        }
        C70940Vec a;
        a.q = (node ? &node->vecA : reinterpret_cast<const C70940Vec*>(&DAT_01267e30))->q;
        C70940Vec b;
        b.q = (node ? &node->vecB : reinterpret_cast<const C70940Vec*>(&DAT_01267e30))->q;
        a.q[2] -= step;
        b.q[2] += step;
        if (node)
        {
            node->vecA = a;
            node->vecA.q = a.q;
            node->vecA.q[3] = node->scale;
        }
        C70940Node* nodeB = cast->node;
        if (nodeB)
        {
            nodeB->vecB = b;
            nodeB->vecB.q = b.q;
            nodeB->vecB.q[3] = nodeB->scale;
        }
        if (cast->node)
            cast->node->scale = value;
    }
    else
    {
        value = GetCurrent();
    }
    if (value == GetCurrent())
    {
        if (value == target5f0)
        {
            if (state5a0 != 2)
            {
                reinterpret_cast<::ControllerShell *>(this)->SetMode(state5a0);
                state5a0 = 2;
            }
            mode600 = 0;
        }
        else
        {
            mode600 = 1;
        }
    }
}


class AutoMemContextC73
{
  public:
    AutoMemContextC73(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = m_uiGeometryShaderFlags;
    }
    ~AutoMemContextC73()
    {
        g_tlsBlock.memoryContext = m_uiPrevious;
    }
    unsigned int m_uiPrevious;
};

struct EntryC73
{
    int iA;
    int iB;
};
struct hkArrayC73
{
    EntryC73* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~hkArrayC73()
    {
        hkMemoryAllocator& kHeap = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kHeap.bufFree(m_data, int((m_iCapacityState & 0x3fffffff) * sizeof(EntryC73)));
    }
};

struct __declspec(align(16)) DescriptorC73
{
    DescriptorC73();
    int iValue;
    void* pvHandle;
    int unk08;
    hkArrayC73 kArray;
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
};

struct PropertyC73
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    short unk14;
    char bEnabled;
    char unk17;
};
struct InputC73
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
    void* pvHandle;
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
    int unk84;
    PropertyC73* pkProperty;
    float fValue8c;
    float fValue90;
    char unk94;
    char unk95;
    char unk96;
    char bFlag97;
    char bFlag98;
    char unk99;
    char unk9a;
    char unk9b;
    int iValue9c;
    int unka0;
    int unka4;
    float fValuea8;
    float fValueac;
    int unkb0;
    int iValueb4;
    float GetA() const
    {
        return fValuea8;
    }
    float GetB() const
    {
        return fValueac;
    }
};
struct ResourceC73
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void SetProperty(PropertyC73*);
    volatile long m_lRefs;
    void* pvHandle;
    int unk0c;
    int unk10;
    int unk14;
    ResourceC73(DescriptorC73*);
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_lRefs))
            v004();
    }
};
struct ResourcePtrC73
{
    ResourceC73* m_pObject;
    ResourcePtrC73& operator=(ResourceC73* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct FlagsC73
{
    int unk00;
    unsigned int m_uiValue1;
    void SetBit(unsigned int b, bool on)
    {
        if (on)
            m_uiValue1 |= b;
        else
            m_uiValue1 &= ~b;
    }
};
struct NodeC73
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
    bool m_bDecalsEnabled;
};
extern float DAT_010c44ac;
struct ControllerC73
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void Toggle(int);
    int unk004;
    NodeC73* pkNode;
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
    unsigned int unkd8;
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
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    FlagsC73 kFlags;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    float fScale;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    int iValue520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    float fValue534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    float fValue54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    ResourcePtrC73 kPrimary;
    ResourceC73* pkSecondary;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    int iValue604;
    void SetScale(float f)
    {
        fScale = f;
    }
    void Initialize(InputC73*);
    void Update(InputC73*);
    void FUN_00c73ed0(InputC73*);
};

// Initialises the controller from pkInput, configures its primary and secondary resources, copies input values, and applies flags to pkNode.
// @fnv 0x00c73ed0
void ControllerC73::FUN_00c73ed0(InputC73* pkInput)
{
    AutoMemContextC73 kContext(0x10);
    SetScale(pkInput->fValueac * pkInput->fValuea8);
    reinterpret_cast<::ShapeOwner *>(this)->FUN_00c72410((::ShapeInput *)(pkInput));
    ResourceC73* pkCur = kPrimary.m_pObject;
    if (!pkCur)
    {
        DescriptorC73 kDesc;
        kDesc.iValue = pkInput->unk84;
        ResourceC73* pkSource = ((::ResourceC73 *)(reinterpret_cast<::Holder *>(this)->GetCurrentObject()));
        kDesc.pvHandle = pkSource ? pkSource->pvHandle : 0;
        kPrimary = new ResourceC73(&kDesc);
    }
    if (pkInput->pkProperty)
    {
        if (kPrimary.m_pObject)
        {
            kPrimary.m_pObject->SetProperty(pkInput->pkProperty);
            ResourceC73* pkRes = kPrimary.m_pObject;
            PropertyC73* pkProp = pkInput->pkProperty;
            reinterpret_cast<::C68E30Owner *>((pkProp))->FUN_00c68e30((::C68E30Holder *)(pkRes), ((int)(::PackColorBigEndian(1.0f, 1.0f, 0.0f, DAT_010c44ac))));
            if (pkInput->pkProperty->bEnabled)
                Toggle(0);
        }
        if (pkSecondary)
            pkSecondary->SetProperty(pkInput->pkProperty);
    }
    iValue520 = pkInput->iValue9c;
    fValue534 = pkInput->fValue8c;
    fValue54c = pkInput->fValue90;
    iValue604 = pkInput->iValueb4;
    pkInput->pvHandle = kPrimary.m_pObject ? kPrimary.m_pObject->pvHandle : 0;
    reinterpret_cast<::CAC300Owner *>(this)->FUN_00cac300((intptr_t)(pkInput));
    if (pkNode->m_bDecalsEnabled)
        pkNode->m_bDecalsEnabled = true;
    else
        pkNode->m_bDecalsEnabled = true;
    FlagsC73& kFlagsRef = kFlags;
    kFlagsRef.SetBit(0x2000000, pkInput->bFlag97 != 0);
    kFlagsRef.SetBit(0x4000000, pkInput->bFlag98 != 0);
    NodeC73* pkN = pkNode;
    if (pkN)
    {
        reinterpret_cast<::FUN_00cac110_Class *>(this)->FUN_00cac110();
        reinterpret_cast<::fnv_00cada30::FUN_00cada30_cls *>((pkN))->AppendPointer(&kFlagsRef);
        reinterpret_cast<::FUN_00cac110_Class *>(this)->FUN_00cac110();
    }
}

struct Scalar74
{
    __m128 value;
    __forceinline Scalar74(__m128 v) : value(v)
    {}
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
struct Vec74
{
    __m128 value;
    __forceinline Scalar74 component(int i) const
    {
        switch (i)
        {
        case 0:
            return value;
        case 1:
            return _mm_shuffle_ps(value, value, 0x55);
        case 2:
            return _mm_shuffle_ps(value, value, 0xaa);
        default:
            return _mm_shuffle_ps(value, value, 0xff);
        }
    }
    __forceinline void cross(const Vec74& a, const Vec74& b)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(p, q);
    }
    __forceinline void subtractScaled(const Scalar74& s, const Vec74& a)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline void addScaled(const Scalar74& s, const Vec74& a)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline Scalar74 dot(const Vec74& a) const
    {
        __m128 p = _mm_mul_ps(value, a.value);
        __m128 h = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
        __m128 k = _mm_shuffle_ps(h, h, 0xb1);
        return _mm_add_ps(h, k);
    }
    __forceinline void splat(const Scalar74& s)
    {
        value = s.broadcast();
    }
    __forceinline void combine(const Vec74& xyz, const Vec74& w)
    {
        value = _mm_shuffle_ps(xyz.value, _mm_unpackhi_ps(xyz.value, w.value), 0xc4);
    }
};
struct Quat74
{
    Vec74 value;
    void FUN_00c74ac0(const Quat74& a, const Quat74& b);
};
// Combines quaternions a and b: xyz from b cross a, minus a.w times b, plus b.w times a, with w set from the 4D dot of a and b.
// @fnv 0x00c74ac0
void Quat74::FUN_00c74ac0(const Quat74& a, const Quat74& b)
{
    Vec74 xyz;
    xyz.cross(b.value, a.value);
    xyz.subtractScaled(a.value.component(3), b.value);
    xyz.addScaled(b.value.component(3), a.value);
    Vec74 w;
    w.splat(a.value.dot(b.value));
    value.combine(xyz, w);
}

inline float MulPart(float a, float b)
{
    return a * b;
}
inline float GetFade(unsigned char a)
{
    if (!a)
        return 1.0f;
    return 0.0f;
}
struct V3Local
{
    float x, y, z;
    float Y() const
    {
        return y;
    }
    float Z() const
    {
        return z;
    }
};
union V4Local
{
    __m128 q;
    struct
    {
        float x, y, z, w;
    };
};
static float DAT_01267c20;
void SetScaleLocal(float v)
{
    DAT_01267c20 = v;
}
extern float DAT_01267dfc;
struct SourceLocal
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
    V3Local position;
};
struct TransformLocal
{
    __m128 value;
};
struct DescriptorLocal
{
    unsigned short w0, w1, w2, w3, w4, w5;
    float m0c;
    __m128 direction;
    float m20, m24, weight0, weight1, m30, m34, m38, m3c;
    __m128 position;
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
    void FUN_00c74ed0();
};
void __cdecl FUN_00cdbae0(void*, DescriptorLocal*, void*);
struct StateLocal
{
    SourceLocal* source;
    float blend, weight;
    unsigned char active, fading;
    unsigned short unk0e;
    __m128 position, direction;
};
struct ControllerLocal
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
    void* target;
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
    int unkf8;
    int unkfc;
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
    StateLocal states[2];
    unsigned short ids[7];
    unsigned char active, unk21f;
    void FUN_00c751f0(void* arg);
};
// For each active state, blends position when not fading, moves weight toward 1 (0 if fading), then deactivates it once faded out or emits via FUN_00cdbae0.
// @fnv 0x00c751f0
void ControllerLocal::FUN_00c751f0(void* arg)
{
    float zero = 0.0f;
    unsigned char result;
    unsigned short* idsAt = ids + 1;
    for (int i = 0; i < 2; ++i)
    {
        StateLocal* state = &states[i];
        if (state->active)
        {
            unsigned char fading = state->fading;
            float fadeTarget;
            if (!fading)
            {
                V3Local point = state->source->position;
                V4Local scaled;
                scaled.x = DAT_01267c20 * point.x;
                scaled.y = DAT_01267c20 * point.Y();
                scaled.z = DAT_01267c20 * point.Z();
                scaled.w = zero;
                __m128 direction = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
                if (state->weight > zero)
                {

                    __m128 blend = _mm_set1_ps(state->blend);
                    state->position =
                        _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps((*reinterpret_cast<const float (*)[4]>((void *)&::DAT_010ec7f0))), blend), state->position),
                                   _mm_mul_ps(scaled.q, blend));
                    __m128 blend2 = _mm_shuffle_ps(_mm_load_ss(&state->blend), _mm_load_ss(&state->blend), 0);
                    state->direction =
                        _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps((*reinterpret_cast<const float (*)[4]>((void *)&::DAT_010ec7f0))), blend2), state->direction),
                                   _mm_mul_ps(blend2, direction));
                }
                else
                {
                    state->position = *(__m128*)&scaled;
                    state->direction = direction;
                }
            }
            if (!state->fading)
                fadeTarget = 1.0f;
            else
                fadeTarget = zero;
            fadeTarget = (fadeTarget - state->weight) * DAT_01267dfc + state->weight;
            state->weight = fadeTarget;
            if (state->weight < 0.01f && fading)
            {
                state->fading = 0;
                state->weight = zero;
                state->active = 0;
            }
            else
            {
                TransformLocal transformed;
                reinterpret_cast<::InversePositionVector *>(&(transformed))->FUN_00c7f840((const ::Vec4 *)(arg), (const ::Vec4 *)(__m128 *)(&state->position));
                DescriptorLocal descriptor;
                new ((void *)&(descriptor)) ::fnv_00c74ed0::FUN_00c74ed0();
                descriptor.weight0 = state->weight;
                descriptor.weight1 = state->weight;
                descriptor.w0 = idsAt[-1];
                descriptor.w1 = idsAt[0];
                descriptor.w2 = idsAt[1];
                descriptor.direction = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
                descriptor.position = transformed.value;
                FUN_00cdbae0(&result, &descriptor, target);
            }
        }
        idsAt += 3;
    }
    if (!states[0].active && !states[1].active)
        active = 0;
}

#include <math.h>
namespace fnv_00c77460 {
extern const float DAT_01013ea4 = 0.01f;
extern const float DAT_01012054;
struct Transform;

struct __declspec(align(16)) Vec
{
    __m128 q;
    struct Component
    {
        const float& value;
        Component(const float& f) : value(f)
        {}
        operator double() const
        {
            return value;
        }
    };
    Component z() const
    {
        return Component(q[2]);
    }
    __forceinline Vec& operator=(const Vec& b)
    {
        q = b.q;
        return *this;
    }
    void interpolate(const Vec& a, const Vec& b, const float& f)
    {
        __m128 t = _mm_load1_ps(&f);
        q = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, t), a.q), _mm_mul_ps(t, b.q));
    }
    int near3(const Vec& b, float eps) const
    {
        __m128 d = _mm_and_ps(_mm_sub_ps(q, b.q), ::DAT_01017d10);
        __m128 e = _mm_set1_ps(eps);
        return (_mm_movemask_ps(_mm_cmple_ps(d, e)) & 7) == 7;
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        __m128 sq = _mm_mul_ps(q, q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        __m128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xy);
        __m128 mask = _mm_cmpeq_ss(len, zero);
        __m128 approx = _mm_rsqrt_ss(len);
        __m128 scale = _mm_andnot_ps(
            mask, _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, approx), approx))));
        q = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), q);
    }
    __forceinline void rotate(const Vec& rot, const Vec& dir)
    {
        __m128 r = _mm_shuffle_ps(rot.q, rot.q, 0xff);
        __m128 base = _mm_add_ps(::DAT_010c71e0, _mm_mul_ps(r, r));
        __m128 ret = _mm_mul_ps(base, dir.q);
        __m128 prod = _mm_mul_ps(rot.q, dir.q);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), rot.q));
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(rot.q, rot.q, 0xc9), _mm_shuffle_ps(dir.q, dir.q, 0xd2)),
                                  _mm_mul_ps(_mm_shuffle_ps(rot.q, rot.q, 0xd2), _mm_shuffle_ps(dir.q, dir.q, 0xc9)));
        ret = _mm_add_ps(ret, _mm_mul_ps(r, cross));
        q = _mm_add_ps(ret, ret);
    }
};
struct RayInput
{
    Vec from, to;
    bool collection;
    unsigned filter;
    int unk28, unk2c;
    RayInput() : collection(false)
    {}
};
struct RayOutput
{
    Vec normal;
    float fraction;
    int shapeKey, unk18, unk1c;
    int otherKey, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    void* object40;
    int unk44, unk48, unk4c;
    void* object50;
    int unk54, unk58, unk5c;
    RayOutput()
    {
        fraction = 1.0f;
        shapeKey = -1;
        object40 = 0;
        otherKey = -1;
        object50 = 0;
    }
};
struct PickData
{
    RayInput input;
    RayOutput output;
    Vec extra;
    int unkA0, unkA4, unkA8;
    bool flagAC;
    PickData(unsigned id)
    {
        unkA0 = 0;
        unkA4 = 0;
        unkA8 = 0;
        flagAC = false;
        input.filter = id;
    }
};
struct RayWorld
{
};
struct Transform
{
    Vec translation, rotation, scale;
};
struct Body
{
    int unk00, unk04, unk08, unk0c;
    Transform* transform;
    int unk14, unk18;
    unsigned char* flags;
    Transform* getTransform()
    {
        if (!(*flags & 2))
            return transform;
        return ((::fnv_00c77460::Transform *)&(reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(0)));
    }
};
struct CastObject
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
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual bool cast(PickData*);
};
struct RayRefObject
{
    int unk000;
    int unk004;
    RayRefObject* object;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    CastObject* world;
    CastObject* resolve()
    {
        if (this && object)
            return object->world;
        return 0;
    }
};
struct RefLink
{
    RayRefObject* object;
};
struct OwnerRef
{
    int unk00, unk04;
    RefLink* link;
};
struct CachedRay
{
    Vec from, to, normal;
    float fraction;
    int unk34, unk38, unk3c;
};
struct CacheGroup
{
    Vec header;
    CachedRay rays[3];
};
struct ControllerRay
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    Vec position;

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
    OwnerRef* owner;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    unsigned filter;
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
    Body* body;
    int unk08c;
    RayWorld* world;
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
    bool useRayWorld;
    int unk228;
    CacheGroup* cache;
    int mode;
    int unk234;
    unsigned short rayIndex, groupIndex;
    int unk23c;
    bool keepNormal;
    bool* FUN_00c77460(bool* hitOut, const Vec& from, const Vec& to, float* fraction, Vec& normal);
    CastObject* pLoadedObject()
    {
        if (owner)
        {
            return owner->link->object->resolve();
        }
        return 0;
    }
};
// Reuses a cached ray result if from/to match, else casts via an object or ray world; writes hit, fraction and normal and updates the cache.
// @fnv 0x00c77460
bool* ControllerRay::FUN_00c77460(bool* hitOut, const Vec& from, const Vec& to, float* fraction, Vec& normal)
{
    bool hit = false;
    if (cache[groupIndex].rays[rayIndex].fraction != ::DAT_01012054 &&
        cache[groupIndex].rays[rayIndex].from.near3(from, DAT_01013ea4) &&
        cache[groupIndex].rays[rayIndex].to.near3(to, DAT_01013ea4))
    {
        normal = cache[groupIndex].rays[rayIndex].normal;
        Vec previous;
        previous.interpolate(cache[groupIndex].rays[rayIndex].from, cache[groupIndex].rays[rayIndex].to,
                             cache[groupIndex].rays[rayIndex].fraction);
        *fraction = (from.z() - previous.z()) / (from.z() - to.z());
        hit = true;
    }
    else
    {
        unsigned filterId = filter;
        ::ShadowLightData::SetTargetMaskForSelection(39, 0x2002200e);
        unsigned computedFilter = (filterId << 16) | 39;
        PickData pick(computedFilter);
        pick.input.from = from;
        pick.extra.q = *reinterpret_cast<__m128*>(&DAT_01267e30);
        pick.input.to = to;
        if (!useRayWorld)
        {
            if (pLoadedObject()->cast(&pick))
            {
                *fraction = pick.output.fraction;
                Vec n = pick.output.normal;
                n.normalize();
                normal = n;
                hit = true;
            }
        }
        else if (world)
        {
            RayInput input;
            RayOutput output;
            input.filter = computedFilter;
            input.from = from;
            input.to = to;
            reinterpret_cast<::PickSelf *>((world))->FUN_00cc26c0((::RayArg *)(&input), (::BestOut *)(::fnv_00c77460::RayOutput *)(&output));
            if (output.object50)
            {
                *fraction = output.fraction;
                Vec n = output.normal;
                n.normalize();
                normal = n;
                hit = true;
            }
        }
    }
    Vec local;
    Vec contact;
    contact.interpolate(from, to, hit ? *fraction : 0.0f);
    if (!hit)
    {
        cache[groupIndex].rays[rayIndex].fraction = ::DAT_01012054;
    }
    else
    {
        reinterpret_cast<::TransformedPosDAD *>(&(local))->FUN_00c7f7a0((*(const ::hkQsTransformDAD *)(&position)), (*(const ::hkVector4DAD *)(body->getTransform())));
        Vec up;
        up.q = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
        Vec rotated;
        rotated.rotate(body->getTransform()->rotation, up);
        if (mode == 2 && fabsf(rotated.z()) > 0.2f)
        {
            if (contact.z() > local.z() - 2.0)
                *fraction = (from.z() - contact.z() + 2.0) / (from.z() - to.z());
        }
        if (!keepNormal)
            normal = up;
        cache[groupIndex].rays[rayIndex].from = from;
        cache[groupIndex].rays[rayIndex].to = to;
        cache[groupIndex].rays[rayIndex].normal = normal;
        cache[groupIndex].rays[rayIndex].fraction = *fraction;
    }
    ++rayIndex;
    *hitOut = hit;
    return hitOut;
}
}  // namespace fnv_00c77460

struct S00c79e20_StrPtr
{
    const char* m_str;
};
struct S00c79e20_Bone
{
    S00c79e20_StrPtr m_name;
    bool m_bLockTranslation;
};
struct S00c79e20_Skeleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00c79e20_Bone* m_kBones;
    int m_iBoneCount;
};
struct S00c79e20_Mapping
{
    short m_sBoneA;
    short m_sBoneB;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_vTranslation;
    __m128 m_rotation;
    __m128 m_vScale;
};
struct S00c79e20_MapperData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    const S00c79e20_Bone& boneA(int i) const
    {
        return m_pSkeletonA->m_kBones[i];
    }
    const S00c79e20_Bone& boneB(int i) const
    {
        S00c79e20_Skeleton* s = m_pSkeletonB;
        return s->m_kBones[i];
    }
    S00c79e20_Skeleton* m_pSkeletonA;
    S00c79e20_Skeleton* m_pSkeletonB;
    S00c79e20_Mapping* m_kMappings;
    int m_numMappings;
    int size() const
    {
        return m_numMappings;
    }
};
template <class T> struct S00c79e20_RefPtr
{
    T* m_pRetainedObject;
    T* operator->() const
    {
        return m_pRetainedObject;
    }
    operator T*() const
    {
        return m_pRetainedObject;
    }
    T* val() const
    {
        return m_pRetainedObject;
    }
};
struct S00c79e20_Mapper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00c79e20_MapperData* m_mappers[2];
};
struct S00c79e20_RTTI
{
    const char* m_name;
    const S00c79e20_RTTI* m_base;
};
struct S00c79e20_Target
{
    virtual void v00();
    virtual void v04();
    virtual const S00c79e20_RTTI* GetRTTI() const;
    void* FUN_00653290(const S00c79e20_RTTI* rtti);
    bool IsKindOfType(const S00c79e20_RTTI* rtti) const
    {
        for (const S00c79e20_RTTI* r = GetRTTI(); r; r = r->m_base)
        {
            if (r == rtti)
                return true;
        }
        return false;
    }
};
static inline bool S00c79e20_IsKindOf(const S00c79e20_RTTI* rtti, const S00c79e20_Target* obj)
{
    return obj && obj->IsKindOfType(rtti);
}
struct S00c79e20_Node
{
    int unk00;
    int unk04;
    int unk08;
    S00c79e20_Target* m_target;
};
struct S00c79e20_Owner
{
    int unk00;
    int unk04;
    S00c79e20_Node** m_kNodeCollection;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_remap;
    S00c79e20_Target* GetTarget(int bone) const
    {
        int idx = m_remap[bone];
        if (idx < 0)
            return 0;
        S00c79e20_Node* n = m_kNodeCollection[idx];
        if (!n)
            return 0;
        return n->m_target;
    }
};
struct S00c79e20_Ostream
{
    void* m_vtbl;
    int m_iObjectReferenceCount;
    void* m_pStreamWriter;
    S00c79e20_Ostream(char* buf, int size)
    {
        new ((void *)this) ::FUN_00cb1600(buf, size);
    }
    ~S00c79e20_Ostream()
    {
        reinterpret_cast<struct ::FUN_00cc00e0 *>(this)->FUN_00cc00e0::~FUN_00cc00e0();
    }
    S00c79e20_Ostream& operator<<(const char* s)
    {
        return (*(::S00c79e20_Ostream *)(reinterpret_cast<::SinkOwner *>(this)->FUN_00cc01c0(s)));
    }
    S00c79e20_Ostream& operator<<(const S00c79e20_StrPtr& s)
    {
        return (*(::S00c79e20_Ostream *)(reinterpret_cast<::AttributeFormatter *>(this)->WriteName((::NameReference *)&(s))));
    }
    S00c79e20_Ostream& operator<<(float f)
    {
        return (*(::S00c79e20_Ostream *)(reinterpret_cast<::FloatArgStream *>(this)->WriteFloat(f)));
    }
};
struct S00c79e20_Error
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void message(int type, int id, const char* desc, const char* file, int line);
};
extern const float DAT_01013ea4;
extern const char str_010c4d7c[];
extern const char str_010c4d88[];
extern const char str_010c4d90[];
extern const char str_010c4db0[];
extern const char str_010c4d38[];

struct S00c79e20_SimdReal
{
    float m_vValue;
    S00c79e20_SimdReal(const __m128& r)
    {
        _mm_store_ss(&m_vValue, r);
    }
    operator const float&() const
    {
        return m_vValue;
    }
};
static __forceinline S00c79e20_SimdReal S00c79e20_Length3(const __m128& v)
{
    __m128 r = _mm_mul_ps(v, v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(r, r, 0x55), r);
    r = _mm_shuffle_ps(r, r, 0xaa);
    r = _mm_add_ss(r, s);
    return _mm_sqrt_ss(r);
}

struct S00c79e20_Ctrl
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
    S00c79e20_Owner* m_pOwnerObject;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    S00c79e20_RefPtr<S00c79e20_Mapper> m_mapper;
    bool FUN_00c79e20();
};

// Logs mappings where bone B locks translation, no target matches and translation length exceeds 0.01; returns true if it logged or a mapper is missing.
// @fnv 0x00c79e20
bool S00c79e20_Ctrl::FUN_00c79e20()
{
    bool warned = false;
    if (!m_mapper || !m_mapper->m_mappers[0] || !m_mapper->m_mappers[1])
    {
        warned = true;
        goto done;
    }

    for (int i = 0; i < m_mapper->m_mappers[0]->size(); i++)
    {
        const S00c79e20_Mapping& m = m_mapper->m_mappers[0]->m_kMappings[i];
        short a = m.m_sBoneA;
        short b = m.m_sBoneB;
        const S00c79e20_Bone& boneA = m_mapper->m_mappers[0]->boneA(a);
        const S00c79e20_Bone& boneB = m_mapper->m_mappers[0]->boneB(b);
        S00c79e20_Target* t = m_pOwnerObject->GetTarget(b);
        void* p = !t ? 0 : t->FUN_00653290(&(*reinterpret_cast<::S00c79e20_RTTI *>(&::g_012683c8)));
        if (boneB.m_bLockTranslation && !p)
        {
            S00c79e20_SimdReal len = S00c79e20_Length3(m.m_vTranslation);
            if (len.m_vValue > 0.01f)
            {
                {
                    char buf[512];
                    S00c79e20_Ostream os(buf, sizeof(buf));
                    reinterpret_cast<::SinkOwner *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::FloatArgStream *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::SinkOwner *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::AttributeFormatter *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::SinkOwner *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::AttributeFormatter *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::SinkOwner *>(&(os))->FUN_00cc01c0(str_010c4d7c)))))->WriteName((::NameReference *)&(boneA.m_name))))))->FUN_00cc01c0(str_010c4d88)))))->WriteName((::NameReference *)&(boneB.m_name))))))->FUN_00cc01c0(str_010c4d90)))))->WriteFloat(len)))))->FUN_00cc01c0(str_010c4db0);
                    (*reinterpret_cast<::S00c79e20_Error * *>(&::DAT_01268360))->message(1, 0xbadbadba, buf, str_010c4d38, 0xc1f);
                }
                warned = true;
            }
        }
    }
    for (int i = 0; i < m_mapper->m_mappers[1]->size(); i++)
    {
        const S00c79e20_Mapping& m = m_mapper->m_mappers[1]->m_kMappings[i];
        short a = m.m_sBoneA;
        short b = m.m_sBoneB;
        const S00c79e20_Bone& boneA = m_mapper->m_mappers[1]->boneA(a);
        const S00c79e20_Bone& boneB = m_mapper->m_mappers[1]->boneB(b);
        S00c79e20_Target* t = m_pOwnerObject->GetTarget(a);
        void* p = !t ? 0 : (t->IsKindOfType(&(*reinterpret_cast<::S00c79e20_RTTI *>(&::g_012683c8))) ? t : 0);
        if (boneB.m_bLockTranslation && !p)
        {
            S00c79e20_SimdReal len = S00c79e20_Length3(m.m_vTranslation);
            if (len.m_vValue > 0.01f)
            {
                {
                    char buf[512];
                    S00c79e20_Ostream os(buf, sizeof(buf));
                    reinterpret_cast<::SinkOwner *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::FloatArgStream *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::SinkOwner *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::AttributeFormatter *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::SinkOwner *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::AttributeFormatter *>(&((*(::S00c79e20_Ostream *)(reinterpret_cast<::SinkOwner *>(&(os))->FUN_00cc01c0(str_010c4d7c)))))->WriteName((::NameReference *)&(boneA.m_name))))))->FUN_00cc01c0(str_010c4d88)))))->WriteName((::NameReference *)&(boneB.m_name))))))->FUN_00cc01c0(str_010c4d90)))))->WriteFloat(len)))))->FUN_00cc01c0(str_010c4db0);
                    (*reinterpret_cast<::S00c79e20_Error * *>(&::DAT_01268360))->message(1, 0xbadbadba, buf, str_010c4d38, 0xc39);
                }
                warned = true;
            }
        }
    }
done:
    return warned;
}

struct SmallFlag
{
    char value;
    SmallFlag()
    {}
    SmallFlag(bool b) : value(b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct S_00c7fb50_item;
struct S_00c7fb50_portal;
struct S_00c7fb50_node;
struct S_00c7fb50_vtable
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    int(* get_type)(S_00c7fb50_node*);
};
struct S_00c7fb50_node
{
    S_00c7fb50_vtable* vtbl;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    unsigned short index_1c;
    SmallFlag Broken(const S_00c7fb50_item* x) const;
};
struct S_00c7fb50_data
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    SmallFlag* bytes_1c;
};
struct S_00c7fb50_item
{
    void* unk00;
    void* unk04;
    void* unk08;
    S_00c7fb50_node* node_0c;
    void* unk10;
    void* next_14;
    void* next_18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    S_00c7fb50_data* data_30;
    const S_00c7fb50_node* Data() const
    {
        return node_0c;
    }
    S_00c7fb50_node* DataRw()
    {
        return node_0c;
    }
    S_00c7fb50_portal* BodyA() const
    {
        return (S_00c7fb50_portal*)next_14;
    }
    S_00c7fb50_portal* BodyB() const
    {
        return (S_00c7fb50_portal*)next_18;
    }
};
struct PortalEntry
{
    S_00c7fb50_item* item;
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
};
struct S_00c7fb50_portal
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unk_a0;
    void* unk_a4;
    void* unk_a8;
    PortalEntry* items_ac;
    unsigned short count_b0;
    int Count() const
    {
        return count_b0;
    }
    const PortalEntry& At(int i) const
    {
        return items_ac[i];
    }
};
extern "C" void _ReadWriteBarrier(void);
inline SmallFlag S_00c7fb50_node::Broken(const S_00c7fb50_item* x) const
{
    return x->data_30->bytes_1c[index_1c];
}
// Returns portal if all items are type 11 or broken type 12; otherwise recurses into the other body of the first item that is neither.
// @fnv 0x00c7fb50
S_00c7fb50_portal* __cdecl FUN_00c7fb50(S_00c7fb50_portal* portal)
{
    if (portal)
    {

        bool all = true;
        for (int i = 0; i < portal->Count(); ++i)
        {
            if (!all)
                break;
            const S_00c7fb50_node* node = portal->At(i).item->Data();
            all = node->vtbl->get_type((S_00c7fb50_node*)node) == 11;
        }
        if (!all)
        {
            for (int j = 0; j < portal->Count(); ++j)
            {
                S_00c7fb50_item* item = portal->At(j).item;
                if (item->Data()->vtbl->get_type((S_00c7fb50_node*)item->Data()) != 11)
                {
                    bool broken = false;
                    if (item->Data()->vtbl->get_type((S_00c7fb50_node*)item->Data()) == 12)
                    {
                        S_00c7fb50_node* data = item->DataRw();
                        broken = data->Broken(item);
                    }
                    if (!broken)
                    {
                        S_00c7fb50_portal* next = item->BodyA() == portal ? item->BodyB() : item->BodyA();
                        return FUN_00c7fb50(next);
                    }
                }
            }
        }
    }
    return portal;
}

namespace fnv_00c68de0 {
// Reconstruction of FUN_00c68de0 (0x00c68de0, 74 bytes).
// member of a Havok-style world object:
//   * +0x10 holds a pointer to a polymorphic object whose vtable slot 3 takes a float
//   * a TLS index global is passed to TlsGetValue, the result is fed to a byte-copy helper
//   * a global holder's +0x18 member is called virtually (vtable slot 9) when non-null
//   * the last statement tail-calls the inherited cleanup at 0x00c688b0

struct FNV_C68DE0_VA
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(float f);
};

struct FNV_C68DE0_VB
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
};

struct FNV_C68DE0_HOLDER
{
    void* h00;
    void* h04;
    void* h08;
    void* h0c;
    void* h10;
    void* h14;
    FNV_C68DE0_VB* h18;
};



struct FNV_C68DE0_OWNER
{
    void* o00;
    void* o04;
    void* o08;
    void* o0c;
    FNV_C68DE0_VA* o10;
    void FUN_00c68de0();
};

// If o10 is set, calls o10->v3(0.0f), passes the TLS value to FUN_00cb0da0 and calls w9 on the holder's h18 object, then calls FUN_00c688b0.
// @fnv 0x00c68de0
void FNV_C68DE0_OWNER::FUN_00c68de0()
{
    if (o10)
    {
        o10->v3(0.0f);
        ::FUN_00cb0da0((::S_00cb0da0 *)(void *)((void*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)))));
        FNV_C68DE0_VB* b = (*reinterpret_cast<::fnv_00c68de0::FNV_C68DE0_HOLDER * *>(&::DAT_012677d0))->h18;
        if (b)
        {
            b->w9();
        }
    }
    reinterpret_cast<::FUN_00c688b0_cls *>(this)->FUN_00c688b0();
}
}  // namespace fnv_00c68de0

namespace fnv_00c6aac0 {


struct hkWorldObjectStub;

template <class T> struct hkLocalArrayStub
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkLocalArrayStub() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkLocalArrayStub()
    {
        hkMemoryAllocator* alloc = hkMemoryRouter::getInstance().m_heap;
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc->bufFree(m_data, int((m_iCapacityState & 0x3fffffff) * sizeof(T)));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkEntityStub
{
    int unk00;
    int unk04;
    struct bhkWorldStub* m_pOwningWorld;
};

struct bhkWorldStub
{
};

struct hkEntityRefStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void GetConstraints(hkLocalArrayStub<hkEntityStub*>* out);
    int unk04;
    bhkWorldStub* m_pOwningWorld;
};

struct TlsStateScope
{
    int m_saved;
    TlsStateScope()
    {
        m_saved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 0x10;
    }
    ~TlsStateScope()
    {
        g_tlsBlock.memoryContext = m_saved;
    }
};

struct FUN_00c6aac0_Base
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
    virtual bhkWorldStub* GetWorld();
};

struct FUN_00c6aac0_Owner : FUN_00c6aac0_Base
{
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
    hkEntityRefStub** m_pDataAtOffset94;
    unsigned int m_pendingCount;

    void FUN_00c6aac0();
};

// @fnv 0x00c6aac0
void FUN_00c6aac0_Owner::FUN_00c6aac0()
{
    TlsStateScope scope;
    if (m_pendingCount > 0)
    {
        if (m_pendingCount >= 100)
            m_pendingCount = 100;
        bhkWorldStub* world = GetWorld();
        if (world)
        {
            for (unsigned int i = 0; i < m_pendingCount; i++)
            {
                if (m_pDataAtOffset94[i] && !m_pDataAtOffset94[i]->m_pOwningWorld)
                {
                    hkLocalArrayStub<hkEntityStub*> list;
                    m_pDataAtOffset94[i]->GetConstraints(&list);
                    bool ok = true;
                    for (int j = 0; j < list.m_iElementCount; j++)
                    {
                        if (!ok)
                            break;
                        ok = list.m_data[j]->m_pOwningWorld == world;
                    }
                    if (ok)
                        reinterpret_cast<::hkpWorldC97 *>((world))->FUN_00c97370((::hkpActionC97 *)(m_pDataAtOffset94[i]));
                }
                if (m_pDataAtOffset94[i])
                    reinterpret_cast<::hkReferencedObjectC905 *>((m_pDataAtOffset94[i]))->FUN_00c905b0();
            }
            std::memset(m_pDataAtOffset94, 0, m_pendingCount * 4);
            m_pendingCount = 0;
        }
    }
}
}  // namespace fnv_00c6aac0

extern float DAT_011b05a8;

class S00c78160_Simd
{
  public:
    __forceinline S00c78160_Simd(const __m128& x) : m_vValue(x)
    {}
    __forceinline S00c78160_Simd(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

struct S00c78160_Quat;
struct S00c78160_Xf;

class S00c78160_V4
{
  public:
    __forceinline S00c78160_V4()
    {}
    __forceinline S00c78160_V4(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline S00c78160_V4(const S00c78160_V4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const S00c78160_V4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline __m128& getQuad()
    {
        return m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void add4(const S00c78160_V4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setAdd4(const S00c78160_V4& a, const S00c78160_V4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setSub4(const S00c78160_V4& a, const S00c78160_V4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const S00c78160_V4& a, const S00c78160_V4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const S00c78160_Simd& s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline void addMul4(const S00c78160_V4& x, const S00c78160_V4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const S00c78160_V4& a, const S00c78160_V4& x, const S00c78160_V4& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const S00c78160_V4& a, const S00c78160_V4& b, const S00c78160_Simd& r)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline void setBroadcast(const S00c78160_V4& v, int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 85);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 170);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 255);
    }
    __forceinline void broadcast(int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 85);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 170);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
    }
    __forceinline S00c78160_Simd dot3(const S00c78160_V4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), xySum);
    }
    __forceinline S00c78160_Simd length3() const
    {
        return _mm_sqrt_ss(this->dot3(*this).getQuad());
    }
    __forceinline S00c78160_Simd lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline void setCross(const S00c78160_V4& v0, const S00c78160_V4& v1)
    {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 201),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 210));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 210),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 201));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void SetRotatedDirection(const S00c78160_Quat& quat, const S00c78160_V4& direction);

  private:
    __m128 m_vComponents;
};

struct S00c78160_Quat
{
    S00c78160_V4 m_vec;
    __forceinline const S00c78160_V4& getImag() const
    {
        return m_vec;
    }
};

__forceinline void S00c78160_V4::SetRotatedDirection(const S00c78160_Quat& quat, const S00c78160_V4& direction)
{
    S00c78160_V4 minusHalf;
    minusHalf.getQuad() = ::DAT_010c71e0;
    S00c78160_V4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    S00c78160_V4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    S00c78160_V4 ret;
    ret.setMul4(direction, q2minus1);
    S00c78160_V4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());
    S00c78160_V4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

struct S00c78160_Xf
{
    S00c78160_V4 m_vTranslation;
    S00c78160_Quat m_rotation;
    S00c78160_V4 m_vScale;
};

struct S00c78160_Pose
{
    int unk00, unk04, unk08, unk0c;
    S00c78160_Xf* m_pModelPose;
    int unk14, unk18;
    unsigned int* m_pBoneFlags;
    __forceinline const S00c78160_Xf& getBoneModelSpace(int boneIdx)
    {
        if (!(m_pBoneFlags[boneIdx] & 2))
            return m_pModelPose[boneIdx];
        return (*(const ::S00c78160_Xf *)&(reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(boneIdx)));
    }
};

struct S00c78160_This
{
    int unk00, unk04, unk08, unk0c;
    S00c78160_Xf m_kMotionTransform;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84;
    S00c78160_Pose* m_pose;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    short unkb0;
    bool m_b2;
    char unkb3;
    int unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    S00c78160_V4 m_target;
    int unke0, unke4, unke8, unkec;
    S00c78160_Pose* m_f0;
    int unkf4, unkf8, unkfc, unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    int unk130, unk134, unk138, unk13c, unk140;
    short m_bone;
    short unk146;
    int unk148, unk14c;
    S00c78160_V4 m_offset;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c;
    bool m_190;
    char unk191, unk192, unk193;
    int unk194, unk198, unk19c, unk1a0;
    bool m_1a4;
    void FUN_00c78160();
};

// @fnv 0x00c78160
void S00c78160_This::FUN_00c78160()
{
    S00c78160_V4 direction;
    reinterpret_cast<::InversePositionVector *>(&(direction))->FUN_00c7f840((const ::Vec4 *)&(m_kMotionTransform), (const ::Vec4 *)&(m_target));
    direction.normalize3();
    S00c78160_V4 up(0.0f, 1.0f, 0.0f, 0.0f);
    m_1a4 = up.dot3(direction) < 0.0f;
    S00c78160_V4 position;
    if (m_b2 || m_1a4)
    {
        if (m_b2)
        {
            S00c78160_V4 offset = m_offset;
            offset.SetRotatedDirection(m_pose->getBoneModelSpace(m_bone).m_rotation, offset);
            offset.SetRotatedDirection(m_kMotionTransform.m_rotation, offset);
            offset.mul4(3.0f);
            position.setZero4();
            if (m_190)
                position.add4((*(const ::S00c78160_V4 *)&(reinterpret_cast<::PoseState *>((m_f0))->FUN_00cda8e0(1))));
            reinterpret_cast<::TransformedPosDAD *>(&(position))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(m_pose->getBoneModelSpace(m_bone)), (const ::hkVector4DAD &)(position));
            reinterpret_cast<::TransformedPosDAD *>(&(position))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(m_kMotionTransform), (const ::hkVector4DAD &)(position));
            m_target.setAdd4(position, offset);
        }
        else
        {
            S00c78160_V4 local;
            reinterpret_cast<::InversePositionVector *>(&(local))->FUN_00c7f840((const ::Vec4 *)&(m_kMotionTransform), (const ::Vec4 *)&(m_target));
            float height = 5.0f;
            if (((float*)&local)[0] < 0.0f)
                height = -5.0f;
            position.setZero4();
            if (m_190)
            {
                const S00c78160_V4& head = (*(const ::S00c78160_V4 *)&(reinterpret_cast<::PoseState *>((m_f0))->FUN_00cda8e0(1)));
                position.add4(head);
            }
            reinterpret_cast<::TransformedPosDAD *>(&(position))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(m_pose->getBoneModelSpace(m_bone)), (const ::hkVector4DAD &)(position));
            ((float*)&position)[0] += height;
            reinterpret_cast<::TransformedPosDAD *>(&(position))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(m_kMotionTransform), (const ::hkVector4DAD &)(position));
            m_target = position;
        }
    }
    position.setZero4();
    if (m_190)
        position.add4((*(const ::S00c78160_V4 *)&(reinterpret_cast<::PoseState *>((m_f0))->FUN_00cda8e0(1))));
    reinterpret_cast<::TransformedPosDAD *>(&(position))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(m_pose->getBoneModelSpace(m_bone)), (const ::hkVector4DAD &)(position));
    reinterpret_cast<::TransformedPosDAD *>(&(position))->FUN_00c7f7a0((const ::hkQsTransformDAD &)(m_kMotionTransform), (const ::hkVector4DAD &)(position));
    S00c78160_V4 difference;
    difference.setSub4(m_target, position);
    float distance = difference.length3();
    difference.normalize3();
    if (distance > DAT_011b05a8)
        m_target.setAddMul4(position, difference, DAT_011b05a8);
}

namespace fnv_00c79a50 {

struct Vec3
{
    float x, y, z;
    __forceinline Vec3& operator*=(float scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }
};
struct Mat3
{
    Vec3 r0, r1, r2;
};
struct SceneTransform
{
    Mat3 rotation;
    Vec3 position;
    float scale;
};

__forceinline __m128 Dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    y = _mm_add_ss(y, p);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    return _mm_add_ss(z, y);
}
__forceinline __m128 Cross(const __m128& a, const __m128& b)
{
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(x, y);
}
__forceinline __m128 Rotate(const __m128& q, const __m128& p)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 cross = Cross(q, p);
    __m128 dot = Dot3(p, q);
    __m128 t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), ::DAT_010c71e0), p);
    __m128 d = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 c = _mm_mul_ps(cross, w);
    __m128 sum = _mm_add_ps(c, _mm_add_ps(t, d));
    return _mm_add_ps(sum, sum);
}

__forceinline __m128 RotateInverseRaw(const __m128& q, const __m128& t)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 cross = Cross(t, q);
    __m128 dot = Dot3(t, q);
    cross = _mm_mul_ps(cross, w);
    __m128 a = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), ::DAT_010c71e0), t);
    __m128 b = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 sum = _mm_add_ps(cross, _mm_add_ps(a, b));
    return _mm_add_ps(sum, sum);
}
struct SimdQuaternion;
class SimdVector
{
    __m128 quad;

  public:
    __forceinline operator __m128() const
    {
        return quad;
    }
    __forceinline __m128& Raw()
    {
        return quad;
    }
    __forceinline const __m128& Raw() const
    {
        return quad;
    }
    __forceinline void operator=(const SimdVector& v)
    {
        quad = v.quad;
    }
    __forceinline void operator=(const __m128& v)
    {
        quad = v;
    }
    __forceinline void Sum(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_add_ps(a.quad, b.quad);
    }
    __forceinline void Difference(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    __forceinline void Product(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_mul_ps(a.quad, b.quad);
    }
    __forceinline void AddProduct(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_add_ps(quad, _mm_mul_ps(a.quad, b.quad));
    }
    __forceinline void AccumulateProduct(const SimdVector& a, const SimdVector& b, const SimdVector& c)
    {
        quad = _mm_add_ps(a.quad, _mm_mul_ps(b.quad, c.quad));
    }
    __forceinline void Negate(const SimdVector& v)
    {
        quad = _mm_xor_ps(v.quad, ::DAT_010c44d0);
    }
    __forceinline void Conjugate(const SimdVector& v)
    {
        quad = v.quad;
        quad = _mm_xor_ps(quad, ::DAT_010c4c00);
    }
    __forceinline void ClearW(const SimdVector& v)
    {
        quad = _mm_and_ps(v, ::DAT_010c4c10);
    }
    __forceinline void Broadcast(const SimdVector& v, int i)
    {
        if (i == 0)
            quad = _mm_shuffle_ps(v.quad, v.quad, 0);
        else
            quad = _mm_shuffle_ps(v.quad, v.quad, 0xff);
    }
    __forceinline __m128 Dot(const SimdVector& v) const
    {
        __m128 product = _mm_mul_ps(quad, v.quad);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline void Cross(const SimdVector& a, const SimdVector& b)
    {
        quad = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xc9), _mm_shuffle_ps(b.quad, b.quad, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xd2), _mm_shuffle_ps(b.quad, b.quad, 0xc9)));
    }
    __forceinline void Reciprocal3(const SimdVector& v);
    __forceinline void Rotate(const SimdQuaternion&, const SimdVector&);
    __forceinline void RotateBack(const SimdQuaternion&, const SimdVector&);
};
__forceinline __m128 RefineReciprocal(__m128 input)
{
    __m128 estimate = _mm_rcp_ps(input);
    return _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, input), estimate));
}
__forceinline void SimdVector::Reciprocal3(const SimdVector& v)
{
    SimdVector xyz1;
    xyz1.quad = _mm_shuffle_ps(v.quad, _mm_unpackhi_ps(v.quad, ::DAT_010c7170), 0xc4);
    quad = RefineReciprocal(xyz1.quad);
}
struct SimdQuaternion
{
    SimdVector q;
    __forceinline const SimdVector& Imaginary() const
    {
        return q;
    }
    __forceinline void Inverse(const SimdQuaternion& other)
    {
        q.Conjugate(other.Imaginary());
    }
    void FUN_00c66320(const SimdQuaternion*, const SimdQuaternion*);
};
__forceinline void SimdVector::RotateBack(const SimdQuaternion& rotation, const SimdVector& direction)
{
    quad = RotateInverseRaw(rotation.q.Raw(), direction.Raw());
}
__forceinline void SimdVector::Rotate(const SimdQuaternion& rotation, const SimdVector& direction)
{
    SimdVector half;
    half = ::DAT_010c71e0;
    SimdVector w;
    w.Broadcast(rotation.q, 3);
    SimdVector factor;
    factor.AccumulateProduct(half, w, w);
    SimdVector result;
    result.Product(direction, factor);
    SimdVector dot;
    dot.Raw() = rotation.Imaginary().Dot(direction);
    dot.Broadcast(dot, 0);
    result.AddProduct(dot, rotation.Imaginary());
    SimdVector cross;
    cross.Cross(rotation.Imaginary(), direction);
    result.AddProduct(w, cross);
    Sum(result, result);
}
struct SimdTransform
{
    SimdVector position;
    SimdQuaternion rotation;
    SimdVector scale;
    __forceinline void SetInverse(const SimdTransform& p)
    {
        position.RotateBack(p.rotation, p.position);
        position.Negate(position);
        rotation.Inverse(p.rotation);
        SimdVector reciprocal;
        reciprocal.Reciprocal3(p.scale);
        scale.ClearW(reciprocal);
    }
    __forceinline void SetMul(const SimdTransform& a, const SimdTransform& b)
    {
        SimdVector extra;
        extra.Rotate(a.rotation, b.position);
        position.Sum(a.position, extra);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(rotation), (void *)(&a.rotation), (const __m128 *)(const ::fnv_00c79a50::SimdQuaternion *)(&b.rotation), {});
        scale.Product(a.scale, b.scale);
    }
    __forceinline void SetInverseMul(const SimdTransform& a, const SimdTransform& b)
    {
        SimdTransform inverse;
        inverse.SetInverse(a);
        SetMul(inverse, b);
    }
};
struct TransformArg
{
    const SimdTransform* p;
    TransformArg(const SimdTransform* v) : p(v)
    {}
};
__declspec(noalias) void __cdecl FUN_00c74d50(SceneTransform*, TransformArg);
struct DirtyObject
{
    int unk00, unk04, unk08, unk0c, unk10;
    bool dirty;
};
struct SceneOwner
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual DirtyObject* GetObject();
};
struct SceneChildLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    SceneOwner* owner;
    int unk20, unk24, unk28, unk2c, unk30;
    Mat3 m34;
    Vec3 m58;
};
struct Hierarchy
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};
struct TransformSet
{
    Hierarchy* hierarchy;
    SimdTransform* local;
    int unk08, unk0c;
    SimdTransform* world;
    int unk14, unk18;
    unsigned* flags;
    __forceinline SimdTransform& GetLocal(int i, int bytes);
    __forceinline SimdTransform* GetWorld(int index)
    {
        if (!(flags[index] & 2))
            return &world[index];
        return ((::fnv_00c79a50::SimdTransform *)&(reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(index)));
    }
};
struct SourceNode
{
    int unk00, unk04, unk08;
    Hierarchy* hierarchy;
};
struct ScaleOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94;
    float scale;
};
struct PoseControllerLocal
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    ScaleOwner* owner;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84;
    TransformSet* transforms;
    int unk8c, unk90, unk94, unk98, unk9c, unka0;
    SceneChildLocal** children;
    int unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    int unk2a0;
    SourceNode* source;
    void FUN_00c79a50();
};

// @fnv 0x00c79a50
void PoseControllerLocal::FUN_00c79a50()
{
    int count = source->hierarchy->count;
    reinterpret_cast<::hkaPoseCDA *>((transforms))->FUN_00cda690();
    float reciprocalScale = 1.0f / owner->scale;
    int i = 0;
    if (count > 0)
    {
        int bytes = 0;
        do
        {
            SceneChildLocal* child = children[i];
            SimdTransform& value = transforms->GetLocal(i, bytes);
            SceneTransform converted;
            FUN_00c74d50(&converted, TransformArg(&value));
            child->m58 = (converted.position *= reciprocalScale);
            child->m34 = converted.rotation;
            SceneOwner* owner = child->owner;
            if (owner)
            {
                DirtyObject* obj = owner->GetObject();
                if (obj)
                    obj->dirty = true;
            }
            bytes += sizeof(SimdTransform);
        } while (++i < count);
    }
}

__forceinline SimdTransform& TransformSet::GetLocal(int i, int bytes)
{
    if (flags[i] & 1)
    {
        short parent = hierarchy->parents[i];
        SimdTransform* world = this->world;
        if (parent != -1)
        {
            (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(local) + bytes))
                .SetInverseMul(*GetWorld(parent),
                               (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)));
        }
        else
        {
            SimdTransform& dest = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(local) + bytes));
            dest.position = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)).position;
            dest.rotation.q = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)).rotation.q;
            dest.scale = (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(world) + bytes)).scale;
        }
        flags[i] &= ~1u;
    }
    return (*reinterpret_cast<SimdTransform*>(reinterpret_cast<char*>(local) + bytes));
}

inline void SimdQuaternion::FUN_00c66320(const SimdQuaternion* a, const SimdQuaternion* b)
{
    SimdVector v;
    v.Cross(a->Imaginary(), b->Imaginary());
    SimdVector aw;
    aw.Broadcast(a->q, 3);
    v.AddProduct(aw, b->Imaginary());
    SimdVector bw;
    bw.Broadcast(b->q, 3);
    v.AddProduct(bw, a->Imaginary());
    SimdVector dot;
    dot.Raw() = a->q.Dot(b->q);
    dot.Broadcast(dot, 0);
    SimdVector product;
    product.Product(a->q, b->q);
    SimdVector result;
    result.Difference(product, dot);
    __m128 hi = _mm_unpackhi_ps(v.Raw(), result.Raw());
    q.Raw() = _mm_shuffle_ps(v.Raw(), hi, 0xc4);
}
}  // namespace fnv_00c79a50

struct P103Transform
{
    __m128 translation;
    __m128 rotation;
    __m128 scale;
    __forceinline P103Transform& operator=(const P103Transform& other)
    {
        translation = other.translation;
        rotation = other.rotation;
        scale = other.scale;
        return *this;
    }
};
struct P103Quaternion
{
    __m128 value;
    __declspec(noinline) void FUN_00c66320(const __m128* a, const __m128* b);
};
__declspec(noinline) __declspec(noalias) void P103Quaternion::FUN_00c66320(const __m128* a, const __m128* b)
{
    P103Quaternion left = *(const P103Quaternion*)a;
    P103Quaternion right = *(const P103Quaternion*)b;
    __m128 q = left.value, r = right.value;
    __m128 prod = _mm_mul_ps(q, r);
    __m128 sy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), sy);
    __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
    __m128 na = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    __m128 pa = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    __m128 xyz = _mm_sub_ps(pa, na);
    __m128 qw = _mm_shuffle_ps(q, q, 0xff);
    qw = _mm_shuffle_ps(qw, qw, 0);
    xyz = _mm_add_ps(_mm_mul_ps(qw, r), xyz);
    __m128 rw = _mm_shuffle_ps(r, r, 0xff);
    rw = _mm_shuffle_ps(rw, rw, 0);
    xyz = _mm_add_ps(_mm_mul_ps(rw, q), xyz);
    value = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, real), 0xc4);
}

struct P103Skeleton
{
    unsigned int unk00, unk04, unk08;
    short* parents;
    unsigned int unk10, unk14, unk18;
    int count;
};
struct P103Pose
{
    P103Skeleton* skeleton;
    P103Transform* local;
    unsigned int unk08, unk0c;
    P103Transform* model;
    unsigned int unk14, unk18;
    unsigned int* flags;
    unsigned int unk20, unk24;
    bool localSynced;
    bool modelSynced;
    __forceinline void storeModel(int selected, const P103Transform& target);
    __forceinline const P103Transform& localAt(int index);
    P103Transform* modelAt(int bone)
    {
        if (!(flags[bone] & 2))
            return model + bone;
        return ((::P103Transform *)&(reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(bone)));
    }
};
static __forceinline __m128 P103Rotate(const __m128& q, const __m128& v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 square = _mm_add_ps(_mm_mul_ps(w, w), ::DAT_010c71e0);
    __m128 base = _mm_mul_ps(v, square);
    __m128 product = _mm_mul_ps(q, v);
    __m128 sy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 sz = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sy);
    __m128 dot = _mm_shuffle_ps(sz, sz, 0);
    base = _mm_add_ps(_mm_mul_ps(dot, q), base);
    __m128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
    __m128 vc9 = _mm_shuffle_ps(v, v, 0xc9);
    __m128 a = _mm_mul_ps(vc9, qd2);
    __m128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
    __m128 vd2 = _mm_shuffle_ps(v, v, 0xd2);
    __m128 b = _mm_mul_ps(vd2, qc9);
    __m128 cross = _mm_sub_ps(b, a);
    base = _mm_add_ps(_mm_mul_ps(w, cross), base);
    return _mm_add_ps(base, base);
}
static __forceinline __m128 P103RotateInverse(const __m128& q, const __m128& v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 square = _mm_add_ps(_mm_mul_ps(w, w), ::DAT_010c71e0);
    __m128 base = _mm_mul_ps(v, square);
    __m128 product = _mm_mul_ps(q, v);
    __m128 sy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 sz = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sy);
    __m128 dot = _mm_shuffle_ps(sz, sz, 0);
    base = _mm_add_ps(_mm_mul_ps(dot, q), base);
    __m128 vd2 = _mm_shuffle_ps(v, v, 0xd2);
    __m128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
    __m128 a = _mm_mul_ps(qc9, vd2);
    __m128 vc9 = _mm_shuffle_ps(v, v, 0xc9);
    __m128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
    __m128 b = _mm_mul_ps(qd2, vc9);
    __m128 cross = _mm_sub_ps(b, a);
    base = _mm_add_ps(_mm_mul_ps(w, cross), base);
    return _mm_add_ps(base, base);
}
static __forceinline __m128 P103Dot3(const __m128& a, const __m128& b)
{
    __m128 product = _mm_mul_ps(a, b);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    return sum;
}
static __forceinline float P103Angle(const __m128& dot)
{
    float f;
    _mm_store_ss(&f, dot);
    return (float)(1.5707963705062866 - (float)acos((double)f));
}
static __forceinline void P103SetInverse(P103Transform& out, const P103Transform& t)
{
    out.translation = _mm_xor_ps(P103RotateInverse(t.rotation, t.translation), ::DAT_010c44d0);
    out.rotation = _mm_xor_ps(t.rotation, DAT_010c4c00);
    __m128 scale = t.scale;
    scale = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, DAT_010c7170), 0xc4);
    __m128 r = _mm_rcp_ps(scale);
    __m128 c = _mm_mul_ps(r, scale);
    c = _mm_mul_ps(c, r);
    r = _mm_add_ps(r, r);
    r = _mm_sub_ps(r, c);
    out.scale = _mm_and_ps(r, DAT_010c4c10);
}
static __forceinline void P103SetMul(P103Transform& out, const P103Transform& t1, const P103Transform& t2)
{
    __m128 temp = _mm_add_ps(P103Rotate(t1.rotation, t2.translation), t1.translation);
    out.translation = temp;
    ::fnv_00c66320::FUN_00c66320((__m128 *)(((P103Quaternion*)&out.rotation)), (void *)(&t1.rotation), (const __m128 *)(const __m128 *)(&t2.rotation), {});
    out.scale = _mm_mul_ps(t1.scale, t2.scale);
}
__forceinline const P103Transform& P103Pose::localAt(int index)
{
    if (flags[index] & 1)
    {
        P103Transform* source = model;
        short parent = skeleton->parents[index];
        if (parent != -1)
        {
            P103Transform* p = modelAt(parent);
            P103Transform& dest = local[index];
            P103Transform inverse;
            P103SetInverse(inverse, *p);
            P103SetMul(dest, inverse, source[index]);
        }
        else
            local[index] = source[index];
        flags[index] &= ~1u;
    }
    return local[index];
}
__forceinline void P103Pose::storeModel(int selected, const P103Transform& target)
{
    int count = skeleton->count;
    flags[selected] |= 4;
    for (int index = selected + 1; index < count; ++index)
    {
        short parent = skeleton->parents[index];
        if (parent != -1 && (flags[parent] & 4))
        {
            localAt(index);
            flags[index] |= 4;
            localSynced = false;
        }
    }
    for (int index = selected + 1; index < count; ++index)
    {
        unsigned int f = flags[index];
        if (f & 4)
            flags[index] = (f & ~4u) | 2;
    }
    model[selected] = target;
    flags[selected] = 1;
    modelSynced = false;
}
struct P103Controller
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
    P103Pose* referencePose;
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
    P103Pose* pose;
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
    unsigned int unk0d8;
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
    float pitchLimit;
    float yawLimit;
    unsigned int unk13c;
    unsigned int unk140;
    short bone;
    short unk146;
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
    bool unk180;
    bool changed;
    short unk182;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    bool enabled;
    unsigned char unk191;
    short unk192;
    int forceChanged;
    unsigned int unk198;
    float pitch;
    float yaw;
    void FUN_00c7aa60(P103Transform* transform);
};
// Stores the bone's transform in pose, combines it with the given transform, and sets pitch/yaw from referencePose, marking changed past the limits.
// @fnv 0x00c7aa60
void P103Controller::FUN_00c7aa60(P103Transform* transform)
{
    reinterpret_cast<::S00c78160_This *>(this)->FUN_00c78160();
    if (changed || !enabled)
    {
        forceChanged = 1;
        reinterpret_cast<::P064Controller *>(this)->FUN_00c78610(1, (const ::P064Point *)&(*transform));
    }
    P103Transform& target = *((::P103Transform *)&(reinterpret_cast<::hkaPoseCDA *>((pose))->FUN_00cdad80(bone, 1)));
    ::fnv_00c66320::FUN_00c66320((__m128 *)(((P103Quaternion*)&target.rotation)), (void *)(&target.rotation), (const __m128 *)(const __m128 *)((const __m128*)&unk0c0), {});
    pose->storeModel(bone, target);
    if (enabled)
    {
        P103Transform* boneTransform = pose->modelAt(bone);
        P103Transform combined;
        combined.translation =
            _mm_add_ps(P103Rotate(transform->rotation, boneTransform->translation), transform->translation);
        ::fnv_00c66320::FUN_00c66320((__m128 *)(((P103Quaternion*)&combined.rotation)), (void *)(&transform->rotation), (const __m128 *)(const __m128 *)(&boneTransform->rotation), {});
        combined.scale = _mm_mul_ps(transform->scale, boneTransform->scale);
        changed = reinterpret_cast<::P064Controller *>(this)->FUN_00c78610(0, (const ::P064Point *)&(combined)) || forceChanged != 0;
        __m128 right = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);
        __m128 axis = _mm_setr_ps(0.0f, 1.0f, 0.0f, 0.0f);
        __m128 negativeZ = _mm_setr_ps(0.0f, 0.0f, -1.0f, 0.0f);
        P103Transform* reference = referencePose->modelAt(1);
        __m128 forward = P103Rotate(reference->rotation, axis);
        float pitchValue = P103Angle(P103Dot3(forward, negativeZ));
        pitch = pitchValue;
        yaw = P103Angle(P103Dot3(forward, right));
        if (fabs(yaw) > yawLimit)
            changed = true;
        if (fabs(pitchValue) > pitchLimit)
            changed = true;
        ::fnv_00cda110::FUN_00cda110((::fnv_00cda110::S *)(referencePose));
    }
}

class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char* psz);
    __forceinline NiFixedString(const char* handle, int) : m_kHandle(handle)
    {}
    __forceinline ~NiFixedString()
    {
        const char* h = m_kHandle;
        if (h != DAT_0109b220)
        {
            _ReadWriteBarrier();
            InterlockedDecrement(&GetGlobalStringHeader(h)->m_lRefCount);
        }
    }
};

struct NiGlobalStringTable
{
    static char* __cdecl AddString(const char* psz);
};
// @fnv 0x00c6e0b0
void* FUN_00c6e0b0_Class::FUN_00c6e0b0()
{
    Scene148* result = 0;
    if (unk414 & 0x8000)
    {
        if (m_594)
        {
            Scene148* object = ((::Scene148 *)(reinterpret_cast<::PropertyOwner *>((m_594))->FUN_00c85c80((void *)(0))));
            if (object)
            {
                Group148* group = object->AsGroup();
                if (group && group->count > 0)
                {
                    Scene148* child = group->children[0];
                    if (child)
                    {
                        Group148* cast = child->FUN_00653290(&(*reinterpret_cast<int *>(&::g_011f4428)));
                        if (cast)
                        {
                            char* text = ::NiGlobalStringTable::AddString(DAT_010c43d8);
                            unsigned int count = cast->count;
                            unsigned int index = 0;
                            while (index < count && !result)
                            {
                                Scene148* entry = cast->children[index];
                                if (entry && entry->name == text)
                                    result = entry;
                                ++index;
                            }
                            if (text != DAT_0109b220)
                                InterlockedDecrement(&GetGlobalStringHeader(text)->m_lRefCount);
                        }
                    }
                }
            }
        }
        if (!result)
            unk414 &= ~0x8000u;
    }
    return result;
}

class NiNodeV;

class NiAVObjV : public NiRefObject
{
  public:
    virtual void v02();
    virtual NiNodeV* v03();

    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NiNodeV* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;

};

class NiNodeV : public NiAVObjV
{
  public:
    NiNodeV(unsigned short usChildren = 0);

    virtual void v_04();
    virtual void v_05();
    virtual void v_06();
    virtual void v_07();
    virtual void v_08();
    virtual void v_09();
    virtual void v_10();
    virtual void v_11();
    virtual void v_12();
    virtual void v_13();
    virtual void v_14();
    virtual void v_15();
    virtual void v_16();
    virtual void v_17();
    virtual void v_18();
    virtual void v_19();
    virtual void v_20();
    virtual void v_21();
    virtual void v_22();
    virtual void v_23();
    virtual void v_24();
    virtual void v_25();
    virtual void v_26();
    virtual void v_27();
    virtual void v_28();
    virtual void v_29();
    virtual void v_30();
    virtual void v_31();
    virtual void v_32();
    virtual void v_33();
    virtual void v_34();
    virtual void v_35();
    virtual void v_36();
    virtual void v_37();
    virtual void v_38();
    virtual void v_39();
    virtual void v_40();
    virtual void v_41();
    virtual void v_42();
    virtual void v_43();
    virtual void v_44();
    virtual void v_45();
    virtual void v_46();
    virtual void v_47();
    virtual void v_48();
    virtual void v_49();
    virtual void v_50();
    virtual void v_51();
    virtual void v_52();
    virtual void v_53();
    virtual void v_54();
    virtual void AttachChildInAvailableSlot(NiAVObjV* pkChild, bool abFirstAvailableSlot);
    virtual void v56();
    virtual void InsertChild(NiAVObjV* pkChild, NiPointer<NiAVObjV>& pChild);

    int unk9c;
    NiAVObjV** m_ppChildren;
    unsigned short unkA4;
    unsigned short m_usChildren;
    int unkA8;
};

struct bhkSubData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct bhkWorldSub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bhkSubData sub;
};

struct bhkWorldStub
{
    virtual void v_00();
    virtual void v_01();
    virtual void v_02();
    virtual void v_03();
    virtual void v_04();
    virtual void v_05();
    virtual void v_06();
    virtual void v_07();
    virtual void v_08();
    virtual void v_09();
    virtual void v_10();
    virtual void v_11();
    virtual void v_12();
    virtual void v_13();
    virtual void v_14();
    virtual void v_15();
    virtual void v_16();
    virtual void v_17();
    virtual void v_18();
    virtual void v_19();
    virtual void v_20();
    virtual void v_21();
    virtual void v_22();
    virtual void v_23();
    virtual void v_24();
    virtual void v_25();
    virtual void v_26();
    virtual void v_27();
    virtual void v_28();
    virtual void v_29();
    virtual void v_30();
    virtual void v_31();
    virtual void v_32();
    virtual void v_33();
    virtual void v_34();
    virtual void v_35();
    virtual void v_36();
    virtual void v_37();
    virtual void v_38();
    virtual void v_39();
    virtual void v_40();
    virtual void v_41();
    virtual void v_42();
    virtual void v_43();
    virtual void v_44();
    virtual void v_45();
    virtual void v_46();
    virtual void v_47();
    virtual void v_48();
    virtual void v_49();
    virtual void v_50();
    virtual NiAVObjV* vfunc_cc(NiNodeV* pNode);
    virtual void vfunc_d0();

    int unk04;
    bhkWorldSub* m_08;
};

struct bhkCollisionProxy : public bhkNiCollisionObjectStub
{
    bhkWorldStub* m_pkWorld;
    void FUN_00c6bd60(bool bEnable);
};

extern unsigned int DAT_0126fd98;

struct CollisionTlsGuard
{
    int saved;
    CollisionTlsGuard(unsigned int id)
    {
        saved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = id;
    }
    ~CollisionTlsGuard()
    {
        g_tlsBlock.memoryContext = saved;
    }
};

// If bEnable, creates a bhkColDisp node under the parent and sets flag 0x10; otherwise looks up bhkColDisp children of the parent and clears flag 0x10.
// @fnv 0x00c6bd60
void bhkCollisionProxy::FUN_00c6bd60(bool bEnable)
{
    CollisionTlsGuard guard(0x10);

    if (bEnable)
    {
        if (GetFlag(4))
        {
            return;
        }
        bhkWorldStub* world = m_pkWorld;
        if (world)
        {
            bhkSubData* updateData = world->m_08 ? &world->m_08->sub : 0;
            int val = updateData ? updateData->unk1C : 0;
            if ((val & 0x7F) == 0x11)
            {
                return;
            }

            NiAVObjV* pkObj = (NiAVObjV*)m_pPointer;
            NiNodeV* a = 0;
            if (!pkObj || !(a = pkObj->v03()))
            {
                a = pkObj->m_pParentNode;
            }

            NiNodeV* fScale = new NiNodeV(0);
            ::AssignFixedString((char *)(fScale), (intptr_t)&(const ::NiFixedString &)(NiFixedString("bhkColDisp")), {});

            if (a)
            {
                float s = a->m_kWorldSpaceTransform.m_fScale;
                fScale->m_kLocalTransform.m_fScale = fabsf(1.0f / s);
                a->AttachChildInAvailableSlot(fScale, true);
                NiUpdateData sub;
                reinterpret_cast<::FUN_00a59c60_cls *>((fScale))->FUN_00a59c60((std::intptr_t)&(sub));
            }

            NiPointer<NiAVObjV> pNode = world->vfunc_cc(fScale);
            if (pNode)
            {
                if (a)
                {
                    reinterpret_cast<::FUN_00a5a040_Class *>(((pNode).operator->()))->FUN_00a5a040();
                    NiUpdateData sub;
                    reinterpret_cast<::FUN_00a59c60_cls *>(((pNode).operator->()))->FUN_00a59c60((std::intptr_t)&(sub));
                }
            }
            else
            {
                if (a && fScale)
                {
                    NiPointer<NiAVObjV> spOld;
                    a->InsertChild(fScale, spOld);
                }
            }

            m_ucFlags |= 0x10;
        }
    }
    else
    {
        if (!GetFlag(4))
        {
            return;
        }

        NiAVObjV* pkObj = (NiAVObjV*)m_pPointer;
        NiNodeV* a = pkObj ? pkObj->v03() : 0;
        if (m_pkWorld)
        {
            m_pkWorld->vfunc_d0();
        }
        if (!a)
        {
            a = pkObj->m_pParentNode;
        }

        if (a)
        {
            unsigned int count = a->m_usChildren;
            unsigned int i = 0;
            for (; i < count; ++i)
            {
                NiAVObjV* b = a->m_ppChildren[i];
                NiAVObjV* pkColDisp =
                    b ? ((::NiAVObjV *)(reinterpret_cast<::fnv_00a59e20::NiAVObject *>((b))->FUN_00a59e20((intptr_t)&(const ::NiFixedString &)(NiFixedString(NiGlobalStringTable::AddString("bhkColDisp"), 0))))) : 0;
                if (pkColDisp)
                {
                    NiPointer<NiAVObjV> spOld;
                    a->InsertChild(pkColDisp, spOld);
                }
            }
        }

        m_ucFlags &= ~0x10;
    }
}

struct WorldProxy;
struct ContainerProxy
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    WorldProxy* world;
};
struct BodyProxy
{
    int unk00, unk04;
    ContainerProxy* unk08;
};
struct LinkProxy
{
    int unk00, unk04;
};
struct ConstraintProxy
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void attach(WorldProxy*);
    virtual void detach();
    void Detach()
    {
        if (this)
            detach();
    }
    void Attach(WorldProxy* w)
    {
        if (this)
            attach(w);
    }
};
struct WorldProxy
{
};
struct C70CharacterController
{
    int unk000;
    int unk004;
    LinkProxy* link;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    unsigned int flags;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    ConstraintProxy* constraint594;
    ConstraintProxy* constraint598;
    void FUN_00c70c90(WorldProxy*);
};
// Moves the character controller between worlds by detaching constraints from the old world and attaching them to the new one.
// @fnv 0x00c70c90
void C70CharacterController::FUN_00c70c90(WorldProxy* world)
{
    BodyProxy* body = link ? ((::BodyProxy *)(reinterpret_cast<::FUN_00cac980_class *>((link))->FUN_00cac980())) : 0;
    WorldProxy* current = body->unk08 ? body->unk08->world : 0;
    if (current != world)
    {
        if (current)
        {
            reinterpret_cast<::CAC680Object *>(this)->ToggleAndUpdate();
            constraint594->Detach();
            constraint598->Detach();
        }
        if (link)
            ((::LinkProxy *)(::FUN_00cac900((::SomeClass *)(link))))->unk04 = 0;
        if (world)
        {
            if (constraint594)
            {
                if (!(*(unsigned char*)&flags & 1) && !((unsigned char)(flags >> 20) & 1))
                {
                    reinterpret_cast<::FUN_00c708a0_cls *>(this)->FUN_00c708a0((float)(DAT_01267bcc * 0.009999999776482582));
                    reinterpret_cast<::C6E180Owner *>(this)->FUN_00c6e180((float)(DAT_01267bcc * 0.009999999776482582));
                    reinterpret_cast<::FUN_00c708a0_cls *>(this)->FUN_00c708a0(0.0f);
                }
                constraint594->attach(world);
                ConstraintProxy* c = constraint594;
                reinterpret_cast<::C68E30Owner *>((world))->FUN_00c68e30((::C68E30Holder *)(c), (int)::PackColorBigEndian(1.0f, 1.0f, 0.0f, 0.75f));
            }
            constraint598->Attach(world);
        }
    }
}

// Releases the two owned array buffers.

template <class T> inline void C71120ReleaseBuffer(hkMemoryAllocator& alloc, T* p, int numElem)
{
    alloc.bufFree(p, int(numElem * sizeof(T)));
}

template <class T> class C71120Array
{
  public:
    ~C71120Array()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            C71120ReleaseBuffer(alloc, m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <class T> class C71120ArrayBase
{
  public:
    ~C71120ArrayBase()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, int((m_iCapacityState & 0x3fffffff) * sizeof(T)));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class FUN_00c71120
{
  public:
    ~FUN_00c71120();
    int m_iID;
    C71120ArrayBase<int> m_kIndices;
    C71120Array<float> m_kWeights;
};

// Destructor for FUN_00c71120; the body is empty because the C71120ArrayBase and C71120Array members handle their own cleanup.
// @fnv 0x00c71120
FUN_00c71120::~FUN_00c71120()
{}

// Force emission of the destructor.
void C71120Destroy(void* pvObject)
{
    static_cast<FUN_00c71120*>(pvObject)->FUN_00c71120::~FUN_00c71120();
}

// Adapted from another contributor's unverified destructor hypothesis and
// adjusted to a single polymorphic primary base, then rechecked by luna1300_133.

struct Base_00c75fa0
{
    int m_04;
    void* m_08;
    virtual ~Base_00c75fa0()
    {
        reinterpret_cast<::S_00b601a0_Map *>((this))->FUN_00b601a0();
        ::FUN_00aa10f0(m_08);
    }
};

struct FUN_00c75fa0 : public Base_00c75fa0
{
    virtual ~FUN_00c75fa0();
};
// @fnv 0x00c7a5b0
void* FUN_00c75fa0_Class::FUN_00c7a5b0(unsigned int flags)
{
    reinterpret_cast<::FUN_00c75fa0 *>(this)->FUN_00c75fa0::~FUN_00c75fa0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

// Calls Reset on the object before the base class destructor runs.
// @fnv 0x00c75fa0
FUN_00c75fa0::~FUN_00c75fa0()
{
    reinterpret_cast<::S_00b601a0_Map *>((this))->FUN_00b601a0();
}

struct C6A540ActionList : FUN_00c68f50_cls
{
    void RemoveKey(FUN_00c663d0_Ref** pKey);
};

void C6A540ActionList::RemoveKey(FUN_00c663d0_Ref** pKey)
{
    if (!*pKey)
        return;
    if (!m_next && !m_key.m_pObject)
        return;
    FUN_00c68f50_cls* pPrev = this;
    FUN_00c68f50_cls* pNode = this;
    while (pNode->m_key.m_pObject != *pKey)
    {
        pPrev = pNode;
        pNode = pNode->m_next;
        if (!pNode)
            return;
    }
    if (pNode == this)
    {
        FUN_00c68f50_cls* pNext = m_next;
        if (pNext)
        {
            m_next = pNext->m_next;
            m_key = pNext->m_key;
            pNext->m_next = 0;
            reinterpret_cast<::Owner_b5063 *>((pNext))->LockOwnerAndRelease();
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(pNext);
        }
        else
        {
            FUN_00c663d0_Ref* pObject = m_key.m_pObject;
            if (pObject && InterlockedDecrement(&pObject->m_uiRefCount) == 0)
                pObject->v1();
            m_key.m_pObject = 0;
        }
    }
    else
    {
        pPrev->m_next = pNode->m_next;
        pNode->m_next = 0;
        reinterpret_cast<::Owner_b5063 *>((pNode))->LockOwnerAndRelease();
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(pNode);
    }
}

struct Item_c6a540
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual int v37();
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
    virtual void v49(float afValue);
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

struct Shell_c6a540
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    int uTmpnk;
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
    C6A540ActionList m_kList;
    void FUN_00c6a540(float afValue);
};

// Iterates m_kList; items whose v37() returns false are removed from the list, others get v49(afValue).
// @fnv 0x00c6a540
void Shell_c6a540::FUN_00c6a540(float afValue)
{
    FUN_00c68f50_cls* pIter = &m_kList;
    while (pIter && (pIter->m_next || pIter->m_key.m_pObject))
    {
        Item_c6a540* pItem = (Item_c6a540*)pIter->m_key.m_pObject;
        FUN_00c68f50_cls* pNext = pIter->m_next;
        if (pItem)
        {
            if (!pItem->v37())
            {
                if (pIter == &m_kList)
                    pNext = pIter;
                NiPointer<Item_c6a540> spItem = pItem;
                reinterpret_cast<::FUN_00c68f50_cls *>(&(m_kList))->RemoveKey((FUN_00c663d0_Ref**)&spItem);
            }
            else
                pItem->v49(afValue);
        }
        pIter = pNext;
    }
}

struct ReleaseObject
{
};
struct FUN_00cbf430
{
    ~FUN_00cbf430();
};
int __cdecl ShutdownIfInitialized();
void __cdecl NotifyThreadObserverEnabled();
void __cdecl RunCallbackIfPresent();


// Releases game and base-system users before the actual native memory-system owner.
// @fnv 0x00c66670
void __cdecl FUN_00c66670()
{
    ThreadMemoryScope scope;
    NotifyThreadObserverEnabled();
    RunCallbackIfPresent();
    ::FUN_00c6d3c0();
    if ((*reinterpret_cast<::WorldEntry * *>(&::g_pkWorldListenerC68)))
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((((ReleaseObject*)(*reinterpret_cast<::WorldEntry * *>(&::g_pkWorldListenerC68)))))->FUN_00c905b0();
        (*reinterpret_cast<::WorldEntry * *>(&::g_pkWorldListenerC68)) = 0;
    }
    if ((*reinterpret_cast<::FUN_00cbf430 * *>(&::DAT_012677d0)))
        delete (*reinterpret_cast<::FUN_00cbf430 * *>(&::DAT_012677d0));
    ShutdownIfInitialized();
    if (!g_havokPhysicsMemory.Shutdown())
        std::terminate();
    ::FUN_00cbbfb0(0);
}

struct Vec4
{
    __m128 q;
};
struct Mat44
{
    Vec4 r0, r1, r2, r3;
};
struct Mat9
{
    float f[9];
};
struct Pt3
{
    float x;
    float y;
    float z;
};
extern char DAT_012677a1;
struct RTTIObj
{
    int m_00;
};
struct RetC
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
void* __cdecl FUN_00c74ea0(int size);
struct NodeBase
{
    virtual void Slot00();
    virtual void Release04();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual int Get40();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual bool GetB4();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void GetD4(void* out);
    virtual void GetD8(void* out);
    virtual void CallDC(const void* p);
    virtual void CallE0(const void* p);
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
struct C69960Node : NodeBase
{
    Vec4 m_20;
    Vec4 m_30;
    C69960Node(C69960Node* a);
    static void* operator new(std::size_t size);
    static void operator delete(void* p);
};
struct ResObj
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual ResObj* Get38();
    int m_04;
    int m_08;
    int m_0c;
    C69960Node* m_10;
    virtual void Extra3c();
    virtual void Extra40();
    virtual void Extra44();
    virtual void Extra48();
    virtual void Extra4c();
    virtual void Extra50();
    virtual void Extra54();
    virtual void Extra58();
    virtual void Extra5c();
    virtual void Extra60();
    virtual void Extra64();
    virtual void Extra68();
    virtual void Extra6c();
    virtual void Extra70();
    virtual void Extra74();
    virtual void Extra78();
    virtual void Extra7c();
    virtual void Extra80();
    virtual void Extra84();
    virtual void Extra88();
    virtual void Extra8c();
    virtual void Extra90();
    virtual void Extra94();
    virtual void Extra98();
    virtual void Extra9c();
    virtual void Extraa0();
    virtual void Extraa4();
    virtual void Extraa8();
    virtual void Extraac();
    virtual void Extrab0();
    virtual bool GetB4();
};
struct C69960Arg
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    ResObj* m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    Mat9 m_34;
    Pt3 m_58;
};
struct LocalRef
{
    void* m_ptr;
    LocalRef(int a);
    ~LocalRef();
};
struct Obj60
{
    Vec4 m_00;
};
struct Obj74
{
    Vec4 m_00;
};
struct ObjAC
{
    Vec4 m_00;
    void FUN_00c7f640(void* a, void* b);
};
struct Ctx
{
    void* m_00;
    char m_04;
    char m_05;
    char m_06;
    char m_07;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
};
__forceinline unsigned int IsEnabled(C69960Arg* obj)
{
    RetC* result = ((::RetC *)(::GetExtraDataChecked((::NiAVObjectX *)(obj))));
    return result ? (result->m_0c & 2) : 0;
}

struct MemScope
{
    int saved;
    __forceinline MemScope()
    {
        saved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 0x10;
    }
    __forceinline ~MemScope()
    {
        g_tlsBlock.memoryContext = saved;
    }
};

__forceinline void Rotate(__m128& out, const __m128& q, const __m128& v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    __m128 crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    __m128 cross = _mm_sub_ps(crossB, crossA);
    __m128 product = _mm_mul_ps(v, q);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    cross = _mm_mul_ps(cross, w);
    __m128 square = _mm_mul_ps(w, w);
    square = _mm_add_ps(square, ::DAT_010c71e0);
    square = _mm_mul_ps(square, v);
    __m128 projection = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 total = _mm_add_ps(cross, _mm_add_ps(square, projection));
    out = _mm_add_ps(total, total);
}
__forceinline void RotateInverse(__m128& out, const __m128& qp, const __m128& vp)
{
    __m128 q = qp;
    __m128 v = vp;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
    __m128 crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
    __m128 cross = _mm_sub_ps(crossA, crossB);
    __m128 product = _mm_mul_ps(qp, v);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    cross = _mm_mul_ps(cross, w);
    __m128 square = _mm_mul_ps(w, w);
    square = _mm_add_ps(square, ::DAT_010c71e0);
    square = _mm_mul_ps(square, v);
    __m128 projection = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    __m128 total = _mm_add_ps(cross, _mm_add_ps(square, projection));
    out = _mm_add_ps(total, total);
}

struct Host
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    char m_14;
    char m_15;
    char m_16;
    char m_17;
    int m_18;
    bool FUN_00c69960(C69960Arg* arg1, C69960Arg* arg2);
};
// @fnv 0x00c69960
bool Host::FUN_00c69960(C69960Arg* apSource, C69960Arg* apTarget)
{
    Mat44 matTransform;
    ObjAC objAC;
    Vec4 bufB;
    Vec4 bufA;
    Obj74 obj74;
    Obj60 obj60;
    Vec4 vTemp;
    Ctx ctx;
    MemScope memory;
    bool flagA = false;
    int state2 = 0;
    ResObj* result1 = 0;
    if (apSource && apTarget && IsEnabled(apTarget))
    {
        {
            ResObj* p1 = apSource->m_1c;
            state2 = 0;
            if (p1)
            {
                result1 = p1->Get38();
                if (result1)
                {
                    C69960Node* node = result1->m_10;
                    state2 = 1;
                    if (node && !result1->GetB4())
                    {
                        m_14 = 1;
                        flagA = 1;
                        if (apTarget != apSource)
                        {
                            C69960Node* work = 0;
                            if (::FUN_0043b300((const ::NiRTTI *)(const ::RTTIObj *)(&(*reinterpret_cast<::RTTIObj *>(&::g_012683c8))), (::NiAVObject *)(node)))
                            {
                                work = node;
                                goto main_block;
                            }
                            {
                                LocalRef smart(node->Get40());
                                C69960Node* work2 = (C69960Node*)smart.m_ptr;
                                if (work2)
                                {
                                    reinterpret_cast<::FUN_00c6b980_cls *>((result1))->FUN_00c6b980((::World_c6b *)(::C69960Node *)(0));
                                    work = new C69960Node(work2);
                                    work2->GetD4(&bufA);
                                    work2->GetD8(&bufB);
                                    work->m_30.q = bufA.q;
                                    work->m_20.q = bufB.q;
                                    work->CallDC(&DAT_01267e30);
                                    work->CallE0(&DAT_012683b0);
                                    reinterpret_cast<::FUN_00c6b980_cls *>((result1))->FUN_00c6b980((::World_c6b *)(work));
                                    if (InterlockedDecrement((long*)&work2->m_04) == 0)
                                        work2->Release04();
                                    smart.m_ptr = 0;
                                }
                            }
                        main_block:
                            if (work)
                            {
                                ::FromHK((*(::hkTransform *)(&matTransform)), (*(const ::NiTransform *)(&apSource->m_34)));
                                Rotate(vTemp.q, work->m_20.q, work->m_30.q);
                                objAC.FUN_00c7f640(&matTransform, &vTemp);
                                reinterpret_cast<::FUN_00827200_class *>(&(obj60))->FUN_00cb26e0((intptr_t)(&matTransform));
                                ::fnv_00c66320::FUN_00c66320((__m128 *)&(obj74), &work->m_20, (const __m128 *)(void *)(&obj60), {});
                                RotateInverse(vTemp.q, work->m_20.q, objAC.m_00.q);
                                work->m_30.q = vTemp.q;
                                work->m_20.q = obj74.m_00.q;
                                reinterpret_cast<::Owner62B *>((((ResObj*)apTarget)))->AttachTarget(result1);
                                reinterpret_cast<::Owner62B *>((apSource))->AttachTarget(0);
                                apSource->m_30 = (apSource->m_30 & ~0x10) | 6;
                            }
                            else
                            {
                                reinterpret_cast<::Owner62B *>((((ResObj*)apTarget)))->AttachTarget(result1);
                                reinterpret_cast<::Owner62B *>((apSource))->AttachTarget(0);
                                apSource->m_34 = (*reinterpret_cast<::Mat9 *>(&::DAT_011a9448));
                                apSource->m_58 = *(const Pt3*)&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
                                apSource->m_30 = (apSource->m_30 & ~0x10) | 6;
                            }
                        }
                    }
                }
            }
        }
        {
            ctx.m_00 = this;
            ctx.m_04 = 1;
            if (DAT_012677a1)
            {
                ctx.m_08 = 0xa;
                ::sc68e90::FUN_00c68e90(apTarget, (::sc68e90::Event *)(void *)(&ctx));
            }
            ctx.m_08 = 0;
            ctx.m_0c = state2;
            ctx.m_10 = 0;
            ctx.m_14 = 0;
            ctx.m_18 = 1;
            S_00c68900_Callback cb = *reinterpret_cast<S_00c68900_Callback*>(&::DAT_011afe88);
            if (cb)
                ::FUN_00c68900((::S_00c68900_Node *)(apTarget), (::S_00c68900_Context *)(void *)(&ctx), cb);
        }
    }
    return flagA;
}

struct Stub65800 : BC6C330HavokCollision
{
    void FUN_00c65800(BC6C330Stream& kStream);
};

// @fnv 0x00c65800
void Stub65800::FUN_00c65800(BC6C330Stream& kStream)
{
    reinterpret_cast<::BC6C330HavokCollision *>(this)->FUN_00c6c330(kStream);
}

#include "generated/data/staging/blk_00c60000_o2.inc"
