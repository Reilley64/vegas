#pragma once

class TESFile;

class MapMarkerData {
public:
    // 0x00438ca0
    bool Load(::TESFile *);
    // 0x00438ed0
    bool GetVisible();
    // 0x00438ef0
    bool IsTravelLocation();
    // 0x0044de40
    void SetVisible(bool);
    // 0x0044de80
    void SetTravelLocation(bool);
};
