
// blk_00640000_od_ctx_variant.cpp: context variant of src/staging/blk_00640000_od.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/staging/blk_00640000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <windows.h>
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSFaceGenEyeData.h"
#include "fnv/decl/BSFaceGenKeyframeMultiple.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/FG_00659100_cls.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_004b70d0_shell.h"
#include "fnv/decl/FUN_004bc480_shell.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_00508050_Class.h"
#include "fnv/decl/FUN_005ca4f0_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_00634900_shell.h"
#include "fnv/decl/FUN_00657f60_class.h"
#include "fnv/decl/FUN_0065d6e0_class.h"
#include "fnv/decl/FUN_0065eb90.h"
#include "fnv/decl/FUN_0065fd10_class.h"
#include "fnv/decl/FUN_00662820_shell.h"
#include "fnv/decl/FUN_006c63e0_Class.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/FloatInsertVector.h"
#include "fnv/decl/InsertVector.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Map62d0.h"
#include "fnv/decl/Mgr.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/NoiseGridBuilder.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/QueryOwner_b64d.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/S8.h"
#include "fnv/decl/S_0060b3f0.h"
#include "fnv/decl/S_0060b980.h"
#include "fnv/decl/Sd4e0.h"
#include "fnv/decl/V_006578b0.h"
#include "fnv/decl/_Dummy_0044a170.h"
#include "fnv/decl/fnv_006505d0__FUN_006505d0_class.h"
#include "fnv/decl/fnv_00650ba0__BSFaceGenModelMap_t.h"
#include "fnv/decl/fnv_00659310__FUN_00659310_Class.h"
#include "fnv/decl/fnv_00659440__FUN_00659440.h"
#include "fnv/decl/fnv_0065bf80__FUN_0065bf80_shell.h"
#include "fnv/decl/fnv_0065d740__FUN_0065d740_cls.h"
#include "fnv/decl/fnv_0065ec10__FUN_0065ec10_class.h"
#include "fnv/decl/fnv_0065ec40__FUN_0065ec40_Class.h"
#include "fnv/decl/fnv_0065ec70__FUN_0065ec70_class.h"
#include "fnv/decl/fnv_0065edd0__FUN_0065edd0_class.h"
#include "fnv/decl/fnv_0065f4f0__FUN_0065f4f0_cls.h"
#include "fnv/decl/fnv_0065f550__FUN_0065f550_Class.h"
#include "fnv/decl/fnv_0065f5a0__FUN_0065f5a0_cls.h"
#include "fnv/decl/fnv_0065fd40__FUN_0065fd40_class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00607000.h"
#include "fnv/symbols_00642000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_0064d000.h"
#include "fnv/symbols_0064e000.h"
#include "fnv/symbols_00650000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_00658000.h"
#include "fnv/symbols_00659000.h"
#include "fnv/symbols_0065e000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_00660000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00ab2000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01035000.h"
#include "fnv/symbols_01140000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_01200000.h"
#include "../../include/layout_support.h"
struct FUN_006427a0_Class
{
    void SetValue(float value);
};
struct FUN_00642890_Class
{
    void FUN_00642890();
};
struct GlobalObject_0040e0b0
{
    float* Float();
};
GlobalObject_0040e0b0 g_011ce00c;
struct Setting_S
{
    float* Float();
};
struct Helper_00644400
{
};
extern int DAT_0104f3e8;
struct FUN_006442b0_class
{
    void* vftable;
    void* FUN_006442b0(int a);
};
extern int DAT_0104f3e8;
struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void ResetPointer();
};
void GlobalObject_00869f00::Clear(bool b)
{
    delete[] p;
    if (b)
        p = 0;
}
struct FUN_00644790_class
{
    float FUN_00644790();
};
struct FUN_00645c20_Class
{
    unsigned short GetShortAtOffset1C0();
};
struct FUN_00645c80_Class
{
    bool IsFlagSet() const;
};
struct FUN_00645ca0_Class
{
    float GetField14C();
};
struct FUN_00645cc0_class
{
    float GetField150Float();
};
struct FUN_00645ce0_class
{
    float GetField154();
};
struct FUN_00647ac0_Class
{
    unsigned char GetByteAt0x62();
};
struct FUN_0064db00_class
{
    bool FUN_0064db00();
};
struct FUN_0064db50_class
{
    void FUN_0064db50(int a, int b);
};
struct FUN_0064dbd0_Class
{
    void FUN_0064dbd0();
};
struct FUN_0064dc30_class
{
    int FUN_0064dc30();
};
struct FUN_0064de50_class
{
    void* FUN_0064de50();
};
struct CF_0081c630
{
    void Init();
};
void CF_0081c630::Init()
{}
struct FUN_0064de90_class
{
    void FUN_0064de90();
};
struct FUN_0064deb0_Class
{
    void ForwardToFUN0064df50(int a, int b, int c, int d);
};
extern "C" void __cdecl FUN_0064e3f0(int, int, int);
struct FUN_0064dee0_Class
{
    void ForwardToHelper(int, int);
};
extern "C" void __cdecl FUN_0064e430(int, int);
struct FUN_0064df30_class
{
    void FUN_0064df30(int a);
};
extern "C" void __cdecl FUN_0064e630(void* a, void* b, void* c, void* d);
struct FUN_0064e480_Class
{
    void FUN_0064e480(void* a, void* b, void* c);
};
struct FUN_0065e9a0_holder
{
    void FUN_0065e9a0(int* p);
};
struct FUN_0064e7d0_class
{
    void FUN_0064e7d0(void* a, void* b);
};
extern "C" void __cdecl FUN_0064e920(int, int, int, int);
struct DecalStub
{
    float m_f;
    void FUN_00654700(float f);
};
struct FUN_00657880_class
{
    bool FUN_00658160(int);
    bool operator==(int other);
};
struct FUN_00657be0_class
{
    int a;
    int b;
    void AddToA();
};
struct FUN_00658100
{
};
struct FUN_00657fd0
{
    void Method_00657fd0();
};
extern "C" void __cdecl FUN_00658bd0(int a1, int a2, int a3);
struct FUN_00657ff0_Class
{
    void FUN_00657ff0(int a1, int a2);
};
extern "C" void __cdecl FUN_00658c10(int a, int b);
struct FUN_00658020_Class
{
    void FUN_00658020(int a);
};
struct FUN_00658130
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
struct FUN_00658040
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    void Call_00658040();
};
struct FUN_00658060_Class
{
    void FUN_00658060(int a, int b);
};
struct FUN_00658090_Class
{
    void FUN_00658090(int a);
};
struct FUN_00658930_class
{
    unsigned int GetShortAtOffsetA() const;
};
extern "C" void __cdecl FUN_00659230(int, int);
extern int DAT_01065870;
struct FUN_00658aa0_class
{
    void* vtbl;
    void FUN_00659230(int a, int b);
    FUN_00658aa0_class* Initialize(int a, unsigned char b);
};
struct NiTStringTemplateMap
{
    int m_auiShapeKeys[1];
    int m_pObject;
};
struct BSFaceGenModelMap
{
    void FUN_00658b80(NiTStringTemplateMap* pStringMap);
};
struct FUN_00658d30_class
{
    void FUN_00658d50();
    void FUN_00658d30();
};
struct FUN_00659170
{
    FUN_00659170();
};
struct FUN_00659210_Class
{
    int FUN_00659210(char a, int b);
};
struct FUN_006592f0
{
    void operator()(void*);
};
struct FUN_00659310_
{
};
extern int DAT_010658b0;
struct FUN_00659490_cls
{
};
struct FUN_00659460_cls
{
    int* m;
    FUN_00659460_cls* Construct(int a);
};
extern "C" void* DAT_00fdf07c;
struct FUN_00659540_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00659540();
};
struct FUN_0065cc30_class
{
    int FUN_0065cc30();
};
struct FUN_0065cc50_Class
{
    int FUN_0065cc50();
};
struct FUN_0065cea0_class
{
    int FUN_0065cea0();
};
struct FUN_0065cf90_class
{
    void* FUN_0065cf90();
};
struct FUN_0065cfb0_Class
{
    void FUN_0065cfb0();
};
struct FUN_0065db40_class
{
    void* FUN_0065db40();
};
struct FUN_0065db60_class
{
    void FUN_0065db60(int a, int b);
};
struct FUN_0065e020_class
{
};
struct FUN_0065db90_class
{
    void FUN_0065db90();
};
struct FUN_0065dbb0_class
{
    void FUN_0065dbb0(int arg);
};
struct FUN_0065dbf0_class
{
    void CallWithThisOffset(int a, int b);
};
struct FUN_0065dc20_class
{
    void FUN_0065dc20(int a);
};
struct FUN_0065dc60Class
{
    void FUN_0065dc60(int a, int b);
};
struct FUN_0065dd50_Class
{
    void FUN_0065dd50(int a);
};
struct FUN_0065dd70_Class
{
    void FUN_0065dd70();
};
struct FUN_0065ddc0_class
{
    void FUN_0065ddc0(int a);
};
struct FUN_0065dde0_Class
{
    void FUN_0065dde0();
};
extern "C" void __cdecl FUN_0065e510(int, int, int);
struct FUN_0065de00_Class
{
    void FUN_0065de00(int a, int b);
};
extern "C" void __cdecl FUN_0065e5a0(int, int, int);
struct FUN_0065de80_Class
{
    void FUN_0065de80(int a, int b);
};
struct FUN_0065deb0_Class
{
    void FUN_0065deb0(int arg);
};
struct FUN_0065df10_class
{
    void FUN_0065df10(void* b, void* c);
};
struct FUN_0065df40_class
{
    void FUN_0065df40(int a);
};
struct FUN_0065df60_class
{
    void FUN_0065df60();
};
struct FUN_0065df80_class
{
    void FUN_0065df80(int a, int b);
};
struct FUN_0065dfb0_Class
{
    void FUN_0065dfb0(int a);
};
struct FUN_0065dfd0_class
{
    bool FUN_0065dfd0(int);
};
struct FUN_0065e000_class
{
    int FUN_0065da80(int a, int b);
    int FUN_0065e000(int a, int b);
};
struct FUN_0065e9a0
{
};
struct FUN_0065e9a0_t
{
    void FUN_0065e9a0(void*);
};
struct FUN_0065ea00_class
{
};
struct FUN_0065ea60_class
{
};
extern "C" void __cdecl FUN_0065eb00(int);
struct FUN_0065e9c0_class
{
    void FUN_0065e9c0(int arg);
};
struct FUN_0065e9e0_Class
{
    void FUN_0065e9e0(void* a);
};
struct FUN_0065ea20_Class
{
    void FUN_0065ea20(int a);
};
struct FUN_0065ea40_class
{
    void FUN_0065ea40(int a);
};
struct FUN_0065ea60_cls
{
    void FUN_0065ea60(void* a);
};
struct FUN_0065ee70_class
{
    void FUN_0065ee70();
};
struct FUN_0065ee30_class
{
    void FUN_0065ee30();
};
struct FUN_0065f2b0_class
{
    void FUN_0065f2b0(int a, int b);
};
struct FUN_0065f400_class
{
    void FUN_0065f400(int a, int b);
};
struct FUN_0065f7c0_Class
{
};
struct FUN_0065f580_Class
{
    void FUN_0065f580();
};
extern "C" void __cdecl FUN_0065f9e0(int a, int b);
struct FUN_0065f6c0_class
{
    void FUN_0065f6c0(int a);
};
struct FUN_0065f7a0_Class
{
    void* FUN_0065f7a0(void* arg);
};
extern "C" void __cdecl FUN_0065fde0(int, int, int, int);
struct FUN_0065f890_class
{
    void FUN_0065f890(int a1, int a2, int a3);
};
struct FUN_0065f930_Class
{
    void FUN_0065f930(int a, int b, int c);
};
extern void* DAT_010658d0;
struct FUN_00658e70_cls : public NiTPointerMap<int, int>
{
    void FUN_00658e70();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00b64d60_Class
{
};
struct FUN_00642860_Class
{
    void FUN_00642860();
};
struct GameSettingCollection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetFloat(unsigned int index);
};
struct FUN_00644350_Class
{
};
void* __cdecl operator new(unsigned int size, void* placement);
struct FUN_00644490_Class
{
    void FUN_00644490(char* items, unsigned int count);
};
struct FUN_006444e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    void* FUN_006444e0(int a, int b, int c, int d);
};
GlobalObject_0040e0b0 g_011ce840;
GlobalObject_0040e0b0 g_011cfd8c;
struct ActorValueOwner
{
    float GetActorValueFloatByIndex(ActorValue::Index);
};
struct S_0064dac0
{
    int FUN_0064dac0(int, int);
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0064db20_Class
{
    void* GetEntryAt(unsigned int a);
};
struct Caller
{
};
struct Pair
{
    int a;
    int b;
};
struct Tgt
{
    Pair m;
    int* CopyPairAfterCallback(int* p1, int p2);
};
struct FUN_0064e2d0_Holder
{
    unsigned int FUN_0064e2d0() const;
};
struct FUN_0064e300_Class
{
    int FUN_0064e300();
};
struct FUN_0064e340_class
{
    void* FUN_0064e340(int a, int b, int c);
};
extern "C" void __cdecl FUN_0064e3f0(int, int, int);
// @fnv 0x0064e3f0
extern "C" void __cdecl FUN_0064e3f0(int a, int b, int c)
{
    char v = ((char)(::FUN_0065e750(&a, &b)));
    ::FUN_0064e600((int *)(a), (int *)(b), (::FUN_0065e9a0_holder *)(c));
}
struct FUN_0064e680_S
{
    int m0;
    int m1;
    int m2;
    int m3;
};
struct FUN_0064e7f0_S
{
    int f0;
    int f4;
    int f8;
    int fC;
};
struct FUN_0064e980_Block
{
    int m0;
    int m4;
    int m8;
    int mC;
};
struct BSFaceGenManager
{
public:
    static ::BSFaceGenManager *GetFaceGenManager();
};
struct Holder00aad6b0
{
};
struct Class_00658100
{
    unsigned int FUN_00658100();
};
struct Dummy658130
{
    unsigned FUN_00658130();
};
void FUN_00658bd0(int a1, int a2, int a3);
void __cdecl operator delete(void* p);
struct FUN_00658bb0_Class
{
    void FUN_00658bb0();
};
struct FUN_00658d00_Class
{
    void* FUN_00658d00(unsigned int flags);
};
struct FUN_00658ea0_cls
{
    void* FUN_00658ea0(unsigned int);
};
void __cdecl operator delete(void* p);
struct FUN_00658ed0_Class
{
    void FUN_00658e10();
    void* FUN_00658ed0(unsigned int flags);
};
struct FUN_00658f00_Class : public FUN_00658d30_class
{
    FUN_00658f00_Class* FUN_00658f00(unsigned int flags);
};
struct Pair590
{
    int a;
    int b;
};
struct S_006590c0
{
    void* CopyPairTo(void* p, int q);
};
struct FUN_006a68b0_Class
{
    void FUN_006a68b0();
};
void __cdecl operator delete(void*);
struct FUN_00659140_Class
{
    void* FUN_00659140(unsigned int flags);
};
extern int DAT_010658f0;
struct FUN_00659230
{
    void* vptr;
    FUN_00659230(int a, unsigned char b);
};
struct S_006592c0
{
    void* FUN_006592c0(unsigned int flags);
};
extern int DAT_01065890;
struct FUN_00659330_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    unsigned char m_10;
    void* InitializeWithGlobal(int a, unsigned char b);
};
struct FUN_00659380_cls
{
};
struct FUN_006593b0_class
{
};
void __cdecl operator delete(void*);
struct FUN_00659380_class
{
    void* FUN_00659380(unsigned int flags);
};
struct FUN_00659440_Class
{
};
struct FUN_006593b0_Class
{
    void* FUN_006593b0(unsigned int flags);
};
struct NarrowString
{
    char* p;
    ~NarrowString();
};
struct FaceGenMatrix
{
    ~FaceGenMatrix();
};
struct FUN_006593e0_Class
{
    FaceGenMatrix m_iWordAt00;
    char m_20[28];
    NarrowString m_40;
    ~FUN_006593e0_Class();
};
struct FUN_00659500_Holder
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00659500_Holder* InitSemaphore(int a, int b);
};
struct FUN_0065b3e0_Holder
{
    char _pad[16];
    void* m_10;
    void* m_14;
    void* GetPointerByFlag(bool);
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0065cc70_Holder
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int FUN_0065cc70(unsigned int param);
};
struct TextureBasis
{
};
unsigned int __cdecl FUN_00ec7c56();
struct Holder : TextureBasis
{
    int FUN_0065cec0(unsigned int);
};
struct Pair65cf50
{
    int a;
    int b;
};
struct Holder65cf50
{
    Pair65cf50 data;
    void* CopyDataAfterCallback(void* p, int q);
};
struct FUN_0064df10_helper
{
    void deallocate(void* p, unsigned int n);
};
struct FUN_0065d150_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void ClearStorage();
};
struct FUN_0065dd90_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_0065dd90(int a1, int a2);
};
struct _Out_0044a170
{
};
struct FUN_0065ded0_Class
{
    _Out_0044a170* FUN_0065ded0(_Out_0044a170* a1, int a2, int a3);
};
struct FUN_0065e020_Cls
{
    int FUN_0065e020();
};
struct FUN_0065e050_Holder
{
    int FUN_0065e050();
};
struct FUN_0065e080_S
{
    int FUN_0065e080();
};
struct FUN_0065e0b0_Class
{
    unsigned int FUN_0065e0b0();
};
struct FUN_0065e110_Holder
{
    int GetPositiveValue();
};
struct S_0065e140
{
    unsigned int FUN_0065e140();
};
struct FUN_0065e170_Cls
{
    unsigned FUN_0065e170();
};
void FUN_0065e510(int a, int b, int c);
void __cdecl FUN_0065e5a0(int a, int b, int c);
struct S_0065eb60
{
};
struct S_0065eb90
{
};
struct FUN_0065ec10_class
{
};
void __cdecl FUN_0065eb00(int a);
struct FUN_0065ec40_class
{
};
struct FUN_0065ec70_class
{
};
struct FUN_0065ecd0_Class
{
};
struct FUN_0065ed00_Class
{
};
struct Sub_0065eed0
{
};
struct Owner_0065eb60
{
    float m_iWordAt00;
    Sub_0065eed0 m_iWordAt04;
    Owner_0065eb60& FUN_0065eb60(const Owner_0065eb60&);
};
void __cdecl operator delete(void*);
struct FUN_0065eca0_class
{
    void* FUN_0065eca0(unsigned int flags);
};
struct FUN_0065ecd0_class
{
    void* FUN_0065ecd0(unsigned int flags);
};
void __cdecl operator delete(void* p);
struct FUN_0065ed00_class
{
    void* FUN_0065ed00(unsigned int flags);
};
void FUN_0065f060();
void FUN_0065ee50_Helper(void*, unsigned int, int, void (*)());
struct FUN_0065ee50_S
{
    char m_auiShapeKeys[16];
    char m_aiIndexedValues[72];
    void FUN_0065ee50();
};
struct S_0065f2e0
{
    int _0;
    int _4;
    int _8;
    int m_iThirdValue;
    int _10;
    int m_14;
    int FUN_0065f2e0();
};
struct FUN_0065f4b0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int FUN_0065f4b0();
};
struct S_0065f7c0
{
    unsigned int FUN_0065f7c0();
};
struct FUN_0065f7f0_Class
{
    unsigned int FUN_0065f7f0() const;
};
struct FUN_0065fb10_Class
{
    void FUN_0065fb10(const FUN_0065fb10_Class& other);
};
struct FUN_0065fa80_Holder
{
    float m_iWordAt00;
    FUN_0065fb10_Class m_iWordAt04;
    FUN_0065fa80_Holder& FUN_0065fa80(const FUN_0065fa80_Holder& other);
};
int __cdecl FUN_00ec7ce3(void* a1, unsigned int a2, void* a3, unsigned int a4);
struct FUN_0065ff30_Class
{
    void FUN_0065ff30(int a, int b, int c, int d, int e);
};
struct FUN_0065ff60_class
{
    void FUN_0065ff60(int a, int b, int c, int d, int e);
};
struct NiRTTI;
struct NiProperty;
struct NiTexture;
struct PropHelper
{
};
struct SkyShaderProperty
{
};
extern int DAT_011f49e0;
struct FUN_00642940_class
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    void FUN_00642940();
};
struct Arr16
{
};
struct FUN_00644400_Class
{
    virtual void v0();
    virtual int v1(int a);
    void FUN_00644400(unsigned int a, unsigned int b);
};
struct FUN_00657e60_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void FUN_00657e60();
};
struct H_0060b3b0
{
};
int __cdecl _memcmp(const void* a, const void* b, unsigned int n);
struct FUN_0065d460_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void FUN_0065d460();
};
struct FUN_0065d660_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void FUN_0065d660();
};
struct FUN_0065d860_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void FUN_0065d860();
};
struct EGMDeltaList;
struct Elem_65eed0
{
    short a, b, c;
};
Elem_65eed0* __cdecl FUN_0065f820(Elem_65eed0*, Elem_65eed0*, Elem_65eed0*);
struct Vec_65eed0
{
    void* unk00;
    void* _Myfirstiter;
    FUN_0064df10_helper _Alval;
    Elem_65eed0* _Myfirst;
    Elem_65eed0* _Mylast;
    Elem_65eed0* _Myend;
    void FUN_0065f320();
    Vec_65eed0* FUN_0065eed0(Vec_65eed0* _Right);
};
struct FUN_0065f430_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    int m_10;
    int m_14;
    void FUN_0065f430();
};
struct FUN_0064cc90_Class
{
    void FUN_0064cc90(unsigned char bFlag);
};
struct FUN_00659490_cls2
{
    void* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00659490_cls2* InitArray(int count);
};
struct FUN_0065d050
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void Clear_0065d050();
};
struct FUN_0065f240
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_auiShapeKeys;
    int m_buf;
    int m_iElementCount;
    int m_cap;
    void Clear();
};
struct StartMenu
{
};
struct GlobalObject_0040c150 : public StartMenu
{
};
struct FUN_0064da80_Class
{
    int FUN_0064da80(int a, int b);
};
struct FUN_0064daa0_Class
{
    int FUN_0064daa0(int a, int b);
};
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct Calendar : public BGSTerrainManager
{
};
struct GO
{
    ~GO();
};
struct Helper62d0
{
    void* operator=(const void*);
};
struct FUN_00658ad0_arg
{
    int m_iWordAt00;
    char* m_iWordAt04;
    Helper62d0 m_8;
};
struct FUN_00658ad0_class
{
    void AssignString(FUN_00658ad0_arg* arg, char* source, GO value);
};
int __cdecl strcpy_s(char*, unsigned int, char*);
int __cdecl strlen(char*);
extern unsigned int _data_011c16bc;
struct FUN_00658bb0 : FUN_00658d30_class
{
    ~FUN_00658bb0();
};
struct FUN_0065d240_class
{
    void ClearAndFree();
};
struct FUN_0065d560_Class
{
    void ClearAndFreeBuffer();
};
struct FUN_0065da00_class
{
    void FUN_0065da00();
};
struct FUN_0065dbd0_Class
{
    int a0;
    int a4;
    int FUN_0065dbd0();
};
struct FUN_0065dc40_Class
{
    int CallNestedMethod();
};
struct FUN_0065de60_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int FUN_0065de60();
};
struct FUN_0065def0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    unsigned int FUN_0065def0();
};
struct CIdvFilenameDestructorHelper
{
    void NarrowString();
};
struct FUN_0065ed30_class
{
    void FUN_0065ed30();
};
struct CIdvFilenameDtorHelper
{
};
struct FUN_0065ed50_Class
{
    void FUN_0065ed50();
};
struct FUN_0044a9d0_Class
{
};
struct FUN_0065f6e0_Class
{
    int m0;
    int m4;
    FUN_0044a9d0_Class m8;
    unsigned int GetNestedValue();
};
extern const char DAT_0104f2ac;
struct FUN_00404eb0
{
    int state;
    FUN_00404eb0(int category, int enabled, const char* source, int line);
    ~FUN_00404eb0();
};
struct FUN_00508050
{
};
struct FUN_00559450
{
};
struct FUN_006427c0_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FUN_00559450 unk28;
    float FUN_006427c0();
};
struct Value_006428b0
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
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float unk6c;
};
struct Link_006428b0
{
};
struct Container_006428b0
{
    Link_006428b0* FUN_00559450(int index);
};
struct Object_006428b0
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Container_006428b0 unk14;
    float GetLinkedValueFloat();
};
struct FUN_0066ef50_Class
{
};
class FUN_00644350_cls
{
  public:
    int m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    unsigned char IsGreaterThan(FUN_00644350_cls* other);
};
struct AVOwnerStub_646400
{
    virtual float GetAV0(int index);
    virtual float GetBaseAV(int index);
    virtual float GetAV2(int index);
    virtual float GetCurAV(int index);
};
struct FloatSetting_646400
{
    float* Float();
};
extern FloatSetting_646400 originalRuntimeFloatSetting762;
extern FloatSetting_646400 originalRuntimeFloatSetting763;
extern FloatSetting_646400 g_011ce78c;
extern FloatSetting_646400 g_011ce064;
extern FloatSetting_646400 g_011ceecc;
extern FloatSetting_646400 gs_011cecd0;
extern FloatSetting_646400 gs_011ce808;
struct FUN_00647a30_Obj
{
    virtual void unk00();
    virtual float unk04(int arg);
};
struct FUN_00647a30_Flag
{
};
class SettingValue
{
  public:
};
extern SettingValue g_011cee24;
extern SettingValue g_011cf314;
extern SettingValue g_011ced28;
extern SettingValue g_011ceb38;
// Scale a value by the remaining fraction (max - current) / max, clamped to [0, 1].
float __cdecl ScaleByInverseRatio(float fValue, float fScaledValue, float fCurrentAmountNext);
struct S_00648ea0_Setting
{
};
int __cdecl ComputeWeightedValue(float value1, float value2, int weight);
struct FUN_0064bda0_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual float vf94(int index);

    int FUN_0064bda0();
};
inline void FUN_0064bda0_Class::vf04()
{}
inline void FUN_0064bda0_Class::vf08()
{}
inline void FUN_0064bda0_Class::vf0c()
{}
inline void FUN_0064bda0_Class::vf10()
{}
inline void FUN_0064bda0_Class::vf14()
{}
inline void FUN_0064bda0_Class::vf18()
{}
inline void FUN_0064bda0_Class::vf1c()
{}
inline void FUN_0064bda0_Class::vf20()
{}
inline void FUN_0064bda0_Class::vf24()
{}
inline void FUN_0064bda0_Class::vf28()
{}
inline void FUN_0064bda0_Class::vf2c()
{}
inline void FUN_0064bda0_Class::vf30()
{}
inline void FUN_0064bda0_Class::vf34()
{}
inline void FUN_0064bda0_Class::vf38()
{}
inline void FUN_0064bda0_Class::vf3c()
{}
inline void FUN_0064bda0_Class::vf40()
{}
inline void FUN_0064bda0_Class::vf44()
{}
inline void FUN_0064bda0_Class::vf48()
{}
inline void FUN_0064bda0_Class::vf4c()
{}
inline void FUN_0064bda0_Class::vf50()
{}
inline void FUN_0064bda0_Class::vf54()
{}
inline void FUN_0064bda0_Class::vf58()
{}
inline void FUN_0064bda0_Class::vf5c()
{}
inline void FUN_0064bda0_Class::vf60()
{}
inline void FUN_0064bda0_Class::vf64()
{}
inline void FUN_0064bda0_Class::vf68()
{}
inline void FUN_0064bda0_Class::vf6c()
{}
inline void FUN_0064bda0_Class::vf70()
{}
inline void FUN_0064bda0_Class::vf74()
{}
inline void FUN_0064bda0_Class::vf78()
{}
inline void FUN_0064bda0_Class::vf7c()
{}
inline void FUN_0064bda0_Class::vf80()
{}
inline void FUN_0064bda0_Class::vf84()
{}
inline void FUN_0064bda0_Class::vf88()
{}
inline void FUN_0064bda0_Class::vf8c()
{}
inline void FUN_0064bda0_Class::vf90()
{}
inline float FUN_0064bda0_Class::vf94(int)
{
    return 0.0f;
}
int FUN_0064bda0_Class::FUN_0064bda0()
{
    int result = -1;

    {
        float bestValue = 0.0f;

        {
            int index = -1;

            for (; index < 15; ++index)
            {
                float value = this->vf94(index);

                if (value > ::_DAT_01012060 && value >= ::_DAT_01012060 && value <= ::g_01012070 && value > bestValue)
                {
                    bestValue = value;
                    result = index;
                }
            }
        }
    }

    return result;
}
struct FUN_0040fbf0_lock
{
};
struct FUN_0064be40_shell
{
    bool FUN_0064be40(float elapsed, int unused);
};
struct FUN_00403e20_setting
{
};
struct S_0064ccf0_Obj
{
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
    virtual int vfn_94();
    virtual int vfn_98();
};
struct S_0064ccf0_Base
{
    int unk04;
    S_0064ccf0_Base();
    virtual ~S_0064ccf0_Base();
};
struct S_0064ccf0_Ptr
{
    S_0064ccf0_Obj* unk00;
    S_0064ccf0_Ptr(S_0064ccf0_Obj* p);
    ~S_0064ccf0_Ptr();
    S_0064ccf0_Ptr& operator=(S_0064ccf0_Obj* p);
    operator S_0064ccf0_Obj*() const;
};
struct S_0064ccf0_Member
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_0064ccf0_Member();
    ~S_0064ccf0_Member();
};
struct FUN_0064ccf0 : S_0064ccf0_Base
{
    S_0064ccf0_Ptr unk08;
    S_0064ccf0_Member unk0c;
    int unk24;
    int unk28;
    FUN_0064ccf0(S_0064ccf0_Obj* a);
    virtual ~FUN_0064ccf0();
};
extern unsigned char DAT_011f94b0;
class ConstIter64D
{
  public:
    ConstIter64D();

    int* m_pMyCont;
    int* m_pPtr;
};
class Iter64D : public ConstIter64D
{
  public:
    Iter64D();
};
class Vector64D
{
  public:
    Iter64D begin();
    Iter64D end();
    void FUN_0064db70();
};
struct PairDword
{
    int a;
    int b;
};
extern "C" int __cdecl FUN_0064e380(int, int, int);
class FUN_0064dc50_cls
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    PairDword FUN_0064dc50(int p1, int p2, int p3, int p4);
};
struct Vec2i
{
    int x;
    int y;
};
struct Vector4f
{
    int a;
    int b;
    int c;
    int d;
};
struct Ret8
{
    int x;
    int y;
    Ret8()
    {}
    Ret8(const Ret8& other)
    {
        x = other.x;
        y = other.y;
    }
};
class FUN_0064dcf0_cls
{
  public:
    void ApplyToCopy(int a1, const Vector4f* a2);
};
struct FUN_0064dda0_target
{
    char pad_00[0x10];
    unsigned int m_10;
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0064dda0_cls
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int FUN_0064dda0();
};
unsigned int __cdecl FUN_00ec7c56(void);
struct S_0064ddf0_Container
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int end;
};
struct S_0064ddf0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_0064ddf0_Iter
{
    int unk00;
    S_0064ddf0_Elem* ptr;
    S_0064ddf0_Iter* Increment();
};
namespace std {
struct exception
{
    virtual ~exception() throw();
    const char* message;
    bool ownsMessage;
};
struct bad_alloc : public exception
{
    bad_alloc(const char* = 0) throw();
};
}
// @fnv 0x0064e430
extern "C" void __cdecl FUN_0064e430(int count, int unused)
{
    if ((unsigned int)count <= 0u)
        count = 0;
    else if (0xffffffffu / (unsigned int)count < 16u)
        throw std::bad_alloc();
    ::FUN_00401000((unsigned int)count * 16u);
}
struct C64E550CheckedTag
{
};
struct C64E550PtrCategory
{
};
struct C64E550Element;
struct C64E550Allocator;
struct FUN_0064e630_flag
{
    bool m_flag;
};
// @fnv 0x0064e630
extern "C" void __cdecl FUN_0064e630(void* a, void* b, void* c, void* d)
{
    FUN_0064e630_flag aa = {};
    unsigned char zz = ::FUN_0065e750(&c, {});
    ::ForwardToHandler(CallWithFlag((int*)&a), CallWithFlag((int*)&b), (int)(c), (int)(d));
}
struct SpawnedFlagBox
{
    unsigned char v;
};
// @fnv 0x0064e6c0
extern "C" void __cdecl FUN_0064e6c0(void* a1, void* a2, void* a3, unsigned char a4)
{
    SpawnedFlagBox flagA3 = {};
    unsigned char flagB;
    flagB = FUN_0065e750(&a1, &a3);
    ::FUN_0064e860((::S_0064e860_Block *)(a1), (::S_0064e860_Block *)(a2), (::S_0064e860_Block *)(a3));
}
struct S_0064e860_Block
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};
struct S_0064e860_TagBase
{
};
struct S_0064e860_TagA : S_0064e860_TagBase
{
};
struct S_0064e860_TagB
{
};
struct S_0064e860_TagC
{
};
struct S_0064e8c0_Blk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct FlagBox5317
{
    unsigned char v;
};
// @fnv 0x0064e920
extern "C" void __cdecl FUN_0064e920(int a, int b, int c, int d)
{
    FlagBox5317 flag1 = {};
    unsigned char flag2 = FUN_0065e750((void*)&a, (void*)&c);
    ::FUN_0064e9c0((::Elem64e9 *)(CallWithFlag((int*)&a)), (::Elem64e9 *)(CallWithFlag((int*)&b)), (::Elem64e9 *)(c), (*(::Alloc64e9 *)(d)), (::NonscalarTag64e9)(flag2), (::CheckedTag64e9)(flag1.v));
}
struct FUN_0064fcd0_Other
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual float v03();
};
struct FUN_0064fcd0_Self
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual void v04(float value);
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual void v20(unsigned int value);
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiItemCount;
    FUN_0064fcd0_Self* CopyFrom(FUN_0064fcd0_Other* other);
};
struct FUN_00438af0_cls
{
};
struct FUN_0064fe10_cls
{
    virtual void unk00();
    FUN_00658bb0 m_04;

    virtual ~FUN_0064fe10_cls();
};
struct PathingSolution
{
    void IncRefCount();
    void DecRefCount();
};
struct PathingSolutionBase
{
    int unk04;
    PathingSolutionBase();
    ~PathingSolutionBase();
    virtual void Release()
    {}
};
struct FUN_00650100 : PathingSolutionBase
{
    NiPointer<PathingSolution> m_pPathingSolution;
    FUN_00650100();
};
struct S_006503b0_Elem;
struct S_006503b0_Slot
{
    int unk00;
    S_006503b0_Slot(int);
    ~S_006503b0_Slot();
    void FUN_0066b0d0(int);
    S_006503b0_Elem* FUN_00559450();
};
struct S_006503b0_Elem
{
    int unk00;
    int unk04;
    S_006503b0_Slot slot08;
};
struct S_006503b0_List
{
};
struct S_006503b0_Owner
{
    int unk00;
    S_006503b0_List list04;
    void FUN_006503b0();
};
struct ModelHelper
{
};
struct InnerPointer
{
    ModelHelper* FUN_00559450();
};
struct ModelRecord
{
    int unk00, unk04;
    InnerPointer model;
    unsigned time;
};
struct NPX
{
    ModelRecord* ptr;
    NPX(int);
    ~NPX();
    ModelRecord* FUN_00559450();
};
struct FileNames
{
};
struct CacheMap
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
};
struct Target
{
    int unk00;
    CacheMap map;
    bool dirty;
    bool FUN_00650480(FileNames*);
};
struct Holder_657c50
{
};
struct Pair_657c50
{
    int m_iWordAt00;
};
struct Blk_657c50
{
    int m_iWordAt00;
    int m_iWordAt04;
};
struct FUN_00657c50_cls
{
    void* FUN_00657c50(void* a, Pair_657c50 b, int c, int d);
};
struct Sub_657cd0_08
{
};
class FUN_00657cd0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;

    bool ReserveEntries(unsigned int idx);
};
struct FUN_00657d50_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void FUN_00657d50();
};
struct FUN_00657d50_callee_a
{
};
struct FUN_00657d50_callee_b
{
};
struct SubPool_08
{
    int m_00;
};
struct FUN_00657dd0_cls
{
    int m_00;
    int m_04;
    SubPool_08 m_08;
    char* m_0c;
    char* m_10;
    char* m_14;
    bool FUN_00657dd0(unsigned int index);
};
struct FUN_00657ee0_sub
{
    int unk00;
};
struct FUN_00657ee0_cls
{
    int unk00;
    int unk04;
    FUN_00657ee0_sub m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    bool FUN_00657ee0(unsigned int a);
};
class SpanEntry;
class FUN_006580b0_cls
{
  public:
    int unk00;
    SpanEntry* m_pEntries;

    int GetEntryOffset(FUN_006580b0_cls* other);
};
struct FNV_MapKey
{
    int value;
    FNV_MapKey(const FNV_MapKey&);
    ~FNV_MapKey();
    void FUN_006e5cc0(FNV_MapKey*);
};
struct FNV_MapNode
{
    FNV_MapNode* next;
    int id;
    FNV_MapKey key;
};
struct FNV_HashMap
{
    virtual void Reserved();
    virtual int Hash(int id);
    virtual bool Equals(int id, int existing);
    virtual void Init(FNV_MapNode* node, int id, FNV_MapKey key);
    unsigned int unk04;
    FNV_MapNode** buckets;
    int count;
    bool keepExisting;
    void InsertOrUpdate(int id, FNV_MapKey key);
};
struct Hldr0044
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
extern "C" void FUN_00ec7894(Hldr0044* p, void* dat);
class Base_b9895
{
  public:
    Base_b9895();
    ~Base_b9895();

    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
class FUN_00659000 : public Base_b9895
{
  public:

    int m_18;
    int m_1c;

    FUN_00659000(int a, int b);
};
struct FUN_0065cd70_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    ~FUN_0065cd70_Elem();
};
struct FUN_00659600
{
    int unk00;
    FUN_0065cd70_Elem m_aiIndexedValues[2];

    ~FUN_00659600();
};
struct PacketEntry
{
    unsigned int identifier;
    unsigned int state;
    unsigned int offset;
    unsigned int length;
    unsigned int mode;
    unsigned int flags;
    PacketEntry();
    ~PacketEntry();
};
struct PacketScope
{
    unsigned int key;
    unsigned int state;
    unsigned int start;
    unsigned int end;
    unsigned int flags;
    unsigned int context;
    unsigned int owner;
    PacketScope(unsigned int selector);
    ~PacketScope();
};
struct FUN_00659670
{
    unsigned int mode;
    PacketEntry entries[2];
    FUN_00659670(unsigned int selector);
};
struct FUN_00659710_elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void Init();
    ~FUN_00659710_elem();
};
class FUN_00659710_cls
{
  public:
    int m_00;
    FUN_00659710_elem m_04[2];
    ~FUN_00659710_cls();
};
class OwnerBase
{
  public:
    virtual ~OwnerBase();
    int m_iWordAt04;
    int m_8;

    OwnerBase(void* p);
};
class SubMember
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;

    SubMember(bool flag);
    ~SubMember();
    void Apply(int value);
};
class FUN_0065be60 : public OwnerBase
{
  public:
    SubMember m_iThirdValue;

    FUN_0065be60(int a);
    virtual ~FUN_0065be60();
};
struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
struct FUN_0065c7c0 : FUN_0065cfb0
{
    ~FUN_0065c7c0();
};
// Container default constructor: base storage takes a default allocator, then reserve nothing.
class C5C820Allocator
{
  public:
    C5C820Allocator();
    C5C820Allocator(const C5C820Allocator& kOther);
};
class C5C820Storage
{
  public:
    C5C820Storage(C5C820Allocator kAlloc);
    ~C5C820Storage();
    void* m_pFirst;
    void* m_pLast;
    void* m_pRecordEnd;
};
class FUN_0065c820 : public C5C820Storage
{
  public:
    FUN_0065c820();
};
struct FUN_0065cfb0_base
{
    int unk00;
    ~FUN_0065cfb0_base();
};
struct FUN_0065c890_cls : FUN_0065cfb0_base
{
    ~FUN_0065c890_cls();
};
class ScopeBase_c960
{
  public:
    ~ScopeBase_c960();
    int unk04;
};
class FUN_0065c960_cls : public ScopeBase_c960
{
  public:
    ~FUN_0065c960_cls();
    void unk08();
};
struct Mem_65ca30
{
    ~Mem_65ca30();
};
struct FUN_0065ca30
{
    Mem_65ca30 m_mem;
    ~FUN_0065ca30();
};
struct FUN_006815c0
{
    void* object;
    FUN_006815c0();
    ~FUN_006815c0();
};
struct FUN_0065de30
{
    unsigned int value;
    FUN_0065de30(const FUN_0065de30&);
    unsigned int FUN_0044abd0(int flag);
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(void* owner);
    ~FUN_008c71b0();
    static void* operator new(unsigned int, unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_0065dc90 : FUN_006815c0
{
    FUN_0065de30 member;
    FUN_0065dc90(FUN_0065de30 argument);
};

struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 value);
    ~FUN_0065d3a0();
};
struct FUN_0065ca90 : FUN_0065d3a0
{
    FUN_0065ca90();
};
// Container default constructor: base storage takes a default allocator, then reserve nothing.
class C5CB60Allocator
{
  public:
    C5CB60Allocator();
    C5CB60Allocator(const C5CB60Allocator& kOther);
};
class C5CB60Storage
{
  public:
    C5CB60Storage(C5CB60Allocator kAlloc);
    ~C5CB60Storage();
    void* m_pFirst;
    void* m_pLast;
    void* m_pRecordEnd;
};
class FUN_0065cb60 : public C5CB60Storage
{
  public:
    FUN_0065cb60();
};
struct FUN_0065cfb0_Base
{
    ~FUN_0065cfb0_Base();
};
struct FUN_0065cd10 : FUN_0065cfb0_Base
{
    ~FUN_0065cd10();
};
struct B65CD70ConstIterator
{
    float* m_pfData;
    int m_iArrayCapacity;
};
struct B65CD70Iterator : public B65CD70ConstIterator
{
};
// clear(): erase(begin(), end())
class B65CD70Vector
{
  public:
    B65CD70Iterator begin();
    B65CD70Iterator end();

    void FUN_0065cd70();
};
class C65CE40List
{
  public:
    ~C65CE40List();

    int unk00;
    int unk04;
};
class FUN_0065ce40 : public C65CE40List
{
  public:
    ~FUN_0065ce40();

    void RemoveAll();
};
struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
};
class FUN_0065cef0_cls
{
  public:
    void FUN_0065cef0();
};
struct FUN_0065cfd0_sub
{
    int m_iWordAt00;
};
struct FUN_0065cfd0_cls
{
    int m_00;
    int m_04;
    FUN_0065cfd0_sub m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    bool ReserveItems(unsigned int n);
};
struct FUN_0065d0d0_sub
{
    int unk00;
};
struct FUN_0065d0d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_0065d0d0_sub m_08;
    char* m_0c;
    char* m_10;
    char* m_14;

    bool ReserveBuffers(unsigned int count);
};
struct S_0065d1c0_Element
{
};
struct S_0065d1c0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    S_0065d1c0_Element m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;

    bool AllocateElements(unsigned int a);
};
struct FUN_0065d2b0_sub
{
    int unk00;
};
struct FUN_0065d2b0_cls
{
    int unk00;
    int unk04;
    FUN_0065d2b0_sub m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    bool FUN_0065d2b0(int n);
};
struct S_0065d3e0_Pool
{
    int unk00;
};
struct S_0065d3e0_Class
{
    int unk00;
    int unk04;
    S_0065d3e0_Pool unk08;
    char* unk0c;
    char* unk10;
    char* unk14;
    bool AllocateBuffer(unsigned n);
};
class FUN_0065d4e0_Pool
{
  public:
    unsigned int unk00;
    unsigned int Alloc(unsigned int count);
};
class FUN_0065d4e0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_0065d4e0_Pool m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    bool FUN_0065d4e0(unsigned int n);
};
struct FUN_0065d5e0_sub
{
    int m_iWordAt00;
};
struct FUN_0065d5e0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_0065d5e0_sub m_8;
    unsigned char* m_iThirdValue;
    unsigned char* m_10;
    unsigned char* m_14;
    bool AllocateEntries(unsigned int index);
};
struct Lay_d8e0_Pair
{
    int m_00;
    int m_04;
};
struct FUN_0065d8e0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    Lay_d8e0_Pair* BuildAndComparePair(Lay_d8e0_Pair* out, int a1, int a2, int a3, int a4);
};
struct D980Elem
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
};
struct D980Alloc
{
};
struct D980Vector
{
    int unk00;
    int unk04;
    D980Alloc _Alval;
    D980Elem* _Myfirst;
    D980Elem* _Mylast;
    D980Elem* _Myend;

    bool FUN_0065d980(unsigned int _Capacity);
};
struct FUN_0065dae0_target
{
    char pad_00[0x10];
    unsigned int m_10;
};
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_0065dae0_cls
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    FUN_0065dae0_cls* FUN_0065dae0();
};
struct FUN_0065e0e0_cls
{
    unsigned int FUN_0065e0e0();
};
struct S_0065e1a0
{
    int unk00;
    int unk04;
    bool FUN_0065e1a0(S_0065e1a0* other);
};
struct LengthErrorB9431
{
    virtual void v0();
    int m_iWordAt04;
    int m_8;
    LengthErrorB9431(int msg);
    ~LengthErrorB9431() throw();
};
struct S_0065e550_Err
{
    virtual void vf00();
    int unk04;
    int unk08;
    S_0065e550_Err(int code);
    ~S_0065e550_Err();
};
void* __cdecl operator new(unsigned int size);
struct LengthErrB9739
{
    virtual void v0();
    int m_iWordAt04;
    int m_8;
    LengthErrB9739(int msg);
    ~LengthErrB9739() throw();
};
struct EmptyTag
{
};
class FUN_0065f060_base
{
  public:
    ~FUN_0065f060_base();
    int unk04;
};
class FUN_0065f060 : public FUN_0065f060_base
{
  public:
    ~FUN_0065f060();
    void unk08();
};
struct Alloc_65f0c0
{
};
struct Vec_65f0c0
{
    void* unk00;
    void* _Myfirstiter;
    Alloc_65f0c0 _Alval;
    char* _Myfirst;
    char* _Mylast;
    char* _Myend;

    unsigned int size() const;
    Vec_65f0c0& FUN_0065f0c0(const Vec_65f0c0& _Right);
};
struct Pair8_b6530
{
    int lo;
    int hi;
};
struct Vec_65eed0_callees_b6530
{
};
struct C65F700Node;
struct C65F700Iterator
{
    void* m_pvContainer;
    C65F700Node* m_pkNode;

    bool operator==(const C65F700Iterator& kOther);
};
class C65F700List
{
  public:

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C65F700Node* m_pkHead;

    C65F700Iterator FUN_0065f700(void* pvFirstCont, C65F700Node* pitFirst, void* pvLastCont, C65F700Node* pitLast);
};
struct S_0065f8c0_PtrTag
{
    char v;
};
struct S_0065f8c0_ChkTag
{
    char v;
};
struct S_0065f8c0_IterTag
{
    char v;
    S_0065f8c0_IterTag()
    {}
};
extern void FUN_0065f060();
extern void FUN_0065fc10();
void FUN_00ecaebb(void* dst, void* src, unsigned int size, unsigned int count, void (*copyCtor)(),
                            void (*dtor)());
struct FUN_0065fab0_cls
{
    float m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_0065fab0_cls* FUN_0065fab0(FUN_0065fab0_cls* src);
};
struct FNVFlag7675
{
    bool v;
};
// Candidate: CallWithFlag
//   int CallWithFlag(int* p) { bool flag; return FUN_0043b1d0(p, flag); }
struct _DummyTag
{
};
struct S_0065ff90_Tag
{
};
struct S_0065ff90_Dest
{
    int* m_ptr;
    unsigned int m_iElementCount;
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_0064ec10_obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool IsCopyable();
    int value04, value08, value0c, value10;
    FUN_0064ec10_obj(const FUN_0064ec10_obj&);
};
struct CloneComponent
{
    int value00, value04, value08, value0c, value10;
};
struct LinkedList
{
    int head, tail, count;
    void* FUN_00559450();
};
struct CloneVector
{
    float x, y, z;
};
struct FUN_00649680 : NiMemObject
{
    int value00, value04, value08;
    FUN_0064ec10_obj* extra;
    CloneComponent member10, member24, member38, member4c, member60, member74;
    LinkedList list88;
    CloneComponent member94, membera8;
    LinkedList listbc;
    CloneComponent memberc8, memberdc;
    LinkedList listf0;
    CloneComponent memberfc, member110;
    CloneVector vector124;
    int value130;
    int value134;
    int value138;
    int value13c;
    int value140;
    int value144;
    int value148;
    int value14c;
    int value150;
    int value154;
    int value158;
    int value15c;
    int value160;
    int value164;
    int value168;
    int value16c;
    int value170;
    int value174;
    int value178;
    int value17c;
    int value180;
    int value184;
    unsigned char flag188;
    unsigned char flag189;
    unsigned char flag18a;
    unsigned char flag18b;
    unsigned char flag18c;
    unsigned char flag18d;
    unsigned char flag18e;
    unsigned char flag18f;
    unsigned char flag190;
    unsigned char flag191;
    unsigned char flag192;
    unsigned char flag193;
    int value194;
    int value198;
    int value19c;
    int value1a0;
    int value1a4;
    int value1a8;
    int value1ac;
    int value1b0;
    int value1b4;
    int value1b8;
    int value1bc;
    FUN_00649680();
    FUN_00649680* FUN_0064c5a0();
};
template <class T> struct FGPointer
{
    T* m_pObject;

    FGPointer(T* apObject);
    ~FGPointer();
    operator T*() const;
};
struct FGPixelFormat
{
    int unk00;
};
struct FGRGBA
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};
struct FGPixels
{
};
struct FGPixelData
{
};
struct FGSourceTexture
{
    int unk00;
};
struct FGColor
{
    float r;
    float g;
    float b;
    float a;
};
struct FGImage
{
    int unk00;
    int unk04;
    int unk08;

    FGColor* GetAt(unsigned int auiIndex);
};
struct FGOwner
{
    int unk00;
    int unk04;
    FGPointer<FGSourceTexture> m_spTexture;
    FGImage m_kImage;

    FGImage* GetOrConvertImage();
};
class Obj653;
class Handle653
{
  public:
    Handle653(int iValue);
    ~Handle653();

    Obj653* m_pPointer;
};
class Owner653
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Handle653 m_kHandle;
};
class Ref653
{
  public:
    int unk00;
    int unk04;
    Owner653* m_pkOwnerManager;

    Obj653* GetHandleObject();
};
struct FUN_00657a80 : FUN_0065d3a0
{
    FUN_00657a80();
};
// Destructor: clear the contents, then the base container is destroyed.
class E7AF0Base
{
  public:
    ~E7AF0Base();

    void* m_pResource;
    unsigned int m_uiSize;
};
class FUN_00657af0 : public E7AF0Base
{
  public:
    ~FUN_00657af0();
    void Clear();
};
void* __cdecl operator new(unsigned int uiSize);
class C658CA0BadAlloc
{
  public:
    C658CA0BadAlloc(const char* pcMessage = 0);
    virtual ~C658CA0BadAlloc();

    const char* m_pcWhat;
    int m_iDoFree;
};
struct C658CA0Element
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
};
struct Node_658d50
{
    Node_658d50* next;
    void* data;
};
struct Base_658d50
{
    virtual ~Base_658d50();
};
struct FUN_00658d50 : Base_658d50
{
    unsigned int count;
    Node_658d50** buckets;
    int unk0c;
    unsigned char flag;
    ~FUN_00658d50();
};
struct ObjectCleanupBase658e10
{
    virtual ~ObjectCleanupBase658e10();
};
struct FUN_00658e10 : ObjectCleanupBase658e10
{
    virtual ~FUN_00658e10();
};
struct FUN_00659080_Class
{
    void FUN_00659080(FUN_00659140_Class* obj);
};
struct FUN_0065c9c0 : FUN_0065d3a0
{
    FUN_0065c9c0();
};
class B65CCA0List
{
  public:
    B65CCA0List();
    B65CCA0List(const B65CCA0List& kOther);

    void* m_pvHandle;
};
class B65CCA0Base
{
  public:
    B65CCA0Base(B65CCA0List kList);
    ~B65CCA0Base();

    int unk04;
};
class FUN_0065cca0_cls : public B65CCA0Base
{
  public:
    FUN_0065cca0_cls();

};
struct FlagA
{
    bool v;
};
struct RangeCheckedTag65E
{
};
struct ScalarPtrTag65E
{
};
struct NonscalarPtrTag65E
{
    NonscalarPtrTag65E();
};
typedef int* Iter65E;
struct FUN_0044d6c0_class
{
    int unk00;
    int unk04;
    int unk08;
    void* FUN_0044d6c0(void** a);
};
// @fnv 0x00658c10
extern "C" void __cdecl FUN_00658c10(int a, int b)
{
    Hldr0044 h;

    if ((unsigned)a <= 0)
    {
        a = 0;
    }
    else
    {
        if (0xFFFFFFFFu / (unsigned)a < 60)
        {
            reinterpret_cast<::FUN_0044d6c0_class *>(&(h))->FUN_0044d6c0((void **)(0));
            FUN_00ec7894(&h, &DAT_01140ef8);
        }
    }

    ::FUN_00401000(a * 60);
}
struct B65E760Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct B65E760IterCategory
{
};
struct B65E760ScalarTag
{
};
struct B65E760CheckedTag
{
};
struct FUN_0065ee70 : FUN_0065cfb0
{
    ~FUN_0065ee70();
};
// Copy-style range helper: unwrap both iterators and forward them with the iterator-category and range tags.
struct EA0RangeTag
{
};
struct EA0CategoryTag
{
};
struct FUN_00657b50 : FUN_0065d3a0
{
    FUN_00657b50();
};
namespace c820 {
struct RCTag
{
};
struct InTag
{
};
struct FwdTag : InTag
{
};
struct BiTag : FwdTag
{
};
struct RaTag : BiTag
{
};
struct PtrCat
{
};
typedef Elem_65eed0* It;
}
Elem_65eed0* __cdecl FUN_0065f820(Elem_65eed0* first, Elem_65eed0* last, Elem_65eed0* dest);
namespace de {
struct RCTag
{
};
struct PtrCat
{
};
PtrCat __cdecl FUN_0065e750(int& a, int& b);
}
// @fnv 0x0065fde0
extern "C" void __cdecl FUN_0065fde0(int first, int last, int dest, int al)
{
    using namespace de;
    ::CopyRange(CallWithFlag(&first), CallWithFlag(&last), dest, (::FUN_00660070_cls *)(al));
}
struct TagA
{
    char v;
};
// @fnv 0x0064e380
extern "C" int __cdecl FUN_0064e380(int arg1, int arg2, int arg3)
{
    TagA flag1 = {};
    char flag2 = ((char)(::FUN_0065e750(&arg1, &arg3)));
    TagA flag3;

    return ::FUN_0064e5a0(CallWithFlag(&arg1), CallWithFlag(&arg2), arg3);
}
struct Tag
{
};
struct Elem64e9
{
    char m_data[0x10];
};
struct Alloc64e9
{
    void FUN_0065e9a0(Elem64e9* pElem);
};
struct NonscalarTag64e9
{
};
struct CheckedTag64e9
{
};
class BSFaceGenModelExtraData : public NiMemObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BSFaceGenModelExtraData(int);
};
class NiRefObject
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class NiExtraData;
class NiObject : public NiRefObject
{
  public:
    virtual ~NiObject();
};
class NiObjectNET : public NiObject
{
  public:
};
class NiGeometryData : public NiObject
{
  public:
};
class NiGeometry : public NiObjectNET
{
  public:
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
    virtual void ReplaceModelData(NiGeometryData* pData);
};
class NiSkinPartition : public NiObject
{
  public:
};
class NiSkinInstance
{
  public:
};
class NiTriBasedGeom : public NiGeometry
{
  public:
};
class FUN_006624c0 : public NiMemObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_006624c0(NiTriBasedGeom* pGeom, int a2, int a3);
};
struct FaceGenModelData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    NiPointer<NiGeometry> spGeom;
    int unk14;
    int unk18;
};
class BSFaceGenModel
{
  public:
    int unk00;
    int unk04;
    FaceGenModelData* unk08;

    bool CloneTriBasedGeom(NiPointer<NiTriBasedGeom>& out);
};
struct VecItem1C
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18;
};
struct VecItemAllocator
{
    unsigned int m_00;
};
struct VecItemVector
{
    unsigned int m_00;
    unsigned int m_04;
    VecItemAllocator _Alval;
    VecItem1C* _Myfirst;
    VecItem1C* _Mylast;
    VecItem1C* _Myend;

    bool FUN_0065d7e0(unsigned int _Capacity);
};
struct S_0065fb10_Elem
{
    short a;
    short b;
    short c;
};
struct S_0065fb10_Alloc
{
    S_0065fb10_Alloc(const S_0065fb10_Alloc&);
};
struct S_0065fb10_Iter
{
    S_0065fb10_Elem* ptr;
    void* cont;
};
struct S_0065fb10_Base
{
    int unk00;
    int unk04;
    S_0065fb10_Alloc _Alval;
    S_0065fb10_Elem* _Myfirst;
    S_0065fb10_Elem* _Mylast;
    S_0065fb10_Elem* _Myend;
    S_0065fb10_Base(S_0065fb10_Alloc al);
    ~S_0065fb10_Base();
};
struct FUN_0065fb10 : S_0065fb10_Base
{
    FUN_0065fb10(const FUN_0065fb10& other);
};
struct Base64ce20
{
    virtual void Slot00();
    unsigned int unk04;
    ~Base64ce20();
};
struct ObjectPointer64ce20
{
    void* m_object;
    ObjectPointer64ce20& operator=(void* object);
    ~ObjectPointer64ce20();
};
struct Vector64ce20
{
    void* m_pHeadNode;
    void* m_last;
    void* m_kRayEnd;
    ~Vector64ce20();
};
struct FUN_0064ce20 : Base64ce20
{
    ObjectPointer64ce20 m_object;
    Vector64ce20 m_iSlotIds;
    ~FUN_0064ce20();
};
struct ItE4E0
{
    int* m_ptr;
};
struct RangeTagE4E0
{
};
struct CatTagE4E0
{
};
struct PtrCatE4E0
{
    PtrCatE4E0()
    {}
};
struct Allocator65C750
{
    Allocator65C750();
    Allocator65C750(const Allocator65C750& kOther);
    int unk00;
};
struct Base65C750
{
    Base65C750(Allocator65C750 kAllocator);
    ~Base65C750();
    int unk00;
};
struct FUN_0065c750 : public Base65C750
{
    FUN_0065c750();
    void Init(int iCount);
};
struct ItQ
{
    int* p;
    int c;
};
struct FUN_0065fc10 : FUN_0065d3a0
{
    int unk00;
    int unk04;
    int m_al;
    int* m_pHeadNode;
    int* m_last;
    int* m_kRayEnd;
    FUN_0065fc10(FUN_0065fc10& r);
};
class FloatSource
{
  public:
};
struct FloatGetterGlobal
{
};
extern FloatGetterGlobal DAT_011cfb5c, DAT_011cf264;
namespace ctor_0065c8f0 {

struct FUN_006815c0
{
    FUN_006815c0();
    FUN_006815c0(const FUN_006815c0& other);
};

struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 al) throw();
    ~FUN_0065d3a0();
};

struct FUN_0065c8f0 : FUN_0065d3a0
{
    FUN_0065c8f0();
};

// @fnv 0x0065c8f0
FUN_0065c8f0::FUN_0065c8f0() : FUN_0065d3a0(FUN_006815c0())
{
    reinterpret_cast<::FUN_0065d2b0_cls *>(this)->FUN_0065d2b0(0);
}

}
namespace ctor_0065d3a0 {

struct FUN_0065de30
{
    FUN_0065de30(const FUN_0065de30& other);
};

struct RebindAllocator
{
    RebindAllocator(const FUN_0065de30& other);
    ~RebindAllocator();
};

struct FUN_0065dc90
{
    int unk00;
    int unk04;
    FUN_0065dc90(RebindAllocator al) throw();
};

struct FUN_0065d3a0 : FUN_0065dc90
{
    FUN_0065de30 alval;
    FUN_0065d3a0(FUN_0065de30 al) throw();
};

// @fnv 0x0065d3a0
FUN_0065d3a0::FUN_0065d3a0(FUN_0065de30 al) throw() : FUN_0065dc90(al), alval(al)
{}

}
struct Elem6_f380
{
    short a, b, c;
};
struct Alloc_f380
{
};
struct VecF380
{
    int unk00;
    int unk04;
    Alloc_f380 _Alval;
    Elem6_f380* _Myfirst;
    Elem6_f380* _Mylast;
    Elem6_f380* _Myend;
    bool FUN_0065f380(unsigned int _Capacity);
};
#include <math.h>
template <class Collection> class SettingT
{
  public:
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting93;
struct FUN_006443d0 : GlobalObject_00869f00
{
    virtual ~FUN_006443d0();
};
struct BGSLoadGameBuffer;
struct Interface
{
};
struct FUN_0065e9a0_Class
{
    void FUN_0065e9a0(BGSLoadGameBuffer* p);
};
struct FUN_0065ea00_Class
{
    void FUN_0065ea00(void* a);
};

void* __cdecl operator new(unsigned int size, unsigned int allocation);
void __cdecl operator delete(void* object, unsigned int allocation);

// @fnv 0x0065dc90
FUN_0065dc90::FUN_0065dc90(FUN_0065de30 argument) : FUN_006815c0(), member(argument)
{
    object = new (member.FUN_0044abd0(1)) FUN_008c71b0(this);
}
