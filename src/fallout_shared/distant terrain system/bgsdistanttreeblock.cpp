
// src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistanttreeblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include <cstring>
#include "fnv/decl/A72BB0_DataStreamOwner.h"
#include "fnv/decl/BB7290Owner.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/FNVOwner_cls.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043caa0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045cec0_Class.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/decl/FUN_004ea9e0_Class.h"
#include "fnv/decl/FUN_006b4060_class.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_006f9740_Class.h"
#include "fnv/decl/FUN_006f9790_class.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a726a0_cls.h"
#include "fnv/decl/FUN_00a72ca0_Class.h"
#include "fnv/decl/FUN_00c3cee0_shell.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/Holder006fa090.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/decl/S_006ac070.h"
#include "fnv/decl/S_006f9c20.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_0049ee30__NiObjectNET.h"
#include "fnv/decl/fnv_006f7780__FUN_006f7780_Class.h"
#include "fnv/decl/fnv_006f9770__GlobalObject_00869f00.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00a730e0__FUN_00a730e0_cls.h"
#include "fnv/decl/fnv_00c3cb70__IOTask.h"
#include "fnv/decl/fnv_00c3cf60__FUN_00c3cf60_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_00bb6000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/symbols_006f7000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_011f9000.h"
struct NP
{
    NP& operator=(void*);
};


// @fnv 0x006f7a60
void FUN_006f7a60(void* p)
{
    DAT_012007c4.operator=(p);
}

struct BGSDistantTreeBlockLoadTask
{
    void* Destroy(unsigned int flags);
    void FUN_006f94a0();
};


namespace fnv_006f9540 {
struct BGSDistantTreeBlockLoadTask
{
    void FUN_006f9540(int a1, void* a2);
};

// Sets the byte at this+0x44 to 1, then calls FUN_00c3cb70 with the given arguments.
// @fnv 0x006f9540
void BGSDistantTreeBlockLoadTask::FUN_006f9540(int aiArg, void* apArg)
{
    ((char*)this + 0x44)[0] = 1;
    reinterpret_cast<::fnv_00c3cb70::IOTask *>(this)->FUN_00c3cb70(aiArg, (::fnv_00c3cb70::RefObj *)(apArg));
}
}  // namespace fnv_006f9540

namespace fnv_006f9640 {
struct QueuedFileEntry
{
    char data[0x38];
};

struct BGSDistantTreeBlockLoadTask : QueuedFileEntry
{
    int iX;
    int iY;
    int iLevel;
    bool FormatDescription(char* apDescription, unsigned int aiBufferSize);
};


// Writes the block coordinates and level into apDescription with _sprintf_s and returns true.
// @fnv 0x006f9640
bool BGSDistantTreeBlockLoadTask::FormatDescription(char* apDescription, unsigned int aiBufferSize)
{
    ::FUN_00406d00(apDescription, aiBufferSize, "Tree LOD Task for block ( %i, %i ) at level ( %i )", iX, iY, iLevel);
    return true;
}
}  // namespace fnv_006f9640

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
// Constructor: initializes unk4 with 0 and calls FUN_006f9740 on unk8.
// @fnv 0x006f8650
FUN_006f8650::FUN_006f8650() : unk4(0)
{
    reinterpret_cast<::FUN_006f9740_Class *>(&(unk8))->FUN_006f9740();
}

struct FUN_006b3140_shell
{
    void* FUN_006b3140();
};
void BuildNavMeshGeometry(void*);
// @fnv 0x006f86b0
void FUN_006f86b0(void* a1)
{
    reinterpret_cast<::S_006f9c20 *>(&((*reinterpret_cast<::FUN_006b3140_shell *>(&::g_011d85d0))))->AddElement((const ::S_006f9c20_Elem *)(a1));
    BuildNavMeshGeometry((*reinterpret_cast<::FUN_006b3140_shell *>(&::g_011d85d0)).FUN_006b3140());
}

struct FUN_006f8800_shell
{
    void FUN_006f8830();
    void* FUN_006f8800(unsigned int flags);
};

// Calls FUN_006f8830, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006f8800
void* FUN_006f8800_shell::FUN_006f8800(unsigned int flags)
{
    FUN_006f8830();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_006f8830 {
struct GO
{
    void* _0;
    ~GO();
};
struct H9770
{
};
struct FUN_006f8830
{
    int _00;
    GO _04;
    H9770 _08;
    ~FUN_006f8830();
};
// Destructor that calls FUN_006f9770 on the member at offset 0x08.
// @fnv 0x006f8830
FUN_006f8830::~FUN_006f8830()
{
    reinterpret_cast<::fnv_006f9770::GlobalObject_00869f00 *>(&(_08))->FUN_006f9770();
}
}  // namespace fnv_006f8830

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
// Sets the byte at offset 0x48 to 1, calls FUN_00929260(1) on the process at offset 0x44, then clears the pointer at offset 0.
// @fnv 0x006f88e0
void FUN_006f88e0_shell::FUN_006f88e0()
{
    *(char*)(this + 0x48) = 1;
    ((MiddleHighProcess*)((Flt*)(*(void**)((char*)this + 0x44)))->operator unsigned int())->FUN_00929260(1);
    reinterpret_cast<::FUN_006f74f0_cls *>(this)->FUN_006f74f0(nullptr);
}

namespace fnv_006f91a0 {
struct ArrSI
{
    unsigned int* GetAt(int);
};
struct Flt
{
    operator unsigned int();
};
struct PropHelper
{
};
struct FUN_006f90a0_shell
{
    void UpdateInstances(void* a, void* b);
};
struct FUN_006f91a0_shell : ArrSI
{
    void FUN_006f91a0();
};
// Iterates the array at this+4, and for each unflagged entry with a nonzero value, looks up a property and passes it with the entry to UpdateInstances.
// @fnv 0x006f91a0
void FUN_006f91a0_shell::FUN_006f91a0()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 4))))->GetName())); ++i)
    {
        void* p = *((void**)((ArrSI*)((char*)this + 4))->GetAt(i));
        if (!(*(unsigned char*)((char*)p + 0x1c)) && ((Flt*)((char*)p + 4))->operator unsigned int())
        {
            void* property =
                ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((Flt*)((char*)p + 4))->operator unsigned int())))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));
            if (property)
                ((FUN_006f90a0_shell*)this)->UpdateInstances(property, p);
        }
    }
}
}  // namespace fnv_006f91a0

struct BGSDistantTreeBlockLoadTask;
struct BGSDistantTreeBlockLoadTask_shell : BGSDistantTreeBlockLoadTask
{
    void FUN_006f94c0();
};
// @fnv 0x006f94c0
void BGSDistantTreeBlockLoadTask_shell::FUN_006f94c0()
{
    *(char*)((char*)this + 0x34) = 1;
    ((void(*)(void*))(*(void***)this)[0x28 / 4])(this);
}

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
// If b45 is set and b44 is clear, calls FUN_006f88e0 on p30.
// @fnv 0x006f9610
void Holder96::FUN_006f9610()
{
    if (b45 && !b44)
        reinterpret_cast<::FUN_006f88e0_shell *>((p30))->FUN_006f88e0();
}

struct InstanceData
{
    int f[8];
};
struct FakeArray
{
    int _0;
    InstanceData* _4;
    unsigned int AppendInstance(InstanceData*);
};
// @fnv 0x006f9800
unsigned int FakeArray::AppendInstance(InstanceData* apInstance)
{
    unsigned int uiNewIndex;
    uiNewIndex = ((unsigned int)(reinterpret_cast<::FUN_006b4060_class *>(this)->GetNextIndex()));
    reinterpret_cast<::FNVOwner_cls *>(this)->ConstructElements((char *)(void *)(&_4[uiNewIndex]), 1);
    _4[uiNewIndex] = *apInstance;
    return uiNewIndex;
}

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
// @fnv 0x006f9c70
void FUN_006f9c70_shell::FUN_006f9c70(bool freeStorage)
{
    if (*(void**)((char*)this + 4))
    {
        reinterpret_cast<::Holder006fa090 *>((((ShaderProp*)this)))->FUN_006fa090((::Elem006fa0d0 *)(*(void**)((char*)this + 4)), (unsigned int)(*(void**)((char*)this + 8)));
        if (freeStorage)
        {
            ::FUN_006a8500((::DummyClass_006a8500 *)(((NavMeshSearchLOSArray*)this)));
            *(void**)((char*)this + 4) = 0;
            *(unsigned int*)((char*)this + 0xc) = 0;
        }
        *(unsigned int*)((char*)this + 8) = 0;
    }
}

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
// Formats a Data\Meshes\Landscape\LOD tree DTL path into a1 using a2's string, a3, a4 and a5, and returns _sprintf_s's result.
// @fnv 0x006f8890
int __cdecl FormatTreeLodDtlPath(char* pcBuffer, Fake076* a2, int iLevel, short iX, short iY)
{
    return ::FUN_00406d00(pcBuffer, 260, "Data\\Meshes\\Landscape\\LOD\\%s\\Trees\\%s.Level%i.X%i.Y%i.DTL", a2->GetStr(),
                      a2->GetStr(), iLevel, iX, iY);
}

namespace fnv_006f92a0 {
struct DummyPointerMap
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct InstanceData
{
    unsigned char pad[0x18];
    int f18;
    unsigned char f1c;
};
struct BGSDistantTreeBlock
{
    char _0[4];
    Arr arr;
    char _1[15];
    DummyPointerMap map;
    void ClearInstanceFlag(unsigned int aID);
};
// Looks up aID in map; if found, clears f1c on the instance and on the instance referenced by arr at f18.
// @fnv 0x006f92a0
void BGSDistantTreeBlock::ClearInstanceFlag(unsigned int aID)
{
    bool bfound;
    InstanceData* pinst = 0;
    bfound = reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(map))->FUN_00853130(aID, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)pinst));
    if (bfound)
    {
        pinst->f1c = 0;
        ((InstanceData*)*arr.GetAt(pinst->f18))->f1c = 0;
    }
}
}  // namespace fnv_006f92a0

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
// @fnv 0x006f94e0
void FUN_006f94e0_shell::FUN_006f94e0()
{
    if (reinterpret_cast<::FUN_0043caa0_shell *>((((IOTask*)this)))->FUN_0043caa0() && m_bValueAtOffset34)
    {
        if (::IsFieldCZero((::Dummy_0069b080 *)(((NiTPointerMap<unsigned int, SoundPlaybackHandle*>*)this))))
            DAT_01202d98->v18(this);
        else
            reinterpret_cast<::ObjectC3 *>((((IOTask*)this)))->NotifyParents();
    }
}

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
// Iterates over every entry in mArray, passes each element to MarkTreeInstance, then calls FUN_006f7780.
// @fnv 0x006f9300
void BGSDistantTreeBlock::ProcessAllTrees()
{
    unsigned int i;
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(mArray))->GetName())); i++)
    {
        reinterpret_cast<::BGSDistantTreeBlock_shell *>(this)->MarkTreeInstance(*mArray.GetAt(i, 0), {});
    }
    reinterpret_cast<::fnv_006f7780::FUN_006f7780_Class *>(this)->FUN_006f7780();
}
// @fnv 0x006f9230
void BGSDistantTreeBlock_shell::MarkTreeInstance(unsigned int aID, bool abQueue)
{
    unsigned int pinst = 0;
    bool bfound = reinterpret_cast<::fnv_00853130::NiTMapBase *>((((DummyPointerMap*)((char*)this + 0x14))))->FUN_00853130(aID, (::fnv_00853130::CombatThreatRecord *&)(pinst));
    if (bfound)
    {
        ((InstanceDataB*)((char*)pinst + 0x1c))->b1c = 1;
        ((InstanceDataB*)((char*)*((ArrB*)((char*)this + 4))->GetAt((int)*(unsigned int*)((char*)pinst + 0x18))) + 0x1c)
            ->b1c = 0;
    }
    else if (abQueue)
        reinterpret_cast<::FUN_00438690 *>((((BSSimpleArrayStandIn*)&this->mArray)))->FUN_007cb2e0((unsigned int *)&((void*&)aID));
}

struct FUN_006b3120_helper
{
    unsigned char* GetElementAt(int);
};


// Clears each element's field at offset 0x1c, resets g_011d85bc, g_011d85c4, g_011d85e0, calls FUN_006f7a60(0) and clears DAT_011d85a0.
// @fnv 0x006f83f0
void FUN_006f83f0()
{
    int i;

    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&(*reinterpret_cast<::FUN_006b3140_shell *>(&::g_011d85d0)))))->GetName())); ++i)
    {
        ((NP*)(((FUN_006b3120_helper*)&(*reinterpret_cast<::FUN_006b3140_shell *>(&::g_011d85d0)))->GetElementAt(i) + 0x1c))->operator=(0);
    }

    (*reinterpret_cast<::NP *>(&::g_011d85bc)) = 0;
    (*reinterpret_cast<::NP *>(&::g_011d85c4)) = 0;
    (*reinterpret_cast<::NP *>(&::g_011d85e0)) = 0;
    FUN_006f7a60(0);
    DAT_011d85a0 = 0;
}

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


// @fnv 0x006f90a0
void FUN_006f90a0_shell::UpdateInstances(FUN_006f90a0_params params)
{
    unsigned int count = FUN_0042f5a0(
        ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(params.owner) + 8)))->GetName())), FUN_00bb6030());

    for (unsigned int i = 0; i < count; ++i)
    {
        FUN_006f90a0_instance* instance = reinterpret_cast<FUN_006f90a0_instance*>(
            ((void *)(reinterpret_cast<FUN_006b3120_shell*>(reinterpret_cast<unsigned char*>(params.owner) + 8)->GetElementAt(i))));

        reinterpret_cast<::BB7290Owner *>((params.renderer))->SetEntry(i, instance->f0, instance->f1, instance->f2, instance->f3,
                                  instance->flag ? 0.0f : instance->f4);
    }

    for (unsigned int j = count; j < FUN_00bb6030(); ++j)
    {
        reinterpret_cast<::BB7290Owner *>((params.renderer))->SetEntry(j, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    }

    params.owner->flag = 1;
}

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
// @fnv 0x006f7a80
void BuildNavMeshGeometry(void* pInParam)
{
    AutoMemHelper helper0(0x25, true, str_0106dd30, 0x95);
    float sB3;
    Obj44* obj304;
    NiPoint3* arrA3;
    unsigned short* idx2;
    float raw8h;
    float rawCa;
    float raw182;
    NiPoint2* arrB5;
    float sAh;
    NiPoint3* arrCy;
    unsigned int tB;
    unsigned int ju;
    unsigned int iy;
    float raw42;
    float raw145;
    float raw103;
    float tmpF1;
    unsigned int cntA3;
    unsigned int cntB;
    float* arrFk;
    unsigned short w4;
    cntA3 = FUN_00bb6030() << 2;
    cntB = FUN_00bb6030() << 3;
    arrA3 = new NiPoint3[cntB];
    arrB5 = new NiPoint2[cntB];
    arrCy = new NiPoint3[cntB];
    idx2 = new unsigned short[cntA3 * 3];
    raw42 = ((InParam*)pInParam)->f4;
    sAh = (float)(raw42 * 0.5);
    raw8h = ((InParam*)pInParam)->f8;
    sB3 = (float)(raw8h * 0.5);
    rawCa = ((InParam*)pInParam)->fc;
    raw103 = ((InParam*)pInParam)->f10;
    raw145 = ((InParam*)pInParam)->f14;
    raw182 = ((InParam*)pInParam)->f18;
    tmpF1 = FUN_004579e0(2.0f);
    for (iy = 0; iy < cntB; iy += 8)
    {
        arrA3[iy].x = -sAh;
        arrA3[iy].y = 0.0f;
        arrA3[iy].z = raw8h;
        arrB5[iy].x = rawCa;
        arrB5[iy].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
        arrA3[iy + 1].x = sAh;
        arrA3[iy + 1].y = 0.0f;
        arrA3[iy + 1].z = raw8h;
        arrB5[iy + 1].x = raw145;
        arrB5[iy + 1].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
        arrA3[iy + 2].x = -sAh;
        arrA3[iy + 2].y = 0.0f;
        arrA3[iy + 2].z = 0.0f;
        arrB5[iy + 2].x = rawCa;
        arrB5[iy + 2].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
        arrA3[iy + 3].x = sAh;
        arrA3[iy + 3].y = 0.0f;
        arrA3[iy + 3].z = 0.0f;
        arrB5[iy + 3].x = raw145;
        arrB5[iy + 3].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
        arrA3[iy + 4].x = 0.0f;
        arrA3[iy + 4].y = -sAh;
        arrA3[iy + 4].z = raw8h;
        arrB5[iy + 4].x = rawCa;
        arrB5[iy + 4].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
        arrA3[iy + 5].x = 0.0f;
        arrA3[iy + 5].y = sAh;
        arrA3[iy + 5].z = raw8h;
        arrB5[iy + 5].x = raw145;
        arrB5[iy + 5].y = raw103;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
        arrA3[iy + 6].x = 0.0f;
        arrA3[iy + 6].y = -sAh;
        arrA3[iy + 6].z = 0.0f;
        arrB5[iy + 6].x = rawCa;
        arrB5[iy + 6].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
        arrA3[iy + 7].x = 0.0f;
        arrA3[iy + 7].y = sAh;
        arrA3[iy + 7].z = 0.0f;
        arrB5[iy + 7].x = raw145;
        arrB5[iy + 7].y = raw182;
        arrCy[iy].x = DAT_01012054;
        arrCy[iy].y = 1.0f;
        arrCy[iy].z = 1.0f;
        reinterpret_cast<::FUN_004a0c10_s *>(&(arrCy[iy]))->FUN_004a0c10();
    }
    w4 = 0;
    for (ju = 0; ju < cntA3 * 3; ju += 6)
    {
        idx2[ju] = w4;
        idx2[ju + 1] = w4 + 1;
        idx2[ju + 2] = w4 + 2;
        idx2[ju + 3] = w4 + 1;
        idx2[ju + 4] = w4 + 3;
        idx2[ju + 5] = w4 + 2;
        w4 = w4 + 4;
    }
    arrFk = new float[cntB];
    for (tB = 0; tB < cntB; ++tB)
        arrFk[tB] = (float)(tB >> 3);
    obj304 = new Obj44((unsigned short)cntB);
    reinterpret_cast<::FUN_00a72ca0_Class *>((obj304))->FUN_00a72ca0(1);
    reinterpret_cast<::fnv_00a730e0::FUN_00a730e0_cls *>((obj304))->FUN_00a730e0(1);
    reinterpret_cast<::A72BB0_DataStreamOwner *>((obj304))->FUN_00a72bb0(0, arrFk, (int)(cntB * 4), 1);
    reinterpret_cast<::FUN_00a726a0_cls *>((obj304))->FUN_00a726a0(0, 0, 0, (void *)(1), (unsigned short)cntB, 4, 4);
    delete[] arrFk;
    GO refObj((int)new Obj88((unsigned short)cntB, arrA3, arrCy, 0, arrB5, 1, 0, (unsigned short)cntA3, idx2));
    ((NiGPUProgramOwner*)FUN_00559450((int*)&refObj))->SetProgram((NiGPUProgram*)obj304);
    ((InParam*)pInParam)->m1c = *(NavMeshPtr*)&refObj;
    ((PathingRef<PathingSolution>*)&refObj)->Reset(0);
}


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

// Finds or creates the tree block for auiType, adds apInstance to it, sets the instance's block index and flag, and registers it in kInstanceMap by ID.
// @fnv 0x006f8470
void TreeLODManager::AddTreeInstance(unsigned int auiType, TreeInstance* apInstance)
{
    AutoMemHelper kMem(0x25, true, str_0106dd30, 0x14b);
    TreeBlock* pBlock = 0;
    bool bFound8 = reinterpret_cast<::fnv_00853130::NiTMapBase *>(&(kBlockMap))->FUN_00853130(auiType, (::fnv_00853130::CombatThreatRecord *&)(pBlock));
    if (!bFound8 || !pBlock || ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pBlock->kInstances))->GetName())) == FUN_00bb6030())
    {
        if (auiType >= ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::TreeTypeArray *>(&::g_011d85d0))))->GetName())))
        {
            ::FUN_005b5e40();
            return;
        }
        pBlock = new TreeBlock;
        pBlock->pType = ((void *)(reinterpret_cast<::FUN_006b3120_shell *>(&((*reinterpret_cast<::TreeTypeArray *>(&::g_011d85d0))))->GetElementAt(auiType)));
        reinterpret_cast<::FUN_00438690 *>(&(kBlocks))->FUN_007cb2e0((unsigned int *)&(pBlock));
        kBlockMap.SetAt(auiType, pBlock);
        pBlock->iIndex = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kBlocks))->GetName())) - 1;
        reinterpret_cast<::FUN_006f9790_class *>(&(pBlock->kInstances))->FUN_006f9790(FUN_00bb6030());
        pBlock->bFull = 0;
    }
    reinterpret_cast<::FakeArray *>(&(pBlock->kInstances))->AppendInstance((::InstanceData *)(apInstance));
    int iLast = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pBlock->kInstances))->GetName())) - 1;
    TreeInstance* pInst6 = ((::TreeInstance *)(reinterpret_cast<::FUN_006b3120_shell *>(&(pBlock->kInstances))->GetElementAt(iLast)));
    pInst6->iBlockIndex = pBlock->iIndex;
    pInst6->bFlag = 0;
    kInstanceMap.SetAt(pInst6->uiID, pInst6);
}

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
// Reads a group count from the file, then for each group reads a type and size and reads that many NiBound instances, passing each to AddTreeInstance.
// @fnv 0x006f8b40
void FUN_006f8b40_shell::ReadGroups(NiFile* apInputFile)
{
    AutoMemHelper tempMemContext(0x25, true, str_0106dd30, 0x204);

    reinterpret_cast<::TreeOwnerS *>((this))->ClearEntries();

    unsigned int uinumGroups;
    reinterpret_cast<::FUN_00462d80_shell *>((apInputFile))->ReadBytes(&uinumGroups, 4);

    for (unsigned int i = 0; i < uinumGroups; ++i)
    {
        unsigned int uitype;
        unsigned int uisize;
        reinterpret_cast<::FUN_00462d80_shell *>((apInputFile))->ReadBytes(&uitype, 4);
        reinterpret_cast<::FUN_00462d80_shell *>((apInputFile))->ReadBytes(&uisize, 4);

        for (unsigned int j = 0; j < uisize; ++j)
        {
            NiBound instance;
            reinterpret_cast<::FUN_00462d80_shell *>((apInputFile))->ReadBytes(&instance, 0x20);
            reinterpret_cast<::TreeLODManager *>((this))->AddTreeInstance(uitype, (::TreeInstance *)(void *)(&instance));
        }
    }
}

// @fnv 0x006f86e0
void TreeOwnerS::ClearEntries()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(kEntries))->GetName())); i++)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(kEntries.GetAt(i)->kInstances))->Clear(true);
        if (kEntries.GetAt(i)->m_pController)
        {
            ((::NiNodeS *)(reinterpret_cast<::FUN_004ea9e0_Class *>((((RootHolderS*)(*(::NiPtrS< ::RootHolderS> *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())))))->FUN_004ea9e0()))->InsertChild(kEntries.GetAt(i)->m_pController);
            kEntries.GetAt(i)->m_pController = 0;
        }
        delete kEntries.GetAt(i);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(kEntries))->Clear(true);
}

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

// Reads a 4-byte record count from the host, then reads and processes that many 0x20-byte TreeRecords.
// @fnv 0x006f8f80
void ReadTreeRecords(TreeHost* host)
{
    TreeScopeGuard guardX(
        0x25, 1,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantTreeBlock.cpp",
        0x27e);
    ((FUN_006f9c70_shell*)&(*reinterpret_cast<::FUN_006b3140_shell *>(&::g_011d85d0)))->FUN_006f9c70(true);
    unsigned int count = 0;
    reinterpret_cast<::FUN_00462d80_shell *>((host))->ReadBytes(&count, 4);
    for (unsigned int i = 0; i < count; i++)
    {
        TreeRecord rec;
        reinterpret_cast<::FUN_00462d80_shell *>((host))->ReadBytes(&rec, 0x20);
        TreeTemp tmp(0);
        FUN_006f86b0(&rec);
    }
}

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

// @fnv 0x006f9060
FUN_006f9060::FUN_006f9060() : m_kMember(0)
{}

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

// @fnv 0x006f9080
void FUN_006f9080_owner::FUN_006f9080()
{
    reinterpret_cast<::FUN_0045cec0_Class *>(&(callee))->FUN_0045cec0();
}

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

// Initializes a QBase task for a distant tree block: stores the block, cell coordinates and LOD level, builds a path and sets the task name and flag.
// @fnv 0x006f9360
FUN_006f9360::FUN_006f9360(BGSDistantTreeBlock* apBlock, Fake076* apWorld, int aiCellX, int aiCellY, int aiLODLevel,
                           int aiUnused)
    : QBase(3)
{
    pBlock = apBlock;
    m_bValueAtOffset34 = false;
    m_iGridPositionX = aiCellX;
    m_iGridCoordinateY = aiCellY;
    iLODLevel = aiLODLevel;
    m_bHeaderParsed = false;
    char acPath[260];
    FormatTreeLodDtlPath(acPath, apWorld, aiLODLevel, (short)aiCellX, (short)aiCellY);
    reinterpret_cast<::FUN_00c3cee0_shell *>(this)->FUN_00c3cee0((char *)(acPath + 5));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>(this)->LookupFileEntryByArchive(0);
    bFadeQueuedCur = false;
}

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
// Calls FUN_006f94a0, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x006f9470
void* BGSDistantTreeBlockLoadTask::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_006f94a0 *>(this)->FUN_006f94a0::~FUN_006f94a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006f94a0
FUN_006f94a0::~FUN_006f94a0()
{}

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

// Opens the loader's filename as a file, loads it into the tree block if not cancelled, and sets the success flag.
// @fnv 0x006f9570
void B6F9570TreeLoader::LoadTreeFile()
{
    B6F9570File* pkFile = B6F9570FileFinder::GetFile(((const char *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())), 0, 0x800, 1);
    if (pkFile && !m_bCancelled)
    {
        reinterpret_cast<::FUN_006f8b40_shell *>((m_pkTreeBlock))->ReadGroups((::NiFile *)(pkFile));
        delete pkFile;
        m_bLoadComplete = true;
        reinterpret_cast<::BGSDistantTreeBlock *>((m_pkTreeBlock))->ProcessAllTrees();
    }
    else
    {
        m_bLoadComplete = false;
    }
}

struct Lod77Foo1
{
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


void* __cdecl FUN_00afdf00(char* path, int mode, unsigned int size);

// Builds the TreeTypes.lst mesh path and the tree LOD texture path, loads both, then populates the LOD containers and steps their elements.
// @fnv 0x006f77a0
void __cdecl LoadTreeLodResources(Fake076* self)
{
    char path[0x104];
    LodFile* f5;
    const char* texName;
    char texPath[0x104];

    ::FUN_00406d00(path, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Trees\\TreeTypes.lst", self->GetStr());
    f5 = (LodFile*)FUN_00afdf00(path, 0, 0x800);
    if (f5 != 0)
    {
        ReadTreeRecords((TreeHost*)f5);
        delete f5;
    }

    texName = "TreeDeadLOD.dds";
    if (!std::strncmp(self->GetStr(), "DLC4", 4))
    {
        texName = "TreeSwampLOD.dds";
    }
    ::FUN_00406d00(texPath, 0x104, "\\Data\\Textures\\Landscape\\Trees\\%s", texName);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::Lod77Mgr * *>(&::g_TES))))->FUN_004568c0(texPath, (*(::TexPtr< ::NiSourceTexture> *)(&(*reinterpret_cast<::Lod77Container *>(&::g_011d85e0)))), 1, 1);
    if (!((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::Lod77Container *>(&::g_011d85e0)))))))
    {
        ::FUN_005b5e40();
    }
    FUN_006f7a60(((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::Lod77Container *>(&::g_011d85e0)))))));
    DAT_011d85a0 = 1;

    (*reinterpret_cast<::Lod77Container *>(&::g_011d85bc)).Add(new Lod77Foo1());
    reinterpret_cast<::fnv_0049ee30::NiObjectNET *>((((::Lod77Elem *)(::FUN_00559450((int *)&((*reinterpret_cast<::Lod77Container *>(&::g_011d85bc))))))))->FUN_0049ee30({});

    (*reinterpret_cast<::Lod77Container *>(&::g_011d85c4)).Add(new Lod77Foo2());
    reinterpret_cast<::Flag512Receiver *>((((::Lod77Elem *)(::FUN_00559450((int *)&((*reinterpret_cast<::Lod77Container *>(&::g_011d85c4))))))))->SetFlag512({});
    reinterpret_cast<::FUN_0049ed90_shell *>((((::Lod77Elem *)(::FUN_00559450((int *)&((*reinterpret_cast<::Lod77Container *>(&::g_011d85c4))))))))->FUN_0049ed90({});
    reinterpret_cast<::FUN_0094db80_shell *>((((::Lod77Elem *)(::FUN_00559450((int *)&((*reinterpret_cast<::Lod77Container *>(&::g_011d85c4))))))))->FUN_0094db80({});
    reinterpret_cast<::NiObjectNET *>((((::Lod77Elem *)(::FUN_00559450((int *)&((*reinterpret_cast<::Lod77Container *>(&::g_011d85c4))))))))->SetFlags({});
}

struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex(float, float, float);
    NiPoint3Ex operator-(const NiPoint3Ex&) const;
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
    NiPoint3Ex FUN_0053d280(float) const;
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
// Computes the bounding sphere of a tree block: min/max of instance positions, center, and radius including the geometry bound.
// @fnv 0x006f8910
FUN_006240d0 TreeBoundsOwner::ComputeTreeBounds(BoundTreeBlock* block)
{
    std::uintptr_t maximum;
    FUN_006240d0 bound;
    // Local spellings preserve the original MSVC9 /Od stack layout.
    // minimum: largest finite float; count: lower corner; limit: upper corner.
    float minimum = 3.402823466e+38F;
    NiPoint3Ex count(minimum, minimum, minimum);
    NiPoint3Ex limit(-minimum, -minimum, -minimum);
    // maximum is the number of instance positions.
    maximum = ((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(block->instances))->GetName()));
    for (unsigned int i = 0; i < maximum; ++i)
    {
        count.x = FUN_0040ebd0(count.x, ((::NiPoint3Ex *)(reinterpret_cast<::FUN_006b3120_shell *>(&(block->instances))->GetElementAt(i)))->x);
        limit.x = FUN_00404010(limit.x, ((::NiPoint3Ex *)(reinterpret_cast<::FUN_006b3120_shell *>(&(block->instances))->GetElementAt(i)))->x);
        count.y = FUN_0040ebd0(count.y, ((::NiPoint3Ex *)(reinterpret_cast<::FUN_006b3120_shell *>(&(block->instances))->GetElementAt(i)))->y);
        limit.y = FUN_00404010(limit.y, ((::NiPoint3Ex *)(reinterpret_cast<::FUN_006b3120_shell *>(&(block->instances))->GetElementAt(i)))->y);
        count.z = FUN_0040ebd0(count.z, ((::NiPoint3Ex *)(reinterpret_cast<::FUN_006b3120_shell *>(&(block->instances))->GetElementAt(i)))->z);
        limit.z = FUN_00404010(limit.z, ((::NiPoint3Ex *)(reinterpret_cast<::FUN_006b3120_shell *>(&(block->instances))->GetElementAt(i)))->z);
    }
    NiPoint3Ex center = count + (limit - count).FUN_0053d280(2.0f);
    float radius = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3Ex &)((limit - center)))->ComputeMagnitude() + reinterpret_cast<::Twin_0084d030 *>((((::TreeGeometry *)(::FUN_00559450((int *)&(block->geometry))))->GetBound()))->GetStoredFloatValue();
    reinterpret_cast<::FUN_004a51d0_shell *>(&(bound))->FUN_004a51d0((void *)&(center), radius);
    return bound;
}

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
// @fnv 0x006f8c40
void OwnerX::FUN_006f8c40()
{
    AutoMemHelper guard(0x25, true, str_0106dd30, 0x240);
    if (loaded && !built)
    {
        for (unsigned int index4 = 0; index4 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(entries))->GetName())); ++index4)
        {
            EntryX* aA = entries.GetAt(index4);
            aA->node = new NewNodeX(entries.GetAt(index4)->type->name);
            reinterpret_cast<::FUN_00705b10_Dummy *>((((NodeX*)aA->node)))->Set(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrayX*)&aA->instances)))->GetName())) * 4);
            PropertyX* propertyA = new PropertyX;
            reinterpret_cast<::FUN_006f90a0_shell *>(this)->UpdateInstances({(FUN_00bb7290_shell*)propertyA, (FUN_006f90a0_owner*)aA});
            reinterpret_cast<::FUN_00439410_cls *>((((NodeX*)aA->node)))->FUN_00439410((::ArgObject *)(propertyA));
            ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::NodeX *)(aA->node), 0, 0);
            reinterpret_cast<::FUN_00439410_cls *>((((NodeX*)aA->node)))->FUN_00439410((::ArgObject *)(void *)(((NiPtrS<void>*)&(*reinterpret_cast<::NP *>(&::g_011d85bc)))->operator void*()));
            reinterpret_cast<::FUN_00439410_cls *>((((NodeX*)aA->node)))->FUN_00439410((::ArgObject *)(void *)(((NiPtrS<void>*)&(*reinterpret_cast<::NP *>(&::g_011d85c4)))->operator void*()));
            ((::NodeX *)(reinterpret_cast<::FUN_004ea9e0_Class *>((((HolderX*)(*(::NiPtrS< ::HolderX> *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())))))->FUN_004ea9e0()))->Attach(aA->node, true);
            reinterpret_cast<::FUN_00a5a040_Class *>((((NodeX*)aA->node)))->FUN_00a5a040();
            UpdateDataX firstUpdate(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((NodeX*)aA->node)))->FUN_00a59c60((std::intptr_t)&(firstUpdate));
            UpdateDataX rootUpdate(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::NodeX *)(reinterpret_cast<::TESRegionDataMap *>((((HolderX*)(*(::NiPtrS< ::HolderX> *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())))))->GetRegionMapName()))))->FUN_00a59c60((std::intptr_t)&(rootUpdate));
            ((NodeX*)aA->node)->SetObjectBound(GetBound(aA));
            UpdateDataX finalUpdate(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((NodeX*)aA->node)))->FUN_00a59c60((std::intptr_t)&(finalUpdate));
        }
        built = true;
    }
    else if (loaded && built)
        reinterpret_cast<::BGSDistantTreeBlock *>(this)->ProcessAllTrees();
}

void FUN_006f7a60(void* p);

struct FUN_006b3140_shell_o2_nood
{
};

void FUN_006f86b0(void* a1);

struct FUN_006f8800_shell_o2_nood
{
    void* FUN_006f8800(unsigned int flags);
};

struct FUN_006b3120_helper_o2_nood
{
};

void FUN_006f83f0();

void BuildNavMeshGeometry(void* param);

void ReadTreeRecords(TreeHost* host);

int __cdecl FUN_00ec8a19(const char* a, const char* b, int c);

struct NiPoint3Ex_o2_nood
{
    float x, y, z;
    NiPoint3Ex_o2_nood(float, float, float);
    NiPoint3Ex_o2_nood operator-(const NiPoint3Ex_o2_nood&) const;
    NiPoint3Ex_o2_nood operator+(const NiPoint3Ex_o2_nood&) const;
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

    int FUN_00bb6050(int arg0, int arg1);
};

// @fnv 0x00bb6050
int S_00bb6050::FUN_00bb6050(int arg0, int arg1)
{
    return this->unk80;
}

struct BGSDistantTreeBlockLoadTask_o2
{
    void* Destroy(unsigned int flags);
};

extern unsigned int DAT_012007b8;

// @fnv 0x00bb6030
unsigned int __cdecl FUN_00bb6030()
{
    if (!DAT_012007b8)
        DAT_012007b8 = 40 + ((::DAT_011f91c0 < 2) ? 0 : 74);
    return DAT_012007b8;
}

#include "generated/data/fallout_shared/distant terrain system/bgsdistanttreeblock.inc"
