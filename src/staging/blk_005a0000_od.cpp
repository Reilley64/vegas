
// src/staging/blk_005a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cstring>
#include "fnv/decl/ActList.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_005a7d40.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_00680a70_shell.h"
#include "fnv/decl/FUN_006a1b60_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/PerkEntryConditionSet.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00456a60__S_456a60.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_005a8d20__FUN_005a8d20_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01268000.h"
#include "../../include/layout_support.h"

struct FUN_005a3740_cls
{
    unsigned char GetByteAt14C();
};

// @fnv 0x005a3740
unsigned char FUN_005a3740_cls::GetByteAt14C()
{
    return *(unsigned char*)((char*)this + 0x14c);
}

struct FUN_005a3790Class
{
    bool FUN_005a3790();
};

// Sets result to 0.0, then to 1.0 if the reference's FUN_005a3790 check succeeds, and returns true.
// @fnv 0x005a3760
bool __cdecl FUN_005a3760(void* reference, void* b, void* c, double& result)
{
    result = 0.0;
    if (((FUN_005a3790Class*)reference)->FUN_005a3790())
        result = 1.0;
    return true;
}

struct FUN_005a7840_Class
{
    void ClearFlag(unsigned char bFlag);
};

// Clears the bit(s) of bFlag in the byte at offset 0x24 of this object.
// @fnv 0x005a7840
void FUN_005a7840_Class::ClearFlag(unsigned char bFlag)
{
    *(unsigned char*)((char*)this + 0x24) &= ~bFlag;
}

struct FUN_005a8040_class
{
    void SetField54(int param_2);
};

// @fnv 0x005a8040
void FUN_005a8040_class::SetField54(int aiValue)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x54) = aiValue;
}

struct FUN_005a8080
{
    void* GetField();
};

// @fnv 0x005a8080
void* FUN_005a8080::GetField()
{
    return (void*)((char*)this + 0x3c);
}


// @fnv 0x005b4940
void FUN_005b4940()
{
    DAT_0118c684 = 0xff;
    DAT_011cac64 = 0;
}


struct FUN_00456a60_class
{
};

// @fnv 0x005b9220
bool FUN_005b9220()
{
    reinterpret_cast<::fnv_00456a60::S_456a60 *>((((FUN_00456a60_class*)g_TES)))->FUN_00456a60();
    return true;
}

struct FUN_00456a60_Class
{
};
// Sets DAT_012680fc to 1, calls FUN_00456a60 on g_TES, resets DAT_012680fc to 0 and returns 1.
// @fnv 0x005b9240
char __cdecl FUN_005b9240()
{
    (*reinterpret_cast<char *>(&::g_bC11F0Debug)) = 1;
    reinterpret_cast<::fnv_00456a60::S_456a60 *>((((FUN_00456a60_Class*)(int)g_TES)))->FUN_00456a60();
    (*reinterpret_cast<char *>(&::g_bC11F0Debug)) = 0;
    return 1;
}

struct FUN_005b92e0_class
{
    int GetField59C();
};

// @fnv 0x005b92e0
int FUN_005b92e0_class::GetField59C()
{
    return *(int*)((char*)this + 0x59c);
}

struct FUN_005a7220_class
{
};
struct FUN_005a71d0_class
{
    void* FUN_005a71d0();
};
struct FUN_005a7220_cls
{
    int Initialize();
};
// Calls Initialize on the sub-objects at offsets 4 and 0x2c, then sets the fields at 0, 0x50 and 0x54 and returns this.
// @fnv 0x005a71d0
void* FUN_005a71d0_class::FUN_005a71d0()
{
    reinterpret_cast<::FUN_005a7220_cls *>((((FUN_005a7220_class*)((char*)this + 4))))->Initialize();
    reinterpret_cast<::FUN_005a7220_cls *>((((FUN_005a7220_class*)((char*)this + 0x2c))))->Initialize();
    *(int*)this = 0;
    *(int*)((char*)this + 0x50) = 4;
    *(int*)((char*)this + 0x54) = 3;
    return this;
}
// @fnv 0x005a7220
int FUN_005a7220_cls::Initialize()
{
    *(int*)this = 0;
    *(int*)(this + 4) = 0;
    *(int*)(this + 8) = 0;
    *(int*)(this + 12) = 0;
    *(float*)(this + 16) = 0.0f;
    *(int*)(this + 20) = 6;
    *(float*)(this + 24) = 255.0f;
    *(float*)(this + 28) = 255.0f;
    *(float*)(this + 32) = 255.0f;
    *(int*)(this + 36) = 1;
    return (int)this;
}

struct Flt
{
    operator unsigned int();
};

struct BSSimpleListBase
{
};

struct FUN_005a7c00_class : public BSSimpleListBase
{
    char FUN_005a7c00(BSSimpleListBase* other);
};

// Compares this list node's value and next pointer against another's, returning 1 if either differs, else 0.
// @fnv 0x005a7c00
char FUN_005a7c00_class::FUN_005a7c00(BSSimpleListBase* other)
{
    if (reinterpret_cast<Flt*>(this)->operator unsigned int() != reinterpret_cast<Flt*>(other)->operator unsigned int())
        return 1;
    if (((::BSSimpleListBase *)(reinterpret_cast<::Callees *>((this))->FUN_00726070())) != ((::BSSimpleListBase *)(reinterpret_cast<::Callees *>((other))->FUN_00726070())))
        return 1;
    return 0;
}

struct FUN_005a8e20_cls
{
    char FUN_005a8ef0(int param_2, int param_3);
};
// @fnv 0x005a8ef0
char FUN_005a8e20_cls::FUN_005a8ef0(int param_2, int param_3)
{
    int result = ((int)(reinterpret_cast<::ActList *>(this)->FUN_005a90b0((::TESForm *)(void *)((void*)param_2), false)));
    if (!result)
        reinterpret_cast<::fnv_005a8d20::FUN_005a8d20_shell *>(this)->AttachScriptLocals((::ScriptLocals *)(void *)((void*)param_2));
    else if (*(int*)((char*)result + 4) & param_3)
        return 1;
    return 0;
}


// @fnv 0x005b4a70
void FUN_005b4a70()
{
    DAT_0118c684 = ConsumeByteAtE4();
}

// @fnv 0x005b9200
void FUN_005b9200(unsigned char value)
{
    (*reinterpret_cast<unsigned char *>(&::g_bLimbConditionEffectInitialized)) = value;
}

namespace fnv_005bac20 {
struct Flt
{
    operator unsigned int();
};
struct NiNode
{
};
// Returns false if g_011c786c is null, otherwise returns whether its FUN_00453470 result is greater than zero.
// @fnv 0x005bac20
bool __cdecl FUN_005bac20()
{
    if ((unsigned int)(*reinterpret_cast<::fnv_005bac20::Flt *>(&::g_011c786c)) == 0)
        return false;
    return 0 < ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((((NiNode*)(unsigned int)(*reinterpret_cast<::fnv_005bac20::Flt *>(&::g_011c786c)))))->FUN_00453470()));
}
}  // namespace fnv_005bac20

namespace fnv_005bac50 {
struct Flt
{
    operator unsigned int() const;
};
// @fnv 0x005bac50
unsigned int FUN_005bac50()
{
    return (*reinterpret_cast<::fnv_005bac50::Flt *>(&::g_011c786c));
}
}  // namespace fnv_005bac50


// @fnv 0x005bac60
NiNode* FUN_005bac60()
{
    return (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011dee84)).operator->();
}

struct GlobalObject_00633c90
{
    void* operator->() const;
};
// @fnv 0x005bac70
void* FUN_005bac70()
{
    return ::g_011deca4.operator->();
}


// @fnv 0x005bac80
void FUN_005bac80(int value)
{
    (*reinterpret_cast<int *>(&::DAT_011c6f18)) = value;
}

struct FUN_00483370
{
    virtual void DestructorEntry();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00483370();
    ~FUN_00483370();
};
struct FUN_00402d00
{
    virtual void DestructorEntry();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FUN_00402d00();
    ~FUN_00402d00();
};
struct FUN_00680890
{
    unsigned int first;
    unsigned int second;
    FUN_00680890();
    ~FUN_00680890();
};
struct FUN_0096a2d0
{
    unsigned int first;
    unsigned int second;
    FUN_0096a2d0();
    ~FUN_0096a2d0();
};
struct FUN_005a7c50 : FUN_00483370, FUN_00402d00
{
    FUN_00680890 member34;
    FUN_0096a2d0 member3c;
    FUN_0096a2d0 member44;
    FUN_0096a2d0 member4c;
    FUN_005a7c50();
};
// Constructs the object and calls FUN_004f15a0 with 0x6a.
// @fnv 0x005a7c50
FUN_005a7c50::FUN_005a7c50()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x6a);
}

// FUN_005bd580 : float member getter, returns *m_pIntegerData if present else 0.0f
struct FUN_005bd580_cls
{
    int m_i00;
    int m_i01;
    int m_i02;
    int m_i03;
    int m_i04;
    int m_i05;
    int m_i06;
    int m_i07;
    int m_i08;
    int m_i09;
    int m_i10;
    int m_i11;
    int m_i12;
    int m_i13;
    float* m_pIntegerData;
    float FUN_005bd580();
};

// @fnv 0x005bd580
float FUN_005bd580_cls::FUN_005bd580()
{
    return this->m_pIntegerData != 0 ? *this->m_pIntegerData : 0.0f;
}

struct FUN_005a77b0 : FUN_00483370, FUN_00402d00
{
    virtual void Extra();
    FUN_005a77b0();
};
// Constructor that calls FUN_004f15a0 with 0x6b and ClearFlag with 1 on this object.
// @fnv 0x005a77b0
FUN_005a77b0::FUN_005a77b0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((FUN_005a7c50*)this)))->FUN_004f15a0(0x6b);
    ((FUN_005a7840_Class*)this)->ClearFlag(1);
}

struct FUN_005a78a0 : FUN_00483370, FUN_00402d00
{
    virtual void Extra();
    virtual ~FUN_005a78a0();
};
// @fnv 0x005a78a0
FUN_005a78a0::~FUN_005a78a0()
{}

struct FUN_004855a0_shell
{
};
struct FUN_00487010_shell
{
    void FUN_00487010();
};
struct FUN_00483710_shell
{
};
struct FUN_00485e20_shell
{
};
struct FUN_00485680_shell
{
};

struct FUN_005a7a90_shell
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
    void FUN_005a7a90();
};

struct FUN_005a7b00_Record
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
    unsigned int m_24;
};
extern int DAT_01186490;
FUN_005a7b00_Record* __cdecl FUN_00ec43fb(unsigned int id, int unused, const int* descriptor, const int* type,
                                          int flag);
struct FUN_005a7b00_Class
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
    unsigned int m_24;
    void InitializeFromRecord(unsigned int id);
};
// Looks up a record by id, copies its m_24 field into this object's m_24, then calls FUN_004851b0 with the id.
// @fnv 0x005a7b00
void FUN_005a7b00_Class::InitializeFromRecord(unsigned int id)
{
    FUN_005a7b00_Record* record = FUN_00ec43fb(id, 0, &DAT_01183028, &DAT_01186490, 0);
    if (record == 0)
        return;
    ::__memcpy(&m_24, &record->m_24, 1);
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0((void *)(id));
}

namespace fnv_005a8660 {
extern "C" char DAT_011864b0;
struct FUN_005a7be0
{
    int data[2];
    FUN_005a7be0();
};
struct CopyList
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};
struct CopyString
{
};
struct CopyForm
{
    char data[0x34];
    CopyList* FUN_005a8080();
    void CopyFrom(void*);
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
// Copies data from the form returned by FUN_00ec43fb into this form, cloning its two node lists and copying several fields.
// @fnv 0x005a8660
void CopyForm::CopyFrom(void* apSource)
{
    CopyForm* source3 = (CopyForm*)FUN_00ec43fb(apSource, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_011864b0, 0);
    if (!source3)
        return;
    reinterpret_cast<::FUN_00680a70_shell *>((((::fnv_005a8660::CopyString *)(::FUN_006a9540((char *)this)))))->CopyConditions((::PerkEntryConditionSet *)(::fnv_005a8660::CopyString *)(((::fnv_005a8660::CopyString *)(::FUN_006a9540((char *)(source3))))), (::PerkEntryConditionSet *)(0));
    ::__memcpy(data + 0x24, source3->data + 0x24, 0x10);
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apSource);
    while (!((::fnv_005a8660::CopyList *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->FUN_008256d0())
        ((::fnv_005a8660::CopyList *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->FUN_0063f7b0();
    CopyList* iter = ((::fnv_005a8660::CopyList *)(reinterpret_cast<struct ::FUN_005a8080 *>((source3))->GetField()));
    while (iter && !iter->FUN_008256d0())
    {
        FUN_005a7be0* oldNode = *((::fnv_005a8660::FUN_005a7be0 **)(new ((void *)(iter)) ::Vec3()));
        FUN_005a7be0* newNode = new FUN_005a7be0;
        reinterpret_cast<::FUN_00537e90 *>((newNode))->SetQuantity(((unsigned int)(::FUN_00559450((int *)(oldNode)))));
        reinterpret_cast<::CombatProcedure *>((newNode))->Initialize((::CombatController *)(void *)(reinterpret_cast<::Callees *>((oldNode))->FUN_00726070()));
        reinterpret_cast<::Callees *>((((::fnv_005a8660::CopyList *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))))->FUN_00905820((void *)&(newNode));
        iter = ((::fnv_005a8660::CopyList *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
    }
    while (!((::fnv_005a8660::CopyList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))->FUN_008256d0())
        ((::fnv_005a8660::CopyList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))->FUN_0063f7b0();
    iter = ((::fnv_005a8660::CopyList *)(reinterpret_cast<::FUN_005d43c0_ *>((source3))->FUN_005d43c0()));
    while (iter && !iter->FUN_008256d0())
    {
        FUN_005a7be0* oldNode = *((::fnv_005a8660::FUN_005a7be0 **)(new ((void *)(iter)) ::Vec3()));
        FUN_005a7be0* newNode = new FUN_005a7be0;
        reinterpret_cast<::FUN_00537e90 *>((newNode))->SetQuantity(((unsigned int)(::FUN_00559450((int *)(oldNode)))));
        reinterpret_cast<::CombatProcedure *>((newNode))->Initialize((::CombatController *)(void *)(reinterpret_cast<::Callees *>((oldNode))->FUN_00726070()));
        reinterpret_cast<::Callees *>((((::fnv_005a8660::CopyList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00905820((void *)&(newNode));
        iter = ((::fnv_005a8660::CopyList *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
    }
    reinterpret_cast<::TESRecipe *>(this)->SetRequiredSkill((::ActorValue::Index)(((int)(reinterpret_cast<::ActorMover *>((source3))->GetCurrentMoveModeType()))));
    reinterpret_cast<::FUN_0061cc40_shell *>(this)->FUN_0061cc40(((int)(reinterpret_cast<::FUN_0045cd60_shell *>((source3))->FUN_0045cd60())));
    reinterpret_cast<::FUN_005a8040_class *>(this)->SetField54(((int)(reinterpret_cast<::FUN_006a1b60_Class *>((source3))->GetField54())));
    reinterpret_cast<::LowProcess *>(this)->SetPackageObjectType(reinterpret_cast<::LowProcess *>((source3))->GetPackageObjectType());
}
}  // namespace fnv_005a8660

namespace fnv_005a8910 {
extern "C" char DAT_011864b0;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct SubItem
{
};
struct SubList
{
    unsigned int FUN_005ae380();
    bool FUN_008256d0();
};
struct SubString
{
};
struct SubChallenge
{
    SubList* FUN_005a8080();
    bool IsNotEqual(void*);
};
// Resolves input to a SubChallenge and returns true if any field, string, list size or list element differs from this object's, false if all match.
// @fnv 0x005a8910
bool SubChallenge::IsNotEqual(void* input)
{
    SubChallenge* other = (SubChallenge*)FUN_00ec43fb(input, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_011864b0, 0);
    if (!other)
        return true;
    if (((int)(reinterpret_cast<::FUN_006a1b60_Class *>(this)->GetField54())) != ((int)(reinterpret_cast<::FUN_006a1b60_Class *>((other))->GetField54())))
        return true;
    if (reinterpret_cast<::LowProcess *>(this)->GetPackageObjectType() != reinterpret_cast<::LowProcess *>((other))->GetPackageObjectType())
        return true;
    if (reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType() != reinterpret_cast<::ActorMover *>((other))->GetCurrentMoveModeType())
        return true;
    if (((int)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())) != ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((other))->FUN_0045cd60())))
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(other)))
        return true;
    if (reinterpret_cast<::PerkEntryConditionSet *>(&((*(::fnv_005a8910::SubString *)(::FUN_006a9540((char *)this)))))->Compare((::PerkEntryConditionSet *)&((*(::fnv_005a8910::SubString *)(::FUN_006a9540((char *)(other)))))))
        return true;
    if (((::fnv_005a8910::SubList *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->FUN_005ae380() != ((::fnv_005a8910::SubList *)(reinterpret_cast<struct ::FUN_005a8080 *>((other))->GetField()))->FUN_005ae380())
        return true;
    if (((::fnv_005a8910::SubList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))->FUN_005ae380() != ((::fnv_005a8910::SubList *)(reinterpret_cast<::FUN_005d43c0_ *>((other))->FUN_005d43c0()))->FUN_005ae380())
        return true;
    SubList* a = ((::fnv_005a8910::SubList *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    SubList* b5 = ((::fnv_005a8910::SubList *)(reinterpret_cast<struct ::FUN_005a8080 *>((other))->GetField()));
    while (b5 && !b5->FUN_008256d0())
    {
        if (!a || a->FUN_008256d0())
            return true;
        SubItem* x = *((::fnv_005a8910::SubItem **)(new ((void *)(a)) ::Vec3()));
        SubItem* y = *((::fnv_005a8910::SubItem **)(new ((void *)(b5)) ::Vec3()));
        if (((unsigned char)(reinterpret_cast<::FUN_005a7c00_class *>((x))->FUN_005a7c00((::BSSimpleListBase *)(y)))))
            return true;
        b5 = ((::fnv_005a8910::SubList *)(reinterpret_cast<::Callees *>((b5))->FUN_00726070()));
        a = ((::fnv_005a8910::SubList *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
    }
    SubList* c3 = ((::fnv_005a8910::SubList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    SubList* d2 = ((::fnv_005a8910::SubList *)(reinterpret_cast<::FUN_005d43c0_ *>((other))->FUN_005d43c0()));
    while (d2 && !d2->FUN_008256d0())
    {
        if (!c3 || c3->FUN_008256d0())
            return true;
        SubItem* x = *((::fnv_005a8910::SubItem **)(new ((void *)(c3)) ::Vec3()));
        SubItem* y = *((::fnv_005a8910::SubItem **)(new ((void *)(d2)) ::Vec3()));
        if (((unsigned char)(reinterpret_cast<::FUN_005a7c00_class *>((x))->FUN_005a7c00((::BSSimpleListBase *)(y)))))
            return true;
        d2 = ((::fnv_005a8910::SubList *)(reinterpret_cast<::Callees *>((d2))->FUN_00726070()));
        c3 = ((::fnv_005a8910::SubList *)(reinterpret_cast<::Callees *>((c3))->FUN_00726070()));
    }
    return false;
}
}  // namespace fnv_005a8910

class TESForm
{
  public:
    virtual ~TESForm();
public:
    void ClearData();
};
// @fnv 0x005a7a90
void FUN_005a7a90_shell::FUN_005a7a90()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    ((FUN_00487010_shell*)&this->unk18)->FUN_00487010();
    if (FUN_00401500())
        reinterpret_cast<::TESForm *>((((FUN_00483710_shell*)&this->unk24)))->ClearData();
    reinterpret_cast<::SDSaveForm *>((((FUN_00485e20_shell*)this)))->FUN_00485e20((const void *)((int)((char*)&this->unk24)), 1);
    if (FUN_00401500())
        reinterpret_cast<::TESForm *>((((FUN_00483710_shell*)&this->unk24)))->ClearData();
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

class TESRecipeCategory : public TESForm
{
  public:
};

struct FUN_008ad910_rd;

class FUN_008ad910_ref
{
  public:
};

class FUN_005e79a0_t
{
  public:
};

class FUN_005a7b60_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned char m_data;

    bool FUN_005a7b60(TESForm* pkForm);
};

// Returns true if pkForm is not a TESRecipeCategory, its first data byte differs from m_data, or FUN_00485270 returns true; otherwise false.
// @fnv 0x005a7b60
bool FUN_005a7b60_cls::FUN_005a7b60(TESForm* pkForm)
{
    TESRecipeCategory* pkCategory = dynamic_cast<TESRecipeCategory*>(pkForm);
    if (!pkCategory)
        return true;
    if (memcmp(&m_data, ((::FUN_008ad910_rd *)(reinterpret_cast<::TESRecipe *>((reinterpret_cast<FUN_008ad910_ref*>(pkCategory)))->GetData())), 1))
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pkCategory))
        return true;
    return false;
}

struct DeletingObject
{
    void* Destroy(unsigned int flags);
};
// Calls FUN_005a7d40, then frees this via operator delete when the low bit of flags is set, and returns this.
// @fnv 0x005a7d10
void* DeletingObject::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_005a7d40 *>(this)->FUN_005a7d40::~FUN_005a7d40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_005a8490 {
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
class TESForm : public BaseFormComponent
{
  public:
    unsigned char formType;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int flags;
    unsigned int formID;
    unsigned int unk10;
    unsigned int unk14;
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> fullName;
};
struct RecipeItem
{
    unsigned int quantity;
    TESForm* form;
};
struct RecipeItemProcessor
{
    unsigned int unk00;
    unsigned int unk04;
};
struct RecipeData
{
    unsigned int skill;
    unsigned int level;
    TESForm* category;
    TESForm* subcategory;
};
class TESRecipe : public TESForm, public TESFullName
{
  public:
    RecipeData data;
    RecipeItemProcessor conditions;
    BSSimpleList<RecipeItem*> ingredients;
    BSSimpleList<RecipeItem*> outputs;
    BSSimpleList<RecipeItem*> unk4c;
    BSSimpleList<RecipeItem*>* FUN_005a8080();
    void FUN_005a8490();
};
// Stores category and subcategory form IDs, then calls FUN_00485910 with the form ID and count of each ingredient and each output item.
// @fnv 0x005a8490
void TESRecipe::FUN_005a8490()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(this)->FUN_00487010();
    reinterpret_cast<::FUN_00680910_shell *>((((::fnv_005a8490::RecipeItemProcessor *)(::FUN_006a9540((char *)this)))))->ProcessItems();
    ((::fnv_005a8490::RecipeData *)(reinterpret_cast<::TESRecipe *>(this)->GetData()))->category = reinterpret_cast<TESForm*>(((::fnv_005a8490::TESForm *)(reinterpret_cast<::FUN_006a1b60_Class *>(this)->GetField54())) ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_005a8490::TESForm *)(reinterpret_cast<::FUN_006a1b60_Class *>(this)->GetField54()))))->FUN_0084e3a0())) : 0);
    ((::fnv_005a8490::RecipeData *)(reinterpret_cast<::TESRecipe *>(this)->GetData()))->subcategory = reinterpret_cast<TESForm*>(((::fnv_005a8490::TESForm *)(reinterpret_cast<::LowProcess *>(this)->GetPackageObjectType())) ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_005a8490::TESForm *)(reinterpret_cast<::LowProcess *>(this)->GetPackageObjectType()))))->FUN_0084e3a0())) : 0);
    if (FUN_00401500())
        reinterpret_cast<::FUN_00414220_shell *>(&(data))->FUN_00414220();
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20(&data, 16);
    if (FUN_00401500())
        reinterpret_cast<::FUN_00414220_shell *>(&(data))->FUN_00414220();
    BSSimpleList<RecipeItem*>* iter = ((::BSSimpleList< ::fnv_005a8490::RecipeItem *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    RecipeItem* item = 0;
    while (iter && ((::fnv_005a8490::RecipeItem *)(new ((void *)(iter)) ::Vec3())))
    {
        item = ((::fnv_005a8490::RecipeItem *)(new ((void *)(iter)) ::Vec3()));
        iter = ((::BSSimpleList< ::fnv_005a8490::RecipeItem *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        ::FUN_00485910(0x4c494352, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_005a8490::TESForm *)(reinterpret_cast<::Callees *>((item))->FUN_00726070()))))->FUN_0084e3a0())));
        ::FUN_00485910(0x59514352, ((unsigned int)(::FUN_00559450((int *)(item)))));
    }
    iter = ((::BSSimpleList< ::fnv_005a8490::RecipeItem *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    item = 0;
    while (iter && ((::fnv_005a8490::RecipeItem *)(new ((void *)(iter)) ::Vec3())))
    {
        item = ((::fnv_005a8490::RecipeItem *)(new ((void *)(iter)) ::Vec3()));
        iter = ((::BSSimpleList< ::fnv_005a8490::RecipeItem *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        ::FUN_00485910(0x444f4352, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_005a8490::TESForm *)(reinterpret_cast<::Callees *>((item))->FUN_00726070()))))->FUN_0084e3a0())));
        ::FUN_00485910(0x59514352, ((unsigned int)(::FUN_00559450((int *)(item)))));
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}
}  // namespace fnv_005a8490

struct FUN_005a7870_cls
{
    virtual ~FUN_005a7870_cls();
};

// @fnv 0x005a7870
FUN_005a7870_cls::~FUN_005a7870_cls()
{}

struct ScriptLocals;

struct Script
{
    static bool __cdecl GetValue(double& result, char const* format, unsigned int& value, TESObjectREFR* reference1,
                                 TESObjectREFR* reference2, Script* script, ScriptLocals* locals, bool evaluate);
};


// Reads a short count and that many values from data via Script::GetValue, then formats them into string using format; returns false if any read fails.
// @fnv 0x005b4960
bool __cdecl FUN_005b4960(int unused, char const* data, TESObjectREFR* reference1, TESObjectREFR* reference2,
                          Script* script, ScriptLocals* locals, int unused2, unsigned int& value, char const* format,
                          BSStringT<char>* string)
{
    double values[10];

    {
        short count = *reinterpret_cast<short const*>(data + value);
        short i;

        value += 2;
        ::FUN_00403d30(values, 0, sizeof(values));

        for (i = 0; i < count; ++i)
        {
            values[i] = 0.0;
            if (!Script::GetValue(values[i], data, value, reference1, reference2, script, locals, true))
            {
                return false;
            }
        }
    }

    ::FUN_00406f60((::FUN_00406f90_this *)(string), format, values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7],
                    values[8], values[9]);
    return true;
}

#include "generated/data/staging/blk_005a0000_od.inc"
