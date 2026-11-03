// include/havok/hkxEnvironment.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKXENVIRONMENT_H
#define FNV_HAVOK_HKXENVIRONMENT_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxEnvironmentVariable;
class hkxEnvironment : public hkReferencedObject
{
  public:
    hkArray<hkxEnvironmentVariable> m_kVariables;  // +0x8
};
#endif
