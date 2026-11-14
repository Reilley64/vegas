#pragma once

// The Gamebryo allocator interface, its two engine classes, the init options
// that select one, and the holder every Ni allocation entry dispatches through.
// Virtual tables are compiler-owned; no generated table supplies dispatch.
//
// The slot set and order follow the base table at 0x010a24d0 (ten slots: the
// destructor 0x00aa24a0 and nine pure calls). Slots 1 to 8 are declared from
// identified bodies and call sites. Slot 9 has no identified body or caller in
// either class and is not declared: native dispatch is by name, so an
// undeclared trailing slot changes no call.
//
// Event types are the engine's integers. Entries pass 1/2 (new), 3/4 (delete),
// 5, 7 (aligned), 9 and 10 (aligned) to slots 1 to 3, and 0xb to 0x10 to slots
// 4 to 6, where 0xd, 0xe and 0x10 are the aligned forms.
class NiAllocator
{
  public:
    // 0x00aa24a0
    virtual ~NiAllocator();
    // Slot 1.
    virtual void* Allocate(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                           bool provideAccurateSizeOnDeallocate, const char* file, int line,
                           const char* function) = 0;
    // Slot 2.
    virtual void Deallocate(void* memory, int eventType, unsigned int sizeInBytes) = 0;
    // Slot 3.
    virtual void* Reallocate(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                             bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file,
                             int line, const char* function) = 0;
    // Slot 4.
    virtual void* Alloc(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                        bool provideAccurateSizeOnDeallocate, const char* file, int line,
                        const char* function) = 0;
    // Slot 5.
    virtual void Free(void* memory, int eventType, unsigned int sizeInBytes) = 0;
    // Slot 6.
    virtual void* Realloc(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                          bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file,
                          int line, const char* function) = 0;
    // Slot 7. Called once per holder publication by 0x00aa2020.
    virtual void Initialize() = 0;
    // Slot 8. No caller is identified in source.
    virtual void Shutdown() = 0;
};

// Forwards to the canonical g_memoryManager. Has no state of its own.
class BSNiAllocator : public NiAllocator
{
  public:
    // 0x00aa2230
    BSNiAllocator();
    // 0x00aa2240
    void* Allocate(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                   bool provideAccurateSizeOnDeallocate, const char* file, int line,
                   const char* function) override;
    // 0x00aa22b0
    void Deallocate(void* memory, int eventType, unsigned int sizeInBytes) override;
    // 0x00aa22f0
    void* Reallocate(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                     bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file, int line,
                     const char* function) override;
    // 0x00aa2370
    void* Alloc(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                bool provideAccurateSizeOnDeallocate, const char* file, int line, const char* function) override;
    // 0x00aa23e0
    void Free(void* memory, int eventType, unsigned int sizeInBytes) override;
    // 0x00aa2420
    void* Realloc(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                  bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file, int line,
                  const char* function) override;
    // No body is identified for these two slots of this class. See the
    // definitions for the native policy.
    void Initialize() override;
    void Shutdown() override;
};

// Binds the recorded bodies as overrides. Its small-object pools are still the
// original 32-bit layout code, so this class is not yet usable natively.
class NiStandardAllocator : public NiAllocator
{
  public:
    // 0x00aa30c0
    void* Allocate(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                   bool provideAccurateSizeOnDeallocate, const char* file, int line,
                   const char* function) override;
    // 0x00aa3150
    void Deallocate(void* memory, int eventType, unsigned int sizeInBytes) override;
    // 0x00aa31b0
    void* Reallocate(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                     bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file, int line,
                     const char* function) override;
    // 0x00aa3300
    void* Alloc(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                bool provideAccurateSizeOnDeallocate, const char* file, int line, const char* function) override;
    // 0x00aa3370
    void Free(void* memory, int eventType, unsigned int sizeInBytes) override;
    // 0x00aa33a0
    void* Realloc(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                  bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file, int line,
                  const char* function) override;
    // 0x00aa3430
    void Initialize() override;
    // 0x00aa3460
    void Shutdown() override;
};

// The object DAT_011f6118 points to. It names the allocator the holder will
// publish and says whether retiring the options also deletes that allocator.
struct NiInitOptions
{
    NiAllocator* allocator;
    bool ownsAllocator;

    // 0x00aa2200: owns a new NiStandardAllocator.
    NiInitOptions();
    // 0x00aa21d0: uses the caller's allocator and does not own it.
    explicit NiInitOptions(NiAllocator* allocator);
    // 0x00aa21e0
    ~NiInitOptions();
};

// The object DAT_011f6080 points to. 0x00aa2020 is its only writer.
struct HolderB3718
{
    NiAllocator* allocator;
};

// 0x011f6080
extern HolderB3718* DAT_011f6080;
// 0x011f6118: null or a constructed NiInitOptions.
extern void* DAT_011f6118;

// 0x00aa2020
extern "C" void InitHolder();

namespace fnv::memory
{
// The allocator statements of the manager startup step 0x00866690: construct
// the Bethesda allocator and its options, then publish the holder. Call it
// after g_memoryManager's heap and fixed-pool startup. Throws std::bad_alloc
// when the manager cannot supply the allocator, its options or the holder;
// DAT_011f6118 and DAT_011f6080 then keep their previous values and nothing
// stays allocated.
void PublishManagerNiAllocator();

// Unpublishes the holder and the options, then returns the holder, the
// options and the allocator they name to g_memoryManager, in that order.
// Source records no such retirement; it exists for fnv::memory::
// RetireProcessMemory. Blocks still held by clients must already be freed.
// Holders and options that an earlier repeated publication left behind are
// not tracked, as recorded, and go with the manager's heaps.
void RetireManagerNiAllocator() noexcept;

// The fence in front of 0x00aa20b0's fallback. That entry builds options that
// own a NiStandardAllocator when none are published, and that allocator's
// small-object pools are still 32-bit layout code. Native policy, not
// recovered behaviour: Ni startup requires the options the manager startup
// published. Returns them, or terminates when there are none.
NiInitOptions* RequirePublishedNiOptions() noexcept;
}
