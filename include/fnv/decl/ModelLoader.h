#pragma once

class QueuedFile;
enum IO_TASK_PRIORITY;
template <class> class BSSimpleList;

struct ModelLoader {
public:
    // 0x00442600
    void ProcessQueuedFile();
    // 0x004431d0
    void FUN_004431d0();
    // 0x00443220
    void FUN_00443220();
    // 0x00446500
    void QueueFileList(::BSSimpleList<const char *> *, ::IO_TASK_PRIORITY, ::QueuedFile *, const char *);
    // 0x00446e30
    static void UpdateLoadingStatusCallback();
};
