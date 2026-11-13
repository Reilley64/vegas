#pragma once

// NiObject, Gamebryo's streamable base class.
//
// The class adds no field to NiRefObject. Its table is the one the
// constructor row 0x00a5d3a0 stores, generated as ?DAT_0109b4f4@@3HA: 35
// slots. Slots 0 and 1 are NiRefObject's. The 33 virtual functions below
// fill slots 2 to 34 in this order. Every one of them is OPEN: no unit of
// the recipe defines a function under NiObject's name in these slots, so
// their names and parameters are the spelling the moved units already used,
// not a finding. Nothing may be concluded from them, and no body may be
// given one of these names on the strength of this header. Their indices
// are fixed by the table.
//
// The constructor and destructor are declared, with no body: the
// constructor row 0x00a5d3a0 and the deleting destructor in slot 0,
// 0x00a5d4e0, keep their stand-in names. Other members with a function row
// under NiObject's name are declared here when their owner defines them on
// this header; none does yet.

#include "fnv/ni_ref_object.h"

struct NiRTTI;
class NiNode;
struct BSFadeNode;
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
struct NiBound;
struct NiControllerManager;
template <class T> class NiTPrimitiveArray;

struct NiObject : public NiRefObject
{
  public:
    NiObject();
    virtual ~NiObject();
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
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual void AddViewerStrings(NiTPrimitiveArray<char*>* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void PostLinkObject(NiStream& stream);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual void SetObjectBound(NiBound* bound);
    virtual void GetBlockAllocationSize();
    virtual NiObjectGroup* GetGroup();
    virtual void SetGroup(NiObjectGroup* group);
    virtual NiControllerManager* IsControllerManager() const;
};
