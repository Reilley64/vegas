// gamebryo2.2/corelibs/nisystem/nimemorydefines_decls.h: declares NiAllocator, NiMemoryManagerState
#include "fnv/symbols_011f6000.h"
class NiAllocator
{
  public:
    virtual void vfn_00();
    virtual void* vfn_04(unsigned int& size, unsigned int& alignment, int event, bool accurateSize, const char* file,
                         int line, const char* function);
};
struct NiMemoryManagerState
{
    NiAllocator* allocator;
};
