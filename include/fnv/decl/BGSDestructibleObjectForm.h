#pragma once

class BaseFormComponent;
class QueuedFile;
class TESBoundObject;
class TESForm;
class TESObjectREFR;
enum IO_TASK_PRIORITY;

class BGSDestructibleObjectForm {
public:
    // 0x004772f0
    static void UpdateDestructionMap();
    // 0x00477640
    void QueueResourceLoad(::TESBoundObject *, ::IO_TASK_PRIORITY, ::QueuedFile *);
    // 0x004786e0
    void FUN_004786e0(::BaseFormComponent *);
    // 0x00478be0
    void InitItem(::TESForm *);
    // 0x007038b0
    static void UpdateTargetHealthBar(::TESObjectREFR *);
};
