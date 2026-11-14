
// src/havok/animation/animation/animation/util/hkatrackanalysis.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/util/hkatrackanalysis.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_simd.h"
#include <new>
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cc02d0_cls.h"
#include "fnv/decl/FloatArgStream.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/fnv_00e50ca0__FUN_00e50ca0_cls.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00e4e000.h"
#include "fnv/symbols_01268000.h"
struct TrackAnalysis
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int count;
    int sum;
    int max;
};

// Accumulates bit counts from each value shifted right by 6 into result->count, result->sum and result->max.
// @fnv 0x00e4e570
void AnalyzeTrackBits(const unsigned short* values, unsigned int count, TrackAnalysis* result)
{
    result->count = 0;
    result->sum = 0;
    result->max = 0;
    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int uiBits = values[i] >> 6;
        result->count += ((uiBits >> 2) & 1) + ((uiBits >> 1) & 1) + (uiBits & 1);
        result->sum += ((uiBits >> 6) & 1) + ((uiBits >> 5) & 1) + ((uiBits >> 4) & 1) + ((uiBits >> 3) & 1);
        result->max += ((uiBits >> 9) & 1) + ((uiBits >> 8) & 1) + ((uiBits >> 7) & 1);
    }
}

void AnalyzeTrackBits(const unsigned short* values, unsigned int count, TrackAnalysis* result);

// Analyzes the first value range via AnalyzeTrackBits, then counts zero entries in values and stores the count at result+0x28.
// @fnv 0x00e4e610
void AnalyzeTrackWithZeroCount(const unsigned short* aFirstValues, const unsigned short* values,
                               unsigned int firstCount, unsigned int count, TrackAnalysis* result)
{
    AnalyzeTrackBits(aFirstValues, firstCount, result);
    int* piZeroCount = (int*)((char*)result + 0x28);
    *piZeroCount = 0;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (values[i] == 0)
        {
            ++*piZeroCount;
        }
    }
}

struct TraceSink
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void write(int, int, const char*, const char*, int);
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void begin(unsigned int, const char*);
    virtual void end();
};
extern const char str_010ec758[];
extern const char str_010ec724[];
extern const char str_010ec74c[];
extern const char str_010ec70c[];
extern const char str_010ec6f4[];
extern const char str_010ec6e0[];
extern const char str_010ec6cc[];
extern const char str_010ec6b4[];
extern const char str_010ec69c[];
extern const char str_010ec688[];
extern const char str_010ec670[];
extern const char str_010ec658[];
extern const char str_010ec644[];
extern const char str_010ec6f40[];
extern const char str_010ec624[];
struct TextBuilder
{
    int state;
    int length;
    int bufferCapacity;
};
struct TrackStatistics
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
    int field8;
    int field9;
    int field10;
    int total0;
    int total1;
    float rate;
    void LogStatistics();
};
// Formats each statistic field and the rate into a text buffer and writes them to the trace sink, then ends the trace.
// @fnv 0x00e4e660
void TrackStatistics::LogStatistics()
{
    {
        TextBuilder textBuilder;
        char* outputWords[128];
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->begin(0x432434a4u, str_010ec758);
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec74c)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 47);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec70c)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 48);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec6f4)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 49);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec6e0)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 50);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec6cc)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 51);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec6b4)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 52);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec69c)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 53);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec688)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 54);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec670)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 55);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec658)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 56);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec644)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 57);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FUN_00cc02d0_cls *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec6f40)))))->FUN_00cc02d0({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 58);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
        new ((void *)&(textBuilder)) ::FUN_00cb1600(reinterpret_cast<char*>(outputWords), 512);
        reinterpret_cast<::FloatArgStream *>((((::TextBuilder *)(reinterpret_cast<::SinkOwner *>(&(textBuilder))->FUN_00cc01c0(str_010ec624)))))->WriteFloat({});
        (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->write(0, -1, reinterpret_cast<char*>(outputWords), str_010ec724, 59);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(textBuilder))->FUN_00cc00e0::~FUN_00cc00e0();
    }
    return (*reinterpret_cast<::TraceSink * *>(&::DAT_01268360))->end();
}


struct hkMemoryAllocator_e50650;

struct hkMemoryRouter_e50650
{
    void* m_acPad00[4];
    hkMemoryAllocator_e50650* m_pkHeap;
    hkMemoryAllocator_e50650& heap()
    {
        return *m_pkHeap;
    }
};

struct hkContainerHeapAllocator_e50650
{
    hkMemoryAllocator_e50650& get(const void*)
    {
        return ((hkMemoryRouter_e50650*)FUN_00c85750())->heap();
    }
};

template <class T> struct hkArray_e50650
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray_e50650() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void reserve(hkMemoryAllocator_e50650& kAllocator, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap = 2 * iCapacity;
            int iNewSize = (n < iCap) ? iCap : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAllocator), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    void _setSize(hkMemoryAllocator_e50650& kAllocator, int n)
    {
        reserve(kAllocator, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        _setSize(hkContainerHeapAllocator_e50650().get(this), n);
    }
};

struct TrackHeader_e50650
{
    int m_iUnk00;
    int m_iArrayLength;
    int m_iUnk08;
};

struct TrackSource_e50650
{
    TrackHeader_e50650 m_kHeader;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    float m_fD;
    unsigned char m_ucE;
};

struct TrackBuffers_e50650
{
    TrackHeader_e50650 m_kHeader;
    hkArray_e50650<float> m_kA;
    hkArray_e50650<float> m_kB;
    hkArray_e50650<float> m_kC;
    hkArray_e50650<float> m_kCubicCoefficient;
    hkArray_e50650<unsigned char> m_kE;

};

struct hkBool_e50650
{
    char m_cBooleanValue;
    hkBool_e50650(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

void FUN_00e4f910(TrackBuffers_e50650* pkBuffers, void* pkArg, void* pkArgCur, hkBool_e50650 bFlag);

// @fnv 0x00e50650
void ExpandTrackSource(const TrackSource_e50650* pkSource, void* pkArg, void* pkArgCur)
{
    TrackBuffers_e50650 kBuffers;
    int iCount = pkSource->m_kHeader.m_iArrayLength;
    kBuffers.m_kHeader.m_iUnk00 = pkSource->m_kHeader.m_iUnk00;
    kBuffers.m_kHeader.m_iArrayLength = iCount;
    kBuffers.m_kHeader.m_iUnk08 = pkSource->m_kHeader.m_iUnk08;
    kBuffers.m_kA.SetSizeAndGrow(iCount);
    kBuffers.m_kB.SetSizeAndGrow(iCount);
    kBuffers.m_kC.SetSizeAndGrow(iCount);
    kBuffers.m_kCubicCoefficient.SetSizeAndGrow(iCount);
    kBuffers.m_kE.SetSizeAndGrow(iCount);
    for (int i = 0; i < iCount; i++)
    {
        kBuffers.m_kA.m_data[i] = pkSource->m_fCoefficientA;
        kBuffers.m_kB.m_data[i] = pkSource->m_fB;
        kBuffers.m_kC.m_data[i] = pkSource->m_fC;
        kBuffers.m_kCubicCoefficient.m_data[i] = pkSource->m_fD;
        kBuffers.m_kE.m_data[i] = pkSource->m_ucE;
    }
    FUN_00e4f910(&kBuffers, pkArg, pkArgCur, true);
    reinterpret_cast<::fnv_00e50ca0::FUN_00e50ca0_cls *>(&(kBuffers))->FUN_00e50ca0();
}

struct StatsB0
{
    unsigned int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30;
    float m_34;
};
__declspec(noinline) void __cdecl Analyze(const unsigned short* p, unsigned int count, StatsB0* s)
{
    for (unsigned int i = 0; i < count; i++)
        s->m_1c += p[i] & 3;
}
__declspec(noinline) void __cdecl CountTail(const unsigned short* p, void* a1, unsigned int count, unsigned int a3,
                                            StatsB0* s)
{
    Analyze(p, count, s);
    Analyze((const unsigned short*)a1, a3, s);
}
// Initializes selected StatsB0 fields, counts mask values from both inputs, and computes derived fields and a ratio in m_34.
// @fnv 0x00e4ebb0
void __cdecl FUN_00e4ebb0(const unsigned short* apFirst, void* apSecond, unsigned int aiFirstCount,
                          unsigned int aiSecondCount, StatsB0* psStats)
{
    psStats->m_34 = 0.0f;
    psStats->m_30 = aiSecondCount;
    psStats->m_2c = aiFirstCount * 10;
    unsigned int* pCounters = &psStats->m_iWordAt00;
    pCounters[0] = 0;
    pCounters[1] = 0;
    pCounters[2] = 0;
    pCounters[4] = 0;
    pCounters[5] = 0;
    pCounters[6] = 0;
    pCounters[10] = 0;
    for (unsigned int i = 0; i < aiFirstCount; i++)
    {
        if ((apFirst[i] & 3) == 2)
            psStats->m_10 += 3;
        if ((apFirst[i] & 0xc) == 8)
            psStats->m_14 += 4;
        if ((apFirst[i] & 0x30) == 0x20)
            psStats->m_18 += 3;
    }
    CountTail(apFirst, apSecond, aiFirstCount, aiSecondCount, psStats);
    psStats->m_iWordAt00 = aiFirstCount * 3 - psStats->m_10 - psStats->m_1c;
    psStats->m_iWordAt04 = aiFirstCount * 4 - psStats->m_20 - psStats->m_14;
    psStats->m_8 = aiFirstCount * 3 - psStats->m_18 - psStats->m_24;
    psStats->m_iThirdValue = aiSecondCount - psStats->m_28;
    unsigned int sum = psStats->m_1c + psStats->m_20 + psStats->m_24 + psStats->m_28;
    if (sum)
    {
        unsigned int num = psStats->m_30;
        num += psStats->m_2c;
        psStats->m_34 = (float)num / (float)sum;
    }
    else
        psStats->m_34 = 0.0f;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00e4f640 {


struct TrackData
{
    unsigned int numTransforms;
    unsigned int numFloats;
    const unsigned short* transformMasks;
    const unsigned short* floatMasks;
    const float* staticData;
    const float* staticFloats;
    const float* dynamicData;
    const float* dynamicFloats;
};
extern const __declspec(align(16)) float DAT_010c71b0[4];
extern const float DAT_01012068;
extern const float DAT_010ec620;
static float readComponent(const float*& stat, const float*& dynamic, unsigned int isDynamic)
{
    return isDynamic ? *dynamic++ : *stat++;
}
// Decodes transform and float tracks from static/dynamic data into 12-float transforms and a float array, using masks to select sources and defaults.
// @fnv 0x00e4f640
void FUN_00e4f640(const TrackData* apTrackData, float* transforms, float* floats)
{
    const float* staticData = apTrackData->staticData;
    const float* dynamicData = apTrackData->dynamicData;
    for (unsigned int i = 0; i < apTrackData->numTransforms; ++i)
    {
        float* p = transforms + i * 12;
        unsigned int mask = apTrackData->transformMasks[i];
        unsigned int flags = mask >> 6;
        if ((mask & 3) != 2)
        {
            p[0] = readComponent(staticData, dynamicData, flags & 4);
            p[1] = readComponent(staticData, dynamicData, flags & 2);
            p[2] = readComponent(staticData, dynamicData, flags & 1);
        }
        else
        {
            _mm_store_ps(p, _mm_setzero_ps());
        }
        if ((mask & 0x0c) != 8)
        {
            float x = readComponent(staticData, dynamicData, flags & 0x40);
            p[4] = x;
            float y = readComponent(staticData, dynamicData, flags & 0x20);
            p[5] = y;
            float z = readComponent(staticData, dynamicData, flags & 0x10);
            p[6] = z;
            float w = readComponent(staticData, dynamicData, flags & 8);
            p[7] = w;
            if ((float)fabs(w) == 2.0f)
            {
                float lenSq = x * x + y * y + z * z;
                if (lenSq > 1.0f)
                    lenSq = 1.0f;
                if (w > 0.0f)
                    p[7] = (float)sqrt(1.0f - lenSq);
                else
                    p[7] = -(float)sqrt(1.0f - lenSq);
            }
        }
        else
        {
            _mm_store_ps(p + 4, _mm_load_ps(DAT_010c71b0));
        }
        if ((mask & 0x30) != 0x20)
        {
            p[8] = readComponent(staticData, dynamicData, flags & 0x200);
            p[9] = readComponent(staticData, dynamicData, flags & 0x100);
            p[10] = readComponent(staticData, dynamicData, flags & 0x80);
        }
        else
        {
            _mm_store_ps(p + 8, _mm_set_ps1(1.0f));
        }
    }
    const float* staticFloats = apTrackData->staticFloats;
    const float* dynamicFloats = apTrackData->dynamicFloats;
    for (unsigned int iFloat = 0; iFloat < apTrackData->numFloats; ++iFloat)
    {
        if (apTrackData->floatMasks[iFloat] == 0)
            floats[iFloat] = *dynamicFloats++;
        else
            floats[iFloat] = *staticFloats++;
    }
}
}  // namespace fnv_00e4f640

struct PerTransformIn
{
    const void* boneData;
    unsigned int numberOfTransformTracks;
    unsigned int numberOfPoses;
};

struct PerFloatIn
{
    const float* floatData;
    unsigned int numberOfFloatTracks;
    unsigned int numberOfPoses;
    hkArray_e50650<float> absoluteTolerance;
};

struct hkMemoryAllocator_e50650
{
    virtual void AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void* BufRealloc(void*, int, int&);
    virtual void ReturnMemory(void*, int);
};

struct E50920Router
{
    char* stackTop;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator_e50650* heap;
};

static __forceinline void ClearStatistics(TrackStatistics& s)
{
    s.field0 = 0;
    s.field1 = 0;
    s.field2 = 0;
    s.field3 = 0;
    s.field4 = 0;
    s.field5 = 0;
    s.field6 = 0;
    s.field7 = 0;
    s.field8 = 0;
    s.field9 = 0;
    s.field10 = 0;
    s.total0 = 0;
    s.total1 = 0;
    s.rate = 0.0f;
}

struct PassBool
{
    unsigned char value;
    PassBool(bool b) : value(b)
    {}
    PassBool(const PassBool& other) : value(other.value)
    {}
};

typedef void(__cdecl* QsAnalyzeFn)(TrackBuffers_e50650*, void*, void*, PassBool);

void __cdecl FUN_00e4ead0(const unsigned short* mask, unsigned int count, TrackStatistics* result);
void __cdecl FUN_00e4ebb0(const unsigned short* maskT, const unsigned short* maskF, unsigned int numT,
                          unsigned int numF, TrackStatistics* result);

struct FloatLocalArray
{
    hkArray_e50650<float> values;
    float* localMemory;

    __forceinline void allocate(int n)
    {
        E50920Router* router = (E50920Router*)FUN_00c85750();
        char* block = router->stackTop;
        router->stackTop = block + ((n * 4 + 127) & ~127);
        values.m_iCapacityState = n | 0x80000000;
        values.m_data = (float*)block;
        localMemory = (float*)block;
    }

    __forceinline void freeStorage(hkMemoryAllocator_e50650& alloc)
    {
        int cap = values.m_iCapacityState;
        values.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReturnMemory(values.m_data, (cap & 0x3fffffff) * 4);
        }
        values.m_data = 0;
        values.m_iCapacityState = 0x80000000;
    }

    __forceinline void release()
    {
        float* saved = localMemory;
        if (saved == values.m_data)
        {
            values.m_iElementCount = 0;
        }
        ((E50920Router*)FUN_00c85750())->stackTop = (char*)saved;
        freeStorage(hkContainerHeapAllocator_e50650().get(&values));
    }
};

// Computes per-track min/max over poses, marks float tracks static when range is below tolerance, and optionally logs statistics.
// @fnv 0x00e50920
void __cdecl FUN_00e50920(const PerTransformIn& input, const PerFloatIn& apFloatIn, unsigned short* staticMask,
                          float* staticDOFs, hkBool_e50650 displayStatsReport)
{
    ((QsAnalyzeFn)FUN_00e4f910)((TrackBuffers_e50650*)&input, staticMask, staticDOFs, PassBool(false));
    TrackStatistics statistics;
    ClearStatistics(statistics);
    FUN_00e4ead0(staticMask, input.numberOfTransformTracks, &statistics);
    float* pStaticDOF = staticDOFs + statistics.field0 + statistics.field1 + statistics.field2;
    FloatLocalArray minimum;
    minimum.allocate(apFloatIn.numberOfFloatTracks);
    minimum.values.SetSizeAndGrow(apFloatIn.numberOfFloatTracks);
    FloatLocalArray maximum;
    maximum.allocate(apFloatIn.numberOfFloatTracks);
    maximum.values.SetSizeAndGrow(apFloatIn.numberOfFloatTracks);
    for (unsigned int track = 0; track < apFloatIn.numberOfFloatTracks; ++track)
    {
        float tolerance = apFloatIn.absoluteTolerance.m_data[track];
        minimum.values.m_data[track] = 3.40282e+38f;
        maximum.values.m_data[track] = -3.40282e+38f;
        for (unsigned int pose = 0; pose < input.numberOfPoses; ++pose)
        {
            float value = apFloatIn.floatData[pose * apFloatIn.numberOfFloatTracks + track];
            if (value < minimum.values.m_data[track])
                minimum.values.m_data[track] = value;
            if (value > maximum.values.m_data[track])
                maximum.values.m_data[track] = value;
        }
        float midpoint = (minimum.values.m_data[track] + maximum.values.m_data[track]) * 0.5;
        float range = fabsf(maximum.values.m_data[track] - minimum.values.m_data[track]);
        float threshold = (float)(tolerance * 2.0);
        if (range < threshold)
        {
            staticMask[input.numberOfTransformTracks + track] = 1;
            *pStaticDOF++ = midpoint;
        }
        else
        {
            staticMask[input.numberOfTransformTracks + track] = 0;
        }
    }
    if (displayStatsReport.m_cBooleanValue)
    {
        const PerTransformIn* __restrict src = &input;
        ClearStatistics(statistics);
        FUN_00e4ebb0(staticMask, staticMask + src->numberOfTransformTracks, src->numberOfTransformTracks,
                     apFloatIn.numberOfFloatTracks, &statistics);
        statistics.LogStatistics();
    }
    maximum.release();
    minimum.release();
}

struct StatisticsResult
{
    unsigned int field0, field1, field2, field3, field4, field5, field6, field7, field8, field9, field10, total0,
        total1;
    float rate;
    void LogStatistics();
};
__declspec(noinline) void AnalyzeTrackBits(const unsigned short* values, unsigned int count, StatisticsResult* result)
{
    result->field7 = 0;
    result->field8 = 0;
    result->field9 = 0;
    for (unsigned int i = 0; i < count; i++)
    {
        unsigned int v = values[i] >> 6;
        result->field7 += ((v >> 2) & 1) + ((v >> 1) & 1) + (v & 1);
        result->field8 += ((v >> 6) & 1) + ((v >> 5) & 1) + ((v >> 4) & 1) + ((v >> 3) & 1);
        result->field9 += ((v >> 9) & 1) + ((v >> 8) & 1) + ((v >> 7) & 1);
    }
}
// Accumulates bit-field counts from mask values, calls FUN_00e4e570 for remaining fields, and computes a rate from total0 and the summed counts.
// @fnv 0x00e4ead0
void __cdecl FUN_00e4ead0(const unsigned short* mask, unsigned int count, StatisticsResult* result)
{
    result->rate = 0.0f;
    StatisticsResult* pResult = result;
    pResult->total0 = count * 10;
    pResult->total1 = 0;
    pResult->field0 = 0;
    pResult->field1 = 0;
    pResult->field2 = 0;
    pResult->field3 = 0;
    pResult->field4 = 0;
    pResult->field5 = 0;
    pResult->field6 = 0;
    pResult->field10 = 0;
    for (unsigned int i = 0; count > i; i++)
    {
        if (((*(mask + i)) & 3) == 2)
            result->field4 += 3;
        if ((0xc & (*(mask + i))) == 8)
            result->field5 += 4;
        if ((0x30 & mask[i]) == 0x20)
            result->field6 += 3;
    }
    AnalyzeTrackBits(mask, count, result);
    result->field0 = 3 * count - pResult->field7 - pResult->field4;
    result->field1 = count * 4 - pResult->field5 - pResult->field8;
    result->field2 = count * 3 - pResult->field9 - result->field6;
    if (pResult->field9 + (pResult->field7 + pResult->field8) > 0)
        pResult->rate = (float)result->total0 / (float)(pResult->field9 + (pResult->field7 + pResult->field8));
    else
        result->rate = 0.0f;
}

void FUN_00c908c0(hkMemoryAllocator_e50650& kAllocator, void* pkArray, intptr_t iNewCapacity, int iElementSize);

extern unsigned char DAT_011be718[16];

class TrackScalar
{
    __m128 number;

  public:
    TrackScalar()
    {}
    TrackScalar(const __m128& value) : number(value)
    {}
    TrackScalar(float value)
    {
        number = _mm_load_ss(&value);
    }
    operator float() const
    {
        float result;
        _mm_store_ss(&result, number);
        return result;
    }
    __forceinline const __m128& raw() const
    {
        return number;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(number, number, 0);
    }
};

class TrackComparison
{
    __m128 lanes;
    friend class TrackVector;

  public:
    enum Mask
    {
        XYZ = 7,
        XYZW = 15
    };
    __forceinline int GetLaneMask(Mask wanted) const
    {
        return _mm_movemask_ps(lanes) & wanted;
    }
    __forceinline int allSet(Mask wanted) const
    {
        return (_mm_movemask_ps(lanes) & wanted) == wanted;
    }
};

class TrackVector
{
    __m128 lanes;

  public:
    operator __m128() const
    {
        return lanes;
    }
    __forceinline __m128& raw()
    {
        return lanes;
    }
    __forceinline const __m128& raw() const
    {
        return lanes;
    }
    __forceinline void operator=(const TrackVector& other)
    {
        lanes = other.lanes;
    }
    __forceinline void operator=(const __m128& other)
    {
        raw() = other;
    }
    __forceinline float& operator()(int axis)
    {
        return reinterpret_cast<float*>(this)[axis];
    }
    __forceinline const float& operator()(int axis) const
    {
        return reinterpret_cast<const float*>(this)[axis];
    }
    __forceinline void fill(float value)
    {
        lanes = _mm_set_ps1(value);
    }
    __forceinline void fill3(float value)
    {
        lanes = _mm_set_ps1(value);
    }
    __forceinline void zero()
    {
        lanes = _mm_setzero_ps();
    }
    __forceinline void minimum(const TrackVector& left, const TrackVector& right)
    {
        lanes = _mm_min_ps(left.lanes, right.lanes);
    }
    __forceinline void maximum(const TrackVector& left, const TrackVector& right)
    {
        lanes = _mm_max_ps(left.lanes, right.lanes);
    }
    __forceinline void subtract(const TrackVector& left, const TrackVector& right)
    {
        lanes = _mm_sub_ps(left.lanes, right.lanes);
    }
    __forceinline void absolute(const TrackVector& other)
    {
        lanes = _mm_and_ps(other.lanes, DAT_01017d10);
    }
    __forceinline void multiply(const TrackScalar& factor, const TrackVector& other)
    {
        lanes = _mm_mul_ps(factor.broadcast(), other.lanes);
    }
    __forceinline void multiply(const TrackScalar& factor)
    {
        lanes = _mm_mul_ps(factor.broadcast(), lanes);
    }
    __forceinline void accumulate(const TrackScalar& factor, const TrackVector& other)
    {
        lanes = _mm_add_ps(lanes, _mm_mul_ps(factor.broadcast(), other.lanes));
    }
    __forceinline TrackScalar dot3(const TrackVector& other) const
    {
        __m128 products = _mm_mul_ps(lanes, other.lanes);
        __m128 first = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 170), first);
    }
    __forceinline TrackScalar dot4(const TrackVector& other) const
    {
        __m128 products = _mm_mul_ps(lanes, other.lanes);
        __m128 pairs = _mm_add_ps(_mm_shuffle_ps(products, products, 78), products);
        __m128 exchanged = _mm_shuffle_ps(pairs, pairs, 177);
        return _mm_add_ps(pairs, exchanged);
    }
    __forceinline TrackScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline TrackScalar lengthSquared4() const
    {
        return dot4(*this);
    }
    __forceinline TrackScalar reciprocalLength4() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zeroValue = _mm_set_ss(0.0f);
        const __m128 squared = dot4(*this).raw();
        const __m128 isZero = _mm_cmpeq_ss(squared, zeroValue);
        const __m128 estimate = _mm_rsqrt_ss(squared);
        const __m128 correction = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                             _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
        return _mm_andnot_ps(isZero, correction);
    }
    __forceinline void normalize4()
    {
        __m128 factor = reciprocalLength4().broadcast();
        lanes = _mm_mul_ps(factor, lanes);
    }
    __forceinline TrackComparison compare(const TrackVector& other) const
    {
        TrackComparison result;
        result.lanes = _mm_cmple_ps(lanes, other.lanes);
        return result;
    }
    inline int equals3(const TrackVector& other, float tolerance) const
    {
        TrackVector difference;
        difference.subtract(*this, other);
        difference.absolute(difference);
        TrackVector limit;
        limit.fill3(tolerance);
        return difference.compare(limit).allSet(TrackComparison::XYZ);
    }
    inline int equals4(const TrackVector& other, float tolerance) const
    {
        TrackVector difference;
        difference.subtract(*this, other);
        difference.absolute(difference);
        TrackVector limit;
        limit.fill(tolerance);
        return difference.compare(limit).allSet(TrackComparison::XYZW);
    }
    inline int majorAxis() const
    {
        TrackVector magnitude;
        magnitude.absolute(*this);
        return magnitude(0) < magnitude(1) ? (magnitude(1) < magnitude(2) ? 2 : 1)
                                           : (magnitude(0) < magnitude(2) ? 2 : 0);
    }
    static inline const TrackVector& zeroValue()
    {
        return reinterpret_cast<const TrackVector&>((*reinterpret_cast<const ::__m128 *>(&::DAT_01267e30)));
    }
};

class TrackQuaternion
{
  public:
    TrackVector vector;
    inline TrackQuaternion()
    {}
    inline void operator=(const TrackQuaternion& other)
    {
        vector = other.vector;
    }
    inline const float& operator()(int axis) const
    {
        return vector(axis);
    }
    inline void identity()
    {
        vector.raw() = DAT_010c71b0;
    }
    inline void normalize()
    {
        vector.normalize4();
    }
};

class TrackTransform
{
  public:
    static __forceinline void* operator new(std::size_t, void* memory)
    {
        return memory;
    }
    TrackVector translation;
    TrackQuaternion rotation;
    TrackVector scale;
    __forceinline const TrackVector& position() const
    {
        return translation;
    }
    __forceinline const TrackQuaternion& orientation() const
    {
        return rotation;
    }
    __forceinline const TrackVector& scaling() const
    {
        return scale;
    }
    __forceinline void zero()
    {
        translation.zero();
        rotation.vector.zero();
        scale.zero();
    }
    __forceinline void addWeighted(const TrackTransform& other, const TrackScalar& weight)
    {
        translation.accumulate(weight, other.translation);
        scale.accumulate(weight, other.scale);
        const TrackScalar signedWeight = rotation.vector.dot4(other.rotation.vector) < 0.0f ? TrackScalar(-weight) : weight;
        rotation.vector.accumulate(signedWeight, other.rotation.vector);
    }
    __forceinline void finish(const TrackScalar& total)
    {
        if (fabsf(total) < 1.1920928955078125e-7f)
        {
            translation.zero();
            rotation.identity();
            scale.fill(1.0f);
            return;
        }
        {
            const TrackScalar reciprocal = TrackScalar(1.0f) / total;
            translation.multiply(reciprocal);
            scale.multiply(reciprocal);
        }
        {
            const float rotationNorm = rotation.vector.lengthSquared4();
            if (rotationNorm < 1.1920928955078125e-7f)
                rotation.identity();
            else
                rotation.normalize();
        }
        {
            const float scaleNorm = scale.lengthSquared3();
            if (scaleNorm < 1.1920928955078125e-7f)
                scale.fill(1.0f);
        }
    }
};

class TrackFlag
{
    char value;

  public:
    inline TrackFlag()
    {}
    inline TrackFlag(bool input) : value(static_cast<char>(input))
    {}
    inline operator bool() const
    {
        return value != 0;
    }
    inline TrackFlag& operator=(bool input)
    {
        value = static_cast<char>(input);
        return *this;
    }
};

template <class T> struct TrackArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline TrackArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~TrackArrayBase()
    {}
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
    __forceinline const T& operator[](int index) const
    {
        return data[index];
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator_e50650& allocator, int count)
    {
        const int oldCapacity = getCapacity();
        if (oldCapacity < count)
        {
            int doubled = 2 * oldCapacity;
            int grown = count < doubled ? doubled : count;
            FUN_00c908c0(allocator, this, grown, sizeof(T));
        }
    }
    __forceinline void resize(hkMemoryAllocator_e50650& allocator, int count)
    {
        reserve(allocator, count);
        for (int n = count; n < size; ++n)
            data[n].~T();
        for (int n = size; n < count; ++n)
            new (data + n) T;
        size = count;
    }
    __forceinline void clear()
    {
        for (int n = 0; n < size; ++n)
            data[n].~T();
        size = 0;
    }
    __forceinline void release(hkMemoryAllocator_e50650& allocator)
    {
        clear();
        if ((capacity & 0x80000000) == 0)
            allocator.ReturnMemory(data, getCapacity() * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};

template <class T> struct TrackArray : TrackArrayBase<T>
{
    __forceinline TrackArray() : TrackArrayBase<T>()
    {}
    __forceinline ~TrackArray()
    {
        release(hkContainerHeapAllocator_e50650().get(this));
    }
    __forceinline void SetSizeAndGrow(int count)
    {
        resize(hkContainerHeapAllocator_e50650().get(this), count);
    }
};

template <class T> __forceinline void releaseTrackStack(T* memory)
{
    static_cast<E50920Router*>(FUN_00c85750())->stackTop = reinterpret_cast<char*>(memory);
}

template <class T> struct TrackLocalArray : TrackArray<T>
{
    T* localMemory;
    __forceinline TrackLocalArray(int count)
    {
        E50920Router* router = static_cast<E50920Router*>(FUN_00c85750());
        char* memory = router->stackTop;
        router->stackTop = memory + ((count * sizeof(T) + 127) & ~127);
        this->data = reinterpret_cast<T*>(memory);
        this->capacity = count | 0x80000000;
        localMemory = this->data;
    }
    __forceinline ~TrackLocalArray()
    {
        if (localMemory == this->data)
            this->clear();
        releaseTrackStack(localMemory);
    }
};

struct TrackInput
{
    const TrackTransform* transforms;
    unsigned int tracks;
    unsigned int frames;
    TrackArray<float> absolute;
    TrackArray<float> relative;
    TrackArray<float> rotation;
    TrackArray<float> scale;
    TrackArray<TrackFlag> special;
};

struct TrackReport
{
    unsigned int staticPosition, staticRotation, staticScale, staticFloat;
    unsigned int clearPosition, clearRotation, clearScale;
    unsigned int dynamicPosition, dynamicRotation, dynamicScale, dynamicFloat;
    unsigned int transformDofs, floatDofs;
    float ratio;
    TrackReport()
        : staticPosition(0), staticRotation(0), staticScale(0), staticFloat(0), clearPosition(0), clearRotation(0),
          clearScale(0), dynamicPosition(0), dynamicRotation(0), dynamicScale(0), dynamicFloat(0), transformDofs(0),
          floatDofs(0), ratio(0.0f)
    {}
};

static __forceinline void analyzeTransformTracks(const TrackInput& input, unsigned short* flags, float* output,
                                                 const TrackFlag& report)
{
    TrackLocalArray<TrackTransform> means(input.tracks);
    means.SetSizeAndGrow(input.tracks);
    TrackVector extent;
    extent.fill(0.0f);
    {
        TrackVector lower, upper;
        lower.fill3(DAT_0104da48);
        upper.fill3(DAT_0104e148);
        for (unsigned int track = 0; track < input.tracks; ++track)
        {
            for (unsigned int frame = 0; frame < input.frames; ++frame)
            {
                TrackVector sample = input.transforms[frame * input.tracks + track].translation;
                lower.minimum(lower, sample);
                upper.maximum(upper, sample);
            }
        }
        extent.subtract(upper, lower);
    }
    for (unsigned int track = 0; track < input.tracks; ++track)
    {
        const float absoluteTolerance = input.absolute[track];
        float relativeTolerance = input.relative[track];
        const float rotationTolerance = input.rotation[track];
        const float scaleTolerance = input.scale[track];
        float relativeSquared = relativeTolerance * relativeTolerance;
        TrackFlag special = input.special[track];
        const float hemisphereThreshold = 0.1f;
        if (extent.lengthSquared3() * TrackScalar(relativeSquared) < 1.1920928955078125e-7f)
        {
            if (extent.lengthSquared3() > 0.0f)
                relativeTolerance = 0.0f;
        }
        means[track].zero();
        for (unsigned int frame = 0; frame < input.frames; ++frame)
        {
            const TrackTransform& sample = input.transforms[frame * input.tracks + track];
            means[track].addWeighted(sample, 1.0f);
        }
        means[track].finish(float(input.frames));
        TrackFlag positive = false;
        TrackFlag negative = false;
        if (special)
        {
            float maxW = DAT_0104e148;
            float minW = DAT_0104da48;
            for (unsigned int frame = 0; frame < input.frames; ++frame)
            {
                const float w = input.transforms[frame * input.tracks + track].orientation()(3);
                if (w > maxW)
                    maxW = w;
                if (w < minW)
                    minW = w;
            }
            positive = minW >= hemisphereThreshold;
            negative = maxW <= -hemisphereThreshold;
        }
        const TrackVector& meanPosition = means[track].position();
        const TrackVector& meanRotation = means[track].orientation().vector;
        const TrackVector& meanScale = means[track].scaling();
        {
            unsigned short mask = 0x15;
            if (relativeTolerance > 0.0f || absoluteTolerance > 0.0f)
            {
                for (unsigned int frame = 0; frame < input.frames; ++frame)
                {
                    const TrackTransform& sample = input.transforms[frame * input.tracks + track];
                    TrackVector difference;
                    difference.subtract(meanPosition, sample.translation);
                    difference.absolute(difference);
                    TrackVector absoluteLimit;
                    absoluteLimit.fill3(absoluteTolerance);
                    TrackVector relativeLimit;
                    relativeLimit.multiply(relativeTolerance, extent);
                    int absoluteMask = difference.compare(absoluteLimit).GetLaneMask(TrackComparison::XYZ);
                    int relativeMask = difference.compare(relativeLimit).GetLaneMask(TrackComparison::XYZ);
                    if (absoluteTolerance > 0.0f && absoluteMask != 7)
                    {
                        mask &= ~3;
                        mask |= DAT_011be718[(~absoluteMask) & 7] << 5;
                    }
                    if (relativeTolerance > 0.0f && relativeMask != 7)
                    {
                        mask &= ~3;
                        mask |= DAT_011be718[(~relativeMask) & 7] << 5;
                    }
                }
            }
            else
            {
                mask &= ~3;
                mask |= 0x1c0;
            }
            if (rotationTolerance > 0.0f)
            {
                const TrackFlag markFourth = special && (positive || negative);
                for (unsigned int frame = 0; frame < input.frames; ++frame)
                {
                    const TrackTransform& sample = input.transforms[frame * input.tracks + track];
                    const TrackVector& rotation = sample.orientation().vector;
                    if (!rotation.equals4(meanRotation, rotationTolerance))
                    {
                        TrackVector difference;
                        difference.subtract(meanRotation, rotation);
                        difference.absolute(difference);
                        TrackVector limit;
                        limit.fill(rotationTolerance);
                        int matched = difference.compare(limit).GetLaneMask(TrackComparison::XYZW);
                        if (markFourth)
                            matched |= 8;
                        if (matched != 15)
                        {
                            mask &= ~12;
                            mask |= DAT_011be718[(~matched) & 15] << 9;
                        }
                    }
                }
                if (markFourth)
                {
                    if (positive)
                        means[track].rotation.vector(3) = 2.0f;
                    if (negative)
                        means[track].rotation.vector(3) = -2.0f;
                }
            }
            else
            {
                mask &= ~12;
                mask |= 0x1e00;
            }
            if (scaleTolerance > 0.0f)
            {
                for (unsigned int frame = 0; frame < input.frames; ++frame)
                {
                    const TrackTransform& sample = input.transforms[frame * input.tracks + track];
                    TrackVector difference;
                    difference.subtract(meanScale, sample.scaling());
                    difference.absolute(difference);
                    TrackVector limit;
                    limit.fill3(scaleTolerance);
                    int matched = difference.compare(limit).GetLaneMask(TrackComparison::XYZ);
                    if (scaleTolerance > 0.0f && matched != 7)
                    {
                        mask &= ~48;
                        mask |= DAT_011be718[(~matched) & 7] << 12;
                    }
                }
            }
            else
            {
                mask &= ~48;
                mask |= 0xe000;
            }
            flags[track] = mask;
        }
        if ((flags[track] & 3) == 1 &&
            ((absoluteTolerance > 0.0f &&
              meanPosition.equals3(TrackVector::zeroValue(), float(absoluteTolerance * 0.5))) ||
             (relativeTolerance > 0.0f &&
              meanPosition.equals3(TrackVector::zeroValue(),
                                   float(extent(extent.majorAxis()) * 0.5 * relativeTolerance)))))
        {
            flags[track] = (flags[track] & ~3) | 2;
            means[track].translation.zero();
        }
        if ((flags[track] & 12) == 4 && fabsf(meanRotation(3)) == 1.0f)
        {
            flags[track] = (flags[track] & ~12) | 8;
            means[track].rotation.identity();
        }
        TrackVector unit;
        unit = ::DAT_010c7170;
        if ((flags[track] & 48) == 16 && meanScale.equals3(unit, float(scaleTolerance * 0.5)))
        {
            flags[track] = (flags[track] & ~48) | 32;
            means[track].scale.fill(1.0f);
        }
    }
    float* cursor = output;
    for (unsigned int track = 0; track < input.tracks; ++track)
    {
        unsigned short mask = flags[track];
        unsigned short bits = mask >> 6;
        if ((mask & 3) != 2)
        {
            for (int axis = 0; axis < 3; ++axis)
            {
                int bit = bits & (1 << (2 - axis));
                if (!bit)
                {
                    *cursor = means[track].translation(axis);
                    ++cursor;
                }
            }
        }
        if (((mask >> 2) & 3) != 2)
        {
            for (int axis = 0; axis < 4; ++axis)
            {
                int bit = bits & (1 << (3 - axis + 3));
                if (!bit)
                {
                    *cursor = means[track].rotation(axis);
                    ++cursor;
                }
            }
        }
        if (((mask >> 4) & 3) != 2)
        {
            for (int axis = 0; axis < 3; ++axis)
            {
                int bit = bits & (1 << (2 - axis + 7));
                if (!bit)
                {
                    *cursor = means[track].scale(axis);
                    ++cursor;
                }
            }
        }
    }
    if (report)
    {
        TrackReport stats;
        ::FUN_00e4ead0(flags, input.tracks, (::StatisticsResult *)&(stats));
        reinterpret_cast<::TrackStatistics *>(&(stats))->LogStatistics();
    }
}

// @fnv 0x00e4f910
void __cdecl FUN_00e4f910(TrackBuffers_e50650* buffers, void* masks, void* values, hkBool_e50650 report)
{
    analyzeTransformTracks(*reinterpret_cast<const TrackInput*>(buffers), static_cast<unsigned short*>(masks),
                           static_cast<float*>(values), reinterpret_cast<const TrackFlag&>(report));
}

struct SplitVector
{
    float values[4];
    const float& operator()(int i) const
    {
        return values[i];
    }
};
struct SplitTransform
{
    SplitVector position, rotation, scale;
    const SplitVector& getPosition() const
    {
        return position;
    }
    const SplitVector& getRotation() const
    {
        return rotation;
    }
    const SplitVector& getScale() const
    {
        return scale;
    }
};
struct SplitInput
{
    const SplitTransform* transforms;
    unsigned transformCount;
    const float* floats;
    unsigned floatCount;
    unsigned frameCount;
    unsigned paddedCount;
    const unsigned short* masks;
};

// @fnv 0x00e4ecb0
void FUN_00e4ecb0(const SplitInput& input, float* output)
{
    const unsigned frames = input.frameCount;
    const unsigned width = frames > input.paddedCount ? frames : input.paddedCount;
    const unsigned tracks = input.transformCount;
    unsigned channel = 0;
    for (unsigned track = 0; track < tracks; ++track)
    {
        const unsigned short mask = input.masks[track];
        const unsigned short selected = mask >> 6;
        if (!(mask & 3))
        {
            for (int component = 0; component < 3; ++component)
            {
                if (selected & (1 << (2 - component)))
                {
                    for (unsigned frame = 0; frame < frames; ++frame)
                        output[channel * width + frame] =
                            input.transforms[frame * tracks + track].getPosition()(component);
                    const unsigned last = (frames - 1) * tracks + track;
                    for (unsigned frame = frames; frame < width; ++frame)
                        output[channel * width + frame] = input.transforms[last].getPosition()(component);
                    ++channel;
                }
            }
        }
        if (!(mask & 12))
        {
            for (int component = 0; component < 4; ++component)
            {
                if (selected & (1 << (6 - component)))
                {
                    for (unsigned frame = 0; frame < frames; ++frame)
                        output[channel * width + frame] =
                            input.transforms[frame * tracks + track].getRotation()(component);
                    const unsigned last = (frames - 1) * tracks + track;
                    for (unsigned frame = frames; frame < width; ++frame)
                        output[channel * width + frame] = input.transforms[last].getRotation()(component);
                    ++channel;
                }
            }
        }
        if (!(mask & 48))
        {
            for (int component = 0; component < 3; ++component)
            {
                if (selected & (1 << (9 - component)))
                {
                    for (unsigned frame = 0; frame < frames; ++frame)
                        output[channel * width + frame] =
                            input.transforms[frame * tracks + track].getScale()(component);
                    const unsigned last = (frames - 1) * tracks + track;
                    for (unsigned frame = frames; frame < width; ++frame)
                        output[channel * width + frame] = input.transforms[last].getScale()(component);
                    ++channel;
                }
            }
        }
    }
    for (unsigned track = 0; track < input.floatCount; ++track)
    {
        if (input.masks[input.transformCount + track] == 0)
        {
            for (unsigned frame = 0; frame < frames; ++frame)
                output[channel * width + frame] = input.floats[frame * input.floatCount + track];
            const unsigned last = (frames - 1) * input.floatCount + track;
            for (unsigned frame = frames; frame < width; ++frame)
                output[channel * width + frame] = input.floats[last];
            ++channel;
        }
    }
}

#include "generated/data/havok/animation/animation/animation/util/hkatrackanalysis.inc"
