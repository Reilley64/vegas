// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsaudio/bsaudiodefines.h
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00ae7f90  NiTPointerListBase<NiTPointerAllocator<unsigned int>,SoundMessageRecord*>::RemoveHead  (117 bytes)
//   0x00ae8770  BSAudioDefinition::BSAudioDefinition  (189 bytes)
//   0x00ae8830  BSAudioDefinition::~BSAudioDefinition  (129 bytes)
//   0x00ae88c0  BSAudioDefinition::operator=  (304 bytes)
//   0x00ae8a40  BSSoundInfo::BSSoundInfo  (173 bytes)
//   0x00ae8af0  BSSoundInfo::~BSSoundInfo  (74 bytes)
//
// BSAudioDefinition and BSSoundInfo are declared in
// include/fnv/bs_audio_definition.h.
#ifndef FNV_BSAUDIODEFINES_H
#define FNV_BSAUDIODEFINES_H


#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/bs_audio_definition.h"
#include "bsaudiodefines_decls.h"
#include <string.h>

class SoundMessageRecord;

template <class Allocator, class T>
// @fnv 0x00ae7f90
T NiTPointerListBase<Allocator, T>::RemoveHead()
{
    NiTListItem<T>* pOldHead;
    int iPad1;
    int iPad2;
    int iPad3;
    T kElement;
    kElement = reinterpret_cast<T>(m_pkHead);
    m_pkHead = m_pkHead->m_pkNext;
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    pOldHead = reinterpret_cast<NiTListItem<T>*>(reinterpret_cast<NiTListItem<T>*>(kElement)->m_element);
    reinterpret_cast<NiTListItem<T>*>(kElement)->m_element = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(m_kItemCount))->FUN_0045cee0(reinterpret_cast<NiTListItem<T>*>(kElement));
    m_kItemCount.m_uiCount--;
    return reinterpret_cast<T>(pOldHead);
}

// @fnv 0x00ae86d0
SoundMessageRecord::~SoundMessageRecord()
{
    if (pObject)
        ::FUN_00c45830((::MyRef *)(::NiAVObject *)(pObject));
}

#endif
