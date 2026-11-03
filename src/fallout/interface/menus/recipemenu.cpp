
// src/fallout/interface/menus/recipemenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/recipemenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/simple_array_item.h"
#include <cstdint>
#include "fnv/simple_list_node_view.h"
#include <new>
#include <cstdlib>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/Description.h"
#include "fnv/decl/FUN_004077e0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006a1b60_Class.h"
#include "fnv/decl/FUN_007185e0_class.h"
#include "fnv/decl/FUN_0071aa60_class.h"
#include "fnv/decl/FUN_007242c0_shell.h"
#include "fnv/decl/FUN_007273f0_shell.h"
#include "fnv/decl/FUN_0072c700_cls.h"
#include "fnv/decl/FUN_0072cba0_cls.h"
#include "fnv/decl/FUN_0072ccd0_cls.h"
#include "fnv/decl/FUN_007312e0_shell.h"
#include "fnv/decl/FUN_00950030_shell.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a03d40_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FlagS.h"
#include "fnv/decl/FlaggedData.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Menu.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/PerkEntryConditionSet.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S8840.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TESWeightForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0046fb20__FUN_0046fb20_shell.h"
#include "fnv/decl/fnv_00576260__FUN_00576260_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00469000.h"
#include "fnv/symbols_00480000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_004d1000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00663000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_00727000.h"
#include "fnv/symbols_00728000.h"
#include "fnv/symbols_00764000.h"
#include "fnv/symbols_007ab000.h"
#include "fnv/symbols_007e8000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01047000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
struct RecipeMenu
{
    int FUN_00726f00();
};

// @fnv 0x00726f00
int RecipeMenu::FUN_00726f00()
{
    return 0x435;
}

struct GlobalObject_0072ce30
{
};

GlobalObject_0072ce30 g_011d8f08;

// @fnv 0x00726f10
GlobalObject_0072ce30* FUN_00726f10()
{
    return &g_011d8f08;
}

struct WeatherEntry;

struct BSSimpleList_WeatherEntry
{
    void Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*)) const;
};

struct FUN_0072b580_shell
{
    int m_auiShapeKeys;
    BSSimpleList_WeatherEntry m_kNode;
    void FUN_0072b580(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};

// Sorts the weather entry list using the given comparison function, then calls FUN_0072c700.
// @fnv 0x0072b580
void FUN_0072b580_shell::FUN_0072b580(int(__cdecl* cmp)(WeatherEntry*, WeatherEntry*))
{
    reinterpret_cast<::ItemChangeList *>((void *)&(m_kNode))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(cmp));
    reinterpret_cast<::FUN_0072c700_cls *>(this)->FUN_0072c700();
}

struct FUN_0072b9c0_shell
{
    void* FUN_0072b9c0(unsigned int flags);
    void FUN_00729a70();
};


struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void* apFirstAddr, unsigned int aiCount);
};

// @fnv 0x0072ba80
void FUN_0072ba80_shell::FUN_0072ba80(void* apFirstAddr, unsigned int aiCount)
{
    for (unsigned int i = 0; i < aiCount; ++i)
    {
    }
}

struct RecipeMenu_00726f20
{
    void* FUN_00726f20(unsigned int flags);
};

extern intptr_t DAT_011d8e90;
extern char DAT_011d8ea4;

struct FUN_00727680_shell
{
    void PopulateChallengeList(int, int);
};

// If abNow is set, calls PopulateChallengeList on DAT_011d8e90 when non-null and clears DAT_011d8ea4; otherwise sets DAT_011d8ea4 to 1.
// @fnv 0x00728a30
void __cdecl FUN_00728a30(bool abNow)
{
    if (abNow)
    {
        if (DAT_011d8e90 != 0)
        {
            reinterpret_cast<FUN_00727680_shell*>(DAT_011d8e90)->PopulateChallengeList(0, 0);
        }
        DAT_011d8ea4 = 0;
    }
    else
    {
        DAT_011d8ea4 = 1;
    }
}

struct FNStub
{
};
// Compares the full names of two WeatherEntry objects via GetFullName and _mbscmp, returning the comparison result.
// @fnv 0x007278c0
int __cdecl CompareWeatherEntryNames(WeatherEntry* apEntryA, WeatherEntry* apEntryB)
{
    const char* pNameA;
    {
        void* v2;
        {
            int r;
            {
                const char* pNameB;
                {
                    void* v1;
                    v1 = *(void**)apEntryA;
                    v2 = *(void**)apEntryB;
                    pNameA = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)v1 + 0x18))))->FUN_00408da0()));
                    pNameB = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)v2 + 0x18))))->FUN_00408da0()));
                    r = 0;
                    r = ::FUN_00469880((void *)((unsigned char const*)pNameA), (void *)((unsigned char const*)pNameB));
                    return r;
                }
            }
        }
    }
}

struct TESChallenge
{
};
struct BSSimpleArray
{
};
extern int DAT_0119fbf4;
// Returns false if DAT_0119fbf4 is -1; otherwise returns true when the challenge's threshold differs from the array element at that index.
// @fnv 0x00728d60
bool IsThresholdDifferent(TESChallenge* apChallenge)
{
    if (DAT_0119fbf4 == -1)
        return false;
    else if (reinterpret_cast<::LowProcess *>((apChallenge))->GetPackageObjectType() != (int)((unsigned int)(SimpleArrayItem<unsigned int>((void *)(((BSSimpleArray*)FUN_00726f10())), DAT_0119fbf4))))
        return true;
    return false;
}

struct FUN_00729970_shell
{
    int m_kPointA;
    intptr_t m_kPointB;
    int m_iThirdValue;
    void FUN_00729970(intptr_t aiParam);
};
// @fnv 0x00729970
void FUN_00729970_shell::FUN_00729970(intptr_t aiParam)
{
    std::qsort((void *)(m_kPointB), m_iThirdValue, 4, (int (*)(const void *, const void *))(aiParam));
}

struct FUN_00729fb0_shell
{
    void BuildMenuEntries();
    void FUN_00729fb0(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
// Sorts the WeatherEntry list at this+4 using cmp, then calls BuildMenuEntries.
// @fnv 0x00729fb0
void FUN_00729fb0_shell::FUN_00729fb0(int(__cdecl* cmp)(WeatherEntry*, WeatherEntry*))
{
    reinterpret_cast<::ItemChangeList *>((void *)(((const BSSimpleList_WeatherEntry*)((char*)this + 4))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(cmp));
    BuildMenuEntries();
}

struct WeatherEntry;
struct BSSimpleList
{
    void Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
struct FUN_0072add0_shell
{
    int m_auiShapeKeys;
    BSSimpleList m_kNode;
    void FUN_0072add0(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
struct FUN_0072c130_shell
{
};
void __cdecl FUN_0072a890(void*);
struct FUN_0072b9f0_shell
{
    void FUN_0072a890();
    void* DestroyIfFlagged(unsigned int flags);
};
void __cdecl FUN_0072b2e0(void*);

struct FUN_0072ba20_shell
{
    void FUN_0072b2e0();
    void* FUN_0072ba20(unsigned int flags);
};

struct FUN_0072ba50_shell
{
    void* m_vt;
    int m_auiShapeKeys;
    void FUN_0072ba50();
};
struct Unk_7879c0
{
    virtual ~Unk_7879c0();
};
struct FUN_00724090_shell
{
    ~FUN_00724090_shell();
};
struct ListX
{
    ~ListX();
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct FUN_00784bf0 : Menu_007a8b10
{
    char m_auiShapeKeys[0x60];
    FUN_00724090_shell m_kPointA;
    char m_pAuxiliaryObject[0x2c];
    Unk_7879c0 m_kPointB;
    char m_pad3[0x2c];
    ListX m_iThirdValue;
    ~FUN_00784bf0();
};
// Destructor that clears the global DAT_011d9fdc flag to 0.
// @fnv 0x00784bf0
FUN_00784bf0::~FUN_00784bf0()
{
    DAT_011d9fdc = 0;
}

struct TGF
{
};
struct VATSMenu
{
};
extern int DAT_011d8f4c;
extern int DAT_011d8f50;
struct FUN_0072bab0_shell
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    int m_pad3;
    TGF* m_tile;
    int GetFilteredCount();
};
// Calls the virtual function at vtable slot 5 with this and the value returned by GetFilteredCount(0) minus one.
// @fnv 0x0072ba50
void FUN_0072ba50_shell::FUN_0072ba50()
{
    ((void(*)(void*, int))(*(int**)this)[5])(this, reinterpret_cast<::FUN_0072bab0_shell *>(this)->GetFilteredCount() - 1);
}
// Returns the VATS menu's count minus the float value read from m_tile for the _num_filtered setting.
// @fnv 0x0072bab0
int FUN_0072bab0_shell::GetFilteredCount()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)(((VATSMenu*)this))) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((m_tile))->GetFloat(numFiltered);
}

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int menuID);
};

extern char DAT_011d8ea5;

struct FUN_00728420_shell
{
    virtual void FUN_00728420_v00() = 0;
    virtual void FUN_00728420_v04() = 0;
    virtual void FUN_00728420_v08() = 0;
    virtual void FUN_00728420_v0c(int value1, int value2) = 0;
    virtual void FUN_00728420_v10(int value1, int value2) = 0;

    bool HandleMenuButton(int aiButton, float afValue);
};

// @fnv 0x00728420
bool FUN_00728420_shell::HandleMenuButton(int aiButton, float afValue)
{
    bool bHandled = false;

    if (InterfaceH::GetSelectedTargetIndex(0x435))
    {
        switch (aiButton)
        {
        case 3:
        case 4:
            this->FUN_00728420_v0c((aiButton - 4) ? 2 : 0, 0);
            bHandled = true;
            break;

        case 14:
            this->FUN_00728420_v10(6, 0);
            DAT_011d8ea5 = 1;
            bHandled = true;
            break;

        case 13:
            this->FUN_00728420_v10(3, 0);
            DAT_011d8ea5 = 0;
            bHandled = true;
            break;

        default:
            break;
        }
    }

    return bHandled;
}

int __cdecl FUN_00727920(void* recipe);

struct FUN_00728c10_entry
{
    char m_auiShapeKeys[4];
    void* m_pRecipe;
};

// @fnv 0x00728c10
int __cdecl CompareRecipes(FUN_00728c10_entry* pLeftEntry, FUN_00728c10_entry* pRightEntry)
{
    int leftName;
    char const* leftCanMake;
    int rightCanMake;
    int rightName;
    char const* result;

    leftCanMake = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(reinterpret_cast<char*>(pLeftEntry->m_pRecipe) + 0x18)))->FUN_00408da0()));
    result = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(reinterpret_cast<char*>(pRightEntry->m_pRecipe) + 0x18)))->FUN_00408da0()));
    rightCanMake = 0;
    rightName = FUN_00727920(pLeftEntry->m_pRecipe);
    leftName = FUN_00727920(pRightEntry->m_pRecipe);

    if ((rightName > 0 && leftName > 0) || (rightName <= 0 && leftName <= 0))
    {
        rightCanMake = ::FUN_00469880((void *)(reinterpret_cast<unsigned char const*>(leftCanMake)),
                               (void *)(reinterpret_cast<unsigned char const*>(result)));
    }
    else if (rightName > 0)
    {
        rightCanMake = -1;
    }
    else if (leftName > 0)
    {
        rightCanMake = 1;
    }
    else
    {
        rightCanMake = ::FUN_00469880((void *)(reinterpret_cast<unsigned char const*>(leftCanMake)),
                               (void *)(reinterpret_cast<unsigned char const*>(result)));
    }

    return rightCanMake;
}

struct FUN_007240c0
{
    intptr_t m_auiShapeKeys;
    FUN_007240c0();
};

FUN_007240c0::FUN_007240c0()
{}

struct SL
{
    int m_iWordAt00;
    int m_iWordAt04;

    SL();
    ~SL();
};

SL::SL()
{}

SL::~SL()
{}

struct TESQuest;
struct Tile;

template <class T> struct ListBox;

template <> struct ListBox<TESQuest*>
{
};

extern void* DAT_01070638[];


struct FUN_0072b210 : public FUN_007240c0, public SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_0072b210();
};

// Initialises the object's vtable and zeroes its fields, clears the selected tile, then calls AddToHeadList on this.
// @fnv 0x0072b210
FUN_0072b210::FUN_0072b210()
{
    reinterpret_cast<void**>(this)[0] = DAT_01070638;
    m_14 = 0;
    m_10 = 0;
    m_0c = 0;
    m_18 = 0;
    m_2c = 0;
    m_1c = 0;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;

    reinterpret_cast<::FlagS *>((reinterpret_cast<ListBox<TESQuest*>*>(this)))->FUN_007a1950((std::uintptr_t)((Tile*)0), true);
    ::AddToHeadList((int *)(void *)(this));
}

struct Tile
{
public:
    void Set(int, int);
public:
    void Set(int, unsigned int);
public:
    bool GetSpeechChallengeFailure();
public:
    static float GetInterfaceScale();
};

struct FUN_0072bc30_shell
{
    int m_auiShapeKeys[3];
    Tile* m_tile;

    bool FUN_0072bc30();
};

// Returns true if m_tile is set and its enabled check passes for the cached "_enabled" trait index.
// @fnv 0x0072bc30
bool FUN_0072bc30_shell::FUN_0072bc30()
{
    static int trait = ::FUN_00a00940("_enabled", -1);

    return m_tile && reinterpret_cast<::FUN_00a01230_shell *>((m_tile))->IsTraitNonZero(trait);
}

struct GameTimerRecord
{
};

struct Tile_Set_shell
{
};

struct FUN_00728a70_shell
{
    void FUN_00728a70();
};

void __cdecl FUN_005330e0(float& value, float minimum, float maximum);

extern float DAT_0106f498;
extern float DAT_0106f49c;
extern unsigned char DAT_0119fbf0;
extern unsigned char DAT_011d8ea6;
extern Tile* DAT_011d8eac;
extern Tile* DAT_011d8eb0;
extern float DAT_011d8eb8;
extern unsigned int DAT_011d8ebc;

GameTimerRecord g_timeGlobal;

// @fnv 0x00728a70
void FUN_00728a70_shell::FUN_00728a70()
{
    if ((unsigned char)DAT_011d8ea4 == 1)
        FUN_00728a30(true);

    if (DAT_0119fbf0)
    {
        unsigned int deltaTime;
        unsigned int brightnessValue;
        float stepValue = DAT_0106f49c;
        float currentValue = DAT_0106f498;
        float maximumValue = 0.25f;
        float minimumValue = DAT_011d8eb8;
        float currentTime;

        FUN_005330e0(minimumValue, 0.0f, 255.0f);
        currentTime = 255.0 - minimumValue;
        FUN_005330e0(currentTime, 0.0f, 255.0f);

        if (DAT_011d8eb0 != 0 && DAT_011d8eac != 0)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<Tile_Set_shell*>(DAT_011d8eb0)))->FUN_00a012d0(4009, currentTime, true);
            reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<Tile_Set_shell*>(DAT_011d8eac)))->FUN_00a012d0(4009, minimumValue, true);
        }

        deltaTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&(g_timeGlobal))->FUN_00825c00();
        brightnessValue = deltaTime - DAT_011d8ebc;
        DAT_011d8ebc = deltaTime;

        if (DAT_011d8ea6)
            DAT_011d8eb8 -= brightnessValue * maximumValue;
        else
            DAT_011d8eb8 += brightnessValue * maximumValue;

        FUN_005330e0(DAT_011d8eb8, currentValue, stepValue);

        if (DAT_011d8eb8 >= stepValue)
            DAT_011d8ea6 = 1;
        if (DAT_011d8eb8 <= currentValue)
            DAT_011d8ea6 = 0;
    }
}

struct RecipeBase_b4821
{
    virtual ~RecipeBase_b4821();
};

struct SubA_b4821
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
    ~SubA_b4821();
};

struct SubB_b4821
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
    ~SubB_b4821();
};

struct SubC_b4821
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~SubC_b4821();
};

struct GlobalHolder_b4821
{
};

extern intptr_t DAT_011d8e90;

struct FUN_00726f50_cls : RecipeBase_b4821
{
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
    SubA_b4821 m_6c;
    SubB_b4821 m_a0;
    SubC_b4821 m_d0;
    virtual ~FUN_00726f50_cls();
};
// @fnv 0x00726f20
void* RecipeMenu_00726f20::FUN_00726f20(unsigned int flags)
{
    reinterpret_cast<::FUN_00726f50_cls *>(this)->FUN_00726f50_cls::~FUN_00726f50_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls FUN_0046fb20 on DAT_011c3f2c and sets DAT_011d8e90 to 0 during destruction.
// @fnv 0x00726f50
FUN_00726f50_cls::~FUN_00726f50_cls()
{
    reinterpret_cast<::fnv_0046fb20::FUN_0046fb20_shell *>(((*reinterpret_cast<::GlobalHolder_b4821 * *>(&::g_dataHandler))))->FUN_0046fb20();
    DAT_011d8e90 = 0;
}

struct FNVVirtualTarget
{
    bool(** vtable)(FNVVirtualTarget*, int);
};
struct FNVAuxController
{
};
extern intptr_t DAT_011d8e90;
struct FNVMenuAction
{
    void FUN_00700320(int id, int value);
};
struct FNVRecipeMenu
{
    int field00;
    FNVMenuAction* action;
};

// @fnv 0x00727430
void __cdecl FUN_00727430()
{
    if (DAT_011d8e90 != 0)
    {
        FNVVirtualTarget* target = ((::FNVVirtualTarget *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer))))->GetBaseTexture()));
        if (target->vtable[0x474 / 4](target, 1))
        {
            reinterpret_cast<::FUN_00950030_shell *>(((*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer))))->FUN_00950030();
        }

        intptr_t value = 0;
        ::StartDialogueForTopic((::TESTopic *)(value));
        reinterpret_cast<::Tile *>((((FNVRecipeMenu*)DAT_011d8e90)->action))->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((((FNVRecipeMenu*)DAT_011d8e90)))->FUN_00a1d910();
    }
}

extern char DAT_010705d4;

struct FUN_007299a0 : FUN_007240c0, SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_007299a0();
};

// Initializes the object's vtable pointer and zeroes its integer, short and float members, then calls FUN_007a1950(0, 1) and AddToHeadList.
// @fnv 0x007299a0
FUN_007299a0::FUN_007299a0()
{
    *(void**)this = &DAT_010705d4;
    this->m_14 = 0;
    this->m_10 = 0;
    this->m_0c = 0;
    this->m_18 = 0;
    this->m_2c = 0;
    this->m_1c = 0;
    this->m_28 = 0.0f;
    this->m_24 = 0.0f;
    this->m_20 = 0.0f;
    reinterpret_cast<::FlagS *>((this))->FUN_007a1950(0, 1);
    ::AddToHeadList((int *)(void *)(this));
}

struct RecipeEntry;
struct MenuNode
{
    int FUN_00a00f30(int key);
    void FUN_00700320(int key, int value);
    void FUN_00a01350(int key, int value, int flags);
};

struct RecipeEntry
{
    int m_iResultCode;
    int m_item;
    int m_data;
    RecipeEntry(RecipeEntry* parent, intptr_t* selection);
    int FUN_00a00f30(int key);
    void FUN_00700320(int key, int value);
    void FUN_00a01350(int key, int value, int flags);
};

struct RecipeList
{
    int m_pHeadNode;
    int m_last;
};


struct RecipePanel
{
    int m_iValueAtOffset0C;
    RecipeList m_recipes;
    MenuNode* m_parent;
    int m_unused10;
    int m_unused14;
    int m_defaultItem;
    unsigned short m_nextIndex;
    unsigned short m_flags;
    int m_updateCounter;
    int m_uiContentCount;
    int m_lastAction;

    RecipeEntry* FUN_00729ae0(intptr_t selection, intptr_t updateChoice, intptr_t aiRecipeIndex, int parentId);
};

struct Item
{
};

struct Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Item* current;
    bool SetCurrentItem(Item* input);
};

extern void* DAT_01070610[];

struct FUN_0072a7c0 : FUN_007240c0, SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_0072a7c0();
};

// @fnv 0x0072a7c0
FUN_0072a7c0::FUN_0072a7c0() : FUN_007240c0(), SL()
{
    m_auiShapeKeys = reinterpret_cast<intptr_t>(DAT_01070610);
    m_14 = 0;
    m_10 = 0;
    m_0c = 0;
    m_18 = 0;
    m_2c = 0;
    m_1c = 0;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, 1);
    ::AddToHeadList((int *)(void *)(this));
}

struct Member_72a890
{
    ~Member_72a890();
    int unk00;
};


class FUN_0072a890_cls
{
  public:
    virtual ~FUN_0072a890_cls();
    Member_72a890 m_04;
};
// Calls FUN_0072a890, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0072b9f0
void* FUN_0072b9f0_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0072a890_cls *>(this)->FUN_0072a890_cls::~FUN_0072a890_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct SelectedOption
{
};

struct SelectionManager
{
    void* vtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    SelectedOption* selectedOption;

    bool FUN_0072c7d0();
    void FUN_0072c880();
    bool FUN_0072b5b0(SelectedOption* option);
};

// @fnv 0x0072b5b0
bool SelectionManager::FUN_0072b5b0(SelectedOption* option)
{
    if (FUN_0072c7d0() && (!option || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((void *)(option)) && reinterpret_cast<::FUN_00a01230_shell *>((option))->IsTraitNonZero((int)(((::FUN_00a00940(&(*reinterpret_cast<char *>((void *)&::kListBoxEnabled)), -1))))))))
    {
        selectedOption = option;
        FUN_0072c880();
        return true;
    }
    else
    {
        return false;
    }
}

struct MenuEntryItem
{
    void FUN_00700320(int action, unsigned int index);
};
struct MenuEntry
{
    MenuEntryItem* m_item;
    int m_unknown04;
    unsigned char m_disabled;
};
struct EntryNode
{
    int m_data;
    int m_next;
};
struct MenuBody
{
    int m_kHeader;
    EntryNode m_entries;
    int m_unknown0c;
    int m_unknown10;
    int m_unknown14;
    int m_unknown18;
    unsigned short m_uiItemCount;
    unsigned short m_unknown1e;
    float m_uiFilterValue;
};
struct Target_b9223
{
};

struct Inner_b9223
{
    intptr_t m_00;
    int m_04;
    unsigned char m_08;
};

struct Node_b9223
{
};

struct FUN_0072c130_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    float m_20;

    void ProcessSlots();
};
// Sorts the list at offset 4 using the given comparator, then calls ProcessSlots on this object.
// @fnv 0x0072add0
void FUN_0072add0_shell::FUN_0072add0(int(__cdecl* cmp)(WeatherEntry*, WeatherEntry*))
{
    reinterpret_cast<::ItemChangeList *>(((&this->m_kNode)))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(cmp));
    reinterpret_cast<::FUN_0072c130_cls *>((((FUN_0072c130_shell*)this)))->ProcessSlots();
}

namespace fnv_0072c200 {

struct TileValueChecker
{
};

struct MenuTileControl
{
    int menuID;
    int state;
    int selected;
    TileValueChecker* tile;

    bool FUN_0072c200();
};

// Returns true if tile is non-null and its checker accepts the cached value obtained from FUN_00a00940.
// @fnv 0x0072c200
bool MenuTileControl::FUN_0072c200()
{
    static void* cachedValue = ((void *)(::FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxEnabled)), -1)));
    return tile != 0 && reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero((intptr_t)(cachedValue));
}
}  // namespace fnv_0072c200

struct TileStub
{
};


struct ScrollBarHelper
{
    int unk00;
    int unk04;
    int unk08;
    TileStub* m_tile;
    int unk10;
    TileStub* m_countTile;
    int unk18;
    int unk1c;
    float m_height;

    void FUN_0072c5d0();
};


// Computes the scroll step from the tile's visible value and m_height, sets the _scroll_delta float and the _number_of_items count on the tiles.
// @fnv 0x0072c5d0
void ScrollBarHelper::FUN_0072c5d0()
{
    if (m_tile)
    {
        float visibleVal = reinterpret_cast<::TileListBoxCalls *>((m_tile))->GetFloat(0xfb0);
        int count = 1;
        if (m_height > 0 && visibleVal > 0)
        {
            if (m_height > visibleVal)
            {
                count = ::FUN_00647b70((int)::FUN_004e4430(((unsigned int)(reinterpret_cast<::FUN_0072ccd0_cls *>(this)->FUN_0072ccd0())) * (m_height - visibleVal) / m_height) + 1, 2);
            }
            if (count > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((m_tile))->FUN_00a012d0(::FUN_00a01860("_scroll_delta"), (m_height - visibleVal) / (count - 1), true);
            }
        }
        if (m_countTile)
        {
            reinterpret_cast<::Tile *>((m_countTile))->Set(::FUN_00a01860("_number_of_items"), count);
        }
    }
}

namespace fnv_0072c7d0 {


class B2C7D0Tile
{
  public:
};

class B2C7D0Menu
{
  public:
    int unk00;
    int unk04;
    int unk08;
    B2C7D0Tile* m_pkTile;
    bool FUN_0072c7d0();
};

// Returns true when m_pkTile exists and its GetBool returns true for the cached list-box-enabled trait index.
// @fnv 0x0072c7d0
bool B2C7D0Menu::FUN_0072c7d0()
{
    static int s_iEnabled = ::FUN_00a00940(kListBoxEnabled, -1);
    return m_pkTile && reinterpret_cast<::FUN_00a01230_shell *>((m_pkTile))->IsTraitNonZero(s_iEnabled);
}
}  // namespace fnv_0072c7d0


struct CMForm;
struct CMTile
{
};

struct CMTileRef
{
    CMTile** Get();
};

struct CMItem
{
    int unk00;
    CMTileRef kTile;
};

struct CMConditions
{
};

struct CMCounter
{
};

struct CMCounterList
{
};

struct CMFullName
{
};

struct CMChallenge
{
    int unk00[6];
    CMFullName kFullName;

};

struct CMChallengeList
{
    CMChallenge* pItem;
    CMChallengeList* pNext;

    bool IsEmpty();
};

struct CMDataHandler
{
};

struct CMPlayer
{
    int unk00[0x18];
    intptr_t iRef60;
};

struct CMFormArray
{
    unsigned int Find(CMForm*& arItem, unsigned int auiStart,
                      bool(__cdecl* apfnCompare)(CMForm* const&, CMForm* const&));
};

struct CMListBox
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Sort(int(__cdecl* apfnCompare)(void*, void*));

};

struct CMSorter
{
    void Sort(int(__cdecl* apfnCompare)(void*, void*));
};


extern CMPlayer* g_pCMPlayer;
extern CMSorter g_kCMSorter;

struct CMMenu
{
    int unk00[0x1b];
    CMListBox kList;

    void PopulateChallengeList(int aiUnused, int aiType);
};

// @fnv 0x00727680
void CMMenu::PopulateChallengeList(int aiUnused, int aiType)
{
    int iType8;
    CMChallengeList* pIter6;
    CMChallenge* pChallenge6;
    int iCount8;
    intptr_t iChallengeType2;
    CMForm* pForm4;
    CMItem* pItem;
    char cBuffer[256];

    iType8 = aiType;
    pIter6 = ((::CMChallengeList *)(reinterpret_cast<::FUN_004077e0_shell *>(((*reinterpret_cast<::CMDataHandler * *>(&::g_dataHandler))))->FUN_004077e0()));
    pChallenge6 = 0;
    iCount8 = 0;
    while (pIter6 && !pIter6->IsEmpty())
    {
        pChallenge6 = *((::CMChallenge **)(&reinterpret_cast<::SimpleListNodeView*>(pIter6)->m_item));
        pIter6 = ((::CMChallengeList *)(reinterpret_cast<::Callees *>((pIter6))->FUN_00726070()));
        iChallengeType2 = ((intptr_t)(reinterpret_cast<::FUN_006a1b60_Class *>((pChallenge6))->GetField54()));
        if (iType8 && iType8 != iChallengeType2)
            continue;
        if (reinterpret_cast<::PerkEntryConditionSet *>((((::CMConditions *)(::FUN_006a9540((char *)(pChallenge6))))))->ContainsTrait((::TESObjectREFR *)(g_pCMPlayer->iRef60), (::TESObjectREFR *)(0)))
        {
            pForm4 = ((::CMForm *)(reinterpret_cast<::LowProcess *>((pChallenge6))->GetPackageObjectType()));
            if (pForm4 && ((::CMFormArray *)(::FUN_00726f10()))->Find(pForm4, 0, ((bool (&)(CMForm *const &, CMForm *const &))::FUN_009a3830)) >= ((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((::CMFormArray *)(::FUN_00726f10()))))->GetName())))
            {
                reinterpret_cast<::FUN_00438690 *>((((::CMFormArray *)(::FUN_00726f10()))))->FUN_007cb2e0((unsigned int *)&(pForm4));
                iCount8++;
            }
            if (*((::CMCounter **)(&reinterpret_cast<::SimpleListNodeView*>(((::CMCounterList *)(reinterpret_cast<::FUN_005d43c0_ *>((pChallenge6))->FUN_005d43c0())))->m_item)) && ((unsigned int)(::FUN_00559450((int *)((*((::CMCounter **)(&reinterpret_cast<::SimpleListNodeView*>(((::CMCounterList *)(reinterpret_cast<::FUN_005d43c0_ *>((pChallenge6))->FUN_005d43c0())))->m_item))))))) > 1)
                ::FUN_00406d00(cBuffer, 256, "%s (%d)", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pChallenge6->kFullName))->FUN_00408da0())),
                          ((unsigned int)(::FUN_00559450((int *)((*((::CMCounter **)(&reinterpret_cast<::SimpleListNodeView*>(((::CMCounterList *)(reinterpret_cast<::FUN_005d43c0_ *>((pChallenge6))->FUN_005d43c0())))->m_item))))))));
            else
                ::FUN_00406d00(cBuffer, 256, "%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pChallenge6->kFullName))->FUN_00408da0())));
            pItem = ((::CMItem *)(reinterpret_cast<::RecipePanel *>(&(kList))->FUN_00729ae0((intptr_t)(pChallenge6), (intptr_t)(cBuffer), 0, 0)));
            if (!::FUN_00727920(pChallenge6))
                reinterpret_cast<::Tile *>(((*((::CMTile **)(reinterpret_cast<::InventoryStackRecord *>(&(pItem->kTile))->GetPayloadAddress())))))->Set(0xfa9, 0x7f);
            else
                reinterpret_cast<::Tile *>(((*((::CMTile **)(reinterpret_cast<::InventoryStackRecord *>(&(pItem->kTile))->GetPayloadAddress())))))->Set(0xfa9, 0xff);
        }
    }
    kList.Sort(((int (&)(void *, void *))::CompareRecipes));
    reinterpret_cast<::FUN_00729970_shell *>(&(g_kCMSorter))->FUN_00729970((intptr_t)(((int (&)(void *, void *))::CompareWeatherEntryNames)));
}

extern char DAT_010705d4;

struct FUN_00729d80_shell
{
};

struct FUN_00729a70
{
    ListX m_kNode;
    virtual ~FUN_00729a70();
};
// Calls FUN_00729a70, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0072b9c0
void* FUN_0072b9c0_shell::FUN_0072b9c0(unsigned int flags)
{
    reinterpret_cast<::FUN_00729a70 *>(this)->FUN_00729a70::~FUN_00729a70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct OwnedItem49
{
    virtual ~OwnedItem49();
};
struct FUN_004459e0
{
    ~FUN_004459e0();
};
struct Pair49
{
    OwnedItem49* item;
    FUN_004459e0* extra;
};
struct FUN_004702f0
{
    ~FUN_004702f0();
};
struct Tile49
{
};
extern unsigned char DAT_011d8909;
struct List49
{
    int context;
    Pair49* first;
    FUN_004702f0* nodes;
    Tile49* tile;
    int selected;
    int field14;
    int field18;
    unsigned short count;
    unsigned short field1e;
    float value;
    void ClearList();
};
struct LBTile
{
};


struct LBItem
{
    LBTile* pTile;
    void* pObject;
    bool m_bFiltered;
};

struct LBList
{
    LBItem* pItem;
    LBList* pNext;

    LBItem*& Item();
};

struct LBBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual LBTile* GetTileByIndex(int aiIndex, bool abFlag);
};

struct LBListBox : LBBase, LBList
{
    LBTile* pParentTile;
    LBTile* pSelected;
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float fScroll;

    LBTile* FUN_0072ba50();
    void ApplyFilter(bool(__cdecl* apFilter)(void*));
};

struct TileX
{
};

struct ListItemX
{
    TileX* tile;
};
struct ListNodeX
{
    ListItemX* m_item;
    ListNodeX* m_next;
};
struct ListBoxBaseX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual TileX* GetTileByIndex(int index, bool flag);
};
struct ListBoxX : ListBoxBaseX, ListNodeX
{
    TileX* m_0c;
    TileX* m_10;
    int m_14;
    int m_18;
    unsigned short m_1c;

    TileX* GetNextEnabledTile(int aiKey);
};

// @fnv 0x0072a2c0
TileX* ListBoxX::GetNextEnabledTile(int aiKey)
{
    TileX* result2 = 0;
    int delta8 = 0;
    switch (aiKey)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 = m_0c ? (int)::InventoryStackRecord::RoundToNearestStep(
                            -reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                      : 0;
        break;
    case 16:
        delta8 = m_0c ? (int)::InventoryStackRecord::RoundToNearestStep(
                            reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                      : 0;
        break;
    }
    if (reinterpret_cast<::FUN_0072bc30_shell *>(this)->FUN_0072bc30() && delta8 && m_1c)
    {
        int idxTmp;
        int aMaxIdx = m_1c - 1;
        if (m_10)
        {
            int cur = (int)reinterpret_cast<::TileListBoxCalls *>((m_10))->GetFloat(0xfac);
            if ((idxTmp = cur + delta8) < 0)
                idxTmp = 0;
            else if (idxTmp > aMaxIdx)
                idxTmp = aMaxIdx;
        }
        else if (delta8 > 0)
        {
            idxTmp = 0;
        }
        else
        {
            idxTmp = aMaxIdx;
        }
        while (1)
        {
            ListNodeX* node;
            for (node = this; !result2 && node && ((::ListItemX *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)); node = ((::ListNodeX *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((::ListItemX *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->tile))->GetFloat(0xfac) == idxTmp)
                    result2 = ((::ListItemX *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->tile;
            }
            if (result2 && !reinterpret_cast<::FUN_00a01230_shell *>((result2))->IsTraitNonZero(::FUN_00a00940("_enabled", -1)))
            {
                result2 = 0;
                if (delta8 > 0 && ++idxTmp > aMaxIdx)
                {
                    idxTmp = aMaxIdx - 1;
                    while ((!result2 || !reinterpret_cast<::FUN_00a01230_shell *>((result2))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) && idxTmp >= 0)
                        result2 = GetTileByIndex(idxTmp--, false);
                    break;
                }
                else if (delta8 < 0 && --idxTmp < 0)
                {
                    idxTmp = 1;
                    while ((!result2 || !reinterpret_cast<::FUN_00a01230_shell *>((result2))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) && idxTmp <= aMaxIdx)
                        result2 = GetTileByIndex(idxTmp++, false);
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return result2 != m_10 ? result2 : 0;
}

struct SelectionTile;
struct SelectionMenu
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void HandleClick(int, SelectionTile*);
};
struct SelectionMenuLink
{
};
struct SelectionTile
{
};
struct SelectionInterface
{
};
struct SelectionList
{
    virtual void SetSelected(SelectionTile*);
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual SelectionTile* GetTile(unsigned int);
    int unk04;
    int unk08;
    SelectionTile* container;
    int unk10;
    SelectionTile* scrollBar;
    int unk18;
    short unk1c;
    short unk1e;
    float unk20;
    float storedIndex;
    float storedScroll;
    void UpdateSelection(bool);
};
// Updates the scroll bar value, selects the tile at the stored index, notifies the interface, and handles a click when not in a certain state.
// @fnv 0x0072a660
void SelectionList::UpdateSelection(bool abNotify)
{
    SelectionTile* selected = 0;
    if (container && scrollBar)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((scrollBar))->FUN_00a012d0(FUN_00a01860("_current_value"), storedScroll, false);
        reinterpret_cast<::FUN_00a01290_shell *>((scrollBar))->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
        selected = GetTile((unsigned int)FUN_0040ebd0(storedIndex, (float)(((unsigned int)(reinterpret_cast<::FUN_0072bab0_shell *>(this)->GetFilteredCount())) - 1.0)));
        reinterpret_cast<::FocusManager *>((((::SelectionInterface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00715860((::FocusTile *)(selected), 0xfc3, abNotify);
        SetSelected(selected);
        if (!FUN_004b71d0())
        {
            if (selected)
            {

                ((::SelectionMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((((::SelectionMenuLink *)(reinterpret_cast<::FUN_00a03d40_shell *>((container))->FUN_00a03d40()))))->FUN_00a03c90()))->HandleClick((int)reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfaa), selected);
            }
            SetSelected(0);
        }
    }
}

struct FUN_007a62e0
{
    int m_iResultCode;
    int m_item;
    int m_data;
    FUN_007a62e0(RecipeEntry*, intptr_t*);
};
struct EntryList515
{
    int first;
    int last;
};
struct Panel515
{
    int context;
    EntryList515 entries;
    MenuNode* parent;
    int unknown10;
    int unknown14;
    int defaultItem;
    unsigned short nextIndex;
    unsigned short flags;
    RecipeEntry* FUN_0072a900(intptr_t selection, intptr_t choice, intptr_t aiRecipeIndex, int parentId);
};
// @fnv 0x0072a900
RecipeEntry* Panel515::FUN_0072a900(intptr_t selection, intptr_t choice, intptr_t aiRecipeIndex, int parentId)
{
    if (parent && (defaultItem || parentId))
    {
        RecipeEntry* entry = ((::RecipeEntry *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::MenuNode *)(reinterpret_cast<::FUN_00a03c90_shell *>((parent))->FUN_00a03c90()))))->FUN_00a1ddb0({}, {}, {})));
        if (!((std::intptr_t)(reinterpret_cast<::FUN_00a00f30_shell *>((entry))->FUN_00a00f30(0xfaa))))
            reinterpret_cast<::Tile *>((entry))->Set(0xfaa, -1);
        if (choice)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((entry))->FUN_00a01350(0xfc4, (char *)(choice), 1);
        if (aiRecipeIndex)
        {
            reinterpret_cast<::FUN_00470440 *>(&(entries))->FUN_007a7eb0((::BGSPerkEntry *)(::FUN_007a62e0 *)(new FUN_007a62e0(entry, &selection)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(aiRecipeIndex));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_0072c130_cls *>(this)->ProcessSlots();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(entries))->FUN_00905820((void *)&(const ::FUN_007a62e0 *const &)(new FUN_007a62e0(entry, &selection)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(entry));
                reinterpret_cast<::ScrollBarHelper *>(this)->FUN_0072c5d0();
            }
            reinterpret_cast<::Tile *>((entry))->Set(0xfac, nextIndex++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat((int)((::FUN_00a00940(&(*reinterpret_cast<char *>((void *)&::kListBoxNumFiltered)), -1)))) > ::_DAT_01012060)
        {
            MenuNode* tile = ((::MenuNode *)(reinterpret_cast<::FUN_00a00e90_shell *>((parent))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((tile))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((tile))->FUN_00a09130(0x7d0, (::Tile *)(entry), 0xfb0);
            reinterpret_cast<::P03Value *>((tile))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat((int)((::FUN_00a00940(&(*reinterpret_cast<char *>((void *)&::kListBoxNumFiltered)), -1)))));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((tile))->FUN_00a09410(0);
        }
        return entry;
    }
    else
        return 0;
}

struct ListValue
{
    virtual ~ListValue();
};
struct ListTile
{
    ~ListTile();
};
struct ListItem
{
    ListValue* value;
    ListTile* tile;
};
struct ListItemNode
{
    ListItem* item;
    ListItemNode* next;
    ~ListItemNode();
};
struct ListPanel
{
    void* vtable;
    ListItem* head;
    ListItemNode* next;
    ListTile* tile;
    int selection;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short flags;
    float position;
    void ClearItems();
};
struct NavigationItem : MenuNode
{
};
struct NavigationEntry
{
    NavigationItem* item;
};
struct NavigationNode
{
    NavigationEntry* entry;
    NavigationNode* next;
};
struct NavigationList
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual NavigationItem* FindItem(int last, int flags);
    NavigationNode entries;
    MenuNode* scrollTile;
    NavigationItem* current;
    int unknown14;
    int unknown18;
    unsigned short count;
    NavigationItem* GetNextItem(int action);
};
// @fnv 0x0072ae70
NavigationItem* NavigationList::GetNextItem(int action)
{
    NavigationItem* selected = 0;
    int step = 0;
    switch (action)
    {
    case 2:
        step = 1;
        break;
    case 1:
        step = -1;
        break;
    case 15:
        step = scrollTile ? (int)::InventoryStackRecord::RoundToNearestStep(-reinterpret_cast<::TileListBoxCalls *>((scrollTile))->GetFloat(0xfb0) /
                                                  reinterpret_cast<::TileListBoxCalls *>((scrollTile))->GetFloat(FUN_00a01860("_scroll_delta")),
                                              1.0f)
                          : 0;
        break;
    case 16:
        step = scrollTile ? (int)::InventoryStackRecord::RoundToNearestStep(reinterpret_cast<::TileListBoxCalls *>((scrollTile))->GetFloat(0xfb0) /
                                                  reinterpret_cast<::TileListBoxCalls *>((scrollTile))->GetFloat(FUN_00a01860("_scroll_delta")),
                                              1.0f)
                          : 0;
        break;
    }
    if (reinterpret_cast<::fnv_0072c200::MenuTileControl *>(this)->FUN_0072c200() && step && count)
    {
        int index = count - 1;
        int last;
        if (current)
        {
            int previous = (int)reinterpret_cast<::TileListBoxCalls *>((current))->GetFloat(0xfac);
            if ((last = previous + step) < 0)
                last = 0;
            else if (last > index)
                last = index;
        }
        else
        {
            if (step > 0)
                last = 0;
            else
                last = index;
        }
        while (true)
        {
            for (NavigationNode* node = this ? &entries : 0; !selected && node && *((::NavigationEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
                 node = ((::NavigationNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::NavigationEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->item))->GetFloat(0xfac) == last)
                    selected = (*((::NavigationEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->item;
            }
            if (selected && !reinterpret_cast<::FUN_00a01230_shell *>((selected))->IsTraitNonZero(::FUN_00a00940((const char *)(int *)(&(*reinterpret_cast<int *>((void *)&::kListBoxEnabled))), -1)))
            {
                selected = 0;
                if (step > 0 && ++last > index)
                {
                    last = index - 1;
                    while ((!selected || !reinterpret_cast<::FUN_00a01230_shell *>((selected))->IsTraitNonZero(::FUN_00a00940((const char *)(int *)(&(*reinterpret_cast<int *>((void *)&::kListBoxEnabled))), -1))) && last >= 0)
                    {
                        selected = FindItem(last--, 0);
                    }
                    break;
                }
                else if (step < 0 && --last < 0)
                {
                    last = 1;
                    while ((!selected || !reinterpret_cast<::FUN_00a01230_shell *>((selected))->IsTraitNonZero(::FUN_00a00940((const char *)(int *)(&(*reinterpret_cast<int *>((void *)&::kListBoxEnabled))), -1))) && last <= index)
                    {
                        selected = FindItem(last++, 0);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return selected != current ? selected : 0;
}

struct OwnedMenuObject
{
    virtual ~OwnedMenuObject();
};
struct OwnedMenuTile
{
    ~OwnedMenuTile();
};
struct OwnedMenuEntry
{
    OwnedMenuObject* object;
    OwnedMenuTile* tile;
};
struct OwnedEntryNode
{
    OwnedMenuEntry* entry;
    OwnedEntryNode* next;
    ~OwnedEntryNode();
};
struct MenuValueTile
{
};
struct RecipeListOwner
{
    int context;
    OwnedMenuEntry* first;
    OwnedEntryNode* remaining;
    MenuValueTile* tile;
    int selected;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short flags;
    float value;
    void FUN_0072c880();
    void ClearEntries();
};
// @fnv 0x0072b350
void RecipeListOwner::ClearEntries()
{
    while (remaining && *((::OwnedMenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(remaining)->m_item)))
    {
        OwnedEntryNode* next = ((::OwnedEntryNode *)(reinterpret_cast<::Callees *>((remaining))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::OwnedMenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(remaining)->m_item)))->object;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::OwnedMenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(remaining)->m_item)))->tile;
        delete *((::OwnedMenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(remaining)->m_item));
        reinterpret_cast<::CombatProcedure *>((remaining))->Initialize((::CombatController *)(0));
        delete remaining;
        remaining = next;
    }
    if (first)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete first->object;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete first->tile;
        delete first;
    }
    first = 0;
    count = 0;
    value = 0.0f;
    if (tile)
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::FUN_0072cba0_cls *>(this)->FUN_0072cba0();
    selected = 0;
    FUN_0072c880();
}

struct NavTile
{

};
struct NavEntry
{
    NavTile* tile;
};
struct NavNode
{
    NavEntry* data;
    NavNode* next;
};
struct NavBase
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual NavTile* Get(int, bool);
};
struct NavList
{
    NavNode head;
};
struct Navigation : NavBase, NavList
{
    NavTile* scroll;
    NavTile* current;
    int unk14;
    int unk18;
    unsigned short count;
    NavTile* FUN_0072b620(int action);
};
// @fnv 0x0072b620
NavTile* Navigation::FUN_0072b620(int action)
{
    NavTile* foundVal = 0;
    int delta8 = 0;
    switch (action)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 =
            scroll
                ? (int)::InventoryStackRecord::RoundToNearestStep(
                      (float)(-reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(FUN_00a01860("_scroll_delta"))), 1.0f)
                : 0;
        break;
    case 16:
        delta8 =
            scroll
                ? (int)::InventoryStackRecord::RoundToNearestStep(
                      (float)(reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(FUN_00a01860("_scroll_delta"))), 1.0f)
                : 0;
        break;
    }
    if (reinterpret_cast<::fnv_0072c7d0::B2C7D0Menu *>(this)->FUN_0072c7d0() && delta8 && count)
    {
        int maximum = count - 1;
        int index;
        if (current)
        {
            int oldIndex4 = (int)reinterpret_cast<::TileListBoxCalls *>((current))->GetFloat(0xfac);
            index = oldIndex4 + delta8;
            if (index < 0)
                index = 0;
            else if (index > maximum)
                index = maximum;
        }
        else if (delta8 > 0)
            index = 0;
        else
            index = maximum;
        while (true)
        {
            for (NavNode* node = (NavNode*)static_cast<NavList*>(this); !foundVal && node && *((::NavEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
                 node = ((::NavNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::NavEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->tile))->GetFloat(0xfac) == index)
                    foundVal = (*((::NavEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->tile;
            }
            if (foundVal && !reinterpret_cast<::FUN_00a01230_shell *>((foundVal))->IsTraitNonZero((int)(((::FUN_00a00940(&(*reinterpret_cast<char *>((void *)&::kListBoxEnabled)), -1))))))
            {
                foundVal = 0;
                if (delta8 > 0 && ++index > maximum)
                {
                    index = maximum - 1;
                    while ((!foundVal || !reinterpret_cast<::FUN_00a01230_shell *>((foundVal))->IsTraitNonZero((int)(((::FUN_00a00940(&(*reinterpret_cast<char *>((void *)&::kListBoxEnabled)), -1)))))) && index >= 0)
                    {
                        foundVal = Get(index--, false);
                    }
                    break;
                }
                else if (delta8 < 0 && --index < 0)
                {
                    index = 1;
                    while ((!foundVal || !reinterpret_cast<::FUN_00a01230_shell *>((foundVal))->IsTraitNonZero((int)(((::FUN_00a00940(&(*reinterpret_cast<char *>((void *)&::kListBoxEnabled)), -1)))))) &&
                           index <= maximum)
                    {
                        foundVal = Get(index++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return foundVal != current ? foundVal : 0;
}

struct List271
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    SelectedOption* current;
    bool FUN_0072ae00(SelectedOption* option);
};
struct RcMenu;

struct RcTile
{
    void FUN_00a01350(int trait, const char* value, bool propagate);
};

struct RcListBox
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
    void FUN_0075a0d0(RcTile* parent, const char* templateName);
};

struct RcMenu
{
    virtual ~RcMenu();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual int GetID();

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
    RcTile* tile2C;
    int unk30;
    RcTile* tile34;
    int unk38;
    int unk3C;
    RcTile* tile40;
    RcTile* tile44;
    RcTile* tile48;
    int unk4C;
    int unk50;
    RcTile* tile54;
    RcTile* tile58;
    RcTile* tile5C;
    intptr_t unk60;
    int unk64;
    int unk68;
    RcListBox list6C;
    int unk9C;
    RcListBox listA0;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    char unk100;

};

struct RcIMSub
{
};

struct RcIM : SelectionInterface
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
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    RcIMSub sub4D4;
};

class TESForm
{
  public:
    virtual ~TESForm();
public:
    static ::TESForm *LookupFormByEditorID(const char *);
};

class BGSMessage : public TESForm
{
  public:
};

class GlobalObject_0040c150
{
  public:
};

extern GlobalObject_0040c150 g_011d2088;
extern GlobalObject_0040c150 g_011d2b08;
extern GlobalObject_0040c150 g_011d3090;
extern GlobalObject_0040c150 g_011d50f8;

extern Tile* DAT_011d8eb4;

int FUN_007273e0();
void FUN_00763ff0();

// @fnv 0x00726ff0
RcTile* CreateRecipeMenu(int vendor, int type)
{
    RcIM* im2 = static_cast<RcIM*>(((::SelectionInterface *)(::fnv_004b7210::FUN_004b7210())));
    if (!vendor)
    {
        ::FUN_005b5e40();
        return 0;
    }
    RcMenu* oldMenu = ((::RcMenu *)(::FUN_00a09030(FUN_007273e0())));
    if (oldMenu)
    {
        delete oldMenu;
    }
    RcTile* tile2 = ((::RcTile *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::RcTile *)(reinterpret_cast<::InterfaceManager *>((im2))->FUN_00586150()))))->FUN_00a01b00((void *)("Data\\Menus\\recipe_menu.xml"))));
    DAT_011d8e90 = (intptr_t)(tile2 ? ((::RcMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((tile2))->FUN_00a03c90())) : 0);
    DAT_011d8eac = 0;
    DAT_011d8eb0 = 0;
    DAT_011d8eb4 = 0;
    if (DAT_011d8e90 && ((RcMenu*)DAT_011d8e90)->GetID() == FUN_007273e0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((((RcMenu*)DAT_011d8e90)))->FUN_00a1dc70((::TileMenu *)(tile2), false);
        if (!reinterpret_cast<::FUN_007273f0_shell *>((((RcMenu*)DAT_011d8e90)))->FUN_007273f0())
        {
            ::FUN_005b5e40();
        }
        if (reinterpret_cast<::TileListBoxCalls *>((tile2))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((tile2))->GetFloat(0xfa7) == 102.0)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((tile2))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), true);
        }
        FUN_00763ff0();
        ((RcMenu*)DAT_011d8e90)->list6C.FUN_0075a0d0(((RcMenu*)DAT_011d8e90)->tile34, "CM_list_template");
        ((RcMenu*)DAT_011d8e90)->listA0.FUN_0075a0d0(((RcMenu*)DAT_011d8e90)->tile40, "CM_list_template");
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RcMenu*)DAT_011d8e90)->tile2C))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d2088))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RcMenu*)DAT_011d8e90)->tile5C))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d2b08))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RcMenu*)DAT_011d8e90)->tile54))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d3090))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RcMenu*)DAT_011d8e90)->tile58))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d50f8))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RcMenu*)DAT_011d8e90)->tile44))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d26f4))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RcMenu*)DAT_011d8e90)->tile48))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d33fc))->GetMenuTitle()))), true);
        reinterpret_cast<::FUN_00a012d0_t *>((((RcMenu*)DAT_011d8e90)
            ->tile44))->FUN_00a012d0(0xfa1, reinterpret_cast<::TileListBoxCalls *>((((RcMenu*)DAT_011d8e90)->tile44))->GetFloat(0xfa1) - 20.0, true);
        reinterpret_cast<::FUN_00a012d0_t *>((((RcMenu*)DAT_011d8e90)
            ->tile48))->FUN_00a012d0(0xfa1, reinterpret_cast<::TileListBoxCalls *>((((RcMenu*)DAT_011d8e90)->tile48))->GetFloat(0xfa1) - 20.0, true);
        ((RcMenu*)DAT_011d8e90)->unk60 = vendor;
        ((RcMenu*)DAT_011d8e90)->unk64 = type;
        ::s717280::FUN_00717280(0x24);
        if (!reinterpret_cast<::S8840 *>(&(static_cast<RcIM*>(((::SelectionInterface *)(::fnv_004b7210::FUN_004b7210())))->sub4D4))->FUN_00718840(0x26))
        {
            BGSMessage* message = dynamic_cast<BGSMessage*>(::TESForm::LookupFormByEditorID("HelpCrafting"));
            if (message)
            {
                ((RcMenu*)DAT_011d8e90)->unk100 = ((char)(::InitTutorialMenu((::TESForm *)(message), 0)));
                reinterpret_cast<::FUN_007185e0_class *>(&(static_cast<RcIM*>(((::SelectionInterface *)(::fnv_004b7210::FUN_004b7210())))->sub4D4))->SetFlag2(0x26);
            }
        }
        reinterpret_cast<::Menu *>((((RcMenu*)DAT_011d8e90)))->SetMenuVisibility(0);
        reinterpret_cast<::CMMenu *>((((RcMenu*)DAT_011d8e90)))->PopulateChallengeList(0, type);
        return tile2;
    }
    else if (DAT_011d8e90 && ((std::intptr_t)(reinterpret_cast<::Callees *>((((RcMenu*)DAT_011d8e90)))->FUN_00726070())))
    {
        delete (RcMenu*)DAT_011d8e90;
    }
    return 0;
}


struct HLItem;

struct HLTileValue
{
    void Refresh(int aiFlags);
};

struct HLTile
{
};

struct HLItem
{
};


struct HLListItem
{
    int unk00;
    int unk04;
    int unk08;
    HLTile* pTile;
    HLItem* pItem;

    void RefreshHighlight();
};
// If the object is ready and the input passes the checks, stores input as current, calls RefreshHighlight and returns true; otherwise returns false.
// @fnv 0x0072a250
bool Object::SetCurrentItem(Item* pItem)
{
    if (reinterpret_cast<::FUN_0072bc30_shell *>(this)->FUN_0072bc30() && (!pItem || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((void *)(pItem)) && reinterpret_cast<::FUN_00a01230_shell *>((pItem))->IsTraitNonZero(::FUN_00a00940((const char *)(int *)(&(*reinterpret_cast<int *>((void *)&::kListBoxEnabled))), -1)))))
    {
        current = pItem;
        reinterpret_cast<::HLListItem *>(this)->RefreshHighlight();
        return true;
    }
    else
    {
        return false;
    }
}

// Updates the _highlight_y and _selected_height tile values from pItem, then shows or hides the lb_highlight_box children based on pItem->IsSelected().
// @fnv 0x0072bce0
void HLListItem::RefreshHighlight()
{
    static int s_iHighlightY = ::FUN_00a00940("_highlight_y", -1);
    static int s_iSelectedHeight = ::FUN_00a00940("_selected_height", -1);

    if (pTile)
    {
        if (pItem)
        {
            HLTileValue* pHighlightY = ((::HLTileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pTile))->FUN_00a00f30(s_iHighlightY)));
            HLTileValue* pSelectedHeight = ((::HLTileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pTile))->FUN_00a00f30(s_iSelectedHeight)));
            reinterpret_cast<::AGOwner *>((pHighlightY))->FUN_00a09130(0x7d0, (::Tile *)(pItem), 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pHighlightY))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((pSelectedHeight))->FUN_00a09130(0x7d0, (::Tile *)(pItem), 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pSelectedHeight))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((pItem))->GetSpeechChallengeFailure())
            {
                HLTile* pBox = ((::HLTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(pTile), "lb_highlight_box")));
                if (pBox)
                {
                    HLTile* pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("top"))));
                    if (pRetrievedObject)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                        pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                        pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                        pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pBox))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((pBox))->FUN_00a07530(8);
                }
            }
            else
            {
                HLTile* pBox = ((::HLTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(pTile), "lb_highlight_box")));
                if (pBox)
                {
                    HLTile* pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("top"))));
                    if (pRetrievedObject)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                        pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                        pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                        pRetrievedObject = ((::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pRetrievedObject))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pRetrievedObject))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pBox))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((pBox))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((pTile))->Set(s_iHighlightY, -1);
            reinterpret_cast<::Tile *>((pTile))->Set(s_iSelectedHeight, 0);
        }
    }
}

struct HighlightTile
{
    void Refresh(int);
};
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* root;
    HighlightTile* selected;
    void FUN_0072c2b0();
};
// Resets m_1c and m_20, walks the node list calling Call(0xfac, m_1c++) and Log on each slot with m_08 == 0, then calls Finish1 and Finish2.
// @fnv 0x0072c130
void FUN_0072c130_cls::ProcessSlots()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (Node_b9223* cur = this ? (Node_b9223*)&unk04 : 0; cur != 0 && *((::Inner_b9223 **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)) != 0; cur = ((::Node_b9223 *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if ((*((::Inner_b9223 **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)))->m_08 == 0)
        {
            reinterpret_cast<::Tile *>((((Target_b9223*)(*((::Inner_b9223 **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)))->m_00)))->Set(0xfac, m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::Inner_b9223 **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)))->m_00));
        }
    }
    reinterpret_cast<::ScrollBarHelper *>(this)->FUN_0072c5d0();
    reinterpret_cast<::HighlightList *>(this)->FUN_0072c2b0();
}
// Destructor that calls ClearItems, then passes this to FUN_007211c0.
// @fnv 0x0072a890
FUN_0072a890_cls::~FUN_0072a890_cls()
{
    reinterpret_cast<::ListPanel *>(this)->ClearItems();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}
// @fnv 0x0072aba0
void ListPanel::ClearItems()
{
    while (next && *((::ListItem **)(&reinterpret_cast<::SimpleListNodeView*>(next)->m_item)))
    {
        ListItemNode* following = ((::ListItemNode *)(reinterpret_cast<::Callees *>((next))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::ListItem **)(&reinterpret_cast<::SimpleListNodeView*>(next)->m_item)))->value;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::ListItem **)(&reinterpret_cast<::SimpleListNodeView*>(next)->m_item)))->tile;
        delete *((::ListItem **)(&reinterpret_cast<::SimpleListNodeView*>(next)->m_item));
        reinterpret_cast<::CombatProcedure *>((next))->Initialize((::CombatController *)(::ListItem *)(0));
        delete next;
        next = following;
    }
    if (head)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete head->value;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete head->tile;
        delete head;
    }
    head = 0;
    count = 0;
    position = 0.0f;
    if (tile)
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::ScrollBarHelper *>(this)->FUN_0072c5d0();
    selection = 0;
    reinterpret_cast<::HighlightList *>(this)->FUN_0072c2b0();
}
// @fnv 0x0072ae00
bool List271::FUN_0072ae00(SelectedOption* option)
{
    if (reinterpret_cast<::fnv_0072c200::MenuTileControl *>(this)->FUN_0072c200() && (!option || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((void *)(option)) && reinterpret_cast<::FUN_00a01230_shell *>((option))->IsTraitNonZero((int)(((::FUN_00a00940(&(*reinterpret_cast<char *>((void *)&::kListBoxEnabled)), -1))))))))
    {
        current = option;
        reinterpret_cast<::HighlightList *>(this)->FUN_0072c2b0();
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x0072c2b0
void HighlightList::FUN_0072c2b0()
{
    static int highlightY = ::FUN_00a00940("_highlight_y", -1);
    static int selectedHeight = ::FUN_00a00940("_selected_height", -1);
    if (root)
    {
        if (selected)
        {
            HighlightTile* pHighlightY = ((::HighlightTile *)(reinterpret_cast<::FUN_00a00f30_shell *>((root))->FUN_00a00f30(highlightY)));
            HighlightTile* pSelectedHeight = ((::HighlightTile *)(reinterpret_cast<::FUN_00a00f30_shell *>((root))->FUN_00a00f30(selectedHeight)));
            reinterpret_cast<::AGOwner *>((pHighlightY))->FUN_00a09130(2000, (::Tile *)(selected), 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pHighlightY))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((pSelectedHeight))->FUN_00a09130(2000, (::Tile *)(selected), 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pSelectedHeight))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((selected))->GetSpeechChallengeFailure())
            {
                HighlightTile* pHighlightBox = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(root), "lb_highlight_box")));
                if (pHighlightBox)
                {
                    HighlightTile* edge7 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pHighlightBox))->FUN_00a03da0((char *)("top"))));
                    if (edge7)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((edge7))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge7))->FUN_00a07530(8);
                        edge7 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pHighlightBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge7))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge7))->FUN_00a07530(8);
                        edge7 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pHighlightBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge7))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge7))->FUN_00a07530(8);
                        edge7 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pHighlightBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge7))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge7))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pHighlightBox))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((pHighlightBox))->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* box2 = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(root), "lb_highlight_box")));
                if (box2)
                {
                    HighlightTile* edge2 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box2))->FUN_00a03da0((char *)("top"))));
                    if (edge2)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((edge2))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge2))->FUN_00a07530(8);
                        edge2 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box2))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge2))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge2))->FUN_00a07530(8);
                        edge2 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box2))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge2))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge2))->FUN_00a07530(8);
                        edge2 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box2))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge2))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge2))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box2))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((box2))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((root))->Set(highlightY, -1);
            reinterpret_cast<::Tile *>((root))->Set(selectedHeight, 0);
        }
    }
}

namespace fnv_0072c880 {

struct HLItem
{
};

struct HLValue
{
};

struct HLTile
{
};


struct HLListItem
{
    int unk00;
    int unk04;
    int unk08;
    HLTile* pTile;
    HLItem* pItem;

    void FUN_0072c880();
};

// Sets the tile's _highlight_y and _selected_height values from pItem, then enables or disables the lb_highlight_box sides based on GetSpeechChallengeFailure.
// @fnv 0x0072c880
void HLListItem::FUN_0072c880()
{
    static int s_iHighlightY = ::FUN_00a00940("_highlight_y", -1);
    static int s_iSelectedHeight = ::FUN_00a00940("_selected_height", -1);

    if (pTile)
    {
        if (pItem)
        {
            HLValue* pHighlightY = ((::fnv_0072c880::HLValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pTile))->FUN_00a00f30(s_iHighlightY)));
            HLValue* pSelectedHeight = ((::fnv_0072c880::HLValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pTile))->FUN_00a00f30(s_iSelectedHeight)));
            reinterpret_cast<::AGOwner *>((pHighlightY))->FUN_00a09130(0x7d0, (::Tile *)(pItem), 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pHighlightY))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((pSelectedHeight))->FUN_00a09130(0x7d0, (::Tile *)(pItem), 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pSelectedHeight))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((pItem))->GetSpeechChallengeFailure())
            {
                HLTile* pBox = ((::fnv_0072c880::HLTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(pTile), "lb_highlight_box")));
                if (pBox)
                {
                    HLTile* pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("top"))));
                    if (pSideTile)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                        pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                        pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                        pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pBox))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((pBox))->FUN_00a07530(8);
                }
            }
            else
            {
                HLTile* pBox = ((::fnv_0072c880::HLTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(pTile), "lb_highlight_box")));
                if (pBox)
                {
                    HLTile* pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("top"))));
                    if (pSideTile)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                        pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                        pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                        pSideTile = ((::fnv_0072c880::HLTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSideTile))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSideTile))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pBox))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((pBox))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((pTile))->Set(s_iHighlightY, -1);
            reinterpret_cast<::Tile *>((pTile))->Set(s_iSelectedHeight, 0);
        }
    }
}
}  // namespace fnv_0072c880

class FUN_0046ffb0
{
  public:
    ~FUN_0046ffb0();
    void* m_item;
    void* m_pkNext;
};


class FUN_0072b2e0
{
  public:
    virtual ~FUN_0072b2e0();


    FUN_0046ffb0 m_kList;
};
// Calls FUN_0072b2e0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0072ba20
void* FUN_0072ba20_shell::FUN_0072ba20(unsigned int flags)
{
    reinterpret_cast<class ::FUN_0072b2e0 *>(this)->::FUN_0072b2e0::~FUN_0072b2e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destroys the entry list by clearing its entries and then calling FUN_007211c0 on itself.
// @fnv 0x0072b2e0
FUN_0072b2e0::~FUN_0072b2e0()
{
    reinterpret_cast<::RecipeListOwner *>(this)->ClearEntries();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

struct CategoryChallenge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FNStub fullName;
};
struct CategoryArray
{
};
struct CategoryList
{
    virtual void SetSelected(RcTile* tile);
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual RcTile* GetTile(int index, bool flag);
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
};
extern void* DAT_011d8ea8;
struct CategoryMenu
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
    RcTile* tiles[14];
    int unk60;
    int unk64;
    int unk68;
    CategoryList list6C;
    void OnAction(int action, RcTile* tile);
};

// Handles a menu action: opens a quantity menu for action 7, resets state for 8, or cycles the selected category and refreshes the list for 0-2.
// @fnv 0x007274b0
void CategoryMenu::OnAction(int action, RcTile* tile)
{
    if (!tile && action >= 0 && action < 14)
        tile = tiles[action];
    switch (action)
    {
    case 7:
        ::CreateQuantityMenu((intptr_t)(DAT_011d8ea8), ((void (&)())::CraftRecipe), 0x7fffffff);
        break;
    case 8:
        DAT_011d8ea5 = 0;
        FUN_00727430();
        break;
    case 0:
    case 1:
    case 2:
        if ((unsigned char)DAT_011d8ea5)
            break;
        FUN_00706f30(unk68);
        DAT_0119fbf4 += action ? 1 : -1;
        if (DAT_0119fbf4 < -1)
            DAT_0119fbf4 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((CategoryArray*)FUN_00726f10())))->GetName())) - 1;
        else if ((unsigned int)DAT_0119fbf4 >= ((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((CategoryArray*)FUN_00726f10())))->GetName())))
            DAT_0119fbf4 = -1;
        if (DAT_0119fbf4 != -1)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tiles[1]))->FUN_00a01350(
                0xfc4, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::CategoryChallenge *)(SimpleArrayItem<void *>((void *)(((CategoryArray*)FUN_00726f10())), DAT_0119fbf4)))->fullName))->FUN_00408da0()))), true);
        else
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tiles[1]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d2088))->GetMenuTitle()))), true);
        list6C.SetSelected(list6C.GetTile(0, false));
        list6C.v10();
        reinterpret_cast<::FUN_007312e0_shell *>(&(list6C))->FUN_007312e0();
        reinterpret_cast<::LBListBox *>(&(list6C))->ApplyFilter((bool (*)(void *))(IsThresholdDifferent));
        reinterpret_cast<::SelectionList *>(&(list6C))->UpdateSelection(true);
        break;
    }
}

class TESFullName
{
  public:
    virtual ~TESFullName();
};
struct FUN_00726070_shell
{
};

struct FUN_00726070_shell_b
{
};

struct FUN_00408da0_shell
{
};

struct FUN_00728cd0_pair
{
    int m_00;
    FUN_00726070_shell* m_04;
};

struct FUN_00728cd0_pair_b
{
    int m_00;
    FUN_00726070_shell_b* m_04;
};

extern int DAT_01183028;
extern int DAT_01183158;
void* __cdecl FUN_00ec43fb(void*, bool, int*, int*, int);

// Compares the full names of two forms by casting their TESForm pointers to TESFullName and calling FUN_00469880 on the resulting name data.
// @fnv 0x00728cd0
int __cdecl FUN_00728cd0(FUN_00728cd0_pair* apRight, FUN_00728cd0_pair_b* apLeft)
{
    FUN_00408da0_shell* right = (FUN_00408da0_shell*)dynamic_cast<TESFullName*>(((::TESForm *)(reinterpret_cast<::Callees *>((apRight->m_04))->FUN_00726070())));
    FUN_00408da0_shell* left = (FUN_00408da0_shell*)dynamic_cast<TESFullName*>(((::TESForm *)(reinterpret_cast<::Callees *>((apLeft->m_04))->FUN_00726070())));
    void* l = ((void *)(reinterpret_cast<::FUN_00408da0_Class *>((right))->FUN_00408da0()));
    void* r = ((void *)(reinterpret_cast<::FUN_00408da0_Class *>((left))->FUN_00408da0()));
    int result = 0;
    result = FUN_00469880(l, r);
    return result;
}

namespace fnv_00726df0 {
struct FUN_00a1c4a0
{
    virtual void MenuVirtual();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    FUN_00a1c4a0();
    ~FUN_00a1c4a0();
};
struct FUN_007299a0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    FUN_007299a0* m_pOwnerObject;
    FUN_007299a0();
    ~FUN_007299a0();
};
struct FUN_0072a7c0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    FUN_0072a7c0();
    ~FUN_0072a7c0();
};
extern char str_01070474[];
extern int DAT_011d8e98;
extern int DAT_011d8e9c;
extern int DAT_011d8ea0;
extern int DAT_011d8e94;
extern int DAT_011d8ea8;
struct Manager726
{
};
struct FUN_00726df0 : FUN_00a1c4a0
{
    FUN_007299a0 m_6c;
    FUN_0072a7c0 m_a0;
    FUN_0072b210 m_d0;
    bool m_100;
    virtual void MenuVirtual();
    FUN_00726df0();
};
// Initializes global string handles, sets m_6c owner, calls FUN_008454f0, and sets m_68 and m_100.
// @fnv 0x00726df0
FUN_00726df0::FUN_00726df0()
{
    DAT_011d8e98 = ::FUN_00a01860(::DAT_0106ed20);
    DAT_011d8e9c = ::FUN_00a01860(::DAT_0106ed18);
    DAT_011d8ea0 = ::FUN_00a01860(str_01070474);
    DAT_011d8e94 = 0;
    m_6c.m_pOwnerObject = &m_6c;
    DAT_011d8ea8 = 0;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<Manager726*>(FUN_00726f10())))->Clear(1);
    m_68 = 3;
    m_100 = false;
}
}  // namespace fnv_00726df0

class TESIcon
{
  public:
    int FUN_0048cee0();
};
struct ArmorNames
{
    const char* FUN_00481280(int);
};
class TESObjectARMO
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    ArmorNames names;
};
struct StatValues
{
};
struct RecipeInventoryCount
{
};
class TESBoundObject
{
};
struct ActorData
{
    virtual void unkV00();
    virtual void unkV01();
    virtual void unkV02();
    virtual void unkV03();
    virtual void unkV04();
    virtual void unkV05();
    virtual void unkV06();
    virtual void unkV07();
    virtual void unkV08();
    virtual void unkV09();
    virtual void unkV0A();
    virtual void unkV0B();
    virtual void unkV0C();
    virtual void unkV0D();
    virtual void unkV0E();
    virtual void unkV0F();
    virtual void unkV10();
    virtual void unkV11();
    virtual void unkV12();
    virtual void unkV13();
    virtual void unkV14();
    virtual void unkV15();
    virtual void unkV16();
    virtual void unkV17();
    virtual void unkV18();
    virtual void unkV19();
    virtual void unkV1A();
    virtual void unkV1B();
    virtual void unkV1C();
    virtual void unkV1D();
    virtual void unkV1E();
    virtual void unkV1F();
    virtual void unkV20();
    virtual void unkV21();
    virtual void unkV22();
    virtual void unkV23();
    virtual void unkV24();
    virtual void unkV25();
    virtual void unkV26();
    virtual void unkV27();
    virtual void unkV28();
    virtual void unkV29();
    virtual void unkV2A();
    virtual void unkV2B();
    virtual void unkV2C();
    virtual void unkV2D();
    virtual void unkV2E();
    virtual void unkV2F();
    virtual void unkV30();
    virtual void unkV31();
    virtual void unkV32();
    virtual void unkV33();
    virtual void unkV34();
    virtual void unkV35();
    virtual void unkV36();
    virtual void unkV37();
    virtual void unkV38();
    virtual void unkV39();
    virtual void unkV3A();
    virtual void unkV3B();
    virtual void unkV3C();
    virtual void unkV3D();
    virtual void unkV3E();
    virtual void unkV3F();
    virtual bool IsValid();
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
    StatValues stats;
};
struct Entry
{
};
struct EntryListNode
{
    unsigned FUN_005ae380();
    bool FUN_008256d0();
};
struct Category
{
    int unk0, unk4, unk8, unkC, unk10, unk14;
    FNStub name;
};
struct RecipeData
{
};
struct RecipeTiles
{
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
};
struct TileRef
{
};
struct RecipeAddedItem
{
    int unk0;
    TileRef tile;
};
struct RecipeBox
{
    virtual void SetSelected(TESForm*);
    virtual Entry* GetSelected();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual TESForm* SelectAt(int, bool);
    virtual void v6();
    virtual void Clear();
    virtual void Sort(int(__cdecl*)(FUN_00728cd0_pair*, FUN_00728cd0_pair_b*));
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    RecipeBox* current;
    Entry* FUN_007a1910();
};
extern RecipeData* DAT_011d8e94;
struct SexData
{
    int FUN_0087f4c0();
};
struct RecipeEnterMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Refresh(int, Entry*);
    virtual void Activate(int, int);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    RecipeTiles* tiles[14];
    ActorData* actor;
    Category* category;
    int unk68;
    RecipeBox first, second;
    void FUN_00727b10(int, RecipeTiles*);
};

struct RecipeScrollMetrics
{
    int unk00;
    int unk04;
    int unk08;
    TileStub* pScrollTile;
    int unk10;
    TileStub* pCountTile;
    int unk18;
    int unk1c;
    float fTotal;

    void FUN_0072c000();
};
// @fnv 0x00729ae0
RecipeEntry* RecipePanel::FUN_00729ae0(intptr_t selection, intptr_t updateChoice, intptr_t aiRecipeIndex, int parentId)
{
    if (m_parent != 0 && (m_defaultItem != 0 || parentId != 0))
    {
        RecipeEntry* current =
            ((::RecipeEntry *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::MenuNode *)(reinterpret_cast<::FUN_00a03c90_shell *>((m_parent))->FUN_00a03c90()))))->FUN_00a1ddb0({}, {}, {})));
        if (!((std::intptr_t)(reinterpret_cast<::FUN_00a00f30_shell *>((current))->FUN_00a00f30(0xfaa))))
            reinterpret_cast<::Tile *>((current))->Set(0xfaa, -1);
        if (updateChoice != 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((current))->FUN_00a01350(0xfc4, (char *)(updateChoice), 1);

        if (aiRecipeIndex != 0)
        {
            reinterpret_cast<::FUN_00470440 *>(&(m_recipes))->FUN_007a7eb0((::BGSPerkEntry *)(::RecipeEntry *)(new RecipeEntry(current, &selection)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(aiRecipeIndex));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_00729fb0_shell *>(this)->BuildMenuEntries();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(m_recipes))->FUN_00905820((void *)&(const ::RecipeEntry *const &)(new RecipeEntry(current, &selection)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(current));
                reinterpret_cast<::RecipeScrollMetrics *>(this)->FUN_0072c000();
            }
            reinterpret_cast<::Tile *>((current))->Set(0xfac, m_nextIndex++);
        }

        if (::GetRaceCount((char *)this) == 1)
        {
            if (reinterpret_cast<::TileListBoxCalls *>((m_parent))->GetFloat(::FUN_00a00940((const char *)(const void *)(&(*reinterpret_cast<char *>((void *)&::kListBoxNumFiltered))), -1)) > ::_DAT_01012060)
            {
                MenuNode* notifier = ((::MenuNode *)(reinterpret_cast<::FUN_00a00e90_shell *>((m_parent))->FindTraitValue(0xfb0)));
                reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((notifier))->RemoveFromReactions();
                reinterpret_cast<::AGOwner *>((notifier))->FUN_00a09130(0x7d0, (::Tile *)(current), 0xfb0);
                reinterpret_cast<::P03Value *>((notifier))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((m_parent))->GetFloat(::FUN_00a00940((const char *)(const void *)(&(*reinterpret_cast<char *>((void *)&::kListBoxNumFiltered))), -1)));
                reinterpret_cast<::fnv_00a09410::EvalValue *>((notifier))->FUN_00a09410(0);
            }
        }
        return current;
    }
    else
    {
        return 0;
    }
}
// Resets the entry count and value, then for each enabled entry assigns an action and index, adds its item, and calls the two finalize methods.
// @fnv 0x0072bb60
void FUN_00729fb0_shell::BuildMenuEntries()
{
    ((MenuBody*)this)->m_uiItemCount = 0;
    ((MenuBody*)this)->m_uiFilterValue = 0.0f;
    for (EntryNode* pNode = this != 0 ? &((MenuBody*)this)->m_entries : 0; pNode != 0 && *((::MenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)) != 0;
         pNode = ((::EntryNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))
    {
        if ((*((::MenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)))->m_disabled == 0)
        {
            reinterpret_cast<::Tile *>(((*((::MenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)))->m_item))->Set(0xfac, ((MenuBody*)this)->m_uiItemCount++);
            reinterpret_cast<::VLList *>((((MenuBody*)this)))->AccumulateTileHeight((::VLTile *)((*((::MenuEntry **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)))->m_item));
        }
    }
    reinterpret_cast<::RecipeScrollMetrics *>((((MenuBody*)this)))->FUN_0072c000();
    reinterpret_cast<::HLListItem *>((((MenuBody*)this)))->RefreshHighlight();
}
// @fnv 0x00729a70
FUN_00729a70::~FUN_00729a70()
{
    reinterpret_cast<::List49 *>((((FUN_00729d80_shell*)this)))->ClearList();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}
// @fnv 0x00729d80
void List49::ClearList()
{
    while (nodes && *((::Pair49 **)(&reinterpret_cast<::SimpleListNodeView*>(nodes)->m_item)))
    {
        FUN_004702f0* next = ((::FUN_004702f0 *)(reinterpret_cast<::Callees *>((nodes))->FUN_00726070()));
        if (!DAT_011d8909)
            delete (*((::Pair49 **)(&reinterpret_cast<::SimpleListNodeView*>(nodes)->m_item)))->item;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::Pair49 **)(&reinterpret_cast<::SimpleListNodeView*>(nodes)->m_item)))->extra;
        delete *((::Pair49 **)(&reinterpret_cast<::SimpleListNodeView*>(nodes)->m_item));
        reinterpret_cast<::CombatProcedure *>((nodes))->Initialize((::CombatController *)(0));
        delete nodes;
        nodes = next;
    }
    if (first)
    {
        if (!DAT_011d8909)
            delete first->item;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete first->extra;
        delete first;
    }
    first = 0;
    count = 0;
    value = 0.0f;
    if (tile)
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(FUN_00a01860(&(*reinterpret_cast<char *>(&::str_0106f8d0))), 0.0f, true);
    reinterpret_cast<::RecipeScrollMetrics *>(this)->FUN_0072c000();
    selected = 0;
    reinterpret_cast<::HLListItem *>(this)->RefreshHighlight();
}
// Marks each item by apFilter, rebuilds the tile list and item count, updates the _num_filtered trait, and restores the selected tile.
// @fnv 0x00729fe0
void LBListBox::ApplyFilter(bool(__cdecl* apFilter)(void*))
{
    int iNumFiltered = 0;
    int iSelectedIndex = -1;
    static int s_iNumFilteredTrait = ::FUN_00a00940("_num_filtered", -1);

    usItemCount = 0;
    fScroll = 0.0f;
    for (LBList* pIter = this; pIter && ((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item)); pIter = ((::LBList *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070())))
    {
        ((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->m_bFiltered = apFilter && apFilter(((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->pObject);
        if (((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->m_bFiltered)
        {
            if (((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->pTile == pSelected)
            {
                iSelectedIndex = reinterpret_cast<::TileListBoxCalls *>((((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->pTile))->GetFloat(0xfac);
                pSelected = 0;
            }
            reinterpret_cast<::Tile *>((((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->pTile))->Set(0xfac, -1);
            iNumFiltered++;
        }
        else
        {
            if (iSelectedIndex >= 0 && usItemCount == iSelectedIndex)
                pSelected = ((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->pTile;
            reinterpret_cast<::Tile *>((((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->pTile))->Set(0xfac, usItemCount++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::LBItem *)(reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))->pTile));
        }
    }

    reinterpret_cast<::Tile *>((pParentTile))->Set(s_iNumFilteredTrait, iNumFiltered);
    reinterpret_cast<::RecipeScrollMetrics *>(this)->FUN_0072c000();
    if (!pSelected && iSelectedIndex >= 0)
        pSelected = GetTileByIndex(iSelectedIndex, false);
    if (!pSelected && iSelectedIndex >= 0)
        pSelected = FUN_0072ba50();
    reinterpret_cast<::HLListItem *>(this)->RefreshHighlight();
}

// Uses fTotal and the scroll tile's 0xfb0 value to set scroll delta and item count.
// @fnv 0x0072c000
void RecipeScrollMetrics::FUN_0072c000()
{
    if (pScrollTile)
    {
        float fVisible = reinterpret_cast<::TileListBoxCalls *>((pScrollTile))->GetFloat(0xfb0);
        int iItemCount = 1;
        if (fTotal > 0.0 && fVisible > 0.0)
        {
            if (fTotal > fVisible)
            {
                iItemCount = FUN_00647b70((int)FUN_004e4430(((unsigned int)(reinterpret_cast<::FUN_0072bab0_shell *>(this)->GetFilteredCount())) * (fTotal - fVisible) / fTotal) + 1, 2);
            }
            if (iItemCount > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((pScrollTile))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (fTotal - fVisible) / (iItemCount - 1), true);
            }
        }
        if (pCountTile)
        {
            reinterpret_cast<::Tile *>((pCountTile))->Set(FUN_00a01860("_number_of_items"), iItemCount);
        }
    }
}

struct ReqData
{
};

struct ReqNode
{
    bool FUN_008256d0();
};

struct ItemEntry
{
    ~ItemEntry();
};

struct ItemList
{
};

struct ChallengeOwner
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool v40();

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
    ItemList kItems;

};

struct RecipeCanMakeView
{
};

// Checks challenge prerequisites and, with an owner, limits the count by bound-object inventory ratios; otherwise it starts at 100.
// @fnv 0x00727920
int __cdecl FUN_00727920(void* apChallenge)
{
    ChallengeOwner* pOwner =
        (((ChallengeOwner*)((RcMenu*)DAT_011d8e90)->unk60) && ((ChallengeOwner*)((RcMenu*)DAT_011d8e90)->unk60)->v40())
            ? ((ChallengeOwner*)((RcMenu*)DAT_011d8e90)->unk60)
            : 0;
    reinterpret_cast<int&>(DAT_011d8ea8) = 100;
    if (!((std::intptr_t)(reinterpret_cast<::FUN_006a1b60_Class *>((static_cast<RecipeCanMakeView*>(apChallenge)))->GetField54())) ||
        !reinterpret_cast<::LowProcess *>((static_cast<RecipeCanMakeView*>(apChallenge)))->GetPackageObjectType())
        return 0;
    if (pOwner)
    {
        if (((int)(reinterpret_cast<::ActorMover *>((static_cast<RecipeCanMakeView*>(apChallenge)))->GetCurrentMoveModeType())) > -1 &&
            reinterpret_cast<::ActorValueOwner *>(&(pOwner->kItems))->GetActorValueAsInteger((::ActorValue::Index)(((int)(reinterpret_cast<::ActorMover *>((static_cast<RecipeCanMakeView*>(apChallenge)))->GetCurrentMoveModeType())))) <
                ((std::intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((static_cast<RecipeCanMakeView*>(apChallenge)))->FUN_0045cd60())))
            return 0;
        if (((RcMenu*)DAT_011d8e90)->unk64 != ((std::intptr_t)(reinterpret_cast<::FUN_006a1b60_Class *>((static_cast<RecipeCanMakeView*>(apChallenge)))->GetField54())))
            return 0;
        ReqNode* pNode = ((::ReqNode *)(reinterpret_cast<struct ::FUN_005a8080 *>((static_cast<RecipeCanMakeView*>(apChallenge)))->GetField()));
        while (pNode && !pNode->FUN_008256d0())
        {
            ReqData* pReq = *((::ReqData **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item));
            TESBoundObject* pObject = dynamic_cast<TESBoundObject*>(((::TESForm *)(reinterpret_cast<::Callees *>(((*((::ReqData **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)))))->FUN_00726070())));
            if (pObject)
            {
                ItemEntry* pEntry = ((::ItemEntry *)(reinterpret_cast<::fnv_00576260::FUN_00576260_shell *>((pOwner))->FUN_00576260((::fnv_00576260::TESBoundObject *)(pObject), 0)));
                unsigned int uiHave = pEntry ? ((unsigned int)(reinterpret_cast<::Callees *>((pEntry))->FUN_00726070())) : 0;
                delete pEntry;
                if (uiHave < ((unsigned int)(::FUN_00559450((int *)(pReq)))))
                {
                    return 0;
                }
                else
                {
                    int iTimes = uiHave / ((unsigned int)(::FUN_00559450((int *)(pReq))));
                    if (iTimes < reinterpret_cast<int&>(DAT_011d8ea8))
                        reinterpret_cast<int&>(DAT_011d8ea8) = iTimes;
                }
            }
            pNode = ((::ReqNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
    }
    return reinterpret_cast<int&>(DAT_011d8ea8);
}


struct TileObj
{
    void FUN_00a01350(int a, const char* b, bool c);
    void FUN_00700320(int a, int b);
};

struct ListLinks
{
    void* FUN_00683520(void** a);
};

struct MenuTileList
{
    int m_00;
    ListLinks links;
};

class RecipeStatsFormView
{
  public:
    virtual ~RecipeStatsFormView();
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
    int nameComponent;
    int FUN_00401170();
};

class Actor;
struct TESObjectWEAP : public TESForm
{
public:
    unsigned char GetDamageForActor(bool, bool, ::Actor *);
public:
    float FUN_00709430(bool);
};

struct RecipeStatsArmorView : public TESForm
{
};

struct SoundObj
{
};

struct AmmoObj
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
    SoundObj name;
};

struct InvChanges
{
};

struct ProcessObj
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
};

struct RecipeStatsPlayerView
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
    int actorValues;
};


struct SettingObj
{
};


float __cdecl ComputeItemValue(float a, float b);

struct ListHead
{
    int unk00;
    int links;
};

struct NamedList
{
    int unk00;
    ListHead entries;
};

struct HolderObj
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
    void* m_24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    void* m_3c;
};

struct SelfObj
{
    void FUN_00728da0(TESForm* a1, MenuTileList* a2);
};
// Handles actions 3, 6, and 15 to switch recipe views, rebuild ingredient details, and update selected item tiles.
// @fnv 0x00727b10
void RecipeEnterMenu::FUN_00727b10(int id, RecipeTiles* tile)
{
    if (!tile && id >= 0 && id < 14)
        tile = tiles[id];
    switch (id)
    {
    case 3:
        Activate(6, 0);
        reinterpret_cast<::FUN_007312e0_shell *>(&(first))->FUN_007312e0();
        second.SetSelected(0);
        reinterpret_cast<::SelectionList *>(&(first))->UpdateSelection(0);
        break;
    case 6:
        Activate(3, 0);
        first.SetSelected(0);
        ::fnv_004b7210::FUN_004b7210();
        if (FUN_004b71d0())
            second.SetSelected(second.SelectAt(0, false));
        DAT_011d8ea5 = 1;
        Refresh(15, second.GetSelected());
        break;
    case 15: {
        Entry* selected = 0;
        bool alternate = false;
        if ((unsigned char)DAT_011d8ea5)
        {
            if (second.FUN_007a1910())
                selected = second.FUN_007a1910();
        }
        else
        {
            reinterpret_cast<::Tile *>((tiles[10]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((tiles[9]))->Set(0xfa3, 0);
            if (first.current->FUN_007a1910())
                DAT_011d8e94 = (RecipeData*)first.current->FUN_007a1910();
            ActorData* owner =
                ((RecipeEnterMenu*)DAT_011d8e90)->actor && ((RecipeEnterMenu*)DAT_011d8e90)->actor->IsValid()
                    ? ((RecipeEnterMenu*)DAT_011d8e90)->actor
                    : 0;
            if (DAT_011d8e94)
            {
                const char* categoryName = "*** MISSING CATEGORY ***";
                if (((::Category *)(reinterpret_cast<::FUN_006a1b60_Class *>((DAT_011d8e94))->GetField54())))
                    categoryName = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::Category *)(reinterpret_cast<::FUN_006a1b60_Class *>((DAT_011d8e94))->GetField54()))->name))->FUN_00408da0()));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[4]))->FUN_00a01350(0xfc4, (char *)(categoryName), true);
                if (((RecipeEnterMenu*)DAT_011d8e90)->category == ((::Category *)(reinterpret_cast<::FUN_006a1b60_Class *>((DAT_011d8e94))->GetField54())))
                    reinterpret_cast<::Tile *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[4]))->Set(0xfa9, 255);
                else
                    reinterpret_cast<::Tile *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[4]))->Set(0xfa9, 127);
                EntryListNode* list = ((::EntryListNode *)(reinterpret_cast<struct ::FUN_005a8080 *>((DAT_011d8e94))->GetField()));
                second.Clear();
                selected = ((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(((::EntryListNode *)(reinterpret_cast<::FUN_005d43c0_ *>((DAT_011d8e94))->FUN_005d43c0())))->m_item));
                if (((::EntryListNode *)(reinterpret_cast<::FUN_005d43c0_ *>((DAT_011d8e94))->FUN_005d43c0()))->FUN_005ae380() > 1 &&
                    ((::EntryListNode *)(reinterpret_cast<struct ::FUN_005a8080 *>((DAT_011d8e94))->GetField()))->FUN_005ae380() == 1)
                {
                    list = ((::EntryListNode *)(reinterpret_cast<::FUN_005d43c0_ *>((DAT_011d8e94))->FUN_005d43c0()));
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RecipeEnterMenu*)DAT_011d8e90)
                        ->tiles[11]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::Category *)(reinterpret_cast<::LowProcess *>((DAT_011d8e94))->GetPackageObjectType()))->name))->FUN_00408da0()))), true);
                    alternate = true;
                }
                else
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[11]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d3090))->GetMenuTitle()))), true);
                while (list && !list->FUN_008256d0())
                {
                    char label[256];
                    TESFullName* name = dynamic_cast<TESFullName*>(((::TESForm *)(reinterpret_cast<::Callees *>((((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(list)->m_item))))->FUN_00726070())));
                    if (name && owner)
                    {
                        TESBoundObject* bound = dynamic_cast<TESBoundObject*>(((::TESForm *)(reinterpret_cast<::Callees *>((((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(list)->m_item))))->FUN_00726070())));
                        if (bound)
                        {
                            FUN_004459e0* have = ((::FUN_004459e0 *)(reinterpret_cast<::fnv_00576260::FUN_00576260_shell *>((owner))->FUN_00576260((::fnv_00576260::TESBoundObject *)(bound), 0)));
                            unsigned inventory = have ? ((unsigned int)(reinterpret_cast<::Callees *>((((RecipeInventoryCount*)have)))->FUN_00726070())) : 0;
                            delete have;
                            if (alternate)
                                FUN_00406d00(label, 256, "%s (%d)", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)name)))->FUN_00408da0())),
                                             ((unsigned int)(::FUN_00559450((int *)(((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(list)->m_item)))))));
                            else
                                FUN_00406d00(label, 256, "%s (%d/%d)", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)name)))->FUN_00408da0())), inventory,
                                             ((unsigned int)(::FUN_00559450((int *)(((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(list)->m_item)))))));
                            RecipeAddedItem* added = ((::RecipeAddedItem *)(reinterpret_cast<::Panel515 *>(&(second))->FUN_0072a900((intptr_t)(((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(list)->m_item))), (intptr_t)(label), 0, 0)));
                            if (inventory < ((unsigned int)(::FUN_00559450((int *)(((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(list)->m_item)))))) && !alternate)
                                reinterpret_cast<::Tile *>((((::RecipeTiles *)(reinterpret_cast<::InventoryStackRecord *>(&(added->tile))->GetPayloadAddress()))))->Set(0xfa9, 127);
                            else
                                reinterpret_cast<::Tile *>((((::RecipeTiles *)(reinterpret_cast<::InventoryStackRecord *>(&(added->tile))->GetPayloadAddress()))))->Set(0xfa9, 255);
                        }
                    }
                    else
                        reinterpret_cast<::Panel515 *>(&(second))->FUN_0072a900((intptr_t)(((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(list)->m_item))), (int)(((::FUN_00464f30((intptr_t)("ERROR WITH CAST"))))), 0, 0);
                    list = ((::EntryListNode *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                }
                second.Sort(FUN_00728cd0);
                if (owner)
                {
                    char skill[256];
                    skill[0] = 0;
                    if (((int)(reinterpret_cast<::ActorMover *>((DAT_011d8e94))->GetCurrentMoveModeType())) > -1)
                        FUN_00406d00(skill, 256, "%s (%d/%d)", ::ActorValue::GetActorValueName((::ActorValue::Index)(((int)(reinterpret_cast<::ActorMover *>((DAT_011d8e94))->GetCurrentMoveModeType())))),
                                     reinterpret_cast<::ActorValueOwner *>(&(owner->stats))->GetActorValueAsInteger((::ActorValue::Index)(((int)(reinterpret_cast<::ActorMover *>((DAT_011d8e94))->GetCurrentMoveModeType())))),
                                     ((std::intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((DAT_011d8e94))->FUN_0045cd60())));
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[5]))->FUN_00a01350(0xfc4, (char *)(skill), true);
                    if (((int)(reinterpret_cast<::ActorMover *>((DAT_011d8e94))->GetCurrentMoveModeType())) > -1 &&
                        reinterpret_cast<::ActorValueOwner *>(&(owner->stats))->GetActorValueAsInteger((::ActorValue::Index)(((int)(reinterpret_cast<::ActorMover *>((DAT_011d8e94))->GetCurrentMoveModeType())))) < ((std::intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((DAT_011d8e94))->FUN_0045cd60())))
                        reinterpret_cast<::Tile *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[5]))->Set(0xfa9, 127);
                    else
                        reinterpret_cast<::Tile *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[5]))->Set(0xfa9, 255);
                }
                if (FUN_00727920(DAT_011d8e94))
                    reinterpret_cast<::Tile *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[7]))->Set(0xfaf, 1);
                else
                    reinterpret_cast<::Tile *>((((RecipeEnterMenu*)DAT_011d8e90)->tiles[7]))->Set(0xfaf, 0);
            }
        }
        if (selected)
        {
            reinterpret_cast<::SelfObj *>(this)->FUN_00728da0(((::TESForm *)(reinterpret_cast<::Callees *>((selected))->FUN_00726070())), (::MenuTileList *)(tiles[10]));
            reinterpret_cast<::Tile *>((tiles[10]))->Set(0xfa3, 1);
            TESIcon* icon = dynamic_cast<TESIcon*>(((::TESForm *)(reinterpret_cast<::Callees *>((selected))->FUN_00726070())));
            if (icon && icon->FUN_0048cee0())
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tiles[9]))->FUN_00a01350(0xfcc, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((icon))->FUN_00408da0()))), true);
                reinterpret_cast<::Tile *>((tiles[9]))->Set(0xfa3, 1);
            }
            else
            {
                TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(((::TESForm *)(reinterpret_cast<::Callees *>((selected))->FUN_00726070())));
                if (armor && ((std::intptr_t)(::FUN_00480f80((::TESForm *)(armor), (::TESObjectREFR *)((*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer)))))))
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tiles[9]))->FUN_00a01350(0xfcc, (char *)(armor->names.FUN_00481280(((SexData*)(*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer)))->FUN_0087f4c0())),
                                           true);
                    reinterpret_cast<::Tile *>((tiles[9]))->Set(0xfa3, 1);
                }
                else
                    reinterpret_cast<::Tile *>((tiles[9]))->Set(0xfa3, 0);
            }
        }
        else
            reinterpret_cast<::Tile *>((tiles[9]))->Set(0xfa3, 0);
        break;
    }
    }
}

// Populates a 12-tile menu with item stats, labels, and visibility flags based on the form type and player values.
// @fnv 0x00728da0
void SelfObj::FUN_00728da0(TESForm* apForm, MenuTileList* apTiles)
{
    char j[16];
    {
        float qfTOqo;
        unsigned int qsSDDgz;
        TileObj* qrEZrs[12];
        float qpqRa;
        int qSVM;
        float qdqWL;
        float qpTd;
        int qvyWyw;
        int qHXYKT;
        int qbGYp;
        void* qnuVZg;
        TESBoundObject* qSuoDt;
        {
            char strMod[128];
            float qkbsJ;
            void* qhxpxJd;
            void* qjXCGmG;
            qsSDDgz = 0;
            qHXYKT = FUN_00a01860(::DAT_0106ed20);
            qvyWyw = FUN_00a01860(::DAT_0106ed18);
            qSVM = 0x1009;
            qpqRa = 0.0f;
            qdqWL = 0.0f;
            qfTOqo = ComputeItemValue((float)::FUN_0048e8a0((::TESForm *)(apForm)), 1.0f);
            qpTd = ::TESWeightForm::GetWeightForForm((::TESForm *)(apForm), (int)::FUN_004d1360((char *)(::RecipeStatsPlayerView *)((RecipeStatsPlayerView*)(*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer)))));
            if (apForm && apTiles)
            {
                qjXCGmG = reinterpret_cast<::Callees *>(&(apTiles->links))->FUN_00726070();
                qbGYp = 0;
                while (qjXCGmG != 0 && 12 > qbGYp)
                {
                    qrEZrs[qbGYp] = (TileObj*)(*(intptr_t*)apTiles->links.FUN_00683520(&qjXCGmG));
                    qbGYp += 1;
                }
                while (12 > qbGYp)
                {
                    qrEZrs[qbGYp] = 0;
                    qbGYp++;
                }
                switch (((RecipeStatsFormView*)apForm)->FUN_00401170())
                {
                case 0x28: {
                    unsigned int count30;
                    float local19;
                    int local31;
                    const char* local9;
                    int local_;
                    unsigned int local67;
                    int loaded;
                    unsigned char local10;
                    TESObjectWEAP* weapon4 = (TESObjectWEAP*)apForm;
                    int skillA = ((int)(::GetField19C((char *)(weapon4))));
                    float damage_2;
                    damage_2 = 0.0f;
                    float localX = 0.0f;
                    float conditionalColorA = 1.0f;
                    localX = ::CombatDamageCalculator::CalculateWeaponDamage((::ActorValueOwner *)(void *)((*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer)) ? &((RecipeStatsPlayerView*)(*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer)))->actorValues : 0),
                                          weapon4, conditionalColorA, 1, (::InventoryStackRecord *)(0), 0, 0, -1, 0.0f, 0.0f, 0, 0, (::TESAmmo *)(0));
                    if (conditionalColorA <= 0.0f)
                    {
                        damage_2 = 0.0f;
                    }
                    else
                    {
                        damage_2 = ::GetWeaponDamage(weapon4, conditionalColorA, (::DamageExtra *)(0), (::TESAmmo *)(0));
                    }
                    char local2[128];
                    FUN_00406d00(local2, 0x80, ::InventorySelection::DAT_01020764, (int)::InventoryStackRecord::RoundToNearestStep(localX, 1.0f));
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[1]))->FUN_00a01350(qvyWyw, (char *)(local2), true);
                    DAT_011d8eac = (Tile*)qrEZrs[1];
                    count30 = (unsigned char)((int)(weapon4->GetDamageForActor(0, 0, (::Actor *)(0))));
                    if (count30 > 1)
                    {
                        local19 = damage_2 / (float)count30;
                        FUN_00406d00(local2, 0x80, ::DAT_0106ecf4, (double)local19, count30);
                    }
                    else
                    {
                        FUN_00406d00(local2, 0x80, ::InventorySelection::DAT_01020764, (int)::InventoryStackRecord::RoundToNearestStep(damage_2, 1.0f));
                    }
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[11]))->FUN_00a01350(qvyWyw, (char *)(local2), true);
                    DAT_011d8eb0 = (Tile*)qrEZrs[11];
                    reinterpret_cast<::FUN_00a012d0_t *>((qrEZrs[4]))->FUN_00a012d0(qSVM, FUN_0040ebd0(conditionalColorA, 1.0f), true);
                    FUN_00406d00(local2, 0x80, ::InventorySelection::DAT_01020764, skillA);
                    if (qrEZrs[10])
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[10]))->FUN_00a01350(qvyWyw, (char *)(local2), true);
                    }
                    DAT_011d8eb4 = (Tile*)qrEZrs[10];
                    if (((void *)(reinterpret_cast<::AmmoOwner *>((weapon4))->FUN_00525980((::AmmoActor *)(0)))))
                    {
                        local31 = ((::ProcessObj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((RecipeStatsPlayerView*)(*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer)))))->GetBaseTexture()))->v52();
                        local_ = ((::ProcessObj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((RecipeStatsPlayerView*)(*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer)))))->GetBaseTexture()))->v53();
                        local9 = ::GetStringAtOffsetC4((void *)(((AmmoObj*)((void *)(reinterpret_cast<::AmmoOwner *>((weapon4))->FUN_00525980((::AmmoActor *)(0)))))));
                        local67 = reinterpret_cast<::FUN_004c8f30_shell *>((((::InvChanges *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::FNVAuxController * *>(&::_g_thePlayer))))))))->FUN_004c8f30((intptr_t)(((void *)(reinterpret_cast<::AmmoOwner *>((weapon4))->FUN_00525980((::AmmoActor *)(0))))));
                        loaded = 0;
                        if (!local9 || *local9 == 0)
                        {
                            local9 = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((AmmoObj*)((void *)(reinterpret_cast<::AmmoOwner *>((weapon4))->FUN_00525980((::AmmoActor *)(0)))))->name))->FUN_00408da0()));
                        }
                        local10 = (weapon4->FUN_00709430(0) == 0.0) ? (unsigned char)0 : (unsigned char)1;
                        if (local10)
                        {
                            FUN_00406d00(local2, 0x80, ::DAT_01019f08, local9);
                        }
                        else
                        {
                            FUN_00406d00(local2, 0x80, ::DAT_0106ece8, local9, loaded, local67 - loaded);
                        }
                    }
                    else
                    {
                        ::TaskQueueInterface::CopyStringToBuffer(local2, 0x80, ::DAT_01047008);
                    }
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[5]))->FUN_00a01350(qHXYKT, (char *)(local2), true);
                    qsSDDgz = 0xc3e;
                    break;
                }
                case 0x18:
                case 0x1a: {
                    char local14[128];
                    float local3 = 1.0f;
                    FUN_00406d00(
                        local14, 0x80, ::InventorySelection::DAT_01020764,
                        (int)::InventoryStackRecord::GetConditionPercent(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((float)(::FUN_004be060((void *)(((RecipeStatsArmorView*)apForm))))), local3)));
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[0]))->FUN_00a01350(qvyWyw, (char *)(local14), true);
                    qsSDDgz = 0x1d;
                    break;
                }
                default:
                    qsSDDgz = 0xc;
                    break;
                }

                qnuVZg = 0;
                qSuoDt = dynamic_cast<TESBoundObject*>(apForm);
                qhxpxJd = ((void *)(::TESEnchantableForm::FindFormEnchantment((::TESForm *)(qSuoDt))));
                if (qhxpxJd && !((unsigned char)(reinterpret_cast<::FlaggedData *>((((HolderObj*)qhxpxJd)))->ContainsAnyFlag(4))))
                {
                    qnuVZg = qhxpxJd ? &((HolderObj*)qhxpxJd)->m_24 : 0;
                }
                if (((RecipeStatsFormView*)apForm)->FUN_00401170() == 0x1d)
                {
                    qnuVZg = apForm ? &((RecipeStatsFormView*)apForm)->nameComponent : 0;
                }
                else if (((RecipeStatsFormView*)apForm)->FUN_00401170() == 0x2f)
                {
                    qnuVZg = qSuoDt ? &((RecipeStatsFormView*)qSuoDt)->nameComponent : 0;
                }
                else
                {
                    void* i = ((void *)(::TESEnchantableForm::FindFormEnchantment((::TESForm *)(apForm))));
                    if (i && !((unsigned char)(reinterpret_cast<::FlaggedData *>((((HolderObj*)i)))->ContainsAnyFlag(4))))
                    {
                        qnuVZg = i ? &((HolderObj*)i)->m_24 : 0;
                    }
                }

                if (qnuVZg && *((int *)(&reinterpret_cast<::SimpleListNodeView*>(&(((NamedList*)qnuVZg)->entries))->m_item)))
                {
                    char nameBuf[256];
                    reinterpret_cast<::Description *>((((ListHead*)qnuVZg)))->BuildDescription(nameBuf, 0x100);
                    if (FUN_0044a670(nameBuf) > 0)
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[6]))->FUN_00a01350(qvyWyw, (char *)(nameBuf), true);
                        qsSDDgz |= 0x40;
                    }
                    else
                    {
                        qsSDDgz &= ~0x40;
                    }
                }
                else
                {
                    qsSDDgz &= ~0x40;
                }

                if (qfTOqo > 0.0f)
                {
                    if (qfTOqo >= 1.0)
                    {
                        FUN_00406d00(j, 0x10, ::DAT_0106ecc8, (double)qfTOqo);
                    }
                    else
                    {
                        FUN_00406d00(j, 0x10, ::DAT_01020768, (double)qfTOqo);
                    }
                }
                else
                {
                    ::TaskQueueInterface::CopyStringToBuffer(j, 0x10, ::DAT_01047008);
                }
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[3]))->FUN_00a01350(qvyWyw, (char *)(j), true);

                if (qpTd > 0.0f)
                {
                    if (qpTd >= 1.0)
                    {
                        FUN_00406d00(j, 0x10, ::DAT_0106ecc8, (double)qpTd);
                    }
                    else
                    {
                        FUN_00406d00(j, 0x10, ::DAT_01020768, (double)qpTd);
                    }
                }
                else
                {
                    ::TaskQueueInterface::CopyStringToBuffer(j, 0x10, ::DAT_01047008);
                }
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[2]))->FUN_00a01350(qvyWyw, (char *)(j), true);

                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[0]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[1]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d412c))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[11]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d2c7c))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[2]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d2aa8))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[3]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d26a0))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[4]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d4da4))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[6]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d4edc))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[7]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d4024))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qrEZrs[10]))->FUN_00a01350(qHXYKT, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingObj *>(&::g_011d330c))))->GetMenuTitle()))), true);

                reinterpret_cast<::Tile *>((qrEZrs[0]))->Set(0xfa3, (qsSDDgz & 1) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[1]))->Set(0xfa3, (2 & qsSDDgz) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[11]))->Set(0xfa3, (qsSDDgz & 0x800) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[2]))->Set(0xfa3, (qsSDDgz & 4) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[3]))->Set(0xfa3, (8 & qsSDDgz) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[4]))->Set(0xfa3, (qsSDDgz & 0x10) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[5]))->Set(0xfa3, (qsSDDgz & 0x20) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[6]))->Set(0xfa3, (qsSDDgz & 0x40) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[7]))->Set(0xfa3, (qsSDDgz & 0x80) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[8]))->Set(0xfa3, (qsSDDgz & 0x100) ? 1 : 0);
                reinterpret_cast<::Tile *>((qrEZrs[9]))->Set(0xfa3, (qsSDDgz & 0x200) ? 1 : 0);

                if (qrEZrs[10])
                {
                    reinterpret_cast<::Tile *>((qrEZrs[10]))->Set(0xfa3, (qsSDDgz & 0x400) ? 1 : 0);
                    reinterpret_cast<::FUN_00a012d0_t *>((qrEZrs[10]))->FUN_00a012d0(0xfa9, DAT_01023cd8, true);
                }

                qkbsJ = (float)(((double)(reinterpret_cast<::TileListBoxCalls *>((apTiles))->GetFloat(0xfb0))) / 2.0 - 20.0);
                if ((qsSDDgz & 0x10) || (qsSDDgz & 0x20))
                {
                    qkbsJ = qkbsJ * 2.0f;
                }
                reinterpret_cast<::FUN_00a012d0_t *>((qrEZrs[6]))->FUN_00a012d0(0xfa2, qkbsJ, true);
                reinterpret_cast<::FUN_00a012d0_t *>((qrEZrs[7]))->FUN_00a012d0(0xfa2, qkbsJ, true);
                reinterpret_cast<::FUN_00a012d0_t *>((qrEZrs[8]))->FUN_00a012d0(0xfa2, qkbsJ + qpqRa, true);
                reinterpret_cast<::FUN_00a012d0_t *>((qrEZrs[9]))->FUN_00a012d0(0xfa2, qkbsJ + qdqWL, true);
            }
        }
    }
}

#include "generated/data/fallout/interface/menus/recipemenu.inc"
