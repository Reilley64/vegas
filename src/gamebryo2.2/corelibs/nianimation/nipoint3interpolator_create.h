#ifndef FNV_NIPOINT3INTERPOLATOR_CREATE_H
#define FNV_NIPOINT3INTERPOLATOR_CREATE_H

#include "fnv/decl/B5Owner.h"
#include "fnv/decl/CameraState.h"
#include "fnv/decl/FUN_005d8710_shell.h"
#include "fnv/decl/FUN_008009d0_cls.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0088d7d0_shell.h"
#include "fnv/decl/FUN_00894cc0_shell.h"
#include "fnv/decl/FUN_009c9a50_shell.h"
#include "fnv/decl/FUN_00aa4db0_shell.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/fnv_008bb650__PlayerView.h"
#include "fnv/decl/fnv_009c9ae0__VATS9c9.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004e6000.h"
#include "fnv/symbols_00529000.h"
#include "fnv/symbols_0052a000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00771000.h"
#include "fnv/symbols_009c7000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
class NiPointLight
{
  public:
    char storage[252];
    static void* operator new(unsigned int);
    static void operator delete(void*);
    NiPointLight();
};
class StateNode
{
  public:
};
class ImageSpaceModifierInstanceDOF
{
  public:
    void FUN_005bbd60(bool);
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2(float, float);
};
union SETTING_VALUE
{
  public:
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
};
class VATS
{
  public:
};
class LightTarget
{
  public:
};
class Interface
{
  public:
};
class ShadowLightData
{
  public:
};
class HUDMainMenu
{
  public:
};
class Actor
{
  public:
};
class PlayerCharacter : public Actor
{
  public:
};
class InputManager
{
  public:
public:
    void FUN_00a25410(int);
};
class OSGlobals
{
  public:
};
class GameTimerRecord
{
  public:
};
class GlobalObject_009c6a30
{
};
class TimeGlobal
{
};
class ShadowSceneNode
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_e8(class NiAVObject*);
    void AttachLight(class NiAVObject*);
};
class ExtraDataList
{
  public:
};
class TemporaryEffect
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual ~TemporaryEffect();
};
#endif
