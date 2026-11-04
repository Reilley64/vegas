// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESREGION_DECLS_H
#define FNV_TESREGION_DECLS_H

#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "layout_support.h"
#include "tesregion_TESForm.h"
#include "layout_support.h"
class NiColor;
class TESRegion;
class RegionDataList;
class RegionPointList;
class TESWeather;
class NiColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    // void __cdecl NiColor::*(float, float, float)
    // bool __cdecl NiColor::*(const NiColor&)
    // bool __cdecl NiColor::*(const NiColor&)
    // NiColor __cdecl NiColor::*(const NiColor&)
    // operator-
    // operator*
    // operator/
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // operator*=
    // operator/=
    // void __cdecl NiColor::*()
    // void __cdecl NiColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiColor::*(const char*)
    // float __cdecl NiColor::*()
    // void __cdecl NiColor::*()
};
class TESRegion : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    RegionDataList* m_pRegionDataList;                 // +0x18, 4 bytes
    BSSimpleList<RegionPointList*>* pRegionPointList;  // +0x1C, 4 bytes
    TESWorldSpace* m_pContainingWorldspace;            // +0x20, 4 bytes
    TESWeather* m_pRegionWeather;                      // +0x24, 4 bytes
    float fWeatherChance;                              // +0x28, 4 bytes
    NiColor m_kDiffuseColor;                           // +0x2C, 12 bytes
    virtual void ClearData();
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    void AssignWorldSpace(TESWorldSpace* world);
    // TESRegion
    // void __cdecl TESRegion::*()
    // void __cdecl TESRegion::*()
    // bool __cdecl TESRegion::*(TESFile*)
    // void __cdecl TESRegion::*()
    // void __cdecl TESRegion::*()
    // RegionDataList* __cdecl TESRegion::*()
    // BSSimpleList<RegionPointList *>* __cdecl TESRegion::*()
    // TESWorldSpace* __cdecl TESRegion::*()
    // void __cdecl TESRegion::*(TESWorldSpace*)
    // TESWeather* __cdecl TESRegion::*()
    // void __cdecl TESRegion::*(TESWeather*)
    // float __cdecl TESRegion::*()
    // void __cdecl TESRegion::*(float)
    // void __cdecl TESRegion::*()
    // void __cdecl TESRegion::*()
    // float __cdecl TESRegion::*()
    // float __cdecl TESRegion::*()
    // float __cdecl TESRegion::*()
    // float __cdecl TESRegion::*()
    // NiColor* __cdecl TESRegion::*()
    // unsigned short __cdecl TESRegion::*()
    // void __cdecl TESRegion::*()
    // void __cdecl TESRegion::*()
    // TESRegion& __cdecl TESRegion::*(const TESRegion&)
    // void __cdecl TESRegion::*()
};
#endif
