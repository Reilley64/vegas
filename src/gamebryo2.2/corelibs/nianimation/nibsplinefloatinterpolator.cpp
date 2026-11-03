// gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp: NiBSplineFloatInterpolator (12 functions)

#include "fnv/decl/A57E90Controller.h"
#include "fnv/decl/BA58200Sequence.h"
#include "fnv/decl/FUN_00a57f20_cls.h"
#include "fnv/decl/NiKeyBasedInterpolator.h"
#include "fnv/decl/S_00a58160_Foo.h"
#include "fnv/decl/SplData.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109a000.h"
#include "fnv/symbols_011f3000.h"
#include "nibsplinefloatinterpolator_decls.h"
// Calls the base NiBSplineInterpolator::LoadBinary, then reads m_fFloatValue and m_kFloatCPHandle from the stream input.
// @fnv 0x00a50cd0
void NiBSplineFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    stream.input->Read(m_fFloatValue);
    stream.input->Read(m_kFloatCPHandle);
}

// @fnv 0x00a50a20
int FUN_00a50a20(unsigned short v)
{
    unsigned short z = 0;
    return z == v;
}

struct CPX
{
    unsigned char pad[0x20];
    unsigned int handle;
};
// @fnv 0x00a50a60
unsigned int GetHandleByIndex(CPX* self, int, unsigned short idx)
{
    unsigned int r = 0xffff;
    if (idx == 0)
        r = self->handle;
    return r;
}

namespace fnv_00a50a80 {
struct CPX
{
    unsigned char pad[0x20];
    unsigned int handle;
};
// @fnv 0x00a50a80
void SetHandleIfFirstIndex(CPX* self, int, unsigned int h, unsigned short idx)
{
    if (idx == 0)
        self->handle = h;
}
}  // namespace fnv_00a50a80

struct IsEqX
{
};
struct FInterpX
{
    unsigned char pad[0x1c];
    float f1c;
    unsigned int h;
};
// Returns true when FUN_00a57e90 matches other and both f1c and h are equal; otherwise false.
// @fnv 0x00a50b30
bool IsInterpEqual(FInterpX* self, int, FInterpX* other)
{
    if (!reinterpret_cast<::A57E90Controller *>((reinterpret_cast<IsEqX*>(self)))->FUN_00a57e90((::A57E90Object *)(other)))
        return false;
    if (self->f1c != other->f1c)
        return false;
    return other->h == self->h ? true : false;
}

struct GlobalObjX
{
    int x;
};
// @fnv 0x00a50b70
GlobalObjX* FUN_00a50b70()
{
    return &(*reinterpret_cast<::GlobalObjX *>(&::g_011f3ffc));
}

void FUN_00a57f80(void*);
// @fnv 0x00a50b80
void* FUN_00a50b80(void* self, int, unsigned int flags)
{
    FUN_00a57f80(self);
    if (flags & 1)
        ::FUN_00aa1460(self, 0x24);
    return self;
}

struct CloningProcess
{
};
struct FUN_00a57f20_shell
{
};
struct FUN_00a50110_proc;
struct FUN_00a50110_obj
{
public:
    void FUN_00a57fd0(::FUN_00a50110_obj *, ::FUN_00a50110_proc &);
};
struct BSFadeNode
{
    static void* __cdecl operator new(size_t);
};
extern int DAT_010997f4;
struct FUN_00a50c20Cls
{
    char _pad[0x1c];
    float m_fFloatValue;
    unsigned int m_kFloatCPHandle;
    FUN_00a50c20Cls* Clone(CloningProcess&);
};
// Allocates a new object, initialises it, copies the float value and handle from this, and returns the clone.
// @fnv 0x00a50c20
FUN_00a50c20Cls* FUN_00a50c20Cls::Clone(CloningProcess& kCloning)
{
    FUN_00a50c20Cls* pkObject = (FUN_00a50c20Cls*)BSFadeNode::operator new(0x24);
    if (pkObject)
    {
        reinterpret_cast<::FUN_00a57f20_cls *>((((FUN_00a57f20_shell*)pkObject)))->FUN_00a57f20((void *)(0), (void *)(0));
        *(void**)pkObject = (void*)&DAT_010997f4;
        pkObject->m_kFloatCPHandle = 0xffff;
    }
    else
    {
        pkObject = 0;
    }
    ((FUN_00a50110_obj*)this)->FUN_00a57fd0((FUN_00a50110_obj*)pkObject, (::FUN_00a50110_proc &)(kCloning));
    pkObject->m_fFloatValue = m_fFloatValue;
    pkObject->m_kFloatCPHandle = m_kFloatCPHandle;
    return pkObject;
}

struct StrArr
{
    unsigned char pad[8];
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned char pad2[2];
    unsigned short m_usGrowth;

};

struct Base
{
    unsigned char pad[0x1c];

};


struct FUN_00a50d30_shell : Base
{
    float m_fFloatValue;
    unsigned int m_kFloatCPHandle;

    void SerializeToStrings(StrArr* strings);
};

// @fnv 0x00a50d30
void FUN_00a50d30_shell::SerializeToStrings(StrArr* strings)
{
    reinterpret_cast<::BA58200Sequence *>((this))->FUN_00a58200((::BA58200StringArray *)(strings));

    char* value = ::FUN_00a7d330(reinterpret_cast<char const*>((*reinterpret_cast<::GlobalObjX *>(&::g_011f3ffc)).x));

    unsigned int index = strings->m_usElementCount;
    if (index >= strings->m_usSize)
        reinterpret_cast<::ViewerStrings *>((strings))->SetSize(index + strings->m_usGrowth);

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strings))->SetAt(index, value);

    value = FUN_00a7d550("m_fFloatValue", m_fFloatValue);

    index = strings->m_usElementCount;
    if (index >= strings->m_usSize)
        reinterpret_cast<::ViewerStrings *>((strings))->SetSize(index + strings->m_usGrowth);

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strings))->SetAt(index, value);

    value = ::FUN_00a7d510("m_kFloatCPHandle", (unsigned int)(reinterpret_cast<char const*>(m_kFloatCPHandle)));

    index = strings->m_usElementCount;
    if (index >= strings->m_usSize)
        reinterpret_cast<::ViewerStrings *>((strings))->SetSize(index + strings->m_usGrowth);

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strings))->SetAt(index, value);
}

struct NiBSplineEvalTarget
{
};

struct FUN_00a50ba0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    float m08;
    float m0c;
    float m10;
    NiBSplineEvalTarget* m14;
    unsigned int m18;
    float m1c;
    unsigned int m20;
    bool EvaluateAt(float v, unsigned int unused, float* out);
};

// If v differs from m08, computes t from m0c/m10 and evaluates the spline into m1c, then writes m1c to out and caches v in m08.
// @fnv 0x00a50ba0
bool FUN_00a50ba0_cls::EvaluateAt(float afTime, unsigned int unused, float* pfOut)
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
        reinterpret_cast<::SplData *>((m14))->FUN_00a52550(t, &m1c, 1, (::NiBSplineBasisData *)(m18), handle);
    }
    *pfOut = m1c;
    m08 = afTime;
    return true;
}

struct FloatInterpStreamBinaryView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(FloatInterpStreamBinaryView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct FloatInterpStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    FloatInterpStreamBinaryView* m_pUnderlyingStream;
};

struct NiBSplineInterpolatorStand
{
    void* vtable;
    char unk04[0x18];
};

struct FUN_00a50c70_cls : NiBSplineFloatInterpolator
{
    void LoadFloatInterpolator(NiStream& stream);
};

// Loads the base interpolator stream, then reads m_fFloatValue and m_kFloatCPHandle from the stream's binary view.
// @fnv 0x00a50c70
void FUN_00a50c70_cls::LoadFloatInterpolator(NiStream& stream)
{
    reinterpret_cast<::S_00a58160_Foo *>((reinterpret_cast<NiBSplineInterpolatorStand*>(this)))->SaveToStream((::S_00a58160_Stream *)&(stream));
    FloatInterpStreamView* s = reinterpret_cast<FloatInterpStreamView*>(&stream);
    s->m_pUnderlyingStream->Load(&m_fFloatValue);
    s->m_pUnderlyingStream->Load(&m_kFloatCPHandle);
}

#include <windows.h>
struct SpawnedRef
{
    virtual void Vslot00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};


struct FUN_00a57f80_cls
{
    void* m_vptr00;
    unsigned int unk04, unk08, unk0C, unk10;
    SpawnedRef* m_14;
    SpawnedRef* m_18;

    void FUN_00a57f80();
};

// Releases the two SpawnedRef pointers m_14 and m_18 via InterlockedDecrement and DeleteThis, then calls BaseTeardown.
// @fnv 0x00a57f80
void FUN_00a57f80_cls::FUN_00a57f80()
{
    *(void* volatile*)&m_vptr00 = (void*)&DAT_0109ae8c;
    SpawnedRef* second = *(SpawnedRef* volatile*)&m_18;
    if (second != 0)
    {
        if (InterlockedDecrement(&second->m_iObjectReferenceCount) == 0)
        {
            second->DeleteThis();
        }
    }
    SpawnedRef* first = m_14;
    if (first != 0)
    {
        if (InterlockedDecrement(&first->m_iObjectReferenceCount) == 0)
        {
            first->DeleteThis();
        }
    }
    reinterpret_cast<::NiKeyBasedInterpolator *>(this)->FUN_00a57010();
}
