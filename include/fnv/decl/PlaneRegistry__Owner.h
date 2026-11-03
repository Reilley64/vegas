#pragma once

namespace PlaneRegistry { struct Matrix; }
namespace PlaneRegistry { struct Object; }
namespace PlaneRegistry { struct Vector; }

namespace PlaneRegistry {
struct Owner {
public:
    // 0x004e4730
    bool FUN_004e4730(::PlaneRegistry::Object *, const ::PlaneRegistry::Vector *, ::PlaneRegistry::Matrix *);
};
}
