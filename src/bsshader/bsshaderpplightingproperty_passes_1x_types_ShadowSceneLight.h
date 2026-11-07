// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_SHADOWSCENELIGHT_H
#define FNV_SHADOWSCENELIGHT_H

#include "layout_support.h"
#include "NiPoint3.h"
#include "NiRefObject.h"
#include "layout_support.h"
class BSMultiBoundNode;
class BSPortal;
class BSPortalGraph;
class BSRenderedTexture;
class BSShaderAccumulator;
struct D3DXMATRIX;
class NiAVObject;
class NiCamera;
class NiFrustumPlanes;
class NiLight;
class NiPlane;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator;
class NiTListItem_NiPointer_NiAVObject___;
class NiTListItem_NiPointer_NiTriBasedGeom___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_NiPointer_NiAVObject___;
class NiTPointerList_NiPointer_NiTriBasedGeom___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___;
class NiTexture;
class NiTriBasedGeom;
class ShadowSceneLight;
class _D3DMATRIX;
#include "fnv/d3dx_types.h"

class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
{
  public:
    NiTListItem_NiPointer_NiTriBasedGeom___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiTriBasedGeom___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(unsigned int)
};
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, const NiPointer<NiTriBasedGeom>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, const NiPointer<NiTriBasedGeom>&)
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*)
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*&)
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*&)
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&)
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiPointer<NiTriBasedGeom> >* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(unsigned int)
};
class NiTPointerList_NiPointer_NiTriBasedGeom___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> > at +0x0, size 12
    // NiTPointerList<NiPointer<NiTriBasedGeom> >
    // void __cdecl NiTPointerList<NiPointer<NiTriBasedGeom> >::*()
    // NiTPointerList<NiPointer<NiTriBasedGeom> >& __cdecl NiTPointerList<NiPointer<NiTriBasedGeom> >::*(const NiTPointerList<NiPointer<NiTriBasedGeom> >&)
    // void* __cdecl NiTPointerList<NiPointer<NiTriBasedGeom> >::*(unsigned int)
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
{
  public:
    NiTListItem_NiPointer_NiAVObject___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiAVObject___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(NiTListItem<NiPointer<NiAVObject> >*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(NiTListItem<NiPointer<NiAVObject> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, NiTListItem<NiPointer<NiAVObject> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, NiTListItem<NiPointer<NiAVObject> >*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(unsigned int)
};
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, const NiPointer<NiAVObject>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, const NiPointer<NiAVObject>&)
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*)
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*&)
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*&)
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&)
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiPointer<NiAVObject> >* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(NiTListItem<NiPointer<NiAVObject> >*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(unsigned int)
};
class NiTPointerList_NiPointer_NiAVObject___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> > at +0x0, size 12
    // NiTPointerList<NiPointer<NiAVObject> >
    // void __cdecl NiTPointerList<NiPointer<NiAVObject> >::*()
    // NiTPointerList<NiPointer<NiAVObject> >& __cdecl NiTPointerList<NiPointer<NiAVObject> >::*(const NiTPointerList<NiPointer<NiAVObject> >&)
    // void* __cdecl NiTPointerList<NiPointer<NiAVObject> >::*(unsigned int)
};
class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;  // +0x0, 12 bytes
    float m_fPlaneConstant;   // +0xC, 4 bytes
    // NiPlane
    // bool __cdecl NiPlane::*(const NiPlane&)
    // bool __cdecl NiPlane::*(const NiPlane&)
    // NiPlane __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(const NiPoint3&)
    // const NiPoint3& __cdecl NiPlane::*()
    // void __cdecl NiPlane::*(float)
    // float __cdecl NiPlane::*()
    // float __cdecl NiPlane::*(const NiPoint3&)
    // int __cdecl NiPlane::*(const NiPoint3&)
    // void __cdecl NiPlane::*(NiStream&)
    // void __cdecl NiPlane::*(NiStream&)
    // char* __cdecl NiPlane::*(const char*)
};
class NiFrustumPlanes
{
  public:
    NiPlane m_akPlanes[6];             // +0x0, 96 bytes
    unsigned int m_uiActivePlaneMask;  // +0x60, 4 bytes
    // NiFrustumPlanes
    // Set
    // const NiPlane& __cdecl NiFrustumPlanes::*(unsigned int)
    // void __cdecl NiFrustumPlanes::*(unsigned int, const NiPlane&)
    // bool __cdecl NiFrustumPlanes::*(unsigned int)
    // bool __cdecl NiFrustumPlanes::*()
    // bool __cdecl NiFrustumPlanes::*()
    // void __cdecl NiFrustumPlanes::*(unsigned int)
    // void __cdecl NiFrustumPlanes::*(unsigned int)
    // void __cdecl NiFrustumPlanes::*()
    // void __cdecl NiFrustumPlanes::*()
    // unsigned int __cdecl NiFrustumPlanes::*()
    // void __cdecl NiFrustumPlanes::*(unsigned int)
};
class ShadowSceneLight : public NiRefObject
{
  public:
    // base NiRefObject at +0x0, size 8
    int m_iShadowLightState;                                       // +0x8, 4 bytes
    float m_fShadowParameter3;                                     // +0xC, 4 bytes
    D3DXMATRIX m_kShadowMatrix1;                                   // +0x10, 64 bytes
    D3DXMATRIX m_kShadowMatrix2;                                   // +0x50, 64 bytes
    D3DXMATRIX m_kShadowMatrix3;                                   // +0x90, 64 bytes
    float m_fShadowParameter4;                                     // +0xD0, 4 bytes
    float m_fShadowParameter5;                                     // +0xD4, 4 bytes
    float m_fShadowParameter2;                                     // +0xD8, 4 bytes
    float m_fShadowParameter1;                                     // +0xDC, 4 bytes
    NiTPointerList_NiPointer_NiTriBasedGeom___ m_kLightStripList;  // +0xE0, 12 bytes
    bool m_bSkipLightObject;                                       // +0xEC, 1 bytes
    bool m_bLightFlag1;                                            // +0xED, 1 bytes
    unsigned char layoutPaddingEE[2];
    NiPointer<NiTexture> m_spShadowTexture;  // +0xF0, 4 bytes
    bool m_bLightFlag0;                      // +0xF4, 1 bytes
    bool m_bLightFlag2;                      // +0xF5, 1 bytes
    unsigned char layoutPaddingF6[2];
    NiPointer<NiLight> m_pMenuLight;  // +0xF8, 4 bytes
    bool m_bIsPipLight;               // +0xFC, 1 bytes
    unsigned char layoutPaddingFD[3];
    NiPoint3 m_kPipLightPosition;                           // +0x100, 12 bytes
    NiPointer<BSRenderedTexture> m_spLightRenderedTexture;  // +0x10C, 4 bytes
    unsigned short m_usEnabledState;                        // +0x110, 2 bytes
    unsigned char layoutPadding112[2];
    NiPointer<NiAVObject> m_spSceneObject;  // +0x114, 4 bytes
    bool m_bLightFlag3;                     // +0x118, 1 bytes
    unsigned char layoutPadding119[3];
    float m_fSpotlightParameter;  // +0x11C, 4 bytes
    float m_kShadowLightData;     // +0x120, 4 bytes
    bool m_bLightFlag4;           // +0x124, 1 bytes
    unsigned char layoutPadding125[3];
    NiPointer<NiAVObject> m_pLightNode;                         // +0x128, 4 bytes
    NiTPointerList_NiPointer_NiAVObject___ m_kSceneObjectList;  // +0x12C, 12 bytes
    void* m_pShadowData;                                        // +0x138, 4 bytes
    NiPointer<NiTriBasedGeom> m_spShadowGeometry;               // +0x13C, 4 bytes
    NiPointer<NiCamera> m_pCamera;                              // +0x140, 4 bytes
    NiFrustumPlanes m_kFrustumPlanes;                           // +0x144, 100 bytes
    float m_afShadowFrustumData[24];                            // +0x1A8, 96 bytes
    bool m_bShadowFrustumInitialized;                           // +0x208, 1 bytes
    unsigned char layoutPadding209[3];
    NiPointer<BSShaderAccumulator> m_spShadowShaderAccumulator;  // +0x20C, 4 bytes
    BSSimpleArray<BSMultiBoundNode*, 1024> m_kMultiBoundNodes;   // +0x210, 16 bytes
    BSSimpleArray<BSPortal*, 1024> m_kShadowLightData1;          // +0x220, 16 bytes
    BSSimpleArray<NiNode*, 1024> m_kShadowLightData2;            // +0x230, 16 bytes
    BSPortalGraph* m_pPortalConnectivityGraphInfo;                                 // +0x240, 4 bytes
    unsigned char layoutPadding244[12];
    // ShadowSceneLight
    // void __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*(NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiTriBasedGeom*)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiTriBasedGeom*, void*)
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*(const NiBound&, NiLight*, float)
    // bool __cdecl ShadowSceneLight::*(const NiBound&)
    // void __cdecl ShadowSceneLight::*(NiLight*)
    // NiLight* __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*(NiCamera*)
    // float __cdecl ShadowSceneLight::*(NiPoint3, NiLight*)
    // float __cdecl ShadowSceneLight::*(NiPoint3, NiPoint3, NiLight*)
    // float __cdecl ShadowSceneLight::*(NiBound*)
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(NiPoint3)
    // NiPoint3 __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSRenderedTexture*)
    // BSRenderedTexture* __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(bool)
    // unsigned short __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSCubeMapCamera*, NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float)
    // float __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float)
    // float __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // NiLines* __cdecl ShadowSceneLight::*(float, float)
    // void __cdecl ShadowSceneLight::*(BSShaderLightingProperty*, NiPoint3)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // NiAVObject* __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float, bool)
    // bool __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // const NiFrustumPlanes* __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float*)
    // float* __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSCullingProcess&, int)
    // void __cdecl ShadowSceneLight::*(BSCullingProcess&, int)
    // BSSimpleArray<BSMultiBoundNode *,1024>& __cdecl ShadowSceneLight::*()
    // BSSimpleArray<BSPortal *,1024>& __cdecl ShadowSceneLight::*()
    // BSSimpleArray<NiNode *,1024>& __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSPortalGraph*)
    // BSPortalGraph* __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiNode*)
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*(NiBound, NiCullingProcess&, unsigned short)
    // bool __cdecl ShadowSceneLight::*(NiCamera*, NiCamera*)
    // void __cdecl ShadowSceneLight::*(BSCubeMapCamera*, NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // ShadowSceneLight& __cdecl ShadowSceneLight::*(const ShadowSceneLight&)
    // void __cdecl ShadowSceneLight::*()
};
#endif
