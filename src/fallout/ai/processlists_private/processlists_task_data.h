// Unit-private PC declarations from the public JohnnyGuitarNVSE Bethesda
// task-data, tasklet, message-queue and free-list headers. No implementations.
#ifndef FNV_PROCESSLISTS_PRIVATE_TASK_DATA_H
#define FNV_PROCESSLISTS_PRIVATE_TASK_DATA_H

#include "processlists_layout_support.h"
#include "processlists_sync.h"

class MobileObject;
class BSWin32TaskletGroupData;

class MobileObjectTaskletContext
{
  public:
    MobileObjectTaskletContext();
    MobileObjectTaskletContext(MobileObject* apObject);
    MobileObjectTaskletContext(unsigned int auiObjectCount);
    ~MobileObjectTaskletContext();
    enum Type
    {
        START = 0,
        EXECUTE = 1,
        END = 2
    };

    unsigned int eType;
    unsigned int uiObjectCount;
    MobileObject* pObject;
};

template <class T> class BSTFreeListElement
{
  public:
    BSTFreeListElement();
    ~BSTFreeListElement();

    unsigned char kRawElem[sizeof(T)];
    BSTFreeListElement<T>* pNext;

    void ConstructElem(const T& arItem);
    void DestructElem();
    T& Elem();
};

template <class T> class BSTFreeList
{
  public:
    BSTFreeList();
    virtual ~BSTFreeList();

    unsigned int m_uiLockState;
    BSTFreeListElement<T>* pFree;

    bool Allocate(BSTFreeListElement<T>*& apElement, const T& arItem);
    void Deallocate(BSTFreeListElement<T>*& apElement);
    void Lock();
    void Unlock();

  protected:
    void Init(unsigned int auiCount, BSTFreeListElement<T>* apElements);

  private:
    bool DoAllocate(BSTFreeListElement<T>*& apElement);
    void DoDeallocate(BSTFreeListElement<T>*& apElement);
};

template <class T, unsigned int ItemUpdateArray> class BSTStaticFreeList : public BSTFreeList<T>
{
  public:
    BSTStaticFreeList();
    virtual ~BSTStaticFreeList();
    BSTFreeListElement<T> kElems[ItemUpdateArray];
};
typedef BSTStaticFreeList<MobileObjectTaskletContext, 4096> ProcessListsMessagePool;

template <class T> class BSTMessageQueue
{
  public:
    BSTMessageQueue();
    virtual ~BSTMessageQueue();
    virtual bool Push(const T& arMessage) = 0;
    virtual bool TryPush(const T& arMessage) = 0;
    virtual bool Pop(T& arMessage) = 0;
    virtual bool TryPop(T& arMessage) = 0;
    virtual bool EnqueueMessage(const T& arMessage) = 0;
    virtual bool RemoveMessage(T& arMessage) = 0;
};

template <class T> class BSTCommonMessageQueue : public BSTMessageQueue<T>
{
  public:
    BSTCommonMessageQueue();
    virtual ~BSTCommonMessageQueue();

    LockPrimitive kLock;

    virtual bool Push(const T& arMessage);
    virtual bool TryPush(const T& arMessage);
    virtual bool Pop(T& arMessage);
    virtual bool TryPop(T& arMessage);
    virtual bool EnqueueMessage(const T& arMessage);
    virtual bool RemoveMessage(T& arMessage);
};

template <class T> class BSTCommonLLMessageQueue : public BSTCommonMessageQueue<T>
{
  public:
    BSTCommonLLMessageQueue(BSTFreeList<T>* apList);
    virtual ~BSTCommonLLMessageQueue();

    BSTFreeList<T>* pSizeClassFreeList;
    BSTFreeListElement<T>* pHead;
    BSTFreeListElement<T>** m_ppTailLink;

    virtual bool EnqueueMessage(const T& arMessage);
    virtual bool RemoveMessage(T& arMessage);
};

class BSTaskletData
{
  public:
    BSTaskletData();
    virtual ~BSTaskletData();
    virtual bool StartTaskThread();
    virtual void Process();
    virtual void OnComplete();

    bool m_bTaskYielded;

    void TaskYield();
};

class BSWin32TaskletData : public BSTaskletData
{
  public:
    BSWin32TaskletData();
    virtual ~BSWin32TaskletData();

    BSWin32TaskletGroupData* m_pTaskletGroupData;
    bool m_bFlagAfterTaskletGroup;
    LockPrimitive kTaskDataLock;
    BSWin32TaskletData* m_pTaskletData;
};

class MobileObjectTaskletData : public BSWin32TaskletData
{
  public:
    MobileObjectTaskletData(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual ~MobileObjectTaskletData();
    virtual void SetMobileObjectCount(unsigned int auiObjectCount);
    virtual void ProcessMobileObject(MobileObject* apObject);
    virtual void SetThreadNumber(unsigned int auiThreadNumber);

    BSSimpleList<MobileObject*>* pMobList;
    BSTCommonLLMessageQueue<MobileObjectTaskletContext> kMessageQueue;
    unsigned int MobileObjectTaskletState;
    unsigned int eType;
};

class DetectionTaskData : public MobileObjectTaskletData
{
  public:
    float m_fDetectionValue;
    int m_iDetectionState;
};

class AnimationTaskData : public MobileObjectTaskletData
{
};

class PackageUpdateTaskData : public MobileObjectTaskletData
{
  public:
    BSSimpleList<MobileObject*>* pPrevObjectList;
    unsigned int uiUpdatedCount;
    unsigned int uiSkippedCount;
};

class ActorUpdateTaskData : public MobileObjectTaskletData
{
  public:
    unsigned int uiRunCount;
};

class ActorsScriptTaskData : public MobileObjectTaskletData
{
  public:
    BSSimpleList<MobileObject*>* pPrevObjectList;
    unsigned int uiRunCount;
};

class MovementTaskData : public MobileObjectTaskletData
{
  public:
    unsigned int uiRunCount;
};

class ActorTaskManager
{
  public:
    DetectionTaskData kDetectionTaskData;
    AnimationTaskData kAnimationTaskData;
    PackageUpdateTaskData kPackageUpdateTaskData;
    ActorUpdateTaskData kActorUpdateTaskData;
    ActorsScriptTaskData kActorsScriptTaskData;
    MovementTaskData kMovementTaskData;
    BSTStaticFreeList<MobileObjectTaskletContext, 4096> kMessagePool;
    bool m_bTrailingManagerFlag;
};
#endif
