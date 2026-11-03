
// src/havok/physics/utilities/serialize/hkpdisplaybindingdataclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpdisplaybindingdataclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00dff6a0.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_0102e000.h"



struct RefElem_t
{
};

struct RefBase_cls
{
    virtual void a00();
    virtual ~RefBase_cls() throw()
    {}
};

class FUN_00dff640_cls : public RefBase_cls
{
  public:
    unsigned short m_uSize;
    unsigned short m_u06;
    RefElem_t* m_pA;
    RefElem_t* m_pB;

    FUN_00dff640_cls* FUN_00dff640(unsigned char acFlags);
};

// Releases m_pB and m_pA, destroys the base, and if acFlags bit 0 is set frees this through the allocator with m_uSize.
// @fnv 0x00dff640
FUN_00dff640_cls* FUN_00dff640_cls::FUN_00dff640(unsigned char acFlags)
{
    if (m_pB != 0)
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pB))->FUN_00c905b0();
    }
    *(RefElem_t* volatile*)&m_pB = 0;
    RefElem_t* pElemA = *(RefElem_t* volatile*)&m_pA;
    if (pElemA != 0)
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((pElemA))->FUN_00c905b0();
    }
    bool bShouldFree = (acFlags & 1) != 0;
    m_pA = 0;
    this->RefBase_cls::~RefBase_cls();
    if (bShouldFree)
    {
        hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* pAllocator = pHolder->m_heap;
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}

namespace fnv_00dff730 {



struct PtrElem
{
    int unk00;
    void Release();
};


struct FUN_00dff730_cls
{
    const void* m_vptr;
    int unk04;
    void** m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    PtrElem** m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void ClearArrays();
};

// Releases and nulls every element of both pointer arrays, frees their storage via the audio allocator, and resets the vtable pointer.
// @fnv 0x00dff730
void FUN_00dff730_cls::ClearArrays()
{
    hkMemoryRouter* pHolder = (&hkMemoryRouter::getInstance());
    hkMemoryAllocator* pAllocator = pHolder->m_heap;
    PtrElem** pData1 = m_pData1;
    int iCount1 = m_iCount1;
    for (int i = 0; i < iCount1; i++)
    {
        if (pData1[i] != 0)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((pData1[i]))->FUN_00c905b0();
        }
        pData1[i] = 0;
    }
    unsigned int uCapBits1 = m_uCapBits1;
    m_iCount1 = 0;
    if ((uCapBits1 & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pData1, (uCapBits1 & 0x3fffffffu) * (int)sizeof(m_pData1[0]));
    }
    m_pData1 = 0;
    m_uCapBits1 = 0x80000000u;

    hkMemoryRouter* pHolder2 = (&hkMemoryRouter::getInstance());
    hkMemoryAllocator* pAllocator2 = pHolder2->m_heap;
    PtrElem** pData2 = (PtrElem**)m_pData2;
    int iCount2 = m_iCount2;
    for (int j = 0; j < iCount2; j++)
    {
        if (pData2[j] != 0)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((pData2[j]))->FUN_00c905b0();
        }
        pData2[j] = 0;
    }
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((m_uCapBits2 & 0x80000000u) == 0)
    {
        pAllocator2->bufFree(m_pData2, (uCapBits2 & 0x3fffffffu) * (int)sizeof(m_pData2[0]));
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
    m_vptr = &::DAT_0102e388;
}
}  // namespace fnv_00dff730

namespace fnv_00dff810 {
struct Owner
{
    unsigned int unk00;
    unsigned short size4, unk06;
    Owner* FUN_00dff810(unsigned int flags);
};
// Calls FUN_00dff6a0, and if flags has bit 0 set, releases this via the hkMemoryRouter allocator with size4 bytes, then returns this.
// @fnv 0x00dff810
Owner* Owner::FUN_00dff810(unsigned int flags)
{
    reinterpret_cast<::FUN_00dff6a0 *>(this)->FUN_00dff6a0::~FUN_00dff6a0();
    if (flags & 1u)
    {
        hkMemoryRouter* audio = &hkMemoryRouter::getInstance();
        unsigned int bytes = size4;
        audio->m_heap->blockFree(this, bytes);
    }
    return this;
}
}  // namespace fnv_00dff810

namespace fnv_00dff840 {
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* FUN_00dff840(unsigned int flags);
};
// @fnv 0x00dff840
CpuObject* CpuObject::FUN_00dff840(unsigned int flags)
{
    reinterpret_cast<::fnv_00dff730::FUN_00dff730_cls *>(this)->ClearArrays();
    if (flags & 1)
    {
        hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00dff840
