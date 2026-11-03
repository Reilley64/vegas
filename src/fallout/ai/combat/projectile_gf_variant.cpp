
// src/fallout/ai/combat/projectile_gf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy /GF (unit src/fallout/ai/combat/projectile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/Dummy009c4e60.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_004587f0_shell.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00978f10_shell.h"
#include "fnv/decl/FUN_009795c0_shell.h"
#include "fnv/decl/FUN_009c19e0_shell.h"
#include "fnv/decl/FUN_009c1a00_Class.h"
#include "fnv/decl/FUN_009c1a50_shell.h"
#include "fnv/decl/FUN_009c1a70_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/ImageSpaceEffectParam.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Proxy.h"
#include "fnv/decl/RefLoad.h"
#include "fnv/decl/S005dbe60_Object.h"
#include "fnv/decl/S50.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_00ae5a50__Mgr_00ae5a50.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_009c2000.h"
#include "fnv/symbols_009c5000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_01268000.h"
#include "projectile_decls.h"

// FUN_009c0d80 reconstruction WIP.
// Built on unverified prior work by "another contributor" (2026-10-24) and an earlier
// "you" attempt (2026-10-23); logic revalidated and conventions corrected under this
// claim by GLM (Z.ai), agent zai_coord_01. Credit for the overall control-flow
// reconstruction belongs to the prior contributors.
// Build flags: /MT /O2 /GS /EHsc /Gy. __cdecl, caller pops, 6 params.
struct Vec3
{
    float components[3];
    Vec3();
    Vec3 ApplyScaled(float);
};
struct __declspec(align(16)) PhysicsVector
{
    float x, y, z, w;
};
struct EventInfo
{
    PhysicsVector normal;  // 16
    float time;            // 0x10
    int unk14, unk18, unk1c;
    char indexBytes[32];  // 0x20..0x40
    int unk40, unk44, unk48, unk4c;
    int eventHandle;  // 0x50
};
struct EventCursor
{
};
struct EventStream
{
};
struct Filter
{
    unsigned int value;
};
struct FormBase
{
};
struct EventEntity
{
    void** vtable;
    FormBase* FUN_0043b4f0(unsigned int* out);
};
struct Scene
{
};
struct AnimationPacket
{
    PhysicsVector rayOrigin, rayDirection;  // 0x00..0x20
    unsigned int filter;                    // 0x20
    unsigned int unk24, unk28, unk2c;
    EventInfo hit;                  // 0x30..0x84
    PhysicsVector cachedDirection;  // 0x90
    void* world;                    // 0xa0
    int unka4, unka8;
    bool unkac;
    AnimationPacket();
    void FUN_004a3f70(unsigned int filterValue);
};
struct HitEntry
{
    EventInfo info;
};
struct HitCollection
{
    HitEntry* entries;
    int size, capacity, allocator;
    HitEntry inlineHits[8];
};
struct __declspec(align(16)) Collector
{
    void** vtable;
    float earlyOutFraction;
    int unk08, unk0c;
    HitCollection hits;  // 0x10.. ; total size 0x340
    Collector();
    void FUN_004a3bc0();
    ~Collector()
    {
        FUN_004a3bc0();
    }
};
struct SoundSource
{
};
struct RenderManager
{
};
struct VisualNode
{
};
struct Controller
{
    void** vtable;
};
struct AudioPlaybackHandle
{
    unsigned int soundID;
    bool assumeSuccess;
    int state;
    void FUN_00483710();
    ~AudioPlaybackHandle()
    {
        FUN_00483710();
    }
};
struct AudioSystem
{
    AudioPlaybackHandle FUN_00ad7480(const char* path, int flags, SoundSource* source);
};
struct WorldTarget
{
    void** vtable;
};
struct Color
{
    float red, green, blue, alpha;
};
struct RenderElement
{
};
struct AudioController
{
};
struct FloatSetting
{
    int type;
    float value;
};
struct FormTypeDescriptor;
extern double DAT_01088210;
struct ParentEntity : EventEntity
{
};
extern Vec3 FUN_004a3760(float ratio, const Vec3& direction);
typedef int(__thiscall* GetKindFn)(EventEntity*);
typedef Vec3*(__thiscall* GetPositionFn)(EventEntity*);
typedef Vec3*(__thiscall* GetLocationFn)(WorldTarget*);
typedef VisualNode*(__thiscall* GetVisualFn)(Controller*);
typedef bool(__thiscall* DispatchFn)(Controller*, EventEntity*, Vec3*, Vec3*, int, int, int);
// @fnv 0x009c0d80
int __cdecl FUN_009c0d80(Scene* scene, Controller* player, int eventOwner, float* hitTime, bool acceptUnknown,
                         float maximumTime)
{
    if (eventOwner == 0 && player != 0)
        eventOwner = (int)((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase()));
    bool picked = false;
    int result = 0;
    if (scene != 0 && ((::EventStream *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>((scene))->FUN_008cdd90())) != 0)
    {
        Vec3 initialPosition;
        Vec3 initialDirection;
        reinterpret_cast<::Proxy *>((scene))->FUN_004585f0((*(::NiPoint3 *)(&initialPosition)));
        reinterpret_cast<::FUN_009c1a50_shell *>((scene))->FUN_009c1a20((*(const ::hkVector4 *)(&initialDirection)));
        bool partialMatch = false;
        EventEntity* lastReference = 0;
        for (int i = 0; !picked && i < ((int)(reinterpret_cast<::Callees *>((((::EventCursor *)(::FUN_00460140((int)(((::EventStream *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>((scene))->FUN_008cdd90()))))))))->FUN_00726070())); ++i)
        {
            EventInfo info;
            reinterpret_cast<::S50 *>(&(info))->FUN_00696c30((::S50 *)(::EventInfo *)(((::EventInfo *)(reinterpret_cast<::FUN_004a46b0_class *>((((::EventCursor *)(::FUN_00460140((int)(((::EventStream *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>((scene))->FUN_008cdd90()))))))))->GetEntryAt(i)))));
            if (info.time > maximumTime)
                continue;
            int handle = ((int)(::FUN_004b5820((::FormLike *)(info.eventHandle))));
            EventEntity* reference = ((::EventEntity *)(::FUN_0056f930((::NiAVObject *)(handle))));
            if (handle != 0)
            {
                bool candidate = true;
                int form = ((int)(::FUN_004b5950((const void *)(info.eventHandle))));
                EventEntity* entity2 = form != 0 ? ((::EventEntity *)(::FUN_004b5a80((const void *)(form)))) : 0;
                if (entity2 != 0)
                {
                    candidate = false;
                    unsigned int filterA, filterB;
                    if (player != 0 && reference != 0 &&
                        (reinterpret_cast<::FUN_0043b4d0_shell *>((entity2->FUN_0043b4f0(&filterA)))->FUN_0043b4d0() == 0x17 ||
                         reinterpret_cast<::FUN_0043b4d0_shell *>((entity2->FUN_0043b4f0(&filterB)))->FUN_0043b4d0() == 0x18))
                    {
                        ::FUN_005ac750((::TESForm *)(player), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()), 0x80);
                        if (((::Controller *)(reinterpret_cast<::FUN_00476c90_Class *>((player))->FUN_00476c90())) != 0)
                            ::FUN_005ac750((::TESForm *)(::Controller *)(((::Controller *)(reinterpret_cast<::FUN_00476c90_Class *>((player))->FUN_00476c90()))), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()), 0x100);
                    }
                    unsigned int filterC;
                    if (::FUN_0043b300((const ::NiRTTI *)(::FormTypeDescriptor *)(&(*reinterpret_cast<::FormTypeDescriptor *>(&::g_01268444))), (::NiAVObject *)(entity2)) ||
                        (acceptUnknown && reinterpret_cast<::FUN_0043b4d0_shell *>((entity2->FUN_0043b4f0(&filterC)))->FUN_0043b4d0() == 0x1e))
                    {
                        partialMatch = true;
                        lastReference = reference;
                        {
                            ParentEntity* parentId = (ParentEntity*)((::EventEntity *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(handle))));
                            EventEntity* parent2 = parentId != 0 ? ((::EventEntity *)(::fnv_006fa820::FUN_006fa820((const char *)(parentId)))) : 0;
                            if (parent2 != 0)
                            {
                                unsigned int filterD;
                                if (reinterpret_cast<::FUN_009c19e0_shell *>((parent2->FUN_0043b4f0(&filterD)))->IsFlagSet() ||
                                    ((GetKindFn)parent2->vtable[0x94 / 4])(parent2) == 0)
                                {
                                    AnimationPacket anim;
                                    Vec3 origin;
                                    reinterpret_cast<::Proxy *>((scene))->FUN_004585f0((*(::NiPoint3 *)(&origin)));
                                    Vec3 direction;
                                    reinterpret_cast<::FUN_009c1a50_shell *>((scene))->FUN_009c1a20((*(const ::hkVector4 *)(&direction)));
                                    reinterpret_cast<::MyPoint439180 *>(&(initialDirection))->FUN_00439180(DAT_010162c0);
                                    reinterpret_cast<::MyPoint439180 *>(&(direction))->FUN_00439180(DAT_010162c0);
                                    Filter sceneFilter;
                                    anim.FUN_004a3f70(((::Filter *)(reinterpret_cast<::FUN_009c1a00_Class *>((scene))->ConstructCF845((::CF845 *)(::Filter *)(&sceneFilter))))->value);
                                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(anim))->FUN_004a3da0(&origin);
                                    reinterpret_cast<::Class_007f68a0 *>(&(anim))->FUN_007f68a0((*(const ::NiPoint3 *)(&direction)));
                                    Collector collector;
                                    reinterpret_cast<::FUN_004a3fb0_shell *>(&(anim))->FUN_004a3fb0((::hkpAllRayHitCollector *)(void *)(&collector));
                                    bool hit = ::FUN_009c5ba0((::World9C *)(::AnimationPacket *)(&anim), (::NiAVObject9C *)(handle), 0, 1);
                                    if (hit)
                                    {
                                        if (((int)(reinterpret_cast<::Callees *>((((::EventCursor *)(::FUN_00460140((int)(((::EventStream *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(anim))->FUN_008cdd90()))))))))->FUN_00726070())) > 0)
                                        {
                                            reinterpret_cast<::FUN_009c1a70_shell *>(&(info))->FUN_009c1a70(((::EventInfo *)(reinterpret_cast<::FUN_004a46b0_class *>((((::EventCursor *)(::FUN_00460140((int)(((::EventStream *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(anim))->FUN_008cdd90()))))))))->GetEntryAt(0))));
                                            candidate = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            labelAfterPartial:
                if (!::fnv_009c2c80::CanProjectileHit((::fnv_009c2c80::RefObj *)(reference), (::fnv_009c2c80::CdBody *)(info.eventHandle), (int)(player), (::fnv_009c2c80::ProjData *)(eventOwner)))
                    candidate = false;
                if (candidate)
                {
                    if (player != 0)
                    {
                        Vec3 hitPoint = initialDirection.ApplyScaled(info.time);
                        Vec3 aimPoint = (*(::Vec3 *)(reinterpret_cast<::Point3Offset *>(&(initialPosition))->ProjectileLaunched((::NiPoint3 *)&(hitPoint), {})));
                        Vec3 tempPoint;
                        ::FUN_004a3970((*(::NiPoint3_local *)(&tempPoint)), (*(const ::hkVector4 *)(&info)));
                        if (reinterpret_cast<::FUN_00444d00_Class *>((player))->FUN_00444d00(1))
                        {
                            reinterpret_cast<::FUN_009795c0_shell *>((player))->FUN_009795c0(reinterpret_cast<::NiPoint3 *>(&(hitPoint))->ComputeMagnitude());
                            reinterpret_cast<::Dummy009c4e60 *>((player))->FUN_009c4e60((*(::NiPoint3 *)&(const ::Vec3 &)(hitPoint)), false);
                        }
                        int lastIndex = -1;
                        for (int k = 0; k < 8 && reinterpret_cast<int*>(info.indexBytes)[k] != -1; ++k)
                        {
                            lastIndex = reinterpret_cast<int*>(info.indexBytes)[k];
                        }
                        picked = ((DispatchFn)player->vtable[0x32c / 4])(player, reference, &aimPoint, &tempPoint,
                                                                         info.eventHandle, lastIndex, 0x24);
                        if (picked)
                            result = handle;
                    }
                    else
                    {
                        picked = true;
                        result = handle;
                    }
                    if (picked && hitTime != 0)
                        *hitTime = info.time;
                }
            }
        }
        if (player != 0)
        {
            if (!picked)
            {
                if (maximumTime != ::_DAT_010231b0)
                {
                    Vec3 away = initialDirection.ApplyScaled(maximumTime);
                    Vec3 dst = (*(::Vec3 *)(reinterpret_cast<::Point3Offset *>(&(initialPosition))->ProjectileLaunched((::NiPoint3 *)&(away), {})));
                    if (reinterpret_cast<::FUN_00444d00_Class *>((player))->FUN_00444d00(1))
                    {
                        reinterpret_cast<::FUN_009795c0_shell *>((player))->FUN_009795c0(reinterpret_cast<::NiPoint3 *>(&(away))->ComputeMagnitude());
                        reinterpret_cast<::Dummy009c4e60 *>((player))->FUN_009c4e60((*(::NiPoint3 *)&(const ::Vec3 &)(away)), false);
                    }
                    ((DispatchFn)player->vtable[0x32c / 4])(player, 0, &dst, &(*reinterpret_cast<::Vec3 *>((void *)&::DAT_011a9484)), 0, -1, 8);
                }
            }
            if (!picked && partialMatch)
            {
                if (lastReference != 0 && lastReference == (*reinterpret_cast<::EventEntity * *>(&::_g_thePlayer)))
                {
                    Vec3 impact;
                    reinterpret_cast<::S005dbe60_Object *>((scene))->FUN_005dbe60((::S005dbe60_Target *)(::Vec3 *)(&impact));
                    if (((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase())) != 0)
                    {
                        if (((::SoundSource *)(reinterpret_cast<::EffectSetting *>((((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase()))))->GetHitSound())) != 0)
                        {
                            int flags = 0x102;
                            AudioPlaybackHandle sound =
                                ((::AudioSystem *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(((::SoundSource *)(reinterpret_cast<::EffectSetting *>((((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase()))))->GetHitSound())))),
                                                             flags, ((::SoundSource *)(reinterpret_cast<::EffectSetting *>((((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase()))))->GetHitSound())));
                            reinterpret_cast<::FUN_00ad8b60_h *>(&(sound))->FUN_00ad8b60(impact.components[0], impact.components[1], impact.components[2]);
                            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(0);
                            if ((*reinterpret_cast<unsigned char *>(&::DAT_011f20a4)) != 0 && ((GetVisualFn)player->vtable[0x1d0 / 4])(player) != 0)
                            {
                                Color color;
                                new ((void *)&(color)) ::ImageSpaceEffectParam(0.0f, 1.0f, 1.0f, DAT_01017870);
                                RenderElement* visual = ((::RenderElement *)(::CreateOctahedron(DAT_0101712c, (const struct ::FUN_004a7800 *)(::Color *)(&color), 1)));
                                reinterpret_cast<::FUN_00a5a040_Class *>((visual))->FUN_00a5a040();
                                reinterpret_cast<::FUN_00440460_S *>((visual))->FUN_00440460((const ::V3 *)(::Vec3 *)(((::Vec3 *)(::FUN_0045bb80((int)(((GetVisualFn)player->vtable[0x1d0 / 4])(player)))))));
                                reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::AudioController * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(visual), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011f210c)))))));
                            }
                        }
                    }
                }
            }
            else if (((::SoundSource *)(reinterpret_cast<::EffectSetting *>((((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase()))))->GetHitSound())) != 0 &&
                     ((picked && lastReference != (*reinterpret_cast<::EventEntity * *>(&::_g_thePlayer))) || !picked) && ((::EventEntity *)(::FUN_00874480((char *)(player)))) != (*reinterpret_cast<::EventEntity * *>(&::_g_thePlayer)) &&
                     ((void *)(reinterpret_cast<::MagicCaster_shell *>((((::AudioSystem *)(::FUN_00453a70()))))->FUN_0044edb0())) != 0)
            {
                Vec3 at, saved, direction, extra, position;
                WorldTarget* world = (WorldTarget*)((void *)(reinterpret_cast<::MagicCaster_shell *>((((::AudioSystem *)(::FUN_00453a70()))))->FUN_0044edb0()));
                position = *((GetLocationFn)world->vtable[3])(world);
                if (lastReference != 0)
                    saved = *((GetPositionFn)lastReference->vtable[0x1f4 / 4])(lastReference);
                else
                    reinterpret_cast<::FUN_004587f0_shell *>((scene))->FUN_004587f0((*(::NiPoint3 *)(&saved)));
                reinterpret_cast<::Proxy *>((scene))->FUN_004585f0((*(::NiPoint3 *)(&at)));
                direction = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(saved))->FUN_00439ef0((::NiPoint3 *)&(at), *(const ::NiPoint3 *)nullptr)));
                extra = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(position))->FUN_00439ef0((::NiPoint3 *)&(at), *(const ::NiPoint3 *)nullptr)));
                float mag = reinterpret_cast<::FUN_004b6190_shell *>(&(extra))->DotProduct((void *)&(direction));
                float len = reinterpret_cast<::FUN_004b6190_shell *>(&(direction))->DotProduct((void *)&(direction));
                float ratio = mag / len;
                Vec3 projected = (*(::Vec3 *)(reinterpret_cast<::Point3Offset *>(&(at))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(FUN_004a3760(ratio, direction)), {})));
                float distance = reinterpret_cast<::NiPoint3 *>((void *)&(const ::Vec3 &)((*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(position))->FUN_00439ef0((::NiPoint3 *)&(projected), *(const ::NiPoint3 *)nullptr)))))->ComputeMagnitude();
                if (distance < DAT_01088210)
                {
                    int flags = 0x102;
                    AudioPlaybackHandle sound =
                        ((::AudioSystem *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(((::SoundSource *)(reinterpret_cast<::EffectSetting *>((((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase()))))->GetHitSound())))), flags,
                                                     ((::SoundSource *)(reinterpret_cast<::EffectSetting *>((((::RenderManager *)(reinterpret_cast<::Actor *>((player))->GetActorBase()))))->GetHitSound())));
                    reinterpret_cast<::FUN_00ad8b60_h *>(&(sound))->FUN_00ad8b60(projected.components[0], projected.components[1], projected.components[2]);
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(0);
                    if ((*reinterpret_cast<unsigned char *>(&::DAT_011f20a4)) != 0)
                    {
                        Color color;
                        new ((void *)&(color)) ::ImageSpaceEffectParam(0.0f, 1.0f, 1.0f, DAT_01017870);
                        RenderElement* visual = ((::RenderElement *)(::CreateOctahedron(DAT_0101712c, (const struct ::FUN_004a7800 *)(::Color *)(&color), 1)));
                        reinterpret_cast<::FUN_00a5a040_Class *>((visual))->FUN_00a5a040();
                        reinterpret_cast<::FUN_00440460_S *>((visual))->FUN_00440460((const ::V3 *)(::Vec3 *)(&projected));
                        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::AudioController * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(visual), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011f210c)))))));
                    }
                }
            }
        }
    }
    return result;
}
