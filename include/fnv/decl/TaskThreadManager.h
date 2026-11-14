#pragma once

class TaskThreadManager {
public:
    // 0x004ea970
    static ::TaskThreadManager *GetSingleton();
    // 0x00b6b730
    static void EndRenderingTaskThread();
    // 0x00ba3720
    void StartRenderingTaskThread();
};
