// gamebryo2.2/corelibs/nimain/nistream_decls.h: declares NiStream
#ifndef FNV_NISTREAM_DECLS_H
#define FNV_NISTREAM_DECLS_H
#include "fnv/symbols_0044a000.h"
struct NiObject;
struct NiObject;
struct NiStream
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual unsigned int vfn_2c(const NiObject* object);
    void SaveLinkID(const NiObject* object);
public:
    ::NiObject *GetLoadedObject();
public:
    void ClearTopLevelObjects();
};
#endif
