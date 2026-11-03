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
    (*reinterpret_cast<void * *>(&::FUN_00a28cb0_aTable11)) = (void*)((void (&)())::LoadBezPosKeys);
    (*reinterpret_cast<void * *>(&::FUN_00a28cb0_aTable3)) = (void*)((void (&)())::SaveKeyArray);
    (*reinterpret_cast<void * *>(&::FUN_00a28cb0_aTable5)) = (void*)((void (&)())::FUN_00a27b60);
    (*reinterpret_cast<void * *>(&::FUN_00a28cb0_aTable2)) = (void*)((void (&)())::AllocateElem64Array);
    (*reinterpret_cast<void * *>(&::FUN_00a28cb0_aTable4)) = (void*)((void (&)())::FUN_00a2a600);
    DAT_011f3760 = 0x40;
    FUN_00a28620(1, 2);
    return 1;
}

extern unsigned char DAT_011f3693;
extern unsigned char DAT_011f375f;
extern int DAT_011f38bc;
extern int DAT_011f394c;
extern int DAT_011f39dc;
extern int DAT_011f3a6c;
extern int DAT_011f3dcc;

// @fnv 0x00a2aab0
int __cdecl FUN_00a2aab0()
{
    if (DAT_011f3693)
        return 0;
    DAT_011f3693 = 1;
    DAT_011f3dcc = (int)((void (&)())::CreateVertexRecords);
    DAT_011f3a6c = (int)((void (&)())::FUN_00a2d470);
    DAT_011f39dc = (int)((void (&)())::FUN_00a2a7b0);
    DAT_011f394c = (int)((void (&)())::AllocateTempArray);
    DAT_011f38bc = (int)((void (&)())::FUN_00a2a600);
    DAT_011f375f = 0x10;
    ::fnv_00a2aa50::FUN_00a2aa50(1, 1);
    return 1;
}

namespace fnv_00a2bb90 {
extern unsigned char DAT_011f3695;
extern unsigned char DAT_011f3761;
extern int DAT_011f38c4;
extern int DAT_011f3954;
extern int DAT_011f39e4;
extern int DAT_011f3a74;
extern int DAT_011f3dd4;

// @fnv 0x00a2bb90
int __cdecl FUN_00a2bb90()
{
    if (DAT_011f3695)
        return 0;
    DAT_011f3695 = 1;
    DAT_011f3dd4 = (int)&((void (&)())::fnv_00a2bb00::AllocateElement76Array);
    DAT_011f3a74 = (int)&((void (&)())::FUN_00a2bb60);
    DAT_011f39e4 = (int)&((void (&)())::CopyFloatBlock);
    DAT_011f3954 = (int)&((void (&)())::AllocateBezierKeys);
    DAT_011f38c4 = (int)&((void (&)())::FUN_00a2a600);
    DAT_011f3761 = 0x4c;
    ::FUN_00a2baa0(1, 3);
    return 1;
}
}  // namespace fnv_00a2bb90

typedef void(__cdecl* FUN_00a28cb0_KeyFn)();

extern bool FUN_00a28cb0_bRegistered;
extern FUN_00a28cb0_KeyFn FUN_00a28cb0_aTable0[36];
extern FUN_00a28cb0_KeyFn FUN_00a28cb0_aTable1[36];
extern FUN_00a28cb0_KeyFn FUN_00a28cb0_aTable6[36];
extern FUN_00a28cb0_KeyFn FUN_00a28cb0_aTable7[36];
extern FUN_00a28cb0_KeyFn FUN_00a28cb0_aTable8[36];
extern FUN_00a28cb0_KeyFn FUN_00a28cb0_aTable9[36];
extern FUN_00a28cb0_KeyFn FUN_00a28cb0_aTable10[36];


// @fnv 0x00a28cb0
int __cdecl FUN_00a28cb0()
{
    if (FUN_00a28cb0_bRegistered)
        return 0;

    FUN_00a28cb0_aTable10[4] = 0;
    FUN_00a28cb0_aTable8[4] = 0;
    FUN_00a28cb0_aTable1[4] = 0;
    FUN_00a28cb0_bRegistered = true;
    FUN_00a28cb0_aTable11[4] = ((void (&)())::FUN_00e7cd40);
    FUN_00a28cb0_aTable3[4] = ::FUN_00a29680;
    FUN_00a28cb0_aTable5[4] = ::FUN_00a29680;
    FUN_00a28cb0_aTable2[4] = ((void (&)())::FUN_00e7cd40);
    FUN_00a28cb0_aTable4[4] = ::FUN_00a29680;
    (*reinterpret_cast<unsigned char (*)[36]>(&::DAT_011f3760))[4] = 20;
    FUN_00a28cb0_aTable7[4] = 0;
    FUN_00a28cb0_aTable6[4] = ((void (&)())::FUN_00a286e0);
    FUN_00a28cb0_aTable0[4] = ((void (&)())::FUN_00a28a80);
    FUN_00a28cb0_aTable9[4] = ((void (&)())::FUN_00a28ab0);
    return 1;
}

typedef void(__cdecl* S_00a29110_Fn)();
extern char DAT_011f367c;
extern char DAT_011f3766;
extern int DAT_011f3d58;
extern int DAT_011f3c38;
extern int DAT_011f3ba8;
extern S_00a29110_Fn DAT_011f3de8;
extern S_00a29110_Fn DAT_011f3a88;
extern S_00a29110_Fn DAT_011f39f8;
extern S_00a29110_Fn DAT_011f3968;
extern S_00a29110_Fn DAT_011f38d8;
extern S_00a29110_Fn DAT_011f3cc8;
extern S_00a29110_Fn DAT_011f3b18;
extern S_00a29110_Fn DAT_011f37b8;
extern S_00a29110_Fn DAT_011f3848;
// @fnv 0x00a29110
int FUN_00a29110()
{
    if (DAT_011f367c)
        return 0;
    DAT_011f367c = 1;
    DAT_011f3d58 = 0;
    DAT_011f3c38 = 0;
    DAT_011f3ba8 = 0;
    DAT_011f3de8 = ((void (&)())::FUN_00a290a0);
    DAT_011f3a88 = ((void (&)())::fnv_00a28ed0::FUN_00a28ed0);
    DAT_011f39f8 = ((void (&)())::CopyBlk36);
    DAT_011f3968 = ((void (&)())::FUN_00a28f00);
    DAT_011f38d8 = ((void (&)())::FUN_00a2a600);
    DAT_011f3766 = 0x24;
    DAT_011f3cc8 = ((void (&)())::CallSpawnTarget);
    DAT_011f3b18 = ((void (&)())::CompareBounds);
    DAT_011f37b8 = ((void (&)())::FUN_00a28dc0);
    DAT_011f3848 = ((void (&)())::FUN_00a28f50);
    return 1;
}

extern unsigned char DAT_011f3655;
extern void* DAT_011f3d28;
extern void* DAT_011f3c08;
extern void* DAT_011f3b78;
extern void* DAT_011f3db8;
extern void* DAT_011f3a58;
extern void* DAT_011f39c8;
extern void* DAT_011f3938;
extern void* DAT_011f38a8;
extern unsigned char DAT_011f375a;
extern void* DAT_011f3c98;
extern void* DAT_011f3ae8;
extern void* DAT_011f3788;
extern void* DAT_011f3818;


// @fnv 0x00a273a0
int __cdecl FUN_00a273a0()
{
    if (DAT_011f3655 != 0)
    {
        return 0;
    }
    DAT_011f3655 = 1;
    DAT_011f3d28 = 0;
    DAT_011f3c08 = 0;
    DAT_011f3b78 = 0;
    DAT_011f3db8 = (void*)((void (&)())::LoadFloatKeys);
    DAT_011f3a58 = (void*)((void (&)())::sa27320::SaveKeys);
    DAT_011f39c8 = (void*)((void (&)())::FUN_00a26f80);
    DAT_011f3938 = (void*)((void (&)())::AllocateTempArray);
    DAT_011f38a8 = (void*)((void (&)())::FUN_00a2a600);
    DAT_011f375a = 0x10;
    DAT_011f3c98 = (void*)((void (&)())::FUN_00a26fe0);
    DAT_011f3ae8 = (void*)((void (&)())::FUN_00a26f30);
    DAT_011f3788 = (void*)FUN_00a29680;
    DAT_011f3818 = (void*)((void (&)())::FUN_00a27080);
    return 1;
}

extern char DAT_011f3656;
extern void* DAT_011f3948;
extern void* DAT_011f39d8;


void __cdecl FUN_00a27aa0(int, int);

// @fnv 0x00a27b00
int FUN_00a27b00()
{
    if (DAT_011f3656)
        return 0;
    DAT_011f3656 = 1;
    (*reinterpret_cast<void * *>(&::DAT_011f3dc8)) = (void*)((void (&)())::FUN_00e7cd40);
    (*reinterpret_cast<void * *>(&::g_011f3a68)) = (void*)::FUN_00a29680;
    DAT_011f39d8 = (void*)::FUN_00a29680;
    DAT_011f3948 = (void*)((void (&)())::FUN_00e7cd40);
    (*reinterpret_cast<void * *>(&::DAT_011f38b8)) = (void*)::FUN_00a29680;
    (*reinterpret_cast<char *>(&::DAT_011f375e)) = 0x10;
    FUN_00a27aa0(1, 0);
    return 1;
}

typedef void(__cdecl* S_00a294f0_Fn)();

extern char DAT_011f367e;
extern S_00a294f0_Fn DAT_011f39a8;
extern S_00a294f0_Fn DAT_011f3a38;

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
    (*reinterpret_cast<void (**)()>(&::DAT_011f3e28)) = &((void (&)())::FUN_00e7cd40);
    (*reinterpret_cast<void (**)()>(&::DAT_011f3ac8)) = &FUN_00a29680;
    DAT_011f3a38 = &::FUN_00a29680;
    DAT_011f39a8 = &((void (&)())::FUN_00e7cd40);
    (*reinterpret_cast<void (**)()>(&::DAT_011f3918)) = &::FUN_00a29680;
    (*reinterpret_cast<char *>(&::DAT_011f3776)) = 8;
    RegisterCurveOps(5, 0);
    return 1;
}


typedef void(__cdecl* A2AD80Callback)();

extern bool g_A2AD80Initialized;
extern A2AD80Callback g_A2AD80Callback0;
extern A2AD80Callback g_A2AD80Callback1;
extern A2AD80Callback g_A2AD80Callback2;
extern A2AD80Callback g_A2AD80Callback3;
extern A2AD80Callback g_A2AD80Callback4;
extern A2AD80Callback g_A2AD80Callback5;
extern A2AD80Callback g_A2AD80Callback6;
extern A2AD80Callback g_A2AD80Callback7;
extern A2AD80Callback g_A2AD80Callback8;
extern A2AD80Callback g_A2AD80Callback9;
extern A2AD80Callback g_A2AD80Callback10;
extern A2AD80Callback g_A2AD80Callback11;
extern unsigned char g_A2AD80Flags;

// @fnv 0x00a2ad80
int __cdecl FUN_00a2ad80()
{
    if (g_A2AD80Initialized)
        return 0;
    g_A2AD80Initialized = true;
    g_A2AD80Callback0 = 0;
    g_A2AD80Callback1 = 0;
    g_A2AD80Callback2 = 0;
    g_A2AD80Callback3 = ((void (&)())::FUN_00a2abc0);
    g_A2AD80Callback4 = ((void (&)())::fnv_00a2d690::FUN_00a2d690);
    g_A2AD80Callback5 = ((void (&)())::FUN_00a2ab10);
    g_A2AD80Callback6 = ((void (&)())::FUN_00a2ab40);
    g_A2AD80Callback7 = ((void (&)())::FUN_00a2a600);
    g_A2AD80Flags = 0x14;
    g_A2AD80Callback8 = ((void (&)())::FUN_00a2ab90);
    g_A2AD80Callback9 = ((void (&)())::FUN_00a2d680);
    g_A2AD80Callback10 = ((void (&)())::FUN_00a2d670);
    g_A2AD80Callback11 = ((void (&)())::FUN_00a2ac30);
    return 1;
}

typedef void(__cdecl* RuntimeCallback)();

extern unsigned char DAT_011f3696;
extern unsigned char DAT_011f3767;
extern RuntimeCallback DAT_011f3d5c;
extern RuntimeCallback DAT_011f3c3c;
extern RuntimeCallback DAT_011f3bac;
extern RuntimeCallback DAT_011f3dec;
extern RuntimeCallback DAT_011f3a8c;
extern RuntimeCallback DAT_011f39fc;
extern RuntimeCallback DAT_011f396c;
extern RuntimeCallback DAT_011f38dc;
extern RuntimeCallback DAT_011f3ccc;
extern RuntimeCallback DAT_011f3b1c;
extern RuntimeCallback DAT_011f37bc;
extern RuntimeCallback DAT_011f384c;


// @fnv 0x00a2c4c0
int __cdecl FUN_00a2c4c0()
{
    if (DAT_011f3696 != 0)
        return 0;

    DAT_011f3696 = 1;
    DAT_011f3d5c = 0;
    DAT_011f3c3c = 0;
    DAT_011f3bac = 0;
    DAT_011f3dec = ((void (&)())::fnv_00a2c420::FUN_00a2c420);
    DAT_011f3a8c = ((void (&)())::FUN_00a2c490);
    DAT_011f39fc = ((void (&)())::FUN_00a2bbf0);
    DAT_011f396c = ((void (&)())::FUN_00a2be60);
    DAT_011f38dc = ((void (&)())::FUN_00a2a600);
    DAT_011f3767 = 0x40;
    DAT_011f3ccc = ((void (&)())::fnv_00a2bc60::InvokeSpawnTarget);
    DAT_011f3b1c = ((void (&)())::BezRotKeyEqual);
    DAT_011f37bc = ((void (&)())::FUN_00a2c130);
    DAT_011f384c = ((void (&)())::FUN_00a2c1b0);
    return 1;
}

extern unsigned char DAT_011f3697;
extern unsigned char DAT_011f375b;
extern int DAT_011f3d2c;
extern int DAT_011f3c0c;
extern int DAT_011f3b7c;
extern void* DAT_011f3dbc;
extern void* DAT_011f3a5c;
extern void* DAT_011f39cc;
extern void* DAT_011f393c;
extern void* DAT_011f38ac;
extern void* DAT_011f3c9c;
extern void* DAT_011f3aec;
extern void* DAT_011f378c;
extern void* DAT_011f381c;

// @fnv 0x00a2cb80
int __cdecl FUN_00a2cb80()
{
    if (DAT_011f3697 != 0)
    {
        return 0;
    }
    DAT_011f3697 = 1;
    DAT_011f3d2c = 0;
    DAT_011f3c0c = 0;
    DAT_011f3b7c = 0;
    DAT_011f3dbc = (void*)((void (&)())::AllocateKeyframeElements);
    DAT_011f3a5c = (void*)((void (&)())::FUN_00a2cb50);
    DAT_011f39cc = (void*)((void (&)())::CopyFloat7);
    DAT_011f393c = (void*)((void (&)())::fnv_00a2c660::AllocateElem28Array);
    DAT_011f38ac = (void*)((void (&)())::FUN_00a2a600);
    DAT_011f375b = 0x1c;
    DAT_011f3c9c = (void*)((void (&)())::FUN_00a2c610);
    DAT_011f3aec = (void*)((void (&)())::FUN_00a2c550);
    DAT_011f378c = (void*)((void (&)())::FUN_00a2c7a0);
    DAT_011f381c = (void*)((void (&)())::FUN_00a2c890);
    return 1;
}

extern unsigned char DAT_011f3698;
extern unsigned char DAT_011f377b;
extern int DAT_011f3dac;
extern int DAT_011f3c8c;
extern int DAT_011f3bfc;
extern void* DAT_011f3e3c;
extern void* DAT_011f3adc;
extern void* DAT_011f3a4c;
extern void* DAT_011f39bc;
extern void* DAT_011f392c;
extern void* DAT_011f3d1c;
extern void* DAT_011f3b6c;
extern void* DAT_011f380c;
extern void* DAT_011f389c;

// @fnv 0x00a2ce20
int __cdecl FUN_00a2ce20()
{
    if (DAT_011f3698 != 0)
    {
        return 0;
    }
    DAT_011f3698 = 1;
    DAT_011f3dac = 0;
    DAT_011f3c8c = 0;
    DAT_011f3bfc = 0;
    DAT_011f3e3c = (void*)((void (&)())::fnv_00a2cdc0::FUN_00a2cdc0);
    DAT_011f3adc = (void*)((void (&)())::FUN_00a2cc60);
    DAT_011f3a4c = (void*)((void (&)())::FUN_00a2cc10);
    DAT_011f39bc = (void*)((void (&)())::AllocateArr8Array);
    DAT_011f392c = (void*)((void (&)())::FUN_00a2a600);
    DAT_011f377b = 8;
    DAT_011f3d1c = (void*)((void (&)())::SelectByteByThreshold);
    DAT_011f3b6c = (void*)((void (&)())::FUN_00a2cc30);
    DAT_011f380c = (void*)FUN_00a29680;
    DAT_011f389c = (void*)((void (&)())::FUN_00a2ccd0);
    return 1;
}

typedef void(__cdecl* RuntimeCallbackFn)();

extern char DAT_011f3699;
extern int DAT_011f3d7c;
extern int DAT_011f3c5c;
extern int DAT_011f3bcc;
extern int DAT_011f37dc;
extern RuntimeCallbackFn DAT_011f3e0c;
extern RuntimeCallbackFn DAT_011f3aac;
extern RuntimeCallbackFn DAT_011f3a1c;
extern RuntimeCallbackFn DAT_011f398c;
extern RuntimeCallbackFn DAT_011f38fc;
extern char DAT_011f376f;
extern RuntimeCallbackFn DAT_011f3cec;
extern RuntimeCallbackFn DAT_011f3b3c;
extern RuntimeCallbackFn DAT_011f386c;


// @fnv 0x00a2d140
int FUN_00a2d140()
{
    if (DAT_011f3699 != 0)
        return 0;
    *(volatile char*)&DAT_011f3699 = 1;
    DAT_011f3d7c = 0;
    DAT_011f3c5c = 0;
    DAT_011f3bcc = 0;
    DAT_011f37dc = 0;
    *(RuntimeCallbackFn volatile*)&DAT_011f3e0c = ((void (&)())::FUN_00a2cf60);
    DAT_011f3aac = ((void (&)())::FUN_00a2cfd0);
    DAT_011f3a1c = ((void (&)())::FUN_00a2ab10);
    DAT_011f398c = ((void (&)())::FUN_00a2ced0);
    DAT_011f38fc = ((void (&)())::FUN_00a2a600);
    DAT_011f376f = 0x14;
    DAT_011f3cec = ((void (&)())::SelectPayloadByThreshold);
    DAT_011f3b3c = ((void (&)())::FUN_00a2a1a0);
    DAT_011f386c = ((void (&)())::fnv_00a2d000::FUN_00a2d000);
    return 1;
}

extern unsigned char DAT_011f369c;
extern unsigned char DAT_011f3769;
extern int DAT_011f3bb4;
extern int DAT_011f3c44;
extern int DAT_011f3d64;
extern void* DAT_011f3df4;
extern void* DAT_011f3a94;
extern void* DAT_011f3a04;
extern void* DAT_011f3974;
extern void* DAT_011f38e4;
extern void* DAT_011f3cd4;
extern void* DAT_011f3b24;
extern void* DAT_011f37c4;
extern void* DAT_011f3854;


// @fnv 0x00a2d810
int __cdecl FUN_00a2d810()
{
    if (DAT_011f369c != 0)
    {
        return 0;
    }
    DAT_011f369c = 1;
    DAT_011f3d64 = 0;
    DAT_011f3c44 = 0;
    DAT_011f3bb4 = 0;
    DAT_011f3df4 = (void*)((void (&)())::FUN_00a2abc0);
    DAT_011f3a94 = (void*)((void (&)())::fnv_00a2d690::FUN_00a2d690);
    DAT_011f3a04 = (void*)((void (&)())::FUN_00a2ab10);
    DAT_011f3974 = (void*)((void (&)())::FUN_00a2ab40);
    DAT_011f38e4 = (void*)((void (&)())::FUN_00a2a600);
    DAT_011f3769 = 0x14;
    DAT_011f3cd4 = (void*)((void (&)())::SelectPayloadByThreshold);
    DAT_011f3b24 = (void*)((void (&)())::FUN_00a2d680);
    DAT_011f37c4 = (void*)((void (&)())::FUN_00a2d670);
    DAT_011f3854 = (void*)((void (&)())::FUN_00a2d6c0);
    return 1;
}

typedef void(__cdecl* S_00a2d360_Fn)();

extern char DAT_011f369a;
extern int DAT_011f3d34;
extern int DAT_011f3c14;
extern int DAT_011f3b84;
extern S_00a2d360_Fn DAT_011f3dc4;
extern S_00a2d360_Fn DAT_011f3a64;
extern S_00a2d360_Fn DAT_011f39d4;
extern S_00a2d360_Fn DAT_011f3944;
extern S_00a2d360_Fn DAT_011f38b4;
extern unsigned char DAT_011f375d;
extern S_00a2d360_Fn DAT_011f3ca4;
extern S_00a2d360_Fn DAT_011f3af4;
extern S_00a2d360_Fn DAT_011f3794;
extern S_00a2d360_Fn DAT_011f3824;


// @fnv 0x00a2d360
int __cdecl FUN_00a2d360()
{
    if (DAT_011f369a)
        return 0;

    DAT_011f3d34 = 0;
    DAT_011f3c14 = 0;
    DAT_011f369a = 1;
    DAT_011f3b84 = 0;
    DAT_011f3dc4 = ((void (&)())::fnv_00a2a5a0::CreateInitializedElems);
    DAT_011f3a64 = ((void (&)())::FUN_00a2d230);
    DAT_011f39d4 = ((void (&)())::CopyFloat2);
    DAT_011f3944 = ((void (&)())::AllocateArr8Array);
    DAT_011f38b4 = ((void (&)())::FUN_00a2a600);
    DAT_011f375d = 8;
    DAT_011f3ca4 = ((void (&)())::FUN_00a2d200);
    DAT_011f3af4 = ((void (&)())::fnv_00a2d1d0::FUN_00a2d1d0);
    DAT_011f3794 = FUN_00a29680;
    DAT_011f3824 = ((void (&)())::fnv_00a2d260::InsertKeyPair);
    return 1;
}

#include <string.h>
struct CallbackTypeA;
struct CallbackTypeB;
struct CallbackTypeC;
struct CallbackTypeD;
struct ColorAnimationKey;
struct Helper;

extern unsigned char DAT_011f367f;
extern int DAT_011f3d68;
extern int DAT_011f3c48;
extern int DAT_011f3bb8;
extern int DAT_011f37c8;
extern int DAT_011f3858;
extern void (*volatile DAT_011f3a08)(CallbackTypeB*);
extern void (*volatile DAT_011f3978)(CallbackTypeB*);
extern int* CopyGlobalsToBuffer(int, int, int, int*);

// @fnv 0x00a299f0
int FUN_00a299f0()
{
    if (DAT_011f367f != 0)
        return 0;
    DAT_011f3d68 = 0;
    DAT_011f3c48 = 0;
    DAT_011f3bb8 = 0;
    DAT_011f37c8 = 0;
    DAT_011f3858 = 0;
    memset(&DAT_011f367f, 1, 1);
    (*reinterpret_cast<void (**volatile)(CallbackTypeA *)>(&::g_apfnColorKeyCreateA3D)) = &((void (&)(CallbackTypeA *))::FUN_00e7cd40);
    (*reinterpret_cast<void (**volatile)(CallbackTypeA *)>(&::DAT_011f3a98)) = &((void (&)(CallbackTypeA *))::FUN_00a29680);
    DAT_011f3a08 = &((void (&)(CallbackTypeB *))::FUN_00a29680);
    DAT_011f3978 = &((void (&)(CallbackTypeB *))::FUN_00e7cd40);
    (*reinterpret_cast<void (**volatile)(ColorAnimationKey *)>(&::DAT_011f38e8)) = &((void (&)(ColorAnimationKey *))::FUN_00a29680);
    (*reinterpret_cast<unsigned char *>(&::DAT_011f376a)) = 0x14;
    DAT_011f3cd8 = &CopyGlobalsToBuffer;
    (*reinterpret_cast<bool (**volatile)(const Helper *, const Helper *)>(&::DAT_011f3b28)) = &CompareHelpers;
    return 1;
}

extern unsigned char DAT_011f3690;
extern unsigned char DAT_011f3768;
extern unsigned int DAT_011f3d60, DAT_011f3c40, DAT_011f3bb0;
extern void (*DAT_011f3df0)();
extern void (*DAT_011f3a90)();
extern void (*DAT_011f3a00)();
extern void (*DAT_011f3970)();
extern void (*DAT_011f38e0)();
extern void (*DAT_011f3cd0)();
extern void (*DAT_011f3b20)();
extern void (*DAT_011f37c0)();
extern void (*DAT_011f3850)();
// @fnv 0x00a2a110
int __cdecl FUN_00a2a110()
{
    if (DAT_011f3690)
        return 0;
    DAT_011f3d60 = 0;
    DAT_011f3c40 = 0;
    DAT_011f3bb0 = 0;
    memset(&DAT_011f3690, 1, 1);
    DAT_011f3df0 = &((void (&)())::FUN_00a2a070);
    DAT_011f3a90 = &((void (&)())::FUN_00a2a0e0);
    DAT_011f3a00 = &((void (&)())::CopyKeyData);
    DAT_011f3970 = &((void (&)())::FUN_00a29db0);
    DAT_011f38e0 = &((void (&)())::FUN_00a2a600);
    DAT_011f3768 = 0x48;
    DAT_011f3cd0 = &((void (&)())::FUN_00a29b10);
    DAT_011f3b20 = &((void (&)())::FUN_00a29c20);
    DAT_011f37c0 = &((void (&)())::fnv_00a29e00::DispatchEntryCallbacks);
    DAT_011f3850 = &((void (&)())::UpdateArrayElements);
    return 1;
}

extern unsigned char DAT_011f3691;
extern unsigned char DAT_011f376b;
extern int DAT_011f3d6c, DAT_011f3c4c, DAT_011f3bbc, DAT_011f37cc;
extern void (*volatile DAT_011f3dfc)();
extern void (*volatile DAT_011f3a9c)();
extern void (*volatile DAT_011f3a0c)();
extern void (*volatile DAT_011f397c)();
extern void (*volatile DAT_011f38ec)();
extern void (*volatile DAT_011f3cdc)();
extern void (*volatile DAT_011f3b2c)();
extern void (*volatile DAT_011f385c)();
// @fnv 0x00a2a4d0
int __cdecl FUN_00a2a4d0()
{
    if (DAT_011f3691 != 0)
        return 0;
    DAT_011f3d6c = 0;
    DAT_011f3c4c = 0;
    DAT_011f3bbc = 0;
    DAT_011f37cc = 0;
    memset(&DAT_011f3691, 1, 1);
    DAT_011f3dfc = &((void (&)())::FUN_00a2a320);
    DAT_011f3a9c = &((void (&)())::FUN_00a2cfd0);
    DAT_011f3a0c = &((void (&)())::FUN_00a2ab10);
    DAT_011f397c = &((void (&)())::FUN_00a2a1b0);
    DAT_011f38ec = &((void (&)())::FUN_00a2a600);
    DAT_011f376b = 0x14;
    DAT_011f3cdc = &((void (&)())::InterpolateQuaternion);
    DAT_011f3b2c = &((void (&)())::FUN_00a2a1a0);
    DAT_011f385c = &((void (&)())::FUN_00a2a390);
    return 1;
}

extern unsigned char DAT_011f3692;
extern unsigned char DAT_011f3759;
extern int DAT_011f3d24, DAT_011f3c04, DAT_011f3b74;
extern void (*DAT_011f3db4)();
extern void (*DAT_011f3a54)();
extern void (*DAT_011f39c4)();
extern void (*DAT_011f3934)();
extern void (*DAT_011f38a4)();
extern void (*DAT_011f3c94)();
extern void (*DAT_011f3ae4)();
extern void (*DAT_011f3784)();
extern void (*DAT_011f3814)();
// @fnv 0x00a2a720
int FUN_00a2a720()
{
    if (DAT_011f3692)
        return 0;
    DAT_011f3d24 = 0;
    DAT_011f3c04 = 0;
    DAT_011f3b74 = 0;
    memset(&DAT_011f3692, 1, 1);
    DAT_011f3db4 = ((void (&)())::fnv_00a2a5a0::CreateInitializedElems);
    DAT_011f3a54 = ((void (&)())::FUN_00a2d230);
    DAT_011f39c4 = ((void (&)())::CopyFloat2);
    DAT_011f3934 = ((void (&)())::AllocateArr8Array);
    DAT_011f38a4 = ((void (&)())::FUN_00a2a600);
    DAT_011f3759 = 8;
    DAT_011f3c94 = ((void (&)())::FUN_00a2a560);
    DAT_011f3ae4 = ((void (&)())::fnv_00a2d1d0::FUN_00a2d1d0);
    DAT_011f3784 = FUN_00a29680;
    DAT_011f3814 = ((void (&)())::FUN_00a2a620);
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
