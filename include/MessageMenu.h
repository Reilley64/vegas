// Source layout: MessageMenu. PC corrections are in generate_headers.py.
#ifndef FNV_MESSAGEMENU_H
#define FNV_MESSAGEMENU_H
#include "layout_support.h"
#include "GameTimerRecord.h"
#include "ListBox_int_.h"
#include "Menu.h"
class MessageMenu : public Menu
{
  public:
    Tile* m_pTiles[6];              // +0x28
    ListBox_int_ m_kChoiceList;     // +0x40
    GameTimerRecord m_kTimerCalls;          // +0x70
    unsigned int m_uiMessageCount;  // +0x90
    int GetClass();
};
#endif
