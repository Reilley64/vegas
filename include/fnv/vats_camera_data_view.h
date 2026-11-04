#pragma once

// The VATS camera data object at g_011f2250: its target list and the VATS camera mode. The release build reads the
// mode through the folded 4-byte getter at 0x0044ddc0 (Twin_0044ddc0::GetName).
struct VATSCameraDataView
{
    void* targetsHead;
    void* targetsNext;
    unsigned int mode;
};
