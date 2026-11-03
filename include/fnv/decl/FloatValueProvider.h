#pragma once

class SpellItem;
struct EdgeV;
template <class> class BSStringT;

struct FloatValueProvider {
public:
    // 0x0048d170
    bool FUN_0048d170(::SpellItem *);
    // 0x00510ea0
    void FUN_00510ea0(::BSStringT<char>);
    // 0x0068f040
    ::EdgeV FUN_0068f040(unsigned short, int);
};
