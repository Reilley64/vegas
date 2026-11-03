// gamebryo2.2/corelibs/nimain/nistencilproperty.cpp: NiStencilProperty (1 function)

#include "fnv/symbols_011f4000.h"
class NiRTTI;

class NiStencilProperty
{
  public:
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x0049ed30
const NiRTTI* NiStencilProperty::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4a0c));
}
