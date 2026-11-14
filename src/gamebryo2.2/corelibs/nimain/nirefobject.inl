#ifndef FNV_ASTRA_NIREF_ARRAY_INL
#define FNV_ASTRA_NIREF_ARRAY_INL
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "nirefobject_types.h"

// @fnv 0x004b0310
template<>
void NiTArray<NiPointer<NiAVObject>,NiTNewInterface<NiPointer<NiAVObject> > >::SetAt(
    unsigned int index,const NiPointer<NiAVObject>& element)
{
    static const NiPointer<NiAVObject> kNull(0);
    if (index >= m_usSize)
    {
        m_usSize = static_cast<unsigned short>(index+1);
        if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(element))->IsNotEqual((const ::DummyStruct_00631820 &)(kNull)))
            m_usESize++;
    }
    else if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(element))->IsNotEqual((const ::DummyStruct_00631820 &)(kNull)))
    {
        if (reinterpret_cast<::FUN_004b0460_class *>((void *)&(const ::NiPointer< ::NiAVObject> &)(m_pBase[index]))->FUN_004b0460((const void **)&(kNull)))
            m_usESize++;
    }
    else if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(m_pBase[index]))->IsNotEqual((const ::DummyStruct_00631820 &)(kNull)))
        m_usESize--;
    m_pBase[index] = element;
}
#endif
