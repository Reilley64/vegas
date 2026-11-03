// bssystemutilities/bssystemutilitiesstrings.h: declares MemoryManager, BSSystemUtilitiesStrings
#ifndef FNV_BSSYSTEMUTILITIESSTRINGS_H
#define FNV_BSSYSTEMUTILITIESSTRINGS_H


#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_011f6000.h"
#include "layout_support.h"

class MemoryManager
{
  public:
};


#pragma pack(push, 4)
class BSSystemUtilitiesStrings
{
  public:
    char* m_pStringFunctions[8];  // +0x4 (vtable is at +0x0 automatically from virtual functions!)

    virtual ~BSSystemUtilitiesStrings();
    virtual void Initialize();
    virtual void Destroy();
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(BSSystemUtilitiesStrings) == 36);
FNV_STATIC_ASSERT(offsetof(BSSystemUtilitiesStrings, m_pStringFunctions) == 4);

#endif
