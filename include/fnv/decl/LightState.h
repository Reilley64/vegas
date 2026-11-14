#pragma once

struct LightSource;

struct LightState {
public:
    // 0x00e8b250
    bool UpdateFromSource(::LightSource *);
};
