#pragma once

struct LockActor;

struct LockAccess {
public:
    // 0x00501fd0
    bool CanAccessLock(::LockActor *, int, bool);
};
