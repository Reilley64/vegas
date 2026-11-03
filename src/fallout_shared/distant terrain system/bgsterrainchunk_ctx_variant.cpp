
// bgsterrainchunk_ctx_variant.cpp: context variant of src/fallout_shared/distant terrain system/bgsterrainchunk.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/fallout_shared/distant terrain system/bgsterrainchunk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsterrainchunk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderPPLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cls5140.h"
#include "fnv/decl/FUN_00439680_class.h"
#include "fnv/decl/FUN_0043caa0_shell.h"
#include "fnv/decl/FUN_004410d0_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004ea9a0_Class.h"
#include "fnv/decl/FUN_006fa670_Target.h"
#include "fnv/decl/FUN_006fe920_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/FUN_00c3cff0_shell.h"
#include "fnv/decl/MLx.h"
#include "fnv/decl/Mgr_e74120.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/decl/S.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TargetObject.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_004e4c80__Main61.h"
#include "fnv/decl/fnv_00540570__FUN_00540570_Owner.h"
#include "fnv/decl/fnv_00c3cb70__IOTask.h"
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
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_006fd000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
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
struct QueuedFileEntry
{
    int f0[0x34 / 4];
};
struct BGSTerrainChunkLoadTask : QueuedFileEntry
{
    int iX;
    int iY;
    int iLevel;
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
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
struct E14
{
    virtual void v0(), v1(), v2(), v3(), v4();
    virtual void* F14();
};
struct C43
{
};
struct Ec
{
    virtual void v0(), v1(), v2();
    virtual C43* Fc(int a);
};
struct E1d0
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(),
        v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(), v62(), v63(),
        v64(), v65(), v66(), v67(), v68(), v69(), v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(), v79(),
        v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89(), v90(), v91(), v92(), v93(), v94(), v95(),
        v96(), v97(), v98(), v99(), v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109(),
        v110(), v111(), v112(), v113(), v114(), v115();
    virtual Ec* F1d0();
};
struct R4e
{
};
struct AutoMemX
{
    int m;
    AutoMemX(int a, int b, const char* f, int l);
    ~AutoMemX();
};
struct Q28
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9();
    virtual struct TaskX* F28();
};
struct TaskX
{
};
struct Obj18
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5();
    virtual void* F18();
};
struct NodeX
{
};
struct RootX
{
    virtual void v0(), v1(), v2();
    virtual int Fc();
};
struct PN
{
    void* p;
    void FUN_0066b0d0(void* q);
};
struct PQ
{
    void* p;
    void FUN_0066b0d0(void* q);
};
struct PV
{
    void* p;
    void FUN_0066b0d0(void* q);
};
struct StreamX
{
    char buf[0x5cc];
    StreamX();
    ~StreamX();
};
struct SettingX
{
    bool* FUN_00408d60();
};
class SelfX
{
  public:
    char pad[0x48];
    PV m48;
    PQ m4c;
    PV m50;
    PN m54;
    void FUN_006fbd00();
public:
    void UpdateWaterReferences(bool);
};

struct G3
{
};
struct G2
{
};
struct G1
{
};
struct G0
{
    void* p;
};
struct PS
{
    void* p;
    void FUN_0066b0d0(void* p);
};
struct MgrX
{
};

struct ObjB
{
};
struct ObjC
{
};
struct Sub4
{
};
struct Cls6fabc0
{
    ObjB* m_iWordAt00;
    Sub4 m_iWordAt04;
    int FUN_006fabc0(int arg);
};
extern "C" int DAT_0106e180;
namespace detach6fb {
struct D6Object
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~D6Object();
};
struct D6Child
{
    int unk00;
};
struct D6Node
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
    virtual void InsertChild(D6Child* child);
};
struct D6Root;
struct D6Ref
{
};
struct D6Owner
{
};
struct D6ChildPtr
{
    D6Child* p;
};
struct D6Queue
{
};
struct D6Manager
{
};
struct D6Detacher
{
    D6Owner* pOwner;
    int unk04;
    D6ChildPtr kChildA;
    D6ChildPtr kChildB;
    int unk10;
    D6ChildPtr kAttachA;
    D6ChildPtr kAttachB;
    D6Object* pObjectA;
    D6Object* pObjectB;
    void FUN_006fb3d0(bool force);
};
}
using namespace detach6fb;


// @fnv 0x006fbd00
void SelfX::FUN_006fbd00()
{
    AutoMemX kMemVal(
        0x23, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSTerrainChunk.cpp",
        0x298);
    int iFile = ((int)(reinterpret_cast<::FUN_00c3cff0_shell *>(this)->FUN_00c3cff0(0, 1)));
    StreamX kStreamVal;
    if (reinterpret_cast<::FUN_00c3a8a0_cls *>(&(kStreamVal))->FUN_00c3a8a0(((int)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())), {}))
    {
        RootX* pkRoot = ((::RootX *)(reinterpret_cast<::MLx *>(&(kStreamVal))->GetStringAt(0)));
        if (pkRoot->Fc())
        {
            m54.FUN_0066b0d0(((::RootX *)(reinterpret_cast<::MLx *>(&(kStreamVal))->GetStringAt(0))));
            m48.FUN_0066b0d0(((::Obj18 *)(reinterpret_cast<::NiNode *>((((::NodeX *)(::FUN_00559450((int *)&(m54))))))->GetAt(0))));
            if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((((::NodeX *)(::FUN_00559450((int *)&(m54))))))->FUN_00453470())) > 1 && *(*reinterpret_cast<::SettingX *>(&::g_011c7adc)).FUN_00408d60())
            {
                m4c.FUN_0066b0d0(((::Obj18 *)(reinterpret_cast<::NiNode *>((((::NodeX *)(::FUN_00559450((int *)&(m54))))))->GetAt(1)))->F18());
                if (((::Q28 *)(::FUN_00559450((int *)&(m4c))))->F28() && ((int)(reinterpret_cast<::FUN_006fbfe0_shell *>((((::Q28 *)(::FUN_00559450((int *)&(m4c))))->F28()))->GetFlagOrValue())) == 3)
                    m4c.FUN_0066b0d0(0);
            }
            if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((((::NodeX *)(::FUN_00559450((int *)&(m54))))))->FUN_00453470())) > 2 && *(*reinterpret_cast<::SettingX *>(&::g_011c7adc)).FUN_00408d60())
                m50.FUN_0066b0d0(((::Obj18 *)(reinterpret_cast<::NiNode *>((((::NodeX *)(::FUN_00559450((int *)&(m54))))))->GetAt(2)))->F18());
        }
        else
        {
            m48.FUN_0066b0d0(((::RootX *)(reinterpret_cast<::MLx *>(&(kStreamVal))->GetStringAt(0))));
            if (((unsigned int)(::GetRefAt21C((const char *)&(kStreamVal)))) > 1)
                m4c.FUN_0066b0d0(((::RootX *)(reinterpret_cast<::MLx *>(&(kStreamVal))->GetStringAt(1))));
        }
    }
}
