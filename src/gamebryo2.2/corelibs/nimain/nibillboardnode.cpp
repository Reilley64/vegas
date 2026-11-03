// gamebryo2.2/corelibs/nimain/nibillboardnode.cpp: NiBillboardNode (1 function)

#include "fnv/symbols_011f4000.h"
class NiRTTI;

class NiBillboardNode
{
  public:
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x0051cf90
const NiRTTI* NiBillboardNode::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4aa0));
}
