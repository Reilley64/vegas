// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMDATA_H
#define FNV_NITRANSFORMDATA_H

#include "layout_support.h"
#include "NiObject.h"
class TimedAnimationKey;
class PositionKeyInterpolator;
class TimedRotationKey;
class NiTransformData;
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
class NiTransformData : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned short m_usNumRotKeys;    // +0x8, 2 bytes
    unsigned short m_usNumPosKeys;    // +0xA, 2 bytes
    unsigned short m_usNumScaleKeys;  // +0xC, 2 bytes
    unsigned char layoutPaddingE[2];
    NiAnimationKey__KeyType m_eRotationKeyType;  // +0x10, 4 bytes
    NiAnimationKey__KeyType m_ePositionKeyType;  // +0x14, 4 bytes
    NiAnimationKey__KeyType m_eScaleKeyType;     // +0x18, 4 bytes
    unsigned char m_ucRotationKeySize;           // +0x1C, 1 bytes
    unsigned char m_ucPositionKeySize;           // +0x1D, 1 bytes
    unsigned char m_ucScaleKeySize;              // +0x1E, 1 bytes
    unsigned char layoutPadding1F[1];
    TimedRotationKey* m_pkRotationKeys;         // +0x20, 4 bytes
    PositionKeyInterpolator* m_pkPositionKeys;  // +0x24, 4 bytes
    TimedAnimationKey* m_pkScaleKeyArray;       // +0x28, 4 bytes
    // const NiRTTI* __cdecl NiTransformData::*()
    // void __cdecl NiTransformData::*(NiStream&)
    // void __cdecl NiTransformData::*(NiStream&)
    // bool __cdecl NiTransformData::*(NiStream&)
    // void __cdecl NiTransformData::*(NiStream&)
    // bool __cdecl NiTransformData::*(NiObject*)
    // NiObject* __cdecl NiTransformData::*()
    // void __cdecl NiTransformData::*(NiTPrimitiveArray<char *>*)
    // NiTransformData
    // void __cdecl NiTransformData::*()
    // unsigned int __cdecl NiTransformData::*()
    // unsigned int __cdecl NiTransformData::*()
    // unsigned int __cdecl NiTransformData::*()
    // void __cdecl NiTransformData::*(float, float)
    // void __cdecl NiTransformData::*(float, float, NiPointer<NiTransformData>&)
    // NiTransformData& __cdecl NiTransformData::*(const NiTransformData&)
    // void __cdecl NiTransformData::*()
};
#endif
