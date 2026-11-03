
// src/effectsetting_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/effectsetting.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/EndianSwappableData.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FUN_008ce390_shell.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "effectsetting_decls.h"

struct BEB3890Body
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    float m_fBoundRadius;
};

static const float NI_INFINITY = 3.402823466e+38f;

class BEB3890Base
{
  public:
    BEB3890Base(float fA, float fB, float fC, int iD);
    virtual ~BEB3890Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
};

class FUN_00eb3890_cls : public BEB3890Base
{
  public:
    FUN_00eb3890_cls(BEB3890Body* pkBodyA, BEB3890Body* pkBodyB, float fA, float fB, float fC, int iD);
    virtual ~FUN_00eb3890_cls();

    BEB3890Body* m_pkBodyA;
    BEB3890Body* m_pkBodyB;
    float m_fInvRadiusSq;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

// @fnv 0x00eb3890
FUN_00eb3890_cls::FUN_00eb3890_cls(BEB3890Body* pkBodyA, BEB3890Body* pkBodyB, float fA, float fB, float fC, int iD)
    : BEB3890Base(fA, fB, fC, iD), m_pkBodyA(pkBodyA), m_pkBodyB(pkBodyB)
{
    m_fInvRadiusSq = 1.0f / (pkBodyB->m_fBoundRadius * pkBodyB->m_fBoundRadius);
    m_fVectorY = NI_INFINITY;
    m_fVectorZ = NI_INFINITY;
    m_fScalarPart = NI_INFINITY;
}
