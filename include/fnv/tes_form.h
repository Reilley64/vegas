#ifndef FNV_TES_FORM_H
#define FNV_TES_FORM_H

#include "fnv/base_form_component.h"
#include "fnv/bs_simple_list.h"

// TESForm: the base class of the game's data forms.
//
// This is the one shared declaration of the class. It is the declaration the
// owning unit, src/fallout_shared/tesform.cpp, compiled before, unchanged:
// the base, the four fields, the 74 virtual functions that follow the four of
// BaseFormComponent, and the members that unit defines or calls. The header
// has no body.
//
// A member with an address beside it has a function row under this class's
// name in build/units.json, in the owning unit unless another is named. For a
// virtual function the slot is given too: the generated vftables of the
// derived classes hold that address in that slot, so the slot is ESTABLISHED.
//
// Every other virtual function is OPEN. It is declared because a later slot
// keeps its index only when every earlier one is declared. Its name and
// parameters are the spelling the copies of this class already used, not a
// finding. The header declares 78 slots, as the copies did; the repository
// shows at least 75 and at most 78 and does not tell 76, 77 and 78 apart. The constructor and the destructor are
// declared and their bodies are still defined under other class names.
// docs/shared-tesform.md has the field table, the slot table, what is open,
// and the rule for moving a unit onto this header.
class TESFile;
enum ENUM_FORM_ID;
template <class T> class BSStringT;
template <class T> class NiTLargePrimitiveArray;

class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();  // 0x00483710, slot 6
    virtual bool Unk_07(void);
    virtual bool Load(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);  // 0x00484b60, slot 18
    virtual void MarkAsUnmodified(unsigned int changedFlags);  // 0x00484bc0, slot 19
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);  // 0x00484da0, slot 23
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);  // 0x00484530, slot 49
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void SetFormFlag40(bool set);  // 0x004848b0, slot 52
    virtual void SetHavokDeath(bool set);  // 0x00484900, slot 53
    virtual void SetNeedToChangeProcess(bool set);  // 0x00484950, slot 54
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    TESForm();
    TESFile* GetFile(int fileIndex);  // 0x00484e60
    void NotifySaveLoadGameOfFormChange();  // 0x00484490
    void SetInitializationState(bool initialized);  // 0x00484ab0

    ENUM_FORM_ID GetFormType() const;  // 0x00401170
    bool GetDisabled() const;  // 0x00440da0
    void SetMasterFile(bool set);  // 0x004844f0
    void SetDestroyed(bool set);  // 0x00484650
    void SetDestructible(bool set);  // 0x004846a0
    void SetIgnoreFriendlyHits(bool set);  // 0x00484990
    static bool IsReservedFormID(unsigned int formID);  // 0x00484b40
    bool IsReservedFormID();  // 0x00484e40
    void SetFormFlags(int flags);  // 0x00484b90
    TESFile* GetOwnerMaster();  // 0x00484ee0
    bool GetInitialized() const;  // 0x004013e0, owned by bgsdehydration.cpp
    static TESForm* LookupFormByEditorID(const char* editorID);  // 0x00483a00
    void SetFile(TESFile* file);  // 0x00484f50
    static NiTLargePrimitiveArray<TESForm*>* ms_pAllForms;
    static void InitializeFormIDMap();  // 0x00483a50
};

#endif
