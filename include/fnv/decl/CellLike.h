#pragma once

struct FaceGenNode;
struct RefForm;

struct CellLike {
public:
    // 0x00545740
    ::FaceGenNode *GetOrCreateFaceGenNode(::RefForm *);
};
