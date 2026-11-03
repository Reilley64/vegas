
// src/staging/blk_00da0000_o2_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/staging/blk_00da0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00da0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <new>
#include "fnv/decl/BDBA270Array.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/FUNObj.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00d87790.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/S_00db7c70_class.h"
#include "fnv/decl/StackTraceOwner.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/decl/fnv_00da2840__DA2840Object.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00da0000.h"
#include "fnv/symbols_00da1000.h"
#include "fnv/symbols_00da3000.h"
#include "fnv/symbols_00da4000.h"
#include "fnv/symbols_00da6000.h"
#include "fnv/symbols_00db0000.h"
#include "fnv/symbols_00db7000.h"
#include "fnv/symbols_00df6000.h"
#include "fnv/symbols_00df7000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_010cf000.h"
#include "fnv/symbols_010d5000.h"
#include "fnv/symbols_01269000.h"
#include "../../include/layout_support.h"
extern "C" void __cdecl FUN_00cb0a70(void*);
extern int DAT_010d461c;
struct FUN_00da07b0_class
{
    void __thiscall FUN_00cb0a70(void*);
};
extern int DAT_010c6bec;
extern int DAT_010d6014;
struct FUN_00db7ab0_class
{
    void* __thiscall FUN_00db7ab0(void* a, void* b, void* c);
};
void* __cdecl FUN_00da6e10(void* a, void* b, void* c);
void __cdecl FUN_00da0680(char* a, int b);
struct FUN_00da0740_vt
{
    virtual void v0(int);
};
struct FUN_00cb0a70_class
{
    void __thiscall FUN_00cb0a70(int);
};
struct FUN_00db7cf0_class
{
    int __thiscall FUN_00db7cf0(int a, int b);
};
void* __cdecl FUN_00da0610();
char* __cdecl FUN_00da0630(void);
int* __cdecl FUN_00da0660(void);
int* __cdecl FUN_00da0670();
struct FUN_00da0720_Class
{
    virtual void vf00(int value);
};
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00da0730();
int* __cdecl FUN_00da0750();
// FUN_00da08a0 : cdecl, 13 bytes
//   mov ecx, [esp+4]
//   mov eax, [ecx]
//   mov edx, [eax]
//   push 0
//   call edx
//   ret
// Calls slot 0 of the object's vtable with the argument 0.
struct FUN_00da08a0_cls
{
    virtual int v00(int a);
};
int* __cdecl FUN_00da08b0();
void* __cdecl FUN_00da08d0(void);
extern int DAT_010c6bec;
void* __cdecl FUN_00da0910(void);
struct DA0920FinishFlag
{
    int m_bFinishing;
};
class DA0920Half
{
  public:
    short m_uiFilterValue;

    void operator=(float f)
    {
        int t = *reinterpret_cast<int*>(&f);
        m_uiFilterValue = static_cast<short>(t >> 16);
    }
};
class DA0920Base
{
  public:
    short unk004;
    short unk006;
    short unk008;
    short unk00A;
    short unk00C;
    short unk00E;
    short unk010;
    short unk012;
    short unk014;
    short unk016;
    short unk018;
    short unk01A;
    short unk01C;
    short unk01E;
    short unk020;
    short unk022;
    short unk024;
    short unk026;
    short unk028;
    short unk02A;
    short unk02C;
    short unk02E;
    short unk030;
    short unk032;
    short unk034;
    short unk036;
    short unk038;
    short unk03A;
    short unk03C;
    short unk03E;
    short unk040;
    short unk042;
    short unk044;
    short unk046;
    short unk048;
    short unk04A;
    short unk04C;
    short unk04E;
    short unk050;
    short unk052;
    short unk054;
    short unk056;
    short unk058;
    short unk05A;
    short unk05C;
    short unk05E;
    short unk060;
    short unk062;
    short unk064;
    short unk066;
    short unk068;
    short unk06A;
    short unk06C;
    short unk06E;
    short unk070;
    short unk072;
    short unk074;
    short unk076;
    short unk078;
    short unk07A;
    short unk07C;
    short unk07E;
    short unk080;
    short unk082;
    short unk084;
    short unk086;
    short unk088;
    short unk08A;
    short unk08C;
    short unk08E;
    short unk090;
    short unk092;
    short unk094;
    short unk096;
    short unk098;
    short unk09A;
    short unk09C;
    short unk09E;
    short unk0A0;
    short unk0A2;
    short unk0A4;
    short unk0A6;
    short unk0A8;
    short unk0AA;
    short unk0AC;
    short unk0AE;
    short unk0B0;
    short unk0B2;
    short unk0B4;
    short unk0B6;
    short unk0B8;
    short unk0BA;
    short unk0BC;
    short unk0BE;
    short unk0C0;
    short unk0C2;
    short unk0C4;
    short unk0C6;
    short unk0C8;
    short unk0CA;
    short unk0CC;
    short unk0CE;
    short unk0D0;
    short unk0D2;
    short unk0D4;
    short unk0D6;
    short unk0D8;
    short unk0DA;
    short unk0DC;
    short unk0DE;
    short unk0E0;
    short unk0E2;
    short unk0E4;
    short unk0E6;
    short unk0E8;
    short unk0EA;
    short unk0EC;
    short unk0EE;
    short unk0F0;
    short unk0F2;
    short unk0F4;
    short unk0F6;
    short unk0F8;
    short unk0FA;
    short unk0FC;
    short unk0FE;
    short unk100;
    short unk102;
    short unk104;
    short unk106;
    short unk108;
    short unk10A;
    short unk10C;
    short unk10E;
    short unk110;
    short unk112;
    short unk114;
    short unk116;
    short unk118;
    short unk11A;
    short unk11C;
    DA0920Half m_fWeight;

    DA0920Base(DA0920FinishFlag flag)
    {
        if (flag.m_bFinishing)
            m_fWeight = 1.0f;
    }
    virtual void vfunc00();

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
class DA0920Object : public DA0920Base
{
  public:
    DA0920Object(DA0920FinishFlag flag) : DA0920Base(flag)
    {}
    virtual void vfunc00();
};
void* __cdecl FUN_00da0950();
void* __cdecl FUN_00da0970();
void* FUN_00da09a0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00da09c0();
void* __cdecl FUN_00da09e0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00da0a00();
void* __cdecl FUN_00da0a20();
// FUN_00da0a40 : a one-line function - getter
void* FUN_00da0a40();
void* __cdecl FUN_00da0a60();
// FUN_00da0a80 : returns the address of a global data object.
int* __cdecl FUN_00da0a80(void);
int __cdecl FUN_00da0aa0();
struct CpuOpaque;
CpuOpaque* __cdecl FUN_00da0ac0();
int* __cdecl FUN_00da0ae0(void);
struct FUN_00da0af0_Class
{
    virtual void vf00(int value);
};
void* __cdecl FUN_00da0b00();
void* __cdecl FUN_00da0b20();
struct FUN_00db0060_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    void __thiscall FUN_00db0060(int* param_2, int param_3);
};
struct DB7570Pair
{
    unsigned int m_key;
    unsigned int m_uiFilterValue;
};
enum DB7570Result
{
    DB7570_SUCCESS = 0,
    DB7570_FAILURE = 1
};
class DB7570Map
{
  public:
    int unk00;
    DB7570Pair* m_data;
    int m_iElementCount;

    DB7570Result Lookup(unsigned int key, unsigned int& valueOut) const;
};
struct FUN_00db75b0_entry
{
    int unk00;
    int unk04;
};
struct FUN_00db75b0_class
{
    int unk00;
    FUN_00db75b0_entry* unk04;
    int unk08;

    unsigned int __thiscall FUN_00db75b0(int a1, unsigned int* a2);
};
struct FUN_00db78a0_item
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};
class FUN_00db78a0_cls
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0c(void* field, void* item);
    void FUN_00db78a0(FUN_00db78a0_item** a, void** b);
};
struct hkMemoryAllocator;
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
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}
struct MapPair
{
    unsigned int key;
    unsigned int val;
};
struct HashEntryTable
{
    MapPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
    unsigned int GetIteratorKey(int it) const
    {
        return m_kPrimitiveElement[it].key;
    }
    unsigned int getValue(int it) const
    {
        return m_kPrimitiveElement[it].val;
    }

};
struct MapHolder
{
    int unk00, unk04;
    HashEntryTable m_map;

    void CopyMapEntries(const MapHolder& other);
};
// ForwardToInner: forwards a 64-bit value to a member function held at this->m_08.
struct SpawnedInner
{
};
struct SpawnedOuter
{
    int unk00;
    int unk04;
    SpawnedInner* m_08;

    void ForwardToInner(__int64 v);
};
struct CallTarget_00dba270
{
};
struct SearchObject
{
    int FUN_00dba320(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
class DBA340Object
{
  public:
    int FUN_00dba340(void* pvA, void* pvB, void* pvC);
};
struct DBB100Class
{
};
struct DBB100Registry
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual const DBB100Class* getClassByObject(const void* object) const;
};
struct DBB100Writer
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void WriteCString(const char* s);
};
static void FUN_00dbb100(const DBB100Registry* registry, const void* object, DBB100Writer* writer);
void DBB100WriteClassNames(const DBB100Registry* registry, const void** objects, DBB100Writer* writer);
struct hkMemoryAllocator
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C(void* field, void* item);
    virtual void free(void* p, unsigned int nbytes);
};
struct AudioRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* unk10;
};
AudioRouter* __cdecl da06d0_getRouter();
struct Elem
{
    int unk00;
    int unk04;
};
struct Buffer
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    Elem* m_ppData;
    int m_iElementCount;
    int m_pRayCursor;
};
void __cdecl FUN_00da06d0(Buffer* self);
struct SweepBounds
{
    unsigned int minX, minY, minZ, key;
    unsigned int maxX, maxY, maxZ, reserved;
};
struct SweepPair
{
    unsigned int first, second;
};
inline unsigned int separatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxY - b.minY) | (a.maxZ - b.minZ) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}
inline SweepPair* emitPair(const SweepBounds& a, const SweepBounds& b, SweepPair* out, SweepPair* end, int& skipped)
{
    if (out < end)
    {
        out->first = a.key;
        out->second = b.key;
        ++out;
    }
    else
        ++skipped;
    return out;
}
__forceinline SweepPair* collideOne(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                    int& skipped)
{
    const unsigned int maxX = bounds->maxX;

    while (scan->minX < maxX)
    {
        unsigned int d0 = separatedYZ(*bounds, scan[0]);
        unsigned int d1 = separatedYZ(*bounds, scan[1]);
        unsigned int d2 = separatedYZ(*bounds, scan[2]);
        unsigned int d3 = separatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}
int __cdecl SweepCollidePairs(const SweepBounds* bounds, int count, SweepPair* pairs, int capacity, int& skipped);
struct DBA430Listener
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vslot10(int a, int b);
};
struct DBA430Inner
{
};
struct BSAudio
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0c;
    DBA430Listener* m_10;
};
BSAudio* __cdecl FUN_00c85750();
struct DBA430Owner
{
    int m_00;
    int m_04;
    int m_08;
    DBA430Inner m_0C;

    void Reset();
};
union FeaturePair
{
    unsigned short pair;
    struct
    {
        unsigned char first;
        unsigned char second;
        unsigned char detail;
        unsigned char flags;
    };
};
struct FeatureCache
{
    FeaturePair entries[8];
    unsigned char dimension;
    unsigned char count;
    bool result;
};
__forceinline int excludedAxis(int flags)
{
    signed char bits = static_cast<signed char>(flags >> 4);
    return (bits & 1) ? 0 : ((bits & 2) ? 1 : 2);
}
__forceinline void addCell(int& mask, int cell)
{
    int bit = 1 << (cell * 2);
    if (!(mask & (bit * 2)))
        mask += bit;
}
__forceinline void UpdateAxisMask(int& mask, unsigned char value, int axis)
{
    unsigned int bits = value >> 4;
    int x = (~bits) & 1;
    int y = (~(bits >> 1)) & 1;
    int z = (~(bits >> 2)) & 1;
    if (axis != 0)
        addCell(mask, y + 2 * z);
    if (axis != 1)
        addCell(mask, x + 2 * z + 4);
    if (axis != 2)
        addCell(mask, x + 2 * y + 8);
}
__forceinline void addEdge(int& mask, int value)
{
    int axis = value & 15;
    unsigned int bits = value >> 4;
    int x = (~bits) & 1;
    int y = (~(bits >> 1)) & 1;
    int z = (~(bits >> 2)) & 1;
    if (axis == 0)
        addCell(mask, y + 2 * z);
    else if (axis == 1)
        addCell(mask, x + 2 * z + 4);
    else
        addCell(mask, x + 2 * y + 8);
}
void __cdecl FUN_00da0600();
void __cdecl FUN_00da0620(void);
void FUN_00da0640();
void FUN_00da0650();
void __cdecl FUN_00da0960();
void __cdecl FUN_00da0980();
void __cdecl FUN_00da0990();
void __cdecl FUN_00da09b0();
void __cdecl FUN_00da09d0();
void __cdecl FUN_00da09f0();
void FUN_00da0a10();
void __cdecl FUN_00da0a30();
void __cdecl FUN_00da0a50();
void __cdecl FUN_00da0a70();
void __cdecl FUN_00da0a90();
void __cdecl FUN_00da0ab0();
void __cdecl FUN_00da0ad0();
struct CallbackHolder
{
    int unk00;
    int unk04;
    int unk08;
    void(__stdcall* callback)(void* argument);
};
extern void*(__stdcall* DAT_00fdf110)();
struct FUN_00da2b30_Class
{
    int unk00;
    int unk04;
    CallbackHolder* holder;

    void InvokeCallback();
};
extern int DAT_010d4de4;
extern int DAT_01269a9c;
struct FUN_00da2840_Obj
{
};
struct FUN_00da2b90_Obj
{
    int unk00;
    short unk04;
    short unk06;
    int* unk08;

    unsigned int* __thiscall Initialize();
};
struct DA2D70Listener
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* object, int value);
};
struct DA2D70Audio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DA2D70Listener* m_10;
};
struct DA2D70Object
{
    int unk00;
    unsigned short unk04;

    void* __thiscall NotifyAudioListener(int flags);
};
extern BSAudio* __cdecl FUN_00c85750();
void __cdecl FUN_00da2da0();
void __cdecl FUN_00da44d0(int a, int b, void* pvCallback);
void* __cdecl FUN_00da6e10(void* a, void* b, void* c);
struct Allocator
{
    virtual void Reserved();
    virtual void* Alloc(unsigned int bytes);
};
struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* heap;
};
struct SubObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct CreatedObject
{
    void* vtable;
    unsigned short allocatedSize;
    unsigned short enabled;
    const char* typeName;
    SubObject base;

    void Init()
    {
        union Flag
        {
            unsigned char byte;
            unsigned int word;
        } flag;

        allocatedSize = 0x20;
        enabled = 1;
        flag.byte = 0;
        unsigned int arg = flag.word;

        vtable = &DAT_010cf7d4;
        typeName = str_010cf830;
        new ((void *)&(base)) ::FUN_00d87790(arg);
        vtable = &DAT_010cf804;
    }
};
void* __cdecl FUN_00db79c0();
struct FUN_00db7c00_obj
{
    virtual void vslot00(int value);
};
// 0x00db7c10  /MT /O2 /GS /EHsc /Gy   target: B8 28 9B 26 01 C3  (mov eax, offset DAT_01269b28; ret)
int* FUN_00db7c10();
extern int DAT_010cce28;
struct hkLoadedObjectDB7C
{
    int* m_ppVirtualMethodTable;
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
    FUN_00cb0a70_class m_name;
};
extern "C" void __cdecl FUN_00ec658f(const void*);
extern unsigned char DAT_01269b80;
extern void* DAT_010d6260;
extern void* DAT_01269b78;
extern void* FUN_00fde2a0;
extern unsigned short DAT_01269b7e;
void* __cdecl FUN_00dba610();
typedef void(__cdecl* FuncDA34)();
void __cdecl FUN_00df6b50();
void __cdecl FUN_00df7340();
struct FuncTableDA34
{
    FuncDA34 m_func0;
    FuncDA34 m_func1;
    FuncDA34 m_func2;
    FuncDA34 m_func3;
    FuncDA34 m_func4;
    FuncDA34 m_func5;
    FuncDA34 m_func6;
};
extern FuncTableDA34 DAT_01269af0;
struct RegisterInfoDA34
{
    FuncTableDA34* m_table;
    int m_numFuncs;
    FuncDA34 m_funcA;
    FuncDA34 m_funcB;
};
class DispatcherDA34
{
  public:
};
void FUN_00da82d0();
inline unsigned int mySeparatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxZ - b.minZ) | (a.maxY - b.minY) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}
template <bool swapPairs>
__forceinline SweepPair* collideOneT(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                     int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0 = mySeparatedYZ(*bounds, scan[0]);
        unsigned int d1 = mySeparatedYZ(*bounds, scan[1]);
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (swapPairs)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}
template <>
__forceinline SweepPair* collideOneT<false>(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out,
                                            SweepPair* end, int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0;
        unsigned int d1 = (d0 = mySeparatedYZ(*bounds, scan[0]), mySeparatedYZ(*bounds, scan[1]));
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (false)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}
static float FUN_00db09f0(unsigned short arg);
unsigned short volatile g_in_db09f0;
float volatile g_out_db09f0;
void drive_db09f0(void);
extern "C" unsigned int stub_val(void);
static int* FUN_00db0db0(unsigned int a);
int stub_caller(void);
struct FUN_00db7c80_class
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int* FUN_00db7c80();
};

class hkMemoryAllocatorDA24
{
  public:
    virtual ~hkMemoryAllocatorDA24() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDA24
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorDA24* m_pStreamAllocator;
    hkMemoryAllocatorDA24& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDA24 {
extern "C" hkMemoryRouterDA24& __cdecl FUN_00c85750() throw();
}

namespace hkArrayUtilDA24 {
template <class T> __forceinline void destruct(T* t, int numElements)
{
    for (int i = 0; i < numElements; i++)
        t[i].~T();
}
}

template <class T> class hkArrayDA24
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocatorDA24& alloc)
    {
        hkArrayUtilDA24::destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }

    ~hkArrayDA24() throw()
    {
        _clearAndDeallocate(hkRouterDA24::FUN_00c85750().heap());
    }

    hkArrayDA24() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
};

struct hkBoolDA24
{
    char m_cBooleanValue;
    hkBoolDA24(bool b) throw() : m_cBooleanValue((char)b)
    {}
};


// @fnv 0x00da24b0
void __cdecl FUN_00da24b0(int iParam, float fParam)
{
    hkArrayDA24<int> kFirst;
    hkArrayDA24<int> kSecond;
    ::FUN_00da12b0((::ScriptProgram *)(iParam), fParam, (*(bool *)&(const ::hkBoolDA24 &)(false)), (::MeshArray<int> *)&(kFirst), (::MeshArray<int> *)&(kSecond));
}
