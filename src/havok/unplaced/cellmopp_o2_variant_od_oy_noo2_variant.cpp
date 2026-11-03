
// src/havok/unplaced/cellmopp_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/havok/unplaced/cellmopp_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/unplaced/cellmopp_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/havok/unplaced/cellmopp.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/havok/unplaced/cellmopp.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cellmopp.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <windows.h>
#include "fnv/decl/CCA1B0Level2.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005076c0Class.h"
#include "fnv/decl/FUN_0056d360_Class.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_006222f0_Class.h"
#include "fnv/decl/FUN_00622470.h"
#include "fnv/decl/FUN_00622490.h"
#include "fnv/decl/FUN_006228e0_shell.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c84d00_cls.h"
#include "fnv/decl/FUN_00c84d50_cls.h"
#include "fnv/decl/FUN_00c84df0_cls.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/FUN_00ca5080_cls.h"
#include "fnv/decl/HeightField.h"
#include "fnv/decl/NiStream.h"
#include "fnv/decl/S00cafef0_Obj.h"
#include "fnv/decl/S_00c85c10.h"
#include "fnv/decl/S_00cb0030_Cls.h"
#include "fnv/decl/StringBuilder_ca5190.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/bhkBoxShape.h"
#include "fnv/decl/bhkUnaryAction.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00c84000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
struct Child;
struct Item
{
    int unk00;
    int unk04;
    Child* child;
};
struct Result
{
    int unk00;
    Item* item;
};
struct This
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual Result* GetResult(char* output);
    void FUN_00ca4e50(int first, int second);
};
struct Resolved
{
    int unk00;
    int unk04;
    Child* child;
};
struct Child
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
    virtual void v17();
    virtual Resolved* Resolve(int value);
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual bool IsRejected(int value);
};
struct S_00ca4ec0_Stream
{
};
struct S_00ca4ec0_Out
{
    int unk00;
    int m_04;
};
struct S_00ca4ec0_Base
{
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
    virtual S_00ca4ec0_Out* vb4(int* out);
};
struct S_00ca4ec0 : S_00ca4ec0_Base
{
    void FUN_00ca4ec0(S_00ca4ec0_Stream& kStream);
};
struct NiStream;
struct FirstInterface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void* FUN_00ca4f40_get();
};
struct SecondInterface
{
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
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void FUN_00ca4f40_stream(NiStream* stream);
};
struct ReturnedObject
{
    int unk00;
    int unk04;
    SecondInterface* unk08;
};
struct HC1Base
{
    int unk00;
    int unk04;
    FirstInterface* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void FUN_00ca4f40(NiStream* stream);
};
struct Link
{
};
struct Header
{
    int state;
    int flags;
    void* value;
    int type;
    Link link;
};
struct Node
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual Link* get();
};
struct Sink
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void set(void*);
};
struct Owner
{
    int state;
    int flags;
    Node* node;
    void FUN_00ca4f80(Sink*);
    void* getValue()
    {
        if (this)
        {
            Node* current = node;
            if (current)
            {
                Link* link = current->get();
                if (link)
                {
                    Header* header = reinterpret_cast<Header*>(reinterpret_cast<char*>(link) - 16);
                    if (header)
                        return header->value;
                }
            }
        }
        return 0;
    }
};
struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard()
    {
        previous = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~MemoryContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};
struct FUN_00cb0780_Allocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Free(void* memory, unsigned int size);
};
struct FUN_00cb0780_Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb0780_Allocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FUN_00cb0780_class
{
    int unk00;
    int unk04;
    int unk08;
    void* memory;
    void FUN_00cb0780(bool release);
};
struct ThreadState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};
struct NiStringArray
{
    void* unk00;
    char** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short unk0C;
    unsigned short growth;
};
struct GlobalString
{
    const char* value;
};
struct StringBuilder
{
    void FUN_00cb09b0(NiStringArray* array);
};
struct ThreadStateGuard
{
    int previous;
    ThreadStateGuard() : previous((*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2B4)
    {
        (*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2B4 = 0x10;
    }
    ~ThreadStateGuard()
    {
        (*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2B4 = previous;
    }
};
struct EP
{
    int u0[0x50];
    int m254;
    int m260;
};
struct K46
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual int M45(void* p);
};
struct QTF
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual int M45(void* p);
    void FUN_00ca4f00(EP* a1);
};
struct FUN_00ca4fd0_Value
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void Target(int first, int second);
};
class FUN_00ca4fd0_cls
{
  public:
    int unk00;
    int unk04;
    Node* m_pReferencedNode;

    void FUN_00ca4fd0(int first, int second);
};
struct RefCounted
{
    int unk00;
    long refCount;
};
struct Owner_Ext : public Owner
{
    void FUN_00ca5130(bool flag);
};
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
struct SpawnedObject
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedObject()
    {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_vtbl = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_01030bf4));
        unk0C = 0;
        unk10 = 0;
        ::DAT_012680f8++;
        m_vtbl = (void*)DAT_0104dbac;
        (*reinterpret_cast<int *>(&::CCA1B0Level2::ms_uiInstances))++;
        m_vtbl = (void*)"@$b";
        DAT_0126834c++;
    }
    void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};
struct FUN_00cb05d0_cls
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49(SpawnedObject* obj, int a1);
    SpawnedObject* FUN_00cb05d0(int a1);
};
struct FUN_00cb06c0_Alloc
{
    virtual void slot00();
    virtual void* Alloc(unsigned int size);
};
struct FUN_00cb06c0_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb06c0_Alloc* allocator;
};
struct FUN_00cb06c0_Obj
{
};
struct FUN_00cb06c0_cls
{
    int unk00;
    int unk04;
    void* unk08;
    void* unk0c;
    void* FUN_00cb06c0(bool* out);
};
struct S00cb0820_Alloc
{
    virtual void slot00();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* memory, unsigned int size);
};
struct S00cb0820_Mem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00cb0820_Alloc* allocator;
    S00cb0820_Alloc& heap()
    {
        return *allocator;
    }
};
struct S00cb0820_Ref
{
    void* m_vtbl;
    unsigned short m_usAllocationSize;
    short m_iObjectReferenceCount;
    void* operator new(unsigned int size)
    {
        S00cb0820_Ref* b = (S00cb0820_Ref*)((S00cb0820_Mem*)FUN_00c85750())->heap().Alloc(size);
        b->m_usAllocationSize = (unsigned short)size;
        return b;
    }
    void operator delete(void* p, unsigned int size);
};
struct S00cb0820_Src
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
    int unk28;
    int unk2c;
    int unk30;
    float unk34;
};
struct S00cb0820_Outer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00cb0820_Src src;
};
extern char DAT_010c853c;
struct S00cb0820_Shape : S00cb0820_Ref
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct S00cb0820_Shape70 : S00cb0820_Shape
{
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
    float unk68;
    int unk6c;
    S00cb0820_Shape70(S00cb0820_Src* src)
    {
        reinterpret_cast<::HeightField *>(this)->FUN_00d248a0((*(const ::hkSampledHeightFieldShapeCinfo *)(src)), (::HeightFieldType)(2));
        m_vtbl = &DAT_010c853c;
        double d = unk14 - ::g_01012070;
        unk60 = src->unk30;
        unk64 = (int)d;
        unk68 = src->unk34;
    }
};
struct S00cb0820_Obj40 : S00cb0820_Ref
{
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
    S00cb0820_Obj40(S00cb0820_Shape70* shape, float value);
};
struct S00cb0820_Tag
{
    char v;
    S00cb0820_Tag() : v(0)
    {}
    S00cb0820_Tag(const S00cb0820_Tag& o) : v(o.v)
    {}
};
struct S00cb0820_Obj30 : S00cb0820_Ref
{
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
    S00cb0820_Obj30(S00cb0820_Obj40* body, S00cb0820_Tag tag);
};
struct S00cb0820_World
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
    virtual void v35(S00cb0820_Obj30* obj);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(S00cb0820_Outer* a1);
    void FUN_00cb0820(S00cb0820_Outer* a1);
};

union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
};
struct xFltSetting
{
};
struct xFilter
{
    xFilter(int, int, int);
    unsigned int m_uiFilterValue;
};
struct __declspec(align(16)) xPhantomCinfo
{
    xPhantomCinfo();
    ~xPhantomCinfo();
    void FUN_0056f0f0(unsigned int);
    int m_q[0x38];
};
struct xRef
{
};
struct __declspec(align(16)) xShapeCinfo
{
    xShapeCinfo();
    int m_iWordAt00[4];
    xVec4 m_10;
    int m_20;
    int m_24;
    int m_28[6];
    unsigned int m_40;
    float m_44;
    int m_48[2];
};
struct xNiAlloc
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct xShape : xNiAlloc
{
    xShape(xShapeCinfo*);
    int m_auiShapeKeys[5];
};
struct xThing
{
    int m_iWordAt00;
};
struct xPhantom : xNiAlloc
{
    xPhantom(xPhantomCinfo*);
    int m_auiShapeKeys[7];
};
struct xPtr
{
    xPtr(void*);
    ~xPtr();
    void* m_p;
};
struct xList
{
    int m_q[4];
};
struct xMgr
{
    int m_iWordAt00, m_iWordAt04;
    xList m_8;
    bool FUN_00621f60(xRef** apList, unsigned int auiCount, float afVal);
};
// @fnv 0x00621f60
bool xMgr::FUN_00621f60(xRef** apList, unsigned int auiCount, float afVal)
{
    bool RESULT = false;
    if (!reinterpret_cast<::FUN_00622470 *>(this)->IsCreated())
    {
        if (apList)
        {
            xPhantomCinfo CI;
            reinterpret_cast<::FUN_00507610_Class *>(&(CI))->FUN_00507610(0.0f);
            reinterpret_cast<::FUN_0056d360_Class *>(&(CI))->FUN_0056d360(5);
            reinterpret_cast<::FUN_005076c0Class *>(&(CI))->FUN_005076c0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011cc1d8)))))));
            xFilter FILTER(0x11, 1, 0);
            CI.FUN_0056f0f0(((unsigned int)(::FUN_00559450((int *)&(FILTER)))));
            for (unsigned int I = 0; I < auiCount; I++)
            {
                xRef* REF = apList[I];
                if (REF)
                {
                    xShapeCinfo SC;
                    SC.m_20 = SC.m_24 = 0x11;
                    reinterpret_cast<::bhkUnaryAction *>(&(SC.m_10))->Set(::FUN_004a3e90(128.0f), ::FUN_004a3e90(1.0f), ::FUN_004a3e90(128.0f), 0.0f);
                    SC.m_40 = reinterpret_cast<::FUN_0049ec60 *>((REF))->GetNext();
                    SC.m_44 = afVal;
                    reinterpret_cast<::S00cafef0_Obj *>(&(SC.m_10))->UpdateBoundsFromElements();
                    xPtr SHAPE(new xShape(&SC));
                    reinterpret_cast<::FUN_006222f0_Class *>(&(CI))->FUN_006222f0(((int)(reinterpret_cast<::FUN_00620b80_shell *>((((void *)(::FUN_00559450((int *)&(SHAPE))))))->GetReferenceFlags())));
                    xPhantom* PHANTOM = new xPhantom(&CI);
                    reinterpret_cast<::S_00c85c10 *>((PHANTOM))->FUN_00c85c10((int *)(REF), (int *)(::xThing *)(&(*reinterpret_cast<::xThing *>(&::g_011f4a20))));
                    reinterpret_cast<::FUN_006228e0_shell *>(&(m_8))->FUN_006227b0((unsigned int)&(const ::xPtr &)(PHANTOM));
                }
            }
        }
        RESULT = true;
    }
    return RESULT;
}
