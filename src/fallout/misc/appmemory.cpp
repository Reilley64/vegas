
// src/fallout/misc/appmemory.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/appmemory.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/BSFaceGenManager.h"
#include "fnv/decl/CellBufferManager.h"
#include "fnv/decl/FUN_004539a0_cls.h"
#include "fnv/decl/FUN_00529ea0_shell.h"
#include "fnv/decl/FUN_0078d200_cls.h"
#include "fnv/decl/FUN_00866dc0_Class.h"
#include "fnv/decl/FUN_00866de0_cls.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/FUN_00aa5c80_shell.h"
#include "fnv/decl/FaceGenModelCache650.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/fnv_00452490__FUN_00452490_shell.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00868000.h"
#include "fnv/symbols_00869000.h"
#include "fnv/symbols_00aa7000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_01202000.h"
unsigned int gm_GetCurrentThreadId();
struct OSGlobals
{
};
struct TES
{
};
extern unsigned int DAT_011de70c;
struct ScrapHeapManager
{
    static ScrapHeapManager& Instance();
};
struct Worker
{
};
int FUN_00652130();
struct RecursiveSpinLock
{
    void FUN_0040fba0();
};
struct IOManager
{
    unsigned int CallSlotMethod(int);
};
struct StateMachine
{
    int unknown000;
    int unknown004;
    int unknown008;
    int unknown00c;
    int unknown010;
    int unknown014;
    int unknown018;
    int unknown01c;
    int unknown020;
    int unknown024;
    int unknown028;
    int unknown02c;
    int unknown030;
    int unknown034;
    int unknown038;
    int unknown03c;
    int unknown040;
    int unknown044;
    int unknown048;
    int unknown04c;
    int unknown050;
    int unknown054;
    int unknown058;
    int unknown05c;
    int unknown060;
    int unknown064;
    int unknown068;
    int unknown06c;
    int unknown070;
    int unknown074;
    int unknown078;
    int unknown07c;
    int unknown080;
    int unknown084;
    int unknown088;
    int unknown08c;
    int unknown090;
    int unknown094;
    int unknown098;
    int unknown09c;
    int unknown0a0;
    int unknown0a4;
    int unknown0a8;
    int unknown0ac;
    int unknown0b0;
    int unknown0b4;
    int unknown0b8;
    int unknown0bc;
    int unknown0c0;
    int unknown0c4;
    int unknown0c8;
    int unknown0cc;
    int unknown0d0;
    int unknown0d4;
    int unknown0d8;
    int unknown0dc;
    int unknown0e0;
    int unknown0e4;
    int unknown0e8;
    int unknown0ec;
    int unknown0f0;
    int unknown0f4;
    int unknown0f8;
    int unknown0fc;
    int unknown100;
    int unknown104;
    int unknown108;
    int unknown10c;
    int unknown110;
    int unknown114;
    int unknown118;
    int unknown11c;
    int unknown120;
    int unknown124;
    int unknown128;
    int unknown12c;
    int unknown130;
    int state;
    int RunStep(void*, unsigned int, bool*);
};
// Runs one step of the state machine by index, setting *finished and returning the next step index.
// @fnv 0x00866a90
int StateMachine::RunStep(void* context, unsigned int step, bool* finished)
{
    *finished = true;
    bool mainThread = gm_GetCurrentThreadId() == ((uintptr_t)(reinterpret_cast<::MagicCaster_shell *>((::g_osGlobals))->FUN_0044edb0()));
    switch (step)
    {
    case 0:
        DAT_011de70c = 0;
        if (mainThread)
            reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00452490(0);
        break;
    case 1:
        reinterpret_cast<::FUN_00aa5c80_shell *>(&(ScrapHeapManager::Instance()))->FUN_00aa5c80();
        break;
    case 2:
        if (((::Worker *)(::BSFaceGenManager::GetModelMap())) && ((bool)(reinterpret_cast<::FUN_00529ea0_shell *>((((::Worker *)(::BSFaceGenManager::GetModelMap()))))->FUN_00529ea0())) && ::fnv_00652160::FUN_00652160())
        {
            if (FUN_00652130() == 1)
                reinterpret_cast<::FaceGenModelCache650 *>((((::Worker *)(::BSFaceGenManager::GetModelMap()))))->PurgeUnusedModels(0);
            ::fnv_00652190::FUN_00652190();
        }
        break;
    case 5:
        if (mainThread)
        {
            ::SetTlsFlag(0);
            if (reinterpret_cast<::CellBufferManager *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00453a80())
                step = step - 1;
            else
                reinterpret_cast<::FUN_004539a0_cls *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_004539a0(1, 0);
            reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00452490(0);
            ::SetTlsFlag(1);
            ::FUN_00868d70(1);
        }
        else
            break;
    case 4:
        if (reinterpret_cast<::FUN_0078d200_cls *>(&(::DAT_011f11a0))->FUN_0078d200())
        {
            ::FUN_00868d70(1);
            ::DAT_011f11a0.FUN_0040fba0();
        }
    case 3:
        ::FUN_00c459d0(1);
        break;
    case 6:
        if (mainThread)
            FUN_00aa7030();
        break;
    case 7:
        if (!*finished && mainThread)
        {
            *finished = true;
            break;
        }
    case 8:
        if (!mainThread)
        {
            state = 6;
            if (DAT_011de70c < 15000)
            {
                if (DAT_01202d98->CallSlotMethod(0) == gm_GetCurrentThreadId())
                {
                    reinterpret_cast<::FUN_00866dc0_Class *>((DAT_01202d98))->FUN_00866dc0(0);
                    reinterpret_cast<::FUN_00866de0_cls *>((DAT_01202d98))->CallElementAt(0);
                }
                if (DAT_01202d98->CallSlotMethod(1) == gm_GetCurrentThreadId())
                {
                    reinterpret_cast<::FUN_00866dc0_Class *>((DAT_01202d98))->FUN_00866dc0(1);
                    reinterpret_cast<::FUN_00866de0_cls *>((DAT_01202d98))->CallElementAt(1);
                }
                FUN_0040fca0(1);
                DAT_011de70c = DAT_011de70c + 1;
                step = step - 1;
                break;
            }
            else if (!*finished)
                *finished = true;
        }
        break;
    }
    return step + 1;
}

#include "generated/data/fallout/misc/appmemory.inc"
