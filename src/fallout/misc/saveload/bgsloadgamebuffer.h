// fallout/misc/saveload/bgsloadgamebuffer.h: declares BGSLoadGameBuffer
#ifndef FNV_BGSLOADGAMEBUFFER_H
#define FNV_BGSLOADGAMEBUFFER_H

#include "fnv/symbols_00401000.h"
#include "bgsloadgamebuffer_decls.h"
class BGSLoadGameBuffer
{
  public:
    void** m_ppVirtualMethodTable;
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
    void ResetReadPosition();
};

// @fnv 0x00848d50
void BGSLoadGameBuffer::ResetReadPosition()
{
    void* buffer = pBuffer;
    ::FUN_00401030(buffer);
    pBuffer = 0;
    iBufferSize = 0;
    m_uiReadOffset = 0;
}
#endif
