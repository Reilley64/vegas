
// bssystemutilities/console/bssysinfosystemutility_console.cpp: BSSysInfoSystemUtility (1 function)
#include "runtime/crt.h"
#include "fnv/symbols_011c3000.h"
struct SystemLocaleState
{
    void* vtable;
    const char* language;
};

extern unsigned int gCachedLanguage;

class BSSysInfoSystemUtility
{
  public:
    static unsigned int GetRandomGenerator(void);
};

// Returns the cached language code, detecting it once by comparing gSystemLocaleState.language against ENGLISH, FRENCH, ITALIAN, GERMAN and SPANISH.
// @fnv 0x00a22cb0
unsigned int BSSysInfoSystemUtility::GetRandomGenerator(void)
{
    if (gCachedLanguage == 0xffffffff)
    {
        const char* pEnglishName;
        if (&(*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)))
            pEnglishName = (*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)).language;
        else
            pEnglishName = 0;
        if (fnv::crt::strnicmp(pEnglishName, "ENGLISH", 7) == 0)
        {
            gCachedLanguage = 0;
        }
        else
        {
            const char* pFrenchName;
            if (&(*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)))
                pFrenchName = (*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)).language;
            else
                pFrenchName = 0;
            if (fnv::crt::strnicmp(pFrenchName, "FRENCH", 6) == 0)
            {
                gCachedLanguage = 2;
            }
            else
            {
                const char* pItalianName;
                if (&(*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)))
                    pItalianName = (*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)).language;
                else
                    pItalianName = 0;
                if (fnv::crt::strnicmp(pItalianName, "ITALIAN", 7) == 0)
                {
                    gCachedLanguage = 4;
                }
                else
                {
                    const char* pGermanName;
                    if (&(*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)))
                        pGermanName = (*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)).language;
                    else
                        pGermanName = 0;
                    if (fnv::crt::strnicmp(pGermanName, "GERMAN", 6) == 0)
                    {
                        gCachedLanguage = 1;
                    }
                    else
                    {
                        const char* pSpanishName;
                        if (&(*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)))
                            pSpanishName = (*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4)).language;
                        else
                            pSpanishName = 0;
                        if (fnv::crt::strnicmp(pSpanishName, "SPANISH", 7) == 0)
                            gCachedLanguage = 3;
                    }
                }
            }
        }
    }
    return gCachedLanguage;
}
