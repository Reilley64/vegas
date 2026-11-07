#pragma once

#include "havok/PackfileRegistry.h"
#include "runtime/havok_memory_prerequisite.h"
#include <span>
#include <string>

struct S_00dc0de0;
namespace havok::fast_mesh
{
class FastMesh;
using Handle = std::shared_ptr<const FastMesh>;
}

namespace havok::serialize
{
// Legacy operations remain supplied by their actual production owner. These are
// capabilities, not alternate implementations of registry or allocator entries.
struct LoadContext
{
    void* registry = nullptr;
    int finishing = 1;
    const void* (*lookupType)(void* registry, const char* className) = nullptr;
    std::shared_ptr<native_memory::Allocator> supplier;
    std::size_t legacyOutputBytes = 0;
    void* (*unpackLegacy)(void*, void*, void*, int, void*) = nullptr;
    void (*cleanupLegacy)(S_00dc0de0*) = nullptr;
    const TypeRegistry* nativeTypes = nullptr;
};

struct Location
{
    int section = -1;
    int offset = -1;
    bool operator==(const Location&) const = default;
};

// A reference explicitly separates a native mesh, another source-decoded native
// object, and serialized bytes. Serialized() never returns a native address.
// Serialized spans are borrowed until resource cleanup; native handles and their
// class-storage leases retain real C++ objects. Unmigrated raw consumers cannot
// accidentally receive a new C++ vtable/layout.
class ObjectReference
{
  public:
    const fast_mesh::Handle& Mesh() const noexcept { return mesh; }
    std::span<const std::byte> Serialized() const noexcept { return serialized; }
    explicit operator bool() const noexcept { return mesh || native || !serialized.empty(); }
    const void* NativeAddress() const noexcept { return mesh ? mesh.get() : native.get(); }
    const hkClass* NativeClass() const noexcept { return nativeClass; }
    const std::shared_ptr<const void>& ClassStorage() const noexcept { return classStorage; }
    ObjectReference(fast_mesh::Handle mesh, std::span<const std::byte> serialized)
        : mesh(std::move(mesh)), serialized(serialized) {}
    ObjectReference(std::shared_ptr<void> native, const hkClass* type, std::shared_ptr<const void> storage)
        : classStorage(std::move(storage)), native(std::move(native)), nativeClass(type) {}
  private:
    fast_mesh::Handle mesh;
    std::span<const std::byte> serialized;
    std::shared_ptr<const void> classStorage; // outlives native final destruction
    std::shared_ptr<void> native;
    const hkClass* nativeClass = nullptr;
};

std::size_t PackfileEnvelopeSize() noexcept;
bool HasNativeObjects(const void* output) noexcept;
bool PackfileFailed(const void* output) noexcept;
void* LegacyPackfileBuffer(void* output) noexcept;
ObjectReference PackfileRoot(const void* output);
const void* PackfileRootTypeInfo(const void* output) noexcept;
struct CompletedIdentity
{
    const void* object;
    std::string serializedType;
    int finishing;
    // Exact supplied representation contract, not a name/size-to-layout guess.
    // A later registry may not authorize a differently described native type.
    bool hasType = false;
    int recordedSize = 0;
    std::size_t nativeSize = 0, nativeAlignment = 0;
    const hkClass* nativeClass = nullptr;
    const void* vtable = nullptr;
    void CaptureType(const hkEntryD479* type) noexcept
    {
        if (!type) return;
        hasType = true; recordedSize = type->size;
        nativeSize = type->nativeSize; nativeAlignment = type->nativeAlignment;
        nativeClass = type->nativeClass; vtable = type->vtable;
    }
    bool Accepts(const hkEntryD479* type) const noexcept
    {
        return hasType && type && recordedSize == type->size && nativeSize == type->nativeSize &&
            nativeAlignment == type->nativeAlignment && nativeClass == type->nativeClass && vtable == type->vtable;
    }
};
// Shared by the production producer and second consumer. A record is appended
// only after real construction succeeds; representation-specific owners retain
// cleanup and allocation contracts. Aliases never create another completion.
struct CompletionLedger { std::vector<CompletedIdentity> objects; };
std::shared_ptr<const CompletionLedger> PackfileCompletions(const void* output);
struct SymbolLocation { std::string name; Location location; };
std::vector<SymbolLocation> PackfileSymbols(const void* output, bool imports);
ObjectReference PackfileObject(const void* output, Location);
ObjectReference PackfileReference(const void* output, Location pointerField);
std::string PackfileError(const void* output);

// Typed resource/result boundary. Its buffer is serializer storage, never a
// prefixed native mesh allocation. Cleanup is the actual loader cleanup entry.
class PackfileResource
{
  public:
    PackfileResource(std::span<const std::byte> input, LoadContext);
    ~PackfileResource();
    PackfileResource(const PackfileResource&) = delete;
    PackfileResource& operator=(const PackfileResource&) = delete;
    ObjectReference Root() const;
    ObjectReference Object(Location) const;
    ObjectReference Reference(Location) const;
    std::string Error() const;
    void Cleanup() noexcept;
  private:
    // max_align_t gives the in-buffer owner its genuine native alignment.
    std::vector<std::max_align_t> buffer;
};
}

// The existing unpack entry now takes an explicit context. The only old caller
// constructs it from the real registry and passes the genuine legacy closure.
// No old finish callback is cast to an allocating native producer.
extern "C" void* UnpackPackfile(void*, void*, void*, int, havok::serialize::LoadContext*) noexcept;
void FUN_00dc0de0(S_00dc0de0*);

// Reads the finishing integer in the actual registry owner, without invoking or
// substituting its void(void*, int) finish callback.
int PackfileRegistryFinishing(void* registry) noexcept;
const void* PackfileRegistryTypeInfo(void* registry, const char* className);
