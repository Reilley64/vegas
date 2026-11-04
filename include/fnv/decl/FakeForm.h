#pragma once

struct BGSSaveFormBuffer;

struct FakeForm {
public:
    // 0x00484d60
    void SaveIfChanged(::BGSSaveFormBuffer *);
};
