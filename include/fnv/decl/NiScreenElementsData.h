#pragma once

class NiScreenElementsData {
public:
    // 0x00a88020
    bool SetRectangle(int, float, float, float, float);
    // 0x00a88130
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
};
