// bsshader/bsshader.cpp: Zero4, ShaderDerived (27 functions)

#include <cstdio>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/E7DE90Owner.h"
#include "fnv/decl/E7DEF0TextureStage.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/LightSlots.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S00b7fd90_cls.h"
#include "fnv/decl/S00e75340_Renderer.h"
#include "fnv/decl/StageSet.h"
#include "fnv/decl/fnv_00e7eb50__BlockAllocatedStringArray.h"
#include "fnv/decl/fnv_00e814b0__UnkShader.h"
#include "fnv/decl/fnv_00e88fc0__E88FC0StageSet.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00af5000.h"
#include "fnv/symbols_00afe000.h"
#include "fnv/symbols_00b97000.h"
#include "fnv/symbols_00b98000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00e7e000.h"
#include "fnv/symbols_00e7f000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_01094000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_0126f000.h"
#include "bsshader_decls.h"

// Initializes the object by zeroing the first element of an array and setting a flag to false.
// @fnv 0x00be2200
BSShader::BSShader()
{
    spRenderPass[0] = 0;
    m_bIsBest = false;
}

#include "bsshader_compile_decls.h"


// @fnv 0x00be0c00
void FUN_00be0c00(const char* path, char* result)
{
    char drive[0x10];
    char dir[0x104];
    char name[0x80];
    char ext[8];
    char szBaseDir[0x104];
    if (result)
    {
        fnv::crt::splitpath_s(path, drive, 0x10, dir, 0x104, name, 0x80, ext, 8);
        fnv::crt::splitpath_s(DAT_011f9308, drive, 0x10, szBaseDir, 0x104, 0, 0, 0, 0);
        fnv::crt::strcat_s(szBaseDir, 0x104, dir);
        fnv::crt::makepath_s(result, 0x104, drive, szBaseDir, name, ext);
    }
}


// Builds a cache path from the default or configured directory, an optional "HDR." prefix, and the cache name, writing it into apCachePath.
// @fnv 0x00be0dc0
void __cdecl BuildCachePath(char* apCachePath, const char* apFileName, const char* apCacheName)
{
    if (apCachePath && apFileName && apCacheName)
    {
        char* ppath = (*reinterpret_cast<char (*)[260]>(&::DAT_011f9200));
        if (!(*reinterpret_cast<char (*)[260]>(&::DAT_011f9200))[0])
            ppath = DAT_011f9308;
        fnv::crt::strcpy_s(apCachePath, 260, ppath);
        if (DAT_011f941e)
            fnv::crt::strcat_s(apCachePath, 260, "HDR.");
        fnv::crt::strcat_s(apCachePath, 260, apCacheName);
    }
}

// @fnv 0x00be0e30
int FUN_00be0e30(void* apUnused, void* apBlock)
{
    reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(apBlock);
    return 0;
}

enum BSRENDERSTATE_LOCK
{
};
class BSRenderStateManager
{
  public:
    static void __cdecl SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
};

void __cdecl FUN_00b97e30(unsigned int, unsigned int);
void __cdecl FUN_00b97e80(unsigned int, unsigned int);

// @fnv 0x00be0e50
void FUN_00be0e50(int)
{
    if (DAT_011f91e4 < 0x252 || DAT_011f91e4 > 0x256)
    {
        BSRenderStateManager::SetDepthBufferEnabled(true, (BSRENDERSTATE_LOCK)0);
        FUN_00b97e30(0, 0);
        FUN_00b97e80(2, 0);
    }
}

namespace fnv_00be0e90 {
enum BSRENDERSTATE_LOCK
{
};
class BSRenderStateManager
{
  public:
};
void __cdecl FUN_00b97e30(unsigned int, unsigned int);
void __cdecl FUN_00b97e80(unsigned int, unsigned int);

// @fnv 0x00be0e90
void __cdecl FUN_00be0e90()
{
    ::BSRenderStateManager::SetDepthBufferEnabled(false, (*(::BSRENDERSTATE_LOCK *)&(const ::fnv_00be0e90::BSRENDERSTATE_LOCK &)((BSRENDERSTATE_LOCK)0)));
    FUN_00b97e30(1, 0);
    FUN_00b97e80(3, 0);
}
}  // namespace fnv_00be0e90

struct Node_00be0eb0
{
    int a;
    int b;
    Node_00be0eb0* next;
};

void __cdecl FUN_00b97d90(int, int, int);

// Walks the linked list at DAT_0126f74c+0x30+0x10 and calls FUN_00b97d90 on each node's a and b fields with 0.
// @fnv 0x00be0eb0
void FUN_00be0eb0(int)
{
    int ecx_val = *(int*)(DAT_0126f74c + 0x30);
    Node_00be0eb0* pNode = *(Node_00be0eb0**)(ecx_val + 0x10);
    while (pNode)
    {
        FUN_00b97d90(pNode->a, pNode->b, 0);
        pNode = pNode->next;
    }
}

struct Node_00be0ee0
{
    int m_val;
    int m_auiShapeKeys;
    Node_00be0ee0* m_next;
};

void __cdecl FUN_00b98610(int, int);

// Walks the linked list at DAT_0126f74c+0x30's +0x10 and calls FUN_00b98610 with each node's m_val and 0.
// @fnv 0x00be0ee0
void FUN_00be0ee0(int)
{
    int p1 = *(int*)(DAT_0126f74c + 0x30);
    Node_00be0ee0* node = *(Node_00be0ee0**)(p1 + 0x10);
    while (node)
    {
        FUN_00b98610(node->m_val, 0);
        node = node->m_next;
    }
}

void __cdecl ResolveRelativePath(const char*, const char*, char*);

class BSFile
{
  public:
    virtual ~BSFile();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual unsigned int GetFileSize();

    unsigned int m_uiStreamFlags;                                                                 // +0x04
    unsigned int(__cdecl* m_pfnRead)(BSFile*, void*, unsigned int, unsigned int*, unsigned int);  // +0x08
    unsigned char pad0C[0x20];                                                                    // +0x0C
    bool m_bGood;                                                                                 // +0x2C
};

// Builds a full path from pFileName, opens the file, allocates a buffer of its size, reads it into ppData, and returns the byte count in pBytes.
// @fnv 0x00be1eb0
long ReadFileIntoMemory(void* pThis, int aiUnused, const char* pFileName, int aiUnused2, const void** appData,
                                  unsigned int* apuiBytes)
{
    char fullPath[260];
    ResolveRelativePath(*((const char**)pThis + 1), pFileName, fullPath);

    BSFile* pFile = FileFinder::GetFile(fullPath, NiFile::READ_ONLY, 0x4000, 0x20);
    if (pFile)
    {
        if (pFile->m_bGood)
        {
            unsigned int size = pFile->GetFileSize();
            void* pData = reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
            *appData = pData;
            unsigned int compSize = 1;
            unsigned int bytesRead = pFile->m_pfnRead(pFile, pData, size, &compSize, 1);
            pFile->m_uiStreamFlags += bytesRead;
            *apuiBytes = bytesRead;
            delete pFile;
            return 0;
        }
        delete pFile;
    }
    return 0x80004005;
}

namespace fnv_00be1f90 {
struct ObjA
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
    virtual void v31_set(int);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35_set(int);
};

struct ObjB
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
    virtual int v31_get(int);
    virtual void v32();
    virtual int v33_get(int);
};

struct GlobalMgr
{
    char pad0[0x44];
    ObjB* p44;
    char pad1[0x14];
    ObjB* p5c;
};

extern GlobalMgr* DAT_0126f74c;

// Gets an ObjA from DAT_0126f74c and sets its v35 from p5c->v33_get(0), and if p44 is non-null sets its v31 from p44->v31_get(0).
// @fnv 0x00be1f90
void SetFromGlobalManager(void* this_ptr, int edx_unused, int aiUnused)
{
    ObjA* pObjA = ((::fnv_00be1f90::ObjA *)(::FUN_00e7f7c0()));
    pObjA->v35_set((*reinterpret_cast<::fnv_00be1f90::GlobalMgr * *>(&::DAT_0126f74c))->p5c->v33_get(0));
    ObjB* p44 = (*reinterpret_cast<::fnv_00be1f90::GlobalMgr * *>(&::DAT_0126f74c))->p44;
    if (p44)
    {
        pObjA->v31_set(p44->v31_get(0));
    }
}
}  // namespace fnv_00be1f90

int __cdecl FUN_00b97f20(unsigned int, unsigned int, int);

// Reads a byte array from param, extracts a 3-bit value from offset 0x18 and a byte at 0x1a, and passes them to FUN_00b97f20.
// @fnv 0x00be20b0
int FUN_00be20b0(unsigned char** apData)
{
    unsigned char* p = *apData;
    return FUN_00b97f20((*(unsigned short*)(p + 0x18) >> 10) & 7, p[0x1a], 0);
}


struct NiD3DPass_Ex : NiD3DPass
{
};

// Iterates the pass list at DAT_0126f74c and calls ShutdownPools_Ex(false) on each non-null pass that is flagged and has a nonzero field at offset 8.
// @fnv 0x00be2170
void __cdecl FUN_00be2170()
{
    int p = DAT_0126f74c;
    unsigned int count = *(unsigned int*)(p + 0x18);
    for (unsigned int i = 0; i < count; ++i)
    {
        NiD3DPass_Ex* pass = ((NiD3DPass_Ex**)*(int*)(p + 0x24))[i];
        if (!pass)
            break;
        if (*(bool*)&pass->m_uiRefCount && *(int*)((char*)pass + 8))
            reinterpret_cast<::NiD3DPass *>((pass))->ApplyRenderStateChanges(false);
    }
}

extern int DAT_011ae640[];

struct NiD3DPass_Ext : public NiD3DPass
{
};

// @fnv 0x00be21b0
void __cdecl FUN_00be21b0()
{
    int p = DAT_0126f74c;
    unsigned int count = *(unsigned int*)(p + 0x18);
    int mask = *(char*)(p + 0x4c);
    for (unsigned int i = 0; i < count; ++i)
    {
        if (DAT_011ae640[i] & mask)
        {
            NiD3DPass_Ext* pass = ((NiD3DPass_Ext**)*(int*)(p + 0x24))[i];
            if (!pass)
                break;
            if (*(int*)((char*)pass + 8) != 0)
                reinterpret_cast<::NiD3DPass *>((pass))->ApplyRenderStateChanges(false);
        }
    }
}

struct FUN_00be0ce0_obj
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
    virtual void vslot(int);
    char pad[0x5c - 4];
    int f5c;
};
// @fnv 0x00be0ce0
void FUN_00be0ce0(FUN_00be0ce0_obj* p, int unused)
{
    p->vslot(p->f5c);
}

struct BeamTextureState
{
};

struct BeamStage
{
    char _pad0[4];
    unsigned int m_arg2;
    char _pad8[8];
    BeamTextureState* m_pTextureState;
    char _pad14[0x4a];
    unsigned char m_byte5e;

};

// @fnv 0x00be0cf0
void __cdecl ConfigureBeamStage(BeamStage* stage, unsigned int uiValue, unsigned int arg3, unsigned int arg4,
                                bool bFlag)
{
    stage->m_arg2 = uiValue;
    reinterpret_cast<::fnv_00e88fc0::E88FC0StageSet *>((stage->m_pTextureState))->SetStageValue(11, (void *)(uiValue), false);
    reinterpret_cast<::fnv_00e88fc0::E88FC0StageSet *>((stage->m_pTextureState))->SetStageValue(1, (void *)(1), false);
    reinterpret_cast<::fnv_00e88fc0::E88FC0StageSet *>((stage->m_pTextureState))->SetStageValue(2, (void *)(2), false);
    reinterpret_cast<::fnv_00e88fc0::E88FC0StageSet *>((stage->m_pTextureState))->SetStageValue(4, (void *)(1), false);
    reinterpret_cast<::fnv_00e88fc0::E88FC0StageSet *>((stage->m_pTextureState))->SetStageValue(5, (void *)(2), false);
    stage->m_byte5e = 0;
    reinterpret_cast<::fnv_00e88fc0::E88FC0StageSet *>((stage->m_pTextureState))->SetStageValue(24, (void *)(0), false);
    if (arg3 == 3)
        reinterpret_cast<::E7DE90Owner *>((stage))->ApplyPairToState(0);
    else
        reinterpret_cast<::E7DE90Owner *>((stage))->ApplyPairToState(3);
    reinterpret_cast<::LightSlots *>((stage->m_pTextureState))->FUN_00e890c0(5, arg4, 0, false);
    reinterpret_cast<::LightSlots *>((stage->m_pTextureState))->FUN_00e890c0(6, arg4, 0, false);
    reinterpret_cast<::LightSlots *>((stage->m_pTextureState))->FUN_00e890c0(7, arg4, 0, false);
    reinterpret_cast<::E7DEF0TextureStage *>((stage))->FUN_00e7def0(bFlag ? 6 : 2);
}

struct M64Inner
{
    char pad[8];
    int f8;
    int fc;
};
struct M64Outer
{
    char pad[0x18];
    int count;
    char pad2[8];
    M64Inner** items;
};
// For each item in o->items, if the item's fc is not 1, sets its f8 to 0.
// @fnv 0x00be0fb0
void FUN_00be0fb0(M64Outer* pOuter)
{
    if (pOuter)
    {
        int iCount = pOuter->count;
        for (int i = 0; i < iCount; i++)
        {
            M64Inner* pEntry = pOuter->items[i];
            if (pEntry->fc != 1)
                pEntry->f8 = 0;
        }
    }
}

void __cdecl FUN_00b97ed0(bool, int);

struct Obj
{
    char pad[0x18];
    unsigned short flags;
};

struct StructA
{
    Obj* prop0;
    char pad[0xC];
    Obj* prop10;
};

// Derives two booleans from param_1's prop10/prop0 flags and DAT_011f91e4, then calls FUN_00b984d0 and FUN_00b97ed0 with them.
// @fnv 0x00be20e0
void FUN_00be20e0(StructA* pStruct, bool bCheckProp0)
{
    unsigned int v = DAT_011f91e4;
    bool bFlagA = false;
    if (pStruct && pStruct->prop10)
    {
        if ((pStruct->prop10->flags & 0xc00) == 0xc00)
        {
            bFlagA = true;
        }
    }
    if ((v - 0x56) <= 1)
    {
        bFlagA = true;
    }

    bool bFlagB = false;
    if (bCheckProp0)
    {
        if (pStruct && pStruct->prop0)
        {
            bFlagB = (pStruct->prop0->flags >> 9) & 1;
        }
    }

    ::FUN_00b984d0(bFlagA ? 3 : 1);
    FUN_00b97ed0(bFlagB, 0);
}

struct StageReturn
{
};
struct StagePool
{
    StageReturn** m_pStackBuffer;
    int m_pad4;
    int m_uiCount;
    int m_pad0c;
    int m_uiCapacity;
    StageReturn* Get()
    {
        if (m_uiCount == 0)
        {
            reinterpret_cast<::fnv_00e7eb50::BlockAllocatedStringArray *>(this)->AppendBlock(m_uiCapacity);
            m_uiCapacity *= 2;
        }
        StageReturn* s = m_pStackBuffer[0];
        --m_uiCount;
        m_pStackBuffer[0] = m_pStackBuffer[m_uiCount];
        return s;
    }
};

// Gets a StageReturn from DAT_0126f6cc, marks it, and refcount-swaps it into output, releasing the previous one.
// @fnv 0x00e7edf0
void AssignStageFromPool(StageReturn*& output)
{
    StageReturn* stage = DAT_0126f6cc->Get();
    if (stage)
        ++*(unsigned int*)((char*)stage + 0x60);
    *((char*)stage + 0x5f) = 1;
    StageReturn* old = output;
    if (old != stage)
    {
        if (old)
        {
            if (--*(unsigned int*)((char*)old + 0x60) == 0)
                reinterpret_cast<::FUN_00e7ecd0_cls *>((old))->FUN_00e7ecd0();
        }
        output = stage;
        ++*(unsigned int*)((char*)stage + 0x60);
    }
    if (--*(unsigned int*)((char*)stage + 0x60) == 0)
        reinterpret_cast<::FUN_00e7ecd0_cls *>((stage))->FUN_00e7ecd0();
}

struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct Direct3DDeviceInterface;
struct GeometryRelatedType;
struct NiD3DShaderProgramCreator;
struct NiGeometry;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiShaderConstantMapEntry;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct ShaderPassRenderer;
struct GraphicsRenderer;
struct _D3DXCONSTANTTABLE_DESC;
struct _D3DXCONSTANT_DESC;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;
struct IUnknown
{
    virtual int QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};
struct ID3DXBuffer : public IUnknown
{
    virtual void* GetBufferPointer();
    virtual unsigned long GetBufferSize();
    virtual int QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};
struct ID3DXConstantTable : public ID3DXBuffer
{
    virtual int GetDesc(_D3DXCONSTANTTABLE_DESC*);
    virtual int GetConstantDescription(unsigned int, _D3DXCONSTANT_DESC*, unsigned int*);
    virtual unsigned int GetSamplerRegisterIndex(unsigned int);
    virtual unsigned int GetPlaneConstant(unsigned int, unsigned int);
    virtual unsigned int FindConstantByName(unsigned int, char*);
    virtual unsigned int GetArrayElementConstant(unsigned int, unsigned int);
    virtual int ApplyDefaults(Direct3DDeviceInterface*);
    virtual int SetValue(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetBool(Direct3DDeviceInterface*, unsigned int, int);
    virtual int SetBoolArray(Direct3DDeviceInterface*, unsigned int, int*, unsigned int);
    virtual int SetInt(Direct3DDeviceInterface*, unsigned int, int);
    virtual int SetIntArray(Direct3DDeviceInterface*, unsigned int, int*, unsigned int);
    virtual int SetFloat(Direct3DDeviceInterface*, unsigned int, float);
    virtual int SetFloatArray(Direct3DDeviceInterface*, unsigned int, float*, unsigned int);
    virtual int SetReferenceVector(Direct3DDeviceInterface*, unsigned int, void*);
    virtual int SetConstantVectorArray(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetMatrix(Direct3DDeviceInterface*, unsigned int, void*);
    virtual int SetMatrixArray(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetMatrixArrayPointers(Direct3DDeviceInterface*, unsigned int, void**, unsigned int);
    virtual int SetMatrixTranspose(Direct3DDeviceInterface*, unsigned int, void*);
    virtual int SetMatrixTransposeArray(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetTransposeMatrixArrayPointers(Direct3DDeviceInterface*, unsigned int, void**, unsigned int);
    virtual int QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual void* GetBufferPointer();
    virtual unsigned long GetBufferSize();
};
struct ShaderBufferRecord
{
    char* QName();
    unsigned int QSize();
    char* QData();
    unsigned int GetTotalSize();
    char pName[256];
    unsigned int uiSize;
    char pData[1];
    char _pad_105[3];
};
struct NiGPUProgram : public NiRefObject
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiNode* IsSceneNode();
    virtual BSFadeNode* IsFadeNode();
    virtual BSMultiBoundNode* IsMultiBoundNode();
    virtual NiGeometry* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    virtual NiTriStrips* IsTriStrips();
    virtual NiTriShape* IsTriShape();
    virtual BSSegmentedTriShape* IsSegmentedTriShape();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual NiParticles* IsParticlesGeom();
    virtual NiLines* IsLineGeometry();
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();
    virtual bhkRigidBody* IsBhkRigidBody();
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();
    virtual unsigned int GetNumberOfVariables();
    virtual char* GetVariableName(unsigned int);
    bool IsExactKindOf(void*);
    static bool IsExactKindOf(void*, void*);
    bool IsKindOfType(void*);
    static bool IsKindOfType(void*, void*);
    NiGPUProgram* DynamicCast(void*);
    static NiGPUProgram* DynamicCast(void*, void*);
    int GetProgramType();
    int m_iProgramType;
};
struct NiD3DShaderProgram : public NiGPUProgram
{
    virtual void __vslot_0();
    virtual char* GetName();
    virtual void SetName(char*);
    virtual char* GetProgramProfile();
    virtual void SetShaderProfile(char*);
    virtual unsigned int GetCodeSize();
    virtual void* GetCode();
    virtual void SetProgramCode(unsigned int, void*);
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void SetCreator(NiD3DShaderProgramCreator*);
    virtual bool SetShaderConstant(NiShaderConstantMapEntry*, void*, unsigned int);
    virtual bool SetShaderConstantArray(NiShaderConstantMapEntry*, void*, unsigned int, unsigned int, unsigned short*);
    virtual void* GetRTTI();
    void SetD3DDevice(Direct3DDeviceInterface*);
    void SetD3DRenderState(ShaderPassRenderer*);
    void SetShaderObject(GraphicsRenderer*);
    void SetVertexShaderConstant(int, int, float*);
    void SetPixelShaderConstant(int, int, float*);
    char* m_pcProgramName;
    char* m_pcProfile;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};
struct NiD3DPixelShader : public NiD3DShaderProgram
{
    virtual void __vslot_0();
    virtual GeometryRelatedType* GetD3DPixelShader();
    virtual void SetD3DPixelShader(GeometryRelatedType*);
    virtual void UnloadShader();
    virtual void BuildVertexShader();
    virtual void* GetRTTI();
    virtual bool SetShaderConstant(NiShaderConstantMapEntry*, void*, unsigned int);
    virtual bool SetShaderConstantArray(NiShaderConstantMapEntry*, void*, unsigned int, unsigned int, unsigned short*);
    GeometryRelatedType* m_pD3DPixelShader;
};
struct FUN_00be1750_shell : public BSShader
{
    NiD3DPixelShader* FUN_00be1750(char*, void*, char*, char*);
};

struct NiD3DGPUProgramCache
{
    static const char* GetPixelShaderProfile(bool);
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct ShaderSourceFile_be1750
{
    virtual ~ShaderSourceFile_be1750();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual unsigned int GetSize();
    unsigned int Read(void* apBuffer, unsigned int auiBytes)
    {
        return reinterpret_cast<::FUN_00462d80_shell *>((((NiBinaryStream*)this)))->ReadBytes(apBuffer, auiBytes);
    }
    bool IsGood()
    {
        return *((bool*)this + 0x2c);
    }
};
struct ShaderCodeBuffer_be1750
{
    virtual long QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual void* GetBufferPointer();
    virtual unsigned long GetBufferSize();
};
struct ShaderIncludes_be1750
{
    const void* vtbl;
    const char* pPath;
};
struct ShaderDevice_be1750
{
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual void s038();
    virtual void s039();
    virtual void s040();
    virtual void s041();
    virtual void s042();
    virtual void s043();
    virtual void s044();
    virtual void s045();
    virtual void s046();
    virtual void s047();
    virtual void s048();
    virtual void s049();
    virtual void s050();
    virtual void s051();
    virtual void s052();
    virtual void s053();
    virtual void s054();
    virtual void s055();
    virtual void s056();
    virtual void s057();
    virtual void s058();
    virtual void s059();
    virtual void s060();
    virtual void s061();
    virtual void s062();
    virtual void s063();
    virtual void s064();
    virtual void s065();
    virtual void s066();
    virtual void s067();
    virtual void s068();
    virtual void s069();
    virtual void s070();
    virtual void s071();
    virtual void s072();
    virtual void s073();
    virtual void s074();
    virtual void s075();
    virtual void s076();
    virtual void s077();
    virtual void s078();
    virtual void s079();
    virtual void s080();
    virtual void s081();
    virtual void s082();
    virtual void s083();
    virtual void s084();
    virtual void s085();
    virtual void s086();
    virtual void s087();
    virtual void s088();
    virtual void s089();
    virtual void s090();
    virtual void s091();
    virtual void s092();
    virtual void s093();
    virtual void s094();
    virtual void s095();
    virtual void s096();
    virtual void s097();
    virtual void s098();
    virtual void s099();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual long CreatePixelShader(const unsigned int*, GeometryRelatedType**);
};
template <unsigned int _Size> inline int ShaderStrCat_be1750(char (&_Dest)[_Size], const char* _Source)
{
    return fnv::crt::strcat_s(_Dest, _Size, _Source);
}
struct FUN_00be08f0
{
    static void* operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    static void operator delete(void* p)
    {
        BSFadeNode::operator delete(p);
    }
    FUN_00be08f0(GraphicsRenderer*);
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
    virtual void SetD3DPixelShader(GeometryRelatedType*);
    unsigned int m_uiRefCount;
    int m_iProgramType;
    char* m_pcProgramName;
    char* m_pcProfile;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
    void* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    void* m_pRenderState;
    GeometryRelatedType* m_pD3DPixelShader;
};

// @fnv 0x00be1750
NiD3DPixelShader* FUN_00be1750_shell::FUN_00be1750(char* apFilename, void* apMacro, char* apTarget, char* apCacheName)
{
    bool bSourceExists;
    bool bfreeBuffer;
    ShaderCodeBuffer_be1750* pCompiledCode = 0;
    bool busecache;
    ShaderBufferRecord* pprePackagedShader = 0;
    ShaderCodeBuffer_be1750* pCompileError = 0;
    FUN_00be08f0* pshader = 0;
    ID3DXConstantTable* pConstantTable = 0;
    unsigned int uiShaderSize = 0;
    char pcachepath[260];
    GeometryRelatedType* pd3dShader;
    bool bCacheExists;
    unsigned int* pshaderbuffer;
    char perror[260];

    ::BuildCachePath(pcachepath, apFilename, apCacheName);
    busecache = true;
    bCacheExists = false;
    if (DAT_011f9498)
        pprePackagedShader = DAT_011f9498->Get(apCacheName);

    if (DAT_011ae638 && !pprePackagedShader)
    {
        _FILETIME ksrcFile = {};
        _FILETIME kcacheFile = {};
        bSourceExists = ::fnv_00afe7d0::FUN_00afe7d0(apFilename, (::fnv_00afe7d0::_FILETIME &)(ksrcFile), 0x20);
        bCacheExists = ::fnv_00afe7d0::FUN_00afe7d0(pcachepath, (::fnv_00afe7d0::_FILETIME &)(kcacheFile), 0x20);
        if (!bCacheExists && DAT_011f94a7)
        {
            const char* ppath = (*reinterpret_cast<char (*)[260]>(&::DAT_011f9200));
            if (0 == ppath || 0 == *ppath)
            {
                fnv::crt::strcpy_s((*reinterpret_cast<char (*)[260]>(&::DAT_011f9200)), 0x104, (const char*)DAT_010bc860);
                ::BuildCachePath(pcachepath, apFilename, apCacheName);
            }
            bCacheExists = ::fnv_00afe7d0::FUN_00afe7d0(pcachepath, (::fnv_00afe7d0::_FILETIME &)(kcacheFile), 0x20);
        }
        if (!bSourceExists)
        {
            ::FUN_00406d00(perror, 0x104, (const char*)DAT_010bc82c, apFilename);
        }
        if (!bCacheExists)
            busecache = false;
    }

    bfreeBuffer = false;
    pshaderbuffer = 0;
    if (pprePackagedShader)
    {
        pshaderbuffer = (unsigned int*)pprePackagedShader->pData;
    }
    else if (!busecache)
    {
        _D3DXMACRO* pMacroDefines = 0;
        if (DAT_011f941e)
        {
            _D3DXMACRO* phdrmacro = (_D3DXMACRO*)apMacro;
            for (int imacro = 1; phdrmacro->Name; imacro++)
                phdrmacro = &((_D3DXMACRO*)apMacro)[imacro];
            phdrmacro->Name = (const char*)DAT_010bc828;
            phdrmacro->Definition = (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::DAT_01011584));
            pMacroDefines = phdrmacro;
        }
        const char* pProfile = apTarget;
        if (std::strncmp(apTarget, "ps_2_0", 4) == 0)
        {
            pProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
            if (!pProfile)
                pProfile = apTarget;
        }
        ShaderSourceFile_be1750* pfile =
            (ShaderSourceFile_be1750*)FileFinder::GetFile(apFilename, NiFile::READ_ONLY, 0x4000, 0x20);
        if (!pfile || !pfile->IsGood())
        {
            if (pfile)
                delete pfile;
            ::FUN_00406d00(perror, 0x104, (const char*)DAT_010bc7b8, apFilename);
            return 0;
        }
        unsigned int uiFileSize = pfile->GetSize();
        char* pfileData = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(uiFileSize);
        pfile->Read(pfileData, uiFileSize);
        ShaderIncludes_be1750 includes;
        includes.vtbl = DAT_010bc610;
        includes.pPath = apFilename;
        {
            char pCompileMacros[1300];
            char pMacroDefines[1300];
            char perror[1300];
            pCompileMacros[0] = 0;
            pMacroDefines[0] = 0;
            for (int imacro = 0; imacro < 8; imacro++)
            {
                if (((_D3DXMACRO*)apMacro)[imacro].Name)
                {
                    ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[imacro].Name);
                    ShaderStrCat_be1750(pMacroDefines, (const char*)DAT_010bc824);
                    ShaderStrCat_be1750(pMacroDefines, ((_D3DXMACRO*)apMacro)[imacro].Name);
                    if (((_D3DXMACRO*)apMacro)[imacro].Definition && *((_D3DXMACRO*)apMacro)[imacro].Definition)
                    {
                        ShaderStrCat_be1750(pCompileMacros, (const char*)DAT_01063ec8);
                        ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[imacro].Definition);
                        ShaderStrCat_be1750(pMacroDefines, (const char*)DAT_01063ec8);
                        ShaderStrCat_be1750(pMacroDefines, ((_D3DXMACRO*)apMacro)[imacro].Definition);
                    }
                    else
                    {
                        ShaderStrCat_be1750(pMacroDefines, (const char*)DAT_010bc820);
                    }
                    ShaderStrCat_be1750(pCompileMacros, (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::DAT_01012630)));
                }
            }
            ::FUN_00406d00(perror, 0x514, (const char*)DAT_010bc808, apFilename, apTarget, pCompileMacros);
            unsigned long uiCompileFlags = 0;
            long hResult =
                ::FUN_00ee6e0a(pfileData, uiFileSize, (const ::D3DXMACRO *)(const ::_D3DXMACRO *)((_D3DXMACRO*)apMacro), (ID3DXInclude*)&includes,
                                  (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::str_01094d90)), pProfile, uiCompileFlags, (ID3DXBuffer**)&pCompiledCode,
                                  (ID3DXBuffer**)&pCompileError, &pConstantTable);
            delete pfile;
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pfileData);
            if (pCompileError && !pCompiledCode)
            {
                pCompileMacros[0] = 0;
                for (int i = 0; i < 8; i++)
                {
                    if (((_D3DXMACRO*)apMacro)[i].Name)
                    {
                        ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[i].Name);
                        if (((_D3DXMACRO*)apMacro)[i].Definition && *((_D3DXMACRO*)apMacro)[i].Definition)
                        {
                            ShaderStrCat_be1750(pCompileMacros, (const char*)DAT_01063ec8);
                            ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[i].Definition);
                        }
                        ShaderStrCat_be1750(pCompileMacros, (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::DAT_01012630)));
                    }
                }
                ::FUN_00406d00(perror, 0x514, (const char*)DAT_010bc7fc, apFilename, pCompileMacros,
                          pCompileError->GetBufferPointer());
                pCompileError->Release();
                pCompileError = 0;
            }
            if (hResult == 0 && pCompiledCode)
            {
                _iobuf* pOutFile = ((_iobuf *)(std::fopen(pcachepath, (const char*)DAT_0106e798)));
                uiShaderSize = pCompiledCode->GetBufferSize();
                std::fwrite(pCompiledCode->GetBufferPointer(), uiShaderSize, 1, (std::FILE *)(pOutFile));
                std::fflush((std::FILE *)(pOutFile));
                std::fclose((std::FILE *)(pOutFile));
                ::HasFileInArchives(pcachepath);
                pshaderbuffer = (unsigned int*)pCompiledCode->GetBufferPointer();
            }
            else
            {
                if (!bCacheExists)
                    return 0;
                pfile = (ShaderSourceFile_be1750*)FileFinder::GetFile(pcachepath, NiFile::READ_ONLY, 0x4000, 0x20);
                if (!pfile)
                    return 0;
                if (pfile->IsGood())
                {
                    uiShaderSize = pfile->GetSize();
                    pshaderbuffer = (unsigned int*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(uiShaderSize);
                    bfreeBuffer = true;
                    pfile->Read(pshaderbuffer, uiShaderSize);
                }
                delete pfile;
                if (!pshaderbuffer)
                    return 0;
            }
        }
        if (pMacroDefines)
        {
            pMacroDefines->Name = 0;
            pMacroDefines->Definition = 0;
        }
    }
    else
    {
        ShaderSourceFile_be1750* pfile =
            (ShaderSourceFile_be1750*)FileFinder::GetFile(pcachepath, NiFile::READ_ONLY, 0x4000, 0x20);
        if (pfile)
        {
            if (pfile->IsGood())
            {
                uiShaderSize = pfile->GetSize();
                pshaderbuffer = (unsigned int*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(uiShaderSize);
                bfreeBuffer = true;
                pfile->Read(pshaderbuffer, uiShaderSize);
            }
            delete pfile;
        }
        else
        {
            char perror[260];
            ::FUN_00406d00(perror, 0x104, (const char*)DAT_010bc754, pcachepath);
            return 0;
        }
    }

    if (pshaderbuffer)
    {
        if (DAT_011f9494)
        {
            reinterpret_cast<::S00b7fd90_cls *>((DAT_011f9494))->FUN_00b7fd90((unsigned int)(apCacheName), (unsigned int)((char*)pshaderbuffer), (::Thing_b9704 *)(uiShaderSize));
        }
        else
        {
            ShaderDevice_be1750* pdevice = *(ShaderDevice_be1750**)((char*)(*reinterpret_cast<::GraphicsRenderer * *>(&::DAT_011f9508)) + 0x288);
            if (pdevice->CreatePixelShader(pshaderbuffer, &pd3dShader))
            {
                char perror[260];
                ::FUN_00406d00(perror, 0x104, "SHADER ERROR : failed to create pixel shader : %s", pcachepath);
                return 0;
            }
            pshader = new FUN_00be08f0((*reinterpret_cast<::GraphicsRenderer * *>(&::DAT_011f9508)));
            pshader->SetD3DPixelShader(pd3dShader);
        }
    }
    if (bfreeBuffer)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pshaderbuffer);
    return (NiD3DPixelShader*)pshader;
}

class BBDF6C0Light;

struct BBDF6C0GeometryData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
};

class BBDF6C0Geometry
{
  public:
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
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
    BBDF6C0GeometryData* m_pUserData;
};

struct BBDF6C0RenderPass
{
    int unk00;
    short unk04;
    unsigned char m_ucLightingType;
};

class BBDF6C0PassArray
{
  public:
    void Add(BBDF6C0Geometry* pkGeometry, unsigned short usPassType, bool bEnabled, unsigned char ucLights,
             BBDF6C0Light* pkLight0, BBDF6C0Light* pkLight1, BBDF6C0Light* pkLight2, BBDF6C0Light* pkLight3);

    int unk00;
    BBDF6C0RenderPass** m_ppkPasses;
    int unk08;
    int unk0C;
    int m_iArrayLength;
};

class BBDF6C0Shader
{
  public:
    virtual ~BBDF6C0Shader();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiFlags1;
    unsigned int m_uiFlags2;
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
    BBDF6C0PassArray* m_pkPasses;

    bool GetFlag(unsigned int uiBit) const
    {
        if (uiBit < 32)
            return (m_uiFlags1 & (1 << uiBit)) > 0;
        return (m_uiFlags2 & (1 << (uiBit - 32))) > 0;
    }

    void AddPasses(BBDF6C0Geometry* pkGeometry, bool bSkipDefault);
};

// Adds a render pass chosen by shader flags (or the geometry's default pass) and sets the first pass's lighting type from the flags.
// @fnv 0x00bdf6c0
void BBDF6C0Shader::AddPasses(BBDF6C0Geometry* pkGeometry, bool bSkipDefault)
{
    if (GetFlag(14))
    {
        m_pkPasses->Add(pkGeometry, 0x22f, true, 0, 0, 0, 0, 0);
    }
    else if (GetFlag(33))
    {
        m_pkPasses->Add(pkGeometry, 0x61, true, 0, 0, 0, 0, 0);
    }
    else if (!bSkipDefault)
    {
        BBDF6C0GeometryData* pkData = pkGeometry->m_pUserData;
        if (pkData && (bool)((pkData->m_usFlags >> 9) & 1))
            m_pkPasses->Add(pkGeometry, 0x63, true, 0, 0, 0, 0, 0);
        else
            m_pkPasses->Add(pkGeometry, 0x62, true, 0, 0, 0, 0, 0);
    }

    if (m_pkPasses->m_iArrayLength)
    {
        BBDF6C0RenderPass* pkPass = m_pkPasses->m_ppkPasses[0];
        unsigned char ucLightingType = 0;
        if (GetFlag(33) || GetFlag(34))
            ucLightingType = 10;
        else if (GetFlag(26))
            ucLightingType = GetFlag(53) ? 1 : 4;
        pkPass->m_ucLightingType = ucLightingType;
    }
}

class StageReturnC06
{
  public:
    void DecRefCount()
    {
        --m_iRefCount;
        if (m_iRefCount == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>(this)->FUN_00e7ecd0();
    }

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_iRefCount;
    bool m_bEnableState;
};

class StageReturnPtrC06
{
  public:
    StageReturnPtrC06() : m_pPointer(0)
    {}
    ~StageReturnPtrC06()
    {
        if (m_pPointer)
            m_pPointer->DecRefCount();
    }
    StageReturnC06* operator->() const
    {
        return m_pPointer;
    }
    operator StageReturnC06*() const
    {
        return m_pPointer;
    }

    StageReturnC06* m_pPointer;
};


class PassC06
{
  public:

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_iStageParam;
    unsigned int m_uiStageData;
    int unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48;
    char m_cMask;
};

// @fnv 0x00c06e10
void __cdecl SetStageMask(PassC06* pkPass, char cMask)
{
    StageReturnPtrC06 spStage;
    unsigned int uiNumStages = pkPass->m_uiStageData;
    if (uiNumStages < 7)
    {
        for (unsigned int i = 0; i < 7; i++)
        {
            ::AssignStageFromPool((::StageReturn *&)(spStage));
            ::ConfigureBeamStage((::BeamStage *)(::StageReturnC06 *)(spStage), i, 1, 2, 1);
            reinterpret_cast<::StageSet *>((pkPass))->FUN_00e802b0(pkPass->m_iStageParam, (::Stage321 *)(::StageReturnC06 *)(spStage));
            spStage->m_bEnableState = (cMask & (1 << i)) != 0;
        }
    }
    pkPass->m_cMask = cMask;
}

// FUN_00e7ee80 : default constructor of the small bookkeeping object used by
// the shader pass code.  The object starts out with its flag byte cleared and
// all four counters zeroed; the constructor returns the freshly built object
// (hence the "mov eax, ecx" prologue of a MSVC constructor).
struct FUN_00e7ee80_cls
{
    bool m_bEnableState;
    int m_iCount04;
    int m_iCount08;
    int m_iCount0c;
    int m_iCount10;

    FUN_00e7ee80_cls();
};

// @fnv 0x00e7ee80
FUN_00e7ee80_cls::FUN_00e7ee80_cls() : m_bEnableState(false), m_iCount04(0), m_iCount08(0), m_iCount0c(0), m_iCount10(0)
{}

struct LodShaderBase
{
};

struct FUN_00b71b90_class : LodShaderBase
{
    void FUN_00be08b0();
};

// @fnv 0x00be08b0
void FUN_00b71b90_class::FUN_00be08b0()
{
    reinterpret_cast<::fnv_00e814b0::UnkShader *>(this)->FUN_00e814b0();
}

struct Alpha818
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    unsigned short flags;
};
struct Data818
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, valid;
    float unk20, unk24, alpha1, alpha2;
};
struct Input818
{
    Alpha818* alpha;
    int unk04, unk08;
    Data818* data;
};
void __cdecl AddToTwoCounters(int, int, int);
// Reads alpha and data from input, checks flags and alpha values, then calls FUN_00b97fa0 and AddToTwoCounters with blend or default counters.
// @fnv 0x00be1ff0
void FUN_00be1ff0(Input818* input)
{
    Alpha818* alpha = input->alpha;
    Data818* data = input->data;
    Data818* pSelected;
    if (!data)
        pSelected = 0;
    else
        pSelected = data->valid != -1 ? data : 0;
    data = pSelected;
    bool enabled = false;
    bool blend = false;
    volatile bool test = false;
    if (alpha)
    {
        unsigned char uiFlagBit = (unsigned char)(alpha->flags >> 9);
        if (uiFlagBit & 1)
            test = true;
        if (alpha->flags & 1)
        {
            enabled = true;
            blend = enabled;
        }
    }
    if (!(data->alpha1 < 1.0f) && !(data->alpha2 < 1.0f) && !enabled)
    {
        ::BSRenderStateManager::SetDepthBufferEnabled(0, (::BSRENDERSTATE_LOCK)(0));
        return;
    }
    ::BSRenderStateManager::SetDepthBufferEnabled(1, (::BSRENDERSTATE_LOCK)(0));
    if (blend)
    {
        unsigned int flags = alpha->flags;
        AddToTwoCounters((flags >> 1) & 15, (flags >> 5) & 15, 0);
    }
    else
        AddToTwoCounters(6, 7, 0);
}

struct Zero4
{
    int a;
    int b;
    int c;
    int d;
    Zero4* Zero();
};

// Sets all four int fields of the struct to zero and returns a pointer to the struct.
// @fnv 0x00e7ee70
Zero4* Zero4::Zero()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return this;
}

namespace fnv_00be0f10 {
struct ShaderPassTarget
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
};
struct PassHolder
{
    ShaderPassTarget* m_pObject;
    ~PassHolder();
};
struct ShaderBase
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
    virtual ~ShaderBase();
};
struct ShaderManager
{
};
struct ShaderDerived : ShaderBase
{
    PassHolder m_akPasses[1];
    virtual ~ShaderDerived();
};
// Releases the referenced ShaderPassTarget when its count reaches zero, then calls a method on the shader manager.
// @fnv 0x00be0f10
ShaderDerived::~ShaderDerived()
{
    ShaderPassTarget* p = m_akPasses[0].m_pObject;
    if (p)
    {
        if (--p->unk64 == 0)
            reinterpret_cast<::NiD3DPass *>((p))->DestroyPass();
        m_akPasses[0].m_pObject = 0;
    }
    reinterpret_cast<::S00e75340_Renderer *>(((*reinterpret_cast<::fnv_00be0f10::ShaderManager * *>(&::DAT_011f9508))))->FUN_00e75340((::S00e75340_Group *volatile)(this));
}
}  // namespace fnv_00be0f10

namespace fnv_00be0fe0 {
class VertexShaderFile
{
  public:
    virtual ~VertexShaderFile();
    virtual void FileMethod1();
    virtual void FileMethod2();
    virtual void FileMethod3();
    virtual void FileMethod4();
    virtual void FileMethod5();
    virtual void FileMethod6();
    virtual void FileMethod7();
    virtual void FileMethod8();
    virtual void FileMethod9();
    virtual unsigned int GetSize();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    bool valid;
};
struct CacheEntryView
{
    char name[260];
    char data[1];
};
class VertexDevice
{
  public:
    virtual void DeviceMethod0();
    virtual void DeviceMethod1();
    virtual void DeviceMethod2();
    virtual void DeviceMethod3();
    virtual void DeviceMethod4();
    virtual void DeviceMethod5();
    virtual void DeviceMethod6();
    virtual void DeviceMethod7();
    virtual void DeviceMethod8();
    virtual void DeviceMethod9();
    virtual void DeviceMethod10();
    virtual void DeviceMethod11();
    virtual void DeviceMethod12();
    virtual void DeviceMethod13();
    virtual void DeviceMethod14();
    virtual void DeviceMethod15();
    virtual void DeviceMethod16();
    virtual void DeviceMethod17();
    virtual void DeviceMethod18();
    virtual void DeviceMethod19();
    virtual void DeviceMethod20();
    virtual void DeviceMethod21();
    virtual void DeviceMethod22();
    virtual void DeviceMethod23();
    virtual void DeviceMethod24();
    virtual void DeviceMethod25();
    virtual void DeviceMethod26();
    virtual void DeviceMethod27();
    virtual void DeviceMethod28();
    virtual void DeviceMethod29();
    virtual void DeviceMethod30();
    virtual void DeviceMethod31();
    virtual void DeviceMethod32();
    virtual void DeviceMethod33();
    virtual void DeviceMethod34();
    virtual void DeviceMethod35();
    virtual void DeviceMethod36();
    virtual void DeviceMethod37();
    virtual void DeviceMethod38();
    virtual void DeviceMethod39();
    virtual void DeviceMethod40();
    virtual void DeviceMethod41();
    virtual void DeviceMethod42();
    virtual void DeviceMethod43();
    virtual void DeviceMethod44();
    virtual void DeviceMethod45();
    virtual void DeviceMethod46();
    virtual void DeviceMethod47();
    virtual void DeviceMethod48();
    virtual void DeviceMethod49();
    virtual void DeviceMethod50();
    virtual void DeviceMethod51();
    virtual void DeviceMethod52();
    virtual void DeviceMethod53();
    virtual void DeviceMethod54();
    virtual void DeviceMethod55();
    virtual void DeviceMethod56();
    virtual void DeviceMethod57();
    virtual void DeviceMethod58();
    virtual void DeviceMethod59();
    virtual void DeviceMethod60();
    virtual void DeviceMethod61();
    virtual void DeviceMethod62();
    virtual void DeviceMethod63();
    virtual void DeviceMethod64();
    virtual void DeviceMethod65();
    virtual void DeviceMethod66();
    virtual void DeviceMethod67();
    virtual void DeviceMethod68();
    virtual void DeviceMethod69();
    virtual void DeviceMethod70();
    virtual void DeviceMethod71();
    virtual void DeviceMethod72();
    virtual void DeviceMethod73();
    virtual void DeviceMethod74();
    virtual void DeviceMethod75();
    virtual void DeviceMethod76();
    virtual void DeviceMethod77();
    virtual void DeviceMethod78();
    virtual void DeviceMethod79();
    virtual void DeviceMethod80();
    virtual void DeviceMethod81();
    virtual void DeviceMethod82();
    virtual void DeviceMethod83();
    virtual void DeviceMethod84();
    virtual void DeviceMethod85();
    virtual void DeviceMethod86();
    virtual void DeviceMethod87();
    virtual void DeviceMethod88();
    virtual void DeviceMethod89();
    virtual void DeviceMethod90();
    virtual long CreateVertexShader(const char*, void**) = 0;
};
class VertexRendererView
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    VertexDevice* device;
    VertexDevice* GetDevice()
    {
        return device;
    }
};
class FUN_00be0b30 : public NiMemObjectAllocation
{
  public:
    FUN_00be0b30(GraphicsRenderer*);
    virtual void ShaderMethod0();
    virtual void ShaderMethod1();
    virtual void ShaderMethod2();
    virtual void ShaderMethod3();
    virtual void ShaderMethod4();
    virtual void ShaderMethod5();
    virtual void ShaderMethod6();
    virtual void ShaderMethod7();
    virtual void ShaderMethod8();
    virtual void ShaderMethod9();
    virtual void ShaderMethod10();
    virtual void ShaderMethod11();
    virtual void ShaderMethod12();
    virtual void ShaderMethod13();
    virtual void ShaderMethod14();
    virtual void ShaderMethod15();
    virtual void ShaderMethod16();
    virtual void ShaderMethod17();
    virtual void ShaderMethod18();
    virtual void ShaderMethod19();
    virtual void ShaderMethod20();
    virtual void ShaderMethod21();
    virtual void ShaderMethod22();
    virtual void ShaderMethod23();
    virtual void ShaderMethod24();
    virtual void ShaderMethod25();
    virtual void ShaderMethod26();
    virtual void ShaderMethod27();
    virtual void ShaderMethod28();
    virtual void ShaderMethod29();
    virtual void ShaderMethod30();
    virtual void ShaderMethod31();
    virtual void ShaderMethod32();
    virtual void ShaderMethod33();
    virtual void SetShader(void*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
};
extern "C" void _ReadWriteBarrier();
inline bool IsEmptyDirectory(const char* path)
{
    const char* empty = 0;
    return empty == path || !*path;
}
inline void Cat(char* d, unsigned n, const char* s)
{
    fnv::crt::strcat_s(d, n, s);
}
extern "C" void* memset(void*, int, unsigned int);
class FileView;
struct FileViewMethods
{
    void(* destroy)(FileView*, unsigned);
    void* method1;
    void* method2;
    void* method3;
    void* method4;
    void* method5;
    void* method6;
    void* method7;
    void* method8;
    void* method9;
    unsigned(* size)(FileView*);
};
class FileView
{
  public:
    FileViewMethods* methods;
};

// Compiles a vertex shader source file with macros and profile, caches the bytecode to disk, and creates a shader object on the device.
// @fnv 0x00be0fe0
FUN_00be0b30* FUN_00be0fe0(const char* source, _D3DXMACRO* macros, const char* profile,
                                     const char* shaderName)
{
    ShaderBufferRecord* pCacheEntry = 0;
    ShaderCodeBuffer_be1750* pCompiledShader = 0;
    ShaderCodeBuffer_be1750* pCompileErrors = 0;
    FUN_00be0b30* result = 0;
    ID3DXConstantTable* constants = 0;
    unsigned int bytecodeSize = 0;
    void* d3dShader;
    char cachePath[260];
    char message[260];
    char defines[1300];
    char errorMessage[260];
    char commandLine[1300];
    char diagnostic[1300];
    ::BuildCachePath(cachePath, source, shaderName);
    bool useCache = true;
    bool cacheExists = false;
    if (DAT_011f9498)
        pCacheEntry = DAT_011f9498->Get(shaderName);
    if (DAT_011ae638 && !pCacheEntry)
    {
        _ReadWriteBarrier();
        _FILETIME ftSourceTime;
        _FILETIME ftCacheTime;
        memset(&ftSourceTime, 0, sizeof(ftSourceTime));
        memset(&ftCacheTime, 0, sizeof(ftCacheTime));
        cacheExists = ::fnv_00afe7d0::FUN_00afe7d0(cachePath, (::fnv_00afe7d0::_FILETIME &)(ftCacheTime), 32);
        bool sourceExists = ::fnv_00afe7d0::FUN_00afe7d0(source, (::fnv_00afe7d0::_FILETIME &)(ftSourceTime), 32);
        if (!cacheExists && DAT_011f94a7)
        {
            if (IsEmptyDirectory((*reinterpret_cast<char (*)[260]>(&::DAT_011f9200))))
            {
                fnv::crt::strcpy_s((*reinterpret_cast<char (*)[260]>(&::DAT_011f9200)), 260, (const char*)DAT_010bc860);
                ::BuildCachePath(cachePath, source, shaderName);
            }
            cacheExists = ::fnv_00afe7d0::FUN_00afe7d0(cachePath, (::fnv_00afe7d0::_FILETIME &)(ftCacheTime), 32);
        }
        if (!sourceExists)
            ::FUN_00406d00(message, 260, (const char*)DAT_010bc82c, source);
        if (!cacheExists)
            useCache = false;
    }
    bool owned = false;
    char* bytecode = 0;
    if (pCacheEntry)
    {
        bytecode = ((CacheEntryView*)pCacheEntry)->data;
    }
    else if (!useCache)
    {
        _D3DXMACRO* addedMacro = 0;
        if (DAT_011f941e)
        {
            _D3DXMACRO* pMacro = macros;
            if (pMacro->Name)
            {
                _D3DXMACRO* next = macros + 1;
                do
                {
                    pMacro = next++;
                } while (pMacro->Name);
            }
            pMacro->Name = (const char*)DAT_010bc828;
            pMacro->Definition = (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::DAT_01011584));
            addedMacro = pMacro;
        }
        VertexShaderFile* pSourceFile = (VertexShaderFile*)FileFinder::GetFile(source, NiFile::READ_ONLY, 0x4000, 32);
        if (!pSourceFile || !pSourceFile->valid)
        {
            if (pSourceFile)
                delete pSourceFile;
            ::FUN_00406d00(message, 260, (const char*)DAT_010bc7b8, source);
            goto failure;
        }
        unsigned int sourceSize = pSourceFile->GetSize();
        char* sourceData = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(sourceSize);
        reinterpret_cast<::FUN_00462d80_shell *>((pSourceFile))->ReadBytes(sourceData, sourceSize);
        struct IncludeHandler
        {
            const unsigned char* methods;
            const char* source;
        } include;
        include.methods = DAT_010bc610;
        include.source = source;
        defines[0] = 0;
        commandLine[0] = 0;
        for (int i = 0; i < 8; i++)
        {
            if (macros[i].Name)
            {
                Cat(defines, 1300, macros[i].Name);
                Cat(commandLine, 1300, (const char*)DAT_010bc824);
                Cat(commandLine, 1300, macros[i].Name);
                if (macros[i].Definition && macros[i].Definition[0])
                {
                    Cat(defines, 1300, (const char*)DAT_01063ec8);
                    Cat(defines, 1300, macros[i].Definition);
                    Cat(commandLine, 1300, (const char*)DAT_01063ec8);
                    Cat(commandLine, 1300, macros[i].Definition);
                }
                else
                {
                    Cat(commandLine, 1300, (const char*)DAT_010bc820);
                }
                Cat(defines, 1300, (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::DAT_01012630)));
            }
        }
        ::FUN_00406d00(diagnostic, 1300, (const char*)DAT_010bc808, source, profile, defines);
        long lCompileStatus =
            ::FUN_00ee6e0a(sourceData, sourceSize, (const ::D3DXMACRO *)(macros), (ID3DXInclude*)&include, (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::str_01094d90)),
                              profile, 0, (ID3DXBuffer**)&pCompiledShader, (ID3DXBuffer**)&pCompileErrors, &constants);
        delete pSourceFile;
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(sourceData);
        if (pCompileErrors && !pCompiledShader)
        {
            defines[0] = 0;
            for (int i = 0; i < 8 && macros[i].Name; i++)
            {
                Cat(defines, 1300, macros[i].Name);
                if (macros[i].Definition && macros[i].Definition[0])
                {
                    Cat(defines, 1300, (const char*)DAT_01063ec8);
                    Cat(defines, 1300, macros[i].Definition);
                }
                Cat(defines, 1300, (const char*)(*reinterpret_cast<const unsigned char (*)[]>((void *)&::DAT_01012630)));
            }
            ::FUN_00406d00(diagnostic, 1300, (const char*)DAT_010bc7fc, source, defines,
                         pCompileErrors->GetBufferPointer());
            pCompileErrors->Release();
            pCompileErrors = 0;
        }
        if (!lCompileStatus && pCompiledShader)
        {
            _iobuf* pOutputFile = ((_iobuf *)(std::fopen(cachePath, (const char*)DAT_0106e798)));
            if (pOutputFile)
            {
                bytecodeSize = pCompiledShader->GetBufferSize();
                std::fwrite(pCompiledShader->GetBufferPointer(), bytecodeSize, 1, (std::FILE *)(pOutputFile));
                std::fclose((std::FILE *)(pOutputFile));
                ::HasFileInArchives(cachePath);
            }
            else
            {
                ::FUN_00406d00(message, 255, (const char*)DAT_010bc7e4, cachePath);
            }
            bytecode = (char*)pCompiledShader->GetBufferPointer();
        }
        else
        {
            if (!cacheExists)
                goto failure;
            VertexShaderFile* pCacheFile =
                (VertexShaderFile*)FileFinder::GetFile(cachePath, NiFile::READ_ONLY, 0x4000, 32);
            if (!pCacheFile)
                goto failure;
            if (pCacheFile->valid)
            {
                bytecodeSize = pCacheFile->GetSize();
                bytecode = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(bytecodeSize);
                owned = true;
                reinterpret_cast<::FUN_00462d80_shell *>((pCacheFile))->ReadBytes(bytecode, bytecodeSize);
            }
            delete pCacheFile;
            if (!bytecode)
                goto failure;
        }
        if (addedMacro)
        {
            addedMacro->Name = 0;
            addedMacro->Definition = 0;
        }
    }
    else
    {
        VertexShaderFile* pCacheFile = (VertexShaderFile*)FileFinder::GetFile(cachePath, NiFile::READ_ONLY, 0x4000, 32);
        if (pCacheFile)
        {
            if (pCacheFile->valid)
            {
                FileView* pFileView = (FileView*)pCacheFile;
                bytecodeSize = pFileView->methods->size(pFileView);
                bytecode = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(bytecodeSize);
                owned = true;
                reinterpret_cast<::FUN_00462d80_shell *>((pCacheFile))->ReadBytes(bytecode, bytecodeSize);
            }
            delete pCacheFile;
        }
        else
        {
            ::FUN_00406d00(errorMessage, 260, (const char*)DAT_010bc754, cachePath);
            goto failure;
        }
    }
    if (bytecode)
    {
        if (DAT_011f9494)
            reinterpret_cast<::S00b7fd90_cls *>((DAT_011f9494))->FUN_00b7fd90((unsigned int)(shaderName), (unsigned int)(bytecode), (::Thing_b9704 *)(bytecodeSize));
        else
        {
            VertexDevice* device = ((VertexRendererView*)(*reinterpret_cast<::GraphicsRenderer * *>(&::DAT_011f9508)))->GetDevice();
            if (device->CreateVertexShader(bytecode, &d3dShader))
                goto deviceError;
            result = new FUN_00be0b30((*reinterpret_cast<::GraphicsRenderer * *>(&::DAT_011f9508)));
            result->SetShader(d3dShader);
        }
    }
    if (owned)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(bytecode);
    return result;
deviceError:
    ::FUN_00406d00(errorMessage, 260, (const char*)DAT_010bc784, cachePath);
failure:
    _ReadWriteBarrier();
    return result;
}
}  // namespace fnv_00be0fe0

#include "generated/data/bsshader/bsshader.inc"
