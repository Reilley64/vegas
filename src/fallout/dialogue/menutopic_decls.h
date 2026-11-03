// fallout/dialogue/menutopic_decls.h: declares MiscStatManager, MenuTopicText, MenuTopicActorValueOwner, MenuTopicPlayer

#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011de000.h"
class MiscStatManager
{
  public:
    enum MiscStat
    {
        MS_COUNT = 43
    };
    static void AddMiscStat(MiscStat, int);
};

#ifndef FNV_MENUTOPIC_EXTENSIONS_H
#define FNV_MENUTOPIC_EXTENSIONS_H
class MobileObject;
class PlayerCharacter;
#include "menutopic_layout.h"
#include "menutopic_tesfullname.h"
#include "menutopic_tesobjectrefr.h"
#include "menutopic_testopic.h"
#include "menutopic_testopicinfo.h"
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class MenuTopicText
{
  public:
};
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class MenuTopicActorValueOwner
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int GetActorValue(int);
};
class MenuTopicPlayer
{
  public:
    unsigned char padding[0xa4];
    MenuTopicActorValueOwner actorValues;
};
class GlobalObject2_0040c150
{
  public:
};
#endif
