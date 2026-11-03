// fallout_shared/sky/stars_decls.h: declares SkyObject, Stars
#ifndef FNV_STARS_DECLS_H
#define FNV_STARS_DECLS_H
#include "fnv/decl/F940Owner.h"
class NiNode;
class SkyObject
{
  public:
    const void* m_pVtable;
    NiNode* m_pRoot;          // +0x04
};
class Stars : public SkyObject
{
  public:
    void Initialize(NiNode*);
    NiNode* m_pStarsNode;     // +0x08
    float m_fAlpha;           // +0x0C
};
#endif
