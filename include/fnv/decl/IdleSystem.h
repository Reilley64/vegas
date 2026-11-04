#pragma once

class IdleSystem {
public:
    // 0x00af22d0
    static ::IdleSystem &GetRandomGenerator();
    // 0x00af2360
    static void Startup();
    // 0x00af2370
    static void Shutdown();
    // 0x00af2d20
    static bool Initialize();
};
