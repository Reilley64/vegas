#pragma once

// The leading data members of NiGeometryData (as in NiGeometryData.h), for units whose geometry data stand-ins
// declare no fields. The 4-byte getter folded into 0x0055b980 (BGSMessageInitAccess::GetIconFormID) reads
// `m_pkTexture` when called on geometry data.
struct GeometryDataFields
{
    void* vtable;
    unsigned int m_uiRefCount;
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    unsigned short m_usTrianglePoints;
    unsigned short m_usDirtyFlags;
    float m_kBound[4];
    void* m_pkVertex;
    void* m_pkNormal;
    void* m_pkColor;
    void* m_pkTexture;
};
