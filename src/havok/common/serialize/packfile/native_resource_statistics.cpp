#include "havok/ResourceStatistics.h"
#include "havok/NativeWorld.h"
#include "havok/hkMemorySystem.h"
#include <array>
#include <cstring>
#include <stdexcept>

void havok::serialize::StatisticsSnapshot::Emit(unsigned kind, std::string_view name, std::span<const std::byte> logical,
    std::size_t allocatedBytes, std::shared_ptr<const void> owner)
{
    if (records.size() == limit) throw std::length_error("statistics sink record limit reached");
    if (!logical.empty() && !owner) throw std::invalid_argument("statistics sink requires storage ownership");
    records.push_back({kind, std::string(name), logical, allocatedBytes, std::move(owner)});
}
namespace
{
using namespace havok::serialize;
struct Sections
{
    struct Array
    {
        void* data = nullptr;
        int logicalBytes = 0, capacityBytes = 0;
        bool owned = false;
    };
    // The original Chunk has an unidentified third integer. No conversion
    // producer claims that contract; chunks remain empty rather than inventing
    // flags or borrowing another allocation's fields.
    struct Export { const char* name; const void* object; };
    struct Import { const char* name; Location location; };
    explicit Sections(std::shared_ptr<Resource> resource) : resource(std::move(resource)),
        supplier(this->resource->SupplierLease()), heap(*supplier)
    {
        try
        {
            const auto memory = this->resource->AllocationPointers();
            Set(0, std::as_bytes(std::span(memory)));
            exported = this->resource->NativeSymbols(false);
            imported = this->resource->NativeSymbols(true);
            std::vector<Export> exports;
            std::vector<Import> imports;
            for (const auto& symbol : exported)
                exports.push_back({symbol.name.c_str(), this->resource->NativeObject(symbol.location).NativeAddress()});
            for (const auto& symbol : imported) imports.push_back({symbol.name.c_str(), symbol.location});
            Set(2, std::as_bytes(std::span(exports))); Set(3, std::as_bytes(std::span(imports)));
        }
        catch (...) { Release(); throw; }
    }
    ~Sections() { Release(); }
    void Release() noexcept
    {
        for (auto i = arrays.rbegin(); i != arrays.rend(); ++i) if (i->owned)
        {
            heap.blockFree(i->data, i->capacityBytes); *i = {};
        }
    }
    void Set(unsigned index, std::span<const std::byte> bytes)
    {
        if (bytes.size() > std::size_t(std::numeric_limits<int>::max())) throw std::length_error("statistics section exceeds allocator extent");
        auto& array = arrays[index];
        if (bytes.empty()) return;
        int capacity = int(bytes.size());
        void* data = heap.bufAlloc(capacity);
        if (!data) throw std::bad_alloc();
        array = {data, int(bytes.size()), capacity, true};
        std::memcpy(data, bytes.data(), bytes.size());
    }
    std::shared_ptr<Resource> resource;
    std::shared_ptr<havok::native_memory::Allocator> supplier;
    hkSystemMemoryAllocator heap;
    std::array<Array, 4> arrays;
    std::vector<SymbolLocation> exported, imported;
};
}
// The source operation returns void and emits owned arrays (or borrowed arrays
// on request), in this exact order. The last value is allocated size from the
// real supplying heap, NOT a digest and NOT an invented universal wire header.
// @fnv 0x00e05250
void FUN_00e05250_Class::WriteSections(FUN_00e05250_Archive* archive, int)
{
    if (!archive || !resource) throw std::invalid_argument("statistics requires collector and resource");
    auto sections = std::make_shared<Sections>(resource);
    static constexpr std::array<std::string_view, 4> names{"memory", "chunks", "exports", "imports"};
    for (unsigned i = 0; i < names.size(); ++i)
    {
        const auto& array = sections->arrays[i];
        if (array.owned || archive->includeBorrowed)
            archive->Emit(3, names[i], {static_cast<const std::byte*>(array.data), std::size_t(array.logicalBytes)},
                std::size_t(sections->heap.getAllocatedSize(array.data, array.capacityBytes)), sections);
    }
}
void hkPackfileDataE055::WriteSections(FUN_00e05250_Archive* archive, int unused)
{
    FUN_00e05250_Class(resource).WriteSections(archive, unused);
}
