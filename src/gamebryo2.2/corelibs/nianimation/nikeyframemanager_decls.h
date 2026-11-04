// gamebryo2.2/corelibs/nianimation/nikeyframemanager_decls.h: declares NiGeomMorpherController
#ifndef NIKEYFRAMEMANAGER_DECLS_H
#define NIKEYFRAMEMANAGER_DECLS_H

#include <cstdint>
#include "fnv/decl/Twin_0044ddc0.h"
class GlobalObject_00869f00
{
  public:
};
class NiNode;
template <class T> class NiPointer
{
  public:
    T* operator->() const;

  private:
    T* m_pObject;
};
class NiGeomMorpherController
{
  public:
    uintptr_t GetNumTargets() const;

  private:
    unsigned char m_controllerData[0x38];
    NiPointer<NiNode> m_spMorphTargetData;
};
#endif
