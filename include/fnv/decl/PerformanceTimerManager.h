#pragma once

class PerformanceMeasurement;

class PerformanceTimerManager {
public:
    // 0x0045d260
    ::PerformanceMeasurement *Register(char *, char *, bool, bool);
    // 0x007005d0
    ::PerformanceTimerManager *BeginFrame();
};
