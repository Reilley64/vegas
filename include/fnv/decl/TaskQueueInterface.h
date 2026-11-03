#pragma once

class BSPackedTask;
class NiPoint3;

class TaskQueueInterface {
public:
    // 0x00406d30
    static void CopyStringToBuffer(char *, unsigned int, const char *);
    // 0x00450f90
    void QueueActorDisarm(bool);
    // 0x004537b0
    static ::TaskQueueInterface *GetSingleton();
    // 0x00476b00
    void SetTaskFlag(bool);
    // 0x0047aa40
    void QueueReferenceStateTask(bool);
    // 0x004902f0
    void FUN_004902f0(bool);
    // 0x004ef970
    void FUN_004ef970(bool);
    // 0x005467c0
    void SetTaskFlag2000(bool);
    // 0x005468b0
    void SetTaskFlag_005468b0(bool);
    // 0x00566930
    void FUN_00566930(bool);
    // 0x00576640
    void FUN_00576640(bool);
    // 0x005c3420
    ::NiPoint3 &QueueActorAnimationTask(::NiPoint3 &);
    // 0x00635fe0
    void FUN_00635fe0(bool);
    // 0x00703490
    static void ThreadProcessSecondaryInput();
    // 0x007034c0
    static void ThreadProcessInput(unsigned int);
    // 0x0087a850
    void ProcessTaskQueue();
    // 0x0087b990
    static void ProcessQueuedTask(const ::BSPackedTask &);
    // 0x0087d160
    void ProcessPackedTask(const ::BSPackedTask &);
    // 0x0087e100
    void FUN_0087e100(bool);
    // 0x008d6f10
    void SetTaskFlag_008d6f10(bool);
};
