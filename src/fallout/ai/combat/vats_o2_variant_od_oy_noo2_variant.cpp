
// src/fallout/ai/combat/vats_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/ai/combat/vats_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/vats_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/vats.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_0058d630_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_0088b030_shell.h"
#include "fnv/decl/FUN_008b70d0_shell.h"
#include "fnv/decl/FUN_0093e840_shell.h"
#include "fnv/decl/FUN_0095f530_shell.h"
#include "fnv/decl/FUN_009c8870_Class.h"
#include "fnv/decl/FUN_009ca500_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S819.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "vats_decls.h"
struct BooleanFloatQuery;
struct TESObjectREFR;
struct VATSCommand
{
    void Initialize();
    void* __vecDelDtor(unsigned int);
    int eAction;
    bool bSuccess;
    bool m_kFieldAfterWeaponFlags;
    bool m_bFirstActionFlag;
    bool m_bSecondActionFlag;
    unsigned char m_ucFirstActionCode;
    unsigned char m_ucSecondActionCode;
    char _pad_a[2];
    TESObjectREFR* pTarget;
    int m_iActionValue;
    BooleanFloatQuery* m_pActionObject;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fOverrideActionPoints;
    bool m_bFinalActionFlag;
    char _pad_25[3];
};
struct FUN_009ca410_shell : public VATS
{
    void ProcessVATSCommands();
};
struct PlayerCharacter;
struct Animation;
struct Actor
{
};
struct FUN_00498910_shell
{
};
struct Node
{
    VATSCommand* item;
    Node* next;
};
struct FUN_009ca410_shell_base : public VATS
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};
struct StandIn
{
};
extern float DAT_011afe74;
extern float DAT_011afe78;
extern unsigned char DAT_012677cc;
float __cdecl FUN_009c8ef0();
struct SoundListEntry;
struct SoundListView
{
    void AddTail(SoundListEntry* const&);
    void AddCommand(SoundListEntry* apCommand);
};
struct ListHolder
{
    bool _ref_008256d0();
    void* FUN_009c71c0();
};
struct MyList
{
    bool _ref_008256d0();
    VATSCommand* FUN_009c71f0();
};
struct bhkWorld
{
    static bool __cdecl QPickCountOverride();
};
float __cdecl FUN_009c8ef0();
extern float DAT_012677c4;
bool __cdecl FUN_009c8ea0();
struct FUN_009c9900_shell
{
    void SetByteAt76(unsigned char param_2);
};
struct FUN_009ca4a0
{
    FUN_009ca4a0();
};
struct Helper62d0
{
    Helper62d0& operator=(void const*);
};
struct FUN_009d9ec0_shell
{
    void AssignAtOffsetB0(void* p);
};

#include <xmmintrin.h>
class NiPoint3L8
{
  public:
    float x;
    float y;
    float z;
};

class HitResultsL8
{
  public:
    HitResultsL8();
    ~HitResultsL8();
    __m128 m_akData[50];
};

class HitL8
{
  public:
    HitL8(void* pvHit);
    __m128 m_akPad[5];
    void* m_pvCollidable;
    int m_aiPad[3];
};

class HitListL8
{
  public:
    void* GetAt(int iIndex);
};

class HitArrayL8
{
  public:
};

class PickFlagsL8
{
  public:
    PickFlagsL8(int iValue);
    int m_iValue;
};

class PickQueryL8
{
  public:
    PickQueryL8();
    void SetFlags(PickFlagsL8 kFlags);
    __m128 m_akData[11];
};

class WorldL8
{
  public:
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w00a();
    virtual void w00b();
    virtual void w00c();
    virtual void w00d();
    virtual void w00e();
    virtual void w00f();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w01a();
    virtual void w01b();
    virtual void w01c();
    virtual void w01d();
    virtual void w01e();
    virtual void w01f();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w02a();
    virtual void w02b();
    virtual void w02c();
    virtual void w02d();
    virtual void w02e();
    virtual void w02f();
    virtual void w030();
    virtual void w031();
    virtual bool Pick(PickQueryL8& kQuery);
};

class CellL8
{
  public:
};

class ProjL8
{
  public:
};

class RefL8
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual const NiPoint3L8* GetPos();
};

class PackageL8
{
  public:
    char m_acPad[0xc];
    RefL8* m_pkTarget;
};


class CheckerL8
{
  public:
    bool FUN_009c8f20(PackageL8* pkPackage);
};

// @fnv 0x009c8f20
bool CheckerL8::FUN_009c8f20(PackageL8* pkPackage)
{
    RefL8* pkTarget = 0;
    if (pkPackage->m_pkTarget->IsActor())
        pkTarget = pkPackage->m_pkTarget;
    if (!pkTarget)
        return false;
    WorldL8* pkWorld = ((::CellL8 *)(reinterpret_cast<::LowProcess *>((pkTarget))->GetTarget())) ? ((::WorldL8 *)(reinterpret_cast<::FUN_004543c0_cls *>((((::CellL8 *)(reinterpret_cast<::LowProcess *>((pkTarget))->GetTarget()))))->FUN_004543c0())) : 0;
    if (!pkWorld)
        return false;
    unsigned int uiMask = 0x26206;
    ::ShadowLightData::SetTargetMaskForSelection(0x27, uiMask);
    NiPoint3L8 kFrom = *(*reinterpret_cast<::RefL8 * *>(&::DAT_011f21f0))->GetPos();
    NiPoint3L8 kTo = *pkTarget->GetPos();
    kFrom.z += 60.0;
    kTo.z += 60.0;
    PickQueryL8 kQuery;
    PickFlagsL8 kFlags(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(kFlags))->FUN_004a39f0(0x27);
    RefL8* pkActor = pkTarget->IsActor() ? pkTarget : 0;
    if (pkActor && ((::ProjL8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pkActor))->FUN_009306d0())))
        reinterpret_cast<::FUN_0059ce80_shell *>(&(kFlags))->FUN_0059ce80((unsigned int)(((void *)(reinterpret_cast<::S819 *>((((::ProjL8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pkActor))->FUN_009306d0()))))->FUN_00819250()))));
    else
        reinterpret_cast<::FUN_0059ce80_shell *>(&(kFlags))->FUN_0059ce80((unsigned int)(((void *)(::FUN_005dbe10()))));
    kQuery.SetFlags(kFlags);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(kQuery))->FUN_004a3da0((void *)&(kFrom));
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(kQuery))->FUN_004a3eb0((void *)&(kTo));
    HitResultsL8 kResults;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(kQuery))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::HitResultsL8 *)(&kResults));
    bool bPickResultFound = false;
    pkWorld->Pick(kQuery);
    for (int i = 0; !bPickResultFound && i < ((int)(reinterpret_cast<::Callees *>((((::HitListL8 *)(::FUN_00460140((int)(((::HitArrayL8 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(kQuery))->FUN_008cdd90()))))))))->FUN_00726070())); i++)
    {
        HitL8 kHit(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitListL8 *)(::FUN_00460140((int)(((::HitArrayL8 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(kQuery))->FUN_008cdd90()))))))))->GetEntryAt(i))));
        void* pvCollidable = ((void *)(::FUN_004b5820((::FormLike *)(kHit.m_pvCollidable))));
        RefL8* pkRef = ((::RefL8 *)(::FUN_0056f930((::NiAVObject *)(pvCollidable))));
        if (pvCollidable)
        {
            if (pkRef == pkTarget || pkRef == (*reinterpret_cast<::RefL8 * *>(&::DAT_011f21f0)))
                continue;
            else
                return false;
        }
    }
    return true;
}
