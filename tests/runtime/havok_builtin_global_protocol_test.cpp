#include "havok/BuiltinTypeRegistry.h"
#include "havok/NativeWorld.h"
#include "fnv/decl/FUN_00d472a0.h"
#include "fnv/decl/ReferencedObjectHolder.h"
#include "havok/PackfileLoad.h"
#include "havok/PackfileResource.h"
#include "havok/hkClassMember.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <new>
#include <stdexcept>
#include <vector>

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
int failures;
void Check(bool condition, const char* message)
{
    if (!condition) { ++failures; std::fprintf(stderr, "FAIL: %s\n", message); }
}
void Initialization()
{
    using namespace havok::serialize;
    ShutdownBuiltinRegistries();
    Check(FUN_00d47820() == nullptr, "factory refuses absent globals");
    fnv_00d47d70::FUN_00d47d70_class initialization;
    initialization.InitGlobalObjects();
    auto* registry = FUN_00d47820();
    Check(registry != nullptr, "actual factory constructs outer owner");
    if (registry)
    {
        Check(registry->Classes() == GlobalClassRegistry(), "outer owns real name registry");
        Check(registry->Types() == GlobalTypeRegistry(), "outer owns actual metadata registry");
        Check(reinterpret_cast<std::intptr_t>(registry->Vtables()) == FUN_00d47a20(), "outer owns real vtable registry");
        registry->ReleaseReference();
    }
    ShutdownBuiltinRegistries();
}

std::vector<void*> finished, cleaned;
bool failSecond;
struct Payload
{
    int value;
    int finishing;
    Payload(int v, int f) : value(v), finishing(f) {}
    virtual ~Payload() { cleaned.push_back(this); }
};
void FinishPayload(Payload* object, int flag)
{
    int value;
    std::memcpy(&value, reinterpret_cast<const std::byte*>(object) + sizeof(void*), sizeof(value));
    if (failSecond && value == 42) throw std::runtime_error("payload construction failure");
    new (object) Payload(value, flag);
    finished.push_back(object);
}
void CleanupPayload(Payload* object) { object->~Payload(); }
struct Source
{
    char name[15] = "BuiltinPayload";
    char valueName[6] = "value";
    Payload exemplar{0, 0};
    hkClassMember member{};
    FUN_00d472a0 descriptor;
    std::unique_ptr<Agg6> metadata;
    Source() : descriptor(name, nullptr, sizeof(Payload), nullptr, 1,
        nullptr, 0, &member, 1, nullptr, nullptr, 0, 1)
    {
        member.m_name = valueName;
        member.m_type = hkClassMember::TYPE_INT32;
        member.m_offset = sizeof(void*);
        const void* vtable;
        std::memcpy(&vtable, static_cast<const void*>(&exemplar), sizeof(vtable));
        metadata = std::make_unique<Agg6>(name, FinishPayload, CleanupPayload,
            vtable, &descriptor, reinterpret_cast<const void*>(sizeof(Payload)));
        metadata->Metadata()->SetNativeLayout<Payload>();
    }
};
void Put(std::vector<std::byte>& bytes, std::size_t at, int value)
{
    for (unsigned i = 0; i < 4; ++i) bytes.at(at + i) = std::byte(static_cast<unsigned>(value) >> (8 * i));
}
std::vector<std::byte> Packfile()
{
    std::vector<std::byte> bytes(200);
    Put(bytes, 0, 0x57e0e057); Put(bytes, 4, 0x10c0c010);
    bytes[16] = std::byte(sizeof(void*)); bytes[17] = std::byte{1};
    Put(bytes, 20, 1); Put(bytes, 24, 0); Put(bytes, 28, 0);
    Put(bytes, 84, 112); Put(bytes, 88, 64); Put(bytes, 92, 64);
    Put(bytes, 96, 64); Put(bytes, 100, 88); Put(bytes, 104, 88); Put(bytes, 108, 88);
    Put(bytes, 120, 41); Put(bytes, 136, 42);
    std::memcpy(bytes.data() + 144, "BuiltinPayload", 15);
    Put(bytes, 176, 0); Put(bytes, 180, 0); Put(bytes, 184, 32);
    Put(bytes, 188, 16); Put(bytes, 192, 0); Put(bytes, 196, 32);
    return bytes;
}
void ConnectedLoad()
{
    using namespace havok::serialize;
    Source source;
    fnv_00d47d70::FUN_00d47d70_class initialization;
    initialization.InitGlobalObjects();
    Check(GetBuiltinCatalogStatus() == BuiltinCatalogStatus::MissingClassDescriptors,
        "missing generated classes are explicit, not invented defaults");
    RegisterInputSource(source.metadata.get(), &source.descriptor);
    auto* owner = FUN_00d47820();
    Check(owner->Classes()->Find("BuiltinPayload") == &source.descriptor, "public input registration preserves class identity");
    Check(owner->Types()->types.Lookup("BuiltinPayload") == source.metadata->Metadata(), "public registration reaches canonical metadata");
    Check(owner->Vtables()->LookupObject(&source.exemplar) == &source.descriptor, "real compiler vptr identity resolves without virtual-slot calls");
    ReferencedObjectHolder holder{&source.exemplar};
    Check(holder.FUN_00d477a0() == &source.descriptor, "actual global reference query uses the constructed vtable owner");
    Check(&DefaultPackfileRegistry() == owner->Types(), "default loader and globals share the same constructed owner");
    auto bytes = Packfile();
    finished.clear(); cleaned.clear();
    auto* resource = static_cast<Resource*>(CreateResourceFromArray(bytes.data(), reinterpret_cast<void*>(bytes.size()), nullptr));
    Check(resource != nullptr, "default production resource loads actual public registration");
    if (resource)
    {
        auto* root = static_cast<Payload*>(resource->contents(nullptr, owner->Types()));
        Check(root && root->value == 41 && root->finishing == 1, "observed finished root retains payload and exact flag");
        Check(owner->Vtables()->LookupObject(root) == &source.descriptor, "loaded real native object resolves its registered class");
        Check(finished.size() == 2, "actual resource finishes both source-owned objects");
        resource->AddReference();
        resource->ReleaseReference();
        Check(cleaned.empty(), "retained resource owns live root");
        const auto expected = std::vector<void*>{finished.rbegin(), finished.rend()};
        ShutdownBuiltinRegistries();
        Check(holder.FUN_00d477a0() == nullptr, "actual global reference query observes unpublication without touching released owners");
        Check(owner->Classes()->Find("BuiltinPayload") == &source.descriptor, "outer reference survives global shutdown");
        owner->ReleaseReference(); owner = nullptr;
        std::fill(bytes.begin(), bytes.end(), std::byte{0xff});
        resource->ReleaseReference();
        Check(cleaned == expected, "shutdown and input overwrite preserve reverse exact-object cleanup");
    }
    if (owner) owner->ReleaseReference();
    ShutdownBuiltinRegistries();
}
void CatalogUnwind()
{
    using namespace havok::serialize;
    Source first, second;
    fnv_00d47d70::FUN_00d47d70_class initialization;
    initialization.InitGlobalObjects();
    auto* owner = FUN_00d47820();
    void* items[] = {first.metadata.get(), second.metadata.get(), nullptr};
    const hkClass* classes[] = {&first.descriptor, &second.descriptor, nullptr};
    SetBuiltinCatalog({items, std::span<const hkClass* const>(classes, 1), &first.descriptor});
    bool threw = false;
    try { FUN_00d47860(); } catch (const std::invalid_argument&) { threw = true; }
    Check(threw, "missing bounded default class pairing reports failure");
    Check(owner->Classes()->Find("BuiltinPayload") == nullptr && owner->Types()->types.Lookup("BuiltinPayload") == nullptr,
        "failed default population leaves all original registries unchanged");
    const auto names = FUN_00d47a10(), types = FUN_00d47a00(), vtables = FUN_00d47a20();
    threw = false;
    try { initialization.InitGlobalObjects(); } catch (const std::invalid_argument&) { threw = true; }
    Check(threw && FUN_00d47a10() == names && FUN_00d47a00() == types && FUN_00d47a20() == vtables,
        "failed repeated global init restores all old owners");
    SetBuiltinCatalog({});
    owner->ReleaseReference();
    ShutdownBuiltinRegistries();
}
void ReinitializationAndLoader()
{
    using namespace havok::serialize;
    Source source;
    void* items[] = {source.metadata.get(), nullptr};
    const hkClass* classes[] = {&source.descriptor, nullptr};
    SetBuiltinCatalog({items, classes, &source.descriptor});
    fnv_00d47d70::FUN_00d47d70_class initialization;
    initialization.InitGlobalObjects();
    auto* old = FUN_00d47820();
    Check(GetBuiltinCatalogStatus() == BuiltinCatalogStatus::ClassDescriptorsProvided, "explicit native source catalogue has real descriptors");
    Check(old->Classes()->Find(source.name) == &source.descriptor, "actual default population registers real class producer");
    const auto references = old->Types()->references;
    old->Initialize(); old->Initialize();
    Check(old->Types()->references == references, "repeated initialize balances ownership without accumulating references");
    old->AddReference(); old->ReleaseReference();
    initialization.InitGlobalObjects();
    Check(GlobalTypeRegistry() != old->Types(), "reinitialization publishes fresh constructed owners");
    Check(old->Classes()->Find(source.name) == &source.descriptor, "previous outer owner retains its coherent snapshot");
    old->ReleaseReference();
    auto* owner = FUN_00d47820();
    for (int flag : {0, 1, 7})
    {
        owner->Types()->finish = flag;
        auto bytes = Packfile();
        MemoryLoadStream input(bytes);
        LoadFormat format;
        format.version = "source-owned-builtin-fixture";
        LoadPolicy policy;
        policy.version = format.version;
        LoadError error;
        finished.clear(); cleaned.clear();
        auto* resource = FUN_00d48760(input, format, &error, *owner->Types(), policy);
        Check(resource != nullptr, "production serialize-util entry loads constructed builtin registry");
        if (resource)
        {
            auto* root = static_cast<Payload*>(resource->contents(source.name, owner->Types()));
            Check(root && root->value == 41 && root->finishing == flag, "production loader retains exact finishing 0/1/7");
            Check(resource->TypeInfo() && resource->TypeInfo()->vtable == source.metadata->Metadata()->vtable &&
                resource->TypeInfo()->size == sizeof(Payload), "production root owns actual generated-producer metadata values");
            const auto expected = std::vector<void*>{finished.rbegin(), finished.rend()};
            resource->ReleaseReference();
            Check(cleaned == expected, "production load cleanup uses real payload destructors");
        }
    }
    auto bytes = Packfile();
    finished.clear(); cleaned.clear(); failSecond = true;
    auto* failed = static_cast<Resource*>(CreateResourceFromArray(bytes.data(), reinterpret_cast<void*>(bytes.size()), owner->Types()));
    failSecond = false;
    Check(failed == nullptr && finished.size() == 1 && cleaned == finished,
        "second construction failure unwinds exactly the successfully finished object");
    if (failed) failed->ReleaseReference();
    for (bool invalidMagic : {true, false})
    {
        auto rejected = Packfile();
        if (invalidMagic) Put(rejected, 0, 0);
        MemoryLoadStream input(rejected);
        LoadFormat format; format.version = "source-owned-failure";
        LoadPolicy policy; policy.version = format.version;
        LoadError error;
        finished.clear(); cleaned.clear(); failSecond = !invalidMagic;
        failed = FUN_00d48760(input, format, &error, *owner->Types(), policy);
        failSecond = false;
        Check(!failed && error.status != 0 && error.message.find(invalidMagic ? "magic" : "payload construction failure") != std::string::npos,
            "actual builtin registration and public loader preserve real failure diagnostic");
        Check(invalidMagic ? finished.empty() : finished.size() == 1 && cleaned == finished,
            "actual public constructor failure preserves exact completed-prefix cleanup");
        if (failed) failed->ReleaseReference();
    }
    bool threw = false;
    try { RegisterInputSource(nullptr, &source.descriptor); } catch (const std::invalid_argument&) { threw = true; }
    Check(threw && owner->Types()->types.Lookup(source.name) == source.metadata->Metadata(), "invalid public registration preserves existing valid family");
    auto cyclic = source.descriptor;
    cyclic.m_parent = &cyclic;
    threw = false;
    try { RegisterInputSource(source.metadata.get(), &cyclic); } catch (const std::invalid_argument&) { threw = true; }
    Check(threw, "cyclic real class graph is rejected before traversal");
    owner->ReleaseReference();
    ShutdownBuiltinRegistries(); ShutdownBuiltinRegistries();
    Check(FUN_00d47a00() == 0 && FUN_00d47a10() == 0 && FUN_00d47a20() == 0 && FUN_00d47820() == nullptr,
        "repeated shutdown unpublishes all globals and prevents factory acquisition");
    SetBuiltinCatalog({});
}
void MetadataTableReader()
{
    Source source;
    Check(source.descriptor.m_name == source.name && source.descriptor.m_iObjectSize == sizeof(Payload) &&
        source.descriptor.m_iNumImplementedInterfaces == 1 && source.descriptor.m_kDeclaredMembers.m_data == &source.member &&
        source.descriptor.m_kDeclaredMembers.m_iElementCount == 1 && source.descriptor.m_iDescribedVersion == 1,
        "retained native class constructor preserves real fields, native pointer widths and described version");
    auto registry = std::make_unique<hkVtableClassRegistry>();
    void* empty[] = {nullptr};
    registry->FUN_00db78a0(empty, nullptr);
    Check(registry->LookupObject(&source.exemplar) == nullptr, "actual metadata reader leading-null needs no fake paired array");
    void* items[] = {source.metadata.get(), nullptr};
    const hkClass* descriptors[] = {&source.descriptor, nullptr};
    registry->FUN_00db78a0(items, descriptors);
    Check(registry->LookupObject(&source.exemplar) == &source.descriptor, "actual metadata reader registers genuine native class and vptr identity");
    Check(registry->LookupClassByVtable(reinterpret_cast<const unsigned long*>(&source.exemplar)) == reinterpret_cast<std::uintptr_t>(&source.descriptor),
        "retained vtable lookup preserves native pointer width");
    Check(registry->LookupObject(nullptr) == nullptr, "null queried object has no class");
    bool threw = false;
    try { registry->RegisterTables(items, {}); } catch (const std::invalid_argument&) { threw = true; }
    Check(threw, "bounded actual table reader rejects a missing paired class extent");
}
void AllocationUnwind()
{
    using namespace havok::serialize;
    Source source;
    fnv_00d47d70::FUN_00d47d70_class initialization;
    SetBuiltinCatalog({});
    initialization.InitGlobalObjects();
    auto* owner = FUN_00d47820();
    bool registered = false;
    int failedRegistrationAllocations = 0;
    for (int fail = 0; fail < 64 && !registered; ++fail)
    {
        allocationFailure = fail;
        try { RegisterInputSource(source.metadata.get(), &source.descriptor); registered = true; }
        catch (const std::bad_alloc&) {}
        allocationFailure = -1;
        if (!registered)
        {
            ++failedRegistrationAllocations;
            Check(owner->Classes()->Find(source.name) == nullptr &&
                owner->Types()->types.Lookup(source.name) == nullptr &&
                owner->Vtables()->LookupObject(&source.exemplar) == nullptr,
                "every public registration allocation failure leaves all three protocols unchanged");
        }
    }
    Check(registered && failedRegistrationAllocations >= 3, "real public registration recovers after allocation failures");
    void* items[] = {source.metadata.get(), nullptr};
    const hkClass* classes[] = {&source.descriptor, nullptr};
    SetBuiltinCatalog({items, classes, &source.descriptor});
    bool initialized = false;
    int failedInitAllocations = 0;
    const auto names = FUN_00d47a10(), types = FUN_00d47a00(), vtables = FUN_00d47a20();
    for (int fail = 0; fail < 64 && !initialized; ++fail)
    {
        allocationFailure = fail;
        try { initialization.InitGlobalObjects(); initialized = true; }
        catch (const std::bad_alloc&) {}
        allocationFailure = -1;
        if (!initialized)
        {
            ++failedInitAllocations;
            Check(FUN_00d47a10() == names && FUN_00d47a00() == types && FUN_00d47a20() == vtables,
                "global construction and population allocation failures retain all old published owners");
            Check(owner->Classes()->Find(source.name) == &source.descriptor,
                "failed global replacement leaves previous family available");
        }
    }
    Check(initialized && failedInitAllocations >= 6, "real global construction recovers after allocation failures");
    const auto stableTypes = FUN_00d47a00();
    allocationFailure = 0;
    bool threw = false;
    try { auto* unexpected = FUN_00d47820(); unexpected->ReleaseReference(); }
    catch (const std::bad_alloc&) { threw = true; }
    allocationFailure = -1;
    Check(threw && FUN_00d47a00() == stableTypes, "outer allocation failure leaves constructed globals intact");
    owner->ReleaseReference();
    ShutdownBuiltinRegistries();
    SetBuiltinCatalog({});
}
}
int main()
{
    using namespace havok::serialize;
    {
        RootObject retained;
        std::weak_ptr<Source> lifetime;
        {
            auto source = std::make_shared<Source>(); lifetime = source;
            SetBuiltinCatalog({});
            fnv_00d47d70::FUN_00d47d70_class initialization;
            initialization.InitGlobalObjects();
            RegisterInputSource(source->metadata.get(), &source->descriptor);
            GlobalClassRegistry()->RegisterClass(&source->descriptor, source);
            auto bytes = Packfile();
            MemoryLoadStream input(bytes);
            LoadFormat format;
            format.version = "source-owned-payload-world";
            format.layout = {std::byte(sizeof(void*)), std::byte{1}, std::byte{}, std::byte{}};
            LoadPolicy policy{format.version, format.layout, nullptr}; LoadError error;
            finished.clear(); cleaned.clear();
            GlobalTypeRegistry()->finish = 7;
            auto* resource = FUN_00d48840(&input, format, &error, GlobalClassRegistry(), GlobalTypeRegistry(), policy);
            Check(resource != nullptr, "actual public-registration heap-loader path publishes native-layout Payload world");
            if (resource)
            {
                retained = resource->Root();
                Check(resource->Data().FUN_00e055f0("BuiltinPayload", GlobalTypeRegistry()) == retained->Address(),
                    "actual second consumer receives registered native Payload root");
                Check(&retained->Class() == &source->descriptor && static_cast<const Payload*>(retained->Address())->value == 41,
                    "native-layout root preserves real CPP descriptor and value");
                std::fill(bytes.begin(), bytes.end(), std::byte{0xdd});
                ShutdownBuiltinRegistries(); source.reset();
                resource->ReleaseReference();
            }
            ShutdownBuiltinRegistries();
        }
        Check(retained && !lifetime.expired(), "native Payload root retains descriptor/member/name and resource after shutdown");
        if (retained) Check(static_cast<const Payload*>(retained->Address())->finishing == 7, "native Payload state survives original metadata destruction request");
        retained.FUN_00dba7f0();
        Check(lifetime.expired(), "native Payload descriptor storage releases after final resource cleanup");
    }
    {
        Source source;
        SetBuiltinCatalog({});
        fnv_00d47d70::FUN_00d47d70_class initialization;
        initialization.InitGlobalObjects();
        RegisterInputSource(source.metadata.get(), &source.descriptor);
        auto bytes = Packfile();
        std::fill(bytes.begin() + 112, bytes.begin() + 176, std::byte{});
        Put(bytes, 28, 1);
        Put(bytes, 121, 41); Put(bytes, 137, 42);
        std::memcpy(bytes.data() + 152, "BuiltinPayload", 15);
        Put(bytes, 176, 1); Put(bytes, 184, 40);
        Put(bytes, 188, 17); Put(bytes, 196, 40);
        finished.clear(); cleaned.clear();
        auto* resource = static_cast<Resource*>(CreateResourceFromArray(
            bytes.data(), reinterpret_cast<void*>(bytes.size()), nullptr));
        Check(!resource && finished.empty() && cleaned.empty(),
            "actual registration rejects misaligned native Payload before constructor");
        if (resource) resource->ReleaseReference();
        auto narrow = Packfile(); narrow[16] = std::byte{4};
        finished.clear(); cleaned.clear();
        resource = static_cast<Resource*>(CreateResourceFromArray(narrow.data(), reinterpret_cast<void*>(narrow.size()), nullptr));
        Check(!resource && finished.empty(), "raw four-byte representation without fixups cannot invoke native callbacks");
        if (resource) resource->ReleaseReference();
        ShutdownBuiltinRegistries();
    }
    Initialization();
    ConnectedLoad();
    CatalogUnwind();
    ReinitializationAndLoader();
    MetadataTableReader();
    AllocationUnwind();
    std::printf("builtin/global protocol failures=%d\n", failures);
    return failures ? 1 : 0;
}
