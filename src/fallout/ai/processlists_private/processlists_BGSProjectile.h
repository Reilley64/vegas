// fallout/ai/processlists_private/processlists_BGSProjectile.h: declares ProjectileProperties, BGSProjectile
#ifndef PROCESSLISTS_PRIVATE_BGSPROJECTILE_H
#define PROCESSLISTS_PRIVATE_BGSPROJECTILE_H

#include "fnv/decl/FUN_004fd420_shell.h"
#include "processlists_TESBoundObject.h"
#include "processlists_TESFullName.h"
#include "processlists_TESModel.h"
#include "processlists_BGSPreloadable.h"
#include "processlists_types_BGSDestructibleObjectForm.h"
class TESObjectLIGH;
class TESObjectWEAP;
class BGSExplosion;
#include "processlists_actor_enums.h"
class ProjectileProperties
{
  public:
    unsigned int iFlags;                      // +0x0, 4 bytes
    float afGravity;                          // +0x4, 4 bytes
    float fSpeed;                             // +0x8, 4 bytes
    float fImpulseRadiusSquared;                             // +0xC, 4 bytes
    TESObjectLIGH* apTargetLight;                    // +0x10, 4 bytes
    TESObjectLIGH* m_pSecondLight;            // +0x14, 4 bytes
    float ExplosionLightingData;              // +0x18, 4 bytes
    float LightExplosionSoundData;            // +0x1C, 4 bytes
    float AlphaFloatParameters;               // +0x20, 4 bytes
    BGSExplosion* ExplosionFadeData;          // +0x24, 4 bytes
    TESSound* m_pExplosionSound;              // +0x28, 4 bytes
    float ExplosionEffectRecord;              // +0x2C, 4 bytes
    float fFadeOutTime;                       // +0x30, 4 bytes
    float fForce;                             // +0x34, 4 bytes
    TESSound* m_pFirstSound;                  // +0x38, 4 bytes
    TESSound* m_pSecondSound;                 // +0x3C, 4 bytes
    TESObjectWEAP* m_pProjectileWeapon;       // +0x40, 4 bytes
    float ProjectileWeaponDataWithTwoSounds;  // +0x44, 4 bytes
    float ProjectileWeaponDataWithOneSound;   // +0x48, 4 bytes
    float ProjectileWeaponData;               // +0x4C, 4 bytes
    float m_fFourthProjectileValue;           // +0x50, 4 bytes
};
class BGSProjectile : public TESBoundObject,
                      public TESFullName,
                      public TESModel,
                      public BGSPreloadable,
                      public BGSDestructibleObjectForm
{
  public:
    BGSProjectile();
    virtual ~BGSProjectile();
    ProjectileProperties Data;
    TESModel m_kProjectileModel;
    SOUND_LEVEL m_eSoundLevel;
    bool GetHasExplosionAltTrigger() const;
};
#endif
