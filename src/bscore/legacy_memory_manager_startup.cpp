#include "fnv/memory/legacy_manager_startup.h"
#include "fnv/decl/FUN_00aa39c0_cls.h"
#include "fnv/decl/FUN_00866690_Class.h"
#include <cstring>
#include "fnv/tls.h"

namespace fnv_00aa58d0 { void FUN_00aa58d0(); }

bool fnv::memory::RequireJoinedMemoryManagerStartup()
{
    throw MemoryManagerStartupUnavailable{};
}

// @fnv 0x00aa39c0
void FUN_00aa39c0_cls::FUN_00aa39c0()
{
    // The former receiver was a shell, not a constructed MemoryManager (nor a
    // TESForm). Reject BEFORE ClearMemoryPoolTables, heap init, the first-byte
    // write, pool startup or the incompatible ClearData callback. No receiver
    // is inspected. InitializeHeaps remains the admitted typed heap-only entry.
    fnv::memory::RequireJoinedMemoryManagerStartup();
    // Preserve the accepted final typed TLS action. Failed startup must not
    // reach it; a future complete startup join must perform it last.
    ::g_tlsBlock.memoryContext = 0;
}

// @fnv 0x00aa3880
FUN_00aa3880::FUN_00aa3880()
    : m_bShaderEnabled(fnv::memory::RequireJoinedMemoryManagerStartup()),
      m_sCount(0), m_sIndex(0), m_iFlags(0), m_iActive(0), m_bEnableState(true),
      m_bVisible(true), m_iFirst(0), m_iSecond(0), m_iThird(0)
{
    // Original construction inputs remain explicit, but none is admitted by a
    // failed startup. In particular do not allocate the table or apply shell
    // initialization/callbacks to the complete global owner.
    ::std::memset(m_apSlots, 0, sizeof(m_apSlots));
    CheckMemoryForLegacyStartup();
    FUN_00aa39c0_cls startup;
    startup.FUN_00aa39c0();
    reinterpret_cast<::FUN_00866690_Class *>(this)->InitializeGlobal();
    ::fnv_00aa58d0::FUN_00aa58d0();
}
