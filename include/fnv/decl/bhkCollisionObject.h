#pragma once

class NiAVObject;
class hkpRigidBody;

class bhkCollisionObject {
public:
    // 0x0043b610
    static ::bhkCollisionObject *GetFromNiAVObject(::NiAVObject *);
    // 0x004b5a20
    static ::bhkCollisionObject *GetFromRigidBody(const ::hkpRigidBody *);
};
