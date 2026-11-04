// fallout_shared/sky/moon_types.h: declares SkyObject, Moon
#ifndef FNV_MOON_PRIVATE_TYPES_H
#define FNV_MOON_PRIVATE_TYPES_H

#include <stddef.h>
// BSStringT, NiPoint3, AutoMemContext/MEM_CONTEXT come from canonical headers (explicit ../../../include/ path: src/fallout_shared shadows it).
// NiPointer stays a unit-local superset (same layout): out-of-line ctor(T*)/dtor/operator=/T*/->/==/!= on NiNode/NiTriShape,
// which have no canonical header yet (the canonical NiPointer bodies need a complete T).
#define NiPointer FNV_NiPointer_Canonical
#include "../../../include/layout_support.h"
#undef NiPointer
#include "../../../include/NiPoint3.h"
#include "../../../include/AutoMemContext.h"
class NiNode;
class NiTriShape;
class Sky;
template <class T> class NiPointer
{
  public:
    NiPointer(T* object);
    ~NiPointer();
    NiPointer& operator=(T* object);
    operator T*() const;
    T* operator->() const;
    bool operator==(T* object) const;
    bool operator!=(T* object) const;
    T* m_pObject;
};
class SkyObject
{
  public:
    SkyObject();
    virtual ~SkyObject();
    virtual NiNode* GetRoot() const;
    virtual void Initialize(NiNode* root);
    virtual void Update(Sky* sky, float elapsed);
    NiPointer<NiNode> m_pRootNode;
};
class Moon : public SkyObject
{
  public:
    enum UpdateStatus
    {
        US_NOT_REQUIRED = 0,
        US_WHEN_CULLED = 1,
        US_INITIALIZE = 2
    };
    Moon(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade, float speed, float zOffset,
         unsigned int size);
    virtual ~Moon();
    virtual void Initialize(NiNode* root, const char* name);
    virtual void Update(Sky* sky, float elapsed);
    static bool IsMoonVisible(const Sky* sky);
    float GetMoonVisibility();
    float GetMoonShadowVisibility();
    NiPointer<NiNode> m_pMoonNode;
    NiPointer<NiNode> m_pMoonShadowNode;
    NiPointer<NiTriShape> m_pMoonShape;
    NiPointer<NiTriShape> m_pMoonShadowShape;
    BSStringT<char> m_kMoonTexturePaths[8];
    float m_fFadeStartAngle;
    float m_fFadeEndAngle;
    float m_fFadeAngleRange;
    float fSpeed;
    float m_fGlyphVerticalOffset;
    unsigned int iSize;
    UpdateStatus m_eUpdateStatus;
    float fPos;
    float m_fValue;
};
#endif
