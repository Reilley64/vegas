// gamebryo2.2/corelibs/niconsolerenderer/nid3dpass_decls.h: declares BeamStage, SNAEntry, NiD3DPassPoolRecord, NiD3DPassAllocation, NiD3DPassPool and more
#ifndef NID3DPASS_DECLS_H
#define NID3DPASS_DECLS_H

#include "fnv/decl/ElemPtrArray.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/FUN_00e89410_Class.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0126f000.h"
extern "C" void* DAT_0126f710;
class BeamStage
{
  public:
    unsigned char m_pcBase[0x60];
    unsigned int m_uiRefCount;
};
struct SNAEntry
{
    unsigned int m_data[4];
    SNAEntry() throw();
    static void* operator new[](size_t bytes) throw();
};
class UnknownPoolReceiver
{
  public:
};
struct NiD3DPassPoolRecord
{
    unsigned int unknown0;
    unsigned int poolIndex;
    unsigned int state;
    unsigned int unknownC;
    UnknownPoolReceiver* pool;
};
struct NiD3DPassAllocation
{
    SNAEntry* entries;
    unsigned int count;
    unsigned int reserved;
};
class NiD3DPassPool
{
  public:
    NiD3DPass** entries;
    unsigned int capacity;
    unsigned int size;
    unsigned int reserved;
    unsigned int grow;
    NiD3DPass* Get()
    {
        unsigned int& available = size;
        if (!available)
        {
            unsigned int& growth = grow;
            reinterpret_cast<::ElemPtrArray *>(this)->FUN_00e80420(growth);
            growth *= 2;
        }
        NiD3DPass** base = entries;
        NiD3DPass* result = base[0];
        base[0] = base[--available];
        return result;
    }
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    static void ReleaseRenderStateGroup(D3DRenderStateGroup* group);
};
struct NiD3DPassRefObject
{
    virtual void vfn_00();
    virtual void DeleteThis();
    long refs;
};
template <class T> class NiTMallocInterface;
template <class T, class A> class NiTSet
{
  public:
    void Add(T& value);
};
#endif
