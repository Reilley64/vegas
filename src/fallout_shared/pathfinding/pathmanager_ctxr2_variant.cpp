// fallout_shared/pathfinding/pathmanager_ctxr2_variant.cpp: free functions (1 function)

#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_006ea330_shell.h"
#include "fnv/decl/FUN_006eabe0_shell.h"
#include "fnv/decl/FUN_006eb790_shell.h"
#include "fnv/decl/FUN_006eb7b0_shell.h"
#include "fnv/decl/FUN_006eb7d0_shell.h"
#include "fnv/decl/FUN_006eb7f0_shell.h"
#include "fnv/decl/FUN_006ebde0_shell.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/Queue44c640.h"
#include "fnv/decl/TESForm.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005dc000.h"
#include "pathmanager_decls.h"
class BSSpinLock_r006eb6b0
{
  public:
};

class PathingActorData;

struct PathSlot
{
    int unk00;
    int unk04;
};

struct PathingRequest
{
};

struct PathWorkList
{
    int unk00[4];
    PathWorkList();
    ~PathWorkList();
};

struct PathIndex
{
};

struct FUN_006eb6b0_cls : public PathManagerImpl
{
    void FUN_006eb6b0(int id);
};

// @fnv 0x006eb6b0
void FUN_006eb6b0_cls::FUN_006eb6b0(int id)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>((reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)))->FUN_004538a0((int)("PathManagerImpl::CancelCurrentPathsAndPause"));
    PathingRequest* ref;
    int outA2;
    PathWorkList list3;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(list3))->FUN_006ebde0())
    {
        if (reinterpret_cast<::Queue44c640 *>((reinterpret_cast<PathIndex*>(reinterpret_cast<char*>(this) + 0x1480)))->TryGetNextEntry((::QueueIter44c640 *)(::PathWorkList *)(&list3), (void **)(::PathingRequest **)(&ref), (int)(&outA2), true))
        {
            if (reinterpret_cast<PathSlot*>(reinterpret_cast<::FUN_006c9900_shell *>((ref))->FUN_006c9900())->unk04 == id)
            {
                reinterpret_cast<PathSlot*>(reinterpret_cast<::FUN_006c9900_shell *>((ref))->FUN_006c9900())->unk04 = 0;
                reinterpret_cast<PathSlot*>(reinterpret_cast<::FUN_006c9900_shell *>((ref))->FUN_006c9900())->unk00 = 0;
            }
        }
    }
    reinterpret_cast<::ActorTaskManager *>((reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)))->WaitForTasksDuringRendering();
}
