#include "havok/CylinderSettings.h"
#include "havok/ScalarConstants.h"

float DAT_011b5be0 = 2.6874115f;
float DAT_011b5be4 = 0.37210527f;
double DAT_010d0f08 = 0.7070000171661377;

// Converts a bit count to bytes, computes a normalized scale from it, and stores the scale and its reciprocal in two globals.
// @fnv 0x00d57160
void ComputeByteScale(int bits)
{
    int bytes = bits / 8;
    float v = (float)(((double)bytes - ::DAT_0101ffa0) / DAT_010d0f08);
    DAT_011b5be0 = v;
    DAT_011b5be4 = 1.0f / v;
}
