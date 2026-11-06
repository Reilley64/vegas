#include "havok/PackfileResource.h"
#include "havok/Dictionary.h"
#include "havok/NativeWorld.h"
#include "havok/PackfileLoad.h"
#include "havok/PackfileTypeInfo.h"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <new>
#include <cstdio>
#include <cstring>
#include <memory>
#include <limits>
#include <exception>
#include <stdexcept>
#include <string_view>
#include <vector>

// Fail real C++ allocation sites, without replacing a router, vtable, registry
// or allocator provider. The production aligned buffer allocator remains real.
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

namespace
{
int failures = 0;
void Check(bool condition, const char* field)
{
    if (!condition) { std::fprintf(stderr, "FAIL: %s\n", field); ++failures; }
}
struct Sample { void* pointer; int value; int finishing; };
std::vector<void*> finished, cleaned;
void Finish(void* object, int finishing)
{
    auto& sample = *static_cast<Sample*>(object);
    sample.finishing = finishing;
    finished.push_back(object);
}
void Cleanup(void* object) { cleaned.push_back(object); }
void FinishPointerToken(Sample* object, void* finishing)
{
    object->finishing = static_cast<int>(reinterpret_cast<std::intptr_t>(finishing));
    finished.push_back(object);
}
void FinishUnsigned(Sample* object, unsigned int finishing)
{
    object->finishing = static_cast<int>(finishing);
    finished.push_back(object);
}
void FinishNativeWord(Sample* object, std::intptr_t finishing)
{
    object->finishing = static_cast<int>(finishing);
    finished.push_back(object);
}
void FinishWithoutFlag(Sample* object)
{
    object->finishing = 91;
    finished.push_back(object);
}
void CleanupTyped(Sample* object) { cleaned.push_back(object); }
int CleanupReturningStatus(Sample* object)
{
    cleaned.push_back(object);
    return 37;
}
void ThrowFinish(void*, int) { throw std::runtime_error("synthetic finishing failure"); }
void Put(std::vector<std::byte>& bytes, std::size_t at, int value)
{
    for (unsigned i = 0; i < 4; ++i) bytes.at(at + i) = std::byte(static_cast<unsigned>(value) >> (8 * i));
}
void Label(std::vector<std::byte>& bytes, std::size_t at, const char* name)
{
    std::memcpy(bytes.data() + at, name, std::strlen(name) + 1);
}
struct Fixture
{
    std::vector<std::byte> bytes = std::vector<std::byte>(512);
    Fixture()
    {
        Put(bytes, 0, 0x57e0e057); Put(bytes, 4, 0x10c0c010);
        bytes[16] = std::byte(sizeof(void*)); bytes[17] = std::byte{1};
        Put(bytes, 20, 2); Put(bytes, 24, 0); Put(bytes, 28, 0);
        // Section zero: 64 data bytes, one local, one global, and three
        // virtual fixups (including a repeated exact identity).
        Header(64, 160, 64, 72, 84, 120, 152, 168);
        Put(bytes, 160 + 64, 0); Put(bytes, 160 + 68, 32);
        Put(bytes, 160 + 72, 16); Put(bytes, 160 + 76, 1); Put(bytes, 160 + 80, 0);
        for (int i = 0; i < 3; ++i)
        {
            Put(bytes, 160 + 84 + i * 12, i == 1 ? 16 : 0);
            Put(bytes, 160 + 88 + i * 12, 1); Put(bytes, 160 + 92 + i * 12, 32);
        }
        Put(bytes, 168, 41); Put(bytes, 184, 42); Put(bytes, 200, 43);
        Record(160 + 120, 0, "root"); Record(160 + 132, 32, "other"); Put(bytes, 160 + 144, -1);
        Record(160 + 152, 16, "bridge"); Put(bytes, 160 + 164, -1);
        // Section one has different stream offsets and base identity.
        Header(112, 336, 64, 64, 64, 64, 80, 96);
        Put(bytes, 344, 91); Label(bytes, 368, "SyntheticSample");
        Record(400, 0, "second"); Put(bytes, 412, -1);
        Record(416, 0, "import2"); Put(bytes, 428, -1);
    }
    void Header(std::size_t at, int absolute, int local, int global, int virtuals, int exports, int imports, int end)
    {
        Put(bytes, at + 20, absolute); Put(bytes, at + 24, local); Put(bytes, at + 28, global);
        Put(bytes, at + 32, virtuals); Put(bytes, at + 36, exports); Put(bytes, at + 40, imports); Put(bytes, at + 44, end);
    }
    void Record(std::size_t at, int offset, const char* name) { Put(bytes, at, offset); Label(bytes, at + 4, name); }
    void* Size() const { return reinterpret_cast<void*>(bytes.size()); }
};
using Resource = fnv_00dc0f20::FUN_00dc0f20_cls;
void Registry()
{
    int destroyed = 0;
    struct ObservedRegistry final : havok::serialize::TypeRegistry
    {
        explicit ObservedRegistry(int& destroyed) : destroyed(destroyed) {}
        ~ObservedRegistry() override { ++destroyed; }
        int& destroyed;
    };
    auto* heap = new ObservedRegistry(destroyed);
    constexpr unsigned maximum = std::numeric_limits<unsigned short>::max();
    for (unsigned i = 1; i < maximum; ++i) heap->AddReference();
    Check(heap->references == maximum, "heap registry retains exactly through maximum live count");
    for (unsigned i = 1; i < maximum; ++i) heap->ReleaseReference();
    Check(destroyed == 0 && heap->references == 1, "high reference releases do not destroy outstanding heap owner");
    heap->ReleaseReference();
    Check(destroyed == 1, "last heap registry reference destroys exactly once");
    auto& process = havok::serialize::DefaultPackfileRegistry();
    const auto initial = process.references;
    for (unsigned i = initial; i < maximum; ++i) process.AddReference();
    for (unsigned i = initial; i < maximum; ++i) process.ReleaseReference();
    Check(process.references == initial && &process == &havok::serialize::DefaultPackfileRegistry(),
        "high static registry retains/releases preserve canonical static owner");
    try
    {
        struct Leases
        {
            ObservedRegistry* owner;
            unsigned count = 1;
            ~Leases() { while (count--) owner->ReleaseReference(); }
        } leases{new ObservedRegistry(destroyed)};
        while (leases.count != maximum) { leases.owner->AddReference(); ++leases.count; }
        throw std::runtime_error("synthetic high-reference unwind");
    }
    catch (const std::runtime_error&) {}
    Check(destroyed == 2, "high-reference exception unwind releases exactly one real heap owner");
    auto metadata = std::make_unique<hkEntryD479>();
    *metadata = {"SyntheticSample", Finish, Cleanup, nullptr, sizeof(Sample)};
    metadata->SetNativeLayout<Sample>();
    Check(reinterpret_cast<std::uintptr_t>(metadata.get()) > UINT32_MAX, "metadata actually above 32 bits");
    std::printf("real registry metadata=%p\n", static_cast<void*>(metadata.get()));
    for (int finish : {0, 1, 7})
    {
        havok::serialize::TypeRegistry registry(finish);
        registry.Register(metadata.get());
        Check(PackfileRegistryFinishing(&registry) == finish, "actual caller registry exact finishing");
        Check(PackfileRegistryTypeInfo(&registry, "SyntheticSample") == metadata.get(), "metadata pointer identity");
        Check(registry.FUN_00d479e0("SyntheticSample") == metadata.get(), "actual owner lookup identity");
        Sample object{};
        finished.clear();
        Check(registry.FindEntryAndCall(&object, const_cast<char*>("SyntheticSample")) == metadata.get(), "actual finish returns metadata");
        Check(object.finishing == finish && finished == std::vector<void*>{&object}, "actual finish callback exact integer/receiver");
        havok::serialize::TypeRegistry unfinished(0);
        unfinished.Import(registry);
        Check(unfinished.finish == 0 && PackfileRegistryTypeInfo(&unfinished, "SyntheticSample") == metadata.get(), "actual unfinished import preserves state and metadata");
        Check(PackfileRegistryTypeInfo(&registry, "missing") == nullptr, "missing metadata remains missing");
    }
}
void GeneratedMetadata()
{
    alignas(64) const char auxiliary[64] = "source metadata auxiliary";
    // This is the actual class constructed by aggregate_initializers_o2.cpp,
    // with source-owned payload callbacks instead of original object families.
    Agg6 producer("SyntheticSample", Finish, Cleanup, nullptr, auxiliary,
        reinterpret_cast<const void*>(16));
    auto* metadata = producer.Metadata();
    metadata->SetNativeLayout<Sample>();
    Check(metadata->size == 16, "generated producer preserves sixth-element size");
    Check(metadata->auxiliary == auxiliary, "generated producer preserves auxiliary identity separately");
    for (int finish : {0, 1, 7})
    {
        Fixture fixture;
        havok::serialize::TypeRegistry registry(finish);
        registry.Register(metadata);
        finished.clear(); cleaned.clear();
        havok::serialize::MemoryLoadStream input(fixture.bytes);
        havok::serialize::LoadFormat format;
        format.version = "synthetic-source-version";
        format.layout = {std::byte(sizeof(void*)), std::byte{1}, std::byte{}, std::byte{}};
        havok::serialize::LoadPolicy policy{format.version, format.layout, nullptr};
        havok::serialize::LoadError error;
        auto* resource = havok::serialize::FUN_00d48760(input, format, &error, registry, policy);
        Check(resource != nullptr, "generated producer through actual loader caller");
        if (!resource) continue;
        auto* root = static_cast<Sample*>(resource->contents(nullptr, nullptr));
        Check(root && root->value == 41 && root->finishing == finish,
            "generated producer exact finishing and root data");
        Check(resource->TypeInfo() && resource->TypeInfo() != metadata && resource->TypeInfo()->auxiliary == auxiliary,
            "resource owns generated metadata values independently of registration lifetime");
        std::fill(fixture.bytes.begin(), fixture.bytes.end(), std::byte{0xee});
        resource->ReleaseReference();
        Check(cleaned == std::vector<void*>({finished[1], finished[0]}),
            "generated callback cleanup uses exact completed identities");
    }
    Check(std::string_view(metadata->name) == "SyntheticSample" && metadata->vtable == nullptr,
        "generated native fields preserve name and vtable identity");
    // Together with producer above, these are all seven compiler-observed
    // finish/cleanup signature pairings from the existing registrations.
    Agg6 pointerToken("SyntheticSample", FinishPointerToken, CleanupTyped, nullptr, auxiliary,
        reinterpret_cast<const void*>(16));
    Agg6 noFlag("SyntheticSample", FinishWithoutFlag, CleanupTyped, nullptr, auxiliary,
        reinterpret_cast<const void*>(16));
    Agg6 intResult("SyntheticSample", Finish, CleanupReturningStatus, nullptr, auxiliary,
        reinterpret_cast<const void*>(16));
    Agg6 noFlagResult("SyntheticSample", FinishWithoutFlag, CleanupReturningStatus, nullptr, auxiliary,
        reinterpret_cast<const void*>(16));
    Agg6 unsignedFlag("SyntheticSample", FinishUnsigned, CleanupTyped, nullptr, auxiliary,
        reinterpret_cast<const void*>(16));
    Agg6 nativeWord("SyntheticSample", FinishNativeWord, CleanupTyped, nullptr, auxiliary,
        reinterpret_cast<const void*>(16));
    for (int finishing : {0, 1, 7})
        for (auto* source : {&pointerToken, &noFlag, &intResult, &noFlagResult, &unsignedFlag, &nativeWord})
        {
            Fixture input;
            Resource* resource = nullptr;
            finished.clear(); cleaned.clear();
            {
                havok::serialize::TypeRegistry transient(finishing);
                source->Metadata()->SetNativeLayout<Sample>();
                transient.Register(source->Metadata());
                resource = static_cast<Resource*>(CreateResourceFromArray(input.bytes.data(), input.Size(), &transient));
            }
            std::fill(input.bytes.begin(), input.bytes.end(), std::byte{0xee});
            Check(resource != nullptr, "generated typed provider and transient registry");
            if (!resource) continue;
            auto* root = static_cast<Sample*>(resource->contents(nullptr, nullptr));
            Check(root && root->finishing == (source == &noFlag || source == &noFlagResult ? 91 : finishing),
                "actual declared provider signature retains finishing semantics");
            resource->ReleaseReference();
            Check(cleaned == std::vector<void*>({finished[1], finished[0]}),
                "typed generated cleanup survives registry and input release");
        }
    Agg6 oversized("SyntheticSample", Finish, Cleanup, nullptr, auxiliary,
        reinterpret_cast<const void*>(65));
    havok::serialize::TypeRegistry registry(7); registry.Register(oversized.Metadata());
    Fixture fixture;
    finished.clear(); cleaned.clear();
    Check(!CreateResourceFromArray(fixture.bytes.data(), fixture.Size(), &registry),
        "generated real size rejects object larger than section");
    Check(finished.empty() && cleaned.empty(), "generated size validation precedes callbacks");
}
void Resources()
{
    auto metadata = std::make_unique<hkEntryD479>();
    *metadata = {"SyntheticSample", Finish, Cleanup, nullptr, sizeof(Sample)};
    metadata->SetNativeLayout<Sample>();
    for (int finish : {0, 1, 7})
    {
        Fixture fixture;
        havok::serialize::TypeRegistry registry(finish); registry.Register(metadata.get());
        finished.clear(); cleaned.clear();
        havok::serialize::MemoryLoadStream input(fixture.bytes);
        havok::serialize::LoadFormat format;
        format.version = "synthetic-source-version";
        format.layout = {std::byte(sizeof(void*)), std::byte{1}, std::byte{}, std::byte{}};
        havok::serialize::LoadPolicy policy{format.version, format.layout, nullptr};
        havok::serialize::LoadError error;
        auto* resource = havok::serialize::FUN_00d48760(input, format, &error, registry, policy);
        Check(resource != nullptr, "actual CreateResourceFromArray");
        if (!resource) continue;
        auto* enumeration = static_cast<FUN_00dc0ed0_class*>(resource);
        auto* getter = static_cast<FUN_00dc0ec0_cls*>(resource);
        Check(dynamic_cast<Resource*>(enumeration) == resource, "actual constructed export receiver RTTI");
        auto* root = static_cast<Sample*>(getter->FUN_00dc0ec0(0, 0));
        Check(reinterpret_cast<std::uintptr_t>(root) > UINT32_MAX, "resource root above 32 bits");
        Check(root == resource->contents(nullptr, &registry), "same-resource root getters");
        Check(root && root->value == 41 && root->finishing == finish, "actual caller exact finishing");
        Check(resource->TypeInfo() && resource->TypeInfo()->size == sizeof(Sample) &&
            reinterpret_cast<std::uintptr_t>(resource->TypeInfo()) > UINT32_MAX, "owned resource metadata above 32 bits preserved");
        std::printf("actual loader caller finish=%d metadata=%p root=%p\n", finish,
            static_cast<const void*>(resource->TypeInfo()), static_cast<void*>(root));
        Check(resource->name() && std::string_view(resource->name()) == "SyntheticSample", "resource class name");
        Check(finished.size() == 2 && finished[0] == root && finished[1] != root,
            "duplicate virtual identity has exactly one real finish and cleanup owner");
        Check(root && static_cast<Sample*>(root->pointer)->value == 43, "actual local pointer fixup");
        auto* secondObject = static_cast<Sample*>(finished.at(1));
        Check(secondObject->pointer && static_cast<Sample*>(secondObject->pointer)->value == 91, "actual cross-section pointer identity");
        std::fill(fixture.bytes.begin(), fixture.bytes.end(), std::byte{0xcc});
        ExportList<ExportRecord, ExportAlloc> exports;
        hkArrayE030<RangeE030> imports;
        enumeration->FUN_00dc0ed0(reinterpret_cast<intptr_t>(&imports), reinterpret_cast<intptr_t>(&exports));
        Check(exports.entries.size() == 3 && imports.entries.size() == 2, "actual nonempty export/import entry");
        if (exports.entries.size() == 3 && imports.entries.size() == 2)
        {
            Check(std::string_view(exports.entries[0].name) == "root" && exports.entries[0].object == root, "export section-zero root identity");
            Check(std::string_view(exports.entries[1].name) == "other" && exports.entries[1].object == root->pointer, "export local identity");
            Check(std::string_view(exports.entries[2].name) == "second" && exports.entries[2].object == secondObject->pointer, "export section-one identity");
            Check(std::string_view(imports.entries[0].m_iStart) == "bridge" && imports.entries[0].m_iFirstValue == secondObject, "import section-zero pointer width");
            Check(std::string_view(imports.entries[1].m_iStart) == "import2" && imports.entries[1].m_iFirstValue == secondObject->pointer, "import section-one identity");
        }
        resource->FUN_00dc0f20();
        Check(cleaned == std::vector<void*>({finished[1], finished[0]}), "actual destructor reverse exact-pointer cleanup");
        Check(!resource->FUN_00dc0ec0(0, 0) && !resource->TypeInfo(), "destructor clears root and metadata");
        resource->FUN_00dc0ef0(); resource->FUN_00dc0f20();
        resource->FUN_00dc0ed0(reinterpret_cast<intptr_t>(&imports), reinterpret_cast<intptr_t>(&exports));
        Check(cleaned.size() == 2, "idempotent cleanup/destruction");
        delete resource;
    }
    Fixture fixture;
    havok::serialize::TypeRegistry registry(7); registry.Register(metadata.get());
    cleaned.clear(); finished.clear();
    auto* resource = static_cast<Resource*>(CreateResourceFromArray(fixture.bytes.data(), fixture.Size(), &registry));
    Check(resource != nullptr, "reference-count lifetime create");
    if (resource)
    {
        resource->AddReference(); resource->ReleaseReference();
        Check(cleaned.empty(), "reference retains actual resource");
        resource->ReleaseReference();
        Check(cleaned.size() == 2, "last reference invokes actual destructor");
    }
    // Failure after one successful finish must clean that prefix. The throwing
    // callback itself has not constructed a successfully finished object.
    auto throwing = *metadata; throwing.name = "Throws"; throwing.m_func = ThrowFinish;
    registry.Register(&throwing);
    Label(fixture.bytes, 336 + 48, "Throws"); Put(fixture.bytes, 160 + 104, 48);
    cleaned.clear(); finished.clear();
    Check(!CreateResourceFromArray(fixture.bytes.data(), fixture.Size(), &registry), "real finish exception refuses publication");
    Check(finished.size() == 1 && cleaned == finished, "real finish failure unwinds completed prefix");
    for (bool invalidMagic : {true, false})
    {
        Fixture rejected;
        if (invalidMagic) Put(rejected.bytes, 0, 0);
        else
        {
            Label(rejected.bytes, 336 + 48, "Throws"); Put(rejected.bytes, 160 + 104, 48);
        }
        havok::serialize::MemoryLoadStream input(rejected.bytes);
        havok::serialize::LoadFormat format;
        format.version = "failure-diagnostic";
        format.layout = {std::byte(sizeof(void*)), std::byte{1}, std::byte{}, std::byte{}};
        havok::serialize::LoadPolicy policy{format.version, format.layout, nullptr};
        havok::serialize::LoadError error;
        finished.clear(); cleaned.clear();
        auto* failed = havok::serialize::FUN_00d48760(input, format, &error, registry, policy);
        Check(!failed && error.status != 0 && !error.message.empty(), "actual public rejected load reports failure status and diagnostic");
        if (!invalidMagic) Check(finished.size() == 1 && cleaned == finished, "public second-object failure cleans only completed prefix");
        if (failed) failed->ReleaseReference();
    }
    Fixture invalid;
    Put(invalid.bytes, 64 + 44, 0x7fffffff);
    Check(!CreateResourceFromArray(invalid.bytes.data(), invalid.Size(), &registry), "bad section allocation extent fails");
    Check(!CreateResourceFromArray(nullptr, nullptr, &registry), "null input fails");
    Fixture narrow;
    narrow.bytes[16] = std::byte{4};
    Check(!CreateResourceFromArray(narrow.bytes.data(), narrow.Size(), &registry), "unmigrated narrow pointer fields safely refused");

    havok::serialize::TypeRegistry missing(1);
    Fixture unknown;
    resource = static_cast<Resource*>(CreateResourceFromArray(unknown.bytes.data(), unknown.Size(), &missing));
    Check(!resource, "unregistered root cannot publish an unconstructed native object");
    if (resource) resource->ReleaseReference();
    // A malformed retained record is not reported as an empty successful list.
    Fixture badRecord;
    Put(badRecord.bytes, 160 + 120, 1000);
    resource = static_cast<Resource*>(CreateResourceFromArray(badRecord.bytes.data(), badRecord.Size(), &registry));
    Check(resource != nullptr, "record validation resource create");
    if (resource)
    {
        ExportList<ExportRecord, ExportAlloc> exports;
        bool threw = false;
        try { resource->FUN_00dc0ed0(0, reinterpret_cast<intptr_t>(&exports)); }
        catch (const std::runtime_error&) { threw = true; }
        Check(threw && exports.entries.empty(), "actual export reader rejects bad identity");
        resource->ReleaseReference();
    }
    Fixture lifetimeFixture;
    {
        havok::serialize::TypeRegistry transient(7); transient.Register(metadata.get());
        resource = static_cast<Resource*>(CreateResourceFromArray(lifetimeFixture.bytes.data(), lifetimeFixture.Size(), &transient));
    }
    lifetimeFixture.bytes.clear();
    Check(resource && resource->TypeInfo() && resource->TypeInfo()->size == sizeof(Sample), "owned resource metadata outlives registry and serialized input");
    if (resource)
    {
        ExportList<ExportRecord, ExportAlloc> exports;
        resource->FUN_00dc0ed0(0, reinterpret_cast<intptr_t>(&exports));
        Check(exports.entries.size() == 3 && exports.entries[0].object == resource->contents(nullptr, nullptr), "retained export identities survive registry release");
        resource->ReleaseReference();
    }
    // Default lookup uses the same genuinely constructed production owner.
    auto& defaults = havok::serialize::DefaultPackfileRegistry();
    defaults.clear(); defaults.Register(metadata.get());
    Fixture defaultFixture;
    resource = static_cast<Resource*>(CreateResourceFromArray(defaultFixture.bytes.data(), defaultFixture.Size(), nullptr));
    Check(resource && resource->TypeInfo() && resource->TypeInfo()->size == sizeof(Sample), "actual default registry/loader owns metadata values");
    if (resource) resource->ReleaseReference();
    defaults.clear();

    finished.reserve(64); cleaned.reserve(64);
    bool reachedSuccess = false;
    for (std::ptrdiff_t site = 0; site < 64; ++site)
    {
        Fixture input;
        finished.clear(); cleaned.clear();
        allocationFailure = site;
        resource = static_cast<Resource*>(CreateResourceFromArray(input.bytes.data(), input.Size(), &registry));
        allocationFailure = -1;
        if (resource) resource->ReleaseReference();
        std::vector<void*> expected;
        for (void* object : finished)
            if (std::find(expected.begin(), expected.end(), object) == expected.end()) expected.push_back(object);
        std::reverse(expected.begin(), expected.end());
        Check(cleaned == expected, "real allocation failure releases every completed finish");
        if (resource)
        {
            std::printf("real caller allocation failure sweep: %td failed sites before success\n", site);
            reachedSuccess = true; break;
        }
    }
    Check(reachedSuccess, "real allocation failure sweep reaches successful allocation");
    Fixture callerFixture;
    havok::serialize::LoadFormat callerFormat;
    callerFormat.version = "synthetic-source-version";
    callerFormat.layout = {std::byte(sizeof(void*)), std::byte{1}, std::byte{}, std::byte{}};
    havok::serialize::LoadPolicy callerPolicy{callerFormat.version, callerFormat.layout, nullptr};
    havok::serialize::LoadError error;
    havok::serialize::MemoryLoadStream mismatch(callerFixture.bytes);
    auto wrong = callerFormat; wrong.layout[0] = std::byte{4};
    Check(!havok::serialize::FUN_00d48760(mismatch, wrong, &error, registry, callerPolicy) &&
        error.status == 3 && mismatch.Tell() == 0, "actual caller rejects mismatched layout before reading");
    reachedSuccess = false;
    for (std::ptrdiff_t site = 0; site < 64; ++site)
    {
        havok::serialize::MemoryLoadStream input(callerFixture.bytes);
        finished.clear(); cleaned.clear();
        allocationFailure = site;
        resource = havok::serialize::FUN_00d48760(input, callerFormat, &error, registry, callerPolicy);
        allocationFailure = -1;
        if (resource) resource->ReleaseReference();
        std::vector<void*> expected;
        for (void* object : finished)
            if (std::find(expected.begin(), expected.end(), object) == expected.end()) expected.push_back(object);
        std::reverse(expected.begin(), expected.end());
        Check(cleaned == expected, "actual loader caller allocation failure unwind");
        if (resource)
        {
            std::printf("actual loader caller allocation sweep: %td failed sites before success\n", site);
            reachedSuccess = true; break;
        }
    }
    Check(reachedSuccess, "actual caller allocation sweep completes");
}
void RetainedReflectionContents(int finishing, int cleanup)
{
    using namespace havok::serialize;
    ObjectReference retained{{}, {}}, alias{{}, {}};
    RootObject worldRoot;
    std::weak_ptr<const void> classStorage;
    Resource* resource = nullptr;
    std::shared_ptr<const void> registration;
    {
        ClassNameRegistry classes;
        TypeRegistry types(finishing);
        registration = dictionary::RegisterReflectionTypes(classes, types);
        // Authored wire holds a real native hkClass, not a reflected wire-size
        // guess or a replacement constructor/cleanup provider.
        const auto nameOffset = (sizeof(hkClass) + 15) & ~std::size_t(15);
        const auto dataBytes = nameOffset + 16;
        const auto end = dataBytes + 12;
        std::vector<std::byte> bytes(112 + end);
        Put(bytes, 0, 0x57e0e057); Put(bytes, 4, 0x10c0c010);
        bytes[16] = std::byte(sizeof(void*)); bytes[17] = std::byte{1};
        Put(bytes, 20, 1); Put(bytes, 84, 112);
        for (unsigned at : {88, 92, 96}) Put(bytes, at, static_cast<int>(dataBytes));
        for (unsigned at : {100, 104, 108}) Put(bytes, at, static_cast<int>(end));
        Label(bytes, 112 + nameOffset, "hkClass");
        Put(bytes, 120 + dataBytes, static_cast<int>(nameOffset));
        LoadError error;
        resource = static_cast<Resource*>(CreateResourceFromArray(bytes.data(),
            reinterpret_cast<void*>(bytes.size()), &types, &error));
        Check(resource != nullptr, "actual reflection producer publishes native resource");
        if (!resource) return;
        retained = resource->NativeContents();
        alias = resource->NativeObject({0, 0});
        Check(retained.NativeClass() == classes.Find("hkClass") &&
            retained.NativeAddress() == alias.NativeAddress(), "real native class and object aliases agree");
        classStorage = retained.ClassStorage();
        static_cast<hkClass*>(resource->contents(nullptr, nullptr))->m_iObjectSize = 73;
        resource->AddReference();
        auto owner = std::shared_ptr<Resource>(resource, [](Resource* value) { value->ReleaseReference(); });
        hkDataWorldNative world(owner, classes);
        worldRoot = world.Root();
    }
    registration.reset();
    auto copy = retained;
    if (cleanup)
    {
        for (int repeat = 0; repeat < 2; ++repeat)
        {
            if (cleanup != 2) resource->FUN_00dc0ef0();
            if (cleanup != 1) resource->FUN_00dc0f20();
        }
        Check(!resource->contents(nullptr, nullptr) && !resource->TypeInfo() &&
            !resource->NativeContents().NativeAddress(), "explicit cleanup retires resource publication");
    }
    resource->ReleaseReference();
    Check(worldRoot && static_cast<const hkClass*>(worldRoot->Address())->m_iObjectSize == 73 &&
        std::string_view(worldRoot->Class().m_name) == "hkClass", "real native-world root survives resource retirement");
    worldRoot.FUN_00dba7f0();
    Check(!classStorage.expired() && retained.NativeClass() &&
        std::string_view(retained.NativeClass()->m_name) == "hkClass", "native class lease survives all public owners");
    Check(static_cast<const hkClass*>(retained.NativeAddress())->m_iObjectSize == 73,
        "retained real native object survives explicit resource cleanup");
    retained = {{}, {}}; copy = {{}, {}};
    Check(static_cast<const hkClass*>(alias.NativeAddress())->m_iObjectSize == 73,
        "separately acquired native alias retains the same real object");
    alias = {{}, {}};
    Check(classStorage.expired(), "final native lease retires real reflection class storage");
}
}
int main(int argc, char** argv)
{
    const std::string_view mode = argc > 1 ? argv[1] : "all";
    if (mode == "retain-overflow-heap" || mode == "retain-overflow-static")
    {
        std::set_terminate([] { std::_Exit(0); });
        auto* owner = mode == "retain-overflow-heap" ? new havok::serialize::TypeRegistry : &havok::serialize::DefaultPackfileRegistry();
        for (unsigned i = owner->references; i < std::numeric_limits<unsigned short>::max(); ++i) owner->AddReference();
        owner->AddReference();
        std::_Exit(73); // reaching here means bounded-retain protection failed
    }
    for (const char* child : {"retain-overflow-heap", "retain-overflow-static"})
    {
        const std::string command = std::string("\"") + argv[0] + "\" " + child;
        Check(std::system(command.c_str()) == 0, "actual static/heap registry retain overflow terminates before wrapping");
    }
    if (mode != "resource") { Registry(); GeneratedMetadata(); }
    if (mode != "registry")
    {
        Resources();
        for (int finishing : {0, 1, 7})
            for (int cleanup : {0, 1, 2, 3}) RetainedReflectionContents(finishing, cleanup);
    }
    if (!failures) std::puts("real registry/resource closure PASS");
    return failures ? 1 : 0;
}
