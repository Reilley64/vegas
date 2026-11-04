// include/havok/hkpDisplayBindingDataRigidBody.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPDISPLAYBINDINGDATARIGIDBODY_H
#define FNV_HAVOK_HKPDISPLAYBINDINGDATARIGIDBODY_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxMesh;
class hkpDisplayBindingDataRigidBody : public hkReferencedObject
{
  public:
    void* m_pRigidBody;      // +0x8
    hkxMesh* m_pMesh;        // +0xC
    hkMatrix4 m_kTransform;  // +0x10
};
#endif
