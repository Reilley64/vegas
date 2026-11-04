#pragma once

class hkObjectE02;
class hkTrackerE02;

class hkLoaderE02 {
public:
    // 0x00e02cb0
    ::hkObjectE02 *GetOrCreateObject(const char *, ::hkTrackerE02 *);
};
