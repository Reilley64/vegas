
// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cdea20_cls.h"
#include "fnv/decl/FUN_00cdea80_cls.h"
#include "fnv/decl/FUN_00cdeaa0_cls.h"
#include "fnv/decl/FUN_00cf3ea0.h"
#include "fnv/decl/FUN_00d4f2a0.h"
#include "fnv/decl/FUN_00d52fc0.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/hkPragdollLimitsData.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_01268000.h"

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
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
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct Block5
{
    int unk00, unk04, unk08, unk0c, unk10;
};

struct Block5b
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    unsigned char unk07;
    int unk08, unk0c, unk10;
};

struct hkRefObj
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

struct CloneDataBase : hkRefObj
{
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    __m128 unk20, unk30, unk40, unk50, unk60, unk70;
};

struct CloneDataA : CloneDataBase
{
    Block5 unk80;
    Block5b unk94;
    Block5 unka8;
};

struct CloneDataB : CloneDataBase
{
    Block5 unk80;
};

struct SourceDataHeader
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
};

struct SourceData : SourceDataHeader
{
    __m128 unk20, unk30, unk40, unk50, unk60, unk70, unk80;
};

struct SourceDataB : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    Block5 unkc0;
};

struct SourceDataA : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc,
        unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8;
    Block5 unkfc;
    Block5b unk110;
    Block5 unk124;
};

struct Instance;

struct Instance : hkRefObj
{
    int unk08;
    SourceData* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    unsigned char unk1c;
};

inline void* hkAlloc(int size)
{
    hkRefObj* p = (hkRefObj*)audio()->heap().AllocateMemoryBlock(size);
    p->m_usMemSizeAndFlags = (unsigned short)size;
    return p;
}

// @fnv 0x00e5aac0
Instance* __cdecl CloneInstanceFromSource(Instance* apSource)
{
    SourceData* data = apSource->unk0c;
    CloneDataBase* clone;
    switch (data->getType())
    {
    case 7: {
        SourceDataA* s = (SourceDataA*)data;
        CloneDataA* pCloneTyped = ((::CloneDataA *)(new ((void *)(((CloneDataA*)hkAlloc(0xc0)))) ::FUN_00d4f2a0()));
        clone = pCloneTyped;
        pCloneTyped->unk20 = s->unk20;
        pCloneTyped->unk30 = s->unk30;
        pCloneTyped->unk40 = s->unk40;
        pCloneTyped->unk50 = s->unk60;
        pCloneTyped->unk60 = s->unk70;
        pCloneTyped->unk70 = s->unk80;
        pCloneTyped->unk80 = s->unkfc;
        pCloneTyped->unka8 = s->unk124;
        pCloneTyped->unk94 = s->unk110;
        hkBool flag(s->unk110.unk06 != 0);
        reinterpret_cast<::hkPragdollLimitsData *>((pCloneTyped))->FUN_00d4f270((*(bool *)&(const ::hkBool &)(flag)));
        break;
    }
    case 2: {
        SourceDataB* s = (SourceDataB*)data;
        CloneDataB* pCloneTyped = ((::CloneDataB *)(new ((void *)(((CloneDataB*)hkAlloc(0xa0)))) ::FUN_00d52fc0()));
        clone = pCloneTyped;
        pCloneTyped->unk20 = s->unk20;
        pCloneTyped->unk30 = s->unk30;
        pCloneTyped->unk40 = s->unk40;
        pCloneTyped->unk50 = s->unk60;
        pCloneTyped->unk60 = s->unk70;
        pCloneTyped->unk70 = s->unk80;
        pCloneTyped->unk80.unk00 = s->unkc0.unk00;
        pCloneTyped->unk80.unk04 = s->unkc0.unk04;
        pCloneTyped->unk80.unk08 = s->unkc0.unk08;
        pCloneTyped->unk80.unk0c = s->unkc0.unk0c;
        pCloneTyped->unk80.unk10 = s->unkc0.unk10;
        break;
    }
    case 18:
    case 19:
        reinterpret_cast<::FUN_00c90510_class *>((apSource))->FUN_00c90510();
        return apSource;
    default:
        return 0;
    }
    Instance* pInstanceMem = (Instance*)hkAlloc(0x38);
    int iPriority = apSource->unk1c;
    void* eb = apSource->unk18;
    void* ea = apSource->unk14;
    Instance* pInstance = ((::Instance *)(new ((void *)(pInstanceMem)) ::FUN_00cf3ea0((::ConstraintEntity *)(ea), (::ConstraintEntity *)(eb), (::ConstraintData *)(clone), (::ConstraintPriority)(iPriority))));
    reinterpret_cast<::hkReferencedObjectC905 *>((clone))->FUN_00c905b0();
    return pInstance;
}

class FnvSink
{
  public:
    virtual void Slot0() throw();
    virtual void Slot1() throw();
    virtual void Slot2() throw();
    virtual void Write(int level, unsigned int hash, const char* msg, const char* file, int line) throw();
};


class MsgWriter
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

class FnvInner
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1C() throw();
    virtual unsigned int GetKind() throw();

    char unk04[0x0c];
    __m128 m_20;
    __m128 m_30;
    char unk40[0x10];
    __m128 m_50;
    char unk60[0x30];
    __m128 m_90;
};

class FnvHolder
{
  public:
    char unk00[0x0c];
    FnvInner* m_0c;
};

// Reads the inner constraint's kind and copies two __m128 vectors into a1/a2, or logs an unsupported-type error and returns 1.
// @fnv 0x00e5ad40
int FUN_00e5ad40(FnvHolder* pHolder, __m128* pOutA, __m128* pOutB)
{
    FnvInner* inner = pHolder->m_0c;

    switch (inner->GetKind())
    {
    case 0:
        *pOutA = inner->m_20;
        *pOutB = inner->m_30;
        return 0;
    case 1:
        *pOutA = inner->m_50;
        *pOutB = inner->m_90;
        return 0;
    case 2:
        *pOutA = inner->m_50;
        *pOutB = inner->m_90;
        return 0;
    case 7:
        *pOutA = inner->m_50;
        *pOutB = inner->m_90;
        return 0;
    }

    MsgWriter writer;
    unsigned int bufStorage[0x80];
    char* buf = (char*)bufStorage;
    new ((void *)&(writer)) ::FUN_00cb1600(buf, 0x200);
    reinterpret_cast<::SinkOwner *>(&(writer))->FUN_00cc01c0("Unsupported type of constraint in prepareSystemForRagdoll()");
    (*reinterpret_cast<::FnvSink * *>(&::DAT_01268360))->Write(1, 0xabbabf3b, buf, ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 0xe2);
    reinterpret_cast<struct ::FUN_00cc00e0 *>(&(writer))->FUN_00cc00e0::~FUN_00cc00e0();
    return 1;
}

namespace fnv_00e5ae60 {
struct S_00e5ae60_Stream
{
    int unk00;
    int unk04;
    int unk08;
    S_00e5ae60_Stream(char* buf, int size) throw();
    ~S_00e5ae60_Stream() throw();
};

struct S_00e5ae60_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int FUN_message(int type, int id, const char* text, const char* file, int line) throw();
};

struct S_00e5ae60_Constraint
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType() throw();
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
    int m_b0;
};

// Reads motor values from the constraint into a, b and d based on its type; for unsupported types logs an error and returns 1.
// @fnv 0x00e5ae60
int __cdecl GetConstraintMotorValues(S_00e5ae60_Constraint* pConstraint, int* piValueA, int* piValueB,
                                     int* piValueD) throw()
{
    switch (pConstraint->GetType())
    {
    case 2:
        *piValueA = pConstraint->m_b0;
        *piValueB = 0;
        *piValueD = 0;
        return 0;
    case 7:
        *piValueA = reinterpret_cast<::FUN_00cdea20_cls *>((pConstraint))->FUN_00cdea20();
        *piValueB = reinterpret_cast<::FUN_00cdea80_cls *>((pConstraint))->FUN_00cdea80();
        *piValueD = ((int)(reinterpret_cast<::FUN_00cdeaa0_cls *>((pConstraint))->FUN_00cdeaa0()));
        return 0;
    default:
        *piValueD = 0;
        *piValueB = 0;
        *piValueA = 0;
        {
            unsigned int buf[128];  // 512-byte text buffer (int array avoids a GS cookie)
            S_00e5ae60_Stream s((char*)buf, 0x200);
            reinterpret_cast<::SinkOwner *>(&(s))->FUN_00cc01c0("This type of constraint does not have motors");
            (*reinterpret_cast<::fnv_00e5ae60::S_00e5ae60_Err * *>(&::DAT_01268360))->FUN_message(1, 0xabbae233, (const char*)buf,
                                      ".\\Constraint\\Bilateral\\hkpConstraintUtils.cpp", 0x104);
        }
        return 1;
    }
}
}  // namespace fnv_00e5ae60
