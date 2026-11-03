#pragma once

class NavMeshObstacleManager {
public:
    // 0x006c3920
    unsigned int GetProcessedTaskCount();
    // 0x006c3970
    unsigned int GetBackgroundTaskCount();
    // 0x006c49e0
    void ProcessActivatedObstacles();
};
