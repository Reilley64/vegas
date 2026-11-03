// src/gamebryo2.2/corelibs/nicollision/nitrigon.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nitrigon.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004a0c10_s.h"
struct EB3830Point3
{
    float x;
    float y;
    float z;

    EB3830Point3()
    {}
    EB3830Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    EB3830Point3 Cross(const EB3830Point3& pt) const
    {
        return EB3830Point3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
    }
};

struct EB3830Triangle
{
    int unk00;
    int unk04;
    int unk08;
    EB3830Point3 m_kEdgeA;
    EB3830Point3 m_kEdgeB;

    EB3830Point3 FUN_00eb3830() const;
};

// Computes the cross product of m_kEdgeA and m_kEdgeB, normalizes it, and returns the resulting vector.
// @fnv 0x00eb3830
EB3830Point3 EB3830Triangle::FUN_00eb3830() const
{
    EB3830Point3 kNormal = m_kEdgeA.Cross(m_kEdgeB);
    reinterpret_cast<::FUN_004a0c10_s *>(&(kNormal))->FUN_004a0c10();
    return kNormal;
}
