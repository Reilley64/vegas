#include "havok/Dictionary.h"
#include <bit>
#include <limits>
#include <optional>
#include <stdexcept>

namespace havok::serialize::dictionary
{
namespace
{
// The retained reader's string and class tables start with a null entry;
// its string table additionally starts with the empty string. Indices are
// checked before access, unlike the old negative-index/stack-buffer views.
class Reader
{
public:
    explicit Reader(LoadStream& stream) : stream(stream), world(std::make_shared<World>()) {}
    RefObj Read()
    {
        if (Word() != 0xcab00d1eU || Word() != 0xd011faceU)
            Fail("binary tagfile magic mismatch");
        bool version = false;
        for (;;)
        {
            switch (Integer())
            {
            case 1:
                if (version || Integer() != 0) Fail("unsupported binary tagfile version");
                version = true; break;
            case 2:
                if (!version) Fail("tagfile class before version");
                ReadClass(); break;
            case 3: case 4:
            {
                // Tag is saved by Integer(), before the class id is consumed.
                const auto tag = lastInteger;
                if (!version) Fail("tagfile object before version");
                auto value = ReadObject(tag, 0);
                if (!std::holds_alternative<Value::ObjectId>(value.data)) Fail("null dictionary root");
                return {world, std::get<Value::ObjectId>(value.data)};
            }
            case 6: Fail("null dictionary root");
            default: Fail("unsupported top-level binary tagfile tag");
            }
        }
    }
private:
    [[noreturn]] static void Fail(const char* text) { throw std::runtime_error(text); }
    void Exact(std::span<std::byte> out)
    {
        if (out.size() > MaxBytes - bytes) Fail("tagfile exceeds admitted byte limit");
        while (!out.empty())
        {
            const auto count = stream.Read(out);
            if (!count || count > out.size()) Fail("truncated binary tagfile");
            bytes += count; out = out.subspan(count);
        }
    }
    unsigned Byte()
    {
        std::byte value; Exact({&value, 1}); return std::to_integer<unsigned>(value);
    }
    std::uint32_t Word()
    {
        std::uint32_t value = 0;
        for (unsigned i = 0; i < 4; ++i) value |= Byte() << (8 * i);
        return value;
    }
    std::int64_t Integer()
    {
        unsigned byte = Byte();
        const bool negative = (byte & 1) != 0;
        std::uint64_t value = (byte & 0x7e) >> 1;
        unsigned shift = 6;
        while (byte & 0x80)
        {
            byte = Byte();
            if (shift >= 64 || (std::uint64_t(byte & 0x7f) > (std::numeric_limits<std::uint64_t>::max() >> shift)))
                Fail("tagfile varint overflow");
            value |= std::uint64_t(byte & 0x7f) << shift;
            shift += 7;
        }
        const auto max = std::uint64_t(std::numeric_limits<std::int64_t>::max());
        if (value > max + unsigned(negative)) Fail("tagfile signed integer overflow");
        lastInteger = negative ? (value == max + 1 ? std::numeric_limits<std::int64_t>::min() : -static_cast<std::int64_t>(value))
                               : static_cast<std::int64_t>(value);
        return lastInteger;
    }
    std::size_t Count()
    {
        const auto count = Integer();
        if (count < 0 || count > static_cast<std::int64_t>(MaxItems)) Fail("invalid tagfile count/index");
        return static_cast<std::size_t>(count);
    }
    std::optional<std::string> StringValue()
    {
        const auto length = Integer();
        if (length <= 0)
        {
            if (length == std::numeric_limits<std::int64_t>::min() || static_cast<std::uint64_t>(-length) >= strings.size())
                Fail("invalid tagfile string reference");
            return strings[static_cast<std::size_t>(-length)];
        }
        if (length > static_cast<std::int64_t>(MaxBytes)) Fail("tagfile string too long");
        std::string text(static_cast<std::size_t>(length), '\0');
        Exact(std::as_writable_bytes(std::span(text)));
        if (text.find('\0') != std::string::npos) Fail("embedded null in tagfile string");
        if (strings.size() == MaxItems) Fail("too many tagfile strings");
        strings.push_back(text);
        return text;
    }
    std::string String() { return StringValue().value_or(""); }
    const Class& ClassAt(std::size_t index)
    {
        if (!index || index >= classes.size()) Fail("invalid tagfile class reference");
        return *classes[index];
    }
    void ReadClass()
    {
        const auto name = String();
        const auto version = Integer();
        if (version < 0 || version > std::numeric_limits<int>::max()) Fail("invalid dictionary class version");
        const auto parentIndex = Count();
        const Class* parent = parentIndex ? &ClassAt(parentIndex) : nullptr;
        const auto count = Count();
        std::vector<Member> members; members.reserve(count);
        for (std::size_t i = 0; i < count; ++i)
        {
            Member member; member.name = String();
            auto type = Count();
            if (type > 0x3f || !(type & 0xf) || (type & 0xf) > 10 || (type & 0x30) == 0x30)
                Fail("unsupported dictionary field type");
            member.type = static_cast<unsigned>(type);
            if (type & 0x20) member.tuple = static_cast<unsigned>(Count());
            if ((type & 0xf) == 8 || (type & 0xf) == 9) member.className = String();
            members.push_back(std::move(member));
        }
        if (classes.size() == MaxItems) Fail("too many dictionary classes");
        classes.push_back(&world->AddClass(name, static_cast<int>(version), parent, std::move(members)));
    }
    std::vector<bool> Bits(std::size_t count)
    {
        std::vector<bool> bits(count);
        for (std::size_t i = 0; i < count;)
        {
            unsigned byte = Byte();
            for (unsigned j = 0; j < 8 && i < count; ++j, ++i) bits[i] = (byte & (1U << j)) != 0;
        }
        return bits;
    }
    Value ReadObject(std::int64_t tag, unsigned depth)
    {
        if (depth > 128) Fail("dictionary nesting limit");
        if (tag == 6) return {};
        if (tag == 5)
        {
            const auto index = Count();
            if (!index || index >= remembered.size()) Fail("invalid remembered object reference");
            return Value{remembered[index]};
        }
        if (tag != 3 && tag != 4) Fail("invalid dictionary object tag");
        const Class& type = ClassAt(Count());
        if (world->ObjectCount() == MaxItems) Fail("too many dictionary objects");
        const auto id = world->AddObject(type);
        if (tag == 4) remembered.push_back(id); // before fields: aliases and cycles
        const auto members = type.Members();
        const auto present = Bits(members.size());
        for (std::size_t i = 0; i < members.size(); ++i)
            if (present[i]) world->Get(id).members[i] = ReadValue(*members[i], depth + 1);
        return Value{id};
    }
    Value ReadValue(const Member& member, unsigned depth)
    {
        if (depth > 128) Fail("dictionary nesting limit");
        if (member.type & 0x30)
        {
            const auto count = (member.type & 0x20) ? member.tuple : Count();
            Member element = member; element.type &= 0xf; element.tuple = 0;
            // The source has an additional class index for an untyped struct array.
            if (element.type == 9 && element.className.empty()) element.className = ClassAt(Count()).name;
            const auto id = world->AddArray(element, count);
            ReadArray(id, depth + 1);
            return Value{id};
        }
        switch (member.type)
        {
        case 1: return Value{std::int64_t(Byte())};
        case 2: return Value{Integer()};
        case 3: return Value{std::bit_cast<float>(Word())};
        case 8: case 9: return ReadObject(Integer(), depth + 1);
        case 10:
        {
            auto text = StringValue();
            return text ? Value{std::move(*text)} : Value{};
        }
        default: Fail("unsupported dictionary scalar/vector type");
        }
    }
    void ReadArray(Value::ArrayId id, unsigned depth)
    {
        const Member element = world->Get(id).element;
        const auto count = world->Get(id).values.size();
        if (element.type == 9)
        {
            const Class* type = world->FindClass(element.className);
            if (!type) Fail("unknown struct-array class");
            const auto members = type->Members();
            const auto present = Bits(members.size());
            std::vector<Value::ObjectId> rows; rows.reserve(count);
            for (std::size_t i = 0; i < count; ++i)
            {
                auto row = world->AddObject(*type); rows.push_back(row); world->Get(id).values[i] = Value{row};
            }
            // Source dc6100 stores struct arrays column-major with one member mask.
            for (std::size_t m = 0; m < members.size(); ++m)
                if (present[m]) for (const auto row : rows) world->Get(row).members[m] = ReadValue(*members[m], depth + 1);
            return;
        }
        for (std::size_t i = 0; i < count; ++i) world->Get(id).values[i] = ReadValue(element, depth + 1);
    }
    static constexpr std::size_t MaxItems = 65536, MaxBytes = 64 * 1024 * 1024;
    LoadStream& stream;
    std::shared_ptr<World> world;
    std::vector<const Class*> classes{nullptr};
    std::vector<std::optional<std::string>> strings{std::string{}, std::nullopt};
    std::vector<Value::ObjectId> remembered{{std::numeric_limits<std::size_t>::max()}};
    std::size_t bytes = 0;
    std::int64_t lastInteger = 0;
};
}
RefObj Read(LoadStream& input) { return Reader(input).Read(); }
}
