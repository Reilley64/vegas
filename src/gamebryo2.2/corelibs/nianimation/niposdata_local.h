// Authored header for gamebryo2.2/corelibs/nianimation/niposdata.inl.
//
// NiPosData has no canonical generated header in the tree; its layout and
//
// The tree's canonical NiPoint3.h is a layout-only struct; this unit
// additionally declares the out-of-line NiPoint3::Set(float, float, float)
// that the runtime binary binds at 0x00416870.
#ifndef FNV_NIPOSDATA_LOCAL_H
#define FNV_NIPOSDATA_LOCAL_H

#include "fnv/decl/FUN_00416870_t.h"
#include "layout_support.h"
#include "NiObject.h"
class PositionKeyInterpolator;
enum NiAnimationKey__KeyType
{
    NiAnimationKey__KeyType_NOINTERP = 0,
    NiAnimationKey__KeyType_LINKEY = 1,
    NiAnimationKey__KeyType_BEZKEY = 2,
    NiAnimationKey__KeyType_TCBKEY = 3,
    NiAnimationKey__KeyType_EULERKEY = 4,
    NiAnimationKey__KeyType_STEPKEY = 5,
    NiAnimationKey__KeyType_NUMKEYTYPES = 6
};
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
};
class NiPosData : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned int m_uiNumKeys;                // +0x8, 4 bytes
    PositionKeyInterpolator* m_pKeyArray;    // +0xC, 4 bytes
    NiAnimationKey__KeyType m_eRequestType;  // +0x10, 4 bytes
    unsigned char m_ucKeyDataSize;           // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    static NiPoint3* ComputePositionAtTime(NiPoint3* pOut, float fTime, const NiPoint3* pIn);
};
#endif
