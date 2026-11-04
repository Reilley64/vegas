#pragma once
#include "havok/hkUlong.h"

namespace ArrowDraw { struct ArrowDrawVector; }

namespace ArrowDraw {
struct ArrowDrawObject {
public:
    // 0x00e10d50
    void FUN_00e10d50(const ::ArrowDraw::ArrowDrawVector *, const ::ArrowDraw::ArrowDrawVector *, const ::ArrowDraw::ArrowDrawVector *, int, float, hkUlong, int);
};
}
