#pragma once

struct MapPointer;
struct MapRefObject;
template <class> class NiPointer;

struct PointerMap {
public:
    // 0x00b582b0
    void InsertOrAssign(unsigned int, ::NiPointer< ::MapRefObject>);
    // 0x00b61010
    void FUN_00b61010(const char *, ::MapPointer);
};
