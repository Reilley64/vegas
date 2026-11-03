#include "fnv/symbols_0040f000.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

unsigned int gm_GetCurrentThreadId();

int FUN_0043b460(const long* lock, long zero, long owner);

struct FUN_0078d200_cls
{
    unsigned int m_pOwnerObject;
    unsigned int m_uiItemCount;
    bool FUN_0078d200();
};

// @fnv 0x0078d200
bool FUN_0078d200_cls::FUN_0078d200()
{
    __declspec(align(32)) unsigned int tid;
    bool ok = false;
    tid = gm_GetCurrentThreadId();
    if (m_pOwnerObject == tid)
    {
        m_uiItemCount = m_uiItemCount + 1;
        ok = true;
    }
    else
    {
        ok = !FUN_0043b460((const long*)this, 0, (long)tid);
        if (ok)
        {
            FUN_0040fbe0();
            m_uiItemCount = 1;
        }
    }
    return ok;
}
