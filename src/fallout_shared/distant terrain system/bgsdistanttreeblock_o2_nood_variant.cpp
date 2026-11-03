
// src/fallout_shared/distant terrain system/bgsdistanttreeblock_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistanttreeblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/A72BB0_DataStreamOwner.h"
#include "fnv/decl/BB7290Owner.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/FNVOwner_cls.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043caa0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/decl/FUN_004ea9e0_Class.h"
#include "fnv/decl/FUN_006b4060_class.h"
#include "fnv/decl/FUN_006f9740_Class.h"
#include "fnv/decl/FUN_006f9790_class.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a726a0_cls.h"
#include "fnv/decl/FUN_00a72ca0_Class.h"
#include "fnv/decl/FUN_00c3cee0_shell.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/Holder006fa090.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/S_006ac070.h"
#include "fnv/decl/S_006f9c20.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_0049ee30__NiObjectNET.h"
#include "fnv/decl/fnv_006f7780__FUN_006f7780_Class.h"
#include "fnv/decl/fnv_006f8830__FUN_006f8830.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00a730e0__FUN_00a730e0_cls.h"
#include "fnv/decl/fnv_00c3cf60__FUN_00c3cf60_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006f7000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_00bb6000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01202000.h"
struct NP
{
    NP& operator=(void*);
};
void FUN_006f7a60(void* p);
struct BGSDistantTreeBlockLoadTask
{
    void* Destroy(unsigned int flags);
    void FUN_006f94a0();
};
struct GO
{
    void* p;
    GO(int);
    ~GO();
};
struct Helper8
{
};
struct FUN_006f8650
{
    int unk0;
    GO unk4;
    Helper8 unk8;
    FUN_006f8650();
};
struct FUN_006b3140_shell
{
};
void BuildNavMeshGeometry(void*);
void FUN_006f86b0(void* a1);
struct FUN_006f8800_shell
{
    void* FUN_006f8800(unsigned int flags);
};
struct Flt
{
    operator unsigned int();
};
struct MiddleHighProcess
{
    void FUN_00929260(unsigned char);
};
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};
struct FUN_006f88e0_shell
{
    void FUN_006f88e0();
};
struct BGSDistantTreeBlockLoadTask;
struct BGSDistantTreeBlockLoadTask_shell : BGSDistantTreeBlockLoadTask
{
    void FUN_006f94c0();
};
struct Block88
{
};
struct Holder96
{
    char _0[0x30];
    Block88* p30;
    char _34[0x10];
    unsigned char b44;
    unsigned char b45;
    void FUN_006f9610();
};
struct InstanceData
{
    int f[8];
};
struct FakeArray
{
    int _0;
    InstanceData* _4;
    unsigned int __thiscall AppendInstance(InstanceData*);
};
struct NavMeshSearchLOSArray
{
};
struct ShaderProp
{
};
struct FUN_006f9c70_shell
{
    void FUN_006f9c70(bool freeStorage);
};
struct Fake076
{
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
    virtual const char* GetStr();
};
int __cdecl FormatTreeLodDtlPath(char* a1, Fake076* a2, int a3, short a4, short a5);
struct Arr
{
    unsigned int* GetAt(int, int);
};
struct ArrSI : public Arr
{
};
struct BGSDistantTreeBlock
{
    char _pad[52];
    ArrSI mArray;
    void ProcessAllTrees();
};
struct IOTask
{
};
class SoundPlaybackHandle;
template <typename A, typename B> struct NiTPointerMap
{
    bool IsEmpty();
};
struct IOManager
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
    virtual void v18(void*);
};
struct FUN_006f94e0_shell
{
    char _pad[52];
    bool m_bValueAtOffset34;
    void FUN_006f94e0();
};
struct DummyPointerMap
{
};
struct BSSimpleArrayStandIn
{
};
struct InstanceDataB
{
    unsigned char b1c;
};
struct ArrB
{
    unsigned int* GetAt(int);
};
struct BGSDistantTreeBlock_shell : BGSDistantTreeBlock
{
    void MarkTreeInstance(unsigned int aID, bool abQueue);
};
struct FUN_006b3120_helper
{
};
void FUN_006f83f0();
struct NiBinaryStream
{
};
struct NiFile : public NiBinaryStream
{
};
struct NiBound
{
    unsigned int x0;
    unsigned int x1;
    unsigned int x2;
    unsigned int x3;
    unsigned int x4;
    unsigned int x5;
    unsigned int x6;
    unsigned int x7;

    NiBound();
};
struct AutoMemHelper
{
    int value;

    AutoMemHelper(int context, bool flag, const char* file, int line);
    ~AutoMemHelper();
};
extern const char str_0106dd30[];
struct FUN_006f8b40_shell
{
    void ReadGroups(NiFile* apInputFile);
};
struct FUN_00bb7290_shell
{
};
struct FUN_006b3120_shell
{
public:
    char *GetElementAt(unsigned int);
};
struct FUN_006f90a0_instance
{
    float f0;
    float f1;
    float f2;
    float f3;
    float f4;
    char _pad[8];
    unsigned char flag;
};
struct FUN_006f90a0_owner
{
    char _pad[0x1c];
    unsigned char flag;
};
struct FUN_006f90a0_params
{
    FUN_00bb7290_shell* renderer;
    FUN_006f90a0_owner* owner;
};
struct FUN_006f90a0_shell
{
    void UpdateInstances(FUN_006f90a0_params params);
};
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
public:
    float ComputeMagnitude() const;
};
struct NiPoint2
{
    float x;
    float y;
    NiPoint2();
};
struct NiMemObject
{
    static void* operator new(unsigned int);
};
struct Obj44 : NiMemObject
{
    char _pad[44];
    Obj44(unsigned short);
};
struct Obj88 : NiMemObject
{
    char _pad[88];
    Obj88(unsigned short, NiPoint3*, NiPoint3*, int, NiPoint2*, int, int, unsigned short, unsigned short*);
};
class PathingSolution
{
};
template <typename T> struct PathingRef
{
    void Reset(void*);
};
struct NavMeshPtr
{
    int v;
    NavMeshPtr& operator=(const NavMeshPtr&);
};
class NiGPUProgram;
struct NiGPUProgramOwner
{
    void SetProgram(NiGPUProgram*);
};
struct InParam
{
    int unk0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    NavMeshPtr m1c;
};
void BuildNavMeshGeometry(void* param);
struct TreeInstance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int uiID;
    int iBlockIndex;
    unsigned char bFlag;
};
struct TreeInstanceArray
{
    int unk00;
    TreeInstance* pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
};
struct TreeTypeArray
{
};
struct TreeBlock
{
    void* pType;
    int unk04;
    TreeInstanceArray kInstances;
    int iIndex;
    unsigned char bFull;
    TreeBlock();
};
struct TreeBlockArray
{
};
struct TreeBlockMap
{
    void SetAt(unsigned int auiKey, TreeBlock* apVal);
};
struct TreeInstanceMap
{
    void SetAt(unsigned int auiKey, TreeInstance* apVal);
};
struct TreeLODManager
{
    int unk00;
    TreeBlockArray kBlocks;
    int unk08;
    int unk0C;
    int unk10;
    TreeInstanceMap kInstanceMap;
    int unk18;
    int unk1C;
    int unk20;
    TreeBlockMap kBlockMap;
    void AddTreeInstance(unsigned int auiType, TreeInstance* apInstance);
};
struct NiAVObjectS;
template <class T> struct NiPtrS
{
    T* m_pObject;
    operator T*() const;
    NiPtrS& operator=(T* p);
};
struct NiNodeS
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void InsertChild(NiAVObjectS* apChild);
};
struct RootHolderS
{
};
struct SimpleArrS
{
    int unk0;
    int unk4;
    int unk8;
};
struct TreeBlockEntryS
{
    int unk0;
    NiPtrS<NiAVObjectS> m_pController;
    SimpleArrS kInstances;
    ~TreeBlockEntryS();
};
struct EntryArrS
{
    TreeBlockEntryS*& GetAt(unsigned int auiIndex);
};
struct TreeOwnerS
{
    int unk0;
    EntryArrS kEntries;
    void ClearEntries();
};
struct TreeScopeGuard
{
    void* p;
    TreeScopeGuard(int line, int flags, const char* file, int size);
    ~TreeScopeGuard();
};
struct TreeRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TreeRecord();
    ~TreeRecord();
};
struct TreeTemp
{
    int v;
    TreeTemp(int v);
};
struct TreeHost
{
};
void ReadTreeRecords(TreeHost* host);
struct C6F9060Member
{
    int unk00;

    C6F9060Member(int value);
};
struct FUN_006f9060
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C6F9060Member m_kMember;

    FUN_006f9060();
};
struct Callee
{
    void FUN_0045cec0();
};
struct FUN_006f9080_owner : BGSDistantTreeBlockLoadTask
{
    char unk1b[0x1c];
    Callee callee;

    void FUN_006f9080();
};
void Callee::FUN_0045cec0()
{}
struct Fake076;
int __cdecl FormatTreeLodDtlPath(char* a1, Fake076* a2, int a3, short a4, short a5);
struct QBase
{
    QBase(int aPriority);
    virtual ~QBase();

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
};
struct BGSDistantTreeBlock;
struct FUN_006f9360 : QBase
{
    BGSDistantTreeBlock* pBlock;
    bool m_bValueAtOffset34;
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    int iLODLevel;
    bool m_bHeaderParsed;
    bool bFadeQueuedCur;

    FUN_006f9360(BGSDistantTreeBlock* apBlock, Fake076* apWorld, int aiCellX, int aiCellY, int aiLODLevel,
                 int aiUnused);
    virtual ~FUN_006f9360();
};
class C6F94A0Base
{
  public:
    virtual ~C6F94A0Base();
};
class FUN_006f94a0 : public C6F94A0Base
{
  public:
    virtual ~FUN_006f94a0();
};
class B6F9570File
{
  public:
    virtual ~B6F9570File();
};
class B6F9570FileFinder
{
  public:
    static B6F9570File* GetFile(const char* pcName, int eMode, unsigned int uiBufferSize, unsigned int uiFlags);
};
class B6F9570TreeBlock
{
  public:
};
class B6F9570TreeLoader
{
  public:
    void LoadTreeFile();

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
    B6F9570TreeBlock* m_pkTreeBlock;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    bool m_bCancelled;
    bool m_bLoadComplete;
};
struct Lod77Foo1
{
    static void* operator new(unsigned int);
    Lod77Foo1();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct Lod77Foo2
{
    static void* operator new(unsigned int);
    Lod77Foo2();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct Lod77Elem
{
};
struct Lod77Container
{
    void Add(void* p);
};
struct LodFile
{
    virtual ~LodFile();
};
struct Lod77Mgr
{
};
int __cdecl FUN_00ec8a19(const char* a, const char* b, int c);
struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex(float, float, float);
    NiPoint3Ex operator-(const NiPoint3Ex&) const;
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
};
struct FUN_006240d0
{
    float x, y, z, radius;
    FUN_006240d0();
};
struct TreeGeometry
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual FUN_006240d0* GetBound();
};
struct TreeGeometryPtr
{
    TreeGeometry* object;
};
struct TreePositions
{
};
struct BoundTreeBlock
{
    int unk00;
    TreeGeometryPtr geometry;
    TreePositions instances;
};
struct TreeBoundsOwner
{
    FUN_006240d0 ComputeTreeBounds(BoundTreeBlock* block);
};
struct UpdateDataX
{
    float time;
    bool a, b;
    int unk08;
    UpdateDataX(float, bool, bool);
};
struct BoundsX
{
    float x, y, z, r;
};
struct NodeX : NiMemObject
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
    virtual void v53();
    virtual void v54();
    virtual void Attach(NodeX*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void SetObjectBound(BoundsX);
};
struct NewNodeX : NodeX
{
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
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    NewNodeX(void*);
};
struct PropertyX : NiMemObject
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
    PropertyX();
};
struct TypeX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    NiPtrS<void> name;
};
struct EntryX
{
    TypeX* type;
    NiPtrS<NodeX> node;
    SimpleArrS instances;
};
struct ArrayX
{
    EntryX*& GetAt(unsigned int);
    int unk00, unk04, unk08, unk0c;
};
struct HolderX
{
};
struct OwnerX
{
    int unk00;
    ArrayX entries;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    bool loaded, built;
    BoundsX GetBound(EntryX*);
    void FUN_006f8c40();
};

struct S_00bb6050
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

    int __thiscall FUN_00bb6050(int arg0, int arg1);
};

// @fnv 0x00bb6050
int __thiscall S_00bb6050::FUN_00bb6050(int arg0, int arg1)
{
    return this->unk80;
}
