#include "havok/Dictionary.h"
#include "havok/ResourceStatistics.h"
#include "havok/hkClassMember.h"
#include "havok/hkClassEnum.h"
#include "havok/hkClassEnumItem.h"
#include <cstdio>
#include <cstring>
#include <limits>
#include <array>
#include <cstdlib>
#include <new>
#include <stdexcept>

namespace allocation_failure
{
long fail = -1;
long attempts = 0;
}
// Standard allocation is a system boundary. Single-shot failure lets the real
// public error owner allocate its diagnostic and exercises every C++ ownership
// allocation in the parser/converter/publication chain without fake bodies.
void* operator new(std::size_t bytes)
{
    ++allocation_failure::attempts;
    if (allocation_failure::fail == 0)
    {
        allocation_failure::fail = -1; throw std::bad_alloc();
    }
    if (allocation_failure::fail > 0) --allocation_failure::fail;
    if (void* pointer = std::malloc(bytes ? bytes : 1)) return pointer;
    throw std::bad_alloc();
}
void operator delete(void* pointer) noexcept { std::free(pointer); }
void* operator new[](std::size_t bytes) { return ::operator new(bytes); }
void operator delete[](void* pointer) noexcept { ::operator delete(pointer); }

namespace
{
int failures = 0;
void Check(bool condition, const char* message)
{
    if (!condition) { std::fprintf(stderr, "dictionary.%s\n", message); ++failures; }
}
class TraceAllocator final : public havok::native_memory::Allocator
{
public:
    void* Allocate(std::size_t bytes) override
    {
        if (fail == 0) { fail = -1; return nullptr; }
        if (fail > 0) --fail;
        void* pointer = backing.Allocate(bytes);
        if (pointer) { if (live == blocks.size()) std::abort(); blocks[live++] = {pointer, bytes}; ++allocations; }
        return pointer;
    }
    void Free(void* pointer, std::size_t bytes) noexcept override
    {
        if (!live || blocks[live - 1].first != pointer || blocks[live - 1].second != bytes) order = false;
        for (std::size_t i = 0; i < live; ++i) if (blocks[i].first == pointer)
        {
            for (std::size_t j = i + 1; j < live; ++j) blocks[j - 1] = blocks[j];
            --live; backing.Free(pointer, bytes); return;
        }
        std::abort();
    }
    havok::native_memory::AlignedAllocator backing;
    std::array<std::pair<void*, std::size_t>, 4096> blocks{};
    std::size_t live = 0, allocations = 0;
    bool order = true;
    long fail = -1;
};
// Source-owned binary tagfile v0. Only wire encoding is fixture code; all
// dictionary producers, native types, conversion and resource bodies are real.
struct Wire
{
    std::vector<std::byte> data;
    void Byte(unsigned value) { data.push_back(std::byte(value)); }
    void Word(unsigned value) { for (unsigned i = 0; i < 4; ++i) Byte(value >> (8 * i)); }
    void Int(std::int64_t value)
    {
        auto magnitude = value < 0 ? std::uint64_t(-(value + 1)) + 1 : std::uint64_t(value);
        unsigned byte = unsigned((magnitude & 63) << 1) | unsigned(value < 0); magnitude >>= 6;
        Byte(byte | (magnitude ? 128 : 0));
        while (magnitude) { byte = unsigned(magnitude & 127); magnitude >>= 7; Byte(byte | (magnitude ? 128 : 0)); }
    }
    void Text(const char* text) { Int(std::strlen(text)); while (*text) Byte(unsigned(*text++)); }
    void Member(const char* name, unsigned type, const char* klass = nullptr)
    {
        Text(name); Int(type); if (klass) Text(klass);
    }
    Wire()
    {
        Word(0xcab00d1e); Word(0xd011face); Int(1); Int(0);
        Int(2); Text("hkClassEnumItem"); Int(0); Int(0); Int(2);
        Member("value", 2); Member("name", 10);
        Int(2); Text("hkClassEnum"); Int(0); Int(0); Int(2);
        Member("name", 10); Member("items", 0x19, "hkClassEnumItem");
        Int(2); Text("hkClassMember"); Int(0); Int(0); Int(6);
        Member("name", 10); Member("type", 2); Member("subtype", 2);
        Member("flags", 2); Member("offset", 2); Member("class", 8, "hkClass");
        Int(2); Text("hkClass"); Int(0); Int(0); Int(6);
        Member("name", 10); Member("parent", 8, "hkClass"); Member("objectSize", 2);
        Member("declaredEnums", 0x19, "hkClassEnum"); Member("declaredMembers", 0x19, "hkClassMember"); Member("describedVersion", 2);
        Int(4); Int(4); Byte(63); // remembered root, all six fields
        Text("SyntheticRoot"); Int(5); Int(1); Int(96); // self cycle; 96 is data, NOT allocation extent
        Int(1); Byte(3); // one enum, column mask
        Text("SyntheticRoot"); Int(2); Byte(3); // pooled alias, two enum items
        Int(-7); Int(42); Text("negative"); Text("answer");
        Int(2); Byte(63); // native class members, column-major
        Text(""); Int(-1); // null string is distinct from the empty string
        Int(hkClassMember::TYPE_STRINGPTR); Int(hkClassMember::TYPE_UINT16);
        Int(0); Int(0); Int(hkClassMember::ALIGN_16); Int(0); Int(8); Int(16);
        Int(5); Int(1); Int(5); Int(1); // duplicate aliases to the remembered root
        Int(7);
    }
};
}
int main()
{
    using namespace havok::serialize;
    // Successful public replacement retires only the superseded registration's
    // storage. Independent consumers of the old descriptor retain their lease.
    for (int mode : {0, 1, 7})
    {
        std::weak_ptr<const void> replacementStorage;
        {
            ClassNameRegistry classes; TypeRegistry types(mode);
            auto first = dictionary::RegisterReflectionTypes(classes, types);
            const auto* oldClass = classes.Find("hkClass");
            std::weak_ptr<const void> superseded = classes.Storage(oldClass);
            auto consumer = classes.Storage(oldClass);
            auto second = dictionary::RegisterReflectionTypes(classes, types);
            const auto* current = classes.Find("hkClass");
            replacementStorage = classes.Storage(current);
            Check(current != oldClass && current == types.types.Lookup("hkClass")->nativeClass,
                "successful-replacement-publishes-real-new-class-and-type");
            Check(!classes.Storage(oldClass), "successful-replacement-retires-old-registry-lease");
            first.reset(); types.clear(); second.reset();
            Check(!superseded.expired() && std::strcmp(oldClass->m_name, "hkClass") == 0,
                "old-independent-consumer-retains-real-descriptor-storage");
            consumer.reset();
            Check(superseded.expired(), "last-old-consumer-releases-superseded-class-storage");
            Check(!replacementStorage.expired() && std::strcmp(current->m_name, "hkClass") == 0,
                "replacement-class-storage-survives-type-and-producer-retirement");
        }
        Check(replacementStorage.expired(), "last-new-registry-releases-replacement-storage");
    }
    // Registration is a public producer seam. An unsuccessful replacement must
    // preserve both existing registries and their live metadata, then permit a
    // real public dictionary load with the original contracts.
    long registrationAllocations = 0;
    {
        ClassNameRegistry classes; TypeRegistry types(7);
        auto first = dictionary::RegisterReflectionTypes(classes, types);
        allocation_failure::attempts = 0;
        auto replacement = dictionary::RegisterReflectionTypes(classes, types);
        registrationAllocations = allocation_failure::attempts;
        types.clear();
    }
    for (long stage = 0; stage < registrationAllocations; ++stage)
    {
        ClassNameRegistry classes; TypeRegistry types(7);
        auto original = dictionary::RegisterReflectionTypes(classes, types);
        const char* names[] = {"hkClass", "hkClassMember", "hkClassEnum", "hkClassEnumItem"};
        const hkClass* oldClasses[4];
        const hkEntryD479* oldTypes[4];
        for (unsigned i = 0; i < 4; ++i)
        {
            oldClasses[i] = classes.Find(names[i]); oldTypes[i] = types.types.Lookup(names[i]);
        }
        bool threw = false;
        std::shared_ptr<const void> replacement;
        allocation_failure::fail = stage;
        try { replacement = dictionary::RegisterReflectionTypes(classes, types); }
        catch (const std::bad_alloc&) { threw = true; }
        allocation_failure::fail = -1;
        Check(threw, "each-registration-allocation-failure-propagates");
        bool unchanged = true;
        for (unsigned i = 0; i < 4; ++i)
            unchanged = unchanged && classes.Find(names[i]) == oldClasses[i] && types.types.Lookup(names[i]) == oldTypes[i];
        Check(unchanged, "failed-registration-preserves-both-live-registries");
        // Do not dereference a changed/dangling entry in the RED implementation.
        // The independent review's separate ASan diagnostic retains that proof.
        if (unchanged)
        {
            Wire wire; MemoryLoadStream input(wire.data); LoadError error; LoadPolicy policy;
            SerializeOptions options{classes, types, policy};
            std::unique_ptr<S_Obj> resource(FUN_00d48d30(&input, &error, &options));
            Check(resource && resource->FUN_00e055f0(nullptr, &types), "failed-registration-still-permits-real-public-load");
            if (resource) Check(&resource->Root()->Class() == oldClasses[0], "failed-registration-retains-original-class-identity");
        }
        types.clear();
    }
    for (int mode : {0, 1, 7})
    {
        ClassNameRegistry classes; TypeRegistry types(mode);
        auto producer = dictionary::RegisterReflectionTypes(classes, types);
        LoadPolicy policy; SerializeOptions options{classes, types, policy};
        Wire wire;
        MemoryLoadStream bytes(wire.data);
        ReplayLoadStream input({}, bytes); // genuine production sequential stream
        LoadError error;
        std::unique_ptr<S_Obj> result(FUN_00d48d30(&input, &error, &options));
        Check(bool(result), "public-entry-constructs-resource");
        if (!result) { std::fprintf(stderr, "%s\n", error.message.c_str()); continue; }
        auto retained = result->Root();
        const auto* root = static_cast<const hkClass*>(retained->Address());
        Check(error.status == 0, "successful-status");
        Check(root && std::strcmp(root->m_name, "SyntheticRoot") == 0, "root-name");
        Check(root->m_parent == root, "remembered-self-cycle");
        Check(root->m_iObjectSize == 96 && root->m_iDescribedVersion == 7, "primitive-values-not-allocation-size");
        Check(root->m_kDeclaredEnums.m_iElementCount == 1, "enum-array-count");
        const auto& enumeration = root->m_kDeclaredEnums.m_data[0];
        Check(root->m_name == enumeration.m_name, "native-pooled-string-alias");
        Check(enumeration.m_items.m_iElementCount == 2, "nested-items-count");
        Check(enumeration.m_items.m_data[0].m_uiFilterValue == -7 && enumeration.m_items.m_data[1].m_uiFilterValue == 42, "signed-width-values");
        Check(std::strcmp(enumeration.m_items.m_data[1].m_name, "answer") == 0, "nested-owned-string");
        Check(root->m_kDeclaredMembers.m_iElementCount == 2, "class-member-array");
        const auto& member0 = root->m_kDeclaredMembers.m_data[0];
        const auto& member1 = root->m_kDeclaredMembers.m_data[1];
        Check(member0.m_type == hkClassMember::TYPE_STRINGPTR && member1.m_type == hkClassMember::TYPE_UINT16 &&
            member0.m_flags == hkClassMember::ALIGN_16 && member1.m_offset == 16, "primitive-width-and-enum-values");
        Check(member0.m_class == root && member1.m_class == root, "duplicate-class-aliases");
        Check(member1.m_name == nullptr && member0.m_name && member0.m_name[0] == '\0', "null-and-empty-strings-distinct");
        Check(result->Reference({4, int(offsetof(hkClassMember, m_class))})->Address() == root, "embedded-array-object-reference-provenance");
        Check(result->FUN_00e055f0(nullptr, &types) == root, "second-finish-same-root");
        Check(result->FUN_00e055f0(nullptr, &types) == root, "repeated-second-finish-same-root");
        Check(result->FUN_00e05140() == &retained->Class(), "root-native-class-identity");
        Check(result->Object({0, 0})->Address() == root, "object-identity-alias");
        Check(result->Reference({0, int(offsetof(hkClass, m_parent))})->Address() == root, "typed-reference-cycle");
        TypeRegistry otherMode(mode == 7 ? 0 : 7);
        Check(!result->FUN_00e055f0(nullptr, &otherMode), "second-finish-mode-mismatch");
        Check(result->Exports().empty() && result->Imports().empty(), "tagfile-has-no-invented-packfile-symbols");
        StatisticsSnapshot defaultStatistics;
        result->Data().WriteSections(&defaultStatistics);
        Check(defaultStatistics.Records().size() == 1 && defaultStatistics.Records()[0].name == "memory", "borrowed-empty-arrays-skipped");
        StatisticsSnapshot prefix(2, true);
        bool sinkFailed = false;
        try { result->Data().WriteSections(&prefix); }
        catch (const std::length_error&) { sinkFailed = true; }
        Check(sinkFailed && prefix.Records().size() == 2, "sink-failure-preserves-completed-prefix");
        StatisticsSnapshot statistics(std::numeric_limits<std::size_t>::max(), true);
        try { result->Data().WriteSections(&statistics); }
        catch (const std::exception& failure) { std::fprintf(stderr, "%s\n", failure.what()); }
        Check(statistics.Records().size() == 4, "actual-helper-emits-four-sections");
        if (statistics.Records().size() == 4)
        {
            const char* names[] = {"memory", "chunks", "exports", "imports"};
            for (unsigned i = 0; i < 4; ++i)
                Check(statistics.Records()[i].kind == 3 && statistics.Records()[i].name == names[i], "statistics-order-and-kind");
            Check(!statistics.Records()[0].logical.empty() &&
                statistics.Records()[0].allocatedBytes >= statistics.Records()[0].logical.size(), "supplier-allocation-extent-not-hash");
        }
        types.clear(); producer.reset(); result.reset(); wire.data.assign(wire.data.size(), std::byte{0});
        Check(std::strcmp(root->m_name, "SyntheticRoot") == 0 && root->m_parent == root, "retained-after-producer-input-resource-retirement");
    }
    {
        RootObject retained;
        std::weak_ptr<const void> classStorage;
        {
            ClassNameRegistry classes; TypeRegistry types(1);
            auto producer = dictionary::RegisterReflectionTypes(classes, types);
            classStorage = types.types.Lookup("hkClass")->nativeClassStorage;
            LoadPolicy policy; SerializeOptions options{classes, types, policy}; Wire wire;
            MemoryLoadStream input(wire.data); LoadError error;
            std::unique_ptr<S_Obj> resource(FUN_00d48d30(&input, &error, &options));
            retained = resource->Root();
        }
        Check(!classStorage.expired() && std::strcmp(retained->Class().m_name, "hkClass") == 0,
            "native-class-member-storage-survives-all-domain-producers");
        retained.FUN_00dba7f0();
        Check(classStorage.expired(), "last-retained-consumer-releases-class-snapshot");
    }
    // Error cases enter the same actual reader branch, never a fixture converter.
    {
        ClassNameRegistry classes; TypeRegistry types(7);
        auto producer = dictionary::RegisterReflectionTypes(classes, types);
        LoadPolicy policy; SerializeOptions options{classes, types, policy}; Wire wire;
        for (std::size_t size = 0; size < wire.data.size(); ++size)
        {
            MemoryLoadStream input(std::span<const std::byte>(wire.data).first(size)); LoadError error;
            std::unique_ptr<S_Obj> result(FUN_00d48d30(&input, &error, &options));
            Check(!result && error.status != 0 && !error.message.empty(), "truncated-public-input-has-meaningful-error");
        }
        auto altered = wire.data;
        // Version follows the two 32-bit magic words and tag1.
        altered[9] = std::byte{2};
        MemoryLoadStream input(altered); LoadError error;
        Check(!FUN_00d48d30(&input, &error, &options) && error.message.find("version") != std::string::npos, "unsupported-version");
        std::vector<std::byte> binary(64);
        binary[0] = std::byte{0x57}; binary[1] = std::byte{0xe0}; binary[2] = std::byte{0xe0}; binary[3] = std::byte{0x57};
        binary[16] = std::byte{4}; binary[17] = std::byte{1};
        MemoryLoadStream binaryMismatch(binary);
        Check(!FUN_00d48d30(&binaryMismatch, &error, &options) && error.message.find("layout") != std::string::npos,
            "actual-public-packfile-layout-not-replaced-by-policy");
        policy.layout[0] = std::byte{4}; policy.layout[1] = std::byte{1};
        binary[40] = std::byte{'X'};
        MemoryLoadStream versionMismatch(binary);
        Check(!FUN_00d48d30(&versionMismatch, &error, &options) && error.message.find("version") != std::string::npos,
            "actual-public-packfile-version-not-replaced-by-policy");
        auto* type = types.types.Lookup("hkClass");
        const auto nativeSize = type->nativeSize; type->nativeSize = 96;
        MemoryLoadStream mismatch(wire.data);
        Check(!FUN_00d48d30(&mismatch, &error, &options) && error.message.find("layout") != std::string::npos, "recorded96-not-native-allocation-contract");
        type->nativeSize = nativeSize;
    }
    for (int mode : {0, 1, 7})
    {
        auto allocator = std::make_shared<TraceAllocator>();
        havok::native_memory::System supplier(allocator, havok::native_memory::ScratchBytes{0});
        InstallPackfileSupplier(supplier);
        ClassNameRegistry classes; TypeRegistry types(mode);
        auto producer = dictionary::RegisterReflectionTypes(classes, types);
        LoadPolicy policy; SerializeOptions options{classes, types, policy}; Wire wire; LoadError error;
        long cxxAllocations;
        std::size_t nativeAllocations;
        {
            MemoryLoadStream input(wire.data);
            allocation_failure::attempts = 0;
            std::unique_ptr<S_Obj> result(FUN_00d48d30(&input, &error, &options));
            cxxAllocations = allocation_failure::attempts; nativeAllocations = allocator->allocations;
            Check(bool(result), "failure-sweep-control-success");
        }
        Check(allocator->live == 0, "control-cleanup-complete");
        {
            MemoryLoadStream originalInput(wire.data);
            std::unique_ptr<S_Obj> previous(FUN_00d48d30(&originalInput, &error, &options));
            Check(bool(previous), "root-consumer-failure-has-real-prior-owner");
            if (previous)
            {
                const auto live = allocator->live;
                const auto* address = previous->Root()->Address();
                hkClass unnamed{}; // real invalid descriptor, not a root provider
                for (int failure = 0; failure < 6; ++failure)
                {
                    MemoryLoadStream complete(wire.data);
                    MemoryLoadStream truncated(std::span<const std::byte>(wire.data).first(1));
                    LoadStream* input = failure == 3 ? nullptr : failure == 4 ? &truncated : &complete;
                    const auto* primary = failure == 0 ? nullptr : failure == 2 ? &unnamed : classes.Find("hkClass");
                    const auto* domain = failure == 1 ? nullptr : &options;
                    S_Obj* output = previous.get(); // independent prior ownership stays with previous
                    LoadError failureError;
                    const auto* selected = FUN_00cc0850(input, domain, primary, &output, &failureError);
                    Check(!selected && !output && failureError.status != 0 && !failureError.message.empty(),
                        "public-root-consumer-clears-owner-on-every-supported-failure");
                    Check(allocator->live == live && previous->FUN_00e055f0(nullptr, &types) == address,
                        "failed-root-consumer-preserves-prior-owner-and-cleans-new-resource");
                }
                S_Obj* output = previous.get();
                Check(!FUN_00cc0850(nullptr, &options, nullptr, &output, nullptr) && !output,
                    "public-root-consumer-clears-owner-without-error-receiver");
                LoadError failureError;
                Check(!FUN_00cc0850(nullptr, &options, classes.Find("hkClass"), nullptr, &failureError) &&
                    failureError.status != 0 && !failureError.message.empty(), "public-root-consumer-rejects-null-owner-slot");
            }
        }
        Check(allocator->live == 0 && allocator->order, "public-root-consumer-failure-and-prior-owner-cleanup-complete");
        for (long stage = 0; stage < cxxAllocations; ++stage)
        {
            MemoryLoadStream input(wire.data);
            allocation_failure::fail = stage;
            std::unique_ptr<S_Obj> result(FUN_00d48d30(&input, &error, &options));
            allocation_failure::fail = -1;
            Check(!result && error.status != 0, "each-cxx-allocation-failure-refused");
            result.reset();
            Check(allocator->live == 0 && allocator->order, "failed-cxx-prefix-reverse-cleanup");
        }
        for (std::size_t stage = 0; stage < nativeAllocations; ++stage)
        {
            MemoryLoadStream input(wire.data); allocator->fail = long(stage);
            std::unique_ptr<S_Obj> result(FUN_00d48d30(&input, &error, &options)); allocator->fail = -1;
            Check(!result && error.status != 0, "each-native-allocation-failure-refused");
            result.reset();
            Check(allocator->live == 0 && allocator->order, "failed-native-prefix-reverse-cleanup");
        }
        RootObject retained;
        StatisticsSnapshot statistics(std::numeric_limits<std::size_t>::max(), true);
        {
            MemoryLoadStream input(wire.data);
            std::unique_ptr<S_Obj> result(FUN_00d48d30(&input, &error, &options));
            retained = result->Root();
            allocator->fail = 0;
            StatisticsSnapshot failed;
            bool refused = false;
            try { result->Data().WriteSections(&failed); } catch (const std::bad_alloc&) { refused = true; }
            allocator->fail = -1;
            Check(refused && failed.Records().empty() &&
                result->FUN_00e055f0(nullptr, &types) == retained->Address(), "archive-allocation-failure-preserves-live-resource");
            ShutdownPackfileSupplier(); Check(supplier.Shutdown(), "supplier-retired-with-live-resource-leases");
            result->Data().WriteSections(&statistics); // uses actual retained supplier, not a global
            types.clear(); producer.reset();
            ShutdownBuiltinRegistries();
        }
        wire.data.clear();
        Check(std::strcmp(static_cast<const hkClass*>(retained->Address())->m_name, "SyntheticRoot") == 0, "supplier-global-producer-retirement");
        retained.FUN_00dba7f0();
        Check(allocator->live != 0, "statistics-receiver-retains-source-storage");
        // statistics destruction releases its source-resource lease at scope end.
    }
    return failures ? 1 : 0;
}
