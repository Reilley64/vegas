#pragma once

struct WorkerTarget;

struct WorkerSource {
public:
    // 0x00bb0040
    void UpdateWorkerObject(::WorkerTarget *);
};
