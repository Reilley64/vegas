// gamebryo2.2/corelibs/nimain/nitlargearray_h_unit.cpp: free functions (1 function)

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005ff4d0_shell.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00a63000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f6000.h"
#include "nitlargearray.inl"

struct TESRegion;

struct BGSAcousticSpace
{
    unsigned char unk00[0x48];
    TESRegion* m_pRegion;
};

struct NiTLargeArray_TESTopicInfo
{
    void** m_ppVirtualMethodTable;
    unsigned int* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int index, unsigned int* value);
    TESTopicInfo* RemoveAt(unsigned int index);
    void Compact();
};

struct FUN_005ff560_shell
{
    void RemoveChildAndRelinkNeighbors(unsigned int index);
};

// If the child array exists, links the next child's region to the previous child, then removes the child at index and compacts the array.
// @fnv 0x005ff560
void FUN_005ff560_shell::RemoveChildAndRelinkNeighbors(unsigned int index)
{
    if (*(void**)(this + 0x40))
    {
        TESTopicInfo* pNext = ((::TESTopicInfo *)(reinterpret_cast<::FUN_005ff4d0_shell *>((this))->GetIdleFormByIndex(index + 1)));
        TESTopicInfo* pPrevVal = ((::TESTopicInfo *)(reinterpret_cast<::FUN_005ff4d0_shell *>((this))->GetIdleFormByIndex(index - 1)));
        if (pNext)
            ((BGSAcousticSpace*)pNext)->m_pRegion = (TESRegion*)pPrevVal;
        ((NiTLargeArray_TESTopicInfo*)*(void**)(this + 0x40))->RemoveAt(index);
        ((NiTLargeArray_TESTopicInfo*)*(void**)(this + 0x40))->Compact();
    }
}
