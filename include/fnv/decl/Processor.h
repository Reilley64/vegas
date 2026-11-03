#pragma once

struct Group;
struct OutputArray;
struct Shape;
struct TaskInput;
struct Transform;
struct hkBoolX;

struct Processor {
public:
    // 0x00623640
    void ProcessRequests();
    // 0x00d02930
    void ProcessGroups(int **, int, ::Group *, int, ::TaskInput *, ::hkBoolX);
    // 0x00de3520
    void FUN_00de3520(::Shape *, const struct ::Transform *, ::OutputArray *);
};
