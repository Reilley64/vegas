
// src/fallout/ai/combat/combatgroupstrategy.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatgroupstrategy.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/combat_group_fields.h"
#include "fnv/simple_array_item.h"
#include <cstdint>
#include <cctype>
#include <malloc.h>
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/B989700List.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004941c0_shell.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0098a340_shell.h"
#include "fnv/decl/FUN_0098a390_shell.h"
#include "fnv/decl/FUN_0098a410_shell.h"
#include "fnv/decl/FUN_00990500_host.h"
#include "fnv/decl/FUN_00990540_shell.h"
#include "fnv/decl/FUN_009b73b0_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/S006950d0.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_006db840__BSSimpleArray.h"
#include "fnv/decl/fnv_0098a470__FUN_0098a470_shell.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_0098e000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01026000.h"
#include "fnv/symbols_01034000.h"
#include "fnv/symbols_01050000.h"
#include "fnv/symbols_011a4000.h"
struct ArrSI
{
};

struct FUN_00990890_shell
{
    unsigned int FUN_00990890();
};

// @fnv 0x00990890
unsigned int FUN_00990890_shell::FUN_00990890()
{
    return SimpleArraySize((reinterpret_cast<ArrSI*>(this + 0x18)));
}

namespace fnv_00990a60 {
struct ArrSI
{
};

struct FUN_00990a60_shell
{
    unsigned int GetArrFlags();
};

// @fnv 0x00990a60
unsigned int FUN_00990a60_shell::GetArrFlags()
{
    return SimpleArraySize((((ArrSI*)(this + 0x28))));
}
}  // namespace fnv_00990a60

struct FUN_00844160_holder
{
};

struct FUN_00990a80_shell
{
    void ForwardToHolder(int arg);
};

struct FUN_00844160_shell
{
    void FUN_00844160(int state);
public:
    uintptr_t FUN_00844160(unsigned int);
};
// @fnv 0x00990a80
void FUN_00990a80_shell::ForwardToHolder(int arg)
{
    reinterpret_cast<::FUN_00844160_shell *>((((FUN_00844160_holder*)((char*)this + 0x28))))->FUN_00844160(arg);
}

struct FUN_00990aa0_shell
{
    void FUN_00990aa0(int state);
};

void FUN_00844160_shell::FUN_00844160(int state)
{}

// @fnv 0x00990aa0
void FUN_00990aa0_shell::FUN_00990aa0(int state)
{
    ((FUN_00844160_shell*)((char*)this + 0x18))->FUN_00844160(state);
}

struct ActorCombatGroup
{
};

struct MarkerStruct
{
};

struct CombatGroupStrategyFallBack
{
    void FUN_00990bd0(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};

// Iterates over every member of the group and calls SetElementValue with index i and value 2.
// @fnv 0x00990bd0
void CombatGroupStrategyFallBack::FUN_00990bd0(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    unsigned int i = 0;
    for (; i < reinterpret_cast<::FUN_00990890_shell *>((apGroup))->FUN_00990890(); i++)
    {
        reinterpret_cast<::FUN_0098a390_shell *>((apGroup))->SetElementValue((int)i, 2);
    }
}

namespace fnv_00990d30 {
struct ActorCombatGroup
{
};

struct CombatGroupStrategyAmbush
{
    bool FUN_00990d30(ActorCombatGroup*);
};

// Returns true if apGroup's lookup for index 3 returns a non-null value, otherwise false.
// @fnv 0x00990d30
bool CombatGroupStrategyAmbush::FUN_00990d30(ActorCombatGroup* apGroup)
{
    if (reinterpret_cast<::FUN_0098a410_shell *>((apGroup))->FindByValue(3) == 0)
        return false;
    return true;
}
}  // namespace fnv_00990d30

struct FUN_00990480_shell
{
    bool FUN_00990480();
};

// Returns whether the float at offset 0x58 is greater than the float at offset 0x5c.
// @fnv 0x00990480
bool FUN_00990480_shell::FUN_00990480()
{
    return *(float*)((char*)this + 0x58) > *(float*)((char*)this + 0x5c);
}

struct Grp_Call2
{
    bool FUN_009899a0();
};
struct Holder904c0
{
    Grp_Call2* m_pCombatData;
    int _pad;
    int m_iValue;
    unsigned char FUN_009904c0();
};
// If the cached flag is unset, evaluates the held object's check and stores the result; returns whether the cached flag equals 1.
// @fnv 0x009904c0
unsigned char Holder904c0::FUN_009904c0()
{
    if (m_iValue == -1)
        m_iValue = m_pCombatData->FUN_009899a0() != 0;
    return m_iValue == 1;
}

struct FUN_009905a0_shell
{
    void UpdateMinProgress();
};
struct FUN_00990570_shell
{
    unsigned int FUN_00990570();
};
// @fnv 0x00990570
unsigned int FUN_00990570_shell::FUN_00990570()
{
    if (*(unsigned int*)((char*)this + 0x10) == 0x80000000)
        ((FUN_009905a0_shell*)this)->UpdateMinProgress();
    return *(unsigned int*)((char*)this + 0x10);
}

struct DataOps
{
};
struct GroupOps
{
};
struct DummyFallback
{
    bool FUN_00990b70(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};
// @fnv 0x00990b70
bool DummyFallback::FUN_00990b70(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    if (((int)reinterpret_cast<CombatGroupFields*>((((DataOps*)apGroupData)))->unk04) < 2)
        return false;
    if (!reinterpret_cast<::fnv_0098a470::FUN_0098a470_shell *>((((GroupOps*)apGroup)))->FUN_0098a470(0, 30.0f))
        return false;
    if (((double)(reinterpret_cast<::FUN_00990500_host *>((((DataOps*)apGroupData)))->GetCachedValue())) > DAT_01026998)
        return false;
    return true;
}

struct HolderFor410
{
};
struct TargetClass
{
    bool FUN_00990c10(struct ActorCombatGroup*);
};
// Calls FindByValue with 2 on the group and returns true if it succeeds, otherwise false.
// @fnv 0x00990c10
bool TargetClass::FUN_00990c10(struct ActorCombatGroup* apGroup)
{
    if (!((intptr_t)(reinterpret_cast<::FUN_0098a410_shell *>((((HolderFor410*)apGroup)))->FindByValue(2))))
        return false;
    return true;
}

struct CombatGroupStrategyAmbush
{
    void FUN_00990cb0(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};

// @fnv 0x00990cb0
void CombatGroupStrategyAmbush::FUN_00990cb0(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    unsigned int i;
    unsigned int i2;
    unsigned int ifallBackCount4 = reinterpret_cast<::FUN_00990890_shell *>((apGroup))->FUN_00990890() >> 1;
    for (i = 0; i < ifallBackCount4; ++i)
    {
        reinterpret_cast<::FUN_0098a390_shell *>((apGroup))->SetElementValue(i, 2);
    }
    for (i2 = ifallBackCount4; i2 < reinterpret_cast<::FUN_00990890_shell *>((apGroup))->FUN_00990890(); ++i2)
    {
        reinterpret_cast<::FUN_0098a390_shell *>((apGroup))->SetElementValue(i2, 3);
    }
}

struct IntPair
{
    int _0;
    int _4;
};
struct CombatGroupStrategyAdvance
{
    void FUN_00990e70(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};
struct FUN_00990aa0_helper
{
    IntPair* FUN_00990aa0(int);
};
// Iterates the group data's members and calls SetElementValue on the group with each member's _4 value and 4.
// @fnv 0x00990e70
void CombatGroupStrategyAdvance::FUN_00990e70(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    int i;
    IntPair* pmember;
    for (i = 0; i < (int)reinterpret_cast<::FUN_00990890_shell *>((((ActorCombatGroup*)apGroupData)))->FUN_00990890(); i++)
    {
        pmember = ((FUN_00990aa0_helper*)apGroupData)->FUN_00990aa0(i);
        reinterpret_cast<::FUN_0098a390_shell *>((apGroup))->SetElementValue(pmember->_4, 4);
    }
}

namespace fnv_00990ec0 {
struct FUN_0098a410_cls
{
};
struct CombatGroupStrategyAdvance
{
    bool FUN_00990ec0(ActorCombatGroup* apGroup);
};
// Calls FindByValue with 4 on apGroup and returns true if the result is nonzero, false otherwise.
// @fnv 0x00990ec0
bool CombatGroupStrategyAdvance::FUN_00990ec0(ActorCombatGroup* apGroup)
{
    if (((intptr_t)(reinterpret_cast<::FUN_0098a410_shell *>((((FUN_0098a410_cls*)apGroup)))->FindByValue(4))) == 0)
        return false;
    return true;
}
}  // namespace fnv_00990ec0

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char* buffer, unsigned int size, const char* name);
};



// Copies apName into a 260-byte buffer, lowercases it, then compares it against four names and returns the matching index's value or 0.
// @fnv 0x00990250
void* FUN_00990250(const char* apName)
{
    char psearchName[260];
    char* pChar;

    TaskQueueInterface::CopyStringToBuffer(psearchName, 0x104, apName);
    pChar = psearchName;
    while (*pChar)
    {
        *pChar = static_cast<char>(std::toupper(*pChar));
        ++pChar;
    }

    for (unsigned int i = 0; i < 4; ++i)
    {
        if (FUN_004812f0(DAT_011a4ed0[i], psearchName) != 0)
        {
            return FUN_0098e980(i);
        }
    }

    return 0;
}

struct FUN_00990a60_shell
{
};

struct FUN_00990a80_member
{
    IntPair* ForwardToHolder(unsigned int index);
};

struct FUN_00990aa0_member
{
    IntPair* FUN_00990aa0(unsigned int index);
};

struct FUN_00990640_shell
{
};

struct FUN_00990930_shell
{
    void FUN_00990930(ActorCombatGroup* apGroup, MarkerStruct* apGroupData);
};

struct CombatMemberState
{
};
struct MemberController
{
};
struct CombatMemberActor
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual void Reserved111();
    virtual void Reserved112();
    virtual void Reserved113();
    virtual void Reserved114();
    virtual void Reserved115();
    virtual void Reserved116();
    virtual void Reserved117();
    virtual void Reserved118();
    virtual void Reserved119();
    virtual void Reserved120();
    virtual void Reserved121();
    virtual void Reserved122();
    virtual void Reserved123();
    virtual void Reserved124();
    virtual void Reserved125();
    virtual void Reserved126();
    virtual void Reserved127();
    virtual void Reserved128();
    virtual void Reserved129();
    virtual void Reserved130();
    virtual void Reserved131();
    virtual void Reserved132();
    virtual void Reserved133();
    virtual void Reserved134();
    virtual void Reserved135();
    virtual void Reserved136();
    virtual void Reserved137();
    virtual void Reserved138();
    virtual void Reserved139();
    virtual void Reserved140();
    virtual void Reserved141();
    virtual void Reserved142();
    virtual void Reserved143();
    virtual void Reserved144();
    virtual void Reserved145();
    virtual void Reserved146();
    virtual void Reserved147();
    virtual void Reserved148();
    virtual void Reserved149();
    virtual void Reserved150();
    virtual void Reserved151();
    virtual void Reserved152();
    virtual void Reserved153();
    virtual void Reserved154();
    virtual void Reserved155();
    virtual void Reserved156();
    virtual void Reserved157();
    virtual void Reserved158();
    virtual void Reserved159();
    virtual void Reserved160();
    virtual void Reserved161();
    virtual void Reserved162();
    virtual void Reserved163();
    virtual void Reserved164();
    virtual void Reserved165();
    virtual void Reserved166();
    virtual void Reserved167();
    virtual void Reserved168();
    virtual void Reserved169();
    virtual void Reserved170();
    virtual void Reserved171();
    virtual void Reserved172();
    virtual void Reserved173();
    virtual void Reserved174();
    virtual void Reserved175();
    virtual void Reserved176();
    virtual void Reserved177();
    virtual void Reserved178();
    virtual void Reserved179();
    virtual void Reserved180();
    virtual void Reserved181();
    virtual void Reserved182();
    virtual void Reserved183();
    virtual void Reserved184();
    virtual void Reserved185();
    virtual void Reserved186();
    virtual void Reserved187();
    virtual void Reserved188();
    virtual void Reserved189();
    virtual void Reserved190();
    virtual void Reserved191();
    virtual void Reserved192();
    virtual void Reserved193();
    virtual void Reserved194();
    virtual void Reserved195();
    virtual void Reserved196();
    virtual void Reserved197();
    virtual void Reserved198();
    virtual void Reserved199();
    virtual void Reserved200();
    virtual void Reserved201();
    virtual void Reserved202();
    virtual void Reserved203();
    virtual void Reserved204();
    virtual void Reserved205();
    virtual void Reserved206();
    virtual void Reserved207();
    virtual void Reserved208();
    virtual void Reserved209();
    virtual void Reserved210();
    virtual void Reserved211();
    virtual void Reserved212();
    virtual void Reserved213();
    virtual void Reserved214();
    virtual void Reserved215();
    virtual void Reserved216();
    virtual void Reserved217();
    virtual void Reserved218();
    virtual void Reserved219();
    virtual void Reserved220();
    virtual void Reserved221();
    virtual void Reserved222();
    virtual void Reserved223();
    virtual void Reserved224();
    virtual void Reserved225();
    virtual void Reserved226();
    virtual void Reserved227();
    virtual void Reserved228();
    virtual void Reserved229();
    virtual void Reserved230();
    virtual void Reserved231();
    virtual void Reserved232();
    virtual void Reserved233();
    virtual void Reserved234();
    virtual void Reserved235();
    virtual void Reserved236();
    virtual void Reserved237();
    virtual void Reserved238();
    virtual void Reserved239();
    virtual void Reserved240();
    virtual void Reserved241();
    virtual void Reserved242();
    virtual void Reserved243();
    virtual void Reserved244();
    virtual void Reserved245();
    virtual void Reserved246();
    virtual void Reserved247();
    virtual void Reserved248();
    virtual void Reserved249();
    virtual void Reserved250();
    virtual void Reserved251();
    virtual void Reserved252();
    virtual void Reserved253();
    virtual void Reserved254();
    virtual void Reserved255();
    virtual void Reserved256();
    virtual void Reserved257();
    virtual void Reserved258();
    virtual void Reserved259();
    virtual void Reserved260();
    virtual void Reserved261();
    virtual void Reserved262();
    virtual void Reserved263();
    virtual void Reserved264();
    virtual void Reserved265();
    virtual MemberController* GetController();
};
struct GroupMembers
{
};
struct IndexedMember
{
    CombatMemberActor* member;
    unsigned int index;
    IndexedMember(CombatMemberActor*, unsigned int);
};
struct IndexedMemberArray
{
    void* data;
    unsigned int size, capacity, growth;
    IndexedMemberArray();
    ~IndexedMemberArray();
};
struct FUN_00990320
{
    GroupMembers* group;
    unsigned int activeCount;
    int intersectionCount;
    int minimum;
    int maximum;
    float strength;
    IndexedMemberArray normalMembers;
    IndexedMemberArray specialMembers;
    FUN_00990320(GroupMembers*);
};
// @fnv 0x00990320
FUN_00990320::FUN_00990320(GroupMembers* pGroup)
    : group(pGroup), activeCount(0), intersectionCount(-1), minimum(0x7fffffff), maximum(0x80000000), strength(0.0f)
{
    unsigned int count = reinterpret_cast<::FUN_00990890_shell *>((pGroup))->FUN_00990890();
    for (unsigned int index = 0; index < count; ++index)
    {
        CombatMemberActor* aActor = ((::CombatMemberActor *)(reinterpret_cast<::Target *>((pGroup))->GetIntAt(index)));
        CombatMemberState* state = ((::CombatMemberState *)(reinterpret_cast<::InterfaceManager *>((aActor->GetController()))->FUN_00586150()));
        if (!((bool)(reinterpret_cast<::FUN_009b73b0_shell *>((state))->GetByteAtOffset())))
        {
            ++activeCount;
            if (reinterpret_cast<::FUN_00990480_shell *>((state))->FUN_00990480())
                reinterpret_cast<::fnv_006db840::BSSimpleArray *>(&(specialMembers))->InsertAtEnd((const ::NiPoint2 &)((const ::IndexedMember &)(IndexedMember(aActor, index))));
            else
                reinterpret_cast<::fnv_006db840::BSSimpleArray *>(&(normalMembers))->InsertAtEnd((const ::NiPoint2 &)((const ::IndexedMember &)(IndexedMember(aActor, index))));
        }
    }
}

struct ContNode;

struct CombatGroupStrategyFlank
{
    virtual bool CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup);
};

// @fnv 0x009908b0
bool CombatGroupStrategyFlank::CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup)
{
    if (((int)reinterpret_cast<CombatGroupFields*>(((ContNode*)apGroup))->unk04) < 3)
    {
        return false;
    }
    if ((int)reinterpret_cast<FUN_00990890_shell*>(apGroup)->FUN_00990890() < 1)
    {
        return false;
    }
    if (!reinterpret_cast<::fnv_0098a470::FUN_0098a470_shell *>((reinterpret_cast<GroupOps*>(apGroupData)))->FUN_0098a470(2, ::DAT_01018f5c))
    {
        return false;
    }
    if ((int)reinterpret_cast<FUN_00990570_shell*>(apGroup)->FUN_00990570() <= 0)
    {
        return false;
    }
    if (reinterpret_cast<Holder904c0*>(apGroup)->FUN_009904c0())
    {
        return false;
    }
    return true;
}

struct NiPoint4
{
    float x, y, z, w;
};
struct CombatGroupMember
{
};
struct CombatGroupMethods
{
};
struct CombatGroupStrategy
{
    bool FUN_00990ac0(ActorCombatGroup*);
};
// @fnv 0x00990ac0
bool CombatGroupStrategy::FUN_00990ac0(ActorCombatGroup* group)
{
    bool bFound = false;
    unsigned count = reinterpret_cast<::FUN_00990890_shell *>((group))->FUN_00990890();
    for (unsigned index = 0; index < count; ++index)
    {
        if (reinterpret_cast<::FUN_0098a340_shell *>((((CombatGroupMethods*)group)))->FUN_0098a340(index) == 1)
        {
            CombatGroupMember* pData = ((::CombatGroupMember *)(reinterpret_cast<::Target *>((((CombatGroupMethods*)group)))->GetIntAt(index)));
            NiPoint4 position;
            if (((intptr_t)(reinterpret_cast<::B989700List *>((((CombatGroupMethods*)group)))->FindRefInRadius((::B9897F0Point *)(((intptr_t)(reinterpret_cast<::FUN_00575650_Class *>((pData))->FUN_00575650((::FUN_00575650_Result *)(::NiPoint4 *)(&position))))), {}, {}))))
                reinterpret_cast<::FUN_0098a390_shell *>((group))->SetElementValue(index, 0);
            else
                bFound = true;
        }
    }
    if (!bFound)
        return false;
    return true;
}


struct FUN_00990c40_cls
{
    bool FUN_00990c40(intptr_t a1, intptr_t a2);
};

struct FUN_00990c40_arg2
{
};

struct FUN_00990c40_arg1
{
};

// @fnv 0x00990c40
bool FUN_00990c40_cls::FUN_00990c40(intptr_t a1, intptr_t a2)
{
    if (((int)reinterpret_cast<CombatGroupFields*>((((FUN_00990c40_arg2*)a2)))->unk04) < 2)
    {
        return false;
    }
    if (!reinterpret_cast<::fnv_0098a470::FUN_0098a470_shell *>((((FUN_00990c40_arg1*)a1)))->FUN_0098a470(3, ::g_011f2af8_arg1))
    {
        return false;
    }
    if (((int)(reinterpret_cast<::FUN_00990570_shell *>((((FUN_00990c40_arg2*)a2)))->FUN_00990570())) <= 0)
    {
        return false;
    }
    if (reinterpret_cast<::Holder904c0 *>((((FUN_00990c40_arg2*)a2)))->FUN_009904c0() != 0)
    {
        return false;
    }
    return true;
}

struct Vec990d60
{
    float x, y, z;
};
struct Target990d60
{
    virtual void unknown_slot_000();
    virtual void unknown_slot_001();
    virtual void unknown_slot_002();
    virtual void unknown_slot_003();
    virtual void unknown_slot_004();
    virtual void unknown_slot_005();
    virtual void unknown_slot_006();
    virtual void unknown_slot_007();
    virtual void unknown_slot_008();
    virtual void unknown_slot_009();
    virtual void unknown_slot_010();
    virtual void unknown_slot_011();
    virtual void unknown_slot_012();
    virtual void unknown_slot_013();
    virtual void unknown_slot_014();
    virtual void unknown_slot_015();
    virtual void unknown_slot_016();
    virtual void unknown_slot_017();
    virtual void unknown_slot_018();
    virtual void unknown_slot_019();
    virtual void unknown_slot_020();
    virtual void unknown_slot_021();
    virtual void unknown_slot_022();
    virtual void unknown_slot_023();
    virtual void unknown_slot_024();
    virtual void unknown_slot_025();
    virtual void unknown_slot_026();
    virtual void unknown_slot_027();
    virtual void unknown_slot_028();
    virtual void unknown_slot_029();
    virtual void unknown_slot_030();
    virtual void unknown_slot_031();
    virtual void unknown_slot_032();
    virtual void unknown_slot_033();
    virtual void unknown_slot_034();
    virtual void unknown_slot_035();
    virtual void unknown_slot_036();
    virtual void unknown_slot_037();
    virtual void unknown_slot_038();
    virtual void unknown_slot_039();
    virtual void unknown_slot_040();
    virtual void unknown_slot_041();
    virtual void unknown_slot_042();
    virtual void unknown_slot_043();
    virtual void unknown_slot_044();
    virtual void unknown_slot_045();
    virtual void unknown_slot_046();
    virtual void unknown_slot_047();
    virtual void unknown_slot_048();
    virtual void unknown_slot_049();
    virtual void unknown_slot_050();
    virtual void unknown_slot_051();
    virtual void unknown_slot_052();
    virtual void unknown_slot_053();
    virtual void unknown_slot_054();
    virtual void unknown_slot_055();
    virtual void unknown_slot_056();
    virtual void unknown_slot_057();
    virtual void unknown_slot_058();
    virtual void unknown_slot_059();
    virtual void unknown_slot_060();
    virtual void unknown_slot_061();
    virtual void unknown_slot_062();
    virtual void unknown_slot_063();
    virtual void unknown_slot_064();
    virtual void unknown_slot_065();
    virtual void unknown_slot_066();
    virtual void unknown_slot_067();
    virtual void unknown_slot_068();
    virtual void unknown_slot_069();
    virtual void unknown_slot_070();
    virtual void unknown_slot_071();
    virtual void unknown_slot_072();
    virtual void unknown_slot_073();
    virtual void unknown_slot_074();
    virtual void unknown_slot_075();
    virtual void unknown_slot_076();
    virtual void unknown_slot_077();
    virtual void unknown_slot_078();
    virtual void unknown_slot_079();
    virtual void unknown_slot_080();
    virtual void unknown_slot_081();
    virtual void unknown_slot_082();
    virtual void unknown_slot_083();
    virtual void unknown_slot_084();
    virtual void unknown_slot_085();
    virtual void unknown_slot_086();
    virtual void unknown_slot_087();
    virtual void unknown_slot_088();
    virtual void unknown_slot_089();
    virtual void unknown_slot_090();
    virtual void unknown_slot_091();
    virtual void unknown_slot_092();
    virtual void unknown_slot_093();
    virtual void unknown_slot_094();
    virtual void unknown_slot_095();
    virtual void unknown_slot_096();
    virtual void unknown_slot_097();
    virtual void unknown_slot_098();
    virtual void unknown_slot_099();
    virtual void unknown_slot_100();
    virtual void unknown_slot_101();
    virtual void unknown_slot_102();
    virtual void unknown_slot_103();
    virtual void unknown_slot_104();
    virtual void unknown_slot_105();
    virtual void unknown_slot_106();
    virtual void unknown_slot_107();
    virtual void unknown_slot_108();
    virtual void unknown_slot_109();
    virtual void unknown_slot_110();
    virtual void unknown_slot_111();
    virtual void unknown_slot_112();
    virtual void unknown_slot_113();
    virtual void unknown_slot_114();
    virtual void unknown_slot_115();
    virtual void unknown_slot_116();
    virtual void unknown_slot_117();
    virtual void unknown_slot_118();
    virtual void unknown_slot_119();
    virtual void unknown_slot_120();
    virtual void unknown_slot_121();
    virtual void unknown_slot_122();
    virtual void unknown_slot_123();
    virtual void unknown_slot_124();
    virtual Vec990d60* GetTargetValue();
};
struct Handle990d60
{
};
struct Actor990d60
{
    virtual void unknown_slot_000();
    virtual void unknown_slot_001();
    virtual void unknown_slot_002();
    virtual void unknown_slot_003();
    virtual void unknown_slot_004();
    virtual void unknown_slot_005();
    virtual void unknown_slot_006();
    virtual void unknown_slot_007();
    virtual void unknown_slot_008();
    virtual void unknown_slot_009();
    virtual void unknown_slot_010();
    virtual void unknown_slot_011();
    virtual void unknown_slot_012();
    virtual void unknown_slot_013();
    virtual void unknown_slot_014();
    virtual void unknown_slot_015();
    virtual void unknown_slot_016();
    virtual void unknown_slot_017();
    virtual void unknown_slot_018();
    virtual void unknown_slot_019();
    virtual void unknown_slot_020();
    virtual void unknown_slot_021();
    virtual void unknown_slot_022();
    virtual void unknown_slot_023();
    virtual void unknown_slot_024();
    virtual void unknown_slot_025();
    virtual void unknown_slot_026();
    virtual void unknown_slot_027();
    virtual void unknown_slot_028();
    virtual void unknown_slot_029();
    virtual void unknown_slot_030();
    virtual void unknown_slot_031();
    virtual void unknown_slot_032();
    virtual void unknown_slot_033();
    virtual void unknown_slot_034();
    virtual void unknown_slot_035();
    virtual void unknown_slot_036();
    virtual void unknown_slot_037();
    virtual void unknown_slot_038();
    virtual void unknown_slot_039();
    virtual void unknown_slot_040();
    virtual void unknown_slot_041();
    virtual void unknown_slot_042();
    virtual void unknown_slot_043();
    virtual void unknown_slot_044();
    virtual void unknown_slot_045();
    virtual void unknown_slot_046();
    virtual void unknown_slot_047();
    virtual void unknown_slot_048();
    virtual void unknown_slot_049();
    virtual void unknown_slot_050();
    virtual void unknown_slot_051();
    virtual void unknown_slot_052();
    virtual void unknown_slot_053();
    virtual void unknown_slot_054();
    virtual void unknown_slot_055();
    virtual void unknown_slot_056();
    virtual void unknown_slot_057();
    virtual void unknown_slot_058();
    virtual void unknown_slot_059();
    virtual void unknown_slot_060();
    virtual void unknown_slot_061();
    virtual void unknown_slot_062();
    virtual void unknown_slot_063();
    virtual void unknown_slot_064();
    virtual void unknown_slot_065();
    virtual void unknown_slot_066();
    virtual void unknown_slot_067();
    virtual void unknown_slot_068();
    virtual void unknown_slot_069();
    virtual void unknown_slot_070();
    virtual void unknown_slot_071();
    virtual void unknown_slot_072();
    virtual void unknown_slot_073();
    virtual void unknown_slot_074();
    virtual void unknown_slot_075();
    virtual void unknown_slot_076();
    virtual void unknown_slot_077();
    virtual void unknown_slot_078();
    virtual void unknown_slot_079();
    virtual void unknown_slot_080();
    virtual void unknown_slot_081();
    virtual void unknown_slot_082();
    virtual void unknown_slot_083();
    virtual void unknown_slot_084();
    virtual void unknown_slot_085();
    virtual void unknown_slot_086();
    virtual void unknown_slot_087();
    virtual void unknown_slot_088();
    virtual void unknown_slot_089();
    virtual void unknown_slot_090();
    virtual void unknown_slot_091();
    virtual void unknown_slot_092();
    virtual void unknown_slot_093();
    virtual void unknown_slot_094();
    virtual void unknown_slot_095();
    virtual void unknown_slot_096();
    virtual void unknown_slot_097();
    virtual void unknown_slot_098();
    virtual void unknown_slot_099();
    virtual void unknown_slot_100();
    virtual void unknown_slot_101();
    virtual void unknown_slot_102();
    virtual void unknown_slot_103();
    virtual void unknown_slot_104();
    virtual void unknown_slot_105();
    virtual void unknown_slot_106();
    virtual void unknown_slot_107();
    virtual void unknown_slot_108();
    virtual void unknown_slot_109();
    virtual void unknown_slot_110();
    virtual void unknown_slot_111();
    virtual void unknown_slot_112();
    virtual void unknown_slot_113();
    virtual void unknown_slot_114();
    virtual void unknown_slot_115();
    virtual void unknown_slot_116();
    virtual void unknown_slot_117();
    virtual void unknown_slot_118();
    virtual void unknown_slot_119();
    virtual void unknown_slot_120();
    virtual void unknown_slot_121();
    virtual void unknown_slot_122();
    virtual void unknown_slot_123();
    virtual void unknown_slot_124();
    virtual Vec990d60* GetTargetValue();
    virtual void unknown_slot_126();
    virtual void unknown_slot_127();
    virtual void unknown_slot_128();
    virtual void unknown_slot_129();
    virtual void unknown_slot_130();
    virtual void unknown_slot_131();
    virtual void unknown_slot_132();
    virtual void unknown_slot_133();
    virtual void unknown_slot_134();
    virtual void unknown_slot_135();
    virtual void unknown_slot_136();
    virtual void unknown_slot_137();
    virtual void unknown_slot_138();
    virtual void unknown_slot_139();
    virtual void unknown_slot_140();
    virtual void unknown_slot_141();
    virtual void unknown_slot_142();
    virtual void unknown_slot_143();
    virtual void unknown_slot_144();
    virtual void unknown_slot_145();
    virtual void unknown_slot_146();
    virtual void unknown_slot_147();
    virtual void unknown_slot_148();
    virtual void unknown_slot_149();
    virtual void unknown_slot_150();
    virtual void unknown_slot_151();
    virtual void unknown_slot_152();
    virtual void unknown_slot_153();
    virtual void unknown_slot_154();
    virtual void unknown_slot_155();
    virtual void unknown_slot_156();
    virtual void unknown_slot_157();
    virtual void unknown_slot_158();
    virtual void unknown_slot_159();
    virtual void unknown_slot_160();
    virtual void unknown_slot_161();
    virtual void unknown_slot_162();
    virtual void unknown_slot_163();
    virtual void unknown_slot_164();
    virtual void unknown_slot_165();
    virtual void unknown_slot_166();
    virtual void unknown_slot_167();
    virtual void unknown_slot_168();
    virtual void unknown_slot_169();
    virtual void unknown_slot_170();
    virtual void unknown_slot_171();
    virtual void unknown_slot_172();
    virtual void unknown_slot_173();
    virtual void unknown_slot_174();
    virtual void unknown_slot_175();
    virtual void unknown_slot_176();
    virtual void unknown_slot_177();
    virtual void unknown_slot_178();
    virtual void unknown_slot_179();
    virtual void unknown_slot_180();
    virtual void unknown_slot_181();
    virtual void unknown_slot_182();
    virtual void unknown_slot_183();
    virtual void unknown_slot_184();
    virtual void unknown_slot_185();
    virtual void unknown_slot_186();
    virtual void unknown_slot_187();
    virtual void unknown_slot_188();
    virtual void unknown_slot_189();
    virtual void unknown_slot_190();
    virtual void unknown_slot_191();
    virtual void unknown_slot_192();
    virtual void unknown_slot_193();
    virtual void unknown_slot_194();
    virtual void unknown_slot_195();
    virtual void unknown_slot_196();
    virtual void unknown_slot_197();
    virtual void unknown_slot_198();
    virtual void unknown_slot_199();
    virtual void unknown_slot_200();
    virtual void unknown_slot_201();
    virtual void unknown_slot_202();
    virtual void unknown_slot_203();
    virtual void unknown_slot_204();
    virtual void unknown_slot_205();
    virtual void unknown_slot_206();
    virtual void unknown_slot_207();
    virtual void unknown_slot_208();
    virtual void unknown_slot_209();
    virtual void unknown_slot_210();
    virtual void unknown_slot_211();
    virtual void unknown_slot_212();
    virtual void unknown_slot_213();
    virtual void unknown_slot_214();
    virtual void unknown_slot_215();
    virtual void unknown_slot_216();
    virtual void unknown_slot_217();
    virtual void unknown_slot_218();
    virtual void unknown_slot_219();
    virtual void unknown_slot_220();
    virtual void unknown_slot_221();
    virtual void unknown_slot_222();
    virtual void unknown_slot_223();
    virtual void unknown_slot_224();
    virtual void unknown_slot_225();
    virtual void unknown_slot_226();
    virtual void unknown_slot_227();
    virtual void unknown_slot_228();
    virtual void unknown_slot_229();
    virtual void unknown_slot_230();
    virtual void unknown_slot_231();
    virtual void unknown_slot_232();
    virtual void unknown_slot_233();
    virtual void unknown_slot_234();
    virtual void unknown_slot_235();
    virtual void unknown_slot_236();
    virtual void unknown_slot_237();
    virtual void unknown_slot_238();
    virtual void unknown_slot_239();
    virtual void unknown_slot_240();
    virtual void unknown_slot_241();
    virtual void unknown_slot_242();
    virtual void unknown_slot_243();
    virtual void unknown_slot_244();
    virtual void unknown_slot_245();
    virtual void unknown_slot_246();
    virtual void unknown_slot_247();
    virtual void unknown_slot_248();
    virtual void unknown_slot_249();
    virtual void unknown_slot_250();
    virtual void unknown_slot_251();
    virtual void unknown_slot_252();
    virtual void unknown_slot_253();
    virtual void unknown_slot_254();
    virtual void unknown_slot_255();
    virtual void unknown_slot_256();
    virtual void unknown_slot_257();
    virtual void unknown_slot_258();
    virtual void unknown_slot_259();
    virtual void unknown_slot_260();
    virtual void unknown_slot_261();
    virtual void unknown_slot_262();
    virtual void unknown_slot_263();
    virtual void unknown_slot_264();
    virtual void unknown_slot_265();
    virtual Handle990d60* GetTargetHandle();
};
struct Member990d60
{
    Actor990d60* actor;
};
struct Data990d60
{
    Member990d60* FUN_00990aa0(unsigned int);
};
struct Strategy990d60
{
    bool IsGroupTargetsSpread(GroupOps* group, Data990d60* data);
};
// @fnv 0x00990d60
bool Strategy990d60::IsGroupTargetsSpread(GroupOps* pGroupOps, Data990d60* data)
{
    if (((int)(reinterpret_cast<::FUN_00990890_shell *>((data))->FUN_00990890())) < 2)
        return false;
    if (!reinterpret_cast<::fnv_0098a470::FUN_0098a470_shell *>((pGroupOps))->FUN_0098a470(1, ::g_011f2af8_arg1))
        return false;
    if (reinterpret_cast<::FUN_00990540_shell *>((data))->FUN_00990540() <= 0)
        return false;
    unsigned int count = ((int)(reinterpret_cast<::FUN_00990890_shell *>((data))->FUN_00990890()));
    for (unsigned int index = 0; index < count; ++index)
    {
        Member990d60* member9 = data->FUN_00990aa0(index);
        Handle990d60* handle5 = member9->actor->GetTargetHandle();
        Target990d60* target8 = ((::Target990d60 *)(reinterpret_cast<::AlchemyItem *>((handle5))->FUN_004030b0()));
        if (target8)
        {
            Vec990d60 delta = (*(::Vec990d60 *)(reinterpret_cast<::FUN_00439ef0_class *>((member9->actor->GetTargetValue()))->FUN_00439ef0((::NiPoint3 *)(target8->GetTargetValue()), *(const ::NiPoint3 *)nullptr)));
            if (((double)(reinterpret_cast<::TESCombatStyle *>(&(delta))->UpdateCombatStyle())) < DAT_0101ece0)
                return false;
        }
    }
    return true;
}

struct Centroid990640
{
    float x, y, z;
};
struct MemberList990640
{
};
struct Strategy990640
{
    GroupMembers* group;
    unsigned int activeCount;
    int intersectionCount;
    int minimum;
    int maximum;
    float strength;
    MemberList990640 normalMembers;
    void SortMembersByTargetDistance();
};
// @fnv 0x00990930
void FUN_00990930_shell::FUN_00990930(ActorCombatGroup* apGroup, MarkerStruct* apGroupData)
{
    unsigned int irangedMemberCount;
    unsigned int itotalMemberCount;
    float frangedPercentage;
    unsigned int irangedFlankers;
    unsigned int imeleeMemberCount;

    imeleeMemberCount = reinterpret_cast<::fnv_00990a60::FUN_00990a60_shell *>((reinterpret_cast<FUN_00990a60_shell*>(apGroupData)))->GetArrFlags();

    {
        unsigned int i;
        IntPair* pmember;

        for (i = 0; i < imeleeMemberCount; ++i)
        {
            pmember = reinterpret_cast<FUN_00990a80_member*>(apGroupData)->ForwardToHolder(i);
            reinterpret_cast<::FUN_0098a390_shell *>((apGroup))->SetElementValue(pmember->_4, 1);
        }
    }

    irangedMemberCount = reinterpret_cast<::FUN_00990890_shell *>((reinterpret_cast<ActorCombatGroup*>(apGroupData)))->FUN_00990890();
    itotalMemberCount = ((int)reinterpret_cast<CombatGroupFields*>((reinterpret_cast<DataOps*>(apGroupData)))->unk04);
    frangedPercentage = static_cast<float>(irangedMemberCount) / static_cast<float>(itotalMemberCount);
    irangedFlankers = 0;

    if (frangedPercentage > 0.5)
        irangedFlankers = static_cast<unsigned int>((frangedPercentage - 0.5) * irangedMemberCount);

    if (irangedFlankers > 0)
    {
        reinterpret_cast<::Strategy990640 *>((reinterpret_cast<FUN_00990640_shell*>(apGroupData)))->SortMembersByTargetDistance();

        {
            unsigned int i;
            IntPair* pmember;

            for (i = irangedMemberCount - irangedFlankers; i < irangedMemberCount; ++i)
            {
                pmember = reinterpret_cast<FUN_00990aa0_member*>(apGroupData)->FUN_00990aa0(i);
                reinterpret_cast<::FUN_0098a390_shell *>((apGroup))->SetElementValue(pmember->_4, 1);
            }
        }
    }
}
// Computes each member's target value, averages them into a centroid, then selection-sorts members by distance to that centroid.
// @fnv 0x00990640
void Strategy990640::SortMembersByTargetDistance()
{
    // i: member count; a: positions; p: centroid; h: distances.
    unsigned int i = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    Vec990d60* a = (Vec990d60*)_alloca(i * sizeof(Vec990d60));
    Vec990d60 p = (*reinterpret_cast<const ::Vec990d60 *>((void *)&::NiPoint3::ZERO));
    for (unsigned int memberIndex = 0; memberIndex < i; ++memberIndex)
    {
        Member990d60* member = ((::Member990d60 *)(reinterpret_cast<::FUN_00844160_shell *>(&(normalMembers))->FUN_00844160(memberIndex)));
        a[memberIndex] = *member->actor->GetTargetValue();
        reinterpret_cast<::FUN_0063c8a0_shell *>((((Centroid990640*)&p)))->FUN_0063c8a0((void *)(&a[memberIndex]));
    }
    reinterpret_cast<::FUN_004941c0_shell *>((((Centroid990640*)&p)))->ScaleByInverse((float)i);
    float* h = (float*)_alloca(i * sizeof(float));
    for (unsigned int j = 0; j < i; ++j)
        h[j] = ((double)(reinterpret_cast<::TESCombatStyle *>((void *)&(const ::Vec990d60 &)((*(::Vec990d60 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(a[j]))->FUN_00439ef0((::NiPoint3 *)(&p), *(const ::NiPoint3 *)nullptr)))))->UpdateCombatStyle()));
    for (unsigned int k = 0; k < i - 1; ++k)
    {
        unsigned int nearest = k;
        float nearestDistance = h[k];
        for (unsigned int n = k + 1; n < i; ++n)
        {
            if (nearestDistance > h[n])
            {
                nearest = n;
                nearestDistance = h[n];
            }
        }
        if (k != nearest)
        {
            // Save the distance and member while exchanging the pair.
            float p = h[k];
            h[k] = h[nearest];
            h[nearest] = p;
            IntPair j = (*(::IntPair *)(reinterpret_cast<::S006950d0 *>(&(normalMembers))->GetElement(k)));
            (*(::IntPair *)(reinterpret_cast<::S006950d0 *>(&(normalMembers))->GetElement(k))) = (*(::IntPair *)(reinterpret_cast<::S006950d0 *>(&(normalMembers))->GetElement(nearest)));
            (*(::IntPair *)(reinterpret_cast<::S006950d0 *>(&(normalMembers))->GetElement(nearest))) = j;
        }
    }
}

#include "generated/data/fallout/ai/combat/combatgroupstrategy.inc"
