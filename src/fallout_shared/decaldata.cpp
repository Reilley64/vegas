// fallout_shared/decaldata.cpp: DecalData (6 functions)

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00485000.h"
#include "decaldata_decls.h"
#include "TESFile.h"
// @fnv 0x005932b0
void DecalData::Copy(DecalData* source)
{
    if (source)
        memcpy(this, source, sizeof(ImpactDecalData));
}

// @fnv 0x00593240
DecalData::DecalData()
{
    Data.m_fDecalMinHeight = 8.0f;
    Data.m_fDecalMaxHeight = 32.0f;
    Data.m_fDecalMinWidth = 8.0f;
    Data.m_fDecalMaxWidth = 32.0f;
    Data.m_ucParallaxPasses = 4;
    Data.m_fParallaxScale = 1.0f;
    Data.m_fProjectionDepth = 32.0f;
    Data.m_fShininess = 4.0f;
    Data.iColor = 0xFFFFFFFF;
}

struct FUN_005932e0_shell
{
    bool Compare(void* apCompare);
};


// Returns true if apCompare is null or the first 0x24 bytes differ from this; otherwise returns false.
// @fnv 0x005932e0
bool FUN_005932e0_shell::Compare(void* apCompare)
{
    if (apCompare == 0)
        return true;
    if (std::memcmp(this, apCompare, 0x24) != 0)
        return true;
    return false;
}

template <int N> struct EndianSizeTag
{
};


struct FUN_00593370_shell
{
    void SwapEndianFields();
};
// @fnv 0x00593450
void DecalData::Load(TESFile* file)
{
    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(this), sizeof(ImpactDecalData));
    if (file->IsEndianConversionRequired())
        reinterpret_cast<::FUN_00593370_shell *>(this)->SwapEndianFields();
}

// Byte-swaps eight 4-byte fields of this object via BSEndian, in the order 0,1,2,3,6,4,5,8.
// @fnv 0x00593370
void FUN_00593370_shell::SwapEndianFields()
{
    ::FUN_00401080((int*)this);
    ::FUN_00401080((int*)this + 1);
    ::FUN_00401080((int*)this + 2);
    ::FUN_00401080((int*)this + 3);
    ::FUN_00401080((int*)this + 6);
    ::FUN_00401080((int*)this + 4);
    ::FUN_00401080((int*)this + 5);
    ::FUN_00401080((int*)this + 8);
}

struct FUN_00593320_shell
{
    void FUN_00593320(void*);
};
// @fnv 0x00593320
void FUN_00593320_shell::FUN_00593320(void* a1)
{
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00593370_shell *>((((DecalData*)this)))->SwapEndianFields();
    ::AppendChunk((std::uintptr_t)(a1), this, 0x24);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00593370_shell *>((((DecalData*)this)))->SwapEndianFields();
}
