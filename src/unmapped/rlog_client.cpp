// src/unmapped/rlog_client.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/remotelog/rlog_client.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// FUN_0060ce80 (0x0060ce80, 38 bytes)
//
// The function is a member of a Gamebryo-style class: it byte-swaps the dword
// that lives at this+4 by handing its address to the byte-swap helper
// FUN_00401080 together with a "do swap" flag that is always false.
//
// The false flag is a one byte object that is value-initialised (hence the
// `xor eax,eax` / `mov byte ptr [ebp-1],al` pair) and whose single byte is
// then read back and pushed as the helper's second argument.


// one byte flag holder (the helper's "bDoSwap" argument)
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_011c6000.h"
struct ByteSwapFlag
{
    unsigned char m_bDoSwap;
};

struct FUN_0060ce80_Obj
{
    void* unk00;
    void* unk04;
    void FUN_0060ce80();
};

// Calls FUN_00401080_helper on the object's field at offset 4, passing the byte-swap flag from a ByteSwapFlag.
// @fnv 0x0060ce80
void FUN_0060ce80_Obj::FUN_0060ce80()
{
    ::FUN_00401080((int *)(void *)((void*)((char*)this + 4)));
}

struct LodCell
{
};
struct LodPoint
{
    float x, y, z;
};
struct LodSetting
{
};
extern LodCell* g_pkLastCell_011c3f04;
extern int g_iLastLod_011c3f00;
extern "C" int __cdecl abs(int i);

struct LodGrid
{
    char pad00[0x24];
    int m_iCenterX;
    int m_iCenterY;
    int FUN_00458be0(LodCell* pkCell, LodPoint* pkPos);
};

// Computes a LOD level from the cell's grid offset relative to the grid center or a position, caches it with the cell, and returns it.
// @fnv 0x00458be0
int LodGrid::FUN_00458be0(LodCell* pkCell, LodPoint* pkPos)
{
    if (g_pkLastCell_011c3f04 == pkCell)
        return g_iLastLod_011c3f00;
    int iDXVal2;
    int iDYVal2;
    if (reinterpret_cast<::TESObjectCELL *>((pkCell))->IsCellInterior())
    {
        iDXVal2 = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1;
        iDYVal2 = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1;
    }
    else if (pkPos)
    {
        iDXVal2 = reinterpret_cast<::TESObjectCELL *>((pkCell))->GetCellGridX() - ((::FUN_00406d90(pkPos->x) >> 12) - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1));
        iDYVal2 = reinterpret_cast<::TESObjectCELL *>((pkCell))->GetCellGridY() - ((::FUN_00406d90(pkPos->y) >> 12) - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1));
    }
    else
    {
        iDXVal2 = reinterpret_cast<::TESObjectCELL *>((pkCell))->GetCellGridX() - (m_iCenterX - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1));
        iDYVal2 = reinterpret_cast<::TESObjectCELL *>((pkCell))->GetCellGridY() - (m_iCenterY - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1));
    }
    int iXY = iDXVal2 - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1);
    int iY8 = iDYVal2 - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::LodSetting *>(&::g_011c63cc)))))) >> 1);
    unsigned char ucDistZ;
    if (iXY > iY8)
        ucDistZ = abs(iXY) * 10 + 10;
    else
        ucDistZ = abs(iY8) * 10 + 10;
    if (ucDistZ <= 20)
        ucDistZ = 20;
    else
        ucDistZ = 40;
    switch (ucDistZ)
    {
    case 10:
        g_iLastLod_011c3f00 = 0;
        break;
    case 20:
        g_iLastLod_011c3f00 = 1;
        break;
    case 30:
        g_iLastLod_011c3f00 = 2;
        break;
    case 40:
        g_iLastLod_011c3f00 = 3;
        break;
    case 50:
        g_iLastLod_011c3f00 = 4;
        break;
    }
    g_pkLastCell_011c3f04 = pkCell;
    return g_iLastLod_011c3f00;
}
