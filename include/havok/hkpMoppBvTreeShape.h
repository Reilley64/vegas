// Shared native MOPP construction and lifetime. Geometry queries are separate.
#ifndef FNV_HAVOK_HKPMOPPBVTREESHAPE_H
#define FNV_HAVOK_HKPMOPPBVTREESHAPE_H

#include "hkBase.h"
#include "hkMoppBvTreeShapeBase.h"
#include "hkpSingleShapeContainer.h"
class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
{
  public:
    hkpMoppBvTreeShape(hkpShape* child, const hkpMoppCode& code);
    ~hkpMoppBvTreeShape() override;
    const hkpShape* getChild() const noexcept { return m_pChildAtom.getChild(); }
    const hkpShapeContainer& getContainer() const noexcept { return m_pChildAtom; }
    hkpSingleShapeContainer m_pChildAtom;
    hkInt32 m_iChildSize; // Written by the separate child-size query, not construction.
};
#endif
