// gamebryo2.2/corelibs/nimain/console/nipoint3_decls.h: declares NiPoint3, NiPlane
#ifndef FNV_NIPOINT3_CONSOLE_DECLS_H
#define FNV_NIPOINT3_CONSOLE_DECLS_H


#include "fnv/decl/Point3_0053d280.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_01017000.h"
#include "layout_support.h"

// Private declarations retain the canonical twelve-byte PC vector layout.
class NiPoint3
{
  public:
    float x;
    float y;
    float z;

    NiPoint3(float fX, float fY, float fZ);
    float ComputeMagnitude() const;
    float GetLengthSquared();
    NiPoint3 CrossProduct(const NiPoint3& kPoint) const;
};



class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
    NiPlane(const NiPoint3& kNormal, const NiPoint3& kPoint);
};

#endif
