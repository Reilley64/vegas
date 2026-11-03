
// extradatalist_ctx_variant.cpp: context variant of src/fallout_shared/extradatalist.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <new>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ExtraList_419050.h"
#include "fnv/decl/FNVLoadHost.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0040fe80_shell.h"
#include "fnv/decl/FUN_00411e20Class.h"
#include "fnv/decl/FUN_004197d0_shell.h"
#include "fnv/decl/FUN_00419a20.h"
#include "fnv/decl/FUN_00419ad0_shell.h"
#include "fnv/decl/FUN_00419bb0_cls.h"
#include "fnv/decl/FUN_00419c60_cls.h"
#include "fnv/decl/FUN_00419d10.h"
#include "fnv/decl/FUN_00419ed0_shell.h"
#include "fnv/decl/FUN_00419f80_shell.h"
#include "fnv/decl/FUN_00419fb0_StandIn.h"
#include "fnv/decl/FUN_0041aa20_shell.h"
#include "fnv/decl/FUN_0041ab70_shell.h"
#include "fnv/decl/FUN_0041b3d0_shell.h"
#include "fnv/decl/FUN_0041b580_shell.h"
#include "fnv/decl/FUN_0041c930_shell.h"
#include "fnv/decl/FUN_0041d330_Class.h"
#include "fnv/decl/FUN_0041d5b0_class.h"
#include "fnv/decl/FUN_0041d700.h"
#include "fnv/decl/FUN_0041da40_shell.h"
#include "fnv/decl/FUN_0041dc70_shell.h"
#include "fnv/decl/FUN_0041e250_cls.h"
#include "fnv/decl/FUN_0041e440_shell.h"
#include "fnv/decl/FUN_00420870_cls.h"
#include "fnv/decl/FUN_00420c10_Class.h"
#include "fnv/decl/FUN_00420e00_cls.h"
#include "fnv/decl/FUN_00421430_shell.h"
#include "fnv/decl/FUN_00421540_shell.h"
#include "fnv/decl/FUN_00421910_shell.h"
#include "fnv/decl/FUN_00421b70_shell.h"
#include "fnv/decl/FUN_00421d20_shell.h"
#include "fnv/decl/FUN_00421e40_shell.h"
#include "fnv/decl/FUN_00421f30_shell.h"
#include "fnv/decl/FUN_00422150_shell.h"
#include "fnv/decl/FUN_00422220_shell.h"
#include "fnv/decl/FUN_00422350_shell.h"
#include "fnv/decl/FUN_0042dde0_cls.h"
#include "fnv/decl/FUN_0042e2c0_shell.h"
#include "fnv/decl/FUN_0042e760_shell.h"
#include "fnv/decl/FUN_0042e800_shell.h"
#include "fnv/decl/FUN_0042eb60_shell.h"
#include "fnv/decl/FUN_0042f420_helper.h"
#include "fnv/decl/FUN_00433b70_shell.h"
#include "fnv/decl/FUN_00434a70_cls.h"
#include "fnv/decl/FUN_00434ee0_Class.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438df0.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ImpactSwapMaps.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/QuantityData.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00589770_Class.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Target0067c6f0.h"
#include "fnv/decl/Unk_00439120.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00411f20__FUN_00411f20_shell.h"
#include "fnv/decl/fnv_00418310__FUN_00418310_shell.h"
#include "fnv/decl/fnv_00418550__FUN_00418550_cls.h"
#include "fnv/decl/fnv_00419120__FUN_00419120_shell.h"
#include "fnv/decl/fnv_00419250__FUN_00419250_shell.h"
#include "fnv/decl/fnv_00419380__FUN_00419380_shell.h"
#include "fnv/decl/fnv_004194b0__ExtraDataListRemoveTrespassPackage.h"
#include "fnv/decl/fnv_00419700__FUN_00419700_shell.h"
#include "fnv/decl/fnv_004198a0__FUN_004198a0.h"
#include "fnv/decl/fnv_00419dc0__FUN_00419dc0_shell2.h"
#include "fnv/decl/fnv_0041ac30__FUN_0041ac30List.h"
#include "fnv/decl/fnv_0041ad00__FUN_0041ad00_shell.h"
#include "fnv/decl/fnv_0041b7e0__FUN_0041b7e0_cls.h"
#include "fnv/decl/fnv_0041bd10__FUN_0041bd10_shell.h"
#include "fnv/decl/fnv_0041c090__FUN_0041c090_shell.h"
#include "fnv/decl/fnv_0041c190__FUN_0041c190_shell.h"
#include "fnv/decl/fnv_0041c290__FUN_0041c290_shell.h"
#include "fnv/decl/fnv_0041c390__ExtraDataList2.h"
#include "fnv/decl/fnv_0041c490__FUN_0041c490_cls.h"
#include "fnv/decl/fnv_0041c7f0__FUN_0041c7f0_cls.h"
#include "fnv/decl/fnv_0041cc90__ExtraDataListStandIn.h"
#include "fnv/decl/fnv_0041d280__FUN_0041d280_shell.h"
#include "fnv/decl/fnv_0041d950__S0041d950.h"
#include "fnv/decl/fnv_0041e160__FUN_0041e160_shell.h"
#include "fnv/decl/fnv_0041fa60__FUN_0041fa60_shell.h"
#include "fnv/decl/fnv_0041fc10__FUN_0041fc10_shell.h"
#include "fnv/decl/fnv_0041fec0__FUN_0041fec0_shell.h"
#include "fnv/decl/fnv_00420a60__FUN_00420a60_Class.h"
#include "fnv/decl/fnv_00420f00__FUN_00420f00_shell.h"
#include "fnv/decl/fnv_00420fd0__FUN_00420fd0_cls.h"
#include "fnv/decl/fnv_00421c60__FUN_00421c60_shell.h"
#include "fnv/decl/fnv_00421d50__FUN_00421d50_shell.h"
#include "fnv/decl/fnv_00422050__FUN_00422050_shell.h"
#include "fnv/decl/fnv_00422480__FUN_00422480_shell.h"
#include "fnv/decl/fnv_00422750__FUN_00422750_class.h"
#include "fnv/decl/fnv_00422c20__FUN_0042dec0_shell.h"
#include "fnv/decl/fnv_0042e380__FUN_0042e380_Class.h"
#include "fnv/decl/fnv_0042ef20__FUN_0042ef20_StandIn.h"
#include "fnv/decl/fnv_0042f200__FUN_0042f200_shell.h"
#include "fnv/decl/fnv_004342b0__FUN_004342b0_shell.h"
#include "fnv/decl/fnv_004346f0__FUN_004346f0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01014000.h"
#include "fnv/symbols_011df000.h"
#include "extradatalist_packet.h"
#include "ExtraDataList.h"
#include "ExtraContainerChanges.h"
#include "InventoryChanges.h"
#include "game_constants.h"


class BGSPortal;
class BGSPrimitive;
class BGSAcousticSpace;
class BGSEncounterZone;
class BGSMusicType;
class TESClimate;
class TESImageSpace;
class TESGlobal;
class TESFaction;
class TESWaterForm;
class Script;
class ScriptLocals;
class NiNode;
class NiTexture;
class TESWorldSpace : public TESForm
{
};
class TESTopicInfo;
class BSMultiBound;
class BSMultiBoundRoom;
class BSOcclusionShape;
class BSPortal;
class CanopyShadowMaskData;
class RagDollData;
class LevCreaModifierData;
class RadioData;
class DistantData;
class FollowerSwimBreadcrumb;


class NiRefCounted
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class NiCell3DNode : public NiRefCounted
{
};
class NiCanopyTexture : public NiRefCounted
{
};
class BSMultiBoundNode : public NiRefCounted
{
};
class BSRoomNode : public NiRefCounted
{
};
class BSOcclusionShapeNode : public NiRefCounted
{
};
class BSPortalNode : public NiRefCounted
{
};

class BSExtraDataEx : public BSExtraData
{
  public:
};

struct LockExtraData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    LockExtraData();
};

class TESForm;
struct TeleportableReference
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    TeleportableReference();
    void Copy(TeleportableReference* apSource);
public:
    ::TESForm *GetTeleportDestinationForm();
};

struct MapMarkerData
{
    int unk00, unk04, unk08, unk0C, unk10;
    MapMarkerData();
    void Copy(MapMarkerData* apSource);
};

struct MediaLocation
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    MediaLocation();
    void Copy(MediaLocation* apSource);
};

struct TwoIntegerValues
{
    int unk00, unk04;
    TwoIntegerValues();
    void Copy(TwoIntegerValues* apSource);
};

struct ImpactSwap
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C, unk030, unk034,
        unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060, unk064, unk068, unk06C,
        unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0, unk0A4,
        unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC,
        unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114,
        unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C,
        unk150, unk154, unk158;
    ImpactSwap();
    void Copy(ImpactSwap* apSource);
};

struct Point3Offset
{
    int unk00, unk04, unk08;
    Point3Offset();
    void Copy(Point3Offset* apSource);
};

struct PatrolRefData
{
    int unk00, unk04, unk08, unk0C, unk10;
    PatrolRefData();
    void Copy(PatrolRefData* apSource);
};

struct PatrolReferenceData
{
    TESObjectREFR* m_pPatrolReferences[4];
    PatrolReferenceData();
};

struct PortalRefData
{
    TESObjectREFR* pRooms[2];
};

struct RoomRefData
{
    int unk00;
    int unk04;
    BSSimpleList<TESObjectREFR*> kLinkedRooms;
    unsigned char bIsMaster;
};

struct CollisionData
{
    unsigned int uiCollisionLayer;
    CollisionData();
};

struct PackageReference
{
    TESPackage* pPackage;
    unsigned char bPickResultFound;
};

struct FactionRankData
{
    TESFaction* pFaction;
    char m_ucRank;
};

struct CanopyShadowMaskData
{
    int unk00;
    int unk04;
};

class BGSPrimitive
{
  public:
    static BGSPrimitive* __cdecl Copy(BGSPrimitive* apSource);
};

class TESFaction;
class ExtraFactionChanges
{
  public:
public:
    void SetFactionRank(::TESFaction *, int);
};

class ExtraEditorRefMoveData : public BSExtraDataEx
{
  public:
    NiPoint3 kRealLocation;
    NiPoint3 kRealAngle;
    NiPoint3 kOldLocation;
    ExtraEditorRefMoveData(TESObjectREFR* apRef);
};

class ExtraAction : public BSExtraDataEx
{
  public:
    unsigned char cFlags;
};
class ExtraOwnership : public BSExtraDataEx
{
  public:
    TESForm* pOwner;
};
class ExtraGlobal : public BSExtraDataEx
{
  public:
    TESGlobal* pGlobalForm;
};
class ExtraRank : public BSExtraDataEx
{
  public:
    int m_iRank;
};
class ExtraCount : public BSExtraDataEx
{
  public:
    unsigned short m_sCount;
};
class ExtraAmmo : public BSExtraDataEx
{
  public:
    TESForm* pAmmo;
    int iCount;
};
class ExtraHotkey : public BSExtraDataEx
{
  public:
    unsigned char cKey;
};
class ExtraSeed : public BSExtraDataEx
{
  public:
    unsigned char cSeed;
};
class ExtraLeveledItem : public BSExtraDataEx
{
  public:
    int iLevelItem;
    unsigned char bFlag;
};
class ExtraHealth : public BSExtraDataEx
{
  public:
    float fHealthPercent;
};
class ExtraHealthPerc : public BSExtraDataEx
{
  public:
    float m_fHealthPercentage;
};
class ExtraUses : public BSExtraDataEx
{
  public:
    unsigned char m_ucUses;
};
class ExtraTimeLeft : public BSExtraDataEx
{
  public:
    float fTimeLeft;
};
class ExtraCharge : public BSExtraDataEx
{
  public:
    float m_fCharge;
};
class ExtraScript : public BSExtraDataEx
{
  public:
    Script* pScript;
    ScriptLocals* pLocals;
};
class ExtraScale : public BSExtraDataEx
{
  public:
    float fScale;
};
class ExtraLock : public BSExtraDataEx
{
  public:
    LockExtraData* pLock;
};
class ExtraRadioData : public BSExtraDataEx
{
  public:
    int kRadioData;
};
class ExtraTeleport : public BSExtraDataEx
{
  public:
    TeleportableReference* pData;
};
class ExtraMapMarker : public BSExtraDataEx
{
  public:
    MapMarkerData* pData;
};
class ExtraAudioMarker : public BSExtraDataEx
{
  public:
    MediaLocation* pData;
};
class ExtraAudioBuoyMarker : public BSExtraDataEx
{
  public:
    TwoIntegerValues* pData;
};
class ExtraPackageStartLocation : public BSExtraDataEx
{
  public:
    TESForm* pLocation;
    NiPoint3 kPos;
    float fAngleDifference;
};
class ExtraRagDollData : public BSExtraDataEx
{
  public:
    RagDollData* pData;
};
class ExtraDistantData : public BSExtraDataEx
{
  public:
    int kDistantData;
};
class ExtraFollower : public BSExtraDataEx
{
  public:
    BSSimpleList<Actor*>* pFollowers;
};
class ExtraHeadTrackTarget : public BSExtraDataEx
{
  public:
    TESObjectREFR* pTarget;
};
class ExtraPoison : public BSExtraDataEx
{
  public:
    TESForm* m_pPoisonItem;
};
class ExtraCell3D : public BSExtraDataEx
{
  public:
    NiPointer<NiCell3DNode> m_pController;
};
class ExtraWaterType : public BSExtraDataEx
{
  public:
    TESWaterForm* m_pWaterForm;
};
class ExtraMusicType : public BSExtraDataEx
{
  public:
    BGSMusicType* pMusic;
};
class ExtraAcousticSpace : public BSExtraDataEx
{
  public:
    BGSAcousticSpace* m_pPathingCell;
};
class ExtraCanopyShadowMask : public BSExtraDataEx
{
  public:
    int iMask;
    NiPointer<NiCanopyTexture> spTexture;
    int unk14;
    int unk18;
};
class ExtraClimate : public BSExtraDataEx
{
  public:
    TESClimate* pClimateData;
};
class ExtraImageSpace : public BSExtraDataEx
{
  public:
    TESImageSpace* m_pImageSpace;
};
class ExtraImpactSwap : public BSExtraDataEx
{
  public:
    ImpactSwap* pSwap;
};
class ExtraReferencePointer : public BSExtraDataEx
{
  public:
    TESObjectREFR* pRef;
};
class ExtraPackage : public BSExtraDataEx
{
  public:
    TESPackage* pPackage;
    int iPackageFlags;
    int m_iPackageData;
    unsigned char cA;
    unsigned char m_ucPackageByte;
    unsigned char cC;
};
class ExtraTresPassPackage : public BSExtraDataEx
{
  public:
    TESPackage* pPackage;
};
class ExtraRunOncePacks : public BSExtraDataEx
{
  public:
    BSSimpleList<PackageReference*>* pPackages;
};
class ExtraOriginalReference : public BSExtraDataEx
{
  public:
    TESObjectREFR* pRef;
};
class ExtraEnableStateParent : public BSExtraDataEx
{
  public:
    TESObjectREFR* pParent;
    unsigned char cFlags;
};
class ExtraRandomTeleportMarker : public BSExtraDataEx
{
  public:
    TESObjectREFR* pTeleportMarker;
};
class ExtraLinkedRef : public BSExtraDataEx
{
  public:
    TESObjectREFR* m_pLinkedReference;
};
class ExtraActivateRef : public BSExtraDataEx
{
  public:
    int unk0C, unk10, unk14, unk18, unk1C;
    ExtraActivateRef();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraDecalRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraDecalRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraReflectedRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraReflectedRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraReflectorRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraReflectorRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraLitWaterRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraLitWaterRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraWaterLightRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraWaterLightRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraMerchantContainer : public BSExtraDataEx
{
  public:
    TESObjectREFR* pContainer;
};
class ExtraXTarget : public BSExtraDataEx
{
  public:
    TESObjectREFR* pTarget;
};
class ExtraEncounterZone : public BSExtraDataEx
{
  public:
    BGSEncounterZone* m_pEncounterZone;
};
class ExtraEmittanceSource : public BSExtraDataEx
{
  public:
    TESForm* pSource;
};
class ExtraMultiBoundRef : public BSExtraDataEx
{
  public:
    TESObjectREFR* pRef;
};
class ExtraMultiBoundMarkerData : public BSExtraDataEx
{
  public:
    Point3Offset* pData;
};
class ExtraLevCreaModifier : public BSExtraDataEx
{
  public:
    int iModifier;
};
class ExtraRefractionProperty : public BSExtraDataEx
{
  public:
    float fRefraction;
};
class ExtraRadius : public BSExtraDataEx
{
  public:
    float fRadius;
};
class ExtraRadiation : public BSExtraDataEx
{
  public:
    float m_fRadiation;
};
class ExtraFactionChangesData : public BSExtraDataEx
{
  public:
    BSSimpleList<FactionRankData*>* pFactions;
};
class ExtraPrimitive : public BSExtraDataEx
{
  public:
    BGSPrimitive* m_pPrimitive;
};
class ExtraMultiBound : public BSExtraDataEx
{
  public:
    NiPointer<BSMultiBoundNode> m_kMultiBoundNode;
};
class ExtraRoom : public BSExtraDataEx
{
  public:
    NiPointer<BSRoomNode> m_pRoomNode;
};
class ExtraPatrolRefData : public BSExtraDataEx
{
  public:
    PatrolRefData* pData;
};
class ExtraOcclusionShape : public BSExtraDataEx
{
  public:
    NiPointer<BSOcclusionShapeNode> pShape;
};
class ExtraOcclusionPlaneRefData : public BSExtraDataEx
{
  public:
    PatrolReferenceData* pData;
};
class ExtraPortalRefData : public BSExtraDataEx
{
  public:
    PortalRefData* pData;
};
class ExtraRoomRefData : public BSExtraDataEx
{
  public:
    RoomRefData* pData;
};
class ExtraCollisionData : public BSExtraDataEx
{
  public:
    CollisionData* pData;
};
class ExtraSayTopicInfoOnceADay : public BSExtraDataEx
{
  public:
    BSSimpleList<TESTopicInfo*>* m_pTopicInfoList;
};
class ExtraPortal : public BSExtraDataEx
{
  public:
    NiPointer<BSPortalNode> m_pPortalNode;
};
class ExtraFollowerSwimBreadcrumbs : public BSExtraDataEx
{
  public:
    int iCount;
    NiPoint3 kLastPos;
    int iLastCell;
    BSSimpleList<FollowerSwimBreadcrumb*> kBreadcrumbs;
};
class ExtraWeaponModFlags : public BSExtraDataEx
{
  public:
};

class ExtraSpecialRenderFlags
{
  public:
    unsigned char cType;
    BSExtraData* pNext;
    int iFlags;
    int unk10;
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void CopyFrom(BSExtraDataEx* apSource);
    ExtraSpecialRenderFlags();
};

class ExtraDataListEx : public ExtraDataList
{
  public:
    void FUN_004103d0(BSExtraDataEx* apExtra);
};

// @fnv 0x004103d0
void ExtraDataListEx::FUN_004103d0(BSExtraDataEx* apExtra)
{
    if (!apExtra || !reinterpret_cast<::fnv_00411f20::FUN_00411f20_shell *>(this)->FUN_00411f20((::BSExtraData *)(apExtra)))
        return;

    BSSimpleList<PackageReference*>* pIter = 0;
    switch (((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((apExtra))->IsPatrolling())))
    {
    case 0x4C: {
        ExtraEditorRefMoveData* pMoveData = (ExtraEditorRefMoveData*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x4C);
        if (!pMoveData)
        {
            pMoveData = new ExtraEditorRefMoveData(0);
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(pMoveData);
        }
        ExtraEditorRefMoveData* pSource = (ExtraEditorRefMoveData*)apExtra;
        pMoveData->kOldLocation = pSource->kOldLocation;
        pMoveData->kRealLocation = pSource->kRealLocation;
        pMoveData->kRealAngle = pSource->kRealAngle;
        break;
    }
    case 0x0E:
        reinterpret_cast<::FUN_0041b3d0_shell *>(this)->FUN_0041b3d0(((ExtraAction*)apExtra)->cFlags);
        break;
    case 0x21:
        reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>(this)->FUN_00419700((::fnv_00419700::TESForm *)(((ExtraOwnership*)apExtra)->pOwner));
        break;
    case 0x22:
        reinterpret_cast<::FUN_004197d0_shell *>(this)->SetExtraDataValue((int)(((ExtraGlobal*)apExtra)->pGlobalForm));
        break;
    case 0x23:
        reinterpret_cast<::fnv_004198a0::FUN_004198a0 *>(this)->SetTeleportData((::fnv_004198a0::TeleportableReference *)(((ExtraRank*)apExtra)->m_iRank));
        break;
    case 0x24:
        reinterpret_cast<::FUN_00419ad0_shell *>(this)->FUN_00419ad0(((ExtraCount*)apExtra)->m_sCount);
        break;
    case 0x6E: {
        ExtraAmmo* pAmmo = (ExtraAmmo*)apExtra;
        reinterpret_cast<::FUN_0042eb60_shell *>(this)->SetOwnership(pAmmo->pAmmo, (void *)(pAmmo->iCount));
        break;
    }
    case 0x16:
        reinterpret_cast<::FUN_0041aa20_shell *>(this)->SetWornState(true, false);
        break;
    case 0x4A:
        reinterpret_cast<::FUN_0042dde0_cls *>(this)->SetHotKey(((ExtraHotkey*)apExtra)->cKey);
        break;
    case 0x17:
        reinterpret_cast<::FUN_0041aa20_shell *>(this)->SetWornState(true, true);
        break;
    case 0x31:
        reinterpret_cast<::fnv_0041ac30::FUN_0041ac30List *>(this)->FUN_0041ac30(((ExtraSeed*)apExtra)->cSeed);
        break;
    case 0x2F:
        reinterpret_cast<::fnv_0041d280::FUN_0041d280_shell *>(this)->SetLeveledItemIndex(((ExtraLeveledItem*)apExtra)->iLevelItem);
        reinterpret_cast<::FUN_0041d330_Class *>(this)->SetExtraDataByte(((ExtraLeveledItem*)apExtra)->bFlag);
        break;
    case 0x25:
        reinterpret_cast<::ExtraDataList *>(this)->SetExtraHealth((((ExtraHealth*)apExtra)->fHealthPercent));
        break;
    case 0x7A:
        reinterpret_cast<::FUN_0041b580_shell *>(this)->SetHealthPerc((((ExtraHealthPerc*)apExtra)->m_fHealthPercentage));
        break;
    case 0x26:
        reinterpret_cast<::FUN_00419a20 *>(this)->SetExtra(((ExtraUses*)apExtra)->m_ucUses);
        break;
    case 0x27:
        reinterpret_cast<::FUN_00419bb0_cls *>(this)->FUN_00419bb0((((ExtraTimeLeft*)apExtra)->fTimeLeft));
        break;
    case 0x28:
        reinterpret_cast<::FUN_00419c60_cls *>(this)->FUN_00419c60((((ExtraCharge*)apExtra)->m_fCharge));
        break;
    case 0x0D:
        reinterpret_cast<::FUN_00419ed0_shell *>(this)->FUN_00419ed0(((ExtraScript*)apExtra)->pScript);
        reinterpret_cast<::FUN_00419f80_shell *>(this)->FUN_00419f80(((ExtraScript*)apExtra)->pLocals);
        break;
    case 0x30:
        reinterpret_cast<::FUN_00419fb0_StandIn *>(this)->FUN_00419fb0(((ExtraScale*)apExtra)->fScale);
        break;
    case 0x2A: {
        LockExtraData* pLock = new LockExtraData;
        ::__memcpy(pLock, ((ExtraLock*)apExtra)->pLock, sizeof(LockExtraData));
        reinterpret_cast<::ExtraList_419050 *>(this)->FUN_00419050(pLock);
        break;
    }
    case 0x68:
        reinterpret_cast<::fnv_00418310::FUN_00418310_shell *>(this)->SetRadioData((::fnv_00418310::RadioReferenceData *)(int *)(&((ExtraRadioData*)apExtra)->kRadioData));
        break;
    case 0x2B: {
        TeleportableReference* pTeleport = new TeleportableReference;
        reinterpret_cast<::QuantityData *>((pTeleport))->CopyFrom(((ExtraTeleport*)apExtra)->pData);
        reinterpret_cast<::fnv_00419120::FUN_00419120_shell *>(this)->FUN_00419120((::fnv_00419120::TeleportableReference *)(pTeleport));
        break;
    }
    case 0x2C: {
        MapMarkerData* pTeleportMarker = new MapMarkerData;
        reinterpret_cast<::FUN_00438df0 *>((pTeleportMarker))->FUN_00438df0_copy((::FUN_00438df0 *)(((ExtraMapMarker*)apExtra)->pData));
        reinterpret_cast<::fnv_00419250::FUN_00419250_shell *>(this)->SetMapMarker((::fnv_00419250::MapMarkerData *)(pTeleportMarker));
        break;
    }
    case 0x90: {
        MediaLocation* pAudio = new MediaLocation;
        reinterpret_cast<::S_00589770_Class *>((pAudio))->CopyFrom((::S_00589770_Class *)(((ExtraAudioMarker*)apExtra)->pData));
        reinterpret_cast<::fnv_00419380::FUN_00419380_shell *>(this)->SetAudioMarker((::fnv_00419380::MediaLocation *)(pAudio));
        break;
    }
    case 0x91: {
        TwoIntegerValues* pBuoy = new TwoIntegerValues;
        reinterpret_cast<::FUN_004534f0_shell *>((pBuoy))->FUN_004534f0((unsigned int)(((ExtraAudioBuoyMarker*)apExtra)->pData));
        reinterpret_cast<::fnv_004194b0::ExtraDataListRemoveTrespassPackage *>(this)->FUN_004194b0((::fnv_004194b0::Date *)(pBuoy));
        break;
    }
    case 0x18: {
        TESWorldSpace* pWorld = dynamic_cast<TESWorldSpace*>(((ExtraPackageStartLocation*)apExtra)->pLocation);
        TESObjectCELL* m_pOwningCell = dynamic_cast<TESObjectCELL*>(((ExtraPackageStartLocation*)apExtra)->pLocation);
        reinterpret_cast<::fnv_0041ad00::FUN_0041ad00_shell *>(this)->FUN_0041ad00((::fnv_0041ad00::TESWorldSpace *)(pWorld), m_pOwningCell, &((ExtraPackageStartLocation*)apExtra)->kPos,
                   ((ExtraPackageStartLocation*)apExtra)->fAngleDifference);
        break;
    }
    case 0x14:
        reinterpret_cast<::FUN_0041d5b0_class *>(this)->FUN_0041d5b0(((ExtraRagDollData*)apExtra)->pData);
        break;
    case 0x13:
        reinterpret_cast<::fnv_0041d950::S0041d950 *>(this)->FUN_0041d950((::fnv_0041d950::Vec3 *)(int *)(&((ExtraDistantData*)apExtra)->kDistantData));
        break;
    case 0x1D: {
        BSSimpleList<Actor*>* pFollowerIter = ((ExtraFollower*)apExtra)->pFollowers;
        while (pFollowerIter && ((::Actor *)(new ((void *)(pFollowerIter)) ::Vec3())))
        {
            Actor* pFollower = ((::Actor *)(new ((void *)(pFollowerIter)) ::Vec3()));
            reinterpret_cast<::fnv_00422480::FUN_00422480_shell *>(this)->FUN_00422480((::fnv_00422480::Actor *)(pFollower));
            pFollowerIter = ((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((pFollowerIter))->FUN_00726070()));
        }
        break;
    }
    case 0x46:
        reinterpret_cast<::fnv_00419dc0::FUN_00419dc0_shell2 *>(this)->FUN_00419dc0((::fnv_00419dc0::TESObjectREFRHelper *)(((ExtraHeadTrackTarget*)apExtra)->pTarget));
        break;
    case 0x3F:
        reinterpret_cast<::FUN_00419d10 *>(this)->SetExtra(((ExtraPoison*)apExtra)->m_pPoisonItem);
        break;
    case 0x02:
        reinterpret_cast<::fnv_0041b7e0::FUN_0041b7e0_cls *>(this)->SetNodeExtra(((ExtraCell3D*)apExtra)->m_pController);
        break;
    case 0x03:
        reinterpret_cast<::fnv_0041e160::FUN_0041e160_shell *>(this)->SetCellWaterType((::fnv_0041e160::TESWaterForm *)(((ExtraWaterType*)apExtra)->m_pWaterForm));
        break;
    case 0x07:
        reinterpret_cast<::fnv_0041bd10::FUN_0041bd10_shell *>(this)->FUN_0041bd10((::fnv_0041bd10::BGSMusicType *)(((ExtraMusicType*)apExtra)->pMusic));
        break;
    case 0x81:
        reinterpret_cast<::fnv_0041c090::FUN_0041c090_shell *>(this)->SetAcousticSpace((::fnv_0041c090::BGSAcousticSpace *)(((ExtraAcousticSpace*)apExtra)->m_pPathingCell));
        break;
    case 0x0A: {
        CanopyShadowMaskData* pMaskData;
        reinterpret_cast<::fnv_0041c490::FUN_0041c490_cls *>(this)->FUN_0041c490(((ExtraCanopyShadowMask*)apExtra)->iMask, (::fnv_0041c490::NiRenderedTexture *)(::NiCanopyTexture *)(((ExtraCanopyShadowMask*)apExtra)->spTexture),
                                (::fnv_0041c490::_D3DLOCKED_RECT **)(::CanopyShadowMaskData **)(&pMaskData));
        pMaskData->unk04 = ((ExtraCanopyShadowMask*)apExtra)->unk18;
        pMaskData->unk00 = ((ExtraCanopyShadowMask*)apExtra)->unk14;
        break;
    }
    case 0x08:
        reinterpret_cast<::fnv_0041c190::FUN_0041c190_shell *>(this)->SetClimate((::fnv_0041c190::TESClimate *)(((ExtraClimate*)apExtra)->pClimateData));
        break;
    case 0x59:
        reinterpret_cast<::fnv_0041c290::FUN_0041c290_shell *>(this)->SetImageSpaceExtra((::fnv_0041c290::TESImageSpace *)(((ExtraImageSpace*)apExtra)->m_pImageSpace));
        break;
    case 0x8C: {
        ImpactSwap* pSwap = new ImpactSwap;
        reinterpret_cast<::ImpactSwapMaps *>((pSwap))->FUN_0058f4c0((::ImpactSwapMaps *)(((ExtraImpactSwap*)apExtra)->pSwap));
        reinterpret_cast<::fnv_0041c390::ExtraDataList2 *>(this)->FUN_0041c390(pSwap);
        break;
    }
    case 0x1C:
        reinterpret_cast<::fnv_0041c7f0::FUN_0041c7f0_cls *>(this)->FUN_0041c7f0(((ExtraReferencePointer*)apExtra)->pRef);
        break;
    case 0x19:
        reinterpret_cast<::FUN_0041c930_shell *>(this)->FUN_0041c930((::Package_0041c930 *)(((ExtraPackage*)apExtra)->pPackage), ((ExtraPackage*)apExtra)->iPackageFlags,
                           ((ExtraPackage*)apExtra)->m_iPackageData, ((ExtraPackage*)apExtra)->cA,
                           ((ExtraPackage*)apExtra)->m_ucPackageByte, ((ExtraPackage*)apExtra)->cC);
        break;
    case 0x1A:
        reinterpret_cast<::fnv_0041cc90::ExtraDataListStandIn *>(this)->SetTrespassPackage((::fnv_0041cc90::TrespassPackage *)(((ExtraTresPassPackage*)apExtra)->pPackage));
        break;
    case 0x1B:
        pIter = ((ExtraRunOncePacks*)apExtra)->pPackages;
        while (pIter)
        {
            PackageReference* pRunOnce = ((::PackageReference *)(new ((void *)(pIter)) ::Vec3()));
            if (pRunOnce)
            {
                TESPackage* pPackage = pRunOnce->pPackage;
                unsigned char bPickResultFound = pRunOnce->bPickResultFound;
                reinterpret_cast<::FUN_0041d700 *>(this)->AddExtraData((int)(pPackage), bPickResultFound);
            }
            pIter = ((::BSSimpleList< ::PackageReference *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
        break;
    case 0x20:
        reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>(this)->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(((ExtraOriginalReference*)apExtra)->pRef));
        break;
    case 0x37:
        reinterpret_cast<::FUN_0041da40_shell *>(this)->FUN_0041da40(((ExtraEnableStateParent*)apExtra)->pParent);
        reinterpret_cast<::FUN_0041dc70_shell *>(this)->SetExtraFlags(((ExtraEnableStateParent*)apExtra)->cFlags);
        break;
    case 0x3B:
        reinterpret_cast<::FUN_0041e250_cls *>(this)->FUN_0041e250(((ExtraRandomTeleportMarker*)apExtra)->pTeleportMarker);
        break;
    case 0x51:
        reinterpret_cast<::FUN_0041e440_shell *>(this)->FUN_0041e440(((ExtraLinkedRef*)apExtra)->m_pLinkedReference);
        break;
    case 0x53: {
        ExtraActivateRef* m_pFourthReference = (ExtraActivateRef*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x53);
        if (!m_pFourthReference)
        {
            m_pFourthReference = new ExtraActivateRef;
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(m_pFourthReference);
        }
        reinterpret_cast<::FUN_00433b70_shell *>((m_pFourthReference))->FUN_00433b70((::BSExtraData *)(apExtra));
        break;
    }
    case 0x57: {
        ExtraDecalRefs* pDecalRefs = (ExtraDecalRefs*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x57);
        if (!pDecalRefs)
        {
            pDecalRefs = new ExtraDecalRefs;
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(pDecalRefs);
        }
        reinterpret_cast<::fnv_004342b0::FUN_004342b0_shell *>((pDecalRefs))->LoadItemsFromArchive(apExtra);
        break;
    }
    case 0x65: {
        ExtraReflectedRefs* pReflectedRefs = (ExtraReflectedRefs*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x65);
        if (!pReflectedRefs)
        {
            pReflectedRefs = new ExtraReflectedRefs;
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(pReflectedRefs);
        }
        reinterpret_cast<::fnv_004346f0::FUN_004346f0_shell *>((pReflectedRefs))->CopyReflectedRefs((::BSExtraData *)(apExtra));
        break;
    }
    case 0x66: {
        ExtraReflectorRefs* pReflectorRefs = (ExtraReflectorRefs*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x66);
        if (!pReflectorRefs)
        {
            pReflectorRefs = new ExtraReflectorRefs;
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(pReflectorRefs);
        }
        reinterpret_cast<::FNVLoadHost *>((pReflectorRefs))->LoadEntriesFromBlock(apExtra);
        break;
    }
    case 0x85: {
        ExtraLitWaterRefs* pLitWaterRefs = (ExtraLitWaterRefs*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x85);
        if (!pLitWaterRefs)
        {
            pLitWaterRefs = new ExtraLitWaterRefs;
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(pLitWaterRefs);
        }
        reinterpret_cast<::FUN_00434ee0_Class *>((pLitWaterRefs))->FUN_00434ee0((int)(apExtra));
        break;
    }
    case 0x84: {
        ExtraWaterLightRefs* pWaterLightRefs = (ExtraWaterLightRefs*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x84);
        if (!pWaterLightRefs)
        {
            pWaterLightRefs = new ExtraWaterLightRefs;
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(pWaterLightRefs);
        }
        reinterpret_cast<::FUN_00434a70_cls *>((pWaterLightRefs))->FUN_00434a70((int)(apExtra));
        break;
    }
    case 0x3C:
        reinterpret_cast<::FUN_00421430_shell *>(this)->FUN_00421430(((ExtraMerchantContainer*)apExtra)->pContainer);
        break;
    case 0x44:
        reinterpret_cast<::FUN_00421b70_shell *>(this)->FUN_00421b70(((ExtraXTarget*)apExtra)->pTarget);
        break;
    case 0x74:
        reinterpret_cast<::fnv_00421c60::FUN_00421c60_shell *>(this)->FUN_00421c60((::fnv_00421c60::BGSEncounterZone *)(((ExtraEncounterZone*)apExtra)->m_pEncounterZone));
        break;
    case 0x67:
        reinterpret_cast<::fnv_00421d50::FUN_00421d50_shell *>(this)->SetEmittanceSource((::fnv_00421d50::TESForm *)(((ExtraEmittanceSource*)apExtra)->pSource));
        break;
    case 0x63:
        reinterpret_cast<::FUN_00421e40_shell *>(this)->FUN_00421e40(((ExtraMultiBoundRef*)apExtra)->pRef);
        break;
    case 0x62: {
        Point3Offset* pNewData = 0;
        Point3Offset* pSrcData = ((ExtraMultiBoundMarkerData*)apExtra)->pData;
        if (pSrcData)
        {
            pNewData = new Point3Offset;
            reinterpret_cast<::Unk_00439120 *>((pNewData))->FUN_00439120((::Unk_00439120 *)(pSrcData));
        }
        reinterpret_cast<::FUN_00421f30_shell *>(this)->FUN_00421f30(pNewData);
        break;
    }
    case 0x1E:
        reinterpret_cast<::FUN_00421540_shell *>(this)->FUN_00421540(((ExtraLevCreaModifier*)apExtra)->iModifier);
        break;
    case 0x48:
        reinterpret_cast<::fnv_00422750::FUN_00422750_class *>(this)->FUN_00422750(true, ((ExtraRefractionProperty*)apExtra)->fRefraction);
        break;
    case 0x3E:
        reinterpret_cast<::FUN_0041ab70_shell *>(this)->FUN_0041ab70(true);
        break;
    case 0x55:
        break;
    case 0x5C:
        reinterpret_cast<::FUN_00422220_shell *>(this)->FUN_00422220(((ExtraRadius*)apExtra)->fRadius);
        break;
    case 0x5D:
        reinterpret_cast<::FUN_00422350_shell *>(this)->SetRadiation(((ExtraRadiation*)apExtra)->m_fRadiation);
        break;
    case 0x5E: {
        reinterpret_cast<::FUN_0042e760_shell *>(this)->FUN_0042e760();
        ExtraFactionChanges* pChanges = reinterpret_cast<::FUN_0042e800_shell *>(this)->FUN_0042e800();
        BSSimpleList<FactionRankData*>* pRankIter = ((ExtraFactionChangesData*)apExtra)->pFactions;
        while (pRankIter && ((::FactionRankData *)(new ((void *)(pRankIter)) ::Vec3())))
        {
            FactionRankData* pRank = ((::FactionRankData *)(new ((void *)(pRankIter)) ::Vec3()));
            if (pRank)
                pChanges->SetFactionRank(pRank->pFaction, pRank->m_ucRank);
            pRankIter = ((::BSSimpleList< ::FactionRankData *> *)(reinterpret_cast<::Callees *>((pRankIter))->FUN_00726070()));
        }
        break;
    }
    case 0x5A:
        reinterpret_cast<::FUN_0042e2c0_shell *>(this)->EnsureNavMeshPortalExtra((::ExtraNavMeshPortal *)(apExtra));
        break;
    case 0x6B: {
        BGSPrimitive* pSrcPrimitive = ((ExtraPrimitive*)apExtra)->m_pPrimitive;
        BGSPrimitive* pNewPrimitive = ((::BGSPrimitive *)(::FUN_004a4d40((::Target004a4d40 *)(pSrcPrimitive))));
        reinterpret_cast<::fnv_0041fa60::FUN_0041fa60_shell *>(this)->AddPrimitiveExtra((::fnv_0041fa60::BGSPrimitive *)(pNewPrimitive));
        break;
    }
    case 0x61:
        reinterpret_cast<::fnv_00422050::FUN_00422050_shell *>(this)->FUN_00422050(((ExtraMultiBound*)apExtra)->m_kMultiBoundNode);
        break;
    case 0x79:
        reinterpret_cast<::fnv_00420f00::FUN_00420f00_shell *>(this)->FUN_00420f00(((ExtraRoom*)apExtra)->m_pRoomNode);
        break;
    case 0x6F: {
        PatrolRefData* pPatrol = new PatrolRefData;
        reinterpret_cast<::Target0067c6f0 *>((pPatrol))->FUN_0067c6f0((::Target0067c6f0 *)(((ExtraPatrolRefData*)apExtra)->pData));
        reinterpret_cast<::fnv_0041fc10::FUN_0041fc10_shell *>(this)->SetPatrolRefData((::fnv_0041fc10::PatrolRefData *)(pPatrol));
        break;
    }
    case 0x71:
        reinterpret_cast<::FUN_00422150_shell *>(this)->FUN_00422150((::BSOcclusionPlane *)(::BSOcclusionShapeNode *)(((ExtraOcclusionShape*)apExtra)->pShape));
        break;
    case 0x76: {
        PatrolReferenceData* pPlaneData = new PatrolReferenceData;
        ExtraOcclusionPlaneRefData* pOcclusionExtra = (ExtraOcclusionPlaneRefData*)apExtra;
        PatrolReferenceData* pSrcLinkedRefs = pOcclusionExtra->pData;
        for (int i = 0; i < 4; i++)
            pPlaneData->m_pPatrolReferences[i] = pSrcLinkedRefs->m_pPatrolReferences[i];
        reinterpret_cast<::fnv_0041fec0::FUN_0041fec0_shell *>(this)->FUN_0041fec0((::fnv_0041fec0::PatrolReferenceData *)(pPlaneData));
        break;
    }
    case 0x77: {
        ExtraPortalRefData* pPortalRefExtra = (ExtraPortalRefData*)apExtra;
        PortalRefData* pPortalRefData = pPortalRefExtra->pData;
        for (int j = 0; j < 2; j++)
            reinterpret_cast<::fnv_00420a60::FUN_00420a60_Class *>(this)->FUN_00420a60(j, pPortalRefData->pRooms[j]);
        break;
    }
    case 0x7B: {
        ExtraRoomRefData* pRefExtra = (ExtraRoomRefData*)apExtra;
        RoomRefData* pRoomRefData = pRefExtra->pData;
        BSSimpleList<TESObjectREFR*>* pRoomLinkIter = &pRoomRefData->kLinkedRooms;
        while (pRoomLinkIter && ((::TESObjectREFR *)(new ((void *)(pRoomLinkIter)) ::Vec3())))
        {
            reinterpret_cast<::FUN_00420c10_Class *>(this)->FUN_00420c10((int)(((::TESObjectREFR *)(new ((void *)(pRoomLinkIter)) ::Vec3()))));
            pRoomLinkIter = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((pRoomLinkIter))->FUN_00726070()));
        }
        reinterpret_cast<::FUN_00420870_cls *>(this)->SetFlagOnRecord123(pRoomRefData->bIsMaster != 0);
        break;
    }
    case 0x72: {
        CollisionData* pCollision = new CollisionData;
        reinterpret_cast<::FUN_00537e90 *>((pCollision))->SetQuantity(((unsigned int)(::FUN_00559450((int *)(((ExtraCollisionData*)apExtra)->pData)))));
        reinterpret_cast<::fnv_00420fd0::FUN_00420fd0_cls *>(this)->FUN_00420fd0((int)(pCollision));
        break;
    }
    case 0x73: {
        BSSimpleList<TESTopicInfo*>* pInfoIter = ((ExtraSayTopicInfoOnceADay*)apExtra)->m_pTopicInfoList;
        while (pInfoIter && ((::TESTopicInfo *)(new ((void *)(pInfoIter)) ::Vec3())))
        {
            reinterpret_cast<::fnv_0042ef20::FUN_0042ef20_StandIn *>(this)->FUN_0042ef20(((::TESTopicInfo *)(new ((void *)(pInfoIter)) ::Vec3())));
            reinterpret_cast<::Callees *>((pInfoIter))->FUN_00726070();
        }
        break;
    }
    case 0x78: {
        BSPortalNode* pPortalNode = apExtra ? ((ExtraPortal*)apExtra)->m_pPortalNode : NiPointer<BSPortalNode>(0);
        reinterpret_cast<::FUN_00420e00_cls *>(this)->FUN_00420e00(pPortalNode);
        break;
    }
    case 0x80:
        reinterpret_cast<::fnv_0042f200::FUN_0042f200_shell *>(this)->SetIgnoredBySandbox(true);
        break;
    case 0x8B: {
        ExtraFollowerSwimBreadcrumbs* pDstBreadcrumbs = ((::ExtraFollowerSwimBreadcrumbs *)(reinterpret_cast<::FUN_0042f420_helper *>(this)->GetOrCreateExtraData()));
        ExtraFollowerSwimBreadcrumbs* pSrcBreadcrumbs = (ExtraFollowerSwimBreadcrumbs*)apExtra;
        pDstBreadcrumbs->kLastPos = pSrcBreadcrumbs->kLastPos;
        pDstBreadcrumbs->iLastCell = pSrcBreadcrumbs->iLastCell;
        pDstBreadcrumbs->iCount = pSrcBreadcrumbs->iCount;
        reinterpret_cast<::FileMatchList *>(&(pDstBreadcrumbs->kBreadcrumbs))->RemoveAll();
        for (BSSimpleList<FollowerSwimBreadcrumb*>* pCrumbIter = &pSrcBreadcrumbs->kBreadcrumbs; pCrumbIter;
             pCrumbIter = ((::BSSimpleList< ::FollowerSwimBreadcrumb *> *)(reinterpret_cast<::Callees *>((pCrumbIter))->FUN_00726070())))
        {
            if (((::FollowerSwimBreadcrumb *)(new ((void *)(pCrumbIter)) ::Vec3())))
                reinterpret_cast<::Callees *>(&(pDstBreadcrumbs->kBreadcrumbs))->FUN_00905820((void *)&(((::FollowerSwimBreadcrumb *)(new ((void *)(pCrumbIter)) ::Vec3()))));
        }
        break;
    }
    case 0x8D:
        if (reinterpret_cast<::FUN_00411e20Class *>((((ExtraWeaponModFlags*)apExtra)))->HasFlag(1))
            reinterpret_cast<::fnv_0042e380::FUN_0042e380_Class *>(this)->FUN_0042e380(1);
        if (reinterpret_cast<::FUN_00411e20Class *>((((ExtraWeaponModFlags*)apExtra)))->HasFlag(2))
            reinterpret_cast<::fnv_0042e380::FUN_0042e380_Class *>(this)->FUN_0042e380(2);
        if (reinterpret_cast<::FUN_00411e20Class *>((((ExtraWeaponModFlags*)apExtra)))->HasFlag(4))
            reinterpret_cast<::fnv_0042e380::FUN_0042e380_Class *>(this)->FUN_0042e380(4);
        break;
    case 0x92: {
        ExtraSpecialRenderFlags* pRenderFlags = (ExtraSpecialRenderFlags*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x92);
        if (!pRenderFlags)
        {
            pRenderFlags = new ExtraSpecialRenderFlags;
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((BSExtraData*)pRenderFlags);
        }
        pRenderFlags->CopyFrom(apExtra);
        break;
    }
    default:
        ::FUN_005b5e40();
        break;
    }
}
