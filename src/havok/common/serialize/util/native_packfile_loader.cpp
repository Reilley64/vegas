#include "havok/FastMesh.h"
#include "havok/NativePackfile.h"
#include "havok/hkClass.h"
#include "havok/BuiltinTypeRegistry.h"

#include <algorithm>
#include <bit>
#include <cstring>
#include <cstdio>
#include <limits>
#include <new>
#include <stdexcept>
#include <string_view>
#include <utility>

namespace havok::serialize
{
namespace
{
constexpr std::uint64_t envelopeMagic = 0x5041434b4f574e52ull;
struct Section
{
    std::vector<std::byte> bytes;
    int absolute = 0, local = 0, global = 0, virtuals = 0, exports = 0, imports = 0, end = 0;
};
struct Fixup { Location field, target; };
struct Finished { Location original; ObjectReference object; const void* typeInfo; std::string name; int recordedExtent; };
struct NativeState
{
    ~NativeState() { Clear(); }
    void Clear() noexcept
    {
        while (!finished.empty()) finished.pop_back();
        completion->objects.clear();
    }
    std::vector<Section> sections;
    std::vector<Fixup> fixups;
    std::vector<Finished> finished;
    std::vector<SymbolLocation> exports, imports;
    std::shared_ptr<CompletionLedger> completion = std::make_shared<CompletionLedger>();
    Location root;
    bool published = false;
};
struct alignas(std::max_align_t) Envelope
{
    std::uint64_t magic = envelopeMagic;
    std::unique_ptr<NativeState> native;
    void (*cleanupLegacy)(S_00dc0de0*) = nullptr;
    void* legacyRoot = nullptr;
    bool legacyLive = false;
    std::array<char, 192> error{};
};
static_assert(sizeof(Envelope) % alignof(std::max_align_t) == 0);

std::span<const std::byte> Slice(std::span<const std::byte> bytes, std::size_t start, std::size_t size)
{
    if (start > bytes.size() || size > bytes.size() - start)
        throw std::runtime_error("packfile extent outside its owner");
    return bytes.subspan(start, size);
}
std::uint32_t U32(std::span<const std::byte> bytes, std::size_t at)
{
    auto s = Slice(bytes, at, 4);
    return std::to_integer<unsigned>(s[0]) | (std::to_integer<unsigned>(s[1]) << 8) |
        (std::to_integer<unsigned>(s[2]) << 16) | (std::to_integer<unsigned>(s[3]) << 24);
}
int I32(std::span<const std::byte> bytes, std::size_t at)
{
    return std::bit_cast<std::int32_t>(U32(bytes, at));
}
float F32(std::span<const std::byte> bytes, std::size_t at) { return std::bit_cast<float>(U32(bytes, at)); }
std::size_t Nonnegative(int value)
{
    if (value < 0) throw std::runtime_error("negative packfile extent");
    return static_cast<std::size_t>(value);
}
std::size_t Nonnegative(std::int64_t value)
{
    if (value < 0) throw std::runtime_error("negative packfile extent");
    return static_cast<std::size_t>(value);
}
std::size_t Extent(int count, int stride, std::size_t width)
{
    const auto n = Nonnegative(count), step = Nonnegative(stride);
    if (!n) return 0;
    if (step && n - 1 > (std::numeric_limits<std::size_t>::max() - width) / step)
        throw std::runtime_error("packfile stream extent overflow");
    return (n - 1) * step + width;
}
const Section& GetSection(const NativeState& state, int index)
{
    if (index < 0 || static_cast<std::size_t>(index) >= state.sections.size())
        throw std::runtime_error("invalid packfile section");
    return state.sections[static_cast<std::size_t>(index)];
}
std::span<const std::byte> Bytes(const NativeState& state, Location loc, std::size_t length)
{
    return Slice(GetSection(state, loc.section).bytes, Nonnegative(loc.offset), length);
}
Location Target(const NativeState& state, Location loc)
{
    auto it = std::find_if(state.fixups.begin(), state.fixups.end(), [&](const Fixup& f) { return f.field == loc; });
    if (it == state.fixups.end()) throw std::runtime_error("missing packfile pointer fixup");
    return it->target;
}
std::span<const std::byte> Stream(const NativeState& state, Location field, std::size_t length)
{
    if (!length) return {};
    return Bytes(state, Target(state, field), length);
}
std::string Name(const NativeState& state, Location loc)
{
    const auto& section = GetSection(state, loc.section);
    auto bytes = Slice(section.bytes, Nonnegative(loc.offset), section.bytes.size() - Nonnegative(loc.offset));
    auto end = std::find(bytes.begin(), bytes.end(), std::byte{});
    if (end == bytes.end()) throw std::runtime_error("unterminated packfile class name");
    return {reinterpret_cast<const char*>(bytes.data()), static_cast<std::size_t>(end - bytes.begin())};
}
struct Virtual { Location object; std::string name; };
struct Parsed
{
    std::unique_ptr<NativeState> state = std::make_unique<NativeState>();
    std::vector<Virtual> virtuals;
};
bool NeedsNativeMaterialization(std::span<const std::byte> input, const LoadContext& context)
{
    Slice(input, 0, 64);
    const int count = I32(input, 20);
    Slice(input, 64, Extent(count, 48, 48));
    for (int i = 0; i < count; ++i)
    {
        const auto header = Slice(input, 64 + static_cast<std::size_t>(i) * 48, 48);
        const int first = I32(header, 32), last = I32(header, 36);
        if (first < 0 || last < first) throw std::runtime_error("invalid virtual fixup range");
        const auto section = Slice(input, Nonnegative(I32(header, 20)), Nonnegative(I32(header, 44)));
        for (std::int64_t j = first; j < last; j += 12)
        {
            if (I32(section, Nonnegative(j)) == -1) continue;
            if (last - j < 12) throw std::runtime_error("truncated virtual fixup");
            const int target = I32(section, Nonnegative(j) + 4);
            if (target < 0 || target >= count) throw std::runtime_error("invalid class-name section");
            const auto nameHeader = Slice(input, 64 + static_cast<std::size_t>(target) * 48, 48);
            const auto nameSection = Slice(input, Nonnegative(I32(nameHeader, 20)), Nonnegative(I32(nameHeader, 24)));
            const auto offset = Nonnegative(I32(section, Nonnegative(j) + 8));
            if (offset >= nameSection.size()) throw std::runtime_error("invalid class-name offset");
            auto name = nameSection.subspan(offset);
            auto end = std::find(name.begin(), name.end(), std::byte{});
            if (end == name.end()) throw std::runtime_error("unterminated class name");
            const auto className = reinterpret_cast<const char*>(name.data());
            if (std::string_view(className, static_cast<std::size_t>(end - name.begin())) == "hkpFastMeshShape") return true;
            if (context.nativeTypes)
                if (const auto* metadata = context.nativeTypes->types.Lookup(className); metadata && metadata->materialize)
                    return true;
        }
    }
    return false;
}
Parsed Parse(std::span<const std::byte> input)
{
    Slice(input, 0, 64);
    if (U32(input, 0) != 0x57e0e057 || U32(input, 4) != 0x10c0c010)
        throw std::runtime_error("invalid packfile magic");
    const int count = I32(input, 20);
    Slice(input, 64, Extent(count, 48, 48));
    Parsed parsed;
    auto& state = *parsed.state;
    state.root = {I32(input, 24), I32(input, 28)};
    for (int i = 0; i < count; ++i)
    {
        const auto h = 64 + static_cast<std::size_t>(i) * 48;
        Section section;
        section.absolute = I32(input, h + 20);
        section.local = I32(input, h + 24);
        section.global = I32(input, h + 28);
        section.virtuals = I32(input, h + 32);
        section.exports = I32(input, h + 36);
        section.imports = I32(input, h + 40);
        section.end = I32(input, h + 44);
        if (section.local < 0 || section.global < section.local || section.virtuals < section.global ||
            section.exports < section.virtuals || section.imports < section.exports || section.end < section.imports)
            throw std::runtime_error("invalid packfile section ranges");
        Slice(input, Nonnegative(section.absolute), Nonnegative(section.end));
        auto data = Slice(input, Nonnegative(section.absolute), Nonnegative(section.local));
        section.bytes.assign(data.begin(), data.end());
        state.sections.push_back(std::move(section));
    }
    // Two phases, as in UnpackPackfile: collect every local and global identity
    // before any virtual finish. Four-byte serialized pointer slots are never
    // overwritten with eight-byte host pointers.
    for (int phase = 0; phase < 2; ++phase)
        for (int i = 0; i < count; ++i)
        {
            const auto& s = state.sections[static_cast<std::size_t>(i)];
            const int first = phase ? s.global : s.local;
            const int last = phase ? s.virtuals : s.global;
            for (std::int64_t j = first; j < last; j += phase ? 12 : 8)
            {
                const auto at = Nonnegative(s.absolute) + Nonnegative(j);
                const int field = I32(input, at);
                if (field == -1) continue;
                if (last - j < (phase ? 12 : 8)) throw std::runtime_error("truncated pointer fixup");
                Location from{i, field};
                Location target{phase ? I32(input, at + 4) : i, I32(input, at + (phase ? 8 : 4))};
                Bytes(state, from, std::to_integer<unsigned>(input[16]));
                Bytes(state, target, 1);
                if (std::any_of(state.fixups.begin(), state.fixups.end(), [&](const Fixup& f) { return f.field == from; }))
                    throw std::runtime_error("duplicate packfile pointer field");
                state.fixups.push_back({from, target});
            }
        }
    for (int i = 0; i < count; ++i)
    {
        const auto& s = state.sections[static_cast<std::size_t>(i)];
        for (std::int64_t j = s.virtuals; j < s.exports; j += 12)
        {
            const auto at = Nonnegative(s.absolute) + Nonnegative(j);
            const int offset = I32(input, at);
            if (offset == -1) continue;
            if (s.exports - j < 12) throw std::runtime_error("truncated virtual fixup");
            auto name = Name(state, {I32(input, at + 4), I32(input, at + 8)});
            Bytes(state, {i, offset}, 1);
            parsed.virtuals.push_back({{i, offset}, std::move(name)});
        }
    }
    for (int i = 0; i < count; ++i)
    {
        const auto& s = state.sections[static_cast<std::size_t>(i)];
        const auto bytes = Slice(input, Nonnegative(s.absolute), Nonnegative(s.end));
        for (int imports = 0; imports != 2; ++imports)
        {
            const int first = imports ? s.imports : s.exports, last = imports ? s.end : s.imports;
            for (std::size_t at = Nonnegative(first); at < Nonnegative(last);)
            {
                Slice(bytes.first(Nonnegative(last)), at, 4);
                const int offset = I32(bytes, at); at += 4;
                if (offset == -1) break;
                Bytes(state, {i, offset}, imports ? 4 : 1);
                auto tail = Slice(bytes, at, Nonnegative(last) - at);
                const auto end = std::find(tail.begin(), tail.end(), std::byte{});
                if (end == tail.end()) throw std::runtime_error("unterminated packfile symbol");
                const std::size_t length = static_cast<std::size_t>(end - tail.begin());
                const std::size_t padded = (length + 1 + 3) & ~std::size_t(3);
                Slice(bytes.first(Nonnegative(last)), at, padded); at += padded;
                (imports ? state.imports : state.exports).push_back({
                    std::string(reinterpret_cast<const char*>(tail.data()), length), {i, offset}});
            }
        }
    }
    Bytes(state, state.root, 1);
    return parsed;
}

const Envelope* Owner(const void* output) noexcept { return static_cast<const Envelope*>(output); }
void Materialize(NativeState& state, const std::vector<Virtual>& objects, const LoadContext& context)
{
    if (!context.supplier) throw std::runtime_error("native packfile requires an owned supplier");
    state.finished.reserve(objects.size());
    state.completion->objects.reserve(objects.size());
    for (const auto& object : objects)
    {
        auto duplicate = std::find_if(state.finished.begin(), state.finished.end(), [&](const Finished& f) { return f.original == object.object; });
        if (duplicate != state.finished.end())
        {
            if (duplicate->name != object.name) throw std::runtime_error("conflicting native alias type");
            continue;
        }
        const void* typeInfo = context.lookupType ? context.lookupType(context.registry, object.name.c_str()) : nullptr;
        if (!typeInfo) throw std::runtime_error("fast-mesh finish type is not registered");
        const hkEntryD479* metadata = context.nativeTypes ? context.nativeTypes->types.Lookup(object.name.c_str()) : nullptr;
        const int extent = object.name == "hkpFastMeshShape" ? 96 : metadata ? metadata->size : 0;
        if (object.name == "hkpFastMeshShape" && metadata && metadata->size != 96)
            throw std::runtime_error("registered fast-mesh recorded extent does not match its decoder");
        if (extent <= 0) throw std::runtime_error("unsupported native serialized type extent");
        for (const auto& f : state.finished)
            if (f.original.section == object.object.section &&
                object.object.offset < static_cast<std::int64_t>(f.original.offset) + f.recordedExtent &&
                f.original.offset < static_cast<std::int64_t>(object.object.offset) + extent)
                throw std::runtime_error("overlapping serialized native identities");
        // Own the name before construction so completion insertion cannot lose
        // a finished identity on string allocation failure.
        std::string retainedName = object.name;
        CompletedIdentity completed{nullptr, object.name, context.finishing};
        completed.CaptureType(metadata);
        if (object.name != "hkpFastMeshShape")
        {
            if (!metadata || !metadata->materialize || !metadata->nativeClass || !metadata->nativeSize ||
                !metadata->nativeAlignment || metadata->nativeClass->m_iObjectSize < 0 ||
                metadata->nativeSize != static_cast<std::size_t>(metadata->nativeClass->m_iObjectSize))
                throw std::runtime_error("mixed type has no source-owned allocating decoder/class/layout");
            if (!metadata->nativeClassStorage)
                throw std::runtime_error("native allocating decoder has no class storage lease");
            ClassNameRegistry validation;
            validation.RegisterClass(metadata->nativeClass);
            auto native = metadata->materialize(Bytes(state, object.object, Nonnegative(extent)), context.finishing, context.supplier);
            if (!native || reinterpret_cast<std::uintptr_t>(native.get()) % metadata->nativeAlignment)
                throw std::runtime_error("native type materialization alignment failed");
            completed.object = native.get();
            state.finished.push_back({object.object,
                ObjectReference(std::move(native), metadata->nativeClass, metadata->nativeClassStorage),
                typeInfo, std::move(retainedName), extent});
            state.completion->objects.push_back(std::move(completed));
            continue;
        }
        const auto o = Bytes(state, object.object, 96); // fixed serialized extent, not sizeof(FastMesh)
        const int partCount = I32(o, 56), weldingCount = I32(o, 68);
        auto partsBytes = Stream(state, {object.object.section, object.object.offset + 52}, Extent(partCount, 56, 56));
        std::vector<fast_mesh::LoadedSubpart> parts;
        for (int i = 0; i < partCount; ++i)
        {
            const auto p = Slice(partsBytes, static_cast<std::size_t>(i) * 56, 56);
            const auto base = Target(state, {object.object.section, object.object.offset + 52});
            auto field = [&](int offset) { return Location{base.section, base.offset + i * 56 + offset}; };
            fast_mesh::LoadedSubpart part;
            // The retained triangle extractor, not misleading reflected names,
            // proves these stream meanings (subpart +0 and +0xc are geometry).
            part.vertexStride = I32(p, 4); part.vertexCount = I32(p, 8);
            part.indexType = std::to_integer<unsigned>(p[16]);
            part.materialIndexType = std::to_integer<unsigned>(p[17]);
            part.triangleStride = I32(p, 20); part.flipAlternateTriangles = U32(p, 24);
            part.triangleCount = I32(p, 28); part.materialIndexStride = I32(p, 36);
            part.materialStride = I32(p, 44); part.materialCount = I32(p, 48); part.weldingOffset = I32(p, 52);
            if (part.indexType != 1 && part.indexType != 2) throw std::runtime_error("unsupported mesh index type");
            const unsigned materialType = part.materialIndexType == 0 && context.finishing ? 1 : part.materialIndexType;
            if (materialType > 2) throw std::runtime_error("unsupported material index type");
            part.vertices = Stream(state, field(0), Extent(part.vertexCount, part.vertexStride, 12));
            part.indices = Stream(state, field(12), Extent(part.triangleCount, part.triangleStride, part.indexType == 1 ? 6 : 12));
            const auto materialCount = Nonnegative(part.materialCount);
            const auto materialStride = Nonnegative(part.materialStride);
            if (materialStride && materialCount > std::numeric_limits<std::size_t>::max() / materialStride)
                throw std::runtime_error("material extent overflow");
            part.materials = Stream(state, field(40), materialCount * materialStride);
            // Type zero on finish(0) does not consume an index stream. Preserve
            // supplied bytes, but do not require a pointer to unused storage.
            const bool hasMaterialIndices = std::any_of(state.fixups.begin(), state.fixups.end(),
                [&](const Fixup& fixup) { return fixup.field == field(32); });
            if (part.materialCount && (materialType || hasMaterialIndices))
                part.materialIndices = Stream(state, field(32), Extent(part.triangleCount, part.materialIndexStride, materialType == 2 ? 2 : 1));
            parts.push_back(part);
        }
        std::vector<std::uint16_t> welding;
        auto weldBytes = Stream(state, {object.object.section, object.object.offset + 64}, Extent(weldingCount, 2, 2));
        for (std::size_t i = 0; i < weldBytes.size(); i += 2)
            welding.push_back(static_cast<std::uint16_t>(std::to_integer<unsigned>(weldBytes[i]) |
                (std::to_integer<unsigned>(weldBytes[i + 1]) << 8)));
        fast_mesh::LoadedMesh mesh;
        mesh.scaling = {F32(o, 32), F32(o, 36), F32(o, 40)};
        mesh.subpartBits = I32(o, 48); mesh.subparts = parts; mesh.welding = welding;
        mesh.weldingType = std::to_integer<unsigned>(o[76]); mesh.radius = F32(o, 80);
        mesh.userData = U32(o, 8); mesh.shapeType = U32(o, 12);
        mesh.collectionType = std::to_integer<unsigned>(o[21]); mesh.disableWelding = o[20] != std::byte{};
        mesh.shapeKeys = {I32(o, 84), I32(o, 88), I32(o, 92)};
        // This is a separate genuine native construction. Registry callback
        // metadata and native identity are not interchangeable return values.
        auto native = fast_mesh::FastMesh::Finish(mesh, context.finishing, context.supplier);
        completed.object = native.get();
        state.finished.push_back({object.object, ObjectReference(std::move(native), {}), typeInfo, std::move(retainedName), 96});
        state.completion->objects.push_back(std::move(completed));
    }
}
void CheckNativeIdentity(const NativeState& state, Location loc)
{
    for (const auto& object : state.finished)
        if (loc.section == object.original.section && loc.offset > object.original.offset &&
            static_cast<std::int64_t>(loc.offset) - object.original.offset < object.recordedExtent)
            throw std::runtime_error("interior native mesh reference has no typed field boundary");
}
ObjectReference Resolve(const NativeState& state, Location loc)
{
    if (!state.published) return {{}, {}};
    CheckNativeIdentity(state, loc);
    auto it = std::find_if(state.finished.begin(), state.finished.end(), [&](const Finished& f) { return f.original == loc; });
    if (it != state.finished.end()) return it->object;
    const auto& section = GetSection(state, loc.section);
    const auto offset = Nonnegative(loc.offset);
    return {{}, Slice(section.bytes, offset, section.bytes.size() - std::min(offset, section.bytes.size()))};
}
}

std::vector<SymbolLocation> PackfileSymbols(const void* output, bool imports)
{
    const auto& e = *Owner(output);
    if (!e.native || !e.native->published) return {};
    return imports ? e.native->imports : e.native->exports;
}
std::shared_ptr<const CompletionLedger> PackfileCompletions(const void* output)
{
    const auto& e = *Owner(output);
    return e.native && e.native->published ? e.native->completion : nullptr;
}
std::size_t PackfileEnvelopeSize() noexcept { return sizeof(Envelope); }
bool HasNativeObjects(const void* output) noexcept { return Owner(output)->native != nullptr; }
bool PackfileFailed(const void* output) noexcept { return Owner(output)->error[0] != '\0'; }
void* LegacyPackfileBuffer(void* output) noexcept { return static_cast<std::byte*>(output) + sizeof(Envelope); }
const void* PackfileRootTypeInfo(const void* output) noexcept
{
    const auto& e = *Owner(output);
    if (e.native && e.native->published)
        for (const auto& object : e.native->finished)
            if (object.original == e.native->root) return object.typeInfo;
    return nullptr;
}
ObjectReference PackfileRoot(const void* output)
{
    const auto& e = *Owner(output);
    return e.native ? Resolve(*e.native, e.native->root) : ObjectReference{{}, {}};
}
ObjectReference PackfileObject(const void* output, Location loc)
{
    const auto& e = *Owner(output);
    return e.native ? Resolve(*e.native, loc) : ObjectReference{{}, {}};
}
ObjectReference PackfileReference(const void* output, Location field)
{
    const auto& e = *Owner(output);
    return e.native ? Resolve(*e.native, Target(*e.native, field)) : ObjectReference{{}, {}};
}
std::string PackfileError(const void* output) { return Owner(output)->error.data(); }

PackfileResource::PackfileResource(std::span<const std::byte> input, LoadContext context)
{
    // Native loads retain section copies in their owner, not in a guessed legacy
    // fixed header/map extent. The legacy resource entry supplies its full size.
    if (context.legacyOutputBytes > static_cast<std::size_t>(std::numeric_limits<int>::max()) - sizeof(Envelope) - sizeof(std::max_align_t))
        throw std::length_error("packfile output size overflow");
    buffer.resize((sizeof(Envelope) + context.legacyOutputBytes + sizeof(std::max_align_t) - 1) / sizeof(std::max_align_t));
    UnpackPackfile(const_cast<std::byte*>(input.data()), reinterpret_cast<void*>(input.size()), buffer.data(),
        static_cast<int>(buffer.size() * sizeof(std::max_align_t)), &context);
}
PackfileResource::~PackfileResource() { Cleanup(); }
void PackfileResource::Cleanup() noexcept
{
    if (!buffer.empty())
    {
        FUN_00dc0de0(reinterpret_cast<S_00dc0de0*>(buffer.data()));
        std::vector<std::max_align_t>().swap(buffer);
    }
}
ObjectReference PackfileResource::Root() const { return buffer.empty() ? ObjectReference{{}, {}} : PackfileRoot(buffer.data()); }
ObjectReference PackfileResource::Object(Location loc) const { return buffer.empty() ? ObjectReference{{}, {}} : PackfileObject(buffer.data(), loc); }
ObjectReference PackfileResource::Reference(Location loc) const { return buffer.empty() ? ObjectReference{{}, {}} : PackfileReference(buffer.data(), loc); }
std::string PackfileResource::Error() const { return buffer.empty() ? "resource cleaned" : PackfileError(buffer.data()); }
}

// Source-backed extraction of the existing loader entry; the old definition is
// removed from hknativepackfileutils.cpp. No generated table is a native vtable.
// @fnv 0x00dc0940
extern "C" void* UnpackPackfile(void* data, void* size, void* output, int outputSize,
    havok::serialize::LoadContext* context) noexcept
{
    using namespace havok::serialize;
    if (!output || outputSize < static_cast<int>(sizeof(Envelope)) ||
        reinterpret_cast<std::uintptr_t>(output) % alignof(Envelope)) return nullptr;
    auto& owner = *new (output) Envelope;
    try
    {
        if (!context) throw std::runtime_error("missing packfile load context");
        if (!data) throw std::runtime_error("null packfile input");
        auto input = std::span(static_cast<const std::byte*>(data), reinterpret_cast<std::uintptr_t>(size));
        if (!NeedsNativeMaterialization(input, *context))
        {
            if (!context->unpackLegacy || !context->cleanupLegacy || !context->legacyOutputBytes ||
                context->legacyOutputBytes > static_cast<std::size_t>(outputSize) - sizeof(Envelope))
                throw std::runtime_error("legacy packfile closure unavailable");
            owner.cleanupLegacy = context->cleanupLegacy;
            owner.legacyRoot = context->unpackLegacy(data, size, LegacyPackfileBuffer(output),
                outputSize - static_cast<int>(sizeof(Envelope)), context->registry);
            owner.legacyLive = true;
            return owner.legacyRoot;
        }
        const unsigned pointerBytes = std::to_integer<unsigned>(input[16]);
        if ((pointerBytes != 4 && pointerBytes != 8) || input[17] != std::byte{1})
            throw std::runtime_error("unsupported serialized pointer/byte order contract");
        auto parsed = Parse(input);
        owner.native = std::move(parsed.state);
        if (pointerBytes != 4 && std::any_of(parsed.virtuals.begin(), parsed.virtuals.end(),
            [](const Virtual& object) { return object.name == "hkpFastMeshShape"; }))
            throw std::runtime_error("unsupported fast-mesh serialized layout");
        Materialize(*owner.native, parsed.virtuals, *context);
        for (const auto& f : owner.native->fixups)
            CheckNativeIdentity(*owner.native, f.target);
        CheckNativeIdentity(*owner.native, owner.native->root);
        owner.native->published = true;
        return nullptr;
    }
    catch (const std::exception& error)
    {
        if (owner.native) owner.native->Clear();
        std::snprintf(owner.error.data(), owner.error.size(), "%s", error.what());
    }
    catch (...)
    {
        if (owner.native) owner.native->Clear();
        std::snprintf(owner.error.data(), owner.error.size(), "%s", "packfile finish failed");
    }
    return nullptr;
}

// @fnv 0x00dc0de0
void FUN_00dc0de0(S_00dc0de0* output)
{
    using namespace havok::serialize;
    if (!output) return;
    auto& owner = *reinterpret_cast<Envelope*>(output);
    if (owner.magic != envelopeMagic) std::terminate();
    if (owner.legacyLive) owner.cleanupLegacy(reinterpret_cast<S_00dc0de0*>(LegacyPackfileBuffer(output)));
    owner.~Envelope();
}
