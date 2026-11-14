// gamebryo2.2/corelibs/nianimation/nibsplinebasisdata_decls.h: declares NiObject, NiBinaryStream, NiStream, NiBSplineBasisData
#ifndef FNV_NIBSPLINEBASISDATA_DECLS_H
#define FNV_NIBSPLINEBASISDATA_DECLS_H


#include "NiRefObject.h"

struct NiStream;
struct CloningProcess;
struct NiRTTI;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;

// PC virtual prefix through LoadBinary, including NiRefObject's two slots.
struct NiObject : public NiRefObject
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
    virtual BSMultiBoundNode* GetMultiBoundNode();
    virtual NiGeometry* GetNiGeometry();
    virtual NiTriBasedGeom* GetTriBasedGeom();
    virtual NiTriStrips* GetTriStrips();
    virtual NiTriShape* GetTriShape();
    virtual BSSegmentedTriShape* GetSegmentedTriShape();
    virtual BSResizableTriShape* GetResizableTriShape();
    virtual NiParticles* GetNiParticles();
    virtual NiLines* GetNiLines();
    virtual bhkNiCollisionObject* GetCollisionObject();
    virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    virtual bhkRigidBody* GetRigidBody();
    virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void LoadBinary(NiStream& stream);
};

class NiBinaryStream
{
  public:
    typedef unsigned int(__cdecl* ReadFunction)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    ReadFunction m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void ReadScalar(T& value)
    {
        unsigned int componentSize = sizeof(T);
        unsigned int bytesRead = m_pfnRead(this, &value, sizeof(T), &componentSize, 1);
        m_uiStreamFlags += bytesRead;
    }
};

// Only the input-stream prefix is needed by this translation unit.
struct NiStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned char layoutPadding4[0x248];
    NiBinaryStream* m_pUnderlyingStream;
};

template <class T, int Degree> class BSplineBasis
{
  public:
    int m_iNumControlPoints;
    T m_afWeights[Degree + 1];
    T m_fLastTime;
    int m_iMinControlPoint;
    int m_iMaxControlPoint;
};

class NiBSplineBasisData : public NiObject
{
  public:
    BSplineBasis<float, 3> m_kBSplineBasis;
    virtual void LoadBinary(NiStream& stream);
};


#endif
