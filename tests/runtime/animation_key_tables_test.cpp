#include "NiAnimationKeyTables.h"

#include <cstdio>

namespace
{
namespace Tables = NiAnimationKeyTables;

int failures;

void Check(bool condition, const char* name)
{
    if (!condition)
    {
        std::fprintf(stderr, "animation key tables: %s\n", name);
        ++failures;
    }
}

// Two signatures the key classes register in one table.
float Interpolate(float time, const void*, const void*)
{
    return time;
}

bool Equal(const void* first, const void* second)
{
    return first == second;
}

using InterpolateFunction = float (*)(float, const void*, const void*);
using EqualFunction = bool (*)(const void*, const void*);

static_assert(Tables::kNumTables == 12);
static_assert(Tables::kNumSlots == 36);
static_assert(sizeof(Tables::g_functions) == 12 * 36 * sizeof(Tables::Function));
static_assert(sizeof(Tables::g_keySizes) == 36);
static_assert(Tables::Index(0, 0) == 0);
static_assert(Tables::Index(1, 0) == 6);
static_assert(Tables::Index(5, 5) == Tables::kNumSlots - 1);

bool AllEmptyExcept(int usedTable, int usedSlot)
{
    for (int table = 0; table < Tables::kNumTables; ++table)
    {
        for (int slot = 0; slot < Tables::kNumSlots; ++slot)
        {
            const bool used = table == usedTable && slot == usedSlot;
            if ((Tables::g_functions[table][slot] != nullptr) != used)
            {
                return false;
            }
        }
    }
    return true;
}

void StartsEmpty()
{
    Check(AllEmptyExcept(-1, -1), "every function slot starts null");
    for (int slot = 0; slot < Tables::kNumSlots; ++slot)
    {
        Check(Tables::g_keySizes[slot] == 0, "every key size starts zero");
    }
}

// A key class registers at Index(content, type). A reader holds the content
// of its key data and adds the type to that content's first slot.
void RegisteredFunctionIsFound()
{
    for (int table = 0; table < Tables::kNumTables; ++table)
    {
        for (int content = 0; content < Tables::kNumContents; ++content)
        {
            for (int type = 0; type < Tables::kNumTypes; ++type)
            {
                const auto which = static_cast<Tables::Table>(table);
                Tables::Set(which, Tables::Index(content, type), &Interpolate);
                Check(Tables::Get<InterpolateFunction>(which, Tables::Index(content, 0) + type) == &Interpolate,
                      "a reader finds the registered function");
                Check(Tables::Get<InterpolateFunction>(which, content * 6 + type)(0.25f, nullptr, nullptr) == 0.25f,
                      "the found function is callable with its own signature");
                Check(AllEmptyExcept(table, Tables::Index(content, type)), "one registration fills one slot");
                Tables::g_functions[table][Tables::Index(content, type)] = nullptr;
            }
        }
    }
    Check(AllEmptyExcept(-1, -1), "cleared slots are null again");
}

void NeighbouringSlotsKeepWholePointers()
{
    const Tables::Table table = Tables::kAt011f3ae0;
    Tables::Set(table, Tables::Index(2, 3), &Equal);
    Tables::Set(table, Tables::Index(2, 4), &Interpolate);
    Tables::Set(table, Tables::Index(2, 2), &Interpolate);
    Check(Tables::Get<EqualFunction>(table, Tables::Index(2, 0) + 3) == &Equal,
          "writing both neighbours leaves a slot whole");
    Check(Tables::Get<EqualFunction>(table, Tables::Index(2, 3))(&failures, &failures),
          "a second signature is called through the same table");
    Tables::Set(Tables::kAt011f3db0, Tables::Index(0, 0), &Equal);
    Check(Tables::Get<InterpolateFunction>(Tables::kAt011f3d20, Tables::Index(5, 5)) == nullptr,
          "the first slot of a table is not the last slot of the table before it");
    Tables::g_functions[table][Tables::Index(2, 2)] = nullptr;
    Tables::g_functions[table][Tables::Index(2, 3)] = nullptr;
    Tables::g_functions[table][Tables::Index(2, 4)] = nullptr;
    Tables::g_functions[Tables::kAt011f3db0][Tables::Index(0, 0)] = nullptr;
}

void RegisteredKeySizeIsFound()
{
    for (int content = 0; content < Tables::kNumContents; ++content)
    {
        for (int type = 0; type < Tables::kNumTypes; ++type)
        {
            Tables::g_keySizes[Tables::Index(content, type)] = static_cast<unsigned char>(1 + content * 6 + type);
        }
    }
    for (int content = 0; content < Tables::kNumContents; ++content)
    {
        for (int type = 0; type < Tables::kNumTypes; ++type)
        {
            Check(Tables::g_keySizes[Tables::Index(content, 0) + type] == 1 + content * 6 + type,
                  "a reader finds the registered key size");
        }
    }
    Check(AllEmptyExcept(-1, -1), "key sizes are not function slots");
}
}

int main()
{
    StartsEmpty();
    RegisteredFunctionIsFound();
    NeighbouringSlotsKeepWholePointers();
    RegisteredKeySizeIsFound();
    return failures == 0 ? 0 : 1;
}
