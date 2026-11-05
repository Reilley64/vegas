#include "fnv/symbols_00c74000.h"

#include <cmath>

// Returns acos(fValue), except returns 0.0f when |fValue| is at least 1 and positive, and pi when it is at least 1 and not positive.
// @fnv 0x00c74a70
float ClampedAcos(float fValue)
{
    if ((float)fabs(fValue) >= 1.0f)
        return (fValue > 0.0f) ? 0.0f : 3.1415927f;
    return (float)acos(fValue);
}
