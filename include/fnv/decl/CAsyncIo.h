#pragma once

class CAsyncIo {
public:
    // 0x009fe570
    long WaitForCompletion(unsigned long, void **, unsigned long *, long *);
};
