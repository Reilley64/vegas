#pragma once

// Shared process-lifetime tessellation factor and reciprocal. The independent
// constructor/lazy-init bias is deliberately not part of this storage owner.
extern float DAT_011b5be0;
extern float DAT_011b5be4;

// Mutable double input read by the retained scale producer. No parameter
// validation or interpretation beyond the supplied arithmetic is imposed here.
extern double DAT_010d0f08;

void ComputeByteScale(int bits);
