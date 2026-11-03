// gamebryo2.2/corelibs/nimain/nitmap_decls.h: declares NiMapAllocator

#include "fnv/decl/ListX.h"
#include "fnv/symbols_006f9000.h"
#include "fnv/symbols_011d6000.h"
class BGSReconstructCellSubBlocksMap;
class CombatThreatRecord;
class TESGlobal;
class NiMapAllocator
{
  public:
};
class GlobalObject_004ee810
{
  public:
};
template <class K, class V> class NiTMap
{
    unsigned int mapHeader[3];
    NiMapAllocator allocator;

  public:
    void* NewItem();
    void NewItem(void* item);
    void FUN_00445370(void* item, int mode);
};
template <> class NiTMap<TESGlobal*, bool>
{
  public:
    static void NewItem();
};
