#pragma once

class FormChangeMask {
public:
    // 0x00841120
    static ::FormChangeMask HasFormChanged(::FormChangeMask, ::FormChangeMask, int, bool);
};
