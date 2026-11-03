// Unit-private PC MobileObjectProcessArray layout. Names and signatures from the supplied
#ifndef FNV_PROCESSLISTS_PRIVATE_PROCESSARRAY_H
#define FNV_PROCESSLISTS_PRIVATE_PROCESSARRAY_H

#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/fnv_005de0f0__FUN_005de0f0_shell.h"
#include "processlists_layout_support.h"

class MobileObject;

class MobileObjectProcessArray
{
  public:
    NiTPrimitiveArray<MobileObject*> m_kMobileObjectArray;
    unsigned int m_auiProcessHeadIndices[PROCESS_TYPE_PROCESS_TYPE_COUNT];
    unsigned int m_auiProcessTailIndices[PROCESS_TYPE_PROCESS_TYPE_COUNT];
    unsigned int m_auiNextUpdateIndices[PROCESS_TYPE_PROCESS_TYPE_COUNT];

    MobileObject* GetItem(unsigned int auiIndex) const;  // PC 00968670
        // PC 005DE0F0
        // PC 005BE5C0
    unsigned int GetSize() const;                        // PC 0055B980
    PROCESS_TYPE GetProcessLevelFromIndex(unsigned int auiIndex) const;
    unsigned int GetIndexFromObject(MobileObject* apObject, PROCESS_TYPE aeLevel) const;
};
#endif
