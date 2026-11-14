#include "havok/SimpleContactRhs.h"

#include <cmath>
#include <cstdio>

namespace {
bool near(float a, float b) { return std::fabs(a - b) < 0.000002f; }
}

int main()
{
    if (DAT_011b6924 != 1.0f || DAT_011b6928 != 0.05f) return 1;
    PhysicsMaterial material{};
    material.m_fAccumulatedImpulse = 7.0f;
    material.m_ulUserData = 0x12345678;
    material.m_fSlipAngle.m_uiFilterValue = 19;
    material.m_fElasticity = 21;
    material.m_usFlags.m_uiFilterValue = 23;
    material.m_flags = 29;
    int modified = 37;
    auto check = [&](float offset, float impulse, float distance, float dt,
                     float expectedRhs, float expectedOffset) {
        material.m_uiUserData = offset;
        material.m_fImpulseLimit = impulse;
        const float rhs = calculateRhs(nullptr, material, distance, dt, modified);
        return near(rhs, expectedRhs) && near(material.m_uiUserData, expectedOffset) &&
               material.m_fImpulseLimit == impulse && material.m_fAccumulatedImpulse == 7.0f &&
               material.m_ulUserData == 0x12345678 && material.m_fSlipAngle.m_uiFilterValue == 19 &&
               material.m_fElasticity == 21 && material.m_usFlags.m_uiFilterValue == 23 &&
               material.m_flags == 29 && modified == 37;
    };
    if (!check(-2.0f, 1.0f, 3.0f, 0.1f, 4.9f, -1.9f)) return 2;
    if (!check(-2.0f, 1.0f, -4.0f, 0.1f, -1.1f, -2.9f)) return 3;
    if (!check(-0.02f, 0.0f, 0.0f, 0.1f, 0.019f, -0.019f)) return 4;
    material.m_uiUserData = 0.0f;
    material.m_fImpulseLimit = 0.0f;
    if (calculateRhs(nullptr, material, 0.0f, 0.1f, modified) != 0.0f ||
        material.m_uiUserData != -1.192092896e-07f) return 5;
    DAT_011b6924 = 2.0f;
    DAT_011b6928 = 0.25f;
    if (!check(-2.0f, 1.0f, 3.0f, 0.1f, 4.8f, -1.8f)) return 6;
    DAT_011b6924 = 1.0f;
    DAT_011b6928 = 0.05f;
    std::puts("Retained simple-contact RHS: bounded relaxation, correction, clamp, shared controls and untouched fields passed");
}
