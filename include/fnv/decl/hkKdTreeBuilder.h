#pragma once

class KdTreeNode;
namespace hkKdTreeBuildInput { struct ProjectedBoundsContext; }
namespace hkKdTreeBuildInput { struct WorkingSet; }
struct FieldlessRecord;

class hkKdTreeBuilder {
public:
    // 0x00df37b0
    static void FUN_00df37b0(const ::hkKdTreeBuildInput::WorkingSet &, ::KdTreeNode *, int, int, ::hkKdTreeBuildInput::ProjectedBoundsContext *, int *, const ::FieldlessRecord &);
};
