
// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpumoppaabbjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpumoppaabbjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include "fnv/decl/GridCell.h"
#include "fnv/decl/LunaOwner.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01268000.h"
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
#include <windows.h>


struct S_00df7010_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

struct S_00df7010_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00df7010_MonitorStream& GetMonitorStream()
    {
        return *(S_00df7010_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00df7010_TimerCommand* h = (S_00df7010_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct S_00df7010_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00df7010_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00df7010_Allocator* m_pStreamAllocator;
    S_00df7010_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};


struct S_00df7010_HitArray
{
    unsigned int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00df7010_HitArray(unsigned int* buffer, int size, int capacity)
        : m_data(buffer), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}
    ~S_00df7010_HitArray() throw()
    {
        _clearAndDeallocate(static_cast<S_00df7010_Router*>(::FUN_00c85750())->heap());
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _clearAndDeallocate(S_00df7010_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(unsigned int));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void _pushBack(S_00df7010_Allocator& alloc, const unsigned int& e)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(unsigned int));
        new (m_data + m_iElementCount) unsigned int(e);
        m_iElementCount++;
    }
    void AddBack(const unsigned int& e)
    {
        _pushBack(static_cast<S_00df7010_Router*>(::FUN_00c85750())->heap(), e);
    }
};

struct S_00df7010_Aabb
{
    float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct S_00df7010_Query
{
    S_00df7010_Aabb m_kBounds;
    unsigned int* m_pResultBuffer;
    int unk24;
    int unk28;
    int unk2C;
};

struct S_00df7010_Vector4
{
    __m128 m_vComponents;
    S_00df7010_Vector4& operator=(const S_00df7010_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct S_00df7010_ByteArray
{
    const unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void set(const unsigned char* d, int size, int cap)
    {
        m_data = d;
        m_iElementCount = size;
        m_iCapacityState = cap;
    }
};

struct S_00df7010_MoppCode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00df7010_Vector4 m_offset;
    S_00df7010_ByteArray m_data;
    unsigned char m_eBuildType;
};

struct S_00df7010_Input
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00df7010_Vector4 m_codeOffset;
    const unsigned char* m_codeData;
    int unk34;
    S_00df7010_Query* m_queries;
    int m_numQueries;
};

struct S_00df7010_VirtualMachine
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct S_00df7010_Output
{
};

// Runs MOPP AABB queries against the input code data, appending a sentinel to each result buffer, then forwards the input to the output.
// @fnv 0x00df7010
void __cdecl ExecuteMoppAabbQuery(S_00df7010_Output* out, const S_00df7010_Input* input) throw()
{
    S_00df7010_MonitorStream::GetMonitorStream().timer("TtCollQueryMoppAabbQuery");

    // aligned storage for a stand-in MOPP code object (non-char buffer: no GS cookie)
    unsigned int buffer[(sizeof(S_00df7010_MoppCode) + 15) / sizeof(unsigned int) + 1];
    S_00df7010_MoppCode* code = (S_00df7010_MoppCode*)(((uintptr_t)buffer + 15) & ~(uintptr_t)15);
    code->m_offset = input->m_codeOffset;
    code->m_data.set(input->m_codeData, 0x200, 0x200);
    code->m_eBuildType = 2;

    for (int i = 0; i < input->m_numQueries; i++)
    {
        S_00df7010_Query& query = input->m_queries[i];
        S_00df7010_HitArray hits(query.m_pResultBuffer, 0, 0x1000);
        S_00df7010_VirtualMachine vm;
        reinterpret_cast<::GridCell *>(&(vm))->FUN_00dd1da0((::GridSource *)(code), (::GridBounds *)&(query.m_kBounds), (int)(&hits));
        hits.AddBack(0xffffffff);
    }

    S_00df7010_MonitorStream::GetMonitorStream().timer("Et");
    reinterpret_cast<::LunaOwner *>((out))->ProcessCallback((intptr_t)(input), (intptr_t)(input), 0);
}
