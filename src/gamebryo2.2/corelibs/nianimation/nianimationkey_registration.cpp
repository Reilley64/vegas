#include "NiAnimationKeyTables.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a27000.h"
#include "fnv/symbols_00a28000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a2a000.h"
#include "fnv/symbols_00a2b000.h"
#include "fnv/symbols_00a2c000.h"
#include "fnv/symbols_00a2d000.h"
#include "fnv/symbols_00e7c000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010a5000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f8000.h"
#include "fnv/symbols_01203000.h"

extern char DAT_011f3668;
void __cdecl FUN_00a28620(int, int);
// @fnv 0x00a28680
int __cdecl FUN_00a28680()
{
    if (DAT_011f3668)
        return 0;
    DAT_011f3668 = 1;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(1, 2), ((void (&)())::LoadBezPosKeys));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(1, 2), ((void (&)())::SaveKeyArray));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(1, 2), ((void (&)())::FUN_00a27b60));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(1, 2), ((void (&)())::AllocateElem64Array));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(1, 2), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(1, 2)] = 0x40;
    FUN_00a28620(1, 2);
    return 1;
}

extern unsigned char DAT_011f3693;

// @fnv 0x00a2aab0
int __cdecl FUN_00a2aab0()
{
    if (DAT_011f3693)
        return 0;
    DAT_011f3693 = 1;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(1, 1), ((void (&)())::CreateVertexRecords));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(1, 1), ((void (&)())::FUN_00a2d470));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(1, 1), ((void (&)())::FUN_00a2a7b0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(1, 1), ((void (&)())::AllocateTempArray));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(1, 1), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(1, 1)] = 0x10;
    ::fnv_00a2aa50::FUN_00a2aa50(1, 1);
    return 1;
}

namespace fnv_00a2bb90 {
extern unsigned char DAT_011f3695;

// @fnv 0x00a2bb90
int __cdecl FUN_00a2bb90()
{
    if (DAT_011f3695)
        return 0;
    DAT_011f3695 = 1;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(1, 3), &((void (&)())::fnv_00a2bb00::AllocateElement76Array));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(1, 3), &((void (&)())::FUN_00a2bb60));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(1, 3), &((void (&)())::CopyFloatBlock));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(1, 3), &((void (&)())::AllocateBezierKeys));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(1, 3), &((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(1, 3)] = 0x4c;
    ::FUN_00a2baa0(1, 3);
    return 1;
}
}  // namespace fnv_00a2bb90

typedef void(__cdecl* FUN_00a28cb0_KeyFn)();

extern bool FUN_00a28cb0_bRegistered;


// @fnv 0x00a28cb0
int __cdecl FUN_00a28cb0()
{
    if (FUN_00a28cb0_bRegistered)
        return 0;

    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(2, 0)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(2, 0)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(2, 0)] = nullptr;
    FUN_00a28cb0_bRegistered = true;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(2, 0), ((void (&)())::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(2, 0), ::FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(2, 0), ::FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(2, 0), ((void (&)())::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(2, 0), ::FUN_00a29680);
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(2, 0)] = 20;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3810][NiAnimationKeyTables::Index(2, 0)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(2, 0), ((void (&)())::FUN_00a286e0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(2, 0), ((void (&)())::FUN_00a28a80));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(2, 0), ((void (&)())::FUN_00a28ab0));
    return 1;
}

typedef void(__cdecl* S_00a29110_Fn)();
extern char DAT_011f367c;
// @fnv 0x00a29110
int FUN_00a29110()
{
    if (DAT_011f367c)
        return 0;
    DAT_011f367c = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(2, 2)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(2, 2)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(2, 2)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(2, 2), ((void (&)())::FUN_00a290a0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(2, 2), ((void (&)())::fnv_00a28ed0::FUN_00a28ed0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(2, 2), ((void (&)())::CopyBlk36));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(2, 2), ((void (&)())::FUN_00a28f00));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(2, 2), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(2, 2)] = 0x24;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(2, 2), ((void (&)())::CallSpawnTarget));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(2, 2), ((void (&)())::CompareBounds));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(2, 2), ((void (&)())::FUN_00a28dc0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(2, 2), ((void (&)())::FUN_00a28f50));
    return 1;
}

extern unsigned char DAT_011f3655;


// @fnv 0x00a273a0
int __cdecl FUN_00a273a0()
{
    if (DAT_011f3655 != 0)
    {
        return 0;
    }
    DAT_011f3655 = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(0, 2)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(0, 2)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(0, 2)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(0, 2), ((void (&)())::LoadFloatKeys));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(0, 2), ((void (&)())::sa27320::SaveKeys));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(0, 2), ((void (&)())::FUN_00a26f80));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(0, 2), ((void (&)())::AllocateTempArray));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(0, 2), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(0, 2)] = 0x10;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(0, 2), ((void (&)())::FUN_00a26fe0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(0, 2), ((void (&)())::FUN_00a26f30));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(0, 2), FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(0, 2), ((void (&)())::FUN_00a27080));
    return 1;
}

extern char DAT_011f3656;


void __cdecl FUN_00a27aa0(int, int);

// @fnv 0x00a27b00
int FUN_00a27b00()
{
    if (DAT_011f3656)
        return 0;
    DAT_011f3656 = 1;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(1, 0), ((void (&)())::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(1, 0), ::FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(1, 0), ::FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(1, 0), ((void (&)())::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(1, 0), ::FUN_00a29680);
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(1, 0)] = 0x10;
    FUN_00a27aa0(1, 0);
    return 1;
}

typedef void(__cdecl* S_00a294f0_Fn)();

extern char DAT_011f367e;

// The original installs one handler address into several slots, and the
// compiler duplicated that constant at every slot, so each slot below
// takes its own alias of the handler it stores.
void __cdecl RegisterCurveOps(int, int);

// @fnv 0x00a294f0
int FUN_00a294f0()
{
    if (DAT_011f367e)
        return 0;
    DAT_011f367e = 1;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(5, 0), &((void (&)())::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(5, 0), &FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(5, 0), &::FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(5, 0), &((void (&)())::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(5, 0), &::FUN_00a29680);
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(5, 0)] = 8;
    RegisterCurveOps(5, 0);
    return 1;
}


typedef void(__cdecl* A2AD80Callback)();

extern bool g_A2AD80Initialized;

// @fnv 0x00a2ad80
int __cdecl FUN_00a2ad80()
{
    if (g_A2AD80Initialized)
        return 0;
    g_A2AD80Initialized = true;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(2, 1)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(2, 1)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(2, 1)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2abc0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(2, 1), ((void (&)())::fnv_00a2d690::FUN_00a2d690));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2ab10));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2ab40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(2, 1)] = 0x14;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2ab90));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2d680));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2d670));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(2, 1), ((void (&)())::FUN_00a2ac30));
    return 1;
}

typedef void(__cdecl* RuntimeCallback)();

extern unsigned char DAT_011f3696;


// @fnv 0x00a2c4c0
int __cdecl FUN_00a2c4c0()
{
    if (DAT_011f3696 != 0)
        return 0;

    DAT_011f3696 = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(2, 3)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(2, 3)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(2, 3)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(2, 3), ((void (&)())::fnv_00a2c420::FUN_00a2c420));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(2, 3), ((void (&)())::FUN_00a2c490));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(2, 3), ((void (&)())::FUN_00a2bbf0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(2, 3), ((void (&)())::FUN_00a2be60));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(2, 3), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(2, 3)] = 0x40;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(2, 3), ((void (&)())::fnv_00a2bc60::InvokeSpawnTarget));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(2, 3), ((void (&)())::BezRotKeyEqual));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(2, 3), ((void (&)())::FUN_00a2c130));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(2, 3), ((void (&)())::FUN_00a2c1b0));
    return 1;
}

extern unsigned char DAT_011f3697;

// @fnv 0x00a2cb80
int __cdecl FUN_00a2cb80()
{
    if (DAT_011f3697 != 0)
    {
        return 0;
    }
    DAT_011f3697 = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(0, 3)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(0, 3)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(0, 3)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(0, 3), ((void (&)())::AllocateKeyframeElements));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(0, 3), ((void (&)())::FUN_00a2cb50));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(0, 3), ((void (&)())::CopyFloat7));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(0, 3), ((void (&)())::fnv_00a2c660::AllocateElem28Array));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(0, 3), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(0, 3)] = 0x1c;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(0, 3), ((void (&)())::FUN_00a2c610));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(0, 3), ((void (&)())::FUN_00a2c550));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(0, 3), ((void (&)())::FUN_00a2c7a0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(0, 3), ((void (&)())::FUN_00a2c890));
    return 1;
}

extern unsigned char DAT_011f3698;

// @fnv 0x00a2ce20
int __cdecl FUN_00a2ce20()
{
    if (DAT_011f3698 != 0)
    {
        return 0;
    }
    DAT_011f3698 = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(5, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(5, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(5, 5)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(5, 5), ((void (&)())::fnv_00a2cdc0::FUN_00a2cdc0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(5, 5), ((void (&)())::FUN_00a2cc60));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(5, 5), ((void (&)())::FUN_00a2cc10));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(5, 5), ((void (&)())::AllocateArr8Array));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(5, 5), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(5, 5)] = 8;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(5, 5), ((void (&)())::SelectByteByThreshold));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(5, 5), ((void (&)())::FUN_00a2cc30));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(5, 5), FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(5, 5), ((void (&)())::FUN_00a2ccd0));
    return 1;
}

typedef void(__cdecl* RuntimeCallbackFn)();

extern char DAT_011f3699;


// @fnv 0x00a2d140
int FUN_00a2d140()
{
    if (DAT_011f3699 != 0)
        return 0;
    *(volatile char*)&DAT_011f3699 = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(3, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(3, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(3, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3780][NiAnimationKeyTables::Index(3, 5)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(3, 5), ((void (&)())::FUN_00a2cf60));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(3, 5), ((void (&)())::FUN_00a2cfd0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(3, 5), ((void (&)())::FUN_00a2ab10));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(3, 5), ((void (&)())::FUN_00a2ced0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(3, 5), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(3, 5)] = 0x14;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(3, 5), ((void (&)())::SelectPayloadByThreshold));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(3, 5), ((void (&)())::FUN_00a2a1a0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(3, 5), ((void (&)())::fnv_00a2d000::FUN_00a2d000));
    return 1;
}

extern unsigned char DAT_011f369c;


// @fnv 0x00a2d810
int __cdecl FUN_00a2d810()
{
    if (DAT_011f369c != 0)
    {
        return 0;
    }
    DAT_011f369c = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(2, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(2, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(2, 5)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(2, 5), ((void (&)())::FUN_00a2abc0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(2, 5), ((void (&)())::fnv_00a2d690::FUN_00a2d690));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(2, 5), ((void (&)())::FUN_00a2ab10));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(2, 5), ((void (&)())::FUN_00a2ab40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(2, 5), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(2, 5)] = 0x14;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(2, 5), ((void (&)())::SelectPayloadByThreshold));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(2, 5), ((void (&)())::FUN_00a2d680));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(2, 5), ((void (&)())::FUN_00a2d670));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(2, 5), ((void (&)())::FUN_00a2d6c0));
    return 1;
}

typedef void(__cdecl* S_00a2d360_Fn)();

extern char DAT_011f369a;


// @fnv 0x00a2d360
int __cdecl FUN_00a2d360()
{
    if (DAT_011f369a)
        return 0;

    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(0, 5)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(0, 5)] = nullptr;
    DAT_011f369a = 1;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(0, 5)] = nullptr;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(0, 5), ((void (&)())::fnv_00a2a5a0::CreateInitializedElems));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(0, 5), ((void (&)())::FUN_00a2d230));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(0, 5), ((void (&)())::CopyFloat2));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(0, 5), ((void (&)())::AllocateArr8Array));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(0, 5), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(0, 5)] = 8;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(0, 5), ((void (&)())::FUN_00a2d200));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(0, 5), ((void (&)())::fnv_00a2d1d0::FUN_00a2d1d0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(0, 5), FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(0, 5), ((void (&)())::fnv_00a2d260::InsertKeyPair));
    return 1;
}

#include <string.h>
struct CallbackTypeA;
struct CallbackTypeB;
struct CallbackTypeC;
struct CallbackTypeD;
struct ColorAnimationKey;

extern unsigned char DAT_011f367f;
extern int* CopyGlobalsToBuffer(int, int, int, int*);

// @fnv 0x00a299f0
int FUN_00a299f0()
{
    if (DAT_011f367f != 0)
        return 0;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(3, 0)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(3, 0)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(3, 0)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3780][NiAnimationKeyTables::Index(3, 0)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3810][NiAnimationKeyTables::Index(3, 0)] = nullptr;
    memset(&DAT_011f367f, 1, 1);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(3, 0), &((void (&)(CallbackTypeA *))::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(3, 0), &((void (&)(CallbackTypeA *))::FUN_00a29680));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(3, 0), &((void (&)(CallbackTypeB *))::FUN_00a29680));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(3, 0), &((void (&)(CallbackTypeB *))::FUN_00e7cd40));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(3, 0), &((void (&)(ColorAnimationKey *))::FUN_00a29680));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(3, 0)] = 0x14;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(3, 0), &CopyGlobalsToBuffer);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(3, 0), &CompareHelpers);
    return 1;
}

extern unsigned char DAT_011f3690;
// @fnv 0x00a2a110
int __cdecl FUN_00a2a110()
{
    if (DAT_011f3690)
        return 0;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(2, 4)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(2, 4)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(2, 4)] = nullptr;
    memset(&DAT_011f3690, 1, 1);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(2, 4), &((void (&)())::FUN_00a2a070));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(2, 4), &((void (&)())::FUN_00a2a0e0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(2, 4), &((void (&)())::CopyKeyData));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(2, 4), &((void (&)())::FUN_00a29db0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(2, 4), &((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(2, 4)] = 0x48;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(2, 4), &((void (&)())::FUN_00a29b10));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(2, 4), &((void (&)())::FUN_00a29c20));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(2, 4), &((void (&)())::fnv_00a29e00::DispatchEntryCallbacks));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(2, 4), &((void (&)())::UpdateArrayElements));
    return 1;
}

extern unsigned char DAT_011f3691;
// @fnv 0x00a2a4d0
int __cdecl FUN_00a2a4d0()
{
    if (DAT_011f3691 != 0)
        return 0;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(3, 1)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(3, 1)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(3, 1)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3780][NiAnimationKeyTables::Index(3, 1)] = nullptr;
    memset(&DAT_011f3691, 1, 1);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(3, 1), &((void (&)())::FUN_00a2a320));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(3, 1), &((void (&)())::FUN_00a2cfd0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(3, 1), &((void (&)())::FUN_00a2ab10));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(3, 1), &((void (&)())::FUN_00a2a1b0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(3, 1), &((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(3, 1)] = 0x14;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(3, 1), &((void (&)())::InterpolateQuaternion));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(3, 1), &((void (&)())::FUN_00a2a1a0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(3, 1), &((void (&)())::FUN_00a2a390));
    return 1;
}

extern unsigned char DAT_011f3692;
// @fnv 0x00a2a720
int FUN_00a2a720()
{
    if (DAT_011f3692)
        return 0;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3d20][NiAnimationKeyTables::Index(0, 1)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3c00][NiAnimationKeyTables::Index(0, 1)] = nullptr;
    NiAnimationKeyTables::g_functions[NiAnimationKeyTables::kAt011f3b70][NiAnimationKeyTables::Index(0, 1)] = nullptr;
    memset(&DAT_011f3692, 1, 1);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3db0, NiAnimationKeyTables::Index(0, 1), ((void (&)())::fnv_00a2a5a0::CreateInitializedElems));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3a50, NiAnimationKeyTables::Index(0, 1), ((void (&)())::FUN_00a2d230));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f39c0, NiAnimationKeyTables::Index(0, 1), ((void (&)())::CopyFloat2));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3930, NiAnimationKeyTables::Index(0, 1), ((void (&)())::AllocateArr8Array));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f38a0, NiAnimationKeyTables::Index(0, 1), ((void (&)())::FUN_00a2a600));
    NiAnimationKeyTables::g_keySizes[NiAnimationKeyTables::Index(0, 1)] = 8;
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3c90, NiAnimationKeyTables::Index(0, 1), ((void (&)())::FUN_00a2a560));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3ae0, NiAnimationKeyTables::Index(0, 1), ((void (&)())::fnv_00a2d1d0::FUN_00a2d1d0));
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3780, NiAnimationKeyTables::Index(0, 1), FUN_00a29680);
    NiAnimationKeyTables::Set(NiAnimationKeyTables::kAt011f3810, NiAnimationKeyTables::Index(0, 1), ((void (&)())::FUN_00a2a620));
    return 1;
}

// Each key type fills its entries of the key function tables once. The original release ran these from every unit
// that included the key headers, in this order; the first call registers and later calls return 0.
[[maybe_unused]] static const int s_keyTypesRegistered[] = {
    ::RegisterFloatKeyOps(),
    ::FUN_00a273a0(),
    ::FUN_00a27b00(),
    ::FUN_00a28680(),
    ::FUN_00a28cb0(),
    ::FUN_00a29110(),
    ::FUN_00a294f0(),
    ::FUN_00a299f0(),
    ::FUN_00a2a110(),
    ::FUN_00a2a4d0(),
    ::FUN_00a2a720(),
    ::FUN_00a2aab0(),
    ::FUN_00a2ad80(),
    ::fnv_00a2bb90::FUN_00a2bb90(),
    ::FUN_00a2c4c0(),
    ::FUN_00a2cb80(),
    ::FUN_00a2ce20(),
    ::FUN_00a2d140(),
    ::FUN_00a2d360(),
    ::FUN_00a2d610(),
    ::FUN_00a2d810(),
};

#include "generated/data/generated/crt_callback_status_o2_variant.inc"
