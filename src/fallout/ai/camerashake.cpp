// fallout/ai/camerashake.cpp: FileFinder, Interface (4 functions)

#include <cstdint>
#include "fnv/decl/Controller.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "camerashake_decls.h"
// Clears DAT_011dfecc, builds the CameraShake.nif path, and if it exists loads it via g_modelLoader and sets its name.
// @fnv 0x008d1820
void InitializeCameraShake()
{
    char path[260];
    DAT_011dfecc = 0;
    ::FUN_00406d00(path, 260, "%s\\Characters\\CameraShake.nif", "Meshes");
    if (FileFinder::Exist(path, 0, 0, -1))
    {
        DAT_011dfecc = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(path), 0, true, false, false, false);
        ::AssignFixedString((char *)(DAT_011dfecc), (intptr_t)&(const ::NiFixedString &)(NiFixedString(path)), {});
    }
}

struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
};
struct ModelLoader_target
{
};
// If DAT_011dfecc is set, passes its GetName() string to g_modelLoader's FUN_0045a5e0 and clears DAT_011dfecc.
// @fnv 0x008d1920
void FUN_008d1920()
{
    if (DAT_011dfecc)
    {
        reinterpret_cast<::FUN_0045a5e0_shell *>((((ModelLoader_target*)g_modelLoader)))->FUN_0045a5e0((char *)((const char*)(*(::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((((SeqObj*)DAT_011dfecc)))->GetLinkToList()))));
        DAT_011dfecc = 0;
    }
}

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3& arPoint) const;
public:
    float ComputeMagnitude() const;
};

class SettingFloat
{
  public:
};

struct Controls
{
};

struct OSGlobals
{
};

struct Interface
{
};

struct FUN_0043c490_shell
{
};

struct FUN_00558310_node;

extern float DAT_011dfed4;
extern float DAT_011dfed8;

// @fnv 0x008d1960
void UpdateDistanceFade(float afMult, const NiPoint3& arPos)
{
    float fdelta;
    float fFadeDelta;
    float fFadeStart;
    NiPoint3 cameraPos;

    if (DAT_011dfecc && afMult > 0.0)
    {
        cameraPos = reinterpret_cast<::NiAVObject *>((((::FUN_0043c490_shell *)(::FUN_00558310((::NiNode_00558310 *)(::FUN_00558310_node *)(((::FUN_00558310_node *)(::FUN_0045c670()))))))))->FUN_0043c490();
        fdelta = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((cameraPos - arPos)))->ComputeMagnitude();
        fFadeStart = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1066)))))) * afMult;
        fFadeDelta = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1067)))))) * afMult;
        if (fFadeStart < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1065)))))))
            fFadeStart = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1065))))));
        if (fFadeStart + fFadeDelta > fdelta)
        {
            if (fdelta > fFadeStart)
                afMult = (1.0f - (fdelta - fFadeStart) / fFadeDelta) * afMult;
            if (afMult > 1.0)
                afMult = 1.0f;
            else if (afMult < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011d09dc)))))))
                afMult = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011d09dc))))));
            DAT_011dfed4 = afMult;
            DAT_011dfed8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1063))))));
            if (!::FUN_00702360())
            {
                Controls* pcontrols = reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720();
                reinterpret_cast<::Controller *>((pcontrols))->FUN_00a255b0(DAT_011dfed4 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011d0b3c)))))), DAT_011dfed4 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011d0b3c)))))),
                                        (int)(DAT_011dfed8 * 1000.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011d064c))))))), 0, 0, 0, 0);
            }
        }
    }
}

struct NiUpdateData
{
    float time;
    bool update;
    bool flags;
    int unk08;
    NiUpdateData(float, bool, bool);
};
struct MatrixView
{
    float entries[9];
    MatrixView FUN_0043f8d0(const MatrixView&) const;
};
struct ControllerView
{
};
struct CameraView
{
};
struct TimeView
{
};
// Advances a camera shake timer, samples the camera controller matrix into output, and returns the current shake amount.
// @fnv 0x008d1b30
float UpdateCameraShake(float time, MatrixView* output)
{
    if (DAT_011dfecc && DAT_011dfed4 != 0.0 && DAT_011dfed8 != 0.0)
    {
        ControllerView* second = ((::ControllerView *)(::fnv_0043b230::FUN_0043b230((const char *)(((CameraView*)DAT_011dfecc)))));
        float position = reinterpret_cast<::TESActorBaseData *>((second))->GetHealthRegeneration();
        NiUpdateData first(position, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((CameraView*)DAT_011dfecc)))->FUN_00a59c60((std::intptr_t)&(first));
        MatrixView controller = (*(::MatrixView *)(::FUN_006a9540((char *)(((CameraView*)DAT_011dfecc)))));
        NiUpdateData old(time, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((CameraView*)DAT_011dfecc)))->FUN_00a59c60((std::intptr_t)&(old));
        *output = (*(::MatrixView *)(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(controller))->FUN_004b45b0({}))).FUN_0043f8d0((*(::MatrixView *)(::FUN_006a9540((char *)(((CameraView*)DAT_011dfecc))))));
        DAT_011dfed8 -= reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeView *>(&::g_timeGlobal))))->GetStoredFloatValue();
        if (DAT_011dfed8 < 0.0)
        {
            DAT_011dfed8 = 0.0f;
            DAT_011dfed4 = 0.0f;
        }
        else if (DAT_011dfed8 < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1064)))))))
            return DAT_011dfed4 * DAT_011dfed8 / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1064))))));
    }
    else if (DAT_011dfed8 != 0.0 || DAT_011dfed4 != 0.0)
    {
        DAT_011dfed8 = 0.0f;
        DAT_011dfed4 = 0.0f;
    }
    return DAT_011dfed4;
}

#include "generated/data/fallout/ai/camerashake.inc"
