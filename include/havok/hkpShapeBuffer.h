// Scoped native triangle storage. A returned child is borrowed until the next
// retrieval into this buffer, or buffer destruction. No original buffer ABI.
#ifndef FNV_HAVOK_HKPSHAPEBUFFER_H
#define FNV_HAVOK_HKPSHAPEBUFFER_H
#include "hkpTriangleShape.h"
#include <optional>

class hkpShapeBuffer
{
  public:
    hkpShapeBuffer() = default;
    hkpShapeBuffer(const hkpShapeBuffer&) = delete;
    hkpShapeBuffer& operator=(const hkpShapeBuffer&) = delete;

  private:
    friend class hkpMeshShape;
    std::optional<hkpTriangleShape> triangle;
};
#endif
