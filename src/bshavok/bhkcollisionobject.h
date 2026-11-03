// bshavok/bhkcollisionobject.h: declares bhkNiCollisionObject, bhkCollisionObject
#ifndef BHKCOLLISIONOBJECT_H
#define BHKCOLLISIONOBJECT_H


#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_01204000.h"
#include "layout_support.h"
#include "bhkcollisionobject_decls.h"

class NiRTTI;
class NiObject;
class NiAVObject;
class hkpRigidBody;

class bhkNiCollisionObject
{
  public:
    virtual ~bhkNiCollisionObject();
};

class bhkCollisionObject : public bhkNiCollisionObject
{
  public:
    virtual ~bhkCollisionObject();
    virtual const NiRTTI* GetRTTI() const;


    static bhkCollisionObject* GetFromNiAVObject(NiAVObject* object);
    static bhkCollisionObject* GetFromRigidBody(const hkpRigidBody* body);
};

// @fnv 0x0056d5b0
const NiRTTI* bhkCollisionObject::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_012043f8));
}

// @fnv 0x0043b610
bhkCollisionObject* bhkCollisionObject::GetFromNiAVObject(NiAVObject* object)
{
    const char* collision = ((const char *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((reinterpret_cast<BGSBodyPart*>(object)))->FUN_006838b0()));
    return reinterpret_cast<bhkCollisionObject*>(
        ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(const_cast<NiRTTI*>(&(*reinterpret_cast<const ::NiRTTI *>(&::g_012043f8)))), (::NiObject *)(::NiNode *)(reinterpret_cast<NiNode*>(const_cast<char*>(collision)))))));
}

// @fnv 0x004b5a20
bhkCollisionObject* bhkCollisionObject::GetFromRigidBody(const hkpRigidBody* body)
{
    NiAVObject* collision = NiShader::DynamicCast(reinterpret_cast<NiAVObject*>(const_cast<hkpRigidBody*>(body)));
    return reinterpret_cast<bhkCollisionObject*>(
        ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(const_cast<NiRTTI*>(&(*reinterpret_cast<const ::NiRTTI *>(&::g_012043f8)))), (::NiObject *)(::NiNode *)(reinterpret_cast<NiNode*>(collision))))));
}

#endif
