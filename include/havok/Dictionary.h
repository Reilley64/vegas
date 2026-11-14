#pragma once
#include "havok/NativeWorld.h"
#include "havok/SerializeEntry.h"
#include <deque>
#include <variant>

namespace havok::serialize::dictionary
{
struct Class;
struct Object;
struct Array;
struct Member
{
    std::string name;
    unsigned type = 0;
    unsigned tuple = 0;
    std::string className;
};
struct Class
{
    std::string name;
    int version = 0;
    const Class* parent = nullptr;
    std::vector<Member> members;
    std::vector<const Member*> Members() const;
};
struct Value
{
    // Object/array identities are world indices, not owning graph edges.
    struct ObjectId { std::size_t value; };
    struct ArrayId { std::size_t value; };
    using Data = std::variant<std::monostate, std::int64_t, float, std::string, ObjectId, ArrayId>;
    Data data;
};
struct Object { const Class* type = nullptr; std::vector<Value> members; };
struct Array { Member element; std::vector<Value> values; };
class World final
{
public:
    const Class& AddClass(std::string, int, const Class*, std::vector<Member>);
    Value::ObjectId AddObject(const Class&);
    Value::ArrayId AddArray(Member, std::size_t);
    Object& Get(Value::ObjectId);
    const Object& Get(Value::ObjectId) const;
    Array& Get(Value::ArrayId);
    const Array& Get(Value::ArrayId) const;
    const Class* FindClass(const std::string&) const noexcept;
    std::size_t ObjectCount() const noexcept { return objects.size(); }
private:
    std::deque<Class> classes;
    std::deque<Object> objects;
    std::deque<Array> arrays;
};
struct RefObj
{
    std::shared_ptr<const World> world;
    Value::ObjectId object{0};
    explicit operator bool() const noexcept { return bool(world); }
};
// Port of the source binary-tagfile version0 reader, with bounded ownership.
// The returned dictionary is independent of the input/string-table lifetime.
RefObj Read(LoadStream&);
std::shared_ptr<Resource> Convert(const RefObj&, const ClassNameRegistry&, const TypeRegistry&,
    std::shared_ptr<native_memory::Allocator>);
// Genuine native reflection family contracts: actual sizeof/alignof/offsetof,
// constructors and destruction of the source hkClass/Member/Enum/EnumItem.
std::shared_ptr<const void> RegisterReflectionTypes(ClassNameRegistry&, TypeRegistry&);
}
