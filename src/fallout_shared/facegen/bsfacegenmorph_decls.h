// fallout_shared/facegen/bsfacegenmorph_decls.h: declares BSFaceGenMorph, NiPoint3, BSFaceGenMorphDifferential, BSFaceGenMorphStatistical, MagicCaster and more
#ifndef BSFACEGENMORPH_DECLS_H
#define BSFACEGENMORPH_DECLS_H


#include "fnv/decl/C6533F0Holder.h"
#include "fnv/decl/FUN_00534570_shell.h"
#include "fnv/decl/FUN_00656fd0_shell.h"
#include "fnv/decl/FUN_00657be0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00a67410.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00660000.h"
#include "fnv/symbols_01065000.h"
class NiTriBasedGeom;
class BSFaceGenBaseMorphExtraData;
class BSFaceGenMorph
{
  public:
    BSFaceGenMorph();
    ~BSFaceGenMorph();
    void** m_ppVirtualMethodTable;
};

struct NiPoint3
{
  public:
    NiPoint3();
    NiPoint3 operator*(float) const;
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3& operator+=(const NiPoint3&);
    float x;
    float y;
    float z;
};

class BSFaceGenMorph_d006606e0 : public BSFaceGenMorph
{
  public:
    BSFaceGenMorph_d006606e0()
    {}
    ~BSFaceGenMorph_d006606e0();
};
class BSFaceGenMorphDifferential : public BSFaceGenMorph_d006606e0
{
  public:
    NiPoint3* m_pkDeltas;
    unsigned int m_uiVertexCount;
    BSFaceGenMorphDifferential(unsigned int count);
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);
};

class BSFaceGenMorphStatistical : public BSFaceGenMorph_d006606e0
{
  public:
    unsigned long* m_puiVertexIndices;
    unsigned int m_uiVertexCount;
    unsigned int m_uiFirstIndex;
    BSFaceGenMorphStatistical(unsigned int count, unsigned int firstIndex);
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);
};


class MagicItem;
class MagicCaster
{
  public:
    virtual void SetSelectedMagicItem(MagicItem*);
};
class GeometryVertexBuffer
{
  public:
    char* m_pkDeltas;
    unsigned int stride;
    unsigned int third;

    void SetVertex(unsigned int, const NiPoint3&);
    GeometryVertexBuffer();
};
class NiGeometryData
{
  public:
};
class NiGeometry
{
  public:
};
class NiTriBasedGeom : public NiGeometry
{
};
class BSFaceGenBaseMorphExtraData
{
  public:
};
#endif
