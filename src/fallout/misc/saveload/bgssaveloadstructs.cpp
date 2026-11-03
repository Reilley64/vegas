
// src/fallout/misc/saveload/bgssaveloadstructs.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgssaveloadstructs.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BGSLoadFormBuffer.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084b450_Class.h"
#include "fnv/decl/FUN_0084e320_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00851110_shell.h"
#include "fnv/decl/FUN_00854b80_class.h"
#include "fnv/decl/FUN_00854c10_Class.h"
#include "fnv/decl/FUN_00865b10_shell.h"
#include "fnv/decl/FUN_008663e0_shell.h"
#include "fnv/decl/FUN_00866450_shell.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00865ad0__BGSSaveFormBuffer.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0083f000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_0084b000.h"
#include "fnv/symbols_00853000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
struct FUN_00847db0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    void FUN_00847db0();
};

// @fnv 0x00847db0
void FUN_00847db0_shell::FUN_00847db0()
{
    m_0C = 0;
    m_10 = 0;
}

struct FUN_00853dc0_shell
{
    int GetDifference();
};

// @fnv 0x00853dc0
int __thiscall FUN_00853dc0_shell::GetDifference()
{
    return *(int*)((char*)this + 0xc) - *(int*)((char*)this + 0x10);
}

struct FUN_008547f0_shell
{
    unsigned char m_auiShapeKeys[8];
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int __thiscall GetSum();
};

// @fnv 0x008547f0
int __thiscall FUN_008547f0_shell::GetSum()
{
    return m_kPointA + m_kPointB + m_iThirdValue;
}

struct FUN_00854810_shell
{
    int __thiscall GetSumOfFields();
};

// @fnv 0x00854810
int __thiscall FUN_00854810_shell::GetSumOfFields()
{
    return ((int*)this)[0x41] + ((int*)this)[0x42];
}

struct FUN_00854880_shell
{
    unsigned int m_iElementCount;
    unsigned int m_kMinimumCorner;
    unsigned int m_kMaximumCorner;
    unsigned int m_sum;
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
    void AccumulateStats(unsigned int a, unsigned int b, unsigned int c);
};

// Increments a counter, adds a, b and c to three running totals, and tracks the minimum and maximum of their sum.
// @fnv 0x00854880
void __thiscall FUN_00854880_shell::AccumulateStats(unsigned int auiValueA, unsigned int auiValueB,
                                                    unsigned int auiValueC)
{
    this->m_iElementCount = this->m_iElementCount + 1;
    this->m_kMinimumCorner = this->m_kMinimumCorner + auiValueA;
    this->m_kMaximumCorner = this->m_kMaximumCorner + auiValueB;
    this->m_sum = this->m_sum + auiValueC;
    unsigned int uiSum = auiValueA + auiValueB + auiValueC;
    if (uiSum < this->m_ucLowNibble)
        this->m_ucLowNibble = uiSum;
    if (uiSum > this->m_ucHighNibble)
        this->m_ucHighNibble = uiSum;
}

struct FUN_00854900_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int FUN_00854900();
};

// @fnv 0x00854900
int FUN_00854900_shell::FUN_00854900()
{
    return m_04 + m_08 + m_0c;
}

extern int DAT_011a2428[];

// Masks the low 6 bits of the first byte and returns the entry at that index from DAT_011a2428.
// @fnv 0x00853640
int __fastcall FUN_00853640(unsigned char* pData)
{
    unsigned char v = pData[0] & 0x3f;
    return DAT_011a2428[v];
}

extern int DAT_011a11fc[1000];
extern int DAT_011a216c[1000];

// Returns DAT_011a216c[index] when index is below 1000, otherwise DAT_011a11fc[index - 1000].
// @fnv 0x00853de0
int FUN_00853de0(unsigned int index)
{
    int result;
    if (index >= 1000)
        result = DAT_011a11fc[index - 1000];
    else
        result = DAT_011a216c[index];
    return result;
}

struct FUN_00854830_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    FUN_00854830_shell();
};

// @fnv 0x00854830
FUN_00854830_shell::FUN_00854830_shell()
{
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0C = 0;
    m_10 = 0xffffffff;
    m_14 = 0;
}

int __fastcall FUN_00853640(unsigned char* param_1);
struct FUN_00849220_shell
{
    unsigned char* p;
    int __thiscall FUN_00849220();
};
// @fnv 0x00849220
int __thiscall FUN_00849220_shell::FUN_00849220()
{
    return FUN_00853640(p);
}

struct FormIDConverter
{
    unsigned int RegisterFormID(unsigned int);
};
struct ArrSI
{
};
struct BGSSaveLoadGame;
struct FUN_00853570_shell
{
    void WriteFormIDBytes(unsigned int numericID);
};
// @fnv 0x00853570
void FUN_00853570_shell::WriteFormIDBytes(unsigned int numericID)
{
    unsigned int iElementIndex = reinterpret_cast<FormIDConverter*>(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(g_BGSSaveLoadGame)))->GetName())))
                              ->RegisterFormID(numericID);
    unsigned int ifileIndex = iElementIndex >> 24;
    if (ifileIndex == 0xFF)
        iElementIndex |= 0x800000;
    ((unsigned char*)this)[0] = (unsigned char)(iElementIndex >> 16);
    ((unsigned char*)this)[1] = (unsigned char)(iElementIndex >> 8);
    ((unsigned char*)this)[2] = (unsigned char)iElementIndex;
}

extern "C" void* memset(void*, int, unsigned int);
extern int DAT_011a2428[];
extern unsigned int DAT_011de3e0;
extern unsigned char DAT_011de360[];
// Fills DAT_011de360 with 255, sets DAT_011de3e0 to 55, then stores each index i at DAT_011de360[DAT_011a2428[i]].
// @fnv 0x008535e0
void FUN_008535e0()
{
    memset(&DAT_011de360, 255, 121);
    DAT_011de3e0 = 55;
    for (unsigned int uiIndex = 0; uiIndex < DAT_011de3e0; ++uiIndex)
        DAT_011de360[DAT_011a2428[uiIndex]] = uiIndex;
}

struct FUN_00853670_shell
{
    unsigned char m0;
    void __thiscall FUN_00853670(int);
};
extern unsigned char DAT_011de360[];
extern unsigned int DAT_011de3e0;
// @fnv 0x00853670
void __thiscall FUN_00853670_shell::FUN_00853670(int formType)
{
    unsigned char type = DAT_011de360[formType];
    if (type >= DAT_011de3e0)
    {
        ::FUN_00845cc0("Unknown form type %i %s in BGSSaveLoadFormInfo::SetFormType()", formType,
                         GetStringForByte((unsigned char)formType));
    }
    m0 = (m0 & ~0x3F) | type;
}

void __cdecl operator delete(void*);
struct FUN_00853880_shell
{
    void __thiscall FUN_008538b0();
    void* __thiscall Destroy(unsigned int flags);
};
struct Dummy008539e0
{
    virtual int Func(int);
};
struct FUN_008539e0_holder
{
    int _pad[6];
    Dummy008539e0* m_ptr;
    void FUN_008539e0();
};
// Calls Func(1) on m_ptr if it is non-null, then sets m_ptr to 0.
// @fnv 0x008539e0
void FUN_008539e0_holder::FUN_008539e0()
{
    Dummy008539e0* b = m_ptr;
    Dummy008539e0* a = b;
    a ? a->Func(1) : 0;
    m_ptr = 0;
}

struct FUN_00854920_shell : FUN_00854900_shell
{
    float __thiscall GetRatio();
};
// @fnv 0x00854920
float __thiscall FUN_00854920_shell::GetRatio()
{
    return (float)((double)(unsigned int)FUN_00854900() / (double)(unsigned int)m_00);
}

// Compares the values returned by calling GetSum on both objects, returning -1 if the first is greater, 1 if less, else 0.
// @fnv 0x00854960
int FUN_00854960(FUN_008547f0_shell* pFirst, FUN_008547f0_shell* pSecond)
{
    unsigned int x = pFirst->GetSum();
    unsigned int y = pSecond->GetSum();
    {
        int r;
        if (x > y)
            r = -1;
        else
            r = x < y;
        return r;
    }
}

struct TESForm
{
    virtual bool v00() = 0;
    virtual bool v01() = 0;
    virtual bool v02() = 0;
    virtual bool v03() = 0;
    virtual bool v04() = 0;
    virtual bool v05() = 0;
    virtual bool v06() = 0;
    virtual bool v07() = 0;
    virtual bool v08() = 0;
    virtual bool v09() = 0;
    virtual bool v10() = 0;
    virtual bool v11() = 0;
    virtual bool v12() = 0;
    virtual bool v13() = 0;
    virtual bool v14() = 0;
    virtual bool v15() = 0;
    virtual bool v16() = 0;
    virtual bool v17() = 0;
    virtual bool v18() = 0;
    virtual bool v19() = 0;
    virtual bool v20() = 0;
    virtual bool v21() = 0;
    virtual bool v22() = 0;
    virtual bool v23() = 0;
    virtual bool v24() = 0;
    virtual bool v25() = 0;
    virtual bool v26() = 0;
    virtual bool v27() = 0;
    virtual bool v28() = 0;
    virtual bool v29() = 0;
    virtual bool v30() = 0;
    virtual bool v31() = 0;
    virtual bool v32() = 0;
    virtual bool v33() = 0;
    virtual bool v34() = 0;
    virtual bool v35() = 0;
    virtual bool v36() = 0;
    virtual bool v37() = 0;
    virtual bool v38() = 0;
    virtual bool v39() = 0;
    virtual bool v40() = 0;
    virtual bool v41() = 0;
    virtual bool v42() = 0;
    virtual bool v43() = 0;
    virtual bool v44() = 0;
    virtual bool v45() = 0;
    virtual bool v46() = 0;
    virtual bool v47() = 0;
    virtual bool v48() = 0;
    virtual bool v49() = 0;
    virtual bool v50() = 0;
    virtual bool v51() = 0;
    virtual bool v52() = 0;
    virtual bool v53() = 0;
    virtual bool v54() = 0;
    virtual bool v55() = 0;
    virtual bool v56() = 0;
    virtual bool v57() = 0;
    virtual bool v58() = 0;
    virtual bool v59() = 0;
    virtual bool IsMobileObject() = 0;
    virtual bool v61() = 0;
    virtual bool v62() = 0;
    virtual bool v63() = 0;
    virtual bool v64() = 0;
    virtual bool v65() = 0;
    virtual bool v66() = 0;
    virtual bool v67() = 0;
    virtual bool v68() = 0;
    virtual bool v69() = 0;
    virtual bool v70() = 0;
    virtual bool v71() = 0;
    virtual bool v72() = 0;
    virtual bool v73() = 0;
    virtual bool v74() = 0;
    virtual bool v75() = 0;
    virtual char const* GetName() = 0;
    unsigned int FNV_GetFormType() const;
};

struct MobileObject : TESForm
{
};

struct TESObjectREFR : MobileObject
{
};

struct TESQuest
{
    virtual bool q00() = 0;
    virtual bool q01() = 0;
    virtual bool q02() = 0;
    virtual bool q03() = 0;
    virtual bool q04() = 0;
    virtual bool q05() = 0;
    virtual bool q06() = 0;
    virtual bool q07() = 0;
    virtual bool q08() = 0;
    virtual bool q09() = 0;
    virtual bool q10() = 0;
    virtual bool q11() = 0;
    virtual bool q12() = 0;
    virtual bool q13() = 0;
    virtual bool q14() = 0;
    virtual bool q15() = 0;
    virtual bool q16() = 0;
    virtual bool q17() = 0;
    virtual bool q18() = 0;
    virtual bool q19() = 0;
    virtual bool q20() = 0;
    virtual bool q21() = 0;
    virtual bool q22() = 0;
    virtual bool q23() = 0;
    virtual bool q24() = 0;
    virtual bool q25() = 0;
    virtual bool q26() = 0;
    virtual bool q27() = 0;
    virtual bool q28() = 0;
    virtual bool q29() = 0;
    virtual bool q30() = 0;
    virtual bool q31() = 0;
    virtual bool q32() = 0;
    virtual bool q33() = 0;
    virtual bool q34() = 0;
    virtual bool q35() = 0;
    virtual bool q36() = 0;
    virtual bool q37() = 0;
    virtual bool q38() = 0;
    virtual bool q39() = 0;
    virtual bool q40() = 0;
    virtual bool q41() = 0;
    virtual bool q42() = 0;
    virtual bool q43() = 0;
    virtual bool q44() = 0;
    virtual bool q45() = 0;
    virtual bool q46() = 0;
    virtual bool q47() = 0;
    virtual bool q48() = 0;
    virtual bool q49() = 0;
    virtual bool q50() = 0;
    virtual bool q51() = 0;
    virtual bool q52() = 0;
    virtual bool q53() = 0;
    virtual bool q54() = 0;
    virtual bool q55() = 0;
    virtual bool q56() = 0;
    virtual bool q57() = 0;
    virtual bool q58() = 0;
    virtual bool q59() = 0;
    virtual bool q60() = 0;
    virtual bool q61() = 0;
    virtual bool q62() = 0;
    virtual bool q63() = 0;
    virtual bool q64() = 0;
    virtual bool q65() = 0;
    virtual bool q66() = 0;
    virtual bool q67() = 0;
    virtual bool q68() = 0;
    virtual bool q69() = 0;
    virtual bool q70() = 0;
    virtual bool q71() = 0;
    virtual bool q72() = 0;
    virtual bool q73() = 0;
    virtual bool q74() = 0;
    virtual bool q75() = 0;
    virtual bool q76() = 0;
    virtual bool q77() = 0;
    virtual char const* GetName() = 0;
};

struct TESTopicInfo : TESForm
{
    TESQuest* __thiscall GetParentQuest();
};

struct TESFullName
{
};

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};


struct FormNameEntry
{
    unsigned int iFormID;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    TESForm* pForm;
    unsigned int m_18;

    void __thiscall BuildFormName(char* apName, unsigned int aiNameSize);
};

// @fnv 0x008536d0
void __thiscall FormNameEntry::BuildFormName(char* apName, unsigned int aiNameSize)
{
    TESObjectREFR* pRefr;
    TESTopicInfo* pTopicInfo;

    if (!this->pForm)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, "UNLOADED");
        return;
    }

    pRefr = this->pForm->IsMobileObject() ? static_cast<TESObjectREFR*>(this->pForm) : 0;

    if (pRefr)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, reinterpret_cast<::FUN_0055d520_shell *>((pRefr))->FUN_0055d520());
    }
    else
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, ::FUN_00482720(this->pForm));
    }

    if (::FUN_0044a670(apName) == 0)
    {
        TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, this->pForm->GetName());
    }

    if (::FUN_0044a670(apName) == 0)
    {
        switch (this->pForm->FNV_GetFormType())
        {
        case 0x46:
            pTopicInfo = static_cast<TESTopicInfo*>(this->pForm);
            TaskQueueInterface::CopyStringToBuffer(apName, aiNameSize, pTopicInfo->GetParentQuest()->GetName());
            break;
        }
    }
}

void* operator new(unsigned int);

int __cdecl FUN_00854960(FUN_008547f0_shell*, FUN_008547f0_shell*);

struct AEList
{
    void* m_auiShapeKeys[2];

};

struct SL : public AEList
{
    SL();
};

struct DummyPointerMap
{
};

struct SetAtHelper
{
};

struct FUN_00854af0
{
    unsigned char m_data[25];

    FUN_00854af0();
};

struct FUN_008549b0_shell
{
    void __thiscall FUN_008549b0(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                                 unsigned int, unsigned char);
};

// @fnv 0x008549b0
void __thiscall FUN_008549b0_shell::FUN_008549b0(unsigned int p0, unsigned int p1, unsigned int uiKey, unsigned int p3,
                                                 unsigned int p4, unsigned int p5, unsigned int p6, unsigned char p7)
{
    FUN_00854af0* form = new FUN_00854af0();

    reinterpret_cast<unsigned int*>(form)[0] = p0;
    reinterpret_cast<unsigned int*>(form)[5] = p1;
    reinterpret_cast<unsigned int*>(form)[1] = p3;
    reinterpret_cast<unsigned int*>(form)[2] = p4;
    reinterpret_cast<unsigned int*>(form)[3] = p5;
    reinterpret_cast<unsigned int*>(form)[4] = p6;
    form->m_data[0x18] = p7;

    {
        unsigned int list = 0;

        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<DummyPointerMap*>(this)))->FUN_00853130(uiKey, (::fnv_00853130::CombatThreatRecord *&)(list)))
        {
            list = reinterpret_cast<unsigned int>(new SL());
            reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<SetAtHelper*>(this)))->FUN_00844700(uiKey, list);
        }

        reinterpret_cast<::FUN_00470440 *>((reinterpret_cast<AEList*>(list)))->FUN_007a7eb0((::BGSPerkEntry *)(form), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(int (*)(void *, void *))(reinterpret_cast<int(__cdecl*)(void*, void*)>(FUN_00854960)));
    }
}

struct FUN_00854c80_shell
{
    virtual ~FUN_00854c80_shell();
    int m_04;
    int m_08;
    int m_0C;
    FUN_00854c80_shell(int formType);
};

struct FUN_0096a2d0_shell
{
    int m_10;
    int m_14;
    FUN_0096a2d0_shell();
};

struct FUN_00853810 : FUN_00854c80_shell
{
    FUN_0096a2d0_shell m_data;
    int m_18;
    FUN_00853810();
    virtual ~FUN_00853810();
};

// Constructs the object with base form type 0x25 and initializes m_18 to 0.
// @fnv 0x00853810
FUN_00853810::FUN_00853810() : FUN_00854c80_shell(0x25)
{
    m_18 = 0;
}

struct ResourceView
{
    virtual ~ResourceView();
};
struct StringListNode
{
    char* item;
    StringListNode* next;
    ~StringListNode();
};
struct MapBase
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    ~MapBase();
};
struct FUN_008538b0 : MapBase
{
    StringListNode owned;
    ResourceView* resource;
    ~FUN_008538b0();
};
// Calls FUN_008538b0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00853880
void* __thiscall FUN_00853880_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_008538b0 *>(this)->FUN_008538b0::~FUN_008538b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Deletes resource, then frees every stored pointer in the map's buckets and in the owned list, walking each linked list.
// @fnv 0x008538b0
FUN_008538b0::~FUN_008538b0()
{
    delete resource;
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        StringListNode* list = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&(list));
        while (list)
        {
            delete *((char **)(new ((void *)(list)) ::Vec3()));
            list = ((::StringListNode *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        }
    }
    StringListNode* list = &owned;
    while (list)
    {
        delete *((char **)(new ((void *)(list)) ::Vec3()));
        list = ((::StringListNode *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
}

// Prepare a dialogue response for the speaker: reset it, fill it from the speaker/topic, then notify.

class B4B10Response;

class B4B10Speaker
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void OnResponseReady(B4B10Response* pkResponse);

    unsigned int GetFormType();
};

class B4B10DialogueManager
{
  public:
};

class B4B10Response
{
  public:
};

void __cdecl B4B10SetupResponse(B4B10Response* pkResponse, B4B10Speaker* pkSpeaker, int iTopic);

class B4B10Dialogue
{
  public:
    void SetupResponse(B4B10Speaker* pkSpeaker, int iTopic, B4B10Response* pkResponse);
};

// Resets and initialises the response from the speaker's voice type, form type and current dialogue ID, then sets the speaker and notifies it.
// @fnv 0x00854b10
void B4B10Dialogue::SetupResponse(B4B10Speaker* pkSpeaker, int iTopic, B4B10Response* pkResponse)
{
    reinterpret_cast<::FUN_00847db0_shell *>((pkResponse))->FUN_00847db0();
    reinterpret_cast<::fnv_00865ad0::BGSSaveFormBuffer *>((pkResponse))->InitFormEntry((unsigned int)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkSpeaker))->FUN_0084e3a0()))), iTopic, pkSpeaker->GetFormType(),
                     reinterpret_cast<::FUN_00851110_shell *>(((*reinterpret_cast<::B4B10DialogueManager * *>(&::DAT_011de134))))->GetConstant27());
    reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((pkResponse))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(pkSpeaker));
    B4B10SetupResponse(pkResponse, pkSpeaker, iTopic);
    pkSpeaker->OnResponseReady(pkResponse);
}

struct SavedBuffer
{
    void* vtable;
    void* data;
    unsigned int capacity;
    unsigned int position;
    unsigned int size;
    void* references;
    unsigned int referenceCount;
    unsigned char version;
    unsigned int flags;
    SavedBuffer();
    ~SavedBuffer();
};
struct SavedDataView
{
    void* data;
};
struct SavedEntry
{
    unsigned int topic;
    SavedDataView buffer;
};
struct SavedEntryMap
{
};
struct BGSSaveLoadGame
{
};
struct SavedStats
{
    void LoadStats();
};
// Iterates saved entries, applying each to stats via FUN_008549b0, then processes indices 0-11 and 1000 through FUN_0084bcd0 and FUN_00854c10.
// @fnv 0x00853b90
void SavedStats::LoadStats()
{
    SavedBuffer map;
    SavedEntryMap* buffer = ((::SavedEntryMap *)(::FUN_00559450((int *)(g_BGSSaveLoadGame))));
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((buffer))->GetFirstPos();
    while (position)
    {
        unsigned int entryId = 0;
        SavedEntry* pEntry = 0;
        reinterpret_cast<::C6b7f20_Map *>((buffer))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(entryId), (void **)&(pEntry));
        if (((void *)(::FUN_00559450((int *)&(pEntry->buffer)))))
        {
            reinterpret_cast<::FUN_008549b0_shell *>(this)->FUN_008549b0(entryId, (unsigned int)(0), reinterpret_cast<::FUN_00849220_shell *>(&(pEntry->buffer))->FUN_00849220(), pEntry->topic, reinterpret_cast<::FUN_008663e0_shell *>(&(pEntry->buffer))->FUN_008663e0(),
                         reinterpret_cast<::FUN_00866450_shell *>(&(pEntry->buffer))->GetAdjustedValue(), 0, reinterpret_cast<::FUN_0084b450_Class *>(&(pEntry->buffer))->FUN_0084b450());
        }
        else
        {
            TESForm* form = ::FUN_004839c0(entryId);
            if (form)
            {
                reinterpret_cast<::B4B10Dialogue *>(this)->SetupResponse((::B4B10Speaker *)(form), pEntry->topic, (::B4B10Response *)(::SavedBuffer *)(&map));
                reinterpret_cast<::FUN_008549b0_shell *>(this)->FUN_008549b0(entryId, (unsigned int)(form), form->FNV_GetFormType(), pEntry->topic, reinterpret_cast<::FUN_00853dc0_shell *>(&(map))->GetDifference(),
                             reinterpret_cast<::FUN_00865b10_shell *>(&(map))->GetValuePlusNine(), ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(&(map))->FUN_0044edb0())), reinterpret_cast<::BGSLoadFormBuffer *>(&(map))->GetVersion());
            }
        }
    }
    for (unsigned int index = 0; index < 12; ++index)
    {
        reinterpret_cast<::FUN_00847db0_shell *>(&(map))->FUN_00847db0();
        if (::FUN_0084bcd0(index, (::BGSSaveFormBuffer *)(::SavedBuffer *)(&map)))
            reinterpret_cast<::FUN_00854c10_Class *>(this)->FUN_00854c10(FUN_00853de0(index), reinterpret_cast<::FUN_00853dc0_shell *>(&(map))->GetDifference(), ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(&(map))->FUN_0044edb0())));
    }
    for (unsigned int index = 1000; index < 1001; ++index)
    {
        reinterpret_cast<::FUN_00847db0_shell *>(&(map))->FUN_00847db0();
        if (::FUN_0084bcd0(index, (::BGSSaveFormBuffer *)(::SavedBuffer *)(&map)))
            reinterpret_cast<::FUN_00854c10_Class *>(this)->FUN_00854c10(FUN_00853de0(index), reinterpret_cast<::FUN_00853dc0_shell *>(&(map))->GetDifference(), ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(&(map))->FUN_0044edb0())));
    }
}

#include <windows.h>
int GameStrcat(char* dst, unsigned int size, const char* src);
int FUN_00ecbf05(const char* path, int mode);

struct BSFile
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
    BSFile(const char* name, int mode, unsigned int bufferSize, bool textMode);
};

struct TextDumpWriter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TextDumpWriter();
    ~TextDumpWriter();
    void WriteBody();
};

// Creates a .txt file from baseName, writes its header and body, then calls ShellExecuteA with the open verb.
// @fnv 0x00853a30
void DumpTextAndOpen(const char* baseName)
{
    TextDumpWriter writer;
    char path[260];
    ::TaskQueueInterface::CopyStringToBuffer(path, 260, baseName);
    GameStrcat(path, 260, ".txt");
    if (FUN_00ecbf05(path, 0) != -1)
        DeleteFileA(path);
    reinterpret_cast<::TESPackage *>(&(writer))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(new BSFile(path, 1, 0x4000, false)));
    reinterpret_cast<::SavedStats *>(&(writer))->LoadStats();
    writer.WriteBody();
    reinterpret_cast<::FUN_008539e0_holder *>(&(writer))->FUN_008539e0();
    ShellExecuteA(0, "open", path, 0, 0, 5);
}

namespace fnv_00853e10 {
void* _fnv_zlib_memset(void*, int, unsigned int);

int xStrcat(char*, unsigned int, const char*);
int xMbsnicmp(const char*, const char*, unsigned int);
struct xTypeName
{
    const char* m_name;
    int m_kPointA, m_kPointB;
};
struct xSizeArg
{
    xSizeArg(int);
    xSizeArg(const xSizeArg&);
    int m_v;
};
struct xSizer
{
    xSizer();
    ~xSizer();
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20;
};
struct xStats
{
    xStats();
    int m_uiItemCount, m_data, m_overhead, m_pDebugAllocator, m_kMinimumCorner, m_kMaximumCorner;
};
struct xLevelHolder
{
};

struct xForm
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual bool IsActorType();
    virtual void v61();
    virtual void v62();
    virtual bool HasLevel();
};

struct xChangeFlags
{
    operator unsigned int();
    unsigned int m_v;
};
struct xChange
{
    unsigned int m_formID;
    xChangeFlags m_flags;
    unsigned int m_8, m_iThirdValue, m_10;
    xForm* m_form;
    unsigned char m_ver;
};
struct xNodeL
{
    int m_kPointA, m_kPointB;
};
struct xMisc
{
    char m_name[0x104];
    unsigned int m_104, m_108;
};
struct xHistory
{
};
struct xSaveLoad
{
};
struct SaveLoadStatsDump
{
    int m_00, m_04, m_08, m_0c;
    xNodeL m_10;
    void FUN_00853e10();
};

// Writes a formatted dump of save/load form stats, misc stats, and save game history via Write.
// @fnv 0x00853e10
void SaveLoadStatsDump::FUN_00853e10()
{
    void* qfTOqo;
    int qsSDDgz;
    xHistory* qSVM;
    int qpTd;
    xNodeL* qvyWyw;
    xSizer qpqRa;
    xStats qdqWL;
    char qHXYKT[0x3e8];
    ::FUN_00406d00(qHXYKT, 0x3e8, "  %-8s %-5s %-8s %3s %-40s  %s\r\n\r\n", "Form ID", "Size", "Flags", "Ver", "Name",
             "Changes");
    reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qHXYKT);
    qfTOqo = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (qfTOqo)
    {
        unsigned int qxQHW;
        xNodeL* qArxcFu;
        xStats qAhbO;
        qxQHW = 0;
        qArxcFu = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(qfTOqo), (unsigned int *)&(qxQHW), (void **)&(qArxcFu));
        ::FUN_00406d00(qHXYKT, 0x3e8, "%ss:\r\n\r\n", (*reinterpret_cast<fnv_00853e10::xTypeName (*)[]>((void *)&::FNV_FormTypeNames))[qxQHW].m_name);
        reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qHXYKT);
        while (qArxcFu)
        {
            xChange* qJDuOZ = (xChange*)*((void **)(new ((void *)(qArxcFu)) ::Vec3()));
            if (qJDuOZ)
            {
                char qpia[0x3e8];
                qpia[0] = *"";
                _fnv_zlib_memset(qpia + 1, 0, sizeof(qpia) - 1);
                xForm* qZWI;
                char qQGWBE[0x3e8];
                int qkJsUdT;
                char qIrY[0x3e8];
                char qdbVTq[0x3e8];
                qZWI = 0;
                qkJsUdT = 0;
                if (qJDuOZ->m_form)
                {
                    reinterpret_cast<::B4B10Dialogue *>(this)->SetupResponse((::B4B10Speaker *)(qJDuOZ->m_form), (*(int *)&(const ::fnv_00853e10::xSizeArg &)(xSizeArg(0))), (::B4B10Response *)(::fnv_00853e10::xSizer *)(&qpqRa));
                    qkJsUdT = reinterpret_cast<::FUN_0084e3a0_Class *>(&(qpqRa))->FUN_0084e3a0();
                    if (qkJsUdT)
                    {
                        ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, "Base");
                        if (qJDuOZ->m_form->IsActorType())
                        {
                            qZWI = qJDuOZ->m_form;
                            if (qZWI->HasLevel())
                            {
                                xForm* qIpA = qZWI;
                                int qXMUYT = -1;
                                if (((::fnv_00853e10::xLevelHolder *)(reinterpret_cast<::BSShaderNoLightingProperty *>((qIpA))->GetBaseTexture())))
                                    qXMUYT = ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_00853e10::xLevelHolder *)(reinterpret_cast<::BSShaderNoLightingProperty *>((qIpA))->GetBaseTexture()))))->FUN_0045cd60()));
                                switch (qXMUYT)
                                {
                                case -1:
                                    ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, "None");
                                    break;
                                case 3:
                                    ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, "Low");
                                    break;
                                case 2:
                                    ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, "Mid Low");
                                    break;
                                case 1:
                                    ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, "Mid High");
                                    break;
                                case 0:
                                    ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, "High");
                                    break;
                                }
                            }
                        }
                        ::FUN_00406d00(qdbVTq, 0x3e8, "%s(%i)", qQGWBE, qkJsUdT);
                        ::FUN_00406d00(qIrY, 0x3e8, "%-25s", qdbVTq);
                        xStrcat(qpia, 0x3e8, qIrY);
                    }
                }
                for (unsigned int qbfQdhM = 0; qbfQdhM < 0x20; qbfQdhM++)
                {
                    unsigned int qAXSCg = 1 << qbfQdhM;
                    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(qJDuOZ->m_flags))->FUN_004280f0(qAXSCg))
                    {
                        ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, ::GetChangeFlagName(qAXSCg, qxQHW, 1));
                        if (qJDuOZ->m_form)
                        {
                            reinterpret_cast<::B4B10Dialogue *>(this)->SetupResponse((::B4B10Speaker *)(qJDuOZ->m_form), (*(int *)&(const ::fnv_00853e10::xSizeArg &)(xSizeArg(qAXSCg))), (::B4B10Response *)(::fnv_00853e10::xSizer *)(&qpqRa));
                            ::FUN_00406d00(qdbVTq, 0x3e8, "%s(%i)", qQGWBE, reinterpret_cast<::FUN_0084e3a0_Class *>(&(qpqRa))->FUN_0084e3a0() - qkJsUdT);
                        }
                        else
                            ::FUN_00406d00(qdbVTq, 0x3e8, "%s", qQGWBE);
                        ::FUN_00406d00(qIrY, 0x3e8, "%-25s", qdbVTq);
                        xStrcat(qpia, 0x3e8, qIrY);
                    }
                }
                ::TaskQueueInterface::CopyStringToBuffer(qQGWBE, 0x3e8, "");
                reinterpret_cast<::FormNameEntry *>((qJDuOZ))->BuildFormName(qQGWBE, 0x3e8);
                ::FUN_00406d00(qHXYKT, 0x3e8, "  %08X %5i %08X %3i %-40s- %s\r\n", qJDuOZ->m_formID, reinterpret_cast<::FUN_008547f0_shell *>((qJDuOZ))->GetSum(),
                         (unsigned int)qJDuOZ->m_flags, qJDuOZ->m_ver, qQGWBE, qpia);
                reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qHXYKT);
            }
            reinterpret_cast<::FUN_00854880_shell *>(&(qAhbO))->AccumulateStats(qJDuOZ->m_8, qJDuOZ->m_iThirdValue, qJDuOZ->m_10);
            reinterpret_cast<::FUN_00854880_shell *>(&(qdqWL))->AccumulateStats(qJDuOZ->m_8, qJDuOZ->m_iThirdValue, qJDuOZ->m_10);
            qArxcFu = ((::fnv_00853e10::xNodeL *)(reinterpret_cast<::Callees *>((qArxcFu))->FUN_00726070()));
        }
        ::FUN_00406d00(
            qHXYKT, 0x3e8,
            "\r\nTotal %s Count: %i  Total %s Size: %i - Data: %i Overhead: %i Debug: %i Min %s Size: %i  Max %s Size: %i  Average %s Size: %.2f\r\n\r\n",
            (*reinterpret_cast<fnv_00853e10::xTypeName (*)[]>((void *)&::FNV_FormTypeNames))[qxQHW].m_name, qAhbO.m_uiItemCount, (*reinterpret_cast<fnv_00853e10::xTypeName (*)[]>((void *)&::FNV_FormTypeNames))[qxQHW].m_name, reinterpret_cast<::FUN_00854900_shell *>(&(qAhbO))->FUN_00854900(), qAhbO.m_data,
            qAhbO.m_overhead, qAhbO.m_pDebugAllocator, (*reinterpret_cast<fnv_00853e10::xTypeName (*)[]>((void *)&::FNV_FormTypeNames))[qxQHW].m_name, qAhbO.m_kMinimumCorner,
            (*reinterpret_cast<fnv_00853e10::xTypeName (*)[]>((void *)&::FNV_FormTypeNames))[qxQHW].m_name, qAhbO.m_kMaximumCorner, (*reinterpret_cast<fnv_00853e10::xTypeName (*)[]>((void *)&::FNV_FormTypeNames))[qxQHW].m_name, reinterpret_cast<::FUN_00854920_shell *>(&(qAhbO))->GetRatio());
        reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qHXYKT);
    }
    ::FUN_00406d00(
        qHXYKT, 0x3e8,
        "\r\nTotal Form Count: %i  Total Form Size: %i - Data: %i Overhead: %i Debug: %i  Min Form Size: %i  Max Form Size: %i  Average Form Size: %.2f\r\n\r\n",
        qdqWL.m_uiItemCount, reinterpret_cast<::FUN_00854900_shell *>(&(qdqWL))->FUN_00854900(), qdqWL.m_data, qdqWL.m_overhead, qdqWL.m_pDebugAllocator,
        qdqWL.m_kMinimumCorner, qdqWL.m_kMaximumCorner, reinterpret_cast<::FUN_00854920_shell *>(&(qdqWL))->GetRatio());
    reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qHXYKT);
    xStats qrEZrs;
    reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80("\r\nMisc Stats:\r\n\r\n");
    qvyWyw = &m_10;
    while (qvyWyw)
    {
        xMisc* qBLsiu = (xMisc*)*((void **)(new ((void *)(qvyWyw)) ::Vec3()));
        if (qBLsiu)
        {
            ::FUN_00406d00(qHXYKT, 0x3e8, "  %8i      %s\r\n", reinterpret_cast<::FUN_00854810_shell *>((qBLsiu))->GetSumOfFields(), qBLsiu);
            reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qHXYKT);
            reinterpret_cast<::FUN_00854880_shell *>(&(qrEZrs))->AccumulateStats(qBLsiu->m_104, 0, qBLsiu->m_108);
        }
        qvyWyw = ((::fnv_00853e10::xNodeL *)(reinterpret_cast<::Callees *>((qvyWyw))->FUN_00726070()));
    }
    ::FUN_00406d00(
        qHXYKT, 0x3e8,
        "\r\nTotal Misc Count: %i  Total Misc Size: %i - Data: %i Overhead: %i Debug: %i  Min Misc Size: %i  Max Misc Size: %i  Average Misc Size: %.2f\r\n\r\n",
        qrEZrs.m_uiItemCount, reinterpret_cast<::FUN_00854900_shell *>(&(qrEZrs))->FUN_00854900(), qrEZrs.m_data, qrEZrs.m_overhead, qrEZrs.m_pDebugAllocator,
        qrEZrs.m_kMinimumCorner, qrEZrs.m_kMaximumCorner, reinterpret_cast<::FUN_00854920_shell *>(&(qrEZrs))->GetRatio());
    reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qHXYKT);
    qSVM = ((::fnv_00853e10::xHistory *)(reinterpret_cast<::BGSTerrainManager *>(((*reinterpret_cast<::fnv_00853e10::xSaveLoad * *>(&::g_BGSSaveLoadGame))))->GetMinLevel()));
    qpTd = ((int)(reinterpret_cast<::FUN_00620b80_shell *>((qSVM))->GetReferenceFlags()));
    qsSDDgz = 0;
    if (qpTd)
    {
        reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80("\r\n\r\nSave Game History:\r\n\r\n");
        for (unsigned int qrUCJDN = 0; qrUCJDN < (unsigned int)qpTd; qrUCJDN++)
        {
            const char* qpydTG = ((const char *)(reinterpret_cast<::FUN_0084e320_Class *>((qSVM))->GetArrayElement(qrUCJDN)));
            int qyFp = 0;
            if (!xMbsnicmp(qpydTG, "***", 3))
                qyFp = 1;
            else if (!xMbsnicmp(qpydTG, "---", 3))
            {
                qyFp = -1;
                qsSDDgz--;
            }
            for (int qhQRuW = 0; qhQRuW < qsSDDgz; qhQRuW++)
                reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80("  ");
            reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80(qyFp ? qpydTG + 3 : qpydTG);
            reinterpret_cast<::FUN_00854b80_class *>(this)->FUN_00854b80("\r\n");
            if (qyFp == 1)
                qsSDDgz++;
        }
    }
}
}  // namespace fnv_00853e10
