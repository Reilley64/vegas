#pragma once

class ShapeDC9;
struct KeyDC9;
template <class> struct hkArrayDC9;

class ShapeRegistryDC9 {
public:
    // 0x00dc92d0
    void CollectShapes(::KeyDC9 *, int, int, ::hkArrayDC9< ::ShapeDC9 *> *);
};
