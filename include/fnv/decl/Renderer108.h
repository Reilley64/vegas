#pragma once

class NiAVObject;
struct Geo108;
struct Packet108;

struct Renderer108 {
public:
    // 0x00e71fe0
    bool PrepareGeometryPacket(::Packet108 *, ::NiAVObject *, ::Geo108 *, ::NiAVObject *, bool);
};
