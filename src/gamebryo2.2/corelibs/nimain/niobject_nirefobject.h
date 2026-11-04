// gamebryo2.2/corelibs/nimain/niobject_nirefobject.h: declares NiRefObject
#ifndef FNV_NIOBJECT_UNIT_NIREFOBJECT_H
#define FNV_NIOBJECT_UNIT_NIREFOBJECT_H

#include <stddef.h>
#include "niobject_nimemobject.h"

// Declaration-only dependency view of supplied include/NiRefObject.h.
// No definitions of its destructor, DeleteThis, or reference-count methods.
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
};


#endif
