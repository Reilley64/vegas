#ifndef NAVMESHARRAY_DECLS_H
#define NAVMESHARRAY_DECLS_H

#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_00464000.h"
class NavMesh;
template <class T> class NiPointer
{
  public:
    T* ptr;
    NiPointer(const NiPointer&);
    ~NiPointer();
};
typedef NiPointer<NavMesh> NavMeshPtr;
struct GlobalObject_00869f00
{
  public:
    NavMesh*& GetAt(unsigned int);
};
#endif
