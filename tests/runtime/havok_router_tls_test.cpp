#include "check.h"
#include "fnv/symbols_00c85000.h"

#include <barrier>
#include <thread>

namespace
{
bool Matches(void* value)
{
    return FUN_00c85750() == value && fnv_00c85760::FUN_00c85760() == value;
}

void PointerAndClear(Checks& checks)
{
    checks.Equal("initial router is absent", true, Matches(nullptr));
    int router = 7;
    SetThreadLocalValue(&router);
    checks.Equal("both getters return the installed pointer", true, Matches(&router));
    SetThreadLocalValue(nullptr);
    checks.Equal("explicit clear reaches both getters", true, Matches(nullptr));
    checks.Equal("clearing does not change the pointee", 7, router);
}

void ThreadIsolation(Checks& checks)
{
    int controllerRouter = 11;
    int workerRouter = 19;
    bool initial = false;
    bool installed = false;
    bool cleared = false;
    std::barrier rendezvous(2);
    SetThreadLocalValue(&controllerRouter);
    std::thread worker([&] {
        initial = Matches(nullptr);
        SetThreadLocalValue(&workerRouter);
        installed = Matches(&workerRouter);
        rendezvous.arrive_and_wait();
        rendezvous.arrive_and_wait();
        cleared = Matches(&workerRouter);
        SetThreadLocalValue(nullptr);
        cleared = cleared && Matches(nullptr);
    });
    rendezvous.arrive_and_wait();
    checks.Equal("worker install does not replace controller router", true, Matches(&controllerRouter));
    SetThreadLocalValue(nullptr);
    rendezvous.arrive_and_wait();
    worker.join();
    checks.Equal("new worker starts absent", true, initial);
    checks.Equal("worker getters agree", true, installed);
    checks.Equal("controller clear does not clear worker router", true, cleared);
    checks.Equal("worker clear does not replace controller router", true, Matches(nullptr));
}

void ExitDoesNotOwnRouter(Checks& checks)
{
    int destructions = 0;
    struct Router
    {
        int& destructions;
        ~Router() { ++destructions; }
    };
    {
        Router router{destructions};
        bool installed = false;
        std::thread worker([&] {
            SetThreadLocalValue(&router);
            installed = Matches(&router);
        });
        worker.join();
        checks.Equal("exiting worker installed the router", true, installed);
        checks.Equal("thread exit does not destroy its router pointee", 0, destructions);
        bool fresh = false;
        std::thread next([&] { fresh = Matches(nullptr); });
        next.join();
        checks.Equal("later thread starts without a stale router", true, fresh);
    }
    checks.Equal("only the caller destroys the router", 1, destructions);
}
}

int main()
{
    Checks checks("runtime.havok_router_tls");
    checks.Run("pointer and explicit clear", [&] { PointerAndClear(checks); });
    checks.Run("thread isolation", [&] { ThreadIsolation(checks); });
    checks.Run("nonowning thread exit", [&] { ExitDoesNotOwnRouter(checks); });
    return checks.ExitCode();
}
