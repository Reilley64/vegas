// bsmenu/tilemenu_decls.h: declares Menu, Interface, TileListBoxCalls
#ifndef TILEMENU_DECLS_H
#define TILEMENU_DECLS_H

#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00a1d000.h"
#include "fnv/symbols_011f3000.h"
class Tile;
class TileMenu;
enum MenuID
{
    kMenuID = 0
};
class Menu
{
  public:
    virtual ~Menu();
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
    virtual int GetID();
    virtual void v14();
    virtual void v15();
    virtual void OnUpdateUserTrait(int);
    static __forceinline void SetVisible(int id, bool b)
    {
        if (id >= 1001 && id <= 1084)
            DAT_011f308f[id] = b;
    }
    static void SetMenuRootTile(int, Tile*);
    __forceinline void SetModal(int id)
    {
        m_iModalMenuId = id;
    }
    char pad[16];
    int m_iModalMenuId;
    char pad2[8];
    int m_iMenuId;
};
class Interface
{
  public:
    static Menu* GetMenuById(int);
};
class TileListBoxCalls
{
  public:
    float GetFloat(int);
};
#endif
