
// src/fallout_shared/havok/teswaterlistener_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /GS /EHsc /Gy /Od (unit src/fallout_shared/havok/teswaterlistener_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/teswaterlistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teswaterlistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_005532a0_cls.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_00563200_Struct.h"
#include "fnv/decl/FUN_00628f30_shell.h"
#include "fnv/decl/FUN_0062e860_cls.h"
#include "fnv/decl/FUN_00630bb0_shell.h"
#include "fnv/decl/FUN_00631100_shell.h"
#include "fnv/decl/FUN_00631140_shell.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/OwnerC9Body.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S00458a10_Vector.h"
#include "fnv/decl/S00630ae0_Result.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/V.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaterSplash_62e970.h"
#include "fnv/decl/WorldObject_c8d3.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/fnv_00437c10__FUN_00437c10.h"
#include "fnv/decl/fnv_004b4ea0__TESDataHandler.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00517000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_00631000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c9c000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011d0000.h"
struct FUN_0062e750_shell
{
    void* FUN_0062e750(unsigned int flags);
};
extern int DAT_011c7a3c;
extern unsigned char DAT_011c7a5a;
void FUN_0062f8e0(unsigned char value);
struct BSOcclusionPlane
{
};
struct ExtraDataList
{
};
struct BSThread
{
};
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane);
extern "C" float __cdecl ExpFloat(float);
float FUN_00630aa0(float value);
extern "C" double __cdecl _exp(double);
float ExpFloat(float value);
extern float _gModifierZero;
struct FUN_005631e0_shell
{
    bool IsNonZero(int a);
};
struct FUN_0062e710_shell
{
    void SetValueAt(float f, int a, int b);
};
struct BSSimpleList_Ragdoll
{
    void* FUN_006310e0();
};
struct TESDataHandler
{
};
struct FUN_006310c0_shell
{
    void FUN_006310c0();
};
struct FUN_00c9a460_shell
{
    void FUN_00c9a600(int a);
};

#include <xmmintrin.h>
struct PhysicsVector
{
    __m128 m_vComponents;
    void FUN_005dbf20(float);
    PhysicsVector* FUN_00630b40(PhysicsVector*);
};
struct PhysicsBounds
{
    PhysicsVector minimum, maximum;
};
struct FUN_005dbf20 : PhysicsVector
{
    FUN_005dbf20(float);
};
struct PhysicsBody
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void GetRotation(PhysicsVector*);
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void GetBounds(PhysicsBounds*);
};
struct PhysicsReference
{
    const PhysicsVector* FUN_004b4ec0();
    const PhysicsVector* FUN_006310c0();
    const PhysicsVector* FUN_00560e50();
};
float FUN_00408840(float);
extern float DAT_0119af4c, DAT_0119af48, DAT_0119af44;
extern float DAT_0119af40, DAT_011cc5e4, DAT_011cc5e0, DAT_0119af3c, DAT_0119af38;
struct RuntimeFloatSetting
{
};
struct ReferenceMap
{
};
struct PhysicsController
{
    int FUN_00630170(PhysicsReference*, float, float, bool);
};
// @fnv 0x00630170
int PhysicsController::FUN_00630170(PhysicsReference* reference, float height, float deltaTime, bool alternate)
{
    int result = 0;
    PhysicsVector position;
    new ((void *)&(position)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(reference->FUN_004b4ec0())));
    PhysicsBody* body = ((::PhysicsBody *)(::FUN_004b5a80(reference)));
    PhysicsBounds bounds;
    new ((void *)&(bounds)) ::fnv_00437c10::FUN_00437c10();
    body->GetBounds(&bounds);
    if (reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2) <= height)
    {
        int handle = ::FUN_00517670((::TESDataHandler *)(reference));
        if (((bool)(::FUN_00c8cce0(&handle))))
        {
            PhysicsReference* state = ((::PhysicsReference *)(reinterpret_cast<::Twin_0044ddc0 *>((reference))->GetName()));
            if (state)
            {
                reinterpret_cast<::TESForm *>((state))->ClearData();
                PhysicsVector direction;
                new ((void *)&(direction)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((const ::PhysicsVector *)(::FUN_00460140((int)(state)))))));
                PhysicsVector velocity;
                new ((void *)&(velocity)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((const ::PhysicsVector *)(::FUN_00560dc0((::TESDataHandler *)(reference)))))));
                float mass = reinterpret_cast<::fnv_004b4ea0::TESDataHandler *>((reference))->FUN_004b4ea0();
                float extent = reinterpret_cast<::bhkCharacterController *>(&(bounds.maximum))->GetVectorElement(2) - reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2);
                float lower = extent * 0.25 + reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2);
                float upper = extent * 0.8500000238418579 + reinterpret_cast<::bhkCharacterController *>(&(bounds.minimum))->GetVectorElement(2);
                float amount = (height - lower) / (upper - lower);
                if (amount <= 0.0)
                {
                    reinterpret_cast<::TESForm *>((state))->ClearData();
                    return result;
                }
                float strength = ::GetObjectMass((::WorldObject62b3 *)(body));
                bool dampVertical = true;
                if (amount < DAT_0119af4c && strength > 0.0)
                {
                    if (amount > DAT_0119af48)
                        strength = DAT_0119af44;
                    else if (amount > DAT_0119af40)
                        strength = DAT_011cc5e4;
                    else if (amount > DAT_011cc5e0)
                        strength = DAT_0119af3c;
                    PhysicsVector component;
                    if (DAT_0119af38 > FUN_00408840(reinterpret_cast<::S004586d0_Obj *>((((::PhysicsVector *)(reinterpret_cast<::Holder *>(&(velocity))->FUN_00458700((::Holder *)(::PhysicsVector *)(&component), 2)))))->FUN_004586d0()))
                        dampVertical = false;
                }
                strength = -strength;
                PhysicsVector force;
                new ((void *)&(force)) ::Vec3();
                FUN_005dbf20 multiplier(strength * mass);
                reinterpret_cast<::S00630ae0_Result *>(&(force))->FUN_00630ae0((const ::S00630ae0_Source *)(const ::PhysicsVector *)(&multiplier), (const ::S00630ae0_Vector *)(const ::PhysicsVector *)(&direction));
                PhysicsVector torque;
                new ((void *)&(torque)) ::Vec3();
                if (!::FUN_00c9c380((void *)(reference), {}))
                {
                    PhysicsBounds inertiaBounds;
                    new ((void *)&(inertiaBounds)) ::fnv_00437c10::FUN_00437c10();
                    reinterpret_cast<::WorldObject_c8d3 *>((body))->GetAabb((*(::Aabb_c8d3 *)(&inertiaBounds)));
                    PhysicsVector localTorque;
                    reinterpret_cast<::FUN_005532a0_cls *>(&(localTorque))->FUN_005532a0(0, 0, 0, 0);
                    PhysicsVector sizes;
                    new ((void *)&(sizes)) ::Vec3();
                    reinterpret_cast<::S00458a10_Vector *>(&(sizes))->FUN_00458a10((const ::S00458a10_Vector *)(const ::PhysicsVector *)(&inertiaBounds.maximum), (const ::S00458a10_Vector *)(const ::PhysicsVector *)(&inertiaBounds.minimum));
                    int smallest = reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) < reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1)
                                       ? (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1) < reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 1)
                                       : (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) < reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 0);
                    int largest = reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1)
                                      ? (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(1) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 1)
                                      : (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(0) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(2) ? 2 : 0);
                    if (reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(smallest) > reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(largest) * 1.5f)
                    {
                        reinterpret_cast<::bhkCharacterController *>(&(localTorque))->GetVectorElement(largest) =
                            reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(smallest) / reinterpret_cast<::bhkCharacterController *>(&(sizes))->GetVectorElement(largest) * 0.1f * SignOfFloat(strength);
                        PhysicsVector rotation;
                        ::FUN_006240d0((void *)&(rotation));
                        body->GetRotation(&rotation);
                        reinterpret_cast<::FUN_00630bb0_shell *>(&(torque))->FUN_00630bb0((::Source630 *)(&rotation), (void *)(&localTorque));
                        reinterpret_cast<::V *>(&(torque))->FUN_00553f70((*(const ::V *)(reference->FUN_006310c0())));
                    }
                    else
                        reinterpret_cast<::AlignedVector *>(&(torque))->FUN_004a3f10((*(const ::AlignedVector *)(reference->FUN_006310c0())));
                }
                else
                    reinterpret_cast<::AlignedVector *>(&(torque))->FUN_004a3f10((*(const ::AlignedVector *)(reference->FUN_006310c0())));
                reinterpret_cast<::TESForm *>((state))->ClearData();
                reinterpret_cast<::FUN_00631140_shell *>((reference))->FUN_00631140(deltaTime, (int)(&force), (int)(&torque));
                PhysicsVector secondForce;
                new ((void *)&(secondForce)) ::Vec3();
                FUN_005dbf20 secondMultiplier(mass * -1.0);
                reinterpret_cast<::S00630ae0_Result *>(&(secondForce))->FUN_00630ae0((const ::S00630ae0_Source *)(const ::PhysicsVector *)(&secondMultiplier), (const ::S00630ae0_Vector *)(const ::PhysicsVector *)(&direction));
                reinterpret_cast<::FUN_00631100_shell *>((reference))->FUN_00631100(deltaTime, (int)(&secondForce));
                reinterpret_cast<::TESForm *>((state))->ClearData();
                PhysicsVector linear;
                new ((void *)&(linear)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((const ::PhysicsVector *)(::FUN_00560dc0((::TESDataHandler *)(reference)))))));
                float vertical = reinterpret_cast<::bhkCharacterController *>(&(linear))->GetVectorElement(2);
                reinterpret_cast<::bhkCharacterController *>(&(linear))->GetVectorElement(2) = 0;
                if (dampVertical)
                {
                    vertical *= FUN_00630aa0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting979)))))) * -1.0 * deltaTime);
                }
                PhysicsVector magnitude;
                if (reinterpret_cast<::S004586d0_Obj *>((linear.FUN_00630b40(&magnitude)))->FUN_004586d0() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting975)))))))
                {
                    FUN_005dbf20 factor(FUN_00630aa0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting978)))))) * -1.0 * deltaTime));
                    reinterpret_cast<::S_00627920 *>(&(linear))->FUN_00627920((::S_00561240 *)(&factor));
                }
                reinterpret_cast<::bhkCharacterController *>(&(linear))->GetVectorElement(2) = vertical;
                reinterpret_cast<::FUN_005616d0_Owner *>((reference))->OnTrigger((::TriggerContext *)(&linear));
                PhysicsVector angular;
                new ((void *)&(angular)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(reference->FUN_00560e50())));
                FUN_005dbf20 factor(FUN_00630aa0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RuntimeFloatSetting *>(&::originalRuntimeFloatSetting980)))))) * -1.0 * deltaTime));
                reinterpret_cast<::S_00627920 *>(&(angular))->FUN_00627920((::S_00561240 *)(&factor));
                reinterpret_cast<::FUN_00561800_Class *>((reference))->FUN_00561800((::FUN_00561730_Obj *)(&angular));
                reinterpret_cast<::TESForm *>((state))->ClearData();
            }
        }
        int flag = alternate ? 128 : 8;
        if (!reinterpret_cast<::FUN_005631e0_shell *>((body))->IsNonZero(flag))
        {
            reinterpret_cast<::FUN_00628f30_shell *>((body))->SetFlag(flag, true);
            reinterpret_cast<::WaterSplash_62e970 *>(this)->SpawnWaterSplash((::Body_62e970 *)(body), FUN_004587d0(height));
            result = 1;
        }
        reinterpret_cast<::FUN_0084d310_class *>(&((*reinterpret_cast<::ReferenceMap *>(&::g_011cc584))))->FUN_0084d310((int)(reference), true);
    }
    else
    {
        int flag = alternate ? 128 : 8;
        if (reinterpret_cast<::FUN_005631e0_shell *>((body))->IsNonZero(flag))
        {
            reinterpret_cast<::WaterSplash_62e970 *>(this)->SpawnWaterSplash((::Body_62e970 *)(body), FUN_004587d0(height));
            result = 2;
        }
        reinterpret_cast<::FUN_00628f30_shell *>((body))->SetFlag(flag, false);
    }
    return result;
}
