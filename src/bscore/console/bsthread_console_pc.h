// bscore/console/bsthread_console_pc.h: declares BSThreadCriticalSectionPC, BSThread, BSThreadEntryPC
#ifndef FNV_BSTHREAD_CONSOLE_PC_H
#define FNV_BSTHREAD_CONSOLE_PC_H


#include <windows.h>
#include "layout_support.h"

struct BSThreadCriticalSectionPC
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

class BSThread
{
  public:
    enum StackSize
    {
        INHERIT_MAIN = 0,
        SMALL_STACK_SIZE = 16384,
        MEDIUM_STACK_SIZE = 32768,
        LARGE_STACK_SIZE = 65536,
        MAINTHREAD_STACK_SIZE = 131072
    };

    BSThread();
    virtual ~BSThread();
    void Initialize(StackSize stackSize, const char* name, bool suspended);
    void SetThreadPriority(int priority);
    void SetSchedulingPriority(unsigned int);
    unsigned int ThreadProc();
    void SetName(const char*);

    BSThreadCriticalSectionPC CriticalSection;
    void* m_pThreadHandle;
    void* m_pCurrentThreadHandle;
    unsigned int m_uiCreatedThreadId;
    unsigned int m_uiCurrentThreadId;
    bool m_bThreadStarted;
};


extern "C"
{
    extern void(* fnv_EnterCriticalSection)(void*);
    extern void(* fnv_LeaveCriticalSection)(void*);
}

class BSThreadEntryPC
{
  public:
    virtual ~BSThreadEntryPC();
    virtual unsigned long ThreadProc();
};

// The thread entry point has no identity candidate in the task or lookup index.
unsigned long RunThreadProc(void*);
extern void(* DAT_00fdf054)(void*);

#endif
