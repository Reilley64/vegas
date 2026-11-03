// src/havok/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include <cstring>
#include "fnv/decl/BufferRequirements.h"
#include "fnv/decl/FUN_00dd50f0_cls.h"
#include "fnv/decl/FUN_00dd5150_cls.h"
#include "fnv/decl/FUN_00e064f0_class.h"
#include "fnv/decl/FUN_00e09ba0.h"
#include "fnv/decl/S_00dd4bb0_Class.h"
#include "fnv/decl/hkProcessorE0A5.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00e09000.h"
#include "fnv/symbols_0102e000.h"
struct InitArg;
struct SubFirst
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;

};
struct SubSecond
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;

};
struct FUN_00dd4bf0
{
    int m_i00;
    int m_i04;
    SubFirst m_kFirst;
    SubSecond m_kSecond;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    int m_i4c;
    __m128 m_kVector;
    int m_iMode;
    char m_bFlag;

    FUN_00dd4bf0(InitArg* apArg);
};
struct SourceData
{
    float x;
    float y;
    float z;
    unsigned int unk0C;
    __m128 unk10;
    unsigned int unk20;
    unsigned char unk24;
};
struct Destination
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    float unk40;
    float unk44;
    float unk48;
    __m128 unk50;
    unsigned int unk60;
    unsigned char unk64;
    void CopyFromSourceData(unsigned int srcAddress);
};

extern "C" void _ReadWriteBarrier(void);
struct FourFloatVector
{
    __m128 q;
};
struct Allocator
{
    virtual void slot0() throw();
    virtual void* allocate(int) throw();
    virtual void slot8() throw();
    virtual void slotC() throw();
    virtual void freeBlock(void*, int) throw();
};
struct MemoryRouter
{
    int unk00, unk04, unk08, unk0C;
    Allocator* m_pStreamAllocator;
    Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
MemoryRouter* __cdecl FUN_00c85750() throw();
void* __cdecl FUN_00c85690(Allocator*, int) throw();
void __cdecl FUN_00c856c0(Allocator*, void*) throw();
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};
class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short memSizeAndFlags;
    short referenceCount;
    hkReferencedObject() throw()
    {
        referenceCount = 1;
    }
    static void* operator new(std::size_t n) throw()
    {
        hkReferencedObject* b = (hkReferencedObject*)FUN_00c85750()->heap().allocate(n);
        b->memSizeAndFlags = (unsigned short)n;
        return b;
    }
    static void operator delete(void*) throw()
    {}
};
template <class T> struct MergeArray
{
    T* data;
    int size;
    int capacity;
    static void fill(T* p, int num)
    {
        _ReadWriteBarrier();
        if (num > 0)
            std::memset(p, 0xcd, num * sizeof(T));
    }
    void init()
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
    }
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    void reserve(int n)
    {
        Allocator& a = FUN_00c85750()->heap();
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            ::FUN_00c908c0((::SpawnedObject *)(::Allocator *)(&a), (::SpawnedArray *)(void *)(this), n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    void reserveExactly(int n)
    {
        Allocator& a = FUN_00c85750()->heap();
        if (getCapacity() < n)
            ::FUN_00c908c0((::SpawnedObject *)(::Allocator *)(&a), (::SpawnedArray *)(void *)(this), n, sizeof(T));
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        size = n;
    }
    void setSizeFill(int n)
    {
        reserve(n);
        fill(data + size, n - size);
        size = n;
    }
    void ClearAndRelease()
    {
        Allocator& a = FUN_00c85750()->heap();
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
class hkpMoppCode : public hkReferencedObject
{
  public:
    FourFloatVector info;
    MergeArray<unsigned char> code;
    unsigned char buildType;
    hkpMoppCode() throw()
    {
        *(void**)this = &(*reinterpret_cast<char *>(&::DAT_0102e368));
        code.init();
        info.q = _mm_setzero_ps();
        buildType = 2;
    }
    virtual ~hkpMoppCode() throw();
};
struct PrimitiveSource
{
    virtual void slot0() throw();
    virtual void slot4() throw();
    virtual void slot8() throw();
    virtual void setAssembler(void*, int) throw();
    virtual int count() throw();
    virtual void SetDataPointer(void*) throw();
};
struct hkpMoppCodeGenerator : hkReferencedObject
{
    int byteCapacity;
    int byteSize;
    unsigned char* byteData;
    MergeArray<int> state;
    hkpMoppCodeGenerator(int) throw();
    ~hkpMoppCodeGenerator() throw();
};
struct CostSettings
{
    float primitive, plane, axis, split, balance, minimum, maximum, scale;
};
struct hkpMoppCostFunction
{
    void* vfptr;
    unsigned short memSizeAndFlags;
    short referenceCount;
    float axis, plane, primitive, split, balance, scale;
    hkpMoppCostFunction(CostSettings*) throw();
    ~hkpMoppCostFunction() throw()
    {
        vfptr = &(*reinterpret_cast<char *>(&::DAT_0102e388));
    }
};
struct AssemblerSettings
{
    int unk00;
};
struct ChunkRecord
{
    int offset;
    int primitive;
};
struct ChunkEntry
{
    hkpMoppCodeGenerator* generator;
    int flags;
};
struct ChunkList
{
    int fixedSize;
    int unk04, unk08, unk0C;
    ChunkEntry* entries;
    int count;
    int capacity;
    int useFixedSize;
    ChunkEntry& at(const int& i)
    {
        return entries[i];
    }
};
struct AssemblerInterface
{
    virtual void slot0() throw();
    virtual void slot4() throw();
    virtual void slot8() throw();
    virtual int outputSize() throw();
    virtual void* output() throw();
    virtual void slot14() throw();
    virtual void finalize(int, FourFloatVector*) throw();
};
struct hkpMoppDefaultAssembler : AssemblerInterface
{
    unsigned short memoryFlags, referenceCount;
    int unk08, unk0C, unk10;
    ChunkList* chunks;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48;
    int unk4C;
    float unk50, unk54, unk58, unk5C;
    FourFloatVector unk60;
    int unk70, unk74, unk78, unk7C;
    hkpMoppDefaultAssembler(AssemblerSettings*, hkpMoppCodeGenerator*, PrimitiveSource*) throw();
    ~hkpMoppDefaultAssembler() throw();
};
struct ScratchLayout
{
    unsigned char* start;
    unsigned char* nodes;
    unsigned char* end;
};
struct hkpMoppDefaultSplitter
{
    void* vtbl;
    int unk04;
    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkpMoppCostFunction* costFunction;
    hkpMoppDefaultAssembler* assembler;
    PrimitiveSource* source;
    int unk2C, unk30, unk34, treeDepth;
    hkpMoppDefaultSplitter() throw()
    {
        new ((void *)this) ::FUN_00e09ba0();
    }
    ~hkpMoppDefaultSplitter() throw()
    {
        ::FUN_00e09bd0((void *)this, {});
    }
};
struct EncodedReference
{
    unsigned char tag, indexHigh, indexMiddle, indexLow, indexLast;
};
static __declspec(noinline) void StoreBigEndian(EncodedReference* reference, int value) throw()
{
    reference->indexHigh = (unsigned int)value >> 24;
    reference->indexMiddle = (unsigned int)value >> 16;
    reference->indexLow = (unsigned int)value >> 8;
    reference->indexLast = value;
}
inline void* allocateScratch(int n)
{
    Allocator* heap = &FUN_00c85750()->heap();
    return FUN_00c85690(heap, n);
}
struct MoppBuilder
{
    int result;
    ChunkList* chunks;
    int options;
    int extraPrimitives;
    int unk10, unk14, unk18;
    bool largeBuffer;
    CostSettings cost;
    AssemblerSettings assembler;
    hkpMoppCode* FUN_00dd4cb0(PrimitiveSource*, void*, int) throw();
};
// @fnv 0x00dd4cb0
hkpMoppCode* MoppBuilder::FUN_00dd4cb0(PrimitiveSource* source, void* buffer, int bufferSize)
{
    int primitiveCount = source->count() + extraPrimitives;
    hkpMoppCodeGenerator generator(primitiveCount * 12);
    hkpMoppCostFunction costFunction(&cost);
    hkpMoppDefaultAssembler output(&assembler, &generator, source);
    output.chunks = chunks;
    AssemblerInterface* outputInterface = &output;
    source->setAssembler(outputInterface->output(), outputInterface->outputSize());
    int required = reinterpret_cast<::BufferRequirements *>(this)->ComputeRequiredSize((::CountProvider *)(source));
    void* scratch = (!buffer || bufferSize < required) ? allocateScratch(required) : buffer;
    ScratchLayout layout;
    layout.start = (unsigned char*)scratch;
    layout.nodes = (unsigned char*)scratch + primitiveCount * 20;
    int nodeCount = largeBuffer ? 4096 : primitiveCount;
    layout.end = layout.nodes + nodeCount * 124;
    source->SetDataPointer(scratch);
    int status;
    {
        hkpMoppDefaultSplitter splitter;
        status = reinterpret_cast<::hkProcessorE0A5 *>(&(splitter))->FUN_00e0a550((::hkInputE0A5 *)(source), (int)(&costFunction), (::hkOutputE0A5 *)(::hkpMoppDefaultAssembler *)(&output), (::hkSettingsE0A5 *)(int *)(&options), (::hkBuffersE0A5 *)(::ScratchLayout *)(&layout));
    }
    if (scratch != buffer)
    {
        Allocator* heap = &FUN_00c85750()->heap();
        FUN_00c856c0(heap, scratch);
    }
    result = status;
    hkpMoppCode* code;
    if (!chunks)
    {
        code = ((::hkpMoppCode *)(reinterpret_cast<::FUN_00e064f0_class *>(&(generator))->FUN_00e064f0()));
    }
    else
    {
        MergeArray<int> offsets;
        offsets.init();
        offsets.SetSizeAndGrow(chunks->count + 1);
        offsets.data[0] = 0;
        for (int i = 0; i < chunks->count; ++i)
        {
            int size;
            if (chunks->useFixedSize)
                size = chunks->fixedSize;
            else
                size = (chunks->entries[i].generator->byteSize + 15) & ~15;
            offsets.data[i + 1] = offsets.data[i] + size;
        }
        for (int i = 0; i < chunks->count; ++i)
        {
            ChunkEntry* entry = &chunks->entries[i];
            MergeArray<ChunkRecord>& records = *(MergeArray<ChunkRecord>*)&entry->generator->state;
            for (int j = 0; j < records.size; ++j)
            {
                hkpMoppCodeGenerator* current = entry->generator;
                EncodedReference* reference =
                    (EncodedReference*)(current->byteData + current->byteCapacity - records.data[j].offset);
                StoreBigEndian(reference, offsets.data[((int)(reinterpret_cast<::S_00dd4bb0_Class *>((reference))->GetPackedValue()))]);
            }
        }
        int totalSize = offsets.data[offsets.size - 1];
        code = new hkpMoppCode;
        MergeArray<unsigned char>& bytes = code->code;
        bytes.reserveExactly(totalSize);
        bytes.setSizeFill(totalSize);
        for (int i = 0; i < chunks->count; ++i)
        {
            unsigned char* dest = bytes.data + offsets.data[i];
            hkpMoppCode* part = ((::hkpMoppCode *)(reinterpret_cast<::FUN_00e064f0_class *>((chunks->at(i).generator))->FUN_00e064f0()));
            ::FUN_00cb1260(dest, part->code.data, part->code.size);
            delete part;
            reinterpret_cast<::hkReferencedObjectC905 *>((chunks->at(i).generator))->FUN_00c905b0();
        }
        offsets.ClearAndRelease();
    }
    outputInterface->finalize(status, &code->info);
    return code;
}
