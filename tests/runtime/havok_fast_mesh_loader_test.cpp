#include "havok/NativePackfile.h"
#include "havok/PackfileResource.h"
#include "havok/NativeWorld.h"
#include "check.h"

#include <algorithm>
#include <bit>
#include <cstring>
#include <map>
#include <thread>

using namespace havok::serialize;
using namespace havok::fast_mesh;

struct Backing final : havok::native_memory::Allocator
{
    havok::native_memory::AlignedAllocator allocator;
    std::map<void*, std::size_t> live;
    std::vector<void*> freed;
    std::vector<void*> nativeAllocations;
    int allocations = 0;
    int failAfter = -1;
    bool throws = false;
    void* Allocate(std::size_t n) override
    {
        if (failAfter == 0) { if (throws) throw std::bad_alloc(); return nullptr; }
        if (failAfter > 0) --failAfter;
        auto* p = allocator.Allocate(n);
        if (p)
        {
            live.emplace(p, n);
            ++allocations;
            if (n == sizeof(FastMesh)) nativeAllocations.push_back(p);
        }
        return p;
    }
    void Free(void* p, std::size_t n) noexcept override
    {
        auto it = live.find(p);
        if (it == live.end() || it->second != n) std::abort();
        live.erase(it);
        freed.push_back(p);
        allocator.Free(p, n);
    }
    ~Backing() override { if (!live.empty()) std::abort(); }
};

#include "fast_mesh_fixture.h"

int main()
{
    Checks c("runtime.havok_fast_mesh_production_loader");
    auto backing = std::make_shared<Backing>();
    {
        Fixture fixture;
        TypeRegistry registry(7);
        hkEntryD479 metadata;
        metadata.name = "hkpFastMeshShape";
        metadata.size = 96; // recorded extent, deliberately not sizeof(FastMesh)
        registry.Register(&metadata);
        auto* resource = static_cast<fnv_00dc0f20::FUN_00dc0f20_cls*>(CreateResourceFromArray(
            fixture.input.data(), reinterpret_cast<void*>(fixture.input.size()), &registry));
        c.Equal("actual owning resource admits materialized native mesh", true, resource != nullptr);
        if (resource) resource->ReleaseReference();
    }
    for (int finishing : {0, 1, 7})
    {
        Fixture fixture(2);
        TypeRegistry types(finishing);
        hkEntryD479 metadata;
        metadata.name = "hkpFastMeshShape";
        metadata.size = 96;
        types.Register(&metadata);
        ClassNameRegistry classes;
        MemoryLoadStream input(fixture.input);
        LoadFormat format;
        format.version = "synthetic-native-world";
        format.layout = {std::byte{4}, std::byte{1}, std::byte{}, std::byte{}};
        LoadPolicy policy{format.version, format.layout, nullptr};
        LoadError error;
        auto* resource = FUN_00d48840(&input, format, &error, &classes, &types, policy);
        c.Equal("actual heap loader publishes constructed native-world resource", true, resource != nullptr);
        if (!resource) continue;
        auto root = resource->Root();
        c.Equal("native root has actual source C++ descriptor", true,
            &root->Class() == NativeFastMeshClass().descriptor);
        c.Equal("native descriptor extent is sizeof actual class, not recorded 96", int(sizeof(FastMesh)), root->Class().m_iObjectSize);
        c.Equal("native object identity is mesh address", true, root->Address() == root->Mesh().get());
        c.Equal("local alias shares native-world implementation", true, resource->Reference({0, 768}).operator->() == root.operator->());
        c.Equal("cross-section alias shares native-world implementation", true, resource->Reference({1, 32}).operator->() == root.operator->());
        c.Equal("second native object is separately constructed", false, resource->Object({0, 96})->Address() == root->Address());
        c.Equal("actual second finishing consumer returns native root", true,
            resource->Data().FUN_00e055f0("havok::fast_mesh::Shape", &types) == root->Address());
        c.Equal("second finishing is identity-idempotent", true,
            resource->Data().FUN_00e055f0("havok::fast_mesh::FastMesh", &types) == root->Address());
        c.Equal("serialized family name is not a native class alias", true,
            resource->Data().FUN_00e055f0("hkpFastMeshShape", &types) == nullptr);
        TypeRegistry wrongMode(finishing == 0 ? 1 : 0); wrongMode.Import(types);
        c.Equal("second finishing rejects a mode change on living object", true,
            resource->Data().FUN_00e055f0(nullptr, &wrongMode) == nullptr);
        std::fill(fixture.input.begin(), fixture.input.end(), std::byte{0xcc});
        ShutdownBuiltinRegistries();
        resource->AddReference(); resource->ReleaseReference();
        resource->ReleaseReference();
        Triangle triangle;
        c.Equal("root lease outlives resource/world/global shutdown/input overwrite", true, root->Mesh()->GetTriangle(0, triangle));
        c.Equal("retained root geometry is decoded native state", 2.0f, triangle.vertices[1].x);
    }
    LoadContext context;
    const char registeredType[] = "hkpFastMeshShape";
    context.registry = const_cast<char*>(registeredType);
    context.lookupType = [](void* registry, const char* name) -> const void*
    {
        // Synthetic registry metadata, not a replacement runtime provider or
        // executable callback. Native destruction never dispatches through it.
        return std::strcmp(static_cast<const char*>(registry), name) == 0 ? registry : nullptr;
    };
    context.supplier = backing;
    {
        Fixture fixture;
        PackfileResource resource(fixture.input, context);
        c.Equal("exact object retains native root identity", true, resource.Root().Mesh() == resource.Object({0, 0}).Mesh());
        for (int offset : {1, 8, 95})
        {
            bool rejected = false;
            try { rejected = !bool(resource.Object({0, offset})); }
            catch (const std::runtime_error&) { rejected = true; }
            c.Equal("direct object rejects interior native identity", true, rejected);
        }
        auto outside = resource.Object({0, 96});
        c.Equal("serialized data outside native extent remains borrowed", true, !outside.Mesh() && !outside.Serialized().empty());
    }
    for (int offset : {1, 8, 95})
    {
        Fixture fixture;
        Put(fixture.input, 28, offset);
        PackfileResource resource(fixture.input, context);
        c.Equal("interior root does not publish serialized native bytes", false, bool(resource.Root()));
        c.Equal("interior root records load rejection", false, resource.Error().empty());
        c.Equal("interior root unwinds native allocations", std::size_t{}, backing->live.size());
    }
    {
        Fixture fixture;
        c.Equal("fixture omits only the unused material-index pointer", true, fixture.SetLocalPointer(384 + 32, -1));
        auto unfinished = context;
        unfinished.finishing = 0;
        PackfileResource resource(fixture.input, unfinished);
        auto mesh = resource.Root().Mesh();
        c.Equal("finish zero accepts absent unused material indices", true, bool(mesh));
        c.Equal("finish zero has no unused-stream error", std::string{}, resource.Error());
        if (mesh)
        {
            c.Equal("finish zero preserves index type", 0u, mesh->Subpart(0).materialIndexType);
            c.Equal("absent unused indices remain empty", true, mesh->Subpart(0).materialIndices.empty());
            c.Equal("finish zero retains material storage", std::size_t{4}, mesh->Subpart(0).materials.size());
            c.Equal("finish zero does not invent material lookup", true, mesh->Material(0).empty());
        }
        PackfileResource finishing(fixture.input, context);
        c.Equal("finishing still requires its active index stream", false, bool(finishing.Root()));
        c.Equal("missing active index stream reports failure", false, finishing.Error().empty());
    }
    {
        Fixture fixture;
        auto unfinished = context;
        unfinished.finishing = 0;
        PackfileResource resource(fixture.input, unfinished);
        auto mesh = resource.Root().Mesh();
        c.Equal("finish zero with supplied unused indices materializes", true, bool(mesh));
        if (mesh) c.Equal("supplied unused index bytes remain owned", std::size_t{1}, mesh->Subpart(0).materialIndices.size());
    }
    for (unsigned indexType : {1u, 2u})
        for (unsigned stepIndices : {1u, 2u})
        {
            Fixture fixture;
            const unsigned width = indexType == 1 ? 2 : 4;
            const unsigned indices = 600;
            c.Equal("strip fixture redirects index stream", true, fixture.SetLocalPointer(384 + 12, indices));
            fixture.input[160 + 384 + 16] = std::byte(indexType);
            Put(fixture.input, 160 + 384 + 20, stepIndices * width);
            Put(fixture.input, 160 + 384 + 24, 1);
            Put(fixture.input, 160 + 384 + 28, 2);
            Put(fixture.input, 160 + 68, 2);
            for (unsigned i = 0; i < stepIndices + 3; ++i)
            {
                const unsigned index = i % 3;
                for (unsigned byte = 0; byte < width; ++byte)
                    fixture.input[160 + indices + i * width + byte] = std::byte((index >> (byte * 8)) & 255);
            }
            PackfileResource resource(fixture.input, context);
            auto mesh = resource.Root().Mesh();
            c.Equal("overlapping strip stream materializes", true, bool(mesh));
            c.Equal("overlapping strip stream has no error", std::string{}, resource.Error());
            if (mesh)
            {
                std::fill(fixture.input.begin(), fixture.input.end(), std::byte{0xff});
                resource.Cleanup();
                Triangle triangle;
                const bool found = mesh->GetTriangle(1, triangle);
                c.Equal("owned strip triangle survives cleanup", true, found);
                if (found)
                {
                    c.Equal("strip second triangle first x", stepIndices == 1 ? 2.0f : 0.0f, triangle.vertices[0].x);
                    c.Equal("strip second triangle first y", stepIndices == 1 ? 0.0f : 3.0f, triangle.vertices[0].y);
                    c.Equal("alternating strip triangle second x", stepIndices == 1 ? 0.0f : 2.0f, triangle.vertices[1].x);
                    c.Equal("alternating strip triangle third y", stepIndices == 1 ? 3.0f : 0.0f, triangle.vertices[2].y);
                }
            }
        }
    for (int malformed : {0, 1, 2})
    {
        Fixture fixture;
        if (malformed == 0) Put(fixture.input, 160 + 384 + 20, 0);
        if (malformed == 1) fixture.input[160 + 512] = std::byte{3};
        if (malformed == 2)
            c.Equal("truncated-stream fixture points at section end", true, fixture.SetLocalPointer(384 + 12, 1020));
        PackfileResource resource(fixture.input, context);
        c.Equal("invalid index stream remains rejected", false, bool(resource.Root()));
        c.Equal("invalid index stream records failure", false, resource.Error().empty());
        c.Equal("invalid index stream releases native prefix", std::size_t{}, backing->live.size());
    }
    {
        Fixture fixture;
        std::vector<std::max_align_t> output((PackfileEnvelopeSize() + sizeof(std::max_align_t) - 1) / sizeof(std::max_align_t));
        void* raw = UnpackPackfile(fixture.input.data(), reinterpret_cast<void*>(fixture.input.size()), output.data(),
            static_cast<int>(output.size() * sizeof(std::max_align_t)), &context);
        c.Equal("raw legacy entry never publishes a native-layout pointer", true, raw == nullptr);
        auto retained = PackfileRoot(output.data()).Mesh();
        c.Equal("actual unpack entry publishes typed root", true, bool(retained));
        FUN_00dc0de0(reinterpret_cast<S_00dc0de0*>(output.data()));
        std::vector<std::max_align_t>().swap(output);
        Triangle triangle;
        c.Equal("actual cleanup keeps retained native object valid", true, retained && retained->GetTriangle(0, triangle));
    }
    {
        Fixture fixture;
        auto invalid = context; invalid.lookupType = nullptr;
        PackfileResource unknown(fixture.input, invalid);
        c.Equal("unknown type cannot publish", false, bool(unknown.Root()));
        c.Equal("unknown type reports failure", false, unknown.Error().empty());
        invalid = context; invalid.supplier.reset();
        PackfileResource borrowed(fixture.input, invalid);
        c.Equal("missing owned supplier cannot publish", false, bool(borrowed.Root()));
        c.Equal("missing supplier reports failure", false, borrowed.Error().empty());
        // Global alias changed into an interior serialized-mesh pointer: there
        // is no valid native field identity to manufacture for this reference.
        const auto namesStart = Get(fixture.input, 132);
        Put(fixture.input, namesStart + 72, 8);
        PackfileResource interior(fixture.input, context);
        c.Equal("interior native alias rejected", false, bool(interior.Root()));
        c.Equal("interior alias error", false, interior.Error().empty());
        c.Equal("rejected alias releases native prefix", std::size_t{}, backing->live.size());
    }
    {
        Fixture fixture;
        Put(fixture.input, 160 + 56, 0); Put(fixture.input, 160 + 68, 0);
        PackfileResource empty(fixture.input, context);
        auto root = empty.Root().Mesh();
        c.Equal("empty serialized mesh materializes", true, bool(root));
        if (root) c.Equal("empty mesh subpart count", std::size_t{}, root->SubpartCount());
    }
    {
        Fixture fixture(2);
        const auto namesStart = Get(fixture.input, 132);
        const char other[] = "OtherShape";
        std::memcpy(fixture.input.data() + namesStart + 16, other, sizeof(other));
        const auto virtuals = Get(fixture.input, 96);
        Put(fixture.input, 160 + virtuals + 12 + 8, 16);
        PackfileResource mixed(fixture.input, context);
        c.Equal("unmigrated mixed publication refused", false, bool(mixed.Root()));
        c.Equal("mixed-family refusal is explicit", false, mixed.Error().empty());
        c.Equal("mixed-family refusal owns no native allocation", std::size_t{}, backing->live.size());
    }
    for (int finishing : {0, 1, 7})
    {
        Fixture fixture;
        context.finishing = finishing;
        PackfileResource resource(fixture.input, context); // calls actual UnpackPackfile
        auto root = resource.Root().Mesh();
        c.Equal("existing loader materializes native root", true, bool(root));
        c.Equal("loader error", std::string{}, resource.Error());
        if (!root) continue;
        c.Equal("root not a serialized/native cast", true, resource.Root().Serialized().empty());
        c.Equal("local alias", true, root == resource.Reference({0, 768}).Mesh());
        c.Equal("second local alias", true, root == resource.Reference({0, 772}).Mesh());
        c.Equal("global alias", true, root == resource.Reference({1, 32}).Mesh());
        c.Equal("shape finishing state", finishing ? 0x17u : 91u, root->ShapeType());
        c.Equal("collection finishing state", finishing ? 5u : 3u, root->CollectionType());
        c.Equal("material finishing state", finishing ? 1u : 0u, root->Subpart(0).materialIndexType);
        std::fill(fixture.input.begin(), fixture.input.end(), std::byte{0xff}); fixture.input.clear(); fixture.input.shrink_to_fit();
        resource.Cleanup(); // calls actual FUN_00dc0de0
        Triangle triangle;
        c.Equal("geometry after source/output release", true, root->GetTriangle(0, triangle));
        c.Equal("scaled vertex after cleanup", 2.0f, triangle.vertices[1].x);
        auto material = root->Subpart(0).materials;
        c.Equal("material storage after cleanup", std::size_t{4}, material.size());
        if (!material.empty()) c.Equal("material after cleanup", 42, std::to_integer<int>(material[0]));
        c.Equal("material lookup respects finish(0)", finishing != 0, !root->Material(0).empty());
        c.Equal("welding after cleanup", std::uint16_t(0x1234), triangle.welding);
    }
    {
        Fixture fixture(3, true);
        backing->nativeAllocations.clear(); backing->freed.clear();
        PackfileResource resource(fixture.input, context);
        c.Equal("partial-prefix load fails", false, bool(resource.Root()));
        c.Equal("failure reported", false, resource.Error().empty());
        c.Equal("completed prefix unwound", std::size_t{}, backing->live.size());
        c.Equal("two completed objects before third decode failure", std::size_t{2}, backing->nativeAllocations.size());
        if (backing->nativeAllocations.size() == 2)
            c.Equal("failed-prefix reverse cleanup", true,
                std::find(backing->freed.begin(), backing->freed.end(), backing->nativeAllocations[1]) <
                std::find(backing->freed.begin(), backing->freed.end(), backing->nativeAllocations[0]));
    }
    {
        Fixture fixture(3);
        PackfileResource resource(fixture.input, context);
        c.Equal("three-object load", std::string{}, resource.Error());
        auto first = resource.Object({0,0}).Mesh(), second = resource.Object({0,96}).Mesh(), third = resource.Object({0,192}).Mesh();
        c.Equal("distinct native identities", true, first && second && third && first != second && second != third);
        auto* a = first.get(); auto* b = second.get(); auto* d = third.get();
        first.reset(); second.reset(); third.reset();
        backing->freed.clear();
        resource.Cleanup();
        c.Equal("three-object reverse cleanup", true,
            std::find(backing->freed.begin(), backing->freed.end(), d) < std::find(backing->freed.begin(), backing->freed.end(), b) &&
            std::find(backing->freed.begin(), backing->freed.end(), b) < std::find(backing->freed.begin(), backing->freed.end(), a));
        c.Equal("resource cleanup exact extents", std::size_t{}, backing->live.size());
    }
    {
        // Null and throwing supplier failures at every successful allocation
        // position, including the third object's partially constructed streams.
        Fixture fixture(3);
        const int before = backing->allocations;
        { PackfileResource resource(fixture.input, context); }
        const int count = backing->allocations - before;
        for (bool throws : {false, true})
            for (int i = 0; i < count; ++i)
            {
                backing->throws = throws; backing->failAfter = i;
                PackfileResource resource(fixture.input, context);
                c.Equal("allocation failure unpublishes root", false, bool(resource.Root()));
                c.Equal("allocation failure reported", false, resource.Error().empty());
                c.Equal("partial native allocation unwound", std::size_t{}, backing->live.size());
                backing->failAfter = -1;
            }
        backing->throws = false;
    }
    {
        auto supplier = std::make_shared<Backing>();
        std::weak_ptr<Backing> weak = supplier;
        havok::native_memory::System memory(supplier, havok::native_memory::ScratchBytes{0});
        havok::native_memory::Router router;
        c.Equal("production owner attaches router", true, memory.Initialize(router));
        c.Equal("shutdown refuses attached router", false, memory.Shutdown());
        LoadContext owned = context;
        owned.supplier = memory.AcquireSupplier();
        Fixture fixture;
        Handle external;
        {
            PackfileResource resource(fixture.input, owned);
            external = resource.Root().Mesh();
            resource.Cleanup();
        }
        owned.supplier.reset(); supplier.reset();
        memory.Quit(router);
        c.Equal("production memory owner shutdown", true, memory.Shutdown());
        c.Equal("external handle keeps real supplier alive", false, weak.expired());
        bool refused = false;
        try { (void)memory.AcquireSupplier(); } catch (const std::logic_error&) { refused = true; }
        c.Equal("shutdown refuses new ownership leases", true, refused);
        c.Equal("shutdown refuses new workers", false, memory.Initialize(router));
        std::thread release([handle = std::move(external)]() mutable { handle.reset(); }); release.join();
        c.Equal("supplier destroyed only after final native Free", true, weak.expired());
    }
    return c.ExitCode();
}
