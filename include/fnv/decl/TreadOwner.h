#pragma once

struct NiObjectNET;
class NiQuatTransform;

class TreadOwner {
public:
    // 0x00a43040
    bool UpdateTreadTransform(float, ::NiObjectNET *, ::NiQuatTransform &);
};
