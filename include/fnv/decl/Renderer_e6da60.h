#pragma once

struct Data_e6da60;
struct GeomData_e6da60;
struct Model_e6da60;
struct Packet_e6da60;

struct Renderer_e6da60 {
public:
    // 0x00e6da60
    bool BuildPacket(::Packet_e6da60 *, ::Model_e6da60 *, ::Data_e6da60 *, ::GeomData_e6da60 *);
};
