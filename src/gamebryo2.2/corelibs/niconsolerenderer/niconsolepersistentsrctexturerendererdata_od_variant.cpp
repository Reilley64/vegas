
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <windows.h>
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c35eb0.h"
#include "fnv/decl/NiRefObject.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_010f0000.h"
#include "fnv/symbols_01202000.h"
#include "niconsolepersistentsrctexturerendererdata_decls.h"

class NiObject;
struct NiStream
{
public:
    ::NiObject *GetLoadedObject();
};

struct NiObject
{
};

struct FUN_00c36040_Class
{
    void FUN_00c36040(NiStream* stream);
};

// @fnv 0x00c36040
void FUN_00c36040_Class::FUN_00c36040(NiStream* stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>((((NiObject*)this)))->ReadGroup((::NiStream *)&(*stream));
    reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
}

namespace fnv_00c36070 {
class NiStream;
class NiObject
{
  public:
    virtual void LinkObject(class NiStream&);
};
class NiStream
{
  public:
};
struct GO
{
    GO& operator=(void*);
};
struct Holder : public NiObject
{
    char _pad[8];
    GO m_go;
    void FUN_00c36070(class NiStream&);
};
// @fnv 0x00c36070
void Holder::FUN_00c36070(class NiStream& stream)
{
    int _u1;
    int _u2;
    ::FUN_00a89af0((int)this);
    m_go = ((::fnv_00c36070::NiObject *)(reinterpret_cast<::NiStream *>(&(stream))->GetLoadedObject()));
}
}  // namespace fnv_00c36070

struct FUN_00c36220_class
{
    void* AppendCameraPathEntries(int);
    void* FUN_00c36220(int arg);
};

// @fnv 0x00c36220
void* FUN_00c36220_class::FUN_00c36220(int arg)
{
    return AppendCameraPathEntries(arg);
}

struct S_00c36290
{
    void* FUN_00c36290(unsigned int);
};
// @fnv 0x00c36290
void* S_00c36290::FUN_00c36290(unsigned int flags)
{
    reinterpret_cast<::FUN_00c35eb0 *>((this))->FUN_00c35eb0::~FUN_00c35eb0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}

struct R_00c362c0
{
    virtual void f0();
    virtual void f1();
    volatile long ref;
};
struct S_00c362c0
{
    R_00c362c0* ptr;
    void FUN_00c362c0();
};
// @fnv 0x00c362c0
void S_00c362c0::FUN_00c362c0()
{
    R_00c362c0* p;
    if (ptr)
    {
        p = ptr;
        if (InterlockedDecrement(&p->ref) == 0)
            p->f1();
    }
}


struct FUN_00c36300_Class
{
    void* FUN_00c36300();
};

// @fnv 0x00c36300
void* FUN_00c36300_Class::FUN_00c36300()
{
    return &(*reinterpret_cast<void * *>(&::g_01202810));
}

struct BSMultiBound
{
    void* b[4];
    BSMultiBound();
};
struct FUN_00c35f50_class
{
    void FUN_00c35fe0(BSMultiBound*, int);
    BSMultiBound* FUN_00c35f50(int);
};

// @fnv 0x00c35f50
BSMultiBound* FUN_00c35f50_class::FUN_00c35f50(int a)
{
    BSMultiBound* t = new BSMultiBound;
    FUN_00c35fe0(t, a);
    return t;
}

extern int _data_011c16bc;

struct A51BF0Base
{
};

// @fnv 0x00c361a0
BSMultiBound* FUN_00c361a0()
{
    return new BSMultiBound;
}

// @fnv 0x00c36130
struct S_00c36130
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool FUN_00c36130(S_00c36130*);
};
bool S_00c36130::FUN_00c36130(S_00c36130* arg)
{
    bool result = reinterpret_cast<::A5d470Class *>(this)->IsSameAs((::A5d470Object *)(arg));
    S_00c36130* other = arg;
    {
        int a;
        int b;
        if ((bool)(int)(unk0c == other->unk0c) && ((a = unk08) == (b = other->unk08)))
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    return result;
}

struct FUN_00c360f0_StreamVTable
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(int);
};

struct FUN_00c360f0_shell : fnv_00c36070::NiObject
{
    int unk04;
    int unk08;
    int val;
    void FUN_00c360f0(fnv_00c36070::NiStream&);
};

// @fnv 0x00c360f0
void FUN_00c360f0_shell::FUN_00c360f0(fnv_00c36070::NiStream& s)
{
    ::FUN_00a89af0((int)this);
    int tmp = val;
    reinterpret_cast<FUN_00c360f0_StreamVTable&>(s).f12(tmp);
}
