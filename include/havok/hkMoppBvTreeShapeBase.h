// Native MOPP code owner and borrowed query data, not an object-layout view.
#ifndef FNV_HAVOK_HKMOPPBVTREESHAPEBASE_H
#define FNV_HAVOK_HKMOPPBVTREESHAPEBASE_H

#include "hkpShape.h"
#include <span>
class hkpMoppCode;
class hkMoppBvTreeShapeBase : public hkpShape
{
  public:
    ~hkMoppBvTreeShapeBase() override;
    const hkpMoppCode& getMoppCode() const noexcept { return *m_pMoppCode; }
    std::span<const hkUint8> getMoppData() const noexcept { return {m_pMoppData, m_uiMoppDataSize}; }
    const hkVector4& getMoppCodeInfo() const noexcept { return m_kMoppCodeInfo; }

  protected:
    hkMoppBvTreeShapeBase(hkUint32 type, const hkpMoppCode&);

  public:
    hkUint8 m_bvTreeType;
    const hkpMoppCode* m_pMoppCode;
    const hkUint8* m_pMoppData;
    hkUint32 m_uiMoppDataSize;
    hkVector4 m_kMoppCodeInfo;
};
#endif
