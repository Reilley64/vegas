#pragma once

class NiAVObject;
struct hkpRigidBody;

struct bhkCollisionObject {
public:
    // 0x0043b610
    static ::bhkCollisionObject *GetFromNiAVObject(::NiAVObject *);
    // 0x004b5a20
    static ::bhkCollisionObject *GetFromRigidBody(const ::hkpRigidBody *);
};
