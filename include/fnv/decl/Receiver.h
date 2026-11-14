#pragma once

struct EventSource;
struct Input;

struct Receiver {
public:
    // 0x0087b300
    void SendEvent(::EventSource *, unsigned char, unsigned char, unsigned char);
    // 0x00a63d10
    void FUN_00a63d10();
    // 0x00c9f890
    void FUN_00c9f890(::Input *);
    // 0x00cecc90
    void FUN_00cecc90(float);
};
