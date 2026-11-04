#pragma once

struct Model_e6da60;
struct PackingData;
struct PackingGeometry;
struct PackingPacket;

struct PackingRenderer {
public:
    // 0x00e6d780
    bool UpdatePackingPacket(::PackingPacket *, ::Model_e6da60 *, void *, ::PackingData *, ::PackingGeometry *, bool);
};
