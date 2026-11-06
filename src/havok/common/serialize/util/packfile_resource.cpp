#include "havok/PackfileResource.h"
#include "havok/PackfileLoad.h"
#include "havok/hkClass.h"
#include "havok/NativeGraph.h"

#include <algorithm>
#include <array>
#include <bit>
#include <cstring>
#include <limits>
#include <new>
#include <span>
#include <stdexcept>
#include <string_view>

namespace
{
using Bytes = std::span<const std::byte>;
Bytes Slice(Bytes bytes, std::size_t at, std::size_t size)
{
    if (at > bytes.size() || size > bytes.size() - at)
        throw std::runtime_error("legacy section outside packfile owner");
    return bytes.subspan(at, size);
}
int Word(Bytes bytes, std::size_t at)
{
    auto value = Slice(bytes, at, 4);
    std::uint32_t word = 0;
    for (unsigned i = 0; i < 4; ++i) word |= std::to_integer<unsigned>(value[i]) << (8 * i);
    return std::bit_cast<std::int32_t>(word);
}
std::size_t Positive(int value)
{
    if (value < 0) throw std::runtime_error("negative legacy section extent");
    return static_cast<std::size_t>(value);
}
const char* Text(Bytes bytes, std::size_t at)
{
    auto tail = Slice(bytes, at, bytes.size() - std::min(at, bytes.size()));
    if (std::find(tail.begin(), tail.end(), std::byte{}) == tail.end())
        throw std::runtime_error("unterminated legacy string");
    return reinterpret_cast<const char*>(tail.data());
}
struct Input
{
    Bytes bytes;
    std::vector<ExportSection> sections;
    int rootSection, rootOffset;
    unsigned pointerBytes;
};
Input Parse(void* data, void* size)
{
    if (!data) throw std::runtime_error("null legacy input");
    Input input{Bytes(static_cast<const std::byte*>(data), reinterpret_cast<std::uintptr_t>(size)), {}, -1, -1, 0};
    Slice(input.bytes, 0, 64);
    if (Word(input.bytes, 0) != 0x57e0e057 || Word(input.bytes, 4) != 0x10c0c010)
        throw std::runtime_error("invalid legacy packfile magic");
    input.pointerBytes = std::to_integer<unsigned>(input.bytes[16]);
    if ((input.pointerBytes != 4 && input.pointerBytes != sizeof(void*)) || input.bytes[17] != std::byte{1})
        throw std::runtime_error("unsupported legacy pointer layout");
    const auto count = Positive(Word(input.bytes, 20));
    if (count > (input.bytes.size() - 64) / 48) throw std::runtime_error("invalid legacy section count");
    input.rootSection = Word(input.bytes, 24); input.rootOffset = Word(input.bytes, 28);
    for (std::size_t i = 0; i < count; ++i)
    {
        const auto at = 64 + i * 48;
        ExportSection section;
        std::memcpy(section.tag, input.bytes.data() + at, 20);
        section.absolute = Word(input.bytes, at + 20); section.local = Word(input.bytes, at + 24);
        section.global = Word(input.bytes, at + 28); section.virtuals = Word(input.bytes, at + 32);
        section.exportStart = Word(input.bytes, at + 36); section.exportEnd = Word(input.bytes, at + 40);
        section.end = Word(input.bytes, at + 44);
        if (section.local < 0 || section.global < section.local || section.virtuals < section.global ||
            section.exportStart < section.virtuals || section.exportEnd < section.exportStart || section.end < section.exportEnd)
            throw std::runtime_error("invalid legacy section ranges");
        Slice(input.bytes, Positive(section.absolute), Positive(section.end));
        input.sections.push_back(section);
    }
    if (input.rootSection < 0 || static_cast<std::size_t>(input.rootSection) >= count || input.rootOffset < 0 ||
        input.rootOffset >= input.sections[static_cast<std::size_t>(input.rootSection)].local)
        throw std::runtime_error("invalid legacy root");
    return input;
}
struct Section
{
    ExportSection header;
    std::vector<std::max_align_t> storage;
    std::byte* Data() noexcept { return reinterpret_cast<std::byte*>(storage.data()); }
    Bytes DataBytes() const noexcept { return {reinterpret_cast<const std::byte*>(storage.data()), Positive(header.local)}; }
};
struct Finished
{
    void* object;
    const hkEntryD479* metadata; // source identity only
    hkEntryD479 retained; // cleanup survives registry/metadata owner shutdown
};
struct alignas(std::max_align_t) LegacyHeader
{
    std::vector<Section> sections;
    std::vector<Finished> finished;
    struct Fixup { havok::serialize::Location from, target; };
    std::vector<Fixup> fixups;
    std::shared_ptr<havok::serialize::CompletionLedger> completion = std::make_shared<havok::serialize::CompletionLedger>();
    void* root = nullptr;
    ~LegacyHeader()
    {
        // The real cleanup callback receives the exact pointer registered at
        // finish time, not an integer key or the envelope's address.
        while (!finished.empty())
        {
            auto entry = std::move(finished.back()); finished.pop_back();
            if (entry.retained.cleanup) entry.retained.cleanup(entry.object);
        }
        completion->objects.clear();
    }
    void* Object(int section, int offset, std::size_t width = 1)
    {
        if (section < 0 || static_cast<std::size_t>(section) >= sections.size())
            throw std::runtime_error("invalid legacy target section");
        auto& s = sections[static_cast<std::size_t>(section)];
        Slice(s.DataBytes(), Positive(offset), width);
        return s.Data() + offset;
    }
    const hkEntryD479* TypeInfo(void* object) const noexcept
    {
        for (const auto& entry : finished) if (entry.object == object) return entry.metadata;
        return nullptr;
    }
};
void CleanupLegacyPackfile(S_00dc0de0* output)
{
    reinterpret_cast<LegacyHeader*>(output)->~LegacyHeader();
}
void* UnpackLegacyPackfile(void* data, void* size, void* output, int outputSize, void* registry)
{
    if (outputSize < static_cast<int>(sizeof(LegacyHeader))) throw std::runtime_error("legacy header storage too small");
    auto input = Parse(data, size);
    if (input.pointerBytes != sizeof(void*))
        throw std::runtime_error("raw in-place packfile objects require native pointer representation");
    auto& header = *new (output) LegacyHeader;
    try
    {
        header.sections.reserve(input.sections.size());
        for (const auto& source : input.sections)
        {
            Section section;
            section.header = source;
            // Keep the genuine export/import streams, removing fixup tables as
            // before. Data and stream offsets belong to this one section base.
            section.header.global = section.header.virtuals = section.header.exportStart = source.local;
            section.header.exportEnd = source.local + (source.exportEnd - source.exportStart);
            section.header.end = section.header.exportEnd + (source.end - source.exportEnd);
            const auto bytes = Positive(section.header.end);
            section.storage.resize((bytes + sizeof(std::max_align_t) - 1) / sizeof(std::max_align_t));
            const auto payload = Slice(input.bytes, Positive(source.absolute), Positive(source.end));
            std::memcpy(section.Data(), payload.data(), Positive(source.local));
            std::memcpy(section.Data() + source.local, payload.data() + source.exportStart, Positive(source.end - source.exportStart));
            header.sections.push_back(std::move(section));
        }
        // Complete all pointer identities before invoking a finish callback.
        for (int phase = 0; phase < 2; ++phase)
            for (std::size_t i = 0; i < input.sections.size(); ++i)
            {
                const auto& s = input.sections[i];
                const auto bytes = Slice(input.bytes, Positive(s.absolute), Positive(s.end));
                const int first = phase ? s.global : s.local, last = phase ? s.virtuals : s.global;
                for (int at = first; at < last; at += phase ? 12 : 8)
                {
                    Slice(bytes, Positive(at), 4);
                    const int from = Word(bytes, Positive(at));
                    if (from == -1) continue;
                    if (last - at < (phase ? 12 : 8)) throw std::runtime_error("truncated legacy pointer fixup");
                    // A four-byte serialized field cannot hold a native pointer.
                    // Do not overwrite its neighbor or pretend the old layout is native.
                    if (input.pointerBytes != sizeof(void*)) throw std::runtime_error("legacy pointer fields require native layout");
                    void* field = header.Object(static_cast<int>(i), from, sizeof(void*));
                    if (reinterpret_cast<std::uintptr_t>(field) % alignof(void*))
                        throw std::runtime_error("misaligned native pointer field");
                    havok::serialize::Location targetLocation{
                        phase ? Word(bytes, Positive(at + 4)) : static_cast<int>(i),
                        Word(bytes, Positive(at + (phase ? 8 : 4)))};
                    void* target = header.Object(targetLocation.section, targetLocation.offset);
                    const havok::serialize::Location sourceLocation{static_cast<int>(i), from};
                    auto existing = std::find_if(header.fixups.begin(), header.fixups.end(),
                        [&](const auto& fixup) { return fixup.from == sourceLocation; });
                    if (existing != header.fixups.end() && existing->target != targetLocation)
                        throw std::runtime_error("conflicting native pointer fixups");
                    if (existing == header.fixups.end()) header.fixups.push_back({sourceLocation, targetLocation});
                    std::memcpy(field, &target, sizeof(target));
                }
            }
        // Reserve tracking before callbacks so successful finishing is always
        // recorded without an allocation that could lose cleanup ownership.
        std::size_t virtualCount = 0;
        for (const auto& s : input.sections) virtualCount += Positive(s.exportStart - s.virtuals) / 12;
        header.finished.reserve(virtualCount);
        header.completion->objects.reserve(virtualCount);
        auto& types = *static_cast<hkObjD479*>(registry);
        for (std::size_t i = 0; i < input.sections.size(); ++i)
        {
            const auto& s = input.sections[i];
            const auto bytes = Slice(input.bytes, Positive(s.absolute), Positive(s.end));
            for (int at = s.virtuals; at < s.exportStart; at += 12)
            {
                Slice(bytes, Positive(at), 4);
                const int offset = Word(bytes, Positive(at));
                if (offset == -1) continue;
                if (s.exportStart - at < 12) throw std::runtime_error("truncated legacy virtual fixup");
                void* object = header.Object(static_cast<int>(i), offset);
                const int nameSection = Word(bytes, Positive(at + 4)), nameOffset = Word(bytes, Positive(at + 8));
                header.Object(nameSection, nameOffset);
                const auto& names = header.sections[static_cast<std::size_t>(nameSection)];
                const char* name = Text(names.DataBytes(), Positive(nameOffset));
                auto* metadata = types.types.Lookup(name);
                if (metadata)
                {
                    if (metadata->size < 0 || !metadata->nativeSize || !metadata->nativeAlignment ||
                        metadata->nativeSize != static_cast<std::size_t>(metadata->size))
                        throw std::runtime_error("legacy type has no matching native layout contract");
                    header.Object(static_cast<int>(i), offset, metadata->nativeSize);
                    if (metadata->nativeAlignment > alignof(std::max_align_t) ||
                        reinterpret_cast<std::uintptr_t>(object) % metadata->nativeAlignment)
                        throw std::runtime_error("packfile object does not meet native type alignment");
                }
                auto tracked = std::find_if(header.finished.begin(), header.finished.end(),
                    [&](const Finished& entry) { return entry.object == object; });
                if (tracked != header.finished.end())
                {
                    if (tracked->metadata != metadata) throw std::runtime_error("conflicting alias type");
                    continue;
                }
                if (!metadata) throw std::runtime_error("unregistered packfile object type");
                const auto begin = reinterpret_cast<std::uintptr_t>(object);
                for (const auto& entry : header.finished)
                {
                    const auto other = reinterpret_cast<std::uintptr_t>(entry.object);
                    if (begin < other + entry.retained.nativeSize && other < begin + metadata->nativeSize)
                        throw std::runtime_error("overlapping native in-place object identities");
                }
                // Copy all allocating callback state before invoking finish;
                // afterwards the reserved vector insertion cannot allocate.
                hkEntryD479 retained = *metadata;
                havok::serialize::CompletedIdentity completed{object, name, types.finish};
                completed.CaptureType(metadata);
                if (retained.m_func) retained.m_func(object, types.finish);
                header.finished.push_back({object, metadata, std::move(retained)});
                header.completion->objects.push_back(std::move(completed));
            }
        }
        header.root = header.Object(input.rootSection, input.rootOffset);
        return header.root;
    }
    catch (...) { header.~LegacyHeader(); throw; }
}
// Bounded validation precedes the retained offset/padded-string readers. Their
// output pointers are borrowed from the resource and die with its cleanup.
void ValidateRecords(const ExportSection& section, const void* base, int first, int last)
{
    const auto bytes = Bytes(static_cast<const std::byte*>(base), Positive(section.end));
    auto stream = Slice(bytes, Positive(first), Positive(last - first));
    for (std::size_t at = 0; at < stream.size();)
    {
        const int offset = Word(stream, at); at += 4;
        if (offset == -1) return;
        Slice(bytes.first(Positive(section.local)), Positive(offset), 1);
        const char* label = Text(stream, at);
        const auto length = std::strlen(label) + 1;
        const auto padded = (length + 3) & ~std::size_t(3);
        Slice(stream, at, padded); at += padded;
    }
}
}

// @fnv 0x00e030c0
int ReadIntAtOffset(intptr_t base, int* cursor)
{
    int word;
    std::memcpy(&word, reinterpret_cast<const char*>(base) + *cursor, sizeof(word));
    *cursor += 4;
    return word;
}
// @fnv 0x00e02f30
char* ReadPaddedString(char* base, int* cursor)
{
    char* text = base + *cursor;
    const auto bytes = (std::strlen(text) + 1 + 3) & ~std::size_t(3);
    *cursor += static_cast<int>(bytes);
    return text;
}
// @fnv 0x00e02f60
void ExportSection::ReadRecords(const void* base, ExportList<ExportRecord, ExportAlloc>& out) const
{
    ValidateRecords(*this, base, exportStart, exportEnd);
    const char* stream = static_cast<const char*>(base) + exportStart;
    for (int cursor = 0; cursor < exportEnd - exportStart;)
    {
        const int offset = ReadIntAtOffset(reinterpret_cast<intptr_t>(stream), &cursor);
        if (offset == -1) break;
        const char* name = ReadPaddedString(const_cast<char*>(stream), &cursor);
        auto& entry = out.add(); entry.name = name;
        entry.object = const_cast<char*>(static_cast<const char*>(base)) + offset;
    }
}
// @fnv 0x00e03010
void ParserE030::FUN_00e03010(intptr_t base, hkArrayE030<RangeE030>& out)
{
    ValidateRecords(section, reinterpret_cast<void*>(base), section.exportEnd, section.end);
    char* stream = reinterpret_cast<char*>(base) + section.exportEnd;
    for (int cursor = 0; cursor < section.end - section.exportEnd;)
    {
        const int offset = ReadIntAtOffset(reinterpret_cast<intptr_t>(stream), &cursor);
        if (offset == -1) break;
        const char* name = ReadPaddedString(stream, &cursor);
        auto& entry = out.AllocatePair(); entry.m_iStart = name;
        entry.m_iFirstValue = reinterpret_cast<char*>(base) + offset;
    }
}
// @fnv 0x00dc08f0
extern "C" void ProcessElements(intptr_t owner, intptr_t exports, intptr_t imports)
{
    auto& header = *reinterpret_cast<LegacyHeader*>(owner);
    for (auto& section : header.sections)
    {
        if (exports) section.header.ReadRecords(section.Data(), *reinterpret_cast<ExportList<ExportRecord, ExportAlloc>*>(exports));
        if (imports) ParserE030(section.header).FUN_00e03010(reinterpret_cast<intptr_t>(section.Data()), *reinterpret_cast<hkArrayE030<RangeE030>*>(imports));
    }
}
// @fnv 0x00dc07d0
extern "C" int FUN_00dc07d0(void* data, void* size) noexcept
{
    try
    {
        (void)Parse(data, size);
        return static_cast<int>(havok::serialize::PackfileEnvelopeSize() + sizeof(LegacyHeader));
    }
    catch (...) { return 0; }
}

namespace
{
struct SupplierInstallation
{
    // The default installation uses the same real native System/allocator
    // contract as explicit engine installations. No TLS or test-only router.
    std::shared_ptr<havok::native_memory::Allocator> allocator =
        std::make_shared<havok::native_memory::AlignedAllocator>();
    havok::native_memory::System system{allocator, havok::native_memory::ScratchBytes{0}};
    std::shared_ptr<havok::native_memory::Allocator> active = system.AcquireSupplier();
};
SupplierInstallation& Suppliers() { static SupplierInstallation installation; return installation; }
}
void havok::serialize::InstallPackfileSupplier(native_memory::System& system)
{
    auto supplier = system.AcquireSupplier();
    if (!supplier) throw std::runtime_error("native supplier system is stopped");
    Suppliers().active = std::move(supplier);
}
void havok::serialize::ShutdownPackfileSupplier() noexcept { Suppliers().active.reset(); }
std::shared_ptr<havok::native_memory::Allocator> havok::serialize::AcquirePackfileSupplier()
{
    auto supplier = Suppliers().active;
    if (!supplier) throw std::runtime_error("packfile supplier installation is shut down");
    return supplier;
}

namespace
{
struct ResourceBufferAllocation
{
    std::shared_ptr<havok::native_memory::Allocator> supplier;
    std::size_t bytes;
    void* data = nullptr;
    ResourceBufferAllocation(std::shared_ptr<havok::native_memory::Allocator> supplier, std::size_t bytes)
        : supplier(std::move(supplier)), bytes(bytes) {}
    ~ResourceBufferAllocation() { if (data) supplier->Free(data, bytes); }
};
struct ResourceBufferContents
{
    std::shared_ptr<ResourceBufferAllocation> allocation;
    explicit ResourceBufferContents(std::shared_ptr<ResourceBufferAllocation> allocation)
        : allocation(std::move(allocation)) {}
    ~ResourceBufferContents()
    {
        if (allocation->data) FUN_00dc0de0(reinterpret_cast<S_00dc0de0*>(allocation->data));
    }
};
}
using Resource = fnv_00dc0f20::FUN_00dc0f20_cls;
Resource::FUN_00dc0f20_cls(std::shared_ptr<havok::native_memory::Allocator> allocator) : FUN_00dc0ef0_class(std::move(allocator)) {}
Resource::~FUN_00dc0f20_cls() { FUN_00dc0f20(); }
void Resource::AddReference() noexcept
{
    if (references == std::numeric_limits<unsigned>::max()) std::terminate();
    ++references;
}
void Resource::ReleaseReference() noexcept { if (--references == 0) delete this; }
void Resource::TakeBuffer(void* data, std::size_t bytes, void* object, const hkEntryD479* type)
{
    // Allocate both control blocks before taking the producer guard's buffer.
    // A failure here leaves that guard as the sole construction/cleanup owner.
    auto allocation = std::make_shared<ResourceBufferAllocation>(supplier, bytes);
    auto contents = std::make_shared<ResourceBufferContents>(allocation);
    allocation->data = data;
    bufferAllocation = std::move(allocation);
    bufferContents = std::move(contents);
    buffer = data; bufferBytes = bytes; root = object; metadata = type ? &retainedType : nullptr; live = true;
}
void Resource::TakeGraph(std::shared_ptr<const havok::serialize::NativeGraph> value)
{
    if (live || !value || !value->completed) throw std::runtime_error("invalid native graph transfer");
    auto object = value->Find(value->root);
    if (!object.NativeAddress()) throw std::runtime_error("native graph root is not constructed");
    root = const_cast<void*>(object.NativeAddress());
    completed = value->completed;
    graph = std::move(value);
    metadata = &retainedType;
    live = true;
}
havok::serialize::ObjectReference havok::serialize::NativeGraph::Find(Location location) const
{
    for (const auto& object : objects) if (object.location == location) return object.reference;
    throw std::runtime_error("location has no native graph identity");
}
havok::serialize::ObjectReference havok::serialize::NativeGraph::Reference(Location location) const
{
    for (const auto& reference : references) if (reference.field == location) return Find(reference.target);
    throw std::runtime_error("native graph field has no source reference");
}
void* havok::serialize::ResourceStorage::contents(const char*, const TypeRegistry*) const noexcept { return root; }
const char* havok::serialize::ResourceStorage::name() const noexcept { return retainedName.empty() ? nullptr : retainedName.c_str(); }
void havok::serialize::ResourceStorage::CaptureType(const hkEntryD479* type, int mode)
{
    if (!type || !type->name) throw std::runtime_error("resource root has no registered type");
    retainedName = type->name;
    retainedType = *type;
    retainedType.name = retainedName.c_str();
    finishing = mode;
}
std::shared_ptr<void> Resource::KeepNativeObject(void* pointer) const
{
    // Alias the genuine completed-object owner, not the resource wrapper.
    // Its final destruction cleans the envelope before releasing its buffer.
    return std::shared_ptr<void>(bufferContents, pointer);
}
havok::serialize::ObjectReference havok::serialize::ResourceStorage::LegacyNativeObject(void* pointer) const
{
    auto& header = *static_cast<LegacyHeader*>(LegacyPackfileBuffer(buffer));
    auto found = std::find_if(header.finished.begin(), header.finished.end(),
        [&](const Finished& value) { return value.object == pointer; });
    if (found == header.finished.end()) throw std::runtime_error("location has no completed native object identity");
    const auto& type = found->retained;
    if (!type.nativeClass || type.nativeClass->m_iObjectSize <= 0 ||
        static_cast<std::size_t>(type.nativeClass->m_iObjectSize) != type.nativeSize)
        throw std::runtime_error("native object query requires its actual native class contract");
    return ObjectReference(KeepNativeObject(pointer), type.nativeClass, type.nativeClassStorage);
}
havok::serialize::ObjectReference havok::serialize::ResourceStorage::NativeContents() const
{
    if (!live) return {{}, {}};
    if (graph) return graph->Find(graph->root);
    if (HasNativeObjects(buffer)) return PackfileRoot(buffer);
    // Preserve the explicit class-registry root path for older native-layout
    // providers without a per-object class descriptor. Never infer one.
    return retainedType.nativeClass ? LegacyNativeObject(root) : ObjectReference{{}, {}};
}
havok::serialize::ObjectReference havok::serialize::ResourceStorage::NativeObject(Location loc) const
{
    if (!live) return {{}, {}};
    if (graph) return graph->Find(loc);
    if (HasNativeObjects(buffer)) return PackfileObject(buffer, loc);
    auto& header = *static_cast<LegacyHeader*>(LegacyPackfileBuffer(buffer));
    return LegacyNativeObject(header.Object(loc.section, loc.offset));
}
havok::serialize::ObjectReference havok::serialize::ResourceStorage::NativeReference(Location loc) const
{
    if (!live) return {{}, {}};
    if (graph) return graph->Reference(loc);
    if (HasNativeObjects(buffer)) return PackfileReference(buffer, loc);
    auto& header = *static_cast<LegacyHeader*>(LegacyPackfileBuffer(buffer));
    auto found = std::find_if(header.fixups.begin(), header.fixups.end(),
        [&](const auto& fixup) { return fixup.from == loc; });
    if (found == header.fixups.end()) throw std::runtime_error("native pointer field has no source fixup");
    return NativeObject(found->target);
}
std::vector<havok::serialize::SymbolLocation> havok::serialize::ResourceStorage::NativeSymbols(bool imports) const
{
    if (!live) return {};
    if (graph) return imports ? graph->imports : graph->exports;
    if (HasNativeObjects(buffer)) return PackfileSymbols(buffer, imports);
    auto& header = *static_cast<LegacyHeader*>(LegacyPackfileBuffer(buffer));
    std::vector<SymbolLocation> result;
    for (std::size_t i = 0; i < header.sections.size(); ++i)
    {
        const auto& section = header.sections[i];
        const int first = imports ? section.header.exportEnd : section.header.exportStart;
        const int last = imports ? section.header.end : section.header.exportEnd;
        ValidateRecords(section.header, section.storage.data(), first, last);
        Bytes bytes(reinterpret_cast<const std::byte*>(section.storage.data()), Positive(last));
        for (std::size_t at = Positive(first); at < Positive(last);)
        {
            const int offset = Word(bytes, at); at += 4;
            if (offset == -1) break;
            const char* name = Text(bytes, at);
            result.push_back({name, {static_cast<int>(i), offset}});
            at += (std::strlen(name) + 1 + 3) & ~std::size_t(3);
        }
    }
    return result;
}
bool havok::serialize::ResourceStorage::FinishedWith(const TypeRegistry& types, const void* rootIdentity) const noexcept
{
    // The producer has already completed this exact mode. Never finish an
    // already-constructed native object twice, or record uncompleted identities.
    if (!live || !completed || finishing != types.finish || completed->objects.empty()) return false;
    bool rootCompleted = false;
    for (const auto& object : completed->objects)
    {
        if (!object.object || object.finishing != types.finish ||
            !object.Accepts(types.types.Lookup(object.serializedType.c_str()))) return false;
        if (object.object == rootIdentity) rootCompleted = true;
    }
    return rootCompleted;
}
const hkEntryD479* havok::serialize::ResourceStorage::TypeInfo() const noexcept { return metadata; }
std::vector<const void*> havok::serialize::ResourceStorage::AllocationPointers() const
{
    if (!live) return {};
    if (graph) return graph->allocations;
    // The envelope is the allocation actually owned here. Mesh internals have
    // their separate owners; do not fabricate a complete recursive census.
    return buffer ? std::vector<const void*>{buffer} : std::vector<const void*>{};
}
// @fnv 0x00dc0ec0
void* FUN_00dc0ec0_cls::FUN_00dc0ec0(intptr_t, intptr_t) const noexcept { return root; }
// @fnv 0x00dc0ed0
void FUN_00dc0ed0_class::FUN_00dc0ed0(intptr_t imports, intptr_t exports)
{
    if (!live) return;
    if (graph || havok::serialize::HasNativeObjects(buffer))
    {
        // Four-byte import locations are not native writable pointer slots.
        // The native-world caller consumes explicit section/offset locations.
        throw std::runtime_error("native resource requires typed symbol locations");
    }
    ProcessElements(reinterpret_cast<intptr_t>(havok::serialize::LegacyPackfileBuffer(buffer)), exports, imports);
}
// @fnv 0x00dc0ef0
void FUN_00dc0ef0_class::FUN_00dc0ef0() noexcept
{
    const bool wasLive = live;
    live = false;
    root = nullptr; metadata = nullptr;
    if (wasLive)
    {
        if (graph) graph.reset();
        else bufferContents.reset();
    }
}
// @fnv 0x00dc0f20
void Resource::FUN_00dc0f20() noexcept
{
    FUN_00dc0ef0();
    bufferAllocation.reset();
    buffer = nullptr; bufferBytes = 0;
}
// @fnv 0x00dc0cd0
void* CreateResourceFromArray(void* data, void* size, void* registry, havok::serialize::LoadError* error) try
{
    if (error) { error->status = 0; error->message.clear(); }
    (void)Parse(data, size); // retain the actual validation diagnostic
    const int needed = FUN_00dc07d0(data, size);
    if (needed <= 0) throw std::runtime_error("packfile envelope sizing failed");
    auto supplier = havok::serialize::AcquirePackfileSupplier();
    void* buffer = supplier->Allocate(static_cast<std::size_t>(needed));
    if (!buffer) throw std::bad_alloc();
    struct Guard
    {
        std::shared_ptr<havok::native_memory::Allocator> supplier;
        void* buffer;
        std::size_t bytes;
        bool constructed = false;
        ~Guard()
        {
            if (buffer)
            {
                if (constructed) FUN_00dc0de0(reinterpret_cast<S_00dc0de0*>(buffer));
                supplier->Free(buffer, bytes);
            }
        }
    } guard{supplier, buffer, static_cast<std::size_t>(needed)};
    havok::serialize::LoadContext context;
    context.registry = registry ? registry : &havok::serialize::DefaultPackfileRegistry();
    context.finishing = PackfileRegistryFinishing(context.registry);
    context.lookupType = PackfileRegistryTypeInfo;
    context.supplier = supplier;
    context.legacyOutputBytes = sizeof(LegacyHeader);
    context.unpackLegacy = UnpackLegacyPackfile;
    context.cleanupLegacy = CleanupLegacyPackfile;
    context.nativeTypes = static_cast<const havok::serialize::TypeRegistry*>(context.registry);
    void* root = UnpackPackfile(data, size, buffer, needed, &context);
    guard.constructed = true;
    if (havok::serialize::PackfileFailed(buffer))
        throw std::runtime_error(havok::serialize::PackfileError(buffer));
    const hkEntryD479* type = nullptr;
    std::shared_ptr<const havok::serialize::CompletionLedger> completed;
    if (havok::serialize::HasNativeObjects(buffer))
    {
        if (!havok::serialize::PackfileRoot(buffer).NativeAddress())
            throw std::runtime_error("resource root has no constructed native representation");
        type = static_cast<const hkEntryD479*>(havok::serialize::PackfileRootTypeInfo(buffer));
        completed = havok::serialize::PackfileCompletions(buffer);
    }
    else
    {
        auto& header = *static_cast<LegacyHeader*>(havok::serialize::LegacyPackfileBuffer(buffer));
        type = header.TypeInfo(root);
        completed = header.completion;
    }
    auto resource = std::make_unique<Resource>(supplier);
    resource->CaptureType(type, context.finishing);
    resource->CaptureCompleted(std::move(completed));
    resource->TakeBuffer(buffer, static_cast<std::size_t>(needed), root, type);
    guard.buffer = nullptr;
    return resource.release();
}
catch (const std::exception& failure)
{
    if (error)
    {
        error->status = 3;
        try { error->message = failure.what(); } catch (...) { error->message.clear(); }
    }
    return nullptr;
}
catch (...)
{
    if (error)
    {
        error->status = 3;
        try { error->message = "packfile native construction failed"; } catch (...) { error->message.clear(); }
    }
    return nullptr;
}
