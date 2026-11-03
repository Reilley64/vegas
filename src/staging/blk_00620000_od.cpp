
// src/staging/blk_00620000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <new>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/A72BB0_DataStreamOwner.h"
#include "fnv/decl/ActiveEffect.h"
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C68E30Owner.h"
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CollisionPair.h"
#include "fnv/decl/CombatWorldStateListNode.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004567e0_Class.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_004a3d60_class.h"
#include "fnv/decl/FUN_004a3d80_Class.h"
#include "fnv/decl/FUN_004a51b0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004ae700_S.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_004d9da0_shell.h"
#include "fnv/decl/FUN_005081b0_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00526ae0_class.h"
#include "fnv/decl/FUN_0052ce20_shell.h"
#include "fnv/decl/FUN_005532a0_cls.h"
#include "fnv/decl/FUN_005545b0.h"
#include "fnv/decl/FUN_005545d0_Class.h"
#include "fnv/decl/FUN_005610f0_cls.h"
#include "fnv/decl/FUN_005631e0_shell.h"
#include "fnv/decl/FUN_0056d2c0_cls.h"
#include "fnv/decl/FUN_0056ded0.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_0061f4d0.h"
#include "fnv/decl/FUN_0061f580_shell.h"
#include "fnv/decl/FUN_0061fc50.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00622290_cls.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/FUN_00623570_class.h"
#include "fnv/decl/FUN_006295a0_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00634830_cls.h"
#include "fnv/decl/FUN_00634870_shell.h"
#include "fnv/decl/FUN_00636bd0_cls.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_006a1b60_Class.h"
#include "fnv/decl/FUN_006b8310_class.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_00807770_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a726a0_cls.h"
#include "fnv/decl/FUN_00a72ca0_Class.h"
#include "fnv/decl/FUN_00c903b0_class.h"
#include "fnv/decl/FUN_00c9c390_Class.h"
#include "fnv/decl/FUN_00cac980_class.h"
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FnvCpu_FUN_00a7b850_CpuObject.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiPSysEmitterCtlr_StandIn.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Precipitation.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S00628640_Vector.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/ShaderOwner.h"
#include "fnv/decl/Sky.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/SpawnPlacerP.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/VecHolder.h"
#include "fnv/decl/WorldObject_c8d3.h"
#include "fnv/decl/_FUN_0052aa80_shell.h"
#include "fnv/decl/_dummy_476a80.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/bhkUnaryAction.h"
#include "fnv/decl/fnv_00437c10__FUN_00437c10.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_005617c0__FUN_005617c0_.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_0062a100__FUN_0062a100_shell.h"
#include "fnv/decl/fnv_00631370__WorkOwner.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/decl/s4a5200__Owner.h"
#include "fnv/decl/xPick.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00486000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b0000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00621000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00626000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00637000.h"
#include "fnv/symbols_00639000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006e6000.h"
#include "fnv/symbols_00993000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c9c000.h"
#include "fnv/symbols_00cab000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "../../include/layout_support.h"

extern int DAT_0104e510;

struct FUN_006318b0_Class
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_006318b0_Class* FUN_006318b0(int count);
};

// Sets the vtable, stores count, allocates count*4 zeroed bytes into m_data and returns this.
// @fnv 0x006318b0
FUN_006318b0_Class* FUN_006318b0_Class::FUN_006318b0(int count)
{
    m_vtbl = &DAT_0104e510;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    unsigned int bytes = m_uiItemCount * 4;
    m_data = ::FUN_00aa1070(bytes);
    memset(m_data, 0, m_uiItemCount * 4);
    return this;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3* ScaleTo(NiPoint3* dst, float scale);
};
// Multiplies this point's x, y and z by scale, stores the result in dst and returns dst.
// @fnv 0x00633b40
NiPoint3* NiPoint3::ScaleTo(NiPoint3* dst, float scale)
{
    NiPoint3 tmp = *this;
    tmp.x *= scale;
    tmp.y *= scale;
    tmp.z *= scale;
    *dst = tmp;
    return dst;
}

extern int DAT_0104d9e0;
struct FUN_00620110_Class
{
    int* m_vtbl;
    void FUN_00620110();
    void FUN_006201c0();
};
// @fnv 0x00620110
void FUN_00620110_Class::FUN_00620110()
{
    m_vtbl = (int*)&DAT_0104d9e0;
    FUN_006201c0();
}

struct FUN_006205a0_Class
{
    int FUN_006205a0();
};
// @fnv 0x006205a0
int FUN_006205a0_Class::FUN_006205a0()
{
    return *(int*)((char*)this + 0x10) & 0x1f;
}

struct T_
{
};

struct FUN_006205c0_Class
{
    void ForwardToMember(void* arg);
};

// @fnv 0x006205c0
void FUN_006205c0_Class::ForwardToMember(void* arg)
{
    reinterpret_cast<::AlignedVector *>((((T_*)((char*)this + 0x20))))->FUN_004a3f10((*(const ::AlignedVector *)(arg)));
}

struct TESIdleForm;
struct HighProcess
{
    TESIdleForm* GetSelectedIdleForm();
};
// Returns the idle form from the given process, or null if the process pointer is null.
// @fnv 0x00621480
TESIdleForm* FUN_00621480(HighProcess* process)
{
    TESIdleForm* result;
    if (process)
        result = process->GetSelectedIdleForm();
    else
        result = 0;
    return result;
}

struct AlphaColor
{
};

struct FUN_006218d0_Class
{
    void FUN_006218d0(float);
};

// @fnv 0x006218d0
void FUN_006218d0_Class::FUN_006218d0(float f)
{
    reinterpret_cast<::FUN_0052ce20_shell *>((((AlphaColor*)((char*)this + 8))))->FUN_0052ce20(f);
}

struct ArrSI
{
};
struct ObjHelper
{
    void* FUN_00621a90();
};
struct FUN_00621ad0_Class
{
    void FUN_00621ad0();
};
// Calls FUN_00621480 with the flags returned by GetFlags on the object obtained from FUN_00621a90().
// @fnv 0x00621ad0
void FUN_00621ad0_Class::FUN_00621ad0()
{
    ::FUN_00621480((::HighProcess *)(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((ObjHelper*)this)->FUN_00621a90())))->GetName()))));
}

struct FUN_00621b20_Class
{
    int m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_auiShapeKeys;
    float m_iThirdValue;
    void FUN_00621b20(float value);
};

// @fnv 0x00621b20
void FUN_00621b20_Class::FUN_00621b20(float value)
{
    m_iThirdValue = value;
}

struct FUN_00621b40_Class
{
    void FUN_00621b60();
    void FUN_00621b40();
};
// @fnv 0x00621b40
void FUN_00621b40_Class::FUN_00621b40()
{
    FUN_00621b60();
}

struct FUN_00437c10
{
};
struct FUN_00621c40_Class
{
    FUN_00621c40_Class* FUN_00621c40(void);
};
// @fnv 0x00621c40
FUN_00621c40_Class* FUN_00621c40_Class::FUN_00621c40(void)
{
    new ((void *)(((FUN_00437c10*)this))) ::fnv_00437c10::FUN_00437c10();
    return this;
}

extern int DAT_0104dc94;

struct FUN_00622780_Class
{
    int* m_vtbl;
    int m_uiItemCount;
    void FUN_00622780();
};

// @fnv 0x00622780
void FUN_00622780_Class::FUN_00622780()
{
    m_vtbl = &DAT_0104dc94;
    ::FUN_004b0220(m_uiItemCount);
}

struct FUN_006228e0_shell
{
    unsigned int FUN_006228e0(unsigned int, void*);
    unsigned int FUN_006227b0(unsigned int arg);
};

// Calls FUN_006228e0 with the 16-bit value at offset 0xa of this object and the given argument, returning its result.
// @fnv 0x006227b0
unsigned int FUN_006228e0_shell::FUN_006227b0(uintptr_t arg)
{
    return FUN_006228e0(*(unsigned short*)((char*)this + 0xa), (void*)arg);
}

struct hkStringPtr
{
    void operator=(const char*);
};
struct FUN_00622f60_Class
{
    hkStringPtr m_str;
    void SetString(const char* s);
};
// @fnv 0x00622f60
void FUN_00622f60_Class::SetString(const char* apString)
{
    reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(*(hkStringPtr*)((char*)this + 0x74)))->FUN_00cb0c10(apString);
}

struct TgtOps
{
};
struct FUN_00623070_Class
{
    BSSimpleList<int*>* FUN_00623070();
};
// @fnv 0x00623070
BSSimpleList<int*>* FUN_00623070_Class::FUN_00623070()
{
    return ((::BSSimpleList<int *> *)(reinterpret_cast<::Callees *>((((::BSSimpleList<int *> *)(::FUN_00460140((int)(reinterpret_cast<TgtOps*>(this)))))))->FUN_00726070()));
}

namespace fnv_006232f0 {
struct TgtOps
{
};
struct FUN_00807770_Class
{
};
struct FUN_006232f0_Class
{
    void FUN_006232f0(int a);
};
// Retrieves the source file object for index a and invokes its FUN_00807770 method.
// @fnv 0x006232f0
void FUN_006232f0_Class::FUN_006232f0(int aiIndex)
{
    reinterpret_cast<::FUN_00807770_Class *>((((FUN_00807770_Class*)((void *)(::FUN_00460140((int)(((TgtOps*)this))))))))->FUN_00807770({});
}
}  // namespace fnv_006232f0

extern int DAT_0104dd5c;

struct FUN_006234b0_Class
{
    int* m_vtbl;
    FUN_006234b0_Class* FUN_006234b0();
};

// @fnv 0x006234b0
FUN_006234b0_Class* FUN_006234b0_Class::FUN_006234b0()
{
    reinterpret_cast<::FUN_00623570_class *>(this)->FUN_00623570();
    m_vtbl = &DAT_0104dd5c;
    return this;
}

struct FUN_00624020_Class
{
    int m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_next;
    FUN_00624020_Class* GetLastNode();
};

// Walks the m_next chain from this node and returns the last node, whose m_next is null.
// @fnv 0x00624020
FUN_00624020_Class* FUN_00624020_Class::GetLastNode()
{
    FUN_00624020_Class* body = this;
    while (body->m_next)
        body = (FUN_00624020_Class*)body->m_next;
    return body;
}


struct FUN_00624050_Class
{
    int m_vtbl;
    int m_uiItemCount;
    void* m_data;
    float FUN_00624050();
};

// @fnv 0x00624050
float FUN_00624050_Class::FUN_00624050()
{
    return FUN_00577bf0(reinterpret_cast<unsigned char*>(&this->m_uiItemCount));
}

struct bhkFilter
{
    int FUN_006240b0();
};

// @fnv 0x006240b0
int bhkFilter::FUN_006240b0()
{
    return ((int)(reinterpret_cast<::FUN_004d9da0_shell *>(this)->FUN_004d9da0()));
}

struct FUN_00c903b0_Class
{
};
// If DAT_01268360 is set, calls its ReleaseReference method, then stores value into DAT_01268360.
// @fnv 0x006263c0
void __cdecl FUN_006263c0(int value)
{
    if ((*reinterpret_cast<int *>(&::DAT_01268360)))
        reinterpret_cast<::FUN_00c903b0_class *>((((FUN_00c903b0_Class*)(*reinterpret_cast<int *>(&::DAT_01268360)))))->ReleaseReference();
    (*reinterpret_cast<int *>(&::DAT_01268360)) = value;
}

namespace fnv_006263f0 {
struct FUN_00c903b0_Class
{
};
void __cdecl FUN_006263f0(int value);
// If DAT_01268364 is set, calls ReleaseReference on it, then stores value into DAT_01268364.
// @fnv 0x006263f0
void __cdecl FUN_006263f0(int value)
{
    if ((*reinterpret_cast<int *>(&::DAT_01268364)))
        reinterpret_cast<::FUN_00c903b0_class *>((reinterpret_cast<FUN_00c903b0_Class*>((*reinterpret_cast<int *>(&::DAT_01268364)))))->ReleaseReference();
    (*reinterpret_cast<int *>(&::DAT_01268364)) = value;
}
}  // namespace fnv_006263f0

struct FUN_00626560_Class
{
    void FUN_00626560(int);
};
struct FUN_00626450_Class
{
    FUN_00626450_Class* FUN_00626450();
};
struct FUN_00626470_Class
{
    void FUN_00626470(int a, int b);
    void CallAndForwardResult(int a, int b);
};

// @fnv 0x00626470
void FUN_00626470_Class::FUN_00626470(int a, int b)
{
    CallAndForwardResult(a, b);
}

struct FUN_00626490_Class
{
    int FUN_00626490(int key, int def);
};

// @fnv 0x00626490
int FUN_00626490_Class::FUN_00626490(int key, int def)
{
    return reinterpret_cast<::FUN_00cb1930_t *>(this)->LookupHashEntry(key, def);
}

struct FUN_00cb18f0_t
{
    int FUN_00cb1fb0(int);
};
struct FUN_006264b0_Class
{
    void FUN_006264b0(int key);
};
// @fnv 0x006264b0
void FUN_006264b0_Class::FUN_006264b0(int key)
{
    ((FUN_00cb18f0_t*)this)->FUN_00cb1fb0(key);
}

struct FUN_00cb1a60_Class
{
    void* ResetEntries();
    void* FUN_006264d0();
};

// @fnv 0x006264d0
void* FUN_00cb1a60_Class::FUN_006264d0()
{
    return ResetEntries();
}

struct FUN_00626660_Class
{
    char* m_vtbl;
    char* FUN_00626660(int idx);
};

// @fnv 0x00626660
char* FUN_00626660_Class::FUN_00626660(int idx)
{
    return m_vtbl + idx * 8;
}

// @fnv 0x00626790
void __cdecl NoOpLoop(int unused, int count)
{
    for (int i = 0; i < count; ++i)
    {
    }
}

struct TESObjectREFR
{
};
struct FUN_00626d00_Class
{
    void SetObjectFlags(unsigned int flags);
};
// @fnv 0x00626d00
void FUN_00626d00_Class::SetObjectFlags(unsigned int flags)
{
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)((char*)this + 0x14))))->AssignLandTexture((::TESLandTexture *)(flags));
}

struct FUN_006288a0_Class
{
    int* GetOffset110();
};

// @fnv 0x006288a0
int* FUN_006288a0_Class::GetOffset110()
{
    return (int*)((char*)this + 0x110);
}

struct Dummy629670
{
};

struct FUN_00629650_Class
{
    void FUN_00629650(bool flag);
};

struct FUN_006296b0_Class
{
    int m_auiShapeKeys;
    unsigned int m_flags;
    void FUN_006296b0(unsigned int mask);
};

// @fnv 0x006296b0
void FUN_006296b0_Class::FUN_006296b0(unsigned int mask)
{
    m_flags &= ~mask;
}

struct FUN_00629a80_Class
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    void FUN_00629a80();
    FUN_00629a80_Class* FUN_006299a0();
};

// @fnv 0x006299a0
FUN_00629a80_Class* FUN_00629a80_Class::FUN_006299a0()
{
    FUN_00629a80();
    return this;
}

extern int DAT_0104e150;

struct FUN_00629ba0_Class
{
    int* m_vtbl;
    void* InitArray(int);
};

struct FUN_006299f0_Class
{
    int* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    FUN_006299f0_Class* Construct(int);
};

// @fnv 0x006299f0
FUN_006299f0_Class* FUN_006299f0_Class::Construct(int aiValue)
{
    reinterpret_cast<::FUN_00629ba0_Class *>(this)->InitArray(aiValue);
    m_vtbl = &DAT_0104e150;
    return this;
}

struct FUN_00629e20_Class
{
    void FUN_00629e20(int a, int b, int c);
};

// Stores c at offset 4 and the low 16 bits of b at offset 8 of the object at a.
// @fnv 0x00629e20
void FUN_00629e20_Class::FUN_00629e20(int pObject, int iValue, int sValue)
{
    *(int*)((char*)pObject + 4) = iValue;
    *(short*)((char*)pObject + 8) = (short)sValue;
}

struct Unk6b
{
};

struct FUN_00629ee0_Class
{
    int m_vtbl;
    int m_auiShapeKeys;
    Unk6b m_unk;
    void FUN_00629ee0(void* param);
};

// Clears the short at offset 8 of param, then calls FreeMemory on the object at this+0xc with param.
// @fnv 0x00629ee0
void FUN_00629ee0_Class::FUN_00629ee0(void* param)
{
    *(short*)((char*)param + 8) = 0;
    reinterpret_cast<::FUN_006b8310_class *>((((Unk6b*)((char*)this + 0xc))))->FreeMemory(param);
}

extern int DAT_0104e190;
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_00629fd0_Class : public AX
{
    AX* FUN_00629fd0();
};
// Sets the object's vtable pointer to DAT_0104e190, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00629fd0
AX* FUN_00629fd0_Class::FUN_00629fd0()
{
    *reinterpret_cast<int**>(this) = &DAT_0104e190;
    FUN_006b3eb0(0, 0);
    return this;
}

extern int DAT_0104e190;
struct GlobalObject_00869f00
{
    int* m_vtbl;
    void Clear(bool);
    void FUN_0062a000();
};
// @fnv 0x0062a000
void GlobalObject_00869f00::FUN_0062a000()
{
    m_vtbl = &DAT_0104e190;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

void FUN_004a3b50(void* p);
struct FUN_0062a290_Class
{
    void FUN_0062a290();
};
struct FUN_0062a2b0_Class
{
    void FUN_0062a2b0();
};
struct FUN_004a3d60_Class
{
};
struct FUN_0062a2d0_Class
{
    void FUN_0062a2d0();
};
// @fnv 0x0062a290
void FUN_0062a290_Class::FUN_0062a290()
{
    reinterpret_cast<::FUN_0062a2b0_Class *>(((char*)this + 0x10))->FUN_0062a2b0();
    FUN_004a3b50(this);
}
// @fnv 0x0062a2b0
void FUN_0062a2b0_Class::FUN_0062a2b0()
{
    *(int*)((char*)this + 0x50) = 0;
    reinterpret_cast<::FUN_0062a2d0_Class *>(this)->FUN_0062a2d0();
}
// @fnv 0x0062a2d0
void FUN_0062a2d0_Class::FUN_0062a2d0()
{
    reinterpret_cast<::FUN_004a3d60_class *>((((FUN_004a3d60_Class*)this)))->FUN_004a3d60();
    reinterpret_cast<::FUN_004a3d80_Class *>((this))->FUN_004a3d80();
}

extern int DAT_0104e254;
struct FUN_0062a480_Class
{
    int* m_vtbl;
    int m_auiShapeKeys;
    FUN_0062a480_Class* FUN_0062a480();
};
// Calls FUN_0061f4d0(0), sets m_vtbl to &DAT_0104e254, and returns this.
// @fnv 0x0062a480
FUN_0062a480_Class* FUN_0062a480_Class::FUN_0062a480()
{
    new ((void *)this) ::FUN_0061f4d0((void *)(0));
    m_vtbl = &DAT_0104e254;
    return this;
}

namespace fnv_00631780 {

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_00631780_Class
{
    int* m_vtbl;
    void FUN_00631780();
};

// @fnv 0x00631780
void FUN_00631780_Class::FUN_00631780()
{
    m_vtbl = (int*)&::DAT_0104e4bc;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_00631780

struct FUN_00632ce0_Class
{
    unsigned char FUN_00632ce0();
};

// @fnv 0x00632ce0
unsigned char FUN_00632ce0_Class::FUN_00632ce0()
{
    return ((unsigned char*)this)[0xac];
}

struct FUN_00632d00_Class
{
    int* GetField600();
};
// @fnv 0x00632d00
int* FUN_00632d00_Class::GetField600()
{
    return *(int**)((char*)this + 0x600);
}

struct FUN_00633bf0_Class
{
    void FUN_00633bf0(const NiPoint3* p);
};

// Copies the NiPoint3 pointed to by p into the object's field at offset 0x20.
// @fnv 0x00633bf0
void FUN_00633bf0_Class::FUN_00633bf0(const NiPoint3* apPoint)
{
    *(NiPoint3*)((char*)this + 0x20) = *apPoint;
}

struct FUN_00633c20_Class
{
    void FUN_00633c20(float a, float b);
};
// @fnv 0x00633c20
void FUN_00633c20_Class::FUN_00633c20(float a, float b)
{
    *(float*)((char*)this + 0x34) = a;
    *(float*)((char*)this + 0x38) = b;
}

struct FUN_00633c40_Class
{
    void FUN_00633c40(float value);
};
// @fnv 0x00633c40
void FUN_00633c40_Class::FUN_00633c40(float value)
{
    *(float*)((char*)this + 0x50) = value;
}

struct FUN_00633c60_Class
{
    void* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_aa;
    int m_ab;
    int m_ac;
    int m_ad;
    int m_ae;
    int m_af;
    int m_ag;
    int m_ah;
    int m_ai;
    int m_aj;
    int m_ak;
    int m_al;
    int m_am;
    int m_an;
    int m_ao;
    int m_ap;
    int m_aq;
    int m_ar;
    int m_as;
    int m_at;
    int m_au;
    int m_av;
    int m_aw;
    int m_ax;
    int m_ay;
    int m_az;
    void FUN_00633c60(const NiPoint3& p);
};

// Stores the given NiPoint3 into the object at offset 0x54.
// @fnv 0x00633c60
void FUN_00633c60_Class::FUN_00633c60(const NiPoint3& aPos)
{
    *(NiPoint3*)((char*)this + 0x54) = aPos;
}

struct FUN_006347a0_Class
{
    int m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    int m_aiIndexedValues[0];
    int* FUN_006347a0(int index);
};
// @fnv 0x006347a0
int* FUN_006347a0_Class::FUN_006347a0(int index)
{
    return (int*)((char*)this + 0x34 + index * 0xc);
}

struct FUN_00634850_Class
{
    NiPoint3* GetPointAt(int index);
};

// @fnv 0x00634850
NiPoint3* FUN_00634850_Class::GetPointAt(int index)
{
    return reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x28 + index * 0xc);
}

extern float DAT_011ff8b4[4];

// Adds value to the element at idx in DAT_011ff8b4 when idx is less than 4.
// @fnv 0x006348b0
void AddToFloatArray(unsigned short ausIndex, float value)
{
    if (ausIndex < 4)
        DAT_011ff8b4[ausIndex] += value;
}

extern float DAT_011ae5d0;

// @fnv 0x006377c0
void AddToGlobal(float value)
{
    DAT_011ae5d0 += value;
}

struct FUN_00639a30_Class
{
    int m_auiShapeKeys[43];
    unsigned short m_flags;
    unsigned short GetFlagBits(unsigned short mask, unsigned short shift);
};
// Returns the bits of m_flags selected by mask, shifted right by shift.
// @fnv 0x00639a30
unsigned short FUN_00639a30_Class::GetFlagBits(unsigned short mask, unsigned short shift)
{
    return (m_flags & mask) >> shift;
}

struct FUN_00639b00_Class
{
    int FUN_00639b00();
};
// @fnv 0x00639b00
int FUN_00639b00_Class::FUN_00639b00()
{
    return ((int)(::FUN_009938b0((const unsigned short *)(void *)((char*)this + 0x54))));
}

struct FUN_00639ce0_Class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int FUN_00639ce0();
};

// @fnv 0x00639ce0
int FUN_00639ce0_Class::FUN_00639ce0()
{
    return m_g & 0x7fffffff;
}

struct FUN_0063ef00_Class
{
    bool FUN_0063ef00();
};
// @fnv 0x0063ef00
bool FUN_0063ef00_Class::FUN_0063ef00()
{
    return (*(int*)((char*)this + 0x244) & 0x40) ? true : false;
}

struct FUN_00626630_Class
{
    int a;
    int b;
    int c;
    FUN_00626630_Class* FUN_00626630();
};

// Sets a, b to 0 and c to -1, then returns this.
// @fnv 0x00626630
FUN_00626630_Class* FUN_00626630_Class::FUN_00626630()
{
    a = 0;
    b = 0;
    c = 0xffffffff;
    return this;
}

struct Holder
{
    Holder* FUN_00628950(Holder* a, Holder* b);
};

// Calls FUN_004a3c90 on a for this and on b for the object at this+0x10, then returns this.
// @fnv 0x00628950
Holder* Holder::FUN_00628950(Holder* apFirst, Holder* apSecond)
{
    new ((void *)(this)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(apFirst)));
    new ((void *)((reinterpret_cast<Holder*>(reinterpret_cast<char*>(this) + 0x10)))) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(apSecond)));
    return this;
}

extern int DAT_0104e170;
struct NiTPointerMap_00629eb0
{
    void RemoveAll();
    void* m_data;
};
struct FUN_00629eb0_Class
{
    void FUN_00629eb0();
};
// @fnv 0x00629eb0
void FUN_00629eb0_Class::FUN_00629eb0()
{
    *(int*)this = (int)&DAT_0104e170;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap_00629eb0*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)((char*)this + 8));
}

struct FUN_00631980_Map
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    void RemoveAll();
    void DestroyMap();
};
// Sets the vtable, calls RemoveAll, then frees m_data with NiFreeAlias.
// @fnv 0x00631980
void FUN_00631980_Map::DestroyMap()
{
    m_vtbl = &DAT_0104e510;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(m_data);
}

struct FUN_00620180_Class
{
};
struct FUN_00620130_Class : public BSSimpleList<int*>
{
    void FUN_00620130(BSSimpleList<int*>* pList);
};
struct FUN_00620230_Class
{
    void* FUN_00620230(unsigned int flags);
};
// Calls FUN_0061fc50, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x00620230
void* FUN_00620230_Class::FUN_00620230(unsigned int flags)
{
    reinterpret_cast<::FUN_0061fc50 *>(this)->FUN_0061fc50::~FUN_0061fc50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct AnimIdle
{
};
struct FUN_0057b700_class
{
    void FUN_0057b700(int);
};
struct FUN_006205e0_shell
{
};
struct FUN_006206d0_Class : public FUN_006205e0_shell
{
    void FUN_006206d0(AnimIdle* self, int a2);
};
struct FUN_00620810_List
{
    FUN_00620810_List* FindByFlags(unsigned int);
};
// Walks the list and returns the first node whose GetFlags() equals flags, or null if none matches.
// @fnv 0x00620810
FUN_00620810_List* FUN_00620810_List::FindByFlags(unsigned int flags)
{
    FUN_00620810_List* cur = this;
    while (cur)
    {
        if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(cur)))->GetName())) == flags)
            break;
        cur = reinterpret_cast<FUN_00620810_List*>(((::BSSimpleList<int *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<int*>*>(cur)))->FUN_00726070())));
    }
    return cur;
}

struct Flt
{
    operator unsigned int();
};
struct S_00c85ce0
{
    void FUN_00c85ce0(unsigned int);
};
struct Stand : Flt
{
    void FUN_00620ba0(unsigned int);
};
// Forwards aiGroup to FUN_00c85ce0 on the object obtained from this.
// @fnv 0x00620ba0
void Stand::FUN_00620ba0(unsigned int aiGroup)
{
    ((S_00c85ce0*)(unsigned int)*this)->FUN_00c85ce0(aiGroup);
}

struct FUN_006218f0_Owner
{
    int GetIndexedValue(int a, int b);
};
// Reads a byte from the table at offset 0x1A0 indexed by (a<<5)+b, then returns the int at offset 0x9A8 indexed by that byte.
// @fnv 0x006218f0
int FUN_006218f0_Owner::GetIndexedValue(int a, int b)
{
    int idx = *(unsigned char*)((char*)this + ((a << 5) + b) + 0x1A0);
    return *(int*)((char*)this + idx * 20 + 0x9A8);
}

struct FUN_006815c0_Class
{
    void FUN_006815c0();
};
struct FUN_00621990_Class
{
    FUN_006815c0_Class m_kPointA;
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    FUN_006815c0_Class m_kPointB;
    int m_pad3;
    int m_pad4;
    int m_pad5;
    FUN_006815c0_Class m_iThirdValue;
    FUN_00621990_Class* FUN_00621990();
};
// Calls FUN_006815c0 on the three embedded subobjects and returns this.
// @fnv 0x00621990
FUN_00621990_Class* FUN_00621990_Class::FUN_00621990()
{
    new ((void *)&(m_kPointA)) ::Vec3();
    new ((void *)&(m_kPointB)) ::Vec3();
    new ((void *)&(m_iThirdValue)) ::Vec3();
    return this;
}

struct Date
{
    ~Date();
};
struct V94
{
    virtual void* f00() = 0;
    virtual void* f01() = 0;
    virtual void* f02() = 0;
    virtual void* f03() = 0;
    virtual void* f04() = 0;
    virtual void* f05() = 0;
    virtual void* f06() = 0;
    virtual void* f07() = 0;
    virtual void* f08() = 0;
    virtual void* f09() = 0;
    virtual void* f10() = 0;
    virtual void* f11() = 0;
    virtual void* f12() = 0;
    virtual void* f13() = 0;
    virtual void* f14() = 0;
    virtual void* f15() = 0;
    virtual void* f16() = 0;
    virtual void* f17() = 0;
    virtual void* f18() = 0;
    virtual void* f19() = 0;
    virtual void* f20() = 0;
    virtual void* f21() = 0;
    virtual void* f22() = 0;
    virtual void* f23() = 0;
    virtual void* f24() = 0;
    virtual void* f25() = 0;
    virtual void* f26() = 0;
    virtual void* f27() = 0;
    virtual void* f28() = 0;
    virtual void* f29() = 0;
    virtual void* f30() = 0;
    virtual void* f31() = 0;
    virtual void* f32() = 0;
    virtual void* f33() = 0;
    virtual void* f34() = 0;
    virtual void* f35() = 0;
    virtual void* f36() = 0;
    virtual void* f37() = 0;
};
struct S219c0
{
    void DestroyDate();
};
// Calls virtual f37 to obtain a Date pointer and, if non-null, invokes its destructor.
// @fnv 0x006219c0
void S219c0::DestroyDate()
{
    Date* p;
    p = (Date*)((V94*)this)->f37();
    if (p != 0)
        reinterpret_cast<::TESForm *>((p))->ClearData();
}

struct hkpRigidBody;
struct ScriptLocalsX
{
};
struct ScriptX
{
};
struct hkpShapePhantom
{
    void SetWorldPosition(hkpRigidBody* body, float pos);
};
struct FUN_006219f0_Class
{
    void FUN_006219f0(hkpRigidBody* body);
};
// @fnv 0x006219f0
void FUN_006219f0_Class::FUN_006219f0(hkpRigidBody* body)
{
    ScriptX* flag = (ScriptX*)((void *)(::FUN_004ae750((void *)(((ScriptLocalsX*)this)))));
    if (flag)
    {
        ::FUN_00a29680();
        ((hkpShapePhantom*)flag)->SetWorldPosition(body, 0.0f);
        ::FUN_00a29680();
    }
}

struct FUN_00cac980_Holder
{
};
// Calls GetReferenceFlags on this, and if it returns a holder, calls the holder's FUN_00cac980 and returns the result, otherwise returns 0.
// @fnv 0x00621a90
void* ObjHelper::FUN_00621a90()
{
    FUN_00cac980_Holder* p = (FUN_00cac980_Holder*)((int)(reinterpret_cast<::FUN_00620b80_shell *>((this))->GetReferenceFlags()));
    return p ? reinterpret_cast<::FUN_00cac980_class *>((p))->FUN_00cac980() : 0;
}

namespace fnv_00621b60 {
struct Date
{
    ~Date();
};
struct FUN_00621b60_Class : public Date
{
    void FUN_00621c60();
    void FUN_00621b60();
    ~FUN_00621b60_Class();
};
// @fnv 0x00621b60
FUN_00621b60_Class::~FUN_00621b60_Class()
{
    FUN_00621c60();
}
}  // namespace fnv_00621b60

struct H_A100
{
};
struct FUN_00621ce0_Class
{
    int m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_auiShapeKeys;
};
struct FUN_00621c90_Class
{
    int m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_auiShapeKeys;
    void FUN_00626870();
    void FUN_00621c90(int arg);
};
struct S_621ce0
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4(int, int)
    {}
    void FUN_00621ce0(int, int);
};
// @fnv 0x00621c90
void FUN_00621c90_Class::FUN_00621c90(int arg)
{
    FUN_00626870();
    if (!(m_kPointB & 0x80000000))
    {
        reinterpret_cast<::S_621ce0 *>((((FUN_00621ce0_Class*)arg)))->FUN_00621ce0(m_vtbl, (int)(((void *)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>((((H_A100*)this)))->GetSizeMasked()))));
    }
    m_vtbl = 0;
    m_kPointB = 0x80000000;
}
// Calls the virtual f4 with arg1 and arg2 multiplied by 0x70.
// @fnv 0x00621ce0
void S_621ce0::FUN_00621ce0(int arg1, int arg2)
{
    int dummy = 0x70;
    f4(arg1, arg2 * 0x70);
}

struct FUN_00622730_S
{
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_C;
    void FUN_00622730(float);
};
// @fnv 0x00622730
void FUN_00622730_S::FUN_00622730(float f)
{
    FUN_004169a0((float)(f * DAT_01011588), m_iWordAt04, m_iWordAt00);
    m_C = 0.0f;
    m_8 = 0.0f;
}

struct FUN_00622870_Holder
{
};
struct FUN_006227e0_Holder
{
    const char* m_p;
    FUN_006227e0_Holder* FUN_006227e0(unsigned int a, unsigned int b);
};
struct FUN_00622780
{
    void Clear();
};
struct FUN_00622810_Class : public FUN_00622780
{
    void* FUN_00622810(unsigned int flags);
};
// Calls Clear(), then deletes this if the flags bit 0 is set, and returns this.
// @fnv 0x00622810
void* FUN_00622810_Class::FUN_00622810(unsigned int flags)
{
    reinterpret_cast<::FUN_00622780_Class *>(this)->FUN_00622780();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00621e40Class
{
    void FUN_00621e40();
    FUN_00621e40Class* FUN_00622840(unsigned int flags);
};
// Calls FUN_00621e40, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00622840
FUN_00621e40Class* FUN_00621e40Class::FUN_00622840(unsigned int flags)
{
    FUN_00621e40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00622f20 {
struct ScriptLocalsX
{
};
struct ScriptX
{
};
struct FUN_00622f20_Class
{
    void FUN_00622f20(const char* s);
};
// @fnv 0x00622f20
void FUN_00622f20_Class::FUN_00622f20(const char* s)
{
    void* flag = ((void *)(::FUN_004ae750((void *)(((ScriptLocalsX*)this)))));
    if (flag)
    {
        ::FUN_00a29680();
        ((FUN_00622f60_Class*)flag)->SetString(s);
        ::FUN_00a29680();
    }
}
}  // namespace fnv_00622f20

namespace fnv_00623150 {
struct ScriptLocalsX
{
};
struct ScriptX
{
};
struct FUN_00623150_Class
{
    void FUN_00623150(void* arg);
};
// @fnv 0x00623150
void FUN_00623150_Class::FUN_00623150(void* arg)
{
    void* result = ((void *)(::FUN_004ae750((void *)(((ScriptLocalsX*)this)))));
    if (result && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)result)))->GetName())))
    {
        ::FUN_00a29680();
        ((void(*)(void*, int, int)) * (int**)(*(int**)result + 0x44 / 4))(result, (int)arg, 0);
        ::FUN_00a29680();
    }
}
}  // namespace fnv_00623150

namespace fnv_00623310 {
struct Flt
{
    operator unsigned int();
};
struct FUN_00623310_Class
{
    void FUN_00623310(float);
};
// @fnv 0x00623310
void FUN_00623310_Class::FUN_00623310(float scale)
{
    if (reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x3a0)->operator unsigned int())
    {
        FUN_00621b20_Class* dst = reinterpret_cast<FUN_00621b20_Class*>(((void *)(::GetStringCStr((::Dummy_004ae6c0 *)(void *)(reinterpret_cast<void*>(
            reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x3a0)->operator unsigned int()))))));
        if (dst)
            dst->FUN_00621b20(::FUN_004a3e90(scale));
    }
}
}  // namespace fnv_00623310

struct H0043b4d0
{
};
struct C00624070
{
    bool FUN_00624070();
};
// @fnv 0x00624070
bool C00624070::FUN_00624070()
{
    int el = reinterpret_cast<::FUN_0043b4d0_shell *>((((H0043b4d0*)this)))->FUN_0043b4d0();
    return el == 8 || el == 0x1d;
}

extern int DAT_0104dde4;
extern int DAT_0104de00;
struct FUN_006c0210_shell
{
};
struct FUN_006241c0_shell
{
public:
    FUN_006241c0_shell();
};
struct FUN_00624150_Class
{
    int m_vtbl;
    int m_kPointA;
    FUN_00624150_Class();
};
// @fnv 0x00624150
FUN_00624150_Class::FUN_00624150_Class()
{
    new ((void *)(((FUN_006241c0_shell*)this))) ::FUN_006241c0_shell();
    reinterpret_cast<::FUN_0061f580_shell *>((((FUN_006c0210_shell*)&this->m_kPointA)))->FUN_0061f580();
    m_vtbl = (int)&DAT_0104de00;
    m_kPointA = (int)&DAT_0104dde4;
}

// Copies two consecutive ints from src into dst using a do-while loop.
// @fnv 0x006267c0
void CopyTwoInts(int* dst, int* src)
{
    unsigned int i = 0;
    do
    {
        dst[i] = src[i];
        i++;
    } while (i < 2);
}

namespace fnv_00626cb0 {
struct Flt
{
    operator unsigned int();
};
struct FUN_004ae700_S
{
};
struct FUN_00626cb0_Class
{
    int* m_vtbl;
    void FUN_00626cb0(Flt filter);
};
// @fnv 0x00626cb0
void FUN_00626cb0_Class::FUN_00626cb0(Flt filter)
{
    FUN_00626d00_Class* obj = ((::FUN_00626d00_Class *)(reinterpret_cast<::FUN_004ae700_S *>((reinterpret_cast<FUN_004ae700_S*>(this)))->FUN_004ae700()));
    if (obj)
        obj->SetObjectFlags(static_cast<unsigned int>(filter));
    reinterpret_cast<void(*)(void*)>(m_vtbl[0xc4 / 4])(this);
}
}  // namespace fnv_00626cb0

struct ShadowLightData
{
    static void __cdecl SetTargetMaskForSelection(unsigned int, unsigned __int64);
};
struct FUN_00626da0_Class
{
    void FUN_00626da0();
};
// @fnv 0x00626da0
void FUN_00626da0_Class::FUN_00626da0()
{
    unsigned __int64 v = 0x6016777e;
    ShadowLightData::SetTargetMaskForSelection(0x27, v);
}

void __cdecl CallWithParam(int);
struct FUN_00626fa0_Class
{
    void FUN_00626930();
    FUN_00626fa0_Class* FUN_00626fa0(unsigned int flags);
};
struct S6281a0
{
    S6281a0& FUN_006281a0(const S6281a0& other);
};
// @fnv 0x006281a0
S6281a0& S6281a0::FUN_006281a0(const S6281a0& other)
{
    reinterpret_cast<::AlignedVector *>((((T_*)this)))->FUN_004a3f10((*(const ::AlignedVector *)((void*)&other)));
    reinterpret_cast<::AlignedVector *>((((T_*)((char*)this + 0x10))))->FUN_004a3f10((*(const ::AlignedVector *)((void*)((char*)&other + 0x10))));
    return *this;
}

struct FUN_006286a0_Holder
{
    int* m_vtbl;
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void Target(int a, float b, int c);
    void ForwardToTarget(int a, float b, int c);
};
// Calls the virtual Target method on this object, forwarding the three arguments unchanged.
// @fnv 0x006286a0
void FUN_006286a0_Holder::ForwardToTarget(int aiArg, float afArg, int aiArg2)
{
    Target(aiArg, afArg, aiArg2);
}

struct S285e0
{
};
struct S28640
{
};
struct FUN_00629560_Class
{
    char _pad[16];
    void FUN_00629560(int arg);
};
// Forwards arg to FUN_006285e0 on this and to FUN_00628640 on the object at this+0x10.
// @fnv 0x00629560
void FUN_00629560_Class::FUN_00629560(int aiValue)
{
    reinterpret_cast<::VecHolder *>((((S285e0*)this)))->FUN_006285e0(this, (const void *)(aiValue));
    reinterpret_cast<::S00628640_Vector *>((((S28640*)((char*)this + 0x10))))->FUN_00628640((const ::S00628640_Source *)(void *)((void*)((char*)this + 0x10)), (const ::S00628640_Source *)(aiValue));
}

struct FUN_00629670_Class : public FUN_006296b0_Class
{
    void FUN_00629670(unsigned int flags, bool tf);
};
// @fnv 0x00629650
void FUN_00629650_Class::FUN_00629650(bool flag)
{
    reinterpret_cast<::FUN_00629670_Class *>((((Dummy629670*)this)))->FUN_00629670(0x20, flag);
}
// @fnv 0x00629670
void FUN_00629670_Class::FUN_00629670(unsigned int flags, bool tf)
{
    if (tf)
        m_flags |= flags;
    else
        FUN_006296b0(flags);
}

struct Unk629a50
{
    void* FUN_00629a50(unsigned int flags);
};
struct FUN_00629e50_Holder
{
};
namespace fnv_00629b40 {
struct Date
{
    void FUN_0062a080();
    ~Date();
};
struct FUN_00629b40 : public Date
{
    ~FUN_00629b40();
};
// @fnv 0x00629b40
FUN_00629b40::~FUN_00629b40()
{
    FUN_0062a080();
}
}  // namespace fnv_00629b40

extern int DAT_0104e170;
// Sets the vtable, stores count at offset 4, allocates count*4 bytes at offset 8, zeroes them, and clears offset 0xc.
// @fnv 0x00629ba0
void* FUN_00629ba0_Class::InitArray(int count)
{
    m_vtbl = &DAT_0104e170;
    *(int*)((char*)this + 4) = count;
    *(int*)((char*)this + 0xc) = 0;
    unsigned int size = *(int*)((char*)this + 4) << 2;
    *(void**)((char*)this + 8) = ::FUN_00aa1070(size);
    memset(*(void**)((char*)this + 8), 0, *(int*)((char*)this + 4) << 2);
    return this;
}

struct FUN_00629f10_Class
{
    int m_vtbl;
    int m_uiItemCount;
    int FUN_00629f10(int* p, int start, int count);
};

// @fnv 0x00629f10
int FUN_00629f10_Class::FUN_00629f10(int* pValue, int start, int count)
{
    if (count < 0)
        count = m_uiItemCount;
    int i = start;
    for (; i < count; ++i)
        if (((int*)m_vtbl)[i] == *pValue)
            return i;
    return -1;
}

namespace fnv_00629f70 {
struct H_A100
{
};
struct FUN_00629f70_Class
{
    void FUN_00629f70(int a, int c);
};
// @fnv 0x00629f70
void FUN_00629f70_Class::FUN_00629f70(int a, int c)
{
    int d = (int)((void *)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>((((H_A100*)this)))->GetSizeMasked()));
    if (d < c)
    {
        int e = d << 1;
        int f = c < e ? e : c;
        ::FUN_00c908c0((::SpawnedObject *)(a), (::SpawnedArray *)((int)this), f, 4);
    }
}
}  // namespace fnv_00629f70

struct FUN_0062a050_Struct
{
    void* FUN_0062a050(unsigned int flags);
};
// @fnv 0x0062a050
void* FUN_0062a050_Struct::FUN_0062a050(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->FUN_0062a000();
    if (flags & 1)
        ::FUN_00401030((void*)this);
    return (void*)this;
}

struct FUN_0062a160_Class
{
    void CallVirtualWithScaledArg(int a, int b);
};
// Calls the virtual method at vtable slot 4 on this, passing a and b multiplied by 4.
// @fnv 0x0062a160
void FUN_0062a160_Class::CallVirtualWithScaledArg(int a, int b)
{
    int local = 4;
    ((void(*)(void*, int, int))(*reinterpret_cast<void***>(this))[4])(this, a, b * 4);
}

// @fnv 0x0062a430
void __cdecl SetSelectedTargetMask(int aiIndex, unsigned __int64 aullMask)
{
    if (aiIndex >= 0x23)
    {
        selected_target_masks[aiIndex] = aullMask;
    }
}

namespace fnv_0062a4b0 {
struct FUN_005545b0
{
};
struct FUN_0062a4b0_Class : public FUN_005545b0
{
    void* FUN_0062a4b0(unsigned int flags);
};
// Calls FUN_005545d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062a4b0
void* FUN_0062a4b0_Class::FUN_0062a4b0(unsigned int flags)
{
    reinterpret_cast<::FUN_005545d0_Class *>(this)->FUN_005545d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0062a4b0

namespace fnv_0062a4e0 {
struct FUN_005545b0
{
    void* FUN_0062a4e0(unsigned int flags);
};
// Calls Call(), then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062a4e0
void* FUN_005545b0::FUN_0062a4e0(unsigned int flags)
{
    reinterpret_cast<::FUN_005545b0 *>(this)->Call();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0062a4e0

struct hkRotation
{
    char d[48];
    hkRotation();
};
struct FUN_008cd6a0_Class
{
};
struct FUN_0062aae0 : public hkRotation
{
    Holder m_h;
    FUN_0062aae0(void* a, Holder* b);
};
// @fnv 0x0062aae0
FUN_0062aae0::FUN_0062aae0(void* apArg, Holder* apHolder)
{
    new ((void *)&(m_h)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(apHolder)));
    reinterpret_cast<::RotationRows *>((((FUN_008cd6a0_Class*)this)))->FUN_00cb2d90(apArg);
}

extern int DAT_0104e38c;
extern int DAT_0104e3a4;

struct FUN_0062d6f0_shell
{
    void* FUN_0062d6f0();
};

struct FUN_0062d680_Class
{
    int* m_vtbl;
    int m_auiShapeKeys;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    void* FUN_0062d6f0();
    void* FUN_0062d680();
};

// @fnv 0x0062d680
void* FUN_0062d680_Class::FUN_0062d680()
{
    new ((void *)(((FUN_0062a480_Class*)this))) ::FUN_0061f4d0((void *)(0));
    ((FUN_0062d6f0_shell*)&this->m_iFourthElementInteger)->FUN_0062d6f0();
    m_vtbl = (int*)&DAT_0104e3a4;
    this->m_iFourthElementInteger = (int)&DAT_0104e38c;
    return this;
}

struct FUN_0062d9e0_shell
{
    void CallMemberAtOffset();
};
struct FUN_0062d9b0_Class : public FUN_0062d9e0_shell
{
    FUN_0062d9e0_shell* FUN_0062d9b0(unsigned int flags);
};
// @fnv 0x0062d9b0
FUN_0062d9e0_shell* FUN_0062d9b0_Class::FUN_0062d9b0(unsigned int flags)
{
    this->CallMemberAtOffset();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0062e780_Class
{
    char m_auiShapeKeys[0x40];
    FUN_0062e780_Class();
};

// Returns the global instance, allocating a new one first if it is null.
// @fnv 0x0062f3d0
FUN_0062e780_Class* __cdecl FUN_0062f3d0()
{
    if (!(*reinterpret_cast<::FUN_0062e780_Class * *>(&::DAT_011cc54c)))
        (*reinterpret_cast<::FUN_0062e780_Class * *>(&::DAT_011cc54c)) = new FUN_0062e780_Class;
    return (*reinterpret_cast<::FUN_0062e780_Class * *>(&::DAT_011cc54c));
}

struct FUN_006317c0_Class
{
    void* FUN_006317c0(unsigned int flags);
};
// Calls FUN_00631780, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006317c0
void* FUN_006317c0_Class::FUN_006317c0(unsigned int flags)
{
    reinterpret_cast<::fnv_00631780::FUN_00631780_Class *>(this)->FUN_00631780();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_0104e4f0;
struct FUN_00631850_Class : FUN_006318b0_Class
{
    FUN_00631850_Class* FUN_00631850(int);
};
// Calls the base constructor with count, installs DAT_0104e4f0 as the vtable pointer, and returns this.
// @fnv 0x00631850
FUN_00631850_Class* FUN_00631850_Class::FUN_00631850(int count)
{
    FUN_006318b0(count);
    *(int*)this = (int)&DAT_0104e4f0;
    return this;
}

struct S_6319b0
{
    void* FUN_006319b0(unsigned int);
};
// Calls DestroyMap on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006319b0
void* S_6319b0::FUN_006319b0(unsigned int flags)
{
    ((FUN_00631980_Map*)this)->DestroyMap();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GO
{
    void* m_p;
    GO(int);
    void operator=(void*);
    ~GO();
};
struct FUN_006319e0_Class
{
    GO m_kPointA;
    char m_kPointB;
    int m_iThirdValue;
    FUN_006319e0_Class();
};
// Initializes the object's pointer to null, its byte to 0 and its int to 0.
// @fnv 0x006319e0
FUN_006319e0_Class::FUN_006319e0_Class() : m_kPointA(0)
{
    m_kPointA = 0;
    m_kPointB = 0;
    m_iThirdValue = 0;
}

struct FUN_00632c30_Class
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8(void* a, void* b, void* c)
    {}
    void* ForwardToV8(void* a, void* b, void* c);
};
// Calls the virtual method v8 with the three arguments and returns the first argument.
// @fnv 0x00632c30
void* FUN_00632c30_Class::ForwardToV8(void* pFirst, void* pSecond, void* pThird)
{
    v8(pFirst, pSecond, pThird);
    return pFirst;
}

struct CalleeObj
{
};
struct FUN_00632c60_Class
{
    int m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    float m_iFourthElementInteger;
    CalleeObj* FUN_00632c60(CalleeObj* p);
};
// @fnv 0x00632c60
CalleeObj* FUN_00632c60_Class::FUN_00632c60(CalleeObj* apCallee)
{
    reinterpret_cast<::FUN_00622570_Class *>((apCallee))->FUN_00622570(m_iFourthElementInteger < 1.0);
    return apCallee;
}

struct M16815
{
    char pad[16];
    void FUN_006815c0();
};
struct S632
{
    M16815 m_kPointA;
    M16815 m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    S632* FUN_00632ca0();
};
// Calls FUN_006815c0 on both embedded members, zeroes the two int fields, and returns this.
// @fnv 0x00632ca0
S632* S632::FUN_00632ca0()
{
    new ((void *)&(m_kPointA)) ::Vec3();
    new ((void *)&(m_kPointB)) ::Vec3();
    m_iThirdValue = 0;
    m_iFourthElementInteger = 0;
    return this;
}

struct FUN_00632dc0_Host
{
    int _pad[8];
    FUN_00632dc0_Host* CopyFrom(FUN_00632dc0_Host* o);
};
// @fnv 0x00632dc0
FUN_00632dc0_Host* FUN_00632dc0_Host::CopyFrom(FUN_00632dc0_Host* apOther)
{
    new ((void *)(((Holder*)this))) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)((Holder*)apOther)));
    new ((void *)(((Holder*)((char*)this + 0x10)))) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)((Holder*)((char*)apOther + 0x10))));
    return this;
}

namespace fnv_00632df0 {
struct ShadowLightData
{
    void CallWithConstant();
};
// @fnv 0x00632df0
void ShadowLightData::CallWithConstant()
{
    unsigned __int64 v = 0x700eef7e;
    ::ShadowLightData::SetTargetMaskForSelection(0x28, v);
}
}  // namespace fnv_00632df0

struct FUN_00633ba0_Class
{
    void FUN_00633ba0(bool set, unsigned short mask);
};
// @fnv 0x00633ba0
void FUN_00633ba0_Class::FUN_00633ba0(bool set, unsigned short mask)
{
    if (set)
        *(unsigned short*)((char*)this + 0x18) |= mask;
    else
        *(unsigned short*)((char*)this + 0x18) &= ~mask;
}

namespace fnv_00633d90 {
struct GO
{
    void* operator=(void*);
};
struct FUN_00633d90_Class
{
    int m_auiShapeKeys;
    GO m_kPointA;
    GO m_kPointB;
    GO m_iThirdValue;
    GO m_iFourthElementInteger;
    void FUN_00633d90();
};
// @fnv 0x00633d90
void FUN_00633d90_Class::FUN_00633d90()
{
    for (int i = 0; i < 4; ++i)
    {
        ((GO*)((char*)this + 8 + i * 4))->operator=(0);
    }
}
}  // namespace fnv_00633d90


// @fnv 0x00639730
void __cdecl FUN_00639730(float scale, float* apfOutA, float* apfOutB)
{
    int index = (int)((512.0 / runtimeInitializationFloat2715) * scale) & 0x1ff;
    *apfOutA = DAT_011f52e0[index];
    *apfOutB = DAT_011f4ae0[index];
}

double DAT_01029790;
// Calls _FUN_006397b0, scales the result by 2.0/DAT_01029790 and subtracts 1.0, returning the float.
// @fnv 0x006397c0
float FUN_006397c0()
{
    float f;
    int v;
    v = ::FUN_006397b0();
    f = (float)(2.0 * v / DAT_01029790 + -1.0);
    return f;
}

struct SetHelper
{
};
struct FUN_006397f0_Obj
{
    void SetFromFloats(float, float, float);
};
// Builds a NiPoint3 from the three float arguments and stores it into this object.
// @fnv 0x006397f0
void FUN_006397f0_Obj::SetFromFloats(float afX, float afY, float afZ)
{
    NiPoint3 tmp;
    *(NiPoint3*)this = *((::NiPoint3 *)(reinterpret_cast<::FUN_00416870_t *>((((SetHelper*)&tmp)))->FUN_00416870(afX, afY, afZ)));
}

struct FUN_006399a0_Class
{
    void SetFlagsFromValue(int);
};
struct FUN_00639940_Class
{
    char m_g;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    FUN_00639940_Class* FUN_00639940();
};
// Clears the five int fields, m_f and m_g, calls SetFlagsFromValue(0), and returns this.
// @fnv 0x00639940
FUN_00639940_Class* FUN_00639940_Class::FUN_00639940()
{
    m_kPointA = 0;
    m_kPointB = 0;
    m_iThirdValue = 0;
    m_iFourthElementInteger = 0;
    m_usTrailingValue = 0;
    m_f = 0;
    m_g = 0;
    ((FUN_006399a0_Class*)this)->SetFlagsFromValue(0);
    return this;
}

namespace fnv_006399a0 {
struct FUN_006399a0_Class
{
    unsigned char m_flags;
    unsigned char FUN_006399e0(int);
    void SetFlagsFromValue(int);
};
// Calls FUN_006399e0 with a, then stores the returned byte into m_flags with bits 1 and 2 cleared and the result OR-ed in.
// @fnv 0x006399a0
void FUN_006399a0_Class::SetFlagsFromValue(int aiValue)
{
    unsigned char r = FUN_006399e0(aiValue);
    m_flags = (m_flags & 0xfffffff9) | r;
}
}  // namespace fnv_006399a0

struct FUN_006399e0_Class
{
    char FUN_006399e0(int value);
};

// @fnv 0x006399e0
char FUN_006399e0_Class::FUN_006399e0(int value)
{
    switch (value)
    {
    case 0:
        return 2;
    case 0x4000:
        return 3;
    default:
        return 3;
    }
}

namespace fnv_00639a60 {
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
struct Flt
{
    operator unsigned int();
};
struct C639a60
{
    unsigned int GetElementAt(unsigned int);
};
// Returns the element at index from the array at offset 0x18 if index is in range, otherwise returns 0.
// @fnv 0x00639a60
unsigned int C639a60::GetElementAt(unsigned int index)
{
    if (index < reinterpret_cast<::FUN_00658930_class *>((((Arr*)((char*)this + 0x18))))->GetShortAtOffsetA())
        return *(Flt*)((Arr*)((char*)this + 0x18))->GetAt(index);
    return 0;
}
}  // namespace fnv_00639a60

namespace fnv_00639ac0 {
struct Flt
{
    operator unsigned int();
};
struct Arr
{
    Flt* GetAt(int);
};
struct FUN_00639ac0_Class
{
    unsigned int GetAtChecked(unsigned int);
};
// Returns the element at index from the array at offset 0x54 if index is within the count, otherwise returns 0.
// @fnv 0x00639ac0
unsigned int FUN_00639ac0_Class::GetAtChecked(unsigned int index)
{
    if (index < (unsigned int)((FUN_00639b00_Class*)this)->FUN_00639b00())
    {
        return (unsigned int)*((Arr*)((char*)this + 0x54))->GetAt(index);
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00639ac0

struct FUN_00639d00_Class
{
    int m_vtbl;
    int m_auiShapeKeys;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    unsigned int m_flags;
    void FUN_00639d00(unsigned int flags);
};

// Clears the low 31 bits of m_flags and stores the low 31 bits of flags, preserving the sign bit.
// @fnv 0x00639d00
void FUN_00639d00_Class::FUN_00639d00(unsigned int flags)
{
    m_flags &= 0x80000000;
    m_flags |= flags & 0x7fffffff;
}


struct FUN_00622870_Class
{
    int* m_vtbl;
    char** m_data;
    unsigned short m_uiItemCount;
    unsigned short m_auiShapeKeys;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    FUN_00622870_Class* FUN_00622870(unsigned short count, unsigned short a);
};
// Calls FUN_00622870 with the two arguments, then stores the string "@(b" at the start of this object and returns this.
// @fnv 0x006227e0
FUN_006227e0_Holder* FUN_006227e0_Holder::FUN_006227e0(unsigned int a, unsigned int b)
{
    reinterpret_cast<::FUN_00622870_Class *>((((FUN_00622870_Holder*)this)))->FUN_00622870(a, b);
    *(const char**)this = "@(b";
    return this;
}

// @fnv 0x00622870
FUN_00622870_Class* FUN_00622870_Class::FUN_00622870(unsigned short count, unsigned short a)
{
    m_vtbl = &DAT_0104dc94;
    m_uiItemCount = count;
    m_kPointB = a;
    m_auiShapeKeys = 0;
    m_kPointA = 0;
    if (m_uiItemCount > 0)
        m_data = FUN_005e0ba0(m_uiItemCount);
    else
        m_data = 0;
    return this;
}

struct FUN_00624d70_Class
{
    void ExtractTes4Prefix(char* path);
};
// Searches path for "TES4" or "tes4" and, if found, copies the text before it into the buffer at this+0x20 and null-terminates it.
// @fnv 0x00624d70
void FUN_00624d70_Class::ExtractTes4Prefix(char* path)
{
    char* found = std::strstr(path, "TES4");
    if (!found)
        found = std::strstr(path, "tes4");
    if (found)
    {
        unsigned int prefixLength = found - path;
        FUN_004add50((char*)this + 0x20, path, prefixLength);
        ((char*)this + 0x20)[prefixLength] = 0;
    }
}

struct NiTexture;
struct SkyShaderProperty
{
    void SetTexture(NiTexture*);
};
struct FUN_00634900_shell
{
    void FUN_00634900(void*);
};
struct Clouds
{
};
struct PropHelper
{
};
// @fnv 0x006349e0
void FUN_006349e0(void* self)
{
    int i = 0;
    for (; i < ((int)(reinterpret_cast<::FUN_00634830_cls *>((((Clouds*)self)))->GetOffset58())); ++i)
    {
        if (((Flt*)((char*)self + 8 + i * 4))->operator unsigned int())
        {
            void* prop = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((Flt*)((char*)self + 8 + i * 4))->operator unsigned int())))->FUN_00a59d30(3)));
            void* obj = ((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const char *const *>(&::g_012005b8))), (::NiObject *)(prop))));
            if (obj)
            {
                ((SkyShaderProperty*)obj)->SetTexture(0);
                ((FUN_00634900_shell*)obj)->FUN_00634900(&(*reinterpret_cast<int *>(&::DAT_011f49e0)));
            }
        }
    }
}

namespace fnv_006369a0 {
struct NiTexture;
struct SkyShaderProperty
{
    void SetTexture(NiTexture*);
};
struct FUN_00634900_shell
{
};

struct PropHelper
{
};
struct FUN_006369a0_Class
{
    void FUN_006369a0();
};
// For the property at this+0x10 and this+0x14, gets property 3, casts it to a sky shader property, clears its texture and calls FUN_00634900 with DAT_011f49e0.
// @fnv 0x006369a0
void FUN_006369a0_Class::FUN_006369a0()
{
    void* p2;
    SkyShaderProperty* s;
    p2 = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((Flt*)((char*)this + 0x10))->operator unsigned int())))->FUN_00a59d30(3)));
    s = (SkyShaderProperty*)((::fnv_006369a0::SkyShaderProperty *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const char *const *>(&::g_012005b8))), (::NiObject *)(p2))));
    if (s)
    {
        s->SetTexture(0);
        reinterpret_cast<::FUN_00634900_shell *>((((FUN_00634900_shell*)s)))->FUN_00634900(&(*reinterpret_cast<int *>(&::DAT_011f49e0)));
    }
    p2 = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((Flt*)((char*)this + 0x14))->operator unsigned int())))->FUN_00a59d30(3)));
    s = (SkyShaderProperty*)((::fnv_006369a0::SkyShaderProperty *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const char *const *>(&::g_012005b8))), (::NiObject *)(p2))));
    if (s)
    {
        s->SetTexture(0);
        reinterpret_cast<::FUN_00634900_shell *>((((FUN_00634900_shell*)s)))->FUN_00634900(&(*reinterpret_cast<int *>(&::DAT_011f49e0)));
    }
}
}  // namespace fnv_006369a0

struct AnimIdle;
struct FUN_00620300_Class
{
};

struct FUN_00620680_Class
{
    int m_auiShapeKeys;
    FUN_00620300_Class* m_kNode;
    AnimIdle* FUN_00620680(int key, int pad);
};

struct FUN_00620850 : public GO
{
    GO m_kPointA;
    FUN_00620850(float, int);
};
// @fnv 0x00620850
FUN_00620850::FUN_00620850(float afValue, int aiValue) : GO(0), m_kPointA(0)
{
    reinterpret_cast<::CollisionPair *>(this)->FUN_00620930(afValue, aiValue);
}

struct FUN_00626800_Pair
{
    int a;
    int b;
};
// For each of count elements, placement-constructs an 8-byte pair at base + i*8 by copying the pair from src.
// @fnv 0x00626800
void __cdecl CopyPairsIntoPlacement(int base, int count, int* src)
{
    for (int i = 0; i < count; i++)
    {
        FUN_00626800_Pair* p = (FUN_00626800_Pair*)::FUN_006e6da0(8, (void*)(base + i * 8));
        FUN_00626800_Pair* q;
        if (p)
        {
            *p = *reinterpret_cast<FUN_00626800_Pair*>(src);
            q = p;
        }
        else
        {
            q = 0;
        }
    }
}

struct FUN_00540b70_Class
{
};

struct FUN_0062a0b0_Class
{
    int m_vtbl;
    int m_auiShapeKeys;
    int m_flags;
    void FUN_0062a0b0(int arg);
};
extern double DAT_010231e8;
struct FUN_006347c0_Class
{
    float InterpolateByIndex(int a, float b, float c);
};
// @fnv 0x006347c0
float FUN_006347c0_Class::InterpolateByIndex(int aiIndex, float b, float c)
{
    unsigned char v = 0x33;
    if (*(int*)((char*)this + 0x368) > 0)
    {
        if (aiIndex >= *(int*)((char*)this + 0x368))
            aiIndex = 0;
        v = ((char*)this)[aiIndex + 0x64];
    }
    return (float)v * DAT_010231e8 * (b - c) + c;
}

struct FUN_0056df00_class
{
};

struct FUN_00621930_Class
{
    void* FUN_00621930(void);
};

// Calls GetItem on six BSSimpleList members at offsets 0x0-0x14, invokes FUN_00621990 on the object at 0x20, and returns this.
// @fnv 0x00621930
void* FUN_00621930_Class::FUN_00621930(void)
{
    new ((void *)(((BSSimpleList<int*>*)this))) ::Vec3();
    new ((void *)(((BSSimpleList<int*>*)((char*)this + 4)))) ::Vec3();
    new ((void *)(((BSSimpleList<int*>*)((char*)this + 8)))) ::Vec3();
    new ((void *)(((BSSimpleList<int*>*)((char*)this + 0xc)))) ::Vec3();
    new ((void *)(((BSSimpleList<int*>*)((char*)this + 0x10)))) ::Vec3();
    new ((void *)(((BSSimpleList<int*>*)((char*)this + 0x14)))) ::Vec3();
    reinterpret_cast<::FUN_00621990_Class *>((((FUN_0056df00_class*)((char*)this + 0x20))))->FUN_00621990();
    return this;
}

extern int DAT_0104dea4;
struct FUN_00624e00_Class
{
    int* m_vtbl;
    FUN_00624e00_Class* FUN_00624e00();
};
struct FUN_00624de0_Class : FUN_00624e00_Class
{
    FUN_00624de0_Class* FUN_00624de0();
};
extern int DAT_0104e228;
struct FUN_0062a460_Class : FUN_0062a480_Class
{
    FUN_0062a460_Class();
};
// @fnv 0x0062a460
FUN_0062a460_Class::FUN_0062a460_Class()
{
    FUN_0062a480_Class::FUN_0062a480();
    m_vtbl = (int*)&DAT_0104e228;
}

extern void* DAT_011cc694;

struct FUN_00632ec0
{
    unsigned char m_data[0x114];
    FUN_00632ec0();
};

FUN_00632ec0::FUN_00632ec0()
{}

// Allocates a FUN_00632ec0 instance and stores it in DAT_011cc694 if that global is currently null.
// @fnv 0x00632e30
void FUN_00632e30()
{
    if (!DAT_011cc694)
        DAT_011cc694 = new FUN_00632ec0;
}

// @fnv 0x006397b0
int FUN_006397b0()
{
    return std::rand();
}

struct Base0_620
{
    int unk00;
};
struct Base1_620
{
    int unk00;
};
struct Derived_620 : Base0_620, Base1_620
{
};

struct List_620
{
};

struct FUN_00620300_cls
{
    int unk00;
    List_620 m_kNode;
    Derived_620* FindDerivedByKey(void* key);
};
// @fnv 0x00620680
AnimIdle* FUN_00620680_Class::FUN_00620680(int key, int pad)
{
    if (m_kNode)
    {
        AnimIdle* idle = ((::AnimIdle *)(reinterpret_cast<::FUN_00620300_cls *>((m_kNode))->FindDerivedByKey((void *)(key))));
        if (idle)
        {
            reinterpret_cast<FUN_006206d0_Class*>(this)->FUN_006206d0(idle, pad);
            return idle;
        }
    }
    return 0;
}

// Looks up key in the list and returns the matching entry cast to Derived_620.
// @fnv 0x00620300
Derived_620* FUN_00620300_cls::FindDerivedByKey(void* key)
{
    return static_cast<Derived_620*>(((::Base1_620 *)(reinterpret_cast<::FUN_00620810_List *>(&(m_kNode))->FindByFlags((unsigned int)(key)))));
}

void FUN_00401050(void* p, unsigned int size, unsigned int count, void(* ctor)(void*));

struct ArrElem70
{
    ArrElem70()
    {}
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
};

struct ArrBase16
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    ArrBase16(void* p, int a, int n);
    ~ArrBase16()
    {}
};

class FUN_00621bc0 : public ArrBase16
{
  public:
    ArrElem70 m_10[8];
    FUN_00621bc0(int a1);
};

// Constructs the base with a pointer to the first of 8 ArrElem70 elements, the given argument and a count of 8.
// @fnv 0x00621bc0
FUN_00621bc0::FUN_00621bc0(int a1) : ArrBase16(&m_10[0], a1, 8)
{}

struct FUN_004a4840_class
{
    unsigned char m_uiFilterValue;
    int FUN_004a4840(int arg);
};

struct FUN_00621c60_Class : public FUN_00621c90_Class
{
    void FUN_00621c60();
};

// Builds a local FUN_004a4840_class, calls FUN_004a4840 on it with this, then passes the result to FUN_00621c90.
// @fnv 0x00621c60
void FUN_00621c60_Class::FUN_00621c60()
{
    FUN_004a4840_class local = {};
    this->FUN_00621c90(local.FUN_004a4840((int)this));
}

struct FUN_0045cec0_Class
{
    ~FUN_0045cec0_Class();
};

struct FUN_006211b0_Class
{
    int m_000, m_004, m_008, m_00c;
    int m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c;
    int m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c;
    int m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c;
    int m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c;
    int m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac;
    int m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc;
    int m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec;
    int m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c;
    int m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c;
    int m_130, m_134, m_138, m_13c;
    int m_140, m_144, m_148, m_14c;
    int m_150, m_154, m_158, m_15c;
    int m_160, m_164, m_168, m_16c;
    int m_170, m_174, m_178, m_17c;
    int m_180, m_184, m_188, m_18c;
    int m_190, m_194, m_198, m_19c;
    int m_1a0, m_1a4, m_1a8, m_1ac;
    int m_1b0, m_1b4, m_1b8, m_1bc;
    int m_1c0, m_1c4, m_1c8, m_1cc;
    int m_1d0, m_1d4, m_1d8, m_1dc;
    int m_1e0, m_1e4, m_1e8, m_1ec;
    int m_1f0, m_1f4, m_1f8, m_1fc;
    int m_200, m_204, m_208, m_20c;
    int m_210, m_214, m_218, m_21c;
    int m_220, m_224, m_228, m_22c;
    int m_230, m_234, m_238, m_23c;
    int m_240, m_244, m_248, m_24c;
    int m_250, m_254, m_258, m_25c;
    int m_260, m_264, m_268, m_26c;
    int m_270, m_274, m_278, m_27c;
    int m_280, m_284, m_288, m_28c;
    int m_290, m_294, m_298, m_29c;
    int m_2a0, m_2a4, m_2a8, m_2ac;
    int m_2b0, m_2b4, m_2b8, m_2bc;
    int m_2c0, m_2c4, m_2c8, m_2cc;
    int m_2d0, m_2d4, m_2d8, m_2dc;
    int m_2e0, m_2e4, m_2e8, m_2ec;
    int m_2f0, m_2f4, m_2f8, m_2fc;
    int m_300, m_304, m_308, m_30c;
    int m_310, m_314, m_318, m_31c;
    int m_320, m_324, m_328, m_32c;
    int m_330, m_334, m_338, m_33c;
    int m_340, m_344, m_348, m_34c;
    int m_350, m_354, m_358, m_35c;
    int m_360, m_364, m_368, m_36c;
    int m_370, m_374, m_378, m_37c;
    int m_380, m_384, m_388, m_38c;
    int m_390, m_394, m_398, m_39c;

    ~FUN_006211b0_Class();
};

struct FUN_00622d00_Class : public FUN_006211b0_Class
{
    FUN_0045cec0_Class m_3a0;

    ~FUN_00622d00_Class();
};

FUN_0045cec0_Class::~FUN_0045cec0_Class()
{}

FUN_006211b0_Class::~FUN_006211b0_Class()
{}

// Destructor for the class; destroys the embedded member and the base class.
// @fnv 0x00622d00
FUN_00622d00_Class::~FUN_00622d00_Class()
{}

class NiNode623;

class NiAVObject623
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void unkv08C();
    virtual void unkv090();
    virtual void unkv094();
    virtual void unkv098();
    virtual void SetParentNode(NiNode623* pkNode);
};

class NiNode623
{
  public:
};

template <class T> class NiPointer623
{
  public:
    T* Get() const;

    T* m_pObject;
};


class Owner623
{
  public:
    void FUN_006231a0(NiNode623* pkNode);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    int unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    int unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C;
    int unk260, unk264, unk268, unk26C, unk270, unk274, unk278, unk27C;
    int unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC;
    int unk2C0, unk2C4, unk2C8, unk2CC, unk2D0, unk2D4, unk2D8, unk2DC;
    int unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318, unk31C;
    int unk320, unk324, unk328, unk32C, unk330, unk334, unk338, unk33C;
    int unk340, unk344, unk348, unk34C, unk350, unk354, unk358, unk35C;
    int unk360, unk364, unk368, unk36C, unk370, unk374, unk378, unk37C;
    int unk380, unk384, unk388, unk38C, unk390, unk394, unk398, unk39C;
    NiPointer623<NiAVObject623> m_pReferencedObject;
};

struct IdleAnim
{
    virtual void* v00() = 0;
    virtual void* v01() = 0;
    virtual void* v02() = 0;
    virtual void* v03() = 0;
    virtual void* v04() = 0;
    virtual void* v05() = 0;
    virtual void* v06() = 0;
    virtual void* v07() = 0;
    virtual void* v08() = 0;
    virtual void* v09() = 0;
    virtual void* v10() = 0;
    virtual void* v11() = 0;
    virtual void* v12() = 0;
    virtual void* v13() = 0;
    virtual void* v14() = 0;
    virtual void* v15() = 0;
    virtual void* v16() = 0;
    virtual void* v17() = 0;
    virtual void* v18() = 0;
    virtual void* v19() = 0;
    virtual void* v20() = 0;
    virtual void* v21() = 0;
    virtual void* v22() = 0;
    virtual void* v23() = 0;
    virtual void* v24() = 0;
    virtual void* v25() = 0;
    virtual void* v26() = 0;
    virtual void* v27() = 0;
    virtual void* v28() = 0;
    virtual void* v29() = 0;
    virtual void* v30() = 0;
    virtual void* v31() = 0;
    virtual void* v32() = 0;
    virtual void* v33() = 0;
    virtual void* v34() = 0;
    virtual void* v35() = 0;
    virtual void* v36() = 0;
    virtual void* v37() = 0;
};

struct SubObj
{
};

struct HighProcess;

struct Owner
{
    char m_auiShapeKeys[0x3A0];
    SubObj m_sub;
    TESIdleForm* GetIdleForm();
public:
    void *GetByIndex(unsigned int);
};
// If the stored object exists and the current node differs from pkNode, reparents the stored object to pkNode and attaches a red highlight to it.
// @fnv 0x006231a0
void Owner623::FUN_006231a0(NiNode623* pkNode)
{
    if (((::NiAVObject623 *)(::FUN_00559450((int *)&(m_pReferencedObject)))) && ((::NiNode623 *)(reinterpret_cast<::Owner *>(this)->GetIdleForm())) != pkNode)
    {
        ((::NiAVObject623 *)(::FUN_00559450((int *)&(m_pReferencedObject))))->SetParentNode(pkNode);
        if (pkNode)
            reinterpret_cast<::C68E30Owner *>((pkNode))->FUN_00c68e30((::C68E30Holder *)(::NiAVObject623 *)(((::NiAVObject623 *)(::FUN_00559450((int *)&(m_pReferencedObject))))), ::PackBytesBigEndian(0xff, 0x10, 0x10, 0x19));
    }
}

TESIdleForm* FUN_00621480(HighProcess* process);

// @fnv 0x00623230
TESIdleForm* Owner::GetIdleForm()
{
    TESIdleForm* result = 0;
    if (((::IdleAnim *)(::FUN_00559450((int *)&(m_sub)))) != 0)
    {
        result = FUN_00621480((HighProcess*)((::IdleAnim *)(::FUN_00559450((int *)&(m_sub))))->v37());
    }
    return result;
}

struct Obj
{
    int FUN_006815c0();
};

struct TileSetHelper
{
    Obj* FUN_006232f0(int a1);
    void SetTileSetValues(int a1, int a2, int a3);
};


// Looks up an object by index and stores its two values into the given slots via FUN_00458620.
// @fnv 0x00623370
void TileSetHelper::SetTileSetValues(int aiIndex, int a2, int a3)
{
    Obj* obj = FUN_006232f0(aiIndex);
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(a2)), (*(const ::hkVector4 *)(((int)(new ((void *)(obj)) ::Vec3())))));
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(a3)), (*(const ::hkVector4 *)(::FUN_00460140((int)(obj)))));
}

struct S_006265c0_Q
{
    int FUN_004a4840(void* owner, int a, int b);
};
struct S_006265c0_Tail
{
};
// Calls FUN_004a4840 with this, a and b, then passes its result to FUN_00cb1870 on this.
// @fnv 0x006265c0
void FUN_00626470_Class::CallAndForwardResult(int aiArg1, int aiArg2)
{
    S_006265c0_Q q = {};
    reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>((reinterpret_cast<S_006265c0_Tail*>(this)))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(q.FUN_004a4840(this, aiArg1, aiArg2))), {}, {});
}

struct C626680Element
{
    int unk00;
    int unk04;
};

struct C626680TypeTag
{
};


class C626680Array
{
  public:
    C626680Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void RemoveAt(int index);
};

// Destructs the element at index, decrements the count, and moves the last element into that slot when index is not the last one.
// @fnv 0x00626680
void C626680Array::RemoveAt(int index)
{
    ::NoOpLoop((int)(&m_data[index]), 1);
    m_iElementCount--;
    if (m_iElementCount != index)
        ::CopyTwoInts((int *)(::C626680Element *)(&m_data[index]), (int *)(::C626680Element *)(&m_data[m_iElementCount]));
}

struct B6266F0Allocator;

struct B6266F0Entry
{
    int m_iKey;
    int m_iValue;
};

struct B6266F0PodTag
{
};


class B6266F0Array
{
  public:
    B6266F0Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void FUN_006266f0(B6266F0Allocator* pkAlloc, const B6266F0Entry& kEntry);
};

// Grows the array if it is full, then constructs a copy of kEntry at the end and increments the element count.
// @fnv 0x006266f0
void B6266F0Array::FUN_006266f0(B6266F0Allocator* pkAlloc, const B6266F0Entry& kEntry)
{
    if (m_iElementCount == ((int)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>((void *)this)->GetSizeMasked())))
        ::ResizeAudioStream((::AudioAllocator *)(pkAlloc), (::AudioStream *)(void *)(this), sizeof(B6266F0Entry));
    ::CopyPairsIntoPlacement((int)(m_data + m_iElementCount), 1, (int *)&(kEntry));
    m_iElementCount++;
}

struct S_00626870_Tag
{
};
// @fnv 0x00626870
void FUN_00621c90_Class::FUN_00626870()
{
    ::NoOpLoop(m_vtbl, m_kPointA);
    m_kPointA = 0;
}

struct FUN_00620ff0
{
    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    int m_020;
    int m_024;
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    int m_304;
    int m_308;
    int m_30c;
    int m_310;
    int m_314;
    int m_318;
    int m_31c;
    int m_320;
    int m_324;
    int m_328;
    int m_32c;
    int m_330;
    int m_334;
    int m_338;
    int m_33c;
    int m_340;
    int m_344;
    int m_348;
    int m_34c;
    int m_350;
    int m_354;
    int m_358;
    int m_35c;
    int m_360;
    int m_364;
    int m_368;
    int m_36c;
    int m_370;
    int m_374;
    int m_378;
    int m_37c;
    int m_380;
    int m_384;
    int m_388;
    int m_38c;
    int m_390;
    int m_394;
    int m_398;
    int m_39c;
    FUN_00620ff0()
    {}
    ~FUN_00620ff0()
    {}
};

struct FUN_00633c90
{
    FUN_00633c90(int)
    {}
    ~FUN_00633c90()
    {}
};

struct FUN_006268b0
{
    FUN_00620ff0 m_pHeadNode;
    FUN_00633c90 m_iSecondInteger;
    FUN_006268b0(float, int);
};

// Constructs the object by initialising its two members and forwarding the float and int arguments to FUN_006269a0.
// @fnv 0x006268b0
FUN_006268b0::FUN_006268b0(float afValue, int aiValue) : m_pHeadNode(), m_iSecondInteger(0)
{
    reinterpret_cast<::xPick *>((this))->FUN_006269a0(afValue, aiValue);
}

struct FNVEffectBase
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39(void* a1);
};
struct FNVSubSys
{
};
struct FNVTarget
{
};
struct FNVEffectOwner
{
    void ApplyEffectToTarget(void* a1);
};
// @fnv 0x00626d20
void FNVEffectOwner::ApplyEffectToTarget(void* pTarget)
{
    if (((void *)(::FUN_00559450((int *)(((FNVSubSys*)((char*)this + 0x3a0)))))))
    {
        ((FNVEffectBase*)((void *)(::FUN_00559450((int *)(((FNVSubSys*)((char*)this + 0x3a0)))))))->v39(pTarget);
        if (pTarget)
        {
            reinterpret_cast<::C68E30Owner *>((((FNVTarget*)pTarget)))->FUN_00c68e30((::C68E30Holder *)(void *)(((void *)(::FUN_00559450((int *)(((FNVSubSys*)((char*)this + 0x3a0))))))), (int)(((void *)(::PackBytesBigEndian(0x58, 0xad, 0x56, 0x28)))));
        }
    }
}

struct D626F10Object
{
    int unk00;
    ~D626F10Object();
};


// Deletes g_pD626F10First and g_pD626F10Second if set, then clears both pointers to null.
// @fnv 0x00626f10
void FUN_00626f10()
{
    if (g_pD626F10First)
        delete g_pD626F10First;
    g_pD626F10First = 0;
    if (g_pD626F10Second)
        delete g_pD626F10Second;
    g_pD626F10Second = 0;
}

extern "C" int DAT_0104e130;

struct ObjBase_cls
{
    ObjBase_cls();
    ~ObjBase_cls();
};

struct ItemSlot_cls
{
    int m_v;
    ItemSlot_cls()
    {}

    ~ItemSlot_cls();
    void FUN_0066b0d0(int a)
    {}
};

struct SubObj_cls
{
    int* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    SubObj_cls(int a);
    ~SubObj_cls();
};

struct FUN_00626fd0 : ObjBase_cls
{
    void* m_vptr;
    int m_04;
    ItemSlot_cls m_08[6];
    int m_20;
    SubObj_cls m_24;
    float m_34;
    float m_38;
    float m_3c;
    float m_40;
    FUN_00626fd0(float a, float b, float c, float d);
};

// @fnv 0x00626fd0
FUN_00626fd0::FUN_00626fd0(float a, float b, float c, float d) : m_vptr(&DAT_0104e130), m_20(0), m_24(0x25)
{
    m_34 = a;
    m_38 = b;
    m_3c = c;
    m_40 = d;
    for (int i = 0; i < 6; i++)
        m_08[i].FUN_0066b0d0(0);
}

class BaseObj
{
  public:
    int unk04;
    virtual ~BaseObj()
    {}
};

class ElemObj
{
  public:
    int unk00;
    void Release(int flag);
    ~ElemObj()
    {}
};

class MemberObj
{
  public:
    int unk00;
    void Shutdown();
    ~MemberObj()
    {}
};
// @fnv 0x00629a50
void* Unk629a50::FUN_00629a50(unsigned int flags)
{
    reinterpret_cast<::MemberObj *>((((FUN_00629e50_Holder*)this)))->MemberObj::~MemberObj();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

class FUN_006270f0 : public BaseObj
{
  public:
    ElemObj m_aiIndexedValues[6];
    int unk20;
    MemberObj m_kMemberDescriptor;
    virtual ~FUN_006270f0();
};

// Releases all six ElemObj entries with flag 0, then calls Init on the MemberObj member.
// @fnv 0x006270f0
FUN_006270f0::~FUN_006270f0()
{
    for (int i = 0; i < 6; i++)
    {
        m_aiIndexedValues[i].Release(0);
    }
    reinterpret_cast<::FUN_00438af0_Class *>(&(m_kMemberDescriptor))->FUN_00438af0();
}

struct Tmp
{
    int a, b, c;
    void FUN_006815c0();
};
struct Sub
{
};
struct Ref;
struct VT
{
    void* p0[125];
    void*(* v1f4)(Ref*, Tmp*);
    void* p1[(0x2a8 - 0x1f8) / 4];
    void(* v2a8)(Ref*, Tmp*);
};
struct Ref
{
    VT* vt;
};
struct Me
{
    void FUN_006295e0(Ref* r);
};
// @fnv 0x006295e0
void Me::FUN_006295e0(Ref* apRef)
{
    Tmp t;
    new ((void *)&(t)) ::Vec3();
    reinterpret_cast<::SpawnPlacerP *>(this)->FUN_006296d0((::TESObjectREFRP *)(apRef), (const ::NiPoint3P *)(void *)(apRef->vt->v1f4(apRef, &t)), {});
    apRef->vt->v2a8(apRef, &t);
    if (((::Sub *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((apRef))->FUN_009306d0())))
    {
        reinterpret_cast<::FUN_00629650_Class *>((((Sub*)((char*)((::Sub *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((apRef))->FUN_009306d0())) + 0x410))))->FUN_00629650(false);
    }
}

struct FUN_004a4840_cls
{
    bool m_flag;
    int FUN_004a4840(void* pArg);
};

struct FUN_00629ad0_cls
{
};

struct FUN_006299c0_cls
{
    int m_iFadeNodeMode;
    void FUN_006299c0(int a);
};

struct S_00629c10_Item
{
    S_00629c10_Item* unk00;
    int unk04;
    unsigned short unk08;
};
struct S_00629c10_Map
{
    virtual unsigned v0();
    virtual unsigned Hash(int key);
    virtual bool IsKeysEqual(int a, int b);
    virtual void SetValue(S_00629c10_Item* item, int key, unsigned short v);
    virtual S_00629c10_Item* v10();
    virtual S_00629c10_Item* NewItem();
    unsigned unk04;
    S_00629c10_Item** unk08;
    unsigned unk0c;
    void SetKeyValue(int key, unsigned short val);
};
// Looks up key in the hash bucket, updates the item's value if found, otherwise inserts a new item at the bucket head and increments the count.
// @fnv 0x00629c10
void S_00629c10_Map::SetKeyValue(int key, unsigned short ausValue)
{
    unsigned idx = Hash(key);
    S_00629c10_Item* item = unk08[idx];
    unsigned count = 0;
    while (item)
    {
        count++;
        if (IsKeysEqual(key, item->unk04))
        {
            item->unk08 = ausValue;
            return;
        }
        item = item->unk00;
    }
    item = NewItem();
    SetValue(item, key, ausValue);
    item->unk00 = unk08[idx];
    unk08[idx] = item;
    unk0c++;
}

class FUN_00629cf0_item
{
  public:
    virtual void v00();
};

struct FUN_00629cf0_node
{
    FUN_00629cf0_node* m_pNext;
    FUN_00629cf0_item* m_pInventoryEntryData;
    unsigned short m_usValue;
};

class FUN_00629cf0_cls
{
  public:
    virtual void v00();
    virtual int v01(int a);
    virtual bool v02(int a, FUN_00629cf0_item* item);

    unsigned int unk04;
    FUN_00629cf0_node** m_ppBuckets;

    bool LookupValue(int a, unsigned short* out);
};

// Hashes a with v01, walks the bucket chain comparing entries via v02, and writes the matching node's m_usValue to out, returning true if found.
// @fnv 0x00629cf0
bool FUN_00629cf0_cls::LookupValue(int aiKey, unsigned short* out)
{
    int idx = v01(aiKey);
    FUN_00629cf0_node* node = m_ppBuckets[idx];
    while (node != 0)
    {
        if (v02(aiKey, node->m_pInventoryEntryData))
        {
            *out = node->m_usValue;
            return true;
        }
        node = node->m_pNext;
    }
    return false;
}

struct FUN_00629d70_entry
{
    FUN_00629d70_entry* m_pNext;
    unsigned int m_uiKey;
    unsigned short m_usValue;
};

class FUN_00629d70_cls
{
  public:
    virtual void unkVtbl00();
    virtual unsigned int FindIndex(unsigned int key);
    unsigned int m_uiSize;
    FUN_00629d70_entry** m_ppData;
    void GetNextEntry(FUN_00629d70_entry** kArgumentPosition, unsigned int* pKey, unsigned short* pValue);
};

// Reads the key and value of the current entry, advances to its next entry or the next non-null bucket, and clears the pointer when exhausted.
// @fnv 0x00629d70
void FUN_00629d70_cls::GetNextEntry(FUN_00629d70_entry** apEntry, unsigned int* pKey, unsigned short* pValue)
{
    FUN_00629d70_entry* cur = *apEntry;
    *pKey = cur->m_uiKey;
    *pValue = cur->m_usValue;
    if (cur->m_pNext != 0)
    {
        *apEntry = cur->m_pNext;
        return;
    }
    unsigned int i = FindIndex(cur->m_uiKey);
    i = i + 1;
    for (; i < m_uiSize; ++i)
    {
        cur = m_ppData[i];
        if (cur != 0)
        {
            *apEntry = cur;
            return;
        }
    }
    *apEntry = 0;
}

class ThisTemp_62a190
{
  public:
    unsigned int m_00;
    ThisTemp_62a190(const ThisTemp_62a190& aOther);
};

class ThisParam_62a190
{
  public:
    virtual ~ThisParam_62a190();
    ThisTemp_62a190 Get();
};

class ThisMember_62a190
{
  public:
    ThisMember_62a190(unsigned int aFlag);
};

class ThisBase_62a190
{
  public:
    ThisBase_62a190();
    virtual ~ThisBase_62a190();
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
};

class FUN_0062a190 : public ThisBase_62a190
{
  public:
    ThisMember_62a190 m_70;
    FUN_0062a190(void* aArg, ThisParam_62a190* aParam);
    virtual ~FUN_0062a190();
};

class SpawnedBase_b7276
{
  public:
    virtual void unk00();
    int m_04;
    int m_08;
    int m_0c;

    SpawnedBase_b7276();
    ~SpawnedBase_b7276();
};

class SpawnedMember_b7276
{
  public:
    int m_00;

    SpawnedMember_b7276();
};

class FUN_0062a220_cls : public SpawnedBase_b7276
{
  public:
    SpawnedMember_b7276 m_10;

    FUN_0062a220_cls();
    virtual void unk00();
};

// @fnv 0x0062a220
FUN_0062a220_cls::FUN_0062a220_cls()
{
    reinterpret_cast<::FUN_0062a290_Class *>(this)->FUN_0062a290();
}

struct A3B0Filter
{
    unsigned int m_uiFilterInfo;

};

void __cdecl SetSelectedTargetMask(int iLayer, unsigned __int64 uiMask);

struct A3B0Controller
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    A3B0Filter m_kFilter;
    float m_fTimer;

    void SetFilter(int iLayer, const A3B0Filter& kFilter);
};
// Initializes m_70 to 0 and, if aParam is non-null, fetches a temp value from it and passes it to Method_62a190 with aArg.
// @fnv 0x0062a190
FUN_0062a190::FUN_0062a190(void* aArg, ThisParam_62a190* aParam) : m_70(0)
{
    if (aParam != 0)
    {
        ThisTemp_62a190 aTemp = aParam->Get();
        reinterpret_cast<::A3B0Controller *>(this)->SetFilter((int)(aArg), (*(const ::A3B0Filter *)(&aTemp)));
    }
}

// @fnv 0x0062a3b0
void A3B0Controller::SetFilter(int iLayer, const A3B0Filter& kFilter)
{
    m_fTimer = 0.0f;
    m_kFilter = kFilter;
    if (iLayer < 0x23)
        iLayer = 0x27;
    unsigned __int64 uiMask = 0x22757;
    uiMask |= (unsigned __int64)1 << reinterpret_cast<::FUN_0043b4d0_shell *>(&(m_kFilter))->FUN_0043b4d0();
    SetSelectedTargetMask(iLayer, uiMask);
}


// @fnv 0x0062aad0
int __cdecl FUN_0062aad0()
{
    return (int)&(*reinterpret_cast<int *>(&::DAT_012683b0));
}

struct NiTriBasedGeom;
struct TESObjectREFR;
struct TES;
struct FUN_00559450_h
{
};
struct Col_0043b4f0
{
};
struct GlobalObject_008c71b0
{
    int m_uiFilterValue;
    GlobalObject_008c71b0(int value);
};
struct FUN_00457880_Class
{
    unsigned int FUN_00457880(int value);
};
// @fnv 0x0062b150
unsigned int __cdecl FUN_0062b150(uintptr_t param_1, uintptr_t uiValue)
{
    int iStack_8;
    unsigned int uiResult;
    iStack_8 =
        ::FUN_004a3a40(reinterpret_cast<TESObjectREFR*>(((::NiTriBasedGeom *)(::FUN_00559450((int *)(reinterpret_cast<FUN_00559450_h*>(param_1)))))));
    if (iStack_8 == 0)
    {
        GlobalObject_008c71b0 local(
            ((int)(::FUN_0043b540((char *)(reinterpret_cast<Col_0043b4f0*>(reinterpret_cast<FUN_00624020_Class*>(param_1)->GetLastNode()))))));
        if (reinterpret_cast<::FUN_0043b4d0_shell *>((reinterpret_cast<H0043b4d0*>(&local)))->FUN_0043b4d0() == 0x11)
        {
            uiResult = reinterpret_cast<FUN_00457880_Class*>((*reinterpret_cast<::TES * *>(&::g_TES)))->FUN_00457880(uiValue);
        }
        else
        {
            uiResult = ::FUN_00c80020((::DispatchContainer *)(param_1));
        }
    }
    else
    {
        uiResult = MinInt(reinterpret_cast<FUN_006205a0_Class*>(iStack_8)->FUN_006205a0(), 0x23);
    }
    return uiResult;
}

class GameSettingCollection;
template <class T> class SettingT
{
  public:
    float* Float();
};
class GlobalObject_0040e0b0
{
  public:
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting964;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting967;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting968;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting969;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting970;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting971;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting972;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting973;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting965;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting966;
extern GlobalObject_0040e0b0 g_011d141c;
extern GlobalObject_0040e0b0 g_011d1224;
// @fnv 0x0062b1e0
float FUN_0062b1e0(unsigned int uiIndex)
{
    switch (uiIndex)
    {
    case 0:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting964))));
    case 1:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting967))));
    case 2:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting968))));
    case 3:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting969))));
    case 4:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting970))));
    case 5:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting971))));
    case 6:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting972))));
    case 7:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting973))));
    case 8:
        return *((float *)&(::FUN_00403e20((float *)&(g_011d141c))));
    case 9:
        return *((float *)&(::FUN_00403e20((float *)&(g_011d1224))));
    case 24:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting966))));
    case 25:
        return *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting965))));
    default:
        return 0.0f;
    }
}

extern "C" int DAT_0104e37c;
extern "C" int DAT_0104e350;
extern "C" int DAT_0104e338;

struct FUN_0061ffb0
{
    int* m_ppVirtualMethodTable;
    int m_data04;
    FUN_0061ffb0();
    ~FUN_0061ffb0();
};

struct FUN_0062d680
{
    int* m_ppVirtualMethodTable;
    int m_data04;
    int m_data08;
    int m_data0c;
    int m_data10;
    FUN_0062d680();
};

struct FUN_0062d5c0 : FUN_0061ffb0
{
    FUN_0062d680 m_part08;
    int* m_vtable1c;
    int m_count20;
    FUN_0062d5c0();
};

// @fnv 0x0062d5c0
FUN_0062d5c0::FUN_0062d5c0() : FUN_0061ffb0(), m_part08()
{
    m_ppVirtualMethodTable = &DAT_0104e37c;
    m_part08.m_ppVirtualMethodTable = &DAT_0104e350;
    m_vtable1c = &DAT_0104e338;
    m_count20 = 0;
}

struct DecompBase0
{
    void* m_vptr;
    virtual ~DecompBase0();
};

struct DecompSec08
{
    void* m_vptr;
    int unk04;
    int unk08;
    int unk0C;
    virtual ~DecompSec08();
};

struct DecompThr1c
{
    void* m_vptr;
    virtual void unk08();
};

struct FUN_0062d8a0 : DecompBase0, DecompSec08, DecompThr1c
{
    virtual ~FUN_0062d8a0();
};

struct FUN_0062d990_Class
{
};

struct FUN_0062d920_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_0062d990_Class* m_20;
    void FUN_0062d920();
};
// @fnv 0x0062d8a0
FUN_0062d8a0::~FUN_0062d8a0()
{
    reinterpret_cast<::FUN_0062d920_cls *>(this)->FUN_0062d920();
}

// @fnv 0x0062d920
void FUN_0062d920_cls::FUN_0062d920()
{
    FUN_0062d990_Class* cur = m_20;
    FUN_0062d990_Class* next;
    {
        FUN_0062d9b0_Class* p;
        FUN_0062d990_Class* a;
        while (cur != 0)
        {
            next = ((::FUN_0062d990_Class *)(reinterpret_cast<::CombatWorldStateListNode *>((cur))->GetNext()));
            a = cur;
            p = (FUN_0062d9b0_Class*)a;
            (p != 0) ? p->FUN_0062d9b0(1) : 0;
            cur = next;
        }
    }
    m_20 = 0;
}

class BasePrim_b9581
{
  public:
    virtual ~BasePrim_b9581();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

class BaseSec_b9581
{
  public:
    virtual ~BaseSec_b9581();
    int m_04;
    int m_08;
    void* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};

class MemberWithDtor_b9581
{
  public:
    ~MemberWithDtor_b9581();
    int m_00;
};


class FUN_0062e860_cls : public BasePrim_b9581, public BaseSec_b9581
{
  public:
    virtual ~FUN_0062e860_cls();
    MemberWithDtor_b9581 m_34;
};

// Resets the object with zeroed values, then frees the pointer stored in the secondary base's m_0c field.
// @fnv 0x0062e860
FUN_0062e860_cls::~FUN_0062e860_cls()
{
    reinterpret_cast<::fnv_00631370::WorkOwner *>(this)->FUN_00631370((::fnv_00631370::WorkActor *)(0), 0, 0);
    void* p = this->BaseSec_b9581::m_0c;
    ::FUN_00401030(p);
}

struct FUN_00631920_base
{
    virtual ~FUN_00631920_base();
};

struct FUN_00631920_sub
{
    void unk00();
};

struct FUN_00631920_cls : FUN_00631920_base
{
    virtual ~FUN_00631920_cls();
};

// Destructor that forwards to unk00 on the object viewed as FUN_00631920_sub.
// @fnv 0x00631920
FUN_00631920_cls::~FUN_00631920_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>((((FUN_00631920_sub*)this)))->FUN_00438af0();
}

struct ObjBaseA
{
    ObjBaseA();
    ~ObjBaseA()
    {}
    virtual void unk00();
};

struct SubObjectA
{
    int unk00;
    SubObjectA(int flag = 0);
    void Reset(int flag);
    ~SubObjectA();
};

struct FUN_00633080 : ObjBaseA
{
    unsigned int unk04;
    SubObjectA m_08;
    SubObjectA m_0c;
    SubObjectA m_10;
    SubObjectA m_14;
    unsigned char m_18;

    FUN_00633080();
    virtual void unk00();
};

// Constructs the object, resetting its four SubObjectA members to 0 and setting m_18 to 1.
// @fnv 0x00633080
FUN_00633080::FUN_00633080() : m_08(0), m_0c(0), m_10(0), m_14(0)
{
    m_08.Reset(0);
    m_14.Reset(0);
    m_10.Reset(0);
    m_0c.Reset(0);
    m_18 = 1;
}

namespace fnv_00636a40 {
struct FUN_00633c90
{
    int unk00;
    FUN_00633c90(int a);
    ~FUN_00633c90();
    void FUN_0066b0d0(int a);
};
struct FUN_00636a40
{
    virtual void vf0();
    FUN_00633c90 m_04;
    FUN_00633c90 m_08;
    int unk0C;
    float m_10;
    int unk14;
    FUN_00636a40();
};
// Constructor: initializes m_04 and m_08 via FUN_0066b0d0(0) and zeroes m_10, unk14 and unk0C.
// @fnv 0x00636a40
FUN_00636a40::FUN_00636a40() : m_04(0), m_08(0)
{
    m_04.FUN_0066b0d0(0);
    m_08.FUN_0066b0d0(0);
    m_10 = 0.0f;
    unk14 = 0;
    unk0C = 0;
}
}  // namespace fnv_00636a40

namespace fnv_00637890 {
struct Pt3
{
    float x, y, z;
    Pt3();
    Pt3(float fx, float fy, float afDepth);
    Pt3 operator*(float s) const;
    Pt3 operator+(const Pt3& o) const;
};
Pt3 operator*(float s, const Pt3& p);

struct Pt2
{
    float x, y;
    Pt2();
    Pt2(float fx, float fy);
};

struct Mat3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Pt3 operator*(const Pt3& p) const;
};

struct Xform
{
    Mat3 m_rot;
    Pt3 m_trans;
    float m_vScale;
    Xform();
    Xform operator*(const Xform& o) const;
    Pt3 operator*(const Pt3& p) const;
};

struct Bnd
{
    Pt3 m_kCenterPosition;
    float m_fSphereRadius;
};

struct Rtti
{
    int unk00;
};

struct Obj
{
    virtual ~Obj();
    virtual void v01();
    virtual void v02();
    virtual Obj* v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39(float a, int b, float* out);
    virtual void v40();
    virtual void v41();
    virtual void v42(Pt3* out, Pt3* in);

    Obj* GetAt(int i);
    const Xform& GetWorld();
    int GetMode();
    void SetActive(int a, int b, int c, int d, unsigned short n, int e, int f);
};

struct TriData : Obj
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    TriData(unsigned short nVerts, Pt3* verts, Pt3* normals, void* colors, Pt2* uvs, unsigned short nSets, int flags,
            unsigned short nTris, unsigned short* tris, int a, int b);
};

struct TriShape : Obj
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    TriShape(TriData* d);
};

struct PartData : Obj
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    PartData(unsigned short n, int a, int b);
};

struct PartCtrl : Obj
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    PartCtrl(unsigned short n, float life, Pt3* dir, Pt3* minp, Pt3* maxp, int flag, int mode);
};



struct ParticleMgr
{
    Obj* CreateParticleShape(Obj* node, int unused, unsigned char flag);
};

// Builds a TriShape from the emitter node's geometry or a generated quad grid, sets its bounds and attaches a PartCtrl, returning the shape or null.
// @fnv 0x00637890
Obj* ParticleMgr::CreateParticleShape(Obj* node, int unused, unsigned char flag)
{
    Obj* empty2;
    Obj* aSrc5;
    Obj* lim3;
    Obj* sig_2;
    Obj* pChild6;
    TriShape* sA;
    float ratio5;
    ratio5 = 0.0f;
    lim3 = 0;
    empty2 = 0;
    sig_2 = 0;
    aSrc5 = 0;
    sA = 0;
    pChild6 = ((::fnv_00637890::Obj *)(::fnv_0043b230::FUN_0043b230((const char *)(node))));
    while (pChild6)
    {
        if (::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_012024e8))), (::NiAVObject *)(pChild6)))
        {
            Obj* extra8 = pChild6;
            lim3 = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202540))), (::NiObject *)(::fnv_00637890::Obj *)(((::fnv_00637890::Obj *)(reinterpret_cast<::Twin_00639b40 *>((extra8))->GetEntryPoint()))))));
            Obj* eb = ((::fnv_00637890::Obj *)(reinterpret_cast<::NiPSysEmitterCtlr_StandIn *>((extra8))->FUN_00639b60()));
            eb->v39(0.0f, 0, &ratio5);
            ratio5 = reinterpret_cast<::FUN_00639aa0_shell *>((lim3))->FUN_00639aa0() * ratio5;
            break;
        }
        else
        {
            pChild6 = ((::fnv_00637890::Obj *)(::fnv_004a8a90::FUN_004a8a90((char *)(pChild6))));
        }
    }
    if (lim3)
    {
        float dstEnd7;
        float playerPosA;
        float desc4;
        float kScale;
        float lit;
        float aPc1;
        unsigned short count8;
        unsigned short pElem9;
        pElem9 = 0;
        count8 = (unsigned short)ratio5;
        lit = 0.0f;
        Xform XA;
        Pt3 minPt3;
        Pt3 mask2;
        if (::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202538))), (::NiAVObject *)(node)))
        {
            int aIi;
            Obj* aLo;
            aIi = 0;
            while (1)
            {
                Obj* ac4 = ((::fnv_00637890::Obj *)(reinterpret_cast<::Owner *>((node))->GetByIndex(aIi++)));
                if (ac4 == 0)
                {
                    break;
                }
                if (!empty2 && ::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202530))), (::NiAVObject *)(ac4)))
                {
                    empty2 = ac4;
                }
                if (!sig_2 && ::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202528))), (::NiAVObject *)(ac4)))
                {
                    sig_2 = ac4;
                }
            }
            if (empty2)
            {
                Obj* tgtD = ((::fnv_00637890::Obj *)(reinterpret_cast<::fnv_00639a60::C639a60 *>((empty2))->GetElementAt(0)))->v03();
                if (tgtD)
                {
                    aSrc5 = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_011f4acc))), (::NiObject *)(::fnv_00637890::Obj *)(((::fnv_00637890::Obj *)(reinterpret_cast<::S_FUN_0045bc00 *>((tgtD))->FUN_0045bc00(0)))))));
                }
            }
            if (sig_2)
            {
                lit = reinterpret_cast<::BSMultiBoundSphere *>((sig_2))->GetRadius();
            }
            aLo = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_011f4a20))), (::NiObject *)(aSrc5))));
            if (aLo == 0)
            {
                unsigned short* aTb;
                Pt2* aU0;
                int aTop;
                Pt3* srcp_2;
                unsigned short* saB;
                Pt3* aV1;
                Obj* sgB;
                Pt2* sn5;
                Obj* gl3;
                unsigned short t2;
                sgB = ((::fnv_00637890::Obj *)(::fnv_005495f0::FUN_005495f0((const char *)(aSrc5))));
                gl3 = 0;
                gl3 = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_011f4a88))), (::NiObject *)(sgB))));
                pElem9 = reinterpret_cast<::TESActorBaseData *>((gl3))->GetFatigue();
                t2 = ((unsigned short)(reinterpret_cast<::LowProcess *>((gl3))->GetActiveCombatTarget()));
                srcp_2 = ((::fnv_00637890::Pt3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((gl3))->FUN_007af430()));
                sn5 = ((::fnv_00637890::Pt2 *)(reinterpret_cast<::BGSMessageInitAccess *>((gl3))->GetIconFormID()));
                saB = ((unsigned short *)(reinterpret_cast<::FnvCpu_FUN_00a7b850_CpuObject *>((gl3))->FUN_00a7b850()));
                count8 = ::MinUnsignedShort(count8, 0xffff / pElem9);
                aV1 = new Pt3[pElem9 * count8];
                aU0 = new Pt2[pElem9 * count8];
                aTb = (unsigned short*)::FUN_00aa1070(t2 * count8 * 2);
                aTop = 0;
                for (int akq4 = 0; akq4 < count8; akq4++)
                {
                    int aBAny = pElem9 * akq4;
                    for (int aVictorz9 = 0; aVictorz9 < pElem9; aVictorz9++)
                    {
                        int aD = aBAny + aVictorz9;
                        aV1[aD] = srcp_2[aVictorz9];
                        aU0[aD] = sn5[aVictorz9];
                    }
                    for (int aN11 = 0; aN11 < t2; aN11++)
                    {
                        aTb[aTop] = saB[aN11] + aBAny;
                        aTop++;
                    }
                }
                sA = new TriShape(new TriData(pElem9 * count8, aV1, 0, 0, aU0, 1, 0, t2 / 3 * count8, aTb, 0, 0));
            }
        }
        else
        {
            Pt2* buffer5;
            unsigned short* bt5;
            int bits7;
            Pt3* bVisible4;
            int nTmp;
            int n4;
            bits7 = 0;
            while (1)
            {
                Obj* bCurrent_2 = ((::fnv_00637890::Obj *)(reinterpret_cast<::Owner *>((node))->GetByIndex(bits7++)));
                if (bCurrent_2 == 0)
                {
                    break;
                }
                if (::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202528))), (::NiAVObject *)(bCurrent_2)))
                {
                    sig_2 = bCurrent_2;
                    break;
                }
            }
            if (sig_2)
            {
                lit = reinterpret_cast<::BSMultiBoundSphere *>((sig_2))->GetRadius();
            }
            aSrc5 = node;
            pElem9 = 4;
            count8 = ::MinUnsignedShort(count8, 0xffff / pElem9);
            nTmp = count8 * 2;
            n4 = count8 * 4;
            bVisible4 = new Pt3[n4];
            buffer5 = new Pt2[n4];
            bt5 = (unsigned short*)::FUN_00aa1070(nTmp * 3 * 2);
            for (unsigned int b2 = 0; b2 < count8; b2++)
            {
                float b6;
                int b3a;
                int bE4;
                b6 = reinterpret_cast<::FUN_00792760_shell *>((lim3))->FUN_00792760();
                b3a = b2 * 4;
                bVisible4[b3a] = b6 * Pt3(::DAT_01012054, 0.0f, ::DAT_01012054);
                bVisible4[b3a + 1] = b6 * Pt3(1.0f, 0.0f, ::DAT_01012054);
                bVisible4[b3a + 2] = b6 * Pt3(1.0f, 0.0f, 1.0f);
                bVisible4[b3a + 3] = b6 * Pt3(::DAT_01012054, 0.0f, 1.0f);
                buffer5[b3a] = Pt2(0.0f, 1.0f);
                buffer5[b3a + 1] = Pt2(1.0f, 1.0f);
                buffer5[b3a + 2] = Pt2(1.0f, 0.0f);
                buffer5[b3a + 3] = Pt2(0.0f, 0.0f);
                bE4 = b2 * 6;
                bt5[bE4] = b3a;
                bt5[bE4 + 1] = b3a + 1;
                bt5[bE4 + 2] = b3a + 2;
                bt5[bE4 + 3] = b3a + 3;
                bt5[bE4 + 4] = b3a;
                bt5[bE4 + 5] = b3a + 2;
            }
            sA = new TriShape(new TriData(n4, bVisible4, 0, 0, buffer5, 1, 0, nTmp, bt5, 0, 0));
        }
        if (sA == 0)
        {
            return 0;
        }
        float fSpeed2;
        float D9;
        float pSel_;
        fSpeed2 = reinterpret_cast<::BSMultiBoundSphere *>((lim3))->GetRadius() + ::GetFloatAtOffset1C((char *)(lim3)) * (::FUN_00639780() - DAT_01011588);
        desc4 = reinterpret_cast<::ActiveEffect *>((lim3))->GetDuration() + reinterpret_cast<::FUN_00526ac0_shell *>((lim3))->FUN_00526ac0() * FUN_006397c0();
        playerPosA = reinterpret_cast<::FUN_00526ae0_class *>((lim3))->FUN_00526ae0() + reinterpret_cast<::FUN_00759450_shell *>((lim3))->FUN_00759450() * FUN_006397c0();
        FUN_00639730(playerPosA, &pSel_, &aPc1);
        FUN_00639730(desc4, &dstEnd7, &D9);
        Pt3 diff2(dstEnd7 * aPc1, dstEnd7 * pSel_, D9);
        Pt3 v30 = fSpeed2 * diff2;
        kScale = reinterpret_cast<::FUN_00639aa0_shell *>((lim3))->FUN_00639aa0();
        Obj* boxA7;
        Obj* meanB;
        PartData* data8;
        Obj* CX;
        Pt3* pos5;
        PartCtrl* ct5;
        Pt3 local7;
        int modeB;
        Obj* spA;
        boxA7 = 0;
        spA = 0;
        CX = 0;
        meanB = 0;
        if (::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202518))), (::NiAVObject *)(lim3)))
        {
            boxA7 = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202518))), (::NiObject *)(lim3))));
            Xform w0 = ((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_006a1b60_Class *>((boxA7))->GetField54()))->GetWorld();
            Xform w1 = ((::fnv_00637890::Obj *)(reinterpret_cast<::MagicCaster_shell *>((boxA7))->FUN_0044edb0()))->GetWorld();
            Xform inv;
            reinterpret_cast<::NiTransform *>((void *)&(w1))->CalculateInverse((::NiTransform &)(inv));
            XA = inv * w0;
            local7 = XA * v30;
            minPt3 = Pt3(-(reinterpret_cast<::FUN_005081b0_shell *>((boxA7))->GetFloatAtOffset58() / ::DAT_01011590), -(reinterpret_cast<::TESGrass *>((boxA7))->GetLowestAllowedSlope() / ::DAT_01011590),
                         ::FUN_0040ebd0(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
            mask2 = Pt3(reinterpret_cast<::FUN_005081b0_shell *>((boxA7))->GetFloatAtOffset58() / ::DAT_01011590, reinterpret_cast<::TESGrass *>((boxA7))->GetLowestAllowedSlope() / ::DAT_01011590,
                        ::FUN_00404010(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
        }
        else if (::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202510))), (::NiAVObject *)(lim3)))
        {
            CX = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202510))), (::NiObject *)(lim3))));
            Xform w0 = ((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_006a1b60_Class *>((CX))->GetField54()))->GetWorld();
            Xform w1 = ((::fnv_00637890::Obj *)(reinterpret_cast<::MagicCaster_shell *>((CX))->FUN_0044edb0()))->GetWorld();
            Xform inv;
            reinterpret_cast<::NiTransform *>((void *)&(w1))->CalculateInverse((::NiTransform &)(inv));
            XA = inv * w0;
            local7 = XA * v30;
            minPt3 =
                Pt3(-reinterpret_cast<::FUN_005081b0_shell *>((CX))->GetFloatAtOffset58(), -reinterpret_cast<::FUN_005081b0_shell *>((CX))->GetFloatAtOffset58(), ::FUN_0040ebd0(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
            mask2 = Pt3(reinterpret_cast<::FUN_005081b0_shell *>((CX))->GetFloatAtOffset58(), reinterpret_cast<::FUN_005081b0_shell *>((CX))->GetFloatAtOffset58(), ::FUN_00404010(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
        }
        else if (::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202508))), (::NiAVObject *)(lim3)))
        {
            spA = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202508))), (::NiObject *)(lim3))));
            Xform w0 = ((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_006a1b60_Class *>((spA))->GetField54()))->GetWorld();
            Xform w1 = ((::fnv_00637890::Obj *)(reinterpret_cast<::MagicCaster_shell *>((spA))->FUN_0044edb0()))->GetWorld();
            Xform inv;
            reinterpret_cast<::NiTransform *>((void *)&(w1))->CalculateInverse((::NiTransform &)(inv));
            XA = inv * w0;
            local7 = XA * v30;
            minPt3 =
                Pt3(-reinterpret_cast<::FUN_005081b0_shell *>((spA))->GetFloatAtOffset58(), -reinterpret_cast<::FUN_005081b0_shell *>((spA))->GetFloatAtOffset58(), ::FUN_0040ebd0(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
            mask2 = Pt3(reinterpret_cast<::FUN_005081b0_shell *>((spA))->GetFloatAtOffset58(), reinterpret_cast<::FUN_005081b0_shell *>((spA))->GetFloatAtOffset58(), ::FUN_00404010(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
        }
        else if (::FUN_0043b300((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202500))), (::NiAVObject *)(lim3)))
        {
            meanB = ((::fnv_00637890::Obj *)(::FUN_00653270((const ::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_01202500))), (::NiObject *)(lim3))));
            Xform m4 = ((::fnv_00637890::Obj *)(reinterpret_cast<::fnv_00639ac0::FUN_00639ac0_Class *>((meanB))->GetAtChecked(0)))->GetWorld();
            Xform m6 = node->GetWorld();
            float radiusX;
            Xform minDistTmp;
            reinterpret_cast<::NiTransform *>((void *)&(m6))->CalculateInverse((::NiTransform &)(minDistTmp));
            XA = minDistTmp * m4;
            local7 = XA * v30;
            Bnd m_ = *((::fnv_00637890::Bnd *)(::GetSourceFilesFromForm((char *)(((::fnv_00637890::Obj *)(reinterpret_cast<::fnv_00639ac0::FUN_00639ac0_Class *>((meanB))->GetAtChecked(0)))))));
            Pt3 kTargetCenter = (*(const ::fnv_00637890::Pt3 *)(new ((void *)&(m_)) ::Vec3()));
            radiusX = reinterpret_cast<::Twin_0084d030 *>((void *)&(m_))->GetStoredFloatValue();
            minPt3 = Pt3(kTargetCenter.x - radiusX, kTargetCenter.y - radiusX,
                         ::FUN_0040ebd0(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
            mask2 = Pt3(kTargetCenter.x + radiusX, kTargetCenter.y + radiusX,
                        ::FUN_00404010(XA.m_trans.z, kScale * local7.z + XA.m_trans.z));
        }
        else
        {
            delete sA;
            return 0;
        }
        int total5;
        total5 = pElem9 * count8;
        pos5 = new Pt3[total5];
        Pt3 node2;
        Pt3 D8 = kScale * local7;
        for (int _k2 = 0; _k2 < count8; _k2++)
        {
            Pt3 p2;
            if (boxA7)
            {
                p2 = Pt3(reinterpret_cast<::FUN_005081b0_shell *>((boxA7))->GetFloatAtOffset58() * (::FUN_00639780() - DAT_01011588),
                         reinterpret_cast<::TESGrass *>((boxA7))->GetLowestAllowedSlope() * (::FUN_00639780() - DAT_01011588), 0.0f);
                p2 = XA.m_rot * p2;
                p2 = D8 * ::FUN_00639780() + p2;
            }
            else if (spA)
            {
                float scaled4;
                float saved6;
                float snB;
                float sp5;
                sp5 = reinterpret_cast<::FUN_005081b0_shell *>((spA))->GetFloatAtOffset58() * ::FUN_00639780();
                saved6 = ::FUN_00639780() * ::runtimeInitializationFloat2715;
                FUN_004169a0(saved6, snB, scaled4);
                p2.x = sp5 * scaled4;
                p2.y = sp5 * snB;
                p2.z = (::FUN_00639780() - DAT_01011588) * reinterpret_cast<::TESGrass *>((spA))->GetLowestAllowedSlope();
                p2 = XA.m_rot * p2;
                p2 = D8 * ::FUN_00639780() + p2;
            }
            else if (CX)
            {
                float kCa2;
                float c1;
                float c13;
                float caX;
                float caTmp;
                float cr3;
                float cr5;
                cr5 = reinterpret_cast<::FUN_005081b0_shell *>((CX))->GetFloatAtOffset58() * ::FUN_00639780();
                caTmp = ::FUN_00639780() * ::runtimeInitializationFloat2715;
                kCa2 = ::FUN_00639780() * ::runtimeInitializationFloat2715;
                FUN_004169a0(caTmp, cr3, caX);
                FUN_004169a0(kCa2, c13, c1);
                p2.x = cr5 * c13 * caX;
                p2.y = cr5 * c13 * cr3;
                p2.z = cr5 * c1;
                p2 = XA.m_rot * p2;
                p2 = D8 * ::FUN_00639780() + p2;
            }
            else
            {
                meanB->v42(&p2, &node2);
                p2 = D8 * ::FUN_00639780() + p2;
            }
            for (int v18 = 0; v18 < pElem9; v18++)
            {
                pos5[pElem9 * _k2 + v18] = p2;
            }
        }
        data8 = new PartData(total5, 1, 1);
        reinterpret_cast<::FUN_00a72ca0_Class *>((data8))->FUN_00a72ca0(1);
        reinterpret_cast<::A72BB0_DataStreamOwner *>((data8))->FUN_00a72bb0(0, pos5, total5 * 0xc, 1);
        delete[] pos5;
        reinterpret_cast<::FUN_00a726a0_cls *>((data8))->FUN_00a726a0(0, 0, 0, (void *)(3), total5, 0xc, 0xc);
        reinterpret_cast<::ShaderOwner *>((sA))->FUN_00539ef0((::NiGPUProgram *)(data8));
        int dot4;
        Bnd bound9 = *((::fnv_00637890::Bnd *)(::GetSourceFilesFromForm((char *)(sA))));
        reinterpret_cast<::FUN_0063f790_shell *>(&(bound9))->FUN_0063f790((mask2.x - minPt3.x) / ::DAT_01011590);
        reinterpret_cast<::FUN_006397f0_Obj *>(&(bound9))->SetFromFloats(0.0f, 0.0f, 0.0f);
        reinterpret_cast<::s4a5200::Owner *>((sA))->FUN_004a5200((int)(&bound9));
        modeB = 1;
        if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(::fnv_00637890::Rtti *)(&(*reinterpret_cast<::fnv_00637890::Rtti *>(&::g_011f4aa0))), (const ::fnv_0045bad0::NiObject *)(::fnv_00637890::Obj *)(((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_009611e0_shell *>((node))->FUN_009611e0())))))
        {
            Obj* pAB = ((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_009611e0_shell *>((node))->FUN_009611e0()));
            modeB = pAB->GetMode();
        }
        if (((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_00a59d30_C *>((aSrc5))->FUN_00a59d30(5))))
        {
            reinterpret_cast<::FUN_00439410_cls *>((sA))->FUN_00439410((::ArgObject *)(::fnv_00637890::Obj *)(((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_00a59d30_C *>((aSrc5))->FUN_00a59d30(5)))));
        }
        if (((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_00a59d30_C *>((aSrc5))->FUN_00a59d30(0))))
        {
            reinterpret_cast<::FUN_00439410_cls *>((sA))->FUN_00439410((::ArgObject *)(::fnv_00637890::Obj *)(((::fnv_00637890::Obj *)(reinterpret_cast<::FUN_00a59d30_C *>((aSrc5))->FUN_00a59d30(0)))));
        }
        reinterpret_cast<::ExtraOwnerB *>((sA))->FUN_00a5b230(3);
        dot4 = flag != 0;
        ct5 = new PartCtrl(count8, lit, &local7, &minPt3, &mask2, dot4, modeB);
        reinterpret_cast<::FUN_00439410_cls *>((sA))->FUN_00439410((::ArgObject *)(ct5));
        reinterpret_cast<::LowProcess *>((ct5))->SetPackageObjectType(0x1e);
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(sA), 0, 0);
        return sA;
    }
    return 0;
}
}  // namespace fnv_00637890

// FUN_00639a10: thin wrapper that queries a bit mask on the object itself.
struct FUN_00639a10_cls : public FUN_00639a30_Class
{
    int FUN_00639a10();
};

// @fnv 0x00639a10
int FUN_00639a10_cls::FUN_00639a10()
{
    return GetFlagBits(7, 0);
}

struct ContNode_620
{
    int unk;
};

struct ContHead_620
{
    int unk;
};

struct ContOwner_620 : public ContHead_620, public ContNode_620
{
    ContOwner_620* FUN_00620180();
};
// @fnv 0x00620130
void FUN_00620130_Class::FUN_00620130(BSSimpleList<int*>* pList)
{
    if (!pList)
        return;
    BSSimpleList<int*>* pNode = ((::BSSimpleList<int *> *)(reinterpret_cast<::Callees *>((this))->FUN_00726070()));
    while (pNode)
    {
        BSSimpleList<int*>* pNext = ((::BSSimpleList<int *> *)(reinterpret_cast<::ContOwner_620 *>((((FUN_00620180_Class*)pNode)))->FUN_00620180()));
        reinterpret_cast<::FUN_006206d0_Class *>(this)->FUN_006206d0((::AnimIdle *)(pNode), (int)(pList));
        pNode = pNext;
    }
}

// Returns the result of FUN_00726070 cast to ContOwner_620*.
// @fnv 0x00620180
ContOwner_620* ContOwner_620::FUN_00620180()
{
    return static_cast<ContOwner_620*>(((::ContNode_620 *)(reinterpret_cast<::Callees *>(this)->FUN_00726070())));
}

class Data620
{
  public:
    int m_iValue;
};

class Link620
{
  public:
    Link620* Unlink(Link620* pkHead);

    Link620* m_pkNext;
};

class Node620 : public Data620, public Link620
{
  public:
    ~Node620();
};

class NodeList620
{
  public:
    void RemoveNode(Node620* pkNode);

    int unk00;
    Node620* m_pkHead;
};
// @fnv 0x006206d0
void FUN_006206d0_Class::FUN_006206d0(AnimIdle* self, int a2)
{
    if (!a2)
        return;
    if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((self))->FUN_00825c00())))
        ((FUN_0057b700_class*)self)->FUN_0057b700(a2);
    if (!((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((self))->FUN_00825c00())))
        reinterpret_cast<::NodeList620 *>(this)->RemoveNode((::Node620 *)(self));
}

// If pkNode is non-null, unlinks it from the list head via Unlink and deletes it.
// @fnv 0x006205e0
void NodeList620::RemoveNode(Node620* pkNode)
{
    if (!pkNode)
        return;
    m_pkHead = static_cast<Node620*>(pkNode->Unlink(m_pkHead));
    delete pkNode;
}

extern int DAT_0104de50;
extern void* __cdecl FUN_0056d280(unsigned int);
extern void __cdecl FUN_006263c0(int);
extern void __cdecl InitHavokPhysics();
extern void __cdecl FUN_00c661d0(int);
struct Allocator622
{
    static __forceinline void* operator new(std::size_t count)
    {
        return FUN_0056d280(count);
    }
    static void operator delete(void*);
};
struct FUN_00624f90 : Allocator622
{
    unsigned int unk000;
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
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    FUN_00624f90();
};
struct FUN_00624de0 : Allocator622
{
    int unk000, unk004;
    FUN_00624de0();
};
struct GlobalObject_0045cfe0
{
};
struct AutoMemContext
{
    int unk00;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
// @fnv 0x00624bf0
void __cdecl FUN_00624bf0()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_HAVOK, true, (const char*)&DAT_0104de50, 0xac);
    char path[260];
    InitHavokPhysics();
    ::fnv_00cb0db0::FUN_00cb0db0();
    {
        FUN_00624f90* created = new FUN_00624f90;
        FUN_006263c0((int)created);
        ::fnv_006263f0::FUN_006263f0((int)(new FUN_00624de0));
        GetCurrentDirectoryA(0x104, path);
        ((FUN_00624d70_Class*)created)->ExtractTes4Prefix(path);
        FUN_00c661d0(*((int *)&(::FUN_0043d4d0((int *)(((GlobalObject_0045cfe0*)&(*reinterpret_cast<int *>(&::g_011cc2e8))))))));
    }
}

struct FUN_00626630
{
    FUN_00626630();
    ~FUN_00626630();
};

struct FUN_00626560 : public FUN_00626630
{
    FUN_00626560(int a);
};
// @fnv 0x00626450
FUN_00626450_Class* FUN_00626450_Class::FUN_00626450()
{
    new ((void *)(((FUN_00626560_Class*)this))) ::FUN_00626560(0);
    return this;
}

struct S_00626600_Guard
{
    unsigned char m_uiFilterValue;
    int FUN_004a4840(int owner, int arg);
};

struct S_00626600_Object
{
    void FUN_00626600(int arg);
};
// Constructs the object by calling the base constructor and then forwarding the argument to FUN_00626600.
// @fnv 0x00626560
FUN_00626560::FUN_00626560(int a) : FUN_00626630()
{
    reinterpret_cast<::S_00626600_Object *>(this)->FUN_00626600(a);
}

// Constructs a guard, calls its FUN_004a4840 with this and arg, then passes the result to this->EnsureCapacity.
// @fnv 0x00626600
void S_00626600_Object::FUN_00626600(int arg)
{
    S_00626600_Guard guard = {};
    reinterpret_cast<::FUN_00cb1fe0_t *>((this))->EnsureCapacity(guard.FUN_004a4840((int)this, arg), {});
}

struct GameSettingStub
{
};

struct Obj6268b0
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    Obj6268b0(float fValue, unsigned int uiValue);
    static void* operator new(std::size_t size);
    static void operator delete(void*);
};


// Returns the cached object for index 0 or 1, creating it from the corresponding float setting and FUN_005dbe10() when bCreate is set.
// @fnv 0x00626dd0
Obj6268b0* FUN_00626dd0(int iIndex, bool bCreate)
{
    Obj6268b0* pObject = 0;
    if (iIndex == 0)
    {
        if (!(*reinterpret_cast<::Obj6268b0 * *>(&::g_pD626F10Second)) && bCreate)
            (*reinterpret_cast<::Obj6268b0 * *>(&::g_pD626F10Second)) = new Obj6268b0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GameSettingStub *>(&::originalRuntimeFloatSetting58)))))), FUN_005dbe10());
        pObject = (*reinterpret_cast<::Obj6268b0 * *>(&::g_pD626F10Second));
    }
    else if (iIndex == 1)
    {
        if (!(*reinterpret_cast<::Obj6268b0 * *>(&::g_pD626F10First)) && bCreate)
            (*reinterpret_cast<::Obj6268b0 * *>(&::g_pD626F10First)) = new Obj6268b0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::GameSettingStub *>(&::originalRuntimeFloatSetting59)))))), FUN_005dbe10());
        pObject = (*reinterpret_cast<::Obj6268b0 * *>(&::g_pD626F10First));
    }
    return pObject;
}

struct FUN_00629a20_State
{
    bool value;
    int FUN_004a4840(void* owner, int input);
};
struct FUN_00629a20_Class
{
    void FUN_00629a20(int input);
};
// Calls FUN_004a4840 with this and input, then passes the returned value to FUN_00629f70.
// @fnv 0x00629a20
void FUN_00629a20_Class::FUN_00629a20(int input)
{
    FUN_00629a20_State state = {};
    reinterpret_cast<::fnv_00629f70::FUN_00629f70_Class *>(this)->FUN_00629f70(state.FUN_004a4840(this, input), {});
}

struct HeapAllocator629;

struct IsPodTag629
{
};


class IntArray629
{
  public:
    void FUN_00629ad0(HeapAllocator629& kAlloc, const int& iValue);

    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
// Calls FUN_004a4840 on this, then passes its result and a to FUN_00629ad0 on this.
// @fnv 0x006299c0
void FUN_006299c0_cls::FUN_006299c0(int a)
{
    FUN_004a4840_cls obj = {};
    reinterpret_cast<::IntArray629 *>((((FUN_00629ad0_cls*)this)))->FUN_00629ad0((*(::HeapAllocator629 *)(obj.FUN_004a4840(this))), a);
}

// Grows the array if it is at capacity, then constructs one element from iValue at the end and increments the count.
// @fnv 0x00629ad0
void IntArray629::FUN_00629ad0(HeapAllocator629& kAlloc, const int& iValue)
{
    if (m_iElementCount == ((int)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>(this)->GetSizeMasked())))
        ::ResizeAudioStream((::AudioAllocator *)&(kAlloc), (::AudioStream *)(void *)(this), sizeof(int));
    ::CopyRepeatedValue(m_data + m_iElementCount, 1, (int *)&(iValue));
    m_iElementCount++;
}

class NiTMapBase629
{
  public:
    virtual ~NiTMapBase629();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00629e50_Map : public NiTMapBase629
{
  public:
    virtual ~FUN_00629e50_Map();
};

// Destructor for the map class that calls RemoveAll to clear all entries.
// @fnv 0x00629e50
FUN_00629e50_Map::~FUN_00629e50_Map()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

// Forward this container's begin iterator (obtained through a stateless helper) to the clearing routine.

class A080Container;

struct A080Iterate
{
    void* Begin(A080Container* pkContainer);
};

class A080Container
{
  public:
    void FUN_0062a080();
};

// Clears the container starting from the position returned by A080Iterate::Begin on this container.
// @fnv 0x0062a080
void A080Container::FUN_0062a080()
{
    reinterpret_cast<::FUN_0062a0b0_Class *>(this)->FUN_0062a0b0((int)(A080Iterate().Begin(this)));
}

struct NoAllocator62A
{
};


class Range62A
{
  public:
    void* m_pvFirst;
    void* m_pvLast;

    void DestroyRange();
};
// @fnv 0x0062a0b0
void FUN_0062a0b0_Class::FUN_0062a0b0(int pTarget)
{
    reinterpret_cast<::Range62A *>((((FUN_00540b70_Class*)this)))->DestroyRange();
    if (!(m_flags & 0x80000000))
    {
        ((FUN_0062a160_Class*)pTarget)->CallVirtualWithScaledArg(*(int*)this, (int)((void *)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>((((H_A100*)this)))->GetSizeMasked())));
    }
    m_vtbl = 0;
    m_flags = 0x80000000;
}

// Destroys the elements in [m_pvFirst, m_pvLast) via DestroyRange62A, then clears m_pvLast.
// @fnv 0x0062a120
void Range62A::DestroyRange()
{
    ::FUN_0040fbe0();
    m_pvLast = 0;
}

// Smart-reference destructor: release the referenced object, then the base reference goes.

class C1A50RefBase
{
  public:
    ~C1A50RefBase();
    void Reset(void* pvObject);
    void* m_pvObject;
};

class FUN_00631a50 : public C1A50RefBase
{
  public:
    ~FUN_00631a50();
};

// Destructor that clears the referenced object by calling Reset with null.
// @fnv 0x00631a50
FUN_00631a50::~FUN_00631a50()
{
    Reset(0);
}

struct RainData
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void SetVertices(int);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void SetActive(int);
    virtual unsigned short GetActive();
};
struct RainProperty
{
};
struct RainGeometry
{
};
struct RainNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void Remove(RainNode*);
};
struct RainSmart
{
    RainNode* ptr;
    void FUN_0066b0d0(RainNode*);
};
struct RainModel
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* Path();
    int FUN_0048cee0();
};
struct RainWeather
{
    float FUN_004ed230(int, float, float);
};
struct RainState
{
};
struct RainMain
{
};
struct RainResource
{
    void* ptr;
    RainResource(int);
    ~RainResource();
};
struct RainManager
{
};
struct RainCell
{
};
struct RainPlayer
{
};
struct RainVector
{
    float x, y, z;
};
struct RainCamera
{
};
struct RainView
{
};
struct RainSystem
{
    int unk00;
    RainSmart current, previous;
    RainNode* parent;
    float total;
    RainModel* cached;
    void FUN_00636ed0(float);
};
// Updates rain particle geometry for current and previous weather, adjusting active particle counts and visibility from blend and thresholds.
// @fnv 0x00636ed0
void RainSystem::FUN_00636ed0(float elapsed)
{
    RainState* state8 = ((::RainState *)(::Sky::GetInstance()));
    bool hide10 = ((int)(reinterpret_cast<::FUN_00476c90_Class *>((state8))->FUN_00476c90())) == 1 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((state8))->FUN_00476c90())) == 0;
    RainWeather* weatherA4 = ((::RainWeather *)(reinterpret_cast<::MagicCaster_shell *>((state8))->FUN_0044edb0()));
    RainWeather* weatherB13 = ((::RainWeather *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((state8))->FUN_00825c00()));
    float blend4 = ::FUN_006447d0((const char *)(state8));
    float thresholdA103 = weatherA4 ? weatherA4->FUN_004ed230(6, 0.999f, 0.0f) : 0.0f;
    float thresholdB7 = weatherB13 ? weatherB13->FUN_004ed230(7, 1.0f, 0.001f) : 0.001f;
    if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::RainMain * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
    {
        if (((::RainNode *)(::FUN_00559450((int *)&(previous)))))
        {
            parent->Remove(((::RainNode *)(::FUN_00559450((int *)&(previous)))));
            previous.FUN_0066b0d0(0);
        }
        if (((::RainNode *)(::FUN_00559450((int *)&(current)))))
        {
            parent->Remove(((::RainNode *)(::FUN_00559450((int *)&(current)))));
            current.FUN_0066b0d0(0);
        }
        if (((::RainWeather *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((state8))->FUN_00825c00())))
            reinterpret_cast<::Precipitation *>(this)->Load(((::RainModel *)(::FUN_006377e0((int)(((::RainWeather *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((state8))->FUN_00825c00()))))))->Path());
        if (((::RainWeather *)(reinterpret_cast<::MagicCaster_shell *>((state8))->FUN_0044edb0())))
            reinterpret_cast<::Precipitation *>(this)->Load(((::RainModel *)(::FUN_006377e0((int)(((::RainWeather *)(reinterpret_cast<::MagicCaster_shell *>((state8))->FUN_0044edb0()))))))->Path());
    }
    else
    {
        if (cached)
        {
            RainModel* model = ((::RainModel *)(::FUN_006377e0((int)(weatherA4))));
            if (model && cached->FUN_0048cee0() == model->FUN_0048cee0() &&
                !FUN_00404dc0(cached->Path(), model->Path()))
            {
                const char* path10 = ((::RainModel *)(::FUN_006377e0((int)(weatherA4))))->Path();
                RainResource resource28(0);
                if (reinterpret_cast<::FUN_004472a0_shell *>(((*reinterpret_cast<::RainManager * *>(&::g_modelLoader))))->FUN_004472a0((char *)(path10), &resource28))
                {
                    cached = 0;
                    reinterpret_cast<::Precipitation *>(this)->Load(path10);
                    reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::RainManager * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)(path10));
                }
            }
            else
            {
                cached = 0;
                reinterpret_cast<::FUN_00636bd0_cls *>(this)->QueuePrecipitationObject((::PrecipQueuedObject *)(model));
            }
        }
        else if (reinterpret_cast<::FUN_00634870_shell *>((state8))->FUN_00634870() && weatherA4)
            reinterpret_cast<::FUN_00636bd0_cls *>(this)->QueuePrecipitationObject((::PrecipQueuedObject *)(::RainModel *)(((::RainModel *)(::FUN_006377e0((int)(weatherA4))))));
    }
    if (blend4 >= 1.0 && ((::RainNode *)(::FUN_00559450((int *)&(previous)))))
    {
        parent->Remove(((::RainNode *)(::FUN_00559450((int *)&(previous)))));
        previous.FUN_0066b0d0(0);
    }
    total = 0.0f;
    if (((::RainNode *)(::FUN_00559450((int *)&(current)))) || ((::RainNode *)(::FUN_00559450((int *)&(previous)))))
    {
        AddToGlobal(elapsed);
        if ((*reinterpret_cast<::RainPlayer * *>(&::_g_thePlayer)) && ((::RainCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::RainPlayer * *>(&::_g_thePlayer))))->GetTarget())) && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((((::RainCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::RainPlayer * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004518e0())
        {
            if (((::RainVector *)(::FUN_0045bb80((int)(((::RainCamera *)(::FUN_00558310((::NiNode_00558310 *)(((::RainView *)(::FUN_0045c670()))))))))))->z < reinterpret_cast<::FUN_0057b0a0_shell *>(((*reinterpret_cast<::RainPlayer * *>(&::_g_thePlayer))))->FUN_0057b0a0())
                hide10 = true;
        }
        if (((::RainNode *)(::FUN_00559450((int *)&(current)))))
        {
            float alphaA7 = 0.0f;
            if (blend4 > thresholdA103)
                alphaA7 = (blend4 - thresholdA103) / (1.0f - thresholdA103);
            int indexA3 = 0;
            while (true)
            {
                RainGeometry* geomA41 = ((::RainGeometry *)(reinterpret_cast<::NiNode *>((((::RainNode *)(::FUN_00559450((int *)&(current))))))->GetAt(indexA3++)));
                if (!geomA41)
                    break;
                RainProperty* propA13 =
                    (!((::RainProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geomA41))->FUN_00a59d30(3))) ? false : ((int)(reinterpret_cast<::BGSTerrainManager *>((((::RainProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geomA41))->FUN_00a59d30(3)))))->GetMinLevel())) == 0x12)
                        ? ((::RainProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geomA41))->FUN_00a59d30(3)))
                        : 0;
                if (propA13)
                {
                    RainGeometry* trianglesA22 = geomA41;
                    RainData* dataA10 = ((::RainData *)(::fnv_005495f0::FUN_005495f0((const char *)(trianglesA22))));
                    unsigned short perParticleA43 = reinterpret_cast<::FUN_004567e0_Class *>((dataA10))->GetShortAtOffset40() / ((int)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((propA13))->FUN_005f5f80()));
                    unsigned short particlesA3 = (unsigned short)(((int)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((propA13))->FUN_005f5f80())) * alphaA7);
                    unsigned short verticesA6 = perParticleA43 * particlesA3;
                    if (verticesA6 != dataA10->GetActive())
                    {
                        dataA10->SetActive(perParticleA43 * particlesA3);
                        if (particlesA3 > 0)
                            dataA10->SetVertices(reinterpret_cast<::TESActorBaseData *>((dataA10))->GetFatigue());
                        else
                            dataA10->SetVertices(0);
                    }
                    total += ((int)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((propA13))->FUN_005f5f80())) * alphaA7;
                }
            }
        }
        if (((::RainNode *)(::FUN_00559450((int *)&(previous)))))
        {
            float alphaB91 = 0.0f;
            if (blend4 < thresholdB7)
                alphaB91 = 1.0f - blend4 / thresholdB7;
            int indexB23 = 0;
            while (true)
            {
                RainGeometry* geomB15 = ((::RainGeometry *)(reinterpret_cast<::NiNode *>((((::RainNode *)(::FUN_00559450((int *)&(previous))))))->GetAt(indexB23++)));
                if (!geomB15)
                    break;
                RainProperty* propB11 =
                    (!((::RainProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geomB15))->FUN_00a59d30(3))) ? false : ((int)(reinterpret_cast<::BGSTerrainManager *>((((::RainProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geomB15))->FUN_00a59d30(3)))))->GetMinLevel())) == 0x12)
                        ? ((::RainProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geomB15))->FUN_00a59d30(3)))
                        : 0;
                if (propB11)
                {
                    RainGeometry* trianglesB23 = geomB15;
                    RainData* dataB18 = ((::RainData *)(::fnv_005495f0::FUN_005495f0((const char *)(trianglesB23))));
                    unsigned short perParticleB10 = reinterpret_cast<::FUN_004567e0_Class *>((dataB18))->GetShortAtOffset40() / ((int)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((propB11))->FUN_005f5f80()));
                    unsigned short particlesB22 = (unsigned short)(((int)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((propB11))->FUN_005f5f80())) * alphaB91);
                    unsigned short verticesB18 = perParticleB10 * particlesB22;
                    if (verticesB18 != dataB18->GetActive())
                    {
                        dataB18->SetActive(perParticleB10 * particlesB22);
                        if (particlesB22 > 0)
                            dataB18->SetVertices(reinterpret_cast<::TESActorBaseData *>((dataB18))->GetFatigue());
                        else
                            dataB18->SetVertices(0);
                    }
                    total += ((int)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((propB11))->FUN_005f5f80())) * alphaB91;
                }
            }
        }
    }
    if (((::RainNode *)(::FUN_00559450((int *)&(current)))))
    {
        if (hide10)
            reinterpret_cast<::TaskQueueInterface *>((((::RainNode *)(::FUN_00559450((int *)&(current))))))->QueueActorDisarm(1);
        else
            reinterpret_cast<::TaskQueueInterface *>((((::RainNode *)(::FUN_00559450((int *)&(current))))))->QueueActorDisarm(0);
    }
    if (((::RainNode *)(::FUN_00559450((int *)&(previous)))))
    {
        if (hide10)
            reinterpret_cast<::TaskQueueInterface *>((((::RainNode *)(::FUN_00559450((int *)&(previous))))))->QueueActorDisarm(1);
        else
            reinterpret_cast<::TaskQueueInterface *>((((::RainNode *)(::FUN_00559450((int *)&(previous))))))->QueueActorDisarm(0);
    }
}

class FUN_00a5d3a0
{
  public:
    FUN_00a5d3a0();
    virtual ~FUN_00a5d3a0();
    int unk04;
};

class FUN_00540830
{
  public:
    FUN_00540830(unsigned int uiMaxSize, unsigned int uiGrowBy);
    ~FUN_00540830();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class FUN_00639940
{
  public:
    FUN_00639940();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};

class FUN_00639830 : public FUN_00a5d3a0
{
  public:
    FUN_00639830(unsigned short usType, unsigned int ItemUpdateArray, int iParam);
    virtual ~FUN_00639830();
    int m_iFadeIndex;              // +0x08
    unsigned short m_usType;       // +0x0c
    unsigned int m_uiCount;        // +0x10
    FUN_00639940* m_pkEntryArray;  // +0x14
    int m_iParam;                  // +0x18
    FUN_00540830 m_kArray;         // +0x1c
};

// @fnv 0x00639830
FUN_00639830::FUN_00639830(unsigned short usType, unsigned int ItemUpdateArray, int iParam) : m_kArray(0, 1)
{
    m_iFadeIndex = 0;
    m_usType = usType;
    m_uiCount = ItemUpdateArray;
    m_pkEntryArray = new FUN_00639940[ItemUpdateArray];
    ::FUN_005e03d0((::NiTArray_Layout *)&(m_kArray));
    m_iParam = iParam;
}

class SceneNode63;
class SceneObject63
{
  public:
};
class SceneNode63
{
  public:
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
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
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
    virtual void InsertChild(SceneObject63* object);
};
class ScenePointer63
{
  public:
    SceneObject63* object;
    ~ScenePointer63();
    void operator=(int value);
};
class SkyOwned63
{
  public:
    virtual ~SkyOwned63();
};
class SkySound
{
  public:
    ~SkySound();
};
class FUN_0063a0b0
{
  public:
    virtual ~FUN_0063a0b0();
    ScenePointer63 scene;
    ScenePointer63 auxiliary;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    SkyOwned63* owned20;
    SkyOwned63* owned24;
    SkyOwned63* owned28;
    SkyOwned63* owned2c;
    SkyOwned63* owned30;
    SkyOwned63* owned34;
    SkyOwned63* owned38;
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
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    BSSimpleList<SkySound*>* sounds;
};
// Deletes the owned objects, detaches the scene object from its parent, clears both scene pointers, deletes all sounds and frees the sound list.
// @fnv 0x0063a0b0
FUN_0063a0b0::~FUN_0063a0b0()
{
    if (owned20)
        delete owned20;
    if (owned24)
        delete owned24;
    if (owned2c)
        delete owned2c;
    if (owned28)
        delete owned28;
    if (owned30)
        delete owned30;
    if (owned34)
        delete owned34;
    if (owned38)
        delete owned38;
    auxiliary = 0;
    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(scene))->operator!=(0) && ((::SceneNode63 *)(reinterpret_cast<::FUN_009611e0_shell *>((((::SceneObject63 *)(::FUN_00559450((int *)&(scene))))))->FUN_009611e0())))
        ((::SceneNode63 *)(reinterpret_cast<::FUN_009611e0_shell *>((((::SceneObject63 *)(::FUN_00559450((int *)&(scene))))))->FUN_009611e0()))->InsertChild(((::SceneObject63 *)(::FUN_00559450((int *)&(scene)))));
    scene = 0;
    for (BSSimpleList<SkySound*>* item = sounds; item && ((::SkySound *)(new ((void *)(item)) ::Vec3())); item = ((::BSSimpleList< ::SkySound *> *)(reinterpret_cast<::Callees *>((item))->FUN_00726070())))
        delete ((::SkySound *)(new ((void *)(item)) ::Vec3()));
    reinterpret_cast<::FileMatchList *>((sounds))->RemoveAll();
    delete sounds;
}

// hkFileSystem : hkReferencedObject, hkSingleton<hkFileSystem>.
struct FUN_00538ef0
{
    virtual ~FUN_00538ef0();
    unsigned short memorySizeAndFlags, referenceCount;
    FUN_00538ef0();
};
struct FUN_006815c0
{
    FUN_006815c0();
};
struct FUN_00624e00 : FUN_00538ef0, FUN_006815c0
{
    FUN_00624e00();
    virtual ~FUN_00624e00();
};
// @fnv 0x00624de0
FUN_00624de0_Class* FUN_00624de0_Class::FUN_00624de0()
{
    new ((void *)this) ::FUN_00624e00();
    m_vtbl = (int*)&DAT_0104dea4;
    return this;
}
// Constructs the object by running the base class constructors; the body is empty.
// @fnv 0x00624e00
FUN_00624e00::FUN_00624e00()
{}

struct FUN_00628f30_shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int unk10;

    void FUN_00628f70(int mask);
};

// @fnv 0x00628f70
void FUN_00628f30_shell::FUN_00628f70(int mask)
{
    unk10 &= ~mask;
}

struct ShapeList62b3
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual unsigned int GetChildShapeKey(int iKey);
    int FUN_0062b480();
    int InvokeVirtualOnResult(int iKey);
};

struct Shape62b3
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual ShapeList62b3* GetContainer();
};

struct Filter62b3
{
    unsigned int m_uiFilter;
    Filter62b3();
};

struct WorldObject62b3
{
    Filter62b3 FUN_0043b4f0();
};

extern GlobalObject_0040e0b0 g_011d0e64;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting974;

// Averages FUN_0062b1e0 over the object's child shapes (or uses the single shape), then scales by a filter-dependent multiplier and returns the mass.
// @fnv 0x0062b310
float GetObjectMass(WorldObject62b3* pkObject)
{
    float fMass = 0.0f;
    Shape62b3* pkWorldShape = ((::Shape62b3 *)(reinterpret_cast<::FUN_004ae6a0_shell *>((pkObject))->FUN_004ae6a0()));
    ShapeList62b3* pkChildList = pkWorldShape->GetContainer();
    if (pkChildList)
    {
        int iCount = 0;
        int iKey = pkChildList->FUN_0062b480();
        while (iKey != -1)
        {
            fMass += FUN_0062b1e0(pkChildList->GetChildShapeKey(iKey));
            iCount++;
            iKey = pkChildList->InvokeVirtualOnResult(iKey);
        }
        fMass /= iCount;
    }
    else
    {
        fMass = FUN_0062b1e0(reinterpret_cast<::FUN_006205a0_Class *>((pkWorldShape))->FUN_006205a0());
    }
    float fMult = 1.0f;
    Filter62b3 kFilter = pkObject->FUN_0043b4f0();
    if (reinterpret_cast<::C00624070 *>(&(kFilter))->FUN_00624070())
    {
        if (fMass > 0.0)
        {
            switch (reinterpret_cast<::bhkFilter *>(&(kFilter))->FUN_006240b0())
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 8:
            case 11:
            case 14:
                fMult = *((float *)&(::FUN_00403e20((float *)&(g_011d0e64))));
                break;
            case 6:
            case 7:
            case 9:
            case 10:
            case 12:
            case 13:
            case 15:
            case 16:
            case 22:
                fMult = *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting974))));
                break;
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
                fMult = 0.0f;
                break;
            }
        }
        else
        {
            fMult = *((float *)&(::FUN_00403e20((float *)&(g_011d0e64))));
        }
    }
    fMass *= fMult;
    return fMass;
}

struct Sub10
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct TargetObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Sub10 sub10;
};


struct ClassA
{
    void FUN_0062b480();
};

// Calls FUN_004ae750 to obtain a TargetObj from this, then invokes v2 on its sub10 member.
// @fnv 0x0062b480
void ClassA::FUN_0062b480()
{
    TargetObj* p = ((::TargetObj *)(::FUN_004ae750(this)));
    p->sub10.v2();
}

namespace fnv_0062b4b0 {
struct FUN_0062b4b0_Virtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c(int arg);
};

struct FUN_0062b4b0_Result
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_0062b4b0_Virtual unk10;
};


struct FUN_0062b4b0_Class
{
    void InvokeVirtualOnResult(int arg);
};

// Calls FUN_004ae750 on this, then invokes vf0c(arg) on the virtual object at offset 0x10 of the returned result.
// @fnv 0x0062b4b0
void FUN_0062b4b0_Class::InvokeVirtualOnResult(int arg)
{
    FUN_0062b4b0_Result* result = static_cast<FUN_0062b4b0_Result*>(((void *)(::FUN_004ae750(this))));
    result->unk10.vf0c(arg);
}
}  // namespace fnv_0062b4b0

struct FUN_0063fc70 : ObjBaseA
{
    int m_auiShapeKeys;
    GO m_go;
    float m_f;
    FUN_0063fc70();
};
// Initializes m_go to 0 and m_f to 0.0f.
// @fnv 0x0063fc70
FUN_0063fc70::FUN_0063fc70() : m_go(0)
{
    m_go = 0;
    m_f = 0.0f;
}

class PathingSolutionBase
{
  public:
    PathingSolutionBase();
    virtual ~PathingSolutionBase();
    int unk04;
};

extern int DAT_011cc1c8;

class FUN_00621d10 : public PathingSolutionBase
{
  public:
    FUN_006227e0_Holder m_kHolder;

    FUN_00621d10();
    virtual ~FUN_00621d10();
};

// After the base constructor, calls m_kHolder.FUN_006227e0(0, 1) and increments DAT_011cc1c8.
// @fnv 0x00621d10
FUN_00621d10::FUN_00621d10()
{
    m_kHolder.FUN_006227e0(0, 1);
    DAT_011cc1c8++;
}

struct TagA626
{
    int FUN_004a4840(void* pkOwner);
};

class FUN_00a29680
{
  public:
    ~FUN_00a29680();
};

class FUN_006264f0 : public FUN_00a29680
{
  public:
    ~FUN_006264f0();
};

// Destructor that calls ProcessArgument with the result of FUN_004a4840 on a temporary TagA626.
// @fnv 0x006264f0
FUN_006264f0::~FUN_006264f0()
{
    reinterpret_cast<::CB1A90Owner *>(this)->ProcessArgument((::CB1A90Argument *)(TagA626().FUN_004a4840(this)));
}

struct Node626930;
class Pointer626930
{
  public:
    ~Pointer626930();
    Pointer626930& operator=(Node626930* pkObject);
    Node626930* m_pObject;
};
class Base626930
{
  public:
    ~Base626930();
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
};
class FUN_00626930 : public Base626930
{
  public:
    ~FUN_00626930();
    Pointer626930 m_spNode;
};
// Calls FUN_00626930, then if bit 0 of flags is set calls CallWithParam on this, and returns this.
// @fnv 0x00626fa0
FUN_00626fa0_Class* FUN_00626fa0_Class::FUN_00626fa0(unsigned int flags)
{
    reinterpret_cast<::FUN_00626930 *>(this)->FUN_00626930::~FUN_00626930();
    if (flags & 1)
        CallWithParam((int)this);
    return this;
}

// Sets m_spNode to zero in the destructor of FUN_00626930.
// @fnv 0x00626930
FUN_00626930::~FUN_00626930()
{
    m_spNode = 0;
}

#include <xmmintrin.h>
struct __declspec(align(16)) BoundaryVector
{
    __m128 value;
    void FUN_006815c0();
};
struct BoundaryBox
{
    BoundaryVector min, max;
    void FUN_00437c10();
};
struct __declspec(align(16)) FUN_0056e4e0
{
    void* shape;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    BoundaryBox box;
    FUN_0056e4e0();
    ~FUN_0056e4e0();
};
struct FUN_0056e550
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FUN_0056e550(const FUN_0056e4e0*);
};
struct BoundaryPointer
{
    FUN_0056e550* ptr;
    void FUN_0066b0d0(FUN_0056e550*);
};
struct BoundaryFilter
{
    unsigned int value;
};
struct BoundaryWorld
{
};
struct BoundaryOwner
{
    int unk00, unk04;
    BoundaryPointer walls[6];
    int unk20, unk24, unk28, unk2c, unk30;
    float thickness, margin, exteriorHeight;
    void BuildWalls(TESObjectCELL*, const BoundaryBox*);
};

// Creates six boundary wall boxes around the input box using thickness and margin, then registers them with the cell's boundary world.
// @fnv 0x00627980
void BoundaryOwner::BuildWalls(TESObjectCELL* cell, const BoundaryBox* apInputBox)
{
    BoundaryWorld* world = ((::BoundaryWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((cell))->FUN_004543c0()));
    for (unsigned int i = 0; i < 6; ++i)
    {
        walls[i].FUN_0066b0d0(0);
        FUN_0056e4e0 wallDescriptor;
        BoundaryBox box;
        new ((void *)&(box)) ::fnv_00437c10::FUN_00437c10();
        BoundaryVector upperCorner;
        new ((void *)&(upperCorner)) ::Vec3();
        BoundaryVector lowerCorner;
        new ((void *)&(lowerCorner)) ::Vec3();
        float height = reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior() ? 0.0f : exteriorHeight;
        switch (i)
        {
        case 0:
            reinterpret_cast<::bhkUnaryAction *>(&(upperCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(0) + margin, reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(1) + margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(2) - thickness, 0.0f);
            reinterpret_cast<::bhkUnaryAction *>(&(lowerCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(0) - margin, reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(1) - margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(2) - margin, 0.0f);
            break;
        case 1:
            reinterpret_cast<::bhkUnaryAction *>(&(upperCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(0) + margin, reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(1) + margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(2) + margin + height, 0.0f);
            reinterpret_cast<::bhkUnaryAction *>(&(lowerCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(0) - margin, reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(1) - margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(2) + height + thickness, 0.0f);
            break;
        case 2:
            reinterpret_cast<::bhkUnaryAction *>(&(upperCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(0) + thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(1) - thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(2) + height + thickness, 0.0f);
            reinterpret_cast<::bhkUnaryAction *>(&(lowerCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(0) - thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(1) - margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(2) - thickness, 0.0f);
            break;
        case 3:
            reinterpret_cast<::bhkUnaryAction *>(&(upperCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(0) - thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(1) + margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(2) + height + thickness, 0.0f);
            reinterpret_cast<::bhkUnaryAction *>(&(lowerCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(0) - margin, reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(1) - margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(2) - thickness, 0.0f);
            break;
        case 4:
            reinterpret_cast<::bhkUnaryAction *>(&(upperCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(0) + margin, reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(1) + margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(2) + height + thickness, 0.0f);
            reinterpret_cast<::bhkUnaryAction *>(&(lowerCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(0) + thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(1) - margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(2) - thickness, 0.0f);
            break;
        case 5:
            reinterpret_cast<::bhkUnaryAction *>(&(upperCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(0) + thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(1) + margin,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(2) + height + thickness, 0.0f);
            reinterpret_cast<::bhkUnaryAction *>(&(lowerCorner))->Set(reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(0) - thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->max))->GetVectorElement(1) + thickness,
                                     reinterpret_cast<::bhkCharacterController *>((void *)&(apInputBox->min))->GetVectorElement(2) - thickness, 0.0f);
            break;
        }
        reinterpret_cast<::AlignedVector *>(&(box.max))->FUN_004a3f10((*(const ::AlignedVector *)(&upperCorner)));
        reinterpret_cast<::AlignedVector *>(&(box.min))->FUN_004a3f10((*(const ::AlignedVector *)(&lowerCorner)));
        reinterpret_cast<::S6281a0 *>(&(wallDescriptor.box))->FUN_006281a0((*(const ::S6281a0 *)(&box)));
        BoundaryFilter filter;
        wallDescriptor.shape = ((void *)(::FUN_00559450((int *)(((::BoundaryFilter *)(reinterpret_cast<::FUN_00622290_cls *>(&(filter))->FUN_00622290(0, FUN_005dbe10(), 0)))))));
        walls[i].FUN_0066b0d0(new FUN_0056e550(&wallDescriptor));
        reinterpret_cast<::FUN_0056d2c0_cls *>((world))->FUN_0056d2c0((::Arg56d2c0 *)(::FUN_0056e550 *)(((::FUN_0056e550 *)(::FUN_00559450((int *)&(walls[i]))))));
    }
}

struct Point628
{
    float x, y, z;
    void FUN_006815c0();
};
struct __declspec(align(16)) Vec628
{
    __m128 value;
};
struct __declspec(align(16)) PhysicsTransform628
{
    Vec628 row0, row1, row2, translation;
};
struct Transform628
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Point628 position;
    float scale;
};
struct __declspec(align(16)) Bounds628
{
    Vec628 min, max;
    void FUN_00437c10();
};
struct Group628
{
    void* data;
    int count, capacity;
    Group628();
    ~Group628();
};
struct Provider628;
struct Geometry628;
struct Handle628
{
};
struct Geometry628
{
};
struct Collision628
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
    virtual void bounds(void*, Bounds628*);
};
struct Provider628 : Collision628
{
};
struct Shape628
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual int type();
};
struct ShapeWrapper628
{
};
struct BodyCollection628
{
};
struct Smart628
{
    void* value;
};
struct Controller628
{
};
struct Body628
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
    virtual Collision628* collision();
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
    virtual void world(PhysicsTransform628*);
    virtual void v0f8();
    virtual void v0fc();
    virtual bool isActor();
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
    virtual int actorArg();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    Controller628* controller;
    Smart628* FUN_00931ed0(Smart628*);
};
float __cdecl FUN_00408840(float);
struct Mover628
{
    void MoveToDestination(Body628*, Group628*);
};
// Moves body, or its group, to a destination from FUN_006296d0 plus a bounds height, setting position and rotation, and zero velocity for group members.
// @fnv 0x00628f90
void Mover628::MoveToDestination(Body628* body, Group628* moved)
{
    if (body && !reinterpret_cast<::FUN_005631e0_shell *>((body))->IsNonZero(32))
    {
        Body628* reference = ((::Body628 *)(::FUN_0062b4e0(reinterpret_cast<::FUN_0043b560_shell *>((body))->GetSourceFilesFromObject())));
        Point628 destination;
        new ((void *)&(destination)) ::Vec3();
        PhysicsTransform628 world;
        new ((void *)&(world)) ::FUN_0056ded0();
        body->world(&world);
        Transform628 transform;
        reinterpret_cast<::_dummy_476a80 *>(&(transform))->FUN_00476a80();
        ::FUN_00624ad0((::NiTransform *)(::Transform628 *)(&transform), (::TopicH *)(::PhysicsTransform628 *)(&world));
        reinterpret_cast<::SpawnPlacerP *>(this)->FUN_006296d0((::TESObjectREFRP *)(reference), (const ::NiPoint3P *)(::Point628 *)(&transform.position), (::NiPoint3P *)(::Point628 *)(&destination));
        bool grouped = false;
        Point628 delta;
        reinterpret_cast<::FUN_00439ef0_class *>((void *)&(destination))->FUN_00439ef0((::NiPoint3 *)(::Point628 *)(&delta), (*(const ::NiPoint3 *)(&transform.position)));
        BodyCollection628* bodies = ((::BodyCollection628 *)(reinterpret_cast<::FUN_00620b80_shell *>((body))->GetReferenceFlags()));
        for (int scan = 0; scan < ::FUN_00c9c380((void *)(bodies), {}) && !grouped; ++scan)
        {
            Shape628* shape = ((::Shape628 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::ShapeWrapper628 *)(reinterpret_cast<::FUN_00c9c390_Class *>((bodies))->GetEntry(scan)))))->FUN_0084e3a0()));
            grouped = shape->type() != 11;
        }
        if (grouped)
        {
            Group628 group;
            ::AppendSpawnedPtr(bodies, (::SpawnedPtrArray *)(::Group628 *)(&group));
            Bounds628 bounds;
            new ((void *)&(bounds)) ::fnv_00437c10::FUN_00437c10();
            reinterpret_cast<::FUN_006295a0_shell *>(&(bounds))->FUN_006295a0();
            Collision628* collision = body->collision();
            for (int index = 0; index < ((int)(reinterpret_cast<::Callees *>(&(group))->FUN_00726070())); ++index)
            {
                Bounds628 itemBounds;
                new ((void *)&(itemBounds)) ::fnv_00437c10::FUN_00437c10();
                Provider628* provider = ((::Provider628 *)(reinterpret_cast<::LowProcess *>((collision))->GetPackageObjectType()));
                provider->bounds(((void *)(reinterpret_cast<::NonActorMagicTarget *>((((::Geometry628 *)(::FUN_00460140((int)(((::Handle628 *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(group))->FUN_00629ab0(index)))))))))->GetActiveEffectList())), &itemBounds);
                reinterpret_cast<::FUN_00629560_Class *>(&(bounds))->FUN_00629560((int)(&itemBounds.max));
                reinterpret_cast<::FUN_00629560_Class *>(&(bounds))->FUN_00629560((int)(&itemBounds.min));
            }
            ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(delta))->FUN_004a51b0(2))) += reinterpret_cast<::bhkCharacterController *>(&(bounds.max))->GetVectorElement(2) - reinterpret_cast<::bhkCharacterController *>(&(bounds.min))->GetVectorElement(2);
            for (int moveIndex = 0; moveIndex < ((int)(reinterpret_cast<::Callees *>(&(group))->FUN_00726070())); ++moveIndex)
            {
                Point628 position;
                new ((void *)&(position)) ::Vec3();
                PhysicsTransform628 bodyWorld;
                new ((void *)&(bodyWorld)) ::FUN_0056ded0();
                body->world(&bodyWorld);
                Transform628 bodyTransform;
                reinterpret_cast<::_dummy_476a80 *>(&(bodyTransform))->FUN_00476a80();
                ::FUN_00624ad0((::NiTransform *)(::Transform628 *)(&bodyTransform), (::TopicH *)(::PhysicsTransform628 *)(&bodyWorld));
                Point628 additionResult;
                position = *((::Point628 *)(reinterpret_cast<::Point3Offset *>((void *)&(bodyTransform.position))->ProjectileLaunched((::NiPoint3 *)(::Point628 *)(&additionResult), (::NiPoint3 *)(&delta))));
                Body628* member = ((::Body628 *)(::FUN_004b5a80(((::Handle628 *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(group))->FUN_00629ab0(moveIndex))))));
                if (body != member)
                    reinterpret_cast<::FUN_006299c0_cls *>((moved))->FUN_006299c0((int)(&((::Handle628 *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(group))->FUN_00629ab0(moveIndex)))));
                reinterpret_cast<::FUN_005610f0_cls *>((member))->FUN_005610f0((int)(&position));
                Vec628 rotation;
                reinterpret_cast<::FUN_005532a0_cls *>(&(rotation))->FUN_005532a0(0.0f, 0.0f, 0.01f, 0.0f);
                Vec628 velocity;
                reinterpret_cast<::FUN_005532a0_cls *>(&(velocity))->FUN_005532a0(0.0f, 0.0f, 0.0f, 0.0f);
                reinterpret_cast<::S *>((member))->FUN_00561690((std::intptr_t)(&rotation));
                reinterpret_cast<::fnv_005617c0::FUN_005617c0_ *>((member))->FUN_005617c0((std::intptr_t)(&velocity));
            }
            if (reference && reference->isActor())
            {
                Body628* actor = reference;
                if (actor->controller)
                {
                    Smart628 smart;
                    reinterpret_cast<::Manager *>((actor->controller))->FUN_00ca2ad0((void *)(reference->actorArg()), (unsigned int)(((void *)(::FUN_00559450((int *)(actor->FUN_00931ed0(&smart)))))));
                }
            }
        }
        if (!grouped)
        {
            Bounds628 soloBounds;
            new ((void *)&(soloBounds)) ::fnv_00437c10::FUN_00437c10();
            reinterpret_cast<::WorldObject_c8d3 *>((body))->GetAabb((*(::Aabb_c8d3 *)(&soloBounds)));
            float height = FUN_004587d0(reinterpret_cast<::bhkCharacterController *>(&(soloBounds.max))->GetVectorElement(2)) +
                           FUN_00408840(FUN_004587d0(reinterpret_cast<::bhkCharacterController *>(&(soloBounds.min))->GetVectorElement(2)));
            ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(destination))->FUN_004a51b0(2))) += height;
            reinterpret_cast<::FUN_005610f0_cls *>((body))->FUN_005610f0((int)(&destination));
            Vec628 rotation;
            reinterpret_cast<::FUN_005532a0_cls *>(&(rotation))->FUN_005532a0(0.0f, 0.0f, 0.01f, 0.0f);
            reinterpret_cast<::S *>((body))->FUN_00561690((std::intptr_t)(&rotation));
        }
    }
}

struct LocalSoundHandle
{
    int unk00, unk04, unk08;
    LocalSoundHandle();
    ~LocalSoundHandle();
};
struct FUN_00639bf0
{
    LocalSoundHandle handle;
    int unk0c, unk10, unk14, unk18;
    FUN_00639bf0(LocalSoundHandle, int, int, int);
};
// Copies sound into handle, stores a, b and c in unk0c, unk10 and unk14, and zeroes unk18.
// @fnv 0x00639bf0
FUN_00639bf0::FUN_00639bf0(LocalSoundHandle sound, int a, int b, int c)
{
    reinterpret_cast<::SoundPlaybackHandle *>(&(handle))->operator=((*(const ::SoundPlaybackHandle *)(&sound)));
    unk0c = a;
    unk10 = b;
    unk14 = c;
    memset(&unk18, 0, sizeof(unk18));
}

class NiAVObject;

template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer(NiAVObject* object = 0);
    ~NiPointer();
    NiPointer<NiAVObject>& operator=(const NiPointer<NiAVObject>& other);
    bool operator==(const NiPointer<NiAVObject>& other) const;
    bool operator!=(const NiPointer<NiAVObject>& other) const;
};

struct FUN_00622920_Array
{
    void* m_vtbl;
    NiPointer<NiAVObject>* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetAt(unsigned int uiIndex, const NiPointer<NiAVObject>& element);
};

// Sets the element at uiIndex in m_pBase, updating m_usSize and m_usESize to track the array's logical size and non-null element count.
// @fnv 0x00622920
void FUN_00622920_Array::SetAt(unsigned int uiIndex, const NiPointer<NiAVObject>& element)
{
    static NiPointer<NiAVObject> kZero(0);
    if (uiIndex >= m_usSize)
    {
        m_usSize = uiIndex + 1;
        if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(element))->IsNotEqual((const ::DummyStruct_00631820 &)(kZero)))
        {
            m_usESize++;
        }
    }
    else
    {
        if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(element))->IsNotEqual((const ::DummyStruct_00631820 &)(kZero)))
        {
            if (reinterpret_cast<::FUN_004b0460_class *>((void *)&(const ::NiPointer< ::NiAVObject> &)(m_pBase[uiIndex]))->FUN_004b0460((const void **)&(kZero)))
            {
                m_usESize++;
            }
        }
        else
        {
            if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(m_pBase[uiIndex]))->IsNotEqual((const ::DummyStruct_00631820 &)(kZero)))
            {
                m_usESize--;
            }
        }
    }
    m_pBase[uiIndex] = element;
}

namespace fnv_00629a80 {
struct FUN_00629a80_Class
{
    int a;
    int b;
    int c;
    FUN_00629a80_Class* FUN_00629a80();
};

// @fnv 0x00629a80
FUN_00629a80_Class* FUN_00629a80_Class::FUN_00629a80()
{
    a = 0;
    b = 0;
    c = 0x80000000;
    return this;
}
}  // namespace fnv_00629a80

struct FUN_0062a020 : FUN_00629eb0_Class
{
    virtual ~FUN_0062a020();
};
// @fnv 0x0062a020
FUN_0062a020::~FUN_0062a020()
{}

struct CB75D0Base
{
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    CB75D0Base();
    virtual ~CB75D0Base();
};

struct SecBase14
{
    int m_04;
    SecBase14();
    virtual ~SecBase14();
};

struct Member34
{
    int m_00;
    int m_04;
    int m_08;
    Member34();
    ~Member34();
};


struct FUN_0062e780 : CB75D0Base, SecBase14
{
    float m_1c;
    int* m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    Member34 m_34;
    FUN_0062e780();
    virtual ~FUN_0062e780();
};

// Initializes m_1c to 1.0f, reads a size from g_011c63cc into m_28, and allocates an int array of m_28 squared elements into m_20.
// @fnv 0x0062e780
FUN_0062e780::FUN_0062e780() : m_1c(1.0f)
{
    m_28 = *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))));
    int iSize = m_28 * m_28;
    m_20 = new int[iSize];
}

struct GlobalObject_00631850
{
    ~GlobalObject_00631850();
};
struct FUN_00631880 : GlobalObject_00631850
{
    virtual ~FUN_00631880();
};
// Empty destructor for FUN_00631880, a subclass of GlobalObject_00631850.
// @fnv 0x00631880
FUN_00631880::~FUN_00631880()
{}

namespace fnv_00632ec0 {
extern int DAT_0104e6ac;
struct INISettingCollection
{
    INISettingCollection();
};
struct FUN_00632ec0 : INISettingCollection
{
    FUN_00632ec0();
};
// @fnv 0x00632ec0
FUN_00632ec0::FUN_00632ec0()
{
    ((int*)this)[0] = (int)&DAT_0104e6ac;
}
}  // namespace fnv_00632ec0

struct FUN_00632f60
{
    virtual ~FUN_00632f60();
};
// @fnv 0x00632f60
FUN_00632f60::~FUN_00632f60()
{}

struct ZoneTargetListenerView : FUN_00620110_Class
{
    FUN_00620180_Class* firstZone;
};
struct FUN_00620230_DeleteView
{
    ~FUN_00620230_DeleteView();
};
// Deletes every node in the firstZone linked list and sets firstZone to null.
// @fnv 0x006201c0
void FUN_00620110_Class::FUN_006201c0()
{
    FUN_00620180_Class* current = static_cast<ZoneTargetListenerView*>(this)->firstZone;
    while (current)
    {
        FUN_00620180_Class* next = reinterpret_cast<FUN_00620180_Class*>(((::BSSimpleList<int *> *)(reinterpret_cast<::ContOwner_620 *>((current))->FUN_00620180())));
        delete reinterpret_cast<FUN_00620230_DeleteView*>(current);
        current = next;
    }
    static_cast<ZoneTargetListenerView*>(this)->firstZone = 0;
}

#include "generated/data/staging/blk_00620000_od.inc"
