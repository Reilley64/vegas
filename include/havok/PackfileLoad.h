#pragma once

#include "havok/PackfileResource.h"
#include <array>
#include <span>
#include <string>
#include <string_view>

namespace havok::serialize
{
class LoadStream
{
  public:
    virtual ~LoadStream() = default;
    virtual std::size_t Read(std::span<std::byte>) = 0;
    virtual bool CanSeek() const noexcept = 0;
    virtual void Seek(bool end) = 0;
    virtual std::size_t Tell() const noexcept = 0;
};
// A real production byte-stream implementation, not a test-inherited reader.
class MemoryLoadStream final : public LoadStream
{
  public:
    explicit MemoryLoadStream(std::span<const std::byte> bytes) noexcept : bytes(bytes) {}
    std::size_t Read(std::span<std::byte>) override;
    bool CanSeek() const noexcept override { return true; }
    void Seek(bool end) override { position = end ? bytes.size() : 0; }
    std::size_t Tell() const noexcept override { return position; }
  private:
    std::span<const std::byte> bytes;
    std::size_t position = 0;
};
// A production prefix-replay owner for format detection on sequential streams.
// It borrows its source only for the synchronous read; published resources never
// retain this adapter or the input. No seek or numerical dispatch is emulated.
class ReplayLoadStream final : public LoadStream
{
public:
    ReplayLoadStream(std::span<const std::byte> prefix, LoadStream& source) noexcept : prefix(prefix), source(source) {}
    std::size_t Read(std::span<std::byte>) override;
    bool CanSeek() const noexcept override { return false; }
    void Seek(bool) override;
    std::size_t Tell() const noexcept override { return position; }
private:
    std::span<const std::byte> prefix;
    LoadStream& source;
    std::size_t position = 0;
};
struct LoadFormat
{
    int type = 2;
    std::string_view version;
    std::array<std::byte, 4> layout{};
};
struct LoadError
{
    int status = 0;
    std::string message;
    void set(int code, const char* text) { status = code; message = text; }
};
using Resource = fnv_00dc0f20::FUN_00dc0f20_cls;
// Expected version/layout and deprecated loading remain capabilities supplied
// by the existing owner. No copied executable payload or alternate provider.
struct LoadPolicy
{
    std::string_view version;
    std::array<std::byte, 4> layout{};
    Resource* (*deprecated)(LoadStream&, const LoadFormat&, LoadError*) = nullptr;
};
void FUN_00d48680(LoadStream&, std::vector<std::byte>&);
Resource* FUN_00d48760(LoadStream&, const LoadFormat&, LoadError*, const TypeRegistry&, const LoadPolicy&) noexcept;
}
