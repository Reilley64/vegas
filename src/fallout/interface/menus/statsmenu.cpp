// fallout/interface/menus/statsmenu.cpp: StatsMenu, BodyPartDisplay, ClickMenu, BGSPerk and more (87 functions)

#include <cstdint>
#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDebris.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSQuestObjective.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/EffectItem_shell.h"
#include "fnv/decl/FUN_00403ee0_shell.h"
#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_004044d0_shell.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_00404760_shell.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006166e0_shell.h"
#include "fnv/decl/FUN_0070ec70_class.h"
#include "fnv/decl/FUN_0071f9f0.h"
#include "fnv/decl/FUN_007242c0_shell.h"
#include "fnv/decl/FUN_007254d0_t.h"
#include "fnv/decl/FUN_00725aa0_cls.h"
#include "fnv/decl/FUN_00725f40_shell.h"
#include "fnv/decl/FUN_0073ac90_shell.h"
#include "fnv/decl/FUN_0075f6f0_shell.h"
#include "fnv/decl/FUN_007b52a0_class.h"
#include "fnv/decl/FUN_007d86c0_shell.h"
#include "fnv/decl/FUN_007df120_Class.h"
#include "fnv/decl/FUN_007e0d80_shell.h"
#include "fnv/decl/FUN_007e0e30_Class.h"
#include "fnv/decl/FUN_007f86f0_shell.h"
#include "fnv/decl/FUN_007fa0f0_Class.h"
#include "fnv/decl/FUN_00833c20_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0088c650_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009c1a50_shell.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a013d0_shell.h"
#include "fnv/decl/FUN_00a01440_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a0b110_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a23390_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/LBList.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/Owner050.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/RenderTile.h"
#include "fnv/decl/S00404510.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S725970.h"
#include "fnv/decl/S_00a04150_Class.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk004043d0.h"
#include "fnv/decl/VATSMenuView.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00404560__FUN_00404210_t.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00576260__FUN_00576260_shell.h"
#include "fnv/decl/fnv_0070bc20__FUN_0070bc20_shell.h"
#include "fnv/decl/fnv_00714fd0__FUN_00714fd0_shell.h"
#include "fnv/decl/fnv_007157b0__FUN_007157b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_007d61e0__FUN_007d61e0_shell.h"
#include "fnv/decl/fnv_007d6ff0__FUN_007d6ff0_shell.h"
#include "fnv/decl/fnv_007d74f0__FUN_007d74f0_shell.h"
#include "fnv/decl/fnv_007e1190__LBH.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004d1000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a3000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00719000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_007da000.h"
#include "fnv/symbols_007db000.h"
#include "fnv/symbols_007dc000.h"
#include "fnv/symbols_007dd000.h"
#include "fnv/symbols_007df000.h"
#include "fnv/symbols_007e0000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01064000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_01078000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "../../../statsmenu_types.h"

static const int kGetClassValue = 1003;

// @fnv 0x0071f660
int StatsMenu::GetClass()
{
    return kGetClassValue;
}

// @fnv 0x007df1f0
float ActiveEffect::GetDuration() const
{
    return fDuration;
}
// @fnv 0x007df1d0
EffectSetting* ActiveEffect::GetEffectSetting() const
{
    return ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)(pEffect))->FUN_00825c00()));
}
// @fnv 0x007dd8a0
bool BGSPerk::IsPerkHidden() const
{
    return Data.bHidden;
}
// @fnv 0x007ddef0
float StatsMenu::GetChartScale()
{
    return 1000.0f;
}
// @fnv 0x007dfd00
void StatsMenu::SetStatsPage(unsigned char page)
{
    if (ms_pInventoryMenu)
        ms_pInventoryMenu->SetCurrentPage(static_cast<Page>(page));
}
// Returns the current page as a Page enum, read from the menu's float value at 0x1004.
// @fnv 0x007dcc00
StatsMenu::Page StatsMenu::GetCurrentPage()
{
    return static_cast<Page>(static_cast<unsigned int>(reinterpret_cast<::TileListBoxCalls *>((void *)(pMenu))->GetFloat(0x1004)));
}
// Maps HEALTH, ACTION_POINTS and EXPERIENCE_POINTS actor values to trait IDs 0x1009-0x100B, returning INT_MIN otherwise.
// @fnv 0x007dfdf0
int StatsMenu::GetTraitForValue(ActorValue::Index value)
{
    switch (value)
    {
    case ActorValue::ActorValue__Index_HEALTH:
        return 0x1009;
    case ActorValue::ActorValue__Index_ACTION_POINTS:
        return 0x100A;
    case ActorValue::ActorValue__Index_EXPERIENCE_POINTS:
        return 0x100B;
    default:
        return (-2147483647 - 1);
    }
}
// @fnv 0x007df5d0
void StatsMenu::UpdateStatusEffects()
{
    if (ms_pInventoryMenu && ms_pInventoryMenu->m_pTiles[37])
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ms_pInventoryMenu->m_pTiles[37]))->FUN_00a01350(0xFC4, (char *)(::FUN_0047e0e0(::_g_thePlayer)), true);
}
// @fnv 0x007dda60
void StatsMenu::ClearPerks()
{
    if (ms_pInventoryMenu && ms_pInventoryMenu->m_pTiles[34])
        ms_pInventoryMenu->m_kPerkRankList.ClearList();
}
// @fnv 0x007ddad0
void StatsMenu::RefreshMiscStat(MiscStatManager__MiscStatID value)
{
    ::FUN_007dfc60(((::Tile *)(reinterpret_cast<::Owner *>(&(m_kMiscStatList))->FindItemData((int *)&(value)))), (*(int *)&(value)));
}
// @fnv 0x007dcfc0
void StatsMenu::UpdateActorValueTiles()
{
    RefreshActorValueTile(ActorValue::ActorValue__Index_HEALTH);
    RefreshActorValueTile(ActorValue::ActorValue__Index_ACTION_POINTS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_EXPERIENCE_POINTS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_RADIATION_RADS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_RADIATION_RESISTANCE);
    for (int value = 25; value < 32; ++value)
        RefreshActorValueTile(static_cast<ActorValue::Index>(value));
    m_pTiles[6]->Set(0x1004, 0);
    reinterpret_cast<::LBList_7314c0 *>(&(m_kPrimaryActorValueList))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(UpdatePrimaryActorValueTile), 0, 2147483647);
    m_pTiles[7]->Set(0x1004, 0);
    reinterpret_cast<::LBList_7314c0 *>(&(m_kSecondaryActorValueList))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(::UpdateActorValueTile), 0, 2147483647);
    RefreshActorValueTile(ActorValue::ActorValue__Index_KARMA);
}
// Sets a tile's current actor value and, if it differs from the permanent value, marks it with a (+)/(-) indicator and flags the parent.
// @fnv 0x007dfa30
void StatsMenu::UpdatePrimaryActorValueTile(Tile* tile, ActorValue::Index value)
{
    if (tile)
    {
        struct ActorValues
        {
            int current;
            int permanent;
        } values;
        values.current = ::_g_thePlayer->GetActorValueAsInteger(value);
        values.permanent = ::_g_thePlayer->GetPermanentActorValue(value);
        tile->Set(0x1005, values.current);
        if (values.permanent == values.current)
            tile->Set(0x1004, 0);
        else
        {
            tile->Set(0x1004, 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0x1006, (char *)(values.current > values.permanent ? "(+)" : "(-)"), true);
            ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)(tile))->FUN_0045cd60()))->Set(0x1004, 1);
        }
    }
}

// @fnv 0x007df1b0
bool EffectSetting::IsScriptEffect()
{
    return ::HasEffectArchetypeFlag((*(int *)&(const ::MagicEffectSystem::_Type::Type &)(GetEffectArchetype())), 0x40);
}

struct TileF
{
};
struct ParSI
{
};
struct OptSI
{
    int pad;
    const char* name;
};
struct VObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
struct MenuSI
{
    char pad0[0x44];
    Tile* t44;
    char pad1[0x30];
    Tile* t78;
    char pad2[0x68];
    VObj e4;
    void PopulateListBoxTiles(void*, int, int, int, bool);
};
struct ListBoxSI
{
    bool AddItem(void*);
};
struct ArrSI
{
    OptSI*& GetAt(unsigned int);
};
// Resets the menu, sets tile values from a, b, c and d, then adds each entry of g_011dab88 to lb and creates a named tile for it.
// @fnv 0x007d49a0
void MenuSI::PopulateListBoxTiles(void* apListBox, int aiValueA, int aiValueB, int auiValueC, bool abFlag)
{
    unsigned int i;
    this->e4.v7();
    reinterpret_cast<::fnv_007d74f0::FUN_007d74f0_shell *>(&(this->e4))->FUN_007d74f0(1);
    reinterpret_cast<::fnv_007d61e0::FUN_007d61e0_shell *>((this))->FadeTile(7, 1, 0x80000000, -1.0f);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileF*)this->t44)))->FUN_00a012d0(0xfa1, (float)(aiValueA - reinterpret_cast<::FUN_00a013d0_shell *>((((ParSI*)((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)(this->t44))->FUN_0045cd60())))))->GetTotalFloat()), true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileF*)this->t44)))->FUN_00a012d0(0xfa2, (float)(aiValueB - reinterpret_cast<::FUN_00a01440_shell *>((((ParSI*)((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)(this->t44))->FUN_0045cd60())))))->GetAccumulatedFloat()), true);
    reinterpret_cast<::Tile *>((((TileF*)this->t44)))->Set(0xfb1, (unsigned int)auiValueC);
    this->t78->Set(0xfa3, (int)abFlag);
    for (i = 0; i < ((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::ArrSI *>(&::g_011dab88))))->GetName())); i++)
    {
        if (((ListBoxSI*)(*reinterpret_cast<::ArrSI *>(&::g_011dab88)).GetAt(i))->AddItem(apListBox))
        {
            Tile* ptile = ((::Tile *)(reinterpret_cast<::fnv_007d6ff0::FUN_007d6ff0_shell *>(&(this->e4))->CreateListItem((int)((*reinterpret_cast<::ArrSI *>(&::g_011dab88)).GetAt(i)), (const char *)(0), (int (*)(fnv_007d6ff0::DebrisData *, fnv_007d6ff0::DebrisData *))(0), (const char *)(0))));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::ArrSI *>(&::g_011dab88)).GetAt(i)->name), true);
            reinterpret_cast<::Tile *>((((TileF*)ptile)))->SetName((*reinterpret_cast<::ArrSI *>(&::g_011dab88)).GetAt(i)->name);
        }
    }
}

struct FUN_007dcc40_shell : public StatsMenu
{
    int FUN_007dcc40();
};

// @fnv 0x007dcc40
int FUN_007dcc40_shell::FUN_007dcc40()
{
    return (unsigned int)reinterpret_cast<::TileListBoxCalls *>((void *)(m_pTiles[5]))->GetFloat(0x1004);
}

struct FUN_007df210_shell : public ActiveEffect
{
    bool FUN_007df210();
};

// @fnv 0x007df210
bool FUN_007df210_shell::FUN_007df210()
{
    return (this->iFlags & 0x80) != 0;
}


// @fnv 0x007dfb00
void __cdecl UpdateActorValueTile(Tile* apTile, ActorValue::Index aeIndex)
{
    if (apTile)
    {
        int ival = ::_g_thePlayer->GetActorValueAsInteger(aeIndex);
        int ibase = ::_g_thePlayer->GetPermanentActorValue(aeIndex);
        float fderivedVal = ::GetSkillValue((::ActorStub *)(void *)((ActorValueOwner*)::_g_thePlayer), aeIndex, false);
        float fderivedBase = ::GetSkillValue((::ActorStub *)(void *)((ActorValueOwner*)::_g_thePlayer), aeIndex, true);
        int idelta = (ival - ibase) + ::FUN_00406d90(fderivedVal - fderivedBase);

        apTile->Set(0x1005, ival);
        if (idelta != 0)
        {
            apTile->Set(0x1004, 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((apTile))->FUN_00a01350(0x1006, (char *)(idelta > 0 ? "(+)" : "(-)"), true);
            ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)(apTile))->FUN_0045cd60()))->Set(0x1004, 1);
        }
        else
        {
            apTile->Set(0x1004, 0);
        }
    }
}


// If apTile is non-null, calls Set with 0x1005 and the result of FUN_005a3370(aeID).
// @fnv 0x007dfc60
void __cdecl FUN_007dfc60(Tile* apTile, int aeID)
{
    if (apTile)
    {
        apTile->Set(0x1005, FUN_005a3370(aeID));
    }
}

int __cdecl GetStatusResult(void);

struct DummyAVOwner
{
    virtual void v0();
    virtual void v1();
    virtual int GetActorValueI(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetPermanentActorValueI(int);
};

// Checks whether the player's current actor value is below its permanent value, choosing the target actor value based on hardcore mode and aHO[2].
// @fnv 0x007e05f0
bool __cdecl IsActorValueBelowPermanent(int* aHO)
{
    bool bIsHardcore = ::FUN_004d1360((char *)(::_g_thePlayer));
    if (aHO[2] != 0)
    {
        int etargetAV = GetStatusResult();
        if (bIsHardcore && etargetAV != -1)
        {
            return false;
        }
        else
        {
            if (bIsHardcore || !FUN_004b71d0() || etargetAV == -1)
            {
                etargetAV = 0x10;
            }
        }
        return ((DummyAVOwner*)static_cast<ActorValueOwner *>(::_g_thePlayer))->GetActorValueI(etargetAV) <
               ((DummyAVOwner*)static_cast<ActorValueOwner *>(::_g_thePlayer))->GetPermanentActorValueI(etargetAV);
    }
    else
    {
        return false;
    }
}

struct Dummy_0071f9c0
{
    void* FUN_0071f9c0(unsigned int);
};

bool _ref_008256d0(void*);
void* FUN_0071f9c0(Dummy_0071f9c0*, int, unsigned int);
void _ref_0063f7b0(void*);

struct Caller_0071f9c0
{
    void* call_del(unsigned int f)
    {
        return FUN_0071f9c0((Dummy_0071f9c0*)this, 0, f);
    }
};

// @fnv 0x007e07f0
void FUN_007e07f0(char* this_ptr)
{
    while (!_ref_008256d0(this_ptr + 4))
    {
        Dummy_0071f9c0* p1;
        Dummy_0071f9c0* p2 = (p1 = *((::Dummy_0071f9c0 **)(&reinterpret_cast<::SimpleListNodeView*>(this_ptr + 4)->m_item)));
        (p2 != 0) ? ((void*(*)(Dummy_0071f9c0*, unsigned int))FUN_0071f9c0)(p2, 1) : 0;
        _ref_0063f7b0(this_ptr + 4);
    }
}

struct BGSRadiationStage;
struct SpellListEntry;
struct BSCullingProcess;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderProperty;
struct FOPipboyManager;
struct FORenderedMenu;
struct ShadowLightData;
struct InventoryStackRecord;
struct NiAVObject;
struct NiAlphaProperty;
struct NiDirectionalLight;
struct NiNode;
struct SceneGraph;
struct ShadowSceneNode;
struct SpellItem;
struct TESFile;
struct TESImageSpaceModifier;
struct TileImage;
struct ViewCaster;
struct blob12
{
    char b[12];
};
class Tile;
struct InterfaceManager
{
    static void Free();
    void Init(bool);
    void RefreshInterfaceState();
    SceneGraph* GetOrCreateSceneGraph(SceneGraph*, char*, bool);
    bool IsDoneFirstInit();
    bool IsDoneSecondInit();
    static void PlayUISound(int);
    SceneGraph* GetSceneGraph();
    SceneGraph* Get3DSceneGraph();
    char GetStatsPageNumber();
    char GetInventoryPageNumber();
    char GetMagicPageNumber();
    char GetMapPageNumber();
    void UpdateStatsPageNumber(char);
    void UpdateInventoryPageNumber(char);
    void UpdateMagicPageNumber(char);
    void UpdateMapPageNumber(char);
    void SetStatsPageNumber(char);
    void SetInventoryPageNumber(char);
    void SetMapPageNumber(char);
    static bool IsInterfaceMenuActive();
    static bool IsCurrentRenderedMenuTopmost();
    int GetCurrentMainMenu();
    void SetCurrentMainMenu(int);
    void PreIdleStuff();
    void Idle();
    void ProcessGamepadInput(int);
    int GetGamepadInput(bool, bool, bool*);
    void RefreshGamepadState();
    void RefreshInputState();
    void RecursiveFade(NiAVObject*, float, float);
    Tile* GetPickTarget(bool);
    void SetPickDistance(int);
    int GetPickDistance();
    void SetTelekinesisDistance(int);
    char GetMenuMode();
    bool IsSaveLoadActive();
    void InternalSetMenuMode(int);
    void CalculateConsolePickRefs();
    void ClearMenuInput();
    int GetCursorY();
    int GetRealCursorX();
    int GetRealCursorY();
    float GetRawCursorX();
    float GetRawCursorY();
    void SetRawCursorX(float);
    void SetRawCursorY(float);
    void SetCursorPos(float, float);
    static void SetCursorAlpha(int);
    int GetCursorOffsetX();
    int GetCursorOffsetY();
    int GetTargetID();
    Tile* GetTarget();
    void SetCursorOffsetX(int);
    void SetCursorOffsetY(int);
    void SetTargetID(int);
    void SetTarget(Tile*);
    float GetMouseHeldTime();
    void SetMouseHeldTime(float);
    void Accumulate();
    void Click(BSRenderedTexture*, BSRenderedTexture*);
    TileImage* GetMouseCursorImage();
    void SwitchControllerModes(bool);
    static bool Get360ControllerDisabled();
    void Disable360Controller(bool);
    bool GetMouseVisible();
    void ToggleMouseVisible();
    void SetDebugTextVisible(bool);
    bool GetDebugTextVisible();
    NiNode* GetInterfaceNode();
    Tile* GetCursor();
    NiNode* GetCursorRoot();
    NiNode* GetPlayerRoot();
    Tile* GetPrimaryInterfaceTile();
    Tile* GetSecondaryInterfaceTile();
    void SetStringRoot(Tile*);
    NiNode* GetDebugTextRoot();
    float GetOneToOneDistance();
    ShadowSceneNode* GetShadowNode();
    BSShaderAccumulator* GetAccumulator();
    BSShaderAccumulator* Get3dAccumulator();
    TESImageSpaceModifier* GetImageSpaceModifier();
    Tile* GetCurrentFocusTarget();
    void ClearInterfaceState(Tile*, int, bool);
    void ClearCurrentFocusTarget();
    void GetDefaultFocus();
    static float GetFourthInterfaceFloat();
    static float GetThirdInterfaceFloat();
    static float GetRealScreenLeft();
    static float GetRealScreenRight();
    static float GetRealScreenTop();
    static float GetRealScreenBottom();
    static float UpdateInterfaceState();
    static float GetFirstInterfaceFloat();
    static float GetScreenLeft();
    static float GetScreenRight();
    static float GetScreenTop();
    static float GetScreenBottom();
    static float GetScreenAspect();
    static float GetScreenSafeX();
    static float GetScreenSafeY();
    static float GetMenuHeight();
    static unsigned int GetLastXDefault(int);
    static int GetInputButtonCode(int, bool);
    static void SendGamepadButton(int);
    int GetDragDroppingState();
    void SetDragDroppingState(int);
    void UpdateScreenShape(int, int);
    void ToggleReticle(int);
    void ToggleSafeZone(int);
    void SetNamedMenuOption(char*, bool);
    void SetFirstChanceTextureRelease(bool);
    void ReleaseMenuTextures();
    bool IsAnyMenuOpen();
    Tile* ScanForMaxFocus(int*, Tile*);
    void SetClickMultithreaded(bool);
    bool GetClickMultithreaded();
    void SetRepeatingKey(int);
    int GetRepeatingKey(float);
    void RefreshTargetReference();
    TESObjectREFR* GetTargetREFR();
    void ClearTargetREFR();
    void SetTargetREFR(TESObjectREFR*);
    TESObjectREFR* GetPickedREFR();
    void ClearPickedREFR();
    void SetPickedREFR(TESObjectREFR*);
    TESObjectREFR* GetActivateREFR();
    TESObjectREFR* GetCurrentPickedREFR();
    struct blob12 GetActivatePickLocation();
    bool IsActivatePickFuzzy();
    void SetActivatePickReference(TESObjectREFR*);
    int GetActivatePickResult(int);
    int GetTopEnterStackEntry();
    int GetMenuStackEntry(int);
    bool IsMenuInStack(unsigned int);
    void Test();
    NiAlphaProperty* GetAlphaProp();
    void NeedToUpdate(bool);
    unsigned short GetKeyModifiers();
    int GetChar(int, int);
    bool IsAltDown();
    bool IsControlDown();
    bool IsShiftDown();
    bool TileIsAcceptingEvents(Tile*);
    static void LocalMessgeResults();
    void FreeTimerList();
    void UpdateAllTimers();
    static void NewTimer(void*, float);
    static void ClearTimer(void*);
    static float GetTimerPercent(void*);
    void CullInterfaceMenus();
    void RestoreMenuVisibility();
    void ProcessMenuCulling(BSCullingProcess*, bool);
    void CullPipboyMenus();
    void UncullPipboyMenus();
    void UpdateMenuCulling();
    void RenderBlur(BSRenderedTexture*);
    FOPipboyManager* GetPipboyManagerInstance();
    ShaderRenderProperty* GetHUDEffects();
    ShadowLightData* GetVATSEffect();
    void SetPipboyPickResults(bool, float, float, int);
    void ClearPipboyPickResults();
    void ShowPipboy(int*, int);
    void ClosePipboy(int*);
    void UpdatePipboyState();
    void SetCurrentRenderedMenu(FORenderedMenu*);
    bool IsPipboyMenuOpen();
    void DumpMenuPackingInfo();
    float GetPipboyMouseX();
    float GetPipboyMouseY();
    void GetPipboyMouseCoords(float*, float*);
    static void RegisterListBox(ListBoxBase*);
    static void UnregisterListBox(ListBoxBase*);
    void HandleMenuTileEvent(Menu*, int, Tile*);
    void HandleMenuMouseEvent(Menu*, int, Tile*);
    void HandleMenuSelection(Menu*, int, Tile*);
    bool HandleMenuInput(Menu*, int, float);
    void AddTileIfAbsent(Tile*);
    void RemoveTileFromUpdateList(Tile*);
    void RefreshInterface();
    void QueueCloseSupportMenus();
    void UpdateQueuedMenuClosings();
    static bool Has360Controller();
    static int ConvertGamepadButton(int);
    static void SetDiskError(bool);
    static bool GetMainDiskError();
    bool QLockpickControlsDisable();
    void SetLockpickControlsDisable(bool);
    static void SetContainerMenuQueued(bool);
    static bool GetContainerMenuQueued();
    void* __vecDelDtor(unsigned int);
    bool m_bFirstStateEnabled;
    bool m_bSecondStateEnabled;
    char _pad_2[2];
    char m_kFirstStateData[4];
    char m_kSecondStateData[4];
    int m_iStateEntryCount;
    bool m_bFirstStateActive;
    bool m_bSecondStateActive;
    char m_cFirstStateCode;
    char m_cSecondStateCode;
    char m_cCurrentStateCode;
    char m_kInterfaceAdditionalData;
    char _pad_16[2];
    int m_kDisplayManagerData;
    int m_iSecondaryState;
    unsigned char m_ucFirstFlag;
    unsigned char m_ucSecondFlag;
    char _pad_22[2];
    NiDirectionalLight* m_pDirectionalLight;
    TileImage* kArgumentPosition;
    NiPoint3 m_kFirstVectorData;
    NiPoint3 m_kSecondVectorData;
    float m_fImageTileLeadingValue;
    float m_fImageTileScale;
    Tile* m_pImageTile;
    int m_iImageTileIndex;
    float m_fImageTileOpacity;
    float m_fImageTileBlendAmount;
    int m_iImageTileFirstState;
    int m_iImageTileFirstIndex;
    int m_iImageTileSecondIndex;
    int m_iTargetIndex;
    Tile* pTarget;
    char m_cTargetTextBuffer[8];
    int m_iTargetTextLength;
    bool m_bTargetTextFlag;
    bool m_kInterfaceExtensionData;
    char _pad_7e[2];
    NiNode* m_pFirstSceneNode;
    NiNode* m_pSecondSceneNode;
    ShadowSceneNode* m_pFirstShadowSceneNode;
    char m_kFirstShadowData[4];
    char m_kSecondShadowData[4];
    ShadowSceneNode* m_pSecondShadowSceneNode;
    ShadowSceneNode* m_pThirdShadowSceneNode;
    Tile* m_pFirstSceneTile;
    Tile* m_pSecondSceneTile;
    NiNode* m_pThirdSceneNode;
    float m_fSceneNodeBlendAmount;
    char m_kSceneMetadata[4];
    bool m_bCursorVisible;
    char _pad_b1[1];
    unsigned short m_usPickDistance;
    Tile* m_pFirstAuxiliaryTile;
    Tile* m_pSecondAuxiliaryTile;
    Tile* m_pThirdAuxiliaryTile;
    unsigned int m_uiAuxiliaryTileFlags;
    int m_iAuxiliaryTileIndex;
    bool m_bFirstMenuFirstFlag;
    bool m_bFirstMenuSecondFlag;
    char _pad_ca[2];
    Tile* m_pFirstMenuTile;
    Menu* m_pFirstMenu;
    Tile* m_pSecondMenuTile;
    Menu* m_pSecondMenu;
    bool m_bSecondMenuFirstFlag;
    bool m_bSecondMenuSecondFlag;
    char _pad_de[2];
    Menu* m_pThirdMenu;
    char m_cThirdMenuState;
    char _pad_e5[3];
    int* m_pMenuIndexArray;
    bool m_bFirstReferenceActive;
    bool m_bSecondReferenceActive;
    char _pad_ee[2];
    TESObjectREFR* m_pFirstReference;
    TESObjectREFR* m_pSecondReference;
    TESObjectREFR* m_pThirdReference;
    TESObjectREFR* m_pFourthReference;
    TESObjectREFR* m_pFifthReference;
    NiPoint3 m_kReferenceData;
    bool m_bActivatePickFuzzy;
    char _pad_111[3];
    char m_cPickedObjectName[40];
    ViewCaster* m_pViewCaster;
    MobileObject* m_pFirstMobileObject;
    MobileObject* m_pSecondMobileObject;
    bool m_bMouseVisible;
    bool m_bControllerModeActive;
    char _pad_14a[2];
    int m_kMenuManagerData;
    int m_kInputManagerData;
    unsigned int m_kCursorManagerData;
    unsigned int m_kReferenceManagerData;
    int m_iValueBetweenReferenceAndOverlay;
    unsigned int m_kOverlayManagerData;
    void* m_ppMeasurements;
    bool m_bRenderedMenuActive;
    char _pad_169[3];
    FORenderedMenu* m_pRenderedMenu;
    bool m_bPipboyMenuActive;
    char _pad_171[3];
    FOPipboyManager* m_pPipboyManager;
    char HUDEffects[100];
    char VATSEffect[452];
    float m_fHUDEffectTime;
    float m_fVATSEffectTime;
    bool m_bVATEffectActive;
    char _pad_3a9[3];
    int m_iHUDEffectState;
    int m_iVATEffectState;
    int* m_pInterfaceIntegerData;
    char m_cDebugTextBuffer[8];
    bool m_bDebugInfoVisible;
    bool m_bDebugTextVisible;
    char _pad_3c2[2];
    float m_fDebugTextScale;
    bool m_bDebugOverlayVisible;
    char _pad_3c9[3];
    char m_kInterfaceStateData[172];
public:
    ::Tile *FUN_00586150();
public:
    int FUN_00747d00();
};

struct VDtor
{
    virtual ~VDtor();
};
struct MenuV
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
    virtual int v0d();
};
struct LBV
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(void* callback);
};
struct StartMenu
{
    const char* GetMenuTitle();
};
struct P09AV
{
};
struct FNStub
{
};
struct GlobalObject2_0040c150
{
};
struct IMH
{
};
class TESForm;
enum DEFAULT_OBJECT;
struct BGSDefaultObjectManager
{
public:
    static ::TESForm *GetDefaultObjectByIndex(::DEFAULT_OBJECT);
};
struct BSStringTChar : public BSStringT<char>
{
    using BSStringT<char>::operator=;
    BSStringTChar& operator+=(const char* text);
    operator const char*() const;
};
class MagicItem : public TESFullName
{
};
class SpellItem : public TESForm
{
};
class AlchemyItem : public TESForm
{
};
struct BGSRadiationStage
{
    static BGSRadiationStage* __cdecl GetStageForLevel(float level);
};
struct BGSDehydrationStage
{
    static BGSDehydrationStage* __cdecl FindStage(float level);
};
struct BGSSleepDeprevationStage
{
};
struct BGSHungerStage
{
};
struct GameSettingString
{
    const char* GetString();
};
struct EquipTypeComponent
{
};
template <class T> class BSSimpleListEx : public BSSimpleList<T>
{
  public:
    int GetSize();
};
class StatsMenu__StatusEffect
{
  public:
    class EffectDataList : public BSSimpleListEx<MagicEffectEntry*>
    {
      public:
        virtual ~EffectDataList();
    };
    class NamedEffectsList : public BSSimpleListEx<EffectSetting*>
    {
      public:
        virtual ~NamedEffectsList();
    };
    TESForm* pForm;
    EffectDataList xEffectData;
    NamedEffectsList m_kNamedEffectsList;
    StatsMenu__StatusEffect(SpellItem* spell);
    ~StatsMenu__StatusEffect();
};
class StatusEffectListOps : public BSSimpleList<StatsMenu__StatusEffect*>
{
  public:
    virtual ~StatusEffectListOps();
    void FUN_007e07f0();
};
struct StatusEffectListBox : public ListBox_StatsMenu__StatusEffect___
{
    Tile* AddItem(StatsMenu__StatusEffect* item, int a, int b, int c);
};
struct MagicTargetVT : public MagicTarget
{
    virtual void Unk_01();
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
};
struct ActorMagicTargetView : public MobileObject, public MagicCaster, public MagicTargetVT
{
};
struct ActiveEffectOps : public ActiveEffect
{
};
struct EffectItemOps : public EffectItem
{
};
struct EffectSettingOps : public EffectSetting
{
};
struct TileOps : public Tile
{
};
struct MenuOps : public Menu
{
};
struct TESFullNameOps : public TESFullName
{
};
struct StatsMenuActiveEffects : public StatsMenu
{
    void FUN_007ddf00();
};

struct ActorValueUtility
{
    static int __cdecl ConvertActorValue(int);
};
struct AVH
{
};
struct TutorialState
{
};
struct LBH
{
    void Initialize(Tile*, const char*);
};
enum ReputationType;
struct TESReputation
{
    static unsigned int* __cdecl GetUnsignedIntegerPointer(unsigned int*);
public:
    float GetUnsignedIntegerPointer(::ReputationType);
public:
    const char *FUN_00616710();
};
struct MenuH
{
    bool HasAllSlots();
    void UpdateXboxButtonState();
};
struct ActorH
{
};
struct Calendar
{
};
struct TileH
{
};
struct StatusH
{
    void FUN_007db250(Tile*);
    void SetFieldBits(int, int);
};
struct StrH
{
};

struct Flt
{
    operator unsigned int() const;
};

int __cdecl FUN_004d5e00();
const char* __cdecl GetGameSettingString(int);
bool __cdecl IsActorValueBelowPermanent(int*);
bool __cdecl IsPlayerSubObjectValueAboveThreshold(int*);

// @fnv 0x007da2c0
Tile* FUN_007da2c0()
{
    Menu* pold_menu_tile = ((::Menu *)(::FUN_00a09030(FUN_004d5e00())));
    if (pold_menu_tile)
        delete (VDtor*)pold_menu_tile;
    InterfaceManager* pin = (InterfaceManager*)((void *)(::fnv_004b7210::FUN_004b7210()));
    float ftop_depth = ::Tile::GetInterfaceScale();
    Tile* ptile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((((TileH*)reinterpret_cast<::InterfaceManager *>((((IMH*)pin)))->FUN_00586150())))->FUN_00a01b00((void *)("Data\\Menus\\Main\\stats_menu.xml"));
    StatsMenu::ms_pInventoryMenu = (StatsMenu*)reinterpret_cast<::FUN_00a03c90_shell *>((((TileH*)ptile)))->FUN_00a03c90();
    ::fnv_00a1ca20::RemoveMenuEntries("Data\\Menus\\Main\\stats_menu.xml", StatsMenu::ms_pInventoryMenu);
    ::FUN_00867a20((void *)(((MenuH*)StatsMenu::ms_pInventoryMenu)));
    if (StatsMenu::ms_pInventoryMenu && ((MenuV*)StatsMenu::ms_pInventoryMenu)->v0d() == FUN_004d5e00())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((((MenuH*)StatsMenu::ms_pInventoryMenu)))->FUN_00a1dc70((TileMenu*)ptile, false);
        if (!((MenuH*)StatsMenu::ms_pInventoryMenu)->HasAllSlots())
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((void *)(ptile))->GetFloat(0xfa7) == ::DAT_010704f0 || reinterpret_cast<::TileListBoxCalls *>((void *)(ptile))->GetFloat(0xfa7) == ::DAT_010704e8)
            reinterpret_cast<::FUN_00a012d0_t *>((((TileH*)ptile)))->FUN_00a012d0(0xfad, ftop_depth, true);
        reinterpret_cast<::TutorialMessageGate718 *>((((TutorialState*)((char*)((void *)(::fnv_004b7210::FUN_004b7210())) + 0x4d4))))->FUN_00718630(0x19, FUN_004d5e00(), 0x200);
        ::fnv_007df4e0::UpdateStatsMenuLevelText();
        BGSRadiationStage* pstage = BGSRadiationStage::GetStageForLevel(3.402823466e+38F);
        reinterpret_cast<::Tile *>((((TileH*)ptile)))->Set(0x1006, pstage ? ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((Calendar*)pstage)))->FUN_009611e0())) : 1000);
        BSStringT<char> strtmp;
        const char* pformat = "%d/%d";
        ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), pformat, ::_g_thePlayer->GetActorValue((ActorValue::Index)0x10),
                       ::_g_thePlayer->GetPermanentActorValue((ActorValue::Index)0x10));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1009, (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), pformat, ::_g_thePlayer->GetActorValue((ActorValue::Index)0xc),
                       ::_g_thePlayer->GetPermanentActorValue((ActorValue::Index)0xc));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x100a, (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        if (reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((ActorH*)::_g_thePlayer)))->FUN_0087f9f0() >= *((int *)&(::FUN_0043d4d0((int *)&(::g_011d0c60)))))
        {
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), DAT_01019f08, (*reinterpret_cast<::StartMenu *>(&::g_011d472c)).GetMenuTitle());
        }
        else
        {
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), pformat, ::_g_thePlayer->GetActorValue((ActorValue::Index)0x18),
                           ActorValueUtility::ConvertActorValue(reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((ActorH*)::_g_thePlayer)))->FUN_0087f9f0() + 1));
        }
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x100b, (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        ptile->Set(0x100c, reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((ActorH*)::_g_thePlayer)))->FUN_0087f9f0());
        strtmp = "stats_list_template";
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPrimaryActorValueList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[6], (const char*)(unsigned int)*(Flt*)&strtmp);
        for (int i = 0; i < ::ActorValue::GetCountForSection((::ActorValue::Section)(0)); i++)
        {
            ActorValue::Index eindex = ::ActorValue::GetActorValueForSectionIndex((::ActorValue::Section)(0), (unsigned char)i);
            if (!::FUN_00406d70(eindex, 0x2000) && eindex != 0x1f)
            {
                Tile* ptmp =
                    ((::Tile *)(reinterpret_cast<::Owner050 *>((((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPrimaryActorValueList)))->AddListEntry(eindex, (const char *)(0), 0, (const char *)(0))));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptmp))->FUN_00a01350(0xfc4, (char *)(::ActorValue::GetActorValueName(eindex)), true);
                reinterpret_cast<::Tile *>((((TileH*)ptmp)))->SetName(::ActorValue::GetActorValueName(eindex));
            }
        }
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[7], (const char*)(unsigned int)*(Flt*)&strtmp);
        for (int i = 0; i < ::ActorValue::GetCountForSection((::ActorValue::Section)(2)); i++)
        {
            ActorValue::Index eindex = ::ActorValue::GetActorValueForSectionIndex((::ActorValue::Section)(2), (unsigned char)i);
            if (!::FUN_00406d70(eindex, 0x2000) && eindex != 0x1f)
            {
                Tile* ptmp =
                    ((::Tile *)(reinterpret_cast<::Owner050 *>((((LBH*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)))->AddListEntry(eindex, (const char *)(0), 0, (const char *)(0))));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptmp))->FUN_00a01350(0xfc4, (char *)(::ActorValue::GetActorValueName(eindex)), true);
                reinterpret_cast<::Tile *>((((TileH*)ptmp)))->SetName(::ActorValue::GetActorValueName(eindex));
            }
        }
        ((LBV*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)->v08((void*)((void (&)())::CompareActorValueNames));
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPerkRankList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[34], (const char*)(unsigned int)*(Flt*)&strtmp);
        ::fnv_007dd710::FUN_007dd710();
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kReputationList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[46], (const char*)(unsigned int)*(Flt*)&strtmp);
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kMiscStatList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[8], (const char*)(unsigned int)*(Flt*)&strtmp);
        for (MiscStatManager__MiscStatID eMiscStat = MiscStatManager__MiscStatID_MS_QUESTS_COMPLETED;
             eMiscStat < MiscStatManager__MiscStatID_MS_COUNT;
             TESReputation::GetUnsignedIntegerPointer((unsigned int*)&eMiscStat))
        {
            Tile* ptile = ((::Tile *)(reinterpret_cast<::fnv_007e1190::LBH *>((((LBH*)&StatsMenu::ms_pInventoryMenu->m_kMiscStatList)))->FUN_007e1190(eMiscStat, (const char *)(0), 0, (const char *)(0))));
            const char* ptext = GetGameSettingString(eMiscStat);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0xfc4, (char *)(ptext), true);
            ptile->Set(0x1005, FUN_005a3370(eMiscStat));
            reinterpret_cast<::Tile *>((((TileH*)ptile)))->SetName(ptext);
        }
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[47]))->FUN_00a01350(0xfcc, (char *)("Interface\\shared\\solid_black.dds"), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[47]->Set(0xfa3, 0);
        TESForm* pform = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0));
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[10];
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].pTile))->FUN_00a01350(
            0x1004, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)dynamic_cast<TESFullName*>(pform))))->FUN_00408da0()))), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsActorValueBelowPermanent;
        pform = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x15));
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[59];
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].pTile))->FUN_00a01350(
            0x1004, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)dynamic_cast<TESFullName*>(pform))))->FUN_00408da0()))), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsHealingOptionAvailable;
        pform = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(2));
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[31];
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].pTile))->FUN_00a01350(
            0x1004, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)dynamic_cast<TESFullName*>(pform))))->FUN_00408da0()))), true);
        pform = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(3));
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[11];
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].pTile))->FUN_00a01350(
            0x1004, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)dynamic_cast<TESFullName*>(pform))))->FUN_00408da0()))), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsPlayerSubObjectValueAboveThreshold;
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kStatusEffectList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[33], "stats_effects_template");
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[12]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[13]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[24]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[18]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[19]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[14]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[15]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[16]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[17]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[22]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[23]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[20]);
        ((::StatusH *)(::FUN_007db1c0()))->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[21]);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(1, 2);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(2, 1);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(3, 3);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(0, 0);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(1, 4);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(2, 1);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(3, 3);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(0, 0);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(1, 4);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(3, 2);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(0, 0);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(1, 5);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(2, 2);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(0, 2);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(3, 5);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(0, 2);
        ((::StatusH *)(::FUN_007db1c0()))->SetFieldBits(2, 4);
        StatsMenu::ms_pInventoryMenu->UpdateActorValueTiles();
        ((MenuH*)StatsMenu::ms_pInventoryMenu)->UpdateXboxButtonState();
        strtmp = (*reinterpret_cast<::StartMenu *>(&::g_011d30c0)).GetMenuTitle();
        reinterpret_cast<::FUN_007b52a0_class *>((((StrH*)&strtmp)))->FUN_007b52a0();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(::FUN_00a00940("_rads", -1), (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        strtmp = (*reinterpret_cast<::StartMenu *>(&::g_011d1f08)).GetMenuTitle();
        reinterpret_cast<::FUN_007b52a0_class *>((((StrH*)&strtmp)))->FUN_007b52a0();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(::FUN_00a00940("_h20", -1), (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        strtmp = (*reinterpret_cast<::StartMenu *>(&::g_011d37c8)).GetMenuTitle();
        reinterpret_cast<::FUN_007b52a0_class *>((((StrH*)&strtmp)))->FUN_007b52a0();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(::FUN_00a00940("_hunger", -1), (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        strtmp = (*reinterpret_cast<::StartMenu *>(&::g_011d246c)).GetMenuTitle();
        reinterpret_cast<::FUN_007b52a0_class *>((((StrH*)&strtmp)))->FUN_007b52a0();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(::FUN_00a00940("_sleep", -1), (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[39]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d3fdc)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[40]))->FUN_00a01350(::FUN_00a00940(::DAT_0106ed20, -1), (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d1f5c)).GetMenuTitle()),
                                                        true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[41]))->FUN_00a01350(::FUN_00a00940(::DAT_0106ed20, -1), (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d50b0)).GetMenuTitle()),
                                                        true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[42]))->FUN_00a01350(::FUN_00a00940(::DAT_0106ed20, -1), (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d44a4)).GetMenuTitle()),
                                                        true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[43]))->FUN_00a01350(::FUN_00a00940(::DAT_0106ed20, -1), (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d3bd4)).GetMenuTitle()),
                                                        true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[28]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d48d0)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d3e74)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x100d, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d2e80)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x100e, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d41bc)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[44]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d47ec)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[45]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d2ebc)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[0]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d2f88)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[1]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d2994)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[2]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d3b08)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[3]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d4bd0)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[4]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::StartMenu *>(&::g_011d4ef4)).GetMenuTitle()), true);
        reinterpret_cast<::Menu *>((((MenuH*)StatsMenu::ms_pInventoryMenu)))->SetMenuVisibility(true);
        return ptile;
    }
    else
    {
        if (StatsMenu::ms_pInventoryMenu && ((std::intptr_t)(reinterpret_cast<::Callees *>((((MenuH*)StatsMenu::ms_pInventoryMenu)))->FUN_00726070())))
            delete (VDtor*)StatsMenu::ms_pInventoryMenu;
    }
    return 0;
}

namespace fnv_00404820 {
struct Flt
{
    operator unsigned int() const;
};
struct S7010
{
};
struct StrMem
{
};
struct StrArg
{
    const char* p;
};
// Appends arg.p to the BSStringT, growing the buffer via Set when the combined length exceeds MaxLength, then copies the string and updates the length.
// @fnv 0x00404820
BSStringT<char>* FUN_00404820(BSStringT<char>* self, StrArg aStrArg)
{
    unsigned int uiTotalLen;
    unsigned int uiSrcLen;
    if (aStrArg.p)
    {
        if ((unsigned int)*(Flt*)self)
        {
            uiSrcLen = aStrArg.p ? ::FUN_0044a670(aStrArg.p) : 0;
            uiTotalLen = ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)self)))->FUN_004048e0())) + uiSrcLen;
            if (uiTotalLen > self->MaxLength())
                reinterpret_cast<::TextString *>((((StrMem*)self)))->FUN_004037f0((const char*)(unsigned int)*(Flt*)self, uiTotalLen);
            ::__memcpy(*(char**)self + ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)self)))->FUN_004048e0())), aStrArg.p, uiSrcLen + 1);
            self->SetLength(uiTotalLen);
        }
        else
        {
            reinterpret_cast<::TextString *>((((StrMem*)self)))->FUN_004037f0(aStrArg.p, 0);
        }
    }
    return self;
}
}  // namespace fnv_00404820

namespace fnv_007dd090 {
struct Setting_S
{
    const char* String();
};
struct Setting_I
{
};
struct ActorValueUtility
{
};
struct StatsMenuImpl : public StatsMenu
{
    void UpdateStatEntry(int aeWhich);
};
struct TileF
{
};
struct ActorLevelHelper
{
};
struct StatsMenuHelper
{
    void UpdatePipboyNeedle();
    void UpdateOption(int mode);
    int FUN_007dfe40();
};
extern const char* DAT_011a0a80[];

// Updates the stats menu tile for the given actor value: formats value text, sets image/bar tiles, and handles special cases like level, resistances, and karma.
// @fnv 0x007dd090
void StatsMenuImpl::UpdateStatEntry(int aeWhich)
{
    int eimage = 60;
    int ebar = 60;
    BSStringT<char> strtmp;
    const char* pformat = "%d/%d";

    switch (aeWhich)
    {
    case 16:
        ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "Interface\\Stats\\face_%02d.dds", ((StatsMenuHelper*)this)->FUN_007dfe40());
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[24]))->FUN_00a01350(0xfcc, (char *)(((const char *)(::FUN_00559450((int *)&(strtmp))))), true);
        ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), pformat, ::_g_thePlayer->GetActorValue((ActorValue::Index)16),
                       ::_g_thePlayer->GetPermanentActorValue((ActorValue::Index)16));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::Tile *)(reinterpret_cast<::Callees *>((((StatsMenuHelper*)this)))->FUN_00726070()))))->FUN_00a01350(GetTraitForValue((ActorValue::Index)16), (char *)(((const char *)(::FUN_00559450((int *)&(strtmp))))), true);
        ((StatsMenuHelper*)this)->UpdateOption(0);
        break;
    case 12:
        ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), pformat, ::_g_thePlayer->GetActorValue((ActorValue::Index)12),
                       ::_g_thePlayer->GetPermanentActorValue((ActorValue::Index)12));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::Tile *)(reinterpret_cast<::Callees *>((((StatsMenuHelper*)this)))->FUN_00726070()))))->FUN_00a01350(GetTraitForValue((ActorValue::Index)12), (char *)(((const char *)(::FUN_00559450((int *)&(strtmp))))), true);
        break;
    case 24:
        if (reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((ActorLevelHelper*)::_g_thePlayer)))->FUN_0087f9f0() >= *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_007dd090::Setting_I *>(&::g_011d0c60)))))))
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%s", (*reinterpret_cast<::fnv_007dd090::Setting_S *>(&::g_011d472c)).String());
        else
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), pformat, ::_g_thePlayer->GetActorValue((ActorValue::Index)24),
                           ::ActorValueUtility::ConvertActorValue(reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((ActorLevelHelper*)::_g_thePlayer)))->FUN_0087f9f0() + 1));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::Tile *)(reinterpret_cast<::Callees *>((((StatsMenuHelper*)this)))->FUN_00726070()))))->FUN_00a01350(GetTraitForValue((ActorValue::Index)24), (char *)(((const char *)(::FUN_00559450((int *)&(strtmp))))), true);
        break;
    case 54:
        ((StatsMenuHelper*)this)->UpdatePipboyNeedle();
        ((StatsMenuHelper*)this)->UpdateOption(2);
        reinterpret_cast<::StatsMenuActiveEffects *>((((StatsMenuHelper*)this)))->FUN_007ddf00();
        break;
    case 20: {
        int iresist = ::MinInt((int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007dd090::Setting_S *>(&::originalRuntimeFloatSetting1017)))))),
                             ::_g_thePlayer->GetActorValueAsInteger((ActorValue::Index)20));
        ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%d%%", iresist);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[38]))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(strtmp))))), true);
        reinterpret_cast<::StatsMenuActiveEffects *>((((StatsMenuHelper*)this)))->FUN_007ddf00();
        break;
    }
    case 25:
        eimage = 12;
        ebar = 13;
    case 26:
        if (eimage == 60)
        {
            eimage = 14;
            ebar = 15;
        }
    case 27:
        if (eimage == 60)
        {
            eimage = 16;
            ebar = 17;
        }
    case 28:
        if (eimage == 60)
        {
            eimage = 18;
            ebar = 19;
        }
    case 29:
        if (eimage == 60)
        {
            eimage = 20;
            ebar = 21;
        }
    case 30:
        if (eimage == 60)
        {
            eimage = 22;
            ebar = 23;
        }
        {
            float fval = ::_g_thePlayer->GetCurrentActorValue((ActorValue::Index)aeWhich) / 100.0;
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), fval > 0.0 ? "Interface\\Stats\\%s.dds" : "Interface\\Stats\\%s_broken.dds",
                           DAT_011a0a80[aeWhich]);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[eimage]))->FUN_00a01350(0xfcc, (char *)(((const char *)(::FUN_00559450((int *)&(strtmp))))), true);
            reinterpret_cast<::FUN_00a012d0_t *>((((TileF*)m_pTiles[ebar])))->FUN_00a012d0(::FUN_00a00940("_Value", -1), fval, true);
            if (m_bUpdateOption)
                ((StatsMenuHelper*)this)->UpdateOption(0);
            break;
        }
    case 23:
        switch (((unsigned int)(::fnv_0047e040::FUN_0047e040(::_g_thePlayer->GetCurrentActorValue((ActorValue::Index)23)))))
        {
        case 1:
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[36]))->FUN_00a01350(0xfcc, (char *)("Interface\\Icons\\PipboyImages\\Karma icons\\karma_neutral.dds"), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[35]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dd090::Setting_S *>(&::g_011d3204)).String()), true);
            break;
        case 0:
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[36]))->FUN_00a01350(0xfcc, (char *)("Interface\\Icons\\PipboyImages\\Karma icons\\karma_good.dds"), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[35]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dd090::Setting_S *>(&::g_011d41b0)).String()), true);
            break;
        case 2:
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[36]))->FUN_00a01350(0xfcc, (char *)("Interface\\Icons\\PipboyImages\\Karma icons\\karma_bad.dds"), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[35]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dd090::Setting_S *>(&::g_011d457c)).String()), true);
            break;
        case 3:
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[36]))->FUN_00a01350(0xfcc, (char *)("Interface\\Icons\\PipboyImages\\Karma icons\\karma_saintly.dds"), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[35]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dd090::Setting_S *>(&::g_011d4ffc)).String()), true);
            break;
        case 4:
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[36]))->FUN_00a01350(0xfcc, (char *)("Interface\\Icons\\PipboyImages\\Karma icons\\karma_evil.dds"), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[35]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dd090::Setting_S *>(&::g_011d31d4)).String()), true);
            break;
        }
        StatsMenu::UpdateStatusEffects();
        break;
    default:
        StatsMenu::UpdatePrimaryActorValueTile(((::Tile *)(reinterpret_cast<::Owner *>((((ListBox_enum_MiscStatManager__MiscStatID_*)&m_kPrimaryActorValueList)))->FindItemData((int *)&(*(MiscStatManager__MiscStatID*)&aeWhich)))),
                                               (ActorValue::Index)aeWhich);
        ::UpdateActorValueTile(
            ((::Tile *)(reinterpret_cast<::Owner *>((((ListBox_enum_MiscStatManager__MiscStatID_*)&m_kSecondaryActorValueList)))->FindItemData((int *)&(*(MiscStatManager__MiscStatID*)&aeWhich)))),
            (ActorValue::Index)aeWhich);
        break;
    }
}
}  // namespace fnv_007dd090

namespace fnv_007df4e0 {
struct LevelS
{
};
struct MenuActiveS
{
    const char* GetMenuTitle();
};
struct MenuTileS
{
};
struct GlobalObject_0040c150
{
    int x;
};
struct Flt
{
    operator unsigned int() const;
};

// @fnv 0x007df4e0
void UpdateStatsMenuLevelText()
{
    if (StatsMenu::ms_pInventoryMenu && ::_g_thePlayer)
    {
        BSStringT<char> strtmp;
        ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%s - %s %hd", reinterpret_cast<::FUN_0055d520_shell *>((((LevelS*)::_g_thePlayer)))->FUN_0055d520(),
                       ((MenuActiveS*)&(*reinterpret_cast<::fnv_007df4e0::GlobalObject_0040c150 *>(&::g_011d2028)))->GetMenuTitle(), reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((LevelS*)::_g_thePlayer)))->FUN_0087f9f0());
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[27]))->FUN_00a01350(0xfc4, (char *)((const char*)(unsigned int)*(Flt*)&strtmp), true);
        ((::Tile *)(reinterpret_cast<::Callees *>((((MenuTileS*)StatsMenu::ms_pInventoryMenu)))->FUN_00726070()))->Set(0x100c, reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((((LevelS*)::_g_thePlayer)))->FUN_0087f9f0());
    }
}
}  // namespace fnv_007df4e0

struct FUN_007dfe40_shell : public StatsMenu
{
    int FUN_007dfe40();
};

struct Script
{
    int GetText();
};
struct AEHelper
{
};
struct NodeHelper
{
};
struct EffectList
{
    virtual void v0();
    virtual void v1();
    virtual NodeHelper* GetFirst();
};
struct ValueSrc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetMax(int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetCur(int);
};

// @fnv 0x007dfe40
int FUN_007dfe40_shell::FUN_007dfe40()
{
    NodeHelper* node;
    float fdmg;
    float fmax;
    int iLevel;
    for (node = ((EffectList*)static_cast<MagicTarget *>(::_g_thePlayer))->GetFirst(); node && *((::Script **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
         node = ((::NodeHelper *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        if (((int)(reinterpret_cast<::BGSMessageInitAccess *>(((*((::Script **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))->GetIconFormID())) == 10 && ((bool)(reinterpret_cast<::FUN_00833c20_shell *>((((AEHelper*)*((::Script **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))->FUN_00833c20())))
            return 10;
    }
    fmax = (float)((ValueSrc*)static_cast<ActorValueOwner *>(::_g_thePlayer))->GetCur(0x10);
    fdmg = fmax - ((ValueSrc*)static_cast<ActorValueOwner *>(::_g_thePlayer))->GetMax(0x10);
    iLevel = (int)(fdmg / fmax * 5.0);
    if (iLevel < 0)
        iLevel = 0;
    if (iLevel > 4)
        iLevel = 4;
    return iLevel;
}

struct FUN_00404210_t
{
    MagicEffectEntry data;
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    void CopyFrom(FUN_00404210_t* apSource);
};

// @fnv 0x00404210
void FUN_00404210_t::CopyFrom(FUN_00404210_t* apSource)
{
    m_pEffectSetting = apSource->m_pEffectSetting;
    reinterpret_cast<::fnv_00404560::FUN_00404210_t *>(this)->FUN_00404560(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apSource))->FUN_0084e3a0())));
    reinterpret_cast<::Unk004043d0 *>(this)->FUN_004043d0(reinterpret_cast<::FUN_00404390_shell *>((apSource))->FUN_00404390());
    reinterpret_cast<::EffectItem_shell *>(this)->FUN_00404470(reinterpret_cast<::FUN_00404420_shell *>((apSource))->FUN_00404420());
    reinterpret_cast<::S00404510 *>(this)->FUN_00404510(reinterpret_cast<::FUN_004044d0_shell *>((apSource))->FUN_004044d0());
    reinterpret_cast<::BGSQuestObjective *>(this)->SetOwner((::TESQuest *)(reinterpret_cast<::EffectItem *>((apSource))->GetAffectedActorValue()));
    reinterpret_cast<::FUN_00404760_shell *>(this)->FUN_00404760(((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>((apSource))->GetDataList())));
    m_fCost = -1.0f;
}

struct BodyPartDisplay
{
    int m_currentBodyPart;
    void SetBodyPart(int aeBodyPart, bool abFlash);
    void FUN_007dbfe0(int arg);
};

// @fnv 0x007dbfa0
void BodyPartDisplay::SetBodyPart(int aeBodyPart, bool abFlash)
{
    if (abFlash)
    {
        FUN_007dbfe0(0);
    }
    m_currentBodyPart = aeBodyPart;
    if (abFlash)
    {
        FUN_007dbfe0(1);
    }
}

namespace fnv_007dcb40 {
struct FNStub
{
};
struct TESReputation
{
};
struct FUN_007dcb40_t : public StatsMenu
{
    void SetReputationEntry(TESReputation* pRep);
};

// @fnv 0x007dcb40
void FUN_007dcb40_t::SetReputationEntry(TESReputation* pRep)
{
    if (!pRep)
        return;
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[47]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_006166e0_shell *>((pRep))->GetReputationName()), true);
    m_pTiles[47]->Set(0xfa3, 1);
    m_pTiles[48]->Set(0xfa3, 1);
    m_pTiles[51]->Set(0xfa3, 1);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[51]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)pRep + 0x18))))->FUN_00408da0()))), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[48]))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::TESReputation *>((pRep))->FUN_00616710()), true);
}
}  // namespace fnv_007dcb40

struct FOPipboyManager
{
public:
    bool IsUnk28Set();
};
struct Interface
{
    FOPipboyManager* GetPipboyManager();
};


// If a stats menu exists, gets the pipboy manager and plays sounds for the menu's current page.
// @fnv 0x007dfc90
void PlayPipboyPageSound(bool abPlaySounds)
{
    if (StatsMenu::ms_pInventoryMenu)
        reinterpret_cast<::FUN_007fa0f0_Class *>((reinterpret_cast<Interface*>(((void *)(::fnv_004b7210::FUN_004b7210())))
            ->GetPipboyManager()))->SetValue(StatsMenu::ms_pInventoryMenu->GetCurrentPage(), abPlaySounds);
}

namespace fnv_007dff40 {
struct FUN_007dff40_shell : public StatsMenu
{
    void SetPage(int);
};

class FORenderedMenu
{
  public:
    void StartBurst(float, float, float);
};
class FOPipboyManager : public FORenderedMenu
{
};
class Interface
{
  public:
    FOPipboyManager* GetPipboyManager();
};
struct VATSMenuView
{
};
struct FUN_007dc7e0_t
{
    void UpdateStatsDisplay(int);
    void UpdateScrollBar(void*);
    void RefreshHealingOptions();
};
struct Setting_S
{
};

// Validates aePage (0-4), updates the Pipboy menu, sets menu value 0x1004 to aePage, and applies page-specific actions.
// @fnv 0x007dff40
void FUN_007dff40_shell::SetPage(int aePage)
{
    if (aePage < 0 || aePage > 4)
        return;
    ((Interface*)((void *)(::fnv_004b7210::FUN_004b7210())))->GetPipboyManager()->StartBurst(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007dff40::Setting_S *>(&::g_011db458)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007dff40::Setting_S *>(&::g_011db37c)))))), 0.5f);
    pMenu->Set(0x1004, aePage);
    if (reinterpret_cast<::FOPipboyManager *>((((Interface*)((void *)(::fnv_004b7210::FUN_004b7210())))->GetPipboyManager()))->IsUnk28Set())
        ::PlayPipboyPageSound(1);
    if (m_bUpdateOption)
        ((FUN_007dc7e0_t*)this)->RefreshHealingOptions();
    if (aePage == 1)
        ((FUN_007dc7e0_t*)this)->UpdateStatsDisplay(5);
    else if (aePage == 2)
        ((FUN_007dc7e0_t*)this)->UpdateStatsDisplay(0x20);
    else if (aePage == 3 && reinterpret_cast<::VATSMenuView *>((((VATSMenuView*)&m_kPerkRankList)))->FUN_00726710())
        ((FUN_007dc7e0_t*)this)->UpdateScrollBar(((void *)(reinterpret_cast<::FUN_007d86c0_shell *>((((VATSMenuView*)&m_kPerkRankList)))->FUN_007d86c0((int *)(0), 0))));
    else
        m_pTiles[25]->Set(0xfa3, 0);
}
}  // namespace fnv_007dff40

struct FUN_007e0160_t : public StatsMenu
{
    bool GetTileIndex(int aiTileID, int* apIndex);
};

// Maps a tile ID (0x1c,0x1d,0x1e,0x35,0x37,0x39) to an index written to apIndex and returns true, otherwise returns false.
// @fnv 0x007e0160
bool FUN_007e0160_t::GetTileIndex(int aiTileID, int* apIndex)
{
    switch (aiTileID)
    {
    case 0x1c:
        *apIndex = 0;
        return true;
    case 0x1d:
        *apIndex = 1;
        return true;
    case 0x1e:
        *apIndex = 2;
        return true;
    case 0x35:
        *apIndex = 3;
        return true;
    case 0x37:
        *apIndex = 4;
        return true;
    case 0x39:
        *apIndex = 5;
        return true;
    }
    return false;
}

namespace fnv_007e0510 {
class FNStub
{
  public:
};


// Compares the full names of the FNStub objects referenced at offset 4 of a and b using _stricmp and returns the result.
// @fnv 0x007e0510
int __cdecl CompareEntryNames(void* pEntryA, void* pEntryB)
{
    return ::FUN_00404dc0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)*(void**)((char*)pEntryA + 4) + 0x18))))->FUN_00408da0())),
                    ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)*(void**)((char*)pEntryB + 4) + 0x18))))->FUN_00408da0())));
}
}  // namespace fnv_007e0510


struct FUN_007e0540_effect
{
};

// Compares the effect names of two effects case-insensitively via _stricmp and returns the result.
// @fnv 0x007e0540
int __cdecl CompareEffectNames(FUN_007e0540_effect* apEffectA, FUN_007e0540_effect* apEffectB)
{
    return ::FUN_00404dc0((*(::BSStringTChar *)(reinterpret_cast<::FUN_004046b0_cls *>((void *)(apEffectA))->AssignFromSub({}))), (*(::BSStringTChar *)(reinterpret_cast<::FUN_004046b0_cls *>((void *)(apEffectB))->AssignFromSub({}))));
}

int __cdecl GetStatusResult();
// @fnv 0x007e06f0
bool __cdecl IsHealingOptionAvailable(StatsMenu__HealingOption* apOption)
{
    bool bResult = ::FUN_004d1360((char *)(::_g_thePlayer));
    if (apOption->m_pStatusEffect)
    {
        int iIndex = GetStatusResult();
        if (!bResult && iIndex != -1)
            return false;
        for (int i = 0x19; i < 0x1f; i++)
        {
            if (::_g_thePlayer->GetActorValue((ActorValue::Index)i) <
                ::_g_thePlayer->GetPermanentActorValue((ActorValue::Index)i))
                return true;
        }
    }
    return false;
}

namespace fnv_007e0850 {
void _ref_0063f7b0(void*);
bool _ref_008256d0(void*);

// @fnv 0x007e0850
void FUN_007e0850(void* thisPtr)
{
    void* p;
    while (!_ref_008256d0((char*)thisPtr + 4))
    {
        p = *(((void **)(&reinterpret_cast<::SimpleListNodeView*>((char*)thisPtr + 4)->m_item)));
        ::FUN_00401030(p);
        _ref_0063f7b0((char*)thisPtr + 4);
    }
}
}  // namespace fnv_007e0850

struct FUN_007e0c50_item
{
    TESForm* pForm;
};
struct FUN_007e0c50_node
{
};
struct FUN_007e0c50_list
{
    void** m_ppVirtualMethodTable;
    FUN_007e0c50_node xList;
    FUN_007e0c50_item* FUN_007e0c50(unsigned int formID);
};

// Walks the list nodes and returns the first item whose form's GetFormID matches formID, or null if none matches.
// @fnv 0x007e0c50
FUN_007e0c50_item* FUN_007e0c50_list::FUN_007e0c50(unsigned int formID)
{
    FUN_007e0c50_node* pNode;
    FUN_007e0c50_item* pEffect = 0;
    for (pNode = this ? &xList : 0; !pEffect && pNode && ((::FUN_007e0c50_item *)(reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)); pNode = ((::FUN_007e0c50_node *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))
    {
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::FUN_007e0c50_item *)(reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item))->pForm))->FUN_0084e3a0())) == formID)
            pEffect = ((::FUN_007e0c50_item *)(reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item));
    }
    return pEffect;
}

namespace fnv_007e0d60 {
struct MenuH
{
    void UpdateXboxButtonState();
    void FUN_007e0d60(bool abHas360Controller);
};

// @fnv 0x007e0d60
void MenuH::FUN_007e0d60(bool abHas360Controller)
{
    MenuH::UpdateXboxButtonState();
}
}  // namespace fnv_007e0d60

// Maps an index 0-5 to a fixed code value (0x19-0x1e) via a switch, returning -1 for any other index.
// @fnv 0x007df9c0
int MapIndexToCode(int aiIndex)
{
    switch (aiIndex)
    {
    case 0:
        return 0x19;
    case 1:
        return 0x1c;
    case 2:
        return 0x1a;
    case 3:
        return 0x1b;
    case 4:
        return 0x1e;
    case 5:
        return 0x1d;
    default:
        return -1;
    }
}

// Returns the current page of the stats menu, or 0 when the menu is not open.
// @fnv 0x007dfcd0
char GetStatsMenuPage()
{
    int page;
    if (StatsMenu::ms_pInventoryMenu)
        page = StatsMenu::ms_pInventoryMenu->GetCurrentPage();
    else
        page = 0;
    return (char)page;
}

struct List_009e03e0
{
    void RemoveAll();
};

struct FUN_007e09b0_class
{
    int m;
    void FUN_007e09b0();
};

// @fnv 0x007e09b0
void FUN_007e09b0_class::FUN_007e09b0()
{
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((char*)this + 4))))->RemoveAll();
}


struct FUN_0071f9c0_class
{
    void* FUN_0071f9c0(unsigned int flags);
};

// Calls FUN_0071f9f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0071f9c0
void* FUN_0071f9c0_class::FUN_0071f9c0(unsigned int flags)
{
    reinterpret_cast<::FUN_0071f9f0 *>(this)->FUN_0071f9f0::~FUN_0071f9f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct G2
{
    int d[2];
    void AddHead(int*&);
};
struct S
{
    int pad;
    G2 arr[1];
    void FUN_007db250(int idx, int* val);
};
// Calls AddHead on the element of arr at idx, passing val.
// @fnv 0x007db250
void S::FUN_007db250(int aiIndex, int* apValue)
{
    arr[aiIndex].AddHead(apValue);
}

namespace fnv_007dbfe0 {
struct Elem8
{
    int x0;
    int x1;
};
struct BodyPartDisplay
{
    int mIndex;
    Elem8 mElems[1];
    void FUN_007dbfe0(unsigned int);
};
// Calls FUN_007e0e30 on the element at mIndex, passing the FUN_007dc040 callback and aiOn.
// @fnv 0x007dbfe0
void BodyPartDisplay::FUN_007dbfe0(unsigned int aiOn)
{
    reinterpret_cast<::FUN_007e0e30_Class *>(&(mElems[mIndex]))->FUN_007e0e30((bool (*)(void *, unsigned int))(bool (*)(Tile *, unsigned int))(&::StatsMenu::SetTileFlashing), aiOn);
}
}  // namespace fnv_007dbfe0

struct S_007dc010
{
    unsigned char _pad[52];
    unsigned int arr[1];
    unsigned int GetByte(unsigned int, unsigned int);
};
// Returns byte b of the 32-bit value stored at arr[a] by masking and shifting.
// @fnv 0x007dc010
unsigned int S_007dc010::GetByte(unsigned int auiIndex, unsigned int auiByteIndex)
{
    return (arr[auiIndex] & (0xFF << (auiByteIndex * 8))) >> (auiByteIndex * 8);
}

struct Struct007ddaa0
{
    char pad[0x210];
    ListBox_enum_ActorValue__Index_ lb;
    void TraverseListBox();
};
// @fnv 0x007ddaa0
void Struct007ddaa0::TraverseListBox()
{
    int unused1;
    int unused2;
    int FlushUsageData;
    reinterpret_cast<::LBList_7314c0 *>(&(lb))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void (*)(Tile *, ActorValue::Index))((void(__cdecl*)(Tile*, ActorValue::Index))((void (&)(Tile *, MiscStatManager__MiscStatID))::FUN_007dfc60)), 0, 0x7fffffff);
}

namespace fnv_007e0b20 {
struct FUN_00403ba0
{
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
    FUN_00403ba0();
};
struct FUN_00404210_t
{
};
struct S3e60
{
};
struct G2
{
    void AddHead(int*);
};
struct FUN_007e0b20_shell
{
    int pad00;
    G2 kList;  // +0x4
    FUN_00403ba0* FindEntryByFormID(int aiActorValue);
    void AddEffectItem(EffectItem* apEffect);
};

// @fnv 0x007e0b20
void FUN_007e0b20_shell::AddEffectItem(EffectItem* apEffect)
{
    if (apEffect)
    {
        FUN_00403ba0* pEntry = FindEntryByFormID(reinterpret_cast<::EffectItem *>((reinterpret_cast<FUN_00404210_t*>(apEffect)))->GetAffectedActorValue());
        if (pEntry)
        {
            pEntry->m_iMagnitude += reinterpret_cast<::FUN_00404390_shell *>((reinterpret_cast<FUN_00404210_t*>(apEffect)))->FUN_00404390();
        }
        else
        {
            pEntry = new FUN_00403ba0;
            pEntry->m_eAssociatedActorValue = reinterpret_cast<::EffectItem *>((reinterpret_cast<FUN_00404210_t*>(apEffect)))->GetAffectedActorValue();
            pEntry->m_iMagnitude = reinterpret_cast<::FUN_00404390_shell *>((reinterpret_cast<FUN_00404210_t*>(apEffect)))->FUN_00404390();
            if (reinterpret_cast<::S3e60 *>((reinterpret_cast<S3e60*>(((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)(apEffect))->FUN_00825c00())))))->FUN_00403e60(4))
                pEntry->m_iMagnitude *= -1;
            if (!reinterpret_cast<::S3e60 *>((reinterpret_cast<S3e60*>(((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)(apEffect))->FUN_00825c00())))))->FUN_00403e60(2))
                pEntry->m_iPayloadInteger = reinterpret_cast<::FUN_004044d0_shell *>((reinterpret_cast<FUN_00404210_t*>(apEffect)))->FUN_004044d0();
            kList.AddHead(reinterpret_cast<int*>(&pEntry));
        }
    }
}
}  // namespace fnv_007e0b20

struct ListX
{
    unsigned char* m_pHead;
    unsigned char* m_pTail;
    unsigned int m_uiCount;
    ~ListX();
};
struct FUN_00406de0 : ListX
{
    virtual ~FUN_00406de0();
    void FUN_007e0850();
};
// @fnv 0x00406de0
FUN_00406de0::~FUN_00406de0()
{
    FUN_007e0850();
}

struct FUN_007db270_t
{
    void SetFieldBits(unsigned int a, unsigned int c, unsigned int b);
};

// @fnv 0x007db270
void FUN_007db270_t::SetFieldBits(unsigned int auiIndex, unsigned int auiByteOffset, unsigned int auiValue)
{
    *(unsigned int*)((char*)this + 0x34 + auiIndex * 4) &= ~(0xff << (auiByteOffset << 3));
    *(unsigned int*)((char*)this + 0x34 + auiIndex * 4) |= auiValue << (auiByteOffset << 3);
}

struct FUN_007e0230_Helper
{
    void UpdateXboxButtonState();
};

bool __cdecl IsActorValueBelowPermanent(int*);

struct FUN_007e0230 : FUN_007e0230_Helper
{
    char pad[0x2a0];
    bool m_bUpdateOption;
    void RefreshHealingOptions();
};

// @fnv 0x007e0230
void FUN_007e0230::RefreshHealingOptions()
{
    m_bUpdateOption = !m_bUpdateOption;
    (*(Tile**)((char*)this + 0x2c))->Set(0xfaf, IsActorValueBelowPermanent((int*)((char*)this + 0x28)));
    (*(Tile**)((char*)this + 0x5c))->Set(0xfaf, IsHealingOptionAvailable((StatsMenu__HealingOption*)((char*)this + 0x58)));
    UpdateXboxButtonState();
}

namespace fnv_007dcc80 {
struct StartMenu
{
    char const* GetMenuTitle();
};

struct GlobalObject2_0045cfe0 : public StartMenu
{
};

struct Struct007ddaa0
{
};

struct FUN_007dd8c0_StandIn
{
    void UpdateReputationList();
};

struct FUN_007df230_StandIn
{
    void UpdateOption(int value);
};

struct FUN_007df920_StandIn
{
    void ShowWorstLimbStatus();
};

struct Tile_helper
{
};


extern const char str_0107732c[];
extern const char str_01077340[];
extern const char str_01077358[];
extern const char str_01077368[];
extern const char str_01077378[];
extern const char str_01077388[];
extern const char str_01077398[];


struct FUN_007dcc80_StandIn : public StatsMenu
{
    void InitializeStatsMenu();
};

// Calls the base menu setup routines, then if the language is English, assigns localized text to the menu's tiles by index and by name.
// @fnv 0x007dcc80
void FUN_007dcc80_StandIn::InitializeStatsMenu()
{
    this->UpdateActorValueTiles();
    reinterpret_cast<::Struct007ddaa0 *>((reinterpret_cast<Struct007ddaa0*>(this)))->TraverseListBox();
    reinterpret_cast<FUN_007dd8c0_StandIn*>(this)->UpdateReputationList();
    reinterpret_cast<FUN_007df230_StandIn*>(this)->UpdateOption(4);
    reinterpret_cast<FUN_007df920_StandIn*>(this)->ShowWorstLimbStatus();

    if (::FUN_00408b20((*reinterpret_cast<::fnv_007dcc80::GlobalObject2_0045cfe0 *>(&::g_011c3cb4)).GetMenuTitle(), reinterpret_cast<char const*>(&(*reinterpret_cast<const char *const *>(&::DAT_01018348)))))
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[0]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d2f88)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[1]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d2994)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[2]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d3b08)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[3]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d4bd0)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[4]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d4ef4)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[28]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d48d0)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d3e74)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[53]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d1f08)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[57]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d246c)).GetMenuTitle()), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_pTiles[55]))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d37c8)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070())))))->FUN_00a01350(0x100d, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d2e80)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070())))))->FUN_00a01350(0x100e, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d41bc)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070()))))))->FUN_00a03da0((char *)(str_01077398))))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d3fdc)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070()))))))->FUN_00a03da0((char *)(str_01077388))))->FUN_00a01350(::FUN_00a01860(::DAT_0106ed20), (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d1f5c)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070()))))))->FUN_00a03da0((char *)(str_01077378))))->FUN_00a01350(::FUN_00a01860(::DAT_0106ed20), (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d50b0)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070()))))))->FUN_00a03da0((char *)(str_01077368))))->FUN_00a01350(::FUN_00a01860(::DAT_0106ed20), (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d44a4)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070()))))))->FUN_00a03da0((char *)(str_01077358))))->FUN_00a01350(::FUN_00a01860(::DAT_0106ed20), (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d3bd4)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070()))))))->FUN_00a03da0((char *)(str_01077340))))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d47ec)).GetMenuTitle()), true);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Tile*>*>(this)))->FUN_00726070()))))))->FUN_00a03da0((char *)(str_0107732c))))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::fnv_007dcc80::StartMenu *>(&::g_011d2ebc)).GetMenuTitle()), true);
    }
}
}  // namespace fnv_007dcc80

namespace fnv_007e06b0 {
struct GO
{
    operator unsigned int() const;
};

typedef GO StatusH;


// @fnv 0x007e06b0
int __cdecl GetStatusResult()
{
    int result;

    if (::fnv_0070ed80::IsStatsMenuActive())
        result = ::MapIndexToCode(static_cast<unsigned int>(*((::fnv_007e06b0::GO *)(::FUN_007db1c0()))));
    else
        result = -1;

    return result;
}
}  // namespace fnv_007e06b0

namespace fnv_007e02b0 {
extern char const $SG2844[];

class StartMenu
{
  public:
    char const* GetMenuTitle();
};

class GlobalObject_0040c150 : public StartMenu
{
};


struct FUN_007e02b0_StandIn
{
    void FUN_007e02b0();
};

// @fnv 0x007e02b0
void FUN_007e02b0_StandIn::FUN_007e02b0()
{
    static int DAT_011dad88 = ::FUN_00a00940($SG2844, -1);
    static int DAT_011dad84 = ::FUN_00a00940("_user0", -1);
    static bool DAT_011a0ae0 = false;

    DAT_011a0ae0 = !DAT_011a0ae0;

    StatsMenu::ms_pInventoryMenu->m_pTiles[46]->Set(DAT_011dad88, DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[46]->Set(0xFA3, DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[8]->Set(DAT_011dad88, !DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[8]->Set(0xFA3, !DAT_011a0ae0);

    if (DAT_011a0ae0)
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[49]))->FUN_00a01350(0xFC4, (char *)((*reinterpret_cast<::fnv_007e02b0::StartMenu *>(&::g_011d4ef4)).GetMenuTitle()), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[50]->Set(0x1004, 1);
    }
    else
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((StatsMenu::ms_pInventoryMenu->m_pTiles[49]))->FUN_00a01350(0xFC4, (char *)((*reinterpret_cast<::fnv_007e02b0::GlobalObject_0040c150 *>(&::g_011d4144)).GetMenuTitle()), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[50]->Set(0x1004, 0);
    }
}
}  // namespace fnv_007e02b0

struct FUN_007d35c0_Tile
{
};
struct FUN_007d35c0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
struct SM7d6
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
    int unk40;
    int unk44;
    FUN_007d35c0_Tile* t48;
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    FUN_007d35c0_Obj e4;
};
struct GameSettingCollection_stub
{
    const char* String();
};
// If DAT_011daac0 is set, calls its e4.v7, sets tile 0xfc4 text from g_011d4930.String(), and calls FUN_0075f6f0(0x4000, true).
// @fnv 0x007d35c0
void __cdecl FUN_007d35c0()
{
    if ((*reinterpret_cast<::SM7d6 * *>(&::fnv_007d0700::DAT_011daac0)))
    {
        (*reinterpret_cast<::SM7d6 * *>(&::fnv_007d0700::DAT_011daac0))->e4.v7();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::SM7d6 * *>(&::fnv_007d0700::DAT_011daac0))->t48))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::GameSettingCollection_stub *>(&::g_011d4930)).String()), true);
        reinterpret_cast<::FUN_0075f6f0_shell *>(((*reinterpret_cast<::SM7d6 * *>(&::fnv_007d0700::DAT_011daac0))))->FUN_0075f6f0(0x4000, true);
    }
}

class FUN_007db340_cls
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
    void* m_slots[60];
    bool HasAllSlots();
};

// Returns true only if all 60 entries of m_slots are non-null, otherwise false.
// @fnv 0x007db340
bool FUN_007db340_cls::HasAllSlots()
{
    for (int i = 0; i < 60; i++)
    {
        if (m_slots[i] == 0)
        {
            return false;
        }
    }
    return true;
}

struct FUN_007db630_Entry
{
    int unk00;
    int unk04;
};
struct FUN_007db630_Owner
{
    int unk00;
    FUN_007db630_Entry entries[6];
    int FindEntryIndex(int value);
};
// Scans up to 6 entries, returning the index of the first whose FUN_005f65d0 accepts value, otherwise 6.
// @fnv 0x007db630
int FUN_007db630_Owner::FindEntryIndex(int value)
{
    int index = 0;
    for (; index < 6; ::TESReputation::GetUnsignedIntegerPointer((unsigned int *)(int *)(&index)))
    {
        if (reinterpret_cast<::RefList *>(&(entries[index]))->FUN_005f65d0((void **)(int *)(&value)))
            return index;
    }
    return 6;
}

extern const char UNK_01074eb8;


struct ChildList007dc7e0
{
};
struct TileAdapter007dc7e0
{
};
struct StatsMenuFunction007dc7e0 : StatsMenu
{
    void UpdateStatsDisplay(void* actor);
};
struct TileValue
{
};
struct MenuItem
{
    unsigned int menuId;
    TileValue* value;
    void FUN_007ddc20();
};
struct TraitValues
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual float GetValue(unsigned int);
};
namespace fnv_007ddd10 {
struct TraitSI
{
};
struct DisplaySI
{
};
struct ActivitySI
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float v3(int);
};
extern float __cdecl FUN_004bd510(float, float);
struct StatsMenuSI
{
    void* unk00;
    DisplaySI* unk04;
    void FUN_007ddd10();
};
// @fnv 0x007ddd10
void StatsMenuSI::FUN_007ddd10()
{
    float scale;

    float adjustment;
    float currentValue;
    float unusedResult;
    scale = reinterpret_cast<::TileListBoxCalls *>((((::fnv_007ddd10::TraitSI *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat({}) * ::DAT_01017b70;
    adjustment = (-scale / ::DAT_01011590) + (((double)(::RandomFloat0To1())) * scale);
    currentValue =
        ::FUN_00404010(0.0f, (reinterpret_cast<ActivitySI*>(reinterpret_cast<char*>((*reinterpret_cast<::fnv_007ddd10::ActivitySI * *>(&::_g_thePlayer))) + 0xa4))->v3(0x4a));
    unusedResult = ::DAT_01064f50 - (currentValue + adjustment) / ::DAT_01017b70 * ::DAT_0101ff40;
    if (currentValue > ::_DAT_01012060 && currentValue < ::g_01012070)
        currentValue = 1.0f;
    else
        currentValue = FUN_004bd510(currentValue, 1.0f);
    reinterpret_cast<::FUN_00a012d0_t *>((unk04))->FUN_00a012d0(0x1010, currentValue, true);
}
}  // namespace fnv_007ddd10

class B7DDE00Tile
{
  public:
};

class B7DDE00ValueOwner
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual float GetActorValue(int m_eAssociatedActorValue);
};

class B7DDE00Player
{
  public:
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
    B7DDE00ValueOwner m_kAVOwner;
};



class B7DDE00Menu
{
  public:
    void UpdateModifierTile();

    int unk00;
    B7DDE00Tile* m_pkTile;
};

// Show the status for the player's most damaged limb.

enum DF920Limb
{
    DF920_LIMB_HEAD = 0,
    DF920_LIMB_COUNT = 6
};

DF920Limb& __cdecl operator++(DF920Limb& reLimb);

class DF920ActorValueOwner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual float GetActorValue(int m_eAssociatedActorValue);
};

class DF920Player
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
    DF920ActorValueOwner m_kAVOwner;
};

class DF920Status
{
  public:
};

class DF920Menu
{
  public:
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
    unsigned char m_ucMode;

    void ShowWorstLimbStatus();
};

// Finds the limb with the lowest actor value and shows its status for the current mode.
// @fnv 0x007df920
void DF920Menu::ShowWorstLimbStatus()
{
    int iWorstLimb = DF920_LIMB_COUNT;
    float fMinValue = 3.402823466e+38f;
    for (DF920Limb m_iActionValue = DF920_LIMB_HEAD; m_iActionValue < DF920_LIMB_COUNT; ++m_iActionValue)
    {
        float fValue = (*reinterpret_cast<::DF920Player * *>(&::_g_thePlayer))->m_kAVOwner.GetActorValue(::MapIndexToCode(m_iActionValue));
        if (fValue < fMinValue)
        {
            fMinValue = fValue;
            iWorstLimb = m_iActionValue;
        }
    }
    reinterpret_cast<::BodyPartDisplay *>((((::DF920Status *)(::FUN_007db1c0()))))->SetBodyPart({}, {});
}

struct Dummy007_obj
{
};

struct GlobA_007dfd20
{
};
struct GlobB_007dfd20
{
};

struct Obj2_007dfd20
{
    Obj2_007dfd20* FUN_00704370();
    void FUN_007f8610();
};


struct FUN_007dfd20_cls
{
    int unk00;
    void FUN_007dfd20(Dummy007_obj* apObj, unsigned int* apOut);
};

// @fnv 0x007dfd20
void FUN_007dfd20_cls::FUN_007dfd20(Dummy007_obj* apObj, unsigned int* apOut)
{
    unsigned int v = (unsigned int)reinterpret_cast<::TileListBoxCalls *>((apObj))->GetFloat(0xfac);
    if (*apOut < v)
    {
        ((::Obj2_007dfd20 *)(::fnv_004b7210::FUN_004b7210()))->FUN_00704370()->FUN_007f8610();
    }
    else if (*apOut > v)
    {
        ((::Obj2_007dfd20 *)(::fnv_004b7210::FUN_004b7210()))->FUN_00704370()->FUN_007f8610();
    }
    *apOut = v;
}

struct FUN_00408da0_obj
{
};

// Resolves the objects referenced by *pA and *pB via FUN_00ec43fb and passes their FUN_00408da0 results to FUN_00404dc0.
// @fnv 0x007e0480
void __cdecl FUN_007e0480(int* pA, int* pB)
{
    ::FUN_00404dc0((const char *)(void *)(((void *)(reinterpret_cast<::FUN_00408da0_Class *>((((FUN_00408da0_obj *)(dynamic_cast<::TESFullName *>(reinterpret_cast<::TESForm *>(*pA))))))->FUN_00408da0()))),
                 (const char *)(void *)(((void *)(reinterpret_cast<::FUN_00408da0_Class *>((((FUN_00408da0_obj *)(dynamic_cast<::TESFullName *>(reinterpret_cast<::TESForm *>(*pB))))))->FUN_00408da0()))));
}

struct Text
{
};
struct Item
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Text text;
};
struct Holder
{
    Item* item;
};
struct Entry
{
    unsigned int unk00;
    Holder* holder;
};
// Compares the text strings of the items referenced by two entries via FUN_00404dc0 and returns its result.
// @fnv 0x007e04e0
int __cdecl CompareEntryText(const Entry* pLeftEntry, const Entry* pRightEntry)
{
    return FUN_00404dc0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pLeftEntry->holder->item->text))->FUN_00408da0())), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pRightEntry->holder->item->text))->FUN_00408da0())));
}


struct SubObject_b5367
{
    virtual void Unk_00();
    virtual void Unk_04();
    virtual void Unk_08();
    virtual float Unk_0C(int aiValue);
};

// Returns true when apArg[2] is nonzero and the player's sub-object at offset 0xa4 returns a value above DAT_01012060 for 0x36.
// @fnv 0x007e07a0
bool __cdecl IsPlayerSubObjectValueAboveThreshold(int* apArg)
{
    int iResult;
    if (apArg[2] != 0 && ((SubObject_b5367*)static_cast<ActorValueOwner *>(::_g_thePlayer))->Unk_0C(0x36) > ::_DAT_01012060)
    {
        iResult = 1;
    }
    else
    {
        iResult = 0;
    }
    return *(bool*)&iResult;
}

struct S_007e0a20_Obj
{
};

struct S_007e0a20_Param
{
};

struct S_007e0a20_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_007e0a20_Entry();
};

struct S_007e0a20_Owner
{
    int unk00;
    BSSimpleList<S_007e0a20_Entry*> m_kNode;
    void ApplyParamToEntry(S_007e0a20_Param* apParam);
};

struct ItemListNode;

struct ItemListEntry
{
    unsigned char unk00[0x10];
    int formID;
};

struct ItemListNode
{
    ItemListEntry** Data();
};

class ItemListOwner
{
  public:
    void** m_ppVirtualMethodTable;
    ItemListNode xList;
    ItemListEntry* FindEntryByFormID(int formID);
};
// Looks up an entry by the param's object id; adds the param's float to its unk00, or creates a new entry with that id and value and adds it to the list.
// @fnv 0x007e0a20
void S_007e0a20_Owner::ApplyParamToEntry(S_007e0a20_Param* apParam)
{
    if (apParam)
    {
        S_007e0a20_Entry* pEntry = ((::S_007e0a20_Entry *)(reinterpret_cast<::ItemListOwner *>(this)->FindEntryByFormID(reinterpret_cast<::EffectItem *>((((::S_007e0a20_Obj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((apParam))->FUN_0084e3a0()))))->GetAffectedActorValue())));
        if (pEntry)
        {
            pEntry->unk00 += (int)::GetFloatAtOffset1C((char *)(apParam));
        }
        else
        {
            pEntry = new S_007e0a20_Entry;
            pEntry->unk10 = reinterpret_cast<::EffectItem *>((((::S_007e0a20_Obj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((apParam))->FUN_0084e3a0()))))->GetAffectedActorValue();
            pEntry->unk00 = (int)::GetFloatAtOffset1C((char *)(apParam));
            m_kNode.AddHead(pEntry);
        }
    }
}

// Walks the linked list and returns the first entry whose formID matches the given formID, or null if none is found.
// @fnv 0x007e0ce0
ItemListEntry* ItemListOwner::FindEntryByFormID(int formID)
{
    ItemListEntry* found = 0;
    ItemListNode* cur = this != 0 ? &xList : 0;
    for (; found == 0 && cur != 0 && *((::ItemListEntry **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)) != 0; cur = ((::ItemListNode *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if ((*((::ItemListEntry **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)))->formID == formID)
        {
            found = *((::ItemListEntry **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item));
        }
    }
    return found;
}

struct FUN_007db2c0
{
    FUN_007db2c0();
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
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
};


// Returns the global FUN_007db2c0 instance, allocating it with new if it does not exist yet.
// @fnv 0x007db1c0
FUN_007db2c0* FUN_007db1c0()
{
    if (!(*reinterpret_cast<::FUN_007db2c0 * *>(&::DAT_011dace4)))
        (*reinterpret_cast<::FUN_007db2c0 * *>(&::DAT_011dace4)) = new FUN_007db2c0();
    return (*reinterpret_cast<::FUN_007db2c0 * *>(&::DAT_011dace4));
}

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
struct ClickNode
{
};
class InventoryStackRecord
{
  public:
public:
    static float RoundToNearestStep(float, float);
public:
    void *GetPayloadAddress();
};
// @fnv 0x007dc7e0
void StatsMenuFunction007dc7e0::UpdateStatsDisplay(void* actor)
{
    TileAdapter007dc7e0* pMain = *(reinterpret_cast<TileAdapter007dc7e0**>(
        ((::Tile **)(reinterpret_cast<::FUN_0073ac90_shell *>((reinterpret_cast<ChildList007dc7e0*>((char*)m_pTiles[26] + 4)))->FUN_0073ac90()))));
    TileAdapter007dc7e0* second = *(reinterpret_cast<TileAdapter007dc7e0**>(
        ((::Tile **)(reinterpret_cast<::InventoryStackRecord *>((reinterpret_cast<ChildList007dc7e0*>((char*)m_pTiles[26] + 4)))->GetPayloadAddress()))));
    float fMinimumInputValue = reinterpret_cast<::TileListBoxCalls *>((second))->GetFloat(FUN_00a01860(&UNK_01074eb8));
    float diff = 0.0f;
    reinterpret_cast<::Tile *>((reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[25])))->Set(0xfa3, 1);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[25])))->FUN_00a01350(0xfcc, (char *)(::FUN_0066e9f0((::ActorValue::Index)reinterpret_cast<std::intptr_t>(actor))), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pMain))->FUN_00a01350(0xfc4, (char *)(::GetActorValueDescription((::ActorValue::Index)reinterpret_cast<std::intptr_t>(actor))), true);
    unsigned int amount = ((unsigned int)(::GetWeaponSkillIconPath((int)(actor))));
    if (amount > 0)
    {
        reinterpret_cast<::Tile *>((reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[52])))->Set(0xfa3, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[52])))->FUN_00a01350(0xfcc, (char *)(amount), true);
    }
    else
    {
        reinterpret_cast<::Tile *>((reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[52])))->Set(0xfa3, 0);
    }
    reinterpret_cast<::RenderTile *>((pMain))->FUN_00a04640(0);
    diff = reinterpret_cast<::TileListBoxCalls *>((pMain))->GetFloat(0xfb0) - reinterpret_cast<::TileListBoxCalls *>((((::TileAdapter007dc7e0 *)(reinterpret_cast<::FUN_0045cd60_shell *>((pMain))->FUN_0045cd60()))))->GetFloat(0xfb0);
    diff = FUN_00404010(0.0f, diff);
    reinterpret_cast<::FUN_00a012d0_t *>((second))->FUN_00a012d0(FUN_00a01860(&(*reinterpret_cast<const char *>(&::str_0106f8f8))), FUN_004e4430(diff / fMinimumInputValue) + ::g_01012070, true);
    reinterpret_cast<::FUN_00a012d0_t *>((second))->FUN_00a012d0(FUN_00a01860(&(*reinterpret_cast<const char *>(&::str_010702d8))), 0.0f, false);
    reinterpret_cast<::FUN_00a01290_shell *>((second))->SetTraitAndReset(FUN_00a01860(&(*reinterpret_cast<const char *>(&::DAT_01070250))), 1.0f);
}
// @fnv 0x007ddc20
void MenuItem::FUN_007ddc20()
{
    float a = reinterpret_cast<::TileListBoxCalls *>((((::TileValue *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat({}) * ::DAT_01017b70;
    float c = (-a / ::DAT_01011590) + ::RandomFloat0To1() * a;
    float d = FUN_00404010(0.0f, ((TraitValues*)((char*)(*reinterpret_cast<void * *>(&::_g_thePlayer)) + 0xa4))->GetValue(0x49));
    float e = ::DAT_01064f50 - (d + c) / ::DAT_01017b70 * ::DAT_0101ff40;
    if (d > ::_DAT_01012060 && d < g_01012070)
        d = 1.0f;
    else
        d = ::InventoryStackRecord::RoundToNearestStep(d, 1.0f);
    reinterpret_cast<::FUN_00a012d0_t *>((value))->FUN_00a012d0(0x100f, d, true);
}
// @fnv 0x007dde00
void B7DDE00Menu::UpdateModifierTile()
{
    float fRange5 = reinterpret_cast<::TileListBoxCalls *>((((::B7DDE00Tile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(0x1008) * 1000.0;
    float fOffset5 = -fRange5 / 2.0 + ::RandomFloat0To1() * fRange5;
    float fValue = FUN_00404010(0.0f, reinterpret_cast<B7DDE00Player*>(::_g_thePlayer)->m_kAVOwner.GetActorValue(0x4b));
    float fAngle2 = 1.5707963267948966 - (fValue + fOffset5) / 1000.0 * 3.1415927410125732;
    if (fValue > ::_DAT_01012060 && fValue < 1.0)
        fValue = 1.0f;
    else
        fValue = ::InventoryStackRecord::RoundToNearestStep(fValue, 1.0f);
    reinterpret_cast<::FUN_00a012d0_t *>((m_pkTile))->FUN_00a012d0(0x1011, fValue, true);
}
struct ClickAlchemy
{
};
struct ClickPlayer
{
};
struct ClickTile
{
};
struct ClickStatus
{
};
struct ClickVirtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void OnClick(int, Tile*);
};
struct ClickMenu : StatsMenu
{
    void FUN_007db380(int id, Tile* tile);
    bool SetIndexFromType(int, int*);
    void FUN_007e0060(int);
    void FUN_007e0230();
};
// Menu input: on the accept key with the button enabled, trigger the default action and play the OK sound.

class C0E0SoundHandle
{
  public:
    ~C0E0SoundHandle();

    int m_iID;
    int unk04;
    int unk08;
};

class C0E0Audio
{
  public:
    C0E0SoundHandle GetSoundHandleByEditorID(const char* pcEditorID, unsigned int uiFlags, int iUnused);
};

class C0E0Tile
{
  public:
};

class C0E0Menu
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void HandleClick(int iButton, int iUnused);

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
    C0E0Tile* m_pkButton;
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
    bool m_bAcceptsInput;

    bool FUN_007dc0e0(int iKey, int iUnused);
};

// @fnv 0x007dc0e0
bool C0E0Menu::FUN_007dc0e0(int iKey, int iUnused)
{
    if (m_bAcceptsInput && iKey == 10 && reinterpret_cast<::FUN_00a01230_shell *>((m_pkButton))->IsTraitNonZero(0xfaf))
    {
        HandleClick(9, 0);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::C0E0SoundHandle &)(((::C0E0Audio *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIMenuOK", 0x121, 0)))->FUN_00ad8830({});
        return true;
    }
    return false;
}

struct FORenderedMenu
{
};
bool __cdecl FUN_00702450(int);
extern unsigned int DAT_011dad74;
extern unsigned char DAT_011a0ae1;
struct AceObj
{
    Tile* m_tiles[0x5e];
};
extern AceObj* DAT_011dace0;

struct TileF15
{
};
struct Host15 : StatsMenu
{
    void FUN_007e0230();
    void FUN_007e0060(int);
    void UpdateStatsMenu();
};

namespace fnv_007dc9b0 {
struct ChildListSI
{
};
struct DescSI
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* GetText(void* pForm, unsigned int chunk);
    int unk04;
};
struct FNStub
{
};
struct EntrySI
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
    DescSI xDesc;
    FNStub StringProvider;
};
struct TileSI : public Tile
{
};

struct FUN_007dc9b0_shell : public StatsMenu
{
    void UpdateScrollBar(EntrySI** apEntry);
};

// @fnv 0x007dc9b0
void FUN_007dc9b0_shell::UpdateScrollBar(EntrySI** apEntry)
{
    TileSI* pHeadTile = (TileSI*)((::Tile *)(reinterpret_cast<::FUN_0073ac90_shell *>((((ChildListSI*)((char*)m_pTiles[26] + 4))))->FUN_0073ac90()));
    TileSI* pTailTile = (TileSI*)((::Tile *)(reinterpret_cast<::InventoryStackRecord *>((((ChildListSI*)((char*)m_pTiles[26] + 4))))->GetPayloadAddress()));
    float fTailScrollDelta = reinterpret_cast<::TileListBoxCalls *>((pTailTile))->GetFloat(::FUN_00a01860("_ScrollDelta"));
    {
        float fPos = 0.0f;
        m_pTiles[25]->Set(0xfa3, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[25]))->FUN_00a01350(0xfcc, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&((*apEntry)->StringProvider))->FUN_00408da0()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pHeadTile))->FUN_00a01350(0xfc4, (char *)((*apEntry)->xDesc.GetText(0, 0x43534544)), true);
        reinterpret_cast<::RenderTile *>((pHeadTile))->FUN_00a04640(0);
        fPos = reinterpret_cast<::TileListBoxCalls *>((pHeadTile))->GetFloat(0xfb0) - reinterpret_cast<::TileListBoxCalls *>((((TileSI*)((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)(pHeadTile))->FUN_0045cd60())))))->GetFloat(0xfb0);
        fPos = ::FUN_00404010(0.0f, fPos);
        reinterpret_cast<::FUN_00a012d0_t *>((pTailTile))->FUN_00a012d0(::FUN_00a01860("_number_of_items"), (float)(::FUN_004e4430(fPos / fTailScrollDelta) + 1.0),
                                true);
    }
    reinterpret_cast<::FUN_00a012d0_t *>((pTailTile))->FUN_00a012d0(::FUN_00a01860("_current_value"), 0.0f, false);
    reinterpret_cast<::FUN_00a01290_shell *>((pTailTile))->SetTraitAndReset(::FUN_00a01860("_SetInCode"), 1.0f);
}
}  // namespace fnv_007dc9b0

namespace fnv_007dd710 {
class FUN_007dd710_str
{
  public:
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    FUN_007dd710_str();
    ~FUN_007dd710_str();
};

class FUN_007dd710_text
{
  public:
};

class FUN_007dd710_form
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    FUN_007dd710_text m18;
};

class FUN_007dd710_item
{
  public:
    FUN_007dd710_form* pForm;
    unsigned char count;
};

class FUN_007dd710_node
{
  public:
};

class FUN_007dd710_sub
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

class FUN_007dd710_list
{
  public:
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
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual FUN_007dd710_node* GetFirst(int which);
};

class FUN_007dd710_ctx
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    int m118;
    unsigned char pad11c[0x1e0 - 0x11c];
    FUN_007dd710_sub m1e0;
};

int __cdecl CompareEntryText(const void* left, const void* right);

extern FUN_007dd710_ctx* DAT_011dace0;

// @fnv 0x007dd710
void __cdecl FUN_007dd710()
{
    if (DAT_011dace0 && DAT_011dace0->m118)
    {
        DAT_011dace0->m1e0.v7();
        for (FUN_007dd710_node* node = (*reinterpret_cast<::fnv_007dd710::FUN_007dd710_list * *>(&::_g_thePlayer))->GetFirst(0); node != 0 && ((::fnv_007dd710::FUN_007dd710_item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)) != 0;
             node = ((::fnv_007dd710::FUN_007dd710_node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
        {
            if (!reinterpret_cast<::BGSPerk *>((((::fnv_007dd710::FUN_007dd710_item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->pForm))->IsPerkHidden())
            {
                FUN_007dd710_str strEntry;
                if (((::fnv_007dd710::FUN_007dd710_item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->count > 1)
                {
                    ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_007dd710::FUN_007dd710_str *)(&strEntry), "%s (%d)", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::fnv_007dd710::FUN_007dd710_item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->pForm->m18))->FUN_00408da0())),
                                 (int)((::fnv_007dd710::FUN_007dd710_item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->count);
                }
                else
                {
                    ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_007dd710::FUN_007dd710_str *)(&strEntry), "%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::fnv_007dd710::FUN_007dd710_item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->pForm->m18))->FUN_00408da0())));
                }
                reinterpret_cast<::ListOwner *>(&(DAT_011dace0->m1e0))->FUN_007e0e70((int)(((::fnv_007dd710::FUN_007dd710_item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))), (const char *)(::FUN_00559450((int *)&(strEntry))), {}, {});
            }
        }
    }
}
}  // namespace fnv_007dd710

namespace fnv_007dd8c0 {
struct ReputationName
{
};
class ReputationView : public TESForm
{
  public:
    ReputationName name;
};
struct ReputationNode
{
};
struct ReputationDataHandler : TESDataHandler
{
};
extern StatsMenu* DAT_011dace0;
void __cdecl CompareEntryNames(void* item);

struct ReputationMenuList : ListBox_TESReputation___
{
    void Insert(ReputationView* reputation, const char* label, void(__cdecl* callback)(void*), bool selected);
};

struct ReputationMenuUpdater : StatsMenu
{
    void UpdateReputationList();
};

// @fnv 0x007dd8c0
void ReputationMenuUpdater::UpdateReputationList()
{
    if (DAT_011dace0 && DAT_011dace0->m_pTiles[46])
    {
        m_pTiles[47]->Set(4003, 0);
        m_pTiles[51]->Set(4003, 0);
        m_pTiles[48]->Set(4003, 0);
        DAT_011dace0->m_kReputationList.ClearList();
        for (ReputationNode* node = ((::fnv_007dd8c0::ReputationNode *)(reinterpret_cast<::FUN_009c1a50_shell *>(((*reinterpret_cast<::fnv_007dd8c0::ReputationDataHandler * *>(&::g_dataHandler))))->FUN_009c1a50())); node && ((::fnv_007dd8c0::ReputationView *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)); node = ((::fnv_007dd8c0::ReputationNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
        {
            ReputationView* reputation = ((::fnv_007dd8c0::ReputationView *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
            if (reputation &&
                (reinterpret_cast<::TESReputation *>((reputation))->GetUnsignedIntegerPointer((::ReputationType)(true)) > ::_DAT_01012060 || reinterpret_cast<::TESReputation *>((reputation))->GetUnsignedIntegerPointer((::ReputationType)(false)) > ::_DAT_01012060))
            {
                BSStringT<char> label;
                ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&label), DAT_01019f08, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(reputation->name))->FUN_00408da0())));
                reinterpret_cast<ReputationMenuList*>(&DAT_011dace0->m_kReputationList)
                    ->Insert(reputation, ((const char *)(::FUN_00559450((int *)&(label)))), CompareEntryNames, false);
            }
        }
    }
}
}  // namespace fnv_007dd8c0

struct TileFloatSetter
{
};
struct PipboyScreenStub
{
};
struct PipboyInterfaceStub
{
    PipboyScreenStub* GetPipboyManager();
};

struct FUN_007ddb00_shell : public Menu
{
    void UpdatePipboyNeedle();
};
// @fnv 0x007dc4f0
void Host15::UpdateStatsMenu()
{
    m_bStatUpdatePending = 0;
    if (reinterpret_cast<::FOPipboyManager *>((((::FORenderedMenu *)(::fnv_00705990::FUN_00705990()))))->IsUnk28Set())
    {
        ::fnv_004b7210::FUN_004b7210();
        if (FUN_007178a0())
        {
            if (((unsigned int)(::FUN_00457fe0())) >= DAT_011dad74)
            {
                reinterpret_cast<::FUN_007ddb00_shell *>(this)->UpdatePipboyNeedle();
                if ((*reinterpret_cast<void * *>(&::_g_thePlayer)) && ::FUN_004d1360((char *)((*reinterpret_cast<void * *>(&::_g_thePlayer)))))
                {
                    reinterpret_cast<::MenuItem *>(this)->FUN_007ddc20();
                    reinterpret_cast<::fnv_007ddd10::StatsMenuSI *>(this)->FUN_007ddd10();
                    reinterpret_cast<::B7DDE00Menu *>(this)->UpdateModifierTile();
                }
                DAT_011dad74 = (unsigned int)((double)((unsigned int)(::FUN_00457fe0())) + reinterpret_cast<::TileListBoxCalls *>((((::TileF15 *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(0x1007) * 1000.0);
            }
        }
        if (m_bUpdateOption)
        {
            if (!FUN_00702450(0x3eb))
                reinterpret_cast<::FUN_007e0230 *>(this)->RefreshHealingOptions();
        }
    }
    if (GetCurrentPage() == 0)
    {
        if (reinterpret_cast<::FUN_007dcc40_shell *>(this)->FUN_007dcc40() > (::FUN_004d1360((char *)((*reinterpret_cast<void * *>(&::_g_thePlayer)))) ? 5 : 2))
            FUN_007e0060(0);
    }
    if ((*reinterpret_cast<void * *>(&::_g_thePlayer)) && !::FUN_004d1360((char *)((*reinterpret_cast<void * *>(&::_g_thePlayer)))) && DAT_011a0ae1)
    {
        DAT_011dace0->m_tiles[0x59]->Set(0xfaf, 0);
        DAT_011dace0->m_tiles[0x59]->Set(0xfa3, 0);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfaf, 0);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfa3, 0);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfaf, 0);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfa3, 0);
        DAT_011a0ae1 = 0;
    }
    else if ((*reinterpret_cast<void * *>(&::_g_thePlayer)) && ::FUN_004d1360((char *)((*reinterpret_cast<void * *>(&::_g_thePlayer)))) && !DAT_011a0ae1)
    {
        DAT_011dace0->m_tiles[0x59]->Set(0xfaf, 1);
        DAT_011dace0->m_tiles[0x59]->Set(0xfa3, 1);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfaf, 1);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfa3, 1);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfaf, 1);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfa3, 1);
    }
    DAT_011a0ae1 = ::FUN_004d1360((char *)((*reinterpret_cast<void * *>(&::_g_thePlayer))));
}

// @fnv 0x007ddb00
void FUN_007ddb00_shell::UpdatePipboyNeedle()
{
    float fRange5 = reinterpret_cast<::TileListBoxCalls *>((void *)(((::Tile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(0x1008) * 1000.0;
    float fBase2 = -fRange5 / 2.0 + ::RandomFloat0To1() * fRange5;
    float fValue = FUN_00404010(0.0f, ::_g_thePlayer->GetCurrentActorValue((ActorValue::Index)0x36));
    float fAngleDifference = 1.5707963267948966 - (fValue + fBase2) / 1000.0 * 3.1415927f;
    if (fValue > 0.0 && fValue < 1.0)
        fValue = 1.0f;
    else
        fValue = ::InventoryStackRecord::RoundToNearestStep(fValue, 1.0f);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileFloatSetter*)pMenu)))->FUN_00a012d0(0x1005, fValue, true);
    reinterpret_cast<::FUN_007f86f0_shell *>((((PipboyInterfaceStub*)((void *)(::fnv_004b7210::FUN_004b7210())))
        ->GetPipboyManager()))->SetKnobTargetAndRate(1, fAngleDifference, ::g_fB5BB800Duration);
}

struct HealText
{
    char* data;
    unsigned short len, cap;
    HealText();
    ~HealText();
    HealText& operator=(const char*);
    operator const char*() const;
};
struct HealTile
{
};
struct HealItem
{
    ~HealItem();
};
struct HealOption
{
    void* item;
    HealTile* tile;
    HealItem* inventory;
    bool(__cdecl* condition)(HealOption*);
};
struct HealPlayer
{
};
struct HealMenu
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    HealOption options[4];
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    HealTile* button;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    bool mode;
    void UpdateOption(int which);
};
// @fnv 0x007db380
void ClickMenu::FUN_007db380(int id, Tile* tile)
{
    if (!tile && id >= 0 && id < 60)
        tile = m_pTiles[id];
    if (FUN_004b71d0() && !reinterpret_cast<::FUN_00a01230_shell *>((((ClickTile*)tile)))->IsTraitNonZero(4015))
        return;
    int skill;
    if (SetIndexFromType(id, &skill))
    {
        reinterpret_cast<::fnv_007dff40::FUN_007dff40_shell *>(this)->SetPage(skill);
        return;
    }
    int special;
    if (reinterpret_cast<::FUN_007e0160_t *>(this)->GetTileIndex(id, &special))
    {
        FUN_007e0060(special);
        return;
    }
    if (id == 9 || (m_bUpdateOption && id == 5))
    {
        reinterpret_cast<::FUN_007e0230 *>(this)->RefreshHealingOptions();
        return;
    }
    if (id == 49)
    {
        reinterpret_cast<::fnv_007e02b0::FUN_007e02b0_StandIn *>(this)->FUN_007e02b0();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (tile == m_kHealingOptions[i].pTile && m_kHealingOptions[i].m_pStatusEffect)
        {
            reinterpret_cast<::FUN_0088c650_shell *>((((ClickPlayer*)::_g_thePlayer)))->FUN_0088c650(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((m_kHealingOptions[i].m_pStatusEffect))->GetName())),
                               (int)(reinterpret_cast<::Callees *>((m_kHealingOptions[i].m_pStatusEffect))->FUN_00726070()),
                               (::ExtraDataList *)(::AlchemyItem *)(((::ClickNode *)(::FUN_00559450((int *)(m_kHealingOptions[i].m_pStatusEffect))))
                                   ? ((::AlchemyItem *)(reinterpret_cast<::SimpleListNodeView*>(((::ClickNode *)(::FUN_00559450((int *)(m_kHealingOptions[i].m_pStatusEffect)))))->m_item))
                                   : 0),
                               false, false, true);
            TESBoundObject* object = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((m_kHealingOptions[i].m_pStatusEffect))->GetName()));
            for (ClickNode* node = (ClickNode*)dynamic_cast<BSSimpleList<EffectItem*>*>(object);
                 node && ((::AlchemyItem *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)); node = ((::ClickNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                reinterpret_cast<::fnv_007dd090::StatsMenuImpl *>(this)->UpdateStatEntry(reinterpret_cast<::EffectItem *>((((ClickAlchemy*)((::AlchemyItem *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))->GetAffectedActorValue());
            }
            reinterpret_cast<::HealMenu *>(this)->UpdateOption(i);
            m_bStatUpdatePending = false;
            reinterpret_cast<::StatsMenuActiveEffects *>(this)->FUN_007ddf00();
            i = 4;
        }
    }
    if (m_bUpdateOption && !FUN_004b71d0())
    {
        int part = reinterpret_cast<::FUN_007db630_Owner *>((((ClickStatus*)((::StatusH *)(::FUN_007db1c0())))))->FindEntryIndex({});
        if (part != 6)
            ::FUN_004d1360((char *)(::_g_thePlayer)) ? ((ClickVirtual*)this)->OnClick(59, 0) : ((ClickVirtual*)this)->OnClick(10, 0);
    }
}

// @fnv 0x007df230
void HealMenu::UpdateOption(int aiOptionIndex)
{
    if (!(*reinterpret_cast<::HealPlayer * *>(&::_g_thePlayer)))
        return;
    for (int indexB = 0; indexB < 4; indexB++)
    {
        if (aiOptionIndex == indexB || aiOptionIndex == 4)
        {
            HealText text;
            delete options[indexB].inventory;
            options[indexB].inventory = ((::HealItem *)(reinterpret_cast<::fnv_00576260::FUN_00576260_shell *>(((*reinterpret_cast<::HealPlayer * *>(&::_g_thePlayer))))->FUN_00576260((::fnv_00576260::TESBoundObject *)(options[indexB].item), 0)));
            reinterpret_cast<::Tile *>((options[indexB].tile))->Set(0xfaf, options[indexB].condition(&options[indexB]));
            if (options[indexB].inventory)
            {
                ::FUN_00406f60((::FUN_00406f90_this *)(::HealText *)(&text), "(%d) %s", ((std::intptr_t)(reinterpret_cast<::Callees *>((options[indexB].inventory))->FUN_00726070())),
                           reinterpret_cast<::FUN_00a011f0_shell *>((options[indexB].tile))->FUN_00a011f0(0x1004));
                if ((indexB == 0 && !::FUN_004d1360((char *)((*reinterpret_cast<::HealPlayer * *>(&::_g_thePlayer))))) || indexB == 3)
                    reinterpret_cast<::Tile *>((button))->Set(0xfaf, 1);
            }
            else
                text = reinterpret_cast<::FUN_00a011f0_shell *>((options[indexB].tile))->FUN_00a011f0(0x1004);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((options[indexB].tile))->FUN_00a01350(0xfc4, (char *)((const char*)text), true);
        }
    }
    if (aiOptionIndex == 0 || aiOptionIndex == 3 || aiOptionIndex == 4)
    {
        int first2 = reinterpret_cast<::CombatState *>(((*reinterpret_cast<::HealPlayer * *>(&::_g_thePlayer))))->GetInventoryItemCount((::TESForm *)(options[0].item));
        int last = reinterpret_cast<::CombatState *>(((*reinterpret_cast<::HealPlayer * *>(&::_g_thePlayer))))->GetInventoryItemCount((::TESForm *)(options[3].item));
        bool enabled3 = true;
        if (::FUN_004d1360((char *)((*reinterpret_cast<::HealPlayer * *>(&::_g_thePlayer)))) && last == 0)
            enabled3 = false;
        else if (!::FUN_004d1360((char *)((*reinterpret_cast<::HealPlayer * *>(&::_g_thePlayer)))) && last == 0 && first2 == 0)
            enabled3 = false;
        if (!enabled3)
        {
            if (mode)
                reinterpret_cast<::FUN_007e0230 *>(this)->RefreshHealingOptions();
            reinterpret_cast<::Tile *>((button))->Set(0xfaf, 0);
        }
    }
}

namespace fnv_007df620 {

struct GSString_00403df0
{
    const char* FUN_00403df0();
};

struct StatsMenuH_007df620
{
    char unk00[0x90];
    Tile* unk90;
    Tile* unk94;
    Tile* unk98;
    Tile* unk9c;
    Tile* unka0;
    char unka4[0xb4 - 0xa4];
    Tile* unkb4;
    char unkb8[0x100 - 0xb8];
    Tile* unk100;
    Tile* unk104;
    Tile* unk108;
    char unk10c[0x164 - 0x10c];
    Tile* unk164;
    int unk168;
    Tile* unk16c;
    int unk170;
    Tile* unk174;
    char unk178[0x2a0 - 0x178];
    bool m_bUpdateOption;
    void UpdateXboxButtonState();
};

// @fnv 0x007df620
void StatsMenuH_007df620::UpdateXboxButtonState()
{
    static int iConsoleButtonTrait = ::FUN_00a00940("_xbox_button", -1);
    static int iEnabledTrait = ::FUN_00a00940("_enabled", -1);
    if (unkb4 && ::FUN_004b71d0())
    {
        unkb4->Set(iConsoleButtonTrait, !m_bUpdateOption + 10);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unkb4))->FUN_00a01350(0xfc4, (char *)(m_bUpdateOption ? (*reinterpret_cast<::fnv_007df620::GSString_00403df0 *>(&::g_011d4708)).FUN_00403df0() : (*reinterpret_cast<::fnv_007df620::GSString_00403df0 *>(&::g_011d2658)).FUN_00403df0()), true);
        unk90->Set(iEnabledTrait, !m_bUpdateOption);
        unk94->Set(iEnabledTrait, !m_bUpdateOption);
        unk98->Set(iEnabledTrait, !m_bUpdateOption);
        unk9c->Set(iEnabledTrait, !m_bUpdateOption);
        unka0->Set(iEnabledTrait, !m_bUpdateOption);
        unk100->Set(iEnabledTrait, !m_bUpdateOption);
        unk104->Set(iEnabledTrait, !m_bUpdateOption);
        unk164->Set(iEnabledTrait, !m_bUpdateOption);
        unk174->Set(iEnabledTrait, !m_bUpdateOption);
        unk16c->Set(iEnabledTrait, !m_bUpdateOption);
        unk108->Set(iEnabledTrait, !m_bUpdateOption);
    }
    reinterpret_cast<::fnv_007dbfe0::BodyPartDisplay *>((((::BodyPartDisplay *)(::FUN_007db1c0()))))->FUN_007dbfe0(m_bUpdateOption);
}
}  // namespace fnv_007df620

namespace fnv_007e0060 {
// FUN_007e0060: /MT /Od /GS /EHsc, 114 bytes, with one stack argument.
// Validates an index against a computed limit, then notifies the owner.


struct FUN_007e0060_owner
{
};

struct FUN_007e0060_cls
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
    FUN_007e0060_owner* m_pSharedOwner;
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
    bool m_bUpdateOption;
    void FUN_007e0230();
    bool FUN_007e0060(int id);
};

// @fnv 0x007e0060
bool FUN_007e0060_cls::FUN_007e0060(int id)
{
    if (id >= 0 && id <= (::FUN_004d1360((char *)(::_g_thePlayer)) ? 5 : 2) && reinterpret_cast<::FUN_007dcc40_shell *>(this)->FUN_007dcc40() != id)
    {
        if (m_bUpdateOption)
        {
            reinterpret_cast<::FUN_007e0230 *>(this)->RefreshHealingOptions();
        }
        reinterpret_cast<::Tile *>((m_pSharedOwner))->Set(0x1004, id);
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_007e0060

struct ActiveCalls : ActiveEffect
{
};
struct EntryEffects
{
    unsigned int unk00, unk04, unk08;
};
struct EffectGroup
{
    TESForm* group;
    EntryEffects normal;
    EntryEffects special;
    EffectGroup(TESForm*);
};
struct EffectGroupList
{
};
struct SettingCalls
{
};
struct FUN_007e08a0_shell
{
    unsigned int unk00;
    EffectGroupList forms;
    void AddEffectToGroup(ActiveCalls*);
};
struct FUN_007e09d0_arg
{
};

struct FUN_007e09d0_sub
{
};

class FUN_007e09d0_cls
{
  public:
    int unk00;
    FUN_007e09d0_sub unk04;
    void FUN_007e09d0(FUN_007e09d0_arg* arg);
};
// Looks up or creates an EffectGroup for the effect's form, then adds the effect to its special or normal list based on a setting flag.
// @fnv 0x007e08a0
void FUN_007e08a0_shell::AddEffectToGroup(ActiveCalls* effect)
{
    TESForm* group = dynamic_cast<TESForm*>(((::MagicItem *)(reinterpret_cast<::Twin_0044ddc0 *>((effect))->GetName())));
    EffectGroup* pGroup = ((::EffectGroup *)(reinterpret_cast<::FUN_007e0c50_list *>(this)->FUN_007e0c50(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((group))->FUN_0084e3a0())))));
    if (!pGroup)
    {
        pGroup = new EffectGroup(group);
        reinterpret_cast<::FUN_00470440 *>(&(forms))->FUN_007a7eb0((::BGSPerkEntry *)(pGroup), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(FUN_007e0480));
    }
    if (reinterpret_cast<::S3e60 *>((((SettingCalls*)effect->GetEffectSetting())))->FUN_00403e60(0x2000))
        reinterpret_cast<::FUN_007e09d0_cls *>(&(pGroup->special))->FUN_007e09d0((::FUN_007e09d0_arg *)(effect));
    else
        reinterpret_cast<::S_007e0a20_Owner *>(&(pGroup->normal))->ApplyParamToEntry((::S_007e0a20_Param *)(effect));
}

// @fnv 0x007e09d0
void FUN_007e09d0_cls::FUN_007e09d0(FUN_007e09d0_arg* arg)
{
    int value = ((int)(reinterpret_cast<::ActiveEffect *>((arg))->GetEffectSetting()));
    if (!reinterpret_cast<::RefList *>(&(unk04))->FUN_005f65d0((void **)(int *)(&value)))
    {
        reinterpret_cast<::FUN_00470440 *>(&(unk04))->FUN_007a7eb0((::BGSPerkEntry *)(((std::intptr_t)(reinterpret_cast<::ActiveEffect *>((arg))->GetEffectSetting()))), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(CompareEffectNames));
    }
}

struct FUN_007a62e0
{
    Tile* tile;
    ActorValue::Index value;
    bool selected;
    FUN_007a62e0(Tile*, ActorValue::Index*);
};
typedef int(__cdecl* ItemCompare)(FUN_007a62e0*, FUN_007a62e0*);
struct ItemListMethods
{
};
struct TraitAction
{
};
struct ItemTileMethods
{
};
struct MenuTemplateMethods
{
};
struct ItemBox : ListBox_enum_ActorValue__Index_
{
    Tile* FUN_007e1430(ActorValue::Index, const char*, ItemCompare, const char*);
};
// @fnv 0x007e1430
Tile* ItemBox::FUN_007e1430(ActorValue::Index value, const char* text, ItemCompare compare, const char* templateName)
{
    if (m_pListTile && (pTemplateName || templateName))
    {
        Tile* tile = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuTemplateMethods*)reinterpret_cast<::FUN_00a03c90_shell *>((((TileH*)m_pListTile)))->FUN_00a03c90())))->FUN_00a1ddb0(m_pListTile, (char *)(templateName ? templateName : pTemplateName), (::Tile *)(0));
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((((ItemTileMethods*)tile)))->FUN_00a00f30(4010))
            tile->Set(4010, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(4036, (char *)(text), true);
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>((((ItemListMethods*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)))->FUN_007a7eb0((::BGSPerkEntry *)(::FUN_007a62e0 *)(new FUN_007a62e0(tile, &value)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_007254d0_t *>(this)->FUN_007254d0();
        }
        else
        {
            reinterpret_cast<::Callees *>((((ItemListMethods*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)))->FUN_00905820((void *)&(const ::FUN_007a62e0 *const &)(new FUN_007a62e0(tile, &value)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::S725970 *>(this)->FUN_00725970();
            }
            tile->Set(4012, m_usSelectedIndex++);
        }
        if (::GetRaceCount((char *)this) == 1 &&
            reinterpret_cast<::TileListBoxCalls *>((((Dummy007_obj*)m_pListTile)))->GetFloat(FUN_00a00940("_number_of_visible_items", -1)) > 0.0)
        {
            TraitAction* action = ((::TraitAction *)(reinterpret_cast<::FUN_00a00e90_shell *>((((ItemTileMethods*)m_pListTile)))->FindTraitValue(4016)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((action))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((action))->FUN_00a09130(2000, tile, 4016);
            reinterpret_cast<::P03Value *>((action))->AppendFloatAction(
                2003, reinterpret_cast<::TileListBoxCalls *>((((Dummy007_obj*)m_pListTile)))->GetFloat(FUN_00a00940("_number_of_visible_items", -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((action))->FUN_00a09410(false);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}

namespace fnv_007e16d0 {
struct FUN_007a62e0
{
    Tile* tile;
    ActorValue::Index value;
    bool filtered;
    FUN_007a62e0(Tile*, ActorValue::Index*);
};
struct ListOperations
{
};
struct TemplateMenu
{
};
struct TileValueOperations
{
};
struct TileOperations
{
};
struct ListBoxInsert : ListBox_enum_ActorValue__Index_
{
    Tile* FUN_007e16d0(ActorValue::Index value, const char* text,
                       int(__cdecl* comparator)(FUN_007a62e0*, FUN_007a62e0*), const char* templateName);
};
// @fnv 0x007e16d0
Tile* ListBoxInsert::FUN_007e16d0(ActorValue::Index value, const char* text,
                                  int(__cdecl* comparator)(FUN_007a62e0*, FUN_007a62e0*), const char* templateName)
{
    if (m_pListTile && (pTemplateName || templateName))
    {
        Tile* tile = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::fnv_007e16d0::TemplateMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((((TileOperations*)m_pListTile)))->FUN_00a03c90()))))->FUN_00a1ddb0(m_pListTile, (char *)(templateName ? templateName : pTemplateName), (::Tile *)(0));
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((((TileOperations*)tile)))->FUN_00a00f30(0xFAA))
            tile->Set(0xFAA, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xFC4, (char *)(text), true);
        if (comparator)
        {
            reinterpret_cast<::FUN_00470440 *>((((ListOperations*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)))->FUN_007a7eb0((::BGSPerkEntry *)(::fnv_007e16d0::FUN_007a62e0 *)(new FUN_007a62e0(tile, &value)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(comparator));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_00725aa0_cls *>(this)->ProcessSlots();
        }
        else
        {
            reinterpret_cast<::Callees *>((((ListOperations*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)))->FUN_00905820((void *)&(const ::fnv_007e16d0::FUN_007a62e0 *const &)(new FUN_007a62e0(tile, &value)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::FUN_00725f40_shell *>(this)->FUN_00725f40();
            }
            tile->Set(0xFAC, m_usSelectedIndex++);
        }
        if (::GetRaceCount((char *)this) == 1 &&
            reinterpret_cast<::TileListBoxCalls *>((((TileOperations*)m_pListTile)))->GetFloat(::FUN_00a00940(kListBoxNumFiltered, -1)) > 0.0)
        {
            TileValueOperations* height = ((::fnv_007e16d0::TileValueOperations *)(reinterpret_cast<::FUN_00a00e90_shell *>((((TileOperations*)m_pListTile)))->FindTraitValue(0xFB0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((height))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((height))->FUN_00a09130(0x7D0, tile, 0xFB0);
            reinterpret_cast<::P03Value *>((height))->AppendFloatAction(
                0x7D3, reinterpret_cast<::TileListBoxCalls *>((((TileOperations*)m_pListTile)))->GetFloat(::FUN_00a00940(kListBoxNumFiltered, -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((height))->FUN_00a09410(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_007e16d0

namespace fnv_007dc490 {

class StatusEntry
{
  public:
};

class StatusMenuOwner
{
  public:
    void FUN_007e0230();
    void FUN_007dc490(int iUnused, int iIndex);

    char unk000[0x160];
    Tile* m_pkTile;  // +0x160
    char unk164[0x13c];
    bool m_bModifierActive;  // +0x2a0
};

// @fnv 0x007dc490
void StatusMenuOwner::FUN_007dc490(int iUnused, int iIndex)
{
    if (m_bModifierActive && !::FUN_004b71d0())
    {
        int iType = reinterpret_cast<::FUN_007db630_Owner *>((((::fnv_007dc490::StatusEntry *)(::FUN_007db1c0()))))->FindEntryIndex({});
        if (iType != 6)
            reinterpret_cast<::FUN_007e0230 *>(this)->RefreshHealingOptions();
    }
    m_pkTile->Set(0xfa3, 0);
}
}  // namespace fnv_007dc490

namespace fnv_007dc1b0 {
struct TileSI : public Tile
{
};
struct PlayerClick
{
};
struct ListClick
{
};
struct StatusH
{
};
class BSSoundHandleEx
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    ~BSSoundHandleEx();
};
class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
extern char DAT_01074f40[];
extern int DAT_011dad60, DAT_011dad64, DAT_011dad68, DAT_011dad6c, DAT_011dad70;
struct ClickMenu : public StatsMenu
{
    void FUN_007e0230();
    void OnTileClick(int id, Tile* tile);
};
// Handles a tile click on the stats menu by dispatching to the current page's list, updating the display, and playing a sound for status effects.
// @fnv 0x007dc1b0
void ClickMenu::OnTileClick(int aiTileIndex, Tile* tile)
{
    if (!tile && aiTileIndex >= 0 && aiTileIndex < 60)
        tile = m_pTiles[aiTileIndex];
    switch (GetCurrentPage())
    {
    case SM_STATUS:
        if (reinterpret_cast<::TileListBoxCalls *>((((TileSI*)tile)))->GetFloat(0xfac) > 0.0)
            reinterpret_cast<::FUN_007dfd20_cls *>(this)->FUN_007dfd20((::Dummy007_obj *)(tile), (unsigned int *)(int *)(&DAT_011dad60));
        if (!::FUN_004b71d0())
        {
            if ((::_g_thePlayer && ::FUN_004d1360((char *)(((PlayerClick*)::_g_thePlayer)))) ? m_kHealingOptions[3].m_pStatusEffect
                                                                             : m_kHealingOptions[0].m_pStatusEffect)
            {
                int status = reinterpret_cast<::FUN_007db630_Owner *>((((::fnv_007dc1b0::StatusH *)(::FUN_007db1c0()))))->FindEntryIndex({});
                if (status != 6)
                {
                    reinterpret_cast<::BodyPartDisplay *>((((::fnv_007dc1b0::StatusH *)(::FUN_007db1c0()))))->SetBodyPart(true, {});
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007dc1b0::BSSoundHandleEx &)(((::fnv_007dc1b0::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID(DAT_01074f40, 0x121)))->FUN_00ad8830(false);
                    if (!m_bUpdateOption)
                        reinterpret_cast<::FUN_007e0230 *>(this)->RefreshHealingOptions();
                }
            }
        }
        break;
    case SM_SPECIAL:
        if (reinterpret_cast<::ListOwner *>((((ListClick*)&m_kPrimaryActorValueList)))->ContainsKey((void *)(tile)))
        {
            reinterpret_cast<::FUN_007dfd20_cls *>(this)->FUN_007dfd20((::Dummy007_obj *)(tile), (unsigned int *)(int *)(&DAT_011dad64));
            reinterpret_cast<::StatsMenuFunction007dc7e0 *>(this)->UpdateStatsDisplay(reinterpret_cast<::LBList *>((((ListClick*)&m_kPrimaryActorValueList)))->FindItemData(tile));
        }
        break;
    case SM_SKILLS:
        if (reinterpret_cast<::ListOwner *>((((ListClick*)&m_kSecondaryActorValueList)))->ContainsKey((void *)(tile)))
        {
            reinterpret_cast<::FUN_007dfd20_cls *>(this)->FUN_007dfd20((::Dummy007_obj *)(tile), (unsigned int *)(int *)(&DAT_011dad68));
            reinterpret_cast<::StatsMenuFunction007dc7e0 *>(this)->UpdateStatsDisplay(reinterpret_cast<::LBList *>((((ListClick*)&m_kSecondaryActorValueList)))->FindItemData(tile));
        }
        break;
    case SM_PERKS:
        if (reinterpret_cast<::ListOwner *>((((ListClick*)&m_kPerkRankList)))->ContainsKey((void *)(tile)))
        {
            reinterpret_cast<::FUN_007dfd20_cls *>(this)->FUN_007dfd20((::Dummy007_obj *)(tile), (unsigned int *)(int *)(&DAT_011dad6c));
            reinterpret_cast<::fnv_007dc9b0::FUN_007dc9b0_shell *>(this)->UpdateScrollBar((::fnv_007dc9b0::EntrySI **)(void *)(reinterpret_cast<::LBList *>((((ListClick*)&m_kPerkRankList)))->FindItemData(tile)));
        }
        break;
    case SM_GENERAL:
        if (reinterpret_cast<::ListOwner *>((((ListClick*)&m_kMiscStatList)))->ContainsKey((void *)(tile)))
            reinterpret_cast<::FUN_007dfd20_cls *>(this)->FUN_007dfd20((::Dummy007_obj *)(tile), (unsigned int *)(int *)(&DAT_011dad70));
        if (reinterpret_cast<::ListOwner *>((((ListClick*)&m_kReputationList)))->ContainsKey((void *)(tile)))
        {
            reinterpret_cast<::fnv_007dcb40::FUN_007dcb40_t *>(this)->SetReputationEntry((::fnv_007dcb40::TESReputation *)(void *)(reinterpret_cast<::LBList *>((((ListClick*)&m_kReputationList)))->FindItemData(tile)));
            reinterpret_cast<::FUN_007dfd20_cls *>(this)->FUN_007dfd20((::Dummy007_obj *)(tile), (unsigned int *)(int *)(&DAT_011dad70));
        }
        break;
    }
}
}  // namespace fnv_007dc1b0

namespace s7e00e0 {

struct Owner
{
    bool SetIndexFromType(unsigned int uiType, int* piIndex);
};

// Sets *piIndex to the matching value for uiType 0-4 and returns true, or returns false for any other value.
// @fnv 0x007e00e0
bool Owner::SetIndexFromType(unsigned int uiType, int* piIndex)
{
    switch (uiType)
    {
    case 0:
        *piIndex = 0;
        return true;
    case 1:
        *piIndex = 1;
        return true;
    case 2:
        *piIndex = 2;
        return true;
    case 3:
        *piIndex = 3;
        return true;
    case 4:
        *piIndex = 4;
        return true;
    }
    return false;
}

}




// Rebuilds the stats menu status-effect tiles and list from the player's active effects and survival stage spells.
// @fnv 0x007ddf00
void StatsMenuActiveEffects::FUN_007ddf00()
{
    BGSDehydrationStage* ph20stage;
    BGSSleepDeprevationStage* psleepstage;
    BGSRadiationStage* pradstage;
    if (m_bStatUpdatePending)
        return;
    m_bStatUpdatePending = true;
    BSStringTChar strtmp;
    Tile* ptile;
    ActiveEffect* pactiveEffect;
    BGSHungerStage* phungerstage;

    ((StatusEffectListOps*)&m_kStatusEffectEntries)->FUN_007e07f0();
    delete m_pStatusEffectAtIndex0;
    m_pStatusEffectAtIndex0 = 0;
    delete m_pStatusEffectAtIndex1;
    m_pStatusEffectAtIndex1 = 0;
    delete m_pStatusEffectAtIndex3;
    m_pStatusEffectAtIndex3 = 0;
    delete m_pStatusEffectAtIndex2;
    m_pStatusEffectAtIndex2 = 0;

    pradstage = BGSRadiationStage::GetStageForLevel(::_g_thePlayer->GetCurrentActorValue((ActorValue::Index)54));
    ph20stage = BGSDehydrationStage::FindStage(::_g_thePlayer->GetCurrentActorValue((ActorValue::Index)73));
    psleepstage = ::GetSleepDeprivationStage(::_g_thePlayer->GetCurrentActorValue((ActorValue::Index)75));
    phungerstage = ::FindHungerStage(::_g_thePlayer->GetCurrentActorValue((ActorValue::Index)74));

    for (BSSimpleList<ActiveEffect*>* pnode = ((ActorMagicTargetView*)::_g_thePlayer)->GetActiveEffectList();
         pnode && (pactiveEffect = ((::ActiveEffect *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))); pnode = ((::BSSimpleList< ::ActiveEffect *> *)(reinterpret_cast<::Callees *>((pnode))->FUN_00726070())))
    {
        if (((bool)(reinterpret_cast<::FUN_00833c20_shell *>((((ActiveEffectOps*)pactiveEffect)))->FUN_00833c20())) &&
            !reinterpret_cast<::EffectItem *>((((EffectItemOps*)((::EffectItem *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ActiveEffectOps*)pactiveEffect)))->FUN_0084e3a0())))))->IsScriptBasedEffect() &&
            (!pactiveEffect->GetEffectSetting()->IsScriptEffect() ||
             reinterpret_cast<::S3e60 *>((((EffectSettingOps*)pactiveEffect->GetEffectSetting())))->FUN_00403e60(0x2000)))
        {
            SpellItem* pspell = dynamic_cast<SpellItem*>(((::MagicItem *)(reinterpret_cast<::Twin_0044ddc0 *>((((ActiveEffectOps*)pactiveEffect)))->GetName())));
            if (pspell && pradstage && pspell == ((::SpellItem *)(reinterpret_cast<::BGSTerrainManager *>((pradstage))->GetMinLevel())))
            {
                if (!m_pStatusEffectAtIndex0)
                    m_pStatusEffectAtIndex0 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex0->pForm == pspell)
                    reinterpret_cast<::S_007e0a20_Owner *>(&(m_pStatusEffectAtIndex0->xEffectData))->ApplyParamToEntry((::S_007e0a20_Param *)(pactiveEffect));
            }
            if (pspell && ph20stage && pspell == ((::SpellItem *)(reinterpret_cast<::BGSTerrainManager *>((ph20stage))->GetMinLevel())))
            {
                if (!m_pStatusEffectAtIndex1)
                    m_pStatusEffectAtIndex1 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex1->pForm == pspell)
                    reinterpret_cast<::S_007e0a20_Owner *>(&(m_pStatusEffectAtIndex1->xEffectData))->ApplyParamToEntry((::S_007e0a20_Param *)(pactiveEffect));
            }
            if (pspell && phungerstage && pspell == ((::SpellItem *)(reinterpret_cast<::BGSTerrainManager *>((phungerstage))->GetMinLevel())))
            {
                if (!m_pStatusEffectAtIndex2)
                    m_pStatusEffectAtIndex2 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex2->pForm == pspell)
                    reinterpret_cast<::S_007e0a20_Owner *>(&(m_pStatusEffectAtIndex2->xEffectData))->ApplyParamToEntry((::S_007e0a20_Param *)(pactiveEffect));
            }
            if (pspell && psleepstage && pspell == ((::SpellItem *)(reinterpret_cast<::BGSTerrainManager *>((psleepstage))->GetMinLevel())))
            {
                if (!m_pStatusEffectAtIndex3)
                    m_pStatusEffectAtIndex3 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex3->pForm == pspell)
                    reinterpret_cast<::S_007e0a20_Owner *>(&(m_pStatusEffectAtIndex3->xEffectData))->ApplyParamToEntry((::S_007e0a20_Param *)(pactiveEffect));
            }
            if (reinterpret_cast<::FUN_00403ee0_shell *>((((EffectItemOps*)((::EffectItem *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ActiveEffectOps*)pactiveEffect)))->FUN_0084e3a0())))))->FUN_00403ee0() &&
                ::FUN_0066eb00(
                    (::ActorValue::Index)(reinterpret_cast<::EffectItem *>((((EffectItemOps*)((::EffectItem *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ActiveEffectOps*)pactiveEffect)))->FUN_0084e3a0())))))->GetAffectedActorValue())) &&
                (pactiveEffect->GetDuration() != 0.0 || ((int)(reinterpret_cast<::BGSMessageInitAccess *>((((ActiveEffectOps*)pactiveEffect)))->GetIconFormID())) == 1 ||
                 ((int)(reinterpret_cast<::BGSMessageInitAccess *>((((ActiveEffectOps*)pactiveEffect)))->GetIconFormID())) == 6 ||
                 ((int)(reinterpret_cast<::BGSMessageInitAccess *>((((ActiveEffectOps*)pactiveEffect)))->GetIconFormID())) == 10 ||
                 (((int)(reinterpret_cast<::BGSMessageInitAccess *>((((ActiveEffectOps*)pactiveEffect)))->GetIconFormID())) == 4 &&
                  reinterpret_cast<::FUN_007df210_shell *>((((ActiveEffectOps*)pactiveEffect)))->FUN_007df210())))
            {
                reinterpret_cast<::FUN_007e08a0_shell *>((((StatusEffectListOps*)&m_kStatusEffectEntries)))->AddEffectToGroup((::ActiveCalls *)(pactiveEffect));
            }
            else if (reinterpret_cast<::S3e60 *>((((EffectSettingOps*)pactiveEffect->GetEffectSetting())))->FUN_00403e60(0x2000))
            {
                reinterpret_cast<::FUN_007e08a0_shell *>((((StatusEffectListOps*)&m_kStatusEffectEntries)))->AddEffectToGroup((::ActiveCalls *)(pactiveEffect));
            }
        }
    }

    if (m_pStatusEffectAtIndex0)
    {
        reinterpret_cast<::S_00a04150_Class *>((((TileOps*)m_pTiles[32])))->FUN_00a04150();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex0->xEffectData; pnode && ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item));
             pnode = ((::BSSimpleList< ::MagicEffectEntry *> *)(reinterpret_cast<::Callees *>((pnode))->FUN_00726070())))
        {
            Tile* ptile = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuOps*)this)))->FUN_00a1ddb0(m_pTiles[32], (char *)("stats_rad_effects_template"), 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_rad_effect_";
            ::fnv_00404820::FUN_00404820((::BSStringT<char> *)&(strtmp), (::fnv_00404820::StrArg)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))));
            reinterpret_cast<::FUN_007df120_Class *>((((TileOps*)ptile)))->FUN_007df120((int)&(strtmp));
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%+d", ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_iMagnitude);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0xfc4, (char *)(const char *)(strtmp), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1005, (char *)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))), true);
        }
        m_pTiles[32]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[32]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex1)
    {
        reinterpret_cast<::S_00a04150_Class *>((((TileOps*)m_pTiles[54])))->FUN_00a04150();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex1->xEffectData; pnode && ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item));
             pnode = ((::BSSimpleList< ::MagicEffectEntry *> *)(reinterpret_cast<::Callees *>((pnode))->FUN_00726070())))
        {
            Tile* ptile = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuOps*)this)))->FUN_00a1ddb0(m_pTiles[54], (char *)("stats_rad_effects_template"), 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_h20_effect_";
            ::fnv_00404820::FUN_00404820((::BSStringT<char> *)&(strtmp), (::fnv_00404820::StrArg)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))));
            reinterpret_cast<::FUN_007df120_Class *>((((TileOps*)ptile)))->FUN_007df120((int)&(strtmp));
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%+d", ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_iMagnitude);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0xfc4, (char *)(const char *)(strtmp), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1005, (char *)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))), true);
        }
        m_pTiles[54]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[54]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex2)
    {
        reinterpret_cast<::S_00a04150_Class *>((((TileOps*)m_pTiles[56])))->FUN_00a04150();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex2->xEffectData; pnode && ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item));
             pnode = ((::BSSimpleList< ::MagicEffectEntry *> *)(reinterpret_cast<::Callees *>((pnode))->FUN_00726070())))
        {
            Tile* ptile = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuOps*)this)))->FUN_00a1ddb0(m_pTiles[56], (char *)("stats_rad_effects_template"), 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_hunger_effect_";
            ::fnv_00404820::FUN_00404820((::BSStringT<char> *)&(strtmp), (::fnv_00404820::StrArg)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))));
            reinterpret_cast<::FUN_007df120_Class *>((((TileOps*)ptile)))->FUN_007df120((int)&(strtmp));
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%+d", ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_iMagnitude);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0xfc4, (char *)(const char *)(strtmp), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1005, (char *)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))), true);
        }
        m_pTiles[56]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[56]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex3)
    {
        reinterpret_cast<::S_00a04150_Class *>((((TileOps*)m_pTiles[58])))->FUN_00a04150();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex3->xEffectData; pnode && ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item));
             pnode = ((::BSSimpleList< ::MagicEffectEntry *> *)(reinterpret_cast<::Callees *>((pnode))->FUN_00726070())))
        {
            Tile* ptile = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuOps*)this)))->FUN_00a1ddb0(m_pTiles[58], (char *)("stats_rad_effects_template"), 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_sleep_effect_";
            ::fnv_00404820::FUN_00404820((::BSStringT<char> *)&(strtmp), (::fnv_00404820::StrArg)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))));
            reinterpret_cast<::FUN_007df120_Class *>((((TileOps*)ptile)))->FUN_007df120((int)&(strtmp));
            ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%+d", ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_iMagnitude);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0xfc4, (char *)(const char *)(strtmp), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1005, (char *)(::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item))->m_eAssociatedActorValue))), true);
        }
        m_pTiles[58]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[58]->Set(0xfa3, 0);
    }

    ptile = 0;
    m_kStatusEffectList.ClearList();
    for (BSSimpleList<StatsMenu__StatusEffect*>* peffectlistnode = (StatusEffectListOps*)&m_kStatusEffectEntries;
         peffectlistnode && ((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item)); peffectlistnode = ((::BSSimpleList< ::StatsMenu__StatusEffect *> *)(reinterpret_cast<::Callees *>((peffectlistnode))->FUN_00726070())))
    {
        ptile = reinterpret_cast<::ItemBox *>((((StatusEffectListBox*)&m_kStatusEffectList)))->FUN_007e1430((::ActorValue::Index)reinterpret_cast<std::intptr_t>(((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item))), (const char *)(0), (int (*)(FUN_007a62e0 *, FUN_007a62e0 *))(0), (const char *)(0));
        AlchemyItem* ppotion = dynamic_cast<AlchemyItem*>(((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item))->pForm);
        if (ppotion && ((std::intptr_t)(reinterpret_cast<::Callees *>((((EquipTypeComponent*)((char*)ppotion + 0x9c))))->FUN_00726070())) == 13)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1004, (char *)((*reinterpret_cast<::GameSettingString *>(&::g_011d1ef0)).GetString()), true);
        }
        else
        {
            TESFullName* pname = dynamic_cast<TESFullName*>(((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item))->pForm);
            if (pname)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1004, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((TESFullNameOps*)pname)))->FUN_00408da0()))), true);
            }
            else
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1004, (char *)(((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item))->pForm->GetName()), true);
            }
        }
        BSStringTChar streffects;
        for (BSSimpleList<EffectSetting*>* pnamelistnode = &((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item))->m_kNamedEffectsList;
             pnamelistnode && ((::EffectSetting *)(reinterpret_cast<::SimpleListNodeView*>(pnamelistnode)->m_item)); pnamelistnode = ((::BSSimpleList< ::EffectSetting *> *)(reinterpret_cast<::Callees *>((pnamelistnode))->FUN_00726070())))
        {
            if ((*(::BSStringTChar *)(reinterpret_cast<::FUN_004046b0_cls *>((void *)(((EffectSettingOps*)((::EffectSetting *)(reinterpret_cast<::SimpleListNodeView*>(pnamelistnode)->m_item)))))->AssignFromSub({}))))
            {
                ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), DAT_01019f08,
                               (const char*)(*(::BSStringTChar *)(reinterpret_cast<::FUN_004046b0_cls *>((void *)(((EffectSettingOps*)((::EffectSetting *)(reinterpret_cast<::SimpleListNodeView*>(pnamelistnode)->m_item)))))->AssignFromSub({}))));
                reinterpret_cast<::FUN_007e0d80_shell *>(&(streffects))->AppendString((::FUN_007e0d80_shell *)&(strtmp));
                if (((::BSSimpleList< ::EffectSetting *> *)(reinterpret_cast<::Callees *>((pnamelistnode))->FUN_00726070())))
                    ::fnv_00404820::FUN_00404820((::BSStringT<char> *)&(streffects), (::fnv_00404820::StrArg)(DAT_01012630));
            }
        }
        if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(streffects))->FUN_004048e0())) > 0 && ((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item))->xEffectData.GetSize())
            ::fnv_00404820::FUN_00404820((::BSStringT<char> *)&(streffects), (::fnv_00404820::StrArg)(DAT_01012630));
        for (BSSimpleList<MagicEffectEntry*>* pdatalistnode = &((::StatsMenu__StatusEffect *)(reinterpret_cast<::SimpleListNodeView*>(peffectlistnode)->m_item))->xEffectData;
             pdatalistnode && ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pdatalistnode)->m_item)); pdatalistnode = ((::BSSimpleList< ::MagicEffectEntry *> *)(reinterpret_cast<::Callees *>((pdatalistnode))->FUN_00726070())))
        {
            if (((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pdatalistnode)->m_item))->m_iMagnitude)
            {
                ::FUN_00406f60((::FUN_00406f90_this *)&(strtmp), "%s %+d", ::FUN_0066eb00((::ActorValue::Index)(((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pdatalistnode)->m_item))->m_eAssociatedActorValue)),
                               ((::MagicEffectEntry *)(reinterpret_cast<::SimpleListNodeView*>(pdatalistnode)->m_item))->m_iMagnitude);
                reinterpret_cast<::FUN_007e0d80_shell *>(&(streffects))->AppendString((::FUN_007e0d80_shell *)&(strtmp));
                if (((::BSSimpleList< ::MagicEffectEntry *> *)(reinterpret_cast<::Callees *>((pdatalistnode))->FUN_00726070())))
                    ::fnv_00404820::FUN_00404820((::BSStringT<char> *)&(streffects), (::fnv_00404820::StrArg)(DAT_01012630));
            }
        }
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ptile))->FUN_00a01350(0x1005, (char *)(const char *)(streffects), true);
    }

    if (ptile)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((((TileOps*)m_pTiles[33])))->FUN_00a012d0(0xfb0,
                  FUN_0042f5a0(8, ::GetRaceCount((char *)(((StatusEffectListBox*)&m_kStatusEffectList)))) * reinterpret_cast<::TileListBoxCalls *>((void *)(ptile))->GetFloat(0xfb0),
                  true);
        ptile->Set(0x1006, 0);
    }
    else
    {
        m_pTiles[33]->Set(0xfb0, 0);
    }
    reinterpret_cast<::FUN_007254d0_t *>((((StatusEffectListBox*)&m_kStatusEffectList)))->FUN_007254d0();
}

namespace fnv_007db680 {
struct InputTile : public Tile
{
};
struct InputChildren
{
};
struct InputList
{
};
struct InputVirtualMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Click(int, Tile*);
};
struct InputStatus
{
};
class FUN_007db2c0;
bool __cdecl FUN_00702450(int);
struct InputRendered
{
};
bool __cdecl IsActorValueBelowPermanent(StatsMenu__HealingOption*);
bool __cdecl IsHealingOptionAvailable(const StatsMenu__HealingOption*);
class BSSoundHandleEx
{
  public:
    unsigned int id;
    bool assume;
    unsigned int state;
    ~BSSoundHandleEx();
};
class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
struct InputSetting
{
};
struct InputPipboy
{
    void FUN_007f8610(int, float, float, bool);
};
struct InputInterface
{
    InputPipboy* FUN_00704370();
};
struct InputControls
{
};
struct InputOS
{
};
extern unsigned int DAT_011dad5c;

struct InputStats : public StatsMenu
{
    bool FUN_007db680(int code, float amount);
};

// Processes input codes for the stats menu, updating healing options, status values, page navigation, and scrolling effect lists.
// @fnv 0x007db680
bool InputStats::FUN_007db680(int code, float amount)
{
    if (!FUN_00702450(1003) || !reinterpret_cast<::FOPipboyManager *>((((::fnv_007db680::InputRendered *)(::fnv_00705990::FUN_00705990()))))->IsUnk28Set())
        return false;
    if (FUN_00702450(1003))
    {
        if (m_bUpdateOption && (code == 1 || code == 2 || code == 4 || code == 3))
        {
            int direction;
            switch (code)
            {
            case 1:
                direction = 0;
                break;
            case 2:
                direction = 1;
                break;
            case 4:
                direction = 2;
                break;
            case 3:
                direction = 3;
                break;
            default:
                return false;
            }
            int selected3 =
                ((int)(reinterpret_cast<::S_007dc010 *>((((InputStatus*)((::fnv_007db680::FUN_007db2c0 *)(::FUN_007db1c0())))))->GetByte(((unsigned int)(::FUN_00559450((int *)(((InputStatus*)((::fnv_007db680::FUN_007db2c0 *)(::FUN_007db1c0()))))))), direction)));
            if (selected3 < 6)
            {
                reinterpret_cast<::BodyPartDisplay *>((((InputStatus*)((::fnv_007db680::FUN_007db2c0 *)(::FUN_007db1c0())))))->SetBodyPart(selected3, true);
                m_kHealingOptions[0].pTile->Set(0xfaf, IsActorValueBelowPermanent(&m_kHealingOptions[0]));
                m_kHealingOptions[3].pTile->Set(0xfaf, IsHealingOptionAvailable(&m_kHealingOptions[3]));
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007db680::BSSoundHandleEx &)(((::fnv_007db680::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIPipBoyHighlight", 0x121)))->FUN_00ad8830(false);
            }
            return true;
        }
        else if ((code == 13 || code == 14) && amount >= 1.0)
        {
            ::s717280::FUN_00717280(0x24);
            if (code == 13)
                ::fnv_00704170::UpdatePipboyMapVisibility(1, false);
            else
                ::sleep704::FUN_007048f0(1, false, true);
            return true;
        }
        else if (code == 4)
        {
            Page _previousPage = GetCurrentPage();
            reinterpret_cast<::fnv_007dff40::FUN_007dff40_shell *>(this)->SetPage((*(int *)&(const ::StatsMenu::Page &)(_previousPage == 0 ? SM_LAST_PAGE : *((::StatsMenu::Page *)(::DecrementInt((int *)(::StatsMenu::Page *)(&_previousPage)))))));
            reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[0])))->FUN_00a0b110(0xfcb);
            return true;
        }
        else if (code == 3)
        {
            Page nextPage = GetCurrentPage();
            reinterpret_cast<::fnv_007dff40::FUN_007dff40_shell *>(this)->SetPage((*(int *)&(const ::StatsMenu::Page &)(nextPage == 4 ? SM_FIRST_PAGE : *((::StatsMenu::Page *)(::TESReputation::GetUnsignedIntegerPointer((unsigned int *)(::StatsMenu::Page *)(&nextPage)))))));
            reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[0])))->FUN_00a0b110(0xfcb);
            return true;
        }
        else if (GetCurrentPage() == SM_GENERAL)
        {
            if (code == 11)
            {
                ((InputVirtualMenu*)this)->Click(0x31, 0);
                return true;
            }
        }
        else if (GetCurrentPage() == SM_STATUS)
        {
            if (code == 1 || code == 2)
            {
                int statusStep6 = code == 1 ? -1 : 1;
                int newStatusVal = reinterpret_cast<::FUN_007dcc40_shell *>(this)->FUN_007dcc40() + statusStep6;
                if (reinterpret_cast<::fnv_007e0060::FUN_007e0060_cls *>(this)->FUN_007e0060(newStatusVal))
                {
                    int limbVal = 6;
                    if (reinterpret_cast<::FUN_007e0160_t *>(this)->GetTileIndex(0x1c, &limbVal) && limbVal == newStatusVal)
                        reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[28])))->FUN_00a0b110(0xfcb);
                    else if (reinterpret_cast<::FUN_007e0160_t *>(this)->GetTileIndex(0x1d, &limbVal) && limbVal == newStatusVal)
                        reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[29])))->FUN_00a0b110(0xfcb);
                    else if (reinterpret_cast<::FUN_007e0160_t *>(this)->GetTileIndex(0x1e, &limbVal) && limbVal == newStatusVal)
                        reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[30])))->FUN_00a0b110(0xfcb);
                    else if (reinterpret_cast<::FUN_007e0160_t *>(this)->GetTileIndex(0x35, &limbVal) && limbVal == newStatusVal)
                        reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[53])))->FUN_00a0b110(0xfcb);
                    else if (reinterpret_cast<::FUN_007e0160_t *>(this)->GetTileIndex(0x37, &limbVal) && limbVal == newStatusVal)
                        reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[55])))->FUN_00a0b110(0xfcb);
                    else if (reinterpret_cast<::FUN_007e0160_t *>(this)->GetTileIndex(0x39, &limbVal) && limbVal == newStatusVal)
                        reinterpret_cast<::FUN_00a0b110_shell *>((((InputTile*)m_pTiles[57])))->FUN_00a0b110(0xfcb);
                    ((::fnv_007db680::InputInterface *)(::fnv_004b7210::FUN_004b7210()))->FUN_00704370()->FUN_007f8610(0, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007db680::InputSetting *>(&::g_011db2f0)))))) * statusStep6,
                                                                 *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007db680::InputSetting *>(&::g_011db358)))))), true);
                    return true;
                }
            }
            else if (code == 9)
            {
                switch (reinterpret_cast<::FUN_007dcc40_shell *>(this)->FUN_007dcc40())
                {
                case 0:
                    ((InputVirtualMenu*)this)->Click(10, 0);
                    return true;
                case 1:
                    ((InputVirtualMenu*)this)->Click(11, 0);
                    return true;
                default:
                    return false;
                }
            }
            else if (code == 11)
            {
                switch (reinterpret_cast<::FUN_007dcc40_shell *>(this)->FUN_007dcc40())
                {
                case 0:
                    if (!m_bUpdateOption && reinterpret_cast<::FUN_00a01230_shell *>((((InputTile*)m_pTiles[9])))->IsTraitNonZero(0xfaf))
                    {
                        ((InputVirtualMenu*)this)->Click(9, 0);
                        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007db680::BSSoundHandleEx &)(((::fnv_007db680::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIMenuOK", 0x121)))->FUN_00ad8830(false);
                        return true;
                    }
                    return false;
                case 1:
                    ((InputVirtualMenu*)this)->Click(31, 0);
                    return true;
                default:
                    return false;
                }
            }
            else if (code == 12)
            {
                switch (reinterpret_cast<::FUN_007dcc40_shell *>(this)->FUN_007dcc40())
                {
                case 0:
                    if (reinterpret_cast<::FUN_00a01230_shell *>((((InputTile*)m_pTiles[9])))->IsTraitNonZero(0xfaf))
                    {
                        ((InputVirtualMenu*)this)->Click(59, 0);
                        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007db680::BSSoundHandleEx &)(((::fnv_007db680::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIMenuOK", 0x121)))->FUN_00ad8830(false);
                        return true;
                    }
                    return false;
                case 1:
                    ((InputVirtualMenu*)this)->Click(31, 0);
                    return true;
                default:
                    return false;
                }
            }
        }
        if (::FUN_00709d40() &&
            (reinterpret_cast<::sa040a0::Owner *>((((::fnv_007db680::InputTile *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((InputList*)&m_kStatusEffectList)))->FUN_00825c00()))))->IsAllChildrenFlag0() ||
             reinterpret_cast<::FUN_00a01230_shell *>((((InputTile*)((::Tile *)(reinterpret_cast<::InventoryStackRecord *>((((InputChildren*)&m_pTiles[26]->m_kChildTileList)))->GetPayloadAddress())))))->IsTraitNonZero(0xfa3)))
        {
            int axisB = 0;
            int scrollStepVal4 = 0;
            axisB = reinterpret_cast<::FUN_00a23390_t *>((((::fnv_007db680::InputControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_007db680::InputOS * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState(0, 10);
            if (::FUN_00408820((float)axisB) <= 8689.0)
                axisB = 0;
            if (axisB != 0)
                scrollStepVal4 = axisB >= 0 ? -1 : 1;
            if (scrollStepVal4 != 0 && ((unsigned int)(::FUN_00457fe0())) > DAT_011dad5c)
            {
                InputTile* scrollTile =
                    GetCurrentPage() == SM_STATUS
                        ? ((::fnv_007db680::InputTile *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((InputList*)&m_kStatusEffectList)))->FUN_00825c00()))
                        : (InputTile*)((::Tile *)(reinterpret_cast<::InventoryStackRecord *>((((InputChildren*)&m_pTiles[26]->m_kChildTileList)))->GetPayloadAddress()));
                int trait3 = ::FUN_00a01860("_current_value");
                int oldValue4 = (int)reinterpret_cast<::TileListBoxCalls *>((scrollTile))->GetFloat(trait3);
                reinterpret_cast<::FUN_00a012d0_t *>((scrollTile))->FUN_00a012d0(trait3, (float)(oldValue4 + scrollStepVal4), false);
                if (oldValue4 != reinterpret_cast<::TileListBoxCalls *>((scrollTile))->GetFloat(trait3))
                    reinterpret_cast<::FUN_00a01290_shell *>((scrollTile))->SetTraitAndReset(::FUN_00a01860("_SetInCode"), 1.0f);
                DAT_011dad5c =
                    ((unsigned int)(::FUN_00457fe0())) + (DAT_011dad5c ? (int)reinterpret_cast<::TileListBoxCalls *>((((InputTile*)m_pTiles[33])))->GetFloat(0x1004)
                                                      : (int)reinterpret_cast<::TileListBoxCalls *>((((InputTile*)m_pTiles[33])))->GetFloat(0x1005));
            }
            else if (scrollStepVal4 == 0)
                DAT_011dad5c = 0;
        }
    }
    return false;
}
}  // namespace fnv_007db680

#include "generated/data/fallout/interface/menus/statsmenu.inc"
