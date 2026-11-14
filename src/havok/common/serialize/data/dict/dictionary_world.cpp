#include "havok/Dictionary.h"
#include <algorithm>
#include <stdexcept>

namespace havok::serialize::dictionary
{
std::vector<const Member*> Class::Members() const
{
    std::vector<const Class*> chain;
    for (auto* type = this; type; type = type->parent)
    {
        if (chain.size() == 128 || std::find(chain.begin(), chain.end(), type) != chain.end())
            throw std::runtime_error("dictionary class inheritance limit/cycle");
        chain.push_back(type);
    }
    std::vector<const Member*> result;
    for (auto i = chain.rbegin(); i != chain.rend(); ++i)
        for (const auto& member : (*i)->members) result.push_back(&member);
    return result;
}
const Class& World::AddClass(std::string name, int version, const Class* parent, std::vector<Member> members)
{
    if (name.empty() || FindClass(name)) throw std::runtime_error("duplicate or empty dictionary class");
    if (parent && std::none_of(classes.begin(), classes.end(), [&](const Class& type) { return &type == parent; }))
        throw std::invalid_argument("dictionary parent belongs to another world");
    auto inherited = parent ? parent->Members() : std::vector<const Member*>{};
    for (std::size_t i = 0; i < members.size(); ++i)
    {
        if (members[i].name.empty()) throw std::runtime_error("empty dictionary member");
        for (std::size_t j = 0; j < i; ++j)
            if (members[i].name == members[j].name) throw std::runtime_error("duplicate dictionary member");
        for (const auto* member : inherited)
            if (members[i].name == member->name) throw std::runtime_error("shadowed dictionary member");
    }
    classes.push_back({std::move(name), version, parent, std::move(members)});
    return classes.back();
}
Value::ObjectId World::AddObject(const Class& type)
{
    if (std::none_of(classes.begin(), classes.end(), [&](const Class& owned) { return &owned == &type; }))
        throw std::invalid_argument("dictionary object class belongs to another world");
    if (objects.size() == 65536) throw std::length_error("dictionary object limit");
    const auto count = type.Members().size();
    objects.push_back({&type, std::vector<Value>(count)});
    return {objects.size() - 1};
}
Value::ArrayId World::AddArray(Member element, std::size_t count)
{
    if (arrays.size() == 65536 || count > 65536) throw std::length_error("dictionary array limit");
    arrays.push_back({std::move(element), std::vector<Value>(count)});
    return {arrays.size() - 1};
}
Object& World::Get(Value::ObjectId id) { return objects.at(id.value); }
const Object& World::Get(Value::ObjectId id) const { return objects.at(id.value); }
Array& World::Get(Value::ArrayId id) { return arrays.at(id.value); }
const Array& World::Get(Value::ArrayId id) const { return arrays.at(id.value); }
const Class* World::FindClass(const std::string& name) const noexcept
{
    for (const auto& type : classes) if (type.name == name) return &type;
    return nullptr;
}
}
