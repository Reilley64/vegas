#pragma once
#include "havok/PackfileLoad.h"
#include <limits>
#include <string_view>

// The retained "archive" is a statistics collector, not a packfile writer.
// Emission returns void; a native sink failure propagates as an exception.
struct FUN_00e05250_Archive
{
    explicit FUN_00e05250_Archive(bool borrowed = false) noexcept : includeBorrowed(borrowed) {}
    virtual ~FUN_00e05250_Archive() = default;
    virtual void Emit(unsigned kind, std::string_view name, std::span<const std::byte> logical,
        std::size_t allocatedBytes, std::shared_ptr<const void> owner) = 0;
    const bool includeBorrowed;
};
namespace havok::serialize
{
class StatisticsSnapshot final : public FUN_00e05250_Archive
{
public:
    struct Record
    {
        unsigned kind;
        std::string name;
        std::span<const std::byte> logical;
        std::size_t allocatedBytes;
        std::shared_ptr<const void> owner;
    };
    explicit StatisticsSnapshot(std::size_t limit = std::numeric_limits<std::size_t>::max(), bool borrowed = false)
        : FUN_00e05250_Archive(borrowed), limit(limit) {}
    void Emit(unsigned, std::string_view, std::span<const std::byte>, std::size_t, std::shared_ptr<const void>) override;
    const std::vector<Record>& Records() const noexcept { return records; }
private:
    std::size_t limit;
    std::vector<Record> records;
};
}
struct FUN_00e05250_Class
{
    explicit FUN_00e05250_Class(std::shared_ptr<havok::serialize::Resource> resource) : resource(std::move(resource)) {}
    void WriteSections(FUN_00e05250_Archive*, int unused);
private:
    std::shared_ptr<havok::serialize::Resource> resource;
};
