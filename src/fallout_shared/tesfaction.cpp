// fallout_shared/tesfaction.cpp: TESFaction, Holder, DelStandIn, FakeFaction and more (36 functions)

#include <new>
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/C0B0Owner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040e500_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048bb70_shell.h"
#include "fnv/decl/FUN_0048bf50_cls.h"
#include "fnv/decl/FUN_0048c1b0_shell.h"
#include "fnv/decl/FUN_0048c220_shell.h"
#include "fnv/decl/FUN_0048c930_shell.h"
#include "fnv/decl/FUN_0048c9d0_Class.h"
#include "fnv/decl/FUN_0048ca90.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_00616c20_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESReactionFormLoad.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048c2e0__FUN_0048c2e0_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00871000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_011c3000.h"
#include "tesfaction_decls.h"

extern "C" void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x005fc840
void TESFaction::ClearData()
{
    ClearReactions();
}

// @fnv 0x005fc800
void TESFaction::ResetFormData()
{
    m_iFirstFactionValue = 0;
    m_iSecondFactionValue = 0;
    pReputationData = 0;
    memset(&data, 0, sizeof(data));
}

// Reverts the form from the load buffer, then initializes the reaction's load-game state from the same buffer.
// @fnv 0x005fd7d0
void TESFaction::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>((reinterpret_cast<TESFormBufferAccess*>(static_cast<TESForm*>(this))))->FUN_004534f0((unsigned int)(buffer));
    reinterpret_cast<::TESReactionForm *>(&(reinterpret_cast<TESFactionReactionView&>(*this).reaction))->InitLoadGame(buffer);
}

// @fnv 0x005fd800
void TESFaction::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>((reinterpret_cast<TESFormBufferAccess*>(static_cast<TESForm*>(this))))->FUN_004534f0((unsigned int)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x80000000)))->FUN_004280f0())
    {
        m_iFirstFactionValue = 0;
        m_iSecondFactionValue = 0;
    }
}

// @fnv 0x005fc860
void TESFaction::ClearReactions()
{
    FactionRankPresentation* rankData;
    while (!((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->IsEmpty())
    {
        rankData = ((::FactionRankPresentation *)(new ((void *)(((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField())))) ::Vec3()));
        delete rankData;
        ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->RemoveHead();
    }
}

// @fnv 0x005fcf80
void TESFaction::InitItem()
{
    if (GetInitialized())
        return;

    reinterpret_cast<::TESReactionForm *>(&(reinterpret_cast<TESFactionReactionView&>(*this).reaction))->InitItem(this);
    SetInitializationState(true);
    if (pReputationData != 0)
    {
        unsigned int formID = 0;
        formID = reinterpret_cast<unsigned int>(pReputationData);
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pReputationData = reinterpret_cast<::TESDataHandler *>((reinterpret_cast<TESDataHandlerAccess*>((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetReputation(formID);
    }
}

// @fnv 0x005fd730
void TESFaction::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESForm *>((reinterpret_cast<TESFormBufferAccess*>(static_cast<TESForm*>(this))))->LoadGame(buffer);
    reinterpret_cast<::FUN_0048ca90 *>(&(reinterpret_cast<TESFactionReactionView&>(*this).reaction))->LoadReaction(buffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(2)))->FUN_004280f0())
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&data), 4);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x80000000)))->FUN_004280f0())
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iFirstFactionValue), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iSecondFactionValue), 4);
    }
}

struct FUN_005fc840_shell : public TESFaction
{
    void FUN_005fc840();
};

// @fnv 0x005fc840
void FUN_005fc840_shell::FUN_005fc840()
{
    ClearReactions();
}

struct FUN_005fc860_shell : public TESFaction
{
    void FUN_005fc860();
};

// Deletes every entry in the rank data list and removes each node until the list is empty.
// @fnv 0x005fc860
void FUN_005fc860_shell::FUN_005fc860()
{
    while (!((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->IsEmpty())
    {
        FactionRankPresentation* rankData = ((::FactionRankPresentation *)(new ((void *)(((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField())))) ::Vec3()));
        delete rankData;
        ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->RemoveHead();
    }
}

extern unsigned int _data_011c16bc;
struct SB005fc900
{
    char p[8];
    ~SB005fc900();
};
struct TT005fc900
{
    virtual ~TT005fc900();
    char p[0xc];
};
struct FUN_005fc900 : public SB005fc900
{
    SB005fc900 s;
    TT005fc900 t;
    ~FUN_005fc900();
};
// Destructor for FUN_005fc900 that destroys its embedded SB005fc900 and TT005fc900 members.
// @fnv 0x005fc900
FUN_005fc900::~FUN_005fc900()
{}

struct FUN_005fcf80_shell : public TESFaction
{
    void FUN_005fcf80();
};

class TESReputation;

struct TESFormInitHelper
{
};

struct TESReactionFormInitHelper
{
    void InitItem(TESForm*);
};

struct TESDataHandlerRepHelper
{
};

// Initializes the faction's reaction form, marks it initialized, and resolves its reputation from the data handler.
// @fnv 0x005fcf80
void FUN_005fcf80_shell::FUN_005fcf80()
{
    if (reinterpret_cast<::TESForm *>((void *)(reinterpret_cast<const TESFormInitHelper*>(this)))->GetInitialized())
        return;
    reinterpret_cast<::TESReactionForm *>((reinterpret_cast<TESReactionFormInitHelper*>(static_cast<TESReactionForm *>(this))))->InitItem(this);
    SetInitializationState(true);
    if (this->pReputationData != 0)
    {
        unsigned int uiReputationFormID = 0;
        uiReputationFormID = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x38);
        ::ResolveFormID((unsigned int *)&(uiReputationFormID), GetFile(-1));
        this->pReputationData =
            reinterpret_cast<::TESDataHandler *>((reinterpret_cast<TESDataHandlerRepHelper*>((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetReputation(uiReputationFormID);
    }
}

struct FUN_005fd3b0_shell : public TESFaction
{
    int FUN_005fd3b0(TESFaction*);
};

struct Dummy_0048bf50
{
};

// @fnv 0x005fd3b0
int FUN_005fd3b0_shell::FUN_005fd3b0(TESFaction* pFaction)
{
    return reinterpret_cast<::FUN_0048bf50_cls *>((((Dummy_0048bf50*)static_cast<TESReactionForm *>(this))))->FindValueByKey((int)(pFaction));
}

struct Sub005fd430
{
    char pad[0x24];
};
struct F005fd430
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
    virtual void v12(int);
    char pad[0x24 - 4];
    void FUN_005fd430(F005fd430* f, int r);
};
// Forwards f and r to the object at this+0x24 via FUN_0048c220, then calls v12(4).
// @fnv 0x005fd430
void F005fd430::FUN_005fd430(F005fd430* f, int r)
{
    reinterpret_cast<::FUN_0048c220_shell *>((((F005fd430*)((char*)this + 0x24))))->FUN_0048c220((::TESForm *)(f), r);
    v12(4);
}

struct FUN_005fd460_shell : public TESFaction
{
    int FUN_005fd460();
};

// Counts the entries in the rank data list, appends a new rank data node to the tail (or head if empty), and returns the previous count.
// @fnv 0x005fd460
int FUN_005fd460_shell::FUN_005fd460()
{
    int iElementIndex = 0;
    FactionRankPresentation* pdata = new FactionRankPresentation;
    BSSimpleList<FactionRankPresentation*>* pCurrentElementNext = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    BSSimpleList<FactionRankPresentation*>* plastlist = 0;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        ++iElementIndex;
        plastlist = pCurrentElementNext;
        pCurrentElementNext = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    if (plastlist)
    {
        reinterpret_cast<::Callees *>((plastlist))->FUN_00905820((void *)&(pdata));
    }
    else
    {
        ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))->AddHead(pdata);
    }
    return iElementIndex;
}

struct FUN_005fd730_shell : public TESFaction
{
    void FUN_005fd730(BGSLoadFormBuffer*);
};

// Loads the form, then reads the reaction buffer and, per change flags, reads 4-byte values into offsets 0x34, 0x44 and 0x48.
// @fnv 0x005fd730
void FUN_005fd730_shell::FUN_005fd730(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::LoadGame(apLoadGameBuffer);
    reinterpret_cast<::FUN_0048ca90 *>((((TESReactionFormBufferAccess*)static_cast<TESReactionForm *>(this))))->LoadReaction(apLoadGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(2)))->FUN_004280f0())
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->data), 4);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x80000000)))->FUN_004280f0())
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iFirstFactionValue), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iSecondFactionValue), 4);
    }
}

struct FUN_005fd800_shell : public TESFaction
{
    void FUN_005fd800(BGSLoadFormBuffer*);
};

// @fnv 0x005fd800
void FUN_005fd800_shell::FUN_005fd800(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((unsigned int)apLoadGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetOldChangeFlags(0x80000000)))->FUN_004280f0())
    {
        this->m_iFirstFactionValue = 0;
        this->m_iSecondFactionValue = 0;
    }
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x005fc8d0
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::FUN_005fc900 *>((((DtorStandIn*)this)))->FUN_005fc900::~FUN_005fc900();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct FactionFormBase
{
    unsigned char pad[0x14];
    FactionFormBase();
    ~FactionFormBase();
    virtual void vfn0();
};
struct FactionFullNameBase
{
    unsigned char pad[8];
    FactionFullNameBase();
    ~FactionFullNameBase();
    virtual void vfn0();
};
struct FactionReactionBase
{
    unsigned char pad[0xc];
    FactionReactionBase();
    ~FactionReactionBase();
    virtual void vfn0();
};
struct SL
{
    unsigned char data[8];
    SL();
    ~SL();
};
class FUN_005fc680 : public FactionFormBase, public FactionFullNameBase, public FactionReactionBase
{
  public:
    unsigned int data34;
    void* pReputationData;
    SL m_kRankDataList;
    FUN_005fc680();
};
// @fnv 0x005fc680
FUN_005fc680::FUN_005fc680()
{
    reinterpret_cast<::TESFaction *>(this)->ResetFormData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(8);
}

namespace fnv_005fc730 {

struct FUN_005fc730_shell
{
    void FUN_005fc760();
    void* FUN_005fc730(unsigned int flags);
};

// Calls FUN_005fc760, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x005fc730
void* FUN_005fc730_shell::FUN_005fc730(unsigned int flags)
{
    FUN_005fc760();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_005fc730

struct FUN_00484bf0
{
    unsigned short GetSaveSize(unsigned int);
};

struct FUN_0048c2e0_shell
{
};

struct FUN_005fd550_shell
{
    unsigned short GetSaveSize(unsigned int);
};

// Returns the sum of the save sizes of the object and its sub-object at offset 0x24, plus 4 when aiFlags has bit 2 set.
// @fnv 0x005fd550
unsigned short FUN_005fd550_shell::GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00484bf0_shell *>((((FUN_00484bf0*)this)))->FUN_00484bf0(aiFlags);
    isize += reinterpret_cast<::fnv_0048c2e0::FUN_0048c2e0_shell *>((((FUN_0048c2e0_shell*)((char*)this + 0x24))))->FUN_0048c2e0(aiFlags);
    if (aiFlags & 2)
        isize += 4;
    return isize;
}

struct NiFormArray
{
    unsigned int GetIndexOfForm(TESForm* form);
};

struct FUN_005ff520_shell
{
    unsigned int FUN_005ff520(unsigned int flags);
};

// @fnv 0x005ff520
unsigned int FUN_005ff520_shell::FUN_005ff520(unsigned int apForm)
{
    unsigned int index = 0xffffffff;
    if (*reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x40))
    {
        index = (*reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x40))
                    ->GetIndexOfForm(reinterpret_cast<TESForm*>(apForm));
    }
    return index;
}

template <int N> struct EndianSizeTag
{
};
struct Class005a6b10
{
    int m0;
    int m1;
    int m2;
    void FUN_005a6b10();
};
// Byte-swaps the three int fields m0, m1 and m2 via BSEndian.
// @fnv 0x005a6b10
void Class005a6b10::FUN_005a6b10()
{
    ::FUN_00401080(&m0);
    ::FUN_00401080(&m1);
    ::FUN_00401080(&m2);
}

struct FUN_0051b070_shell
{
};
struct PC7d
{
public:
    void FUN_00484c20(unsigned int);
};
struct S24
{
    void WriteReactionList(unsigned int);
};
struct FUN_005fd5c0_shell
{
    void FUN_005fd5c0(unsigned int);
};
// @fnv 0x005fd5c0
void FUN_005fd5c0_shell::FUN_005fd5c0(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>((((FUN_0051b070_shell*)this)))->FUN_00484c20(aiFlags);
    ((S24*)((char*)this + 0x24))->WriteReactionList(aiFlags);
    if (aiFlags & 2)
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((((PC7d*)this)))->FUN_00484ce0((void *)((unsigned int)((char*)this + 0x34)), 4);
}

struct TESFormStub
{
};
struct STR24
{
};
struct STR00
{
};
struct FUN_005fd610_shell
{
    void FUN_005fd610(unsigned int, unsigned int);
};
// @fnv 0x005fd610
void FUN_005fd610_shell::FUN_005fd610(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((((TESFormStub*)this)))->FUN_00484c50(aiFlags, aiCurrentFlags);
    reinterpret_cast<::TESReactionFormLoad *>((((STR24*)((char*)this + 0x24))))->LoadReactions(aiFlags, (::BGSLoadFormBuffer *)(aiCurrentFlags));
    if (aiFlags & 2)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00((void*)((char*)this + 0x34), 4);
}

struct Holder
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18(int) = 0;
    char _pad[0x30];
    int m_flags;
    void FUN_005fc970(int flag, bool value);
public:
    void FUN_00485680();
};
// Sets or clears the given bit in m_flags based on value, then calls v18(2).
// @fnv 0x005fc970
void Holder::FUN_005fc970(int flag, bool value)
{
    value ? m_flags |= flag : m_flags &= ~flag;
    v18(2);
}

struct HackReact
{
    void SetReactionValue(struct TESForm* form, int v);
};
struct Unk_005fd3d0
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
    virtual void v18(int v);
    char pad[32];
    HackReact m_hack;
    void FUN_005fd3d0(struct TESForm* form, int v);
};
// @fnv 0x005fd3d0
void Unk_005fd3d0::FUN_005fd3d0(struct TESForm* form, int v)
{
    m_hack.SetReactionValue(form, v);
    v18(4);
}

struct Helper_48c0b0
{
};
struct Outer_5fd400
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void v18(int);
    int _pad[8];
    Helper_48c0b0 _h;
    void FUN_005fd400(int, int);
};
// Calls the helper's FUN_0048c0b0 with a and b, then invokes virtual v18 with 4.
// @fnv 0x005fd400
void Outer_5fd400::FUN_005fd400(int aiArg1, int aiArg2)
{
    reinterpret_cast<::C0B0Owner *>(&(_h))->FUN_0048c0b0((::C0B0Form *)(aiArg1), aiArg2);
    v18(4);
}

namespace fnv_005fd660 {
struct SkyObject
{
};
struct MidObj
{
};
struct Holder : SkyObject
{
    char _pad[0x24];
    MidObj mid;
    void FUN_005fd660(unsigned int, unsigned int);
};
// Calls SkyObject::Update and then mid.ResolveGroupReactionForms with the same two arguments.
// @fnv 0x005fd660
void Holder::FUN_005fd660(unsigned int auiArg1, unsigned int auiArg2)
{
    reinterpret_cast<::FUN_008d0600_s *>(this)->FUN_008d0600(auiArg1, auiArg2);
    reinterpret_cast<::FUN_0048c930_shell *>(&(mid))->ResolveGroupReactionForms(auiArg1, auiArg2);
}
}  // namespace fnv_005fd660

struct Unk38
{
};
struct FakeFaction
{
    virtual void F00();
    virtual void F01();
    virtual void F02();
    virtual void F03();
    virtual void F04();
    virtual void F05();
    virtual void F06();
    virtual void F07();
    virtual void F08();
    virtual void F09();
    virtual void F10();
    virtual void F11();
    virtual void F12();
    virtual void F13();
    virtual void F14();
    virtual void F15();
    virtual void F16();
    virtual void F17();
    virtual void F18(int);
    char pad0[0x34];
    Unk38* p38;
    int pad1[3];
    int i48;
    void ModifyReputation(int aiCount, bool bModRep);
};
// @fnv 0x005fda00
void FakeFaction::ModifyReputation(int aiCount, bool bModRep)
{
    i48 += aiCount;
    if (p38 != 0 && bModRep)
        reinterpret_cast<::FUN_00616c20_shell *>((p38))->FUN_00616c20(0);
    F18(0x80000000);
}

struct FUN_005e78f0_t
{
};
struct NiAVObject
{
};
struct TESTopicInfo
{
};
struct BGSAcousticSpace
{
};
struct BSStr
{
};
struct Flt
{
    operator unsigned int();
};

struct FUN_005fd210_shell : TESFaction
{
    void FUN_005fd210(TESForm* apCopy);
};

// Copies faction data from apCopy: base copy, rotation, noon sound, then deep-copies each rank entry into this faction's rank list.
// @fnv 0x005fd210
void FUN_005fd210_shell::FUN_005fd210(TESForm* apCopy)
{
    BSSimpleList<FactionRankPresentation*>* pDestRankList;
    {
        TESFaction* faction = dynamic_cast<TESFaction*>(apCopy);
        if (!faction)
            return;
        reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
        __memcpy((char*)&this->data, ::FUN_006a9540((char *)(((NiAVObject*)faction))), 4);
        reinterpret_cast<::FUN_0040e500_shell *>((((BGSAcousticSpace*)this)))->SetValue((int)(((::TESSound *)(::GetField38((char *)(((TESTopicInfo*)faction)))))));
        ClearReactions();
        pDestRankList = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
        {
            BSSimpleList<FactionRankPresentation*>* pSourceRankList = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((faction))->GetField()));
            while (pSourceRankList && !pSourceRankList->IsEmpty())
            {
                FactionRankPresentation* pdata = new FactionRankPresentation;
                reinterpret_cast<::TextString *>((((BSStr*)&pdata->m_kMaleRankName)))->FUN_004037f0((const char*)(unsigned int)*(Flt*)&((::FactionRankPresentation *)(new ((void *)(pSourceRankList)) ::Vec3()))->m_kMaleRankName, 0);
                reinterpret_cast<::TextString *>((((BSStr*)&pdata->m_kFemaleRankName)))->FUN_004037f0((const char*)(unsigned int)*(Flt*)&((::FactionRankPresentation *)(new ((void *)(pSourceRankList)) ::Vec3()))->m_kFemaleRankName, 0);
                pdata->m_kRankTexture.CopyFromBase(&((::FactionRankPresentation *)(new ((void *)(pSourceRankList)) ::Vec3()))->m_kRankTexture);
                reinterpret_cast<::Callees *>((pDestRankList))->FUN_00905820((void *)&(pdata));
                if (((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<::Callees *>((pDestRankList))->FUN_00726070())))
                    pDestRankList = (BSSimpleList<FactionRankPresentation*>*)((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<::Callees *>((pDestRankList))->FUN_00726070()));
                pSourceRankList = (BSSimpleList<FactionRankPresentation*>*)((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<::Callees *>((pSourceRankList))->FUN_00726070()));
            }
        }
    }
}

struct BGSSaveFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
struct FUN_005fd690_s
{
    void FUN_005fd690(BGSSaveFormBuffer* buffer);
};
// @fnv 0x005fd690
void FUN_005fd690_s::FUN_005fd690(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FakeForm *>((((BGSSaveFormBuffer*)this)))->SaveIfChanged(buffer);
    reinterpret_cast<::FUN_0048c9d0_Class *>((((BGSSaveFormBuffer*)((char*)this + 0x24))))->FUN_0048c9d0((::FUN_0048c9d0_SaveBuffer *)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(2)))->FUN_004280f0())
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x34, 4, 0);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x80000000)))->FUN_004280f0())
    {
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x44, 4, 0);
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x48, 4, 0);
    }
}

namespace fnv_005fd850 {
int FNV_GetFormType(TESForm*);
struct Node_006815c0
{
};
struct TgtOps
{
};
struct _FactionSub
{
};
struct F005fd430
{
};
struct Reaction_5fd850
{
    TESFaction* pFaction;
    int iMod;
    int eReaction;
};
// Iterates all factions and their reactions; for friend/ally reactions not reciprocated, warns and forces the other faction to be a friend.
// @fnv 0x005fd850
void ValidateFactionReactions()
{
    BSSimpleList<TESFaction*>* pIter = (BSSimpleList<TESFaction*>*)::FUN_00871a30((int)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)));
    while (pIter)
    {
        TESFaction* pFaction = (TESFaction*)*((void **)(new ((void *)(((Node_006815c0*)pIter))) ::Vec3()));
        if (pFaction)
        {
            BSSimpleList<Reaction_5fd850*>* pRIter =
                (BSSimpleList<Reaction_5fd850*>*)((void *)(reinterpret_cast<::BaseProcess *>((((TgtOps*)static_cast<TESReactionForm *>(pFaction))))->GetCurrentProcessData()));
            while (pRIter)
            {
                Reaction_5fd850* pReaction = (Reaction_5fd850*)*((void **)(new ((void *)(((Node_006815c0*)pRIter))) ::Vec3()));
                if (pReaction && pReaction->pFaction && FNV_GetFormType((TESForm*)pReaction->pFaction) == 8 &&
                    (pReaction->eReaction == 3 || pReaction->eReaction == 2))
                {
                    TESFaction* pOther = pReaction->pFaction;
                    int iFactionReaction = reinterpret_cast<::FUN_0048c1b0_shell *>((((_FactionSub*)static_cast<TESReactionForm *>(pOther))))->FUN_0048c1b0((::TESForm *)(pFaction));
                    if (iFactionReaction != 2 && iFactionReaction != 3)
                    {
                        ::FUN_005b5e40(
                            );
                        reinterpret_cast<::F005fd430 *>((((F005fd430*)pOther)))->FUN_005fd430((::F005fd430 *)(::fnv_005fd850::F005fd430 *)((F005fd430*)pFaction), 3);
                    }
                }
                pRIter = ((::BSSimpleList< ::fnv_005fd850::Reaction_5fd850 *> *)(reinterpret_cast<::Callees *>((pRIter))->FUN_00726070()));
            }
        }
        pIter = ((::BSSimpleList< ::TESFaction *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
}
}  // namespace fnv_005fd850

struct ListX
{
    ~ListX();
};

struct Base5a
{
    virtual ~Base5a();
    char padding[0x14];
};

struct FUN_00591300
{
    virtual ~FUN_00591300();
    char padding[8];
};

struct FUN_0048ba70
{
    virtual ~FUN_0048ba70();
    char padding[0x14];
};

struct FUN_005fc760 : public Base5a, public FUN_00591300, public FUN_0048ba70
{
    ListX m_kReactionList;

    ~FUN_005fc760();
};

// Destructor that calls TESFaction::ClearData on this object.
// @fnv 0x005fc760
FUN_005fc760::~FUN_005fc760()
{
    reinterpret_cast<TESFaction*>(this)->TESFaction::ClearData();
}

struct RankTitle : BSStringT<char>
{
    operator const char*() const;
};
struct RankInsignia : TESTexture
{
    unsigned int GetModelLength();
};
class TESReputation
{
  public:
};
struct FullNameSaver : TESFullName
{
};
struct ReactionSaver : TESReactionForm
{
};

struct TESFactionSaveShell : TESForm, FullNameSaver, ReactionSaver
{
    FactionSaveData data;
    TESReputation* pReputationData;
    BSSimpleList<FactionRankPresentation*> m_kRankDataList;
    int m_iFirstFactionValue;
    int m_iSecondFactionValue;
    void SaveFactionData();
};

// @fnv 0x005fc9d0
void TESFactionSaveShell::SaveFactionData()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(this)->FUN_00487010();
    reinterpret_cast<::FUN_0048bb70_shell *>(this)->WriteCameraShotList();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>(&(data))->FUN_00503210();
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20(&data, 4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>(&(data))->FUN_00503210();
    int iRankIndex = 0;
    BSSimpleList<FactionRankPresentation*>* pNode = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    while (pNode && !pNode->IsEmpty())
    {
        FactionRankPresentation* pRank = ((::FactionRankPresentation *)(new ((void *)(pNode)) ::Vec3()));
        ::FUN_00485910(0x4d414e52, iRankIndex);
        if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(static_cast<RankTitle&>(pRank->m_kMaleRankName)))->FUN_004048e0())))
            ::FUN_004856f0((void *)(0x4d414e4d), (void *)((const char*)static_cast<RankTitle&>(pRank->m_kMaleRankName)),
                          (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(static_cast<RankTitle&>(pRank->m_kMaleRankName)))->FUN_004048e0())) + 1));
        if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(static_cast<RankTitle&>(pRank->m_kFemaleRankName)))->FUN_004048e0())))
            ::FUN_004856f0((void *)(0x4d414e46), (void *)((const char*)static_cast<RankTitle&>(pRank->m_kFemaleRankName)),
                          (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(static_cast<RankTitle&>(pRank->m_kFemaleRankName)))->FUN_004048e0())) + 1));
        if (static_cast<RankInsignia&>(pRank->m_kRankTexture).GetModelLength())
            ::FUN_004856f0((void *)(0x4d414e49), (void *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(static_cast<RankInsignia&>(pRank->m_kRankTexture)))->FUN_00408da0()))),
                          (void *)(static_cast<RankInsignia&>(pRank->m_kRankTexture).GetModelLength() + 1));
        iRankIndex++;
        pNode = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    if (pReputationData)
    {
        unsigned int uiRepID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pReputationData))->FUN_0084e3a0()));
        ::FUN_00485910(0x31494d57, uiRepID);
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

class TESTexture1024 : public TESTexture
{
  public:
};

class FactionLoader : public TESFaction
{
  public:
    bool LoadFactionRecord(TESFile* file);
};

// Reads a faction record's chunks (editor ID, bounds, full name, reactions, flags, ranks, reputation) from file until no chunks remain and returns true.
// @fnv 0x005fcb70
bool FactionLoader::LoadFactionRecord(TESFile* file)
{
    FactionRankPresentation* rankData = NULL;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
        {
        case CHUNK_ID_EDID_ID: {
            char* pEditorId = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEditorId), 0x200);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_FULL_ID:
            ::ReadFullName(this, file);
            break;
        case CHUNK_ID_XNAM_ID: {
            ReactionInfo* reaction = new ReactionInfo;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(reaction), 0xC);
            if (file->IsEndianConversionRequired())
            {
                reinterpret_cast<::Class005a6b10 *>((reaction))->FUN_005a6b10();
            }
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ReactionInfo *> *)(reinterpret_cast<::BaseProcess *>((((TESReactionFormLoader*)static_cast<TESReactionForm *>(this))))->GetCurrentProcessData()))))->FUN_00905820((void *)&(reaction));
            break;
        }
        case 0x41544144: {  // DATA
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570() < 9)
            {
                char byteData;
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<TESFactionRecordLoader*>(this)))->FUN_004861f0(file, &byteData, 1);
                data.iFlags = byteData;
            }
            else
            {
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<TESFactionRecordLoader*>(this)))->FUN_004861f0(file, &data, 4);
                if (file->IsEndianConversionRequired())
                {
                    reinterpret_cast<::fnv_00503210::Unk *>(&(data))->FUN_00503210();
                }
            }
            break;
            break;
        }
        case 0x4D414E52: {  // RNAM
            rankData = ::new FactionRankPresentation;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))))->FUN_00905820((void *)&(rankData));
            break;
        }
        case 0x4D414E4D: {  // MNAM
            if (rankData)
            {
                char* pMaleRank = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pMaleRank), 0);
                reinterpret_cast<::TextString *>(&(rankData->m_kMaleRankName))->FUN_004037f0(pMaleRank, 0);
            }
            break;
        }
        case CHUNK_ID_FNAM_ID: {
            if (rankData)
            {
                char* pFemaleRank = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pFemaleRank), 0);
                reinterpret_cast<::TextString *>(&(rankData->m_kFemaleRankName))->FUN_004037f0(pFemaleRank, 0);
            }
            break;
        }
        case 0x4D414E49: {  // INAM
            if (rankData)
            {
                char* pInsignia = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pInsignia), 0);
                reinterpret_cast<::TESFullName *>((reinterpret_cast<TESTexture1024*>(&rankData->m_kRankTexture)))->SetFullName(pInsignia);
            }
            break;
        }
        case 0x31494D57: {  // WMI1
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            if (formID)
            {
                pReputationData = (TESReputation*)formID;
            }
            break;
        }
        default:
            break;
        }
    } while (file->NextChunk());
    return true;
}

#include <string.h>
struct FactionCompareAccess : TESFaction
{
    bool IsDifferentFrom(TESForm* other);
};

struct RankStringAccess : BSStringT<char>
{
};

// Returns true if this faction differs from other in save data, reputation, or rank presentation lists; false if identical.
// @fnv 0x005fd000
bool FactionCompareAccess::IsDifferentFrom(TESForm* other)
{
    FactionCompareAccess* faction2 = static_cast<FactionCompareAccess*>(dynamic_cast<TESFaction*>(other));
    if (!faction2)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(faction2))
        return true;
    if (memcmp(&data, ((const ::FactionSaveData *)(::FUN_006a9540((char *)(faction2)))), 4))
        return true;
    if (pReputationData != ((::TESReputation *)(::GetField38((char *)(faction2)))))
        return true;

    BSSimpleList<FactionRankPresentation*>* node1 = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    BSSimpleList<FactionRankPresentation*>* node2 = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((faction2))->GetField()));
    while (node1 && !node1->IsEmpty())
    {
        if (!node2 || !((::FactionRankPresentation *)(new ((void *)(node2)) ::Vec3())))
            return true;
        FactionRankPresentation* current2 = ((::FactionRankPresentation *)(new ((void *)(node1)) ::Vec3()));
        FactionRankPresentation* current = ((::FactionRankPresentation *)(new ((void *)(node2)) ::Vec3()));
        if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current2->m_kMaleRankName)))->FUN_004048e0())) ||
            ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current->m_kMaleRankName)))->FUN_004048e0())))
        {
            if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current2->m_kMaleRankName)))->FUN_004048e0())) !=
                ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current->m_kMaleRankName)))->FUN_004048e0())))
                return true;
            else if (reinterpret_cast<::B408A80String *>((void *)&(static_cast<RankStringAccess&>(current2->m_kMaleRankName)))->FUN_00408a80(((const char *)(::FUN_00559450((int *)&(static_cast<RankStringAccess&>(current->m_kMaleRankName))))), false))
                return true;
        }
        if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current2->m_kFemaleRankName)))->FUN_004048e0())) ||
            ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current->m_kFemaleRankName)))->FUN_004048e0())))
        {
            if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current2->m_kFemaleRankName)))->FUN_004048e0())) !=
                ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(static_cast<RankStringAccess&>(current->m_kFemaleRankName)))->FUN_004048e0())))
                return true;
            else if (reinterpret_cast<::B408A80String *>((void *)&(static_cast<RankStringAccess&>(current2->m_kFemaleRankName)))->FUN_00408a80(((const char *)(::FUN_00559450((int *)&(static_cast<RankStringAccess&>(current->m_kFemaleRankName))))),
                                       false))
                return true;
        }
        if (current2->m_kRankTexture.CompareWithBase(&current->m_kRankTexture))
            return true;
        node1 = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<::Callees *>((node1))->FUN_00726070()));
        node2 = ((::BSSimpleList< ::FactionRankPresentation *> *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070()));
    }
    if (node2 && !node2->IsEmpty())
        return true;
    return false;
}
