#pragma once

namespace SaveThumbnail { struct File; }
namespace SaveThumbnail { struct Identity; }
namespace SaveThumbnail { struct Texture; }

namespace SaveThumbnail {
struct Reader {
public:
    // 0x00860390
    ::SaveThumbnail::Texture *ReadTexture(::SaveThumbnail::File *, unsigned int, unsigned int *, char *, unsigned short *, char *, float *, ::SaveThumbnail::Identity *, unsigned int *, unsigned int *);
};
}
