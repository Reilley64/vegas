// gamebryo2.2/corelibs/niconsolerenderer/niconsolepersistentsrctexturerendererdata_decls.h: declares FnvTextureReference, FnvTextureData
#ifndef FNV_NICONSOLEPERSISTENTSRCTEXTURERENDERERDATA_DECLS_H
#define FNV_NICONSOLEPERSISTENTSRCTEXTURERENDERERDATA_DECLS_H


#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_010f0000.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern void* __cdecl _NiMalloc(unsigned int size);
extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned long size);

extern unsigned char kVtbl_NiDX9IndexBufferManager;

class NiShader;
template <class T> class NiTPointerAllocator
{
};

template <class Allocator, class Key, class Value> class NiTMapBase
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_items;
    unsigned int m_uiCount;
    void RemoveAll();
};

typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*> FnvMap;

class FnvTextureReference
{
  public:
    void** m_ppVirtualMethodTable;
};

class FnvTextureData
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    FnvTextureReference* m_pkTexture;
    unsigned int m_u0c;
    unsigned int m_u10;
    unsigned int m_u14;
    unsigned int m_u18;
    FnvMap m_map1;
    FnvMap m_map2;
    FnvMap m_map3;
    unsigned char m_unused[0x48];

    FnvTextureData* AllocateData(FnvTextureReference* texture);
};

#endif
