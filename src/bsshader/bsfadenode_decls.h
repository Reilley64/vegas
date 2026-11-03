// bsshader/bsfadenode_decls.h: declares NiMemObject, NiRefObject, NiObject, NiObjectNET, NiProperty and more
#ifndef FNV_BSFADENODE_DECLS_H
#define FNV_BSFADENODE_DECLS_H
#include <cstddef>


// Private PC declarations for this translation unit. Opaque storage represents
// inherited fields that none of these three routines inspect.
#include <windows.h>
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"

class NiMemObject
{
  public:
    static void* operator new(std::size_t);
    static void operator delete(void*);
};
class NiRefObject : public NiMemObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
class NiRTTI;
class NiObject : public NiRefObject
{
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
class NiObjectNET : public NiObject
{
  public:
    unsigned char objectNetData[16];
};
class NiProperty : public NiObjectNET
{
  public:
    NiProperty();
};
class NiAlphaProperty : public NiProperty
{
  public:
    virtual ~NiAlphaProperty();
    unsigned short m_uiObjectFlags;
    unsigned char m_ucAlphaThreshold;
    NiAlphaProperty() : m_uiObjectFlags(0xEC), m_ucAlphaThreshold(0)
    {}
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (object)
                InterlockedIncrement(&object->m_uiRefCount);
        }
        return *this;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

class MemoryManager
{
  public:
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* s);
    static void* operator new(std::size_t n)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(n);
    }
    static void operator delete(void*);
};


union SETTING_VALUE
{
    const char* str;
    int i;
    unsigned int u;
    float f;
    bool b;
    char c;
    unsigned char h;
};
class Setting
{
  public:
    SETTING_VALUE uValue;
    const char* pKey;
    virtual ~Setting();
    virtual bool IsPrefSetting();
};
class INISettingCollection;
template <class T> class SettingT : public Setting
{
};
class NiExtraData;
class NiFixedString;
class NiAVObject : public NiObjectNET
{
  public:
    unsigned char avObjectData[0x84];
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};
class CloningProcess;
class NiUpdateData;
class NiNode : public NiAVObject
{
  public:
    unsigned char childrenData[0x10];
public:
    void CopyMemberData(::NiNode *, ::CloningProcess &);
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
public:
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
};
class FadingSceneNode;
class BSMultiBoundRoom;
class BSPortal;
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList* m_pkNext;
};
class BSFadeNode : public NiNode
{
  public:
    float fNearDistSqr;
    float fFarDistSqr;
    float fLastFade;
    float fCurrentFade;
    float m_fFadeDelta;
    float fTimeSinceUpdate;
    int eMultType;
    int iFrameCounter;
    void* pUserData;
    FadingSceneNode* m_pFadingSceneNode;
    BSSimpleList<BSMultiBoundRoom*> m_kParentRooms;
    BSSimpleList<BSPortal*> m_kParentPortals;

    BSFadeNode();
    static NiObject* CreateObject();
    static void InitializeMultiBounds();
    static NiPointer<NiAlphaProperty> ms_pAlphaProperty;
    static NiFixedString* ms_pFadeNodeAnimationName;
    void SetRange(float, float);
};
// PC depth texture forwarding declarations. The singleton has no known
// canonical data name, so its address-based name is kept here.
class BSRenderedTexture;
class ImageSpaceManager
{
  public:
    BSRenderedTexture* GetDepthRenderedTexture();
};
class BSShaderManager
{
  public:
    static BSRenderedTexture* GetSceneDepthRenderedTexture();
};
#endif
