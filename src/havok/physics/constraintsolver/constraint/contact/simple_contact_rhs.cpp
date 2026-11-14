#include "havok/SimpleContactRhs.h"
#include "havok/hkBase.h"

#include <type_traits>

static_assert(std::is_same_v<hkReal, float>);

float DAT_011b6924 = 1.0f;
float DAT_011b6928 = 0.05f;

// Retained RHS reader used by FUN_00d72190. Neither unused argument conveys an
// additional contact/material layout contract.
hkReal calculateRhs(const hkContactPoint*, PhysicsMaterial& sr, hkReal distance, hkReal dt,
                    int&)
{
    hkReal distanceOffset = sr.m_uiUserData;
    hkReal RHS = distance - distanceOffset;
    const hkReal estimatedRHS = -sr.m_fImpulseLimit;
    const hkReal secondOrderError = estimatedRHS - RHS;
    const hkReal maxDiff = dt * DAT_011b6924;
    hkReal distanceOffsetRelaxation = MathUtilities::min2(-DAT_011b6928 * distanceOffset, maxDiff);
    distanceOffset += distanceOffsetRelaxation;
    RHS -= distanceOffsetRelaxation;
    if (secondOrderError > 2.0 * distanceOffsetRelaxation + maxDiff)
    {
        distanceOffset -= secondOrderError;
        RHS += secondOrderError;
    }
    sr.m_uiUserData = MathUtilities::min2(distanceOffset, -1.192092896e-07f);
    return RHS;
}
