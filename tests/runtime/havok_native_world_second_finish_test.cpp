#include "havok/FastMesh.h"
#include "havok/NativeWorld.h"
#include "fnv/decl/FUN_00d472a0.h"
#include "havok/hkClassMember.h"
#include "fast_mesh_fixture.h"
#include "check.h"
#include <map>
#include <cstdlib>

namespace { std::ptrdiff_t allocationFailure = -1; }
void* operator new(std::size_t bytes)
{
    if (allocationFailure == 0) { allocationFailure = -1; throw std::bad_alloc(); }
    if (allocationFailure > 0) --allocationFailure;
    if (void* block = std::malloc(bytes ? bytes : 1)) return block;
    throw std::bad_alloc();
}
void* operator new[](std::size_t bytes) { return ::operator new(bytes); }
void operator delete(void* block) noexcept { std::free(block); }
void operator delete[](void* block) noexcept { std::free(block); }
void operator delete(void* block, std::size_t) noexcept { std::free(block); }
void operator delete[](void* block, std::size_t) noexcept { std::free(block); }
#include <new>
#include <stdexcept>

using namespace havok::serialize;
namespace
{
int constructions = 0, destructions = 0;
std::vector<int> cleanupOrder;
class Payload
{
public:
    Payload(int value, int finishing) : value(value), finishing(finishing)
    {
        if (value == -1) throw std::runtime_error("synthetic Payload constructor rejects value");
        ++constructions;
    }
    virtual ~Payload() { ++destructions; cleanupOrder.push_back(value); }
    int value, finishing;
};
struct DescriptorStorage
{
    char name[24] = "SyntheticPayload";
    char memberName[8] = "value";
    Payload exemplar{0, 0};
    hkClassMember member{};
    FUN_00d472a0 descriptor;
    DescriptorStorage() : descriptor(name, nullptr, sizeof(Payload), nullptr, 1,
        nullptr, 0, &member, 1, nullptr, nullptr, 0, 1)
    {
        member.m_name = memberName;
        member.m_type = hkClassMember::TYPE_INT32;
        member.m_offset = static_cast<hkUint16>(reinterpret_cast<const char*>(&exemplar.value) - reinterpret_cast<const char*>(&exemplar));
    }
};
struct Supplier final : havok::native_memory::Allocator
{
    havok::native_memory::AlignedAllocator allocator;
    std::map<void*, std::size_t> live;
    int failAfter = -1;
    void* Allocate(std::size_t size) override
    {
        if (failAfter == 0) return nullptr;
        if (failAfter > 0) --failAfter;
        void* block = allocator.Allocate(size);
        if (block)
        {
            try { live.emplace(block, size); }
            catch (...) { allocator.Free(block, size); throw; }
        }
        return block;
    }
    void Free(void* block, std::size_t size) noexcept override
    {
        auto found = live.find(block);
        if (found == live.end() || found->second != size) std::abort();
        live.erase(found); allocator.Free(block, size);
    }
    ~Supplier() override { if (!live.empty()) std::abort(); }
};
std::vector<std::byte> MixedFixture()
{
    Fixture mesh(2);
    const auto dataAt = Get(mesh.input, 84), namesAt = Get(mesh.input, 132);
    std::vector<std::byte> data(mesh.input.begin() + dataAt, mesh.input.begin() + namesAt);
    std::vector<std::byte> names(mesh.input.begin() + namesAt, mesh.input.end());
    std::memcpy(names.data() + 40, "SyntheticPayload", 17);
    const auto dl = Get(mesh.input, 88), dg = Get(mesh.input, 92), dv = Get(mesh.input, 96);
    Put(data, 608, 41);
    // Separate 12-byte serialized payload, not a native Payload/sizeof claim.
    Put(data, data.size(), 608); Put(data, data.size(), 1); Put(data, data.size(), 40);
    const auto de = data.size();
    auto record = [](auto& bytes, int offset, const char* name)
    {
        Put(bytes, bytes.size(), offset);
        const auto first = bytes.size(), size = (std::strlen(name) + 1 + 3) & ~std::size_t(3);
        bytes.resize(first + size); std::memcpy(bytes.data() + first, name, std::strlen(name) + 1);
    };
    record(data, 0, "mesh"); record(data, 608, "payload"); record(data, 0, "alias"); Put(data, data.size(), ~0u);
    const auto di = data.size(); record(data, 768, "hook"); Put(data, data.size(), ~0u);
    // Second section contains another serialized payload, a global alias and
    // its own real virtual/export/import records at different section offsets.
    names.insert(names.begin() + 64, 16, std::byte{});
    Put(names, 64, 77);
    const auto nl = 80u, ng = 80u, nv = 92u;
    Put(names, names.size(), 64); Put(names, names.size(), 1); Put(names, names.size(), 40);
    const auto ne = names.size(); record(names, 64, "other"); Put(names, names.size(), ~0u);
    const auto ni = names.size(); record(names, 32, "cross"); Put(names, names.size(), ~0u);
    std::vector<std::byte> bytes(mesh.input.begin(), mesh.input.begin() + 160);
    auto header = [&](int at, unsigned absolute, unsigned local, unsigned global, unsigned virtuals, unsigned exports, unsigned imports, unsigned end)
    {
        Put(bytes, at + 20, absolute); Put(bytes, at + 24, local); Put(bytes, at + 28, global);
        Put(bytes, at + 32, virtuals); Put(bytes, at + 36, exports); Put(bytes, at + 40, imports); Put(bytes, at + 44, end);
    };
    header(64, 160, dl, dg, dv, de, di, data.size());
    header(112, 160 + data.size(), nl, ng, nv, ne, ni, names.size());
    bytes.insert(bytes.end(), data.begin(), data.end()); bytes.insert(bytes.end(), names.begin(), names.end());
    return bytes;
}
hkEntryD479 PayloadMetadata(const std::shared_ptr<DescriptorStorage>& descriptor)
{
    hkEntryD479 metadata;
    metadata.name = descriptor->name;
    metadata.size = 12;
    metadata.SetNativeLayout<Payload>();
    metadata.nativeClass = &descriptor->descriptor;
    metadata.nativeClassStorage = descriptor;
    metadata.materialize = [](std::span<const std::byte> bytes, int finishing,
        std::shared_ptr<havok::native_memory::Allocator> supplier) -> std::shared_ptr<void>
    {
        if (bytes.size() != 12) throw std::runtime_error("synthetic Payload wire extent");
        unsigned value = 0;
        for (unsigned i = 0; i < 4; ++i) value |= std::to_integer<unsigned>(bytes[i]) << (i * 8);
        void* block = supplier->Allocate(sizeof(Payload));
        if (!block) throw std::bad_alloc();
        Payload* object;
        try { object = new (block) Payload(static_cast<int>(value), finishing); }
        catch (...) { supplier->Free(block, sizeof(Payload)); throw; }
        return std::shared_ptr<void>(object, [supplier](void* pointer)
        {
            static_cast<Payload*>(pointer)->~Payload(); supplier->Free(pointer, sizeof(Payload));
        });
    };
    return metadata;
}
ObjectResource* Load(std::vector<std::byte>& bytes, TypeRegistry& types, ClassNameRegistry& classes, LoadError& error)
{
    MemoryLoadStream input(bytes);
    LoadFormat format;
    format.version = "synthetic-mixed-world";
    format.layout = {std::byte{4}, std::byte{1}, std::byte{}, std::byte{}};
    LoadPolicy policy{format.version, format.layout, nullptr};
    return FUN_00d48840(&input, format, &error, &classes, &types, policy);
}
}
int main()
{
    Checks c("runtime.havok_native_world_second_finish");
    cleanupOrder.reserve(8192);
    auto supplier = std::make_shared<Supplier>();
    havok::native_memory::System system(supplier, havok::native_memory::ScratchBytes{0});
    InstallPackfileSupplier(system);
    for (int finishing : {0, 1, 7})
    {
        RootObject retained;
        std::weak_ptr<DescriptorStorage> descriptorLifetime;
        const int before = destructions;
        {
            auto descriptor = std::make_shared<DescriptorStorage>(); descriptorLifetime = descriptor;
            auto payload = PayloadMetadata(descriptor);
            hkEntryD479 mesh; mesh.name = "hkpFastMeshShape"; mesh.size = 96;
            TypeRegistry types(finishing); types.Register(&mesh); types.Register(&payload);
            ClassNameRegistry classes; classes.RegisterClass(&descriptor->descriptor, descriptor);
            auto bytes = MixedFixture(); LoadError error;
            auto* resource = Load(bytes, types, classes, error);
            c.Equal("synthetic Payload plus retained FastMesh mixed resource publishes", true, resource != nullptr);
            if (!resource) { std::fprintf(stderr, "%s\n", error.message.c_str()); continue; }
            auto exports = resource->Exports();
            auto imports = resource->Imports();
            c.Equal("both sections publish nonempty exports", std::size_t{4}, exports.size());
            c.Equal("both sections preserve explicit import locations", std::size_t{2}, imports.size());
            if (exports.size() == 4)
            {
                c.Equal("duplicate exported mesh shares actual implementation", true, exports[0].object.operator->() == exports[2].object.operator->());
                auto* one = static_cast<const Payload*>(exports[1].object->Address());
                auto* two = static_cast<const Payload*>(exports[3].object->Address());
                c.Equal("first generic allocating decoder value", 41, one->value);
                c.Equal("second-section generic allocating decoder value", 77, two->value);
                c.Equal("generic constructor receives exact finishing integer", finishing, one->finishing);
                c.Equal("generic descriptor actual native extent differs from wire", int(sizeof(Payload)), exports[1].object->Class().m_iObjectSize);
                retained = exports[1].object;
            }
            c.Equal("second consumer obtains root from actual producer", true,
                resource->Data().FUN_00e055f0("havok::fast_mesh::FastMesh", &types) == resource->Root()->Address());
            TypeRegistry incomplete(finishing); incomplete.Register(&mesh);
            c.Equal("second consumer validates all completed types, not just root", true,
                resource->Data().FUN_00e055f0(nullptr, &incomplete) == nullptr);
            std::fill(bytes.begin(), bytes.end(), std::byte{0xee});
            resource->AddReference(); resource->ReleaseReference(); resource->ReleaseReference();
            ShutdownBuiltinRegistries();
        }
        c.Equal("actual class/member/name storage survives registry destruction", false, descriptorLifetime.expired());
        if (retained)
        {
            c.Equal("native generic root survives source/input/world destruction", 41, static_cast<const Payload*>(retained->Address())->value);
            c.Equal("native generic descriptor remains readable", true, std::strcmp(retained->Class().m_name, "SyntheticPayload") == 0);
        }
        retained.FUN_00dba7f0();
        c.Equal("class descriptor lease released after final root", true, descriptorLifetime.expired());
        c.Equal("native generic final destruction includes exact two objects and exemplar", before + 3, destructions);
        c.Equal("all native supplier blocks freed", std::size_t{}, supplier->live.size());
    }
    {
        auto descriptor = std::make_shared<DescriptorStorage>();
        auto payload = PayloadMetadata(descriptor);
        TypeRegistry types(7); types.Register(&payload);
        ClassNameRegistry classes; auto bytes = MixedFixture(); LoadError error;
        const auto virtuals = Get(bytes, 96);
        for (unsigned i = 0; i < 3; ++i) Put(bytes, 160 + virtuals + i * 12, ~0u);
        Put(bytes, 28, 608); // no FastMesh virtual records: allocating Payload-only path
        auto* resource = Load(bytes, types, classes, error);
        c.Equal("explicit source decoder admits four-byte Payload-only representation", true, resource != nullptr);
        if (resource)
        {
            auto root = resource->Root();
            c.Equal("decoded Payload is not a cast of its twelve wire bytes", 41, static_cast<const Payload*>(root->Address())->value);
            c.Equal("second consumer uses shared generic production completion ledger", true,
                resource->Data().FUN_00e055f0("SyntheticPayload", &types) == root->Address());
            resource->ReleaseReference();
        }
    }
    // Fail every real supplier allocation until the complete mixed graph loads.
    int failedSites = 0;
    for (int failAfter = 0; failAfter != 64; ++failAfter)
    {
        auto descriptor = std::make_shared<DescriptorStorage>();
        auto payload = PayloadMetadata(descriptor);
        hkEntryD479 mesh; mesh.name = "hkpFastMeshShape"; mesh.size = 96;
        TypeRegistry types(7); types.Register(&mesh); types.Register(&payload);
        ClassNameRegistry classes; auto bytes = MixedFixture(); LoadError error;
        const auto before = supplier->live.size();
        supplier->failAfter = failAfter;
        auto* resource = Load(bytes, types, classes, error);
        supplier->failAfter = -1;
        if (resource) { resource->ReleaseReference(); break; }
        ++failedSites;
        c.Equal("allocation failure unwinds every partial native owner", before, supplier->live.size());
    }
    c.Equal("failure sweep reaches multiple actual allocations", true, failedSites > 3);
    {
        auto descriptor = std::make_shared<DescriptorStorage>();
        auto payload = PayloadMetadata(descriptor);
        hkEntryD479 mesh; mesh.name = "hkpFastMeshShape"; mesh.size = 96;
        TypeRegistry types(7); types.Register(&mesh); types.Register(&payload);
        ClassNameRegistry classes; auto bytes = MixedFixture(); LoadError error;
        Put(bytes, Get(bytes, 132) + 64, ~0u);
        cleanupOrder.clear();
        auto* failed = Load(bytes, types, classes, error);
        c.Equal("real second Payload constructor failure rejects mixed publication", true, failed == nullptr);
        if (failed) failed->ReleaseReference();
        c.Equal("failed constructor reports actual public diagnostic", true, error.status != 0 && error.message.find("constructor rejects") != std::string::npos);
        c.Equal("only successful generic prefix is destroyed", true, cleanupOrder == std::vector<int>{41});
        c.Equal("constructor exception frees its block and all completed prefix", std::size_t{}, supplier->live.size());
    }
    bool reachedSuccess = false;
    for (int site = 0; site != 256; ++site)
    {
        auto descriptor = std::make_shared<DescriptorStorage>();
        auto payload = PayloadMetadata(descriptor);
        hkEntryD479 mesh; mesh.name = "hkpFastMeshShape"; mesh.size = 96;
        TypeRegistry types(7); types.Register(&mesh); types.Register(&payload);
        ClassNameRegistry classes; auto bytes = MixedFixture(); LoadError error;
        const int built = constructions, destroyed = destructions;
        allocationFailure = site;
        auto* resource = Load(bytes, types, classes, error);
        allocationFailure = -1;
        if (resource) resource->ReleaseReference();
        c.Equal("C++ allocation unwind destroys exactly completed native Payloads", constructions - built, destructions - destroyed);
        c.Equal("C++ allocation unwind frees every supplying allocator block", std::size_t{}, supplier->live.size());
        if (resource) { reachedSuccess = true; std::printf("world C++ allocation sweep: %d failing sites before success\n", site); break; }
    }
    c.Equal("world C++ allocation sweep reaches complete production success", true, reachedSuccess);
    {
        auto descriptor = std::make_shared<DescriptorStorage>();
        auto payload = PayloadMetadata(descriptor);
        hkEntryD479 mesh; mesh.name = "hkpFastMeshShape"; mesh.size = 96;
        TypeRegistry types(7); types.Register(&mesh); types.Register(&payload);
        ClassNameRegistry classes; auto bytes = MixedFixture(); LoadError error;
        auto* resource = Load(bytes, types, classes, error);
        c.Equal("production world exists before supplier shutdown", true, resource != nullptr);
        RootObject retained = resource ? resource->Root() : RootObject{};
        ShutdownPackfileSupplier();
        c.Equal("native memory system shutdown permits outstanding supplier leases", true, system.Shutdown());
        if (resource) resource->ReleaseReference();
        havok::fast_mesh::Triangle triangle;
        c.Equal("root remains operational after supplier/system shutdown", true, retained && retained->Mesh()->GetTriangle(0, triangle));
        retained.FUN_00dba7f0();
        c.Equal("final destruction after shutdown frees supplier blocks", std::size_t{}, supplier->live.size());
    }
    bool rejected = false;
    try { (void)AcquirePackfileSupplier(); } catch (const std::runtime_error&) { rejected = true; }
    c.Equal("supplier shutdown prevents new packfile admission", true, rejected);
    return c.ExitCode();
}
