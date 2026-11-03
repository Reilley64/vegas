// bscore/bsrandom_singleton.h: declares MersenneTwister
#ifndef FNV_BSRANDOM_SINGLETON_H
#define FNV_BSRANDOM_SINGLETON_H

#include "fnv/symbols_011c5000.h"
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
