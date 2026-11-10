// Authored declaration for the Nif particle stream helper closure.
#ifndef FNV_NISTREAM_H
#define FNV_NISTREAM_H

#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "NiObject.h"

struct NiObject;
struct NiStream : public NiObject
{
  public:
    unsigned int GetLinkIDFromObject(const NiObject* pkObject);
    NiObject* DeserializeObject();
    NiObject* GetLoadedObject(unsigned int uiLinkID);
public:
    ::NiObject *GetLoadedObject();
};
#endif
