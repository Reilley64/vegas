#pragma once

struct E25FB0Edge;
struct E25FB0Item;

struct E25FB0Mesh {
public:
    // 0x00e25fb0
    void ProcessItems(::E25FB0Edge, const ::E25FB0Item *);
};
