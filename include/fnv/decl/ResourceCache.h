#pragma once

struct CachedResource;

struct ResourceCache {
public:
    // 0x00e8fc50
    ::CachedResource *AcquireCachedResource(unsigned int, unsigned int, unsigned int, unsigned int);
};
