// fallout_shared/screensplatter.cpp: ScreenSplatter (16 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/CamLook.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_00622d00_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/FUN_00a71b70_cls.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_00622d60__xCaster.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004e0000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00622000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00b81000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "screensplatter_decls.h"

// @fnv 0x004e0540
void ScreenSplatter::Init()
{
    AutoMemContext m_uiMemoryContext(static_cast<MEM_CONTEXT>(7), true, &DAT_01022ab8, 181);
    DAT_011c7834 = *reinterpret_cast<unsigned char*>((*reinterpret_cast<::ProcessLists *>(&::g_011c784c)).GetLifeStateControlFlag());
    if (DAT_011c7834)
    {
        ScreenSplatterInitLocals initLocals;
        initLocals.renderer = reinterpret_cast<GraphicsRenderer*>(FUN_0043c4b0());
        initLocals.aspect = static_cast<float>(static_cast<double>(initLocals.renderer->GetRenderTargetWidth()) /
                                               initLocals.renderer->GetRenderTargetHeight());

        (*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c7840)) = reinterpret_cast<NiAVObject*>(new FUN_00a712f0());

        reinterpret_cast<::FUN_00440460_S *>((reinterpret_cast<NiAVObject*>((*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c7840)).operator->())))->FUN_00440460((const ::V3 *)&(const ::NiPoint3 &)(NiPoint3(0.0f, 0.0f, DAT_01022960)));

        reinterpret_cast<NiUpdateData*>(&initLocals.firstData)->NiUpdateData::NiUpdateData(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NiNode*>((*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c7840)).operator->())))->FUN_00a59c60((std::intptr_t)&(*reinterpret_cast<NiUpdateData*>(&initLocals.firstData)));

        reinterpret_cast<::CamLook *>((reinterpret_cast<NiCamera*>((*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c7840)).operator->())))->SetLookAt((const ::CamPoint &)(NiPoint3::ZERO), (const ::CamPoint &)(DAT_011a9478));

        reinterpret_cast<::FUN_00a71b70_cls *>((reinterpret_cast<NiFrustum*>(&initLocals.frustum)))->FUN_00a71b70(false);
        initLocals.frustum.ortho = false;
        initLocals.frustum.top = ::fnv_00c88020::DAT_01016248;
        initLocals.frustum.bottom = DAT_0102295c;
        initLocals.frustum.left = static_cast<float>(initLocals.aspect * DAT_01011598);
        initLocals.frustum.right = static_cast<float>(initLocals.aspect * ::DAT_01011588);
        initLocals.frustum.farPlane = DAT_01022958;
        initLocals.frustum.nearPlane = 1.0f;
        reinterpret_cast<NiCamera*>((*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c7840)).operator->())
            ->UpdateViewFrustum(*reinterpret_cast<NiFrustum*>(&initLocals.frustum));

        reinterpret_cast<NiUpdateData*>(&initLocals.secondData)->NiUpdateData::NiUpdateData(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NiNode*>((*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c7840)).operator->())))->FUN_00a59c60((std::intptr_t)&(*reinterpret_cast<NiUpdateData*>(&initLocals.secondData)));
        DAT_01189550 = initLocals.frustum.right;
        DAT_01189554 = initLocals.frustum.top;

        (*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)) = reinterpret_cast<NiAVObject*>(new NiSortAdjustNode(0));
        DAT_011c7828 = 0;

        SkyTextureManager::LoadTextureFromPath(
            &DAT_011c7864, ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&(*reinterpret_cast<unsigned char *>(&::g_011ce918)))))->GetMenuTitle())));
        SkyTextureManager::LoadTextureFromPath(
            &DAT_011c7860, ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&(*reinterpret_cast<unsigned char *>(&::g_011ce284)))))->GetMenuTitle())));
        if ((*reinterpret_cast<unsigned char *>(&::DAT_011f941e)))
        {
            SkyTextureManager::LoadTextureFromPath(
                &DAT_011c7868, ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&(*reinterpret_cast<unsigned char *>(&::g_011cede8)))))->GetMenuTitle())));
        }
    }
}

// If DAT_011c7834 is set, calls FUN_004def90 on the NiNode from DAT_011c786c and clears DAT_011c7828.
// @fnv 0x004e0870
void ScreenSplatter::Clear()
{
    if (DAT_011c7834)
    {
        reinterpret_cast<::FUN_004def90_Class *>((reinterpret_cast<NiNode*>((*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)).operator->())))->FUN_004def90();
        DAT_011c7828 = 0;
    }
}

// @fnv 0x00622a70
FUN_00622c80* ScreenSplatter::Activate(float time, bool enabled)
{
    if (time > FUN_00622ba0())
    {
        if (!DAT_011cc200 && enabled)
            DAT_011cc200 = new FUN_00622c80(FUN_00622bb0(), FUN_005dbe10());
        return DAT_011cc200;
    }
    else
    {
        if (!DAT_011cc1fc && enabled)
            DAT_011cc1fc = new FUN_00622c80(FUN_00622ba0(), FUN_005dbe10());
        return DAT_011cc1fc;
    }
}

class BSFadeNode
{
    int dummy;

  public:
    BSFadeNode(const char* name);
};


// Allocates a BSFadeNode named "SPD" and stores it in DAT_011c7830.
// @fnv 0x004e0050
void CreateSpdFadeNode()
{
    DAT_011c7830 = new BSFadeNode("SPD");
}

struct BSFadeNode;


// @fnv 0x004e0320
BSFadeNode* FUN_004e0320()
{
    return DAT_011c7830;
}

struct GlobalObject_00a7b610;

struct FUN_004e0530_shell
{
    GlobalObject_00a7b610* GetGlobalObject();
};

// @fnv 0x004e0530
GlobalObject_00a7b610* FUN_004e0530_shell::GetGlobalObject()
{
    return &::g_011c7844;
}

// @fnv 0x00622ba0
float FUN_00622ba0()
{
    return 32.0f;
}


// @fnv 0x00622bb0
float FUN_00622bb0()
{
    return ::DAT_01032adc;
}

namespace fnv_004e00d0 {
struct BSFadeNode
{
};
struct Holder_004b9900
{
    int FUN_004b9900(int);
};
// Calls FUN_004b9900(1) on DAT_011c7830 if non-null, then sets DAT_011c7830 to null.
// @fnv 0x004e00d0
void FUN_004e00d0()
{
    BSFadeNode* b;
    {
        BSFadeNode* a = (*reinterpret_cast<::fnv_004e00d0::BSFadeNode * *>(&::DAT_011c7830));
        b = a;
    }
    (b ? ((Holder_004b9900*)b)->FUN_004b9900(1) : 0);
    (*reinterpret_cast<::fnv_004e00d0::BSFadeNode * *>(&::DAT_011c7830)) = 0;
}
}  // namespace fnv_004e00d0

struct Flt
{
    operator unsigned int();
};
struct GO
{
    GO& operator=(void*);
};
// @fnv 0x004e0800
void FUN_004e0800()
{
    if (DAT_011c7834)
    {
        reinterpret_cast<::FUN_004def90_Class *>((((NiNode*)((Flt*)&(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)))->operator unsigned int())))->FUN_004def90();
        ((GO*)&(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)))->operator=(0);
        ((GO*)&(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c7840)))->operator=(0);
    }
    DAT_011c7834 = 0;
    for (int i = 0; i < 3; ++i)
        ((GO*)((char*)&DAT_011c7860 + i * 4))->operator=(0);
}

void __cdecl CallWithParam(std::intptr_t);
struct Dummy00622c50
{
    void* FUN_00622c50(unsigned int flags);
};
// Calls FUN_00622d00, then if bit 0 of flags is set calls CallWithParam with this, and returns this.
// @fnv 0x00622c50
void* Dummy00622c50::FUN_00622c50(unsigned int flags)
{
    reinterpret_cast<::FUN_00622d00_Class *>(this)->FUN_00622d00_Class::~FUN_00622d00_Class();
    if (flags & 1)
        CallWithParam((std::intptr_t)this);
    return this;
}

struct IntSetting
{
};
struct FloatSetting
{
};
struct Params
{
    float a, b, c;
    unsigned int d;
};
struct FUN_004e04e0 : NiMemObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_004e04e0(const Params&);
};
class NiFixedString
{
    int value;

  public:
    NiFixedString(const char*);
    ~NiFixedString();
};
struct ObjectProxy
{
};
struct RootProxy
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9c();
    virtual void unka0();
    virtual void unka4();
    virtual void unka8();
    virtual void unkac();
    virtual void unkb0();
    virtual void unkb4();
    virtual void unkb8();
    virtual void unkbc();
    virtual void unkc0();
    virtual void unkc4();
    virtual void unkc8();
    virtual void unkcc();
    virtual void unkd0();
    virtual void unkd4();
    virtual void unkd8();
    virtual void Attach(ObjectProxy*, bool);
};
// If screen splatter is enabled, allocates a splatter proxy for the requested amount, attaches it to the root, and updates it.
// @fnv 0x004e0330
void FUN_004e0330(unsigned int requested, float time)
{
    if (DAT_011c7834)
    {
        unsigned int p = FUN_0042f5a0(requested, *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting *>(&::g_011cf2b8)))))) - DAT_011c7828);
        if (p > 0)
        {
            ObjectProxy* a = ((::ObjectProxy *)(::CreateScatterShapes(p)));
            DAT_011c7828 += p;
            Params s;
            s.c = 1.0f;
            s.a = 0.0f;
            if (time > 0.0)
                s.b = time;
            else
                s.b = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting735))))));
            s.d = p;
            FUN_004e04e0* h = new FUN_004e04e0(s);
            reinterpret_cast<::FUN_00a5bca0_shell *>((a))->SetExtraDataName((::NiExtraData *)(h));
            ::AssignFixedString((char *)(a), (int)&(const ::NiFixedString &)(NiFixedString("ScreenSplatterRoot")), {});
            ((RootProxy*)(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)).operator->())->Attach(a, true);
            ::FUN_00b81420((::S_00b81420_AVObject *)(a), ((std::uintptr_t)(reinterpret_cast<::NonActorMagicTarget *>((h))->GetActiveEffectList())));
            NiUpdateData i(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((RootProxy*)(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)).operator->())))->FUN_00a59c60((std::intptr_t)&(i));
        }
    }
}

struct OpacityFadeState
{
    float age;
    float life;
    float alpha;
    unsigned int count;
};
struct ExtraShell
{
};
struct ObjShell
{
};
struct RootCalls
{
    unsigned int FUN_0043b480();
};
struct SplatterRoot : RootProxy
{
    virtual void SlotA();
    virtual void SlotB();
    virtual void SlotC();
    virtual void SlotD();
    virtual NiAVObject* DetachAt(unsigned int);
};
struct TimeGlobal
{
};
struct SettingF
{
};
extern unsigned int DAT_011c7828;
void __cdecl FUN_004de8a0(float);
void __cdecl FUN_004de8b0(float);
void __cdecl FUN_004de8c0(float);
float __cdecl FUN_004de8d0();

// Advances each splatter child's age by elapsed time, detaches expired ones and decrements DAT_011c7828, fades alpha, updates nodes, and ramps splash5 toward 1.
// @fnv 0x004e0110
void FUN_004e0110()
{
    if (DAT_011c7834)
    {
        float elapsed_2;
        unsigned int count;
        float splash5;
        count = ((RootCalls*)(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)).operator->())->FUN_0043b480();
        elapsed_2 = reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
        for (unsigned int i5 = 0; i5 < count; i5++)
        {
            NiAVObject* child4 = reinterpret_cast<::NiNode *>((((RootCalls*)(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)).operator->())))->GetAt(i5);
            if (child4)
            {
                ExtraShell* extra4 = ((::ExtraShell *)(reinterpret_cast<::NiAVObject *>((((ObjShell*)child4)))->GetExtraData((*(const ::NiFixedString *)(FUN_004e0320())))));
                OpacityFadeState* data = ((::OpacityFadeState *)(::GetOffsetC((std::intptr_t)(extra4))));
                data->age += elapsed_2;
                if (data->age >= data->life)
                {
                    DAT_011c7828 -= data->count;
                    ((SplatterRoot*)(*reinterpret_cast<::NiPointer< ::NiAVObject> *>(&::g_011c786c)).operator->())->DetachAt(i5);
                }
                else
                {
                    if (data->age / data->life >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingF *>(&::originalRuntimeFloatSetting736)))))))
                        data->alpha = 1.0f - LinearInterpolate(0.0f, 1.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingF *>(&::originalRuntimeFloatSetting736)))))) * data->life,
                                                               data->life, data->age);
                    NiUpdateData updateDataA(data->age, true, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((((ObjShell*)child4)))->FUN_00a59c60((std::intptr_t)&(updateDataA));
                }
            }
        }
        FUN_004de8a0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingF *>(&::originalRuntimeFloatSetting742)))))));
        FUN_004de8b0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingF *>(&::g_011cf6a8)))))));
        splash5 = FUN_004de8d0();
        if (splash5 < 1.0)
        {
            splash5 += elapsed_2 / 0.4;
            splash5 = FUN_0040ebd0(1.0f, splash5);
            FUN_004de8c0(splash5);
        }
    }
}

// Constructor-like thiscall with one stack arg: calls a base routine with the
// result of a global getter, stores the class vtable pointer, copies a
// 16-byte value from the argument into the member at +0x0c and returns this.

extern char DAT_01022a24[];

struct FUN_004e04e0_quad
{
    unsigned int a, b, c, d;
};

struct FUN_004e04e0_base
{
};

struct FUN_004e04e0_cls : FUN_004e04e0_base
{
    void* m_pVTable;
    unsigned int m_04;
    unsigned int m_08;
    FUN_004e04e0_quad m_0c;

    FUN_004e04e0_cls* FUN_004e04e0(const FUN_004e04e0_quad* value);
};

// Sets the vtable, copies the given quad into m_0c, and returns this after calling FUN_00a7b440 on FUN_004e0320().
// @fnv 0x004e04e0
FUN_004e04e0_cls* FUN_004e04e0_cls::FUN_004e04e0(const FUN_004e04e0_quad* pQuad)
{
    new ((void *)this) ::NiExtraData((*(const ::NiFixedString *)(FUN_004e0320())));
    m_pVTable = (void*)DAT_01022a24;
    m_0c = *pQuad;
    return this;
}

// If DAT_011cc200 and DAT_011cc1fc are set, calls FUN_00622c50(1) on each, then clears both globals.
// @fnv 0x00622bc0
void FUN_00622bc0()
{
    if (DAT_011cc200)
    {
        FUN_00622c80* a = DAT_011cc200;
        FUN_00622c80* b5 = a;
        b5 ? ((Dummy00622c50*)b5)->FUN_00622c50(1) : 0;
    }
    DAT_011cc200 = 0;
    if (DAT_011cc1fc)
    {
        FUN_00622c80* c = DAT_011cc1fc;
        FUN_00622c80* d = c;
        d ? ((Dummy00622c50*)d)->FUN_00622c50(1) : 0;
    }
    DAT_011cc1fc = 0;
}

class FUN_00620ff0
{
  public:
    FUN_00620ff0();
    ~FUN_00620ff0();
};

class FUN_00633c90
{
  public:
    FUN_00633c90(int iCount);
    ~FUN_00633c90();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

namespace ScreenSplatterImpl {
class FUN_00622c80 : public FUN_00620ff0
{
  public:

  private:
  public:
    FUN_00622c80(float value, unsigned int id);


    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248, unk24C, unk250, unk254, unk258, unk25C, unk260, unk264, unk268, unk26C;
    int unk270, unk274, unk278, unk27C, unk280, unk284, unk288, unk28C, unk290, unk294, unk298, unk29C;
    int unk2A0, unk2A4, unk2A8, unk2AC, unk2B0, unk2B4, unk2B8, unk2BC, unk2C0, unk2C4, unk2C8, unk2CC;
    int unk2D0, unk2D4, unk2D8, unk2DC, unk2E0, unk2E4, unk2E8, unk2EC, unk2F0, unk2F4, unk2F8, unk2FC;
    int unk300, unk304, unk308, unk30C, unk310, unk314, unk318, unk31C, unk320, unk324, unk328, unk32C;
    int unk330, unk334, unk338, unk33C, unk340, unk344, unk348, unk34C, unk350, unk354, unk358, unk35C;
    int unk360, unk364, unk368, unk36C, unk370, unk374, unk378, unk37C, unk380, unk384, unk388, unk38C;
    int unk390, unk394, unk398, unk39C;
    FUN_00633c90 m_kSplatters;
};

// Initializes m_kSplatters, then calls FUN_00622d60 with value and id.
// @fnv 0x00622c80
FUN_00622c80::FUN_00622c80(float value, unsigned int id) : m_kSplatters(0)
{
    reinterpret_cast<::fnv_00622d60::xCaster *>(this)->FUN_00622d60(value, id);
}
}

#include "generated/data/fallout_shared/screensplatter.inc"
