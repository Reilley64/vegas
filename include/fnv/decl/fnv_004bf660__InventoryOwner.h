#pragma once

namespace fnv_004bf660 { struct InventoryEntry; }

namespace fnv_004bf660 {
struct InventoryOwner {
public:
    // 0x004bf660
    ::fnv_004bf660::InventoryEntry **CollectEntriesByRank(int, int);
};
}
