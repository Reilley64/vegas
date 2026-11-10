// gamebryo2.2/corelibs/nianimation/niblendfloatinterpolator_pre.h: declares NiBinaryStream

#include "fnv/symbols_01096000.h"
#include "fnv/symbols_0109a000.h"
struct NiStream;
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
};

