// fallout_shared/screencustomsplatter.cpp: ScreenCustomSplatter, BSPortal, BSCustomSplatterExtraData (15 functions)

#include "fnv/decl/CamLook.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/FUN_00a7b300_shell.h"
#include "fnv/decl/FUN_00c5dea0_Class.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b81000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "screencustomsplatter_decls.h"
// Iterates the entries array and calls FUN_00c5dea0 on each non-null PortalEntry before destruction.
// @fnv 0x00c50930
BSPortal::~BSPortal()
{
    unsigned int count = entries.count;
    for (unsigned int uiIndex = 0; uiIndex < count; uiIndex++)
    {
        PortalEntry* value;
        PortalEntry* slot;
        PortalEntry*& entry = entries.data[uiIndex];
        slot = entry;
        value = slot;
        if (value)
            reinterpret_cast<::FUN_00c5dea0_Class *>((value))->FUN_00c5dea0();
    }
}
// @fnv 0x004defb0
void ScreenCustomSplatter::Clear()
{
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011c77e8)))
    {
        reinterpret_cast<::FUN_004def90_Class *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c7810))).operator->()))->FUN_004def90();
        DAT_011c77dc = 0;
        DAT_011c77ec = 0.0f;
        DAT_011c77e9 = 0;
        SkyTextureManager::LoadTextureFromPath(&(*reinterpret_cast<::NiPointer< ::NiTexture> *>(&::g_spDebrisTexture)), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011ce918))))->GetMenuTitle())));
        SkyTextureManager::LoadTextureFromPath(&(*reinterpret_cast<::NiPointer< ::NiTexture> *>(&::g_spDebrisNormalMap)), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011ce284))))->GetMenuTitle())));
        if (DAT_011f941e)
            SkyTextureManager::LoadTextureFromPath(&(*reinterpret_cast<::NiPointer< ::NiTexture> *>(&::g_spDebrisShadowTexture)), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cede8))))->GetMenuTitle())));
    }
}
// @fnv 0x004deb30
void ScreenCustomSplatter::Init()
{
    AutoMemContext mem(MEM_CONTEXT_SCREEN, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ScreenCustomSplatter.cpp", 189);
    (*reinterpret_cast<unsigned char *>(&::DAT_011c77e8)) = (*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011c77f4)).Bool()->b;
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011c77e8)))
    {
        GraphicsRenderer* renderer = reinterpret_cast<GraphicsRenderer*>(FUN_0043c4b0());
        float fAspect = (float)renderer->GetRenderTargetWidth() / (float)renderer->GetRenderTargetHeight();
        reinterpret_cast<NiPointer<NiAVObject>&>((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c781c))) = new FUN_00a712f0;
        reinterpret_cast<::FUN_00440460_S *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c781c))).operator->()))->FUN_00440460((const ::V3 *)&(const ::NiPoint3 &)(NiPoint3(0.0f, 0.0f, DAT_01022960)));
        NiUpdateData update1(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c781c))).operator->()))->FUN_00a59c60((int)&(update1));
        reinterpret_cast<::CamLook *>((reinterpret_cast<NiCamera*>((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c781c)).operator->())))->SetLookAt((const ::CamPoint &)(NiPoint3::ZERO), (const ::CamPoint &)(DAT_011a9478));
        NiFrustum frustum(false);
        frustum.ortho = false;
        frustum.top = ::fnv_00c88020::DAT_01016248;
        frustum.bottom = DAT_0102295c;
        frustum.left = (float)(fAspect * DAT_01011598);
        frustum.right = (float)(fAspect * DAT_01011588);
        frustum.farPlane = DAT_01022958;
        frustum.nearPlane = 1.0f;
        reinterpret_cast<NiCamera*>((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c781c)).operator->())->UpdateViewFrustum(frustum);
        NiUpdateData update2(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c781c))).operator->()))->FUN_00a59c60((int)&(update2));
        ::g_fDebrisRangeX = frustum.right;
        ::g_fDebrisRangeY = frustum.top;
        DAT_011c77ec = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting736))))))->f;
        DAT_011c77e9 = 0;
        reinterpret_cast<NiPointer<NiAVObject>&>((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c7810))) = new NiNode(0);
        DAT_011c77dc = 0;
        SkyTextureManager::LoadTextureFromPath(&(*reinterpret_cast<::NiPointer< ::NiTexture> *>(&::g_spDebrisTexture)), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011ce918))))->GetMenuTitle())));
        SkyTextureManager::LoadTextureFromPath(&(*reinterpret_cast<::NiPointer< ::NiTexture> *>(&::g_spDebrisNormalMap)), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011ce284))))->GetMenuTitle())));
        if (DAT_011f941e)
            SkyTextureManager::LoadTextureFromPath(&(*reinterpret_cast<::NiPointer< ::NiTexture> *>(&::g_spDebrisShadowTexture)), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cede8))))->GetMenuTitle())));
    }
}

class BSFadeNode
{
  public:
    int m_iFadeNodeMode;
    BSFadeNode(const char*);
};
extern BSFadeNode* DAT_011c77e4;
// Allocates a BSFadeNode constructed from the string "CSD" and stores it in DAT_011c77e4.
// @fnv 0x004de580
void CreateCSDFadeNode()
{
    DAT_011c77e4 = new BSFadeNode("CSD");
}

// @fnv 0x004de890
BSFadeNode* FUN_004de890()
{
    return DAT_011c77e4;
}

extern float DAT_011feda4;

// @fnv 0x004de8a0
void FUN_004de8a0(float value)
{
    DAT_011feda4 = value;
}


// @fnv 0x004de8b0
void FUN_004de8b0(float value)
{
    DAT_011ad874 = value;
}


// @fnv 0x004de8c0
void FUN_004de8c0(float f)
{
    DAT_011ad878 = f;
}


// @fnv 0x004de8d0
float FUN_004de8d0()
{
    return DAT_011ad878;
}

struct NiRTTI
{
};

struct BSCustomSplatterExtraData
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x004dead0
const NiRTTI* BSCustomSplatterExtraData::GetRTTI() const
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_011c7820));
}

struct FUN_004deb10_shell
{
    void FUN_004deb10();
};

// @fnv 0x004deb10
void FUN_004deb10_shell::FUN_004deb10()
{
    reinterpret_cast<::FUN_00a7b300_shell *>(this)->FUN_00a7b300();
}

extern int DAT_010228c4;
struct NiExtraData
{
    char _pad[12];
    NiExtraData(BSFadeNode*);
};
struct Vector4f
{
    int a, b, c, d;
};
struct FUN_004dea80 : NiExtraData
{
    Vector4f q;
    FUN_004dea80(Vector4f* p);
};
// Initialises a NiExtraData-derived object with a vtable pointer and copies the four ints from p into its q member.
// @fnv 0x004dea80
FUN_004dea80::FUN_004dea80(Vector4f* apSource) : NiExtraData(FUN_004de890())
{
    *(int*)this = (int)&DAT_010228c4;
    q = *apSource;
}

struct FUN_004deae0_holder
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004deb10 on this, then deletes this with size 0x1c when bit 0 of flags is set, and returns this.
// @fnv 0x004deae0
void* FUN_004deae0_holder::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<FUN_004deb10_shell*>(this)->FUN_004deb10();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x1c);
    return this;
}

struct OpacityFadeState
{
    float elapsed;
    float duration;
    float opacity;
    unsigned int count;
};
struct SplatterExtra : NiExtraData
{
};
struct SplatterObject : NiAVObject
{
};
struct SplatterNode : NiNode
{
    virtual void virtual00();
    virtual void virtual01();
    virtual void virtual02();
    virtual void virtual03();
    virtual void virtual04();
    virtual void virtual05();
    virtual void virtual06();
    virtual void virtual07();
    virtual void virtual08();
    virtual void virtual09();
    virtual void virtual0a();
    virtual void virtual0b();
    virtual void virtual0c();
    virtual void virtual0d();
    virtual void virtual0e();
    virtual void virtual0f();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual1a();
    virtual void virtual1b();
    virtual void virtual1c();
    virtual void virtual1d();
    virtual void virtual1e();
    virtual void virtual1f();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual2a();
    virtual void virtual2b();
    virtual void virtual2c();
    virtual void virtual2d();
    virtual void virtual2e();
    virtual void virtual2f();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual3a();
    virtual void virtual3b();
    virtual void RemoveAt(unsigned int);
    unsigned int FUN_0043b480();
};
struct TimeGlobal
{
};

// Advances each splatter child's elapsed time, removes expired ones, updates opacity and NiUpdateData, then advances the fade value toward 1.
// @fnv 0x004de600
void FUN_004de600()
{
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011c77e8)))
    {
        unsigned int uiChildCount = reinterpret_cast<SplatterNode*>((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c7810)).operator->())->FUN_0043b480();
        float elapsed = reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
        for (unsigned int index = 0; index < uiChildCount; ++index)
        {
            SplatterObject* child = static_cast<SplatterObject*>(
                reinterpret_cast<::NiNode *>((reinterpret_cast<SplatterNode*>((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c7810)).operator->())))->GetAt(index));
            if (child)
            {
                SplatterExtra* extra = ((::SplatterExtra *)(reinterpret_cast<::NiAVObject *>((child))->GetExtraData((*(const ::NiFixedString *)(FUN_004de890())))));
                OpacityFadeState* data = ((::OpacityFadeState *)(::GetOffsetC((int)(extra))));
                data->elapsed += elapsed;
                if (data->elapsed >= data->duration)
                {
                    DAT_011c77dc -= data->count;
                    reinterpret_cast<SplatterNode*>((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011c7810)).operator->())->RemoveAt(index);
                }
                else
                {
                    if (!DAT_011c77e9 && data->elapsed / data->duration >= DAT_011c77ec)
                    {
                        data->opacity = 1.0f - LinearInterpolate(0.0f, 1.0f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting736))))))->f * data->duration,
                                                                 data->duration, data->elapsed);
                    }
                    else if (DAT_011c77e9 && data->elapsed >= data->duration - DAT_011c77ec)
                    {
                        float fFadeFraction = (data->duration - DAT_011c77ec) / data->duration;
                        data->opacity = 1.0f - LinearInterpolate(0.0f, 1.0f, fFadeFraction * data->duration,
                                                                 data->duration, data->elapsed);
                    }
                    NiUpdateData updateData(data->elapsed, true, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((child))->FUN_00a59c60((int)&(updateData));
                }
            }
        }
        FUN_004de8a0(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting742))))))->f);
        FUN_004de8b0(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cf6a8))))))->f);
        float fade = FUN_004de8d0();
        if (fade < 1.0)
        {
            fade += elapsed / 0.4;
            fade = FUN_0040ebd0(1.0f, fade);
            FUN_004de8c0(fade);
        }
    }
}

struct NiFixedString
{
    const char* m_kHandle;
    NiFixedString(const char* str);
    ~NiFixedString();
};

struct SplatterParams
{
    float fStart;
    float fAlpha;
    float fScale;
    unsigned int ItemUpdateArray;
};

struct SplatterExtraData : NiExtraData
{
    SplatterParams params;
    SplatterExtraData(SplatterParams* p);
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

struct SplatterGeometry
{
};

struct SplatterRoot
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
    virtual void AttachChildInAvailableSlot(SplatterGeometry* pChild, bool abFirstAvailableSlot);
};



// @fnv 0x004de8e0
void FUN_004de8e0(unsigned int ItemUpdateArray, float fAlpha, int iUnused, float fSizeMin, float fSizeMax)
{
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011c77e8)))
    {
        unsigned int uiNum_2 = ItemUpdateArray;
        if (uiNum_2 > 0)
        {
            SplatterGeometry* pGeom = ((::SplatterGeometry *)(::CreateDebrisNode(uiNum_2, fSizeMin, fSizeMax)));
            DAT_011c77dc += uiNum_2;
            SplatterParams kParams2;
            kParams2.fScale = 1.0f;
            kParams2.fStart = 0.0f;
            if (fAlpha > 0.0)
            {
                kParams2.fAlpha = fAlpha;
            }
            else
            {
                kParams2.fAlpha = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting735))))))->f;
            }
            kParams2.ItemUpdateArray = uiNum_2;
            SplatterExtraData* pExtraData = new SplatterExtraData(&kParams2);
            reinterpret_cast<::FUN_00a5bca0_shell *>((pGeom))->SetExtraDataName((::NiExtraData *)(pExtraData));
            ::AssignFixedString((char *)(pGeom), (int)&(const ::NiFixedString &)(NiFixedString("ScreenSplatterRoot")), {});
            (*reinterpret_cast<::NiPointer< ::SplatterRoot> *>(&::g_011c7810))->AttachChildInAvailableSlot(pGeom, true);
            ::FUN_00b81420((::S_00b81420_AVObject *)(pGeom), (int)(((void *)(reinterpret_cast<::NonActorMagicTarget *>((pExtraData))->GetActiveEffectList()))));
            NiUpdateData kUpdate(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((*reinterpret_cast<::NiPointer< ::SplatterRoot> *>(&::g_011c7810))).operator->()))->FUN_00a59c60((int)&(kUpdate));
        }
    }
}
