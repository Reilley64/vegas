#pragma once

class NiNode;

// The leading data members of NiAVObject (NiObjectNET and the parent), for units whose scene graph stand-ins declare
// no fields. The release build reads `m_pkParent` through the folded 4-byte getter at 0x009611e0.
struct NiAVObjectFields
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
