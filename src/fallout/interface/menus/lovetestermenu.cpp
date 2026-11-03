
// src/fallout/interface/menus/lovetestermenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/lovetestermenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/decl/AnimationSequence.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CamLook.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_00792780_Class.h"
#include "fnv/decl/FUN_007c9dc0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0093a7c0_Owner.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a24180_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/NiPointLight.h"
#include "fnv/decl/S148c0.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Tile.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_007fd640__FUN_007fd640Class.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00791000.h"
#include "fnv/symbols_00794000.h"
#include "fnv/symbols_00795000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01074000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01203000.h"
struct FUN_00791a80_shell
{
    void FUN_00795dc0();
    void* FUN_00791a80(unsigned int flags);
};

struct Flt
{
    operator unsigned int();
};
struct Glob
{
    char _0[0x208];
    Flt ff;
};
struct Inner
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void Target(int, int, unsigned int);
};
struct Outer
{
    char _0[12];
    Inner* q;
};
// @fnv 0x00795780
void FUN_00795780(Outer* pOuter)
{
    pOuter->q->Target(0, 0, DAT_011da2c8->ff);
}

struct GO
{
    GO& operator=(void*);
    ~GO();
};
struct FUN_00795dc0
{
    char _pad[8];
    GO m;
    ~FUN_00795dc0();
};
// @fnv 0x00791a80
void* FUN_00791a80_shell::FUN_00791a80(unsigned int flags)
{
    reinterpret_cast<::FUN_00795dc0 *>(this)->FUN_00795dc0::~FUN_00795dc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00795dc0
FUN_00795dc0::~FUN_00795dc0()
{
    m = 0;
}

namespace fnv_00795390 {
struct Flt
{
    int v;
    operator unsigned int();
};
struct InnerV
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual int m7(int);
};
struct PC7d
{
    char _pad[0xA4];
    InnerV inner;
};
struct Holder00795390
{
    char _pad[0x1C4];
    Flt arr[1];
};
struct Target00795390
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60(int, int, unsigned int);
};
struct Param00795390
{
    int unk0;
    Target00795390* unk4;
    char pad8[12];
    int unk14;
};
// Calls m7 on the player's inner object with p->unk14, then invokes f60 on p->unk4 using the indexed arr entry from DAT_011da2c8.
// @fnv 0x00795390
void FUN_00795390(Param00795390* pParam)
{
    int t = (*reinterpret_cast<::fnv_00795390::PC7d * *>(&::_g_thePlayer))->inner.m7(pParam->unk14);
    pParam->unk4->f60(0, 0, (unsigned int)(*reinterpret_cast<::fnv_00795390::Holder00795390 * *>(&::DAT_011da2c8))->arr[t]);
}
}  // namespace fnv_00795390

namespace fnv_00795c60 {
struct LoveTesterMenu
{
    char _pad[0x54];
    bool m_bState54;
    void StepPosition(int);
    void FUN_00795e20();
};


// If the LoveTesterMenu singleton exists and its flag is set, calls StepPosition with 1 and then FUN_00795e20 on it.
// @fnv 0x00795c60
void FUN_00795c60()
{
    if ((*reinterpret_cast<::fnv_00795c60::LoveTesterMenu * *>(&::DAT_011da2c8)) && (*reinterpret_cast<::fnv_00795c60::LoveTesterMenu * *>(&::DAT_011da2c8))->m_bState54)
    {
        (*reinterpret_cast<::fnv_00795c60::LoveTesterMenu * *>(&::DAT_011da2c8))->StepPosition(1);
        (*reinterpret_cast<::fnv_00795c60::LoveTesterMenu * *>(&::DAT_011da2c8))->FUN_00795e20();
    }
}
}  // namespace fnv_00795c60

namespace fnv_00795ca0 {
struct LoveTesterMenu
{
    char pad[0x54];
    bool m_bState54;
    void StepPosition(int);
    void FUN_00795e20();
};


// @fnv 0x00795ca0
void __cdecl FUN_00795ca0()
{
    if ((*reinterpret_cast<::fnv_00795ca0::LoveTesterMenu * *>(&::DAT_011da2c8)) && (*reinterpret_cast<::fnv_00795ca0::LoveTesterMenu * *>(&::DAT_011da2c8))->m_bState54)
    {
        (*reinterpret_cast<::fnv_00795ca0::LoveTesterMenu * *>(&::DAT_011da2c8))->StepPosition(0);
        (*reinterpret_cast<::fnv_00795ca0::LoveTesterMenu * *>(&::DAT_011da2c8))->FUN_00795e20();
    }
}
}  // namespace fnv_00795ca0

struct FUN_00794d30_shell
{
    int FUN_00794d30();
};
int FUN_00794d80(void*);

struct AVOwner_007927a0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int GetValue(int aiIndex);
};
struct Player_007927a0
{
    char _pad[0xa4];
    AVOwner_007927a0 avOwner;
};

struct FUN_007927a0_shell
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
    char _pad[0x54];
    int m_iEntryCount;
    bool HandleKeyInput(int aiKey);
};

// @fnv 0x007927a0
bool FUN_007927a0_shell::HandleKeyInput(int aiKey)
{
    switch (aiKey)
    {
    case '+':
    case '=':
    case 0x80000003: {
        int iIndex = ((FUN_00794d30_shell*)this)->FUN_00794d30();
        if (iIndex != -1 && FUN_00794d80(this) < m_iEntryCount && (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(iIndex) < 10)
        {
            f3(2, 0);
            return true;
        }
        break;
    }
    case '-':
    case '_':
    case 0x80000004: {
        int iIndex2 = ((FUN_00794d30_shell*)this)->FUN_00794d30();
        if (iIndex2 != -1 && (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(iIndex2) > 1)
        {
            f3(3, 0);
            return true;
        }
        break;
    }
    case 0x80000001:
    case 0x80000002:
        f3(aiKey == 0x80000001, 0);
        return true;
    }
    return false;
}

// Sums the player's avOwner values for indices 5 through 11 and returns the total.
// @fnv 0x00794d80
int FUN_00794d80(void* apUnused)
{
    return (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(5) + (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(6) + (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(7) +
           (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(8) + (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(9) + (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(10) +
           (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(11);
}

// @fnv 0x00795700
void SetTargetFromGlobalState(Outer* apOuter)
{
    if (*(unsigned int*)((char*)DAT_011da2c8 + 0x48) == 8 &&
        FUN_00794d80(DAT_011da2c8) < *(int*)((char*)DAT_011da2c8 + 0x58))
        apOuter->q->Target(0, 0, (unsigned int)*(Flt*)((char*)DAT_011da2c8 + 0x200));
    else
        apOuter->q->Target(0, 0, (unsigned int)*(Flt*)((char*)DAT_011da2c8 + 0x204));
}

struct Date
{
    int _0;
    int _4;
    int _8;
    ~Date();
};

struct SoundPlaybackHandle
{
    int _0;
    int _4;
    int _8;
    ~SoundPlaybackHandle();
    bool Play();
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
};

struct BSAudio
{
    static BSAudio* __cdecl GetSingleton(void);
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int, bool);
};

struct LoveTesterMenu
{
    char _0[0x58];
    int m_iEntryCount;
};

void __cdecl FUN_007917a0(void);
extern int _data_011c16bc;

// @fnv 0x00795ce0
void __cdecl FUN_00795ce0(void* apButton)
{
    if (DAT_011da2c8 && FUN_00794d80(DAT_011da2c8) == reinterpret_cast<LoveTesterMenu*>(DAT_011da2c8)->m_iEntryCount)
    {
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialNumberFinished", 0x121, false)))->FUN_00ad8830({});
        FUN_007917a0();
    }
    else
    {
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIActivateNothing", 0x121, false)))->FUN_00ad8830({});
    }
}

struct RendererHelper
{
};
struct CameraHelper
{
};
struct ManagerHelper
{
};
struct InterfaceHelper
{
};
struct NP
{
    int value;
    NP(int);
    ~NP();
    operator int() const;
};
// @fnv 0x007948d0
void FUN_007948d0()
{
    if (!DAT_011da2c8 || !(unsigned int)(*reinterpret_cast<::Flt *>(&::g_011da2f4)))
        return;
    reinterpret_cast<::S148c0 *>((((::RendererHelper *)(::FUN_0043c4b0()))))->FUN_007148c0(0, 4);
    ManagerHelper* manager = ((::ManagerHelper *)(::FUN_0045c670()));
    CameraHelper* camera = ((::CameraHelper *)(reinterpret_cast<::MiddleLowProcess *>((manager))->GetProcessInteger()));
    reinterpret_cast<::FUN_00c4f270_Class *>((camera))->FUN_00c4f270(true);
    unsigned int localNode = (unsigned int)(*reinterpret_cast<::Flt *>(&::g_011da2f4));
    ::UpdateCameraFrustum((::NiCamera *)(localNode), 0.65f);
    NP node(((int)(reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((((::InterfaceHelper *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007fd640())));
    reinterpret_cast<::FUN_004a0fd0_shell *>((camera))->FUN_004a0fd0((::NiNode *)((int)node));
    ::FUN_00b6bee0((void *)(localNode), ((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))), (::BSShaderAccumulator *)(camera));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(localNode), (::BSShaderAccumulator *)((int)node), 0);
    reinterpret_cast<::FUN_004a0fd0_shell *>((camera))->FUN_004a0fd0((::NiNode *)(0));
    reinterpret_cast<::FUN_00c4f2d0_class *>((camera))->FUN_00c4f2d0();
}

struct NiFixedString
{
    const char* m_kHandle;
    NiFixedString(const char* s);
    ~NiFixedString();
};

struct NiProperty
{
};

struct NiAVObject
{
};

struct NiNode
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0a();
    virtual void f0b();
    virtual void f0c();
    virtual void f0d();
    virtual void f0e();
    virtual void f0f();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f1a();
    virtual void f1b();
    virtual void f1c();
    virtual void f1d();
    virtual void f1e();
    virtual void f1f();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual NiAVObject* GetObjectByName(const NiFixedString& name);
};

struct SceneGlob
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
    NiNode* root;
};

template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* p);
    ~NiPointer();
    NiPointer& operator=(T* p);
};

struct FUN_00794e70
{
    int unk00;
    int unk04;
    NiPointer<NiAVObject> spRetainedObject;
    NiProperty* pProperty;
    FUN_00794e70(int a, int b, const char* name);
};

// Stores two ints, looks up a scene object by name, and stores its property 3 if its type is between 8 and 12, else null.
// @fnv 0x00794e70
FUN_00794e70::FUN_00794e70(int iFirst, int iSecond, const char* pcObjectName) : spRetainedObject(0)
{
    unk00 = iFirst;
    unk04 = iSecond;
    spRetainedObject = ((SceneGlob*)DAT_011da2c8)->root->GetObjectByName(NiFixedString(pcObjectName));
    NiAVObject* obj = ((SceneGlob*)DAT_011da2c8)->root->GetObjectByName(NiFixedString(pcObjectName));
    pProperty = (!((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((obj))->FUN_00a59d30(3))) ? false : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((obj))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((obj))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((obj))->FUN_00a59d30(3)))
                    : 0;
}

namespace fnv_007950b0 {
struct NiFixedString
{
    const char* m_kHandle;
    NiFixedString(const char* pcString);
    ~NiFixedString();
};

struct NiProperty
{
};

struct NiAVObject
{
};

struct NodeSource
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual NiAVObject* GetObjectByName(const NiFixedString& kName);
};

struct NodeSourceHolder
{
    int unk00[23];
    NodeSource* unk5C;
    NodeSource* unk60;
};

struct FUN_007950b0
{
    int unk00;
    NiProperty* unk04;
    NiProperty* unk08;
    NiAVObject* unk0C;
    NiAVObject* unk10;
    int unk14;
    int unk18;

    FUN_007950b0(int a1, const char* pcName, const char* pcName2, int a4, bool bFirst, int a6);
};

// Looks up two named NiAVObjects on one of two scene nodes and stores their property of type 3 when its value is between 8 and 12.
// @fnv 0x007950b0
FUN_007950b0::FUN_007950b0(int a1, const char* pcObjectName, const char* pcSecondObjectName, int aiParam4,
                           bool abUseFirstNode, int aiParam6)
{
    unk00 = a1;
    unk14 = aiParam4;
    unk18 = aiParam6;
    if (abUseFirstNode)
        unk0C = ((NodeSourceHolder*)DAT_011da2c8)->unk5C->GetObjectByName(NiFixedString(pcObjectName));
    else
        unk0C = ((NodeSourceHolder*)DAT_011da2c8)->unk60->GetObjectByName(NiFixedString(pcObjectName));
    unk04 = (((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk0C))->FUN_00a59d30(3))) == 0
                 ? 0
                 : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk0C))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk0C))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                ? ((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk0C))->FUN_00a59d30(3)))
                : 0;
    if (pcSecondObjectName)
    {
        if (abUseFirstNode)
            unk10 = ((NodeSourceHolder*)DAT_011da2c8)->unk5C->GetObjectByName(NiFixedString(pcSecondObjectName));
        else
            unk10 = ((NodeSourceHolder*)DAT_011da2c8)->unk60->GetObjectByName(NiFixedString(pcSecondObjectName));
        unk08 = (((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk10))->FUN_00a59d30(3))) == 0
                     ? 0
                     : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk10))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk10))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::fnv_007950b0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((unk10))->FUN_00a59d30(3)))
                    : 0;
    }
    else
    {
        unk10 = 0;
        unk08 = 0;
    }
}
}  // namespace fnv_007950b0

struct NiAVObjectS
{
};
struct DigitString
{
    unsigned int ptr;
    unsigned int get()
    {
        return ((Flt*)this)->operator unsigned int();
    }
};
struct DigitGlobals
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
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    DigitString digits[10];
};
struct DigitView
{
    int unk00;
    Inner* tens;
    Inner* ones;
    NiAVObjectS* tensVisibility;
    NiAVObjectS* onesVisibility;
};
// @fnv 0x007953f0
void __cdecl UpdateDigitDisplay(DigitView* view)
{
    if (!view->tens || !view->ones)
        return;
    int ones = ((LoveTesterMenu*)DAT_011da2c8)->m_iEntryCount - FUN_00794d80(DAT_011da2c8);
    int value = (ones / 10 < 9 ? ones / 10 : 9) > 0 ? (ones / 10 < 9 ? ones / 10 : 9) : 0;
    int tens = ones % 10 < 0 ? 0 : ones % 10;
    if (value > 0)
    {
        reinterpret_cast<::TaskQueueInterface *>((view->tensVisibility))->QueueActorDisarm(false);
        view->tens->Target(0, 0, ((unsigned int)(::FUN_00559450((int *)&(((DigitGlobals*)DAT_011da2c8)->digits[value])))));
    }
    else
    {
        reinterpret_cast<::TaskQueueInterface *>((view->tensVisibility))->QueueActorDisarm(false);
        view->tens->Target(0, 0, ((unsigned int)(::FUN_00559450((int *)&(((DigitGlobals*)DAT_011da2c8)->digits[0])))));
    }
    reinterpret_cast<::TaskQueueInterface *>((view->onesVisibility))->QueueActorDisarm(false);
    view->ones->Target(0, 0, ((unsigned int)(::FUN_00559450((int *)&(((DigitGlobals*)DAT_011da2c8)->digits[tens])))));
}

// Uses pack declarations already in scope: AVOwner_007927a0, Player_007927a0,
// g_thePlayer, Glob, DAT_011da2c8 (extern Glob*). GlobView below adds named
// fields at the offsets this function accesses; the pack's Glob stand-in cannot
// be redefined, so the global pointer is viewed through this layout.
struct GlobView_00795580
{
    char _pad[0x48];
    int m48;
    int m4c;
};

struct Entry_00795580
{
};
struct List_00795580
{
};
struct Menu_00795580
{
    char _0[8];
    List_00795580 m8;
    char _1[0x1b];
    int m24;
};


// @fnv 0x00795580
void __cdecl UpdateMenuEntryState(Menu_00795580* pMenu)
{
    int iVar1 = pMenu->m24;
    if (iVar1 != -1)
    {
        if ((*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(iVar1) > 1)
            reinterpret_cast<::TaskQueueInterface *>((((::Entry_00795580 *)(::FUN_00559450((int *)&(pMenu->m8))))))->QueueActorDisarm({});
        else
            reinterpret_cast<::TaskQueueInterface *>((((::Entry_00795580 *)(::FUN_00559450((int *)&(pMenu->m8))))))->QueueActorDisarm({});
        if (((unsigned char)(::FUN_004b71d0())) && ((GlobView_00795580*)DAT_011da2c8)->m48 == 8 &&
            iVar1 != ((GlobView_00795580*)DAT_011da2c8)->m4c + 4)
            reinterpret_cast<::TaskQueueInterface *>((((::Entry_00795580 *)(::FUN_00559450((int *)&(pMenu->m8))))))->QueueActorDisarm({});
    }
}

struct BSSoundHandleEx
{
    unsigned int id;
    unsigned int state;
    unsigned int flags;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    void operator=(const BSSoundHandleEx&);
    bool Play(bool);
};
struct AudioView
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
extern const char DAT_010747c4[];
struct PlayerSetter
{
};
void FUN_00795e20(Glob*);
struct CallbackInput
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int actorValue;
};
// @fnv 0x007957c0
void __cdecl FUN_007957c0(CallbackInput* input)
{
    if (!DAT_011da2c8)
        return;
    int value = input->actorValue;
    if (value != -1)
    {
        int count = (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(value);
        if (count > 1)
        {
            BSSoundHandleEx sound;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(((AudioView*)::FUN_00453a70())->GetSoundHandleByEditorID(DAT_010747c4, 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        reinterpret_cast<::FUN_0093a7c0_Owner *>((((PlayerSetter*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(value), FUN_00647b70(count - 1, 1));
    }
    FUN_00795e20(DAT_011da2c8);
}

namespace fnv_007958e0 {
struct AudioPlaybackHandle
{
    int id, state, flags;
    AudioPlaybackHandle();
    ~AudioPlaybackHandle();
    void Copy(const void*);
    bool Play(bool);
};
struct BSSoundHandleEx
{
    int id, state, flags;
    ~BSSoundHandleEx();
};
struct GlobalObject_0041a250
{
    int id, state, flags;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    void FUN_copy(const void*);
    bool FUN_00ad8830(bool);
};
struct SH_00418890
{
    int id, state, flags;
    void FUN_copy(const void*);
};
struct BSAudioS_
{
    static BSAudio* GetSingleton();
};
struct Audio
{
    BSSoundHandleEx FUN_00ad7550(const char*, unsigned int);
};
struct FUN_00ad8830_shell
{
    bool FUN_00ad8830(bool);
};
struct Menu
{
    void FUN_00795e20();
};
struct PlayerOps
{
};
// @fnv 0x007958e0
void FUN_007958e0()
{
    if (!DAT_011da2c8)
        return;
    int index = ((FUN_00794d30_shell*)DAT_011da2c8)->FUN_00794d30();
    if (index != -1)
    {
        int value = (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(index);
        if (value > 1)
        {
            GlobalObject_0041a250 sound;
            reinterpret_cast<::SoundPlaybackHandle *>((((SH_00418890*)&sound)))->operator=((*(const ::SoundPlaybackHandle *)(&((Audio*)::FUN_00453a70())->FUN_00ad7550("OBJBookSpecialNumberDown", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>((((FUN_00ad8830_shell*)&sound)))->FUN_00ad8830(false);
        }
        reinterpret_cast<::FUN_0093a7c0_Owner *>((((PlayerOps*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(index), ::FUN_00647b70(value - 1, 1));
    }
    ((Menu*)DAT_011da2c8)->FUN_00795e20();
}
}  // namespace fnv_007958e0

namespace fnv_00796100 {
class NiSourceTexture
{
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
struct TES
{
};
extern const char str_01074cc0[];
extern const char str_01074c9c[];
extern const char str_01074c78[];
extern const char str_01074c58[];
extern const char str_01074c2c[];
struct This796
{
    char _0[0x1c4];
    NiPointer<NiSourceTexture> tex[27];
    void FUN_00796100();
};
// Builds texture paths with _sprintf_s and FUN_004b7240, then creates each texture via g_TES->CreateTextureImage into tex[0..26].
// @fnv 0x00796100
void This796::FUN_00796100()
{
    char bufB[0x104];
    char bufA5[0x108];
    char plat[8];
    int i3;
    int j;
    ::FUN_00406d00(bufA5, 0x104, ::DAT_0101996c, str_01074c9c, str_01074cc0);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[25]), false, false);
    ::FUN_00406d00(bufA5, 0x104, ::DAT_0101996c, str_01074c9c, str_01074c78);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[26]), false, false);
    for (i3 = 0; i3 < 11; i3++)
    {
        ::FUN_00406d00(bufA5, 0x104, str_01074c4c, str_01074c58, str_01074c6c, i3);
        ::ConvertLocalizedString(bufA5, bufB, 0x104);
        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[i3]), false, false);
    }
    for (j = 1; j < 5; j++)
    {
        ::FUN_00406d00(bufA5, 0x104, str_01074c4c, str_01074c9c, str_01074c40, j);
        ::ConvertLocalizedString(bufA5, bufB, 0x104);
        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[j + 10]), false, false);
    }
    if (::FUN_00709d40())
    {
        ::TaskQueueInterface::CopyStringToBuffer(plat, 5, str_0101fd1c);
    }
    else
    {
        ::TaskQueueInterface::CopyStringToBuffer(plat, 5, str_0101fd24);
    }
    ::FUN_00406d00(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c38);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[16]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c24);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[15]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c1c);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[17]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c08, str_01074c9c, str_01074c14);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[18]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c00);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[19]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074bf8);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[20]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c08, str_01074c58, str_01074be8);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[21]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c08, str_01074c58, str_01074bd8);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[22]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c08, str_01074c58, str_01074bc8);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[23]), false, false);
    ::FUN_00406d00(bufA5, 0x104, str_01074c08, str_01074c58, str_01074bb8);
    ::ConvertLocalizedString(bufA5, bufB, 0x104);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00796100::TES * *>(&::g_TES))))->FUN_004568c0(bufB, (::TexPtr< ::NiSourceTexture> &)(tex[24]), false, false);
}
}  // namespace fnv_00796100

struct ResetArray
{
    unsigned int count, capacity, data, grow;
};
struct ResetGroup
{
    ResetArray objects, allocations;
};
struct ResetView
{
    unsigned int unk00;
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
    unsigned int counter5c, counter60;
    ResetArray list64, list74;
    ResetGroup groups[9];
    ResetArray list1a4, list1b4;
};
struct ResetResourceManager
{
};
struct ResetPlayer
{
};
struct ResetString
{
    void FUN_0066b0d0(int);
};
struct IntegerBooleanHandler
{
};
// @fnv 0x007917a0
void __cdecl FUN_007917a0()
{
    int menu;
    unsigned int m, j, k, l;
    IntegerBooleanHandler* i = ((::IntegerBooleanHandler *)(::FUN_00a09030((int)(((void *)(::FUN_00791740()))))));
    if (!i)
        return;
    reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::ResetResourceManager * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)("Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Activate.NIF"));
    reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::ResetResourceManager * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)("Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Cabinet.NIF"));
    reinterpret_cast<::FUN_004def90_Class *>((((ResetPlayer*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))))->FUN_004def90();
    reinterpret_cast<::MultiBoundManagerB5D *>((((ResetPlayer*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))))->FUN_00b5d180();
    ((ResetView*)DAT_011da2c8)->counter5c = 0;
    ((ResetView*)DAT_011da2c8)->counter60 = 0;
    ((ResetString*)&(*reinterpret_cast<::Flt *>(&::g_011da2f4)))->FUN_0066b0d0(0);
    for (menu = 0; menu < 9; menu++)
    {
        for (k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(((ResetView*)DAT_011da2c8)->groups[menu].objects))->GetName())); k++)
        {
            FUN_00791a80_shell* object = *((::FUN_00791a80_shell **)(reinterpret_cast<::S3e60 *>(&(((ResetView*)DAT_011da2c8)->groups[menu].objects))->FUN_006a7ad0(k)));
            FUN_00791a80_shell* doomed = object;
            doomed ? doomed->FUN_00791a80(1) : 0;
        }
        for (l = 0; l < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(((ResetView*)DAT_011da2c8)->groups[menu].allocations))->GetName())); l++)
        {
            FUN_00791a80_shell* allocation = *((::FUN_00791a80_shell **)(reinterpret_cast<::S3e60 *>(&(((ResetView*)DAT_011da2c8)->groups[menu].allocations))->FUN_006a7ad0(l)));
            ::FUN_00401030(allocation);
        }
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((ResetView*)DAT_011da2c8)->groups[menu].objects))->Clear(1);
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((ResetView*)DAT_011da2c8)->groups[menu].allocations))->Clear(1);
    }
    for (j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(((ResetView*)DAT_011da2c8)->list1a4))->GetName())); j++)
    {
        FUN_00791a80_shell* object = *((::FUN_00791a80_shell **)(reinterpret_cast<::S3e60 *>(&(((ResetView*)DAT_011da2c8)->list1a4))->FUN_006a7ad0(j)));
        FUN_00791a80_shell* doomed = object;
        doomed ? doomed->FUN_00791a80(1) : 0;
    }
    for (m = 0; m < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(((ResetView*)DAT_011da2c8)->list1b4))->GetName())); m++)
    {
        FUN_00791a80_shell* allocation = *((::FUN_00791a80_shell **)(reinterpret_cast<::S3e60 *>(&(((ResetView*)DAT_011da2c8)->list1b4))->FUN_006a7ad0(m)));
        ::FUN_00401030(allocation);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((ResetView*)DAT_011da2c8)->list1a4))->Clear(1);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((ResetView*)DAT_011da2c8)->list1b4))->Clear(1);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((ResetView*)DAT_011da2c8)->list64))->Clear(1);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((ResetView*)DAT_011da2c8)->list74))->Clear(1);
    if (DAT_011da2c8)
    {
        reinterpret_cast<::Tile *>((i))->Set(6002, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((((ResetView*)DAT_011da2c8)))->FUN_00a1d910();
    }
}

struct Controls
{
};
struct OSGlobals
{
};
struct InventoryMenuSetting
{
};
bool FUN_00702450(int);
extern const char DAT_0101fd00[];
struct NiUpdateData
{
    float time;
    bool updateControllers, isMT, updateGeom, updateShadow, updateBounds;
    NiUpdateData(float, bool, bool);
};
struct NiControllerSequence
{
    void Update(float, bool);
};
struct NiTimeController
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
    virtual void Update(const NiUpdateData&);
};
struct ModelOps
{
};
struct NiRTTI;
union AnimationNames
{
    bool enabled;
    const char* names[9];
};
struct TimeGlobal
{
};
struct MenuAnimation
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void HandleClick(int, int);
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int animationIndex;
    int unk4c;
    float elapsed;
    bool finished;
    int availablePoints;
    ModelOps* model;
    void UpdateAnimation();
};
// @fnv 0x00791ab0
void MenuAnimation::UpdateAnimation()
{
    if (!FUN_00702450(0x432))
        return;
    Controls* current = reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720();
    int input = 30;
    if (!FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011c3cb4))))->GetMenuTitle())), DAT_0101fd00))
        input = 16;
    if (reinterpret_cast<::FUN_00a24180_shell *>((current))->FUN_00a24180(input, 1))
    {
        HandleClick(4, 0);
        return;
    }
    NiTimeController* iter = ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(model))));
    if (iter)
    {
        NiTimeController* manager = iter;
        NiControllerSequence* sequence = 0;
        if (!(*reinterpret_cast<::AnimationNames *>(&::increasing170)).enabled || animationIndex > 0)
            sequence = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString((*reinterpret_cast<::AnimationNames *>(&::increasing170)).enabled ? (*reinterpret_cast<::AnimationNames *>(&::increasing170)).names[animationIndex]
                                                                                : DAT_011a03c0[animationIndex])))));
        elapsed += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
        if (sequence)
        {
            reinterpret_cast<::AnimationSequence *>((sequence))->FUN_00a34ba0(elapsed, true);
            if (reinterpret_cast<::BSFaceGenMorphData *>((sequence))->FUN_00508120() < reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100() && animationIndex > 0)
                finished = false;
            else
                finished = true;
        }
        else
            finished = true;
        for (; iter; iter = ((::NiTimeController *)(::fnv_004a8a90::FUN_004a8a90((char *)(iter)))))
        {
            NiTimeController* transform = ((::NiTimeController *)(::FUN_00653270(&(*reinterpret_cast<const ::NiRTTI *>(&::g_011f36bc)), (::NiObject *)(iter))));
            if (transform)
            {
                NiUpdateData updateData(elapsed, false, false);
                iter->Update(updateData);
                break;
            }
        }
    }
    NiUpdateData updateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((model))->FUN_00a59c60((int)&(updateData));
}

bool __cdecl SKIsMenuMode(int aiMenuID);

struct SKValueOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int GetActorValue(int aiIndex);
};

struct SKPlayer
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
    SKValueOwner kValueOwner;
};


struct SKMenu
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void HandleClick(int aiID, int aiUnk);
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
    int iMode;
    int unk4C;
    int unk50;
    int unk54;
    int m_iMaximumCount;

    bool HandleMenuKey(int aiKey, int aiUnused);
};

// In menu mode 0x432, maps a key to a click action (3 or 2) on the selected entry when mode and actor-value limits allow, returning whether it handled the key.
// @fnv 0x00791cf0
bool SKMenu::HandleMenuKey(int aiKey, int aiUnused)
{
    if (SKIsMenuMode(0x432))
    {
        int iIndex = reinterpret_cast<::FUN_00794d30_shell *>(this)->FUN_00794d30();
        switch (aiKey)
        {
        case 4:
            if (iMode != 8)
                return false;
        case 2:
            if (iMode == 8)
                return false;
        case 10:
            if (iIndex != -1 && (*reinterpret_cast<::SKPlayer * *>(&::_g_thePlayer))->kValueOwner.GetActorValue(iIndex) > 1)
                HandleClick(3, 0);
            return true;
        case 3:
            if (iMode != 8)
                return false;
        case 1:
            if (iMode == 8)
                return false;
        case 9:
            if (iIndex != -1 && ::FUN_00794d80((void *)this) < m_iMaximumCount && (*reinterpret_cast<::SKPlayer * *>(&::_g_thePlayer))->kValueOwner.GetActorValue(iIndex) < 10)
                HandleClick(2, 0);
            return true;
        }
    }
    return false;
}

namespace fnv_007945f0 {
struct ImageSpaceEffectParam
{
    float left, right, top, bottom;
    ImageSpaceEffectParam(float, float, float, float);
};
struct SettingFloatHelper
{
};
struct NiFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
    NiFrustum(bool);
};
struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool multithreaded;
    bool updateGeomorphs, updateShadowScene, updateProcess;
    NiUpdateData(float, bool, bool);
};
struct NiPoint3
{
    float x, y, z;
    NiPoint3(float, float, float);
};
struct CameraRenderer
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual float GetAspectRatio();
};
struct FUN_00a712f0
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a712f0();
};
struct SurgeryCameraMenu
{
    FUN_00a712f0* CreateSurgeryCamera();
};
// Allocates and configures a new camera object from the aspect ratio, FOV and screen ratio settings, then returns it.
// @fnv 0x007945f0
FUN_00a712f0* SurgeryCameraMenu::CreateSurgeryCamera()
{
    FUN_00a712f0* k = new FUN_00a712f0;
    ImageSpaceEffectParam ba(0.0f, 1.0f, 1.0f, 0.0f);
    if (::DAT_011f9426)
        ba = (*reinterpret_cast<::fnv_007945f0::ImageSpaceEffectParam *>(&::DAT_011ad840));
    reinterpret_cast<::_Cam_00712e60 *>((k))->FUN_00712e60((const ::_Rect16_00712e60 &)(ba));
    NiFrustum c(false);
    c.farPlane = ((CameraRenderer*)((::ManagerHelper *)(::FUN_0045c670())))->GetAspectRatio();
    c.nearPlane = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007945f0::SettingFloatHelper *>(&::g_01203144))))));
    reinterpret_cast<::FUN_00507700_cls *>((k))->FUN_00507700(c.farPlane / c.nearPlane);
    float l = double(::DAT_011f9426 ? ::DAT_011f9434 : ::FUN_004dc200()) / ((int)(::FUN_004dc1f0()));
    float e = 0.75f;
    float j = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007945f0::SettingFloatHelper *>(&::g_01203150)))))) * 0.01745329238474369 * 0.6499999761581421;
    c.left = -::FUN_0057dd70(j) * e;
    c.right = ::FUN_0057dd70(j) * e;
    c.bottom = -::FUN_0057dd70(j) * l * e;
    c.top = ::FUN_0057dd70(j) * l * e;
    c.orthographic = false;
    reinterpret_cast<::NiCamera *>((k))->UpdateViewFrustum((const ::NiFrustum &)(c));
    reinterpret_cast<::FUN_004bc1f0_S *>((k))->FUN_004bc1f0(0.0f, 0.0f, 1.0f);
    NiUpdateData b(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((k))->FUN_00a59c60((int)&(b));
    reinterpret_cast<::CamLook *>((k))->SetLookAt((const ::CamPoint &)((const ::fnv_007945f0::NiPoint3 &)(NiPoint3(0.0f, 0.0f, 0.0f))), (const ::CamPoint &)((const ::fnv_007945f0::NiPoint3 &)(NiPoint3(0.0f, 1.0f, 0.0f))));
    reinterpret_cast<::FUN_00733fd0_shell *>((k))->FUN_00733fd0(1.0f);
    ::AssignFixedString((char *)(k), (int)&(const ::NiFixedString &)(NiFixedString("Surgery3DCamera")), {});
    return k;
}
}  // namespace fnv_007945f0

struct GlobalObject_0041a250
{
    int id, state, flags;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    bool FUN_00ad8830(bool);
};
struct BSAudioS_
{
    static AudioView* GetSingleton();
};
struct Sequence170
{
};
struct Controller170
{
};
struct Node170
{
};
struct Scene170
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54,
        u58;
    Node170* root;
};
struct Menu170
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44;
    int position;
    int u4c, u50, u54;
    int available;
    bool StepPosition(bool increase);
};
// Moves position up or down within bounds, plays page-turn or limit sounds, and triggers the matching animation sequence on the scene controller.
// @fnv 0x007949f0
bool Menu170::StepPosition(bool increase)
{
    bool changed = false;
    if (increase)
    {
        increasing170 = true;
        if (position < 8)
        {
            position++;
            changed = true;
            GlobalObject_0041a250 sound;
            reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->operator=((*(const ::SoundPlaybackHandle *)(&((::AudioView *)(::FUN_00453a70()))->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        else
        {
            if (::FUN_00794d80((void *)this) == available)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::AudioView *)(::FUN_00453a70()))->GetSoundHandleByEditorID("OBJBookSpecialNumberFinished", 0x121)))->FUN_00ad8830(false);
                FUN_007917a0();
            }
            else
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::AudioView *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIActivateNothing", 0x121)))->FUN_00ad8830(false);
            }
            return false;
        }
    }
    else
    {
        increasing170 = false;
        if (position > 0)
        {
            position--;
            changed = true;
            GlobalObject_0041a250 sound;
            reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->operator=((*(const ::SoundPlaybackHandle *)(&((::AudioView *)(::FUN_00453a70()))->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        else
        {
            return false;
        }
    }
    if (changed)
    {
        Controller170* object = ((::Controller170 *)(reinterpret_cast<::MyHost *>(((*reinterpret_cast<::Scene170 * *>(&::DAT_011da2c8))->root))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<const char *>(&::g_011f36ac))))));
        if (object)
        {
            Controller170* manager = object;
            Sequence170* sequence = 0;
            if (!increasing170 || position > 0)
            {
                sequence =
                    ((::Sequence170 *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString(increasing170 ? (*reinterpret_cast<const char * (*)[]>(&::increasing170))[position] : (*reinterpret_cast<const char * (*)[]>((void *)&::DAT_011a03c0))[position])))));
            }
            if (sequence)
            {
                reinterpret_cast<::NiControllerManager *>((manager))->DeactivateAllSequences(0.0f);
                reinterpret_cast<::NiControllerManager *>((manager))->ActivateControllerSequence((::NiControllerSequence *)(sequence), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::TaskQueueInterface *>((manager))->QueueReferenceStateTask(true);
                ::SetNegatedGlobal((void *)(sequence));
            }
        }
    }
    return true;
}


struct MenuParam_00795630
{
    int unk00;
    int unk04;
    List_00795580 unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

// @fnv 0x00795630
void __cdecl FUN_00795630(MenuParam_00795630* pMenuParam)
{
    int value = pMenuParam->unk24;
    if (value != -1)
    {
        if ((*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(value) < 10 &&
            (DAT_011da2c8 == 0 || FUN_00794d80(DAT_011da2c8) < *(int*)((char*)DAT_011da2c8 + 0x58)))
        {
            reinterpret_cast<::TaskQueueInterface *>((((::Entry_00795580 *)(::FUN_00559450((int *)&(pMenuParam->unk08))))))->QueueActorDisarm({});
        }
        else
        {
            reinterpret_cast<::TaskQueueInterface *>((((::Entry_00795580 *)(::FUN_00559450((int *)&(pMenuParam->unk08))))))->QueueActorDisarm({});
        }

        if (((unsigned char)(::FUN_004b71d0())) && *(int*)((char*)DAT_011da2c8 + 0x48) == 8 &&
            value != *(int*)((char*)DAT_011da2c8 + 0x4C) + 4)
        {
            reinterpret_cast<::TaskQueueInterface *>((((::Entry_00795580 *)(::FUN_00559450((int *)&(pMenuParam->unk08))))))->QueueActorDisarm({});
        }
    }
}

struct WorkerButton
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
    int value;
};
struct WorkerMenu
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int available;
    void FUN_00795e20();
};
struct WorkerSound
{
    int unk00;
    int unk04;
    int unk08;
    WorkerSound();
    ~WorkerSound();
    WorkerSound& operator=(const WorkerSound&);
    bool FUN_00ad8830(bool);
};
extern const char DAT_010747ac[];
struct WorkerAudio
{
    WorkerSound GetSoundHandleByEditorID(const char*, unsigned int);
};
struct WorkerActor
{
};
// @fnv 0x00795a00
void FUN_00795a00(WorkerButton* button)
{
    if (!DAT_011da2c8)
        return;
    int index = button->value;
    if (index != -1)
    {
        int value = (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(index);
        if (value < 10)
        {
            WorkerSound sound;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::WorkerSound &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::WorkerSound &)(((::WorkerAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID(DAT_010747ac, 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        if (FUN_00794d80(DAT_011da2c8) < ((WorkerMenu*)DAT_011da2c8)->available)
            reinterpret_cast<::FUN_0093a7c0_Owner *>((((WorkerActor*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(index), MinInt(value + 1, 10));
    }
    ((WorkerMenu*)DAT_011da2c8)->FUN_00795e20();
}





// If DAT_011daa38 and DAT_011daa9c are set, configures the camera for scene DAT_011daa9c with a node from FUN_007fd640 and calls FUN_00b6bee0/FUN_00b6c0d0.
// @fnv 0x007c9ca0
void __cdecl FUN_007c9ca0()
{
    if (!DAT_011daa38 || !(*reinterpret_cast<::Flt *>(&::g_011daa9c)))
        return;
    {
        reinterpret_cast<::S148c0 *>((((::RendererHelper *)(::FUN_0043c4b0()))))->FUN_007148c0(0, 4);
        ManagerHelper* mgr = ((::ManagerHelper *)(::FUN_0045c670()));
        CameraHelper* cam = ((::CameraHelper *)(reinterpret_cast<::MiddleLowProcess *>((mgr))->GetProcessInteger()));
        reinterpret_cast<::FUN_00c4f270_Class *>((cam))->FUN_00c4f270(true);
        unsigned int scene = (*reinterpret_cast<::Flt *>(&::g_011daa9c));
        ::UpdateCameraFrustum((::NiCamera *)(scene), 0.15f);
        NP node(((int)(reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((((::InterfaceHelper *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007fd640())));
        reinterpret_cast<::FUN_004a0fd0_shell *>((cam))->FUN_004a0fd0((::NiNode *)(node));
        ::FUN_00b6bee0((void *)(scene), ((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))), (::BSShaderAccumulator *)(cam));
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(scene), (::BSShaderAccumulator *)(node), 0);
        reinterpret_cast<::FUN_004a0fd0_shell *>((cam))->FUN_004a0fd0((::NiNode *)(0));
        reinterpret_cast<::FUN_00c4f2d0_class *>((cam))->FUN_00c4f2d0();
    }
}

namespace fnv_007caa80 {
struct GlobalObject_0041a250
{
    int unk00;
    int unk04;
    int unk08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    bool FUN_00ad8830(bool);
};
struct Audio_7caa80
{
    GlobalObject_0041a250 FUN_00ad7550(const char*, unsigned int);
};
struct Menu_7caa80 : LoveTesterMenu
{
};
struct Player_7caa80
{
};
struct Button_7caa80
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
    int stat;
};
// @fnv 0x007caa80
void __cdecl PlaySpecialBookSoundAndSetStat(Button_7caa80* button)
{
    if (!(*reinterpret_cast<::fnv_007caa80::Menu_7caa80 * *>(&::DAT_011daa38)))
        return;
    int key = button->stat;
    if (key != -1)
    {
        int value = (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(key);
        if (value < 10)
        {
            GlobalObject_0041a250 sound;
            reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_007caa80::GlobalObject_0041a250 &)(((::fnv_007caa80::Audio_7caa80 *)(::FUN_00453a70()))->FUN_00ad7550("OBJBookSpecialNumber", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        if (FUN_00794d80((*reinterpret_cast<::fnv_007caa80::Menu_7caa80 * *>(&::DAT_011daa38))) < (*reinterpret_cast<::fnv_007caa80::Menu_7caa80 * *>(&::DAT_011daa38))->m_iEntryCount)
        {
            reinterpret_cast<::FUN_0093a7c0_Owner *>((((Player_7caa80*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(key), ::MinInt(value + 1, 10));
        }
    }
    reinterpret_cast<::FUN_007c9dc0_Class *>(((*reinterpret_cast<::fnv_007caa80::Menu_7caa80 * *>(&::DAT_011daa38))))->InvokeCallbacksForSlot();
}
}  // namespace fnv_007caa80

void FUN_00795e20(Glob*);

// @fnv 0x00795b30
void __cdecl UpdateLoveTester()
{
    if (!DAT_011da2c8)
        return;
    int key = ((FUN_00794d30_shell*)DAT_011da2c8)->FUN_00794d30();
    if (key != -1)
    {
        int value = (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(key);
        if (value < 10)
        {
            BSSoundHandleEx sound;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(((AudioView*)::FUN_00453a70())->GetSoundHandleByEditorID("OBJBookSpecialNumber", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        if (FUN_00794d80(DAT_011da2c8) < ((LoveTesterMenu*)DAT_011da2c8)->m_iEntryCount)
            reinterpret_cast<::FUN_0093a7c0_Owner *>((((PlayerSetter*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(key), MinInt(value + 1, 10));
    }
    FUN_00795e20(DAT_011da2c8);
}

namespace fnv_007928e0 {
struct Matrix109
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix109();
    Matrix109 FUN_0043f8d0(const Matrix109&);
};
struct Update109
{
    float time;
    bool update, force;
    short unk06;
    int unk08;
    Update109(float, bool, bool);
};
struct Color109
{
    float r, g, b;
    Color109(float, float, float);
};
struct Bound109
{
};
struct Animation109
{
};
struct Controller109
{
};
struct Scene109
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual Scene109* v00c();
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
    virtual void v094(const Update109&);
    virtual void v098();
    virtual Scene109* v09c(const NiFixedString&);
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
    virtual void v0dc(Scene109*, bool);
    void FUN_0050dd50(const Color109&);
};
struct Light109 : Scene109
{
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
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    Light109();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct Loader109
{
};
struct Button109
{
    int unk00, unk04, unk08, unk0c, unk10;
    Button109(void*, void*, const char*);
};
struct Adjust109 : Button109
{
    int unk14, unk18, unk1c, unk20, unk24;
    __cdecl Adjust109(void*, void*, const char*, int, int, ...);
};
struct Label109 : Button109
{
    int unk14, unk18;
    Label109(void*, const char*, const char*, int, int, int);
};
struct Digit109
{
    Scene109* object;
    int value;
    Digit109(Scene109*, int);
};
struct ButtonList109
{
    int unk00, unk04, unk08, unk0c;
};
struct LabelList109
{
    int unk00, unk04, unk08, unk0c;
};
struct DigitList109
{
    int unk00, unk04, unk08, unk0c;
};
struct Menu109
{
    int unk000;
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
    float time;
    int unk054, unk058;
    Scene109* front;
    Scene109* cabinet;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    DigitList109 digits;
    ButtonList109 misc;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    ButtonList109 adjustments;
    LabelList109 values;
    ButtonList109 controls;
    LabelList109 totals;
    void FUN_00795e20();
    void Init();
};
// Loads the front and cabinet NIF scenes, positions them, adds lights and creates the digit, value, adjustment and button widgets for the menu.
// @fnv 0x007928e0
void Menu109::Init()
{
    ((Menu109*)DAT_011da2c8)->front = ((::fnv_007928e0::Scene109 *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::fnv_007928e0::Loader109 * *>(&::g_modelLoader))))->FUN_00447080(
        (char *)("Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Activate.NIF"), 0, 1, 0, 0, 0)));
    ::UpdateObjectVisibility((::NiAVObject *)(((Menu109*)DAT_011da2c8)->front));
    ((Menu109*)DAT_011da2c8)->cabinet = ((::fnv_007928e0::Scene109 *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::fnv_007928e0::Loader109 * *>(&::g_modelLoader))))->FUN_00447080(
        (char *)("Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Cabinet.NIF"), 0, 1, 0, 0, 0)));
    ::UpdateObjectVisibility((::NiAVObject *)(((Menu109*)DAT_011da2c8)->cabinet));
    Matrix109 rotation5, turn1;
    reinterpret_cast<::FUN_00524ac0_shell *>(&(rotation5))->FUN_00524ac0(1.57079637f);
    reinterpret_cast<::FUN_004a0c90_shell *>(&(turn1))->FUN_004a0c90(3.14159274f);
    rotation5 = rotation5.FUN_0043f8d0(turn1);
    reinterpret_cast<::FUN_00524ac0_shell *>(&(turn1))->FUN_00524ac0(0.125663713f);
    rotation5 = rotation5.FUN_0043f8d0(turn1);
    bool narrow3 = ((double)(::FUN_00706e50())) <= 640.0;
    if (narrow3)
    {
        reinterpret_cast<::FUN_00440490_shell *>((((Menu109*)DAT_011da2c8)->front))->FUN_00440490(1.0f);
        reinterpret_cast<::FUN_004bc1f0_S *>((((Menu109*)DAT_011da2c8)->front))->FUN_004bc1f0(0.0f, -85.0f, -75.0f);
        reinterpret_cast<::FUN_0043fa80_s *>((((Menu109*)DAT_011da2c8)->front))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(rotation5));
        reinterpret_cast<::FUN_00440490_shell *>((((Menu109*)DAT_011da2c8)->cabinet))->FUN_00440490(1.0f);
        reinterpret_cast<::FUN_004bc1f0_S *>((((Menu109*)DAT_011da2c8)->cabinet))->FUN_004bc1f0(0.0f, -85.0f, -75.0f);
        reinterpret_cast<::FUN_0043fa80_s *>((((Menu109*)DAT_011da2c8)->cabinet))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(rotation5));
    }
    else
    {
        reinterpret_cast<::FUN_00440490_shell *>((((Menu109*)DAT_011da2c8)->front))->FUN_00440490(1.0f);
        reinterpret_cast<::FUN_004bc1f0_S *>((((Menu109*)DAT_011da2c8)->front))->FUN_004bc1f0(0.0f, -85.0f, -85.0f);
        reinterpret_cast<::FUN_0043fa80_s *>((((Menu109*)DAT_011da2c8)->front))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(rotation5));
        reinterpret_cast<::FUN_00440490_shell *>((((Menu109*)DAT_011da2c8)->cabinet))->FUN_00440490(1.0f);
        reinterpret_cast<::FUN_004bc1f0_S *>((((Menu109*)DAT_011da2c8)->cabinet))->FUN_004bc1f0(0.0f, -85.0f, -85.0f);
        reinterpret_cast<::FUN_0043fa80_s *>((((Menu109*)DAT_011da2c8)->cabinet))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(rotation5));
    }
    Update109 update13(0.0f, false, false), update259(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((Menu109*)DAT_011da2c8)->front))->FUN_00a59c60((int)&(update13));
    reinterpret_cast<::FUN_00a59c60_cls *>((((Menu109*)DAT_011da2c8)->cabinet))->FUN_00a59c60((int)&(update259));
    ((Menu109*)DAT_011da2c8)->time += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_007928e0::Bound109 *>(&::g_timeGlobal))))->GetStoredFloatValue();
    Controller109* controller7 = ((::fnv_007928e0::Controller109 *)(reinterpret_cast<::MyHost *>((((Menu109*)DAT_011da2c8)->front))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36ac))))));
    if (controller7)
    {
        Controller109* animationController20 = controller7;
        Animation109* animation7 = ((::fnv_007928e0::Animation109 *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((animationController20))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Forward")))));
        if (animation7)
        {
            reinterpret_cast<::NiControllerManager *>((animationController20))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((animationController20))->ActivateControllerSequence((::NiControllerSequence *)(animation7), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            reinterpret_cast<::TaskQueueInterface *>((animationController20))->QueueReferenceStateTask(true);
            ::SetNegatedGlobal((void *)(animation7));
        }
    }
    ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(front));
    for (; controller7; controller7 = ((::fnv_007928e0::Controller109 *)(::fnv_004a8a90::FUN_004a8a90((char *)(controller7)))))
    {
        void* special = ((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36bc))), (::NiObject *)(controller7))));
        if (special)
        {
            Update109 controllerUpdate(0.0f, false, false);
            ((Scene109*)controller7)->v094(controllerUpdate);
            break;
        }
    }
    Update109 update31(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((front))->FUN_00a59c60((int)&(update31));
    float radius41 = reinterpret_cast<::Twin_0084d030 *>((((::fnv_007928e0::Bound109 *)(reinterpret_cast<::FUN_0043d450_Owner *>((((Menu109*)DAT_011da2c8)->front))->FUN_0043d450()))))->GetStoredFloatValue() * 20.0;
    Scene109* ambient16 = ((::fnv_007928e0::Scene109 *)(reinterpret_cast<::SSN_b5 *>((((Scene109*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))))->FUN_00b5ca70((::Node_b5 *)(::fnv_007928e0::Scene109 *)(((Menu109*)DAT_011da2c8)->front->v00c()), radius41)));
    if (!ambient16)
    {
        Light109* light52 = new Light109;
        reinterpret_cast<::FUN_00440460_S *>((light52))->FUN_00440460((const ::V3 *)&(const ::fnv_007928e0::Color109 &)(Color109(0.0f, 0.0f, 0.0f)));
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((light52))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)((const ::fnv_007928e0::Color109 &)(Color109(0.85f, 0.85f, 0.85f))));
        light52->FUN_0050dd50(Color109(radius41, 0.0f, 0.0f));
        reinterpret_cast<::NiPointLight *>((light52))->FUN_0050dd20(1.0f);
        Update109 lightUpdate10(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((light52))->FUN_00a59c60((int)&(lightUpdate10));
        ((Scene109*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->v0dc(light52, true);
        reinterpret_cast<::fnv_00b5c940::SSNode *>((((Scene109*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(light52), 0);
    }
    ((Scene109*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->v0dc(((Menu109*)DAT_011da2c8)->front, true);
    ((Scene109*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->v0dc(((Menu109*)DAT_011da2c8)->cabinet, true);
    Label109* total28 = 0;
    Adjust109* decrease27;
    Adjust109* increase7;
    Button109* button12;
    Label109* value4;
    decrease27 = new Adjust109((void*)((void (&)(void *))::fnv_007958e0::FUN_007958e0), (void*)UpdateMenuEntryState, "P1_Decrease_Btn:0", -1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->controls))->FUN_007cb2e0((unsigned int *)&(decrease27));
    decrease27 = new Adjust109((void*)((void (&)(void *))::UpdateLoveTester), (void*)((void (&)(void *))::FUN_00795630), "P1_Increase_Btn:0", -1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->controls))->FUN_007cb2e0((unsigned int *)&(decrease27));
    button12 = new Button109((void*)((void (&)(void *))::fnv_00795c60::FUN_00795c60), (void*)SetTargetFromGlobalState, "P1_RT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->controls))->FUN_007cb2e0((unsigned int *)&(button12));
    button12 = new Button109((void*)((void (&)(void *))::fnv_00795ca0::FUN_00795ca0), (void*)FUN_00795780, "P1_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->controls))->FUN_007cb2e0((unsigned int *)&(button12));
    for (int row = 1; row < 10; ++row)
    {
        char name[30];
        for (int digit = 0; digit < 10; ++digit)
        {
            ::FUN_00406d00(name, 30, "P1_PointVal_0%i_GLOW:%i", row, digit);
            if (((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name)))
            {
                Digit109* entry = new Digit109(((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name)), row);
                reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->digits))->FUN_007cb2e0((unsigned int *)&(entry));
            }
        }
        ::FUN_00406d00(name, 30, "P1_PointVal_0%i_GLOW", row);
        if (((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name)))
        {
            Digit109* entry2 = new Digit109(((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name)), row);
            reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->digits))->FUN_007cb2e0((unsigned int *)&(entry2));
        }
    }
    {
        char name10[30];
        for (int digit10 = 0; digit10 < 10; ++digit10)
        {
            ::FUN_00406d00(name10, 30, "P1_PointVal_10_GLOW:%i", digit10);
            if (((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name10)))
            {
                Digit109* entry10 = new Digit109(((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name10)), 10);
                reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->digits))->FUN_007cb2e0((unsigned int *)&(entry10));
            }
        }
        ::FUN_00406d00(name10, 30, "P1_PointVal_10_GLOW");
        if (((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name10)))
        {
            Digit109* entryLast = new Digit109(((Menu109*)DAT_011da2c8)->cabinet->v09c(NiFixedString(name10)), 10);
            reinterpret_cast<::FUN_00438690 *>(&(((Menu109*)DAT_011da2c8)->digits))->FUN_007cb2e0((unsigned int *)&(entryLast));
        }
    }
    total28 = new Label109((void*)UpdateDigitDisplay, "P1_PointsRemainDigit1:0", "P1_PointsRemainDigit2:0", -1, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(totals))->FUN_007cb2e0((unsigned int *)&(total28));
    button12 = new Button109((void*)((void (&)(void *))::fnv_00795c60::FUN_00795c60), (void*)SetTargetFromGlobalState, "LookInside_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(misc))->FUN_007cb2e0((unsigned int *)&(button12));
    value4 = new Label109((void*)((void (&)(void *))::fnv_00795390::FUN_00795390), "Index_StrengthPointVal:0", 0, 5, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(values))->FUN_007cb2e0((unsigned int *)&(value4));
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_StrengthDecrease_Btn:0", 5, 2,
                               value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(decrease27));
    increase7 =
        new Adjust109((void*)((void (&)(void *))::FUN_00795a00), (void*)((void (&)(void *))::FUN_00795630), "Index_StrengthIncrease_Btn:0", 5, 2, value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(increase7));
    value4 = new Label109((void*)((void (&)(void *))::fnv_00795390::FUN_00795390), "Index_PerceptionPointVal:0", 0, 6, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(values))->FUN_007cb2e0((unsigned int *)&(value4));
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_PerceptionDecrease_Btn:0", 6, 2,
                               value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(decrease27));
    increase7 = new Adjust109((void*)((void (&)(void *))::FUN_00795a00), (void*)((void (&)(void *))::FUN_00795630), "Index_PerceptionIncrease_Btn:0", 6, 2, value4,
                              total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(increase7));
    value4 = new Label109((void*)((void (&)(void *))::fnv_00795390::FUN_00795390), "Index_EndurancePointVal:0", 0, 7, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(values))->FUN_007cb2e0((unsigned int *)&(value4));
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_EnduranceDecrease_Btn:0", 7, 2,
                               value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(decrease27));
    increase7 =
        new Adjust109((void*)((void (&)(void *))::FUN_00795a00), (void*)((void (&)(void *))::FUN_00795630), "Index_EnduranceIncrease_Btn:0", 7, 2, value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(increase7));
    value4 = new Label109((void*)((void (&)(void *))::fnv_00795390::FUN_00795390), "Index_CharismaPointVal:0", 0, 8, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(values))->FUN_007cb2e0((unsigned int *)&(value4));
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_CharismaDecrease_Btn:0", 8, 2,
                               value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(decrease27));
    increase7 =
        new Adjust109((void*)((void (&)(void *))::FUN_00795a00), (void*)((void (&)(void *))::FUN_00795630), "Index_CharismaIncrease_Btn:0", 8, 2, value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(increase7));
    value4 = new Label109((void*)((void (&)(void *))::fnv_00795390::FUN_00795390), "Index_IntelligencePointVal:0", 0, 9, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(values))->FUN_007cb2e0((unsigned int *)&(value4));
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_IntelligenceDecrease_Btn:0", 9,
                               2, value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(decrease27));
    increase7 = new Adjust109((void*)((void (&)(void *))::FUN_00795a00), (void*)((void (&)(void *))::FUN_00795630), "Index_IntelligenceIncrease_Btn:0", 9, 2,
                              value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(increase7));
    value4 = new Label109((void*)((void (&)(void *))::fnv_00795390::FUN_00795390), "Index_AgilityPointVal:0", 0, 10, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(values))->FUN_007cb2e0((unsigned int *)&(value4));
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_AgilityDecrease_Btn:0", 10, 2,
                               value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(decrease27));
    increase7 =
        new Adjust109((void*)((void (&)(void *))::FUN_00795a00), (void*)((void (&)(void *))::FUN_00795630), "Index_AgilityIncrease_Btn:0", 10, 2, value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(increase7));
    value4 = new Label109((void*)((void (&)(void *))::fnv_00795390::FUN_00795390), "Index_LuckPointVal:0", 0, 11, 1, 0);
    reinterpret_cast<::FUN_00438690 *>(&(values))->FUN_007cb2e0((unsigned int *)&(value4));
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_LuckDecrease_Btn:0", 11, 2,
                               value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(decrease27));
    increase7 =
        new Adjust109((void*)((void (&)(void *))::FUN_00795a00), (void*)((void (&)(void *))::FUN_00795630), "Index_LuckIncrease_Btn:0", 11, 2, value4, total28);
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(increase7));
    button12 = new Button109((void*)FUN_00795ce0, (void*)SetTargetFromGlobalState, "AllDone_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(adjustments))->FUN_007cb2e0((unsigned int *)&(button12));
    reinterpret_cast<::fnv_00796100::This796 *>(this)->FUN_00796100();
    ((Menu109*)DAT_011da2c8)->FUN_00795e20();
    ::fnv_00795c60::FUN_00795c60();
}
}  // namespace fnv_007928e0

struct Cb_WM
{
    void(__cdecl* pfn0)(Cb_WM*);
    void(__cdecl* pfn4)(Cb_WM*);
};
struct CbArr_WM
{
    int a, b, c, d;
};
struct Lvl_WM
{
    NiAVObjectS* obj;
    int level;
    int u08, u0c, u10, u14, u18;
};
struct LvlArr_WM
{
    int a, b, c, d;
};
struct G_WM
{
    char _0[0x64];
    LvlArr_WM arr64;
    LvlArr_WM arr74;
};
struct Pair_WM
{
    CbArr_WM a;
    CbArr_WM b;
};
struct FUN_00795e20_cls
{
    char _0[0x48];
    int idx;
    char _4c[0x84 - 0x4c];
    Pair_WM pairs[9];
    CbArr_WM arr1a4;
    CbArr_WM arr1b4;
    void FUN_00795e20();
};
// When idx is at most 8, processes level entries and invokes pfn0 or pfn4 across the selected callback arrays.
// @fnv 0x00795e20
void FUN_00795e20_cls::FUN_00795e20()
{
    int iLevel;
    if (idx <= 8)
    {
        if (DAT_011da2c8)
        {
            int a = reinterpret_cast<::FUN_00794d30_shell *>((((G_WM*)DAT_011da2c8)))->FUN_00794d30();
            iLevel = 0;
            if (a != -1)
                iLevel = (*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer))->avOwner.GetValue(reinterpret_cast<::FUN_00794d30_shell *>((((G_WM*)DAT_011da2c8)))->FUN_00794d30());
            for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(((G_WM*)DAT_011da2c8)->arr64))->GetName())); i++)
            {
                int x = ((::Lvl_WM *)(reinterpret_cast<::S3e60 *>(&(((G_WM*)DAT_011da2c8)->arr64))->FUN_006a7ad0(i)))->u18;
                reinterpret_cast<::S3e60 *>(&(((G_WM*)DAT_011da2c8)->arr64))->FUN_006a7ad0(i);
            }
            if (0)
            {
            }
            for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(((G_WM*)DAT_011da2c8)->arr74))->GetName())); j++)
            {
                int iRequiredLevel = ((::Lvl_WM *)(reinterpret_cast<::S3e60 *>(&(((G_WM*)DAT_011da2c8)->arr74))->FUN_006a7ad0(j)))->level;
                if (((::Lvl_WM *)(reinterpret_cast<::S3e60 *>(&(((G_WM*)DAT_011da2c8)->arr74))->FUN_006a7ad0(j)))->obj)
                    reinterpret_cast<::TaskQueueInterface *>((((::Lvl_WM *)(reinterpret_cast<::S3e60 *>(&(((G_WM*)DAT_011da2c8)->arr74))->FUN_006a7ad0(j)))->obj))->QueueActorDisarm(iLevel < iRequiredLevel);
            }
        }
        for (unsigned int iIndex = 0; iIndex < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pairs[idx].b))->GetName())); iIndex++)
            ((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(pairs[idx].b))->FUN_006a7ad0(iIndex)))->pfn0(((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(pairs[idx].b))->FUN_006a7ad0(iIndex))));
        for (unsigned int k1 = 0; k1 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pairs[idx].a))->GetName())); k1++)
            ((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(pairs[idx].a))->FUN_006a7ad0(k1)))->pfn4(((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(pairs[idx].a))->FUN_006a7ad0(k1))));
        for (unsigned int k2 = 0; k2 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr1b4))->GetName())); k2++)
            ((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(arr1b4))->FUN_006a7ad0(k2)))->pfn0(((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(arr1b4))->FUN_006a7ad0(k2))));
        for (unsigned int k3 = 0; k3 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr1a4))->GetName())); k3++)
            ((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(arr1a4))->FUN_006a7ad0(k3)))->pfn4(((::Cb_WM *)(reinterpret_cast<::S3e60 *>(&(arr1a4))->FUN_006a7ad0(k3))));
    }
}

struct AVRead
{
    virtual int GetCurrent(int);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int GetBase(int);
};
struct InputPlayer
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    AVRead owner;
};
struct Vec3
{
    float local879956, local866269, z;
    Vec3();
};
struct Hit
{
};
class NiPoint3;
struct NiPick
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30;
    NiPick(int, int);
    ~NiPick();
    void FUN_00705fc0(void*);
public:
    bool PerformPick(const ::NiPoint3 &, const ::NiPoint3 &, bool);
};
struct ClickNode
{
    void(__cdecl* click)(ClickNode*);
    int u04;
    Flt object;
};
struct ClickArray
{
    int count, capacity, data, grow;
};
struct ClickGroup
{
    ClickArray objects, allocations;
};
struct Cursor
{
};
struct Buffer
{
};
struct Render
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual Buffer* GetBuffer();
};
struct CameraRay
{
};
struct InputMenu
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int mode;
    int special;
    float time;
    bool finished;
    int available;
    int u5c, u60;
    ClickArray arr64, arr74;
    ClickGroup groups[9];
    ClickArray arr1a4, arr1b4;
    void HandleButton(int button, int unused);
};
// Handles menu button cases for navigation, value changes, and ray-tested clicks on menu tiles.
// @fnv 0x00791e40
void InputMenu::HandleButton(int button, int unused)
{
    bool local720986 = false;
    switch (button)
    {
    case 4:
        if (FUN_00794d80(this) == available)
        {
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialNumberFinished", 0x121, false)))->FUN_00ad8830({});
            FUN_007917a0();
        }
        else
        {
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIActivateNothing", 0x121, false)))->FUN_00ad8830({});
        }
        break;
    case 0:
    case 1:
        if (finished)
        {
            if (button == 0)
                local720986 = reinterpret_cast<::Menu170 *>(this)->StepPosition(true);
            else
                local720986 = reinterpret_cast<::Menu170 *>(this)->StepPosition(false);
            reinterpret_cast<::FUN_00795e20_cls *>(this)->FUN_00795e20();
        }
        break;
    case 2:
    case 3: {
        int local972322 = 0;
        int local421248 = 0;
        if (((FUN_00794d30_shell*)this)->FUN_00794d30() != -1)
        {
            local972322 = ((InputPlayer*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))->owner.GetBase(((FUN_00794d30_shell*)this)->FUN_00794d30());
            if (button == 2)
            {
                if (FUN_00794d80(this) < available)
                    reinterpret_cast<::FUN_0093a7c0_Owner *>((((PlayerSetter*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(((FUN_00794d30_shell*)this)->FUN_00794d30()), MinInt(local972322 + 1, 10));
            }
            else
            {
                reinterpret_cast<::FUN_0093a7c0_Owner *>((((PlayerSetter*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(((FUN_00794d30_shell*)this)->FUN_00794d30()), FUN_00647b70(local972322 - 1, 1));
            }
            local421248 = ((InputPlayer*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))->owner.GetCurrent(((FUN_00794d30_shell*)this)->FUN_00794d30());
        }
        else if (((unsigned char)(::FUN_004b71d0())) && mode == 8)
        {
            int local294918 = special + 4;
            local972322 = ((InputPlayer*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))->owner.GetBase(local294918);
            if (button == 2)
            {
                if (FUN_00794d80(this) < available)
                    reinterpret_cast<::FUN_0093a7c0_Owner *>((((PlayerSetter*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(local294918), MinInt(local972322 + 1, 10));
            }
            else
            {
                reinterpret_cast<::FUN_0093a7c0_Owner *>((((PlayerSetter*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(local294918), FUN_00647b70(local972322 - 1, 1));
            }
            local421248 = ((InputPlayer*)(*reinterpret_cast<::Player_007927a0 * *>(&::_g_thePlayer)))->owner.GetCurrent(local294918);
        }
        if (local972322 > local421248)
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialNumberDown", 0x121, false)))->FUN_00ad8830({});
        if (local972322 < local421248)
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialNumber", 0x121, false)))->FUN_00ad8830({});
        reinterpret_cast<::FUN_00795e20_cls *>(this)->FUN_00795e20();
    }
    break;
    case 5:
        if (mode <= 8)
        {
            int local879956;
            Cursor* local97635 = (Cursor*)((::InterfaceHelper *)(::fnv_004b7210::FUN_004b7210()));
            local879956 = (int)reinterpret_cast<::BGSImpactData *>((local97635))->FUN_009a9350();
            int local866269 = (int)reinterpret_cast<::FUN_00792760_shell *>((local97635))->FUN_00792760();
            if (DAT_011f9426)
                local866269 = (int)(local866269 * (DAT_011ad848 - DAT_011ad84c) +
                                    ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((Render*)((::RendererHelper *)(::FUN_0043c4b0())))->GetBuffer()))->FUN_0084e3a0())) * (double)DAT_011ad84c);
            for (unsigned int local610845 = 0; local610845 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(groups[mode].objects))->GetName())); local610845++)
            {
                Vec3 local960365;
                Vec3 local282417;
                NiPick local38019(0, 8);
                reinterpret_cast<::FUN_00458b30_class *>(&(local38019))->SetByteAtOffset17(true);
                local38019.FUN_00705fc0(
                    (void*)(*((::ClickNode **)(reinterpret_cast<::S3e60 *>(&(groups[mode].objects))->FUN_006a7ad0(local610845))))->object.operator unsigned int());
                reinterpret_cast<::CombatProcedure *>(&(local38019))->Initialize((::CombatController *)(0));
                reinterpret_cast<::FUN_00792780_Class *>(&(local38019))->SetByteAtOffset30(true);
                reinterpret_cast<::CameraWindowRay *>((((CameraRay*)(*reinterpret_cast<::Flt *>(&::g_011da2f4)).operator unsigned int())))->MapScreenToRay(local879956, local866269, (::NiPoint3 &)(local960365), (::NiPoint3 &)(local282417), (const ::NiRenderTargetGroup *)(false));
                if (reinterpret_cast<::NiPick *>(&(local38019))->PerformPick((const ::NiPoint3 &)(local960365), (const ::NiPoint3 &)(local282417), false))
                {
                    unsigned int local919856 = 0;
                    void* local799449 = ((void *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::Hit *)(reinterpret_cast<::BGSCameraPath *>(&(local38019))->GetConditions()))))->FUN_00968670({})));
                    if (local799449)
                    {
                        (*((::ClickNode **)(reinterpret_cast<::S3e60 *>(&(groups[mode].objects))->FUN_006a7ad0(local610845))))
                            ->click(*((::ClickNode **)(reinterpret_cast<::S3e60 *>(&(groups[mode].objects))->FUN_006a7ad0(local610845))));
                        break;
                    }
                }
            }
            for (unsigned int local966572 = 0; local966572 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr1a4))->GetName())); local966572++)
            {
                Vec3 local960365;
                Vec3 local282417;
                NiPick local38019(0, 8);
                reinterpret_cast<::FUN_00458b30_class *>(&(local38019))->SetByteAtOffset17(true);
                local38019.FUN_00705fc0((void*)(*((::ClickNode **)(reinterpret_cast<::S3e60 *>(&(arr1a4))->FUN_006a7ad0(local966572))))->object.operator unsigned int());
                reinterpret_cast<::CombatProcedure *>(&(local38019))->Initialize((::CombatController *)(0));
                reinterpret_cast<::FUN_00792780_Class *>(&(local38019))->SetByteAtOffset30(true);
                reinterpret_cast<::CameraWindowRay *>((((CameraRay*)(*reinterpret_cast<::Flt *>(&::g_011da2f4)).operator unsigned int())))->MapScreenToRay(local879956, local866269, (::NiPoint3 &)(local960365), (::NiPoint3 &)(local282417), (const ::NiRenderTargetGroup *)(false));
                if (reinterpret_cast<::NiPick *>(&(local38019))->PerformPick((const ::NiPoint3 &)(local960365), (const ::NiPoint3 &)(local282417), false))
                {
                    unsigned int local919856 = 0;
                    void* local799449 = ((void *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::Hit *)(reinterpret_cast<::BGSCameraPath *>(&(local38019))->GetConditions()))))->FUN_00968670({})));
                    if (local799449)
                    {
                        (*((::ClickNode **)(reinterpret_cast<::S3e60 *>(&(arr1a4))->FUN_006a7ad0(local966572))))->click(*((::ClickNode **)(reinterpret_cast<::S3e60 *>(&(arr1a4))->FUN_006a7ad0(local966572))));
                        break;
                    }
                }
            }
        }
        break;
    case 6:
        if (mode == 8 && special > 1)
        {
            special--;
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121, false)))->FUN_00ad8830({});
        }
        reinterpret_cast<::FUN_00795e20_cls *>(this)->FUN_00795e20();
        break;
    case 7:
        if (mode == 8 && special < 7)
        {
            special++;
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121, false)))->FUN_00ad8830({});
        }
        reinterpret_cast<::FUN_00795e20_cls *>(this)->FUN_00795e20();
        break;
    }
}

#include <stdarg.h>
struct Animation;

template <class T, unsigned int N> struct BSScrapArray
{
    unsigned int Add(T& kItem);
};

struct FUN_00723fa0
{
    void* m_pData;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
    unsigned int m_uiGrow;
    FUN_00723fa0();
    ~FUN_00723fa0();
};

struct FUN_00794ff0 : FUN_00794e70
{
    int m_10;
    FUN_00723fa0 m_kAnims;
    int m_24;
    FUN_00794ff0(int a, int b, const char* pName, int iParam, int iCount, ...);
};

// Initialises m_24 with iParam and appends iCount Animation* arguments from the variadic list to m_kAnims.
// @fnv 0x00794ff0
FUN_00794ff0::FUN_00794ff0(int aiParam1, int aiParam2, const char* pName, int iParam, int aiAnimCount, ...)
    : FUN_00794e70(aiParam1, aiParam2, pName)
{
    m_24 = iParam;
    va_list kArgs;
    va_start(kArgs, aiAnimCount);
    for (int i = 0; i < aiAnimCount; i++)
        ((BSScrapArray<Animation*, 0x400>*)&m_kAnims)->Add(va_arg(kArgs, Animation*));
    va_end(kArgs);
}
