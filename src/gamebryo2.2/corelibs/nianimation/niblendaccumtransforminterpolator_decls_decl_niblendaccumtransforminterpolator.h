
#include "fnv/decl/FUN_00a386a0_shell.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011f3000.h"
class NiObjectNET;
class NiPoint3
{
  public:
    float x, y, z;
};
class NiQuaternion
{
  public:
    float w, x, y, z;
};
class NiQuatTransform
{
  public:
    bool IsInvalid() const;  // declared for the original code (decl_variants.py)
  public:
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    NiQuatTransform CombineTransforms(const NiQuatTransform&);
    bool IsMarkedInvalid() const
    {
        return m_fScale == -3.4028234663852886e38 && m_kRotate.x == -3.4028234663852886e38 &&
               m_kTranslate.x == -3.4028234663852886e38;
    }
};
struct AccumRotationMatrix
{
    float m[9];
};
struct AccumItem
{
    float time;
    NiQuatTransform value, accum;
    AccumRotationMatrix rotation;
};
struct InterpArrayItem
{
    void* interpolator;
    float weight;
    float normalizedWeight;
    char priority;
    char pad0d[3];
    float easeSpinner;
    float updateTime;
};
class NiBlendAccumTransformInterpolator
{
  public:
    char prefix[12];
    unsigned char m_uiObjectFlags, m_ucArraySize, m_ucInterpCount, m_ucSingleIdx;
    char rest10[4];
    InterpArrayItem* m_pInterpArray;
    char rest18[8];
    float m_fSingleInterpolatorTime;
    char rest2[12];
    NiQuatTransform m_kAccumulatedTransform;
    AccumItem* m_pAccumulationData;
    bool m_bHasAccumulation;
    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiQuatTransform&);
};
