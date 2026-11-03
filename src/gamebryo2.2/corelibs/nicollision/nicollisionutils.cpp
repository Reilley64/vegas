// gamebryo2.2/corelibs/nicollision/nicollisionutils.cpp: RayTriangleIntersector (1 function)

#include "fnv/decl/FUN_004b6190_shell.h"
#include "nicollisionutils_decls.h"
// @fnv 0x00eadb90
bool RayTriangleIntersector::IntersectRayTriangle(const NiPoint3& aOrigin, const NiPoint3& aDirection,
                                                  const NiPoint3& aVertex0, const NiPoint3& aVertex1,
                                                  const NiPoint3& aVertex2, bool cull, NiPoint3& hit, float& t,
                                                  float& u, float& v)
{
    NiPoint3 edge1 = aVertex1 - aVertex0;
    NiPoint3 edge2 = aVertex2 - aVertex0;
    NiPoint3 pVec = aDirection.Cross(edge2);
    float det = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(edge1))->DotProduct((void *)&(pVec));
    if (det >= 0.00001f)
    {
        NiPoint3 sVec = aOrigin - aVertex0;
        u = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(sVec))->DotProduct((void *)&(pVec));
        if (u < 0.0f || u > det)
            return false;
        NiPoint3 qVec = sVec.Cross(edge1);
        v = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(aDirection))->DotProduct((void *)&(qVec));
        if (v < 0.0f || u + v > det)
            return false;
        t = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(edge2))->DotProduct((void *)&(qVec));
        if (t < 0.0f)
            return false;
    }
    else if (det <= -0.00001f && !cull)
    {
        NiPoint3 sVec = aOrigin - aVertex0;
        u = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(sVec))->DotProduct((void *)&(pVec));
        if (u > 0.0f || u < det)
            return false;
        NiPoint3 qVec = sVec.Cross(edge1);
        v = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(aDirection))->DotProduct((void *)&(qVec));
        if (v > 0.0f || u + v < det)
            return false;
        t = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(edge2))->DotProduct((void *)&(qVec));
        if (t > 0.0f)
            return false;
    }
    else
        return false;
    float fInvDet = 1.0f / det;
    u *= fInvDet;
    v *= fInvDet;
    t *= fInvDet;
    hit = aOrigin + NiPosData::ComputePositionAtTime(t, aDirection);
    return true;
}
