// Unit-local PC header for fallout_shared/tesimagespace.cpp.
// ImageSpaceModifierParameterData (152 bytes, +0x18 in TESImageSpace) and
// TESImageSpace strName +0xB0 (184 bytes total). Additions for this unit:
// ImageSpaceModifierParameterData::Endian (target 0x00b8ad00, defined in another
// unit, only declared here) and the two covered member declarations.
#ifndef FNV_TESIMAGESPACE_UNIT_H
#define FNV_TESIMAGESPACE_UNIT_H

#include "fnv/decl/B8AD00Header.h"
#include "layout_support.h"
#include "TESForm.h"
#include "TESFile.h"
#include "layout_support.h"
class ImageSpaceModifierParameterData;
class TESImageSpace;
class ImageSpaceModifierParameterData
{
  public:
    float m_afFirstParameterSet[15];        // +0x0, 60 bytes
    float m_afSecondParameterSet[3];        // +0x3C, 12 bytes
    float m_afThirdParameterSet[3];         // +0x48, 12 bytes
    float m_afFourthParameterSet[4];        // +0x54, 16 bytes
    float m_afColorAndAlphaParameters[12];  // +0x64, 48 bytes
    unsigned int ShaderConstantData;        // +0x94, 4 bytes
    // void __cdecl ImageSpaceModifierParameterData::*()
      // 0x00b8ad00; defined in another unit, declared here only
};
class TESImageSpace : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    ImageSpaceModifierParameterData Data;  // +0x18, 152 bytes
    BSStringT<char> strName;               // +0xB0, 8 bytes
    virtual void ResetFormData();
    virtual bool Load(TESFile* file);
    // TESImageSpace
    // void __cdecl TESImageSpace::*()
    // const ImageSpaceModifierParameterData* __cdecl TESImageSpace::*()
    // bool __cdecl TESImageSpace::*(unsigned int)
    // void __cdecl TESImageSpace::*(unsigned int, bool)
    // bool __cdecl TESImageSpace::*(TESFile*)
    // void __cdecl TESImageSpace::*()
    // void __cdecl TESImageSpace::*(TESForm*)
    // bool __cdecl TESImageSpace::*(TESForm*)
    // void __cdecl TESImageSpace::*()
    // void __cdecl TESImageSpace::*()
    // void __cdecl TESImageSpace::*()
    // TESImageSpace& __cdecl TESImageSpace::*(const TESImageSpace&)
    // void __cdecl TESImageSpace::*()
};
#endif
