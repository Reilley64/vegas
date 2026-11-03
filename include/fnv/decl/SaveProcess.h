#pragma once

struct ControllerSaveBuffer;

struct SaveProcess {
public:
    // 0x00928880
    void SaveControllerState(::ControllerSaveBuffer *);
};
