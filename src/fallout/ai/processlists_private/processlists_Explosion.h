// Unit-private PC Explosion declaration. Public layout facts and real virtual
// declarations only. ApplyBlastEffects is the supplied pack's actual candidate.
#ifndef FNV_PROCESSLISTS_PRIVATE_EXPLOSION_H
#define FNV_PROCESSLISTS_PRIVATE_EXPLOSION_H

#include "fnv/decl/ProjCls.h"
#include "processlists_MobileObject.h"
#include "processlists_BSSoundHandle.h"
#include "processlists_NiPoint3.h"

class ActorCause;
class NiLight;
class NonActorMagicCaster;
class TESObjectWEAP;
class bhkSimpleShapePhantom;

class Explosion : public MobileObject
{
  public:
    struct ExplosionParameters;

    virtual ~Explosion();
    virtual void Initialize();  // +0x304

    float m_fFirstFloatValue;
    float f3DLifetime;
    float fInnerRadius;
    float fOuterRadius;
    float ExplosionRuntimeData;
    float m_fFourthRecordValue;
    NiPointer<bhkSimpleShapePhantom> m_pExplosionPhantom;
    BSSimpleList<ExplosionParameters*> kTargets;
    SoundPlaybackHandle kSoundHandles[2];
    NiPointer<NiLight> m_pMenuLight;
    TESObjectREFR* pOwnerRef;
    TESObjectREFR* ReferenceSoundCauseData;
    NiPointer<ActorCause> m_pActorCause;
    bool ReferenceCauseInfo;
    bool m_bFlagD5;
    bool m_bFlagD6;
    bool m_bFlagD7;
    bool MagicWeaponState;
    bool bUnderwater;
    NonActorMagicCaster* m_pEffectInstance;
    TESObjectWEAP* m_pFiringWeapon;
    int m_iValueE4;
    NiPoint3 kClosestPoint;
    NiPoint3 kClosestPointNormal;
    float m_fClosestPointScalar;

      // PC 009AE6E0, supplied candidate identity
};

#endif
