
// src/havok/common/base/math/swepttransform/hkswepttransformutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/swepttransform/hkswepttransformutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00cf1480
#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include "fnv_simd.h"
#include "fnv/decl/C74C20Quat.h"
#include "fnv/decl/Quat74.h"
#include "fnv/symbols_00cf1000.h"
#include "fnv/symbols_00cf2000.h"
#include "fnv/symbols_simd.h"
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01092000.h"
#include "fnv/symbols_01272000.h"
void FUN_00cf1480(float afValue1, float afValue2, int* piTarget)
{
    *reinterpret_cast<float*>(piTarget + 19) = afValue1;
    *reinterpret_cast<float*>(piTarget + 23) = afValue2;
}

struct S_00cf10f0_BinaryStream;
typedef unsigned int(__cdecl* S_00cf10f0_ReadFn)(S_00cf10f0_BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                 unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct S_00cf10f0_BinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    S_00cf10f0_ReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T>
inline void S_00cf10f0_BinaryStreamLoad(S_00cf10f0_BinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct S_00cf10f0_Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    S_00cf10f0_BinaryStream* unk24c;
};

struct S_00cf10f0_Tls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00cf10f0_Tls DAT_tls;

struct S_00cf10f0_Ctx
{
    int saved;
    __forceinline S_00cf10f0_Ctx(int c)
    {
        saved = (*reinterpret_cast<::S_00cf10f0_Tls *>(&::g_tlsBlock)).ctx;
        (*reinterpret_cast<::S_00cf10f0_Tls *>(&::g_tlsBlock)).ctx = c;
    }
    __forceinline ~S_00cf10f0_Ctx()
    {
        (*reinterpret_cast<::S_00cf10f0_Tls *>(&::g_tlsBlock)).ctx = saved;
    }
};

struct S_00cf10f0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00cf10f0_Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    S_00cf10f0_Heap* m10;
    __forceinline S_00cf10f0_Heap& heap()
    {
        return *m10;
    }
};

struct S_00cf10f0_Arr4;

struct S_00cf10f0_Arr4
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void reserve(int n) throw()
    {
        S_00cf10f0_Heap& h = static_cast<S_00cf10f0_Router*>(::FUN_00c85750())->heap();
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
            ::FUN_00c908c0((::SpawnedObject *)(::S_00cf10f0_Heap *)(&h), (::SpawnedArray *)(::S_00cf10f0_Arr4 *)(this), (n < cap * 2) ? cap * 2 : n, 4);
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        reserve(n);
        m_iElementCount = n;
    }
    __forceinline void _clearAndDeallocate(S_00cf10f0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 4);
        m_data = 0;
        m_cap = 0x80000000;
    }
};

// Reads a count from the stream, resets arr, reserves n elements, loads n ints into arr->m_data and returns n*4 bytes.
// @fnv 0x00cf10f0
int __cdecl LoadIntArray(S_00cf10f0_Stream* kStream, S_00cf10f0_Arr4* pArray)
{
    S_00cf10f0_Ctx guard(0x10);
    int n = 0;
    S_00cf10f0_BinaryStreamLoad(*kStream->unk24c, &n, 1);
    pArray->_clearAndDeallocate(static_cast<S_00cf10f0_Router*>(::FUN_00c85750())->heap());
    pArray->SetSizeAndGrow(n);
    int bytes = n * 4;
    for (int iIndex = 0; iIndex < n; iIndex++)
        S_00cf10f0_BinaryStreamLoad(*kStream->unk24c, &pArray->m_data[iIndex], 1);
    return bytes;
}

namespace fnv_00cf1270 {


extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long value);


struct HeapContextGuard
{
    unsigned int m_uiOld;
    HeapContextGuard(unsigned int uiNew)
    {
        m_uiOld = ::currentAllocationContext;
        ::currentAllocationContext = uiNew;
    }
    ~HeapContextGuard()
    {
        ::currentAllocationContext = m_uiOld;
    }
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
inline AudioMgr* audio()
{
    return (AudioMgr*)static_cast<BSAudio*>(::FUN_00c85750());
}


struct NiBinaryStreamStandIn
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(NiBinaryStreamStandIn* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    unsigned int BinaryRead(void* buffer, unsigned int totalBytes, unsigned int* componentSizes,
                            unsigned int componentCount)
    {
        unsigned int bytesRead = read(this, buffer, totalBytes, componentSizes, componentCount);
        absolutePosition += bytesRead;
        return bytesRead;
    }
    template <class T> unsigned int Read(T* value)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(value, sizeof(T), &size, 1);
    }
    template <class T> unsigned int Read(T* array, unsigned int count)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(array, sizeof(T) * count, &size, 1);
    }
    unsigned int ReadRaw(void* buffer, unsigned int bytes)
    {
        return BinaryRead(buffer, bytes, 0, 0);
    }
};

struct BlobStream
{
    int unk00;
    unsigned int unk04;
    int pad08[0x75];
    char pad1dc[9];
    unsigned char unk1e5;
    char pad1e6[0x66];
    NiBinaryStreamStandIn* istr;
};


struct __declspec(align(16)) BlobVec
{
    unsigned int x, y, z, w;
};

struct ByteArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), n < cap ? cap : n, sizeof(char));
        }
        m_iElementCount = n;
    }
};

inline void Swap32(unsigned int& v)
{
    v = _byteswap_ulong(v);
}
struct BlobObject
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08;
    int unk0c;
    BlobVec m_kHeader;
    ByteArray m_data;
    unsigned char unk2c;

    void Init()
    {
        m_vtbl = (*reinterpret_cast<char (*)[]>(&::DAT_0102e368));
        m_usMemSizeAndFlags = 0x30;
        m_sReferenceCount = 1;
        m_data.init();
        unk2c = 2;
        *(__m128*)&m_kHeader = _mm_setzero_ps();
    }
};

// @fnv 0x00cf1270
int __cdecl ReadBlobObject(BlobStream* stream, BlobObject** ppOut)
{
    HeapContextGuard guard(0x10);
    BlobObject* obj = (BlobObject*)audio()->heap().AllocateMemoryBlock(0x30);
    obj->Init();
    *ppOut = obj;
    int count = 0;
    stream->istr->Read(&count);
    stream->istr->ReadRaw(&(*ppOut)->m_kHeader, 0x10);
    if (stream->unk04 < 6 && count)
    {
        count -= 0x30;
        int skip[8];
        stream->istr->Read(skip, 8);
    }
    if (count)
    {
        (*ppOut)->m_data.SetSizeAndGrow(count);
        stream->istr->ReadRaw((*ppOut)->m_data.m_data, count);
    }
    if (stream->unk1e5 != 1)
    {
        BlobVec& v = (*ppOut)->m_kHeader;
        Swap32(v.x);
        Swap32(v.y);
        Swap32(v.z);
        Swap32(v.w);
    }
    return count;
}
}  // namespace fnv_00cf1270

int __cdecl FUN_00cf1f80(int, int, int);
// @fnv 0x00cf2160
int __cdecl FUN_00cf2160(unsigned int uiValue, unsigned int arg1)
{
    unsigned int callResult0 = (unsigned int)FUN_00cf1f80((int)(arg1 + 48u), (int)uiValue, (int)arg1);
    return (int)callResult0;
}

#include <xmmintrin.h>
struct F4
{
    float x, y, z, w;
};

struct Obj
{
    __m128 m00;
    __m128 m10;
    __m128 m20;
    int unk30;
    int unk34;
    __m128 m40;
    __m128 m50;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    __m128 m80;
};

struct Calc
{
    __declspec(align(16)) F4 res;
    void mul(Obj* o, F4* v);
};

extern const __m128 g_mask;

// Subtracts b->m80 from a, stores a in b->m80, passes the difference to Calc, then adds a masked result to b->m40 and b->m50.
// @fnv 0x00cf14a0
void ApplyDelta(__m128* apDelta, Obj* apObj)
{
    __m128 vDelta = *apDelta;
    vDelta = _mm_sub_ps(vDelta, apObj->m80);
    __declspec(align(16)) F4 d;
    F4* pd = &d;
    *(__m128*)&d = vDelta;
    apObj->m80 = *apDelta;
    Calc c;
    c.mul(apObj, pd);
    __m128 vMasked = _mm_and_ps(g_mask, *(const __m128*)&c.res);
    apObj->m40 = _mm_add_ps(apObj->m40, vMasked);
    apObj->m50 = _mm_add_ps(apObj->m50, vMasked);
}

extern __declspec(align(16)) float DAT_010ec7f0[4];

__forceinline void normalize4(__m128& q)
{
    __m128 x2 = _mm_mul_ps(q, q);
    __m128 s = _mm_add_ps(x2, _mm_shuffle_ps(x2, x2, 0x4E));
    s = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xB1));
    __m128 r = _mm_rsqrt_ss(s);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 eq = _mm_cmpeq_ss(s, zero);
    __m128 prod = _mm_mul_ss(_mm_mul_ss(s, r), r);
    __m128 three = _mm_set_ss(3.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 nr = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, prod));
    nr = _mm_andnot_ps(eq, nr);
    q = _mm_mul_ps(q, _mm_shuffle_ps(nr, nr, 0));
}

struct V4
{
    __m128 q;
};

struct FUN_008cd6a0_Class
{
    V4 col0;
    V4 col1;
    V4 col2;
    V4 translation;
    V4 com0;
    V4 com1;
    V4 rot0;
    V4 rot1;
    V4 comLocal;
};

__forceinline void interpolate(__m128& dst, __m128 a, __m128 b, float w)
{
    __m128 wb = _mm_load_ss(&w);
    wb = _mm_shuffle_ps(wb, wb, 0);
    __m128 other = _mm_sub_ps(_mm_load_ps(DAT_010ec7f0), wb);
    dst = _mm_add_ps(_mm_mul_ps(other, a), _mm_mul_ps(wb, b));
}
// Clamps time, interpolates and normalizes the rotation quaternions, interpolates com0/com1, then recomputes translation from comLocal and rotation columns.
// @fnv 0x00cf1d50
void __cdecl UpdateRotationInterpolation(float time, FUN_008cd6a0_Class* apTransform)
{
    float t0 = fnv_simd_as<float>(apTransform->com0.q)[3];
    if (!(time > t0))
        time = t0;

    float alpha = (time - fnv_simd_as<float>(apTransform->com0.q)[3]) * fnv_simd_as<float>(apTransform->com1.q)[3];

    __m128 q0 = apTransform->rot0.q;
    __m128 q1 = apTransform->rot1.q;
    __m128 sum = _mm_add_ps(q0, q1);
    __m128 x2 = _mm_mul_ps(sum, sum);
    __m128 qShuffled = _mm_shuffle_ps(x2, x2, 0x4E);
    __m128 qDotProduct = _mm_add_ps(qShuffled, x2);
    qDotProduct = _mm_add_ps(_mm_shuffle_ps(qDotProduct, qDotProduct, 0xB1), qDotProduct);
    float fComponentSum;
    _mm_store_ss(&fComponentSum, qDotProduct);
    double product = DAT_010924a8 * fComponentSum;
    apTransform->rot1.q = sum;
    float a = (float)(::DAT_0101de30 - product);
    double halfLen = DAT_01011588 * fComponentSum;
    float fPolynomial = (float)(a * (DAT_01016ff0 - a * (a * halfLen)));
    double half = ::fnv_00c88020::DAT_01016248;
    __m128& qScaled = apTransform->rot1.q;
    qScaled = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&fPolynomial), _mm_load_ss(&fPolynomial), 0), sum);

    if (half > alpha)
    {
        float w = alpha + alpha;
        interpolate(apTransform->rot1.q, q0, qScaled, w);
    }
    else
    {
        float w = (alpha + alpha) - 1.0;
        interpolate(apTransform->rot1.q, qScaled, q1, w);
    }
    normalize4(apTransform->rot1.q);
    apTransform->rot0.q = apTransform->rot1.q;

    __m128 qAlpha = _mm_load_ss(&alpha);
    qAlpha = _mm_shuffle_ps(qAlpha, qAlpha, 0);
    __m128 com = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(DAT_010ec7f0), qAlpha), apTransform->com0.q),
                            _mm_mul_ps(qAlpha, apTransform->com1.q));
    apTransform->com0.q = com;
    fnv_simd_as<float>(apTransform->com0.q)[3] = time;
    apTransform->com1.q = com;
    fnv_simd_as<float>(apTransform->com1.q)[3] = 0.0f;

    reinterpret_cast<::RotationRows *>((apTransform))->FUN_00cb2d90(&apTransform->rot1);

    __m128 v = apTransform->comLocal.q;
    __m128 y = _mm_shuffle_ps(v, v, 0x55);
    __m128 x = _mm_shuffle_ps(v, v, 0x00);
    __m128 z = _mm_shuffle_ps(v, v, 0xAA);
    __m128 rot = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, apTransform->col1.q), _mm_mul_ps(x, apTransform->col0.q)),
                            _mm_mul_ps(z, apTransform->col2.q));
    apTransform->translation.q = _mm_sub_ps(apTransform->com1.q, rot);
}

void FUN_00cf1480(float a, float b, int* c);

struct __declspec(align(16)) MotionVec4
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) MotionMat4
{
    MotionVec4 c0;
    MotionVec4 c1;
    MotionVec4 c2;
    MotionVec4 c3;
};

class MotionRotSet_cls
{
  public:
};

struct __declspec(align(16)) MotionState_cls
{
    MotionMat4 m_kMotionTransform;  // +0x00
    MotionVec4 m_com0;              // +0x40
    MotionVec4 m_com1;              // +0x50
    MotionVec4 m_rot0;              // +0x60
    MotionVec4 m_rot1;              // +0x70
    MotionVec4 m_comLocal;          // +0x80
    MotionVec4 m_kDeltaAngle;       // +0x90
};

// Copies the transform into m_kMotionTransform, derives rotation via MotionRotSet_cls, and computes m_com0/m_com1 from m_comLocal.
// @fnv 0x00cf2020
void SetMotionState(const MotionMat4* transform, MotionState_cls* apMotionState)
{
    MotionVec4 q;
    _mm_store_ps((float*)&apMotionState->m_kDeltaAngle, _mm_setzero_ps());
    reinterpret_cast<::FUN_00827200_class *>((((MotionRotSet_cls*)&q)))->FUN_00cb26e0((intptr_t)(transform));
    const __m128* m = (const __m128*)transform;
    _mm_store_ps((float*)&apMotionState->m_kMotionTransform.c0, m[0]);
    _mm_store_ps((float*)&apMotionState->m_kMotionTransform.c1, m[1]);
    _mm_store_ps((float*)&apMotionState->m_kMotionTransform.c2, m[2]);
    _mm_store_ps((float*)&apMotionState->m_kMotionTransform.c3, m[3]);
    __m128 rot = _mm_load_ps((float*)&q);
    _mm_store_ps((float*)&apMotionState->m_rot0, rot);
    _mm_store_ps((float*)&apMotionState->m_rot1, rot);
    float t0 = apMotionState->m_com0.w;
    __m128 com = _mm_load_ps((float*)&apMotionState->m_comLocal);
    __m128 vM0 = m[0];
    __m128 vM1 = m[1];
    __m128 r = _mm_mul_ps(_mm_shuffle_ps(com, com, 0x55), vM1);
    r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(com, com, 0), vM0));
    r = _mm_add_ps(r, _mm_mul_ps(m[2], _mm_shuffle_ps(com, com, 0xaa)));
    r = _mm_add_ps(r, m[3]);
    _mm_store_ps((float*)&apMotionState->m_com0, r);
    _mm_store_ps((float*)&apMotionState->m_com1, r);
    apMotionState->m_com0.w = t0;
    apMotionState->m_com1.w = 0.0f;
}

struct TransformData
{
    __m128 row0;
    __m128 row1;
    __m128 row2;
    __m128 sourceCopy;
    __m128 output;
    __m128 output2;
    __m128 output3;
    __m128 translation;
    __m128 transform;
    __m128 zero;
};
// Weights the row vectors by transform components, adds source, stores the result in output and output2, and copies translation to output3.
// @fnv 0x00cf20d0
extern "C" void __cdecl FUN_00cf20d0(const __m128* source, TransformData* data)
{
    data->zero = _mm_setzero_ps();
    data->sourceCopy = *source;
    volatile float* savedLane = (volatile float*)((char*)data + 0x4c);
    float oldW = *savedLane;
    __m128 transform = data->transform;
    __m128 result = _mm_mul_ps(_mm_shuffle_ps(transform, transform, _MM_SHUFFLE(1, 1, 1, 1)), data->row1);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(transform, transform, _MM_SHUFFLE(0, 0, 0, 0)), data->row0));
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(transform, transform, _MM_SHUFFLE(2, 2, 2, 2)), data->row2));
    result = _mm_add_ps(result, *source);
    data->output = result;
    *savedLane = oldW;
    data->output2 = result;
    ((float*)&data->output2)[3] = 0.0f;
    data->output3 = data->translation;
}

struct Obj_t
{
    __m128 m00;
    __m128 m10;
    __m128 m20;
    __m128 m30;
    __m128 m40;
    __m128 m50;
    __m128 m60;
    __m128 m70;
    __m128 m80;
    __m128 m90;

};

// Applies a 3x3 matrix (m00, m10, m20) times a vector (m80) plus translation (first) to produce m40 and m50, preserving the w component of m40.
// @fnv 0x00cf1f80
void __cdecl FUN_00cf1f80(const __m128& apTranslation, const __m128& second, Obj_t* obj)
{
    obj->m90 = _mm_setzero_ps();
    obj->m60 = second;
    obj->m70 = second;
    reinterpret_cast<::RotationRows *>((obj))->FUN_00cb2d90((void *)&(second));
    {
        __m128& t = obj->m30;
        t = apTranslation;
    }
    volatile float saved = ((volatile float*)&obj->m40)[3];
    __m128 v = obj->m80;
    __m128 result = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), obj->m10);
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), obj->m00));
    result = _mm_add_ps(result, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xAA), obj->m20));
    result = _mm_add_ps(result, apTranslation);
    obj->m40 = result;
    obj->m50 = result;
    ((volatile float*)&obj->m40)[3] = saved;
    ((volatile float*)&obj->m50)[3] = 0.0f;
}


struct VectorComponentValue
{
    __m128 m_vValue;
    __forceinline VectorComponentValue(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline VectorComponentValue(__m128 q) : m_vValue(q)
    {}
};

struct hkVector4
{
    union
    {
        __m128 m_vComponents;
        float m_f[4];
    };
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const VectorComponentValue& s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline void setMul4(const VectorComponentValue& s, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), v.m_vComponents);
    }
    __forceinline void sub4(const hkVector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline float lengthSquared4() const
    {
        __m128 l = _mm_mul_ps(m_vComponents, m_vComponents);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0x4e), l);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0xb1), l);
        float r;
        _mm_store_ss(&r, l);
        return r;
    }
    __forceinline void setInterpolate4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& t)
    {
        __m128 av = a.m_vComponents;
        __m128 weight = t.broadcast();
        __m128 rest = _mm_sub_ps(_mm_load_ps(DAT_010ec7f0), weight);
        m_vComponents = _mm_add_ps(_mm_mul_ps(rest, av), _mm_mul_ps(weight, b.m_vComponents));
    }
    __forceinline void normalize4()
    {
        __m128 l = _mm_mul_ps(m_vComponents, m_vComponents);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0x4e), l);
        l = _mm_add_ps(_mm_shuffle_ps(l, l, 0xb1), l);
        __m128 e = _mm_rsqrt_ss(l);
        __m128 isZero = _mm_cmpeq_ss(l, _mm_set_ss(::DAT_01011d78));
        __m128 three = _mm_sub_ss(_mm_set_ss(::DAT_01017718), _mm_mul_ss(_mm_mul_ss(l, e), e));
        __m128 inv = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), e), three));
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m_vComponents);
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkMatrix3
{
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};

__forceinline void SetRotatedDirection(hkVector4& out, const hkMatrix3& r, const hkVector4& v)
{
    __m128 x =
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55), r.m_kColumn1.m_vComponents),
                   _mm_mul_ps(_mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00), r.m_kColumn0.m_vComponents));
    out.m_vComponents =
        _mm_add_ps(x, _mm_mul_ps(_mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa), r.m_kColumn2.m_vComponents));
}

struct __declspec(align(16)) hkVector4L
{
    float x, y, z, w;
    __m128 Vector4f() const
    {
        return _mm_load_ps(&x);
    }
};
struct hkSweptTransform
{
    hkVector4L m_vCenterOfMass0;
    hkVector4L m_vCenterOfMass1;
    hkVector4L m_qRotation0;
    hkVector4L m_qRotation1;
    hkVector4L m_vCenterOfMassLocal;
};

struct OutputArg
{
    FUN_008cd6a0_Class* ptr;
    OutputArg(FUN_008cd6a0_Class* p) : ptr(p)
    {}
};
// Interpolates a swept transform's rotation and position at time t, writing the result into out and adjusting its translation by the local center of mass.
// @fnv 0x00cf1920
void __cdecl FUN_00cf1920(const hkSweptTransform* sweptTrans, float afTime, FUN_008cd6a0_Class* apTransform, ...)
{
    hkQuaternion qResult;
    {
        hkQuaternion q0;
        q0.m_vec.m_vComponents = sweptTrans->m_qRotation0.Vector4f();
        hkQuaternion q1;
        q1.m_vec.m_vComponents = sweptTrans->m_qRotation1.Vector4f();
        qResult.m_vec.setAdd4(q0.m_vec, q1.m_vec);
        float fLengthSquared = qResult.m_vec.lengthSquared4();
        float r = (float)(0.75 - DAT_010924a8 * fLengthSquared);
        r = (float)(r * (DAT_01016ff0 - 0.5 * fLengthSquared * r * r));
        hkVector4 qhalf;
        qhalf.setMul4(r, qResult.m_vec);
        if (afTime < 0.5f)
        {
            qResult.m_vec.setInterpolate4(q0.m_vec, qhalf, afTime + afTime);
        }
        else
        {
            qResult.m_vec.setInterpolate4(qhalf, q1.m_vec, (float)(afTime + afTime - 1.0));
        }
        qResult.m_vec.normalize4();
    }
    FUN_008cd6a0_Class* pTransform = apTransform;
    reinterpret_cast<::RotationRows *>((pTransform))->FUN_00cb2d90(&qResult);

    hkVector4& vTranslation = *((hkVector4*)&pTransform->translation);
    __m128 vTimeWeight = _mm_load_ss(&afTime);
    __m128 vStartPosition = sweptTrans->m_vCenterOfMass0.Vector4f();
    __m128 vOnes = _mm_load_ps(DAT_010ec7f0);
    vTimeWeight = _mm_shuffle_ps(vTimeWeight, vTimeWeight, 0);
    __m128 vStartTerm = _mm_mul_ps(_mm_sub_ps(vOnes, vTimeWeight), vStartPosition);
    __m128 vEndTerm = _mm_mul_ps(sweptTrans->m_vCenterOfMass1.Vector4f(), vTimeWeight);
    vTranslation.m_vComponents = _mm_add_ps(vStartTerm, vEndTerm);
    hkVector4 vCenterShift;
    hkVector4 vCenterLocal;
    vCenterLocal.m_vComponents = sweptTrans->m_vCenterOfMassLocal.Vector4f();
    SetRotatedDirection(vCenterShift, *(hkMatrix3*)&pTransform->col0, vCenterLocal);
    ((hkVector4*)&pTransform->translation)->sub4(vCenterShift);
}


struct MotionExtR : FUN_008cd6a0_Class
{
    V4 deltaAngle;
};

// Computes values from time and com0/com1, then updates rot1, com1, deltaAngle, and translation.
// @fnv 0x00cf1b10
void __cdecl FUN_00cf1b10(float time, FUN_008cd6a0_Class* self)
{
    float t0 = (time - fnv_simd_as<float>(self->com0.q)[3]) * fnv_simd_as<float>(self->com1.q)[3];
    float w = (::DAT_0104da4c < t0) ? t0 : ::DAT_0104da4c;

    __m128 vRot0 = self->rot0.q;
    __m128 vRot1 = self->rot1.q;
    __m128 sum = _mm_add_ps(vRot1, vRot0);
    __m128 vSq = _mm_mul_ps(sum, sum);
    __m128 s = _mm_add_ps(vSq, _mm_shuffle_ps(vSq, vSq, 0x4E));
    s = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xB1));
    float d;
    _mm_store_ss(&d, s);
    self->rot1.q = sum;
    float y = 0.75 - d * 0.125;
    float inv = (1.5 - d * 0.5 * y * y) * y;
    __m128 vInv = _mm_load_ss(&inv);
    vInv = _mm_shuffle_ps(vInv, vInv, 0);
    self->rot1.q = _mm_mul_ps(vInv, sum);

    float a = w;
    if (w < 0.5f)
    {
        interpolate(self->rot1.q, vRot0, self->rot1.q, a + w);
    }
    else
    {
        interpolate(self->rot1.q, self->rot1.q, vRot1, (a + w) - 1.0);
    }
    normalize4(self->rot1.q);

    float& wRef = fnv_simd_as<float>(self->com1.q)[3];
    float oldW = wRef;
    interpolate(self->com1.q, self->com0.q, self->com1.q, w);
    wRef = oldW / w;
    __m128 wb = _mm_load_ss(&w);
    wb = _mm_shuffle_ps(wb, wb, 0);
    ((MotionExtR*)self)->deltaAngle.q = _mm_mul_ps(wb, ((MotionExtR*)self)->deltaAngle.q);
    reinterpret_cast<::RotationRows *>((self))->FUN_00cb2d90(&self->rot1);

    __m128 vComLocal = self->comLocal.q;
    __m128 vRy = _mm_mul_ps(_mm_shuffle_ps(vComLocal, vComLocal, 0x55), self->col1.q);
    __m128 vRx = _mm_mul_ps(_mm_shuffle_ps(vComLocal, vComLocal, 0x00), self->col0.q);
    __m128 vRz = _mm_mul_ps(_mm_shuffle_ps(vComLocal, vComLocal, 0xAA), self->col2.q);
    self->translation.q = _mm_sub_ps(self->com1.q, _mm_add_ps(_mm_add_ps(vRy, vRx), vRz));
}


extern double DAT_01012070;
struct __declspec(align(16)) hkTranslationL
{
    __m128 m_vComponents;
    __m128 Vector4f() const
    {
        return m_vComponents;
    }
    void SetQuad(__m128 v)
    {
        m_vComponents = v;
    }
    void Sub4(__m128 v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v);
    }
};
struct __declspec(align(16)) hkQuaternionL
{
    float m_uiX, m_uiY, m_uiZ, m_w;
    __m128 Get() const
    {
        return _mm_load_ps(&m_uiX);
    }
    void Set(__m128 v)
    {
        _mm_store_ps(&m_uiX, v);
    }
};
struct LocalRotation
{
    hkVector4L m_kColumn0, m_kColumn1, m_kColumn2;
    void Set(void* p)
    {
        reinterpret_cast<::RotationRows *>((reinterpret_cast<FUN_008cd6a0_Class*>(this)))->FUN_00cb2d90(p);
    }
};
struct hkTransformL
{
    LocalRotation m_rotation;
    hkTranslationL m_vTranslation;
};
struct hkSweptTransformL
{
    hkVector4L m_vCenterOfMass0, m_vCenterOfMass1;
    hkVector4L m_qRotation0, m_qRotation1, m_vCenterOfMassLocal;
};

static inline __m128 SumSquares(__m128 v)
{
    __m128 sq = _mm_mul_ps(v, v);
    __m128 h = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
    return _mm_add_ps(_mm_shuffle_ps(h, h, 0xb1), h);
}
static inline __m128 InvNorm(__m128 s)
{
    __m128 rs = _mm_rsqrt_ss(s);
    __m128 mask = _mm_cmpeq_ss(s, _mm_set_ss(::DAT_01011d78));
    __m128 prod = _mm_mul_ss(_mm_mul_ss(s, rs), rs);
    __m128 three = _mm_set_ss(::DAT_01017718);
    __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
    return _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, rs), _mm_sub_ss(three, prod)));
}

// @fnv 0x00cf1510
void __cdecl FUN_00cf1510(const hkSweptTransformL& sweptTrans, float t, hkTransformL& transformOut)
{
    const float r = (t - sweptTrans.m_vCenterOfMass0.GetW()) * sweptTrans.m_vCenterOfMass1.GetW();
    const __m128 r0 = sweptTrans.m_qRotation0.Vector4f();
    const __m128 r1 = sweptTrans.m_qRotation1.Vector4f();
    __m128 sum = _mm_add_ps(r1, r0);
    float len2;
    _mm_store_ss(&len2, SumSquares(sum));
    hkQuaternionL quat;
    quat.Set(sum);
    float invLen = (float)(::DAT_0101de30 - DAT_010924a8 * len2);
    invLen = (float)(invLen * (DAT_01016ff0 - DAT_01011588 * len2 * invLen * invLen));
    __m128 q = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&invLen), _mm_load_ss(&invLen), 0), quat.Get());
    if (r < 0.5f)
    {
        const float u = r * 2.0f;
        __m128 u4 = _mm_load_ss(&u);
        u4 = _mm_shuffle_ps(u4, u4, 0);
        __m128 part = _mm_mul_ps(_mm_sub_ps(_mm_load_ps((*reinterpret_cast<float (*)[4]>((void *)&::DAT_010ec7f0))), u4), r0);
        q = _mm_add_ps(part, _mm_mul_ps(u4, q));
    }
    else
    {
        const float u = (float)(r * 2.0f - 1.0);
        __m128 u4 = _mm_load_ss(&u);
        u4 = _mm_shuffle_ps(u4, u4, 0);
        __m128 part = _mm_mul_ps(_mm_sub_ps(_mm_load_ps((*reinterpret_cast<float (*)[4]>((void *)&::DAT_010ec7f0))), u4), q);
        q = _mm_add_ps(part, _mm_mul_ps(u4, r1));
    }
    __m128 norm = InvNorm(SumSquares(q));
    quat.Set(_mm_mul_ps(_mm_shuffle_ps(norm, norm, 0), q));
    transformOut.m_rotation.Set(&quat);
    __m128 u4 = _mm_load_ss(&r);
    u4 = _mm_shuffle_ps(u4, u4, 0);
    __m128 a = sweptTrans.m_vCenterOfMass0.Vector4f();
    __m128 b = sweptTrans.m_vCenterOfMass1.Vector4f();
    transformOut.m_vTranslation.SetQuad(
        _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps((*reinterpret_cast<float (*)[4]>((void *)&::DAT_010ec7f0))), u4), a), _mm_mul_ps(b, u4)));
    __m128 local = sweptTrans.m_vCenterOfMassLocal.Vector4f();
    __m128 shift = _mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), transformOut.m_rotation.m_kColumn1.Vector4f());
    shift =
        _mm_add_ps(shift, _mm_mul_ps(_mm_shuffle_ps(local, local, 0), transformOut.m_rotation.m_kColumn0.Vector4f()));
    shift = _mm_add_ps(shift,
                       _mm_mul_ps(_mm_shuffle_ps(local, local, 0xaa), transformOut.m_rotation.m_kColumn2.Vector4f()));
    transformOut.m_vTranslation.Sub4(shift);
}namespace fnv_00cf1710 {
extern "C" void _ReadWriteBarrier();
  // 0.125
  // 0.75
  // 0.5
  // 1.5
extern double DAT_01012070;  // 1.0
   // 0.5f
   // 0.0f
   // 3.0f

struct __declspec(align(16)) hkVector4L
{
    float x, y, z, w;
    float GetW() const
    {
        return w;
    }
    __m128 Vector4f() const
    {
        return _mm_load_ps(&x);
    }
    void SetQuad(__m128 v)
    {
        _mm_store_ps(&x, v);
    }
};

struct __declspec(align(16)) hkTranslationL
{
    __m128 m_vComponents;
    __m128 Vector4f() const
    {
        return m_vComponents;
    }
    void SetQuad(__m128 v)
    {
        m_vComponents = v;
    }
    void Sub4(__m128 v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v);
    }
};
static inline __m128 LengthSquared4(__m128 v)
{
    const __m128 sq = _mm_mul_ps(v, v);
    const __m128 h = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
    return _mm_add_ps(_mm_shuffle_ps(h, h, 0xb1), h);
}
static inline __m128 Interpolate4(__m128 a, __m128 b, float t)
{
    __m128 tt = _mm_load_ss(&t);
    tt = _mm_shuffle_ps(tt, tt, 0);
    return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps((*reinterpret_cast<float (*)[4]>((void *)&::DAT_010ec7f0))), tt), a), _mm_mul_ps(tt, b));
}
static inline __m128 SqrtInverse(__m128 r)
{
    const __m128 e = _mm_rsqrt_ss(r);
    const __m128 mask = _mm_cmpeq_ss(r, _mm_set_ss(::DAT_01011d78));
    const __m128 q = _mm_mul_ss(_mm_mul_ss(r, e), e);
    const __m128 three = _mm_set_ss(::DAT_01017718);
    const __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
    return _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, q)));
}

struct __declspec(align(16)) hkQuaternionL
{
    float m_uiX, m_uiY, m_uiZ, m_w;
    __m128 Get() const
    {
        return *reinterpret_cast<const __m128*>(&m_uiX);
    }
    void Set(__m128 v)
    {
        _mm_store_ps(&m_uiX, v);
    }
};
struct LocalRotation
{
    hkVector4L m_kColumn0;
    hkVector4L m_kColumn1;
    hkVector4L m_kColumn2;
    void Set(void* p)
    {
        reinterpret_cast<::RotationRows *>((reinterpret_cast<FUN_008cd6a0_Class*>(this)))->FUN_00cb2d90(p);
    }
};
struct hkTransformL
{
    LocalRotation m_rotation;
    hkTranslationL m_vTranslation;
};
struct hkSweptTransformL
{
    hkVector4L m_vCenterOfMass0;
    hkVector4L m_vCenterOfMass1;
    hkVector4L m_qRotation0;
    hkVector4L m_qRotation1;
    hkVector4L m_vCenterOfMassLocal;
};

// @fnv 0x00cf1710
void __cdecl FUN_00cf1710(const hkSweptTransformL& sweptTrans, float t, float deltaTimeAddon,
                          hkTransformL& transformOut)
{
    const __m128 r0 = sweptTrans.m_qRotation0.Vector4f();
    const __m128 r1 = sweptTrans.m_qRotation1.Vector4f();
    const float s = t - sweptTrans.m_vCenterOfMass0.GetW();
    __m128 sum = r1;
    sum = _mm_add_ps(sum, r0);
    const float u = s + deltaTimeAddon;
    float len2;
    _mm_store_ss(&len2, LengthSquared4(sum));
    const float r = u * sweptTrans.m_vCenterOfMass1.GetW();

    hkQuaternionL quat;
    quat.Set(sum);
    float invLen = (float)(::DAT_0101de30 - ::DAT_010924a8 * len2);
    invLen = (float)(invLen * (::DAT_01016ff0 - ::DAT_01011588 * len2 * invLen * invLen));
    __m128 qv = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&invLen), _mm_load_ss(&invLen), 0), quat.Get());
    if (r < 0.5f)
    {
        const float t2 = r * 2.0f;
        __m128 tt = _mm_load_ss(&t2);
        tt = _mm_shuffle_ps(tt, tt, 0);
        __m128 p1 = _mm_sub_ps(_mm_load_ps((*reinterpret_cast<float (*)[4]>((void *)&::DAT_010ec7f0))), tt);
        p1 = _mm_mul_ps(p1, r0);
        tt = _mm_mul_ps(tt, qv);
        qv = _mm_add_ps(p1, tt);
    }
    else
    {
        const float t2 = (float)(r * 2.0f - 1.0);
        __m128 tt = _mm_load_ss(&t2);
        tt = _mm_shuffle_ps(tt, tt, 0);
        __m128 p1 = _mm_sub_ps(_mm_load_ps((*reinterpret_cast<float (*)[4]>((void *)&::DAT_010ec7f0))), tt);
        p1 = _mm_mul_ps(p1, qv);
        tt = _mm_mul_ps(tt, r1);
        qv = _mm_add_ps(p1, tt);
    }
    const __m128 rot = qv;

    const __m128 invNorm = SqrtInverse(LengthSquared4(rot));
    quat.Set(_mm_mul_ps(_mm_shuffle_ps(invNorm, invNorm, 0), rot));
    transformOut.m_rotation.Set(&quat);

    transformOut.m_vTranslation.SetQuad(
        Interpolate4(sweptTrans.m_vCenterOfMass0.Vector4f(), sweptTrans.m_vCenterOfMass1.Vector4f(), r));

    __m128 shift;
    const __m128 local = sweptTrans.m_vCenterOfMassLocal.Vector4f();
    shift = _mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), transformOut.m_rotation.m_kColumn1.Vector4f());
    shift = _mm_add_ps(shift,
                       _mm_mul_ps(_mm_shuffle_ps(local, local, 0x00), transformOut.m_rotation.m_kColumn0.Vector4f()));
    shift = _mm_add_ps(shift,
                       _mm_mul_ps(_mm_shuffle_ps(local, local, 0xaa), transformOut.m_rotation.m_kColumn2.Vector4f()));
    transformOut.m_vTranslation.Sub4(shift);
}
}

struct TimeInterval
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

struct SweptTransform
{
    hkVector4 m_vCenterOfMass0;
    hkVector4 m_vCenterOfMass1;
    hkQuaternion m_qRotation0;
    hkQuaternion m_qRotation1;
    hkVector4 m_vCenterOfMassLocal;
};

struct MotionState
{
    hkVector4 m_rot0;
    hkVector4 m_rot1;
    hkVector4 m_rot2;
    hkVector4 m_vTranslation;
    SweptTransform m_kSweptTransform;
    hkVector4 m_kDeltaAngle;
    void SetRotation(const hkQuaternion* p)
    {
        reinterpret_cast<::RotationRows *>((reinterpret_cast<FUN_008cd6a0_Class*>(this)))->FUN_00cb2d90((void*)p);
    }
};

struct Bool8
{
    unsigned char b;
};

struct __declspec(align(16)) Quat
{
    float x, y, z, w;
    Bool8* FUN_00ce1500(Bool8* o);
    void FUN_00c74c90(hkVector4* out);
};

struct __declspec(align(16)) TempVec
{
    float x, y, z, w;
};

// @fnv 0x00cf2180
void __cdecl FUN_00cf2180(const TimeInterval& info, const hkVector4& pos1, const hkQuaternion& rot1, MotionState& ms)
{
    SweptTransform& st = ms.m_kSweptTransform;
    st.m_vCenterOfMass0 = st.m_vCenterOfMass1;
    st.m_qRotation0 = st.m_qRotation1;
    st.m_vCenterOfMass1 = pos1;
    st.m_qRotation1 = rot1;

    Quat diff;
    reinterpret_cast<::Quat74 *>(&(diff))->FUN_00c74ac0((*(const ::Quat74 *)(&rot1)), (*(const ::Quat74 *)(&st.m_qRotation0)));
    float angle = reinterpret_cast<::C74C20Quat *>(&(diff))->GetAngle();
    hkVector4 axis;
    Bool8 ok;
    if (diff.FUN_00ce1500(&ok)->b != 0)
    {
        TempVec t;
        diff.FUN_00c74c90((hkVector4*)&t);
        axis = *(hkVector4*)&t;
    }
    else
    {
        axis.setZero4();
    }
    ms.m_kDeltaAngle.setMul4(angle, axis);
    ms.m_kDeltaAngle(3) = angle;
    st.m_vCenterOfMass0(3) = info.m_uiStartTime;
    st.m_vCenterOfMass1(3) = info.m_fInverseDeltaTime;

    ms.SetRotation(&st.m_qRotation1);
    __m128 m80 = st.m_vCenterOfMassLocal.m_vComponents;
    __m128 sum = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m80, m80, 0x55), ms.m_rot1.m_vComponents),
                            _mm_mul_ps(_mm_shuffle_ps(m80, m80, 0), ms.m_rot0.m_vComponents));
    sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(m80, m80, 0xaa), ms.m_rot2.m_vComponents));
    ms.m_vTranslation.m_vComponents = _mm_sub_ps(st.m_vCenterOfMass1.m_vComponents, sum);
}

#include "generated/data/havok/common/base/math/swepttransform/hkswepttransformutil.inc"
