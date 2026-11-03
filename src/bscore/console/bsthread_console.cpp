// bscore/console/bsthread_console.cpp: BSThread (8 functions)

#include <windows.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "bsthread_console_pc.h"

// @fnv 0x00aa6550
void BSThread::SetSchedulingPriority(unsigned int argument0)
{}

#include "bsthread_console_pc.h"

// @fnv 0x00ad87c0
unsigned int BSThread::ThreadProc()
{
    return 0;
}

#include "bsthread_console_pc.h"

// @fnv 0x00aa6540
void BSThread::SetName(const char* argument0)
{}

// Creates the thread once, records its handle and id, sets its priority, and resumes it under the critical section.
// @fnv 0x00aa6430
void BSThread::Initialize(StackSize stackSize, const char* name, bool suspended)
{
    if (m_pThreadHandle)
        return;

    m_pCurrentThreadHandle = GetCurrentThread();
    m_uiCurrentThreadId = GetCurrentThreadId();
    m_pThreadHandle = CreateThread(0, stackSize, RunThreadProc, this, suspended ? 4 : 0, &m_uiCreatedThreadId);
    fnv_EnterCriticalSection(&CriticalSection);
    SetThreadPriority(-1);
    m_bThreadStarted = true;
    unsigned long previousSuspendCount = ResumeThread(m_pThreadHandle);
    fnv_LeaveCriticalSection(&CriticalSection);
}

// @fnv 0x00aa6360
BSThread::BSThread()
{
    BSThreadCriticalSectionPC* criticalSection = &CriticalSection;
    DAT_00fdf054(criticalSection);
    m_pThreadHandle = 0;
    m_pCurrentThreadHandle = 0;
    m_uiCreatedThreadId = 0;
    m_uiCurrentThreadId = 0;
    m_bThreadStarted = false;
}

// If the stored thread handle is non-null, applies the given priority to it via SetThreadPriority.
// @fnv 0x00aa6560
void BSThread::SetThreadPriority(int priority)
{
    if (m_pThreadHandle)
        ::SetThreadPriority(m_pThreadHandle, priority);
}

// @fnv 0x00aa64d0
unsigned long RunThreadProc(void* thread)
{
    return static_cast<BSThreadEntryPC*>(thread)->ThreadProc();
}

struct CRITSEC : CRITICAL_SECTION
{
};
struct FUN_00aa64f0_t
{
    int vt;
    CRITSEC cs;
    void* handle;
    int pad[3];
    char running;
    void StopAndCloseHandle();
};
// If handle is set, clears running, closes handle under the critical section, and resets handle to 0.
// @fnv 0x00aa64f0
void FUN_00aa64f0_t::StopAndCloseHandle()
{
    if (handle)
    {
        running = 0;
        EnterCriticalSection(&cs);
        CloseHandle(handle);
        handle = 0;
        LeaveCriticalSection(&cs);
    }
}

unsigned long RunThreadProc(void* thread);

struct CriticalSectionAA63 : CRITICAL_SECTION
{
    ~CriticalSectionAA63()
    {
        DeleteCriticalSection(this);
    }
};

class FUN_00aa63c0
{
  public:
    virtual ~FUN_00aa63c0();

    CriticalSectionAA63 m_kCriticalSection;
    void* m_hThread;
    void* m_hParent;
    unsigned int m_uiThreadID;
    unsigned int m_uiParentID;
    bool m_bModifierActive;
};

// @fnv 0x00aa63c0
FUN_00aa63c0::~FUN_00aa63c0()
{
    reinterpret_cast<::FUN_00aa64f0_t *>(this)->StopAndCloseHandle();
}

#include "generated/data/bscore/console/bsthread_console.inc"
