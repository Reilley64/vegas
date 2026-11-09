#include "AutoMemContext.h"
// fallout_shared/tesdatahandler_decls.h: declares AutoMemContext, TESDataHandler
#ifndef FNV_TESDATAHANDLER_DECLS_H
#define FNV_TESDATAHANDLER_DECLS_H

#include <cstdint>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077e0_shell.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_0045a730_shell.h"
#include "fnv/decl/FUN_0045c650_shell.h"
#include "fnv/decl/FUN_00460fb0_class.h"
#include "fnv/decl/FUN_00460fd0_class.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_004610f0_Class.h"
#include "fnv/decl/FUN_00503650_shell.h"
#include "fnv/decl/FUN_00506390Class.h"
#include "fnv/decl/FUN_00613790_shell.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_0062d2f0_shell.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/MessageHandler.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/PackedByteIntRecord.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/fnv_00455600__FUN_00455600_shell.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004ea000.h"
#include "fnv/symbols_00514000.h"
#include "fnv/symbols_00637000.h"
#include "fnv/symbols_00871000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_00984000.h"
#include "tesdatahandler_forms.h"
#include "tesdatahandler_defaults.h"
#include "tesdatahandler_files.h"
enum MEM_CONTEXT
{
    MEM_CONTEXT_COMPILE = 22,
    MEM_CONTEXT_ARCHIVES = 19,
    MEM_CONTEXT_DEFAULT_OBJECTS = 47,
    MEM_CONTEXT_FORMS = 48
};
using ::AutoMemContext;
class TESDataHandler
{
  public:
    unsigned int flags;
    TESFormList* objectList;
    unsigned char data_008[8];
    BSSimpleList<TESWorldSpace*> worldSpaces;
    BSSimpleList<TESForm*> climateList;
    BSSimpleList<TESForm*> imageSpaceList;
    BSSimpleList<TESForm*> imageSpaceModList;
    BSSimpleList<TESForm*> weatherList;
    BSSimpleList<TESForm*> enchantmentItemList;
    BSSimpleList<TESForm*> spellItemList;
    BSSimpleList<TESForm*> headPartList;
    BSSimpleList<TESForm*> hairList;
    BSSimpleList<TESForm*> eyeList;
    BSSimpleList<TESForm*> raceList;
    BSSimpleList<TESForm*> encounterZoneList;
    BSSimpleList<TESForm*> landTextureList;
    BSSimpleList<TESForm*> cameraShotList;
    BSSimpleList<TESForm*> classList;
    BSSimpleList<TESForm*> factionList;
    BSSimpleList<TESForm*> reputationList;
    BSSimpleList<TESForm*> challengeList;
    BSSimpleList<TESForm*> recipeList;
    BSSimpleList<TESForm*> recipeCategoryList;
    BSSimpleList<TESForm*> ammoEffectList;
    BSSimpleList<TESForm*> casinoList;
    BSSimpleList<TESForm*> caravanDeckList;
    BSSimpleList<TESForm*> scriptList;
    BSSimpleList<TESForm*> soundList;
    BSSimpleList<TESForm*> acousticSpaceList;
    BSSimpleList<TESForm*> ragdollList;
    BSSimpleList<TESForm*> globalList;
    BSSimpleList<TESForm*> voiceTypeList;
    BSSimpleList<TESForm*> impactDataList;
    BSSimpleList<TESForm*> impactDataSetList;
    BSSimpleList<TESForm*> topicList;
    BSSimpleList<TESForm*> topicInfoList;
    BSSimpleList<TESForm*> questList;
    BSSimpleList<TESForm*> combatStyleList;
    BSSimpleList<TESForm*> loadScreenList;
    BSSimpleList<TESForm*> waterFormList;
    BSSimpleList<TESForm*> effectShaderList;
    BSSimpleList<TESForm*> projectileList;
    BSSimpleList<TESForm*> explosionList;
    BSSimpleList<TESForm*> radiationStageList;
    BSSimpleList<TESForm*> dehydrationStageList;
    BSSimpleList<TESForm*> hungerStageList;
    BSSimpleList<TESForm*> sleepDeprivationStageList;
    BSSimpleList<TESForm*> debrisList;
    BSSimpleList<TESForm*> perkList;
    BSSimpleList<TESForm*> bodyPartDataList;
    BSSimpleList<TESForm*> noteList;
    BSSimpleList<TESForm*> listFormList;
    BSSimpleList<TESForm*> menuIconList;
    BSSimpleList<TESForm*> anioList;
    BSSimpleList<TESForm*> messageList;
    BSSimpleList<TESForm*> lightingTemplateList;
    BSSimpleList<TESForm*> musicTypeList;
    BSSimpleList<TESForm*> loadScreenTypeList;
    BSSimpleList<TESForm*> mediaSetList;
    BSSimpleList<TESForm*> mediaLocControllerList;
    void* regionList;
    NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> > interiorCells;
    NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> > addonNodes;
    NiTPointerList<TESForm*> pendingReferences;
    unsigned int nextID;
    TESFile* activeFile;
    BSSimpleList<TESFile*> files;
    unsigned int loadedCount;
    TESFile* loadedFiles[255];
    bool allowPlugin, specialFile, compiling, flag61b, flag61c, flag61d, flag61e, flag61f, flag620, flag621;
    unsigned char loadingGroup;
    unsigned char unk623;
    void* regionDataManager;
    struct FNVRecordManager* pRecordManager;
    unsigned int unk62c;
    TESEffectShader* unk630;
    TESEffectShader* unk634;
    TESForm* unk638;
    void RegisterAddonNode(BGSAddonNode*);
    int GetDLCIndex(const char*);
    void GetReferencesInArea(TESObjectCELL*, const NiPoint3&, float, const NiPoint3&, float,
                             bool(__cdecl*)(TESObjectREFR*, intptr_t), std::intptr_t);
    void GetRegions();
    TESFile* LookupTESFile(const char*);
    unsigned int GetNextID();
    void BuildCompiledFileList();
    TESSound* GetSoundByEditorID(const char*);
    BGSAddonNode* GetAddonNodeByIndex(unsigned int);
    TESReputation* GetReputation(unsigned int);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFaction* GetFactionByFormID(unsigned int);
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetCompiledFileCount();
    bool AddFormToDataHandler(TESForm*);
    BSSimpleList<TESCasino*>* GetTESCasinoList();
    BSSimpleList<TESClass*>* GetTESClassList();
    BSSimpleList<BGSNote*>* GetBGSNoteList();
    BSSimpleList<BGSAcousticSpace*>* GetBGSAcousticSpaceList();
    BSSimpleList<BGSImpactData*>* GetBGSImpactDataList();
    BSSimpleList<TESObjectANIO*>* GetTESObjectANIOList();
    BSSimpleList<BGSProjectile*>* GetBGSProjectileList();
    BSSimpleList<BGSRadiationStage*>* GetBGSRadiationStageList();
    BSSimpleList<BGSSleepDeprivationStage*>* GetBGSSleepDeprivationStageList();
    BSSimpleList<BGSLightingTemplate*>* GetBGSLightingTemplateList();
    BSSimpleList<TESLoadScreenType*>* GetTESLoadScreenTypeList();
    BSSimpleList<TESSkill*>* GetTESSkillList();
    BSSimpleList<TESTopic*>* GetTESTopicList();
    BSSimpleList<TESIdleForm*>* GetTESIdleFormList();
    BSSimpleList<TESFile*>* GetFileList();
    void SetSaveLoadGameState(int);
    bool LoadPluginFiles(bool);
    void MarkGameSettingsLoaded();
    void ReportDataHandlerError(int);
    bool FUN_00467780(TESFile*, bool);
    void SetField638(TESForm*);
    BSSimpleList<TESForm*>* FUN_00436aa0();
    BSSimpleList<TESForm*>* FUN_00624700();
    BSSimpleList<TESForm*>* FUN_004077e0();
    BSSimpleList<TESForm*>* FUN_0041d8a0();
    BSSimpleList<TESForm*>* FUN_0087eaa0();
    BSSimpleList<TESForm*>* FUN_00413f40();
    BSSimpleList<TESForm*>* FUN_00461110();
    BSSimpleList<TESForm*>* FUN_004ea950();
    BSSimpleList<TESForm*>* GetOffsetPtr();
    BSSimpleList<TESForm*>* FUN_0045a330();
    BSSimpleList<TESForm*>* FUN_004a0d10();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    static bool LoadForm(TESForm*, TESFile*);
    void InitializeMagicSystem();
    BSSimpleList<BGSListForm*>* GetBGSListFormList();
    BSSimpleList<BGSMessage*>* GetBGSMessageList();
    BSSimpleList<TESCombatStyle*>* GetTESCombatStyleList();
    static TESForm* CreateFormForType(unsigned char);
};
#endif
