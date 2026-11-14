#include "NiAnimationKeyTables.h"

namespace NiAnimationKeyTables
{
// Zero until a key class registers, as in the original release.
Function g_functions[kNumTables][kNumSlots];
unsigned char g_keySizes[kNumSlots];
}
