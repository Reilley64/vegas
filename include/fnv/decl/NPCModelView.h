#pragma once

template <class> class BSSimpleList;

struct NPCModelView {
public:
    // 0x0060af90
    ::BSSimpleList<const char *> *CollectModelPaths(bool, bool);
};
