
// src/gamebryo2.2/corelibs/nimain/nitristripsdata_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nimain/nitristripsdata.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00a8aa30_shell.h"
#include "fnv/decl/NiObject_b.h"
#include "fnv/decl/fnv_00a761c0__StripLoad.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
#include "nitristripsdata_types_NiTriStripsData.h"
#include "nitristripsdata_forwarders.h"

// @fnv 0x00a75f30
extern "C" const NiRTTI* __cdecl FUN_00a75f30()
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4a70));
}

class NiTriStripsDataWork : public NiTriStripsData
{
  public:
    void FUN_00a75f40(unsigned short& rNumStrips, const unsigned short*& rStripLengths,
                      const unsigned short*& rStripLists, unsigned int& rNumIndices);
};

// @fnv 0x00a75f40
void NiTriStripsDataWork::FUN_00a75f40(unsigned short& rNumStrips, const unsigned short*& rStripLengths,
                                       const unsigned short*& rStripLists, unsigned int& rNumIndices)
{
    rNumStrips = m_usStrips;
    rStripLengths = m_pusStripLengths;
    rStripLists = m_pusStripLists;
    rNumIndices = (unsigned int)(unsigned short)(m_usStrips * 2 + m_usTriangles);
}
