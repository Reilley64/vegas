#pragma once

#include "havok/hkMemorySystem.h"

// Complete native owner for the retained free-list memory-system constructor.
struct FUN_00cd0a60 final : hkMemorySystem
{
    // No implicit publication. The startup owner installs this instance.
    FUN_00cd0a60();
    FUN_00cd0a60(havok::native_memory::Allocator& backing, int scratchBytes);
    ~FUN_00cd0a60() override;
    bool InitializeThreadRouter(hkMemoryRouter&, const char* name, int flags) override;
    void ThreadQuit(hkMemoryRouter&, int flags) override;
    hkMemoryRouter* MainInit(int scratchBytes, int flags, int solverBytes = 0);
    void MainQuit(int flags);
    // Terminal shutdown requires worker quiescence and released main allocations.
    bool TryMainQuit();
    hkMemoryRouter* MainInitBorrowed(void* stack, int bytes);

  private:
    void ReleaseScratch(hkMemoryRouter& router);
    havok::native_memory::AlignedAllocator backing;
    hkSystemMemoryAllocator heap;
    hkNativeSolverAllocator solver;
    int scratchBytes = 0;
    bool closing = false;
    std::mutex mutex;
    struct Record
    {
        hkNativeThreadMemory cache;
        hkMemoryRouter* router = nullptr;
        int scratchCapacity = 0;
    };
    std::array<Record, 32> records;
    hkMemoryRouter mainRouter;
};
