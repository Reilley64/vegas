#pragma once

struct SeqFixedString;

struct ControllerSequence {
public:
    // 0x00a32a10
    ControllerSequence(const ::SeqFixedString &, unsigned int, unsigned int);
};
