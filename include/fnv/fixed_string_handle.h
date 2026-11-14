#pragma once

#include <cstddef>
#include <cstdint>

// Handle protocol of the one native global string table. A handle is the
// interned text pointer; the null handle is the null string and has no node.
// A node keeps its 32-bit reference count eight bytes and its 32-bit length
// four bytes before the text, so the retain and release operations here and
// the direct interlocked updates in older units act on the same count.

// 0x00a5b630: starts the table.
void FUN_00a5b630();
// 0x00a5b460: frees every node whose reference count is zero. This is the
// only place a node is retired; a release never frees.
void FUN_00a5b460();

namespace fnv::strings {

// 0x00a5b270: h * 33 + signed char over the text, modulo the 513 buckets.
unsigned int HashString(const char* text, unsigned int length) noexcept;

void RetainHandle(char* handle) noexcept;
void ReleaseHandle(char* handle) noexcept;
// 0x00a5b950 body: retains the incoming handle before releasing the old one.
void AssignHandle(char*& slot, char* incoming) noexcept;

// Stops the table once no node remains; live nodes refuse the shutdown.
bool ShutdownTable() noexcept;

// Ownership facts for bounded tests. Owns never reads through the handle.
const void* TableIdentity() noexcept;
bool Owns(const char* handle) noexcept;
std::uint32_t RefCount(const char* handle) noexcept;
std::uint32_t Length(const char* handle) noexcept;
std::size_t NodeCount() noexcept;

} // namespace fnv::strings
