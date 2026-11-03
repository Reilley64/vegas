// bscore/oei_io_thread_decls.h: declares CountingSemaphore, IORequest, IO_Thread
#ifndef FNV_OEI_IO_THREAD_DECLS_H
#define FNV_OEI_IO_THREAD_DECLS_H

#include <windows.h>
#include "fnv/symbols_011f6000.h"
#include "BSThread.h"

struct _iobuf;
extern "C" int __cdecl fseek(_iobuf*, long, int);
extern "C" unsigned int __cdecl fread(void*, unsigned int, unsigned int, _iobuf*);
extern "C" unsigned int __cdecl fwrite(const void*, unsigned int, unsigned int, _iobuf*);
extern "C" void(* fnv_EnterCriticalSection)(_RTL_CRITICAL_SECTION*);
extern "C" void(* fnv_LeaveCriticalSection)(_RTL_CRITICAL_SECTION*);

class CountingSemaphore
{
  public:
    volatile long iCount;
    void* hSemaphore;
    int m_iMaximumCount;
    __forceinline void Wait()
    {
        WaitForSingleObject(hSemaphore, 0xffffffffUL);
        InterlockedDecrement(&iCount);
    }
    __forceinline void Signal()
    {
        ReleaseSemaphore(hSemaphore, 1, 0);
        InterlockedIncrement(&iCount);
    }
};

__forceinline void LockRequestQueue(RecursiveLock* section)
{
    fnv_EnterCriticalSection(&section->CriticalSection);
}
__forceinline void UnlockRequestQueue(RecursiveLock* section)
{
    // Unused local homes reproduce the original inlined unlock frame.
    // The diagnostic names are inferred; their original purpose is unknown.
    unsigned long threadOwner;
    unsigned long previousOwner;
    fnv_LeaveCriticalSection(&section->CriticalSection);
}

namespace OEI {
namespace IO {
enum IO_Request_Type
{
    IRT_INVALID,
    IRT_SEEK,
    IRT_READ,
    IRT_WRITE,
    IRT_QUIT
};
enum Seek_Whence_Type
{
    SWT_SET,
    SWT_CURRENT,
    SWT_END
};
class IORequest
{
  public:
    _iobuf* m_pFile;
    IO_Request_Type m_eRequestType;
    Seek_Whence_Type m_eSeekWhence;
    void* m_pBuffer;
    unsigned int m_uiSize;
    CountingSemaphore* m_pCompletionSemaphore;
    union
    {
        int result_int;
        unsigned int result_unsigned_int;
    } result;
};
class IO_Thread : public BSThread
{
  public:
    unsigned int ThreadProc();
};
}
}

template <class T> class BSListNode;
template <class T> class BSListBase
{
  public:
    void** m_ppVirtualMethodTable;
    BSListNode<T>* m_pkHead;
    BSListNode<T>* m_pkTail;
    unsigned int m_uiCount;
};
template <class T> class BSPointerListBase : public BSListBase<T>
{
  public:
    T RemoveHead();
};
template <class T> class BSList : public BSPointerListBase<T>
{
};

#endif
