#pragma once

struct GPContact;

struct GPShell {
public:
    // 0x009b4950
    void HandleContactHit(::GPContact *);
};
