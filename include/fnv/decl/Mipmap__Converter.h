#pragma once

namespace Mipmap { struct Image; }

namespace Mipmap {
struct Converter {
public:
    // 0x00a78090
    ::Mipmap::Image *GenerateMipmaps(::Mipmap::Image *, ::Mipmap::Image *);
};
}
