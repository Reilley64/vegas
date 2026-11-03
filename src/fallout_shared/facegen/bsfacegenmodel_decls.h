// fallout_shared/facegen/bsfacegenmodel_decls.h: declares NiPoint3, AutoMemContext, FaceGenMorphTarget, FaceGenMorphData, FaceGenCoordinate and more
#ifndef BSFACEGENMODEL_DECLS_H
#define BSFACEGENMODEL_DECLS_H

#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_00457b80_class.h"
#include "fnv/decl/FUN_00457ba0_class.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_00534570_shell.h"
#include "fnv/decl/FUN_0065b3e0_Holder.h"
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
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00607000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0065c000.h"
#include "fnv/symbols_00ab5000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
enum MEM_CONTEXT
{
    FaceGenMeshContext = 56,
    FaceGenTextureContext = 57
};
class AutoMemContext
{
  public:
    MEM_CONTEXT oldContext;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
enum HAIR_PART
{
    HAIR_PART_NONE = -1,
    HAIR_PART_NORMAL = 0,
    HAIR_PART_HAT = 1
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short size, capacity;
    const T* String();
    unsigned int Length();
    bool Set(const T*, unsigned int);
};
template <class T> class FaceGenIterator
{
  public:
    T* current;
    void* container;
    T& operator*() const;
    FaceGenIterator operator++(int);
};
template <class T> class FaceGenVector
{
  public:
    void* proxy;
    T* first;
    T* last;
    T* end;
    unsigned int allocator;
    unsigned int state;
    unsigned int size() const;
    T& operator[](unsigned int);
    FaceGenIterator<T> begin();
};
template <class T> class ThreeComponentVector
{
  public:
    T x, y, z;
};
class FaceGenMorphTarget
{
  public:
    float scale;
    FaceGenVector<ThreeComponentVector<short> > kVertexPositionLocal;
};
class FaceGenMorphData
{
  public:
    unsigned int state;
    FaceGenVector<FaceGenMorphTarget> modes[2];
    FaceGenMorphData(const char*);
};
class FaceGenCoordinate
{
  public:
    unsigned int data[8];
    FaceGenIterator<float> operator()(unsigned int, int);
};
class GeometryBufferView
{
  public:
    void* data;
    unsigned int stride;
    unsigned int count;
    GeometryBufferView();
};
class NiGeometryData
{
  public:
    void SetDirtyFlags(unsigned int);
public:
    bool IsGeometryDataStreamable(bool);
};
class NiTriBasedGeom;
class NiFixedString
{
  public:
    const char* data;
    operator const char*() const;
public:
    void *FUN_004b9900(unsigned int);
};
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    bool updateControllers;
    NiUpdateData(float, bool, bool);
};
class TESQuest;
class TESQuest;
class BGSQuestObjective
{
  public:
public:
    void SetOwner(::TESQuest *);
};
class NiSkinInstance;
class NiAVObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual NiAVObject* vfn_94();
};
class NiAVObject;
class NiNode : public NiAVObject
{
  public:
    unsigned int FUN_0043b480();
public:
    ::NiAVObject *GetAt(unsigned int);
};
class NiTriBasedGeom : public NiAVObject
{
  public:
};
class BSFaceGenBaseMorphExtraData
{
  public:
};
template <class T> class NiPointer
{
  public:
    T* pointer;
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
class BSFaceGenMorphData
{
  public:
    void* vtable;
    unsigned int refCount;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class FaceGenTriData
{
  public:
    unsigned int data[60];
    FaceGenTriData();
    ~FaceGenTriData();
    unsigned int FUN_0065a5a0();
    NiPoint3& FUN_0065c720(unsigned int);
};
class BSFaceGenMorphDataHair : public BSFaceGenMorphData
{
  public:
    void* hairMorph;
    BSFaceGenMorphDataHair(FaceGenTriData*);
};
class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
  public:
    void* expression;
    void* modifier;
    void* phoneme;
    void* custom;
    BSFaceGenMorphDataHead(FaceGenTriData*);
};
class FaceGenGeometryModel
{
  public:
    BSStringT<char> m_kEGMFileName;
    FaceGenMorphData* m_pModelData;
    NiPointer<NiNode> m_spModelRoot;
    NiPointer<NiTriBasedGeom> m_pRenderedNodeEntry;
    NiPoint3* pAdditionalVertices;
    unsigned int m_uiAdditionalVertexCount;
    NiPointer<BSFaceGenMorphData> m_spFaceMorphData;
    int BackgroundTask;
    FaceGenGeometryModel();
};
struct FaceGenTextureFile;
class BSFaceGenTexture
{
  public:
    BSStringT<char> EGTFileName;
    FaceGenTextureFile* m_pTextureData;
    BSFaceGenTexture();
};
class NiTriBasedGeom;
template <class> class NiPointer;
class BSFaceGenModel
{
  public:
    void* vtable;
    unsigned int refCount;
    FaceGenGeometryModel* m_pGeometryModel;
    BSFaceGenTexture* m_kTextureSlots;
    bool LoadModelMesh(const char*, const char*, const char*, HAIR_PART, bool);
    bool LoadFaceGenTexture();
    bool LoadFaceGenTexture(const char*);
    static NiAVObject* GetFaceGenModelNode(NiAVObject*);
public:
    bool CloneTriBasedGeom(::NiPointer< ::NiTriBasedGeom> &);
};
class BSFaceGenManager
{
  public:
    static FaceGenCoordinate* GetFaceGenCoordinates();
};
class CloningProcess
{
  public:
    unsigned int state[7];
    CloningProcess(float);
    ~CloningProcess();
};
class ModelLoader
{
  public:
};
class TES
{
  public:
};
class NarrowString
{
  public:
    unsigned int text[7];
    NarrowString(const char*);
    ~NarrowString();
};
int FUN_004af340();
FaceGenTextureFile* FUN_00659780(const char*);
#endif
