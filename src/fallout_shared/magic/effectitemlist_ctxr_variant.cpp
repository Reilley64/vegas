
// effectitemlist_ctxr_variant.cpp: rename variant for 0x00405760 (integration 2026-10-30): the unit's skeleton with Str renamed, whose names are bound elsewhere.
#include "fnv/decl/EffectItem.h"
#include "fnv/decl/EffectItemList.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/S3c60.h"
#include "fnv/decl/TESFile.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "effectitemlist.h"
ActorPathHandler::PATH_HANDLER_RESULT CallNoPathUpdate(ActorPathHandler* pHandler, float fSeconds)
{
    return pHandler->CompleteNoPathUpdate(fSeconds);
}

extern "C" char DAT_011837c4, DAT_01183028, DAT_010120d8, DAT_010125c0, DAT_01012578, DAT_01012520, DAT_011c33d4;
struct File
{
    void ReadChunkInt(unsigned*);
};
struct Str_r00405760
{
    char data[8];
    ~Str_r00405760();
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class EffectSetting : public TESForm
{
  public:
};
struct Item
{
    char data[36];
    Item(EffectSetting*);
    ~Item();
};
void* __cdecl operator new(unsigned);
void __cdecl operator delete(void*);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct List
{
    int pad[3];
    int count;
    void FUN_00405760(File*, const char*);
};
// @fnv 0x00405760
void List::FUN_00405760(File* file, const char* name)
{
    unsigned id;
    EffectSetting* effect;
    Item* actorValue;
    int item;
    switch (reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())
    {
    case 0x44494645:
        file->ReadChunkInt(&id);
        ::ResolveFormID(&id, (::TESFile *)(file));
        effect = dynamic_cast<EffectSetting*>(FUN_004839c0(id));
        if (effect)
        {
            actorValue = new Item(effect);
            reinterpret_cast<::TESFile *>((file))->NextChunk();
            if (reinterpret_cast<::S3c60 *>((effect))->HasFlag2() && ((int)(reinterpret_cast<::InterfaceManager *>((effect))->FUN_00586150())) == 0x36)
                item = 0;
            if (reinterpret_cast<::EffectItem *>((actorValue))->Load((::TESFile *)(file), name))
                reinterpret_cast<::EffectItemList *>(this)->AddItem((::EffectItem *)(actorValue));
            else
            {
                ::FUN_005b5e40();
                delete actorValue;
                actorValue = 0;
            }
            *(Item**)&DAT_011c33d4 = actorValue;
        }
        else
            ::FUN_005b5e40();
        break;
    case 0x41445443:
        if (*(Item**)&DAT_011c33d4)
        {
            reinterpret_cast<::EffectItem *>(((*(Item**)&DAT_011c33d4)))->Load((::TESFile *)(file), name);
            if (reinterpret_cast<::EffectItem *>(((*(Item**)&DAT_011c33d4)))->IsHostile())
                count++;
        }
        else
            ::FUN_005b5e40();
        break;
    }
}

#include "generated/data/fallout_shared/magic/effectitemlist_ctxr_variant.inc"
