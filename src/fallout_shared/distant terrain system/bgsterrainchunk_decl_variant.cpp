
// src/fallout_shared/distant terrain system/bgsterrainchunk_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006fb980: the skeleton of src/fallout_shared/distant terrain system/bgsterrainchunk.cpp
// with declarations corrected to what the original code does (unit: struct QueuedFileEntry { int f0[0x34 / 4]; }; -> class TESWorldSpace; struct QueuedFileEntry { virtual ~Q; unit: struct BGSTerrainChunkLoadTask : QueuedFileEntry { int i -> struct BGSTerrainChunkLoadTask : QueuedFileEntry { bool ). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/distant terrain system/bgsterrainchunk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsterrainchunk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00439680_class.h"
#include "fnv/decl/FUN_0043caa0_shell.h"
#include "fnv/decl/FUN_004410d0_Class.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_004ea9a0_Class.h"
#include "fnv/decl/FUN_006fa670_Target.h"
#include "fnv/decl/FUN_006fe920_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00c3cee0_shell.h"
#include "fnv/decl/Mgr_e74120.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/decl/SelfX.h"
#include "fnv/decl/TargetObject.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_00c3cb70__IOTask.h"
#include "fnv/decl/fnv_00c3cf60__FUN_00c3cf60_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00441000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_006fd000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_01202000.h"
struct FUN_006fa840_shell
{
    unsigned char GetByteAt5D();
};
struct FUN_006fb150_shell
{
    unsigned char GetByteAtOffset5C();
};
struct NiAVObject
{
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_006fb6e0_shell
{
    void SetAllAppCulled();
};
struct FUN_006fb940_shell
{
    void FUN_006fb940(float a, float b, float c);
};
class TESWorldSpace;
struct QueuedFileEntry
{
    virtual ~QueuedFileEntry();
    int f4[0x2c / 4];
    QueuedFileEntry(int priority);
};
template <class T> struct ChunkPtr
{
    ChunkPtr(T* p);
    ~ChunkPtr();
    T* p;
};
struct BGSTerrainChunkLoadTask : QueuedFileEntry
{
    bool unk30;
    int iX;
    int iY;
    int iLevel;
    void* owner;
    TESWorldSpace* world;
    ChunkPtr<void> unk48;
    ChunkPtr<void> unk4c;
    ChunkPtr<void> unk50;
    ChunkPtr<void> unk54;
    bool unk58;
    BGSTerrainChunkLoadTask(void* block, TESWorldSpace* space, int x, int y, int level);
    bool FUN_006fc400(char* apDescription, unsigned int aiBufferSize);
};
extern "C" void __cdecl UpdateListItems();
struct FakeWorld006faad0
{
    virtual const char* f0();
    virtual const char* f1();
    virtual const char* f2();
    virtual const char* f3();
    virtual const char* f4();
    virtual const char* f5();
    virtual const char* f6();
    virtual const char* f7();
    virtual const char* f8();
    virtual const char* f9();
    virtual const char* f10();
    virtual const char* f11();
    virtual const char* f12();
    virtual const char* f13();
    virtual const char* f14();
    virtual const char* f15();
    virtual const char* f16();
    virtual const char* f17();
    virtual const char* f18();
    virtual const char* f19();
    virtual const char* f20();
    virtual const char* f21();
    virtual const char* f22();
    virtual const char* f23();
    virtual const char* f24();
    virtual const char* f25();
    virtual const char* f26();
    virtual const char* f27();
    virtual const char* f28();
    virtual const char* f29();
    virtual const char* f30();
    virtual const char* f31();
    virtual const char* f32();
    virtual const char* f33();
    virtual const char* f34();
    virtual const char* f35();
    virtual const char* f36();
    virtual const char* f37();
    virtual const char* f38();
    virtual const char* f39();
    virtual const char* f40();
    virtual const char* f41();
    virtual const char* f42();
    virtual const char* f43();
    virtual const char* f44();
    virtual const char* f45();
    virtual const char* f46();
    virtual const char* f47();
    virtual const char* f48();
    virtual const char* f49();
    virtual const char* f50();
    virtual const char* f51();
    virtual const char* f52();
    virtual const char* f53();
    virtual const char* f54();
    virtual const char* f55();
    virtual const char* f56();
    virtual const char* f57();
    virtual const char* f58();
    virtual const char* f59();
    virtual const char* f60();
    virtual const char* f61();
    virtual const char* f62();
    virtual const char* f63();
    virtual const char* f64();
    virtual const char* f65();
    virtual const char* f66();
    virtual const char* f67();
    virtual const char* f68();
    virtual const char* f69();
    virtual const char* f70();
    virtual const char* f71();
    virtual const char* f72();
    virtual const char* f73();
    virtual const char* f74();
    virtual const char* f75();
    virtual const char* GetStr();
};
int __cdecl _sprintf(char*, const char*, ...);
struct FakeFab
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
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual const char* GetStr();
};
void __cdecl BuildLodNormalTexturePath(char* a1, FakeFab* a2, int a3, short a4, short a5);
struct FUN_006fb760_shell
{
    void FUN_006fb760();
};
struct S_006fbae0
{
    void FUN_006fbb10();
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_006fbcd0_shell
{
    void SetFlagAndCall(int a, int b);
};
struct FUN_006fbfe0_shell
{
    unsigned int GetFlagOrValue();
};
struct IOTask
{
};
struct SoundPlaybackHandle;
template <class K, class V> struct NiTPointerMap
{
    bool IsEmpty();
};
struct IOManager
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
    virtual void vfn_48(void*);
};
struct FUN_006f7140_shell : IOTask
{
    char _pad[48];
    bool b30;
    void ProcessTask();
};
struct FakeObj
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
int __cdecl _sprintf(char*, const char*, ...);
void __cdecl BuildLODDiffuseTexturePath(char* buf, FakeObj* obj, int level, short x, short y);
struct GO;
struct FUN_006fea10_Class
{
};
struct GO
{
    FUN_006fea10_Class* f0;
    operator unsigned int() const;
};
struct SoundListView
{
    bool _ref_008256d0();
};
void UpdateSoundListItems();
struct QueuedFile
{
};
struct ModelLoader
{
};
struct FUN_0043cc60_shell
{
    int FUN_0043cc60();
};
struct FUN_006fbbd0_virtual
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
};
struct FUN_006fbbd0_shell : BGSTerrainChunkLoadTask
{
    void LoadTerrainChunkTextures();
};
void __cdecl BuildLODDiffuseTexturePath(char*, FakeObj*, int, short, short);
struct FUN_006fbb10_base
{
    virtual ~FUN_006fbb10_base();
};
struct FUN_006fbb10_sub
{
    int unk00;
    ~FUN_006fbb10_sub();
    void Reset(int aiValue);
};
struct FUN_006fbb10 : FUN_006fbb10_base
{
    virtual ~FUN_006fbb10();
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
    FUN_006fbb10_sub m_48;
    FUN_006fbb10_sub m_4c;
    FUN_006fbb10_sub m_50;
    FUN_006fbb10_sub m_54;
};
struct Point006fac
{
    float x, y, z;
};
struct FUN_0043d410
{
    int a, b, c;
    FUN_0043d410(float, bool, bool);
};
struct TESObjectDoorController
{
};
struct Obj006fac;
struct Ref006fac
{
    void FUN_0066b0d0(void*);
    int data;
};
struct Obj006fac
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
    virtual void attach(Obj006fac*, int);
};
struct FUN_00c37ec0 : TESObjectDoorController
{
    int pad[8];
    FUN_00c37ec0();
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
    virtual void position(const Point006fac&);
};
struct FUN_00c46970 : TESObjectDoorController
{
    int pad[45];
    FUN_00c46970();
};
struct BSMultiBound : TESObjectDoorController
{
    int pad[4];
    BSMultiBound();
};
struct Target006fac
{
    Obj006fac* root;
    Ref006fac r4, r8, rc, r10, r14, r18;
    int p1c, p20, p24;
    unsigned char enabled, done;
    void FUN_006facb0();
};
struct B5D0Status
{
};
struct B5D0Item
{
};
struct B5D0List
{
    bool FUN_008256d0();
};
void __cdecl UpdateListItems();
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
    NiPointer& operator=(T*);
};
class NiNode;
class NiGeometry;
class NiProperty;
class NiProperty : public FUN_006fb940_shell
{
  public:
};
class NiGeometryData
{
  public:
    void FUN_00a67050(int);
public:
    void SetCompressFlags(unsigned char);
};
struct PropState
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
    virtual void* v70(NiGeometry*, NiProperty*);
};
class NiRenderer
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
    virtual void v59(NiGeometry*, int, int, void*);
};
class NiGeometry : public NiAVObject
{
  public:
};
class TerrainChunk
{
  public:
    int unk00;
    NiPointer<NiGeometry> m_spGeom;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    short unk28;
    bool m_bFlag;
    char unk2B;
    NiPointer<NiNode> m_spProperty;

    void FUN_006fb7e0();
};
struct NiFixedString
{
    unsigned int m_data;
    NiFixedString(const char*);
    ~NiFixedString();
    operator const char*() const;
};
struct LoadedNode
{
};
struct NodeRef
{
    LoadedNode* m_ptr;
    NodeRef& operator=(void*);
};
struct FinalObject
{
};
struct TerrainTask : BGSTerrainChunkLoadTask
{
    FinalObject* m_pExtra40;
    unsigned int m_unk44;
    NodeRef m_ref48;
    NodeRef m_ref4c;
    NodeRef m_ref50;
    unsigned int m_unk54;
    bool m_bDisabled58;
    void UpdateTerrainLODNames();
};

// @fnv 0x006fb980
BGSTerrainChunkLoadTask::BGSTerrainChunkLoadTask(void* block, TESWorldSpace* space, int x, int y, int level)
    : QueuedFileEntry(3), unk30(false), iX(x), iY(y), iLevel(level), owner(block), world(space), unk48(0), unk4c(0),
      unk50(0), unk54(0), unk58(false)
{
    char fileName[260];
    ::BuildLodMeshPath(fileName, (::FakeWorld006faad0 *)(world), level, (short)x, (short)y);
    reinterpret_cast<::FUN_00c3cee0_shell *>(this)->FUN_00c3cee0((char *)(fileName + 5));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>(this)->LookupFileEntryByArchive(0);
}
