#pragma once

struct TreeIterator;
struct TreeNode;
struct TreeValue;

struct HintTree {
public:
    // 0x00b398c0
    ::TreeIterator FUN_00b398c0(::TreeIterator, const ::TreeValue &);
    // 0x00b3ac00
    ::TreeIterator FUN_00b3ac00(bool, ::TreeNode *, const ::TreeValue &);
};
