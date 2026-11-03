// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRISTRIPSDATA_H
#define FNV_NITRISTRIPSDATA_H

#include "fnv/decl/FUN_00a8aa30_shell.h"
#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class NiAdditionalGeometryData;
class NiRTTI;
class NiStream;
class NiBound;
class RgbaColor;
class NiGeometryData;
class NiGeometryData__RendererData;
class NiPoint2;
class NiTriBasedGeomData;
class NiTriStripsData;
class NiBound
{
  public:
    NiPoint3 m_kCenter;  // +0x0, 12 bytes
    union
    {                          // overlapping CodeView storage
        float m_fBoundRadius;  // +0xC, 4 bytes
        int m_iRadius;         // +0xC, 4 bytes
    };
    // void __cdecl NiBound::*()
    // const NiPoint3& __cdecl NiBound::*()
    // void __cdecl NiBound::*(float)
    // float __cdecl NiBound::*()
    // void __cdecl NiBound::*(const NiPoint3&, float)
    // bool __cdecl NiBound::*(const NiBound&)
    // bool __cdecl NiBound::*(const NiBound&)
    // void __cdecl NiBound::*(int, const NiPoint3*)
    // Update
    // void __cdecl NiBound::*(NiTPrimitiveArray<NiBound const *>&)
    // void __cdecl NiBound::*(const NiBound*)
    // int __cdecl NiBound::*(const NiPlane&)
    // bool __cdecl NiBound::*(float, const NiBound&, const NiPoint3&, const NiBound&, const NiPoint3&)
    // bool __cdecl NiBound::*(float, const NiBound&, const NiPoint3&, const NiBound&, const NiPoint3&, float&, NiPoint3&, bool, NiPoint3&, NiPoint3&)
    // void __cdecl NiBound::*(NiStream&)
    // void __cdecl NiBound::*(NiStream&)
    // char* __cdecl NiBound::*(const char*)
    // const NiBound& __cdecl NiBound::*(const NiBound&)
};
class NiGeometryData : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned short m_usVertices;                                 // +0x8, 2 bytes
    unsigned short m_usGeometryFlags;                            // +0xA, 2 bytes
    unsigned short m_usTrianglePoints;                           // +0xC, 2 bytes
    unsigned short m_usDirtyFlags;                               // +0xE, 2 bytes
    NiBound m_kBound;                                            // +0x10, 16 bytes
    NiPoint3* m_pkVertex;                                        // +0x20, 4 bytes
    NiPoint3* m_pkNormal;                                        // +0x24, 4 bytes
    RgbaColor* m_pkColor;                                        // +0x28, 4 bytes
    NiPoint2* m_pkTexture;                                       // +0x2C, 4 bytes
    NiPointer<NiAdditionalGeometryData> m_spAdditionalGeomData;  // +0x30, 4 bytes
    NiGeometryData__RendererData* m_pkGeometryRendererData;      // +0x34, 4 bytes
    unsigned char m_ucKeepFlags;                                 // +0x38, 1 bytes
    unsigned char m_ucCompressFlags;                             // +0x39, 1 bytes
    bool m_bIsDynamic;                                           // +0x3A, 1 bytes
    bool m_bBoundDirty;                                          // +0x3B, 1 bytes
    bool m_bVerticesDirty;                                       // +0x3C, 1 bytes
    unsigned char layoutPadding3D[3];
    // const NiRTTI* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiStream&)
    // void __cdecl NiGeometryData::*(NiStream&)
    // bool __cdecl NiGeometryData::*(NiStream&)
    // void __cdecl NiGeometryData::*(NiStream&)
    // bool __cdecl NiGeometryData::*(NiObject*)
    // void __cdecl NiGeometryData::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(bool)
    // unsigned short __cdecl NiGeometryData::*()
    // GetVertices
    // void __cdecl NiGeometryData::*(bool)
    // GetNormals
    // NiGeometryData::DataFlags __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiGeometryData::DataFlags)
    // GetBound
    // void __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(bool)
    // GetColors
    // void __cdecl NiGeometryData::*(bool, unsigned short)
    // unsigned short __cdecl NiGeometryData::*()
    // GetTextures
    // GetTextureSet
    // void __cdecl NiGeometryData::*(NiPoint2*)
    // void __cdecl NiGeometryData::*(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short, NiGeometryData::DataFlags)
    // bool __cdecl NiGeometryData::*(bool)
    // void __cdecl NiGeometryData::*()
    // NiGeometryData::Consistency __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiGeometryData::Consistency)
    // void __cdecl NiGeometryData::*(unsigned short)
    // unsigned int __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(unsigned int)
    // NiGeometryData::RendererData* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiGeometryData::RendererData*)
    // unsigned int __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(unsigned int)
    // NiAdditionalGeometryData* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiAdditionalGeometryData*)
    // unsigned int __cdecl NiGeometryData::*()
    // NiObjectGroup* __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(NiObjectGroup*)
    // unsigned short __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*()
    // unsigned short __cdecl NiGeometryData::*()
    // void __cdecl NiGeometryData::*(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short, NiGeometryData::DataFlags)
    // void __cdecl NiGeometryData::*(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short, NiGeometryData::DataFlags)
    // void __cdecl NiGeometryData::*(unsigned short*&, unsigned short*&, unsigned char)
    // int __cdecl NiGeometryData::*(unsigned short, unsigned short, unsigned char)
    // NiGeometryData
    // void __cdecl NiGeometryData::*(unsigned short*, unsigned char, int, int)
    // int __cdecl NiGeometryData::*(unsigned short*, unsigned char, int, int)
    // void __cdecl NiGeometryData::*(unsigned short)
    // void __cdecl NiGeometryData::*(NiGeometryData::DataFlags)
    // NiGeometryData& __cdecl NiGeometryData::*(const NiGeometryData&)
    // void __cdecl NiGeometryData::*()
};
class NiTriBasedGeomData : public NiGeometryData
{
  public:
    // base NiGeometryData at +0x0, size 64
    unsigned short m_usTriangles;  // +0x40, 2 bytes
    unsigned char layoutPadding42[2];
    void SaveBinary(NiStream&);
    unsigned short GetNumTriangles();
    // const NiRTTI* __cdecl NiTriBasedGeomData::*()
    // void __cdecl NiTriBasedGeomData::*(NiStream&)
    // void __cdecl NiTriBasedGeomData::*(NiStream&)
    // bool __cdecl NiTriBasedGeomData::*(NiStream&)
    // void __cdecl NiTriBasedGeomData::*(NiStream&)
    // bool __cdecl NiTriBasedGeomData::*(NiObject*)
    // void __cdecl NiTriBasedGeomData::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiTriBasedGeomData::*()
    // unsigned short __cdecl NiTriBasedGeomData::*()
    // void __cdecl NiTriBasedGeomData::*(unsigned short)
    // NiTriBasedGeomData
    // NiTriBasedGeomData& __cdecl NiTriBasedGeomData::*(const NiTriBasedGeomData&)
    // void __cdecl NiTriBasedGeomData::*()
};
class NiTriStripsData : public NiTriBasedGeomData
{
  public:
    // base NiTriBasedGeomData at +0x0, size 68
    unsigned short m_usStrips;  // +0x44, 2 bytes
    unsigned char layoutPadding46[2];
    unsigned short* m_pusStripLengths;  // +0x48, 4 bytes
    unsigned short* m_pusStripLists;    // +0x4C, 4 bytes
    const NiRTTI* GetRTTI() const;
    unsigned short* GetTriangleStripData();
    void GetTriangleStripData(unsigned short&, const unsigned short*&, const unsigned short*&, unsigned int&);
    void SaveBinary(NiStream&);
    // const NiRTTI* __cdecl NiTriStripsData::*()
    // void __cdecl NiTriStripsData::*(NiStream&)
    // void __cdecl NiTriStripsData::*(NiStream&)
    // bool __cdecl NiTriStripsData::*(NiStream&)
    // void __cdecl NiTriStripsData::*(NiStream&)
    // bool __cdecl NiTriStripsData::*(NiObject*)
    // NiObject* __cdecl NiTriStripsData::*()
    // void __cdecl NiTriStripsData::*(NiTPrimitiveArray<char *>*)
    // NiTriStripsData
    // void __cdecl NiTriStripsData::*()
    // void __cdecl NiTriStripsData::*(unsigned short, unsigned short&, unsigned short&, unsigned short&)
    // unsigned short __cdecl NiTriStripsData::*()
    // unsigned short* __cdecl NiTriStripsData::*()
    // unsigned short* __cdecl NiTriStripsData::*()
    // unsigned short __cdecl NiTriStripsData::*()
    // NiTriStripsData* __cdecl NiTriStripsData::*()
    // void __cdecl NiTriStripsData::*(unsigned short, unsigned short*, unsigned short*)
    // void __cdecl NiTriStripsData::*(unsigned short, unsigned short*, unsigned short*)
    // void __cdecl NiTriStripsData::*()
    // void __cdecl NiTriStripsData::*(unsigned short&, const unsigned short*&, const unsigned short*&, unsigned int&)
    // unsigned int __cdecl NiTriStripsData::*()
    // NiTriStripsData& __cdecl NiTriStripsData::*(const NiTriStripsData&)
    // void __cdecl NiTriStripsData::*()
};
#endif
