
// SSE_DECLARATIONS_DEFER_TO_SDK
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c90000.h"
#include <xmmintrin.h>
#include <cstdint>
#include <cstddef>
#include "generated/data/vtables.h"
#include <windows.h>
// src/staging/blk_00ca0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/BC87850RefObject.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C68E30Owner.h"
#include "fnv/decl/C9F270Object.h"
#include "fnv/decl/C_00c6cde0.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/Dispatch_00c89dd0.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0042fc00_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_009ba5f0_shell.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00a6d220.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00c84d00_cls.h"
#include "fnv/decl/FUN_00c84d50_cls.h"
#include "fnv/decl/FUN_00c84dc0_cls.h"
#include "fnv/decl/FUN_00c84df0_cls.h"
#include "fnv/decl/FUN_00c867d0_cls.h"
#include "fnv/decl/FUN_00c86800_Class.h"
#include "fnv/decl/FUN_00c868b0_cls.h"
#include "fnv/decl/FUN_00c87600_Obj.h"
#include "fnv/decl/FUN_00c87650_t.h"
#include "fnv/decl/FUN_00c87670_Class.h"
#include "fnv/decl/FUN_00c878c0_cls.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/FUN_00c899d0_Class.h"
#include "fnv/decl/FUN_00c89c80_obj.h"
#include "fnv/decl/FUN_00c89cf0_cls.h"
#include "fnv/decl/FUN_00ca5360_cls.h"
#include "fnv/decl/FUN_00ca8860_cls.h"
#include "fnv/decl/FUN_00ca9240.h"
#include "fnv/decl/FUN_00ca9270.h"
#include "fnv/decl/FUN_00ca9360_cls.h"
#include "fnv/decl/FUN_00ca9b40_class.h"
#include "fnv/decl/FUN_00cb9ce0_cls.h"
#include "fnv/decl/FUN_00cbc810_cls.h"
#include "fnv/decl/FUN_00cfb1e0.h"
#include "fnv/decl/FUN_00d1dfa0.h"
#include "fnv/decl/FUN_00d1e160_t.h"
#include "fnv/decl/FUN_00d1fa20_t.h"
#include "fnv/decl/FUN_00d21930.h"
#include "fnv/decl/FUN_00d21ce0_cls.h"
#include "fnv/decl/FUN_00d26450_Obj.h"
#include "fnv/decl/FUN_00d53200_class.h"
#include "fnv/decl/HavokFilterInfo.h"
#include "fnv/decl/LegacyCollisionLoader.h"
#include "fnv/decl/LegacyLinker.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiExtraData.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/NiObject_00a7b3d0.h"
#include "fnv/decl/NiTimeControllerCM.h"
#include "fnv/decl/Owner89730.h"
#include "fnv/decl/ProjectileListener.h"
#include "fnv/decl/S004b4db0_Quaternion.h"
#include "fnv/decl/S00d1e690_cls.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/decl/S_00c8a280_Obj.h"
#include "fnv/decl/S_00cac150.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/ViewerConstraint.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/WorldWithPending.h"
#include "fnv/decl/Wrapper86b80.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c86790__Holder.h"
#include "fnv/decl/fnv_00cd2fd0__Object.h"
#include "fnv/decl/fnv_00cdf7a0__FUN_00cdf7a0Class.h"
#include "fnv/decl/fnv_00d055c0__S_00d055c0_Obj.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpCharacterProxy.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a75000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a81000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa4000.h"
#include "fnv/symbols_00b4d000.h"
#include "fnv/symbols_00c65000.h"
#include "fnv/symbols_00c81000.h"
#include "fnv/symbols_00c84000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c98000.h"
#include "fnv/symbols_00ca1000.h"
#include "fnv/symbols_00ca6000.h"
#include "fnv/symbols_00cab000.h"
#include "fnv/symbols_00cac000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00cb9000.h"
#include "fnv/symbols_00cba000.h"
#include "fnv/symbols_00cbd000.h"
#include "fnv/symbols_00cc9000.h"
#include "fnv/symbols_00cf4000.h"
#include "fnv/symbols_00d1f000.h"
#include "fnv/symbols_00d2c000.h"
#include "fnv/symbols_00d2d000.h"
#include "fnv/symbols_00d2e000.h"
#include "fnv/symbols_00d2f000.h"
#include "fnv/symbols_00d31000.h"
#include "fnv/symbols_00d32000.h"
#include "fnv/symbols_00d33000.h"
#include "fnv/symbols_00d34000.h"
#include "fnv/symbols_00d36000.h"
#include "fnv/symbols_00d37000.h"
#include "fnv/symbols_00d38000.h"
#include "fnv/symbols_00d39000.h"
#include "fnv/symbols_00d3a000.h"
#include "fnv/symbols_00d3c000.h"
#include "fnv/symbols_00d3d000.h"
#include "fnv/symbols_00d3e000.h"
#include "fnv/symbols_00d3f000.h"
#include "fnv/symbols_00d40000.h"
#include "fnv/symbols_00d41000.h"
#include "fnv/symbols_00fff000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0108f000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_010c8000.h"
#include "fnv/symbols_010c9000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011b2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/decl/CbfOwner.h"
#include "../../include/layout_support.h"

// The byte before an aligned block holds the distance back to the start of its allocation.
struct AlignedBlockPrefix
{
    unsigned char m_ucOffset;
};
// An hkStringPtr value with the low bit set owns its (aligned) string copy.
inline uintptr_t TagOwnedString(const void* apString)
{
    return reinterpret_cast<uintptr_t>(apString) | 1;
}
inline AlignedBlockPrefix* GetAlignedBlockPrefix(void* apBlock)
{
    return static_cast<AlignedBlockPrefix*>(apBlock) - 1;
}

// The NiStream fields that code reads through an untyped stream pointer.
struct NiStreamFields
{
    char pad[0x1e4];
    unsigned char m_ucSourceByteOrder;
    char pad1e5[0x250 - 0x1e5];
    void* m_pkStream;
};

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

struct VelocityNode;
struct VelocityController
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
    VelocityNode* node;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    __m128 velocity;
    float amount;
    void FUN_00cb9290();
};


void __cdecl _delete(void* p, int);

struct FUN_00ca3980_class
{
    FUN_00ca3980_class* FUN_00ca3980(int);
};

extern "C" void NiFreeAlias(void*);
extern int DAT_010c759c;

struct FUN_00ca4470_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void FUN_00ca4470();
};

// @fnv 0x00ca4470
void FUN_00ca4470_Class::FUN_00ca4470()
{
    void* p = m_iWordAt04;
    m_iWordAt00 = &DAT_010c759c;
    NiFreeAlias(p);
}

struct FUN_00ca5310_class
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    struct FUN_00ca5310_inner* m_p;
};

struct FUN_00ca5310_inner
{
    char pad[0x90];
    float m_f90;
};

// Returns m_p->m_f90 when a and m_p are non-null, otherwise 1.0f.
// @fnv 0x00ca5310
float GetField24Float(struct FUN_00ca5310_class* pClass)
{
    float result;
    if (pClass && pClass->m_p)
        result = pClass->m_p->m_f90;
    else
        result = 1.0f;
    return result;
}

struct FUN_00ca6590_t
{
    int FUN_00ca6590();
    FUN_00ca6590_t* FUN_00ca6650(int flags);
};
void __cdecl _delete(void* p, unsigned int size);

// Calls FUN_00ca6590, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00ca6650
FUN_00ca6590_t* FUN_00ca6590_t::FUN_00ca6650(int flags)
{
    FUN_00ca6590();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_00ca9840_Target
{
    char pad[0x1c];
    float m_fValue;
};

struct FUN_00ca9840_Class
{
    int m_iWordAt00;
    FUN_00ca9840_Target* m_pTarget;
    void SetFieldValue(float v);
};

// @fnv 0x00ca9840
void FUN_00ca9840_Class::SetFieldValue(float afValue)
{
    if (m_pTarget)
        m_pTarget->m_fValue = afValue;
}


struct FUN_00ca9a80
{
    void* a;
    int b, c, d, e;
    FUN_00ca9a80();
};

// @fnv 0x00ca9a80
FUN_00ca9a80::FUN_00ca9a80()
{
    b = 0;
    c = 1;
    d = 0;
    e = 0;
    a = &DAT_010c8288;
}


struct FUN_00cb0a80_class
{
    uintptr_t m_stringAndFlag;
    int FUN_00cb0a80();
};

// @fnv 0x00cb0a80
int FUN_00cb0a80_class::FUN_00cb0a80()
{
    uintptr_t v = m_stringAndFlag;
    v &= ~(uintptr_t)1;
    if (v)
        return ::fnv_00cb10d0::FUN_00cb10d0((const char *)(v));
    return 0;
}

// @fnv 0x00cb0f10
char ToUpperAscii(char acChar)
{
    char r = acChar;
    if (acChar >= 'a' && acChar <= 'z')
        r = acChar - 0x20;
    return r;
}

// @fnv 0x00cb0f30
char ToLowerAscii(char acChar)
{
    if (acChar >= 'A' && acChar <= 'Z')
        acChar += ' ';
    return acChar;
}

void __cdecl FUN_00cc9640();

struct FUN_00cb9b60_class
{
    FUN_00cb9b60_class* DestroyIfFlagged(int flag);
};

// Calls FUN_00cc9640, deletes this with size 0x10 when flag has bit 0 set, and returns this.
// @fnv 0x00cb9b60
FUN_00cb9b60_class* FUN_00cb9b60_class::DestroyIfFlagged(int aiFlags)
{
    FUN_00cc9640();
    if (aiFlags & 1)
        operator delete(this, 0x10);
    return this;
}

namespace fnv_00cbc720 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
extern void* NiFreeAlias(void*);

struct NiTMapBase
{
    void* m_data;
    int m_auiShapeKeys;
    void* m_alloc;
    void RemoveAll();
    void FUN_00cbc720();
};

// @fnv 0x00cbc720
void NiTMapBase::FUN_00cbc720()
{
    m_data = &DAT_010c91a8;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    NiFreeAlias(m_alloc);
}
}  // namespace fnv_00cbc720

struct FUN_00cbc8f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    const unsigned char* m_pucData;
    int m_iCount;
    void FUN_00cbc8f0(int arg);
};

// Scans m_pucData backwards from m_iCount-1 and stops at the last index whose byte equals arg.
// @fnv 0x00cbc8f0
void FUN_00cbc8f0_cls::FUN_00cbc8f0(int aiValue)
{
    int count = m_iCount - 1;
    if (count >= 0)
    {
        const unsigned char* data = m_pucData;
        int val;
        do
        {
            val = data[count];
            if (val == aiValue)
                break;
            --count;
        } while (count >= 0);
    }
}

struct GlobalObject_0045cfe0
{
    GlobalObject_0045cfe0(const char* name, int flags);
    void* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
};

struct FUN_00cbf400_class : GlobalObject_0045cfe0
{
    FUN_00cbf400_class();
};

// Constructs the "iNumThreads:HAVOK" setting object with flags 1 and zeroes its four trailing fields.
// @fnv 0x00cbf400
FUN_00cbf400_class::FUN_00cbf400_class() : GlobalObject_0045cfe0("iNumThreads:HAVOK", 1)
{
    m_iThirdValue = 0;
    m_iFourthElementInteger = 0;
    m_usTrailingValue = 0;
    m_f = 0;
}

struct FUN_00ca0d40_vtable
{
    void* slot0;
    void* slot1;
    void (*Free)(void*);
};
struct FUN_00ca0d40_class
{
    void* m_vtbl;
    void* m_pData;
    unsigned int m_08;
    unsigned int m_0c;
    void FUN_00ca0d40();
};
// Sets the vtable pointer to DAT_010c7310 and, if m_pData is set, frees it through slot 2 of that vtable and clears m_pData, m_08 and m_0c.
// @fnv 0x00ca0d40
void FUN_00ca0d40_class::FUN_00ca0d40()
{
    void* p = m_pData;
    m_vtbl = &DAT_010c7310;
    if (p)
    {
        reinterpret_cast<FUN_00ca0d40_vtable*>(&DAT_010c7310)->Free(p);
        m_pData = 0;
        m_0c = 0;
        m_08 = 0;
    }
}

void __cdecl FUN_00ca4490();
struct MemoryManager
{
    void Deallocate(void* p);
public:
    void *Reallocate(void *, unsigned int);
};
struct FUN_00ca4a90_Class
{
    FUN_00ca4a90_Class* FUN_00ca4a90(int flags);
};
// Calls FUN_00ca4490, then if flags bit 0 is set and this is non-null, deallocates the block preceding this via _g_memoryManager, and returns this.
// @fnv 0x00ca4a90
FUN_00ca4a90_Class* FUN_00ca4a90_Class::FUN_00ca4a90(int flags)
{
    FUN_00ca4490();
    if ((flags & 1) && this)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060((char*)this - GetAlignedBlockPrefix(this)->m_ucOffset);
    return this;
}

struct bhkRefObject
{
};
struct bhkCapsuleShape : public bhkRefObject
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    void* InitializeCapsuleShape();
};
extern int DAT_01066e2c;

// @fnv 0x00caad90
void* bhkCapsuleShape::InitializeCapsuleShape()
{
    reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
    d = 0;
    e = 0;
    *reinterpret_cast<int**>(this) = &DAT_01030bf4;
    ++DAT_012680f8;
    *reinterpret_cast<int**>(this) = &DAT_01030b0c;
    ++DAT_01268274;
    *reinterpret_cast<int**>(this) = &DAT_01030a24;
    ++DAT_01268250;
    *reinterpret_cast<int**>(this) = &DAT_01066e2c;
    ++DAT_01268324;
    return this;
}

namespace fnv_00cbc550 {
extern int DAT_0108f1bc;
extern int _NiPoint3_ZERO;

struct bhkRefObject
{
    void* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    char m_3c;
};

struct FUN_00cbc550_cls : public bhkRefObject
{
    FUN_00cbc550_cls* FUN_00cbc550();
};

// @fnv 0x00cbc550
FUN_00cbc550_cls* FUN_00cbc550_cls::FUN_00cbc550()
{
    reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
    m_vtbl = &::DAT_0102016c;
    m_iThirdValue = 0;
    ++::DAT_01268154;
    m_vtbl = &::DAT_0102009c;
    ++::DAT_01268118;
    m_f14 = 0.0f;
    m_f18 = 0.0f;
    m_10 = 0;
    m_f1c = 0.0f;
    m_vtbl = &DAT_0108f1bc;
    m_f20 = 0.0f;
    m_24 = _NiPoint3_ZERO;
    m_28 = ::_DAT_011f4270;
    m_2c = ::_DAT_011f4274;
    m_30 = _NiPoint3_ZERO;
    m_34 = ::_DAT_011f4270;
    m_38 = ::_DAT_011f4274;
    m_3c = 1;
    ++::DAT_0126841c;
    return this;
}
}  // namespace fnv_00cbc550

namespace fnv_00cbc8b0 {
struct MemoryManager
{
    void Deallocate(void*);
};
extern void NiFree(void*);
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00cbc8b0 : NiTMapBaseStub
{
    void* m_vtbl;
    void* m_field;
    void* m_p;
    FUN_00cbc8b0* FUN_00cbc8b1(int flags);
};
// Sets the vtable, calls RemoveAll, frees m_p, and if flags has bit 0 set deallocates this via g_memoryManager; returns this.
// @fnv 0x00cbc8b0
FUN_00cbc8b0* FUN_00cbc8b0::FUN_00cbc8b1(int flags)
{
    m_vtbl = &::fnv_00cbc720::DAT_010c91a8;
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
    NiFree(m_p);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00cbc8b0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00cbc8b0

void __cdecl RegisterScriptHandlers(void*);

// @fnv 0x00cbfcb0
void __cdecl FUN_00cbfcb0(void* pObject)
{
    ::RegisterStaticCollisionAgent((::D41FD0CollisionDispatcher *)(pObject));
    ::FUN_00d41f00((::SpawnedObject *)(pObject), 0x12, 0x12);
    RegisterScriptHandlers(pObject);
    ::FUN_00d40910((::BoxAgentRegistry *)(pObject));
    ::FUN_00d40130((::hkpCollisionDispatcherD40 *)(pObject));
    ::FUN_00d3fd00((::Agent *)(pObject));
    ::FUN_00d3ef70((::S_00d3ef70_Dispatcher *)(pObject));
    ::FUN_00d3dca0((::S_00d3dca0_Obj *)(pObject));
    ::FUN_00d3cef0((::Registry *)(pObject));
    ::RegisterHandlers((::Registry *)(pObject));
    ::FUN_00d3abc0((::S_00d389f0_Dispatcher *)(pObject));
    ::FUN_00d39840((::hkpCollisionDispatcherD398 *)(pObject));
    ::FUN_00d389f0((::S_00d389f0_Dispatcher *)(pObject));
    ::FUN_00d377d0((intptr_t)(pObject));
    ::FUN_00d2e760((::Registry *)(pObject));
}

struct FUN_00cbbfa0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cbbfa0_class();
};

// @fnv 0x00cbbfa0
FUN_00cbbfa0_class::FUN_00cbbfa0_class()
{
    m_iWordAt00 = 0x32000;
    m_iWordAt04 = 0x600000;
}

struct FUN_00ca5540_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_uiValue;
};

struct FUN_00ca5540_Table
{
    char pad[0x10];
    unsigned short m_usCount;
    char pad12[0x12];
    FUN_00ca5540_Entry* m_pEntries;
};

struct FUN_00ca5540_Owner
{
    char pad[0x84];
    FUN_00ca5540_Table* m_pTable;
};

struct FUN_00ca5540_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00ca5540_Owner* m_p;
    int unk0c;
    unsigned int m_uiDefault;
    int GetEntryValue(int i);
};

// @fnv 0x00ca5540
int FUN_00ca5540_Class::GetEntryValue(int i)
{
    FUN_00ca5540_Owner* p = this ? m_p : 0;
    unsigned int uiIndex = (unsigned int)i >> 24;
    if (i != -1 && (int)uiIndex < (int)p->m_pTable->m_usCount)
    {
        return p->m_pTable->m_pEntries[uiIndex].m_uiValue;
    }
    return m_uiDefault & 0x1f;
}

extern int DAT_010c8d14;
struct FUN_00cba080_class
{
    void* m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    FUN_00cba080_class* FUN_00cba080(int flag);
};
// @fnv 0x00cba080
FUN_00cba080_class* FUN_00cba080_class::FUN_00cba080(int flag)
{
    void* old = m_data;
    m_vtbl = &DAT_010c8d14;
    if (old)
    {
        reinterpret_cast<FUN_00ca0d40_vtable*>(&DAT_010c8d14)->Free(old);
        m_data = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
    if (flag & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

extern int DAT_010c8d00;
extern void(__cdecl* DAT_010c8d08)(void*);

struct FUN_00cba030_class
{
    void* m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_00cba030_class* FUN_00cba030(int flag);
};

// @fnv 0x00cba030
FUN_00cba030_class* FUN_00cba030_class::FUN_00cba030(int flag)
{
    m_vtbl = &DAT_010c8d00;
    if (m_iWordAt04)
    {
        ((void(*)(void*))DAT_010c8d08)(m_iWordAt04);
        m_iWordAt04 = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
    if (flag & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    }
    return this;
}

struct FUN_00ca2020_Class
{
};

struct FUN_00ca20e0_Entries;
struct FUN_00ca20e0_EntriesVtable
{
    void* slot0;
    void* slot1;
    void (*Free)(FUN_00ca20e0_Entries*, void*);
};
struct FUN_00ca20e0_Entries
{
    FUN_00ca20e0_EntriesVtable* vtable;
    FUN_00ca2020_Class** m_pData;
    int m_iCount;
    int m_iCapacity;
};
struct FUN_00ca20e0_Class
{
    int m_iWordAt00;
    FUN_00ca20e0_Entries m_kEntries;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_28;
    int m_2c;
    void ClearAndFreeEntries();
};

void __cdecl _NiFree(void*);
struct FUN_00ca4440_Class
{
    void* m_vtbl;
    void* m_data;
    FUN_00ca4440_Class* FUN_00ca4440(unsigned int flags);
};
// @fnv 0x00ca4440
FUN_00ca4440_Class* FUN_00ca4440_Class::FUN_00ca4440(unsigned int flags)
{
    void* old = m_data;
    m_vtbl = (void*)&DAT_010c759c;
    _NiFree(old);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}


struct FUN_00ca47a0_Ref
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_lRefCount;
};

struct FUN_00ca47a0_Class
{
    FUN_00ca47a0_Ref* m_iWordAt00;
    int m_iWordAt04;
    FUN_00ca47a0_Class* AssignFrom(FUN_00ca47a0_Class* other);
};

// @fnv 0x00ca47a0
FUN_00ca47a0_Class* FUN_00ca47a0_Class::AssignFrom(FUN_00ca47a0_Class* other)
{
    FUN_00ca47a0_Ref* p = m_iWordAt00;
    if (p != other->m_iWordAt00)
    {
        if (p)
        {
            if (!InterlockedDecrement(&p->m_lRefCount))
            {
                p->DeleteThis();
            }
        }
        m_iWordAt00 = other->m_iWordAt00;
        if (m_iWordAt00)
        {
            InterlockedIncrement(&m_iWordAt00->m_lRefCount);
        }
    }
    m_iWordAt04 = other->m_iWordAt04;
    return this;
}

struct FUN_00ca5340_class
{
    int FUN_00ca5290();
    FUN_00ca5340_class* FUN_00ca5340(int flags);
};

extern int _data_011c16bc;
extern int DAT_010c761c;

struct A51BF0Base
{
};

struct S_00cb79d0_Base : public A51BF0Base
{
    void* m_vptr;
    char m_iWordAt04[8];
    int m_iThirdValue;
    int m_10;

    S_00cb79d0_Base();
};

struct bhkPackedNiTriStripsShape : public S_00cb79d0_Base
{
    bhkPackedNiTriStripsShape()
    {
        int count = 1;
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        DAT_012680f8 += count;
        m_vptr = &DAT_010c44e4;
        DAT_012686d0 += count;
        m_vptr = &DAT_010c761c;
        DAT_012682d8 += count;
    }
};

// Allocates and constructs a new bhkPackedNiTriStripsShape and returns it.
// @fnv 0x00ca53b0
bhkPackedNiTriStripsShape* CreatePackedNiTriStripsShape()
{
    return new bhkPackedNiTriStripsShape;
}

class NiObject;
struct NiStream
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
    virtual void v54(NiStream*);
public:
    ::NiObject *GetLoadedObject();
};
struct HC1Owner
{
    char pad[0x84];
    NiStream* m_p84;
};
struct HC1Base
{
    char pad[8];
    HC1Owner* m_p08;
    bool FUN_00aa0ad0(NiStream*);
    bool FUN_00ca54c0(NiStream*);
};
// @fnv 0x00ca54c0
bool HC1Base::FUN_00ca54c0(NiStream* stream)
{
    HC1Owner* s = this ? m_p08 : 0;
    s->m_p84->v54(stream);
    return FUN_00aa0ad0(stream);
}

struct FUN_00ca6620_inner
{
    char pad[0x80];
    float m_f80;
};
struct FUN_00ca6620_outer
{
    char pad[8];
    FUN_00ca6620_inner* m_p08;
};

// Returns m_f80 of the object in p's m_p08, or 1.0f if p or that object is null.
// @fnv 0x00ca6620
float FUN_00ca6620(void* p, int)
{
    float v;
    FUN_00ca6620_outer* outer = static_cast<FUN_00ca6620_outer*>(p);
    if (outer && outer->m_p08)
        v = outer->m_p08->m_f80;
    else
        v = 1.0f;
    return v;
}

// @fnv 0x00ca98e0
float __cdecl FUN_00ca98e0()
{
    return 3.402820018375656e+38;
}

// @fnv 0x00ca9900
void FUN_00ca9900(void** p)
{
    *p = &::DAT_0102e388;
}

void __cdecl _delete(void* p, int size);

struct FUN_00ca9920_class
{
    FUN_00ca9920_class* FUN_00ca9920(int flags);
};

namespace fnv_00ca99f0 {
extern int _data_011c16bc;

struct A51BF0Base
{
};

struct S_00cb79d0_Base : public A51BF0Base
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;

    S_00cb79d0_Base();
};

struct bhkConstraint : public S_00cb79d0_Base
{
    int m_iThirdValue;

    bhkConstraint()
    {
        *(int**)this = &::DAT_0108febc;
        m_iThirdValue = 0;
        ::DAT_01268188 += 1;
        *(int**)this = &::DAT_010c81ac;
        ::DAT_0126830c += 1;
    }
};

// Allocates and constructs a new bhkConstraint, returning the pointer.
// @fnv 0x00ca99f0
bhkConstraint* FUN_00ca99f0()
{
    return new bhkConstraint;
}
}  // namespace fnv_00ca99f0

namespace fnv_00caa1c0 {
struct A51BF0Base
{
};

extern int _data_011c16bc;
extern char DAT_010c5ce4[];

struct S_00cb79d0_Base : public A51BF0Base
{
    void* m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;

    S_00cb79d0_Base();
};

struct bhkConstraint : public S_00cb79d0_Base
{
    bhkConstraint() : S_00cb79d0_Base()
    {
        m_vtbl = (*reinterpret_cast<char (*)[]>(&::DAT_0108febc));
        m_iThirdValue = 0;
        ++::DAT_01268188;
        m_vtbl = DAT_010c5ce4;
        ++::DAT_01268318;
    }
};

// Allocates and constructs a new bhkConstraint object, returning the pointer.
// @fnv 0x00caa1c0
bhkConstraint* __cdecl FUN_00caa1c0()
{
    return new bhkConstraint();
}
}  // namespace fnv_00caa1c0

struct NiStream;
struct FUN_00cac980_Holder
{
};
struct BaseThunk
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cac980_Holder* m_8;
};
struct FUN_00cac070_Stub : BaseThunk
{
    void FUN_00cac070(NiStream&);
};
struct hkpShapePhantom
{
    void SetWorldPosition(void* body, float pos);
};

struct FUN_00cac920_Class
{
    char pad[0x30];
    void* m_30;
    char pad2[0x24];
    float m_58;
    float m_5c;
    void FUN_00cac920(void* body);
};

// Computes pos as m_5c + m_58 and passes it with body to the phantom's method at m_30.
// @fnv 0x00cac920
void FUN_00cac920_Class::FUN_00cac920(void* body)
{
    float pos = m_5c + m_58;
    ((hkpShapePhantom*)m_30)->SetWorldPosition(body, pos);
}

extern int DAT_010c8b0c;
struct FUN_00cb99a0_class
{
    void FUN_00cb99a0(int a);
};
struct FUN_00cb9b30_class : FUN_00cb99a0_class
{
    void* m_vtbl;
    FUN_00cb9b30_class(intptr_t a);
};
struct FUN_00cc66b0
{
    virtual ~FUN_00cc66b0();
};

struct FUN_00cb9c10_class : FUN_00cc66b0
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c10_class* FUN_00cb9c10(int flags);
};

// Calls the base destructor and, when flags has bit 0 set, frees this with size 0x10; returns this.
// @fnv 0x00cb9c10
FUN_00cb9c10_class* FUN_00cb9c10_class::FUN_00cb9c10(int flags)
{
    this->FUN_00cc66b0::~FUN_00cc66b0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern int DAT_010c8cc8;

struct FUN_00cb9c30_class
{
    void* m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c30_class();
};

// @fnv 0x00cb9c30
FUN_00cb9c30_class::FUN_00cb9c30_class()
{
    m_iWordAt04 = 0;
    m_8 = 1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_vtbl = &DAT_010c8cc8;
}

extern int DAT_010c8ce4;
struct FUN_00cb9c50_class
{
    void* m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c50_class();
};
// @fnv 0x00cb9c50
FUN_00cb9c50_class::FUN_00cb9c50_class()
{
    m_iWordAt04 = 0;
    m_8 = 1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_vtbl = &DAT_010c8ce4;
}

struct MemoryManagerReallocateHelper
{
    void* Reallocate(void* p, unsigned int size);
};

struct FUN_00cb9cc0_class
{
    void* ReallocateArray(void* p, unsigned int count);
};

// @fnv 0x00cb9cc0
void* FUN_00cb9cc0_class::ReallocateArray(void* pBuffer, unsigned int count)
{
    return reinterpret_cast<::MemoryManager *>((((MemoryManagerReallocateHelper*)&::g_memoryManager)))->Reallocate(pBuffer, count * 4);
}

// Sets each of the n ints pointed to by p to 0, skipping null p and advancing the pointer.
// @fnv 0x00cb9d50
void FUN_00cb9d50(int* paiValues, uintptr_t n)
{
    while (n > 0)
    {
        if (paiValues)
            *paiValues = 0;
        ++paiValues;
        --n;
    }
}

struct FUN_00cba000_class
{
    void* m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    ~FUN_00cba000_class();
};

extern void(* DAT_010c8d1c)(void*);

// @fnv 0x00cba000
FUN_00cba000_class::~FUN_00cba000_class()
{
    m_vtbl = &DAT_010c8d14;
    if (m_data)
    {
        DAT_010c8d1c(m_data);
        m_data = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
}

void __cdecl FUN_00cba1d0();

struct FUN_00cba6d0_class
{
    FUN_00cba6d0_class* FUN_00cba6d0(int flags);
};

// @fnv 0x00cba6d0
FUN_00cba6d0_class* FUN_00cba6d0_class::FUN_00cba6d0(int flags)
{
    FUN_00cba1d0();
    if (flags & 1)
        _delete(this, 0x40);
    return this;
}

namespace fnv_00cbdae0 {
extern int _data_011c16bc;
extern int DAT_0108fddc;

struct A51BF0Base
{
};

struct S_00cb79d0_Base : A51BF0Base
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;

    S_00cb79d0_Base();
};

struct bhkConstraint : S_00cb79d0_Base
{
    int m_iThirdValue;

    bhkConstraint();
};

bhkConstraint::bhkConstraint() : S_00cb79d0_Base()
{
    *(void**)this = &::DAT_0108febc;
    m_iThirdValue = 0;
    ++::DAT_01268188;
    *(void**)this = &DAT_0108fddc;
    ++::DAT_01268434;
}

// Allocates and constructs a new bhkConstraint object, returning the pointer.
// @fnv 0x00cbdae0
bhkConstraint* __cdecl FUN_00cbdae0()
{
    return new bhkConstraint();
}
}  // namespace fnv_00cbdae0



class CA0CD0World
{
  public:
};

struct CA0CD0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA0CD0World* m_pkWorld;
    int unk14;
    int unk18;
    int unk1C;
    bool m_bValueAt0C;
};

class CA0CD0Manager
{
  public:
    int unk00;
    int unk04;
    CA0CD0Entry** m_ppkEntries;
    unsigned int m_uiCount;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __int64 m_i64StartTime;
    __int64 m_i64Duration;

    void ResetEntries();
};

// @fnv 0x00ca0cd0
void CA0CD0Manager::ResetEntries()
{
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        m_ppkEntries[i]->m_bValueAt0C = true;
        reinterpret_cast<::FUN_00d1fa20_t *>((m_ppkEntries[i]->m_pkWorld))->ResetEntries();
    }
    float fStepMilliseconds = g_fCA0CD0StepTime * 1000.0;
    m_i64StartTime = ((long long)(::FUN_00aa4d80()));
    m_i64Duration = (__int64)(DAT_011ac39c * fStepMilliseconds);
}



struct FUN_00ca0d70_Class
{
    void* m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* FUN_00ca0d70(unsigned char flag);
};

// @fnv 0x00ca0d70
void* FUN_00ca0d70_Class::FUN_00ca0d70(unsigned char flag)
{
    void* v = m_iWordAt04;
    m_vtbl = &DAT_010c7310;
    if (v != 0)
    {
        DAT_010c7318(v);
        m_iWordAt04 = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
    if (flag & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    }
    return this;
}

struct SubObject04
{
    virtual ~SubObject04();
    virtual void Slot1();
    virtual void Free(void* apPtr);
    void* unk04;
    int unk08;
    int unk0c;

    SubObject04();
};

struct Flag18
{
    unsigned char m_v;
    Flag18()
    {
        m_v = 0;
    }
    ~Flag18();
};

SubObject04::SubObject04()
{
    unk04 = 0;
    unk08 = 0;
    unk0c = 0;
}

struct GuardBase04
{
    GuardBase04()
    {}
    ~GuardBase04();
};

struct FUN_00ca0dc0_cls : GuardBase04
{
    virtual ~FUN_00ca0dc0_cls();
    SubObject04 m_sub04;
    int unk14;
    unsigned char m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;

    FUN_00ca0dc0_cls();
};

// Constructor that zeroes m_18 through m_2c and frees m_sub04's unk04 pointer if set, resetting its fields.
// @fnv 0x00ca0dc0
FUN_00ca0dc0_cls::FUN_00ca0dc0_cls() : m_sub04()
{
    SubObject04* pSubObject = &m_sub04;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    if (pSubObject->unk04 != 0)
    {
        pSubObject->Free(pSubObject->unk04);
        pSubObject->unk04 = 0;
        pSubObject->unk0c = 0;
        pSubObject->unk08 = 0;
    }
    m_28 = 0;
    m_2c = 0;
}

// BSSimpleArray-style container of pointer-sized elements.
class CA0E60Array
{
  public:
    void** m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    virtual ~CA0E60Array();
    virtual void** Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void** pBuffer);


    __forceinline void SetSize(unsigned int uiSize)
    {
        if (uiSize == 0)
        {
            if (m_pBuffer)
            {
                Free(m_pBuffer);
                m_pBuffer = 0;
                m_uiCapacity = 0;
                m_uiSize = 0;
            }
        }
        else if (uiSize > m_uiCapacity)
        {
            if (m_uiCapacity == 0)
                m_pBuffer = Allocate(uiSize);
            else
                reinterpret_cast<::FUN_00cb9ce0_cls *>(this)->FUN_00cb9ce0(uiSize, m_uiSize);
            m_uiCapacity = uiSize;
            m_uiSize = uiSize;
        }
        else if (uiSize < m_uiSize)
        {
            m_uiSize = uiSize;
            if (uiSize <= m_uiCapacity >> 2)
            {
                reinterpret_cast<::FUN_00cb9ce0_cls *>(this)->FUN_00cb9ce0(uiSize, uiSize);
                m_uiCapacity = uiSize;
            }
        }
        else
        {
            m_uiSize = uiSize;
        }
    }

    void CopyTo(CA0E60Array& kDest) const;
};

// Resizes the destination array to this array's size and copies each element pointer into it.
// @fnv 0x00ca0e60
void CA0E60Array::CopyTo(CA0E60Array& kDest) const
{
    kDest.SetSize(m_uiSize);
    for (unsigned int i = 0; i < m_uiSize; i++)
        kDest.m_pBuffer[i] = m_pBuffer[i];
}

struct CA1080_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};

struct CA1080_Holder
{
    int unk00;
    int unk04;
    int unk08;
    CA1080_Shape* shape;
};

struct CA1080_Entry
{
    CA1080_Holder* holder;
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

struct CA1080_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
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
    CA1080_Entry* entries;
    unsigned short entryCount;
    unsigned short unkb2;
    CA1080_Holder** holders;
    int holderCount;
};

struct CA1080_NodeList
{
    CA1080_Node** data;
    int count;
    CA1080_Node* GetAt(int i) const
    {
        return data[i];
    }
};

struct CA1080_PtrArray
{
    virtual void v00();
    virtual void** Allocate(unsigned int count);
    virtual void v08();
    virtual void** Reallocate(void** data, unsigned int count);

    void** data;
    unsigned int size;
    unsigned int capacity;

    void Add(void* item)
    {
        if (size == capacity)
        {
            if (capacity == 0)
            {
                data = Allocate(4);
                capacity = 4;
            }
            else
            {
                unsigned int newCap = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                if (data)
                {
                    data = Reallocate(data, newCap);
                }
                else
                {
                    data = Allocate(newCap);
                    capacity = newCap;
                }
                capacity = newCap;
            }
        }
        size++;
        data[size - 1] = item;
    }
};

// For each node in list, adds node->m_0c to out when its entries are not all type 11 and its holders are not all non-type-11.
// @fnv 0x00ca1080
void CollectMixedTypeNodes(CA1080_NodeList* list, CA1080_PtrArray* out)
{
    for (int i = 0; i < list->count; i++)
    {
        bool bAllEntriesType11 = true;
        for (int j = 0; j < list->GetAt(i)->entryCount && bAllEntriesType11; j++)
        {
            bAllEntriesType11 = list->GetAt(i)->entries[j].holder->shape->GetType() == 11;
        }
        bool other = false;
        for (int k = 0; k < list->GetAt(i)->holderCount && !other; k++)
        {
            other = list->GetAt(i)->holders[k]->shape->GetType() != 11;
        }
        if (!bAllEntriesType11 && !other)
        {
            CA1080_Node* node = list->GetAt(i);
            out->Add(node ? node->m_0c : 0);
        }
    }
}


struct SceneLookupBase_cls
{
};

struct SceneHost_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SceneHost_cls* m_10;
};

struct SceneLeaf_cls : SceneLookupBase_cls
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
    virtual int v37();
};

struct SceneNode_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    SceneHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    SceneNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct SceneWalker_cls
{
    void TraverseSceneNode(SceneNode_cls* node, void* a2, void* a3);
};

// @fnv 0x00ca1f00
void SceneWalker_cls::TraverseSceneNode(SceneNode_cls* node, void* a2, void* a3)
{
    if (node == 0)
        return;
    if (node->m_1c != 0)
    {
        SceneHost_cls* h2 = (SceneHost_cls*)((void *)(reinterpret_cast<::NiObject *>((node->m_1c))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_01267e64))))));
        if (h2 != 0 && h2->m_10 != 0)
        {
            SceneLeaf_cls* leaf = (SceneLeaf_cls*)((void *)(reinterpret_cast<::NiObject *>((h2->m_10))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_012681c0))))));
            if (leaf != 0 && leaf->v37() != 0)
            {
                ::CollectLeafObjects((::WalkLeaf *)(leaf), (::WalkArray *)(a2), (::WalkArray *)(a3));
            }
        }
    }
    SceneNode_cls* arr = (SceneNode_cls*)((void *)(reinterpret_cast<::NiObject *>((node))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f4428))))));
    if (arr != 0)
    {
        for (unsigned int i = 0; i < arr->m_a6; i++)
        {
            TraverseSceneNode(arr->m_a0[i], a2, a3);
        }
    }
}

struct FNVTaskElement
{
};
struct FNVTaskAllocator
{
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void Free(void* memory, unsigned int byteCount);
};
struct FNVTaskMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FNVTaskAllocator* allocator;
};

struct FNVTaskDynamicBuffer
{
    void* entries;
    int elementCount;
    unsigned int capacityAndFlags;
    void Clear();
};

// @fnv 0x00ca1fb0
void FNVTaskDynamicBuffer::Clear()
{
    FNVTaskAllocator* allocator = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator;
    char* entry = (char*)entries;
    if (elementCount > 0)
    {
        int remaining = elementCount;
        do
        {
            ::FUN_00d1fa10();
            entry += 48;
        } while (--remaining);
    }
    elementCount = 0;
    if ((capacityAndFlags & 0x80000000u) == 0)
        allocator->Free(entries, (capacityAndFlags & 0x3fffffffu) * 48);
    capacityAndFlags = 0x80000000u;
    entries = 0;
}


struct CA2020AllocTagScope
{
    int m_iSaved;

    CA2020AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CA2020AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class CA2020Object
{
  public:
    virtual ~CA2020Object();
};

class CA2020Referenced
{
  public:
};

class CA2020Array
{
  public:
    ~CA2020Array();

    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;
};

class FUN_00ca2020_Holder
{
  public:
    ~FUN_00ca2020_Holder();

    int unk00;
    CA2020Referenced* m_pkShape;
    CA2020Object* m_pkFirst;
    CA2020Object* m_pkSecond;
    CA2020Referenced* m_pkBody;
    CA2020Array m_kEntries;
};
// @fnv 0x00ca20e0
void FUN_00ca20e0_Class::ClearAndFreeEntries()
{
    unsigned int i;
    for (i = 0; i < (unsigned int)m_kEntries.m_iCount; i++)
    {
        FUN_00ca2020_Class* p = m_kEntries.m_pData[i];
        if (p)
        {
            reinterpret_cast<::FUN_00ca2020_Holder *>((p))->FUN_00ca2020_Holder::~FUN_00ca2020_Holder();
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
        }
    }
    FUN_00ca20e0_Entries* arr = &m_kEntries;
    if (arr->m_pData)
    {
        arr->vtable->Free(arr, arr->m_pData);
        arr->m_pData = 0;
        arr->m_iCapacity = 0;
        arr->m_iCount = 0;
    }
    m_28 = 0;
    m_2c = 0;
}

// Destructor: deletes m_pkFirst and m_pkSecond, removes references from m_pkShape and m_pkBody, under an alloc-tag scope of 0x10.
// @fnv 0x00ca2020
FUN_00ca2020_Holder::~FUN_00ca2020_Holder()
{
    CA2020AllocTagScope kScope(0x10);
    if (m_pkFirst)
        delete m_pkFirst;
    if (m_pkShape)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pkShape))->FUN_00c905b0();
    if (m_pkBody)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pkBody))->FUN_00c905b0();
    if (m_pkSecond)
        delete m_pkSecond;
}

struct FUN_00a5d3d0_class
{
};

struct FUN_00ca3570_class : FUN_00a5d3d0_class
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;

    void FUN_00ca3570();
};
// Calls FUN_00ca3570, then if bit 0 of a is set frees this with size 0x30, and returns this.
// @fnv 0x00ca3980
FUN_00ca3980_class* FUN_00ca3980_class::FUN_00ca3980(int aiFlags)
{
    static_cast<::FUN_00ca3570_class *>(nullptr)->FUN_00ca3570();
    if (aiFlags & 1)
        _delete(this, 0x30);
    return this;
}

extern "C" char DAT_010c740c[];

// @fnv 0x00ca3570
void FUN_00ca3570_class::FUN_00ca3570()
{
    m_vtbl = DAT_010c740c;

    if (unk14)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(unk14);

    if (unk18)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(unk18);

    if (unk24)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(unk24);

    if (unk20)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(unk20);

    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
}

struct Record
{
    int m_iValue;
    int m_iField04;
    int m_iField08;
};

struct Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int* m_pValues;
};

struct Owner
{
    int unk00[29];
    Table* m_pTable;

    int GetValueByIndex(unsigned int a1);
public:
    void FUN_00cab0e0(intptr_t, intptr_t, float);
};

// Extracts a 24-bit-shifted index from a1, bounds-checks it against m_pTable->unk10, and returns the value at that index times 3 from m_pValues.
// @fnv 0x00ca3670
int Owner::GetValueByIndex(unsigned int a1)
{
    Table* pSearchEntries = m_pTable;
    int iIndex = (int)(a1 >> 24);
    if (iIndex >= (int)pSearchEntries->unk10)
    {
        return 0;
    }
    return pSearchEntries->m_pValues[iIndex * 3];
}

struct FUN_00ca3b10_cls
{
    int m_iWordAt00;
    unsigned char m_iWordAt04;
    int m_8;

    bool FUN_00ca3b10();
};

// @fnv 0x00ca3b10
bool FUN_00ca3b10_cls::FUN_00ca3b10()
{
    return m_iWordAt04 == 0;
}

namespace fnv_00ca40f0 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00ca40f0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00ca3b90();

    FUN_00ca40f0_cls* FUN_00ca40f0(unsigned char acFlags);
};

// Calls FUN_00ca3b90, then if bit 0 of acFlags is set frees this through the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00ca40f0
FUN_00ca40f0_cls* FUN_00ca40f0_cls::FUN_00ca40f0(unsigned char acFlags)
{
    FUN_00ca3b90();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00ca40f0

void __cdecl FUN_00aa10f0(void*);
struct PrimaryPart
{
    virtual ~PrimaryPart()
    {}
    unsigned int unknown_04, unknown_08, unknown_0c;
};
struct SecondaryPart
{
    virtual ~SecondaryPart()
    {}
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
};
struct CombinedBase : PrimaryPart, SecondaryPart
{
    virtual ~CombinedBase()
    {}
};
struct ResourceMember
{
    virtual ~ResourceMember()
    {
        FUN_00aa10f0(data);
    }
    void* data;
};
struct FUN_00ca4490 : CombinedBase
{
    ResourceMember resource;
    virtual ~FUN_00ca4490();
};
// @fnv 0x00ca4490
FUN_00ca4490::~FUN_00ca4490()
{}

struct FUN_00ca4780_tableEntry
{
    unsigned int m_iIndex;
    void* m_pIntegerData;
};

struct FUN_00ca4780_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    FUN_00ca4780_tableEntry* m_pTable;
    void* FUN_00ca4780(unsigned int a1);
};

// @fnv 0x00ca4780
void* FUN_00ca4780_cls::FUN_00ca4780(unsigned int a1)
{
    FUN_00ca4780_tableEntry* pSearchEntries = m_pTable;
    unsigned int iIndex = a1 >> 20;
    return pSearchEntries[iIndex].m_pIntegerData;
}

struct S_00ca49a0_Obj
{
    long m_refs;
    virtual void vfn0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_refs))
            DeleteThis();
    }
};

struct S_00ca49a0_Ptr
{
    S_00ca49a0_Obj* m_p;
    S_00ca49a0_Ptr(S_00ca49a0_Obj* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    S_00ca49a0_Ptr(const S_00ca49a0_Ptr& o)
    {
        m_p = o.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00ca49a0_Ptr()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    S_00ca49a0_Ptr& operator=(const S_00ca49a0_Ptr& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};

struct S_00ca49a0_Elem
{
    S_00ca49a0_Ptr obj;
    int unk04;
    S_00ca49a0_Elem(int v = 0) : obj(0)
    {
        unk04 = v;
    }
    bool operator==(const S_00ca49a0_Elem& o) const
    {
        return obj.m_p == o.obj.m_p && unk04 == o.unk04;
    }
    bool operator!=(const S_00ca49a0_Elem& o) const
    {
        return !(*this == o);
    }
};

struct S_00ca49a0_Array
{
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    int unk08;
    unsigned int m_uiESize;
    unsigned int m_uiCount;
    void FUN_00ca49a0(unsigned int idx, const S_00ca49a0_Elem& e);
};

// Stores element e at index idx, growing m_uiESize and adjusting m_uiCount when the slot's empty/non-empty state changes.
// @fnv 0x00ca49a0
void S_00ca49a0_Array::FUN_00ca49a0(unsigned int uiIndex, const S_00ca49a0_Elem& arElem)
{
    if (uiIndex >= m_uiESize)
    {
        m_uiESize = uiIndex + 1;
        if ((arElem != S_00ca49a0_Elem(0)))
            m_uiCount++;
    }
    else
    {
        if ((arElem != S_00ca49a0_Elem(0)))
        {
            if (m_pBase[uiIndex] == S_00ca49a0_Elem(0))
                m_uiCount++;
        }
        else if (m_pBase[uiIndex] != S_00ca49a0_Elem(0))
        {
            m_uiCount--;
        }
    }
    m_pBase[uiIndex] = arElem;
}

struct HandlePage
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    unsigned short m_40;
};

struct HandleSlot
{
    HandlePage* m_pHandlePage;
    int m_04;
};

class HandleManager
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    HandleSlot* m_88;
    int m_8C;
    int m_90;

    int FUN_00ca4ac0(int handle);
};

struct HandleOwner
{
    char pad[0x10];
    HandleManager m_kManager;
    bool IsDegenerate(unsigned int handle);
};

// @fnv 0x00ca4ac0
int HandleManager::FUN_00ca4ac0(int handle)
{
    unsigned int cur = (unsigned int)handle;
    for (;;)
    {
        cur++;
        unsigned int page = cur >> 0x14;
        int lo = (int)(cur & 0xfffff);
        int iPageCount = (int)m_88[page].m_pHandlePage->m_40;
        if (lo >= iPageCount)
        {
            cur = (page + 1) << 0x14;
        }
        int iPageIndex = (int)(cur >> 0x14);
        if (iPageIndex >= m_90)
        {
            return -1;
        }
        HandleOwner* owner = reinterpret_cast<HandleOwner*>(reinterpret_cast<char*>(this) - offsetof(HandleOwner, m_kManager));
        if (!owner->IsDegenerate(cur))
        {
            return (int)cur;
        }
    }
}

struct RefEntryObject
{
    virtual void Unknown();
    virtual void Release();
    volatile long referenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
};
struct RecordEntry
{
    NiPointer<RefEntryObject> object;
    unsigned int value;
    RecordEntry() : object(), value(0)
    {}
};
struct RecordArray
{
    void* vtable;
    RecordEntry* records;
    unsigned int capacity;
    unsigned int count;
    unsigned int elementSize;
    void ClearRecords();
};
// Resets every record in the array to a default RecordEntry, then sets count and elementSize to zero.
// @fnv 0x00ca4b20
void RecordArray::ClearRecords()
{
    for (unsigned int i = 0; i < count; ++i)
    {
        records[i] = RecordEntry();
    }
    count = 0;
    elementSize = 0;
}

class FUN_00ca4d20_cls;
class FNVSub3Blob
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVSub4
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVEntry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
};
class FNVSub2
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int m_14;
};
class FNVArg
{
  public:
    unsigned int unk00;
    float m_04;
    FNVSub2 m_08;
    FNVSub4 m_20;
};
class FUN_00ca4d20_cls
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
    FNVSub3Blob m_80;
    float m_90;
    unsigned int unk94;
    FNVEntry* m_98;
    unsigned int unk9c;
    int m_a0;
    void CopyEntriesToArg(FNVArg* a1);
};

struct S_00ca4e10_T
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00ca4e10_Out
{
    int unk00;
    void* unk04;
};

struct S_00ca4e10_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual char* v10();
};

struct S_00ca4e10_Cls
{
    int unk00;
    int unk04;
    S_00ca4e10_Obj* unk08;
    char* FUN_00ca4e10(S_00ca4e10_Out* out);
};

// Calls FUN_00c84e20 on out, then stores the object's v10() result minus 0x10 (or null) into out->unk04 and returns it.
// @fnv 0x00ca4e10
char* S_00ca4e10_Cls::FUN_00ca4e10(S_00ca4e10_Out* out)
{
    reinterpret_cast<::This *>(this)->FUN_00c84e20((unsigned int *)(out));
    char* r;
    char* p;
    S_00ca4e10_Obj* o;
    if (this && (o = unk08) != 0 && (p = o->v10()) != 0)
        r = p - 0x10;
    else
        r = 0;
    out->unk04 = r;
    return r;
}

struct FUN_00cd2de0
{
    virtual ~FUN_00cd2de0();
};
struct FUN_00ca5290 : FUN_00cd2de0
{
    virtual ~FUN_00ca5290();
};
// Calls FUN_00ca5290, and if flags has bit 0 set, frees this with size 0x14; returns this.
// @fnv 0x00ca5340
FUN_00ca5340_class* FUN_00ca5340_class::FUN_00ca5340(int flags)
{
    reinterpret_cast<::FUN_00ca5290 *>(this)->FUN_00ca5290::~FUN_00ca5290();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}
// Calls FUN_00c876a0 then decrements the global counter DAT_012682d8.
// @fnv 0x00ca5290
FUN_00ca5290::~FUN_00ca5290()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_012682d8;
}


// @fnv 0x00ca5300
int* __cdecl FUN_00ca5300()
{
    return &(*reinterpret_cast<int *>(&::g_012682dc));
}

struct MatchData
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
    int value84;
};
struct MatchObject
{
    int unk00;
    int unk04;
    MatchData* data;
    bool Equals(MatchObject* rhs);
};
// Calls FUN_00c84dc0(rhs); if it returns true, also compares value84 of this->data and rhs->data and returns that result.
// @fnv 0x00ca54f0
bool MatchObject::Equals(MatchObject* rhs)
{
    bool result = reinterpret_cast<::FUN_00c84dc0_cls *>(this)->FUN_00c84dc0((::FUN_00c84dc0_param *)(rhs));
    if (result)
    {
        MatchData* right = rhs ? rhs->data : 0;
        MatchData* left = this ? this->data : 0;
        result = left->value84 == right->value84;
    }
    return result;
}

struct S_00ca59d0_Out;
struct S_00ca59d0_Bin
{
    int unk00;
    unsigned int unk04;
    unsigned int(__cdecl* unk08)(S_00ca59d0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* unk0C)(S_00ca59d0_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* buf, unsigned int bytes, unsigned int* compSize, unsigned int n)
    {
        unk04 += unk0C(this, buf, bytes, compSize, n);
    }
};
template <class T> inline void S_00ca59d0_Save(S_00ca59d0_Bin& bin, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    bin.Write(p, n * sizeof(T), &uiSize, 1);
}
struct S_00ca59d0_Stream
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
    virtual void v12(void* link);
    int unk4;
    int unk8;
    int unkC;
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
    S_00ca59d0_Bin* unk250;
};
struct S_00ca59d0_Vec4
{
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};
struct S_00ca59d0_Member
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    void* unk84;
    int unk88;
    int unk8C;
    S_00ca59d0_Vec4 unk90;
    float unkA0;
};
struct S_00ca59d0_Self
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
    virtual void v41(int out);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45(int* out);
    int unk04;
    S_00ca59d0_Member* unk08;
    void FUN_00ca59d0(S_00ca59d0_Stream* s);
};
// @fnv 0x00ca59d0
void S_00ca59d0_Self::FUN_00ca59d0(S_00ca59d0_Stream* pStream)
{
    int out;
    v45(&out);
    S_00ca59d0_Member* m = unk08;
    reinterpret_cast<::FUN_00c84d50_cls *>(this)->FUN_00c84d50(pStream);
    float f = m->unkA0;
    S_00ca59d0_Save(*pStream->unk250, &f, 1);
    S_00ca59d0_Save(*pStream->unk250, &m->unk90, 1);
    pStream->v12(m->unk84);
    v41(out);
}

struct TlsBlock_t
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct Owned_t
{
};

struct PoolFree_t
{
    void Free(void* p);
};


struct FUN_00ca5a80_cls
{
    int unk00;
    int unk04;
    int unk08;
    Owned_t* m_0c;

    void ReleaseOwned(bool flag);
};

// FUN_00ca6600 : a one-line function - getter
// @fnv 0x00ca6600
void* FUN_00ca6600()
{
    return &(*reinterpret_cast<int *>(&::g_012682e8));
}


void* __cdecl FUN_00aa13e0(size_t size);

struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

};

struct ChainA_cls : public OwnerBase
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

struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        DAT_012682e4 += 1;
    }
};

// Allocates and constructs a SpawnedObject, returning the new instance.
// @fnv 0x00ca6670
SpawnedObject* FUN_00ca6670()
{
    return new SpawnedObject();
}

struct ArgB
{
    unsigned int unk00, unk04, unk08, unk0c;
    float f10;
};
struct ca6720Target
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float f20, f24, f28, f2c;
};
class bhkSphereShape
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual ca6720Target* Target(char* out);
    void ScaleTarget(void* a1, ArgB* a2);
};
// Scales the target's four floats by a2->f10, then calls FUN_00c84df0 with a1 and a2.
// @fnv 0x00ca6720
void bhkSphereShape::ScaleTarget(void* apArg, ArgB* apArgB)
{
    unsigned char c;
    ca6720Target* r = this->Target((char*)&c);
    float v = apArgB->f10;
    volatile float* first = &r->f20;
    *first = *first * v;
    r->f24 = r->f24 * v;
    volatile float* third = &r->f28;
    *third = *third * v;
    r->f2c = r->f2c * v;
    reinterpret_cast<::FUN_00c84df0_cls *>((this))->FUN_00c84df0((::FUN_00c84df0_cls *)(apArg), (::FUN_00c84df0_cls *)(apArgB));
}

struct S_00ca6810_Callable
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54(int arg);
};

struct S_00ca6810_Entry
{
    S_00ca6810_Callable* callable;
    int unk04;
};

struct S_00ca6810_Inner
{
    void* unk00;
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
    S_00ca6810_Entry* unk98;
    int unk9c;
    int unkA0;
};


struct S_00ca6810_Class
{
    void* unk00;
    int unk04;
    S_00ca6810_Inner* unk08;

    void FUN_00ca6810(int arg);
};

// Calls slot54(arg) on each callable in unk08->unk98 up to unk08->unkA0 entries, then calls FUN_00aa0ad0(arg).
// @fnv 0x00ca6810
void S_00ca6810_Class::FUN_00ca6810(int aiValue)
{
    int count;

    if (this != 0 && this->unk08 != 0)
        count = this->unk08->unkA0;
    else
        count = 0;

    for (int i = 0; i < count; ++i)
    {
        S_00ca6810_Callable** slot;

        if (this != 0 && this->unk08 != 0)
        {
            S_00ca6810_Entry& entry = this->unk08->unk98[i];
            slot = &entry.callable;
        }
        else
        {
            slot = &DAT_012682f0;
        }

        S_00ca6810_Callable* callable = *slot;
        if (callable != 0)
            callable->slot54(aiValue);
    }

    ::FUN_00aa0ad0();
}

struct S_00ca6880_Node
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
};

struct S_00ca6880_Class
{
    int unk00;
    int unk04;
    S_00ca6880_Node* unk08;
    char IsEquivalent(S_00ca6880_Class* arg);
};

static inline int Val(S_00ca6880_Class* o)
{
    if (o && o->unk08)
        return o->unk08->unka0;
    return 0;
}
// Calls FUN_00c84dc0 on arg; if it returns true, returns whether Val(this) equals Val(arg).
// @fnv 0x00ca6880
char S_00ca6880_Class::IsEquivalent(S_00ca6880_Class* pOther)
{
    char r = ((char)(reinterpret_cast<::FUN_00c84dc0_cls *>(this)->FUN_00c84dc0((::FUN_00c84dc0_param *)(pOther))));
    if (r)
    {
        r = Val(this) == Val(pOther);
    }
    return r;
}

namespace fnv_00ca68d0 {
// GetFieldValue: thiscall, one stack arg (table index selector)
struct FUN_00ca68d0_rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct FUN_00ca68d0_entry
{
    FUN_00ca68d0_rec* m_pAssociatedRecord;
    unsigned int m_04;
};

struct FUN_00ca68d0_owner
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
    FUN_00ca68d0_entry* m_98;
};


class FUN_00ca68d0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00ca68d0_owner* m_08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int GetFieldValue(unsigned int a1);
};

// @fnv 0x00ca68d0
unsigned int FUN_00ca68d0_cls::GetFieldValue(unsigned int auiIndex)
{
    if (auiIndex == 0xffffffff)
    {
        return m_10 & 0x1f;
    }
    FUN_00ca68d0_entry* e;
    if (this != 0 && m_08 != 0)
    {
        e = m_08->m_98 + (auiIndex >> 20);
    }
    else
    {
        e = &(*reinterpret_cast<::fnv_00ca68d0::FUN_00ca68d0_entry *>(&::DAT_012682f0));
    }
    FUN_00ca68d0_rec* rec = e->m_pAssociatedRecord;
    if (rec != 0)
    {
        return (rec->m_0c >> 6) & 0x1f;
    }
    return 0;
}
}  // namespace fnv_00ca68d0

namespace fnv_00ca6920 {
struct S_00ca6920_Rec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;
};

struct S_00ca6920_RecB
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
};

struct S_00ca6920_Ent
{
    S_00ca6920_Rec* rec;
    int unk04;
};

struct S_00ca6920_Mgr
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
    S_00ca6920_Ent* unk98;
};


struct S_00ca6920_Cls
{
    int unk00;
    int unk04;
    S_00ca6920_Mgr* unk08;
    int unk0c;
    unsigned unk10;
    unsigned char GetFlag(unsigned id, unsigned mask);
};

// @fnv 0x00ca6920
unsigned char S_00ca6920_Cls::GetFlag(unsigned id, unsigned mask)
{
    if (id == 0xffffffff)
        return (unk10 & mask) != 0;
    S_00ca6920_Ent* pEntry;
    if (this && unk08)
        pEntry = unk08->unk98 + (id >> 20);
    else
        pEntry = &(*reinterpret_cast<::fnv_00ca6920::S_00ca6920_Ent *>(&::DAT_012682f0));
    unsigned char r = 0;
    S_00ca6920_Rec* rec = pEntry->rec;
    if (rec)
    {
        switch (mask)
        {
        case 0x20:
            r = (((S_00ca6920_RecB*)rec)->unk0c >> 5) & 1;
            break;
        case 0x40:
            r = (rec->unk0c >> 11) & 1;
            break;
        }
    }
    return r;
}
}  // namespace fnv_00ca6920

void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
extern int DAT_010c771c;

struct AllocationContextGuard
{
    int previous;
    AllocationContextGuard()
    {
        previous = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~AllocationContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};

struct FNVShape : S_00cb79d0_Base
{
    FNVShape()
    {
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_vptr = &DAT_010c44e4;
        ++DAT_012686d0;
        m_vptr = &DAT_010c771c;
        ++DAT_012682e4;
    }
};

struct FNVShapeHost
{
    virtual void Slot00() = 0;
    virtual void Slot04() = 0;
    virtual void Slot08() = 0;
    virtual void Slot0c() = 0;
    virtual void Slot10() = 0;
    virtual void Slot14() = 0;
    virtual void Slot18() = 0;
    virtual void Slot1c() = 0;
    virtual void Slot20() = 0;
    virtual void Slot24() = 0;
    virtual void Slot28() = 0;
    virtual void Slot2c() = 0;
    virtual void Slot30() = 0;
    virtual void Slot34() = 0;
    virtual void Slot38() = 0;
    virtual void Slot3c() = 0;
    virtual void Slot40() = 0;
    virtual void Slot44() = 0;
    virtual void Slot48() = 0;
    virtual void Slot4c() = 0;
    virtual void Slot50() = 0;
    virtual void Slot54() = 0;
    virtual void Slot58() = 0;
    virtual void Slot5c() = 0;
    virtual void Slot60() = 0;
    virtual void Slot64() = 0;
    virtual void Slot68() = 0;
    virtual void Slot6c() = 0;
    virtual void Slot70() = 0;
    virtual void Slot74() = 0;
    virtual void Slot78() = 0;
    virtual void Slot7c() = 0;
    virtual void Slot80() = 0;
    virtual void Slot84() = 0;
    virtual void Slot88() = 0;
    virtual void Slot8c() = 0;
    virtual void Slot90() = 0;
    virtual void Slot94() = 0;
    virtual void Slot98() = 0;
    virtual void Slot9c() = 0;
    virtual void Slota0() = 0;
    virtual void Slota4() = 0;
    virtual void Slota8() = 0;
    virtual void Slotac() = 0;
    virtual void Slotb0() = 0;
    virtual void Slotb4() = 0;
    virtual void Slotb8() = 0;
    virtual void Slotbc() = 0;
    virtual void Slotc0() = 0;
    virtual void AssignShape(FNVShape* shape, int flags) = 0;
    FNVShape* CreateShape(int flags);
};

// Creates a new FNVShape, assigns it via AssignShape with the given flags, and returns it.
// @fnv 0x00ca6990
FNVShape* FNVShapeHost::CreateShape(int flags)
{
    AllocationContextGuard allocationScope;
    FUN_00c876f0();
    FNVShape* shape = new FNVShape();
    AssignShape(shape, flags);
    FUN_00c87700();
    return shape;
}

namespace fnv_00ca6a80 {
struct TlsBlock
{
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
    unsigned int m_2b4;
};

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = (*reinterpret_cast<::fnv_00ca6a80::TlsBlock *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00ca6a80::TlsBlock *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        (*reinterpret_cast<::fnv_00ca6a80::TlsBlock *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct FUN_00aa3e40_alloc
{
};

struct FUN_00ca4bc0_obj
{
    static void* operator new(std::size_t size)
    {
        unsigned char* a = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00ca6a80::FUN_00aa3e40_alloc *>(&::g_memoryManager))))->FUN_00aa3e40(size);
        unsigned char pad = (unsigned char)(0x10 - ((uintptr_t)a & 0xf));
        a += pad;
        GetAlignedBlockPrefix(a)->m_ucOffset = pad;
        return a;
    }
    static void operator delete(void*)
    {}
    FUN_00ca4bc0_obj(int arg);
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
};

struct FUN_00c905b0_obj
{
};

class FUN_00ca6a80_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c(void* obj);
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc(int arg);
    void InitWithArg(int arg);
};

// Allocates a FUN_00ca4bc0_obj with arg, passes it to vfn_8c, calls FUN_00c905b0 on it, then calls vfn_bc(arg) under a TLS flag guard.
// @fnv 0x00ca6a80
void FUN_00ca6a80_cls::InitWithArg(int arg)
{
    TlsFlagGuard guard;
    FUN_00ca4bc0_obj* obj = new FUN_00ca4bc0_obj(arg);
    vfn_8c(obj);
    reinterpret_cast<::hkReferencedObjectC905 *>((reinterpret_cast<FUN_00c905b0_obj*>(obj)))->FUN_00c905b0();
    vfn_bc(arg);
}
}  // namespace fnv_00ca6a80

struct S_00ca7310_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned int m_pRayCursor;
    S_00ca7310_Arr() : m_data(0), m_iElementCount(0), m_pRayCursor(0x80000000)
    {}
};
struct S_00ca7310_Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00ca7310_Root()
    {
        unk00 = 0;
    }
};
struct S_00ca7310_Vec
{
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    S_00ca7310_Vec()
    {
        unk10 = 0.0f;
        unk14 = 0.0f;
        unk18 = 0.0f;
        unk1C = 0.0f;
    }
};
struct FUN_00ca7310 : S_00ca7310_Root
{
    S_00ca7310_Vec vec;
    int unk20;
    S_00ca7310_Arr unk24;
    S_00ca7310_Arr unk30;
    S_00ca7310_Arr unk3C;
    S_00ca7310_Arr unk48;
    S_00ca7310_Arr unk54;
    S_00ca7310_Arr unk60;
    S_00ca7310_Arr unk6C;
    S_00ca7310_Arr unk78;
    S_00ca7310_Arr unk84;
    S_00ca7310_Arr unk90;
    S_00ca7310_Arr unk9C;
    S_00ca7310_Arr unkA8;
    FUN_00ca7310();
};
// @fnv 0x00ca7310
FUN_00ca7310::FUN_00ca7310()
{}

struct MotionByte
{
};
struct MotionInstance
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void SetMass(float);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void SetInertia(const float*);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void SetGridPosition(const void*);
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
    MotionByte linearDamping;
    MotionByte angularDamping;
};
struct MotionStorage
{
};
float FUN_00c9e0f0(float, float);
// Selects a motion instance from storage by type, sets inertia, center and mass unless type is 4, then applies linear and angular damping.
// @fnv 0x00ca8240
void FUN_00ca8240(int type, const void* position, const void* rotation, float mass, const float* inertia,
                  const void* center, float linearDamping, float angularDamping, MotionStorage* storage)
{
    MotionInstance* motion;
    switch (type)
    {
    case 2:
        motion = storage ? ((::MotionInstance *)(new ((void *)(storage)) ::FUN_00ca9270((void *)(position), (void *)(rotation)))) : 0;
        break;
    case 3:
        motion = storage ? ((::MotionInstance *)(reinterpret_cast<::S00d1e690_cls *>((storage))->FUN_00d1e690((intptr_t)(position), (intptr_t)(rotation)))) : 0;
        break;
    case 6:
        motion = storage ? ((::MotionInstance *)(new ((void *)(storage)) ::FUN_00d21930((intptr_t)(position), (intptr_t)(rotation)))) : 0;
        break;
    case 1: {
        float x = inertia[0], y = inertia[5], z = inertia[10];
        float fMinInertia = FUN_00c9e0f0(x, FUN_00c9e0f0(y, z));
        if ((double)0.8f * FUN_00c98210(x, FUN_00c98210(y, z)) < fMinInertia)
            motion = storage ? ((::MotionInstance *)(new ((void *)(storage)) ::FUN_00ca9270((void *)(position), (void *)(rotation)))) : 0;
        else
            motion = storage ? ((::MotionInstance *)(reinterpret_cast<::S00d1e690_cls *>((storage))->FUN_00d1e690((intptr_t)(position), (intptr_t)(rotation)))) : 0;
        break;
    }
    case 4:
        angularDamping = linearDamping = 1000000.0f;
        motion = storage ? ((::MotionInstance *)(new ((void *)(storage)) ::FUN_00d1dfa0((*(const ::hkVector4D1DF *)(position)), (*(const ::hkQuaternionD1DF *)(rotation))))) : 0;
        break;
    case 7:
        motion = storage ? ((::MotionInstance *)(new ((void *)(storage)) ::FUN_00ca9240((intptr_t)(position), (intptr_t)(rotation)))) : 0;
        break;
    default:
        motion = storage ? ((::MotionInstance *)(reinterpret_cast<::FUN_00d1e160_t *>((storage))->InitFixedRigidMotion((intptr_t)(position), (intptr_t)(rotation)))) : 0;
        break;
    }
    if (type != 4)
    {
        motion->SetInertia(inertia);
        motion->SetGridPosition(center);
        motion->SetMass(mass);
    }
    reinterpret_cast<::FUN_00ca9360_cls *>(&(motion->linearDamping))->FUN_00ca9360(&linearDamping);
    reinterpret_cast<::FUN_00ca9360_cls *>(&(motion->angularDamping))->FUN_00ca9360(&angularDamping);
}

struct Ctx
{
    void* pThis;
    int a1;
    char a2;
};
struct Obj
{
    virtual void v0();
    virtual void v1(Ctx*);
public:
    bool FUN_00c85810(::Obj *);
};
struct C
{
    char pad[0x8c];
    Obj** m8c;
    int m90;
    void NotifyAll(intptr_t a1, char a2);
};
// Iterates m8c backwards from m90-1 and calls v1 on each non-null entry with a context holding a1, this and a2.
// @fnv 0x00ca9520
void C::NotifyAll(intptr_t aiValue, char a2)
{
    Ctx ctx;
    ctx.a1 = aiValue;
    ctx.pThis = this;
    ctx.a2 = a2;
    for (int i = this->m90 - 1; i >= 0; --i)
    {
        if (this->m8c[i])
        {
            Obj* p = this->m8c[i];
            p->v1(&ctx);
        }
    }
}


class FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_base();
};

class FUN_00ca9860_cls : public FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_cls();
};
// @fnv 0x00ca9920
FUN_00ca9920_class* FUN_00ca9920_class::FUN_00ca9920(int flags)
{
    reinterpret_cast<::FUN_00ca9860_cls *>(this)->FUN_00ca9860_cls::~FUN_00ca9860_cls();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

// Calls FUN_00c876a0 and decrements the global counter DAT_0126830c.
// @fnv 0x00ca9860
FUN_00ca9860_cls::~FUN_00ca9860_cls()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_0126830c;
}


// @fnv 0x00ca9910
void* __cdecl FUN_00ca9910()
{
    return &::g_01268310;
}

struct S_00ca9940_Child
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual unsigned int vfn_20();
};
struct S_00ca9940_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ca9940_Child* m_pChildObject;
};
void __cdecl FUN_00cbd9e0(float f, S_00ca9940_Child* c);

// If o and its child are non-null and f is not 1.0, dispatches on the child's vfn_20 result to call FUN_00cc96b0 or FUN_00cbd9e0 with f.
// @fnv 0x00ca9940
void __cdecl FUN_00ca9940(float afValue, S_00ca9940_Obj* pObj)
{
    S_00ca9940_Child* c;
    if (pObj && (c = pObj->m_pChildObject) != 0 && afValue != 1.0f)
    {
        switch (c->vfn_20())
        {
        case 0:
            ::FUN_00cc96b0(afValue, (::S00cc96b0_ScaleObject *)(pObj->m_pChildObject));
            break;
        case 1: {
            S_00ca9940_Child* p = pObj->m_pChildObject;
            FUN_00cbd9e0(afValue, p);
        }
        break;
        case 2: {
            S_00ca9940_Child* q = pObj->m_pChildObject;
            FUN_00cbd9e0(afValue, q);
        }
        break;
        case 7: {
            S_00ca9940_Child* r = pObj->m_pChildObject;
            FUN_00cbd9e0(afValue, r);
        }
        break;
        }
    }
}

struct FUN_00ca9aa0;
struct State
{
    unsigned int value;
    State() : value(0)
    {}
};
struct BaseOwner
{
    virtual void Act();
    unsigned short unk04;
    unsigned short unk06;
    State unk08;
    BaseOwner() : unk06(1), unk08()
    {}
};
struct InternalPart
{
    unsigned short mode;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    InternalPart() : mode(1)
    {}
    ~InternalPart();
};
struct FUN_00ca9aa0 : BaseOwner
{
    virtual void Act();
    unsigned int unk0c;
    InternalPart part;
    float value;
    FUN_00ca9aa0();
};
// Constructor: initializes unk0c to 0, calls FUN_00d21ce0 on part with command 1, and sets value to 0.01f.
// @fnv 0x00ca9aa0
FUN_00ca9aa0::FUN_00ca9aa0() : BaseOwner(), part()
{
    unk0c = 0;
    reinterpret_cast<::FUN_00d21ce0_cls *>((&part))->FUN_00d21ce0((void *)(1));
    value = 0.01f;
}

namespace fnv_00ca9b10 {
struct FnvCpu_FUN_00ca9b10_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00ca9b10_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ca9b10_CpuAllocator* allocator;
};
struct FnvCpu_FUN_00ca9b10_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00ca9b10_CpuObject* FUN_00ca9b10(unsigned int flags);
};
// Calls FUN_00cdf7a0, then if bit 0 of flags is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00ca9b10
FnvCpu_FUN_00ca9b10_CpuObject* FnvCpu_FUN_00ca9b10_CpuObject::FUN_00ca9b10(unsigned int flags)
{
    reinterpret_cast<::fnv_00cdf7a0::FUN_00cdf7a0Class *>(this)->FUN_00cdf7a0();
    if (flags & 1)
    {
        FnvCpu_FUN_00ca9b10_CpuAllocatorHolder* holder = static_cast<FnvCpu_FUN_00ca9b10_CpuAllocatorHolder*>(::FUN_00c85750());
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00ca9b10

class BCA9D50BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCA9D50BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCA9D50BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCA9D50Stream
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
    BCA9D50BinaryStream* m_pUnderlyingStream;
    BCA9D50BinaryStream* m_pBackingStream;
};

template <class T>
inline void BCA9D50BinaryStreamSave(BCA9D50BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BCA9D50SaveBinary(BCA9D50Stream& kStream, const T& value)
{
    BCA9D50BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BCA9D50Object;


struct BCA9D50Data
{
    int unk00;
    int unk04;
    int unk08;
    BCA9D50Object* m_pPointer;
    int unk10;
    int unk14;
    int unk18;
    float m_fValue;
};

class BCA9D50Base
{
  public:
};

class BCA9D50Wrapper : public BCA9D50Base
{
  public:
    int unk00;
    BCA9D50Data* m_pUserData;

    void FUN_00ca9d50(BCA9D50Stream& kStream);
};

// @fnv 0x00ca9d50
void BCA9D50Wrapper::FUN_00ca9d50(BCA9D50Stream& kStream)
{
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((::S_00c8a280_Stream &)(kStream));
    BCA9D50Data* pkData = m_pUserData;
    ::FUN_00cf4bc0((::CF4BC0Stream &)(kStream), (::CF4BC0Object *)(pkData->m_pPointer));
    BCA9D50SaveBinary(kStream, pkData->m_fValue);
}

namespace fnv_00ca9da0 {
struct TlsBlock_t
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00ca9da0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00ca9da0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00ca9da0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct SlotAllocator
{
    virtual void vSlot00();
    virtual void* vSlot04(unsigned int size);
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual void vSlot10(unsigned int a, unsigned int b);
};

struct AllocHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SlotAllocator* m_pAllocator;
};


struct SpawnedBase
{
    virtual void vSlot00()
    {}
    unsigned short m_size04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    SpawnedBase();
};

struct SpawnedObject : SpawnedBase
{
    SpawnedObject() : SpawnedBase()
    {}
    void* operator new(std::size_t size) throw()
    {
        AllocHolder* holder = static_cast<AllocHolder*>(::FUN_00c85750());
        void* p = holder->m_pAllocator->vSlot04(size);
        ((SpawnedBase*)p)->m_size04 = (unsigned short)size;
        return p;
    }
};

struct FUN_00ca9da0_cls
{
    int unk00;
    SpawnedObject* m_04;
    int EnsureSpawnedObject();
};

// Allocates a SpawnedObject into m_04 if it is null, then returns 0x20.
// @fnv 0x00ca9da0
int FUN_00ca9da0_cls::EnsureSpawnedObject()
{
    TlsGuard_t guard;
    if (this->m_04 == 0)
    {
        SpawnedObject* p = new SpawnedObject();
        this->m_04 = p;
    }
    return 0x20;
}
}  // namespace fnv_00ca9da0

struct FUN_00ca9b40_Obj
{
};

struct FUN_00ca9e50_Obj
{
    int unk00;
    FUN_00ca9b40_Obj* unk04;

    void FUN_00ca9e50(intptr_t value);
};

// @fnv 0x00ca9e50
void FUN_00ca9e50_Obj::FUN_00ca9e50(intptr_t value)
{
    if (this->unk04 != 0)
    {
        reinterpret_cast<::FUN_00ca9b40_class *>((this->unk04))->FUN_00ca9b40((::ObjectRef *)(value));
    }
}

namespace fnv_00ca9f40 {
struct TlsBlock_t
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
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard
{
    int m_saved;
    TlsGuard()
    {
        m_saved = (*reinterpret_cast<::fnv_00ca9f40::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00ca9f40::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard()
    {
        (*reinterpret_cast<::fnv_00ca9f40::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct S_ca9f40_Pool
{
};
struct S_ca9f40_Base
{
    int unk04;
};
struct S_ca9f40_Counters
{
    int* unk00;
    S_ca9f40_Base base;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_ca9f40
{
    int unk00;
    int unk04;
    int unk08;
    S_ca9f40_Base* unk0c;
    S_ca9f40_Base* GetOrCreateBase(bool* created);
};
// Returns unk0c, allocating and initialising a new S_ca9f40_Counters (setting *created) when unk0c is null, then calling CopyFromSource if unk08 is set.
// @fnv 0x00ca9f40
S_ca9f40_Base* S_ca9f40::GetOrCreateBase(bool* created)
{
    TlsGuard guard;
    bool b = (unk0c == 0);
    *created = b;
    if (b)
    {
        S_ca9f40_Counters* c = new S_ca9f40_Counters;
        S_ca9f40_Base* r;
        if (c)
        {
            S_ca9f40_Base* bp = &c->base;
            c->unk08 = 1;
            c->unk0c = 0;
            c->unk10 = 0;
            c->unk00 = &::DAT_010c8288;
            bp->unk04 = 0;
            r = bp;
        }
        else
        {
            r = 0;
        }
        unk0c = r;
        if (unk08)
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((uintptr_t)(unk0c ? reinterpret_cast<S_ca9f40_Counters*>(reinterpret_cast<char*>(unk0c) - offsetof(S_ca9f40_Counters, base)) : 0));
    }
    return unk0c;
}
}  // namespace fnv_00ca9f40


class PolyBase
{
  public:
    virtual ~PolyBase();
};

class FUN_00caa140_cls : public PolyBase
{
  public:
    virtual ~FUN_00caa140_cls();
};

// @fnv 0x00caa140
FUN_00caa140_cls::~FUN_00caa140_cls()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_01268318;
}

void* __cdecl FUN_00aa13e0(size_t size);

struct SpawnedObject20_b9537
{
    char m00[0x14];
    SpawnedObject20_b9537();
};

// Allocates and constructs a SpawnedObject20_b9537 via its custom operator new and returns the pointer.
// @fnv 0x00caae30
SpawnedObject20_b9537* CreateSpawnedObject20()
{
    return new SpawnedObject20_b9537();
}

// Packs four bytes into an unsigned int, shifting in d first, then a, b and c, and returns it.
// @fnv 0x00cabb00
unsigned int __cdecl PackBytesBigEndian(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    unsigned int result = d;
    result = (result << 8) + a;
    result = (result << 8) + b;
    result = (result << 8) + c;
    return result;
}

struct FUN_00cac9a0_Obj
{
};

struct FUN_00cabfd0_Obj
{
    int unk00;
    int unk04;
    FUN_00cac9a0_Obj* unk08;

    void FUN_00cabfd0(intptr_t value);
};

// @fnv 0x00cabfd0
void FUN_00cabfd0_Obj::FUN_00cabfd0(intptr_t value)
{
    if (this != 0 && this->unk08 != 0)
    {
        reinterpret_cast<::hkpCharacterProxy *>((this->unk08))->FUN_00cac9a0((*(::hkpCharacterProxyCinfo *)(value)));
    }
}

struct FUN_00cabff0_res
{
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
};

struct FUN_00cabff0_cls
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
    virtual FUN_00cabff0_res* SlotB4(intptr_t* p);
    void FUN_00cabff0(intptr_t a);
};


// @fnv 0x00cabff0
void FUN_00cabff0_cls::FUN_00cabff0(intptr_t a)
{
    intptr_t b = *(volatile intptr_t*)&a;
    reinterpret_cast<::FUN_00a645b0_cls *>((b))->FUN_00a645b0();
    reinterpret_cast<::FUN_00c87650_t *>(this)->LoadBinary((*(::NiStream *)(b)));
    FUN_00cabff0_res* r = SlotB4(&a);
    r->m_48 = 0;
}

struct S_00cac0b0_Arg
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
    virtual void v0c(int value);
};

struct S_00cac0b0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct S_00cac0b0_Obj
{
    int unk00;
    int unk04;
    S_00cac0b0_Inner* unk08;
};

struct S_00cac0b0_cls
{
    int unk00;
    int unk04;
    S_00cac0b0_Obj* unk08;
    void FUN_00cac0b0(S_00cac0b0_Arg* a);
};

struct FUN_00cac110_Class
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
    virtual void FUN_00cac110();
};

// @fnv 0x00cac110
void FUN_00cac110_Class::FUN_00cac110()
{
    this->FUN_00cac110();
}

namespace fnv_00cac250 {
struct FUN_00cac250_tls
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
    int m_2b4;
};

struct FUN_00cac250_obj
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
    FUN_00cac250_obj();
};

struct TlsGuard_b9283
{
    int m_saved;
    TlsGuard_b9283()
    {
        m_saved = (*reinterpret_cast<::fnv_00cac250::FUN_00cac250_tls *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00cac250::FUN_00cac250_tls *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard_b9283()
    {
        (*reinterpret_cast<::fnv_00cac250::FUN_00cac250_tls *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = m_saved;
    }
};

extern "C" void __cdecl FUN_00c876f0(void);
extern "C" void __cdecl FUN_00c87700(void);

struct FUN_00cac250_cls
{
    FUN_00cac250_obj* CreateObject(intptr_t a1);
};

// @fnv 0x00cac250
FUN_00cac250_obj* FUN_00cac250_cls::CreateObject(intptr_t a1)
{
    TlsGuard_b9283 guard;
    FUN_00cac250_obj* obj = 0;
    FUN_00c876f0();
    obj = new FUN_00cac250_obj();
    reinterpret_cast<::FUN_00c87600_Obj *>(this)->FUN_00c87600(obj, (void *)(a1));
    FUN_00c87700();
    return obj;
}
}  // namespace fnv_00cac250

class CAC680World
{
  public:
};

class CAC680Listener
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void OnUpdate();

    int unk04;
};

class CAC680Object
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
    virtual void Toggle();

    int unk04;
    CAC680World* m_pkWorld;
    int unk0C;
    CAC680Listener m_kListener;

    void ToggleAndUpdate();
};

// Toggles the object, updates m_pkWorld, toggles again, then calls OnUpdate on m_kListener.
// @fnv 0x00cac680
void CAC680Object::ToggleAndUpdate()
{
    Toggle();
    reinterpret_cast<::S_00cac150 *>((m_pkWorld))->ClearItems();
    Toggle();
    m_kListener.OnUpdate();
}

namespace fnv_00cb0ad0 {
struct CB0AD0Allocator;

struct CB0AD0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CB0AD0Allocator* m_pStreamAllocator;
};

char* AllocateWithHeader(CB0AD0Allocator* pkHeap, int iSize);
void CopyIfNonEmpty(char* pcDst, const char* pcSrc, int iCount);

static inline char* CB0AD0AllocateChars(int iCount)
{
    CB0AD0Allocator* pkHeap = (*static_cast<CB0AD0MemoryRouter*>(::FUN_00c85750())).m_pStreamAllocator;
    return AllocateWithHeader(pkHeap, iCount);
}

// @fnv 0x00cb0ad0
static __declspec(noinline) char* FUN_00cb0ad0(const char* pcSrc, int iMaxChars)
{
    int iLen = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(pcSrc));
    if (iLen > iMaxChars)
        iLen = iMaxChars;
    char* pcCopy = CB0AD0AllocateChars(iLen + 1);
    ::CopyIfNonEmpty(pcCopy, pcSrc, iLen);
    pcCopy[iLen] = 0;
    return pcCopy;
}

char* CB0AD0Dup(const char* pcSrc, int iMaxChars)
{
    return FUN_00cb0ad0(pcSrc, iMaxChars);
}
}  // namespace fnv_00cb0ad0

// Rect-like record used by InitRect and its helper.
struct FUN_00cb0ed0_rect
{
    volatile int m_fMinimumU;
    volatile int m_fMinimumV;
    volatile int m_fMaximumU;
    volatile int m_fMaximumV;
    volatile bool m_bValueAt0C;
};


// Resets the rect: clears its flag (calling ResizeBuffer if set), then sets its four bounds from nLeft and nSize.
// @fnv 0x00cb0ed0
void __cdecl InitRect(FUN_00cb0ed0_rect* pRect, int nLeft, int nSize)
{
    if (pRect->m_bValueAt0C)
    {
        ::ResizeBuffer((::SpawnedBuffer *)(pRect), 0);
    }
    pRect->m_bValueAt0C = false;
    pRect->m_fMinimumU = nLeft;
    pRect->m_fMinimumV = nLeft;
    pRect->m_fMaximumU = nLeft + nSize;
    pRect->m_fMaximumV = nLeft + nSize - 0x20;
}

// File-static helper (reconstructed separately at its own address).
static __declspec(noinline) char CB1030ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}

// Exported elsewhere through a function pointer, which keeps the helper's cdecl stack arguments.
char(__cdecl* g_pfnCB1030ToLower)(char) = CB1030ToLower;

// @fnv 0x00cb1030
int __cdecl CompareCaseInsensitive(const char* pcA, const char* pcB, int n)
{
    int i = 0;
    while ((pcA[i] || pcB[i]) && i < n)
    {
        char cA = CB1030ToLower(pcA[i]);
        char cCharB = CB1030ToLower(pcB[i]);
        if (cA < cCharB)
            return -1;
        if (cA > cCharB)
            return 1;
        ++i;
    }
    return 0;
}

// FUN_00cb75d0 : default constructor of the object whose first member holds
// the class table pointer.  The constructor clears three trailing dword
// members, sets a byte flag to 1 and installs the table pointer last.

extern int DAT_010c88b8;

struct FUN_00cb75d0_cls
{
    void* m_pVTable;
    int m_iValue04;
    unsigned char m_bValue08;
    int m_iValue0c;
    int m_iValue10;

    FUN_00cb75d0_cls();
};

// @fnv 0x00cb75d0
FUN_00cb75d0_cls::FUN_00cb75d0_cls()
{
    m_iValue0c = 0;
    m_iValue10 = 0;
    m_iValue04 = 0;
    m_bValue08 = 1;
    m_pVTable = (void*)&DAT_010c88b8;
}

static float DAT_010c8ae4 = 0.016f;

struct S_00cb9770_Foo
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
    virtual float V41(float value);

    int unk04;
    unsigned short unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;
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
    float unk50;

    bool GetActive()
    {
        return ((this->unk08 >> 3) & 1) != 0;
    }
    void UpdateActiveState(float* param);
};

// @fnv 0x00cb9770
void S_00cb9770_Foo::UpdateActiveState(float* pfValue)
{
    this->unk50 = DAT_010c8ae4;

    if (this->GetActive() && this->unk2c != 0)
    {
        if (this->unk20 != ::DAT_010241b0)
        {
            float fDiff = *pfValue - this->unk20;
            this->unk50 = fDiff;
            if (fDiff < 0.0f)
                this->unk50 = DAT_010c8ae4;
        }
        float fResult = this->V41(*pfValue);
        reinterpret_cast<::VelocityController *>((this))->FUN_00cb9290();
        if (fResult == this->unk18)
            this->unk08 &= 0xfff7;
    }
}

struct FUN_00c87c30
{
    void* vtable;
    int unk04;
    int unk08;
    FUN_00c87c30();
};
struct InitializedField
{
    int value;
    InitializedField() : value(0)
    {}
    ~InitializedField();
};
struct FUN_00cb99a0 : FUN_00c87c30
{
    InitializedField unk0c;
    FUN_00cb99a0(char* source);
};
// @fnv 0x00cb9b30
FUN_00cb9b30_class::FUN_00cb9b30_class(intptr_t aiValue)
{
    new ((void *)this) ::FUN_00cb99a0((char *)(aiValue));
    m_vtbl = &DAT_010c8b0c;
    DAT_01268648++;
}
// Sets the vtable, initializes unk0c, calls SpawnAndAttach with source+4 (or null), and increments DAT_01268188.
// @fnv 0x00cb99a0
FUN_00cb99a0::FUN_00cb99a0(char* source) : FUN_00c87c30(), unk0c()
{
    vtable = &DAT_0108febc;
    reinterpret_cast<::Dispatch_00c89dd0 *>(this)->SpawnAndAttach((intptr_t)(source ? source + 4 : 0));
    ++DAT_01268188;
}


struct S_cb9a90_Base
{
    int unk04;
    void* unk08;
    S_cb9a90_Base();
    virtual ~S_cb9a90_Base();
};

struct S_cb9a90_A : S_cb9a90_Base
{
    int unk0c;
    int unk10;
    S_cb9a90_A()
    {
        unk0c = 0;
        unk10 = 0;
        DAT_012680f8++;
    }
};

struct S_cb9a90_B : S_cb9a90_A
{
    S_cb9a90_B()
    {
        DAT_01268274++;
    }
};

struct S_cb9a90_C : S_cb9a90_B
{
    S_cb9a90_C()
    {
        DAT_01268250++;
    }
};

struct FUN_00cb9a90 : S_cb9a90_C
{
    FUN_00cb9a90(intptr_t a, intptr_t b, float c);
    virtual ~FUN_00cb9a90();
};

// Increments DAT_01268324 and forwards the three constructor arguments to FUN_00cab0e0.
// @fnv 0x00cb9a90
FUN_00cb9a90::FUN_00cb9a90(intptr_t aiParam1, intptr_t aiParam2, float afValue)
{
    DAT_01268324++;
    reinterpret_cast<::Owner *>(this)->FUN_00cab0e0(aiParam1, aiParam2, afValue);
}

class GlobalObjectO2_00a7b610;

// @fnv 0x00cb9b50
GlobalObjectO2_00a7b610* __cdecl FUN_00cb9b50()
{
    return &g_0126864c;
}

struct CB9B80Header
{
    int unk00;
};

struct CB9B80BaseInfo
{
    int unk00;
};

struct CB9B80Info : CB9B80Header, CB9B80BaseInfo
{
};

class CB9B80RefObject
{
  public:
    CB9B80RefObject();
    virtual ~CB9B80RefObject();

    int unk04;
    int unk08;
};

class CB9B80SerializableObject : public CB9B80RefObject
{
  public:
    CB9B80SerializableObject() : m_pkWorld(0)
    {}

    void* m_pkWorld;
};

class CB9B80WorldObject : public CB9B80SerializableObject
{
  public:
    CB9B80WorldObject()
    {
        ++(*reinterpret_cast<unsigned int *>(&::DAT_01268188));
    }
    virtual ~CB9B80WorldObject();

};

class FUN_00cb9b80 : public CB9B80WorldObject
{
  public:
    FUN_00cb9b80(CB9B80Info* pkInfo);
    virtual ~FUN_00cb9b80();

    void Init(CB9B80BaseInfo* pkInfo);

};

// Initializes the object from pkInfo and increments the static instance count.
// @fnv 0x00cb9b80
FUN_00cb9b80::FUN_00cb9b80(CB9B80Info* pkInfo)
{
    reinterpret_cast<::Dispatch_00c89dd0 *>(this)->SpawnAndAttach((intptr_t)(pkInfo));
    ++(*reinterpret_cast<unsigned int *>(&::DAT_0126860c));
}

struct CpuOpaque;
// @fnv 0x00cb9c00
CpuOpaque* __cdecl FUN_00cb9c00()
{
    return &(*reinterpret_cast<::CpuOpaque *>(&::g_01268610));
}

class FUN_00cb9c70_item
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
    virtual void v21(intptr_t a1);
};

class FUN_00cb9c70_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb9c70_item** m_ppItems;
    unsigned int m_uiCount;
    bool FUN_00cb9c70(intptr_t a1);
};

// Calls Check(a1); if it returns true, calls v21(a1) on each of the m_uiCount items in m_ppItems and returns the Check result.
// @fnv 0x00cb9c70
bool FUN_00cb9c70_cls::FUN_00cb9c70(intptr_t aiValue)
{
    bool result = reinterpret_cast<::MyOwner *>(this)->FUN_00a7b290((*(::NiStream *)(aiValue)));
    if (result)
    {
        unsigned int count = m_uiCount;
        for (unsigned int i = 0; i < count; i++)
        {
            m_ppItems[i]->v21(aiValue);
        }
    }
    return result;
}

namespace fnv_00cb9cb0 {
struct S_00aa4060_Class
{
};


// @fnv 0x00cb9cb0
void __cdecl FUN_00cb9cb0()
{
    reinterpret_cast<::FNV_MemoryManager *>((((S_00aa4060_Class*)&(*reinterpret_cast<int *>(&::g_memoryManager)))))->FUN_00aa4060({});
}
}  // namespace fnv_00cb9cb0

struct RefCountedStandIn
{
    virtual void Unk0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

struct ArgStandIn
{
};

class FUN_00cb9ee0_cls
{
  public:
    void AssignRefCountedArray(ArgStandIn* arg);

    char unk00[0x10];
    RefCountedStandIn** m_10;
    unsigned int m_14;
};

// Calls FUN_00a7b3b0, then for each of m_14 slots swaps in arg->FUN_00a63430(), releasing the old ref and retaining the new one.
// @fnv 0x00cb9ee0
void FUN_00cb9ee0_cls::AssignRefCountedArray(ArgStandIn* arg)
{
    reinterpret_cast<::NiExtraData *>(this)->LinkObject((*(::NiStream *)(arg)));
    for (unsigned int i = 0; i < m_14; i++)
    {
        RefCountedStandIn** slot = &m_10[i];
        RefCountedStandIn* pNew = ((::RefCountedStandIn *)(reinterpret_cast<::NiStream *>((arg))->GetLoadedObject()));
        RefCountedStandIn* old = *slot;
        if (old != pNew)
        {
            if (old != 0)
            {
                if (InterlockedDecrement(&old->m_uiRefCount) == 0)
                {
                    old->DeleteThis();
                }
            }
            *slot = pNew;
            if (pNew != 0)
            {
                InterlockedIncrement(&pNew->m_uiRefCount);
            }
        }
    }
}

class BCB9F60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCB9F60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCB9F60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCB9F60Stream
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
    virtual void SaveLinkID(void* pkObject);

  public:
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
    BCB9F60BinaryStream* m_pUnderlyingStream;
    BCB9F60BinaryStream* m_pBackingStream;
};

template <class T>
inline void BCB9F60BinaryStreamSave(BCB9F60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BCB9F60SaveBinary(BCB9F60Stream& kStream, const T& value)
{
    BCB9F60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BCB9F60ExtraData
{
  public:
};

class BCB9F60LinkData : public BCB9F60ExtraData
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void** m_ppkObjects;
    unsigned int m_uiCount;

    void FUN_00cb9f60(BCB9F60Stream& kStream);
};

// Saves the base extra data, writes m_uiCount, then saves each link ID from m_ppkObjects.
// @fnv 0x00cb9f60
void BCB9F60LinkData::FUN_00cb9f60(BCB9F60Stream& kStream)
{
    reinterpret_cast<::FUN_00a7b2c0_shell *>(this)->FUN_00a7b2c0((::NiStream &)(kStream));
    unsigned int ItemUpdateArray = m_uiCount;
    BCB9F60SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        kStream.SaveLinkID(m_ppkObjects[i]);
}

// Releases the resource held by the object and resets it to its empty state.
typedef void(* FreeFn)(void*);

struct FUN_00cb9fd0_cls
{
    void* m_ppVirtualMethodTable;
    void* m_pData;
    int m_i08;
    int m_i0c;
    void ResetAndFreeData();
};

// Sets the first pointer to DAT_010c8d00 and, if m_pData is non-null, frees it via DAT_010c8d08 and clears m_pData, m_i0c and m_i08.
// @fnv 0x00cb9fd0
void FUN_00cb9fd0_cls::ResetAndFreeData()
{
    void* pData = m_pData;
    m_ppVirtualMethodTable = (void*)&DAT_010c8d00;
    if (pData != 0)
    {
        FreeFn pFree = (FreeFn)DAT_010c8d08;
        pFree(pData);
        m_pData = 0;
        m_i0c = 0;
        m_i08 = 0;
    }
}

class FUN_00cba0d0_cls
{
  public:
    virtual void v0();
    virtual void v1();
    long m_04;
};

// For each of count items, decrements the reference count and calls v1() when it reaches zero.
// @fnv 0x00cba0d0
void ReleaseItems(FUN_00cba0d0_cls** items, uintptr_t count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        FUN_00cba0d0_cls* p = items[i];
        if (p != 0 && InterlockedDecrement(&p->m_04) == 0)
        {
            p->v1();
        }
    }
}


class CBaseOwner
{
  public:
    virtual void unk00();
    unsigned int unk04;
    CBaseOwner();
    ~CBaseOwner();
};

class CSlot08
{
  public:
    void* p;
    CSlot08(void* v)
    {
        p = v;
    }
    ~CSlot08();
};

class CSubA
{
  public:
    virtual void unkA00();
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0c;
    CSubA()
    {
        unkA04 = 0;
        unkA08 = 0;
        unkA0c = 0;
    }
    ~CSubA();
};

class CSubB
{
  public:
    virtual void unkB00();
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0c;
    CSubB()
    {
        unkB04 = 0;
        unkB08 = 0;
        unkB0c = 0;
    }
    ~CSubB();
};

class FUN_00cba110 : public CBaseOwner
{
  public:
    CSlot08 m_08;
    CSubA m_0c;
    CSubB m_1c;
    FUN_00cba110();
};

// @fnv 0x00cba110
FUN_00cba110::FUN_00cba110() : m_08((*reinterpret_cast<void * *>(&::DAT_0109b220)))
{
    void* p = m_08.p;
    if (p != 0)
    {
        m_08.p = ((void *)(::NiGlobalStringTable::AddString((const char *)(0))));
        if (p != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
        {
            InterlockedDecrement(&GetGlobalStringHeader(p)->m_lRefCount);
        }
    }
}


// @fnv 0x00cba1c0
void* __cdecl FUN_00cba1c0()
{
    return &(*reinterpret_cast<int *>(&::g_01268400));
}


// @fnv 0x00cbbfb0
void FUN_00cbbfb0(uintptr_t a1)
{
    DAT_01268418 = a1;
}

namespace fnv_00cbc5e0 {
extern "C" void* __cdecl FUN_00aa13e0(size_t);

struct FUN_00cbc550
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    FUN_00cbc550();
};
// Allocates and constructs a new FUN_00cbc550 object, returning its pointer.
// @fnv 0x00cbc5e0
FUN_00cbc550* __cdecl CreateFUN_00cbc550()
{
    return new FUN_00cbc550;
}
}  // namespace fnv_00cbc5e0

namespace fnv_00cbc7b0 {
struct FUN_00aa3e40_class
{
};


struct FUN_00cbc7b0_cls
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void PushItem(void** pItem);
};

// @fnv 0x00cbc7b0
void FUN_00cbc7b0_cls::PushItem(void** pItem)
{
    void* item = *pItem;
    if (item)
    {
        if (m_iWordAt00)
        {
            void** n = (void**)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00cbc7b0::FUN_00aa3e40_class *>(&::g_memoryManager))))->FUN_00aa3e40(8);
            if (n)
            {
                n[0] = m_iWordAt00;
                n[1] = 0;
            }
            else
            {
                n = 0;
            }
            n[1] = m_iWordAt04;
            m_iWordAt04 = n;
            item = *pItem;
        }
        m_iWordAt00 = item;
    }
}
}  // namespace fnv_00cbc7b0

// FUN_00cbd960 registers the 0x00cbd7a0 comparison helper in the global
// callback slot at 0x01268430, which is later called indirectly with two
// arguments (see the indirect call through 0x01268430).

void __cdecl InsertIntoContext(void* pList, void* pContext);

// @fnv 0x00cbd960
void __cdecl FUN_00cbd960(void)
{
    DAT_01268430 = &InsertIntoContext;
}


struct PrimaryBase
{
    virtual ~PrimaryBase();
};

struct HolderBase
{
    void Release();
};

struct FUN_00cbd970 : PrimaryBase
{
    int unk04;
    virtual ~FUN_00cbd970();
};

// Releases the holder and decrements the global counter DAT_01268434.
// @fnv 0x00cbd970
FUN_00cbd970::~FUN_00cbd970()
{
    reinterpret_cast<::ProjectileListener *>((((HolderBase*)this)))->FUN_00c876a0();
    DAT_01268434--;
}

namespace fnv_00cbdcb0 {
struct CBDCB0Allocator
{
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct CBDCB0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBDCB0Allocator* m_pStreamAllocator;

    CBDCB0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};



struct CBDCB0AllocTagScope
{
    int m_iSaved;

    CBDCB0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CBDCB0AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class CBDCB0Child
{
  public:
    CBDCB0Child();
    virtual ~CBDCB0Child();

    static void* operator new(std::size_t uiSize)
    {
        void* p = (*static_cast<CBDCB0MemoryRouter*>(::FUN_00c85750())).heap().AllocateMemoryBlock(uiSize);
        static_cast<CBDCB0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

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
};

class CBDCB0Owner
{
  public:
    int unk00;
    CBDCB0Child* m_pkChild;

    int EnsureChild();
};

// Creates m_pkChild with a new CBDCB0Child if it is null, then returns sizeof(CBDCB0Child).
// @fnv 0x00cbdcb0
int CBDCB0Owner::EnsureChild()
{
    CBDCB0AllocTagScope kScope(0x10);
    if (!m_pkChild)
        m_pkChild = new CBDCB0Child();
    return sizeof(CBDCB0Child);
}
}  // namespace fnv_00cbdcb0

struct WriteStream
{
    void* unk00;
    unsigned int transferred;
    void* unk08;
    int(__cdecl* write)(WriteStream*, const void*, unsigned int, unsigned int*, int);
};
struct BufferOwner
{
    void* unk00;
    unsigned char* buffer;
    void WriteToStream(void*);
};
// Calls FUN_00c8a280 on source, then writes two 64-byte blocks from buffer+0x20 and buffer+0x60 to the stream at source+0x250, accumulating transferred bytes.
// @fnv 0x00cbdf10
void BufferOwner::WriteToStream(void* source)
{
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((*(::S_00c8a280_Stream *)(source)));
    unsigned char* data = buffer;
    WriteStream* __restrict stream = static_cast<WriteStream*>(static_cast<NiStreamFields*>(source)->m_pkStream);
    unsigned int length = 64;
    stream->transferred += stream->write(stream, data + 0x20, 64, &length, 1);
    stream = static_cast<WriteStream*>(static_cast<NiStreamFields*>(source)->m_pkStream);
    length = 64;
    stream->transferred += stream->write(stream, data + 0x60, 64, &length, 1);
}

extern "C" void _ReadWriteBarrier(void);

struct FUN_00cbe820_sub
{
    void Init(float* value);
};

struct FUN_00cbe820_cls
{
    short m_00;
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
    int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c, m_80, m_84, m_88, m_8c;
    short m_90;
    short m_92;
    short m_94;
    unsigned char m_96;
    FUN_00cbe820_sub m_97;
    float m_98;

    FUN_00cbe820_cls* FUN_00cbe820();
};

// Initialises the object: sets m_00 to 2, m_90 to 0xc, m_94 to 5, m_96 to 0, calls m_97.Init with 1.0f, sets m_98 to DAT_0104da48, and returns this.
// @fnv 0x00cbe820
FUN_00cbe820_cls* FUN_00cbe820_cls::FUN_00cbe820()
{
    float one = 1.0f;
    *(volatile short*)&m_00 = 2;
    _ReadWriteBarrier();
    *(volatile short*)&m_90 = 0xc;
    _ReadWriteBarrier();
    float* pOne = &one;
    m_94 = 5;
    m_96 = 0;
    reinterpret_cast<::FUN_00ca9360_cls *>(&(m_97))->FUN_00ca9360(pOne);
    m_98 = ::DAT_0104da48;
    return this;
}

struct FUN_00cbe880_Class
{
    void* m_iWordAt00;
    void FUN_00cbe880();
};

extern "C" void __cdecl FUN_00c9eec0();

// @fnv 0x00cbe880
void FUN_00cbe880_Class::FUN_00cbe880()
{
    this->m_iWordAt00 = fnv_vftable_FUN_00c6d1e0;
    FUN_00c9eec0();
}

struct FUN_00c68e30_cls
{
};
struct FUN_00cbe890_cls
{
    int m_auiShapeKeys[7];
    unsigned char m_1c;
    unsigned char FUN_00cbe890(void* a);
};
// @fnv 0x00cbe890
unsigned char FUN_00cbe890_cls::FUN_00cbe890(void* a)
{
    unsigned char r = 0;
    if (m_1c == 0)
    {
        unsigned char b = ((unsigned char)(reinterpret_cast<::Obj *>((a))->FUN_00c85810({})));
        if (b)
        {
            unsigned int color = ::PackBytesBigEndian(0x1e, 0x82, 0, 0x14);
            reinterpret_cast<::C68E30Owner *>((((FUN_00c68e30_cls*)a)))->FUN_00c68e30((::C68E30Holder *)(void *)(this), (int)(color));
        }
        r = b;
    }
    return r;
}

namespace fnv_00cbf2d0 {
// FUN_00cbf2d0 : cdecl one-arg entry point.  When the argument is non null the
// game allocator is fetched from the global allocator holder and its virtual
// slot 2 is asked to release/store the block with a fixed 0x1c0 byte size.

struct AllocClass
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, unsigned int size);
};

struct HolderClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocClass* m_pAllocator;
};


// If p is non-null, gets the holder from FUN_00c85750 and calls its allocator's v2 with p and size 0x1c0.
// @fnv 0x00cbf2d0
void __cdecl FUN_00cbf2d0(void* p)
{
    if (p)
    {
        HolderClass* holder = static_cast<HolderClass*>(::FUN_00c85750());
        AllocClass* allocator = holder->m_pAllocator;
        allocator->v2(p, 0x1c0);
    }
}
}  // namespace fnv_00cbf2d0

namespace fnv_00cbf2f0 {
__declspec(thread) int fnvThreadMemoryBase;
__forceinline int& threadMemoryMode()
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(&(*reinterpret_cast<int *>(&::g_tlsBlock))) + 0x2b4);
}
struct MemoryContextScope
{
    int savedMode;
    __forceinline explicit MemoryContextScope(int n)
    {
        savedMode = threadMemoryMode();
        threadMemoryMode() = n;
    }
    __forceinline ~MemoryContextScope()
    {
        threadMemoryMode() = savedMode;
    }
};
struct ResourceOne
{
};
struct ResourceTwo
{
};
struct ResourceDisposer
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void dispose(ResourceOne*, int);
};
struct ResourceService
{
    int unk00, unk04, unk08, unk0c;
    ResourceDisposer* disposer;
};
struct FUN_00cbf2f0_class
{
    int unk00, unk04, unk08;
    int active;
    int unk10;
    ResourceOne* first;
    ResourceTwo* second;
    void FUN_00cbf2f0();
};
// @fnv 0x00cbf2f0
void FUN_00cbf2f0_class::FUN_00cbf2f0()
{
    MemoryContextScope m_uiMemoryContext(0x10);
    if (active != 0)
    {
        ResourceOne* owned = first;
        if (owned != 0)
        {
            reinterpret_cast<::fnv_00d055c0::S_00d055c0_Obj *>((owned))->FUN_00d055c0();
            ResourceService* s = static_cast<ResourceService*>(::FUN_00c85750());
            ResourceDisposer* p = s->disposer;
            p->dispose(owned, 0x1c0);
        }
        first = 0;
        if (second != 0)
            reinterpret_cast<::hkReferencedObjectC905 *>((second))->FUN_00c905b0();
        second = 0;
    }
    active = 0;
}
}  // namespace fnv_00cbf2f0

namespace fnv_00cbf3c0 {
struct SpawnedAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedAllocator* m_pAllocator;
};


struct FUN_00cbf3c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pData;
    int m_14;
    unsigned int m_18;

    void FreeData();
};

// @fnv 0x00cbf3c0
void FUN_00cbf3c0_cls::FreeData()
{
    AllocHolder* holder = static_cast<AllocHolder*>(::FUN_00c85750());
    SpawnedAllocator* alloc = holder->m_pAllocator;
    unsigned int flags = m_18;
    m_14 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(m_pData, (flags & 0x3fffffffu) * 4);
    }
    m_pData = 0;
    m_18 = 0x80000000u;
}
}  // namespace fnv_00cbf3c0

// Release the per-body lists: destroy every inner array, then free the outer array.

struct CBF490Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct CBF490MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBF490Allocator* m_pStreamAllocator;

    CBF490Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CBF490MemoryRouter& __cdecl CBF490GetMemoryRouter() throw();

template <class T> inline void CBF490Deallocate(CBF490Allocator& alloc, T* p, int numElem)
{
    alloc.ReturnMemory(p, numElem * sizeof(T));
}

template <class T> __forceinline void CBF490Destruct(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}

template <class T> struct CBF490Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~CBF490Array() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline void ClearAndRelease() throw()
    {
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        CBF490Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            CBF490Deallocate(alloc, m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class CBF490Lists
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CBF490Array<CBF490Array<int> > m_kLists;

    void ClearLists();
};

// Clears the m_kLists array by destroying its elements and releasing its storage.
// @fnv 0x00cbf490
void CBF490Lists::ClearLists()
{
    m_kLists.ClearAndRelease();
}

class hkBool
{
  public:
    hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

class CBFC60Dispatcher
{
  public:
};


// @fnv 0x00cbfc60
void __cdecl FUN_00cbfc60(CBFC60Dispatcher* pkDispatcher)
{
    ::FUN_00d36c60(pkDispatcher);
    reinterpret_cast<::FUN_00cfb1e0 *>((pkDispatcher))->Set((*(bool *)&(const ::hkBool &)(false)));
    ::FUN_00d367d0((::hkpCollisionDispatcherD367 *)(pkDispatcher));
    ::FUN_00d362c0((::D362Script *)(pkDispatcher));
    reinterpret_cast<::FUN_00cfb1e0 *>((pkDispatcher))->Set((*(bool *)&(const ::hkBool &)(true)));
    ::RegisterConvexListAgentCollisionFuncs((::hkpConvexListAgent *)(pkDispatcher));
    ::RegisterAgent3Entries((::hkpCollisionDispatcherD331 *)(pkDispatcher));
    ::FUN_00d321e0((::S_00d321e0_Dispatcher *)(pkDispatcher));
}

struct TypedObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetKind();
};

struct PropHolder
{
    int unk00;
    int unk04;
    int unk08;
    TypedObj* pObj;
};

struct PassEntry
{
    PropHolder* pHolder;
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

struct ShaderData
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
    PassEntry* pPasses;
    unsigned short usPassCount;
    unsigned short unkb2;
    PropHolder** ppExtra;
    int iExtraCount;
};

struct ShaderProp
{
    int unk00;
    int unk04;
    ShaderData* pData;
};

struct CastResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShaderProp* pShader;
};

struct RttiObject
{
};


struct GeomNode;

struct ChildNode
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
    GeomNode** ppChildren;
    unsigned short unka4;
    unsigned short usChildCount;
};

struct GeomNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ChildNode* GetAsNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RttiObject* pProp;
};

struct GeomArray
{
    virtual void v00();
    virtual GeomNode** Allocate(unsigned int count);
    GeomNode** pData;
    unsigned int uiSize;
    unsigned int uiCapacity;

    __forceinline void Add(GeomNode* p)
    {
        if (uiSize == uiCapacity)
        {
            if (uiCapacity == 0)
            {
                pData = Allocate(4);
                uiCapacity = 4;
            }
            else
            {
                unsigned int newCap = uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2;
                reinterpret_cast<::FUN_0042fc00_shell *>(this)->FUN_0042fc00((void *)(uintptr_t)(newCap), uiSize);
                uiCapacity = newCap;
            }
        }
        pData[++uiSize - 1] = p;
    }
};

struct GeomCollector
{
    void CollectShaderNodes(GeomNode* pObj, GeomArray* pArray);
};

// Recursively collects GeomNodes whose shader has all passes of kind 11 and at least one extra of another kind into pArray, then descends into child nodes.
// @fnv 0x00ca0f00
void GeomCollector::CollectShaderNodes(GeomNode* pObj, GeomArray* pArray)
{
    if (!pObj)
        return;
    if (pObj->pProp)
    {
        CastResult* pCastResult = ((::CastResult *)(reinterpret_cast<::NiObject *>((pObj->pProp))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const int *>(&::g_012043f8))))));
        if (pCastResult && pCastResult->pShader)
        {
            ShaderData* pData = pCastResult->pShader->pData;
            if (pData)
            {
                bool bAllPassesKind11 = true;
                for (int i = 0; i < pData->usPassCount; i++)
                {
                    if (!bAllPassesKind11)
                        break;
                    TypedObj* pPassObj = pData->pPasses[i].pHolder->pObj;
                    bAllPassesKind11 = pPassObj->GetKind() == 11;
                }
                bool bAnyExtraOtherKind = false;
                for (int j = 0; j < pData->iExtraCount; j++)
                {
                    if (bAnyExtraOtherKind)
                        break;
                    bAnyExtraOtherKind = pData->ppExtra[j]->pObj->GetKind() != 11;
                }
                if (bAllPassesKind11 && bAnyExtraOtherKind)
                    pArray->Add(pObj);
            }
        }
    }
    ChildNode* pChildNode = pObj->GetAsNode();
    if (pChildNode)
    {
        for (unsigned int k = 0; k < pChildNode->usChildCount; k++)
            CollectShaderNodes(pChildNode->ppChildren[k], pArray);
    }
}

class NiRefObjectCA3
{
  public:
    virtual ~NiRefObjectCA3();
    virtual void DeleteThis();

    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerCA3
{
  public:
    ~NiPointerCA3()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerCA3& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }

    T* m_pObject;
};
class PrimaryCA3
{
  public:
    virtual ~PrimaryCA3()
    {}

    int unk04, unk08, unk0C;
};
class SecondaryCA3
{
  public:
    virtual ~SecondaryCA3()
    {}
};
class BaseCA3 : public PrimaryCA3, public SecondaryCA3
{
  public:
    virtual ~BaseCA3()
    {}

    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    int unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80;
};
class FUN_00ca3b90 : public BaseCA3
{
  public:
    virtual ~FUN_00ca3b90();

    NiPointerCA3<NiRefObjectCA3> m_pReferencedObject;
};
// Destructor that releases the held reference by assigning null to the NiPointer, decrementing the object's ref count.
// @fnv 0x00ca3b90
FUN_00ca3b90::~FUN_00ca3b90()
{
    m_pReferencedObject = 0;
}
// The pack prelude keeps only the declaration of this file-static helper (used by a
// neighbouring function's function-pointer table); provide its body so the unit links.

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct RefCounted
{
    virtual ~RefCounted();
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

struct PtrEntry
{
    NiPointer<RefCounted> m_pReferencedObject;
    int m_iValue;
    PtrEntry() : m_pReferencedObject(0), m_iValue(0)
    {}
    bool operator==(const PtrEntry& other) const
    {
        return m_pReferencedObject == other.m_pReferencedObject && m_iValue == other.m_iValue;
    }
    bool operator!=(const PtrEntry& other) const
    {
        return !(*this == other);
    }
};

struct PtrEntryArray
{
    virtual ~PtrEntryArray();
    PtrEntry* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};
// Copies m_90 into the arg's m_04, resets and fills its m_08 sub-list from m_98 entries, and attaches m_80 to its m_20 sub-object.
// @fnv 0x00ca4d20
void FUN_00ca4d20_cls::CopyEntriesToArg(FNVArg* apArg)
{
    FNVSub2* s = &apArg->m_08;
    apArg->m_04 = m_90;
    reinterpret_cast<::RecordArray *>((s))->ClearRecords();
    reinterpret_cast<::S004b4db0_Quaternion *>(&(apArg->m_20))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(&m_80)));
    for (int i = 0; i < m_a0; ++i)
    {
        FNVEntry* e = &m_98[i];
        unsigned int idx = s->m_0c;
        if (idx >= s->m_08)
        {
            reinterpret_cast<::PtrEntryArray *>((s))->Resize(s->m_14 + idx);
        }
        reinterpret_cast<::S_00ca49a0_Array *>((s))->FUN_00ca49a0(idx, (*(const ::S_00ca49a0_Elem *)(e)));
    }
}

// Resizes the array to uiMaxSize: clears and shrinks the size if smaller, reallocates the buffer, copies existing entries and default-initialises the rest.
// @fnv 0x00ca47f0
void PtrEntryArray::Resize(unsigned int uiNewMaxSize)
{
    if (uiNewMaxSize == m_uiMaxSize)
        return;

    unsigned int i;
    if (uiNewMaxSize < m_uiSize)
    {
        for (i = uiNewMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != PtrEntry())
            {
                m_pBase[i] = PtrEntry();
                m_uiESize--;
            }
        }
        m_uiSize = uiNewMaxSize;
    }

    PtrEntry* pOldEntries = m_pBase;
    m_uiMaxSize = uiNewMaxSize;
    if (uiNewMaxSize > 0)
    {
        m_pBase = (PtrEntry*)NiMalloc(sizeof(PtrEntry) * m_uiMaxSize);
        for (i = 0; i < m_uiSize; i++)
            reinterpret_cast<::FUN_00ca47a0_Class *>((void *)&(const ::PtrEntry &)(m_pBase[i]))->AssignFrom((::FUN_00ca47a0_Class *)&(pOldEntries[i]));
        for (i = m_uiSize; i < m_uiMaxSize; i++)
            m_pBase[i] = PtrEntry();
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pOldEntries);
}

// Prelude helper whose body the unit prelude omits.
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
struct CA56B0AllocTagScope
{
    int m_iSaved;

    CA56B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CA56B0AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};
void CA56B0Lock();
void CA56B0Unlock();
class CA56B0RefObject
{
  public:
    CA56B0RefObject();
    virtual ~CA56B0RefObject();


    int unk04;
    int unk08;
};
class CA56B0Shape : public CA56B0RefObject
{
  public:
    CA56B0Shape() : m_pUserData(0), m_pkExtra(0)
    {
        ++::DAT_012680f8;
    }
    virtual ~CA56B0Shape();

    void* m_pUserData;
    void* m_pkExtra;

};
class CA56B0MidShape : public CA56B0Shape
{
  public:
    CA56B0MidShape()
    {
        ++::DAT_012686d0;
    }
    virtual ~CA56B0MidShape();

};
class CA56B0ListShape : public CA56B0MidShape
{
  public:
    CA56B0ListShape()
    {
        ++::DAT_012682d8;
    }
    virtual ~CA56B0ListShape();

};
class CA56B0Owner
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void AddShape(CA56B0Shape* pkShape, int iIndex);

    CA56B0Shape* CreateListShape(int iIndex);
};
// Allocates a CA56B0ListShape under an alloc tag and lock, adds it to the owner at iIndex, unlocks, and returns the shape.
// @fnv 0x00ca56b0
CA56B0Shape* CA56B0Owner::CreateListShape(int iIndex)
{
    CA56B0AllocTagScope kScope(0x10);
    CA56B0Lock();
    CA56B0Shape* pkShape = new CA56B0ListShape;
    AddShape(pkShape, iIndex);
    CA56B0Unlock();
    return pkShape;
}

struct ReadBin
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(ReadBin*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        position += read(this, data, bytes, sizes, n);
    }
};
template <class T> inline void Load(ReadBin& bin, T* data, unsigned int n)
{
    unsigned int size = sizeof(T);
    bin.Read(data, n * sizeof(T), &size, 1);
}
struct ReadStream
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
    ReadBin* binary;
};
struct ReadData
{
    int unk00, unk04;
    int value08;
    int unk0c;
    float vector10[4];
};
struct CA5940
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
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual ReadData* GetData(char* out);
    void ReadDataFromStream(ReadStream* stream);
};
// Reads a value and a 4-float vector from the stream into the object's ReadData, then calls FUN_00a645b0.
// @fnv 0x00ca5940
void CA5940::ReadDataFromStream(ReadStream* stream)
{
    char temporary;
    ReadData* data = GetData(&temporary);
    reinterpret_cast<::FUN_00c84d00_cls *>(this)->FUN_00c84d00((::FUN_00c84d00_obj *)(stream));
    Load(*stream->binary, &data->value08, 1);
    unsigned int size2 = 4;
    stream->binary->Read(data->vector10, 16, &size2, 1);
    reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
}

struct CA6E60AllocTagScope
{
    int m_iSaved;

    CA6E60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CA6E60AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};
class CA6E60Buffer
{
  public:
    virtual ~CA6E60Buffer()
    {
        NiFreeAlias(m_pResource);
    }

    void* m_pResource;
};
class CA6E60Data
{
  public:
    static void operator delete(void* pvMem)
    {
        unsigned char ucOffset = GetAlignedBlockPrefix(pvMem)->m_ucOffset;
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(static_cast<char*>(pvMem) - ucOffset);
    }

    int unk00;
    int unk04;
    CA6E60Buffer m_kBuffer;
};
class CA6E60Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CA6E60Data* m_pUserData;

    void ReleaseData(bool bRelease);
};
// Sets the thread-local allocation tag to 0x10 and, when bRelease is true, deletes the owned data object and clears the pointer.
// @fnv 0x00ca6e60
void CA6E60Owner::ReleaseData(bool bRelease)
{
    CA6E60AllocTagScope kScope(0x10);
    if (bRelease)
    {
        delete m_pUserData;
        m_pUserData = 0;
    }
}

struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    void AppendReference(char*& value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};
struct PartFlags
{
    void* vtable;
    int references;
    int unk08;
    unsigned short flags;
};
struct PartValue
{
    int value;
};
struct DiagnosticShape : S_00ca6810_Class
{
    void AppendSubpartDiagnostics(StrArr* output);
    unsigned int Count() const
    {
        return this && unk08 ? (unsigned int)unk08->unkA0 : 0;
    }
    S_00ca6810_Entry& Part(unsigned int index) const
    {
        if (this && unk08)
            return unk08->unk98[index];
        return *reinterpret_cast<S_00ca6810_Entry*>(&DAT_012682f0);
    }
};
// Appends a name, a Subparts count, then MATERIAL and value entries for up to the first 5 parts and the last 3 parts when the count exceeds 5.
// @fnv 0x00ca6f10
void DiagnosticShape::AppendSubpartDiagnostics(StrArr* output)
{
    unsigned int count;
    TlsGuard_t guard;
    reinterpret_cast<::fnv_00cd2fd0::Object *>(this)->FUN_00cd2fd0((::fnv_00cd2fd0::StrArr *)(output));
    {
        char* name = ::FUN_00a7d330((*reinterpret_cast<char * *>(&::g_012682e8)));
        output->AppendReference(name);
    }
    unsigned int leadingCount = Count();
    count = leadingCount;
    {
        char* countText = FUN_00a7d510("Subparts", count);
        output->AppendReference(countText);
    }
    unsigned int trailingCount = 0;
    if (leadingCount > 5)
    {
        leadingCount = 5;
        trailingCount = count - leadingCount;
        if (trailingCount > 3)
            trailingCount = 3;
    }
    for (unsigned int index = 0; index < leadingCount; ++index)
    {
        output->Append(FUN_00a7d510("Part", index));
        S_00ca6810_Entry& part = Part(index);
        PartFlags* flags = reinterpret_cast<PartFlags*>(part.callable);
        output->Append(FUN_00a7d4d0("MATERIAL", flags ? (flags->flags >> 6) & 31 : 0));
        PartValue value;
        value.value = part.unk04;
        reinterpret_cast<::HavokFilterInfo *>(&(value))->AppendToViewerStrings((::ViewerStrings *)(output));
    }
    for (unsigned int index = 0; index < trailingCount; ++index)
    {
        unsigned int partIndex = count - index - 1;
        output->Append(FUN_00a7d510("Part", partIndex));
        S_00ca6810_Entry& part = Part(partIndex);
        PartFlags* flags = reinterpret_cast<PartFlags*>(part.callable);
        output->Append(FUN_00a7d4d0("MATERIAL", flags ? (flags->flags >> 6) & 31 : 0));
        PartValue value;
        value.value = part.unk04;
        reinterpret_cast<::HavokFilterInfo *>(&(value))->AppendToViewerStrings((::ViewerStrings *)(output));
    }
}

struct LockFlag_t
{
    bool m_kPointB;
    LockFlag_t(bool b) : m_kPointB(b)
    {}
    LockFlag_t(const LockFlag_t& o) : m_kPointB(o.m_kPointB)
    {}
};

struct WorldLock_t
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Mark(unsigned int id, LockFlag_t flag);
};

struct CAC300Allocator
{
    virtual void fn00();
    virtual void* Alloc(unsigned int size);
};

struct hkReferencedObject
{
    void* vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
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

    hkReferencedObject(intptr_t arg);

    static void* operator new(std::size_t size)
    {
        FNVTaskMemoryRouter* router = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
        hkReferencedObject* p = (hkReferencedObject*)((CAC300Allocator*)router->allocator)->Alloc(size);
        p->m_usMemSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};

struct CAC300Owner
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
    virtual void SetObject(hkReferencedObject* obj);
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
    virtual void Apply(intptr_t arg);

    void FUN_00cac300(intptr_t arg);
};

// Marks the world lock, allocates an hkReferencedObject with arg, hands it to SetObject, releases it, then calls Apply(arg).
// @fnv 0x00cac300
void CAC300Owner::FUN_00cac300(intptr_t arg)
{
    TlsGuard_t guard;
    WorldLock_t* lock = (*reinterpret_cast<::WorldLock_t * *>(&::DAT_01268360));
    lock->Mark(0x6cee9071, LockFlag_t(false));
    hkReferencedObject* obj = new hkReferencedObject(arg);
    lock->Mark(0x6cee9071, LockFlag_t(true));
    SetObject(obj);
    reinterpret_cast<::hkReferencedObjectC905 *>((obj))->FUN_00c905b0();
    Apply(arg);
}

// Prelude helper whose body the unit prelude omits.
// Factory: create a new 0x40-byte object.
class BA2D0Object
{
  public:
    BA2D0Object();


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
};
// Allocates and constructs a new BA2D0Object, returning the pointer.
// @fnv 0x00cba2d0
BA2D0Object* CreateBA2D0Object()
{
    return new BA2D0Object;
}

// Prelude helper whose body the unit prelude omits.
// NiTMap destructor: remove all entries, then the base map frees its hash table.
void __cdecl CBC740NiFree(void* pvMem);
class CBC740MapBase
{
  public:
    virtual ~CBC740MapBase()
    {
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        CBC740NiFree(m_ppkHashTable);
    }
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00cbc740 : public CBC740MapBase
{
  public:
    virtual ~FUN_00cbc740();
};
// Destructor that calls RemoveAll to clear the map's entries.
// @fnv 0x00cbc740
FUN_00cbc740::~FUN_00cbc740()
{
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
}

namespace fnv_00cbdf80 {
struct hkVector4
{
    float x, y, z, w;
};
class NiPoint3
{
  public:
    float x, y, z;
    char* FUN_00a59af0(const char* label);
};
struct StrArr
{
    void* vtable;
    char** entries;
    unsigned short capacity, size, used, growBy;
    void SetSize(unsigned int count);
    void Add(char*& value)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + growBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
};
struct ConstraintVectors
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    hkVector4 perpendicular1;
    hkVector4 perpendicular2;
    hkVector4 pivotA;
    hkVector4 axleB;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    hkVector4 pivotB;
};
struct ConstraintOwner
{
    void* vtable;
    ConstraintVectors* data;
    void AppendConstraintVectors(StrArr* output);
};
// @fnv 0x00cbdf80
void ConstraintOwner::AppendConstraintVectors(StrArr* output)
{
    TlsGuard_t context;
    reinterpret_cast<::ViewerConstraint *>(this)->FUN_00c8a560((::BC8AD40StringArray *)(output));
    ConstraintVectors* vectors = data;
    if (vectors)
    {
        NiPoint3 point;
        ::FUN_004a3970((::NiPoint3_local &)(point), (const ::hkVector4 &)(vectors->pivotA));
        char* text = point.FUN_00a59af0("PivotInA");
        output->Add(text);
        ::FUN_004a3970((::NiPoint3_local &)(point), (const ::hkVector4 &)(vectors->pivotB));
        text = point.FUN_00a59af0("PivotInB");
        output->Add(text);
        ::FUN_004a3970((::NiPoint3_local &)(point), (const ::hkVector4 &)(vectors->axleB));
        text = point.FUN_00a59af0("AxleInB");
        output->Add(text);
        ::FUN_004a3970((::NiPoint3_local &)(point), (const ::hkVector4 &)(vectors->perpendicular1));
        text = point.FUN_00a59af0("Perp2AxleInA1");
        output->Add(text);
        ::FUN_004a3970((::NiPoint3_local &)(point), (const ::hkVector4 &)(vectors->perpendicular2));
        text = point.FUN_00a59af0("Perp2AxleInA2");
        output->Add(text);
    }
}
}  // namespace fnv_00cbdf80

struct BCBEA40AllocTagScope
{
    int m_iSaved;

    BCBEA40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCBEA40AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};
class BCBEA40StringArray
{
  public:
    virtual ~BCBEA40StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class BCBEA40Owner
{
  public:
    void AddNameToArray(BCBEA40StringArray* pkArray);
};
// Sets an allocation tag scope, calls FUN_00c9f270 on the array, then appends the string from g_pcCBEA40Name to it.
// @fnv 0x00cbea40
void BCBEA40Owner::AddNameToArray(BCBEA40StringArray* pkArray)
{
    BCBEA40AllocTagScope kScope(0x10);
    reinterpret_cast<::C9F270Object *>(this)->FUN_00c9f270((::C9F270StrArray *)(pkArray));
    char* pcName = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268444)));
    pkArray->Add(pcName);
}

namespace fnv_00cbf540 {
struct hkMemoryAllocatorStub
{
    virtual void v00();
    virtual void* allocate(int nbytes);
    virtual void v08();
    virtual void v0c();
    virtual void deallocate(void* p, int nbytes);
};

struct hkThreadMemoryStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorStub* m_pThreadAllocator;
    void* allocateChunk(int nbytes)
    {
        return m_pThreadAllocator->allocate(nbytes);
    }
    void deallocateChunk(void* p, int nbytes)
    {
        m_pThreadAllocator->deallocate(p, nbytes);
    }
};


inline void* hkAllocateChunkStub(int nbytes)
{
    return static_cast<hkThreadMemoryStub*>(::FUN_00c85750())->allocateChunk(nbytes);
}

inline void hkDeallocateChunkStub(void* p, int nbytes)
{
    static_cast<hkThreadMemoryStub*>(::FUN_00c85750())->deallocateChunk(p, nbytes);
}


struct TlsScopeGuard
{
    int m_saved;
    TlsScopeGuard()
    {
        m_saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~TlsScopeGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_saved;
    }
};

struct hkPtrArrayStub
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~hkPtrArrayStub()
    {
        hkThreadMemoryStub* mem = static_cast<hkThreadMemoryStub*>(::FUN_00c85750());
        hkMemoryAllocatorStub* alloc = mem->m_pThreadAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc->deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(void*));
    }
};

struct CinfoA
{
    int m_iWordAt00;
    int unk04;
    int unk08;
    int unk0c;
    hkPtrArrayStub m_ppData;
    int unk1c;
    CinfoA();
};

struct ObjB
{
    int unk000;
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk006;
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

    static void* operator new(std::size_t nbytes)
    {
        ObjB* b = (ObjB*)hkAllocateChunkStub(nbytes);
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p, std::size_t nbytes)
    {
        static_cast<hkThreadMemoryStub*>(::FUN_00c85750())->deallocateChunk(p, ((ObjB*)p)->m_usMemSizeAndFlags);
    }
    ObjB(CinfoA* info);
};

struct CinfoCBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    CinfoCBase();
};

struct CinfoC : CinfoCBase
{
    CinfoC()
    {
        m_18 = 10;
    }
    ~CinfoC();
};

struct ObjD
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

    static void* operator new(std::size_t nbytes)
    {
        return hkAllocateChunkStub(nbytes);
    }
    static void operator delete(void* p, std::size_t nbytes)
    {
        hkDeallocateChunkStub(p, nbytes);
    }
    ObjD(CinfoC* info);
};


struct FUN_00cbf540_Owner
{
    int unk00;
    int m_iWordAt04;
    int unk08;
    int m_iThirdValue;
    int unk10;
    ObjD* m_14;
    ObjB* m_18;
    void CreateObjects(int* key, int unused);
};

// @fnv 0x00cbf540
void FUN_00cbf540_Owner::CreateObjects(int* key, int unused)
{
    TlsScopeGuard guard;
    reinterpret_cast<::fnv_00cbf2f0::FUN_00cbf2f0_class *>(this)->FUN_00cbf2f0();
    m_iThirdValue = *key;
    CinfoA a;
    a.m_iWordAt00 = m_iWordAt04;
    m_18 = new ObjB(&a);
    CinfoC c;
    m_14 = new ObjD(&c);
    ::InitHookTable((::TargetObj *)(m_14));
}
}  // namespace fnv_00cbf540

// Registers a batch of classes with the registry while it is temporarily locked.
class CBFC10Bool
{
  public:
    CBFC10Bool(bool b)
    {
        m_cBool = (char)b;
    }
    char m_cBool;
};
class CBFC10Registry
{
  public:
};
// @fnv 0x00cbfc10
void __cdecl RegisterAll(CBFC10Registry* pkRegistry)
{
    reinterpret_cast<::FUN_00cfb1e0 *>((pkRegistry))->Set((*(bool *)&(const ::CBFC10Bool &)(false)));
    ::fnv_00d314e0::FUN_00d314e0((::fnv_00d314e0::SpawnedObject *)(pkRegistry));
    ::FUN_00d2f2c0((::D2F2C0Dispatcher *)(pkRegistry));
    ::fnv_00d2e6d0::FUN_00d2e6d0((::fnv_00d2e6d0::TargetClass *)(pkRegistry));
    ::FUN_00d2dc70((::Agent *)(pkRegistry));
    ::FUN_00d2da20((::FUN_00cfbd60_Obj *)(pkRegistry));
    reinterpret_cast<::FUN_00cfb1e0 *>((pkRegistry))->Set((*(bool *)&(const ::CBFC10Bool &)(true)));
}

extern unsigned int DAT_011b1730;
extern unsigned int DAT_011b1734;

struct FUN_00ca3dc0_cls
{
    int unk00;
    int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned short m_10;
    unsigned short unk12;
    void* m_14;
    void* m_18;
    int unk1C;
    void* m_20;
    void* m_24;
    void FUN_00ca3dc0(S_00ca59d0_Stream* s);
};

// Serializes m_08, m_0c, a flag for m_20, m_10 and their buffers to the stream via S_00ca59d0_Save and Write.
// @fnv 0x00ca3dc0
void FUN_00ca3dc0_cls::FUN_00ca3dc0(S_00ca59d0_Stream* pStream)
{
    S_00ca59d0_Save(*pStream->unk250, &m_08, 1);
    pStream->unk250->Write(m_14, m_08 * 8, &DAT_011b1734, 4);
    S_00ca59d0_Save(*pStream->unk250, &m_0c, 1);
    bool v = m_20 != 0;
    S_00ca59d0_Save(*pStream->unk250, &v, 1);
    if (!v)
    {
        pStream->unk250->Write(m_18, m_0c * 12, &DAT_011b1730, 1);
    }
    else
    {
        unsigned int cs = 2;
        pStream->unk250->Write(m_20, m_0c * 6, &cs, 1);
    }
    S_00ca59d0_Save(*pStream->unk250, &m_10, 1);
    pStream->unk250->Write(m_24, m_10 * 12, &DAT_011b1730, 1);
}

struct SArr046
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void AppendReference(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};

struct InnerEntry046
{
    void* f0;
    int f4;
    void* f8;
};
struct Inner046
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m_uiItemCount;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    InnerEntry046* m_entries;
};
struct SubObj046
{
    int unk00[0x21];
    Inner046* m_84;
};
struct NodePtr046
{
    void* m_p;
};


struct ThisCls046
{
    int unk00;
    int unk04;
    SubObj046* m_8;
    void AppendSubpartNames(SArr046* arr);
};

// @fnv 0x00ca5b20
void ThisCls046::AppendSubpartNames(SArr046* arr)
{
    TlsGuard_t guard;
    reinterpret_cast<::fnv_00cd2fd0::Object *>(this)->FUN_00cd2fd0((::fnv_00cd2fd0::StrArr *)(arr));
    char* v1 = ::FUN_00a7d330(*reinterpret_cast<char* const*>(&::g_012682dc));
    arr->AppendReference(v1);
    SubObj046* sub = this ? m_8 : 0;
    unsigned int n = sub->m_84->m_uiItemCount;
    char* v2 = FUN_00a7d510("Subparts", n);
    arr->AppendReference(v2);
    if (n > 5)
        n = 5;
    for (unsigned int i = 0; i < n; ++i)
    {
        char* p = FUN_00a7d510("Part", i);
        arr->Append(p);
        NodePtr046 nodePtr;
        nodePtr.m_p = sub->m_84->m_entries[i].f0;
        reinterpret_cast<::HavokFilterInfo *>(&(nodePtr))->AppendToViewerStrings((::ViewerStrings *)(arr));
        Inner046* pInner = sub->m_84;
        char* m = FUN_00a7d4d0("MATERIAL", (intptr_t)pInner->m_entries[i].f8);
        arr->Append(m);
    }
}

struct bhkSerializable
{
    virtual ~bhkSerializable();
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
    int m_04;
    int m_08;
};

struct bhkCharacterPointCollector
{
    ~bhkCharacterPointCollector();
};


class FUN_00cabf50 : public bhkSerializable
{
  public:
    virtual ~FUN_00cabf50();
    int m_0c;
    bhkCharacterPointCollector m_kCollector;
};

// @fnv 0x00cabf50
FUN_00cabf50::~FUN_00cabf50()
{
    ((bhkSerializable*)this)->v37();
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_01268340;
}

struct LinkedObject
{
    int unk00[2];
    int m_iValue;  // +0x08
};

struct LinkStream
{
};

struct LandTextureParameters
{
    int unk00[18];
    int m_iValue;  // +0x48
};

class LinkBase
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
    virtual LandTextureParameters* GetHavokData(char& rcFlag);  // +0xb4
                         // base LinkObject
};

class LinkWrapper : public LinkBase
{
  public:
    void CopyHavokValueFromStream(LinkStream& kStream);
};

// @fnv 0x00cac030
void LinkWrapper::CopyHavokValueFromStream(LinkStream& kStream)
{
    LinkedObject* pkObject = ((::LinkedObject *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject()));
    char cFlag;
    LandTextureParameters* pkData = GetHavokData(cFlag);
    if (pkObject)
        pkData->m_iValue = pkObject->m_iValue;
    reinterpret_cast<::FUN_00c87670_Class *>(this)->FUN_00c87670((::NiStream &)(kStream));
}

struct FUN_00cb9d80_child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(void* context);
};

typedef int(__cdecl* FUN_00cb9d80_read_fn)(void* stream, void* data, unsigned int size, void* result, int flag);

struct FUN_00cb9d80_stream
{
    int unk00;
    int position;
    int unk08;
    FUN_00cb9d80_read_fn read;
};

struct FUN_00a641f0_class
{
};


struct FUN_00cb9d80_class
{
    int unk00;
    int unk04;
    int* unk08;
    int unk0c;
    FUN_00cb9d80_child** unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int* unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    void ReadFromStream(void* context);
};

// @fnv 0x00cb9d80
void FUN_00cb9d80_class::ReadFromStream(void* context)
{
    ::FUN_00a89af0((std::intptr_t)(context));
    unsigned int count = unk14;
    reinterpret_cast<::FUN_00a641f0_cls *>((((FUN_00a641f0_class*)context)))->WriteObjectLink(&unk08);

    unsigned int size = 4;

    FUN_00cb9d80_stream* stream = static_cast<FUN_00cb9d80_stream*>(static_cast<NiStreamFields*>(context)->m_pkStream);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk2c, size, &temp, 1);
    }
    stream = static_cast<FUN_00cb9d80_stream*>(static_cast<NiStreamFields*>(context)->m_pkStream);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk30, size, &temp, 1);
    }
    stream = static_cast<FUN_00cb9d80_stream*>(static_cast<NiStreamFields*>(context)->m_pkStream);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk34, size, &temp, 1);
    }
    stream = static_cast<FUN_00cb9d80_stream*>(static_cast<NiStreamFields*>(context)->m_pkStream);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk38, size, &temp, 1);
    }
    stream = static_cast<FUN_00cb9d80_stream*>(static_cast<NiStreamFields*>(context)->m_pkStream);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk3c, size, &temp, 1);
    }
    stream = static_cast<FUN_00cb9d80_stream*>(static_cast<NiStreamFields*>(context)->m_pkStream);
    {
        int temp = size;
        stream->position += stream->read(stream, &count, size, &temp, 1);
    }

    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int value = unk20[i];
        stream = static_cast<FUN_00cb9d80_stream*>(static_cast<NiStreamFields*>(context)->m_pkStream);
        {
            int temp = size;
            stream->position += stream->read(stream, &value, size, &temp, 1);
        }
    }

    for (unsigned int i = 0; i < count; ++i)
    {
        unk10[i]->v0c(context);
    }
}

struct StandInBinaryStream
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(StandInBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void BinaryStreamLoad(StandInBinaryStream& kIs, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kIs.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct StandInStream : public NiStream
{
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
    StandInBinaryStream* m_pkIStream;

};

template <class T> inline void StreamRead(StandInStream& kStream, T& val)
{
    BinaryStreamLoad(*kStream.m_pkIStream, &val, 1);
}

struct MemoryManager_t
{
};

struct BaseCinfo
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;


    __forceinline BaseCinfo() : m_iWordAt04(0), m_8(1), m_iThirdValue(0), m_10(0)
    {}

    virtual void v00();
    virtual void v04();
    virtual void LoadBinary(NiStream& kStream);
};

extern int DAT_0108ff98;

struct Cinfo_13 : public BaseCinfo
{
    __forceinline Cinfo_13()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_0 : public BaseCinfo
{
    __forceinline Cinfo_0()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_1 : public BaseCinfo
{
    __forceinline Cinfo_1()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_2 : public BaseCinfo
{
    __forceinline Cinfo_2()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_7 : public BaseCinfo
{
    __forceinline Cinfo_7()
    {}
    virtual void LoadBinary(NiStream& kStream);
};

struct RagdollBase
{
    virtual ~RagdollBase();
};

class bhkRagdollTemplateData : public RagdollBase
{
  public:
    int unk04;
    void* m_kName;
    CA0E60Array m_kArray1;
    CA0E60Array m_kArray2;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;

    void FUN_00cba340(StandInStream& kStream);
};

// Loads the ragdoll template data: name link, five ints, a count, type array, then allocates and loads a Cinfo per type.
// @fnv 0x00cba340
void bhkRagdollTemplateData::FUN_00cba340(StandInStream& kStream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(kStream));
    reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((*(::fnv_00a64df0::NiFixedString *)(&m_kName)));

    StreamRead(kStream, m_2c);
    StreamRead(kStream, m_30);
    StreamRead(kStream, m_34);
    StreamRead(kStream, m_38);
    StreamRead(kStream, m_3c);

    unsigned int ItemUpdateArray = 0;
    StreamRead(kStream, ItemUpdateArray);

    m_kArray1.SetSize(ItemUpdateArray);
    m_kArray2.SetSize(ItemUpdateArray);

    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiType;
        StreamRead(kStream, uiType);
        ((unsigned int*)m_kArray2.m_pBuffer)[i] = uiType;
    }

    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiType = ((unsigned int*)m_kArray2.m_pBuffer)[i];
        BaseCinfo* pCinfo = 0;
        switch (uiType)
        {
        case 13:
            pCinfo = new Cinfo_13();
            m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        case 0:
            m_kArray1.m_pBuffer[i] = new Cinfo_0();
            break;
        case 1:
            pCinfo = new Cinfo_1();
            m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        case 2:
            m_kArray1.m_pBuffer[i] = new Cinfo_2();
            break;
        case 7:
            pCinfo = new Cinfo_7();
            m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        }
        BaseCinfo* pObj = (BaseCinfo*)m_kArray1.m_pBuffer[i];
        pObj->LoadBinary(kStream);
    }
}

struct FUN_00ca0ca0_Class
{
    void* m_vtbl;
    FUN_00ca0ca0_Class* FUN_00ca0ca0(int flags);
};

struct MemMgr_00aa4060
{
};

extern int DAT_010c7304;

// Sets the vtable pointer and, when flags has bit 0 set, passes this to FUN_00aa4060 on DAT_011f6238, then returns this.
// @fnv 0x00ca0ca0
FUN_00ca0ca0_Class* FUN_00ca0ca0_Class::FUN_00ca0ca0(int flags)
{
    m_vtbl = &DAT_010c7304;
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemMgr_00aa4060*)&(*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

struct WalkPlacement
{
};
inline void* operator new(std::size_t, WalkPlacement, void* p)
{
    return p;
}
struct WalkRTTI
{
    const char* name;
    WalkRTTI* parent;
};
struct WalkObject
{
    virtual void v0();
    virtual void v4();
    virtual WalkRTTI* GetRTTI();
    int ref;
    struct WalkBody* body;
    struct WalkType* fallback;
    __forceinline WalkObject* AsItem()
    {
        if (!this)
            return 0;
        return IsKind(&(*reinterpret_cast<int *>(&::g_0126818c))) ? this : 0;
    }
    bool IsKind(const void* type)
    {
        for (WalkRTTI* r = GetRTTI(); r; r = r->parent)
            if (r == type)
                return true;
        return false;
    }
};
inline WalkObject* KindCast(WalkObject* item)
{
    if (!item)
        return 0;
    return item->IsKind(&(*reinterpret_cast<int *>(&::g_0126818c))) ? item : 0;
}
struct WalkType
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct WalkBody
{
    int unk, unkCur, unkValue;
    WalkType* type;
};
struct WalkLink
{
    WalkObject* item;
    WalkLink* next;
    WalkObject* GetItem()
    {
        return item;
    }
    WalkLink* Next()
    {
        return next;
    }
};
struct WalkLeaf
{
    int unk, unkCur;
    void* object;
    int unk0c, uNewnk;
    WalkLink links;
};
class NiAVObject;
class NiRTTI;
class GarbageCollectorObjectPtr
{
  public:
    WalkObject* object;
    int high;
};
GarbageCollectorObjectPtr* __cdecl FUN_00c85ef0(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
struct WalkAlloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void Free(void*, int) throw();
};
struct WalkRouter
{
    int unk, unkCur, unkValue, unk0c;
    WalkAlloc* heap;
    WalkAlloc& Heap()
    {
        return *heap;
    }
};

template <class T> __forceinline void WalkDestruct(T* ptr, int count)
{
    for (int i = 0; i < count; ++i)
        ptr[i].~T();
}
template <class T> inline void WalkDeallocate(WalkAlloc& alloc, T* ptr, int count)
{
    alloc.Free(ptr, count * int(sizeof(T)));
}
struct WalkArray
{
    void** data;
    int size;
    int capacity;
    WalkArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~WalkArray()
    {
        WalkAlloc& alloc = ((WalkRouter*)static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750()))->Heap();
        ClearAndRelease(alloc);
    }
    void ClearAndRelease(WalkAlloc& alloc)
    {
        WalkDestruct(data, size);
        size = 0;
        if ((capacity & 0x80000000) == 0)
            WalkDeallocate(alloc, data, capacity & 0x3fffffff);
        data = 0;
        capacity = 0x80000000;
    }

    __forceinline void Add(void* const& value)
    {
        FNVTaskAllocator* alloc = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator;
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(alloc), (::AudioStream *)(void *)(this), 4);
        *new (WalkPlacement(), &data[size]) void* = value;
        ++size;
    }
};
inline WalkObject* GetRoot(void* obj)
{
    GarbageCollectorObjectPtr temp;
    return FUN_00c85ef0(&temp, (NiAVObject*)obj, (const NiRTTI*)&(*reinterpret_cast<::WalkRTTI *>(&::g_01267b70)))->object;
}
// @fnv 0x00ca11e0
void CollectLeafObjects(WalkLeaf* leaf, WalkArray* outObjects, WalkArray* outBodies)
{
    if (!leaf)
        return;
    WalkObject* cast;
    {
        WalkObject* root = GetRoot(leaf->object);
        if (!root)
            cast = 0;
        else
            cast = ((::WalkObject *)(reinterpret_cast<::NiObject *>((root))->DynamicCast((const ::NiRTTI *)(const ::WalkRTTI *)(&(*reinterpret_cast<::WalkRTTI *>(&::g_0126817c))))));
    }
    WalkLink* link = &leaf->links;
    bool found = false;
    WalkArray bodyArray;
    for (; link && (link->GetItem() != 0) && !found; link = link->Next())
    {
        WalkObject* item = link->item;
        WalkObject* body = item->AsItem();
        if (body)
        {
            WalkType* type = body->body ? body->body->type : (body->fallback ? *(WalkType**)body->fallback : 0);
            if (type->GetType() == 12)
                found = true;
            else
            {
                void* value = body->body;
                FNVTaskAllocator* alloc = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator;
                if (bodyArray.size == (bodyArray.capacity & 0x3fffffff))
                    ::ResizeAudioStream((::AudioAllocator *)(alloc), (::AudioStream *)(void *)(&bodyArray), 4);
                bodyArray.data[bodyArray.size++] = value;
            }
        }
    }
    if ((!cast || bodyArray.size > 0) && !found)
    {
        void* object = leaf->object;
        outObjects->Add(object);
        for (int index = 0; index < bodyArray.size; ++index)
            outBodies->Add(bodyArray.data[index]);
    }
}

struct TlsBlock_ca57
{
    unsigned int m_2b4;
};
struct TlsFlagGuard_ca57
{
    unsigned int m_saved;
    TlsFlagGuard_ca57()
    {
        m_saved = (*reinterpret_cast<::TlsBlock_ca57 *>(&::currentAllocationContext)).m_2b4;
        (*reinterpret_cast<::TlsBlock_ca57 *>(&::currentAllocationContext)).m_2b4 = 16;
    }
    ~TlsFlagGuard_ca57()
    {
        (*reinterpret_cast<::TlsBlock_ca57 *>(&::currentAllocationContext)).m_2b4 = m_saved;
    }
};
class Pool_ca57
{
  public:
};
class Node_ca57
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Node_ca57();
    static void operator delete(void*) throw()
    {}
    void* operator new(std::size_t size) throw()
    {
        unsigned char* raw = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>((((Pool_ca57*)&(*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager)))))->FUN_00aa3e40(size);
        unsigned char lo = (unsigned char)(uintptr_t)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        GetAlignedBlockPrefix(raw)->m_ucOffset = pad;
        return raw;
    }
};
class Owner_ca57
{
  public:
    unsigned int unk00, unk04, m_08;
    unsigned int* m_0c;
    unsigned int* GetOrCreateNode(bool*);
};
// Sets *out to whether m_0c is null; if so allocates a Node_ca57, stores it in m_0c, and calls FUN_00ca5360 when m_08 is nonzero; returns m_0c.
// @fnv 0x00ca57a0
unsigned int* Owner_ca57::GetOrCreateNode(bool* pbWasNull)
{
    TlsFlagGuard_ca57 guard;
    *pbWasNull = (m_0c == 0);
    if (*pbWasNull)
    {
        pbWasNull = (bool*)new Node_ca57();
        m_0c = (unsigned int*)pbWasNull;
        if (m_08 != 0)
            reinterpret_cast<::FUN_00ca5360_cls *>(this)->FUN_00ca5360((::MassInfo_ca5360 *)(m_0c));
    }
    return m_0c;
}

// @fnv 0x00ca6610
int __cdecl FUN_00ca6610(intptr_t param_1)
{
    return ::FUN_00c84ec0((void *)(param_1));
}

struct FNVHeapAllocator : FNVTaskAllocator
{
    template <typename T> void _bufFree(void* p, int numElem)
    {
        Free(p, numElem * sizeof(T));
    }
};

struct FNVHeapRouter : FNVTaskMemoryRouter
{
    FNVHeapAllocator& heap()
    {
        return *(FNVHeapAllocator*)allocator;
    }
};

template <typename T> struct FNVArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(FNVHeapAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~FNVArray()
    {
        _clearAndDeallocate(((FNVHeapRouter*)static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750()))->heap());
    }
};

struct FUN_00ca73c0
{
    int unk00[9];
    FNVArray<int> unk24;
    FNVArray<int> unk30;
    FNVArray<int> unk3C;
    FNVArray<int> unk48;
    FNVArray<char> unk54;
    FNVArray<int> unk60;
    FNVArray<int> unk6C;
    FNVArray<int> unk78;
    FNVArray<int> unk84;
    FNVArray<int> unk90;
    FNVArray<int> unk9C;
    FNVArray<int> unkA8;
    ~FUN_00ca73c0();
};

// Destroys the object; the member arrays are released by their own destructors after this body runs.
// @fnv 0x00ca73c0
FUN_00ca73c0::~FUN_00ca73c0()
{}

struct PositionCommand
{
    unsigned char opcode;
    void* sender;
    float x;
    float y;
    float z;
};

struct PositionQueue
{
    char pad[0x94];
    int m_iLockCount;
};

struct PositionOwner
{
    int unk00;
    int unk04;
    PositionQueue* queue;

    void SendPositionCommand(float* position);
};

// @fnv 0x00ca89e0
void PositionOwner::SendPositionCommand(float* position)
{
    PositionQueue* active = queue;
    if (active && active->m_iLockCount)
    {
        PositionCommand command;
        command.sender = this;
        command.opcode = 0x19;
        command.x = position[0];
        command.y = position[1];
        command.z = position[2];
        reinterpret_cast<::WorldWithPending *>((active))->FUN_00c91160();
    }
    else
    {
        reinterpret_cast<::FUN_005616d0_Owner *>(this)->OnTrigger((::TriggerContext *)(position));
    }
}

void __cdecl FUN_00c896b0();
// @fnv 0x00ca98d0
void __cdecl FUN_00ca98d0()
{
    FUN_00c896b0();
}

// @fnv 0x00ca98f0
char FUN_00ca98f0()
{
    return 0xff;
}


struct RNG_cabbd0
{
    int unk00;
    unsigned int m_uiState;

    unsigned int Next()
    {
        m_uiState = m_uiState * 1664525 + 1013904223;
        return m_uiState;
    }
};

// @fnv 0x00cabbd0
unsigned int __cdecl FUN_00cabbd0(RNG_cabbd0* rng)
{
    float min = 0.0f;
    float max = 1.0f;
    unsigned int uRand1 = rng->Next();
    unsigned int uRand2 = rng->Next();
    unsigned int uRand3 = rng->Next();
    return PackColorBigEndian((float)(min + (max - min) * (float)((float)uRand1 * 2.3283064365386963e-10)),
                              (float)(min + (max - min) * (float)((float)uRand2 * 2.3283064365386963e-10)),
                              (float)(min + (max - min) * (float)((float)uRand3 * 2.3283064365386963e-10)), 1.0f);
}

extern int DAT_011b1a58[8];
// @fnv 0x00cabcb0
int __cdecl CombineIndexedMaskAndShift(int aiIndex, int aiHighByte)
{
    return (DAT_011b1a58[aiIndex & 0x1F] & 0x00ffffff) | (aiHighByte << 0x18);
}

struct SomeClass
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
    int m_74;
};

// @fnv 0x00cac900
int* FUN_00cac900(SomeClass* pThis)
{
    return &pThis->m_74;
}

struct FnvCpu_FUN_00cac950_CpuObject
{
    char pad[16];
    char m_acData[1];
    char* FUN_00cac950();
};
// @fnv 0x00cac950
char* FnvCpu_FUN_00cac950_CpuObject::FUN_00cac950()
{
    return m_acData;
}

struct FUN_00CAFEC0_This
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
    void** unk60;
    int unk64;
    float unk68;
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
};
struct FUN_00CAFEC0_Class
{
    float GetTableValue(int param_2, int param_3);
};
// Reads a float from the table at unk60 using an index computed from param_2, param_3, unk64 and unk10, and adds unk68.
// @fnv 0x00cafec0
float FUN_00CAFEC0_Class::GetTableValue(int param_2, int param_3)
{
    int v0_64 = ((FUN_00CAFEC0_This*)this)->unk64;
    int v0_10 = ((FUN_00CAFEC0_This*)this)->unk10;

    int diff = v0_64 - param_3;
    int product = diff * v0_10;
    int index = product + param_2;

    float* pfTable = (float*)((FUN_00CAFEC0_This*)this)->unk60;
    float val = pfTable[2 + index * 3];

    return val + ((FUN_00CAFEC0_This*)this)->unk68;
}

struct FUN_00cb0a70_Class
{
    void* FUN_00cb0a70(intptr_t a);
};

// @fnv 0x00cb0a70
void* FUN_00cb0a70_Class::FUN_00cb0a70(intptr_t a)
{
    return this;
}

// @fnv 0x00cb0f80
void __cdecl FUN_00cb0f80(char* a, const char* b, char* c)
{
    std::vsprintf(a, b, (char*)&c);
}


// @fnv 0x00cb0fd0
int __cdecl FUN_00cb0fd0(const char* s1, const char* s2, unsigned int count)
{
    return std::strncmp(s1, s2, count);
}

namespace fnv_00cb0fe0 {
__declspec(noinline) char ToLowerAscii(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}

char(__cdecl* g_pfnCB0FE0ToLower)(char) = ::ToLowerAscii;

// @fnv 0x00cb0fe0
int CompareStringsCaseInsensitive(const char* pStringA, const char* pStringB)
{
    int off = (int)(pStringA - pStringB);
    for (;;)
    {
        if (pStringB[off] == 0)
        {
            if (*pStringB == 0)
            {
                return 0;
            }
        }
        char x = ::ToLowerAscii(pStringB[off]);
        char y = ::ToLowerAscii(*pStringB);
        if (x < y)
        {
            return -1;
        }
        if (x > y)
        {
            return 1;
        }
        pStringB++;
    }
}
}  // namespace fnv_00cb0fe0

void FUN_00cd4af0(int a1);
// @fnv 0x00cb2d70
uintptr_t FUN_00cb2d70(uintptr_t uiValue)
{
    FUN_00cd4af0((int)uiValue);
    return uiValue;
}

// @fnv 0x00cb75f0
void __cdecl FUN_00cb75f0(void)
{
    static_cast<::LegacyCollisionLoader *>(nullptr)->FUN_00c87f60(*(::NiStream *)nullptr);
}

// @fnv 0x00cb7600
void __cdecl FUN_00cb7600()
{
    static_cast<::LegacyLinker *>(nullptr)->FUN_00c87f80({});
}

void __cdecl FUN_00c87fa0();

// @fnv 0x00cb7610
void __cdecl FUN_00cb7610()
{
    FUN_00c87fa0();
}

bool __cdecl FUN_00c87fb0(int param_1, int param_2);
// @fnv 0x00cb7630
bool __cdecl FUN_00cb7630(int param_1, int param_2)
{
    return FUN_00c87fb0(param_1, param_2);
}

extern int DAT_012683e8;

struct FUN_00c86720
{
    virtual ~FUN_00c86720();
};

struct FUN_00cb83f0 : FUN_00c86720
{
    virtual ~FUN_00cb83f0();
};

// @fnv 0x00cb83f0
FUN_00cb83f0::~FUN_00cb83f0()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_012683e8;
}

struct CpuOpaque;
// @fnv 0x00cb8460
CpuOpaque* __cdecl FUN_00cb8460()
{
    return &(*reinterpret_cast<::CpuOpaque *>(&::g_012683ec));
}

// @fnv 0x00cb8470
void __cdecl FUN_00cb8470()
{
    static_cast<::FUN_00c86800_Class *>(nullptr)->FUN_00c86800({}, {});
}

extern "C" void __cdecl FUN_00aa1460(void* self, int size);

struct FUN_00cb8480_class
{
    void FUN_00cb83f0();
    FUN_00cb8480_class* FUN_00cb8480(char flag);
};

// @fnv 0x00cb8480
FUN_00cb8480_class* FUN_00cb8480_class::FUN_00cb8480(char flag)
{
    reinterpret_cast<::FUN_00cb83f0 *>(this)->FUN_00cb83f0::~FUN_00cb83f0();
    if (flag & 1)
    {
        FUN_00aa1460(this, 0x10);
    }
    return this;
}

struct FUN_00d2acf0
{
    void* vtable;
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
    unsigned int unk08, unk0C, unk10, unk14;
    unsigned int unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34;
    unsigned int unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54;
    unsigned int unk58, unk5C;

    FUN_00d2acf0(void* source, void* start, void* end, float nearValue, float farValue, int flags);

    static void* operator new(std::size_t bytes)
    {
        FNVTaskMemoryRouter* router = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
        FUN_00d2acf0* object = (FUN_00d2acf0*)((CAC300Allocator*)router->allocator)->Alloc(bytes);
        object->memorySizeAndFlags = (unsigned short)bytes;
        return object;
    }
    static void operator delete(void* object);
};

struct FUN_00cb88d0_params
{
    int unk00;
    void* m_pShape;
    char pad08[8];
    float m_afA[4];
    float m_afB[4];
    float m_f30;
    float m_f34;
};

struct FUN_00cb88d0_owner : CAC300Owner
{
    void CreateShapeAndApply(void* parameters);
};

// Allocates a FUN_00d2acf0 from the parameters block, sets it as the object, calls FUN_00c905b0, then applies the parameters.
// @fnv 0x00cb88d0
void FUN_00cb88d0_owner::CreateShapeAndApply(void* pParams)
{
    CA2020AllocTagScope allocationTag(16);
    FUN_00cb88d0_params* params = static_cast<FUN_00cb88d0_params*>(pParams);
    FUN_00d2acf0* shape = new FUN_00d2acf0(params->m_pShape, (char*)params->m_afA, (char*)params->m_afB, params->m_f30,
                                           params->m_f34, 0);
    SetObject((hkReferencedObject*)shape);
    reinterpret_cast<::hkReferencedObjectC905 *>((shape))->FUN_00c905b0();
    Apply((intptr_t)pParams);
}

struct FUN_00cb89c0_cls
{
    void AppendGlobalReference(SArr046* arr);
};
// Calls FUN_00c86b80 on arr, then appends the reference returned by FUN_00a7d330 for g_012683ec to arr.
// @fnv 0x00cb89c0
void FUN_00cb89c0_cls::AppendGlobalReference(SArr046* pArray)
{
    TlsGuard_t guard;
    char* value = 0;
    reinterpret_cast<::Wrapper86b80 *>(this)->FUN_00c86b80((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(pArray));
    value = ::FUN_00a7d330((const char *)(*reinterpret_cast<GlobalObjectO2_00a7b610**>(&g_012683ec)));
    pArray->AppendReference(value);
}

struct CpuOpaque;
// @fnv 0x00cb9250
CpuOpaque* __cdecl FUN_00cb9250()
{
    return &(*reinterpret_cast<::CpuOpaque *>(&::g_012683f4));
}


// @fnv 0x00cb9920
void __cdecl FUN_00cb9920()
{
    static_cast<::NiObject_00a7b3d0 *>(nullptr)->FUN_00a7b3d0({});
}

class CBADDynamicArray : public CA0E60Array
{
  public:
    void FUN_00cbadf0(unsigned int requestedSize, bool compact);
};

// @fnv 0x00cbadf0
void CBADDynamicArray::FUN_00cbadf0(unsigned int requestedSize, bool compact)
{
    if (requestedSize == 0)
    {
        if (m_pBuffer != 0)
        {
            ::ReleaseItems((::FUN_00cba0d0_cls **)this, (uintptr_t)(m_pBuffer));
            if (compact)
            {
                Free(m_pBuffer);
                m_pBuffer = 0;
                m_uiCapacity = 0;
            }
            m_uiSize = 0;
        }
        return;
    }

    if (requestedSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(requestedSize);
        }
        else
        {
            reinterpret_cast<::FUN_00cb9ce0_cls *>(this)->FUN_00cb9ce0(requestedSize, m_uiSize);
        }
        unsigned int oldSize = m_uiSize;
        m_uiCapacity = requestedSize;
        ::FUN_00cb9d50((int *)this, (uintptr_t)(m_pBuffer + oldSize));
        m_uiSize = requestedSize;
    }
    else if (requestedSize < m_uiSize)
    {
        ::ReleaseItems((::FUN_00cba0d0_cls **)this, (uintptr_t)(m_pBuffer + requestedSize));
        m_uiSize = requestedSize;
        if (compact && requestedSize <= m_uiCapacity / 4)
        {
            reinterpret_cast<::FUN_00cb9ce0_cls *>(this)->FUN_00cb9ce0(requestedSize, requestedSize);
            m_uiCapacity = requestedSize;
        }
    }
    else
    {
        unsigned int oldSize = m_uiSize;
        ::FUN_00cb9d50((int *)this, (uintptr_t)(m_pBuffer + oldSize));
        m_uiSize = requestedSize;
    }
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01268408;

// @fnv 0x00cbaf80
GlobalObjectO2_00a7b610* __cdecl FUN_00cbaf80()
{
    return &g_01268408;
}

struct FUN_00cbaf90_Obj
{
    void FUN_00cbaf90();
};
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct FUN_00cbb130_Class : FUN_00cbaf90_Obj
{
    void* FUN_00cbb130(unsigned char flag);
};
extern int DAT_010c9194;

struct FUN_00cbc460
{
    void* m_ppVirtualMethodTable;
    unsigned short m_04;
    unsigned short m_w06;
    // volatile keeps the vptr store ahead of the zero stores, as in the original
    void* volatile m_p08;
    void* volatile m_p0c;
    void* volatile m_p10;
    void* volatile m_p14;
    void* volatile m_p18;
    void* volatile m_p1c;
    void* volatile m_p20;
    void* volatile m_p24;
    void* volatile m_p28;
    void* volatile m_p2c;
    void* volatile m_p30;
    FUN_00cbc460();
};

// @fnv 0x00cbc460
FUN_00cbc460::FUN_00cbc460()
{
    m_ppVirtualMethodTable = &DAT_010c9194;
    m_w06 = 1;
    m_p08 = 0;
    m_p0c = 0;
    m_p10 = 0;
    m_p14 = 0;
    m_p18 = 0;
    m_p1c = 0;
    m_p20 = 0;
    m_p24 = 0;
    m_p28 = 0;
    m_p2c = 0;
    m_p30 = 0;
}


// @fnv 0x00cbf530
void __cdecl FUN_00cbf530()
{
    static_cast<::CBF490Lists *>(nullptr)->ClearLists();
}

struct HeapAllocator
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};

struct RefStub
{
    void IncRefCount();
    void DecRefCount();
};

struct RefHolder
{
    RefStub* object;
    RefHolder()
    {}
    ~RefHolder()
    {
        if (object)
            object->DecRefCount();
    }
};

struct ThreadLocalData
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
    int heapIndex;
};

struct HeapIndexGuard
{
    int saved;
    HeapIndexGuard(int index)
    {
        saved = (*reinterpret_cast<::ThreadLocalData *>(&::g_tlsBlock)).heapIndex;
        (*reinterpret_cast<::ThreadLocalData *>(&::g_tlsBlock)).heapIndex = index;
    }
    ~HeapIndexGuard()
    {
        (*reinterpret_cast<::ThreadLocalData *>(&::g_tlsBlock)).heapIndex = saved;
    }
};

extern int DAT_010c7600;

struct ShapePrefix
{
    int unk00;
    float unk04;
    ShapePrefix() : unk00(0), unk04(0.0f)
    {}
};

struct ShapeStrips
{
    void* vtbl;
    void* pBase;
    unsigned int maxSize;
    unsigned int size;
    unsigned int eSize;
    unsigned int growBy;

    ShapeStrips(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        maxSize = uiMaxSize;
        growBy = uiGrowBy;
        size = 0;
        eSize = 0;
        if (uiMaxSize > 0)
            pBase = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::HeapAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(uiMaxSize);
        else
            pBase = 0;
        vtbl = &DAT_010c7600;
    }
};

struct ShapeVector
{
    float x;
    float y;
    float z;
    float w;
    ShapeVector()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};

struct ShapeData : ShapePrefix
{
    ShapeStrips strips;
    ShapeVector scale;

    static void* operator new(std::size_t size)
    {
        char* p = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::HeapAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(size + 16);
        unsigned char off = (unsigned char)(16 - ((unsigned char)(uintptr_t)p & 15));
        p += off;
        GetAlignedBlockPrefix(p)->m_ucOffset = off;
        return p;
    }
    static void operator delete(void* p)
    {
        if (p)
        {
            unsigned char off = GetAlignedBlockPrefix(p)->m_ucOffset;
            (*reinterpret_cast<::HeapAllocator *>(&::g_memoryManager)).Deallocate((char*)p - off);
        }
    }

    ShapeData()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
    void SetScale()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
};
struct ShapeOwnerTarget
{
};

struct MyObj
{
    int unk00;
    int unk04;
    ShapeOwnerTarget* unk08;
    ShapeData* unk0c;

    ShapeData* GetOrCreateShapeData(bool* created);
};

// Creates a ShapeData on first call, copies entries from unk08 or resets scale, and returns the stored ShapeData pointer.
// @fnv 0x00ca6d40
ShapeData* MyObj::GetOrCreateShapeData(bool* created)
{
    HeapIndexGuard guard(16);
    if ((*created = (unk0c == 0)) != false)
    {
        ShapeData* data = new ShapeData;
        unk0c = data;
        if (unk08)
        {
            reinterpret_cast<::This *>(this)->FUN_00c84e20((unsigned int *)(data));
            if (unk08)
                reinterpret_cast<::FUN_00ca4d20_cls *>((unk08))->CopyEntriesToArg((::FNVArg *)(data));
            else
                data->SetScale();
        }
    }
    return unk0c;
}

struct FNV_InnerObject
{
    virtual void Call0(int);
    virtual void Call1(int);
    virtual void Call2(int);
    virtual void Call3(int);
    virtual void Call4(int);
    virtual void Call5(int);
    virtual void Call6(int);
    virtual void Call7(int);
    virtual void Call8(int);
};
struct FNV_OwnerObject
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
    FNV_InnerObject inner;
    void FUN_00ca8940(int);
};
// @fnv 0x00ca8940
void FNV_OwnerObject::FUN_00ca8940(int forwarded)
{
    inner.Call8(forwarded);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    char *FUN_00a59af0(const char *);
};
struct CA8B80Command;
struct CA8B80Queue
{
    char pad[0x94];
    int m_iLockCount;
};
struct FUN_00ca8a30_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    CA8B80Queue* m_8;
    void PushCommand(NiPoint3*);
};
struct FUN_00ca8a30_Local
{
    unsigned char m_kPointB;
    FUN_00ca8a30_Class* m_p;
    float m_uiX;
    float m_uiY;
    float m_uiZ;
};
// If m_8 is set and its m_iLockCount is nonzero, pushes a command holding this and the coordinates onto m_8; otherwise calls FUN_00561800(p).
// @fnv 0x00ca8a30
void FUN_00ca8a30_Class::PushCommand(NiPoint3* apPoint)
{
    if (m_8 && m_8->m_iLockCount)
    {
        FUN_00ca8a30_Local localCmd;
        localCmd.m_p = this;
        localCmd.m_uiX = apPoint->x;
        localCmd.m_kPointB = 0x1a;
        localCmd.m_uiY = apPoint->y;
        localCmd.m_uiZ = apPoint->z;
        reinterpret_cast<::WorldWithPending *>((m_8))->FUN_00c91160();
    }
    else
    {
        reinterpret_cast<::FUN_00561800_Class *>(this)->FUN_00561800((::FUN_00561730_Obj *)(apPoint));
    }
}

void __cdecl _delete(void* p, int size);

struct ScopedMemContext_ca9e60
{
    int m_iOld;
    ScopedMemContext_ca9e60(int context)
    {
        m_iOld = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = context;
    }
    ~ScopedMemContext_ca9e60()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iOld;
    }
};

struct Holder_ca9e60
{
    void* p;
    Holder_ca9e60(void* q) : p(q)
    {}
    ~Holder_ca9e60()
    {
        if (p)
            _delete(p, 0x10);
    }
};

struct Host_ca9e60
{
    void* FUN_00ca9e60(void* arg);
};

struct Object_ca9e60
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int m_0c;
};

// Allocates a bhkRefObject, initializes it, increments two global counters, passes it and arg to FUN_00c89730, and returns it.
// @fnv 0x00ca9e60
void* Host_ca9e60::FUN_00ca9e60(void* arg)
{
    ScopedMemContext_ca9e60 context(0x10);
    FUN_00c876f0();
    bhkRefObject* obj;
    void* p = FUN_00aa13e0(0x10);
    {
        Holder_ca9e60 h(p);
        if (p)
        {
            reinterpret_cast<::FUN_00c87c30_t *>((((bhkRefObject*)p)))->FUN_00c87c30();
            *(void**)p = &DAT_0108febc;
            int one = 1;
            static_cast<Object_ca9e60*>(p)->m_0c = 0;
            DAT_01268188 += one;
            *(void**)p = &DAT_010c81ac;
            DAT_0126830c += one;
            obj = (bhkRefObject*)p;
        }
        else
        {
            obj = NULL;
        }
        h.p = 0;
    }
    reinterpret_cast<::Owner89730 *>((this))->FUN_00c89730(obj, (::Process89730 *)(arg));
    FUN_00c87700();
    return obj;
}

// @fnv 0x00caa1b0
void __cdecl FUN_00caa1b0()
{
    static_cast<::FUN_00c89cf0_cls *>(nullptr)->DispatchToTarget({});
}

extern int DAT_01268334;
extern int DAT_01268338;
extern int DAT_0126833c;

// @fnv 0x00cabe90
unsigned int __cdecl FUN_00cabe90()
{
    if (!(DAT_0126833c & 1))
    {
        DAT_0126833c |= 1;
        DAT_01268334 = 0;
        DAT_01268338 = 0;
    }
    return ::FUN_00cabbd0((::RNG_cabbd0 *)(int *)(&DAT_01268334));
}

struct CA0F0Result
{
    int unk00;
    int unk04;
    int m_8;
};
struct CA0F0Object : BaseThunk
{
    int GetResultValue();
};
struct RefCountedCAC4B0
{
    int unk00;
    long m_iRefCount;
};
struct ShapeHolderCAC4B0
{
    int unk00;
    int unk04;
    int unk08;
    RefCountedCAC4B0* m_pkShape;
};
struct WorldObjectCAC4B0
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
    void* m_pkUserData;
};
struct RefObjectCAC4B0
{
    int unk00;
    int unk04;
    WorldObjectCAC4B0* m_pkHavokObject;
    WorldObjectCAC4B0* GetHavokObject()
    {
        return this ? m_pkHavokObject : 0;
    }
};
struct ShapeRefCAC4B0 : public RefObjectCAC4B0
{
    void FUN_00cac4b0(bool bAdd);
};

inline unsigned int GetMemContextC5E0()
{
    return ::currentAllocationContext;
}
inline void SetMemContextC5E0(unsigned int m_uiGeometryShaderFlags)
{
    ::currentAllocationContext = m_uiGeometryShaderFlags;
}
class AutoMemContextC5E0
{
  public:
    AutoMemContextC5E0(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC5E0();
        SetMemContextC5E0(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC5E0()
    {
        SetMemContextC5E0(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

class hkMemoryAllocatorC5E0
{
  public:
    virtual ~hkMemoryAllocatorC5E0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterC5E0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorC5E0& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocatorC5E0* m_pStreamAllocator;
};

hkMemoryRouterC5E0* __cdecl GetMemoryRouterC5E0();

class BufferOwnerC5E0
{
  public:
    void FreeBuffer(bool bFree);

    int unk00;
    int unk04;
    int unk08;
    void* pvContextData;
};

// If bFree is set, releases the pvContextData buffer through the memory router heap and nulls the pointer.
// @fnv 0x00cac5e0
void BufferOwnerC5E0::FreeBuffer(bool bFree)
{
    AutoMemContextC5E0 kContext(0x10);
    if (bFree)
    {
        void* pvBuffer = pvContextData;
        if (pvBuffer)
            GetMemoryRouterC5E0()->heap().ReleaseBlock(pvBuffer, 0x80);
        pvContextData = 0;
    }
}

namespace fnv_00cac6b0 {
// ---- FUN_00cac6b0 candidate ----

struct NiRTTI
{
    char* m_pcName;
};


class NiPoint3
{
  public:
    float x, y, z;
};

struct FUN_00cac910_shell
{
};
struct ProxyHolder
{
};

struct ProxyOwner
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

    int unk04;
    FUN_00cac910_shell* m_8;

    void FUN_00cac6b0(SArr046* pkStrings);
};

static const char kCac6b0Pos[] = "Pos";
static const char kCac6b0Vel[] = "Vel";

// Appends to pkStrings the class name, then the Pos and Vel vectors read from the proxy m_8 when it is present.
// @fnv 0x00cac6b0
void ProxyOwner::FUN_00cac6b0(SArr046* pkStrings)
{
    TlsGuard_t guard;

    reinterpret_cast<::FUN_00c878c0_cls *>((this))->FUN_00c878c0((::BC878C0StringArray *)(pkStrings));

    char* pcStr = ::FUN_00a7d330((*reinterpret_cast<const ::fnv_00cac6b0::NiRTTI *>(&::g_01268344)).m_pcName);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiIndex + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIndex, pcStr);

    NiPoint3 kVec;
    FUN_00cac910_shell* pkProxy = this->m_8;
    const void* pvSrc = &::DAT_01267e30;
    if (pkProxy)
    {
        this->v37();
        pvSrc = ((void *)(reinterpret_cast<::CpuObject *>((pkProxy))->FUN_00cac910()));
        this->v37();
    }
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&kVec)), (*(const ::hkVector4 *)(pvSrc)));
    pcStr = reinterpret_cast<::NiPoint3 *>(&(kVec))->FUN_00a59af0(kCac6b0Pos);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiIndex + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIndex, pcStr);

    FUN_00cac910_shell* pkProxy2 = this->m_8;
    if (pkProxy2)
    {
        this->v37();
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&kVec)), (*(const ::hkVector4 *)(reinterpret_cast<::FnvCpu_FUN_00cac950_CpuObject *>((((ProxyHolder*)pkProxy2)))->FUN_00cac950())));
        this->v37();
    }
    pcStr = reinterpret_cast<::NiPoint3 *>(&(kVec))->FUN_00a59af0(kCac6b0Vel);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiIndex + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIndex, pcStr);
}
}  // namespace fnv_00cac6b0

struct CAFBase
{
    virtual ~CAFBase();
};
struct FUN_00caff80 : CAFBase
{
    virtual ~FUN_00caff80();
};
// @fnv 0x00caff80
FUN_00caff80::~FUN_00caff80()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_0126834c;
}

// FUN_00cb0aa0: allocator-backed string dup. Takes the source string in the
// caller's edi (private convention derived for this static noinline helper):
// length via FUN_00cb10d0 (+1 for the NUL), block allocated through the task
// memory router's allocator, contents filled by FUN_00cb1090.

struct FNVTaskMemoryRouter;

extern "C" void* __cdecl AllocateWithHeader(void* allocator, unsigned int count);

struct CbobRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};

// Allocates a block of FUN_00cb10d0(s) + 1 units from the router's allocator, fills it from s via FUN_00cb1090, and returns it.
// @fnv 0x00cb0aa0
static __declspec(noinline) void* FUN_00cb0aa0(char* s)
{
    unsigned int count = (unsigned int)(::fnv_00cb10d0::FUN_00cb10d0((const char *)(s)) + 1);
    CbobRouter* router = (CbobRouter*)static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
    void* block = AllocateWithHeader(router->allocator, count);
    ::FUN_00cb1090((char *)(block), (const char *)(s));
    return block;
}

void zz_probe_call(char* s)
{
    FUN_00cb0aa0(s);
}

namespace fnv_00cb1200 {
__declspec(noinline) char ToLowerAscii(char c)
{
    if ((unsigned char)(c - 'A') <= 'Z' - 'A')
        c += 'a' - 'A';
    return c;
}

// Converts every character in pcString to its lowercase ASCII equivalent in place and returns pcString.
// @fnv 0x00cb1200
char* FUN_00cb1200(char* pcString)
{
    if (*pcString)
    {
        char* pc = pcString;
        do
        {
            *pc = ::ToLowerAscii(*pc);
            pc++;
        } while (*pc);
    }
    return pcString;
}
}  // namespace fnv_00cb1200

namespace fnv_00cb1230 {
char __declspec(noinline) ToUpperAscii(char c)
{
    if ((unsigned char)(c - 'a') <= 25u)
        c -= 32;
    return c;
}

// Converts every character of the null-terminated string s to uppercase in place and returns s.
// @fnv 0x00cb1230
char* __cdecl MakeUpperAscii(char* apString)
{
    if (*apString)
    {
        char* p = apString;
        do
        {
            *p = ::ToUpperAscii(*p);
            ++p;
        } while (*p);
    }
    return apString;
}
}  // namespace fnv_00cb1230

struct Cb1b80Arr
{
    int* m_data;
    int m_flags;
    int m_uiItemCount;
    Cb1b80Arr* FUN_00cb1b80(void* data, unsigned int size);
};

// @fnv 0x00cb1b80
Cb1b80Arr* Cb1b80Arr::FUN_00cb1b80(void* data, unsigned int size)
{
    int n = size >> 4;
    m_data = (int*)data;
    m_flags = 0x80000000;
    m_uiItemCount = n - 1;
    for (int i = 0; i < n; ++i)
    {
        int* q = m_data;
        q[4 * i] = -1;
        q[4 * i + 1] = -1;
    }
    return this;
}

// @fnv 0x00cb7620
void __cdecl FUN_00cb7620(void)
{
    FUN_00c65820();
}

extern int DAT_010c8914;

struct S00cb84f0_Obj : FUN_00c87c30
{
    int unk0c;
    S00cb84f0_Obj()
    {
        *(void**)this = (void*)&DAT_0102016c;
        unk0c = 0;
        DAT_01268154 += 1;
        *(void**)this = (void*)&DAT_0102009c;
        DAT_01268118 += 1;
        *(void**)this = (void*)&DAT_010c8914;
    }
};

// Allocates a new S00cb84f0_Obj instance and returns its pointer, or null if allocation fails.
// @fnv 0x00cb84f0
void* __cdecl FUN_00cb84f0()
{
    S00cb84f0_Obj* p = new S00cb84f0_Obj;
    if (p)
    {
        return p;
    }
    return 0;
}

void __cdecl FUN_00a6d290(void);
struct FUN_00aa4060_Class
{
};
struct FUN_00cb9260_Class
{
    void* FUN_00cb9260(unsigned char flags);
};
// Calls FUN_00a6d290, then if flags bit 0 is set and this is non-null passes the block before this to FUN_00aa4060; returns this.
// @fnv 0x00cb9260
void* FUN_00cb9260_Class::FUN_00cb9260(unsigned char flags)
{
    unsigned char* object = reinterpret_cast<unsigned char*>(this);
    void* result = this;

    FUN_00a6d290();

    if ((flags & 1) != 0 && object != 0)
    {
        unsigned int size = *(object - 1);
        void* p = object - size;
        reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<FUN_00aa4060_Class*>(&(*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager)))))->FUN_00aa4060(p);
    }

    return result;
}

// @fnv 0x00cb9910
void __cdecl FUN_00cb9910()
{
    static_cast<::FUN_00a7b330_shell *>(nullptr)->FUN_00a7b330({}, {});
}

struct FUN_00cbadb0_Dispatch
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
};
struct FUN_00cbadb0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
    virtual ~FUN_00cbadb0_Obj();

    void* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

};
// Destructor that releases the m_items array via ReleaseItems and releaseItem, then nulls m_items and the two counters.
// @fnv 0x00cbadb0
FUN_00cbadb0_Obj::~FUN_00cbadb0_Obj()
{
    if (m_items)
    {
        ::ReleaseItems((::FUN_00cba0d0_cls **)this, (uintptr_t)(m_items));
        reinterpret_cast<FUN_00cbadb0_Dispatch*>(this)->releaseItem(m_items);
        m_items = 0;
        m_pRayCursor = 0;
        m_uiItemCount = 0;
    }
}

extern int DAT_010c8d28;
struct FUN_00cbaec0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* data);
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiReservedSize;
    FUN_00cbaec0_Obj* ReleaseAndDestroy(unsigned char flags);
};
// Releases the held items, optionally deallocates this object when flags bit 0 is set, and returns this.
// @fnv 0x00cbaec0
FUN_00cbaec0_Obj* FUN_00cbaec0_Obj::ReleaseAndDestroy(unsigned char flags)
{
    void* oldData = m_pData;
    *reinterpret_cast<int**>(this) = &DAT_010c8d28;
    if (oldData)
    {
        ::ReleaseItems((::FUN_00cba0d0_cls **)this, (uintptr_t)(oldData));
        vf08(m_pData);
        m_pData = 0;
        m_uiReservedSize = 0;
        m_uiSize = 0;
    }
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct ArrayCBAF90
{
    virtual __forceinline ~ArrayCBAF90()
    {
        RemoveAll();
    }
    virtual void v04();
    virtual void Deallocate(void* pvBase);
    __forceinline void RemoveAll()
    {
        if (m_pBase)
        {
            ::ReleaseItems((::FUN_00cba0d0_cls **)this, (uintptr_t)(m_pBase));
            Deallocate(m_pBase);
            m_pBase = 0;
            m_uiAllocated = 0;
            m_uiSize = 0;
        }
    }
    void* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiAllocated;
};
struct ObjectCBAF90
{
    virtual ~ObjectCBAF90();
    int unk04;
    int unk08;
};
struct FUN_00cbaf90 : public ObjectCBAF90
{
    virtual ~FUN_00cbaf90();
    ArrayCBAF90 m_kArray;
};
// @fnv 0x00cbb130
void* FUN_00cbb130_Class::FUN_00cbb130(unsigned char flag)
{
    reinterpret_cast<::FUN_00cbaf90 *>(this)->FUN_00cbaf90::~FUN_00cbaf90();
    if ((flag & 1) != 0)
    {
        FUN_00aa1460(this, 0x1c);
    }
    return this;
}

// Destructor that releases all items in m_kArray by calling RemoveAll.
// @fnv 0x00cbaf90
FUN_00cbaf90::~FUN_00cbaf90()
{
    m_kArray.RemoveAll();
}

struct CBB050Array
{
};
struct CBB050Object
{
    int unk00;
    int unk04;
    int unk08;
    CBB050Array array;
    void FUN_00cbb050(ReadStream* stream);
};
// Calls FUN_00a7b4a0, loads a count from the stream, passes it to the array's FUN_00cbadf0, then calls stream->FUN_00a645b0 count times.
// @fnv 0x00cbb050
void CBB050Object::FUN_00cbb050(ReadStream* stream)
{
    reinterpret_cast<::NiExtraData *>(this)->LoadBinary((*(::NiStream *)(stream)));
    unsigned int count = 0;
    Load(*stream->binary, &count, 1);
    reinterpret_cast<::CBADDynamicArray *>(&(array))->FUN_00cbadf0(count, true);
    for (unsigned int i = 0; i < count; ++i)
        reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
}

void* __cdecl FUN_00aa13e0(size_t size);

struct FUN_00cbaf20_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    FUN_00cbaf20_class();
};

// Allocates a FUN_00cbaf20_class instance and assigns it the fixed string stored at DAT_011f49e0.
// @fnv 0x00cbb0c0
FUN_00cbaf20_class* CreateNamedObject()
{
    FUN_00cbaf20_class* obj = new FUN_00cbaf20_class();
    ::AssignFixedString((char *)(obj), (intptr_t)&(*(const NiFixedString*)&(*reinterpret_cast<int *>(&::DAT_011f49e0))), {});
    return obj;
}

struct FUN_00cbf540_class
{
};

struct FUN_00cbf6b0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void EnsureObjectsCreated(int v);
};

extern int(* DAT_00fdf1d0)();

// @fnv 0x00cbf6b0
void FUN_00cbf6b0_class::EnsureObjectsCreated(int v)
{
    int r = DAT_00fdf1d0();
    if (m_iThirdValue != r)
    {
        reinterpret_cast<::fnv_00cbf540::FUN_00cbf540_Owner *>((((FUN_00cbf540_class*)this)))->CreateObjects(&r, v);
    }
}


struct FUN_00cbf6e0_cls
{
    void* m_ppVirtualMethodTable;
    FUN_00cbf6e0_cls* FUN_00cbf6e0(unsigned int flags);
};

// @fnv 0x00cbf6e0
FUN_00cbf6e0_cls* FUN_00cbf6e0_cls::FUN_00cbf6e0(unsigned int flags)
{
    m_ppVirtualMethodTable = &DAT_010c925c;
    if ((flags & 1) != 0)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

struct FUN_00ca5620
{
    unsigned int m_00;
    NiPointer<RefCounted> m_pReferencedObject;
    ~FUN_00ca5620();
};
// If flag is set, destroys the owned object at m_0c, frees its allocation via DAT_011f6238.Free, and clears m_0c.
// @fnv 0x00ca5a80
void FUN_00ca5a80_cls::ReleaseOwned(bool abRelease)
{
    TlsGuard_t guard;
    unsigned int unkLocal = 0;
    if (abRelease)
    {
        Owned_t* p = m_0c;
        if (p)
        {
            reinterpret_cast<::FUN_00ca5620 *>((p))->FUN_00ca5620::~FUN_00ca5620();
            unsigned char n = GetAlignedBlockPrefix(p)->m_ucOffset;
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager))))->FUN_00aa4060((char*)p - n);
        }
        m_0c = 0;
    }
}

// Destructor that releases the held RefCounted object by nulling m_pReferencedObject.
// @fnv 0x00ca5620
FUN_00ca5620::~FUN_00ca5620()
{
    m_pReferencedObject = (RefCounted*)0;
}

#include <math.h>
#include "fnv/decl/CD4AF0Matrix3.h"
#include "fnv/decl/FUN_00a6d290.h"
#include "fnv/decl/FUN_00cc9640.h"
#include "fnv/decl/fnv_00c9eec0__FUN_00c9eec0.h"
#include "fnv/symbols_00ca5000.h"
#include "fnv/symbols_00ca8000.h"
#include "fnv/symbols_00ca9000.h"
#include "fnv/symbols_00caa000.h"
#include "fnv/symbols_00cb2000.h"
#include "fnv/symbols_00cb7000.h"
#include "fnv/symbols_00cb8000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/decl/C74C20Quat.h"
#include "fnv/decl/C89AC0_Owner.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00631100_shell.h"
#include "fnv/decl/FUN_00a5b790_cls.h"
#include "fnv/decl/FUN_00ca39a0.h"
#include "fnv/decl/FUN_00ca86c0_class.h"
#include "fnv/decl/FUN_00ca88c0_Class.h"
#include "fnv/decl/FUN_00cd9fe0_cls.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiGeometryDataRecovered.h"
#include "fnv/decl/Phantom_00cf2510.h"
#include "fnv/decl/PropertyOwner.h"
#include "fnv/decl/S006230f0_Object.h"
#include "fnv/decl/bhkRigidBody_2.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a7b000.h"
#include "fnv/symbols_00ce1000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_011b1000.h"
#include "fnv/symbols_simd.h"
namespace fnv_00ca6b60 {

struct ScopedMemContext
{
    int m_iOld;
    ScopedMemContext(int context)
    {
        m_iOld = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = context;
    }
    ~ScopedMemContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iOld;
    }
};


class NiGlobalStringTable
{
  public:
};

class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* str)
    {
        m_kHandle = ::NiGlobalStringTable::AddString(str);
    }
    ~NiFixedString()
    {
        if (m_kHandle != ::DAT_0109b220)
            InterlockedDecrement(&GetGlobalStringHeader(m_kHandle)->m_lRefCount);
    }
};

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

class NiObject
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    int m_uiRefCount;
    int unk08;
    unsigned short m_usFlags;
};

class NiTriStripsData : public NiObject
{
  public:
};

class NiAVObject
{
  public:
};

class NiTriStrips : public NiAVObject
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
    float m_fScale;
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
    NiTriStrips(NiTriStripsData* data);
};

class NiNode
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
    virtual void AttachChildInAvailableSlot(NiAVObject* child, bool firstAvail);
};


struct ShapeEntry
{
    NiObject* m_pData;
    int unk04;
};


struct StripsShape
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
    ShapeEntry* m_pEntries;
    int unk9C;
    int m_iNumEntries;
};

class bhkNiTriStripsShape
{
  public:
    int unk00;
    int unk04;
    StripsShape* m_pShape;
    void FUN_00ca6b60(NiNode* parent, intptr_t arg);
};

static inline int GetNumStrips(bhkNiTriStripsShape* shape)
{
    return (shape && shape->m_pShape) ? shape->m_pShape->m_iNumEntries : 0;
}

static inline ShapeEntry& GetStrip(bhkNiTriStripsShape* shape, int i)
{
    return (shape && shape->m_pShape) ? shape->m_pShape->m_pEntries[i] : (*reinterpret_cast<::fnv_00ca6b60::ShapeEntry *>(&::DAT_012682f0));
}

static inline bool IsTriStripsData(NiObject* obj)
{
    for (const NiRTTI* rtti = obj->GetRTTI(); rtti; rtti = rtti->m_pBaseRTTI)
    {
        if (rtti == &(*reinterpret_cast<const ::fnv_00ca6b60::NiRTTI *>(&::g_011f4a70)))
            return true;
    }
    return false;
}

// For each strip entry with NiTriStripsData, creates a NiTriStrips, sets its scale, calls SetupCollisionGeometry, and attaches it to parent.
// @fnv 0x00ca6b60
void bhkNiTriStripsShape::FUN_00ca6b60(NiNode* parent, intptr_t arg)
{
    ScopedMemContext context(0x10);
    int count = GetNumStrips(this);
    for (int i = 0; i < count; i++)
    {
        ShapeEntry& entry = GetStrip(this, i);
        NiObject* obj = entry.m_pData;
        if (obj)
        {
            NiTriStripsData* data = IsTriStripsData(obj) ? (NiTriStripsData*)obj : 0;
            if (data)
            {
                NiTriStrips* strips = new NiTriStrips(data);
                ::AssignFixedString((char *)(strips), (intptr_t)&(const ::fnv_00ca6b60::NiFixedString &)(NiFixedString("bhkNiTriStripsShape")), {});
                strips->m_fScale = fabs(::FUN_00ca6620((void *)this, {}));
                int layer = entry.m_pData ? (entry.m_pData->m_usFlags >> 6) & 0x1f : 0;
                ::AttachEmissiveMaterial((::C11F0Object *)(strips), (::C11F0Owner *)(parent), layer, (::C11F0Color *)(arg));
                parent->AttachChildInAvailableSlot(strips, true);
            }
        }
    }
}
}  // namespace fnv_00ca6b60

inline unsigned int GetMemContextC520()
{
    return ::currentAllocationContext;
}
inline void SetMemContextC520(unsigned int m_uiGeometryShaderFlags)
{
    ::currentAllocationContext = m_uiGeometryShaderFlags;
}
class AutoMemContextC520
{
  public:
    AutoMemContextC520(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC520();
        SetMemContextC520(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC520()
    {
        SetMemContextC520(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

class hkMemoryAllocatorC520
{
  public:
    virtual ~hkMemoryAllocatorC520();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterC520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorC520& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocatorC520* m_pStreamAllocator;
};

hkMemoryRouterC520* __cdecl GetMemoryRouterC520();

class BufferC520
{
  public:
    static void* operator new(std::size_t uiSize) throw()
    {
        return GetMemoryRouterC520()->heap().AllocateMemoryBlock(uiSize);
    }
    BufferC520() throw()
    {
        reinterpret_cast<::C_00c6cde0 *>(this)->FUN_00c6cde0();
    }
    void Init() throw();
    int m_aiData0;
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
};

class ConsumerC520
{
  public:
};

class BufferOwnerC520
{
  public:
    BufferC520* GetBuffer(bool* pbCreated);

    int unk00;
    int unk04;
    ConsumerC520* m_pkConsumer;
    BufferC520* m_pCacheEntry;
};

// Sets *pbCreated if m_pCacheEntry was null; then creates a BufferC520 into it, passes it to m_pkConsumer if set, and returns m_pCacheEntry.
// @fnv 0x00cac520
BufferC520* BufferOwnerC520::GetBuffer(bool* pbCreated)
{
    AutoMemContextC520 kContext(0x10);
    bool bCreate = m_pCacheEntry == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        BufferC520* pkBuffer = new BufferC520;
        m_pCacheEntry = pkBuffer;
        if (m_pkConsumer)
            reinterpret_cast<::hkpCharacterProxy *>((m_pkConsumer))->FUN_00cac9a0((*(::hkpCharacterProxyCinfo *)(pkBuffer)));
    }
    return m_pCacheEntry;
}

// FUN_00cac980: getter, 4 bytes: mov eax,[ecx+0x30]; ret
// Original index entry spans 0xcac980..0xcac993 (20 bytes): this 4-byte getter,
// 12 bytes of int3 COMDAT pad, then a byte-identical anonymous twin getter at
// 0xcac990 (mov eax,[ecx+0x30]; ret) that the pack does not index.
// Twin drafted below so a re-indexer has the neighbor shape.

struct FUN_00cac980_class
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
    void* m_30;
    void* FUN_00cac980();
};
struct FUN_00cac070_target;
struct FUN_00cac070_vtable
{
    void* slots[21];
    void (*Link)(FUN_00cac070_target*, NiStream&);
};
struct FUN_00cac070_target
{
    FUN_00cac070_vtable* vtable;
};
struct FUN_00cac070_entry
{
    char pad[0xc];
    FUN_00cac070_target* m_0c;
};

// @fnv 0x00cac070
void FUN_00cac070_Stub::FUN_00cac070(NiStream& stream)
{
    if (m_8)
    {
        FUN_00cac070_entry* r = static_cast<FUN_00cac070_entry*>(reinterpret_cast<::FUN_00cac980_class *>((m_8))->FUN_00cac980());
        if (r)
        {
            FUN_00cac070_target* obj = r->m_0c;
            if (obj)
                obj->vtable->Link(obj, stream);
        }
    }
    ::FUN_00a81fe0((intptr_t)this);
}
// @fnv 0x00cac0b0
void S_00cac0b0_cls::FUN_00cac0b0(S_00cac0b0_Arg* a)
{
    S_00cac0b0_Inner* node = 0;
    if (unk08)
        node = ((::S_00cac0b0_Inner *)(reinterpret_cast<::FUN_00cac980_class *>((unk08))->FUN_00cac980()));
    a->v0c(node ? node->unk0c : 0);
    reinterpret_cast<::BC87850RefObject *>(this)->SaveSerializeData((*(::BC87850Stream *)(a)));
}
// @fnv 0x00cac0f0
int CA0F0Object::GetResultValue()
{
    int value = 0;
    if (m_8)
    {
        CA0F0Result* result = static_cast<CA0F0Result*>(reinterpret_cast<::FUN_00cac980_class *>((m_8))->FUN_00cac980());
        if (result)
            value = result->m_8;
    }
    return value;
}
// If bAdd, calls InterlockedIncrement on the shape's refcount, else FUN_00cac410(); sets the Havok object's user data to this or null, then calls UpdateReference(bAdd).
// @fnv 0x00cac4b0
void ShapeRefCAC4B0::FUN_00cac4b0(bool bAdd)
{
    WorldObjectCAC4B0* pkObject = GetHavokObject();
    if (bAdd)
    {
        if (m_pkHavokObject)
        {
            ShapeHolderCAC4B0* pkHolder = ((::ShapeHolderCAC4B0 *)(reinterpret_cast<::FUN_00cac980_class *>((m_pkHavokObject))->FUN_00cac980()));
            if (pkHolder && pkHolder->m_pkShape)
                InterlockedIncrement((volatile long*)(&pkHolder->m_pkShape->m_iRefCount));
        }
    }
    else
    {
        ::FUN_00cac410({});
    }
    if (pkObject)
        pkObject->m_pkUserData = bAdd ? this : 0;
    reinterpret_cast<::FUN_00c899d0_Class *>(this)->ReleaseReference(bAdd);
}

// @fnv 0x00cac980
void* FUN_00cac980_class::FUN_00cac980()
{
    return m_30;
}

struct CAC980_Twin_class
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
    void* m_30;
    void* TwinGet();
};

void* CAC980_Twin_class::TwinGet()
{
    return m_30;
}

struct GetterCAC990
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
    int m_30;
    int Get();
};

// @fnv 0x00cac990
int GetterCAC990::Get()
{
    return m_30;
}

struct S00cafef0_Elem
{
    int e0;
    int e4;
    float ez;
};

struct S00cafef0_Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    float m_18;
    float m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    S00cafef0_Elem* m_30;
    float m_34;
    void UpdateBoundsFromElements();
};

// Computes min/max of element ez values over m_10*m_14 elements and stores them offset by m_34 into m_18 and m_1c.
// @fnv 0x00cafef0
void S00cafef0_Obj::UpdateBoundsFromElements()
{
    S00cafef0_Elem* p = m_30;
    if (p)
    {
        float a = p->ez;
        float b = p->ez;
        for (int i = 0; i < m_10; i++)
        {
            for (int j = 0; j < m_14; j++)
            {
                float c = p->ez;
                if (!(a < c))
                    a = c;
                if (!(b > c))
                    b = c;
                ++p;
            }
        }
        m_1c = m_34 + b;
        m_18 = m_34 + a;
    }
}

namespace fnv_00cb0b80 {
extern "C" void __cdecl FUN_00c856c0(void*, void*);
static __declspec(noinline) char* FUN_00cb0ad0(char* text, int count)
{
    int length = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(text));
    if (length > count)
        length = count;
    char* result = (char*)AllocateWithHeader(static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator, length + 1);
    ::CopyIfNonEmpty(result, text, length);
    result[length] = 0;
    return result;
}
static __declspec(noinline) void* FUN_00cb0aa0(char* text)
{
    int length = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(text)) + 1;
    void* result = AllocateWithHeader(static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator, length);
    ::FUN_00cb1090((char *)(result), (const char *)(text));
    return result;
}
struct StringSlot
{
    uintptr_t* p;
};
static __declspec(noinline) void FUN_00cb0b10(char* text, int count, StringSlot slot)
{
    uintptr_t* out = slot.p;
    uintptr_t old = *out;
    if ((old & ~(uintptr_t)1) != (uintptr_t)text)
    {
        if (old & 1)
        {
            FUN_00c856c0(static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator, (void*)(old - 1));
        }
        if (text)
        {
            if (count == -1)
                *out = TagOwnedString(FUN_00cb0aa0(text));
            else
                *out = TagOwnedString(FUN_00cb0ad0(text, count));
        }
        else
        {
            *out = ::DAT_01268358;
        }
    }
}
extern volatile int cbCount;
extern char* volatile cbText;
extern uintptr_t* volatile cbOut;
void cbAssignProbe()
{
    StringSlot slot = {cbOut};
    FUN_00cb0b10(cbText, cbCount, slot);
}
struct CBString
{
    uintptr_t m_data;
    CBString* FUN_00cb0b80(char* text);
};
// Sets m_data to the empty-string sentinel, then calls FUN_00cb0b10 to copy text into m_data and returns this.
// @fnv 0x00cb0b80
CBString* CBString::FUN_00cb0b80(char* text)
{
    m_data = ::DAT_01268358;
    StringSlot slot = {&m_data};
    FUN_00cb0b10(text, -1, slot);
    return this;
}
}  // namespace fnv_00cb0b80

namespace fnv_00cb0ba0 {
extern "C" void __cdecl FUN_00c856c0(void* allocator, void* block);
extern "C" char* __cdecl FUN_00cb0ad0(const char* text, int count);

static __declspec(noinline) void* FUN_00cb0aa0(char* s)
{
    int n = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(s)) + 1;
    void* block = AllocateWithHeader(static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator, n);
    ::FUN_00cb1090((char *)(block), (const char *)(s));
    return block;
}
void zz_probe_call(char* s)
{
    FUN_00cb0aa0(s);
}

struct StringStorageCB
{
    uintptr_t handle;
    StringStorageCB* FUN_00cb0ba0(const char* text, int count);
};

struct StringRefCB
{
    StringStorageCB* ptr;
};

__declspec(noinline) void AssignStringCB(StringRefCB ref, const char* text, int count)
{
    StringStorageCB* self = ref.ptr;
    uintptr_t old = self->handle;
    if ((old & ~(uintptr_t)1) == (uintptr_t)text)
        return;
    if (old & 1)
        FUN_00c856c0(static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator, (void*)(old - 1));
    if (text)
    {
        if (count == -1)
            self->handle = TagOwnedString(FUN_00cb0aa0((char*)text));
        else
            self->handle = TagOwnedString(FUN_00cb0ad0(text, count));
    }
    else
    {
        self->handle = ::DAT_01268358;
    }
}

static __declspec(noinline) void FUN_00cb0b10(StringRefCB ref, const char* text, int count)
{
    AssignStringCB(ref, text, count);
}

// Sets handle to DAT_01268358, then assigns text to handle via FUN_00cb0b10 and returns this.
// @fnv 0x00cb0ba0
StringStorageCB* StringStorageCB::FUN_00cb0ba0(const char* text, int count)
{
    handle = ::DAT_01268358;
    StringRefCB ref = {this};
    FUN_00cb0b10(ref, text, count);
    return this;
}
}  // namespace fnv_00cb0ba0

#ifndef _INCLUDED_MM2
#endif

struct S00cb87e0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 v10;
    __m128 v20;
    volatile float f30;
    float f34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    __forceinline S00cb87e0_Node()
    {
        f30 = ::fnv_00c88020::DAT_01016248;
        unk00 = 0;
        unk04 = 0;
        v10 = (*reinterpret_cast<const __m128 *>(&::DAT_01267e30));
        v20 = (*reinterpret_cast<const __m128 *>(&::DAT_01267e30));
        f34 = DAT_0101e2bc;
    }
    void* operator new(std::size_t size) throw()
    {
        unsigned char* raw = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>((((MemoryManager_t*)&(*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager)))))->FUN_00aa3e40(size);
        unsigned char lo = (unsigned char)(uintptr_t)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        GetAlignedBlockPrefix(raw)->m_ucOffset = pad;
        return raw;
    }
    void operator delete(void*) throw()
    {}
};

struct S00cb87e0_Guard
{
    int m_saved;
    S00cb87e0_Guard()
    {
        m_saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~S00cb87e0_Guard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_saved;
    }
};

struct S00cb87e0_Obj
{
    int unk00;
    int unk04;
    int m_08;
    S00cb87e0_Node* m_0c;
    void* GetNode(bool* out);
};

namespace fnv_00cb96c0 {
// FUN_00cb96c0: CloneSpec::Clone(void* param) - allocate 0x70, 16-align with pad byte,
// construct, run base clone-into helper, copy cloneable fields, return the new object.

struct CloneableObj
{
};



struct CloneSpec : public CloneableObj
{
    void* m_vtbl;
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
    __m128 m_u40;
    float m_f50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;

    __forceinline void* operator new(size_t size)
    {
        char* raw = (char*)reinterpret_cast<::MemoryManagerStandIn *>((((MemoryManager_t*)&::g_memoryManager)))->FUN_00aa3e40((unsigned int)size);
        unsigned char pad = 0x10 - ((unsigned char)(uintptr_t)raw & 0xF);
        raw += pad;
        GetAlignedBlockPrefix(raw)->m_ucOffset = pad;
        return raw;
    }

    __forceinline void operator delete(void* p)
    {
        unsigned char pad = GetAlignedBlockPrefix(p)->m_ucOffset;
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060((char*)p - pad);
    }

    __forceinline CloneSpec()
    {
        new ((void *)(this)) class ::FUN_00a6d220();
        m_vtbl = &(*reinterpret_cast<unsigned int *>(&::DAT_010c8a2c));
        m_u40 = *(const __m128*)&::DAT_01267e30;
        m_f50 = 0.0f;
    }

    CloneSpec* FUN_00cb96c0(void* param);
};

// Allocates a new CloneSpec, calls FUN_00a6cfe0 on this with the new object and param, then copies m_u40 and m_f50 into it and returns it.
// @fnv 0x00cb96c0
CloneSpec* CloneSpec::FUN_00cb96c0(void* param)
{
    CloneSpec* obj = new CloneSpec();
    reinterpret_cast<::NiTimeControllerCM *>(this)->FUN_00a6cfe0((::NiTimeController *)(obj), (*(::CloningProcess *)(param)));
    obj->m_u40 = m_u40;
    obj->m_f50 = m_f50;
    return obj;
}
}  // namespace fnv_00cb96c0


struct SpawnMidBase : FUN_00c87c30
{
    InitializedField unk0c;
    SpawnMidBase()
    {
        vtable = &DAT_0108febc;
        ++DAT_01268188;
    }
};

struct FUN_00cb9a10 : SpawnMidBase
{
    FUN_00cb9a10(char* source);
};

// Sets the vtable, calls SpawnAndAttach with source+4 or 0, and increments DAT_0126830c.
// @fnv 0x00cb9a10
FUN_00cb9a10::FUN_00cb9a10(char* source)
{
    vtable = &DAT_010c81ac;
    reinterpret_cast<::Dispatch_00c89dd0 *>(this)->SpawnAndAttach((intptr_t)(source ? source + 4 : 0));
    ++DAT_0126830c;
}


class CbaItem
{
  public:
    virtual ~CbaItem();
};

// Gamebryo-style array whose storage is released through its own virtual Free.
template <class T> class CbaArray
{
  public:
    virtual ~CbaArray()
    {
        RemoveAll();
    }
    virtual void* Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void* pvMem);

    void RemoveAll()
    {
        if (m_pBase)
        {
            Free(m_pBase);
            m_pBase = 0;
            m_uiMaxSize = 0;
            m_uiSize = 0;
        }
    }

    unsigned int GetSize() const
    {
        return m_uiSize;
    }
    T& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    T* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
};

class CbaString
{
  public:
    ~CbaString()
    {
        if (m_pcString != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedDecrement(&GetGlobalStringHeader(m_pcString)->m_lRefCount);
    }
    void* m_pcString;
};

class CbaBase
{
  public:
    virtual ~CbaBase();  // FUN_00a5d3d0
    unsigned int unk04;
};

class FUN_00cba1d0 : public CbaBase
{
  public:
    virtual ~FUN_00cba1d0();

    CbaString m_kName;
    CbaArray<CbaItem*> m_kUnsortedGeometryList;
    CbaArray<void*> m_kOther;
};

// Deletes each CbaItem* in m_kUnsortedGeometryList and then releases the array's storage via RemoveAll.
// @fnv 0x00cba1d0
FUN_00cba1d0::~FUN_00cba1d0()
{
    for (unsigned int i = 0; i < m_kUnsortedGeometryList.GetSize(); i++)
        delete m_kUnsortedGeometryList.GetAt(i);
    m_kUnsortedGeometryList.RemoveAll();
}

// @fnv 0x00cbb920
void __cdecl FUN_00cbb920()
{}


struct CB920Entry
{
    void* m_uiFilterValue;
    CB920Entry* m_pNext;

};

struct CB920Map
{
    void GetAt(void* key, void** out) const;
    void RemoveAt(void* key);
};


struct CB920Base
{
    virtual ~CB920Base();
};

static void CB920SetTag(int aiAllocationTag)
{
    g_tlsBlock.m_2b4 = aiAllocationTag;
}

struct CB920Guard
{
    int m_saved;

    CB920Guard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    void Leave()
    {
        CB920SetTag(m_saved);
    }

    ~CB920Guard()
    {
        Leave();
    }
};

struct FUN_00cbc920 : CB920Base
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* m_name;

    virtual ~FUN_00cbc920();
};

// Removes this object from the CB920Map entry for m_name, cleans up the entry if it becomes empty, calls Cleanup, and decrements DAT_0126841c.
// @fnv 0x00cbc920
FUN_00cbc920::~FUN_00cbc920()
{
    CB920Guard kGuard;
    if (m_name != 0)
    {
        void* pValue = 0;
        reinterpret_cast<::A54440Hash *>((void *)&(DAT_011b2190))->FUN_00a53c30((::A54440Manager *)(m_name), (::A54440Manager **)(void **)(&pValue));
        if (pValue != 0)
        {
            CB920Entry* pEntry = (CB920Entry*)pValue;
            pValue = this;
            reinterpret_cast<::FUN_00cbc810_cls *>((pEntry))->RemoveKey((unsigned int *)&(pValue));
            if (pEntry->m_pNext == 0 && pEntry->m_uiFilterValue == 0)
            {
                void* key = m_name;
                DAT_011b2190.RemoveAt(key);
                ::FUN_00b4df30((void *)(pEntry));
                reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pEntry);
            }
        }
    }
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_0126841c;
}

struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
};

struct ChainSource
{
    __m128 m_00;
    __m128 m_10;
    ChainNode* m_20;
    ChainNode* m_24;
};

struct ChainDest
{
    __m128 m_00;
    __m128 m_10;
    ChainNode* m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    ChainNode* m_48;
    int m_4c;
    int m_50[1];
};

// Copies two vectors, stores the end node of each chain in dst, and writes the second chain's m_04 values to dst->m_50 followed by -1.
// @fnv 0x00cbd700
static __declspec(noinline) void FUN_00cbd700(ChainSource* src, ChainDest* dst)
{
    dst->m_00 = src->m_00;
    dst->m_10 = src->m_10;

    ChainNode* node = src->m_20;
    while (node->m_0c)
        node = node->m_0c;
    dst->m_20 = node;

    node = src->m_24;
    while (node->m_0c)
        node = node->m_0c;
    dst->m_48 = node;

    dst->m_24 = src->m_20->m_04;
    dst->m_4c = src->m_24->m_04;

    int count = 0;
    ChainNode* n = src->m_24;
    while (n->m_0c)
    {
        n = n->m_0c;
        ++count;
    }

    ChainNode* cur = src->m_24;
    dst->m_50[count] = -1;
    for (int i = count - 1; i >= 0; i--)
    {
        dst->m_50[i] = cur->m_04;
        cur = cur->m_0c;
    }
}

void __cdecl InsertIntoContext(void* pList, void* pContext)
{
    FUN_00cbd700((ChainSource*)pList, (ChainDest*)pContext);
}

// @fnv 0x00cbf190
void __cdecl FUN_00cbf190()
{}

// Floors a float (rounds toward negative infinity) using integer bit manipulation of its IEEE-754 representation.
// @fnv 0x00cbfd80
float __cdecl FUN_00cbfd80(float value)
{
    union
    {
        float f;
        int i;
    } u;
    u.f = value;
    int x = u.i;
    int e = (((unsigned)x >> 23) & 0xff) - 127;
    int t = 23 - e;
    int ns = ~(t >> 31);
    x &= ~(((x & 0x7fffffff) - 1) >> 31);
    int mask = ((int)0xff800000 >> ((ns & 23) - (ns & t))) | ~ns;
    int sign = x >> 31;
    int frac = ~((~mask & x) - 1) & (0x800000 >> e) & sign;
    int neg = e >> 31;
    u.i = ((frac + x) & ~neg & mask) | (neg & sign & 0xbf800000);
    return u.f;
}

extern double DAT_010c92f8;
extern double DAT_010c92f0;
// Polynomial approximation of atan2 with x as numerator and y as denominator, adjusted using the signs of y and x.
// @fnv 0x00cbff80
float __cdecl Atan2(float x, float y)
{
    float ax = (float)fabs(x);
    float ay = (float)fabs(y);
    float t, result;
    if (ax <= ay)
    {
        t = ax / (float)(ay + DAT_010c9300);
        float tCopy = t;
        float partial = tCopy - (t * DAT_010c92f8) * t;
        result = partial - t * (t * (t * DAT_010c92f0));
    }
    else
    {
        t = ay / (float)(ax + DAT_010c9300);
        float tCopy = t;
        float partial = tCopy - (t * DAT_010c92f8) * t;
        result = partial - t * (t * (t * DAT_010c92f0));
        result = (float)(DAT_01030f38 - result);
    }
    if (y < 0.0f)
        result = (float)(DAT_0101ff40 - result);
    if (x < 0.0f)
        result = -result;
    return result;
}

namespace fnv_00ca3b00 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00ca3b00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00ca3b00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ca3b00
    virtual void FUN_00ca3b00();
};

Derived::Derived()
{}
}  // namespace fnv_00ca3b00

namespace fnv_00ca4510 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00ca4510();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00ca4510();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ca4510
    virtual void FUN_00ca4510();
};

Derived::Derived()
{}
}  // namespace fnv_00ca4510

extern int DAT_010c771c;

struct ScopeHost_cls
{
    void* m_vptr;
    void FUN_00cd2de0();
    void FUN_00ca6590();
};

struct OwnerGuard_cls
{
    ScopeHost_cls* m_pOwnerObject;
    OwnerGuard_cls(ScopeHost_cls* owner)
    {
        m_pOwnerObject = owner;
        owner->m_vptr = &DAT_010c771c;
    }
    ~OwnerGuard_cls()
    {
        reinterpret_cast<::FUN_00cd2de0 *>((m_pOwnerObject))->FUN_00cd2de0::~FUN_00cd2de0();
    }
};

// Sets a guard on this (sets the vtable pointer, calls FUN_00cd2de0 on exit), calls FUN_00c876a0, and decrements g_fnvDecompCounter.
// @fnv 0x00ca6590
void ScopeHost_cls::FUN_00ca6590()
{
    OwnerGuard_cls guard(this);
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --::DAT_012682e4;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00ca6780_sub
{
    unsigned int unk00;
    int m_04;
    int(__cdecl* m_08)(void* a, volatile unsigned int* b, unsigned int c, unsigned int d, unsigned int e);
};

struct FUN_00ca6780_arg
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
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned short unk1E6;
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
    FUN_00ca6780_sub* m_24c;
};

struct FUN_00ca6780_cls
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
    virtual int v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* v2D(unsigned char* out);
    int FUN_00ca6780(FUN_00ca6780_arg* a1);
};

// @fnv 0x00ca6780
int FUN_00ca6780_cls::FUN_00ca6780(FUN_00ca6780_arg* a1)
{
    unsigned char owned;
    volatile unsigned int* p = v2D(&owned);
    int size = v2A();
    if (a1->unk04 < 4)
    {
        size -= 0x10;
    }
    FUN_00ca6780_sub* sub = a1->m_24c;
    sub->m_04 += sub->m_08(sub, p, size, 0, 0);
    if (a1->m_1e5 != 1 && a1->unk04 >= 4)
    {
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
    }
    return size;
}

struct BlockData
{
    __m128 position;
    __m128 rotation;
};
struct Command
{
    unsigned char type;
    void* owner;
    BlockData* data;
};
struct QueueCA8960
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
};
struct AllocCA8960
{
    virtual void v00();
    virtual BlockData* Allocate(unsigned int bytes);
};
struct FUN_00ca8960_Class
{
    int unk00;
    int unk04;
    QueueCA8960* queue08;
    void EnqueueTransform(const __m128* position, const __m128* rotation);
};
// If queue08 is set and its unk94 is nonzero, queues a type 0x18 command holding position and rotation; otherwise calls FUN_00ca8860 with them.
// @fnv 0x00ca8960
void FUN_00ca8960_Class::EnqueueTransform(const __m128* position, const __m128* rotation)
{
    if (queue08 && queue08->unk94)
    {
        Command cmd;
        cmd.type = 0x18;
        cmd.owner = this;
        FNVTaskMemoryRouter* router = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
        cmd.data = ((AllocCA8960*)router->allocator)->Allocate(32);
        cmd.data->position = *position;
        cmd.data->rotation = *rotation;
        reinterpret_cast<::WorldWithPending *>((queue08))->FUN_00c91160();
    }
    else
        reinterpret_cast<::FUN_00ca8860_cls *>(this)->FUN_00ca8860((intptr_t)(position), (intptr_t)(rotation));
}

namespace fnv_00cabf30 {
// sub ecx,8; jmp FUN_00cac120  ==  MSVC adjustor thunk for a secondary base at offset 8.
struct PrimaryBase
{
    virtual void FUN_00cabf30();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00cabf30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cabf30
    virtual void FUN_00cabf30();
};

Derived::Derived()
{}
}  // namespace fnv_00cabf30

// Adjustor thunk for FUN_00cabf40: sub ecx,0xc; jmp FUN_00cac120.
// Primary base sized 12 (vptr + 8 pad) so the secondary->primary
// this adjustment is exactly 0xc.

struct Prim_00cabf40
{
    virtual void FUN_00cabf40();
    int m04;
    int m08;
};

struct Sec_00cabf40
{
    virtual void FUN_00cabf40();
};

struct TO_00cabf40 : Prim_00cabf40, Sec_00cabf40
{
// @fnv 0x00cabf40
    virtual void FUN_00cabf40();
};

// Forces vtable emission: the override lands in both the primary and the
// secondary vftable, so VC9 emits [thunk]:TO_00cabf40::FUN_00cabf40
// 'adjustor{12}' = sub ecx,0xc ; jmp TO_00cabf40::FUN_00cabf40.
static TO_00cabf40 g_thunk_00cabf40;

struct CAC410_TLSState
{
    char m_ucUnknownByte[0x2B4];
    int m_uiFilterValue;
};

__declspec(thread) CAC410_TLSState g_CAC410_TLSState;

struct CAC410_RefCounted
{
    virtual void Dummy();
    virtual void Release();
    volatile LONG m_lRefCount;
};

struct CAC410_Owner
{
    void* unk00;
    void* unk04;
    struct FUN_00cac980_Holder* m_08;
};

struct FUN_00cac980_Result
{
    void* m_vtbl;
    int m_iWordAt04;
    int m_8;
    CAC410_RefCounted* m_iThirdValue;
};

struct CAC410_ScopedValue
{
    int m_oldValue;

    CAC410_ScopedValue() : m_oldValue((*reinterpret_cast<::CAC410_TLSState *>(&::g_tlsBlock)).m_uiFilterValue)
    {
        (*reinterpret_cast<::CAC410_TLSState *>(&::g_tlsBlock)).m_uiFilterValue = 0x10;
    }

    ~CAC410_ScopedValue()
    {
        (*reinterpret_cast<::CAC410_TLSState *>(&::g_tlsBlock)).m_uiFilterValue = m_oldValue;
    }
};

// Sets a scoped TLS value to 0x10, calls FUN_00cac980 on the holder at pThis+8, and drops one reference on the object in its result.
// @fnv 0x00cac410
void FUN_00cac410(void* pThis)
{
    CAC410_ScopedValue scopedValue;

    FUN_00cac980_Holder* holder = static_cast<CAC410_Owner*>(pThis)->m_08;

    if (holder)
    {
        void* result = reinterpret_cast<::FUN_00cac980_class *>((holder))->FUN_00cac980();
        if (result)
        {
            CAC410_RefCounted* object = static_cast<FUN_00cac980_Result*>(result)->m_iThirdValue;

            if (object)
            {
                if (InterlockedDecrement(&object->m_lRefCount) == 0)
                {
                    object->Release();
                }
            }
        }
    }
}

void CB0Free(void* p);
int CB0Len(const char* s);

struct CB0StringPtr
{
    uintptr_t m_pcText;
    CB0StringPtr(const CB0StringPtr& other);
    const char* cString() const
    {
        return (const char*)(m_pcText & ~(uintptr_t)1);
    }
};

struct CB0SelfRef
{
    CB0StringPtr* p;
};
static __declspec(noinline) void FUN_00cb0b10(CB0SelfRef selfRef, const char* s, int len)
{
    CB0StringPtr* self = selfRef.p;
    if (len == -1)
        len = CB0Len(s);
    self->m_pcText = (uintptr_t)s + len;
}

// Sets m_pcText to DAT_01268358, then calls FUN_00cb0b10 with other's string and length -1, which stores the string's end pointer in m_pcText.
// @fnv 0x00cb0bd0
CB0StringPtr::CB0StringPtr(const CB0StringPtr& other)
{
    m_pcText = DAT_01268358;
    CB0SelfRef r;
    r.p = this;
    FUN_00cb0b10(r, other.cString(), -1);
}

struct CC3320Info
{
    unsigned int unk00, unk04, unk08, unk0c;
    __m128 vec10, vec20;
    float out30, out34;
};
struct CC3320Source
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    __m128 vec20, vec30;
    unsigned int unk40, unk44, unk48, unk4c;
    float value50, value54;
};
struct CC3320Base
{
    int unk00;
    void GetInfo(CC3320Info* info);
};
struct FUN_00cb84a0_cls : CC3320Base
{
    int unk04;
    CC3320Source* src08;
    void FUN_00cb84a0(CC3320Info* info);
};
// Ensures m_0c points to a valid S00cb87e0_Node, allocating and initializing one if null, and sets *out to true when a new node was created.
// @fnv 0x00cb87e0
void* S00cb87e0_Obj::GetNode(bool* abCreated)
{
    S00cb87e0_Guard guard;
    bool empty = (m_0c == 0);
    *abCreated = empty;
    if (empty)
    {
        unsigned char* raw = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>((((MemoryManager_t*)&(*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager)))))->FUN_00aa3e40(sizeof(S00cb87e0_Node));
        double defaultScale = ::fnv_00c88020::DAT_01016248;
        unsigned char low = (unsigned char)(uintptr_t)raw;
        low &= 0x0f;
        unsigned char padding = 0x10;
        padding -= low;
        raw += padding;
        GetAlignedBlockPrefix(raw)->m_ucOffset = padding;
        S00cb87e0_Node* p = (S00cb87e0_Node*)raw;
        p->unk00 = 0;
        p->unk04 = 0;
        p->v10 = (*reinterpret_cast<const __m128 *>(&::DAT_01267e30));
        p->v20 = (*reinterpret_cast<const __m128 *>(&::DAT_01267e30));
        p->f30 = defaultScale;
        p->f34 = DAT_0101e2bc;
        m_0c = p;
        if (m_08)
            reinterpret_cast<::FUN_00cb84a0_cls *>(this)->FUN_00cb84a0((::CC3320Info *)(p));
    }
    return m_0c;
}
// Calls GetInfo, then copies vec20, vec30, value50 and value54 from src08 into info's vec10, vec20, out30 and out34.
// @fnv 0x00cb84a0
void FUN_00cb84a0_cls::FUN_00cb84a0(CC3320Info* info)
{
    reinterpret_cast<::FUN_00c867d0_cls *>(this)->FUN_00c867d0((::FUN_00c867d0_out *)(info));
    CC3320Source* src = this ? src08 : 0;
    info->vec10 = src->vec20;
    info->vec20 = src->vec30;
    info->out30 = src->value50;
    info->out34 = src->value54;
}

struct S00cb8590_Out
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
};

struct S00cb8590_Obj
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
    int unk1e0;
    unsigned char unk1e4;
    unsigned char unk1e5;
};


struct S00cb8590_cls
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
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
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
    virtual void v1a()
    {}
    virtual void v1b()
    {}
    virtual void v1c()
    {}
    virtual void v1d()
    {}
    virtual void v1e()
    {}
    virtual void v1f()
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
    virtual void v2a()
    {}
    virtual void v2b()
    {}
    virtual void v2c()
    {}
    virtual S00cb8590_Out* vfn2d(S00cb8590_Obj** pp)
    {
        return 0;
    }
    void FUN_00cb8590(int a0);
};
static __forceinline void S00cb8590_swapAll(S00cb8590_Out* p)
{
    p->unk10 = _byteswap_ulong(p->unk10);
    _ReadWriteBarrier();
    p->unk14 = _byteswap_ulong(p->unk14);
    _ReadWriteBarrier();
    p->unk18 = _byteswap_ulong(p->unk18);
    _ReadWriteBarrier();
    p->unk1c = _byteswap_ulong(p->unk1c);
    _ReadWriteBarrier();
    p->unk20 = _byteswap_ulong(p->unk20);
    _ReadWriteBarrier();
    p->unk24 = _byteswap_ulong(p->unk24);
    _ReadWriteBarrier();
    p->unk28 = _byteswap_ulong(p->unk28);
    _ReadWriteBarrier();
    p->unk2c = _byteswap_ulong(p->unk2c);
    _ReadWriteBarrier();
    p->unk30 = _byteswap_ulong(p->unk30);
    _ReadWriteBarrier();
    p->unk34 = _byteswap_ulong(p->unk34);
    _ReadWriteBarrier();
}

// Calls FUN_00c86790 on the object; unless its unk1e5 is 1, byte-swaps the ten 32-bit fields at 0x10-0x34 of the vfn2d result.
// @fnv 0x00cb8590
void S00cb8590_cls::FUN_00cb8590(int apObj)
{
    S00cb8590_Obj* o = reinterpret_cast<S00cb8590_Obj*>(*(volatile int*)&apObj);
    reinterpret_cast<::fnv_00c86790::Holder *>((o))->FUN_00c86790({});
    if (o->unk1e5 != 1)
    {
        S00cb8590_swapAll(vfn2d(reinterpret_cast<S00cb8590_Obj**>(&apObj)));
    }
}

struct FUN_00c868b0_Obj
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
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
};

struct FUN_00cb8610_Class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}

    virtual void FUN_00cb8610(void* arg);

    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}

    virtual FUN_00c868b0_Obj* vfB4(unsigned char* value);

};

// If the byte at arg+0x1E4 is not 1, byte-swaps ten fields of the vfB4 result before and after calling FUN_00c868b0(arg).
// @fnv 0x00cb8610
void FUN_00cb8610_Class::FUN_00cb8610(void* arg)
{
    unsigned char value;
    FUN_00c868b0_Obj* result = vfB4(&value);

    if (static_cast<NiStreamFields*>(arg)->m_ucSourceByteOrder != 1)
    {
        result->unk10 = _byteswap_ulong(result->unk10);
        _ReadWriteBarrier();
        result->unk14 = _byteswap_ulong(result->unk14);
        _ReadWriteBarrier();
        result->unk18 = _byteswap_ulong(result->unk18);
        _ReadWriteBarrier();
        result->unk1C = _byteswap_ulong(result->unk1C);
        _ReadWriteBarrier();
        result->unk20 = _byteswap_ulong(result->unk20);
        _ReadWriteBarrier();
        result->unk24 = _byteswap_ulong(result->unk24);
        _ReadWriteBarrier();
        result->unk28 = _byteswap_ulong(result->unk28);
        _ReadWriteBarrier();
        result->unk2C = _byteswap_ulong(result->unk2C);
        _ReadWriteBarrier();
        result->unk30 = _byteswap_ulong(result->unk30);
        _ReadWriteBarrier();
        result->unk34 = _byteswap_ulong(result->unk34);
    }

    reinterpret_cast<::FUN_00c868b0_cls *>(this)->FUN_00c868b0((::C868_Iface *)(arg));

    if (static_cast<NiStreamFields*>(arg)->m_ucSourceByteOrder != 1)
    {
        result->unk10 = _byteswap_ulong(result->unk10);
        _ReadWriteBarrier();
        result->unk14 = _byteswap_ulong(result->unk14);
        _ReadWriteBarrier();
        result->unk18 = _byteswap_ulong(result->unk18);
        _ReadWriteBarrier();
        result->unk1C = _byteswap_ulong(result->unk1C);
        _ReadWriteBarrier();
        result->unk20 = _byteswap_ulong(result->unk20);
        _ReadWriteBarrier();
        result->unk24 = _byteswap_ulong(result->unk24);
        _ReadWriteBarrier();
        result->unk28 = _byteswap_ulong(result->unk28);
        _ReadWriteBarrier();
        result->unk2C = _byteswap_ulong(result->unk2C);
        _ReadWriteBarrier();
        result->unk30 = _byteswap_ulong(result->unk30);
        _ReadWriteBarrier();
        result->unk34 = _byteswap_ulong(result->unk34);
    }
}

// bhkRagdollTemplate::bhkRagdollTemplate @ 0xcbaf20 (84 bytes)
// ctor: NiExtraData base ctor (0xa7b2e0), derived vftable (0x10c8dcc), then member
// BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> (vftable 0x10c8d28 + three
// zero stores) constructed inline; returns this.
// The original carries a dead /GS+EH unwind-only registration frame (FuncInfo
// optimizer folded away, and the c1 EH scope (unwind funclet destroys the base
// subobject) survived as stale weight.

// base NiExtraData: named after its ctor's address so the implicit base-ctor
// call binds to 0xa7b2e0
struct FUN_00a7b2e0
{
    virtual void v0();
    unsigned int unk04;
    unsigned int unk08;
    FUN_00a7b2e0();
    ~FUN_00a7b2e0();
};

struct AryType
{  // BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> stand-in
    virtual void v0();
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
    AryType();
};

class FUN_00cbaf20 : public FUN_00a7b2e0
{
  public:
    AryType m_data;
    FUN_00cbaf20();
};

AryType::AryType()
{
    if (0)
        throw 1;
    m_pData = 0;
    m_uiSize = 0;
    m_uiMaxSize = 0;
}

// Default constructor for FUN_00cbaf20; the body is empty and the base class and m_data member are default-constructed implicitly.
// @fnv 0x00cbaf20
FUN_00cbaf20::FUN_00cbaf20()
{}

struct SearchNodeCB
{
    int unk00;
    unsigned int id;
    int unk08;
    SearchNodeCB* parent;
};

struct InputCB
{
    __m128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* first;
    SearchNodeCB* second;
};

struct OutputCB
{
    __m128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* firstRoot;
    unsigned int firstId;
    int unk28_0;
    int unk28_1;
    int unk28_2;
    int unk28_3;
    int unk28_4;
    int unk28_5;
    int unk28_6;
    int unk28_7;
    SearchNodeCB* secondRoot;
    unsigned int secondId;
    unsigned int secondPath[8];
};

struct ContextCB
{
    int unk00;
    float limit;
    OutputCB* begin;
    OutputCB* next;
    int capacity;
    int size;
};

static __declspec(noinline) void CopyCB(OutputCB* dest, const InputCB* src)
{
    dest->point = src->point;
    *(__m128*)&dest->x = *(__m128 const*)&src->x;
    SearchNodeCB* c = src->first;
    while (c->parent)
        c = c->parent;
    dest->firstRoot = c;
    c = src->second;
    while (c->parent)
        c = c->parent;
    dest->secondRoot = c;
    dest->firstId = src->first->id;
    dest->secondId = src->second->id;
    SearchNodeCB* h = src->second;
    int count = 0;
    SearchNodeCB* n = h->parent;
    while (n)
    {
        n = n->parent;
        ++count;
    }
    dest->secondPath[count] = 0xffffffff;
    int i = count - 1;
    while (i >= 0)
    {
        dest->secondPath[i] = h->id;
        h = h->parent;
        --i;
    }
}

// Adds input to context, or when full replaces the highest-score entry if input's score is lower, then sets context->limit to the highest remaining score.
// @fnv 0x00cbd7a0
void __cdecl InsertIntoContext(const InputCB* input, ContextCB* context)
{
    if (context->capacity)
    {
        if (context->size < context->capacity)
        {
            CopyCB(context->next, input);
            ++context->size;
            ++context->next;
            return;
        }
        OutputCB* end = context->begin + context->size;
        OutputCB* cur = context->begin;
        OutputCB* best = cur++;
        __assume(cur < end);
        for (; cur < end; ++cur)
            if (cur->score > best->score)
                best = cur;
        if (input->score < best->score)
        {
            CopyCB(best, input);
            cur = context->begin;
            best = cur++;
            __assume(cur < end);
            for (; cur < end; ++cur)
                if (cur->score > best->score)
                    best = cur;
        }
        context->limit = best->score;
    }
}

struct FUN_00cbda30_io;

struct FUN_00cbda30_io
{
    unsigned int unk00;
    unsigned int m04;
    unsigned int(__cdecl* m08)(FUN_00cbda30_io*, void*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00cbda30_arg
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
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
    char unk1E6;
    char unk1E7;
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
    FUN_00cbda30_io* m24C;
};

struct FUN_00cbda30_rec
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
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};

struct FUN_00cbda30_obj
{
    char pad[0x20];
    FUN_00cbda30_rec m_kFirst;
    FUN_00cbda30_rec m_kSecond;
};

struct FUN_00cbda30_cls
{
    virtual void v00()
    {}
    FUN_00cbda30_obj* m04;
    void ReadRecord(FUN_00cbda30_arg* a1);
};

void SwapEndianBlocks(void* p);

extern "C" void _ReadWriteBarrier(void);
unsigned int* __cdecl SwapEndianBlocks(unsigned int* arg);

// Calls FUN_00c8a230, reads the two 0x40-byte blocks of m04 via a1->m24C, and byte-swaps them unless a1->m1E5 is 1.
// @fnv 0x00cbda30
void FUN_00cbda30_cls::ReadRecord(FUN_00cbda30_arg* a1)
{
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((*(::NiStream *)(a1)));
    FUN_00cbda30_obj* obj = m04;
    FUN_00cbda30_io* io = a1->m24C;
    FUN_00cbda30_rec* b = &obj->m_kFirst;
    io->m04 += io->m08(io, b, 0x40, 0, 0);
    io = a1->m24C;
    FUN_00cbda30_rec* q = &obj->m_kSecond;
    io->m04 += io->m08(io, q, 0x40, 0, 0);
    FUN_00cbda30_rec* p = q;
    if (a1->m1E5 != 1)
    {
        b->m30 = _byteswap_ulong(b->m30);
        _ReadWriteBarrier();
        b->m34 = _byteswap_ulong(b->m34);
        _ReadWriteBarrier();
        b->m38 = _byteswap_ulong(b->m38);
        _ReadWriteBarrier();
        b->m3C = _byteswap_ulong(b->m3C);
        SwapEndianBlocks((unsigned int*)b);
        p->m30 = _byteswap_ulong(p->m30);
        _ReadWriteBarrier();
        p->m34 = _byteswap_ulong(p->m34);
        _ReadWriteBarrier();
        p->m38 = _byteswap_ulong(p->m38);
        _ReadWriteBarrier();
        p->m3C = _byteswap_ulong(p->m3C);
        SwapEndianBlocks((unsigned int*)p);
    }
}

struct CA3F10MemMgr
{
    void* Allocate(unsigned int size);
};

struct CA3F10BinaryStream
{
    void* unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CA3F10BinaryStream* pkStream, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

struct CA3F10Stream
{
    void* unk00;
    unsigned int m_uiFormatVersion;
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
    CA3F10BinaryStream* m_pUnderlyingStream;
};

template <class T> inline unsigned int CA3F10LoadBinary(CA3F10BinaryStream& kStream, T& val)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(&val, sizeof(T), &uiSize, 1);
}

extern unsigned int DAT_011b1750[];
extern unsigned int DAT_011b1754[];

struct CA3F10Triangle
{
    unsigned int uiVerts01;
    unsigned int uiVert2Welding;
};

struct CA3F10OldTriangle
{
    CA3F10Triangle kTri;
    float f08;
    float f0c;
    float f10;
};

struct CA3F10Vertex
{
    float x;
    float y;
    float z;
    CA3F10Vertex()
    {}
};

struct CA3F10Normal
{
    float x;
    float y;
    float z;
};

struct CA3F10Data
{
    int unk00;
    int unk04;
    unsigned int m_uiTriangles;
    unsigned int m_uiVertices;
    unsigned short m_usNormals;
    unsigned short unk12;
    CA3F10Triangle* m_pkTriangles;
    CA3F10Vertex* m_pkVertices;
    int unk1c;
    int unk20;
    CA3F10Normal* m_pkNormals;

    void FUN_00ca3f10(CA3F10Stream* pkStream);
};

// Reads triangle, vertex, and normal data from a CA3F10Stream, handling format version differences for triangle and vertex reading.
// @fnv 0x00ca3f10
void CA3F10Data::FUN_00ca3f10(CA3F10Stream* pkStream)
{
    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_uiTriangles);
    m_pkTriangles = new CA3F10Triangle[m_uiTriangles];
    if (pkStream->m_uiFormatVersion < 0x21)
    {
        for (unsigned int i = 0; i < m_uiTriangles; i++)
        {
            CA3F10OldTriangle kOld;
            pkStream->m_pUnderlyingStream->BinaryRead(&kOld, sizeof(kOld), DAT_011b1754, 7);
            CA3F10Triangle& kTri = m_pkTriangles[i];
            kTri.uiVerts01 = kOld.kTri.uiVerts01;
            kTri.uiVert2Welding = kOld.kTri.uiVert2Welding;
        }
    }
    else
    {
        pkStream->m_pUnderlyingStream->BinaryRead(m_pkTriangles, m_uiTriangles * sizeof(CA3F10Triangle), DAT_011b1754,
                                                  4);
    }

    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_uiVertices);
    if (pkStream->m_uiFormatVersion >= 0x22)
    {
        CA3F10BinaryStream* pkIstr = pkStream->m_pUnderlyingStream;
        unsigned int (*pfnRead)(CA3F10BinaryStream*, void*, unsigned int, unsigned int*, unsigned int) =
            pkIstr->m_pfnRead;
        bool bUnused;
        unsigned int uiSize = 1;
        unsigned int uiRead = pfnRead(pkIstr, &bUnused, 1, &uiSize, 1);
        pkIstr->m_uiStreamFlags += uiRead;
        CA3F10Vertex* pkVerts = new CA3F10Vertex[m_uiVertices];
        unsigned int uiBytes = m_uiVertices * sizeof(CA3F10Vertex);
        m_pkVertices = pkVerts;
        pkStream->m_pUnderlyingStream->BinaryRead(pkVerts, uiBytes, DAT_011b1750, 1);
    }
    else
    {
        CA3F10Vertex* pkVerts = new CA3F10Vertex[m_uiVertices];
        unsigned int uiBytes = m_uiVertices * sizeof(CA3F10Vertex);
        m_pkVertices = pkVerts;
        pkStream->m_pUnderlyingStream->BinaryRead(pkVerts, uiBytes, DAT_011b1750, 1);
    }

    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_usNormals);
    m_pkNormals = new CA3F10Normal[m_usNormals];
    pkStream->m_pUnderlyingStream->BinaryRead(m_pkNormals, m_usNormals * sizeof(CA3F10Normal), DAT_011b1750, 1);
}

struct Alloc9bd0
{
    virtual void R();
    virtual void* Allocate(unsigned int);
};
extern "C" int DAT_010c82ec;
struct Rec9bd0;
struct Router9bd0
{
    int a[4];
    Alloc9bd0* allocator;
    Alloc9bd0& heap()
    {
        return *allocator;
    }
};
struct Sub9bd0
{
    int v;
};
struct Item9bd0
{
};
struct Rec9bd0
{
    void* vt;
    unsigned short cap, fl;
    int pad[2];
    Sub9bd0 sub;
    int pad2[2];
    float score;
    void FUN_00ca9aa0();
    static void* operator new(std::size_t size)
    {
        Rec9bd0* m = (Rec9bd0*)((Router9bd0*)static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750()))->heap().Allocate(size);
        m->cap = (unsigned short)size;
        return m;
    }
    static void operator delete(void*);
    Rec9bd0()
    {
        new ((void *)this) ::FUN_00ca9aa0();
        vt = &DAT_010c82ec;
    }
};
struct Ctx9bd0
{
    int a, b, c;
    void* coll;
    int d[3];
    float score;
};
struct Key9bd0
{
    intptr_t value;
};
struct Owner9bd0
{
    int u;
    Ctx9bd0* ctx;
    void FUN_00ca9bd0(Rec9bd0* r, Key9bd0 key);
};
extern "C" void _ReadWriteBarrier();
// Uses r or allocates a Rec9bd0, attaches an item made by CreateF4A30Result from ctx->coll and key, copies ctx->score, then calls ReleaseObject(rec, key).
// @fnv 0x00ca9bd0
void Owner9bd0::FUN_00ca9bd0(Rec9bd0* apRecord, Key9bd0 key)
{
    TlsGuard_t s;
    Ctx9bd0* c = ctx;
    Rec9bd0* rec = apRecord;
    if (rec == 0)
        rec = new Rec9bd0;
    void* coll = c->coll;
    intptr_t k = *(volatile intptr_t*)&key.value;
    _ReadWriteBarrier();
    Item9bd0* pItem = coll ? ((::Item9bd0 *)(::CreateF4A30Result((::F4A30Node *)(coll), (void *)(k)))) : 0;
    if (pItem)
    {
        reinterpret_cast<::FUN_00ca9b40_class *>((rec))->FUN_00ca9b40((::ObjectRef *)(pItem));
        reinterpret_cast<::hkReferencedObjectC905 *>((pItem))->FUN_00c905b0();
    }
    float sc = c->score;
    rec->score = sc;
    reinterpret_cast<::FUN_00d21ce0_cls *>(&(rec->sub))->FUN_00d21ce0(rec);
    reinterpret_cast<::FUN_009ba5f0_shell *>(this)->ReleaseObject((::hkReferencedObject *)(rec), k);
}

// 0x00cabcd0  340 B  /MT /O2 /GS /EHsc /Gy  - HSV ramp helper.
struct ColorOutput
{
    float* value;
};

// Converts HSV color components to RGB, writing the result to pR, pG, and out1, with a special case for zero saturation.
// @fnv 0x00cabcd0
static __declspec(noinline) void HsvToRgb(float* apRed, float afHue, float afSaturation, float afValue, float* apGreen,
                                          float* apBlue)
{
    (void)apBlue;
    (void)apGreen;
    float*& red = apRed;
    float p, q, t, f;
    int i;
    if (afSaturation == 0.0f)
    {
        *apBlue = afValue;
        *apGreen = afValue;
        *red = afValue;
        return;
    }
    if (afHue == 1.0f)
    {
        i = 5;
        afHue = 6.0f;
    }
    else
    {
        afHue = afHue * 6.0;
        i = (int)(float)std::floor(afHue);
    }
    f = afHue - i;
    p = afValue * (1.0f - afSaturation);
    q = afValue * (1.0f - afSaturation * f);
    t = afValue * (1.0f - afSaturation * (1.0f - f));
    switch (i)
    {
    case 0:
        *red = afValue;
        *apGreen = t;
        *apBlue = p;
        break;
    case 1:
        *red = q;
        *apGreen = afValue;
        *apBlue = p;
        break;
    case 2:
        *red = p;
        *apGreen = afValue;
        *apBlue = t;
        break;
    case 3:
        *red = p;
        *apGreen = q;
        *apBlue = afValue;
        break;
    case 4:
        *red = t;
        *apGreen = p;
        *apBlue = afValue;
        break;
    default:
        *red = afValue;
        *apGreen = p;
        *apBlue = q;
        break;
    }
}

void CallerHsv9(float* a, float h, float s, float v, float* r, float* g)
{
    HsvToRgb(a, h, s, v, g, r);
}

static inline float hkFloor(float x)
{
    return (float)floor((double)x);
}

static __declspec(noinline) void S00cabcd0_HSV(float* b, float h, float s, float v, float* g, float* r)
{
    float* const* pb = &b;
    volatile float* vp = b;
    (void)vp;
    (void)pb;
    int i;
    float f, p, q, t;
    if (s == 0.0f)
    {
        *r = *g = *b = v;
        return;
    }
    if (h == 1.0f)
    {
        i = 5;
        h = 6.0f;
    }
    else
    {
        h = h * 6.0;
        i = (int)hkFloor(h);
    }
    f = h - i;
    p = v * (1.0f - s);
    q = v * (1.0f - s * f);
    t = v * (1.0f - s * (1.0f - f));
    switch (i)
    {
    case 0:
        *r = v;
        *g = t;
        *b = p;
        break;
    case 1:
        *r = q;
        *g = v;
        *b = p;
        break;
    case 2:
        *r = p;
        *g = v;
        *b = t;
        break;
    case 3:
        *r = p;
        *g = q;
        *b = v;
        break;
    case 4:
        *r = t;
        *g = p;
        *b = v;
        break;
    default:
        *r = v;
        *g = p;
        *b = q;
        break;
    }
}

// Converts h, s, v to RGB with S00cabcd0_HSV and returns PackColorBigEndian called with the three results (c.b, c.g, c.r) and a.
// @fnv 0x00cabe30
unsigned int __cdecl FUN_00cabe30(float h, float s, float v, float afAlpha)
{
    struct C
    {
        float r, g, b;
    } c;
    S00cabcd0_HSV(&c.b, h, s, v, &c.g, &c.r);
    return PackColorBigEndian(c.b, c.g, c.r, afAlpha);
}

extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" void _ReadWriteBarrier();
void __cdecl FUN_00c856c0(void*, void*);
static __declspec(noinline) void* FUN_00cb0ad0(char* s, int maxLen)
{
    int len = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(s));
    if (len > maxLen)
        len = maxLen;
    char* p = (char*)AllocateWithHeader(static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->allocator, len + 1);
    ::CopyIfNonEmpty(p, s, len);
    p[len] = 0;
    return p;
}
struct StringSlot
{
    uintptr_t* volatile p;
};
// Frees the slot's old string if its low bit is set, then stores a tagged copy of s (length-limited unless len is -1), or DAT_01268358 when s is null.
// @fnv 0x00cb0b10
static __declspec(noinline) void FUN_00cb0b10(StringSlot slotRef, char* apString, int aiLength)
{
    uintptr_t* slot = slotRef.p;
    uintptr_t cur = *slot;
    if ((char*)(cur & ~(uintptr_t)1) == apString)
        return;
    if (cur & 1)
    {
        char* old = (char*)(cur - 1);
        FNVTaskMemoryRouter* r = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
        if (old)
            _ReadWriteBarrier();
        else
            _ReadWriteBarrier();
        FUN_00c856c0(r->allocator, old);
    }
    if (apString)
    {
        if (aiLength == -1)
        {
            *slot = TagOwnedString(FUN_00cb0aa0(apString));
            return;
        }
        *slot = TagOwnedString(FUN_00cb0ad0(apString, aiLength));
        return;
    }
    *slot = DAT_01268358;
}
void StringSetCaller(uintptr_t* slot, char* s, int len)
{
    StringSlot r = {slot};
    FUN_00cb0b10(r, s, len);
}

struct S_ca4520_Entry
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
    unsigned short count;
    unsigned short unk46;
    unsigned short* runs;
    unsigned short* lists;
    unsigned short GetCount() const
    {
        return count;
    }
    unsigned short* GetLengths() const
    {
        return runs;
    }
    unsigned short GetVertices() const
    {
        return (unsigned short)unk08;
    }
};
struct S_ca4520_Slot
{
    NiPointer<S_ca4520_Entry> entry;
    int unk04;
};
struct S_ca4520
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
    S_ca4520_Slot* slots;
    S_ca4520_Slot& GetPart(unsigned int n) const
    {
        return slots[n];
    }
    S_ca4520_Entry* GetData(unsigned int n) const
    {
        return GetPart(n).entry;
    }
    bool IsDegenerate(unsigned int key) const;
};

union HandleKey
{
    unsigned int raw;
    struct
    {
        unsigned int index : 20;
        unsigned int slot : 12;
    };
};

// Looks up the entry for the key's slot, walks its runs to the key's index, and returns true if any two of the three consecutive values there are equal.
// @fnv 0x00ca4520
bool S_ca4520::IsDegenerate(unsigned int key) const
{
    bool result = false;
    HandleKey k;
    k.raw = key;
    S_ca4520_Entry* e = GetData(k.slot);
    unsigned short count = e->GetCount();
    unsigned short* p = ((unsigned short *)(::FUN_00a75f10((char *)(e))));
    unsigned short* runs = e->GetLengths();
    unsigned short i = 0;
    unsigned int idx = k.index;
    while (i < count)
    {
        if (idx < (unsigned int)(runs[i] - 2))
            break;
        idx += 2 - runs[i];
        p += runs[i];
        ++i;
    }
    unsigned short* q = p + idx;
    unsigned short a = *q;
    q++;
    unsigned short b = *q;
    q++;
    unsigned short c = *q;
    if (a == b || a == c || b == c)
        result = true;
    return result;
}

static volatile int g_helperSink;
__declspec(noinline) static int FUN_00cb0b10(int a, int b, intptr_t c)
{
    g_helperSink = a + b + (int)c;
    return g_helperSink;
}
// @fnv 0x00cb0c00
void FUN_00cb0c00(intptr_t p)
{
    int x = FUN_00cb0b10(0, -1, p);
    (void)x;
}

struct SStringPtr
{
    void* FUN_00cb0c10(const char* s);
};
struct SelfRef
{
    void* p;
};
static uintptr_t g_sink;
static __declspec(noinline) void FUN_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (uintptr_t)s + len;
    *(uintptr_t*)self.p = g_sink;
}
// @fnv 0x00cb0c10
void* SStringPtr::FUN_00cb0c10(const char* s)
{
    SelfRef ref;
    ref.p = this;
    FUN_00cb0b10(ref, s, -1);
    return this;
}

struct Cb0StringCopy
{
    uintptr_t m_pcText;
    Cb0StringCopy* FUN_00cb0c30(const CB0StringPtr& other);
};
// @fnv 0x00cb0c30
Cb0StringCopy* Cb0StringCopy::FUN_00cb0c30(const CB0StringPtr& other)
{
    CB0SelfRef self = {(CB0StringPtr*)this};
    FUN_00cb0b10(self, other.cString(), -1);
    return this;
}

namespace fnv_00cb0c50 {
struct SStringPtr
{
    void FUN_00cb0c50(const char* s, int len);
};
struct SelfRef
{
    void* p;
};
static uintptr_t g_sink;
static __declspec(noinline) void FUN_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (uintptr_t)s + len;
    *(uintptr_t*)self.p = g_sink;
}
// @fnv 0x00cb0c50
void SStringPtr::FUN_00cb0c50(const char* apStr, int len)
{
    SelfRef ref;
    ref.p = this;
    FUN_00cb0b10(ref, apStr, len);
}
}  // namespace fnv_00cb0c50

template <typename KEY> struct MapOps
{
    static __forceinline unsigned hash(KEY key, unsigned mod)
    {
        return unsigned((unsigned long)(key) >> 4) * 2654435761U & mod;
    }
    static __forceinline int isValid(KEY key)
    {
        return key != KEY(-1);
    }
    static __forceinline int equal(KEY key0, KEY key1)
    {
        return key0 == key1;
    }
};

struct ProbeMap64
{
    struct Pair
    {
        unsigned __int64 key;
        unsigned __int64 val;
    };
    typedef MapOps<unsigned __int64> OPS;

    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FUN_00cb1c60(unsigned __int64 key);
};

// Searches the probe map for the given key and returns its index, or m_iPairCount + 1 if not found.
// @fnv 0x00cb1c60
int ProbeMap64::FUN_00cb1c60(unsigned __int64 key)
{
    if (m_iPairCount > 0)
    {
        for (unsigned i = OPS::hash(key, m_iPairCount); OPS::isValid(m_kPrimitiveElement[i].key);
             i = (i + 1) & m_iPairCount)
        {
            if (OPS::equal(m_kPrimitiveElement[i].key, key))
            {
                return i;
            }
        }
    }
    return m_iPairCount + 1;
}

namespace fnv_00ca2140 {
struct ChildLayout;
typedef void (ChildLayout::*ReleaseFunction)(void*);
struct BaseState
{
    virtual ~BaseState()
    {}
};
struct ChildLayout
{
    void* m_vptr;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    ~ChildLayout()
    {
        m_vptr = &::DAT_010c7310;
        if (m_iWordAt04 != 0)
        {
            ::DAT_010c7318(m_iWordAt04);
            m_iWordAt04 = 0;
            m_iThirdValue = 0;
            m_8 = 0;
        }
    }
};
struct FUN_00ca2140 : BaseState
{
    ChildLayout child;
    ~FUN_00ca2140();
};
// Destructor that only calls FUN_00ca20e0 on this.
// @fnv 0x00ca2140
FUN_00ca2140::~FUN_00ca2140()
{
    ((FUN_00ca20e0_Class*)this)->ClearAndFreeEntries();
}
}  // namespace fnv_00ca2140

extern int DAT_010c7600;
struct ExtraArray
{
    ~ExtraArray()
    {
        FUN_00aa10f0(m_pBase);
    }
    void* unk00;
    S_00ca49a0_Elem* m_pBase;
    unsigned int unk08, m_uiESize, m_uiCount, growBy;
    ExtraArray(unsigned int n = 0, unsigned int g = 1)
    {
        unk08 = n;
        growBy = g;
        m_uiESize = 0;
        m_uiCount = 0;
        m_pBase = 0;
        unk00 = &DAT_010c7600;
    }
    __declspec(noinline) void Resize(unsigned int capacity)
    {
        if (capacity == unk08)
            return;
        if (capacity < m_uiESize)
        {
            for (unsigned int i = capacity; i < m_uiESize; ++i)
            {
                if (m_pBase[i] != S_00ca49a0_Elem(0))
                {
                    m_pBase[i] = S_00ca49a0_Elem(0);
                    --m_uiCount;
                }
            }
            m_uiESize = capacity;
        }
        S_00ca49a0_Elem* old = m_pBase;
        unk08 = capacity;
        if (capacity)
        {
            m_pBase = (S_00ca49a0_Elem*)FUN_00aa13e0(capacity * sizeof(S_00ca49a0_Elem));
            for (unsigned int i = 0; i < m_uiESize; ++i)
                m_pBase[i] = old[i];
            for (unsigned int i = m_uiESize; i < unk08; ++i)
                m_pBase[i] = S_00ca49a0_Elem(0);
        }
        else
            m_pBase = 0;
        FUN_00aa10f0(old);
    }
    __declspec(noinline) void FUN_00ca49a0(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= m_uiESize)
        {
            m_uiESize = i + 1;
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else if (m_pBase[i] == S_00ca49a0_Elem(0))
        {
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else
        {
            if (e == S_00ca49a0_Elem(0))
                --m_uiCount;
        }
        m_pBase[i] = e;
    }
    const S_00ca49a0_Elem& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    unsigned int Add(const S_00ca49a0_Elem& e)
    {
        return SetAtGrow(m_uiESize, e);
    }
    unsigned int SetAtGrow(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= unk08)
            reinterpret_cast<::PtrEntryArray *>(this)->Resize(i + growBy);
        reinterpret_cast<::S_00ca49a0_Array *>(this)->FUN_00ca49a0(i, e);
        return i;
    }
};
inline void CopyEntry(ExtraArray& out, int i, const ExtraArray& source)
{
    const S_00ca49a0_Elem& e = source.m_pBase[i];
    unsigned at = out.m_uiESize;
    if (at >= out.unk08)
    {
        unsigned n = at + out.growBy;
        reinterpret_cast<::PtrEntryArray *>(&(out))->Resize(n);
    }
    reinterpret_cast<::S_00ca49a0_Array *>(&(out))->FUN_00ca49a0(at, e);
}
struct SavedExtraArray : ExtraArray
{
    SavedExtraArray() : ExtraArray()
    {}
};
struct SerializedExtraBody
{
    unsigned int unk00;
    float scale;
    ExtraArray entries;
    unsigned int value20, value24, value28, value2c;
    static void Swap4(void* p)
    {
        *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
    }
    void Swap()
    {
        Swap4(&scale);
        Swap4(&value20);
        Swap4(&value24);
        Swap4(&value28);
        Swap4(&value2c);
    }
};
struct ExtraSerializer
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void Restore(int token);
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual SerializedExtraBody* Acquire(int* token);
    void FUN_00ca77f0(S_00ca59d0_Stream* stream);
};
inline void SaveR(S_00ca59d0_Bin& bin, const unsigned int* p)
{
    unsigned int uiSize = 4;
    unsigned int written = bin.unk0C(&bin, p, 4, &uiSize, 1);
    bin.unk04 += written;
}
inline void SaveRV(S_00ca59d0_Bin& bin, unsigned int value)
{
    SaveR(bin, &value);
}
// Copies the acquired body's entries, writes each entry's link via stream->v12 and its unk04 value, byte-swapping the body when unk1E4 is not 1.
// @fnv 0x00ca77f0
void ExtraSerializer::FUN_00ca77f0(S_00ca59d0_Stream* stream)
{
    TlsGuard_t heap;
    int token;
    SerializedExtraBody* raw = Acquire(&token);
    SavedExtraArray entries;
    int count = 0;
    count = (int)raw->entries.m_uiESize;
    SerializedExtraBody* body = raw;
    for (int i = 0; i < count; ++i)
        CopyEntry(entries, i, body->entries);
    reinterpret_cast<::RecordArray *>(&(body->entries))->ClearRecords();
    reinterpret_cast<::PtrEntryArray *>(&(body->entries))->Resize(0);
    body->scale = DAT_010c72c0;
    if (*(unsigned char*)&stream->unk1E4 != 1)
        body->Swap();
    reinterpret_cast<::FUN_00c84d50_cls *>(this)->FUN_00c84d50(stream);
    S_00ca59d0_Save(*stream->unk250, &count, 1);
    for (int i = 0; i < count; ++i)
    {
        void* link = entries.m_pBase[i].obj.m_p;
        stream->v12(link);
    }
    S_00ca59d0_Save(*stream->unk250, &count, 1);
    for (int i = 0; i < count; ++i)
    {
        SaveRV(*stream->unk250, entries.GetAt(i).unk04);
    }
    if (*(unsigned char*)&stream->unk1E4 != 1)
        body->Swap();
    Restore(token);
}


struct cb86f0_obj : bhkRefObject
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;

    cb86f0_obj()
    {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        vtable = (void*)fnv_vftable_FUN_00c87970;
        const int inc = 1;
        unk0c = 0;
        DAT_01268154 += inc;
        vtable = (void*)&DAT_0102009c;
        DAT_01268118 += inc;
        vtable = (void*)fnv_vftable_FUN_00cb83f0;
    }

};

struct FUN_00cb86f0_class
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
    virtual void v50(void* obj, int param);
    cb86f0_obj* FUN_00cb86f0(int a1);
};

// Allocates a cb86f0_obj, calls v50 on it with a1, and returns the new object.
// @fnv 0x00cb86f0
cb86f0_obj* FUN_00cb86f0_class::FUN_00cb86f0(int a1)
{
    TlsGuard_t guard;
    FUN_00c876f0();
    cb86f0_obj* p = new cb86f0_obj();
    v50(p, a1);
    FUN_00c87700();
    return p;
}

class RagdollRaycastCleanup
{
  public:
    void* m_vtbl;
    void FUN_00ca0c30();
};

// @fnv 0x00ca0c30
void RagdollRaycastCleanup::FUN_00ca0c30()
{
    m_vtbl = &DAT_010c7304;
}

struct S_ca5870_Alloc
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct S_ca5870_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_ca5870_Alloc* m_10;
};

struct S_ca5870_Obj
{
    S_ca5870_Obj(void* arg);
    int unk00;
    unsigned short m_04;
    unsigned short unk06;
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

    static void* operator new(std::size_t size) throw()
    {
        S_ca5870_Holder* h = (S_ca5870_Holder*)static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
        void* p = h->m_10->Alloc(size);
        ((S_ca5870_Obj*)p)->m_04 = (unsigned short)size;
        return p;
    }
};

struct S_ca5870
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6C();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7C();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void SlotA(S_ca5870_Obj* obj);
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9C();
    virtual void unkA0();
    virtual void unkA4();
    virtual void unkA8();
    virtual void unkAC();
    virtual void unkB0();
    virtual void unkB4();
    virtual void unkB8();
    virtual void SlotB(void* arg);
    void FUN_00ca5870(void* arg);
};

// Constructs a S_ca5870_Obj from arg, passes it to SlotA, calls FUN_00c905b0 on it, then calls SlotB with arg.
// @fnv 0x00ca5870
void S_ca5870::FUN_00ca5870(void* arg)
{
    TlsGuard_t guard;
    S_ca5870_Obj* obj = new S_ca5870_Obj(arg);
    this->SlotA(obj);
    reinterpret_cast<::hkReferencedObjectC905 *>((obj))->FUN_00c905b0();
    this->SlotB(arg);
}

extern "C" void __cdecl _ReadWriteBarrier(void);

struct FUN_00cb1130_class
{
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& val)
    {
        FNVTaskMemoryRouter* router = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ::ResizeAudioStream((::AudioAllocator *)(router->allocator), (::AudioStream *)(void *)(this), sizeof(T));
        }
        T* slot = m_data + m_iElementCount;
        _ReadWriteBarrier();
        *slot = val;
        m_iElementCount++;
    }
};

// Appends the offset of the first match of substr in str to indices, or of every match when findAll is nonzero; returns whether any match was found.
// @fnv 0x00cb1440
hkBool FUN_00cb1440(const char* str, const char* substr, hkArray<int>& indices, int findAll)
{
    int len = (int)strlen(substr);
    const char* match = ::fnv_00cb1130::FUN_00cb1130(str, substr);
    hkBool result = false;
    while (match != 0)
    {
        result = true;
        indices.AddBack((int)(match - str));
        if (!findAll)
            break;
        match = ::fnv_00cb1130::FUN_00cb1130(match + len, substr);
    }
    return result;
}

struct S_Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    __m128 unk20;
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
    float unk58;
    int unk5c;
    int unk60;
};

struct S_D26450
{
};

struct S_00cb0030_Obj : S_00ca4e10_Obj
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_D26450* unk18;
};

struct S_00cb0030_Out : S_00ca4e10_Out
{
    int unk08;
    int unk0c;
    __m128 unk10;
    int unk20;
    int unk24;
    float unk28;
    float unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
};

struct S_00cb0030_Cls : S_00ca4e10_Cls
{
    void FUN_00cb0030(S_00cb0030_Out* out);
};

// Calls FUN_00ca4e10, then if obj->unk18 yields a source, fills out unk10, unk20, unk24, unk28, unk2c and unk40 from its fields.
// @fnv 0x00cb0030
void S_00cb0030_Cls::FUN_00cb0030(S_00cb0030_Out* out)
{
    reinterpret_cast<::S_00ca4e10_Cls *>(this)->FUN_00ca4e10((::S_00ca4e10_Out *)(out));
    S_00cb0030_Obj* obj = static_cast<S_00cb0030_Obj*>(unk08);
    if (obj && obj->unk18)
    {
        S_Source* src = ((::S_Source *)(reinterpret_cast<::FUN_00d26450_Obj *>((obj->unk18))->FUN_00d26450()));
        if (src)
        {
            out->unk2c = src->unk58 + src->unk18;
            out->unk28 = src->unk18 - src->unk58;
            out->unk10 = src->unk20;
            out->unk20 = src->unk10;
            out->unk24 = src->unk14;
            out->unk40 = src->unk60;
        }
    }
}




float __cdecl FUN_00ca98e0();

void FUN_00ca9900(void** p);


int* __cdecl FUN_00ca5300();

// FUN_00ca6600 : a one-line function - getter
void* FUN_00ca6600();

void* __cdecl FUN_00ca9910();

void __cdecl InitRect(FUN_00cb0ed0_rect* pRect, int nLeft, int nSize);

int __cdecl CompareCaseInsensitive(const char* pcA, const char* pcB, int n);

GlobalObjectO2_00a7b610* __cdecl FUN_00cb9b50();

CpuOpaque* __cdecl FUN_00cb9c00();

void* __cdecl FUN_00cba1c0();




int __cdecl FUN_00ca6610(intptr_t param_1);

void __cdecl FUN_00ca98d0();

char FUN_00ca98f0();

int __cdecl CombineIndexedMaskAndShift(int aiIndex, int aiHighByte);

int __cdecl FUN_00ec6cc4(char*, const char*, char*);

extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);

void __cdecl FUN_00cb75f0(void);

void __cdecl FUN_00cb7600();

bool __cdecl FUN_00cb7630(int param_1, int param_2);

CpuOpaque* __cdecl FUN_00cb8460();

void __cdecl FUN_00cb8470();

CpuOpaque* __cdecl FUN_00cb9250();

void __cdecl FUN_00cb9920();

GlobalObjectO2_00a7b610* __cdecl FUN_00cbaf80();

void __cdecl FUN_00cbf530();


void __cdecl DispatchToTarget();

void __cdecl FUN_00caa1b0();

unsigned int __cdecl FUN_00cabe90();

static void* FUN_00cb0aa0(char* s);

void zz_probe_call(char* s);

void __cdecl FUN_00cb7620(void);

void __cdecl FUN_00cb9910();

void __cdecl FUN_00cbb920();

static void FUN_00cbd700(ChainSource* src, ChainDest* dst);

void __cdecl FUN_00cbf190();

float __cdecl FUN_00cbfd80(float value);

static void FUN_00cb0b10(CB0SelfRef selfRef, const char* s, int len);

// 0x00cabcd0  340 B  /MT /O2 /GS /EHsc /Gy  - HSV ramp helper.
extern double FUN_00ec6940(double);

static void HsvToRgb(float* pR, float h, float s, float v, float* pG, float* out1);

void CallerHsv9(float* a, float h, float s, float v, float* r, float* g);

unsigned int __cdecl FUN_00cabe30(float h, float s, float v, float a);


static void FUN_00cb0b10(StringSlot slotRef, char* s, int len);

void StringSetCaller(uintptr_t* slot, char* s, int len);

inline void CopyEntry(ExtraArray& out, int i, const ExtraArray& source);


hkBool FUN_00cb1440(const char* str, const char* substr, hkArray<int>& indices, int findAll);

union __declspec(align(16)) AcousticVector
{
    float lanes[4];
    signed char bytes[16];
};

struct hkpWorld
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
    void* m_ulUserData;
    void* getUserData() const
    {
        return m_ulUserData;
    }
};

struct hkpWorldObject
{
    void* vt;
    int refc;
    hkpWorld* m_pOwningWorld;
    hkpWorld* getWorld() const
    {
        return m_pOwningWorld;
    }
};

struct hkpCollidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    void* getOwner() const
    {
        return (void*)((char*)this + m_iOwnerOffset);
    }
};

struct ContactCallback
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int* out);
};

struct bhkWorld
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
    ContactCallback* m28;
};

inline hkpWorldObject* GetWorldObject(const hkpCollidable* c)
{
    return (hkpWorldObject*)c->getOwner();
}

inline bhkWorld* GetOwningWorld(hkpWorld* w)
{
    return w ? (bhkWorld*)w->getUserData() : 0;
}

inline bhkWorld* GetOwningWorld(const hkpCollidable* c)
{
    return GetOwningWorld(GetWorldObject(c)->getWorld());
}

struct Rec
{
    AcousticVector v00;
    AcousticVector v10;
    void* a20;
    int u24;
    int u28;
    int u2c;
    AcousticVector v30;
    int u40;
    int u44;
    hkpCollidable* p48;
    int u4c;
    AcousticVector v50;
    AcousticVector v60;
};

// @fnv 0x00ca0bd0
extern "C" void FUN_00ca0bd0(void* a, hkpCollidable* p)
{
    Rec r;
    r.a20 = a;
    r.p48 = p;
    bhkWorld* o = GetOwningWorld(p);
    if (o)
    {
        o->m28->v08((int*)&r);
    }
}







namespace fnv_00ca0b70 {
struct World;

struct WorldObject
{
    int unk00;
    int unk04;
    World* m_pOwningWorld;
};

struct Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char m_iOwnerOffset;
    WorldObject* getOwner() const
    {
        return (WorldObject*)((char*)this + m_iOwnerOffset);
    }
};

struct __declspec(align(16)) LocalEvent
{
    __m128 m_vComponents;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_a1;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    Collidable* m_a2;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

struct TargetClass
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(LocalEvent& event);
};

struct Mgr
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
    TargetClass* m_target;
};

struct World
{
    int unk000[0xd4];
    Mgr* m_pManager;
};

// @fnv 0x00ca0b70
void FUN_00ca0b70(void* a1, Collidable* a2, void* a3)
{
    LocalEvent ev;
    ev.m_a1 = a1;
    ev.m_a2 = a2;

    World* world = a2->getOwner()->m_pOwningWorld;
    Mgr* mgr = world ? world->m_pManager : 0;
    mgr->m_target->v1c(ev);
}
}

struct RayScalar_rc1c
{
    __m128 value;
    RayScalar_rc1c(float x)
    {
        value = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};

struct hkVector4_rc1c
{
    __m128 m_vComponents;
    hkVector4_rc1c()
    {}
    __forceinline void operator=(const hkVector4_rc1c& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkVector4_rc1c(const hkVector4_rc1c& v) : m_vComponents(v.m_vComponents)
    {}
    void setInterpolate4(const hkVector4_rc1c& a, const hkVector4_rc1c& b, const RayScalar_rc1c& t)
    {
        __m128 tt = t.broadcast();
        __m128 s = _mm_sub_ps(::DAT_010ec7f0, tt);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, a.m_vComponents), _mm_mul_ps(tt, b.m_vComponents));
    }
};

struct hkpCollidable_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    char unk11;
    short unk12;
    int unk14;
    unsigned char m_type;
    char unk19;
    short unk1a;
    unsigned int m_uiCollisionFilterData;
    int getType() const
    {
        return m_type;
    }
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct hkpWorldObject_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkpCollidable_rc1c m_kCollidable;
    unsigned int GetFilterInfoForKey() const
    {
        return m_kCollidable.m_uiCollisionFilterData;
    }
};

inline const hkpWorldObject_rc1c* getBody(const hkpCollidable_rc1c* c)
{
    return c->getType() == 1 ? (const hkpWorldObject_rc1c*)c->getOwner() : 0;
}

struct hkpWorldRayCastOutput_rc1c
{
    hkVector4_rc1c m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
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
    const hkpCollidable_rc1c* m_pRootCollidable;
    int unk54;
    int unk58;
    int unk5c;
    __forceinline hkpWorldRayCastOutput_rc1c(const hkpWorldRayCastOutput_rc1c& o)
    {
        m_vHitNormal = o.m_vHitNormal;
        m_fHitFraction = o.m_fHitFraction;
        m_iExtraInfo = o.m_iExtraInfo;
        unk18 = o.unk18;
        unk1c = o.unk1c;
        unk20 = o.unk20;
        unk24 = o.unk24;
        unk28 = o.unk28;
        unk2c = o.unk2c;
        unk30 = o.unk30;
        unk34 = o.unk34;
        unk38 = o.unk38;
        unk3c = o.unk3c;
        unk40 = o.unk40;
        unk44 = o.unk44;
        unk48 = o.unk48;
        unk4c = o.unk4c;
        m_pRootCollidable = o.m_pRootCollidable;
        unk54 = o.unk54;
        unk58 = o.unk58;
        unk5c = o.unk5c;
    }
};

struct hkpWorldRayCastInput_rc1c
{
    hkVector4_rc1c m_vFrom;
    hkVector4_rc1c m_vTo;
    bool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
    hkpWorldRayCastInput_rc1c() : m_bEnableShapeCollectionFilter(false), m_uiFilterInfo(0)
    {}
};

struct hkpRayHitCollector_rc1c
{
    float m_fEarlyOutHitFraction;
    virtual ~hkpRayHitCollector_rc1c();
};

struct hkpWorldRayCastOutputArray_rc1c
{
    hkpWorldRayCastOutput_rc1c* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkpWorldRayCastOutput_rc1c m_kStorage[8];
};

struct hkpAllRayHitCollector_rc1c : public hkpRayHitCollector_rc1c
{
    hkpWorldRayCastOutputArray_rc1c m_kHits;
    hkpAllRayHitCollector_rc1c();
    virtual ~hkpAllRayHitCollector_rc1c();
    void reset()
    {
        m_fEarlyOutHitFraction = 1.0f;
        m_kHits.m_iElementCount = 0;
    }
};

struct hkpWorld_rc1c
{
};

struct RayFilter_rc1c
{
    unsigned int bits;
    RayFilter_rc1c(unsigned int x) : bits(x)
    {}
    void AddObjectReference(unsigned int x)
    {
        bits &= 0xffff;
        bits |= x << 16;
    }
    void setLayer(unsigned int x)
    {
        bits &= ~0x7fu;
        bits |= x;
    }
    bool bip() const
    {
        unsigned int layer = bits & 0x7f;
        return layer == 8 || layer == 29;
    }
    operator unsigned int() const
    {
        return bits;
    }
};

struct RayCaster_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_systemGroup;
    hkBool FUN_00ca1c50(const hkpWorld_rc1c* world, const hkVector4_rc1c& from, const hkVector4_rc1c& to,
                        hkVector4_rc1c& pointOut, hkVector4_rc1c& normalOut);
};

// @fnv 0x00ca1c50
hkBool RayCaster_rc1c::FUN_00ca1c50(const hkpWorld_rc1c* world, const hkVector4_rc1c& from, const hkVector4_rc1c& to,
                                    hkVector4_rc1c& pointOut, hkVector4_rc1c& normalOut)
{
    bool found = false;
    hkpWorldRayCastInput_rc1c input;
    hkpAllRayHitCollector_rc1c collector;
    RayFilter_rc1c filter(0);
    filter.AddObjectReference(m_systemGroup);
    filter.setLayer(29);

    input.m_vFrom = from;
    input.m_vTo = to;
    input.m_uiFilterInfo = filter;
    collector.reset();
    reinterpret_cast<::Phantom_00cf2510 *>((void *)(world))->FUN_00cf2510((const ::WorldRayCastInput &)(input), (::PhRayHitCollector &)(collector));
    for (int i = 0; i < collector.m_kHits.m_iElementCount && !found; i++)
    {
        hkpWorldRayCastOutput_rc1c hit = collector.m_kHits.m_data[i];
        const hkpWorldObject_rc1c* owner = getBody(hit.m_pRootCollidable);
        if (owner)
        {
            {
                RayFilter_rc1c hitFilter(owner->GetFilterInfoForKey());
                if (!hitFilter.bip())
                {
                    pointOut.setInterpolate4(input.m_vFrom, input.m_vTo, hit.m_fHitFraction);
                    normalOut = hit.m_vHitNormal;
                    found = true;
                }
            }
        }
    }

    if (!found)
    {
        input.m_vFrom = to;
        input.m_vTo = from;
        input.m_uiFilterInfo = filter;
        input.m_bEnableShapeCollectionFilter = true;
        collector.reset();
        reinterpret_cast<::Phantom_00cf2510 *>((void *)(world))->FUN_00cf2510((const ::WorldRayCastInput &)(input), (::PhRayHitCollector &)(collector));
        for (int i = 0; i < collector.m_kHits.m_iElementCount && !found; i++)
        {
            hkpWorldRayCastOutput_rc1c hit = collector.m_kHits.m_data[i];
            const hkpWorldObject_rc1c* owner = getBody(hit.m_pRootCollidable);
            if (owner)
            {
                {
                    RayFilter_rc1c hitFilter(owner->GetFilterInfoForKey());
                    if (!hitFilter.bip())
                    {
                        pointOut.setInterpolate4(input.m_vFrom, input.m_vTo, hit.m_fHitFraction);
                        normalOut = hit.m_vHitNormal;
                        found = true;
                    }
                }
            }
        }
    }
    return found;
}

struct Ca35Owner;

struct Ca35Record
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
};

struct Ca35Entry
{
    unsigned short m_00;
    unsigned short unk02;
    unsigned int unk04;
};

struct Ca35Table
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int unk0c;
    unsigned int unk10;
    Ca35Entry* m_14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Ca35Record* m_24;
};

struct Ca35Owner
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
    unsigned int unk6C;
    unsigned int unk70;
    Ca35Table* m_74;
    unsigned int FUN_00ca35d0(unsigned int a1);
};

// @fnv 0x00ca35d0
unsigned int Ca35Owner::FUN_00ca35d0(unsigned int a1)
{
    unsigned int type = a1 >> 24;
    unsigned int v = (a1 & 0xffffff) + 1;
    if (v >= m_74->m_08)
    {
        return 0xffffffff;
    }
    unsigned int sum = 0;
    for (int i = 0; i <= (int)type; ++i)
        sum += m_74->m_24[i].m_04;
    unsigned int w = m_74->m_14[v].m_00;
    if (w >= sum)
        ++type;
    return (v & 0xffffff) | (type << 24);
}

typedef __m128 S00ca4120_Q;

extern float DAT_012682c8;

extern const float DAT_01011d78;

struct S00ca4120_Vec
{
    S00ca4120_Q q;
    void set(float a, float b, float c, float d)
    {
        q[0] = a;
        q[1] = b;
        q[2] = c;
        q[3] = d;
    }
    void setMin4(const S00ca4120_Vec& a, const S00ca4120_Vec& b)
    {
        *(__m128*)&q = _mm_min_ps(*(__m128*)&a.q, *(__m128*)&b.q);
    }
    void setMax4(const S00ca4120_Vec& a, const S00ca4120_Vec& b)
    {
        *(__m128*)&q = _mm_max_ps(*(__m128*)&a.q, *(__m128*)&b.q);
    }
    void mul4(const S00ca4120_Vec& a)
    {
        *(__m128*)&q = _mm_mul_ps(*(__m128*)&q, *(__m128*)&a.q);
    }
    void FUN_00c7f640(const struct S00ca4120_Xf* t, const S00ca4120_Vec* v);
};

struct S00ca4120_Xf
{
    S00ca4120_Vec c0, c1, c2, c3;
};

struct S00ca4120_Pt
{
    float x, y, z;
};

struct S00ca4120_Mesh
{
    unsigned int unk00, unk04;
    unsigned short count, unk0a;
    unsigned int unk0c, unk10, unk14, unk18, unk1c;
    S00ca4120_Pt* positions;
};

struct S00ca4120_Entry
{
    S00ca4120_Mesh* mesh;
    unsigned int unk04;
};

struct S00ca4120_Geom
{
    __m128 unk00, unk10;
    S00ca4120_Xf transform;
    S00ca4120_Vec minimum, maximum;
    S00ca4120_Vec scale;
    unsigned int unk90, unk94;
    S00ca4120_Entry* entries;
    unsigned int unk9c, count;
    void FUN_00ca4120(const S00ca4120_Xf* input);
};

// @fnv 0x00ca4120
void S00ca4120_Geom::FUN_00ca4120(const S00ca4120_Xf* input)
{
    *(__m128*)&transform.c0.q = *(__m128 const*)&input->c0.q;
    *(__m128*)&transform.c1.q = *(__m128 const*)&input->c1.q;
    *(__m128*)&transform.c2.q = *(__m128 const*)&input->c2.q;
    *(__m128*)&transform.c3.q = *(__m128 const*)&input->c3.q;
    *(__m128*)&minimum.q = _mm_setr_ps(3.40282e38F, 3.40282e38F, 3.40282e38F, 0.0f);
    *(__m128*)&maximum.q = _mm_setr_ps(-3.40282e38F, -3.40282e38F, -3.40282e38F, 0.0f);
    unsigned int n = count;
    const S00ca4120_Vec& s = scale;
    for (unsigned int i = 0; i < n; ++i)
    {
        S00ca4120_Mesh* mesh = entries[i].mesh;
        S00ca4120_Pt* p = mesh->positions;
        unsigned int m = mesh->count;
        for (unsigned int j = 0; j < m; ++j)
        {
            S00ca4120_Vec pt;
            pt.set(p[j].x * DAT_012682c8, p[j].y * DAT_012682c8, p[j].z * DAT_012682c8, 0.0f);
            pt.mul4(s);
            S00ca4120_Vec r;
            r.FUN_00c7f640(input, &pt);
            minimum.setMin4(minimum, r);
            maximum.setMax4(maximum, r);
        }
    }
}

struct VelocityBody
{
};

struct VelocityHolder
{
    int unk00;
    int unk04;
    VelocityBody* body;
};

struct VelocityProperty
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    VelocityHolder* holder;
    int unk14;
    float fraction;
};

struct DynCastHelper
{
};

struct VelocityNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DynCastHelper* property;
};


void FUN_00a6d220(void* p);

struct MemoryManagerAllocHelper : MemoryManager
{
    void* Allocate(unsigned int size);
};

class NiTimeController;

struct CB9320Object
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
};

// @fnv 0x00cb9290
void VelocityController::FUN_00cb9290()
{
    if (node && node->property)
    {
        VelocityProperty* prop = ((::VelocityProperty *)(reinterpret_cast<::NiObject *>((node->property))->DynamicCast((const ::NiRTTI *)(const ::GlobalObjectO2_00a7b610 *)(&g_01267e64))));
        if (prop && prop->fraction < 1.0f)
        {
            VelocityHolder* holder = prop->holder;
            if (holder)
            {
                VelocityBody* body = holder->body;
                if (body)
                {
                    __m128 scalar = _mm_load_ss(&::DAT_01016410);
                    __m128 factor = _mm_shuffle_ps(scalar, scalar, 0);
                    __m128 scaled = _mm_mul_ps(factor, velocity);
                    reinterpret_cast<::FUN_00631100_shell *>((body))->FUN_00631100(amount, (intptr_t)(&scaled));
                }
            }
        }
    }
}

struct Aux2
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
    float f194;
};

struct Aux1
{
    void* m_iWordAt00;
    int unk04;
    void* unk08;
};

class NiAVObject
{
  public:
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* unk1c;
};

extern int DAT_010c8a2c;

union Mem128
{
    __m128 v;
    struct
    {
        float x;
        float y;
        float z;
        float w;
    } components;
};

class NiTimeController;

struct NTCVtable
{
    virtual ~NTCVtable();
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
    virtual void vf35(float v);
    virtual void v36();
    virtual void v37();
    virtual void vf38(NiAVObject* pObj);
};

struct NTCVt
{
    void* m_vtbl;
    int unk04;
    unsigned short flags08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Mem128 m_40;
    float m_50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    void* operator new(std::size_t size) throw();
    void operator delete(void*)
    {}
    NTCVt();
};

void* NTCVt::operator new(std::size_t size) throw()
{
    char* p = (char*)reinterpret_cast<::MemoryManagerStandIn *>((((MemoryManagerAllocHelper*)&::g_memoryManager)))->FUN_00aa3e40(size);
    unsigned char adj = (unsigned char)(0x10 - ((unsigned char)(uintptr_t)p & 0xf));
    p += adj;
    GetAlignedBlockPrefix(p)->m_ucOffset = adj;
    return p;
}

NTCVt::NTCVt()
{
    new ((void *)(this)) class ::FUN_00a6d220();
    m_vtbl = (void*)&DAT_010c8a2c;
    m_40.v = (*reinterpret_cast<const __m128 *>(&::DAT_01267e30));
    m_50 = 0.0f;
}

// @fnv 0x00cb9320
void __cdecl FUN_00cb9320(NiAVObject* a1, const void* a2, NiAVObject* a3)
{
    NiAVObject* pObj = a3;
    if (pObj == 0)
        pObj = a1;
    NiTimeController* pCtl = ((::NiTimeController *)(reinterpret_cast<::MyHost *>((pObj))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)((const NiRTTI*)&g_012683f4))));
    if (pCtl == 0)
    {
        pCtl = (NiTimeController*)(NTCVt*)new NTCVt();
        ((NTCVtable*)pCtl)->vf38(pObj);
    }
    CB9320Object* pUnk;
    if (pObj->unk1c == 0)
        pUnk = 0;
    else
        pUnk = (CB9320Object*)((::NiObject*)pObj->unk1c)->DynamicCast((const ::NiRTTI *)(const void *)((const void*)&g_012043f8));
    __m128 vec = _mm_load_ps((const float*)a2);
    if (pUnk != 0 && pUnk->unk10 != 0)
    {
        Aux1* pA1 = (Aux1*)pUnk->unk10;
        float scale = reinterpret_cast<::bhkRigidBody *>((pA1))->GetBodyMass();
        scale = DAT_011b1d3c * scale;
        __m128 scalar = _mm_load_ss(&scale);
        __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), vec);
        Aux2* pA2 = (Aux2*)((volatile Aux1*)pA1)->unk08;
        float bias = (float)(pA2->f194 * 0.75);
        __m128 tb = _mm_load_ss(&bias);
        vec = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(tb, tb, 0x00), t1), t1);
    }
    NTCVt* __restrict pT = (NTCVt*)pCtl;
    pT->unk14 = 0.0f;
    pT->unk18 = ::DAT_0101df44;
    pT->flags08 = (unsigned short)((pT->flags08 & 0xfff5) | 5);
    pT->unk10 = 0.0f;
    pT->unk0c = 1.0f;
    pT->m_40.v = vec;
    ((NTCVtable*)pCtl)->vf35(DAT_01015f5c);
}

class CBD9E0V4
{
  public:
    __m128 m_vComponents;
    void mul(float s)
    {
        __m128 scalar = _mm_load_ss(&s);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), m_vComponents);
    }
};

struct FUN_00cbd9e0_cls
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
    CBD9E0V4 m_v50;
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
    CBD9E0V4 m_v90;
};

// @fnv 0x00cbd9e0
void FUN_00cbd9e0(float scale, FUN_00cbd9e0_cls* p)
{
    if (p == 0 || scale == 1.0f)
        return;
    p->m_v50.mul(scale);
    p->m_v90.mul(scale);
}

extern int DAT_010c91ec;

struct S00cbe7b0_Obj
{
    void* m_vtbl;
    unsigned short m_iWordAt04;
    unsigned short m_6;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    float m_18;
    float m_1c;
    __m128 q20;
    __m128 q30;
    __m128 q40;
    __m128 q50;
    __m128 q60;
    __m128 q70;
    __m128 q80;
    __m128 q90;
    unsigned char m_a0;
    unsigned char m_a1;
    unsigned char m_a2;
    S00cbe7b0_Obj* FUN_00cbe7b0();
};

// @fnv 0x00cbe7b0
S00cbe7b0_Obj* S00cbe7b0_Obj::FUN_00cbe7b0()
{
    m_6 = 1;
    m_8 = 0;
    m_vtbl = &DAT_010c91ec;
    reinterpret_cast< ::FUN_00cbe820_cls*>(&m_10)->FUN_00cbe820();
    __m128 z = _mm_setzero_ps();
    _mm_store_ps((float*)&q20, z);
    _mm_store_ps((float*)&q30, z);
    _mm_store_ps((float*)&q40, z);
    q20[0] = 1.0f;
    q30[1] = 1.0f;
    q40[2] = 1.0f;
    _mm_store_ps((float*)&q50, z);
    _mm_store_ps((float*)&q60, z);
    _mm_store_ps((float*)&q70, z);
    _mm_store_ps((float*)&q80, z);
    q60[0] = 1.0f;
    q70[1] = 1.0f;
    q80[2] = 1.0f;
    _mm_store_ps((float*)&q90, z);
    m_a2 = 0;
    return this;
}

static inline ::NiPoint3 Scale_00cbe8d0(::NiPoint3 p, float fScalar)
{
    ::NiPoint3 kResult;
    kResult.x = p.x * fScalar;
    kResult.y = p.y * fScalar;
    kResult.z = p.z * fScalar;
    return kResult;
}

union BoundCenter
{
    __m128 m_vComponents;
    unsigned char m_bytes[16];
    ::NiPoint3 m_kPoint;
};

struct BoundView_00cbe8d0
{
    ::NiPoint3 m_kCenter;
    float m_fBoundRadius;
};

struct BoundItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BoundView_00cbe8d0* m_pkBound;
};

struct BoundSource
{
};

class NodeView_00cbe8d0
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
    BoundSource* m_pkSource;
};

struct Scaled
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};

struct BoundHolderBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct ScaledList
{
    Scaled* m_pkScaled;
};

struct ScaledHolder : public BoundHolderBase, public ScaledList
{
};

extern bool DAT_01268440;

extern float DAT_011b21e8;

extern float DAT_0126844c;

class BoundOwner
{
  public:
    int unk00;
    int unk04;
    ScaledHolder* m_pkHolder;
    int unk0C;
    int unk10;
    int unk14;
    NodeView_00cbe8d0* m_pkNode;

    void FUN_00cbe8d0();
};

// @fnv 0x00cbe8d0
void BoundOwner::FUN_00cbe8d0()
{
    if (DAT_01268440 || !m_pkNode)
        return;

    BoundCenter kTargetCenter;
    float fRadius;
    BoundSource* pkSource = m_pkNode->m_pkSource;
    BoundItem* pkItem;
    if (pkSource && (pkItem = ((::BoundItem *)(reinterpret_cast<::PropertyOwner *>((pkSource))->FUN_00c85c80((void *)(0))))) != 0)
    {
        BoundView_00cbe8d0* __restrict source = pkItem->m_pkBound ? pkItem->m_pkBound : &(*reinterpret_cast<::BoundView_00cbe8d0 *>(&::g_defaultBound));
        BoundView_00cbe8d0 kBound = *source;
        kTargetCenter.m_kPoint = kBound.m_kCenter;
        fRadius = kBound.m_fBoundRadius;
    }
    else
    {
        kTargetCenter.m_vComponents = *((__m128 *)(reinterpret_cast<::NiObject *>((m_pkNode))->FUN_00621a40()));
        kTargetCenter.m_kPoint = Scale_00cbe8d0(kTargetCenter.m_kPoint, DAT_011b21e8);
        fRadius = 1.0f;
    }

    ScaledHolder* pkHolder = m_pkHolder;
    ScaledList* pkList = 0;
    if (pkHolder)
    {
        ::FUN_00a29680();
        pkList = (ScaledList*)pkHolder;
        ::FUN_00a29680();
    }
    Scaled* pkScaled = pkList ? pkList->m_pkScaled : 0;

    if (!(fRadius > 0.0f))
        fRadius = 1.0f;
    pkScaled->m_fScale = DAT_0126844c * fRadius;
    reinterpret_cast<::S006230f0_Object *>(this)->FUN_006230f0((const ::S006230f0_Source *)(const ::NiPoint3 *)(reinterpret_cast<const ::NiPoint3*>(&kTargetCenter.m_bytes[0])));
}

static float DAT_012682c8;

union S00ca45b0_Vec
{
    __m128 m_vComponents;
    char m_bytes[16];
    void set(float x, float y, float z, float w)
    {
        float* f = reinterpret_cast<float*>(&m_vComponents);
        f[0] = x;
        f[1] = y;
        f[2] = z;
        f[3] = w;
    }
    void operator=(const S00ca45b0_Vec& o)
    {
        m_vComponents = o.m_vComponents;
    }
    void mul4(const S00ca45b0_Vec& o)
    {
        m_vComponents =
            _mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&m_vComponents)), o.m_vComponents);
    }
};

struct S00ca45b0_Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S00ca45b0_Vec m_v0;
    S00ca45b0_Vec m_v1;
    S00ca45b0_Vec m_v2;
};

struct S00ca45b0_Alloc
{
};

struct S00ca45b0_Chunk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float* m_verts;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned short m_numStrips;
    unsigned short unk46;
    unsigned short* m_pStripIndices;
};

struct S00ca45b0_Slot
{
    S00ca45b0_Chunk* m_pCurrentMemoryChunk;
    int unk04;
};

struct S00ca45b0_Shape
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
    S00ca45b0_Vec m_vScale;
    float m_fSphereRadius;
    int unk84;
    S00ca45b0_Slot* m_slots;

    S00ca45b0_Tri* FUN_00ca45b0(unsigned int key, S00ca45b0_Alloc* alloc);
};

// @fnv 0x00ca45b0
S00ca45b0_Tri* S00ca45b0_Shape::FUN_00ca45b0(unsigned int key, S00ca45b0_Alloc* alloc)
{
    S00ca45b0_Chunk* chunk = m_slots[key >> 20].m_pCurrentMemoryChunk;
    unsigned short numStrips = chunk->m_numStrips;
    unsigned short* idx = ((unsigned short *)(::FUN_00a75f10((char *)(chunk))));
    unsigned short* lengths = chunk->m_pStripIndices;
    float* verts = chunk->m_verts;
    unsigned short s = 0;
    unsigned int t = key & 0xfffff;
    for (; s < numStrips; s++)
    {
        if (t < (unsigned int)(lengths[s] - 2))
            break;
        t -= lengths[s] - 2;
        idx += lengths[s];
    }
    unsigned short* p = &idx[t];
    unsigned short i0 = *p;
    unsigned short i1 = *++p;
    unsigned short i2 = *++p;
    if (i0 == i1 || i0 == i2 || i1 == i2)
        return 0;
    const float* a = &verts[i0 * 3];
    const float* b = &verts[i1 * 3];
    const float* c = &verts[i2 * 3];
    S00ca45b0_Tri* tri = alloc ? ((::S00ca45b0_Tri *)(new ((void *)(alloc)) ::FUN_00ca39a0(m_fSphereRadius))) : 0;
    S00ca45b0_Vec v;
    float* q = reinterpret_cast<float*>(&v.m_vComponents);
    q[0] = *(float volatile*)&a[0] * DAT_012682c8;
    q[1] = a[1] * DAT_012682c8;
    q[2] = a[2] * DAT_012682c8;
    q[3] = 0.0f;
    v.mul4(m_vScale);
    tri->m_v0 = v;
    q[0] = b[0] * DAT_012682c8;
    q[1] = b[1] * DAT_012682c8;
    q[2] = b[2] * DAT_012682c8;
    q[3] = 0.0f;
    v.mul4(m_vScale);
    tri->m_v1 = v;
    q[0] = c[0] * DAT_012682c8;
    q[1] = c[1] * DAT_012682c8;
    q[2] = c[2] * DAT_012682c8;
    q[3] = 0.0f;
    v.mul4(m_vScale);
    tri->m_v2 = v;
    return tri;
}

struct BoundVector
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};

struct PointBounds
{
    BoundVector min;
    BoundVector max;
};

struct PointArrayArg
{
    BoundVector** p;
    PointArrayArg(BoundVector** v) : p(v)
    {}
};

struct BoundsArg
{
    PointBounds* p;
    BoundsArg(PointBounds* v) : p(v)
    {}
};

// @fnv 0x00cbebf0
void FUN_00cbebf0(PointArrayArg points, int n, BoundsArg bounds)
{
    if (!n)
    {
        PointBounds* pd = bounds.p;
        _ReadWriteBarrier();
        pd->min.quad = _mm_load_ps1(&::DAT_0104da48);
        pd->max.quad = _mm_load_ps1(&DAT_0104e148);
    }
    else
    {
        BoundVector** pa = points.p;
        __m128 first = pa[0]->quad;
        _ReadWriteBarrier();
        PointBounds* pd = bounds.p;
        pd->min.quad = first;
        pd->max.quad = pa[0]->quad;
        for (int i = 1; i < n; ++i)
        {
            pd->min.quad = _mm_min_ps(pa[i]->quad, pd->min.quad);
            pd->max.quad = _mm_max_ps(pa[i]->quad, pd->max.quad);
        }
        pd->min.w = 0.0f;
        pd->max.w = 0.0f;
    }
}

union StripsBoundsQuad
{
    __m128 simd;
    float lanes[4];
    signed char bytes[16];
};

struct StripsBoundsTransform;

class StripsBoundsVector
{
  public:
    StripsBoundsQuad m_vComponents;
    void add(const StripsBoundsQuad& r)
    {
        m_vComponents.simd = _mm_add_ps(m_vComponents.simd, r.simd);
    }
    float getX() const
    {
        float x;
        _mm_store_ss(&x, m_vComponents.simd);
        return x;
    }
    void FUN_00c7f640(const StripsBoundsTransform& t, const StripsBoundsVector& v);
};

struct StripsBoundsVertex
{
    float x, y, z;
};

struct StripsBoundsAabb
{
    StripsBoundsVector m_kMinimumCorner, m_kMaximumCorner;
};

struct StripsBoundsCache
{
    hkBool FUN_00cb2160(const StripsBoundsTransform& t, float tolerance) const;
    int unk00;
};

struct StripsBoundsData
{
    int unk00, unk04;
    unsigned short count;
    unsigned short unk0a;
    int unk0c, unk10, unk14, unk18, unk1c;
    StripsBoundsVertex* vertices;
};

struct StripsBoundsEntry
{
    StripsBoundsData* data;
    int unk04;
};

extern float DAT_012682c8;

class StripsBoundsShape
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    StripsBoundsCache m_pAccessManager;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    StripsBoundsVector m_cachedMin, m_cachedMax, m_vScale;
    float m_fSphereRadius;
    int unk94;
    StripsBoundsEntry* entries;
    unsigned capacity, count;
    void FUN_00ca4280(const StripsBoundsTransform& t, float tolerance, StripsBoundsAabb& out);
};

// @fnv 0x00ca4280
void StripsBoundsShape::FUN_00ca4280(const StripsBoundsTransform& t, float tolerance, StripsBoundsAabb& out)
{
    if (m_cachedMin.getX() != 3.402820018375656e+38 && m_pAccessManager.FUN_00cb2160(t, 0.001f).m_cBooleanValue)
    {
        out.m_kMinimumCorner.m_vComponents.simd = m_cachedMin.m_vComponents.simd;
        out.m_kMaximumCorner.m_vComponents.simd = m_cachedMax.m_vComponents.simd;
    }
    else
    {
        out.m_kMinimumCorner.m_vComponents.simd =
            _mm_setr_ps(3.40282e38f, 3.40282e38f, 3.40282e38f, 0.0f);
        out.m_kMaximumCorner.m_vComponents.simd =
            _mm_setr_ps(-3.40282e38f, -3.40282e38f, -3.40282e38f, 0.0f);
        unsigned n = count;
        const StripsBoundsVector& scale = m_vScale;
        for (unsigned i = 0; i < n; ++i)
        {
            StripsBoundsData* data = entries[i].data;
            const StripsBoundsVertex* p = data->vertices;
            unsigned vertices = data->count;
            for (unsigned j = 0; j < vertices; ++j)
            {
                StripsBoundsVector v;
                v.m_vComponents.lanes[0] = p[j].x * DAT_012682c8;
                v.m_vComponents.lanes[1] = p[j].y * DAT_012682c8;
                v.m_vComponents.lanes[2] = p[j].z * DAT_012682c8;
                v.m_vComponents.lanes[3] = 0.0f;
                v.m_vComponents.simd =
                    _mm_mul_ps(scale.m_vComponents.simd, v.m_vComponents.simd);
                StripsBoundsVector tv;
                tv.FUN_00c7f640(t, v);
                out.m_kMinimumCorner.m_vComponents.simd =
                    _mm_min_ps(out.m_kMinimumCorner.m_vComponents.simd, tv.m_vComponents.simd);
                out.m_kMaximumCorner.m_vComponents.simd =
                    _mm_max_ps(out.m_kMaximumCorner.m_vComponents.simd, tv.m_vComponents.simd);
            }
        }
    }
    float radius = m_fSphereRadius + tolerance;
    StripsBoundsQuad r;
    r.simd = _mm_load_ps1(&radius);
    out.m_kMinimumCorner.m_vComponents.simd =
        _mm_sub_ps(out.m_kMinimumCorner.m_vComponents.simd, r.simd);
    out.m_kMaximumCorner.add(r);
}

class NiFixedString
{
  public:
    char* m_kHandle;
    __forceinline NiFixedString(const char* s)
    {
        m_kHandle = (char*)((void *)(::NiGlobalStringTable::AddString((const char *)(s))));
    }
    __forceinline ~NiFixedString()
    {
        if (m_kHandle != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedDecrement(&GetGlobalStringHeader(m_kHandle)->m_lRefCount);
    }
};

static float DAT_011b1864 = 6.9991255f;

__forceinline void* S00ca5da0_Memcpy(void* dst, const void* src, unsigned int n)
{
    return std::memmove(dst, src, n);
}

union __declspec(align(16)) DisplayVector
{
    __m128 simd;
    float lanes[4];
    unsigned char byteLanes[16];
};

struct S00ca5da0_ArrayAllocation
{
};

struct S00ca5da0_Vec3 : S00ca5da0_ArrayAllocation
{
    float x, y, z;
};

struct S00ca5da0_Index : S00ca5da0_ArrayAllocation
{
    unsigned short value;
};

struct S00ca5da0_Entry
{
    unsigned short f0;
    unsigned short f1;
    unsigned short f2;
    unsigned short f6;
};

struct S00ca5da0_Part
{
    int unk00;
    unsigned int count;
    int unk08;
};

struct S00ca5da0_Geom
{
    int unk00;
    int unk04;
    unsigned int m_08;
    int unk0c;
    unsigned short m_10;
    unsigned short unk12;
    S00ca5da0_Entry* m_14;
    S00ca5da0_Vec3* m_18;
    int unk1c;
    int unk20;
    S00ca5da0_Part* m_24;
};

struct S00ca5da0_Data
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
    struct S00ca5da0_Geom* m_84;
};

struct S00ca5da0_Arr
{
    void* m_vtbl;
    unsigned short* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __forceinline S00ca5da0_Arr(unsigned int maxSize = 0, unsigned int growBy = 1)
    {

        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_vtbl = &(*reinterpret_cast<int *>(&::indexVtable));
    }
    __forceinline ~S00ca5da0_Arr()
    {
        FUN_00aa10f0(m_pBase);
    }
    __forceinline void SetAt(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usSize)
        {
            m_usSize = (unsigned short)(idx + 1);
            if (v != 0)
                m_usESize++;
        }
        else
        {
            if (v != 0)
            {
                if (m_pBase[idx] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[idx] != 0)
                    m_usESize--;
            }
        }
        m_pBase[idx] = v;
    }
    __forceinline unsigned int SetAtGrow(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usMaxSize)
            reinterpret_cast<::FUN_00a5b790_cls *>(this)->FUN_00a5b790(idx + m_usGrowBy);
        SetAt(idx, v);
        return idx;
    }
    __forceinline unsigned int Add(const unsigned short& v)
    {
        return SetAtGrow(m_usSize, v);
    }
    __forceinline void RemoveAll()
    {
        for (unsigned short q = 0; q < m_usSize; q++)
            m_pBase[q] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

struct S00ca5da0_Mesh
{
    static void* operator new(std::size_t size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa10f0(p);
    }
    S00ca5da0_Mesh();
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
};

struct S00ca5da0_Prop
{
    static void* operator new(std::size_t size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa10f0(p);
    }
    S00ca5da0_Prop();
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

    int m_28;
    int m_2c;
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;

    int m_44;
    int unk48;
};

struct S00ca5da0_Shape
{
    static void* operator new(std::size_t size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa10f0(p);
    }
    S00ca5da0_Shape(S00ca5da0_Mesh* mesh);
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

    float m_64;
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
};

struct S00ca5da0_Pt
{
    int x, y, z;
};

struct S00ca5da0_Node
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
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(S00ca5da0_Shape* child, int one);
};

struct S00ca5da0_Builder
{
    int unk00;
    int unk04;
    S00ca5da0_Data* m_08;
    void FUN_00ca5da0(S00ca5da0_Node* parent, S00ca5da0_Pt* pt);
};

// @fnv 0x00ca5da0
void S00ca5da0_Builder::FUN_00ca5da0(S00ca5da0_Node* parent, S00ca5da0_Pt* pt)
{
    TlsGuard_t guard;
    S00ca5da0_Geom* geom = (this ? m_08 : 0)->m_84;
    S00ca5da0_Arr arr;
    unsigned short base = 0;
    unsigned short flag;
    unsigned short c;
    unsigned short prevJ = 0;
    unsigned short a;
    unsigned short j = 0;
    unsigned short b;
    for (int i = 0; i < geom->m_10; i++)
    {
        a = 0;
        b = 0;
        c = 0;
        flag = 0;
        do
        {
            S00ca5da0_Entry* e = &geom->m_14[j];
            if (flag == 0)
            {
                a = e->f0;
                b = e->f1;
                c = e->f2;
                if (a >= base + geom->m_24[i].count)
                    break;
                arr.Add((unsigned short)(a - base));
                arr.Add((unsigned short)(b - base));
                arr.Add((unsigned short)(c - base));
                j++;
                flag = 1;
            }
            else if (b == e->f0 && c == e->f1)
            {
                a = b;
                b = c;
                c = e->f2;
                arr.Add((unsigned short)(a - base));
                arr.Add((unsigned short)(b - base));
                arr.Add((unsigned short)(c - base));
                flag++;
                j++;
            }
            else
            {
                flag = 0;
            }
        } while (a < base + geom->m_24[i].count && j < geom->m_08);

        S00ca5da0_Mesh* mesh = new S00ca5da0_Mesh;
        unsigned short cnt = (unsigned short)geom->m_24[i].count;
        S00ca5da0_Vec3* verts = new S00ca5da0_Vec3[cnt];
        for (unsigned short k = base; k < base + cnt; k++)
        {
            DisplayVector storage;
            __m128& v = *(__m128*)&storage.byteLanes[0];
            float* t = storage.lanes;
            t[0] = geom->m_18[k].x;
            t[1] = geom->m_18[k].y;
            t[2] = geom->m_18[k].z;
            t[3] = 0.0f;
            float x, y, z;
            _mm_store_ss(&x, v);
            _mm_store_ss(&y, _mm_shuffle_ps(v, v, 0x55));
            _mm_store_ss(&z, _mm_shuffle_ps(v, v, 0xaa));
            S00ca5da0_Vec3* d = &verts[k - base];
            d->x = x * DAT_011b1864;
            d->y = y * DAT_011b1864;
            d->z = z * DAT_011b1864;
        }
        reinterpret_cast<::NiGeometryDataRecovered *>((mesh))->FUN_00a66b30(cnt, (::NiPoint3 *)(verts), (::NiPoint3 *)(0), (::RgbaColor *)(0), (::NiPoint2 *)(0), 0, 0);
        unsigned short nTri = (unsigned short)(j - prevJ);
        unsigned short* tris = (unsigned short*)new S00ca5da0_Index[nTri * 3];
        S00ca5da0_Memcpy(tris, arr.m_pBase, arr.m_usSize * sizeof(unsigned short));
        ::FUN_00a7b700((::FUN_00a7b700_T *)(mesh), 0, nTri, (uintptr_t)(tris));

        S00ca5da0_Shape* shape = new S00ca5da0_Shape(mesh);
        ::AssignFixedString((char *)(shape), (intptr_t)&(const ::NiFixedString &)(NiFixedString(::g_012682dc_arg0)), {});
        float f = (float)((double)(::GetField24Float((::FUN_00ca5310_class *)(::S00ca5da0_Builder *)(this))));
        shape->m_64 = (float)fabs(f);
        arr.RemoveAll();

        S00ca5da0_Prop* prop = new S00ca5da0_Prop;
        prop->m_28 = pt->x;
        prop->m_2c = pt->y;
        prop->m_30 = pt->z;
        prop->m_44++;
        reinterpret_cast<::FUN_00439410_cls *>((shape))->FUN_00439410((::ArgObject *)(prop));
        parent->AttachChildInAvailableSlot(shape, 1);
        base += cnt;
        prevJ = j;
    }
}

extern const char DAT_010c9288[];

extern void*(* DAT_00fdf044)(unsigned long);

struct S00cbfaa0_Entry
{
    const char* name;
    unsigned int time;
    unsigned int unk08;
};

struct S00cbfaa0_Stream
{
    int unk00;
    S00cbfaa0_Entry* m_cur;
    int unk08;
    S00cbfaa0_Entry* m_kRayEnd;
};

struct __declspec(align(16)) SinglePointVector
{
    float x, y, z, w;
};

struct S00cbfaa0_Src
{
    SinglePointVector q00;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned char m_20;
};

struct S00cbfaa0_Dst
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S00cbfaa0_Rec
{
    SinglePointVector vec;
    int m_10;
    const void* m_14;
    int m_18;
    int m_1c;
};

struct S00cbfaa0_Base
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
    virtual void vf23(S00cbfaa0_Rec* r, struct S00cbfaa0_Obj* o, int z);
};

struct S00cbfaa0_Obj
{
    int unk00;
    S00cbfaa0_Src* m_04;
    void* m_08;
    int m_0c;
    int m_10;
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
    void* m_44;
    void FUN_00cbfaa0(S00cbfaa0_Base* a0, S00cbfaa0_Src* a1, int a2, S00cbfaa0_Dst* a3, int a4, int a5, int a6);
};

// @fnv 0x00cbfaa0
void S00cbfaa0_Obj::FUN_00cbfaa0(S00cbfaa0_Base* a0, S00cbfaa0_Src* a1, int a2, S00cbfaa0_Dst* a3, int a4, int a5,
                                 int a6)
{
    volatile unsigned int ts;
    void*(* getStream)(unsigned long) = DAT_00fdf044;
    S00cbfaa0_Stream* st = (S00cbfaa0_Stream*)getStream(DAT_0126835c);
    S00cbfaa0_Entry* cur = st->m_cur;
    if (cur < st->m_kRayEnd)
    {
        cur->name = DAT_010c9288;
        _ReadWriteBarrier();
        ts = (unsigned int)__rdtsc();
        cur->time = ts;
        cur = cur + 1;
        st->m_cur = cur;
    }

    m_04 = a1;
    m_08 = a3 ? &a3->unk14 : 0;
    m_0c = a5;
    m_10 = a6;
    if (a1->m_20)
    {
        m_44 = a3 ? &a3->unk10 : 0;
    }
    else
    {
        m_44 = 0;
    }

    S00cbfaa0_Rec r;
    *(__m128*)&r.vec = *(const __m128*)&a1->q00;
    r.m_1c = a4;
    r.m_14 = &a1->unk10;
    r.m_10 = a2;
    r.m_18 = 0x30;
    a0->vf23(&r, this, 0);

    st = (S00cbfaa0_Stream*)getStream(DAT_0126835c);
    cur = st->m_cur;
    if (cur < st->m_kRayEnd)
    {
        cur->name = ::DAT_010c41f8;
        _ReadWriteBarrier();
        ts = (unsigned int)__rdtsc();
        cur->time = ts;
        cur = cur + 1;
        st->m_cur = cur;
    }
}

namespace fnv_00ca1410 {
extern const float DAT_0104da4c;
extern float DAT_0126829c;
extern float DAT_012682a8;
extern const float DAT_01011d78;
extern const float DAT_01012068 = 1.0f;
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline void grow(FNVTaskAllocator& heap, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int doubled = 2 * cap;
            int wanted = n < doubled ? doubled : n;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap), (::SpawnedArray *)(void *)(this), wanted, sizeof(T));
        }
    }
    __forceinline void reserveExact(FNVTaskAllocator& heap, int n)
    {
        if (getCapacity() < n)
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap), (::SpawnedArray *)(void *)(this), n, sizeof(T));
    }
    __forceinline void SetSizeAndGrow(FNVTaskAllocator& heap, int n)
    {
        grow(heap, n);
        size = n;
    }
    __forceinline void setSizeZero(FNVTaskAllocator& heap, int n)
    {
        grow(heap, n);
        int remaining = n - size;
        T* out = data + size;
        for (int k = 0; k < remaining; ++k)
            *out++ = 0;
        size = n;
    }
};
struct RouterView : FNVTaskMemoryRouter
{
    FNVTaskAllocator& heap()
    {
        return *allocator;
    }
    static RouterView& current()
    {
        return *static_cast<RouterView*>(::FUN_00c85750());
    }
};
struct HeapChoice
{
    FNVTaskAllocator& get(const void*)
    {
        return RouterView::current().heap();
    }
};
template <class T> struct WorkArray : ArrayBase<T>
{
    ~WorkArray();
    __forceinline void reserve(int n)
    {
        reserveExact(HeapChoice().get(this), n);
    }
    __forceinline void resize(int n)
    {
        SetSizeAndGrow(HeapChoice().get(this), n);
    }
    __forceinline void resizeZero(int n)
    {
        setSizeZero(HeapChoice().get(this), n);
    }
};
struct SkeletonBone;
struct Transform;
struct Skeleton
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    ArrayBase<SkeletonBone> bones;
    ArrayBase<Transform> reference;
    ArrayBase<char*> slots;
};
struct ScalarValue
{
    __m128 q;
    ScalarValue()
    {}
    ScalarValue(const __m128& v) : q(v)
    {}
    ScalarValue(float f)
    {
        q = _mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, q);
        return f;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
union VectorQuad
{
    __m128 simd;
    float lanes[4];
    signed char bytes[16];
};
struct VectorValue
{
    VectorQuad q;
    VectorValue()
    {}
    VectorValue(float x, float y, float z, float w)
    {
        q.simd = _mm_setr_ps(x, y, z, w);
    }
    VectorValue(const VectorValue& v)
    {
        q.simd = v.q.simd;
    }
    VectorValue(const __m128& v)
    {
        q.simd = v;
    }
    operator __m128() const
    {
        return q.simd;
    }
    void operator=(const __m128& v)
    {
        q.simd = v;
    }
    void operator=(const VectorValue& v)
    {
        q.simd = v.q.simd;
    }
    __forceinline void difference(const VectorValue& a, const VectorValue& b)
    {
        q.simd = _mm_sub_ps(a.q.simd, b.q.simd);
    }
    __forceinline void cross(const VectorValue& a, const VectorValue& b)
    {
        __m128 lhs =
            _mm_mul_ps(_mm_shuffle_ps(a.q.simd, a.q.simd, 0xc9), _mm_shuffle_ps(b.q.simd, b.q.simd, 0xd2));
        __m128 rhs =
            _mm_mul_ps(_mm_shuffle_ps(a.q.simd, a.q.simd, 0xd2), _mm_shuffle_ps(b.q.simd, b.q.simd, 0xc9));
        q.simd = _mm_sub_ps(lhs, rhs);
    }
    __forceinline void add(const VectorValue& a)
    {
        q.simd = _mm_add_ps(q.simd, a.q.simd);
    }
    __forceinline ScalarValue dot(const VectorValue& a) const
    {
        __m128 products = _mm_mul_ps(q.simd, a.q.simd);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), xy);
    }
    __forceinline ScalarValue length() const
    {
        return _mm_sqrt_ss(dot(*this).q);
    }
    __forceinline ScalarValue inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 squared = dot(*this).q;
        __m128 isZero = _mm_cmpeq_ss(squared, zero);
        __m128 estimate = _mm_rsqrt_ss(squared);
        __m128 result = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                       _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
        return _mm_andnot_ps(isZero, result);
    }
    __forceinline void normalize()
    {
        q.simd = _mm_mul_ps(inverseLength().splat(), q.simd);
    }
    __forceinline void scale(const ScalarValue& a, const VectorValue& b)
    {
        q.simd = _mm_mul_ps(a.splat(), b.q.simd);
    }
};
struct Contact
{
    short bone;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    VectorValue point, direction;
};
struct Transform
{
    VectorValue position, rotation, scale;
};
struct FUN_00c7c030
{
    Skeleton* skeleton;
    WorkArray<Transform> localFUN_00c7c030, modelFUN_00c7c030;
    WorkArray<int> flags;
    bool modelSync, localSync;
    WorkArray<float> floats;
    __forceinline FUN_00c7c030(Skeleton* s) : skeleton(s), modelSync(false), localSync(false)
    {
        int n = skeleton->bones.GetLogicalSize();
        modelFUN_00c7c030.resize(n);
        localFUN_00c7c030.resize(n);
        flags.resize(n);
        const int paddedCount = (skeleton->slots.GetLogicalSize() + 3) & ~3;
        floats.reserve(paddedCount);
        floats.resizeZero(skeleton->slots.GetLogicalSize());
    }
    ~FUN_00c7c030();
};
struct BodyHeader
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
    virtual void apply(const VectorValue*, const VectorValue*);
    unsigned int unk04;
    unsigned char type;
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
};
struct Body : BodyHeader
{
    VectorValue position;
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
    VectorValue linearVelocity;
    VectorValue angularVelocity;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    __forceinline void pointVelocity(const VectorValue& point, VectorValue& result) const
    {
        VectorValue offset;
        offset.difference(point, position);
        result.cross(angularVelocity, offset);
        result.add(linearVelocity);
    }
};
struct Properties
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct Meta
{
    unsigned int unk00, unk04, unk08, unk0c;
    Properties props;
};
struct Wrapper
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
    virtual void refresh();
    unsigned int unk04;
    Meta* meta;
    inline Properties* getProps()
    {
        return meta ? &meta->props : 0;
    }
    inline unsigned int GetPropertyFlags()
    {
        Properties* p = getProps();
        return p ? p->flags : 0;
    }
    inline void setFlags(unsigned int value)
    {
        Meta* m = meta;
        if (m)
        {
            ::FUN_00a29680();
            Properties* props = &m->props;
            ::FUN_00a29680();
            if (props)
                props->flags = value;
        }
    }
    inline void changeFlag(bool set)
    {
        unsigned int f = GetPropertyFlags();
        if (((unsigned char)(f >> 14) & 1) != set)
        {
            setFlags(set ? f | 0x4000 : f & ~0x4000);
            refresh();
        }
    }
};
struct World
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
    void* context;
};
struct Bone
{
    unsigned int unk00;
    unsigned int unk04;
    World* world;
    Wrapper* wrapper;
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
    Body body;
};
struct Rig
{
    unsigned int unk00;
    unsigned int unk04;
    ArrayBase<Bone*> bones;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    ArrayBase<int> boneMap;
    Skeleton* skeleton;
    inline Skeleton* getSkeleton() const
    {
        return skeleton;
    }
    inline int getNumBones() const
    {
        return getSkeleton()->bones.GetLogicalSize();
    }
    inline const ArrayBase<Bone*>& getBodies() const
    {
        return bones;
    }
    inline Bone* getBone(int n)
    {
        int index = boneMap[n];
        return index >= 0 ? bones[index] : 0;
    }
    inline World* getWorld()
    {
        Bone* root = bones[0];
        return root ? root->world : 0;
    }
};
struct ByteBoolean
{
    unsigned char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct Controller
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    WorkArray<int> states;
    inline const ArrayBase<int>& getStates() const
    {
        return states;
    }
    ByteBoolean FUN_00d1fb00(FUN_00c7c030&, WorkArray<Contact>&);
};
struct Observer
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
    virtual World* getWorld();
    virtual void v98();
    virtual void setWorld(void*);
};
struct Entry
{
    unsigned int unk00;
    Rig* rig;
    unsigned int unk08;
    Observer* observer;
    Controller* controller;
    WorkArray<Contact> contacts;
    bool active;
};
struct EntryListNode
{
    unsigned int capacity;
    Entry** data;
    unsigned int size;
    inline unsigned int GetLogicalSize() const
    {
        return size;
    }
    __forceinline Entry*& operator[](unsigned int i)
    {
        return data[i];
    }
};
struct UpdateManager
{
    unsigned int unk00;
    EntryListNode entries;
    unsigned int unk10, unk14, unk18, unk1c;
    __int64 startTime, duration;
    void FUN_00ca1410();
};
// @fnv 0x00ca1410
void UpdateManager::FUN_00ca1410()
{
    for (unsigned int i = 0; i < entries.GetLogicalSize(); ++i)
    {
        Entry* entry = entries[i];
        Rig* rig = entry->rig;
        bool excluded = false;
        for (int k = 0; k < rig->bones.GetLogicalSize() && !excluded; ++k)
        {
            unsigned char type = rig->bones[k]->body.type;
            excluded = type == 4 || type == 5;
        }
        if (rig->getWorld() && !excluded && (entry->active || ((long long)(::FUN_00aa4d80())) - startTime <= duration))
        {
            if (((long long)(::FUN_00aa4d80())) - startTime <= duration || entries[i]->active)
                reinterpret_cast<::FUN_00d1fa20_t *>((entries[i]->controller))->ResetEntries();
            FUN_00c7c030 pose(entries[i]->rig->getSkeleton());
            ::FUN_00ce18d0((intptr_t)(entries[i]->rig), (::hkQsTransformC17 *)(&pose));
            if (entries[i]->rig->getWorld() != entries[i]->observer->getWorld())
            {
                World* w = entries[i]->rig->getWorld();
                entries[i]->observer->setWorld(w ? w->context : 0);
            }
            bool wasActive = entries[i]->active;
            entries[i]->active = entries[i]->controller->FUN_00d1fb00(pose, entries[i]->contacts);
            int j;
            if (entries[i]->active)
            {
                const ArrayBase<int>& states = entries[i]->controller->getStates();
                for (j = 0; j < entries[i]->rig->getNumBones(); ++j)
                {
                    Bone* bone = entries[i]->rig->getBone(j);
                    if (bone && bone->wrapper)
                    {
                        Wrapper* wrapper = bone->wrapper;
                        if (states[j])
                        {
                            wrapper->changeFlag(true);
                            if (states[j] == 1)
                            {
                                VectorValue position(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_01011d78);
                                VectorValue direction(DAT_01011d78, DAT_01011d78, DAT_01012068, DAT_01011d78);
                                for (int k = 0; k < entries[i]->contacts.GetLogicalSize(); ++k)
                                {
                                    if (j == entries[i]->contacts[k].bone)
                                    {
                                        position = entries[i]->contacts[k].point;
                                        direction = entries[i]->contacts[k].direction;
                                    }
                                }
                                VectorValue velocity;
                                bone->body.pointVelocity(position, velocity);
                                float speed = velocity.length();
                                float projection;
                                if (speed > ::DAT_0104da4c)
                                {
                                    velocity.normalize();
                                    projection = direction.dot(velocity);
                                }
                                else
                                    projection = 0;
                                float mass = reinterpret_cast<::MotionMassView *>(&(bone->body))->FUN_00c86430();
                                float impulse = mass * (DAT_0126829c - projection * speed);
                                impulse = impulse > DAT_012682a8 ? DAT_012682a8 : impulse;
                                impulse = impulse < -DAT_012682a8 ? -DAT_012682a8 : impulse;
                                VectorValue force;
                                force.scale(ScalarValue(impulse), direction);
                                reinterpret_cast<::hkpEntityC9C *>((bone))->FUN_00c9c1d0();
                                bone->body.apply(&force, &position);
                            }
                        }
                        else
                            wrapper->changeFlag(false);
                    }
                }
            }
            else if (wasActive)
            {
                reinterpret_cast<::FUN_00d1fa20_t *>((entries[i]->controller))->ResetEntries();
                for (j = 0; j < entries[i]->rig->getNumBones(); ++j)
                {
                    Bone* bone = entries[i]->rig->getBone(j);
                    if (bone && bone->wrapper)
                        bone->wrapper->changeFlag(false);
                }
            }
        }
        else
        {
            if (entries[i]->rig->getWorld())
                reinterpret_cast<::FUN_00d1fa20_t *>((entries[i]->controller))->ResetEntries();
        }
    }
}

}

// namespace fnv_00ca1410

template <class T, unsigned Growth> __forceinline T& GetAtSV(BSSimpleArray<T, Growth>& a, int index)
{
    return a.pBuffer[index];
}

union RagdollScalarVector
{
    __m128 simd;
    struct
    {
        float x, y, z, w;
    } scalar;
    signed char bytes[16];
};

struct ScalarValue
{
    float value;
    ScalarValue(float x)
    {
        RagdollScalarVector copy;
        *reinterpret_cast<float*>(&copy.bytes[0]) = x;
        value = copy.scalar.x;
    }
};

namespace RagdollConstruction {
struct FUN_00cb9a90 : S_cb9a90_C
{
    FUN_00cb9a90(intptr_t, intptr_t, float);
};
struct FUN_00cb9a10 : SpawnMidBase
{
    FUN_00cb9a10(char*);
};
struct FUN_00cb9b80 : CB9B80WorldObject
{
    FUN_00cb9b80(CB9B80Info*);
};
}

struct CopyMap
{
    virtual ~CopyMap();
};

struct Init
{
    CopyMap* clones;
    CopyMap* processed;
    int copyType;
    char append;
    Init(unsigned int);
    __forceinline ~Init()
    {
        delete clones;
        delete processed;
    }
};

struct ScaleShapeData
{
    int unk00;
};

struct IntegerBlock18
{
    __forceinline int GetC() const
    {
        return unk0c;
    }
    __forceinline int GetD() const
    {
        return unk10;
    }
    __forceinline void SetC(int v)
    {
        unk0c = v;
    }
    __forceinline void SetD(int v)
    {
        unk10 = v;
    }
    __forceinline ScaleShapeData* GetShape() const
    {
        return shape;
    }
    int unk00;
    ScaleShapeData* shape;
    int unk08;
    int unk0c;
    int unk10;
};

struct ViewPrefix
{
    int prefix;
};

struct ViewPart
{
    int part;
};

struct ShapeView : ViewPrefix, ViewPart
{
    int unk04;
    int unk08;
    int unk0c;
};

struct ShapeRef
{
    virtual void v00();
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
    virtual void SetContext(void*);
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual ViewPart* GetView(char*);
    volatile long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    ScaleShapeData* data;
    int unk0c;
};

struct MaterialShape : ShapeRef
{
    int material;
};

struct FUN_00cb9b30 : ShapeRef
{
    FUN_00cb9b30(IntegerBlock18*);
    static void* operator new(std::size_t size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};

struct FUN_009ba410 : ShapeRef
{
    FUN_009ba410(IntegerBlock18*);
    static void* operator new(std::size_t size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};

struct FUN_00c88380 : ShapeRef
{
    FUN_00c88380(IntegerBlock18*);
    static void* operator new(std::size_t size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};

struct ShapeLink
{
    ShapeLink* next;
    ShapeLink* prev;
    ShapeRef* object;
};

struct Body;

struct Motion
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetMass(float);
};

struct Body
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetShape(ScaleShapeData*);
    int unk04;
    int unk08;
    int unk0c;
    ShapeLink* shapeHead;
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
    float damping90;
    float damping94;
};

struct BodyOwner
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
    virtual void* GetContextOwner();
    int unk04;
    Body* body;
    int unk0c;
    int unk10;
    NiPointer<ShapeRef> shape;
    __forceinline ShapeRef* GetShape(Body* current)
    {
        if (current)
        {
            ::FUN_00a29680();
            ShapeLink** head = &current->shapeHead;
            ::FUN_00a29680();
            if (head && *head)
                return (*head)->object;
        }
        return 0;
    }
    __forceinline void SetMass(const ScalarValue& mass)
    {
        Motion* motion = body ? ((::Motion *)(reinterpret_cast<::FUN_00ca86c0_class *>((body))->FUN_00ca86c0())) : 0;
        if (motion)
            motion->SetMass(mass.value);
        else if (body)
            reinterpret_cast<::FUN_00ca88c0_Class *>((body))->FUN_00ca88c0(mass.value);
    }
    __forceinline void SetAngularDamping(const ScalarValue& a)
    {
        body->damping90 = a.value;
    }
    __forceinline void SetLinearDamping(const ScalarValue& a)
    {
        body->damping94 = a.value;
    }
};

struct CastBody
{
    int unk00, unk04, unk08, unk0c;
    BodyOwner* owner;
};

struct CastObject
{
};

struct SceneObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    CastObject* collision;
};

struct TransformData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float source;
    int unk24, unk28, unk2c;
    float target;
};

struct CloneProcess : Init
{
    float scaleX, scaleY, scaleZ;
    __forceinline CloneProcess(unsigned n) : Init(n)
    {
        scaleX = scaleY = scaleZ = 1.0f;
    }
};

struct ContextOwner
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
    void* context;
};

struct ShapeUpdater
{
    int unk00, unk04, unk08;
    BSSimpleArray<IntegerBlock18*, 1024> shapes;
    BSSimpleArray<unsigned, 1024> kinds;
    float mass, linearDamping, angularDamping, radius;
    int material;
    __forceinline int GetMaterial() const
    {
        return material;
    }
    __forceinline IntegerBlock18* GetInfo(unsigned i)
    {
        return GetAtSV(shapes, i);
    }
    __forceinline unsigned GetKind(unsigned i)
    {
        return GetAtSV(kinds, i);
    }
    void FUN_00cba6f0(SceneObject*, float);
};

static __forceinline NiPointer<ShapeRef>& AssignSV(NiPointer<ShapeRef>& self, const NiPointer<ShapeRef>& other)
{
    if (self.m_pObject != other.m_pObject)
    {
        if (self.m_pObject)
            self.m_pObject->DecRefCount();
        self.m_pObject = other.m_pObject;
        if (self.m_pObject)
            self.m_pObject->IncRefCount();
    }
    return self;
}

struct ScaledShapeData : ScaleShapeData
{
};

struct CapsuleData : ScaleShapeData
{
};

struct ScriptProgram : ScaleShapeData
{
};

// @fnv 0x00cba6f0
void ShapeUpdater::FUN_00cba6f0(SceneObject* object, float scale)
{
    if (!object->collision)
        return;
    CastBody* cast = ((::CastBody *)(reinterpret_cast<::NiObject *>((object->collision))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_012043f8))))));
    if (!cast)
        return;
    BodyOwner* owner = cast->owner;
    if (!owner)
        return;
    Body* body = owner->body;
    if (!body)
        return;
    owner->SetMass(ScalarValue(mass));
    Body* current = owner->body;
    {
        ScalarValue value(angularDamping);
        float* damping = &current->damping90;
        *damping = value.value;
    }
    {
        ScalarValue value(linearDamping);
        float* damping = &current->damping94;
        *damping = value.value;
    }
    MaterialShape* old = (MaterialShape*)owner->GetShape(current);
    old->material = GetMaterial();
    RagdollConstruction::FUN_00cb9a90* replacement = new RagdollConstruction::FUN_00cb9a90(
        intptr_t(old->data ? &((TransformData*)old->data)->source : (const float*)&(*reinterpret_cast<const __m128 *>(&::DAT_01267e30))),
        intptr_t(old->data ? &((TransformData*)old->data)->target : (const float*)&(*reinterpret_cast<const __m128 *>(&::DAT_01267e30))), radius * scale);
    ((RefCounted*)replacement)->IncRefCount();
    replacement->unk10 = GetMaterial();
    ScaleShapeData* scaledData = (ScaleShapeData*)replacement->unk08;
    body->SetShape(scaledData);
    old->DecRefCount();
    ContextOwner* contextOwner = (ContextOwner*)owner->GetContextOwner();
    void* context = contextOwner ? contextOwner->context : 0;
    for (unsigned int i = 0; i < shapes.iSize; ++i)
    {
        if (owner->shape)
        {
            char viewFlag;
            ShapeView* view = static_cast<ShapeView*>(owner->shape->GetView(&viewFlag));
            IntegerBlock18* source = (IntegerBlock18*)view;
            GetAtSV(shapes, i)->SetC(source->unk0c);
            GetAtSV(shapes, i)->SetD(source->unk10);
            ShapeRef* result = 0;
            CloneProcess clone(0x101);
            switch (GetAtSV(kinds, i))
            {
            case 13:
                ::FUN_00ca9940(scale, (::S_00ca9940_Obj *)(::ScaleShapeData *)(GetAtSV(shapes, i)->GetShape()));
                result = (ShapeRef*)new RagdollConstruction::FUN_00cb9a10((char*)GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        ((::Item9bd0 *)((::CreateF4A30Result)((::F4A30Node *)(void *)(GetAtSV(shapes, i)->GetShape()), (void *)(reinterpret_cast<intptr_t>(&clone))))));
                    if (copy)
                    {
                        reinterpret_cast<::C89AC0_Owner *>((GetAtSV(shapes, i)))->SetChildObject((::C89AC0_Child *)(copy));
                        reinterpret_cast<::hkReferencedObjectC905 *>((copy))->FUN_00c905b0();
                    }
                }
                ::FUN_00ca9940(1.0f / scale, (::S_00ca9940_Obj *)(::ScaleShapeData *)(GetAtSV(shapes, i)->GetShape()));
                break;
            case 0:
                ::FUN_00cc96b0(scale, (::S00cc96b0_ScaleObject *)(::ScaleShapeData *)(GetAtSV(shapes, i)->GetShape()));
                result = new FUN_00cb9b30(GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        ((::Item9bd0 *)((::CreateF4A30Result)((::F4A30Node *)(void *)(GetAtSV(shapes, i)->GetShape()), (void *)(reinterpret_cast<intptr_t>(&clone))))));
                    if (copy)
                    {
                        reinterpret_cast<::C89AC0_Owner *>((GetAtSV(shapes, i)))->SetChildObject((::C89AC0_Child *)(copy));
                        reinterpret_cast<::hkReferencedObjectC905 *>((copy))->FUN_00c905b0();
                    }
                }
                ::FUN_00cc96b0(1.0f / scale, (::S00cc96b0_ScaleObject *)(::ScaleShapeData *)(GetAtSV(shapes, i)->GetShape()));
                break;
            case 1:
                ::FUN_00cbd9e0(scale, (::FUN_00cbd9e0_cls *)(::ScaledShapeData *)((ScaledShapeData*)GetAtSV(shapes, i)->GetShape()));
                result = new FUN_009ba410(GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        ((::Item9bd0 *)((::CreateF4A30Result)((::F4A30Node *)(void *)(GetAtSV(shapes, i)->GetShape()), (void *)(reinterpret_cast<intptr_t>(&clone))))));
                    if (copy)
                    {
                        reinterpret_cast<::C89AC0_Owner *>((GetAtSV(shapes, i)))->SetChildObject((::C89AC0_Child *)(copy));
                        reinterpret_cast<::hkReferencedObjectC905 *>((copy))->FUN_00c905b0();
                    }
                }
                ::FUN_00cbd9e0(1.0f / scale, (::FUN_00cbd9e0_cls *)(::ScaledShapeData *)((ScaledShapeData*)GetAtSV(shapes, i)->GetShape()));
                break;
            case 2:
                ::FUN_00cbd9e0(scale, (::FUN_00cbd9e0_cls *)(::CapsuleData *)((CapsuleData*)GetAtSV(shapes, i)->GetShape()));
                result = new FUN_00c88380(GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        ((::Item9bd0 *)((::CreateF4A30Result)((::F4A30Node *)(void *)(GetAtSV(shapes, i)->GetShape()), (void *)(reinterpret_cast<intptr_t>(&clone))))));
                    if (copy)
                    {
                        reinterpret_cast<::C89AC0_Owner *>((GetAtSV(shapes, i)))->SetChildObject((::C89AC0_Child *)(copy));
                        reinterpret_cast<::hkReferencedObjectC905 *>((copy))->FUN_00c905b0();
                    }
                }
                ::FUN_00cbd9e0(1.0f / scale, (::FUN_00cbd9e0_cls *)(::CapsuleData *)((CapsuleData*)GetAtSV(shapes, i)->GetShape()));
                break;
            case 7:
                ::FUN_00cbd9e0(scale, (::FUN_00cbd9e0_cls *)(::ScriptProgram *)((ScriptProgram*)GetAtSV(shapes, i)->GetShape()));
                result =
                    (ShapeRef*)new RagdollConstruction::FUN_00cb9b80((CB9B80Info*)(IntegerBlock18*)GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        ((::Item9bd0 *)((::CreateF4A30Result)((::F4A30Node *)(void *)(GetAtSV(shapes, i)->GetShape()), (void *)(reinterpret_cast<intptr_t>(&clone))))));
                    if (copy)
                    {
                        reinterpret_cast<::C89AC0_Owner *>((GetAtSV(shapes, i)))->SetChildObject((::C89AC0_Child *)(copy));
                        reinterpret_cast<::hkReferencedObjectC905 *>((copy))->FUN_00c905b0();
                    }
                }
                ::FUN_00cbd9e0(1.0f / scale, (::FUN_00cbd9e0_cls *)(::ScriptProgram *)((ScriptProgram*)GetAtSV(shapes, i)->GetShape()));
                break;
            }
            {
                NiPointer<ShapeRef> ref(result);
                if (ref)
                    AssignSV(owner->shape, ref);
            }
            result->SetContext(context);
        }
    }
}

struct FNV_ALIGN(16) VectorComponentValue
{
    float realX, realY, realZ, realW;
    __m128 getRealQuad() const
    {
        return *(const __m128*)this;
    }
    VectorComponentValue(__m128 q)
    {
        *(__m128*)this = q;
    }
    VectorComponentValue(const float& f)
    {
        *(__m128*)this = _mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, getRealQuad());
        return f;
    }
};

inline VectorComponentValue operator*(const VectorComponentValue& a, const VectorComponentValue& b)
{
    return VectorComponentValue(_mm_mul_ss(a.getRealQuad(), b.getRealQuad()));
}

struct FNV_ALIGN(16) hkVector4
{
    float x, y, z, w;
    __m128 getQuad() const
    {
        return *(__m128*)this;
    }
    void setQuad(__m128 q)
    {
        *(__m128*)this = q;
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 mul = _mm_mul_ps(getQuad(), a.getQuad());
        __m128 shuf1 = _mm_shuffle_ps(mul, mul, 0x55);
        __m128 add1 = _mm_add_ss(shuf1, mul);
        __m128 shuf2 = _mm_shuffle_ps(mul, mul, 0xaa);
        return _mm_add_ss(shuf2, add1);
    }
};

struct FNV_ALIGN(16) hkQuaternion
{
    hkVector4 m_vec;
    hkQuaternion& operator=(const hkQuaternion& other)
    {
        m_vec.setQuad(other.m_vec.getQuad());
        return *this;
    }
    void FUN_00cb2a50(const hkVector4& axis);
    void FUN_00c66320(const hkQuaternion& q1, const hkQuaternion& q2);
    void SetConjugate(const hkQuaternion& q)
    {
        m_vec.setQuad(_mm_xor_ps(q.m_vec.getQuad(), *(__m128*)&(*reinterpret_cast<unsigned int *>(&::DAT_010c4c00))));
    }
    void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1)
    {
        hkQuaternion inv0;
        inv0.SetConjugate(q0);
        ::fnv_00c66320::FUN_00c66320((__m128 *)this, (void *)&(inv0), (const __m128 *)&(q1), {});
    }
    float getReal() const
    {
        return m_vec.w;
    }
    const hkVector4& getImag() const
    {
        return m_vec;
    }
    void FUN_00cb2ca0(const hkVector4& axis, hkQuaternion& restOut, float& angleOut) const;
};

__declspec(noinline) void copyQuaternionVector(hkVector4* out, const hkVector4* in)
{
    out->setQuad(in->getQuad());
}
__declspec(noinline) void hkQuaternion::FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b)
{
    __m128 u = a.m_vec.getQuad(), v = b.m_vec.getQuad();
    __m128 cross =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(u, u, 0xc9),
                                                                _mm_shuffle_ps(v, v, 0xd2)),
                                    _mm_mul_ps(_mm_shuffle_ps(u, u, 0xd2),
                                                                _mm_shuffle_ps(v, v, 0xc9)));
    __m128 uw = _mm_shuffle_ps(u, u, 0xff),
                            vw = _mm_shuffle_ps(v, v, 0xff);
    __m128 xyz = _mm_add_ps(_mm_mul_ps(uw, v), cross);
    xyz = _mm_add_ps(_mm_mul_ps(vw, u), xyz);
    __m128 product = _mm_mul_ps(u, v);
    __m128 yz =
        _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 dot =
        _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), yz);
    dot = _mm_shuffle_ps(dot, dot, 0);
    __m128 real = _mm_sub_ps(product, dot);
    hkVector4 result;
    result.setQuad(_mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, real), 0xc4));
    copyQuaternionVector(&m_vec, &result);
}

// @fnv 0x00cb2ca0
void hkQuaternion::FUN_00cb2ca0(const hkVector4& axis, hkQuaternion& restOut, float& angleOut) const
{
    restOut = *this;
    restOut.FUN_00cb2a50(axis);
    hkQuaternion q;
    q.setInverseMul(restOut, *this);
    float angle = reinterpret_cast<::C74C20Quat *>(&(q))->GetAngle();
    angleOut = angle;
    VectorComponentValue dot = axis.dot3(q.getImag());
    VectorComponentValue w = q.getReal();
    if (float(w * dot) < float(VectorComponentValue(*(const float*)&DAT_01011d78)))
    {
        angleOut = -angle;
    }
}

namespace fnv_00cb94a0 {
extern "C" void _ReadWriteBarrier();
extern void* DAT_010c8a2c;
class GlobalObjectO2_00a7b610;
extern void FUN_00a6d220(void* p);
struct ChildInner
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
    float unk194;
};
struct ChildObj
{
    int unk00;
    int unk04;
    ChildInner* unk08;
};
struct DynCastHelper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ChildObj* unk10;
};
struct MyRTTI;
class bhkForceController;
struct MyHost
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DynCastHelper* unk1c;
};
class NiTimeController
{
  public:
    virtual ~NiTimeController();
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
    virtual void V35(float);
    virtual void V36();
    virtual void V37();
    virtual void V38(MyHost*);
    virtual void V39();
    virtual void V40();
    virtual float V41(float);
    long refs04;
    unsigned short unk08, unk0a;
    float unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    MyHost* target2c;
    NiTimeController* next30;
    NiTimeController();
};
class bhkForceController : public NiTimeController
{
  public:
    __m128 unk40;
    float unk50;
    static void operator delete(void*);
    static void* operator new(std::size_t size)
    {
        unsigned char* raw = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>((((Pool_ca57*)&(*reinterpret_cast<::PoolFree_t *>(&::g_memoryManager)))))->FUN_00aa3e40(size + 16);
        unsigned char lo = (unsigned char)(uintptr_t)raw;
        unsigned char pad = 16 - (lo & 15);
        raw += pad;
        GetAlignedBlockPrefix(raw)->m_ucOffset = pad;
        return raw;
    }
    bhkForceController() : unk40(*(__m128*)&(*reinterpret_cast<const __m128 *>(&::DAT_01267e30))), unk50(0.0f)
    {}
    __forceinline void Configure(float duration)
    {
        unk14 = 0.0f;
        unsigned short flags = unk08;
        unk18 = duration;
        flags = (flags & 0xFFF5) | 5;
        unk10 = 0.0f;
        *(volatile unsigned short*)&unk08 = flags;
        unk0c = 1.0f;
    }
};
// @fnv 0x00cb94a0
void __cdecl FUN_00cb94a0(MyHost* param1, const __m128* param2, float param3)
{
    TlsGuard_t guard;
    bhkForceController* controller = ((::fnv_00cb94a0::bhkForceController *)(reinterpret_cast<::MyHost *>((void *)(param1))->FUN_00a5c570((const ::MyRTTI *)(const ::fnv_00cb94a0::MyRTTI *)((const MyRTTI*)&(*reinterpret_cast<::fnv_00cb94a0::GlobalObjectO2_00a7b610 *>(&::g_012683f4))))));
    if (!controller)
    {
        controller = new bhkForceController();
        controller->V38(param1);
    }
    DynCastHelper* castObj =
        !param1->unk1c ? 0 : ((::fnv_00cb94a0::DynCastHelper *)(reinterpret_cast<::NiObject *>((param1->unk1c))->DynamicCast((const ::NiRTTI *)(const ::fnv_00cb94a0::GlobalObjectO2_00a7b610 *)((const GlobalObjectO2_00a7b610*)&(*reinterpret_cast<::fnv_00cb94a0::GlobalObjectO2_00a7b610 *>(&::g_012043f8))))));
    __m128 val = *param2;
    if (castObj && castObj->unk10)
    {
        ChildObj* child = castObj->unk10;
        float scale = reinterpret_cast<::bhkRigidBody *>((child))->GetBodyMass();
        scale = ::DAT_011b1d3c * scale;
        ChildInner* inner = *(ChildInner* const volatile*)&child->unk08;
        __m128 original = *param2;
        __m128 r1 = _mm_load1_ps(&scale);
        double s2 = inner->unk194 * 0.75;
        _ReadWriteBarrier();
        __m128 first = _mm_mul_ps(r1, val);
        scale = (float)s2;
        __m128 r2 = _mm_load_ss(&scale);
        r2 = _mm_shuffle_ps(r2, r2, 0);
        val = _mm_add_ps(_mm_mul_ps(r2, original), first);
    }
    bhkForceController* __restrict output = controller;
    output->Configure(param3);
    output->unk40 = val;
    output->V35(::DAT_01015f5c);
}
}

int __cdecl CombineIndexedMaskAndShift(int a, int b);

struct VecNode
{
    float unk00;
    float unk04;
    float unk08;
    float copyW;
    float x;
    float y;
    float z;
    float w;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
};

// @fnv 0x00cac890
void FUN_00cac890(VecNode* nodes, int count, const __m128* axis)
{
    VecNode* cur = nodes;

    int c = count - 1;
    if (c >= 0)
        do
        {
            float value = cur->w;
            __m128 v = *(__m128 const*)&cur->x;
            float dot;

            cur->copyW = value;

            __m128 prod = _mm_mul_ps(v, *axis);
            __m128 s1 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
            __m128 s2 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), s1);
            _mm_store_ss(&dot, s2);

            cur->w = value * -dot;
            cur++;
        } while (--c >= 0);
}

extern "C" unsigned __int64 __rdtsc(void);

extern char DAT_010c9278;

struct S00cbf950_TraceEntry
{
    const char* name;
    unsigned int tick;
    unsigned int unk08;
};

struct S00cbf950_Trace
{
    int unk00;
    S00cbf950_TraceEntry* next;
    int unk08;
    S00cbf950_TraceEntry* end;
    inline void mark(const char* n, volatile unsigned int& t)
    {
        S00cbf950_TraceEntry* e = next;
        if (e < end)
        {
            e->name = n;
            _ReadWriteBarrier();
            t = (unsigned int)__rdtsc();
            e->tick = t;
            next = e + 1;
        }
    }
};

struct S00cbf950_Input
{
    __m128 low, high, extra;
};

struct S00cbf950_Bounds
{
    __m128 low, high;
};

struct S00cbf950_Body
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
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual unsigned int GetSize();
    virtual void v19();
    virtual void Fill(const S00cbf950_Bounds*, unsigned char*);
};

struct S00cbf950_Target;

struct WorkState
{
    union
    {
        intptr_t offset;
        volatile unsigned int beginTick;
    };
    union
    {
        unsigned int size;
        int remaining;
        volatile unsigned int endTick;
    };
    S00cbf950_Target* volatile owner;
};

struct S00cbf950_Target
{
    void FUN_00cbf950(S00cbf950_Body*, const S00cbf950_Input*, int, intptr_t, intptr_t, int);
};

// @fnv 0x00cbf950
void S00cbf950_Target::FUN_00cbf950(S00cbf950_Body* body, const S00cbf950_Input* input, int count, intptr_t mode,
                                    intptr_t offset, int step)
{
    WorkState state;
    state.owner = this;
    ((S00cbf950_Trace*)TlsGetValue(DAT_0126835c))->mark(&DAT_010c9278, state.beginTick);
    S00cbf950_Bounds bounds;
    __m128 v = input[0].low;
    bounds.low = _mm_min_ps(v, input[0].high);
    bounds.high = _mm_max_ps(v, input[0].high);
    const S00cbf950_Input* cur = input + 1;
    for (int i = count - 2; i >= 0; i--)
    {
        bounds.low = _mm_min_ps(_mm_min_ps(bounds.low, cur->high), cur->low);
        bounds.high = _mm_max_ps(_mm_max_ps(bounds.high, cur->high), cur->low);
        cur++;
    }
    state.size = body->GetSize();
    FNVTaskMemoryRouter* arena = static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750());
    unsigned char* saved = (unsigned char*)arena->unk00;
    arena->unk00 = saved + ((state.size + 127) & ~127);
    body->Fill(&bounds, saved);
    const S00cbf950_Input* walk = input;
    state.offset = offset;
    for (state.remaining = count - 1; state.remaining >= 0; state.remaining--)
    {
        reinterpret_cast<::CbfOwner *>((state.owner))->FUN_00cbf860((::CbfTarget *)(body), (::CbfSrc *)(walk), (int *)(mode), (intptr_t)(saved), state.offset);
        *(volatile intptr_t*)&state.offset += step;
        walk++;
    }
    static_cast<FNVTaskMemoryRouter*>(::FUN_00c85750())->unk00 = saved;
    ((S00cbf950_Trace*)TlsGetValue(DAT_0126835c))->mark(&(*reinterpret_cast<char *>(&::DAT_010c41f8)), state.endTick);
}

#include "generated/data/staging/blk_00ca0000_o2.inc"
#include "generated/data/staging/blk_00ca0000_o2_rtm_variant.inc"
#include "generated/data/staging/blk_00ca0000_o2_gs_ehsc_nogs_noehsc_variant.inc"
