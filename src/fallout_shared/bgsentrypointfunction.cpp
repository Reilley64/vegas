// The class header lives in include/; a plain "BGSEntryPointFunction.h" resolves to this folder's
// bgsentrypointfunction.h (case-insensitive lookup), which declares a different class.
#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSFaceGenKeyframe.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005abe00.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005e6600.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/Scr.h"
#include "fnv/decl/ScriptCompareOwner.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "../../include/BGSEntryPointFunction.h"

// @fnv 0x005e5b30
unsigned char BGSEntryPointFunction::GetArgumentCount(ENTRY_POINT_FUNCTION_TYPE type)
{
    return static_cast<unsigned char>(ms_auiArgumentCountsByType[type]);
}

// Looks up the handler for the given entry point function in the table and calls it with the reference, type, argument count, arguments and data.
// @fnv 0x005e5b40
void BGSEntryPointFunction::ApplyFunction(ENTRY_POINT_FUNCTION function, TESObjectREFR* reference,
                                          ENTRY_POINT_FUNCTION_TYPE type, unsigned char argumentCount, void** arguments,
                                          void* data)
{
    if (ms_kEntryPointFunctionTable[function].pFunction)
    {
        ms_kEntryPointFunctionTable[function].pFunction(reference, type, argumentCount, arguments, data);
    }
}

class EntryPointValueSource
{
  public:
};



// Validates arguments, then adds a random float between the source's two values to the first value in apapValues.
// @fnv 0x005e5d80
void FUN_005e5d80(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                  EntryPointValueSource* apSource)
{
    if (!::FUN_005e5b80(0, 2, (::TESObjectREFR *)(aiArg1), aiArg2, aucArgCount, (void **)(apapValues), apSource))
        return;

    float* pfValue = *apapValues;
    EntryPointValueSource* pSource = apSource;

    *pfValue += RandomFloat(reinterpret_cast<::TimeoutTimer *>((pSource))->FUN_006b9130(), reinterpret_cast<::BSFaceGenKeyframe *>((pSource))->GetTime());
}

class E5DF0Counter
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual int GetCount(unsigned int uiIndex);
};

class E5DF0Actor
{
  public:
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    E5DF0Counter m_kCounter;
};

class E5DF0Modifier
{
  public:
};


// Calls FUN_005e5b80 to validate the modifier, then adds the product of the counter value and FUN_006b9130 to the result.
// @fnv 0x005e5df0
void FUN_005e5df0(E5DF0Actor* pkActor, void* pvTarget, bool bFlag, float** ppfResult, E5DF0Modifier* pkModifier)
{
    if (!::FUN_005e5b80(0, 2, (::TESObjectREFR *)(pkActor), (int)(pvTarget), bFlag, (void **)(ppfResult), pkModifier))
        return;

    float* pfOut3 = *ppfResult;
    E5DF0Modifier* pkMod = pkModifier;
    E5DF0Actor* pkSource = pkActor;
    float fSecondFunctionValue = reinterpret_cast<::TimeoutTimer *>((pkMod))->FUN_006b9130();
    unsigned int uiIndex3 = (unsigned int)reinterpret_cast<::BSFaceGenKeyframe *>((pkMod))->GetTime();
    *pfOut3 += pkSource->m_kCounter.GetCount(uiIndex3) * fSecondFunctionValue;
}


struct StringOwner
{
    void* m_pVtbl;
    char* m_pText;
};

struct FUN_005e6c60_shell
{
    void FUN_005e6c60(const char* text);
};

// Frees the current m_pText buffer, then allocates a new one and copies text into it if text is non-null.
// @fnv 0x005e6c60
void FUN_005e6c60_shell::FUN_005e6c60(const char* text)
{
    delete[] ((StringOwner*)this)->m_pText;
    ((StringOwner*)this)->m_pText = 0;

    if (text)
    {
        ((StringOwner*)this)->m_pText = new char[::FUN_0044a670(text) + 1];
        ::FUN_004046f0(((StringOwner*)this)->m_pText, text);
    }
}

class EntryPointSingleValueSource
{
  public:
};
// Calls FUN_005e5b80 to validate arguments, then writes the result of a5->FUN_006b9130() into the float pointed to by *a4.
// @fnv 0x005e5c70
void __cdecl FUN_005e5c70(void* apArg1, void* apArg2, unsigned char a3, float** ppValue,
                          EntryPointSingleValueSource* apSource)
{
    EntryPointSingleValueSource* pSource;
    if (!::FUN_005e5b80(0, 1, (::TESObjectREFR *)(apArg1), (int)(apArg2), a3, (void **)(ppValue), apSource))
        return;
    {
        float* pValue;
        pValue = *ppValue;
        pSource = apSource;
        *pValue = reinterpret_cast<::TimeoutTimer *>((pSource))->FUN_006b9130();
    }
}

namespace std {
float __cdecl abs(float);
}


// Validates entry function arguments, then sets the first value in apapValues to its absolute value.
// @fnv 0x005e5ea0
void __cdecl FUN_005e5ea0(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                          EntryPointValueSource* apSource)
{
    float* pfValue;
    if (!::FUN_005e5b80(0, 0, (::TESObjectREFR *)(aiArg1), aiArg2, aucArgCount, (void **)(apapValues), apSource))
        return;
    pfValue = *apapValues;
    *pfValue = std::abs(*pfValue);
}

class EntryPointValueSource;


// @fnv 0x005e5ef0
void FUN_005e5ef0(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                  EntryPointValueSource* apSource)
{
    if (!::FUN_005e5b80(0, 0, (::TESObjectREFR *)(aiArg1), aiArg2, aucArgCount, (void **)(apapValues), apSource))
        return;

    float* pfValue = *apapValues;
    *pfValue = -std::abs(*pfValue);
}

struct Dummy
{
    void* FUN_005e6440(unsigned int);
};
struct FUN_005e6490_shell
{
    void FUN_005e6490();
};

struct FUN_005e6420
{
    int m0;
    FUN_005e6420();
};
extern int DAT_01046300;
struct FUN_005e64b0 : FUN_005e6420
{
    float f4;
    float f8;
    FUN_005e64b0();
};
// @fnv 0x005e64b0
FUN_005e64b0::FUN_005e64b0()
{
    m0 = (int)&DAT_01046300;
    f4 = 0.0f;
    f8 = 0.0f;
}

struct FUN_005e63f0
{
    FUN_005e63f0();
    ~FUN_005e63f0();
    unsigned int vtable;
    float value;
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct OneValueDuplicateEntry
{
    unsigned int vtable;
    float value;
    FUN_005e63f0* FUN_005e6670();
};
// Allocates a new FUN_005e63f0, copies the value field into it, and returns the pointer.
// @fnv 0x005e6670
FUN_005e63f0* OneValueDuplicateEntry::FUN_005e6670()
{
    FUN_005e63f0* pduplicate = new FUN_005e63f0;
    pduplicate->value = value;
    return pduplicate;
}

class BGSEntryPointFunctionData
{
  public:
    virtual ~BGSEntryPointFunctionData();
};

class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
{
  public:
    float fValue;
    bool FUN_005e6700(BGSEntryPointFunctionData* apCompare);
};

// Returns true if apCompare is not a BGSEntryPointFunctionDataOneValue or its fValue differs from this object's fValue.
// @fnv 0x005e6700
bool BGSEntryPointFunctionDataOneValue::FUN_005e6700(BGSEntryPointFunctionData* apCompare)
{
    BGSEntryPointFunctionDataOneValue* poneValue;
    poneValue = dynamic_cast<BGSEntryPointFunctionDataOneValue*>(apCompare);
    if (!poneValue)
        return true;
    if (fValue != poneValue->fValue)
        return true;
    return false;
}

namespace fnv_005e67f0 {

struct FUN_005e64b0
{
    char base[4];
    float EntryPointTwoValueFunctionData;
    float fSecondFunctionValue;
    FUN_005e64b0();
};

struct FUN_005e67f0_shell : FUN_005e64b0
{
    FUN_005e64b0* FUN_005e67f0();
};

// Allocates a new FUN_005e64b0, copies EntryPointTwoValueFunctionData and fSecondFunctionValue into it, and returns the pointer.
// @fnv 0x005e67f0
FUN_005e64b0* FUN_005e67f0_shell::FUN_005e67f0()
{
    FUN_005e64b0* pduplicate = new FUN_005e64b0;
    pduplicate->EntryPointTwoValueFunctionData = EntryPointTwoValueFunctionData;
    pduplicate->fSecondFunctionValue = fSecondFunctionValue;
    return pduplicate;
}
}  // namespace fnv_005e67f0

extern int DAT_01197440;
extern int DAT_01197468;

class BGSEntryPointFunctionDataTwoValue : public BGSEntryPointFunctionData
{
  public:
    float EntryPointTwoValueFunctionData;
    float fSecondFunctionValue;
    bool FUN_005e6890(BGSEntryPointFunctionData* apCompare);
};

// Returns true if the dynamic_cast to BGSEntryPointFunctionDataTwoValue fails or if either float field differs from apCompare.
// @fnv 0x005e6890
bool BGSEntryPointFunctionDataTwoValue::FUN_005e6890(BGSEntryPointFunctionData* apCompare)
{
    BGSEntryPointFunctionDataTwoValue* ptwoValue = dynamic_cast<BGSEntryPointFunctionDataTwoValue*>(apCompare);
    if (!ptwoValue)
        return true;
    if (EntryPointTwoValueFunctionData != ptwoValue->EntryPointTwoValueFunctionData)
        return true;
    if (fSecondFunctionValue != ptwoValue->fSecondFunctionValue)
        return true;
    return false;
}

struct FUN_005e6510
{
    void* m_vtbl;
    int m_uiFilterValue;
    FUN_005e6510();
};
struct FUN_005e69d0_shell
{
    void* m_vtbl;
    int m_uiFilterValue;
    FUN_005e6510* FUN_005e69d0();
};
// @fnv 0x005e69d0
FUN_005e6510* FUN_005e69d0_shell::FUN_005e69d0()
{
    FUN_005e6510* pduplicate = new FUN_005e6510;
    pduplicate->m_uiFilterValue = m_uiFilterValue;
    return pduplicate;
}

struct TESSound
{
};
struct FUN_005e6ab0_StandIn
{
    int f0;
    TESSound* pLeveledList;
    void FUN_005e6ab0();
};
struct BGSEntryPointFunctionData;
struct TESLevItem;

template <int Value> struct EndianSizeTag
{
};
struct TESFile_s
{
};
struct FUN_005e6b00_cls
{
    int pad;
    int value;
    bool FUN_005e6b00(TESFile_s* apFile);
};
// Reads a 4-byte leveled list ID into value, byte-swapping it when GetChunkData returns true.
// @fnv 0x005e6b00
bool FUN_005e6b00_cls::FUN_005e6b00(TESFile_s* apFile)
{
    unsigned int isize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
    if (isize != 4)
        return false;
    unsigned int ileveledListID = 0;
    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&ileveledListID), 0);
    if (reinterpret_cast<::TESFile *>((apFile))->IsEndianConversionRequired())
        ::FUN_00401080((int*)&ileveledListID);
    value = ileveledListID;
    return true;
}

struct FUN_005abe00_shell
{
};

struct FUN_00413f40_shell
{
};


struct FUN_005e6e50_obj
{
    int unk00;
    char* m_kChoiceText;
    void FUN_005e6e50();
};


// Validates the arguments, then adds the return value of FUN_006b9130 to the first pointed-to float.
// @fnv 0x005e5cc0
void FUN_005e5cc0(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                  EntryPointValueSource* apSource)
{
    EntryPointSingleValueSource* pSource;
    if (!::FUN_005e5b80(0, 1, (::TESObjectREFR *)(aiArg1), aiArg2, aucArgCount, (void **)(apapValues), apSource))
        return;

    {
        float* pfValue;
        pfValue = *apapValues;
        pSource = reinterpret_cast<EntryPointSingleValueSource*>(apSource);
        *pfValue += reinterpret_cast<::TimeoutTimer *>((pSource))->FUN_006b9130();
    }
}

struct FUN_005e6470_shell
{
    void FUN_005e6470();
};
// Calls FUN_005e6470, then calls _Deallocate on this when the low bit of flags is set, and returns this.
// @fnv 0x005e6440
void* Dummy::FUN_005e6440(unsigned int flags)
{
    reinterpret_cast<::FUN_005e6470_shell *>(this)->FUN_005e6470();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x005e6490
void FUN_005e6490_shell::FUN_005e6490()
{
    reinterpret_cast<::FUN_005e6470_shell *>(this)->FUN_005e6470();
}

// @fnv 0x005e6470
void FUN_005e6470_shell::FUN_005e6470()
{
    *(const char**)this = "@d^";
}

class OneValueSaveEntry
{
  public:
    void* vtable;
    float value;

    void FUN_005e6760();
};


class ActionPointCostSetting
{
  public:
};

extern ActionPointCostSetting* DAT_0119baf8[22];

// Returns the action point cost for the given action index, or 0.0f if the index is out of range.
// @fnv 0x0066dc70
float FUN_0066dc70(int aiAction)
{
    float cost = 0.0f;
    if (aiAction >= 0 && aiAction < 22)
        cost = *((float *)&(::FUN_00403e20((float *)(DAT_0119baf8[aiAction]))));
    return cost;
}

struct EntryFunctionDataView
{
    virtual ~EntryFunctionDataView();
    virtual unsigned int GetType();
};

// Checks the function type, argument count, non-null arguments, and, when present, data type; warns and returns false on mismatches.
// @fnv 0x005e5b80
bool FUN_005e5b80(int aeExpectedFunctionType, unsigned char acExpectedFunctionData, TESObjectREFR* apPerkOwner,
                  int aeFunctionType, unsigned char acArgumentCount, void** apFunctionArgument, void* apData)
{
    if (aeExpectedFunctionType != aeFunctionType)
    {
        ::FUN_005b5e40(
            );
        return false;
    }
    if (::BGSEntryPointFunction::ms_auiArgumentCountsByType[aeExpectedFunctionType] != acArgumentCount)
    {
        ::FUN_005b5e40(
            );
        return false;
    }
    for (unsigned int i = 0; i < acArgumentCount; ++i)
    {
        if (!apFunctionArgument[i])
        {
            ::FUN_005b5e40(
                );
            return false;
        }
    }
    EntryFunctionDataView* pfunctionData = (EntryFunctionDataView*)apData;
    if (pfunctionData && pfunctionData->GetType() != acExpectedFunctionData)
    {
        ::FUN_005b5e40(
            );
        return false;
    }
    return true;
}


class EntryPointFunctionDataStartView
{
  public:
    virtual ~EntryPointFunctionDataStartView();
    virtual unsigned char GetType();

    void FUN_005e6250();
};
// @fnv 0x005e6ab0
void FUN_005e6ab0_StandIn::FUN_005e6ab0()
{
    reinterpret_cast<::EntryPointFunctionDataStartView *>(this)->FUN_005e6250();
    unsigned int ileveledListID = 0;
    if (pLeveledList != 0)
    {
        ileveledListID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pLeveledList))->FUN_0084e3a0()));
        ::FUN_00485910(0x44465045, ileveledListID);
    }
}
// @fnv 0x005e6e50
void FUN_005e6e50_obj::FUN_005e6e50()
{
    reinterpret_cast<::EntryPointFunctionDataStartView *>(this)->FUN_005e6250();
    unsigned int z = 0;
    if (m_kChoiceText && ::std::strlen(m_kChoiceText))
        ::FUN_004856f0((void *)(0x32465045), m_kChoiceText, (void *)(::FUN_0044a670(m_kChoiceText) + 1));
    ::FUN_00485950((void *)(0x33465045), *(unsigned short*)((char*)this + 0x5c));
    reinterpret_cast<::FUN_005abe00 *>((((::FUN_005abe00_shell *)(reinterpret_cast<::TESTopicInfoData *>((reinterpret_cast<FUN_00413f40_shell*>(this)))->GetLinkToList()))))->ProcessHeader();
}
// @fnv 0x005e6760
void OneValueSaveEntry::FUN_005e6760()
{
    reinterpret_cast<::EntryPointFunctionDataStartView *>(this)->FUN_005e6250();
    ::FUN_00485910(0x44465045, value);
}

// @fnv 0x005e6250
void EntryPointFunctionDataStartView::FUN_005e6250()
{
    unsigned char type = GetType();
    FUN_004858f0(0x54465045, type);
}

struct EntryPointFloatPair
{
    float EntryPointTwoValueFunctionData;
    float fSecondFunctionValue;
};
class EntryPointTwoValueSave
{
  public:
    void FUN_005e6900();
};
// Copies two float fields into a local pair, conditionally byte-swaps it, and passes its address and size to a helper.
// @fnv 0x005e6900
void EntryPointTwoValueSave::FUN_005e6900()
{
    reinterpret_cast<::EntryPointFunctionDataStartView *>(this)->FUN_005e6250();
    EntryPointFloatPair data;
    data.EntryPointTwoValueFunctionData =
        reinterpret_cast<BGSEntryPointFunctionDataTwoValue*>(this)->EntryPointTwoValueFunctionData;
    data.fSecondFunctionValue = reinterpret_cast<BGSEntryPointFunctionDataTwoValue*>(this)->fSecondFunctionValue;
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::S_00462230 *>(&(data))->FUN_00462230();
    ::AppendChunk(0x44465045, &data, 8);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::S_00462230 *>(&(data))->FUN_00462230();
}

namespace fnv_005e64e0 {

struct EntryPointDataBase_5e6490
{
    void Destroy_5e6490();
};

void EntryPointDataBase_5e6490::Destroy_5e6490()
{}

struct EntryPointData_5e64e0
{
    void* FUN_005e64e0(unsigned int flags);
};

// Calls the base class destructor, deallocates this object if the low bit of flags is set, and returns this.
// @fnv 0x005e64e0
void* EntryPointData_5e64e0::FUN_005e64e0(unsigned int flags)
{
    reinterpret_cast<::FUN_005e6490_shell *>((((EntryPointDataBase_5e6490*)this)))->FUN_005e6490();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_005e64e0

class BGSEntryPointFunctionDataLeveledList : public BGSEntryPointFunctionData
{
  public:
    TESLevItem* pLeveledList;
    bool FUN_005e6a60(BGSEntryPointFunctionData* apCompare);
};

// Returns true if the cast to BGSEntryPointFunctionDataLeveledList fails or if pLeveledList differs from the other entry's pLeveledList, otherwise false.
// @fnv 0x005e6a60
bool BGSEntryPointFunctionDataLeveledList::FUN_005e6a60(BGSEntryPointFunctionData* apCompare)
{
    BGSEntryPointFunctionDataLeveledList* pleveledList = dynamic_cast<BGSEntryPointFunctionDataLeveledList*>(apCompare);
    if (!pleveledList)
        return true;
    if (pLeveledList != pleveledList->pLeveledList)
        return true;
    return false;
}

struct Script
{
};

struct NiFixedStr : Script
{
};

struct SeqObj
{
    NiFixedStr& GetName();
};

struct TESChallenge : SeqObj
{
    bool GetStartsLocked();
};

struct G2
{
    void AddHead(int*);
};

struct FUN_005e61b0_Local
{
    G2* pList;
    void* pLocals;
};


// Runs the challenge name object's script when it starts locked; otherwise adds the challenge pointer to pList.
// @fnv 0x005e61b0
void __cdecl FUN_005e61b0(void* arg1, void* arg2, bool arg3, FUN_005e61b0_Local* apLocal, TESChallenge* apChallenge)
{
    if (!::FUN_005e5b80(2, 4, (::TESObjectREFR *)(arg1), (int)(arg2), arg3, (void **)(apLocal), apChallenge))
        return;

    G2* pChallenge = apLocal->pList;
    void* pLocals = apLocal->pLocals;
    TESChallenge* pList = apChallenge;

    if (pChallenge && pList)
    {
        if (pList->GetStartsLocked())
        {
            NiFixedStr* pName = &(*(::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((pList))->GetLinkToList()));
            if (pName)
                reinterpret_cast<::FUN_005ac1e0_shell *>((pName))->FUN_005ac1e0((::TESObjectREFR *)(pLocals), (::ScriptLocals *)(0), (::TESObjectREFR *)(0), 0);
        }
        else
        {
            pChallenge->AddHead((int*)&pList);
        }
    }
}

struct Place_5e65d0
{
    void* FUN_005e65d0(unsigned int);
};
// @fnv 0x005e65d0
void* Place_5e65d0::FUN_005e65d0(unsigned int flags)
{
    reinterpret_cast<::FUN_005e6600 *>(this)->FUN_005e6600::~FUN_005e6600();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_005e6790 {
template <int Value> struct EndianSizeTag
{
};
struct TESFile_s
{
};
struct FUN_005e6790_cls
{
    int pad;
    int value;
    bool FUN_005e6790(TESFile_s* apFile);
};
// Reads a 4-byte chunk from apFile into value, converting endianness if GetChunkData succeeds, and returns false if the chunk size is not 4.
// @fnv 0x005e6790
bool FUN_005e6790_cls::FUN_005e6790(TESFile_s* apFile)
{
    unsigned int isize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
    if (isize != 4)
        return false;
    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&value), 0);
    if (reinterpret_cast<::TESFile *>((apFile))->IsEndianConversionRequired())
        ::FUN_00401080(&value);
    return true;
}
}  // namespace fnv_005e6790

namespace fnv_005e6cd0 {
void* __cdecl operator new(unsigned int);

struct Script
{
};

struct NiFixedStr : Script
{
};

struct SeqObj
{
    NiFixedStr& GetName();
};

struct BGSEntryPointFunctionData : SeqObj
{
    int baseData;
};

struct FUN_005e6540 : BGSEntryPointFunctionData
{
    char* m_kChoiceText;
    unsigned char padding[0x54];
    unsigned short value;

    FUN_005e6540();
};

struct FUN_005e6cd0_shell : FUN_005e6540
{
    BGSEntryPointFunctionData* FUN_005e6cd0();
};

// Creates a new FUN_005e6540, copies m_kChoiceText, script contents, and value from this, and returns it.
// @fnv 0x005e6cd0
BGSEntryPointFunctionData* FUN_005e6cd0_shell::FUN_005e6cd0()
{
    FUN_005e6540* pduplicate = new FUN_005e6540();

    reinterpret_cast<::FUN_005e6c60_shell *>((pduplicate))->FUN_005e6c60(this->m_kChoiceText);
    reinterpret_cast<::FUN_005aa420_shell *>(&((*(::fnv_005e6cd0::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((pduplicate))->GetLinkToList()))))->CopyFromScript((::Script *)(::fnv_005e6cd0::Script *)(&(*(::fnv_005e6cd0::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((this))->GetLinkToList()))));
    pduplicate->value = this->value;

    return pduplicate;
}
}  // namespace fnv_005e6cd0

class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
{
  public:
    const char* choiceText;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned short flags;
public:
    void InitializeComponent();
};

class ActivateChoiceForm
{
  public:
};

struct ActivationChoiceLabelView
{
    void* vtable;
    const char* text;
};

class ActivateChoiceCompare : public BGSEntryPointFunctionDataActivateChoice
{
  public:
    bool FUN_005e6d80(BGSEntryPointFunctionData* other);
};


// Returns true if the cast fails, a label comparison is nonzero, the form comparison returns true, or flags differ.
// @fnv 0x005e6d80
bool ActivateChoiceCompare::FUN_005e6d80(BGSEntryPointFunctionData* other)
{
    ActivateChoiceCompare* pOtherChoice =
        reinterpret_cast<ActivateChoiceCompare*>(dynamic_cast<BGSEntryPointFunctionDataActivateChoice*>(other));
    if (pOtherChoice == 0)
        return true;
    if ((reinterpret_cast<ActivationChoiceLabelView*>(this)->text != 0 &&
         reinterpret_cast<ActivationChoiceLabelView*>(pOtherChoice)->text == 0) ||
        (reinterpret_cast<ActivationChoiceLabelView*>(this)->text == 0 &&
         reinterpret_cast<ActivationChoiceLabelView*>(pOtherChoice)->text != 0))
        return true;
    if (reinterpret_cast<ActivationChoiceLabelView*>(this)->text != 0 &&
        reinterpret_cast<ActivationChoiceLabelView*>(pOtherChoice)->text != 0 &&
        FUN_00408b20(reinterpret_cast<ActivationChoiceLabelView*>(this)->text,
                     reinterpret_cast<ActivationChoiceLabelView*>(pOtherChoice)->text))
        return true;
    if (reinterpret_cast<::ScriptCompareOwner *>((((::ActivateChoiceForm *)(reinterpret_cast<::TESTopicInfoData *>(this)->GetLinkToList()))))->IsDifferentFrom((::Script *)(::ActivateChoiceForm *)(((::ActivateChoiceForm *)(reinterpret_cast<::TESTopicInfoData *>((pOtherChoice))->GetLinkToList())))))
        return true;
    if (flags != pOtherChoice->flags)
        return true;
    return false;
}

class ActivationChoiceFormView
{
  public:
    virtual void Unknown000();
    virtual void Unknown004();
    virtual void Unknown008();
    virtual void Unknown00C();
    virtual void Unknown010();
    virtual void Unknown014();
    virtual void Unknown018();
    virtual void Unknown01C();
    virtual void Unknown020();
    virtual void Unknown024();
    virtual void Unknown028();
    virtual void Unknown02C();
    virtual void Unknown030();
    virtual void Unknown034();
    virtual void Unknown038();
    virtual void Unknown03C();
    virtual void Unknown040();
    virtual void Unknown044();
    virtual void Unknown048();
    virtual void Unknown04C();
    virtual void Unknown050();
    virtual void Unknown054();
    virtual void Unknown058();
    virtual void Unknown05C();
    virtual void Unknown060();
    virtual void Unknown064();
    virtual void Unknown068();
    virtual void Unknown06C();
    virtual void Unknown070();
    virtual void Unknown074();
    virtual void Unknown078();
    virtual void Unknown07C();
    virtual void Unknown080();
    virtual void Unknown084();
    virtual void Unknown088();
    virtual void Unknown08C();
    virtual void Unknown090();
    virtual void Unknown094();
    virtual void Unknown098();
    virtual void Unknown09C();
    virtual void Unknown0A0();
    virtual void Unknown0A4();
    virtual void Unknown0A8();
    virtual void Unknown0AC();
    virtual void Unknown0B0();
    virtual void Unknown0B4();
    virtual void Unknown0B8();
    virtual void Unknown0BC();
    virtual void Unknown0C0();
    virtual void Unknown0C4();
    virtual void Unknown0C8();
    virtual void Unknown0CC();
    virtual void Unknown0D0();
    virtual void Unknown0D4();
    virtual void Unknown0D8();
    virtual void Unknown0DC();
    virtual void Unknown0E0();
    virtual void Unknown0E4();
    virtual void Unknown0E8();
    virtual void Unknown0EC();
    virtual void Unknown0F0();
    virtual void Unknown0F4();
    virtual void Unknown0F8();
    virtual void Unknown0FC();
    virtual void Unknown100();
    virtual void Unknown104();
    virtual void Unknown108();
    virtual void Unknown10C();
    virtual void Unknown110();
    virtual void Unknown114();
    virtual void Unknown118();
    virtual void Unknown11C();
    virtual void Unknown120();
    virtual void Unknown124();
    virtual void Unknown128();
    virtual void Unknown12C();
    virtual const char* GetName();
};

class ActivationChoiceScript
{
  public:
};

class ActivationChoiceInitializer : public BGSEntryPointFunctionData
{
  public:
    char* choiceLabel;
    ActivationChoiceScript resultScript;
    void FUN_005e7230(TESForm* form);
};

extern char str_010463f0[];


// Calls resultScript with form, then logs a message when the subsequent count returned by FUN_0046e8a0 is nonzero.
// @fnv 0x005e7230
void ActivationChoiceInitializer::FUN_005e7230(TESForm* form)
{
    int savedWarnings = FUN_0046e8a0();
    FUN_0043b2b0(true);
    FUN_004fffe0(0);
    reinterpret_cast<::Scr *>(&(resultScript))->FUN_005ab400(form);
    FUN_0043b2b0(false);

    int newWarnings = FUN_0046e8a0();
    FUN_004fffe0(savedWarnings);

    if (newWarnings != 0)
        ::FUN_005b5e40();
}

namespace fnv_005e6970 {
struct TESFile_s
{
};

struct EntryPointTwoValueChunk_5e6970
{
    float valueA;
    float valueB;
};

struct FUN_005e6970_cls
{
    void* vtable;
    float valueA;
    float valueB;

    bool FUN_005e6970(TESFile_s* apFile);
};

// Reads an 8-byte chunk from apFile, optionally applies FUN_00462230, then copies its two floats into valueA and valueB.
// @fnv 0x005e6970
bool FUN_005e6970_cls::FUN_005e6970(TESFile_s* apFile)
{
    EntryPointTwoValueChunk_5e6970 data;
    unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
    if (size != 8)
        return false;
    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&data), size);
    if (reinterpret_cast<::TESFile *>((apFile))->IsEndianConversionRequired())
        reinterpret_cast<::S_00462230 *>(&(data))->FUN_00462230();
    valueA = data.valueA;
    valueB = data.valueB;
    return true;
}
}

class TESFile;
class TESForm
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual const char* GetName();
public:
    ::TESFile *GetFile(int);
};


struct TESLevItem : TESForm
{
};
class EntryPointOwnerView : public TESForm
{
  public:
};

struct LevListData
{
    int unk00;
    TESLevItem* pLevItem;
    void FUN_005e6b70(TESForm* apOwner);
};

// Resolves pLevItem's numeric value to a TESLevItem and warns if the resolved form is not one.
// @fnv 0x005e6b70
void LevListData::FUN_005e6b70(TESForm* apOwner)
{
    if (pLevItem)
    {
        unsigned int itempint = (unsigned int)pLevItem;
        ::ResolveFormID((unsigned int *)&(itempint), apOwner->GetFile(-1));
        pLevItem = dynamic_cast<TESLevItem*>(FUN_004839c0(itempint));
        if (!pLevItem)
        {
            if (reinterpret_cast<::BGSCameraPath *>((static_cast<EntryPointOwnerView*>(apOwner)))->HasNameForWarning())
                ::FUN_005b5e40();
            else
                ::FUN_005b5e40();
        }
    }
}

struct FUN_005e6420_SV
{
    FUN_005e6420_SV();
    ~FUN_005e6420_SV();
    virtual void V1();
};

struct TESForm_SV
{
    virtual ~TESForm_SV();
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<void*> kMods;
};

class ChoiceDataInitialization
{
  public:
};

class Script_SV : public TESForm_SV
{
  public:
    Script_SV();
    virtual ~Script_SV();

    unsigned int variableCount;
    unsigned int referenceCount;
    unsigned int compiledSize;
    unsigned int lastVariableID;
    bool isQuestScript;
    bool isMagicEffectScript;
    bool isCompiled;
    char* sourceText;
    char* compiledData;
    float profilerTime;
    float questDelay;
    float secondsBuffer;
    TESForm* ownerQuest;
    BSSimpleList<void*> referencedObjects;
    BSSimpleList<void*> variables;
};

struct FUN_005e6540 : FUN_005e6420_SV
{
    char* label;
    Script_SV m_script;
    unsigned short flags;

    FUN_005e6540();
};

// Initializes label and flags to zero, default-constructs m_script, then calls FUN_005e6c30.
// @fnv 0x005e6540
FUN_005e6540::FUN_005e6540() : FUN_005e6420_SV(), label(0), m_script(), flags(0)
{
    reinterpret_cast<::BGSEntryPointFunctionDataActivateChoice *>((reinterpret_cast<ChoiceDataInitialization*>(this)))->InitializeComponent();
}
