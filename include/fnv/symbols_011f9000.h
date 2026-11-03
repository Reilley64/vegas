#pragma once

class B57FF0RefObject;
class B58070AVObject;
class BSTextureManager;
class GlobalObjectO2_0045cf30;
class GlobalObjectO2_0045cfe0;
class GlobalObjectO2_00a7b610;
class NiAVObject;
class NiCamera;
class NiGeometry;
class NiPoint2;
class NiRefObject;
class NiRenderer;
class NiTexture;
class SetColl_011f96a0_0044f570;
class ShaderBufferCollection;
class ShaderEntryBase;
class ShadowSceneNode;
namespace fnv_00b54630 { class NP; }
namespace fnv_00b5ddf0 { struct LocalLock; }
struct BSRenderedTexture;
struct C0BC90Texture;
struct Camera;
struct ImageSpaceManager;
struct NLPlane;
struct NiTexture;
struct TextureReceiver;
template <class> class NiPointer;

// 0x011f912c
extern "C" extern int randomInitCount;
// 0x011f9138
extern int DAT_011f9138;
// 0x011f9140
extern ::GlobalObjectO2_00a7b610 g_011f9140;
// 0x011f9148
extern ::GlobalObjectO2_0045cfe0 g_011f9148;
// 0x011f9168
extern int DAT_011f9168;
// 0x011f916c
extern int DAT_011f916c;
// 0x011f9170
namespace fnv_00b54630 { namespace CleanupState { extern ::fnv_00b54630::NP *DAT_011f9170; } }
// 0x011f917c
extern ::NiCamera *DAT_011f917c;
// 0x011f9180
extern unsigned char DAT_011f9180;
// 0x011f9181
extern bool DAT_011f9181;
// 0x011f9183
extern bool DAT_011f9183;
// 0x011f9184
extern float DAT_011f9184;
// 0x011f9188
extern float DAT_011f9188;
// 0x011f918c
extern float DAT_011f918c;
// 0x011f9190
extern float DAT_011f9190;
// 0x011f9194
extern bool DAT_011f9194;
// 0x011f91a3
extern bool DAT_011f91a3;
// 0x011f91a4
extern unsigned char DAT_011f91a4;
// 0x011f91a7
extern unsigned char DAT_011f91a7;
// 0x011f91a8
extern ::BSTextureManager *DAT_011f91a8;
// 0x011f91ac
extern ::ImageSpaceManager *DAT_011f91ac;
// 0x011f91b0
extern unsigned int DAT_011f91b0;
// 0x011f91b8
extern unsigned int DAT_011f91b8;
// 0x011f91bc
extern unsigned int DAT_011f91bc;
// 0x011f91c0
extern int DAT_011f91c0;
// 0x011f91c4
extern unsigned char DAT_011f91c4;
// 0x011f91c6
extern bool DAT_011f91c6;
// 0x011f91c8
extern ShadowSceneNode * DAT_011f91c8[4];
// 0x011f91d8
namespace fnv_005bf7b0 { extern int DAT_011f91d8; }
// 0x011f91dc
extern bool DAT_011f91dc;
// 0x011f91dd
extern bool DAT_011f91dd;
// 0x011f91e0
extern ::NiGeometry **DAT_011f91e0;
// 0x011f91e4
extern unsigned int DAT_011f91e4;
// 0x011f91ec
extern unsigned int (*DAT_011f91ec)(NiAVObject *);
// 0x011f91f0
extern float (*DAT_011f91f0)(int);
// 0x011f9200
extern bool DAT_011f9200;
// 0x011f9308
extern char DAT_011f9308[];
// 0x011f940c
extern float DAT_011f940c;
// 0x011f9410
extern float DAT_011f9410;
// 0x011f941c
extern unsigned short DAT_011f941c;
// 0x011f941e
extern bool DAT_011f941e;
// 0x011f941f
extern bool DAT_011f941f;
// 0x011f9420
extern bool DAT_011f9420;
// 0x011f9421
extern bool DAT_011f9421;
// 0x011f9422
extern char DAT_011f9422;
// 0x011f9425
extern unsigned char DAT_011f9425;
// 0x011f9426
extern bool DAT_011f9426;
// 0x011f9427
extern unsigned char DAT_011f9427;
// 0x011f9428
namespace fnv_004da670 { extern float DAT_011f9428; }
// 0x011f9430
extern int DAT_011f9430;
// 0x011f9434
extern int DAT_011f9434;
// 0x011f9438
extern ::BSRenderedTexture *DAT_011f9438;
// 0x011f943c
extern ::TextureReceiver *DAT_011f943c;
// 0x011f9440
extern unsigned char DAT_011f9440;
// 0x011f9444
namespace sb9e { extern "C" extern float DAT_011f9444; }
// 0x011f9448
namespace sb9e { extern "C" extern float DAT_011f9448; }
// 0x011f944c
namespace sb9e { extern "C" extern int DAT_011f944c; }
// 0x011f9450
namespace sb9e { extern "C" extern int DAT_011f9450; }
// 0x011f9454
extern float DAT_011f9454;
// 0x011f9458
extern float DAT_011f9458;
// 0x011f945c
extern float DAT_011f945c;
// 0x011f9460
extern float DAT_011f9460;
// 0x011f9464
extern float DAT_011f9464;
// 0x011f9468
extern float DAT_011f9468;
// 0x011f946c
extern float DAT_011f946c;
// 0x011f9470
extern float DAT_011f9470;
// 0x011f9474
extern float DAT_011f9474;
// 0x011f9478
extern float DAT_011f9478;
// 0x011f947c
extern float DAT_011f947c;
// 0x011f948a
extern bool DAT_011f948a;
// 0x011f948b
extern bool DAT_011f948b;
// 0x011f948c
extern int DAT_011f948c;
// 0x011f9490
extern int DAT_011f9490;
// 0x011f9498
extern ::ShaderBufferCollection *DAT_011f9498;
// 0x011f94a4
extern bool DAT_011f94a4;
// 0x011f94a6
extern unsigned char DAT_011f94a6;
// 0x011f94a9
extern char DAT_011f94a9;
// 0x011f94aa
extern bool DAT_011f94aa;
// 0x011f94ab
namespace fnv_00454450 { extern bool reloadHasWorld; }
// 0x011f94ac
extern float DAT_011f94ac;
// 0x011f94b4
extern bool DAT_011f94b4;
// 0x011f94b8
extern int DAT_011f94b8;
// 0x011f94bc
extern int g_00539f40;
// 0x011f94f8
extern ::GlobalObjectO2_0045cf30 g_011f94f8;
// 0x011f9508
extern ::NiRenderer *DAT_011f9508;
// 0x011f950c
extern int DAT_011f950c;
// 0x011f9510
extern int DAT_011f9510;
// 0x011f9514
extern ::C0BC90Texture *g_pkC0BC90DefaultTexture;
// 0x011f9518
extern ::NiTexture *DAT_011f9518;
// 0x011f951c
extern ::NiPointer< ::B57FF0RefObject> DAT_011f951c;
// 0x011f9520
extern ::NiPointer< ::B57FF0RefObject> DAT_011f9520;
// 0x011f9524
extern ::NiPointer< ::B57FF0RefObject> DAT_011f9524;
// 0x011f9528
extern ::NiPointer< ::B57FF0RefObject> DAT_011f9528;
// 0x011f952c
extern ::NiPointer< ::B57FF0RefObject> DAT_011f952c;
// 0x011f9530
extern int DAT_011f9530;
// 0x011f9534
extern unsigned int DAT_011f9534;
// 0x011f9538
extern int DAT_011f9538;
// 0x011f953c
extern ::NiPointer< ::B57FF0RefObject> DAT_011f953c;
// 0x011f9540
extern ::NiPointer< ::B57FF0RefObject> DAT_011f9540;
// 0x011f9544
extern unsigned int DAT_011f9544;
// 0x011f9548
extern ::ShaderEntryBase *DAT_011f9548;
// 0x011f95d4
extern char DAT_011f95d4;
// 0x011f95d8
namespace fnv_00b54630 { namespace CleanupState { extern ::fnv_00b54630::NP DAT_011f95d8; } }
// 0x011f95e4
extern int DAT_011f95e4;
// 0x011f95e8
extern int DAT_011f95e8;
// 0x011f95ec
extern "C" extern ::NiTexture *DAT_011f95ec;
// 0x011f95f0
extern ::NiPointer< ::NiRefObject> g_spCurrentAccumulator;
// 0x011f9604
extern ::NLPlane DAT_011f9604;
// 0x011f9614
namespace fnv_004ec800 { extern ::NiPoint2 DAT_011f9614; }
// 0x011f9618
extern float DAT_011f9618;
// 0x011f962c
extern ::NiPoint2 DAT_011f962c;
// 0x011f9634
extern ::NiPoint2 DAT_011f9634;
// 0x011f9640
extern int DAT_011f9640;
// 0x011f9644
extern ::B58070AVObject *g_pkB58070Root;
// 0x011f9648
extern ::GlobalObjectO2_00a7b610 g_011f9648;
// 0x011f9684
extern ::Camera *DAT_011f9684;
// 0x011f96a0
extern ::SetColl_011f96a0_0044f570 *g_coll_011f96a0;
// 0x011f9e80
extern ::GlobalObjectO2_00a7b610 g_011f9e80;
// 0x011f9ea0
namespace fnv_00b5ddf0 { extern "C" extern ::fnv_00b5ddf0::LocalLock DAT_011f9ea0; }
// 0x011f9ec0
namespace fnv_00b5ddf0 { extern "C" extern ::fnv_00b5ddf0::LocalLock DAT_011f9ec0; }
// 0x011f9ef0
extern bool DAT_011f9ef0;
// 0x011f9ef4
extern unsigned int DAT_011f9ef4;
// 0x011f9ef8
extern unsigned int DAT_011f9ef8;
// 0x011f9f00
extern ::GlobalObjectO2_00a7b610 g_011f9f00;
// 0x011f9f40
extern void (*DAT_011f9f40[16])();
// 0x011f9f80
extern void (*DAT_011f9f80[16])();
// 0x011f9fc0
extern char DAT_011f9fc0;
// 0x011f9fc1
extern bool DAT_011f9fc1;
// 0x011f9fc2
extern bool DAT_011f9fc2;
