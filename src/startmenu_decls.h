// startmenu_decls.h: declares Interface
#ifndef FNV_STARTMENU_DECLS_H
#define FNV_STARTMENU_DECLS_H

class Tile;
template <class T> class ListBox
{
  public:
    virtual void vfn_0();
    virtual Tile* vfn_4();
    unsigned char data[44];
    bool IsSelected(Tile*);
};
struct Interface
{
  public:
    enum enumMenus
    {
        START_MENU = 0x3f5
    };
    static bool GetSelectedTargetIndex(enumMenus);
};
#endif
