
// src/fallout_shared/tes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "fnv/decl/Actor.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/B200Owner.h"
#include "fnv/decl/B4F9A0ShaderManager.h"
#include "fnv/decl/B93BE30ProcessManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BGSDestructibleObjectForm.h"
#include "fnv/decl/BGSImpactDataSet.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSProjectile.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSFileCache.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/C00c66300.h"
#include "fnv/decl/C6B540Manager.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellStub.h"
#include "fnv/decl/CellTarget.h"
#include "fnv/decl/CellUpdateView.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/Cls.h"
#include "fnv/decl/DeletionDataHandler.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/Entry664.h"
#include "fnv/decl/FUN_00401280_Class.h"
#include "fnv/decl/FUN_004036b0_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_00447950_shell.h"
#include "fnv/decl/FUN_00450fd0_class.h"
#include "fnv/decl/FUN_004524f0_Class.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_00453700_shell.h"
#include "fnv/decl/FUN_00454380_Class.h"
#include "fnv/decl/FUN_004543a0_Class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00454420_Class.h"
#include "fnv/decl/FUN_00454b30_class.h"
#include "fnv/decl/FUN_00454b70.h"
#include "fnv/decl/FUN_00456520_Class.h"
#include "fnv/decl/FUN_00457ff0_class.h"
#include "fnv/decl/FUN_00458010_class.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_0045a140_Class.h"
#include "fnv/decl/FUN_0045a160_Cls.h"
#include "fnv/decl/FUN_0045a1a0_Class.h"
#include "fnv/decl/FUN_0045c4a0_class.h"
#include "fnv/decl/FUN_0045c4c0_cls.h"
#include "fnv/decl/FUN_0045c4e0_This.h"
#include "fnv/decl/FUN_0045c570_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00460360_shell.h"
#include "fnv/decl/FUN_00461960_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_0046ec10_cls.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004ba7d0_shell.h"
#include "fnv/decl/FUN_004ba9a0_shell.h"
#include "fnv/decl/FUN_004bac20_shell.h"
#include "fnv/decl/FUN_004baec0_shell.h"
#include "fnv/decl/FUN_004f9bf0_shell.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_00526270_shell.h"
#include "fnv/decl/FUN_00528820_shell.h"
#include "fnv/decl/FUN_0053f440_shell.h"
#include "fnv/decl/FUN_00545cf0_Cls.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00547610_shell.h"
#include "fnv/decl/FUN_0054af40_cls.h"
#include "fnv/decl/FUN_0054bb90_shell.h"
#include "fnv/decl/FUN_00553d00_shell.h"
#include "fnv/decl/FUN_00564e60_shell.h"
#include "fnv/decl/FUN_005651e0_shell.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/FUN_00565730_shell.h"
#include "fnv/decl/FUN_00576830_shell.h"
#include "fnv/decl/FUN_00580080_shell.h"
#include "fnv/decl/FUN_005800a0_shell.h"
#include "fnv/decl/FUN_005800c0_shell.h"
#include "fnv/decl/FUN_005a8040_class.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d8710_shell.h"
#include "fnv/decl/FUN_00620130_Class.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_0062de90_shell.h"
#include "fnv/decl/FUN_0062e710_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_006fce00_shell.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_00812870_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_0085f850_class.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_008727b0_Class.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_0093bea0_cls.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0096bc50_shell.h"
#include "fnv/decl/FUN_00975f90_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5e930.h"
#include "fnv/decl/FUN_00b631d0_cls.h"
#include "fnv/decl/FUN_00c44e20.h"
#include "fnv/decl/FUN_00c47980_cls.h"
#include "fnv/decl/FUN_00c66310_class.h"
#include "fnv/decl/FUN_00ec17c0_Class.h"
#include "fnv/decl/FaderManager.h"
#include "fnv/decl/FakeGame.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Getter_9b8.h"
#include "fnv/decl/Holder006fcdb0.h"
#include "fnv/decl/IOManager.h"
#include "fnv/decl/LLD_TESHelper.h"
#include "fnv/decl/LandForm.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MessageHandler.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/NiColorInterpolator.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/NiSourceTexture.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/Processor.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Renderer.h"
#include "fnv/decl/Root.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SceneB54.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/ShadowSceneNode.h"
#include "fnv/decl/Shell54ca00.h"
#include "fnv/decl/SortHandler.h"
#include "fnv/decl/StandNode.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/Stub.h"
#include "fnv/decl/Surface.h"
#include "fnv/decl/TESObjectWEAP.h"
#include "fnv/decl/TESQuest.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESSaveLoadGame_861f20.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/TallGrassShaderProperty.h"
#include "fnv/decl/TextureFileEntrySetter.h"
#include "fnv/decl/ThisCls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/Worker53.h"
#include "fnv/decl/WorldCellLoader.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/bhkEntityListener_shell.h"
#include "fnv/decl/bhkWorld.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00454b10__TESObjectCELL.h"
#include "fnv/decl/fnv_0046ddb0__ModelTest.h"
#include "fnv/decl/fnv_004baca0__GridCellArrayHelper.h"
#include "fnv/decl/fnv_0053f0e0__TESObjectLAND.h"
#include "fnv/decl/fnv_0053f570__OwnerInterp.h"
#include "fnv/decl/fnv_0053fa40__HostMesh53.h"
#include "fnv/decl/fnv_00547250__FUN_00547250_shell.h"
#include "fnv/decl/fnv_00548880__FNV_Cell.h"
#include "fnv/decl/fnv_0054c740__FUN_0054c740_shell.h"
#include "fnv/decl/fnv_0054cfd0__TESObjectCELL_Ext.h"
#include "fnv/decl/fnv_00550340__FUN_00550340_t.h"
#include "fnv/decl/fnv_00552970__FUN_00552970_Call.h"
#include "fnv/decl/fnv_005538e0__Cell5538.h"
#include "fnv/decl/fnv_00553bf0__S00553bf0.h"
#include "fnv/decl/fnv_00558c90__FUN_00558c90_shell.h"
#include "fnv/decl/fnv_00565870__FUN_00565870_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_0056f700__Ref.h"
#include "fnv/decl/fnv_00570f00__FUN_00570f00_shell.h"
#include "fnv/decl/fnv_00570f70__Obj570.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00587550__FUN_00587550_shell.h"
#include "fnv/decl/fnv_00588150__FUN_00588150_shell.h"
#include "fnv/decl/fnv_0063ac70__FUN_0063ac70_shell.h"
#include "fnv/decl/fnv_006c39c0__FUN_006c39c0_shell.h"
#include "fnv/decl/fnv_006fd130__FUN_006fd130_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008492b0__FUN_008492b0_shell.h"
#include "fnv/decl/fnv_0086ff70__Main86.h"
#include "fnv/decl/fnv_00871dc0__FUN_00871dc0_class.h"
#include "fnv/decl/fnv_0093db60__PlayerCenterOnCell.h"
#include "fnv/decl/fnv_0096d810__FUN_0096d810_shell.h"
#include "fnv/decl/fnv_0096eb40__FUN_0096eb40_cls.h"
#include "fnv/decl/fnv_009d9f20__FUN_009d9f20_shell.h"
#include "fnv/decl/fnv_00b5cbd0__ShadowSceneNode_Self.h"
#include "fnv/decl/fnv_00b5ddf0__LocalTarget.h"
#include "fnv/decl/s54ba00__Owner.h"
#include "fnv/decl/s54ba80__Owner.h"
#include "fnv/decl/s54cee0__Owner.h"
#include "fnv/decl/s5573e0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00451000.h"
#include "fnv/symbols_00452000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00456000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045a000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0049c000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004a9000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004e7000.h"
#include "fnv/symbols_00514000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00557000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_0063e000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_006fd000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00771000.h"
#include "fnv/symbols_00878000.h"
#include "fnv/symbols_00952000.h"
#include "fnv/symbols_00993000.h"
#include "fnv/symbols_00a5e000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aff000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b58000.h"
#include "fnv/symbols_00b65000.h"
#include "fnv/symbols_00c3c000.h"
#include "fnv/symbols_01000000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00b58570_Class.h"
#include "fnv/decl/FUN_00c4ed40_cls.h"
#include "fnv/decl/FUN_00c67850_Class.h"
#include "fnv/decl/FUN_00c68a40_Class.h"
#include "fnv/decl/S_00c4edf0_cls.h"
#include "fnv/decl/S_Owner.h"
#include "fnv/decl/This676.h"
#include "fnv/decl/fnv_00c1b4a0__RefObjectList.h"
#include "fnv/decl/fnv_00c6aac0__FUN_00c6aac0_Owner.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00b61000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/decl/fnv_00547ad0__CellMask.h"
#include "fnv/symbols_00441000.h"
#include "fnv/symbols_0057d000.h"
struct GlobalObject_00a7b610
{
};

struct NiRTTI
{
};

struct FUN_00450620_shell
{
    const NiRTTI* GetNiRTTI() const;
};

// @fnv 0x00450620
const NiRTTI* FUN_00450620_shell::GetNiRTTI() const
{
    return (const NiRTTI*)&::g_01202df8;
}

struct BSTempNodeManager
{
    virtual ~BSTempNodeManager();
    void* FUN_00450630(unsigned int flags);
};

// @fnv 0x00450630
void* BSTempNodeManager::FUN_00450630(unsigned int flags)
{
    reinterpret_cast<::FUN_00c44e20 *>((this))->FUN_00c44e20::~FUN_00c44e20();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xb0);
    return this;
}

struct FUN_004512a0_shell
{
    unsigned char m_ucState;
    void SetState(unsigned char ucState);
};

// @fnv 0x004512a0
void FUN_004512a0_shell::SetState(unsigned char ucState)
{
    *reinterpret_cast<unsigned char*>(this + 0x26) = ucState;
}

extern char DAT_01189184;

// @fnv 0x00451520
void FUN_00451520(unsigned char value)
{
    DAT_01189184 = value;
}

struct NP
{
    NP& operator=(void*);
};


// @fnv 0x00451570
void FUN_00451570(void* apValue)
{
    (*reinterpret_cast<::NP *>(&::DAT_011f95e8)) = apValue;
}

extern unsigned char DAT_011ad86c;

// @fnv 0x00451590
void FUN_00451590(unsigned char value)
{
    DAT_011ad86c = value;
}

struct AlchemyItem;
struct BGSAddonNode;
struct BGSDebris;
struct BGSExplosion;
struct BGSMessage;
struct BGSPerk;
struct BGSPrimitive;
struct BGSProjectile;
struct BGSVoiceType;
struct FormRecordHeader;
struct InventoryChanges;
struct InventoryStackRecord;
struct NiAVObject;
struct NiPoint3;
struct NiTriBasedGeom;
struct Script;
struct TESAmmoEffect;
struct TESBoundObject;
struct TESCaravanDeck;
struct TESCasino;
struct TESChallenge;
struct TESClass;
struct TESCombatStyle;
struct TESEffectShader;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESLandTexture;
struct TESLoadScreenType;
struct TESObject;
struct TESObjectANIO;
struct TESObjectCELL;
struct TESFormList;
struct TESObjectREFR;
struct TESQuest;
struct TESRace;
struct TESRecipe;
struct TESRecipeCategory;
struct TESRegionDataManager;
struct TESRegionList;
struct TESReputation;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct TESDataHandler
{
    static bool LoadForm(TESForm*, TESFile*);
    bool SaveForm(TESForm*, bool);
    char* GetFormName(unsigned char);
    void OutputFormList();
    void SetModelSizeOutputEnabled(bool);
    void OutputModelSizeList();
    void CheckTexturesRecurse(NiAVObject*, char*);
    static bool CheckDismemberSkinInstanceRecurse(NiAVObject*, char*);
    void PrintTextureInfo(void*, NiTriBasedGeom*, char*, char*, bool);
    void OutputTextureInfo();
    void CheckTexturePath(char*);
    bool AddFormToDataHandler(TESForm*);
    void ReleaseForm(TESForm*);
    unsigned char NotUniqueID(char*);
    void GetObjectCounts();
    void GetReferenceCounts();
    void GetRegions();
    void InitializeMagicSystem();
    void GetReferencesInArea(TESObjectCELL*, void*, float, void*, float, int*, intptr_t);
    void GetReferencesInArea(void*, float, void*, float, int*, long);
    void EnumReferencesCloseToRef(TESObjectREFR*, float, void*, float, int*, long);
    static bool ReferenceBaseSearchEnumFunc(TESObjectREFR*, intptr_t);
    bool FindTeleportPathBetweenSmallSpaces(TESForm*, TESForm*, void*);
    bool FindTeleportPathBetweenWorlds(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindTeleportPathFromSmallSpaceToWorld(TESForm*, TESWorldSpace*, void*, bool);
    TESObjectREFR* FindFirstReference(TESObject*);
    TESObjectREFR* FindFirstReference(char*);
    bool FindConnectedWorld(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindConnectedSmallSpace(TESForm*, TESForm*, void*, void*);
    TESWorldSpace* BuildPathNodeLocation(TESForm*, NiPoint3*, void*);
    TESObjectREFR* FindClosestReference(TESBoundObject*, void*, TESObjectCELL*);
    TESObjectREFR* FindClosestReference(char*, void*, TESObjectCELL*);
    TESObjectREFR* GetReference(char*);
    TESObjectREFR* GetReference(unsigned int);
    TESLandTexture* GetLandTexture(char*);
    TESLandTexture* GetLandTexture(unsigned int);
    TESRace* GetRace(char*);
    TESRace* GetRace(unsigned int);
    TESClass* GetClass(char*);
    TESClass* GetClass(unsigned int);
    Script* GetScript(char*);
    Script* GetScript(unsigned int);
    TESSound* GetSoundByEditorID(char*);
    TESSound* GetSoundByEditorID(unsigned int);
    TESGlobal* GetGlobal(char*);
    TESGlobal* GetGlobal(unsigned int);
    BGSVoiceType* GetVoiceType(unsigned int);
    TESFaction* GetFactionByFormID(char*);
    TESFaction* GetFactionByFormID(unsigned int);
    TESReputation* GetReputation(char*);
    TESReputation* GetReputation(unsigned int);
    TESRecipe* GetRecipe(char*);
    TESRecipe* GetRecipe(unsigned int);
    TESRecipeCategory* GetRecipeCategory(char*);
    TESRecipeCategory* GetRecipeCategory(unsigned int);
    TESCasino* GetCasino(char*);
    TESCasino* GetCasino(unsigned int);
    TESCaravanDeck* GetCaravanDeck(char*);
    TESCaravanDeck* GetCaravanDeck(unsigned int);
    TESTopic* GetAudioBackendData(int, int);
    TESTopic* GetAudioBackendData(char*);
    TESTopic* GetAudioBackendData(unsigned int);
    TESChallenge* GetChallenge(char*);
    TESAmmoEffect* GetAmmoEffect(char*);
    TESQuest* GetQuest(char*);
    TESCombatStyle* GetCombatStyle(char*);
    TESEffectShader* GetEffectShader(char*);
    BGSProjectile* GetProjectileData(char*);
    BGSExplosion* GetExplosion(char*);
    BGSDebris* GetDebris(char*);
    BGSPerk* GetPerk(char*);
    BGSMessage* GetMessage(char*);
    TESLoadScreenType* GetLoadScreenType(char*);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFormList* GetObjectList();
    void* GetFileList();
    void* GetPartDataList();
    void* GetPerks();
    void* GetDebrisList();
    void* GetExplosionList();
    void* GetProjectileList();
    void* GetRadiationStageList();
    void* GetDehydrationStageList();
    void* GetHungerStageList();
    void* GetSleepDeprevationStageList();
    void* GetEffectShaderList();
    void* GetWaterList();
    void* GetLoadScreenList();
    void* GetAnimObjectList();
    TESObjectANIO* GetAnimObject(TESIdleForm*, int);
    void* GetCombatStyleList();
    void* GetPackageList();
    void* GetWorldSpaceList();
    void* GetClimateList();
    void* GetImageSpaceList();
    void* GetImageSpaceModifierList();
    void* GetWeatherList();
    void* GetEnchantmentItemList();
    void* GetSpellItemList();
    void* GetLandTextList();
    void* GetCameraShotList();
    void* GetHeadPartList();
    void* GetHairList();
    void* GetEyesList();
    void* GetRaceList();
    void* GetZoneList();
    void* GetClassList();
    void* GetFactionList();
    void* GetReputationList();
    void* GetChallengeList();
    void* GetRecipeList();
    void* GetRecipeCategoryList();
    void* GetAmmoEffectList();
    void* GetCasinoList();
    void* GetCaravanDeckList();
    void* GetSoundList();
    void* GetAcousticSpaceList();
    void* GetRagdollList();
    void* GetGlobalList();
    void* GetVoiceTypeList();
    void* GetImpactDataList();
    void* GetImpactDataSetList();
    void* GetBadFormList();
    TESRegionList* GetRegionList();
    void* GetTopicList();
    void* GetTopicInfoList();
    void* GetNoteList();
    void* GetMenuIconList();
    void* GetListFormList();
    void* GetMessageList();
    void* GetLightingTemplateList();
    void* GetMusicTypeList();
    void* GetLoadScreenTypeList();
    void* GetMediaSetList();
    void* GetMediaLocationControllerList();
    void AddTopic(TESTopic*);
    void RemoveTopic(TESTopic*);
    void AddTopicInfo(TESTopicInfo*);
    void RemoveTopicInfo(TESTopicInfo*);
    void* GetScriptList();
    void SortScriptList();
    void* GetQuestList();
    void AddQuest(TESQuest*);
    void RemoveQuest(TESQuest*);
    unsigned int GetAddonNodeCount();
    BGSAddonNode* GetAddonNodeByIndex(unsigned int);
    void RegisterAddonNode(BGSAddonNode*);
    void RemoveAddonNode(BGSAddonNode*);
    TESObjectCELL* GetCellByNameAndGrid(char*);
    TESObjectCELL* GetCellByNameAndGrid(char*, int, int, TESWorldSpace*);
    unsigned int GetInteriorCellCount();
    TESObjectCELL* GetCellByInteriorIndex(unsigned int);
    void RefreshCellList();
    unsigned int GetCellCount();
    TESObjectCELL* GetCellByIndex(unsigned int);
    TESObjectCELL* GetCellByNumericID(unsigned int);
    TESObjectCELL* LookupCellByEditorID(char*);
    TESWorldSpace* GetWorldSpaceByEditorID(char*, int*, int*);
    TESObjectCELL* GetCellByWorldPosition(float, float, TESWorldSpace*, bool);
    TESObjectCELL* GetCellAtGridPosition(int, int, TESWorldSpace*, bool);
    TESWorldSpace* GetWorldSpaceForCell(TESObjectCELL*);
    void RemoveCell(TESObjectCELL*);
    void RemoveCell(int, int, TESWorldSpace*);
    void RemoveCell(char*);
    TESObjectREFR* CreateReferenceInLoadedArea(TESBoundObject*, void*, void*, bool, BGSPrimitive*, void*);
    TESObjectREFR* PlaceReferenceAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*,
                                            TESObjectREFR*, BGSPrimitive*, void*);
    TESObjectCELL* SelectCell(struct blob12, bool*, TESWorldSpace*);
    bool AssignToCell(TESObjectCELL*, TESObjectREFR*);
    bool PlaceInExterior(TESObjectREFR*, TESWorldSpace*);
    void RemoveDuplicateReferences();
    TESObjectREFR* CreateProjectileAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESObjectREFR* PlaceObjectAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESFile* LookupTESFile(unsigned int);
    TESFile* LookupTESFile(char*);
    bool RemoveListFile(TESFile*);
    static void FileCacheCompleteCallback(char*);
    char* GetActiveFileName();
    void SetActiveFile(TESFile*);
    TESFile* GetActiveFile();
    void RemoveIDFromDataHandler(unsigned int);
    unsigned int GetNextID();
    void AddCompiledFile(TESFile*);
    void ClearFileList();
    bool UpdateLoadingStatusCallback(char*);
    void BuildCompiledFileList();
    int CountCheckedFiles(int);
    unsigned int CountFiles();
    unsigned int CountCompiled();
    bool LoadPluginFiles(bool);
    bool ClearData();
    bool SaveActiveData(char*, bool);
    void CloseAllTES();
    bool LoadTESFile(TESFile*, bool);
    void ClearLoadedFormCount();
    unsigned int AddDownloadedContentToFileList();
    void RunAllPersistentRefScripts();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    bool FormGroupLoadsInGame(TESFile*, FormRecordHeader*);
    static TESForm* CreateFormForType(unsigned char);
    bool ResetOffsetData(TESFile*);
    void FixAllScriptIDs();
    void SetSaveLoadGameState(int);
    bool GetMasterSave();
    void SetMasterSave(bool);
    bool GetSaveLoadGame();
    void SetSaveLoadGame(bool);
    bool GetSaveLoad();
    void SetSaveLoad(bool);
    bool GetAutoSaving();
    void SetAutoSaving(bool);
    bool GetClearingData();
    void SetClearingData(bool);
    bool GetHasDesiredFiles();
    void SetHasDesiredFiles(bool);
    bool IsSavingLoading();
    void SetCheckingModels(bool);
    bool GetCheckingModels();
    void SetLoadingFiles(bool);
    bool GetLoadingFiles();
    bool GetGameSettingsLoaded();
    void MarkGameSettingsLoaded();
    void FlushSoundBuffers();
    void SetBarterContainer(TESObjectREFR*);
    void AddBarterItem(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearBarterContainer();
    InventoryChanges* GetBarterContainer();
    void CreateRecipeContainer(TESObjectREFR*);
    void RemoveItemRecipeContainer(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearRecipeContainer();
    InventoryChanges* GetRecipeContainer();
    TESRegionDataManager* GetRegionDataManager();
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetNextFormID();
    void SetNextFormID(unsigned int);
    bool FormIDExists(unsigned int);
    AlchemyItem* DoesPotionMatch(AlchemyItem*);
    void SetDontRemoveIDs(bool);
    bool GetDontRemoveIDs();
    void* QArrayInteriorCells();
    TESEffectShader* GetSpotterShader();
    TESEffectShader* GetItemDetectedShader();
    TESEffectShader* GetCateyeShader();
    void SetSpotterShader(TESEffectShader*);
    void SetItemDetectedShader(TESEffectShader*);
    void SetCateyeShader(TESEffectShader*);
    void ClearDLCFlags();
    int GetNumDLCInstalled();
    void DataError(int);
    bool IsFormIDRemapped(unsigned int);
    void AdvanceNextID();
    char* GetDLCFlags();
    bool IsDLCFlagSet(char);
    void SetDLCFlag(char, bool);
    int GetDLCIndex(char*);
    unsigned int LoadFilesInDirectory(char*, void*);
    void* __vecDelDtor(unsigned int);
    char m_cDLCFlagCount;
    char _pad_1[3];
    TESFormList* m_pBoundObjectList;
    char m_kPackages[8];
    char m_kWorldSpaceList[8];
    char m_kClimateList[8];
    char m_kImageSpaceList[8];
    char m_kImageSpaceModifierList[8];
    char m_kWeatherList[8];
    char m_kEnchantmentItemList[8];
    char m_kSpellList[8];
    char m_kHeadPartList[8];
    char m_kHairList[8];
    char m_kEyeList[8];
    char m_kRaceList[8];
    char m_kEncounterZoneList[8];
    char m_kLandTextureList[8];
    char m_kCameraShotList[8];
    char m_kClassList[8];
    char m_pVoiceType[8];
    char m_kReputationList[8];
    char m_kChallengeList[8];
    char m_kCraftingRecipeList[8];
    char m_kRecipeCategoryList[8];
    char m_kAmmoEffectList[8];
    char m_kCasinoList[8];
    char m_kCaravanDeckList[8];
    char m_kScriptList[8];
    char m_kSoundList[8];
    char m_kAcousticSpaceList[8];
    char m_kRagdollList[8];
    char m_kGlobalList[8];
    char m_kVoiceTypeList[8];
    char m_kImpactEffectList[8];
    char m_kImpactDataSetList[8];
    char m_kTopicList[8];
    char m_kTopicInfoList[8];
    char m_kQuestList[8];
    char m_kCombatStyleList[8];
    char m_kLoadScreenList[8];
    char m_kWaterFormList[8];
    char m_kEffectShaderList[8];
    char m_kProjectileList[8];
    char m_kExplosionList[8];
    char m_kRadiationStageList[8];
    char m_kDehydrationStageList[8];
    char m_kHungerStageList[8];
    char m_kSleepDeprivationStageList[8];
    char m_kDebrisList[8];
    char m_kPerkList[8];
    char m_kBodyPartDataList[8];
    char m_kNoteList[8];
    char m_kListFormList[8];
    char m_kMenuIconList[8];
    char m_kFourthDataList[8];
    char m_kMessageList[8];
    char m_kLightingTemplateList[8];
    char m_kMusicTypeList[8];
    char m_kLoadScreenTypeList[8];
    char m_kMediaSetList[8];
    char m_kMediaLocationControllerList[8];
    TESRegionList* m_pRegions;
    char m_kFirstArrayStorage[16];
    char m_kSecondArrayStorage[16];
    char m_kThirdArrayStorage[12];
    unsigned int m_uiFormCount;
    TESFile* m_pActiveFile;
    char m_kModInfoList[8];
    unsigned int m_iLoadedModCount;
    char m_ppLoadedMods[1020];
    bool m_bLoadingFiles;
    bool m_bGameSettingsLoaded;
    bool m_bMasterSave;
    bool m_bSaveLoadGame;
    bool m_bFirstStateField;
    bool m_bSecondStateField;
    bool m_bThirdStateField;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    unsigned char m_ucInternalStateByte;
    char _pad_623[1];
    TESRegionDataManager* m_pRegionDataManager;
    InventoryChanges* m_pFirstInventoryChanges;
    InventoryChanges* m_pSecondInventoryChanges;
    TESEffectShader* m_pFirstEffectShader;
    TESEffectShader* m_pSecondEffectShader;
    TESEffectShader* m_pThirdEffectShader;
};
struct FUN_004516b0_shell : public TESDataHandler
{
    bool FUN_004516b0();
};

// @fnv 0x004516b0
bool FUN_004516b0_shell::FUN_004516b0()
{
    return m_bMasterSave;
}

struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESForm;
struct TESObjectCELL;
struct TESObjectREFR;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
struct FUN_004523c0_shell : public BGSSaveLoadGame
{
    bool FUN_004523c0();
};


// @fnv 0x004523c0
bool FUN_004523c0_shell::FUN_004523c0()
{
    return ((int)(reinterpret_cast<::FUN_00450fd0_class *>((this))->GetByteAtOffset38())) == 5;
}

struct FUN_00452420_shell
{
    unsigned int pad0;   // +0x00
    unsigned int pad1;   // +0x04
    unsigned int pad2;   // +0x08
    unsigned int pad3;   // +0x0C
    unsigned int flags;  // +0x10
    bool GetFlag(unsigned int aiFlags) const;
};

// @fnv 0x00452420
bool FUN_00452420_shell::GetFlag(unsigned int aiFlags) const
{
    return (flags & aiFlags) ? true : false;
}

struct FUN_00452440_shell
{
    bool FUN_00452440();
};

struct FUN_004e32c0_shell
{
};

struct PlaceableWaterData
{
    unsigned int flags;
};

struct BGSPlaceableWater
{
    bool HasFlags(unsigned int flags);
};
// @fnv 0x00452440
bool FUN_00452440_shell::FUN_00452440()
{
    return reinterpret_cast<::BGSPlaceableWater *>((reinterpret_cast<FUN_004e32c0_shell*>(this)))->HasFlags(0x40000000);
}

// @fnv 0x00452460
bool BGSPlaceableWater::HasFlags(unsigned int flags)
{
    return (((::PlaceableWaterData *)(reinterpret_cast<::FUN_00624700_shell *>((this))->FUN_00624700()))->flags & flags) ? true : false;
}

extern unsigned char DAT_0119b8c8;

// @fnv 0x00452480
unsigned char FUN_00452480()
{
    return DAT_0119b8c8;
}


struct FUN_00453470_shell
{
    int FUN_00453470(void);
};

// @fnv 0x00453470
int FUN_00453470_shell::FUN_00453470(void)
{
    return ((int)(::FUN_009938b0((const unsigned short *)(void *)(reinterpret_cast<char*>(this) + 0x9c))));
}

struct FUN_004534f0_shell
{
    void FUN_004534f0(std::uintptr_t);
};
// @fnv 0x004534f0
void FUN_004534f0_shell::FUN_004534f0(std::uintptr_t)
{}

struct FUN_00453500_shell
{
    void FUN_00453500(bool set);
};

// @fnv 0x00453500
void FUN_00453500_shell::FUN_00453500(bool set)
{
    if (set)
    {
        *(unsigned int*)(this + 0x244) |= 0x10;
    }
    else
    {
        *(unsigned int*)(this + 0x244) &= ~0x10;
    }
}

struct BSAudio;

BSAudio* DAT_011f6d98;

// @fnv 0x00453a70
BSAudio* FUN_00453a70()
{
    return DAT_011f6d98;
}


// @fnv 0x00454440
void FUN_00454440(unsigned char value)
{
    DAT_011f9427 = value;
}

struct FNStub
{
    char const* GetFullName() const;
};

char const* FNStub::GetFullName() const
{
    return 0;
}

struct FUN_00454b50_shell
{
    char const* FUN_00454b50() const;
};

// @fnv 0x00454b50
char const* FUN_00454b50_shell::FUN_00454b50() const
{
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((FNStub*)((char*)this + 0xe0))))->FUN_00408da0()));
}

namespace fnv_00455600 {
struct AlchemyItem;
struct BGSAddonNode;
struct BGSDebris;
struct BGSExplosion;
struct BGSMessage;
struct BGSPerk;
struct BGSPrimitive;
struct BGSProjectile;
struct BGSVoiceType;
struct FormRecordHeader;
struct InventoryChanges;
struct InventoryStackRecord;
struct NiAVObject;
struct NiPoint3;
struct NiTriBasedGeom;
struct Script;
struct TESAmmoEffect;
struct TESBoundObject;
struct TESCaravanDeck;
struct TESCasino;
struct TESChallenge;
struct TESClass;
struct TESCombatStyle;
struct TESEffectShader;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESLandTexture;
struct TESLoadScreenType;
struct TESObject;
struct TESObjectANIO;
struct TESObjectCELL;
struct TESFormList;
struct TESObjectREFR;
struct TESQuest;
struct TESRace;
struct TESRecipe;
struct TESRecipeCategory;
struct TESRegionDataManager;
struct TESRegionList;
struct TESReputation;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct TESDataHandler
{
    static bool LoadForm(TESForm*, TESFile*);
    bool SaveForm(TESForm*, bool);
    char* GetFormName(unsigned char);
    void OutputFormList();
    void SetModelSizeOutputEnabled(bool);
    void OutputModelSizeList();
    void CheckTexturesRecurse(NiAVObject*, char*);
    static bool CheckDismemberSkinInstanceRecurse(NiAVObject*, char*);
    void PrintTextureInfo(void*, NiTriBasedGeom*, char*, char*, bool);
    void OutputTextureInfo();
    void CheckTexturePath(char*);
    bool AddFormToDataHandler(TESForm*);
    void ReleaseForm(TESForm*);
    unsigned char NotUniqueID(char*);
    void GetObjectCounts();
    void GetReferenceCounts();
    void GetRegions();
    void InitializeMagicSystem();
    void GetReferencesInArea(TESObjectCELL*, void*, float, void*, float, int*, long);
    void GetReferencesInArea(void*, float, void*, float, int*, long);
    void EnumReferencesCloseToRef(TESObjectREFR*, float, void*, float, int*, long);
    static bool ReferenceBaseSearchEnumFunc(TESObjectREFR*, intptr_t);
    bool FindTeleportPathBetweenSmallSpaces(TESForm*, TESForm*, void*);
    bool FindTeleportPathBetweenWorlds(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindTeleportPathFromSmallSpaceToWorld(TESForm*, TESWorldSpace*, void*, bool);
    TESObjectREFR* FindFirstReference(TESObject*);
    TESObjectREFR* FindFirstReference(char*);
    bool FindConnectedWorld(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindConnectedSmallSpace(TESForm*, TESForm*, void*, void*);
    TESWorldSpace* BuildPathNodeLocation(TESForm*, NiPoint3*, void*);
    TESObjectREFR* FindClosestReference(TESBoundObject*, void*, TESObjectCELL*);
    TESObjectREFR* FindClosestReference(char*, void*, TESObjectCELL*);
    TESObjectREFR* GetReference(char*);
    TESObjectREFR* GetReference(unsigned int);
    TESLandTexture* GetLandTexture(char*);
    TESLandTexture* GetLandTexture(unsigned int);
    TESRace* GetRace(char*);
    TESRace* GetRace(unsigned int);
    TESClass* GetClass(char*);
    TESClass* GetClass(unsigned int);
    Script* GetScript(char*);
    Script* GetScript(unsigned int);
    TESSound* GetSoundByEditorID(char*);
    TESSound* GetSoundByEditorID(unsigned int);
    TESGlobal* GetGlobal(char*);
    TESGlobal* GetGlobal(unsigned int);
    BGSVoiceType* GetVoiceType(unsigned int);
    TESFaction* GetFactionByFormID(char*);
    TESFaction* GetFactionByFormID(unsigned int);
    TESReputation* GetReputation(char*);
    TESReputation* GetReputation(unsigned int);
    TESRecipe* GetRecipe(char*);
    TESRecipe* GetRecipe(unsigned int);
    TESRecipeCategory* GetRecipeCategory(char*);
    TESRecipeCategory* GetRecipeCategory(unsigned int);
    TESCasino* GetCasino(char*);
    TESCasino* GetCasino(unsigned int);
    TESCaravanDeck* GetCaravanDeck(char*);
    TESCaravanDeck* GetCaravanDeck(unsigned int);
    TESTopic* GetAudioBackendData(int, int);
    TESTopic* GetAudioBackendData(char*);
    TESTopic* GetAudioBackendData(unsigned int);
    TESChallenge* GetChallenge(char*);
    TESAmmoEffect* GetAmmoEffect(char*);
    TESQuest* GetQuest(char*);
    TESCombatStyle* GetCombatStyle(char*);
    TESEffectShader* GetEffectShader(char*);
    BGSProjectile* GetProjectileData(char*);
    BGSExplosion* GetExplosion(char*);
    BGSDebris* GetDebris(char*);
    BGSPerk* GetPerk(char*);
    BGSMessage* GetMessage(char*);
    TESLoadScreenType* GetLoadScreenType(char*);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFormList* GetObjectList();
    void* GetFileList();
    void* GetPartDataList();
    void* GetPerks();
    void* GetDebrisList();
    void* GetExplosionList();
    void* GetProjectileList();
    void* GetRadiationStageList();
    void* GetDehydrationStageList();
    void* GetHungerStageList();
    void* GetSleepDeprevationStageList();
    void* GetEffectShaderList();
    void* GetWaterList();
    void* GetLoadScreenList();
    void* GetAnimObjectList();
    TESObjectANIO* GetAnimObject(TESIdleForm*, int);
    void* GetCombatStyleList();
    void* GetPackageList();
    void* GetWorldSpaceList();
    void* GetClimateList();
    void* GetImageSpaceList();
    void* GetImageSpaceModifierList();
    void* GetWeatherList();
    void* GetEnchantmentItemList();
    void* GetSpellItemList();
    void* GetLandTextList();
    void* GetCameraShotList();
    void* GetHeadPartList();
    void* GetHairList();
    void* GetEyesList();
    void* GetRaceList();
    void* GetZoneList();
    void* GetClassList();
    void* GetFactionList();
    void* GetReputationList();
    void* GetChallengeList();
    void* GetRecipeList();
    void* GetRecipeCategoryList();
    void* GetAmmoEffectList();
    void* GetCasinoList();
    void* GetCaravanDeckList();
    void* GetSoundList();
    void* GetAcousticSpaceList();
    void* GetRagdollList();
    void* GetGlobalList();
    void* GetVoiceTypeList();
    void* GetImpactDataList();
    void* GetImpactDataSetList();
    void* GetBadFormList();
    TESRegionList* GetRegionList();
    void* GetTopicList();
    void* GetTopicInfoList();
    void* GetNoteList();
    void* GetMenuIconList();
    void* GetListFormList();
    void* GetMessageList();
    void* GetLightingTemplateList();
    void* GetMusicTypeList();
    void* GetLoadScreenTypeList();
    void* GetMediaSetList();
    void* GetMediaLocationControllerList();
    void AddTopic(TESTopic*);
    void RemoveTopic(TESTopic*);
    void AddTopicInfo(TESTopicInfo*);
    void RemoveTopicInfo(TESTopicInfo*);
    void* GetScriptList();
    void SortScriptList();
    void* GetQuestList();
    void AddQuest(TESQuest*);
    void RemoveQuest(TESQuest*);
    unsigned int GetAddonNodeCount();
    BGSAddonNode* GetAddonNodeByIndex(unsigned int);
    void RegisterAddonNode(BGSAddonNode*);
    void RemoveAddonNode(BGSAddonNode*);
    TESObjectCELL* GetCellByNameAndGrid(char*);
    TESObjectCELL* GetCellByNameAndGrid(char*, int, int, TESWorldSpace*);
    unsigned int GetInteriorCellCount();
    TESObjectCELL* GetCellByInteriorIndex(unsigned int);
    void RefreshCellList();
    unsigned int GetCellCount();
    TESObjectCELL* GetCellByIndex(unsigned int);
    TESObjectCELL* GetCellByNumericID(unsigned int);
    TESObjectCELL* LookupCellByEditorID(char*);
    TESWorldSpace* GetWorldSpaceByEditorID(char*, int*, int*);
    TESObjectCELL* GetCellByWorldPosition(float, float, TESWorldSpace*, bool);
    TESObjectCELL* GetCellAtGridPosition(int, int, TESWorldSpace*, bool);
    TESWorldSpace* GetWorldSpaceForCell(TESObjectCELL*);
    void RemoveCell(TESObjectCELL*);
    void RemoveCell(int, int, TESWorldSpace*);
    void RemoveCell(char*);
    TESObjectREFR* CreateReferenceInLoadedArea(TESBoundObject*, void*, void*, bool, BGSPrimitive*, void*);
    TESObjectREFR* PlaceReferenceAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*,
                                            TESObjectREFR*, BGSPrimitive*, void*);
    TESObjectCELL* SelectCell(struct blob12, bool*, TESWorldSpace*);
    bool AssignToCell(TESObjectCELL*, TESObjectREFR*);
    bool PlaceInExterior(TESObjectREFR*, TESWorldSpace*);
    void RemoveDuplicateReferences();
    TESObjectREFR* CreateProjectileAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESObjectREFR* PlaceObjectAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESFile* LookupTESFile(unsigned int);
    TESFile* LookupTESFile(char*);
    bool RemoveListFile(TESFile*);
    static void FileCacheCompleteCallback(char*);
    char* GetActiveFileName();
    void SetActiveFile(TESFile*);
    TESFile* GetActiveFile();
    void RemoveIDFromDataHandler(unsigned int);
    unsigned int GetNextID();
    void AddCompiledFile(TESFile*);
    void ClearFileList();
    bool UpdateLoadingStatusCallback(char*);
    void BuildCompiledFileList();
    int CountCheckedFiles(int);
    unsigned int CountFiles();
    unsigned int CountCompiled();
    bool LoadPluginFiles(bool);
    bool ClearData();
    bool SaveActiveData(char*, bool);
    void CloseAllTES();
    bool LoadTESFile(TESFile*, bool);
    void ClearLoadedFormCount();
    unsigned int AddDownloadedContentToFileList();
    void RunAllPersistentRefScripts();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    bool FormGroupLoadsInGame(TESFile*, FormRecordHeader*);
    static TESForm* CreateFormForType(unsigned char);
    bool ResetOffsetData(TESFile*);
    void FixAllScriptIDs();
    void SetSaveLoadGameState(int);
    bool GetMasterSave();
    void SetMasterSave(bool);
    bool GetSaveLoadGame();
    void SetSaveLoadGame(bool);
    bool GetSaveLoad();
    void SetSaveLoad(bool);
    bool GetAutoSaving();
    void SetAutoSaving(bool);
    bool GetClearingData();
    void SetClearingData(bool);
    bool GetHasDesiredFiles();
    void SetHasDesiredFiles(bool);
    bool IsSavingLoading();
    void SetCheckingModels(bool);
    bool GetCheckingModels();
    void SetLoadingFiles(bool);
    bool GetLoadingFiles();
    bool GetGameSettingsLoaded();
    void MarkGameSettingsLoaded();
    void FlushSoundBuffers();
    void SetBarterContainer(TESObjectREFR*);
    void AddBarterItem(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearBarterContainer();
    InventoryChanges* GetBarterContainer();
    void CreateRecipeContainer(TESObjectREFR*);
    void RemoveItemRecipeContainer(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearRecipeContainer();
    InventoryChanges* GetRecipeContainer();
    TESRegionDataManager* GetRegionDataManager();
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetNextFormID();
    void SetNextFormID(unsigned int);
    bool FormIDExists(unsigned int);
    AlchemyItem* DoesPotionMatch(AlchemyItem*);
    void SetDontRemoveIDs(bool);
    bool GetDontRemoveIDs();
    void* QArrayInteriorCells();
    TESEffectShader* GetSpotterShader();
    TESEffectShader* GetItemDetectedShader();
    TESEffectShader* GetCateyeShader();
    void SetSpotterShader(TESEffectShader*);
    void SetItemDetectedShader(TESEffectShader*);
    void SetCateyeShader(TESEffectShader*);
    void ClearDLCFlags();
    int GetNumDLCInstalled();
    void DataError(int);
    bool IsFormIDRemapped(unsigned int);
    void AdvanceNextID();
    char* GetDLCFlags();
    bool IsDLCFlagSet(char);
    void SetDLCFlag(char, bool);
    int GetDLCIndex(char*);
    unsigned int LoadFilesInDirectory(char*, void*);
    void* __vecDelDtor(unsigned int);
    char m_cDLCFlagCount;
    char _pad_1[3];
    TESFormList* m_pBoundObjectList;
    char m_kPackages[8];
    char m_kWorldSpaceList[8];
    char m_kClimateList[8];
    char m_kImageSpaceList[8];
    char m_kImageSpaceModifierList[8];
    char m_kWeatherList[8];
    char m_kEnchantmentItemList[8];
    char m_kSpellList[8];
    char m_kHeadPartList[8];
    char m_kHairList[8];
    char m_kEyeList[8];
    char m_kRaceList[8];
    char m_kEncounterZoneList[8];
    char m_kLandTextureList[8];
    char m_kCameraShotList[8];
    char m_kClassList[8];
    char m_pVoiceType[8];
    char m_kReputationList[8];
    char m_kChallengeList[8];
    char m_kCraftingRecipeList[8];
    char m_kRecipeCategoryList[8];
    char m_kAmmoEffectList[8];
    char m_kCasinoList[8];
    char m_kCaravanDeckList[8];
    char m_kScriptList[8];
    char m_kSoundList[8];
    char m_kAcousticSpaceList[8];
    char m_kRagdollList[8];
    char m_kGlobalList[8];
    char m_kVoiceTypeList[8];
    char m_kImpactEffectList[8];
    char m_kImpactDataSetList[8];
    char m_kTopicList[8];
    char m_kTopicInfoList[8];
    char m_kQuestList[8];
    char m_kCombatStyleList[8];
    char m_kLoadScreenList[8];
    char m_kWaterFormList[8];
    char m_kEffectShaderList[8];
    char m_kProjectileList[8];
    char m_kExplosionList[8];
    char m_kRadiationStageList[8];
    char m_kDehydrationStageList[8];
    char m_kHungerStageList[8];
    char m_kSleepDeprivationStageList[8];
    char m_kDebrisList[8];
    char m_kPerkList[8];
    char m_kBodyPartDataList[8];
    char m_kNoteList[8];
    char m_kListFormList[8];
    char m_kMenuIconList[8];
    char m_kFourthDataList[8];
    char m_kMessageList[8];
    char m_kLightingTemplateList[8];
    char m_kMusicTypeList[8];
    char m_kLoadScreenTypeList[8];
    char m_kMediaSetList[8];
    char m_kMediaLocationControllerList[8];
    TESRegionList* m_pRegions;
    char m_kFirstArrayStorage[16];
    char m_kSecondArrayStorage[16];
    char m_kThirdArrayStorage[12];
    unsigned int m_uiFormCount;
    TESFile* m_pActiveFile;
    char m_kModInfoList[8];
    unsigned int m_iLoadedModCount;
    char m_ppLoadedMods[1020];
    bool m_bLoadingFiles;
    bool m_bGameSettingsLoaded;
    bool m_bMasterSave;
    bool m_bSaveLoadGame;
    bool m_bFirstStateField;
    bool m_bSecondStateField;
    bool m_bThirdStateField;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    unsigned char m_ucInternalStateByte;
    char _pad_623[1];
    TESRegionDataManager* m_pRegionDataManager;
    InventoryChanges* m_pFirstInventoryChanges;
    InventoryChanges* m_pSecondInventoryChanges;
    TESEffectShader* m_pFirstEffectShader;
    TESEffectShader* m_pSecondEffectShader;
    TESEffectShader* m_pThirdEffectShader;
};
struct FUN_00455600_shell : public TESDataHandler
{
    void* FUN_00455600();
};

// @fnv 0x00455600
void* FUN_00455600_shell::FUN_00455600()
{
    return reinterpret_cast<char*>(&this->m_kQuestList);
}
}  // namespace fnv_00455600

struct TESFaction_RankDataView
{
    bool FUN_00455620(void);
};

// @fnv 0x00455620
bool TESFaction_RankDataView::FUN_00455620()
{
    return (*((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField())) & 1) != 0;
}


// @fnv 0x00455680
void FUN_00455680()
{
    DAT_011c56e8 = 0;
}

struct FUN_004565f0_shell
{
    float m_f;
    float GetFloat();
};

// @fnv 0x004565f0
float FUN_004565f0_shell::GetFloat()
{
    return *(float*)((char*)this + 0xa0);
}


struct FUN_00458f20_shell
{
    const void* const* FUN_00458f20() const;
};

// @fnv 0x00458f20
const void* const* FUN_00458f20_shell::FUN_00458f20() const
{
    return &(*reinterpret_cast<const void *const *>(&::g_01202e00));
}


struct FUN_00458f70_shell
{
    void FUN_00458f70();
};

// @fnv 0x00458f70
void FUN_00458f70_shell::FUN_00458f70()
{
    *reinterpret_cast<const void**>(this) = &DAT_01017d24;
    reinterpret_cast<class ::FUN_00a5e930 *>((this))->FUN_00a5e930::~FUN_00a5e930();
}

namespace fnv_0045a520 {
struct StartMenu
{
};
struct ModelLoader
{
    void FUN_0045a5e0(char const*);
};
struct NP
{
    NP& operator=(void*);
};


struct FUN_0045a520_shell
{
    void LoadStartMenuModels();
};

// @fnv 0x0045a520
void FUN_0045a520_shell::LoadStartMenuModels()
{
    if (((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011d14c4))))->GetMenuTitle()))[0])
        (*reinterpret_cast<::fnv_0045a520::ModelLoader * *>(&::g_modelLoader))->FUN_0045a5e0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011d14c4))))->GetMenuTitle())));

    if (((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011cebb0))))->GetMenuTitle()))[0])
        (*reinterpret_cast<::fnv_0045a520::ModelLoader * *>(&::g_modelLoader))->FUN_0045a5e0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011cebb0))))->GetMenuTitle())));

    if (((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011d12c0))))->GetMenuTitle()))[0])
        (*reinterpret_cast<::fnv_0045a520::ModelLoader * *>(&::g_modelLoader))->FUN_0045a5e0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011d12c0))))->GetMenuTitle())));

    if (((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011d0ce4))))->GetMenuTitle()))[0])
        (*reinterpret_cast<::fnv_0045a520::ModelLoader * *>(&::g_modelLoader))->FUN_0045a5e0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a520::StartMenu *>(&::g_011d0ce4))))->GetMenuTitle())));

    ((NP*)((char*)this + 0xa8))->operator=(0);
}
}  // namespace fnv_0045a520

struct AnimIdle;
struct Animation;
struct AttachDistant3DTask;
struct BSFile;
struct BSFileEntry;
struct BackgroundCloneThread;
struct BipedAnim;
struct EffectSetting;
struct KFModel;
struct LoadedFile;
struct MagicItem;
struct Model;
struct NiAVObject;
struct NiControllerSequence;
struct NiNode;
struct QueuedFile;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESBoundObject;
struct TESModel;
struct TESNPC;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESObjectTREE;
struct FileEntryList;
struct FileEntryListCollection;
struct ModelLoadData;
struct ModelLoader
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};
struct FUN_0045a5e0_shell : public ModelLoader
{
    void FUN_0045a5e0(char*);
};

// @fnv 0x0045a5e0
void FUN_0045a5e0_shell::FUN_0045a5e0(char* apModelFileName)
{
    reinterpret_cast<::FUN_00445300_shell *>(this)->FUN_00445300(apModelFileName, true, 1);
}

void __cdecl CreateCSDFadeNode(void);
void __cdecl CreateSpdFadeNode(void);
void __cdecl FUN_004f92e0(void);
void __cdecl FUN_00649e40(void);
void __cdecl FUN_0065c570(void);
void __cdecl FUN_00662760(void);

// @fnv 0x0045b020
void __cdecl FUN_0045b020(void)
{
    FUN_00649e40();
    FUN_0065c570();
    FUN_00662760();
    FUN_004f92e0();
    CreateSpdFadeNode();
    CreateCSDFadeNode();
}

struct FUN_0045c650_shell
{
    void* FUN_0045c650();
};

// @fnv 0x0045c650
void* FUN_0045c650_shell::FUN_0045c650()
{
    return reinterpret_cast<char*>(this) + 0xD0;
}

// @fnv 0x0045c670
std::uintptr_t FUN_0045c670()
{
    return *reinterpret_cast<std::uintptr_t *>(&::g_011deb7c);
}

struct TESObjectREFR;


// Calls FUN_00578060 on arg when flag is true, otherwise calls FUN_00578170 on arg.
// @fnv 0x0045c680
void FUN_0045c680(TESObjectREFR* apRefr, bool flag)
{
    if (flag)
    {
        ::FUN_00578060((::NodeView *)(apRefr));
    }
    else
    {
        ::fnv_00578170::FUN_00578170((::NiNode *)(apRefr));
    }
}


struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    static const ::NiPoint3 ZERO;
};

struct NiCamera
{
    float x;
    float y;
    float z;
    float w;
    int ClassifyPoint(const NiPoint3* other);
};

// Computes the dot product of this camera's xyz with other minus w and returns 2 if negative, 1 if positive, else 0.
// @fnv 0x0049da80
int NiCamera::ClassifyPoint(const NiPoint3* apPoint)
{
    float result = this->x * apPoint->x + this->y * apPoint->y + this->z * apPoint->z - this->w;
    if (result < 0.0)
        return 2;
    else if (result > 0.0)
        return 1;
    else
        return 0;
}

struct FUN_00451cd0_shell
{
    unsigned char FUN_00451cd0();
};

// @fnv 0x00451cd0
unsigned char FUN_00451cd0_shell::FUN_00451cd0()
{
    return *(unsigned char*)((char*)this + 0x54);
}

namespace fnv_00452490 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct GridCellData;
struct GridCell;
struct GridCellArray;
struct GridDistantArray;
struct GridLand;
struct NavMeshInfoMap;
struct NiAVObject;
struct NiCamera;
struct RgbaColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiGeometry;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiTexture;
struct QueuedReference;
struct Sky;
struct TESActorBase;
struct TESForm;
struct TESLandTexture;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESFormList;
struct TESObjectREFR;
struct TESRegion;
struct WaterZoneManager;
struct TESWorldSpace;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};
struct TES
{
    virtual bool SetDateTimeText(void*, struct blob12, TESWorldSpace*);
    void InitVars();
    NiNode* GetRoot();
    NiNode* GetTempNodeManager();
    NiNode* GetLandRoot();
    NiNode* GetLODWaterRoot();
    GridCell* GetGridCell(int, int);
    NiDirectionalLight* GetLight();
    NiFogProperty* GetFog();
    TESObjectCELL* GetDetailedActorPathHandler();
    GridCellArray* GetGridCellA();
    void UpdateWater(NiAVObject*, float);
    void InitializeWater();
    void FreeWater();
    bool LoadAndBufferExterior(int, int, TESWorldSpace*, unsigned int);
    bool LoadAndBufferInterior(TESObjectCELL*);
    void InitGridCells(void*, bool);
    int FindCellAtPosition(void*, bool);
    void ResizeGrid(unsigned int);
    void SetTESActive(bool);
    void SetLODFadeDistance(float);
    void UpdateGrid();
    void InitializeTESManager(bool);
    void SyncCellActorHavok();
    void UpdateDeferredCellAnimationTransforms();
    void ProcessCellQueues(bool, bool);
    bool IsCellFreePending();
    bool HasCellToFree();
    void ClearCellsForWorld(TESWorldSpace*);
    bool IsCoordInLoadedArea(void*);
    bool IsCellBuffered(TESObjectCELL*, bool);
    void GetLoadedAreaBounds(tagRECT*, float);
    TESObjectCELL* LineIntersectsLoadedCells(void*, void*, NiPoint3*, float);
    void GetCellStrings(NiNode*);
    void GetCollideStrings(NiNode*);
    TESObjectCELL* IsCellInterior();
    void SetInterior(TESObjectCELL*);
    void ClearWorldSpace();
    TESWorldSpace* GetParentWorldSpace();
    void AssignWorldSpace(TESWorldSpace*);
    void GetSaveGridXY(tagPOINT*);
    void SetSaveGridXY(void*);
    void SetCellCallback(TESObjectCELL*, void*);
    void LeaveInterior(NiPoint3*);
    GridCell* FindFirstGridCellWithWater();
    TESObjectCELL* FindCellByGridCoordinates(int, int);
    GridCell* GetGridCellForCell(TESObjectCELL*);
    int GetCellPriority(TESObjectCELL*, NiPoint3*);
    TESObjectCELL* GetCellContainingPoint(struct blob12);
    void RunScripts();
    void RunAnimations();
    void UpdateRefSounds();
    void SetAtmosphere(TESObjectCELL*);
    void SetTestAllCellsCallback(int*);
    void SetTestAllCellsCallbackData(void*);
    void SetTestAllCellsRegionFilter(TESRegion*);
    void TestAllCells(int);
    void TestSubmergedObjects();
    bool CellTestRunning();
    bool CellTestRunning2();
    bool SumbergedObjectTestRunning();
    void SetCellTestRunning(bool);
    void SetCellTestRunning2(bool);
    void RunCellTest(unsigned int);
    void EmptyStructPlaceholder(TESObjectCELL*, unsigned int, unsigned int);
    void BuildCountString(NiNode*);
    int GetFaceCount(NiNode*, bool);
    int InitializeTESResources(NiNode*);
    void CreateTextureImage(char*, void*, bool, bool);
    bool LoadCanopyShadowTexture(char*, unsigned int);
    void WriteTextureImage(NiTexture*, char*, int);
    NiAVObject* CreateDeepCopySameTextures(NiAVObject*, GridCellData*);
    void InitializeTESWorld(int, int, int, int);
    void InitializeTESWorld(TESObjectCELL*);
    void CancelExteriorCellLoads();
    void* GetLastLoadedExteriors();
    void* GetBedChairList();
    void ClearBedChairList();
    void* GetDeadCountList();
    void ClearDeadCountList();
    short GetDeadCount(TESActorBase*);
    void AddDeadCount(TESActorBase*, short);
    void SetShowCollisionBounds(bool);
    bool GetShowCollisionBounds();
    void ShowCollisionBounds(bool, bool);
    void ShowCollisionBox(NiNode*);
    void ToggleCollisionGeometry();
    void TogglePrimitives();
    void SaveWorld(char*);
    void SetShowLandBorders(bool);
    bool GetShowLandBorders();
    void SetShowWater(bool);
    void SetLandRenderingOptions(int, bool, bool);
    bool PickLandscapeOnly(NiPick*, void*, void*);
    bool PickWaterDistance(NiPick*, void*, void*, float);
    bool PickWorldDistance(NiPick*, void*, void*, float, char);
    bool GetLandHeightAtPosition(void*, float*);
    bool GetSurfaceNormal(void*, NiPoint3*, NiPoint3*);
    bool GetSurfaceColor(void*, RgbaColor*);
    NiGeometry* GetSurfaceGeometry(void*);
    TESLandTexture* GetLandTexture(void*);
    int GetLandMaterialType(void*);
    float GetLandFrictionValue(void*);
    float GetLandRestitutionValue(void*);
    bool LineVsLand(void*, void*, NiPoint3*, float);
    bool CanAttach3D(TESObjectREFR*);
    void GetCurrentWorldspace(TESObjectREFR*);
    void AttachModel(TESObjectREFR*, TESObjectCELL*, QueuedReference*, bool);
    void DetachModel(TESObjectREFR*);
    void UpdateGridLights();
    float UpdateTESState(void*, TESObjectCELL*);
    WaterZoneManager* GetWaterSystem();
    Sky* GetSky();
    void HideSky();
    void ShowSky();
    void UpdateSky(struct blob12);
    void SetSkyMode(int);
    bool RefreshWorldState(bool, TESForm*, bool);
    void ShowLoadingAreaMessage(char*);
    GridDistantArray* GetGridDistantArray();
    void SetUpdateGridString();
    bool GetUpdateGridString();
    void UpdateExteriorCellBuffer();
    void MoveToEndOfExteriorBuffer(TESObjectCELL*);
    void RemoveCellFromExteriorBuffer(TESObjectCELL*, bool);
    void RemoveCellFromInteriorBuffer(TESObjectCELL*);
    void CreateFurnitureList();
    GridLand* FindGridLandForLand(TESObjectLAND*);
    void ToggleLoadFade();
    static bool ProcessVisibleBounds(NiNode*, bool);
    NiAVObject* Pick(BhkPickData*, bool);
    NiAVObject* Pick(BhkPickData*);
    NiAVObject* PickNI(BhkPickData*);
    static bool QCollisionDisableFlag();
    static void SetCollisionDisableFlag(bool);
    void ToggleCollision();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void FinishLoad();
    void ClearPersistentRef3DInLoadedCells();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
    void Revert(BGSLoadGameBuffer*);
    int GetCurrentGridX();
    int GetCurrentGridY();
    void SetCurrentGridX(int);
    void SetCurrentGridY(int);
    unsigned int GetExteriorBufferSize();
    TESObjectCELL* GetExteriorBufferCellByIndex(unsigned int);
    unsigned int GetInteriorBufferSize();
    TESObjectCELL* GetInteriorBufferCellByIndex(unsigned int);
    void InitializeTESData();
    void UpdateFadeNodesForAttachedCells();
    void LoadTESWorldData();
    void UnloadAddonNodes();
    void ProcessTESObjects();
    void UnloadDefaultModels();
    void PreloadPlaceableWaterNoiseTextures();
    void UnloadPlaceableWaterNoiseTextures();
    void InitializeTESCells();
    void UnPreloadForms();
    void ClearCachedForms();
    void AddTemporaryParticleObjectToCache(NiAVObject*);
    unsigned int GetUnusedCachedParticleObject(NiAVObject*, void*);
    void PurgeUnusedParticleObjects();
    static bool GetSelectivePurgeUnusedOnFastTravel();
    void SetAllowUnusedPurge(bool);
    bool GetAllowUnusedPurge();
    NavMeshInfoMap* GetActiveCell();
    void IsCellAttached(NavMeshInfoMap*);
    void* GetActiveImageSpaceModifierList();
    static void InitializeMultiBounds();
    static void ClearMultiBoundResults();
    void UpdateMultiBoundResults(NiCamera*);
    void SetMultiBoundVisibility(bool, bool);
    void AddMultiBoundsToDebugLines(NiCamera*);
    static void RangedNodeVisibilityChangedCB(NiNode*, bool);
    static unsigned int RecursiveGetVertexCount(NiNode*, bool);
    static int GetModelResourceType(TESObject*);
    static void SetFadeOutObjectMult(float);
    static void SetFadeOutItemMult(float);
    static void SetFadeOutActorMult(float);
    void ResetFadeOutMultipliers();
    void InitializeTES();
    void IncrementPlaceableWaterCount();
    void DecrementPlaceableWaterCount();
    unsigned int QPlaceableWaterCount();
    static void InitFadeOutMultipliers();
    void UpdateLoadedCellsAtPosition(bool, NiPoint3*);
    void ProcessTESUpdate(void*, bool);
    bool IsCellBuffering();
    void ClearCellBuffers();
    void UpdateCellBuffers();
    bool IsBuffered(TESObjectCELL*);
    bool IsInteriorBuffered(TESObjectCELL*);
    void AddToBuffer(TESObjectCELL*);
    void AddCellToInteriorBuffer(TESObjectCELL*);
    unsigned int GetInteriorBufferCount(bool);
    bool IsExteriorBuffered(TESObjectCELL*);
    void AddCellToExteriorBuffer(TESObjectCELL*);
    unsigned int GetExteriorBufferCount(bool, TESWorldSpace*);
    void AddCollideObject(TESFormList*);
    void HideUnneededLandPasses();
    void HideFarLandNormalMaps();
    void SetHideLandBlendPassForGridCell(int, int, bool);
    void SetHideLandNormalMapForGridCell(int, int, bool);
    void* __vecDelDtor(unsigned int);
    GridDistantArray* m_pGridDistantArray;
    GridCellArray* m_pGridCells;
    NiNode* m_pLandRootNode;
    NiNode* m_pWaterRootNode;
    NiNode* m_pDistantLandRootNode;
    NiNode* m_pObjectRootNode;
    NiDirectionalLight* m_pDirectionalLight;
    NiFogProperty* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    TESObjectCELL* m_pReferenceCell;
    TESObjectCELL** m_ppCellBufferA;
    TESObjectCELL** m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    int* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    TESRegion* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    char _pad_61[3];
    WaterZoneManager* m_pCurrentClimate;
    Sky* pWeatherSky;
    char m_kImageSpaceModifierInstances[8];
    unsigned int m_uiNextImageSpaceModifierId;
    unsigned int m_uiImageSpaceModifierCount;
    bool m_bImageSpaceStateFlag;
    bool m_bSkyStateFlag;
    char _pad_7e[2];
    float m_fFirstWorldspaceValue;
    float m_fSecondWorldspaceValue;
    TESWorldSpace* m_pContainingWorldspace;
    char m_kWorldspaceCellList[8];
    char m_kTemporaryReferences[8];
    char m_kLeveledActorEntries[8];
    char m_spWorldspaceQueuedFile[4];
    char m_pSourceTexture[4];
    char m_spQueuedFile[4];
    void* m_pParticleObjectCache;
    bool m_bFirstTESStateFlag;
    bool m_bSecondTESStateFlag;
    char _pad_b6[2];
    unsigned int m_uiNavMeshStateValue;
    NavMeshInfoMap* m_pNavMeshInfoMap;
    char m_spLoadedAreaBound[4];
};
struct FUN_00452490_shell : public TES
{
    void FUN_00452490(bool);
};

struct Renderer
{
};
struct FUN_004524f0_t
{
};

// @fnv 0x00452490
void FUN_00452490_shell::FUN_00452490(bool abWaitForCompletion)
{
    if (!::Renderer::CanRender())
        return;
    ::LockSpinLock();
    ::Entry664::FUN_00664cd0(1);
    if (((bool)(reinterpret_cast<::FUN_004524f0_Class *>((reinterpret_cast<FUN_004524f0_t*>(this)))->GetByteB5())) || abWaitForCompletion)
    {
        ::FUN_00a61cd0();
    }
    ::Entry664::FUN_00664cd0(1);
    ::FUN_00452530();
}
}  // namespace fnv_00452490

class BGSEncounterZone;
class NiAVObject;
class TESRegionList;
class TESWorldSpace;
struct TESObjectCELL
{
public:
    bool IsCellInterior() const;
public:
    int GetCellStandValue();
public:
    ::NiAVObject *GetCellChildAt(int);
public:
    int GetCellGridX();
public:
    int GetCellGridY();
public:
    ::BGSEncounterZone *FindEncounterZone() const;
public:
    ::TESRegionList *GetRegionList(bool);
public:
    ::TESWorldSpace *GetParentWorldSpace();
public:
    void FUN_005571a0(bool);
};
struct TESObjectCELL_AddToInteriorBuffer
{
    void AddCellToInteriorBuffer(TESObjectCELL* cell);
};
struct TESObjectCELL_AddToExteriorBuffer
{
    void AddCellToExteriorBuffer(TESObjectCELL* cell);
};
struct FUN_00454b90_shell
{
    void AddCellToBuffer(TESObjectCELL* cell);
};
struct FUN_00458f30_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};


// Calls FUN_00458f70, then deletes this with size 0xb0 when bit 0 of flags is set, and returns this.
// @fnv 0x00458f30
void* FUN_00458f30_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00458f70_shell *>((this))->FUN_00458f70();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xb0);
    return this;
}

struct FUN_00459840_shell
{
    void FUN_00459840(uintptr_t a);
};

struct FUN_0045a730_shell
{
    char* FUN_0045a730();
};
// @fnv 0x0045a730
char* FUN_0045a730_shell::FUN_0045a730()
{
    return reinterpret_cast<char*>(this) + 0x130;
}


struct FUN_0045ae20_shell
{
    void FUN_0045ae50();
    void* FUN_0045ae20(unsigned int flags);
};

struct FUN_00451250_shell
{
    unsigned char bFlags;
    void SetFlag2(bool value);
};

// @fnv 0x00451250
void FUN_00451250_shell::SetFlag2(bool abSet)
{
    abSet ? ((unsigned char*)this)[0x24] |= 2 : ((unsigned char*)this)[0x24] &= ~2;
}

namespace fnv_00451530 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct GridCellData;
struct GridCell;
struct GridCellArray;
struct GridDistantArray;
struct GridLand;
struct NavMeshInfoMap;
struct NiAVObject;
struct NiCamera;
struct RgbaColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiGeometry;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiTexture;
struct QueuedReference;
struct Sky;
struct TESActorBase;
struct TESForm;
struct TESLandTexture;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESFormList;
struct TESObjectREFR;
struct TESRegion;
struct WaterZoneManager;
struct TESWorldSpace;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};
struct TES
{
    virtual bool SetDateTimeText(void*, struct blob12, TESWorldSpace*);
    void InitVars();
    NiNode* GetRoot();
    NiNode* GetTempNodeManager();
    NiNode* GetLandRoot();
    NiNode* GetLODWaterRoot();
    GridCell* GetGridCell(int, int);
    NiDirectionalLight* GetLight();
    NiFogProperty* GetFog();
    TESObjectCELL* GetDetailedActorPathHandler();
    GridCellArray* GetGridCellA();
    void UpdateWater(NiAVObject*, float);
    void InitializeWater();
    void FreeWater();
    bool LoadAndBufferExterior(int, int, TESWorldSpace*, unsigned int);
    bool LoadAndBufferInterior(TESObjectCELL*);
    void InitGridCells(void*, bool);
    int FindCellAtPosition(void*, bool);
    void ResizeGrid(unsigned int);
    void SetTESActive(bool);
    void SetLODFadeDistance(float);
    void UpdateGrid();
    void InitializeTESManager(bool);
    void SyncCellActorHavok();
    void UpdateDeferredCellAnimationTransforms();
    void ProcessCellQueues(bool, bool);
    bool IsCellFreePending();
    bool HasCellToFree();
    void ClearCellsForWorld(TESWorldSpace*);
    bool IsCoordInLoadedArea(void*);
    bool IsCellBuffered(TESObjectCELL*, bool);
    void GetLoadedAreaBounds(tagRECT*, float);
    TESObjectCELL* LineIntersectsLoadedCells(void*, void*, NiPoint3*, float);
    void GetCellStrings(NiNode*);
    void GetCollideStrings(NiNode*);
    TESObjectCELL* IsCellInterior();
    void SetInterior(TESObjectCELL*);
    void ClearWorldSpace();
    TESWorldSpace* GetParentWorldSpace();
    void AssignWorldSpace(TESWorldSpace*);
    void GetSaveGridXY(tagPOINT*);
    void SetSaveGridXY(void*);
    void SetCellCallback(TESObjectCELL*, void*);
    void LeaveInterior(NiPoint3*);
    GridCell* FindFirstGridCellWithWater();
    TESObjectCELL* FindCellByGridCoordinates(int, int);
    GridCell* GetGridCellForCell(TESObjectCELL*);
    int GetCellPriority(TESObjectCELL*, NiPoint3*);
    TESObjectCELL* GetCellContainingPoint(struct blob12);
    void RunScripts();
    void RunAnimations();
    void UpdateRefSounds();
    void SetAtmosphere(TESObjectCELL*);
    void SetTestAllCellsCallback(int*);
    void SetTestAllCellsCallbackData(void*);
    void SetTestAllCellsRegionFilter(TESRegion*);
    void TestAllCells(int);
    void TestSubmergedObjects();
    bool CellTestRunning();
    bool CellTestRunning2();
    bool SumbergedObjectTestRunning();
    void SetCellTestRunning(bool);
    void SetCellTestRunning2(bool);
    void RunCellTest(unsigned int);
    void EmptyStructPlaceholder(TESObjectCELL*, unsigned int, unsigned int);
    void BuildCountString(NiNode*);
    int GetFaceCount(NiNode*, bool);
    int InitializeTESResources(NiNode*);
    void CreateTextureImage(char*, void*, bool, bool);
    bool LoadCanopyShadowTexture(char*, unsigned int);
    void WriteTextureImage(NiTexture*, char*, int);
    NiAVObject* CreateDeepCopySameTextures(NiAVObject*, GridCellData*);
    void InitializeTESWorld(int, int, int, int);
    void InitializeTESWorld(TESObjectCELL*);
    void CancelExteriorCellLoads();
    void* GetLastLoadedExteriors();
    void* GetBedChairList();
    void ClearBedChairList();
    void* GetDeadCountList();
    void ClearDeadCountList();
    short GetDeadCount(TESActorBase*);
    void AddDeadCount(TESActorBase*, short);
    void SetShowCollisionBounds(bool);
    bool GetShowCollisionBounds();
    void ShowCollisionBounds(bool, bool);
    void ShowCollisionBox(NiNode*);
    void ToggleCollisionGeometry();
    void TogglePrimitives();
    void SaveWorld(char*);
    void SetShowLandBorders(bool);
    bool GetShowLandBorders();
    void SetShowWater(bool);
    void SetLandRenderingOptions(int, bool, bool);
    bool PickLandscapeOnly(NiPick*, void*, void*);
    bool PickWaterDistance(NiPick*, void*, void*, float);
    bool PickWorldDistance(NiPick*, void*, void*, float, char);
    bool GetLandHeightAtPosition(void*, float*);
    bool GetSurfaceNormal(void*, NiPoint3*, NiPoint3*);
    bool GetSurfaceColor(void*, RgbaColor*);
    NiGeometry* GetSurfaceGeometry(void*);
    TESLandTexture* GetLandTexture(void*);
    int GetLandMaterialType(void*);
    float GetLandFrictionValue(void*);
    float GetLandRestitutionValue(void*);
    bool LineVsLand(void*, void*, NiPoint3*, float);
    bool CanAttach3D(TESObjectREFR*);
    void GetCurrentWorldspace(TESObjectREFR*);
    void AttachModel(TESObjectREFR*, TESObjectCELL*, QueuedReference*, bool);
    void DetachModel(TESObjectREFR*);
    void UpdateGridLights();
    float UpdateTESState(void*, TESObjectCELL*);
    WaterZoneManager* GetWaterSystem();
    Sky* GetSky();
    void HideSky();
    void ShowSky();
    void UpdateSky(struct blob12);
    void SetSkyMode(int);
    bool RefreshWorldState(bool, TESForm*, bool);
    void ShowLoadingAreaMessage(char*);
    GridDistantArray* GetGridDistantArray();
    void SetUpdateGridString();
    bool GetUpdateGridString();
    void UpdateExteriorCellBuffer();
    void MoveToEndOfExteriorBuffer(TESObjectCELL*);
    void RemoveCellFromExteriorBuffer(TESObjectCELL*, bool);
    void RemoveCellFromInteriorBuffer(TESObjectCELL*);
    void CreateFurnitureList();
    GridLand* FindGridLandForLand(TESObjectLAND*);
    void ToggleLoadFade();
    static bool ProcessVisibleBounds(NiNode*, bool);
    NiAVObject* Pick(BhkPickData*, bool);
    NiAVObject* Pick(BhkPickData*);
    NiAVObject* PickNI(BhkPickData*);
    static bool QCollisionDisableFlag();
    static void SetCollisionDisableFlag(bool);
    void ToggleCollision();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void FinishLoad();
    void ClearPersistentRef3DInLoadedCells();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
    void Revert(BGSLoadGameBuffer*);
    int GetCurrentGridX();
    int GetCurrentGridY();
    void SetCurrentGridX(int);
    void SetCurrentGridY(int);
    unsigned int GetExteriorBufferSize();
    TESObjectCELL* GetExteriorBufferCellByIndex(unsigned int);
    unsigned int GetInteriorBufferSize();
    TESObjectCELL* GetInteriorBufferCellByIndex(unsigned int);
    void InitializeTESData();
    void UpdateFadeNodesForAttachedCells();
    void LoadTESWorldData();
    void UnloadAddonNodes();
    void ProcessTESObjects();
    void UnloadDefaultModels();
    void PreloadPlaceableWaterNoiseTextures();
    void UnloadPlaceableWaterNoiseTextures();
    void InitializeTESCells();
    void UnPreloadForms();
    void ClearCachedForms();
    void AddTemporaryParticleObjectToCache(NiAVObject*);
    unsigned int GetUnusedCachedParticleObject(NiAVObject*, void*);
    void PurgeUnusedParticleObjects();
    static bool GetSelectivePurgeUnusedOnFastTravel();
    void SetAllowUnusedPurge(bool);
    bool GetAllowUnusedPurge();
    NavMeshInfoMap* GetActiveCell();
    void IsCellAttached(NavMeshInfoMap*);
    void* GetActiveImageSpaceModifierList();
    static void InitializeMultiBounds();
    static void ClearMultiBoundResults();
    void UpdateMultiBoundResults(NiCamera*);
    void SetMultiBoundVisibility(bool, bool);
    void AddMultiBoundsToDebugLines(NiCamera*);
    static void RangedNodeVisibilityChangedCB(NiNode*, bool);
    static unsigned int RecursiveGetVertexCount(NiNode*, bool);
    static int GetModelResourceType(TESObject*);
    static void SetFadeOutObjectMult(float);
    static void SetFadeOutItemMult(float);
    static void SetFadeOutActorMult(float);
    void ResetFadeOutMultipliers();
    void InitializeTES();
    void IncrementPlaceableWaterCount();
    void DecrementPlaceableWaterCount();
    unsigned int QPlaceableWaterCount();
    static void InitFadeOutMultipliers();
    void UpdateLoadedCellsAtPosition(bool, NiPoint3*);
    void ProcessTESUpdate(void*, bool);
    bool IsCellBuffering();
    void ClearCellBuffers();
    void UpdateCellBuffers();
    bool IsBuffered(TESObjectCELL*);
    bool IsInteriorBuffered(TESObjectCELL*);
    void AddToBuffer(TESObjectCELL*);
    void AddCellToInteriorBuffer(TESObjectCELL*);
    unsigned int GetInteriorBufferCount(bool);
    bool IsExteriorBuffered(TESObjectCELL*);
    void AddCellToExteriorBuffer(TESObjectCELL*);
    unsigned int GetExteriorBufferCount(bool, TESWorldSpace*);
    void AddCollideObject(TESFormList*);
    void HideUnneededLandPasses();
    void HideFarLandNormalMaps();
    void SetHideLandBlendPassForGridCell(int, int, bool);
    void SetHideLandNormalMapForGridCell(int, int, bool);
    void* __vecDelDtor(unsigned int);
    GridDistantArray* m_pGridDistantArray;
    GridCellArray* m_pGridCells;
    NiNode* m_pLandRootNode;
    NiNode* m_pWaterRootNode;
    NiNode* m_pDistantLandRootNode;
    NiNode* m_pObjectRootNode;
    NiDirectionalLight* m_pDirectionalLight;
    NiFogProperty* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    TESObjectCELL* m_pReferenceCell;
    TESObjectCELL** m_ppCellBufferA;
    TESObjectCELL** m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    int* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    TESRegion* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    char _pad_61[3];
    WaterZoneManager* m_pCurrentClimate;
    Sky* pWeatherSky;
    char m_kImageSpaceModifierInstances[8];
    unsigned int m_uiNextImageSpaceModifierId;
    unsigned int m_uiImageSpaceModifierCount;
    bool m_bImageSpaceStateFlag;
    bool m_bSkyStateFlag;
    char _pad_7e[2];
    float m_fFirstWorldspaceValue;
    float m_fSecondWorldspaceValue;
    TESWorldSpace* m_pContainingWorldspace;
    char m_kWorldspaceCellList[8];
    char m_kTemporaryReferences[8];
    char m_kLeveledActorEntries[8];
    char m_spWorldspaceQueuedFile[4];
    char m_pSourceTexture[4];
    char m_spQueuedFile[4];
    void* m_pParticleObjectCache;
    bool m_bFirstTESStateFlag;
    bool m_bSecondTESStateFlag;
    char _pad_b6[2];
    unsigned int m_uiNavMeshStateValue;
    NavMeshInfoMap* m_pNavMeshInfoMap;
    char m_spLoadedAreaBound[4];
};
struct FUN_00451530_shell : public TES
{
    bool FUN_00451530();
};

// @fnv 0x00451530
bool FUN_00451530_shell::FUN_00451530()
{
    return m_bSecondCellGridFlag || m_bThirdCellGridFlag;
}
}  // namespace fnv_00451530

struct FUN_00401280_shell
{
};
struct FUN_00451cb0_shell
{
    void FUN_00451cb0();
};
// @fnv 0x00451cb0
void FUN_00451cb0_shell::FUN_00451cb0()
{
    reinterpret_cast<::FUN_00401280_Class *>((((FUN_00401280_shell*)this)))->FUN_00401280();
}

struct RefH
{
};
struct FNVHelper
{
    unsigned char _FNV_GetFormType();
};
class NiPoint3;
struct GridCell;
struct TES
{
    bool IsRefUsable(TESObjectREFR* apRef);
public:
    int FindCellAtPosition(const ::NiPoint3 *, bool);
public:
    ::GridCell *FUN_00457050(int, int);
};

struct FUN_00452370_shell
{
    bool FUN_00452370() const;
};

// @fnv 0x00452370
bool FUN_00452370_shell::FUN_00452370() const
{
    return (*(const unsigned int*)((const char*)this + 8) & (std::uintptr_t)&DAT_01000000) ? true : false;
}

namespace fnv_00453940 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct GridCellData;
struct GridCell;
struct GridCellArray;
struct GridDistantArray;
struct GridLand;
struct NavMeshInfoMap;
struct NiAVObject;
struct NiCamera;
struct RgbaColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiGeometry;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiTexture;
struct QueuedReference;
struct Sky;
struct TESActorBase;
struct TESForm;
struct TESLandTexture;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESFormList;
struct TESObjectREFR;
struct TESRegion;
struct WaterZoneManager;
struct TESWorldSpace;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};
struct TES
{
    virtual bool SetDateTimeText(void*, struct blob12, TESWorldSpace*);
    void InitVars();
    NiNode* GetRoot();
    NiNode* GetTempNodeManager();
    NiNode* GetLandRoot();
    NiNode* GetLODWaterRoot();
    GridCell* GetGridCell(int, int);
    NiDirectionalLight* GetLight();
    NiFogProperty* GetFog();
    TESObjectCELL* GetDetailedActorPathHandler();
    GridCellArray* GetGridCellA();
    void UpdateWater(NiAVObject*, float);
    void InitializeWater();
    void FreeWater();
    bool LoadAndBufferExterior(int, int, TESWorldSpace*, unsigned int);
    bool LoadAndBufferInterior(TESObjectCELL*);
    void InitGridCells(void*, bool);
    int FindCellAtPosition(void*, bool);
    void ResizeGrid(unsigned int);
    void SetTESActive(bool);
    void SetLODFadeDistance(float);
    void UpdateGrid();
    void InitializeTESManager(bool);
    void SyncCellActorHavok();
    void UpdateDeferredCellAnimationTransforms();
    void ProcessCellQueues(bool, bool);
    bool IsCellFreePending();
    bool HasCellToFree();
    void ClearCellsForWorld(TESWorldSpace*);
    bool IsCoordInLoadedArea(void*);
    bool IsCellBuffered(TESObjectCELL*, bool);
    void GetLoadedAreaBounds(tagRECT*, float);
    TESObjectCELL* LineIntersectsLoadedCells(void*, void*, NiPoint3*, float);
    void GetCellStrings(NiNode*);
    void GetCollideStrings(NiNode*);
    TESObjectCELL* IsCellInterior();
    void SetInterior(TESObjectCELL*);
    void ClearWorldSpace();
    TESWorldSpace* GetParentWorldSpace();
    void AssignWorldSpace(TESWorldSpace*);
    void GetSaveGridXY(tagPOINT*);
    void SetSaveGridXY(void*);
    void SetCellCallback(TESObjectCELL*, void*);
    void LeaveInterior(NiPoint3*);
    GridCell* FindFirstGridCellWithWater();
    TESObjectCELL* FindCellByGridCoordinates(int, int);
    GridCell* GetGridCellForCell(TESObjectCELL*);
    int GetCellPriority(TESObjectCELL*, NiPoint3*);
    TESObjectCELL* GetCellContainingPoint(struct blob12);
    void RunScripts();
    void RunAnimations();
    void UpdateRefSounds();
    void SetAtmosphere(TESObjectCELL*);
    void SetTestAllCellsCallback(int*);
    void SetTestAllCellsCallbackData(void*);
    void SetTestAllCellsRegionFilter(TESRegion*);
    void TestAllCells(int);
    void TestSubmergedObjects();
    bool CellTestRunning();
    bool CellTestRunning2();
    bool SumbergedObjectTestRunning();
    void SetCellTestRunning(bool);
    void SetCellTestRunning2(bool);
    void RunCellTest(unsigned int);
    void EmptyStructPlaceholder(TESObjectCELL*, unsigned int, unsigned int);
    void BuildCountString(NiNode*);
    int GetFaceCount(NiNode*, bool);
    int InitializeTESResources(NiNode*);
    void CreateTextureImage(char*, void*, bool, bool);
    bool LoadCanopyShadowTexture(char*, unsigned int);
    void WriteTextureImage(NiTexture*, char*, int);
    NiAVObject* CreateDeepCopySameTextures(NiAVObject*, GridCellData*);
    void InitializeTESWorld(int, int, int, int);
    void InitializeTESWorld(TESObjectCELL*);
    void CancelExteriorCellLoads();
    void* GetLastLoadedExteriors();
    void* GetBedChairList();
    void ClearBedChairList();
    void* GetDeadCountList();
    void ClearDeadCountList();
    short GetDeadCount(TESActorBase*);
    void AddDeadCount(TESActorBase*, short);
    void SetShowCollisionBounds(bool);
    bool GetShowCollisionBounds();
    void ShowCollisionBounds(bool, bool);
    void ShowCollisionBox(NiNode*);
    void ToggleCollisionGeometry();
    void TogglePrimitives();
    void SaveWorld(char*);
    void SetShowLandBorders(bool);
    bool GetShowLandBorders();
    void SetShowWater(bool);
    void SetLandRenderingOptions(int, bool, bool);
    bool PickLandscapeOnly(NiPick*, void*, void*);
    bool PickWaterDistance(NiPick*, void*, void*, float);
    bool PickWorldDistance(NiPick*, void*, void*, float, char);
    bool GetLandHeightAtPosition(void*, float*);
    bool GetSurfaceNormal(void*, NiPoint3*, NiPoint3*);
    bool GetSurfaceColor(void*, RgbaColor*);
    NiGeometry* GetSurfaceGeometry(void*);
    TESLandTexture* GetLandTexture(void*);
    int GetLandMaterialType(void*);
    float GetLandFrictionValue(void*);
    float GetLandRestitutionValue(void*);
    bool LineVsLand(void*, void*, NiPoint3*, float);
    bool CanAttach3D(TESObjectREFR*);
    void GetCurrentWorldspace(TESObjectREFR*);
    void AttachModel(TESObjectREFR*, TESObjectCELL*, QueuedReference*, bool);
    void DetachModel(TESObjectREFR*);
    void UpdateGridLights();
    float UpdateTESState(void*, TESObjectCELL*);
    WaterZoneManager* GetWaterSystem();
    Sky* GetSky();
    void HideSky();
    void ShowSky();
    void UpdateSky(struct blob12);
    void SetSkyMode(int);
    bool RefreshWorldState(bool, TESForm*, bool);
    void ShowLoadingAreaMessage(char*);
    GridDistantArray* GetGridDistantArray();
    void SetUpdateGridString();
    bool GetUpdateGridString();
    void UpdateExteriorCellBuffer();
    void MoveToEndOfExteriorBuffer(TESObjectCELL*);
    void RemoveCellFromExteriorBuffer(TESObjectCELL*, bool);
    void RemoveCellFromInteriorBuffer(TESObjectCELL*);
    void CreateFurnitureList();
    GridLand* FindGridLandForLand(TESObjectLAND*);
    void ToggleLoadFade();
    static bool ProcessVisibleBounds(NiNode*, bool);
    NiAVObject* Pick(BhkPickData*, bool);
    NiAVObject* Pick(BhkPickData*);
    NiAVObject* PickNI(BhkPickData*);
    static bool QCollisionDisableFlag();
    static void SetCollisionDisableFlag(bool);
    void ToggleCollision();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void FinishLoad();
    void ClearPersistentRef3DInLoadedCells();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
    void Revert(BGSLoadGameBuffer*);
    int GetCurrentGridX();
    int GetCurrentGridY();
    void SetCurrentGridX(int);
    void SetCurrentGridY(int);
    unsigned int GetExteriorBufferSize();
    TESObjectCELL* GetExteriorBufferCellByIndex(unsigned int);
    unsigned int GetInteriorBufferSize();
    TESObjectCELL* GetInteriorBufferCellByIndex(unsigned int);
    void InitializeTESData();
    void UpdateFadeNodesForAttachedCells();
    void LoadTESWorldData();
    void UnloadAddonNodes();
    void ProcessTESObjects();
    void UnloadDefaultModels();
    void PreloadPlaceableWaterNoiseTextures();
    void UnloadPlaceableWaterNoiseTextures();
    void InitializeTESCells();
    void UnPreloadForms();
    void ClearCachedForms();
    void AddTemporaryParticleObjectToCache(NiAVObject*);
    unsigned int GetUnusedCachedParticleObject(NiAVObject*, void*);
    void PurgeUnusedParticleObjects();
    static bool GetSelectivePurgeUnusedOnFastTravel();
    void SetAllowUnusedPurge(bool);
    bool GetAllowUnusedPurge();
    NavMeshInfoMap* GetActiveCell();
    void IsCellAttached(NavMeshInfoMap*);
    void* GetActiveImageSpaceModifierList();
    static void InitializeMultiBounds();
    static void ClearMultiBoundResults();
    void UpdateMultiBoundResults(NiCamera*);
    void SetMultiBoundVisibility(bool, bool);
    void AddMultiBoundsToDebugLines(NiCamera*);
    static void RangedNodeVisibilityChangedCB(NiNode*, bool);
    static unsigned int RecursiveGetVertexCount(NiNode*, bool);
    static int GetModelResourceType(TESObject*);
    static void SetFadeOutObjectMult(float);
    static void SetFadeOutItemMult(float);
    static void SetFadeOutActorMult(float);
    void ResetFadeOutMultipliers();
    void InitializeTES();
    void IncrementPlaceableWaterCount();
    void DecrementPlaceableWaterCount();
    unsigned int QPlaceableWaterCount();
    static void InitFadeOutMultipliers();
    void UpdateLoadedCellsAtPosition(bool, NiPoint3*);
    void ProcessTESUpdate(void*, bool);
    bool IsCellBuffering();
    void ClearCellBuffers();
    void UpdateCellBuffers();
    bool IsBuffered(TESObjectCELL*);
    bool IsInteriorBuffered(TESObjectCELL*);
    void AddToBuffer(TESObjectCELL*);
    void AddCellToInteriorBuffer(TESObjectCELL*);
    unsigned int GetInteriorBufferCount(bool);
    bool IsExteriorBuffered(TESObjectCELL*);
    void AddCellToExteriorBuffer(TESObjectCELL*);
    unsigned int GetExteriorBufferCount(bool, TESWorldSpace*);
    void AddCollideObject(TESFormList*);
    void HideUnneededLandPasses();
    void HideFarLandNormalMaps();
    void SetHideLandBlendPassForGridCell(int, int, bool);
    void SetHideLandNormalMapForGridCell(int, int, bool);
    void* __vecDelDtor(unsigned int);
    GridDistantArray* m_pGridDistantArray;
    GridCellArray* m_pGridCells;
    NiNode* m_pLandRootNode;
    NiNode* m_pWaterRootNode;
    NiNode* m_pDistantLandRootNode;
    NiNode* m_pObjectRootNode;
    NiDirectionalLight* m_pDirectionalLight;
    NiFogProperty* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    TESObjectCELL* m_pReferenceCell;
    TESObjectCELL** m_ppCellBufferA;
    TESObjectCELL** m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    int* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    TESRegion* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    char _pad_61[3];
    WaterZoneManager* m_pCurrentClimate;
    Sky* pWeatherSky;
    char m_kImageSpaceModifierInstances[8];
    unsigned int m_uiNextImageSpaceModifierId;
    unsigned int m_uiImageSpaceModifierCount;
    bool m_bImageSpaceStateFlag;
    bool m_bSkyStateFlag;
    char _pad_7e[2];
    float m_fFirstWorldspaceValue;
    float m_fSecondWorldspaceValue;
    TESWorldSpace* m_pContainingWorldspace;
    char m_kWorldspaceCellList[8];
    char m_kTemporaryReferences[8];
    char m_kLeveledActorEntries[8];
    char m_spWorldspaceQueuedFile[4];
    char m_pSourceTexture[4];
    char m_spQueuedFile[4];
    void* m_pParticleObjectCache;
    bool m_bFirstTESStateFlag;
    bool m_bSecondTESStateFlag;
    char _pad_b6[2];
    unsigned int m_uiNavMeshStateValue;
    NavMeshInfoMap* m_pNavMeshInfoMap;
    char m_spLoadedAreaBound[4];
};
struct FUN_00453940_shell : public TES
{
    void FUN_00453940();
};

struct GridCellArray
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void Clear();
};
// If g_dataHandler is set, clears the grid cell array and calls FUN_00451570(0) and FUN_00451520(1).
// @fnv 0x00453940
void FUN_00453940_shell::FUN_00453940()
{
    if (!(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))
        return;
    m_pGridCells->Clear();
    FUN_00451570(0);
    FUN_00451520(1);
}
}  // namespace fnv_00453940

struct GlobalObject_0045cfe0
{
};
struct FUN_00453980_shell
{
    int GetGlobalInt();
};
// @fnv 0x00453980
int FUN_00453980_shell::GetGlobalInt()
{
    return *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90))))));
}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};

struct FUN_00454400_shell
{
    int GetRaceListSize();
};

// @fnv 0x00454400
int FUN_00454400_shell::GetRaceListSize()
{
    return ((BSSimpleListTESRaceSize*)((char*)this + 0xac))->GetSize();
}

void __cdecl FUN_00455680(void);
struct FUN_004baba0_shell
{
    void FUN_004baba0();
};
struct FUN_00553820_shell
{
};
struct CP_008c48d0
{
};
struct FUN_00455640_shell
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00455640();
};
// Calls FUN_00455680, then invokes FUN_00553820 on the previous path if one exists, otherwise calls FUN_004baba0 on m8.
// @fnv 0x00455640
void FUN_00455640_shell::FUN_00455640()
{
    FUN_00455680();
    if (((void *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath())))
    {
        ::fnv_00553820::FUN_00553820((::TESObjectCELL *)(((FUN_00553820_shell*)((void *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath())))));
    }
    else
    {
        ((FUN_004baba0_shell*)m8)->FUN_004baba0();
    }
}

namespace fnv_00455690 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct GridCellData;
struct GridCell;
struct GridCellArray;
struct GridDistantArray;
struct GridLand;
struct NavMeshInfoMap;
struct NiAVObject;
struct NiCamera;
struct RgbaColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiGeometry;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiTexture;
struct QueuedReference;
struct Sky;
struct TESActorBase;
struct TESForm;
struct TESLandTexture;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESFormList;
struct TESObjectREFR;
struct TESRegion;
struct WaterZoneManager;
struct TESWorldSpace;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};
struct TES
{
    virtual bool SetDateTimeText(void*, struct blob12, TESWorldSpace*);
    void InitVars();
    NiNode* GetRoot();
    NiNode* GetTempNodeManager();
    NiNode* GetLandRoot();
    NiNode* GetLODWaterRoot();
    GridCell* GetGridCell(int, int);
    NiDirectionalLight* GetLight();
    NiFogProperty* GetFog();
    TESObjectCELL* GetDetailedActorPathHandler();
    GridCellArray* GetGridCellA();
    void UpdateWater(NiAVObject*, float);
    void InitializeWater();
    void FreeWater();
    bool LoadAndBufferExterior(int, int, TESWorldSpace*, unsigned int);
    bool LoadAndBufferInterior(TESObjectCELL*);
    void InitGridCells(void*, bool);
    int FindCellAtPosition(void*, bool);
    void ResizeGrid(unsigned int);
    void SetTESActive(bool);
    void SetLODFadeDistance(float);
    void UpdateGrid();
    void InitializeTESManager(bool);
    void SyncCellActorHavok();
    void UpdateDeferredCellAnimationTransforms();
    void ProcessCellQueues(bool, bool);
    bool IsCellFreePending();
    bool HasCellToFree();
    void ClearCellsForWorld(TESWorldSpace*);
    bool IsCoordInLoadedArea(void*);
    bool IsCellBuffered(TESObjectCELL*, bool);
    void GetLoadedAreaBounds(tagRECT*, float);
    TESObjectCELL* LineIntersectsLoadedCells(void*, void*, NiPoint3*, float);
    void GetCellStrings(NiNode*);
    void GetCollideStrings(NiNode*);
    TESObjectCELL* IsCellInterior();
    void SetInterior(TESObjectCELL*);
    void ClearWorldSpace();
    TESWorldSpace* GetParentWorldSpace();
    void AssignWorldSpace(TESWorldSpace*);
    void GetSaveGridXY(tagPOINT*);
    void SetSaveGridXY(void*);
    void SetCellCallback(TESObjectCELL*, void*);
    void LeaveInterior(NiPoint3*);
    GridCell* FindFirstGridCellWithWater();
    TESObjectCELL* FindCellByGridCoordinates(int, int);
    GridCell* GetGridCellForCell(TESObjectCELL*);
    int GetCellPriority(TESObjectCELL*, NiPoint3*);
    TESObjectCELL* GetCellContainingPoint(struct blob12);
    void RunScripts();
    void RunAnimations();
    void UpdateRefSounds();
    void SetAtmosphere(TESObjectCELL*);
    void SetTestAllCellsCallback(int*);
    void SetTestAllCellsCallbackData(void*);
    void SetTestAllCellsRegionFilter(TESRegion*);
    void TestAllCells(int);
    void TestSubmergedObjects();
    bool CellTestRunning();
    bool CellTestRunning2();
    bool SumbergedObjectTestRunning();
    void SetCellTestRunning(bool);
    void SetCellTestRunning2(bool);
    void RunCellTest(unsigned int);
    void EmptyStructPlaceholder(TESObjectCELL*, unsigned int, unsigned int);
    void BuildCountString(NiNode*);
    int GetFaceCount(NiNode*, bool);
    int InitializeTESResources(NiNode*);
    void CreateTextureImage(char*, void*, bool, bool);
    bool LoadCanopyShadowTexture(char*, unsigned int);
    void WriteTextureImage(NiTexture*, char*, int);
    NiAVObject* CreateDeepCopySameTextures(NiAVObject*, GridCellData*);
    void InitializeTESWorld(int, int, int, int);
    void InitializeTESWorld(TESObjectCELL*);
    void CancelExteriorCellLoads();
    void* GetLastLoadedExteriors();
    void* GetBedChairList();
    void ClearBedChairList();
    void* GetDeadCountList();
    void ClearDeadCountList();
    short GetDeadCount(TESActorBase*);
    void AddDeadCount(TESActorBase*, short);
    void SetShowCollisionBounds(bool);
    bool GetShowCollisionBounds();
    void ShowCollisionBounds(bool, bool);
    void ShowCollisionBox(NiNode*);
    void ToggleCollisionGeometry();
    void TogglePrimitives();
    void SaveWorld(char*);
    void SetShowLandBorders(bool);
    bool GetShowLandBorders();
    void SetShowWater(bool);
    void SetLandRenderingOptions(int, bool, bool);
    bool PickLandscapeOnly(NiPick*, void*, void*);
    bool PickWaterDistance(NiPick*, void*, void*, float);
    bool PickWorldDistance(NiPick*, void*, void*, float, char);
    bool GetLandHeightAtPosition(void*, float*);
    bool GetSurfaceNormal(void*, NiPoint3*, NiPoint3*);
    bool GetSurfaceColor(void*, RgbaColor*);
    NiGeometry* GetSurfaceGeometry(void*);
    TESLandTexture* GetLandTexture(void*);
    int GetLandMaterialType(void*);
    float GetLandFrictionValue(void*);
    float GetLandRestitutionValue(void*);
    bool LineVsLand(void*, void*, NiPoint3*, float);
    bool CanAttach3D(TESObjectREFR*);
    void GetCurrentWorldspace(TESObjectREFR*);
    void AttachModel(TESObjectREFR*, TESObjectCELL*, QueuedReference*, bool);
    void DetachModel(TESObjectREFR*);
    void UpdateGridLights();
    float UpdateTESState(void*, TESObjectCELL*);
    WaterZoneManager* GetWaterSystem();
    Sky* GetSky();
    void HideSky();
    void ShowSky();
    void UpdateSky(struct blob12);
    void SetSkyMode(int);
    bool RefreshWorldState(bool, TESForm*, bool);
    void ShowLoadingAreaMessage(char*);
    GridDistantArray* GetGridDistantArray();
    void SetUpdateGridString();
    bool GetUpdateGridString();
    void UpdateExteriorCellBuffer();
    void MoveToEndOfExteriorBuffer(TESObjectCELL*);
    void RemoveCellFromExteriorBuffer(TESObjectCELL*, bool);
    void RemoveCellFromInteriorBuffer(TESObjectCELL*);
    void CreateFurnitureList();
    GridLand* FindGridLandForLand(TESObjectLAND*);
    void ToggleLoadFade();
    static bool ProcessVisibleBounds(NiNode*, bool);
    NiAVObject* Pick(BhkPickData*, bool);
    NiAVObject* Pick(BhkPickData*);
    NiAVObject* PickNI(BhkPickData*);
    static bool QCollisionDisableFlag();
    static void SetCollisionDisableFlag(bool);
    void ToggleCollision();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void FinishLoad();
    void ClearPersistentRef3DInLoadedCells();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
    void Revert(BGSLoadGameBuffer*);
    int GetCurrentGridX();
    int GetCurrentGridY();
    void SetCurrentGridX(int);
    void SetCurrentGridY(int);
    unsigned int GetExteriorBufferSize();
    TESObjectCELL* GetExteriorBufferCellByIndex(unsigned int);
    unsigned int GetInteriorBufferSize();
    TESObjectCELL* GetInteriorBufferCellByIndex(unsigned int);
    void InitializeTESData();
    void UpdateFadeNodesForAttachedCells();
    void LoadTESWorldData();
    void UnloadAddonNodes();
    void ProcessTESObjects();
    void UnloadDefaultModels();
    void PreloadPlaceableWaterNoiseTextures();
    void UnloadPlaceableWaterNoiseTextures();
    void InitializeTESCells();
    void UnPreloadForms();
    void ClearCachedForms();
    void AddTemporaryParticleObjectToCache(NiAVObject*);
    unsigned int GetUnusedCachedParticleObject(NiAVObject*, void*);
    void PurgeUnusedParticleObjects();
    static bool GetSelectivePurgeUnusedOnFastTravel();
    void SetAllowUnusedPurge(bool);
    bool GetAllowUnusedPurge();
    NavMeshInfoMap* GetActiveCell();
    void IsCellAttached(NavMeshInfoMap*);
    void* GetActiveImageSpaceModifierList();
    static void InitializeMultiBounds();
    static void ClearMultiBoundResults();
    void UpdateMultiBoundResults(NiCamera*);
    void SetMultiBoundVisibility(bool, bool);
    void AddMultiBoundsToDebugLines(NiCamera*);
    static void RangedNodeVisibilityChangedCB(NiNode*, bool);
    static unsigned int RecursiveGetVertexCount(NiNode*, bool);
    static int GetModelResourceType(TESObject*);
    static void SetFadeOutObjectMult(float);
    static void SetFadeOutItemMult(float);
    static void SetFadeOutActorMult(float);
    void ResetFadeOutMultipliers();
    void InitializeTES();
    void IncrementPlaceableWaterCount();
    void DecrementPlaceableWaterCount();
    unsigned int QPlaceableWaterCount();
    static void InitFadeOutMultipliers();
    void UpdateLoadedCellsAtPosition(bool, NiPoint3*);
    void ProcessTESUpdate(void*, bool);
    bool IsCellBuffering();
    void ClearCellBuffers();
    void UpdateCellBuffers();
    bool IsBuffered(TESObjectCELL*);
    bool IsInteriorBuffered(TESObjectCELL*);
    void AddToBuffer(TESObjectCELL*);
    void AddCellToInteriorBuffer(TESObjectCELL*);
    unsigned int GetInteriorBufferCount(bool);
    bool IsExteriorBuffered(TESObjectCELL*);
    void AddCellToExteriorBuffer(TESObjectCELL*);
    unsigned int GetExteriorBufferCount(bool, TESWorldSpace*);
    void AddCollideObject(TESFormList*);
    void HideUnneededLandPasses();
    void HideFarLandNormalMaps();
    void SetHideLandBlendPassForGridCell(int, int, bool);
    void SetHideLandNormalMapForGridCell(int, int, bool);
    void* __vecDelDtor(unsigned int);
    GridDistantArray* m_pGridDistantArray;
    GridCellArray* m_pGridCells;
    NiNode* m_pLandRootNode;
    NiNode* m_pWaterRootNode;
    NiNode* m_pDistantLandRootNode;
    NiNode* m_pObjectRootNode;
    NiDirectionalLight* m_pDirectionalLight;
    NiFogProperty* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    TESObjectCELL* m_pReferenceCell;
    TESObjectCELL** m_ppCellBufferA;
    TESObjectCELL** m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    int* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    TESRegion* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    char _pad_61[3];
    WaterZoneManager* m_pCurrentClimate;
    Sky* pWeatherSky;
    char m_kImageSpaceModifierInstances[8];
    unsigned int m_uiNextImageSpaceModifierId;
    unsigned int m_uiImageSpaceModifierCount;
    bool m_bImageSpaceStateFlag;
    bool m_bSkyStateFlag;
    char _pad_7e[2];
    float m_fFirstWorldspaceValue;
    float m_fSecondWorldspaceValue;
    TESWorldSpace* m_pContainingWorldspace;
    char m_kWorldspaceCellList[8];
    char m_kTemporaryReferences[8];
    char m_kLeveledActorEntries[8];
    char m_spWorldspaceQueuedFile[4];
    char m_pSourceTexture[4];
    char m_spQueuedFile[4];
    void* m_pParticleObjectCache;
    bool m_bFirstTESStateFlag;
    bool m_bSecondTESStateFlag;
    char _pad_b6[2];
    unsigned int m_uiNavMeshStateValue;
    NavMeshInfoMap* m_pNavMeshInfoMap;
    char m_spLoadedAreaBound[4];
};
struct FUN_00455690_shell : public TES
{
    void FUN_00455690();
};

struct CP_008c48d0
{
};
struct S_005538e0
{
};
struct S_004bac20
{
};
// @fnv 0x00455690
void FUN_00455690_shell::FUN_00455690()
{
    if (((int)(std::intptr_t)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath())))
        reinterpret_cast<::fnv_005538e0::Cell5538 *>((((S_005538e0*)((reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath())))))->PlayCellSoundEffects();
    else
        reinterpret_cast<::FUN_004bac20_shell *>((((S_004bac20*)m_pGridCells)))->FUN_004bac20();
}
}  // namespace fnv_00455690

namespace fnv_00456be0 {
struct TESObjectCELL;
struct bhkWorld;
struct FUN_00454380_shell
{
};
struct ExtraDataList
{
};
struct CP_008c48d0
{
};
struct FUN_00456be0_shell
{
    void FUN_00456be0();
};
// @fnv 0x00456be0
void FUN_00456be0_shell::FUN_00456be0()
{
    bool bcol = !::FUN_00456c70();
    ::FUN_00456c80(bcol);
    bhkWorld* pw = 0;
    TESObjectCELL* pcell = reinterpret_cast<TESObjectCELL*>(((std::intptr_t)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(::g_TES)))->GetPrevPath())));
    if (pcell)
        pw = reinterpret_cast<bhkWorld*>(((std::uintptr_t)(reinterpret_cast<::FUN_004543c0_cls *>((reinterpret_cast<ExtraDataList*>(pcell)))->FUN_004543c0())));
    else
        pw = ((::fnv_00456be0::bhkWorld *)(::FUN_00451010()));
    if (pw)
        reinterpret_cast<::FUN_00454380_Class *>((reinterpret_cast<FUN_00454380_shell*>(pw)))->FUN_00454380(!bcol);
    ::fnv_00456c90::FUN_00456c90(!bcol);
}
}  // namespace fnv_00456be0

namespace fnv_00456cb0 {
struct CP_008c48d0
{
};
struct FUN_004baca0_Holder
{
};
struct TES
{
    char _pad0[8];
    FUN_004baca0_Holder* m_pGridCells;
    char _pad1[84];
    bool m_bHasCurrentRegion;
    void FUN_00456cb0(bool);
};
// @fnv 0x00456cb0
void TES::FUN_00456cb0(bool abShow)
{
    if (m_bHasCurrentRegion != abShow)
    {
        m_bHasCurrentRegion = abShow;
        if (!(*reinterpret_cast<void * *>(&::g_dataHandler)) || ((std::intptr_t)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath())))
            return;
        reinterpret_cast<::fnv_004baca0::GridCellArrayHelper *>((m_pGridCells))->FUN_004baca0(abShow);
    }
}
}  // namespace fnv_00456cb0

namespace fnv_00457070 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct GridCellData;
struct GridCell;
struct GridCellArray;
struct GridDistantArray;
struct GridLand;
struct NavMeshInfoMap;
struct NiAVObject;
struct NiCamera;
struct RgbaColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiGeometry;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiTexture;
struct QueuedReference;
struct Sky;
struct TESActorBase;
struct TESForm;
struct TESLandTexture;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESFormList;
struct TESObjectREFR;
struct TESRegion;
struct WaterZoneManager;
struct TESWorldSpace;
struct BhkPickData;
struct tagPOINT;
struct tagRECT;
struct blob12
{
    char b[12];
};
struct TES
{
    virtual bool SetDateTimeText(void*, struct blob12, TESWorldSpace*);
    void InitVars();
    NiNode* GetRoot();
    NiNode* GetTempNodeManager();
    NiNode* GetLandRoot();
    NiNode* GetLODWaterRoot();
    GridCell* GetGridCell(int, int);
    NiDirectionalLight* GetLight();
    NiFogProperty* GetFog();
    TESObjectCELL* GetDetailedActorPathHandler();
    GridCellArray* GetGridCellA();
    void UpdateWater(NiAVObject*, float);
    void InitializeWater();
    void FreeWater();
    bool LoadAndBufferExterior(int, int, TESWorldSpace*, unsigned int);
    bool LoadAndBufferInterior(TESObjectCELL*);
    void InitGridCells(void*, bool);
    int FindCellAtPosition(void*, bool);
    void ResizeGrid(unsigned int);
    void SetTESActive(bool);
    void SetLODFadeDistance(float);
    void UpdateGrid();
    void InitializeTESManager(bool);
    void SyncCellActorHavok();
    void UpdateDeferredCellAnimationTransforms();
    void ProcessCellQueues(bool, bool);
    bool IsCellFreePending();
    bool HasCellToFree();
    void ClearCellsForWorld(TESWorldSpace*);
    bool IsCoordInLoadedArea(void*);
    bool IsCellBuffered(TESObjectCELL*, bool);
    void GetLoadedAreaBounds(tagRECT*, float);
    TESObjectCELL* LineIntersectsLoadedCells(void*, void*, NiPoint3*, float);
    void GetCellStrings(NiNode*);
    void GetCollideStrings(NiNode*);
    TESObjectCELL* IsCellInterior();
    void SetInterior(TESObjectCELL*);
    void ClearWorldSpace();
    TESWorldSpace* GetParentWorldSpace();
    void AssignWorldSpace(TESWorldSpace*);
    void GetSaveGridXY(tagPOINT*);
    void SetSaveGridXY(void*);
    void SetCellCallback(TESObjectCELL*, void*);
    void LeaveInterior(NiPoint3*);
    GridCell* FindFirstGridCellWithWater();
    TESObjectCELL* FindCellByGridCoordinates(int, int);
    GridCell* GetGridCellForCell(TESObjectCELL*);
    int GetCellPriority(TESObjectCELL*, NiPoint3*);
    TESObjectCELL* GetCellContainingPoint(struct blob12);
    void RunScripts();
    void RunAnimations();
    void UpdateRefSounds();
    void SetAtmosphere(TESObjectCELL*);
    void SetTestAllCellsCallback(int*);
    void SetTestAllCellsCallbackData(void*);
    void SetTestAllCellsRegionFilter(TESRegion*);
    void TestAllCells(int);
    void TestSubmergedObjects();
    bool CellTestRunning();
    bool CellTestRunning2();
    bool SumbergedObjectTestRunning();
    void SetCellTestRunning(bool);
    void SetCellTestRunning2(bool);
    void RunCellTest(unsigned int);
    void EmptyStructPlaceholder(TESObjectCELL*, unsigned int, unsigned int);
    void BuildCountString(NiNode*);
    int GetFaceCount(NiNode*, bool);
    int InitializeTESResources(NiNode*);
    void CreateTextureImage(char*, void*, bool, bool);
    bool LoadCanopyShadowTexture(char*, unsigned int);
    void WriteTextureImage(NiTexture*, char*, int);
    NiAVObject* CreateDeepCopySameTextures(NiAVObject*, GridCellData*);
    void InitializeTESWorld(int, int, int, int);
    void InitializeTESWorld(TESObjectCELL*);
    void CancelExteriorCellLoads();
    void* GetLastLoadedExteriors();
    void* GetBedChairList();
    void ClearBedChairList();
    void* GetDeadCountList();
    void ClearDeadCountList();
    short GetDeadCount(TESActorBase*);
    void AddDeadCount(TESActorBase*, short);
    void SetShowCollisionBounds(bool);
    bool GetShowCollisionBounds();
    void ShowCollisionBounds(bool, bool);
    void ShowCollisionBox(NiNode*);
    void ToggleCollisionGeometry();
    void TogglePrimitives();
    void SaveWorld(char*);
    void SetShowLandBorders(bool);
    bool GetShowLandBorders();
    void SetShowWater(bool);
    void SetLandRenderingOptions(int, bool, bool);
    bool PickLandscapeOnly(NiPick*, void*, void*);
    bool PickWaterDistance(NiPick*, void*, void*, float);
    bool PickWorldDistance(NiPick*, void*, void*, float, char);
    bool GetLandHeightAtPosition(void*, float*);
    bool GetSurfaceNormal(void*, NiPoint3*, NiPoint3*);
    bool GetSurfaceColor(void*, RgbaColor*);
    NiGeometry* GetSurfaceGeometry(void*);
    TESLandTexture* GetLandTexture(void*);
    int GetLandMaterialType(void*);
    float GetLandFrictionValue(void*);
    float GetLandRestitutionValue(void*);
    bool LineVsLand(void*, void*, NiPoint3*, float);
    bool CanAttach3D(TESObjectREFR*);
    void GetCurrentWorldspace(TESObjectREFR*);
    void AttachModel(TESObjectREFR*, TESObjectCELL*, QueuedReference*, bool);
    void DetachModel(TESObjectREFR*);
    void UpdateGridLights();
    float UpdateTESState(void*, TESObjectCELL*);
    WaterZoneManager* GetWaterSystem();
    Sky* GetSky();
    void HideSky();
    void ShowSky();
    void UpdateSky(struct blob12);
    void SetSkyMode(int);
    bool RefreshWorldState(bool, TESForm*, bool);
    void ShowLoadingAreaMessage(char*);
    GridDistantArray* GetGridDistantArray();
    void SetUpdateGridString();
    bool GetUpdateGridString();
    void UpdateExteriorCellBuffer();
    void MoveToEndOfExteriorBuffer(TESObjectCELL*);
    void RemoveCellFromExteriorBuffer(TESObjectCELL*, bool);
    void RemoveCellFromInteriorBuffer(TESObjectCELL*);
    void CreateFurnitureList();
    GridLand* FindGridLandForLand(TESObjectLAND*);
    void ToggleLoadFade();
    static bool ProcessVisibleBounds(NiNode*, bool);
    NiAVObject* Pick(BhkPickData*, bool);
    NiAVObject* Pick(BhkPickData*);
    NiAVObject* PickNI(BhkPickData*);
    static bool QCollisionDisableFlag();
    static void SetCollisionDisableFlag(bool);
    void ToggleCollision();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void FinishLoad();
    void ClearPersistentRef3DInLoadedCells();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
    void Revert(BGSLoadGameBuffer*);
    int GetCurrentGridX();
    int GetCurrentGridY();
    void SetCurrentGridX(int);
    void SetCurrentGridY(int);
    unsigned int GetExteriorBufferSize();
    TESObjectCELL* GetExteriorBufferCellByIndex(unsigned int);
    unsigned int GetInteriorBufferSize();
    TESObjectCELL* GetInteriorBufferCellByIndex(unsigned int);
    void InitializeTESData();
    void UpdateFadeNodesForAttachedCells();
    void LoadTESWorldData();
    void UnloadAddonNodes();
    void ProcessTESObjects();
    void UnloadDefaultModels();
    void PreloadPlaceableWaterNoiseTextures();
    void UnloadPlaceableWaterNoiseTextures();
    void InitializeTESCells();
    void UnPreloadForms();
    void ClearCachedForms();
    void AddTemporaryParticleObjectToCache(NiAVObject*);
    unsigned int GetUnusedCachedParticleObject(NiAVObject*, void*);
    void PurgeUnusedParticleObjects();
    static bool GetSelectivePurgeUnusedOnFastTravel();
    void SetAllowUnusedPurge(bool);
    bool GetAllowUnusedPurge();
    NavMeshInfoMap* GetActiveCell();
    void IsCellAttached(NavMeshInfoMap*);
    void* GetActiveImageSpaceModifierList();
    static void InitializeMultiBounds();
    static void ClearMultiBoundResults();
    void UpdateMultiBoundResults(NiCamera*);
    void SetMultiBoundVisibility(bool, bool);
    void AddMultiBoundsToDebugLines(NiCamera*);
    static void RangedNodeVisibilityChangedCB(NiNode*, bool);
    static unsigned int RecursiveGetVertexCount(NiNode*, bool);
    static int GetModelResourceType(TESObject*);
    static void SetFadeOutObjectMult(float);
    static void SetFadeOutItemMult(float);
    static void SetFadeOutActorMult(float);
    void ResetFadeOutMultipliers();
    void InitializeTES();
    void IncrementPlaceableWaterCount();
    void DecrementPlaceableWaterCount();
    unsigned int QPlaceableWaterCount();
    static void InitFadeOutMultipliers();
    void UpdateLoadedCellsAtPosition(bool, NiPoint3*);
    void ProcessTESUpdate(void*, bool);
    bool IsCellBuffering();
    void ClearCellBuffers();
    void UpdateCellBuffers();
    bool IsBuffered(TESObjectCELL*);
    bool IsInteriorBuffered(TESObjectCELL*);
    void AddToBuffer(TESObjectCELL*);
    void AddCellToInteriorBuffer(TESObjectCELL*);
    unsigned int GetInteriorBufferCount(bool);
    bool IsExteriorBuffered(TESObjectCELL*);
    void AddCellToExteriorBuffer(TESObjectCELL*);
    unsigned int GetExteriorBufferCount(bool, TESWorldSpace*);
    void AddCollideObject(TESFormList*);
    void HideUnneededLandPasses();
    void HideFarLandNormalMaps();
    void SetHideLandBlendPassForGridCell(int, int, bool);
    void SetHideLandNormalMapForGridCell(int, int, bool);
    void* __vecDelDtor(unsigned int);
    GridDistantArray* m_pGridDistantArray;
    GridCellArray* m_pGridCells;
    NiNode* m_pLandRootNode;
    NiNode* m_pWaterRootNode;
    NiNode* m_pDistantLandRootNode;
    NiNode* m_pObjectRootNode;
    NiDirectionalLight* m_pDirectionalLight;
    NiFogProperty* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    TESObjectCELL* m_pReferenceCell;
    TESObjectCELL** m_ppCellBufferA;
    TESObjectCELL** m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    int* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    TESRegion* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    char _pad_61[3];
    WaterZoneManager* m_pCurrentClimate;
    Sky* pWeatherSky;
    char m_kImageSpaceModifierInstances[8];
    unsigned int m_uiNextImageSpaceModifierId;
    unsigned int m_uiImageSpaceModifierCount;
    bool m_bImageSpaceStateFlag;
    bool m_bSkyStateFlag;
    char _pad_7e[2];
    float m_fFirstWorldspaceValue;
    float m_fSecondWorldspaceValue;
    TESWorldSpace* m_pContainingWorldspace;
    char m_kWorldspaceCellList[8];
    char m_kTemporaryReferences[8];
    char m_kLeveledActorEntries[8];
    char m_spWorldspaceQueuedFile[4];
    char m_pSourceTexture[4];
    char m_spQueuedFile[4];
    void* m_pParticleObjectCache;
    bool m_bFirstTESStateFlag;
    bool m_bSecondTESStateFlag;
    char _pad_b6[2];
    unsigned int m_uiNavMeshStateValue;
    NavMeshInfoMap* m_pNavMeshInfoMap;
    char m_spLoadedAreaBound[4];
};
struct FUN_00457070_shell : public TES
{
    TESObjectCELL* FUN_00457070();
};

// @fnv 0x00457070
TESObjectCELL* FUN_00457070_shell::FUN_00457070()
{
    if (((::fnv_00457070::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        return ((::fnv_00457070::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (iFirstValue == 0x7fffffff || iSecondValue == 0x7fffffff)
        return 0;
    return FindCellByGridCoordinates(iFirstValue, iSecondValue);
}
}  // namespace fnv_00457070

class NiUpdateData;
struct NiNode
{
    NiAVObject* GetAt(unsigned int);
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
public:
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
};
struct TESObjectCELLHelper
{
};
struct FUN_0045c9a0_shell : public TESObjectCELL
{
    NiAVObject* GetCellNodeAt(unsigned int index);
};
// @fnv 0x0045c9a0
NiAVObject* FUN_0045c9a0_shell::GetCellNodeAt(unsigned int index)
{
    NiAVObject* node = reinterpret_cast<::TESObjectCELL *>((((TESObjectCELLHelper*)this)))->GetCellChildAt(2);
    return node ? ((NiNode*)node)->GetAt(index) : 0;
}

struct FUN_00557090_shell
{
    void FUN_00557090();
};
struct FUN_005570b0_shell
{
    void IsSet();
};
// @fnv 0x00557090
void FUN_00557090_shell::FUN_00557090()
{
    ((FUN_005570b0_shell*)((char*)this + 0x80))->IsSet();
}

namespace fnv_00c44e40 {
struct NiUpdateData;
struct NiNode
{
};
struct FUN_00c44ed0_shell
{
};
struct FUN_00c44e40_shell
{
    void UpdateNodeDownward(float* p, unsigned int flags);
};
// Calls FUN_00c44ed0 with the float at p, then calls NiNode::UpdateDownwardPass with the NiUpdateData at p and flags.
// @fnv 0x00c44e40
void FUN_00c44e40_shell::UpdateNodeDownward(float* apUpdateData, unsigned int flags)
{
    reinterpret_cast<::StandNode *>((((FUN_00c44ed0_shell*)this)))->FUN_00c44ed0(*apUpdateData);
    reinterpret_cast<::NiNode *>((((NiNode*)this)))->UpdateDownwardPass((::NiUpdateData &)(*(NiUpdateData*)apUpdateData), flags);
}
}  // namespace fnv_00c44e40

namespace fnv_00c44e70 {
struct NiUpdateData;
struct NiNode
{
    virtual void UpdateSelectedDownwardPass(NiUpdateData&, unsigned int);
    void FUN_00c44e70(NiUpdateData&, unsigned int);
};
// @fnv 0x00c44e70
void NiNode::FUN_00c44e70(NiUpdateData& aUpdateData, unsigned int uiFlags)
{
    reinterpret_cast<::StandNode *>(this)->FUN_00c44ed0(*(float*)&aUpdateData);
    reinterpret_cast<::NiNode *>(this)->UpdateSelectedDownwardPass((::NiUpdateData &)(aUpdateData), uiFlags);
}
}  // namespace fnv_00c44e70

struct Unk_C44EA0
{
    void FUN_00c44ea0(float*, unsigned int);
};
// Calls FUN_00c44ed0 with the float pointed to by a, then FUN_00a5e1f0 with a and b.
// @fnv 0x00c44ea0
void Unk_C44EA0::FUN_00c44ea0(float* pfValue, unsigned int b)
{
    reinterpret_cast<::StandNode *>(this)->FUN_00c44ed0(*pfValue);
    ::FUN_00a5e1f0((::NiNode *)this, (std::intptr_t)(pfValue), (*(::NiUpdateData *)(b)), {});
}

namespace fnv_004518e0 {
struct TESObjectCELL;
struct TESObjectCELL
{
    char _pad[0x24];
    unsigned char m_ucStateAtOffset24;
    bool FUN_004518e0();
};
// @fnv 0x004518e0
bool TESObjectCELL::FUN_004518e0()
{
    return m_ucStateAtOffset24 & 0x2;
}
}  // namespace fnv_004518e0

namespace fnv_00451ea0 {
struct TESObjectREFR
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual bool V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual void V74();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
};
struct MobileObject : TESObjectREFR
{
};
struct Actor : MobileObject
{
};
struct ProcessLists
{
};
struct TES
{
    void FUN_00451ea0(TESObjectREFR* apRef);
};
// @fnv 0x00451ea0
void TES::FUN_00451ea0(TESObjectREFR* apRef)
{
    Actor* pactor;
    if (apRef->V64())
    {
        pactor = (Actor*)apRef;
        if (pactor)
        {
            pactor->V152();
            reinterpret_cast<::ProcessLists *>((((ProcessLists*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->RemoveMobileObjectFromList((::MobileObject *)(pactor));
        }
    }
}
}  // namespace fnv_00451ea0

struct FUN_00452390_shell
{
    char _pad[0xaa];
    unsigned short _0xaa;
    void FUN_00452390();
};

// Increments the unsigned short field at offset 0xaa of this object.
// @fnv 0x00452390
void FUN_00452390_shell::FUN_00452390()
{
    _0xaa++;
}

struct Holder4523e0
{
    char _pad[0x64];
    FUN_00452420_shell* pLoaded;
    bool FUN_004523e0(unsigned int aiFlag);
};
// Returns the loaded object's flag for aiFlag when pLoaded is set, otherwise false.
// @fnv 0x004523e0
bool Holder4523e0::FUN_004523e0(unsigned int aiFlag)
{
    return pLoaded ? pLoaded->GetFlag(aiFlag) : false;
}

namespace fnv_00454bd0 {
struct CellStand
{
};
struct GlobalObject_0045cfe0 : CellStand
{
};
struct TES
{
    char _pad[0x38];
    TESObjectCELL** m_ppCellBufferA;
    bool ContainsCell(TESObjectCELL* apCell);
};
// @fnv 0x00454bd0
bool TES::ContainsCell(TESObjectCELL* apCell)
{
    unsigned int n = 0;
    for (; n < reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::fnv_00454bd0::GlobalObject_0045cfe0 *>(&::g_011c3e38))))->GetCellStandValue(); n++)
    {
        if (m_ppCellBufferA[n] == apCell)
            return true;
    }
    return false;
}
}  // namespace fnv_00454bd0

namespace fnv_00454e20 {
struct CellStand
{
    char _pad[60];
    void** _arr;
    bool FUN_00454e20(void*);
};
// @fnv 0x00454e20
bool CellStand::FUN_00454e20(void* pElement)
{
    for (unsigned int i = 0; i < (unsigned int)reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::fnv_00454e20::CellStand *>(&::DAT_011c3c90))))->GetCellStandValue(); ++i)
    {
        if (_arr[i] == pElement)
            return true;
    }
    return false;
}
}  // namespace fnv_00454e20

namespace fnv_00458ef0 {
struct NiNode
{
    const void* vtbl;
    char pad[0xa8];
    float f0ac;
    NiNode(unsigned short);
};
struct FUN_00458ef0_shell : NiNode
{
    FUN_00458ef0_shell(float value);
};
// Initialises the NiNode base with 0, sets the vtable to DAT_01017d24 and stores value in f0ac.
// @fnv 0x00458ef0
FUN_00458ef0_shell::FUN_00458ef0_shell(float value) : NiNode(0)
{
    vtbl = &::DAT_01017d24;
    f0ac = value;
}
}  // namespace fnv_00458ef0

namespace fnv_00459000 {
struct TESActorBase
{
};
struct LeveledActorEntry
{
    TESActorBase* m_pActorBaseFormItem;
    short m_sLevel;
};
struct FakeList
{
};
struct TES
{
    char _pad[0x9c];
    FakeList m_kLeveledActorEntries;
    short FindActorBaseValue(TESActorBase* apObject);
};
// Searches the list for an entry whose TESActorBase pointer matches apObject and returns its short value, or 0 if not found.
// @fnv 0x00459000
short TES::FindActorBaseValue(TESActorBase* apObject)
{
    FakeList* pCurrentElementNext = &m_kLeveledActorEntries;
    while (pCurrentElementNext != 0 && *((::fnv_00459000::LeveledActorEntry **)((void *)(pCurrentElementNext))) != 0)
    {
        LeveledActorEntry* pEntry = *((::fnv_00459000::LeveledActorEntry **)((void *)(pCurrentElementNext)));
        if (pEntry->m_pActorBaseFormItem == apObject)
            return pEntry->m_sLevel;
        pCurrentElementNext = ((::fnv_00459000::FakeList *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    return 0;
}
}  // namespace fnv_00459000

struct FUN_0045aee0_shell
{
    char pad_0045aee0[0xb5];
    char m_0045aee0_b5;  // at offset 0xb5
    void SetByteB5(char v);
};

// @fnv 0x0045aee0
void FUN_0045aee0_shell::SetByteB5(char acValue)
{
    m_0045aee0_b5 = acValue;
}

namespace fnv_00628da0 {
struct NP
{
    NP& operator=(void*);
};
struct NiTPointerMap
{
};
struct LoadedAreaBound
{
    char _pad_0[8];
    NP arr[6];
    char _pad_1[0x10];
    int _pad_2;
    NiTPointerMap map;
    void FUN_00628da0();
};

// Clears _pad_2, sets all six entries of arr to null, and calls RemoveAll on map.
// @fnv 0x00628da0
void LoadedAreaBound::FUN_00628da0()
{
    _pad_2 = 0;
    for (int i = 0; i < 6; ++i)
    {
        *(NP*)(((char*)arr) + i * 4) = 0;
    }
    reinterpret_cast<::FUN_00438af0_Class *>(&(map))->FUN_00438af0();
}
}  // namespace fnv_00628da0

struct FUN_00454fc0_cls
{
};
struct FUN_004ba5a0_cell_helper
{
};
struct FUN_00452e50_class
{
    void FUN_00452e50();
};
struct CellStand
{
};
struct DH
{
    void DeleteObject(TESObjectCELL*);
};

struct FUN_00454e70_shell
{
    char _pad[0x3c];
    TESObjectCELL** m_ppCellBufferB;
    void MoveCellToFront(TESObjectCELL* apCell);
};
// If cell is non-null, adds it to the interior buffer when it is interior, otherwise to the exterior buffer.
// @fnv 0x00454b90
void FUN_00454b90_shell::AddCellToBuffer(TESObjectCELL* cell)
{
    if (cell)
    {
        if (cell->IsCellInterior())
        {
            ((TESObjectCELL_AddToInteriorBuffer*)this)->AddCellToInteriorBuffer(cell);
        }
        else
        {
            reinterpret_cast<::FUN_00454e70_shell *>((((TESObjectCELL_AddToExteriorBuffer*)this)))->MoveCellToFront(cell);
        }
    }
}

struct TESObjectLAND;
struct NiNode;
struct NiPoint2
{
    float x;
    float y;
};
struct L_GetHitSound
{
};
struct W_00585b30
{
};
struct W_00588150
{
};
struct FUN_00461c20_Holder
{
    TESObjectCELL* GetOrCreateCell(int, int, TESWorldSpace*, bool);
};
struct S00551440
{
    void FUN_00551440(bool);
};
struct FUN_004ba5a0_shell
{
    bool IsOutdoorCell(unsigned int, unsigned int);
};
struct GridCellArrayStandin
{
    void SetCellAt(unsigned int, unsigned int, TESObjectCELL*);
};
struct GridCellArray_Target
{
    void FUN_004ba960(NiNode*, unsigned int, unsigned int);
};
struct S454b90
{
};
struct C_0084e3a0
{
};
struct CellH
{
};
struct S451cb0
{
    const char* FUN_00451cb0();
};
struct FakeCell
{
};
struct LAND_x
{
};
struct S451250
{
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct MobileObjectCellAccess
{
};
struct S451cd0
{
};

struct TES_00451a50
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pGridCells;
    NiNode* m_pLandRootNode;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    bool m_bHasCurrentRegion;
    void FUN_00451a50(int aiGridX, int aiGridY, int aiCellX, int aiCellY);
};

// @fnv 0x00451a50
void TES_00451a50::FUN_00451a50(int aiGridX, int aiGridY, int aiCellX, int aiCellY)
{
    if (!((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((((L_GetHitSound*)this)))->GetHitSound())))
        return;
    TESObjectCELL* pcell = 0;
    NiPoint2 extents;
    TESObjectLAND* pLand;
    char pmessage[260];
    pcell = ((::TESObjectCELL *)(reinterpret_cast<::WorldCellLoader *>((((W_00585b30*)((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((((L_GetHitSound*)this)))->GetHitSound())))))->FUN_00585b30(aiCellX, aiCellY)));
    if (!pcell)
    {
        pcell = ((FUN_00461c20_Holder*)g_dataHandler)
                    ->GetOrCreateCell(aiCellX, aiCellY, ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((((L_GetHitSound*)this)))->GetHitSound())), true);
        reinterpret_cast<::fnv_00588150::FUN_00588150_shell *>((((W_00588150*)((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((((L_GetHitSound*)this)))->GetHitSound())))))->AddCellReferences(pcell);
        ((S00551440*)pcell)->FUN_00551440(true);
    }
    if (((FUN_004ba5a0_shell*)m_pGridCells)->IsOutdoorCell(aiGridX, aiGridY))
    {
        reinterpret_cast<::FUN_00454b90_shell *>((((S454b90*)this)))->AddCellToBuffer(pcell);
        return;
    }
    std::sprintf(pmessage, "Loading cell...%s (%i, %i) (%08X)", ((S451cb0*)pcell)->FUN_00451cb0(),
             reinterpret_cast<::TESObjectCELL *>((((CellH*)pcell)))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((((CellH*)pcell)))->GetCellGridY(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((C_0084e3a0*)pcell)))->FUN_0084e3a0())));
    ((GridCellArrayStandin*)m_pGridCells)->SetCellAt(aiGridX, aiGridY, pcell);
    ((GridCellArray_Target*)m_pGridCells)->FUN_004ba960(m_pLandRootNode, aiGridX, aiGridY);
    pLand = reinterpret_cast<::S00546fb0_Cell *>((((FakeCell*)pcell)))->FUN_00546fb0();
    if (!reinterpret_cast<::LandForm *>((((LAND_x*)pLand)))->FUN_00535b90(true))
        reinterpret_cast<::Worker53 *>((((LAND_x*)pLand)))->FUN_0053a090(0, 0);
    reinterpret_cast<::FUN_0053f440_shell *>((((LAND_x*)reinterpret_cast<::S00546fb0_Cell *>((((FakeCell*)pcell)))->FUN_00546fb0())))->FUN_0053f440();
    reinterpret_cast<::FUN_00451250_shell *>((((S451250*)pcell)))->SetFlag2(reinterpret_cast<::FUN_005471e0_shell *>((pcell))->FUN_005471e0() > extents.x);
    if (*::g_011c7adc.Bool() && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(((MobileObjectCellAccess*)pcell)))->FUN_004518e0() && !reinterpret_cast<::FUN_00451cd0_shell *>((((S451cd0*)pcell)))->FUN_00451cd0())
        ::FUN_0049c860((::MeshInput *)(pcell));
    reinterpret_cast<::fnv_0053fa40::HostMesh53 *>((((LAND_x*)pLand)))->FUN_0053fa40(m_bHasCurrentRegion);
}

struct Setting_S
{
};
enum Sky__SKY_MODE;
struct Sky
{
    void Update(float);
public:
    void SetMode(::Sky__SKY_MODE);
};
struct Animation
{
};
struct TaskQueueInterface
{
public:
    void QueueActorDisarm(bool);
public:
    static ::TaskQueueInterface *GetSingleton();
};
struct FUN_0087aa90_shell
{
    void FUN_0087aa90();
};
struct DialogH
{
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct Zt5Cell
{
};
struct Zt5Grid
{
};
struct Zt5Listener
{
};
void __cdecl FUN_00c468c0(float, float);
void __cdecl FUN_00c74550(float, float);
void FUN_00975080(char*);
struct Zt5TES
{
    void* pVtbl;
    void* m_pGridDistantArray;
    Zt5Grid* m_pGridCells;
    void* m_pLandRootNode;
    void* m_pWaterRootNode;
    void* m_pDistantLandRootNode;
    void* m_pObjectRootNode;
    void* m_pDirectionalLight;
    void* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    void* m_pReferenceCell;
    void* m_ppCellBufferA;
    void* m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    void* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    void* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    void* m_pCurrentClimate;
    Sky* pWeatherSky;
    void FUN_004537c0();
    void FUN_00453550(float afTime);
};

// Advances the global time, updates wind and cell/grid state, runs queued tasks and the sky, then processes the listener and DAT_011e0e80.
// @fnv 0x00453550
void Zt5TES::FUN_00453550(float afTime)
{
    Zt5Cell* pcell = (Zt5Cell*)((void *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)this)))->GetPrevPath()));
    if (pcell)
    {
        FUN_00c468c0(0, 0);
        FUN_00c74550(0, 0);
    }
    else
    {
        float fwindSpeed = reinterpret_cast<::FUN_004536e0_Class *>((pWeatherSky))->GetFieldCC();
        float fwindAngle = reinterpret_cast<::FUN_00453700_shell *>((((Animation*)pWeatherSky)))->FUN_00453700();
        FUN_00c468c0(fwindSpeed, fwindAngle);
        FUN_00c74550(fwindSpeed, fwindAngle);
    }
    ::fnv_00563f30::DAT_011c3c08 += afTime;
    reinterpret_cast<::ActorTaskManager *>(this)->FUN_00453860(true);
    if (pcell)
        reinterpret_cast<::CellUpdateView *>((pcell))->FUN_00551890(::fnv_00563f30::DAT_011c3c08, false);
    else
        reinterpret_cast<::FUN_004ba9a0_shell *>((m_pGridCells))->UpdateCellGrid(::fnv_00563f30::DAT_011c3c08);
    reinterpret_cast<::ActorTaskManager *>(this)->FUN_00453860(false);
    if (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c3ea4)))) > 1)
    {
        TaskQueueInterface* pTaskQueue = ::TaskQueueInterface::GetSingleton();
        ((FUN_0087aa90_shell*)pTaskQueue)->FUN_0087aa90();
    }
    reinterpret_cast<::Processor *>((((::Zt5Listener *)(::FUN_00453720()))))->ProcessRequests();
    if (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c3ea4)))) == 1)
        reinterpret_cast<::fnv_0063ac70::FUN_0063ac70_shell *>((pWeatherSky))->FUN_0063ac70(::fnv_007050d0::FUN_007050d0() ? (*reinterpret_cast<::Twin_0084d030 *>(&::g_timeGlobal)).GetStoredFloatValue() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011c5724)))))) : afTime);
    if (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c3ea4)))) == 1)
        FUN_004537c0();
    FUN_00975080((char*)&(*reinterpret_cast<int *>(&::g_011e0e80)));
}

struct TESForm_0045c6b0
{
    unsigned int FUN_0045c6b0();
};
// Calls the object's virtual method and maps its returned type code to 3, 2, or 1 depending on which case group it falls into.
// @fnv 0x0045c6b0
int FUN_0045c6b0(TESForm_0045c6b0* apObj)
{
    int iResult = 0;
    switch (apObj->FUN_0045c6b0())
    {
    case 0x2a:
    case 0x2b:
        iResult = 3;
        break;
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1f:
    case 0x28:
    case 0x29:
    case 0x2e:
    case 0x2f:
    case 0x32:
    case 0x67:
    case 0x6c:
    case 0x73:
    case 0x74:
        iResult = 2;
        break;
    default:
        iResult = 1;
        break;
    }
    return iResult;
}

struct FUN_00453490_shell
{
    bool FUN_00453490(TESObjectCELL* cell);
};
// Returns false for a null cell, otherwise dispatches to ContainsCell for interior cells or FUN_00454e20 for exterior cells.
// @fnv 0x00453490
bool FUN_00453490_shell::FUN_00453490(TESObjectCELL* cell)
{
    return cell ? ((bool)(unsigned char)(cell->IsCellInterior() ? reinterpret_cast<::fnv_00454bd0::TES *>(this)->ContainsCell(cell) : reinterpret_cast<::fnv_00454e20::CellStand *>(this)->FUN_00454e20(cell))) : false;
}

struct FUN_00455400_sky : Sky
{
};
struct FUN_00455400_cell : TESObjectCELL
{
    bool FUN_00454b10();
};
struct FUN_00455400_tes
{
    void UpdateSkyModeForCell(TESObjectCELL* apCell);
};
// @fnv 0x00455400
void FUN_00455400_tes::UpdateSkyModeForCell(TESObjectCELL* apCell)
{
    if (!((int)(reinterpret_cast<::FUN_00476c90_Class *>((((::FUN_00455400_sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))))->FUN_00476c90())))
        return;
    if (apCell)
    {
        if (((FUN_00455400_cell*)apCell)->IsCellInterior())
        {
            if (((bool)(reinterpret_cast<::fnv_00454b10::TESObjectCELL *>((((FUN_00455400_cell*)apCell)))->GetFakeExterior())))
                reinterpret_cast<::Sky *>((((::FUN_00455400_sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))))->SetMode((::Sky__SKY_MODE)(2));
            else
                reinterpret_cast<::Sky *>((((::FUN_00455400_sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))))->SetMode((::Sky__SKY_MODE)(1));
        }
        else
            reinterpret_cast<::Sky *>((((::FUN_00455400_sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))))->SetMode((::Sky__SKY_MODE)(3));
    }
    else
        reinterpret_cast<::Sky *>((((::FUN_00455400_sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))))->SetMode((::Sky__SKY_MODE)(3));
}

struct GO
{
    int mObject;
    int mObject2;
    int mObject3;
    GO(intptr_t);
    ~GO();
    void operator=(void*);
};
struct FUN_0045ab30_shell : GO
{
    FUN_0045ab30_shell();
};
// Initializes the object by assigning 0 to the base GO and setting mObject2 and mObject3 to 0.
// @fnv 0x0045ab30
FUN_0045ab30_shell::FUN_0045ab30_shell() : GO(0)
{
    ((GO*)this)->operator=(0);
    mObject2 = 0;
    mObject3 = 0;
}

struct GridCellArray
{
    void* Get(unsigned int, unsigned int);
};
struct NiAdditionalGeometryData
{
    static void* __cdecl GetShadowSceneNodeForIndex(int);
};
struct FUN_00b5ddb0_self
{
    void FUN_00b5ddb0(bool, bool);
};
struct CellExt
{
};
struct FUN_00451cf0_shell
{
    char pad[8];
    GridCellArray* cells;
    void FUN_00451cf0();
};
// @fnv 0x00451cf0
void FUN_00451cf0_shell::FUN_00451cf0()
{
    for (unsigned int x = 0; x < *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); x++)
    {
        for (unsigned int y = 0; y < *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); y++)
        {
            CellExt* cell = (CellExt*)*(void**)cells->Get(x, y);
            if (cell && ::FUN_00450ff0((void *)(cell)))
                reinterpret_cast<::s54ba80::Owner *>((cell))->FUN_0054ba80(true);
        }
    }
    ((FUN_00b5ddb0_self*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))->FUN_00b5ddb0(true, true);
}

struct LLD_Cell;

struct LLD_DataHandler
{
    LLD_Cell* GetOrCreateCell(int, int, TESWorldSpace*, bool);
};

struct TESSaveLoadGame
{
};

struct FUN_00451900_shell
{
    TESObjectCELL* FUN_00451900(int aiCellX, int aiCellY);
};

// Converts cell coordinates to grid indices, returns the grid cell if in range, otherwise falls back to the data handler lookup.
// @fnv 0x00451900
TESObjectCELL* FUN_00451900_shell::FUN_00451900(int aiCellX, int aiCellY)
{
    TESObjectCELL* pcell;
    int igridX;
    int igridY;

    igridX = aiCellX - (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x24) -
                        (static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) >> 1));
    igridY = aiCellY - (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x28) -
                        (static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) >> 1));
    pcell = 0;

    if (static_cast<unsigned int>(igridX) < static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) &&
        static_cast<unsigned int>(igridY) < static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) && igridX >= 0 && igridY >= 0)
    {
        pcell = *reinterpret_cast<TESObjectCELL**>(
            reinterpret_cast<GridCellArray*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x08))
                ->Get(static_cast<unsigned int>(igridX), static_cast<unsigned int>(igridY)));
    }

    if (pcell == 0 && ((void *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<TESSaveLoadGame*>(this)))->GetHitSound())) != 0)
    {
        pcell = reinterpret_cast<TESObjectCELL*>(
            reinterpret_cast<LLD_DataHandler*>(g_dataHandler)
                ->GetOrCreateCell(
                    aiCellX, aiCellY,
                    reinterpret_cast<TESWorldSpace*>(((void *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<TESSaveLoadGame*>(this)))->GetHitSound()))), 0));
    }

    return pcell;
}

namespace fnv_00452ed0 {
struct GridCell
{
    TESObjectCELL* pCell;
};

struct TESWorldSpace
{
    TESObjectCELL* GetCellAtGridPosition(int x, int y);
};

struct TESSaveLoadGame
{
};


struct FUN_00452ed0_shell
{
    bool FUN_00452ed0();
};

// @fnv 0x00452ed0
bool FUN_00452ed0_shell::FUN_00452ed0()
{
    int pgc;
    int ix;
    int icellY;
    unsigned int iy;
    GridCell* pcell;
    TESObjectCELL* icellX;

    if (!((::fnv_00452ed0::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<TESSaveLoadGame*>(::g_TES)))->GetHitSound())))
        return false;

    pgc = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x24) -
          (static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) >> 1);
    ix = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x28) -
         (static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) >> 1);

    for (icellY = 0; static_cast<unsigned int>(icellY) < static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))); ++icellY)
    {
        for (iy = 0; iy < static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))); ++iy)
        {
            pcell = static_cast<GridCell*>((*reinterpret_cast<GridCellArray**>(reinterpret_cast<char*>(this) + 8))
                                               ->Get(static_cast<unsigned int>(icellY), iy));

            if (pcell)
            {
                icellX = pcell->pCell;
                if (!icellX)
                {
                    icellX = reinterpret_cast<::TESWorldSpace *>((((::fnv_00452ed0::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<TESSaveLoadGame*>(::g_TES)))->GetHitSound()))))->GetCellAtGridPosition(
                        pgc + static_cast<unsigned int>(icellY), ix + static_cast<unsigned int>(iy));
                }

                if (!icellX || !reinterpret_cast<::fnv_00454e20::CellStand *>((reinterpret_cast<FUN_00453490_shell*>(this)))->FUN_00454e20(icellX))
                    return false;
            }
        }
    }

    return true;
}
}  // namespace fnv_00452ed0


struct FUN_00454fc0_shell
{
    void* vftable;
    void* m_pGridDistantArray;
    unsigned char padding[0x1c];
    int iFirstValue;
    int unknown_28;
    int m_iGridWidth;
    int m_iGridHeight;
    int unknown_34;
    int unknown_38;
    TESObjectCELL** m_ppCellBufferB;

    void CompactQueuedCells();
};
// Moves apCell to the front of the cell list, shifting entries, and unloads the displaced cell via g_dataHandler if one remains.
// @fnv 0x00454e70
void FUN_00454e70_shell::MoveCellToFront(TESObjectCELL* apCell)
{
    TESObjectCELL* pmoveCell;
    reinterpret_cast<::FUN_00454fc0_shell *>((((FUN_00454fc0_cls*)this)))->CompactQueuedCells();
    bool bvisible = ::FUN_00450ff0((void *)(((FUN_004ba5a0_cell_helper*)apCell))) || ((FUN_004523c0_shell*)apCell)->FUN_004523c0();
    if (!m_ppCellBufferB[*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) * *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) - 1])
        bvisible = true;
    pmoveCell = apCell;
    unsigned int n;
    TESObjectCELL* ptempCell;
    for (n = (!bvisible && (unsigned int)reinterpret_cast<::TESObjectCELL *>((((CellStand*)&(*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90)))))->GetCellStandValue() >
                               (unsigned int)(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) * *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))))
                 ? *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) * *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))
                 : 0;
         n < (unsigned int)reinterpret_cast<::TESObjectCELL *>((((CellStand*)&(*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90)))))->GetCellStandValue(); n++)
    {
        ptempCell = m_ppCellBufferB[n];
        m_ppCellBufferB[n] = pmoveCell;
        if (ptempCell == apCell)
            return;
        pmoveCell = ptempCell;
    }
    if (pmoveCell)
    {
        reinterpret_cast<::DeletionDataHandler *>((g_dataHandler))->DeleteObject((::DeletionObject *)(pmoveCell));
        ((FUN_00452e50_class*)this)->FUN_00452e50();
    }
}

// @fnv 0x00454fc0
void FUN_00454fc0_shell::CompactQueuedCells()
{
    unsigned int iattachedCount;
    unsigned int ilastNonQueuedPos;
    int ihalfgrid;

    if (iFirstValue == m_iGridWidth && m_iGridHeight == m_iGridHeight)
        return;

    iattachedCount = *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) * *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))));
    ihalfgrid = static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) >> 1;
    ilastNonQueuedPos = 0;

    {
        unsigned int i;
        int icellX;
        TESObjectCELL* pcell;
        bool bqueuedArea;
        int ideltaY;
        int icellY;
        int ideltaX;

        for (i = iattachedCount; i < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90)))))) - 1; ++i)
        {
            pcell = m_ppCellBufferB[i];
            if (!pcell)
                break;

            icellX = reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(pcell)))->GetCellGridX();
            icellY = reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(pcell)))->GetCellGridY();
            ideltaX = m_iGridWidth - icellX;
            ideltaY = m_iGridHeight - icellY;
            bqueuedArea = false;

            if (ideltaX >= -ihalfgrid)
            {
                if (ideltaX <= ihalfgrid)
                {
                    if (ideltaY >= -ihalfgrid)
                    {
                        if (ideltaY <= ihalfgrid)
                            bqueuedArea = true;
                    }
                }
            }

            if (bqueuedArea && ilastNonQueuedPos != 0)
            {
                std::memmove(&m_ppCellBufferB[ilastNonQueuedPos + 1], &m_ppCellBufferB[ilastNonQueuedPos],
                              (i - ilastNonQueuedPos) * 4);
                m_ppCellBufferB[ilastNonQueuedPos] = pcell;
                i = ilastNonQueuedPos + 1;
                ilastNonQueuedPos = 0;
            }
            else
            {
                ilastNonQueuedPos = i;
            }
        }
    }
}

struct A51BF0Base
{
};

struct NiAVObject : A51BF0Base
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}

    virtual void SetDebugObject(NiAVObject*, int);

    void UpdateSceneObject();
};

void NiAVObject::SetDebugObject(NiAVObject*, int)
{}

void NiAVObject::UpdateSceneObject()
{}

struct Calendar : NiAVObject
{
    Calendar* GetDaysPassed();
public:
    void ResetCachedValues();
public:
    void Update(float);
};

Calendar* Calendar::GetDaysPassed()
{
    return this;
}

struct FUN_00458ef0 : NiAVObject
{
    unsigned char padding[172];

    FUN_00458ef0(float);
};

FUN_00458ef0::FUN_00458ef0(float)
{}

typedef FUN_00458ef0 BSTempNode;

struct FUN_00458e20_shell : Calendar
{
    void FUN_00458e20(NiAVObject*, float);
};

// @fnv 0x00458e20
void FUN_00458e20_shell::FUN_00458e20(NiAVObject* apObject, float afTime)
{
    if (apObject)
    {
        BSTempNode* pTempNode = new FUN_00458ef0(afTime);

        pTempNode->SetDebugObject(apObject, 1);
        ((::Calendar *)(reinterpret_cast<::FUN_009611e0_shell *>((this))->FUN_009611e0()))->SetDebugObject(pTempNode, 1);
        reinterpret_cast<::FUN_00a5a040_Class *>((pTempNode))->FUN_00a5a040();
    }
}


struct G2
{
    void AddHead(int*);
};

struct FUN_00459060_item
{
    unsigned int key;
    short value;
};

struct FUN_00459060_shell
{
    void AddOrAccumulateItem(unsigned int key, short value);
};

// Walks the list at this+0x9c for an item with the given key, adds value to it if found, otherwise allocates a new item and adds it to the head.
// @fnv 0x00459060
void FUN_00459060_shell::AddOrAccumulateItem(unsigned int key, short sValue)
{
    G2* node = reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x9c);

    while (node && *((int **)((void *)(node))))
    {
        FUN_00459060_item* item = reinterpret_cast<FUN_00459060_item*>(*((int **)((void *)(node))));

        if (item->key == key)
        {
            item->value += sValue;
            return;
        }

        node = reinterpret_cast<G2*>(reinterpret_cast<::Callees *>((node))->FUN_00726070());
    }

    FUN_00459060_item* item = new FUN_00459060_item;
    item->key = key;
    item->value = sValue;

    reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x9c)->AddHead(reinterpret_cast<int*>(&item));
}

namespace fnv_00459d20 {
struct Interface
{
};

struct FUN_00456520_Class
{
};

struct IOManager : public FUN_00456520_Class
{
};

struct Calendar
{
    void Update(float);
};

struct LLD_Cell
{
};

struct LLD_PlayerCharacter
{
};

struct SaveManager
{
};

struct FUN_0084e3a0_shell
{
};

struct FUN_00459d20_shell
{
    void MoveToCell(TESObjectCELL*, unsigned int, unsigned int);
};



// Logs the target cell, moves the player into it, times the load, updates the calendar and handles save options.
// @fnv 0x00459d20
void FUN_00459d20_shell::MoveToCell(TESObjectCELL* apCell, unsigned int aiOptions, unsigned int aiTestStartTime)
{
    unsigned int itime;
    unsigned int inumSeconds;
    unsigned int icenterOnCellStartTime;
    unsigned int icenterOnCellStopTime;
    unsigned int inumMinutes;
    unsigned int inumHours;

    if (apCell)
    {
        if (apCell->IsCellInterior())
        {
            ::FUN_0040fbe0(
                );
        }
        else
        {
            ::FUN_0040fbe0(
                );
        }

        icenterOnCellStartTime = ((unsigned int)(::FUN_00457fe0()));
        reinterpret_cast<::fnv_0093db60::PlayerCenterOnCell *>(((*reinterpret_cast<::fnv_00459d20::LLD_PlayerCharacter * *>(&::_g_thePlayer))))->FUN_0093db60((const char *)(0), (::fnv_0093db60::CellS *)(::fnv_00459d20::LLD_Cell *)(reinterpret_cast<LLD_Cell*>(apCell)));
        reinterpret_cast<::FUN_00456520_Class *>(((*reinterpret_cast<::fnv_00459d20::IOManager * *>(&::DAT_01202d98))))->FUN_00456520();
        icenterOnCellStopTime = ((unsigned int)(::FUN_00457fe0()));

        itime = ((unsigned int)(::FUN_00457fe0())) - aiTestStartTime;
        inumHours = itime / 3600000;
        itime = itime - inumHours * 3600000;
        inumMinutes = itime / 60000;
        itime = itime - inumMinutes * 60000;
        inumSeconds = itime / 1000;

        if (apCell->IsCellInterior())
        {
            ::FUN_0040fbe0(
                );
        }
        else
        {
            ::FUN_0040fbe0(
                );
        }

        reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::fnv_00459d20::Calendar *>(&::g_011de7b8))))->Update(::runtimeFloatSettingDefault175);
        reinterpret_cast<::fnv_0096eb40::FUN_0096eb40_cls *>((&(*reinterpret_cast<int *>(&::g_011e0e80))))->FUN_0096eb40();
        reinterpret_cast<::fnv_0096d810::FUN_0096d810_shell *>((&(*reinterpret_cast<int *>(&::g_011e0e80))))->FUN_0096d810();
        reinterpret_cast<::fnv_0096eb40::FUN_0096eb40_cls *>((&(*reinterpret_cast<int *>(&::g_011e0e80))))->FUN_0096eb40();

        switch (aiOptions)
        {
        case 4:
        case 5:
            reinterpret_cast<::TESSaveLoadGame_861f20 *>(((*reinterpret_cast<::fnv_00459d20::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_00861f20(aiOptions);
            break;
        }
    }
}
}  // namespace fnv_00459d20

struct FUN_0045c780_sound
{
};

struct FUN_0045c780_shell
{
    unsigned char unknown_0045c780[8];
    FUN_0045c780_sound* sound;

    void InitSoundGrid();
};

extern const unsigned char DAT_01017830[5][5];

struct FUN_0045c840_shell
{
    void* field_00;
    void* field_04;
    void* field_08;

    void FUN_0045c9e0(unsigned int index1, unsigned int index2, unsigned char value);
    void InitFromMatrix();
};

extern unsigned char DAT_0101784c[];

// @fnv 0x0045c840
void FUN_0045c840_shell::InitFromMatrix()
{
    if (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) == 5)
    {
        for (unsigned int index1 = 0; index1 < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->field_08))->FUN_0084e3a0())); ++index1)
        {
            for (unsigned int index2 = 0; index2 < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->field_08))->FUN_0084e3a0())); ++index2)
            {
                unsigned char value = DAT_0101784c[index1 * 5 + index2];
                this->FUN_0045c9e0(index1, index2, value);
            }
        }
    }
}

struct LandscapeColorData;
struct TESObjectLAND
{
    bool GetLandHeightAtPosition(const NiPoint3& coord, float& height);
public:
    bool FUN_0053f180(const ::LandscapeColorData &, float &);
};

struct FUN_004572e0_shell : public TES
{
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    bool GetLandHeightAt(const NiPoint3& coord, float& height);
};

struct TESCallHelper
{
    bool IsCellBuffered(TESObjectCELL* cell, bool force);
};

extern float DAT_01017824;

bool TESCallHelper::IsCellBuffered(TESObjectCELL* cell, bool force)
{
    return false;
}

// @fnv 0x004572e0
bool FUN_004572e0_shell::GetLandHeightAt(const NiPoint3& coord, float& height)
{
    int icellX = ::FUN_00406d90(coord.x);
    int icellY = ::FUN_00406d90(coord.y);

    if (icellX % 4096 == 0 && coord.x < icellX)
        --icellX;

    if (icellY % 4096 == 0 && coord.y < icellY)
        --icellY;

    icellX >>= 12;
    icellY >>= 12;

    height = DAT_01017824;

    TESObjectCELL* ptestcell = reinterpret_cast<::FUN_00451900_shell *>((this))->FUN_00451900(icellX, icellY);
    if (ptestcell && ((TESCallHelper*)g_TES)->IsCellBuffered(ptestcell, false))
        return reinterpret_cast<::S00546fb0_Cell *>((((FakeCell*)ptestcell)))->FUN_00546fb0()->FUN_0053f180((const ::LandscapeColorData &)(coord), height);

    return false;
}

struct FUN_00451020_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    int m_28;
    void FUN_00451020(int* out, float f);
};

// Writes four fixed-point bounds around m_24/m_28 expanded by half of g_011c63cc, offset by f.
// @fnv 0x00451020
void FUN_00451020_cls::FUN_00451020(int* out, float f)
{
    int iMinX = m_24 - (int)((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
    int cellY = m_28 - (int)((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
    int iMaxX = m_24 + (int)((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
    int top = m_28 + (int)((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);

    out[0] = (int)((float)(iMinX << 12) + f);
    out[3] = (int)((float)(cellY << 12) + f);
    out[2] = (int)((float)((iMaxX << 12) + 0x1000) - f);
    out[1] = (int)((float)((top << 12) + 0x1000) - f);
}


struct FUN_004511e0_cls
{
    bool FUN_004511e0(void* pObj, unsigned char bFlag);
};

// Returns true if pObj is non-null and its state from GetByteAtOffset38 is 5 or 6, or is 2-4 when bFlag is zero.
// @fnv 0x004511e0
bool FUN_004511e0_cls::FUN_004511e0(void* pObj, unsigned char bFlag)
{
    if (pObj == 0)
    {
        return false;
    }
    switch (((int)(reinterpret_cast<::FUN_00450fd0_class *>((pObj))->GetByteAtOffset38())))
    {
    case 2:
    case 3:
    case 4:
        if (bFlag == 0)
        {
            return true;
        }
        break;
    case 5:
    case 6:
        return true;
    }
    return false;
}

// Clear an actor's pending state: if it is flagged, has a current process target and is active,
// notify the target's owner, then reset two state flags.

class ProcessTarget;

class TargetOwner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void OnTargetCleared(ProcessTarget* pTarget);
};

class ProcessTarget
{
  public:
};

class ActorLike
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual ProcessTarget* GetProcessTarget();

};

class ActorStateHandler
{
  public:
    void FUN_00451da0(ActorLike* pActor);
};

// If pActor is flagged, has a process target and is active, notifies the target's owner via OnTargetCleared, then clears pending and active state.
// @fnv 0x00451da0
void ActorStateHandler::FUN_00451da0(ActorLike* pActor)
{
    if (reinterpret_cast<::FUN_00564e60_shell *>((pActor))->FUN_00564e60() && pActor->GetProcessTarget() && reinterpret_cast<::FUN_005651e0_shell *>((pActor))->FUN_005651e0())
    {
        TargetOwner* pOwner = ((::TargetOwner *)(reinterpret_cast<::FUN_009611e0_shell *>((pActor->GetProcessTarget()))->FUN_009611e0()));
        if (pOwner)
            pOwner->OnTargetCleared(pActor->GetProcessTarget());
        reinterpret_cast<::fnv_00570f70::Obj570 *>((pActor))->FUN_00570f70(0);
        reinterpret_cast<::FUN_00565210_shell *>((pActor))->FUN_00565210(false);
    }
}


struct TESBuffer45130 : Zt5TES
{
    void FUN_00455130(TESObjectCELL* apCell);
};

// @fnv 0x00455130
void TESBuffer45130::FUN_00455130(TESObjectCELL* apCell)
{
    if (apCell == 0)
        return;

    int index = 0;
    int last = reinterpret_cast<::TESObjectCELL *>((&(*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90))))->GetCellStandValue() - 1;
    for (; index < last; ++index)
    {
        if (apCell == ((TESObjectCELL**)m_ppCellBufferB)[index])
        {
            TESObjectCELL* nextCell;
            for (; index < last; ++index)
            {
                nextCell = ((TESObjectCELL**)m_ppCellBufferB)[index + 1];
                if (!(nextCell != 0 && ((unsigned char)(::FUN_00450ff0(nextCell)))))
                    break;
                ((TESObjectCELL**)m_ppCellBufferB)[index] = nextCell;
            }
            ((TESObjectCELL**)m_ppCellBufferB)[index] = apCell;
            return;
        }
        else
        {
            if (((TESObjectCELL**)m_ppCellBufferB)[index] == 0)
                return;
        }
    }
}

struct ExtCell : TESObjectCELL
{
    bool GetCellStandValue();
    TESWorldSpace* GetParentWorldSpace();
};
struct BufferSizeSetting
{
};
struct ResettableState
{
    void Reset();
};
struct WorldSpaceView
{
};

struct TES_ExteriorBuffer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    ExtCell** m_ppCellBufferB;

    bool IsCellBuffered(ExtCell* apCell, bool abCheck);
    WorldSpaceView* GetParentWorldSpace();
    unsigned int FUN_00455200(bool abSkipLoaded, TESWorldSpace* apWorld);
};

// @fnv 0x00455200
unsigned int TES_ExteriorBuffer::FUN_00455200(bool abSkipLoaded, TESWorldSpace* apWorld)
{
    unsigned int ItemUpdateArray = 0;
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::TESObjectCELL *>((((BufferSizeSetting*)&(*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90)))))->GetCellStandValue())); i++)
    {
        if (m_ppCellBufferB[i])
        {
            if (!abSkipLoaded || !reinterpret_cast<::TESCallHelper *>(this)->IsCellBuffered((::TESObjectCELL *)(m_ppCellBufferB[i]), true))
            {
                if (!m_ppCellBufferB[i]->GetCellStandValue())
                {
                    if (apWorld && reinterpret_cast<::TESObjectCELL *>((m_ppCellBufferB[i]))->GetParentWorldSpace() != apWorld)
                        continue;
                    reinterpret_cast<::DeletionDataHandler *>((g_dataHandler))->DeleteObject((::DeletionObject *)(m_ppCellBufferB[i]));
                    m_ppCellBufferB[i] = 0;
                    ItemUpdateArray++;
                }
            }
        }
    }
    if (!m_ppCellBufferB[0] && ((::WorldSpaceView *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())) && ((::ResettableState *)(reinterpret_cast<::TESWorldSpace *>((((::WorldSpaceView *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound()))))->GetWorldTerrainManager())))
        reinterpret_cast<::FUN_006fce00_shell *>((((::ResettableState *)(reinterpret_cast<::TESWorldSpace *>((((::WorldSpaceView *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound()))))->GetWorldTerrainManager()))))->FUN_006fce00();
    return ItemUpdateArray;
}

struct FUN_0043d4d0_cls
{
};

struct FUN_00455330_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int* m_38;

    void RemoveEntry(std::uintptr_t value);
};

// @fnv 0x00455330
void FUN_00455330_cls::RemoveEntry(std::uintptr_t value)
{
    unsigned int i;
    for (i = 0; i < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_0043d4d0_cls *>(&::g_011c3e38)))))); i++)
    {
        if (value == m_38[i])
        {
            reinterpret_cast<::DeletionDataHandler *>((::g_dataHandler))->DeleteObject((::DeletionObject *)(::TESObjectCELL *)(reinterpret_cast<TESObjectCELL*>(value)));
            m_38[i] = 0;
            break;
        }
    }
    for (; i < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_0043d4d0_cls *>(&::g_011c3e38)))))) - 1; i++)
    {
        m_38[i] = m_38[i + 1];
    }
    m_38[*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_0043d4d0_cls *>(&::g_011c3e38)))))) - 1] = 0;
    reinterpret_cast<FUN_00452e50_class*>(this)->FUN_00452e50();
}

struct LookupEntry
{
};
struct LookupResult
{
    LookupEntry* entry;
    LookupResult(int initialState);
    ~LookupResult();
};
struct LookupHandler
{
    bool FUN_00456800(void* object, unsigned int limit);
};
// @fnv 0x00456800
bool LookupHandler::FUN_00456800(void* object, unsigned int limit)
{
    LookupResult result(0);
    ::FindTextureByPath((const char *)(object), (::NiTexture **)(::LookupResult *)(&result));
    if (((::LookupEntry *)(::FUN_00559450((int *)&(result)))) != 0)
    {
        if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((::LookupEntry *)(::FUN_00559450((int *)&(result))))))->FUN_00726070())) <= limit + 2)
        {
            ::FUN_00a61f30(((::LookupEntry *)(::FUN_00559450((int *)&(result)))));
            return true;
        }
    }
    return false;
}

struct FUN_004570d0_node;

struct FUN_004570d0_mgr
{
};

struct FUN_004570d0_lst
{
};

struct FUN_004570d0_node
{
};


struct FUN_004570d0_cls
{
    bool FUN_004570d0(void* a1, intptr_t a2, intptr_t a3, float f);
};

// If a1 is non-null, forwards it to the manager's node or, failing that, to every node in the grid, returning whether any call succeeded.
// @fnv 0x004570d0
bool FUN_004570d0_cls::FUN_004570d0(void* a1, intptr_t aiArg2, intptr_t aiArg3, float afValue)
{
    bool result = false;
    if (a1 != 0)
    {
        if (((::FUN_004570d0_node *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::FUN_004570d0_mgr * *>(&::g_TES))))->GetPrevPath())) != 0)
        {
            result = reinterpret_cast<::fnv_00553bf0::S00553bf0 *>((((::FUN_004570d0_node *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::FUN_004570d0_mgr * *>(&::g_TES))))->GetPrevPath()))))->FUN_00553bf0((::fnv_00553bf0::ScriptS *)(a1), (::fnv_00553bf0::NiPoint3 *)(aiArg2), aiArg3, afValue);
        }
        else
        {
            for (unsigned int i = 0; i < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); i++)
            {
                for (unsigned int j = 0; j < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); j++)
                {
                    FUN_004570d0_node* n = *((::FUN_004570d0_node **)(reinterpret_cast<::TES *>((this))->FUN_00457050(i, j)));
                    if (n != 0)
                    {
                        if (reinterpret_cast<::fnv_00553bf0::S00553bf0 *>((n))->FUN_00553bf0((::fnv_00553bf0::ScriptS *)(a1), (::fnv_00553bf0::NiPoint3 *)(aiArg2), aiArg3, afValue))
                        {
                            result = true;
                        }
                    }
                }
            }
        }
    }
    return result;
}

namespace fnv_00457620 {

struct FUN_00457620_gridowner
{
};

struct FUN_00457620_nodeowner
{
};

struct FUN_00457620_cellhost
{
};

struct FUN_00457620_cls
{
    intptr_t FUN_00457620(const float* pos);
};

// @fnv 0x00457620
intptr_t FUN_00457620_cls::FUN_00457620(const float* pos)
{
    int cellX = ::FUN_00406d90(pos[0]);
    int cellY2 = ::FUN_00406d90(pos[1]);
    if (cellX % 4096 == 0 && (float)cellX > pos[0])
    {
        cellX--;
    }
    if (cellY2 % 4096 == 0 && (float)cellY2 > pos[1])
    {
        cellY2--;
    }
    cellX >>= 12;
    cellY2 >>= 12;
    TESObjectCELL* cell5 = ((FUN_00451900_shell*)this)->FUN_00451900(cellX, cellY2);
    if (cell5 != 0)
    {
        if (((unsigned char)(reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_00457620::FUN_00457620_gridowner * *>(&::g_TES))))->IsCellBuffered(cell5, false))))
        {
            return ((int)(reinterpret_cast<::fnv_0053f0e0::TESObjectLAND *>((((::fnv_00457620::FUN_00457620_nodeowner *)(reinterpret_cast<::S00546fb0_Cell *>((((FUN_00457620_cellhost*)cell5)))->FUN_00546fb0()))))->FUN_0053f0e0(*(const ::fnv_0053f0e0::NiPoint3 *)pos)));
        }
    }
    return 0;
}
}  // namespace fnv_00457620

namespace fnv_00457be0 {
struct CellProxy
{
};
struct GridProxy
{
    CellProxy* FUN_004ba490(unsigned int, unsigned int);
};
struct WorldProxy
{
};
struct DataProxy
{
    CellProxy* GetOrCreateCell(int, int, WorldProxy*, bool);
};
struct OwnerProxy
{
    int unk00;
    int unk04;
    GridProxy* grid;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int x;
    int y;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    WorldProxy* world;
    WorldProxy* FUN_004fd3e0();
    void FUN_00457d70(int, WorldProxy*, int);
    void FUN_00457be0(int);
};
// Scans a grid-sized area around x/y, skipping cells by mode, and sums cell values into a total that triggers FUN_00457d70 when nonzero.
// @fnv 0x00457be0
void OwnerProxy::FUN_00457be0(int mode)
{
    unsigned int h, p;
    int a = 0;
    int s = x - ((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
    int i = y - ((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
    for (h = 0; h < (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); ++h)
    {
        for (p = 0; p < (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); ++p)
        {
            switch (mode)
            {
            case 0:
                if (reinterpret_cast<::FUN_004ba5a0_shell *>((grid))->IsOutdoorCell(h, p))
                    continue;
                break;
            case 1:
                if (grid->FUN_004ba490(h, p))
                    continue;
                break;
            }
            if (((::fnv_00457be0::WorldProxy *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())))
            {
                CellProxy* f = 0;
                f = ((::fnv_00457be0::CellProxy *)(reinterpret_cast<::WorldCellLoader *>((world))->FUN_00585b30(s + h, i + p)));
                if (!f)
                    f = (*reinterpret_cast<::fnv_00457be0::DataProxy * *>(&::g_dataHandler))->GetOrCreateCell(s + h, i + p, ((::fnv_00457be0::WorldProxy *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())), true);
                if (f && !::FUN_00450fb0((void *)(f)))
                    a += reinterpret_cast<::FUN_00454400_shell *>((f))->GetRaceListSize();
            }
        }
    }
    if (a)
        FUN_00457d70(1, world, 0);
}
}  // namespace fnv_00457be0

struct FUN_00458f90_shell
{
    void FUN_00458f90();
};
// @fnv 0x00459840
void FUN_00459840_shell::FUN_00459840(uintptr_t a)
{
    reinterpret_cast<::FUN_00458f90_shell *>((this))->FUN_00458f90();
    *reinterpret_cast<unsigned int*>(this + 0x48) = 0x7fffffff;
    *reinterpret_cast<unsigned int*>(this + 0x4c) = 0x7fffffff;
}
struct G2List : G2
{
};

// Walks the list at this+0x9c, deleting each referenced object, then calls FUN_00470470 on the list.
// @fnv 0x00458f90
void FUN_00458f90_shell::FUN_00458f90()
{
    G2* entry = (G2*)((char*)this + 0x9c);
    while (entry != 0 && *((int **)((void *)(entry))) != 0)
    {
        int* object = *((int **)((void *)(entry)));
        delete object;
        entry = (G2*)reinterpret_cast<::Callees *>((entry))->FUN_00726070();
    }
    reinterpret_cast<::FileMatchList *>((((G2List*)((char*)this + 0x9c))))->RemoveAll();
}

struct SaveFormRecord
{
    unsigned int formId;
    unsigned char formType;
    unsigned char flags[4];
};
struct SaveState
{
    SaveFormRecord* FUN_004fd3e0();
};
struct SaveLogSetting
{
    bool* FUN_00408d60();
};
struct SaveForm
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual const char* GetDebugName();
};
struct SaveItemList
{
    unsigned int FUN_005ae380();
};
struct SaveSizeOwner
{
    unsigned short FUN_00459100();
};
// @fnv 0x00459100
unsigned short SaveSizeOwner::FUN_00459100()
{
    unsigned short size = 0;
    unsigned short originalSize = size;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        size += 4;
        size += 2;
    }
    SaveItemList* items3 = ((::SaveItemList *)(reinterpret_cast<::FUN_0050d100_shell *>(this)->FUN_0050d100()));
    size += 4;
    size += items3->FUN_005ae380() * 6;
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 50)
        size += 4;
    if (*(*reinterpret_cast<::SaveLogSetting *>(&::g_011de4e8)).FUN_00408d60())
    {
        SaveFormRecord* record6 = ((::SaveFormRecord *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (record6)
        {
            SaveForm* form = ((::SaveForm *)(::FUN_004839c0(record6->formId)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return size;
}

namespace fnv_00459750 {
struct ArrHead
{
    int count;
};
struct ArrAccessor
{
};
struct ItemX
{
};
struct MgrX
{
};
struct ResX
{
};
struct SubX
{
};
struct FUN_00459750_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    ItemX** m_38;
    ItemX** m_3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    SubX m_C0;
    void ProcessItems(uintptr_t unused);
};
// Iterates m_38 and m_3C, calling FUN_0054ba00 on non-null entries accepted by FUN_004511e0, then calls FUN_00628da0 on the result of m_C0.FUN_00559450().
// @fnv 0x00459750
void FUN_00459750_cls::ProcessItems(uintptr_t unused)
{
    for (int i = 0; i < ((::fnv_00459750::ArrHead *)&(::FUN_0043d4d0((int *)(reinterpret_cast<ArrAccessor*>(&(*reinterpret_cast<char *>(&::g_011c3e38)))))))->count; i++)
    {
        if (m_38[i] != 0)
        {
            if (reinterpret_cast<::TESCallHelper *>((reinterpret_cast<MgrX*>((*reinterpret_cast<unsigned int *>(&::g_TES)))))->IsCellBuffered((::TESObjectCELL *)(m_38[i]), 1))
            {
                reinterpret_cast<::s54ba00::Owner *>((m_38[i]))->FUN_0054ba00();
            }
        }
    }
    for (int j = 0; j < ((::fnv_00459750::ArrHead *)&(::FUN_0043d4d0((int *)(reinterpret_cast<ArrAccessor*>(&(*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90)))))))->count; j++)
    {
        if (m_3C[j] != 0)
        {
            if (reinterpret_cast<::TESCallHelper *>((reinterpret_cast<MgrX*>((*reinterpret_cast<unsigned int *>(&::g_TES)))))->IsCellBuffered((::TESObjectCELL *)(m_3C[j]), 1))
            {
                reinterpret_cast<::s54ba00::Owner *>((m_3C[j]))->FUN_0054ba00();
            }
        }
    }
    reinterpret_cast<::fnv_00628da0::LoadedAreaBound *>((((::fnv_00459750::ResX *)(::FUN_00559450((int *)&(m_C0))))))->FUN_00628da0();
}
}  // namespace fnv_00459750

namespace fnv_00459870 {
struct ArrHead
{
    unsigned int count;
};
struct ArrAccessor
{
};
struct ItemNode
{
};
struct Lookup
{
    ItemNode** FUN_004ba490(unsigned int a, unsigned int b);
};
struct FUN_00459870_cls
{
    int unk00;
    int unk04;
    Lookup* m_08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    ItemNode* m_34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int m_94;
    void ProcessItemNodes();
};
// If m_34 is set, calls FUN_0054ca00 on it with &m_94; otherwise iterates all index pairs via m_08->FUN_004ba490 and calls FUN_0054ca00 on each node.
// @fnv 0x00459870
void FUN_00459870_cls::ProcessItemNodes()
{
    if (m_34 != 0)
    {
        reinterpret_cast<::Shell54ca00 *>((m_34))->FUN_0054ca00((::G2 *)(void *)(&m_94));
    }
    else
    {
        for (unsigned int i = 0; i < ((::fnv_00459870::ArrHead *)&(::FUN_0043d4d0((int *)(reinterpret_cast<ArrAccessor*>(&(*reinterpret_cast<char *>(&::g_011c63cc)))))))->count; i++)
        {
            for (unsigned int j = 0; j < ((::fnv_00459870::ArrHead *)&(::FUN_0043d4d0((int *)(reinterpret_cast<ArrAccessor*>(&(*reinterpret_cast<char *>(&::g_011c63cc)))))))->count; j++)
            {
                ItemNode** tmp = m_08->FUN_004ba490(i, j);
                ItemNode* val = *tmp;
                reinterpret_cast<::Shell54ca00 *>((val))->FUN_0054ca00((::G2 *)(void *)(&m_94));
            }
        }
    }
}
}  // namespace fnv_00459870

struct FUN_00459920_reference
{
};
struct FUN_00459920_grid
{
    FUN_00459920_reference** FUN_004ba490(unsigned int column, unsigned int row);
};
struct FUN_00459920_shell
{
    void* unk00;
    void* unk04;
    FUN_00459920_grid* referenceGrid;
    void FUN_00459920();
};
// @fnv 0x00459920
void FUN_00459920_shell::FUN_00459920()
{
    if (!g_dataHandler)
        return;

    if (((::FUN_00459920_reference *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())) && ::FUN_00450ff0((void *)(((::FUN_00459920_reference *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))))
        reinterpret_cast<::TESObjectCELL *>((((::FUN_00459920_reference *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))))->FUN_005571a0(0);

    for (unsigned int column = 0; column < static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))); ++column)
    {
        for (unsigned int row = 0; row < static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))); ++row)
        {
            FUN_00459920_reference* object;
            FUN_00459920_reference** entry = referenceGrid->FUN_004ba490(column, row);
            object = *entry;
            if (object && ::FUN_00450ff0((void *)(object)))
                reinterpret_cast<::TESObjectCELL *>((object))->FUN_005571a0(0);
        }
    }
}

struct AutoMemContext
{
    int iPrevContext;
    AutoMemContext(int aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
};



struct NiSourceTexture;

template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* apObject);
    ~NiPointer();
    operator T*() const;
};

struct TESWaterForm
{
};

struct WaterFormNode
{
    bool IsEmpty();
};

struct WaterDataHandler
{
};

struct WaterTES
{
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};

struct WaterTextureLoader
{
    void LoadWaterTextures();
};

struct NiObject
{
};

struct ModelPtr
{
    NiObject* m_pObject;
    ModelPtr();
    ~ModelPtr();
    ModelPtr& operator=(NiObject* pObject);
    bool operator==(NiObject* pObject) const;
};

struct ModelCloneNode
{
    ModelPtr m_pRenderedNodeEntry;
    ModelPtr* pClones;
    ModelCloneNode* pNext;
    ModelCloneNode();
};

struct ModelCloneOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    ModelCloneNode* pCloneList;
    void AddCloneEntry(NiObject* m_kModelObjectsItem);
};

// @fnv 0x0045a9a0
void ModelCloneOwner::AddCloneEntry(NiObject* apObject)
{
    if (!apObject)
        return;
    ModelCloneNode* pIter6 = pCloneList;
    while (pIter6)
    {
        if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::ModelPtr &)(pIter6->m_pRenderedNodeEntry))->operator==((int)(apObject)))
            return;
        pIter6 = ((::ModelCloneNode *)(reinterpret_cast<::Twin_0044ddc0 *>((pIter6))->GetName()));
    }
    ModelCloneNode* pNode2 = new ModelCloneNode;
    pNode2->m_pRenderedNodeEntry = apObject;
    reinterpret_cast<::TESRegionGrassObject *>((pNode2))->AssignLandTexture((::TESLandTexture *)(pCloneList));
    pCloneList = pNode2;
    pNode2->pClones = new ModelPtr[3];
    pNode2->pClones[0] = apObject;
    for (int i = 1; i < 3; i++)
    {
        pNode2->pClones[i] = ((::NiObject *)(reinterpret_cast<::CloneSourceA5d6 *>((apObject))->FUN_00a5d680()));
    }
}

struct ListNodeB;
struct SlotB;
struct ObjC;
struct ObjD;

struct ListNodeB
{
    unsigned int unk00;
    SlotB* m_slots;
};
struct SlotB
{
    unsigned int unk00;
};
struct ObjD
{
};
struct ObjC
{
    void Release(SlotB* slot);
    void Attach(SlotB* slot);
};

struct FUN_0045aba0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    ListNodeB* m_b0;
    int FindMatchingNode(void* a1, ObjC* a2);
};

// @fnv 0x0045aba0
int FUN_0045aba0_cls::FindMatchingNode(void* pKey, ObjC* pObj)
{
    int result;
    ListNodeB* node;
    {
        int i;
        pObj->Release(0);
        result = 0;
        node = m_b0;
        while (node != 0)
        {
            if (reinterpret_cast<::_FUN_00822510_Class *>((node))->operator==((int)(pKey)))
            {
                result = 1;
                break;
            }
            node = ((::ListNodeB *)(reinterpret_cast<::Twin_0044ddc0 *>((node))->GetName()));
        }
        if (node != 0 && node->m_slots != 0)
        {
            for (i = 0; i < 3; i++)
            {
                if (((::ObjD *)(::FUN_00559450((int *)&(node->m_slots[i])))) != 0)
                {
                    if (reinterpret_cast<::FUN_009611e0_shell *>((((::ObjD *)(::FUN_00559450((int *)&(node->m_slots[i]))))))->FUN_009611e0() == 0)
                    {
                        pObj->Attach(&node->m_slots[i]);
                        result = 2;
                        break;
                    }
                }
            }
        }
        return result;
    }
}

struct NavMeshHolder
{
    virtual void unkV0();
    virtual void unkV1();
    virtual void unkV2();
    virtual void unkV3();
    virtual void* unkV4(unsigned int flags);
};


struct FUN_0045afb0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    NavMeshHolder* m_pNavMeshMaps;

    void SetNavMeshMaps(NavMeshHolder* arg);
};

// @fnv 0x0045afb0
void FUN_0045afb0_cls::SetNavMeshMaps(NavMeshHolder* pNavMeshMaps)
{
    if (m_pNavMeshMaps != 0)
    {
        if (pNavMeshMaps != 0)
        {
            ::FUN_005b5e40();
        }
        NavMeshHolder* pOldMaps = m_pNavMeshMaps;
        NavMeshHolder* first = pOldMaps;
        (first != 0) ? first->unkV4(1) : 0;
    }
    m_pNavMeshMaps = pNavMeshMaps;
}

namespace fnv_0045bc80 {
struct Obj;
struct BigV
{
    virtual Obj* v0();
    virtual Obj* v1();
    virtual Obj* v2();
    virtual Obj* v3ret();
    virtual Obj* v4();
    virtual Obj* v5();
    virtual Obj* v6();
    virtual Obj* v7();
    virtual Obj* v8();
    virtual Obj* v9();
    virtual Obj* v10();
    virtual Obj* v11();
    virtual Obj* v12();
    virtual Obj* v13();
    virtual Obj* v14();
    virtual Obj* v15();
    virtual Obj* v16();
    virtual Obj* v17();
    virtual Obj* v18();
    virtual Obj* v19();
    virtual Obj* v20();
    virtual Obj* v21();
    virtual Obj* v22();
    virtual Obj* v23();
    virtual Obj* v24();
    virtual Obj* v25();
    virtual Obj* v26();
    virtual Obj* v27();
    virtual Obj* v28();
    virtual Obj* v29();
    virtual Obj* v30();
    virtual Obj* v31();
    virtual Obj* v32();
    virtual Obj* v33();
    virtual Obj* v34();
    virtual Obj* v35();
    virtual Obj* v36();
    virtual Obj* v37();
    virtual Obj* v38();
    virtual Obj* v39();
    virtual Obj* v40();
    virtual Obj* v41();
    virtual Obj* v42();
    virtual Obj* v43();
    virtual Obj* v44();
    virtual Obj* v45();
    virtual Obj* v46();
    virtual Obj* v47bc();
    virtual Obj* v48();
    virtual Obj* v49();
    virtual Obj* v50();
    virtual Obj* v51();
    virtual Obj* v52();
    virtual Obj* v53();
    virtual Obj* v54();
    virtual Obj* v55();
    virtual Obj* v56();
    virtual Obj* v57();
    virtual Obj* v58();
    virtual Obj* v59();
    virtual Obj* v60();
    virtual Obj* v61();
    virtual Obj* v62();
    virtual Obj* v63();
    virtual Obj* v64();
    virtual int v65chk();
    virtual Obj* v66();
    virtual Obj* v67();
    virtual Obj* v68();
    virtual Obj* v69();
    virtual Obj* v70();
    virtual Obj* v71();
    virtual Obj* v72();
    virtual Obj* v73();
    virtual Obj* v74();
    virtual Obj* v75();
    virtual Obj* v76();
    virtual Obj* v77();
    virtual Obj* v78();
    virtual Obj* v79();
    virtual Obj* v80();
    virtual Obj* v81();
    virtual Obj* v82();
    virtual Obj* v83();
    virtual Obj* v84();
    virtual Obj* v85();
    virtual Obj* v86();
    virtual Obj* v87();
    virtual Obj* v88();
    virtual Obj* v89();
    virtual Obj* v90();
    virtual Obj* v91();
    virtual Obj* v92();
    virtual Obj* v93();
    virtual Obj* v94();
    virtual Obj* v95();
    virtual Obj* v96();
    virtual Obj* v97();
    virtual Obj* v98();
    virtual Obj* v99();
    virtual Obj* v100();
    virtual Obj* v101();
    virtual Obj* v102();
    virtual Obj* v103();
    virtual Obj* v104();
    virtual Obj* v105();
    virtual Obj* v106();
    virtual Obj* v107();
    virtual Obj* v108();
    virtual Obj* v109();
    virtual Obj* v110();
    virtual Obj* v111();
    virtual Obj* v112();
    virtual Obj* v113();
    virtual Obj* v114();
    virtual Obj* v115();
    virtual Obj* v116ret();
};
struct Obj
{
    unsigned int FUN_0043b480();
    Obj* FUN_0043b4a0(unsigned int);
    Obj* FUN_00586170();
    Obj* FUN_004ba490(int, int);
    Obj* FUN_00454b30();
    Obj* FUN_006733e0();
};
template <class T> class NiPointer
{
    T* m_p;

  public:
    NiPointer(const NiPointer&);
    ~NiPointer();
};
union SETTING_VALUE
{
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
};
class TESSound
{
  public:
    Obj* FUN_00586170();
};
struct EffectSetting
{
};
Obj* __cdecl FUN_00450b80(int);
struct ThisC
{
    unsigned int unk00;
    unsigned int unk04;
    Obj* m_08;
    char pad0c[0x28];
    Obj* m_34;
    void FUN_0045bc80(unsigned char a1, unsigned char a2);
};
// @fnv 0x0045bc80
void ThisC::FUN_0045bc80(unsigned char a1, unsigned char a2)
{
    Obj* list;
    Obj* formPtr;
    unsigned int ii;
    {
        Obj* head;
        if (!!m_34)
        {
            list = ((::fnv_0045bc80::Obj *)(reinterpret_cast<::TESObjectCELL *>((m_34))->GetCellChildAt(7)));
            if (list != 0)
            {
                for (ii = 0; ii < list->FUN_0043b480(); ii++)
                {
                    formPtr = list->FUN_0043b4a0(ii);
                    if (formPtr != 0)
                    {
                        head = formPtr;
                        if (((BigV*)head)->v65chk() == 0)
                        {
                            reinterpret_cast<::FUN_00528820_shell *>((((::fnv_0045bc80::Obj *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSFaceGenNiNode *>((head))->GetAnimationData()))))))))->ClearField();
                        }
                    }
                }
            }
        }
        else
        {
            Obj* ptr =
                ((::fnv_0045bc80::TESSound *)(reinterpret_cast<::EffectSetting *>((((EffectSetting*)this)))->GetHitSound())) ? ((::fnv_0045bc80::Obj *)(reinterpret_cast<::TESWorldSpace *>((((::fnv_0045bc80::TESSound *)(reinterpret_cast<::EffectSetting *>((((EffectSetting*)this)))->GetHitSound()))))->GetWorldTerrainManager())) : 0;
            if (ptr != 0)
                reinterpret_cast<::fnv_006fd130::FUN_006fd130_shell *>((ptr))->FUN_006fd130();
            unsigned int j;
            for (j = 0; j < (unsigned int)((::fnv_0045bc80::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0045bc80::SettingT_GameSettingCollection_ *>(&::g_011c63cc))))))->i; j++)
            {
                unsigned int k;
                for (k = 0; k < (unsigned int)((::fnv_0045bc80::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0045bc80::SettingT_GameSettingCollection_ *>(&::g_011c63cc))))))->i; k++)
                {
                    Obj* e4 = m_08->FUN_004ba490(j, k);
                    Obj* discB = *(Obj**)e4;
                    if (discB != 0)
                    {
                        Obj* c = ((::fnv_0045bc80::Obj *)(reinterpret_cast<::TESObjectCELL *>((discB))->GetCellChildAt(7)));
                        if (c != 0)
                        {
                            unsigned int l;
                            for (l = 0; l < c->FUN_0043b480(); l++)
                            {
                                Obj* e2 = c->FUN_0043b4a0(l);
                                if (e2 != 0)
                                {
                                    Obj* m = e2;
                                    ((BigV*)m)->v47bc();
                                    reinterpret_cast<::FUN_00528820_shell *>((((::fnv_0045bc80::Obj *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSFaceGenNiNode *>((m))->GetAnimationData()))))))))->ClearField();
                                }
                            }
                        }
                        if (a1 != 0)
                        {
                            c = ((::fnv_0045bc80::Obj *)(reinterpret_cast<::TESObjectCELL *>((discB))->GetCellChildAt(2)));
                            unsigned int nxtBase;
                            for (nxtBase = 0; nxtBase < c->FUN_0043b480(); nxtBase++)
                            {
                                Obj* e3 = c->FUN_0043b4a0(nxtBase);
                                if (e3 != 0)
                                {
                                    Obj* h3 = e3;
                                    reinterpret_cast<::FUN_00528820_shell *>((((::fnv_0045bc80::Obj *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSFaceGenNiNode *>((h3))->GetAnimationData()))))))))->ClearField();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    Obj* it2 = ((::fnv_0045bc80::Obj *)(reinterpret_cast<::S_FUN_0045bc00 *>((FUN_00450b80(0)))->FUN_0045bc00(6)));
    Obj* pList = it2 ? ((BigV*)it2)->v3ret() : 0;
    if (pList != 0)
    {
        unsigned int i2;
        for (i2 = 0; i2 < pList->FUN_0043b480(); i2++)
        {
            Obj* cell = pList->FUN_0043b4a0(i2);
            if (cell != 0)
            {
                Obj* h4 = cell;
                reinterpret_cast<::FUN_00528820_shell *>((((::fnv_0045bc80::Obj *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSFaceGenNiNode *>((h4))->GetAnimationData()))))))))->ClearField();
            }
        }
    }
    if (((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_00454b30_class *>((FUN_00450b80(0)))->FUN_00454b30())) != 0)
    {
        Obj* z = ((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::TESTopicInfoData *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_00454b30_class *>((FUN_00450b80(0)))->FUN_00454b30()))))->GetLinkToList()))))));
        while (z != 0)
        {
            Obj* next6c = *(Obj**)((::fnv_0045bc80::Obj *)(reinterpret_cast<::ListStandIn *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::TESTopicInfoData *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_00454b30_class *>((FUN_00450b80(0)))->FUN_00454b30()))))->GetLinkToList()))))->FUN_0057cbe0((int **)(::fnv_0045bc80::Obj **)(&z))));
            if (next6c != 0)
                reinterpret_cast<::FUN_0045c4a0_class *>((next6c))->ClearField40();
        }
        Obj* obj2 = ((::fnv_0045bc80::Obj *)(reinterpret_cast<::BGSCameraPath *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_00454b30_class *>((FUN_00450b80(0)))->FUN_00454b30()))))->GetShotList()));
        if (((unsigned char)(reinterpret_cast<::FUN_0076b610_Class *>((obj2))->FUN_0076b610())) == 0)
        {
            if (a2 != 0)
            {
                Obj* temp68 = ((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(obj2))));
                while (temp68 != 0)
                {
                    NiPointer<NiAVObject> smart(*(NiPointer<NiAVObject>*)((::fnv_0045bc80::Obj *)(reinterpret_cast<::ListStandIn *>((obj2))->FUN_0057cbe0((int **)(::fnv_0045bc80::Obj **)(&temp68)))));
                    if (((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart))))) != 0)
                    {
                        ((BigV*)((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart))))))->v47bc();
                        reinterpret_cast<::FUN_0045c570_Class *>((((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart)))))))->FUN_0045c570(3);
                        reinterpret_cast<::FUN_0045c4e0_This *>((((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart)))))))->SetFieldCC(0);
                        Obj* v = ((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSMultiBoundRoom *>((((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart)))))))->FUN_006ab360()))))));
                        while (!!v)
                        {
                            Obj* nxt = *(Obj**)((::fnv_0045bc80::Obj *)(reinterpret_cast<::ListStandIn *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSMultiBoundRoom *>((((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart)))))))->FUN_006ab360()))))->FUN_0057cbe0((int **)(::fnv_0045bc80::Obj **)(&v))));
                            if (nxt != 0)
                            {
                                reinterpret_cast<::FUN_0045c4a0_class *>((nxt))->ClearField40();
                                if (((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_004f9bf0_shell *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_0045c4c0_cls *>((nxt))->FUN_0045c4c0()))))->FUN_004f9bf0())) != 0)
                                {
                                    reinterpret_cast<::FUN_00c47980_cls *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_004f9bf0_shell *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_0045c4c0_cls *>((nxt))->FUN_0045c4c0()))))->FUN_004f9bf0()))))->InitFromArg((::FUN_00c47980_arg *)(0));
                                }
                            }
                        }
                        Obj* inner = ((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((::fnv_0045bc80::Obj *)(::FUN_00514f30((std::intptr_t)(((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart)))))))))))));
                        while (inner != 0)
                        {
                            Obj* nxt2 =
                                *(Obj**)((::fnv_0045bc80::Obj *)(reinterpret_cast<::ListStandIn *>((((::fnv_0045bc80::Obj *)(::FUN_00514f30((std::intptr_t)(((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)(void*)&smart)))))))))))->FUN_0057cbe0((int **)(::fnv_0045bc80::Obj **)(&inner))));
                            if (nxt2 != 0)
                                reinterpret_cast<::FUN_0045c4a0_class *>((nxt2))->ClearField40();
                        }
                    }
                }
            }
        }
    }
    {
        Obj* base;
        std::intptr_t ret;
        Obj* node;
        if (((Obj*)::FUN_0070ec90((char*)this)) != 0)
        {
            node = 0;
            base = ((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<struct ::FUN_005a8080 *>((((Obj*)::FUN_0070ec90((char*)this))))->GetField()))))));
            ret = 0;
            while (0 != base)
            {
                ret = ((std::intptr_t)(reinterpret_cast<::FUN_007b52d0_cls *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<struct ::FUN_005a8080 *>((((Obj*)::FUN_0070ec90((char*)this))))->GetField()))))->DereferenceIfNotNull((int **)(base))));
                if (base != 0)
                {
                    node = *(Obj**)((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_006317a0_struct *>((((::fnv_0045bc80::Obj *)(reinterpret_cast<struct ::FUN_005a8080 *>((((Obj*)::FUN_0070ec90((char*)this))))->GetField()))))->AddEight((std::intptr_t)(base))));
                    Obj* lst = ((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)((char*)node + 0x24))))));
                    std::uintptr_t nxtL = 0;
                    while (lst != 0)
                    {
                        nxtL = ((std::intptr_t)(reinterpret_cast<::FUN_007b52d0_cls *>((((Obj*)((char*)node + 0x24))))->DereferenceIfNotNull((int **)(lst))));
                        if (lst != 0)
                        {
                            Obj* theItem = *(Obj**)((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_006317a0_struct *>((((Obj*)((char*)node + 0x24))))->AddEight((std::intptr_t)(lst))));
                            std::intptr_t pass = ((std::intptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((theItem))->FUN_007af430()));
                            Obj* vTmp = ((BigV*)theItem)->v116ret();
                            if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(char *)(&(*reinterpret_cast<char *>(&::g_01202e74))), (const ::fnv_0045bad0::NiObject *)(::fnv_0045bc80::Obj *)(vTmp->FUN_0043b4a0(0))))
                            {
                                Obj* res = vTmp->FUN_0043b4a0(0);
                                reinterpret_cast<::FUN_00528820_shell *>((((::fnv_0045bc80::Obj *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSFaceGenNiNode *>((res))->GetAnimationData()))))))))->ClearField();
                            }
                        }
                        lst = (Obj*)nxtL;
                    }
                }
                base = (Obj*)ret;
            }
            node = ((Obj*)::FUN_0070ec90((char*)this))->FUN_006733e0();
            if (node != 0)
            {
                Obj* lst2 = ((::fnv_0045bc80::Obj *)(::FUN_00559450((int *)(((Obj*)((char*)node + 0x24))))));
                std::intptr_t nxt2 = 0;
                while (lst2 != 0)
                {
                    nxt2 = ((std::intptr_t)(reinterpret_cast<::FUN_007b52d0_cls *>((((Obj*)((char*)node + 0x24))))->DereferenceIfNotNull((int **)(lst2))));
                    if (lst2 != 0)
                    {
                        Obj* itemB = *(Obj**)((::fnv_0045bc80::Obj *)(reinterpret_cast<::FUN_006317a0_struct *>((((Obj*)((char*)node + 0x24))))->AddEight((std::intptr_t)(lst2))));
                        std::intptr_t has = ((std::intptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((itemB))->FUN_007af430()));
                        Obj* top = ((BigV*)itemB)->v116ret();
                        if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(char *)(&(*reinterpret_cast<char *>(&::g_01202e74))), (const ::fnv_0045bad0::NiObject *)(::fnv_0045bc80::Obj *)(top->FUN_0043b4a0(0))))
                        {
                            Obj* sub = top->FUN_0043b4a0(0);
                            reinterpret_cast<::FUN_00528820_shell *>((((::fnv_0045bc80::Obj *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_0045bc80::Obj *)(reinterpret_cast<::BSFaceGenNiNode *>((sub))->GetAnimationData()))))))))->ClearField();
                        }
                    }
                    lst2 = (Obj*)nxt2;
                }
            }
        }
    }
}
}  // namespace fnv_0045bc80

struct S_0045c8d0_Obj;
struct S_0045c8d0_Tgt
{
    void FUN_00441130(unsigned int a, unsigned char b);
};
struct S_0045c8d0_Obj
{
};
struct S_0045c8d0_Virt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual S_0045c8d0_Obj* v6();
};
struct S_0045c8d0_Child
{
    S_0045c8d0_Virt* FUN_0043b4a0(int a);
};
struct S_0045c8d0_Cell
{
};
struct S_0045c8d0_R
{
    S_0045c8d0_Cell* unk0;
};
struct S_0045c8d0_A
{
    S_0045c8d0_R* FUN_004ba490(unsigned int a, unsigned int b);
};
struct S_0045c8d0
{
    int unk0;
    int unk4;
    S_0045c8d0_A* unk8;
    void FUN_0045c8d0(unsigned int a, unsigned int b, unsigned char c);
};
// @fnv 0x0045c780
void FUN_0045c780_shell::InitSoundGrid()
{
    if (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) == 5)
    {
        unsigned int index1;
        for (index1 = 0; index1 < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->sound))->FUN_0084e3a0())); ++index1)
        {
            unsigned int index2;
            for (index2 = 0; index2 < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->sound))->FUN_0084e3a0())); ++index2)
            {
                unsigned char value = 0;
                if (DAT_011c3c0c)
                {
                    if (index1 == 2 && index2 == 2)
                        value = 1;
                }
                else
                {
                    value = DAT_01017830[index1][index2];
                }

                reinterpret_cast<::S_0045c8d0 *>((this))->FUN_0045c8d0(index1, index2, value);
            }
        }
    }
}
// @fnv 0x0045c8d0
void S_0045c8d0::FUN_0045c8d0(unsigned int a, unsigned int b, unsigned char c)
{
    S_0045c8d0_R* r7 = unk8->FUN_004ba490(a, b);
    if (r7 && r7->unk0)
    {
        for (int i = 0; i < 4; i++)
        {
            S_0045c8d0_Child* child = ((::S_0045c8d0_Child *)(reinterpret_cast<::FUN_0045c9a0_shell *>((r7->unk0))->GetCellNodeAt(i)));
            S_0045c8d0_Obj* objVal = ((int)(reinterpret_cast<::S_FUN_0045bc00 *>((child))->FUN_0045bc00(0))) ? child->FUN_0043b4a0(0)->v6() : 0;
            if (objVal)
            {
                S_0045c8d0_Tgt* t = ((::S_0045c8d0_Tgt *)(reinterpret_cast<::FUN_00a59d30_C *>((objVal))->FUN_00a59d30(FUN_00438220())));
                t->FUN_00441130(0x2e, c);
            }
        }
    }
}

namespace fnv_0045c9e0 {
struct FUN_0043b4a0_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual struct FUN_00a59d30_shell* FUN_Virtual0x18();
};

struct FUN_0045bc00_shell
{
    FUN_0043b4a0_Target* FUN_0043b4a0(int);
};


struct FUN_00441130_shell
{
    void FUN_00441130(int, bool);
};

struct FUN_00a59d30_shell
{
};

struct FUN_0045c9e0_shell
{
    void* unk00;
    void* unk04;
    GridCellArray* cells;
    void FUN_0045c9e0(int x, int y, bool flag);
};

// @fnv 0x0045c9e0
void FUN_0045c9e0_shell::FUN_0045c9e0(int x, int y, bool flag)
{
    TESObjectCELL** cell = (TESObjectCELL**)cells->Get(x, y);
    if (cell && *cell)
    {
        int i;
        FUN_00a59d30_shell* obj;
        for (i = 0; i < 4; i++)
        {
            NiAVObject* node = ((FUN_0045c9a0_shell*)*cell)->GetCellNodeAt(i);
            obj = ((int)(reinterpret_cast<::S_FUN_0045bc00 *>((((FUN_0045bc00_shell*)node)))->FUN_0045bc00(0)))
                      ? ((FUN_0045bc00_shell*)node)->FUN_0043b4a0(0)->FUN_Virtual0x18()
                      : 0;
            if (obj)
            {
                FUN_00441130_shell* target = ((::fnv_0045c9e0::FUN_00441130_shell *)(reinterpret_cast<::FUN_00a59d30_C *>((obj))->FUN_00a59d30((int)(((void *)(::FUN_00438220()))))));
                target->FUN_00441130(0x34, !flag);
            }
        }
    }
}
}  // namespace fnv_0045c9e0

struct FUN_0045cb90_inner
{
    unsigned int m_00;
    unsigned int m_04;
};

struct FUN_0045cb90_cls
{
    char unk00[0x28];
    FUN_0045cb90_inner* m_28;

    bool FUN_0045cb90();
};

// Returns true when m_28 is non-null and its m_04 field is non-zero.
// @fnv 0x0045cb90
bool FUN_0045cb90_cls::FUN_0045cb90()
{
    return (m_28 != 0 && m_28->m_04 != 0) ? true : false;
}

class B45CDA0Cell
{
  public:
};

struct B45CDA0GridCell
{
    B45CDA0Cell* m_pkCell;
};

class B45CDA0GridCellArray
{
  public:
    B45CDA0GridCell* Get(unsigned int uiX, unsigned int uiY);
};

class B45CDA0TES
{
  public:
    int unk00;
    int unk04;
    B45CDA0GridCellArray* m_pkGridCells;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    B45CDA0Cell* m_pkInteriorCell;

    void FUN_0045cda0();
};

// Calls FUN_00558c90 on the interior cell if set, otherwise on every non-null cell in the grid cell array.
// @fnv 0x0045cda0
void B45CDA0TES::FUN_0045cda0()
{
    if (m_pkInteriorCell)
    {
        reinterpret_cast<::fnv_00558c90::FUN_00558c90_shell *>((m_pkInteriorCell))->FUN_00558c90();
    }
    else
    {
        for (unsigned int uiX = 0; uiX < (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); uiX++)
        {
            for (unsigned int uiY = 0; uiY < (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); uiY++)
            {
                B45CDA0GridCell* pkGridCell = m_pkGridCells->Get(uiX, uiY);
                B45CDA0Cell* pkCell = pkGridCell->m_pkCell;
                if (pkCell)
                    reinterpret_cast<::fnv_00558c90::FUN_00558c90_shell *>((pkCell))->FUN_00558c90();
            }
        }
    }
}

struct Grid4512
{
    virtual void v0();
    virtual void v1();
    virtual void Reset();
    virtual void v3();
    virtual void SetGridPosition(int x, int y);
};
struct Terrain4512
{
    void FUN_006fca90(void* position);
};
struct World4512
{
    Terrain4512* FUN_00586170();
};
struct Player4512
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* GetPosition(int which);
};
struct FUN_00c3dfa0_Class
{
};
struct NiPoint3Ex : NiPoint3
{
    NiPoint3Ex(float, float, float);
};
void FUN_0057d0a0(NiPoint3Ex position, NiPoint3Ex direction, float scale);
struct Setting4512
{
    float* FUN_00403e20();
};
class TESForm;
class TESWorldSpace;
struct Interface
{
public:
    static bool IsWorldSpaceEnabled(::TESWorldSpace *);
public:
    static void SetQuestTarget(::TESForm *, bool);
public:
    static bool IsGamePaused();
};
struct Process4512
{
};
struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool isMultiThreaded;
    bool flag6;
    bool flag7;
    bool flag8;
    NiUpdateData(float, bool, bool);
};
struct Node4512
{
};
struct Data4512
{
};
extern bool DAT_011c3ed0;
struct TES4512
{
    int unk00;
    int unk04;
    Grid4512* grid;
    int unk0c;
    Node4512* root;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int gridX;
    int gridY;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    World4512* world;
    void RefreshGrid();
    bool GetLandHeightAt(const NiPoint3&, float&);
    void FUN_00455490();
    void FUN_004512c0(const NiPoint3* position, bool reload);
};
// @fnv 0x004512c0
void TES4512::FUN_004512c0(const NiPoint3* position, bool reload)
{
    if (!::g_dataHandler || ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        return;
    if (DAT_011c3ed0)
        return;
    DAT_011c3ed0 = true;
    if (reload)
    {
        grid->Reset();
        FUN_00451520(1);
        FUN_00451570(0);
        reinterpret_cast<::FUN_006fce00_shell *>((((::Terrain4512 *)(reinterpret_cast<::TESWorldSpace *>((world))->GetWorldTerrainManager()))))->FUN_006fce00();
        reinterpret_cast<::BGSTerrainManager *>((((::Terrain4512 *)(reinterpret_cast<::TESWorldSpace *>((world))->GetWorldTerrainManager()))))->FUN_006fca90((*(const ::NiPoint3 *)((*reinterpret_cast<::Player4512 * *>(&::_g_thePlayer))->GetPosition(15))), {});
        grid->SetGridPosition(gridX, gridY);
        reinterpret_cast<::TES_ExteriorBuffer *>(this)->FUN_00455200(false, 0);
        reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(false);
        reinterpret_cast<::fnv_00457be0::OwnerProxy *>(this)->FUN_00457be0(false);
        RefreshGrid();
        reinterpret_cast<::IOManager *>(((*reinterpret_cast<::FUN_00c3dfa0_Class * *>(&::DAT_01202d98))))->FUN_00c3dfa0(4);
        NiPoint3Ex point(position->x, position->y, 0.0f);
        reinterpret_cast<::FUN_004572e0_shell *>(this)->GetLandHeightAt(*position, point.z);
        FUN_00451590(0);
        FUN_0057d0a0(point, (*reinterpret_cast<::NiPoint3Ex *>(&::DAT_011a9478)), 1.0f);
        FUN_00451590(1);
        if (!reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(this)->FUN_00451530())
            reinterpret_cast<::FaderManager *>((::DAT_011d8804))->AddFader((::FADER_ENUM)(1), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting4512 *>(&::originalRuntimeFloatSetting16)))))), false);
        reinterpret_cast<::fnv_00459870::FUN_00459870_cls *>(this)->ProcessItemNodes();
        reinterpret_cast<::ThisCls *>((((Process4512*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_00972d30();
        reinterpret_cast<::ProcessLists *>((((Process4512*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->UpdateHighProcess();
    }
    else
    {
        grid->SetGridPosition(gridX, gridY);
        reinterpret_cast<::fnv_00457be0::OwnerProxy *>(this)->FUN_00457be0(true);
        RefreshGrid();
    }
    FUN_00455490();
    NiUpdateData update(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((root))->FUN_00a59c60((std::intptr_t)&(update));
    reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(false);
    reinterpret_cast<::FUN_00460360_shell *>((((Data4512*)::g_dataHandler)))->ProcessAllFiles();
    DAT_011c3ed0 = false;
}

struct FUN_004516d0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    GridCellArray* cells;
    MobileObjectCellAccess** FUN_004516d0();
};

// @fnv 0x004516d0
MobileObjectCellAccess** FUN_004516d0_shell::FUN_004516d0()
{
    MobileObjectCellAccess** foundCell = 0;
    unsigned int gridSize = *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))));
    unsigned int center = gridSize >> 1;
    unsigned int centerCoordinate = center;
    for (unsigned int radius = 0; radius < center; ++radius)
    {
        if (radius == 0)
        {
            MobileObjectCellAccess** cell = (MobileObjectCellAccess**)cells->Get(centerCoordinate, centerCoordinate);
            if (cell && *cell && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)((*cell)))->FUN_004518e0())
                foundCell = cell;
        }
        else
        {
            unsigned int yMax = centerCoordinate + radius;
            unsigned int xMax = yMax;
            unsigned int yMin = centerCoordinate - radius;
            unsigned int xMin = yMin;
            for (unsigned int x = xMin; x <= xMax; ++x)
            {
                MobileObjectCellAccess** cell = (MobileObjectCellAccess**)cells->Get(x, yMax);
                if (cell && *cell && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)((*cell)))->FUN_004518e0())
                {
                    foundCell = cell;
                    break;
                }
                else
                {
                    cell = (MobileObjectCellAccess**)cells->Get(x, yMin);
                    if (cell && *cell && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)((*cell)))->FUN_004518e0())
                    {
                        foundCell = cell;
                        break;
                    }
                }
            }
            if (!foundCell)
            {
                for (unsigned int y = yMin + 1; y < yMax; ++y)
                {
                    MobileObjectCellAccess** cell = (MobileObjectCellAccess**)cells->Get(xMin, y);
                    if (cell && *cell && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)((*cell)))->FUN_004518e0())
                    {
                        foundCell = cell;
                        break;
                    }
                    else
                    {
                        cell = (MobileObjectCellAccess**)cells->Get(xMax, y);
                        if (cell && *cell && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)((*cell)))->FUN_004518e0())
                        {
                            foundCell = cell;
                            break;
                        }
                    }
                }
            }
        }
        if (foundCell)
            break;
    }
    return foundCell;
}

class TESBoundObject
{
  public:
    virtual void Reserved();
    unsigned int FUN_00401170();
};
struct TreeDimensions
{
    float x;
    float y;
};
class TESObjectTREE : public TESBoundObject
{
  public:
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual double GetTreeScale(float);
};
struct AttachNode;
struct AttachRoot
{
};
AttachRoot* __cdecl FUN_00450b80(int);
struct AttachNode
{
    struct NodeOwner* FUN_009611e0();
};
struct NodeOwner
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Release(AttachNode*);
};
struct AttachRef
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual bool IsActor();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual void Reserved111();
    virtual void Reserved112();
    virtual void Reserved113();
    virtual AttachNode* GetNode(int);
    virtual void Reserved115();
    virtual void Reserved116();
    virtual void Reserved117();
    virtual void Reserved118();
    virtual void Reserved119();
    virtual void Reserved120();
    virtual void Reserved121();
    virtual void Reserved122();
    virtual void Reserved123();
    virtual void Reserved124();
    virtual NiPoint3* GetPoint(unsigned int);
    virtual void Reserved126();
    virtual void Reserved127();
    virtual void Reserved128();
    virtual void Reserved129();
    virtual void Reserved130();
    virtual void Reserved131();
    virtual void Reserved132();
    virtual void Reserved133();
    virtual void Reserved134();
    virtual void Reserved135();
    virtual bool IsSpecialA();
    virtual bool IsSpecialB();
    virtual void Reserved138();
    virtual void Reserved139();
    virtual void Reserved140();
    virtual void Reserved141();
    virtual void Reserved142();
    virtual void Reserved143();
    virtual void Reserved144();
    virtual void Reserved145();
    virtual void Reserved146();
    virtual void Reserved147();
    virtual void Reserved148();
    virtual void Reserved149();
    virtual void Reserved150();
    virtual void Reserved151();
    virtual void Reserved152();
    virtual void Reserved153();
    virtual void Reserved154();
    virtual void Reserved155();
    virtual void Reserved156();
    virtual void Reserved157();
    virtual void Reserved158();
    virtual void Reserved159();
    virtual void Reserved160();
    virtual void Reserved161();
    virtual void Reserved162();
    virtual void Reserved163();
    virtual void Reserved164();
    virtual void Reserved165();
    virtual void Reserved166();
    virtual void Reserved167();
    virtual void Reserved168();
    virtual void Reserved169();
    virtual void Reserved170();
    virtual void Reserved171();
    virtual void Reserved172();
    virtual void Reserved173();
    virtual void Reserved174();
    virtual void Reserved175();
    virtual void Reserved176();
    virtual void Reserved177();
    virtual void Reserved178();
    virtual void Reserved179();
    virtual void Reserved180();
    virtual void Reserved181();
    virtual void Reserved182();
    virtual void Reserved183();
    virtual void Reserved184();
    virtual void Reserved185();
    virtual void Reserved186();
    virtual void Reserved187();
    virtual void Reserved188();
    virtual void Reserved189();
    virtual void Reserved190();
    virtual void Reserved191();
    virtual void Reserved192();
    virtual void HandleA();
    virtual void HandleB();
};
struct AttachCell
{
    void FUN_00547ad0(NiPoint3);
};
struct AttachContext
{
};

struct AttachmentHandler
{
    void FUN_00451ef0(AttachRef*, AttachCell*, AttachRef*, bool);
};
namespace GridRefresh {
struct Profile
{
    int unk00;
    Profile(int, int, const char*, int);
    ~Profile();
};
struct Setting
{
};
struct Update
{
    float time;
    int flags, unk08;
    Update(float, int, int);
};
struct Node
{
};
struct Cell
{
};
struct Game
{
};
struct Loader
{
};
struct Main
{
};
struct World
{
};
struct Cells
{
    Cell* GetOrCreateCell(int, int, World*, int);
};
struct Queue
{
};
struct CellHandle
{
    void FUN_005ae3d0();
};
struct Grid
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int centerX, centerY;
    World* FUN_004fd3e0();
    void RefreshGrid();
};
// @fnv 0x00452ff0
void Grid::RefreshGrid()
{
    Profile profile3(26, 1, ::DAT_01017874, 2262);
    int originX = centerX - (*((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc)))))) >> 1);
    int originY = centerY - (*((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc)))))) >> 1);
    int count = 0;
    bool defer = false;
    if (::Interface::IsGamePaused())
        defer = true;
    bool loading4 = ::Interface::IsGamePaused();
    reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
    reinterpret_cast<::FUN_00453500_shell *>(((*reinterpret_cast<::GridRefresh::Loader * *>(&::g_BGSSaveLoadGame))))->FUN_00453500(true);
    if (((::GridRefresh::Queue *)(::FUN_00451010())))
        reinterpret_cast<::C00c66300 *>((((::GridRefresh::Queue *)(::FUN_00451010()))))->FUN_00c66300();
    for (unsigned int x = 0; x < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc)))))); ++x)
    {
        for (unsigned int y = 0; y < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc)))))); ++y)
        {
            reinterpret_cast<::TES_00451a50 *>(this)->FUN_00451a50(x, y, originX + x, originY + y);
            Cell* cell = (*reinterpret_cast<::GridRefresh::Cells * *>(&::g_dataHandler))->GetOrCreateCell(originX + x, originY + y, ((::GridRefresh::World *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())), 0);
            if (reinterpret_cast<::FUN_00453490_shell *>(((*reinterpret_cast<::GridRefresh::Main * *>(&::g_TES))))->FUN_00453490((::TESObjectCELL *)(cell)))
                reinterpret_cast<::FUN_00454b90_shell *>(this)->AddCellToBuffer((::TESObjectCELL *)(cell));
            if (loading4 || (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition()))
            {
                ++count;
                float percent =
                    (double)count / (*((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc)))))) * *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc))))))) * ::g_d100;
                if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
                    reinterpret_cast<::LLD_TESHelper *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_00861ea0();
            }
        }
    }
    if (((::GridRefresh::Queue *)(::FUN_00451010())))
        reinterpret_cast<::C6B540Manager *>((((::GridRefresh::Queue *)(::FUN_00451010()))))->FUN_00c6b540(0);
    reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(false);
    if (((bool)(reinterpret_cast<::FUN_008727b0_Class *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_008727b0())))
    {
        bool first = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
        bool second6 = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
        reinterpret_cast<::Cls *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_00858af0((::EntryListNode *)(0), (::Entry *)(0), 0);
        reinterpret_cast<::FUN_0085f850_class *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_0085f850(0);
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(second6);
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(first);
    }
    reinterpret_cast<::FUN_00453500_shell *>(((*reinterpret_cast<::GridRefresh::Loader * *>(&::g_BGSSaveLoadGame))))->FUN_00453500(false);
    if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::GridRefresh::Loader * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
        reinterpret_cast<::fnv_008492b0::FUN_008492b0_shell *>(((*reinterpret_cast<::GridRefresh::Loader * *>(&::g_BGSSaveLoadGame))))->ResetLoadBuffers(0);
    if (((::GridRefresh::Queue *)(::FUN_00451010())))
        reinterpret_cast<::C00c66300 *>((((::GridRefresh::Queue *)(::FUN_00451010()))))->FUN_00c66300();
    for (unsigned int x2 = 0; x2 < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc)))))); ++x2)
    {
        for (unsigned int y2 = 0; y2 < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting *>(&::g_011c63cc)))))); ++y2)
        {
            if (((::GridRefresh::World *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())))
            {
                Cell* cell2 = (*reinterpret_cast<::GridRefresh::Cells * *>(&::g_dataHandler))->GetOrCreateCell(originX + x2, originY + y2, ((::GridRefresh::World *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())), 0);
                if (cell2)
                {
                    if (((int)(reinterpret_cast<::FUN_00450fd0_class *>((cell2))->GetByteAtOffset38())) == 5)
                    {
                        reinterpret_cast<::SceneB54 *>((cell2))->FUN_0054bcf0(!defer);
                        reinterpret_cast<::FUN_00454b90_shell *>(this)->AddCellToBuffer((::TESObjectCELL *)(cell2));
                        Node* node = ((::GridRefresh::Node *)(reinterpret_cast<::FUN_00545cf0_Cls *>((cell2))->GetOrCreateWidget()));
                        reinterpret_cast<::FUN_00a5a040_Class *>((node))->FUN_00a5a040();
                        if (!reinterpret_cast<::FUN_00453470_shell *>((node))->FUN_00453470())
                        {
                            Update update(0.0f, 0, 0);
                            reinterpret_cast<::FUN_00a59c60_cls *>((node))->FUN_00a59c60((std::intptr_t)&(update));
                        }
                    }
                    ((::GridRefresh::CellHandle *)(::FUN_0045bb80((std::intptr_t)this)))->FUN_005ae3d0();
                }
            }
        }
    }
    if (((::GridRefresh::Queue *)(::FUN_00451010())))
        reinterpret_cast<::C6B540Manager *>((((::GridRefresh::Queue *)(::FUN_00451010()))))->FUN_00c6b540(0);
    ::FUN_00451570(0);
    ::FUN_00451520(1);
}
}

struct S_004537c0_Sky : Sky
{
};
struct S_004537c0_Mgr
{
};
struct S_004537c0_Tes : Zt5TES
{
    S_004537c0_Mgr* FUN_009611e0();
};
struct S_004537c0_Fade
{
    float unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
};

// Updates the sky with a time-based or fallback value, builds a fade from DAT_011c3c08, and passes it to the manager obtained via FUN_009611e0.
// @fnv 0x004537c0
void Zt5TES::FUN_004537c0()
{
    S_004537c0_Fade fadeData;
    reinterpret_cast<::fnv_0063ac70::FUN_0063ac70_shell *>((((S_004537c0_Sky*)pWeatherSky)))->FUN_0063ac70(::fnv_007050d0::FUN_007050d0() ? (*reinterpret_cast<::Twin_0084d030 *>(&::g_timeGlobal)).GetStoredFloatValue() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011c5724)))))) : FUN_00453850());
    new ((void *)&(fadeData)) ::NiUpdateData(::fnv_00563f30::DAT_011c3c08, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((((::S_004537c0_Mgr *)(reinterpret_cast<::FUN_009611e0_shell *>((((S_004537c0_Tes*)this)))->FUN_009611e0()))))->FUN_00a59c60((std::intptr_t)(&fadeData));
}

struct FUN_004539a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    unsigned char unkB4;
    void FUN_00454d50(unsigned char a);
    void FUN_008d7dc0(int b);
    void FUN_004539a0(unsigned char a1, unsigned char a2);
};

struct FUN_004539a0_helperA
{
};
struct FUN_004539a0_helperB
{
};

struct BufferedCell : TESObjectCELL
{
    bool FUN_00557090();
};
struct BufferMap
{
};
struct BufferWorld
{
    BufferMap* FUN_00586170();
};
struct CellBufferManager
{
    void* vtable;
    void* distantGrid;
    C_0084e3a0* grid;
    void* objectRoot;
    void* landRoot;
    void* waterRoot;
    void* tempNodeManager;
    void* light;
    void* fog;
    int currentGridX;
    int currentGridY;
    int queuedGridX;
    int queuedGridY;
    BufferedCell* interiorCell;
    BufferedCell** interiorBuffer;
    BufferedCell** exteriorBuffer;

    BufferWorld* FUN_004fd3e0();
    bool FUN_00453a80();
};

// @fnv 0x00453a80
bool CellBufferManager::FUN_00453a80()
{
    BufferedCell* cell = 0;
    if (!((::BufferedCell *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
    {
        for (int i = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_0043d4d0_cls *>(&::g_011c3e38)))))) - 1; i >= 0; --i)
        {
            if (interiorBuffer[i])
            {
                cell = interiorBuffer[i];
                interiorBuffer[i] = 0;
                break;
            }
        }
        if (!cell)
        {
            reinterpret_cast<::FUN_00454fc0_shell *>(this)->CompactQueuedCells();
            unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((grid))->FUN_0084e3a0())) * ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((grid))->FUN_0084e3a0()));
            for (unsigned int i = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90)))))) - 1; i >= count; --i)
            {
                if (exteriorBuffer[i])
                {
                    if (!reinterpret_cast<::TESCallHelper *>(this)->IsCellBuffered((::TESObjectCELL *)(exteriorBuffer[i]), true) && !exteriorBuffer[i]->FUN_00557090())
                    {
                        cell = exteriorBuffer[i];
                        exteriorBuffer[i] = 0;
                    }
                    break;
                }
            }
        }
    }
    else
    {
        unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((grid))->FUN_0084e3a0())) * ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((grid))->FUN_0084e3a0()));
        for (unsigned int i = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90)))))) - 1; i >= count; --i)
        {
            if (exteriorBuffer[i] && !reinterpret_cast<::TESCallHelper *>(this)->IsCellBuffered((::TESObjectCELL *)(exteriorBuffer[i]), true) && !exteriorBuffer[i]->FUN_00557090())
            {
                cell = exteriorBuffer[i];
                exteriorBuffer[i] = 0;
                break;
            }
        }
        if (!cell)
        {
            for (int i = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_0043d4d0_cls *>(&::g_011c3e38)))))) - 1; i >= 0; --i)
            {
                if (interiorBuffer[i] && interiorBuffer[i] != ((::BufferedCell *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
                {
                    cell = interiorBuffer[i];
                    interiorBuffer[i] = 0;
                    break;
                }
            }
        }
        if (!cell)
        {
            for (unsigned int i = 0; i < count; ++i)
            {
                if (exteriorBuffer[i] && !reinterpret_cast<::TESCallHelper *>(this)->IsCellBuffered((::TESObjectCELL *)(exteriorBuffer[i]), true) && !exteriorBuffer[i]->FUN_00557090())
                {
                    cell = exteriorBuffer[i];
                    exteriorBuffer[i] = 0;
                    reinterpret_cast<::fnv_00453940::FUN_00453940_shell *>(this)->FUN_00453940();
                    break;
                }
            }
        }
    }
    if (cell)
    {
        reinterpret_cast<::DeletionDataHandler *>((g_dataHandler))->DeleteObject((::DeletionObject *)(cell));
        if (!exteriorBuffer[0] && ((::BufferWorld *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())))
            reinterpret_cast<::FUN_006fce00_shell *>((((::BufferMap *)(reinterpret_cast<::TESWorldSpace *>((((::BufferWorld *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound()))))->GetWorldTerrainManager()))))->FUN_006fce00();
        return true;
    }
    return false;
}

struct ReloadPoint
{
    float x, y, z;
    ReloadPoint(float, int, int);
};
struct ReloadPair
{
    float x, y;
    ReloadPair(float, float);
};
struct ReloadGrid;
struct ReloadCell;
struct ReloadScene;
struct ReloadHandler
{
    void FUN_006fca90(ReloadPoint*, int);
    void FUN_006fcdb0(ReloadPoint*);
    bool FUN_00454b70();
};
struct ReloadWorld
{
    ReloadHandler* FUN_00586170();
};
struct ReloadGrid
{
    bool FUN_00447a00();
    void FUN_00450f90(int);
};
struct ReloadTexture
{
    void* FUN_0044edb0();
    void* FUN_00825c00();
    void FUN_0063ddb0(void*);
};
struct ReloadInterior;
struct ReloadRoot;
struct ReloadObject;
struct ReloadInterior
{
    ReloadGrid* FUN_009611e0();
};
struct ReloadInterior;
struct ReloadRoot;
struct ReloadObject;
struct ReloadScene
{
    void* FUN_009d9f20();
    void FUN_0054af40(bool);
    bool FUN_00454b10();
};
struct ReloadName
{
    void* FUN_006733e0();
    const char* FUN_00454b50();
};
struct ReloadRoot
{
    void* FUN_00454b30();
};
ReloadRoot* ReloadGetRootCreate(int);
ReloadRoot* ReloadGetMain(int);
void ReloadDisableRendering(int);
void ReloadGlobalUpdate(int);
struct ReloadPlayer
{
};
struct ReloadData
{
    void DeleteObject(ReloadScene*);
};
struct ReloadMode
{
};
struct ReloadState
{
};
struct ReloadCells
{
};
struct ReloadAudio
{
};
struct ReloadObject
{
};
struct ReloadShader
{
    void FUN_004ba7d0();
};
struct ReloadSetting
{
    float* FUN_00403e20(int);
};
struct ReloadFade
{
};
struct ReloadTerrain
{
};
struct ReloadZone
{
};
struct ReloadNode
{
    unsigned object;
    ReloadNode(int);
    ~ReloadNode();
};
struct TileReloadContext
{
    void FUN_0045cda0();
};
struct ReloadContext
{
    int old;
    ReloadContext(int, bool, const char*, int);
    ~ReloadContext();
};
struct ReloadPathing
{
};
extern ReloadSetting reloadSetting;
extern bool reloadFinished, reloadFlagA, reloadFlagB, reloadHasWorld, reloadFlagC;
extern ReloadPoint reloadRotation;
extern ReloadPair reloadCurrent, reloadPrevious;
extern float reloadHeight;
float ReloadHeight(int);
void ReloadMovePoint(ReloadPoint, ReloadPoint, float);
bool ReloadDropFlag();
struct ReloadCamera
{
};
struct ReloadManager
{
    unsigned unk00;
    unsigned unk04;
    ReloadCamera* camera;
    ReloadObject* object;
    ReloadInterior* interior;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    int gridX;
    int gridY;
    int oldX;
    int oldY;
    unsigned unk34;
    unsigned unk38;
    int* loaded;
    unsigned unk40;
    unsigned unk44;
    int savedX;
    int savedY;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    ReloadTexture* texture;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    ReloadName* name;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    ReloadNode loadedNode;
    void FUN_008d7dc0(ReloadScene*);
    void Pause(int, int);
    void UpdateSkyModeForCell(ReloadScene*);
    void FUN_00454c20(ReloadScene*);
    void AttachScene(ReloadScene*, ReloadPoint*);
    ReloadWorld* FUN_004fd3e0();
    void FUN_008d7dc0(int);
    void Pause(int, ReloadPoint*);
    int FUN_00457620(ReloadPoint*);
    ReloadCell* FUN_00451900(int, int);
    ReloadShader* FUN_0044ddc0();
    void InitFromMatrix();
    void InitSoundGrid();
    void FUN_0045cda0();
    void GetLandHeightAt(ReloadPoint*, float&);
    void FUN_00451cf0();
    void UpdateSkyModeForCell(int);
    void FUN_00454450(ReloadPoint*);
};
struct ReloadInterface
{
};
struct ReloadStreaming
{
};
struct ReloadBoolSetting
{
    bool* FUN_00408d60();
};
struct ReloadRuntime
{
};
bool ReloadMenuActive(int, int);
struct ReloadGridSetting
{
};
struct ReloadLoaded
{
};
struct ReloadPlayerCheck
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int CheckState();
};
namespace fnv_00454450 {
struct ReloadPoint
{
    float x, y, z;
    ReloadPoint(float, float, float);
};
struct ReloadPair
{
    float x, y;
    ReloadPair(float, float);
};
struct ReloadGrid;
struct ReloadCell;
struct ReloadScene;
struct ReloadHandler
{
    void FUN_006fca90(ReloadPoint*, int);
    void FUN_006fcdb0(ReloadPoint*);
    bool FUN_00454b70();
};
struct ReloadWorld
{
    ReloadHandler* FUN_00586170();
};
struct ReloadGrid
{
    bool FUN_00447a00();
    void FUN_00450f90(int);
};
struct ReloadTexture
{
    void* FUN_0044edb0();
    void* FUN_00825c00();
    void FUN_0063ddb0(void*);
};
struct ReloadInterior
{
    ReloadGrid* FUN_009611e0();
};
struct ReloadScene
{
    void* FUN_009d9f20();
    void FUN_0054af40(bool);
    bool FUN_00454b10();
};
struct ReloadName
{
    void* FUN_006733e0();
    const char* FUN_00454b50();
};
struct ReloadRoot
{
    void* FUN_00454b30();
};
ReloadRoot* ReloadGetRootCreate(int);
ReloadRoot* ReloadGetMain(int);
void ReloadDisableRendering(int);
void ReloadGlobalUpdate(int);
struct ReloadPlayer
{
};
struct ReloadData
{
    void DeleteObject(ReloadScene*);
};
struct ReloadMode
{
};
struct ReloadState
{
};
struct ReloadCells
{
};
struct ReloadAudio
{
};
struct ReloadObject
{
};
struct ReloadShader
{
    void FUN_004ba7d0();
};
struct ReloadSetting
{
    float* FUN_00403e20(int);
};
struct ReloadFade
{
};
struct ReloadTerrain
{
};
struct ReloadZone
{
};
struct ReloadNode
{
    unsigned object;
    ReloadNode(int);
    ~ReloadNode();
};
struct TileReloadContext
{
    void FUN_004568c0(const char*, ReloadNode&, int, int);
};
struct ReloadContext
{
    int old;
    ReloadContext(int, bool, const char*, int);
    ~ReloadContext();
};
struct ReloadPathing
{
};
extern ReloadSetting reloadSetting;
extern bool reloadFinished, reloadFlagA, reloadFlagB, reloadHasWorld, reloadFlagC;
extern ReloadPoint reloadRotation;
extern ReloadPair reloadCurrent, reloadPrevious;
extern float reloadHeight;
float ReloadHeight(int);
void ReloadMovePoint(ReloadPoint, ReloadPoint, float);
bool ReloadDropFlag();
struct ReloadManager
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    ReloadObject* object;
    ReloadInterior* interior;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    int gridX;
    int gridY;
    int oldX;
    int oldY;
    unsigned unk34;
    unsigned unk38;
    int* loaded;
    unsigned unk40;
    unsigned unk44;
    int savedX;
    int savedY;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    ReloadTexture* texture;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    ReloadName* name;
    ReloadWorld* FUN_004fd3e0();
    void FUN_008d7dc0(int);
    void Pause(int, ReloadPoint*);
    int FUN_00457620(ReloadPoint*);
    ReloadCell* FUN_00451900(int, int);
    void FUN_00457d70(int, ReloadCell*, int);
    ReloadShader* FUN_0044ddc0();
    void InitFromMatrix();
    void InitSoundGrid();
    void FUN_0045cda0();
    void GetLandHeightAt(ReloadPoint*, float&);
    void FUN_00451cf0();
    void UpdateSkyModeForCell(int);
    void FUN_00454450(ReloadPoint*);
};
// @fnv 0x00454450
void ReloadManager::FUN_00454450(ReloadPoint* point)
{
    ReloadWorld* world = ((::fnv_00454450::ReloadWorld *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound()));
    if (world)
    {
        reinterpret_cast<::BGSTerrainManager *>((((::fnv_00454450::ReloadHandler *)(reinterpret_cast<::TESWorldSpace *>((world))->GetWorldTerrainManager()))))->FUN_006fca90((*(const ::NiPoint3 *)(point)), 15);
        reinterpret_cast<::Holder006fcdb0 *>((((::fnv_00454450::ReloadHandler *)(reinterpret_cast<::TESWorldSpace *>((world))->GetWorldTerrainManager()))))->FUN_006fcdb0((std::intptr_t)(point));
    }
    FUN_00454440(0);
    if (name)
        ::BGSImpactDataSet::RefreshImpactData((::ImpactSwap *)(void *)(name->FUN_006733e0()));
    ::SetRootAppCulled(0);
    reinterpret_cast<::FUN_00454380_Class *>((((::fnv_00454450::ReloadRoot *)(::FUN_00451010()))))->FUN_00454380(1);
    ReloadScene* sceneTmp = ((::fnv_00454450::ReloadScene *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (sceneTmp)
    {
        if (((void *)(reinterpret_cast<::FUN_00454b30_class *>((ReloadGetMain(0)))->FUN_00454b30())) == ((void *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((sceneTmp))->FUN_009d9f20())))
            reinterpret_cast<::fnv_00b5ddf0::LocalTarget *>((ReloadGetMain(0)))->FUN_00b5ddf0((::fnv_00b5ddf0::LocalContext *)(0));
        reinterpret_cast<::CellTarget *>((sceneTmp))->FUN_00552bd0(true);
        if (!reinterpret_cast<::fnv_00454bd0::TES *>(this)->ContainsCell((::TESObjectCELL *)(sceneTmp)))
            reinterpret_cast<::DeletionDataHandler *>(((*reinterpret_cast<::fnv_00454450::ReloadData * *>(&::g_dataHandler))))->DeleteObject((::DeletionObject *)(sceneTmp));
        else
            reinterpret_cast<::FUN_0054af40_cls *>((sceneTmp))->FUN_0054af40(true);
        reinterpret_cast<::LowProcess *>(this)->SetCurrentBoundObject((::TESBoundObject *)(0));
        if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00454450::ReloadMode * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
        {
            if (savedX != 0x7fffffff)
            {
                if (*loaded)
                {
                    gridX = savedX;
                    gridY = savedY;
                    Pause(0, point);
                }
                else
                {
                    gridX = 0x7fffffff;
                    gridY = 0x7fffffff;
                    oldX = gridX;
                    oldY = gridY;
                }
                savedX = 0x7fffffff;
                savedY = 0x7fffffff;
            }
            else if (!reinterpret_cast<::fnv_00457620::FUN_00457620_cls *>(this)->FUN_00457620((const float *)(point)))
            {
                gridX = 0x7fffffff;
                gridY = 0x7fffffff;
                oldX = gridX;
                oldY = gridY;
            }
        }
        reinterpret_cast<::MultiBoundManagerB5D *>((ReloadGetMain(0)))->FUN_00b5d180();
        reinterpret_cast<::fnv_00b5cbd0::ShadowSceneNode_Self *>((ReloadGetMain(0)))->FUN_00b5cbd0(((void *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00454450::ReloadPlayer * *>(&::_g_thePlayer))))->FUN_00950bb0(0))));
    }
    if (interior)
    {
        ReloadGrid* grid6 = ((::fnv_00454450::ReloadGrid *)(reinterpret_cast<::FUN_009611e0_shell *>((interior))->FUN_009611e0()));
        if (grid6)
            reinterpret_cast<::TaskQueueInterface *>((grid6))->QueueActorDisarm(0);
        ::FUN_006fd1f0(1);
    }
    ::FUN_00451010();
    reinterpret_cast<::Root *>((((::fnv_00454450::ReloadRoot *)(::FUN_00451010()))))->SetProcessEnabled(ReloadDropFlag());
    bool mode = false;
    bool stateB = false;
    mode = reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00454450::ReloadMode * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10();
    stateB = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::fnv_00454450::ReloadState * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
    reinterpret_cast<::TES *>(this)->FindCellAtPosition((const ::NiPoint3 *)(point), !stateB);
    ReloadCell* cellA = ((::fnv_00454450::ReloadCell *)(reinterpret_cast<::FUN_00451900_shell *>(this)->FUN_00451900(gridX, gridY)));
    if (reinterpret_cast<::FUN_00447950_shell *>(((*reinterpret_cast<::fnv_00454450::ReloadCells * *>(&::g_modelLoader))))->FUN_00447950((::TESObjectCELL *)(cellA)))
        FUN_00457d70(1, cellA, 0);
    if (((::fnv_00454450::ReloadRoot *)(::FUN_00451010())))
        reinterpret_cast<::C00c66300 *>((((::fnv_00454450::ReloadRoot *)(::FUN_00451010()))))->FUN_00c66300();
    if (!mode)
        reinterpret_cast<::IOManager *>(((*reinterpret_cast<::fnv_00454450::ReloadAudio * *>(&::DAT_01202d98))))->FUN_00c3dfa0(4);
    reinterpret_cast<::FUN_004ba7d0_shell *>((((::fnv_00454450::ReloadShader *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()))))->FUN_004ba7d0();
    reinterpret_cast<::FUN_0045c840_shell *>(this)->InitFromMatrix();
    reinterpret_cast<::FUN_0045c780_shell *>(this)->InitSoundGrid();
    if (((::fnv_00454450::ReloadRoot *)(::FUN_00451010())))
        reinterpret_cast<::C6B540Manager *>((((::fnv_00454450::ReloadRoot *)(::FUN_00451010()))))->FUN_00c6b540(0);
    reinterpret_cast<::B45CDA0TES *>(this)->FUN_0045cda0();
    ReloadPoint position6(point->x, point->y, 0.0f);
    reinterpret_cast<::FUN_004572e0_shell *>(this)->GetLandHeightAt((*(const ::NiPoint3 *)(point)), position6.z);
    FUN_00451590(0);
    ReloadMovePoint(position6, (*reinterpret_cast<::fnv_00454450::ReloadPoint *>(&::DAT_011a9478)), 1.0f);
    FUN_00451590(1);
    if (!reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(this)->FUN_00451530() && !mode)
        reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_00454450::ReloadFade * *>(&::DAT_011d8804))))->AddFader((::FADER_ENUM)(true), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00454450::ReloadSetting *>(&::originalRuntimeFloatSetting16)))))), {});
    if (!mode)
    {
        reinterpret_cast<::FUN_00975f90_cls *>(&((*reinterpret_cast<::fnv_00454450::ReloadTerrain *>(&::g_011e0e80))))->ClearMobileObjectData();
        reinterpret_cast<::fnv_00459870::FUN_00459870_cls *>(this)->ProcessItemNodes();
        reinterpret_cast<::ThisCls *>(&((*reinterpret_cast<::fnv_00454450::ReloadTerrain *>(&::g_011e0e80))))->FUN_00972d30();
        reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::fnv_00454450::ReloadTerrain *>(&::g_011e0e80))))->UpdateHighProcess();
    }
    if (sceneTmp && !((bool)(reinterpret_cast<::fnv_00454b10::TESObjectCELL *>((sceneTmp))->GetFakeExterior())))
    {
        reinterpret_cast<::ThisCls *>((texture))->FUN_0063ddb0((::ParamObj *)(void *)(((void *)(reinterpret_cast<::MagicCaster_shell *>((texture))->FUN_0044edb0()))));
        reinterpret_cast<::ThisCls *>((texture))->FUN_0063ddb0((::ParamObj *)(void *)(((void *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((texture))->FUN_00825c00()))));
    }
    reinterpret_cast<::FUN_00451cf0_shell *>(this)->FUN_00451cf0();
    reinterpret_cast<::FUN_00455400_tes *>(this)->UpdateSkyModeForCell((::TESObjectCELL *)(0));
    reinterpret_cast<::FUN_00a5a040_Class *>((object))->FUN_00a5a040();
    ::BGSDestructibleObjectForm::UpdateTargetHealthBar((::TESObjectREFR *)(0));
    if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(this)->FUN_00451530())
        FUN_00457d70(0, 0, 0);
    reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(0);
    if (name && *reinterpret_cast<::FUN_00454b50_shell *>((name))->FUN_00454b50())
    {
        ReloadContext context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 3434);
        ReloadNode node3(0);
        (*reinterpret_cast<::fnv_00454450::TileReloadContext * *>(&::g_TES))->FUN_004568c0(reinterpret_cast<::FUN_00454b50_shell *>((name))->FUN_00454b50(), node3, 1, 0);
        reinterpret_cast<::NiColorInterpolator *>((((::fnv_00454450::ReloadZone *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_00454450::TileReloadContext * *>(&::g_TES))))))))->SetColorData((::NiColorData *)(void *)(((void *)(::FUN_00559450((int *)&(node3))))));
    }
    else
        reinterpret_cast<::NiColorInterpolator *>((((::fnv_00454450::ReloadZone *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_00454450::TileReloadContext * *>(&::g_TES))))))))->SetColorData((::NiColorData *)(void *)(0));
    reloadFinished = true;
    (*reinterpret_cast<::fnv_00454450::ReloadPair *>(&::DAT_011f962c)) = ReloadPair((gridX + 0.5) * 4096.0, (gridY + 0.5) * 4096.0);
    (*reinterpret_cast<::fnv_00454450::ReloadPair *>(&::DAT_011f9634)) = (*reinterpret_cast<::fnv_00454450::ReloadPair *>(&::DAT_011f962c));
    ::DAT_011f94ac = ::FUN_00452e70(0);
    ::DAT_011c3c0c = false;
    ::DAT_011f94aa = ::DAT_011c3c0c;
    if (reinterpret_cast<::FUN_00454b70 *>((((::fnv_00454450::ReloadHandler *)(reinterpret_cast<::TESWorldSpace *>((((::fnv_00454450::ReloadWorld *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound()))))->GetWorldTerrainManager()))))->GetHasLOD())
        reloadHasWorld = true;
    else
        reloadHasWorld = false;
    if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00454450::ReloadMode * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
        reinterpret_cast<::fnv_006c39c0::FUN_006c39c0_shell *>((((::fnv_00454450::ReloadPathing *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c39c0();
}
}  // namespace fnv_00454450

namespace fnv_00454d50 {
struct TESObjectCELL;
struct FUN_004503f0_obj
{
};
struct FUN_00557090_obj
{
    bool FUN_00557090(void);
};
struct DH_stub
{
    void DeleteObject(TESObjectCELL* c);
};

struct FUN_00454d50_shell
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    TESObjectCELL** unk38;
    unsigned int FUN_00454d50(unsigned char flag);
};

// @fnv 0x00454d50
unsigned int FUN_00454d50_shell::FUN_00454d50(unsigned char abSkipCurrent)
{
    unsigned int count = 0;
    unsigned int i;
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::TESObjectCELL *>((((FUN_004503f0_obj*)&(*reinterpret_cast<int *>(&::g_011c3e38)))))->GetCellStandValue())); i++)
    {
        if (unk38[i] != 0)
        {
            if (!(abSkipCurrent && ((::fnv_00454d50::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())) != 0 && unk38[i] == ((::fnv_00454d50::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))))
            {
                if (!((FUN_00557090_obj*)unk38[i])->FUN_00557090())
                {
                    reinterpret_cast<::DeletionDataHandler *>(((*reinterpret_cast<::fnv_00454d50::DH_stub * *>(&::g_dataHandler))))->DeleteObject((::DeletionObject *)(unk38[i]));
                    unk38[i] = 0;
                    count++;
                }
            }
        }
    }
    return count;
}
}  // namespace fnv_00454d50

namespace fnv_00455490 {
struct Q455490Quest
{
};
struct Q455490List
{
};
struct Q455490DataHandler
{
};
struct Q455490Cell
{
};
struct Q455490GridCellArray
{
    Q455490Cell** Get(unsigned int, unsigned int);
};
struct Q455490Setting
{
};
struct Q455490Lock
{
};
struct Q455490Player
{
};

extern bool g_455490_busy;

struct Q455490TES
{
    void* vtbl;
    void* unk04;
    Q455490GridCellArray* m_pGridCells;
    void FUN_00455490();
};

// Under a lock, runs scripts of all enabled quests, updates the interior cell or scans the grid for a matching cell, then updates the player.
// @fnv 0x00455490
void Q455490TES::FUN_00455490()
{
    if (g_455490_busy || !::Script::IsConsolePlatform())
        return;
    {
        g_455490_busy = true;
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_00455490::Q455490Lock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
        Q455490List* pIter6;
        Q455490Quest* kPQuest = 0;
        pIter6 = ((::fnv_00455490::Q455490List *)(reinterpret_cast<::fnv_00455600::FUN_00455600_shell *>(((*reinterpret_cast<::fnv_00455490::Q455490DataHandler * *>(&::g_dataHandler))))->FUN_00455600()));
        while (pIter6)
        {
            kPQuest = *((::fnv_00455490::Q455490Quest **)((void *)(pIter6)));
            pIter6 = ((::fnv_00455490::Q455490List *)(reinterpret_cast<::Callees *>((pIter6))->FUN_00726070()));
            if (kPQuest && reinterpret_cast<::TESFaction_RankDataView *>((kPQuest))->FUN_00455620())
                reinterpret_cast<::TESQuest *>((kPQuest))->RunScript();
        }
        if (((::fnv_00455490::Q455490Cell *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        {
            reinterpret_cast<::fnv_0054c740::FUN_0054c740_shell *>((((::fnv_00455490::Q455490Cell *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))))->FUN_0054c740(0, 0);
        }
        else
        {
            bool bCellFound = false;
            for (unsigned int uiX = 0; uiX < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00455490::Q455490Setting *>(&::g_011c63cc)))))); uiX++)
            {
                for (unsigned int uiY = 0; uiY < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00455490::Q455490Setting *>(&::g_011c63cc)))))); uiY++)
                {
                    Q455490Cell* pCell = *m_pGridCells->Get(uiX, uiY);
                    if (pCell && ::FUN_00450ff0(pCell) && reinterpret_cast<::fnv_0054c740::FUN_0054c740_shell *>((pCell))->FUN_0054c740(0, 0))
                    {
                        bCellFound = true;
                        break;
                    }
                }
                if (bCellFound)
                    break;
            }
        }
        reinterpret_cast<::fnv_00565870::FUN_00565870_shell *>(((*reinterpret_cast<::fnv_00455490::Q455490Player * *>(&::_g_thePlayer))))->FUN_00565870();
        reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_00455490::Q455490Lock *>(&::DAT_011f11a0))))->FUN_0040fba0();
        g_455490_busy = false;
    }
}
}  // namespace fnv_00455490

struct NiSourceTexture;
struct NiTextureFormatPrefs
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};

template <class T> struct TexPtr
{
    T* m_pObject;
    TexPtr(T* apObject);
    ~TexPtr();
    TexPtr& operator=(T* apObject);
    operator T*() const;
};

struct FixedStr
{
    const char* m_kHandle;
    FixedStr(const char* apString);
    ~FixedStr();
};

struct FileFinderStub
{
    static int Exist(const char* apPath, char* apOut, unsigned int auiFlags, unsigned int auiMask);
};

struct SourceTextureStub
{
    static NiSourceTexture* Create(const FixedStr& arName, NiTextureFormatPrefs& arPrefs, bool abA, bool abB);
};


struct TESTexLoader
{
    void FUN_004568c0(const char* apPath, TexPtr<NiSourceTexture>& arTexture, bool abNoWarning, bool abArchiveOnly);
};
// Iterates the water form list and, unless g_011c7b98.Bool() is set, creates and assigns a texture image for each form that has a texture.
// @fnv 0x0045a600
void WaterTextureLoader::LoadWaterTextures()
{
    AutoMemContext kMemContext(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 7207);
    FUN_0070ec90((char*)this);
    if (*::g_011c7b98.Bool())
        return;
    WaterFormNode* pNode = ((::WaterFormNode *)(reinterpret_cast<::FUN_0045a730_shell *>((((WaterDataHandler*)g_dataHandler)))->FUN_0045a730()));
    while (pNode && !pNode->IsEmpty())
    {
        TESWaterForm* m_pWaterForm = *((::TESWaterForm **)((void *)(pNode)));
        if (reinterpret_cast<::FUN_00580080_shell *>((m_pWaterForm))->FUN_00580080())
        {
            NiPointer<NiSourceTexture> spTexture(0);
            reinterpret_cast<::TESTexLoader *>((((WaterTES*)g_TES)))->FUN_004568c0(reinterpret_cast<::FUN_005800a0_shell *>((void *)(m_pWaterForm))->FUN_005800a0(), (::TexPtr< ::NiSourceTexture> &)(spTexture), true, false);
            reinterpret_cast<::FUN_005800c0_shell *>((m_pWaterForm))->SetNP(spTexture);
        }
        pNode = ((::WaterFormNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
}

// @fnv 0x004568c0
void TESTexLoader::FUN_004568c0(const char* apPath, TexPtr<NiSourceTexture>& arTexture, bool abNoWarning,
                                bool abArchiveOnly)
{
    unsigned int uiFlags = 0;
    unsigned int uiMask = 0xffff;
    arTexture = 0;
    ::FindTextureByPath(apPath, (::NiTexture **)(::TexPtr< ::NiSourceTexture> *)(&arTexture));
    if (arTexture)
        return;
    TexPtr<NiSourceTexture> spTexture(0);
    if (abArchiveOnly)
    {
        uiFlags = 6;
        uiMask = 2;
    }
    if (!FileFinderStub::Exist(apPath, 0, uiFlags, uiMask) && abNoWarning)
        return;
    arTexture = ::NiSourceTexture::Create((const ::NiFixedString &)((const ::FixedStr &)(FixedStr(apPath))), (::NiTexture__FormatPrefs &)((*reinterpret_cast<::NiTextureFormatPrefs *>(&::DAT_011a9598))), true, false);
    if (arTexture)
        ::TextureFileEntrySetter::SetTexture((::NiTexture *)(::NiSourceTexture *)(arTexture), (const ::BSFileEntry *)(0));
    else if (!abNoWarning)
        ::FUN_005b5e40();
}

struct FUN_00450f90_obj
{
    void FUN_00450f90(bool abFlag);
};
void __cdecl FUN_00457000(int aiType, bool abFlag);

struct FUN_00456fc0_ref
{
};

struct FUN_00456d00_cnt
{
};

struct FUN_00456d00_tes
{
};

struct FUN_00456d00_shell
{
    char pad[0x38];
    FUN_00456fc0_ref** ppRefs;
    FUN_00456fc0_ref** ppOthers;
    void FUN_00456d00(int aiType, bool abShow, bool abGrid);
};

// @fnv 0x00456d00
void FUN_00456d00_shell::FUN_00456d00(int aiType, bool abShow, bool abGrid)
{
    FUN_00457000(aiType, !abShow);
    if (aiType == 0xb)
    {
        if (!((::FUN_00456fc0_ref *)(reinterpret_cast<::BGSCameraPath *>((((FUN_00456d00_tes*)(*reinterpret_cast<::FUN_004570d0_mgr * *>(&::g_TES)))))->GetPrevPath())) ||
            !reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(((MobileObjectCellAccess*)((::FUN_00456fc0_ref *)(reinterpret_cast<::BGSCameraPath *>((((FUN_00456d00_tes*)(*reinterpret_cast<::FUN_004570d0_mgr * *>(&::g_TES)))))->GetPrevPath())))))->FUN_004518e0())
            reinterpret_cast<::TaskQueueInterface *>((((::FUN_00450f90_obj *)(::FUN_004e7ff0()))))->QueueActorDisarm(!abShow);
        return;
    }

    int iCount = abGrid ? 0 : *((int *)&(::FUN_0043d4d0((int *)(((FUN_00456d00_cnt*)&(*reinterpret_cast<::FUN_0043d4d0_cls *>(&::g_011c3e38)))))));
    for (int i = -1; i < iCount; i++)
    {
        FUN_00456fc0_ref* pRef = i == -1 ? ((::FUN_00456fc0_ref *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())) : ppRefs[i];
        if (pRef)
        {
            switch (aiType)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                FUN_00450f90_obj* pNode = ((::FUN_00450f90_obj *)(reinterpret_cast<::TESObjectCELL *>((pRef))->GetCellChildAt(aiType)));
                if (pNode)
                    reinterpret_cast<::TaskQueueInterface *>((pNode))->QueueActorDisarm(!abShow);
                reinterpret_cast<::CellStub *>((pRef))->FUN_00557990(!abShow, aiType);
                break;
            }
        }
    }

    if (!abGrid)
    {
        for (int j = 0; j < *((int *)&(::FUN_0043d4d0((int *)(((FUN_00456d00_cnt*)&(*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::DAT_011c3c90))))))); j++)
        {
            FUN_00456fc0_ref* pOther = ppOthers[j];
            if (pOther)
            {
                switch (aiType)
                {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 7:
                case 8:
                    FUN_00450f90_obj* pNode2 = ((::FUN_00450f90_obj *)(reinterpret_cast<::TESObjectCELL *>((pOther))->GetCellChildAt(aiType)));
                    if (pNode2)
                        reinterpret_cast<::TaskQueueInterface *>((pNode2))->QueueActorDisarm(!abShow);
                    break;
                }
            }
        }
    }
    else
    {
        for (unsigned int x = 0; x < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); x++)
        {
            for (unsigned int y = 0; y < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); y++)
            {
                FUN_00456fc0_ref** ppGrid = ((::FUN_00456fc0_ref **)(reinterpret_cast<::TES *>((((FUN_00456d00_tes*)(*reinterpret_cast<::FUN_004570d0_mgr * *>(&::g_TES)))))->FUN_00457050(x, y)));
                FUN_00456fc0_ref* pGridRef = *ppGrid;
                if (pGridRef)
                {
                    switch (aiType)
                    {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 7:
                    case 8:
                        FUN_00450f90_obj* pNode3 = ((::FUN_00450f90_obj *)(reinterpret_cast<::TESObjectCELL *>((pGridRef))->GetCellChildAt(aiType)));
                        if (pNode3)
                            reinterpret_cast<::TaskQueueInterface *>((pNode3))->QueueActorDisarm(!abShow);
                        break;
                    }
                }
            }
        }
    }
}

struct NiPoint3;

struct FUN_004571c0_obj
{
};

struct FUN_004571c0_cell : FUN_004570d0_node
{
    bool Apply(FUN_004571c0_obj* obj, int a2, int a3, float f, unsigned char b);
};

struct FUN_004571c0_cls : FUN_004570d0_cls
{
    bool ApplyToObject(FUN_004571c0_obj* obj, intptr_t a2, intptr_t a3, float f, char b);
};

// If obj and b are set, resets obj's flag and transforms, then applies the current cell or every grid cell to obj, returning whether any applied.
// @fnv 0x004571c0
bool FUN_004571c0_cls::ApplyToObject(FUN_004571c0_obj* pObject, intptr_t a2, intptr_t a3, float f, char b)
{
    bool result = false;
    if (pObject && b)
    {
        reinterpret_cast<::NiPick *>((pObject))->FUN_00705fc0(0);
        reinterpret_cast<::NiPick *>((pObject))->PerformPick((*(const ::NiPoint3 *)(&::NiPoint3::ZERO)), (*(const ::NiPoint3 *)(&::NiPoint3::ZERO)), 0);
        if (((::FUN_004570d0_node *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::FUN_004570d0_mgr * *>(&::g_TES))))->GetPrevPath())))
        {
            result = reinterpret_cast<::FUN_00553d00_shell *>((((FUN_004571c0_cell*)((::FUN_004570d0_node *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::FUN_004570d0_mgr * *>(&::g_TES))))->GetPrevPath())))))->PickChildNodes((::NiPick *)(pObject), a2, a3, f, b);
        }
        else
        {
            for (unsigned int i = 0; i < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); i++)
            {
                for (unsigned int j = 0; j < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); j++)
                {
                    FUN_004571c0_cell* cell = (FUN_004571c0_cell*)*((::FUN_004570d0_node **)(reinterpret_cast<::TES *>(this)->FUN_00457050(i, j)));
                    if (cell)
                    {
                        if (reinterpret_cast<::FUN_00553d00_shell *>((cell))->PickChildNodes((::NiPick *)(pObject), a2, a3, f, b))
                            result = true;
                    }
                }
            }
        }
    }
    return result;
}

struct WS458200_Obj
{
};
struct WS458200_Quest;
struct WS458200_World
{
    WS458200_Quest* FUN_006733e0();
    const char* FUN_00454b50() const;
};
struct WS458200_Sky
{
};
struct WS458200_TES
{
    WS458200_Sky* GetSky();
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};

struct WS458200_Shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    WS458200_World* m_pContainingWorldspace;

    void FUN_00458200(WS458200_World* apWorld);
};

// @fnv 0x00458200
void WS458200_Shell::FUN_00458200(WS458200_World* apWorld)
{
    if (apWorld && m_pContainingWorldspace != apWorld)
    {
        if (*::g_011c3d40.Bool())
        {
            if (((void *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
                reinterpret_cast<::fnv_00453940::FUN_00453940_shell *>(this)->FUN_00453940();
            int iCount = 0;
            iCount += ((int)(reinterpret_cast<::TES_ExteriorBuffer *>(this)->FUN_00455200(true, (::TESWorldSpace *)(m_pContainingWorldspace))));
            if (!((void *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
                iCount += ((int)(reinterpret_cast<::fnv_00454d50::FUN_00454d50_shell *>(this)->FUN_00454d50(true)));
            if (iCount)
                reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(false);
        }
        m_pContainingWorldspace = apWorld;
        WS458200_Obj* pObj = ((::WS458200_Obj *)(reinterpret_cast<::FUN_00458400_cls *>((m_pContainingWorldspace))->GetFieldD0()));
        if (pObj)
            reinterpret_cast<::FUN_00526270_shell *>((pObj))->FUN_00526270();
        ::BGSImpactDataSet::RefreshImpactData((::ImpactSwap *)(::WS458200_Quest *)(m_pContainingWorldspace->FUN_006733e0()));
        reinterpret_cast<::fnv_00453940::FUN_00453940_shell *>(this)->FUN_00453940();
        reinterpret_cast<::Calendar *>(this)->ResetCachedValues();
        ::Interface::IsWorldSpaceEnabled({});
        ::FUN_00709d20((std::intptr_t)(apWorld));
        if (*reinterpret_cast<::FUN_00454b50_shell *>((void *)(apWorld))->FUN_00454b50())
        {
            AutoMemContext kMemContext(0x1d, true, DAT_01017874, 0x1751);
            NiPointer<NiSourceTexture> spTexture(0);
            reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::WS458200_TES * *>(&::g_TES))))->FUN_004568c0(reinterpret_cast<::FUN_00454b50_shell *>((void *)(apWorld))->FUN_00454b50(), (::TexPtr< ::NiSourceTexture> &)(spTexture), true, true);
            reinterpret_cast<::NiColorInterpolator *>((((::WS458200_Sky *)(::FUN_0070ec90((char *)((*reinterpret_cast<::WS458200_TES * *>(&::g_TES))))))))->SetColorData((::NiColorData *)(::NiSourceTexture *)(spTexture));
        }
        else
        {
            reinterpret_cast<::NiColorInterpolator *>((((::WS458200_Sky *)(::FUN_0070ec90((char *)((*reinterpret_cast<::WS458200_TES * *>(&::g_TES))))))))->SetColorData((::NiColorData *)(::NiSourceTexture *)(0));
        }
        ::FUN_004583f0(!reinterpret_cast<::TESWorldSpace *>((apWorld))->IsFlag4C20Set());
    }
}

struct Point458
{
    float x, y, z;
};

class Ref458
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual bool PlaySound(int iSound, Point458 kPos);
};

class Manager458
{
  public:
    bool PlaySoundOnRef(int iSound, Point458 kPos, Ref458* pkRef);
};

// Resolves the given ref or the default ref, then calls PlaySound on it with the sound id and position, returning false if no ref exists.
// @fnv 0x00458b70
bool Manager458::PlaySoundOnRef(int iSound, Point458 kPos, Ref458* pkRef)
{
    Ref458* pkTarget = pkRef ? pkRef : ((::Ref458 *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound()));
    if (!pkTarget)
        return false;
    return pkTarget->PlaySound(iSound, kPos);
}

struct SaveWriter : SaveState
{
    unsigned char* FUN_00825c00();
};
struct ValueReferencePair
{
    C_0084e3a0* form;
    unsigned short value;
};
struct SaveEntryNode
{
};
struct SaveBlockOwner : SaveSizeOwner
{
    void WriteSaveBlock();
};

// @fnv 0x00459230
void SaveBlockOwner::WriteSaveBlock()
{
    SaveEntryNode* node;
    // Local names and declaration order preserve the original MSVC9 stack layout.
    unsigned short count = 0;            // Serialized 16-bit block length placeholder.
    unsigned char* initialPosition = 0;  // Location where the block length is backfilled.
    // Beginning of the range measured for diagnostic logging.
    unsigned char* blockSizePosition = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (*(*reinterpret_cast<::SaveLogSetting *>(&::g_011de4e8)).FUN_00408d60())
        blockSizePosition = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int blockType = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&blockType, 4);
        initialPosition = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&count, 2);
    }
    node = reinterpret_cast<SaveEntryNode*>(((::SaveItemList *)(reinterpret_cast<::FUN_0050d100_shell *>(this)->FUN_0050d100())));
    // Number of entries written before the entry data.
    unsigned int blockSize = reinterpret_cast<SaveItemList*>(node)->FUN_005ae380();
    reinterpret_cast<::FUN_008579b0_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&blockSize, 4);
    while (node)
    {
        ValueReferencePair* entry = *((::ValueReferencePair **)((void *)(node)));
        if (entry)
        {
            unsigned int formId = 0;
            if (entry->form)
                formId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((entry->form))->FUN_0084e3a0()));
            reinterpret_cast<::C857A10Buffer *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_00857a10((const unsigned int *)(void *)(&formId), 4);
            reinterpret_cast<::FUN_008579b0_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&entry->value, 2);
        }
        node = ((::SaveEntryNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 50)
        reinterpret_cast<::FUN_008579b0_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&::fnv_00563f30::DAT_011c3c08, 4);
    if (*(*reinterpret_cast<::SaveLogSetting *>(&::g_011de4e8)).FUN_00408d60())
    {
        unsigned char* finalPosition = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        SaveFormRecord* record = ((::SaveFormRecord *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (record)
        {
            SaveForm* form = ((::SaveForm *)(::FUN_004839c0(record->formId)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned char* uiTimestamp;
        unsigned char* endPosition = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<SaveWriter*>((*reinterpret_cast<::SaveState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        uiTimestamp = initialPosition;
        if (endPosition > uiTimestamp + 65535)
            ::FUN_005b5e40();
        *reinterpret_cast<unsigned short*>(initialPosition) = static_cast<unsigned short>(endPosition - uiTimestamp);
    }
}

extern const char DAT_01017e24[];
struct EmptyStructPlaceholder
{
};
struct TestWorldString
{
};
struct TestWorld
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* DebugName();
    int unk04, unk08, unk0c, unk10, unk14;
    TestWorldString name;
};
struct TestWorldList
{
    bool FUN_008256d0();
};
struct TestDataHandler
{
};
struct TestStep
{
};
struct CellTest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned char unk50;
    bool running, finished;
    void FUN_00459ae0(unsigned int);
};
// Marks the test running, iterates world cells within bounds and interior cells, invoking the per-cell test, then clears finished.
// @fnv 0x00459ae0
void CellTest::FUN_00459ae0(unsigned int flags)
{
    running = true;
    ::FUN_009526a0(true);
    ::FUN_0040fbe0();
    ::fnv_007037e0::FUN_007037e0();
    int state3 = ((int)(::FUN_00457fe0()));
    TestWorldList* worlds5 = ((::TestWorldList *)(::FUN_00460140((std::intptr_t)((*reinterpret_cast<::TestDataHandler * *>(&::g_dataHandler))))));
    while (worlds5 && !worlds5->FUN_008256d0())
    {
        TestWorld* world = *((::TestWorld **)((void *)(worlds5)));
        if (world)
        {
            reinterpret_cast<::WS458200_Shell *>(this)->FUN_00458200((::WS458200_World *)(world));
            int minX = ((int)reinterpret_cast<::FUN_004565f0_shell *>((world))->GetFloat()) >> 12;
            int minY5 = ((int)reinterpret_cast<::FUN_00812870_t *>((world))->GetUnka4()) >> 12;
            int maxX6 = ((int)reinterpret_cast<::LowProcess *>((world))->GetCurrentDetectionAmount()) >> 12;
            int maxY6 = ((int)reinterpret_cast<::Getter_9b8 *>((world))->FUN_009b88c0()) >> 12;
            const char* name3 = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(world->name))->FUN_00408da0()));
            if (!name3 || !FUN_0044a670(name3))
                name3 = world->DebugName();
            ::FUN_0040fbe0();
            for (int x7 = minX; x7 < maxX6; x7 += *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::TestStep *>(&::g_011c63cc)))))))
            {
                for (int y4 = minY5; y4 < maxY6; y4 += *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::TestStep *>(&::g_011c63cc)))))))
                {
                    EmptyStructPlaceholder* cellTmp = ((::EmptyStructPlaceholder *)(reinterpret_cast<::TESWorldSpace *>((world))->GetCellAtGridPosition(x7, y4)));
                    if (!cellTmp)
                        cellTmp = ((::EmptyStructPlaceholder *)(reinterpret_cast<::WorldCellLoader *>((world))->FUN_00585b30(x7, y4)));
                    if (cellTmp)
                        reinterpret_cast<::fnv_00459d20::FUN_00459d20_shell *>(this)->MoveToCell((::TESObjectCELL *)(cellTmp), flags, state3);
                }
            }
        }
        worlds5 = ((::TestWorldList *)(reinterpret_cast<::Callees *>((worlds5))->FUN_00726070()));
    }
    reinterpret_cast<::SortHandler *>(((*reinterpret_cast<::TestDataHandler * *>(&::g_dataHandler))))->FUN_004619b0();
    unsigned int count2 = ((unsigned int)(reinterpret_cast<::FUN_00461960_shell *>(((*reinterpret_cast<::TestDataHandler * *>(&::g_dataHandler))))->FUN_00461960()));
    for (unsigned int index7 = 0; index7 < count2; index7++)
    {
        EmptyStructPlaceholder* interior4 = ((::EmptyStructPlaceholder *)(reinterpret_cast<::Stub *>(((*reinterpret_cast<::TestDataHandler * *>(&::g_dataHandler))))->GetCameraPathAt(index7)));
        reinterpret_cast<::fnv_00459d20::FUN_00459d20_shell *>(this)->MoveToCell((::TESObjectCELL *)(interior4), flags, state3);
    }
    finished = false;
}

struct QueuedFile
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    QueuedFile(int priority);
};
struct AddonQueuePointer
{
    QueuedFile* object;
};
struct AddonFormBase
{
    virtual void ReservedForm0();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct TESModel
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual char* GetModelPath();
};
struct BGSAddonNode : AddonFormBase, TESModel
{
public:
    bool IsMasterParticleSystem() const;
};
struct AddonParticleNode : NiNode
{
};
struct AddonParticleManager
{
};
struct AddonOwner
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    AddonQueuePointer queuedFile;
    void FUN_00459f10();
};
// Queues a priority-5 file, then for each addon node loads its model, configures the particle node and registers it, or queues the model for loading.
// @fnv 0x00459f10
void AddonOwner::FUN_00459f10()
{
    if (((::QueuedFile *)(::FUN_00559450((int *)&(queuedFile)))))
        return;
    AutoMemContext count(7, true, DAT_01017874, 7054);
    reinterpret_cast<::FUN_006f74f0_cls *>(&(queuedFile))->FUN_006f74f0((::ObjA *)(::QueuedFile *)(new QueuedFile(5)));
    unsigned int context = reinterpret_cast<::BSFaceGenMorphData *>((reinterpret_cast<TESDataHandler*>(g_dataHandler)))->DynamicCast();
    for (unsigned int i = 0; i < context; ++i)
    {
        BGSAddonNode* addon = reinterpret_cast<TESDataHandler*>(g_dataHandler)->GetAddonNodeByIndex(i);
        if (addon)
        {
            if (addon->IsMasterParticleSystem())
            {
                NiNode* model = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(addon->GetModelPath(), 0, true, false, false, false);
                if (model)
                {
                    AddonParticleNode* particle = static_cast<AddonParticleNode*>(model);
                    reinterpret_cast<::AlchemyItem *>((particle))->SetSound((::TESSound *)(((reinterpret_cast<::FUN_0068a830_shell *>((addon))->GetGrass()))));
                    reinterpret_cast<::FUN_00705b10_Dummy *>((particle))->Set(((std::intptr_t)(reinterpret_cast<::TESQuest *>((addon))->GetScriptLocalData())));
                    reinterpret_cast<::FUN_0045a140_Class *>((particle))->SetShortAtOffsetBC(reinterpret_cast<::FUN_0045a1a0_Class *>((addon))->GetShortAtOffset58());
                    reinterpret_cast<::FUN_0045a160_Cls *>((((::AddonParticleManager *)(::FUN_0045a190()))))->FUN_0045a160((std::intptr_t)(particle));
                }
                reinterpret_cast<::FUN_00445300_shell *>((::g_modelLoader))->FUN_00445300(addon->GetModelPath(), true, 1);
            }
            else
            {
                reinterpret_cast<::QueueModelHolder *>((::g_modelLoader))->FUN_00443d30((std::uintptr_t)(static_cast<TESModel*>(addon)), 5, (std::uintptr_t)(((::QueuedFile *)(::FUN_00559450((int *)&(queuedFile))))), 0, true,
                                                   false, false);
            }
        }
    }
}

namespace fnv_0045a1e0 {
enum MEM_CONTEXT
{
    MemoryContext7 = 7
};
struct AutoMemContext
{
    int old;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
struct QueuedFile
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    QueuedFile(int);
};
struct QueuePtr45
{
    QueuedFile* ptr;
};
struct Component45
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Queue(int, QueuedFile*);
};
struct Body45
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Component45 component;
};
struct List45
{
    bool FUN_008256d0();
};
struct DataHandler45
{
};
struct Manager45
{
};
struct Target45
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    QueuePtr45 queued;
    void QueueLoadForAll();
};
// @fnv 0x0045a1e0
void Target45::QueueLoadForAll()
{
    if (((::fnv_0045a1e0::QueuedFile *)(::FUN_00559450((int *)&(queued)))))
        return;
    AutoMemContext list(MemoryContext7, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp",
                        0x1bd0);
    reinterpret_cast<::FUN_006f74f0_cls *>(&(queued))->FUN_006f74f0((::ObjA *)(::fnv_0045a1e0::QueuedFile *)(new QueuedFile(5)));
    List45* memory = ((::fnv_0045a1e0::List45 *)(reinterpret_cast<::MessageHandler *>(((*reinterpret_cast<::fnv_0045a1e0::DataHandler45 * *>(&::g_dataHandler))))->GetWarningFileName()));
    while (memory && !memory->FUN_008256d0())
    {
        Body45* body = *((::fnv_0045a1e0::Body45 **)((void *)(memory)));
        memory = ((::fnv_0045a1e0::List45 *)(reinterpret_cast<::Callees *>((memory))->FUN_00726070()));
        if (body)
            body->component.Queue(5, ((::fnv_0045a1e0::QueuedFile *)(::FUN_00559450((int *)&(queued)))));
    }
    if ((*reinterpret_cast<::fnv_0045a1e0::Manager45 * *>(&::DAT_011ca278)))
        reinterpret_cast<::TESObjectWEAP *>(((*reinterpret_cast<::fnv_0045a1e0::Manager45 * *>(&::DAT_011ca278))))->QueueResourceLoad(5, (::QueuedFile *)(::fnv_0045a1e0::QueuedFile *)(((::fnv_0045a1e0::QueuedFile *)(::FUN_00559450((int *)&(queued))))), false);
}
}  // namespace fnv_0045a1e0

struct ModelSetting
{
};
extern bool DAT_011c3f08;
struct PreloadOwner : ModelCloneOwner
{
    void PreloadModelSettings();
};
// If not already done, marks the flag and loads each non-empty model setting string via g_modelLoader, passing the result to AddCloneEntry.
// @fnv 0x0045a750
void PreloadOwner::PreloadModelSettings()
{
    if (DAT_011c3f08)
        return;
    AutoMemContext context(0x32, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 0x1c66);
    DAT_011c3f08 = true;
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011ce0c0))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011ce0c0))))->GetMenuTitle())), 0, true, false, false, false));
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cfa28))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cfa28))))->GetMenuTitle())), 0, true, false, false, false));
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011d12c0))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011d12c0))))->GetMenuTitle())), 0, true, false, false, false));
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011ce1a0))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011ce1a0))))->GetMenuTitle())), 0, true, false, false, false));
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cfa64))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cfa64))))->GetMenuTitle())), 0, true, false, false, false));
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cf3a4))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cf3a4))))->GetMenuTitle())), 0, true, false, false, false));
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cf54c))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cf54c))))->GetMenuTitle())), 0, true, false, false, false));
    if (*((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cebb0))))->GetMenuTitle())))
        AddCloneEntry((NiObject*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080(((char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ModelSetting *>(&::g_011cebb0))))->GetMenuTitle())), 0, true, false, false, false));
}

struct FUN_0045ae20
{
    ~FUN_0045ae20();
    FUN_0045ae20* FUN_0044ddc0();
};
struct InventoryMenuSetting
{
};
struct FUN_0076b630;
struct Target
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    FUN_0045ae20* head;
    void FUN_0045ac80();
public:
    ::FUN_0076b630 *FUN_004c8c10(int, int);
};
// @fnv 0x0045ac80
void Target::FUN_0045ac80()
{
    FUN_0045ae20* current = head;
    while (current)
    {
        FUN_0045ae20* next = ((::FUN_0045ae20 *)(reinterpret_cast<::Twin_0044ddc0 *>((current))->GetName()));
        delete current;
        current = next;
    }
    head = 0;
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cebb0))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cebb0))))->GetMenuTitle())));
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d12c0))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d12c0))))->GetMenuTitle())));
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011ce1a0))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011ce1a0))))->GetMenuTitle())));
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cf3a4))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cf3a4))))->GetMenuTitle())));
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cf54c))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cf54c))))->GetMenuTitle())));
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cfa64))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cfa64))))->GetMenuTitle())));
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011ce0c0))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011ce0c0))))->GetMenuTitle())));
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cfa28))))->GetMenuTitle())))
        (*reinterpret_cast<::FUN_0045a5e0_shell * *>(&::g_modelLoader))->FUN_0045a5e0((char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011cfa28))))->GetMenuTitle())));
}

class NavMeshInfoMap45A
{
  public:
    NavMeshInfoMap45A();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

class TESDataHandler45A
{
  public:
};


class Owner45A
{
  public:
    NavMeshInfoMap45A* FUN_0045af00();

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    NavMeshInfoMap45A* m_pkNavMeshInfoMap;
};

// Lazily creates m_pkNavMeshInfoMap when it is null, the data handler exists and is not loading, then returns it.
// @fnv 0x0045af00
NavMeshInfoMap45A* Owner45A::FUN_0045af00()
{
    if (!m_pkNavMeshInfoMap && (*reinterpret_cast<::TESDataHandler45A * *>(&::g_dataHandler)) && !reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::TESDataHandler45A * *>(&::g_dataHandler))))->FUN_004516b0())
        m_pkNavMeshInfoMap = new NavMeshInfoMap45A;
    return m_pkNavMeshInfoMap;
}

struct CellView : public TESObjectCELL
{
};
struct FUN_0045cbc0_Grid
{
};
struct FUN_0045cbc0_TES
{
    FUN_0045cbc0_Grid* FUN_004fd3e0();
};
struct FUN_0045cbc0_shell
{
    float GetCellHeightAtPosition(const NiPoint3* apPos, CellView* apCell);
};
// @fnv 0x0045cbc0
float FUN_0045cbc0_shell::GetCellHeightAtPosition(const NiPoint3* apPos, CellView* apCell)
{
    float fRate = DAT_01015f5c;
    if (apCell)
    {
        float fCellHeight;
        if (reinterpret_cast<::fnv_00547250::FUN_00547250_shell *>((apCell))->CheckWaterHeight((void *)(apPos), &fCellHeight))
            return fCellHeight;
        else if (reinterpret_cast<::TESObjectCELL *>((apCell))->IsCellInterior())
            return DAT_01015f5c;
        fRate = reinterpret_cast<::FUN_005471e0_shell *>((apCell))->FUN_005471e0();
    }
    else
    {
        if (((::CellView *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        {
            float fCurrentHeight;
            reinterpret_cast<::fnv_00547250::FUN_00547250_shell *>((((::CellView *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))))->CheckWaterHeight((void *)(apPos), &fCurrentHeight);
            return fCurrentHeight;
        }
        apCell = ((::CellView *)(reinterpret_cast<::fnv_00587550::FUN_00587550_shell *>((((::FUN_0045cbc0_Grid *)(reinterpret_cast<::EffectSetting *>((((FUN_0045cbc0_TES*)g_TES)))->GetHitSound()))))->FUN_00587550((*(const ::fnv_00587550::NiPoint3 *)(apPos)))));
        if (apCell)
            fRate = reinterpret_cast<::FUN_005471e0_shell *>((apCell))->FUN_005471e0();
        else
            return reinterpret_cast<::BGSProjectile *>((((::FUN_0045cbc0_Grid *)(reinterpret_cast<::EffectSetting *>((((FUN_0045cbc0_TES*)g_TES)))->GetHitSound()))))->GetExplosionProximity();
    }
    int iWorldX;
    std::intptr_t iBaseY;
    if (apCell)
    {
        iWorldX = reinterpret_cast<::TESObjectCELL *>((apCell))->GetCellGridX();
        iBaseY = reinterpret_cast<::TESObjectCELL *>((apCell))->GetCellGridY();
    }
    else
    {
        iWorldX = ((int)(reinterpret_cast<::ActorMover *>((((FUN_0045cbc0_TES*)g_TES)))->GetCurrentMoveModeType()));
        iBaseY = ((std::intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((FUN_0045cbc0_TES*)g_TES)))->FUN_0045cd60()));
    }
    float fOtherHeight = 0.0f;
    for (int iX = iWorldX - 1; iX < iWorldX + 2; iX++)
    {
        for (int iY = iBaseY - 1; iY < iBaseY + 2; iY++)
        {
            CellView* pCell = ((::CellView *)(reinterpret_cast<::TESWorldSpace *>((((::FUN_0045cbc0_Grid *)(reinterpret_cast<::EffectSetting *>((((FUN_0045cbc0_TES*)g_TES)))->GetHitSound()))))->GetCellAtGridPosition(iX, iY)));
            if (pCell && pCell != apCell && reinterpret_cast<::fnv_00547250::FUN_00547250_shell *>((pCell))->CheckWaterHeight((void *)(apPos), &fOtherHeight))
                return fOtherHeight;
        }
    }
    return fRate;
}

// Register this reference with its cell's world occlusion manager (planes, lists and bounds).

class C6760Base
{
  public:
    virtual ~C6760Base();
    int unk04;
};

class C6760ManagerBase
{
  public:
    virtual ~C6760ManagerBase();
};

class C6760Ref;

class C6760Manager : public C6760Base, public C6760ManagerBase
{
  public:
};

class C6760World
{
  public:
};

class C6760Cell
{
  public:
};

class C6760Ref
{
  public:
    void FUN_00576760();
};

// Gets the parent cell's world, then registers this ref with its occlusion manager via AddPlanes, AddToLists and UpdateBounds.
// @fnv 0x00576760
void C6760Ref::FUN_00576760()
{
    C6760Cell* pkCell = ((::C6760Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    C6760World* pkWorld = pkCell ? ((::C6760World *)(reinterpret_cast<::FUN_004543c0_cls *>((pkCell))->FUN_004543c0())) : 0;
    if (pkWorld)
    {
        C6760Manager* pkManager = static_cast<C6760Manager*>(((::C6760ManagerBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkWorld))->FUN_007af430())));
        if (pkManager)
        {
            reinterpret_cast<::FUN_00576830_shell *>((pkManager))->FUN_00576800((::BSOcclusionPlane *)(::C6760Ref *)(this));
            reinterpret_cast<::FUN_00620130_Class *>((pkManager))->FUN_00620130((::BSSimpleList<int *> *)(::C6760Ref *)(this));
            reinterpret_cast<::FUN_0062de90_shell *>((pkManager))->FUN_0062de90((::CombatWorldStateListNode *)(::C6760Ref *)(this));
        }
    }
}

namespace n451 {
struct Pt
{
    float iMinY, nX, z;
};
struct Grid
{
    char pad[0x24];
    int m_24;
    int m_28;
    bool ContainsPoint(const Pt& pt);
};
}
// Returns true if FUN_005f36f0 succeeds, otherwise checks whether the scaled point coordinates fall inside the grid cell range derived from m_24 and m_28.
// @fnv 0x00451110
bool n451::Grid::ContainsPoint(const Pt& aPoint)
{
    if (((void *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        return true;
    int iMinY = FUN_00406d90(aPoint.iMinY) >> 12;
    int nX = FUN_00406d90(aPoint.nX) >> 12;
    int ix = m_24 - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))) >> 1);
    int px = m_28 - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))) >> 1);
    if (iMinY < ix || iMinY >= ix + (int)*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))) || nX < px ||
        nX >= px + (int)*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))))
        return false;
    return true;
}

struct FUN_005400e0_obj : FUN_0045cb90_cls
{
};

struct FUN_00546fb0_cell : B45CDA0Cell
{
};

struct FUN_0045cac0_tes : B45CDA0TES
{
    void FUN_0045cac0();
};

// Iterates the grid cells, and for each cell with an entry object that passes FUN_0045cb90, calls FUN_005400e0 on it.
// @fnv 0x0045cac0
void FUN_0045cac0_tes::FUN_0045cac0()
{
    FUN_00546fb0_cell* pCell = 0;
    FUN_005400e0_obj* pEntryObj;
    unsigned int i;
    unsigned int j;
    for (i = 0; i < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); i++)
    {
        for (j = 0; j < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))); j++)
        {
            pCell = static_cast<FUN_00546fb0_cell*>(m_pkGridCells->Get(i, j)->m_pkCell);
            pEntryObj = pCell ? ((::FUN_005400e0_obj *)(reinterpret_cast<::S00546fb0_Cell *>((pCell))->FUN_00546fb0())) : 0;
            if (pCell && pEntryObj && pEntryObj->FUN_0045cb90())
                reinterpret_cast<::Surface *>((((::FUN_005400e0_obj *)(reinterpret_cast<::S00546fb0_Cell *>((pCell))->FUN_00546fb0()))))->FUN_005400e0();
        }
    }
}

struct CellHit
{
};
struct CellProbe
{
};
struct TESCellLookup
{
};

struct FUN_004573f0_shell : public TES
{
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    bool FUN_004573f0(const NiPoint3* pos, NiPoint3* normal, int flags);
};

// Computes the cell coordinates from pos, sets normal to (0,0,1), and if the cell passes a lookup test returns the result of a probe hit test.
// @fnv 0x004573f0
bool FUN_004573f0_shell::FUN_004573f0(const NiPoint3* pos, NiPoint3* normal, int flags)
{
    int cellX = ::FUN_00406d90(pos->x);
    int cellY2 = ::FUN_00406d90(pos->y);
    if (cellX % 4096 == 0 && (float)cellX > pos->x)
        cellX = cellX - 1;
    if (cellY2 % 4096 == 0 && (float)cellY2 > pos->y)
        cellY2 = cellY2 - 1;
    cellX >>= 12;
    cellY2 >>= 12;
    *normal = ::NiPoint3::ZERO;
    normal->z = 1.0f;
    TESObjectCELL* cell5 = reinterpret_cast<::FUN_00451900_shell *>(this)->FUN_00451900(cellX, cellY2);
    if (cell5 && reinterpret_cast<::TESCallHelper *>((((TESCellLookup*)g_TES)))->IsCellBuffered((::TESObjectCELL *)(cell5), 0))
        return reinterpret_cast<::Owner *>((((::CellHit *)(reinterpret_cast<::S00546fb0_Cell *>((((CellProbe*)cell5)))->FUN_00546fb0()))))->FUN_0053d2e0({}, {}, {});
    return false;
}

struct xPt3C
{
    float x, y, z;
};
struct xChk
{
};
struct xCellC
{
};
struct xTESC
{
};
class xWorldC
{
  public:
    bool FUN_00457520(const xPt3C* pPos, std::intptr_t i);
};

// Truncates pPos to cell coordinates, checks if the containing cell is loaded, and returns whether the cell's test at pPos passes.
// @fnv 0x00457520
bool xWorldC::FUN_00457520(const xPt3C* pPos, std::intptr_t i)
{
    int qrEZrs = ::FUN_00406d90(pPos->x);
    int qsSDDgz = ::FUN_00406d90(pPos->y);
    if (qrEZrs % 4096 == 0 && qrEZrs > pPos->x)
        qrEZrs--;
    if (qsSDDgz % 4096 == 0 && qsSDDgz > pPos->y)
        qsSDDgz--;
    qrEZrs >>= 12;
    qsSDDgz >>= 12;
    xCellC* qfTOqo = ((::xCellC *)(reinterpret_cast<::FUN_00451900_shell *>(this)->FUN_00451900(qrEZrs, qsSDDgz)));
    if (qfTOqo && reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::xTESC * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(qfTOqo), 0))
        return reinterpret_cast<::fnv_0053f570::OwnerInterp *>((((::xChk *)(reinterpret_cast<::S00546fb0_Cell *>((qfTOqo))->FUN_00546fb0()))))->FUN_0053f570({}, {});
    return false;
}

class PathingSolution;

template <class T> class PathingRef
{
  public:
    void Reset(void* pvNew);
};

class FUN_0045cec0 : public PathingRef<PathingSolution>
{
  public:
    ~FUN_0045cec0();
    PathingSolution* m_pkRef;
};

class FUN_00667120
{
  public:
    ~FUN_00667120();
    int unk00;
};

class FUN_0045ae50 : public FUN_0045cec0
{
  public:
    ~FUN_0045ae50();
    FUN_00667120* m_pkArray;
};
// Calls FUN_0045ae50, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0045ae20
void* FUN_0045ae20_shell::FUN_0045ae20(unsigned int flags)
{
    reinterpret_cast<::FUN_0045ae50 *>(this)->FUN_0045ae50::~FUN_0045ae50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that resets the PathingRef and deletes the m_pkArray array if it is not null.
// @fnv 0x0045ae50
FUN_0045ae50::~FUN_0045ae50()
{
    Reset(0);
    if (m_pkArray)
        delete[] m_pkArray;
}

namespace s450dd0 {

struct Cell
{
};

struct CellGrid
{
    Cell** FUN_004ba490(unsigned int uiX, unsigned int uiY);
    void FUN_004ba960(int iWorld, unsigned int uiX, unsigned int uiY);
};

struct GridSettings
{
};

struct Scheduler
{
};

struct Audio
{
};

struct Camera
{
    void FUN_00450f90(bool bPause);
};

struct Params
{
    Params(float fValue, int iArg0, int iArg1);

    float m_fValue;
    int m_iArg0;
    int m_iArg1;
};

struct SceneGraph
{
    Camera* FUN_009611e0();
};



struct World
{
    int unk00;
    int unk04;
    CellGrid* m_pkGrid;
    int m_iWorldSpace;
    SceneGraph* m_pkScene;

    void Pause(bool bPause, int iUnused);
};

// Updates the scheduler and cells based on bPause, clears mobile object data when resuming, updates the camera, and applies a zero fade.
// @fnv 0x00450dd0
void World::Pause(bool bPause, int iUnused)
{
    if (!(*reinterpret_cast<int *>(&::g_dataHandler)))
        return;
    if (((::s450dd0::Scheduler *)(::FUN_00451010())))
    {
        if (bPause)
            reinterpret_cast<::FUN_00c66310_class *>((((::s450dd0::Scheduler *)(::FUN_00451010()))))->FUN_00c66310();
        else
            reinterpret_cast<::C00c66300 *>((((::s450dd0::Scheduler *)(::FUN_00451010()))))->FUN_00c66300();
    }
    for (unsigned int uiRow = 0; uiRow < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::s450dd0::GridSettings *>(&::g_011c63cc)))))); uiRow++)
    {
        for (unsigned int j = 0; j < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::s450dd0::GridSettings *>(&::g_011c63cc)))))); j++)
        {
            Cell** ppCell = m_pkGrid->FUN_004ba490(uiRow, j);
            Cell* pkCell = *ppCell;
            if (bPause)
            {
                if (pkCell && ::FUN_00450ff0((void *)(pkCell)))
                    reinterpret_cast<::CellTarget *>((pkCell))->FUN_00552bd0(0);
            }
            else
            {
                if (pkCell && ::FUN_00450fb0((void *)(pkCell)))
                {
                    m_pkGrid->FUN_004ba960(m_iWorldSpace, uiRow, j);
                    reinterpret_cast<::SceneB54 *>((pkCell))->FUN_0054bcf0(0);
                }
            }
        }
    }
    if (((::s450dd0::Scheduler *)(::FUN_00451010())))
    {
        if (bPause)
            reinterpret_cast<::bhkWorld *>((((::s450dd0::Scheduler *)(::FUN_00451010()))))->SetWorldActive(0);
        else
            reinterpret_cast<::C6B540Manager *>((((::s450dd0::Scheduler *)(::FUN_00451010()))))->FUN_00c6b540(0);
    }
    if (!bPause)
        reinterpret_cast<::FUN_00975f90_cls *>(&((*reinterpret_cast<::s450dd0::Audio *>(&::g_011e0e80))))->ClearMobileObjectData();
    Camera* pkView = ((::s450dd0::Camera *)(reinterpret_cast<::FUN_009611e0_shell *>((m_pkScene))->FUN_009611e0()));
    if (pkView)
    {
        reinterpret_cast<::TaskQueueInterface *>((pkView))->QueueActorDisarm(bPause);
        ::FUN_006fd1f0(!bPause);
    }
    Params kFade(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((m_pkScene))->FUN_00a59c60((std::intptr_t)&(kFade));
}

}

struct TESObjectCELL;

struct FnCls
{
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    TESObjectCELL* FUN_004519d0(float f1, float f2, int a3);
};

// Returns a non-null result from FUN_005f36f0; otherwise looks up a cell using shifted coordinates and checks it with FUN_004511e0.
// @fnv 0x004519d0
TESObjectCELL* FnCls::FUN_004519d0(float afX, float afY, int a3)
{
    if (((void *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        return (TESObjectCELL*)((void *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    int cellX = ((int)afX) >> 12;
    int cellY8 = ((int)afY) >> 12;
    TESObjectCELL* pCell = reinterpret_cast<::FUN_00451900_shell *>(this)->FUN_00451900(cellX, cellY8);
    if (pCell != 0 && reinterpret_cast<::TESCallHelper *>((((FUN_004511e0_cls*)g_TES)))->IsCellBuffered((::TESObjectCELL *)(pCell), 1))
        return pCell;
    return 0;
}

int __cdecl FUN_00458030();
extern unsigned int DAT_011c3efc;

struct BSAudio
{
public:
    void SetAudioState(unsigned int);
};

struct Tex457
{
};

struct Mgr457
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
};

struct Form457
{
    unsigned int FUN_00401170();
};

struct S457d70
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    int u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c;
    int u60, u64;
    Tex457* pTex68;
    bool FUN_00457d70(bool abFlag1, Form457* apForm, bool abFlag2);
};
// Switches the active scene to destination at position, resetting interfaces, streaming, terrain and audio, then updates the menu and pathing.
// @fnv 0x00453dc0
void ReloadManager::AttachScene(ReloadScene* destination, ReloadPoint* position)
{
    if (!reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(this)->FUN_00451530())
        reinterpret_cast<::fnv_00871dc0::FUN_00871dc0_class *>(((*reinterpret_cast<::ReloadStreaming * *>(&::g_osGlobals))))->FUN_00871dc0();
    reinterpret_cast<::FUN_00454380_Class *>((((::ReloadRoot *)(::FUN_00451010()))))->FUN_00454380(0);
    reinterpret_cast<::Root *>((((::ReloadRoot *)(::FUN_00451010()))))->SetProcessEnabled(false);
    ReloadInterior* interiorData5;
    ReloadScene* cellB = ((::ReloadScene *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (cellB == destination)
    {
        reinterpret_cast<::TES *>(this)->FindCellAtPosition((const ::NiPoint3 *)(position), false);
    }
    else
    {
        if (((::ReloadInterface *)(::FUN_00b4f5c0())))
            ::fnv_00b65570::FUN_00b65570((char *)(((::ReloadInterface *)(::FUN_00b4f5c0()))), {});
        if (*(*reinterpret_cast<::ReloadBoolSetting *>(&::g_011c3d40)).FUN_00408d60())
        {
            if (!cellB)
            {
                if (((int)(reinterpret_cast<::TES_ExteriorBuffer *>(this)->FUN_00455200(1, (::TESWorldSpace *)(0)))))
                    reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(0);
            }
            else
            {
                reinterpret_cast<::fnv_00453940::FUN_00453940_shell *>(this)->FUN_00453940();
                if (((int)(reinterpret_cast<::TES_ExteriorBuffer *>(this)->FUN_00455200(1, (::TESWorldSpace *)(0)))))
                    reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(0);
            }
        }
        if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::ReloadMode * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() && !ReloadMenuActive(1007, 0) && !reinterpret_cast<::FUN_00ec17c0_Class *>(((*reinterpret_cast<::ReloadRuntime * *>(&::DAT_0126fac4))))->FUN_00ec17c0())
            reinterpret_cast<::fnv_0086ff70::Main86 *>(((*reinterpret_cast<::ReloadStreaming * *>(&::g_osGlobals))))->FUN_0086ff70();
        interiorData5 = ((::ReloadInterior *)(reinterpret_cast<::TESObjectCELL *>((destination))->FindEncounterZone()));
        if (interiorData5)
            reinterpret_cast<::FUN_00526270_shell *>((interiorData5))->FUN_00526270();
        ::BGSImpactDataSet::RefreshImpactData((::ImpactSwap *)(void *)(((void *)(reinterpret_cast<::FUN_00547610_shell *>((destination))->GetImpactSwap()))));
        reinterpret_cast<::fnv_00b5ddf0::LocalTarget *>((ReloadGetMain(0)))->FUN_00b5ddf0((::fnv_00b5ddf0::LocalContext *)(0));
        reinterpret_cast<::Owner *>((ReloadGetMain(0)))->FUN_00b5fd60();
        reinterpret_cast<::MultiBoundManagerB5D *>((ReloadGetMain(0)))->FUN_00b5d180();
        bool hadCell = false;
        if (cellB)
        {
            hadCell = true;
            reinterpret_cast<::CellTarget *>((cellB))->FUN_00552bd0(true);
            ::B4F9A0ShaderManager::ClearAllCachedStates();
            reinterpret_cast<::fnv_00b5cbd0::ShadowSceneNode_Self *>((ReloadGetMain(0)))->FUN_00b5cbd0(((void *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::ReloadPlayer * *>(&::_g_thePlayer))))->FUN_00950bb0(0))));
        }
        if (!reinterpret_cast<::fnv_00454bd0::TES *>(this)->ContainsCell((::TESObjectCELL *)(destination)))
        {
            ReloadScene* discard = ((::ReloadScene *)(reinterpret_cast<::FUN_00454420_Class *>(this)->GetEntry(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ReloadGridSetting *>(&::g_011c3e38)))))) - 1)));
            if (discard)
                reinterpret_cast<::FUN_00455330_cls *>(this)->RemoveEntry((std::uintptr_t)(discard));
        }
        cellB = destination;
        reinterpret_cast<::LowProcess *>(this)->SetCurrentBoundObject((::TESBoundObject *)(destination));
        FUN_00454440(1);
        if (cellB)
        {
            if (savedX == 0x7fffffff && !hadCell)
            {
                savedX = gridX;
                savedY = gridY;
                Pause(1, 0);
            }
            gridX = ::FUN_00406d90(position->x) >> 12;
            gridY = ::FUN_00406d90(position->y) >> 12;
            reinterpret_cast<::fnv_00550340::FUN_00550340_t *>((cellB))->FUN_00550340();
            bool modeA = false;
            bool _state = false;
            modeA = reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::ReloadMode * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10();
            _state = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::ReloadState * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
            if (reinterpret_cast<::FUN_00454400_shell *>((cellB))->GetRaceListSize() && !::FUN_00450fb0((void *)(cellB)))
                reinterpret_cast<::S457d70 *>(this)->FUN_00457d70(1, (::Form457 *)(::ReloadCell *)(reinterpret_cast<ReloadCell*>(cellB)), 0);
            reinterpret_cast<::fnv_00552970::FUN_00552970_Call *>((cellB))->UpdateCellScene((::NiNode *)(object));
            ReloadRoot* root = ((::ReloadRoot *)(reinterpret_cast<::FUN_004543c0_cls *>((cellB))->FUN_004543c0()));
            if (((void *)(::FUN_00559450((int *)&(loadedNode)))))
                reinterpret_cast<::fnv_00628da0::LoadedAreaBound *>((reinterpret_cast<ReloadLoaded*>(((void *)(::FUN_00559450((int *)&(loadedNode)))))))->FUN_00628da0();
            if (root)
                reinterpret_cast<::C00c66300 *>((root))->FUN_00c66300();
            reinterpret_cast<::SceneB54 *>((cellB))->FUN_0054bcf0(true);
            if (reinterpret_cast<::FUN_00447950_shell *>(((*reinterpret_cast<::ReloadCells * *>(&::g_modelLoader))))->FUN_00447950((::TESObjectCELL *)(::ReloadCell *)(reinterpret_cast<ReloadCell*>(cellB))))
                reinterpret_cast<::S457d70 *>(this)->FUN_00457d70(1, (::Form457 *)(::ReloadCell *)(reinterpret_cast<ReloadCell*>(cellB)), 0);
            reinterpret_cast<::FUN_00455400_tes *>(this)->UpdateSkyModeForCell((::TESObjectCELL *)(cellB));
            if (!modeA)
                reinterpret_cast<::IOManager *>(((*reinterpret_cast<::ReloadAudio * *>(&::DAT_01202d98))))->FUN_00c3dfa0(1);
            if (root)
                reinterpret_cast<::C6B540Manager *>((root))->FUN_00c6b540(0);
            reinterpret_cast<::B45CDA0TES *>(((*reinterpret_cast<::TileReloadContext * *>(&::g_TES))))->FUN_0045cda0();
            if (!reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(this)->FUN_00451530() && !modeA && (*reinterpret_cast<::ReloadPlayerCheck * *>(&::_g_thePlayer))->CheckState())
                reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::ReloadFade * *>(&::DAT_011d8804))))->AddFader((::FADER_ENUM)(true), 0.0f, 0);
            if (!modeA)
            {
                reinterpret_cast<::FUN_00975f90_cls *>(&((*reinterpret_cast<::ReloadTerrain *>(&::g_011e0e80))))->ClearMobileObjectData();
                reinterpret_cast<::fnv_00459870::FUN_00459870_cls *>(this)->ProcessItemNodes();
                reinterpret_cast<::ThisCls *>(&((*reinterpret_cast<::ReloadTerrain *>(&::g_011e0e80))))->FUN_00972d30();
                reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::ReloadTerrain *>(&::g_011e0e80))))->UpdateHighProcess();
            }
            reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(0);
            reinterpret_cast<::FUN_00460360_shell *>(((*reinterpret_cast<::ReloadData * *>(&::g_dataHandler))))->ProcessAllFiles();
            ReloadObject* cellObject7 = ((::ReloadObject *)(reinterpret_cast<::FUN_00545cf0_Cls *>((cellB))->GetOrCreateWidget()));
            reinterpret_cast<::FUN_00a5a040_Class *>((cellObject7))->FUN_00a5a040();
            if (!reinterpret_cast<::FUN_00453470_shell *>((cellObject7))->FUN_00453470())
            {
                ReloadPoint zero8(0.0f, 0, 0);
                reinterpret_cast<::FUN_00a59c60_cls *>((cellObject7))->FUN_00a59c60((std::intptr_t)(&zero8));
            }
            reinterpret_cast<::s54ba80::Owner *>((cellB))->FUN_0054ba80(true);
            FUN_00454c20(destination);
        }
        if (!hadCell)
        {
            ReloadInterface* interface = ((::ReloadInterface *)(::FUN_00b4f5c0()));
            if (interface)
                reinterpret_cast<::FUN_00b631d0_cls *>((interface))->FUN_00b631d0();
            ::TallGrassShaderProperty::ClearCaches();
            reinterpret_cast<::FUN_004baec0_shell *>((camera))->FUN_004baec0();
        }
        if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(this)->FUN_00451530())
            reinterpret_cast<::S457d70 *>(this)->FUN_00457d70(0, (::Form457 *)(::ReloadCell *)(0), 0);
        reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(this)->FUN_00452490(0);
        ::BGSDestructibleObjectForm::UpdateTargetHealthBar((::TESObjectREFR *)(0));
        if (*reinterpret_cast<::FUN_004543a0_Class *>((cellB))->FUN_004543a0())
        {
            ReloadContext context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 3188);
            ReloadNode node3(0);
            reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::TileReloadContext * *>(&::g_TES))))->FUN_004568c0(reinterpret_cast<::FUN_004543a0_Class *>((cellB))->FUN_004543a0(), (::TexPtr< ::NiSourceTexture> &)(node3), 1, 0);
            reinterpret_cast<::NiColorInterpolator *>((((::ReloadZone *)(::FUN_0070ec90((char *)((*reinterpret_cast<::TileReloadContext * *>(&::g_TES))))))))->SetColorData((::NiColorData *)(void *)(((void *)(::FUN_00559450((int *)&(node3))))));
        }
        else
            reinterpret_cast<::NiColorInterpolator *>((((::ReloadZone *)(::FUN_0070ec90((char *)((*reinterpret_cast<::TileReloadContext * *>(&::g_TES))))))))->SetColorData((::NiColorData *)(void *)(0));
        if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::ReloadMode * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
            reinterpret_cast<::fnv_006c39c0::FUN_006c39c0_shell *>((((::ReloadPathing *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c39c0();
    }
}

// On the abFlag1 path, may pass apForm to FUN_00705e00 and call manager methods; otherwise updates DAT_011c3efc and may run cleanup calls.
// @fnv 0x00457d70
bool S457d70::FUN_00457d70(bool abFlag1, Form457* apForm, bool abFlag2)
{
    if (abFlag1)
    {
        if (::Interface::IsGamePaused() && !((bool)(::FUN_00458140())))
        {
            ::UpdateIfEnabled((int)(apForm));
            return false;
        }
        if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(this)->FUN_00451530())
        {
            return false;
        }
        ::fnv_0063e010::FUN_0063e010((char *)(pTex68));
        FUN_00453a70()->SetAudioState(0x14);
        Form457* v8 = 0;
        Form457* v4 = 0;
        if (apForm)
        {
            switch (apForm->FUN_00401170())
            {
            case 0x41:
                v4 = apForm;
                break;
            case 0x39:
                v8 = apForm;
                if (v8 && !reinterpret_cast<::TESObjectCELL *>((v8))->IsCellInterior())
                {
                    v4 = ((::Form457 *)(reinterpret_cast<::TESObjectCELL *>((v8))->GetParentWorldSpace()));
                    apForm = v4;
                    v8 = 0;
                }
                break;
            case 0x3a:
            case 0x3b:
            case 0x3c:
            case 0x3d:
            case 0x3e:
            case 0x3f:
            case 0x40:
            case 0x69:
                v8 = ((::Form457 *)(reinterpret_cast<::LowProcess *>((apForm))->GetTarget()));
                if (v8 && !reinterpret_cast<::TESObjectCELL *>((v8))->IsCellInterior())
                {
                    v4 = ((::Form457 *)(reinterpret_cast<::TESObjectCELL *>((v8))->GetParentWorldSpace()));
                    v8 = 0;
                }
                else if (!v8)
                {
                    v4 = ((::Form457 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((apForm))->FUN_00575d70()));
                }
                break;
            }
        }
        ::Interface::SetQuestTarget((::TESForm *)(apForm), abFlag2);
        reinterpret_cast<::FUN_00458010_class *>((((::Mgr457 *)&(::BSFileCache::GetRandomGenerator()))))->FUN_00458010();
        ((::Mgr457 *)&(::BSFileCache::GetRandomGenerator()))->v30();
        reinterpret_cast<::FUN_00457ff0_class *>((((::Mgr457 *)&(::BSFileCache::GetRandomGenerator()))))->FUN_00457ff0();
        return true;
    }
    else
    {
        if (!((bool)(::FUN_004580e0())) || (((bool)(::FUN_004580e0())) && abFlag2))
        {
            DAT_011c3efc = 0;
            ::FUN_00458060(0);
            FUN_00705e30();
            if (FUN_00458030() != 0x18)
            {
                ::fnv_00771700::FUN_00771700(2);
            }
        }
        else
        {
            if (DAT_011c3efc == 0)
            {
                DAT_011c3efc = ((int)(::FUN_00457fe0())) + 0x1388;
            }
            if (((int)(::FUN_00457fe0())) > DAT_011c3efc)
            {
                DAT_011c3efc = 0;
                ::FUN_00458060(0);
                FUN_00705e30();
                if (FUN_00458030() != 0x18)
                {
                    ::fnv_00771700::FUN_00771700(2);
                }
            }
        }
    }
    return false;
}

#include <windows.h>
struct BatchPoint
{
    float x, y, z;
    BatchPoint();
    BatchPoint(float, float, float);
    void Reset();
};
struct BatchString
{
    char* data;
    unsigned short length, capacity;
    BatchString();
    ~BatchString();
    operator const char*() const;
};
struct BatchSettings
{
    bool flag0, flag1, flag2, flag3, flag4, flag5;
    char unk06, unk07;
    int savedPriority;
};
struct BatchPortalList
{
};
struct BatchPortal
{
};
struct BatchRegionList
{
};
struct BatchRegions
{
    int unk00;
    BatchRegionList list;
};
struct BatchTerrain
{
};
struct BatchWorld;
struct BatchCell
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void FunctionAtSlot4();
    virtual void FunctionAtSlot5();
    virtual void FunctionAtSlot6();
    virtual void VirtualFunction7();
    virtual void VirtualFunction8();
    virtual void VirtualFunction9();
    virtual void VirtualFunction10();
    virtual void ReplaceImpactData();
    virtual void reserved12();
    virtual void VirtualFunction13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void VirtualFunction22();
    virtual void VirtualFunction23();
    virtual void VirtualFunction24();
    virtual void VirtualFunction25();
    virtual void VirtualFunction26();
    virtual void VirtualFunction27();
    virtual void VirtualFunction28();
    virtual void VirtualFunction29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void reserved35();
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void reserved47();
    virtual void reserved48();
    virtual void reserved49();
    virtual void reserved50();
    virtual void reserved51();
    virtual void reserved52();
    virtual void reserved53();
    virtual void reserved54();
    virtual void reserved55();
    virtual void reserved56();
    virtual void reserved57();
    virtual void reserved58();
    virtual void reserved59();
    virtual void reserved60();
    virtual void reserved61();
    virtual void reserved62();
    virtual void reserved63();
    virtual void reserved64();
    virtual void reserved65();
    virtual void reserved66();
    virtual void reserved67();
    virtual void reserved68();
    virtual void reserved69();
    virtual void reserved70();
    virtual void reserved71();
    virtual void reserved72();
    virtual void reserved73();
    virtual void reserved74();
    virtual void reserved75();
    virtual const char* Name();
    BatchWorld* World();
};
struct BatchWorld
{
    BatchCell* Cell(int, int);
};
struct BatchWorldNode
{
};
struct BatchHandler
{
    void SetModelSizeOutputEnabled(bool);
    BatchCell* Cell(unsigned int);
};
struct BatchDestination
{
    BatchWorld* world;
    BatchCell* cell;
    BatchPoint position;
    BatchPoint angle;
    bool enabled;
    char unk21, unk22, unk23;
    int unk24, unk28, unk2c, unk30;
    BatchDestination();
};
struct BatchPlayer
{
    BatchWorld* World();
};
struct BatchIO
{
};
struct BatchCalendar
{
    void Update(float);
};
struct BatchSave
{
    void Update(int);
};
struct BatchProcess
{
};
struct BatchMemory
{
};
struct BatchTES
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    char unk50;
    bool active;
    char unk52, unk53;
    void(__cdecl* callback)(BatchCell*, void*);
    void* callbackArg;
    void* region;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    BatchWorld* currentWorld;
    BatchCell* IsCellInterior();
    void FUN_004556d0(int mode);
};
extern bool batchInitialized, batchNewWorld, batchLog;
extern int batchMode, batchInputDirection, batchX, batchY, batchExteriorCount;
extern unsigned int batchCellIndex, batchCellCount;
extern const char* batchLogFile;
extern BatchWorldNode* batchWorlds;
int __cdecl BatchCompare(const char*, const char*, unsigned int);

// Iterates through batch worlds and cells, moving the player to each and logging performance stats based on the specified mode.
// @fnv 0x004556d0
void BatchTES::FUN_004556d0(int mode)
{
    if (mode == 4 || mode == 5 || mode == 9)
        batchInitialized = true;
    switch (mode)
    {
    case 6:
    case 7:
        mode -= 5;
        batchInitialized = true;
        reinterpret_cast<::FUN_005a8040_class *>(this)->SetField54((std::intptr_t)(((void (&)())::fnv_00557dd0::FUN_00557dd0)));
        break;
    }
    switch (mode)
    {
    default:
        batchMode = mode;
        active = true;
        ::FUN_0043b2b0(true);
        ::FUN_00aff0b0(batchLogFile);
        if (!batchInitialized)
        {
            ::FUN_005b5e40();
            reinterpret_cast<::fnv_0046ddb0::ModelTest *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->FUN_0046ddb0(false);
            ::FUN_005b5e40();
            reinterpret_cast<::FUN_0046ec10_cls *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->ValidateFormIcons();
            batchInitialized = true;
        }
        if ((mode == 1 || mode == 4 || mode == 5 || mode == 9) && !batchWorlds && !batchCellCount)
        {
            batchWorlds = ((::BatchWorldNode *)(::FUN_00460140((std::intptr_t)((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))));
            batchNewWorld = true;
            reinterpret_cast<::SortHandler *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->FUN_004619b0();
            batchCellCount = ((unsigned int)(reinterpret_cast<::FUN_00461960_shell *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->FUN_00461960()));
            batchCellIndex = 0;
        }
        else if (mode == 3)
        {
            if (!batchWorlds || *((::BatchWorld **)((void *)(batchWorlds))) != currentWorld)
            {
                batchWorlds = ((::BatchWorldNode *)(::FUN_00460140((std::intptr_t)((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))));
                while (batchWorlds)
                {
                    BatchWorld* world = *((::BatchWorld **)((void *)(batchWorlds)));
                    if (world && world == currentWorld)
                        break;
                    batchWorlds = ((::BatchWorldNode *)(reinterpret_cast<::Callees *>((batchWorlds))->FUN_00726070()));
                }
            }
            if (batchWorlds)
            {
                batchNewWorld = true;
                reinterpret_cast<::SortHandler *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->FUN_004619b0();
                batchCellCount = ((unsigned int)(reinterpret_cast<::FUN_00461960_shell *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->FUN_00461960()));
                batchCellIndex = 0;
            }
        }
        else if (mode == 2)
        {
            bool changed = false;
            if (batchWorlds)
            {
                batchWorlds = 0;
                batchNewWorld = false;
                changed = true;
            }
            if (!batchCellCount)
            {
                reinterpret_cast<::SortHandler *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->FUN_004619b0();
                batchCellCount = ((unsigned int)(reinterpret_cast<::FUN_00461960_shell *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->FUN_00461960()));
                batchCellIndex = 0;
                changed = true;
            }
        }
        break;
    case -1:
        active = false;
        ::FUN_0043b2b0(false);
        region = 0;
        break;
    case 0:
        break;
    }
    bool again = true;
    while (again)
    {
        again = false;
        if (active)
        {
            if (mode == 9)
                again = true;
            BatchCell* cell = 0;
            int start = std::clock();
            INPUT input;
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_MOVE;
            input.mi.time = 0;
            input.mi.dy = 0;
            input.mi.mouseData = 0;
            input.mi.dwExtraInfo = 0;
            if (batchInputDirection > 0)
                input.mi.dx = 2;
            else
                input.mi.dx = -1;
            SendInput(1, &input, sizeof(INPUT));
            batchInputDirection = -batchInputDirection;
            if (batchNewWorld)
            {
                if (batchWorlds)
                {
                    BatchWorld* world = *((::BatchWorld **)((void *)(batchWorlds)));
                    while (world && !BatchCompare(((BatchCell*)world)->Name(), "test", 4))
                    {
                        batchWorlds = ((::BatchWorldNode *)(reinterpret_cast<::Callees *>((batchWorlds))->FUN_00726070()));
                        if (batchWorlds)
                            world = *((::BatchWorld **)((void *)(batchWorlds)));
                        else
                            world = 0;
                    }
                    if (world)
                    {
                        reinterpret_cast<::WS458200_Shell *>(this)->FUN_00458200((::WS458200_World *)(world));
                        batchX = ((int)reinterpret_cast<::FUN_004565f0_shell *>((currentWorld))->GetFloat()) >> 12;
                        batchY = ((int)reinterpret_cast<::FUN_00812870_t *>((currentWorld))->GetUnka4()) >> 12;
                        int maxX = ((int)reinterpret_cast<::LowProcess *>((currentWorld))->GetCurrentDetectionAmount()) >> 12;
                        int maxY = ((int)reinterpret_cast<::Getter_9b8 *>((currentWorld))->FUN_009b88c0()) >> 12;
                        ::FUN_005b5e40();
                    }
                }
                batchNewWorld = false;
            }
            bool found = false;
            bool done = false;
            while (!found && !batchNewWorld && !done)
            {
                if (batchWorlds)
                {
                    cell = ((::BatchCell *)(reinterpret_cast<::WorldCellLoader *>((currentWorld))->FUN_00585b30(batchX, batchY)));
                    if (cell)
                        reinterpret_cast<::FUN_00454e70_shell *>(this)->MoveCellToFront((::TESObjectCELL *)(cell));
                    batchY++;
                    if (batchY > (((int)reinterpret_cast<::Getter_9b8 *>((currentWorld))->FUN_009b88c0()) >> 12))
                    {
                        batchY = ((int)reinterpret_cast<::FUN_00812870_t *>((currentWorld))->GetUnka4()) >> 12;
                        batchX++;
                        if (batchX > (((int)reinterpret_cast<::LowProcess *>((currentWorld))->GetCurrentDetectionAmount()) >> 12))
                        {
                            batchWorlds = ((::BatchWorldNode *)(reinterpret_cast<::Callees *>((batchWorlds))->FUN_00726070()));
                            if (batchWorlds)
                                batchNewWorld = true;
                        }
                    }
                }
                else
                {
                    if (!batchCellIndex)
                        ::FUN_005b5e40();
                    cell = ((::BatchCell *)(reinterpret_cast<::Stub *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->GetCameraPathAt(batchCellIndex)));
                    batchCellIndex++;
                    while (cell && !BatchCompare(cell->Name(), "test", 4))
                    {
                        cell = ((::BatchCell *)(reinterpret_cast<::Stub *>(((*reinterpret_cast<::BatchHandler * *>(&::g_dataHandler))))->GetCameraPathAt(batchCellIndex)));
                        batchCellIndex++;
                    }
                    if (!cell)
                        done = true;
                }
                if (cell && !reinterpret_cast<::FUN_00440d80_shell *>((cell))->FUN_00440d80() && reinterpret_cast<::s54cee0::Owner *>((cell))->FUN_0054cee0())
                    found = true;
            }
            if (cell && found)
            {
                BatchRegions* regions = ((::BatchRegions *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetRegionList(true)));
                if (region)
                {
                    if (!regions || !reinterpret_cast<::RefList *>(&(regions->list))->FUN_005f65d0((void **)&(region)))
                        found = false;
                }
            }
            else if (batchNewWorld)
            {
                if (((::BatchWorld *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((*reinterpret_cast<::BatchPlayer * *>(&::_g_thePlayer))))->FUN_00575d70())) != currentWorld)
                    again = true;
            }
            if (found)
            {
                reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::BatchCalendar *>(&::g_011de7b8))))->Update(10.0f);
                BatchPoint position4 = (*reinterpret_cast<::BatchPoint *>((void *)&::NiPoint3::ZERO));
                if (!reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
                    position4 = BatchPoint((reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX() << 12) + 2048.0, (reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY() << 12) + 2048.0, 0.0f);
                if (reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
                {
                    reinterpret_cast<::fnv_00550340::FUN_00550340_t *>((cell))->FUN_00550340();
                    BatchPoint rotation;
                    reinterpret_cast<::fnv_0054cfd0::TESObjectCELL_Ext *>((cell))->FUN_0054cfd0((::fnv_0054cfd0::NiPoint3 *)(::BatchPoint *)(&position4), (::fnv_0054cfd0::NiPoint3 *)(::BatchPoint *)(&rotation));
                    reinterpret_cast<::ReloadManager *>(this)->AttachScene((::ReloadScene *)(cell), (::ReloadPoint *)(::BatchPoint *)(&position4));
                }
                else if (((::BatchCell *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
                {
                    reinterpret_cast<::fnv_00454450::ReloadManager *>(this)->FUN_00454450((::fnv_00454450::ReloadPoint *)(::BatchPoint *)(&position4));
                    float height;
                    reinterpret_cast<::TESObjectLAND *>((((::BatchTerrain *)(reinterpret_cast<::S00546fb0_Cell *>((cell))->FUN_00546fb0()))))->FUN_0053f180((const ::LandscapeColorData &)(position4), height);
                    if (height >= 0.0)
                        position4.z = height;
                }
                else
                {
                    reinterpret_cast<::TES *>(this)->FindCellAtPosition((const ::NiPoint3 *)(::BatchPoint *)(&position4), false);
                    float height;
                    reinterpret_cast<::TESObjectLAND *>((((::BatchTerrain *)(reinterpret_cast<::S00546fb0_Cell *>((cell))->FUN_00546fb0()))))->FUN_0053f180((const ::LandscapeColorData &)(position4), height);
                    if (height >= 0.0)
                        position4.z = height;
                }
                BatchDestination* destination5 = new BatchDestination;
                destination5->position = position4;
                destination5->angle = (*(const ::BatchPoint *)(reinterpret_cast<::TESRecipe *>(((*reinterpret_cast<::BatchPlayer * *>(&::_g_thePlayer))))->GetData()));
                destination5->enabled = true;
                if (reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
                    destination5->cell = cell;
                else
                    destination5->world = ((::BatchWorld *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace()));
                reinterpret_cast<::B93BE30ProcessManager *>(((*reinterpret_cast<::BatchPlayer * *>(&::_g_thePlayer))))->FUN_0093be30((::B93BE30Request *)(destination5));
                reinterpret_cast<::FUN_0093bea0_cls *>(((*reinterpret_cast<::BatchPlayer * *>(&::_g_thePlayer))))->FUN_0093bea0();
                reinterpret_cast<::FUN_00456520_Class *>(((*reinterpret_cast<::BatchIO * *>(&::DAT_01202d98))))->FUN_00456520();
                int finish3 = std::clock();
                float elapsed = (finish3 - start) / 1000.0;
                BatchSettings settings8;
                ::FUN_00878160((char*)&settings8, true, true, true);
                reinterpret_cast<::FUN_004539a0_cls *>(((*reinterpret_cast<::BatchTES * *>(&::g_TES))))->FUN_004539a0(true, false);
                ::FUN_00878250(settings8.flag5);
                ::FUN_00878200((unsigned char*)&settings8);
                if (batchLog)
                {
                    float textureCount9 = 0.0f;
                    float modelCountTmp = 0.0f;
                    BatchString modelString2;
                    ::fnv_004a8bb0::FUN_004a8bb0(&textureCount9, &modelCountTmp, true, true);
                    ::FUN_004a9120(modelCountTmp, (char *)(::BatchString *)(&modelString2), 0);
                    bool portalsVal = false;
                    BatchPortal* graphTmp = ((::BatchPortal *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((cell))->FUN_009d9f20()));
                    if (graphTmp && !reinterpret_cast<::FUN_0076b610_Class *>((((::BatchPortalList *)(reinterpret_cast<::BGSCameraPath *>((graphTmp))->GetShotList()))))->FUN_0076b610())
                        portalsVal = true;
                    unsigned int memory2 = 0;
                    BatchMemory* entry30 = ((::BatchMemory *)(::FUN_00456510()));
                    while (entry30)
                    {
                        if (reinterpret_cast<::ActorMover *>((entry30))->GetCurrentMoveModeType())
                            memory2 += ::FUN_005b5e40();
                        entry30 = ((::BatchMemory *)(reinterpret_cast<::BGSMessageInitAccess *>((entry30))->GetIconFormID()));
                    }
                    memory2 >>= 20;
                    // The original initializes three diagnostic counters without reading them.
                    int count13 = 0;
                    int numA2 = 0;
                    int numB9 = 0;
                    unsigned int actors3 = reinterpret_cast<::FUN_0096bc50_shell *>(&((*reinterpret_cast<::BatchProcess *>(&::g_011e0e80))))->CountHighProcessActors();
                    if (reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
                    {
                        ::FUN_005b5e40(
                            );
                        ::FUN_00c3c220();
                    }
                    else
                    {
                        batchExteriorCount++;
                        ::FUN_005b5e40(
                            );
                        ::FUN_00c3c220();
                    }
                }
                if (callback)
                    callback(cell, callbackArg);
                if (batchMode == 4 || batchMode == 5)
                    reinterpret_cast<::TESSaveLoadGame_861f20 *>(((*reinterpret_cast<::BatchSave * *>(&::g_TESSaveLoadGame))))->FUN_00861f20(batchMode);
            }
            if (batchCellIndex >= batchCellCount)
            {
                batchCellCount = 0;
                active = false;
                ::FUN_0043b2b0(false);
                region = 0;
            }
        }
    }
    switch (mode)
    {}
}

struct MagicItem
{
    int value;
};
struct TESForm
{
    virtual void formVirtual();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
public:
    bool GetDisabled() const;
public:
    void ClearData();
};
// Gets the form type of apRef's object reference and returns true only if apRef is neither deleted nor disabled.
// @fnv 0x00451e40
bool TES::IsRefUsable(TESObjectREFR* apRef)
{
    unsigned char type = ((::FNVHelper *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((FNVHelper*)apRef)))->FUN_007af430()))->_FNV_GetFormType();
    return !reinterpret_cast<::FUN_00440d80_shell *>((void *)(((RefH*)apRef)))->FUN_00440d80() && !reinterpret_cast<::TESForm *>((((RefH*)apRef)))->GetDisabled();
}
// Attaches ref to cell: handles special cases, picks a node from other or ref, adds ref to the cell, and updates actor/tree state.
// @fnv 0x00451ef0
void AttachmentHandler::FUN_00451ef0(AttachRef* ref, AttachCell* cell, AttachRef* other, bool skip)
{
    if (!ref)
        return;
    if (ref->IsSpecialB())
    {
        AttachRef* specialB = ref;
        specialB->HandleB();
        return;
    }
    if (ref->IsSpecialA())
    {
        AttachRef* specialA = ref;
        specialA->HandleA();
        return;
    }
    reinterpret_cast<::ActorStateHandler *>(this)->FUN_00451da0((::ActorLike *)(ref));
    unsigned char type = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FUN_00401170();
    if (reinterpret_cast<::TES *>(this)->IsRefUsable((::TESObjectREFR *)(ref)))
    {
        if (!skip)
            reinterpret_cast<::fnv_00451ea0::TES *>(this)->FUN_00451ea0((::fnv_00451ea0::TESObjectREFR *)(ref));
        AttachNode* node = 0;
        if (other && ((::AttachNode *)(reinterpret_cast<::FUN_005d8710_shell *>((other))->FUN_005d8710())))
        {
            node = ((::AttachNode *)(reinterpret_cast<::FUN_005d8710_shell *>((other))->FUN_005d8710()));
            if (!((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((ref))->FUN_0043fcd0())))
                reinterpret_cast<::fnv_00570f70::Obj570 *>((ref))->FUN_00570f70((std::intptr_t)(node));
        }
        else
            node = ref->GetNode(0);
        AttachNode* chosen = node;
        if (other)
            other->FinalizeAttach();
        if (chosen)
        {
            if (type == 44 || type == 45)
            {
                if (((::NodeOwner *)(reinterpret_cast<::FUN_009611e0_shell *>((chosen))->FUN_009611e0())))
                    ((::NodeOwner *)(reinterpret_cast<::FUN_009611e0_shell *>((chosen))->FUN_009611e0()))->Release(chosen);
            }
            else
            {
                reinterpret_cast<::FUN_00545cf0_Cls *>((cell))->GetOrCreateWidget();
                reinterpret_cast<::ShadowSceneNode *>((FUN_00450b80(0)))->AddObject((::NiAVObject *)(chosen));
                if (ref->IsActor())
                    reinterpret_cast<::fnv_00b5cbd0::ShadowSceneNode_Self *>((FUN_00450b80(0)))->FUN_00b5cbd0(chosen);
                if (reinterpret_cast<::FUN_00564e60_shell *>((ref))->FUN_00564e60())
                    reinterpret_cast<::FUN_00452390_shell *>((cell))->FUN_00452390();
                bool add = true;
                if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FUN_00401170() == 35)
                {
                    TESBoundObject* base = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
                    if (reinterpret_cast<::FUN_00452440_shell *>((base))->FUN_00452440())
                        add = false;
                }
                if (add)
                {
                    reinterpret_cast<::fnv_00548880::FNV_Cell *>((cell))->FUN_00548880((::fnv_00548880::FNV_Ref *)(ref), 0);
                    reinterpret_cast<::fnv_0056f700::Ref *>((ref))->FUN_0056f700();
                }
                if (reinterpret_cast<::FUN_00452370_shell *>((ref))->FUN_00452370() && reinterpret_cast<::B200Owner *>((ref))->FUN_0057b200())
                    ::fnv_00578170::FUN_00578170((::NiNode *)(::TESObjectREFR *)((TESObjectREFR*)chosen));
                else if (reinterpret_cast<::Holder4523e0 *>((ref))->FUN_004523e0(2))
                {
                    if (::FUN_00450ff0((void *)(cell)) || reinterpret_cast<::FUN_004523c0_shell *>((cell))->FUN_004523c0())
                        ::FUN_00578060((::NodeView *)(::TESObjectREFR *)((TESObjectREFR*)chosen));
                }
                if (ref->IsActor())
                {
                    AttachRef* actor = ref;
                    if (actor)
                        reinterpret_cast<::TESForm *>((actor))->ClearData();
                }
                if (type == 30)
                    reinterpret_cast<::FUN_004534f0_shell *>((((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))))->FUN_004534f0((std::uintptr_t)(((void *)(reinterpret_cast<::TESRecipe *>((ref))->GetData()))));
                else
                    reinterpret_cast<::S00b5d9f0_Owner *>((FUN_00450b80(0)))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(chosen), 0);
            }
        }
        reinterpret_cast<::FUN_00565730_shell *>((ref))->FUN_00565730();
        if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::AttachContext * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
        {
            ::FUN_005ac190((::TESObjectREFR *)(ref), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()));
            ::FUN_005ac750((::TESForm *)(ref), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()), 4096);
        }
        if (type == 37)
        {
            TESObjectTREE* tree = dynamic_cast<TESObjectTREE*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())));
            if (tree && FUN_00452480())
            {
                TreeDimensions treeDimensions = *((::TreeDimensions *)(::FUN_0045bb80((std::intptr_t)(tree))));
                if (treeDimensions.x > ::DAT_010179e0 && treeDimensions.y > ::DAT_010179e0)
                {
                    cell->FUN_00547ad0(*ref->GetPoint((unsigned int)(tree->GetTreeScale(1.0f) * ((double)(reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((ref))->FUN_00567400())))));
                }
            }
        }
        if (ref->IsActor())
        {
            AttachRef* actor2 = ref;
            reinterpret_cast<::Actor *>((actor2))->UpdateActorPresentation();
            if (ref != (*reinterpret_cast<::AttachRef * *>(&::_g_thePlayer)))
                ::SetObjectFormID((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((actor2))->FUN_0043fcd0()))), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ref))->FUN_0084e3a0())));
        }
    }
}
// @fnv 0x004539a0
void FUN_004539a0_cls::FUN_004539a0(unsigned char a1, unsigned char a2)
{
    reinterpret_cast<::FileMatchList *>((((FUN_004539a0_helperA*)((::FUN_004539a0_cls *)(::FUN_0045bb80((std::intptr_t)this))))))->RemoveAll();
    if (a1 == 0 || ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())) != 0)
    {
        reinterpret_cast<::fnv_00453940::FUN_00453940_shell *>(this)->FUN_00453940();
    }
    reinterpret_cast<::TESForm *>((((FUN_004539a0_helperB*)FUN_00453a70())))->ClearData();
    reinterpret_cast<::TES_ExteriorBuffer *>(this)->FUN_00455200(a1, (::TESWorldSpace *)(0));
    if (((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())) != 0 && a1 == 0)
    {
        if (!reinterpret_cast<::fnv_00454bd0::TES *>(this)->ContainsCell(((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))))
        {
            reinterpret_cast<::DeletionDataHandler *>((g_dataHandler))->DeleteObject((::DeletionObject *)(::TESObjectCELL *)(((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))));
        }
    }
    FUN_00454d50(a1);
    if (a1 == 0 && a2 == 0)
    {
        reinterpret_cast<::LowProcess *>(this)->SetCurrentBoundObject((::TESBoundObject *)(0));
    }
    unkB4 = 1;
}

class SpellItem : public TESForm, public MagicItem
{
};
class TESEnchantableForm
{
  public:
    virtual void enchantVirtual();
};
struct SpellNode
{
};
struct SpellList
{
};
struct ActorBaseView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    SpellList spells;
};
struct RaceView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    SpellList spells;
};
struct MagicTarget
{
    int t0;
    bool HasSpell(MagicItem*, bool);
};
struct CasterView
{
    virtual void AddSpell(SpellItem*, bool);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Apply(SpellItem*, MagicTarget*, bool);
    virtual void ApplyEnchantment(MagicItem*, TESBoundObject*, bool);
    int c4;
    int c8;
};
struct ItemEntry
{
    TESBoundObject* FUN_0044ddc0();
    void* FUN_004459e0(bool);
};
class TESObjectREFR;
struct InventoryChanges
{
public:
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
};
struct ActorFields
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void virtual74();
    virtual void virtual75();
    virtual void virtual76();
    virtual void virtual77();
    virtual void virtual78();
    virtual void virtual79();
    virtual void virtual80();
    virtual void virtual81();
    virtual void virtual82();
    virtual void virtual83();
    virtual void virtual84();
    virtual void virtual85();
    virtual void virtual86();
    virtual void virtual87();
    virtual void virtual88();
    virtual void virtual89();
    virtual void virtual90();
    virtual void virtual91();
    virtual void virtual92();
    virtual void virtual93();
    virtual void virtual94();
    virtual void virtual95();
    virtual void virtual96();
    virtual void virtual97();
    virtual void virtual98();
    virtual void virtual99();
    virtual void virtual100();
    virtual void virtual101();
    virtual void virtual102();
    virtual void virtual103();
    virtual void virtual104();
    virtual void virtual105();
    virtual void virtual106();
    virtual void virtual107();
    virtual void virtual108();
    virtual void virtual109();
    virtual void virtual110();
    virtual void virtual111();
    virtual void virtual112();
    virtual void virtual113();
    virtual void virtual114();
    virtual void virtual115();
    virtual void virtual116();
    virtual void virtual117();
    virtual void virtual118();
    virtual void virtual119();
    virtual void virtual120();
    virtual void virtual121();
    virtual void virtual122();
    virtual void virtual123();
    virtual void virtual124();
    virtual void virtual125();
    virtual void virtual126();
    virtual void virtual127();
    virtual void virtual128();
    virtual void virtual129();
    virtual void virtual130();
    virtual void virtual131();
    virtual void virtual132();
    virtual void virtual133();
    virtual void virtual134();
    virtual void virtual135();
    virtual void virtual136();
    virtual void virtual137();
    virtual void virtual138();
    virtual void virtual139();
    virtual void virtual140();
    virtual void virtual141();
    virtual void virtual142();
    virtual void virtual143();
    virtual void virtual144();
    virtual void virtual145();
    virtual void virtual146();
    virtual void virtual147();
    virtual void virtual148();
    virtual void virtual149();
    virtual void virtual150();
    virtual void virtual151();
    virtual void virtual152();
    virtual void virtual153();
    virtual void virtual154();
    virtual void virtual155();
    virtual void virtual156();
    virtual void virtual157();
    virtual void virtual158();
    virtual void virtual159();
    virtual void virtual160();
    virtual void virtual161();
    virtual void virtual162();
    virtual void virtual163();
    virtual void virtual164();
    virtual void virtual165();
    virtual void virtual166();
    virtual void virtual167();
    virtual void virtual168();
    virtual void virtual169();
    virtual void virtual170();
    virtual void virtual171();
    virtual void virtual172();
    virtual void virtual173();
    virtual void virtual174();
    virtual void virtual175();
    virtual void virtual176();
    virtual void virtual177();
    virtual void virtual178();
    virtual void virtual179();
    virtual void virtual180();
    virtual void virtual181();
    virtual void virtual182();
    virtual void virtual183();
    virtual void virtual184();
    virtual void virtual185();
    virtual void virtual186();
    virtual void virtual187();
    virtual void virtual188();
    virtual void virtual189();
    virtual void virtual190();
    virtual void virtual191();
    virtual void virtual192();
    virtual void virtual193();
    virtual void virtual194();
    virtual void virtual195();
    virtual void virtual196();
    virtual void virtual197();
    virtual void virtual198();
    virtual void virtual199();
    virtual void virtual200();
    virtual void virtual201();
    virtual void virtual202();
    virtual void virtual203();
    virtual void virtual204();
    virtual void virtual205();
    virtual void virtual206();
    virtual void virtual207();
    virtual void virtual208();
    virtual void virtual209();
    virtual void virtual210();
    virtual void virtual211();
    virtual void virtual212();
    virtual void virtual213();
    virtual void virtual214();
    virtual void virtual215();
    virtual void virtual216();
    virtual void virtual217();
    virtual void virtual218();
    virtual void virtual219();
    virtual void virtual220();
    virtual void virtual221();
    virtual void virtual222();
    virtual RaceView* GetRace();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
};
struct ActorSpellView : public ActorFields, public CasterView, public MagicTarget
{
    bool HandleRef(ItemEntry*);
    void UpdateSpells(bool equipped);
};
// Adds actor and race spells when unequipped, applies qualifying inventory enchantments when equipped, and adds the default spell if absent.
// @fnv 0x008c26e0
void ActorSpellView::UpdateSpells(bool equipped)
{
    ItemEntry* released7;
    ItemEntry* releasedA;
    SpellItem* defaultSpell2;
    int previous9;
    bool found5;
    ItemEntry* pEntry7;
    SpellItem* enchantment4;
    TESEnchantableForm* enchantable5;
    int clearIndexA;
    int clearIndex6;
    InventoryChanges* _pChangeNode;
    TESBoundObject* seen8[20];
    SpellItem* spell4;
    SpellItem* pSpell;
    SpellNode* node;
    TESForm* aDefaultForm5;

    if (!equipped)
    {
        node = ((::SpellNode *)(reinterpret_cast<::BaseProcess *>(&(((::ActorBaseView *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))->spells))->GetCurrentProcessData()));
        while (node)
        {
            pSpell = *((::SpellItem **)((void *)(node)));
            if (pSpell)
            {
                AddSpell(pSpell, true);
                Apply(pSpell, this, true);
            }
            node = ((::SpellNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        node = GetRace() ? ((::SpellNode *)(reinterpret_cast<::BaseProcess *>(&(GetRace()->spells))->GetCurrentProcessData())) : 0;
        while (node)
        {
            spell4 = *((::SpellItem **)((void *)(node)));
            if (spell4)
            {
                AddSpell(spell4, true);
                Apply(spell4, this, true);
            }
            node = ((::SpellNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }
    else
    {
        _pChangeNode = ::InventoryChanges::CreateForReference((::TESObjectREFR *)(void *)(this));

        for (clearIndex6 = 0; clearIndex6 < 20; ++clearIndex6)
            seen8[clearIndex6] = 0;
        for (clearIndexA = 0; clearIndexA < 20; ++clearIndexA)
        {
            pEntry7 = ((::ItemEntry *)(reinterpret_cast<::Target *>((_pChangeNode))->FUN_004c8c10(clearIndexA, 0)));
            enchantable5 = pEntry7 ? dynamic_cast<TESEnchantableForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pEntry7))->GetName()))) : 0;
            enchantment4 = enchantable5 ? ((::SpellItem *)(reinterpret_cast<::Callees *>((enchantable5))->FUN_00726070())) : 0;
            if (enchantment4)
            {
                found5 = false;
                for (previous9 = 0; previous9 < clearIndexA && !found5; ++previous9)
                    found5 = seen8[previous9] && seen8[previous9] == ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pEntry7))->GetName()));
                if (!found5 && HandleRef(pEntry7))
                {
                    ApplyEnchantment(enchantment4, ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pEntry7))->GetName())), true);
                    seen8[clearIndexA] = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pEntry7))->GetName()));
                }
            }
            {
                released7 = pEntry7;
                releasedA = released7;
                releasedA ? releasedA->FUN_004459e0(true) : 0;
            }
        }
    }
    aDefaultForm5 = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(19));
    if (aDefaultForm5)
    {
        defaultSpell2 = dynamic_cast<SpellItem*>(aDefaultForm5);
        if (defaultSpell2 && !HasSpell(defaultSpell2, true))
            AddSpell(defaultSpell2, true);
    }
}

namespace fnv_0045a370 {
struct AutoMemHelper
{
    int state;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct SettingT_GameSettingCollection_
{
};
struct QueueHelper
{
};
struct TextureLoader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    void* texture;
    void FUN_0045a370();
};
// Queues each nonempty setting string and loads a texture using a path built under Data\Textures.
// @fnv 0x0045a370
void TextureLoader::FUN_0045a370()
{
    AutoMemHelper context(7, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TES.cpp", 7152);
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011d14c4))))->GetMenuTitle())))
        reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::fnv_0045a370::QueueHelper * *>(&::g_modelLoader))))->FUN_00444040((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011d14c4))))->GetMenuTitle()))), 5, 0, 0, true, true, false);
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011cebb0))))->GetMenuTitle())))
        reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::fnv_0045a370::QueueHelper * *>(&::g_modelLoader))))->FUN_00444040((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011cebb0))))->GetMenuTitle()))), 5, 0, 0, true, true, false);
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011d12c0))))->GetMenuTitle())))
        reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::fnv_0045a370::QueueHelper * *>(&::g_modelLoader))))->FUN_00444040((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011d12c0))))->GetMenuTitle()))), 5, 0, 0, true, true, false);
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011d0ce4))))->GetMenuTitle())))
        reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::fnv_0045a370::QueueHelper * *>(&::g_modelLoader))))->FUN_00444040((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011d0ce4))))->GetMenuTitle()))), 5, 0, 0, true, true, false);
    if (*((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011cfd40))))->GetMenuTitle())))
    {
        char path[260];
        ::FUN_00406d00(path, 260, "%s\\%s\\%s", "Data", "Textures", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0045a370::SettingT_GameSettingCollection_ *>(&::g_011cfd40))))->GetMenuTitle())));
        reinterpret_cast<::TESTexLoader *>(this)->FUN_004568c0(path, (*(::TexPtr< ::NiSourceTexture> *)(&texture)), false, false);
    }
}
}  // namespace fnv_0045a370

namespace fnv_00454c20 {
struct RecentLimit
{
};
struct RecentReleaser
{
    void DeleteObject(void*);
};
struct RecentItems
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    void** items;
    void FUN_00454c20(void*);
};
// Moves item to the front of items, shifting entries down and releasing the last entry when it is non-null.
// @fnv 0x00454c20
void RecentItems::FUN_00454c20(void* item)
{
    int last;
    if (reinterpret_cast<::fnv_00454bd0::TES *>(this)->ContainsCell((::TESObjectCELL *)(item)))
    {
        for (unsigned int index = 0; index < ((unsigned int)(reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::fnv_00454c20::RecentLimit *>(&::g_011c3e38))))->GetCellStandValue())); index++)
        {
            if (items[index] == item)
            {
                while (index != 0)
                {
                    items[index] = items[index - 1];
                    index--;
                }
                items[0] = item;
                break;
            }
        }
    }
    else
    {
        last = ((unsigned int)(reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::fnv_00454c20::RecentLimit *>(&::g_011c3e38))))->GetCellStandValue())) - 1;
        for (int slot = last; slot >= 0; slot--)
        {
            if (slot == last && items[slot])
            {
                reinterpret_cast<::DeletionDataHandler *>(((*reinterpret_cast<::fnv_00454c20::RecentReleaser * *>(&::g_dataHandler))))->DeleteObject((::DeletionObject *)(items[slot]));
            }
            if (slot != 0)
            {
                items[slot] = items[slot - 1];
            }
            else
            {
                items[slot] = 0;
            }
        }
        items[0] = item;
    }
}
}  // namespace fnv_00454c20

namespace fnv_0062f460 {
struct FUN_0062e780_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    float maximum;
    int dimension;
    int originX, originY;
};
struct GridCell
{
    TESObjectCELL* cell;
};
struct GridCalls
{
};
struct FUN_0062e710_shell
{
};
struct FUN_005471e0_shell
{
};
struct CellCoords
{
};
struct FUN_004036b0_Class
{
};
struct bhkEntityListener_shell
{
};
// @fnv 0x0062f460
void __cdecl FUN_0062f460()
{
    FUN_0062e780_Class* width = ((::fnv_0062f460::FUN_0062e780_Class *)(::FUN_0062f3d0()));
    width->maximum = ::DAT_01015f5c;
    int height = width->dimension;
    int first = width->dimension;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < first; y++)
        {
            float value = ::DAT_01015f5c;
            TESObjectCELL* cell = ((::fnv_0062f460::GridCell *)(reinterpret_cast<::TES *>((((GridCalls*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00457050(x, y)))->cell;
            if (cell && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(((MobileObjectCellAccess*)cell)))->FUN_004518e0())
                value = reinterpret_cast<::FUN_005471e0_shell *>((((FUN_005471e0_shell*)cell)))->FUN_005471e0();
            reinterpret_cast<::FUN_0062e710_shell *>((((FUN_0062e710_shell*)width)))->SetValueAt(value, x, y);
            if (width->maximum < value)
                width->maximum = value;
        }
    }
    TESObjectCELL* data = ((::fnv_0062f460::GridCell *)(reinterpret_cast<::TES *>((((GridCalls*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00457050(0, 0)))->cell;
    if (data)
    {
        width->originX = reinterpret_cast<::TESObjectCELL *>((((CellCoords*)data)))->GetCellGridX();
        width->originY = reinterpret_cast<::TESObjectCELL *>((((CellCoords*)data)))->GetCellGridY();
    }
    if (!reinterpret_cast<::FUN_004036b0_Class *>((((FUN_004036b0_Class*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_004036b0() && width->maximum == ::DAT_010241b0)
        reinterpret_cast<::bhkEntityListener_shell *>((((bhkEntityListener_shell*)width)))->FUN_00937090(false);
}
}  // namespace fnv_0062f460

struct FadeAttachedCell
{
};

struct FadeAttachedTES
{
    void* unk00;
    void* unk04;
    GridCellArray* m_pGridCells;

    void FUN_00459a00();
};

// @fnv 0x00459a00
void FadeAttachedTES::FUN_00459a00()
{
    if (!g_dataHandler)
    {
        return;
    }

    if (((void *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath())) != 0)
    {
        if (::FUN_00450ff0((void *)(reinterpret_cast<CellExt*>(((void *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath()))))))
        {
            reinterpret_cast<::s5573e0::Owner *>((reinterpret_cast<FadeAttachedCell*>(((void *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath())))))->FUN_005573e0();
        }
    }

    unsigned int x = 0;
    for (; x < *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); ++x)
    {
        unsigned int y = 0;
        for (; y < *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))); ++y)
        {
            void* pgridcell = (m_pGridCells->Get(x, y));
            TESObjectCELL* pcell = reinterpret_cast<TESObjectCELL*>(*reinterpret_cast<void**>(pgridcell));

            if (pcell != 0)
            {
                if (::FUN_00450ff0((void *)(reinterpret_cast<CellExt*>(pcell))))
                {
                    reinterpret_cast<::s5573e0::Owner *>((reinterpret_cast<FadeAttachedCell*>(pcell)))->FUN_005573e0();
                }
            }
        }
    }
}

struct NiPoint3_o2;

struct TESObjectCELL_o2;

struct TESDataHandler_o2
{
    static bool LoadForm(TESForm*, TESFile*);
    bool SaveForm(TESForm*, bool);
    char* GetFormName(unsigned char);
    void OutputFormList();
    void SetModelSizeOutputEnabled(bool);
    void OutputModelSizeList();
    void CheckTexturesRecurse(NiAVObject*, char*);
    static bool CheckDismemberSkinInstanceRecurse(NiAVObject*, char*);
    void PrintTextureInfo(void*, NiTriBasedGeom*, char*, char*, bool);
    void OutputTextureInfo();
    void CheckTexturePath(char*);
    bool AddFormToDataHandler(TESForm*);
    void ReleaseForm(TESForm*);
    unsigned char NotUniqueID(char*);
    void GetObjectCounts();
    void GetReferenceCounts();
    void GetRegions();
    void InitializeMagicSystem();
    void GetReferencesInArea(TESObjectCELL_o2*, void*, float, void*, float, int*, long);
    void GetReferencesInArea(void*, float, void*, float, int*, long);
    void EnumReferencesCloseToRef(TESObjectREFR*, float, void*, float, int*, long);
    static bool ReferenceBaseSearchEnumFunc(TESObjectREFR*, intptr_t);
    bool FindTeleportPathBetweenSmallSpaces(TESForm*, TESForm*, void*);
    bool FindTeleportPathBetweenWorlds(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindTeleportPathFromSmallSpaceToWorld(TESForm*, TESWorldSpace*, void*, bool);
    TESObjectREFR* FindFirstReference(TESObject*);
    TESObjectREFR* FindFirstReference(char*);
    bool FindConnectedWorld(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindConnectedSmallSpace(TESForm*, TESForm*, void*, void*);
    TESWorldSpace* BuildPathNodeLocation(TESForm*, NiPoint3_o2*, void*);
    TESObjectREFR* FindClosestReference(TESBoundObject*, void*, TESObjectCELL_o2*);
    TESObjectREFR* FindClosestReference(char*, void*, TESObjectCELL_o2*);
    TESObjectREFR* GetReference(char*);
    TESObjectREFR* GetReference(unsigned int);
    TESLandTexture* GetLandTexture(char*);
    TESLandTexture* GetLandTexture(unsigned int);
    TESRace* GetRace(char*);
    TESRace* GetRace(unsigned int);
    TESClass* GetClass(char*);
    TESClass* GetClass(unsigned int);
    Script* GetScript(char*);
    Script* GetScript(unsigned int);
    TESSound* GetSoundByEditorID(char*);
    TESSound* GetSoundByEditorID(unsigned int);
    TESGlobal* GetGlobal(char*);
    TESGlobal* GetGlobal(unsigned int);
    BGSVoiceType* GetVoiceType(unsigned int);
    TESFaction* GetFactionByFormID(char*);
    TESFaction* GetFactionByFormID(unsigned int);
    TESReputation* GetReputation(char*);
    TESReputation* GetReputation(unsigned int);
    TESRecipe* GetRecipe(char*);
    TESRecipe* GetRecipe(unsigned int);
    TESRecipeCategory* GetRecipeCategory(char*);
    TESRecipeCategory* GetRecipeCategory(unsigned int);
    TESCasino* GetCasino(char*);
    TESCasino* GetCasino(unsigned int);
    TESCaravanDeck* GetCaravanDeck(char*);
    TESCaravanDeck* GetCaravanDeck(unsigned int);
    TESTopic* GetAudioBackendData(int, int);
    TESTopic* GetAudioBackendData(char*);
    TESTopic* GetAudioBackendData(unsigned int);
    TESChallenge* GetChallenge(char*);
    TESAmmoEffect* GetAmmoEffect(char*);
    TESQuest* GetQuest(char*);
    TESCombatStyle* GetCombatStyle(char*);
    TESEffectShader* GetEffectShader(char*);
    BGSProjectile* GetProjectileData(char*);
    BGSExplosion* GetExplosion(char*);
    BGSDebris* GetDebris(char*);
    BGSPerk* GetPerk(char*);
    BGSMessage* GetMessage(char*);
    TESLoadScreenType* GetLoadScreenType(char*);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFormList* GetObjectList();
    void* GetFileList();
    void* GetPartDataList();
    void* GetPerks();
    void* GetDebrisList();
    void* GetExplosionList();
    void* GetProjectileList();
    void* GetRadiationStageList();
    void* GetDehydrationStageList();
    void* GetHungerStageList();
    void* GetSleepDeprevationStageList();
    void* GetEffectShaderList();
    void* GetWaterList();
    void* GetLoadScreenList();
    void* GetAnimObjectList();
    TESObjectANIO* GetAnimObject(TESIdleForm*, int);
    void* GetCombatStyleList();
    void* GetPackageList();
    void* GetWorldSpaceList();
    void* GetClimateList();
    void* GetImageSpaceList();
    void* GetImageSpaceModifierList();
    void* GetWeatherList();
    void* GetEnchantmentItemList();
    void* GetSpellItemList();
    void* GetLandTextList();
    void* GetCameraShotList();
    void* GetHeadPartList();
    void* GetHairList();
    void* GetEyesList();
    void* GetRaceList();
    void* GetZoneList();
    void* GetClassList();
    void* GetFactionList();
    void* GetReputationList();
    void* GetChallengeList();
    void* GetRecipeList();
    void* GetRecipeCategoryList();
    void* GetAmmoEffectList();
    void* GetCasinoList();
    void* GetCaravanDeckList();
    void* GetSoundList();
    void* GetAcousticSpaceList();
    void* GetRagdollList();
    void* GetGlobalList();
    void* GetVoiceTypeList();
    void* GetImpactDataList();
    void* GetImpactDataSetList();
    void* GetBadFormList();
    TESRegionList* GetRegionList();
    void* GetTopicList();
    void* GetTopicInfoList();
    void* GetNoteList();
    void* GetMenuIconList();
    void* GetListFormList();
    void* GetMessageList();
    void* GetLightingTemplateList();
    void* GetMusicTypeList();
    void* GetLoadScreenTypeList();
    void* GetMediaSetList();
    void* GetMediaLocationControllerList();
    void AddTopic(TESTopic*);
    void RemoveTopic(TESTopic*);
    void AddTopicInfo(TESTopicInfo*);
    void RemoveTopicInfo(TESTopicInfo*);
    void* GetScriptList();
    void SortScriptList();
    void* GetQuestList();
    void AddQuest(TESQuest*);
    void RemoveQuest(TESQuest*);
    void RegisterAddonNode(BGSAddonNode*);
    void RemoveAddonNode(BGSAddonNode*);
    TESObjectCELL_o2* GetCellByNameAndGrid(char*);
    TESObjectCELL_o2* GetCellByNameAndGrid(char*, int, int, TESWorldSpace*);
    unsigned int GetInteriorCellCount();
    TESObjectCELL_o2* GetCellByInteriorIndex(unsigned int);
    void RefreshCellList();
    unsigned int GetCellCount();
    TESObjectCELL_o2* GetCellByIndex(unsigned int);
    TESObjectCELL_o2* GetCellByNumericID(unsigned int);
    TESObjectCELL_o2* LookupCellByEditorID(char*);
    TESWorldSpace* GetWorldSpaceByEditorID(char*, int*, int*);
    TESObjectCELL_o2* GetCellByWorldPosition(float, float, TESWorldSpace*, bool);
    TESObjectCELL_o2* GetCellAtGridPosition(int, int, TESWorldSpace*, bool);
    TESWorldSpace* GetWorldSpaceForCell(TESObjectCELL_o2*);
    void RemoveCell(TESObjectCELL_o2*);
    void RemoveCell(int, int, TESWorldSpace*);
    void RemoveCell(char*);
    TESObjectREFR* CreateReferenceInLoadedArea(TESBoundObject*, void*, void*, bool, BGSPrimitive*, void*);
    TESObjectREFR* PlaceReferenceAtLocation(TESBoundObject*, void*, void*, TESObjectCELL_o2*, TESWorldSpace*,
                                            TESObjectREFR*, BGSPrimitive*, void*);
    TESObjectCELL_o2* SelectCell(struct blob12, bool*, TESWorldSpace*);
    bool AssignToCell(TESObjectCELL_o2*, TESObjectREFR*);
    bool PlaceInExterior(TESObjectREFR*, TESWorldSpace*);
    void RemoveDuplicateReferences();
    TESObjectREFR* CreateProjectileAtLocation(TESBoundObject*, void*, void*, TESObjectCELL_o2*, TESWorldSpace*);
    TESObjectREFR* PlaceObjectAtLocation(TESBoundObject*, void*, void*, TESObjectCELL_o2*, TESWorldSpace*);
    TESFile* LookupTESFile(unsigned int);
    TESFile* LookupTESFile(char*);
    bool RemoveListFile(TESFile*);
    static void FileCacheCompleteCallback(char*);
    char* GetActiveFileName();
    void SetActiveFile(TESFile*);
    TESFile* GetActiveFile();
    void RemoveIDFromDataHandler(unsigned int);
    unsigned int GetNextID();
    void AddCompiledFile(TESFile*);
    void ClearFileList();
    bool UpdateLoadingStatusCallback(char*);
    void BuildCompiledFileList();
    int CountCheckedFiles(int);
    unsigned int CountFiles();
    unsigned int CountCompiled();
    bool LoadPluginFiles(bool);
    bool ClearData();
    bool SaveActiveData(char*, bool);
    void CloseAllTES();
    bool LoadTESFile(TESFile*, bool);
    void ClearLoadedFormCount();
    unsigned int AddDownloadedContentToFileList();
    void RunAllPersistentRefScripts();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    bool FormGroupLoadsInGame(TESFile*, FormRecordHeader*);
    static TESForm* CreateFormForType(unsigned char);
    bool ResetOffsetData(TESFile*);
    void FixAllScriptIDs();
    void SetSaveLoadGameState(int);
    bool GetMasterSave();
    void SetMasterSave(bool);
    bool GetSaveLoadGame();
    void SetSaveLoadGame(bool);
    bool GetSaveLoad();
    void SetSaveLoad(bool);
    bool GetAutoSaving();
    void SetAutoSaving(bool);
    bool GetClearingData();
    void SetClearingData(bool);
    bool GetHasDesiredFiles();
    void SetHasDesiredFiles(bool);
    bool IsSavingLoading();
    void SetCheckingModels(bool);
    bool GetCheckingModels();
    void SetLoadingFiles(bool);
    bool GetLoadingFiles();
    bool GetGameSettingsLoaded();
    void MarkGameSettingsLoaded();
    void FlushSoundBuffers();
    void SetBarterContainer(TESObjectREFR*);
    void AddBarterItem(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearBarterContainer();
    InventoryChanges* GetBarterContainer();
    void CreateRecipeContainer(TESObjectREFR*);
    void RemoveItemRecipeContainer(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearRecipeContainer();
    InventoryChanges* GetRecipeContainer();
    TESRegionDataManager* GetRegionDataManager();
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetNextFormID();
    void SetNextFormID(unsigned int);
    AlchemyItem* DoesPotionMatch(AlchemyItem*);
    void SetDontRemoveIDs(bool);
    bool GetDontRemoveIDs();
    void* QArrayInteriorCells();
    TESEffectShader* GetSpotterShader();
    TESEffectShader* GetItemDetectedShader();
    TESEffectShader* GetCateyeShader();
    void SetSpotterShader(TESEffectShader*);
    void SetItemDetectedShader(TESEffectShader*);
    void SetCateyeShader(TESEffectShader*);
    void ClearDLCFlags();
    int GetNumDLCInstalled();
    void DataError(int);
    bool IsFormIDRemapped(unsigned int);
    void AdvanceNextID();
    char* GetDLCFlags();
    bool IsDLCFlagSet(char);
    void SetDLCFlag(char, bool);
    int GetDLCIndex(char*);
    unsigned int LoadFilesInDirectory(char*, void*);
    void* __vecDelDtor(unsigned int);
    char m_cDLCFlagCount;
    char _pad_1[3];
    TESFormList* m_pBoundObjectList;
    char m_kPackages[8];
    char m_kWorldSpaceList[8];
    char m_kClimateList[8];
    char m_kImageSpaceList[8];
    char m_kImageSpaceModifierList[8];
    char m_kWeatherList[8];
    char m_kEnchantmentItemList[8];
    char m_kSpellList[8];
    char m_kHeadPartList[8];
    char m_kHairList[8];
    char m_kEyeList[8];
    char m_kRaceList[8];
    char m_kEncounterZoneList[8];
    char m_kLandTextureList[8];
    char m_kCameraShotList[8];
    char m_kClassList[8];
    char m_pVoiceType[8];
    char m_kReputationList[8];
    char m_kChallengeList[8];
    char m_kCraftingRecipeList[8];
    char m_kRecipeCategoryList[8];
    char m_kAmmoEffectList[8];
    char m_kCasinoList[8];
    char m_kCaravanDeckList[8];
    char m_kScriptList[8];
    char m_kSoundList[8];
    char m_kAcousticSpaceList[8];
    char m_kRagdollList[8];
    char m_kGlobalList[8];
    char m_kVoiceTypeList[8];
    char m_kImpactEffectList[8];
    char m_kImpactDataSetList[8];
    char m_kTopicList[8];
    char m_kTopicInfoList[8];
    char m_kQuestList[8];
    char m_kCombatStyleList[8];
    char m_kLoadScreenList[8];
    char m_kWaterFormList[8];
    char m_kEffectShaderList[8];
    char m_kProjectileList[8];
    char m_kExplosionList[8];
    char m_kRadiationStageList[8];
    char m_kDehydrationStageList[8];
    char m_kHungerStageList[8];
    char m_kSleepDeprivationStageList[8];
    char m_kDebrisList[8];
    char m_kPerkList[8];
    char m_kBodyPartDataList[8];
    char m_kNoteList[8];
    char m_kListFormList[8];
    char m_kMenuIconList[8];
    char m_kFourthDataList[8];
    char m_kMessageList[8];
    char m_kLightingTemplateList[8];
    char m_kMusicTypeList[8];
    char m_kLoadScreenTypeList[8];
    char m_kMediaSetList[8];
    char m_kMediaLocationControllerList[8];
    TESRegionList* m_pRegions;
    char m_kFirstArrayStorage[16];
    char m_kSecondArrayStorage[16];
    char m_kThirdArrayStorage[12];
    unsigned int m_uiFormCount;
    TESFile* m_pActiveFile;
    char m_kModInfoList[8];
    unsigned int m_iLoadedModCount;
    char m_ppLoadedMods[1020];
    bool m_bLoadingFiles;
    bool m_bGameSettingsLoaded;
    bool m_bMasterSave;
    bool m_bSaveLoadGame;
    bool m_bFirstStateField;
    bool m_bSecondStateField;
    bool m_bThirdStateField;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    unsigned char m_ucInternalStateByte;
    char _pad_623[1];
    TESRegionDataManager* m_pRegionDataManager;
    InventoryChanges* m_pFirstInventoryChanges;
    InventoryChanges* m_pSecondInventoryChanges;
    TESEffectShader* m_pFirstEffectShader;
    TESEffectShader* m_pSecondEffectShader;
    TESEffectShader* m_pThirdEffectShader;
};

struct FUN_004516b0_shell_o2 : public TESDataHandler_o2
{
    bool FUN_004516b0();
};

struct TESObjectCELL_o2;

struct BGSSaveLoadGame_o2
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL_o2*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};

struct FUN_004523c0_shell_o2 : public BGSSaveLoadGame_o2
{
    bool FUN_004523c0();
};

void FUN_00454440(unsigned char value);

struct FNStub_o2
{
};

void FUN_00455680();

struct TESObjectCELL_o2;

struct ModelLoader_o2
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL_o2*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL_o2*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL_o2*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};

struct FUN_0045a5e0_shell_o2 : public ModelLoader_o2
{
    void FUN_0045a5e0(char*);
};

struct Flt
{
    operator unsigned int(void) const;
};

struct NiPoint3_o2
{
    float x;
    float y;
    float z;
};

struct NiCamera_o2
{
    float x;
    float y;
    float z;
    float w;
    int ClassifyPoint(const NiPoint3_o2* other);
};

struct TESObjectCELL_o2
{
public:
    bool IsCellInterior() const;
};

struct TESObjectCELL_AddToInteriorBuffer_o2
{
};

struct TESObjectCELL_AddToExteriorBuffer_o2
{
};

struct FUN_00454b90_shell_o2
{
    void AddCellToBuffer(TESObjectCELL_o2* cell);
};

struct FUN_0045ae20_shell_o2
{
    void* FUN_0045ae20(unsigned int flags);
};

struct ShaderBufferRecord;

struct NiTStringPointerMap_00e93060
{
};

struct ShaderBufferRecord
{
    char pad[0x30];
    NiTStringPointerMap_00e93060 map;
};

struct TallGrassShaderProperty_o2
{
};

// @fnv 0x00b617b0
bool __cdecl FUN_00b617b0(char const* a, char const* b)
{
    ShaderBufferRecord* pn = 0;
    if (!reinterpret_cast<::A54440Hash *>((((::NiTStringPointerMap_00e93060 *)(::fnv_00b61170::GetArrayHolder()))))->FUN_00a53c30((::A54440Manager *)(a), (::A54440Manager **)&(pn)))
        return false;
    return reinterpret_cast<::A54440Hash *>(&(pn->map))->FUN_00a53c30((::A54440Manager *)(b), (::A54440Manager **)&(pn));
}

// Release one update lock; when the last lock goes away, process (a budgeted part of) the pending queue
// or flush it, then run the post-update steps.

class C6B540Item;

class C6B540Manager_o2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiLockCount;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    C6B540Item** m_ppkPending;
    unsigned int m_uiPendingCount;

    void FUN_00c6b540(bool bProcess);
};

// @fnv 0x00c6b540
void C6B540Manager_o2::FUN_00c6b540(bool bProcess)
{
    if (m_uiLockCount > 0)
    {
        if (--m_uiLockCount == 0)
        {
            if (bProcess)
            {
                if (m_uiPendingCount > 0 && !(*reinterpret_cast<bool *>(&::DAT_012677a2)))
                {
                    if (m_uiPendingCount >= 3000)
                        m_uiPendingCount = 3000;
                    unsigned int ItemUpdateArray =
                        m_uiPendingCount < ::DAT_011afe80 ? m_uiPendingCount : ::DAT_011afe80;
                    unsigned int uiRemaining = m_uiPendingCount - ItemUpdateArray;
                    reinterpret_cast<::S_Owner *>(this)->FUN_00c674d0((::S_Item **)(::C6B540Item **)(&m_ppkPending[uiRemaining]), ItemUpdateArray);
                    m_uiPendingCount = uiRemaining;
                    (*reinterpret_cast<bool *>(&::DAT_012677a2)) = true;
                }
            }
            else
            {
                reinterpret_cast<::FUN_00c68a40_Class *>(this)->FUN_00c68a40();
            }
            reinterpret_cast<::This676 *>(this)->ClearIndexedValues();
            reinterpret_cast<::fnv_00c6aac0::FUN_00c6aac0_Owner *>(this)->FUN_00c6aac0();
            reinterpret_cast<::FUN_00c67850_Class *>(this)->ProcessConstraints();
        }
    }
    else if (m_uiPendingCount > 0 && !bProcess)
    {
        reinterpret_cast<::FUN_00c68a40_Class *>(this)->FUN_00c68a40();
    }
}

struct QueryStub
{
};

struct MemoryManager
{
};

struct SlotEntry
{
    void* item;
    unsigned char flag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
    int unk10;
};

struct HolderNode
{
    int unk00;
    int unk04;
    void* holder;
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* item;
};

inline void* const& NextHolder(HolderNode*& pos)
{
    void* const& element = pos->holder;
    pos = (HolderNode*)pos->unk00;
    return element;
}

struct FUN_00b631d0_cls_o2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned char m_flag40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    SlotEntry m_entries[3];
    int unk84;
    unsigned short m_88;
    unsigned short m_uiItemCount;
    void** m_ppData;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    void* m_kNode;
    int unk144;
    int m_listCount;
    void FUN_00b631d0();
};

// @fnv 0x00b631d0
void FUN_00b631d0_cls_o2::FUN_00b631d0()
{
    unsigned int state;
    int i = 0;
    while (i < m_uiItemCount)
    {
        if (m_ppData[i] != 0)
        {
            reinterpret_cast<::S_00c4edf0_cls *>((((QueryStub*)m_ppData[i])))->FUN_00c4edf0((std::intptr_t)(&state), 1);

            void* item = m_ppData[i];
            if (item != 0)
            {
                reinterpret_cast<::FUN_00c4ed40_cls *>((item))->FUN_00c4ed40();
                reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(item);
            }

            m_ppData[i] = 0;
        }
        ++i;
    }

    SlotEntry* entry = m_entries;
    int remaining = 3;
    do
    {
        if (entry->item != 0)
        {
            reinterpret_cast<::S_00c4edf0_cls *>((((QueryStub*)entry->item)))->FUN_00c4edf0((std::intptr_t)(&state), 1);
            void* item = entry->item;
            if (item != 0)
            {
                reinterpret_cast<::FUN_00c4ed40_cls *>((item))->FUN_00c4ed40();
                reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(item);
            }
            entry->item = 0;
            entry->flag = 0;
        }
        ++entry;
        --remaining;
    } while (remaining != 0);

    m_flag40 = 0;
    HolderNode* node = (HolderNode*)m_kNode;
    while (m_listCount != 0)
    {
        Holder* holder = (Holder*)NextHolder(node);
        if (holder != 0 && holder->item != 0)
        {
            reinterpret_cast<::S_00c4edf0_cls *>((((QueryStub*)holder->item)))->FUN_00c4edf0((std::intptr_t)(&state), 1);
            void* item = holder->item;
            if (item != 0)
            {
                reinterpret_cast<::FUN_00c4ed40_cls *>((item))->FUN_00c4ed40();
                reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(item);
            }
            holder->item = 0;
        }
    }

    void** array = m_ppData;
    m_88 = 0;
    m_uiItemCount = 0;
    reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(array);
    m_ppData = 0;
}

struct Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int type;
};

struct Ref
{
    Item* ptr;
    Ref(Item*);
    ~Ref();
};

struct List
{
    int head;
    int tail;
    int count;
    Ref FUN_00b9fcc0(const Ref&);
};

struct Node
{
    Node* next;
    Node* prev;
    Item** data;
};

struct S00b6da10_Other
{
};

struct Pending
{
    Node* head;
    Node* tail;
    int count;
    __declspec(noalias) void FUN_00e7d7f0(Node* const&);
    __forceinline void Find(Item* item, Node*& pos, Item**& found)
    {
        while (pos)
        {
            if (found)
                return;
            if (*pos->data == item)
                found = pos->data;
            else
                pos = pos->next;
        }
    }
};

struct Manager
{
    List list0;
    List list1;
    List list2;
    List list3;
    List list4;
    List dest0;
    List dest1;
    List dest2;
    List dest3;
    List dest4;
    S00b6da10_Other other;
    int o4;
    int o8;
    Pending pending;
    void FUN_00b6da10(Item* item);
    template <int N> static __forceinline void ProcT(List& l, List& d, Item* p)
    {
        {
            Ref tmp(p);
            reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(l))->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)(tmp));
        }
        {
            Ref tmp(p);
            d.FUN_00b9fcc0(tmp);
        }
    }
    __forceinline void Purge(Item* item, Node* pos, Item** found)
    {
        pending.Find(item, pos, found);
        if (found)
        {
            reinterpret_cast<::FUN_00b58570_Class *>(&(other))->FUN_00b58570((void *)&(found));
            pending.FUN_00e7d7f0(pos);
        }
    }
    static __forceinline void Proc(List& l, List& d, Item* p)
    {
        {
            Ref tmp(p);
            reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(l))->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)(tmp));
        }
        {
            Ref tmp(p);
            d.FUN_00b9fcc0(tmp);
        }
    }
};

// @fnv 0x00b6da10
void Manager::FUN_00b6da10(Item* item)
{
    if (item)
    {
        if (item->type > -1)
        {
            switch (item->type)
            {
            case 43: {
                {
                    Ref tmp(item);
                    reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(list0))->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)(tmp));
                }
                {
                    Ref tmp(item);
                    dest0.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 17: {
                {
                    Ref tmp(item);
                    reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(list1))->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)(tmp));
                }
                {
                    Ref tmp(item);
                    dest1.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 9: {
                {
                    Ref tmp(item);
                    reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(list2))->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)(tmp));
                }
                {
                    Ref tmp(item);
                    dest2.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 22: {
                {
                    Ref tmp(item);
                    reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(list3))->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)(tmp));
                }
                {
                    Ref tmp(item);
                    dest3.FUN_00b9fcc0(tmp);
                }
                break;
            }
            case 19: {
                {
                    Ref tmp(item);
                    reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(list4))->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)(tmp));
                }
                {
                    Ref tmp(item);
                    dest4.FUN_00b9fcc0(tmp);
                }
                break;
            }
            }
        }
        else
        {
            Item** found = 0;
            Node* pos = pending.head;
            pending.Find(item, pos, found);
            if (found)
            {
                reinterpret_cast<::FUN_00b58570_Class *>(&(other))->FUN_00b58570((void *)&(found));
                pending.FUN_00e7d7f0(pos);
            }
        }
    }
}

struct TESBoundObject_ob1;

struct TESObjectCELL_ob1;

struct TESDataHandler_ob1
{
    static bool LoadForm(TESForm*, TESFile*);
    bool SaveForm(TESForm*, bool);
    char* GetFormName(unsigned char);
    void OutputFormList();
    void SetModelSizeOutputEnabled(bool);
    void OutputModelSizeList();
    void CheckTexturesRecurse(NiAVObject*, char*);
    static bool CheckDismemberSkinInstanceRecurse(NiAVObject*, char*);
    void PrintTextureInfo(void*, NiTriBasedGeom*, char*, char*, bool);
    void OutputTextureInfo();
    void CheckTexturePath(char*);
    bool AddFormToDataHandler(TESForm*);
    void ReleaseForm(TESForm*);
    unsigned char NotUniqueID(char*);
    void GetObjectCounts();
    void GetReferenceCounts();
    void GetRegions();
    void InitializeMagicSystem();
    void GetReferencesInArea(TESObjectCELL_ob1*, void*, float, void*, float, int*, long);
    void GetReferencesInArea(void*, float, void*, float, int*, long);
    void EnumReferencesCloseToRef(TESObjectREFR*, float, void*, float, int*, long);
    static bool ReferenceBaseSearchEnumFunc(TESObjectREFR*, intptr_t);
    bool FindTeleportPathBetweenSmallSpaces(TESForm*, TESForm*, void*);
    bool FindTeleportPathBetweenWorlds(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindTeleportPathFromSmallSpaceToWorld(TESForm*, TESWorldSpace*, void*, bool);
    TESObjectREFR* FindFirstReference(TESObject*);
    TESObjectREFR* FindFirstReference(char*);
    bool FindConnectedWorld(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindConnectedSmallSpace(TESForm*, TESForm*, void*, void*);
    TESWorldSpace* BuildPathNodeLocation(TESForm*, NiPoint3*, void*);
    TESObjectREFR* FindClosestReference(TESBoundObject_ob1*, void*, TESObjectCELL_ob1*);
    TESObjectREFR* FindClosestReference(char*, void*, TESObjectCELL_ob1*);
    TESObjectREFR* GetReference(char*);
    TESObjectREFR* GetReference(unsigned int);
    TESLandTexture* GetLandTexture(char*);
    TESLandTexture* GetLandTexture(unsigned int);
    TESRace* GetRace(char*);
    TESRace* GetRace(unsigned int);
    TESClass* GetClass(char*);
    TESClass* GetClass(unsigned int);
    Script* GetScript(char*);
    Script* GetScript(unsigned int);
    TESSound* GetSoundByEditorID(char*);
    TESSound* GetSoundByEditorID(unsigned int);
    TESGlobal* GetGlobal(char*);
    TESGlobal* GetGlobal(unsigned int);
    BGSVoiceType* GetVoiceType(unsigned int);
    TESFaction* GetFactionByFormID(char*);
    TESFaction* GetFactionByFormID(unsigned int);
    TESReputation* GetReputation(char*);
    TESReputation* GetReputation(unsigned int);
    TESRecipe* GetRecipe(char*);
    TESRecipe* GetRecipe(unsigned int);
    TESRecipeCategory* GetRecipeCategory(char*);
    TESRecipeCategory* GetRecipeCategory(unsigned int);
    TESCasino* GetCasino(char*);
    TESCasino* GetCasino(unsigned int);
    TESCaravanDeck* GetCaravanDeck(char*);
    TESCaravanDeck* GetCaravanDeck(unsigned int);
    TESTopic* GetAudioBackendData(int, int);
    TESTopic* GetAudioBackendData(char*);
    TESTopic* GetAudioBackendData(unsigned int);
    TESChallenge* GetChallenge(char*);
    TESAmmoEffect* GetAmmoEffect(char*);
    TESQuest* GetQuest(char*);
    TESCombatStyle* GetCombatStyle(char*);
    TESEffectShader* GetEffectShader(char*);
    BGSProjectile* GetProjectileData(char*);
    BGSExplosion* GetExplosion(char*);
    BGSDebris* GetDebris(char*);
    BGSPerk* GetPerk(char*);
    BGSMessage* GetMessage(char*);
    TESLoadScreenType* GetLoadScreenType(char*);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFormList* GetObjectList();
    void* GetFileList();
    void* GetPartDataList();
    void* GetPerks();
    void* GetDebrisList();
    void* GetExplosionList();
    void* GetProjectileList();
    void* GetRadiationStageList();
    void* GetDehydrationStageList();
    void* GetHungerStageList();
    void* GetSleepDeprevationStageList();
    void* GetEffectShaderList();
    void* GetWaterList();
    void* GetLoadScreenList();
    void* GetAnimObjectList();
    TESObjectANIO* GetAnimObject(TESIdleForm*, int);
    void* GetCombatStyleList();
    void* GetPackageList();
    void* GetWorldSpaceList();
    void* GetClimateList();
    void* GetImageSpaceList();
    void* GetImageSpaceModifierList();
    void* GetWeatherList();
    void* GetEnchantmentItemList();
    void* GetSpellItemList();
    void* GetLandTextList();
    void* GetCameraShotList();
    void* GetHeadPartList();
    void* GetHairList();
    void* GetEyesList();
    void* GetRaceList();
    void* GetZoneList();
    void* GetClassList();
    void* GetFactionList();
    void* GetReputationList();
    void* GetChallengeList();
    void* GetRecipeList();
    void* GetRecipeCategoryList();
    void* GetAmmoEffectList();
    void* GetCasinoList();
    void* GetCaravanDeckList();
    void* GetSoundList();
    void* GetAcousticSpaceList();
    void* GetRagdollList();
    void* GetGlobalList();
    void* GetVoiceTypeList();
    void* GetImpactDataList();
    void* GetImpactDataSetList();
    void* GetBadFormList();
    TESRegionList* GetRegionList();
    void* GetTopicList();
    void* GetTopicInfoList();
    void* GetNoteList();
    void* GetMenuIconList();
    void* GetListFormList();
    void* GetMessageList();
    void* GetLightingTemplateList();
    void* GetMusicTypeList();
    void* GetLoadScreenTypeList();
    void* GetMediaSetList();
    void* GetMediaLocationControllerList();
    void AddTopic(TESTopic*);
    void RemoveTopic(TESTopic*);
    void AddTopicInfo(TESTopicInfo*);
    void RemoveTopicInfo(TESTopicInfo*);
    void* GetScriptList();
    void SortScriptList();
    void* GetQuestList();
    void AddQuest(TESQuest*);
    void RemoveQuest(TESQuest*);
    void RegisterAddonNode(BGSAddonNode*);
    void RemoveAddonNode(BGSAddonNode*);
    TESObjectCELL_ob1* GetCellByNameAndGrid(char*);
    TESObjectCELL_ob1* GetCellByNameAndGrid(char*, int, int, TESWorldSpace*);
    unsigned int GetInteriorCellCount();
    TESObjectCELL_ob1* GetCellByInteriorIndex(unsigned int);
    void RefreshCellList();
    unsigned int GetCellCount();
    TESObjectCELL_ob1* GetCellByIndex(unsigned int);
    TESObjectCELL_ob1* GetCellByNumericID(unsigned int);
    TESObjectCELL_ob1* LookupCellByEditorID(char*);
    TESWorldSpace* GetWorldSpaceByEditorID(char*, int*, int*);
    TESObjectCELL_ob1* GetCellByWorldPosition(float, float, TESWorldSpace*, bool);
    TESObjectCELL_ob1* GetCellAtGridPosition(int, int, TESWorldSpace*, bool);
    TESWorldSpace* GetWorldSpaceForCell(TESObjectCELL_ob1*);
    void RemoveCell(TESObjectCELL_ob1*);
    void RemoveCell(int, int, TESWorldSpace*);
    void RemoveCell(char*);
    TESObjectREFR* CreateReferenceInLoadedArea(TESBoundObject_ob1*, void*, void*, bool, BGSPrimitive*, void*);
    TESObjectREFR* PlaceReferenceAtLocation(TESBoundObject_ob1*, void*, void*, TESObjectCELL_ob1*, TESWorldSpace*,
                                            TESObjectREFR*, BGSPrimitive*, void*);
    TESObjectCELL_ob1* SelectCell(struct blob12, bool*, TESWorldSpace*);
    bool AssignToCell(TESObjectCELL_ob1*, TESObjectREFR*);
    bool PlaceInExterior(TESObjectREFR*, TESWorldSpace*);
    void RemoveDuplicateReferences();
    TESObjectREFR* CreateProjectileAtLocation(TESBoundObject_ob1*, void*, void*, TESObjectCELL_ob1*, TESWorldSpace*);
    TESObjectREFR* PlaceObjectAtLocation(TESBoundObject_ob1*, void*, void*, TESObjectCELL_ob1*, TESWorldSpace*);
    TESFile* LookupTESFile(unsigned int);
    TESFile* LookupTESFile(char*);
    bool RemoveListFile(TESFile*);
    static void FileCacheCompleteCallback(char*);
    char* GetActiveFileName();
    void SetActiveFile(TESFile*);
    TESFile* GetActiveFile();
    void RemoveIDFromDataHandler(unsigned int);
    unsigned int GetNextID();
    void AddCompiledFile(TESFile*);
    void ClearFileList();
    bool UpdateLoadingStatusCallback(char*);
    void BuildCompiledFileList();
    int CountCheckedFiles(int);
    unsigned int CountFiles();
    unsigned int CountCompiled();
    bool LoadPluginFiles(bool);
    bool ClearData();
    bool SaveActiveData(char*, bool);
    void CloseAllTES();
    bool LoadTESFile(TESFile*, bool);
    void ClearLoadedFormCount();
    unsigned int AddDownloadedContentToFileList();
    void RunAllPersistentRefScripts();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    bool FormGroupLoadsInGame(TESFile*, FormRecordHeader*);
    static TESForm* CreateFormForType(unsigned char);
    bool ResetOffsetData(TESFile*);
    void FixAllScriptIDs();
    void SetSaveLoadGameState(int);
    bool GetMasterSave();
    void SetMasterSave(bool);
    bool GetSaveLoadGame();
    void SetSaveLoadGame(bool);
    bool GetSaveLoad();
    void SetSaveLoad(bool);
    bool GetAutoSaving();
    void SetAutoSaving(bool);
    bool GetClearingData();
    void SetClearingData(bool);
    bool GetHasDesiredFiles();
    void SetHasDesiredFiles(bool);
    bool IsSavingLoading();
    void SetCheckingModels(bool);
    bool GetCheckingModels();
    void SetLoadingFiles(bool);
    bool GetLoadingFiles();
    bool GetGameSettingsLoaded();
    void MarkGameSettingsLoaded();
    void FlushSoundBuffers();
    void SetBarterContainer(TESObjectREFR*);
    void AddBarterItem(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearBarterContainer();
    InventoryChanges* GetBarterContainer();
    void CreateRecipeContainer(TESObjectREFR*);
    void RemoveItemRecipeContainer(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearRecipeContainer();
    InventoryChanges* GetRecipeContainer();
    TESRegionDataManager* GetRegionDataManager();
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetNextFormID();
    void SetNextFormID(unsigned int);
    AlchemyItem* DoesPotionMatch(AlchemyItem*);
    void SetDontRemoveIDs(bool);
    bool GetDontRemoveIDs();
    void* QArrayInteriorCells();
    TESEffectShader* GetSpotterShader();
    TESEffectShader* GetItemDetectedShader();
    TESEffectShader* GetCateyeShader();
    void SetSpotterShader(TESEffectShader*);
    void SetItemDetectedShader(TESEffectShader*);
    void SetCateyeShader(TESEffectShader*);
    void ClearDLCFlags();
    int GetNumDLCInstalled();
    void DataError(int);
    bool IsFormIDRemapped(unsigned int);
    void AdvanceNextID();
    char* GetDLCFlags();
    bool IsDLCFlagSet(char);
    void SetDLCFlag(char, bool);
    int GetDLCIndex(char*);
    unsigned int LoadFilesInDirectory(char*, void*);
    void* __vecDelDtor(unsigned int);
    char m_cDLCFlagCount;
    char _pad_1[3];
    TESFormList* m_pBoundObjectList;
    char m_kPackages[8];
    char m_kWorldSpaceList[8];
    char m_kClimateList[8];
    char m_kImageSpaceList[8];
    char m_kImageSpaceModifierList[8];
    char m_kWeatherList[8];
    char m_kEnchantmentItemList[8];
    char m_kSpellList[8];
    char m_kHeadPartList[8];
    char m_kHairList[8];
    char m_kEyeList[8];
    char m_kRaceList[8];
    char m_kEncounterZoneList[8];
    char m_kLandTextureList[8];
    char m_kCameraShotList[8];
    char m_kClassList[8];
    char m_pVoiceType[8];
    char m_kReputationList[8];
    char m_kChallengeList[8];
    char m_kCraftingRecipeList[8];
    char m_kRecipeCategoryList[8];
    char m_kAmmoEffectList[8];
    char m_kCasinoList[8];
    char m_kCaravanDeckList[8];
    char m_kScriptList[8];
    char m_kSoundList[8];
    char m_kAcousticSpaceList[8];
    char m_kRagdollList[8];
    char m_kGlobalList[8];
    char m_kVoiceTypeList[8];
    char m_kImpactEffectList[8];
    char m_kImpactDataSetList[8];
    char m_kTopicList[8];
    char m_kTopicInfoList[8];
    char m_kQuestList[8];
    char m_kCombatStyleList[8];
    char m_kLoadScreenList[8];
    char m_kWaterFormList[8];
    char m_kEffectShaderList[8];
    char m_kProjectileList[8];
    char m_kExplosionList[8];
    char m_kRadiationStageList[8];
    char m_kDehydrationStageList[8];
    char m_kHungerStageList[8];
    char m_kSleepDeprivationStageList[8];
    char m_kDebrisList[8];
    char m_kPerkList[8];
    char m_kBodyPartDataList[8];
    char m_kNoteList[8];
    char m_kListFormList[8];
    char m_kMenuIconList[8];
    char m_kFourthDataList[8];
    char m_kMessageList[8];
    char m_kLightingTemplateList[8];
    char m_kMusicTypeList[8];
    char m_kLoadScreenTypeList[8];
    char m_kMediaSetList[8];
    char m_kMediaLocationControllerList[8];
    TESRegionList* m_pRegions;
    char m_kFirstArrayStorage[16];
    char m_kSecondArrayStorage[16];
    char m_kThirdArrayStorage[12];
    unsigned int m_uiFormCount;
    TESFile* m_pActiveFile;
    char m_kModInfoList[8];
    unsigned int m_iLoadedModCount;
    char m_ppLoadedMods[1020];
    bool m_bLoadingFiles;
    bool m_bGameSettingsLoaded;
    bool m_bMasterSave;
    bool m_bSaveLoadGame;
    bool m_bFirstStateField;
    bool m_bSecondStateField;
    bool m_bThirdStateField;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    unsigned char m_ucInternalStateByte;
    char _pad_623[1];
    TESRegionDataManager* m_pRegionDataManager;
    InventoryChanges* m_pFirstInventoryChanges;
    InventoryChanges* m_pSecondInventoryChanges;
    TESEffectShader* m_pFirstEffectShader;
    TESEffectShader* m_pSecondEffectShader;
    TESEffectShader* m_pThirdEffectShader;
};

struct FUN_004516b0_shell_ob1 : public TESDataHandler_ob1
{
    bool FUN_004516b0();
};

struct TESObjectCELL_ob1;

struct BGSSaveLoadGame_ob1
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL_ob1*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};

struct FUN_004523c0_shell_ob1 : public BGSSaveLoadGame_ob1
{
    bool FUN_004523c0();
};

struct NiNode_ob1;

struct TESBoundObject_ob1;

struct TESObjectCELL_ob1;

struct TESObjectTREE_ob1;

struct ModelLoader_ob1
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE_ob1*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE_ob1*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject_ob1*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject_ob1*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL_ob1*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject_ob1*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL_ob1*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL_ob1*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode_ob1*);
    void UpdateModelNode(NiNode_ob1*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};

struct FUN_0045a5e0_shell_ob1 : public ModelLoader_ob1
{
    void FUN_0045a5e0(char*);
};

struct TESObjectCELL_ob1
{
public:
    bool IsCellInterior() const;
public:
    int GetCellStandValue();
public:
    ::NiAVObject *GetCellChildAt(int);
public:
    int GetCellGridX();
public:
    int GetCellGridY();
public:
    ::BGSEncounterZone *FindEncounterZone() const;
public:
    ::TESWorldSpace *GetParentWorldSpace();
public:
    void FUN_005571a0(bool);
};

struct TESObjectCELL_AddToInteriorBuffer_ob1
{
};

struct TESObjectCELL_AddToExteriorBuffer_ob1
{
};

struct FUN_00454b90_shell_ob1
{
    void AddCellToBuffer(TESObjectCELL_ob1* cell);
};

struct FUN_0045ae20_shell_ob1
{
    void* FUN_0045ae20(unsigned int flags);
};

struct FNVHelper_ob1
{
};

struct NiNode_ob1
{
    NiAVObject* GetAt(unsigned int);
};

struct FUN_0045c9a0_shell_ob1 : public TESObjectCELL_ob1
{
    NiAVObject* GetCellNodeAt(unsigned int index);
};

struct FUN_005570b0_shell_ob1
{
};

struct DH_ob1
{
    void DeleteObject(TESObjectCELL_ob1*);
};

struct FUN_00454e70_shell_ob1
{
    char _pad[0x3c];
    TESObjectCELL_ob1** m_ppCellBufferB;
    void MoveCellToFront(TESObjectCELL_ob1* apCell);
};

struct TESObjectLAND_ob1;

struct NiNode_ob1;

struct FUN_00461c20_Holder_ob1
{
};

struct GridCellArrayStandin_ob1
{
};

struct GridCellArray_Target_ob1
{
};

struct S451cb0_ob1
{
};

int _sprintf(char*, const char*, ...);

struct TES_00451a50_ob1
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pGridCells;
    NiNode_ob1* m_pLandRootNode;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    bool m_bHasCurrentRegion;
    void FUN_00451a50(int aiGridX, int aiGridY, int aiCellX, int aiCellY);
};

struct Sky_ob1
{
    void Update_ob1(float);
public:
    void SetMode(::Sky__SKY_MODE);
};

struct TaskQueueInterface_ob1
{
public:
    static ::TaskQueueInterface_ob1 *GetSingleton();
};

struct Zt5TES_ob1
{
    void* pVtbl;
    void* m_pGridDistantArray;
    Zt5Grid* m_pGridCells;
    void* m_pLandRootNode;
    void* m_pWaterRootNode;
    void* m_pDistantLandRootNode;
    void* m_pObjectRootNode;
    void* m_pDirectionalLight;
    void* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    void* m_pReferenceCell;
    void* m_ppCellBufferA;
    void* m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    void* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    void* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    void* m_pCurrentClimate;
    Sky_ob1* pWeatherSky;
    void FUN_004537c0();
    void FUN_00453550(float afTime);
};

struct TESForm_0045c6b0_ob1
{
};

struct FUN_00453490_shell_ob1
{
    bool FUN_00453490(TESObjectCELL_ob1* cell);
};

struct FUN_00455400_sky_ob1 : Sky_ob1
{
};

struct FUN_00455400_cell_ob1 : TESObjectCELL_ob1
{
    bool FUN_00454b10();
};

struct FUN_00455400_tes_ob1
{
    void UpdateSkyModeForCell(TESObjectCELL_ob1* apCell);
};

struct GridCellArray_ob1
{
};

struct NiAdditionalGeometryData_ob1
{
};

struct FUN_00451cf0_shell_ob1
{
    char pad[8];
    GridCellArray_ob1* cells;
    void FUN_00451cf0();
};

struct LLD_DataHandler_ob1
{
};

struct FUN_00451900_shell_ob1
{
    TESObjectCELL_ob1* FUN_00451900(int aiCellX, int aiCellY);
};

void* __cdecl _FUN_00ec7230(void*, void*, unsigned int);

struct FUN_00454fc0_shell_ob1
{
    void* vftable;
    void* m_pGridDistantArray;
    unsigned char padding[0x1c];
    int iFirstValue;
    int unknown_28;
    int m_iGridWidth;
    int m_iGridHeight;
    int unknown_34;
    int unknown_38;
    TESObjectCELL_ob1** m_ppCellBufferB;

    void CompactQueuedCells();
};

struct Calendar_ob1 : NiAVObject
{
    Calendar_ob1* GetDaysPassed();
public:
    void ResetCachedValues();
};

Calendar_ob1* Calendar_ob1::GetDaysPassed()
{
    return this;
}

struct FUN_00458e20_shell_ob1 : Calendar_ob1
{
    void FUN_00458e20(NiAVObject*, float);
};

struct FUN_0045c840_shell_ob1
{
    void* field_00;
    void* field_04;
    void* field_08;

    void InitFromMatrix();
};

struct TESObjectLAND_ob1
{
public:
    bool FUN_0053f180(const ::LandscapeColorData &, float &);
};

struct FUN_004572e0_shell_ob1 : public TES
{
    TESObjectCELL_ob1* FUN_00451900(int cellX, int cellY);
    bool GetLandHeightAt(const NiPoint3& coord, float& height);
};

struct TESCallHelper_ob1
{
    bool IsCellBuffered(TESObjectCELL_ob1* cell, bool force);
};

bool TESCallHelper_ob1::IsCellBuffered(TESObjectCELL_ob1* cell, bool force)
{
    return false;
}

struct FUN_004511e0_cls_ob1
{
};

struct TESBuffer45130_ob1 : Zt5TES_ob1
{
    void FUN_00455130(TESObjectCELL_ob1* apCell);
};

struct ExtCell_ob1 : TESObjectCELL_ob1
{
};

struct TES_ExteriorBuffer_ob1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    ExtCell_ob1** m_ppCellBufferB;

    unsigned int FUN_00455200(bool abSkipLoaded, TESWorldSpace* apWorld);
};

struct FUN_00459920_grid_ob1
{
};

struct FUN_00459920_shell_ob1
{
    void* unk00;
    void* unk04;
    FUN_00459920_grid_ob1* referenceGrid;
    void FUN_00459920();
};

struct WaterTES_ob1
{
};

struct S_0045c8d0_Tgt_ob1
{
};

struct S_0045c8d0_Child_ob1
{
};

struct S_0045c8d0_A_ob1
{
};

struct S_0045c8d0_ob1
{
    int unk0;
    int unk4;
    S_0045c8d0_A_ob1* unk8;
    void FUN_0045c8d0(unsigned int a, unsigned int b, unsigned char c);
};

class B45CDA0GridCellArray_ob1
{
  public:
};

class B45CDA0TES_ob1
{
  public:
    int unk00;
    int unk04;
    B45CDA0GridCellArray_ob1* m_pkGridCells;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    B45CDA0Cell* m_pkInteriorCell;

    void FUN_0045cda0();
};

struct Interface_ob1
{
public:
    static bool IsWorldSpaceEnabled(::TESWorldSpace *);
public:
    static bool IsGamePaused();
};

struct TES4512_ob1
{
    int unk00;
    int unk04;
    Grid4512* grid;
    int unk0c;
    Node4512* root;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int gridX;
    int gridY;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    World4512* world;
    bool GetLandHeightAt(const NiPoint3&, float&);
    void FUN_004512c0(const NiPoint3* position, bool reload);
};

struct FUN_004516d0_shell_ob1
{
    unsigned int unk00;
    unsigned int unk04;
    GridCellArray_ob1* cells;
    MobileObjectCellAccess** FUN_004516d0();
};

class TESBoundObject_ob1
{
  public:
    virtual void Reserved();
};

class TESObjectTREE_ob1 : public TESBoundObject_ob1
{
  public:
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual double GetTreeScale(float);
};

struct AttachCell_ob1
{
};

struct AttachmentHandler_ob1
{
    void FUN_00451ef0(AttachRef*, AttachCell_ob1*, AttachRef*, bool);
};

namespace GridRefresh {
struct Profile_ob1
{
    int unk00;
    Profile_ob1(int, int, const char*, int);
    ~Profile_ob1();
};
struct Setting_ob1
{
};
struct Update_ob1
{
    float time;
    int flags, unk08;
    Update_ob1(float, int, int);
};
struct Node_ob1
{
};
struct Cell_ob1
{
};
struct Game_ob1
{
};
struct Loader_ob1
{
};
struct Main_ob1
{
};
struct World_ob1
{
};
struct Cells_ob1
{
    Cell_ob1* GetOrCreateCell(int, int, World_ob1*, int);
};
struct Queue_ob1
{
};
struct CellHandle_ob1
{
    void FUN_005ae3d0();
};
struct Grid_ob1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int centerX, centerY;
    World_ob1* FUN_004fd3e0();
    void RefreshGrid();
};
// @fnv 0x00452ff0
void Grid_ob1::RefreshGrid()
{
    Profile_ob1 profile3(26, 1, ::DAT_01017874, 2262);
    int originX = centerX - (*((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc)))))) >> 1);
    int originY = centerY - (*((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc)))))) >> 1);
    int count = 0;
    bool defer = false;
    if (::Interface_ob1::IsGamePaused())
        defer = true;
    bool loading4 = ::Interface_ob1::IsGamePaused();
    reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
    reinterpret_cast<::FUN_00453500_shell *>(((*reinterpret_cast<::GridRefresh::Loader_ob1 * *>(&::g_BGSSaveLoadGame))))->FUN_00453500(true);
    if (((::GridRefresh::Queue_ob1 *)(::FUN_00451010())))
        reinterpret_cast<::C00c66300 *>((((::GridRefresh::Queue_ob1 *)(::FUN_00451010()))))->FUN_00c66300();
    for (unsigned int x = 0; x < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc)))))); ++x)
    {
        for (unsigned int y = 0; y < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc)))))); ++y)
        {
            reinterpret_cast<::TES_00451a50_ob1 *>(this)->FUN_00451a50(x, y, originX + x, originY + y);
            Cell_ob1* cell = (*reinterpret_cast<::GridRefresh::Cells_ob1 * *>(&::g_dataHandler))->GetOrCreateCell(originX + x, originY + y, ((::GridRefresh::World_ob1 *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())), 0);
            if (reinterpret_cast<::FUN_00453490_shell_ob1 *>(((*reinterpret_cast<::GridRefresh::Main_ob1 * *>(&::g_TES))))->FUN_00453490((::TESObjectCELL_ob1 *)(cell)))
                reinterpret_cast<::FUN_00454b90_shell_ob1 *>(this)->AddCellToBuffer((::TESObjectCELL_ob1 *)(cell));
            if (loading4 || (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition()))
            {
                ++count;
                float percent =
                    (double)count / (*((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc)))))) * *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc))))))) * ::g_d100;
                if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
                    reinterpret_cast<::LLD_TESHelper *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_00861ea0();
            }
        }
    }
    if (((::GridRefresh::Queue_ob1 *)(::FUN_00451010())))
        reinterpret_cast<::C6B540Manager *>((((::GridRefresh::Queue_ob1 *)(::FUN_00451010()))))->FUN_00c6b540(0);
    reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(false);
    if (((bool)(reinterpret_cast<::FUN_008727b0_Class *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_008727b0())))
    {
        bool first = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
        bool second6 = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
        reinterpret_cast<::Cls *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_00858af0((::EntryListNode *)(0), (::Entry *)(0), 0);
        reinterpret_cast<::FUN_0085f850_class *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_0085f850(0);
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(second6);
        reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::GridRefresh::Game_ob1 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(first);
    }
    reinterpret_cast<::FUN_00453500_shell *>(((*reinterpret_cast<::GridRefresh::Loader_ob1 * *>(&::g_BGSSaveLoadGame))))->FUN_00453500(false);
    if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::GridRefresh::Loader_ob1 * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
        reinterpret_cast<::fnv_008492b0::FUN_008492b0_shell *>(((*reinterpret_cast<::GridRefresh::Loader_ob1 * *>(&::g_BGSSaveLoadGame))))->ResetLoadBuffers(0);
    if (((::GridRefresh::Queue_ob1 *)(::FUN_00451010())))
        reinterpret_cast<::C00c66300 *>((((::GridRefresh::Queue_ob1 *)(::FUN_00451010()))))->FUN_00c66300();
    for (unsigned int x2 = 0; x2 < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc)))))); ++x2)
    {
        for (unsigned int y2 = 0; y2 < *((const unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GridRefresh::Setting_ob1 *>(&::g_011c63cc)))))); ++y2)
        {
            if (((::GridRefresh::World_ob1 *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())))
            {
                Cell_ob1* cell2 = (*reinterpret_cast<::GridRefresh::Cells_ob1 * *>(&::g_dataHandler))->GetOrCreateCell(originX + x2, originY + y2, ((::GridRefresh::World_ob1 *)(reinterpret_cast<::EffectSetting *>(this)->GetHitSound())), 0);
                if (cell2)
                {
                    if (((int)(reinterpret_cast<::FUN_00450fd0_class *>((cell2))->GetByteAtOffset38())) == 5)
                    {
                        reinterpret_cast<::SceneB54 *>((cell2))->FUN_0054bcf0(!defer);
                        reinterpret_cast<::FUN_00454b90_shell_ob1 *>(this)->AddCellToBuffer((::TESObjectCELL_ob1 *)(cell2));
                        Node_ob1* node = ((::GridRefresh::Node_ob1 *)(reinterpret_cast<::FUN_00545cf0_Cls *>((cell2))->GetOrCreateWidget()));
                        reinterpret_cast<::FUN_00a5a040_Class *>((node))->FUN_00a5a040();
                        if (!reinterpret_cast<::FUN_00453470_shell *>((node))->FUN_00453470())
                        {
                            Update_ob1 update(0.0f, 0, 0);
                            reinterpret_cast<::FUN_00a59c60_cls *>((node))->FUN_00a59c60((std::intptr_t)&(update));
                        }
                    }
                    ((::GridRefresh::CellHandle_ob1 *)(::FUN_0045bb80((std::intptr_t)this)))->FUN_005ae3d0();
                }
            }
        }
    }
    if (((::GridRefresh::Queue_ob1 *)(::FUN_00451010())))
        reinterpret_cast<::C6B540Manager *>((((::GridRefresh::Queue_ob1 *)(::FUN_00451010()))))->FUN_00c6b540(0);
    ::FUN_00451570(0);
    ::FUN_00451520(1);
}
}

struct S_004537c0_Sky_ob1 : Sky_ob1
{
};

struct S_004537c0_Tes_ob1 : Zt5TES_ob1
{
    S_004537c0_Mgr* FUN_009611e0();
};

struct FUN_004539a0_cls_ob1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    unsigned char unkB4;
    void FUN_008d7dc0(int b);
    void FUN_004539a0(unsigned char a1, unsigned char a2);
};

struct BufferedCell_ob1 : TESObjectCELL_ob1
{
};

struct CellBufferManager_ob1
{
    void* vtable;
    void* distantGrid;
    C_0084e3a0* grid;
    void* objectRoot;
    void* landRoot;
    void* waterRoot;
    void* tempNodeManager;
    void* light;
    void* fog;
    int currentGridX;
    int currentGridY;
    int queuedGridX;
    int queuedGridY;
    BufferedCell_ob1* interiorCell;
    BufferedCell_ob1** interiorBuffer;
    BufferedCell_ob1** exteriorBuffer;

    BufferWorld* FUN_004fd3e0();
    bool FUN_00453a80();
};

struct ReloadManager_ob1
{
    unsigned unk00;
    unsigned unk04;
    ReloadCamera* camera;
    ReloadObject* object;
    ReloadInterior* interior;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    int gridX;
    int gridY;
    int oldX;
    int oldY;
    unsigned unk34;
    unsigned unk38;
    int* loaded;
    unsigned unk40;
    unsigned unk44;
    int savedX;
    int savedY;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    ReloadTexture* texture;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    ReloadName* name;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    ReloadNode loadedNode;
    void FUN_008d7dc0(ReloadScene*);
    void Pause(int, int);
    void UpdateSkyModeForCell(ReloadScene*);
    void AttachScene(ReloadScene*, ReloadPoint*);
    ReloadWorld* FUN_004fd3e0();
    void FUN_008d7dc0(int);
    void Pause(int, ReloadPoint*);
    int FUN_00457620(ReloadPoint*);
    ReloadCell* FUN_00451900(int, int);
    ReloadShader* FUN_0044ddc0();
    void InitFromMatrix();
    void InitSoundGrid();
    void FUN_0045cda0();
    void GetLandHeightAt(ReloadPoint*, float&);
    void FUN_00451cf0();
    void UpdateSkyModeForCell(int);
    void FUN_00454450(ReloadPoint*);
};

struct FUN_004571c0_cell_ob1 : FUN_004570d0_node
{
};

struct WS458200_TES_ob1
{
};

struct AddonParticleNode_ob1 : NiNode_ob1
{
};

struct Target_ob1
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    FUN_0045ae20* head;
    void FUN_0045ac80();
};

struct CellView_ob1 : public TESObjectCELL_ob1
{
};

struct FUN_0045cbc0_shell_ob1
{
    float GetCellHeightAtPosition(const NiPoint3* apPos, CellView_ob1* apCell);
};

namespace n451 {
struct Pt_ob1
{
    float iMinY, nX, z;
};
struct Grid_ob1
{
    char pad[0x24];
    int m_24;
    int m_28;
    bool ContainsPoint(const Pt_ob1& pt);
};
}

// @fnv 0x00451110
bool n451::Grid_ob1::ContainsPoint(const Pt_ob1& pt)
{
    if (((void *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        return true;
    int iMinY = FUN_00406d90(pt.iMinY) >> 12;
    int nX = FUN_00406d90(pt.nX) >> 12;
    int ix = m_24 - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))) >> 1);
    int px = m_28 - (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))) >> 1);
    if (iMinY < ix || iMinY >= ix + (int)*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))) || nX < px ||
        nX >= px + (int)*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_004570d0_lst *>(&::g_011c63cc)))))))
        return false;
    return true;
}

struct FUN_0045cac0_tes_ob1 : B45CDA0TES_ob1
{
    void FUN_0045cac0();
};

struct FUN_004573f0_shell_ob1 : public TES
{
    TESObjectCELL_ob1* FUN_00451900(int cellX, int cellY);
    bool FUN_004573f0(const NiPoint3* pos, NiPoint3* normal, int flags);
};

struct StandRTTI
{
    const char* m_pcName;
    const StandRTTI* m_pBaseRTTI;
};

struct StandRef
{
    virtual ~StandRef();
    virtual void DeleteThis();
    virtual const StandRTTI* GetRTTI() const;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct StandPtr
{
    T* m_pObject;
    StandPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~StandPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct StandNode_ob1;

struct StandChildren
{
    virtual ~StandChildren();
    StandRef** data;
    unsigned short capacity;
    unsigned short firstFree;
    unsigned short size;
    unsigned short grow;
    StandRef* const& GetAt(unsigned int i) const
    {
        StandRef* const& item = data[i];
        return item;
    }
};

struct StandNode_ob1 : StandRef
{
    virtual void Unk0c();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1c();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2c();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3c();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4c();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5c();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6c();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7c();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8c();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9c();
    virtual void Unka0();
    virtual void Unka4();
    virtual void Unka8();
    virtual void Unkac();
    virtual void Unkb0();
    virtual void Unkb4();
    virtual void Unkb8();
    virtual void Unkbc();
    virtual void Unkc0();
    virtual void Unkc4();
    virtual void Unkc8();
    virtual void Unkcc();
    virtual void Unkd0();
    virtual void Unkd4();
    virtual void Unkd8();
    virtual void Unkdc();
    virtual void Unke0();
    virtual void Unke4();
    virtual void Unke8();
    virtual void RemoveAt(unsigned int i, StandPtr<StandRef>& removed);
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    StandChildren children;
    float time;
    float UpdateTime(float f)
    {
        float delta = time != ::_DAT_01012060 ? f - time : time;
        time = f;
        return delta;
    }
    StandRef* GetChild(unsigned int i)
    {
        StandRef* const& entry = children.data[i];
        {
            StandRef* item = entry;
            return item;
        }
    }
    void SetTime(float f)
    {
        time = f;
        if (time < ::_DAT_01012060)
            time = 0.0f;
    }
    bool Expired() const
    {
        return time == ::_DAT_01012060;
    }
    void FUN_00c44ed0(float);
};

__forceinline bool IsKindOfType(const StandRTTI* target, const StandRef* object)
{
    const StandRTTI* rtti = object->GetRTTI();
    while (rtti)
    {
        if (rtti == target)
            return true;
        rtti = rtti->m_pBaseRTTI;
    }
    return false;
}
__forceinline StandNode_ob1* CastNode(StandRef* object)
{
    if (!object)
        return 0;
    return IsKindOfType(reinterpret_cast<const StandRTTI*>(&(*reinterpret_cast<const void *const *>(&::g_01202e00))), object) ? static_cast<StandNode_ob1*>(object) : 0;
}

// @fnv 0x00c44ed0
void StandNode_ob1::FUN_00c44ed0(float f)
{
    StandPtr<StandRef> spRemoved;
    float delta = UpdateTime(f);
    {
        unsigned int i = children.firstFree;
        while (i--)
        {
            StandRef* object = GetChild(i);
            StandNode_ob1* child = CastNode(object);
            if (child)
            {
                child->SetTime(child->time - delta);
                if (child->Expired())
                    RemoveAt(i, spRemoved);
            }
        }
    }
}

#include "generated/data/fallout_shared/tes.inc"
