#pragma once

class CloningProcess;
class NiAVObject;
class NiUpdateData;

class NiNode {
public:
    // 0x0043b4a0
    ::NiAVObject *GetAt(unsigned int);
    // 0x00a5dc80
    void CopyMemberData(::NiNode *, ::CloningProcess &);
    // 0x00a5dd70
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
    // 0x00a5ded0
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
    // 0x00a5e0b0
    void UpdateTransformAndBounds(::NiUpdateData &);
};
