#pragma once

class FormChangeMask {
public:
    unsigned int flags;
    // 0x00841120
    static ::FormChangeMask HasFormChanged(::FormChangeMask, ::FormChangeMask, int, bool);
};
