
// src/fallout/ai/combat/hitdata_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/ai/combat/hitdata_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/hitdata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/hitdata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/hitdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/hitdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FNVEffectOwner.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_005e50f0_Obj.h"
#include "fnv/decl/FUN_005e5130_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00822650_shell.h"
#include "fnv/decl/FUN_008a50f0_class.h"
#include "fnv/decl/FUN_008b3ef0_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009b7010_shell.h"
#include "fnv/decl/FUN_009c3ee0_shell.h"
#include "fnv/decl/Hld621210.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Obj5e5300.h"
#include "fnv/decl/ShapeCaster.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WeightedResultList.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008a50d0__bhkCharacterController.h"
#include "fnv/decl/fnv_008aff80__ActorStub.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005dc000.h"
#include "fnv/symbols_00626000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
struct FUN_009b7040_shell
{
    float GetField168();
};
struct FUN_009b73b0_shell
{
    char GetByteAtOffset() const;
};
struct FUN_009b7840_shell
{
    void RaiseMaxValue(float a);
};
struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    static const ::NiPoint3 ZERO;
};
struct BooleanFloatQuery
{
    void* m_pAggressor;
    void* pTarget;
    void* m_pSourceReference;
    unsigned int m_uiHitLocation;
    unsigned int m_uiHitFlags;
    float m_fDamage;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    NiPoint3 vOffset1;
    NiPoint3 vOffset2;
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
    void FUN_009b4dc0();
};
struct GlobalObject_00869f00
{
};
extern int DAT_0108f9e8;
struct FUN_009b7970_shell
{
    void InitializeAndClear();
};

#include <xmmintrin.h>
class hkVector4_9B6
{
  public:
    hkVector4_9B6();
    __m128 m_vComponents;
};

class Point9B6
{
  public:
    Point9B6();
    Point9B6 operator+(const Point9B6& kPt) const;
    Point9B6 operator-(const Point9B6& kPt) const;
    Point9B6 operator*(float fScalar) const;
    Point9B6 operator-() const;
    Point9B6& operator+=(const Point9B6& kPt);
    Point9B6 UnitizeScaled(float fScaleMultiplier) const;
    float x, y, z;
};

class hkBool9B6
{
  public:
    hkBool9B6();
    char m_cBooleanValue;
};

class Transform9B6
{
  public:
};

class NiAVObject9B6
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiAVObject9B6* GetBone();
};

class Collidable9B6;

class Collision9B6
{
  public:
};

class Entity9B6;

class Hit9B6
{
  public:
    Hit9B6(const Hit9B6& kOther);
    hkVector4_9B6 m_kPathOffset;
    hkVector4_9B6 m_kPlaneNormal;
    float m_fHitFraction;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    Collidable9B6* m_pkCollidable;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
};

class HitArray9B6
{
  public:
    Hit9B6& GetAt(int i);
};

class Results9B6
{
  public:
};

class World9B6;

class Query9B6
{
  public:
};

class Middle9B6
{
  public:
};

class SpherePick9B6
{
  public:
    SpherePick9B6();
    hkVector4_9B6 m_kPathOffset;
};

class BodyPart9B6
{
  public:
};

class BodyPartData9B6
{
  public:
};

class Base9B6
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual BodyPartData9B6* GetBodyPartData();
};

class ActorValueOwner9B6
{
  public:
    virtual void v00();
};

class PartSet9B6
{
  public:
    PartSet9B6();
    ~PartSet9B6();
    bool Contains(BodyPart9B6* pkPart);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

class Ref9B6
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual NiAVObject9B6* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual bool IsCrippled();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
};

class Actor9B6 : public Ref9B6, public ActorValueOwner9B6
{
};

class Attacker9B6
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual NiAVObject9B6* Get3D();
    Point9B6 GetEyePosition(int iMode);
};

class Weapon9B6
{
  public:
};

class LinkInfo9B6
{
  public:
    void* m_pvForm;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int m_iPart;
};

class Contact9B6
{
  public:
    int unk00;
    Point9B6 m_kPathOffset;
    Point9B6 m_kPlaneNormal;
    unsigned int unk1c;
    unsigned int unk20;
    int m_iPart;
};

class Event9B6
{
  public:
};

class FloatSetting9B6
{
  public:
};


class Target9B6
{
  public:
    bool HasFlag(int iFlag);
    void FUN_009b6620(Event9B6* pkEvent);
    Attacker9B6* m_pkAttacker;
    Ref9B6* m_pkTarget;
    int unk08;
    int unk0c;
    int m_iPart;
    float m_fBaseChance;
    int unk18;
    int unk1c;
    float m_fChance;
    int unk24;
    int unk28;
    int unk2c;
    Weapon9B6* m_pkWeapon;
    int unk34;
    Point9B6 m_kPathOffset;
    Point9B6 m_kLightVector;
    int unk50;
    LinkInfo9B6* m_pkLink;
};

// @fnv 0x009b6620
void Target9B6::FUN_009b6620(Event9B6* pkEvent)
{
    if (!m_pkTarget || !m_pkTarget->IsActor())
        return;
    Base9B6* pkBase = ((::Base9B6 *)(reinterpret_cast<::Actor *>((m_pkTarget))->GetActorBase()));
    BodyPartData9B6* pkParts = pkBase->GetBodyPartData();
    BodyPart9B6* pkPart = 0;
    bool bSearch = false;
    if (m_pkLink)
    {
        if (m_pkLink->m_iPart != -1)
        {
            if (pkParts)
            {
                pkPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e5130_Class *>((pkParts))->FUN_005e5130(m_pkLink->m_iPart)));
                m_iPart = pkPart ? ((int)(reinterpret_cast<::Obj5e5300 *>((pkPart))->GetByte61())) : 0xe;
            }
        }
        else if (::FUN_0066de30((int)(m_pkLink->m_pvForm)))
        {
            if (HasFlag(0x800))
                m_iPart = 0;
            else
                bSearch = true;
        }
        else
        {
            m_iPart = 0xe;
        }
    }
    else if (pkEvent)
    {
        bSearch = false;
        Contact9B6* pkContact = ((::Contact9B6 *)(reinterpret_cast<::FUN_009c3ee0_shell *>((pkEvent))->FindItemByKey(m_pkTarget)));
        if (pkContact)
        {
            m_iPart = pkContact->m_iPart;
            pkPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pkParts))->GetValueByIndex(m_iPart)));
            m_kPathOffset = pkContact->m_kPathOffset;
            m_kLightVector = (*(::Point9B6 *)&(reinterpret_cast<::FUN_009b7010_shell *>((pkEvent))->FUN_009b7010(*(::NiPoint3 *)nullptr)));
            reinterpret_cast<::FUN_004a0c10_s *>(&(m_kLightVector))->FUN_004a0c10();
            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Point9B6 &)(m_kLightVector))->FUN_0063c8a0((void *)&(const ::Point9B6 &)(-pkContact->m_kPlaneNormal));
            reinterpret_cast<::FUN_004a0c10_s *>(&(m_kLightVector))->FUN_004a0c10();
        }
    }
    else
    {
        bSearch = true;
    }
    if (bSearch)
    {
        Point9B6 kHitPos = m_pkAttacker->GetEyePosition(1);
        Point9B6 kLookPos;
        Point9B6 kLookDir;
        reinterpret_cast<::fnv_008aff80::ActorStub *>((m_pkAttacker))->GetCameraPosAndDir((::fnv_008aff80::Vec3 *)&(kLookPos), (::fnv_008aff80::Vec3 *)&(kLookDir), 0);
        Point9B6 kFrom = kLookPos;
        Point9B6 kRay = kLookDir * 200.0f;
        float fScaleMultiplier = 200.0f;
        bool bFound = false;
        PartSet9B6 kParts;
        Middle9B6* pkMiddle = ((::Middle9B6 *)(reinterpret_cast<::LowProcess *>((m_pkAttacker))->GetTarget()));
        if (pkMiddle)
        {
            Query9B6* pkQuery = ((::Query9B6 *)(::FUN_00626dd0(m_pkAttacker != (*reinterpret_cast<::Attacker9B6 * *>(&::_g_thePlayer)), 1)));
            reinterpret_cast<::FNVEffectOwner *>((pkQuery))->ApplyEffectToTarget(((::World9B6 *)(reinterpret_cast<::FUN_004543c0_cls *>((pkMiddle))->FUN_004543c0())));
            reinterpret_cast<::ShapeCaster *>((pkQuery))->FUN_00626b30((const ::NiPoint3 &)(kFrom), (const ::NiPoint3 &)(kLookDir), fScaleMultiplier);
            Results9B6* pkResults = ((::Results9B6 *)(new ((void *)(pkQuery)) ::Vec3()));
            if (reinterpret_cast<::FUN_005609f0_shell *>((void *)(void *)&(const ::hkBool9B6 &)((*(::hkBool9B6 *)(reinterpret_cast<::Hld621210 *>((pkResults))->FUN_00621210({})))))->FUN_005609f0())
            {
                for (int i = 0; i < ((int)(reinterpret_cast<::Callees *>((((::HitArray9B6 *)(::FUN_00460140((int)(pkResults))))))->FUN_00726070())); i++)
                {
                    Hit9B6 kHit(((::HitArray9B6 *)(::FUN_00460140((int)(pkResults))))->GetAt(i));
                    NiAVObject9B6* pkObject = ((::NiAVObject9B6 *)(::FUN_004b5820((::FormLike *)(kHit.m_pkCollidable))));
                    Ref9B6* pkRef = ((::Ref9B6 *)(::FUN_0056f930((::NiAVObject *)(pkObject))));
                    if (pkRef && pkRef == m_pkTarget)
                    {
                        ::SetNiPoint3FromHkVector4((::NiPoint3 &)(kHitPos), (const ::hkVector4 &)((*(const ::hkVector4_9B6 *)(new ((void *)&(kHit)) ::Vec3()))));
                        Entity9B6* pkEntity = ((::Entity9B6 *)(::FUN_004b59f0(kHit.m_pkCollidable)));
                        if (pkEntity)
                        {
                            if (!bFound)
                            {
                                bFound = true;
                                ::SetNiPoint3FromHkVector4((::NiPoint3 &)(m_kPathOffset), (const ::hkVector4 &)((*(const ::hkVector4_9B6 *)(new ((void *)&(kHit)) ::Vec3()))));
                                m_kLightVector = kLookDir;
                            }
                            int iIndex = pkObject->GetBone() ? reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(pkObject->GetBone()))
                                                             : reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(((::NiAVObject9B6 *)(reinterpret_cast<::FUN_009611e0_shell *>((pkObject))->FUN_009611e0()))));
                            if (iIndex != -1 && iIndex != 0xe)
                            {
                                BodyPart9B6* pkHitPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pkParts))->GetValueByIndex(iIndex)));
                                if (pkHitPart && !kParts.Contains(pkHitPart))
                                    reinterpret_cast<::WeightedResultList *>(&(kParts))->FUN_009b7990((::BGSBodyPart *)(pkHitPart), ((bool)(::FUN_005dc980((const char *)(pkHitPart)))));
                            }
                        }
                    }
                }
            }
        }
        if (!bFound && m_pkTarget->Get3D() && m_pkAttacker->Get3D())
        {
            Point9B6 kTargetPos = *((const ::Point9B6 *)(new ((void *)(((::Transform9B6 *)(reinterpret_cast<::FUN_0043d450_Owner *>((m_pkTarget->Get3D()))->FUN_0043d450())))) ::Vec3()));
            Point9B6 kAttackerPos = *((const ::Point9B6 *)(new ((void *)(((::Transform9B6 *)(reinterpret_cast<::FUN_0043d450_Owner *>((m_pkAttacker->Get3D()))->FUN_0043d450())))) ::Vec3()));
            m_kPathOffset = kTargetPos + (m_pkAttacker->GetEyePosition(1) - kTargetPos).UnitizeScaled(6.0f);
            m_kLightVector = kTargetPos - kAttackerPos;
            SpherePick9B6 kPick;
            hkVector4_9B6 kTargetCenter;
            ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kTargetCenter), (const ::fnv_004a3e00::NiPoint3 &)(kHitPos));
            reinterpret_cast<::FUN_008a50f0_class *>(&(kPick))->FUN_008a50f0((int)&(kTargetCenter));
            reinterpret_cast<::fnv_008a50d0::bhkCharacterController *>(&(kPick))->FUN_008a50d0(200.0f);
            Collision9B6* pkCollision = ((::Collision9B6 *)(::FUN_00c806b0(m_pkTarget->Get3D(), &kPick, 0)));
            if (pkCollision)
            {
                bFound = true;
                NiAVObject9B6* pkObject = ((::NiAVObject9B6 *)(::FUN_004b5820((::FormLike *)(::Collidable9B6 *)(((::Collidable9B6 *)(reinterpret_cast<::FUN_0043b560_shell *>((pkCollision))->GetSourceFilesFromObject()))))));
                if (pkObject)
                {
                    int iIndex = pkObject->GetBone() ? reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(pkObject->GetBone()))
                                                     : reinterpret_cast<::FUN_008b3ef0_cls *>((m_pkTarget))->FUN_008b3ef0((::TESObjectREFR *)(::NiAVObject9B6 *)(((::NiAVObject9B6 *)(reinterpret_cast<::FUN_009611e0_shell *>((pkObject))->FUN_009611e0()))));
                    if (iIndex != -1)
                    {
                        BodyPart9B6* pkHitPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pkParts))->GetValueByIndex(iIndex)));
                        if (pkHitPart && !kParts.Contains(pkHitPart))
                            reinterpret_cast<::WeightedResultList *>(&(kParts))->FUN_009b7990((::BGSBodyPart *)(pkHitPart), ((bool)(::FUN_005dc980((const char *)(pkHitPart)))));
                    }
                }
            }
        }
        if (bFound)
        {
            pkPart = ((::BodyPart9B6 *)(reinterpret_cast<::FUN_00822650_shell *>(&(kParts))->FindFirstItemExceedingRemaining()));
            m_iPart = pkPart ? ((int)(reinterpret_cast<::Obj5e5300 *>((pkPart))->GetByte61())) : -1;
        }
    }
    if (m_iPart == 0xe)
    {
        m_fChance = m_fBaseChance;
        if (m_pkLink)
            m_fChance *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting9B6 *>(&::originalRuntimeFloatSetting759))))));
        m_fBaseChance = 0.0f;
        return;
    }
    if (pkPart)
    {
        m_iPart = pkPart ? ((int)(reinterpret_cast<::Obj5e5300 *>((pkPart))->GetByte61())) : -1;
        m_fChance = ::FUN_00647a30((::FUN_00647a30_Obj *)(::ActorValueOwner9B6 *)((Actor9B6*)m_pkTarget), (::FUN_00647a30_Flag *)(pkPart), m_fBaseChance);
        if (m_pkTarget->IsCrippled())
            m_fChance *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting9B6 *>(&::originalRuntimeFloatSetting750))))));
        float fBodyPartChance = reinterpret_cast<::TESGrass *>((pkPart))->GetLowestAllowedSlope();
        if (!m_pkWeapon || ::FUN_006450c0((::TESObjectWEAP *)(m_pkWeapon)))
            fBodyPartChance = 1.0f;
        if (m_pkWeapon)
            m_fChance *= reinterpret_cast<::FUN_009b7040_shell *>((m_pkWeapon))->GetField168();
        reinterpret_cast<::FUN_009b7840_shell *>(this)->RaiseMaxValue(fBodyPartChance);
    }
}
