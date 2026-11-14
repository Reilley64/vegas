// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSDATA_H
#define FNV_NIPSYSDATA_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class NiAdditionalGeometryData;
struct NiBound;
struct RgbaColor;
class NiGeometryData;
class NiGeometryData__RendererData;
struct NiPSysData;
struct Point3ParameterData;
class NiParticlesData;
struct NiPoint2;
class NiQuaternion;
struct NiStream;
struct NiBound
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
class NiParticlesData : public NiGeometryData
{
  public:
    // base NiGeometryData at +0x0, size 64
    bool m_bHasRadii;  // +0x40, 1 bytes
    unsigned char layoutPadding41[3];
    unsigned short* m_pusParticleIndices;  // +0x44, 4 bytes
    float* m_pfSortValues;                 // +0x48, 4 bytes
    float* m_pfRadii;                      // +0x4C, 4 bytes
    unsigned short m_usActive;             // +0x50, 2 bytes
    unsigned char layoutPadding52[2];
    float* m_pfSizes;                         // +0x54, 4 bytes
    NiQuaternion* m_pkRotations;              // +0x58, 4 bytes
    float* m_pfRotationAngles;                // +0x5C, 4 bytes
    NiPoint3* m_pkRotationAxes;               // +0x60, 4 bytes
    unsigned char* m_pucTextureIndices;       // +0x64, 4 bytes
    RgbaColor* m_pkSubTextureOffsets;         // +0x68, 4 bytes
    unsigned char m_ucSubTextureOffsetCount;  // +0x6C, 1 bytes
    unsigned char layoutPadding6D[3];
    // const NiRTTI* __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(NiStream&)
    // void __cdecl NiParticlesData::*(NiStream&)
    // bool __cdecl NiParticlesData::*(NiStream&)
    // void __cdecl NiParticlesData::*(NiStream&)
    // bool __cdecl NiParticlesData::*(NiObject*)
    // NiObject* __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(NiTPrimitiveArray<char *>*)
    // NiParticlesData
    // void __cdecl NiParticlesData::*()
    // GetRadii
    // GetSizes
    // GetTextureIndices
    // GetSubTextureOffsets
    // GetSubTextureOffsetCount
    // GetRotations
    // GetRotationAngles
    // GetRotationAxes
    // void __cdecl NiParticlesData::*(unsigned short)
    // unsigned short __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiQuaternion*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiPoint3*)
    // void __cdecl NiParticlesData::*(unsigned char*)
    // void __cdecl NiParticlesData::*(RgbaColor*, unsigned char)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiQuaternion*)
    // void __cdecl NiParticlesData::*(float*)
    // void __cdecl NiParticlesData::*(NiPoint3*)
    // void __cdecl NiParticlesData::*(unsigned char*)
    // void __cdecl NiParticlesData::*(RgbaColor*, unsigned char)
    // void __cdecl NiParticlesData::*()
    // NiObject* __cdecl NiParticlesData::*()
    // unsigned short* __cdecl NiParticlesData::*()
    // void __cdecl NiParticlesData::*(const NiCamera*)
    // void __cdecl NiParticlesData::*(int, int)
    // NiParticlesData& __cdecl NiParticlesData::*(const NiParticlesData&)
    // void __cdecl NiParticlesData::*()
    virtual void LoadBinary(NiStream&);
    void SetRotations(NiQuaternion*);
};
struct NiPSysData : public NiParticlesData
{
  public:
    // base NiParticlesData at +0x0, size 112
    Point3ParameterData* m_pkParticleInfo;  // +0x70, 4 bytes
    float* m_pfRotationSpeeds;              // +0x74, 4 bytes
    unsigned short m_usNumActive;           // +0x78, 2 bytes
    unsigned short m_usNumParticles;        // +0x7A, 2 bytes
    // const NiRTTI* __cdecl NiPSysData::*()
    // void __cdecl NiPSysData::*(NiStream&)
    // void __cdecl NiPSysData::*(NiStream&)
    // bool __cdecl NiPSysData::*(NiStream&)
    // void __cdecl NiPSysData::*(NiStream&)
    // bool __cdecl NiPSysData::*(NiObject*)
    // NiObject* __cdecl NiPSysData::*()
    // void __cdecl NiPSysData::*(NiTPrimitiveArray<char *>*)
    // NiPSysData
    // void __cdecl NiPSysData::*()
    // GetParticleInfo
    // void __cdecl NiPSysData::*(Point3ParameterData*)
    // GetRotationSpeeds
    // void __cdecl NiPSysData::*(float*)
    // void __cdecl NiPSysData::*(unsigned short)
    // void __cdecl NiPSysData::*()
    // unsigned short __cdecl NiPSysData::*()
    // unsigned short __cdecl NiPSysData::*()
    // void __cdecl NiPSysData::*(Point3ParameterData*)
    // void __cdecl NiPSysData::*(float*)
    // NiPSysData& __cdecl NiPSysData::*(const NiPSysData&)
    // void __cdecl NiPSysData::*()
    virtual void LoadBinary(NiStream&);
};
#endif
