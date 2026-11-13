// fallout/misc/scenegraph.cpp: SceneGraph, StandIn (5 functions)

#include <new>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00454b70.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_00c51df0.h"
#include "fnv/decl/fnv_00c517b0__FUN_00c517b0.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01083000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_01203000.h"
struct NiRTTI;

class BSSceneGraph
{
  public:
    virtual const NiRTTI* GetRTTI() const;
};

class SceneGraph : public BSSceneGraph
{
  public:
    virtual const NiRTTI* GetRTTI() const;
};

// @fnv 0x00878640
const NiRTTI* SceneGraph::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011df0c0));
}

extern int DAT_01083b5c;

struct Base_00c517b0
{
};

struct Wrapper_00878610 : Base_00c517b0
{
    void* FUN_00878610(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera);
};

// @fnv 0x00878610
void* Wrapper_00878610::FUN_00878610(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera)
{
    new ((void *)this) ::fnv_00c517b0::FUN_00c517b0(apSceneGraphName, abMenuSceneGraph, (::fnv_00c517b0::FUN_00a712f0 *)(apCamera));
    *(int**)this = &DAT_01083b5c;
    return this;
}

struct FUN_008786b0_shell : public SceneGraph
{
    float FUN_008786b0();
    char pad04[0xb4];
    bool unkb8;
    char padb9[0x3];
};

union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
};
class BGSTerrainManager
{
  public:
};
class TESWorldSpace
{
  public:
    BGSTerrainManager* GetWorldTerrainManager();
};
struct Sky
{
  public:
};
class TESObjectCELL
{
  public:
    float GetInteriorLightValue();
};
class BGSCameraPath
{
  public:
    BGSCameraPath* GetPrevPath();
};
class TES
{
  public:
};

extern float DAT_010c26d8;


// @fnv 0x008786b0
float FUN_008786b0_shell::FUN_008786b0()
{
    float ffar;
    if (this->unkb8)
    {
        ffar = DAT_01083c64;
    }
    else if (!(*reinterpret_cast<::TES * *>(&::g_TES)) || !((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetHitSound())) || reinterpret_cast<::FUN_00454b70 *>((((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetHitSound()))->GetWorldTerrainManager()))->GetHasLOD())
    {
        if ((*reinterpret_cast<::TES * *>(&::g_TES)) && ((BGSCameraPath*)(*reinterpret_cast<::TES * *>(&::g_TES)))->GetPrevPath() && ((int)(reinterpret_cast<::FUN_00476c90_Class *>((((::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetBaseTexture()))))->FUN_00476c90())) == 1)
        {
            ffar = ((TESObjectCELL*)((BGSCameraPath*)(*reinterpret_cast<::TES * *>(&::g_TES)))->GetPrevPath())->GetInteriorLightValue();
            if (ffar <= ::_DAT_01012060 || ffar > DAT_010c26d8)
            {
                ffar = DAT_010c26d8;
            }
        }
        else
        {
            ffar = DAT_010c26d8;
        }
    }
    else
    {
        float ffarMax;
        if ((*reinterpret_cast<::TES * *>(&::g_TES)) && ((BGSCameraPath*)(*reinterpret_cast<::TES * *>(&::g_TES)))->GetPrevPath() && ((int)(reinterpret_cast<::FUN_00476c90_Class *>((((::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetBaseTexture()))))->FUN_00476c90())) == 1)
        {
            ffarMax = ((TESObjectCELL*)((BGSCameraPath*)(*reinterpret_cast<::TES * *>(&::g_TES)))->GetPrevPath())->GetInteriorLightValue();
            if (ffarMax <= ::_DAT_01012060 || ffarMax > ((::SETTING_VALUE *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_0120312c))))))->f)
            {
                ffarMax = ((::SETTING_VALUE *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_0120312c))))))->f;
            }
        }
        else
        {
            ffarMax = ((::SETTING_VALUE *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_0120312c))))))->f;
        }
        ffar = LinearInterpolate(((::SETTING_VALUE *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_01203120))))))->f, ffarMax, 0.0f, 1.0f, ((::SETTING_VALUE *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_01203138))))))->f);
    }
    return ffar;
}

struct StandIn
{
    void* DestroyIfFlagged(unsigned int);
};
extern int DAT_01083b5c;

struct FUN_00878690_shell
{
    void FUN_00878690();
};
// Calls FUN_00878690, then frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00878650
void* StandIn::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00878690_shell *>((this))->FUN_00878690();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xC0);
    return this;
}

// @fnv 0x00878690
void FUN_00878690_shell::FUN_00878690()
{
    *(void**)this = (void*)&DAT_01083b5c;
    reinterpret_cast<::FUN_00c51df0 *>(this)->FUN_00c51df0::~FUN_00c51df0();
}

#include "generated/data/fallout/misc/scenegraph.inc"
