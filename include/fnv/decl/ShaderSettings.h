#pragma once

struct Destination;

struct ShaderSettings {
public:
    // 0x00507060
    void CopySettingsTo(::Destination *, void *);
};
