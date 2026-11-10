#pragma once

struct BGSLoadFormBuffer;
class TESForm;
enum QUEUED_SUB_BUFFER_TYPE;

class LoadGameSubBufferQueue {
public:
    // 0x008651d0
    LoadGameSubBufferQueue();
    // 0x008652f0
    void ProcessSubBuffer(::QUEUED_SUB_BUFFER_TYPE, ::BGSLoadFormBuffer *, ::TESForm *);
    // 0x00865360
    void QueueAnimationAndCharController();
};
