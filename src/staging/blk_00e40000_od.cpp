
// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/GridCell.h"
#include "fnv/decl/MoppFindAllVM.h"
#include "fnv/decl/MoppFindAllVirtualMachine.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/hkpMoppFindAllVirtualMachine.h"
#include "fnv/decl/xSphereMachine.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00e50000.h"
#include "fnv/symbols_010d5000.h"
#include "fnv/symbols_01268000.h"
#include "fnv_asm_helpers.h"
#include <math.h>
#include "fnv/symbols_simd.h"
#include <cmath>
#include "fnv/decl/ObbQueryDetail__ObbMachine.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/decl/S_00e647e0.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/decl/AttributeFormatter.h"
#include "fnv/symbols_010ec000.h"

struct FloatLess
{
	bool operator()(const float& a, const float& b) const { return a < b; }
};

// @fnv 0x00e50f10
void __cdecl FUN_00e50f10(float* pArr, int d, int h, FloatLess cmpLess)
{
	int i, j;
	__declspec(align(16)) float str;

loop:
	i = h;
	j = d;
	str = pArr[(d + h) >> 1];
	do
	{
		while (cmpLess(pArr[j], str)) j++;
		while (cmpLess(str, pArr[i])) i--;

		if (j <= i)
		{
			if (i != j)
			{
				float t = pArr[i];
				pArr[i] = pArr[j];
				pArr[j] = t;
			}
			i--;
			j++;
		}
	} while (j <= i);

	if (d < i)
	{
		FUN_00e50f10(pArr, d, i, cmpLess);
	}
	if (j < h)
	{
		d = j;
		goto loop;
	}
}

static inline __m128 Dot3v(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}

static inline __m128 Dot3_e4b570(__m128 p)
{
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}

// @fnv 0x00e4b570
int __cdecl FUN_00e4b570(const __m128* point, const __m128* verts, float* out)
{
    float zero = 0.0f;
    float one = -1.0f;
    int b = 2;
    int a = 1;
    for (int i = 0; i < 3; i++)
    {
        if (out[i] >= zero && out[a] >= zero)
        {
            __m128 o = verts[b];
            __m128 A = _mm_sub_ps(verts[i], o);
            __m128 B = _mm_sub_ps(verts[a], verts[b]);
            __m128 P = _mm_sub_ps(point[0], o);
            __m128 C = _mm_sub_ps(verts[3], o);
            __m128 dPA = Dot3v(P, A);
            __m128 dPB = Dot3v(P, B);
            __m128 dCA = Dot3v(C, A);
            __m128 dCB = Dot3v(C, B);
            __m128 r = _mm_sub_ss(_mm_mul_ss(dPA, dCB), _mm_mul_ss(dPB, dCA));
            if (_mm_movemask_ps(r) & 1)
                out[a] = one;
            else
                out[i] = one;
        }
        a = b;
        b = i;
    }
    if (out[0] > zero) return 0;
    if (out[1] > zero) return 1;
    if (out[2] > zero) return 2;
    return -1;
}

// stand-in for the local object whose method is called
struct LocalObj {
    int m_unk00;
    int m_unk01;
    int m_unk02;
    int m_unk03;
    int m_unk04;
    int m_unk05;
    int m_unk06;
    int m_unk07;
    int m_unk08;
    int m_unk09;
    int m_unk10;
    int m_unk11;
    int m_unk12;
    int m_unk13;
    int m_unk14;
    int m_unk15;
    int m_unk16;
    int m_unk17;
    int m_unk18;
    int m_unk19;
    char* SetupAndProcessShape(char* buf, void* a1, int a2, int a3, int a4);
};

// @fnv 0x00e5cf00
int __cdecl FUN_00e5cf00(void* a1, int a2, int a3, int a4)
{
    __declspec(align(16)) LocalObj obj;
    char buf;
    return obj.SetupAndProcessShape(&buf, a1, a2, a3, a4)[0] != 0;
}

struct __declspec(align(16)) Vec4E5 { float x, y, z, w; };

struct TmpE5CF40 { Vec4E5 a, b;  };

// @fnv 0x00e5cf40
void __cdecl FUN_00e5cf40(int a, int b, int c)
{
    TmpE5CF40 tmp;
    reinterpret_cast<::xSphereMachine *>(&(tmp))->FUN_00e64f00((const ::xMoppCode *)(a), (*(const ::xSphere *)(b)), (::HitArray *)(c));
}

struct __declspec(align(16)) FUN_00e5d010_Block {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
};

// @fnv 0x00e5d010
extern "C" void __cdecl FUN_00e5d010(int first,int second,int third)
{
    FUN_00e5d010_Block instance;
    reinterpret_cast<::GridCell *>(&(instance))->FUN_00dd1da0((::GridSource *)(first),(::GridBounds *)(second),third);
}

extern "C" void _ReadWriteBarrier();

extern "C" void _ReadBarrier();

extern "C" void _WriteBarrier();

struct hkQuatStore_e52d90 { __m128 m_vec; };

struct Shorts_e52d90 { short a; short b; short c; };

// @fnv 0x00e52d90
void __cdecl FUN_00e52d90(const unsigned short* in, hkQuatStore_e52d90* out)
{
    static const float s_scale = (float)(1.0 / ((float)sqrt(2.0) * 16383.0));
    Shorts_e52d90 v;
    v.a = in[0] & 0x7fff;
    v.b = in[1] & 0x7fff;
    v.c = in[2] & 0x7fff;
    int missing = ((in[1] & 0x8000) | (in[0] >> 1)) >> 14;
    __m128 zero = _mm_setzero_ps();
    out->m_vec = zero;
    float* f = (float*)&out->m_vec;
    int i = (missing == 0);
    f[i] = (v.a - 0x3fff) * s_scale;
    i++;
    i += (i == missing);
    f[i] = (v.b - 0x3fff) * s_scale;
    i++;
    f[i + (i == missing)] = (v.c - 0x3fff) * s_scale;
    __m128 sq = _mm_mul_ps(out->m_vec, out->m_vec);
    sq = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
    sq = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0xb1), sq);
    float sum; _mm_store_ss(&sum,sq);
    f[missing] = sqrtf(1.0f-sum);
    if (in[2] & 0x8000)
        f[missing] = -f[missing];
}

extern "C" void _ReadWriteBarrier();

static __forceinline int readPacked(const unsigned char* q) {int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}

static __forceinline int readUpper(const unsigned char* q) {return ((q[0]<<8)+q[1]<<8)+q[2];}

struct P1 { union { struct { int f0; int f4; int xyz[3]; int f14; }; int fields[6]; }; };

struct V4 { union { __m128 m; float f[4]; };
 __forceinline void setAdd(const V4& a,const V4& b){m=_mm_add_ps(a.m,b.m);}
 __forceinline void setSub(const V4& a,const V4& b){m=_mm_sub_ps(a.m,b.m);}
 __forceinline void setMin(const V4& a,const V4& b){m=_mm_min_ps(a.m,b.m);}
 __forceinline void sub(const V4& a){m=_mm_sub_ps(m,a.m);}
 __forceinline void add(const V4& a){m=_mm_add_ps(m,a.m);}
 __forceinline void abs(const __m128& mask){m=_mm_and_ps(m,mask);}
 __forceinline float lengthSquared3() const {
  __m128 square=_mm_mul_ps(m,m); float r;
  _mm_store_ss(&r,_mm_add_ss(_mm_shuffle_ps(square,square,0xaa),_mm_add_ss(_mm_shuffle_ps(square,square,0x55),square)));
  return r;
 }
};

struct F8 { V4 lower, upper; };

struct BoundsRef { F8* p; F8* operator->() const { return p; } operator F8*() const { return p; } };

struct Vec { int* base; int count; int cap; };

struct Resource { int unk00, unk04, unk08, unk0c; void* allocator; };

extern void* FUN_00c85750();

static const __declspec(align(16)) unsigned int AbsMask[4] = { 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff };

struct Diagnostic {
  int unk00, unk04, unk08;
};

struct ErrorReporter {
  virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2();
  virtual int report(int, unsigned int, const char*, const char*, int);
};

struct Query {
  __forceinline int classify(P1* state, unsigned char* stream, int offset, F8* bounds) {
    float r2 = center[3] * center[3];
    V4 sum, extent, outside;
    sum.setAdd(bounds->upper,bounds->lower);
    extent.setSub(bounds->upper,bounds->lower);
    sum.sub(*(const V4*)center);
    sum.abs(*(const __m128*)AbsMask);
    outside.setMin(sum,extent);
    outside.sub(sum);
    float near2=outside.lengthSquared3();
    if(near2>r2) return 0;
    extent.add(sum);
    float far2=extent.lengthSquared3();
    if(far2<r2){reinterpret_cast<::hkpMoppFindAllVirtualMachine *>(this)->FUN_00e65ee0((const ::MoppState *)(state),stream+offset);return 1;}
    return 2;
  }
  __forceinline int classifyLocal(P1* state, unsigned char* stream, int offset, F8* bounds) {
    float r2 = center[3] * center[3];
    V4 sum, extent, outside;
    sum.setAdd(bounds->upper,bounds->lower);
    extent.setSub(bounds->upper,bounds->lower);
    sum.sub(*(const V4*)center);
    sum.abs(*(const __m128*)AbsMask);
    outside.setMin(sum,extent);
    outside.sub(sum);
    float near2=outside.lengthSquared3();
    if(near2>r2) return 0;
    extent.add(sum);
    float far2=extent.lengthSquared3();
    if(far2<r2){reinterpret_cast<::hkpMoppFindAllVirtualMachine *>(this)->FUN_00e65ee0((const ::MoppState *)(state),stream+offset);return 1;}
    return 2;
  }
  Vec* results; int unk24; int unk28; int unk2c;
  float center[4];
};

struct Cls {
  Vec* vec;
  int unk04; int unk08; int unk0c;
  float scale;
  int unk14; int unk18; int unk1c;
  Query query;
  __forceinline void scan(P1* cur, unsigned char* p, int& offset, F8* const bounds) {
    int code;
      code = p[offset];
      while (code >= 38 && 43 >= code) {
        if (code >= 41) {
          bounds->lower.f[code - 41] = (float)readPacked(p+offset+1) * scale;
          bounds->upper.f[code - 41] = (float)((((p[offset+4] << 8) + p[offset+5]) << 8) + p[offset+6]) * scale;
          offset += 7;
        } else {
          bounds->lower.f[code - 38] = (float)((p[offset+1] << cur->f14) + cur->fields[code - 36]) * scale;
          bounds->upper.f[code - 38] = (float)((p[offset+2] << cur->f14) + cur->fields[code - 36]) * scale;
          offset += 3;
        }
        code = p[offset];
      }

  }
  __forceinline void scanRight(P1* cur, unsigned char* p, int& offset, F8* const bounds) {
    int code;
      code = p[offset];
      while (code >= 38 && 43 >= code) {
        if (code >= 41) {
          bounds->lower.f[code - 41] = (float)readPacked(p+offset+1) * scale;
          bounds->upper.f[code - 41] = (float)readUpper(p+offset+4)*scale;
          offset += 7;
        } else {
          bounds->lower.f[code - 38] = (float)((p[offset+1] << cur->f14) + cur->fields[code - 36]) * scale;
          bounds->upper.f[code - 38] = (float)((p[offset+2] << cur->f14) + cur->fields[code - 36]) * scale;
          offset += 3;
        }
        code = p[offset];
      }

  }
  void FUN_00e5f070(P1* a1, unsigned char* p, F8* a3);
  __forceinline void interpret(P1* a1, unsigned char* p, F8* const& a3);
};

__forceinline void Cls::interpret(P1* a1, unsigned char* p, F8* const& a3) {
  P1 local;
  F8 val;
  P1* cur = a1;
  int left, right, code;
  for (;;) {
    int op = *p;
    switch (op) {
    case 0: return;
    case 19: case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: {
      right = p[3];
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      p += 4;
      F8* child=&val;
      FUN_00e5f070(cur, p, child);
      p += right;
      break;
    }
    case 16: case 17: case 18: {
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      int r;
      r = p[2];
      a3->upper.f[op - 16] = (float)((p[1] << cur->f14) + cur->fields[op - 14]) * scale;
      val.lower.f[op - 16] = (float)((r << cur->f14) + cur->fields[op - 14]) * scale;
      left = 0; p += 4; right = p[-1];
      goto branch_common;
    }
    case 32: case 33: case 34: {
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      int r = p[1] + 1;
      val.lower.f[op - 32] = (float)((p[1] << cur->f14) + cur->fields[op - 30]) * scale;
      a3->upper.f[op - 32] = (float)((r << cur->f14) + cur->fields[op - 30]) * scale;
      left = 0; p += 3; right = p[-1];
      goto branch_common;
    }
    case 35: case 36: case 37: {
      val.lower.m = a3->lower.m;
      val.upper.m = a3->upper.m;
      long r;
      r = p[2];
      a3->upper.f[op - 35] = (float)((p[1] << cur->f14) + cur->fields[op - 33]) * scale;
      val.lower.f[op - 35] = (float)((r << cur->f14) + cur->fields[op - 33]) * scale;
      left = ((unsigned int)p[3] << 8) + p[4];
      right = ((unsigned int)p[5] << 8) + p[6];
      p += 7;
    }
    branch_common: {
      scan(cur, p, left, a3);
      F8* scanned=&val; scanRight(cur, p, right, scanned);
      int second = query.classifyLocal(cur, p, right, &val);
      int loc = query.classify(cur, p, left, a3);
      if (second != 2) {
        if (loc != 2) return;
        p += left;
      } else if (loc != 2) {
        F8* destination = a3;
        destination->lower.m = val.lower.m;
        destination->upper.m = val.upper.m;
        p += right;
      } else {
        F8* child=&val;
        FUN_00e5f070(cur, p + right, child);
        p += left;
      }
      break;
    }
    case 41: case 42: case 43:
      a3->lower.f[op - 41] = (float)readPacked(p+1) * scale;
      a3->upper.f[op - 41] = (float)((((p[4] << 8) + p[5]) << 8) + p[6]) * scale;
      p += 7;
      goto preserve_metadata;
    case 38: case 39: case 40:
      a3->lower.f[op - 38] = (float)((p[1] << cur->f14) + cur->fields[op - 36]) * scale;
      a3->upper.f[op - 38] = (float)((p[2] << cur->f14) + cur->fields[op - 36]) * scale;
      p += 3;
    preserve_metadata:
      if (*p >= 38 && *p <= 43) break;
      {
        int result = query.classify(cur, p, 0, a3);
        if (!result) return;
        if (1 == result) return;
      }
      break;
    case 5: p += (unsigned int)p[1] + 2; break;
    case 6: p += ((unsigned int)p[1] << 8) + p[2] + 3; break;
    case 7: p += ((((unsigned int)p[1] << 8) + p[2]) << 8) + p[3] + 4; break;
    case 1: case 2: case 3: case 4: {
      local.xyz[0] = (int)((unsigned int)p[1] << cur->f14) + cur->xyz[0];
      local.xyz[1] = (int)((unsigned int)p[2] << cur->f14) + cur->xyz[1];
      local.xyz[2] = (int)((unsigned int)p[3] << cur->f14) + cur->xyz[2];
      local.f14 = cur->f14 - (int)op;
      local.f4 = cur->f4;
      local.f0 = cur->f0;
      cur = &local;
      p += 4;
      break;
    }
    case 9: {
      int keep = p[1];
      if (cur != &local) { local = *cur; cur = &local; }
      local.f0 += keep;
      p += 2;
      break;
    }
    case 10: {
      int keep = (p[1] << 8) + p[2];
      if (cur != &local) { local = *cur; cur = &local; }
      local.f0 += keep;
      p += 3;
      break;
    }
    case 11: {
      int keep = (readPacked(p+1) << 8) + p[4];
      if (cur != &local) { local = *cur; cur = &local; }
      local.f0 = keep;
      p += 5;
      break;
    }
    case 96: case 97: case 98: case 99: {
      int keep = p[1];
      p += 2;
      local.fields[op - 95] = keep;
      goto slot;
    }
    case 100: case 101: case 102: case 103: {
      int keep = (int)(((unsigned int)p[1] << 8) + p[2]);
      local.fields[op - 99] = keep;
      p += 3;
      goto slot;
    }
    case 104: case 105: case 106: case 107: {
      int keep = (int)(((((((unsigned int)p[1] << 8) + p[2]) << 8) + p[3]) << 8) + p[4]);
      local.fields[op - 103] = keep;
      p += 5;
      goto slot;
    }
    slot: {
      int pForm;
      pForm = local.f4;
      if (cur != &local) { local = *cur; cur = &local; }
      local.f4 = pForm;
      break;
    }
    default: {
      Diagnostic high;
      int buffer[128];
      new ((void *)&(high)) ::FUN_00cb1600((char*)buffer, 512);
      reinterpret_cast<::SinkOwner *>(&(high))->FUN_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
      if (((ErrorReporter*)(*reinterpret_cast<int *>(&::DAT_01268360)))->report(3, 0x1298fedd, (char*)buffer, "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Physics/Internal/Collide/Mopp/Machine/hkpMoppUsingFloatAabbVirtualMachine.inl", 301)) __debugbreak();
      reinterpret_cast<struct ::FUN_00cc00e0 *>(&(high))->FUN_00cc00e0::~FUN_00cc00e0();
      break;
    }
    case 80: right = p[1]; goto append;
    case 81: right = ((p[1] << 8) + p[2]); goto append;
    case 82: right = (((p[1] << 8) + p[2]) << 8) + p[3]; goto append;
    case 83: right = (readPacked(p+1) << 8) + p[4]; goto append;
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
    case 56: case 57: case 58: case 59: case 60: case 61: case 62: case 63:
    case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71:
    case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79:
      right = op - 48;
    append: {
      Vec* item=vec; unsigned int bounds_test=right; _ReadWriteBarrier(); *(volatile int*)&right=right; bounds_test+=cur->f0;
      Resource* first = (Resource*)FUN_00c85750();
      if (item->count == (item->cap & 0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(first->allocator), (::AudioStream *)(item), 4);
      int* message = &item->base[item->count++];
      *message = bounds_test;
      return;
    }
    }
  }
}

// @fnv 0x00e5f070
void Cls::FUN_00e5f070(P1* a1, unsigned char* p, F8* a3) { interpret(a1, p, a3); }

extern "C" void _ReadWriteBarrier();

__forceinline int rightPacked(const unsigned char* q){return ((q[0]<<8)+q[1]<<8)+q[2];}

extern "C" void _ReadWriteBarrier();

__forceinline int packedLocal(const unsigned char* q){_ReadWriteBarrier(); int a=q[0]; return ((a<<8)+q[1]<<8)+q[2];}

extern "C" void _ReadWriteBarrier();

static __forceinline int read24(const unsigned char* q) {_ReadWriteBarrier(); int a=q[0]; int b=q[1]; int c=q[2]; return ((a<<8)+b<<8)+c;}

extern "C" void __debugbreak();

struct IntegerOrigin { int x,y,z; int& operator[](int i) { return (&x)[i]; }
    int volatileAt(int i) const { return reinterpret_cast<const volatile int*>(&x)[i]; } };

struct DecodeState {
    int baseID; int property; IntegerOrigin origin; int shift;
    int& propertyAt(int i) { return (&property)[i]; }
};

struct __declspec(align(16)) BoundsPair { __m128 minimum; __m128 maximum;
    BoundsPair& operator=(const BoundsPair& b) { minimum=b.minimum; maximum=b.maximum; return *this; }
};

struct OutputArray { int* data; int size; int capacity; };

struct AllocatorContext { int unk00; int unk04; int unk08; int unk0C; void* allocator; };

struct DiagnosticStream {
    void* vtable; int flags; void* writer;
};

extern const char str_010ecd88[];

struct __declspec(align(16)) PlanePacket { __m128 x,y,z,w; };

struct CullMachine {
    int unk00; int unk04; int unk08; int unk0C; int count; int unk14; int unk18; int unk1C;
    PlanePacket planes[8];
    PlanePacket absolutePlanes[8];
    __forceinline int classify(DecodeState* state, const unsigned char* code, const BoundsPair& bounds) {
        int allInside = 15;
        const PlanePacket* p=planes;
        const PlanePacket* q=absolutePlanes;
        __m128 center = _mm_add_ps(bounds.maximum, bounds.minimum);
        __m128 extent = _mm_sub_ps(bounds.maximum, bounds.minimum);
        for (int n=count; --n >= 0; ++p, ++q) {
            __m128 radius = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&q->x)),_mm_shuffle_ps(extent,extent,0)),
                           _mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&q->y)),_mm_shuffle_ps(extent,extent,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&q->z)),_mm_shuffle_ps(extent,extent,0xaa)),_mm_load_ps(reinterpret_cast<float*>(&q->w))));
            __m128 distance = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&p->x)),_mm_shuffle_ps(center,center,0)),
                           _mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&p->y)),_mm_shuffle_ps(center,center,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&p->z)),_mm_shuffle_ps(center,center,0xaa)),_mm_load_ps(reinterpret_cast<float*>(&p->w))));
            if (_mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(distance,radius),_mm_setzero_ps())) != 15) return 0;
            allInside &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(distance,radius),_mm_setzero_ps()));
        }
        if (allInside == 15) {
            reinterpret_cast<::MoppFindAllVirtualMachine *>(this)->FUN_00e66600((const ::MoppState *)(state),code);
            reinterpret_cast<::MoppFindAllVM *>(this)->FUN_00e66290((const ::MoppQueryState *)(state),code);
            return 1;
        }
        return 2;
    }
    __forceinline int classifyB(DecodeState* state, const unsigned char* code, const BoundsPair& bounds) {
        const __m128& lower=bounds.minimum;
        int allInside = 15;
        int n=count;
        const PlanePacket* p=planes;
        const PlanePacket* q=absolutePlanes;
        __m128 center = _mm_add_ps(bounds.maximum, lower);
        __m128 extent = _mm_sub_ps(bounds.maximum, lower);
        for (; --n >= 0; ++p, ++q) {
            __m128 px=p->x;
            __m128 radius = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(q->x,_mm_shuffle_ps(extent,extent,0)),
                           _mm_mul_ps(q->y,_mm_shuffle_ps(extent,extent,0x55))),
                _mm_add_ps(_mm_mul_ps(q->z,_mm_shuffle_ps(extent,extent,0xaa)),q->w));
            __m128 distance = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(center,center,0),px),
                           _mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&p->y)),_mm_shuffle_ps(center,center,0x55))),
                _mm_add_ps(_mm_mul_ps(_mm_load_ps(reinterpret_cast<float*>(&p->z)),_mm_shuffle_ps(center,center,0xaa)),_mm_load_ps(reinterpret_cast<float*>(&p->w))));
            if (_mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(distance,radius),_mm_setzero_ps())) != 15) return 0;
            allInside &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(distance,radius),_mm_setzero_ps()));
        }
        if (allInside == 15) {
            reinterpret_cast<::MoppFindAllVirtualMachine *>(this)->FUN_00e66600((const ::MoppState *)(state),code);
            reinterpret_cast<::MoppFindAllVM *>(this)->FUN_00e66290((const ::MoppQueryState *)(state),code);
            return 1;
        }
        return 2;
    }
};

struct TreeDecoder {
    OutputArray* output;
    int unk04; int unk08; int unk0C; float scale; int unk14; int unk18; int unk1C;
    CullMachine cull;
    void FUN_00e5e430(DecodeState*, const unsigned char*, BoundsPair*);
    __forceinline void emit(int value) {
        OutputArray* a = output;
        AllocatorContext* context = (AllocatorContext*)FUN_00c85750();
        if (a->size == (a->capacity & 0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(context->allocator),(::AudioStream *)(a),4);
        int* destination = &a->data[a->size]; ++a->size; *destination = value;
    }
    __forceinline void readBounds(DecodeState* state, const unsigned char* code, int& offset, BoundsPair& bounds, const float& scalar) {
        int op = code[offset];
        while (op >= 0x26 && op <= 0x2b) {
            if (op >= 0x29) {
                bounds.minimum[op-0x29] = read24(code+offset+1)*scalar;
                bounds.maximum[op-0x29] = int(((code[offset+4]<<8)+code[offset+5]<<8)+code[offset+6])*scalar;
                offset += 7;
            } else {
                bounds.minimum[op-0x26] = (state->origin[op-0x26] + (code[offset+1]<<state->shift))*scalar;
                bounds.maximum[op-0x26] = (state->origin[op-0x26] + (code[offset+2]<<state->shift))*scalar;
                offset += 3;
            }
            op = code[offset];
        }
    }    __forceinline void readBoundsRight(DecodeState* state, const unsigned char* code, int& offset, BoundsPair& bounds) {
        int op = code[offset];
        while (op >= 0x26 && op <= 0x2b) {
            if (op >= 0x29) {
                bounds.minimum[op-0x29] = read24(code+offset+1)*scale;
                bounds.maximum[op-0x29] = (int)rightPacked(code+offset+4)*scale;
                offset += 7;
            } else {
                bounds.minimum[op-0x26] = (state->origin[op-0x26] + (code[offset+1]<<state->shift))*scale;
                bounds.maximum[op-0x26] = (state->origin[op-0x26] + (code[offset+2]<<state->shift))*scale;
                offset += 3;
            }
            op = code[offset];
        }
    }

};

// @fnv 0x00e5e430
void TreeDecoder::FUN_00e5e430(DecodeState* state, const unsigned char* code, BoundsPair* bounds)
{
    DecodeState localState;
    BoundsPair localBounds;
    void* buffer[128]; DiagnosticStream stream;
    int diagnosticResult;
    int left, right, value;
    for (;;) {
        int op = *code;
        if ((unsigned)op > 0x6b) {
            new ((void *)&(stream)) ::FUN_00cb1600(buffer,512);
            reinterpret_cast<::SinkOwner *>(&(stream))->FUN_00cc01c0(str_010d5100);
            diagnosticResult=((ErrorReporter*)(*reinterpret_cast<int *>(&::DAT_01268360)))->report(3,0x1298fedd,(const char*)buffer,str_010ecd88,301);
            goto DiagnosticTail;
        }
        switch (op) {
        case 0: return;
        case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c: {
            int skip=code[3]; localBounds=*bounds; code+=4;
            FUN_00e5e430(state,code,&localBounds); code+=skip; break;
        }
        case 0x10: case 0x11: case 0x12: {
            localBounds=*bounds;
            int v1=code[1], v2=code[2];
            bounds->maximum[op-0x10]=(state->origin[op-0x10]+(v1<<state->shift))*scale;
            localBounds.minimum[op-0x10]=(state->origin[op-0x10]+(v2<<state->shift))*scale;
            left=0; right=code[3]; code+=4; goto split; }
        case 0x20: case 0x21: case 0x22: {
localBounds=*bounds; int r=code[1]+1; localBounds.minimum[op-0x20]=(state->origin[op-0x20]+(code[1]<<state->shift))*scale; bounds->maximum[op-0x20]=(state->origin[op-0x20]+(r<<state->shift))*scale;
            left=0; right=code[2]; code+=3; goto split;
        }
        case 0x23: case 0x24: case 0x25: {
            localBounds=*bounds;
            int v1=code[1],v2=code[2];
            bounds->maximum[op-0x23]=(state->origin[op-0x23]+(v1<<state->shift))*scale;
            localBounds.minimum[op-0x23]=(state->origin[op-0x23]+(v2<<state->shift))*scale;
            int lh=code[3],rh=code[5],ll=code[4],rl=code[6];
            left=(lh<<8)+ll; right=(rh<<8)+rl; code+=7; }
        split: {
            readBounds(state,code,left,*bounds,scale);
            readBoundsRight(state,code,right,localBounds);
            const unsigned char* rightCode=code+right;
            int rightResult=cull.classify(state,rightCode,localBounds);
            const unsigned char* leftCode=code+left;
            int leftResult=cull.classify(state,leftCode,*bounds);
            if (rightResult != 2) { if (leftResult != 2) return; code=leftCode; }
            else if (leftResult != 2) { *bounds=localBounds; code=rightCode; }
            else { FUN_00e5e430(state,rightCode,&localBounds); code=leftCode; }
            break;
        }
        case 0x29: case 0x2a: case 0x2b:
            bounds->minimum[op-0x29]=packedLocal(code+1)*scale;
            bounds->maximum[op-0x29]=read24(code+4)*scale;
            code+=7; goto cullBounds;
        case 0x26: case 0x27: case 0x28:
            bounds->minimum[op-0x26]=(state->origin[op-0x26]+(code[1]<<state->shift))*scale;
            bounds->maximum[op-0x26]=(state->origin[op-0x26]+(code[2]<<state->shift))*scale;
            code+=3;
        cullBounds:
            if (*code >=0x26 && *code<=0x2b) break;
            { int result=cull.classifyB(state,code,*bounds); if(result!=2) return; }
            break;
        case 5: code+=code[1]+2; break;
        case 6: code+=(code[1]<<8)+code[2]+3; break;
        case 7: code+=(((code[1]<<8)+code[2])<<8)+code[3]+4; break;
        case 1: case 2: case 3: case 4:
            localState.origin[0]=state->origin[0]+(code[1]<<state->shift);
            localState.origin[1]=state->origin[1]+(code[2]<<state->shift);
            localState.origin[2]=state->origin[2]+(code[3]<<state->shift);
            localState.shift=state->shift-op;
            localState.property=state->property; localState.baseID=state->baseID;
            state=&localState; code+=4; break;
        case 9: {
            int value=code[1];
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.baseID+=value; code+=2; break;
        }
        case 10: {
            int value=(code[1]<<8)+code[2];
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.baseID+=value; code+=3; break;
        }
        case 11: {
            int value=((((code[1]<<8)+code[2])<<8)+code[3])<<8; value+=code[4];
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.baseID=value; code+=5; break;
        }
        case 0x60: case 0x61: case 0x62: case 0x63:
            { int propertyValue=code[1]; code+=2; localState.propertyAt(op-0x60)=propertyValue; goto property; }
        case 0x64: case 0x65: case 0x66: case 0x67:
            localState.propertyAt(op-0x64)=(code[1]<<8)+code[2]; code+=3; goto property;
        case 0x68: case 0x69: case 0x6a: case 0x6b:
            localState.propertyAt(op-0x68)=((((((code[1]<<8)+code[2])<<8)+code[3])<<8)+code[4]); code+=5;
        property: {
            int value=localState.property;
            if(state!=&localState) {localState=*state;state=&localState;}
            localState.property=value; break;
        }
        default: {

            new ((void *)&(stream)) ::FUN_00cb1600(buffer,512);
            reinterpret_cast<::SinkOwner *>(&(stream))->FUN_00cc01c0(str_010d5100);
            diagnosticResult=((ErrorReporter*)(*reinterpret_cast<int *>(&::DAT_01268360)))->report(3,0x1298fedd,(const char*)buffer,str_010ecd88,301);
        DiagnosticTail:
            if(diagnosticResult) __debugbreak();
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(stream))->FUN_00cc00e0::~FUN_00cc00e0(); break;
        }
        case 0x50: value=code[1]; goto terminal;
        case 0x51: value=(code[1]<<8)+code[2]; goto terminal;
        case 0x52: value=(((code[1]<<8)+code[2])<<8)+code[3]; goto terminal;
        case 0x53: value=(((((code[1]<<8)+code[2])<<8)+code[3])<<8)+code[4]; goto terminal;
        case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
        case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f:
        case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
        case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f:
            value=op-0x30;
        terminal: value += state->baseID; emit(value); return;
        }
    }
}

struct hkQuatStore_e52190 { __m128 m_vec; };

// @fnv 0x00e52190
void __cdecl FUN_00e52190(const hkQuatStore_e52190* q, unsigned char* out)
{
    static const float s_scale = (float)((float)sqrt(2.0) * 63.0);
    __m128 a = _mm_and_ps(q->m_vec, DAT_01017d10);
    const float* f = (const float*)&q->m_vec;
    int idx = 0;
    if (a[1] > a[0]) idx = 1;
    if (a[2] > a[idx]) idx = 2;
    if (a[3] > a[idx]) idx = 3;
    int i = (idx == 0);
    float sc = s_scale;
    unsigned char c[3];
    c[0] = (unsigned char)((int)(f[i++] * sc) + 0x3f);
    i += (i == idx);
    c[1] = (unsigned char)((int)(f[i++] * sc) + 0x3f);
    c[2] = (unsigned char)((int)(f[i + (i == idx)] * sc) + 0x3f);
    out[0] = (unsigned char)((idx << 7) | c[0]);
    out[1] = (unsigned char)(((idx & ~1) << 6) | c[1]);
    out[2] = c[2];
    out[2] = (unsigned char)(((f[idx] < 0.0f) << 7) | c[2]);
}

struct RotationVector
{
    __m128 m_vComponents;
    float& operator()(int i)
    {
        return m_vComponents[i];
    }
};

extern const __m128 DAT_01017d10;

static __forceinline float AbsValue(float r)
{
    return (float)fabs(r);
}

static __forceinline float SafeAcos(float r)
{
    if (AbsValue(r) >= 1.0f)
    {
        r = r > 0.0f ? 0.0f : 3.1415927410125732421875f;
        return r;
    }
    return (float)acos(r);
}

// @fnv 0x00e52320
void __cdecl FUN_00e52320(const RotationVector* rotation, unsigned int* packed)
{
    RotationVector value = *rotation;
    *packed = 0;
    int sx = value(0) < 0.0f ? 1 : 0;
    int sy = value(1) < 0.0f ? 1 : 0;
    int sz = value(2) < 0.0f ? 1 : 0;
    int sw = value(3) < 0.0f ? 1 : 0;
    *packed = (sx | sy << 1 | sz << 2 | sw << 3) << 28;
    value.m_vComponents = _mm_and_ps(DAT_01017d10, value.m_vComponents);
    float magnitude = value(3);
    if (value(0) != 0.0f || value(1) != 0.0f || value(2) != 0.0f)
    {
        __m128 lanes = value.m_vComponents;
        __m128 squared = _mm_mul_ps(lanes, lanes);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), sum);
        __m128 estimate = _mm_rsqrt_ss(sum);
        __m128 mask = _mm_cmpeq_ss(sum, _mm_set_ss(DAT_01011d78));
        squared = _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(sum, estimate), estimate));
        sum = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), estimate), squared));
        value.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(sum, sum, 0), lanes);
        float angle = SafeAcos(value(2));
        int latitude = (int)(angle * 2.0 / 3.1415927410125732421875 * 511.0 + 0.5);
        int columns = latitude * 2;
        int longitude = (int)(Atan2(value(1), value(0)) * 2.0f / 3.1415927410125732421875f * columns + 0.5);
        int direction = longitude + latitude * latitude;
        magnitude = (float)sqrt(1.0f - magnitude);
        *packed |= ((unsigned int)(magnitude * 1023.0 + 0.5) << 18) | direction;
    }
}

namespace fnv_00e526f0 {


extern const __m128 DAT_01017d10;

struct hkQuaternion
{
    union
    {
        __m128 m_vComponents;
        float m_f[4];
    };
};

// @fnv 0x00e526f0
void __cdecl FUN_00e526f0(const hkQuaternion* q, short* out)
{
    static float scale = float(sqrt(2.0)) * 16383.0;
    __m128 a = _mm_and_ps(q->m_vComponents, DAT_01017d10);
    short largest = 0;
    if (a[1] > a[0])
        largest = 1;
    if (a[2] > a[largest])
        largest = 2;
    if (a[3] > a[largest])
        largest = 3;

    int L = largest;
    int i = (L == 0);
    short v[3];
    v[0] = (short)(int)(q->m_f[i] * scale) + 0x3fff;
    i++;
    i += (i == L);
    v[1] = (short)(int)(q->m_f[i] * scale) + 0x3fff;
    i++;
    i += (i == L);
    v[2] = (short)(int)(q->m_f[i] * scale) + 0x3fff;

    out[0] = (short)((largest << 15) | v[0]);
    out[1] = (short)(((largest >> 1) << 15) | v[1]);
    int sign = (q->m_f[L] < 0.0f) ? 1 : 0;
    out[2] = (short)((sign << 15) | v[2]);
}
}

union __declspec(align(16)) PackedQuaternionOutput
{
    __m128 simd;
    float components[4];
};

// @fnv 0x00e52920
void FUN_00e52920(const unsigned char* p, PackedQuaternionOutput* output)
{
    static float scale = (float)(1.0 / ((float)sqrt(2.0) * 63.0));
    struct
    {
        short a, b, c;
    } v;
    v.a = (short)(p[0] & 0x7f);
    v.b = (short)(p[1] & 0x7f);
    v.c = (short)(p[2] & 0x7f);
    unsigned int missing = ((p[1] & 0x80) | (p[0] >> 1)) >> 6;
    output->simd = _mm_setzero_ps();
    unsigned int index = missing == 0;
    output->components[index] = (v.a - 63) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.b - 63) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.c - 63) * scale;
    float remainder = 1.0f - output->components[0] * output->components[0] -
                      output->components[1] * output->components[1] - output->components[2] * output->components[2] -
                      output->components[3] * output->components[3];
    output->components[missing] = sqrtf(remainder);
    if (p[2] & 0x80)
        output->components[missing] = -output->components[missing];
}

namespace fnv_00e52c30 {
union __declspec(align(16)) PackedQuaternionOutput
{
    __m128 simd;
    float components[4];
};
// @fnv 0x00e52c30
void FUN_00e52c30(const unsigned char* p, PackedQuaternionOutput* output)
{
    static float scale = (float)(1.0 / ((float)sqrt(2.0) * 2047.0));
    struct
    {
        short a, b, c;
    } v;
    v.a = (short)(((p[1] & 0x0f) << 8) | p[0]);
    v.b = (short)((p[2] << 4) | ((p[1] & 0xf0) >> 4));
    v.c = (short)(((p[4] & 0x0f) << 8) | p[3]);
    unsigned int missing = (p[4] >> 4) & 3;
    output->simd = _mm_setzero_ps();
    unsigned int index = missing == 0;
    output->components[index] = (v.a - 2047) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.b - 2047) * scale;
    ++index;
    index += index == missing;
    output->components[index] = (v.c - 2047) * scale;
    float remainder = 1.0f - output->components[0] * output->components[0] -
                      output->components[1] * output->components[1] - output->components[2] * output->components[2] -
                      output->components[3] * output->components[3];
    output->components[missing] = sqrtf(remainder);
    if (p[4] & 64)
        output->components[missing] = -output->components[missing];
}
}

// namespace fnv_00e52c30

struct FNV_ALIGN(16) FUN_00dd1bf0
{
    int m[16];
};

// @fnv 0x00e5cfe0
void FUN_00e5cfe0(int a1, int a2, int a3, float a4, int a5)
{
    FUN_00dd1bf0 obj;
    reinterpret_cast<::ObbQueryDetail::ObbMachine *>(&(obj))->FUN_00dd1bf0((const ::ObbQueryDetail::ObbCodeView *)(a1), (const ::ObbQueryDetail::ObbTransform *)(a2), (const ::ObbQueryDetail::ObbVector *)(a3), a4, a5);
}

int __cdecl FUN_00e4b570(const __m128* point, const __m128* verts, float* out);

// VEGAS17-CONFLICT: LocalObj (variant definition below differs from the one above)
// stand-in for the local object whose method is called
struct LocalObj {
    int m_unk00;
    int m_unk01;
    int m_unk02;
    int m_unk03;
    int m_unk04;
    int m_unk05;
    int m_unk06;
    int m_unk07;
    int m_unk08;
    int m_unk09;
    int m_unk10;
    int m_unk11;
    int m_unk12;
    int m_unk13;
    int m_unk14;
    int m_unk15;
    int m_unk16;
    int m_unk17;
    int m_unk18;
    int m_unk19;
};

int __cdecl FUN_00e5cf00(void* a1, int a2, int a3, int a4);

void __cdecl FUN_00e5cf40(int a, int b, int c);

void __cdecl FUN_00e52d90(const unsigned short* in, hkQuatStore_e52d90* out);

void __cdecl FUN_00e52190(const hkQuatStore_e52190* q, unsigned char* out);

class FaceScalar
{
    __m128 value;
public:
    FaceScalar() {}
    FaceScalar(const __m128& input) : value(input) {}
    operator float() const { float result; _mm_store_ss(&result, value); return result; }
    __forceinline const __m128& packed() const { return value; }
};

inline FaceScalar operator*(const FaceScalar& left, const FaceScalar& right)
{ return _mm_mul_ss(left.packed(), right.packed()); }

inline FaceScalar operator-(const FaceScalar& left, const FaceScalar& right)
{ return _mm_sub_ss(left.packed(), right.packed()); }

inline int negativeScalar(const FaceScalar& value)
{ return _mm_movemask_ps(value.packed()) & 1; }

struct FaceBasis;

class FaceVector
{
    __m128 value;
public:
    __forceinline FaceVector() {}
    __forceinline FaceVector(const FaceVector& other) : value(other.value) {}
    __forceinline void operator=(const FaceVector& other) { value = other.value; }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&value)[i]; }
    __forceinline const float& operator()(int i) const { return reinterpret_cast<const float*>(&value)[i]; }
    __forceinline void difference(const FaceVector& left, const FaceVector& right)
    { value = _mm_sub_ps(left.value, right.value); }
    __forceinline void product(const FaceVector& left, const FaceVector& right)
    { value = _mm_mul_ps(left.value, right.value); }
    __forceinline void scale(float amount)
    {
        __m128 scalar = _mm_load_ss(&amount);
        scalar = _mm_shuffle_ps(scalar, scalar, 0);
        value = _mm_mul_ps(scalar, value);
    }
    __forceinline void absolute(const FaceVector& other)
    { value = _mm_and_ps(other.value, DAT_01017d10); }
    __forceinline void cross(const FaceVector& left, const FaceVector& right)
    {
        __m128 cyclic = _mm_mul_ps(_mm_shuffle_ps(left.value,left.value,0xc9),_mm_shuffle_ps(right.value,right.value,0xd2));
        __m128 reverse = _mm_mul_ps(_mm_shuffle_ps(left.value,left.value,0xd2),_mm_shuffle_ps(right.value,right.value,0xc9));
        value = _mm_sub_ps(cyclic, reverse);
    }
    __forceinline FaceScalar dot(const FaceVector& other) const
    {
        __m128 lanes = _mm_mul_ps(value, other.value);
        __m128 pair = _mm_add_ss(_mm_shuffle_ps(lanes,lanes,0x55),lanes);
        return _mm_add_ss(_mm_shuffle_ps(lanes,lanes,0xaa),pair);
    }
    __forceinline FaceScalar squaredLength() const { return dot(*this); }
    __forceinline void inverseRotation(const FaceBasis& basis, const FaceVector& input);
};

struct FaceColumns
{
    FaceVector first, second, third;
    __forceinline FaceVector& column(int i) { return (&first)[i]; }
    __forceinline const FaceVector& column(int i) const { return (&first)[i]; }
};

struct __declspec(align(16)) FaceBasis : FaceColumns {};

__forceinline void FaceVector::inverseRotation(const FaceBasis& basis, const FaceVector& input)
{
    __m128 row0 = basis.column(0).value;
    __m128 row1 = basis.column(1).value;
    __m128 row2 = basis.column(2).value;
    __m128 lo = _mm_unpacklo_ps(row0,row1);
    __m128 hi = _mm_unpackhi_ps(row0,row1);
    row0 = _mm_movelh_ps(lo,row2);
    row1 = _mm_shuffle_ps(_mm_movehl_ps(row0,lo),row2,0xd4);
    row2 = _mm_shuffle_ps(hi,row2,0xe4);
    __m128 x = _mm_shuffle_ps(input.value,input.value,0);
    __m128 xTerm = _mm_mul_ps(row0,x);
    __m128 y = _mm_shuffle_ps(input.value,input.value,0x55);
    __m128 yTerm = _mm_mul_ps(row1,y);
    __m128 z = _mm_shuffle_ps(input.value,input.value,0xaa);
    __m128 zTerm = _mm_mul_ps(row2,z);
    value = _mm_add_ps(_mm_add_ps(xTerm,yTerm),zTerm);
}

template<class T> inline void exchangeValues(T& left, T& right)
{ T old = left; left = right; right = old; }

static __forceinline int edgeFallback(const FaceVector& query, const FaceVector* vertices, FaceVector& distances, float orientation)
{
    int previous = 1;
    int next = 2;
    for (int current = 0; current < 3; previous = next, next = current, ++current)
    {
        if (distances(current) >= 0.0f && distances(previous) >= 0.0f)
        {
            FaceVector firstEdge; firstEdge.difference(vertices[current], vertices[next]);
            FaceVector secondEdge; secondEdge.difference(vertices[previous], vertices[next]);
            FaceVector queryDelta; queryDelta.difference(query, vertices[next]);
            FaceVector apexDelta; apexDelta.difference(vertices[3], vertices[next]);
            FaceScalar queryFirst = queryDelta.dot(firstEdge);
            FaceScalar querySecond = queryDelta.dot(secondEdge);
            FaceScalar apexFirst = apexDelta.dot(firstEdge);
            FaceScalar apexSecond = apexDelta.dot(secondEdge);
            FaceScalar determinant = queryFirst * apexSecond - querySecond * apexFirst;
            if (negativeScalar(determinant)) distances(previous) = -1.0f;
            else distances(current) = -1.0f;
        }
    }
    if (distances(0) > 0.0f) return 0;
    if (distances(1) > 0.0f) return 1;
    if (distances(2) > 0.0f) return 2;
    return -1;
}

// @fnv 0x00e4b810
int __cdecl FUN_00e4b810(const FaceVector& query, const FaceVector* vertices, float orientation)
{
    FaceVector firstEdge; firstEdge.difference(vertices[2], vertices[1]);
    FaceVector secondEdge; secondEdge.difference(vertices[0], vertices[2]);
    FaceVector thirdEdge; thirdEdge.difference(vertices[1], vertices[0]);
    FaceVector apexFirst; apexFirst.difference(vertices[3], vertices[0]);
    FaceVector apexSecond; apexSecond.difference(vertices[3], vertices[1]);
    FaceVector apexThird; apexThird.difference(vertices[3], vertices[2]);
    FaceBasis basis;
    basis.column(0).cross(firstEdge, apexSecond);
    basis.column(1).cross(secondEdge, apexThird);
    basis.column(2).cross(thirdEdge, apexFirst);
    FaceVector delta; delta.difference(query, vertices[3]); delta.scale(orientation);
    FaceVector projected; projected.inverseRotation(basis, delta);
    FaceVector magnitude; magnitude.absolute(projected);
    FaceVector square; square.product(projected, magnitude);
    float distances[3];
    for (int i = 0; i < 3; ++i)
    {
        float norm = basis.column(i).squaredLength();
        if (norm != 0.0f) distances[i] = square(i) / norm;
        else distances[i] = 3.40282e+38f;
    }
    int best = 1;
    if (distances[0] > distances[1]) { exchangeValues(distances[0], distances[1]); best = 0; }
    if (distances[1] > distances[2])
    {
        exchangeValues(distances[1], distances[2]);
        if (distances[0] > distances[1]) exchangeValues(distances[0], distances[1]);
    }
    else best = 2;
    if (distances[2] < ::fnv_00c8e160::DAT_010c6090) return -1;
    if (distances[1] * DAT_010290f8 < distances[2]) return best;
    struct Four { float x,y,z,w; }; Four active = reinterpret_cast<const Four&>(projected);
    return edgeFallback(query, vertices, reinterpret_cast<FaceVector&>(active), orientation);
}

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class hkOstream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
    hkOstream(char* buf, int bufSize);     // FUN_00cb1600
    ~hkOstream();                          // FUN_00cc00e0
    hkOstream& operator<<(const char* s);  // FUN_00cc01c0
    hkOstream& operator<<(const void* p);  // WriteName
};

class hkError
{
  public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int message(int type, int id, const char* description, const char* file, int line);
};

extern const char str_010ecd48[];

struct VectorAttribute
{
    const char* m_name;
    int m_type;
    hkVector4* m_uiFilterValue;
};

struct AttributeHolder
{
    VectorAttribute* FUN_00e5c650(const char* name);
    int FUN_00e5ca80(const char* name, unsigned char warn, hkVector4& out);
};

// @fnv 0x00e5ca80
int AttributeHolder::FUN_00e5ca80(const char* name, unsigned char warn, hkVector4& out)
{
    VectorAttribute* attr = FUN_00e5c650(name);
    if (attr)
    {
        out = *attr->m_uiFilterValue;
        return 0;
    }
    if (warn)
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        reinterpret_cast<::SinkOwner *>((void *)&(const ::hkOstream &)(reinterpret_cast<::AttributeFormatter *>((void *)&(const ::hkOstream &)(reinterpret_cast<::SinkOwner *>((void *)&(const ::hkOstream &)(reinterpret_cast<::SinkOwner *>((void *)&(const ::hkOstream &)(reinterpret_cast<::SinkOwner *>((void *)&(const ::hkOstream &)(ostr))->FUN_00cc01c0(str_010ecd48)))->FUN_00cc01c0(name)))->FUN_00cc01c0(str_010eccfc)))->WriteName((::NameReference *)((const void*)this))))->FUN_00cc01c0(str_010ecd0c);
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabbaab81, assertBuf, str_010eccc8, 0xa2);
    }
    return 1;
}

struct Quaternion81
{
    float x, y, z, w;
};

// @fnv 0x00e52590
void __cdecl FUN_00e52590(const Quaternion81* quaternion, unsigned char* packed)
{
    static float scale = static_cast<float>(sqrt(2.0)) * 2047.0;
    const float* components = &quaternion->x;
    __declspec(align(16)) static const unsigned int absMask[4] = {0x7fffffffu, 0x7fffffffu, 0x7fffffffu, 0x7fffffffu};
    __declspec(align(16)) float abs[4];
    _mm_store_ps(abs,
                 _mm_and_ps(*reinterpret_cast<const __m128*>(quaternion), *reinterpret_cast<const __m128*>(absMask)));
    unsigned int largest = 0;
    if (abs[1] > abs[0])
        largest = 1;
    if (abs[2] > abs[largest])
        largest = 2;
    if (abs[3] > abs[largest])
        largest = 3;
    unsigned int lane = largest == 0;
    short quantized[3];
    quantized[0] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    ++lane;
    lane += lane == largest;
    quantized[1] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    ++lane;
    lane += lane == largest;
    quantized[2] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    packed[0] = static_cast<unsigned char>(quantized[0]);
    packed[1] = static_cast<unsigned char>((quantized[0] >> 8) | (quantized[1] << 4));
    packed[2] = static_cast<unsigned char>(quantized[1] >> 4);
    packed[3] = static_cast<unsigned char>(quantized[2]);
    unsigned int negative = components[largest] < 0.0f;
    packed[4] = static_cast<unsigned char>(((largest | (negative << 2)) << 4) | (quantized[2] >> 8));
}

#include "generated/data/staging/blk_00e40000_od_o2_nood_variant.inc"
