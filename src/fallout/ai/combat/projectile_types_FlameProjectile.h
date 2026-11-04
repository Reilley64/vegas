// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_FLAMEPROJECTILE_H
#define FNV_FLAMEPROJECTILE_H

#include "layout_support.h"
#include "SoundPlaybackHandle.h"
#include "InventoryStackRecord.h"
#include "MobileObject.h"
#include "NiPoint3.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class ActorCause;
class FlameProjectile;
class NiLight;
class ThreeByThreeMatrix;
class NiPoint4;
class NiTransform;
class Projectile;
class Projectile__ImpactData;
class ProjectileAuxiliaryData;
class ProjectileSupportData;
class TESObjectWEAP;
class FourComponentNumericValue;
class FourComponentNumericValue
{
  public:
    union
    {                                     // overlapping CodeView storage
        float m_afComponents[4];          // +0x0, 16 bytes
        unsigned int m_auiComponents[4];  // +0x0, 16 bytes
        struct
        {
            float x;  // +0x0, 4 bytes
            float y;  // +0x4, 4 bytes
            float z;  // +0x8, 4 bytes
            float w;  // +0xC, 4 bytes
        };
        float v[4];         // +0x0, 16 bytes
        unsigned int u[4];  // +0x0, 16 bytes
    };
};
class NiPoint4
{
  public:
    union
    {                                             // overlapping CodeView storage
        FourComponentNumericValue m_kComponents;  // +0x0, 16 bytes
        float m_afExtents[4];                     // +0x0, 16 bytes
    };
    // NiPoint4
    // bool __cdecl NiPoint4::*(const NiPoint4&)
    // void __cdecl NiPoint4::*()
    // Set
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // NiPoint4 __cdecl NiPoint4::*(NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(NiPoint4*, unsigned int, NiPoint3*)
};
class ThreeByThreeMatrix
{
  public:
    NiPoint4 m_afEntries[3];  // +0x0, 48 bytes
    // GetRow
    // SetRow
    // GetCol
    // SetCol
    // operator*
    // Inverse
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;  // +0x0, 48 bytes
    NiPoint3 m_kTranslation;   // +0x30, 12 bytes
    float m_fScale;            // +0x3C, 4 bytes
    // void __cdecl NiTransform::*()
    // bool __cdecl NiTransform::*(const NiTransform&)
    // operator*
    // void __cdecl NiTransform::*(NiTransform&)
    // void __cdecl NiTransform::*(NiTransform&)
    // bool __cdecl NiTransform::*()
    // void __cdecl NiTransform::*(NiStream&)
    // void __cdecl NiTransform::*(NiStream&)
    // void __cdecl NiTransform::*()
};
class Projectile : public MobileObject
{
  public:
    // base MobileObject at +0x0, size 136
    BSSimpleList<Projectile__ImpactData*> m_kProjectileImpactList;  // +0x88, 8 bytes
    bool m_bHasImpactData;                                          // +0x90, 1 bytes
    unsigned char layoutPadding91[15];
    NiTransform m_kImpactTransform;      // +0xA0, 64 bytes
    unsigned int iFlags;                 // +0xE0, 4 bytes
    float m_fAlpha;                      // +0xE4, 4 bytes
    float TransformFlagFloatData;        // +0xE8, 4 bytes
    float fImpulseRadiusSquared;                        // +0xEC, 4 bytes
    float m_fFirstFloatValue;                          // +0xF0, 4 bytes
    float afDamageAmount;                // +0xF4, 4 bytes
    float fAlpha;                        // +0xF8, 4 bytes
    float AlphaFloatParameters;          // +0xFC, 4 bytes
    float AlphaParameterSet;             // +0x100, 4 bytes
    float WeaponAlphaParameters;         // +0x104, 4 bytes
    float WeaponReferenceParameterData;  // +0x108, 4 bytes
    float m_fFourthRecordValue;          // +0x10C, 4 bytes
    TESObjectWEAP* m_pFiringWeapon;      // +0x110, 4 bytes
    TESObjectREFR* WeaponHitData;        // +0x114, 4 bytes
    TESObjectREFR* m_pMagicTarget;       // +0x118, 4 bytes
    NiPoint3 m_kImpactPoint;             // +0x11C, 12 bytes
    float m_fImpactForce;                // +0x128, 4 bytes
    NiPointer<NiLight> m_pMenuLight;     // +0x12C, 4 bytes
    bool m_bFlagAfterLight;              // +0x130, 1 bytes
    unsigned char layoutPadding131[3];
    NiPointer<ProjectileAuxiliaryData> m_pExplosionEffect;  // +0x134, 4 bytes
    NiPointer<ActorCause> m_pActorCause;                    // +0x138, 4 bytes
    float m_fLifetime;                                      // +0x13C, 4 bytes
    SoundPlaybackHandle m_kFirstValue;                            // +0x140, 12 bytes
    SoundPlaybackHandle m_kSecondValue;                           // +0x14C, 12 bytes
    ProjectileSupportData* pTarget;                         // +0x158, 4 bytes
    InventoryStackRecord* m_pTargetData;                              // +0x15C, 4 bytes
    bool m_bHasTarget;                                      // +0x160, 1 bytes
    unsigned char layoutPadding161[3];
    float ObjectPointerFlagFloatData;  // +0x164, 4 bytes
    unsigned char layoutPadding168[8];
    // Projectile
    // void __cdecl Projectile::*()
    // Projectile* __cdecl Projectile::*(BGSProjectile*, TESObjectREFR*, CombatController*, TESObjectWEAP*, NiPoint3, float, float, ProjectileAuxiliaryData*, TESObjectREFR*, bool, bool, float, float, TESObjectCELL*)
    // Projectile* __cdecl Projectile::*(BGSProjectile*, TESObjectREFR*, TESObjectREFR*, TESObjectWEAP*)
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*(bool)
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // void __cdecl Projectile::*(float)
    // bool __cdecl Projectile::*(float)
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // void __cdecl Projectile::*(TESObjectREFR*)
    // bool __cdecl Projectile::*(TESFile*)
    // void __cdecl Projectile::*(BGSSaveFormBuffer*)
    // void __cdecl Projectile::*(BGSLoadFormBuffer*)
    // void __cdecl Projectile::*(BGSLoadFormBuffer*)
    // void __cdecl Projectile::*(BGSLoadFormBuffer*)
    // void __cdecl Projectile::*(BGSLoadFormBuffer*)
    // BGSProjectile* __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // void __cdecl Projectile::*(ProjectileAuxiliaryData*)
    // void __cdecl Projectile::*(float)
    // float __cdecl Projectile::*()
    // void __cdecl Projectile::*(TESObjectWEAP*)
    // TESObjectWEAP* __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // float __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // float __cdecl Projectile::*()
    // void __cdecl Projectile::*(TESObjectREFR*)
    // TESObjectREFR* __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // float __cdecl Projectile::*()
    // float __cdecl Projectile::*()
    // float __cdecl Projectile::*()
    // NiPoint3 __cdecl Projectile::*()
    // TESObjectREFR* __cdecl Projectile::*()
    // void __cdecl Projectile::*(TESObjectREFR*)
    // bool __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // void __cdecl Projectile::*(float)
    // float __cdecl Projectile::*()
    // ProjectileAuxiliaryData* __cdecl Projectile::*()
    // ProjectileSupportData* __cdecl Projectile::*()
    // void __cdecl Projectile::*(ProjectileSupportData*)
    // float __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // float __cdecl Projectile::*()
    // void __cdecl Projectile::*(float)
    // void __cdecl Projectile::*(ActorCause*)
    // ActorCause* __cdecl Projectile::*()
    // bool __cdecl Projectile::*(Projectile::ProjectileFlags)
    // void __cdecl Projectile::*(Projectile::ProjectileFlags, bool)
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // void __cdecl Projectile::*(NiPoint3*, int, NiPoint3, float, float, float, float, float)
    // float __cdecl Projectile::*(float, float, float)
    // float __cdecl Projectile::*(Actor*)
    // Projectile* __cdecl Projectile::*(TESObjectREFR*, BGSProjectile*)
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*(NiAVObject*, NiPoint3&)
    // bool __cdecl Projectile::*(Actor*, Actor*, TESFaction*)
    // void __cdecl Projectile::*()
    // float __cdecl Projectile::*()
    // bool __cdecl Projectile::*(TESObjectREFR*, const hkpCollidable*, Projectile*, BGSProjectile*)
    // void __cdecl Projectile::*()
    // Move
    // void __cdecl Projectile::*(NiPoint3, bool)
    // void __cdecl Projectile::*(bool, bool)
    // void __cdecl Projectile::*(TESObjectREFR*, const NiPoint3&, const NiPoint3&, const hkpCollidable*, MATERIAL_TYPE)
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*(NiPoint3, NiPoint3, const hkpCollidable*)
    // void __cdecl Projectile::*(float)
    // bool __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // void __cdecl Projectile::*(Actor*, bool)
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*(NiPoint3)
    // void __cdecl Projectile::*()
    // void __cdecl Projectile::*()
    // bool __cdecl Projectile::*()
    // Projectile& __cdecl Projectile::*(const Projectile&)
    // void __cdecl Projectile::*()
};
class FlameProjectile : public Projectile
{
  public:
    bool IsProximityDetonationTriggered();
    // base Projectile at +0x0, size 368
    float TwoFloatRecord;   // +0x170, 4 bytes
    float FloatPairRecord;  // +0x174, 4 bytes
    unsigned char layoutPadding178[8];
    // FlameProjectile
    // Projectile::PROJECTILE_TYPE __cdecl FlameProjectile::*()
    // void __cdecl FlameProjectile::*()
    // void __cdecl FlameProjectile::*()
    // void __cdecl FlameProjectile::*(float)
    // bool __cdecl FlameProjectile::*()
    // float __cdecl FlameProjectile::*()
    // void __cdecl FlameProjectile::*()
    // float __cdecl FlameProjectile::*(NiAVObject*)
    // void __cdecl FlameProjectile::*(BGSSaveFormBuffer*)
    // void __cdecl FlameProjectile::*(BGSLoadFormBuffer*)
    // void __cdecl FlameProjectile::*(BGSLoadFormBuffer*)
    // void __cdecl FlameProjectile::*(BGSLoadFormBuffer*)
    // void __cdecl FlameProjectile::*(BGSLoadFormBuffer*)
    // bool __cdecl FlameProjectile::*(TESObjectREFR*, const NiPoint3&, const NiPoint3&, const hkpCollidable*, unsigned int, MATERIAL_TYPE)
    // void __cdecl FlameProjectile::*()
    // FlameProjectile& __cdecl FlameProjectile::*(const FlameProjectile&)
    // void __cdecl FlameProjectile::*()
};
#endif
