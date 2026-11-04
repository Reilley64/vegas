#pragma once

class BGSDehydrationStage;
class BGSHungerStage;
class BGSSleepDeprevationStage;
class EffectSetting;
class GameSettingCollection;
class GlobalObject2_0040c150;
class GlobalObject2_0045cfe0;
class GlobalObject_0040c150;
class GlobalObject_0044f440;
class GlobalObject_0044fae0;
class GlobalObject_0045cf30;
class GlobalObject_0045cfe0;
class GlobalObject_0045d060;
class GlobalObject_0045d260;
class GlobalObject_00680890;
class GlobalObject_008c71b0;
class GlobalObject_0096a2d0;
class ModelLoader;
class SpellItem;
class TESEffectShader;
class TESGlobal;
class TESObjectCELL;
class TESObjectCONT;
class TESTopicInfo;
class TESWorldSpace;
struct CountSetting;
struct DH;
template <class> class SettingT;

// 0x011c3180
extern "C" extern unsigned int DAT_011c3180;
// 0x011c3184
extern "C" extern ::BGSDehydrationStage **DAT_011c3184;
// 0x011c3198
extern "C" extern unsigned int gHungerStageCount;
// 0x011c319c
extern "C" extern ::BGSHungerStage **gHungerStages;
// 0x011c31b0
extern "C" extern unsigned int DAT_011c31b0;
// 0x011c31b4
extern "C" extern ::BGSSleepDeprevationStage **DAT_011c31b4;
// 0x011c33e0
extern ::GlobalObject_008c71b0 g_011c33e0;
// 0x011c33f4
extern "C" extern ::EffectSetting *DAT_011c33f4;
// 0x011c3400
extern ::GlobalObject_00680890 g_011c3400;
// 0x011c344c
extern ::GlobalObject_0040c150 g_011c344c;
// 0x011c3458
extern ::GlobalObject_0040c150 g_011c3458;
// 0x011c3474
extern ::GlobalObject_0040c150 g_011c3474;
// 0x011c348c
extern ::GlobalObject_0040c150 g_011c348c;
// 0x011c34a0
extern ::GlobalObject_0040c150 g_011c34a0;
// 0x011c34c0
extern ::GlobalObject_0040c150 g_011c34c0;
// 0x011c34d8
extern ::GlobalObject_0040c150 g_011c34d8;
// 0x011c3534
extern bool g_bLimbConditionEffectInitialized;
// 0x011c3580
extern ::TESEffectShader *DAT_011c3580;
// 0x011c3584
extern ::TESEffectShader *DAT_011c3584;
// 0x011c3588
extern ::TESEffectShader *DAT_011c3588;
// 0x011c358c
extern ::SpellItem *DAT_011c358c;
// 0x011c3664
extern ::SettingT< ::GameSettingCollection> originalRuntimeFloatSetting9;
// 0x011c38e4
extern int DAT_011c38e4;
// 0x011c3920
extern ::GlobalObject_0096a2d0 g_011c3920;
// 0x011c399c
extern ::GlobalObject2_0040c150 g_011c399c;
// 0x011c39a8
extern ::GlobalObject_0040c150 g_011c39a8;
// 0x011c39b4
extern ::SettingT< ::GameSettingCollection> originalRuntimeFloatSetting10;
// 0x011c39e8
extern ::GlobalObject_0040c150 g_011c39e8;
// 0x011c3a00
extern ::GlobalObject2_0040c150 g_011c3a00;
// 0x011c3a24
extern ::GlobalObject2_0040c150 g_011c3a24;
// 0x011c3a30
extern ::GlobalObject2_0040c150 g_011c3a30;
// 0x011c3a4c
extern ::GlobalObject2_0040c150 g_011c3a4c;
// 0x011c3a70
extern ::GlobalObject_0040c150 g_011c3a70;
// 0x011c3a94
extern ::GlobalObject_0040c150 g_011c3a94;
// 0x011c3ab0
extern ::GlobalObject2_0040c150 g_011c3ab0;
// 0x011c3ae4
extern int DAT_011c3ae4;
// 0x011c3b38
extern int DAT_011c3b38;
// 0x011c3b3c
extern ::ModelLoader *g_modelLoader;
// 0x011c3b6c
extern ::GlobalObject_0044fae0 g_011c3b6c;
// 0x011c3bb8
extern ::GlobalObject_0044f440 g_011c3bb8;
// 0x011c3be4
extern ::GlobalObject_0044f440 g_011c3be4;
// 0x011c3c08
namespace fnv_00563f30 { extern float DAT_011c3c08; }
// 0x011c3c0c
extern bool DAT_011c3c0c;
// 0x011c3c0f
extern ::GlobalObject_0045d260 g_011c3c0f;
// 0x011c3c10
extern ::GlobalObject_0045cf30 g_011c3c10;
// 0x011c3c30
extern ::GlobalObject_0045cfe0 g_011c3c30;
// 0x011c3c3c
extern ::GlobalObject_0045cfe0 g_011c3c3c;
// 0x011c3c5c
extern ::GlobalObject_0044f440 g_011c3c5c;
// 0x011c3c74
extern ::SettingT< ::GameSettingCollection> originalRuntimeFloatSetting15;
// 0x011c3c90
extern ::CountSetting DAT_011c3c90;
// 0x011c3cb4
extern ::GlobalObject2_0045cfe0 g_011c3cb4;
// 0x011c3ccc
extern ::GlobalObject_0045cf30 g_011c3ccc;
// 0x011c3ce8
extern ::SettingT< ::GameSettingCollection> originalRuntimeFloatSetting17;
// 0x011c3d00
extern ::GlobalObject_0044f440 g_011c3d00;
// 0x011c3d0c
extern ::GlobalObject_0045d060 g_011c3d0c;
// 0x011c3d28
extern ::GlobalObject_0044f440 g_011c3d28;
// 0x011c3d40
extern ::GlobalObject_0045cf30 g_011c3d40;
// 0x011c3d4c
extern ::GlobalObject_0044f440 g_011c3d4c;
// 0x011c3d60
extern ::GlobalObject_0044f440 g_011c3d60;
// 0x011c3d78
extern ::GlobalObject_0045d060 g_011c3d78;
// 0x011c3d84
extern ::GlobalObject_0044fae0 g_011c3d84;
// 0x011c3da0
extern ::GlobalObject_0045cf30 g_011c3da0;
// 0x011c3db0
extern ::SettingT< ::GameSettingCollection> originalRuntimeFloatSetting14;
// 0x011c3dbc
extern ::GlobalObject_0045cf30 g_011c3dbc;
// 0x011c3df4
extern ::GlobalObject_0044f440 g_011c3df4;
// 0x011c3e18
extern ::GlobalObject_0044f440 g_011c3e18;
// 0x011c3e38
extern ::GlobalObject_0045cfe0 g_011c3e38;
// 0x011c3e54
extern ::GlobalObject_0044f440 g_011c3e54;
// 0x011c3e64
extern ::GlobalObject_0045cf30 g_011c3e64;
// 0x011c3e7c
extern ::SettingT< ::GameSettingCollection> originalRuntimeFloatSetting16;
// 0x011c3e94
extern ::GlobalObject_0044f440 g_011c3e94;
// 0x011c3ea4
extern ::GlobalObject_0045cfe0 g_011c3ea4;
// 0x011c3ec0
extern ::GlobalObject_0045d060 g_011c3ec0;
// 0x011c3f2c
extern ::DH *g_dataHandler;
// 0x011c3f30
extern ::TESObjectCELL *DAT_011c3f30;
// 0x011c3f34
extern ::TESWorldSpace *DAT_011c3f34;
// 0x011c3f38
extern ::TESTopicInfo *DAT_011c3f38;
// 0x011c3f3c
extern ::TESGlobal *DAT_011c3f3c;
// 0x011c3f40
extern ::TESObjectCONT *DAT_011c3f40;
// 0x011c3f74
extern ::GlobalObject2_0045cfe0 g_011c3f74;
// 0x011c3fa8
extern ::GlobalObject_0045cf30 g_011c3fa8;
// 0x011c3fd4
extern ::GlobalObject_0045cf30 g_011c3fd4;
