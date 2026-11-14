// fallout_shared/region system/tesregiondataweather_decls.h: declares TESRegion, TESWeatherList, TESRegionDataWeather
#ifndef TESREGIONDATAWEATHER_DECLS_H
#define TESREGIONDATAWEATHER_DECLS_H

#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_005b5000.h"
#include "TESForm.h"
class TESRegion : public TESForm
{
};
class TESWeatherList
{
  public:
    void* entries[2];
    static void LoadWeatherEntries(TESWeatherList*, TESFile*, TESForm*);
};
class TESRegionDataWeather
{
  public:
    unsigned char base[8];
    TESWeatherList weatherList;
    void LoadWeatherData(TESFile*, TESRegion*);
};
#endif
