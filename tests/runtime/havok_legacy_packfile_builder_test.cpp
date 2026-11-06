#include "havok/NativeWorld.h"
#include "havok/ResourceStatistics.h"
#include "havok/SerializeEntry.h"
#include "fast_mesh_fixture.h"
#include "check.h"
#include <memory>
#include <algorithm>
#include <cstring>
#include <new>
#include <stdexcept>

using namespace havok::serialize;
namespace
{
struct RawNode { RawNode* next; int value; int mode; };
struct RawContract
{
    char name[16] = "NativeRawNode";
    hkClass type{name, nullptr, sizeof(RawNode), 0, {}, {}, nullptr, nullptr, hkClass::FLAGS_NOT_SERIALIZABLE, 0};
};
std::vector<int> cleaned;
int rawConstructions = 0;
std::vector<std::byte> RawFixture()
{
    std::vector<std::byte> bytes(360);
    Put(bytes, 0, 0x57e0e057); Put(bytes, 4, 0x10c0c010);
    bytes[16] = std::byte(sizeof(void*)); bytes[17] = std::byte{1};
    Put(bytes, 20, 1); Put(bytes, 24, 0); Put(bytes, 28, 0);
    // Explicit native RawNode storage, pointer fixup, three virtual records
    // (one alias), three exports and one import. No wire/native size inference.
    Put(bytes, 84, 112); Put(bytes, 88, 96); Put(bytes, 92, 104);
    Put(bytes, 96, 104); Put(bytes, 100, 140); Put(bytes, 104, 184); Put(bytes, 108, 200);
    Put(bytes, 112 + sizeof(void*), 41); Put(bytes, 144 + sizeof(void*), 77);
    std::memcpy(bytes.data() + 176, "NativeRawNode", 14);
    Put(bytes, 208, 0); Put(bytes, 212, 32);
    for (int i = 0; i != 3; ++i)
    {
        Put(bytes, 216 + i * 12, i == 1 ? 32 : 0);
        Put(bytes, 220 + i * 12, 0); Put(bytes, 224 + i * 12, 64);
    }
    for (int i = 0; i != 3; ++i)
    {
        Put(bytes, 252 + i * 12, i == 1 ? 32 : 0);
        std::memcpy(bytes.data() + 256 + i * 12, i == 0 ? "root" : i == 1 ? "other" : "alias", i == 0 ? 5 : 6);
    }
    Put(bytes, 288, ~0u);
    Put(bytes, 296, 0); std::memcpy(bytes.data() + 300, "hook", 5); Put(bytes, 308, ~0u);
    return bytes;
}
void RawQueries(Checks& c)
{
    for (int mode : {0, 1, 7})
    {
        RootObject retained;
        ObjectReference direct{{}, {}};
        std::weak_ptr<RawContract> lease;
        cleaned.clear(); rawConstructions = 0;
        {
            auto contract = std::make_shared<RawContract>(); lease = contract;
            hkEntryD479 metadata;
            metadata.name = contract->name; metadata.size = sizeof(RawNode); metadata.SetNativeLayout<RawNode>();
            metadata.nativeClass = &contract->type; metadata.nativeClassStorage = contract;
            metadata.m_func = [](void* pointer, int mode)
            {
                RawNode serialized;
                std::memcpy(&serialized, pointer, sizeof(serialized));
                new (pointer) RawNode{serialized.next, serialized.value, mode};
                ++rawConstructions;
            };
            metadata.cleanup = [](void* pointer)
            {
                auto* node = static_cast<RawNode*>(pointer);
                cleaned.push_back(node->value); std::destroy_at(node);
            };
            TypeRegistry types(mode); types.Register(&metadata);
            ClassNameRegistry classes; classes.RegisterClass(&contract->type, contract);
            S_Dom domain(classes); auto bytes = RawFixture(); LoadError error;
            S_PH source(std::shared_ptr<Resource>(static_cast<Resource*>(CreateResourceFromArray(
                bytes.data(), reinterpret_cast<void*>(bytes.size()), &types, &error)),
                [](Resource* resource) { if (resource) resource->ReleaseReference(); }));
            c.Equal("raw producer has real source native storage", true, bool(source.resource));
            if (source.resource) direct = source.resource->NativeObject({0, 32});
            auto* owner = FUN_00dc3300(&source, &domain);
            c.Equal("public legacy entry constructs raw native resource", true, owner != nullptr);
            if (!owner) continue;
            try
            {
                auto exports = owner->Exports(); auto imports = owner->Imports();
                c.Equal("raw native exports are not silently empty", std::size_t{3}, exports.size());
                c.Equal("raw native imports retain location", std::size_t{1}, imports.size());
                StatisticsSnapshot statistics(std::numeric_limits<std::size_t>::max(), true);
                owner->Data().WriteSections(&statistics);
                c.Equal("actual raw resource helper emits four ordered collector records", std::size_t{4}, statistics.Records().size());
                if (statistics.Records().size() == 4)
                {
                    c.Equal("nonempty raw exports reach real statistics receiver", true,
                        statistics.Records()[2].name == "exports" && !statistics.Records()[2].logical.empty());
                    c.Equal("nonempty raw imports reach real statistics receiver", true,
                        statistics.Records()[3].name == "imports" && !statistics.Records()[3].logical.empty());
                }
                if (exports.size() == 3)
                {
                    c.Equal("raw alias shares public root implementation", true, exports[0].object.operator->() == exports[2].object.operator->());
                    retained = exports[1].object;
                    c.Equal("raw object exact value", 77, static_cast<const RawNode*>(retained->Address())->value);
                    c.Equal("raw exact finish mode", mode, static_cast<const RawNode*>(retained->Address())->mode);
                    auto target = owner->Reference({0, 0});
                    c.Equal("raw typed reference uses explicit fixup", true, target.operator->() == retained.operator->());
                }
            }
            catch (const std::exception& failure) { std::fprintf(stderr, "%s\n", failure.what()); c.Equal("raw public native queries succeed", true, false); }
            S_00dc4710_Cls finishing(domain);
            auto* second = finishing.FUN_00dc4710(&source, &types, &error);
            c.Equal("retained finishing builder constructs the same resource family", true, second != nullptr);
            if (second) second->ReleaseReference();
            c.Equal("alias and second builder never repeat native construction", 2, rawConstructions);
            hkEntryD479 wrongLayout = metadata;
            wrongLayout.nativeSize = sizeof(int); wrongLayout.nativeAlignment = alignof(int);
            TypeRegistry wrongType(mode); wrongType.Register(&wrongLayout);
            c.Equal("same name cannot authorize a different native type contract", true,
                owner->FUN_00e055f0(nullptr, &wrongType) == nullptr);
            bool interiorRejected = false, unrecordedRejected = false;
            try { (void)owner->Object({0, 8}); } catch (const std::runtime_error&) { interiorRejected = true; }
            try { (void)owner->Reference({0, int(sizeof(void*))}); } catch (const std::runtime_error&) { unrecordedRejected = true; }
            c.Equal("raw interior address is not a constructed identity", true, interiorRejected);
            c.Equal("raw reference requires recorded fixup provenance", true, unrecordedRejected);
            TypeRegistry mismatch(mode == 7 ? 1 : 7); mismatch.Register(&metadata);
            auto* rejected = finishing.FUN_00dc4710(&source, &mismatch, &error);
            c.Equal("retained finishing builder rejects mismatched mode", true, rejected == nullptr && error.status != 0);
            if (rejected) rejected->ReleaseReference();
            source = S_PH{}; std::fill(bytes.begin(), bytes.end(), std::byte{0xee});
            owner->ReleaseReference();
        }
        c.Equal("raw descriptor survives producer retirement", false, lease.expired());
        if (retained) c.Equal("raw retained pointer survives all source owners", 77, static_cast<const RawNode*>(retained->Address())->value);
        retained.FUN_00dba7f0();
        c.Equal("standalone native query lease outlives world handles", true, cleaned.empty());
        c.Equal("standalone raw native query retains real storage", 77, static_cast<const RawNode*>(direct.NativeAddress())->value);
        direct = ObjectReference{{}, {}};
        c.Equal("raw final cleanup follows completed prefix in reverse once", true, cleaned == std::vector<int>({77, 41}));
        c.Equal("raw descriptor final lease releases", true, lease.expired());
    }
}
}
int main()
{
    Checks c("runtime.havok_legacy_packfile_builder");
    auto supplier = std::make_shared<havok::native_memory::AlignedAllocator>();
    havok::native_memory::System system(supplier, havok::native_memory::ScratchBytes{0});
    InstallPackfileSupplier(system);
    for (int mode : {0, 1, 7})
    {
        RootObject retained, bufferedRoot;
        {
            Fixture fixture(2);
            hkEntryD479 mesh; mesh.name = "hkpFastMeshShape"; mesh.size = 96;
            TypeRegistry types(mode); types.Register(&mesh);
            ClassNameRegistry classes;
            S_Dom domain(classes);
            LoadError error;
            {
                LoadPolicy policy;
                policy.layout[0] = std::byte{4}; policy.layout[1] = std::byte{1};
                SerializeOptions options{classes, types, policy};
                MemoryLoadStream source(fixture.input);
                ReplayLoadStream sequential({}, source);
                std::unique_ptr<S_Obj> publicEntry(FUN_00d48d30(&sequential, &error, &options));
                c.Equal("public serializer preserves actual supported binary-packfile branch", true,
                    publicEntry && publicEntry->Root()->Mesh() != nullptr);
                error.set(99, "stale buffer error");
                std::unique_ptr<S_Obj> buffered(fnv_00d48f00::FUN_00d48f00(fixture.input, &error, &options));
                c.Equal("buffer entry publishes the same native owner protocol", true,
                    buffered && buffered->Root()->Mesh() != nullptr && error.status == 0);
                if (buffered)
                {
                    bufferedRoot = buffered->Root();
                    c.Equal("buffer entry honors the supplied exact finishing mode", true,
                        buffered->FUN_00e055f0(nullptr, &types) == buffered->Root()->Address());
                    TypeRegistry wrongMode(mode == 7 ? 0 : 7); wrongMode.Register(&mesh);
                    c.Equal("buffer entry does not silently use default finishing", true,
                        buffered->FUN_00e055f0(nullptr, &wrongMode) == nullptr);
                }
                auto wrongPolicy = policy; wrongPolicy.version = "rejected-source-version";
                SerializeOptions rejected{classes, types, wrongPolicy};
                std::unique_ptr<S_Obj> badVersion(fnv_00d48f00::FUN_00d48f00(fixture.input, &error, &rejected));
                c.Equal("buffer entry honors supplied version policy and error output", true,
                    !badVersion && error.status != 0 && error.message.find("version") != std::string::npos);
                std::unique_ptr<S_Obj> truncated(fnv_00d48f00::FUN_00d48f00(
                    std::span<const std::byte>(fixture.input).first(4), &error, &options));
                c.Equal("buffer entry bounds header reads and reports truncation", true,
                    !truncated && error.status != 0 && !error.message.empty());
            }
            S_PH input(std::shared_ptr<Resource>(static_cast<Resource*>(CreateResourceFromArray(
                fixture.input.data(), reinterpret_cast<void*>(fixture.input.size()), &types, &error)),
                [](Resource* resource) { if (resource) resource->ReleaseReference(); }));
            S_Ctx context(domain);
            auto* owner = S_toResource(&context, &input, &error);
            c.Equal("real legacy builder constructs public resource", true, owner != nullptr);
            if (!owner) continue;
            retained = owner->Root();
            c.Equal("legacy builder publishes actual native mesh", true, bool(retained));
            c.Equal("retained second finish uses builder root", true,
                owner->Data().FUN_00e055f0("havok::fast_mesh::FastMesh", &types) == retained->Address());
            c.Equal("repeated exact finishing does not reconstruct object", true,
                owner->Data().FUN_00e055f0(nullptr, &types) == retained->Address());
            TypeRegistry mismatch(mode == 7 ? 1 : 7); mismatch.Register(&mesh);
            c.Equal("different finishing mode is rejected", true,
                owner->Data().FUN_00e055f0(nullptr, &mismatch) == nullptr);
            c.Equal("wrong native class is rejected", true,
                owner->Data().FUN_00e055f0("hkpFastMeshShape", &types) == nullptr);
            c.Equal("class lookup uses pointer-width object identity", true,
                owner->FUN_00e05140() == &retained->Class());
            auto same = owner->Object({0, 0});
            c.Equal("public object lookup reuses builder root implementation", true,
                same.operator->() == retained.operator->());
            input = S_PH{};
            std::fill(fixture.input.begin(), fixture.input.end(), std::byte{0xee});
            owner->AddReference(); owner->ReleaseReference(); owner->ReleaseReference();
            auto* failed = S_toResource(&context, &input, &error);
            c.Equal("reused context rejects an absent producer", true, failed == nullptr && error.status != 0);
        }
        havok::fast_mesh::Triangle triangle;
        c.Equal("root survives producer/domain/builder/resource retirement", true,
            retained && retained->Mesh()->GetTriangle(0, triangle));
        retained.FUN_00dba7f0();
        c.Equal("buffer root survives input/domain/public-owner retirement", true,
            bufferedRoot && bufferedRoot->Mesh()->GetTriangle(0, triangle));
        bufferedRoot.FUN_00dba7f0();
    }
    RawQueries(c);
    ShutdownPackfileSupplier();
    return c.ExitCode();
}
