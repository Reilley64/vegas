
// to their real unit once identified.

#include <windows.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "bsthread_console_pc.h"
#include "bsthread_console_pc.h"
#include "bsthread_console_pc.h"
unsigned long RunThreadProc(void* thread);
struct CRITSEC
{
    int a[6];
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


struct CriticalSectionAA63
{
    ~CriticalSectionAA63()
    {
        DeleteCriticalSection(this);
    }
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
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
