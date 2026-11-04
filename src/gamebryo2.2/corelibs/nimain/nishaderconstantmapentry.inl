
#include "fnv/decl/NiRefObject.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "nishaderconstantmapentry_decls.h"
// @fnv 0x00e81ba0
NiShaderConstantMapEntry::NiShaderConstantMapEntry()
{
    m_pVTable = &(*reinterpret_cast<unsigned char *>(&::DAT_0101dce4));
    m_uiRefCount = 0;
    InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    m_pVTable = &kVtbl_NiShaderConstantMapEntry;
    m_bEnableState = true;
    m_kControlPoint = (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220));
    m_uiValue1 = 0;
    m_uiValue2 = 0;
    m_uiValue3 = 0;
    m_uiValue4 = 0;
    *reinterpret_cast<char* volatile*>(&m_kSecondaryString.m_kHandle) = (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle;
    volatile NiShaderConstantMapEntry* ordered = this;
    ordered->m_uiValue5 = 0;
    ordered->m_uiValue6 = 0;
    ordered->m_pConstantData = 0;
    ordered->m_bFlag0 = false;
    ordered->m_bFlag1 = false;
    ordered->m_bFlag2 = false;
}
