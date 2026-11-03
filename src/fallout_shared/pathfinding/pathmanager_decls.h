// fallout_shared/pathfinding/pathmanager_decls.h: declares QueuedMessage, ActorPathingMessageQueue, NiMemObject, PathingSolution, Pathing and more

#include <new>
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/TESForm.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005dc000.h"
class WaitableObject;
class PathingRequest;
class ActorPathingMessageQueue;
class PathingSolution;

template <class T> class NiPointer;

template <> class NiPointer<WaitableObject>
{
  public:
    WaitableObject* m_pObject;
    NiPointer<WaitableObject>& operator=(const NiPointer<WaitableObject>&);
};

template <> class NiPointer<PathingRequest>
{
  public:
    PathingRequest* m_pObject;
    NiPointer();
    NiPointer(const NiPointer<PathingRequest>&);
    ~NiPointer();
    operator PathingRequest*() const;
};

template <> class NiPointer<ActorPathingMessageQueue>
{
  public:
    ActorPathingMessageQueue* m_pObject;
    NiPointer();
    NiPointer(const NiPointer<ActorPathingMessageQueue>&);
    ~NiPointer();
    operator ActorPathingMessageQueue*() const;
};

template <> class NiPointer<PathingSolution>
{
  public:
    PathingSolution* m_pObject;
    NiPointer();
    NiPointer(PathingSolution*);
    NiPointer(const NiPointer<PathingSolution>&);
    ~NiPointer();
    operator PathingSolution*() const;
    NiPointer<PathingSolution>& operator=(PathingSolution*);
};

enum PATHING_MESSAGE_TYPE
{
    PATHING_MESSAGE_TYPE_PMT_UNDEF = -1,
    PATHING_MESSAGE_TYPE_PMT_OK = 0,
    PATHING_MESSAGE_TYPE_PMT_ERROR = 1
};

class QueuedMessage
{
  public:
    int m_eMessageType;
    NiPointer<WaitableObject> m_pPathingSolution;
    QueuedMessage(PATHING_MESSAGE_TYPE type, const NiPointer<PathingSolution>& solution);
    ~QueuedMessage();
    QueuedMessage& operator=(const QueuedMessage&);
};

class ActorPathingMessageQueue
{
  public:
    virtual ~ActorPathingMessageQueue();
    virtual bool Push(const QueuedMessage& msg);
};

class NiMemObject
{
  public:
};

class PathingSolution : public NiMemObject
{
  public:
    char pad[0x44];
    PathingSolution();
};

class Pathing
{
  public:
    static bool BuildPath(PathingRequest* pRequest, PathingSolution* m_pOutputSolution);
};

class RecursiveSpinLock
{
  public:
public:
    void FUN_0040fba0();
};

class ParentSpaceNode;
template <class T, int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
};

class TESObjectREFR
{
  public:
    int pad;
    int state;
};

template <class T> class NiTNewInterface;

template <class T, class Allocator> class NiTArray
{
  public:
    T& GetAt(unsigned int);
};

struct Struct_004b0680
{
    int m_val;
    void* m_ptr;
    Struct_004b0680(int val, void* ptr);
    ~Struct_004b0680();
};

class PathingTaskData
{
  public:
    int pad00;
    bool bFlag04;
    char pad05[0x13];
    NiPointer<PathingRequest> m_pPathingRequest;
    NiPointer<PathingSolution> m_pPathingSolution;
    char pad20[0x40];
    NiPointer<ActorPathingMessageQueue> spQueue;

    bool HasPendingMessages();
    void Process();
};

class PerformanceMeasurement;
class PerformanceTimerManager
{
  public:
    PerformanceMeasurement* Register(char*, char*, bool, bool);
};

enum MEM_CONTEXT
{
    MEM_CONTEXT_DEFAULT = 0x2d
};

class AutoMemContext
{
  public:
    int m_eMemoryContext;
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};

class PathManagerImpl
{
  public:
    char pad[0xc34];
    bool unkc34;
    char padc35[0x88b];
    PathManagerImpl();
    bool BuildPath(NiPointer<PathingRequest> m_pPathingRequest, NiPointer<ActorPathingMessageQueue> spQueue);

};

union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    char* s;
};

class INISettingCollection;

template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};

class GlobalObject_0045cf30 : public SettingT<INISettingCollection>
{
};
extern GlobalObject_0045cf30 g_011d77cc;

struct DummyTimer
{
};

class PathManager
{
  public:
    PathManagerImpl* m_pPathManagerImpl;
    PerformanceTimerManager m_kPerformanceTimerManager;
    PathManager();
    bool Initialize();
    bool BuildPath(NiPointer<PathingRequest> m_pPathingRequest, NiPointer<ActorPathingMessageQueue> spQueue,
                   bool bAsync);

};

extern "C" char DAT_0103a1bc[];
extern "C" char DAT_0106d624[];
extern "C" char DAT_0106d560[];
