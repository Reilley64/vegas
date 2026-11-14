#include "havok/Dictionary.h"
#include "havok/NativeGraph.h"
#include "havok/hkClassMember.h"
#include <algorithm>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <unordered_map>

namespace havok::serialize::dictionary
{
namespace
{
using M = hkClassMember;
struct Arena
{
    struct Block { void* data; std::size_t bytes; };
    struct Finished { void* data; hkEntryD479 type; };
    explicit Arena(std::shared_ptr<native_memory::Allocator> supplier) : supplier(std::move(supplier)) {}
    ~Arena()
    {
        // Only completed construction enters this ledger; allocations and
        // construction are separate, and all dependent storage remains alive
        // through reverse completed-prefix destruction.
        while (!finished.empty())
        {
            auto& object = finished.back();
            if (object.type.cleanup) object.type.cleanup(object.data);
            finished.pop_back();
        }
        while (!blocks.empty())
        {
            auto block = blocks.back(); blocks.pop_back(); supplier->Free(block.data, block.bytes);
        }
    }
    void* Allocate(std::size_t bytes)
    {
        if (!bytes) return nullptr;
        void* data = supplier->Allocate(bytes);
        if (!data) throw std::bad_alloc();
        try { blocks.push_back({data, bytes}); }
        catch (...) { supplier->Free(data, bytes); throw; }
        return data;
    }
    void Construct(void* data, const hkEntryD479& type, int finishing)
    {
        // Snapshot and reserve before invoking a real finish constructor. A
        // throwing constructor owns its own incomplete subobject unwind.
        Finished record{data, type};
        finished.reserve(finished.size() + 1);
        type.m_func(data, finishing);
        finished.push_back(std::move(record));
    }
    std::shared_ptr<native_memory::Allocator> supplier;
    std::vector<Block> blocks;
    std::vector<Finished> finished;
};
struct Target { void* address; const hkEntryD479* type; };
class Converter
{
public:
    Converter(const RefObj& source, const ClassNameRegistry& classes, const TypeRegistry& types,
        std::shared_ptr<native_memory::Allocator> supplier)
        : source(source), classes(classes), types(types), arena(std::make_shared<Arena>(std::move(supplier))),
          graph(std::make_shared<NativeGraph>()), completion(std::make_shared<CompletionLedger>()) {}
    std::shared_ptr<Resource> Convert()
    {
        if (!source || !arena->supplier) throw std::invalid_argument("dictionary conversion requires world and supplier owners");
        Target root = Object(source.object, 0);
        graph->root = Identity(source.object);
        graph->completed = completion;
        for (const auto& block : arena->blocks) graph->allocations.push_back(block.data);
        auto resource = std::shared_ptr<Resource>(new Resource(arena->supplier), [](Resource* value) { value->ReleaseReference(); });
        resource->CaptureType(root.type, types.finish);
        resource->TakeGraph(graph);
        return resource;
    }
private:
    [[noreturn]] static void Fail(const std::string& text) { throw std::runtime_error(text); }
    static Location Identity(Value::ObjectId id)
    {
        if (id.value > static_cast<std::size_t>(std::numeric_limits<int>::max())) Fail("dictionary identity overflow");
        return {static_cast<int>(id.value), 0};
    }
    const hkEntryD479& Type(const Class& sourceType)
    {
        auto& cached = contracts[sourceType.name];
        if (cached) return *cached;
        const auto* entry = types.types.Lookup(sourceType.name.c_str());
        const auto* klass = classes.Find(sourceType.name.c_str());
        if (!entry || !klass || entry->nativeClass != klass || !entry->nativeClassStorage ||
            !entry->m_func || !entry->cleanup || !entry->nativeSize || !entry->nativeAlignment ||
            entry->nativeAlignment > 16 || (entry->nativeAlignment & (entry->nativeAlignment - 1)) ||
            klass->m_iObjectSize <= 0 || entry->nativeSize != static_cast<std::size_t>(klass->m_iObjectSize))
            Fail("no complete native construction/layout contract for dictionary class " + sourceType.name);
        if (klass->m_flags & hkClass::FLAGS_NOT_SERIALIZABLE) Fail("native class is not dictionary-serializable: " + sourceType.name);
        if (sourceType.version != klass->m_iDescribedVersion) Fail("dictionary class version mismatch: " + sourceType.name);
        if (bool(sourceType.parent) != bool(klass->m_parent) ||
            (sourceType.parent && sourceType.parent->name != klass->m_parent->m_name))
            Fail("dictionary parent class mismatch: " + sourceType.name);
        auto owned = std::make_unique<hkEntryD479>(*entry);
        // The stable key owns the copied metadata's name, independent of the
        // source producer and registry lifetime. Class storage owns descriptors.
        owned->name = klass->m_name;
        cached = std::move(owned);
        return *cached;
    }
    static std::vector<const M*> Members(const hkClass& klass)
    {
        auto fields = klass.m_parent ? Members(*klass.m_parent) : std::vector<const M*>{};
        if (klass.m_kDeclaredMembers.m_iElementCount < 0 ||
            (klass.m_kDeclaredMembers.m_iElementCount && !klass.m_kDeclaredMembers.m_data)) Fail("invalid native class member storage");
        for (int i = 0; i < klass.m_kDeclaredMembers.m_iElementCount; ++i) fields.push_back(&klass.m_kDeclaredMembers.m_data[i]);
        return fields;
    }
    static std::size_t Width(unsigned type)
    {
        switch (type)
        {
        case M::TYPE_BOOL: case M::TYPE_CHAR: case M::TYPE_INT8: case M::TYPE_UINT8: return 1;
        case M::TYPE_INT16: case M::TYPE_UINT16: return 2;
        case M::TYPE_INT32: case M::TYPE_UINT32: case M::TYPE_REAL: return 4;
        case M::TYPE_INT64: case M::TYPE_UINT64: return 8;
        case M::TYPE_POINTER: case M::TYPE_CSTRING: case M::TYPE_STRINGPTR: return sizeof(void*);
        case M::TYPE_SIMPLEARRAY: return sizeof(hkSimpleArray<std::byte>);
        case M::TYPE_ARRAY: return sizeof(hkArray<std::byte>);
        default: Fail("unsupported native dictionary field type " + std::to_string(type));
        }
    }
    void Schema(const Member& sourceMember, const M& native, std::size_t extent)
    {
        if (!native.m_name || sourceMember.name != native.m_name || native.m_flags & M::SERIALIZE_IGNORED || native.m_iArraySize)
            Fail("unsupported or mismatched native dictionary member " + sourceMember.name);
        const auto width = Width(native.m_type);
        if (native.m_offset > extent || width > extent - native.m_offset) Fail("native dictionary member outside evidenced extent: " + sourceMember.name);
        const bool array = (sourceMember.type & 0x30) != 0;
        if (array != (native.m_type == M::TYPE_ARRAY || native.m_type == M::TYPE_SIMPLEARRAY))
            Fail("dictionary array representation mismatch: " + sourceMember.name);
        if (array && (sourceMember.type & 0xf) == 8)
            Fail("dictionary pointer-array source provenance is not migrated: " + sourceMember.name);
        const unsigned type = array ? native.m_eSubtype : native.m_type;
        const unsigned sourceType = sourceMember.type & 0xf;
        const bool integer = type >= M::TYPE_CHAR && type <= M::TYPE_UINT64;
        if (!((sourceType == 1 && type == M::TYPE_BOOL) || (sourceType == 2 && integer) ||
            (sourceType == 3 && type == M::TYPE_REAL) || (sourceType == 8 && type == M::TYPE_POINTER) ||
            (sourceType == 9 && type == M::TYPE_STRUCT) ||
            (sourceType == 10 && (type == M::TYPE_CSTRING || type == M::TYPE_STRINGPTR))))
            Fail("dictionary/native field type mismatch: " + sourceMember.name);
        if ((sourceType == 8 || sourceType == 9) && native.m_class && sourceMember.className != native.m_class->m_name)
            Fail("dictionary member class mismatch: " + sourceMember.name);
    }
    Target Create(Value::ObjectId id, void* address)
    {
        const auto& object = source.world->Get(id);
        if (!object.type) Fail("dictionary object has no class");
        const auto& type = Type(*object.type);
        if (!address) address = arena->Allocate(type.nativeSize);
        if (reinterpret_cast<std::uintptr_t>(address) % type.nativeAlignment) Fail("native dictionary allocation alignment mismatch");
        arena->Construct(address, type, types.finish);
        Target target{address, &type};
        targets.emplace(id.value, target);
        CompletedIdentity finished{address, object.type->name, types.finish}; finished.CaptureType(&type);
        completion->objects.push_back(std::move(finished));
        graph->objects.push_back({Identity(id), ObjectReference(std::shared_ptr<void>(arena, address), type.nativeClass, type.nativeClassStorage)});
        return target;
    }
    Target Object(Value::ObjectId id, unsigned depth)
    {
        auto existing = targets.find(id.value);
        if (existing != targets.end()) return existing->second;
        if (depth > 128) Fail("dictionary native conversion nesting limit");
        Target target = Create(id, nullptr);
        Fill(id, target, depth + 1);
        return target;
    }
    void Fill(Value::ObjectId id, Target target, unsigned depth)
    {
        const auto& object = source.world->Get(id);
        auto fields = object.type->Members();
        const auto native = Members(*target.type->nativeClass);
        if (fields.size() != object.members.size()) Fail("dictionary member/value count mismatch");
        for (std::size_t i = 0; i < fields.size(); ++i)
        {
            auto found = std::find_if(native.begin(), native.end(), [&](const M* member) {
                return member->m_name && fields[i]->name == member->m_name;
            });
            if (found == native.end()) Fail("unknown native dictionary member " + object.type->name + "." + fields[i]->name);
            const M& member = **found;
            Schema(*fields[i], member, target.type->nativeSize);
            void* out = static_cast<std::byte*>(target.address) + member.m_offset;
            Write(object.members[i], *fields[i], member, out, id, depth);
        }
    }
    template<class T> static void Integer(void* out, std::int64_t value)
    {
        if constexpr (std::is_unsigned_v<T>)
        {
            if (value < 0 || std::uint64_t(value) > std::numeric_limits<T>::max()) Fail("dictionary unsigned primitive overflow");
        }
        else if (value < std::numeric_limits<T>::min() || value > std::numeric_limits<T>::max()) Fail("dictionary signed primitive overflow");
        const T narrowed = static_cast<T>(value); std::memcpy(out, &narrowed, sizeof(T));
    }
    void Write(const Value& value, const Member& sourceMember, const M& member, void* out, Value::ObjectId owner, unsigned depth)
    {
        if (std::holds_alternative<std::monostate>(value.data)) return; // real value-initialized/default construction
        if (member.m_type == M::TYPE_SIMPLEARRAY || member.m_type == M::TYPE_ARRAY)
        {
            const auto* id = std::get_if<Value::ArrayId>(&value.data);
            if (!id) Fail("dictionary array value mismatch: " + sourceMember.name);
            Array(*id, sourceMember, member, out, owner, depth + 1); return;
        }
        if (const auto* integer = std::get_if<std::int64_t>(&value.data))
        {
            switch (member.m_type)
            {
            case M::TYPE_BOOL: if (*integer != 0 && *integer != 1) Fail("dictionary boolean outside 0/1"); [[fallthrough]];
            case M::TYPE_UINT8: Integer<std::uint8_t>(out, *integer); return;
            case M::TYPE_CHAR: case M::TYPE_INT8: Integer<std::int8_t>(out, *integer); return;
            case M::TYPE_UINT16: Integer<std::uint16_t>(out, *integer); return;
            case M::TYPE_INT16: Integer<std::int16_t>(out, *integer); return;
            case M::TYPE_UINT32: Integer<std::uint32_t>(out, *integer); return;
            case M::TYPE_INT32: Integer<std::int32_t>(out, *integer); return;
            case M::TYPE_UINT64: Integer<std::uint64_t>(out, *integer); return;
            case M::TYPE_INT64: Integer<std::int64_t>(out, *integer); return;
            default: Fail("dictionary integer value/type mismatch");
            }
        }
        if (const auto* real = std::get_if<float>(&value.data))
        {
            if (member.m_type != M::TYPE_REAL) Fail("dictionary real value/type mismatch");
            std::memcpy(out, real, sizeof(*real)); return;
        }
        if (const auto* string = std::get_if<std::string>(&value.data))
        {
            if (member.m_type != M::TYPE_CSTRING && member.m_type != M::TYPE_STRINGPTR) Fail("dictionary string value/type mismatch");
            auto found = strings.find(*string);
            char* text;
            if (found != strings.end()) text = found->second;
            else
            {
                text = static_cast<char*>(arena->Allocate(string->size() + 1));
                std::memcpy(text, string->c_str(), string->size() + 1);
                strings.emplace(*string, text);
            }
            std::memcpy(out, &text, sizeof(text)); return;
        }
        if (const auto* object = std::get_if<Value::ObjectId>(&value.data))
        {
            if (member.m_type != M::TYPE_POINTER || !member.m_class) Fail("dictionary object requires typed native pointer member");
            auto target = Object(*object, depth + 1);
            if (target.type->nativeClass != member.m_class) Fail("dictionary reference target native class mismatch");
            std::memcpy(out, &target.address, sizeof(target.address));
            graph->references.push_back({{Identity(owner).section, member.m_offset}, Identity(*object)}); return;
        }
        Fail("unsupported dictionary value representation");
    }
    void Array(Value::ArrayId id, const Member& sourceMember, const M& member, void* out, Value::ObjectId owner, unsigned depth)
    {
        if (depth > 128) Fail("dictionary array conversion nesting limit");
        const auto& array = source.world->Get(id);
        const auto count = array.values.size();
        if (count > static_cast<std::size_t>(std::numeric_limits<int>::max())) Fail("dictionary array count overflow");
        if (array.element.type != (sourceMember.type & 0xf) || array.element.className != sourceMember.className)
            Fail("dictionary array element schema mismatch");
        if ((sourceMember.type & 0x20) && count != sourceMember.tuple) Fail("dictionary tuple extent mismatch");
        const hkEntryD479* elementType = nullptr;
        std::size_t width;
        if (member.m_eSubtype == M::TYPE_STRUCT)
        {
            if (!member.m_class) Fail("dictionary struct array has no native class");
            const Class* klass = source.world->FindClass(array.element.className);
            if (!klass) Fail("dictionary struct array has no source class");
            elementType = &Type(*klass); width = elementType->nativeSize;
            if (elementType->nativeClass != member.m_class) Fail("dictionary struct array class mismatch");
        }
        else width = Width(member.m_eSubtype);
        if (count > std::numeric_limits<std::size_t>::max() / width) Fail("dictionary array allocation overflow");
        auto* data = static_cast<std::byte*>(arena->Allocate(count * width));
        if (elementType)
        {
            // Reserve all embedded identities before filling any element. No
            // per-row allocation and no copied vtable/serialized extent.
            for (std::size_t i = 0; i < count; ++i)
            {
                const auto* row = std::get_if<Value::ObjectId>(&array.values[i].data);
                if (!row || targets.contains(row->value)) Fail("aliased struct-array storage identity is unsupported");
                if (source.world->Get(*row).type->name != array.element.className) Fail("struct-array row class mismatch");
                Create(*row, data + i * width);
            }
            for (const auto& value : array.values)
            {
                const auto row = std::get<Value::ObjectId>(value.data); Fill(row, targets.at(row.value), depth + 1);
            }
        }
        else
        {
            if (count) std::memset(data, 0, count * width);
            M scalar = member; scalar.m_type = member.m_eSubtype;
            for (std::size_t i = 0; i < count; ++i) Write(array.values[i], array.element, scalar, data + i * width, owner, depth + 1);
        }
        const int size = static_cast<int>(count);
        // Write the actual native array fields, not the old 12/8-byte wire view.
        if (member.m_type == M::TYPE_SIMPLEARRAY)
        {
            hkSimpleArray<std::byte> header{data, size}; std::memcpy(out, &header, sizeof(header));
        }
        else
        {
            hkArray<std::byte> header{data, size, int(std::uint32_t(size) | 0x80000000U)};
            std::memcpy(out, &header, sizeof(header));
        }
    }
    const RefObj& source;
    const ClassNameRegistry& classes;
    const TypeRegistry& types;
    std::shared_ptr<Arena> arena;
    std::shared_ptr<NativeGraph> graph;
    std::shared_ptr<CompletionLedger> completion;
    std::unordered_map<std::string, std::unique_ptr<hkEntryD479>> contracts;
    std::unordered_map<std::size_t, Target> targets;
    std::unordered_map<std::string, char*> strings;
};
}
std::shared_ptr<Resource> Convert(const RefObj& source, const ClassNameRegistry& classes, const TypeRegistry& types,
    std::shared_ptr<native_memory::Allocator> supplier)
{
    return Converter(source, classes, types, std::move(supplier)).Convert();
}
}
