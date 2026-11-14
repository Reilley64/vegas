// corrected to the evidenced PC layouts. See EVIDENCE.md. No helper bodies.
#ifndef FNV_FONT_PRIVATE_GEOMETRY_TYPES_H
#define FNV_FONT_PRIVATE_GEOMETRY_TYPES_H

#include "fnv/decl/FnvCpu_FUN_00a7b850_CpuObject.h"
#include "font_types.h"
class NiNode;
class NiCollisionObject;
class FourComponentFloatVector;
class NiProperty;
class NiTimeController;
class NiExtraData;
class NiAdditionalGeometryData;
class NiGeometryData;
class NiGeometryData__RendererData;
class NiSkinInstance;
class NiShader;
class NiTriShapeData__SharedNormalArray;
class NiTriShapeData__SNAMemBlock;
class NiTListItem_NiPointer_NiProperty___;

#include "fnv/ni_mem_object.h"

#include "fnv/ni_ref_object.h"

struct NiObject : public NiRefObject
{
  public:
};

class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
};

struct NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;                       // +0x8
    NiPointer<NiTimeController> m_pControllers;  // +0xC
    NiExtraData** m_ppExtraData;                 // +0x10
    unsigned short m_usExtraDataCount;           // +0x14
    unsigned short m_usMaxSize;                  // +0x16
};

struct NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
public:
    static const ::NiPoint3 ZERO;
};

struct RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
};

class TextureCoordinate
{
  public:
    float fTextureCoordinateU;  // +0x0, 4 bytes
    float fV;                   // +0x4, 4 bytes
};

class FontCharacterInfo
{
  public:
    int m_iCharacterCode;           // +0x0, 4 bytes
    TextureCoordinate pMapping[4];  // +0x4, 32 bytes
    float m_fGlyphWidthInPixels;                   // +0x24, 4 bytes
    float m_fGlyphExtent;                  // +0x28, 4 bytes
    float m_fHorizontalAdvance;     // +0x2C, 4 bytes
    float m_fHorizontalSpacing;     // +0x30, 4 bytes
    float m_fVerticalOffset;        // +0x34, 4 bytes
};

// PC NiPoint2 coordinates: JohnnyGuitar NiPoint2.hpp declarations only.
struct NiPoint2
{
  public:
    float x;
    float y;
};

class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};

class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};

class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    unsigned int m_uiCount;  // +0x0, 4 bytes
};

class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
    NiTListItem_NiPointer_NiProperty___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiProperty___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
};

class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
};

class NiTPointerList_NiPointer_NiProperty___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiProperty___
{
  public:
};

struct ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];  // PC: +0x0, 36 bytes
};

class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;  // PC: +0x0, 36 bytes
    NiPoint3 m_kTranslation;   // PC: +0x24, 12 bytes
    float m_fScale;            // PC: +0x30, 4 bytes
};

class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_pParentNode;                                    // +0x18, 4 bytes
    NiPointer<NiCollisionObject> m_spCollisionObject;         // +0x1C, 4 bytes
    FourComponentFloatVector* m_kWorldBound;                  // +0x20, 4 bytes
    NiTPointerList_NiPointer_NiProperty___ SceneGraphObject;  // +0x24, 12 bytes
    unsigned int m_uiObjectFlags;                                    // +0x30, 4 bytes
    NiTransform m_kLocalTransform;                            // PC: +0x34, 52 bytes
    NiTransform m_kWorldSpaceTransform;                                     // PC: +0x68, 52 bytes
};

class NiPropertyState
{
  public:
    NiPointer<NiProperty> m_spProperties[7];  // +0x0, 28 bytes
};

class NiGeometry : public NiAVObject
{
  public:
    NiPropertyState m_kPropertyState;                // +0x9C, 28 bytes
    NiPointer<NiGeometryData> m_spGeometryData;      // +0xB8, 4 bytes
    NiPointer<NiSkinInstance> m_spSkinningInstance;  // +0xBC, 4 bytes
    NiShader* m_pGeometryShader;                     // +0xC0, 4 bytes
};

class NiTriBasedGeom : public NiGeometry
{
  public:
};

class NiTriShape : public NiTriBasedGeom
{
  public:
};

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
    unsigned short m_usTriangles;    // +0x40, 2 bytes
    unsigned short activeTriangles;  // PC +0x42, JIP name
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

#endif
