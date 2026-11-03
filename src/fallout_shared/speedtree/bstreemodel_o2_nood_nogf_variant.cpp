
// src/fallout_shared/speedtree/bstreemodel_o2_nood_nogf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/speedtree/bstreemodel.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/fallout_shared/speedtree/bstreemodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreemodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstdint>
#include <new>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_004410d0_Class.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_0051d250_Class.h"
#include "fnv/decl/FUN_00633c90.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00874460_cls.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/FUN_00a59c90_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00b08750_class.h"
#include "fnv/decl/FUN_00b66ad0_cls.h"
#include "fnv/decl/FUN_00baa000_shell.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/ListOwnerRefB087.h"
#include "fnv/decl/MLx.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/Owner226.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/ShaderOwner.h"
#include "fnv/decl/SpeedTreeRelease.h"
#include "fnv/decl/Tree66C.h"
#include "fnv/decl/fnv_00668500__TreeLeafModel.h"
#include "fnv/decl/fnv_00669500__TreeModelX.h"
#include "fnv/decl/fnv_00669990__BSTreeModel.h"
#include "fnv/decl/fnv_00b0ab20__SpeedTreeImpl.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_00669000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00c81000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f4000.h"
struct BSTreeModel
{
    virtual ~BSTreeModel();
    void* DestroyAndFree(unsigned int flags);
};
struct FUN_00666f00_shell
{
    int m_04;
    int m_08;
    bool FUN_00666f00();
};
struct GlobalObject_0044f440
{
    struct
    {
        float f;
    }* Float();
};
extern GlobalObject_0044f440 g_011d5d14;
float FUN_00666f20();
struct FUN_006684d0_shell
{
    void FUN_006684d0(int param1, unsigned short param2);
};
struct FUN_006694c0_shell
{
    float fPad0;
    float fPad1;
    float fPad2;
    float fPad3;
    float fPad4;
    float fPad5;
    void SetPad5(float value);
};
struct CSpeedTreeRT
{
public:
    unsigned short FUN_00b08710();
};
struct FUN_006699d0_shell
{
    void* m_NiRefObject;
    void* m_auiShapeKeys;
    void* m_pAuxiliaryObject;
    CSpeedTreeRT* m_pTreeRuntime;
    unsigned short GetUnsignedShort();
};
extern "C" unsigned char __cdecl GetByteAtOffset1B();
unsigned char __cdecl GetByteAtOffset1B();
struct Flt
{
    operator unsigned int() const;
};
struct FUN_0066a630_shell
{
    char m_auiShapeKeys[0x38];
    Flt m_flt;
    void ConvertFloatToUInt();
};
GlobalObject_0044f440 g_011d5c80;
float FUN_00666fa0();
struct S_00666910
{
    void* FUN_00666910(unsigned int);
};
struct NiAlphaProperty
{
    char m_auiShapeKeys[0x1c];
    NiAlphaProperty();
    ~NiAlphaProperty();
};
struct RefBase
{
    virtual ~RefBase();
    unsigned int m_uiRefCount;
};
struct NiPtr
{
    void* m_pObject;
    ~NiPtr();
};
struct TreeData
{
    ~TreeData();
};
struct FUN_00666800 : RefBase
{
    int unk08;
    TreeData* pData;
    NiPtr spNode10;
    int unk14;
    int unk18;
    NiPtr spNode1C;
    NiPtr spNode20;
    int unk24;
    int unk28;
    NiPtr spNode2C;
    NiPtr spNode30;
    NiPtr spNode34;
    NiPtr spNode38;
    virtual ~FUN_00666800();
};
struct Point3X
{
    float x, y, z;
    Point3X();
    Point3X(float afX, float afY, float afZ);
};
struct Point2X
{
    float x, y;
    Point2X();
    Point2X(float afX, float afY);
};
struct ColorAX
{
    float r, g, b, a;
    ColorAX();
    ColorAX(float afR, float afG, float afB, float afA);
};
struct MemObjX
{
};
struct LeafDataX : public MemObjX
{
    char _pad[0x10];
    LeafDataX();
};
struct StripsDataX : public MemObjX
{
    char _pad[0x50];
    StripsDataX(unsigned int a1, Point3X* a2, Point3X* a3, unsigned int a4, Point2X* a5, unsigned int a6,
                unsigned int a7, unsigned int a8, unsigned int a9, unsigned short* a10, unsigned short* a11);
    void FUN_00a67050(unsigned int auiFlags);
};
struct LeafShapeX : public MemObjX
{
    char _pad[0x108];
    LeafShapeX(LeafDataX* apData);
};
template <class T> struct PtrX
{
    T* m_pObject;
    PtrX();
    PtrX(T* apObject);
    ~PtrX();
    PtrX& operator=(T* apObject);
    operator T*() const;
};
struct GeometryX
{
    int _pad00[2];
    unsigned short* pStripCount;
    unsigned short** ppStrips;
    unsigned short usVertexCount;
    unsigned short _pad12;
    unsigned int* pColors;
    float* pNormals;
    float* pBinormals;
    float* pTangents;
    float* pCoords;
    float* pTexCoords;
    int _pad2c;
    float* pLodFade;
    unsigned char* pWindIndices;
    int _pad38[(0x130 - 0x38) / 4];
    GeometryX();
    ~GeometryX();
};
struct SpeedTreeX
{
};
struct UIntArrayX
{
    void* pBase;
    unsigned short usMax;
    unsigned short usSize;
    unsigned short usESize;
    unsigned short usGrow;
    int iActionIndex;
    UIntArrayX(unsigned int auiMax, unsigned int auiGrow);
    ~UIntArrayX();
    unsigned int* GetAt(unsigned int auiIndex);
};
extern "C" int xIsNaN(double adValue);
struct TreeModelX
{
    char _pad00[0xc];
    SpeedTreeX* m_pTreeRuntime;
    char _pad10[4];
    PtrX<StripsDataX>* pLeafGeometry;
    char _pad18[0xc];
    PtrX<LeafShapeX>* pLeafShapes;

    void FUN_00667470();
};
struct ModelHolder_b5531
{
    void FUN_006694e0();
};
struct GlobalObject_0044fae0
{
    void FUN_004538a0(int);
};
extern GlobalObject_0044fae0 g_011d5df8;
struct AutoMemContext
{
    int previous;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
struct TreeCloneProcess
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    TreeCloneProcess(float);
    ~TreeCloneProcess();
};
struct NiNode
{
};
template <class T> struct NiPointer
{
    T* object;
    NiPointer();
    ~NiPointer();
    NiPointer& operator=(const NiPointer&);
    NiPointer& operator=(T*);
    operator T*();
};
struct TreeRuntimeCopy
{
    TreeRuntimeCopy* FUN_00b05210();
};
struct TreeCloneView
{
    unsigned int unk00, unk04;
    int initialized;
    TreeRuntimeCopy* runtime;
    NiPointer<TreeCloneView> source;
    NiPointer<NiNode>* branchGeometry;
    NiPointer<NiNode>* leafGeometry;
    NiPointer<NiNode> billboard;
    NiPointer<NiNode> unk20;
    NiPointer<NiNode>* branchNodes;
    NiPointer<NiNode>* leafNodes;
    NiPointer<NiNode> unk2c, unk30, unk34;
    NiPointer<NiNode> collision;
    float unk3c;
    unsigned int unk40, unk44;
    float unk48, unk4c;
    bool CloneFromModel(TreeCloneView*);
};
struct PathingSolutionBase
{
    virtual ~PathingSolutionBase();
    unsigned int refs;
    PathingSolutionBase();
};
struct GlobalObject_00633c90
{
    void* p;
    GlobalObject_00633c90(int);
    ~GlobalObject_00633c90();
    GlobalObject_00633c90& operator=(void*);
};
struct FUN_00666650 : PathingSolutionBase
{
    unsigned int unk08, unk0c;
    GlobalObject_00633c90 a;
    unsigned int unk14, unk18;
    GlobalObject_00633c90 b, c;
    unsigned int unk24, unk28;
    GlobalObject_00633c90 d, e, f, g;
    float unk3c;
    unsigned int unk40;
    bool unk44;
    float unk48, unk4c;
    FUN_00666650();
    virtual ~FUN_00666650();
};
int strcpy_s(char* apDst, unsigned int auiSize, const char* apSrc);
int strcat_s(char* apDst, unsigned int auiSize, const char* apSrc);
template <class T> unsigned int BSStringLength(const T* apString);
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_NOT_FOUND
    };
    static FILE_LOCATION Exist(const char* apPath, char* apOut, unsigned int auiArg, unsigned int auiArgCur);
};
struct NiRTTI;
class NiAVObject;
struct bhkWorldObject;
struct bhkCollisionObject
{
};
class NiStream
{
  public:
    int m_kNextStreamField[0x5cc / 4];
    virtual ~NiStream();
};
class BSStream : public NiStream
{
  public:
    BSStream();
    virtual ~BSStream();
};
class TESModel
{
  public:
    virtual ~TESModel();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual const char* GetModelFileName();
};
class TESObjectTREE
{
  public:
    char pad[0x30];
    TESModel kModel;
};
NiNode* __cdecl FUN_00c81380(float afArg, float afArgCur);
struct ModelName
{
    char acName[0x104];
};
struct FUN_00667190_shell : public TreeCloneView
{
    void LoadTreeCollision(TESObjectTREE* apTree);
};
namespace TreeBuild {
struct Model;
struct Geometry;
struct GeometryData;
struct Object;
struct Property;
struct Shader;
template <class T> struct Handle
{
    T* object;
    Handle(T*);
    ~Handle();
    T* FUN_00559450();
    void FUN_0066b0d0(T*);
};
struct Scope
{
    int value;
    Scope(int, int, const char*, int);
    ~Scope();
};
extern const char DAT_010667b8[], DAT_01066830[];
struct UpdateData
{
    float time;
    int flags, unk08;
    UpdateData(float, int, int);
};
struct ShaderState
{
};
struct Property
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
    virtual Shader* CreateShader(Geometry*);
};
struct Geometry
{
    virtual void v0();
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
    Geometry(GeometryData*);
};
struct Leaves : Geometry
{
    Leaves(GeometryData*);
};
struct Renderer
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
    virtual void Prepare(Geometry*, int, int, int);
};
struct Tree
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
    virtual void* GetBranches();
    virtual void v66();
    virtual void* GetLeaves();
    virtual Geometry* GetBranch(unsigned int);
    virtual void v69();
    virtual void v70();
    virtual void SetBranch(unsigned int, Geometry*);
    virtual void SetLeaf(unsigned int, Geometry*);
    virtual void SetBillboardObject(Object*);
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
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    Tree(Model*, Object*);
};
struct Model
{
    int unk00, unk04, unk08;
    void* model;
    int unk10;
    Handle<GeometryData>* branches;
    Handle<GeometryData>* leaves;
    Handle<Object> billboard;
    int unk20;
    Handle<Property>* branchProperties;
    Handle<Property>* leafProperties;
    Handle<Object> extra;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    float radius, height;
    Object* ConvertFloatToUInt();
    Tree* CreateTree(float);
};
// @fnv 0x00669fd0
Tree* Model::CreateTree(float scale)
{
    Scope scope(30, 1, DAT_010667b8, 901);
    Tree* tree5 = 0;
    void* unusedB = 0;
    Handle<Object> shape(0);
    if (!model)
        return 0;
    if (radius > ::DAT_010240c0)
    {
        if (scale == ::g_01012070)
            shape.FUN_0066b0d0(ConvertFloatToUInt());
        else
            shape.FUN_0066b0d0(((::TreeBuild::Object *)(::FUN_00c81380(scale * radius, scale * height / ::DAT_01011590))));
    }
    else
        shape.FUN_0066b0d0(0);
    tree5 = new Tree(this, ((::TreeBuild::Object *)(::FUN_00559450((int *)&(shape)))));
    unsigned short count3;
    unsigned short i;
    void* shader;
    Geometry* geometryX;
    Property* alpha;
    if (branches && branchProperties)
    {
        count3 = reinterpret_cast<::fnv_00669990::BSTreeModel *>(this)->FUN_00669990();
        shader = ((void *)(::FUN_00b55560(4)));
        unusedB = tree5->GetBranches();
        for (i = 0; i < count3; i++)
        {
            if (!((::TreeBuild::GeometryData *)(::FUN_00559450((int *)&(branches[i])))))
                continue;
            geometryX = new Geometry(((::TreeBuild::GeometryData *)(::FUN_00559450((int *)&(branches[i])))));
            alpha = ((::TreeBuild::Property *)(::FUN_006698f0()));
            if (alpha)
            {
                reinterpret_cast<::Flag512Receiver *>((alpha))->SetFlag512(0);
                reinterpret_cast<::FUN_00439410_cls *>((geometryX))->FUN_00439410((::ArgObject *)(alpha));
            }
            if (((::TreeBuild::Property *)(::FUN_00559450((int *)&(branchProperties[i])))))
            {
                reinterpret_cast<::FUN_00baa000_shell *>((((::TreeBuild::Property *)(::FUN_00559450((int *)&(branchProperties[i]))))))->FUN_00baa000();
                reinterpret_cast<::FUN_00439410_cls *>((geometryX))->FUN_00439410((::ArgObject *)(::TreeBuild::Property *)(((::TreeBuild::Property *)(::FUN_00559450((int *)&(branchProperties[i]))))));
                if (!((int)(::fnv_004a8a90::FUN_004a8a90((char *)(((::TreeBuild::ShaderState *)(::fnv_005495f0::FUN_005495f0((const char *)(geometryX)))))))))
                {
                    Shader* created = ((::TreeBuild::Property *)(::FUN_00559450((int *)&(branchProperties[i]))))->CreateShader(geometryX);
                    reinterpret_cast<::ShaderOwner *>((geometryX))->FUN_00539ef0((::NiGPUProgram *)(created));
                }
            }
            if (reinterpret_cast<::FUN_00666f00_shell *>(this)->FUN_00666f00())
                reinterpret_cast<::FUN_00874460_cls *>((geometryX))->set((int)(shader));
            tree5->SetBranch(i, geometryX);
        }
        if (!reinterpret_cast<::FUN_00666f00_shell *>(this)->FUN_00666f00())
        {
            for (i = 0; i < count3; i++)
            {
                geometryX = tree5->GetBranch(i);
                if (!geometryX)
                    continue;
                reinterpret_cast<::FUN_00b66ad0_cls *>((((::TreeBuild::Property *)(::FUN_00559450((int *)&(branchProperties[i]))))))->FUN_00b66ad0((std::intptr_t)(DAT_01066830), (::FnvTarget *)(::TreeBuild::Object *)(((::TreeBuild::Object *)(::FUN_00559450((int *)&(extra))))));
                ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(geometryX), 0, 0);
                reinterpret_cast<::ShaderOwner *>((geometryX))->FUN_00539ef0((::NiGPUProgram *)(::TreeBuild::Shader *)(((::TreeBuild::Property *)(::FUN_00559450((int *)&(branchProperties[i]))))->CreateShader(geometryX)));
                if (!((int)(reinterpret_cast<::BGSCameraPath *>((((::TreeBuild::ShaderState *)(::fnv_005495f0::FUN_005495f0((const char *)(geometryX))))))->GetPrevPath())))
                    ((::TreeBuild::Renderer *)(::FUN_0043c4b0()))->Prepare(geometryX, 0, 0, 0);
            }
        }
    }
    if (leaves && leafProperties)
    {
        count3 = reinterpret_cast<::FUN_006699d0_shell *>(this)->GetUnsignedShort();
        shader = ((void *)(::FUN_00b55560(6)));
        for (i = 0; i < count3; i++)
        {
            if (!((::TreeBuild::GeometryData *)(::FUN_00559450((int *)&(leaves[i])))))
                continue;
            geometryX = new Leaves(((::TreeBuild::GeometryData *)(::FUN_00559450((int *)&(leaves[i])))));
            alpha = ((::TreeBuild::Property *)(::FUN_006698f0()));
            if (alpha)
                reinterpret_cast<::FUN_00439410_cls *>((geometryX))->FUN_00439410((::ArgObject *)(alpha));
            if (((::TreeBuild::Property *)(::FUN_00559450((int *)&(leafProperties[i])))))
            {
                reinterpret_cast<::FUN_00baa000_shell *>((((::TreeBuild::Property *)(::FUN_00559450((int *)&(leafProperties[i]))))))->FUN_00baa000();
                reinterpret_cast<::FUN_00439410_cls *>((geometryX))->FUN_00439410((::ArgObject *)(::TreeBuild::Property *)(((::TreeBuild::Property *)(::FUN_00559450((int *)&(leafProperties[i]))))));
            }
            tree5->SetLeaf(i, geometryX);
            reinterpret_cast<::FUN_00874460_cls *>((geometryX))->set((int)(shader));
            ((::TreeBuild::Renderer *)(::FUN_0043c4b0()))->Prepare(geometryX, 0, 0, 0);
        }
    }
    unusedB = tree5->GetLeaves();
    if (((::TreeBuild::Object *)(::FUN_00559450((int *)&(billboard)))))
        tree5->SetBillboardObject(((::TreeBuild::Object *)(::FUN_00559450((int *)&(billboard)))));
    reinterpret_cast<::FUN_00a5a040_Class *>((tree5))->FUN_00a5a040();
    UpdateData update(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c90_shell *>((tree5))->FUN_00a59c90((*(::NiUpdateData *)(&update)));
    reinterpret_cast<::Tree66C *>((tree5))->FUN_0066cb40((::Bounds66C *)(model), scale);
    return tree5;
}
}

#include <xmmintrin.h>
struct hkVector4C813
{
    __m128 m_vComponents;
};
struct __declspec(align(16)) CapsuleParams
{
    int flags;
    float radius;
    int unk08, unk0c;
    hkVector4C813 endpoints[2];
};
struct FUN_0066d6a0 : MemObjX
{
    int unk00, unk04;
    void* shape;
    int unk0c, material;
    FUN_0066d6a0(CapsuleParams*);
};
struct AllocatorC813
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, int);
};
struct MemoryC813
{
    int unk00, unk04, unk08, unk0c;
    AllocatorC813* allocator;
    AllocatorC813& heap()
    {
        return *allocator;
    }
};
MemoryC813* FUN_00c85750();
struct __declspec(align(16)) FUN_00c8f510
{
    int filter00;
    void* shape04;
    int unk08;
    void* data;
    int size;
    int capacity;
    int unk18;
    int unk1c;
    int filter20;
    void* shape24;
    int unk28;
    int unk2c;
    hkVector4C813 position;
    hkVector4C813 rotation;
    hkVector4C813 linearVelocity;
    hkVector4C813 angularVelocity;
    hkVector4C813 inertiaTensor[3];
    hkVector4C813 centerOfMass;
    float valueb0;
    int unkb4;
    int unkb8;
    int unkbc;
    float valuec0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    unsigned char motion, unkD5, unkD6, unkD7;
    int unkd8;
    int unkdc;
    FUN_00c8f510();
    void ClearAndRelease(AllocatorC813& alloc)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            alloc.Free(data, (capacity & 0x3fffffff) * 8);
    }
    ~FUN_00c8f510()
    {
        ClearAndRelease(FUN_00c85750()->heap());
    }
};
struct FUN_0056d380 : MemObjX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_0056d380(FUN_00c8f510*);
};
extern float DAT_01267e44;
// @fnv 0x00c81380
NiNode* __cdecl FUN_00c81380(float a, float b)
{
    CapsuleParams params;
    params.endpoints[0].m_vComponents.m128_f32[3] = 0.0f;
    params.endpoints[1].m_vComponents.m128_f32[3] = 0.0f;
    params.flags = 0;
    if (a <= b * 2.0f)
        a = (float)(b * 2.0f + 1.0);
    params.radius = DAT_01267e44 * b;
    params.endpoints[0].m_vComponents.m128_f32[0] = 0.0f;
    params.endpoints[0].m_vComponents.m128_f32[1] = 0.0f;
    float delta = a - b;
    params.endpoints[0].m_vComponents.m128_f32[2] = delta * DAT_01267e44;
    params.endpoints[1].m_vComponents.m128_f32[0] = 0.0f;
    params.endpoints[1].m_vComponents.m128_f32[1] = 0.0f;
    params.endpoints[1].m_vComponents.m128_f32[2] = params.radius;
    NiNode* result = 0;
    FUN_0066d6a0* desc = new FUN_0066d6a0(&params);
    if (desc)
    {
        desc->material = 9;
        FUN_00c8f510 block;
        void* shape = desc->shape;
        block.valueb0 = 0.0f;
        block.valuec0 = DAT_01018180;
        block.motion = 5;
        block.filter00 = 0x40009;
        block.filter20 = 0x40009;
        block.shape04 = shape;
        block.shape24 = shape;
        FUN_0056d380* obj = new FUN_0056d380(&block);
        result = (NiNode*)obj;
    }
    return result;
}

#include "generated/data/fallout_shared/speedtree/bstreemodel_o2_nood_nogf_variant.inc"
