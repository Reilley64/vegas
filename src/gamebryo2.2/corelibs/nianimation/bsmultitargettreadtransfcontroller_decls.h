// gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller_decls.h: declares TreadEntry, BSMultiTargetTreadTransfController
#include "fnv/symbols_00a2d000.h"
#include "fnv/symbols_00aa2000.h"
class NiInterpolator;
struct TreadEntry
{
    char data[0x34];
};
class BSMultiTargetTreadTransfController
{
    char padding[0x34];
    TreadEntry* entries;

  public:
    NiInterpolator* GetInterpolator(unsigned short index);
};
extern unsigned int DAT_011f36a0;
class GlobalObject_00a2e180
{
  public:
    GlobalObject_00a2e180();
};
