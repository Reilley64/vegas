// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADCHANGESMAP_H
#define FNV_BGSSAVELOADCHANGESMAP_H

#include <cstdint>
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/symbols_00845000.h"
#include "layout_support.h"
#include "layout_support.h"
class FormChangeRecord;
class FormChangeMask;
class BGSSaveLoadChangesMap;
class BGSSaveLoadChangesMapBase
{
  public:
    unsigned int layout[4];
};
class BGSSaveLoadChangesMap : public BGSSaveLoadChangesMapBase
{
  public:
    // base NiTPointerMap<unsigned int,FormChangeRecord *> at +0x0, size 16
    BGSSaveLoadChangesMap();
    FormChangeRecord* FUN_009a4250(uintptr_t formID);
    bool ContainsChangeFlags(unsigned int formID, FormChangeMask flags);
    void AddFormChangeFlags(unsigned int formID, FormChangeMask flags);
    void ApplyFormQuantityChange(unsigned int formID, FormChangeMask flags);
    bool HasFormChanges(uintptr_t formID);
    bool ClearChangeFlags(unsigned int formID, FormChangeMask flags);
    // BGSSaveLoadChangesMap
    // void __cdecl BGSSaveLoadChangesMap::*()
    // void __cdecl BGSSaveLoadChangesMap::*()
    // FormChangeRecord* __cdecl BGSSaveLoadChangesMap::*(unsigned int)
    // FormChangeMask __cdecl BGSSaveLoadChangesMap::*(unsigned int)
    // bool __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // void __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // void __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // bool __cdecl BGSSaveLoadChangesMap::*(unsigned int)
    // bool __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // BGSSaveLoadChangesMap& __cdecl BGSSaveLoadChangesMap::*(const BGSSaveLoadChangesMap&)
    // void __cdecl BGSSaveLoadChangesMap::*()
public:
    ~BGSSaveLoadChangesMap();
};
#endif
