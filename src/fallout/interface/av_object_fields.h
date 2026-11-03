#pragma once

class NiNode;

// The leading fields of NiAVObject (the NiObjectNET members, then the parent), for interface code that reaches a
// scene object through a stand-in type. 0x009611e0 (a folded getter) returns m_pkParent.
struct AVObjectFields
{
    void* vtable;
    unsigned int m_uiRefCount;
    const char* m_kName;
    void* m_spControllers;
    void** m_ppkExtra;
    unsigned short m_usExtraDataSize;
    unsigned short m_usMaxSize;
    NiNode* m_pkParent;
};
