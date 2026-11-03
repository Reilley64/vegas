#pragma once

class BGSAddonNode;
class TESClass;
class TESFile;
class TESForm;
class TESObjectCELL;
class TESObjectREFR;
class TESReputation;
class TESSound;
namespace TESDataHandlerTypes { class TESFaction; }
struct Item;
struct NiPoint3;
template <class> class BSSimpleList;

class TESDataHandler {
public:
    // 0x004601d0
    static bool LoadForm(::TESForm *, ::TESFile *);
    // 0x004603b0
    bool AddFormToDataHandler(::TESForm *);
    // 0x004614e0
    void GetRegions();
    // 0x00461600
    ::TESDataHandlerTypes::TESFaction *GetFactionByFormID(unsigned int);
    // 0x00461630
    ::TESReputation *GetReputation(unsigned int);
    // 0x004616c0
    ::TESSound *GetSoundByEditorID(const char *);
    // 0x004617e0
    ::BGSAddonNode *GetAddonNodeByIndex(unsigned int);
    // 0x00462ee0
    void BuildCompiledFileList();
    // 0x00462f40
    ::TESFile *LookupTESFile(const char *);
    // 0x00465010
    ::TESFile *GetCompiledFileByIndex(int);
    // 0x004650a0
    void SetSaveLoadGameState(int);
    // 0x00465110
    static ::TESForm *CreateFormForType(unsigned char);
    // 0x00467bd0
    bool ConstructObject(::TESFile *, bool, ::TESForm *, bool);
    // 0x00469800
    unsigned int GetNextID();
    // 0x0046f280
    void GetReferencesInArea(::TESObjectCELL *, const ::NiPoint3 &, float, const ::NiPoint3 &, float, bool (*)(TESObjectREFR *, long), long);
    // 0x0046fd50
    ::Item *FindNthMatchingItem(void *, int);
    // 0x0046feb0
    int GetDLCIndex(const char *);
    // 0x00482f20
    bool LoadDescriptionForForm();
    // 0x0051f550
    unsigned int GetCompiledFileCount();
    // 0x005ae670
    void ClearHairList();
    // 0x006130e0
    ::BSSimpleList< ::TESClass *> *GetTESClassList();
};
