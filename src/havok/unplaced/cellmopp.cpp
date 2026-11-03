
// src/havok/unplaced/cellmopp.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cellmopp.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c84d00_cls.h"
#include "fnv/decl/FUN_00c84d50_cls.h"
#include "fnv/decl/FUN_00c84df0_cls.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/HeightField.h"
#include "fnv/decl/NiStream.h"
#include "fnv/decl/S_00cb0030_Cls.h"
#include "fnv/decl/ShapeViewerFields.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/bhkBoxShape.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00c84000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005076c0Class.h"
#include "fnv/decl/FUN_0056d360_Class.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_006228e0_shell.h"
#include "fnv/decl/S00cafef0_Obj.h"
#include "fnv/decl/S_00c85c10.h"
struct NiStringArray;
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011f4000.h"
#include <new>
#include "fnv/decl/C68E30Owner.h"
#include "fnv/decl/CCA1B0Level2.h"
#include "fnv/decl/Cl537.h"
#include "fnv/decl/FUN_005610f0_cls.h"
#include "fnv/decl/FUN_0056d2c0_cls.h"
#include "fnv/decl/FUN_0056e6f0.h"
#include "fnv/decl/FUN_00622780_Class.h"
#include "fnv/decl/FUN_00caff80.h"
#include "fnv/decl/S00561150_Object.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkUnaryAction.h"
#include "fnv/decl/fnv_00c5ac00__ArrObj.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_00621000.h"
#include "fnv/symbols_00993000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00cab000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01268000.h"
struct GlobalObject_004aff00
{
};
struct FUN_00621e60
{
    void Clear();
};
struct FUN_00622780
{
};

struct FUN_00621e40Class
{
    void FUN_00621e40();
};

// @fnv 0x00621e40
void FUN_00621e40Class::FUN_00621e40()
{
    reinterpret_cast<::FUN_00622780_Class *>((((FUN_00622780*)this)))->FUN_00622780();
}

struct FUN_00622290_cls
{
    intptr_t FUN_00622290(int a, int b, int c);
};

struct FUN_006222c0_class
{
    void SetPackedValue(unsigned int a, unsigned int c, unsigned int b);
};
// Calls SetPackedValue with the three arguments, then returns this.
// @fnv 0x00622290
intptr_t FUN_00622290_cls::FUN_00622290(int a, int b, int c)
{
    reinterpret_cast<::FUN_006222c0_class *>(this)->SetPackedValue(a, b, c);
    return (intptr_t)this;
}

// @fnv 0x006222c0
void FUN_006222c0_class::SetPackedValue(unsigned int auiLow, unsigned int auiHigh, unsigned int auiMid)
{
    *(unsigned int*)this = (auiHigh << 0x10) | (auiMid << 8) | auiLow;
}

struct FUN_006222f0_Class
{
    void FUN_006222f0(int a);
};
// @fnv 0x006222f0
void FUN_006222f0_Class::FUN_006222f0(int aiValue)
{
    *(int*)((char*)this + 4) = aiValue;
    *(int*)((char*)this + 0x24) = aiValue;
}


struct bhkBvTreeShape
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x006223c0
const char* const* bhkBvTreeShape::GetArg1Ptr()
{
    return &(*reinterpret_cast<const char *const *>(&::g_012682d0));
}


struct FUN_006223d0
{
    void* FUN_00577190();
};

// @fnv 0x006223d0
void* FUN_006223d0::FUN_00577190()
{
    return ::FUN_00577190(this);
}


struct FUN_00622420_Class
{
    void* GetGlobalPtr();
};

// @fnv 0x00622420
void* FUN_00622420_Class::GetGlobalPtr()
{
    return &(*reinterpret_cast<void * *>(&::g_01268350));
}


struct FUN_00622470
{
    bool IsCreated();
};

// @fnv 0x00622470
bool FUN_00622470::IsCreated()
{
    return ((int)(::FUN_009938b0((const unsigned short *)(void *)(reinterpret_cast<char*>(this) + 8)))) != 0;
}

struct Base537
{
};
struct CellMopp_00622490
{
};
struct FUN_00622490 : Base537
{
    FUN_00622490();
};
struct FUN_00622570_Class
{
    unsigned char m_kPointB;
    unsigned char* FUN_00622570(unsigned char b);
};

// @fnv 0x00622570
unsigned char* FUN_00622570_Class::FUN_00622570(unsigned char aucValue)
{
    m_kPointB = aucValue;
    return &m_kPointB;
}

struct CellMopp_00621d90
{
    void* Destroy(unsigned int flags);
};
struct FUN_00622390_Class
{
    void* FUN_00622390();
};
// @fnv 0x00622390
void* FUN_00622390_Class::FUN_00622390()
{
    new ((void *)this) ::FUN_0056e6f0();
    *(void**)this = &DAT_0104dbac;
    ++(*reinterpret_cast<int *>(&::CCA1B0Level2::ms_uiInstances));
    return this;
}

struct FUN_00622440_Class
{
    void* FUN_00622440(unsigned int flags);
};

// @fnv 0x00622440
void* FUN_00622440_Class::FUN_00622440(unsigned int flags)
{
    reinterpret_cast<::FUN_00caff80 *>(this)->FUN_00caff80::~FUN_00caff80();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

struct Param5380d0;
struct This5380d0
{
public:
    bool FUN_005380d0(::Param5380d0 *);
};
struct Flt
{
    operator unsigned int();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct CellMopp_00621ef0
{
};
struct CellMopp_00621e80
{
    void FUN_00621e80();
};

struct FUN_00ca4da0
{
    ~FUN_00ca4da0();
};
struct FUN_006223f0 : FUN_00ca4da0
{
    void* Delete(unsigned int flags);
};
// Runs the base destructor, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006223f0
void* FUN_006223f0::Delete(unsigned int flags)
{
    this->FUN_00ca4da0::~FUN_00ca4da0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

struct CellMopp_006224f0
{
    void* Reset();
};
// @fnv 0x00622490
FUN_00622490::FUN_00622490()
{
    reinterpret_cast<::Cl537 *>(this)->FUN_00537bb0();
    reinterpret_cast<::CellMopp_006224f0 *>((((CellMopp_00622490*)((char*)this + 0x10))))->Reset();
}

extern int DAT_011cc1c8;

struct FUN_00621dc0_sub
{
    ~FUN_00621dc0_sub();
};

struct FUN_00621dc0_base
{
    virtual ~FUN_00621dc0_base();
    unsigned int unk04;
};

struct FUN_00621dc0_cls : FUN_00621dc0_base
{
    FUN_00621dc0_sub m_08;
    virtual ~FUN_00621dc0_cls();
};
// Calls FUN_00621dc0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00621d90
void* CellMopp_00621d90::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00621dc0_cls *>((this))->FUN_00621dc0_cls::~FUN_00621dc0_cls();
    if (flags & 1)
        ::FUN_00aa1460(this, 24);
    return this;
}

// @fnv 0x00621dc0
FUN_00621dc0_cls::~FUN_00621dc0_cls()
{
    --DAT_011cc1c8;
    reinterpret_cast<::FUN_00621e60 *>(this)->Clear();
}


class B622310Base
{
  public:
    int unk04;

    B622310Base();
    virtual ~B622310Base();
};

class FUN_00622310 : public B622310Base
{
  public:

    FUN_00622310(void* pvArg);
    virtual ~FUN_00622310();
};

struct CellMoppBaseView_006815c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m10;
    int m14;
    float m18;
    float m1c;
};
struct CellMoppMemberView_00622570
{
    unsigned char m_kPointB;
};
struct CellMoppCtor_006224f0 : CellMoppBaseView_006815c0
{
    CellMoppMemberView_00622570 m20;
    CellMoppCtor_006224f0* InitializeCellMopp();
};
// Calls InitializeCellMopp, then zeroes the int at offset 0x30 and the float at 0x34, and returns this.
// @fnv 0x006224c0
void* CellMopp_006224f0::Reset()
{
    reinterpret_cast<::CellMoppCtor_006224f0 *>(this)->InitializeCellMopp();
    *(int*)((char*)this + 0x30) = 0;
    *(float*)((char*)this + 0x34) = 0.0f;
    return this;
}
// @fnv 0x006224f0
CellMoppCtor_006224f0* CellMoppCtor_006224f0::InitializeCellMopp()
{
    new ((void *)(((CellMoppBaseView_006815c0*)this))) ::Vec3();
    new ((void *)&(m20)) ::Vec3();
    reinterpret_cast<::bhkUnaryAction *>(this)->Set(1.0f, 1.0f, 1.0f, 0.0f);
    m10 = 2;
    m14 = 2;
    m18 = 0.0f;
    m1c = ::DAT_01012054;
    reinterpret_cast<::FUN_00622570_Class *>(&(m20))->FUN_00622570(0);
    return this;
}

class C621EF0Object
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual uintptr_t GetFormID();
};

class C621EF0Pointer
{
  public:
};

class C621EF0Array
{
  public:
    C621EF0Pointer& GetAt(unsigned int uiIndex);
};


class C621EF0Owner
{
  public:
    int unk00;
    int unk04;
    C621EF0Array m_kThirdFollowingStreamField;

    intptr_t LookupFirstFormID();
};
// @fnv 0x00621e60
void FUN_00621e60::Clear()
{
    reinterpret_cast<::CellMopp_00621e80 *>(this)->FUN_00621e80();
    reinterpret_cast<::fnv_00c5ac00::ArrObj *>((((GlobalObject_004aff00*)((char*)this + 8))))->FUN_004dffa0();
}
// Gets the array from LookupFirstFormID and, if non-null, calls FUN_005380d0 on each non-zero element of the list at this+8.
// @fnv 0x00621e80
void CellMopp_00621e80::FUN_00621e80()
{
    unsigned int* pArray = ((unsigned int *)(reinterpret_cast<::C621EF0Owner *>((((CellMopp_00621ef0*)this)))->LookupFirstFormID()));
    if (pArray)
    {
        for (unsigned int i = 0; i < ((int)(::FUN_009938b0((const unsigned short *)(void *)((char*)this + 8)))); ++i)
        {
            uintptr_t p = *(Flt*)((Arr*)((char*)this + 8))->GetAt(i);
            if (p)
                ((This5380d0*)pArray)->FUN_005380d0((::Param5380d0 *)(p));
        }
    }
}

// @fnv 0x00621ef0
intptr_t C621EF0Owner::LookupFirstFormID()
{
    if (::FUN_009938b0((const unsigned short *)&(m_kThirdFollowingStreamField)) && ((*(::C621EF0Object * *)(&(m_kThirdFollowingStreamField.GetAt(0))))))
        return ((intptr_t)(::FUN_00621480((::HighProcess *)(((*(::C621EF0Object * *)(&(m_kThirdFollowingStreamField.GetAt(0)))))->GetFormID()))));
    else
        return 0;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct B006815c0
{
    B006815c0();
};

struct FUN_00622730_S : public B006815c0
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00622730(float angle);
};

struct FUN_005610f0_Class
{
};

struct FUN_0056d2c0_Class
{
};


class FUN_00622590_Owner : public FUN_00622470
{
  public:
    int unk00;
    int unk04;
    C621EF0Array m_kThirdFollowingStreamField;

    bool PlaceGridObjects(FUN_0056d2c0_Class* p1, const NiPoint3* pPos, int p3);
};

// @fnv 0x00622590
bool FUN_00622590_Owner::PlaceGridObjects(FUN_0056d2c0_Class* p1, const NiPoint3* pPos, int p3)
{
    bool bResultTmp = false;
    if (p1 && IsCreated())
    {
        FUN_00622730_S kRot;
        kRot.FUN_00622730(1.5707964f);
        float offsetY2 = 0.0f;
        int kIdx = 0;
        for (unsigned int aI = 0; aI < 2; aI++)
        {
            float _offsetX = -2048.0f;
            for (unsigned int j8 = 0; j8 < 2; j8++)
            {
                FUN_005610f0_Class* pObj4 = (FUN_005610f0_Class*)((*(::C621EF0Object * *)(&(m_kThirdFollowingStreamField.GetAt(kIdx++)))));
                NiPoint3 kPos = *pPos;
                kPos.x += _offsetX;
                kPos.y += offsetY2;
                reinterpret_cast<::FUN_005610f0_cls *>((pObj4))->FUN_005610f0((intptr_t)(&kPos));
                reinterpret_cast<::S00561150_Object *>((pObj4))->FUN_00561150((const ::S00561150_Source *)(::FUN_00622730_S *)(&kRot));
                _offsetX += 2048.0;
            }
            offsetY2 += 2048.0;
        }
        if (reinterpret_cast<::C621EF0Owner *>(this)->LookupFirstFormID() == 0)
        {
            for (unsigned int k = 0; k < (unsigned int)((int)(::FUN_009938b0((const unsigned short *)(void *)(&m_kThirdFollowingStreamField)))); k++)
            {
                FUN_005610f0_Class* pObj3 = (FUN_005610f0_Class*)((*(::C621EF0Object * *)(&(m_kThirdFollowingStreamField.GetAt(k)))));
                reinterpret_cast<::FUN_0056d2c0_cls *>((p1))->FUN_0056d2c0((::Arg56d2c0 *)(pObj3));
                reinterpret_cast<::C68E30Owner *>((p1))->FUN_00c68e30((::C68E30Holder *)(pObj3), ::PackBytesBigEndian(0xdc, 0x96, 0x28, 0xff));
            }
        }
    }
    return bResultTmp;
}
struct Child;
struct Item
{
    int unk00;
    int unk04;
    Child* child;
};
struct Result
{
    int unk00;
    Item* item;
};
struct This
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual Result* GetResult(char* output);
    void FUN_00ca4e50(intptr_t first, intptr_t second);
};
struct Resolved
{
    int unk00;
    int unk04;
    Child* child;
};
struct Child
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual Resolved* Resolve(intptr_t value);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual bool IsRejected(intptr_t value);
};

// @fnv 0x00ca4e50
void This::FUN_00ca4e50(intptr_t first, intptr_t second)
{
    char output;
    Result* result = GetResult(&output);
    if (result->item)
    {
        Child* child = result->item->child;
        if (child && !child->IsRejected(second))
        {
            Resolved* found = child->Resolve(second);
            result->item = (Item*)(found ? found->child : 0);
        }
    }
    reinterpret_cast<::FUN_00c84df0_cls *>(this)->FUN_00c84df0((::FUN_00c84df0_cls *)(first), (::FUN_00c84df0_cls *)(second));
}

struct S_00ca4ec0_Stream
{
};

struct S_00ca4ec0_Out
{
    int unk00;
    int m_04;
};

struct S_00ca4ec0_Base
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual S_00ca4ec0_Out* vb4(int* out);
};

struct S_00ca4ec0 : S_00ca4ec0_Base
{
    void FUN_00ca4ec0(S_00ca4ec0_Stream& kStream);
};

// @fnv 0x00ca4ec0
void S_00ca4ec0::FUN_00ca4ec0(S_00ca4ec0_Stream& kStream)
{
    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    reinterpret_cast<::FUN_00c84d00_cls *>(this)->FUN_00c84d00((::FUN_00c84d00_obj *)&(kStream));
    int tmp;
    vb4(&tmp)->m_04 = 0;
}

struct NiStream;
struct FirstInterface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void* FUN_00ca4f40_get();
};
struct SecondInterface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void FUN_00ca4f40_stream(NiStream* stream);
};
struct ReturnedObject
{
    int unk00;
    int unk04;
    SecondInterface* unk08;
};
struct HC1Base
{
    int unk00;
    int unk04;
    FirstInterface* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void FUN_00ca4f40(NiStream* stream);
};
// @fnv 0x00ca4f40
void HC1Base::FUN_00ca4f40(NiStream* stream)
{
    if (this)
    {
        FirstInterface* first = unk08;
        if (first)
        {
            void* result = first->FUN_00ca4f40_get();
            if (result)
            {
                ReturnedObject* object = (ReturnedObject*)((char*)result - 0x10);
                if (object)
                {
                    SecondInterface* second = object->unk08;
                    if (second)
                        second->FUN_00ca4f40_stream(stream);
                }
            }
        }
    }
    ::FUN_00aa0ad0();
}

struct Link
{
};
struct Header
{
    int state;
    int flags;
    void* value;
    int type;
    Link link;
};
struct Node
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual Link* get();
};
struct Sink
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
    virtual void set(void*);
};
struct Owner
{
    int state;
    int flags;
    Node* node;
    void FUN_00ca4f80(Sink*);
    void* getValue()
    {
        if (this)
        {
            Node* current = node;
            if (current)
            {
                Link* link = current->get();
                if (link)
                {
                    Header* header = reinterpret_cast<Header*>(reinterpret_cast<char*>(link) - 16);
                    if (header)
                        return header->value;
                }
            }
        }
        return 0;
    }
};
// @fnv 0x00ca4f80
void Owner::FUN_00ca4f80(Sink* sink)
{
    sink->set(getValue());
    reinterpret_cast<::FUN_00c84d50_cls *>(this)->FUN_00c84d50(sink);
}

namespace fnv_00ca5010 {
struct Interface
{
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void* GetObject() = 0;
};
typedef void(* FinishObject)(Interface*);
struct Owner
{
    int unk00;
    int unk04;
    Interface* unk08;
    void FUN_00ca5010();
};
// @fnv 0x00ca5010
void Owner::FUN_00ca5010()
{
    if (this == 0)
        return;
    Interface* input = unk08;
    if (input == 0)
        return;
    void* raw = input->GetObject();
    if (raw == 0)
        return;
    char* base = (char*)raw - 0x10;
    if (base == 0)
        return;
    Interface* object = *(Interface**)(base + 8);
    if (object == 0)
        return;
    FinishObject finish = (FinishObject)(*(void***)object)[54];
    finish(object);
}
}  // namespace fnv_00ca5010

namespace fnv_00cafff0 {
struct Owner
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45(char*);
    void FUN_00cafff0(int first, int second);
};
// @fnv 0x00cafff0
void Owner::FUN_00cafff0(int first, int second)
{
    char local;
    V45(&local);
    reinterpret_cast<::This *>(this)->FUN_00ca4e50(first, second);
}
}  // namespace fnv_00cafff0


struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard()
    {
        previous = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~MemoryContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};

struct FUN_00cb0780_Allocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Free(void* memory, unsigned int size);
};
struct FUN_00cb0780_Manager
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FUN_00cb0780_Allocator* allocator;
};

struct FUN_00cb0780_class
{
    int unk00;
    int unk04;
    int unk08;
    void* memory;
    void FUN_00cb0780(bool release);
};
// @fnv 0x00cb0780
void FUN_00cb0780_class::FUN_00cb0780(bool release)
{
    void* allocation;
    MemoryContextGuard guard;
    if (release)
    {
        allocation = memory;
        if (allocation)
        {
            FUN_00cb0780_Manager* manager = (FUN_00cb0780_Manager*)FUN_00c85750();
            manager->allocator->Free(allocation, 0x30);
        }
        memory = 0;
    }
}

struct ThreadState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};
struct NiStringArray
{
    void* unk00;
    char** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short unk0C;
    unsigned short growth;
};
struct GlobalString
{
    const char* value;
};
struct StringBuilder
{
    void FUN_00cb09b0(NiStringArray* array);
};
struct ThreadStateGuard
{
    int previous;
    ThreadStateGuard() : previous((*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2B4)
    {
        (*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2B4 = 0x10;
    }
    ~ThreadStateGuard()
    {
        (*reinterpret_cast<::ThreadState *>(&::g_tlsBlock)).unk2B4 = previous;
    }
};
struct EP
{
    int u0[0x50];
    int m254;
    int m260;
};

struct QTF
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual intptr_t M45(void* p);
    void FUN_00ca4f00(EP* a1);
};

// @fnv 0x00ca4f00
void QTF::FUN_00ca4f00(EP* a1)
{
    char tmp;
    void* r;
    r = (void*)this->M45(&tmp);
    intptr_t v = ((intptr_t)(reinterpret_cast<::NiStream *>((a1))->GetLoadedObject()));
    if (v != 0)
        ((int*)r)[1] = ((int*)v)[2];
    ::FUN_00c84cc0((int *)(this), (uintptr_t)(a1));
}

struct FUN_00ca4fd0_Value
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void Target(int first, int second);
};

class FUN_00ca4fd0_cls
{
  public:
    int unk00;
    int unk04;
    Node* m_pReferencedNode;

    void FUN_00ca4fd0(int first, int second);
};

// @fnv 0x00ca4fd0
void FUN_00ca4fd0_cls::FUN_00ca4fd0(int first, int second)
{
    Node* pNode;
    Link* m_pTaskletData;
    Header* pHeader;
    void* pValue;

    if (this == 0)
    {
        return;
    }
    pNode = m_pReferencedNode;
    if (pNode == 0)
    {
        return;
    }
    m_pTaskletData = pNode->get();
    if (m_pTaskletData == 0)
    {
        return;
    }
    pHeader = reinterpret_cast<Header*>(reinterpret_cast<char*>(m_pTaskletData) - 16);
    if (pHeader == 0)
    {
        return;
    }
    pValue = pHeader->value;
    if (pValue == 0)
    {
        return;
    }
    ((FUN_00ca4fd0_Value*)pValue)->Target(first, second);
}


struct RefCounted
{
    int unk00;
    long refCount;
};

struct Owner_Ext : public Owner
{
    void FUN_00ca5130(bool flag);
};

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);

struct SpawnedObject
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedObject()
    {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_vtbl = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_01030bf4));
        unk0C = 0;
        unk10 = 0;
        ::DAT_012680f8++;
        m_vtbl = (void*)DAT_0104dbac;
        (*reinterpret_cast<int *>(&::CCA1B0Level2::ms_uiInstances))++;
        m_vtbl = (void*)"@$b";
        DAT_0126834c++;
    }
    void* operator new(std::size_t size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

struct FUN_00cb05d0_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49(SpawnedObject* obj, int a1);
    SpawnedObject* FUN_00cb05d0(int a1);
};

// @fnv 0x00cb05d0
SpawnedObject* FUN_00cb05d0_cls::FUN_00cb05d0(int a1)
{
    ThreadStateGuard guard;
    ::FUN_00c876f0();
    SpawnedObject* p = new SpawnedObject();
    this->v49(p, a1);
    ::FUN_00c87700();
    return p;
}

struct FUN_00cb06c0_Alloc
{
    virtual void slot00();
    virtual void* Alloc(unsigned int size);
};
struct FUN_00cb06c0_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb06c0_Alloc* allocator;
};
struct FUN_00cb06c0_Obj
{
};
struct FUN_00cb06c0_cls
{
    int unk00;
    int unk04;
    void* unk08;
    void* unk0c;
    void* FUN_00cb06c0(bool* out);
};

// @fnv 0x00cb06c0
void* FUN_00cb06c0_cls::FUN_00cb06c0(bool* out)
{
    ThreadStateGuard guard;
    bool empty = (unk0c == 0);
    *out = empty;
    if (empty)
    {
        FUN_00cb06c0_Holder* holder = reinterpret_cast<FUN_00cb06c0_Holder*>(FUN_00c85750());
        void* result = holder->allocator->Alloc(0x50);
        if (result != 0)
        {
            result = ((void *)(new ((void *)(reinterpret_cast<FUN_00cb06c0_Obj*>(result))) ::FUN_00622490()));
        }
        else
        {
            result = 0;
        }
        unk0c = result;
        if (unk08 != 0)
        {
            reinterpret_cast<::S_00cb0030_Cls *>(this)->FUN_00cb0030((::S_00cb0030_Out *)(result));
        }
    }
    return unk0c;
}

struct S00cb0820_Alloc
{
    virtual void slot00();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* memory, unsigned int size);
};
struct S00cb0820_Mem
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    S00cb0820_Alloc* allocator;
    S00cb0820_Alloc& heap()
    {
        return *allocator;
    }
};

struct S00cb0820_Ref
{
    void* m_vtbl;
    unsigned short m_usAllocationSize;
    short m_iObjectReferenceCount;
    void* operator new(std::size_t size)
    {
        S00cb0820_Ref* b = (S00cb0820_Ref*)((S00cb0820_Mem*)FUN_00c85750())->heap().Alloc(size);
        b->m_usAllocationSize = (unsigned short)size;
        return b;
    }
    void operator delete(void* p, std::size_t size);
};

struct S00cb0820_Src
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
    float unk34;
};

struct S00cb0820_Outer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00cb0820_Src src;
};

extern char DAT_010c853c;

struct S00cb0820_Shape : S00cb0820_Ref
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S00cb0820_Shape70 : S00cb0820_Shape
{
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
    float unk68;
    int unk6c;
    S00cb0820_Shape70(S00cb0820_Src* src)
    {
        reinterpret_cast<::HeightField *>(this)->FUN_00d248a0((*(const ::hkSampledHeightFieldShapeCinfo *)(src)), (::HeightFieldType)(2));
        m_vtbl = &DAT_010c853c;
        double d = unk14 - ::g_01012070;
        unk60 = src->unk30;
        unk64 = (int)d;
        unk68 = src->unk34;
    }
};

struct S00cb0820_Obj40 : S00cb0820_Ref
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
    int unk34;
    int unk38;
    int unk3c;
    S00cb0820_Obj40(S00cb0820_Shape70* shape, float value);
};

struct S00cb0820_Tag
{
    char v;
    S00cb0820_Tag() : v(0)
    {}
    S00cb0820_Tag(const S00cb0820_Tag& o) : v(o.v)
    {}
};

struct S00cb0820_Obj30 : S00cb0820_Ref
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
    S00cb0820_Obj30(S00cb0820_Obj40* body, S00cb0820_Tag tag);
};
struct S00cb0820_Outer;


struct S00cb0820_World
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(S00cb0820_Obj30* obj);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(S00cb0820_Outer* a1);
    void FUN_00cb0820(S00cb0820_Outer* a1);
};

// @fnv 0x00cb0820
void S00cb0820_World::FUN_00cb0820(S00cb0820_Outer* a1)
{
    ThreadStateGuard guard;
    S00cb0820_Shape70* shape = new S00cb0820_Shape70(a1 ? &a1->src : 0);
    S00cb0820_Obj40* body = new S00cb0820_Obj40(shape, ::fnv_00c88020::DAT_01016248);
    S00cb0820_Obj30* phantom = new S00cb0820_Obj30(body, S00cb0820_Tag());
    v35(phantom);
    reinterpret_cast<::hkReferencedObjectC905 *>((phantom))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((body))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((shape))->FUN_00c905b0();
    v47(a1);
}struct ValueRefObject
{
    virtual void v00();
    virtual void Destroy();
    LONG m_lRefCount;
};

struct ValueHeader
{
    int unk00;
    int unk04;
    ValueRefObject* value;
};

struct ValueNode
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void* get();
};

struct FUN_00ca5080_cls
{
    int unk00;
    int unk04;
    ValueNode* m_pReferencedNode;

    void FUN_00ca5080();
};
// @fnv 0x00ca5130
void Owner_Ext::FUN_00ca5130(bool flag)
{
    if (flag)
    {
        RefCounted* val = (RefCounted*)getValue();
        if (val)
        {
            InterlockedIncrement(&val->refCount);
        }
    }
    else
    {
        static_cast<::FUN_00ca5080_cls *>(nullptr)->FUN_00ca5080();
    }
    reinterpret_cast<::bhkBoxShape *>(this)->FUN_00c84e50(flag);
}

// @fnv 0x00ca5080
void FUN_00ca5080_cls::FUN_00ca5080()
{
    ThreadStateGuard guard;
    if (this != 0)
    {
        ValueNode* pNode = m_pReferencedNode;
        if (pNode != 0)
        {
            void* m_pTaskletData = pNode->get();
            if (m_pTaskletData != 0)
            {
                ValueHeader* pHeader = (ValueHeader*)((char*)m_pTaskletData - 16);
                if (pHeader != 0)
                {
                    ValueRefObject* pValue = pHeader->value;
                    if (pValue != 0)
                    {
                        if (InterlockedDecrement(&pValue->m_lRefCount) == 0)
                        {
                            pValue->Destroy();
                        }
                    }
                }
            }
        }
    }
}

struct BinaryDataRecord
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int value10;
    unsigned int value14;
    unsigned int value18;
    unsigned int value1C;
    unsigned int value20;
    unsigned int value24;
    unsigned int value28;
    unsigned int value2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int flags40;
};

struct FUN_00cb00a0_Class
{
    virtual void* slot00(void*);
    virtual void* slot01(void*);
    virtual void* slot02(void*);
    virtual void* slot03(void*);
    virtual void* slot04(void*);
    virtual void* slot05(void*);
    virtual void* slot06(void*);
    virtual void* slot07(void*);
    virtual void* slot08(void*);
    virtual void* slot09(void*);
    virtual void* slot10(void*);
    virtual void* slot11(void*);
    virtual void* slot12(void*);
    virtual void* slot13(void*);
    virtual void* slot14(void*);
    virtual void* slot15(void*);
    virtual void* slot16(void*);
    virtual void* slot17(void*);
    virtual void* slot18(void*);
    virtual void* slot19(void*);
    virtual void* slot20(void*);
    virtual void* slot21(void*);
    virtual void* slot22(void*);
    virtual void* slot23(void*);
    virtual void* slot24(void*);
    virtual void* slot25(void*);
    virtual void* slot26(void*);
    virtual void* slot27(void*);
    virtual void* slot28(void*);
    virtual void* slot29(void*);
    virtual void* slot30(void*);
    virtual void* slot31(void*);
    virtual void* slot32(void*);
    virtual void* slot33(void*);
    virtual void* slot34(void*);
    virtual void* slot35(void*);
    virtual void* slot36(void*);
    virtual void* slot37(void*);
    virtual void* slot38(void*);
    virtual void* slot39(void*);
    virtual void* slot40(void*);
    virtual void* slot41(void*);
    virtual void* slot42(void*);
    virtual void* slot43(void*);
    virtual void* slot44(void*);
    virtual BinaryDataRecord* getData(void*);
    void FUN_00cb00a0(char*);
};

// @fnv 0x00cb00a0
void FUN_00cb00a0_Class::FUN_00cb00a0(char* object)
{
    reinterpret_cast<::S_00ca4ec0 *>((this))->FUN_00ca4ec0((*(::S_00ca4ec0_Stream *)(object)));
    if (object[0x1e5] != 1)
    {
        void* out;
        volatile BinaryDataRecord* data = (volatile BinaryDataRecord*)this->getData(&out);
        data->value10 = _byteswap_ulong(data->value10);
        data->value14 = _byteswap_ulong(data->value14);
        data->value18 = _byteswap_ulong(data->value18);
        data->value1C = _byteswap_ulong(data->value1C);
        data->value20 = _byteswap_ulong(data->value20);
        data->value24 = _byteswap_ulong(data->value24);
        data->value28 = _byteswap_ulong(data->value28);
        data->value2C = _byteswap_ulong(data->value2C);
        data->flags40 = 0;
    }
}

struct T
{
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual void slot26() = 0;
    virtual void slot27() = 0;
    virtual void slot28() = 0;
    virtual void slot29() = 0;
    virtual void slot30() = 0;
    virtual void slot31() = 0;
    virtual void slot32() = 0;
    virtual void slot33() = 0;
    virtual void slot34() = 0;
    virtual void slot35() = 0;
    virtual void slot36() = 0;
    virtual void slot37() = 0;
    virtual void slot38() = 0;
    virtual void slot39() = 0;
    virtual void slot40() = 0;
    virtual void slot41() = 0;
    virtual void slot42() = 0;
    virtual void slot43() = 0;
    virtual void slot44() = 0;
    virtual void* Query(char*) = 0;
    void FUN_00cb0120(void*);
};

// @fnv 0x00cb0120
void T::FUN_00cb0120(void* arg)
{
    char local;
    volatile unsigned int* data = (volatile unsigned int*)Query(&local);
    unsigned char* context = (unsigned char*)arg;
    if (context[0x1e4] != 1)
    {
        data[0x4] = _byteswap_ulong(data[0x4]);
        data[0x5] = _byteswap_ulong(data[0x5]);
        data[0x6] = _byteswap_ulong(data[0x6]);
        data[0x7] = _byteswap_ulong(data[0x7]);
        data[0x8] = _byteswap_ulong(data[0x8]);
        data[0x9] = _byteswap_ulong(data[0x9]);
        data[0xa] = _byteswap_ulong(data[0xa]);
        data[0xb] = _byteswap_ulong(data[0xb]);
        data[0x10] = 0;
    }
    reinterpret_cast<::Owner *>(this)->FUN_00ca4f80((::Sink *)(arg));
    if (context[0x1e4] != 1)
    {
        data[0x4] = _byteswap_ulong(data[0x4]);
        data[0x5] = _byteswap_ulong(data[0x5]);
        data[0x6] = _byteswap_ulong(data[0x6]);
        data[0x7] = _byteswap_ulong(data[0x7]);
        data[0x8] = _byteswap_ulong(data[0x8]);
        data[0x9] = _byteswap_ulong(data[0x9]);
        data[0xa] = _byteswap_ulong(data[0xa]);
        data[0xb] = _byteswap_ulong(data[0xb]);
        data[0x10] = 0;
    }
}
struct ValueObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual bool vD0(int a);
};
struct ValueOwner
{
    int state;
    int flags;
    Node* node;
    void* getValue()
    {
        if (this)
        {
            Node* current = node;
            if (current)
            {
                Link* link = current->get();
                if (link)
                {
                    Header* header = reinterpret_cast<Header*>(reinterpret_cast<char*>(link) - 16);
                    if (header)
                        return header->value;
                }
            }
        }
        return 0;
    }
    bool FUN_00ca5040(int a);
};
// @fnv 0x00ca5040
bool ValueOwner::FUN_00ca5040(int a)
{
    ValueObj* pkColl = static_cast<ValueObj*>(getValue());
    bool bResult;
    if (pkColl)
        bResult = pkColl->vD0(a);
    else
        bResult = ((bool)(::FUN_00c84ec0((void *)this)));
    return bResult;
}

struct StringArrayCalls_00ca5190
{
};
struct StringBuilderCalls_00ca5190
{
};

struct ValueObject_00ca5190
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60(NiStringArray* array);
};

struct StringBuilder_ca5190 : public StringBuilder
{
    void FUN_00ca5190(NiStringArray* array);
};
// @fnv 0x00cb09b0
void StringBuilder::FUN_00cb09b0(NiStringArray* array)
{
    ThreadStateGuard guard;
    reinterpret_cast<::StringBuilder_ca5190 *>(this)->FUN_00ca5190(array);
    char* value = FUN_00a7d330((*reinterpret_cast<::GlobalString *>(&::g_01268350)).value);
    unsigned int count = array->count;
    unsigned int capacity = array->capacity;
    if (count >= capacity)
        reinterpret_cast<::ViewerStrings *>((array))->SetSize(count + array->growth);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(count, (*(char * *)(&value)));
}

// @fnv 0x00ca5190
void StringBuilder_ca5190::FUN_00ca5190(NiStringArray* array)
{
    ThreadStateGuard guard;
    reinterpret_cast<::ShapeViewerFields *>((reinterpret_cast<StringBuilderCalls_00ca5190*>(this)))->FUN_00c851c0((::BCA05B0StringArray *)(array));

    char* text = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_012682d0)));
    unsigned int count = array->count;
    if (count >= array->capacity)
    {
        reinterpret_cast<::ViewerStrings *>((reinterpret_cast<StringArrayCalls_00ca5190*>(array)))->SetSize(count + array->growth);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((reinterpret_cast<StringArrayCalls_00ca5190*>(array)))->SetAt(count, (*(char * *)(&text)));

    if (this != 0)
    {
        FirstInterface* m_8 = reinterpret_cast<HC1Base*>(this)->unk08;
        if (m_8 != 0)
        {
            void* link = m_8->FUN_00ca4f40_get();
            if (link != 0)
            {
                Header* header = reinterpret_cast<Header*>(reinterpret_cast<char*>(link) - 16);
                if (header != 0)
                {
                    void* value = header->value;
                    if (value != 0)
                    {
                        reinterpret_cast<ValueObject_00ca5190*>(value)->v60(array);
                    }
                }
            }
        }
    }
}

union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
};
struct xFltSetting
{
};
struct xFilter
{
    xFilter(int, int, int);
    unsigned int m_uiFilterValue;
};
struct __declspec(align(16)) xPhantomCinfo
{
    xPhantomCinfo();
    ~xPhantomCinfo();
    void FUN_0056f0f0(uintptr_t);
    int m_q[0x38];
};
struct xRef
{
};
struct __declspec(align(16)) xShapeCinfo
{
    xShapeCinfo();
    int m_iWordAt00[4];
    xVec4 m_10;
    int m_20;
    int m_24;
    int m_28[6];
    unsigned int m_40;
    float m_44;
    int m_48[2];
};
struct xNiAlloc
{
    static void* operator new(std::size_t);
    static void operator delete(void*, std::size_t);
};
struct xShape : xNiAlloc
{
    xShape(xShapeCinfo*);
    int m_auiShapeKeys[5];
};
struct xThing
{
    int m_iWordAt00;
};
struct xPhantom : xNiAlloc
{
    xPhantom(xPhantomCinfo*);
    int m_auiShapeKeys[7];
};
struct xPtr
{
    xPtr(void*);
    ~xPtr();
    void* m_p;
};
struct xList
{
    int m_q[4];
};
struct xMgr
{
    int m_iWordAt00, m_iWordAt04;
    xList m_8;
    bool FUN_00621f60(xRef** apList, unsigned int auiCount, float afVal);
};
// @fnv 0x00621f60
bool xMgr::FUN_00621f60(xRef** apList, unsigned int auiCount, float afVal)
{
    bool RESULT = false;
    if (!reinterpret_cast<::FUN_00622470 *>(this)->IsCreated())
    {
        if (apList)
        {
            xPhantomCinfo CI;
            reinterpret_cast<::FUN_00507610_Class *>(&(CI))->FUN_00507610(0.0f);
            reinterpret_cast<::FUN_0056d360_Class *>(&(CI))->FUN_0056d360(5);
            reinterpret_cast<::FUN_005076c0Class *>(&(CI))->FUN_005076c0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011cc1d8)))))));
            xFilter FILTER(0x11, 1, 0);
            CI.FUN_0056f0f0(((unsigned int)(::FUN_00559450((int *)&(FILTER)))));
            for (unsigned int I = 0; I < auiCount; I++)
            {
                xRef* REF = apList[I];
                if (REF)
                {
                    xShapeCinfo SC;
                    SC.m_20 = SC.m_24 = 0x11;
                    reinterpret_cast<::bhkUnaryAction *>(&(SC.m_10))->Set(::FUN_004a3e90(128.0f), ::FUN_004a3e90(1.0f), ::FUN_004a3e90(128.0f), 0.0f);
                    SC.m_40 = reinterpret_cast<::FUN_0049ec60 *>((REF))->GetNext();
                    SC.m_44 = afVal;
                    reinterpret_cast<::S00cafef0_Obj *>(&(SC.m_10))->UpdateBoundsFromElements();
                    xPtr SHAPE(new xShape(&SC));
                    reinterpret_cast<::FUN_006222f0_Class *>(&(CI))->FUN_006222f0(((int)(reinterpret_cast<::FUN_00620b80_shell *>((((*(void * *)(&(SHAPE))))))->GetReferenceFlags())));
                    xPhantom* PHANTOM = new xPhantom(&CI);
                    reinterpret_cast<::S_00c85c10 *>((PHANTOM))->FUN_00c85c10((int *)(REF), (int *)(::xThing *)(&(*reinterpret_cast<::xThing *>(&::g_011f4a20))));
                    reinterpret_cast<::FUN_006228e0_shell *>(&(m_8))->FUN_006227b0((uintptr_t)&(const ::xPtr &)(PHANTOM));
                }
            }
        }
        RESULT = true;
    }
    return RESULT;
}



// Calls FUN_00cb0820 with pvArg, then increments g_i622310Count.
// @fnv 0x00622310
FUN_00622310::FUN_00622310(void* pvArg)
{
    reinterpret_cast<::S00cb0820_World *>(this)->FUN_00cb0820((::S00cb0820_Outer *)(pvArg));
    ::DAT_0126834c++;
}

#include "generated/data/havok/unplaced/cellmopp.inc"
