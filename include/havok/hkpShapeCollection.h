// Shared native collection state and typed child retrieval.
#ifndef FNV_HAVOK_HKPSHAPECOLLECTION_H
#define FNV_HAVOK_HKPSHAPECOLLECTION_H

#include "hkBase.h"
#include "hkpShape.h"
#include "hkpShapeContainer.h"
class hkpShapeBuffer;
class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
  public:
    enum CollectionType
    {
        COLLECTION_LIST = 0,
        COLLECTION_EXTENDED_MESH = 1,
        COLLECTION_TRISAMPLED_HEIGHTFIELD = 2,
        COLLECTION_USER = 3,
        COLLECTION_SIMPLE_MESH = 4,
        COLLECTION_MESH_SHAPE = 5,
        COLLECTION_COMPRESSED_MESH = 6,
        COLLECTION_MAX = 7
    };
    virtual const hkpShape* getChildShape(hkUint32 key, hkpShapeBuffer& buffer) const = 0;
    hkBool m_bDisableWelding;
    hkUint8 m_eCollectionType;

  protected:
    hkpShapeCollection(hkUint32 type, CollectionType collectionType) noexcept
        : hkpShape(type), m_bDisableWelding(0), m_eCollectionType(collectionType) {}
};
#endif
