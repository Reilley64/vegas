
// tesnpc_ctx_variant.cpp: context variant of src/fallout_shared/tesnpc.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "fnv/decl/ActorSpellView.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/B441420Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BipedAnimWeap.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/Dummy_00607810.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_0041c930_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041cb70_shell.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0047bdd0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_0047ded0_shell.h"
#include "fnv/decl/FUN_0047fb50_shell.h"
#include "fnv/decl/FUN_00480000_shell.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004870f0_shell.h"
#include "fnv/decl/FUN_00487240_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004bfe50_t.h"
#include "fnv/decl/FUN_004c8220_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00503240_shell.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/FUN_005b8fc0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FUN_00601800_shell.h"
#include "fnv/decl/FUN_00601c10_shell.h"
#include "fnv/decl/FUN_00602130_shell.h"
#include "fnv/decl/FUN_00602170_shell.h"
#include "fnv/decl/FUN_006031e0_shell.h"
#include "fnv/decl/FUN_00603200_shell.h"
#include "fnv/decl/FUN_00604210_shell.h"
#include "fnv/decl/FUN_00606050_shell.h"
#include "fnv/decl/FUN_00606800_shell.h"
#include "fnv/decl/FUN_00607350_shell.h"
#include "fnv/decl/FUN_00607830_helper.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00613870_Class.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00634890_shell.h"
#include "fnv/decl/FUN_006727b0_shell.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_0094eaf0_Class.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00c748d0_C.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/HeadNPC.h"
#include "fnv/decl/Header47cb90.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/ModelCopyView.h"
#include "fnv/decl/RaceAppearance__Race.h"
#include "fnv/decl/Ref3.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/Self9.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Thing575.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk_0097fa10.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_0043ecb0__FUN_0043ecb0_shell.h"
#include "fnv/decl/fnv_0043ed90__AttachTask.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047d220__ABD_47d220.h"
#include "fnv/decl/fnv_0047f500__FUN_0047f500_shell.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048cce0__FUN_0048cce0_shell.h"
#include "fnv/decl/fnv_0048d290__FUN_0048d290_shell.h"
#include "fnv/decl/fnv_0048d630__SpellListAccess.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0057b7c0__Actor57.h"
#include "fnv/decl/fnv_00613c50__FUN_00613c50_C.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0088c830__ThisC.h"
#include "fnv/decl/fnv_008a7a90__ActorAnimView.h"
#include "fnv/decl/fnv_008a8e50__ActorP_S.h"
#include "fnv/decl/fnv_008b3c30__FUN_008b3c30_shell.h"
#include "fnv/decl/fnv_008bb520__TES.h"
#include "fnv/decl/fnv_00950110__FUN_00950110_pc.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_00505000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d9000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00655000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00754000.h"
#include "fnv/symbols_008f2000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "tesnpc_pc_decls.h"

class Helper009f8770
{
  public:
};
class FUN_00484d40_Host
{
  public:
    void FUN_00484d40(unsigned int* apFormID, int aiSize);
};
class FUN_004ac110_shell
{
  public:
    TESRace* FUN_004ac110();
};
class FUN_009611e0_shell
{
  public:
    int FUN_009611e0();
};
class FUN_006141f0_shell
{
  public:
};
class FUN_008b70d0_shell
{
  public:
    Animation* FUN_008b70d0();
};
class FUN_004eaf60_shell
{
  public:
    bool FUN_004eaf60();
};
class FUN_0043c610_shell
{
  public:
    void RunVirtualMethod28();
};
class ActorView
{
  public:
    TESActorBase* GetActorBase();
};
class GlobalObject_0040c150
{
  public:
};
extern GlobalObject_0040c150 g_011d2b38;
class ActorFace
{
  public:
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
    virtual NiNode* GetHeadRootNode(bool);
    virtual NiNode* GetFaceRootNode(bool);
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void UpdateHead();
};
class NodeFace
{
  public:
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
    virtual void InsertChild(NiAVObject*);
};
class ModelFace
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void SetModelFilePath(const char*);
};
class NPCModelView
{
  public:
    int pad[0xdc / 4];
    ModelFace kModel;
};
class FaceRefr
{
  public:
};
class PlayerFace
{
  public:
};
class NPCFace
{
  public:
};
class FUN_005dd590
{
  public:
    int data[0x3c];
    FUN_005dd590();
    ~FUN_005dd590();
};
class FaceGenPaletteEntry
{
  public:
    int data[0xe];
    ~FaceGenPaletteEntry();
};
class QHeadLocal : public FaceGenPaletteEntry
{
  public:
    QHeadLocal(TESNPC* apNPC, int aiFlag);
};
class Animation;
class NiAVObject;
class MiddleHighProcess : public BaseProcess
{
public:
    ::NiAVObject *GetSceneRoot();
public:
    bool IsActorInCombat();
public:
    ::Animation *GetAnimation();
};
class TESNPCFace : public TESNPC
{
  public:
    void FUN_00609f60(Actor* apActor);
};

// @fnv 0x00609f60
void TESNPCFace::FUN_00609f60(Actor* apActor)
{
    bool bChanged = false;
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            unsigned int uiNumRows = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(m_kFaceGenCoordinates[i][j]))->FUN_009611e0()));
            unsigned int uiNumCols = reinterpret_cast<::BGSTerrainManager *>(&(m_kFaceGenCoordinates[i][j]))->GetMinLevel();
            for (unsigned int r = 0; r < uiNumRows; r++)
            {
                for (unsigned int c = 0; c < uiNumCols; c++)
                {
                    float fValue;
                    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((Helper009f8770*)this)))->FUN_00484d00(&fValue, 4);
                    if (*((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(m_kFaceGenCoordinates[i][j].FUN_0060b370(r, c)))->FUN_00629ab0({}))) != fValue)
                    {
                        *(float*)((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(m_kFaceGenCoordinates[i][j].FUN_0060b370(r, c)))->FUN_00629ab0({}))) = fValue;
                        bChanged = true;
                    }
                }
            }
        }
    }
    bool bPrevHadRace = false;
    if (((FUN_004ac110_shell*)this)->FUN_004ac110())
        bPrevHadRace = false;
    else
        ::FUN_005b5e40();
    unsigned int uiNewRace;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&uiNewRace, 4);
    TESRace* pRace = dynamic_cast<TESRace*>(FUN_004839c0(uiNewRace));
    if (uiNewRace && !pRace)
        ::FUN_005b5e40();
    if (((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())) != pRace)
        bChanged = true;
    reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(pRace));
    bool bNowHasRace = false;
    if (((FUN_004ac110_shell*)this)->FUN_004ac110())
        bNowHasRace = false;
    else
        ::FUN_005b5e40();
    unsigned int uiNewHairFormID;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&uiNewHairFormID, 4);
    TESHair* pReadHair = dynamic_cast<TESHair*>(FUN_004839c0(uiNewHairFormID));
    if (uiNewHairFormID && !pReadHair)
        ::FUN_005b5e40();
    if (m_pHair != pReadHair)
        bChanged = true;
    m_pHair = pReadHair;
    unsigned int uiEyes;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&uiEyes, 4);
    TESEyes* pCurEyeForm = dynamic_cast<TESEyes*>(FUN_004839c0(uiEyes));
    if (uiEyes && !pCurEyeForm)
        ::FUN_005b5e40();
    if (m_pEyes != pCurEyeForm)
        bChanged = true;
    m_pEyes = pCurEyeForm;
    float fScaleMultiplier;
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((Helper009f8770*)this)))->FUN_00484d00(&fScaleMultiplier, 4);
    unsigned int uiCurHairColor;
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((Helper009f8770*)this)))->FUN_00484d00(&uiCurHairColor, 4);
    if (m_fHairLength != fScaleMultiplier || iHairColor != uiCurHairColor)
        bChanged = true;
    m_fHairLength = fScaleMultiplier;
    iHairColor = uiCurHairColor;
    bool bLoadedFemale;
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((Helper009f8770*)this)))->FUN_00484d00(&bLoadedFemale, 1);
    if (TESActorBaseData::GetFlag(1) != bLoadedFemale)
        bChanged = true;
    reinterpret_cast<::FlagSet *>(this)->FUN_0047dd50(1, bLoadedFemale, true);
    if (bChanged)
    {
        NiAVObject* p3D = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apActor))->FUN_0043fcd0()));
        NiNode* pNode = 0;
        if (p3D)
            pNode = p3D->IsSceneNode();
        if (bPrevHadRace == bNowHasRace)
        {
            if (pNode)
            {
                NiControllerManager* pAnimManager = 0;
                if (((FUN_008b70d0_shell*)apActor)->FUN_008b70d0() &&
                    reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((ActorAnimData*)((FUN_008b70d0_shell*)apActor)->FUN_008b70d0())))->FUN_00496940())
                    pAnimManager = ((::NiControllerManager *)(::fnv_00537bd0::GetStringAtOffset((const char *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((ActorAnimData*)((FUN_008b70d0_shell*)apActor)->FUN_008b70d0())))->FUN_00496940()))));
                NiControllerManager* pkManager = pAnimManager;
                NiNode* pFace = ((ActorFace*)apActor)->GetFaceRootNode(false);
                if (pFace && ((FUN_009611e0_shell*)pFace)->FUN_009611e0())
                {
                    ::FUN_00a6e8e0((::S_00a6e8e0_Object *)(pFace), (::S_00a6e8e0_Palette *)(pkManager));
                    ((NodeFace*)((FUN_009611e0_shell*)pFace)->FUN_009611e0())->InsertChild(pFace);
                }
                pFace = ((ActorFace*)apActor)->GetHeadRootNode(false);
                if (pFace && ((FUN_009611e0_shell*)pFace)->FUN_009611e0())
                {
                    ::FUN_00a6e8e0((::S_00a6e8e0_Object *)(pFace), (::S_00a6e8e0_Palette *)(pkManager));
                    ((NodeFace*)((FUN_009611e0_shell*)pFace)->FUN_009611e0())->InsertChild(pFace);
                }
            }
            reinterpret_cast<::TESNPC *>((((NPCFace*)this)))->ResetFaceGen();
            if (FUN_005d9f90((char*)apActor))
                reinterpret_cast<::HeadNPC *>((((NPCFace*)this)))->FUN_00606820((::TESObjectREFR *)(apActor), (::NiPointer< ::BipedAnim> *)(FUN_005d9f90((char*)apActor)));
            if (((ActorFace*)apActor)->GetHeadRootNode(false) && ((ActorFace*)apActor)->GetFaceRootNode(false))
            {
                FUN_005dd590 kData;
                reinterpret_cast<::RaceAppearance::Race *>((((FUN_006141f0_shell*)((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())))))->BuildAppearance((::RaceAppearance::NPC *)(::TESActorBase *)(this), (::RaceAppearance::Output *)(void *)(&kData), (*(int *)&(const ::SEX &)(MALE)), false);
                ::fnv_00655fa0::ApplyFaceGenTextures((::fnv_00655fa0::NiAVObject *)(::NiNode *)(((ActorFace*)apActor)->GetHeadRootNode(false)), (::fnv_00655fa0::FaceGenData *)(void *)(&kData));
                ::fnv_00655fa0::ApplyFaceGenTextures((::fnv_00655fa0::NiAVObject *)(::NiNode *)(((ActorFace*)apActor)->GetFaceRootNode(false)), (::fnv_00655fa0::FaceGenData *)(void *)(&kData));
            }
        }
        else
        {
            NiNode* pParent = 0;
            reinterpret_cast<::TESNPC *>((((NPCFace*)this)))->ResetFaceGen();
            bool bWasFirstPerson = ((FUN_004eaf60_shell*)::_g_thePlayer)->FUN_004eaf60();
            reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>((((PlayerFace*)::_g_thePlayer)))->FUN_00950110(false);
            if (pNode && bPrevHadRace != bNowHasRace)
            {
                pParent = (NiNode*)((FUN_009611e0_shell*)((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apActor))->FUN_0043fcd0())))->FUN_009611e0();
                reinterpret_cast<::Ref3 *>((((FaceRefr*)apActor)))->FUN_005702e0((::Obj3 *)(::NiNode *)(0), true);
            }
            if (bNowHasRace)
                ((NPCModelView*)this)->kModel.SetModelFilePath(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d2b38))->GetMenuTitle())));
            else if (reinterpret_cast<::TESActorBase *>(this)->GetSex() == FEMALE)
                ((NPCModelView*)this)->kModel.SetModelFilePath(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d2718))->GetMenuTitle())));
            else
                ((NPCModelView*)this)->kModel.SetModelFilePath(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d3e44))->GetMenuTitle())));
            if (pParent)
            {
                DAT_011c5cb4 = true;
                NiNode* pNew3D = ((::NiNode *)(reinterpret_cast<::Self9 *>((((FaceRefr*)apActor)))->FUN_0087e060(false)));
                if (!((ActorFace*)apActor)->GetFaceRootNode(false) && !((ActorFace*)apActor)->GetHeadRootNode(false))
                {
                    TESNPC* m_pActorBaseFormItem = (TESNPC*)reinterpret_cast<::Actor *>((((ActorView*)apActor)))->GetActorBase();
                    QHeadLocal kHead(m_pActorBaseFormItem, 0);
                    reinterpret_cast<::fnv_0043ecb0::FUN_0043ecb0_shell *>(&(kHead))->FUN_0043ecb0();
                    ((FUN_0043c610_shell*)&kHead)->RunVirtualMethod28();
                    reinterpret_cast<::fnv_0043ed90::AttachTask *>(&(kHead))->FUN_0043ed90((::fnv_0043ed90::RefActor *)(apActor), FUN_005d9f90((char*)apActor));
                }
                pParent->AttachChildInAvailableSlot(pNew3D, true);
                DAT_011c5cb4 = false;
                if (apActor == ::_g_thePlayer)
                    reinterpret_cast<::FUN_0094eaf0_Class *>((((PlayerFace*)::_g_thePlayer)))->FUN_0094eaf0((::Vt9c *)(pNew3D), false);
                ((ActorFace*)apActor)->UpdateHead();
                MiddleHighProcess* pProcess = dynamic_cast<MiddleHighProcess*>(((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture())));
                if (pProcess)
                    pProcess->ApplyProcessLevelChange(apActor);
            }
            reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>((((PlayerFace*)::_g_thePlayer)))->FUN_00950110(!bWasFirstPerson);
        }
    }
}

struct ElemT;
struct ObjX;
struct NiTimeController
{
    virtual void z00();
    virtual void z01();
    virtual void z02();
    virtual void z03();
    virtual void z04();
    virtual void z05();
    virtual void z06();
    virtual void z07();
    virtual void z08();
    virtual void z09();
    virtual void z10();
    virtual void z11();
    virtual void z12();
    virtual void z13();
    virtual void z14();
    virtual void z15();
    virtual void z16();
    virtual void z17();
    virtual void z18();
    virtual void z19();
    virtual void z20();
    virtual void z21();
    virtual void z22();
    virtual void z23();
    virtual void z24();
    virtual void z25();
    virtual void z26();
    virtual void z27();
    virtual void z28();
    virtual void z29();
    virtual void z30();
    virtual void z31();
    virtual void z32();
    virtual void z33();
    virtual void z34();
    virtual void z35();
    virtual void z36();
    virtual void z37();
    virtual void z38();
    virtual void z39();
    virtual void z40();
    virtual void z41();
    virtual void z42();
    virtual void z43();
    virtual void z44();
    virtual void z45();
    virtual void z46();
    virtual void z47();
    virtual void z48();
    virtual void z49();
    virtual void z50();
    virtual void z51();
    virtual void z52();
    virtual void z53();
    virtual void z54();
    virtual void z55();
    virtual void z56();
    virtual void z57();
    virtual void z58();
    virtual void z59();
    virtual void z60();
    virtual void z61();
    virtual void z62();
    virtual void v63(int, void*);
};
struct NiFixedString
{
    NiFixedString(const char*);
    ~NiFixedString();
    operator const char*() const;
    int f0;
};
struct ElemRet;
struct ListT
{
    virtual void y00();
    virtual void y01();
    virtual void y02();
    virtual void y03();
    virtual void y04();
    virtual void y05();
    virtual void y06();
    virtual void y07();
    virtual void y08();
    virtual void y09();
    virtual void y10();
    virtual void y11();
    virtual void y12();
    virtual void y13();
    virtual void y14();
    virtual void y15();
    virtual void y16();
    virtual void y17();
    virtual void y18();
    virtual void y19();
    virtual void y20();
    virtual void y21();
    virtual void y22();
    virtual void y23();
    virtual void y24();
    virtual void y25();
    virtual void y26();
    virtual void y27();
    virtual void y28();
    virtual void y29();
    virtual void y30();
    virtual void y31();
    virtual void y32();
    virtual void y33();
    virtual void y34();
    virtual void y35();
    virtual void y36();
    virtual void y37();
    virtual void y38();
    virtual ElemT* v39(const NiFixedString&);
    unsigned int FUN_0043b480();
};
struct PartT;
struct ElemT
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual PartT* v7();
};
struct NiObjectNET
{
};
struct FUN_00633c90
{
    FUN_00633c90(int);
    ~FUN_00633c90();
    void FUN_0066b0d0(PartT*);
    int f0;
};
struct FUN_004037b0
{
    FUN_004037b0();
    ~FUN_004037b0();
    int f0;
    int f4;
};
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a6aa40 : NiMemObject
{
    FUN_00a6aa40();
    void FUN_004f3200(int);
    void FUN_0060aeb0(int);
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
};
struct MgrT
{
};
extern char DAT_0104aac0;
extern char DAT_0104aab0;
extern char DAT_0104aa80;
extern char DAT_0104a64c;
struct ParamSub
{
};
struct ParamT
{
    char pad24[0x24];
    ParamSub sub;
};
struct ThisT
{
    char pad1c4[0x1c4];
    FUN_00633c90 holder;
    void FUN_0060a950(ParamT*);
};
// @fnv 0x0060a950
void ThisT::FUN_0060a950(ParamT* param)
{
    FUN_00633c90 a(0);
    FUN_00633c90 eye(0);
    ElemT* cur;
    if (((::ListT *)(::FUN_00559450((int *)&(holder)))))
    {
        long count;
        count = ((::ListT *)(::FUN_00559450((int *)&(holder))))->FUN_0043b480();
        unsigned int ptr;
        for (ptr = 0; ptr < count; ptr++)
        {
            cur = ((::ElemT *)(reinterpret_cast<::NiNode *>((((::ListT *)(::FUN_00559450((int *)&(holder))))))->GetAt(ptr)));
            if (FUN_00408b20((const char*)(*(::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((cur))->GetLinkToList())), &DAT_0104aac0) == 0)
                a.FUN_0066b0d0(cur->v7());
            if (FUN_00408b20((const char*)(*(::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((cur))->GetLinkToList())), &DAT_0104aab0) == 0)
                eye.FUN_0066b0d0(cur->v7());
        }
        if (((::ListT *)(::FUN_00559450((int *)&(a)))) && ((::ListT *)(::FUN_00559450((int *)&(eye)))))
        {
            FUN_004037b0 p40;
            if (param)
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&p40), &DAT_0104a64c, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(param->sub))->FUN_00408da0())));
            else
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&p40), &DAT_0104aa80);
            FUN_00633c90 c(0);
            reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::MgrT * *>(&::g_TES))))->FUN_004568c0((const char *)(void *)(((void *)(::FUN_00559450((int *)&(p40))))), (*(::TexPtr< ::NiSourceTexture> *)(&c)), 0, 0);
            if (((::ListT *)(::FUN_00559450((int *)&(c)))))
            {
                NiObjectNET* x;
                x = ((::NiObjectNET *)(reinterpret_cast<::FUN_0050d100_shell *>((((::ListT *)(::FUN_00559450((int *)&(a))))))->FUN_0050d100()));
                NiObjectNET* x2;
                x2 = ((::NiObjectNET *)(reinterpret_cast<::FUN_0050d100_shell *>((((::ListT *)(::FUN_00559450((int *)&(eye))))))->FUN_0050d100()));
                if (x && x2)
                {
                    NiTimeController* b3;
                    b3 = ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(x))));
                    (!b3 ? 0 : ((int)reinterpret_cast<::BGSTerrainManager *>((b3))->GetMinLevel() >= 8 && (int)reinterpret_cast<::BGSTerrainManager *>((b3))->GetMinLevel() <= 12));
                    NiTimeController* nw;
                    nw = (!b3 ? 0 : ((int)reinterpret_cast<::BGSTerrainManager *>((b3))->GetMinLevel() >= 8 && (int)reinterpret_cast<::BGSTerrainManager *>((b3))->GetMinLevel() <= 12)) ? b3 : 0;
                    NiTimeController* m40;
                    m40 = ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(x2))));
                    NiTimeController* found;
                    found = (!m40 ? 0 : ((int)reinterpret_cast<::BGSTerrainManager *>((m40))->GetMinLevel() >= 8 && (int)reinterpret_cast<::BGSTerrainManager *>((m40))->GetMinLevel() <= 12)) ? m40 : 0;
                    if (nw && found)
                    {
                        nw->v63(0, ((::ListT *)(::FUN_00559450((int *)&(c)))));
                        found->v63(0, ((::ListT *)(::FUN_00559450((int *)&(c)))));
                        return;
                    }
                }
                FUN_00a6aa40* p44;
                p44 = new FUN_00a6aa40;
                reinterpret_cast<::FUN_005b8fc0_shell *>((p44))->FUN_005b8fc0((::NiNode *)(void *)(((::ListT *)(::FUN_00559450((int *)&(c))))));
                p44->FUN_004f3200(3);
                p44->FUN_0060aeb0(2);
                if (((int)(reinterpret_cast<::FUN_00a59d30_C *>((((::ListT *)(::FUN_00559450((int *)&(a))))))->FUN_00a59d30(5))))
                    reinterpret_cast<::ExtraOwnerB *>((((::ListT *)(::FUN_00559450((int *)&(a))))))->FUN_00a5b230(5);
                reinterpret_cast<::FUN_00439410_cls *>((((::ListT *)(::FUN_00559450((int *)&(a))))))->FUN_00439410((::ArgObject *)(p44));
                if (((int)(reinterpret_cast<::FUN_00a59d30_C *>((((::ListT *)(::FUN_00559450((int *)&(eye))))))->FUN_00a59d30(5))))
                    reinterpret_cast<::ExtraOwnerB *>((((::ListT *)(::FUN_00559450((int *)&(eye))))))->FUN_00a5b230(5);
                reinterpret_cast<::FUN_00439410_cls *>((((::ListT *)(::FUN_00559450((int *)&(eye))))))->FUN_00439410((::ArgObject *)(p44));
            }
        }
        cur = ((::ListT *)(::FUN_00559450((int *)&(holder))))->v39(NiFixedString(&DAT_0104aac0));
        if (cur)
            ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(cur), 0, 0);
        cur = ((::ListT *)(::FUN_00559450((int *)&(holder))))->v39(NiFixedString(&DAT_0104aab0));
        if (cur)
            ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(cur), 0, 0);
    }
}
