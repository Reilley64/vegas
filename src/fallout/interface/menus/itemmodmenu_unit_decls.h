// fallout/interface/menus/itemmodmenu_unit_decls.h: declares Menu, ListBox_ItemChange___, Tile, InterfaceManager, InventoryMenu and more
#ifndef ITEMMODMENU_UNIT_DECLS_H
#define ITEMMODMENU_UNIT_DECLS_H


#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011da000.h"

class Tile;
class TileMenu;

class Menu
{
  public:
    unsigned char opaque_04_27[0x24];

    virtual Menu* Destructor(bool doFree) = 0;
    virtual void SetTile(unsigned int idx, Tile* value) = 0;
    virtual void HandleLeftClickPress(unsigned int tileID, Tile* activeTile) = 0;
    virtual void HandleClick(int tileID, Tile* clickedTile) = 0;
    virtual void HandleMouseover(unsigned int tileID, Tile* activeTile) = 0;
    virtual void HandleMouseoverTileAlt(unsigned int tileID, Tile* tile) = 0;
    virtual void PostDragTileChange(unsigned int tileID, Tile* newTile, Tile* activeTile) = 0;
    virtual void PreDragTileChange(unsigned int tileID, Tile* oldTile, Tile* activeTile) = 0;
    virtual void HandleActiveMenuClick(unsigned int tileID, Tile* activeTile) = 0;
    virtual void OnClickHeld(unsigned int tileID, Tile* activeTile) = 0;
    virtual void HandleMousewheel(unsigned int tileID, Tile* tile) = 0;
    virtual void Update() = 0;
    virtual bool HandleKeyboardInput(unsigned int inputChar) = 0;
    virtual unsigned int GetID() = 0;

    Menu();
    ~Menu();
    void SetMenuVisibility(bool visible);

};

class ListBox_ItemChange___
{
  public:
    unsigned char opaque[0x30];

    ListBox_ItemChange___();
    ~ListBox_ItemChange___();
    void Initialize(Tile*, const char*);
    void FUN_007a1930(bool);
};

class Tile
{
  public:
    virtual Tile* Destroy(bool doFree) = 0;


    static float GetInterfaceScale();
public:
    void Set(int, int);
};

class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};

class InventoryStackRecord;
class InventoryMenu
{
  public:
public:
    static ::InventoryStackRecord *ms_pActionPointSource;
};

class TileListBoxCalls
{
  public:
    float GetFloat(int);
};

class MapMenu
{
  public:
    void RefreshMapMenu(bool selected);
};

class BGSPerkEntry;

template <class T> class BSSimpleList
{
  public:
    BSSimpleList* GetNext();
};

template <class T> class ListBox
{
  public:
    void Initialize(Tile* tile, const char* templateName);
};

class ItemModMenu : public Menu
{
  public:
    Tile* m_pTiles[14];
    ListBox_ItemChange___ m_kItemList;

    ItemModMenu();
    Tile* __cdecl Create();
    int GetClass();
};

class RepairMenu : public Menu
{
  public:
    Tile* m_pTiles[13];
    ListBox_ItemChange___ m_kItemList;

    RepairMenu();
};


extern "C"
{
    extern void* DAT_01073b7c;
    extern void* DAT_01075c5c;

    extern const char DAT_01073b64[];
    extern const char DAT_01075c44[];
    extern const char DAT_01073bc4[];
    extern const char DAT_01073be0[];
    extern const char DAT_01073c34[];


    extern int DAT_011d9f3c;
    extern unsigned char DAT_011d9f40;
    extern int DAT_011d9f44;
    extern int DAT_011d9f48;
    extern int DAT_011d9f4c;

    extern int DAT_011da750;
}

int __cdecl FUN_00783640();

#endif
