// Source layout: TESTexture. PC corrections are in generate_headers.py.
#ifndef FNV_TESTEXTURE_H
#define FNV_TESTEXTURE_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;  // +0x4
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
#endif
