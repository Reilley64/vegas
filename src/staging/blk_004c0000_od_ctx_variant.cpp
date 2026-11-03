// staging/blk_004c0000_od_ctx_variant.cpp: ObjectTree (2 functions)

#include <windows.h>
// blk_004c0000_od_ctx_variant.cpp: context variant of src/staging/blk_004c0000_od.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/staging/blk_004c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/C52520Camera.h"
#include "fnv/decl/C8AAHost.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_0045d240_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00476be0_Class.h"
#include "fnv/decl/FUN_004de420.h"
#include "fnv/decl/FUN_0062e150_cls.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00b631d0_cls.h"
#include "fnv/decl/GlobalObject_0045cf30.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LockCtx.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Main.h"
#include "fnv/decl/NiAVObject_004b5b00.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00495d00__FUN_00495d00_shell.h"
#include "fnv/decl/fnv_00495d20__FUN_00495d20_shell.h"
#include "fnv/decl/fnv_004d80b0__FUN_004d80b0_Class.h"
#include "fnv/decl/fnv_004d8a40__TreeCtrl4d8a.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00a640b0__NiStreamLoadStandIn.h"
#include "fnv/decl/fnv_00c5ac00__ArrObj.h"
#include "fnv/decl/fnv_00e73eb0__DX9RendererE73E.h"
#include "fnv/decl/fnv_00ec25e0__FUN_00ec25e0_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004bc000.h"
#include "fnv/symbols_004d5000.h"
#include "fnv/symbols_004d6000.h"
#include "fnv/symbols_004d7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004dd000.h"
#include "fnv/symbols_004de000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_00a62000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00fdf000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_0126f000.h"
#include "../../include/layout_support.h"
struct FUN_004dfdd0_StandIn
{
    float m_f0;
    float m_f4;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    void InitIdentity();
};
struct FUN_004d4e10_StandIn
{
    void FUN_004d4eb0();
    void* DestroyIfFlagged(unsigned int flags);
};
void __cdecl ClearGlobalArray();
struct FUN_004d5d40_Class
{
    void __thiscall FUN_004d5d40();
};
extern void(__stdcall* DAT_00fdf28c)(void*, int, int, int);
struct FUN_004d7490_Class
{
    void FUN_004d7490();
};
struct ArrSI
{
};
struct FUN_004d7d50_StandIn
{
    unsigned int __thiscall FUN_004d7d50();
};
struct FUN_004d8510_StandIn
{
    void FUN_004d8510();
};
struct TESObjectREFR;
struct bhkShape;
void* GetLocalSubValue(TESObjectREFR* p, int a);
struct FUN_004d85a0_Class
{
    void* GetLocalSubValue(int a);
    void* FUN_004d85a0(int a);
};
struct FUN_004d8670_Class
{
    BSSimpleList<int>* GetListNext();
};
struct FUN_004d8a00_Class
{
    unsigned short GetField3C();
};
struct FUN_004d8a20_Class
{
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fC;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1C;
    int m_f20;
    int m_f24;
    int m_f28;
    int m_f2C;
    int m_f30;
    int m_f34;
    int* m_p38;
    int GetEntry(unsigned short index);
};
extern int DAT_01020fe4;
struct FUN_004d8fa0_StandIn
{
    int m_p;
    FUN_004d8fa0_StandIn* FUN_004d8fa0(int a);
};
struct FUN_004d9190_Class
{
    void __thiscall FUN_004d9190();
};
struct FUN_004dc020_Class
{
    unsigned int m_p288;
    unsigned int FUN_004dc020();
};
struct FUN_004dc1c0_Class
{
    int m_i0;
    int m_i4;
    char HasNonZeroValue();
};
struct Arr
{
    unsigned int GetSize();
};
struct FUN_004dcce0_Class
{
    void FUN_004dcce0();
};
struct FUN_004dcd60_Class
{
    unsigned char GetByteAt140();
};
struct FUN_004dd220_Class
{
    unsigned int GetField5C8();
};
void* __stdcall FUN_004dd240(unsigned int size);
void __stdcall ClearAndFreePointer(void*);
int __cdecl FUN_004dd2a0(void* p);
struct FUN_004de290_StandIn
{
    float m_f0;
    float m_f4;
    FUN_004de290_StandIn* SetValue(float);
};
struct FUN_004de2b0_StandIn
{
    FUN_004de2b0_StandIn* __thiscall SetCharAtOffset4(char c);
};
extern unsigned char DAT_011c77e9;
extern float DAT_011c77ec;
struct GlobalObject_004aff00
{
};
struct FUN_004def90_Class
{
    void FUN_004def90();
};
struct GO
{
    GO& operator=(void*);
};
struct FUN_004dfe80_Class
{
    GO m_p[12];
    void SetSlotValue(int index, void* value);
};
struct MersenneTwister
{
};
struct FUN_004dfec0_StandIn
{
};
struct FUN_004d4f10_StandIn : public NiTPointerMap<int, int>
{
    void FUN_004d4f10();
};
extern int DAT_01021004;
struct FUN_004d90d0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void FUN_004d90d0();
};
struct FUN_004d8fd0_Class
{
    void __thiscall FUN_004d9070();
    void* __thiscall Destroy(unsigned int flags);
};
struct FUN_004d9160_Class : public FUN_004d9190_Class
{
    void* FUN_004d9160(unsigned int flags);
};
extern int DAT_01020924;
struct FUN_004d4e40_Holder
{
};
struct FUN_004d4de0_Class
{
    void* __thiscall FUN_004d4de0(unsigned int);
};
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
extern int DAT_01020944;
struct FUN_004d4e40_Class
{
    void* m_pVT;
    unsigned int m_uiSize;
    void* m_pData;
    unsigned int m_uiCount;
    FUN_004d4e40_Class(unsigned int size);
};
struct FUN_004d4f40_StandIn
{
    void* __thiscall FUN_004d4f40(unsigned int flags);
};
struct FUN_004d5c20_Base
{
    virtual int __thiscall FUN_000(int);
};
struct FUN_004d5c20_StandIn
{
    FUN_004d5c20_Base* m_p0;
    void __thiscall FUN_004d5c20();
};
struct FUN_004d5dd0_Class
{
    void* __thiscall FUN_004d5dd0(unsigned int);
};
extern void*(__stdcall* DAT_00fdf020)(void*, int, int, int, int, int, int);
struct FUN_004d6490_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pC;
    void* m_p10;
    void* m_p14;
    void __thiscall FUN_004d6490();
};
extern void(__stdcall* DAT_00fdf290)(void*);
struct FUN_004d7440_Class
{
    char _0[8];
    void* p8;
    void* pC;
    void __thiscall FUN_004d7440();
};
int __cdecl FUN_004d7890(int a, int b, int c, int d);
struct FUN_004d8530_Class
{
    virtual void const* f00();
    virtual void const* f01();
    virtual void const* f02();
    virtual void const* f03();
    virtual void const* f04();
    virtual void const* f05();
    virtual void const* f06();
    virtual void const* f07();
    virtual void const* f08();
    virtual void const* f09();
    virtual void const* f10();
    virtual void const* f11();
    virtual void const* f12();
    virtual void const* f13();
    virtual void const* f14();
    virtual void const* f15();
    virtual void const* f16();
    virtual void const* f17();
    virtual void const* f18();
    virtual void const* f19();
    virtual void const* f20();
    virtual void const* f21();
    virtual void const* f22();
    virtual void const* f23();
    virtual void const* f24();
    virtual void const* f25();
    virtual void const* f26();
    virtual void const* f27();
    virtual void const* f28();
    virtual void const* f29();
    virtual void const* f30();
    virtual void const* f31();
    virtual void const* f32();
    virtual void const* f33();
    virtual void const* f34();
    virtual void const* f35();
    virtual void const* f36();
    virtual void const* f37();
    virtual void const* f38();
    virtual void const* f39();
    virtual void const* f40();
    virtual void const* f41();
    virtual void const* f42();
    virtual void const* f43();
    virtual void const* f44();
    virtual void const* f45();
    virtual void const* f46();
    virtual void const* f47();
    virtual void const* f48();
    virtual void const* f49();
    virtual void const* f50();
    virtual void const* f51();
    virtual void const* f52();
    void* __thiscall FUN_004d8530();
};
struct FUN_004d8560_Inner
{
    virtual void f0();
    virtual void* f1();
};
struct FUN_004d8560_Outer
{
    char _0[0x10];
    FUN_004d8560_Inner _10;
};
struct ScriptLocalsX
{
};
struct FUN_004d8560_StandIn
{
    void* __thiscall GetInnerVirtualResult();
};
void* __cdecl memset(void* dest, int value, unsigned int count);
struct FUN_004d8fa0_Class
{
    int* m_p0;
    unsigned int m_i4;
    void* m_p8;
    unsigned int m_iC;
    FUN_004d8fa0_Class* FUN_004d9000(unsigned int size);
};
struct FUN_004d9130_Class
{
    void* __thiscall FUN_004d9130(unsigned int flags);
};
struct FUN_004d91e0_Class : public FUN_004d9190_Class
{
    void* __thiscall FUN_004d91e0(unsigned int flags);
};
struct FUN_004d9380_Class
{
    char m_p0;
    void* m_p4;
    void __thiscall FreeAndClear();
};
struct TgtOps
{
};
struct FUN_004dc120_StandIn
{
    void* __thiscall FUN_004dc120(int a);
};
struct FUN_004dc160_StandIn
{
    unsigned int FUN_004dc160(int a);
};
struct GlobalObject_004a4a40
{
};
struct CellStand
{
};
struct GlobalObject_0045cfe0
{
    CellStand m_cell;
};
extern float DAT_011ad83c;
struct Flt
{
    operator unsigned int();
};
struct Date
{
    ~Date();
};
struct NiNode;
struct S0042fa20
{
    S0042fa20* FUN_0045ce80(int);
};
struct FUN_004dcd30_Class
{
    unsigned char __thiscall FUN_004dcd30(int p);
};
struct G7d1
{
};
G7d1 g_011c726c;
struct MyArr_GetAt
{
    unsigned int* GetAt(int);
};
struct FUN_004dcdf0_Class
{
    int _0;
    union
    {
        Arr a;
        MyArr_GetAt m;
    } _4;
    unsigned int __thiscall FUN_004dcdf0(unsigned int index);
};
__pragma(comment(linker, "/alternatename:?GetAt@MyArr_GetAt@@QAEPAIH@Z=?GetAt@Arr@@QAEPAIH@Z"))
// @fnv 0x004dcdf0
    unsigned int __thiscall FUN_004dcdf0_Class::FUN_004dcdf0(unsigned int index)
{
    if (index < reinterpret_cast<::FUN_00658930_class *>(&(_4.a))->GetShortAtOffsetA())
        return *(_4.m.GetAt((int)index));
    return 0;
}
void __stdcall ClearAndFreePointer(void* p);
struct FUN_004de550_StandIn
{
    void* __thiscall FUN_004de550(unsigned int);
};
struct NiTexture;
struct SkyTextureManager
{
};
bool __cdecl FUN_004deed0(char const* a, unsigned char b);
struct FUN_004d4f70
{
    unsigned int m_uiCount;
    int m_iParam;
    float** m_ppfA;
    float** m_ppfB;

    FUN_004d4f70(unsigned int ItemUpdateArray, int iParam);
};
struct FUN_004d5080_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;

    void __thiscall FUN_004d5080();
};
struct GlobalObject_0044f440
{
};
struct Buf
{
    unsigned int m0;
    unsigned int m4;
    float** p8;
    float** pC;
    Buf(unsigned int a, unsigned int b);
    ~Buf();
};
extern double DAT_010209a8;
struct FUN_004d5a90_Class
{
    int m_i0;
    int m_i4;
    float GetNegativeMagnitude();
};
extern const char DAT_01020d58[];
struct FUN_0040c150
{
    int value0;
    int value4;
    int value8;
    FUN_0040c150(char* text, int index);
};
struct FUN_004d5b60
{
    FUN_0040c150* object;
    int value;
    FUN_004d5b60(int index, int number, int extra);
};
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
void __cdecl ClearGlobalArray(void);
int __cdecl FUN_004d5e00();
struct FUN_004d9070
{
    ~FUN_004d9070();
};
struct FUN_004d62a0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    FUN_004d9070 m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    void* m_p2C;

    ~FUN_004d62a0_Class();
};
struct InitCommonControls4d63
{
    unsigned long m_ulSize;
    unsigned long m_ulICC;
};
struct Rect4d63
{
    long left;
    long top;
    long right;
    long bottom;
};
struct WndClass4d63
{
    unsigned int style;
    long(__stdcall* lpfnWndProc)(void*, unsigned int, unsigned int, long);
    int cbClsExtra;
    int cbWndExtra;
    void* hInstance;
    void* hIcon;
    void* hCursor;
    void* hbrBackground;
    const char* lpszMenuName;
    const char* lpszClassName;
};
extern int(__stdcall* DAT_00fdf024)(InitCommonControls4d63*);
extern void*(__stdcall* DAT_00fdf280)(void*, const char*);
extern void*(__stdcall* DAT_00fdf2a0)(void*, const char*);
extern void*(__stdcall* DAT_00fdf03c)(int);
extern unsigned short(__stdcall* DAT_00fdf2b4)(const WndClass4d63*);
extern void*(__stdcall* DAT_00fdf2b8)(unsigned long, const char*, const char*, unsigned long, int, int, int, int, void*,
                                      void*, void*, void*);
extern int(__stdcall* DAT_00fdf2bc)(void*, Rect4d63*);
extern char DAT_01189338[];
struct TreeCtrl4d63
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    int unk10[7];
    const char* m_pcTitle;
    void CreateTreeWindows(int iX, int iY, int iWidth, int iHeight);
};
struct ClearMap64
{
    int unk00;
};
typedef int(__stdcall* SendMessageResult64)(void*, int, int, int);
extern void(__stdcall* DAT_00fdf288)(void*, int);
struct Header64
{
    int primary, secondary, tertiary, unused0c, unused10, unused14;
};
struct Params64
{
    const char* message;
    int unused04;
    int flags;
    int flagsCopy;
    int unused10;
    int number;
    int status18;
    int context1c;
    int callback20;
    int source24;
};
struct Owner64
{
    void* unk00;
    void* unk04;
    void* window;
    void* dialog;
    int result;
    int hwndContext;
    ClearMap64 messageMap;
    int unk1c, unk20, unk24, unk28;
    const char* defaultText;
    void __thiscall FUN_004d64c0(int value, const char* text);
};
extern void(__stdcall* DAT_00fdf01c)(void*);
struct FUN_004d7470_StandIn
{
    char _0[20];
    void* p14;
    void __thiscall FUN_004d7470();
};
typedef int(__stdcall* SendTreeMessage)(void*, int, int, int);
struct FUN_004d74c0_Value
{
};
struct FUN_004d74c0_Node
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual FUN_004d74c0_Value* getValue();
};
struct FUN_004d74c0_Item
{
    unsigned int mask;
    int handle;
    int state;
    int stateMask;
    char* text;
    int textCapacity;
    int image;
    int selectedImage;
    int children;
    FUN_004d74c0_Node* itemData;
    int integral;
    int stateEx;
    void* hwnd;
    int expandedImage;
};
int FUN_00406d50(char* pcDest, unsigned int uiSize, const char* pcSrc);
class NiObject
{
  public:
    int m_aiObject[2];
};
class NiFixedString
{
  public:
    operator const char*() const;
    const char* m_kHandle;
};
struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int m_pkUpdateProcess;
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);
};
struct NiPoint3;
class NiAVObject : public NiObject
{
  public:
    NiFixedString& GetName();
public:
    ::NiPoint3 &FUN_0043c490();
};
class NiStream
{
  public:
    NiStream();
    ~NiStream();
    void InsertObject(NiObject* pkObject);
    int m_kNextStreamField[0x172];
};
struct NiObject;
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
class BGSAddonNode;
struct Holder_004d9100 : public NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >
{
    Holder_004d9100(int a, int b);
};
struct NiTArray_Layout;
class ActorPathingMessageQueue;
struct Name
{
};
struct ItemClass
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual Name& GetName();
    virtual void vfn_0c();
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
    virtual void FillHolders(Holder_004d9100* holder);
};
struct MsgStruct
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const char* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
struct ObjClass : public FUN_004d7d50_StandIn
{
};
typedef int(__stdcall* DAT_00fdf28c_fn)(void*, int, int, void*);
struct HostClass
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0C;
    void __thiscall SendModifierMessages(int a1, NiObject* a2);
};
extern "C" char DAT_01020ebc;
struct Node7
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
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
    virtual void v24(void*);
};
struct FUN_004d9100
{
    FUN_004d9100(int, int);
    virtual ~FUN_004d9100();
    char pad[12];
    char** FUN_00877a30(unsigned);
};
struct Insert7
{
    void* parent;
    unsigned after, mask;
    unsigned item, state, stateMask;
    const char* text;
    int max, image, selected, children;
    Node7* param;
    int extra[4];
};
struct C7
{
    char pad[12];
    void* hwnd;
    void AddChildTreeItem(void* parent, Node7* node);
};
struct FUN_0062e150_Obj
{
};
struct FUN_004d8610_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0062e150_Obj sub18;
    int GetSubValue(int arg);
};
struct TreeItem4d86
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};
struct TreeInsert4d86
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d86 item;
};
typedef void*(__stdcall* SendMessage4d86)(void*, int, int, int);
struct MediaSet4d86
{
};
struct Palette4d86;
struct Object4d86
{
};
struct TreeCtrl4d86
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void PopulateObjectTree(void* hParent, Object4d86* pkObject);
};
struct TreeItem4d88
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};
struct TreeInsert4d88
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d88 item;
};
typedef void*(__stdcall* SendMessage4d88)(void*, int, int, int);
extern const char DAT_01020f14[];
struct Target4d88
{
};
struct Interp4d88;
struct BlendInterp4d88
{
};
struct TreeCtrl4d88
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void AddBlendInterpTreeItems(void* hParent, BlendInterp4d88* pkBlend);
};
struct FUN_004d9210
{
    virtual ~FUN_004d9210();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    FUN_004d9210(unsigned short capacity, unsigned short growBy);
};
class DepthDevice;
char* DAT_01202fa0;
extern int DAT_011c70d4;
extern int DAT_011c70d8;
extern int DAT_01189464;
extern int DAT_011c70d0;
extern int DAT_01189470;
extern int DAT_01189474;
extern float DAT_01189490;
struct DisplayDevice4de1
{
    unsigned long cb;
    char DeviceName[32];
    char DeviceString[128];
    unsigned long StateFlags;
    char DeviceID[128];
    char DeviceKey[128];
};
struct EyefinityInfo4de1
{
    int iSLSActive;
    int iSLSGridWidth;
    int iSLSGridHeight;
    int iSLSWidth;
    int iSLSHeight;
    int iPadding;
};
struct DisplayInfo4de1
{
    int iGridXCoord;
    int iGridYCoord;
    int iRectLeft;
    int iRectTop;
    int iRectRight;
    int iRectBottom;
};
extern int(__stdcall* DAT_00fdf2f0)(const char*, unsigned long, DisplayDevice4de1*, unsigned long);
int __cdecl FUN_00ec9d4a(const char* pcFormat, ...);
extern bool DAT_01189484;
extern float DAT_01189488;
extern float DAT_01189490;
extern "C" float DAT_01189494;
extern float DAT_01189498;
extern bool DAT_011c70ed;
extern bool DAT_011c70ee;
extern bool DAT_011c70ef;
extern float DAT_011c70f0;
struct FUN_004de2d0_StandIn : FUN_004de2b0_StandIn
{
    FUN_004de2b0_StandIn* __thiscall FUN_004de2d0(char c);
};
struct FUN_004de3f0_Class
{
    void* __thiscall FUN_004de3f0(int flags);
};
struct INISettingCollection
{
    INISettingCollection();
    virtual void v0();
};
struct FUN_004de530 : public INISettingCollection
{
    FUN_004de530();
};
struct FUN_00559450_Helper
{
};
struct FUN_0066b0d0_Helper
{
    void FUN_0066b0d0(int);
};
void* __cdecl operator new(unsigned int uiSize);
void __cdecl operator delete(void* pvMem);
class C4DF040Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};
class C4DF040Point3
{
  public:
    C4DF040Point3();
    C4DF040Point3(float fX, float fY, float fZ);

    C4DF040Point3 operator+(const C4DF040Point3& kPt) const;

    float x;
    float y;
    float z;
};
class C4DF040Point2
{
  public:
    C4DF040Point2();
    C4DF040Point2(float fX, float fY);

    C4DF040Point2 operator+(const C4DF040Point2& kPt) const;

    float x;
    float y;
};
class C4DF040Matrix3
{
  public:
    C4DF040Matrix3();

    C4DF040Point3 operator*(const C4DF040Point3& kPt) const;

    float m_afEntries[3][3];
};
class C4DF040Texture;
class C4DF040TexturePtr
{
  public:

    C4DF040Texture* m_pPointer;
};
class C4DF040Property : public C4DF040Object
{
  public:
    C4DF040Property();


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
};
class C4DF040TriShape : public C4DF040Object
{
  public:
    C4DF040TriShape(unsigned short usVertices, C4DF040Point3* pkVertex, C4DF040Point3* pkNormal, void* pkColor,
                    C4DF040Point2* pkTexture, unsigned short usNumTextureSets, unsigned int eNBTMethod,
                    unsigned short usTriangles, unsigned short* pusTriList);


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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
};
class C4DF040Node : public C4DF040Object
{
  public:
    C4DF040Node(unsigned int uiMode);

    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void AttachChildInAvailableSlot(C4DF040TriShape* pkChild, bool abFirstAvailableSlot);

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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
};
class C4DF040FloatSetting
{
  public:
};
struct FUN_004dfec0_Class
{
    float FUN_004dfec0();
};
class FUN_004d4f10
{
  public:
    virtual ~FUN_004d4f10();

};
class FUN_004d4eb0 : public FUN_004d4f10
{
  public:
    virtual ~FUN_004d4eb0();
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
};
struct SavedSettingValue
{
    unsigned int unk00;
    unsigned int value;
};
class ListT
{
  public:
};
class Owner
{
  public:
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
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    ListT kList;
    void* GetByIndex(unsigned int idx);
};
struct NiTMallocInterface_004d91b0
{
};
struct FUN_004d91b0_Class
{
    virtual void v00();
    void* pData;
    ~FUN_004d91b0_Class();
};
struct DoorTeleportLoadData
{
    unsigned int unk00;
    float positionX, positionY, positionZ;
    float rotationX, rotationY, rotationZ;
    DoorTeleportLoadData();
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
struct DoorTeleportArray
{
    unsigned char count;
    DoorTeleportLoadData* entries;
    void FUN_004da3f0();
};
extern int DAT_011c70e0;
extern int DAT_011c70e4;
struct OutT
{
    int x;
    int y;
};
extern int(__stdcall* DAT_00fdf2ec)(int, int);
extern int(__stdcall* DAT_00fdf2e8)(unsigned int, int);
extern int(__stdcall* DAT_00fdf310)(OutT*, int, int);
extern int(__stdcall* DAT_00fdf2a4)(unsigned int, int, int);
class NiAVObject;
struct FUN_004dc540_shell
{
    void FUN_004dc540(NiAVObject*);
};
class BGSMoviePlayer
{
  public:
};
class BSAudio
{
  public:
};
struct FUN_00b7b930_Ctx
{
};
struct GO45
{
};
struct S45a
{
};
struct S45b
{
};
class GlobalObject_00633c90
{
  public:
};
struct FUN_00558310_node
{
};
class E73shell
{
  public:
};
class Interface
{
  public:
    static void Init(bool);
public:
    static void RefreshInterfaceState();
};
void FUN_00b578a0();
extern bool DAT_011c70ed;
extern float DAT_01189498;
float __cdecl FUN_004de0f0();
struct FUN_004dfe30_Class
{
    float x;
    float y;

    FUN_004dfe30_Class();
    FUN_004dfe30_Class __thiscall FUN_004dfe30(const FUN_004dfe30_Class& kPt) const;
};
struct FUN_004d8610_StandIn
{
};

namespace fnv_004d66d0 {
struct NiPoint3
{
  public:
    float x, y, z;
};
class NiFixedString
{
  public:
    const char* text;
};
class NiRTTI : public BSStringT<char>
{
};
class ViewerStrings
{
  public:
    virtual ~ViewerStrings();
    const char** strings;
    unsigned short capacity, size, used, growBy;
    ViewerStrings(int initialSize, int growSize);
    unsigned int GetSize();
    const char*& GetAt(unsigned int index);
};
class NiTimeController;
class NiTriBasedGeom;
class NiObject
{
  public:
    virtual ~NiObject();
    virtual void Unk01();
    virtual NiRTTI* GetRTTI();
    virtual NiNode* IsSceneNode();
    virtual void Unk04();
    virtual void Unk05();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void GetViewerStrings(ViewerStrings* strings);
};
class NiObjectNET : public NiObject
{
  public:
};
class NiTimeController : public NiObject
{
  public:
};
class PropertyValue
{
  public:
};
class PropertyList
{
  public:
};
class NiAVObject : public NiObjectNET
{
  public:
    NiFixedString& GetName();
};
class NiNode : public NiAVObject
{
  public:
    unsigned int FUN_0043b480();
};
class NiTriBasedGeom
{
  public:
};
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
struct TreeItemFields
{
    unsigned int mask;
    void* handle;
    unsigned int state;
    unsigned int stateMask;
    const char* text;
    int textMax;
    int image;
    int selectedImage;
    int children;
    NiAVObject* data;
    int integral;
    unsigned int stateEx;
    HWND window;
    int expandedImage;
};
struct TreeInsert
{
    void* parent;
    void* insertAfter;
    union
    {
        TreeItemFields item;
        TreeItemFields itemex;
    };
};
class ObjectTree
{
  public:
    void* field00;
    void* field04;
    void* field08;
    HWND tree;
    void* field10;
    void* field14;
    NiTPointerMap<unsigned int, unsigned int> entries;
    void FUN_004d66d0(void* parent, NiAVObject* object);
};
// @fnv 0x004d66d0
void ObjectTree::FUN_004d66d0(void* parent, NiAVObject* object)
{
    // The controller chain and extra-data object outlive the tree-building scopes.
    NiObject* insertion;
    unsigned int i;
    NiTimeController* extra;
    {
        char scale[260];
        {
            bool hasPropertyControllers;
            {
                ViewerStrings* strings;
                {
                    char label[260];
                    {
                        TreeInsert treeItem;

                        treeItem.insertAfter = reinterpret_cast<void*>(0xffff0002);
                        treeItem.item.mask = 0x27;
                        treeItem.parent = parent;
                        treeItem.item.data = object;
                        ::FUN_00406d00(label, 260, "%s \"%s\" (%.0f,%.0f,%.0f)", ((const char *)(::FUN_00559450((int *)(object->GetRTTI())))),
                                  (*(::fnv_004d66d0::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((object))->GetLinkToList())).text, (*(::fnv_004d66d0::NiPoint3 *)&(reinterpret_cast<::NiAVObject *>((object))->FUN_0043c490())).x, (*(::fnv_004d66d0::NiPoint3 *)&(reinterpret_cast<::NiAVObject *>((object))->FUN_0043c490())).y,
                                  (*(::fnv_004d66d0::NiPoint3 *)&(reinterpret_cast<::NiAVObject *>((object))->FUN_0043c490())).z);
                        if (reinterpret_cast<::FUN_009cdae0_shell *>((object))->GetFloatAt64() != 1.0)
                        {
                            ::FUN_00406d00(scale, 260, " Scale %.1f", reinterpret_cast<::FUN_009cdae0_shell *>((object))->GetFloatAt64());
                            FUN_00406d50(label, 260, scale);
                        }
                        if (reinterpret_cast<::FUN_00456630_helper *>((object))->FUN_00456610())
                            FUN_00406d50(label, 260, " Culled");
                        treeItem.item.text = ((const char *)(::FUN_00464f30((int)(label))));
                        if (object->IsSceneNode())
                            treeItem.item.image = 3;
                        else if (::FUN_0043b300((const ::NiRTTI *)(const ::fnv_004d66d0::NiRTTI *)(&(*reinterpret_cast<::fnv_004d66d0::NiRTTI *>(&::g_011f4a18))), (::NiAVObject *)(object)))
                            treeItem.item.image = 1;
                        else if (::FUN_0043b300((const ::NiRTTI *)(const ::fnv_004d66d0::NiRTTI *)(&(*reinterpret_cast<::fnv_004d66d0::NiRTTI *>(&::g_011f4a28))), (::NiAVObject *)(object)))
                            treeItem.item.image = 2;
                        else
                            treeItem.item.image = 4;
                        treeItem.item.selectedImage = treeItem.item.image;
                        treeItem.parent = (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                        treeItem.item.data = 0;
                        reinterpret_cast<::FUN_00844700_Class *>(&(entries))->FUN_00844700((unsigned int)object, (unsigned int)treeItem.parent);
                        treeItem.item.text = ((const char *)(::FUN_00464f30((int)("Attributes"))));
                        treeItem.item.image = 5;
                        treeItem.item.selectedImage = treeItem.item.image;
                        parent = treeItem.parent;
                        treeItem.parent = (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                        strings = new ViewerStrings(128, 128);
                        object->GetViewerStrings(strings);
                        for (i = 0; i < reinterpret_cast<::FUN_00658930_class *>((strings))->GetShortAtOffsetA(); i++)
                        {
                            treeItem.item.text = ((const char *)(::FUN_00464f30((int)(strings->GetAt(i)))));
                            treeItem.item.image = 6;
                            treeItem.item.selectedImage = treeItem.item.image;
                            SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                        }
                        ::FUN_005e03d0((::NiTArray_Layout *)(strings));
                        hasPropertyControllers = false;
                        if (!reinterpret_cast<::FUN_0076b610_Class *>((void *)&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))->FUN_0076b610())
                        {
                            void* position = ((void *)(::FUN_00559450((int *)&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))));
                            while (position)
                            {
                                NiObjectNET* property = ((::fnv_004d66d0::NiObjectNET *)(::FUN_00559450((int *)&((*(::fnv_004d66d0::PropertyValue *)(reinterpret_cast<::ListStandIn *>(&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))->FUN_0057cbe0((int **)&(position))))))));
                                NiTimeController* propertyController = ((::fnv_004d66d0::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(property))));
                                if (propertyController)
                                {
                                    hasPropertyControllers = true;
                                    break;
                                }
                            }
                        }
                        extra = ((::fnv_004d66d0::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(object))));
                        if (extra || hasPropertyControllers)
                        {
                            treeItem.item.text = ((const char *)(::FUN_00464f30((int)("Controllers"))));
                            treeItem.item.image = 5;
                            treeItem.item.selectedImage = treeItem.item.image;
                            treeItem.parent = parent;
                            void* controllersItem = (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                            while (extra)
                            {
                                unsigned int j;
                                {
                                    NiObject* typedController;
                                    {
                                        char controllerName[64];
                                        ::FUN_004add50(controllerName, ((const char *)(::FUN_00559450((int *)(extra->GetRTTI())))), 63);
                                        controllerName[63] = 0;
                                        treeItem.item.text = ((const char *)(::FUN_00464f30((int)(controllerName))));
                                        treeItem.item.image = 6;
                                        treeItem.item.selectedImage = treeItem.item.image;
                                        treeItem.parent = controllersItem;
                                        treeItem.parent = (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                                        extra->GetViewerStrings(strings);
                                        for (j = 0; j < reinterpret_cast<::FUN_00658930_class *>((strings))->GetShortAtOffsetA(); j++)
                                        {
                                            treeItem.item.text = ((const char *)(::FUN_00464f30((int)(strings->GetAt(j)))));
                                            treeItem.item.image = 6;
                                            treeItem.item.selectedImage = treeItem.item.image;
                                            SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                                        }
                                        ::FUN_005e03d0((::NiTArray_Layout *)(strings));
                                        typedController = ((::fnv_004d66d0::NiObject *)(::FUN_00653270((const ::NiRTTI *)(const ::fnv_004d66d0::NiRTTI *)(&(*reinterpret_cast<::fnv_004d66d0::NiRTTI *>(&::g_011f36ac))), (::NiObject *)(extra))));
                                        if (typedController)
                                        {
                                            (*reinterpret_cast<::fnv_004d66d0::NiObject * *>(&::DAT_011f36f8)) = (*reinterpret_cast<::fnv_004d66d0::NiObject * *>(&::DAT_011f36f4));
                                            (*reinterpret_cast<::fnv_004d66d0::NiObject * *>(&::DAT_011f36f4)) = typedController;
                                            reinterpret_cast<::TreeCtrl4d86 *>(this)->PopulateObjectTree(treeItem.parent, (::Object4d86 *)(typedController));
                                        }
                                        else
                                        {
                                            NiObject* otherController = ((::fnv_004d66d0::NiObject *)(::FUN_00653270((const ::NiRTTI *)(const ::fnv_004d66d0::NiRTTI *)(&(*reinterpret_cast<::fnv_004d66d0::NiRTTI *>(&::g_011f36bc))), (::NiObject *)(extra))));
                                            if (otherController)
                                                reinterpret_cast<::TreeCtrl4d88 *>(this)->AddBlendInterpTreeItems(treeItem.parent, (::BlendInterp4d88 *)(otherController));
                                        }
                                        extra = ((::fnv_004d66d0::NiTimeController *)(::fnv_004a8a90::FUN_004a8a90((char *)(extra))));
                                    }
                                }
                            }
                            if (hasPropertyControllers)
                            {
                                void* position = ((void *)(::FUN_00559450((int *)&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))));
                                while (position)
                                {
                                    NiObjectNET* property = ((::fnv_004d66d0::NiObjectNET *)(::FUN_00559450((int *)&((*(::fnv_004d66d0::PropertyValue *)(reinterpret_cast<::ListStandIn *>(&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))->FUN_0057cbe0((int **)&(position))))))));
                                    NiTimeController* propertyController = ((::fnv_004d66d0::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(property))));
                                    while (propertyController)
                                    {
                                        unsigned int j;
                                        {
                                            NiObject* typedController;
                                            {
                                                char controllerName[64];
                                                ::FUN_004add50(controllerName, ((const char *)(::FUN_00559450((int *)(propertyController->GetRTTI())))),
                                                             63);
                                                controllerName[63] = 0;
                                                treeItem.item.text = ((const char *)(::FUN_00464f30((int)(controllerName))));
                                                treeItem.item.image = 6;
                                                treeItem.item.selectedImage = treeItem.item.image;
                                                treeItem.parent = controllersItem;
                                                treeItem.parent =
                                                    (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                                                propertyController->GetViewerStrings(strings);
                                                for (j = 0; j < reinterpret_cast<::FUN_00658930_class *>((strings))->GetShortAtOffsetA(); j++)
                                                {
                                                    treeItem.item.text = ((const char *)(::FUN_00464f30((int)(strings->GetAt(j)))));
                                                    treeItem.item.image = 6;
                                                    treeItem.item.selectedImage = treeItem.item.image;
                                                    SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                                                }
                                                ::FUN_005e03d0((::NiTArray_Layout *)(strings));
                                                typedController = ((::fnv_004d66d0::NiObject *)(::FUN_00653270((const ::NiRTTI *)(const ::fnv_004d66d0::NiRTTI *)(&(*reinterpret_cast<::fnv_004d66d0::NiRTTI *>(&::g_011f36ac))), (::NiObject *)(propertyController))));
                                                if (typedController)
                                                {
                                                    (*reinterpret_cast<::fnv_004d66d0::NiObject * *>(&::DAT_011f36f8)) = (*reinterpret_cast<::fnv_004d66d0::NiObject * *>(&::DAT_011f36f4));
                                                    (*reinterpret_cast<::fnv_004d66d0::NiObject * *>(&::DAT_011f36f4)) = typedController;
                                                    reinterpret_cast<::TreeCtrl4d86 *>(this)->PopulateObjectTree(treeItem.parent, (::Object4d86 *)(typedController));
                                                }
                                                else
                                                {
                                                    NiObject* otherController =
                                                        ((::fnv_004d66d0::NiObject *)(::FUN_00653270((const ::NiRTTI *)(const ::fnv_004d66d0::NiRTTI *)(&(*reinterpret_cast<::fnv_004d66d0::NiRTTI *>(&::g_011f36bc))), (::NiObject *)(propertyController))));
                                                    if (otherController)
                                                        reinterpret_cast<::TreeCtrl4d88 *>(this)->AddBlendInterpTreeItems(treeItem.parent, (::BlendInterp4d88 *)(otherController));
                                                }
                                                propertyController = ((::fnv_004d66d0::NiTimeController *)(::fnv_004a8a90::FUN_004a8a90((char *)(propertyController))));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        reinterpret_cast<::HostClass *>(this)->SendModifierMessages((int)(parent), (::NiObject *)(object));
                        if (!reinterpret_cast<::FUN_0076b610_Class *>((void *)&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))->FUN_0076b610())
                        {
                            treeItem.item.text = ((const char *)(::FUN_00464f30((int)("Properties"))));
                            treeItem.item.image = 5;
                            treeItem.item.selectedImage = treeItem.item.image;
                            treeItem.parent = parent;
                            void* propertiesItem = (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                            void* position = ((void *)(::FUN_00559450((int *)&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))));
                            while (position)
                            {
                                NiObjectNET* property = ((::fnv_004d66d0::NiObjectNET *)(::FUN_00559450((int *)&((*(::fnv_004d66d0::PropertyValue *)(reinterpret_cast<::ListStandIn *>(&((*(::fnv_004d66d0::PropertyList *)(reinterpret_cast<::TESRecipe *>((object))->GetData()))))->FUN_0057cbe0((int **)&(position))))))));
                                {
                                    unsigned int j;
                                    {
                                        char propertyName[64];
                                        ::FUN_004add50(propertyName, ((const char *)(::FUN_00559450((int *)(property->GetRTTI())))), 63);
                                        propertyName[63] = 0;
                                        treeItem.item.text = ((const char *)(::FUN_00464f30((int)(propertyName))));
                                        treeItem.item.image = 6;
                                        treeItem.item.selectedImage = treeItem.item.image;
                                        treeItem.parent = propertiesItem;
                                        treeItem.parent = (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                                        property->GetViewerStrings(strings);
                                        for (j = 0; j < reinterpret_cast<::FUN_00658930_class *>((strings))->GetShortAtOffsetA(); j++)
                                        {
                                            treeItem.item.text = ((const char *)(::FUN_00464f30((int)(strings->GetAt(j)))));
                                            treeItem.item.image = 6;
                                            treeItem.item.selectedImage = treeItem.item.image;
                                            SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                                        }
                                        ::FUN_005e03d0((::NiTArray_Layout *)(strings));
                                    }
                                }
                            }
                        }
                        if (object->IsTriBasedGeom() && ((::fnv_004d66d0::NiObject *)(::fnv_0043fad0::FUN_0043fad0((const char *)(object->IsTriBasedGeom())))))
                        {
                            treeItem.item.text = ((const char *)(::FUN_00464f30((int)("SkinInstance"))));
                            treeItem.item.image = 5;
                            treeItem.item.selectedImage = treeItem.item.image;
                            treeItem.parent = parent;
                            treeItem.parent = (void*)SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                            ViewerStrings* skinStrings = new ViewerStrings(128, 128);
                            ((::fnv_004d66d0::NiObject *)(::fnv_0043fad0::FUN_0043fad0((const char *)(object->IsTriBasedGeom()))))->GetViewerStrings(skinStrings);
                            for (unsigned int j = 0; j < reinterpret_cast<::FUN_00658930_class *>((skinStrings))->GetShortAtOffsetA(); j++)
                            {
                                treeItem.item.text = ((const char *)(::FUN_00464f30((int)(skinStrings->GetAt(j)))));
                                treeItem.item.image = 6;
                                treeItem.item.selectedImage = treeItem.item.image;
                                SendMessageA(tree, 0x1100, 0, (LPARAM)&treeItem);
                            }
                            ::FUN_005e03d0((::NiTArray_Layout *)(skinStrings));
                        }
                        insertion = ((::fnv_004d66d0::NiObject *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((object))->FUN_006838b0()));
                        if (insertion)
                            reinterpret_cast<::C7 *>(this)->AddChildTreeItem(parent, (::Node7 *)(insertion));
                        delete strings;
                        if (object->IsSceneNode())
                        {
                            NiNode* node = (NiNode*)object;
                            for (unsigned int j = 0; j < node->FUN_0043b480(); j++)
                            {
                                NiAVObject* child = ((::fnv_004d66d0::NiAVObject *)(reinterpret_cast<::NiNode *>((node))->GetAt(j)));
                                if (child)
                                    FUN_004d66d0(parent, child);
                            }
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_004d66d0
