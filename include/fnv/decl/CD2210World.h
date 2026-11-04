#pragma once

struct CD2210Listener;

struct CD2210World {
public:
    // 0x00cd2210
    void RemoveListener(::CD2210Listener *);
};
