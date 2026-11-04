#pragma once

class Tile;
namespace ActorValue { enum Index; }
struct FUN_007a62e0;

struct ItemBox {
public:
    // 0x007e1430
    ::Tile *FUN_007e1430(::ActorValue::Index, const char *, int (*)(FUN_007a62e0 *, FUN_007a62e0 *), const char *);
};
