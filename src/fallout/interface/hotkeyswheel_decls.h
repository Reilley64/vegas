// fallout/interface/hotkeyswheel_decls.h: declares Tile
#ifndef HOTKEYSWHEEL_DECLS_H
#define HOTKEYSWHEEL_DECLS_H

#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a23e10_Class.h"
#include "fnv/decl/FUN_00a24180_shell.h"
#include "fnv/decl/InputManager245.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_01011000.h"
class Tile
{
  public:
    void Set(int, int);
};
class HotkeyWheelDisplay
{
  public:
    Tile* m_pWheelTile;
    Tile* m_ppHotkeySlotTiles[8];
    bool m_bHasHotkeySelection;
    unsigned char pad[3];
    int m_iTileValueIdAtOffset28, m_iTileValueIdAtOffset2C, m_iTileValueIdAtOffset30;
    bool GetVisible();
    void SetVisible(bool);
    void Initialize(Tile*);
    char inputPadding[0x1b92 - 0x34];
    unsigned short flags;
    unsigned char keyboard[3][28];
    unsigned char controller[28];
    int SetHotkeyItem(int, int);
};
template <class T> class BSStringT
{
    T* data;
    unsigned short length, capacity;

  public:
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    const char* String();
};
extern const char DAT_0106eaa0[], DAT_0106ea94[], DAT_0106ea84[], DAT_0106ea74[];
__forceinline unsigned short HotkeySuppressedMask()
{
    return 8;
}
extern bool DAT_011f35c8;
#endif
