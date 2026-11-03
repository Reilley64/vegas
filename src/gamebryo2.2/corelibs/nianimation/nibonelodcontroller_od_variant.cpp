
// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00a6d730_shell.h"
#include "fnv/decl/FUN_00c53e40.h"
#include "fnv/decl/NiTimeController.h"
#include "fnv/decl/NiTimeControllerCM.h"
#include "fnv/decl/Q52Obj.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c53000.h"
#include "fnv/symbols_010c1000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01203000.h"
extern int DAT_0109a2a4;
struct FUN_00a543f0_shell
{
    void* m_kPointA;
    void* m_ptr;
    void FUN_00a543f0();
};
struct GlobalObjectO2_00a7b610
{
};
GlobalObjectO2_00a7b610* __cdecl FUN_00a55120();

struct Unknown_00c536a0
{
    bool FUN_00c536a0(int);
};
// @fnv 0x00c536a0
bool Unknown_00c536a0::FUN_00c536a0(int a)
{
    if (::FUN_00a6d0f0((::TCReg *)this, a, *(::NiStream *)nullptr) == 0)
        return false;
    return true;
}

class NiObject;
struct NiStream
{
public:
    ::NiObject *GetLoadedObject();
public:
    static int RegisterObjectLoader(const char *, NiObject *(*)());
};
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct NiBSBoneLODController : NiObject
{
    void* m_34;
    void FUN_00c53ab0(NiStream& s);
};
// @fnv 0x00c53ab0
void NiBSBoneLODController::FUN_00c53ab0(NiStream& s)
{
    ::FUN_00a89af0((int)this);
    void* old = *(void**)((char*)this + 0x34);
    *(void**)((char*)this + 0x34) = (void*)0xffffffff;
    reinterpret_cast<::Q52Obj *>(this)->FUN_00c52960((unsigned int)(old));
}

namespace fnv_00c53cd0 {
struct NiObject;
struct NiStream
{
};
// @fnv 0x00c53cd0
int __cdecl FUN_00c53cd0()
{
    return ::NiStream::RegisterObjectLoader(::g_012031b8_arg0, (NiObject *(*)())(((fnv_00c53cd0::NiObject *(&)())::fnv_00c537f0::FUN_00c537f0)));
}
}  // namespace fnv_00c53cd0

struct FUN_00c53e00_shell
{
    GlobalObjectO2_00a7b610* FUN_00c53e00();
};
// @fnv 0x00c53e00
GlobalObjectO2_00a7b610* FUN_00c53e00_shell::FUN_00c53e00()
{
    return &(*reinterpret_cast<::GlobalObjectO2_00a7b610 *>(&::g_012031b8));
}

class NiControllerManager
{
  public:
    char _pad[0x34];
    int m34;
    int m38;
};
class CloningProcess
{
};
class CloneableObj
{
  public:
    char _pad[0x34];
    int m34;
    int m38;
    void FUN_00c533f0(NiControllerManager*, CloningProcess*);
};
// @fnv 0x00c533f0
void CloneableObj::FUN_00c533f0(NiControllerManager* a, CloningProcess* b)
{
    reinterpret_cast<::NiTimeControllerCM *>(this)->FUN_00a6cfe0((::NiTimeController *)(a), (*(::CloningProcess *)(b)));
    a->m34 = m34;
    a->m38 = m38;
}

void operator delete(void*, size_t);
struct S_00c53e10
{
    void* FUN_00c53e10(unsigned int);
};
// @fnv 0x00c53e10
void* S_00c53e10::FUN_00c53e10(unsigned int flags)
{
    int pad[2];
    reinterpret_cast<::FUN_00c53e40 *>((this))->FUN_00c53e40::~FUN_00c53e40();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x4c);
    return this;
}

struct Inner_00c53ed0
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual int F3();
};
struct S_00c53ed0
{
    char _pad[0x2C];
    Inner_00c53ed0* m_ptr;
    bool FUN_00c53ed0();
};
// @fnv 0x00c53ed0
bool S_00c53ed0::FUN_00c53ed0()
{
    if (m_ptr != 0 && m_ptr->F3() != 0)
        return true;
    return false;
}

struct ObjectWriter
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void WriteObjectWithClass(void*);
};
struct BoneEntryGroup
{
    void** objects;
    int unk04;
    unsigned int count;
};
struct BoneLODControllerSave : NiBSBoneLODController
{
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
    void* m_34field;
    void* m_38field;
    int unk3c;
    BoneEntryGroup** groupArray;
    unsigned short unk44;
    unsigned short groupCount;
    void FUN_00c536d0(NiStream*);
};
// @fnv 0x00c536d0
void BoneLODControllerSave::FUN_00c536d0(NiStream* stream)
{
    BoneEntryGroup* i;
    unsigned int n;
    unsigned int groupTotal;
    void* group;
    unsigned int savedCount;
    unsigned int zero;
    unsigned int object;
    unsigned int innerCount;
    unsigned int j;

    reinterpret_cast<::FUN_00a6d730_shell *>(this)->FUN_00a6d730((*(::Stream_a6d730 *)(stream)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(stream), (int)(&m_34field));
    ::FUN_0044adf0((::MiddleHighProcess *)(stream), (int)(&m_38field));
    savedCount = groupCount;
    ::FUN_0044adf0((::MiddleHighProcess *)(stream), (int)(&savedCount));

    for (n = 0; n < groupCount; ++n)
    {
        i = groupArray[n];
        if (i)
        {
            innerCount = i->count;
            zero = innerCount;
            ::FUN_0044adf0((::MiddleHighProcess *)(stream), (int)(&zero));
            for (groupTotal = 0; groupTotal < (j = i->count); ++groupTotal)
            {
                group = i->objects[groupTotal];
                reinterpret_cast<ObjectWriter*>(stream)->WriteObjectWithClass(group);
            }
        }
        else
        {
            object = 0;
            ::CallAnimCallback((::FUN_00a3da50_Owner *)(stream), (int)(&object));
        }
    }
}

struct RefList
{
    unsigned int* elements;
    unsigned int unk04;
    unsigned int count;
};
struct BinaryStream
{
};
struct ControllerObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    RefList** lists;
    unsigned short unk44;
    unsigned short listCount;
    void FUN_00c53a10(BinaryStream*);
};
// @fnv 0x00c53a10
void ControllerObject::FUN_00c53a10(BinaryStream* stream)
{
    reinterpret_cast<::NiTimeController *>(this)->LinkObject((*(::NiStream *)(stream)));
    for (unsigned int i = 0; i < listCount; ++i)
    {
        RefList* list = lists[i];
        if (list != 0)
        {
            unsigned int value = 0;
            unsigned int size;
            unsigned int j;
            for (; value < (j = list->count); ++value)
            {
                size = ((unsigned int)(reinterpret_cast<::NiStream *>((stream))->GetLoadedObject()));
                if (value >= list->count)
                {
                }
                else
                {
                    list->elements[value] = size;
                }
            }
        }
    }
}

struct S_00c53cf0_Arr
{
    void** unk00;
    int unk04;
    unsigned int unk08;
};
struct S_00c53cf0_Cls
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
    S_00c53cf0_Arr** unk40;
    short unk44;
    unsigned short unk46;
    bool FUN_00c53cf0();
};
// @fnv 0x00c53cf0
bool S_00c53cf0_Cls::FUN_00c53cf0()
{
    for (unsigned int i = 0; i < unk46; i++)
    {
        S_00c53cf0_Arr* a = unk40[i];
        if (a)
        {
            unsigned int idx;
            unsigned int size;
            for (idx = 0; idx < (size = a->unk08); idx++)
            {
                if (a->unk00[idx])
                {
                    return true;
                }
            }
        }
    }
    return false;
}


extern "C" char str_0109a388[];
extern "C" char str_0109a394[];

struct NiTPrimitiveArray_unsigned_int
{
};

struct FUN_00c53c50_Class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;

    void FUN_00c53c50(NiTPrimitiveArray_unsigned_int* array);
};

struct FUN_00c53c50_Padding
{
    unsigned int p00;
    unsigned int p04;
    unsigned int p08;
    unsigned int p0c;
    unsigned int p10;
    unsigned int p14;
    unsigned int p18;
    unsigned int p1c;
    unsigned int p20;
    unsigned int p24;
    unsigned int p28;
    unsigned int p2c;
};

struct FUN_00c53c50_Values
{
    unsigned int value3;
    unsigned int value2;
    unsigned int value1;
    unsigned int value0;
};

// @fnv 0x00c53c50
void FUN_00c53c50_Class::FUN_00c53c50(NiTPrimitiveArray_unsigned_int* array)
{
    FUN_00c53c50_Padding padding;
    FUN_00c53c50_Values values;

    values.value3 = *(unsigned int*)&(*reinterpret_cast<::GlobalObjectO2_00a7b610 *>(&::g_012031b8));
    values.value0 = (unsigned int)::FUN_00a7d330((const char *)(values.value3));
    reinterpret_cast<::S_0060ba10 *>((array))->FUN_0096a610((int)&(values.value0));

    values.value1 = (unsigned int)::FUN_00a7d4d0(str_0109a394, this->unk34);
    reinterpret_cast<::S_0060ba10 *>((array))->FUN_0096a610((int)&(values.value1));

    values.value2 = (unsigned int)::FUN_00a7d510(str_0109a388, this->unk38);
    reinterpret_cast<::S_0060ba10 *>((array))->FUN_0096a610((int)&(values.value2));
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nibonelodcontroller_od_variant.inc"
