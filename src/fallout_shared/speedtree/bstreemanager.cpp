// fallout_shared/speedtree/bstreemanager.cpp: BSTreeManager, LFFreeList, TreeManager (27 functions)

#include <cstdint>
#include <cmath>
#include <new>
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00450570_Class.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_0045cec0_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005692d0_cls.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/LookupHandler.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_0064dac0.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TreeCloneView.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004bc450__FUN_004bc450_S.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_0066ac40__TreeModelLoader.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00b06c10__SpdTreeQ.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00451000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004f3000.h"
#include "fnv/symbols_0051d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057e000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_00665000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_00b07000.h"
#include "fnv/symbols_00b08000.h"
#include "fnv/symbols_00b0d000.h"
#include "fnv/symbols_00bb2000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fd000.h"
#include "bstreemanager_decls.h"
#include "fnv/decl/B6B330Renderer.h"
#include "fnv/symbols_0054e000.h"
#include "fnv/symbols_00b6b000.h"

// @fnv 0x00664870
void BSTreeManager::Create(bool create)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TREESYSTEM, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp",
                           0xb1);
    if ((*reinterpret_cast<::BSTreeManager * *>(&::fnv_0043da00::DAT_011d5c48)))
    {
        if (create)
            FUN_00664940();
        else
            return;
    }

    (*reinterpret_cast<::BSTreeManager * *>(&::fnv_0043da00::DAT_011d5c48)) = new BSTreeManager();
}

// @fnv 0x00665860
void BSTreeManager::UpdateTreeInstances()
{
    if (((NiPointer<NiAVObject>*)((char*)FUN_00664840(true) + 4))->operator NiAVObject*())
    {
        ((NiPointer<NiNode>*)((char*)FUN_00664840(true) + 4))->operator=(0);
        ::SetGlobalValue(nullptr);
        reinterpret_cast<::LookupHandler *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00456800((void *)("Data\\Textures\\Trees\\CanopyShadow.dds"), 0);
    }
}

// Returns DAT_011d5c48, creating the BSTreeManager first when create is true and it is not yet set.
// @fnv 0x00664840
void* FUN_00664840(bool create)
{
    if (!(*reinterpret_cast<::BSTreeManager * *>(&::fnv_0043da00::DAT_011d5c48)) && create)
        BSTreeManager::Create(false);

    return (*reinterpret_cast<::BSTreeManager * *>(&::fnv_0043da00::DAT_011d5c48));
}

// Stores the unsigned int argument converted to float into the global DAT_011fd890.
// @fnv 0x00664720
void SetGlobalFloatFromUInt(unsigned int value)
{
    DAT_011fd890 = (float)value;
}

// Clamps value to the range [0.0, 1.0] and stores the result in DAT_011adce0.
// @fnv 0x00665520
void ClampAndStoreValue(float value)
{
    float fClampedResult;
    float fClampedValue;

    if (value >= 0.0)
    {
        if (value <= 1.0)
            fClampedValue = value;
        else
            fClampedValue = 1.0f;

        fClampedResult = fClampedValue;
    }
    else
    {
        fClampedResult = 0.0f;
    }

    DAT_011adce0 = fClampedResult;
}

struct NP
{
    NP& operator=(void*);
};


// @fnv 0x00664820
void SetGlobalValue(void* value)
{
    (*reinterpret_cast<::NP *>(&::DAT_011f95e4)) = value;
}

struct FUN_006652c0_shell
{
    void SetByteAtOffset44(unsigned char value);
};

// @fnv 0x006652c0
void FUN_006652c0_shell::SetByteAtOffset44(unsigned char value)
{
    *reinterpret_cast<unsigned char*>(this + 0x44) = value;
}

struct Setting_S
{
    float f;
};

struct originalRuntimeFloatSetting1295_t
{
};


// @fnv 0x006655a0
float FUN_006655a0()
{
    return ((::Setting_S *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::originalRuntimeFloatSetting1295_t *>(&::originalRuntimeFloatSetting1295))))))->f;
}

namespace fnv_006655f0 {
struct Setting_S
{
};

Setting_S originalRuntimeFloatSetting1296;

// @fnv 0x006655f0
float GetOriginalRuntimeFloatSetting1296()
{
    return *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_006655f0::Setting_S *>(&::originalRuntimeFloatSetting1296))))));
}
}  // namespace fnv_006655f0


// Returns 1 if GetFirstProcessListByte succeeds and the byte at offset 0x18 of the object from _FUN_00664840(true) is nonzero, otherwise 0.
// @fnv 0x0054ee20
unsigned char FUN_0054ee20(bool abCreateIfNotFound)
{
    int result;
    if (GetFirstProcessListByte() && ((unsigned char*)(((unsigned char *)(::FUN_00664840(true))) + 0x18))[0])
        result = 1;
    else
        result = 0;
    return result;
}

struct S664990
{
};
struct FUN_00664990_shell
{
    void FUN_00664740();
    void* DestroyIfFlagged(unsigned int);
};
// If DAT_011d5c48 is set, calls its DestroyIfFlagged with 1, then clears DAT_011d5c48.
// @fnv 0x00664940
void FUN_00664940()
{
    void* b;
    if ((*reinterpret_cast<::BSTreeManager * *>(&::fnv_0043da00::DAT_011d5c48)))
    {
        void* a;
        a = (*reinterpret_cast<::BSTreeManager * *>(&::fnv_0043da00::DAT_011d5c48));
        b = a;
        {
            void* c;
            if (b)
                c = reinterpret_cast<::FUN_00664990_shell *>((((S664990*)b)))->DestroyIfFlagged(1);
            else
                c = 0;
        }
        (*reinterpret_cast<::BSTreeManager * *>(&::fnv_0043da00::DAT_011d5c48)) = 0;
    }
}
extern Setting_S DAT_011f9158;
// Returns the result of FUN_006655a0 multiplied by the float value stored in DAT_011f9158.
// @fnv 0x00665570
float FUN_00665570()
{
    return (double)FUN_006655a0() * *((float *)&(::FUN_00403e20((float *)&(DAT_011f9158))));
}

extern Setting_S DAT_011f9158;
// Returns the value from GetOriginalRuntimeFloatSetting1296 multiplied by the float stored in DAT_011f9158.
// @fnv 0x006655c0
float FUN_006655c0()
{
    return ((double)(::fnv_006655f0::GetOriginalRuntimeFloatSetting1296())) * *((float *)&(::FUN_00403e20((float *)&(DAT_011f9158))));
}

struct I2_665b80
{
    virtual int Func(int);
};
struct I1_665b80
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned char Foo(int, I2_665b80**, int);
};
struct C665b80
{
    void FUN_00665b80(int, I2_665b80*);
};
// Calls Foo on the object at this+0x1c; if it returns false, calls Func(1) on b when b is non-null.
// @fnv 0x00665b80
void C665b80::FUN_00665b80(int aiValue, I2_665b80* pObject)
{
    I2_665b80* p1;
    I2_665b80* p2;
    if (!(*(I1_665b80**)((char*)this + 0x1c))->Foo(aiValue, &pObject, 0))
    {
        p1 = pObject;
        p2 = p1;
        p2 ? p2->Func(1) : 0;
    }
}

namespace fnv_006652e0 {
struct NiStream;
struct NiMemObject
{
    char _pad_0[1];
};
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};

struct B006815c0
{
    B006815c0();
    float x;
    float y;
    float z;
};
struct NiAVObject
{
    NiPoint3 GetWorldTranslation();
};
struct NiPosData
{
    static B006815c0 __cdecl ComputePositionAtTime(float, const NiPoint3&);
};
struct Twin_0084d030
{
};
struct GameTimerRecord;
extern float DAT_011d5dd4;
struct NiTexture;
struct BSShaderNoLightingProperty
{
};
struct CP_008c48d0
{
};
struct Sky
{
};
struct Flt
{
    operator unsigned int();
};
struct TESFile
{
};
struct FUN_00450570_shell
{
};
struct FUN_004534f0_shell
{
};
struct NiProperty
{
};
struct FUN_006658b0_shell
{
    void Update();
};
struct GlobalObject_0045cfe0
{
};
struct GlobalObject_0044f440;

// @fnv 0x006652e0
void FUN_006652e0(NiAVObject* apCamera, bool abMenuMode)
{
    B006815c0 vecTemp;
    float fcamDir[3];
    float fcamLoc[3];
    if (!abMenuMode)
    {
        DAT_011d5dd4 += reinterpret_cast<::Twin_0084d030 *>((((Twin_0084d030*)&(*reinterpret_cast<::fnv_006652e0::GameTimerRecord *>(&::g_timeGlobal)))))->GetStoredFloatValue();
        ::fnv_00b07060::FUN_00b07060(DAT_011d5dd4);
    }
    if (apCamera)
    {
        fcamLoc[0] = ((::NiPoint3 *)(::FUN_0045bb80((std::intptr_t)(apCamera))))->x;
        fcamLoc[1] = ((::NiPoint3 *)(::FUN_0045bb80((std::intptr_t)(apCamera))))->y;
        fcamLoc[2] = ((::NiPoint3 *)(::FUN_0045bb80((std::intptr_t)(apCamera))))->z;
        vecTemp = NiPosData::ComputePositionAtTime(-1.0f, apCamera->GetWorldTranslation());
        fcamDir[0] = vecTemp.x;
        fcamDir[1] = vecTemp.y;
        fcamDir[2] = vecTemp.z;
        ::fnv_00b06c10::SpdTreeQ::FUN_00b06c10(fcamLoc, fcamDir);
    }
    if (!abMenuMode)
    {
        if ((*reinterpret_cast<::TES * *>(&::g_TES)) && ((::fnv_006652e0::NiTexture *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((BSShaderNoLightingProperty*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->GetBaseTexture())))
        {
            if (((int)(std::intptr_t)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->GetPrevPath())))
                *(float*)(((unsigned char *)(::FUN_00664840(1))) + 0x14) = 0.0f;
            else
                *(float*)(((unsigned char *)(::FUN_00664840(1))) + 0x14) =
                    reinterpret_cast<::FUN_004536e0_Class *>((((Sky*)((::fnv_006652e0::NiTexture *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((BSShaderNoLightingProperty*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->GetBaseTexture())))))->GetFieldCC();
            if (*(void**)(((unsigned char *)(::FUN_00664840(1))) + 8) &&
                ((::fnv_006652e0::TESFile *)(reinterpret_cast<::FUN_00450570_Class *>((((FUN_00450570_shell*)((::fnv_006652e0::NiTexture *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((BSShaderNoLightingProperty*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->GetBaseTexture())))))->FUN_00450570())))
            {
                NiColor col;
                col = *(const NiColor*)((const char *)(reinterpret_cast<::BGSCameraPath *>((((::fnv_006652e0::TESFile *)(reinterpret_cast<::FUN_00450570_Class *>((((FUN_00450570_shell*)((::fnv_006652e0::NiTexture *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((BSShaderNoLightingProperty*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->GetBaseTexture())))))->FUN_00450570()))))->GetShotList()));
                reinterpret_cast<::FUN_004534f0_shell *>((((FUN_004534f0_shell*)*(void**)(((unsigned char *)(::FUN_00664840(1))) + 8))))->FUN_004534f0((std::uintptr_t)&col);
                reinterpret_cast<::FUN_004534f0_shell *>((((FUN_004534f0_shell*)*(void**)(((unsigned char *)(::FUN_00664840(1))) + 8))))->FUN_004534f0((std::uintptr_t)&col);
                reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>((((NiProperty*)*(void**)(((unsigned char *)(::FUN_00664840(1))) + 8))))->FUN_004bc450((const ::fnv_004bc450::C3 *)(const ::fnv_006652e0::NiColor *)(&col));
            }
        }
        ((FUN_006658b0_shell*)((unsigned char *)(::FUN_00664840(1))))->Update();
    }
    SetGlobalFloatFromUInt(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_006652e0::GlobalObject_0045cfe0 *>(&::g_011d5d98)))))));
    ClampAndStoreValue(*((float *)&(::FUN_00403e20((float *)(((Setting_S*)&(*reinterpret_cast<::fnv_006652e0::GlobalObject_0044f440 *>(&::g_011d5d4c))))))));
}
}  // namespace fnv_006652e0

struct TreeLockObj
{
};

class TreeModel664b50
{
  public:
    TreeModel664b50();
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
};

struct TreeModelPtr
{
    TreeModel664b50* m_pObject;
    TreeModelPtr(TreeModel664b50* p = 0);
    ~TreeModelPtr();
    TreeModelPtr& operator=(TreeModel664b50* p);
    TreeModelPtr& operator=(const TreeModelPtr& p);
    operator TreeModel664b50*() const;
};

struct TreeMgr664b50
{
    void GetOrCreateModel(TESObjectTREE* tree, int key, TreeModelPtr& out);
};

struct FUN_00665be0_interface
{
    virtual void f0();
    virtual void f1();
    virtual bool f2(int, void**);
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};

struct C665be0_shell
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    FUN_00665be0_interface* unk1c;

    void FUN_00665be0(int value);
};


// @fnv 0x00665be0
void C665be0_shell::FUN_00665be0(int value)
{
    void* result = 0;

    if (unk1c->f2(value, &result))
    {
        unk1c->f5(value);

        if (result != 0)
        {
            ::FUN_00c45830((::MyRef *)(result));
        }
    }
}


struct LFNode
{
};

struct LFThreadData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LFNode** m_pAdditionalHudTile;
    unsigned int GetMaxThreads() const;
};

struct LFFreeList
{
    LFThreadData* pThreadData;
    int unk04;
    int unk08;
    unsigned int iCount;
    LFNode* pHead;
    void PruneFreeList();
};

// @fnv 0x006c7610
void LFFreeList::PruneFreeList()
{
    AutoMemContext context_2(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true, kThreadSafeStructuresSourceFile, 0xd0);
    unsigned int uiSlotsVal = pThreadData->GetMaxThreads() * 2;
    LFNode** ppActive = new LFNode*[uiSlotsVal];
    ::__memcpy(ppActive, pThreadData->m_pAdditionalHudTile, uiSlotsVal * 4);
    LFNode* pKept = 0;
    unsigned int uiKept = 0;
    while (pHead)
    {
        LFNode* pNode4 = pHead;
        pHead = ((::LFNode *)(reinterpret_cast<::Callees *>((pHead))->FUN_00726070()));
        bool bInUse4 = false;
        for (unsigned int i2 = 0; i2 < uiSlotsVal; i2++)
        {
            if (pNode4 == ppActive[i2])
            {
                bInUse4 = true;
                break;
            }
        }
        if (bInUse4)
        {
            reinterpret_cast<::CombatProcedure *>((pNode4))->Initialize((::CombatController *)(pKept));
            pKept = pNode4;
            uiKept++;
        }
        else
        {
            reinterpret_cast<::CombatProcedure *>((pNode4))->Initialize((::CombatController *)(::LFNode *)(0));
            delete pNode4;
        }
    }
    delete[] ppActive;
    pHead = pKept;
    iCount = uiKept;
}


class Child664
{
  public:
    virtual ~Child664();
};

class String664
{
  public:
    ~String664();

    char* m_pString;
};

class FUN_00664740
{
  public:
    ~FUN_00664740();

    int unk00;
    String664 m_kFirst;
    String664 m_kSecond;
    String664 m_kThird;
    String664 m_kFourth;
    int unk14;
    int unk18;
    Child664* m_pkChild;
};
// Calls FUN_00664740, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00664990
void* FUN_00664990_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00664740 *>(this)->FUN_00664740::~FUN_00664740();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

class NiTexture
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class FUN_00665c50
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_hashSize;
    void** m_hashTable;
    unsigned int m_uiItemCount;
    FUN_00665c50(int hashSize);
    ~FUN_00665c50();
};

struct Mgr6649c0
{
    FUN_00665c50* m_map;
    NiPointer<NiTexture>* GetOrCreateTexturePointer(std::uintptr_t key);
};
// @fnv 0x00664b50
void TreeMgr664b50::GetOrCreateModel(TESObjectTREE* tree, int key, TreeModelPtr& out)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::TreeLockObj *>(&::g_011d5cc0))))->FUN_004538a0(0);
    TreeModelPtr spModel3(0);
    if (tree)
    {
        TreeModelPtr* entries3 = ((::TreeModelPtr *)(reinterpret_cast<::Mgr6649c0 *>(this)->GetOrCreateTexturePointer((std::uintptr_t)(tree))));
        int freeIdx3 = -1;
        bool found3 = false;
        for (int i3 = 0; i3 < 1; i3++)
        {
            TreeModel664b50* model = entries3[i3];
            if (model)
            {
                if (((int)(std::intptr_t)(reinterpret_cast<::LowProcess *>((void *)(model))->GetTarget())) == key)
                {
                    spModel3 = model;
                    found3 = true;
                    break;
                }
            }
            else if (freeIdx3 == -1)
            {
                freeIdx3 = i3;
            }
        }
        if (!found3 || !spModel3)
        {
            if (freeIdx3 < 0)
            {
                spModel3 = *entries3;
            }
            else
            {
                spModel3 = new TreeModel664b50;
                entries3[freeIdx3] = spModel3;
            }
        }
    }
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::TreeLockObj *>(&::g_011d5cc0))))->WaitForTasksDuringRendering();
    out = spModel3;
}

// Looks up key in m_map, creating the map if null and inserting a new NiPointer<NiTexture> array when absent, then returns the pointer.
// @fnv 0x006649c0
NiPointer<NiTexture>* Mgr6649c0::GetOrCreateTexturePointer(std::uintptr_t key)
{
    AutoMemContext ctx(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp", 216);
    NiPointer<NiTexture>* value2 = 0;
    if (key == 0)
        return 0;
    if (m_map == 0)
        m_map = new FUN_00665c50(37);
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((NiTPointerMap<unsigned int, unsigned int>*)m_map)))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(*(unsigned int*)&value2)))
        return value2;
    value2 = new NiPointer<NiTexture>[1];
    reinterpret_cast<::FUN_00844700_Class *>((((NiTPointerMap<unsigned int, unsigned int>*)m_map)))->FUN_00844700(key, *(unsigned int*)&value2);
    return value2;
}

class NiFixedString
{
  public:
    const char* value;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiAVObject
{
  public:
};
class TESModel
{
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual const char* GetModelPath();
    unsigned int GetModelLength();
};
class TESObjectTREE : public TESForm
{
  public:
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    TESModel model;
};
class TreeReference : public TESObjectREFR
{
  public:
};
class BSTreeModel
{
  public:
    virtual ~BSTreeModel();
    virtual void f1();
    virtual void f2();
    virtual NiAVObject* CreateInstance(float);
};
template <> class NiPointer<BSTreeModel>
{
  public:
    BSTreeModel* m_pObject;
    NiPointer(BSTreeModel* = 0);
    ~NiPointer();
    operator BSTreeModel*() const;
};
class FUN_00666650 : public BSTreeModel
{
  public:
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c;
    FUN_00666650();
};
class LockFreeMap_TESObjectREFR___BSTreeNode___
{
  public:
    virtual void f0();
    virtual void f1();
    virtual bool Find(TreeReference*, NiAVObject**);
    virtual void f3();
    virtual void f4();
    virtual void Remove(TreeReference*);
};
struct TreeModelManager
{
};
struct TreeManager : BSTreeManager
{
    NiAVObject* CreateTreeInstance(TreeReference*, TESObjectTREE*);
};
// Validates the tree and reference, looks up or builds a BSTreeModel, creates a scaled NiAVObject instance, names it from the model path, and returns it.
// @fnv 0x00664f50
NiAVObject* TreeManager::CreateTreeInstance(TreeReference* reference, TESObjectTREE* tree)
{
    AutoMemContext cached(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                          "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp", 462);
    NiPointer<BSTreeModel> scale(0);
    BSTreeModel* model = 0;
    if (!GetFirstProcessListByte() || !tree || !tree->model.GetModelPath() || !tree->model.GetModelLength() ||
        (reference && ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) != (TESBoundObject*)tree))
        return 0;
    NiAVObject* m_uiMemoryContext = 0;
    if (m_pTreeInstanceMap->Find(reference, &m_uiMemoryContext))
    {
        m_pTreeInstanceMap->Remove(reference);
        return m_uiMemoryContext;
    }
    unsigned int node = 1;
    if (reference)
        node = ((unsigned int)(reinterpret_cast<::FUN_005692d0_cls *>((reference))->FUN_005692d0()));
    reinterpret_cast<::TreeMgr664b50 *>((((TreeModelManager*)FUN_00664840(true))))->GetOrCreateModel(tree, node, (::TreeModelPtr &)(scale));
    if (!(BSTreeModel*)scale)
        return 0;
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((BSTreeModel*)scale)))->FUN_00726070())) > 2)
    {
        model = new FUN_00666650;
        if (!reinterpret_cast<::TreeCloneView *>((model))->CloneFromModel((::TreeCloneView *)(::BSTreeModel *)(scale)))
        {
            delete model;
            return 0;
        }
    }
    else
    {
        if (!reinterpret_cast<::fnv_0066ac40::TreeModelLoader *>((((BSTreeModel*)scale)))->FUN_0066ac40((::fnv_0066ac40::TreeModelInput *)(tree), node))
            return 0;
        model = scale;
    }
    float key = 1.0f;
    if (reference)
        key = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((reference))->FUN_00567400();
    NiAVObject* instanceModel = model->CreateInstance(key);
    if (instanceModel)
        ::AssignFixedString((char *)(instanceModel), (std::intptr_t)&(const ::NiFixedString &)(NiFixedString(tree->model.GetModelPath())), {});
    reinterpret_cast<::FUN_006652c0_shell *>((model))->SetByteAtOffset44(1);
    return instanceModel;
}

namespace fnv_00665610 {
class NiPixelFormat;
class NiPixelData
{
  public:
    NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format, unsigned int mipLevels,
                unsigned int faces);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
};
class NiFixedString
{
  public:
    const char* text;
    NiFixedString(const char* text);
    ~NiFixedString();
    operator const char*() const;
};
struct TexturePointer
{
    NiSourceTexture* object;
    TexturePointer& FUN_0066b0d0(NiSourceTexture* texture);
};
struct TreeTextureState
{
    unsigned int unk00;
    TexturePointer shadow;
};
struct TextureLoader
{
};
struct TextureFormatPrefs
{
    unsigned int pixelLayout;
    unsigned int alphaFormat;
    unsigned int mipmapped;
};

// Ensures the tree state's shadow texture is loaded from CanopyShadow.dds or generated as a 16x16 white NiPixelData, then returns it.
// @fnv 0x00665610
NiSourceTexture* FUN_00665610()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp", 629);
    if (!((::NiSourceTexture *)(::FUN_00559450((int *)&(((TreeTextureState*)FUN_00664840(true))->shadow)))))
    {
        if ((*reinterpret_cast<::TES * *>(&::g_TES)))
            reinterpret_cast<::TESTexLoader *>((((TextureLoader*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_004568c0("Data\\Textures\\Trees\\CanopyShadow.dds",
                               (::TexPtr< ::NiSourceTexture> &)(((TreeTextureState*)FUN_00664840(true))->shadow), true, false);
        else
            ((TreeTextureState*)FUN_00664840(true))->shadow.FUN_0066b0d0(0);
        SetGlobalValue(((::NiSourceTexture *)(::FUN_00559450((int *)&(((TreeTextureState*)FUN_00664840(true))->shadow)))));
    }
    if (!((::NiSourceTexture *)(::FUN_00559450((int *)&(((TreeTextureState*)FUN_00664840(true))->shadow)))))
    {
        NiPixelData* pixels = new NiPixelData(16, 16, (*reinterpret_cast<const ::fnv_00665610::NiPixelFormat *>((void *)&::DAT_011aa2e8)), 1, 1);
        unsigned char* pPixelBytes = ((unsigned char *)(reinterpret_cast<::S_0064dac0 *>((pixels))->FUN_0064dac0(0, 0)));
        for (unsigned int y = 0; y < 16; ++y)
        {
            for (unsigned int x = 0; x < 16; ++x)
            {
                pPixelBytes[(y * 16 + x) * 3] = 255;
                pPixelBytes[(y * 16 + x) * 3 + 1] = 255;
                pPixelBytes[(y * 16 + x) * 3 + 2] = 255;
            }
        }
        reinterpret_cast<::NiGlobalStringTable *>((pixels))->AddString();
        NiFixedString kName("CanopyShadowTexture");
        ((TreeTextureState*)FUN_00664840(true))
            ->shadow.FUN_0066b0d0(((::NiSourceTexture *)(::fnv_00a5ff10::FUN_00a5ff10((::fnv_00a5ff10::RefCounted *)(pixels), &kName, (const ::fnv_00a5ff10::OwnerTriple *)&((*reinterpret_cast<const ::fnv_00665610::TextureFormatPrefs *>(&::DAT_011a9598)))))));
        SetGlobalValue(((::NiSourceTexture *)(::FUN_00559450((int *)&(((TreeTextureState*)FUN_00664840(true))->shadow)))));
    }
    return ((::NiSourceTexture *)(::FUN_00559450((int *)&(((TreeTextureState*)FUN_00664840(true))->shadow))));
}
}  // namespace fnv_00665610

struct Obj664
{
};
struct Ref664
{
    int p;
    void FUN_0066b0d0(void*);
    void* FUN_00667120(unsigned int);
};
struct Map664
{
    virtual void* Destroy(unsigned int);
};
struct Timer664
{
};
struct Entry664
{
    static void FUN_00664cd0(bool);
};
// Resets mode, enabled state, target and state, refreshes, then deletes m_pkChild.
// @fnv 0x00664740
FUN_00664740::~FUN_00664740()
{
    ::Entry664::FUN_00664cd0(0);
    ::SetGlobalValue(nullptr);
    ::FUN_00451570(0);
    ::FUN_00451520(1);
    ::ClearGlobalObjects();
    delete m_pkChild;
}
// @fnv 0x00664cd0
void Entry664::FUN_00664cd0(bool partial)
{
    Ref664* p;
    void* h;
    unsigned int a;
    bool i;
    int s;
    void* f;
    Ref664* eb;
    unsigned int cf;
    Ref664 *b, *q, *c, *l;
    Map664 *k, *ba, *j, *e;
    if (!*(Map664**)((unsigned char *)(::FUN_00664840(true))))
        return;
    reinterpret_cast<::GlobalObject_0044fae0 *>((((Timer664*)&(*reinterpret_cast<char *>(&::g_011d5cc0)))))->FUN_004538a0(0);
    if (partial)
    {
        h = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->GetFirstPos();
        while (h)
        {
            reinterpret_cast<::C6b7f20_Map *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->FUN_006b7f20((::C6b7f20_Node **)&(h), (unsigned int *)&(a), (void **)&(p));
            if (p)
            {
                i = true;
                for (s = 0; s < 1; ++s)
                {
                    if (((::Obj664 *)(::FUN_00559450((int *)&(p[s])))))
                    {
                        if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((::Obj664 *)(::FUN_00559450((int *)&(p[s]))))))->FUN_00726070())) <= 1)
                            p[s].FUN_0066b0d0(0);
                        else
                            i = false;
                    }
                }
                if (i)
                {
                    b = p;
                    q = b;
                    q ? q->FUN_00667120(3) : 0;
                    p = 0;
                    reinterpret_cast<::NiTMap_S *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->RemoveKey(a);
                    h = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->GetFirstPos();
                }
            }
        }
        if (::IsFieldCZero((::Dummy_0069b080 *)((*(Map664**)((unsigned char *)(::FUN_00664840(true)))))))
        {
            reinterpret_cast<::FUN_00438af0_Class *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->FUN_00438af0();
            k = *(Map664**)((unsigned char *)(::FUN_00664840(true)));
            ba = k;
            ba ? ba->Destroy(1) : 0;
            *(Map664**)((unsigned char *)(::FUN_00664840(true))) = 0;
        }
    }
    else
    {
        f = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->GetFirstPos();
        while (f)
        {
            reinterpret_cast<::C6b7f20_Map *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->FUN_006b7f20((::C6b7f20_Node **)&(f), (unsigned int *)&(cf), (void **)&(eb));
            c = eb;
            l = c;
            l ? l->FUN_00667120(3) : 0;
        }
        reinterpret_cast<::FUN_00438af0_Class *>(((*(Map664**)((unsigned char *)(::FUN_00664840(true))))))->FUN_00438af0();
        j = *(Map664**)((unsigned char *)(::FUN_00664840(true)));
        e = j;
        e ? e->Destroy(1) : 0;
        *(Map664**)((unsigned char *)(::FUN_00664840(true))) = 0;
    }
    reinterpret_cast<::ActorTaskManager *>((((Timer664*)&(*reinterpret_cast<char *>(&::g_011d5cc0)))))->WaitForTasksDuringRendering();
}

extern "C" char DAT_011d5dec, DAT_011d5de8, DAT_011d5dd8, DAT_0119b8cc;
struct Time6658
{
};
struct Setting6658
{
};
struct Pair6658
{
    float x, y;
};
float FUN_0063c600(float);
void FUN_00bb1390(float, float, float, float);
struct C6658
{
    char pad[20];
    float value;
    void Update();
};
// @fnv 0x006658b0
void C6658::Update()
{
    if ((*(int*)&DAT_011d5dec & 1) == 0)
    {
        *(int*)&DAT_011d5dec |= 1;
        (*(float*)&DAT_011d5de8) = value;
    }
    int i = 0;
    float amplitudeB = value * 0.6100000143051147;
    float sum = 0.0f;
    for (i = 0; i < 4; i++)
    {
        ((float*)&DAT_011d5dd8)[i] += reinterpret_cast<::Twin_0084d030 *>((((Time6658*)&(*reinterpret_cast<char *>(&::g_timeGlobal)))))->GetStoredFloatValue();
        if (value != 0.0)
            ((float*)&DAT_011d5dd8)[i] = ((float*)&DAT_011d5dd8)[i] * (*(float*)&DAT_011d5de8) / value;
        float speed4 = value * 20.0;
        float s7 = FUN_0063c600(speed4 * ((Pair6658*)&DAT_0119b8cc)[i].x * ((float*)&DAT_011d5dd8)[i]);
        float c = FUN_0057e960(speed4 * ((Pair6658*)&DAT_0119b8cc)[i].y * ((float*)&DAT_011d5dd8)[i]);
        if (i == 2)
        {
            sum += std::abs(s7);
            sum += std::abs(c);
        }
        ::FUN_00bb2fc0(i, amplitudeB * s7, amplitudeB * c);
    }
    float a7 = (1.0 - *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5dc4)))))))) +
               *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5dc4))))))) * sum / 2.0;
    float b = (1.0 - *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5d3c)))))))) +
              *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5d3c))))))) * sum / 2.0;
    float outerc4 = (1.0 - *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5c68)))))))) +
                    *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5c68))))))) * sum / 2.0;
    float d9 = (1.0 - *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5c74)))))))) +
               *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::g_011d5c74))))))) * sum / 2.0;
    FUN_00bb1390(value * a7, value * b,
                 reinterpret_cast<::Twin_0084d030 *>((((Time6658*)&(*reinterpret_cast<char *>(&::g_timeGlobal)))))->GetStoredFloatValue() * *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting1299))))))) * outerc4,
                 reinterpret_cast<::Twin_0084d030 *>((((Time6658*)&(*reinterpret_cast<char *>(&::g_timeGlobal)))))->GetStoredFloatValue() * *((float *)&(::FUN_00403e20((float *)(((Setting6658*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting1300))))))) * d9);
    (*(float*)&DAT_011d5de8) = value;
}

struct xMemObj
{
};

class RGBColorValue
{
  public:
    float r, g, b;
    RGBColorValue(float fR, float fG, float fB);
};

class xMatProp : public xMemObj
{
  public:
    int m_ai[0x13];
    xMatProp();
};

class xAlphaProp : public xMemObj
{
  public:
    int m_ai[7];
    xAlphaProp();
};

class xFlagsObj : public xMemObj
{
  public:
    int m_ai[4];
    xFlagsObj(int i);
};

class xMapObj
{
  public:
    int m_ai[0x10];
    xMapObj(int a, int b, int c);
};

template <class T> class xPtr
{
  public:
    T* m_pObject;
    xPtr(T* p = 0);
    ~xPtr();
    xPtr& operator=(T* p);
    T* operator->() const;
};

struct xGBool
{
    bool* Bool();
};
struct xGInt
{
};


class FUN_00664440
{
  public:
    int m_i0;
    xPtr<xMemObj> m_sp4;
    xPtr<xMatProp> m_spMat;
    xPtr<xAlphaProp> m_spAlpha;
    xPtr<xFlagsObj> m_spFlags;
    float m_f14;
    bool m_b18;
    bool m_b19;
    bool m_b1a;
    bool m_b1b;
    xMapObj* m_pMapObject;
    FUN_00664440();
};

// Initializes material, alpha, and flag properties with default values, then creates a map object and calls global setup functions.
// @fnv 0x00664440
FUN_00664440::FUN_00664440()
{
    m_i0 = 0;
    m_f14 = 0.0f;
    m_b19 = true;
    m_b18 = true;
    m_b1a = false;
    m_b1b = *(*reinterpret_cast<::xGBool *>(&::g_011d5d00)).Bool();
    m_spMat = new xMatProp();
    reinterpret_cast<::FUN_004534f0_shell *>(((m_spMat).operator->()))->FUN_004534f0((std::uintptr_t)&(const ::RGBColorValue &)(RGBColorValue(1.0f, 1.0f, 1.0f)));
    reinterpret_cast<::FUN_004534f0_shell *>(((m_spMat).operator->()))->FUN_004534f0((std::uintptr_t)&(const ::RGBColorValue &)(RGBColorValue(1.0f, 1.0f, 1.0f)));
    reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>(((m_spMat).operator->()))->FUN_004bc450((const ::fnv_004bc450::C3 *)&(const ::RGBColorValue &)(RGBColorValue(1.0f, 1.0f, 1.0f)));
    m_spAlpha = new xAlphaProp();
    reinterpret_cast<::Flag512Receiver *>(((m_spAlpha).operator->()))->SetFlag512(true);
    reinterpret_cast<::NiObjectNET *>(((m_spAlpha).operator->()))->SetFlags(4);
    reinterpret_cast<::FUN_0094db80_shell *>(((m_spAlpha).operator->()))->FUN_0094db80(0x54);
    reinterpret_cast<::FUN_0049ed90_shell *>(((m_spAlpha).operator->()))->FUN_0049ed90(false);
    m_spFlags = new xFlagsObj(3);
    ::fnv_00b07db0::FUN_00b07db0(4);
    ::FUN_00b084f0(1);
    ::FUN_00b0d7b0(1);
    ::SetGlobalFloatFromUInt(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::xGInt *>(&::g_011d5d98)))))));
    m_pMapObject = new xMapObj(2, 0x25, 0xc);
}

struct PointerDtor667
{
    void FUN_0045cec0();
};
struct PointerArrayCount667
{
    unsigned int count;
};
void FUN_00ec5fce(void*, unsigned int, int, void (PointerDtor667::*)());

// Destroys the object or its array elements, optionally frees the allocation, and returns this or the preceding count header.
// @fnv 0x00667120
void* Ref664::FUN_00667120(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 4, (reinterpret_cast<PointerArrayCount667*>(this) - 1)->count,
                     &PointerDtor667::FUN_0045cec0);
        if (flags & 1)
            ::operator delete(reinterpret_cast<PointerArrayCount667*>(this) - 1);
        return reinterpret_cast<PointerArrayCount667*>(this) - 1;
    }
    reinterpret_cast<::FUN_0045cec0_Class *>((reinterpret_cast<PointerDtor667*>(this)))->FUN_0045cec0();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

void ClampAndStoreValue(float value);

float FUN_006655a0();

struct NiRenderTargetGroup;

struct NiRenderer
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
    virtual NiRenderTargetGroup* GetCurrentRenderTargetGroup();
    static NiRenderer* ms_pRenderer;
};

struct GraphicsRenderer : public NiRenderer
{
    bool BeginUsingRenderTargetGroup(NiRenderTargetGroup* pkTarget, unsigned int uiClone);
};

// @fnv 0x00b6b7d0
void FUN_00b6b7d0(NiRenderTargetGroup* pkTarget, unsigned int uiClone)
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkTarget == 0)
    {
        pkTarget = pkRenderer->GetCurrentRenderTargetGroup();
    }
    if (*(bool*)((char*)pkRenderer + 0x208))
    {
        reinterpret_cast<::B6B330Renderer *>((pkRenderer))->TryUnlock();
    }
    NiRenderTargetGroup* pkTarget2 = pkTarget;
    if (pkTarget2 == 0)
    {
        pkTarget2 = NiRenderer::ms_pRenderer->GetCurrentRenderTargetGroup();
    }
    ((GraphicsRenderer*)NiRenderer::ms_pRenderer)->BeginUsingRenderTargetGroup(pkTarget2, uiClone);
    ::PushRefCountedSlot((int *)(pkTarget));
}

#include "generated/data/fallout_shared/speedtree/bstreemanager.inc"
#include "generated/data/fallout_shared/speedtree/bstreemanager_o2_variant.inc"
