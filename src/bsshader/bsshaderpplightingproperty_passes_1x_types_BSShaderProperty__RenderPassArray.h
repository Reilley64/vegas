// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERPROPERTY_RENDERPASSARRAY_H
#define FNV_BSSHADERPROPERTY_RENDERPASSARRAY_H

#include "layout_support.h"
#include "layout_support.h"
class BSShaderProperty__RenderPass;
class NiGeometry;
class ShadowSceneLight;
class BSShaderProperty__RenderPassArray;
class BSShaderProperty__RenderPassArray
{
  public:
    NiTObjectArray<BSShaderProperty__RenderPass*> m_kRenderPasses;  // +0x0, 16 bytes
    unsigned int iSize;                                             // +0x10, 4 bytes
    void Add(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*,
             ShadowSceneLight*);
};
#endif
