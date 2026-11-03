
// src/staging/blk_008c0000_o2_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/staging/blk_008c0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_008c0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <cstdint>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_00894d60_shell.h"
#include "fnv/decl/FUN_008a50f0_class.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder00807080.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/MyActor008A5300.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008a50d0__bhkCharacterController.h"
#include "fnv/decl/fnv_008ccfb0__xActor.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/xActor_2.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00cb9000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01085000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct FUN_004a3c90
{
    __m128 value;
    FUN_004a3c90(const FUN_004a3c90*);
};
class NiUpdateData
{
  public:
    float time;
    bool updateControllers, threaded, unk06, unk07, unk08;
    unsigned char unk09, unk0a, unk0b;
    NiUpdateData(float, bool, bool);
};
struct hkVector4
{
    __m128 value;
    hkVector4();
};
class ThreeByThreeMatrix;
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator*(float) const;
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    static const ::NiPoint3 ZERO;
};
class ThreeByThreeMatrix
{
  public:
    float elements[3][3];
    ThreeByThreeMatrix();
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
public:
    bool Inverse(::ThreeByThreeMatrix &);
};
class NiTransform
{
  public:
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
    NiTransform();
    NiPoint3 FUN_00524c40(const NiPoint3&) const;
public:
    void CalculateInverse(::NiTransform &);
};
// Aligned sphere: xyz center and radius in one SIMD vector.
class __declspec(align(16)) FUN_006240d0
{
  public:
    __m128 centerAndRadius;
    FUN_006240d0();
};
struct Ref8;
struct Node8;
struct Form8;
struct Controller8;
struct Link8;
struct Material8;
struct Node8
{
    NiPoint3 FUN_004b4500(const NiPoint3&);
};
struct Form8
{
};
struct Link8
{
};
struct Material8
{
};
struct Controller8
{
};
struct FUN_008cc6f0
{
    int mode;
    NiPoint3 target, end, direction;
    Ref8* victim;
    Node8* node;
    ThreeByThreeMatrix rotation;
    FUN_008cc6f0();
};
struct Ref8
{
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
    virtual void v190(int, int, int);
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
    virtual Node8* v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual NiPoint3* v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual bool v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int);
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
    virtual float v2bc(int);
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
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual bool v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual Controller8* v428();

    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    FUN_008cc6f0* state;
    int active;
    unsigned int unk090;
    unsigned int unk094;
    float angle;
    unsigned int unk09c;
    unsigned int unk0a0;
    Ref8* actor;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned char unk0c0;
    bool requested;
    unsigned short unk0c2;
    void FUN_008d0020(NiPoint3, NiPoint3, Link8*);
    void FUN_008cba30(const NiPoint3*, const NiPoint3*, Ref8*);
};
struct FloatSetting8
{
};
struct IntSetting8
{
};
extern float DAT_01085c58, DAT_01047224;
extern double DAT_010356f0;
Node8* FUN_008cfbc0(Node8*, NiPoint3, NiPoint3, float*, bool);

// @fnv 0x008cba30
void Ref8::FUN_008cba30(const NiPoint3* start, const NiPoint3* end, Ref8* victim)
{
    state = new FUN_008cc6f0;
    state->mode = 0;
    state->node = 0;
    state->victim = 0;
    state->end = *end;
    state->target = *start;
    state->rotation = DAT_011a9448;
    state->direction = ::NiPoint3::ZERO;
    if (((::Ref8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
    {
        FUN_004a3c90 direction(((::FUN_004a3c90 *)(reinterpret_cast<::Holder00807080 *>((((::Ref8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00807080())));
        if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::FUN_004a3c90 &)((*(::FUN_004a3c90 *)(reinterpret_cast<::Holder *>((void *)&(direction))->FUN_00458700((::Holder *)(0), {})))))->FUN_004586d0() == -DAT_01085910)
        {
            if (v1d0())
                state->direction = ((::Node8 *)(::FUN_00461130((int)(v1d0()))))->FUN_004b4500(DAT_011a9478 * angle);
        }
        else
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&state->direction)), (*(const ::hkVector4 *)(&direction)));
    }
    active = 1;
    if (victim)
    {
        Node8* root = v1d0();
        if (actor && actor->v428())
            reinterpret_cast<::FUN_008d0600_s *>((actor->v428()))->FUN_008d0600((int)(victim->v1f4()), 1);
        state->victim = victim;
        if (victim)
            reinterpret_cast<::MyActor008A5300 *>((victim))->CallProcessAt778();
        ::FUN_005ac750((::TESForm *)(((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((state->victim))->FUN_005d43c0()), 0x100);
        if (actor)
        {
            if (actor != (*reinterpret_cast<::Ref8 * *>(&::_g_thePlayer)) && !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((actor))->FUN_00493bb0())))
                goto sceneReady;
            bool blocked = victim->v22c(0);
            if (!blocked && victim->v22c(0) && (!victim->v21c() || victim->v38c()))
            {
                Node8* scene = ((::Node8 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((victim))->FUN_0043fcd0()));
                if (scene)
                {
                    float setting = ::RemapValueBySettings(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting8 *>(&::originalRuntimeFloatSetting701)))))), 1);
                    ::FUN_00cb9650((::FUN_00cb9650_Object *)(scene));
                    ::FUN_00c6a350((::NiAVObject *)(scene), 1, 1, 0, 1);
                    NiUpdateData zero(0.0f, false, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((scene))->FUN_00a59c60((std::intptr_t)&(zero));
                    NiPoint3 offset = ((::Node8 *)(::FUN_00461130((int)(root))))->FUN_004b4500(DAT_011a9478);
                    reinterpret_cast<::FUN_004a0c10_s *>(&(offset))->FUN_004a0c10();
                    offset = *v1f4() + (offset * DAT_01085c58);
                    hkVector4 position;
                    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&position)), (*(const ::fnv_004a3e00::NiPoint3 *)(&offset)));
                    ::SetCollisionScale((::SceneNode *)(scene), (unsigned int)&(position), setting, (::MaterialSelector *)(0));
                }
            }
        }
    sceneReady:
        Link8* linked = 0;
        Node8* victimScene;
        if (victim == (*reinterpret_cast<::Ref8 * *>(&::_g_thePlayer)))
            victimScene = ((::Node8 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::Ref8 * *>(&::_g_thePlayer))))->FUN_00950bb0(0)));
        else
            victimScene = ((::Node8 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((victim))->FUN_0043fcd0()));
        float range = DAT_010231a0;
        NiPoint3 direction;
        ThreeByThreeMatrix pitch;
        ThreeByThreeMatrix heading;
        reinterpret_cast<::FUN_004a0c90_shell *>(&(pitch))->FUN_004a0c90(v2bc(0));
        reinterpret_cast<::FUN_00524ac0_shell *>(&(heading))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
        pitch = reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(pitch))->operator+(heading);
        reinterpret_cast<::FUN_00439f50_class *>((void *)&(pitch))->FUN_00439f50(1, &direction);
        ::FUN_00525340((float *)(::NiPoint3 *)(&direction));
        NiPoint3 ray = *v1f4() - reinterpret_cast<::Point3_0053d280 *>((void *)(void *)&(const ::NiPoint3 &)((direction * range)))->FUN_0053d280(DAT_010162c0);
        bool found = false;
        Node8* hit = FUN_008cfbc0(victim->v1d0(), ray, direction, &range, !victim->v22c(1));
        if (hit)
        {
            NiPoint3 scaled = direction * (float)(range + DAT_010356f0);
            NiTransform transform;
            reinterpret_cast<::NiTransform *>((((::Node8 *)(::FUN_00461130((int)(hit))))))->CalculateInverse((*(::NiTransform *)(&transform)));
            state->target = transform.FUN_00524c40(ray + scaled);
            ThreeByThreeMatrix inverse;
            reinterpret_cast<::ThreeByThreeMatrix *>((((::Node8 *)(::FUN_00461130((int)(hit))))))->Inverse((*(::ThreeByThreeMatrix *)(&inverse)));
            state->rotation = reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(inverse))->operator+(*reinterpret_cast<ThreeByThreeMatrix*>(((::Node8 *)(::FUN_00461130((int)(root))))));
            state->node = hit;
            Form8* form = ((::Form8 *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(hit))));
            if (form)
                linked = ((::Link8 *)(::fnv_006fa820::FUN_006fa820((const char *)(form))));
            found = true;
        }
        bool overrideHit = false;
        if (reinterpret_cast<::FUN_00894d60_shell *>((victim))->FUN_00894d60() && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((victim))->GetBaseTexture())) && ::IsTargetInCone((::ConeRef *)(victim), (::ConeRef *)(::Ref8 *)(this), (float *)(0)))
        {
            NiPoint3 position = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((victim))->GetAddTopicList()));
            float top = reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((victim))->GetActorHeight() / DAT_01011590 + position.z;
            if (top <= start->z)
                overrideHit = true;
        }
        if (!found || overrideHit)
        {
            FUN_006240d0 bound;
            hkVector4 center;
            ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&center)), (*(const ::fnv_004a3e00::NiPoint3 *)(start)));
            reinterpret_cast<::FUN_008a50f0_class *>(&(bound))->FUN_008a50f0((int)&(center));
            reinterpret_cast<::fnv_008a50d0::bhkCharacterController *>(&(bound))->FUN_008a50d0(::g_011c72ac_arg1);
            Link8* candidate = 0;
            if (overrideHit)
                candidate = ((::Link8 *)(::FindPhysicsBodyByLayer((::SearchObject *)(victimScene), 7)));
            else
                candidate = ((::Link8 *)(::FUN_00c806b0(victimScene, &bound, !victim->v22c(1))));
            if (candidate)
            {
                linked = candidate;
                Form8* object = ((::Form8 *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(::Form8 *)(((::Form8 *)(::FUN_004ae750((void *)(linked))))))));
                if (object)
                {
                    hit = ((::Node8 *)(reinterpret_cast<::Twin_0044ddc0 *>((object))->GetName()));
                    NiPoint3 scaled = direction * DAT_01047224;
                    NiTransform transform;
                    reinterpret_cast<::NiTransform *>((((::Node8 *)(::FUN_00461130((int)(hit))))))->CalculateInverse((*(::NiTransform *)(&transform)));
                    state->target = transform.FUN_00524c40(*((::NiPoint3 *)(::FUN_0045bb80((int)(hit)))) + scaled);
                    ThreeByThreeMatrix inverse;
                    reinterpret_cast<::ThreeByThreeMatrix *>((((::Node8 *)(::FUN_00461130((int)(hit))))))->Inverse((*(::ThreeByThreeMatrix *)(&inverse)));
                    state->rotation = reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(inverse))->operator+(*reinterpret_cast<ThreeByThreeMatrix*>(((::Node8 *)(::FUN_00461130((int)(root))))));
                    state->node = hit;
                }
            }
            if (!state->node)
            {
                reinterpret_cast<::fnv_008ccfb0::xActor *>(this)->FUN_008ccfb0((int)(victim));
                return;
            }
        }
        if (linked)
            FUN_008d0020(*start, ((::Node8 *)(::FUN_00461130((int)(root))))->FUN_004b4500(DAT_011a9478), linked);
        if (state->node)
        {
            Form8* form = ((::Form8 *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(state->node))));
            Link8* object = form ? ((::Link8 *)(::fnv_006fa820::FUN_006fa820((const char *)(form)))) : 0;
            Material8* material = object ? ((::Material8 *)(reinterpret_cast<::FUN_004ae6a0_shell *>((object))->FUN_004ae6a0())) : 0;
            if (material)
            {
                switch (((unsigned int)(reinterpret_cast<::FUN_006205a0_Class *>((material))->FUN_006205a0())))
                {
                case 0:
                case 3:
                case 5:
                case 10:
                case 11:
                case 13:
                case 15:
                    reinterpret_cast<::xActor *>(this)->FUN_008ccce0((*(const ::xP3 *)(start)), (*(const ::xP3 *)(end)));
                    return;
                default:
                    break;
                }
            }
        }
        if (victim->v21c() && !victim->v38c())
        {
            reinterpret_cast<::fnv_008ccfb0::xActor *>(this)->FUN_008ccfb0((int)(victim));
            reinterpret_cast<::FUN_008cc6d0_class *>(this)->FUN_008cc6d0(3);
            return;
        }
        else
        {
            if (!((int)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(this)->FUN_008cdd90())) && ::DialogueRandom() % 100 < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting8 *>(&::g_011cf510)))))))
            {
                victim->v190(((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())), 0, 1);
                requested = true;
            }
        }
    }
}

#include "generated/data/staging/blk_008c0000_o2_od_noo2_variant.inc"
