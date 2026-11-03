// fallout_shared/facegen/bsfacegenmodel.cpp: BSFaceGenModel, FaceGenTriData, DelStandIn, FileSizeInfo and more (43 functions)

#include <cstdint>
#include <new>
#include <cstdlib>
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_00457b80_class.h"
#include "fnv/decl/FUN_00457ba0_class.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_00534570_shell.h"
#include "fnv/decl/FUN_0064dda0_cls.h"
#include "fnv/decl/FUN_00659600.h"
#include "fnv/decl/FUN_00659710_cls.h"
#include "fnv/decl/FUN_0065b3e0_Holder.h"
#include "fnv/decl/FUN_0065cc30_class.h"
#include "fnv/decl/FUN_0065cfd0_cls.h"
#include "fnv/decl/FUN_0065d050.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5bfa0_shell.h"
#include "fnv/decl/FUN_00a673d0_shell.h"
#include "fnv/decl/GeometryVertexBuffer.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/S00a67410.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/_Dummy_0044a170.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_006505d0__FUN_006505d0_class.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00607000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_0065c000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aaf000.h"
#include "fnv/symbols_00ab5000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "bsfacegenmodel_decls.h"
#include <cstring>
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/symbols_01017000.h"

// @fnv 0x0065c2c0
bool BSFaceGenModel::LoadFaceGenTexture()
{
    AutoMemContext context(FaceGenTextureContext, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 1336);
    if (!m_kTextureSlots)
        return false;
    if (!m_kTextureSlots->m_pTextureData)
    {
        if (!((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(m_kTextureSlots->EGTFileName))->FUN_004048e0())))
            return false;
        m_kTextureSlots->m_pTextureData = FUN_00659780(((const char *)(::FUN_00559450((int *)&(m_kTextureSlots->EGTFileName)))));
    }
    return true;
}

// @fnv 0x0065a760
bool BSFaceGenModel::LoadFaceGenTexture(const char* filename)
{
    if (m_kTextureSlots || !filename)
        return true;
    AutoMemContext context(FaceGenTextureContext, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 448);
    m_kTextureSlots = new BSFaceGenTexture;
    reinterpret_cast<::TextString *>(&(m_kTextureSlots->EGTFileName))->FUN_004037f0(filename, 0);
    return true;
}

// Resolves the given object via GetGeomExtraData and returns the result of its vfn_94 virtual call, or null if resolution fails.
// @fnv 0x006530e0
NiAVObject* BSFaceGenModel::GetFaceGenModelNode(NiAVObject* object)
{
    NiAVObject* result = ((::NiAVObject *)(::GetGeomExtraData((::NiTriBasedGeom *)(object))));
    return result ? result->vfn_94() : 0;
}

void* FUN_00659670(void* pThis, int, const char* apEGTFilename);

struct Dummy_00659780
{
    char pad[0x34];
    Dummy_00659780(const char* apEGTFilename)
    {
        FUN_00659670(this, 0, apEGTFilename);
    }
};

// Allocates a Dummy_00659780 object, constructing it from apEGTFilename, and returns it as a pointer.
// @fnv 0x00659780
FaceGenTextureFile* __cdecl FUN_00659780(const char* apEGTFilename)
{
    return (FaceGenTextureFile*)new Dummy_00659780(apEGTFilename);
}

void FUN_00659b50(void*);

struct NiMemObject
{
};

struct FUN_00659b20_thiscall
{
    void* FUN_00659b20(unsigned int flags);
};

struct FUN_00659c70_shell : public BSFaceGenModel
{
    bool FUN_00659c70(char*, char*, char*, char*, int, bool);
};


// @fnv 0x00659c70
bool FUN_00659c70_shell::FUN_00659c70(char* apEGMFilename, char* apNIFFilename, char* apTRIFilename,
                                      char* apEGTFilename, int aeHairPart, bool abIsAccessory)
{
    bool breturn = false;
    if (!((bool)(::FUN_0043faf0())))
        return false;
    breturn |=
        LoadModelMesh(apEGMFilename, apNIFFilename, apTRIFilename, static_cast<HAIR_PART>(aeHairPart), abIsAccessory);
    breturn |= LoadFaceGenTexture(apEGTFilename);
    return breturn;
}

struct StatisticalEntry;
class StatisticalArray
{
  public:
    StatisticalEntry* FUN_00662890(unsigned int);
};

// @fnv 0x0065a5a0
unsigned int FaceGenTriData::FUN_0065a5a0()
{
    unsigned int uiMinValue = ::FUN_0065c700((const ::_Vec12 *)this);
    for (unsigned int uiIndex = 0; uiIndex < ((unsigned int)(reinterpret_cast<::FUN_0065cc30_class *>((((StatisticalArray*)((char*)this + 0xd8))))->FUN_0065cc30())); ++uiIndex)
    {
        if (*(unsigned int*)((char*)((StatisticalArray*)((char*)this + 0xd8))->FUN_00662890(uiIndex) + 0x1c) <
            uiMinValue)
        {
            uiMinValue =
                *(unsigned int*)((char*)((StatisticalArray*)((char*)this + 0xd8))->FUN_00662890(uiIndex) + 0x1c);
        }
    }
    return uiMinValue;
}

struct FourComponentFloatVector;
struct NiAdditionalGeometryData;
struct NiBound;
struct RgbaColor;
struct NiCullingProcess;
struct NiObject;
struct NiPoint2;
struct NiPropertyState;
struct NiRenderer;
struct NiShader;
struct NiSkinInstance;
struct NiStream;
struct NiGeometry : public NiAVObject
{
    virtual void __vslot_0();
    virtual void RenderImmediate(NiRenderer*);
    virtual void RenderWithRenderer(NiRenderer*);
    virtual void ReplaceModelData(NiGeometryData*);
    virtual void CalculateNormals();
    virtual void CalculateConsistency(bool);
    virtual void* GetRTTI();
    void CopyMemberData(NiGeometry*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    virtual void GetViewerStrings(void*);
    unsigned short GetVertexCount();
    NiPoint3* GetVertices();
    void SetActiveVertexQuantity(unsigned short);
    unsigned short GetActiveVertexQuantity();
    void SetDynamicData(bool);
    NiPoint3* GetNormals();
    int GetNormalBinormalTangentMethod();
    void StoreNormalBinormalTangent(int);
    void SetModelBound(void*);
    NiBound* GetModelBound();
    void CreateColors(bool);
    RgbaColor* GetColors();
    void CreateTextures(bool, unsigned short);
    unsigned short GetTextureSets();
    NiPoint2* GetTextures();
    NiPoint2* GetTextureSet(unsigned short);
    void AppendTextureSet(NiPoint2*);
    NiSkinInstance* GetSkinInstance();
    void SetSkinInstance(NiSkinInstance*);
    NiAdditionalGeometryData* GetAdditionalGeometryData();
    void AssignAdditionalGeometryData(NiAdditionalGeometryData*);
    void SetSortObject(bool);
    bool GetSortObject();
    NiPropertyState* GetPropertyStateP();
    virtual NiGeometry* IsGeometry();
    virtual void SetObjectBound(FourComponentFloatVector*);
    NiShader* GetGeometryShaderObject();
    NiShader* GetShaderFromMaterial();
    void SetShader(NiShader*);
    bool HasGeometryProperty(int);
    virtual void OnVisible(NiCullingProcess*);
    virtual void ApplyTransform(void*, void*, bool);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
    int GetConsistency();
    void SetDataConsistency(int);
    virtual void ProcessClone(CloningProcess*);
    virtual void PostLinkObject(NiStream*);
    virtual void SetSelectiveUpdateFlags(bool*, bool, bool*);
    virtual void PurgeRendererData(NiRenderer*);
    unsigned int QMemContext();
    virtual void UpdateWorldBound();
    void __local_vftable_ctor_closure();
    char _pad_4[188];
    char m_kPropertyState[28];
    char m_spGeometryData[4];
    char m_spSkinningInstance[4];
    NiShader* m_pGeometryShader;
    unsigned int m_uiGeometryShaderFlags;
    char _pad_ec[4];
};
struct FUN_0065a620_shell : public NiGeometry
{
    void FUN_0065a620(int);
};
// @fnv 0x00659ce0
bool BSFaceGenModel::LoadModelMesh(const char* egmPath, const char* nifPath, const char* triPath, HAIR_PART part,
                                   bool keepProperty)
{
    if (m_pGeometryModel || !egmPath)
        return true;
    AutoMemContext context(FaceGenMeshContext, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 286);
    m_pGeometryModel = new FaceGenGeometryModel;
    reinterpret_cast<::TextString *>(&(m_pGeometryModel->m_kEGMFileName))->FUN_004037f0(egmPath, 0);
    if (nifPath)
    {
        unsigned int count;
        NiAVObject* i;
        unsigned int child;
        NiNode* root = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(nifPath + 7), 0, true, false, true, true);
        if (root)
        {
            CloningProcess cloning(1.0f);
            m_pGeometryModel->m_spModelRoot = ((::NiNode *)(reinterpret_cast<::FUN_00457ba0_class *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00457ba0((::NiAVObject *)(root), (::CloningProcess *)&(cloning))));
            if (m_pGeometryModel->m_spModelRoot)
            {
                child = m_pGeometryModel->m_spModelRoot->FUN_0043b480();
                for (count = 0; count < child; count++)
                {
                    i = m_pGeometryModel->m_spModelRoot->GetAt(count);
                    if (i)
                    {
                        switch (part)
                        {
                        case HAIR_PART_NORMAL:
                            if (child == 1)
                            {
                                ((NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry) = i->IsTriBasedGeom();
                            }
                            else
                            {
                            case HAIR_PART_HAT:
                                if (!FUN_00404dc0((*(::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((i))->GetLinkToList())), DAT_0119b734[part]))
                                    ((NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry) = i->IsTriBasedGeom();
                            }
                            break;
                        default:
                            ((NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry) = i->IsTriBasedGeom();
                            break;
                        }
                    }
                    if (((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator NiAVObject*())
                        break;
                }
                if (((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator NiAVObject*())
                {
                    if (!keepProperty)
                        reinterpret_cast<::ExtraOwnerB *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->FUN_00a5b230(FUN_004af340());
                    reinterpret_cast<::NiObjectNET *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->FUN_00a5c050();
                    reinterpret_cast<::FUN_00a5bfa0_shell *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->ClearExtraData();
                    if (((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->()))))))
                        ((BGSQuestObjective*)((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry)
                                                  .
                                                  operator->()))))))->SetOwner(
                                (TESQuest*)(NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry)
                                    .
                                    operator NiAVObject*());
                    reinterpret_cast<::TaskQueueInterface *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->FUN_004902f0(true);
                }
                reinterpret_cast<::FUN_00a5a040_Class *>((root))->FUN_00a5a040();
                NiUpdateData update(0.0f, false, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((root))->FUN_00a59c60((std::intptr_t)&(update));
            }
        }
        else
        {
            ::FUN_005b5e40();
            return false;
        }
    }
    if (triPath)
    {
        FaceGenTriData* i = new FaceGenTriData;
        unsigned int tri;
        if (::fnv_00ab5ec0::FUN_00ab5ec0((const ::fnv_00ab5ec0::TriString &)((const ::NarrowString &)(triPath)), (::fnv_00ab5ec0::Geometry *)(i)) &&
            reinterpret_cast<::FUN_00456650_shell *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->FUN_00456650() ==
                i->FUN_0065a5a0())
        {
            if (part != HAIR_PART_NONE)
                ((NiPointer<NiAVObject>&)m_pGeometryModel->m_spFaceMorphData) =
                    (NiAVObject*)new BSFaceGenMorphDataHair(i);
            else
            {
                ((NiPointer<NiAVObject>&)m_pGeometryModel->m_spFaceMorphData) =
                    (NiAVObject*)new BSFaceGenMorphDataHead(i);
                if (::FUN_0065c700((const ::_Vec12 *)(i)) >
                    reinterpret_cast<::FUN_00456650_shell *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->FUN_00456650())
                {
                    m_pGeometryModel->m_uiAdditionalVertexCount =
                        ::FUN_0065c700((const ::_Vec12 *)(i)) -
                        reinterpret_cast<::FUN_00456650_shell *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->FUN_00456650();
                    m_pGeometryModel->pAdditionalVertices = new NiPoint3[m_pGeometryModel->m_uiAdditionalVertexCount];
                    for (tri = 0; tri < m_pGeometryModel->m_uiAdditionalVertexCount; tri++)
                    {
                        m_pGeometryModel->pAdditionalVertices[tri] = NiPoint3(
                            i->FUN_0065c720(i->FUN_0065a5a0() + tri).x, i->FUN_0065c720(i->FUN_0065a5a0() + tri).y,
                            i->FUN_0065c720(i->FUN_0065a5a0() + tri).z);
                    }
                }
            }
        }
        delete i;
    }
    if (m_pGeometryModel && ((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator NiAVObject*())
        reinterpret_cast<::FUN_0065a620_shell *>((((NiTriBasedGeom*)((const NiPointer<NiAVObject>&)m_pGeometryModel->m_pRenderedNodeEntry).operator->())))->FUN_0065a620(false);
    return true;
}

struct NiGeometryData_SetConsistency_View
{
    void SetDataConsistency(int);
};

// Forwards eConsistency to the consistency setter of the geometry data obtained from the object at offset 0xb8.
// @fnv 0x0065a620
void FUN_0065a620_shell::FUN_0065a620(int eConsistency)
{
    reinterpret_cast<NiGeometryData_SetConsistency_View*>(
        ((void *)(::FUN_00559450((int *)(reinterpret_cast<GeometryBufferView*>(reinterpret_cast<char*>(this) + 0xb8))))))
        ->SetDataConsistency(eConsistency);
}

struct S_0065c6a0
{
    int a[6];
    ~S_0065c6a0();
};
struct S_0065c7c0
{
    int a[6];
    ~S_0065c7c0();
};
struct S_0065c890
{
    int a[6];
    ~S_0065c890();
};
struct S_0065c960
{
    int a[6];
    ~S_0065c960();
};
struct S_0065ca30
{
    int a[6];
    ~S_0065ca30();
};
struct S_0065cb00
{
    int a[6];
    ~S_0065cb00();
};
struct S_0065cbd0
{
    int a[6];
    ~S_0065cbd0();
};

void FUN_0065c6a0(void*);
void FUN_0065c7c0(void*);
void FUN_0065c890(void*);
void FUN_0065c960(void*);
void FUN_0065ca30(void*);
void FUN_0065cb00(void*);
void FUN_0065cbd0(void*);

struct FUN_0065a680
{
    S_0065c6a0 m0;
    S_0065c6a0 m1;
    S_0065c7c0 m2;
    S_0065c890 m3;
    S_0065c6a0 m4;
    S_0065c7c0 m5;
    S_0065c960 m6;
    S_0065ca30 m7;
    S_0065cb00 m8;
    S_0065cbd0 m9;
    ~FUN_0065a680();
};

// @fnv 0x0065a680
FUN_0065a680::~FUN_0065a680()
{}

S_0065c6a0::~S_0065c6a0()
{
    FUN_0065c6a0(this);
}
S_0065c7c0::~S_0065c7c0()
{
    FUN_0065c7c0(this);
}
S_0065c890::~S_0065c890()
{
    FUN_0065c890(this);
}
S_0065c960::~S_0065c960()
{
    FUN_0065c960(this);
}
S_0065ca30::~S_0065ca30()
{
    FUN_0065ca30(this);
}
S_0065cb00::~S_0065cb00()
{
    FUN_0065cb00(this);
}
S_0065cbd0::~S_0065cbd0()
{
    FUN_0065cbd0(this);
}

class BSFadeNode
{
  public:
    int m_unk;
    BSFadeNode(const char* name);
};


// Allocates a BSFadeNode named "FMD" and stores it in DAT_011d5b50.
// @fnv 0x0065c570
void __cdecl FUN_0065c570()
{
    DAT_011d5b50 = new BSFadeNode("FMD");
}

struct _Elem12
{
    int a, b, c;
};

struct _Vec12
{
    int pad0, pad1, pad2;
    _Elem12* _Myfirst;
    _Elem12* _Mylast;
};

// @fnv 0x0065c700
unsigned int FUN_0065c700(const _Vec12* pVec)
{
    return pVec->_Mylast - pVec->_Myfirst;
}


// Bounds-checks _Pos against FUN_0065c700() and returns the NiPoint3 element at that index from the array at data[3].
// @fnv 0x0065c720
NiPoint3& FaceGenTriData::FUN_0065c720(unsigned int uiIndex)
{
    if (uiIndex >= ::FUN_0065c700((const ::_Vec12 *)this))
    {
        std::abort();
    }
    do
    {
    } while (0);
    return reinterpret_cast<NiPoint3*>(data[3])[uiIndex];
}

extern unsigned int _data_011c16bc;
struct FUN_0065c630
{
    char p[0x18];
    FUN_0065c630();
    ~FUN_0065c630();
};
struct FUN_0065c750
{
    char p[0x18];
    FUN_0065c750();
    ~FUN_0065c750();
};
struct FUN_0065c820
{
    char p[0x18];
    FUN_0065c820();
    ~FUN_0065c820();
};
struct FUN_0065c8f0
{
    char p[0x18];
    FUN_0065c8f0();
    ~FUN_0065c8f0();
};
struct FUN_0065c9c0
{
    char p[0x18];
    FUN_0065c9c0();
    ~FUN_0065c9c0();
};
struct FUN_0065ca90
{
    char p[0x18];
    FUN_0065ca90();
    ~FUN_0065ca90();
};
struct FUN_0065cb60
{
    char p[0x18];
    FUN_0065cb60();
};
struct FUN_0065a4c0
{
    FUN_0065c630 m0;
    FUN_0065c630 m1;
    FUN_0065c750 m2;
    FUN_0065c820 m3;
    FUN_0065c630 m4;
    FUN_0065c750 m5;
    FUN_0065c8f0 m6;
    FUN_0065c9c0 m7;
    FUN_0065ca90 m8;
    FUN_0065cb60 m9;
    FUN_0065a4c0();
};
// Default constructor for FUN_0065a4c0 that initializes its member subobjects.
// @fnv 0x0065a4c0
FUN_0065a4c0::FUN_0065a4c0()
{}

struct FUN_0065a910_shell : public BSFaceGenModel
{
    bool FUN_0065a910(void*, void*);
};

struct FUN_0065bbc0_h
{
};
struct FUN_00559450_h
{
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct EBase
{
    virtual void Unk00();
    ~EBase();
};
struct FUN_00659c10
{
    ~FUN_00659c10();
};
struct FUN_00659c40
{
    ~FUN_00659c40();
};
struct FUN_00659b50 : EBase
{
    int pad;
    FUN_00659c10* m_pGeometryModel;
    FUN_00659c40* m_kTextureSlots;
    virtual ~FUN_00659b50();
};
// Calls FUN_00659b50 on this, frees this with NiMemObject::operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00659b20
void* FUN_00659b20_thiscall::FUN_00659b20(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_00659b50 *>((this))->FUN_00659b50::~FUN_00659b50();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}
// @fnv 0x00659b50
FUN_00659b50::~FUN_00659b50()
{
    if (m_pGeometryModel)
        delete m_pGeometryModel;
    if (m_kTextureSlots)
        delete m_kTextureSlots;
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_0065a650(unsigned int flags);
};
// Calls the destructor on this, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0065a650
void* DelStandIn::FUN_0065a650(unsigned int flags)
{
    reinterpret_cast<::FUN_0065a680 *>((((DtorStandIn*)this)))->FUN_0065a680::~FUN_0065a680();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

// @fnv 0x00657bc0
int FUN_00657bc0(std::intptr_t param_1)
{
    return (*(int*)(param_1 + 0x10) - *(int*)(param_1 + 0xc)) / 6;
}

struct GlobalObject_00a7b610
{
};

struct FUN_0065bee0_shell
{
    GlobalObject_00a7b610* GetGlobalObject();
};

// @fnv 0x0065bee0
GlobalObject_00a7b610* FUN_0065bee0_shell::GetGlobalObject()
{
    return &::g_011d5b58;
}

struct FUN_0065cca0
{
    unsigned int uiNumMorphs;
    unsigned int m_uiScaleCount;
    float* pScales;
    void* pFirst;
    void* pLast;
    void* pEnd;
    FUN_0065cca0();
    ~FUN_0065cca0();
};
struct FUN_00659560
{
    unsigned int m_uiScaleCount;
    FUN_0065cca0 kMorphs[2];
    FUN_00659560(const char* apcPath);
};

// Constructs a name from apcPath and passes it with this and both kMorphs entries to FUN_00aafc80.
// @fnv 0x00659560
FUN_00659560::FUN_00659560(const char* apcPath)
{
    NarrowString kName(apcPath);
    ::fnv_00aafc80::FUN_00aafc80((const ::fnv_00aafc80::std::basic_string<char, ::fnv_00aafc80::std::char_traits<char>, ::fnv_00aafc80::std::allocator<char>> &)(kName), (int *)(void *)(this), (::fnv_00aafc80::Arr28 *)(void *)(&kMorphs[0]), (::fnv_00aafc80::Arr28 *)(void *)(&kMorphs[1]));
}

struct StrMem
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    StrMem();
    ~StrMem();
};
struct NP
{
    void* m_pObject;
    NP& operator=(void* pObject);
};
struct GO : public NP
{
    GO(intptr_t pObject = 0);
    ~GO();
    using NP::operator=;
};
struct FUN_00659800
{
    StrMem m_kEGMFileName;
    FaceGenMorphData* m_pModelData;
    GO m_spModelRoot;
    GO m_pRenderedNodeEntry;
    NiPoint3* pAdditionalVertices;
    unsigned int m_uiAdditionalVertexCount;
    GO m_spFaceMorphData;
    int BackgroundTask;
    FUN_00659800();
};

// @fnv 0x00659800
FUN_00659800::FUN_00659800()
{
    m_pModelData = 0;
    m_pRenderedNodeEntry = 0;
    m_spModelRoot = 0;
    m_spFaceMorphData = 0;
    pAdditionalVertices = 0;
    m_uiAdditionalVertexCount = 0;
    BackgroundTask = 0;
}

namespace fnv_006598d0 {
struct BSS
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    ~BSS();
};
struct NP
{
    void* m_pObject;
    NP& operator=(void* pObject);
};
struct GO : public NP
{
    ~GO();
    using NP::operator=;
};
struct FUN_006599d0
{
    ~FUN_006599d0();
};
struct FUN_006598d0
{
    BSS m_kEGMFileName;
    FUN_006599d0* m_pModelData;
    GO m_spModelRoot;
    GO m_pRenderedNodeEntry;
    NiPoint3* pAdditionalVertices;
    unsigned int m_uiAdditionalVertexCount;
    GO m_spFaceMorphData;
    int BackgroundTask;
    ~FUN_006598d0();
};

// @fnv 0x006598d0
FUN_006598d0::~FUN_006598d0()
{
    m_pRenderedNodeEntry = 0;
    m_spModelRoot = 0;
    m_spFaceMorphData = 0;
    if (pAdditionalVertices)
        delete pAdditionalVertices;
    if (m_pModelData)
        delete m_pModelData;
}
}  // namespace fnv_006598d0

struct BSS
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    ~BSS();
};
struct FaceGenTextureFile
{
    ~FaceGenTextureFile();
};
struct FUN_00659a20
{
    BSS strName;
    FaceGenTextureFile* m_pTextureData;
    ~FUN_00659a20();
};

// @fnv 0x00659a20
FUN_00659a20::~FUN_00659a20()
{
    if (m_pTextureData)
        delete m_pTextureData;
}

struct FUN_0065a840_t : public BSFaceGenModel
{
    void FUN_0065a840();
};

// @fnv 0x0065a840
void FUN_0065a840_t::FUN_0065a840()
{
    if (!m_kTextureSlots)
    {
        const char* pegmfile = ((const char *)(reinterpret_cast<::fnv_006505d0::FUN_006505d0_class *>(this)->GetFloatValue()));
        if (pegmfile)
        {
            char pegtfile[260];
            ::TaskQueueInterface::CopyStringToBuffer(pegtfile, 260, pegmfile);
            char* pExtension = FUN_0040ab30(pegtfile, '.');
            if (pExtension)
            {
                *pExtension = 0;
                strcat_s(pegtfile, 260, ".egt");
                LoadFaceGenTexture(pegtfile);
                LoadFaceGenTexture();
            }
        }
    }
}

namespace fnv_0065bf80 {
struct FUN_0065bf80_shell : public BSFaceGenModel
{
    bool EnsureMorphData();
};

struct AutoMemHelper
{
    int iOldContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct S7010
{
};
struct FUN_0065cca0
{
    unsigned int uiNumMorphs;
    unsigned int m_uiScaleCount;
    float* pScales;
    void* pFirst;
    void* pLast;
    void* pEnd;
    FUN_0065cca0();
};
struct FUN_00659560
{
    unsigned int m_uiScaleCount;
    FUN_0065cca0 kMorphs[2];
    FUN_00659560(const char*);
};

// @fnv 0x0065bf80
bool FUN_0065bf80_shell::EnsureMorphData()
{
    AutoMemHelper tempMemContext(
        0x38, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 0x4f0);
    if (!m_pGeometryModel)
        return false;
    if (!*(FUN_00659560**)&m_pGeometryModel->m_pModelData)
    {
        if (!((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)m_pGeometryModel)))->FUN_004048e0())))
            return false;
        *(FUN_00659560**)&m_pGeometryModel->m_pModelData =
            new FUN_00659560((const char*)::FUN_00559450((int*)m_pGeometryModel));
    }
    return true;
}
}  // namespace fnv_0065bf80

struct EGMDeltaList;
struct EGMMorph
{
    float fScale;
};
struct EGMMorphList
{
    unsigned int ItemUpdateArray;
    unsigned int uiCapacity;
    EGMMorph* pMorphs;
    void* pFirst;
    void* pLast;
    void* pEnd;
    EGMMorph& GetMorphEntry(unsigned int uiIndex);
};
struct EGMDataStandIn
{
    unsigned int m_uiScaleCount;
    EGMMorphList kMorphs[2];
};
struct FUN_0065c110_t : public BSFaceGenModel
{
    unsigned int GetEGMSize();
};

struct FileSizeInfo
{
    enum ErrorCode
    {
        BSSF_OK = 0
    };
    enum AccessMode
    {
        AM_READ = 0
    };
    enum OpenMode
    {
        OM_NONE = 0
    };
    ErrorCode m_eErrorCode;
    AccessMode m_eAccessMode;
    OpenMode m_eOpenMode;
    bool bSynchronousNoBuffer;
    bool bIsOpen;
    void* hFile;
    FileSizeInfo(const char* apcPath, AccessMode aeAccessMode, OpenMode aeOpenMode, bool abSynchronousNoBuffer);
    ~FileSizeInfo();
    ErrorCode FUN_00559450();
    ErrorCode FUN_0065c290(unsigned __int64& auiSize);
    static ErrorCode GetFileSize(const char* apcPath, unsigned __int64& auiSize);
};

// Opens the file at apcPath for reading, queries its size into auiSize, and returns the error code; sets auiSize to 0 if opening fails.
// @fnv 0x0065c1f0
FileSizeInfo::ErrorCode FileSizeInfo::GetFileSize(const char* apcPath, unsigned __int64& auiSize)
{
    FileSizeInfo::ErrorCode eError;
    FileSizeInfo File(apcPath, AM_READ, OM_NONE, false);
    eError = File.FUN_00559450();
    if (eError == BSSF_OK)
        eError = File.FUN_0065c290(auiSize);
    else
        auiSize = 0;
    return eError;
}

namespace fnv_0065c400 {
struct BSS
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    ~BSS();
};
struct FaceGenTextureFile
{
    ~FaceGenTextureFile();
};
struct FUN_00659c40
{
    BSS strName;
    FaceGenTextureFile* m_pTextureData;
    ~FUN_00659c40();
};
struct FUN_0065c400_t : public BSFaceGenModel
{
    void FUN_0065c400();
};

// @fnv 0x0065c400
void FUN_0065c400_t::FUN_0065c400()
{
    if (m_kTextureSlots)
    {
        delete ((FUN_00659c40*)m_kTextureSlots)->m_pTextureData;
        ((FUN_00659c40*)m_kTextureSlots)->m_pTextureData = 0;
        delete (FUN_00659c40*)m_kTextureSlots;
        m_kTextureSlots = 0;
    }
}
}  // namespace fnv_0065c400

struct FUN_00657c00_shell
{
    int GetCount();
};
// Sums the size of the EGM data: base struct plus per-morph list and delta sizes for both morph lists, returning the total.
// @fnv 0x0065c110
unsigned int FUN_0065c110_t::GetEGMSize()
{
    unsigned int uiSize = 0;
    unsigned int i;
    unsigned int j;
    if (m_pGeometryModel && m_pGeometryModel->m_pModelData)
    {
        uiSize = sizeof(EGMDataStandIn);
        for (i = 0; i < 2; i++)
        {
            uiSize += ((unsigned int)(reinterpret_cast<::FUN_00657c00_shell *>(&(((EGMDataStandIn*)m_pGeometryModel->m_pModelData)->kMorphs[i]))->GetCount())) * 0x18;
            for (j = 0; j < ((unsigned int)(reinterpret_cast<::FUN_00657c00_shell *>(&(((EGMDataStandIn*)m_pGeometryModel->m_pModelData)->kMorphs[i]))->GetCount())); j++)
                uiSize += ::FUN_00657bc0((std::intptr_t)((EGMDeltaList*)((char*)&((EGMDataStandIn*)m_pGeometryModel->m_pModelData)
                                                           ->kMorphs[i]
                                                           .GetMorphEntry(j) +
                                                       4))) *
                          6;
        }
    }
    return uiSize;
}

// @fnv 0x00657c00
int FUN_00657c00_shell::GetCount()
{
    return (*(int*)((char*)this + 0x10) - *(int*)((char*)this + 0xc)) / 0x1c;
}

struct FUN_00659c10_shell
{
    void FUN_006598d0();
    void* FUN_00659c10(unsigned int flags);
};

// Calls FUN_006598d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00659c10
void* FUN_00659c10_shell::FUN_00659c10(unsigned int flags)
{
    reinterpret_cast<::fnv_006598d0::FUN_006598d0 *>(this)->fnv_006598d0::FUN_006598d0::~FUN_006598d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct BSFaceGenModelExtraData
{
    void FUN_0065bf20();
    void* FUN_0065bef0(unsigned int flags);
};

namespace fnv_00657c20 {
struct EGMMorphList
{
    char _pad[12];
    ::FaceGenMorphTarget* _base;
    ::FaceGenMorphTarget& GetMorphEntry(unsigned int);
};
// Bounds-checks idx against the morph count, then returns the address of the entry at idx (stride 0x1c) from _base.
// @fnv 0x00657c20
::FaceGenMorphTarget& EGMMorphList::GetMorphEntry(unsigned int idx)
{
    if (idx >= ((unsigned int)(reinterpret_cast<::FUN_00657c00_shell *>(this)->GetCount())))
        std::abort();
    do
    {
    } while (0);
    return _base[idx];
}
}  // namespace fnv_00657c20

struct Unk_006599d0
{
    void* FUN_006599d0(unsigned int);
};
// Calls FUN_00659600, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006599d0
void* Unk_006599d0::FUN_006599d0(unsigned int flags)
{
    reinterpret_cast<::FUN_00659600 *>(this)->FUN_00659600::~FUN_00659600();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00659a00 {
struct StrMem
{
    int _0;
    int _4;
    StrMem();
};
struct FUN_00659a00 : StrMem
{
    int _8;
    FUN_00659a00();
};
// Initializes the _8 member to 0 after the base StrMem constructor runs.
// @fnv 0x00659a00
FUN_00659a00::FUN_00659a00()
{
    _8 = 0;
}
}  // namespace fnv_00659a00

struct BSFadeNode;
struct Holder_004b9900
{
};
// Calls FUN_004b9900(1) on DAT_011d5b50 if it is non-null, then sets DAT_011d5b50 to null.
// @fnv 0x0065c5f0
void FUN_0065c5f0()
{
    BSFadeNode* pFadeNode;
    {
        BSFadeNode* bInner = DAT_011d5b50;
        pFadeNode = bInner;
        {
            std::intptr_t iRes;
            if (pFadeNode)
                iRes = ((std::intptr_t)(reinterpret_cast<::NiFixedString *>((((Holder_004b9900*)pFadeNode)))->FUN_004b9900(1)));
            else
                iRes = 0;
        }
    }
    DAT_011d5b50 = 0;
}

namespace fnv_0065c6a0 {
extern int _data_011c16bc;
struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
struct FUN_0065c6a0 : FUN_0065cfb0
{
    ~FUN_0065c6a0();
};
// @fnv 0x0065c6a0
FUN_0065c6a0::~FUN_0065c6a0()
{
    reinterpret_cast<::FUN_0065d050 *>(this)->Clear_0065d050();
}
}  // namespace fnv_0065c6a0


struct Cls_659ab0
{
    void* FUN_00659ab0(unsigned int flags);
};

// Calls FUN_00659710, then if bit 0 of flags is set calls FUN_00401030 on this, and returns this.
// @fnv 0x00659ab0
void* Cls_659ab0::FUN_00659ab0(unsigned int flags)
{
    reinterpret_cast<::FUN_00659710_cls *>(this)->FUN_00659710_cls::~FUN_00659710_cls();
    if (flags & 1)
        FUN_00401030(this);
    return this;
}

struct ModelName
{
    ~ModelName();
};
struct ExtraDataBase
{
    ~ExtraDataBase();
};
struct FUN_0065bf20 : ExtraDataBase
{
    unsigned int flags;
    unsigned int refCount;
    unsigned int subtype;
    ModelName name;
    ~FUN_0065bf20();
};
// Calls FUN_0065bf20, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x0065bef0
void* BSFaceGenModelExtraData::FUN_0065bef0(unsigned int flags)
{
    reinterpret_cast<::FUN_0065bf20 *>((this))->FUN_0065bf20::~FUN_0065bf20();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}
// @fnv 0x0065bf20
FUN_0065bf20::~FUN_0065bf20()
{}

struct FUN_0065c090_Inner
{
    int unk00;
    int unk04;
    Unk_006599d0* unk08;
};

struct FUN_0065c090_shell
{
    int unk00;
    int unk04;
    FUN_0065c090_Inner* unk08;
    bool FUN_0065c090();
};

// @fnv 0x0065c090
bool FUN_0065c090_shell::FUN_0065c090()
{
    if (unk08 && unk08->unk08)
    {
        if (!((std::intptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((unk08))->FUN_007af430())))
        {
            Unk_006599d0* pCopy = unk08->unk08;
            Unk_006599d0* p = pCopy;
            p ? p->FUN_006599d0(1) : 0;
            unk08->unk08 = 0;
        }
        else
        {
            return false;
        }
    }
    return true;
}

extern int DAT_01065af4;
class FUN_004968b0
{
  public:
    void* m_vt;
    int m_iWordAt04;
    FUN_004968b0();
};
class FUN_00659ae0 : public FUN_004968b0
{
  public:
    int m_8;
    int m_iThirdValue;
    FUN_00659ae0();
};
// Initializes the vtable pointer to DAT_01065af4 and zeroes the two integer members.
// @fnv 0x00659ae0
FUN_00659ae0::FUN_00659ae0()
{
    m_vt = &DAT_01065af4;
    m_8 = 0;
    m_iThirdValue = 0;
}

struct FUN_0065a970_shell : BSFaceGenModel
{
    bool ApplyMorphs(FaceGenCoordinate* apCoordinate, NiTriBasedGeom* apGeometry, bool abIncludeZero);
};
// @fnv 0x0065a910
bool FUN_0065a910_shell::FUN_0065a910(void* apCoord, void* aspReturnMesh)
{
    if (!apCoord)
        return false;
    if (!reinterpret_cast<::BSFaceGenModel *>((((FUN_0065bbc0_h*)this)))->CloneTriBasedGeom((*(::NiPointer< ::NiTriBasedGeom> *)(aspReturnMesh))))
        return false;
    if (!reinterpret_cast<::FUN_0065a970_shell *>(this)->ApplyMorphs((FaceGenCoordinate*)apCoord, ((::NiTriBasedGeom *)(::FUN_00559450((int *)(((FUN_00559450_h*)aspReturnMesh))))), true))
    {
        *(NP_0081c630*)aspReturnMesh = 0;
        return false;
    }
    return true;
}

// Applies face-gen morph data to apGeometry vertices using apCoordinate weights, updating positions and additional geometry data in place.
// @fnv 0x0065a970
bool FUN_0065a970_shell::ApplyMorphs(FaceGenCoordinate* apCoordinate, NiTriBasedGeom* apGeometry, bool abIncludeZero)
{
    if (!m_pGeometryModel)
        return false;
    if (!apCoordinate)
        apCoordinate = BSFaceGenManager::GetFaceGenCoordinates();
    if (!apCoordinate)
        return false;

    FUN_00652140();
    if (!::fnv_00651f70::FUN_00651f70((std::intptr_t)(this)))
    {
        if (!m_pGeometryModel->m_pModelData)
        {
            if (!((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(m_pGeometryModel->m_kEGMFileName))->FUN_004048e0())))
            {
                ::fnv_00652190::FUN_00652190();
                return false;
            }
            m_pGeometryModel->m_pModelData = new FaceGenMorphData(((const char *)(::FUN_00559450((int *)&(m_pGeometryModel->m_kEGMFileName)))));
        }
        if (!m_pGeometryModel->m_pModelData)
        {
            ::fnv_00652190::FUN_00652190();
            return false;
        }
    }

    unsigned int uiNumAdditionalVal = 0;
    NiPoint3* pAdditional = 0;
    NiPoint3* pVerticesCount = 0;
    NiPoint3* pThePositions = 0;
    BSFaceGenBaseMorphExtraData* pLastMorphExtra = ((::BSFaceGenBaseMorphExtraData *)(::GetExtraDataIfPresent((::NiAVObject *)(apGeometry))));
    NiPoint3* pExtraVerticesTmp = pLastMorphExtra ? ((::NiPoint3 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pLastMorphExtra))->FUN_0084e3a0())) : 0;
    NiPoint3* pExtra = 0;
    bool bPackedResult = false;
    GeometryBufferView kIteratorNum;
    if (apGeometry)
    {
        NiGeometryData* pData = ((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeometry))));
        if (pData && pData->IsGeometryDataStreamable(1))
        {
            reinterpret_cast<::S00a67410 *>((pData))->FUN_00a67410((::BSFaceGenMorphData *)&(kIteratorNum));
            uiNumAdditionalVal = *((unsigned int *)(reinterpret_cast<::BaseProcess *>(&(kIteratorNum))->GetCurrentProcessData()));
            pVerticesCount = (NiPoint3*)((void *)(::FUN_00559450((int *)&(kIteratorNum))));
        }
    }

    unsigned int uiNumVertices;
    if (pVerticesCount)
    {
        uiNumVertices = reinterpret_cast<::FUN_00456650_shell *>((apGeometry))->FUN_00456650();
    }
    else
    {
        ::fnv_00652190::FUN_00652190();
        return false;
    }

    unsigned int uiMorphCountVal;
    for (unsigned int uiMode = 0; uiMode < 2; uiMode++)
    {
        uiMorphCountVal = ((unsigned int)(reinterpret_cast<::FUN_00657c00_shell *>((void *)&(m_pGeometryModel->m_pModelData->modes[uiMode]))->GetCount()));
        for (unsigned int i = 0; i < uiMorphCountVal; i++)
        {
            if (((unsigned int)(::FUN_00657bc0((std::intptr_t)&(reinterpret_cast<::fnv_00657c20::EGMMorphList *>((void *)&(const ::FaceGenVector< ::FaceGenMorphTarget> &)(m_pGeometryModel->m_pModelData->modes[uiMode]))->GetMorphEntry(i).kVertexPositionLocal)))) < uiNumVertices)
                uiNumVertices = ((unsigned int)(::FUN_00657bc0((std::intptr_t)&(reinterpret_cast<::fnv_00657c20::EGMMorphList *>((void *)&(const ::FaceGenVector< ::FaceGenMorphTarget> &)(m_pGeometryModel->m_pModelData->modes[uiMode]))->GetMorphEntry(i).kVertexPositionLocal))));
        }
    }

    float fWeightCur = 0.0f;
    for (unsigned int uiMode = 0; uiMode < 2; uiMode++)
    {
        uiMorphCountVal = ((unsigned int)(reinterpret_cast<::FUN_00657c00_shell *>((void *)&(m_pGeometryModel->m_pModelData->modes[uiMode]))->GetCount()));
        for (unsigned int i = 0; i < uiMorphCountVal; i++)
        {
            fWeightCur = *apCoordinate[uiMode](i, 0) * reinterpret_cast<::fnv_00657c20::EGMMorphList *>((void *)&(const ::FaceGenVector< ::FaceGenMorphTarget> &)(m_pGeometryModel->m_pModelData->modes[uiMode]))->GetMorphEntry(i).scale;
            if (fWeightCur == 0.0 && !abIncludeZero)
                continue;

            pThePositions = pVerticesCount;
            pExtra = pExtraVerticesTmp;
            FaceGenIterator<ThreeComponentVector<short> > kDelta;
            kDelta = (*(::FaceGenIterator< ::ThreeComponentVector<short>> *)(reinterpret_cast<::_Dummy_0044a170 *>(&(reinterpret_cast<::fnv_00657c20::EGMMorphList *>((void *)&(const ::FaceGenVector< ::FaceGenMorphTarget> &)(m_pGeometryModel->m_pModelData->modes[uiMode]))->GetMorphEntry(i).kVertexPositionLocal))->FUN_0044a170({})));
            unsigned int j;
            for (j = 0; j + 3 < uiNumVertices; j += 4)
            {
                NiPoint3 kP0;
                NiPoint3 kP1New;
                NiPoint3 kP2Tmp;
                NiPoint3 kP3Tmp;
                if (pExtra)
                {
                    kP0 = pExtra[0];
                    kP1New = pExtra[1];
                    kP2Tmp = pExtra[2];
                    kP3Tmp = pExtra[3];
                }
                else
                {
                    reinterpret_cast<::FUN_00534570_shell *>(&(kIteratorNum))->FUN_00534570(j, kP0);
                    reinterpret_cast<::FUN_00534570_shell *>(&(kIteratorNum))->FUN_00534570(j + 1, kP1New);
                    reinterpret_cast<::FUN_00534570_shell *>(&(kIteratorNum))->FUN_00534570(j + 2, kP2Tmp);
                    reinterpret_cast<::FUN_00534570_shell *>(&(kIteratorNum))->FUN_00534570(j + 3, kP3Tmp);
                }
                ThreeComponentVector<short> kD0Tmp = *(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0();
                kDelta++;
                ThreeComponentVector<short> kD1Cur = *(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0();
                kDelta++;
                ThreeComponentVector<short> kD2 = *(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0();
                kDelta++;
                ThreeComponentVector<short> kD3 = *(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0();
                kDelta++;

                kP0.x += kD0Tmp.x * fWeightCur;
                kP0.y += kD0Tmp.y * fWeightCur;
                kP0.z += kD0Tmp.z * fWeightCur;
                kP1New.x += kD1Cur.x * fWeightCur;
                kP1New.y += kD1Cur.y * fWeightCur;
                kP1New.z += kD1Cur.z * fWeightCur;
                kP2Tmp.x += kD2.x * fWeightCur;
                kP2Tmp.y += kD2.y * fWeightCur;
                kP2Tmp.z += kD2.z * fWeightCur;
                kP3Tmp.x += kD3.x * fWeightCur;
                kP3Tmp.y += kD3.y * fWeightCur;
                kP3Tmp.z += kD3.z * fWeightCur;

                reinterpret_cast<::GeometryVertexBuffer *>(&(kIteratorNum))->SetVertex(j, kP0);
                reinterpret_cast<::GeometryVertexBuffer *>(&(kIteratorNum))->SetVertex(j + 1, kP1New);
                reinterpret_cast<::GeometryVertexBuffer *>(&(kIteratorNum))->SetVertex(j + 2, kP2Tmp);
                reinterpret_cast<::GeometryVertexBuffer *>(&(kIteratorNum))->SetVertex(j + 3, kP3Tmp);
                if (pExtra)
                {
                    pExtra[0] = kP0;
                    pExtra[1] = kP1New;
                    pExtra[2] = kP2Tmp;
                    pExtra[3] = kP3Tmp;
                    pExtra += 4;
                }
            }
            for (; j < uiNumVertices; j++, kDelta++)
            {
                NiPoint3 kVertexDelta;
                if (pExtra)
                    kVertexDelta = *pExtra;
                else
                    reinterpret_cast<::FUN_00534570_shell *>(&(kIteratorNum))->FUN_00534570(j, kVertexDelta);
                kVertexDelta.x += (*(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0()).x * fWeightCur;
                kVertexDelta.y += (*(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0()).y * fWeightCur;
                kVertexDelta.z += (*(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0()).z * fWeightCur;
                reinterpret_cast<::GeometryVertexBuffer *>(&(kIteratorNum))->SetVertex(j, kVertexDelta);
                if (pExtra)
                {
                    *pExtra = kVertexDelta;
                    pExtra++;
                }
            }
            if (pExtra)
            {
                std::uintptr_t uiTotal = ((std::uintptr_t)(reinterpret_cast<::FUN_0065b3e0_Holder *>((pLastMorphExtra))->GetPointerByFlag(0)));
                for (unsigned int k = uiNumVertices; k < uiTotal; k++, kDelta++)
                {
                    pExtra->x = (*(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0()).x * fWeightCur + pExtra->x;
                    pExtra->y = (*(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0()).y * fWeightCur + pExtra->y;
                    pExtra->z = (*(::ThreeComponentVector<short> *)reinterpret_cast<::FUN_0064dda0_cls *>(&kDelta)->FUN_0064dda0()).z * fWeightCur + pExtra->z;
                    pExtra++;
                }
            }
        }
    }

    if (((void *)(reinterpret_cast<::FUN_0049ec60 *>((apGeometry))->GetNext())) && ((unsigned int)(reinterpret_cast<::FUN_00457b80_class *>((((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeometry))))))->FUN_00457b80())) != 0x4000)
        ((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeometry))))->SetDirtyFlags(1);
    reinterpret_cast<::FUN_00a673d0_shell *>((((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeometry))))))->FUN_00a673d0();
    ::fnv_00652190::FUN_00652190();
    return true;
}

namespace fnv_0065c630 {
struct Allocator65C630
{
    Allocator65C630();
    Allocator65C630(const Allocator65C630& kOther);
    int unk00;
};
struct Base65C630
{
    Base65C630(Allocator65C630 kAllocator);
    ~Base65C630();
    int unk00;
};
struct FUN_0065c630 : public Base65C630
{
    FUN_0065c630();
};

// Default constructor that initializes the base with a default allocator and calls Init with zero.
// @fnv 0x0065c630
FUN_0065c630::FUN_0065c630() : Base65C630(Allocator65C630())
{
    reinterpret_cast<::FUN_0065cfd0_cls *>(this)->ReserveItems(0);
}
}  // namespace fnv_0065c630

namespace fnv_00659c40 {
struct FUN_00659a20
{
    ~FUN_00659a20();
};
struct FUN_00659c40_shell : FUN_00659a20
{
    void* FUN_00659c40(unsigned int flags);
};
// Deletes the object, then calls _Deallocate on it if the low bit of flags is set, and returns the original this pointer.
// @fnv 0x00659c40
void* FUN_00659c40_shell::FUN_00659c40(unsigned int flags)
{
    delete this;
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00659c40

extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);

void __cdecl FUN_00ec7c56();

namespace std {
class exception_ob1
{
  public:
    exception_ob1();
    exception_ob1(const char* const& pcWhat);
    virtual ~exception_ob1();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
class bad_alloc_ob1 : public exception_ob1
{
  public:
    bad_alloc_ob1(const char* pcMessage = "bad allocation") throw() : exception_ob1(pcMessage)
    {}
    virtual ~bad_alloc_ob1() throw()
    {}
};
}

struct SecureCharTag
{
};

struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};

struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};

inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc_ob1(0);
    return (char*)::FUN_00401000(ItemUpdateArray * sizeof(char));
}

struct CharAllocator
{
    CharAllocator()
    {}
    CharAllocator(const CharAllocator&)
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::FUN_00401030(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};

struct StringBase
{
    static void _Xlen();
    static void _Xran();
};

struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};

struct String : public StringVal
{
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal(kRight.m_kAlval)
    {
        _Tidy();
        assign(kRight, 0, ::g_010173f0);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& operator+=(const String& kRight)
    {
        return append(kRight);
    }
    String& operator+=(const char* pcPtr)
    {
        return append(pcPtr);
    }
    String& append(const String& kRight)
    {
        return append(kRight, 0, ::g_010173f0);
    }
    String& append(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (uiElementCount < ItemUpdateArray)
            ItemUpdateArray = uiElementCount;
        if (::g_010173f0 - m_uiSize <= ItemUpdateArray || m_uiSize + ItemUpdateArray < m_uiSize)
            _Xlen();
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, kRight._Myptr() + uiRoff, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return append(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (::g_010173f0 - m_uiSize <= ItemUpdateArray)
            _Xlen();
        unsigned int uiElementCount;
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, pcPtr, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr)
    {
        return append(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = ::g_010173f0)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign((16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf)[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};

inline String operator+(const String& kLeft, const char* pcRight)
{
    return String(kLeft) += pcRight;
}

inline String operator+(const String& kLeft, const String& kRight)
{
    return String(kLeft) += kRight;
}

namespace std {
class logic_error : public exception_ob1
{
  public:
    explicit logic_error(const String& _Message) : _Str(_Message)
    {}
    virtual ~logic_error();

  private:
    String _Str;
};
class length_error : public logic_error
{
  public:
    explicit length_error(const String& _Message) : logic_error(_Message)
    {
        unsigned int u1;
        unsigned int u2;
        unsigned int u3;
    }
    virtual ~length_error()
    {}
};
}

// @fnv 0x00ac0b00
void __cdecl FUN_00ac0b00()
{
    throw std::length_error("vector<T> too long");
}

namespace xlenb0f {
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)::FUN_00401000(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ::FUN_00401030(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

struct BxVecBase
{
    static void FUN_00b0fb80();
};
}
using namespace xlenb0f;

// @fnv 0x00b0fb80
void BxVecBase::FUN_00b0fb80()
{
    throw BxLengthError("vector<T> too long");
}

#include "generated/data/fallout_shared/facegen/bsfacegenmodel.inc"
