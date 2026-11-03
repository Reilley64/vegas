
// src/staging/blk_00420000_od_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm). The skeleton of src/staging/blk_00420000_od.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/staging/blk_00420000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <new>
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0040fe80_shell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_0042e010_ExtraLock.h"
#include "fnv/decl/FUN_00435de0_ctor.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_0049fa20_List.h"
#include "fnv/decl/FUN_004fbf00_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00761540_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00898280.h"
#include "fnv/decl/FUN_00935ae0_t.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/Holder0042f780.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_0066e2b0_Class.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaitableObject.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00420440__FUN_00420440_shell.h"
#include "fnv/decl/fnv_00422c20__FUN_0042dec0_shell.h"
#include "fnv/decl/fnv_00436180__FUN_00436180.h"
#include "fnv/decl/fnv_004363c0__FUN_004363c0.h"
#include "fnv/decl/fnv_004364e0__FUN_004364e0.h"
#include "fnv/decl/fnv_00436600__FUN_00436600.h"
#include "fnv/decl/fnv_004385f0__FUN_004385f0_Class.h"
#include "fnv/decl/fnv_00438780__NiTPointerMap_00438780.h"
#include "fnv/decl/fnv_00439390__NiObjectNET.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00565480__RefPersistsStandin.h"
#include "fnv/decl/fnv_00569880__FUN_00569880_cls.h"
#include "fnv/decl/fnv_00575700__RefrV.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00433000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_00439000.h"
#include "fnv/symbols_0043a000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005f3000.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "../../include/layout_support.h"
struct BaseExtraList
{
};
struct FUN_004216d0_shell
{
    bool FUN_004216d0();
};
struct FUN_0042ce90_class
{
    bool FUN_0042ce90() const;
};
extern "C" void* __cdecl DAT_010159e8;
struct FUN_0042f4e0_class
{
    void* m_vtbl;
    void* FUN_0042f4e0(void* arg);
};
struct FUN_0042ff10_cls
{
    void FUN_0042ff30(int);
};
extern int DAT_01015a08;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_0042ff80();
};
extern void* DAT_01015968;
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_00435ef0 : public BSExtraData
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    void FUN_00435ef0_init();
};
struct FUN_006815c0
{
};
struct FUN_00437dd0_Class
{
    void* FUN_00437dd0();
};
extern int DAT_01015fbc;
struct FUN_004383b0_Class
{
    void* p;
    void* FUN_004383b0(void* a);
};
extern char DAT_01015fdc;
struct FUN_004383e0_class
{
    void* p;
    void* FUN_004383e0(void* a);
};
struct AX
{
    AX* FUN_00438570();
};
extern int DAT_01016010;
struct BSSimpleArrayShell
{
    void FUN_00438a60(unsigned int, unsigned int);
    BSSimpleArrayShell* FUN_004385c0();
};
struct FUN_00438940_Class
{
    void FUN_00438940(void* p);
};
struct FUN_00438b90_class
{
    char FUN_00438b90();
};
struct FUN_00591300_shell
{
    void FUN_00591300();
};
struct FUN_00438bf0_shell : FUN_00591300_shell
{
    void FUN_00438bf0();
};
struct FUN_00438f10_Class
{
    bool FUN_00438f10();
};
struct FUN_00438f30_Class
{
    unsigned int FUN_00438f30();
};
struct FUN_004392c0_shell
{
    void FUN_004392c0();
    void FUN_00439320();
};
struct NiObjectNET
{
    void FUN_00439360(unsigned short a, unsigned int b, unsigned int c);
    void FUN_00439340(unsigned short a);
public:
    void SetFlags(unsigned short);
};
struct NiPoint3
{
    float x, y, z;
};
struct FUN_00439680_class
{
    void FUN_00439680(const NiPoint3& p);
};
struct FUN_0043b260_Class
{
    unsigned short m_0018;
    bool FUN_0043b260(unsigned short* pArg);
};
struct TaskQueueInterface
{
    void FUN_0043b350(bool enabled);
};
struct TESForm
{
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
};
struct TESObjectTREE
{
};
struct FUN_0043b5b0_shell
{
    void FUN_0043b5b0();
};
struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(FUN_0043ba10_shell*);
};
struct FUN_0043b9f0_shell
{
    void FUN_0043b9f0(FUN_0043ba10_shell* p);
};
struct GO
{
    void* operator=(void*);
};
struct FUN_0043baa0_class
{
    void FUN_0043baa0(void* p);
};
struct FUN_0043fab0_class
{
    bool FUN_0043fab0();
};
extern int DAT_01015a1c;
struct FUN_0042fee0_cls : NiTPointerMap<int, int>
{
    void FUN_0042fee0();
};
extern int DAT_01015f24;
struct BE
{
    BE(unsigned char);
};
struct FUN_00436ac0 : BE
{
    FUN_00436ac0();
};
struct NavMeshPtr
{
    void* FUN_0042ffa0(unsigned int flags);
};
struct FUN_0042ffd0_cls : public FUN_0042fee0_cls
{
    void* FUN_0042ffd0(unsigned int flags);
};
struct FUN_00435ec0 : public BE
{
    void* vtbl;
    int a;
    int b;
    void* p;
    FUN_00435ec0(void* a);
};
struct FUN_00435f20_class : public BE
{
    const char* m_pName;
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    float m_fValue;
    FUN_00435f20_class(float f);
};
struct FUN_00435f80_shell
{
    void FUN_00435f80();
};
struct FUN_00435f50_class : FUN_00435f80_shell
{
    void* FUN_00435f50(unsigned int flags);
};
extern "C" void* DAT_01015974;
struct FUN_00436090 : public BE
{
    void* vtbl;
    int a;
    int b;
    unsigned char c;
    FUN_00436090(unsigned char);
};
struct FUN_00436150_Class
{
    void* FUN_00436150(unsigned int flags);
};
struct FUN_00436390_Class
{
    void* FUN_00436390(unsigned int flags);
};
struct FUN_004364b0_Class
{
    void* FUN_004364b0(unsigned int flags);
};
struct FUN_004365d0_class
{
    void* FUN_004365d0(unsigned int flags);
};
void FUN_00436720();
struct FUN_004366f0_class
{
    void FUN_00436720();
    void* FUN_004366f0(unsigned int flags);
};
void FUN_00436bb0();
struct FUN_00436af0_Class
{
    void FUN_00436bb0();
    void* FUN_00436af0(unsigned int flags);
};
void __cdecl FUN_00438720(FUN_004383b0_Class*);
struct FUN_00438410_Class
{
    void* FUN_00438720();
    void* FUN_00438410(unsigned int flags);
};
struct FUN_004388a0_Class
{
    void* FUN_004388a0();
};
struct FUN_00438440_Class
{
    void* FUN_00438440(unsigned int flags);
};
void FUN_004385a0();
struct FUN_00438970_class
{
    void FUN_004385a0();
    void* FUN_00438970(unsigned int flags);
};
struct FUN_004389a0_Class
{
    void* FUN_004389a0(unsigned int flags);
};
struct FUN_00438780_Class
{
    void* FUN_00438a00(unsigned int flags);
};
struct FUN_00438900_class
{
    void FUN_00438900();
};
struct FUN_00438a30_class
{
    void* FUN_00438a30(unsigned int flags);
};
struct PointerFlagNode
{
};
struct FUN_004207e0Class
{
    PointerFlagNode* FUN_004207e0();
    void FUN_00420da0(unsigned int);
};
struct Flt
{
    operator unsigned int();
};
struct Holder00420dd0
{
    unsigned int FUN_00420dd0();
};
struct FUN_0042cba0_class : public BE
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    FUN_0042cba0_class();
};
struct FHolder_42cbe0 : BE
{
    void* FUN_0042cbe0();
};
struct FUN_0042cc10_class
{
    int m0;
    int m4;
    float m8;
    FUN_0042cc10_class* FUN_0042cc10();
};
struct FUN_00432470 : public BSExtraData
{
    int x;
    int y;
    int z;
    FUN_00432470(int v);
    ~FUN_00432470();
};
struct ExtraListHelper
{
};
struct FUN_0042dee0_shell
{
    void FUN_0042dee0(int v);
};
struct ExtraDataList
{
};
struct ExtraLock
{
    ~ExtraLock();
};
struct FUN_0042df90_shell
{
    ExtraLock* FUN_0042df90(int a);
};
struct FUN_0042e210_Class : public BE
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    FUN_0042e210_Class(int x, int y);
};
extern void* DAT_010159bc;
struct FUN_0042e650_class : BE
{
    void* vtbl;
    int a;
    int b;
    unsigned char c;
    FUN_0042e650_class(unsigned char c);
};
struct NiAVObject
{
};
struct G00559a40
{
};
struct FUN_0042fdc0_class
{
    NiAVObject* m_pObject;
    NiAVObject* FUN_0042fdc0(NiAVObject** arg);
};
struct FUN_0042fe10_class
{
    void* m_pName;
    unsigned int m_uiCount;
    void* m_pData;
    unsigned int m_uiSize;
    void* FUN_0042fe10(unsigned int count);
};
struct FUN_0042ff80_s
{
};
struct FUN_0042ff50_host : FUN_0042ff80_s
{
    void* FUN_0042ff50(unsigned int flags);
};
struct FUN_00438660_class
{
    void* vtable;
    FUN_00438660_class* FUN_00438660();
};
extern void* DAT_01016058;
struct FNStub
{
};
struct TESModel
{
};
struct TESSound
{
};
struct FUN_00438c10_Class : public FNStub
{
    void FUN_00438c10();
};
struct FUN_00438f90_Class
{
    void FUN_00438f90();
};
struct Unk_00439120
{
    int m0;
    int m4;
    int m8;
    void FUN_00439120(Unk_00439120* p);
};
struct S_00439150
{
    bool FUN_00439150();
};
struct MyPoint439180
{
    float x;
    float y;
    float z;
    MyPoint439180* FUN_00439180(float);
};
struct Mat9
{
    int v[9];
};
struct FUN_004396b0_class
{
    char _pad[0x24];
    Mat9 m;
    void FUN_004396b0(const Mat9& src);
};
struct FUN_00439f50_class
{
    void FUN_00439f50(unsigned int col, NiPoint3* out);
};
struct Node
{
    void* p;
};
struct Helper62d0
{
    void* operator=(const void*);
};
struct ScriptPool
{
    void FUN_00439fd0(const void* arg);
};
struct TESSaveLoadGame
{
};
struct FUN_0043a9a0_class
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    unsigned int l;
    unsigned int m;
    unsigned int n;
    unsigned int o;
    unsigned int p;
    unsigned int q;
    unsigned int r;
    unsigned int s;
    unsigned int t;
    unsigned int u;
    unsigned int v;
    unsigned int w;
    unsigned int x;
    unsigned int y;
    unsigned int z;
    void FUN_0043a9a0();
};
struct S_0043b320
{
    char _pad0[0x38];
    TaskQueueInterface** arr;
    void FUN_0043b320(unsigned short a, TaskQueueInterface* b);
};
struct FUN_00435820 : public BSExtraData
{
    FUN_00435820();
    ~FUN_00435820();
    char m_data[0xc];
};
struct FUN_00420e00_cls : public BaseExtraList
{
    void FUN_00420e00(void* p);
};
struct FUN_00421600_Class
{
    void FUN_00421600(unsigned char val);
};
extern int DAT_01015cd8;
struct ListX
{
    void* m_pInventoryEntryData;
    void* m_pNext;
    void* m_pListObject;
    ~ListX();
};
struct FUN_00433830 : public BSExtraData
{
    void* m_pData;
    int m_iFlags;
    ListX m_kEntryList;
    ~FUN_00433830();
};
extern "C" void _fnv_zlib_memset(void* p, int c, unsigned int n);
struct FUN_00438820_Class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00438820_Class(int c);
};
struct BaseExtraList2
{
};
struct TESLeveledList
{
    void FUN_0042e680(unsigned char type);
};
struct FUN_0042e5a0_class
{
    void FUN_0042e5a0(unsigned char type);
};
struct FUN_004386b0_Class
{
    void* p;
    void* FUN_004386b0(void* a);
};
struct NiPoint3Set
{
};
struct FUN_00439ef0_class : public NiPoint3
{
    NiPoint3* FUN_00439ef0(NiPoint3* a, const NiPoint3& b);
};
struct NiInterpController
{
    static const unsigned short INVALID_INDEX;
};
struct FUN_0043b3b0_class
{
    unsigned short FUN_0043b3b0(unsigned int value);
};
struct G2
{
    void AddHead(int* pValue);
};
struct LH
{
    bool IsInList(int& value);
};
struct FUN_00420440_Class
{
};
struct FUN_00416b80
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;

    FUN_00416b80();
};
struct FUN_00420c10_Class : public FUN_004207e0Class
{
    void FUN_00420c10(int value);
};
struct FUN_0042cca0 : public BSExtraData
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    virtual ~FUN_0042cca0();
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct FUN_0042dff0_shell
{
    int FUN_0042dff0();
};
struct FUN_0042e130_Base
{
};
struct FUN_0042e130_shell : FUN_0042e130_Base
{
    void FUN_0042e130();
};
struct FUN_0042e6d0 : public BSExtraData
{
    virtual ~FUN_0042e6d0();
};
struct NavMeshArr
{
    ~NavMeshArr();
    void* FUN_0042f510(unsigned int flags);
};
NavMeshArr::~NavMeshArr()
{}
struct BSSimpleArrayActor
{
    void* m_vtbl;
    int* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void Clear(bool);
    void FUN_0042f5f0(unsigned int count, bool clear);
};
struct FUN_0042fc00_shell
{
    void FUN_0042fc00(void* count, unsigned int size);
};
struct BSSimpleArrayShell_FUN_00430000
{
    void FUN_00430000(void* data, unsigned int count);
};
struct FUN_0072ba80_shell
{
public:
    void FUN_0072ba80(void *, unsigned int);
};
struct AC_0042f730
{
    void* vtbl;
    void FUN_0042f760();
};
struct NiPointerStandIn
{
    bool operator==(int) const;
};
struct BSExtraDataHelper
{
    virtual ~BSExtraDataHelper();
};
struct FUN_00435f80 : public BSExtraDataHelper
{
    virtual ~FUN_00435f80();
};
struct FUN_004362a0
{
    ~FUN_004362a0();
    void* FUN_00436270(unsigned int flags);
};
struct FUN_00436bb0 : public BSExtraData
{
    virtual ~FUN_00436bb0();
};
struct FUN_0043a080_Node
{
    FUN_0043a080_Node* next;
    int field2;
    int field3;
};
extern int DAT_01188f7c;
extern void* DAT_011c5f54;
struct Date
{
    ~Date();
public:
    void *FUN_007b3fa0(unsigned int);
};
struct FUN_0043b5f0_cls : TESObjectTREE
{
    void FUN_0043b5f0();
};
struct ExtraListShell
{
    void FUN_004216b0();
};
extern "C" void* DAT_0101598c;
struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
    int unk04;
    int unk08;
};
struct FUN_0042f780
{
    int unk00;
    int unk04;
    int unk08;

    ~FUN_0042f780();
};
struct FUN_0042cb30 : public FUN_0040ecb0
{
    FUN_0042f780 unk0c;

    virtual ~FUN_0042cb30();
};
class BSString42C
{
  public:
    BSString42C();
    ~BSString42C();

    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMaxLen;
};
class BSExtraData42C
{
  public:
    BSExtraData42C(unsigned char ucType);
    virtual ~BSExtraData42C();

    unsigned char m_ucType;
    BSExtraData42C* m_pkNext;
};
class FUN_0042ccc0 : public BSExtraData42C
{
  public:
    FUN_0042ccc0();
    virtual ~FUN_0042ccc0();

    BSString42C m_kFirst;
    BSString42C m_kSecond;
};
struct FUN_00436b20
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00436b20(unsigned int a, unsigned int b);
};
struct FUN_0042e060_class
{
    void FUN_0042e060(unsigned int a, unsigned int b);
};
struct B42FA60Entry
{
    int unk00;

    B42FA60Entry();
};
class B42FA60Allocator
{
  public:
    void FUN_0042fa60(B42FA60Entry* pkArray, unsigned int ItemUpdateArray);
};
class B42FE80MapBase
{
  public:
    virtual ~B42FE80MapBase();
    int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
};
class FUN_0042fe80_Map : public B42FE80MapBase
{
  public:
    virtual ~FUN_0042fe80_Map();
    void RemoveAll();
};
struct FUN_004300a0
{
    void* m_uiFilterValue;
    FUN_004300a0();
};
struct SpawnedSub
{
    ~SpawnedSub();
};
struct SpawnedBase
{
    int unk00;
    int unk04;
    int unk08;
    ~SpawnedBase();
};
struct FUN_00435ce0_cls : public SpawnedBase
{
    SpawnedSub m_0c;
    ~FUN_00435ce0_cls();
};
struct FloatSlot
{
    unsigned int m_bits;
};
struct FloatHolder
{
    float m_f;
};
struct FloatList
{
    int unk00;
};
struct FloatGlobal
{
    int unk00;
};
class FUN_00435d40_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FloatList m_0c;

    void FUN_00435d40();
};
struct FUN_00435e40_key
{
    unsigned int m_v;
};
struct FUN_00435e40_arr
{
    unsigned int* GetAt(unsigned int i);
};
struct FUN_00435e40_flt
{
};
struct FUN_00435e40_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00435e40_arr m_0c;
    void FUN_00435e40();
};
struct Vec3Sub
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    Vec3Sub();
};
struct SlottedSource
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
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Vec3Sub* GetVariedData();
};
struct RootCtorCls
{
    virtual void v0();
    RootCtorCls(unsigned int sizeInit);
    ~RootCtorCls();
};
struct FUN_00435fa0_cls : RootCtorCls
{
    virtual void v0();
    int unk04;
    int unk08;
    Vec3Sub m_kPointA;
    Vec3Sub m_kPointB;
    Vec3Sub m_iThirdValue;
    FUN_00435fa0_cls(SlottedSource* pSrc);
};
struct Arg12
{
    int unk00;
    int unk04;
    int unk08;
    ~Arg12();
    void Release();
};
struct EhGuard
{
    ~EhGuard()
    {}
};
struct Base4f
{
    virtual void Tick();
    int unk04;
    int unk08;

    Base4f(int flags);
    ~Base4f();
};
struct Member12
{
    Member12();
    ~Member12();
};
struct FUN_004360c0_cls : public Base4f
{
    virtual void Update();
    Member12 m_0c;

    FUN_004360c0_cls(Arg12 value);
};
struct Base_004361e0
{
    virtual void v00();
    int unk04;
    int unk08;

    Base_004361e0(int aValue);
    ~Base_004361e0();
};
struct Arg12_004361e0
{
    int unk00;
    int unk04;
    int unk08;

    ~Arg12_004361e0();
};
struct Member_004361e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    Member_004361e0();
    ~Member_004361e0();
    void Add(Arg12_004361e0* pArg);
};
struct FUN_004361e0 : Base_004361e0
{
    Member_004361e0 m_0C;

    FUN_004361e0(Arg12_004361e0 aArg);
    virtual void v00();
};
struct ParamBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Release();
    ~ParamBlock();
};
class ChildMember
{
  public:
    ChildMember();
    ~ChildMember();
};
class NodeBase
{
  public:
    NodeBase(int kind);
    virtual void v00();
    ~NodeBase();
    unsigned int unk04;
    unsigned int unk08;
};
class FUN_00436660 : public NodeBase
{
  public:
    FUN_00436660(ParamBlock p);
    virtual void v00();
    ChildMember m_pChildAtom;
};
struct CloneCell;
struct CloneSound;
struct CloneChildCell
{
    virtual CloneCell* GetPersistentCell();
};
struct CloneCell
{
};
struct CloneExtraList
{
};
struct CloneSource
{
    char pad00[0x18];
    CloneChildCell kChildCell;

};
struct CloneProcess
{
};
struct CloneRef
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void SetParentCell(CloneCell* pCell);

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

    CloneRef();
};
struct CloneLowProcess : CloneProcess
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
    CloneLowProcess();
};
struct CloneMiddleLowProcess : CloneLowProcess
{
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    CloneMiddleLowProcess();
};
struct CloneMiddleHighProcess : CloneMiddleLowProcess
{
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
    CloneMiddleHighProcess();
};
struct CloneHighProcess : CloneMiddleHighProcess
{
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
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    CloneHighProcess();
};
struct CloneProcessLists
{
};
struct CloneFactory
{
    CloneRef* FUN_00436780(void* pBase, CloneSource* pSource);
};
struct GcItem
{
};
struct GcNode
{
    ~GcNode();
};
struct GcBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    virtual ~GcBase();
};
class FUN_00437d10 : public GcBase
{
  public:
    GcNode m_pChildAtom;
    virtual ~FUN_00437d10();
};
class FUN_00438610_cls
{
  public:
    unsigned int m_unk00;
    unsigned int* m_pData;
    int FUN_00438610(unsigned int* value);
};
class Base_438720
{
  public:
    virtual ~Base_438720();
    int unk04;
};
class FUN_00438720_cls : public Base_438720
{
  public:
    virtual ~FUN_00438720_cls();
};
struct NiSpawnBase
{
    NiSpawnBase();
    ~NiSpawnBase()
    {}
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};
NiSpawnBase::NiSpawnBase()
{}
class FUN_004391c0 : public NiSpawnBase
{
  public:
    FUN_004391c0();
    virtual void v00();
    void Init4(unsigned int a);
    unsigned short m_0018;
};
// NiProperty's constructor: calls the primary base constructor, installs the
// class vtable pointer, then returns `this`.
struct NiPropertyBase
{
    NiPropertyBase();
    virtual void v00();
};
struct FUN_00439260 : public NiPropertyBase
{
    FUN_00439260();
};
namespace std {
double __cdecl abs(float);
}
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
class TESObjectREFR
{
  public:
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
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
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual int v125();
};
class NiMemObject
{
  public:
};
struct Bound : NiMemObject
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void SetScale(int);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct FUN_00c37ec0 : Bound
{
    FUN_00c37ec0();
};
struct FUN_00c36310 : Bound
{
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    FUN_00c36310();
};
class BSMultiBound : public NiMemObject
{
  public:
    int unk00, unk04, unk08, unk0c;
    BSMultiBound();
};
extern "C" long InterlockedCompareExchange(long volatile* Destination, long Exchange, long Comparand);
typedef long(* InterlockedCompareExchange_t)(long volatile*, long, long);
InterlockedCompareExchange_t DAT_00fdf1bc = InterlockedCompareExchange;
struct ObjB4037
{
};
struct Sub4037
{
    ObjB4037** FUN_006815c0();
    void FUN_00726c60(int* a);
    void FUN_0063f7b0();
};
struct Host00437df0
{
    char m_auiShapeKeys[0x20];
    Sub4037 m_sub;
    void FUN_00437df0();
};
class NiTMapBase438
{
  public:
    virtual ~NiTMapBase438();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_004388a0 : public NiTMapBase438
{
  public:
    virtual ~FUN_004388a0();
};
struct AnimPoint3
{
    float x, y, z;
};
struct AnimMatrix3
{
    float m[9];
};
struct AnimMemObject
{
};
struct AnimSource
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void* GetSourceData();
};
struct AnimInterpolator : AnimMemObject
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void SetSource(void* apData);
};
struct AnimPointInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    AnimPointInterpolator();
};
struct AnimTransformInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44;
    AnimTransformInterpolator();
};
struct AnimBlendData : AnimMemObject
{
    int unk00, unk04, unk08, unk0C;
    AnimBlendData();
};
struct AnimController : AnimMemObject
{
    int unk00;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    int unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
    int unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0;
    int unkE4, unkE8;
    AnimController();
};
struct RefCountedObject
{
    void IncRefCount();
    void DecRefCount();
};
struct FUN_0043b750
{
    void* m_pBuffer;
    NiPointer<RefCountedObject> m_pHeadNode;
    NiPointer<RefCountedObject> m_iSecondInteger;
    int m_unk0c;
    int m_unk10;

    ~FUN_0043b750();
};
class NiFixedString
{
  public:
    NiFixedString(const char* pcString);
    ~NiFixedString();
    const char* m_kHandle;
};
class NameSource
{
  public:
};
class NamedObject
{
  public:
};
class AttachedNode
{
};
class AttachTarget
{
  public:
};
class NamedObjectPtr
{
  public:
    NamedObject* m_pObject;
      // NiPointer<T>::operator T*
};
class AttachedNodePtr
{
  public:
    AttachedNode* m_pObject;
                       // NiPointer<T>::operator T*
    AttachedNodePtr& FUN_0066b0d0(AttachedNode* pkNode);  // NiPointer<T>::operator=
};
const char* __cdecl FUN_0043b9d0(const char* pcString, int iChar);
class NamedObjectLoader
{
  public:
    int unk00;
    NamedObjectPtr m_pReferencedObject;  // +0x04
    AttachedNodePtr m_spNode;            // +0x08

    void FUN_0043b7e0(const char* pcName);
};
class MenuTopic;
class ExtraBase437510
{
  public:
    virtual ~ExtraBase437510();
    unsigned char m_ucType;
    void* m_pkNext;
    ExtraBase437510(unsigned char type);
};
class FUN_00437510 : public ExtraBase437510
{
  public:
    BSSimpleList<BSSimpleList<MenuTopic*>*>* m_pTopics;
    FUN_00437510(BSSimpleList<MenuTopic*>* topics);
    ~FUN_00437510();
};


class FUN_0043a9f0_C
{
  public:
    TESObjectREFR* m_pkRef;

    void FUN_0043a9f0();
};

// @fnv 0x0043a9f0
void FUN_0043a9f0_C::FUN_0043a9f0()
{
    unsigned int auiFormId = (unsigned int)m_pkRef;
    if (auiFormId)
        m_pkRef = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(auiFormId));
}
