// fallout_shared/tesland_od_variant_ctx_variant.cpp: GeometryOwner (2 functions)

#include <string.h>
// tesland_od_variant_ctx_variant.cpp: context variant of src/fallout_shared/tesland_od_variant.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/fallout_shared/tesland_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesland.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include <cstring>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainChunk.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderPPLightingProperty.h"
#include "fnv/decl/Bound88.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439680_class.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004410d0_Class.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_0045cb90_cls.h"
#include "fnv/decl/FUN_00485b60.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a8030_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0050a550_shell.h"
#include "fnv/decl/FUN_00510130_shell.h"
#include "fnv/decl/FUN_00528790_shell.h"
#include "fnv/decl/FUN_00537b50_shell.h"
#include "fnv/decl/FUN_00539f20_Class.h"
#include "fnv/decl/FUN_00540750_Class.h"
#include "fnv/decl/FUN_005407b0_Class.h"
#include "fnv/decl/FUN_00544590_cls.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_00621e60.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_006fce30_shell.h"
#include "fnv/decl/FUN_006fce70_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a673d0_shell.h"
#include "fnv/decl/FUN_00a67660_cls.h"
#include "fnv/decl/FUN_00b600e0_cls.h"
#include "fnv/decl/FUN_00baa000_shell.h"
#include "fnv/decl/GuardedSubHolder.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder00592cc0.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/LandOwner535d.h"
#include "fnv/decl/LandscapeSpecularView.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Mgr_e74120.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/Owner_b9713.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/RenderOwner.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/S_00538f40.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/ShaderOwner.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TexSet_b68660.h"
#include "fnv/decl/This_004a8050.h"
#include "fnv/decl/_FUN_0052aa80_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_00534010__FUN_00534010.h"
#include "fnv/decl/fnv_00535b30__FUN_00535b30_class.h"
#include "fnv/decl/fnv_00538fb0__FUN_00538fb0.h"
#include "fnv/decl/fnv_0053a550__DoorH.h"
#include "fnv/decl/fnv_0053fa40__HostMesh53.h"
#include "fnv/decl/fnv_00540570__FUN_00540570_Owner.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00a66a60__GeometryDataA66A.h"
#include "fnv/decl/fnv_00a73080__S.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/xMgr_2.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_00534000.h"
#include "fnv/symbols_00535000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00538000.h"
#include "fnv/symbols_00539000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7e000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b54000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0102d000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c8000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "tesland_decls.h"
#pragma optimize("",off)
struct FUN_00533260_holder {
    void FUN_00533260();
};
struct FUN_00533210_class {
    void* FUN_00533210(unsigned int flags);
};
struct CellH {
};
struct FUN_00533fd0_Class {
    int FUN_00533fd0();
};
struct FUN_00534050_Class {
    float FUN_00534050();
};
struct FUN_00534080_Class {
    double FUN_00534080();
};
struct TESWorldSpace;
struct DoorH {  };
struct FUN_005340b0_Class {
    int m_auiShapeKeys[8];
    DoorH* m_pDoor;
    TESWorldSpace* FUN_005340b0();
};
struct FUN_00534140_Class {
    bool FUN_00534140();
};
struct FUN_00534160_Class {
    void FUN_00534160(bool set);
};
struct FUN_005341a0_Class {
    void FUN_005341a0(bool set);
};
struct FUN_005341e0_Class {
    bool FUN_005341e0();
};
struct FUN_00534200_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00534200(bool value);
};
struct NiPoint3 { float x; float y; float z; public:
    ::NiPoint3 Cross(const ::NiPoint3 &) const;
public:
    static const ::NiPoint3 ZERO;
};
class TESFile;
struct TESForm {  public:
    void ClearData();
public:
    ::TESFile *GetFile(int);
};
struct FUN_00534570_shell { char* m_pkDeltas; unsigned int stride; void FUN_00534570(unsigned int index, NiPoint3& vertex); };
template<int> struct EndianSizeTag {};
struct FUN_00535a60_Class {
    void FUN_00535a60();
};
struct FUN_00537100_Class {
    void FUN_00537130();
    void* FUN_00537100(unsigned int flags);
};
struct FUN_00537ca0_class
{
    const char* const* FUN_00537ca0();
};
struct FUN_00a73080_holder {  };
void __cdecl operator delete(void* p, unsigned int size);
class ShadowSceneNode;
struct NiAdditionalGeometryData {
    void* FUN_00537cb0(unsigned int flags);
public:
    static ::ShadowSceneNode *GetShadowSceneNodeForIndex(int);
};
struct FUN_00540800_Class {
    void FUN_00540800();
    void FUN_00537ce0();
};
struct FUN_00537d00_Class {
    void* FUN_00537d00();
};
struct FUN_00537d10_Class {
    void FUN_00537d40();
    void* FUN_00537d10(unsigned int flags);
    static void operator delete(void* p, unsigned int size);
};
struct QuantityData {  };
struct TESRaceForm {  };
struct TESObjectREFR {  };
struct MagicCaster {  };
struct TESConditionItem {  };
struct TESQuest;
struct BGSQuestObjective {  };
struct FUN_00537e30_cls { char _pad[24]; int _m18; int _m1c; FUN_00537e30_cls* FUN_00537e30(); };
struct FUN_00537e90 {
    unsigned int quantity;
    void SetQuantity(unsigned int value);
};
struct FUN_00538e30_class {
};
extern int DAT_0102e378;
struct FUN_00538e10_class {
    int* m_vtbl;
    void FUN_00538e10();
};
struct B1 { virtual ~B1(); void* FUN_00538e80(unsigned int); };
extern "C" void __cdecl FUN_00538f20();
extern int DAT_0102e378;
struct FUN_00538ef0_class {
    void* m_ppVirtualMethodTable;
    int m_kPointA;
    int m_kPointB;
    void FUN_00538f20();
    void* FUN_00538ef0();
};
struct FUN_00538f20 {
    int* p;
    FUN_00538f20();
};
struct FUN_00538f80 {
    void* DeleteThis(unsigned int flags);
};
struct FUN_00539460_Class {
    char m_00[0x1c];
    int m_1c;
    bool FUN_00539460();
};
struct FUN_005394c0_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_005394c0(bool value);
};
struct GlobalObjectO2_00a7b610;
struct FUN_00539fc0_Class
{
    GlobalObjectO2_00a7b610* FUN_00539fc0();
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_0053a000 {
};
struct FUN_00539fd0 : public FUN_0053a000 {
    void* ScalarDeletingDestructor(unsigned int flags);
};
struct FUN_0053a070_Class {
    void FUN_0053a070(int a, int b);
};
struct B006815c0 { B006815c0(); };
struct FUN_0053a510 {
    B006815c0 m0;
    char _p1[7];
    B006815c0 m1;
    char _p2[19];
    B006815c0 m2;
    char _p3[19];
    B006815c0 m3;
    FUN_0053a510();
};
struct FUN_0053a760_Class {
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
    int m_30[6];
    void FUN_0053a760(unsigned char a, unsigned short b, int c);
};
struct FUN_0053ae30_class {
    float FUN_0053ae30(unsigned char type, unsigned short id);
};
struct GlobalObject_0044f440 {
};
float FUN_0053ca40();
struct FUN_0053ca60 {
    FUN_0053ca60* Init();
};
struct Buf50
{
    int m00; int m04; int m08; int m0C; int m10; int m14; int m18; int m1C;
    int m20; int m24; int m28; int m2C; int m30; int m34; int m38; int m3C;
    int m40; int m44; int m48; int m4C;
    void FUN_0053a510();
};
struct Owner
{
    bool FUN_0053d2e0(int, int, int);
};
struct FUN_0053df00_Class {
    int FUN_0053df00();
};
struct Tmp53e210 {
    int m00;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    void FUN_0053a510();
};
struct Host53e210 {
    bool FUN_0053e210(int a);
};
struct FUN_0053e260_Class {
    void* m_p; // +0x00
    void* m_q; // +0x04
    void* m_r; // +0x08
    void* m_s; // +0x0c
    void* m_t; // +0x10
    void* m_u; // +0x14
    void* m_v; // +0x18
    void* m_w; // +0x1c
    void* m_uiX; // +0x20
    void* m_uiY; // +0x24
    void* m_uiZ; // +0x28
    unsigned char FUN_0053e260(int index, int offset);
};
struct NiAVObject;
class NiAVObject;
struct NiNode {  public:
    ::NiAVObject *GetAt(unsigned int);
};
struct FUN_0053f120_Param { unsigned char _pad[0x18]; unsigned int idx; };
struct FUN_0053f120_Holder { unsigned char _pad[0x28]; NiNode*** fld28; NiAVObject* FUN_0053f120(FUN_0053f120_Param*); };
struct LandscapeColorData
{
    int m00,m04,m08,m0C,m10,m14,m18,m1C,m20,m24,m28,m2C,m30,m34,m38,m3C,m40,m44,m48,m4C;
    void FUN_0053a510();
};
struct TESObjectLAND
{
    bool FUN_0053f180(const LandscapeColorData&, float&);
};
struct QueuedFile;
struct BGSTextureSet {
};
struct FUN_00541540_Class {
    void FUN_00541540(int a, QueuedFile* b);
};
struct FUN_00541590_Class {
    char FUN_00541590();
};
struct S_00592cf0 { void* FUN_00592cf0(); };
struct Param5380d0 {
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
	virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual bool v40();
};
struct This5380d0 {
	bool FUN_005380d0(Param5380d0* p);
};
struct BSAudio {  };
struct Topic
{
    virtual void f0() {}
    virtual void f1() {}
    virtual void Method(void* a, unsigned int b) {}
};
struct Prm
{
    char pad[4];
    unsigned short val;
};
struct FUN_0053a5a0_Inner
{
    char pad[32];
    void* arr[4];
};
struct FUN_0053a5a0_Outer
{
    char pad[40];
    FUN_0053a5a0_Inner* ptr;
    void* FUN_0053a5a0(unsigned char index);
};
struct FUN_0053a700_Mid {
    unsigned char pad[0x30];
    int* arr[4];
};
struct FUN_0053a700_Holder {
    unsigned char pad[0x28];
    FUN_0053a700_Mid* p;
    int FUN_0053a700(unsigned char, unsigned short);
};
struct FUN_0053a630_Class : public FUN_0053ae30_class {
    int FUN_0053a630(unsigned char type, unsigned short id);
};
struct A51BF0Base {
    static void* operator new(unsigned int); static void operator delete(void*, unsigned int);
};
struct FUN_00537d60 : A51BF0Base {
    char _pad[0x18];
    int _m18;
    int _m1c;
    FUN_00537e30_cls* FUN_00537e30();
    FUN_00537d60();
};
struct FUN_005330d8_class
{
};
struct FUN_005331f0_class
{
    void FUN_005331f0();
};
extern int DAT_0102dcd4;
extern int DAT_0102dccc;
struct FUN_00483370 {
    void* m_vt;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00483370();
    ~FUN_00483370();
};
struct FUN_00533240_cls {
    void* m_vt;
    FUN_00533240_cls();
};
struct FUN_00528cb0_cls {
    int m_00;
    FUN_00528cb0_cls(int value);
    ~FUN_00528cb0_cls();
};
struct FUN_00533120_cls : FUN_00483370 {
    FUN_00533240_cls m_18;
    int m_1c;
    int m_20;
    FUN_00528cb0_cls m_24;
    int m_28;

    FUN_00533120_cls();
};
struct AutoMemContext {
    int ctx;
    AutoMemContext(int memContext, bool push, const char* file, int line);
    ~AutoMemContext();
};
struct TESFile;
struct LandData {
    int unk00;
};
struct LandForm : TESPackage {
    int unk20;
    int unk24;
    LandData* unk28;

    bool FUN_00535b90(bool bFlag);
};
struct FUN_0045cec0 {
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
    ~FUN_0045cec0();
};
struct FUN_005409b0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~FUN_005409b0();
};
struct FUN_00537130 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_0045cec0 m_14;
    FUN_005409b0 m_54[4];
    FUN_0045cec0 m_94;

    ~FUN_00537130();
};
class D40NiObject {
public:
    virtual ~D40NiObject();

    int m_uiRefCount;
};
class FUN_00537d40 : public D40NiObject {
public:
    virtual ~FUN_00537d40();
};
int __cdecl FUN_00ec7d40(int v);
void __cdecl CompressSaveLoadRecord();
struct FUN_0084e3a0_Class { int FUN_0084e3a0(); };
struct FUN_00535aa0_Class { void FUN_00535aa0(); };
struct FUN_004855a0_shell {  };
struct FUN_00485680_shell {  };
extern double DAT_0102dfe0;
struct Elem16 { float x; float y; float z; float w; };
struct FUN_004a0c10_Class { float x; float y; float z;  };
struct Data538110 {
    void* m_00;
    NiPoint3** m_04;
    NiPoint3** m_08;
    Elem16** m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20arr[4];
    int* m_30arr[4];
    int m_40arr[4];
};
struct BigBuf538110 {
    float m_00;
    char m_04[1092];
};
struct X538110 {
    int m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned short m_06;
};
struct Entry538110 {
    unsigned short m_00;
    unsigned short m_02;
    float m_04;
};
struct FUN_0053db20_Class {  };
struct FUN_0053a940_Class {  };
struct This538110 {
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
    Data538110* m_28;
    void FUN_00538110();
};
struct Base8ef0 { virtual void v0(); int a; int b; int c; Base8ef0(); ~Base8ef0(); };
struct MA { int x[4]; MA();  };
struct MB { int x[3]; MB(); ~MB(); };
struct MC { int x[4]; MC();  };
struct FUN_00538d70_cls : Base8ef0 {
    MA a; MB b; MC c;
    FUN_00538d70_cls();
    virtual void v0();
};
struct S_00539280_Arg {
    void* unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
};
struct S_00539280_Obj {
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0a();
    virtual void vfn0b();
    virtual void vfn0c();
    virtual void vfn0d();
    virtual void vfn0e();
    virtual void vfn0f();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1a();
    virtual void vfn1b();
    virtual void vfn1c();
    virtual void vfn1d();
    virtual void vfn1e();
    virtual void vfn1f();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn2a();
    virtual void vfn2b();
    virtual void vfn2c();
    virtual void vfn2d();
    virtual void vfn2e();
    virtual void vfn2f();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn3a();
    virtual void vfn3b();
    virtual void vfn3c();
    virtual void vfn3d();
    virtual void vfn3e();
    virtual void vfn3f();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual bool vfn44(S_00539280_Arg* a, bool b, bool c);
};
struct S_00539280_Owner {
    bool FUN_00539280(S_00539280_Arg* a, bool b, bool c);
};
struct Mem960 {int value;Mem960(int,bool,const char*,int);~Mem960();};
struct Color960 {float r,g,b,a;Color960(float,float,float,float);};
struct Texture960 {};
struct Property960 {virtual void v000();virtual void v004();virtual void v008();virtual void v00c();virtual void v010();virtual void v014();virtual void v018();virtual void v01c();virtual void v020();virtual void v024();virtual void v028();virtual void v02c();virtual void v030();virtual void v034();virtual void v038();virtual void v03c();virtual void v040();virtual void v044();virtual void v048();virtual void v04c();virtual void v050();virtual void v054();virtual void v058();virtual void v05c();virtual void v060();virtual void v064();virtual void v068();virtual void v06c();virtual void v070();virtual void v074();virtual void v078();virtual void v07c();virtual void v080();virtual void v084();virtual void v088();virtual void v08c();virtual void v090();virtual void v094();virtual void v098();virtual void v09c();virtual void v0a0();virtual void v0a4();virtual void v0a8();virtual void v0ac();virtual void v0b0();virtual void v0b4();virtual void v0b8();virtual void v0bc();virtual void v0c0();virtual void v0c4();virtual void v0c8();virtual void v0cc();virtual void v0d0();virtual void* vd4(void*);unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;unsigned unk02c;unsigned unk030;unsigned unk034;unsigned unk038;unsigned unk03c;unsigned unk040;unsigned unk044;unsigned unk048;unsigned unk04c;unsigned unk050;unsigned unk054;unsigned unk058;unsigned unk05c;unsigned unk060;unsigned unk064;unsigned unk068;unsigned unk06c;unsigned unk070;unsigned unk074;unsigned unk078;unsigned unk07c;unsigned unk080;unsigned unk084;unsigned unk088;unsigned unk08c;unsigned unk090;unsigned unk094;unsigned unk098;unsigned unk09c;unsigned unk0a0;unsigned unk0a4;unsigned unk0a8;unsigned unk0ac;unsigned unk0b0;unsigned unk0b4;unsigned unk0b8;unsigned unk0bc;unsigned unk0c0;unsigned unk0c4;unsigned unk0c8;unsigned unk0cc;unsigned unk0d0;unsigned unk0d4;unsigned unk0d8;unsigned unk0dc;unsigned unk0e0;unsigned unk0e4;unsigned unk0e8;unsigned unk0ec;unsigned unk0f0;unsigned unk0f4;unsigned unk0f8;unsigned unk0fc;unsigned unk100;Property960();static void* operator new(unsigned); static void operator delete(void*, unsigned int);};
struct Binary960 {unsigned unk00,unk04,unk08,unk0c,unk10;Binary960(unsigned,unsigned char*);static void* operator new(unsigned); static void operator delete(void*, unsigned int);};
struct Geometry960 {};
struct Node960 {};
struct Data960 {Node960** nodes;unsigned unk04,unk08;Color960** colors;unsigned unk10,unk14,unk18,unk1c;Texture960* base[4];Texture960** layers[4];unsigned char** binary[4];};
struct Host960 {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,flags,unk20,unk24;Data960* data;bool FUN_00539960();};
class B53A000ExtraData {
public:
    virtual ~B53A000ExtraData();

    int m_iRefCount;
    const char* m_kName;
};
class FUN_0053a000_cls : public B53A000ExtraData {
public:
    virtual ~FUN_0053a000_cls();

    void* m_pResource;
};
struct LocalObj53a5e0 {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    unsigned char m18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    unsigned short m3c;
    unsigned short unk3e;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    void FUN_0053a510();
};
struct FUN_0053a5e0_cls {
    int FUN_0053a5e0(int arg);
};
struct FUN_0053a7a0_Tbl {
    char pad[0x40];
    float** arr[4];
};
struct FUN_0053a7a0_cls {
    char pad[0x28];
    FUN_0053a7a0_Tbl* m_28;
    float FUN_0053a7a0(unsigned char a, unsigned short b);
};
struct FUN_0053a830_Row {
    float* cells[0x121];
};
struct FUN_0053a830_Mid {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    float** tables[4];
};
struct FUN_0053a830_cls {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    FUN_0053a830_Mid* m_28;
    float FUN_0053a830(unsigned char type, unsigned short id, unsigned short idx);
};
struct C53A8A0Data {
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
    float** m_appfTables[4];
};
class C53A8A0Owner {
public:
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
    C53A8A0Data* m_pUserData;

    void FUN_0053a8a0(unsigned char ucTable, unsigned short usRow, unsigned short usColumn, float fValue);
};
struct WeightTables53ace0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int current[4];
    int* choices[4];
    float** weights[4];
};
struct Owner53ace0 : public FUN_0053ae30_class {
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
    WeightTables53ace0* tables;
    void FUN_0053ace0(unsigned char type, unsigned short id);
};
struct FNv53b450_Point {
    float x;
    float y;
    float z;
    void FUN_006815c0();
};
struct FNv53b450_Source {
    FNv53b450_Point* FUN_0053b450(FNv53b450_Point* output, unsigned char flags, unsigned short cellIndex, const int* x, const int* y);
};
class B3CA80Map {
public:

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct B3CA80Data {
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
    B3CA80Map m_akMaps[4];
};
class B3CA80Owner {
public:
    unsigned int FUN_0053ca80(int iQuad, int iIndex);

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
    B3CA80Data* m_pUserData;
};
struct TESWorldSpace;
struct TESObjectCELL;
struct Obj53 {
};
struct Cell53 {
};
struct FUN_00461c20_Holder {
};
struct This53 {
    void FUN_0053d330(Obj53** out, bool flag, unsigned char* outFlags);
};
class B3DA60Point3 {
public:
    B3DA60Point3(float fX, float fY, float fZ);


    float x;
    float y;
    float z;
};
struct B3DA60Rect {
    int m_iLeft;
    int m_iBottom;
    int m_iRight;
    int m_iTop;
};
class B3DA60Object {
public:
    bool FUN_0053da60(B3DA60Rect* pkRect, void* pvMatrix);
};
struct FUN_0053f390_v2 {
    float x;
    float y;
};
struct FUN_0053f390_v3 {
    float x;
    float y;
    float z;
    void FUN_006815c0();
};
struct FUN_0053f390_cls {
    FUN_0053f390_v2* FUN_0053f390(FUN_0053f390_v2* out, int n);
};
class NiPoint2 { public: float x,y; NiPoint2(float,float); };
struct UVBounds { float x,y,z,w; };
struct TextureSample {    };
struct TexturePointer {  };
struct TextureManager {    };
struct WorldManager {  };
struct TESView {  };
struct ShaderProperty {
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
 virtual void vd4();
 virtual void vd8();
 virtual void vdc();
 virtual void ve0();
 virtual void ve4();
 virtual void ve8();
 virtual void vec();
 virtual void vf0();
 virtual void vf4();
 virtual void vf8();
 virtual void setFirst(int,void*);
 virtual void setSecond(int,void*);
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
 UVBounds bounds;
   
};
struct QuadNode {   };
struct TESFileRecordLoader {
 QuadNode** nodes;
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
 int x,y;
};
struct Surface {
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
 TESFileRecordLoader* data;
 void FUN_005400e0();
};
struct FUN_00538ef0 {
    virtual void VirtualMethod();
    ~FUN_00538ef0();
    int m_kPointA;
    int m_kPointB;
    FUN_00538ef0();
};
struct FUN_0056d640 : FUN_00538ef0 {
    B006815c0 m_quantity;
    FUN_0056d640(unsigned int quantity);
};
struct LandFormBase {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    virtual ~LandFormBase();
};
struct LandChildCell {
    virtual void* GetPersistentCell() = 0;
};
struct LandMember24 {
    int unk00;
    ~LandMember24();
};
struct LandSharedObject {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ~LandSharedObject();
};
struct LandNiPointer {
    LandNiPointer& operator=(void* p);
};
struct LandBuffer {
    int unk00;
};
struct FUN_00533260 : LandFormBase, LandChildCell {
    int unk1C;
    int unk20;
    LandMember24 unk24;
    virtual void* GetPersistentCell();
    virtual ~FUN_00533260();
};
struct LandPoint3 {
    float x;
    float y;
    float z;
    LandPoint3(float fx, float fy, float afDepth);
};
struct LandGeomData {
};
struct LandNode {
};
struct LandLoadedData {
    LandNode** m_ppLandNodes;
    LandPoint3** m_ppLandPoints;
    int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    float m_fTrailingValue;
};
struct LandObject : TESObjectLAND {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24;
    LandLoadedData* m_pRenderData;
    void FUN_00534240(int quadrant, int index, LandPoint3* vertex);
};
struct VertPt {
    float x; float y; float z;
    VertPt(float fx, float fy, float afDepth);
};
struct VertCtl {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual bool IsSkinned();
};
struct VertLock : FUN_00534570_shell {
    int unk08;
    VertLock();
};
struct VertGeomData {
};
struct VertGeom {
};
struct VertNode {
};
struct VertTables {
    VertNode** nodes;
    int unk04;
    VertPt** points;
};
struct VertOwner {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int unk14; int unk18; int unk1c; int unk20; int unk24;
    VertTables* tables;
    void FUN_00534390(unsigned int index, unsigned int vert, VertPt& out);
};
struct Color_5345c0 { float r, g, b, a; };
struct Buffer_5345c0 {
    void* data;
    unsigned int stride;
    unsigned int unk08;
};
struct Format_5345c0 {
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
    virtual bool HasColor();
};
struct Data_5345c0 {
};
struct Geometry_5345c0 {
};
struct Node_5345c0 {  };
struct Store_5345c0 {
    Node_5345c0** nodes;
    int unk04;
    int unk08;
    Color_5345c0** colors;
};
struct FUN_005345c0_shell {
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
    Store_5345c0* store;
    void FUN_005345c0(unsigned int group, unsigned int index, Color_5345c0& out);
};
struct RgbaColor {
    float r;
    float g;
    float b;
    float a;
};
struct FUN_00534780_Class {
    int m_00;
    int m_04;
    unsigned char m_08;
    void FUN_00534780(int index, RgbaColor* out);
};
extern int FNV_RTTI_TESObjectLAND;
extern "C" void* __cdecl FNV_DynamicCast(void*, int, const void*, const void*, int);
struct LandCopyData {
    void* nodes;
    NiPoint3** vertices;
    NiPoint3** normals;
    Elem16** colors;
    unsigned char** textureIndices;
    int unk14;
    int cellX;
    int cellY;
    int baseTextures[4];
    int* textureLayers[4];
    void** weights[4];
};
struct LandCopy : TESPackage {
    void* cell;
    int unk24;
    LandCopyData* data;
    void FUN_005348c0(TESForm* form);
};
struct CleanupMap {
    int unk00, unk04, unk08, unk0c;
};
struct RefCleanup {  };
struct CleanupData {
    int unk00;
    int** vertices;
    int** normals;
    int** colors;
    int** extra;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int* choices[4];
    int** weights[4];
    RefCleanup* reference;
    CleanupMap maps[4];
    ~CleanupData();
};
struct CleanupOwner {
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
    CleanupData* data;
    bool FUN_00536d80();
};
void* __cdecl operator new(unsigned int);
struct Point { float x,y,z; Point(float,float,float); };
struct Range {float x,y;};
struct UpdateData {float time; bool a,b; int c; UpdateData(float,bool,bool);};
struct Shape;
struct GeomData { void FUN_00a67050(int);  };
struct Bound {};
struct Property { };
struct Model {};
struct Scene {
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
virtual void SetPosition(const NiPoint3&);
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void vec();
virtual void vf0();
virtual void vf4();
virtual void Attach(int,Shape*);
  
 
 
};
struct Shape {    };
struct PropPointer {};
struct Renderer {virtual void v00();
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
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void Render(Shape*,int,int,void*);
};
struct Cell {};
struct Mopp { };
struct Scratch {int a,b,c,d; Scratch();};
struct Other { };
struct Data {Scene** nodes; int unk04;
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
int unk9c; float scale;};
struct Land {int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c; Cell* cell; int unk24; Data* data;
 
  
 void FUN_0053aeb0(); 
  void FUN_005374f0();};
struct SceneObject {
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void Unknown55();
    virtual void Unknown56();
    virtual void Unknown57();
    virtual void InsertChild(SceneObject* child);
    virtual void Unknown59();
    virtual void SetState(int state);
};
struct ScenePointer {
    SceneObject* value;
    void FUN_0066b0d0(SceneObject* value);
};
struct QueuePointer {
    void* value;
};
struct SceneController {
};
struct SceneSource {
};
struct BoneTransformData {
    SceneObject** objects;
    int* states;
    void** buffers;
    int* counts;
    int unknown10;
    ScenePointer node;
    int unknown18;
    int unknown1c;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2c;
    int unknown30;
    int unknown34;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;
    int unknown48;
    int unknown4c;
    int unknown50;
    int unknown54;
    int unknown58;
    int unknown5c;
    int unknown60;
    int unknown64;
    int unknown68;
    int unknown6c;
    int unknown70;
    int unknown74;
    int unknown78;
    int unknown7c;
    int unknown80;
    int unknown84;
    int unknown88;
    int unknown8c;
    int unknown90;
    ScenePointer extraNode;
};
struct SceneCleanup {
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    SceneSource* source;
    QueuePointer queued;
    BoneTransformData* data;
    void FUN_00537eb0();
};
struct ShadowSceneNode {
};
void* __cdecl FUN_0056d280(unsigned int size);
struct Buffer538c00

{

    unsigned int m00;

    unsigned int m04;



};
struct Output538c00

{

    virtual ~Output538c00();

    unsigned int m04;

    unsigned int m08;

    unsigned int m0c;

    unsigned int m10;

    unsigned int m14;

    unsigned int m18;

    unsigned int m1c;

    Buffer538c00 buffer;

    unsigned int m28;

    unsigned int m2c;

    Output538c00();
    static void* operator new(unsigned int bytes) { return FUN_0056d280(bytes); } static void operator delete(void*);

};
struct FUN_00538c00_Class

{

    char FUN_00538c00(const void* source, unsigned int size, Output538c00** result);

};
struct Mesh53;
struct Buffer53 {  };
struct Texture53Data {  };
struct Texture53 {   };
struct GeoData53 {    };
struct NiTimeController {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
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
 virtual void slot37();
 virtual void slot38();
 virtual void SetGeometry(Mesh53*);
};
struct Mesh53 {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual Mesh53* AsMesh();
};
struct Update53 { float time; bool update; bool flags; int unk08;  };
struct Node53 {    };
struct Config53 {
 int enabled; int unk04; void** sources; int unk0c; int unk10; int unk14; int unk18; int unk1c;
 Texture53* primary[4]; Texture53** textures[4];
};
struct TES53 {  };
struct Worker53 {
 int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
 Config53* config;
   
 void FUN_0053a090(bool update, int unused);
};
struct LayerOwner53a940 : Owner53ace0 {
    void FUN_0053a940();
};
struct ShiftTableData {
    int unk00[12];
    int* m_apiEntries[4];          // +0x30, each int[6]
    float** m_appfRows[4];         // +0x40, each float*[0x121] of float[6]
};
class ShiftTableOwner {
public:
    int unk00[10];
    ShiftTableData* m_pUserData;      // +0x28

    void FUN_0053abb0(unsigned char ucSlot, unsigned short usIndex);
};
struct xPoint3 {
    float x, y, z;
    xPoint3();
    xPoint3(float qpqRa, float qsSDDgz, float fZ);
    xPoint3 operator+(const xPoint3& kOther) const;
};
struct xPoint2 {
    float x, y;
    xPoint2(float qpqRa, float qsSDDgz);
    xPoint2 operator-(const xPoint2& kOther) const;
};
struct xCoordData {
    float fX;
    float fY;
    float fCellX;
    float fCellY;
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    int iCell;
    float fQuadX;
    float fQuadY;
    int iQuadX;
    int iQuadY;
    int iQuad;
    xPoint3 kPos;
    int iVertex;
    int aiVerts[3];
    bool bFlip;
    bool bUpper;
};
struct xLandData {
    int m_iWordAt00;
    int m_iWordAt04;
};
struct xLand {
    char _pad0[0x28];
    xLandData* m_pData;
    bool FUN_0053b550(xCoordData& kData, const xPoint3& kPos, bool bRecurse);
};
struct Grass;
struct GrassNode {   };
struct TextureGrass {  };
struct Grass {
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
 virtual void v094();
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
 virtual void v0f4();
 virtual void v0f8();
 virtual void v0fc();
 virtual void v100();
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
 virtual unsigned char v180();
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
 virtual float v1b0();
 virtual void v1b4();
 virtual float v1b8();
 virtual void v1bc();
 virtual float v1c0();
 virtual void v1c4();
 virtual float v1c8();
 virtual void v1cc();
 virtual unsigned char v1d0();
 virtual void v1d4();
 virtual unsigned char v1d8();
 virtual void v1dc();
 virtual unsigned char v1e0();
  
};
struct Sample {
 const char* model; unsigned int id; float f08,f0c,f10,f14,f18;
 unsigned char b1c,b1d,b1e,b1f;
 float weights[9];
 Sample();
};
struct SampleMap { int u00,u04,u08,u0c;  };
struct TerrainData {
 int u00,u04,u08,u0c,u10,u14,u18,u1c;
 TextureGrass* base[4]; TextureGrass** layers[4]; float** weights[4];
 int u50; SampleMap maps[4];
};
struct SampleSetting {  };
struct IntSetting {  };
extern unsigned long DAT_011c9f6c;
class NiPoint3;
struct TerrainInput;
struct TerrainOwner {
 int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24; TerrainData* data;
 bool FUN_0053bc10();
public:
    bool ComputeTerrainNormalAndTangent(::TerrainInput *, ::NiPoint3 *, ::NiPoint3 *);
};
struct Pt53d8f0 {
    float x;
    float y;
    float z;
    Pt53d8f0();
};
struct Edges53d8f0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct LandData53d8f0 {
    int unk00;
    Pt53d8f0** normals;
    Pt53d8f0** vertices;
};
struct Land53d8f0 {
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
    LandData53d8f0* data;

    void FUN_0053d8f0(Edges53d8f0* edges, void* other);
};
struct NormalPoint {
 float x,y,z;
 NormalPoint operator-(const NormalPoint&) const;
 NormalPoint& operator+=(const NormalPoint&);
};
struct NormalData {
 int unk00;
 NormalPoint** vertices;
 NormalPoint** normals;
 int unk0c;
 unsigned char** flags;
};
struct NormalLand : TESPackage {
 int unk20;
 int unk24;
 NormalData* data;
 void FUN_0053df30(void* region);
};
struct LandVertex {
    float x;
    float y;
    float z;
    LandVertex();
};
struct LandCoord {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int cellIndex;
    float fracX;
    float fracY;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int vertex0;
    int vertex1;
    int vertex2;
    bool upperTriangle;
    bool swapAxes;
};
struct LandHeights {
    float z0;
    float z1;
    float z2;
};
struct LandStandIn {
    bool FUN_0053f1e0(LandCoord& coord, float& height);
};
struct LandData53f
{
    char pad00[0x18];
    NiPoint2 kHeight;
};
struct FUN_0053f440_shell
{
    char pad00[0x1c];
    unsigned int uiFlags;
    char pad20[8];
    LandData53f* pkData;

    NiPoint2 FUN_0053f440();
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
namespace TESLandInit {

struct LandMemContext {
    int iOldContext;
    LandMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~LandMemContext();
};

struct LandMemObject {
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
};

struct LandTexturePtr {
    void* pObject;
    LandTexturePtr(void* apObject);
    ~LandTexturePtr();
};

struct LandShaderSlot {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b(); virtual void v1c(); virtual void v1d();
    virtual void v1e(); virtual void v1f(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void FUN_vt90(int aiIndex, LandTexturePtr* apOut);
};

struct LandTexturing : LandMemObject {
    LandTexturing();
    char pad00[0x30];
    LandShaderSlot kShader;
    char pad34[0x6c];
};

struct LandShaderData {
    LandShaderData();
    char data[0x28];
};

struct LandTextureData {
    LandTextureData(void* apTexture, int a2, int a3, int a4, int a5);
    char data[0x10];
};

struct LandProperty : LandMemObject {
    LandProperty();
    char data[0x30];
};

struct LandPropertyList {
};

struct LandPropertyHolder {
    void FUN_0066b0d0(LandProperty* apProperty);
};

struct LandShaderList {
};

struct LandShaderManager {
};

struct LandStringSetting {
};

struct LandFloatSetting {
};

struct LandColor {
    float r, g, b, a;
    LandColor();
    LandColor(float afR, float afG, float afB, float afA);
};

struct LandPoint3 {
    float x, y, z;
    LandPoint3();
    LandPoint3(float afX, float afY, float afZ);
};

struct LandPoint2 {
    float x, y;
    LandPoint2();
    LandPoint2(float afX, float afY);
};



static const char s_szSourceFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp";
static const char s_szLandscapeFormat[] = "Landscape\\%s";
static const char s_szTilingWarning[] = "DEFAULT: INI setting fLandTextureTilingMult cannot be 0.";

// @fnv 0x00533420
void __cdecl FUN_00533420() {
    LandMemContext kMemContext(0x1b, true, s_szSourceFile, 0xc6);
    (*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1)) = new LandTexturing();
    char acPath[260];
    ::FUN_00406d00(acPath, 260, s_szLandscapeFormat, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::TESLandInit::LandStringSetting *>(&::g_011ca004))))->GetMenuTitle())));
    reinterpret_cast<::Holder00592cc0 *>(((*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))))->SetFullNameByType(0, acPath);
    ::FUN_00406d00(acPath, 260, s_szLandscapeFormat, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::TESLandInit::LandStringSetting *>(&::g_011c9f8c))))->GetMenuTitle())));
    reinterpret_cast<::Holder00592cc0 *>(((*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))))->SetFullNameByType(1, acPath);
    reinterpret_cast<::FUN_00510130_shell *>((((::TESLandInit::LandShaderList *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::TESLandInit::LandShaderManager * *>(&::g_dataHandler))))->FUN_00726070()))))->RemoveNode((::NiNode *)((*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))));
    (*reinterpret_cast<::TESLandInit::LandShaderData * *>(&::DAT_011c9f04)) = new LandShaderData();
    reinterpret_cast<::TESPackage *>(((*reinterpret_cast<::TESLandInit::LandShaderData * *>(&::DAT_011c9f04))))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)((*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))));
    LandTexturePtr kTexture(0);
    (*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))->kShader.FUN_vt90(0, &kTexture);
    LandTextureData* pTextureDataValue = new LandTextureData(((void *)(::FUN_00559450((int *)&(kTexture)))), 0, 3, 5, 0);
    (*reinterpret_cast<::TESLandInit::LandPropertyHolder *>(&::g_011ca000)).FUN_0066b0d0(new LandProperty());
    reinterpret_cast<::NiObjectNET *>((((::TESLandInit::LandPropertyList *)(::FUN_00559450((int *)&((*reinterpret_cast<::TESLandInit::LandPropertyHolder *>(&::g_011ca000))))))))->FUN_00533fb0(2);
    reinterpret_cast<::Owner_b9713 *>((((::TESLandInit::LandPropertyList *)(::FUN_00559450((int *)&((*reinterpret_cast<::TESLandInit::LandPropertyHolder *>(&::g_011ca000))))))))->FUN_00533f40((::ObjectBase *)(pTextureDataValue));

    (*reinterpret_cast<unsigned short * *>(&::g_landBuf0)) = new unsigned short[0x600];
    int iIndex = 0;
    int iVal;
    int jPtr;
    for (iVal = 0; iVal < 16; iVal++) {
        for (jPtr = 0; jPtr < 16; jPtr++) {
            if ((iVal % 2) ^ (jPtr % 2)) {
                unsigned short m_usVertexId;
                m_usVertexId = (iVal + 1) * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = (iVal + 1) * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = (iVal + 1) * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
            } else {
                unsigned short usCorner;
                usCorner = (iVal + 1) * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = (iVal + 1) * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = (iVal + 1) * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
            }
        }
    }

    float fTiling = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TESLandInit::LandFloatSetting *>(&::g_011c9f2c))))));
    if (fTiling == 0.0) {
        ::FUN_005b5e40();
        fTiling = 16.0f;
    }
    fTiling = 4.0 / fTiling;
    (*reinterpret_cast<::TESLandInit::LandColor * *>(&::g_landBuf1)) = new LandColor[0x121];
    (*reinterpret_cast<::TESLandInit::LandPoint3 * *>(&::g_landBuf2)) = new LandPoint3[0x121];
    (*reinterpret_cast<unsigned char * *>(&::g_landBuf4)) = new unsigned char[0x121];
    (*reinterpret_cast<::TESLandInit::LandPoint2 * *>(&::g_landBuf3)) = new LandPoint2[0x121];
    iIndex = 0;
    for (iVal = 0; iVal < 17; iVal++) {
        for (jPtr = 0; jPtr < 17; jPtr++) {
            (*reinterpret_cast<::TESLandInit::LandColor * *>(&::g_landBuf1))[iIndex] = LandColor(1.0f, 1.0f, 1.0f, 0.0f);
            (*reinterpret_cast<::TESLandInit::LandPoint3 * *>(&::g_landBuf2))[iIndex] = LandPoint3(0.0f, 0.0f, 1.0f);
            (*reinterpret_cast<unsigned char * *>(&::g_landBuf4))[iIndex] = 1;
            (*reinterpret_cast<::TESLandInit::LandPoint2 * *>(&::g_landBuf3))[iIndex] = LandPoint2(jPtr / fTiling, iVal / fTiling);
            iIndex++;
        }
    }
    int kLocal;
    for (kLocal = 0; kLocal < 4; kLocal++) {
        DAT_011c9ec4[kLocal] = (kLocal % 2) * 2048 - 2048;
        DAT_011c9eb4[kLocal] = (kLocal / 2) * 2048 - 2048;
    }
    for (kLocal = 0; kLocal < 4; kLocal++) {
        iIndex = 0;
        (*reinterpret_cast<TESLandInit::LandPoint3 * (*)[4]>(&::g_landBufArray))[kLocal] = new LandPoint3[0x121];
        for (iVal = 0; iVal < 17; iVal++) {
            for (jPtr = 0; jPtr < 17; jPtr++) {
                (*reinterpret_cast<TESLandInit::LandPoint3 * (*)[4]>(&::g_landBufArray))[kLocal][iIndex] = LandPoint3(jPtr * 128 + DAT_011c9ec4[kLocal], iVal * 128 + DAT_011c9eb4[kLocal], -2048.0f);
                iIndex++;
            }
        }
    }
    (*reinterpret_cast<unsigned char *>(&::g_landBuffersReady)) = 1;
}

}
struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(float afX, float afY, float afZ);
};
struct CoordProcessor { int x, y, z;  };
struct Grid53 { int count; CoordProcessor** processors; Vec3** positions; int unknown0c; unsigned char** evaluated; };
struct FNV53WorkerProxy {   };
struct WorkerTable53 { FNV53WorkerProxy* southwest; FNV53WorkerProxy* northwest; FNV53WorkerProxy* southeast; FNV53WorkerProxy* northCount; FNV53WorkerProxy* east; FNV53WorkerProxy* west; FNV53WorkerProxy* upper; FNV53WorkerProxy* northeast; };
struct Region53 { int m00,m04,m08,m0c,m10,m14,m18,m1c,m20,m24; Grid53* grid;   void FUN_0053e290(int,int,Vec3*,WorkerTable53*); };
struct NiP2 { float x, y; NiP2(); };
struct NiPoint3_ext { float x, y, z; NiPoint3_ext(); };
class NiFixedString {
public:
    const char* value;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct Geometry5371 {
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
    static void* operator new(unsigned int); static void operator delete(void*, unsigned int);
    Geometry5371(unsigned short, NiPoint3*, NiPoint3_ext*, void*, NiP2*, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short*, unsigned short*);
};
struct MeshData5371 {
    void* unk00;
    NiPoint3** vertices;
    NiPoint3_ext** normals;
    NiP2** texcoords;
};
struct Land5371 {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int unk14; int unk18; int unk1c; int unk20; int unk24;
    MeshData5371* data;
    Geometry5371* FUN_005371b0(unsigned char index);
};
extern unsigned short DAT_0118ae90[];
class NiPoint3LD {
public:
    NiPoint3LD();
    float x;
    float y;
    float z;
};
struct LandDataLD {
    unsigned int unk00;
    unsigned int unk04;
    NiPoint3LD** m_apkNormals;
};
class LandLD {
public:
    bool FUN_0053db20();
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
    LandDataLD* m_pUserData;
};

struct FUN_006815c0 {
    float x, y, z;
    FUN_006815c0();
};

struct FUN_004a7800 {
    float x, y, z, w;
    FUN_004a7800();
};

struct Resource {
};

struct FUN_005405a0 {
    void* unknown00;
    FUN_006815c0** positions;
    FUN_006815c0** normals;
    FUN_004a7800** transforms;
    unsigned char** tags;
    int unknown14;
    int unknown18;
    int unknown1c;
    void* resources[4];
    void* metadata[4];
    float** vertexRows[4];
    int unknown50, unknown54, unknown58, unknown5c;
    int unknown60, unknown64, unknown68, unknown6c;
    int unknown70, unknown74, unknown78, unknown7c;
    int unknown80, unknown84, unknown88, unknown8c;
    int unknown90, unknown94;
    void* initialValue98;
    void* initialValue9c;
    int unknownA0;
    FUN_005405a0();
};

struct GeometryOwner {
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14, unknown18, unknown1c;
    Resource* resource;
    int unknown24;
    FUN_005405a0* geometry;
    bool FUN_00539500(GeometryOwner* source);
};


// @fnv 0x00539500
bool GeometryOwner::FUN_00539500(GeometryOwner* source)
{
    if (geometry != 0 && geometry->positions != 0)
        return false;

    geometry = new FUN_005405a0;
    geometry->initialValue98 = ((void *)(reinterpret_cast<::TESObjectCELL *>((resource))->GetCellGridX()));
    geometry->initialValue9c = ((void *)(reinterpret_cast<::TESObjectCELL *>((resource))->GetCellGridY()));

    geometry->positions = new FUN_006815c0*[4];
    geometry->transforms = new FUN_004a7800*[4];
    geometry->normals = new FUN_006815c0*[4];
    geometry->tags = new unsigned char*[4];

    float height = reinterpret_cast<::fnv_0053a550::DoorH *>(this)->FUN_0053a550();
    for (int i = 0; i < 4; ++i) {
        geometry->positions[i] = new FUN_006815c0[0x121];
        geometry->transforms[i] = new FUN_004a7800[0x121];
        geometry->normals[i] = new FUN_006815c0[0x121];
        geometry->tags[i] = new unsigned char[0x121];
        geometry->vertexRows[i] = new float*[0x121];
        geometry->resources[i] = (void*)FUN_00535ae0();
        geometry->metadata[i] = new unsigned char[0x18];

        if (!source || !source->geometry) {
            memcpy(geometry->positions[i], (*reinterpret_cast<void * (*)[4]>(&::g_landBufArray))[i], 0xd8c);
            memcpy(geometry->transforms[i], (*reinterpret_cast<void * *>(&::g_landBuf1)), 0x1210);
            memcpy(geometry->normals[i], (*reinterpret_cast<void * *>(&::g_landBuf2)), 0xd8c);
            memcpy(geometry->tags[i], (*reinterpret_cast<void * *>(&::g_landBuf4)), 0x121);

            if (height != DAT_0102dcc4) {
                for (int j = 0; j < 0x121; ++j)
                    geometry->positions[i][j].z = height;
            }

            float* vertexData = new float[0x121 * 8];
            memset(vertexData, 0, 0x2420);
            for (int k = 0; k < 0x121; ++k)
                geometry->vertexRows[i][k] = vertexData + k * 8;
            memset(geometry->metadata[i], 0, 0x18);
        }
    }
    return true;
}
