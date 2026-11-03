#pragma once

class NiAVObject;
class NiStream;

struct NiCollisionObject {
public:
    // 0x00a80fa0
    ::NiCollisionObject *Construct();
    // 0x00a80fd0
    void LoadBinary(::NiStream &);
    // 0x00a80ff0
    void LinkObject(::NiStream &);
    // 0x00a810b0
    void SetSceneObject(::NiAVObject *);
    // 0x00a810d0
    NiCollisionObject(::NiAVObject *);
};
