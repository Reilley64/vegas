#pragma once

struct KFQueueOwner;
template <class> class BSSimpleList;

struct ModelLoaderKFList {
public:
    // 0x004463b0
    void QueueKFPathsFromList(::BSSimpleList<const char *> *, ::KFQueueOwner *, int, void *, const char *);
};
