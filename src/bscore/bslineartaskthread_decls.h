// bscore/bslineartaskthread_decls.h: declares BSThread, CountingSemaphore, BSLinearTaskThread
#ifndef BSLINEARTASKTHREAD_DECLS_H
#define BSLINEARTASKTHREAD_DECLS_H

#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
class BSThread
{
  public:
    BSThread();
    virtual ~BSThread();
    virtual unsigned int ThreadProc();
    unsigned char threadData[0x2c];
};
class CountingSemaphore
{
  public:
    CountingSemaphore();
    ~CountingSemaphore();
    unsigned char data[12];
};
class BSLinearTaskThread : public BSThread
{
  public:
    BSLinearTaskThread();
    virtual unsigned int ThreadProc();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    CountingSemaphore m_kWorkAvailableSemaphore;
    CountingSemaphore m_kCompletionSemaphore;
    bool m_bStopRequested;
};
#endif
