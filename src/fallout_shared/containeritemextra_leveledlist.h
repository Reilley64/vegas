// fallout_shared/containeritemextra_leveledlist.h: declares TESLeveledList
#ifndef FNV_CONTAINERITEMEXTRA_LEVELEDLIST_H
#define FNV_CONTAINERITEMEXTRA_LEVELEDLIST_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class LeveledObject;
class TESGlobal;
class TESLeveledList : public BaseFormComponent
{
  public:
    BSSimpleList<LeveledObject*> leveledList;
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    unsigned char layoutPaddingE[2];
    TESGlobal* m_pLevelGlobal;
    BSSimpleList<LeveledObject*> m_kLeveledObjects;
    void FUN_0042e680(unsigned char chance);
};
#endif
