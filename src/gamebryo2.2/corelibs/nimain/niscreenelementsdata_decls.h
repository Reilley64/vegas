// gamebryo2.2/corelibs/nimain/niscreenelementsdata_decls.h: declares NiPoint2, NiBound, NiGeometryData, NiTriBasedGeomData, NiTriShapeData and more
#ifndef FNV_NISCREENELEMENTSDATA_DECLS_H
#define FNV_NISCREENELEMENTSDATA_DECLS_H

#include "fnv/decl/FUN_00a66960_cls.h"
#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class NiAdditionalGeometryData;
struct NiBound;
struct RgbaColor;
class NiGeometryData;
class NiGeometryData__RendererData;
struct NiPoint2
{
  public:
    float x, y;
};
class NiScreenElementsData;
class NiScreenElementsData__Polygon;
class NiTriBasedGeomData;
class NiTriShapeData;
class NiTriShapeData__SNAMemBlock;
class NiTriShapeData__SharedNormalArray;
struct NiBound
{
  public:
    NiPoint3 m_kCenter;  // +0x0, 12 bytes
    union
    {                          // overlapping CodeView storage
        float m_fBoundRadius;  // +0xC, 4 bytes
        int m_iRadius;         // +0xC, 4 bytes
    };
};
class NiGeometryData : public NiObject
{
  public:
    void SetDirtyFlags(unsigned int);
    // Unnamed PC texture-set accessor; see manifest binding.
    NiPoint3* GetVertices()
    {
        return m_pkVertex;
    }
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
};
class NiTriBasedGeomData : public NiGeometryData
{
  public:
    unsigned short m_usTriangles;  // +0x40, 2 bytes
    unsigned char layoutPadding42[2];
};
class NiTriShapeData : public NiTriBasedGeomData
{
  public:
    unsigned int m_uiTriListLength;                            // +0x44, 4 bytes
    unsigned short* m_pusTriList;                              // +0x48, 4 bytes
    NiTriShapeData__SharedNormalArray* m_pkSharedNormalArray;  // +0x4C, 4 bytes
    unsigned short m_usSharedNormalCount;                      // +0x50, 2 bytes
    unsigned char layoutPadding52[2];
    NiTriShapeData__SNAMemBlock* m_pkSharedNormalArrayMemoryBlock;  // +0x54, 4 bytes
};
class NiScreenElementsData__Polygon
{
  public:
    unsigned short m_usVertexCount;
    unsigned short m_usVertexOffset;
    unsigned short m_usTriangleCount;
    unsigned short m_usTriangleIndexOffset;
};
class NiScreenElementsData : public NiTriShapeData
{
  public:
    bool SetRectangle(int, float, float, float, float);
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
    NiScreenElementsData__Polygon* m_akPolygon;  // +0x58, 4 bytes
    unsigned short* m_ausPIndexer;               // +0x5C, 4 bytes
    unsigned short m_usMaxPQuantity;             // +0x60, 2 bytes
    unsigned short m_usPGrowBy;                  // +0x62, 2 bytes
    unsigned short m_usPQuantity;                // +0x64, 2 bytes
    unsigned short m_usMaxVQuantity;             // +0x66, 2 bytes
    unsigned short m_usVGrowBy;                  // +0x68, 2 bytes
    unsigned short m_usMaxIQuantity;             // +0x6A, 2 bytes
    unsigned short m_usIGrowBy;                  // +0x6C, 2 bytes
    bool m_bGeometryInitialized;                 // +0x6E, 1 bytes
    unsigned char layoutPadding6F[1];
};
#endif
