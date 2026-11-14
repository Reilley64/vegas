#pragma once

struct ArrQ;
class NiNode;
struct ParamT;

struct ThisT {
public:
    // 0x00595d30
    bool IsWithinRange();
    // 0x0060a950
    void FUN_0060a950(::ParamT *);
    // 0x0068a8f0
    void CollectUniqueChildValues(::NiNode *, ::ArrQ *, int *);
    // 0x007d42b0
    void PopulateList(int);
};
