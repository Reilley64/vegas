// fallout_shared/tesweatherlist_decls.h: declares TESForm, TESGlobal, WeatherEntry, TESWeatherList, ContainerItemExtraFileData
#ifndef FNV_TESWEATHERLIST_DECLS_H
#define FNV_TESWEATHERLIST_DECLS_H


#include "fnv/decl/Callees.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00582000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "layout_support.h"

class TESFile;
class TESForm
{
  public:
    virtual void vfn_0();
};
class TESWeather;
class TESGlobal : public TESForm
{
};

class WeatherEntry
{
  public:
    TESWeather* m_weather;
    unsigned int m_uiFilterValue;
    TESGlobal* m_otherWeather;
    WeatherEntry();
};

template <> class BSSimpleList<WeatherEntry*>
{
  public:
    WeatherEntry* m_item;
    BSSimpleList<WeatherEntry*>* m_pkNext;
    void AddHead(WeatherEntry* const& item);
};

class TESWeatherList : public BSSimpleList<WeatherEntry*>
{
  public:
    void ClearWeatherSounds();
    static void LoadWeatherEntries(TESWeatherList* list, TESFile* file, TESForm* form);
};

class FUN_00582570
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    FUN_00582570();
};

class ContainerItemExtraFileData
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
};

extern "C" void* __cdecl __RTDynamicCast(void* object, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
extern "C" const char DAT_010318b4[];
extern "C" const char DAT_01031858[];
extern "C" const char DAT_0118629c[];

extern "C" const char DAT_01183ad4[];

#endif
