
// src/fallout/ai/bsplayerdistancecheckcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/bsplayerdistancecheckcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_008d17d0_Class.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011f4000.h"
struct NiRTTI
{
};

struct FUN_008d1610_shell
{
    const NiRTTI* const* GetNiRTTI();
};

// @fnv 0x008d1610
const NiRTTI* const* FUN_008d1610_shell::GetNiRTTI()
{
    return &(*reinterpret_cast<const ::NiRTTI *const *>(&::g_011dfeac));
}

struct BSPlayerDistanceCheckController
{
    virtual ~BSPlayerDistanceCheckController();
    void* ScalarDeletingDestructor(unsigned int flags);
};

struct TESObjectDoorController
{
    TESObjectDoorController();
    void* vtable;
    unsigned int references;
    void* next;
    unsigned short flags;
    unsigned short state;
    float frequency;
    float phase;
    float startTime;
    float stopTime;
    float lastTime;
    float weightedTime;
    float scaledTime;
    void* target;
    void* interpolation;
    void* door;
    void* animation;
};
struct ControllerFactory
{
    TESObjectDoorController* CreateController(void*);
};
// @fnv 0x008d1740
TESObjectDoorController* ControllerFactory::CreateController(void* context)
{
    TESObjectDoorController* result = new TESObjectDoorController;
    reinterpret_cast<::FUN_008d17d0_Class *>(this)->FUN_008d17d0((::BGSAcousticSpace *)(result), context);
    return result;
}


struct DoorSpawnRequest
{
    unsigned int unk00;
};
struct ItemHandle
{
    unsigned int raw;
    unsigned int unk04;
    unsigned int unk08;
};
struct ItemRef
{
};

struct Manager
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual ItemRef* v1f4(ItemHandle* out, void* h);
};

struct FUN_008d1670_cls
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    void* m_2c;
    unsigned int unk30, unk34;
    void(__cdecl* m_38)(void*);
    void UpdateDoorSpawn(unsigned int unkArg);
};

// @fnv 0x008d1670
void FUN_008d1670_cls::UpdateDoorSpawn(unsigned int unkArg)
{
    DoorSpawnRequest* req;
    ItemHandle handle;
    if (((double)(reinterpret_cast<::BSFaceGenMorphData *>(this)->FUN_00508120())) < ::_DAT_01012060 || !::GetField38((char *)this) || (*reinterpret_cast<::Manager * *>(&::_g_thePlayer)) == 0)
    {
    }
    else
    {
        req = ((::DoorSpawnRequest *)(::FUN_00653270((const ::NiRTTI *)(char *)((char*)&(*reinterpret_cast<char *>(&::g_011f4280))), (::NiObject *)(m_2c))));
        if (req != 0)
        {
            reinterpret_cast<::FUN_00439ef0_class *>(((*reinterpret_cast<::Manager * *>(&::_g_thePlayer))->v1f4(&handle, ((void *)(::FUN_0045bb80((intptr_t)(req)))))))->FUN_00439ef0({}, *(const ::NiPoint3 *)nullptr);
            if (((double)(reinterpret_cast<::NiPoint3 *>(&(handle))->ComputeMagnitude())) < ((double)(reinterpret_cast<::BSFaceGenMorphData *>(this)->FUN_00508120())))
            {
                m_38(req);
            }
        }
    }
}

namespace fnv_008d1720 {


struct FUN_008d1720_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void* m_pIntegerData;

    void FUN_008d1720();
};

// @fnv 0x008d1720
void FUN_008d1720_cls::FUN_008d1720()
{
    ::FUN_0043b300((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_011f4280))), (::NiAVObject *)(m_pIntegerData));
}
}  // namespace fnv_008d1720

struct FUN_00a6d290
{
    virtual void v00();
    ~FUN_00a6d290();
};
struct FUN_008d1650 : FUN_00a6d290
{
    virtual void v00();
    ~FUN_008d1650();
};
// Runs the destructor and, when bit 0 of flags is set, frees this with operator delete; returns this.
// @fnv 0x008d1620
void* BSPlayerDistanceCheckController::ScalarDeletingDestructor(unsigned int flags)
{
    reinterpret_cast<::FUN_008d1650 *>((this))->FUN_008d1650::~FUN_008d1650();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x3c);
    return this;
}
// @fnv 0x008d1650
FUN_008d1650::~FUN_008d1650()
{}
