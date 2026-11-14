// gamebryo2.2/corelibs/niparticle/nipsysboundupdatemodifier_decls.h: declares NiBound, NiPSysModifier, NiPSysBoundUpdateModifier
#ifndef FNV_NIPSYSBOUNDUPDATEMODIFIER_DECLS_H
#define FNV_NIPSYSBOUNDUPDATEMODIFIER_DECLS_H

#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include "NiFixedString.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "MemoryManager.h"

struct NiParticleSystem;

struct NiBound
{
  public:
    NiPoint3 m_kCenter;
    union
    {
        float m_fBoundRadius;
        int m_iRadius;
    };
    void SetCenterAndRadius(const NiPoint3& center, float radius)
    {
        m_kCenter = center;
        m_fBoundRadius = radius;
    }
};

struct NiPSysModifier : public NiObject
{
  public:
    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
};

class NiPSysBoundUpdateModifier : public NiPSysModifier
{
  public:
    short m_usUpdateSkip;
    unsigned short m_usUpdateSkipCounter;
    NiBound* m_pkBounds;
    // The PC body reads a full stack slot and narrows both the stored skip and count.
    void SetUpdateSkipCounter(int iUpdateSkip);
};

#endif
