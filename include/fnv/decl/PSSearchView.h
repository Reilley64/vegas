#pragma once

class NavMeshEdgeSegment;
class PathSmootherPOVAvoidanceNode;
template <class, class> class AStarNode;

struct PSSearchView {
public:
    // 0x006b32f0
    ::AStarNode< ::PathSmootherPOVAvoidanceNode, ::NavMeshEdgeSegment> *InsertNode(unsigned int, const ::PathSmootherPOVAvoidanceNode &, float);
};
