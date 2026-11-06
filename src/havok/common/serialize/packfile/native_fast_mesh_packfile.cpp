#include "havok/FastMeshPackfile.h"

#include <stdexcept>

namespace havok::fast_mesh
{
FastMeshPackfileData::FastMeshPackfileData(std::shared_ptr<native_memory::Allocator> allocator)
    : supplier(std::move(allocator))
{
    if (!supplier) throw std::invalid_argument("Fast-mesh packfile needs an owning allocator");
}
FastMeshPackfileData::~FastMeshPackfileData() { Cleanup(); }
const FastMesh& FastMeshPackfileData::FinishObject(const LoadedMesh& mesh, int finishing)
{
    try
    {
        auto object = FastMesh::Finish(mesh,finishing,supplier);
        finished.push_back(std::move(object));
        return *finished.back();
    }
    catch (...)
    {
        Cleanup();
        throw;
    }
}
Handle FastMeshPackfileData::Retain(std::size_t index) const { return finished.at(index); }
void FastMeshPackfileData::Cleanup() noexcept
{
    while (!finished.empty()) finished.pop_back();
}
}
