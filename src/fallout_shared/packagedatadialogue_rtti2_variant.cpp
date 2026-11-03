// src/fallout_shared/packagedatadialogue_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESDialoguePackageData, TESPackageData). The skeleton of src/fallout_shared/packagedatadialogue.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.


#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0067ad20_Class.h"
#include "fnv/decl/FUN_0067fb60_shell.h"
#include "fnv/decl/FUN_0067fbe0_cls.h"
#include "fnv/decl/FUN_0067fc50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_01068000.h"
#include "packagedatadialogue_decls_rtti2_packagedatadialogue.h"
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0067b1e0(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x0067b1e0
void* DelStandIn::FUN_0067b1e0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
struct FUN_00670b30
{
    void* __vecDelDtor(unsigned int);
};
struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    int field4;
    int field8;
};
struct FUN_0067b280_cls : FUN_0067ad70_cls
{
    FUN_00670b30* data;
    virtual ~FUN_0067b280_cls();
};
class BGSLoadFormBuffer;
struct FUN_0067fc50_impl
{
};
struct FUN_0067b920_host
{
    int pad0;
    int pad4;
    int pad8;
    FUN_0067fc50_impl* padC;
    void FUN_0067b920(BGSLoadFormBuffer*);
};
struct LocationDescriptor
{
};
struct FUN_0067b100_Class
{
    float m_fFirstFloat;
    unsigned int m_uiTopicFormID;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;

    void FUN_0067b100();
};
typedef FUN_0067b100_Class FunctionObject;
struct FUN_0067b630_cls
{
    unsigned int pad0;
    float m_fFirstFloat;
    TESTopic* pMenuTopicEntry;
    LocationDescriptor* m_pTargetLocation;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;

    void SaveTopicData();
};
struct FUNObj
{
};
struct SaveFormIDHelper
{
};
struct BGSSaveFormBuffer : SaveFormIDHelper
{
};
struct TESPackageData
{
    virtual ~TESPackageData();  // the original class is polymorphic (rtti_variants.py)
    int pad;
};
struct FUN_0067b6f0_cls : TESPackageData
{
    int field4;
    TESTopic* pMenuTopicEntry;
    FUNObj* m_pTargetLocation;
    bool field10;
    bool field11;
    bool field12;
    int field14;
    bool field18;
    int field1c;

    void SavePackageData(BGSSaveFormBuffer*);
};
struct PairOfBytes
{
    unsigned char first;
    unsigned char second;
};
struct ConstructorHost
{
    void* vtable;
    float value04;
    unsigned int value08;
    unsigned int value0C;
    unsigned char value10;
    unsigned char value11;
    float value14;
    unsigned char value18;
    unsigned int value1C;

    ConstructorHost* Construct(float initial, unsigned int object, PairOfBytes flags, float scale,
                               unsigned char enabled, unsigned int reference);
};
void* __cdecl operator new(unsigned int);
class TESForm;
class BGSLoadFormBuffer
{
  public:
};
struct TESEatPackageData_
{
    int field0;
    int field4;

};
struct B0067f030 : TESEatPackageData_
{
    int field8;

    B0067f030();
};
struct FUN_0067b7d0_shell
{
    int field0;
    int field4;
    TESTopic* pMenuTopicEntry;
    LocationDescriptor* m_pTargetLocation;
    unsigned char field10;
    unsigned char field11;
    unsigned char field12;
    unsigned int field14;
    unsigned char field18;
    unsigned int field1c;

    void FUN_0067b7d0(BGSLoadFormBuffer* apLoadGameBuffer);
};

struct DialogueTargetComparison : LocationDescriptor
{
};

struct DialoguePackageComparison : TESDialoguePackageData
{
    DialogueTargetComparison* m_pTargetLocation;
    unsigned char m_bFirstFlag;
    unsigned char m_bFollowingFlag;
    float m_fFloatValue;
    unsigned char m_bThirdFlag;
    int m_iTrailingValue;

    bool FUN_0067b470(void*);
};

// @fnv 0x0067b470
bool DialoguePackageComparison::FUN_0067b470(void* object)
{
    DialoguePackageComparison* other = reinterpret_cast<DialoguePackageComparison*>(
        dynamic_cast< ::TESDialoguePackageData*>(static_cast< ::TESPackageData*>(object)));

    if (other == 0)
        return true;

    if (m_fFirstFloat != other->m_fFirstFloat)
        return true;

    if (m_fFloatValue != other->m_fFloatValue)
        return true;

    if (m_bFirstFlag != other->m_bFirstFlag)
        return true;

    if (pMenuTopicEntry != other->pMenuTopicEntry)
        return true;

    if (m_pTargetLocation != 0)
    {
        if (reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((m_pTargetLocation))->IsDifferentFrom((::LocationDescriptor *)(other->m_pTargetLocation)))
            return true;
    }
    else if (other->m_pTargetLocation != 0)
    {
        return true;
    }

    if (m_bFollowingFlag != other->m_bFollowingFlag)
        return true;

    if (m_bThirdFlag != other->m_bThirdFlag)
        return true;

    if (m_iTrailingValue != other->m_iTrailingValue)
        return true;

    return false;
}
