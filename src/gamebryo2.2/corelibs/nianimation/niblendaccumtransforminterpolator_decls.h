
#include "fnv/decl/FUN_00a386a0_shell.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011f3000.h"
class NiObjectNET;
class NiPoint3
{
  public:
    float x, y, z;
public:
    static const ::NiPoint3 ZERO;
};
class NiQuaternion
{
  public:
    float w, x, y, z;
public:
    static const ::NiQuaternion IDENTITY;
};
class NiStream;
class NiQuatTransform
{
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
public:
    NiQuatTransform();
public:
    void LoadBinary(::NiStream &);
public:
    bool IsInvalid() const;
};
struct AccumItem
{
    float time;
    NiQuatTransform value, accum;
    float rotation[9];
};
class NiBlendAccumTransformInterpolator
{
  public:
    char prefix[12];
    unsigned char m_uiObjectFlags, m_ucArraySize, m_ucInterpCount, m_ucSingleIdx;
    char rest[16];
    float m_fSingleInterpolatorTime;
    char rest2[12];
    NiQuatTransform m_kAccumulatedTransform;
    AccumItem* m_pAccumulationData;
    bool m_bHasAccumulation;
    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiQuatTransform&);
};
