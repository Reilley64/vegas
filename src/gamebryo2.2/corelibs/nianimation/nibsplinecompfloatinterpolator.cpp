// gamebryo2.2/corelibs/nianimation/nibsplinecompfloatinterpolator.cpp: NiBSplineCompFloatInterpolator, FObj (10 functions)

#include "fnv/decl/FUN_00a50c70_cls.h"
#include "fnv/decl/FUN_00a50d30_shell.h"
#include "fnv/decl/FUN_00a57f20_cls.h"
#include "fnv/decl/NiBSplineData.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a50aa0__FUN_00a50aa0_class.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a50000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_011f4000.h"
#include "nibsplinecompfloatinterpolator_decls.h"
// Calls the base NiBSplineFloatInterpolator::LoadBinary and then reads a value from the stream input into a member.
// @fnv 0x00a51660
void NiBSplineCompFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineFloatInterpolator::LoadBinary(stream);
    stream.input->Read(m_afOffsetAndHalfRange);
}


// @fnv 0x00a51520
int* __cdecl FUN_00a51520()
{
    return &(*reinterpret_cast<int *>(&::g_011f401c));
}

struct FUN_00a52d20_shell
{
    int* m_p;
    int __thiscall FUN_00a52d20(int* b, int* c, char* d);
};

// @fnv 0x00a52d20
int __thiscall FUN_00a52d20_shell::FUN_00a52d20(int* b, int* c, char* d)
{
    int* p = *(int**)((char*)this + 0x10);
    if (p)
    {
        *b = *(int*)((char*)p + 8);
        *c = *(int*)((char*)p + 0x10);
        *d = *(char*)((char*)p + 0x14);
        return *(int*)((char*)p + 0xc);
    }
    *b = 0;
    *c = 0;
    *d = 0;
    return 0;
}

struct FUN_00a57f20_shell
{
};
extern int DAT_010997f4;
struct FUN_00a509f0_shell
{
    FUN_00a509f0_shell* __thiscall FUN_00a509f0(int a, int b, int c);
};
// Calls FUN_00a57f20 with a and c, sets the vtable pointer to DAT_010997f4, stores b at offset 0x20, and returns this.
// @fnv 0x00a509f0
FUN_00a509f0_shell* __thiscall FUN_00a509f0_shell::FUN_00a509f0(int aiArg1, int b, int aiArg2)
{
    reinterpret_cast<::FUN_00a57f20_cls *>((((FUN_00a57f20_shell*)this)))->FUN_00a57f20((void *)(aiArg1), (void *)(aiArg2));
    *(int*)this = (int)&DAT_010997f4;
    *(int*)((char*)this + 0x20) = b;
    return this;
}

struct StrArr
{
    void* m_pData;
    int _unk4;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _unkC;
    unsigned short m_usGrowBy;
};
struct BaseX
{
};
struct FUN_00a516e0_shell : BaseX
{
    void __thiscall AppendString(StrArr*);
};
// Calls the base handler, gets a string from g_011f401c, grows pkStrings if full, and stores the string at the next free index.
// @fnv 0x00a516e0
void __thiscall FUN_00a516e0_shell::AppendString(StrArr* pkStrings)
{
    reinterpret_cast<::FUN_00a50d30_shell *>(this)->SerializeToStrings(pkStrings);
    char* pszString = ::FUN_00a7d330((const char*)(*reinterpret_cast<int *>(&::g_011f401c)));
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMaxSize;
    if (uiSize >= uiMax)
    {
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiSize + pkStrings->m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiSize, pszString);
}

struct FUN_00a50b30_shell
{
};
struct FUN_00a514e0_shell
{
    unsigned char _pad[0x24];
    float m_afOffsetAndHalfRange[2];
    bool __thiscall Equals(void* pkObject);
};
// @fnv 0x00a514e0
bool __thiscall FUN_00a514e0_shell::Equals(void* pkObject)
{
    FUN_00a514e0_shell* pkDest;
    unsigned int iIndex;
    if (!::IsInterpEqual((::FInterpX *)(((FUN_00a50b30_shell*)this)), (int)(pkObject), {}))
        return false;
    pkDest = (FUN_00a514e0_shell*)pkObject;
    for (iIndex = 0; iIndex < 2; iIndex++)
    {
        if (m_afOffsetAndHalfRange[iIndex] != pkDest->m_afOffsetAndHalfRange[iIndex])
            return false;
    }
    return true;
}

struct BaseShell
{
};
struct BinaryOutputStream
{
    int _0;
    int m_pos;
    void* _8;
    int(__cdecl* m_write)(void*, void*, unsigned int, unsigned int*, unsigned int);
};
struct FUN_00a516a0_shell
{
    int _pad[9];
    int m_data[2];
    void __thiscall WriteToStream(void* kStream);
};
// @fnv 0x00a516a0
void __thiscall FUN_00a516a0_shell::WriteToStream(void* kStream)
{
    reinterpret_cast<::FUN_00a50c70_cls *>((((BaseShell*)this)))->LoadFloatInterpolator((*(::NiStream *)(kStream)));
    BinaryOutputStream* __restrict pkOstr = *(BinaryOutputStream**)((char*)kStream + 0x250);
    unsigned int size = 4;
    pkOstr->m_pos += pkOstr->m_write(pkOstr, m_data, 8, &size, 1);
}

struct NiBSplineEvalTarget2
{
};

struct FUN_00a51530_cls
{
    unsigned int unk00;
    unsigned int unk04;
    float m08;
    float m0c;
    float m10;
    NiBSplineEvalTarget2* m14;
    unsigned int m18;
    float m1c;
    unsigned int m20;
    float m24;
    float m28;
    bool EvaluateAtTime(float v, unsigned int unused, float* out);
};

// @fnv 0x00a51530
bool FUN_00a51530_cls::EvaluateAtTime(float afTime, unsigned int unused, float* pfOut)
{
    float t;
    if (m08 == afTime)
    {
        *pfOut = m1c;
        return true;
    }
    unsigned int handle = m20;
    if (handle != 0xffff)
    {
        t = (afTime - m0c) / (m10 - m0c);
        reinterpret_cast<::NiBSplineData *>((m14))->CalculateSplineValue(t, &m1c, 1, (::NiBSplineBasisData *)(m18), handle, m24, m28);
    }
    *pfOut = m1c;
    m08 = afTime;
    return true;
}

void* __cdecl FUN_00aa13e0(unsigned int size);
inline void* operator new(unsigned int, void* q)
{
    return q;
}

static const float kMaxCompScalar = 3.402823466e+38F;

struct FBase
{
    virtual void LoadBinary(NiStream&);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    FBase(int a, int b, int c);
};

struct FObj : FBase
{
    float m_afOffsetAndHalfRange[2];
    FObj() : FBase(0, 0xffff, 0)
    {
        float* pfScalars = m_afOffsetAndHalfRange;
        pfScalars[0] = kMaxCompScalar;
        pfScalars[1] = kMaxCompScalar;
    }
    virtual void LoadBinary(NiStream&);
    FObj* __thiscall FUN_00a515c0(int arg);
};

struct FUN_00a50aa0_shell
{
};

// @fnv 0x00a515c0
FObj* __thiscall FObj::FUN_00a515c0(int arg)
{
    FObj* p = (FObj*)FUN_00aa13e0(0x2c);
    if (p)
    {
        new (p) FObj();
    }
    else
    {
        p = 0;
    }

    reinterpret_cast<::fnv_00a50aa0::FUN_00a50aa0_class *>((reinterpret_cast<FUN_00a50aa0_shell*>(this)))->FUN_00a50aa0(p, (void *)(arg));

    p->m_afOffsetAndHalfRange[0] = m_afOffsetAndHalfRange[0];
    p->m_afOffsetAndHalfRange[1] = m_afOffsetAndHalfRange[1];

    return p;
}

class Base51620
{
  public:
    Base51620(int iA, int iB, int iC) throw();
    virtual ~Base51620();
    static void* operator new(unsigned int uiSize);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct ScalarPair51620
{
    float first;
    float second;
    ScalarPair51620() throw() : first(kMaxCompScalar), second(kMaxCompScalar)
    {}
};
class Object51620 : public Base51620
{
  public:
    Object51620() throw() : Base51620(0, 0xffff, 0)
    {}
    ScalarPair51620 scalars;
};

// Allocates and returns a new Object51620 instance with default constructor values.
// @fnv 0x00a51620
Base51620* FUN_00a51620()
{
    return new Object51620;
}
