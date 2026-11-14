// Unit-private PC Projectile declaration. Public JohnnyGuitarNVSE supplies
// names and virtual order; JIP independently annotates the PC slots/layout.
// This declares real virtual destruction and contains no method bodies.
#ifndef FNV_PROCESSLISTS_PRIVATE_PROJECTILE_H
#define FNV_PROCESSLISTS_PRIVATE_PROJECTILE_H

#include "processlists_MobileObject.h"
#include "processlists_BSSoundHandle.h"
#include "processlists_impacts_math.h"

class Actor;
class ActorCause;
class InventoryStackRecord;
class NiLight;
class NiRefObject;
class ProjectileSupportData;
class TESObjectWEAP;
class hkpCollidable;

class Projectile : public MobileObject
{
  public:
    enum Type
    {
        UNKNOWN,
        BEAM,
        FLAME,
        GRENADE,
        MISSILE,
        CONTINUOUS_BEAM
    };
    struct ImpactData;

    virtual ~Projectile();
    virtual Type GetProjectileType() const;              // +0x304
    virtual void Initialize();                           // +0x308
    virtual void ResetProjectile();                      // +0x30C
    virtual void UpdateProjectile(float timeDelta);      // +0x310
    virtual bool ProcessProjectile();                    // +0x314; JIP calls this ProcessImpact
    virtual bool IsProjectileActive() const;             // +0x318
    virtual void UpdateProjectileState();                // +0x31C
    virtual bool OnActorHit(Actor* actor, bool silent);  // +0x320
    virtual bool GetCharacterSex() const;                // +0x324
    virtual bool IsProximityDetonationTriggered();       // +0x328
    virtual bool OnCollision(Actor* actor, const NiPoint3& contactPoint, const NiPoint3& contactNormal,
                             hkpCollidable* collidable, unsigned int collisionShapeKey,
                             unsigned int hitMaterial);  // +0x32C

    BSSimpleList<ImpactData*> kImpacts;
    bool m_bHasImpactData;
    NiTransform m_kImpactTransform;
    unsigned int iFlags;
    float m_fAlpha;
    float TransformFlagFloatData;
    float fImpulseRadiusSquared;
    float m_fFirstFloatValue;
    float afDamageAmount;
    float fAlpha;
    float AlphaFloatParameters;
    float AlphaParameterSet;
    float WeaponAlphaParameters;
    float WeaponReferenceParameterData;
    float m_fFourthRecordValue;
    TESObjectWEAP* pSourceWeapon;
    TESObjectREFR* WeaponHitData;
    TESObjectREFR* m_pMagicTarget;
    NiPoint3 kMovementDirection;
    float fDistanceMoveds;
    NiPointer<NiLight> m_pMenuLight;
    bool m_bFlagAfterLight;
    NiPointer<NiRefObject> m_pExplosionEffect;
    NiPointer<ActorCause> m_pActorCause;
    float m_fLifetime;
    SoundPlaybackHandle kSound;
    SoundPlaybackHandle kCountdownSound;
    ProjectileSupportData* pProjectileTarget;
    InventoryStackRecord* pRockItLauncherEntry;
    bool m_bHasTarget;
    float fSoundDistance;
public:
    void FUN_009bc8f0();
};

#endif
