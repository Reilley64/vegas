
// src/staging/blk_004a0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BSFaceGenKeyframe.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ConsoleManager.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a3fe0_shell.h"
#include "fnv/decl/FUN_004a4020_shell.h"
#include "fnv/decl/FUN_004a40a0_Class.h"
#include "fnv/decl/FUN_004a40c0_Class.h"
#include "fnv/decl/FUN_004a41c0.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_006233c0.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00c84f10_cls.h"
#include "fnv/decl/FnCls.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/Owner623.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/ScreenSplatter.h"
#include "fnv/decl/TESObjectREFR.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Unk.h"
#include "fnv/decl/fnv_00457620__FUN_00457620_cls.h"
#include "fnv/decl/fnv_00490e40__FUN_00490e40_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004a40e0__FUN_004a40e0.h"
#include "fnv/decl/fnv_004a4220__FUN_004a4220Class.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004a1000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011de000.h"
#include <xmmintrin.h>

class NiPoint3
{
  public:
    union
    {
        struct
        {
            float x, y, z;
        };
        float components[3];
    };
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 ApplyScaled(float) const;
};

struct __declspec(align(16)) ImpactVector4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float components[4];
    };
};

struct HitBody;

struct ImpactHit
{
    ImpactVector4 normal;
    float fraction;
    int unk14, unk18, unk1c;
    unsigned int keys[8];
    int unk40, unk44, unk48, unk4c;
    HitBody* body;
    int unk54, unk58, unk5c;
};

struct HitArray
{
};

struct HitHolder
{
};

struct FUN_004a3c20
{
    ImpactVector4 from, to;
    int filter, unk24, unk28, unk2c;
    ImpactVector4 normal;
    float fraction;
    int shapeKey, unk48, unk4c;
    unsigned int keys[8];
    int unk70, unk74, unk78, unk7c;
    HitBody* body;
    int unk84, unk88, unk8c;
    ImpactVector4 transform;
    int unkA0, unkA4, unkA8;
    bool flag;
    FUN_004a3c20();
    void FUN_004a3f70(unsigned int);
};

struct FUN_004a3a70
{
    unsigned int vtable;
    float earlyOut;
    int unk08, unk0c;
    unsigned int data;
    int size, capacity, unk1c;
    unsigned char hitStorage[8 * sizeof(ImpactHit)];
    FUN_004a3a70();
    ~FUN_004a3a70();
};

struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int);
};

struct FUN_004a37b0
{
    NiPoint3 position, normal, tangent;
    int unk24;
    void* reference;
    int unk2c;
    void* texture;
    int unk34;
    float width, height, depth, lifetime;
    int unk48;
    float radius;
    int unk50;
    float parallax, shininess, scale;
    NiPoint3 color;
    int unk6c;
    unsigned char rotation, unk71, unk72, flag73, flag74, flag75, flag76, unk77;
    int unk78, unk7c;
    FUN_004a37b0();
};

struct World
{
    void** vtable;
};

struct Cell
{
};

struct Prompt
{
};

struct Scene
{
};

struct Ref
{
};

struct RefHandle
{
};

struct HitBody
{
    RefHandle shape;
};

struct Shape
{
};

struct ImpactData
{
    void* FUN_006733e0();
    bool FUN_004a4100();
    bool FUN_004a41e0();
    bool CallMemberAtOffset54();
    bool FUN_004a4140();
};

struct Gate
{
};

struct Splatter
{
};

struct FloatSetting
{
};

struct IntSetting
{
};

struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
};

struct TESView
{
};

NiPoint3 __cdecl FUN_004a3760(float, const NiPoint3&);

float __cdecl FUN_00406cc0(float);

struct ImpactTask
{
    int remaining;
    bool finished;
    unsigned char unk05;
    unsigned short unk06;
    ImpactData* impact;
    RefHandle reference;
    void FUN_004a2d50();
};

// @fnv 0x004a2d50
void ImpactTask::FUN_004a2d50()
{
    if (reinterpret_cast<::FUN_004a4020_shell *>((((::Gate *)(::ConsoleManager::Instance(1)))))->FUN_004a4020() || ((bool)(::IsStartMenuFlag1Set())))
        return;
    if (!((::Cell *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->FUN_0084e3a0())) || !((::Scene *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->FUN_00490e40())))
    {
        finished = true;
        return;
    }
    if (remaining > 0 && impact && reinterpret_cast<::FUN_00621b00_shell *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->FUN_00621b00() <= reinterpret_cast<::BSFaceGenKeyframe *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->GetTime())
    {
        NiPoint3 direction;
        reinterpret_cast<::ThreeByThreeMatrix *>((((::Prompt *)(::FUN_006a9540((char *)(((::Scene *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->FUN_00490e40()))))))))->GetRow(2, direction);
        reinterpret_cast<::FUN_004a0c10_s *>(&(direction))->FUN_004a0c10();
        NiPoint3 origin = reinterpret_cast<::NiAVObject *>((((::Scene *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->FUN_00490e40()))))->FUN_0043c490();
        float radius = ::RandomFloat(reinterpret_cast<::FUN_004a40a0_Class *>((impact))->FUN_004a40a0(), reinterpret_cast<::FUN_004a40c0_Class *>((impact))->GetModifierValue());
        Splatter* splatter = ((::Splatter *)(::ScreenSplatter::Activate(radius, true)));
        reinterpret_cast<::FUN_006233c0 *>((splatter))->GetImpactDataForMaterial(0);
        reinterpret_cast<::Unk *>((splatter))->FUN_004a1a10(8, 0);
        reinterpret_cast<::Unk *>((splatter))->FUN_004a1a10(29, 0);
        Cell* cell = ((::Cell *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->FUN_0084e3a0()));
        World* world = cell ? ((::World *)(reinterpret_cast<::FUN_004543c0_cls *>((cell))->FUN_004543c0())) : 0;
        FUN_004a3c20 ray;
        if (world)
        {
            reinterpret_cast<::Owner623 *>((splatter))->FUN_006231a0((::NiNode623 *)(world));
            float distance = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting29))))));
            NiPoint3 end = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)&(origin))->ProjectileLaunched((::NiPoint3 *)&(const ::NiPoint3 &)(direction.ApplyScaled(distance)), {})));
            end.x += ::RandomFloat(DAT_0101e578, DAT_01017868);
            end.y += ::RandomFloat(DAT_0101e578, DAT_01017868);
            end.z += ::RandomFloat(DAT_0101e578, DAT_01017868);
            float drop = -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting30)))))) *
                         (reinterpret_cast<::FUN_00621b00_shell *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->FUN_00621b00() / reinterpret_cast<::BSFaceGenKeyframe *>((((::Ref *)(::FUN_00559450((int *)&(reference))))))->GetTime());
            end.z += drop;
            if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting *>(&::g_011c5868)))))) > 0)
            {
                void* line = ((void *)(::fnv_004b3890::FUN_004b3890((const class ::FUN_006815c0 &)(origin), (const ::fnv_004b3890::FUN_004a7800 &)((const ::ImageSpaceEffectParam &)(ImageSpaceEffectParam(0, 1, 0, 1))), (const class ::FUN_006815c0 &)(end),
                                          (const ::fnv_004b3890::FUN_004a7800 &)((const ::ImageSpaceEffectParam &)(ImageSpaceEffectParam(0, 1, 1, 1))), true)));
                reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::TESView * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(line), ::DAT_01018f5c);
            }
            FUN_008c71b0 filter(0);
            reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(39);
            ray.FUN_004a3f70(filter.value);
            reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray))->FUN_004a3da0((void *)&(origin));
            reinterpret_cast<::FUN_004a3eb0_shell *>(&(ray))->FUN_004a3eb0((void *)&(end));
            FUN_004a3a70 collector;
            reinterpret_cast<::FUN_004a3fb0_shell *>(&(ray))->FUN_004a3fb0((::hkpAllRayHitCollector *)(void *)(&collector));
            bool rayHit = ((bool(*)(World*, FUN_004a3c20*))world->vtable[50])(world, &ray);
            int count = ((int)(uintptr_t)(reinterpret_cast<::Callees *>((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->FUN_00726070()));
            bool placed = false;
            for (int hit = 0; !placed && hit < count; ++hit)
            {
                HitBody* body = ((::ImpactHit *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->GetEntryAt(hit)))->body;
                if (body)
                {
                    unsigned int key = -1;
                    for (int keyIndex = 0;
                         keyIndex < 8 && ((::ImpactHit *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->GetEntryAt(hit)))->keys[keyIndex] != -1;
                         ++keyIndex)
                    {
                        key = ((::ImpactHit *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->GetEntryAt(hit)))->keys[keyIndex];
                    }
                    Shape* shape = ((::Shape *)(uintptr_t)(::FUN_004a3a40((::TESObjectREFR *)(::Ref *)(((::Ref *)(::FUN_00559450((int *)&(body->shape))))))));
                    if (!shape)
                        continue;
                    unsigned int material = ((unsigned int)(reinterpret_cast<::FUN_00c84f10_cls *>((shape))->FUN_00c84f10(key)));
                    void* texture = impact ? impact->FUN_006733e0() : 0;
                    if (!texture)
                        continue;
                    NiPoint3 position = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)&(origin))->ProjectileLaunched((::NiPoint3 *)&(const ::NiPoint3 &)(FUN_004a3760(
                        ((::ImpactHit *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->GetEntryAt(hit)))->fraction, (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(end))->FUN_00439ef0((::NiPoint3 *)&(origin), *(const ::NiPoint3 *)nullptr))))), {})));
                    NiPoint3 normal;
                    ::FUN_004a3970((::NiPoint3_local &)(normal), (const ::hkVector4 &)(((::ImpactHit *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->GetEntryAt(hit)))->normal));
                    bool landscape = reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::FUN_008c71b0 &)(FUN_008c71b0(::FUN_0043b540((char *)(body)))))->FUN_004a3a20() == 1;
                    Ref* target = 0;
                    if (landscape)
                    {
                        target = ((::Ref *)(intptr_t)(reinterpret_cast<::fnv_00457620::FUN_00457620_cls *>(((*reinterpret_cast<::TESView * *>(&::g_TES))))->FUN_00457620((const float *)&(position))));
                        if (target && ((::Ref *)(reinterpret_cast<::FUN_009611e0_shell *>((target))->FUN_009611e0())))
                            target = ((::Ref *)(reinterpret_cast<::FUN_009611e0_shell *>((target))->FUN_009611e0()));
                    }
                    else
                        target = ((::Ref *)(intptr_t)(::FUN_00c7fa90((::S_Obj *)(body))));
                    void* object = ((void *)(::FUN_0056f930((::NiAVObject *)(target))));
                    if (!landscape && (!object || !::IsAcousticSpaceFormTypeAllowed((::Refr_C *)(object), true)))
                        continue;
                    Ref* owner = ((::Ref *)(reinterpret_cast<::FnCls *>(((*reinterpret_cast<::TESView * *>(&::g_TES))))->FUN_004519d0((*(float *)&(const ::NiPoint3 &)(position)), {}, {})));
                    FUN_004a37b0 decal;
                    decal.position = position;
                    decal.normal = normal;
                    decal.width = radius;
                    decal.height = radius;
                    decal.depth = DAT_0101e574;
                    decal.lifetime = ::FUN_004a4240();
                    decal.rotation = (unsigned char)(int)FUN_00406cc0(::RandomFloat(0, DAT_0101e570));
                    decal.reference = target;
                    decal.texture = texture;
                    decal.flag73 = impact->FUN_004a4100();
                    decal.radius = reinterpret_cast<::FUN_004a41c0 *>((impact))->GetRadius();
                    decal.flag76 = impact->FUN_004a41e0();
                    decal.flag74 = impact->CallMemberAtOffset54();
                    decal.flag75 = impact->FUN_004a4140();
                    decal.parallax = reinterpret_cast<::fnv_004a40e0::FUN_004a40e0 *>((impact))->GetHealthRegeneration();
                    decal.shininess = reinterpret_cast<::BGSImpactData *>((impact))->FUN_009a9350();
                    decal.scale = reinterpret_cast<::TESObjectREFR *>((impact))->GetScale();
                    decal.color =
                        NiPoint3((unsigned char)(reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((impact))->GetNextFromSubobject() & 255) / 255.0,
                                 (unsigned char)(((unsigned short)reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((impact))->GetNextFromSubobject() >> 8) & 255) / 255.0,
                                 (unsigned char)((reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((impact))->GetNextFromSubobject() >> 16) & 255) / 255.0);
                    reinterpret_cast<::FUN_004a3fe0_shell *>((owner))->FUN_004a3fe0(&decal, 1, 0);
                    placed = true;
                }
            }
            if (placed)
                --remaining;
        }
    }
    else
        finished = true;
}

struct FUN_004b4cf0_shell
{
    __m128* FUN_004b4cf0(unsigned int index);
};

struct FUN_004b4ab0_Class
{
    __m128 value;
    void FUN_004b4ad0(FUN_004b4cf0_shell* matrix, __m128* vector);
};

// @fnv 0x004b4ad0
void FUN_004b4ab0_Class::FUN_004b4ad0(FUN_004b4cf0_shell* matrix, __m128* vector)
{
    __m128 row0 = *matrix->FUN_004b4cf0(0);
    __m128 row1 = *matrix->FUN_004b4cf0(1);
    __m128 row2 = *matrix->FUN_004b4cf0(2);
    __m128 low = _mm_unpacklo_ps(row0, row1);
    __m128 high = _mm_shuffle_ps(_mm_unpackhi_ps(row0, row1), row2, 0xe4);
    row0 = _mm_movelh_ps(low, row2);
    row1 = _mm_shuffle_ps(_mm_movehl_ps(row0, low), row2, 0xd4);
    row2 = high;
    __m128 sx = _mm_shuffle_ps(*vector, *vector, 0);
    __m128 x = _mm_mul_ps(row0, sx);
    __m128 sy = _mm_shuffle_ps(*vector, *vector, 0x55);
    __m128 y = _mm_mul_ps(row1, sy);
    __m128 sz = _mm_shuffle_ps(*vector, *vector, 0xaa);
    __m128 z = _mm_mul_ps(row2, sz);
    value = _mm_add_ps(_mm_add_ps(x, y), z);
}
