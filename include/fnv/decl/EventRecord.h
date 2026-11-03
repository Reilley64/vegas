#pragma once

struct EventSource;

struct EventRecord {
public:
    // 0x00985410
    ::EventRecord *Init(::EventSource *, unsigned short);
};
