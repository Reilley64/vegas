
// src/bsshader/speedtreeleafshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/speedtreeleafshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.



// Base of the object: a NiRefObject-like polymorphic base whose constructor is
#include <windows.h>
class NiRefObject
{
  public:
    virtual void v0();

    int m_kPointA;

    NiRefObject();
public:
    static unsigned int ms_lObjectCount;
};

struct FUN_00bb33c0 : NiRefObject
{
    int m_kPointB;
    unsigned short m_iThirdValue;

    FUN_00bb33c0();
    virtual ~FUN_00bb33c0();
};

NiRefObject::NiRefObject()
{
    m_kPointA = 0;
    InterlockedIncrement(&(*reinterpret_cast<long *>(&::NiRefObject::ms_lObjectCount)));
}

// @fnv 0x00bb33c0
FUN_00bb33c0::FUN_00bb33c0()
{
    m_kPointB = 0;
    m_iThirdValue = 0;
}
