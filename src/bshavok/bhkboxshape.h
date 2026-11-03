// bshavok/bhkboxshape.h: declares bhkBoxShape
#ifndef BHKBOXSHAPE_H
#define BHKBOXSHAPE_H


#include "fnv/symbols_01268000.h"
class NiRTTI;
class hkVector4;

class bhkBoxShape
{
  public:
    unsigned int m_uiRefCount;
    void* m_pHavokObject;
    void* pInfo;
    unsigned int m_uiMaterial;

    void Init(const hkVector4& halfExtents);
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x0056e7f0
const NiRTTI* bhkBoxShape::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_01268264));
}

#endif
