
// src/staging/blk_008a0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_008a50f0_class.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_008a50d0__bhkCharacterController.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00c80000.h"
#include <xmmintrin.h>

struct FUN_008b3d70_Vec3
{
    float x;
    float y;
    float z;
    FUN_008b3d70_Vec3 ApplyScaled(float f) const;
};

struct FUN_008b3d70_Hit
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* GetObject();
};

struct FUN_008b3d70_World;

FUN_008b3d70_Hit* FUN_008cfbc0(FUN_008b3d70_World* world, FUN_008b3d70_Vec3 origin, FUN_008b3d70_Vec3 dir, float* dist,
                               int flag);

struct FUN_008b3d70_hkVec
{
    __m128 v;
};

struct FUN_008b3d70_Sphere
{
    __m128 v;
};

struct FUN_008b3d70_Body
{
};

struct FUN_008b3d70_Wrap
{
};

struct FUN_008b3d70_Picker
{
    void* FUN_008b3d70(FUN_008b3d70_Vec3 start, FUN_008b3d70_Vec3 end);
};

// @fnv 0x008b3d70
void* FUN_008b3d70_Picker::FUN_008b3d70(FUN_008b3d70_Vec3 start, FUN_008b3d70_Vec3 end)
{
    FUN_008b3d70_World* world = ((::FUN_008b3d70_World *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()));
    FUN_008b3d70_Hit* object = 0;
    float distance = 512.0f;
    FUN_008b3d70_Vec3 direction = (*(::FUN_008b3d70_Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(end))->FUN_00439ef0((::NiPoint3 *)&(start), *(const ::NiPoint3 *)nullptr)));
    ::FUN_00525340((float *)(::FUN_008b3d70_Vec3 *)(&direction));
    FUN_008b3d70_Vec3 origin = (*(::FUN_008b3d70_Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(end))->FUN_00439ef0((::NiPoint3 *)&(const ::FUN_008b3d70_Vec3 &)(direction.ApplyScaled(distance).ApplyScaled(0.5f)), *(const ::NiPoint3 *)nullptr)));
    object = FUN_008cfbc0(world, origin, direction, &distance, 0);
    if (!object)
    {
        FUN_008b3d70_Sphere bound;
        ::FUN_006240d0((void *)&(bound));
        FUN_008b3d70_hkVec center;
        new ((void *)&(center)) ::Vec3();
        ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(center), (const ::fnv_004a3e00::NiPoint3 &)(end));
        reinterpret_cast<::FUN_008a50f0_class *>(&(bound))->FUN_008a50f0((int)&(center));
        reinterpret_cast<::fnv_008a50d0::bhkCharacterController *>(&(bound))->FUN_008a50d0(200.0f);
        FUN_008b3d70_Body* body = ((::FUN_008b3d70_Body *)(::FUN_00c806b0(world, &bound, 0)));
        if (body)
        {
            FUN_008b3d70_Wrap* wrapper = ((::FUN_008b3d70_Wrap *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(void *)(((void *)(::FUN_004ae750((void *)(body))))))));
            if (wrapper)
                object = ((::FUN_008b3d70_Hit *)(reinterpret_cast<::Twin_0044ddc0 *>((wrapper))->GetName()));
        }
    }
    if (object)
        return object->GetObject();
    return 0;
}
