#pragma once

struct Registry;
struct RequestContext;

struct QueueLockView {
public:
    // 0x00d04400
    ::Registry *FUN_00d04400(::RequestContext *);
};
