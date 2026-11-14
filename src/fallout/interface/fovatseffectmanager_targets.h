// fallout/interface/fovatseffectmanager_targets.h: declares NiPoint2, ShadowLightData
#ifndef FNV_FOVATSEFFECTMANAGER_TARGETS_H
#define FNV_FOVATSEFFECTMANAGER_TARGETS_H

#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011f4000.h"
#include "layout_support.h"
#include "fovatseffectmanager_shader.h"
class NiAVObject;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer(NiAVObject*);
    ~NiPointer();
    NiPointer& operator=(NiAVObject*);
};
class FUN_007002d0
{
  public:
    unsigned char unknown00[36];
    bool enabled;
    unsigned char unknown25[7];
    FUN_007002d0();
    ~FUN_007002d0();
};
struct NiPoint2
{
  public:
    float x, y;
    NiPoint2();
};
class GlobalObject_0044f440;
class ShadowLightData
{
  public:
    NiPointer<NiAVObject> m_spTargetObject;
    FUN_007002d0 state;
    NiPoint2 point0, point1, point2, point3;
    ImageSpaceShaderParam* pShaderParams;
    bool effectEnabled;
    float duration;
    float intensity;
    float radius;
    ShadowLightData();
    static void SetTargetMaskForSelection(unsigned int selectedIndex, unsigned __int64 targetMask);
};
#endif
