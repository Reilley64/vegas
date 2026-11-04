#pragma once

class CloningProcess;
class NiCullingProcess;
class NiGeometryData;
class NiPropertyState;
class NiStream;

struct NiGeometry {
public:
    // 0x004a1ff0
    void FUN_004a1ff0();
    // 0x00a7fd90
    void OnVisible(::NiCullingProcess &);
    // 0x00a80540
    NiGeometry();
    // 0x00a80680
    void ReplaceModelData(::NiGeometryData *);
    // 0x00a80710
    void UpdateWorldBound();
    // 0x00a80820
    void UpdatePropertiesDownwardPass(::NiPropertyState *);
    // 0x00a80a10
    void ProcessClone(::CloningProcess &);
    // 0x00a80b50
    void LinkObject(::NiStream &);
    // 0x00a89ab0
    ::NiGeometry *CopyMemberData();
};
