// gamebryo2.2/corelibs/niparticle/nipsysmodifier_decls.h: declares NiObject, CloningProcess, NiBinaryStream, NiStream, NiPSysModifier
#ifndef FNV_NIPSYSMODIFIER_DECLS_H
#define FNV_NIPSYSMODIFIER_DECLS_H


#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/symbols_0109b000.h"
#include "NiRefObject.h"
#include "NiFixedString.h"


struct NiStream;
struct CloningProcess;
struct NiParticleSystem;

// Only the base operations used by this translation unit are exposed here.
struct NiObject : public NiRefObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);
    // Base copying operation has no identified name in the PC symbol evidence.
};

struct CloningProcess
{
  public:
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;
    NiTPointerMap<NiObject*, bool>* m_pProcessMap;
    unsigned int m_eCloneCopyMode;
    char m_bExactType;
};

struct ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char* key, T& value);
};

// The pointer-map lookup is folded with this canonically bound specialization.
inline bool NiPSysCloneMapGetAt(NiTPointerMap<NiObject*, NiObject*>* pkMap, NiObject* pkOriginal, NiObject*& pkClone)
{
    return reinterpret_cast<::A54440Hash *>((reinterpret_cast<NiTStringPointerMap<ShaderBufferRecord*>*>(pkMap)))->FUN_00a53c30(
        (::A54440Manager *)(reinterpret_cast<const char*>(pkOriginal)), (::A54440Manager **)&(reinterpret_cast<ShaderBufferRecord*&>(pkClone)));
}

class NiBinaryStream : public NiMemObject
{
  public:
    virtual ~NiBinaryStream();
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    inline unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                                   unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

struct NiStream : public NiObject
{
  public:
    unsigned char m_streamHeader[0xD8 - 8];
    unsigned int m_uiNifVersion;
    unsigned char m_streamTables[0x24C - 0xDC];
    NiBinaryStream* m_pUnderlyingStream;

    NiObject* GetLoadedObject();
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(pValue, sizeof(T), &uiSize, 1);
}

struct NiPSysModifier : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);
    void CopyMemberData(NiPSysModifier* pkDest, CloningProcess& kCloning);

    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
};


#endif
