#pragma once

struct InputProvider;

struct MessageProcessor {
public:
    // 0x00dd9600
    void ProcessInputData(::InputProvider *);
};
