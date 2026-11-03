
// src/fallout_shared/tesleveledlist_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Ob1 /Oy- /GS /EHsc /Gy /GF (unit src/fallout_shared/tesleveledlist.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include <cmath>
#include <cstring>
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/FUN_0040e7f0_owner.h"
#include "fnv/decl/FUN_0040eb90_shell.h"
#include "fnv/decl/FUN_004214f0_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00476be0_Class.h"
#include "fnv/decl/FUN_00481fd0_shell.h"
#include "fnv/decl/FUN_00482040_shell.h"
#include "fnv/decl/FUN_00487790_shell.h"
#include "fnv/decl/FUN_00487980_shell.h"
#include "fnv/decl/FUN_00487a00_shell.h"
#include "fnv/decl/FUN_00488350_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00c4fab0_shell.h"
#include "fnv/decl/Owner487a60.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/fnv_004818e0__FUN_004818e0_t.h"
#include "fnv/decl/fnv_00487840__FUN_00487840_shell.h"
#include "fnv/decl/fnv_00567e10__FUN_00567e10_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/p07__DelStandIn.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_01204000.h"
#include "tesleveledlist_decls.h"
extern "C" int __cdecl _ftol2_sse();

extern const char str_010c3570[];
extern const char str_010c3568[];

class NiRTTI
{
  public:
    const char* GetName() const
    {
        return m_pcName;
    }
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

class NiViewerStringsArray
{
  public:
};

class NiPoint3
{
  public:
    float x, y, z;
    char* FormatToBuffer(const char* pcPrefix) const
    {
        unsigned int uiLen = strlen(pcPrefix) + 64;
        char* pcString = (char*)::FUN_00aa1070(uiLen);
        NiSprintf(pcString, uiLen, "%s = (%g, %g, %g)", pcPrefix, x, y, z);
        return pcString;
    }
public:
    char *FUN_00a59af0(const char *);
};

inline char* CreateDebugString(const char* pcText)
{
    unsigned int uiLen = strlen(pcText) + 9;
    char* pcString = (char*)::FUN_00aa1070(uiLen);
    NiSprintf(pcString, uiLen, "%s", pcText);
    return pcString;
}

inline char* CreateDebugString(const char* pcPrefix, float fValue)
{
    unsigned int uiLen = strlen(pcPrefix) + 20;
    char* pcString = (char*)::FUN_00aa1070(uiLen);
    double dValue = fValue;
    NiSprintf(pcString, uiLen, "%s = %g", pcPrefix, dValue);
    return pcString;
}

class NiBaseModifier
{
  public:
    void* m_ppVirtualMethodTable;
    int m_iRefCount;
    int m_unk08;
};

class NiPointModifier : public NiBaseModifier
{
  public:
    float GetAttributeStrength() const
    {
        return m_fValue;
    }
    void FUN_00c61120(NiViewerStringsArray* pkStrings);

    NiPoint3 m_kPathOffset;
    NiPoint3 m_kLightVector;
    float m_fValue;
};

// @fnv 0x00c61120
void NiPointModifier::FUN_00c61120(NiViewerStringsArray* pkStrings)
{
    reinterpret_cast<::FUN_00c4fab0_shell *>(this)->FUN_00c4fab0((int)(pkStrings));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d330((*reinterpret_cast<::NiRTTI *>(&::g_01204398)).GetName())));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(reinterpret_cast<::NiPoint3 *>((void *)&(m_kPathOffset))->FUN_00a59af0(str_010c3570)));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(reinterpret_cast<::NiPoint3 *>((void *)&(m_kLightVector))->FUN_00a59af0(str_010c3568)));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(const char *const &)(::FUN_00a7d550((*reinterpret_cast<const char (*)[]>(&::UNK_01015a9c)), GetAttributeStrength())));
}

#include "generated/data/fallout_shared/tesleveledlist_ob1_variant.inc"
