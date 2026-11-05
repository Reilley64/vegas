#pragma once

#include "fnv/decl/FUN_00cd0a60.h"

#include <memory>

// The game owns this memory system, including every router's supplying allocator.
class HavokPhysicsMemory
{
  public:
    hkMemoryRouter* Initialize(void* borrowedStack, int bytes);
    FUN_00cd0a60* GetSystem() const { return system.get(); }
    // Call only after the worker controller has stopped and joined its workers.
    // A false result retains the entire owner and its outstanding allocations.
    bool Shutdown();
  private:
    std::unique_ptr<FUN_00cd0a60> system;
};

extern HavokPhysicsMemory g_havokPhysicsMemory;
