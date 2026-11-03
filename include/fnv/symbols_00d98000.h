#pragma once

struct QuantizedBounds;
struct TreeCollector;
struct TreeNode;
struct TreeVector;

// 0x00d986c0
void IntersectTree(void *, const ::TreeNode *, const ::QuantizedBounds *, const ::TreeVector *, const ::TreeVector *, const ::TreeVector *, const ::TreeVector *, float, float, float, ::TreeCollector *);
