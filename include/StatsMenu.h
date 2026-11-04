// Source layout: StatsMenu. PC corrections are in generate_headers.py.
#ifndef FNV_STATSMENU_H
#define FNV_STATSMENU_H

#include "layout_support.h"
#include "ListBox_PerkRankData___.h"
#include "ListBox_StatsMenu__StatusEffect___.h"
#include "ListBox_TESReputation___.h"
#include "ListBox_enum_ActorValue__Index_.h"
#include "ListBox_enum_MiscStatManager__MiscStatID_.h"
#include "Menu.h"
#include "StatsMenu__HealingOption.h"
#include "StatsMenu__NamedEffectsList.h"
#include "StatsMenu__StatusEffectList.h"
class StatsMenu : public Menu
{
  public:
    StatsMenu__HealingOption m_kHealingOptions[4];               // +0x28
    StatsMenu__NamedEffectsList m_kNamedEffectsList;             // +0x68
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex0;            // +0x74
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex1;            // +0x78
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex2;            // +0x7C
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex3;            // +0x80
    StatsMenu__StatusEffectList m_kStatusEffectEntries;          // +0x84
    Tile* m_pTiles[60];                                          // +0x90
    ListBox_enum_ActorValue__Index_ m_kPrimaryActorValueList;    // +0x180
    ListBox_enum_ActorValue__Index_ m_kSecondaryActorValueList;  // +0x1B0
    ListBox_PerkRankData___ m_kPerkRankList;                     // +0x1E0
    ListBox_enum_MiscStatManager__MiscStatID_ m_kMiscStatList;   // +0x210
    ListBox_StatsMenu__StatusEffect___ m_kStatusEffectList;      // +0x240
    ListBox_TESReputation___ m_kReputationList;                  // +0x270
    bool m_bUpdateOption;                                        // +0x2A0
    bool m_bStatUpdatePending;                                   // +0x2A1
    unsigned short layoutPadding2A2;
    int GetClass();
};
#endif
