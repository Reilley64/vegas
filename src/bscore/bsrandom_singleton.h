// bscore/bsrandom_singleton.h: declares MersenneTwister
#ifndef FNV_BSRANDOM_SINGLETON_H
#define FNV_BSRANDOM_SINGLETON_H
#include <cstddef>

#include "fnv/symbols_011c5000.h"
void* __cdecl operator new(std::size_t);
void __cdecl operator delete(void*);
namespace bsrandom_singleton {
class MersenneTwister
{
  public:
    MersenneTwister();
    static MersenneTwister* GetRandomGenerator();

  private:
    unsigned char state[40];
};
}
#endif
