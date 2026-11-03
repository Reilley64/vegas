#pragma once

struct CtxRec;
struct ItemListRec;

class ListWalker {
public:
    // 0x00d9df50
    ::ListWalker *InitWalker(::ItemListRec *, ::CtxRec *);
};
