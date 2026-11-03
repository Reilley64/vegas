#ifndef NICONSOLEIBMANAGER_DECLS_H
#define NICONSOLEIBMANAGER_DECLS_H

#include <cstring>
#include "fnv/symbols_00a29000.h"
#include "NiRefObject.h"

struct _D3DINDEXBUFFER_DESC
{
    int Format;
    int Type;
    unsigned long Usage;
    int Pool;
    unsigned int Size;
};

class COMBaseInterface
{
  public:
    virtual void vfn_0() = 0;
    virtual void vfn_4() = 0;
    virtual unsigned long Release() = 0;
    virtual void vfn_c() = 0;
    virtual void vfn_10() = 0;
    virtual void vfn_14() = 0;
    virtual void vfn_18() = 0;
    virtual void vfn_1c() = 0;
    virtual void vfn_20() = 0;
    virtual void vfn_24() = 0;
    virtual void vfn_28() = 0;
    virtual long Lock(unsigned int, unsigned int, void**, unsigned long) = 0;
    virtual long Unlock() = 0;
    virtual long GetDesc(_D3DINDEXBUFFER_DESC*) = 0;
};

class Direct3DDeviceInterface
{
  public:
    virtual void vfn_0() = 0;
    virtual void vfn_4() = 0;
    virtual void vfn_8() = 0;
    virtual void vfn_c() = 0;
    virtual void vfn_10() = 0;
    virtual void vfn_14() = 0;
    virtual void vfn_18() = 0;
    virtual void vfn_1c() = 0;
    virtual void vfn_20() = 0;
    virtual void vfn_24() = 0;
    virtual void vfn_28() = 0;
    virtual void vfn_2c() = 0;
    virtual void vfn_30() = 0;
    virtual void vfn_34() = 0;
    virtual void vfn_38() = 0;
    virtual void vfn_3c() = 0;
    virtual void vfn_40() = 0;
    virtual void vfn_44() = 0;
    virtual void vfn_48() = 0;
    virtual void vfn_4c() = 0;
    virtual void vfn_50() = 0;
    virtual void vfn_54() = 0;
    virtual void vfn_58() = 0;
    virtual void vfn_5c() = 0;
    virtual void vfn_60() = 0;
    virtual void vfn_64() = 0;
    virtual void vfn_68() = 0;
    virtual long CreateIndexBuffer(unsigned int, unsigned long, int, int, COMBaseInterface**, void*) = 0;
};

class NiConsoleIndexBufferManager__NiConsoleIBInfo;
class IndexBufferManager : public NiRefObject
{
  public:
    Direct3DDeviceInterface* m_pDirect3DDevice;
    COMBaseInterface* m_pCurrentIndexBuffer;
    unsigned int m_uiIndexBufferSize;
    COMBaseInterface* m_pPackedIndexBuffer;
    unsigned int m_uiPackedIndexBufferSize;
    NiTPointerMap<unsigned int, NiConsoleIndexBufferManager__NiConsoleIBInfo*> m_kIndexBufferMap;
    NiTPointerMap<unsigned int, NiConsoleIndexBufferManager__NiConsoleIBInfo*> m_kIndexBufferLookupMap;
    NiTPointerMap<unsigned int, NiConsoleIndexBufferManager__NiConsoleIBInfo*> m_kIndexBufferCacheMap;
    COMBaseInterface* PackBuffer(const unsigned short*, unsigned int, unsigned int, COMBaseInterface*, unsigned int&,
                                 unsigned long, unsigned int);
};

class NiD3DDefaultShader
{
  public:
};
#endif
