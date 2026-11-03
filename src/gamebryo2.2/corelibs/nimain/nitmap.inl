
#include <cstdint>
#include "fnv/decl/ListX.h"
#include "fnv/decl/fnv_00445370__FUN_00445370_cls.h"
#include "fnv/symbols_006f9000.h"
#include "nitmap_decls.h"
template<>
// @fnv 0x00844a70
void* NiTMap<unsigned int, BGSReconstructCellSubBlocksMap*>::NewItem() {
    return ::FUN_006f99e0((void *)&(allocator));
}
// @fnv 0x00975cf0
void NiTMap<TESGlobal*, bool>::NewItem() {
    reinterpret_cast<::ListX *>(&(g_011d6a30))->FUN_004ee920();
    DAT_011d6a20 = 0;
}
template<>
// @fnv 0x0048eff0
void NiTMap<unsigned int, CombatThreatRecord*>::NewItem(void* item) {
    reinterpret_cast<::fnv_00445370::FUN_00445370_cls *>(this)->FUN_00445370((uintptr_t)(item), 1);
}
