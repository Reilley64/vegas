// gamebryo2.2/corelibs/nimain/niobjectnet_bhk_decls.h: declares bhkConvexShape, bhkSphereShape
#ifndef NIOBJECTNET_BHK_DECLS_H
#define NIOBJECTNET_BHK_DECLS_H
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0056e000.h"
#include "fnv/symbols_01268000.h"
class bhkConvexShape
{
  public:
    bhkConvexShape();
    virtual ~bhkConvexShape();
};
class bhkSphereShape : public bhkConvexShape
{
  public:
    bhkSphereShape(float, bool);
    virtual ~bhkSphereShape();
};
#endif
