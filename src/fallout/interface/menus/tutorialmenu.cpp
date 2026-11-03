
// src/fallout/interface/menus/tutorialmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/tutorialmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a1d9e0__FUN_00a1d9e0_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_007cc000.h"
#include "fnv/symbols_007d0000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011db000.h"
struct FUN_007e8e20_shell
{
    void FUN_007e8e20();
};

struct TutorialMenu
{
    bool FUN_007e8e60(int aiButton, float afValue);
};

// @fnv 0x007e8e60
bool TutorialMenu::FUN_007e8e60(int aiButton, float afValue)
{
    bool bhandled = false;
    return bhandled;
}

struct FUN_007e8e40_shell : FUN_007e8e20_shell
{
    void DecrementAndDispatch();
};

struct Tile
{
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
struct Menu
{
public:
    void SetMenuVisibility(bool);
};
struct FORenderedMenu;

struct BSSimpleList
{
};

// @fnv 0x007e8d60
void FUN_007e8d60()
{
    if ((*reinterpret_cast<::Menu * *>(&::DAT_011db088)))
    {
        reinterpret_cast<Tile*>(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList*>((*reinterpret_cast<::Menu * *>(&::DAT_011db088)))))->FUN_00726070())->Set(0x1772, 1);
        if (::FUN_00707ad0())
            reinterpret_cast<::fnv_00a1d9e0::FUN_00a1d9e0_shell *>(((*reinterpret_cast<::Menu * *>(&::DAT_011db088))))->FUN_00a1d9e0();
        else
            reinterpret_cast<::FUN_00a1d910_shell *>(((*reinterpret_cast<::Menu * *>(&::DAT_011db088))))->FUN_00a1d910();
        HandleBackAction();
    }
}

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int);
};
struct Interface
{
    enum enumGamepadButtons
    {
        E10 = 10
    };
};
class Tile;
struct InterfaceManager
{
    static void __cdecl SendGamepadButton(Interface::enumGamepadButtons);
public:
    ::Tile *FUN_00586150();
};
void __cdecl FUN_007e8d60();
struct VHack
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
};
struct TMenu
{
    bool HandleGamepadButton(int aiButton, float afValue);
};
// @fnv 0x007e8e80
bool TMenu::HandleGamepadButton(int aiButton, float afValue)
{
    if (InterfaceH::GetSelectedTargetIndex(((VHack*)this)->v13()) && aiButton == 10)
    {
        ::fnv_004b7210::FUN_004b7210();
        InterfaceManager::SendGamepadButton((Interface::enumGamepadButtons)10);
        FUN_007e8d60();
        return true;
    }
    else
    {
        return false;
    }
}

namespace fnv_007e9010 {
struct Tile
{
};
struct FUN_007e9010_Owner
{
    char _pad0[44];
    Tile* tileA;
    Tile* tileB;
    char _pad1[20];
    unsigned int m_iMapDisplayMode;
    unsigned int m_uiPageCount;
    void FUN_007e9010();
};
// @fnv 0x007e9010
void FUN_007e9010_Owner::FUN_007e9010()
{
    reinterpret_cast<::Tile *>((tileB))->Set(0xFAF, 0 < m_iMapDisplayMode);
    reinterpret_cast<::Tile *>((tileA))->Set(0xFAF, m_iMapDisplayMode + 1 < m_uiPageCount);
}
}  // namespace fnv_007e9010

struct FUN_007e8db0_shell : FUN_007e8e40_shell
{
    Tile* m_pTiles[32];
    void FUN_007e8db0(int aiID, Tile* apTarget);
};

// Resolves apTarget from the tile array at offset 0x28 when null and aiID is 0-7, then dispatches on aiID to one of three handlers.
// @fnv 0x007e8db0
void FUN_007e8db0_shell::FUN_007e8db0(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 8)
        apTarget = (&this->m_pTiles[10])[aiID];
    switch (aiID)
    {
    case 1:
        FUN_007e8e20();
        break;
    case 2:
        DecrementAndDispatch();
        break;
    case 3:
        FUN_007e8d60();
        break;
    }
}

struct MenuValueField
{
};
struct MenuStringReader
{
    virtual void Read0();
    virtual void Read1();
    virtual void Read2();
    virtual void Read3();
    virtual char* ReadString(int unused, unsigned int recordType);
};
struct MenuRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MenuValueField value18;
    int unk1c;
    int unk20;
    MenuStringReader record24;
};
struct MenuTileField
{
};
struct TutorialMenuView
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
    MenuTileField* text28;
    int unk2c;
    int unk30;
    int unk34;
    MenuTileField* text38;
    int unk3c;
    MenuTileField* text40;
    void ApplyRecordToTiles(MenuRecord* record);
};
// @fnv 0x007e9060
void TutorialMenuView::ApplyRecordToTiles(MenuRecord* record)
{
    char* description;
    if (!record)
        return;
    if (text38 != 0)
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((text38))->FUN_00a01350(0xFC4, ((char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(record->value18))->FUN_00408da0())), 1);
    }
    if (text28 != 0)
    {
        description = record->record24.ReadString(0, 0x43534544);
        if (description != 0)
        {
            reinterpret_cast<::Tile *>((text28))->Set(0xFBE, description[0] == '<');
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((text28))->FUN_00a01350(0xFC4, description, 1);
        }
    }
    if (text40 != 0)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((text40))->FUN_00a012d0((int)(((void *)(::FUN_00a00940(str_010702d8, -1)))), 0.0f, 0);
    }
}

struct BSStringT
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    operator const char*() const;
};

class TESForm
{
  public:
    virtual ~TESForm();
public:
    void ClearData();
};
class BGSMessage : public TESForm
{
};

struct HelpTile
{
};

struct HelpListNode
{
};

struct HelpMenuShell
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
    HelpTile* pPageTile;
    int unk40;
    int unk44;
    unsigned int uiCurrentPage;
    unsigned int uiPageCount;
    HelpListNode* pPages;
    void ShowPageByIndex(unsigned int auiPage);
};
// @fnv 0x007e8e20
void FUN_007e8e20_shell::FUN_007e8e20()
{
    reinterpret_cast<::HelpMenuShell *>(this)->ShowPageByIndex(*(int*)(this + 0x48) + 1);
}
// @fnv 0x007e8e40
void FUN_007e8e40_shell::DecrementAndDispatch()
{
    reinterpret_cast<::HelpMenuShell *>(this)->ShowPageByIndex(((int*)this)[0x48 / 4] - 1);
}

// Sets the current help page index, updates the page counter tile, walks the page list to the requested page, shows it and refreshes the menu.
// @fnv 0x007e8ed0
void HelpMenuShell::ShowPageByIndex(unsigned int auiPage)
{
    if (auiPage < uiPageCount)
    {
        BSStringT kText;
        uiCurrentPage = auiPage;
        ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT *)(&kText), "%d/%d", auiPage + 1, uiPageCount);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pPageTile))->FUN_00a01350(0xfc4, (char *)(kText), true);
        HelpListNode* pPageNode = pPages;
        while (pPageNode && auiPage--)
        {
            pPageNode = ((::HelpListNode *)(reinterpret_cast<::Callees *>((pPageNode))->FUN_00726070()));
        }
        if (!pPageNode)
        {
            ::FUN_005b5e40();
            return;
        }
        reinterpret_cast<::TutorialMenuView *>(this)->ApplyRecordToTiles((::MenuRecord *)(::BGSMessage *)(dynamic_cast<BGSMessage*>(*((::TESForm **)(new ((void *)(pPageNode)) ::Vec3())))));
        reinterpret_cast<::fnv_007e9010::FUN_007e9010_Owner *>(this)->FUN_007e9010();
    }
}

struct TileX;
struct HelpListNode;
struct IMF;
struct TileNU;

class AA
{
  public:
    virtual ~AA();
};

struct TileMenu
{
    int unk;
};

struct SettingX
{
};
extern char str_01077ba4[];

struct StrMem : BSStringT
{
    StrMem();
    ~StrMem();
};

class BGSListForm : public TESForm
{
  public:
    HelpListNode* FUN_00500940();
};

struct TForm2
{
};

struct IMF
{
};

struct TileX
{
};

void* __cdecl FUN_00ec43fb(void* apObject, long alVfDelta, void* apSrcType, void* apDstType, int aiIsRef);

class HMenuX
{
  public:
    virtual ~HMenuX();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual int vGet();
    int pad0[10];
    TileX* t2c;
    TileX* t30;
    TileX* t34;
    int pad1;
    TileX* t3c;
    int pad2;
    TileX* t44;
    unsigned int u48;
    unsigned int u4c;
    HelpListNode* pPages;
};

struct HelpListNode;


// @fnv 0x007e8890
bool InitTutorialMenu(TESForm* apMsg, bool aFlag)
{
    AA* p = ((::AA *)(::FUN_00a09030(FUN_007cc6d0())));
    if (p)
        delete p;

    TileX* pTile = ((::TileX *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::TileX *)(reinterpret_cast<::InterfaceManager *>((((IMF*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00586150()))))->FUN_00a01b00((void *)(str_01077ba4))));
    (*reinterpret_cast<::Menu * *>(&::DAT_011db088)) = pTile ? reinterpret_cast<::FUN_00a03c90_shell *>((pTile))->FUN_00a03c90() : 0;

    if ((*reinterpret_cast<::Menu * *>(&::DAT_011db088)) != 0 && ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->vGet() == FUN_007cc6d0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))))->FUN_00a1dc70((::TileMenu *)(void *)(FUN_00ec43fb(pTile, 0, (void*)&typeid(Tile), (void*)&typeid(TileMenu), 0)), 0);

        if (reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), 1);

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t44))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d2340))))->GetMenuTitle()))), 1);

        if (aFlag)
        {
            BGSListForm* pForm = FUN_004b71d0() ? dynamic_cast<BGSListForm*>(FUN_004839c0(0x165u))
                                                : dynamic_cast<BGSListForm*>(FUN_004839c0(0x163u));
            if (pForm)
            {
                ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->pPages = pForm->FUN_00500940();
                if (apMsg == 0)
                    apMsg = dynamic_cast<BGSMessage*>(*((::TESForm **)(new ((void *)(((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->pPages)) ::Vec3())));
            }
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t2c))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d34b0))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t30))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d4468))))->GetMenuTitle()))), 1);
        }
        else
        {
            reinterpret_cast<::Tile *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t2c))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t30))->Set(0xfa3, 0);
        }

        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t34))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d22b0))))->GetMenuTitle()))), 1);

        if (apMsg == 0)
            ::FUN_005b5e40();

        ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u4c = 0;
        ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u48 = 0;
        HelpListNode* node5;
        bool found2 = false;
        node5 = ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->pPages;
        while (node5 != 0 && *((::TESForm **)(new ((void *)(node5)) ::Vec3())) != 0)
        {
            if (!found2 && *((::TESForm **)(new ((void *)(node5)) ::Vec3())) == apMsg)
            {
                ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u48 = ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u4c;
                found2 = true;
            }
            ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u4c = ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u4c + 1;
            node5 = ((::HelpListNode *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
        }

        if (found2)
        {
            StrMem str;
            ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT *)(&str), "%d/%d", ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u48 + 1, ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u4c);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t3c))->FUN_00a01350(0xfc4, (char *)(str), 1);
        }
        else
        {
            reinterpret_cast<::Tile *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->t3c))->Set(0xfa3, 0);
            ((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))->u4c = 0;
        }

        if (apMsg != 0)
        {
            reinterpret_cast<::TutorialMenuView *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))))->ApplyRecordToTiles((::MenuRecord *)(apMsg));
            reinterpret_cast<::fnv_007e9010::FUN_007e9010_Owner *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))))->FUN_007e9010();
            reinterpret_cast<::TESForm *>((((TForm2*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))))->ClearData();
            reinterpret_cast<::FUN_00a012d0_t *>((((::TileX *)(reinterpret_cast<::FUN_0045cd60_shell *>((((IMF*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60()))))->FUN_00a012d0(0xfa9, DAT_01023cd8, 1);
            reinterpret_cast<::Menu *>((((HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))))->SetMenuVisibility(0);
            return true;
        }
        else
        {
            delete (HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088));
            return false;
        }
    }
    else
    {
        if ((*reinterpret_cast<::Menu * *>(&::DAT_011db088)) != 0 && reinterpret_cast<::Callees *>((((BSSimpleList*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088)))))->FUN_00726070())
            delete (HMenuX*)(*reinterpret_cast<::Menu * *>(&::DAT_011db088));
    }
    return false;
}

#include "generated/data/fallout/interface/menus/tutorialmenu.inc"
