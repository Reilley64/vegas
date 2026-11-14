// bscore/bsrandom.h
//
// Engine random-number service. The class wraps a 624-word Mersenne Twister
// state (m_uiSeed/m_uiLastValue/mt/mti).

#ifndef FNV_BSCORE_BSRANDOM_H
#define FNV_BSCORE_BSRANDOM_H


class MersenneTwister
{
  public:
    MersenneTwister();
    void Init(unsigned int seed);
    void Seed(unsigned int seed);
    void FUN_00aa5170(unsigned int seed);
    unsigned int GetRandomUInt(unsigned int bound);
    bool Bool(float chance);
    float Float0To1();
    unsigned int FUN_00476be0();
    float FUN_00476b90(float minimum, float maximum);
    int IntInRange(int minimum, int maximum);
    float FUN_004a4260();
    float FUN_004dfec0();
    float FUN_006d1620();
    float FloatNeg1To1();
    float FloatNegPiToPi();
    float FloatTwoPi();
    void Kill();
    static MersenneTwister* GetRandomGenerator();

    unsigned int m_uiSeed;
    unsigned int m_uiLastValue;
    unsigned int mt[624];
    unsigned int mti;
};

#endif
