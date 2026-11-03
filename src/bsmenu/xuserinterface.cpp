
// src/bsmenu/xuserinterface.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/xuserinterface.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00711e00_StandIn.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MouseInputStandIn.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption,
                                                           unsigned int uType);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

struct SettingBool
{
    unsigned char* Bool();
};

struct LockObj
{
    void Lock();
    void Unlock();
};

struct SettingStr
{
};

struct Controls
{
};

struct OSGlobals
{
};

extern unsigned char DAT_011a3015;

void __cdecl FUN_0086a530();
int __cdecl FUN_0086a820();

// @fnv 0x0086a580
int FUN_0086a580(const char* text, const char* caption, unsigned int flags)
{
    int result = 6;
    {
        signed char mode;

        if (*(*reinterpret_cast<::SettingBool *>(&::g_011deb3c)).Bool())
        {
            signed char type = flags & 0xf;
            signed char ret;
            switch (type)
            {
            case 2:
                ret = 5;
                break;
            default:
                ret = 6;
                break;
            }
            return ret;
        }

        (*reinterpret_cast<::LockObj *>(&::g_timeGlobal)).Lock();
        mode = flags & 0xf;
        if (DAT_011a3015 && ::g_osGlobals && reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720())
        {
            DAT_011a3015 = 0;
            {
                signed char kind = (signed char)0xff;
            }
            int a = 0;
            const char* c = 0;
            const char* d = 0;
            const char* b = 0;

            switch (mode)
            {
            case 3:
                b = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingStr *>(&::g_011d12b4))))->GetMenuTitle()));
            case 4:
                c = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingStr *>(&::g_011d0cb4))))->GetMenuTitle()));
                d = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingStr *>(&::g_011d06f4))))->GetMenuTitle()));
                break;
            }

            if (mode == 2 || mode == 0 ||
                !((unsigned char)(::fnv_00703e80::FUN_00703e80(text, (const char *)(0), (const char *)(0), (void*)FUN_0086a530, a, FUN_0086a820(), 0.0f, 0.0f, c, d, b, 0))))
            {
                if (!FUN_00446e10() || !FUN_004dc1e0())
                {
                    if (::g_osGlobals && GetCurrentThreadId() != ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((::g_osGlobals))->FUN_0044edb0())) &&
                        reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720() && !((int)(reinterpret_cast<::FUN_00711e00_StandIn *>((reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720()))->FUN_00711e00())))
                    {
                        reinterpret_cast<::MouseInputStandIn *>((reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720()))->RecreateDevice(1);
                    }
                    result = MessageBoxA(0, text, caption, flags);
                }
                else
                {
                    switch (mode)
                    {
                    case 2:
                        result = 5;
                        break;
                    case 3:
                    case 4:
                        result = 6;
                        break;
                    }
                }
            }
            DAT_011a3015 = 1;
        }
        else
        {
            if (!FUN_00446e10() || !FUN_004dc1e0())
            {
                if (::g_osGlobals && GetCurrentThreadId() != ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((::g_osGlobals))->FUN_0044edb0())) &&
                    reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720() && !((int)(reinterpret_cast<::FUN_00711e00_StandIn *>((reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720()))->FUN_00711e00())))
                {
                    reinterpret_cast<::MouseInputStandIn *>((reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720()))->RecreateDevice(1);
                }
                result = MessageBoxA(0, text, caption, flags);
            }
        }
    }

    (*reinterpret_cast<::LockObj *>(&::g_timeGlobal)).Unlock();
    return result;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

struct GameTimerRecord
{
    unsigned char m_ucFirstTimerByte;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned int m_uiFirstTimerValue;
    unsigned int m_uiSecondTimerValue;

    void FUN_00aa50a0();
};

// When m_ucFirstTimerByte is zero before incrementing, subtracts both stored values from GetTickCount() and stores the results.
// @fnv 0x00aa50a0
void GameTimerRecord::FUN_00aa50a0()
{
    if (m_ucFirstTimerByte++ == 0)
    {
        unsigned int uiTickCount = GetTickCount();
        m_uiFirstTimerValue = uiTickCount - m_uiFirstTimerValue;
        m_uiSecondTimerValue = uiTickCount - m_uiSecondTimerValue;
    }
}
