
// src/staging/blk_00c60000_od_o2_gf_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy /GF (unit src/staging/blk_00c60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/A89210IntsExtraData.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C613A0_Extra.h"
#include "fnv/decl/C74C20Quat.h"
#include "fnv/decl/Collector62.h"
#include "fnv/decl/Extra_00a998e0.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045bb20_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5d2f0_class.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a698a0_class.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a89ae0_shell.h"
#include "fnv/decl/FUN_00a99a90_IntsExtraData.h"
#include "fnv/decl/FUN_00c319e0_cls.h"
#include "fnv/decl/FUN_00c31b80_This.h"
#include "fnv/decl/FUN_00c5fd50_cls.h"
#include "fnv/decl/FUN_00c62390_cls.h"
#include "fnv/decl/FUN_00c64e70.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiObject_00a7b3d0.h"
#include "fnv/decl/NiPSysBoxEmitterWrapper.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/ParticleModifierBinary.h"
#include "fnv/decl/PoseState.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/Quat74.h"
#include "fnv/decl/S00c62f40_Array.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00a742a0.h"
#include "fnv/decl/SetAtArray.h"
#include "fnv/decl/Stub_00c31b60.h"
#include "fnv/decl/X.h"
#include "fnv/decl/fnv_00a9a4e0__Cls_00a9a4e0.h"
#include "fnv/decl/fnv_00c65490__C65490_Owner.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00a41000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00a9a000.h"
#include "fnv/symbols_00c60000.h"
#include "fnv/symbols_00c61000.h"
#include "fnv/symbols_00c63000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0109d000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "../../include/layout_support.h"
struct FUN_00c600f0_Class
{
    void* FUN_00c600f0();
};
struct NiStream;
class CloningProcess;
class NiStream;
struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
public:
    void CopyMemberData(::NiPSysModifier *, ::CloningProcess &);
public:
    void LoadBinary(::NiStream &);
};
struct BSPSysSimpleColorModifier : public NiPSysModifier
{
    void FUN_00c60910(NiStream& stream);
};
struct FUN_00c60930_class
{
    void FUN_00c60930(void* a);
};
struct FUN_00c60d40_Class
{
    void* FUN_00c60d40();
};
struct FUN_00c61420_Class
{
    void* FUN_00c61420(void* p);
};
struct FUN_00a99870_Class
{
    void FUN_00a99870(int, int);
};
void FUN_00a99870_Class::FUN_00a99870(int, int)
{}
struct FUN_00c61430_Class
{
    void FUN_00c61430(int, int);
};
struct FUN_00c61450_Class
{
    void FUN_00c61450(int a);
};
struct FUN_00a9af00_class
{
};
struct FUN_00c61470_class : FUN_00a9af00_class
{
    void CallBaseWithArg(int a);
};
struct FUN_00c61490_Class
{
    bool IsNot(const void* arg);
};
struct FUN_00c614c0_Class
{
    void FUN_00c614c0(void* ap);
};
struct FUN_00c614e0_Class
{
    char FUN_00c614e0(int arg);
};
struct NiFixedString;
struct NiAVObject
{
    void FUN_00c61610();
};
struct FUN_00c61810_class
{
    void* FUN_00c61810();
};
struct FUN_00c61820_class
{
    void* FUN_00c61820(int);
};
struct NiStream;
struct NiPSysVolumeEmitter
{
    void LoadBinaryFromStream(NiStream* stream);
};
struct NiStream;
struct NiObject
{
    void FUN_00c61f30(NiStream& stream);
};
struct FUN_00c61f60_class
{
    void FUN_00c61f60(int);
};
struct FUN_00c61f80_cls
{
    void FUN_00c61f80(void* apParam);
};
struct NiAVObject;
struct NiPSysCylinderEmitter
{
    bool FUN_00c61fa0(NiAVObject*);
};
struct FUN_00c627e0_Class
{
    void FUN_00c627e0(void* p);
};
struct FUN_00c632e0_Class
{
    void* FUN_00c632e0();
};
struct FUN_00c31670_class
{
};
struct FUN_00c63950_class
{
    void ForwardToOther(int a);
};
struct GlobalObject_00a7b610;
struct FUN_00c63aa0_class
{
    GlobalObject_00a7b610* FUN_00c63aa0();
};
void __cdecl CallWithSameArgumentTwice(int a);
struct NiBinaryExtraData
{
};
struct BSDecalPlacementVectorExtraData : NiBinaryExtraData
{
    void LinkToObject(void*);
};
struct FUN_00c644d0_Class
{
    unsigned char FUN_00c644d0(const char*);
};
struct FUN_00c64600_Class
{
    void* GetGlobalPointer();
};
struct NiStream;
struct NiObjectBase
{
};
struct FUN_00c64b70 : NiObjectBase
{
    bool RegisterStreamables(NiStream& stream);
};
struct FUN_00c64fc0_class
{
    int GetThisAddress(int);
};
struct NiStream;
struct NiExtraData
{
    void FUN_00c65160(NiStream& stream);
};
struct C00c541e0
{
    bool FUN_00c65290(int a);
};
extern "C" void* DAT_012043f0;
struct FUN_00c657e0_class
{
    void* GetGlobalDataPtr();
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c377c;
struct NiTPointerList_00c62890
{
    void* m_pObjectItem;
    void* m_pNext;
    void FUN_00c62890();
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c3a08;
struct FUN_00c65680_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void FUN_00c65680();
};
struct FUN_00c600c0_class
{
    void* FUN_00c600c0(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};
struct FUN_00c613a0_Class
{
    void* FUN_00c617e0(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
extern "C" void NiFree(void*);
struct MemoryManager
{
};
struct FUN_00c63210_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* FUN_00c63210(int flag);
};
struct FUN_00a7b300_shell
{
    void FUN_00a7b300();
};
struct FUN_00c632f0_class
{
    void* FUN_00c632f0(unsigned int flags);
};
void __cdecl operator delete(void*, int);
struct CloningProcess;
struct NiPSysModifierCopy : NiPSysModifier
{
};
struct FUN_00c63840_Class : NiPSysModifier
{
    void CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc);
};
struct SStream;
struct SObj;
struct NiPSysModifier_00c31950
{
};
struct FUN_00c63970_class : NiPSysModifier_00c31950
{
    void FUN_00c63970(void* stream);
};
void __cdecl FUN_00c63b40(void* p);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64610_Class
{
    void FUN_00c63b40();
    void* FUN_00c64610(unsigned int flags);
};
struct FUN_00c64930_Class
{
    void FUN_00c64930(int a);
};
struct FUN_00c64940_Class
{
    bool FUN_00c64940(int a);
};
struct FUN_00c64c30_Class
{
    bool FUN_00c64c30(int a);
};
extern int DAT_010c3384;
struct NiPSysPositionModifier
{
    NiPSysPositionModifier();
    ~NiPSysPositionModifier();
};
struct FUN_00c60240 : NiPSysPositionModifier
{
    int m_vt;
    float m_f[4];
    float m_v[4];
    float m_w[4];
    FUN_00c60240();
};
struct NiStream;
class NiStream;
struct RgbaColor
{
public:
    void LoadBinary(::NiStream &);
};
struct FUN_00c60950_class : NiPSysModifier_00c31950
{
    void FUN_00c60950(NiStream* stream);
};
size_t _strlen(const char*);
struct P03MM
{
};
struct FUN_00c62090_Class
{
    char* BuildAttachTypeString(const char* name, int type);
};
struct FUN_00c63320_Class
{
    GlobalObject_00a7b610* FUN_00c63320();
};
struct NiStream
{
};
struct NiExtraDataSaveHelper
{
};
struct FUN_00c65210_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    unsigned short m_18;
    void FUN_00c65210(NiStream& stream);
};
extern "C" void* __cdecl NiMalloc(unsigned int size);
struct FUN_00c65760_Class
{
    int* m_pVtbl;
    void* m_pData;
    unsigned short m_iArrayLength;
    unsigned short m_iFlags;
    unsigned short m_iPad;
    unsigned short m_iType;
    void* InitArray(unsigned short count, unsigned short type);
};
struct FUN_00c61b10
{
    char m_iWordAt00[0x6c];
    FUN_00c61b10();
    ~FUN_00c61b10();
    static void* operator new(unsigned int size);
};
FUN_00c61b10* FUN_00c61e70();
extern "C" void* __cdecl NiMalloc(unsigned int);
struct FUN_00c63260_class
{
    int* m_ppVirtualMethodTable;
    void* m_data;
    unsigned short m_uiX;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_uiY;
    FUN_00c63260_class(unsigned short x, unsigned short y);
};
struct NiPoint3_ZERO
{
    int x;
    int y;
    int z;
};
extern int DAT_010c37fc;
struct FUN_00c63330 : NiPSysPositionModifier
{
    FUN_00c63330();
};
int strcpy_s(char* dst, unsigned int size, const char* src);
size_t strlen(const char*);
struct MemoryManagerAllocHelper
{
};
struct FUN_00c64780_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00c64780(const char* apName);
};
struct FUN_00c65710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* FUN_00c65710(unsigned int flags);
};
struct IsEqualHelper
{
};
struct FUN_00c60000_Class
{
    bool IsEqualWithFloat(void* arg);
};
struct FUN_00c60700_Group
{
    unsigned int value00;
    unsigned int value04;
    unsigned int value08;
    unsigned int value0c;
};
struct FUN_00c60700_Data
{
    unsigned char padding[0x18];
    FUN_00c60700_Group group00;
    FUN_00c60700_Group group10;
    FUN_00c60700_Group group20;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
};
struct FUN_00c60700_Class : NiPSysModifierCopy
{
    void FUN_00c60700(NiPSysModifier* dst, CloningProcess& proc);
};
template <class T> void __cdecl ReadBinaryValue(NiStream& stream, T& value);
struct NiPSysModifierLoadBinary_StandIn
{
};
struct NiColorALoadBinary_StandIn
{
};
struct FUN_00c60850_Class : public NiPSysModifier
{
    void FUN_00c60850(NiStream& stream);
};
struct MyIsEqual
{
};
struct FUN_004a4cc0_shell
{
    bool FUN_004a4cc0(void*);
};
struct FUN_00c60a10_Class
{
    unsigned char m_00[0x48];
    float m_48;
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;

    bool FUN_00c60a10(NiObject*);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c60d10_Class
{
    void* FUN_00c60d10(unsigned int flags);
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct FUN_00c612b0_Class : NiAVObject, A51BF0Base
{
    unsigned char m_data[19];

    FUN_00c612b0_Class();
};
class NiBinaryExtraData;
struct CloningProcess;
struct FUN_00a7b330_shell
{
public:
    void FUN_00a7b330(::NiBinaryExtraData *, ::CloningProcess *);
};
struct FUN_00c61830_class
{
    void FUN_00c61830(void* a, void* b);
};
struct FUN_00c62390_class
{
};
struct FUN_00c61ba0_class : FUN_00c62390_class
{
    void ForwardToBase(void* a, void* b, void* c);
};
template <class T> void ReadBinaryValue(NiStream&, T&);
struct NiPSysModifierStub
{
    virtual void LoadBinary(NiStream&);
};
struct FUN_00c63900_class : NiPSysModifierStub
{
    void LoadModifierData(NiStream& stream);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c31750_Class
{
};
struct FUN_00c63a70_Class
{
    void* FUN_00c63a70(unsigned int flags);
};
struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool FUN_00c64500(const void* arg);
};
struct A46BB0Object
{
};
int __cdecl __stricmp(const char*, const char*);
struct FUN_00c64980_Class : A46BB0Object
{
    bool FUN_00c64980(A46BB0Object* arg);
};
struct FUN_0043ba10_shell
{
public:
    ::FUN_0043ba10_shell *FUN_0043ba10(::FUN_0043ba10_shell *);
};
struct FUN_00c64dc0_Class
{
    char m_iWordAt00;
    char m_cByteAtOffset1;
    char m_cByteAtOffset2;
    char m_cByteAtOffset3;
    FUN_0043ba10_shell m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_0043ba10_shell* FUN_00c64dc0(unsigned int a);
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64e70_Class
{
    void* FUN_00c65650(unsigned int flags);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct SpawnedObject_b9118
{
    char m00[0x60];
    SpawnedObject_b9118();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
class C61330Base
{
  public:
    C61330Base(int iA, int iB);
    virtual ~C61330Base();

    int unk04;
};
class FUN_00c61330 : public C61330Base
{
  public:

    FUN_00c61330(int iA, int iB);
    virtual ~FUN_00c61330();
};
struct FUN_00c61c50_sub
{
    void FUN_00c628c0(unsigned int n);
};
struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void FUN_00c61c50(unsigned int x, unsigned int y);
};
struct FUN_00c62140_Elem;
struct FUN_00c62140_Item;
struct FUN_00c62140_Val
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};
struct FUN_00c62140_Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
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
    FUN_00c62140_Elem** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct FUN_00c62140_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c62140_Item* v03();
};
struct FUN_00c62140_Pad
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct FUN_00c62140_Pad5
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};
struct FUN_00c62140_Sub
{
};
struct FUN_00c62140_cls
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
    FUN_00c62140_Obj* m_54;
    int unk58;
    FUN_00c62140_Sub m_5c;

    void FUN_00c62140();
};
struct S_00c62cc0_Class
{
    void* unk0;
    void* unk4;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short unk_c;
    unsigned short m_usTrailingValue;

    void FUN_00c628c0(unsigned int arg);
    unsigned int FUN_00c62cc0(unsigned int arg);
};
struct S_00c62cc0_Locals
{
    unsigned int value;
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
};
// FUN_00c634b0: thiscall (this in ecx), 2 stack params (a1 pointer, unsigned short index).
class XVec12
{
  public:
    float m_00;
    float m_04;
    float m_08;
};
class XSub30
{
  public:
    unsigned int unk00;
};
class XItem12
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
class XItem28
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
};
class XObj70
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    XItem12* m_20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68, unk6c;
    XItem28* m_70;
};
class FUN_00c634b0_cls
{
  public:
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    XSub30 m_30;
    void FUN_00c634b0(XObj70* a1, unsigned short idx);
};
struct NiPoint3_c
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
extern NiPoint3_c NiPoint3_ZERO;
struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3_c v;
    void ResetVector();
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct PositionModifierObject_b9439
{
    char m00[0x3c];
    PositionModifierObject_b9439();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct Pad32
{
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7;
};
struct ArgObj
{
};
struct FUN_00c63a00_cls
{
    void FUN_00c63a00(ArgObj* a1);
};
struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    void* m_entries[16];

    void FUN_00c643d0(int arg);
};
class FUN_00c64b90_target;
class FUN_00c64b90_item
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
};
class FUN_00c64b90_target
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(unsigned int value);
};
class FUN_00c64b90_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00c64b90_item** m_0c;
    int unk10;
    unsigned short m_14;
    void FUN_00c64b90(FUN_00c64b90_target* a1);
};
struct FUN_00c64da0_cls
{
    int unk00;
    void FUN_00c64da0(int a);
};
struct DispatchStub_c64
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void** m10;
    int unk14;
    unsigned short m18;
    void DispatchToItems(int a8, int cc);
};
struct ItemCallee_c64
{
};
struct FUN_00c65180_VTable
{
    virtual void FUN_00c65180_v0();
    virtual void FUN_00c65180_v1();
    virtual void FUN_00c65180_v2();
    virtual void FUN_00c65180_v3();
    virtual void FUN_00c65180_v4();
    virtual void FUN_00c65180_v5();
    virtual void FUN_00c65180_v6();
    virtual void FUN_00c65180_v7();
    virtual void FUN_00c65180_v8(void* p);
};
struct FUN_00c65180_Class
{

    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void** m_10;
    int m_14;
    unsigned short m_18;

    unsigned char VisitEntries(FUN_00c65180_VTable* p);
};
struct MyColorA
{
    float r;
    float g;
    float b;
    float a;
};
struct Point3ParameterData
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    float unk18;
};
struct NiPSysData
{
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
    MyColorA* m_pkParticleColors;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short m_usNumParticles;
    short pad52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
};
struct BSPSysSimpleColorModifierCand
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MyColorA m_kColor1;
    MyColorA m_kColor2;
    MyColorA m_kColor3;
    float m_fFadeInPercent;
    float m_fFadeOutPercent;
    float m_fColor1End;
    float m_fColor2Start;
    float m_fColor2End;
    float m_fColor3Start;

    void UpdateParticleColors(float fTime, NiPSysData* pkData);
};
class NiObjectC60
{
  public:
    NiObjectC60();
    virtual ~NiObjectC60();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

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
};
class NiCloningProcessC60;
class NiOwnerC60
{
  public:
    NiObjectC60* CloneObject(NiCloningProcessC60& kCloning);
};
struct NiTPrimitiveArray_unsigned_int_
{
};
struct FUN_00c615a0_class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
    void FUN_00a99b20(NiTPrimitiveArray_unsigned_int_* values);
    void AppendGlobalAndFormatValues(NiTPrimitiveArray_unsigned_int_* values);
};
struct GlobalObject_00a7b610;
struct Unused20
{
    int a, b, c, d, e, f, g, h;
};
struct C639a0Cls : MyIsEqual
{
    char pad[0x20];
    float m_20;
    bool FUN_00c639a0(NiObject* pObject);
};

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
struct Vector
{
    __m128 value;
    void FUN_00c74c90(Vector*);
    void FUN_00cb2450(const Vector*, float);
    inline void FUN_00c66320(const Vector*, const Vector*);
    inline void FUN_005611c0();
    Vector()
    {}
    __forceinline void operator=(const Vector& v)
    {
        value = v.value;
    }
    __forceinline void normalize()
    {
        __m128 squared = _mm_mul_ps(value, value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), sum);
        __m128 estimate = _mm_rsqrt_ss(sum);
        __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(sum, estimate), estimate));
        __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
        inverse = _mm_andnot_ps(_mm_cmpeq_ss(sum, _mm_set_ss(::DAT_01011d78)), inverse);
        value = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), value);
    }
};
struct InputRef
{
    const Vector* p;
    InputRef(const Vector* q) : p(q)
    {}
    operator const Vector*() const
    {
        return p;
    }
    const Vector* operator->() const
    {
        return p;
    }
};
struct TargetVector
{
    unsigned int unk00, unk04, unk08, unk0c;
    Vector vector;
};
struct Holder
{
};
struct Entry
{
    Holder* holder;
    short index;
    short unk06;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Vector position;
    unsigned int unk40, unk44, unk48, unk4c;
};
extern float DAT_01267d30, DAT_01267d24;
struct Constraint
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
    unsigned short unkb0;
    bool enabled;
    unsigned char unkb3;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    Entry entries[1];
    float FUN_00c755e0(unsigned int, InputRef);
};
// @fnv 0x00c755e0
float Constraint::FUN_00c755e0(unsigned int index, InputRef input)
{
    float distance = 0.0f;
    __m128 oldPosition = entries[index].position.value;
    __m128 newPosition = input->value;
    __m128 difference = _mm_and_ps(_mm_sub_ps(newPosition, oldPosition), ::DAT_01017d10);
    __m128 epsilon;
    epsilon = _mm_set1_ps(::AngularDashpotApplyD4DCB0::DAT_01017d00);
    if ((_mm_movemask_ps(_mm_cmple_ps(difference, epsilon)) & 7) != 7)
    {
        Vector delta;
        reinterpret_cast<::Quat74 *>(&(delta))->FUN_00c74ac0((*(const ::Quat74 *)(input)), (*(const ::Quat74 *)(&entries[index].position)));
        distance = reinterpret_cast<::C74C20Quat *>(&(delta))->GetAngle();
        float limit = enabled ? DAT_01267d30 : DAT_01267d24;
        if (distance > limit * ::DAT_01023128)
        {
            distance = (float)(limit * ::DAT_01023128);
            Vector axis;
            delta.FUN_00c74c90(&axis);
            axis.normalize();
            delta.FUN_00cb2450(&axis, distance);
        }
        {
            Vector result;
            ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(result), (void *)(&delta), (const ::fnv_00c66320::__m128 *)(const ::Vector *)(&entries[index].position), {});
            reinterpret_cast<::FUN_005611c0_t *>(&(result))->FUN_005611c0();
            TargetVector* target = ((::TargetVector *)&(reinterpret_cast<::PoseState *>((entries[index].holder))->FUN_00cda8e0(entries[index].index)));
            __m128 updated = result.value;
            target->vector.value = updated;
            entries[index].position.value = updated;
        }
    }
    return distance;
}

static __forceinline __m128 cross3(__m128 a, __m128 b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(first, second);
}
static __forceinline __m128 dot4(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
    return _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));
}
static __forceinline __m128 blendXYZW(__m128 a, __m128 b)
{
    return _mm_shuffle_ps(a, _mm_unpackhi_ps(a, b), 0xc4);
}
inline void Vector::FUN_00c66320(const Vector* a, const Vector* b)
{
    __m128 xyz = cross3(a->value, b->value);
    xyz = _mm_add_ps(xyz, _mm_mul_ps(_mm_shuffle_ps(a->value, a->value, 0xff), b->value));
    xyz = _mm_add_ps(xyz, _mm_mul_ps(_mm_shuffle_ps(b->value, b->value, 0xff), a->value));
    __m128 p = _mm_mul_ps(a->value, b->value);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    __m128 w = _mm_sub_ps(p, _mm_shuffle_ps(s, s, 0));
    value = blendXYZW(xyz, w);
}
inline void Vector::FUN_005611c0()
{
    __m128 s = dot4(value, value);
    __m128 e = _mm_rsqrt_ss(s);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(s, e), e));
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), correction);
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(s, _mm_set_ss(0.0f)), inverse);
    value = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), value);
}
