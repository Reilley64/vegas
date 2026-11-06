// Native retained single child; not a serialized object layout.
#ifndef FNV_HAVOK_HKPSINGLESHAPECONTAINER_H
#define FNV_HAVOK_HKPSINGLESHAPECONTAINER_H

#include "hkBase.h"
#include "hkpShapeContainer.h"
class hkpShape;
class hkpSingleShapeContainer : public hkpShapeContainer
{
  public:
    // Fresh construction requires a live, non-null child.
    explicit hkpSingleShapeContainer(hkpShape*);
    ~hkpSingleShapeContainer() override;
    hkpSingleShapeContainer(const hkpSingleShapeContainer&) = delete;
    hkpSingleShapeContainer& operator=(const hkpSingleShapeContainer&) = delete;
    const hkpShape* getChild() const noexcept { return m_pContainedShape; }
    hkpShape* m_pContainedShape;
};
#endif
