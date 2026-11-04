// Unit-private PC declarations from public JohnnyGuitar TESModelTextureSwap.hpp.
#ifndef FNV_PROCESSLISTS_TESMODELTEXTURESWAP_H
#define FNV_PROCESSLISTS_TESMODELTEXTURESWAP_H

#include "processlists_TESModel.h"
struct DistantTreeTextureInfo;
class TESModelTextureSwap : public TESModel
{
  public:
    TESModelTextureSwap();
    virtual ~TESModelTextureSwap();
    BSSimpleList<DistantTreeTextureInfo*> kTextureSwaps;  // +0x18
};
#endif
