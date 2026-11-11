// gamebryo2.2/corelibs/nimain/niavobject_types.h: declares NiPoint3, NiBound, FourComponentFloatVector, NiRefObject, NiObject and more
#ifndef FNV_NIAVOBJECT_TYPES_H
#define FNV_NIAVOBJECT_TYPES_H

// JohnnyGuitarNVSE PC reverse-engineering headers. No dependency definitions.
#include <stddef.h>
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/decl/FUN_004f0000_shell.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_004a8000.h"
struct NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
struct CloningProcess;
struct NiStream;
class NiObjectGroup;
struct NiControllerManager;
class NiTimeController;
class NiExtraData;
class NiCollisionObject;
struct NiUpdateData;
class FourComponentFloatVector;
template <class T> class NiTPrimitiveArray;
typedef NiTPrimitiveArray<char*> NiViewerStringsArray;
struct NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
struct NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};
// FourComponentFloatVector, but these two parameter types are inferred from the PC call site.
class FourComponentFloatVector : public NiBound
{
  public:
    FourComponentFloatVector(unsigned int, unsigned int);
};
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
struct NiObject : public NiRefObject
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsSceneNode() const;
    virtual BSFadeNode* IsFadeNode() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiGeometry* IsGeometry() const;
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual NiTriStrips* IsTriStrips() const;
    virtual NiTriShape* IsTriShape() const;
    virtual BSSegmentedTriShape* IsSegmentedTriShape() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiParticles* IsParticlesGeom() const;
    virtual NiLines* IsLineGeometry() const;
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject() const;
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject() const;
    virtual bhkRigidBody* IsBhkRigidBody() const;
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint() const;
    virtual NiObject* MakeClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual void RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void AddViewerStrings(NiViewerStringsArray*);
    virtual void ProcessClone(CloningProcess&);
    virtual void PostLinkObject(NiStream&);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual void SetObjectBound(FourComponentFloatVector*);
    virtual void GetBlockAllocationSize();
    virtual NiObjectGroup* GetGroup();
    virtual void SetGroup(NiObjectGroup*);
    virtual NiControllerManager* IsControllerManager() const;
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
};
#include "fnv/native_fixed_string.h"
struct NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;
    NiPointer<NiTimeController> m_pControllers;
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount;
    unsigned short m_usMaxSize;
};
class NiTimeController : public NiObject
{
  public:
    virtual void Start(float);
    virtual void Stop();
    virtual void Update(NiUpdateData&);
};
class NiProperty : public NiObjectNET
{
  public:
    enum Type
    {
        ALPHA,
        CULLING,
        MATERIAL,
        SHADE,
        STENCIL,
        TEXTURING,
        WIREFRAME,
        COUNT
    };
    virtual Type GetType() const;
    virtual void Update(NiUpdateData&);
};
typedef void* NiTListIterator;
template <class T> class NiTListItem;
template <class T> class NiTPointerAllocator
{
};
template <class Allocator, class T> class NiTListBase
{
  public:
    struct MapEntryCount : Allocator
    {
        unsigned int m_uiCount;
    };
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    MapEntryCount m_kItemCount;
    NiTListIterator GetHeadPos() const;
};
template <class Allocator, class T> class NiTPointerListBase : public NiTListBase<Allocator, T>
{
  public:
    T& GetNext(NiTListIterator&);
};
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
};
struct ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTPointerList<NiPointer<NiProperty> > SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
    void UpdateTimeControllers(NiUpdateData&, bool);
    void EnsureWorldBound();
};
#endif
