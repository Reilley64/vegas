#pragma once

struct KdCtx;
struct KdNode;

struct MyTree {
public:
    // 0x00e07160
    int Recurse(::KdNode *, ::KdCtx *, ::KdCtx *);
};
