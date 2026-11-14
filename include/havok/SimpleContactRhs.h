#pragma once

#include "fnv/symbols_010c7000.h"
#include "havok/SimpleContactSettings.h"

// These are the existing simple-contact property types. Field meanings beyond
// their retained source use are not inferred from their names.
class QuantizedFloat8
{
  public:
    operator float() const { return ::DAT_010c7948[m_uiFilterValue]; }
    unsigned char m_uiFilterValue;
};

class hkContactPointMaterial
{
  public:
    float getFriction() const { return m_fSlipAngle; }
    unsigned int m_ulUserData;
    QuantizedFloat8 m_fSlipAngle;
    unsigned char m_fElasticity;
    QuantizedFloat8 m_usFlags;
    unsigned char m_flags;
};

class ContactImpulseInfo
{
  public:
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
};

class PhysicsMaterial : public ContactImpulseInfo, public hkContactPointMaterial
{
  public:
    float m_uiUserData;
};

namespace MathUtilities {
template <typename T> inline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

class hkContactPoint;

float calculateRhs(const hkContactPoint* ccp, PhysicsMaterial& sr, float distance,
                   float dt, int& solverResultsModified);
