
#include "fnv/decl/FUN_008691b0.h"
#include "layout_support.h"

class FNV_ALIGN(32) RecursiveSpinLock
{
public:
    volatile unsigned int m_uiOwningThreadID; // +0x0
    unsigned int m_uiRecursionCount;             // +0x4
    unsigned char layoutPadding8[24];

    void Lock();
};


// @fnv 0x00868250
void RecursiveSpinLock::Lock()
{
    reinterpret_cast<::FUN_008691b0 *>((m_uiOwningThreadID))->Lock();
}
