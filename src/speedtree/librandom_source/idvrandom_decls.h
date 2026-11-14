// speedtree/librandom_source/idvrandom_decls.h: declares RandomNumberGenerator, Random

#include <ctime>
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
