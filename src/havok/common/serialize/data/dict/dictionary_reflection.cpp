#include "havok/Dictionary.h"
#include "havok/hkClassMember.h"
#include "havok/hkClassEnum.h"
#include "havok/hkClassEnumItem.h"
#include <array>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <type_traits>

namespace havok::serialize::dictionary
{
namespace
{
char* Name(const char* name) { return const_cast<char*>(name); }
struct Contracts
{
    hkClass klass{}, member{}, enumeration{}, item{};
    std::array<hkClassMember, 10> classMembers{};
    std::array<hkClassMember, 9> memberMembers{};
    std::array<hkClassMember, 4> enumMembers{};
    std::array<hkClassMember, 2> itemMembers{};
    static hkClassMember Field(const char* name, unsigned type, std::size_t offset, hkClass* klass = nullptr, unsigned sub = 0)
    {
        if (offset > std::numeric_limits<hkUint16>::max()) throw std::runtime_error("native member offset exceeds reflection representation");
        return {Name(name), klass, nullptr, static_cast<hkUint8>(type), static_cast<hkUint8>(sub), 0, 0, static_cast<hkUint16>(offset), nullptr};
    }
    Contracts()
    {
        using M = hkClassMember;
        static_assert(std::is_standard_layout_v<hkClass> && std::is_standard_layout_v<hkClassMember> &&
            std::is_standard_layout_v<hkClassEnum> && std::is_standard_layout_v<hkClassEnumItem>);
        classMembers = {{
            Field("name", M::TYPE_CSTRING, offsetof(hkClass, m_name)),
            Field("parent", M::TYPE_POINTER, offsetof(hkClass, m_parent), &klass),
            Field("objectSize", M::TYPE_INT32, offsetof(hkClass, m_iObjectSize)),
            Field("numImplementedInterfaces", M::TYPE_INT32, offsetof(hkClass, m_iNumImplementedInterfaces)),
            Field("declaredEnums", M::TYPE_SIMPLEARRAY, offsetof(hkClass, m_kDeclaredEnums), &enumeration, M::TYPE_STRUCT),
            Field("declaredMembers", M::TYPE_SIMPLEARRAY, offsetof(hkClass, m_kDeclaredMembers), &member, M::TYPE_STRUCT),
            Field("defaults", M::TYPE_POINTER, offsetof(hkClass, m_pDefaultObject)),
            Field("attributes", M::TYPE_POINTER, offsetof(hkClass, m_pCustomAttributes)),
            Field("flags", M::TYPE_UINT32, offsetof(hkClass, m_flags)),
            Field("describedVersion", M::TYPE_INT32, offsetof(hkClass, m_iDescribedVersion))
        }};
        memberMembers = {{
            Field("name", M::TYPE_CSTRING, offsetof(hkClassMember, m_name)),
            Field("class", M::TYPE_POINTER, offsetof(hkClassMember, m_class), &klass),
            Field("enum", M::TYPE_POINTER, offsetof(hkClassMember, m_pClassEnum), &enumeration),
            Field("type", M::TYPE_UINT8, offsetof(hkClassMember, m_type)),
            Field("subtype", M::TYPE_UINT8, offsetof(hkClassMember, m_eSubtype)),
            Field("cArraySize", M::TYPE_INT16, offsetof(hkClassMember, m_iArraySize)),
            Field("flags", M::TYPE_UINT16, offsetof(hkClassMember, m_flags)),
            Field("offset", M::TYPE_UINT16, offsetof(hkClassMember, m_offset)),
            Field("attributes", M::TYPE_POINTER, offsetof(hkClassMember, m_pCustomAttributes))
        }};
        enumMembers = {{
            Field("name", M::TYPE_CSTRING, offsetof(hkClassEnum, m_name)),
            Field("items", M::TYPE_SIMPLEARRAY, offsetof(hkClassEnum, m_items), &item, M::TYPE_STRUCT),
            Field("attributes", M::TYPE_POINTER, offsetof(hkClassEnum, m_pCustomAttributes)),
            Field("flags", M::TYPE_UINT32, offsetof(hkClassEnum, m_flags))
        }};
        itemMembers = {{Field("value", M::TYPE_INT32, offsetof(hkClassEnumItem, m_uiFilterValue)),
            Field("name", M::TYPE_CSTRING, offsetof(hkClassEnumItem, m_name))}};
        klass = {Name("hkClass"), nullptr, sizeof(hkClass), 0, {}, {classMembers.data(), int(classMembers.size())}, nullptr, nullptr, 0, 0};
        member = {Name("hkClassMember"), nullptr, sizeof(hkClassMember), 0, {}, {memberMembers.data(), int(memberMembers.size())}, nullptr, nullptr, 0, 0};
        enumeration = {Name("hkClassEnum"), nullptr, sizeof(hkClassEnum), 0, {}, {enumMembers.data(), int(enumMembers.size())}, nullptr, nullptr, 0, 0};
        item = {Name("hkClassEnumItem"), nullptr, sizeof(hkClassEnumItem), 0, {}, {itemMembers.data(), int(itemMembers.size())}, nullptr, nullptr, 0, 0};
    }
};
struct Registration
{
    std::shared_ptr<Contracts> contracts = std::make_shared<Contracts>();
    std::array<hkEntryD479, 4> entries;
    template<class T> void Set(unsigned index, const hkClass& klass)
    {
        auto& entry = entries[index];
        entry.name = klass.m_name;
        entry.size = sizeof(T);
        entry.SetNativeLayout<T>();
        entry.nativeClass = &klass;
        entry.nativeClassStorage = contracts;
        entry.m_func = [](void* pointer, int) { std::construct_at(static_cast<T*>(pointer)); };
        entry.cleanup = [](void* pointer) { std::destroy_at(static_cast<T*>(pointer)); };
    }
    Registration()
    {
        Set<hkClass>(0, contracts->klass); Set<hkClassMember>(1, contracts->member);
        Set<hkClassEnum>(2, contracts->enumeration); Set<hkClassEnumItem>(3, contracts->item);
    }
};
}
std::shared_ptr<const void> RegisterReflectionTypes(ClassNameRegistry& classes, TypeRegistry& types)
{
    auto registration = std::make_shared<Registration>();
    // Stage every allocation before either borrowing registry can observe the
    // new producer. Unwind must never leave pointers to destroyed entries.
    auto nextClasses = classes;
    auto nextTypes = types;
    for (auto& entry : registration->entries)
    {
        nextClasses.RegisterClass(entry.nativeClass, entry.nativeClassStorage);
        nextTypes.Register(&entry);
    }
    classes.SwapContents(nextClasses);
    types.types.entries.swap(nextTypes.types.entries);
    // The caller retains this producer until registry retirement. Published
    // resources copy callbacks/contracts and do not borrow the registration.
    return registration;
}
}
