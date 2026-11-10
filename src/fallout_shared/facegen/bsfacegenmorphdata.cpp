// fallout_shared/facegen/bsfacegenmorphdata.cpp: BSFaceGenMorphDataHead, DifferentialArray, HolderDb0, BSFaceGenMorphDataHair (26 functions)

#include <cstdint>
#include "generated/data/vtables.h"
#include <cstdlib>
#include "runtime/crt.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_00656fd0_shell.h"
#include "fnv/decl/FUN_00657be0_class.h"
#include "fnv/decl/FUN_0065cc30_class.h"
#include "fnv/decl/FUN_00a673d0_shell.h"
#include "fnv/decl/NiFixedString.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/S00a67410.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00496000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005dd000.h"
#include "fnv/symbols_0065c000.h"
#include "fnv/symbols_00661000.h"
#include "fnv/symbols_00662000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d5000.h"
#include "bsfacegenmorphdata_decls.h"
struct V_006578b0
{
    int pad[3];
    unsigned int* first;
    unsigned int* FUN_006578b0(unsigned int _Pos);
};

// Copies count bytes from first to dest and returns dest advanced by count.
// @fnv 0x00660270
char* __cdecl FUN_00660270(const char* first, const char* last, char* dest)
{
    unsigned int count = last - first;
    char* result = dest + count;
    if (count > 0)
        fnv::crt::memmove_s(dest, count, first, count);
    return result;
}

struct BSFadeNode
{
    int _pad;
    BSFadeNode(char const*);
};

extern char const* const g_011d37c8_arg1;

// @fnv 0x00662760
void __cdecl FUN_00662760()
{
    (*reinterpret_cast<::BSFadeNode * *>(&::fnv_00653460::DAT_011d5b8c)) = new BSFadeNode((char const*)&g_011d37c8_arg1);
}


// Bounds-checks _Pos against the array size, then returns the 0x34-byte DifferentialEntry at first + _Pos * 0x34.
// @fnv 0x00662860
DifferentialEntry* DifferentialArray::FUN_00662860(unsigned int _Pos)
{
    if (_Pos >= ((unsigned int)(::GetEntryCount((int *)this))))
        std::abort();
    do
    {
    } while (0);
    return (DifferentialEntry*)(first + _Pos * 0x34);
}


struct FUN_00662390_shell
{
    int* GetGlobalIntPtr();
};

// @fnv 0x00662390
int* FUN_00662390_shell::GetGlobalIntPtr()
{
    return &(*reinterpret_cast<int *>(&::g_011d5ba8));
}

struct NiRTTI;

struct FUN_006626e0_shell
{
    NiRTTI* GetRTTI();
};

// @fnv 0x006626e0
NiRTTI* FUN_006626e0_shell::GetRTTI()
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_011d5ba0));
}

// @fnv 0x00662840
int GetEntryCount(int* thisPtr)
{
    return (*(thisPtr + 4) - *(thisPtr + 3)) / 0x34;
}

struct EBase
{
    virtual ~EBase();
};

extern int DAT_01065f04;

struct FUN_00661d40_shell : EBase
{
    void SetVTableAndDestroy();
};

// @fnv 0x00661d40
void FUN_00661d40_shell::SetVTableAndDestroy()
{
    *reinterpret_cast<void**>(this) = fnv_vftable_DAT_01065f04;
    ::FUN_00496910((int **)this);
}

struct FUN_00662820_shell
{
    int FUN_00662820();
};
// Builds differential and statistical morph arrays for expressions, modifiers, phonemes and custom morphs from the given tri data.
// @fnv 0x00660ba0
BSFaceGenMorphDataHead::BSFaceGenMorphDataHead(FaceGenTriData* tri)
{
    expressions = 0;
    modifiers = 0;
    phonemes = 0;
    custom = 0;
    if (!tri)
        return;
    // Preserve the original unoptimized stack layout for the shared loop state.
    struct MorphLocals
    {
        BSFaceGenMorph* statisticalMorph;
        unsigned int phoneme;
        unsigned int i;
        StatisticalEntry* entry;
        unsigned int modifier;
        unsigned int j;
        float* values;
        bool ReportDiagnostic, unused1, unused2, found;
        NiPoint3* points;
        unsigned int customIndex;
        unsigned int count;
        BSFaceGenMorph* differentialMorph;
        unsigned int expression;
    } local;
    // Load differential morphs by matching the four sets of names.
    for (local.i = 0; local.i < ((unsigned int)(::GetEntryCount((int *)&(tri->differential)))); local.i++)
    {
        local.found = false;
        for (local.expression = 0; local.expression < 15; local.expression++)
        {
            if (!FUN_00404dc0(::FUN_005dd830(local.expression), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->differential.FUN_00662860(local.i)))))
            {
                if (!expressions)
                {
                    expressions = new BSFaceGenMorph*[15];
                    memset(expressions, 0, 60);
                }
                local.count = ::FUN_0065c700((const ::_Vec12 *)(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)));
                expressions[local.expression] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = expressions[local.expression];
                local.points = (NiPoint3*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.modifier = 0; local.modifier < 17; local.modifier++)
        {
            if (!FUN_00404dc0(((const char *)(::FUN_005dd840(local.modifier))), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->differential.FUN_00662860(local.i)))))
            {
                if (!modifiers)
                {
                    modifiers = new BSFaceGenMorph*[17];
                    memset(modifiers, 0, 68);
                }
                local.count = ::FUN_0065c700((const ::_Vec12 *)(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)));
                modifiers[local.modifier] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = modifiers[local.modifier];
                local.points = (NiPoint3*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.phoneme = 0; local.phoneme < 16; local.phoneme++)
        {
            if (!FUN_00404dc0(((const char *)(::FUN_005dd850(local.phoneme))), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->differential.FUN_00662860(local.i)))))
            {
                if (!phonemes)
                {
                    phonemes = new BSFaceGenMorph*[16];
                    memset(phonemes, 0, 64);
                }
                local.count = ::FUN_0065c700((const ::_Vec12 *)(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)));
                phonemes[local.phoneme] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = phonemes[local.phoneme];
                local.points = (NiPoint3*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.customIndex = 0; local.customIndex < 1; local.customIndex++)
        {
            if (!FUN_00404dc0(::FUN_00661da0(local.customIndex), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->differential.FUN_00662860(local.i)))))
            {
                if (!custom)
                {
                    custom = new BSFaceGenMorph*[1];
                    memset(custom, 0, 4);
                }
                local.count = ::FUN_0065c700((const ::_Vec12 *)(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)));
                custom[local.customIndex] = new BSFaceGenMorphDifferential(local.count);
                local.differentialMorph = custom[local.customIndex];
                local.points = (NiPoint3*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.differentialMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    local.points[local.j] =
                        NiPoint3(((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .x,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .y,
                                 ((FaceGenTriData*)&tri->differential.FUN_00662860(local.i)->vertexData)
                                     ->FUN_0065c720(local.j)
                                     .z);
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
    }
    // Statistical morphs replace differential morphs with the same name.
    for (local.i = 0; local.i < ((unsigned int)(reinterpret_cast<::FUN_0065cc30_class *>(&(tri->statistical))->FUN_0065cc30())); local.i++)
    {
        local.found = false;
        for (local.expression = 0; local.expression < 15; local.expression++)
        {
            if (!FUN_00404dc0(::FUN_005dd830(local.expression), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->statistical.FUN_00662890(local.i)))))
            {
                if (!expressions)
                {
                    expressions = new BSFaceGenMorph*[15];
                    memset(expressions, 0, 60);
                }
                if (expressions[local.expression])
                {
                    ::FUN_005b5e40();
                    delete expressions[local.expression];
                }
                local.entry = tri->statistical.FUN_00662890(local.i);
                local.count = ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>(&(local.entry->matrix))->FUN_00662820()));
                expressions[local.expression] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = expressions[local.expression];
                local.values = (float*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)((float *)(reinterpret_cast<::V_006578b0 *>((void *)&(local.entry->matrix))->FUN_006578b0(local.j)));
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.modifier = 0; local.modifier < 17; local.modifier++)
        {
            if (!FUN_00404dc0(((const char *)(::FUN_005dd840(local.modifier))), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->statistical.FUN_00662890(local.i)))))
            {
                if (!modifiers)
                {
                    modifiers = new BSFaceGenMorph*[17];
                    memset(modifiers, 0, 68);
                }
                if (modifiers[local.modifier])
                {
                    ::FUN_005b5e40();
                    delete modifiers[local.modifier];
                }
                local.entry = tri->statistical.FUN_00662890(local.i);
                local.count = ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>(&(local.entry->matrix))->FUN_00662820()));
                modifiers[local.modifier] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = modifiers[local.modifier];
                local.values = (float*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)((float *)(reinterpret_cast<::V_006578b0 *>((void *)&(local.entry->matrix))->FUN_006578b0(local.j)));
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.phoneme = 0; local.phoneme < 16; local.phoneme++)
        {
            if (!FUN_00404dc0(((const char *)(::FUN_005dd850(local.phoneme))), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->statistical.FUN_00662890(local.i)))))
            {
                if (!phonemes)
                {
                    phonemes = new BSFaceGenMorph*[16];
                    memset(phonemes, 0, 64);
                }
                if (phonemes[local.phoneme])
                {
                    ::FUN_005b5e40();
                    delete phonemes[local.phoneme];
                }
                local.entry = tri->statistical.FUN_00662890(local.i);
                local.count = ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>(&(local.entry->matrix))->FUN_00662820()));
                phonemes[local.phoneme] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = phonemes[local.phoneme];
                local.values = (float*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)((float *)(reinterpret_cast<::V_006578b0 *>((void *)&(local.entry->matrix))->FUN_006578b0(local.j)));
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
        for (local.customIndex = 0; local.customIndex < 1; local.customIndex++)
        {
            if (!FUN_00404dc0(::FUN_00661da0(local.customIndex), ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(tri->statistical.FUN_00662890(local.i)))))
            {
                if (!custom)
                {
                    custom = new BSFaceGenMorph*[1];
                    memset(custom, 0, 4);
                }
                if (custom[local.customIndex])
                {
                    ::FUN_005b5e40();
                    delete custom[local.customIndex];
                }
                local.entry = tri->statistical.FUN_00662890(local.i);
                local.count = ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>(&(local.entry->matrix))->FUN_00662820()));
                custom[local.customIndex] = new BSFaceGenMorphStatistical(local.count, local.entry->columns);
                local.statisticalMorph = custom[local.customIndex];
                local.values = (float*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)local.statisticalMorph)))->FUN_00726070()));
                for (local.j = 0; local.j < local.count; local.j++)
                {
                    ((unsigned int*)local.values)[local.j] = *(unsigned int*)((float *)(reinterpret_cast<::V_006578b0 *>((void *)&(local.entry->matrix))->FUN_006578b0(local.j)));
                }
                local.found = true;
                break;
            }
        }
        if (local.found)
            continue;
    }
}
// Bounds-checks _Pos against the container size and returns a pointer to the element at that position.
// @fnv 0x006578b0
unsigned int* V_006578b0::FUN_006578b0(unsigned int _Pos)
{
    if (_Pos >= (unsigned int)((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((reinterpret_cast<FaceGenMatrix<float>*>(this)))->FUN_00662820())))
        std::abort();
    do
    {
    } while (0);
    return first + _Pos;
}

// @fnv 0x00662820
int FUN_00662820_shell::FUN_00662820()
{
    return (*reinterpret_cast<int*>(this + 0x10) - *reinterpret_cast<int*>(this + 0xc)) >> 2;
}

struct HolderDe0
{
    void FUN_00661de0();
};
struct HolderDb0
{
    void* FUN_00661db0(unsigned int);
};
struct FUN_00662110_Holder
{
    char _pad[12];
    int* m12;
    int FUN_00662110(int);
};
// Returns m12[idx] when m12 is set and idx is in [0,16], otherwise returns 0.
// @fnv 0x00662110
int FUN_00662110_Holder::FUN_00662110(int aiIndex)
{
    return m12 && aiIndex > -1 && aiIndex < 0x11 ? m12[aiIndex] : 0;
}

struct S_00662150
{
    char _00[16];
    int* f10;
    int FUN_00662150(int);
};
// Returns f10[idx] when f10 is set and idx is in [0, 16), otherwise returns 0.
// @fnv 0x00662150
int S_00662150::FUN_00662150(int aiIndex)
{
    return f10 && aiIndex > -1 && aiIndex < 0x10 ? f10[aiIndex] : 0;
}

struct FUN_00662190_This
{
    char _pad[0x14];
    int* fld14;
    int FUN_00662190(int);
};
// Returns fld14[a] when fld14 is non-null and a is in [0,1), otherwise returns 0.
// @fnv 0x00662190
int FUN_00662190_This::FUN_00662190(int aiIndex)
{
    return fld14 && aiIndex > -1 && aiIndex < 1 ? fld14[aiIndex] : 0;
}

struct BSFaceGenMorphDataHair
{
    void FUN_006623d0();
    void* FUN_006623a0(unsigned int);
};
struct Host006626f0
{
    void* FUN_006626f0(unsigned int);
};
extern int DAT_01065fac;
struct FUN_00a7b300_shell
{
public:
    void FUN_00a7b300();
};
struct FUN_00662720_shell
{
    int f0;
    int f4;
    int f8;
    void* f12;
    void FUN_00662720();
};
// Calls FUN_00662720, then deletes this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x006626f0
void* Host006626f0::FUN_006626f0(unsigned int flags)
{
    reinterpret_cast<::FUN_00662720_shell *>((this))->FUN_00662720();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x18);
    return this;
}
// @fnv 0x00662720
void FUN_00662720_shell::FUN_00662720()
{
    *(void**)this = (void*)&DAT_01065fac;
    if (f12)
    {
        void* tmp = f12;
        ::FUN_00401030(tmp);
    }
    ((FUN_00a7b300_shell*)this)->FUN_00a7b300();
}

namespace fnv_006627e0 {
struct S_004b9900
{
};
// Calls FUN_004b9900(1) on DAT_011d5b8c if non-null, then sets DAT_011d5b8c to null.
// @fnv 0x006627e0
void FUN_006627e0()
{
    S_004b9900* p2;
    {
        S_004b9900* p1 = (*reinterpret_cast<::fnv_006627e0::S_004b9900 * *>(&::fnv_00653460::DAT_011d5b8c));
        p2 = p1;
        {
            std::intptr_t v;
            if (p2)
                v = ((std::intptr_t)(reinterpret_cast<::NiFixedString *>((p2))->FUN_004b9900(1)));
            else
                v = 0;
        }
    }
    (*reinterpret_cast<::fnv_006627e0::S_004b9900 * *>(&::fnv_00653460::DAT_011d5b8c)) = 0;
}
}  // namespace fnv_006627e0

extern int DAT_01065f04;
struct PathingInfo
{
    PathingInfo();
};
struct FUN_00661d10_shell : PathingInfo
{
    const void* m_pVtable;
    FUN_00661d10_shell();
};
// @fnv 0x00661d10
FUN_00661d10_shell::FUN_00661d10_shell()
{
    m_pVtable = &DAT_01065f04;
}

struct FUN_006620d0_Class
{
    char _pad[8];
    int* m_aiIndexedValues;
    int FUN_006620d0(int idx);
};
// Returns the element at idx from the array, or 0 if the array is null or idx is out of range (0..14).
// @fnv 0x006620d0
int FUN_006620d0_Class::FUN_006620d0(int aiIndex)
{
    return m_aiIndexedValues == 0 || aiIndex <= -1 || aiIndex >= 0xf ? 0 : m_aiIndexedValues[aiIndex];
}

struct FUN_00662460_iface
{
    virtual void v0();
    virtual void FUN_00662460(int a, int b, float c);
};
struct FUN_00662460_shell
{
    int f0;
    int f1;
    FUN_00662460_iface* p;
    void FUN_00662460(std::intptr_t a, int b, float c);
};
// Forwards a, b and c to the interface's FUN_00662460 when p and a are set and c is not below _gModifierZero.
// @fnv 0x00662460
void FUN_00662460_shell::FUN_00662460(std::intptr_t aiArg1, int aiArg2, float c)
{
    if (!p || !aiArg1 || c < ::_DAT_01012060)
        return;
    p->FUN_00662460(aiArg1, aiArg2, c);
}

struct S_006623d0_Item
{
    virtual ~S_006623d0_Item();
};

struct S_006623d0_Base
{
    int unk04;
    virtual ~S_006623d0_Base();
};

struct FUN_006623d0 : S_006623d0_Base
{
    S_006623d0_Item* unk08;
    ~FUN_006623d0();
};
// @fnv 0x006623a0
void* BSFaceGenMorphDataHair::FUN_006623a0(unsigned int flags)
{
    reinterpret_cast<::FUN_006623d0 *>((this))->FUN_006623d0::~FUN_006623d0();
    if (flags & 1)
        ::FUN_00aa1460(this, 12);
    return this;
}

// @fnv 0x006623d0
FUN_006623d0::~FUN_006623d0()
{
    if (unk08)
        delete unk08;
}

struct MorphItem
{
    virtual ~MorphItem();
};
struct MorphBase
{
    virtual ~MorphBase();
    unsigned int ref;
};
struct FUN_00661de0 : MorphBase
{
    MorphItem** expressions;
    MorphItem** modifiers;
    MorphItem** phonemes;
    MorphItem** custom;
    virtual ~FUN_00661de0();
};
// Calls FUN_00661de0 on this, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00661db0
void* HolderDb0::FUN_00661db0(unsigned int flags)
{
    reinterpret_cast<::FUN_00661de0 *>((reinterpret_cast<HolderDe0*>(this)))->FUN_00661de0::~FUN_00661de0();
    if (flags & 1)
        ::FUN_00aa1460(this, 24);
    return this;
}
// Frees each non-null entry in the expressions, modifiers, phonemes and custom arrays, then deletes the arrays themselves.
// @fnv 0x00661de0
FUN_00661de0::~FUN_00661de0()
{
    if (expressions)
    {
        for (unsigned int expr = 0; expr < 15; ++expr)
            if (expressions[expr])
                delete expressions[expr];
        delete[] expressions;
    }
    if (modifiers)
    {
        for (unsigned int mod = 0; mod < 17; ++mod)
            if (modifiers[mod])
                delete modifiers[mod];
        delete[] modifiers;
    }
    if (phonemes)
    {
        for (unsigned int phon = 0; phon < 16; ++phon)
            if (phonemes[phon])
                delete phonemes[phon];
        delete[] phonemes;
    }
    if (custom)
    {
        for (unsigned int cust = 0; cust < 1; ++cust)
            if (custom[cust])
                delete custom[cust];
        delete[] custom;
    }
}

struct MorphVt
{
    virtual void v0();
    virtual void v1(int a, int b, float c);
};
struct FUN_00662030_cls
{
    void FUN_00662030(int sel, int p2, std::intptr_t p3, int p4, float p5);
};
// Dispatches on sel to one of four lookup functions with p2, then if the result is non-null calls v1(p3, p4, p5) on it.
// @fnv 0x00662030
void FUN_00662030_cls::FUN_00662030(int aiSelector, int aiIndex, std::intptr_t aiArg1, int aiArg2, float p5)
{
    std::intptr_t pMorph = 0;
    switch (aiSelector)
    {
    case 1:
        pMorph = reinterpret_cast<::FUN_006620d0_Class *>(this)->FUN_006620d0(aiIndex);
        break;
    case 2:
        pMorph = reinterpret_cast<::FUN_00662110_Holder *>(this)->FUN_00662110(aiIndex);
        break;
    case 0:
        pMorph = reinterpret_cast<::S_00662150 *>(this)->FUN_00662150(aiIndex);
        break;
    case 3:
        pMorph = reinterpret_cast<::FUN_00662190_This *>(this)->FUN_00662190(aiIndex);
        break;
    }
    if (pMorph != 0)
        ((MorphVt*)pMorph)->v1(aiArg1, aiArg2, p5);
}

struct HairMorphPoints
{
};
class FUN_006621d0 : public BSFaceGenMorphData
{
  public:
    BSFaceGenMorph* m_pkDifferential;
    FUN_006621d0(FaceGenTriData* pkTriData);
    virtual ~FUN_006621d0();
};
// @fnv 0x006621d0
FUN_006621d0::FUN_006621d0(FaceGenTriData* pkTriData)
{
    m_pkDifferential = 0;
    if (!pkTriData)
        return;
    if (!FUN_00404dc0("HairMorph", ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(pkTriData->differential.FUN_00662860(0)))))
    {
        unsigned int uiCountCur =
            ::FUN_0065c700((const ::_Vec12 *)(((FaceGenTriData*)&pkTriData->differential.FUN_00662860(0)->vertexData)));
        m_pkDifferential = new BSFaceGenMorphDifferential(uiCountCur);
        NiPoint3* pkPointsTmp = ((::NiPoint3 *)(reinterpret_cast<::Callees *>((((HairMorphPoints*)m_pkDifferential)))->FUN_00726070()));
        for (unsigned int i = 0; i < uiCountCur; i++)
            pkPointsTmp[i] =
                NiPoint3(((FaceGenTriData*)&pkTriData->differential.FUN_00662860(0)->vertexData)->FUN_0065c720(i).x,
                         ((FaceGenTriData*)&pkTriData->differential.FUN_00662860(0)->vertexData)->FUN_0065c720(i).y,
                         ((FaceGenTriData*)&pkTriData->differential.FUN_00662860(0)->vertexData)->FUN_0065c720(i).z);
    }
}

class NiFixedString;
const NiFixedString& __cdecl FUN_00653460();
class NiExtraData
{
  public:
    NiExtraData(const NiFixedString&);
    virtual ~NiExtraData();
    int refCount;
    int name;
};
struct V3
{
    float x, y, z;
    V3();
};
struct GeometryStream
{
    int first, second, third;
    GeometryStream();
};
struct GeometryData
{
};
class NiGeometry
{
};
struct FUN_006624c0 : NiExtraData
{
    V3* vertices;
    unsigned int count;
    unsigned int originalCount;
    FUN_006624c0(NiGeometry*, V3*, unsigned int);
    virtual ~FUN_006624c0();
};
// Copies the geometry's vertex stream into a new V3 array, appending extra vertices when provided, and stores the counts.
// @fnv 0x006624c0
FUN_006624c0::FUN_006624c0(NiGeometry* geometry, V3* apExtraVertices, unsigned int extraCount)
    : NiExtraData(FUN_00653460())
{
    GeometryStream geometryStream;
    if (geometry && ((::GeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry)))) && reinterpret_cast<::NiGeometryData *>((((::GeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry))))))->IsGeometryDataStreamable(1))
        reinterpret_cast<::S00a67410 *>((((::GeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry))))))->FUN_00a67410((::BSFaceGenMorphData *)(::GeometryStream *)(&geometryStream));
    if (((void *)(::FUN_00559450((int *)&(geometryStream)))))
    {
        originalCount = reinterpret_cast<::FUN_00456650_shell *>((geometry))->FUN_00456650();
        count = originalCount;
        if (apExtraVertices && extraCount)
            count += extraCount;
        vertices = new V3[count];
        unsigned int i = 0;
        V3* dest = vertices;
        for (; i < originalCount; i++)
        {
            V3 vertex;
            reinterpret_cast<::FUN_00656fd0_shell *>(&(geometryStream))->CopyV3(&vertex);
            *dest = vertex;
            dest++;
            reinterpret_cast<::FUN_00657be0_class *>(&(geometryStream))->AddToA();
        }
        if (apExtraVertices && extraCount)
            ::__memcpy(vertices + originalCount, apExtraVertices, extraCount * sizeof(V3));
        reinterpret_cast<::FUN_00a673d0_shell *>((((::GeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry))))))->FUN_00a673d0();
    }
    else
    {
        vertices = 0;
        originalCount = 0;
        count = 0;
    }
}

#include "generated/data/fallout_shared/facegen/bsfacegenmorphdata.inc"
