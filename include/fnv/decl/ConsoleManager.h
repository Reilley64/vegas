#pragma once

class ConsoleManager {
public:
    // 0x0071b160
    static ::ConsoleManager *Instance(bool);
    // 0x0071b210
    bool Idle(int);
    // 0x011d8ce8
    static ::ConsoleManager *pInstance;
};
