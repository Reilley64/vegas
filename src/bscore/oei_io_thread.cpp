// bscore/oei_io_thread.cpp: IO_Thread (2 functions)

#include <cstdio>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa63c0.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "oei_io_thread_decls.h"

// @fnv 0x00aa8430
unsigned int OEI::IO::IO_Thread::ThreadProc()
{
    bool quit;
    SetSchedulingPriority(1);
    while (true)
    {
        reinterpret_cast<::SemaphoreWaitReceiver *>(((*reinterpret_cast<::CountingSemaphore * *>(&::DAT_011f6bf4))))->FUN_004424e0();
        LockRequestQueue((*reinterpret_cast<::RecursiveLock * *>(&::DAT_011f6bfc)));
        IORequest* request = (*reinterpret_cast<::BSList< ::OEI::IO::IORequest *> * *>(&::DAT_011f6c00))->RemoveHead();
        UnlockRequestQueue((*reinterpret_cast<::RecursiveLock * *>(&::DAT_011f6bfc)));
        quit = false;
        switch (request->m_eRequestType)
        {
        case IRT_QUIT:
            quit = true;
            break;
        case IRT_SEEK:
            request->result.result_int = std::fseek((std::FILE *)(request->m_pFile), request->m_uiSize, request->m_eSeekWhence);
            break;
        case IRT_READ:
            request->result.result_unsigned_int = std::fread(request->m_pBuffer, 1, request->m_uiSize, (std::FILE *)(request->m_pFile));
            break;
        case IRT_WRITE:
            request->result.result_unsigned_int = std::fwrite(request->m_pBuffer, 1, request->m_uiSize, (std::FILE *)(request->m_pFile));
            break;
        }
        if (quit)
        {
            reinterpret_cast<::FUN_00442550_shell *>(((*reinterpret_cast<::CountingSemaphore * *>(&::IoTaskGlobals::DAT_011f6bf8))))->ReleaseAndInitScriptRunLock();
            break;
        }
        if (request->m_pCompletionSemaphore)
            reinterpret_cast<::FUN_00442550_shell *>((request->m_pCompletionSemaphore))->ReleaseAndInitScriptRunLock();
    }
    return 0;
}

struct MemoryManager
{
};

struct FUN_00aa89d0_holder
{
    FUN_00aa89d0_holder* Destroy(unsigned int flags);
};

// Calls FUN_00aa63c0, then frees this via g_memoryManager.Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00aa89d0
FUN_00aa89d0_holder* FUN_00aa89d0_holder::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00aa63c0 *>(this)->FUN_00aa63c0::~FUN_00aa63c0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
