#pragma once

class TESFile;
enum ENUM_FORM_ID;
template <class> class NiTLargePrimitiveArray;

class TESForm {
public:
    // 0x00401170
    ::ENUM_FORM_ID GetFormType() const;
    // 0x004013e0
    bool GetInitialized() const;
    // 0x00440da0
    bool GetDisabled() const;
    // 0x00483710
    void ClearData();
    // 0x00483a00
    static ::TESForm *LookupFormByEditorID(const char *);
    // 0x00483a50
    static void InitializeFormIDMap();
    // 0x00484490
    void NotifySaveLoadGameOfFormChange();
    // 0x00484530
    void MarkForDeletion(bool);
    // 0x00484650
    void SetDestroyed(bool);
    // 0x004846a0
    void SetDestructible(bool);
    // 0x00484990
    void SetIgnoreFriendlyHits(bool);
    // 0x00484ab0
    void SetInitializationState(bool);
    // 0x00484b40
    static bool IsReservedFormID(unsigned int);
    // 0x00484b60
    void MarkAsModified(unsigned int);
    // 0x00484b90
    void SetFormFlags(int);
    // 0x00484bc0
    void MarkAsUnmodified(unsigned int);
    // 0x00484da0
    void LoadGame(void *);
    // 0x00484e40
    bool IsReservedFormID();
    // 0x00484e60
    ::TESFile *GetFile(int);
    // 0x00484ee0
    ::TESFile *GetOwnerMaster();
    // 0x00484f50
    void SetFile(::TESFile *);
    // 0x00693ef0
    void SetCollisionDisabled(bool);
    // 0x011c54c4
    static ::NiTLargePrimitiveArray< ::TESForm *> *ms_pAllForms;
};
