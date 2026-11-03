
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "bslineartaskthread_decls.h"
// @fnv 0x008c7720
unsigned int BSLinearTaskThread::ThreadProc()
{
    vfn_08();
    while (!m_bStopRequested)
    {
        reinterpret_cast<::SemaphoreWaitReceiver *>(&(m_kWorkAvailableSemaphore))->FUN_004424e0();
        if (m_bStopRequested)
            break;
        vfn_10();
        reinterpret_cast<::FUN_00442550_shell *>(&(m_kCompletionSemaphore))->ReleaseAndInitScriptRunLock();
    }
    vfn_0c();
    reinterpret_cast<::FUN_00442550_shell *>(&(m_kCompletionSemaphore))->ReleaseAndInitScriptRunLock();
    return 0;
}
// @fnv 0x008c76a0
BSLinearTaskThread::BSLinearTaskThread()
{
    m_bStopRequested = false;
}
