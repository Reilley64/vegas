// fallout_shared/tesweatherlist.cpp: TESWeatherList, WeatherEntry (10 functions)

#include <new>
#include <cstring>
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00582000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "tesweatherlist_decls.h"

// Deletes each WeatherEntry in the list, then calls RemoveAll to clear the list.
// @fnv 0x00582780
void TESWeatherList::ClearWeatherSounds()
{
    BSSimpleList<WeatherEntry*>* current = this;
    while (current)
    {
        WeatherEntry* item = (current->m_item);
        ::FUN_00401030(item);
        current = ((::BSSimpleList< ::WeatherEntry *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>(this)->RemoveAll();
}

// @fnv 0x00824340
WeatherEntry::WeatherEntry()
{
    m_weather = 0;
    m_uiFilterValue = 0;
    m_otherWeather = 0;
}

// Reads weather entries from the file chunk, resolves each weather and global form, adds them to the list, sorts it, and warns on failures.
// @fnv 0x00582940
void TESWeatherList::LoadWeatherEntries(TESWeatherList* list, TESFile* file, TESForm* form)
{
    if (!file || !list || !form)
        return;
    unsigned int count = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() / 12;
    if (count > 0)
    {
        list->ClearWeatherSounds();
        FUN_00582570* pEntries = new FUN_00582570[count];
        if (!reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEntries), count * 12))
            ::FUN_005b5e40();
        for (unsigned int i = 0; i < count; i++)
        {
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::Class005a6b10 *>((((ContainerItemExtraFileData*)&pEntries[i])))->FUN_005a6b10();
            ::ResolveFormID((unsigned int *)&(pEntries[i].m_unk00), file);
            list->AddHead(new WeatherEntry);
            if (!(((::WeatherEntry *)((void *)(list)))->m_weather =
                      (TESWeather*)__RTDynamicCast(::FUN_004839c0(pEntries[i].m_unk00), 0,
                                                   (void*)(*reinterpret_cast<const char (*)[]>(&::DAT_01183028)), (void*)DAT_0118629c, 0)))
                ::FUN_005b5e40();
            ((::WeatherEntry *)((void *)(list)))->m_uiFilterValue = pEntries[i].m_unk04;
            ::ResolveFormID((unsigned int *)&(pEntries[i].m_unk08), file);
            ((::WeatherEntry *)((void *)(list)))->m_otherWeather =
                dynamic_cast<TESGlobal*>(::FUN_004839c0(pEntries[i].m_unk08));
        }
        reinterpret_cast<::ItemChangeList *>((list))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(((int (&)(WeatherEntry *, WeatherEntry *))::CompareSecondElement)));
        delete[] pEntries;
    }
}

struct ListX
{
    void* m_item;
    ListX* m_next;
    ~ListX();
};
struct FUN_00582320 : ListX
{
    ~FUN_00582320();
};
// @fnv 0x00582320
FUN_00582320::~FUN_00582320()
{
    ((TESWeatherList*)this)->ClearWeatherSounds();
}

struct FUN_00582570_Data
{
    int unk0;
    int unk1;
    int unk2;
    FUN_00582570_Data* FUN_00582570();
};
// Sets the three integer fields to zero and returns this.
// @fnv 0x00582570
FUN_00582570_Data* FUN_00582570_Data::FUN_00582570()
{
    unk2 = 0;
    unk1 = 0;
    unk0 = 0;
    return this;
}

struct TESGlobalValueReader
{
};
struct FUN_005827d0_list : public BSSimpleList<WeatherEntry*>
{
    TESWeather* FUN_005827d0();
};
struct FUN_005827d0_node
{
};

// @fnv 0x005827d0
TESWeather* FUN_005827d0_list::FUN_005827d0()
{
    BSSimpleList<WeatherEntry*>* pCurrent7;
    {
        unsigned int uiTotalChance5 = 0;
        pCurrent7 = this;
        while (pCurrent7)
        {
            if (((::WeatherEntry *)((void *)(((FUN_005827d0_node*)pCurrent7)))))
            {
                if (((::WeatherEntry *)((void *)(((FUN_005827d0_node*)pCurrent7))))->m_otherWeather)
                    uiTotalChance5 += (unsigned int)reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)((::WeatherEntry *)((void *)(((FUN_005827d0_node*)pCurrent7))))
                                                         ->m_otherWeather)))->FUN_00526ac0();
                else
                    uiTotalChance5 += ((::WeatherEntry *)((void *)(((FUN_005827d0_node*)pCurrent7))))->m_uiFilterValue;
            }
            pCurrent7 = ((::BSSimpleList< ::WeatherEntry *> *)(reinterpret_cast<::Callees *>((pCurrent7))->FUN_00726070()));
        }
        if (uiTotalChance5)
        {
            unsigned int uiLower;
            unsigned int uiUpper;
            WeatherEntry* pEntry;
            BSSimpleList<WeatherEntry*>* pIter4;
            unsigned int uiRollB;
            uiRollB = DialogueRandom() % uiTotalChance5;
            uiLower = 0;
            uiUpper = 0xFFFFFFFF;
            pEntry = 0;
            pIter4 = this;
            while (pIter4)
            {
                pEntry = ((::WeatherEntry *)((void *)(((FUN_005827d0_node*)pIter4))));
                if (pEntry)
                {
                    unsigned int m_uiWeatherChance =
                        pEntry->m_otherWeather
                            ? (unsigned int)reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)pEntry->m_otherWeather)))->FUN_00526ac0()
                            : pEntry->m_uiFilterValue;
                    if (m_uiWeatherChance)
                    {
                        uiUpper += m_uiWeatherChance;
                        if (uiLower <= uiRollB && uiRollB <= uiUpper)
                            break;
                        uiLower += m_uiWeatherChance;
                    }
                }
                pIter4 = ((::BSSimpleList< ::WeatherEntry *> *)(reinterpret_cast<::Callees *>((pIter4))->FUN_00726070()));
            }
            if (pEntry)
                return pEntry->m_weather;
        }
    }
    return 0;
}

struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_005827d0_shell
{
    bool FUN_005827d0();
};
struct FUN_005825a0_shell : public TESWeatherList
{
    void CopyWeatherList(const TESWeatherList* apCopyWL, bool abAppend);
};
// @fnv 0x005825a0
void FUN_005825a0_shell::CopyWeatherList(const TESWeatherList* apCopyWL, bool abAppend)
{
    if (!apCopyWL)
        return;
    if (!abAppend)
        ClearWeatherSounds();
    if (!((FUN_005827d0_shell*)apCopyWL)->FUN_005827d0())
    {
        BSSimpleList<WeatherEntry*>* pSourceNode = (BSSimpleList<WeatherEntry*>*)apCopyWL;
        while (pSourceNode)
        {
            WeatherEntry* pNewEntry = new WeatherEntry;
            __memcpy((char*)pNewEntry, (char*)(pSourceNode->m_item), sizeof(WeatherEntry));
            reinterpret_cast<::Callees *>((((SoundListView*)this)))->FUN_00905820((void *)&((char* const&)pNewEntry));
            pSourceNode = ((::BSSimpleList< ::WeatherEntry *> *)(reinterpret_cast<::Callees *>((pSourceNode))->FUN_00726070()));
        }
    }
}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};

bool _ref_008256d0(void* pObject);

struct FUN_00582690_shell : public TESWeatherList
{
    bool IsDifferentFrom(TESWeatherList* apCompareWL);
};

// Compares this weather list against another: returns true if the other is null, sizes differ, or any entry has no matching 12-byte-equal entry.
// @fnv 0x00582690
bool FUN_00582690_shell::IsDifferentFrom(TESWeatherList* apCompareWL)
{
    BSSimpleList<WeatherEntry*>* pThisNode;
    bool bFound;
    BSSimpleList<WeatherEntry*>* pCompNode;

    if (apCompareWL == 0)
    {
        return true;
        goto L_end;
    }

    if (_ref_008256d0(this) && _ref_008256d0(apCompareWL))
    {
        return false;
        goto L_end;
    }

    if (reinterpret_cast<BSSimpleListTESRaceSize*>(this)->GetSize() !=
        reinterpret_cast<BSSimpleListTESRaceSize*>(apCompareWL)->GetSize())
    {
        return true;
        goto L_end;
    }

    for (pThisNode = this; pThisNode != 0; pThisNode = ((::BSSimpleList< ::WeatherEntry *> *)(reinterpret_cast<::Callees *>((pThisNode))->FUN_00726070())))
    {
        bFound = false;

        for (pCompNode = apCompareWL; !bFound && pCompNode != 0; pCompNode = ((::BSSimpleList< ::WeatherEntry *> *)(reinterpret_cast<::Callees *>((pCompNode))->FUN_00726070())))
        {
            bFound = (std::memcmp((pThisNode->m_item), (pCompNode->m_item), 0xc) == 0);
        }

        if (!bFound)
            return true;
    }

    return false;

L_end:;
}

class SrcListBase_b6402
{
  public:
    virtual ~SrcListBase_b6402();
    unsigned int m_04;
    SrcListBase_b6402(class SrcRecord_b6402* aSrc);
};

class SrcListItem_b6402
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    SrcListItem_b6402();
    ~SrcListItem_b6402();
};

class SrcRecord_b6402
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    unsigned int m_04;
    SrcListItem_b6402 m_08;
};

class FUN_004f5140 : public SrcListBase_b6402
{
  public:
    virtual ~FUN_004f5140();
    SrcListItem_b6402 m_08;

    FUN_004f5140(SrcRecord_b6402* aSrc);
};

// Constructs a list copy from a source record, copying its item list without appending.
// @fnv 0x004f5140
FUN_004f5140::FUN_004f5140(SrcRecord_b6402* aSrc) : SrcListBase_b6402(aSrc)
{
    reinterpret_cast<::FUN_005825a0_shell *>(&(m_08))->CopyWeatherList((const ::TESWeatherList *)(const ::SrcListItem_b6402 *)(&aSrc->m_08), false);
}

struct WeatherSaveEntry
{
    unsigned int m_weatherID;
    unsigned int m_uiFilterValue;
    unsigned int m_globalID;
    WeatherSaveEntry();
};


struct FUN_00582380_shell : public TESWeatherList
{
    int GetSize();
    void WriteWeatherList(void* apDest);
};

// Builds a WeatherSaveEntry array from the list's weather entries, endian-swaps if needed, writes it to apDest, then swaps back and frees it.
// @fnv 0x00582380
void FUN_00582380_shell::WriteWeatherList(void* apDest)
{
    unsigned int ItemUpdateArray = GetSize();
    if (ItemUpdateArray > 0)
    {
        WeatherSaveEntry* pEntries = new WeatherSaveEntry[ItemUpdateArray];
        ItemUpdateArray = 0;
        BSSimpleList<WeatherEntry*>* pNode = this;
        while (pNode)
        {
            pEntries[ItemUpdateArray].m_weatherID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)(pNode->m_item)->m_weather)))->FUN_0084e3a0()));
            pEntries[ItemUpdateArray].m_uiFilterValue = (pNode->m_item)->m_uiFilterValue;
            pEntries[ItemUpdateArray].m_globalID =
                (pNode->m_item)->m_otherWeather ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((pNode->m_item)->m_otherWeather))->FUN_0084e3a0())) : 0;
            ItemUpdateArray++;
            pNode = ((::BSSimpleList< ::WeatherEntry *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                reinterpret_cast<::Class005a6b10 *>(&(pEntries[i]))->FUN_005a6b10();
        }
        ::AppendChunk((unsigned int)(apDest), pEntries, ItemUpdateArray * sizeof(WeatherSaveEntry));
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int j = 0; j < ItemUpdateArray; j++)
                reinterpret_cast<::Class005a6b10 *>(&(pEntries[j]))->FUN_005a6b10();
        }
        delete[] pEntries;
    }
}
