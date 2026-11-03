
// src/staging/blk_00460000_od_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm). The skeleton of src/staging/blk_00460000_od.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/staging/blk_00460000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <cstdint>
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDebris_shell2.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ExtraListHelper.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0041b6b0_shell.h"
#include "fnv/decl/FUN_0042e150_StandIn.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00470650_shell.h"
#include "fnv/decl/FUN_00471130_shell.h"
#include "fnv/decl/FUN_00471a10_shell.h"
#include "fnv/decl/FUN_00472150_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004746d0.h"
#include "fnv/decl/FUN_00480d90_shell.h"
#include "fnv/decl/FUN_0049fa20_List.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_008d85e0_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00c455a0_cls.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/HealthHandler.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder42.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESObjectARMO.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WorldData.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_00470550__FUN_00470550_t.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00474880__FUN_00474880.h"
#include "fnv/decl/fnv_00474a40__FUN_00474a40_shell.h"
#include "fnv/decl/fnv_0047d680__FUN_0047d680_shell.h"
#include "fnv/decl/fnv_0047e2a0__FUN_0047e2a0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0087b0f0__FUN_0087b0f0_shell.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00474000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00477000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_0047b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00486000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_006f9000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_009ac000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "../../include/layout_support.h"
struct FUN_004600f0_class
{
    unsigned char GetByteAt618();
};
struct FUN_00460fb0_class
{
    void* FUN_00460fb0();
};
struct FUN_00460fd0_class
{
    void* FUN_00460fd0();
};
struct FUN_004610f0_Class
{
    void* GetOffset70Ptr();
};
struct FUN_00462e60_Class
{
    void SetByteAt428(unsigned char value);
};
struct FUN_00464f40_class
{
    void FUN_00470110();
    void FUN_00464f40();
};
struct NavMesh
{
    NavMesh* FUN_00464ff0(int);
};
struct FUN_0046dcc0_class
{
    void SetByteAtOffsetF4(unsigned char param);
};
struct FUN_0046dce0_class
{
    void FUN_0046dce0(float value);
};
void __cdecl FUN_00ec825b(char* p, unsigned int a, char const* b, char const* c, char const* d, char const* e);
struct FUN_0046e880_Class
{
    void SetByteField(int value);
};
struct FUN_0046e8c0_class
{
    bool FUN_0046e8c0();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_0046eb00_Class
{
    unsigned int GetSecondElement();
};
struct FUN_0046ebf0_Class
{
    unsigned short GetMaskedShifted(unsigned short a, unsigned short b);
};
struct FUN_0046fdf0_class
{
    int GetZero();
};
struct FUN_0046fe90_Class
{
    bool HasFlag(signed char flag);
};
extern int DAT_01019a1c;
struct FUN_00470040_class
{
    int m_vft;
    void FUN_004704e0(int a, int b);
    FUN_00470040_class(int a, int b);
};
extern int DAT_01019a2c;
struct FUN_004700a0
{
    void* vtbl;
    FUN_004700a0(int a, int b);
};
struct FUN_004705c0_cls
{
    void* FUN_004705c0();
};
struct FUN_00471110_Class
{
    void SetField3DC(float value);
};
struct FUN_00471de0_class
{
    bool FUN_00471de0();
};
struct P03MM
{
};
struct ActorCombatGroup;
struct NiTMallocInterface_StandIn
{
};
struct FUN_00474760_This
{
    const char* p;
    ActorCombatGroup* q;
    void FUN_00474760();
};
extern "C" void* DAT_0101a3b8;
struct BFC_s
{
    BFC_s();
};
struct FUN_008c6060_shell
{
    void FUN_008c6060();
};
struct FUN_004748f0 : BFC_s
{
    void* vtbl;
    FUN_004748f0();
};
struct FUN_00475a90_cls
{
    bool IsFlag2Set();
};
struct FUN_00476a00_cls
{
    bool FUN_00476a00();
};
struct FUN_00476a20_Class
{
    bool IsFlag4Set();
};
struct FUN_00476ae0_class
{
    void SetTaskFlag(bool a);
    void FUN_00476ae0(bool a);
};
struct TaskQueueInterface
{
    void SetTaskFlag(bool enabled);
public:
    static ::TaskQueueInterface *GetSingleton();
};
struct MersenneTwister
{
    unsigned int GetRandomUInt(unsigned int);
};
struct FUN_00476be0_Class
{
    unsigned int FUN_00476be0();
};
struct FUN_00476c70_Class
{
    void FUN_00476c70(int value);
};
struct FUN_00476c90_Class
{
    unsigned int FUN_00476c90();
};
struct FUN_004791f0_holder
{
};
extern int DAT_0101a8fc;
struct FUN_00479190_holder
{
    int m_iWordAt00;
    FUN_00479190_holder* Construct(int a);
};
struct FUN_00573eb0_Class
{
    int FUN_0047b4b0();
};
struct FUN_0047b4d0_Class
{
    bool FUN_0047b4d0(unsigned short flags);
};
struct S47
{
    void FUN_0047dea0(short);
};
struct FUN_0047ebb0_Class
{
    void FUN_0047ebb0(int value);
};
struct FUN_0047ebd0_Class
{
    void FUN_0047ebd0(bool value);
};
struct FUN_0047ff50_class
{
    void FUN_0047ff50(unsigned short value);
};
extern void* DAT_0101a364;
struct FUN_00474630 : public NiTPointerMap<int, int>
{
    void FUN_00474631();
};
extern int DAT_0101a91c;
struct FUN_004792c0_Class : NiTPointerMap<int, int>
{
    void FUN_004792c0();
};
struct FUN_0045d930_class
{
    void FUN_0046ffd0();
    void* FUN_00470320(unsigned int flags);
};
struct FUN_0045d950_Class
{
    void FUN_00470070();
    void* FUN_00470380(unsigned int flags);
};
struct FUN_004703e0_class : public FUN_00464f40_class
{
    void* FUN_004703e0(unsigned int flags);
};
struct FUN_00470410_class : public FUN_00464f40_class
{
    void* FUN_00470410(unsigned int flags);
};
struct FUN_004746d0_Class
{
    void* FUN_00474530(unsigned int flags);
};
struct FUN_004747c0_Class : public FUN_00474630
{
    void* FUN_004747c0(unsigned int flags);
};
void FUN_00474730();
struct FUN_004747f0_class
{
    void FUN_00474730();
    void* FUN_004747f0(unsigned int flags);
};
struct FUN_00473f00_class
{
    void ForwardToHolder();
};
struct FUN_00474850_class : public FUN_00473f00_class
{
    void* FUN_00474850(unsigned int flags);
};
struct FUN_004752e0_Class
{
    void* FUN_004752e0(unsigned int flags);
};
struct FUN_00479140_class
{
    void FUN_00479140();
};
struct FUN_00479160_class
{
    void* FUN_00479160(unsigned int flags);
};
struct FUN_004792f0_Class : FUN_004792c0_Class
{
    void* FUN_004792f0(unsigned int flags);
};
struct BGSImpactDataSet
{
    static BGSImpactDataSet* ms_pImpactDataSet;
};
BGSImpactDataSet* BGSImpactDataSet::ms_pImpactDataSet;
struct BGSEncounterZone
{
};
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned int*, EndianSizeTag<3>);
struct S_00462230
{
    void FUN_00462230();
};
struct TlsBlock462480
{
    unsigned char pad[0x294];
    int flag;
};
__declspec(thread) TlsBlock462480 g_tls462480;
extern int __tls_index;
struct FUN_00462480_Class
{
    unsigned char FUN_00462480();
};
__declspec(thread) unsigned int TLS_PAD[166];
struct S69570
{
    unsigned char FUN_00469570();
};
struct KFModel
{
};
struct FUN_0046e8e0_This
{
    void FUN_0046e8e0(KFModel* a, int b, int c, int d, int e);
};
extern int DAT_01019a14;
// @fnv 0x0046ffd0
template <> struct NiTMallocInterface<void*>
{
};
void FUN_0045d930_class::FUN_0046ffd0()
{
    *(void**)this = (void*)&DAT_01019a14;
    ::FUN_004ede70(*(void***)((char*)this + 4));
}
struct FUN_004700d0_class : FUN_004705c0_cls
{
    void FUN_004700d0(int* p);
};
struct FUN_00471d90_class
{
    char m_auiShapeKeys[0x3e8];
    int m_flags;
    void FUN_00471d90(bool enabled);
};
struct FUN_00471e10_class
{
    void SetFlag40(bool set);
};
struct BSFile
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Seek(int, int);
    unsigned int Read(void*, unsigned int);
};
struct MyForm
{
    unsigned int uiID;
    char _rest[0x14];
};
struct Twin_008d0360
{
    bool GetBooleanValue();
};
Twin_008d0360* FUN_00471f70();
struct FUN_00471e60_shell
{
    char _pad0[0x10];
    BSFile* pFile;
    char _pad14[0x22c];
    MyForm kForm;
    char _pad258[0x41];
    bool bFlag;
    void LoadFormAndUpdateFlag();
};
struct FUN_00474500_Class
{
    void FUN_004745d0();
    void* FUN_00474500(unsigned int flags);
};
struct FUN_00474660_class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00474660_class(int n);
};
struct FUN_00474880_Helper
{
};
struct FUN_00474790_Class
{
    const char* m0;
    FUN_00474790_Class* FUN_00474790(unsigned int a, unsigned int b);
};
struct FUN_00474820_Class
{
    void* FUN_00474820(unsigned int);
};
enum ENUM_FORM_ID;
struct TESForm
{
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
public:
    ::ENUM_FORM_ID GetFormType() const;
};
struct FUN_00474a00_shell
{
    void* p;
    void* q;
    void* GetAmmoForm();
};
struct QueueObj
{
    QueueObj(int);
};
struct S751
{
    S751* Initialize();
};
struct FUN_00476a40_Data
{
    int _00;
    unsigned char count;
    unsigned char _pad[3];
    void** items;
};
struct FUN_00476a40_Holder
{
    int _00;
    FUN_00476a40_Data* data;
    void* FUN_00476a40(unsigned int index);
};
struct FUN_004781b0_This
{
    int field0;
    unsigned char field4;
    unsigned char field5;
    FUN_004781b0_This* FUN_004781b0();
};
struct FUN_00478f70_s
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned int d4;
    unsigned int d8;
    unsigned int dc;
    unsigned int d10;
    unsigned int d14;
    FUN_00478f70_s* FUN_00478f70();
};
struct AX
{
};
extern int vftable__ShadowSceneArray;
struct S
{
    void* vf;
    S* ConstructShadowSceneArray();
};
struct FUN_004791f0_holder2
{
    void* InitArrayHolder(int a);
};
struct FUN_0047b470_This
{
    bool FUN_0047b470();
};
struct Actor;
struct LH
{
    bool IsInList(Actor*&);
};
struct ScriptS
{
};
struct FUN_0047ba80_This
{
    int _0;
    ScriptS* m4;
    bool IsActorInList(Actor* actor);
};
struct FUN_0046fe10_Class
{
    int FUN_0046fe10();
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
    BSSimpleList<TESForm*>* GetNext();
};
struct TESObject
{
    unsigned int GetNext();
};
struct FUN_00474a00
{
};
struct FUN_00474a40
{
};
struct FUN_00474920_shell
{
    TESForm* GetFormOrScriptForm();
};
struct GlobalObject_00a7b610;
struct NiAVObject;
struct NiNode
{
    NiAVObject* GetAt(unsigned int);
};
struct FUN_00476ec0_Class
{
};
struct NiObject
{
    virtual ~NiObject();
    virtual void v1();
    virtual void v2();
    virtual NiNode* GetAsNode();
};
struct FUN_00478130_class
{
    void FUN_00478130();
};
struct FUN_00462e10_Class
{
    signed char m_flags;
    void SetFlags(signed char mask, bool set);
};
struct NiTMallocInterface_0096afc0
{
};
struct FUN_004704e0
{
    void* vtbl;
    ActorCombatGroup** p;
    unsigned short a;
    unsigned short c;
    unsigned short d;
    unsigned short f;
    FUN_004704e0(unsigned short x, unsigned short y);
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    char d[0x20];
};
struct FUN_00478570_holder
{
    char m_iWordAt00[0x14];
    B2_4fe* m_cByteAtOffset1;
    void EnsureB2_4fe();
};
struct FUN_0047bac0_NPC : TESForm
{
    unsigned char m_npc[0x15c];
    void* biped;
};
struct FUN_0047bac0_ARMO : TESForm
{
    unsigned char m_armor[0xbc];
    void* biped;
};
struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct TESAttackDamageForm : public BaseFormComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned short GetDamage();
    void FUN_0047fe30(BaseFormComponent* apCopyFC);
};
struct FUN_0046eb20_Class
{
    unsigned int GetElementAt2();
};
struct FUN_0046ebd0_Class
{
    unsigned int FUN_0046ebd0();
};
struct FUN_0046fdd0_Class
{
    char m_iWordAt00[0x38];
    int m_38;
    char IsFieldEqual(int param_2);
};
extern int DAT_0101a644;
struct Date
{
    virtual ~Date();
    virtual int v0();
};
struct FUN_004750e0 : Date
{
    ~FUN_004750e0();
};
struct BSSimpleArrayActor
{
    void Clear(bool);
};
struct FUN_0047bcf0_class
{
    bool IsFlag80Clear();
};
struct FUN_0047eb90_Class
{
    void FUN_0047eb90(int value);
};
class FUN_00462dc0_cls
{
  public:
    int m_00;
    int m_04;
    int(__cdecl* m_08)(FUN_00462dc0_cls* self, int a, int b, int c, int d);
    int InvokeAndAccumulate(std::intptr_t a1, int a2, int a3, int a4);
};
extern int DAT_01019a34;
struct ResourceDescriptor
{
    void* vtable;
    void* resource;
    unsigned int count;
    unsigned int capacity;
    void* manager;
    unsigned int options;

    ResourceDescriptor* FUN_004705e0(unsigned int initialCount, unsigned int initialOptions);
};
Twin_008d0360* __cdecl FUN_00471f70();
class Base_b9207
{
  public:
    virtual ~Base_b9207();
    unsigned int unk04;
    unsigned int unk08;
};
class FUN_004745d0 : public Base_b9207
{
  public:
    virtual ~FUN_004745d0();
};
struct FUN_00475220_member
{
    ~FUN_00475220_member();
};
struct FUN_00475220
{
    int unk00;
    unsigned char ucCount;
    FUN_004752e0_Class** ppItems;
    int unk0C;
    FUN_00475220_member member;
    ~FUN_00475220();
};
class FUN_00475310_obj
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual int vSlot10(int arg);
};
class FUN_00475310_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00475310_obj* m_14;

    void FUN_00475310();
};
struct InstanceData36
{
    unsigned int values[9];
};
struct InstanceData12
{
    unsigned int values[3];
};
struct OutputRenderer
{
};
struct ChildRange;
struct CollectionItem
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual ChildRange* GetChildren();
};
struct ChildRange
{
};
struct ActorProcessor
{
    int ProcessCollectionTree(CollectionItem*, int, unsigned int, OutputRenderer*);
};
struct NodeChildren;
struct Node
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual NodeChildren* GetChildren();
};
struct NodeChildren
{
};
struct Context
{
};
struct Receiver
{
};
struct Walk
{
    int WalkTree(Node* node, Receiver* receiver, unsigned int mode, Context* context, void* extra);
};
struct FUN_00477090_Sound;
struct FUN_00477090_Space;
struct FUN_00477090_Handle
{
};
struct FUN_00477090_Ref
{
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
    virtual void v180();
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
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void RefreshSound(int a, int b);
};
struct FUN_00477090_Stage
{
    unsigned char unk00;
    unsigned char percent;
    unsigned char unk02;
    unsigned char unk03;
    int value;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00477090_Sound* sound;
};
struct FUN_00477090_Data
{
    unsigned int total;
    unsigned char count;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    FUN_00477090_Stage** stages;
};
struct FUN_00477090_Owner
{
    int unk00;
    FUN_00477090_Data* data;
    void UpdateSoundLevel(FUN_00477090_Ref* ref);
};
struct FUN_00477230_owner
{
};
struct FUN_00477230_item
{
};
struct FUN_00477230_arg
{
};
struct FUN_00477230_node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual FUN_00477230_item* v0c();
};
struct FUN_00477230_cls
{
    void FUN_00477230(FUN_00477230_node* node, FUN_00477230_arg* arg);
};
class FnvShapeObject
{
  public:
};
struct FnvShapeEntry
{
    unsigned char unk00;
    unsigned char m_b01;
    unsigned short unk02;
    unsigned int unk04;
    FnvShapeObject* m_obj08;
};
struct FnvShapeList
{
    unsigned int unk00;
    unsigned char m_count04;
    unsigned char unk05;
    unsigned short unk06;
    FnvShapeEntry** m_entries08;
};
class FUN_00477970_cls
{
  public:
    unsigned int unk00;
    FnvShapeList* m_list04;
    float FindShapeByThresholds(unsigned char a1, float a2, float a3, FnvShapeObject** out);
};
struct ManagedSceneEntry
{
    unsigned int state;
    unsigned int identifier;
    unsigned int priority;
    unsigned int flags;
    unsigned int timestamp;

    __forceinline ManagedSceneEntry()
    {
        reinterpret_cast<S751*>(this)->Initialize();
    }
};
struct ManagedSceneHolder
{
    unsigned int mode;
    ManagedSceneEntry* current;
    void EnsureCurrentEntry();
};
struct SpawnedItem_b10003
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    SpawnedItem_b10003();
};
struct FUN_00478e90_This
{
    int unk00;
    SpawnedItem_b10003** AllocateSpawnedItemArray(unsigned char count);
};
struct FUN_0048a3d0;
typedef void(* CopyMethod)(FUN_0048a3d0*, const FUN_0048a3d0*);
typedef void*(* ReleaseMethod)(FUN_0048a3d0*, int);
struct EffectMethods
{
    void* unk00;
    void* unk04;
    CopyMethod copy08;
    void* unk0c;
    ReleaseMethod release10;
};
struct FUN_0048a3d0
{
    EffectMethods* methods;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_0048a3d0();
};
struct CopyInterface
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void CopyFrom(const FUN_0048a3d0* other);
};
struct EffectData
{
    unsigned char flags00;
    unsigned char flags01;
    unsigned char flags02;
    int count04;
    int count08;
    int count0c;
    int count10;
    FUN_0048a3d0* effect14;
    void FUN_00478fd0(const EffectData* source);
};
class B479260MapBase
{
  public:
    virtual ~B479260MapBase();
    int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
};
class FUN_00479260_Map : public B479260MapBase
{
  public:
    virtual ~FUN_00479260_Map();
    void RemoveAll();
};
class BGSChangeFlags47E
{
  public:
    BGSChangeFlags47E(unsigned int uiFlags);

    unsigned int m_uiValue1;
};
class BGSLoadFormBuffer47E
{
  public:
};
class TESActorBaseData47E
{
  public:
    void FUN_0047ea70(BGSLoadFormBuffer47E* pkBuffer);

    int unk00;
    int m_iFlags;
};
struct FUN_0047ead0_cls
{
    void FUN_0047ead0(int mode);
};
struct FUN_0047fe80_class : BaseFormComponent
{
    virtual void FUN_0047fe80_v1();
    virtual void FUN_0047fe80_v2();
    virtual void FUN_0047fe80_v3();
    virtual unsigned short GetAttackDamage();
    bool IsAttackDamageDifferent(BaseFormComponent* other);
};
struct Standin77900
{
    float FUN_00477900();
};
class PathingRequest
{
  public:
public:
    float GetTargetRadius();
};
struct FUN_00477a50_Entry
{
    char cType;
    unsigned char ucHour;
    char pad02[2];
    unsigned int ItemUpdateArray;
    Standin77900* pData;
};
struct FUN_00477a50_Table
{
    unsigned int uiTotal;
    unsigned char ucEntries;
    char pad05[3];
    FUN_00477a50_Entry** ppEntries;
};
struct FUN_00477a50_shell
{
    void* vtbl;
    FUN_00477a50_Table* pSearchEntries;
    float GetHourlyWeightedTime(unsigned char aucHour, float afMin, float afMinB, Standin77900** appData);
};
struct CopyStage
{
    ~CopyStage();
};
struct DestructionData
{
    unsigned int health;
    unsigned char count;
    unsigned char flags;
    unsigned short unk06;
    CopyStage** stages;
    unsigned int unk0c;
    unsigned int unk10;
    DestructionData();
    ~DestructionData();
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    DestructionData* data;
    void FUN_004786e0(BaseFormComponent* source);
};
struct NiFixedString_47ab40
{
    operator const char*() const;
};
struct NamedObject_47ab40
{
};
union SETTING_VALUE_47ab40
{
    bool b;
    int i;
};
struct Setting_47ab40
{
    SETTING_VALUE_47ab40* Bool();
};
int FUN_00ec6da0(const char*, const char*);
struct NiNode_47ab40;
struct World_47ab40
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void AddObject(NiNode_47ab40* node, bool a, bool b, int c, int d);
};
struct Cell_47ab40;
struct TaskQueue_47ab40
{
};
struct Ref_47ab40
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual NiNode_47ab40* Get3D();
};
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    bool multithread;
    NiUpdateData(float, bool, bool);
};
class NN_00605d70
{
  public:
};
template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer(NiNode* object);
    ~NiPointer();
    operator NiNode*() const;
};
struct RefWithGetNiNode
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual NiNode* GetNiNode();
};
struct ItemForm
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual bool IsQuestItem();
};
struct ActorStub;
struct ScriptOwnerStub
{
};
struct WeapStub : ItemForm
{
    int GetWeaponType();
};
struct BipedFlagsStub
{
    int flags;
};
struct ListStub
{
    void* item;
    ListStub* next;
};
struct ArmorStub : ItemForm
{
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
    BipedFlagsStub bipedModel;
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
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    ListStub list154;
};
struct PlayerStub;

// FUN_00461cf0 (0x00461cf0, 1340 bytes) -- TESFile record scan.
// Vtable-free; member of the file-list holder (count at +0x218, array at +0x21c).
class TESWorldSpace;

struct TESRecordHeader
{
    unsigned int type;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
};

class TESFile
{
  public:
    bool GetOptimizedFile();
    TESRecordHeader* GetRecordHeader();
    bool FUN_00470c70(int, int);
    bool IsEndianConversionRequired();
public:
    bool NextChunk();
public:
    unsigned char GetFileCompileIndex();
public:
    bool IsGroupOpen();
};

// XCLC chunk payload: two dwords swapped by the endian pass plus a trailing bool.
struct XCLC
{
    unsigned int x;
    unsigned int y;
    unsigned char z;
    XCLC();
};

class AutoMemContext
{
  public:
    int m0;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};

class VoiceStr
{
  public:
    bool FUN_008256d0();
};

class DialogueResponse
{
  public:
};

struct FUN_00585940_shell
{
};

struct TESWorldSpace : TESForm
{
  public:
    virtual ~TESWorldSpace();
};


extern "C" char DAT_010186b8[];

struct TESFileArray
{
    char pad[0x218];
    unsigned int mCount;
    TESFile* mFiles[1];
    int FUN_00461cf0(char*, int*, int*);
};

// @fnv 0x00461cf0
int TESFileArray::FUN_00461cf0(char* name, int* out1, int* out2)
{
    AutoMemContext ctx(0x16, true, (char*)DAT_010186b8, 0x1041);
    int result = 0;
    *out1 = 0;
    *out2 = 0;
    if (name && *name)
    {
        bool found = false;
        for (unsigned int i = 0; i < mCount; i++)
        {
            if (mFiles[i] && mFiles[i]->GetOptimizedFile())
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            VoiceStr* p = ((::VoiceStr *)(::FUN_00460140((int)((*reinterpret_cast<::DialogueResponse * *>(&::g_dataHandler))))));
            while (p && !p->FUN_008256d0())
            {
                void* v = *((void **)(new ((void *)(p)) ::Vec3()));
                p = ((::VoiceStr *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
                if (reinterpret_cast<::WorldData *>((((FUN_00585940_shell*)v)))->FindCellByEditorID(name, out1, out2))
                {
                    result = (int)v;
                    break;
                }
            }
        }
        else
        {
            for (unsigned int j = 0; j < mCount; j++)
            {
                TESFile* f = mFiles[j];
                if (f && f->FUN_00470c70(0, 0))
                {
                    TESRecordHeader* hdr = f->GetRecordHeader();
                    bool got = false;
                    while (hdr && !got)
                    {
                        bool read = false;
                        if (hdr->type == (unsigned int)(*reinterpret_cast<int *>(&::fnv_00543df0::kGroupFormType)))
                        {
                            if (hdr->fC == 0 && hdr->f8 == (unsigned int)(*reinterpret_cast<int *>((void *)&::fnv_00543f50::str_01187314)))
                            {
                                got = true;
                                read = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                            }
                            else
                            {
                                read = f->IsGroupOpen();
                            }
                        }
                        else
                        {
                            read = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                        }
                        if (read)
                            hdr = f->GetRecordHeader();
                        else
                            hdr = 0;
                    }
                    if (got)
                    {
                        hdr = f->GetRecordHeader();
                        got = false;
                        while (hdr && !got)
                        {
                            bool read2 = false;
                            if (hdr->type == (unsigned int)(*reinterpret_cast<int *>((void *)&::fnv_00543f50::str_01187314)))
                            {
                                unsigned int id = hdr->fC;
                                unsigned int hi = id >> 24;
                                TESFile* w = reinterpret_cast<::FUN_00471a10_shell *>((f))->GetFileByIndex(hi + 1);
                                if (!w)
                                    w = f;
                                id &= 0xffffff;
                                id |= (unsigned int)(unsigned char)w->GetFileCompileIndex() << 24;
                                result = (int)dynamic_cast<TESWorldSpace*>(::FUN_004839c0(id));
                                read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                            }
                            else if (hdr->type == (unsigned int)(*reinterpret_cast<int *>(&::DAT_011872b4)))
                            {
                                int chunk = reinterpret_cast<::FUN_004726b0_class *>((f))->FUN_004726b0();
                                if (chunk == 0x44494445)
                                {
                                    unsigned int len = reinterpret_cast<::FUN_00401660_Class *>((f))->GetField25C() + 1;
                                    char* ptr = (char*)::FUN_00401000(len);
                                    ::FUN_00403d30(ptr, 0, len);
                                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((f))->FUN_00472890((char *)(ptr), 0);
                                    if (FUN_00404dc0(ptr, name) == 0)
                                    {
                                        got = true;
                                        while (chunk)
                                        {
                                            if (chunk == 0x434c4358)
                                            {
                                                XCLC v;
                                                ::FUN_00403d30(&v, 0, sizeof(v));
                                                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((f))->FUN_00472890((char *)(void *)(&v), sizeof(v));
                                                if (f->IsEndianConversionRequired())
                                                    reinterpret_cast<::S_00462230 *>(&(v))->FUN_00462230();
                                                *out1 = v.x;
                                                *out2 = v.y;
                                                chunk = 0;
                                            }
                                            else if (f->NextChunk())
                                            {
                                                chunk = reinterpret_cast<::FUN_004726b0_class *>((f))->FUN_004726b0();
                                            }
                                            else
                                            {
                                                chunk = 0;
                                            }
                                        }
                                    }
                                    FUN_00401030(ptr);
                                }
                                read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                            }
                            else
                            {
                                bool flag = false;
                                if (hdr->type == (unsigned int)(*reinterpret_cast<int *>(&::fnv_00543df0::kGroupFormType)))
                                {
                                    switch (hdr->fC)
                                    {
                                    case 0:
                                        if (hdr->f8 == (unsigned int)(*reinterpret_cast<int *>((void *)&::fnv_00543f50::str_01187314)))
                                        {
                                            read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                                            flag = true;
                                        }
                                        else
                                        {
                                            unsigned char c = (unsigned char)FindFormEnumIndex(hdr->f8);
                                            if (c > 0x41)
                                            {
                                                read2 = false;
                                                flag = true;
                                            }
                                        }
                                        break;
                                    case 1:
                                    case 4:
                                    case 5:
                                        read2 = reinterpret_cast<::FUN_00472150_shell *>((f))->FUN_00472150(true);
                                        flag = true;
                                        break;
                                    case 6:
                                        read2 = f->IsGroupOpen();
                                        flag = true;
                                        break;
                                    }
                                }
                                if (0)
                                {
                                }
                            }
                            if (read2)
                                hdr = f->GetRecordHeader();
                            else
                                hdr = 0;
                        }
                    }
                    reinterpret_cast<::FUN_00471130_shell *>((f))->FUN_00471130();
                    if (!got)
                        result = 0;
                    else
                        break;
                }
            }
        }
    }
    return result;
}

#include "generated/data/staging/blk_00460000_od_rtti_variant.inc"
