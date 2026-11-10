// gamebryo2.2/corelibs/nianimation/nirotkey_decls.h: declares NiQuaternion, AnimationKey, TimedRotationKey
#ifndef ARMY_NIROTKEY_DECLS_H
#define ARMY_NIROTKEY_DECLS_H


#include "fnv/decl/NiKeyBasedInterpolator.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01097000.h"
#include "fnv/symbols_011f3000.h"
class NiQuaternion
{
  public:
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP = 0,
        LINKEY = 1,
        BEZKEY = 2,
        TCBKEY = 3,
        EULERKEY = 4,
        STEPKEY = 5,
        NUMKEYTYPES = 6
    };
};

class TimedRotationKey
{
  public:
    float m_fTime;
    NiQuaternion m_kRotationValue;

    static NiQuaternion __cdecl InterpolatePosition(float fTime, TimedRotationKey* pkKeys, AnimationKey::KeyType eType,
                                                    unsigned int uiNumKeys, unsigned int& ruiLastIndex,
                                                    unsigned char ucKeySize);
};

typedef void(__cdecl* NiRotKeyInterpFn)(float, const TimedRotationKey*, const TimedRotationKey*, NiQuaternion*);

extern "C" NiRotKeyInterpFn DAT_011f3cc0[];

// Placeholders for the 0x00a3ca30 span (thunk + padding + accessor); rename in one place later.
  // NiKeyBasedInterpolator vtbl (JIP-LN-NVSE)
  // ctor tail-target of the thunk (thiscall, no stack args)

#endif
