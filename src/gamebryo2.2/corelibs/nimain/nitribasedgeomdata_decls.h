// gamebryo2.2/corelibs/nimain/nitribasedgeomdata_decls.h: declares NiGeometryData, NiTriBasedGeomData
#ifndef NITRIBASEDGEOMDATA_DECLS_H
#define NITRIBASEDGEOMDATA_DECLS_H

#include "fnv/decl/fnv_00a67ea0__GeomEA0.h"
#include "fnv/decl/fnv_00a68520__NiGeometryDataSave.h"
#include "fnv/symbols_00d3d000.h"
struct NiStream;
struct NiPoint3;
struct NiPoint2;
struct RgbaColor;
enum NiGeometryData__DataFlags
{
    DataFlags_None = 0
};
class NiGeometryData
{
  public:
    NiGeometryData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                   NiGeometryData__DataFlags);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    unsigned char data[60];
};
class NiTriBasedGeomData : public NiGeometryData
{
  public:
    NiTriBasedGeomData(unsigned short, NiPoint3*, NiPoint3*, RgbaColor*, NiPoint2*, unsigned short,
                       NiGeometryData__DataFlags, unsigned short);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    unsigned short m_usTriangles;
};
#endif
