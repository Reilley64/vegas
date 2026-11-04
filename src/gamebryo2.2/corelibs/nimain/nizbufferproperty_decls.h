// gamebryo2.2/corelibs/nimain/nizbufferproperty_decls.h: declares NiAlphaAccumulator, NiAlphaProperty
#include "fnv/symbols_010a1000.h"
class NiAlphaAccumulator
{
  public:
    NiAlphaAccumulator();
    unsigned char storage[0x30];
};
class NiAlphaProperty : public NiAlphaAccumulator
{
  public:
    NiAlphaProperty();
    unsigned char enabled, flag1, flag2;
};
