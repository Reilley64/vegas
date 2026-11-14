#pragma once

#include "havok/FastMesh.h"

namespace havok::fast_mesh
{
// Native fast-mesh finish/cleanup owner for decoded packfile objects. A failed
// finish releases the already-finished prefix in reverse order. Published handles
// may outlive Cleanup; their geometry and supplying allocator remain owned.
//
// This is not an in-place finish callback for the old 96-byte reflected object.
// The legacy registry and its pointer-fixup consumers must explicitly materialize
// and publish these native objects before they can use this owner.
class FastMeshPackfileData
{
  public:
    explicit FastMeshPackfileData(std::shared_ptr<native_memory::Allocator>);
    ~FastMeshPackfileData();
    FastMeshPackfileData(const FastMeshPackfileData&) = delete;
    FastMeshPackfileData& operator=(const FastMeshPackfileData&) = delete;
    const FastMesh& FinishObject(const LoadedMesh&, int finishing);
    Handle Retain(std::size_t index) const;
    std::size_t Size() const noexcept { return finished.size(); }
    void Cleanup() noexcept;
  private:
    std::shared_ptr<native_memory::Allocator> supplier;
    std::vector<Handle> finished;
};
}
