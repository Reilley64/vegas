#pragma once

class Tile;

class HotkeyWheelDisplay {
public:
    // 0x00701610
    void Initialize(::Tile *);
    // 0x00701740
    bool GetVisible();
    // 0x00701760
    void SetVisible(bool);
    // 0x00a24660
    int SetHotkeyItem(int, int);
};
