#include "fnv/d3d_texture_stage.h"
// Keep runtime checks active in Release test builds.
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>
#include <cstdint>
#include "fnv/decl/NiGlobalStringTable.h"
#include "NiFixedString.h"
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <new>
#include <exception>
#include <limits>

namespace
{
struct Allocation { std::size_t bytes; int domain; };
std::map<void*, Allocation> live;
std::vector<int> events;
int failAllocation = -1;
void* Allocate(std::size_t bytes, int domain)
{
    if (failAllocation == 0) return nullptr;
    if (failAllocation > 0) --failAllocation;
    void* raw = std::malloc(bytes);
    assert(raw);
    assert(live.emplace(raw, Allocation{bytes, domain}).second);
    events.push_back(domain);
    return raw;
}
void Free(void* raw, int domain)
{
    if (!raw) return;
    auto it = live.find(raw);
    assert(it != live.end() && it->second.domain == domain);
    live.erase(it);
    events.push_back(-domain);
    std::free(raw);
}
struct Interned { std::int32_t refs = 0; unsigned int length = 9; char name[16] = "transform"; };
Interned interned;
unsigned int constants = 0;
unsigned int removes = 0;
bool failString = false;
bool failConstant = false;
}
char* DAT_0109b220 = nullptr;
char* NiGlobalStringTable::AddString(const char* name)
{
    if (failString) return nullptr;
    assert(std::strcmp(name, interned.name) == 0);
    ++interned.refs;
    return interned.name;
}
bool AcquireGlobalConstantEntry(const NiFixedString* key, unsigned int, unsigned int, std::uintptr_t)
{
    assert(key->m_kHandle == interned.name && interned.refs > 0);
    if (failConstant) return false;
    ++constants;
    return true;
}
bool RemoveGlobalConstant(const NiFixedString* key)
{
    assert(key->m_kHandle == interned.name && interned.refs >= 2);
    assert(constants);
    --constants;
    ++removes;
    return true;
}
void* FUN_00401000(unsigned int n) { return Allocate(n, 1); }
void FUN_00401030(void* p) { Free(p, 1); }
void* FUN_00aa1420(std::size_t n) { return Allocate(n, 2); }
void FUN_00aa1490(void* p, unsigned int extent) { assert(extent == sizeof(BeamStage)); Free(p, 2); }
void* FUN_00aa13e0(std::size_t n) { return Allocate(n, 3); }
void FUN_00aa1460(void* p, unsigned int extent) { assert(extent == sizeof(BeamStage)); Free(p, 3); }
void* FUN_00aa1070(unsigned int n) { return Allocate(n, 4); }
void FUN_00aa10f0(void* p) { Free(p, 4); }

int main(int argc, char** argv)
{
    if (argc > 1 && std::strcmp(argv[1], "--outstanding-owner-termination") == 0)
    {
        std::set_terminate([] { std::_Exit(live.size() == 3 ? 0 : 3); });
        D3DTextureStagePool pool;
        (void)pool.Acquire();
        return 4;
    }
    {
        D3DTextureStagePool pool;
        BeamStage* stage = pool.Acquire();
        assert(stage->GetStageIndex() == 0);
        assert(stage->GetTexture() == nullptr);
        assert(pool.Available() == 7);
        stage->SetStageIndex(3);
        stage->DecRefCount();
        assert(pool.Available() == 8);
        assert(pool.Shutdown());
    }
    assert(live.empty());
    {
        auto* stage = new BeamStage;
        stage->IncRefCount();
        stage->IncRefCount();
        assert(stage->textureTransform.Acquire("transform", 1, 64, nullptr));
        assert(constants == 1 && interned.refs == 1);
        stage->DecRefCount();
        assert(!live.empty() && constants == 1);
        stage->DecRefCount();
        assert(live.empty() && constants == 0 && interned.refs == 0 && removes == 1);
    }
    for (unsigned int count : {0u, 1u, 3u})
    {
        events.clear();
        BeamStage* stages = CreateD3DTextureStages(count);
        assert(stages);
        assert(reinterpret_cast<std::uintptr_t>(stages) % alignof(BeamStage) == 0);
        assert(events.size() == 1 && events[0] == (count ? 2 : 1));
        for (unsigned int i = 0; i < count; ++i)
        {
            assert(stages[i].GetTexture() == nullptr);
            assert(stages[i].GetStageIndex() == 0);
            if (i) assert(reinterpret_cast<char*>(&stages[i]) - reinterpret_cast<char*>(&stages[i-1]) == sizeof(BeamStage));
        }
        delete[] stages;
        assert(live.empty() && events.back() == (count ? -2 : -1));
        D3DTextureStageBlock block(count);
        assert(block.GetAt(count) == nullptr);
        for (unsigned int i = 0; i < count; ++i)
            assert(block.GetAt(i) == block.items + i);
    }
    assert(live.empty());
    {
        D3DTextureStagePool pool;
        std::vector<BeamStage*> owners;
        for (unsigned int i = 0; i < 8; ++i) owners.push_back(pool.Acquire());
        auto* stage = owners.back();
        unsigned char borrowedTexture;
        auto* texture = reinterpret_cast<NiTexture*>(&borrowedTexture);
        stage->SetTexture(texture);
        stage->SetStageIndex(7);
        stage->clampMode = 6;
        stage->mode = 3;
        stage->textureTransformFlags = 0x10000000;
        stage->transformFlags = 7;
        stage->transformEnabled = true;
        stage->transform[15] = 17.0f;
        using Group = D3DTextureStageState::Group;
        for (unsigned int i = 0; i < 8; ++i)
            assert(stage->state.SetStageValue(i, i + 11, i % 2 ? Group::first : Group::second));
        for (unsigned int i = 0; i < 5; ++i)
            assert(stage->state.SetSamplerValue(i, i + 21, i % 2 ? Group::first : Group::second, true));
        assert(stage->textureTransform.Acquire("transform", 1, 64, nullptr));
        const auto count = live.size();
        failAllocation = 0;
        stage->DecRefCount();
        assert(pool.Available() == 1 && live.size() == count);
        auto* reused = pool.Acquire();
        assert(reused == stage && reused->GetTexture() == nullptr && reused->GetStageIndex() == 0);
        assert(reused->clampMode == 0 && reused->mode == 0 && reused->textureTransformFlags == 0);
        assert(!reused->transformFlags && !reused->transformEnabled && reused->transform[15] == 17.0f);
        assert(!reused->textureTransform.GetName() && constants == 0 && interned.refs == 0);
        assert(reused->state.StageCount(Group::first) == 0 && reused->state.StageCount(Group::second) == 0);
        assert(reused->state.SamplerCount(Group::first) == 0 && reused->state.SamplerCount(Group::second) == 0);
        assert(reused->state.FlaggedSamplerCount() == 0);
        for (unsigned int i = 0; i < 8; ++i)
        {
            std::uintptr_t value; Group group;
            assert(!reused->state.GetStageValue(i, value, group));
        }
        for (unsigned int i = 0; i < 5; ++i)
        {
            unsigned int value; Group group; bool flagged;
            assert(!reused->state.GetSamplerValue(i, value, group, flagged));
        }
        failAllocation = -1;
        for (int failure : {0, 1, 2})
        {
            failAllocation = failure;
            try { (void)pool.Acquire(); assert(false); } catch (const std::bad_alloc&) {}
            assert(pool.Total() == 8 && pool.Available() == 0 && live.size() == count);
        }
        failAllocation = -1;
        auto* ninth = pool.Acquire();
        for (auto* previous : owners) assert(ninth != previous);
        assert(pool.Total() == 24 && pool.Available() == 15);
        assert(!pool.Shutdown() && pool.Total() == 24 && pool.Available() == 15);
        ninth->DecRefCount();
        for (auto* owner : owners) owner->DecRefCount();
        assert(pool.Shutdown() && pool.Total() == 0 && live.empty());
        auto* restarted = pool.Acquire();
        assert(pool.Total() == 8);
        restarted->DecRefCount();
    }
    assert(live.empty());
    for (int failure : {0, 1, 2})
    {
        D3DTextureStagePool pool;
        failAllocation = failure;
        try { (void)pool.Acquire(); assert(false); } catch (const std::bad_alloc&) {}
        assert(pool.Total() == 0 && pool.Available() == 0 && live.empty());
        failAllocation = -1;
        auto* stage = pool.Acquire();
        stage->DecRefCount();
    }
    assert(live.empty());
    for (unsigned int count : {0u, 1u, 3u})
    {
        failAllocation = 0;
        try { (void)CreateD3DTextureStages(count); assert(false); } catch (const std::bad_alloc&) {}
        assert(live.empty());
    }
    failAllocation = -1;
    events.clear();
    try { (void)CreateD3DTextureStages((std::numeric_limits<unsigned int>::max)()); assert(false); }
    catch (const std::bad_alloc&) {}
    assert(events.empty());
    {
        D3DStageTransformConstant constant;
        assert(!constant.Acquire(nullptr, 1, 64, nullptr));
        failString = true;
        assert(!constant.Acquire("transform", 1, 64, nullptr));
        failString = false;
        assert(constant.Acquire("transform", 1, 64, nullptr));
        auto* name = constant.GetName();
        failConstant = true;
        assert(!constant.Acquire("transform", 1, 64, nullptr));
        assert(constant.GetName() == name && constants == 1 && interned.refs == 1);
        failConstant = false;
        assert(constant.Acquire("transform", 1, 64, nullptr));
        assert(constants == 1 && interned.refs == 1);
        constant.Reset(); constant.Reset();
        assert(constants == 0 && interned.refs == 0);
    }
    {
        auto* pool = new D3DTextureStagePool;
        auto* stage = pool->Acquire();
        stage->DecRefCount();
        delete pool;
    }
    assert(live.empty());
}
