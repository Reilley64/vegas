#include "AutoMemContext.h"
#include "fnv/tls.h"

// @fnv 0x00404eb0
AutoMemContext::AutoMemContext(int context, bool overridable, const char* file, int line) noexcept
{
    Enter(context, overridable, file, line);
}

AutoMemContext::AutoMemContext(int context) noexcept
    : AutoMemContext(context, true, nullptr, 0)
{
}

// @fnv 0x00404ee0
AutoMemContext::~AutoMemContext() noexcept
{
    Leave();
}

// @fnv 0x00404f00
void AutoMemContext::Enter(int context, bool, const char*, int) noexcept
{
    // The source Enter always takes a fresh snapshot, even when already
    // active (BootInit enters immediately after construction). This replaces
    // the outstanding restoration point; it is not a second stacked entry.
    // The source ignores overridable/file/line; do not invent a policy or
    // retain a borrowed filename that is never consumed.
    previousContext_ = GetTlsField();
    active_ = true;
    fnv_00404f30::FUN_00404f30(context);
}

// @fnv 0x00404f70
void AutoMemContext::Leave() noexcept
{
    if (active_)
    {
        active_ = false;
        fnv_00404f30::FUN_00404f30(previousContext_);
    }
}

// @fnv 0x00404f50
int GetTlsField()
{
    return g_tlsBlock.memoryContext;
}

// @fnv 0x00404f30
void fnv_00404f30::FUN_00404f30(int context)
{
    g_tlsBlock.memoryContext = context;
}
