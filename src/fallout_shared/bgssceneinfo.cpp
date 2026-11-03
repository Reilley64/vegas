
// src/fallout_shared/bgssceneinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgssceneinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "runtime/crt.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/BSShaderLightingProperty.h"
#include "fnv/decl/C4A9A60Array.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0041f050_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00438b90_class.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_00444ed0_shell.h"
#include "fnv/decl/FUN_0045a1c0_cls.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_004a8ab0_shell.h"
#include "fnv/decl/FUN_004a97e0_Class.h"
#include "fnv/decl/FUN_004a9850.h"
#include "fnv/decl/FUN_004a98e0_class.h"
#include "fnv/decl/FUN_004a9ab0_cls.h"
#include "fnv/decl/FUN_004a9b50_Class.h"
#include "fnv/decl/FUN_004aa3d0_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_0057c850_cls.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009a3910_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a72550_Class.h"
#include "fnv/decl/FUN_00a727b0_Class.h"
#include "fnv/decl/Fake_FUN_004a2020.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiTMapContainer.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/TES.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004a9000.h"
#include "fnv/symbols_00545000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00565000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_009ee000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00b70000.h"
#include "fnv/symbols_00c51000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
struct FUN_004a7cf0_shell
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    int m_0030;
    int m_0034;
    int m_0038;
    int m_003c;

    int GetValueAt(int index);
};

// @fnv 0x004a7cf0
int FUN_004a7cf0_shell::GetValueAt(int index)
{
    if (index >= 0 && index < 16)
    {
        return *(reinterpret_cast<int*>(this) + index + 1);
    }
    return 0;
}

struct Flt
{
    operator unsigned int() const;
};

struct Script
{
};

struct FUN_004a8070_shell
{
    int GetScriptText();
};

// Calls GetText on the Script pointer stored at offset 0xb8 of this object and returns the result.
// @fnv 0x004a8070
int FUN_004a8070_shell::GetScriptText()
{
    return ((int)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)((unsigned int)(*(Flt*)((char*)this + 0xb8))))))->GetIconFormID()));
}

extern unsigned char DAT_0118868c;

// @fnv 0x004a82c0
unsigned char __cdecl FUN_004a82c0()
{
    return DAT_0118868c;
}

// Returns the smaller of the two integer arguments.
// @fnv 0x004a8f20
int __cdecl MinInt(int iA, int iB)
{
    int result;
    if (iA < iB)
        result = iA;
    else
        result = iB;
    return result;
}

struct FUN_004a8f50_shell
{
    void* FUN_004a8f50();
};

struct GlobalObject2_0040c150
{
};

struct GlobalObject2_0045cfe0
{
};

GlobalObject2_0045cfe0 g_011c59e0;

// @fnv 0x004a9100
int FUN_004a9100()
{
    return *((int *)&(::FUN_0043d4d0((int *)&(g_011c59e0))));
}

struct DummyArr
{
    int GetBufferElementAddress(unsigned int);
    int FUN_004a95b0(unsigned int);
};

// @fnv 0x004a95b0
int DummyArr::FUN_004a95b0(unsigned int a)
{
    return GetBufferElementAddress(a);
}

struct FUN_004a9630_shell
{
    void* FUN_004a9630(unsigned int flags);
};

struct FUN_004a9850_shell
{
};


// @fnv 0x004a9630
void* FUN_004a9630_shell::FUN_004a9630(unsigned int flags)
{
    reinterpret_cast<::FUN_004a9850 *>((((FUN_004a9850_shell*)this)))->FUN_004a9850::~FUN_004a9850();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_0101ec68;

struct FUN_004a7c40_shell
{
    void* FUN_004a7c40();
};


struct FUN_004a7c80_shell
{
    void* ClearToZero();
};
// @fnv 0x004a7c40
void* FUN_004a7c40_shell::FUN_004a7c40()
{
    *(int*)this = (int)&DAT_0101ec68;
    reinterpret_cast<::FUN_004a7c80_shell *>((((FUN_004a7c40_shell*)((char*)this + 4))))->ClearToZero();
    ::FUN_00403d30((char*)this + 4, 0, 0x40);
    *(int*)((char*)this + 0x44) = 0;
    return this;
}

// @fnv 0x004a7c80
void* FUN_004a7c80_shell::ClearToZero()
{
    ::FUN_00403d30(this, 0, 0x40);
    return this;
}

struct BGSSceneInfo_shell
{
    void* Destroy(unsigned int flags);
};
extern int DAT_0101ec68;

struct FUN_004a7cd0_shell
{
    int* m_0000;
    void FUN_004a7cd0();
};
// Calls FUN_004a7cd0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004a7ca0
void* BGSSceneInfo_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_004a7cd0_shell *>(this)->FUN_004a7cd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004a7cd0
void FUN_004a7cd0_shell::FUN_004a7cd0()
{
    m_0000 = &DAT_0101ec68;
}

struct BSThread
{
};
struct FUN_004a8030_shell
{
    unsigned int FUN_004a8030();
};
// Returns the thread ID of the BSThread stored at offset 0xb8 of this object.
// @fnv 0x004a8030
unsigned int FUN_004a8030_shell::FUN_004a8030()
{
    return reinterpret_cast<::ActorMover *>((((BSThread*)((Flt*)((char*)this + 0xb8))->operator unsigned int())))->GetCurrentMoveModeType();
}

struct Proc_S
{
};
struct This_004a8050
{
    void* GetNextProc();
};
// Returns the result of GetNext() on the Proc_S pointer stored at offset 0xB8 of this object.
// @fnv 0x004a8050
void* This_004a8050::GetNextProc()
{
    return ((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)(unsigned int)*(Flt*)((char*)this + 0xB8))))->FUN_0045cd60()));
}

extern int DAT_0101ecec;
struct FUN_004a95d0_shell
{
    void* FUN_004a95d0(int a);
};
// @fnv 0x004a8f50
void* FUN_004a8f50_shell::FUN_004a8f50()
{
    reinterpret_cast<::FUN_004a95d0_shell *>((((FUN_004a8f50_shell*)((char*)this + 4))))->FUN_004a95d0(0x25);
    return this;
}

// Calls FUN_004a97e0(a), stores the address of DAT_0101ecec into this, and returns this.
// @fnv 0x004a95d0
void* FUN_004a95d0_shell::FUN_004a95d0(int a)
{
    reinterpret_cast<::FUN_004a97e0_Class *>(this)->FUN_004a97e0(a);
    *(int*)this = (int)&DAT_0101ecec;
    return this;
}

extern int DAT_0101ed0c;

struct FUN_004a9600_shell
{
    int m_0000;
    void* FUN_004a9600(void* arg);
};

// Calls FUN_004a98e0 on arg, stores the address of DAT_0101ed0c in m_0000, and returns this.
// @fnv 0x004a9600
void* FUN_004a9600_shell::FUN_004a9600(void* arg)
{
    reinterpret_cast<::FUN_004a98e0_class *>(this)->FUN_004a98e0((int)(arg));
    m_0000 = (int)&DAT_0101ed0c;
    return this;
}

struct FUN_004a9970_shell
{
    void FUN_004a9970();
    void* FUN_004a9660(unsigned int flags);
};

struct Target
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
};
struct FUN_004a8090_shell
{
    char _pad[0xB8];
    Flt m_kHandle;
    int CallTargetV36();
};
// @fnv 0x004a8090
int FUN_004a8090_shell::CallTargetV36()
{
    return ((Target*)(unsigned int)m_kHandle)->v36();
}

struct INISettingCollection
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05(unsigned int a);
};
struct SettingT
{
    static INISettingCollection* __cdecl GetCollection();
};

// @fnv 0x004a8fe0
void __cdecl FUN_004a8fe0()
{
    int i;
    for (i = 0; i < 0x10; ++i)
    {
        SettingT::GetCollection()->v05(*(unsigned int*)(0x01188694 + i * 0x14));
        SettingT::GetCollection()->v05(*(unsigned int*)(0x01188698 + i * 0x14));
    }
}

struct GlobalObject_0045cfe0
{
};
struct TESWorldSpace
{
    TESWorldSpace* GetParentWorld(int);
};
struct CP_008c48d0
{
};
struct TESSaveLoadGame
{
};
struct _ref_0084e3a0
{
};
extern GlobalObject_0045cfe0 g_011c5b20;
extern GlobalObject_0045cfe0 g_011c5ae0;
extern GlobalObject2_0045cfe0 g_011c5c04;
// @fnv 0x004a9050
int FUN_004a9050()
{
    int iValue = *((int *)&(::FUN_0043d4d0((int *)&(g_011c5b20))));
    if (!((int)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)g_TES)))->GetPrevPath())))
    {
        TESWorldSpace* pworld = ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((((TESSaveLoadGame*)g_TES)))->GetHitSound()));
        TESWorldSpace* pLODworld;
        pLODworld = pworld;
        while (pLODworld && pLODworld->GetParentWorld(1))
            pLODworld = pLODworld->GetParentWorld(1);
        if (pLODworld)
        {
            int iadjust = 0;
            if (reinterpret_cast<::FUN_0084e3a0_Class *>((((_ref_0084e3a0*)pLODworld)))->FUN_0084e3a0() == 0x3c)
                iadjust = *((int *)&(::FUN_0043d4d0((int *)&(g_011c5ae0))));
            else
                iadjust = *((int *)&(::FUN_0043d4d0((int *)&(g_011c5c04))));
            iValue -= iadjust;
        }
    }
    return iValue;
}

struct NiNode;

struct GlobalObject_004a9e90
{
};

struct GlobalObject_004aa1b0
{
};

struct GlobalObject_004a9d80
{
};

struct GlobalObject_004a9bf0
{
};

extern GlobalObject_004a9e90 g_011c5be8;
extern GlobalObject_004aa1b0 g_011c5ad0;
extern GlobalObject_004a9d80 g_011c5ab4;
extern GlobalObject_004a9bf0 g_011c5c40;
extern unsigned char DAT_0118868d;

struct FUN_004a8230_shell
{
    void AccumulateSceneStatistics(NiNode* node, void* data, bool trackActors, bool extra);
    void ResetAndProcessNode(NiNode* node, bool includeAddonNodes, bool trackActors);
};

struct SceneDescription
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* Name();
    const char* FUN_0048cee0();
};
struct SceneRecord
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
    SceneDescription description;
};
struct SceneInfo
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
};
struct SceneSource
{
};
struct SceneCache
{
};
struct SceneLoader
{
};
extern SceneSource* DAT_011c3f2c;
extern SceneLoader* DAT_011c3b3c;
extern SceneCache DAT_011c5ab4;
void __cdecl FUN_00406d50(char*, unsigned int, const char*);
struct LoadScenes
{
    void AccumulateSceneStatistics(void*, void*, int, int);
    void LoadSceneModels();
};
struct SearchRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct S5460
{
};
struct NavMeshSearchLOSArray
{
    virtual void v0();
    virtual SearchRecord* Allocate(unsigned int);
    SearchRecord* data;
    unsigned int count, capacity;
    void InsertAt(unsigned int, const SearchRecord&);
};
// @fnv 0x004a8230
void FUN_004a8230_shell::ResetAndProcessNode(NiNode* node, bool includeAddonNodes, bool trackActors)
{
    reinterpret_cast<::FUN_00438af0_Class *>(&(g_011c5be8))->FUN_00438af0();
    reinterpret_cast<::FUN_00438af0_Class *>(&(g_011c5ad0))->FUN_00438af0();

    if (includeAddonNodes && DAT_0118868d && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(g_011c5ab4))->GetName())) == 0)
        reinterpret_cast<::LoadScenes *>((this))->LoadSceneModels();

    ::FUN_00403d30((char*)this + 4, 0, 0x40);

    this->AccumulateSceneStatistics(node, (char*)this + 4, trackActors, 0);

    if (FUN_004a82c0())
        reinterpret_cast<::FUN_00438af0_Class *>(&(g_011c5c40))->FUN_00438af0();
}
// Iterates all scenes, fills a SceneInfo per index, builds a model path from the scene description name, loads it, and registers it unless already loaded.
// @fnv 0x004a80c0
void LoadScenes::LoadSceneModels()
{
    unsigned int count = reinterpret_cast<::BSFaceGenMorphData *>((DAT_011c3f2c))->DynamicCast();
    for (unsigned int uiSceneIndex = 0; uiSceneIndex < count; ++uiSceneIndex)
    {
        SceneInfo sceneInfo;
        reinterpret_cast<::FUN_004a7c80_shell *>(&(sceneInfo))->ClearToZero();
        reinterpret_cast<::NavMeshSearchLOSArray *>(&(DAT_011c5ab4))->InsertAt(uiSceneIndex, (*(const ::SearchRecord *)(&sceneInfo)));
        SceneRecord* pSceneRecord = ((::SceneRecord *)(reinterpret_cast<::TESDataHandler *>((DAT_011c3f2c))->GetAddonNodeByIndex(uiSceneIndex)));
        if (pSceneRecord)
        {
            bool loaded = false;
            if (pSceneRecord->description.FUN_0048cee0())
            {
                char cPath[260];
                ::TaskQueueInterface::CopyStringToBuffer(cPath, 260, &::fnv_00448080::DAT_01016fac);
                FUN_00406d50(cPath, 260, pSceneRecord->description.Name());
                void* model = ((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((DAT_011c3b3c))->FUN_00447080((char *)(cPath), 0, 1, 0, 0, 0)));
                if (model)
                {
                    if (!::FUN_00c511f0((::FUN_00c511f0_cls *)(model)))
                        AccumulateSceneStatistics(((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f4428))), (::NiObject *)(model)))),
                                                  ((void *)(reinterpret_cast<::DummyArr *>(&(DAT_011c5ab4))->FUN_004a95b0(uiSceneIndex))), 0, 0);
                    reinterpret_cast<::FUN_0045a5e0_shell *>((DAT_011c3b3c))->FUN_0045a5e0((char *)(cPath));
                }
            }
        }
    }
}
// @fnv 0x004a9690
void NavMeshSearchLOSArray::InsertAt(unsigned int index, const SearchRecord& value)
{
    if (index == count)
    {
        reinterpret_cast<::C4A9A60Array *>(this)->AddEntry((const ::C4A9A60Entry &)(value));
        return;
    }
    if (((bool)(reinterpret_cast<::FUN_00438b90_class *>((((S5460*)this)))->FUN_00438b90())))
    {
        unsigned int fresh = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>((((S5460*)this)))->FUN_009a3910()));
        SearchRecord* newCapacity = Allocate(fresh);
        reinterpret_cast<::FUN_004a9b50_Class *>(this)->CopyBlocks((char *)(newCapacity), (char *)(data), index);
        reinterpret_cast<::FUN_004a9ab0_cls *>(this)->ConstructScanItems((int)(newCapacity + index), 1);
        reinterpret_cast<::FUN_004a9b50_Class *>(this)->CopyBlocks((char *)(::SearchRecord *)(newCapacity + index + 1), (char *)(::SearchRecord *)(data + index), count - index);
        ::FUN_006a8500((::DummyClass_006a8500 *)this);
        data = newCapacity;
        capacity = fresh;
    }
    else
    {
        reinterpret_cast<::FUN_004a9b50_Class *>(this)->CopyBlocks((char *)(::SearchRecord *)(data + index + 1), (char *)(::SearchRecord *)(data + index), count - index);
        reinterpret_cast<::FUN_004a9ab0_cls *>(this)->ConstructScanItems((int)(data + index), 1);
    }
    count = count + 1;
    data[index] = value;
}

struct SceneOwner;
struct SceneItem
{
};
struct ItemList
{
};
struct OuterRecord
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    ItemList items;
};
struct OuterList
{
};
struct SceneManager
{
};
struct SceneGlobal
{
};
struct FUN_004a9600
{
    int unk00, unk04, unk08, unk0c;
    FUN_004a9600(unsigned int);
    ~FUN_004a9600();
};
struct FUN_0042f4e0
{
    int unk00, unk04, unk08, unk0c;
    FUN_0042f4e0(unsigned int);
    ~FUN_0042f4e0();
};
struct ScriptProgram
{
};
struct MeshPart
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual ScriptProgram* v7();
};
struct MeshGroup
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};
struct MeshObject
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
    virtual MeshGroup* v116();
};
struct MeshNode
{
};
struct SceneOwner
{
};
struct SceneCounter
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int count;
    int unk28, unk2c;
    int bytes;
    void AccumulateSceneStats(SceneOwner* owner);
};
// Walks the scene's outer and item lists counting items owned by owner, then walks the owner's mesh nodes summing per-part byte sizes into bytes.
// @fnv 0x004a7d20
void SceneCounter::AccumulateSceneStats(SceneOwner* owner)
{
    OuterList* j = ((::OuterList *)(reinterpret_cast<struct ::FUN_005a8080 *>((((::SceneManager *)(::FUN_0070ec90((char *)((*reinterpret_cast<::SceneGlobal * *>(&::g_TES))))))))->GetField()));
    FUN_004a9600 e(0x25);
    FUN_0042f4e0 k(0x25);
    void* ba = ((void *)(::FUN_00559450((int *)(j))));
    void* l = 0;
    while (ba)
    {
        l = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((j))->DereferenceIfNotNull((int **)(ba))));
        if (ba)
        {
            OuterRecord* q = *((::OuterRecord **)(reinterpret_cast<::FUN_006317a0_struct *>((j))->AddEight((int)(ba))));
            if (q)
            {
                int eb = 0;
                void* s = ((void *)(::FUN_00559450((int *)&(q->items))));
                void* cf = 0;
                bool f = false;
                while (s)
                {
                    cf = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(q->items))->DereferenceIfNotNull((int **)(s))));
                    SceneItem* i = *((::SceneItem **)(reinterpret_cast<::FUN_006317a0_struct *>(&(q->items))->AddEight((int)(s))));
                    if (!reinterpret_cast<::FUN_0057c850_cls *>(&(e))->FUN_0057c850(((::SceneOwner *)(reinterpret_cast<::LowProcess *>((i))->GetTarget())), &f))
                        ++eb;
                    if (!reinterpret_cast<::FUN_0057c850_cls *>(&(k))->FUN_0057c850(i, &f) && ((::SceneOwner *)(reinterpret_cast<::LowProcess *>((i))->GetTarget())) == owner)
                    {
                        ++this->count;
                        reinterpret_cast<::FUN_0084d310_class *>(&(k))->FUN_0084d310((int)(i), 1);
                    }
                    reinterpret_cast<::FUN_0084d310_class *>(&(e))->FUN_0084d310((int)(((::SceneOwner *)(reinterpret_cast<::LowProcess *>((i))->GetTarget()))), 1);
                    s = cf;
                }
                if (reinterpret_cast<::FUN_0057c850_cls *>(&(e))->FUN_0057c850(owner, &f))
                {
                    int a = 0;
                }
            }
        }
        reinterpret_cast<::FUN_00438af0_Class *>(&(e))->FUN_00438af0();
        ba = l;
    }
    MeshNode* c = ((::MeshNode *)(::FUN_00545710((int)(owner))));
    while (c && *((::MeshObject **)(new ((void *)(c)) ::Vec3())))
    {
        MeshObject* h = *((::MeshObject **)(new ((void *)(c)) ::Vec3()));
        MeshGroup* p = h->v116();
        if (p && p->v4())
        {
            MeshPart* h2 = ((::MeshPart *)(reinterpret_cast<::NiNode *>((p))->GetAt(0)));
            ScriptProgram* b = h2->v7();
            if (b)
            {
                int e2 = 0;
                unsigned int j2 = ((unsigned short)(reinterpret_cast<::FUN_004a8090_shell *>((b))->CallTargetV36()));
                if (((int)(reinterpret_cast<::FUN_0049ec60 *>((b))->GetNext())))
                    e2 += j2 * 12;
                if (((int)(reinterpret_cast<::This_004a8050 *>((b))->GetNextProc())))
                    e2 += j2 * 16;
                if (((int)(reinterpret_cast<::FUN_004a8030_shell *>((b))->FUN_004a8030())))
                    e2 += j2 * 12;
                if (reinterpret_cast<::FUN_004a8070_shell *>((b))->GetScriptText())
                    e2 += j2 * 8;
                this->bytes += e2;
            }
        }
        c = ((::MeshNode *)(reinterpret_cast<::Callees *>((c))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00438af0_Class *>(&(k))->FUN_00438af0();
}

namespace fnv_004a82d0 {
struct StatsBase;
struct SceneName
{
    const char* FUN_0043b1b0();
};
struct StatObject;
struct StatForm
{
    int FUN_00401170();
};
struct StatLink
{
};
struct StatNodeLink
{
};
struct StatKey
{
};
struct StatKeyHolder
{
};
struct StatRef
{
};
struct StatActor
{
};
struct StatExtra
{
};
struct StatMap
{
};
struct StatUnique
{
};
struct StatTextureSet
{
};
struct StatTextureCount
{
};
struct StatGeom
{
};
struct ScriptExecutionContext
{
    unsigned short FUN_004a1ff0();
};
struct StatBlocks
{
};
struct StatSkin
{
};
struct StatProperty;
struct StatObject
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual StatObject* AsNode();
    virtual void* AsFade();
    virtual void Slot05();
    virtual StatObject* AsGeometry();
    virtual ScriptExecutionContext* GetData();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Visit(void(__cdecl*)(void*, void*), int**);
    unsigned int FUN_0043b480();
};
struct StatDetector
{
};

extern StatUnique DAT_011c5b30;

extern StatTextureCount DAT_011c5a90;
struct SceneStatistics
{
    int unk00;
    int counters[16];
    void AccumulateSceneStatistics(StatObject* object, int* output, bool trackActors, StatObject* parent);
};
// Walks the scene object tree and accumulates per-category counts into output or counters, then calls DAT_011dea10->ClearQueuedFile().
// @fnv 0x004a82d0
void SceneStatistics::AccumulateSceneStatistics(StatObject* object, int* output, bool trackActors, StatObject* parent)
{
    int* counts;
    if (output)
        counts = output;
    else
        counts = counters;
    if (object)
    {
        bool addon = false;
        bool actorNode = false;
        StatObject* node3 = object->AsNode();
        if (node3)
        {
            if (((::fnv_004a82d0::SceneName *)(reinterpret_cast<::TESTopicInfoData *>((node3))->GetLinkToList()))->FUN_0043b1b0() &&
                !fnv::crt::strnicmp(((::fnv_004a82d0::SceneName *)(reinterpret_cast<::TESTopicInfoData *>((node3))->GetLinkToList()))->FUN_0043b1b0(), "FurnitureMarker", 15))
                return;
            if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_01202de8))), (::NiAVObject *)(node3)))
            {
                StatExtra* extra = (StatExtra*)((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_01202de8))), (::NiObject *)(node3))));
                int index = ::FUN_009ee040((char *)(extra));
                if (index >= 0 && index < (int)reinterpret_cast<::BSFaceGenMorphData *>((DAT_011c3f2c))->DynamicCast() &&
                    index < ((int)(reinterpret_cast<::Twin_0044ddc0 *>((((StatMap*)&g_011c5ab4)))->GetName())))
                {
                    for (int i = 0; i < 16; i++)
                    {
                        switch (i)
                        {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            break;
                        default:
                            counts[i] += ((int *)(reinterpret_cast<::DummyArr *>((((StatMap*)&g_011c5ab4)))->FUN_004a95b0(index)))[i];
                            break;
                        }
                    }
                }
            }
            bool isActor2 = false;
            StatRef* reference = 0;
            StatObject* fade = 0;
            if (node3->AsFade())
                fade = node3;
            if (fade && (reference = ((::fnv_004a82d0::StatRef *)(reinterpret_cast<::BSFadeNode *>((fade))->FUN_009ad610()))) && !reinterpret_cast<::FUN_00444ed0_shell *>((reference))->FUN_00444ed0() && (!actorNode || !addon))
            {
                counts[0]++;
                if (::fnv_00565580::FUN_00565580((::fnv_00565580::NiAVObject *)(object)))
                {
                    counts[2]++;
                    if (!reinterpret_cast<::RefList *>(&(DAT_011c5b30))->FUN_005f65d0((void **)&(const int &)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_004a82d0::StatForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))))->FUN_0084e3a0())))
                    {
                        counts[3]++;
                        reinterpret_cast<::Callees *>(&(DAT_011c5b30))->FUN_00905820((void *)&(const int &)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_004a82d0::StatForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))))->FUN_0084e3a0()));
                    }
                }
                StatNodeLink* link = (StatNodeLink*)((::fnv_004a82d0::StatForm *)(reinterpret_cast<::FUN_0041f050_shell *>((((::fnv_004a82d0::StatLink *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041f050()));
                while (link && *((int *)(new ((void *)(link)) ::Vec3())))
                {
                    counts[14]++;
                    link = ((::fnv_004a82d0::StatNodeLink *)(reinterpret_cast<::Callees *>((link))->FUN_00726070()));
                }
                switch (((::fnv_004a82d0::StatForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170())
                {
                case 42:
                case 43:
                case 44:
                case 45:
                    counts[1]++;
                    isActor2 = true;
                    break;
                }
                StatActor* actor = ((::fnv_004a82d0::StatActor *)(::FUN_004a8b00((::BGSBodyPart *)(object))));
                if (actor)
                {
                    StatKeyHolder* holder = ((::fnv_004a82d0::StatKeyHolder *)(::fnv_006fa820::FUN_006fa820((const char *)(actor))));
                    StatKey* key = holder ? ((::fnv_004a82d0::StatKey *)(reinterpret_cast<::FUN_0043b560_shell *>((holder))->GetSourceFilesFromObject())) : 0;
                    StatForm* form1 = key ? ((::fnv_004a82d0::StatForm *)(::FUN_00559450((int *)(key)))) : 0;
                    if (form1)
                        counts[15] += ::FUN_004a9240((::Node *)(form1));
                }
            }
            if (isActor2 && !trackActors)
                return;
            if (!actorNode || !addon)
            {
                unsigned int childCount = node3->FUN_0043b480();
                for (unsigned int child = 0; child < childCount; child++)
                {
                    StatObject* next = ((::fnv_004a82d0::StatObject *)(reinterpret_cast<::NiNode *>((node3))->GetAt(child)));
                    AccumulateSceneStatistics(next, output, false, node3);
                }
            }
        }
        else
        {
            StatObject* geometry = object->AsGeometry();
            if (geometry)
            {
                bool addonGeometry = false;
                bool actorGeometry = false;
                if (!actorGeometry || !addonGeometry)
                {
                    counts[6]++;
                    StatObject* property = (StatObject*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((geometry))->FUN_00a59d30(3)));
                    StatObject* textureProperty1 = !property ? 0 : ((int)(reinterpret_cast<::BGSTerrainManager *>((property))->GetMinLevel())) != -1 ? property : 0;
                    if (textureProperty1)
                    {
                        int* textureCount = &counts[10];
                        textureProperty1->Visit(((void (&)(void *, void *))::AddToRefCountIfNotFlagged), &textureCount);
                        if ((parent && ::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_011c7d34))), (::NiAVObject *)(parent))) || reinterpret_cast<::Fake_FUN_004a2020 *>((textureProperty1))->GetFlag(26) ||
                            reinterpret_cast<::Fake_FUN_004a2020 *>((textureProperty1))->GetFlag(27))
                            counts[14]++;
                    }
                    StatGeom* shader1 =
                        (StatGeom*)((!property
                                         ? 0
                                         : (((int)(reinterpret_cast<::BGSTerrainManager *>((property))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((property))->GetMinLevel())) <= 12 ? 1 : 0))
                                        ? property
                                        : 0);
                    if (shader1)
                    {
                        int textureSlots = ((unsigned short)(::FUN_00b70790((::FUN_00b70790_owner *)(shader1))));
                        void* position1;
                        void* texture1 = ((void *)(reinterpret_cast<::BSShaderLightingProperty *>((shader1))->GetFirstActiveLight((*(void * *)(&position1)))));
                        while (texture1)
                        {
                            int uses = 0;
                            reinterpret_cast<::fnv_00853130::NiTMapBase *>((((StatTextureSet*)&g_011c5ad0)))->FUN_00853130((unsigned int)(texture1), (*(::fnv_00853130::CombatThreatRecord * *)(&uses)));
                            uses++;
                            reinterpret_cast<::FUN_00844700_Class *>((((StatTextureSet*)&g_011c5ad0)))->FUN_00844700((unsigned int)(texture1), uses);
                            if (uses == *((int *)&(::FUN_0043d4d0((int *)&(DAT_011c5a90)))))
                                counts[13]++;
                            texture1 = ((void *)(::FUN_00b70680((::NiTListItem< ::ShadowSceneLight *> *&)(shader1))));
                        }
                    }
                    ScriptExecutionContext* data = geometry->GetData();
                    if (data)
                    {
                        counts[7] += data->FUN_004a1ff0();
                        int bytes = 0;
                        int vertices = ((unsigned short)(reinterpret_cast<::FUN_004a8090_shell *>((data))->CallTargetV36()));
                        if (((void *)(reinterpret_cast<::FUN_0049ec60 *>((data))->GetNext())))
                            bytes += vertices * 12;
                        if (reinterpret_cast<::This_004a8050 *>((data))->GetNextProc())
                            bytes += vertices * 16;
                        if (((void *)(reinterpret_cast<::FUN_004a8030_shell *>((data))->FUN_004a8030())))
                            bytes += vertices * 12;
                        if (((void *)(reinterpret_cast<::FUN_004a8070_shell *>((data))->GetScriptText())))
                            bytes += vertices * 8;
                        counts[9] += bytes;
                    }
                    if (((::fnv_004a82d0::StatSkin *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry)))))
                    {
                        StatBlocks* blocks = ((::fnv_004a82d0::StatBlocks *)(::fnv_004a8a90::FUN_004a8a90((char *)(((::fnv_004a82d0::StatSkin *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry))))))));
                        for (unsigned int block = 0; blocks && block < reinterpret_cast<::FUN_00a727b0_Class *>((blocks))->FUN_00a727b0(); block++)
                        {
                            unsigned int blockBytes = 0;
                            reinterpret_cast<::FUN_00a72550_Class *>((blocks))->GetItemData(block, (int *)(unsigned int *)(&blockBytes));
                            counts[9] += blockBytes;
                        }
                    }
                }
            }
            else
            {
                StatObject* particle = (StatObject*)((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_011f4a28))), (::NiObject *)(object))));
                if (particle)
                {
                    StatObject* manager = ((::fnv_004a82d0::StatObject *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
                    if (manager && ((int)(::FUN_00b5b4a0((::FUN_00b5b4a0_self *)(manager), (int)(particle), {}))))
                        counts[12]++;
                }
            }
            StatObject* lines1 = (StatObject*)((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012024e0))), (::NiObject *)(object))));
            if (lines1)
            {
                counts[5]++;
                counts[4] += reinterpret_cast<::FUN_004a8ab0_shell *>((lines1))->GetActorBaseFatigue();
            }
        }
    }
    reinterpret_cast<::FUN_0045a1c0_cls *>(((*reinterpret_cast<::fnv_004a82d0::StatDetector * *>(&::g_TES))))->ClearQueuedFile();
}
}  // namespace fnv_004a82d0

namespace fnv_004a8bb0 {
struct Cell245
{
};
struct FUN_004a7c40
{
    virtual ~FUN_004a7c40();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44;
    FUN_004a7c40();
    float GetScaledSlotValue(int);
};
struct FUN_004aa340
{
    int unk00, unk04, unk08, unk0c, unk10;
    FUN_004aa340();
    ~FUN_004aa340();
};
struct GlobalObject2_0096a2d0
{
    FUN_004a7c40* data;
    void* next;
    GlobalObject2_0096a2d0();
    ~GlobalObject2_0096a2d0();
    void FUN_005ae3d0(FUN_004a7c40*&);
    bool _ref_008256d0();
    void FUN_0063f7b0();
};
struct TES245
{
};
extern GlobalObject2_0045cfe0 DAT_011c63cc;
struct Cost245
{
    bool disabled;
    int unk04, unk08, unk0c, unk10;
};
extern Cost245 DAT_011886a0[16];
struct Clear245
{
};
extern Clear245 DAT_011c5c40;
void* __cdecl operator new(unsigned int);
// Accumulates cost and count over the interior cell or nearby exterior cells, adding the list total when include is set, then calls FUN_00438af0.
// @fnv 0x004a8bb0
void __cdecl FUN_004a8bb0(float* cost, float* count, bool include, bool addons)
{
    *cost = 0.0f;
    *count = 0.0f;
    FUN_004a8fe0();
    FUN_004aa340 list;
    GlobalObject2_0096a2d0 map;
    if (((::fnv_004a8bb0::Cell245 *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_004a8bb0::TES245 * *>(&::g_TES))))->GetPrevPath())))
    {
        Cell245* cell = ((::fnv_004a8bb0::Cell245 *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_004a8bb0::TES245 * *>(&::g_TES))))->GetPrevPath()));
        FUN_004a7c40* scene = new FUN_004a7c40;
        reinterpret_cast<::LowProcess *>((scene))->SetCurrentCombatTarget((::TESObjectREFR *)(cell));
        reinterpret_cast<::FUN_004a8230_shell *>((scene))->ResetAndProcessNode(reinterpret_cast<::FUN_00545cb0_shell *>((cell))->FUN_00545cb0(), addons, false);
        reinterpret_cast<::SceneCounter *>((scene))->AccumulateSceneStats((::SceneOwner *)(cell));
        reinterpret_cast<::FUN_004aa3d0_shell *>(&(list))->SetValueAndCall((int)(reinterpret_cast<::FUN_00545cb0_shell *>((cell))->FUN_00545cb0()), (int)(cell), 0);
        map.FUN_005ae3d0(scene);
    }
    else
    {
        unsigned int last = *(unsigned int*)((int *)&(::FUN_0043d4d0((int *)&(DAT_011c63cc)))) >> 1;
        unsigned int center = last - MinInt(last, 2);
        unsigned int first = last + MinInt(last, 2);
        for (unsigned int x = center; x <= first; x++)
        {
            for (unsigned int y = center; y <= first; y++)
            {
                Cell245** entry = ((::fnv_004a8bb0::Cell245 **)(reinterpret_cast<::TES *>(((*reinterpret_cast<::fnv_004a8bb0::TES245 * *>(&::g_TES))))->FUN_00457050(x, y)));
                if (*entry)
                {
                    Cell245* scene2 = *entry;
                    FUN_004a7c40* cell2 = new FUN_004a7c40;
                    reinterpret_cast<::LowProcess *>((cell2))->SetCurrentCombatTarget((::TESObjectREFR *)(scene2));
                    reinterpret_cast<::FUN_004a8230_shell *>((cell2))->ResetAndProcessNode(reinterpret_cast<::FUN_00545cb0_shell *>((scene2))->FUN_00545cb0(), addons, false);
                    reinterpret_cast<::FUN_004aa3d0_shell *>(&(list))->SetValueAndCall((int)(reinterpret_cast<::FUN_00545cb0_shell *>((scene2))->FUN_00545cb0()), (int)(scene2), 0);
                    reinterpret_cast<::SceneCounter *>((cell2))->AccumulateSceneStats((::SceneOwner *)(scene2));
                    map.FUN_005ae3d0(cell2);
                }
            }
        }
    }
    while (!map._ref_008256d0())
    {
        FUN_004a7c40* current = ((::fnv_004a8bb0::FUN_004a7c40 *)(new ((void *)&(map)) ::Vec3()));
        map.FUN_0063f7b0();
        *count += ((unsigned int)(reinterpret_cast<::FUN_004a7cf0_shell *>((current))->GetValueAt(9)));
        for (int i = 0; i < 16; i++)
        {
            if (!DAT_011886a0[i].disabled)
                *cost += current->GetScaledSlotValue(i);
        }
        delete current;
    }
    if (include)
        *count += ((unsigned int)(reinterpret_cast<::NiTMapContainer *>(&(list))->FUN_004aa890()));
    reinterpret_cast<::FUN_00438af0_Class *>(&(DAT_011c5c40))->FUN_00438af0();
}
}  // namespace fnv_004a8bb0

// Return the skill-scaled value for a slot: the slot's integer value times its game-setting multiplier.

class A8F70Setting
{
  public:
};

struct A8F70SlotInfo
{
    A8F70Setting* m_pkMultiplier;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

extern A8F70SlotInfo g_akA8F70Slots[];

class A8F70Owner
{
  public:
    float GetScaledSlotValue(int iSlot);
};

// Returns the slot value multiplied by the slot's multiplier float, or 0.0f if the slot index is out of range or has no multiplier.
// @fnv 0x004a8f70
float A8F70Owner::GetScaledSlotValue(int iSlot)
{
    if (iSlot >= 0 && iSlot < 16 && g_akA8F70Slots[iSlot].m_pkMultiplier)
        return (float)((double)((unsigned int)(reinterpret_cast<::FUN_004a7cf0_shell *>(this)->GetValueAt(iSlot))) * *((float *)&(::FUN_00403e20((float *)(g_akA8F70Slots[iSlot].m_pkMultiplier)))));
    return 0.0f;
}

int FUN_004a9100();
int FUN_004a9050();

// @fnv 0x004a9120
void __cdecl FUN_004a9120(float fUsed, char* buffer, bool abUseFirstTotal)
{
    float fTotal = abUseFirstTotal ? (float)(unsigned int)FUN_004a9100() : (float)(unsigned int)FUN_004a9050();
    float fPercent2 = fUsed * 100.0 / fTotal;
    fTotal = fTotal / 1048576.0;
    if (fUsed > 1048576.0)
    {
        fUsed = fUsed / 1048576.0;
        ::FUN_00406f60((::FUN_00406f90_this *)(buffer), "%.2f%% (%.2f MB / %.2f MB)", fPercent2, fUsed, fTotal);
    }
    else if (fUsed > 1024.0)
    {
        fUsed = fUsed / 1024.0;
        ::FUN_00406f60((::FUN_00406f90_this *)(buffer), "%.2f%% (%.2f KB / %.2f MB)", fPercent2, fUsed, fTotal);
    }
    else
    {
        ::FUN_00406f60((::FUN_00406f90_this *)(buffer), "%.2f%% (%.0f bytes / %.2f MB)", fPercent2, fUsed, fTotal);
    }
}

template <class A, class B> struct NiTPointerMap
{
    virtual ~NiTPointerMap();
    void RemoveAll();
};
struct FUN_004a99d0 : NiTPointerMap<unsigned int, unsigned int>
{
    ~FUN_004a99d0();
};
struct FUN_004a9970 : FUN_004a99d0
{
    ~FUN_004a9970();
};
// Calls FUN_004a9970, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x004a9660
void* FUN_004a9970_shell::FUN_004a9660(unsigned int flags)
{
    reinterpret_cast<::FUN_004a9970 *>(this)->FUN_004a9970::~FUN_004a9970();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that calls RemoveAll to clear all entries in the pointer map.
// @fnv 0x004a9970
FUN_004a9970::~FUN_004a9970()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}
