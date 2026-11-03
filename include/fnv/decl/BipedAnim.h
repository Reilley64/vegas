#pragma once

class BSFaceGenModel;
class BipedAnimObject;
class NiNode;
class QueuedFile;
class QueuedHelmet;
class TESForm;
class TESObjectREFR;
class TESRace;
enum BIPED_BONE;
enum BIPED_OBJECT;
enum IO_TASK_PRIORITY;
enum SEX;
template <class> class NiPointer;

class BipedAnim {
public:
    // 0x004aae70
    void CompleteModelLoadTask();
    // 0x004ab020
    void ClearBipedObject(::BipedAnimObject *, bool, ::TESForm *);
    // 0x004ab230
    ::NiNode *GetBoneNode(::BIPED_BONE);
    // 0x004ab250
    void UpdateRaceSex(::TESRace *, ::SEX);
    // 0x004abd30
    void FUN_004abd30(::IO_TASK_PRIORITY, ::NiPointer< ::QueuedHelmet> &, ::QueuedFile *);
    // 0x004abfa0
    static bool CanLoadHiddenBipedObjects();
    // 0x004ae250
    static void AttachFaceGenNode(::NiNode *, ::NiNode *, ::NiNode *, ::BipedAnim *, ::BIPED_OBJECT, ::BSFaceGenModel *);
    // 0x004ae8a0
    bool IsSlotHidden(::BIPED_OBJECT);
    // 0x004af240
    static void ApplyReferenceExtraData(::NiNode *, ::NiNode *, ::BIPED_OBJECT, ::TESObjectREFR *);
    // 0x00571b50
    void AttachFaceGenNode();
};
