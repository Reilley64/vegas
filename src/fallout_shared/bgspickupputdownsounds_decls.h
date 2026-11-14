// fallout_shared/bgspickupputdownsounds_decls.h: declares TESIcon, TESSound, BGSCameraPath
#ifndef FNV_BGSPICKUPDOWNSOUNDS_DECLS_H
#define FNV_BGSPICKUPDOWNSOUNDS_DECLS_H

#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "TESForm.h"
#include "TESTexture.h"
class TESIcon : public TESTexture
{
  public:
    TESIcon();
};
class TESSound : public TESForm
{
};
class BGSCameraShot;
template <class> class BSSimpleList;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
public:
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
#endif
