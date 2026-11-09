#include "AutoMemContext.h"
// fallout_shared/speedtree/bstreemanager_decls.h: declares AutoMemContext, MemoryManager
#ifndef BSTREEMANAGER_DECLS_H
#define BSTREEMANAGER_DECLS_H

#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011fd000.h"
#include "layout_support.h"
#include <new>
class NiAVObject;
class NiNode;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    operator NiAVObject*() const;
};
template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer<NiNode>& operator=(NiNode* object);
};
#include "bstreemanager_types_BSTreeManager.h"
#include "bstreemanager_types_TES.h"
using ::AutoMemContext;
class MemoryManager
{
  public:
};
void FUN_00664940();
void* FUN_00664840(bool);
void SetGlobalFloatFromUInt(unsigned int);
void ClampAndStoreValue(float);
extern float DAT_011adce0;
#endif
