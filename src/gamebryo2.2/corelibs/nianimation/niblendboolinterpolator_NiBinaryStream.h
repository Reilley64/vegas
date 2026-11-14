// gamebryo2.2/corelibs/nianimation/niblendboolinterpolator_NiBinaryStream.h: declares NiBinaryStream
#ifndef FNV_NIBLENDBOOLINTERPOLATOR_NIBINARYSTREAM_H
#define FNV_NIBLENDBOOLINTERPOLATOR_NIBINARYSTREAM_H



#include "fnv/symbols_01096000.h"
#include "fnv/symbols_0109a000.h"
class NiBinaryStream;
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
};
#endif
