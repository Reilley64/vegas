#pragma once

#include <array>
#include <cstddef>
#include <mutex>
#include <memory>

// Isolated native ownership operations, not installed game types or release layouts.
// No solver/cache contract or thread-local publication is supplied here.
namespace havok::native_memory
{
// Allocation returns null or throws on failure. Successful blocks are 16-byte aligned.
// Free is nonthrowing and requires the original block and exact requested extent.
// Implementations must support concurrent calls and outlive every System using them.
class Allocator
{
  public:
    virtual ~Allocator() = default;
    virtual void* Allocate(std::size_t bytes) = 0;
    virtual void Free(void* block, std::size_t bytes) noexcept = 0;
};

class AlignedAllocator final : public Allocator
{
  public:
    void* Allocate(std::size_t bytes) override;
    void Free(void* block, std::size_t bytes) noexcept override;
};

struct ScratchBytes
{
    std::size_t value;
};

class System;

// One worker exclusively uses each router. Initialize/quit on that worker, then
// join it before destroying the System. Destroying an attached router is fatal.
class Router
{
  public:
    Router() = default;
    ~Router();
    Router(const Router&) = delete;
    Router& operator=(const Router&) = delete;
    bool IsInitialized() const noexcept { return owner != nullptr; }
    Allocator& heap() const noexcept;
    // Positive extents consume a 16-byte-aligned start, without rounding the extent.
    // Zero/overflow/exhaustion returns null and leaves the cursor unchanged.
    void* AllocateStack(std::size_t bytes) noexcept;

    // Nested scopes restore the saved cursor, including alignment padding.
    // Scopes must end in LIFO order before scratch release or router quit.
    class StackScope
    {
      public:
        explicit StackScope(Router& router) noexcept;
        ~StackScope();
        StackScope(const StackScope&) = delete;
        StackScope& operator=(const StackScope&) = delete;
      private:
        friend class Router;
        Router& router;
        StackScope* previous;
        std::size_t saved;
    };

  private:
    friend class System;
    System* owner = nullptr;
    Allocator* allocator = nullptr;
    std::size_t slot = 0;
    void* stack = nullptr;
    std::size_t stackBytes = 0;
    std::size_t cursor = 0;
    bool ownsStack = false;
    StackScope* scope = nullptr;
};

// Controller owns this by value; workers receive a direct reference, never a
// registry lookup. 32 is a bounded admission choice, not a whole-game guarantee.
// All routers must quit and workers join before destruction; violation is fatal.
class System
{
  public:
    explicit System(Allocator& allocator, ScratchBytes workerScratch) noexcept;
    // Owned mode is used by serializer resources with native retained objects.
    // A borrowed-router/reference constructor cannot produce an owning lease.
    explicit System(std::shared_ptr<Allocator> allocator, ScratchBytes workerScratch);
    std::shared_ptr<Allocator> AcquireSupplier();
    // Refuse shutdown with attached workers; successful shutdown stops new
    // admission/leases. Already acquired suppliers survive through final Free.
    bool Shutdown() noexcept;
    ~System();
    System(const System&) = delete;
    System& operator=(const System&) = delete;
    // Reserves a record before allocating configured scratch. Null/exception
    // rolls back the reservation; exceptions propagate. Zero config is heap-only.
    bool Initialize(Router& router);
    // Borrowed storage remains caller-owned/alive through release. Require a
    // nonempty, 16-byte-aligned region. Invalid input changes no router state.
    bool InitializeBorrowed(Router& router, void* stack, std::size_t bytes);
    void ReleaseScratch(Router& router) noexcept;
    // Idempotent when detached. Wrong owner, live scopes and corrupt record state
    // are fatal invariants. Cleanup is nonthrowing, not an ordinary failure path.
    void Quit(Router& router) noexcept;

  private:
    bool Reserve(Router& router);
    void Cleanup(Router& router, bool releaseRecord) noexcept;
    std::shared_ptr<Allocator> ownedAllocator;
    Allocator& allocator;
    bool stopped = false;
    const ScratchBytes workerScratch;
    std::mutex mutex;
    struct Record { bool occupied = false; };
    std::array<Record, 32> records{};
};
}
