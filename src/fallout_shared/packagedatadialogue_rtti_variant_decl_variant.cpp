
// src/fallout_shared/packagedatadialogue_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0067b310: the skeleton of src/fallout_shared/packagedatadialogue_rtti_variant.cpp
// with declarations corrected to what the original code does (packagedatadialogue_decls_rtti_variant.h: class TESDialoguePackageData { -> struct TargetLocation; class TESDialoguePackageDat; packagedatadialogue_decls_rtti_variant.h: TESTopic* pMenuTopicEntry; void InitItem(TESForm*); -> TESTopic* pMenuTopicEntry; TargetLocation* pTargetL). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/packagedatadialogue_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
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
#include "fnv/decl/FUN_0067fc50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
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
#include "packagedatadialogue_decls_rtti_variant_decl_packagedatadialogue_rtti_variant.h"
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0067b1e0(unsigned int flags);
};
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
public:
    void Copy(::LocationDescriptor *, bool);
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

struct TargetLocation
{
    unsigned char type;
    unsigned char unk01, unk02, unk03;
    unsigned int data;
    float radius;
    TargetLocation();
    ~TargetLocation();
};
struct DialogueData544 : TESDialoguePackageData
{
    void FUN_0067b310(TESPackageData*);
};
// @fnv 0x0067b310
void DialogueData544::FUN_0067b310(TESPackageData* input)
{
    TESDialoguePackageData* source = dynamic_cast<TESDialoguePackageData*>(input);
    if (source)
    {
        m_fFirstFloat = source->m_fFirstFloat;
        m_fFloatValue = source->m_fFloatValue;
        m_bFirstFlag = source->m_bFirstFlag;
        if (m_pTargetLocation)
        {
            delete m_pTargetLocation;
            m_pTargetLocation = 0;
        }
        if (source->m_pTargetLocation)
        {
            m_pTargetLocation = new TargetLocation;
            reinterpret_cast<::LocationDescriptor *>((m_pTargetLocation))->Copy((::LocationDescriptor *)(source->m_pTargetLocation), 0);
        }
        pMenuTopicEntry = source->pMenuTopicEntry;
        m_bFollowingFlag = source->m_bFollowingFlag;
        m_bThirdFlag = source->m_bThirdFlag;
        m_iTrailingValue = source->m_iTrailingValue;
    }
}
