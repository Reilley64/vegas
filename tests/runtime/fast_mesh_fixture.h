#pragma once
#include <algorithm>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>
#include <utility>

inline void Put(std::vector<std::byte>& bytes, std::size_t at, std::uint32_t value)
{
    if (bytes.size() < at + 4) bytes.resize(at + 4);
    for (unsigned i = 0; i < 4; ++i) bytes[at + i] = std::byte((value >> (i * 8)) & 255);
}
inline std::uint32_t Get(const std::vector<std::byte>& bytes, std::size_t at)
{
    std::uint32_t value = 0;
    for (unsigned i = 0; i < 4; ++i) value |= std::to_integer<std::uint32_t>(bytes.at(at + i)) << (i * 8);
    return value;
}
inline void Float(std::vector<std::byte>& bytes, std::size_t at, float f) { Put(bytes, at, std::bit_cast<std::uint32_t>(f)); }
struct Fixture
{
    std::vector<std::byte> input;
    explicit Fixture(int objects = 1, bool badThird = false)
    {
        std::vector<std::byte> data(1024), names(64);
        const char name[] = "hkpFastMeshShape";
        std::memcpy(names.data(), name, sizeof(name));
        // Geometry streams are source-owned synthetic bytes, not game data.
        for (int i = 0; i < objects; ++i)
        {
            const int o = i * 96;
            Put(data, o + 8, 123 + i); Put(data, o + 12, 91);
            data[o + 20] = std::byte{1}; data[o + 21] = std::byte{3};
            Float(data, o + 32, 2); Float(data, o + 36, 3); Float(data, o + 40, 4);
            Put(data, o + 48, 12); Put(data, o + 56, 1); Put(data, o + 60, 1);
            Put(data, o + 68, 1); Put(data, o + 72, 1); data[o + 76] = std::byte{2};
            Float(data, o + 80, 0.25f); Put(data, o + 84, 7); Put(data, o + 88, 8); Put(data, o + 92, 9);
        }
        const int part = 384, vertices = 448, indices = 512, mi = 528, mat = 544, welding = 560;
        Put(data, part + 4, 16); Put(data, part + 8, 3);
        data[part + 16] = std::byte{1}; data[part + 17] = std::byte{0};
        Put(data, part + 20, 6); Put(data, part + 28, 1);
        Put(data, part + 36, 1); Put(data, part + 44, 4); Put(data, part + 48, 1);
        Float(data, vertices + 16, 1); Float(data, vertices + 32 + 4, 1);
        data[indices + 2] = std::byte{1}; data[indices + 4] = std::byte{2};
        data[mi] = std::byte{}; data[mat] = std::byte{42};
        data[welding] = std::byte{0x34}; data[welding + 1] = std::byte{0x12};
        std::vector<std::pair<int,int>> locals;
        for (int i = 0; i < objects; ++i)
        {
            locals.push_back({i * 96 + 52, badThird && i == 2 ? 1020 : part});
            locals.push_back({i * 96 + 64, welding});
        }
        locals.insert(locals.end(), {{part, vertices}, {part + 12, indices}, {part + 32, mi}, {part + 40, mat}, {768, 0}, {772, 0}});
        // Local alias and a global alias from the other section share root identity.
        const int local = static_cast<int>(data.size());
        for (auto [field,target] : locals) { Put(data, data.size(), field); Put(data, data.size(), target); }
        const int global = static_cast<int>(data.size()), virtuals = global;
        for (int i = 0; i < objects; ++i)
        {
            Put(data, data.size(), i * 96); Put(data, data.size(), 1); Put(data, data.size(), 0);
        }
        // Duplicate virtual identity is an alias, not a second native construction.
        Put(data, data.size(), 0); Put(data, data.size(), 1); Put(data, data.size(), 0);
        const int exports = static_cast<int>(data.size());
        const int namesLocal = static_cast<int>(names.size()), namesGlobal = namesLocal;
        Put(names, names.size(), 32); Put(names, names.size(), 0); Put(names, names.size(), 0);
        const int namesVirtuals = static_cast<int>(names.size());
        input.resize(160);
        Put(input, 0, 0x57e0e057); Put(input, 4, 0x10c0c010); Put(input, 12, 7);
        input[16] = std::byte{4}; input[17] = std::byte{1};
        Put(input, 20, 2); Put(input, 24, 0); Put(input, 28, 0); Put(input, 32, 1); Put(input, 36, 0);
        auto section = [&](int at, int absolute, int l, int g, int v, int e, int end)
        {
            Put(input, at + 20, absolute); Put(input, at + 24, l); Put(input, at + 28, g);
            Put(input, at + 32, v); Put(input, at + 36, e); Put(input, at + 40, end); Put(input, at + 44, end);
        };
        section(64, 160, local, global, virtuals, exports, exports);
        section(112, 160 + static_cast<int>(data.size()), namesLocal, namesGlobal, namesVirtuals, namesVirtuals, namesVirtuals);
        input.insert(input.end(), data.begin(), data.end()); input.insert(input.end(), names.begin(), names.end());
    }
    bool SetLocalPointer(int field, int target)
    {
        const auto first = 160u + Get(input, 88), last = 160u + Get(input, 92);
        for (auto at = first; at < last; at += 8)
            if (Get(input, at) == static_cast<unsigned>(field))
            {
                if (target == -1) Put(input, at, ~0u); // Omit the pointer fixup.
                else Put(input, at + 4, target);
                return true;
            }
        return false;
    }
};
