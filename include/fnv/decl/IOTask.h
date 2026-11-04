#pragma once

enum IO_TASK_PRIORITY;
struct RefObj;

class IOTask {
public:
    // 0x0043db70
    void GenerateKey();
    // 0x00440540
    IOTask(::IO_TASK_PRIORITY);
    // 0x00c3c7e0
    void FUN_00c3c7e0(::RefObj *);
};
