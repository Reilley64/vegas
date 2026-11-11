// fallout_shared/bgsidlecollection.cpp: BGSIdleCollection, StandIn, IdleCollectionStandIn (14 functions)

#include <cstring>
#include <malloc.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b2010_shell.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00479000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0101a000.h"
#include "bgsidlecollection_decls.h"

// @fnv 0x004797e0
void BGSIdleCollection::InitializeComponent()
{
    m_ucIdleCount = 0;
    m_ucPickType = 0;
    m_ppIdleForms = 0;
    m_fIdleChance = 0.0f;
}

// @fnv 0x00479c40
void BGSIdleCollection::Load(TESFile* file)
{
    int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()));
    if (::IsIdleCollectionChunk(chunk))
    {
        switch (chunk)
        {
        case 0x464c4449:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_ucIdleCount), 1);
            break;
        case 0x434c4449:
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 1)
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_ucPickType), 1);
            else
            {
                unsigned int count = 0;
                file->GetChunkData(&count);
                m_ucPickType = (unsigned char)count;
            }
            if (m_ucPickType)
            {
                if (m_ppIdleForms)
                    delete[] m_ppIdleForms;
                m_ppIdleForms = new TESIdleForm*[m_ucPickType];
                memset(m_ppIdleForms, 0, m_ucPickType * sizeof(*m_ppIdleForms));
            }
            break;
        case 0x414c4449:
            if (m_ppIdleForms)
            {
                unsigned int size = m_ucPickType * 4;
                if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == size)
                {
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_ppIdleForms), size);
                    if (file->IsEndianConversionRequired())
                        for (int i = 0; i < m_ucPickType; ++i)
                            ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&m_ppIdleForms[i])));
                }
            }
            break;
        case 0x544c4449:
            file->GetChunkData(reinterpret_cast<unsigned int*>(&m_fIdleChance));
            break;
        }
    }
}

struct Arr
{
    void** GetAt(int);
};
struct SArgs
{
    int i;
    void* const* v;
};

// @fnv 0x0047a030
unsigned int BGSIdleCollection::GetAvailableIdles(Actor* actor, TESObjectREFR* target,
                                                  BSSimpleArray<TESIdleForm*, 1024>* idles)
{
    unsigned int count = 0;
    if (actor)
    {
        unsigned int size = 0;
        if (idles)
            size = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((idles))->FUN_0084e3a0()));
        for (int i = 0; i < m_ucPickType; ++i)
        {
            TESIdleForm* idle = m_ppIdleForms[i];
            if (idle && reinterpret_cast<::FUN_008b2010_shell *>((actor))->HasIdleInFormArray(idle) &&
                idle->IsValidForReferences(reinterpret_cast<TESObjectREFR*>(actor), target, true))
            {
                if (idles)
                {
                    if (count < size)
                        ::FUN_0047a110((::Arr *)(idles), ::SArgs{(int)count, (void* const*)&idle});
                    else
                        reinterpret_cast<::FUN_00438690 *>((idles))->FUN_007cb2e0((unsigned int *)&(idle));
                }
                ++count;
            }
        }
    }
    return count;
}

// Returns true if chunk matches one of six IDLE-family chunk IDs, otherwise false.
// @fnv 0x00479e20
bool IsIdleCollectionChunk(int chunk)
{
    switch (chunk)
    {
    case 0x464c4449:
    case 0x414c4449:
    case 0x424c4449:
    case 0x434c4449:
    case 0x4e4c4449:
    case 0x544c4449:
        return true;
    default:
        return false;
    }
}

// @fnv 0x00479e80
int BGSIdleCollection::GetPickType()
{
    if (m_ucIdleCount & 1)
        return 1;
    return 0;
}


// @fnv 0x00479790
void* FUN_00479790(BaseFormComponent* pThis)
{
    ::FUN_00402d30((int *)(pThis));
    *(int**)pThis = &(*reinterpret_cast<int *>(&::fnv_004797c0::DAT_0101abd8));
    reinterpret_cast<::BGSIdleCollection *>((pThis))->InitializeComponent();
    return pThis;
}

// Stores the value pointed to by a.v into the element of self at index a.i.
// @fnv 0x0047a110
void FUN_0047a110(Arr* self, SArgs aArgs)
{
    *self->GetAt(aArgs.i) = *aArgs.v;
}

namespace fnv_004797c0 {

struct FUN_004797c0_shell
{
    void FUN_00479810();
    void FUN_004797c0();
};

// @fnv 0x004797c0
void FUN_004797c0_shell::FUN_004797c0()
{
    *reinterpret_cast<void**>(this) = &DAT_0101abd8;
    FUN_00479810();
}
}  // namespace fnv_004797c0

struct BGSIdleCollection_shell : BGSIdleCollection
{
    bool IsDifferentFrom(BaseFormComponent* other);
};

// @fnv 0x00479930
bool BGSIdleCollection_shell::IsDifferentFrom(BaseFormComponent* other)
{
    BGSIdleCollection* idle = dynamic_cast<BGSIdleCollection*>(other);
    if (!idle)
        return true;
    if (this->m_ucIdleCount != idle->m_ucIdleCount)
        return true;
    if (this->m_ucPickType != idle->m_ucPickType)
        return true;
    if (this->m_fIdleChance != idle->m_fIdleChance)
        return true;
    if ((*reinterpret_cast<const TESIdleForm**>((void *)&this->m_ppIdleForms)) && (*reinterpret_cast<const TESIdleForm**>((void *)&idle->m_ppIdleForms)) &&
        memcmp((*reinterpret_cast<const TESIdleForm**>((void *)&this->m_ppIdleForms)), (*reinterpret_cast<const TESIdleForm**>((void *)&idle->m_ppIdleForms)),
               this->m_ucPickType * sizeof(*this->m_ppIdleForms)))
        return true;
    return false;
}

struct StandIn
{
    char _pad0[5];
    unsigned char _c5;
    char _pad6[2];
    void* _p8;
    void FUN_00479810();
};
// @fnv 0x00479810
void StandIn::FUN_00479810()
{
    void* idleArray = _p8;
    ::FUN_00401030(idleArray);
    _c5 = 0;
    _p8 = 0;
}

struct _DeallocateHelper
{
};
struct __memcpyHelper
{
};
struct FUN_00479850_shell : BGSIdleCollection
{
    void FUN_00479850(BaseFormComponent* apCopyFC);
};
// Copies the idle count, reallocates and copies the idle form array from apCopyFC, and copies the extra field.
// @fnv 0x00479850
void FUN_00479850_shell::FUN_00479850(BaseFormComponent* apCopyFC)
{
    BGSIdleCollection* pSource = dynamic_cast<BGSIdleCollection*>(apCopyFC);
    if (!pSource)
        return;
    m_ucIdleCount = pSource->m_ucIdleCount;
    {
        TESIdleForm** pOld = m_ppIdleForms;
        ::FUN_00401030(pOld);
    }
    m_ppIdleForms = 0;
    m_ucPickType = 0;
    if (pSource->m_ucPickType)
    {
        m_ppIdleForms = new TESIdleForm*[pSource->m_ucPickType];
        ::__memcpy(m_ppIdleForms, pSource->m_ppIdleForms, pSource->m_ucPickType * sizeof(*m_ppIdleForms));
        m_ucPickType = pSource->m_ucPickType;
    }
    m_fIdleChance = pSource->m_fIdleChance;
}

struct FUN_004799f0_shell : BaseFormComponent
{
    unsigned char m_ucIdleCount;  // +0x04
    unsigned char m_ucPickType;   // +0x05
    TESForm** m_ppIdleForms;      // +0x08
    float m_fIdleChance;          // +0x0c
    void FUN_004799f0();
};

// @fnv 0x004799f0
void FUN_004799f0_shell::FUN_004799f0()
{
    unsigned int isize3;
    unsigned int* parray;
    unsigned int i;

    if (m_ucPickType)
    {
        FUN_004858f0(0x464c4449, m_ucIdleCount);
        FUN_004858f0(0x434c4449, m_ucPickType);
        ::FUN_00485910(0x544c4449, m_fIdleChance);

        isize3 = m_ucPickType << 2;
        parray = (unsigned int*)_alloca(isize3);

        for (i = 0; i < m_ucPickType; i++)
        {
            if (m_ppIdleForms[i] != 0)
                parray[i] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_ppIdleForms[i]))->FUN_0084e3a0()));
            else
                parray[i] = 0;
        }

        ::FUN_00485710((void *)(0x414c4449), parray, (void *)(std::uintptr_t)(m_ucPickType));
    }
}


class TESForm;

struct IdleCollectionStandIn
{
    int unk00;
    unsigned char m_ucIdleCount;
    unsigned char m_ucPickType;
    unsigned short unk06;
    TESForm** m_ppIdleForms;
    void RemoveAt(unsigned int index);
};
// Resolves each stored form ID to a TESObjectANIO idle, keeps valid idles, and warns and removes entries that are missing or lack an animation.
// @fnv 0x00479b00
void BGSIdleCollection::InitItem(TESForm* form)
{
    TESObjectANIO* idle;

    idle = 0;
    for (unsigned int index = 0; index < m_ucPickType; ++index)
    {
        unsigned int formID;
        formID = (unsigned int)(std::uintptr_t)(m_ppIdleForms[index]);
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        idle = dynamic_cast<TESObjectANIO*>(::FUN_004839c0(formID));
        if (idle)
        {
            if (static_cast<TESIdleForm*>(idle)->IsIdleFile())
            {
                m_ppIdleForms[index] = static_cast<TESIdleForm*>(idle);
            }
            else
            {
                ::FUN_005b5e40();
                reinterpret_cast<::IdleCollectionStandIn *>(this)->RemoveAt(index);
                --index;
            }
        }
        else
        {
            ::FUN_005b5e40();
            reinterpret_cast<::IdleCollectionStandIn *>(this)->RemoveAt(index);
            --index;
        }
    }
}

// Removes the element at index from the array, shrinking the count and reallocating the array without that element.
// @fnv 0x00479ea0
void IdleCollectionStandIn::RemoveAt(unsigned int index)
{
    if (index < m_ucPickType)
    {
        if (m_ucPickType == 1)
        {
            m_ucPickType = 0;
            delete m_ppIdleForms;
            m_ppIdleForms = 0;
        }
        else
        {
            m_ucPickType--;
            int n;
            TESForm** newArrayA = new TESForm*[m_ucPickType];
            n = index;
            if (n > 0)
            {
                __memcpy(newArrayA, m_ppIdleForms, n * 4);
            }
            n = m_ucPickType - index;
            if (n > 0)
            {
                __memcpy(&newArrayA[index], &m_ppIdleForms[index + 1], n * 4);
            }
            delete m_ppIdleForms;
            m_ppIdleForms = newArrayA;
        }
    }
}
