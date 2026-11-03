// fallout_shared/bgsragdoll.cpp: BGSRagdoll (33 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSSimpleArrayActor.h"
#include "fnv/decl/CompareData.h"
#include "fnv/decl/Data005ecb30.h"
#include "fnv/decl/E5EF9A0Allocator.h"
#include "fnv/decl/EFBC0Array.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005ece50_class.h"
#include "fnv/decl/FUN_005eeda0_this.h"
#include "fnv/decl/FUN_005eee30_class.h"
#include "fnv/decl/FUN_005ef860_class.h"
#include "fnv/decl/FUN_005ef910.h"
#include "fnv/decl/FUN_005efa80_cls.h"
#include "fnv/decl/FUN_0072ba80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00c7a790_Data.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/StandIn_C74FB0.h"
#include "fnv/decl/Target005ed1e0.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_005efc90__FUN_005efc90_class.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005ed000.h"
#include "fnv/symbols_005ee000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01047000.h"
#include "bgsragdoll_types_BGSRagdoll.h"
#include <malloc.h>
#include "fnv/symbols_00472000.h"

template <int N> struct EndianSizeTag
{
};

class TESFileLoadView : public TESFile
{
  public:
};

class TESFormInitFlag
{
  public:
};


class BGSBodyPartData : public TESForm
{
};
class TESActorBase : public TESForm
{
};

// @fnv 0x005edd00
void BGSRagdoll::ResetFormData()
{
    struct InitLocals
    {
        TESObjectREFR* grabName;
        TESObjectREFR* lookName;
        TESObjectREFR* footName;
        unsigned int grabIndex;
        unsigned int lookIndex;
        unsigned int footIndex;
    } locals;

    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter1 = 0.8f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fHeirGain = 0.17f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter3 = 0.05f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fVelGain = 0.6f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter5 = 1.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fSnapGain = 0.1f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter7 = 0.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter8 = 3.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter9 = 0.3f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter10 = 0.3f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter11 = 3.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter12 = 14.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter13 = 18.0f;

    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)))->Clear(true);

    for (locals.footIndex = 0;
         locals.footIndex <
         ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kFootNames)))->GetName()));
         ++locals.footIndex)
    {
        locals.footName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kFootIKData.m_kFootNames)
                ->GetAt(locals.footIndex);
        ::FUN_00401030(locals.footName);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kLegData)))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kFootNames)))->Clear(true);

    m_kFootIKData.m_kRagdollFeedbackData.fOnOffGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fGroundAscendingGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fGroundDescendingGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fFootRaisedGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.m_fAdditionalFeedbackGain1 = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.m_fAdditionalFeedbackGain2 = 0.0f;

    for (locals.lookIndex = 0;
         locals.lookIndex <
         ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kLookNames)))->GetName()));
         ++locals.lookIndex)
    {
        locals.lookName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kLookIKData.m_kLookNames)
                ->GetAt(locals.lookIndex);
        ::FUN_00401030(locals.lookName);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kHeadData)))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kLookNames)))->Clear(true);

    for (locals.grabIndex = 0;
         locals.grabIndex <
         ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabNames)))->GetName()));
         ++locals.grabIndex)
    {
        locals.grabName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kGrabIKData.m_kGrabNames)
                ->GetAt(locals.grabIndex);
        ::FUN_00401030(locals.grabName);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabArmData)))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabNames)))->Clear(true);

    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sFirstRagdollFeedbackIndex = -1;
    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sSecondRagdollFeedbackIndex = -1;
    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sThirdRagdollFeedbackIndex = -1;
    m_kRagdollAnimationData.bEnabled = false;
    m_kFootIKData.bEnabled = false;
    m_kLookIKData.bEnabled = false;
    m_kGrabIKData.bEnabled = false;
    m_kRagdollFeedbackProfile.bEnabled = false;
    m_pActorBase = 0;
    m_pBodyPartDataCur = 0;
}

// @fnv 0x005ed680
BGSRagdoll::BGSRagdoll()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x63))));
    ResetFormData();
}

// @fnv 0x005eea20
void BGSRagdoll::InitItem()
{
    if (GetInitialized())
        return;

    TESForm::ClearData();

    unsigned int formID = reinterpret_cast<unsigned int>(m_pBodyPartDataCur);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pBodyPartDataCur = dynamic_cast<BGSBodyPartData*>(::FUN_004839c0(formID));
        if (!m_pBodyPartDataCur)
            ::FUN_005b5e40();
    }

    formID = reinterpret_cast<unsigned int>(m_pActorBase);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pActorBase = dynamic_cast<TESActorBase*>(::FUN_004839c0(formID));
        if (!m_pActorBase)
            ::FUN_005b5e40();
    }

    SetInitializationState(true);
}


// @fnv 0x005ed760
void* FUN_005ed760(char* pThis)
{
    *pThis = 0;
    ::FUN_005ed790((float *)(void *)(pThis + 4));
    reinterpret_cast<::FUN_005eee30_class *>((pThis + 0x40))->FUN_005eee30();
    return pThis;
}


// Fills the 15-element float/int block at pThis with constant values and returns pThis.
// @fnv 0x005ed790
void* FUN_005ed790(float* pThis)
{
    pThis[0] = ::DAT_010177e8;
    pThis[1] = 0.8f;
    pThis[2] = DAT_010231a8;
    pThis[3] = 0.2f;
    pThis[4] = 0.1f;
    pThis[5] = 0.3f;
    pThis[6] = 0.0f;
    pThis[7] = 50.0f;
    pThis[8] = 50.0f;
    pThis[9] = g_011d8aa4_arg1;
    pThis[10] = g_011d8aa4_arg1;
    pThis[11] = 50.0f;
    pThis[12] = 50.0f;
    ((int*)pThis)[13] = 10000;
    ((int*)pThis)[14] = 30000;
    return pThis;
}

struct FUN_005ed8c0
{
    int pad[7];
    FUN_005ed8c0();
};

struct FUN_005eede0
{
    int pad[4];
    FUN_005eede0();
    ~FUN_005eede0();
};

struct FUN_005eefc0
{
    int pad;
    FUN_005eefc0();
};

struct FUN_005ed850
{
    char b0;
    FUN_005ed8c0 m4;
    FUN_005eede0 m20;
    FUN_005eefc0 m30;
    FUN_005ed850();
};

// Initializes the object by setting b0 to 0 and default-constructing the m4, m20 and m30 members.
// @fnv 0x005ed850
FUN_005ed850::FUN_005ed850() : b0(0)
{}

// Sets the first seven floats of pThis to 0.0f and returns pThis.
// @fnv 0x005ed8c0
float* FUN_005ed8c0(float* pThis)
{
    pThis[0] = 0.0f;
    pThis[1] = 0.0f;
    pThis[2] = 0.0f;
    pThis[3] = 0.0f;
    pThis[4] = 0.0f;
    pThis[5] = 0.0f;
    pThis[6] = 0.0f;
    return pThis;
}

namespace fnv_005ed910 {
struct FUN_005eede0
{
    int pad[4];
    FUN_005eede0();
    ~FUN_005eede0();
};

struct FUN_005ef380
{
    int pad;
    FUN_005ef380();
};

struct FUN_005ed910
{
    bool b;
    FUN_005eede0 m1;
    FUN_005ef380 m2;
    FUN_005ed910();
};

// Initializes b to false and default-constructs the m1 and m2 members.
// @fnv 0x005ed910
FUN_005ed910::FUN_005ed910() : b(false)
{}
}  // namespace fnv_005ed910

namespace fnv_005ed980 {
struct FUN_005eede0
{
    int pad[4];
    FUN_005eede0();
    ~FUN_005eede0();
};

struct FUN_005ef380
{
    int pad;
    FUN_005ef380();
};

struct FUN_005ed980
{
    bool b;
    FUN_005eede0 m1;
    FUN_005ef380 m2;
    FUN_005ed980();
};

// Constructor that initializes b to false and default-constructs the m1 and m2 members.
// @fnv 0x005ed980
FUN_005ed980::FUN_005ed980() : b(false)
{}
}  // namespace fnv_005ed980


struct FUN_005ed9f0
{
    char m_00;
    BSStringT<char> m_04;
    int m_0c;

    FUN_005ed9f0();
};

// Initializes m_00 to 0 and constructs m_0c by calling InitDefaults.
// @fnv 0x005ed9f0
FUN_005ed9f0::FUN_005ed9f0() : m_00(0)
{
    ::InitDefaults((char *)(void *)(&m_0c));
}

// Initializes the object's fields: three shorts to -1, a byte to 0, and floats to 0, 0, 0.1, 0, then returns pThis.
// @fnv 0x005eda60
void* InitDefaults(char* pThis)
{
    *(short*)(pThis + 0x0) = -1;
    *(short*)(pThis + 0x2) = -1;
    *(short*)(pThis + 0x4) = -1;
    *(char*)(pThis + 0x6) = 0;
    *(float*)(pThis + 0x8) = 0.0f;
    *(float*)(pThis + 0xc) = 0.0f;
    *(float*)(pThis + 0x10) = 0.1f;
    *(float*)(pThis + 0x14) = 0.0f;
    return pThis;
}

// Byte-swaps four consecutive 16-bit values starting at thisPtr via BSEndian.
// @fnv 0x005ee510
void SwapEndianFourShorts(unsigned short* thisPtr)
{
    ::FUN_00407a90((short *)(thisPtr));
    ::FUN_00407a90((short *)(unsigned short *)(thisPtr + 1));
    ::FUN_00407a90((short *)(unsigned short *)(thisPtr + 2));
    ::FUN_00407a90((short *)(unsigned short *)(thisPtr + 3));
}


struct GlobalObject_00869f00
{
public:
    void ResetToGlobal();
};
struct ArrSI
{
};
struct Arr
{
    unsigned int* GetAt(int aiIndex);
};
struct _Mem_20a4
{
};
struct FUN_0069ccf0_obj
{
    GrabIK_DATA__GrabIK_Arm_DATA& FUN_0069ccf0(unsigned int auiIndex);
};

struct FUN_005ed360_shell : GrabIK_DATA
{
    void FUN_005ed360(const GrabIK_DATA& arData);
};

// Clears this object's arrays, resizes them to match arData, copies the arm data and duplicated strings, then copies bEnabled.
// @fnv 0x005ed360
void FUN_005ed360_shell::FUN_005ed360(const GrabIK_DATA& arSource)
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x14))))->Clear(true);
    for (unsigned int ui = 0; ui < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 4))))->GetName())); ui++)
        delete (void*)*((Arr*)((char*)this + 4))->GetAt(ui);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 4))))->Clear(true);

    this->m_kGrabArmData.SetSize(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)&arSource + 0x14))))->GetName())), true);
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((_Mem_20a4*)((char*)this + 4))))->FUN_006f2290(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)&arSource + 4))))->GetName())), true);

    for (unsigned int ui = 0; ui < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)&arSource + 0x14))))->GetName())); ui++)
        ((FUN_0069ccf0_obj*)((char*)this + 0x14))->FUN_0069ccf0(ui) =
            ((FUN_0069ccf0_obj*)((char*)&arSource + 0x14))->FUN_0069ccf0(ui);

    for (unsigned int ui = 0; ui < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)&arSource + 4))))->GetName())); ui++)
    {
        unsigned int uiLength = ::FUN_0044a670((const char*)*((Arr*)((char*)&arSource + 4))->GetAt(ui)) + 1;
        char* pString = new char[uiLength];
        ::TaskQueueInterface::CopyStringToBuffer(pString, uiLength, (const char*)*((Arr*)((char*)&arSource + 4))->GetAt(ui));
        *((Arr*)((char*)this + 4))->GetAt(ui) = (unsigned int)pString;
    }

    bEnabled = arSource.bEnabled;
}

struct FUN_00501c90_shell
{
    int CompareString(const BSStringT<char>* apString, bool abIgnoreCase);
};

struct FUN_005ed4f0_shell : RagdollFeedbackProfile
{
    bool FUN_005ed4f0(const RagdollFeedbackProfile& arData);
};

// @fnv 0x005ed4f0
bool FUN_005ed4f0_shell::FUN_005ed4f0(const RagdollFeedbackProfile& arOther)
{
    bool bret = false;
    if (((FUN_00501c90_shell*)((char*)this + 4))
            ->CompareString((const BSStringT<char>*)&arOther.m_kAnimationFileName, true))
        bret = true;
    if (bret || bEnabled != arOther.bEnabled ||
        this->m_kRagdollFeedbackData.m_sFirstRagdollFeedbackIndex != *(const short*)&arOther.m_kRagdollFeedbackData.m_sFirstRagdollFeedbackIndex ||
        this->m_kRagdollFeedbackData.m_sSecondRagdollFeedbackIndex != *(const short*)&arOther.m_kRagdollFeedbackData.m_sSecondRagdollFeedbackIndex ||
        this->m_kRagdollFeedbackData.m_sThirdRagdollFeedbackIndex != *(const short*)&arOther.m_kRagdollFeedbackData.m_sThirdRagdollFeedbackIndex ||
        this->m_kRagdollFeedbackData.ShortFlagFloatRecord != *(const float*)&arOther.m_kRagdollFeedbackData.ShortFlagFloatRecord ||
        this->m_kRagdollFeedbackData.FourFloatParameterBlock != *(const float*)&arOther.m_kRagdollFeedbackData.FourFloatParameterBlock ||
        *(unsigned char*)&this->m_kRagdollFeedbackData.ShortTripleFloatPairRecord != *(const unsigned char*)&arOther.m_kRagdollFeedbackData.ShortTripleFloatPairRecord ||
        this->m_kRagdollFeedbackData.m_fFourthParameter != *(const float*)&arOther.m_kRagdollFeedbackData.m_fFourthParameter ||
        this->m_kRagdollFeedbackData.FourFloatRecord != *(const float*)&arOther.m_kRagdollFeedbackData.FourFloatRecord)
        bret = true;
    return bret;
}

struct BSStringTCharAssign
{
    BSStringT<char>& operator=(const BSStringT<char>& arString);
};

struct FUN_005ed5f0_shell : RagdollFeedbackProfile
{
    void AssignFrom(const RagdollFeedbackProfile& arData);
};

// Copies a string, a flag and several numeric fields from arData into this object.
// @fnv 0x005ed5f0
void FUN_005ed5f0_shell::AssignFrom(const RagdollFeedbackProfile& arSource)
{
    reinterpret_cast<::FUN_00501c10_cls *>((void *)&(const ::BSStringTCharAssign &)(*(BSStringTCharAssign*)((char*)this + 4)))->CallAndReturnSelf((int)&(*(const BSStringT<char>*)&arSource.m_kAnimationFileName));
    bEnabled = arSource.bEnabled;
    *(unsigned short*)&this->m_kRagdollFeedbackData.m_sFirstRagdollFeedbackIndex = *(const unsigned short*)&arSource.m_kRagdollFeedbackData.m_sFirstRagdollFeedbackIndex;
    *(unsigned short*)&this->m_kRagdollFeedbackData.m_sSecondRagdollFeedbackIndex = *(const unsigned short*)&arSource.m_kRagdollFeedbackData.m_sSecondRagdollFeedbackIndex;
    *(unsigned short*)&this->m_kRagdollFeedbackData.m_sThirdRagdollFeedbackIndex = *(const unsigned short*)&arSource.m_kRagdollFeedbackData.m_sThirdRagdollFeedbackIndex;
    this->m_kRagdollFeedbackData.ShortFlagFloatRecord = *(const float*)&arSource.m_kRagdollFeedbackData.ShortFlagFloatRecord;
    this->m_kRagdollFeedbackData.FourFloatParameterBlock = *(const float*)&arSource.m_kRagdollFeedbackData.FourFloatParameterBlock;
    *(unsigned char*)&this->m_kRagdollFeedbackData.ShortTripleFloatPairRecord = *(const unsigned char*)&arSource.m_kRagdollFeedbackData.ShortTripleFloatPairRecord;
    this->m_kRagdollFeedbackData.FourFloatRecord = *(const float*)&arSource.m_kRagdollFeedbackData.FourFloatRecord;
    this->m_kRagdollFeedbackData.m_fFourthParameter = *(const float*)&arSource.m_kRagdollFeedbackData.m_fFourthParameter;
}

namespace fnv_005edfb0 {
struct GlobalObject_00869f00
{
};
struct ArrSI
{
};
struct Arr
{
    unsigned int* GetAt(int aiIndex);
};

struct FUN_005edfb0_shell : BGSRagdoll
{
    void ClearRagdollData();
};

// Frees each element of three arrays at offsets 0xb0, 0xd4 and 0xf8, then clears those arrays and the objects at 0x80, 0xc0, 0xe4 and 0x108.
// @fnv 0x005edfb0
void FUN_005edfb0_shell::ClearRagdollData()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x80))))->Clear(true);

    for (unsigned int ui = 0; ui < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0xb0))))->GetName())); ui++)
        delete (void*)*((Arr*)((char*)this + 0xb0))->GetAt(ui);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0xc0))))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0xb0))))->Clear(true);

    for (unsigned int ui = 0; ui < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0xd4))))->GetName())); ui++)
        delete (void*)*((Arr*)((char*)this + 0xd4))->GetAt(ui);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0xe4))))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0xd4))))->Clear(true);

    for (unsigned int ui = 0; ui < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0xf8))))->GetName())); ui++)
        delete (void*)*((Arr*)((char*)this + 0xf8))->GetAt(ui);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x108))))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0xf8))))->Clear(true);
}
}  // namespace fnv_005edfb0


struct FUN_005ee380_Data
{
    unsigned int uiValue0;
    unsigned int uiValue1;
    unsigned int uiValue2;
    unsigned int uiValue3;
    unsigned int uiValue4;
    unsigned int uiValue5;
    unsigned int uiValue6;
    unsigned int uiValue7;
    unsigned int uiValue8;
    unsigned int uiValue9;
    unsigned int uiValue10;
    unsigned int uiValue11;
    unsigned int uiValue12;
    unsigned int uiValue13;
    unsigned int uiValue14;
    void FUN_005ee380();
};

// Byte-swaps each of the 15 unsigned int fields of this struct via BSEndian.
// @fnv 0x005ee380
void FUN_005ee380_Data::FUN_005ee380()
{
    ::FUN_00401080((int *)(unsigned int *)(&uiValue0));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue1));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue2));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue3));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue4));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue5));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue6));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue7));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue8));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue9));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue10));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue11));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue12));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue13));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue14));
}


struct FUN_005ee580_Data
{
    unsigned short usValue0;
    unsigned short usValue1;
    unsigned short usValue2;
    unsigned char ucValue3;
    unsigned int uiValue3;
    unsigned int uiValue4;
    unsigned int uiValue5;
    unsigned int uiValue6;
    void FUN_005ee580();
};
// Reads a BGSRagdoll record from a TESFile, handling EDID, OBND, MODL/MODT, DATA, XNAM, TNAM, RAFD, RAFB, RAPS and ANAM chunks.
// @fnv 0x005ee640
bool BGSRagdoll::Load(TESFile* file)
{
    if (((unsigned int)(reinterpret_cast<::FUN_00472660_shell *>((reinterpret_cast<TESFileLoadView*>(file)))->FUN_00472660())) != 0x63)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    struct LoadLocals
    {
        char* filename;
        unsigned int i;
        unsigned int count;
        unsigned int body;
        unsigned int preview;
        SaveMetadata saved;
        char* editorID;
        int chunk;
    } locals;
    while ((locals.chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (locals.chunk)
        {
        case 0x44494445: {
            locals.editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(locals.editorID), 512);
            SetEditorID_AtRuntime(locals.editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144: {
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&locals.saved), sizeof(locals.saved));
            if (file->IsEndianConversionRequired())
                ::SwapEndianFourShorts((unsigned short *)&(locals.saved));
            reinterpret_cast<::BSSimpleArrayActor *>((reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)))->FUN_005eee80(locals.saved.m_usFootIndexCount, true);
            m_kFootIKData.m_kLegData.SetSize(locals.saved.m_usLegDataCount, true);
            m_kLookIKData.m_kHeadData.SetSize(locals.saved.m_usHeadDataCount, true);
            m_kGrabIKData.m_kGrabArmData.SetSize(locals.saved.m_usGrabArmDataCount, true);
            m_kRagdollAnimationData.bEnabled = locals.saved.m_bRagdollAnimationEnabled;
            m_kFootIKData.bEnabled = locals.saved.m_bFootIKEnabled;
            m_kLookIKData.bEnabled = locals.saved.m_bLookIKEnabled;
            m_kGrabIKData.bEnabled = locals.saved.m_bGrabIKEnabled;
            m_kRagdollFeedbackProfile.bEnabled = locals.saved.m_bRagdollFeedbackEnabled;
            break;
        }
        case 0x4d414e58: {
            locals.preview = 0;
            file->GetChunkData(&locals.preview);
            m_pActorBase = reinterpret_cast<TESActorBase*>(locals.preview);
            break;
        }
        case 0x4d414e54: {
            locals.body = 0;
            file->GetChunkData(&locals.body);
            m_pBodyPartDataCur = reinterpret_cast<BGSBodyPartData*>(locals.body);
            break;
        }
        case 0x44464152:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kRagdollAnimationData.m_kRagdollFeedbackData),
                               sizeof(m_kRagdollAnimationData.m_kRagdollFeedbackData));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_005ee380_Data *>(&(m_kRagdollAnimationData.m_kRagdollFeedbackData))->FUN_005ee380();
            break;
        case 0x42464152: {
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890(
                (char *)(void *)(&reinterpret_cast<::FUN_005eeda0_this *>((reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)))->GetBufferEntry(0)),
                ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)))->GetName())) *
                    2);
            locals.count =
                ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)))->GetName()));
            if (file->IsEndianConversionRequired())
            {
                for (locals.i = 0; locals.i < locals.count; ++locals.i)
                    ::FUN_00407a90(
                        (short *)(unsigned short *)(&reinterpret_cast<::FUN_005eeda0_this *>((reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)))->GetBufferEntry(locals.i)));
            }
            break;
        }
        case 0x53504152:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kRagdollFeedbackProfile.m_kRagdollFeedbackData),
                               sizeof(m_kRagdollFeedbackProfile.m_kRagdollFeedbackData));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_005ee580_Data *>(&(m_kRagdollFeedbackProfile.m_kRagdollFeedbackData))->FUN_005ee580();
            break;
        case 0x4d414e41: {
            locals.filename = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(locals.filename), 0);
            reinterpret_cast<::TextString *>(&(m_kRagdollFeedbackProfile.m_kAnimationFileName))->FUN_004037f0(locals.filename, 0);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Byte-swaps the three 16-bit and four 32-bit fields of the struct via BSEndian.
// @fnv 0x005ee580
void FUN_005ee580_Data::FUN_005ee580()
{
    ::FUN_00407a90((short *)(unsigned short *)(&usValue0));
    ::FUN_00407a90((short *)(unsigned short *)(&usValue1));
    ::FUN_00407a90((short *)(unsigned short *)(&usValue2));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue3));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue4));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue5));
    ::FUN_00401080((int *)(unsigned int *)(&uiValue6));
}

namespace fnv_005eeb70 {
struct FUN_005092f0_obj
{
};
struct FUN_00c7a790_obj
{
};
struct FUN_005ecb30_shell : FootIK_DATA
{
};
struct FUN_005ecfd0_shell : LookIK_DATA
{
    void FUN_005ecfd0(const LookIK_DATA& arData);
};
struct FUN_005ed360_shell : GrabIK_DATA
{
};
struct FUN_005ed5f0_shell : RagdollFeedbackProfile
{
};
struct FUN_005eeb70_shell : BGSRagdoll
{
    void FUN_005eeb70(TESForm* apCopy);
};

// Casts apCopy to BGSRagdoll, then copies its fields and embedded sub-objects into this ragdoll.
// @fnv 0x005eeb70
void FUN_005eeb70_shell::FUN_005eeb70(TESForm* apCopy)
{
    BGSRagdoll* pcopy = dynamic_cast<BGSRagdoll*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005092f0_obj*)this)))->FUN_004851b0(apCopy);
    m_pActorBase = pcopy->m_pActorBase;
    m_pBodyPartDataCur = pcopy->m_pBodyPartDataCur;
    m_iRagdollType = pcopy->m_iRagdollType;
    reinterpret_cast<::FUN_00c7a790_Data *>((((FUN_00c7a790_obj*)&this->m_kRagdollAnimationData.bEnabled)))->CopyFrom((const ::FUN_00c7a790_Data &)(*(FUN_00c7a790_obj*)&pcopy->m_kRagdollAnimationData.bEnabled));
    reinterpret_cast<::Data005ecb30 *>((((FUN_005ecb30_shell*)((char*)this + 0x90))))->FUN_005ecb30((::Data005ecb30 *)&(pcopy->m_kFootIKData));
    ((FUN_005ecfd0_shell*)((char*)this + 0xd0))->FUN_005ecfd0(pcopy->m_kLookIKData);
    reinterpret_cast<::FUN_005ed360_shell *>((((FUN_005ed360_shell*)((char*)this + 0xf4))))->FUN_005ed360(pcopy->m_kGrabIKData);
    reinterpret_cast<::FUN_005ed5f0_shell *>((((FUN_005ed5f0_shell*)((char*)this + 0x118))))->AssignFrom(pcopy->m_kRagdollFeedbackProfile);
}
}  // namespace fnv_005eeb70

namespace fnv_005eec60 {
struct FUN_00509540_obj
{
};
struct FUN_00c74fb0_obj
{
};
struct FUN_005ec920_shell : FootIK_DATA
{
};
struct FUN_005ece50_shell : LookIK_DATA
{
};
struct FUN_005ed1e0_shell : GrabIK_DATA
{
};
struct FUN_005ed4f0_shell : RagdollFeedbackProfile
{
};
struct FUN_005eec60_shell : BGSRagdoll
{
    bool FUN_005eec60(TESForm* apCompare);
};

// Compares this BGSRagdoll with apCompare field by field, returning true if any compared member differs or the cast fails.
// @fnv 0x005eec60
bool FUN_005eec60_shell::FUN_005eec60(TESForm* apCompare)
{
    BGSRagdoll* pcomp = dynamic_cast<BGSRagdoll*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_00509540_obj*)this)))->FUN_00485270(pcomp))
        return true;
    if (m_iRagdollType != pcomp->m_iRagdollType)
        return true;
    if (reinterpret_cast<::StandIn_C74FB0 *>((((FUN_00c74fb0_obj*)&this->m_kRagdollAnimationData.bEnabled)))->FUN_00c74fb0((const ::StandIn_C74FB0 &)(*(FUN_00c74fb0_obj*)&pcomp->m_kRagdollAnimationData.bEnabled)))
        return true;
    if (reinterpret_cast<::CompareData *>((((FUN_005ec920_shell*)((char*)this + 0x90))))->FUN_005ec920((::CompareData *)&(pcomp->m_kFootIKData)))
        return true;
    if (((bool)(reinterpret_cast<::FUN_005ece50_class *>((((FUN_005ece50_shell*)((char*)this + 0xd0))))->FUN_005ece50((::FUN_005ece50_class *)&(pcomp->m_kLookIKData)))))
        return true;
    if (reinterpret_cast<::Target005ed1e0 *>((((FUN_005ed1e0_shell*)((char*)this + 0xf4))))->FUN_005ed1e0((::Target005ed1e0 *)&(pcomp->m_kGrabIKData)))
        return true;
    if (reinterpret_cast<::FUN_005ed4f0_shell *>((((FUN_005ed4f0_shell*)((char*)this + 0x118))))->FUN_005ed4f0(pcomp->m_kRagdollFeedbackProfile))
        return true;
    if (m_pBodyPartDataCur != pcomp->m_pBodyPartDataCur)
        return true;
    return false;
}
}  // namespace fnv_005eec60

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    void* FUN_005eede0();
};

// Sets the object's vtable pointer to DAT_010472d0, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x005eede0
void* AX::FUN_005eede0()
{
    *(int*)this = (int)&::DAT_010472d0;
    FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_005edac0_shell
{
    void FUN_005edc30();
    void* FUN_005edac0(unsigned int);
};
struct FUN_005eee10
{
    ~FUN_005eee10();
};
struct FUN_005ef3b0
{
    ~FUN_005ef3b0();
};
struct FUN_005edbd0
{
    char _0[4];
    FUN_005eee10 a;
    char _pad[15];
    FUN_005ef3b0 b;
    ~FUN_005edbd0();
};
// @fnv 0x005edbd0
FUN_005edbd0::~FUN_005edbd0()
{}

namespace fnv_005eee10 {

struct GlobalObject_00869f00
{
};

struct FUN_005eee10_shell
{
    int* p;
    void FUN_005eee10();
};

// @fnv 0x005eee10
void FUN_005eee10_shell::FUN_005eee10()
{
    p = &::DAT_010472d0;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_005eee10

namespace fnv_005edb10 {
struct FUN_005eee10
{
    ~FUN_005eee10();
};
struct FUN_005eeff0
{
    ~FUN_005eeff0();
};
struct FUN_005edb10
{
    char _pad0[0x20];
    FUN_005eee10 m20;
    char _pad1[0x0F];
    FUN_005eeff0 m30;
    ~FUN_005edb10();
};
// @fnv 0x005edb10
FUN_005edb10::~FUN_005edb10()
{}
}  // namespace fnv_005edb10

namespace fnv_005edb70 {
struct FUN_005eee10
{
    ~FUN_005eee10();
};
struct FUN_005ef1d0
{
    ~FUN_005ef1d0();
};
struct FUN_005edb70
{
    int _00;
    FUN_005eee10 _04;
    char _pad[15];
    FUN_005ef1d0 _14;
    ~FUN_005edb70();
};
// @fnv 0x005edb70
FUN_005edb70::~FUN_005edb70()
{}
}  // namespace fnv_005edb70

namespace fnv_005ef010 {
struct FUN_005ef010_Item
{
    char b[0x38];
};
struct GlobalObject_00869f00
{
};
struct FUN_0072ba80_shell
{
};
struct FUN_005ef010_Arr
{
    virtual void v0();
    virtual FUN_005ef010_Item* Allocate(unsigned int n);
    FUN_005ef010_Item* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void FUN_005ef010(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef010
void FUN_005ef010_Arr::FUN_005ef010(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_005ef860_class *>(this)->FUN_005ef860(aiNewSize, uiSize);
            uiAllocSize = aiNewSize;
        }
        reinterpret_cast<::FUN_005ef910 *>(this)->ConstructSpawnItems((int)(pBuffer + uiSize), aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((((FUN_0072ba80_shell*)this)))->FUN_0072ba80(pBuffer + aiNewSize, uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            reinterpret_cast<::FUN_005ef860_class *>(this)->FUN_005ef860(aiNewSize, aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        reinterpret_cast<::FUN_005ef910 *>(this)->ConstructSpawnItems((int)(pBuffer + uiSize), aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef010

namespace fnv_005ef1f0 {
struct FUN_005ef1f0_Item
{
    char b[0x28];
};
struct GlobalObject_00869f00
{
};
struct FUN_0072ba80_shell
{
};
struct FUN_005ef1f0_Arr
{
    virtual void v0();
    virtual FUN_005ef1f0_Item* Allocate(unsigned int n);
    FUN_005ef1f0_Item* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void FUN_005ef1f0(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef1f0
void FUN_005ef1f0_Arr::FUN_005ef1f0(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_005efa80_cls *>(this)->FUN_005efa80((void *)(aiNewSize), uiSize);
            uiAllocSize = aiNewSize;
        }
        reinterpret_cast<::E5EF9A0Allocator *>(this)->ConstructEntries((::E5EF9A0Entry *)(::fnv_005ef1f0::FUN_005ef1f0_Item *)(pBuffer + uiSize), aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((((FUN_0072ba80_shell*)this)))->FUN_0072ba80(pBuffer + aiNewSize, uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            reinterpret_cast<::FUN_005efa80_cls *>(this)->FUN_005efa80((void *)(aiNewSize), aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        reinterpret_cast<::E5EF9A0Allocator *>(this)->ConstructEntries((::E5EF9A0Entry *)(::fnv_005ef1f0::FUN_005ef1f0_Item *)(pBuffer + uiSize), aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef1f0

namespace fnv_005ef3d0 {
struct GlobalObject_00869f00
{
};
struct FUN_0072ba80_shell
{
};
struct GrabIK_Arm_DATA_005ef3d0
{
    unsigned short data[3];
};
struct BSSimpleArray_005ef3d0
{
    virtual void Destroy(bool);
    virtual GrabIK_Arm_DATA_005ef3d0* Allocate(unsigned int);
    GrabIK_Arm_DATA_005ef3d0* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void FUN_005ef3d0(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef3d0
void BSSimpleArray_005ef3d0::FUN_005ef3d0(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            reinterpret_cast<::fnv_005efc90::FUN_005efc90_class *>(this)->FUN_005efc90((void *)(aiNewSize), (void *)(uiSize));
            uiAllocSize = aiNewSize;
        }
        reinterpret_cast<::EFBC0Array *>(this)->ConstructItems((::EFBC0Item *)(::fnv_005ef3d0::GrabIK_Arm_DATA_005ef3d0 *)(pBuffer + uiSize), aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((((FUN_0072ba80_shell*)this)))->FUN_0072ba80(pBuffer + aiNewSize, uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            reinterpret_cast<::fnv_005efc90::FUN_005efc90_class *>(this)->FUN_005efc90((void *)(aiNewSize), (void *)(aiNewSize));
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        reinterpret_cast<::EFBC0Array *>(this)->ConstructItems((::EFBC0Item *)(::fnv_005ef3d0::GrabIK_Arm_DATA_005ef3d0 *)(pBuffer + uiSize), aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef3d0

namespace fnv_005ee110 {
struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct FUN_004891d0_obj
{
};

struct ArrSI
{
};

struct DA00694f80
{
};

struct FUN_005ee110_String
{
    operator unsigned int() const;
};

struct FUN_005ee110_shell
{
    void FUN_005ee110();
};


// @fnv 0x005ee110
void FUN_005ee110_shell::FUN_005ee110()
{
    SaveMetadata saveData;

    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    reinterpret_cast<::FUN_004891d0_cls *>((reinterpret_cast<FUN_004891d0_obj*>(reinterpret_cast<unsigned char*>(this) + 0x18)))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));

    ::FUN_00485910(0x5245564e, 1);

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x00) =
        ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x80)))->GetName()));

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x02) =
        ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0xc0)))->GetName()));

    saveData.m_usHeadDataCount =
        ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0xe4)))->GetName()));

    saveData.m_usGrabArmDataCount =
        ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x108)))->GetName()));

    *reinterpret_cast<unsigned char*>(&saveData.m_bRagdollAnimationEnabled) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x40);

    *reinterpret_cast<unsigned char*>(&saveData.m_bFootIKEnabled) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x90);

    *reinterpret_cast<unsigned char*>(&saveData.m_bLookIKEnabled) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0xd0);

    *reinterpret_cast<unsigned char*>(&saveData.m_bGrabIKEnabled) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0xf4);

    *reinterpret_cast<unsigned char*>(&saveData.m_bRagdollFeedbackEnabled) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x118);

    if (((bool)(::FUN_00401500())))
        ::SwapEndianFourShorts(reinterpret_cast<unsigned short*>(&saveData));

    ::AppendChunk(0x41544144, &saveData, 0x0e);

    if (((bool)(::FUN_00401500())))
        ::SwapEndianFourShorts(reinterpret_cast<unsigned short*>(&saveData));

    if (*reinterpret_cast<TESActorBase**>(reinterpret_cast<unsigned char*>(this) + 0x144))
    {
        unsigned int itempint;
        itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<TESActorBase**>(reinterpret_cast<unsigned char*>(this) + 0x144))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e58, itempint);
    }

    if (*reinterpret_cast<BGSBodyPartData**>(reinterpret_cast<unsigned char*>(this) + 0x140))
    {
        unsigned int itempint;
        itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<BGSBodyPartData**>(reinterpret_cast<unsigned char*>(this) + 0x140))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e54, itempint);
    }

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005ee380_Data *>((reinterpret_cast<RagdollFeedbackData__RagdollFeedbackSystemData*>(reinterpret_cast<unsigned char*>(this) + 0x44)))->FUN_005ee380();

    ::AppendChunk(0x44464152, reinterpret_cast<unsigned char*>(this) + 0x44, 0x3c);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005ee380_Data *>((reinterpret_cast<RagdollFeedbackData__RagdollFeedbackSystemData*>(reinterpret_cast<unsigned char*>(this) + 0x44)))->FUN_005ee380();

    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x80)))->GetName())) > 0)
    {
        ::FUN_00485730(reinterpret_cast<void*>(0x42464152),
                     &reinterpret_cast<::FUN_005eeda0_this *>((reinterpret_cast<DA00694f80*>(reinterpret_cast<unsigned char*>(this) + 0x80)))->GetBufferEntry(0),
                     reinterpret_cast<void*>(
                         ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x80)))->GetName()))));
    }

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005ee580_Data *>((reinterpret_cast<PoseMatching_DATA__PoseMatching_System_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x124)))->FUN_005ee580();

    ::AppendChunk(0x53504152, reinterpret_cast<unsigned char*>(this) + 0x124, 0x18);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005ee580_Data *>((reinterpret_cast<PoseMatching_DATA__PoseMatching_System_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x124)))->FUN_005ee580();

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<FUN_005ee110_String*>(reinterpret_cast<unsigned char*>(this) + 0x11c)))->FUN_004048e0())))
    {
        ::FUN_004856f0((void *)(0x4d414e41),
                     reinterpret_cast<void*>(
                         reinterpret_cast<FUN_005ee110_String*>(reinterpret_cast<unsigned char*>(this) + 0x11c)
                             ->
                             operator unsigned int()),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<FUN_005ee110_String*>(reinterpret_cast<unsigned char*>(this) + 0x11c)))->FUN_004048e0())) +
                         1));
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}
}  // namespace fnv_005ee110

// RunInner: a thin thiscall wrapper that forwards to a method of the
// sub-object living at offset 0x40 of the owner object.
struct Inner
{
};

struct FUN_005edaf0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    Inner m_40;
    void RunInner();
};

// @fnv 0x005edaf0
void FUN_005edaf0_cls::RunInner()
{
    reinterpret_cast<::GlobalObject_00869f00 *>(&(m_40))->ResetToGlobal();
}

class ObjPrimary
{
  public:
    virtual void v00();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    ~ObjPrimary();
};

class ObjSecondary
{
  public:
    virtual void v00();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    ~ObjSecondary();
};

class ObjMemberA
{
  public:
    ObjMemberA();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    ~ObjMemberA();
};

class ObjMemberB
{
  public:
    ObjMemberB();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    ~ObjMemberB();
};

class ObjMemberC
{
  public:
    ObjMemberC();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    ~ObjMemberC();
};

class ObjMemberD
{
  public:
    ObjMemberD();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    ~ObjMemberD();
};

class ObjMemberE
{
  public:
    ObjMemberE();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    ~ObjMemberE();
};

class FUN_005edc30 : public ObjPrimary, public ObjSecondary
{
  public:
    ObjMemberA m_40;
    ObjMemberB m_90;
    ObjMemberC m_d0;
    ObjMemberD m_f4;
    ObjMemberE m_118;
    virtual ~FUN_005edc30();
};
// Calls FUN_005edc30 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005edac0
void* FUN_005edac0_shell::FUN_005edac0(unsigned int flags)
{
    reinterpret_cast<::FUN_005edc30 *>((this))->FUN_005edc30::~FUN_005edc30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x005edc30
FUN_005edc30::~FUN_005edc30()
{
    reinterpret_cast<::fnv_005edfb0::FUN_005edfb0_shell *>(this)->ClearRagdollData();
}

struct StandIn_C74FB0_o2
{
    unsigned char flag00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    float f2C;
    float f30;
    float f34;
    int i38;
    int i3C;
    int unk40;
    unsigned short* data44;
    unsigned int count48;

    bool FUN_00c74fb0(const StandIn_C74FB0_o2& other) const;
};

// @fnv 0x00c74fb0
bool StandIn_C74FB0_o2::FUN_00c74fb0(const StandIn_C74FB0_o2& other) const
{
    bool diff = false;
    if (count48 != other.count48)
        goto fail;
    {
        unsigned int i = 0;
        while (i < count48)
        {
            if (diff)
                goto fail;
            diff = data44[i] != other.data44[i];
            i++;
        }
    }
    if (diff)
        goto fail;
    if (flag00 != other.flag00)
        goto fail;
    if (f04 != other.f04)
        goto fail;
    if (f08 != other.f08)
        goto fail;
    if (f0C != other.f0C)
        goto fail;
    if (f10 != other.f10)
        goto fail;
    if (f14 != other.f14)
        goto fail;
    if (f18 != other.f18)
        goto fail;
    if (f1C != other.f1C)
        goto fail;
    if (f20 != other.f20)
        goto fail;
    if (f24 != other.f24)
        goto fail;
    if (f28 != other.f28)
        goto fail;
    if (f2C != other.f2C)
        goto fail;
    if (f30 != other.f30)
        goto fail;
    if (i38 != other.i38)
        goto fail;
    if (i3C != other.i3C)
        goto fail;
    if (f34 != other.f34)
        goto fail;
    goto done;
fail:
    diff = true;
done:
    return diff;
}

// FUN_005effb0 : MSVC this-adjusting thunk  (sub ecx, 0x18 ; jmp <impl>)
struct A1_005effb0
{
    A1_005effb0();
    virtual void FUN_005effb0();
    char pad[0x14];
};

struct A2_005effb0
{
    A2_005effb0();
    virtual void FUN_005effb0();
};

struct Own_005effb0 : A1_005effb0, A2_005effb0
{
    Own_005effb0();
    virtual void key_fn();
// @fnv 0x005effb0
    void FUN_005effb0();
};

Own_005effb0::Own_005effb0()
{}

void Own_005effb0::key_fn()
{}
Own_005effb0* make_005effb0()
{
    static Own_005effb0 o;
    return &o;
}

#include "generated/data/fallout_shared/bgsragdoll.inc"
