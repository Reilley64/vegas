#pragma once

class ObstacleData;
enum OBSTACLE_TASK_TYPE;
template <class> class NiPointer;

class ObstacleTaskData {
public:
    // 0x006c7a30
    bool AddOperation(const ::NiPointer< ::ObstacleData> &, ::OBSTACLE_TASK_TYPE);
};
