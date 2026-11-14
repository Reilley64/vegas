// gamebryo2.2/corelibs/nianimation/nipoint3interpcontroller_decls.h: declares NiKeyBasedInterpolator, NiBoolInterpController
#include <cstddef>
#include <windows.h>
#include "fnv/symbols_0109a000.h"
#include "fnv/symbols_011f4000.h"
struct NiStream;
class NiBoolInterpolator;
class NiKeyBasedInterpolator
{
  public:
    NiKeyBasedInterpolator();
};
class NiBoolInterpController
{
  public:
};
extern unsigned int DAT_0109a0b4;

inline void* operator new(std::size_t, NiBoolInterpController& p)
{
    return &p;
}
