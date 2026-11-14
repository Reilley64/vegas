#ifndef FNV_NIANIMATIONKEYTABLES_H
#define FNV_NIANIMATIONKEYTABLES_H

// The tables each NiAnimationKey class registers its functions and key size
// in, and every key data reader indexes. They are one object: the original
// release named many addresses inside it, and docs/animation-key-tables.md
// records how its extent and element size were established.
namespace NiAnimationKeyTables
{
// A key class is one of six contents in one of six types.
inline constexpr int kNumContents = 6;
inline constexpr int kNumTypes = 6;
inline constexpr int kNumSlots = kNumContents * kNumTypes;

// The twelve function tables, each named for the recipe address it starts at.
enum Table
{
    kAt011f3780,
    kAt011f3810,
    kAt011f38a0,
    kAt011f3930,
    kAt011f39c0,
    kAt011f3a50,
    kAt011f3ae0,
    kAt011f3b70,
    kAt011f3c00,
    kAt011f3c90,
    kAt011f3d20,
    kAt011f3db0,
    kNumTables
};

// A registered function. The key classes store functions of differing
// signatures in one table, so a reader names the signature it calls.
using Function = void (*)();

extern Function g_functions[kNumTables][kNumSlots];
extern unsigned char g_keySizes[kNumSlots];

constexpr int Index(int content, int type)
{
    return content * kNumTypes + type;
}

template <class Fn, class Slot>
Fn Get(Table table, Slot slot)
{
    return reinterpret_cast<Fn>(g_functions[table][slot]);
}

template <class Slot, class Fn>
void Set(Table table, Slot slot, Fn function)
{
    g_functions[table][slot] = reinterpret_cast<Function>(function);
}
}

#endif
