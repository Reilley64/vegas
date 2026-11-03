// fallout_shared/packagedatadialogue.cpp: TESDialoguePackageData, DelStandIn, ConstructorHost (8 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/BGSCameraPath.h"
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
#include "packagedatadialogue_decls.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "packagedatadialogue_decls_rtti2_packagedatadialogue.h"
#include <cstring>
#include "packagedatadialogue_decls_rtti_variant.h"
#include "packagedatadialogue_decls_rtti_variant_decl_packagedatadialogue_rtti_variant.h"
// Resolves the stored topic ID to a TESTopic via the form's file and warns if the topic is missing.
// @fnv 0x0067b590
void TESDialoguePackageData::InitItem(TESForm* form)
{
    std::uintptr_t topicID = (std::uintptr_t)pMenuTopicEntry;
    ::ResolveFormID((unsigned int *)&(topicID), form->GetFile(-1));
    pMenuTopicEntry = dynamic_cast<TESTopic*>(::FUN_004839c0(topicID));
    if (!pMenuTopicEntry && topicID)
        ::FUN_005b5e40();
}

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

// Destructor that deletes the owned data object via its vector deleting destructor.
// @fnv 0x0067b280
FUN_0067b280_cls::~FUN_0067b280_cls()
{
    FUN_00670b30* b = data;
    FUN_00670b30* a = b;
    a ? a->__vecDelDtor(1) : 0;
}

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
// If padC is non-null, forwards apLoadGameBuffer to padC's ResolveObject.
// @fnv 0x0067b920
void FUN_0067b920_host::FUN_0067b920(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (padC != 0)
        reinterpret_cast<::FUN_0067fc50_shell *>((padC))->ResolveObject((int)(apLoadGameBuffer));
}

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

// @fnv 0x0067b630
void FUN_0067b630_cls::SaveTopicData()
{
    FunctionObject saveData;

    ::FUN_00403d30(&saveData, 0, 0x18);
    saveData.m_bFirstFlag = m_bFirstFlag;
    saveData.m_fFirstFloat = m_fFirstFloat;
    saveData.m_bFollowingFlag = m_bFollowingFlag;
    saveData.m_bThirdFlag = m_bThirdFlag;
    saveData.m_iTrailingValue = m_iTrailingValue;
    saveData.m_fFloatValue = m_fFloatValue;

    if (pMenuTopicEntry)
        saveData.m_uiTopicFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pMenuTopicEntry))->FUN_0084e3a0()));

    if (((bool)(::FUN_00401500())))
        saveData.FUN_0067b100();

    ::AppendChunk(0x44444b50, &saveData, 0x18);

    if (((bool)(::FUN_00401500())))
        saveData.FUN_0067b100();

    if (m_pTargetLocation)
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((m_pTargetLocation))->FUN_0067f6c0(0x32444c50);
}

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

// Serializes the package fields to the save buffer, then saves the topic and, if a location object exists, saves it too.
// @fnv 0x0067b6f0
void FUN_0067b6f0_cls::SavePackageData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&field4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&field10, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&field11, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&field12, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&field14, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&field18, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&field1c, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pMenuTopicEntry), 0);

    bool bhasLocation = m_pTargetLocation;
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&bhasLocation, 1, 0);
    if (bhasLocation)
        reinterpret_cast<::FUN_0067fb60_shell *>((m_pTargetLocation))->FUN_0067fb60((::LocationInputStream *)(apSaveGameBuffer));
}

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

// Calls FUN_0067ad20, sets the vtable, then stores the six arguments into the object's fields and returns this.
// @fnv 0x0067b210
ConstructorHost* ConstructorHost::Construct(float initial, unsigned int object, PairOfBytes flags, float scale,
                                            unsigned char enabled, unsigned int reference)
{
    new ((void *)this) ::FUN_0067ad20_Class();
    vtable = &UNK_010688ac;
    value04 = initial;
    value10 = flags.first;
    value08 = object;
    value14 = scale;
    value0C = 0;
    value11 = flags.second;
    value18 = enabled;
    value1C = reference;
    return this;
}


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

// Reads fields from apLoadGameBuffer, resolves pMenuTopicEntry by form ID, and optionally allocates and reads m_pTargetLocation.
// @fnv 0x0067b7d0
void FUN_0067b7d0_shell::FUN_0067b7d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field10), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field11), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field12), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field14), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field18), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field1c), 4);

    pMenuTopicEntry = dynamic_cast<TESTopic*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0()));

    bool bhasLocation = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bhasLocation), 1);
    if (bhasLocation)
    {
        m_pTargetLocation = (LocationDescriptor*)new B0067f030;
        reinterpret_cast<::FUN_0067fbe0_cls *>((((TESEatPackageData_*)m_pTargetLocation)))->FUN_0067fbe0((::PackageLoadStream *)(apLoadGameBuffer));
    }
}

struct TESPackageData_rtti2
{
    virtual ~TESPackageData_rtti2();  // the original class is polymorphic (rtti_variants.py)
    int pad;
};

struct FUN_0067b6f0_cls_rtti2 : TESPackageData_rtti2
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
        dynamic_cast< ::TESDialoguePackageData*>(static_cast< ::TESPackageData_rtti2*>(object)));

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

void __cdecl Deallocate(void*);

namespace p07 {
struct DtorStandIn_rtti
{
    void FUN_0083dec0();
};
struct DelStandIn_rtti
{
    void* FUN_0067b1e0(unsigned int flags);
};
// @fnv 0x0067b1e0
void* DelStandIn_rtti::FUN_0067b1e0(unsigned int flags)
{
    ((DtorStandIn_rtti*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_0067fc50_impl_rtti
{
    void ResolveObject(BGSLoadFormBuffer*);
};

struct FUN_0067b920_host_rtti
{
    int pad0;
    int pad4;
    int pad8;
    FUN_0067fc50_impl_rtti* padC;
    void FUN_0067b920(BGSLoadFormBuffer*);
};

struct LocationDescriptor_rtti
{
    void Save(int);
};

bool _FUN_00401500();

void _FUN_00485990(int, void*, unsigned int);

struct FUN_0067b630_cls_rtti
{
    unsigned int pad0;
    float m_fFirstFloat;
    TESTopic* pMenuTopicEntry;
    LocationDescriptor_rtti* m_pTargetLocation;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;

    void SaveTopicData();
};

struct FUNObj_rtti
{
    void FUN_0067fb60(void*);
};

struct SaveFormIDHelper_rtti
{
    void SerializeFormData(void*, int);
};

struct BGSSaveFormBuffer_rtti : SaveFormIDHelper_rtti
{
    void SaveData(void*, int, int);
};

struct TESPackageData_rtti
{
    virtual ~TESPackageData_rtti();  // the original class is polymorphic (rtti_variants.py)
    int pad;
};

struct FUN_0067b6f0_cls_rtti : TESPackageData_rtti
{
    int field4;
    TESTopic* pMenuTopicEntry;
    FUNObj_rtti* m_pTargetLocation;
    bool field10;
    bool field11;
    bool field12;
    int field14;
    bool field18;
    int field1c;

    void SavePackageData(BGSSaveFormBuffer_rtti*);
};

extern void* UNK_010688ac;

struct ConstructorHost_rtti
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

    void FUN_0067ad20();
    ConstructorHost_rtti* Construct(float initial, unsigned int object, PairOfBytes flags, float scale,
                               unsigned char enabled, unsigned int reference);
};

struct LocationDescriptor_rtti_decl
{
public:
    void Copy(::LocationDescriptor_rtti_decl *, bool);
};

struct FUN_0067b630_cls_rtti_decl
{
    unsigned int pad0;
    float m_fFirstFloat;
    TESTopic* pMenuTopicEntry;
    LocationDescriptor_rtti_decl* m_pTargetLocation;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;

    void SaveTopicData();
};

struct TESPackageData_rtti_decl
{
    virtual ~TESPackageData_rtti_decl();  // the original class is polymorphic (rtti_variants.py)
    int pad;
};

struct FUN_0067b6f0_cls_rtti_decl : TESPackageData_rtti_decl
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
    void FUN_0067b310(TESPackageData_rtti_decl*);
};

// @fnv 0x0067b310
void DialogueData544::FUN_0067b310(TESPackageData_rtti_decl* input)
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
            reinterpret_cast<::LocationDescriptor_rtti_decl *>((m_pTargetLocation))->Copy((::LocationDescriptor_rtti_decl *)(source->m_pTargetLocation), 0);
        }
        pMenuTopicEntry = source->pMenuTopicEntry;
        m_bFollowingFlag = source->m_bFollowingFlag;
        m_bThirdFlag = source->m_bThirdFlag;
        m_iTrailingValue = source->m_iTrailingValue;
    }
}
