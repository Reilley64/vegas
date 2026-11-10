#pragma once

class A29F00Stream;
class A3D370Stream;
class AnimationKey;
class BooleanKey;
class ColorAnimationKey;
class GlobalObjectO2_00a7b610;
class GlobalObject_00a7b610;
class MenuClassArray;
class NiColorKeyA3D;
class NiQuaternion;
struct NiStream;
class PositionKeyInterpolator;
struct ScrapHeapBuffer;
class ScrapListShell;
class Setting_01017720_011f96a0;
class TimedRotationKey;
namespace fnv_00a00a30 { class FadeNodeA00; }
namespace fnv_00a00a30 { class TileTemplateA00; }
namespace fnv_00a00a30 { template <class> class SimpleListA00; }
namespace fnv_00a1ca20 { struct ScrapHeapBuffer; }
namespace fnv_00a1ca20 { template <class, class> class BSMapBase; }
struct A0A220HandlerMap;
struct A29FE0Context;
struct FUN_004de530;
struct FUN_00a25b00;
struct LegacyD810;
struct MyPosKey;
struct NiStream2;
struct PendingObj;
struct Record;
struct S009ff340_List;
struct S_a3d410_Stream;
template <class, class> class BSMapBase;
template <class, class> struct BSMapBase;

// 0x011f308f
extern bool DAT_011f308f[];
// 0x011f3298
extern int DAT_011f3298;
// 0x011f329c
extern void * DAT_011f329c[];
// 0x011f32c8
namespace fnv_00a01b00 { extern unsigned char DAT_011f32c8; }
// 0x011f32c9
namespace fnv_00a04200 { extern bool DAT_011f32c9; }
// 0x011f32d4
extern int DAT_011f32d4;
// 0x011f32d8
extern int DAT_011f32d8;
// 0x011f32dc
extern int DAT_011f32dc;
// 0x011f32f4
extern ::BSMapBase<unsigned long, ::ScrapHeapBuffer *> DAT_011f32f4;
// 0x011f3308
extern ::ScrapListShell DAT_011f3308;
// 0x011f3318
extern ::S009ff340_List DAT_011f3318;
// 0x011f3320
extern int DAT_011f3320;
// 0x011f3324
extern ::S009ff340_List DAT_011f3324;
// 0x011f3330
extern char DAT_011f3330;
// 0x011f3348
namespace fnv_00a00a30 { extern ::fnv_00a00a30::SimpleListA00< ::fnv_00a00a30::FadeNodeA00 *> DAT_011f3348; }
// 0x011f3350
namespace fnv_00a00a30 { extern ::fnv_00a00a30::SimpleListA00< ::fnv_00a00a30::TileTemplateA00 *> DAT_011f3350; }
// 0x011f3358
extern ::A0A220HandlerMap g_kA0A220Handlers;
// 0x011f3368
extern ::Setting_01017720_011f96a0 g_011f3368;
// 0x011f33a8
extern ::PendingObj *g_011f33a8;
// 0x011f33bc
extern int DAT_011f33bc;
// 0x011f33c8
extern ::Setting_01017720_011f96a0 g_011f33c8;
// 0x011f33d4
extern ::GlobalObject_00a7b610 g_011f33d4;
// 0x011f33f8
extern ::Record **DAT_011f33f8;
// 0x011f34cc
namespace tileext { extern const char *DAT_011f34cc; }
// 0x011f34e0
extern ::BSMapBase<unsigned long, ::ScrapHeapBuffer *> DAT_011f34e0;
// 0x011f34f4
namespace fnv_00a1ca20 { extern ::fnv_00a1ca20::BSMapBase<unsigned long, ::fnv_00a1ca20::ScrapHeapBuffer *> DAT_011f34f4; }
// 0x011f3508
extern ::MenuClassArray g_menuByClassArray;
// 0x011f35a0
extern ::FUN_004de530 *DAT_011f35a0;
// 0x011f35b4
extern short DAT_011f35b4;
// 0x011f35b6
extern short DAT_011f35b6;
// 0x011f35cc
extern char *DAT_011f35cc;
// 0x011f35d0
extern ::Setting_01017720_011f96a0 g_011f35d0;
// 0x011f35dc
extern ::Setting_01017720_011f96a0 g_011f35dc;
// 0x011f35e8
extern ::Setting_01017720_011f96a0 g_011f35e8;
// 0x011f35f4
extern ::Setting_01017720_011f96a0 g_011f35f4;
// 0x011f3600
extern ::Setting_01017720_011f96a0 g_011f3600;
// 0x011f360c
extern ::Setting_01017720_011f96a0 g_011f360c;
// 0x011f3618
extern ::Setting_01017720_011f96a0 g_011f3618;
// 0x011f3634
extern ::FUN_00a25b00 *DAT_011f3634Q;
// 0x011f3638
extern ::Setting_01017720_011f96a0 g_011f3638;
// 0x011f369d
extern bool DAT_011f369d;
// 0x011f36ac
extern ::GlobalObjectO2_00a7b610 g_011f36ac;
// 0x011f36b4
extern ::GlobalObjectO2_00a7b610 g_011f36b4;
// 0x011f36bc
extern ::GlobalObjectO2_00a7b610 g_011f36bc;
// 0x011f36dc
extern ::GlobalObjectO2_00a7b610 g_011f36dc;
// 0x011f36e4
extern ::GlobalObjectO2_00a7b610 g_011f36e4;
// 0x011f36ec
extern ::GlobalObjectO2_00a7b610 g_011f36ec;
// 0x011f36f4
extern int DAT_011f36f4;
// 0x011f36f8
extern int DAT_011f36f8;
// 0x011f36fc
extern ::GlobalObjectO2_00a7b610 g_011f36fc;
// 0x011f3704
extern ::NiQuaternion DAT_011f3704;
// 0x011f3708
extern int DAT_011f3708;
// 0x011f370c
extern int DAT_011f370c;
// 0x011f3710
extern int DAT_011f3710;
// 0x011f3714
extern ::GlobalObjectO2_00a7b610 g_011f3714;
// 0x011f371c
extern ::GlobalObjectO2_00a7b610 g_011f371c;
// 0x011f3728
extern ::GlobalObjectO2_00a7b610 g_011f3728;
// 0x011f3730
extern ::GlobalObjectO2_00a7b610 g_011f3730;
// 0x011f3738
extern ::GlobalObjectO2_00a7b610 g_011f3738;
// 0x011f3740
extern ::GlobalObjectO2_00a7b610 g_011f3740;
// 0x011f3748
extern ::GlobalObjectO2_00a7b610 g_011f3748;
// 0x011f3750
extern ::GlobalObjectO2_00a7b610 g_011f3750;
// 0x011f3758
extern unsigned char DAT_011f3758[];
// 0x011f375e
extern unsigned char DAT_011f375e[];
// 0x011f3760
extern char DAT_011f3760;
// 0x011f376a
extern unsigned char DAT_011f376a[];
// 0x011f3776
extern unsigned char DAT_011f3776[6];
// 0x011f3780
extern int DAT_011f3780;
// 0x011f37b0
extern void (*DAT_011f37b0[])(TimedRotationKey *, unsigned int, unsigned char);
// 0x011f37f8
extern void (*DAT_011f37f8[6])(AnimationKey *, unsigned int, unsigned char);
// 0x011f3810
extern bool (*g_fnv_cb_011f3810[])(float, int *, int *);
// 0x011f38a0
extern void (*DAT_011f38a0[])(void *);
// 0x011f38b8
extern void (*DAT_011f38b8[])(PositionKeyInterpolator *);
// 0x011f38c0
extern void (*FUN_00a28cb0_aTable4[36])();
// 0x011f38e8
extern void (*DAT_011f38e8[])(ColorAnimationKey *);
// 0x011f3918
extern void (*DAT_011f3918[6])(AnimationKey *);
// 0x011f3930
extern void *(*DAT_011f3930[])(unsigned int);
// 0x011f3950
extern void (*FUN_00a28cb0_aTable2[36])();
// 0x011f39c0
extern void (*DAT_011f39c0[])(void *, const void *);
// 0x011f39e0
extern void (*FUN_00a28cb0_aTable5[36])();
// 0x011f3a50
extern void (*g_apfnA29FE0Load[])(A29FE0Context *, void *, unsigned int);
// 0x011f3a68
extern void (*g_011f3a68[])(NiStream &, PositionKeyInterpolator *, unsigned int);
// 0x011f3a70
extern void (*FUN_00a28cb0_aTable3[36])();
// 0x011f3a80
extern void (*DAT_011f3a80[])(NiStream2 &, TimedRotationKey *, unsigned int);
// 0x011f3a98
extern void (*DAT_011f3a98[])(S_a3d410_Stream *, int, unsigned int);
// 0x011f3ac8
extern "C" extern void (*DAT_011f3ac8[6])(NiStream &, BooleanKey *, unsigned int);
// 0x011f3ae0
extern int DAT_011f3ae0;
// 0x011f3af8
extern bool (*DAT_011f3af8[6])(void *, void *);
// 0x011f3b10
extern bool (*DAT_011f3b10[6])(void *, void *);
// 0x011f3b28
extern bool (*DAT_011f3b28[])(ColorAnimationKey *, ColorAnimationKey *);
// 0x011f3b70
extern int DAT_011f3b70;
// 0x011f3c00
extern int DAT_011f3c00;
// 0x011f3c18
extern void (*DAT_011f3c18[6])(float, const AnimationKey *, const AnimationKey *, void *);
// 0x011f3c90
extern int DAT_011f3c90;
// 0x011f3ca8
extern void * DAT_011f3ca8[];
// 0x011f3cd8
extern int *(*volatile DAT_011f3cd8)(int, int, int, int *);
// 0x011f3d20
extern int DAT_011f3d20;
// 0x011f3d38
extern float (*DAT_011f3d38[])(MyPosKey *, unsigned int);
// 0x011f3db0
extern void *(*DAT_011f3db0[])(A29F00Stream &, unsigned int);
// 0x011f3dc8
extern PositionKeyInterpolator *(*DAT_011f3dc8[])(NiStream &, unsigned int);
// 0x011f3dd0
extern void (*FUN_00a28cb0_aTable11[36])();
// 0x011f3de0
extern TimedRotationKey *(*DAT_011f3de0[])(NiStream &, unsigned int);
// 0x011f3df8
extern NiColorKeyA3D *(*g_apfnColorKeyCreateA3D[])(A3D370Stream &, unsigned int);
// 0x011f3e28
extern AnimationKey *(*DAT_011f3e28[6])(NiStream &, unsigned int);
// 0x011f3e48
extern ::GlobalObjectO2_00a7b610 g_011f3e48;
// 0x011f3e50
extern ::GlobalObjectO2_00a7b610 g_011f3e50;
// 0x011f3e58
extern ::GlobalObjectO2_00a7b610 g_011f3e58;
// 0x011f3e64
extern ::GlobalObjectO2_00a7b610 g_011f3e64;
// 0x011f3e6c
extern ::GlobalObjectO2_00a7b610 g_011f3e6c;
// 0x011f3e74
extern ::GlobalObjectO2_00a7b610 g_011f3e74;
// 0x011f3ec8
extern ::GlobalObjectO2_00a7b610 g_011f3ec8;
// 0x011f3ed0
extern ::GlobalObjectO2_00a7b610 g_011f3ed0;
// 0x011f3ed8
extern ::GlobalObjectO2_00a7b610 g_011f3ed8;
// 0x011f3ee0
extern ::GlobalObjectO2_00a7b610 g_011f3ee0;
// 0x011f3ee8
extern ::GlobalObjectO2_00a7b610 g_011f3ee8;
// 0x011f3ef0
extern ::GlobalObjectO2_00a7b610 g_011f3ef0;
// 0x011f3ef8
extern ::GlobalObjectO2_00a7b610 g_011f3ef8;
// 0x011f3f00
extern ::GlobalObjectO2_00a7b610 g_011f3f00;
// 0x011f3f08
extern ::GlobalObjectO2_00a7b610 g_011f3f08;
// 0x011f3f10
extern ::GlobalObjectO2_00a7b610 g_011f3f10;
// 0x011f3f18
extern ::GlobalObjectO2_00a7b610 g_011f3f18;
// 0x011f3f20
extern ::GlobalObjectO2_00a7b610 g_011f3f20;
// 0x011f3f28
extern ::GlobalObjectO2_00a7b610 g_011f3f28;
// 0x011f3f30
extern ::GlobalObjectO2_00a7b610 g_011f3f30;
// 0x011f3f38
extern ::GlobalObjectO2_00a7b610 g_011f3f38;
// 0x011f3f48
extern ::GlobalObjectO2_00a7b610 g_011f3f48;
// 0x011f3f50
extern ::GlobalObjectO2_00a7b610 g_011f3f50;
// 0x011f3f58
extern ::GlobalObjectO2_00a7b610 g_011f3f58;
// 0x011f3f60
extern ::GlobalObjectO2_00a7b610 g_011f3f60;
// 0x011f3f68
extern ::GlobalObjectO2_00a7b610 g_011f3f68;
// 0x011f3f70
extern ::GlobalObjectO2_00a7b610 g_011f3f70;
// 0x011f3f80
extern ::GlobalObjectO2_00a7b610 g_011f3f80;
// 0x011f3f88
extern ::GlobalObjectO2_00a7b610 g_011f3f88;
// 0x011f3f90
extern ::GlobalObjectO2_00a7b610 g_011f3f90;
// 0x011f3f98
extern ::GlobalObjectO2_00a7b610 g_011f3f98;
// 0x011f3fa0
extern ::GlobalObjectO2_00a7b610 g_011f3fa0;
// 0x011f3fa8
extern ::GlobalObjectO2_00a7b610 g_011f3fa8;
// 0x011f3fb0
extern ::LegacyD810 *DAT_011f3fb0;
// 0x011f3fb4
extern ::GlobalObjectO2_00a7b610 g_011f3fb4;
// 0x011f3fbc
extern ::GlobalObjectO2_00a7b610 g_011f3fbc;
// 0x011f3fc4
extern ::GlobalObjectO2_00a7b610 g_011f3fc4;
// 0x011f3fcc
extern ::GlobalObjectO2_00a7b610 g_011f3fcc;
// 0x011f3fd4
extern ::GlobalObjectO2_00a7b610 g_011f3fd4;
// 0x011f3fdc
extern ::GlobalObjectO2_00a7b610 g_011f3fdc;
// 0x011f3fe4
extern ::GlobalObjectO2_00a7b610 g_011f3fe4;
// 0x011f3ff4
extern ::GlobalObjectO2_00a7b610 g_011f3ff4;
// 0x011f3ffc
extern ::GlobalObjectO2_00a7b610 g_011f3ffc;
