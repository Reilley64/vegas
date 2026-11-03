#pragma once

class BGSRadiationStage {
public:
    // 0x00591c80
    void ClearData();
    // 0x00592220
    static ::BGSRadiationStage *GetStageForLevel(float);
};
