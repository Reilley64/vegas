#pragma once

class NiAVObject;
class TESObjectTREE;
class TreeReference;

struct TreeManager {
public:
    // 0x00664f50
    ::NiAVObject *CreateTreeInstance(::TreeReference *, ::TESObjectTREE *);
};
