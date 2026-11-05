#pragma once

#include "havok/hkMemoryRouter.h"

#include <atomic>
#include <cstddef>
#include <cstdio>
#include <memory_resource>
#include <new>
#include <utility>
#include <vector>

namespace havok::base
{
using ErrorCallback = void (*)(const char*, void*);

// Each native reference remembers the allocator which must outlive it.
class Reference
{
  public:
    void AddReference();
    void RemoveReference();
    int GetReferenceCount() const { return references.load(); }
    Reference(const Reference&) = delete;
    Reference& operator=(const Reference&) = delete;

    template<class T, class... Args>
    static T* Create(hkMemoryAllocator& allocator, Args&&... args)
    {
        static_assert(alignof(T) <= 16 && sizeof(T) <= 0x7fffffff);
        void* storage = allocator.blockAlloc(sizeof(T));
        if (!storage)
            return nullptr;
        try { return new (storage) T(allocator, std::forward<Args>(args)...); }
        catch (...) { allocator.blockFree(storage, sizeof(T)); throw; }
    }
  protected:
    explicit Reference(hkMemoryAllocator& allocator) : allocator(allocator) {}
    virtual ~Reference() = default;
    virtual void Destroy() = 0;
    template<class T> void DestroyAs()
    {
        hkMemoryAllocator& supplyingAllocator = allocator;
        auto* object = static_cast<T*>(this);
        object->~T();
        supplyingAllocator.blockFree(object, sizeof(T));
    }
  private:
    hkMemoryAllocator& allocator;
    std::atomic<int> references{1};
};

class AllocatorResource final : public std::pmr::memory_resource
{
  public:
    explicit AllocatorResource(hkMemoryAllocator& allocator) : allocator(allocator) {}
  private:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* memory, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override
    { return this == &other; }
    hkMemoryAllocator& allocator;
};

class Error final : public Reference
{
  public:
    Error(hkMemoryAllocator& allocator, ErrorCallback callback, void* user);
    int Message(int mode, int id, const char* message, const char* file, int line);
    bool IsEnabled(int id) const;
    void SetEnabled(int id, bool enabled);
    void EnableAll();
    void BeginSection(int id, const char* name);
    void EndSection();
  private:
    void Destroy() override { DestroyAs<Error>(); }
    AllocatorResource resource;
    std::pmr::vector<int> disabled;
    std::pmr::vector<int> sections;
    ErrorCallback callback;
    void* user;
};

// Native files retain their supplying allocator, not a reconstructed stream view.
class File final : public Reference
{
  public:
    File(hkMemoryAllocator& allocator, std::FILE* handle);
    ~File() override;
    int Read(void* data, int bytes);
    int Write(const void* data, int bytes);
    bool Seek(long offset, int origin);
    long Tell() const;
    bool IsOk() const { return ok; }
  private:
    void Destroy() override { DestroyAs<File>(); }
    std::FILE* handle;
    bool ok = true;
    char buffer[4096];
};

class FileSystem final : public Reference
{
  public:
    explicit FileSystem(hkMemoryAllocator& allocator) : Reference(allocator), allocator(allocator) {}
    File* OpenReader(const char* name);
    File* OpenWriter(const char* name);
  private:
    File* Open(const char* name, const char* mode);
    void Destroy() override { DestroyAs<FileSystem>(); }
    hkMemoryAllocator& allocator;
};

// Native base-owner readiness only. Game singleton migration is a separate prerequisite.
bool IsInitialized();
Error* GetError();
FileSystem* GetFileSystem();
}

namespace fnv_00cbbb10
{
// Initializes complete native owners. It does not activate unmigrated singleton records.
int FUN_00cbbb10(hkMemoryRouter* router, havok::base::ErrorCallback callback, void* user);
}
int ShutdownIfInitialized();
