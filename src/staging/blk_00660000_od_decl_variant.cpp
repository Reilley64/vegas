
// src/staging/blk_00660000_od_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0066e100: the skeleton of src/staging/blk_00660000_od.cpp
// with declarations corrected to what the original code does (unit: struct G2 : public List_009e03e0 { void AddHead(Detectio -> struct G2 : public List_009e03e0 { void AddHead(Detectio). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00660000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <new>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/ArrD9E0.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DurationData.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_0044ed80_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a4840_class.h"
#include "fnv/decl/FUN_005ca4f0_shell.h"
#include "fnv/decl/FUN_0065cc30_class.h"
#include "fnv/decl/FUN_0065ea40_class.h"
#include "fnv/decl/FUN_0065ea60_cls.h"
#include "fnv/decl/FUN_006661e0.h"
#include "fnv/decl/FUN_00678cc0_shell.h"
#include "fnv/decl/FUN_00678ce0_shell.h"
#include "fnv/decl/FUN_0067fb60_shell.h"
#include "fnv/decl/FUN_00821660_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/Range62A.h"
#include "fnv/decl/SpawnedSourceOwner.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/Worker.h"
#include "fnv/decl/fnv_0062a100__FUN_0062a100_shell.h"
#include "fnv/decl/fnv_0066df40__B6DF40Owner.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_008d7070__DetectionStateProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_0065e000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_00660000.h"
#include "fnv/symbols_00661000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_0066b000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_008d7000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aaf000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01268000.h"
#include "../../include/layout_support.h"
struct FUN_006601f0_Class
{
    void FUN_006601f0(int a, int b);
};
extern "C" void __cdecl FUN_006603a0(void* a, void* b, void* c, void* d);
struct FUN_00660300_Class
{
    int FUN_00660300(int a, int b);
};
struct FUN_00660320_Class
{
    void FUN_00660320(int a, int b);
};
struct FUN_00661d30_cls
{
    const char* const* GetArg1Ptr();
};
extern "C" void* __cdecl FUN_00665f50(void*);
extern int DAT_01066434;
struct FUN_00665c50
{
    void* FUN_00665f50(int a);
    void* Set(int a);
};
struct FUN_00665f10_class
{
    int Identity(int a);
};
struct BGSSaveLoadChangesMap
{
    void Deallocate(void* p);
    void FUN_00666050(void* p);
};
struct Setting_S
{
};
struct Flt
{
    operator unsigned int();
};
struct FUN_0066dd80_Class
{
    bool IsFlag8Set() const;
};
extern int DAT_01068884;
struct FUN_0067ad20_Class
{
    int* vtbl;
    FUN_0067ad20_Class();
};
extern int DAT_01068884;
struct FUN_0067ad70_Class
{
    void FUN_0067ad70();
};
extern int DAT_01068aa4;
struct ActorPackageData
{
    ActorPackageData();
};
ActorPackageData::ActorPackageData()
{}
extern "C" int DAT_01068aa4;
struct FUN_0067d970_Class
{
    int m;
    void FUN_0067d970();
};
struct FUN_0067f4b0_class
{
    unsigned char b;
    int a;
    int c;
    void FUN_0067f4b0(int d);
};
struct FUN_00666020
{
    void* vtbl;
    int a;
    void* b;
    void RemoveAll();
    void Init();
};
struct S6
{
    short a;
    short b;
    short c;
};
struct FUN_00661d40_shell
{
    void SetVTableAndDestroy();
    void* FUN_00661d60(unsigned int);
};
extern const char* DAT_0119b49c[];
struct StatisticalArray
{
    int _pad[3];
    int m_base;
    int FUN_00662890(unsigned int);
};
unsigned int __cdecl FUN_00ec7c56();
void __cdecl Deallocate(void* p);
struct FUN_00665c80_Class
{
    void FUN_00665fc0();
    void* FUN_00665c80(unsigned int flags);
};
struct Inner0080
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
    virtual int Func(int a, int b);
};
struct FUN_00665f20_Holder
{
    Inner0080* p;
    void CallInnerFuncAndForward(int a);
};
extern int $SG6086;
struct FUN_00665f50_Class
{
    int* vtbl;
    int count;
    int* data;
    int zero;
    void* FUN_00665f50(int a);
};
struct FUN_006661b0_Class
{
    void* FUN_006661b0(unsigned int flags);
};
struct FUN_00666270_Holder
{
    void* InitAndMaybeDeallocate(unsigned int);
};
void __cdecl FUN_006665c0();
void __cdecl Deallocate(void*);
struct FUN_00666570_Class
{
    void FUN_006665c0();
    void* FUN_00666570(unsigned int flags);
};
struct T_
{
};
struct bhkCharacterController
{
    float& GetVectorElement(int);
};
struct FUN_0066c9c0_Class
{
    T_ a;
    T_ b;
    void FUN_0066c9c0(T_& x, T_& y, float f);
};
struct Date
{
    ~Date();
};
struct FUN_0066da50 : Date
{
    ~FUN_0066da50();
    void FUN_0066dab0();
};
struct H_A100
{
};
struct H_6db70
{
};
struct FUN_0066dae0_Class
{
    void* p;
    unsigned int pad;
    unsigned int state;
    void FUN_0066dae0(void* a);
};
struct FUN_0066db70_Class
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4(int, int)
    {}
    void FUN_0066db70(int a, int b);
};
void __cdecl Deallocate(void* p);
struct FUN_0066df40_Class
{
    void* FUN_0066e300(unsigned int flags);
};
struct FUN_00671a70_Class
{
    unsigned short flags;
    void FUN_00671a70(bool set);
};
struct FUN_00671ad0_Class
{
    void FUN_00671ad0(bool a);
};
struct FUN_00671b30_Class
{
    unsigned short m_0024;
    void FUN_00671b30(bool a);
};
struct FUN_00671b90_Class
{
    void FUN_00671b90(bool b);
};
struct FUN_00671bf0_Class
{
    void FUN_00671bf0(bool a);
};
struct FUN_00671c50_Class
{
    void FUN_00671c50(bool bSet);
};
struct FUN_00671cb0_Class
{
    void SetFlag20(bool b);
};
struct FUN_0067ac70_Class
{
    unsigned short wFlags;  // +0x22
    void SetFlag100(bool bSet);
};
struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    void* DestroyAndFree(unsigned int);
};
struct BGSSaveFormBuffer
{
};
struct FUNObj
{
};
struct Holder
{
    int _0;
    FUNObj* q;
    void SaveToBuffer(void*);
};
extern int DAT_010689e4;
struct FUN_0067c3f0_Class : public FUN_0067ad20_Class
{
    unsigned char b;
    unsigned char c;
    FUN_0067c3f0_Class();
};
template <int N> struct EndianSizeTag
{
};
struct FUN_0067eff0_Class
{
    void FUN_0067eff0();
};
struct FUN_0067b170
{
    int pad[4];
    unsigned char flag;
    int pad2[3];
    FUN_0067b170();
};
struct TESPackage
{
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    void* u;
    void* v;
    void* w;
    void* x;
    void* y;
    FUN_0067b170* e;
    void SetPackageFlag(bool b);
};
struct FUN_0067b100_Class
{
    unsigned char b0;
    unsigned char b4;
    unsigned char b0c;
    unsigned char b14;
    void FUN_0067b100();
};
struct bhkConvexShape
{
    bhkConvexShape();
    ~bhkConvexShape();
};
extern int DAT_01066e2c;
struct FUN_0066d6a0 : bhkConvexShape
{
    int* vtbl;
    FUN_0066d6a0(int a);
};
struct GlobalObject_0045cfe0
{
};
struct Pair8
{
    GlobalObject_0045cfe0* a;
    GlobalObject_0045cfe0* b;
};
struct FUN_00672c40_Class
{
    void SetExtraValue(float value);
};
struct ListX
{
    ~ListX();
};
struct PackageList : ListX
{
    void ClearPackageList();
    ~PackageList();
};
struct FUN_0067e3a0_Class : PackageList
{
    ~FUN_0067e3a0_Class();
};
// @fnv 0x00660400
template <class T> struct BSSimpleList;
BSSimpleList<int>* FUN_00660400(BSSimpleList<int>* a)
{
    return ((::BSSimpleList<int> *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
}
struct AutoMemHelper
{
    int pad;
    AutoMemHelper(int context, bool flag, const char* file, int line);
    ~AutoMemHelper();
};
struct FUN_0044d000
{
    int pad[9];
    FUN_0044d000(int a, int b, int c, int d);
};
struct FUN_00665e30_Class
{
    int pad;
    int* data;
    FUN_0044d000* FUN_00665e30(int index);
};
struct DetectionViewData;
struct List_009e03e0
{
    void* padding[2];

    void RemoveAll();
};
struct G2 : public List_009e03e0
{
    void AddHead(DetectionViewData** value);
    bool IsEmpty();
};
struct SL : public G2
{
    SL();
};
struct BGSLoadFormBuffer
{
};
struct BGSLoadGameBuffer : public BGSLoadFormBuffer
{
};
struct DetectionViewData
{
    void* formId;
    SL* list;
    unsigned char data[12];
    unsigned int value;
    int padding[3];

    DetectionViewData();
    void FUN_0066e440(BGSLoadGameBuffer* buffer);
};
struct FUN_0067caa0
{
    int m_auiShapeKeys[9];

    FUN_0067caa0();
};
struct FUN_00672d10_Class
{
    unsigned char m_auiShapeKeys[0x28];
    FUN_0067caa0* m_pObject;

    FUN_0067caa0* FUN_00672d10();
};
struct C0130Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};
struct C0130ScalarPtrTag
{
};
struct C0130RangeCheckedTag
{
};
struct C0190Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};
struct C0190ScalarPtrTag
{
};
struct C0190RangeCheckedTag
{
};
struct C6602B0Entry
{
    short m_sA;
    short m_sB;
    short m_sC;
};
struct SpawnedFlagBox
{
    bool v;
};
// @fnv 0x006603a0
extern "C" void __cdecl FUN_006603a0(void* a, void* b, void* c, void* d)
{
    SpawnedFlagBox flagA3 = {};
    bool flagB;
    flagB = ((bool)(::FUN_0065e750(&a, &c)));
    ::std6605::CopyConstructRange((::Elem6605 *)(void *)(((void *)(::CallWithFlag((int *)(void *)(&a))))), (::Elem6605 *)(void *)(((void *)(::CallWithFlag((int *)(void *)(&b))))), (::Elem6605 *)(c), (*(::Alloc6605 *)(d)), (::NonscalarTag6605)(flagB), (::CheckedTag6605)(flagA3.v));
}

// std::_Construct for a 0x58-byte element: copy-construct in place.

struct C60490Element
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

    C60490Element(const C60490Element& kOther);
};
struct FUN_006665c0_Item
{
    int unk00;
    int unk04;
};
struct FUN_006665c0_Entry
{
    int unk00;
    FUN_006665c0_Item* m_item;
};
struct FUN_006665c0_cls
{
    int unk00;
    void* m_04;
    FUN_006665c0_Entry* m_08;

    void FUN_006665c0();
};
extern unsigned char g_counter;
struct FUN_0066ca50_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;
    int unk53;
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    int unk58;
    int unk59;
    int unk60;
    float m_f4;

    bool FUN_0066ca50(float dt);
};
struct SpawnedObject
{
    int GetRefPtr();
};
float __cdecl FUN_0066dc70(int a);
struct S_0066e2b0_Class : public FUN_0066df40_Class
{
    void FUN_0066e2b0();
};
struct G2;
struct SaveBufCls
{
};
struct SaveItemCls
{
};
struct SaveNodeCls
{
};
struct DetClassCls
{
    void* m_00;
    SaveNodeCls* m_04;
    unsigned char m_08[12];
    unsigned int m_14;
    void WriteToSaveBuffer(SaveBufCls* buffer);
};
class StatsGetterCls
{
  public:
};
struct SpawnedFlag
{
    bool m_bValue;
};
struct FUN_0067ca10_cls
{
    void FUN_0067ca10();
};
// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.
class F5FC0MapBase
{
  public:
    virtual ~F5FC0MapBase();
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00665fc0 : public F5FC0MapBase
{
  public:
    virtual ~FUN_00665fc0();
};
// Forward the position for the given key (obtained through a stateless helper) to the erase routine.
class D9B0Container;
struct D9B0Locate
{
};
class D9B0Container
{
  public:
    void EraseByKey(int iKey);
};
// Save: write the header value, every queued item, then patch the item count in at the reserved position.
class E6D0SaveBuffer;
class E6D0Item
{
  public:
};
class E6D0Node
{
  public:
};
class E6D0SaveBuffer
{
  public:
};
struct ComparisonEntry
{
};
struct ComparisonOwner
{
    int CompareTo(ComparisonEntry* other);
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class Actor : public TESForm
{
};
struct E640Item
{
};
struct E640Cls : DetClassCls
{
    void FUN_0066e640(SaveBufCls* buffer);
};
struct S_00660510_Context
{
};
struct Elem6605
{
    char m_data[0x58];
};
struct Alloc6605
{
};
struct NonscalarTag6605
{
};
struct CheckedTag6605
{
};
namespace std6605 {
// @fnv 0x006605d0
Elem6605* __cdecl CopyConstructRange(Elem6605* _First, Elem6605* _Last, Elem6605* _Dest, Alloc6605& _Al,
                                     NonscalarTag6605, CheckedTag6605)
{
    Elem6605* _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
            reinterpret_cast<::FUN_00660320_Class *>(&(_Al))->FUN_00660320((int)(_Dest), (int)&(*_First));
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            reinterpret_cast<::FUN_0065ea60_cls *>(&(_Al))->FUN_0065ea60(_Next);
        throw;
    }
    return _Dest;
}
}

float __cdecl FUN_0066dc70(int value);
struct Vector3
{
    float x;
    float y;
    float z;
};
struct SaveNodeExtended : SaveNodeCls
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    ~SaveNodeExtended();
};
struct DetClassExtended : DetClassCls
{
    void ClearAndReset();
};

struct DetectionEntry
{
    unsigned int key;
};
struct DetectionEntryList
{
    DetectionEntry* item;
    DetectionEntryList* next;
};
struct DetectionGroup
{
    unsigned int owner;
    DetectionEntryList* entries;
};
// @fnv 0x0066e100
void __cdecl FUN_0066e100(unsigned int key)
{
    G2* node = &(*reinterpret_cast<::G2 *>(&::g_011d6124));
    while (node && !node->IsEmpty())
    {
        DetectionGroup* group = ((::DetectionGroup *)(new ((void *)(node)) ::Vec3()));
        node = ((::G2 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (group && reinterpret_cast<::FUN_005ca4f0_shell *>((group))->FUN_005ca4f0())
        {
            if (((unsigned int)(::FUN_00559450((int *)(group)))) == key)
                reinterpret_cast<::DetClassExtended *>((group))->ClearAndReset();
            DetectionEntryList* child = ((::DetectionEntryList *)(reinterpret_cast<::Callees *>((group))->FUN_00726070()));
            bool removed = false;
            while (!removed && child && ((::DetectionEntry *)(new ((void *)(child)) ::Vec3())))
            {
                DetectionEntry* entry = ((::DetectionEntry *)(new ((void *)(child)) ::Vec3()));
                child = ((::DetectionEntryList *)(reinterpret_cast<::Callees *>((child))->FUN_00726070()));
                if (entry->key == key)
                {
                    reinterpret_cast<::ItemChangeListNode *>((((::DetectionEntryList *)(reinterpret_cast<::Callees *>((group))->FUN_00726070()))))->FUN_00905330((::InventoryStackRecord *const &)(entry));
                    delete entry;
                    removed = true;
                }
            }
        }
    }
}
