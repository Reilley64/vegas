#pragma once

class NavMeshVertexEdgeData;
class TwoIntRecord;

struct VertMap {
public:
    // 0x0069b560
    void GetNextEntry(void *&, ::TwoIntRecord &, ::NavMeshVertexEdgeData *&) const;
};
