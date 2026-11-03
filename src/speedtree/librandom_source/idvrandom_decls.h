// speedtree/librandom_source/idvrandom_decls.h: declares RandomNumberGenerator, Random

#include "fnv/symbols_00b43000.h"
class RandomNumberGenerator
{
  public:
    RandomNumberGenerator();
    void SeedRandomGenerator(long seed);
};
class Random
{
  public:
    static void Set(double seed);
};
extern bool DAT_011f8eb8;
extern "C" __int64 __cdecl _time64(__int64*);
