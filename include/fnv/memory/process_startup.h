#pragma once

// Startup of the process-lifetime g_memoryManager, as main runs it.
//
// The original manager is constructed by 0x00aa3880, which no recorded unit
// calls: it is the dynamic initializer of the global at 0x011f6238. That
// constructor is a shell over the original object and is never applied to the
// native owner, whose construction is constant initialization. Its startup
// statements are composed here instead, in the recorded order:
//
//   0x00aa39c0  heap startup 0x00866e00, fixed-pool startup 0x00866770, then
//               allocation context 0 on the calling thread;
//   0x00866690  the Bethesda Ni allocator, its options and the holder.
//
// Not composed, each for a stated reason in docs/native-engine-heaps.md: the
// page-file preflight, the legacy pool-table clear 0x00aa6840, the scrap heap
// object of 0x00aa58d0 and the last call of 0x00866690.
namespace fnv::memory
{
// Native policy, not recovered behaviour: main calls this explicitly instead
// of relying on dynamic-initializer order, and a refused stage is reported
// instead of continuing. Returns false when the heaps cannot be reserved, the
// pools cannot be created or the allocator cannot be published. Stages that
// did start stay started, so allocations made from them stay valid and a later
// call resumes at the refused stage. A call after success does nothing.
// Call it on the main thread before any other thread exists.
bool StartProcessMemory() noexcept;
bool ProcessMemoryStarted() noexcept;

// Retires what StartProcessMemory established, in reverse order: the Ni
// allocator publication, the fixed pools, then the heaps and the manager's
// remaining bootstrap blocks. Every client must already be detached: any block
// still held is gone afterwards. Source records no retirement of the manager,
// so main does not call this at exit; the manager serves static destructors
// until the process ends. StartProcessMemory may run again afterwards.
void RetireProcessMemory() noexcept;
}
