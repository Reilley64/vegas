#pragma once

class FOPipboyManager;
class NiNode;
class TESForm;
class TESObjectREFR;
class TESWorldSpace;
class Tile;

class Interface {
public:
    // 0x00702250
    static void Init(bool);
    // 0x007022c0
    static void RefreshInterfaceState();
    // 0x00703860
    static void SetLookAtReference(::TESObjectREFR *);
    // 0x00704370
    ::FOPipboyManager *GetPipboyManager();
    // 0x007043c0
    static bool IsWorldSpaceEnabled(::TESWorldSpace *);
    // 0x00704ad0
    static bool IsPipBoyOpen();
    // 0x00705000
    static bool ContainerIsRecipe();
    // 0x00705020
    static bool ContainerIsBarter();
    // 0x00705e00
    static void SetQuestTarget(::TESForm *, bool);
    // 0x00705e80
    static bool IsGamePaused();
    // 0x00705ea0
    static bool IsInterfaceActive();
    // 0x00706cd0
    static ::Tile *GetPrimaryInterfaceTile();
    // 0x00706cf0
    static ::Tile *GetSecondaryInterfaceTile();
    // 0x00706d30
    static ::NiNode *GetInterfaceNode();
    // 0x00706d70
    static bool IsAnyMenuOpen();
    // 0x00706df0
    static float GetFirstInterfaceFloat();
    // 0x00706e00
    static float UpdateInterfaceState();
    // 0x00706e10
    static float GetThirdInterfaceFloat();
    // 0x00706e40
    static float GetFourthInterfaceFloat();
    // 0x00706e70
    static float GetInterfaceFloat();
    // 0x00707860
    static const char *GetInterfaceName();
    // 0x00707b40
    static bool IsInterfaceOpen();
    // 0x00709c40
    static void SetHUDVisible(bool);
    // 0x007fa8d0
    void FUN_007fa8d0(bool);
};
