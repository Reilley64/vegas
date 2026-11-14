#ifndef FNV_NICAMERA_H
#define FNV_NICAMERA_H

#include "layout_support.h"
#include "NiObjectNET.h"
#include "NiPoint3.h"
#include "NiProperty.h"
#include "layout_support.h"
class FourComponentFloatVector;
class NiAVObject;
class NiCamera;
class NiCollisionObject;
struct NiFrustum;
struct ThreeByThreeMatrix;
class NiPoint4;
class NiRect_float_;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator;
class NiTListItem_NiPointer_NiProperty___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_NiPointer_NiProperty___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___;
class NiTransform;
class FourComponentNumericValue;
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    unsigned int m_uiCount;
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    NiTListItem_NiPointer_NiProperty___* m_pkHead;
    NiTListItem_NiPointer_NiProperty___* m_pkTail;
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator m_kItemCount;
};
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
};
class NiTPointerList_NiPointer_NiProperty___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
};
class FourComponentNumericValue
{
  public:
    union
    {
        float m_afComponents[4];
        unsigned int m_auiComponents[4];
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float v[4];
        unsigned int u[4];
    };
};
class NiPoint4
{
  public:
    union
    {
        FourComponentNumericValue m_kComponents;
        float m_afExtents[4];
    };
};
struct ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTPointerList_NiPointer_NiProperty___ SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
};
struct NiFrustum
{
  public:
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
    unsigned char layoutPadding19[3];
};
class NiRect_float_
{
  public:
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
class NiCamera : public NiAVObject
{
  public:
    float m_afWorldToCamera[4][4];
    NiFrustum m_kViewFrustum;
    float m_fMinNearPlaneDist;
    float GetMaxFarNearRatio() const;
    float m_fMaxFarNearRatio;
    NiRect_float_ m_kPort;
    float m_fTrailingValue;
};
#endif
