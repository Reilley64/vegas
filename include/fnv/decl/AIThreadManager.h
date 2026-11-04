#pragma once

class AIThreadManager {
public:
    // 0x008c7290
    void StartRenderingTaskThread();
    // 0x008c80e0
    static void SetThreadingEnabled(bool);
};
