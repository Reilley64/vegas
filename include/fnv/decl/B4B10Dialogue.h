#pragma once

class B4B10Response;
class B4B10Speaker;

class B4B10Dialogue {
public:
    // 0x00854b10
    void SetupResponse(::B4B10Speaker *, int, ::B4B10Response *);
};
