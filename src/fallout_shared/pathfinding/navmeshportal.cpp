
// src/fallout_shared/pathfinding/navmeshportal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshportal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/Owner45A.h"
#include "fnv/decl/Pathing.h"
#include "fnv/decl/TESFile.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_011de000.h"
struct DFD0SwapFlag
{
    bool m_bValue;
};


struct DFD0File
{
};


struct DFD0Form
{
};

struct DFD0TES
{
};


struct DFD0Data
{
    void* m_pBase;
    short m_sCount;

    void LoadFormRef(void* pUnused, DFD0File* pkFile, const char* pBuffer);
};

// Reads a form ID and a count from the buffer, byte-swaps them if the file needs endian conversion, resolves the form ID to a base pointer, and stores both.
// @fnv 0x0069dfd0
void DFD0Data::LoadFormRef(void* pUnused, DFD0File* pkFile, const char* pBuffer)
{
    int iFormID = *(const int*)pBuffer;
    if (reinterpret_cast<::TESFile *>((pkFile))->IsEndianConversionRequired())
        ::FUN_00401080(&iFormID);
    ::ResolveFormID((unsigned int *)(int *)(&iFormID), (::TESFile *)(pkFile));
    if (iFormID)
        m_pBase = ((void *)(reinterpret_cast<::Pathing *>((((::DFD0Form *)(reinterpret_cast<::Owner45A *>(((*reinterpret_cast<::DFD0TES * *>(&::g_TES))))->FUN_0045af00()))))->FindReferenceByFormId({})));
    else
        m_pBase = 0;
    pBuffer += 4;
    m_sCount = *(const short*)pBuffer;
    if (reinterpret_cast<::TESFile *>((pkFile))->IsEndianConversionRequired())
        ::FUN_00407a90(&m_sCount);
}
