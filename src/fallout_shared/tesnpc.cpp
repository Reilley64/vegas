// fallout_shared/tesnpc.cpp: TESNPC, ActorValue, TESActorBaseData, FR2MatrixVTCData and more (114 functions)

#include <cstdint>
#include <new>
#include <cstdlib>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/ActorBaseInitItemView.h"
#include "fnv/decl/ActorBaseSaveView.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorSpellView.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/ArmorContainer.h"
#include "fnv/decl/B441420Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BGSDehydrationStage.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BipedAnimWeap.h"
#include "fnv/decl/BipedLoadAccess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0041c930_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041cb70_shell.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_0042ce90_class.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0043f220_cls.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004440d0_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00461560_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0047bd70_shell.h"
#include "fnv/decl/FUN_0047bdd0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047cac0_t.h"
#include "fnv/decl/FUN_0047ccc0_shell.h"
#include "fnv/decl/FUN_0047cd40_shell.h"
#include "fnv/decl/FUN_0047cd90_shell.h"
#include "fnv/decl/FUN_0047cdd0_shell.h"
#include "fnv/decl/FUN_0047d370_shell.h"
#include "fnv/decl/FUN_0047d390_shell.h"
#include "fnv/decl/FUN_0047d3b0_shell.h"
#include "fnv/decl/FUN_0047d3d0_shell.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_0047dd30_shell.h"
#include "fnv/decl/FUN_0047ded0_shell.h"
#include "fnv/decl/FUN_0047f4c0_shell.h"
#include "fnv/decl/FUN_0047fb50_shell.h"
#include "fnv/decl/FUN_00480000_shell.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_004811e0_shell.h"
#include "fnv/decl/FUN_00482910_cls.h"
#include "fnv/decl/FUN_00485e00_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004870f0_shell.h"
#include "fnv/decl/FUN_00487240_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_0048b830_Class.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004adda0_shell.h"
#include "fnv/decl/FUN_004bfe50_t.h"
#include "fnv/decl/FUN_004c8220_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f32e0_class.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00503240_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0050eaa0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/FUN_005ca4f0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f1f30_shell.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FUN_006053f0_class.h"
#include "fnv/decl/FUN_0060bb40_class.h"
#include "fnv/decl/FUN_0060bd90_cls.h"
#include "fnv/decl/FUN_00613870_Class.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_00634890_shell.h"
#include "fnv/decl/FUN_00649680.h"
#include "fnv/decl/FUN_0064df10_helper.h"
#include "fnv/decl/FUN_0065f2b0_class.h"
#include "fnv/decl/FUN_00662820_shell.h"
#include "fnv/decl/FUN_006727b0_shell.h"
#include "fnv/decl/FUN_00693d50_shell.h"
#include "fnv/decl/FUN_00729970_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00894d60_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009442e0_class.h"
#include "fnv/decl/FUN_00944300_class.h"
#include "fnv/decl/FUN_00950b30_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009962f0_s.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00c748d0_C.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/Header47cb90.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/ModelCopyView.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S47.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TABStub.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESSpellListShell.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Thing575.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk_0097fa10.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/V_006578b0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_Dummy_0044a170.h"
#include "fnv/decl/_FUN_0052aa80_shell.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047ca20__FUN_0047ca20_shell.h"
#include "fnv/decl/fnv_0047d220__ABD_47d220.h"
#include "fnv/decl/fnv_0047de40__TABStub.h"
#include "fnv/decl/fnv_0047de70__TABStub.h"
#include "fnv/decl/fnv_0047dfe0__TABStub.h"
#include "fnv/decl/fnv_0047e010__TABStub.h"
#include "fnv/decl/fnv_0047e1c0__S47b.h"
#include "fnv/decl/fnv_0047e270__FUN_0047e270_shell.h"
#include "fnv/decl/fnv_0047f500__FUN_0047f500_shell.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048cce0__FUN_0048cce0_shell.h"
#include "fnv/decl/fnv_0048d290__FUN_0048d290_shell.h"
#include "fnv/decl/fnv_0048d630__SpellListAccess.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_0057b7c0__Actor57.h"
#include "fnv/decl/fnv_005f18c0__SaveActorBase.h"
#include "fnv/decl/fnv_005f1b30__ActorBaseLoad.h"
#include "fnv/decl/fnv_0060bd20__FUN_0060bd20_class.h"
#include "fnv/decl/fnv_00613c50__FUN_00613c50_C.h"
#include "fnv/decl/fnv_0065f550__FUN_0065f550_Class.h"
#include "fnv/decl/fnv_00672800__Proxy72800.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0088c830__ThisC.h"
#include "fnv/decl/fnv_008a7a90__ActorAnimView.h"
#include "fnv/decl/fnv_008a8e50__ActorP_S.h"
#include "fnv/decl/fnv_008b3c30__FUN_008b3c30_shell.h"
#include "fnv/decl/fnv_008b78c0__FUN_008b78c0_shell.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ea000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00505000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_00603000.h"
#include "fnv/symbols_00604000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_00607000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00754000.h"
#include "fnv/symbols_008f2000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0104a000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "tesnpc_pc_decls.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_005b8fc0_shell.h"
#include "fnv/decl/FUN_0094eaf0_Class.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/RaceAppearance__Race.h"
#include "fnv/decl/Ref3.h"
#include "fnv/decl/Self9.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/fnv_0043ecb0__FUN_0043ecb0_shell.h"
#include "fnv/decl/fnv_0043ed90__AttachTask.h"
#include "fnv/decl/fnv_008bb520__TES.h"
#include "fnv/decl/fnv_00950110__FUN_00950110_pc.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_005d9000.h"
#include "fnv/symbols_00655000.h"
#include "fnv/decl/FUN_0060b370_shell.h"
#include "fnv/symbols_011cc000.h"
#include "tesnpc_pc_decls_decl_tesnpc.h"

// @fnv 0x00601170
TESNPC::TESNPC() : m_pkPrimaryFaceGenNode(0), m_pkSecondaryFaceGenNode(0), m_pkFaceGenTexture(0), undoStates(0, true)
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_NPC__ID)));
    ResetFormData();
    reinterpret_cast<::TESAIForm *>(this)->SetResponsibility(50, false);
    reinterpret_cast<::TESAIForm *>(this)->SetAggression(0, false);
    reinterpret_cast<::TESAIForm *>(this)->SetConfidence(2, false);
    reinterpret_cast<::TESAIForm *>(this)->SetEnergy(50, false);
    m_ulTopicFlags = 0;
}

// @fnv 0x00601750
void TESNPC::ClearData()
{
    if (!reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition())
    {
        m_pkSecondaryFaceGenNode = m_pkPrimaryFaceGenNode = 0;
        m_pkFaceGenTexture = 0;
    }
    m_usLastRace = 255;
    reinterpret_cast<::FileMatchList *>(&(m_kHeadPartList))->RemoveAll();
    delete[] m_pOffsetFaceCoordinates;
    m_pOffsetFaceCoordinates = 0;
}

// @fnv 0x00602190
bool TESNPC::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 42)
        return false;
    m_ulTopicFlags = reinterpret_cast<::TESFile *>((static_cast<TESNPCFileAccess*>(file)))->GetOffset();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    bool validRecord;
    bool bTextureWarning = false;
    while (int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        bool chunkAdvanced;
        {
            struct FaceCoordReadCursor
            {
                int column, row;
                float* values;
            } cursor;
            cursor.row = -1;
            cursor.column = -1;
            validRecord = true;
            chunkAdvanced = false;
            switch (chunk)
            {
            case 'DIDE': {
                char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
                SetEditorID_AtRuntime(editorID);
                break;
            }
            case 'DNBO':
                readOBNDSubRecord(file);
                break;
            case 'LLUF':
                ::ReadFullName(static_cast<TESFullName*>(this), file);
                break;
            case 'LDOM':
            case 'TDOM':
                TESModel::LoadModelData(static_cast<TESModel*>(this), file);
                break;
            case 'IRCS': {
                unsigned int scriptID = 0;
                file->GetChunkData(&scriptID);
                reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(scriptID));
                TESScriptableForm::InitItem(this);
                break;
            }
            case 'OTNC':
            case 'DEOC':
                switch (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
                {
                case 'OTNC': {
                    ContainerItem item;
                    memset(&item, 0, 8);
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&item), 8);
                    if (file->IsEndianConversionRequired())
                        reinterpret_cast<::S_00462230 *>(&(item))->FUN_00462230();
                    DAT_011cb7d8 = reinterpret_cast<::fnv_004817f0::FUN_004817f0_shell *>(this)->AddContainerObject((::fnv_004817f0::ContainerChanges *)(::ContainerItem *)(&item));
                    break;
                }
                case 'DEOC':
                    if (DAT_011cb7d8)
                    {
                        DAT_011cb7d8->pExtra = new ContainerItemExtra;
                        DAT_011cb7d8->pExtra->Load(file);
                        DAT_011cb7d8 = 0;
                    }
                    break;
                }
                break;
            case 'OLPS': {
                unsigned int spell = 0;
                file->GetChunkData(&spell);
                reinterpret_cast<::fnv_0048d290::FUN_0048d290_shell *>(this)->FUN_0048d290((::TESForm *)(std::uintptr_t)(spell));
                break;
            }
            case 'MTIE': {
                unsigned int spell = 0;
                file->GetChunkData(&spell);
                reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(spell));
                break;
            }
            case 'TMAE': {
                unsigned short value = 0;
                reinterpret_cast<::FUN_00472840_impl *>((static_cast<TESFileChunkData16*>(file)))->ReadChunkData(&value);
                reinterpret_cast<::TESEnchantableForm *>(this)->SetFormEnchantmentAmount(value);
                break;
            }
            case 'TDIA': {
                PackedRecordData ai;
                memset(&ai, 0, 20);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&ai), 20);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_00503240_shell *>(&(ai))->SwapEndianFields();
                if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(file)))->FUN_00403570() < 4 && ai.m_ucField00 > 1)
                    ++ai.m_ucField00;
                if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(file)))->FUN_00403570() < 6)
                    switch (ai.m_ucField00)
                    {
                    case 0:
                        ai.m_ucField0E = 0;
                        break;
                    case 1:
                        ai.m_ucField00 = 0;
                        ai.m_ucField0E = 1;
                        break;
                    case 2:
                        ai.m_ucField00 = 1;
                        ai.m_ucField0E = 1;
                        break;
                    case 3:
                        ai.m_ucField00 = 1;
                        ai.m_ucField0E = 2;
                        break;
                    case 4:
                        ai.m_ucField00 = 2;
                        ai.m_ucField0E = 2;
                        break;
                    case 5:
                        ai.m_ucField00 = 3;
                        ai.m_ucField0E = 0;
                        break;
                    }
                if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(file)))->FUN_00403570() < 7)
                    ai.m_ucField01 = 4 - ai.m_ucField01;
                reinterpret_cast<::TESAIForm *>(this)->CopyAIDataFromAIDATA(&ai);
                break;
            }
            case 'DIKP': {
                unsigned int package = 0;
                file->GetChunkData(&package);
                reinterpret_cast<::fnv_0047f500::FUN_0047f500_shell *>(this)->FUN_0047f500((::fnv_0047f500::TESPackage *)(std::uintptr_t)(package));
                break;
            }
            case 'MANS': {
                FactionReaction rank;
                memset(&rank, 0, 8);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&rank), 8);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::fnv_00503210::Unk *>(&(rank))->FUN_00503210();
                reinterpret_cast<::FUN_0047d800_shell *>(this)->FUN_0047d800(rank.pFaction, rank.m_ucRank);
                break;
            }
            case 'MANI': {
                unsigned int deathItem = 0;
                file->GetChunkData(&deathItem);
                m_pBaseTemplateForm = reinterpret_cast<TESForm*>(deathItem);
                break;
            }
            case 'KCTV': {
                unsigned int voice;
                file->GetChunkData(&voice);
                m_kFactionList = reinterpret_cast<TESForm*>(voice);
                break;
            }
            case 'TLPT': {
                unsigned int templateID;
                file->GetChunkData(&templateID);
                m_ppTemplateForms = reinterpret_cast<TESForm*>(templateID);
                break;
            }
            case 'SBCA':
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&actorData), 24);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::Header47cb90 *>(&(actorData))->SwapEndianness();
                if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(file)))->FUN_00403570() < 8)
                    actorData.m_usField16 = 0;
                actorData.m_usField06 = 0;
                break;
            case 'MANR': {
                unsigned int race = 0;
                file->GetChunkData(&race);
                reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(race));
                break;
            }
            case 'ZFFK':
                reinterpret_cast<::TESAnimation *>(this)->LoadComponent((::TESForm *)(::TESAnimation *)(static_cast<TESAnimation*>(this)), file);
                break;
            case 'TSED':
            case 'DTSD':
                ::FUN_004781e0(static_cast<BGSDestructibleObjectForm*>(this), file);
                break;
            case 'ATAD': {
                unsigned int added = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() - reinterpret_cast<::FUN_00486620_shell *>(this)->FUN_00486620();
                if (added)
                {
                    if (added != 28 && added * 2 != 28)
                        ::FUN_005b5e40();
                    reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, (unsigned short)added);
                }
                else
                    reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, 0, 0);
                break;
            }
            case 'MAND':
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), 28);
                break;
            case 'SGGF':
                if (cursor.row == -1)
                {
                    cursor.row = 0;
                    cursor.column = 0;
                }
            case 'AGGF':
                if (cursor.row == -1)
                {
                    cursor.row = 0;
                    cursor.column = 1;
                }
            case 'STGF': {
                if (cursor.row == -1)
                {
                    cursor.row = 1;
                    cursor.column = 0;
                }
                struct FaceCoordReadCounts
                {
                    unsigned int floatCount, byteCount;
                } counts;
                counts.byteCount = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
                counts.floatCount = counts.byteCount >> 2;
                m_kFaceGenCoordinates[cursor.row][cursor.column].SetDimensions(counts.floatCount, 1);
                cursor.values = static_cast<float*>(_alloca(counts.byteCount));
                memset(cursor.values, 0, counts.byteCount);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(cursor.values), counts.byteCount);
                for (unsigned int index = 0; index < counts.floatCount; ++index)
                {
                    if (file->IsEndianConversionRequired())
                        ::FUN_00401080((int *)(float *)(&cursor.values[index]));
                    *const_cast<float*>(
                        m_kFaceGenCoordinates[cursor.row][cursor.column].FUN_0060b370(index, 0).FUN_00629ab0()) =
                        cursor.values[index];
                }
                break;
            }
            case 'MANP': {
                struct FormResolution
                {
                    unsigned int formID;
                    BGSHeadPart* part;
                } resolved;
                file->GetChunkData(&resolved.formID);
                ::ResolveFormID((unsigned int *)&(resolved.formID), file);
                resolved.part = dynamic_cast<BGSHeadPart*>(::FUN_004839c0(resolved.formID));
                if (resolved.part)
                    FUN_00602170()->AddHead(resolved.part);
                else
                    ::FUN_005b5e40();
                break;
            }
            case 'MANH': {
                struct FormResolution
                {
                    unsigned int formID;
                    TESHair* hair;
                } resolved;
                file->GetChunkData(&resolved.formID);
                ::ResolveFormID((unsigned int *)&(resolved.formID), file);
                resolved.hair = dynamic_cast<TESHair*>(::FUN_004839c0(resolved.formID));
                if (resolved.hair)
                    SetHair(resolved.hair);
                else
                    ::FUN_005b5e40();
                break;
            }
            case 'MANL': {
                float length;
                file->GetChunkData(reinterpret_cast<unsigned int*>(&length));
                if (length < 0.0)
                    length = 0.0f;
                if (length > 1.0)
                    length = 1.0f;
                FUN_00601c10(length);
                break;
            }
            case 'MANE': {
                struct FormResolution
                {
                    unsigned int formID;
                    TESEyes* eyes;
                } resolved;
                file->GetChunkData(&resolved.formID);
                ::ResolveFormID((unsigned int *)&(resolved.formID), file);
                resolved.eyes = dynamic_cast<TESEyes*>(::FUN_004839c0(resolved.formID));
                if (resolved.eyes)
                    SetEyes(resolved.eyes);
                else
                    ::FUN_005b5e40();
                break;
            }
            case 'RLCH':
            case '9MAN':
                file->GetChunkData(&iHairColor);
                break;
            case 'MANC': {
                unsigned int classID = 0;
                file->GetChunkData(&classID);
                m_pClass = reinterpret_cast<TESClass*>(classID);
                break;
            }
            case 'MANZ': {
                unsigned int combatStyle;
                file->GetChunkData(&combatStyle);
                SetCombatStyle(reinterpret_cast<TESCombatStyle*>(combatStyle));
                break;
            }
            case 'MANF':
                if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() >= 2)
                {
                    reinterpret_cast<::FUN_00472840_impl *>((static_cast<TESFileChunkData16*>(file)))->ReadChunkData(&m_usLastRace);
                    if (file->IsEndianConversionRequired())
                        ::FUN_00407a90((short *)(unsigned short *)(&m_usLastRace));
                }
                break;
            case '0MAN':
            case '1MAN':
            case '2MAN':
            case '3MAN':
                if (!bTextureWarning)
                {
                    ::FUN_005b5e40();
                    bTextureWarning = true;
                }
                break;
            case '4MAN': {
                unsigned int race;
                file->GetChunkData(&race);
                m_eImpactMaterial = (int)race;
                break;
            }
            case '6MAN':
                file->GetChunkData(reinterpret_cast<unsigned int*>(&m_fGlyphExtent));
                break;
            case '7MAN':
                file->GetChunkData(reinterpret_cast<unsigned int*>(&fWeight));
                break;
            default:
                break;
            }
            if (!validRecord)
                break;
            if (!chunkAdvanced && !file->NextChunk())
                break;
        }
    }
    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) == 7 && ::_g_thePlayer && !((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430())))
        reinterpret_cast<::Fn575690 *>((::_g_thePlayer))->FUN_00575690(this);
    if (!::GetShortAtOffset12((const char *)this))
        ::FUN_005b5e40();
    return true;
}

// @fnv 0x00603370
void TESNPC::InitItem()
{
    unsigned int classID, combatID;
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    if (TESActorBaseData::GetFlag(4))
    {
        TESNPC* npc = this;
        (*reinterpret_cast<::BSSimpleList< ::TESNPC *> *>(&::g_011cb764)).AddHead(npc);
    }
    TESScriptableForm::InitItem(this);
    TESContainer::InitItem(this);
    reinterpret_cast<::FUN_0047f4c0_shell *>(this)->FUN_0047f4c0(this);
    TESRaceForm::InitItem(this);
    reinterpret_cast<::ActorBaseInitItemView *>(this)->FUN_0047d8b0(this);
    TESSpellList::InitItem(this);
    BGSTouchSpellForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    if (m_pClass)
    {
        classID = reinterpret_cast<unsigned int>(m_pClass);
        ::ResolveFormID((unsigned int *)&(classID), GetFile(-1));
        m_pClass = dynamic_cast<TESClass*>(::FUN_004839c0(classID));
    }
    if (vfn_144())
        UpdateActorBaseData(false);
    if (m_pCombatStyle)
    {
        combatID = reinterpret_cast<unsigned int>(GetCombatStyle());
        if (combatID)
        {
            ::ResolveFormID((unsigned int *)&(combatID), GetFile(-1));
            m_pCombatStyle = dynamic_cast<TESCombatStyle*>(::FUN_004839c0(combatID));
            if (!m_pCombatStyle)
                ::FUN_005b5e40();
        }
    }
    if (!GetCombatStyle())
        SetCombatStyle(((::TESCombatStyle *)(::FUN_00505000())));
    if (((unsigned int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) <= 0)
        reinterpret_cast<::FUN_00565210_shell *>(this)->FUN_00565210(true);
    if (m_fGlyphExtent == 0.0)
        m_fGlyphExtent = GetDefaultHeight();
    SetInitializationState(true);
}

// @fnv 0x006035e0
void TESNPC::Copy(TESForm* form)
{
    if (form->GetFormType() != ENUM_FORM_ID_NPC__ID)
        return;
    TESNPC* npc = static_cast<TESNPC*>(form);
    TESAIForm::BaseFormRecord(form);
    reinterpret_cast<::fnv_0048d630::SpellListAccess *>(this)->FUN_0048d630(form);
    reinterpret_cast<::FUN_0047bdd0_shell *>(this)->FUN_0047bdd0(form);
    TESRaceForm::BaseFormRecord(form);
    reinterpret_cast<::fnv_0047d220::ABD_47d220 *>(this)->CopyFromActorBaseData(form);
    reinterpret_cast<::FUN_00487240_shell *>(this)->CopyHealthForm(form);
    reinterpret_cast<::FUN_00480000_shell *>(this)->CopyAttributesFromComponent(form);
    reinterpret_cast<::FUN_004870f0_shell *>(this)->CopyFullNameFrom(form);
    reinterpret_cast<::ModelCopyView *>(this)->FUN_00489430(form);
    reinterpret_cast<::fnv_0048cce0::FUN_0048cce0_shell *>(this)->CopyFromScriptableForm(form);
    reinterpret_cast<::TESContainer *>(this)->CopyFromBase(form);
    reinterpret_cast<::FUN_0047fb50_shell *>(this)->FUN_0047fb50(form);
    reinterpret_cast<::BGSDestructibleObjectForm *>(this)->FUN_004786e0(form);
    memcpy(&data, ((::ActorSkillData *)(reinterpret_cast<::FUN_00634890_shell *>((npc))->GetTextureManager())), 28);
    m_pClass = ((::TESClass *)(reinterpret_cast<::MiddleHighProcess *>((npc))->GetSceneRoot()));
    SetCombatStyle(npc->GetCombatStyle());
    vfn_5c(npc->vfn_58());
    CopyActorBaseData(npc);
    m_fGlyphExtent = npc->m_fGlyphExtent;
    fWeight = npc->fWeight;
}

// Returns the NPC's hair form, using the race's hair for the current sex unless this is the player's object reference.
// @fnv 0x00603b50
TESHair* TESNPC::GetHair()
{
    TESHair* hair = m_pHair;
    if (m_pAssignedRace && this != ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430())))
        hair = ((::TESHair *)(reinterpret_cast<::FUN_00613870_Class *>((((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070()))))->FUN_00613870((*(int *)&(const ::SEX &)(reinterpret_cast<::TESActorBase *>(this)->GetSex())))));
    return hair;
}

// @fnv 0x00603be0
void TESNPC::UpdateActorBaseData(bool menu)
{
    float fValue = 0.0f;
    if (!((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())) || !m_pClass)
        return;
    bool m_bFaceGenDataValid = false;
    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) == 7)
        m_bFaceGenDataValid = true;
    bool bUseDefaults = true;
    if (m_bFaceGenDataValid && ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d0e7c))))))->i == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TESClass *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetSceneRoot()))))->FUN_0084e3a0())))
        bUseDefaults = false;
    if (vfn_144())
    {
        int iLevel;
        {
            unsigned char luck;
            {
                struct SkillInitializationBudget
                {
                    float fPointsPerSkill;
                    int iSkillPoints;
                    int iRemainingTagSkills;
                    float overflow;
                } budget;
                for (int iIndex = 0; iIndex < 7; ++iIndex)
                {
                    ActorValue::Index eAttribute =
                        ::ActorValue::GetActorValueForSectionIndex(ActorValue::Attributes, (unsigned char)iIndex);
                    if (bUseDefaults)
                        fValue = reinterpret_cast<::FUN_00480160_shell *>(&(((::TESClass *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetSceneRoot()))->classAttributes))->FUN_00480160(iIndex + 5);
                    if (fValue > 10.0)
                        fValue = 10.0f;
                    reinterpret_cast<::Thing *>(this)->SetByte((*(int *)&(eAttribute)), (unsigned char)::FUN_00406d90(fValue), false);
                }
                luck = reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(11);
                budget.iSkillPoints = ::ComputeIntelligenceResult(reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(9), true);
                iLevel = reinterpret_cast<::FUN_0047ded0_shell *>(this)->FUN_0047ded0();
                budget.iSkillPoints = (iLevel - 1) * budget.iSkillPoints;
                budget.iRemainingTagSkills = (menu ? 1 : 0) + 3;
                budget.fPointsPerSkill =
                    ((double)(::FUN_00404040((float)budget.iSkillPoints / budget.iRemainingTagSkills))) * ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cd6c0))))))->i;
                budget.overflow = 0.0f;
                --budget.iRemainingTagSkills;
                for (int iIndex = 0; iIndex < 14; ++iIndex)
                {
                    ActorValue::Index eAttribute =
                        ::ActorValue::GetActorValueForSectionIndex(ActorValue::Skills, (unsigned char)iIndex);
                    if (!::FUN_00406d70((*(int *)&(eAttribute)), 0x2000) && ::FUN_0047f060((*(int *)&(eAttribute))))
                    {
                        fValue = 0.0f;
                        int iAttribute = -1;
                        ::GetSkillAttributeAndBase((*(int *)&(eAttribute)), &iAttribute, &fValue);
                        fValue =
                            AIFormulas::CalculateSkillValue(fValue, (float)attributes[iAttribute - 5], (float)luck);
                        if (bUseDefaults && m_pClass && m_pClass->IsTagSkill(eAttribute))
                        {
                            fValue = fValue + (budget.fPointsPerSkill + budget.overflow +
                                               originalRuntimeFloatSetting327.Float()->f);
                            budget.overflow = 0.0f;
                            if (fValue > 100.0)
                            {
                                budget.overflow = (float)(fValue - 100.0);
                                if (budget.iRemainingTagSkills)
                                    budget.overflow /= budget.iRemainingTagSkills;
                            }
                            --budget.iRemainingTagSkills;
                        }
                        if (fValue > 100.0)
                            fValue = 100.0f;
                        data.skills[iIndex] = (unsigned char)::FUN_00406d90(fValue);
                    }
                }
                if (m_pClass)
                {
                    if (vfn_30())
                        TESAIForm::SetServiceFlags(((unsigned int)(reinterpret_cast<::LowProcess *>((m_pClass))->GetPackageObjectType())), false);
                }
                else
                    TESAIForm::SetServiceFlags(0, false);
                MarkAsModified(0x20c);
            }
        }
    }
}

// @fnv 0x006055f0
BipedAnim* TESNPC::GetBipedAnimationForReference(TESObjectREFR* refr)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESNPC.cpp", 5585);
    BipedAnim* biped = refr->GetBipedAnim();
    if (biped)
        ::FUN_005b5e40();
    else
    {
        biped = new BipedAnim(refr, false);
        refr->SetBipedAnim(biped);
    }
    return biped;
}

// @fnv 0x006061b0
bool TESNPC::InitWornObject(TESObjectREFR* refr, BipedAnim* biped, TESBoundObject* object)
{
    bool bReturnValue = true;
    {
        struct BipedModelSources
        {
            BGSBipedModelList* list;
            TESBipedModelForm* model;
        } models;
        models.model = ::TESBipedModelForm::GetFormAsBipedModel(object);
        if (object->GetFormType() == ENUM_FORM_ID_WEAP_ID)
        {
            TESObjectWEAP* weapon = static_cast<TESObjectWEAP*>(object);
            reinterpret_cast<::BipedAnimWeap *>((biped))->SetWeaponModel(weapon, 0);
        }
        else if (models.model)
            models.model->SetBipedModel(biped, (SEX)((actorData.m_uiActorFlags & 1) != 0), (::BIPED_OBJECT)(-1));
        else
            ::FUN_005b5e40();
        models.list = BGSBipedModelList::GetBipedModelList(object);
        if (models.list && ((::BGSListForm *)(reinterpret_cast<::Callees *>((models.list))->FUN_00726070())))
        {
            BSSimpleList<TESForm*>* node = ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::BGSCameraPath *>((((::BGSListForm *)(reinterpret_cast<::Callees *>((models.list))->FUN_00726070()))))->GetConditions()));
            while (node && !node->IsEmpty())
            {
                TESBoundObject* part = static_cast<TESBoundObject*>((node->m_item));
                models.model = ::TESBipedModelForm::GetFormAsBipedModel(part);
                if (models.model)
                    models.model->SetBipedModel(biped, (SEX)((actorData.m_uiActorFlags & 1) != 0), (::BIPED_OBJECT)(-1));
                node = ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            }
        }
    }
    return bReturnValue;
}

// @fnv 0x00607420
void TESNPC::UpdateActorFaceGen(TESObjectREFR* refr, BipedAnim* biped, BSFaceGenNiNode* head, BSFaceGenNiNode* skinned)
{
    BSFaceGenAnimationData* pAnimationData = 0;
    NiNode* pNode;
    {
        NiAVObject* p3D = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((refr))->FUN_0043fcd0()));
        pNode = 0;
        if (p3D)
            pNode = p3D->IsSceneNode();
    }
    NiNode* pHeadBone = biped->GetBoneNode(BIPED_BONE_HEAD);
    ThreeByThreeMatrix kRotationBasis;
    NiDefaultAVObjectPalette* pObjectPalette = 0;
    if (refr->GetAnimData() && reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((refr->GetAnimData()))->FUN_00496940())
        pObjectPalette =
            reinterpret_cast<NiDefaultAVObjectPalette*>(((::NiControllerManager *)(::fnv_00537bd0::GetStringAtOffset((const char *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((refr->GetAnimData()))->FUN_00496940())))));
    {
        NiDefaultAVObjectPalette* objectPalette = pObjectPalette;
        if (pHeadBone && pNode)
        {
            if (head)
            {
                if (head->GetFaceGenAnimationData() && reinterpret_cast<::HealthReferenceEntry *>((refr))->FUN_00568ad0() <= 0.0)
                {
                    head->GetFaceGenAnimationData()->vfn_d8(true, true);
                    head->GetFaceGenAnimationData()->vfn_d0(true);
                }
                head->vfn_114(true);
                head->vfn_11c(true);
                reinterpret_cast<::FUN_00440460_S *>((head))->FUN_00440460((const ::V3 *)&(::NiPoint3::ZERO));
                reinterpret_cast<::FUN_0043fa80_s *>((head))->FUN_0043fa80(reinterpret_cast<const ThreeByThreeMatrix&>((*reinterpret_cast<unsigned char *>(&::DAT_011a9448))));
                pHeadBone->AttachChildInAvailableSlot(head, true);
                AddObjectToPalette(head, objectPalette);
            }
            if (skinned)
            {
                kRotationBasis = reinterpret_cast<const ThreeByThreeMatrix&>((*reinterpret_cast<unsigned char *>(&::DAT_011a9448)));
                skinned->vfn_114(head == 0);
                skinned->vfn_11c(head == 0);
                reinterpret_cast<::FUN_00440460_S *>((skinned))->FUN_00440460((const ::V3 *)&(::NiPoint3::ZERO));
                pNode->AttachChildInAvailableSlot(skinned, true);
                AddObjectToPalette(skinned, objectPalette);
                skinned->vfn_128(pNode, true);
            }
            pAnimationData = head ? head->GetFaceGenAnimationData() : 0;
            if (!pAnimationData)
                pAnimationData = skinned ? skinned->GetFaceGenAnimationData() : 0;
            if (pAnimationData)
            {
                pAnimationData->vfn_b4(0.0f, true, true, true, true, false);
                if (refr->IsActor())
                {
                    Actor* pActor = static_cast<Actor*>(refr);
                    if (pActor->pFaceGenAnimationData)
                    {
                        struct AnimationSample
                        {
                            float value, time;
                        } sample;
                        float fDuration;
                        ComputeAngleRange(&sample.value, &sample.time);
                        ::fnv_00649f70::ClampMinMaxFromSetting(&sample.value, &fDuration);
                        pActor->pFaceGenAnimationData->FUN_00607830(fDuration);
                        pActor->pFaceGenAnimationData->SetBoneMaxAngle(0, sample.time);
                        FUN_00649fe0(&sample.value, &sample.time);
                        GetEyeAngleLimits(&sample.value, &fDuration);
                        reinterpret_cast<::FUN_00c748d0_C *>((pActor->pFaceGenAnimationData))->SetSlotFloats(0, sample.time, fDuration);
                    }
                }
            }
            m_pkPrimaryFaceGenNode = head;
            m_pkSecondaryFaceGenNode = skinned;
            reinterpret_cast<::FUN_00a5a040_Class *>((pNode))->FUN_00a5a040();
            NiUpdateData kUpdateData(0.0f, 0, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((pNode))->FUN_00a59c60((std::intptr_t)&(kUpdateData));
        }
        else
            ::FUN_005b5e40();
    }
    AttachHeadParts(refr, 0);
}

// @fnv 0x00607950
TESCombatStyle* TESNPC::GetCombatStyle()
{
    return m_pCombatStyle;
}

// @fnv 0x00607970
void TESNPC::SetCombatStyle(TESCombatStyle* style)
{
    m_pCombatStyle = style;
}

// @fnv 0x006099f0
void TESNPC::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESNPC *>(this)->Revert(buffer);
    unsigned char modified = 0;
    bool keepHeight = false;
    if (m_fGlyphExtent == GetDefaultHeight())
        keepHeight = true;
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x2000000)))->FUN_004280f0(0x2000000) && !reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x2000000)))->FUN_004280f0(0x2000000) && m_pAssignedRace)
    {
        reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(m_pAssignedRace));
        m_pAssignedRace = 0;
        modified |= 0x1b;
    }
    if (keepHeight)
        m_fGlyphExtent = GetDefaultHeight();
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x800)))->FUN_004280f0(0x800) && !reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x800)))->FUN_004280f0(0x800))
    {
        delete[] m_pOffsetFaceCoordinates;
        m_pOffsetFaceCoordinates = 0;
        modified |= 8;
        reinterpret_cast<::FileMatchList *>(&(m_kHeadPartList))->RemoveAll();
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x1000000)))->FUN_004280f0(0x1000000) && !reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x1000000)))->FUN_004280f0(0x1000000))
    {
        reinterpret_cast<::FlagSet *>(this)->FUN_0047dd50(1, !TESActorBaseData::GetFlag(1), true);
        modified |= 0x1b;
    }
    if (modified & 8)
        ResetFaceGen();
    if (modified)
        reinterpret_cast<::TESActorBase *>(this)->FUN_005f20a0(modified);
}

struct FUN_004169d0_shell : public TESNPC
{
    std::uintptr_t FUN_004169d0();
};

// @fnv 0x004169d0
std::uintptr_t FUN_004169d0_shell::FUN_004169d0()
{
    return this->iHairColor;
}

struct FUN_004a0c90_shell : public ThreeByThreeMatrix
{
    void FUN_004a0c90(float);
};


// Computes the sine and cosine of the angle and writes a 3x3 rotation matrix about Z into the object's fields.
// @fnv 0x004a0c90
void FUN_004a0c90_shell::FUN_004a0c90(float afAngle)
{
    float fSin, fCos;
    FUN_004169a0(afAngle, fSin, fCos);

    *(float*)((char*)this + 0x00) = fCos;
    this->m[0][1] = fSin;
    this->m[0][2] = 0.0f;

    this->m[1][0] = -fSin;
    this->m[1][1] = fCos;
    this->m[1][2] = 0.0f;

    this->m[2][0] = 0.0f;
    this->m[2][1] = 0.0f;
    this->m[2][2] = 1.0f;
}

struct FUN_00601570_shell : public TESNPC
{
    void ResetCharacterData();
};

struct Calendar_DaysPassed_Helper : public Calendar
{
};

struct FUN_00601800_shell : public TESNPC
{
    void* FUN_00601800();
};
// Fills coords with the mean face coordinates for the NPC's race and sex, or with the default face coordinates when no race is set.
// @fnv 0x00603ad0
void TESNPC::GetFaceGenCoords(FaceGenMatrix<float> (&coords)[2][2])
{
    ::BSFaceGenManager::InitializeFaceGenCoordinates((::FaceGenCoordinates *)(coords));
    if (!((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())))
        ::fnv_006529a0::FUN_006529a0(
            (FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(reinterpret_cast<FaceGenMatrix<float>(*)[2]>(BSFaceGenManager::GetFaceGenCoordinates())), (FaceGenCoordArray (*)[2])(coords), 0, 0);
    else
        ::FUN_00652af0((CoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::S9fb0 *>((((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070()))))->FUN_005d9fb0((*(int *)&(const ::SEX &)(reinterpret_cast<::TESActorBase *>(this)->GetSex())))))), (CoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::FUN_00601800_shell *>(this)->FUN_00601800()))),
                                                  (CoordArray (*)[2])(coords), false, 0.0f);
}

// Returns the pointer stored at offset 0x1b4 if non-null, otherwise returns this plus 0x134.
// @fnv 0x00601800
void* FUN_00601800_shell::FUN_00601800()
{
    if (*(void**)&this->m_pOffsetFaceCoordinates)
    {
        return *(void**)&this->m_pOffsetFaceCoordinates;
    }
    else
    {
        return (char*)&this->m_kFaceGenCoordinates;
    }
}

struct FUN_00601c10_shell : public TESNPC
{
    void FUN_00601c10(float);
};

// @fnv 0x00601c10
void FUN_00601c10_shell::FUN_00601c10(float afHairLength)
{
    this->m_fHairLength = afHairLength;
}

struct FUN_00602130_shell : public TESNPC
{
    float FUN_00602130();
};

// @fnv 0x00602130
float FUN_00602130_shell::FUN_00602130()
{
    return this->m_fHairLength;
}

struct FUN_00602170_shell : public TESNPC
{
    void* FUN_00602170();
};
// @fnv 0x00603790
void TESNPC::CopyActorBaseData(TESNPC* source)
{
    reinterpret_cast<::FileMatchList *>((((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>(this)->FUN_00602170()))))->RemoveAll();
    m_pHair = source->GetHair();
    m_fHairLength = reinterpret_cast<::FUN_00602130_shell *>((source))->FUN_00602130();
    m_pEyes = ((::TESEyes *)(reinterpret_cast<::MiddleHighProcess *>((source))->GetAnimation()));
    iHairColor = reinterpret_cast<::FUN_004169d0_shell *>((source))->FUN_004169d0();
    BSSimpleList<BGSHeadPart*>* node = ((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>((source))->FUN_00602170()));
    while (node && !node->IsEmpty())
    {
        reinterpret_cast<::Callees *>((((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>(this)->FUN_00602170()))))->FUN_00905820((void *)&((node->m_item)));
        node = ((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::FUN_00601800_shell *>((source))->FUN_00601800()))), (FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::FUN_00601800_shell *>(this)->FUN_00601800()))), 0, 0);
    if (!::_g_thePlayer || this != ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430())))
        SetField1F0(source);
}

// @fnv 0x00602170
void* FUN_00602170_shell::FUN_00602170()
{
    return reinterpret_cast<char*>(&this->m_kHeadPartList);
}

struct FUN_006031e0_shell : public TESNPC
{
    void SetHair(TESHair*);
};

// @fnv 0x006031e0
void FUN_006031e0_shell::SetHair(TESHair* apHair)
{
    this->m_pHair = apHair;
}

struct FUN_00603200_shell : public TESNPC
{
    void SetEyes(TESEyes*);
};

// @fnv 0x00603200
void FUN_00603200_shell::SetEyes(TESEyes* apEyes)
{
    this->m_pEyes = apEyes;
}

struct FUN_006035e0_shell : public TESNPC
{
    void CopyFromNPC(TESForm*);
};

// Copies an NPC form's components and fields into this actor base after checking the form type is 0x2a.
// @fnv 0x006035e0
void FUN_006035e0_shell::CopyFromNPC(TESForm* apCopy)
{
    if (apCopy->GetFormType() != 0x2a)
        return;

    TESNPC* npc = (TESNPC*)apCopy;

    TESAIForm::BaseFormRecord((BaseFormComponent*)apCopy);
    reinterpret_cast<::fnv_0048d630::SpellListAccess *>(this)->FUN_0048d630((BaseFormComponent*)apCopy);
    reinterpret_cast<::FUN_0047bdd0_shell *>(this)->FUN_0047bdd0((BaseFormComponent*)apCopy);
    TESRaceForm::BaseFormRecord((BaseFormComponent*)apCopy);
    reinterpret_cast<::fnv_0047d220::ABD_47d220 *>(this)->CopyFromActorBaseData((BaseFormComponent*)apCopy);
    reinterpret_cast<::FUN_00487240_shell *>(this)->CopyHealthForm((BaseFormComponent*)apCopy);
    reinterpret_cast<::FUN_00480000_shell *>(this)->CopyAttributesFromComponent((BaseFormComponent*)apCopy);
    reinterpret_cast<::FUN_004870f0_shell *>(this)->CopyFullNameFrom((BaseFormComponent*)apCopy);
    reinterpret_cast<::ModelCopyView *>(this)->FUN_00489430((BaseFormComponent*)apCopy);
    reinterpret_cast<::fnv_0048cce0::FUN_0048cce0_shell *>(this)->CopyFromScriptableForm((BaseFormComponent*)apCopy);
    reinterpret_cast<::TESContainer *>(this)->CopyFromBase((BaseFormComponent*)apCopy);
    reinterpret_cast<::FUN_0047fb50_shell *>(this)->FUN_0047fb50((BaseFormComponent*)apCopy);
    reinterpret_cast<::BGSDestructibleObjectForm *>(this)->FUN_004786e0((BaseFormComponent*)apCopy);

    memcpy(&data, ((::ActorSkillData *)(reinterpret_cast<::FUN_00634890_shell *>((npc))->GetTextureManager())), sizeof(ActorSkillData));
    m_pClass = ((::TESClass *)(reinterpret_cast<::MiddleHighProcess *>((npc))->GetSceneRoot()));
    ((TESActorBase*)this)->SetCombatStyle(((TESActorBase*)npc)->GetCombatStyle());
    vfn_5c(npc->vfn_58());
    CopyActorBaseData(npc);
    m_fGlyphExtent = npc->m_fGlyphExtent;
    fWeight = npc->fWeight;
}

struct FUN_00604210_shell : public TESRace
{
    float FUN_00604210(int);
};
// @fnv 0x006041d0
float TESNPC::GetDefaultHeight()
{
    if (((::TESHairRaceResult *)(reinterpret_cast<::FUN_004ac110_shell *>((reinterpret_cast<TESHairCanBeNPCData*>(this)))->FUN_004ac110())))
        return reinterpret_cast<::FUN_00604210_shell *>((((::TESHairRaceResult *)(reinterpret_cast<::FUN_004ac110_shell *>((reinterpret_cast<TESHairCanBeNPCData*>(this)))->FUN_004ac110()))))->FUN_00604210((*(int *)&(const ::SEX &)(reinterpret_cast<::TESActorBase *>(this)->GetSex())));
    return 0.0f;
}

// @fnv 0x00604210
float FUN_00604210_shell::FUN_00604210(int aeSex)
{
    return (aeSex >= 0 && aeSex < 2) ? reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x60)[aeSex]
                                     : 0.0f;
}

struct FUN_006044c0_shell : public TESNPC
{
    TESNPC* FUN_006044c0();
};

// @fnv 0x006044c0
TESNPC* FUN_006044c0_shell::FUN_006044c0()
{
    return this->m_pTemplateNPC;
}

struct FUN_006047a0_shell : public PlayerCharacter
{
    bool FUN_006047a0();
};

// @fnv 0x006047a0
bool FUN_006047a0_shell::FUN_006047a0()
{
    return *((bool*)((char*)this + 0x7c5));
}

struct VR_00605d70
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
    virtual BipedAnim* v122();
};
struct VN_00605d70
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
    virtual void* v47();
};
struct PC_00605d70 : PlayerCharacter
{
};
struct NN_00605d70 : NiNode
{
    void Update(const NiUpdateData&);
};
void FUN_004ac1e0_x();
struct BA_00605d70
{
};
struct T_00605d70 : TESNPC
{
    void FUN_00605d70(TESObjectREFR* apRef);
};
// @fnv 0x00605d70
void T_00605d70::FUN_00605d70(TESObjectREFR* apRef)
{
    int iPasses;
    BipedAnim* pbiped;
    NiAVObject* pobj;
    pbiped = ((VR_00605d70*)apRef)->v122();
    pobj = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apRef))->FUN_0043fcd0()));
    iPasses = 1;
    if (apRef == ::_g_thePlayer)
        iPasses = 2;
    while (iPasses != 0)
    {
        if (apRef == ::_g_thePlayer && iPasses == 1)
        {
            pbiped = ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(reinterpret_cast<::FUN_004eaf60_shell *>((((PC_00605d70*)::_g_thePlayer)))->FUN_004eaf60())));
            pobj = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PC_00605d70*)::_g_thePlayer)))->FUN_00950bb0(true)));
        }
        RebuildHeadModel(apRef, pbiped, false);
        reinterpret_cast<::BipedLoadAccess *>((((BA_00605d70*)pbiped)))->UpdateBipedObjects(0);
        if (pobj)
        {
            reinterpret_cast<::FUN_00a5a040_Class *>((pobj))->FUN_00a5a040();
            ((VN_00605d70*)pobj)->v47();
            NiUpdateData UpdateData(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((NN_00605d70*)pobj)))->FUN_00a59c60((std::intptr_t)&(UpdateData));
        }
        iPasses--;
    }
}

struct FUN_00606050_shell : public TESNPC
{
    void InitWornObjects(TESObjectREFR*, BipedAnim*);
};

bool FUN_006061b0(TESNPC*, int, TESObjectREFR*, BipedAnim*, TESBoundObject*);

struct FUN_006061b0_caller
{
    bool FUN_006061b0_call(TESObjectREFR*, BipedAnim*, TESBoundObject*);
};

struct FUN_006061b0_shell : public TESNPC
{
    bool FUN_006061b0(TESObjectREFR*, BipedAnim*, TESBoundObject*);
};

bool _ref_008256d0(BSSimpleList<TESForm*>*);

// Attaches the given object's biped model (or weapon) to the biped anim, then attaches models from the object's race form list.
// @fnv 0x006061b0
bool FUN_006061b0_shell::FUN_006061b0(TESObjectREFR* apRef, BipedAnim* apBipedAnim, TESBoundObject* apObject)
{
    bool bresult = true;
    TESBipedModelForm* pbipedModel = ::TESBipedModelForm::GetFormAsBipedModel(apObject);
    if (apObject->GetFormType() == 0x28)
    {
        TESObjectWEAP* pweap = reinterpret_cast<TESObjectWEAP*>(apObject);
        reinterpret_cast<::BipedAnimWeap *>((apBipedAnim))->SetWeaponModel(pweap, 0);
    }
    else if (pbipedModel)
    {
        pbipedModel->SetBipedModel(
            apBipedAnim,
            static_cast<SEX>((*reinterpret_cast<unsigned int*>(&this->actorData.m_uiActorFlags) & 1) != 0), (::BIPED_OBJECT)(-1));
    }
    else
    {
        ::FUN_005b5e40();
    }

    BGSBipedModelList* pformList = BGSBipedModelList::GetBipedModelList(apObject);
    if (pformList && ((::TESRace *)(reinterpret_cast<::Callees *>((void *)(reinterpret_cast<TESRaceForm*>(pformList)))->FUN_00726070())))
    {
        BSSimpleList<TESForm*>* pCurrentElementNext =
            ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<BGSListForm*>(((::TESRace *)(reinterpret_cast<::Callees *>((void *)(reinterpret_cast<TESRaceForm*>(pformList)))->FUN_00726070())))))->GetConditions()));
        while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
        {
            TESForm* plistItem = pCurrentElementNext->m_item;
            pbipedModel = ::TESBipedModelForm::GetFormAsBipedModel(plistItem);
            if (pbipedModel)
            {
                pbipedModel->SetBipedModel(
                    apBipedAnim,
                    static_cast<SEX>((*reinterpret_cast<unsigned int*>(&this->actorData.m_uiActorFlags) & 1) != 0),
                    (::BIPED_OBJECT)(-1));
            }
            pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(((::TESRace *)(reinterpret_cast<::Callees *>((void *)(reinterpret_cast<TESRaceForm*>(pCurrentElementNext)))->FUN_00726070())));
        }
    }
    return bresult;
}

struct BipedAnimObject;
struct FUN_00606800_shell : public BipedAnim
{
    BipedAnimObject* FUN_00606800();
};

// @fnv 0x00606800
BipedAnimObject* FUN_00606800_shell::FUN_00606800()
{
    return reinterpret_cast<BipedAnimObject*>(&this->bipedData[364]);
}

struct FourComponentFloatVector;
struct NiAdditionalGeometryData;
struct NiBound;
struct CloningProcess;
struct RgbaColor;
struct NiCullingProcess;
struct NiGeometryData;
struct NiObject;
struct NiPoint2;
struct NiPropertyState;
struct NiRenderer;
struct NiShader;
struct NiSkinInstance;
struct NiStream;
struct NiGeometry : public NiAVObject
{
    virtual void __vslot_0();
    virtual void RenderImmediate(NiRenderer*);
    virtual void RenderWithRenderer(NiRenderer*);
    virtual void ReplaceModelData(NiGeometryData*);
    virtual void CalculateNormals();
    virtual void CalculateConsistency(bool);
    virtual void* GetRTTI();
    void CopyMemberData(NiGeometry*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    virtual void GetViewerStrings(void*);
    unsigned short GetVertexCount();
    NiPoint3* GetVertices();
    void SetActiveVertexQuantity(unsigned short);
    unsigned short GetActiveVertexQuantity();
    void SetDynamicData(bool);
    NiPoint3* GetNormals();
    int GetNormalBinormalTangentMethod();
    void StoreNormalBinormalTangent(int);
    void SetModelBound(void*);
    NiBound* GetModelBound();
    void CreateColors(bool);
    RgbaColor* GetColors();
    void CreateTextures(bool, unsigned short);
    unsigned short GetTextureSets();
    NiPoint2* GetTextures();
    NiPoint2* GetTextureSet(unsigned short);
    void AppendTextureSet(NiPoint2*);
    NiSkinInstance* GetSkinInstance();
    void SetSkinInstance(NiSkinInstance*);
    NiAdditionalGeometryData* GetAdditionalGeometryData();
    void AssignAdditionalGeometryData(NiAdditionalGeometryData*);
    void SetSortObject(bool);
    bool GetSortObject();
    NiPropertyState* GetPropertyStateP();
    virtual NiGeometry* IsGeometry();
    virtual void SetObjectBound(FourComponentFloatVector*);
    NiShader* GetGeometryShaderObject();
    NiShader* GetShaderFromMaterial();
    void SetShader(NiShader*);
    NiGeometryData* GetModelData();
    bool HasGeometryProperty(int);
    virtual void OnVisible(NiCullingProcess*);
    virtual void ApplyTransform(void*, void*, bool);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
    int GetConsistency();
    void SetDataConsistency(int);
    virtual void ProcessClone(CloningProcess*);
    virtual void PostLinkObject(NiStream*);
    virtual void SetSelectiveUpdateFlags(bool*, bool, bool*);
    virtual void PurgeRendererData(NiRenderer*);
    unsigned int QMemContext();
    virtual void UpdateWorldBound();
    void __local_vftable_ctor_closure();
    char _pad_4[188];
    char m_kPropertyState[28];
    char m_spGeometryData[4];
    char m_spSkinningInstance[4];
    NiShader* m_pGeometryShader;
    unsigned int m_uiGeometryShaderFlags;
    char _pad_ec[4];
};
struct NiTriBasedGeom : public NiGeometry
{
    virtual void __vslot_0();
    virtual void GetTrianglePoints(unsigned short, NiPoint3**, NiPoint3**, NiPoint3**);
    virtual void* GetRTTI();
    void CopyMemberData(NiTriBasedGeom*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    virtual void GetViewerStrings(void*);
    virtual void ReplaceModelData(NiGeometryData*);
    unsigned short GetTriangleCount();
    void SetNumberOfVertices(unsigned short);
    unsigned short GetNumberOfVertices();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    void GetTriangleVertexIndices(unsigned short, unsigned short*, unsigned short*, unsigned short*);
    void __local_vftable_ctor_closure();
};

class NiExtraData;
class NiFixedString;

const NiFixedString& __cdecl FUN_00607340();

struct NiAVObjectCall : public NiAVObject
{
};

// Returns the extra data named by FUN_00607340 from apGeom, or null if apGeom is null.
// @fnv 0x00607310
NiExtraData* __cdecl GetGeomExtraData(NiTriBasedGeom* apGeom)
{
    return apGeom ? reinterpret_cast<::NiAVObject *>((reinterpret_cast<NiAVObjectCall*>(apGeom)))->GetExtraData(FUN_00607340()) : 0;
}

struct FUN_00607350_shell : public TESRace
{
    unsigned short FUN_00607350();
};
// @fnv 0x00607370
void TESNPC::GetFaceGenNodes(BSFaceGenNiNode*& headBiped, BSFaceGenNiNode*& headSkinned)
{
    m_pkPrimaryFaceGenNode = 0;
    m_pkSecondaryFaceGenNode = 0;
    if (!m_pkPrimaryFaceGenNode && !m_pkSecondaryFaceGenNode && ((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())))
    {
        reinterpret_cast<::fnv_00613c50::FUN_00613c50_C *>((((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070()))))->CreateFaceGenNodes((::fnv_00613c50::FUN_006628c0_C **)&(headBiped), (::fnv_00613c50::FUN_006628c0_C **)&(headSkinned), (::TESActorBase *)(::TESNPC *)(this), true, false, (*(int *)&(const ::SEX &)((SEX)0)));
        m_usLastRace = reinterpret_cast<::FUN_00607350_shell *>((((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070()))))->FUN_00607350();
    }
}

// @fnv 0x00607350
unsigned short FUN_00607350_shell::FUN_00607350()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x4f8);
}

struct Dummy_00607810
{
    void SetBoneMaxAngle(int aeBone, float afMaxAngle);
};

struct Elem_00607810
{
    char pad[0x50];
};

struct Layout_00607810
{
    char pad[0xf8];
    Elem_00607810 arr[1];
};

// Stores afMaxAngle into the per-bone entry of the array at offset 0xf8 indexed by aeBone.
// @fnv 0x00607810
void Dummy_00607810::SetBoneMaxAngle(int aeBone, float afMaxAngle)
{
    *(float*)&((Layout_00607810*)this)->arr[aeBone] = afMaxAngle;
}

struct FUN_00607830_helper
{
    char pad[0x1a8];
    float f1A8;
    void set(float afAngle);
};

// @fnv 0x00607830
void FUN_00607830_helper::set(float afAngle)
{
    f1A8 = afAngle;
}

struct FUN_00608d80_shell : public Actor
{
    bool FUN_00608d80();
};

struct GameSettingCollection
{
};

// @fnv 0x00608d80
bool FUN_00608d80_shell::FUN_00608d80()
{
    return (int)((::TESFile *)(reinterpret_cast<::FUN_004f8960_shell *>((((GameSettingCollection*)this)))->FUN_004f8960())) == 4 ? true : false;
}

struct FUN_006099f0_shell : public TESNPC
{
    void LoadGamePostProcess(BGSLoadFormBuffer*);
};

// @fnv 0x006099f0
void FUN_006099f0_shell::LoadGamePostProcess(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Revert(apLoadGameBuffer);
    unsigned char cresetFlags = 0;
    bool bfixHeight = false;
    if (m_fGlyphExtent == GetDefaultHeight())
        bfixHeight = true;
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetOldChangeFlags(0x2000000)))->FUN_004280f0(0x2000000) && !reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x2000000)))->FUN_004280f0(0x2000000) &&
        m_pAssignedRace)
    {
        reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(reinterpret_cast<unsigned int>(m_pAssignedRace)));
        m_pAssignedRace = 0;
        cresetFlags |= 0x1b;
    }
    if (bfixHeight)
        m_fGlyphExtent = GetDefaultHeight();
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetOldChangeFlags(0x800)))->FUN_004280f0(0x800) && !reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x800)))->FUN_004280f0(0x800))
    {
        delete[] m_pOffsetFaceCoordinates;
        m_pOffsetFaceCoordinates = 0;
        cresetFlags |= 8;
        reinterpret_cast<::FileMatchList *>((reinterpret_cast<BSSimpleList<int>*>(&m_kHeadPartList)))->RemoveAll();
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetOldChangeFlags(0x1000000)))->FUN_004280f0(0x1000000) && !reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x1000000)))->FUN_004280f0(0x1000000))
    {
        reinterpret_cast<::FlagSet *>(this)->FUN_0047dd50(1, !GetFlag(1), true);
        cresetFlags |= 0x1b;
    }
    if (cresetFlags & 8)
        ResetFaceGen();
    if (cresetFlags)
        reinterpret_cast<::TESActorBase *>(this)->FUN_005f20a0(cresetFlags);
}

struct S_0060af60
{
    void FUN_0060af60(unsigned short a);
};
// Calls SetMaskedBits with the given unsigned short, 0xf00 and 8.
// @fnv 0x0060af60
void S_0060af60::FUN_0060af60(unsigned short ausValue)
{
    reinterpret_cast<::FUN_004f32e0_class *>(this)->SetMaskedBits(ausValue, 0xf00, 8);
}

struct FR2MatrixVTCData
{
    void SetDimensions(int nr, int nc);
};

struct H_0060b3b0
{
    char pad[0x18];
    unsigned int a;
    unsigned int b;
    void FUN_0060b3b0();
};
// @fnv 0x00601570
void TESNPC::ResetFormData()
{
    fWeight = 0.0f;
    m_fGlyphExtent = 0.0f;
    m_pHair = 0;
    m_fHairLength = 0.0f;
    m_pEyes = 0;
    if (!reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition())
    {
        m_pkPrimaryFaceGenNode = m_pkSecondaryFaceGenNode = 0;
        m_pkFaceGenTexture = 0;
    }
    m_usLastRace = 255;
    m_pClass = 0;
    m_pCombatStyle = 0;
    iHairColor = 0x19324b;
    m_pOffsetFaceCoordinates = 0;
    ::fnv_006529a0::FUN_006529a0(
        (FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(reinterpret_cast<FaceGenMatrix<float>(*)[2]>(BSFaceGenManager::GetFaceGenCoordinates())), (FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::FUN_00601800_shell *>(this)->FUN_00601800()))),
        0, 0);
    for (int r = 0; r < 2; ++r)
        for (int c = 0; c < 2; ++c)
            if (((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(m_kFaceGenCoordinates[r][c]))->FUN_009611e0())))
                reinterpret_cast<::H_0060b3b0 *>(&(m_kFaceGenCoordinates[r][c]))->FUN_0060b3b0();
    for (int i = 0; i < 14; ++i)
    {
        data.skills[i] = 5;
        data.skillOffsets[i] = 0;
    }
    m_eImpactMaterial = 6;
    m_pAssignedRace = 0;
    m_pTemplateNPC = 0;
    reinterpret_cast<::FUN_005f7b50_Class *>(this)->SetFlag200(1, false);
    reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(50));
}
// Resets face, hair color, skill values and related character fields, clears them when not loading, and reinitializes face coordinates and skills.
// @fnv 0x00601570
void FUN_00601570_shell::ResetCharacterData()
{
    fWeight = 0.0f;
    m_fGlyphExtent = 0.0f;
    m_pHair = 0;
    m_fHairLength = 0.0f;
    m_pEyes = 0;
    if (!reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition())
    {
        m_pkPrimaryFaceGenNode = (m_pkSecondaryFaceGenNode = 0);
        m_pkFaceGenTexture = 0;
    }
    m_usLastRace = 0xff;
    m_pClass = 0;
    m_pCombatStyle = 0;
    iHairColor = 0x19324b;
    m_pOffsetFaceCoordinates = 0;
    ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])((FaceGenMatrix<float>(*)[2])BSFaceGenManager::GetFaceGenCoordinates()),
                                             (FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::FUN_00601800_shell *>(this)->FUN_00601800()))), false, false);
    for (int etype = 0; etype < 2; ++etype)
    {
        for (int esymm = 0; esymm < 2; ++esymm)
        {
            if (((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((Calendar_DaysPassed_Helper*)&m_kFaceGenCoordinates[etype][esymm])))->FUN_009611e0())))
                reinterpret_cast<::H_0060b3b0 *>(&(m_kFaceGenCoordinates[etype][esymm]))->FUN_0060b3b0();
        }
    }
    for (int iSkillIndex = 0; iSkillIndex < 14; ++iSkillIndex)
    {
        data.skills[iSkillIndex] = 5;
        data.skillOffsets[iSkillIndex] = 0;
    }
    m_eImpactMaterial = 6;
    m_pAssignedRace = 0;
    m_pTemplateNPC = 0;
    reinterpret_cast<::FUN_005f7b50_Class *>(this)->SetFlag200(1, false);
    reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(50));
}
// Zeroes the buffer returned by FUN_006578b0(0), clearing a*b*4 bytes.
// @fnv 0x0060b3b0
void H_0060b3b0::FUN_0060b3b0()
{
    memset(((float *)(reinterpret_cast<::V_006578b0 *>((void *)this)->FUN_006578b0(0))), 0, a * b * 4);
}

struct S_0060b3f0
{
    void FUN_0060b3f0(unsigned int a);
};
struct S_0060ba10
{
    char pad[0xa];
    unsigned short s;
    void FUN_0060ba10(std::intptr_t a);
};
// Forwards the stored short s and the given int to FUN_0060bd90.
// @fnv 0x0060ba10
void S_0060ba10::FUN_0060ba10(std::intptr_t aiValue)
{
    reinterpret_cast<::FUN_0060bd90_cls *>(this)->FUN_0060bd90(s, aiValue);
}

struct FUN_00629ab0_shell
{
    float* p;
    float& FUN_00629ab0(unsigned int i);
};

// @fnv 0x00629ab0
float& FUN_00629ab0_shell::FUN_00629ab0(unsigned int uiIndex)
{
    return p[uiIndex];
}

struct GlobalObject_00528cb0
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    int v;
};
struct QueueHelper
{
    void FUN_00444040(int, int, int, int, bool, bool, bool);
};
// Constructs a GlobalObject_00528cb0 with 0 and forwards it with the remaining arguments to QueueTaskByKey.
// @fnv 0x00444040
void QueueHelper::FUN_00444040(int aiArg1, int aiArg2, int aiArg3, int aiArg4, bool abFlag1, bool abFlag2, bool abFlag3)
{
    GlobalObject_00528cb0 obj(0);
    reinterpret_cast<::FUN_004440d0_shell *>(this)->QueueTaskByKey(aiArg1, (*(::QOut444 *)(&obj)), aiArg2, (::QueuedFile *)(aiArg3), aiArg4, abFlag1, abFlag2, abFlag3);
}

struct BSFaceGenManager;
struct NP
{
    NP(int);
    ~NP();
    int* p;
};
extern BSFaceGenManager* DAT_011d59e8;
// Returns FUN_00559450() of the NP at offset 0x119c of DAT_011d59e8, or of a default NP(0) when DAT_011d59e8 is null.
// @fnv 0x006045f0
intptr_t __cdecl GetFaceGenManagerValue()
{
    NP kPointer = DAT_011d59e8 ? *(NP*)((char*)DAT_011d59e8 + 0x119c) : NP(0);
    return ::FUN_00559450((int *)&kPointer);
}

struct FUN_006055f0_shell : public TESNPC
{
    BipedAnim* GetOrCreateBipedAnim(TESObjectREFR*);
};

// Returns the reference's existing BipedAnim, warning if already set, otherwise creates one and assigns it to the reference.
// @fnv 0x006055f0
BipedAnim* FUN_006055f0_shell::GetOrCreateBipedAnim(TESObjectREFR* apRef)
{
    BipedAnim* pExistingBipedAnim;
    AutoMemContext tempMemContext((MEM_CONTEXT)0x33, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESNPC.cpp", 0x15d1);
    pExistingBipedAnim = apRef->GetBipedAnim();
    if (pExistingBipedAnim)
    {
        ::FUN_005b5e40();
    }
    else
    {
        pExistingBipedAnim = new BipedAnim(apRef, false);
        apRef->SetBipedAnim(pExistingBipedAnim);
    }
    return pExistingBipedAnim;
}

struct FUN_005d9f70_shell
{
    void SetField1B4(std::intptr_t value);
};

// @fnv 0x005d9f70
void FUN_005d9f70_shell::SetField1B4(std::intptr_t value)
{
    *(int*)((char*)this + 0x1b4) = value;
}

struct FUN_005f1230_shell : TESAttributes
{
    unsigned char GetAttributeValue7();
};

// @fnv 0x005f1230
unsigned char FUN_005f1230_shell::GetAttributeValue7()
{
    return reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(7);
}

struct FUN_00601c70_shell
{
    void FUN_00601c70(std::intptr_t param);
};

// Stores param at offset 0x130 of this and calls the virtual function at vtable offset 0x48 with 0x400.
// @fnv 0x00601c70
void FUN_00601c70_shell::FUN_00601c70(std::intptr_t aiValue)
{
    *(int*)((char*)this + 0x130) = aiValue;
    ((void(*)(void*, int)) * (int**)(*(int*)this + 0x48))(this, 0x400);
}

struct FUN_00603f90_shell : TESRaceForm
{
    TESRace* GetRaceOrNull();
};

// Returns GetFormRace(), replacing a negative result with null.
// @fnv 0x00603f90
TESRace* FUN_00603f90_shell::GetRaceOrNull()
{
    TESRace* race = ((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070()));
    if ((long)race < 0)
        race = 0;
    return race;
}

extern NiFixedString* DAT_011c6210;

// @fnv 0x006041c0
NiFixedString* __cdecl FUN_006041c0()
{
    return DAT_011c6210;
}

struct FUN_00604780_shell
{
    int FUN_00604780(int index);
};

// @fnv 0x00604780
int FUN_00604780_shell::FUN_00604780(int index)
{
    return *(int*)((char*)this + 0x4FC + index * 4);
}

namespace fnv_00607340 {
class BSFadeNode;

// @fnv 0x00607340
BSFadeNode* __cdecl FUN_00607340()
{
    return (*reinterpret_cast<::fnv_00607340::BSFadeNode * *>(&::DAT_011d5b50));
}
}  // namespace fnv_00607340

extern unsigned char DAT_011871f8;
struct FileH
{
    bool OpenTESFile(int, bool);
};
struct FUN_00472660_shell
{
    int FUN_00472660();
};
struct FUN_00609bf0_s : TESNPC
{
    bool FUN_00609bf0(TESFile* apFile);
};
// Checks apFile and the offset at this+0x1e8, seeks there, compares the read value to DAT_011871f8 and the form ID to GetFormID.
// @fnv 0x00609bf0
bool FUN_00609bf0_s::FUN_00609bf0(TESFile* apFile)
{
    if (apFile && this->m_ulTopicFlags &&
        reinterpret_cast<FileH*>(apFile)->OpenTESFile(0, false) &&
        reinterpret_cast<::TESOffsetWorker *>((reinterpret_cast<FileH*>(apFile)))->FUN_004723a0(
            this->m_ulTopicFlags) &&
        reinterpret_cast<FUN_00472660_shell*>(apFile)->FUN_00472660() == DAT_011871f8 &&
        ((unsigned int)(reinterpret_cast<::MiddleHighProcess *>((reinterpret_cast<FileH*>(apFile)))->GetFaceGenHeadNode())) == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())))
        return true;
    return false;
}

struct FUN_0060b1d0_shell : TESActorBaseData
{
    bool FUN_0060b1d0();
};

// @fnv 0x0060b1d0
bool FUN_0060b1d0_shell::FUN_0060b1d0()
{
    return GetFlag(0x800);
}

struct FUN_0060b1f0_shell : TESActorBaseData
{
    bool FUN_0060b1f0();
};

// @fnv 0x0060b1f0
bool FUN_0060b1f0_shell::FUN_0060b1f0()
{
    return GetFlag(0x1000);
}

struct FUN_0060b210_shell : TESActorBaseData
{
    void FUN_0060b210(bool bArg);
};

// @fnv 0x0060b210
void FUN_0060b210_shell::FUN_0060b210(bool bArg)
{
    reinterpret_cast<::FlagSet *>(this)->FUN_0047dd50(0x1000, bArg, true);
}

struct BGSSaveFormBuffer;
struct Crime;
struct FUN_009dace0_shell : public TESActorBase
{
    void FUN_009dace0(BGSLoadFormBuffer*);
};

// @fnv 0x009dace0
void FUN_009dace0_shell::FUN_009dace0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((std::uintptr_t)apLoadGameBuffer);
}

struct FUN_005f16f0_shell
{
};

struct TESNPC;

struct FUN_00608da0_shell : TESNPC
{
    unsigned short FUN_00608da0(unsigned int aiFlags);
};

// Accumulates the base size from FUN_005f16f0 and adds 0xe when aiFlags has 0x200 set, returning the total.
// @fnv 0x00608da0
unsigned short FUN_00608da0_shell::FUN_00608da0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::ActorBaseSaveView *>((((FUN_005f16f0_shell*)this)))->FUN_005f16f0(aiFlags);
    if (aiFlags & 0x200)
        isize += 0xe;
    if (aiFlags & 0)
        isize += 4;
    return isize;
}

struct FUN_00601370_shell
{
    void FUN_006013c0();
    void* FUN_00601370(unsigned int);
};
// Calls FUN_006013c0, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00601370
void* FUN_00601370_shell::FUN_00601370(unsigned int flags)
{
    this->FUN_006013c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006013a0_shell
{
    void FUN_006013a0();
};

struct Struct00601c30
{
    const char* GetSexBasedString();
};
// Returns the string from one of two game setting collections depending on whether the actor base at this-0xDC has sex 1.
// @fnv 0x00601c30
const char* Struct00601c30::GetSexBasedString()
{
    if (((TESActorBase*)((char*)this - 0xDC))->GetSex() == 1)
        return ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d2718))))->GetMenuTitle()));
    return ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3e44))))->GetMenuTitle()));
}

struct GO
{
    void* p;
    GO& operator=(void*);
};
struct FUN_00603bb0_Owner
{
    char pad[0x1C4];
    GO a;
    GO b;
    void FUN_00603bb0();
};
// @fnv 0x00603bb0
void FUN_00603bb0_Owner::FUN_00603bb0()
{
    a = 0;
    b = 0;
}

namespace fnv_006072c0 {
struct NiSkinInstance;
struct NiTriBasedGeom
{
};
struct Inner6072
{
    char _c[16];
    int _v;
};
struct Outer6072
{
    char _pad[8];
    Inner6072* p;
    NiSkinInstance* FUN_006072c0();
};
// @fnv 0x006072c0
NiSkinInstance* Outer6072::FUN_006072c0()
{
    return (p && ::FUN_00559450(&p->_v)) ? ((::fnv_006072c0::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(((NiTriBasedGeom*)::FUN_00559450(&p->_v)))))) : 0;
}
}  // namespace fnv_006072c0

struct FUN_008b78c0_shell
{
};
struct FUN_0060b240_shell : public TESNPC
{
    void SetRace(TESRace* race, FUN_008b78c0_shell* actor);
};
// @fnv 0x0060b240
void FUN_0060b240_shell::SetRace(TESRace* race, FUN_008b78c0_shell* actor)
{
    TESRace* current = ((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070()));
    if (race != current)
    {
        bool fixHeight = false;
        if (GetDefaultHeight() == m_fGlyphExtent)
            fixHeight = true;
        if (m_pAssignedRace == race)
        {
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(race));
            m_pAssignedRace = 0;
            MarkAsUnmodified(0x2000000);
        }
        else
        {
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(race));
            MarkAsModified(0x2000000);
            if (m_pAssignedRace == 0)
                m_pAssignedRace = current;
        }
        if (fixHeight)
            m_fGlyphExtent = GetDefaultHeight();
        if (actor)
            reinterpret_cast<::fnv_008b78c0::FUN_008b78c0_shell *>((actor))->UpdateHurtReaction(0);
    }
}

struct S8
{
    int v0;
    int v1;
    S8* FUN_0060b820(S8*, int);
};
void __cdecl FillRange(int, int, int, void*);
struct Unk060b8a0
{
    std::intptr_t FUN_0060b8a0(std::intptr_t, int, int);
};
// Calls FillRange with the three arguments and this+8, then returns a + b*4.
// @fnv 0x0060b8a0
std::intptr_t Unk060b8a0::FUN_0060b8a0(std::intptr_t aiFirst, int aiSecond, int aiThird)
{
    FillRange(aiFirst, aiSecond, aiThird, (char*)this + 8);
    return aiFirst + aiSecond * 4;
}

struct FUN_0060b8e0_shell
{
    void* FUN_0060b8e0(int);
};
// @fnv 0x0060b820
S8* S8::FUN_0060b820(S8* out, int arg)
{
    S8 tmp = *this;
    *out = *((::S8 *)(reinterpret_cast<::FUN_0060b8e0_shell *>(&(tmp))->FUN_0060b8e0(arg)));
    return out;
}

struct S_0060b980
{
    int* p;
    std::intptr_t FUN_0060b980();
};
// Returns the result of FUN_00559450 on the stored pointer, or 0 when the pointer is null.
// @fnv 0x0060b980
std::intptr_t S_0060b980::FUN_0060b980()
{
    return p ? FUN_00559450(p) : 0;
}

struct Holder_FUN_0060b9b0
{
    void* vfptr;
    void* m_data;
    void FUN_0060b9b0();
};
// @fnv 0x006013a0
void FUN_006013a0_shell::FUN_006013a0()
{
    reinterpret_cast<::Holder_FUN_0060b9b0 *>(this)->FUN_0060b9b0();
}
// Sets the vtable pointer to DAT_0104aae0 and calls FUN_004ede70 on m_data.
// @fnv 0x0060b9b0
void Holder_FUN_0060b9b0::FUN_0060b9b0()
{
    vfptr = (void*)&DAT_0104aae0;
    FUN_004ede70(m_data);
}

struct FUN_006042d0_Owner
{
    char _pad[0x68];
    float _arr[2];
    float GetArrValue(int);
};
// Returns the element of _arr at index a1 when a1 is in [0,2), otherwise returns 0.0f.
// @fnv 0x006042d0
float FUN_006042d0_Owner::GetArrValue(int aiIndex)
{
    return (aiIndex >= 0 && aiIndex < 2) ? _arr[aiIndex] : 0.0f;
}

struct FUN_0060b860_Cls
{
    char _pad0[12];
    int _c;
    char _pad1[4];
    int _t;
    int FUN_0060b860();
};
// @fnv 0x0060b860
int FUN_0060b860_Cls::FUN_0060b860()
{
    return _c == 0 ? 0 : (_t - _c) >> 2;
}

struct STR_0060b9e0
{
    void* FUN_0060b9e0(unsigned int, unsigned int);
};
extern int DAT_0104aae8;
// @fnv 0x0060b9e0
void* STR_0060b9e0::FUN_0060b9e0(unsigned int arg1, unsigned int arg2)
{
    new ((void *)this) ::fnv_0060bd20::FUN_0060bd20_class(arg1, arg2);
    *(void**)this = &DAT_0104aae8;
    return this;
}

namespace fnv_006013c0 {
struct GO
{
    void* p;
    ~GO();
};
struct ListX
{
    void* a;
    void* b;
    ~ListX();
};
struct FUN_006013a0
{
    unsigned char d[0x10];
    ~FUN_006013a0();
};
struct NpcList_t
{
};

struct FUN_006013c0 : public TESActorBase, public TESRaceForm
{
    ActorSkillData data;
    TESClass* m_pClass;
    FaceGenMatrix<float> m_kFaceGenCoordinates[2][2];
    void* m_pOffsetFaceCoordinates;
    TESHair* m_pHair;
    float m_fHairLength;
    TESEyes* m_pEyes;
    GO m_pkPrimaryFaceGenNode, m_pkSecondaryFaceGenNode, m_pkFaceGenTexture;
    unsigned short m_usLastRace;
    unsigned short lastRacePadding;
    TESCombatStyle* m_pCombatStyle;
    unsigned int iHairColor;
    ListX m_kHeadPartList;
    int m_eImpactMaterial;
    unsigned int m_ulTopicFlags;
    TESRace* m_pAssignedRace;
    TESNPC* m_pTemplateNPC;
    float m_fGlyphExtent, fWeight;
    FUN_006013a0 undoStates;
    ~FUN_006013c0();
};

// @fnv 0x006013c0
FUN_006013c0::~FUN_006013c0()
{
    ((TESNPC*)this)->TESNPC::ClearData();
    if (GetFlag(4))
    {
        reinterpret_cast<::ItemChangeListNode *>((((NpcList_t*)&(*reinterpret_cast<::BSSimpleList< ::TESNPC *> *>(&::g_011cb764)))))->FUN_00905330((::InventoryStackRecord *const &)((const ::TESNPC *const &)((TESNPC*)this)));
    }
}
}  // namespace fnv_006013c0

namespace fnv_006044e0 {
struct FUN_006044e0_shell : public TESNPC
{
    void CreatePartTexture(int, void*);
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct TESObject
{
};
struct GO
{
    GO(int);
    ~GO();
    void operator=(void*);
    void* ptr;
};
struct Helper62d0
{
    void* operator=(void const*);
};
struct TES
{
};
struct FUN_00604310_shell
{
    bool FUN_00604310(int, char*, unsigned int);
};

// @fnv 0x006044e0
void FUN_006044e0_shell::CreatePartTexture(int aePart, void* aspTexture)
{
    if (*(*reinterpret_cast<::fnv_006044e0::GlobalObject_0045cf30 *>(&::g_011d5adc)).Bool() || (unsigned int)this == ((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject*)::_g_thePlayer)))->FUN_007af430())))
    {
        *(GO*)aspTexture = 0;
        return;
    }
    if (aePart >= 1)
    {
        *(GO*)aspTexture = ((void *)(::GetFaceGenManagerValue()));
        return;
    }
    char filename[260];
    if (!((FUN_00604310_shell*)this)->FUN_00604310(aePart, filename, 0x104))
    {
        *(GO*)aspTexture = 0;
        return;
    }
    GO sTexture(0);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_006044e0::TES * *>(&::g_TES))))->FUN_004568c0(filename, (::TexPtr< ::NiSourceTexture> &)(sTexture), true, false);
    *(Helper62d0*)aspTexture = &sTexture;
}
}  // namespace fnv_006044e0


// @fnv 0x00603220
int FUN_00603220(char** apFirst, char** apSecond)
{
    char** localA = apFirst;
    char** localB = apSecond;
    if (!localA || !*localA || !localB || !*localB)
        return 0;
    return FUN_00408b20(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(*localA) + 0xd0)))->FUN_00408da0())),
                        ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(*localB) + 0xd0)))->FUN_00408da0())));
}

struct PC7d
{
};
struct FUN_00484d20_Class
{
public:
    void ForwardToSaveLoadGame(int, int);
};
struct FUN_00608e00_shell
{
    void FUN_00608e00(unsigned int aiFlags);
};

// @fnv 0x00608e00
void FUN_00608e00_shell::FUN_00608e00(unsigned int aiFlags)
{
    reinterpret_cast<::fnv_005f18c0::SaveActorBase *>(this)->FUN_005f18c0(aiFlags);
    if (aiFlags & 0x200)
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
            (void *)(reinterpret_cast<unsigned int>(reinterpret_cast<char*>(this) + 0x114)), 0xe);
    if (aiFlags & 0)
    {
        int icombatstyleID = 0;
        if (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x1d4))
            icombatstyleID =
                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x1d4))))->FUN_0084e3a0()));
        reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame((int)(&icombatstyleID), 4);
    }
}

struct TESCombatStyle;
struct TESForm;
struct STR00
{
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int*, int);
};
struct FUN_00608e80_shell
{
    void FUN_00608e80(unsigned int aiFlags, unsigned int aiCurrentFlags);
};
// @fnv 0x00608e80
void FUN_00608e80_shell::FUN_00608e80(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<::fnv_005f1b30::ActorBaseLoad *>(this)->FUN_005f1b30(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x200)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00((char*)this + 0x114, 0xe);
    if (aiFlags & 0)
    {
        unsigned int icombatstyleID;
        ((FUN_00484d40_Host*)this)->FUN_00484d40(&icombatstyleID, 4);
        *(TESCombatStyle**)((char*)this + 0x1d4) =
            (TESCombatStyle*)dynamic_cast<TESCombatStyle*>(::FUN_004839c0(icombatstyleID));
    }
}

namespace fnv_006046a0 {
struct TESObject
{
};

struct FUN_006047a0_shell : public TESObject
{
};

struct FUN_00604780_shell
{
};

struct BGSDefaultObjectManager
{
};

struct FUN_006046a0_shell
{
    TESForm* GetHeadPartForm();
};


// For the player actor, picks a default head part form by sex and FUN_006047a0 state, then returns the stored form or resolves one from the list at +0xdc.
// @fnv 0x006046a0
TESForm* FUN_006046a0_shell::GetHeadPartForm()
{
    if (reinterpret_cast<unsigned int>(reinterpret_cast<char*>(this) - 0x30) == ((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::fnv_006046a0::FUN_006047a0_shell * *>(&::_g_thePlayer))))->FUN_007af430())))
    {
        if (reinterpret_cast<TESActorBase*>(reinterpret_cast<char*>(this) - 0x30)->GetSex() == 0)
        {
            if (!reinterpret_cast<::FUN_006047a0_shell *>(((*reinterpret_cast<::fnv_006046a0::FUN_006047a0_shell * *>(&::_g_thePlayer))))->FUN_006047a0())
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x0e));
            else
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x0f));
        }
        else
        {
            if (!reinterpret_cast<::FUN_006047a0_shell *>(((*reinterpret_cast<::fnv_006046a0::FUN_006047a0_shell * *>(&::_g_thePlayer))))->FUN_006047a0())
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x10));
            else
                *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20) =
                    ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x11));
        }
    }

    if (*reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20))
        return *reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x20);

    BSSimpleList<BGSHeadPart*>* list =
        ((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(reinterpret_cast<char*>(this) + 0xdc)))->FUN_00726070()));

    if (list)
        return reinterpret_cast<TESForm*>(reinterpret_cast<::FUN_00604780_shell *>((reinterpret_cast<FUN_00604780_shell*>(list)))->FUN_00604780(
            reinterpret_cast<TESActorBase*>(reinterpret_cast<char*>(this) - 0x30)->GetSex()));

    return 0;
}
}  // namespace fnv_006046a0

struct FUN_006062e0_shell : public TESNPC
{
    void UpdateFaceGenHairVisibility(TESObjectREFR*, NiNode*);
};

struct SaveField
{
    unsigned int FUN_009611e0();
};
struct FaceValue
{
    float* data;
    unsigned int offset;
};
struct FaceMatrix
{
    unsigned int FUN_009611e0();
    FaceValue FUN_0060b370(unsigned int index, unsigned int column);
};
struct GameForm
{
};
struct HeadPartNode
{
    bool FUN_008256d0();
};

struct NPCSerializer
{
    void WriteToStream();
};

// Serializes the NPC record: writes sub-records, head parts, face morph values and extra fields to the save stream.
// @fnv 0x00601ca0
void NPCSerializer::WriteToStream()
{
    unsigned int count;
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((SaveField*)((char*)this + 0xd0))))->FUN_00487010();
    reinterpret_cast<::FUN_004891d0_cls *>((((SaveField*)((char*)this + 0xdc))))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    reinterpret_cast<::FUN_0047cac0_t *>((((SaveField*)((char*)this + 0x30))))->DestroySoundHandles();
    reinterpret_cast<::FUN_0048b830_Class *>((((SaveField*)((char*)this + 0x10c))))->ReleaseSound();
    reinterpret_cast<::TESSpellListShell *>((((SaveField*)((char*)this + 0x7c))))->FUN_0048d330();
    reinterpret_cast<::FUN_0047bd70_shell *>((((SaveField*)((char*)this + 0x70))))->FUN_0047bd70();
    reinterpret_cast<::FUN_00477f20_shell *>((((SaveField*)((char*)this + 0x104))))->FUN_00477f20();

    if (*(GameForm**)((char*)this + 0x130))
    {
        count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*(GameForm**)((char*)this + 0x130))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e43, count);
    }
    reinterpret_cast<::FUN_00485e00_shell *>(this)->FUN_00485e00();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>((((SaveField*)((char*)this + 0x114))))->ClearData();
    ::AppendChunk(0x4d414e44, (char*)this + 0x114, 0x1c);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>((((SaveField*)((char*)this + 0x114))))->ClearData();

    HeadPartNode* head = ((::HeadPartNode *)(reinterpret_cast<::FUN_00602170_shell *>(this)->FUN_00602170()));
    while (head && !head->FUN_008256d0())
    {
        GameForm* item = *((::GameForm **)((void *)(head)));
        ::FUN_00485910(0x4d414e50, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((item))->FUN_0084e3a0())));
        head = ((::HeadPartNode *)(reinterpret_cast<::Callees *>((head))->FUN_00726070()));
    }

    if (((::GameForm *)(reinterpret_cast<::TESNPC *>(this)->GetHair())))
    {
        ::FUN_00485910(0x4d414e48, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::GameForm *)(reinterpret_cast<::TESNPC *>(this)->GetHair()))))->FUN_0084e3a0())));
        ::FUN_00485910(0x4d414e4c, reinterpret_cast<::FUN_00602130_shell *>(this)->FUN_00602130());
    }
    if (((::GameForm *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetAnimation())))
    {
        ::FUN_00485910(0x4d414e45, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::GameForm *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetAnimation()))))->FUN_0084e3a0())));
    }
    ::FUN_00485910(0x524c4348, *(unsigned int*)((char*)this + 0x1d8));

    typedef GameForm*(* GetExtraFace)(NPCSerializer*);
    if (((GetExtraFace)((*(void***)this)[0x188 / 4]))(this))
    {
        ::FUN_00485910(0x4d414e5a, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((GetExtraFace)((*(void***)this)[0x188 / 4]))(this)))->FUN_0084e3a0())));
    }
    ::FUN_00485910(0x344d414e, *(unsigned int*)((char*)this + 0x1e4));

    std::uintptr_t formID = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix*)((char*)this + 0x134))))->FUN_009611e0()));
    if (formID != 0)
    {
        unsigned int values = formID * 4;
        float* bytes = (float*)FUN_00401000(values);
        FUN_00403d30(bytes, 0, values);
        for (unsigned int index = 0; index < formID; ++index)
        {
            bytes[index] = *((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue &)(((FaceMatrix*)((char*)this + 0x134))->FUN_0060b370(index, 0)))->FUN_00629ab0({})));
        }
        ::FUN_00485710((void *)(0x53474746), (void *)(bytes), (void *)(formID));
        FUN_00401030(bytes);
        bytes = 0;
    }
    formID = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix*)((char*)this + 0x154))))->FUN_009611e0()));
    if (formID != 0)
    {
        unsigned int bytesSecond = formID * 4;
        float* valuesSecond = (float*)FUN_00401000(bytesSecond);
        FUN_00403d30(valuesSecond, 0, bytesSecond);
        for (unsigned int indexSecond = 0; indexSecond < formID; ++indexSecond)
        {
            valuesSecond[indexSecond] =
                *((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue &)(((FaceMatrix*)((char*)this + 0x154))->FUN_0060b370(indexSecond, 0)))->FUN_00629ab0({})));
        }
        ::FUN_00485710((void *)(0x41474746), (void *)(valuesSecond), (void *)(formID));
        FUN_00401030(valuesSecond);
        valuesSecond = 0;
    }
    formID = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix*)((char*)this + 0x174))))->FUN_009611e0()));
    if (formID != 0)
    {
        unsigned int bytesThird = formID * 4;
        float* valuesThird = (float*)FUN_00401000(bytesThird);
        FUN_00403d30(valuesThird, 0, bytesThird);
        for (unsigned int indexThird = 0; indexThird < formID; ++indexThird)
        {
            valuesThird[indexThird] = *((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue &)(((FaceMatrix*)((char*)this + 0x174))->FUN_0060b370(indexThird, 0)))->FUN_00629ab0({})));
        }
        ::FUN_00485710((void *)(0x53544746), (void *)(valuesThird), (void *)(formID));
        FUN_00401030(valuesThird);
        valuesThird = 0;
    }

    ::FUN_00485950((void *)(0x354d414e), *(unsigned short*)((char*)this + 0x1d0));
    ::FUN_00485910(0x364d414e, *(float*)((char*)this + 0x1f4));
    ::FUN_00485910(0x374d414e, *(float*)((char*)this + 0x1f8));
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}


struct NpcFaceGenQueue
{
};

class NpcLoadShell : public TESNPC
{
  public:
    bool FUN_00602190(TESFile* apFile);
};

// @fnv 0x00602190
bool NpcLoadShell::FUN_00602190(TESFile* apFile)
{
    unsigned char _type;
    bool _found;
    int iD5;
    int iRow_2;
    int aType;
    bool bContinue;
    bool next9;
    float* buf3;
    char* pEditorID;

    _type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((apFile))->FUN_00472660()));
    if (_type != 0x2A)
        return false;

    m_ulTopicFlags = reinterpret_cast<::TESFile *>((((TESNPCFileAccess*)apFile)))->GetOffset();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(apFile));
    SetInitializationState(false);

    _found = false;
    while ((iD5 = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()))) != 0)
    {
        iRow_2 = -1;
        aType = -1;
        bContinue = true;
        next9 = false;

        switch (iD5)
        {
        case 0x44494445 /* EDID */:
            pEditorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pEditorID), 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        case 0x444E424F /* OBND */:
            readOBNDSubRecord(apFile);
            break;
        case 0x4C4C5546 /* FULL */:
            ::ReadFullName(this, apFile);
            break;
        case 0x4C444F4D /* MODL */:
        case 0x54444F4D /* MODT */:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x49524353 /* SCRI */: {
            unsigned int uiScript = 0;
            apFile->GetChunkData(&uiScript);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(uiScript));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x44454F43 /* COED */:
        case 0x4F544E43 /* CNTO */:
            switch (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())))
            {
            case 0x4F544E43 /* CNTO */: {
                ContainerItem kItem;
                memset(&kItem, 0, sizeof(kItem));
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&kItem), sizeof(kItem));
                if (apFile->IsEndianConversionRequired())
                    reinterpret_cast<::S_00462230 *>(&(kItem))->FUN_00462230();
                DAT_011cb7d8 = reinterpret_cast<::fnv_004817f0::FUN_004817f0_shell *>(this)->AddContainerObject((::fnv_004817f0::ContainerChanges *)(::ContainerItem *)(&kItem));
                break;
            }
            case 0x44454F43 /* COED */:
                if (DAT_011cb7d8)
                {
                    DAT_011cb7d8->pExtra = new ContainerItemExtra;
                    DAT_011cb7d8->pExtra->Load(apFile);
                    DAT_011cb7d8 = 0;
                }
                break;
            }
            break;
        case 0x4F4C5053 /* SPLO */: {
            unsigned int uiSpell = 0;
            apFile->GetChunkData(&uiSpell);
            reinterpret_cast<::fnv_0048d290::FUN_0048d290_shell *>(this)->FUN_0048d290((::TESForm *)(std::uintptr_t)(uiSpell));
            break;
        }
        case 0x4D544945 /* EITM */: {
            unsigned int uiEnchant = 0;
            apFile->GetChunkData(&uiEnchant);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(uiEnchant));
            break;
        }
        case 0x544D4145 /* EAMT */: {
            unsigned short usAmount = 0;
            reinterpret_cast<::FUN_00472840_impl *>((((TESFileChunkData16*)apFile)))->ReadChunkData(&usAmount);
            reinterpret_cast<::TESEnchantableForm *>(this)->SetFormEnchantmentAmount(usAmount);
            break;
        }
        case 0x54444941 /* AIDT */: {
            PackedRecordData kAIData;
            memset(&kAIData, 0, sizeof(kAIData));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&kAIData), sizeof(kAIData));
            if (apFile->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00503240_shell *>(&(kAIData))->SwapEndianFields();
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)apFile)))->FUN_00403570() < 4)
            {
                if (kAIData.m_ucField00 > 1)
                    kAIData.m_ucField00++;
            }
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)apFile)))->FUN_00403570() < 6)
            {
                switch (kAIData.m_ucField00)
                {
                case 0:
                    kAIData.m_ucField0E = 0;
                    break;
                case 1:
                    kAIData.m_ucField00 = 0;
                    kAIData.m_ucField0E = 1;
                    break;
                case 2:
                    kAIData.m_ucField00 = 1;
                    kAIData.m_ucField0E = 1;
                    break;
                case 3:
                    kAIData.m_ucField00 = 1;
                    kAIData.m_ucField0E = 2;
                    break;
                case 4:
                    kAIData.m_ucField00 = 2;
                    kAIData.m_ucField0E = 2;
                    break;
                case 5:
                    kAIData.m_ucField00 = 3;
                    kAIData.m_ucField0E = 0;
                    break;
                }
            }
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)apFile)))->FUN_00403570() < 7)
                kAIData.m_ucField01 = 4 - kAIData.m_ucField01;
            reinterpret_cast<::TESAIForm *>(this)->CopyAIDataFromAIDATA(&kAIData);
            break;
        }
        case 0x44494B50 /* PKID */: {
            unsigned int uiPackage = 0;
            apFile->GetChunkData(&uiPackage);
            reinterpret_cast<::fnv_0047f500::FUN_0047f500_shell *>(this)->FUN_0047f500((::fnv_0047f500::TESPackage *)(std::uintptr_t)(uiPackage));
            break;
        }
        case 0x4D414E53 /* SNAM */: {
            FactionReaction kRank;
            memset(&kRank, 0, sizeof(kRank));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&kRank), sizeof(kRank));
            if (apFile->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>(&(kRank))->FUN_00503210();
            reinterpret_cast<::FUN_0047d800_shell *>(this)->FUN_0047d800(kRank.pFaction, kRank.m_ucRank);
            break;
        }
        case 0x4D414E49 /* INAM */: {
            unsigned int uiDeathItem = 0;
            apFile->GetChunkData(&uiDeathItem);
            m_pBaseTemplateForm = (TESForm*)(std::uintptr_t)uiDeathItem;
            break;
        }
        case 0x4B435456 /* VTCK */: {
            unsigned int uiVoice;
            apFile->GetChunkData(&uiVoice);
            m_kFactionList = (TESForm*)(std::uintptr_t)uiVoice;
            break;
        }
        case 0x544C5054 /* TPLT */: {
            unsigned int uiTemplate;
            apFile->GetChunkData(&uiTemplate);
            m_ppTemplateForms = (TESForm*)(std::uintptr_t)uiTemplate;
            break;
        }
        case 0x53424341 /* ACBS */:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&actorData), sizeof(actorData));
            if (apFile->IsEndianConversionRequired())
                reinterpret_cast<::Header47cb90 *>(&(actorData))->SwapEndianness();
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)apFile)))->FUN_00403570() < 8)
                actorData.m_usField16 = 0;
            actorData.m_usField06 = 0;
            break;
        case 0x4D414E52 /* RNAM */: {
            unsigned int uiRace = 0;
            apFile->GetChunkData(&uiRace);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(uiRace));
            break;
        }
        case 0x5A46464B /* KFFZ */:
            reinterpret_cast<::TESAnimation *>(this)->LoadComponent((::TESForm *)(::TESAnimation *)(this), apFile);
            break;
        case 0x54534544 /* DEST */:
        case 0x44545344 /* DSTD */:
            ::FUN_004781e0(this, apFile);
            break;
        case 0x41544144 /* DATA */: {
            unsigned int uiExtra = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C() - reinterpret_cast<::FUN_00486620_shell *>(this)->FUN_00486620();
            if (uiExtra)
            {
                if (uiExtra != 0x1C && uiExtra * 2 != 0x1C)
                    ::FUN_005b5e40();
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(apFile, &data, (unsigned short)uiExtra);
            }
            else
            {
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(apFile, 0, 0);
            }
            break;
        }
        case 0x4D414E44 /* DNAM */:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&data), 0x1C);
            break;
        case 0x53474746 /* FGGS */:
            if (iRow_2 == -1)
            {
                iRow_2 = 0;
                aType = 0;
            }
        case 0x41474746 /* FGGA */:
            if (iRow_2 == -1)
            {
                iRow_2 = 0;
                aType = 1;
            }
        case 0x53544746 /* FGTS */: {
            if (iRow_2 == -1)
            {
                iRow_2 = 1;
                aType = 0;
            }
            unsigned int uiSize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
            unsigned int ItemUpdateArray = uiSize >> 2;
            reinterpret_cast<::FR2MatrixVTCData *>(&(m_kFaceGenCoordinates[iRow_2][aType]))->SetDimensions(ItemUpdateArray, 1);
            buf3 = (float*)_alloca(uiSize);
            memset(buf3, 0, uiSize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(buf3), uiSize);
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                if (apFile->IsEndianConversionRequired())
                    ::FUN_00401080((int *)(float *)(&buf3[i]));
                *(float*)((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(m_kFaceGenCoordinates[iRow_2][aType].FUN_0060b370(i, 0)))->FUN_00629ab0({}))) = buf3[i];
            }
            break;
        }
        case 0x4D414E50 /* PNAM */: {
            unsigned int uiPartID;
            apFile->GetChunkData(&uiPartID);
            ::ResolveFormID((unsigned int *)&(uiPartID), apFile);
            BGSHeadPart* pHeadPart = dynamic_cast<BGSHeadPart*>(::FUN_004839c0(uiPartID));
            if (pHeadPart)
                ((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>(this)->FUN_00602170()))->AddHead(pHeadPart);
            else
                ::FUN_005b5e40();
            break;
        }
        case 0x4D414E48 /* HNAM */: {
            unsigned int _id;
            apFile->GetChunkData(&_id);
            ::ResolveFormID((unsigned int *)&(_id), apFile);
            TESHair* pHairForm = dynamic_cast<TESHair*>(::FUN_004839c0(_id));
            if (pHairForm)
                reinterpret_cast<::FUN_006031e0_shell *>(this)->SetHair(pHairForm);
            else
                ::FUN_005b5e40();
            break;
        }
        case 0x4D414E4C /* LNAM */: {
            float fScaleMultiplier;
            apFile->GetChunkData((unsigned int*)&fScaleMultiplier);
            if (fScaleMultiplier < 0.0)
                fScaleMultiplier = 0.0f;
            if (fScaleMultiplier > 1.0)
                fScaleMultiplier = 1.0f;
            reinterpret_cast<::FUN_00601c10_shell *>(this)->FUN_00601c10(fScaleMultiplier);
            break;
        }
        case 0x4D414E45 /* ENAM */: {
            unsigned int uiEyesID;
            apFile->GetChunkData(&uiEyesID);
            ::ResolveFormID((unsigned int *)&(uiEyesID), apFile);
            TESEyes* pEyes = dynamic_cast<TESEyes*>(::FUN_004839c0(uiEyesID));
            if (pEyes)
                reinterpret_cast<::FUN_00603200_shell *>(this)->SetEyes(pEyes);
            else
                ::FUN_005b5e40();
            break;
        }
        case 0x524C4348 /* HCLR */:
        case 0x394D414E /* NAM9 */:
            apFile->GetChunkData(&iHairColor);
            break;
        case 0x4D414E43 /* CNAM */: {
            unsigned int uiClass = 0;
            apFile->GetChunkData(&uiClass);
            m_pClass = (TESClass*)(std::uintptr_t)uiClass;
            break;
        }
        case 0x4D414E5A /* ZNAM */: {
            unsigned int uiCombatStyle;
            apFile->GetChunkData(&uiCombatStyle);
            ((TESActorBase*)this)->SetCombatStyle((TESCombatStyle*)(std::uintptr_t)uiCombatStyle);
            break;
        }
        case 0x4D414E46 /* FNAM */:
            if (reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C() >= 2)
            {
                reinterpret_cast<::FUN_00472840_impl *>((((TESFileChunkData16*)apFile)))->ReadChunkData(&m_usLastRace);
                if (apFile->IsEndianConversionRequired())
                    ::FUN_00407a90((short *)(unsigned short *)(&m_usLastRace));
            }
            break;
        case 0x304D414E /* NAM0 */:
        case 0x314D414E /* NAM1 */:
        case 0x324D414E /* NAM2 */:
        case 0x334D414E /* NAM3 */:
            if (!_found)
            {
                ::FUN_005b5e40();
                _found = true;
            }
            break;
        case 0x344D414E /* NAM4 */: {
            unsigned int uiImpactMaterial;
            apFile->GetChunkData(&uiImpactMaterial);
            m_eImpactMaterial = uiImpactMaterial;
            break;
        }
        case 0x364D414E /* NAM6 */:
            apFile->GetChunkData((unsigned int*)&m_fGlyphExtent);
            break;
        case 0x374D414E /* NAM7 */:
            apFile->GetChunkData((unsigned int*)&fWeight);
            break;
        }

        if (!bContinue)
            break;
        if (!next9 && !apFile->NextChunk())
            break;
    }

    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) == 7 && (*reinterpret_cast<::NpcFaceGenQueue * *>(&::_g_thePlayer)) && !((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::NpcFaceGenQueue * *>(&::_g_thePlayer))))->FUN_007af430())))
        reinterpret_cast<::Fn575690 *>(((*reinterpret_cast<::NpcFaceGenQueue * *>(&::_g_thePlayer))))->FUN_00575690(this);

    if (!::GetShortAtOffset12((const char *)this))
        ::FUN_005b5e40();

    return true;
}

namespace fnv_00603280 {
struct FUN_00603280_Api
{
    int FUN_00401170();
    int FUN_005f0cc0();
};


// @fnv 0x00603280
void FUN_00603280(int aiFirstValue, int aiSecondValue, int pCollector)
{
    if (pCollector == 0)
    {
        return;
    }
    bool flag = true;
    while (1)
    {
        std::intptr_t pEntry = ((std::intptr_t)(reinterpret_cast<::Callees *>((((FUN_00603280_Api*)((reinterpret_cast<::Callees *>((((FUN_00603280_Api*)(*reinterpret_cast<int *>(&::g_dataHandler)))))->FUN_00726070())))))->FUN_00726070()));
        while (pEntry != 0)
        {
            if (((FUN_00603280_Api*)pEntry)->FUN_00401170() == 0x2a)
            {
                int item = pEntry;
                if (((int)(reinterpret_cast<::FUN_004ac110_shell *>((((FUN_00603280_Api*)item)))->FUN_004ac110())) == aiFirstValue &&
                    ((FUN_00603280_Api*)item)->FUN_005f0cc0() == aiSecondValue)
                {
                    if (!flag || reinterpret_cast<::TESActorBaseData *>((((FUN_00603280_Api*)(item + 0x30))))->GetFlag(4))
                    {
                        if (item != ((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((FUN_00603280_Api*)(*reinterpret_cast<int *>(&::_g_thePlayer)))))->FUN_007af430())))
                        {
                            reinterpret_cast<::FUN_00438690 *>((((FUN_00603280_Api*)pCollector)))->FUN_007cb2e0((unsigned int *)(int *)(&item));
                        }
                    }
                }
            }
            pEntry = ((std::intptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((FUN_00603280_Api*)pEntry)))->FUN_007af430()));
        }
        if (reinterpret_cast<::FUN_0076b610_Class *>((((FUN_00603280_Api*)pCollector)))->FUN_0076b610() && flag)
        {
            flag = false;
        }
        else
        {
            break;
        }
    }
    reinterpret_cast<::FUN_00729970_shell *>((((FUN_00603280_Api*)pCollector)))->FUN_00729970((int)(::FUN_00603220));
}
}  // namespace fnv_00603280

struct LevelProxy
{
    unsigned int data;
};
struct CountProxy
{
    void* items;
    unsigned int count;
};
struct AttributeProxy
{
};
struct SettingProxy
{
};
struct Context
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
    LevelProxy level;
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
    CountProxy count;
    AttributeProxy attributes;
    int ComputeAttributeValue(bool includeCount);
};
// Computes a value from level, count and attribute settings, clamping the level to at least 1 and the result to at least 0.
// @fnv 0x00603fc0
int Context::ComputeAttributeValue(bool includeCount)
{
    int a = reinterpret_cast<::FUN_0047ded0_shell *>(&(level))->FUN_0047ded0();
    if (a < 1)
        a = 1;
    int j =
        ((unsigned int)(reinterpret_cast<::Callees *>(&(count))->FUN_00726070()))
            ? (int)((includeCount ? ((unsigned int)(reinterpret_cast<::Callees *>(&(count))->FUN_00726070())) : 0) +
                    (reinterpret_cast<::FUN_005f1230_shell *>(&(attributes))->GetAttributeValue7() + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingProxy *>(&::originalRuntimeFloatSetting298))))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingProxy *>(&::originalRuntimeFloatSetting297)))))) +
                    (a - 1) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingProxy *>(&::originalRuntimeFloatSetting299)))))))
            : 0;
    if (j < 0)
        j = 0;
    return j;
}

class B6040D0Setting
{
  public:
    float* Float();
};


class B6040D0ActorBase
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
    virtual unsigned short GetBaseValue();

};

class B6040D0Attributes
{
  public:
};

class B6040D0NPC
{
  public:
    int ComputeDerivedValue(bool bUseBase);

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
    B6040D0ActorBase m_kBaseData;
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
    int unkB4;
    B6040D0Attributes m_kAttributes;
};

// @fnv 0x006040d0
int B6040D0NPC::ComputeDerivedValue(bool bUseBase)
{
    int iLevel = reinterpret_cast<::FUN_0047ded0_shell *>(&(m_kBaseData))->FUN_0047ded0();
    if (iLevel < 1)
        iLevel = 1;
    int iResult = m_kBaseData.GetBaseValue()
                      ? (int)((bUseBase ? (float)m_kBaseData.GetBaseValue() : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::B6040D0Setting *>(&::originalRuntimeFloatSetting303))))))) +
                              reinterpret_cast<::FUN_005f1230_shell *>(&(m_kAttributes))->GetAttributeValue7() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::B6040D0Setting *>(&::originalRuntimeFloatSetting304)))))) +
                              iLevel * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::B6040D0Setting *>(&::originalRuntimeFloatSetting305)))))))
                      : 0;
    if (iResult < 0)
        iResult = 0;
    return iResult;
}

struct WeightAccessor
{
};
struct FUN_00604250_shell : TESNPC
{
    void* FUN_005f0cc0();
    float GetWeight();
};
// @fnv 0x00604250
float FUN_00604250_shell::GetWeight()
{
    if (reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0() == 7)
    {
        return fWeight == ::_DAT_01012060 && ((::WeightAccessor *)(reinterpret_cast<::FUN_004ac110_shell *>(this)->FUN_004ac110())) ? reinterpret_cast<::FUN_006042d0_Owner *>((((::WeightAccessor *)(reinterpret_cast<::FUN_004ac110_shell *>(this)->FUN_004ac110()))))->GetArrValue({}) : fWeight;
    }
    return reinterpret_cast<::FUN_00944300_class *>(this)->FUN_00944300();
}

struct FUN_00605fc0_obj
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual bool vE4();
};

struct FUN_00605fc0_owner
{
};

struct FUN_00605fc0_disp
{
    bool Process(FUN_00605fc0_obj** p);
};

struct FUN_00605fc0_cls
{
    int unk00;
    void ProcessSlots(int unk08, FUN_00605fc0_owner* a2, FUN_00605fc0_disp* a3);
};

// Iterates 20 slots from a2, and for each non-null slot whose vE4() is true, calls a3->Process and a3->Release if Process returns false.
// @fnv 0x00605fc0
void FUN_00605fc0_cls::ProcessSlots(int aiUnused, FUN_00605fc0_owner* pOwner, FUN_00605fc0_disp* pDisp)
{
    for (unsigned int i = 0; i < 20; i++)
    {
        FUN_00605fc0_obj** slot = ((::FUN_00605fc0_obj **)(reinterpret_cast<::FUN_0043f220_cls *>((pOwner))->GetEntryAt(i)));
        if (*slot != 0 && (*slot)->vE4())
        {
            FUN_00605fc0_obj* obj = *slot;
            if (!reinterpret_cast<::FUN_009962f0_s *>((pDisp))->f((*(::NavMesh *const *)(&obj))))
            {
                reinterpret_cast<::FUN_00438690 *>((pDisp))->FUN_007cb2e0((unsigned int *)(::FUN_00605fc0_obj **)(&obj));
            }
        }
    }
}

// Save-size computation: four 2x2 tracked lists (count * element size each) plus fixed fields.

class SaveTrackedList
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

};

class SaveTrackedOwner
{
  public:
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
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    SaveTrackedList m_aakLists[2][2];

    unsigned short GetSaveSize(int iVersion);
};

// Sums count times element size times 4 over the 2x2 m_aakLists, adds 21 bytes of fixed fields, and returns the total as unsigned short.
// @fnv 0x00609c70
unsigned short SaveTrackedOwner::GetSaveSize(int iVersion)
{
    unsigned short usSize = 0;
    for (unsigned int i = 0; i < 2; i++)
    {
        for (unsigned int j = 0; j < 2; j++)
        {
            unsigned int ItemUpdateArray = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(m_aakLists[i][j]))->FUN_009611e0()));
            unsigned int uiElementSize = reinterpret_cast<::BGSTerrainManager *>(&(m_aakLists[i][j]))->GetMinLevel();
            usSize += ItemUpdateArray * uiElementSize * 4;
        }
    }
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 1;
    return usSize;
}

namespace fnv_0060a890 {
struct CopyBlob9
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};

struct OutBuf
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};


struct VirtHolder
{
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_00a();
    virtual void vfn_00b();
    virtual void vfn_00c();
    virtual void vfn_00d();
    virtual void vfn_00e();
    virtual void vfn_00f();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_01a();
    virtual void vfn_01b();
    virtual void vfn_01c();
    virtual void vfn_01d();
    virtual void vfn_01e();
    virtual void vfn_01f();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_02a();
    virtual void vfn_02b();
    virtual void vfn_02c();
    virtual void vfn_02d();
    virtual void vfn_02e();
    virtual void vfn_02f();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_03a();
    virtual void vfn_03b();
    virtual void vfn_03c();
    virtual void vfn_03d();
    virtual void vfn_03e();
    virtual void vfn_03f();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_04a();
    virtual void vfn_04b();
    virtual void vfn_04c();
    virtual void vfn_04d();
    virtual void vfn_04e();
    virtual void vfn_04f();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_05a();
    virtual void vfn_05b();
    virtual void vfn_05c();
    virtual void vfn_05d();
    virtual void vfn_05e();
    virtual void vfn_05f();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_06a();
    virtual void vfn_06b();
    virtual void vfn_06c();
    virtual void vfn_06d();
    virtual void vfn_06e();
    virtual void vfn_06f();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_07a();
    virtual void vfn_07b();
    virtual void vfn_07c();
    virtual void vfn_07d();
    virtual void vfn_07e();
    virtual void vfn_07f();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void vfn_082();
    virtual void vfn_083();
    virtual void vfn_084();
    virtual void vfn_085();
    virtual void vfn_086();
    virtual void vfn_087();
    virtual void vfn_088();
    virtual void vfn_089();
    virtual void vfn_08a();
    virtual void vfn_08b();
    virtual void vfn_08c();
    virtual void vfn_08d();
    virtual void vfn_08e();
    virtual void vfn_08f();
    virtual void vfn_090();
    virtual void vfn_091();
    virtual void vfn_092();
    virtual void vfn_093();
    virtual void vfn_094();
    virtual void vfn_095();
    virtual void vfn_096();
    virtual void vfn_097();
    virtual void vfn_098();
    virtual void vfn_099();
    virtual void vfn_09a();
    virtual void vfn_09b();
    virtual void vfn_09c();
    virtual void vfn_09d();
    virtual void vfn_09e();
    virtual void vfn_09f();
    virtual void vfn_0a0();
    virtual void vfn_0a1();
    virtual void vfn_0a2();
    virtual void vfn_0a3();
    virtual void vfn_0a4();
    virtual void vfn_0a5();
    virtual void vfn_0a6();
    virtual void vfn_0a7();
    virtual void vfn_0a8();
    virtual void vfn_0a9();
    virtual void vfn_0aa();
    virtual void vfn_0ab();
    virtual void vfn_0ac();
    virtual void vfn_0ad();
    virtual void vfn_0ae();
    virtual void vfn_0af();
    virtual void vfn_0b0();
    virtual void vfn_0b1();
    virtual void vfn_0b2();
    virtual void vfn_0b3();
    virtual void vfn_0b4();
    virtual void vfn_0b5();
    virtual void vfn_0b6();
    virtual void vfn_0b7();
    virtual void vfn_0b8();
    virtual void vfn_0b9();
    virtual void vfn_0ba();
    virtual void vfn_0bb();
    virtual void vfn_0bc();
    virtual void vfn_0bd();
    virtual void vfn_0be();
    virtual void vfn_0bf();
    virtual void vfn_0c0();
    virtual void vfn_0c1();
    virtual void vfn_0c2();
    virtual void vfn_0c3();
    virtual void vfn_0c4();
    virtual void vfn_0c5();
    virtual void vfn_0c6();
    virtual void vfn_0c7();
    virtual void vfn_0c8();
    virtual void vfn_0c9();
    virtual void vfn_0ca();
    virtual void vfn_0cb();
    virtual void vfn_0cc();
    virtual void vfn_0cd();
    virtual void vfn_0ce();
    virtual void vfn_0cf();
    virtual void vfn_0d0();
    virtual void vfn_0d1();
    virtual void vfn_0d2();
    virtual void vfn_0d3();
    virtual void vfn_0d4();
    virtual void vfn_0d5();
    virtual void vfn_0d6();
    virtual void vfn_0d7();
    virtual void vfn_0d8();
    virtual void vfn_0d9();
    virtual void vfn_0da();
    virtual void vfn_0db();
    virtual void vfn_0dc();
    virtual void vfn_0dd();
    virtual void vfn_0de();
    virtual void vfn_0df();
    virtual void vfn_0e0();
    virtual void vfn_0e1();
    virtual void vfn_0e2();
    virtual void vfn_0e3();
    virtual void vfn_0e4();
    virtual void vfn_0e5();
    virtual void vfn_0e6();
    virtual void vfn_0e7();
    virtual void vfn_0e8();
    virtual void vfn_0e9();
    virtual void vfn_0ea();
    virtual void vfn_0eb();
    virtual void vfn_0ec();
    virtual void vfn_0ed();
    virtual void vfn_0ee();
    virtual void vfn_0ef();
    virtual void vfn_0f0();
    virtual void vfn_0f1();
    virtual void vfn_0f2();
    virtual void vfn_0f3();
    virtual void vfn_0f4();
    virtual void vfn_0f5();
    virtual void vfn_0f6();
    virtual void vfn_0f7();
    virtual void vfn_0f8();
    virtual void vfn_0f9();
    virtual void vfn_0fa();
    virtual void vfn_0fb();
    virtual void vfn_0fc();
    virtual void vfn_0fd();
    virtual void vfn_0fe();
    virtual void vfn_0ff();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_10a();
    virtual void vfn_10b();
    virtual void vfn_10c();
    virtual void vfn_10d();
    virtual void vfn_10e();
    virtual void vfn_10f();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119(int a);
};

struct ProcessHost
{
    void* FUN_0056fac0(OutBuf* out, CopyBlob9* blob);
    void FUN_0060a890(int a1);
};

// @fnv 0x0060a890
void ProcessHost::FUN_0060a890(int pObject)
{
    CopyBlob9 blob;
    (*reinterpret_cast<unsigned char *>(&::DAT_011c5cb4)) = 1;
    ((VirtHolder*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((ProcessHost*)pObject)))->GetBaseTexture())))->vfn_119(pObject);
    (*reinterpret_cast<unsigned char *>(&::DAT_011c5cb4)) = 0;
    if (pObject == (*reinterpret_cast<int *>(&::_g_thePlayer)))
    {
        OutBuf out;
        std::intptr_t x;
        std::intptr_t y;
        std::intptr_t p;
        x = (std::intptr_t)((void *)(reinterpret_cast<::FUN_00950bb0_shell *>((((ProcessHost*)(*reinterpret_cast<int *>(&::_g_thePlayer)))))->FUN_00950bb0(1)));
        y = x != 0 ? x : 0;
        p = y != 0 ? (int)((void *)(reinterpret_cast<::S_FUN_0045bc00 *>((((ProcessHost*)y)))->FUN_0045bc00(0))) : 0;
        blob = *(CopyBlob9*)&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448));
        if (p != 0)
        {
            reinterpret_cast<::FUN_0043fa80_s *>((((ProcessHost*)p)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(((ProcessHost*)(*reinterpret_cast<int *>(&::_g_thePlayer)))->FUN_0056fac0(&out, &blob))));
        }
    }
}
}  // namespace fnv_0060a890


struct FaceCoordinateRange
{
    int referenceCount;
    int allocationCount;
    int stride;
    int* begin;
    int* end;
};

struct FaceCoordinateCursor
{
    int owner;
    int* current;
    FaceCoordinateCursor* Advance(int count);
};
// @fnv 0x0060b8e0
void* FUN_0060b8e0_shell::FUN_0060b8e0(int a)
{
    reinterpret_cast<::FaceCoordinateCursor *>(this)->Advance(a);
    return this;
}

// Checks the cursor is valid and that advancing by count stays within the range, then advances current by count and returns this.
// @fnv 0x0060b900
FaceCoordinateCursor* FaceCoordinateCursor::Advance(int count)
{
    if (!reinterpret_cast<::FUN_005ca4f0_shell *>(this)->FUN_005ca4f0())
    {
        std::abort();
    }
    do
    {
    } while (false);

    if (current + count > ((::FaceCoordinateRange *)(reinterpret_cast<::S_0060b980 *>(this)->FUN_0060b980()))->end || current + count < ((::FaceCoordinateRange *)(reinterpret_cast<::S_0060b980 *>(this)->FUN_0060b980()))->begin)
    {
        std::abort();
    }
    do
    {
    } while (false);

    current += count;
    return this;
}

struct FaceSetting
{
};
struct FaceRace;
struct RaceLink
{
};
struct FaceRace
{
};
struct FaceMatrixLocal
{
    FaceMatrixLocal();
    ~FaceMatrixLocal();
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
};
struct HeadPointer
{
    HeadPointer& operator=(void*);
};
struct FaceNpc
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    RaceLink race;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    HeadPointer head;
    int FUN_005f0cc0();
    void RandomizeFace(bool, bool, bool);
};
// Builds a face matrix from the race data, randomizes age/shape/other values unless kept, clamps them, and applies the result to the head if it differs.
// @fnv 0x00601830
void FaceNpc::RandomizeFace(bool keepAge, bool keepShape, bool keepOther)
{
    FaceMatrixLocal source9[2][2];
    FaceMatrixLocal _result[2][2];
    float first2, second, value, other7;
    ::BSFaceGenManager::InitializeFaceGenCoordinates((::FaceGenCoordinates *)(_result));
    ::FUN_00652fc0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FaceSetting *>(&::originalRuntimeFloatSetting46)))))), (std::intptr_t)(((void *)(reinterpret_cast<::S9fb0 *>((((::FaceRace *)(reinterpret_cast<::Callees *>(&(race))->FUN_00726070()))))->FUN_005d9fb0(FUN_005f0cc0())))), (std::intptr_t)(source9));
    first2 = ::FUN_00652440((std::intptr_t)(source9), 0, 0);
    second = ::FUN_00652440((std::intptr_t)(source9), 0, 1);
    if (keepAge)
        value = first2;
    else
        value = ::RandomFloat0To1() * 50.0 + 15.0;
    other7 = second - (first2 - value);
    value = FUN_0040ebd0(FUN_00404010(value, 15.0f), 65.0f);
    other7 = FUN_0040ebd0(FUN_00404010(other7, 15.0f), 65.0f);
    ::FUN_00652470((std::intptr_t)(source9), 0, 0, value);
    ::FUN_00652470((std::intptr_t)(source9), 0, 1, other7);
    first2 = ::FUN_00652440((std::intptr_t)(source9), 1, 0);
    second = ::FUN_00652440((std::intptr_t)(source9), 1, 1);
    if (keepShape)
    {
        value = first2;
        other7 = second;
    }
    else
    {
        value = ::RandomFloat0To1() * 4.0 - 2.0;
        other7 = second - (first2 - value);
    }
    value = FUN_0040ebd0(FUN_00404010(value, -2.0f), 2.0f);
    other7 = FUN_0040ebd0(FUN_00404010(other7, -2.0f), 2.0f);
    ::FUN_00652470((std::intptr_t)(source9), 1, 0, value);
    ::FUN_00652470((std::intptr_t)(source9), 1, 1, other7);
    if (!keepOther)
        reinterpret_cast<::FUN_00601c10_shell *>(this)->FUN_00601c10(::RandomFloat0To1());
    ::FUN_00652e00((MatrixProxy (*)[2])(void *)(((void *)(reinterpret_cast<::S9fb0 *>((((::FaceRace *)(reinterpret_cast<::Callees *>(&(race))->FUN_00726070()))))->FUN_005d9fb0(FUN_005f0cc0())))), (MatrixProxy (*)[2])(source9), (MatrixProxy (*)[2])(_result), 0);
    if (::fnv_00652900::FUN_00652900((const fnv_00652900::FaceGenMatrix<float> (*)[2])(_result), (fnv_00652900::FaceGenMatrix<float> (*)[2])(void *)(reinterpret_cast<::FUN_00601800_shell *>(this)->FUN_00601800())))
    {
        ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(_result), (FaceGenCoordArray (*)[2])(void *)(reinterpret_cast<::FUN_00601800_shell *>(this)->FUN_00601800()), 0, 0);
        head = 0;
    }
}

#include <string.h>

struct NPCCompare : TESNPC
{
    bool IsDifferentFrom(TESForm* form);
};
struct HeadPartCompare : HeadPartNode
{
    unsigned int FUN_005ae380();
};

// Compares this NPC against another TESNPC, returning true if any class, hair, head part, combat style or related field differs.
// @fnv 0x00603880
bool NPCCompare::IsDifferentFrom(TESForm* form)
{
    TESNPC* npc = dynamic_cast<TESNPC*>(form);
    if (!npc)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(npc))
        return true;
    if (memcmp(&data, ((::ActorSkillData *)(reinterpret_cast<::FUN_00634890_shell *>((npc))->GetTextureManager())), sizeof(data)))
        return true;
    if (m_pClass != ((::TESClass *)(reinterpret_cast<::MiddleHighProcess *>((npc))->GetSceneRoot())))
        return true;
    if (m_pHair != npc->GetHair())
        return true;
    if (m_fHairLength != reinterpret_cast<::FUN_00602130_shell *>((npc))->FUN_00602130())
        return true;
    if (m_pEyes != ((::TESEyes *)(reinterpret_cast<::MiddleHighProcess *>((npc))->GetAnimation())))
        return true;
    if (iHairColor != reinterpret_cast<::FUN_004169d0_shell *>((npc))->FUN_004169d0())
        return true;
    if (::fnv_00652900::FUN_00652900((const fnv_00652900::FaceGenMatrix<float> (*)[2])(void *)(reinterpret_cast<FUN_00601800_shell*>(this)->FUN_00601800()),
                     (fnv_00652900::FaceGenMatrix<float> (*)[2])(void *)(static_cast<FUN_00601800_shell*>(npc)->FUN_00601800())))
        return true;
    if (GetCombatStyle() != npc->GetCombatStyle())
        return true;
    if (vfn_58() != npc->vfn_58())
        return true;
    if (reinterpret_cast<HeadPartCompare*>(((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>(this)->FUN_00602170())))->FUN_005ae380() !=
        reinterpret_cast<HeadPartCompare*>(((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>((npc))->FUN_00602170())))->FUN_005ae380())
        return true;
    HeadPartNode* node = reinterpret_cast<HeadPartNode*>(((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>(this)->FUN_00602170())));
    while (node && !node->FUN_008256d0())
    {
        if (!reinterpret_cast<::RefList *>((reinterpret_cast<HeadPartCompare*>(((::BSSimpleList< ::BGSHeadPart *> *)(reinterpret_cast<::FUN_00602170_shell *>((npc))->FUN_00602170())))))->FUN_005f65d0((void **)&(*((::GameForm **)((void *)(node))))))
            return true;
        node = ((::HeadPartNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    if (m_fGlyphExtent != npc->m_fGlyphExtent)
        return true;
    if (fWeight != npc->fWeight)
        return true;
    return false;
}

extern const char str_0104a714[], str_0104a704[], str_0104a6cc[], str_0104a694[], str_0104a660[];
int __cdecl FUN_004564f0(const char*, const char*, unsigned int);
struct FileName
{
};
struct RaceID
{
};
struct GenderQuery
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
    virtual bool v2c();
};
struct ActorStand;
struct FUN_0076b630;
struct Target
{
    unsigned int unknown_000;
    unsigned int unknown_004;
    unsigned int unknown_008;
    unsigned int unknown_00c;
    unsigned int unknown_010;
    unsigned int unknown_014;
    unsigned int unknown_018;
    unsigned int unknown_01c;
    unsigned int unknown_020;
    unsigned int unknown_024;
    unsigned int unknown_028;
    unsigned int unknown_02c;
    GenderQuery actorData;
    unsigned int unknown_034;
    unsigned int unknown_038;
    unsigned int unknown_03c;
    unsigned int unknown_040;
    unsigned int unknown_044;
    unsigned int unknown_048;
    unsigned int unknown_04c;
    unsigned int unknown_050;
    unsigned int unknown_054;
    unsigned int unknown_058;
    unsigned int unknown_05c;
    unsigned int unknown_060;
    unsigned int unknown_064;
    unsigned int unknown_068;
    unsigned int unknown_06c;
    unsigned int unknown_070;
    unsigned int unknown_074;
    unsigned int unknown_078;
    unsigned int unknown_07c;
    unsigned int unknown_080;
    unsigned int unknown_084;
    unsigned int unknown_088;
    unsigned int unknown_08c;
    unsigned int unknown_090;
    unsigned int unknown_094;
    unsigned int unknown_098;
    unsigned int unknown_09c;
    unsigned int unknown_0a0;
    unsigned int unknown_0a4;
    unsigned int unknown_0a8;
    unsigned int unknown_0ac;
    unsigned int unknown_0b0;
    unsigned int unknown_0b4;
    unsigned int unknown_0b8;
    unsigned int unknown_0bc;
    unsigned int unknown_0c0;
    unsigned int unknown_0c4;
    unsigned int unknown_0c8;
    unsigned int unknown_0cc;
    unsigned int unknown_0d0;
    unsigned int unknown_0d4;
    unsigned int unknown_0d8;
    unsigned int unknown_0dc;
    unsigned int unknown_0e0;
    unsigned int unknown_0e4;
    unsigned int unknown_0e8;
    unsigned int unknown_0ec;
    unsigned int unknown_0f0;
    unsigned int unknown_0f4;
    unsigned int unknown_0f8;
    unsigned int unknown_0fc;
    unsigned int unknown_100;
    unsigned int unknown_104;
    unsigned int unknown_108;
    unsigned int unknown_10c;
    unsigned int unknown_110;
    unsigned int unknown_114;
    unsigned int unknown_118;
    unsigned int unknown_11c;
    unsigned int unknown_120;
    unsigned int unknown_124;
    unsigned int unknown_128;
    unsigned int unknown_12c;
    unsigned int unknown_130;
    unsigned int unknown_134;
    unsigned int unknown_138;
    unsigned int unknown_13c;
    unsigned int unknown_140;
    unsigned int unknown_144;
    unsigned int unknown_148;
    unsigned int unknown_14c;
    unsigned int unknown_150;
    unsigned int unknown_154;
    unsigned int unknown_158;
    unsigned int unknown_15c;
    unsigned int unknown_160;
    unsigned int unknown_164;
    unsigned int unknown_168;
    unsigned int unknown_16c;
    unsigned int unknown_170;
    unsigned int unknown_174;
    unsigned int unknown_178;
    unsigned int unknown_17c;
    unsigned int unknown_180;
    unsigned int unknown_184;
    unsigned int unknown_188;
    unsigned int unknown_18c;
    unsigned int unknown_190;
    unsigned int unknown_194;
    unsigned int unknown_198;
    unsigned int unknown_19c;
    unsigned int unknown_1a0;
    unsigned int unknown_1a4;
    unsigned int unknown_1a8;
    unsigned int unknown_1ac;
    unsigned int unknown_1b0;
    unsigned int unknown_1b4;
    unsigned int unknown_1b8;
    unsigned int unknown_1bc;
    unsigned int unknown_1c0;
    unsigned int unknown_1c4;
    unsigned int unknown_1c8;
    unsigned int unknown_1cc;
    unsigned int unknown_1d0;
    unsigned int unknown_1d4;
    unsigned int unknown_1d8;
    unsigned int unknown_1dc;
    unsigned int unknown_1e0;
    unsigned int unknown_1e4;
    unsigned int unknown_1e8;
    unsigned int unknown_1ec;
    Target* m_pTemplateNPC;

    bool FUN_00604310(const char*, char*, unsigned int);
    int FUN_005f0cc0();
public:
    ::FUN_0076b630 *SelectBestWeapon(::ActorStand *, float *, int, bool);
public:
    ::FUN_0076b630 *FUN_004c8c10(int, int);
};
// Removes worn items, equips best armor and weapon for the given refr, and updates the actor's process state.
// @fnv 0x006047c0
void TESNPC::UpdateModel3D(TESObjectREFR* refr, bool armor, bool weapon, bool update, bool allowChanges)
{
    struct DefaultEquipmentState
    {
        InventoryStackRecord* pArmorItem;
        ExtraDataList* pExtraData;
        Actor* pActorRefr;
        TESBipedModelForm* pBodyModel;
    } equipment;
    bool bPreviousChanges = true;
    if (!allowChanges)
        bPreviousChanges = reinterpret_cast<::FUN_004623f0_shell *>((::g_BGSSaveLoadGame))->FUN_004623f0(false);
    if (refr->IsActor())
        reinterpret_cast<::BipedAnim *>((refr))->AttachFaceGenNode();
    InventoryChanges* inventory = ::InventoryChanges::CreateForReference(refr);
    reinterpret_cast<::FUN_004bfe50_t *>((inventory))->RemoveWornItems(true, refr);
    equipment.pActorRefr = static_cast<Actor*>(refr);
    if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((equipment.pActorRefr))->GetBaseTexture())))
    {
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((equipment.pActorRefr))->GetBaseTexture()))->SetCurrentAmmunition(0);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((equipment.pActorRefr))->GetBaseTexture()))->SetCurrentShield(0);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((equipment.pActorRefr))->GetBaseTexture()))->SetCurrentTorch(0);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((equipment.pActorRefr))->GetBaseTexture()))->SetCurrentArmor(0, 0, false);
    }
    equipment.pBodyModel = 0;
    equipment.pExtraData = 0;
    for (int iBipedObject = 0; iBipedObject < 20; ++iBipedObject)
    {
        equipment.pArmorItem = reinterpret_cast<::FUN_004c8220_shell *>((inventory))->FUN_004c8220(this, iBipedObject, true);
        if (equipment.pArmorItem)
        {
            bool bShouldEquip = true;
            TESBoundObject* pItemObject = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((equipment.pArmorItem))->GetName()));
            if ((!equipment.pBodyModel || !equipment.pBodyModel->HasBipedModel((::BIPED_OBJECT)(iBipedObject), false, (::BGSBipedModelList *)(void *)(0))) &&
                !reinterpret_cast<::Thing575 *>((refr))->FUN_00575400((int)(pItemObject)))
            {
                if (((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(equipment.pArmorItem)))))
                    equipment.pExtraData = ((((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(equipment.pArmorItem)))))->m_item);
                else
                    equipment.pExtraData = 0;
                if (iBipedObject == 2)
                    equipment.pBodyModel = dynamic_cast<TESBipedModelForm*>(pItemObject);
                else
                {
                    TESBipedModelForm* pBipedModel = ::TESBipedModelForm::GetFormAsBipedModel(pItemObject);
                    if (pBipedModel->HasBipedModel((::BIPED_OBJECT)(2), false, (::BGSBipedModelList *)(void *)(0)))
                        bShouldEquip = false;
                }
                if (bShouldEquip)
                    refr->EquipItem(pItemObject, 1, equipment.pExtraData, false);
            }
            delete equipment.pArmorItem;
            equipment.pArmorItem = 0;
        }
    }
    if (weapon && !refr->HasHealth(false))
    {
        float fValue = 0.0f;
        InventoryStackRecord* pArmorItem = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((inventory))->SelectBestWeapon((::ActorStand *)(::TESActorBase *)(this), &fValue, 6, true)));
        if (pArmorItem)
        {
            bool bDeleteItem = true;
            if (!reinterpret_cast<::Thing575 *>((refr))->FUN_00575400((int)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pArmorItem))->GetName())))))
            {
                ExtraDataList* pExtraData = 0;
                if (((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(pArmorItem)))))
                {
                    pExtraData = ((((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(pArmorItem)))))->m_item);
                    bDeleteItem = false;
                }
                else
                    pExtraData = 0;
                Actor* pActorRefr = static_cast<Actor*>(refr);
                reinterpret_cast<::fnv_0088c830::ThisC *>((pActorRefr))->FUN_0088c830((::fnv_0088c830::FormC *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pArmorItem))->GetName()))), ((int)(reinterpret_cast<::Callees *>((pArmorItem))->FUN_00726070())), pExtraData, true, false,
                                        true);
                if (bDeleteItem)
                    delete pArmorItem;
            }
            else if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((static_cast<Actor*>(refr)))->GetBaseTexture())) &&
                     ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pArmorItem))->GetName())) != reinterpret_cast<::FUN_008a1710_shell *>((static_cast<Actor*>(refr)))->FUN_008a1710())
                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((static_cast<Actor*>(refr)))->GetBaseTexture()))->SetCurrentArmor(pArmorItem, refr->GetNiNode(), false);
        }
    }
    if (!allowChanges)
        reinterpret_cast<::FUN_004623f0_shell *>((::g_BGSSaveLoadGame))->FUN_004623f0(bPreviousChanges);
    if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((equipment.pActorRefr))->GetBaseTexture())))
        reinterpret_cast<::ActorSpellView *>((equipment.pActorRefr))->UpdateSpells(true);
}
// @fnv 0x006062e0
void TESNPC::AttachHeadParts(TESObjectREFR* refr, NiNode* node)
{
    if (!node)
        node = reinterpret_cast<NiNode*>(((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((refr))->FUN_0043fcd0())));
    if (!node)
        return;
    struct HeadDisplayContext
    {
        NiAVObject* hair;
        InventoryChanges* inventory;
        InventoryStackRecord* wornItem;
        NiAVObject* biped;
        NiAVObject* skinned;
    } context;
    context.biped = ::FUN_004aae30(node, (::NiFixedString *)("BSFaceGenNiNodeBiped"));
    context.skinned = ::FUN_004aae30(node, (::NiFixedString *)("BSFaceGenNiNodeSkinned"));
    if (!context.biped || !context.skinned)
        return;
    context.inventory = ::InventoryChanges::CreateForReference(refr);
    context.wornItem = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((context.inventory))->FUN_004c8c10(0, false)));
    if (context.wornItem)
    {
        reinterpret_cast<::TaskQueueInterface *>((context.biped))->QueueActorDisarm(true);
        reinterpret_cast<::TaskQueueInterface *>((context.skinned))->QueueActorDisarm(true);
        delete context.wornItem;
        context.wornItem = 0;
        return;
    }
    reinterpret_cast<::TaskQueueInterface *>((context.biped))->QueueActorDisarm(false);
    reinterpret_cast<::TaskQueueInterface *>((context.skinned))->QueueActorDisarm(false);
    context.hair = ::FUN_004aae30(node, (::NiFixedString *)(((const char *)(::FUN_00605d40(true)))));
    {
        char hairName[32];
        NiAVObject* hair[2];
        for (int i = 0; i < 2; ++i)
            hair[i] = ::FUN_004aae30(node, (::NiFixedString *)(BSFaceGenManager::BuildFaceGenPartPath(hairName, i)));
        bool bHairHidden = false;
        bool bHatVisible = true;
        context.wornItem = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((context.inventory))->FUN_004c8c10(1, false)));
        if (context.wornItem)
        {
            delete context.wornItem;
            context.wornItem = 0;
            bHairHidden = true;
        }
        if (hair[1])
        {
            context.wornItem = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((context.inventory))->FUN_004c8c10(10, false)));
            if (context.wornItem)
            {
                delete context.wornItem;
                context.wornItem = 0;
                bHatVisible = false;
                bHairHidden = true;
            }
        }
        if (context.hair)
            reinterpret_cast<::TaskQueueInterface *>((context.hair))->QueueActorDisarm(bHairHidden);
        for (int i = 0; i < 2; ++i)
            if (hair[i])
            {
                if (i == 0)
                    reinterpret_cast<::TaskQueueInterface *>((hair[i]))->QueueActorDisarm(bHairHidden);
                else
                    reinterpret_cast<::TaskQueueInterface *>((hair[i]))->QueueActorDisarm(bHatVisible);
            }
    }
}
// @fnv 0x00606050
void FUN_00606050_shell::InitWornObjects(TESObjectREFR* apRef, BipedAnim* apBipedAnim)
{
    InventoryChanges* pinv = ::InventoryChanges::CreateForReference(apRef);
    InventoryStackRecord* pitem;
    InventoryStackRecord* pshield;
    InventoryStackRecord* ptorch = 0;
    pshield = 0;
    TESBoundObject* pobj;
    Actor* apactor = dynamic_cast<Actor*>(apRef);
    if (!apRef || !apBipedAnim)
        return;

    for (int i = 0; i <= 21; ++i)
    {
        if (i == 3 || i == 5)
        {
            ++i;
        }
        else if (i == 20)
        {
            i = 3;
        }
        else if (i == 21)
        {
            i = 5;
        }

        pitem = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((pinv))->FUN_004c8c10(i, false)));
        if (pitem)
        {
            pobj = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pitem))->GetName()));
            delete pitem;
            if (pobj)
            {
                if (!((bool(*)(TESNPC*, TESObjectREFR*, BipedAnim*, TESBoundObject*))FUN_006061b0)(
                        this, apRef, apBipedAnim, pobj))
                {
                    ::FUN_005b5e40(
                        );
                }
            }
        }

        if (i == 3)
        {
            i = 20;
        }
        else if (i == 5)
        {
            i = 21;
        }
    }
}
// @fnv 0x006062e0
void FUN_006062e0_shell::UpdateFaceGenHairVisibility(TESObjectREFR* apRef, NiNode* apNode)
{
    NiAVObject* pheadSkinned;
    NiAVObject* pheadBiped5;
    InventoryStackRecord* pitem7;
    InventoryChanges* pinv5;
    NiAVObject* pearsObj9;

    if (apNode == 0)
        apNode = reinterpret_cast<NiNode*>(((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apRef))->FUN_0043fcd0())));

    if (apNode == 0)
        return;

    pheadBiped5 = ::FUN_004aae30(apNode, (::NiFixedString *)("BSFaceGenNiNodeBiped"));
    pheadSkinned = ::FUN_004aae30(apNode, (::NiFixedString *)("BSFaceGenNiNodeSkinned"));

    if (pheadBiped5 == 0 || pheadSkinned == 0)
        return;

    {
        bool bhideHair9;
        bool bhideHatHair7;
        NiAVObject* phairObjX[2];
        char tempHairName4[32];

        pinv5 = ::InventoryChanges::CreateForReference(apRef);
        pitem7 = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((pinv5))->FUN_004c8c10(0, false)));

        if (pitem7 != 0)
        {
            reinterpret_cast<::TaskQueueInterface *>((pheadBiped5))->QueueActorDisarm(true);
            reinterpret_cast<::TaskQueueInterface *>((pheadSkinned))->QueueActorDisarm(true);
            delete pitem7;
            pitem7 = 0;
            return;
        }

        reinterpret_cast<::TaskQueueInterface *>((pheadBiped5))->QueueActorDisarm(false);
        reinterpret_cast<::TaskQueueInterface *>((pheadSkinned))->QueueActorDisarm(false);

        pearsObj9 = ::FUN_004aae30(apNode, (::NiFixedString *)(((const char *)(::FUN_00605d40(true)))));

        for (int i = 0; i < 2; ++i)
            phairObjX[i] =
                ::FUN_004aae30(apNode, (::NiFixedString *)(BSFaceGenManager::BuildFaceGenPartPath(tempHairName4, i)));

        bhideHair9 = false;
        bhideHatHair7 = true;

        pitem7 = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((pinv5))->FUN_004c8c10(1, false)));
        if (pitem7 != 0)
        {
            delete pitem7;
            pitem7 = 0;
            bhideHair9 = true;
        }

        if (phairObjX[1] != 0)
        {
            pitem7 = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((pinv5))->FUN_004c8c10(10, false)));
            if (pitem7 != 0)
            {
                delete pitem7;
                pitem7 = 0;
                bhideHatHair7 = false;
                bhideHair9 = true;
            }
        }

        if (pearsObj9 != 0)
            reinterpret_cast<::TaskQueueInterface *>((pearsObj9))->QueueActorDisarm(bhideHair9);

        for (int i = 0; i < 2; ++i)
        {
            if (phairObjX[i] != 0)
            {
                if (i == 0)
                    reinterpret_cast<::TaskQueueInterface *>((phairObjX[i]))->QueueActorDisarm(bhideHair9);
                else
                    reinterpret_cast<::TaskQueueInterface *>((phairObjX[i]))->QueueActorDisarm(bhideHatHair7);
            }
        }
    }
}
// @fnv 0x00604310
bool Target::FUN_00604310(const char* extension, char* output, unsigned int length)
{
    if (m_pTemplateNPC)
    {
        Target* face = static_cast<Target*>(m_pTemplateNPC);
        while (face && ((::Target *)(reinterpret_cast<::FUN_006044c0_shell *>((face))->FUN_006044c0())))
            face = ((::Target *)(reinterpret_cast<::FUN_006044c0_shell *>((face))->FUN_006044c0()));
        return face->FUN_00604310(extension, output, length);
    }
    FileName* file = ((::FileName *)(reinterpret_cast<::TESForm *>(this)->GetOwnerMaster()));
    if (!file)
        return false;
    unsigned int npcID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) & 0x00ffffffu;
    unsigned int raceID6 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RaceID *)(reinterpret_cast<::FUN_004ac110_shell *>(this)->FUN_004ac110()))))->FUN_0084e3a0())) & 0x00ffffffu;
    bool master = false;
    if (!FUN_004564f0(((const char *)(reinterpret_cast<::BGSCameraPath *>((file))->GetShotList())), str_0104a714, 6))
        master = true;
    if (actorData.v2c())
    {
        if (FUN_005f0cc0() == 1)
        {
            ::FUN_00406d00(output, length, str_0104a6cc, !master ? ((const char *)(reinterpret_cast<::BGSCameraPath *>((file))->GetShotList())) : str_0104a704, raceID6, npcID,
                         extension);
        }
        else
        {
            ::FUN_00406d00(output, length, str_0104a694, !master ? ((const char *)(reinterpret_cast<::BGSCameraPath *>((file))->GetShotList())) : str_0104a704, raceID6, npcID,
                         extension);
        }
    }
    else
    {
        ::FUN_00406d00(output, length, str_0104a660, !master ? ((const char *)(reinterpret_cast<::BGSCameraPath *>((file))->GetShotList())) : str_0104a704, npcID, extension);
    }
    return true;
}

struct CopyNpc;

struct BaseFormRecord
{
    int tag;
};

struct CopyPrefix
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void slot4();

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void slot8();

    virtual void slot9();

    virtual void slot10();

    virtual void slot11();

    virtual void slot12();

    virtual void slot13();

    virtual void slot14();

    virtual void slot15();

    virtual void slot16();

    virtual void slot17();

    virtual void slot18();

    virtual void slot19();

    virtual void slot20();

    virtual void slot21();

    virtual void slot22();

    virtual void slot23();

    virtual void slot24();

    virtual void slot25();

    virtual void slot26();

    virtual void slot27();

    virtual void slot28();

    virtual void slot29();

    virtual void slot30();

    virtual void slot31();

    virtual void slot32();

    virtual void slot33();

    virtual void slot34();

    virtual void slot35();

    virtual void slot36();

    virtual void slot37();

    virtual void slot38();

    virtual void slot39();

    virtual void slot40();

    virtual void slot41();

    virtual void slot42();

    virtual void slot43();

    virtual void slot44();

    virtual void slot45();

    virtual void slot46();

    virtual void slot47();

    virtual void slot48();

    virtual void slot49();

    virtual void slot50();

    virtual void slot51();

    virtual void slot52();

    virtual void slot53();

    virtual void slot54();

    virtual void slot55();

    virtual void slot56();

    virtual void slot57();

    virtual void slot58();

    virtual void slot59();

    virtual void slot60();

    virtual void slot61();

    virtual void slot62();

    virtual void slot63();

    virtual void slot64();

    virtual void slot65();

    virtual void slot66();

    virtual void slot67();

    virtual void slot68();

    virtual void slot69();

    virtual void slot70();

    virtual void slot71();

    virtual void slot72();

    virtual void slot73();

    virtual void slot74();

    virtual void slot75();

    virtual void slot76();

    virtual void slot77();

    virtual void slot78();

    virtual void slot79();

    virtual void slot80();

    virtual bool GetFemale();

    virtual void SetFemale(bool);

    virtual void slot83();

    virtual void slot84();

    virtual void slot85();

    virtual void slot86();

    virtual void slot87();

    virtual void slot88();

    virtual void slot89();

    virtual void slot90();

    virtual void slot91();

    virtual void slot92();

    virtual void slot93();

    virtual void slot94();

    virtual void slot95();

    virtual void slot96();

    virtual void slot97();

    virtual void* GetStyle();

    virtual void SetStyle(void*);
    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    int unk020;

    int unk024;

    int unk028;

    int unk02c;

    int FUN_00401170();
};

struct CopyData
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void Reset(int);

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void slot8();

    virtual void slot9();

    virtual void slot10();

    virtual void slot11();

    virtual void slot12();

    virtual void slot13();

    virtual void slot14();

    virtual void slot15();

    virtual void slot16();

    virtual void slot17();

    virtual void slot18();

    virtual void slot19();

    virtual void slot20();

    virtual void slot21();

    virtual unsigned int GetValue();

    virtual void SetValue(unsigned int);

    virtual unsigned short GetStat();

    virtual float GetFactor();

    virtual int GetData();
    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    int unk020;

    CopyNpc* pTemplateForm;

    int unk028;

    int unk02c;

    int unk030;

    BaseFormRecord container;

    int unk038;

    int unk03c;

    BaseFormRecord touch;

    int unk044;

    int unk048;

    BaseFormRecord spell;

    int unk050;

    int unk054;

    int unk058;

    int unk05c;

    BaseFormRecord ai;

    int unk064;

    int unk068;

    int unk06c;

    int unk070;

    int unk074;

    int unk078;

    int unk07c;

    BaseFormRecord health;

    int unk084;

    BaseFormRecord attributes;

    int unk08c;

    int unk090;

    BaseFormRecord animation;

    int unk098;

    int unk09c;

    BaseFormRecord fullName;

    int unk0a4;

    int unk0a8;

    int unk0ac;

    int unk0b0;

    int unk0b4;

    int unk0b8;

    int unk0bc;

    int unk0c0;

    BaseFormRecord model;

    int unk0c8;

    int unk0cc;

    int unk0d0;

    BaseFormRecord destructible;

    int unk0d8;

    BaseFormRecord race;

    int unk0e0;

    unsigned char skills[14];
    unsigned char skillOffsets[14];

    void FUN_00604ba0(CopyPrefix*);

    unsigned int* FUN_00717e50();
};

struct CopyNpc : public CopyPrefix, public CopyData
{

    float GetWeight();
};

struct DefaultNpcValue
{
};

struct DefaultNpcManager
{
};




// Copies selected fields from a source NPC (or a default fallback) into this record according to the active copy flags, then applies the template form.
// @fnv 0x00604ba0
void CopyData::FUN_00604ba0(CopyPrefix* apSource)
{

    CopyNpc* source9;
    CopyNpc* templateForm;

    {
        unsigned short flags;

        if (!((::CopyNpc *)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType())) && !apSource)
            return;

        {

            TESNPC fallback;

            source9 = 0;

            if (!reinterpret_cast<::FUN_0047cdd0_shell *>(this)->FUN_0047cdd0())
                source9 = ((::CopyNpc *)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()));

            if (apSource && apSource->FUN_00401170() == 42)
                source9 = static_cast<CopyNpc*>(apSource);

            if (!source9)
            {

                source9 = reinterpret_cast<CopyNpc*>(&fallback);

                reinterpret_cast<::CombatProcedure *>(&(source9->race))->Initialize((::CombatController *)(*((int *)((void *)(((::DefaultNpcValue *)(::FUN_004ea950((int)((*reinterpret_cast<::DefaultNpcManager * *>(&::g_dataHandler)))))))))));

                reinterpret_cast<::FUN_00601c70_shell *>((source9))->FUN_00601c70(*((int *)((void *)(((::DefaultNpcValue *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DefaultNpcManager * *>(&::g_dataHandler))))->GetTESClassList()))))));
            }
            else if (((::CopyNpc *)(reinterpret_cast<::ActorMover *>((source9))->GetCurrentMoveModeType())) && !reinterpret_cast<::TABStub *>((source9))->FUN_0047cca0())
                source9->Reset(0);

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(9))
                reinterpret_cast<::fnv_0048cce0::FUN_0048cce0_shell *>(&(model))->CopyFromScriptableForm((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->model : 0));

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(8))
                reinterpret_cast<::TESContainer *>(&(container))->CopyFromBase((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->container : 0));

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(7))
            {

                reinterpret_cast<::FUN_004870f0_shell *>(&(fullName))->CopyFullNameFrom((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->fullName : 0));

                unsigned int ownFlags = *FUN_00717e50();
                ownFlags &= 0xef9f5df5;

                unsigned int sourceFlags4 = *source9->FUN_00717e50();
                sourceFlags4 &= 0x1060a20a;

                reinterpret_cast<::FUN_0047dd30_shell *>(this)->FUN_0047dd30(sourceFlags4 | ownFlags);
            }

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(6))
            {

                reinterpret_cast<::FUN_0047fb50_shell *>(&(animation))->FUN_0047fb50((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->animation : 0));

                reinterpret_cast<::FUN_0050eaa0_shell *>((reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))))->FUN_0050eaa0((::TESBoundObject *)(source9));

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->SetValue(source9->GetValue());

                reinterpret_cast<::TESNPC *>((reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))))->CopyActorBaseData((::TESNPC *)(source9));

                reinterpret_cast<::BGSDestructibleObjectForm *>(&(destructible))->FUN_004786e0((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->destructible : 0));
            }

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(0))
            {

                reinterpret_cast<::BGSDehydrationStage *>(this)->FUN_0050f9a0((::SpellItem *)(((reinterpret_cast<::BGSTerrainManager *>((source9))->GetMinLevel()))));

                reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>(this)->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(source9->GetData()));

                reinterpret_cast<::FlagSet *>(this)->FUN_0047dd50(true, reinterpret_cast<::TESActorBaseData *>((source9))->GetFlag(true), {});

                reinterpret_cast<::CombatProcedure *>(&(race))->Initialize((::CombatController *)(((reinterpret_cast<::Callees *>(&(source9->race))->FUN_00726070()))));

                reinterpret_cast<::FUN_009442e0_class *>((reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))))->FUN_009442e0(reinterpret_cast<::FUN_00944300_class *>((source9))->FUN_00944300());

                reinterpret_cast<::FUN_006053f0_class *>((reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))))->FUN_006053f0(reinterpret_cast<::FUN_00604250_shell *>((source9))->GetWeight());

                reinterpret_cast<::FUN_00601c70_shell *>((reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))))->FUN_00601c70(((int)(reinterpret_cast<::MiddleHighProcess *>((source9))->GetSceneRoot())));

                reinterpret_cast<::fnv_0047e1c0::S47b *>(this)->SetClampedValue(source9->GetFactor());

                reinterpret_cast<::S47 *>(this)->FUN_0047dea0(reinterpret_cast<::FUN_0047d3d0_shell *>(this)->FUN_0047d3d0());

                reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                    ->SetStyle(source9->GetStyle());
            }

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(1))
            {

                reinterpret_cast<::fnv_0047dfe0::TABStub *>(this)->FUN_0047dfe0(reinterpret_cast<::FUN_0047d370_shell *>((source9))->FUN_0047d370());

                reinterpret_cast<::TESActorBaseData *>(this)->SetMatchesPCLevel(reinterpret_cast<::FUN_00461560_shell *>((source9))->FUN_00461560());

                reinterpret_cast<::fnv_0047de40::TABStub *>(this)->FUN_0047de40(reinterpret_cast<::FUN_0047d390_shell *>((source9))->FUN_0047d390());

                reinterpret_cast<::fnv_0047de70::TABStub *>(this)->FUN_0047de70(reinterpret_cast<::FUN_0047d3b0_shell *>((source9))->FUN_0047d3b0());

                reinterpret_cast<::FUN_00480000_shell *>(&(attributes))->CopyAttributesFromComponent((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->attributes : 0));

                reinterpret_cast<::FUN_00487240_shell *>(&(health))->CopyHealthForm((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->health : 0));

                reinterpret_cast<::fnv_0047e270::FUN_0047e270_shell *>(this)->SetSpeedMult(::GetShortAtOffset12((const char *)(source9)));

                reinterpret_cast<::fnv_0047e010::TABStub *>(this)->FUN_0047e010(source9->GetStat());

                ::__memcpy(skills, source9->skills, 14);

                ::__memcpy(skillOffsets, source9->skillOffsets, 14);

                if (reinterpret_cast<::FUN_00461560_shell *>(this)->FUN_00461560())
                    reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))->SetFemale(true);

                else
                    reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))
                        ->SetFemale(source9->GetFemale());
            }

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(2))
                reinterpret_cast<::fnv_0047ca20::FUN_0047ca20_shell *>(this)->CopyFactionRanks((::TESActorBaseData *)(source9));

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(3))
            {

                reinterpret_cast<::fnv_0048d630::SpellListAccess *>(&(spell))->FUN_0048d630((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->spell : 0));

                reinterpret_cast<::FUN_0047bdd0_shell *>(&(touch))->FUN_0047bdd0((::BaseFormComponent *)(::BaseFormRecord *)(source9 ? &source9->touch : 0));
            }

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(4))
                reinterpret_cast<::TESAIForm *>(&(ai))->CopyAISettings((::TESAIForm *)(::BaseFormRecord *)(source9 ? &source9->ai : 0));

            if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40(5))
                reinterpret_cast<::TESAIForm *>(&(ai))->CopyAIPackageList((const ::TESAIForm *)(::BaseFormRecord *)(source9 ? &source9->ai : 0));

            if (reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))->GetFemale())
                reinterpret_cast<::TESNPC *>((reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))))->UpdateActorBaseData(0);

            flags = 0;

            templateForm = ((::CopyNpc *)(::FindFirstNonActorBaseTemplate(
                (::DummyVtable *)(::CopyNpc *)(reinterpret_cast<CopyNpc*>(reinterpret_cast<char*>(this) - sizeof(CopyPrefix))), &flags)));

            if (templateForm)
            {
                pTemplateForm = templateForm;
                reinterpret_cast<::FUN_0047cd90_shell *>(this)->FUN_0047cd90(flags);
            }

            reinterpret_cast<::FUN_0047ccc0_shell *>(this)->FUN_0047ccc0(true);
        }
    }
}

struct EqProcess
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44C();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45C();
    virtual void v460();
    virtual void v464();
    virtual void SetPaused(bool abPaused);
    virtual void v46C();
    virtual void Resume();
};
struct EqNode
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void vBC();
};
struct EqUpdateData
{
    float fTime;
    int iUnk04;
    int iUnk08;
    EqUpdateData(float afTime, int aiUnk04, int aiUnk08);
};
struct EqRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual EqNode* Get3D();
};
struct EqActor : EqRef
{
};
struct EqInventory
{
};
struct EqItemList
{
};
struct EqSimpleList
{
};

struct FUN_00605e70_Owner
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
    int iFlags;
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
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    EqSimpleList kList;

    void ProcessInventoryItems(EqRef* apRef, EqInventory* apInventory, EqItemList* apItems);
};

// Applies the list count to the inventory, pauses the actor's process, processes each item, resumes the process, and updates the 3D node.
// @fnv 0x00605e70
void FUN_00605e70_Owner::ProcessInventoryItems(EqRef* apRef, EqInventory* apInventory, EqItemList* apItems)
{
    EqNode* pNode;
    EqActor* pActor6;
    unsigned int i4;
    std::intptr_t iItem7;

    reinterpret_cast<::BipedAnim *>((apInventory))->UpdateRaceSex((::TESRace *)(((reinterpret_cast<::Callees *>(&(kList))->FUN_00726070()))), (::SEX)((iFlags & 1) ? 1 : 0));
    pActor6 = static_cast<EqActor*>(apRef);
    if (pActor6 && ((::EqProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor6))->GetBaseTexture())))
        ((::EqProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor6))->GetBaseTexture()))->SetPaused(true);

    for (i4 = 0; i4 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apItems))->GetName())); i4++)
    {
        iItem7 = *((int *)(reinterpret_cast<::S3e60 *>((apItems))->FUN_006a7ad0(i4)));
        reinterpret_cast<::FUN_006061b0_shell *>(this)->FUN_006061b0((::TESObjectREFR *)(apRef), (::BipedAnim *)(apInventory), (::TESBoundObject *)(iItem7));
    }

    reinterpret_cast<::TESNPC *>(this)->AttachHeadParts((::TESObjectREFR *)(apRef), (::NiNode *)(0));
    if (pActor6 && ((::EqProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor6))->GetBaseTexture())))
        ((::EqProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor6))->GetBaseTexture()))->Resume();

    reinterpret_cast<::BipedLoadAccess *>((apInventory))->UpdateBipedObjects(1);
    pNode = apRef->Get3D();
    if (pNode)
    {
        reinterpret_cast<::FUN_00a5a040_Class *>((pNode))->FUN_00a5a040();
        pNode->vBC();
        EqUpdateData kData(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((pNode))->FUN_00a59c60((std::intptr_t)&(kData));
    }
}

// Additional call contracts and named object fields used by this routine.
struct FaceObject;
struct FaceCloneProcess
{
    void* cloneMap;
    void* processMap;
    void* stringMap;
    unsigned int copyType;
    float scale;
    unsigned int flags;
    void* context;
    FaceCloneProcess(float);
    ~FaceCloneProcess();
};
struct FaceGeometryData
{
};
struct FaceSkinData
{
};
class NiSkinInstance
{
  public:
    void FUN_004addc0(NiSkinInstance*);
};
struct FaceExtraModel
{
};
struct FaceExtraData
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual FaceExtraModel* GetModelFilePath();
};
struct FaceObject
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual FaceObject* IsSceneNode();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual FaceObject* IsTriBasedGeom();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual FaceExtraModel* GetModelFilePath();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void UpdateAnimation(float, bool, bool, bool, bool, bool);
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void SetActive(bool);
    virtual void slot0d4();
    virtual void SetEnabled(bool, bool);
    virtual void AttachChildInAvailableSlot(FaceObject*, bool);
    virtual void slot0e0();
    virtual void SetGeometryData(NiAVObject*);
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual FaceObject* GetFaceAnimation();
    virtual void SetFaceAnimation(FaceObject*);
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void SetFlag114(bool);
    virtual void slot118();
    virtual void SetFlag11c(bool);
    virtual void slot120();
    virtual void slot124();
    virtual void AttachTo(FaceObject*, bool);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    TESObjectREFR* owner;
    unsigned int FUN_0043b480();
    FaceObject* GetAt(unsigned int);
    void Update(const NiUpdateData&);
};
struct FacePointerCompare
{
};
struct HeadBipedLookup
{
};
struct HeadPlayerCheck
{
};
struct HeadRefCalls
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual int HasNodeA(FaceObject*);
    virtual int HasNodeB(FaceObject*);
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual ActorAnimData* GetAnimData();
};
struct HeadRaceCalls
{
};
struct HeadMatrix
{
    float m[3][3];
    HeadMatrix();
};
struct HeadNPC : TESNPC
{
    void FUN_00606820(TESObjectREFR* ref, NiPointer<BipedAnim>* biped);
};
// @fnv 0x00606540
void TESNPC::RebuildHeadModel(TESObjectREFR* refr, BipedAnim* biped, bool rebuild)
{
    Actor* pActorRefr;
    {
        bool bFixHead;
        if (biped)
        {
            if (!rebuild)
                for (unsigned int i = 0; i < 20; ++i)
                    if (((::BIPED_OBJECT_DATA *)(reinterpret_cast<::FUN_00606800_shell *>((biped))->FUN_00606800()))[i].pObject)
                        return;
            biped->UpdateRaceSex(((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())), (SEX)((actorData.m_uiActorFlags & 1) != 0));
        }
        pActorRefr = dynamic_cast<Actor*>(refr);
        if (pActorRefr && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActorRefr))->GetBaseTexture())))
        {
            bool intact = true;
            ExtraDismemberedLimbs* limbs = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((pActorRefr))->FUN_005d43c0()))->GetDismemberedLimbs();
            if (limbs && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(limbs->parts))->GetName())) && ((::DismembermentPart *)(reinterpret_cast<::B441420Owner *>((limbs))->GetInfoAt(0))))
            {
                for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(limbs->parts))->GetName())); ++i)
                {
                    DismembermentPart* part = ((::DismembermentPart *)(reinterpret_cast<::B441420Owner *>((limbs))->GetInfoAt(i)));
                    if (!part->bIsBody && part->bDismembered)
                        intact = false;
                }
            }
            if (intact)
                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActorRefr))->GetBaseTexture()))->ResetActorModel(1);
        }
        if (!((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((refr))->FUN_0043fcd0())) || rebuild)
        {
            bool defaults = ShouldUseDefaultAppearance(refr) | rebuild;
            if (this == ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430())))
            {
                InventoryChanges* inventory = ::InventoryChanges::CreateForReference(refr);
                if (inventory)
                    for (int i = 0; i < 20; ++i)
                    {
                        InventoryStackRecord* item = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((inventory))->FUN_004c8c10(i, false)));
                        if (item)
                        {
                            defaults = false;
                            delete item;
                            item = 0;
                            break;
                        }
                    }
            }
            if (defaults)
            {
                bool bShouldEquipWeapon = true;
                TESPackage* pActorPackage = reinterpret_cast<::FUN_009344a0_shell *>((pActorRefr))->FUN_009344a0();
                if (pActorPackage && pActorPackage->GetForceUnequipWeapon())
                    bShouldEquipWeapon = false;
                reinterpret_cast<::TESNPC *>(this)->FUN_006047c0(refr, true, bShouldEquipWeapon, false, false);
            }
        }
        if (!::BipedAnim::CanLoadHiddenBipedObjects())
            reinterpret_cast<::HeadNPC *>(this)->FUN_00606820(refr, (::NiPointer< ::BipedAnim> *)(biped));
        reinterpret_cast<::FUN_00606050_shell *>(this)->InitWornObjects(refr, biped);
        bFixHead = true;
        if (biped == ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(true))))
            bFixHead = false;
        if (bFixHead)
            AttachHeadParts(refr, 0);
    }
}

// Creates and attaches the NPC head and duplicate head face geometry to the biped head node, cloning face data and updating the face animation.
// @fnv 0x00606820
void HeadNPC::FUN_00606820(TESObjectREFR* ref, NiPointer<BipedAnim>* biped)
{
    NiPointer<NiAVObject> copiedData(0);
    if (((int)(::BSFaceGenManager::GetFaceGenManager())) && (BipedAnim*)*biped && ((bool)(::FUN_0043faf0())) &&
        (ref != (TESObjectREFR*)(*reinterpret_cast<::NpcFaceGenQueue * *>(&::_g_thePlayer)) || !reinterpret_cast<::FUN_00950b30_Class *>((((HeadPlayerCheck*)(*reinterpret_cast<::NpcFaceGenQueue * *>(&::_g_thePlayer)))))->FUN_00950b30((::BipedAnim *)(biped))))
    {
        FaceObject* node1_2 = (FaceObject*)((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((ref))->FUN_0043fcd0()));
        FaceObject* aNode2 = 0;
        if (node1_2)
            aNode2 = node1_2->IsSceneNode();
        FaceObject* bipedNodeB = ((::FaceObject *)(reinterpret_cast<::BipedAnim *>((((HeadBipedLookup*)biped)))->GetBoneNode((::BIPED_BONE)(0))));
        HeadMatrix a;
        NiControllerManager* p = 0;
        if (((HeadRefCalls*)ref)->GetAnimData() && reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((HeadRefCalls*)ref)->GetAnimData()))->FUN_00496940())
            p = ((::NiControllerManager *)(::fnv_00537bd0::GetStringAtOffset((const char *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((HeadRefCalls*)ref)->GetAnimData()))->FUN_00496940()))));
        NiControllerManager* f = p;
        if (bipedNodeB && aNode2)
        {
            if (!((HeadRefCalls*)ref)->HasNodeA(bipedNodeB) && !((HeadRefCalls*)ref)->HasNodeB(bipedNodeB))
            {
                FaceObject* node9 = 0;
                FaceObject* bipedNodeVal = 0;
                FaceObject* nodeB = 0;
                NiPointer<NiAVObject> bipedNode_2(0);
                NiPointer<NiAVObject> aBipedNode(0);
                unsigned int count_2;
                unsigned int index4;
                FaceObject* node7_2;
                FaceObject* aNode5;
                if ((BSFaceGenNiNode*)m_pkPrimaryFaceGenNode)
                {
                    if ((BSFaceGenNiNode*)m_pkSecondaryFaceGenNode &&
                        ((unsigned int)(reinterpret_cast<::Callees *>((((FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)))->FUN_00726070())) <= 1)
                        node9 = (FaceObject*)(BSFaceGenNiNode*)m_pkPrimaryFaceGenNode;
                    else
                    {
                        FaceCloneProcess cloning(1.0f);
                        node9 = ((::FaceObject *)(reinterpret_cast<::A5D2C0Object *>((((FaceObject*)(BSFaceGenNiNode*)m_pkPrimaryFaceGenNode)))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(cloning))));
                    }
                    count_2 = node9->FUN_0043b480();
                    for (index4 = 0; index4 < count_2; index4++)
                    {
                        node7_2 = ((::FaceObject *)(reinterpret_cast<::NiNode *>((node9))->GetAt(index4)));
                        aNode5 = node7_2 ? node7_2->IsTriBasedGeom() : 0;
                        if (aNode5 && reinterpret_cast<::_FUN_0052aa80_shell *>((void *)(((FacePointerCompare*)&m_pkPrimaryFaceGenNode)))->operator!=((int)(node9)))
                        {
                            reinterpret_cast<::NiObjectD510 *>((((::FaceGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(aNode5))))))->FUN_00a5d510((::NiPointerD510 &)(copiedData));
                            bipedNode_2 = (NiAVObject*)copiedData;
                            if ((NiAVObject*)bipedNode_2)
                                aNode5->SetGeometryData((NiAVObject*)bipedNode_2);
                        }
                    }
                    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)(((FacePointerCompare*)&m_pkPrimaryFaceGenNode)))->operator!=((int)(node9)))
                    {
                        nodeB = ((::FaceObject *)(reinterpret_cast<::FUN_00649680 *>((node9->GetFaceAnimation()))->FUN_0064c5a0()));
                        if (nodeB)
                            node9->SetFaceAnimation(nodeB);
                    }
                }
                if ((BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)
                {
                    if (((unsigned int)(reinterpret_cast<::Callees *>((((FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)))->FUN_00726070())) <= 1)
                        bipedNodeVal = (FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode;
                    else
                    {
                        FaceCloneProcess cloning(1.0f);
                        bipedNodeVal = ((::FaceObject *)(reinterpret_cast<::A5D2C0Object *>((((FaceObject*)(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode)))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(cloning))));
                    }
                    count_2 = bipedNodeVal->FUN_0043b480();
                    for (index4 = 0; index4 < count_2; index4++)
                    {
                        node7_2 = ((::FaceObject *)(reinterpret_cast<::NiNode *>((bipedNodeVal))->GetAt(index4)));
                        aNode5 = node7_2 ? node7_2->IsTriBasedGeom() : 0;
                        if (aNode5)
                        {
                            if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)(((FacePointerCompare*)&m_pkSecondaryFaceGenNode)))->operator!=((int)(bipedNodeVal)))
                            {
                                reinterpret_cast<::NiObjectD510 *>((((::FaceGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(aNode5))))))->FUN_00a5d510((::NiPointerD510 &)(copiedData));
                                bipedNode_2 = (NiAVObject*)copiedData;
                                if ((NiAVObject*)bipedNode_2)
                                    aNode5->SetGeometryData((NiAVObject*)bipedNode_2);
                            }
                            if (((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(aNode5)))) && ((::FaceObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(aNode5)))))))))
                            {
                                FaceExtraData* extra = (FaceExtraData*)GetGeomExtraData((NiTriBasedGeom*)aNode5);
                                if (extra && extra->GetModelFilePath() && ((::NiSkinInstance *)(reinterpret_cast<::fnv_006072c0::Outer6072 *>((extra->GetModelFilePath()))->FUN_006072c0())))
                                {
                                    NiSkinInstance* l = ((::NiSkinInstance *)(reinterpret_cast<::fnv_006072c0::Outer6072 *>((extra->GetModelFilePath()))->FUN_006072c0()));
                                    NiSkinInstance* k = ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(aNode5))));
                                    FaceObject** ba = ((::FaceObject **)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((l))->FUN_00825c00()));
                                    std::uintptr_t b = ((std::uintptr_t)(reinterpret_cast<::LowProcess *>((((::FaceSkinData *)(reinterpret_cast<::TESRegionDataMap *>((l))->GetRegionMapName()))))->GetActiveCombatTarget()));
                                    for (unsigned int j = 0; j < b; j++)
                                        reinterpret_cast<::FUN_004adda0_shell *>((k))->SetBone(j, (::NiAVObject *)(ba[j]));
                                }
                                else
                                {
                                    ::FUN_005b5e40(
                                        );
                                }
                                reinterpret_cast<::NiObjectD510 *>((((FaceGeometryData*)((::FaceObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(aNode5)))))))))))->FUN_00a5d510((::NiPointerD510 &)(copiedData));
                                aBipedNode = (NiAVObject*)copiedData;
                                if ((NiAVObject*)aBipedNode)
                                    ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(aNode5))))->FUN_004addc0((NiSkinInstance*)(NiAVObject*)aBipedNode);
                            }
                        }
                    }
                    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)(((FacePointerCompare*)&m_pkSecondaryFaceGenNode)))->operator!=((int)(bipedNodeVal)))
                    {
                        if (!nodeB)
                        {
                            nodeB = ((::FaceObject *)(reinterpret_cast<::FUN_00649680 *>((bipedNodeVal->GetFaceAnimation()))->FUN_0064c5a0()));
                            if (nodeB)
                                bipedNodeVal->SetFaceAnimation(nodeB);
                        }
                        else
                            bipedNodeVal->SetFaceAnimation(nodeB);
                    }
                }
                if (!(BSFaceGenNiNode*)m_pkPrimaryFaceGenNode && !(BSFaceGenNiNode*)m_pkSecondaryFaceGenNode &&
                    ((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())))
                {
                    bool female = false;
                    reinterpret_cast<::fnv_00613c50::FUN_00613c50_C *>((((HeadRaceCalls*)((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())))))->CreateFaceGenNodes((::fnv_00613c50::FUN_006628c0_C **)&(node9), (::fnv_00613c50::FUN_006628c0_C **)&(bipedNodeVal), (::TESActorBase *)(::TESNPC *)(this), female, false, false);
                    m_usLastRace = reinterpret_cast<::FUN_00607350_shell *>((((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070()))))->FUN_00607350();
                    m_pkPrimaryFaceGenNode = (BSFaceGenNiNode*)node9;
                    m_pkSecondaryFaceGenNode = (BSFaceGenNiNode*)bipedNodeVal;
                }
                if (!node9 && !bipedNodeVal)
                    ::FUN_005b5e40();
                if (node9)
                {
                    if (node9->GetFaceAnimation() && reinterpret_cast<::HealthReferenceEntry *>((ref))->FUN_00568ad0() <= 0.0)
                    {
                        node9->GetFaceAnimation()->SetEnabled(true, true);
                        node9->GetFaceAnimation()->SetActive(true);
                    }
                    node9->SetFlag114(true);
                    node9->SetFlag11c(true);
                    reinterpret_cast<::FUN_00440460_S *>((node9))->FUN_00440460((const ::V3 *)&(::NiPoint3::ZERO));
                    reinterpret_cast<::FUN_0043fa80_s *>((node9))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448)))));
                    bipedNodeB->AttachChildInAvailableSlot(node9, true);
                    node9->owner = ref;
                    ::AddObjectToPalette((::NiAVObject *)(node9), (::NiDefaultAVObjectPalette *)(f));
                }
                if (bipedNodeVal)
                {
                    a = *(HeadMatrix*)&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448));
                    bipedNodeVal->SetFlag114(node9 == 0);
                    bipedNodeVal->SetFlag11c(node9 == 0);
                    reinterpret_cast<::FUN_00440460_S *>((bipedNodeVal))->FUN_00440460((const ::V3 *)&(::NiPoint3::ZERO));
                    aNode2->AttachChildInAvailableSlot(bipedNodeVal, true);
                    bipedNodeVal->owner = ref;
                    ::AddObjectToPalette((::NiAVObject *)(bipedNodeVal), (::NiDefaultAVObjectPalette *)(f));
                    bipedNodeVal->AttachTo(aNode2, true);
                }
                nodeB = node9 ? node9->GetFaceAnimation() : 0;
                if (!nodeB)
                    nodeB = bipedNodeVal ? bipedNodeVal->GetFaceAnimation() : 0;
                if (nodeB)
                    nodeB->UpdateAnimation(0.0f, true, true, true, true, false);
            }
            NiUpdateData update(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((aNode2))->FUN_00a59c60((std::intptr_t)&(update));
        }
        else
            ::FUN_005b5e40();
    }
}

struct FUN_00609d60_shell : public TESNPC
{
    void SerializeFaceGenData(int);
};

// @fnv 0x00609d60
void FUN_00609d60_shell::SerializeFaceGenData(int unused)
{
    unsigned int i2 = 0;
    for (; i2 < 2; ++i2)
    {
        unsigned int j = 0;
        for (; j < 2; ++j)
        {
            unsigned int rows = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(this->m_kFaceGenCoordinates[i2][j]))->FUN_009611e0()));
            unsigned int cols = reinterpret_cast<::BGSTerrainManager *>(&(this->m_kFaceGenCoordinates[i2][j]))->GetMinLevel();
            unsigned int row = 0;
            for (; row < rows; ++row)
            {
                unsigned int col = 0;
                for (; col < cols; ++col)
                {
                    float value = *((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(this->m_kFaceGenCoordinates[i2][j].FUN_0060b370(row, col)))->FUN_00629ab0({})));
                    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((((PC7d*)this)))->FUN_00484ce0((void *)((unsigned int)&value), 4);
                }
            }
        }
    }
    int hairID = 0;
    if (((::TESRace *)(reinterpret_cast<::Callees *>((void *)(this))->FUN_00726070())) != 0)
    {
        hairID = (int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TESRace *)(reinterpret_cast<::Callees *>((void *)(this))->FUN_00726070()))))->FUN_0084e3a0()));
    }
    ((FUN_00484d20_Class*)this)->ForwardToSaveLoadGame((int)(&hairID), 4);
    int raceID = 0;
    if (this->m_pHair != 0)
    {
        raceID = (int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->m_pHair))->FUN_0084e3a0()));
    }
    ((FUN_00484d20_Class*)this)->ForwardToSaveLoadGame((int)(&raceID), 4);
    int eyeID = 0;
    if (this->m_pEyes != 0)
    {
        eyeID = (int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->m_pEyes))->FUN_0084e3a0()));
    }
    ((FUN_00484d20_Class*)this)->ForwardToSaveLoadGame((int)(&eyeID), 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((((PC7d*)this)))->FUN_00484ce0((void *)((unsigned int)&this->m_fHairLength), 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((((PC7d*)this)))->FUN_00484ce0((void *)((unsigned int)&this->iHairColor), 4);
    unsigned char sex = 0;
    if (this->GetSex() == 1)
    {
        sex = 1;
    }
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((((PC7d*)this)))->FUN_00484ce0((void *)((unsigned int)&sex), 1);
}

struct BipedModelView : TESBipedModelForm
{
};
struct EnchantmentComponent : BaseFormComponent
{
    TESForm* enchantment;
    unsigned short charge;
    unsigned short castingType;
    unsigned int enchantmentFlags;
};
struct ValueComponent : BaseFormComponent
{
    int value;
};
struct WeightComponent : BaseFormComponent
{
    float weight;
};
struct ArmorModelView : TESObjectARMO
{
    TESFullName fullName;
    TESScriptableForm script;
    EnchantmentComponent enchantment;
    ValueComponent value;
    WeightComponent weight;
    TESHealthForm health;
    BipedModelView biped;
};
struct ModelPathView : TESModel
{
    virtual void vfn_10();
    virtual const char* GetModelPath();
};
struct WeaponModelView : TESObjectWEAP
{
    TESFullName fullName;
    ModelPathView model;
};
struct ContainerModelView : TESContainer
{
};
struct NPCModelView : TESBoundObject, TESActorBaseData, ContainerModelView
{
    BSSimpleList<const char*>* CollectModelPaths(bool armorModels, bool weaponModels);
};
// @fnv 0x0060af90
BSSimpleList<const char*>* NPCModelView::CollectModelPaths(bool armorModels, bool weaponModels)
{
    BSSimpleList<const char*>* models = new BSSimpleList<const char*>;
    if (armorModels)
    {
        BipedModelView* pBodyModel = 0;
        {
            int sex = reinterpret_cast<TESActorBase*>(this)->GetSex();
            {
                BipedModelView* apSlotModels[20];
                memset(apSlotModels, 0, sizeof(apSlotModels));
                for (int slot = 0; slot < 20; slot++)
                {
                    TESObjectARMO* unusedArmor = 0;
                    {
                        ArmorModelView* armor = ((::ArmorModelView *)(reinterpret_cast<::ArmorContainer *>(this)->FindBestArmorForSlot((::ArmorRater *)(::TESActorBase *)(reinterpret_cast<TESActorBase*>(this)), slot)));
                        if (armor && (!pBodyModel || !pBodyModel->HasBipedModel((::BIPED_OBJECT)(slot), false, (::BGSBipedModelList *)(void *)(0))) && !apSlotModels[slot])
                        {
                            apSlotModels[slot] = armor ? &armor->biped : 0;
                            if (apSlotModels[slot])
                            {
                                const char* pModelPath = reinterpret_cast<::FUN_004811e0_shell *>((apSlotModels[slot]))->FUN_004811e0(sex);
                                if (pModelPath)
                                    models->AddHead(pModelPath);
                            }
                            if (slot == 2)
                                pBodyModel = apSlotModels[slot];
                        }
                    }
                }
            }
        }
    }
    if (weaponModels)
    {
        WeaponModelView* weapon = ((::WeaponModelView *)(reinterpret_cast<::FUN_00482910_cls *>(this)->FindBestRecord((::FUN_00482910_obj *)(::TESActorBase *)(reinterpret_cast<TESActorBase*>(this)))));
        if (weapon)
        {
            ModelPathView* model = weapon ? &weapon->model : 0;
            if (model)
            {
                const char* pModelPath = model->GetModelPath();
                if (pModelPath)
                    models->AddHead(pModelPath);
            }
        }
    }
    return models;
}

struct IterPair
{
    void* v0;
    float* v1;
};

struct FoundPair
{
    void* v0;
    float* v1;
};

struct Facade410
{
    void* v0;
    float* v1;
};

struct Vec410
{
    FoundPair FUN_0044a1a0(void*, float*, void*, float*);
    void FUN_0060b410(unsigned int level, float value);
};
// @fnv 0x0060b340
void FR2MatrixVTCData::SetDimensions(int aiRows, int aiCols)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) = aiRows;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1c) = aiCols;
    reinterpret_cast<::S_0060b3f0 *>(this)->FUN_0060b3f0(aiRows * aiCols);
}
// @fnv 0x0060b3f0
void S_0060b3f0::FUN_0060b3f0(unsigned int auiValue)
{
    reinterpret_cast<::Vec410 *>(this)->FUN_0060b410(auiValue, 0.0f);
}

extern "C" char DAT_01186424;
extern "C" char DAT_0118627c;
extern "C" char DAT_0104a600;
struct H3370
{
    void FUN_005ae3d0(void*);
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct C3370
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
    virtual void* v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual bool v81();
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
    virtual void* v98();
    virtual void v99(void*);
    char pad[0x12c];
    void* field130;
    char pad134[0xa0];
    void* field1d4;
    char pad1d8[0x1c];
    float field1f4;
    void FUN_00603370();
};
// @fnv 0x00603370
void C3370::FUN_00603370()
{
    C3370* c;
    void* a;
    void* b;
    if (reinterpret_cast<::TESForm *>((((H3370*)this)))->GetInitialized())
        return;
    if (reinterpret_cast<::TESActorBaseData *>((((H3370*)((char*)this + 0x30))))->GetFlag(4))
    {
        c = this;
        ((H3370*)&(*reinterpret_cast<char *>(&::g_011cb764)))->FUN_005ae3d0(&c);
    }
    reinterpret_cast<::TESScriptableForm *>((((H3370*)((char*)this + 0xf4))))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::TESContainer *>((((H3370*)((char*)this + 0x64))))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::FUN_0047f4c0_shell *>((((H3370*)((char*)this + 0x90))))->FUN_0047f4c0((::TESForm *)(void *)(this));
    reinterpret_cast<::TESRaceForm *>((((H3370*)((char*)this + 0x10c))))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::ActorBaseInitItemView *>((((H3370*)((char*)this + 0x30))))->FUN_0047d8b0((::TESForm *)(void *)(this));
    reinterpret_cast<::TESSpellList *>((((H3370*)((char*)this + 0x7c))))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::BGSTouchSpellForm *>((((H3370*)((char*)this + 0x70))))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::BGSDestructibleObjectForm *>((((H3370*)((char*)this + 0x104))))->InitItem((::TESForm *)(void *)(this));
    if (field130)
    {
        a = field130;
        ::ResolveFormID((unsigned int *)(void *)(&a), (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>((((H3370*)this)))->GetFile(-1)))));
        field130 = dynamic_cast<TESClass*>(::FUN_004839c0((unsigned int)(a)));
    }
    if (v81())
        reinterpret_cast<::TESNPC *>((((H3370*)this)))->UpdateActorBaseData(false);
    if (field1d4)
    {
        b = v98();
        if (b)
        {
            ::ResolveFormID((unsigned int *)(void *)(&b), (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>((((H3370*)this)))->GetFile(-1)))));
            field1d4 = dynamic_cast<TESCombatStyle*>(::FUN_004839c0((unsigned int)(b)));
            if (!field1d4)
                ::FUN_005b5e40();
        }
    }
    if (!v98())
        v99(((::TESCombatStyle *)(::FUN_00505000())));
    if (((unsigned int)(reinterpret_cast<::Callees *>((((H3370*)((char*)this + 0xb0))))->FUN_00726070())) <= 0)
        reinterpret_cast<::FUN_00565210_shell *>((((H3370*)this)))->FUN_00565210(true);
    if (field1f4 == 0.0)
        field1f4 = reinterpret_cast<::TESNPC *>((((H3370*)this)))->GetDefaultHeight();
    reinterpret_cast<::TESForm *>((((H3370*)this)))->SetInitializationState(true);
}

class NPC_Helper : public TESNPC
{
  public:
    void InitAttributesAndSkills(bool arg1);
};

// @fnv 0x00603be0
void NPC_Helper::InitAttributesAndSkills(bool arg1)
{
    float level;
    level = 0.0f;
    if (!((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())) || !m_pClass)
        return;

    bool i;
    i = false;
    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) == 7)
        i = true;

    bool s;
    s = true;
    if (i)
    {
        if (((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d0e7c))))))->i == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TESClass *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetSceneRoot()))))->FUN_0084e3a0())))
            s = false;
    }

    if (vfn_144())
    {
        ActorValue::Index luck;
        int z;
        for (z = 0; z < 7; ++z)
        {
            luck = ::ActorValue::GetActorValueForSectionIndex(ActorValue::Attributes, (unsigned char)z);
            if (s)
            {
                level = (float)reinterpret_cast<::FUN_00480160_shell *>(&(((::TESClass *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetSceneRoot()))->classAttributes))->FUN_00480160(5 + z);
            }
            if (level > 10.0)
            {
                level = 10.0f;
            }
            reinterpret_cast<::Thing *>(this)->SetByte((*(int *)&(luck)), (unsigned char)::FUN_00406d90(level), false);
        }

        unsigned char res;
        res = reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(11);
        long tmp;
        tmp = ::ComputeIntelligenceResult(reinterpret_cast<::FUN_00480160_shell *>(this)->FUN_00480160(9), true);
        long fRemainder;
        fRemainder = reinterpret_cast<::FUN_0047ded0_shell *>(this)->FUN_0047ded0();
        tmp = (fRemainder - 1) * tmp;
        int kIter;
        kIter = (arg1 ? 1 : 0) + 3;
        float q;
        q = (float)(((double)(::FUN_00404040((float)tmp / kIter))) * ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cd6c0))))))->i);
        float y;
        y = 0.0f;
        --kIter;

        long pObj;
        ActorValue::Index fPointsPerSkill;
        int j;
        for (pObj = 0; pObj < 14; ++pObj)
        {
            fPointsPerSkill = ::ActorValue::GetActorValueForSectionIndex(ActorValue::Skills, (unsigned char)pObj);
            if (!::FUN_00406d70((*(int *)&(fPointsPerSkill)), 0x2000))
            {
                if (::FUN_0047f060((*(int *)&(fPointsPerSkill))))
                {
                    level = 0.0f;
                    j = -1;
                    ::GetSkillAttributeAndBase((*(int *)&(fPointsPerSkill)), &j, &level);

                    level = AIFormulas::CalculateSkillValue(level, (float)attributes[j - 5], (float)res);

                    if (s && m_pClass)
                    {
                        if (m_pClass->IsTagSkill(fPointsPerSkill))
                        {
                            level += (q + y) + originalRuntimeFloatSetting327.Float()->f;
                            y = 0.0f;
                            if (level > 100.0)
                            {
                                y = level - 100.0;
                                if (!!kIter)
                                {
                                    y /= kIter;
                                }
                            }
                            --kIter;
                        }
                    }

                    if (level > 100.0)
                    {
                        level = 100.0f;
                    }
                    data.skills[pObj] = (unsigned char)::FUN_00406d90(level);
                }
            }
        }

        if (m_pClass)
        {
            if (vfn_30())
            {
                SetServiceFlags(((unsigned int)(reinterpret_cast<::LowProcess *>((m_pClass))->GetPackageObjectType())), false);
            }
        }
        else
        {
            SetServiceFlags(0, false);
        }

        MarkAsModified(0x20c);
    }
}

namespace fnv_00606540 {
struct Part
{
    bool a, b;
};
struct Count
{
};
struct Extra
{
    char pad[32];
    Count count;
};
struct Extras
{
};
template <int N> struct Slots : Slots<N - 1>
{
    virtual void slot(Slots<N>*);
};
template <> struct Slots<0>
{
};
struct Process : Slots<282>
{
    virtual void FUN_00606540_slot(bool);
};
struct Package
{
};
struct Ref
{
};
struct FUN_004459e0
{
    ~FUN_004459e0();
};
typedef FUN_004459e0 Item;
struct Inventory
{
};
struct BipedData
{
    void* p;
    char pad[12];
};
struct Biped
{
};
struct Field
{
};
struct Player
{
};
struct Shell
{
    char pad[52];
    unsigned flags;
    char pad2[212];
    Field field;
    void FUN_00606540(Ref* ref, Biped* biped, bool force);
};
// @fnv 0x00606540
void Shell::FUN_00606540(Ref* ref, Biped* biped, bool force)
{
    if (biped)
    {
        if (!force)
        {
            for (unsigned i = 0; i < 20; ++i)
            {
                if (((::fnv_00606540::BipedData *)(reinterpret_cast<::FUN_00606800_shell *>((biped))->FUN_00606800()))[i].p)
                    return;
            }
        }
        reinterpret_cast<::BipedAnim *>((biped))->UpdateRaceSex((::TESRace *)(void *)(reinterpret_cast<::Callees *>(&(field))->FUN_00726070()), {});
    }
    Ref* actor = (Ref*)dynamic_cast<::Actor *>(reinterpret_cast<::TESObjectREFR *>(ref));
    if (actor && ((::fnv_00606540::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())))
    {
        bool valid = true;
        Extra* extra = ((::fnv_00606540::Extra *)(reinterpret_cast<::ExtraDataList *>((((::fnv_00606540::Extras *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))))->GetDismemberedLimbs()));
        if (extra && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(extra->count))->GetName())) && ((::fnv_00606540::Part *)(reinterpret_cast<::B441420Owner *>((extra))->GetInfoAt(0))))
        {
            for (unsigned j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(extra->count))->GetName())); ++j)
            {
                Part* part = ((::fnv_00606540::Part *)(reinterpret_cast<::B441420Owner *>((extra))->GetInfoAt(j)));
                if (!part->a && part->b)
                    valid = false;
            }
        }
        if (valid)
        {
            ((::fnv_00606540::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->FUN_00606540_slot(true);
        }
    }
    if (!((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((ref))->FUN_0043fcd0())) || force)
    {
        bool update = reinterpret_cast<::TESActorBase *>(this)->ShouldUseDefaultAppearance((::TESObjectREFR *)(ref)) | force;
        if (this == ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*(Player**)&(*reinterpret_cast<char *>(&::_g_thePlayer)))))->FUN_007af430())))
        {
            Inventory* inv = ((::fnv_00606540::Inventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(ref))));
            if (inv)
            {
                for (int k = 0; k < 20; ++k)
                {
                    Item* item = ((::fnv_00606540::FUN_004459e0 *)(reinterpret_cast<::Target *>((inv))->FUN_004c8c10(k, 0)));
                    if (item)
                    {
                        update = false;
                        delete item;
                        item = 0;
                        break;
                    }
                }
            }
        }
        if (update)
        {
            bool package = true;
            Package* equip = ((::fnv_00606540::Package *)(reinterpret_cast<::FUN_009344a0_shell *>((actor))->FUN_009344a0()));
            if (equip && reinterpret_cast<::TESPackage *>((equip))->GetForceUnequipWeapon())
                package = false;
            reinterpret_cast<::TESNPC *>(this)->FUN_006047c0((::TESObjectREFR *)(ref), true, package, 0, 0);
        }
    }
    if (!::BipedAnim::CanLoadHiddenBipedObjects())
        reinterpret_cast<::HeadNPC *>(this)->FUN_00606820((::TESObjectREFR *)(ref), (::NiPointer< ::BipedAnim> *)(biped));
    reinterpret_cast<::FUN_00606050_shell *>(this)->InitWornObjects((::TESObjectREFR *)(ref), (::BipedAnim *)(biped));
    bool other = true;
    if (biped == ((::fnv_00606540::Biped *)(reinterpret_cast<::PlayerCharacter *>(((*(Player**)&(*reinterpret_cast<char *>(&::_g_thePlayer)))))->FUN_00950b00(true))))
        other = false;
    if (other)
        reinterpret_cast<::TESNPC *>(this)->AttachHeadParts((::TESObjectREFR *)(ref), (::NiNode *)(0));
}
}  // namespace fnv_00606540

struct TESNPC_Sub : public TESNPC
{
    void AttachHeadModels(TESObjectREFR* apRefr, BipedAnim* apBiped, BSFaceGenNiNode* apHeadBiped,
                          BSFaceGenNiNode* apHeadSkinned);
};

// @fnv 0x00607420
void TESNPC_Sub::AttachHeadModels(TESObjectREFR* apRefr, BipedAnim* apBiped, BSFaceGenNiNode* apHeadBiped,
                                  BSFaceGenNiNode* apHeadSkinned)
{
    BSFaceGenAnimationData* animData;
    NiAVObject* palette;
    animData = NULL;
    palette = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apRefr))->FUN_0043fcd0()));
    NiNode* a;
    a = NULL;
    if (palette)
    {
        a = palette->IsSceneNode();
    }
    NiNode* idx;
    idx = apBiped->GetBoneNode(BIPED_BONE_HEAD);
    NiControllerManager* f54;
    ThreeByThreeMatrix ptr;
    f54 = NULL;
    if (apRefr->GetAnimData() && reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((apRefr->GetAnimData()))->FUN_00496940())
    {
        f54 = ((::NiControllerManager *)(::fnv_00537bd0::GetStringAtOffset((const char *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((apRefr->GetAnimData()))->FUN_00496940()))));
    }
    NiDefaultAVObjectPalette* val;
    val = (NiDefaultAVObjectPalette*)f54;

    if (idx && a)
    {
        if (apHeadBiped)
        {
            if (apHeadBiped->GetFaceGenAnimationData())
            {
                if (reinterpret_cast<::HealthReferenceEntry *>((apRefr))->FUN_00568ad0() <= 0.0)
                {
                    apHeadBiped->GetFaceGenAnimationData()->vfn_d8(true, true);
                    apHeadBiped->GetFaceGenAnimationData()->vfn_d0(true);
                }
            }
            apHeadBiped->vfn_114(true);
            apHeadBiped->vfn_11c(true);
            reinterpret_cast<::FUN_00440460_S *>((apHeadBiped))->FUN_00440460((const ::V3 *)&(::NiPoint3::ZERO));
            reinterpret_cast<::FUN_0043fa80_s *>((apHeadBiped))->FUN_0043fa80(*(const ThreeByThreeMatrix*)&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448)));
            idx->AttachChildInAvailableSlot(apHeadBiped, true);
            AddObjectToPalette(apHeadBiped, val);
        }

        if (apHeadSkinned)
        {
            ptr = *(const ThreeByThreeMatrix*)&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448));
            apHeadSkinned->vfn_114(0 == apHeadBiped);
            apHeadSkinned->vfn_11c(apHeadBiped == 0);
            reinterpret_cast<::FUN_00440460_S *>((apHeadSkinned))->FUN_00440460((const ::V3 *)&(::NiPoint3::ZERO));
            a->AttachChildInAvailableSlot(apHeadSkinned, true);
            AddObjectToPalette(apHeadSkinned, val);
            apHeadSkinned->vfn_128(a, true);
        }

        animData = apHeadBiped ? apHeadBiped->GetFaceGenAnimationData() : NULL;
        if (0 == animData)
        {
            animData = apHeadSkinned ? apHeadSkinned->GetFaceGenAnimationData() : NULL;
        }

        if (animData)
        {
            animData->vfn_b4(0.0f, true, true, true, true, false);
            if (apRefr->IsActor())
            {
                Actor* pObj;
                pObj = (Actor*)apRefr;
                if (pObj->pFaceGenAnimationData)
                {
                    float v;
                    float obj3D;
                    float res;
                    ComputeAngleRange(&obj3D, &v);
                    ::fnv_00649f70::ClampMinMaxFromSetting(&obj3D, &res);
                    reinterpret_cast<::FUN_00607830_helper *>((pObj->pFaceGenAnimationData))->set(res);
                    reinterpret_cast<::Dummy_00607810 *>((pObj->pFaceGenAnimationData))->SetBoneMaxAngle(0, v);
                    FUN_00649fe0(&obj3D, &v);
                    GetEyeAngleLimits(&obj3D, &res);
                    reinterpret_cast<::FUN_00c748d0_C *>((pObj->pFaceGenAnimationData))->SetSlotFloats(0, v, res);
                }
            }
        }

        this->m_pkPrimaryFaceGenNode = apHeadBiped;
        this->m_pkSecondaryFaceGenNode = apHeadSkinned;
        reinterpret_cast<::FUN_00a5a040_Class *>((a))->FUN_00a5a040();
        NiUpdateData updateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((a))->FUN_00a59c60((std::intptr_t)&(updateData));
    }
    else
    {
        ::FUN_005b5e40();
    }

    this->AttachHeadParts(apRefr, 0);
}

struct FloatInsertIterator
{
    void* owner;
    float* current;
};
struct FloatInsertAllocator
{
    unsigned int state;
    float* FUN_0044abd0(unsigned int count);
};
struct FloatInsertVector
{
    unsigned int unk00;
    unsigned int unk04;
    FloatInsertAllocator allocator;
    float* first;
    float* last;
    float* end;
    unsigned int FUN_0044a2c0() const;
    float* FUN_0060bb40(float*, float*, float*);
    void Insert(FloatInsertIterator where, unsigned int count, const float& value);
};
// @fnv 0x0060b410
void Vec410::FUN_0060b410(unsigned int level, float value)
{
    if (((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())) < level)
    {
        IterPair beg;
        IterPair it = (*(::IterPair *)(reinterpret_cast<::fnv_0065f550::FUN_0065f550_Class *>(this)->CallWithSelf((::fnv_0065f550::_Out_0044a170 *)(::IterPair *)(&beg))));
        reinterpret_cast<::FloatInsertVector *>(this)->Insert({it.v0, it.v1}, level - ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())), value);
    }
    else if (level < ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())))
    {
        IterPair seek;
        IterPair res = (*(::IterPair *)(reinterpret_cast<::fnv_0065f550::FUN_0065f550_Class *>(this)->CallWithSelf((::fnv_0065f550::_Out_0044a170 *)(::IterPair *)(&seek))));
        FoundPair target;
        Facade410 begin;
        reinterpret_cast<::_Dummy_0044a170 *>(this)->FUN_0044a170((::_Out_0044a170 *)&begin);
        reinterpret_cast<::S8 *>(&begin)->FUN_0060b820((::S8 *)&target, level);
        FUN_0044a1a0(target.v0, target.v1, res.v0, res.v1);
    }
}
void __cdecl FUN_0060bb70(float*, float*, const float&);
float* __cdecl FUN_0060bba0(float*, float*, float*);

// Inserts count copies of value at where, growing or reallocating the buffer when capacity is insufficient.
// @fnv 0x0060b4d0
void FloatInsertVector::Insert(FloatInsertIterator where, unsigned int count, const float& value)
{
    unsigned int capacity = ((unsigned int)(reinterpret_cast<::FUN_0060b860_Cls *>((void *)this)->FUN_0060b860()));
    if (count == 0)
        ;
    else if (FUN_0044a2c0() - ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())) < count)
        ::fnv_0065f640::ThrowVectorTooLong();
    else if (capacity < ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())) + count)
    {
        capacity = FUN_0044a2c0() - capacity / 2 < capacity ? 0 : capacity + capacity / 2;
        if (capacity < ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())) + count)
            capacity = ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())) + count;
        float* ptr = allocator.FUN_0044abd0(capacity);
        float* pWritePos = ptr;
        try
        {
            pWritePos = FUN_0060bb40(first, where.current, ptr);
            pWritePos = ((float *)(reinterpret_cast<::Unk060b8a0 *>(this)->FUN_0060b8a0((std::intptr_t)(pWritePos), count, (int)&(value))));
            reinterpret_cast<::FUN_0060bb40_class *>(this)->FUN_0060bb40(where.current, last, pWritePos);
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0065f2b0_class *>(this)->FUN_0065f2b0((std::intptr_t)(ptr), (std::intptr_t)(pWritePos));
            reinterpret_cast<::FUN_0064df10_helper *>(&(allocator))->deallocate(ptr, capacity);
            throw;
        }
        count += ((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820()));
        if (first != 0)
        {
            reinterpret_cast<::FUN_0065f2b0_class *>(this)->FUN_0065f2b0((std::intptr_t)(first), (std::intptr_t)(last));
            reinterpret_cast<::FUN_0064df10_helper *>(&(allocator))->deallocate(first, end - first);
        }
        end = ptr + capacity;
        last = ptr + count;
        first = ptr;
    }
    else if ((unsigned int)(last - where.current) < count)
    {
        float tmp = value;
        reinterpret_cast<::FUN_0060bb40_class *>(this)->FUN_0060bb40(where.current, last, where.current + count);
        try
        {
            reinterpret_cast<::Unk060b8a0 *>(this)->FUN_0060b8a0((std::intptr_t)(last), count - (last - where.current), (int)&(tmp));
        }
        catch (...)
        {
            reinterpret_cast<::FUN_0065f2b0_class *>(this)->FUN_0065f2b0((std::intptr_t)(where.current + count), (std::intptr_t)(last + count));
            throw;
        }
        last += count;
        FUN_0060bb70(where.current, last - count, tmp);
    }
    else
    {
        float tmp = value;
        float* oldend = last;
        last = FUN_0060bb40(oldend - count, oldend, last);
        FUN_0060bba0(where.current, oldend - count, oldend);
        FUN_0060bb70(where.current, where.current + count, tmp);
    }
}

struct Flag75
{
    unsigned int value;
};

struct Buffer75
{
    virtual unsigned char Version();
    Flag75 FUN_00428110(unsigned int);
    bool FUN_0042ce90();
};


struct Cell75
{
    int unk00, unk04;
};

struct Matrix75
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Matrix75();
    ~Matrix75();
    unsigned int FUN_009611e0();
    Cell75 FUN_0060b370(unsigned int, unsigned int);
};


struct Race75
{
    int unk00, unk04;
};

struct Node75
{
    BGSHeadPart* item;
    Node75* next;
    void FUN_005ae3d0(BGSHeadPart* const&);
};

struct Saved75
{
    int unk00, unk04, unk08, unk0c, unk10;
    Saved75();
    ~Saved75();
    int FUN_00719b20(BGSHeadPart*&, int, bool (*)(BGSHeadPart*&, BGSHeadPart*&));
};

struct ActorData75
{
    int unk00;
};

struct NPC75
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

    ActorData75 actorData;

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

    int unkac;

    int unkb0;

    int unkb4;

    int unkb8;

    int unkbc;

    int unkc0;

    int unkc4;

    int unkc8;

    int unkcc;

    int unkd0;

    int unkd4;

    int unkd8;

    int unkdc;

    int unke0;

    int unke4;

    int unke8;

    int unkec;

    int unkf0;

    int unkf4;

    int unkf8;

    int unkfc;

    int unk100;

    int unk104;

    int unk108;

    Race75 race;

    ActorSkillData skills;

    TESClass* npcClass;

    Matrix75 face[2][2];

    Matrix75 (*alternate)[2];

    TESHair* hair;

    float hairLength;

    TESEyes* eyes;

    int unk1c4;

    int unk1c8;

    int unk1cc;

    int unk1d0;

    int unk1d4;

    unsigned int hairColor;

    Node75 parts;

    int unk1e4;

    int unk1e8;

    TESRace* originalRace;

    int unk1f0;

    float height;

    void FUN_005f1fd0(Buffer75*);
    void FUN_00609220(Buffer75*);
};

// Reads actor data, race, face matrices, hair, eyes, head parts, and sex from a save buffer, updating fields and marking changes.
// @fnv 0x00609220
void NPC75::FUN_00609220(Buffer75* buffer)
{

    FUN_005f1fd0(buffer);

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Flag75 &)(buffer->FUN_00428110(0x200)))->FUN_004280f0({}))
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&skills), 28);

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Flag75 &)(buffer->FUN_00428110(0x400)))->FUN_004280f0({}))
        npcClass = dynamic_cast<TESClass*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

    unsigned char changed1 = 0;

    if (reinterpret_cast<::FUN_0042ce90_class *>((buffer))->FUN_0042ce90())
        changed1 |= 0x1b;

    bool updateHeight27 = false;

    if (height == reinterpret_cast<::TESNPC *>(this)->GetDefaultHeight())
        updateHeight27 = true;

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Flag75 &)(buffer->FUN_00428110(0x2000000)))->FUN_004280f0({}))
    {

        TESRace* newRace = 0;

        newRace = dynamic_cast<TESRace*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

        if (newRace != ((::TESRace *)(reinterpret_cast<::Callees *>(&(race))->FUN_00726070())))
        {
            reinterpret_cast<::CombatProcedure *>(&(race))->Initialize((::CombatController *)(newRace));
            changed1 |= 0x1b;
        }

        originalRace = dynamic_cast<TESRace*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
    }

    if (updateHeight27)
        height = reinterpret_cast<::TESNPC *>(this)->GetDefaultHeight();

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Flag75 &)(buffer->FUN_00428110(0x800)))->FUN_004280f0({}))
    {

        bool useAlternate7 = false;

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&useAlternate7), 1);

        Matrix75(*coordinates20)[2] = face;

        if (useAlternate7)
        {
            if (!alternate)
            {
                alternate = (Matrix75(*)[2]) new Matrix75[4];
                ::BSFaceGenManager::InitializeFaceGenCoordinates((::FaceGenCoordinates *)(alternate));
            }
            coordinates20 = alternate;
        }

        for (unsigned int set = 0; set < 2; ++set)
        {

            for (unsigned int group = 0; group < 2; ++group)
            {

                unsigned int rows7 = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(coordinates20[set][group]))->FUN_009611e0()));

                unsigned int cols2 = reinterpret_cast<::BGSTerrainManager *>(&(coordinates20[set][group]))->GetMinLevel();

                for (unsigned int row = 0; row < rows7; ++row)
                {

                    for (unsigned int col = 0; col < cols2; ++col)
                    {

                        float value = 0.0f;
                        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&value), 4);

                        if (*((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::Cell75 &)(coordinates20[set][group].FUN_0060b370(row, col)))->FUN_00629ab0({}))) != value)
                        {

                            *((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::Cell75 &)(coordinates20[set][group].FUN_0060b370(row, col)))->FUN_00629ab0({}))) = value;
                            changed1 |= 8;
                        }
                    }
                }
            }
        }

        TESHair* oldHair4 = hair;
        TESEyes* oldEyes3 = eyes;
        float oldLength23 = hairLength;
        float oldColor22 = (float)hairColor;

        hair = dynamic_cast<TESHair*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
        eyes = dynamic_cast<TESEyes*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hairLength), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hairColor), 4);

        bool partsChanged41 = false;

        if (buffer->Version() >= 14)
        {

            Saved75 saved14;

            Node75* node17 = &parts;

            while (node17)
            {
                BGSHeadPart* part = ((::BGSHeadPart *)((void *)(node17)));
                if (part)
                    reinterpret_cast<::FUN_00438690 *>(&(saved14))->FUN_007cb2e0((unsigned int *)&(part));
                node17 = ((::Node75 *)(reinterpret_cast<::Callees *>((node17))->FUN_00726070()));
            }

            reinterpret_cast<::FileMatchList *>(&(parts))->RemoveAll();

            {

                unsigned int count33 = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));

                for (unsigned int index = 0; index < count33; ++index)
                {
                    BGSHeadPart* part = 0;
                    part = dynamic_cast<BGSHeadPart*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                    if (part)
                        parts.FUN_005ae3d0(part);
                }

                node17 = &parts;

                while (node17)
                {

                    BGSHeadPart* part = ((::BGSHeadPart *)((void *)(node17)));

                    if (part)
                    {
                        int found = saved14.FUN_00719b20(part, 0, ((bool (&)(BGSHeadPart *&, BGSHeadPart *&))::FUN_009a3830));
                        if (found == -1)
                        {
                            partsChanged41 = true;
                            break;
                        }
                        else
                            reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(saved14))->FUN_009a4320(found, 1);
                    }

                    node17 = ((::Node75 *)(reinterpret_cast<::Callees *>((node17))->FUN_00726070()));
                }

                if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(saved14))->GetName())))
                    partsChanged41 = true;
            }
        }

        if (partsChanged41 || oldHair4 != hair || oldEyes3 != eyes || oldLength23 != hairLength ||
            oldColor22 != hairColor)
            changed1 |= 8;
    }

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Flag75 &)(buffer->FUN_00428110(0x1000000)))->FUN_004280f0({}))
    {

        bool sex = false;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&sex), 1);

        if (reinterpret_cast<::TESActorBaseData *>(&(actorData))->GetFlag(1) != sex)
        {
            reinterpret_cast<::FlagSet *>(&(actorData))->FUN_0047dd50(1, sex, 1);
            changed1 |= 0x1b;
        }
    }

    if (changed1 & 8)
        reinterpret_cast<::TESNPC *>(this)->ResetFaceGen();

    if (changed1)
        reinterpret_cast<::TESActorBase *>(this)->FUN_005f20a0(changed1);
}

class Shell_00608f00_Flags
{
  public:
    unsigned int flags;
    Shell_00608f00_Flags();
};
class BGSSaveFormBuffer
{
  public:
    Shell_00608f00_Flags FUN_00428110();
};
class Shell_00608f00_Buf
{
  public:
};
class Shell_00608f00_Base
{
  public:
};
class Shell_00608f00_Row
{
  public:
};
struct Shell_00608f00_RowVal : public Shell_00608f00_Row
{
    unsigned int a, b;
    Shell_00608f00_RowVal();
};
class Shell_00608f00_Mat
{
  public:
    Shell_00608f00_RowVal FUN_0060b370(int);
};
class Shell_00608f00_Item
{
  public:
    Shell_00608f00_Item();
};
struct Shell_00608f00_Node;
class Shell_00608f00_Flag
{
  public:
};

class Shell_00608f00_NPC : public TESNPC
{
  public:
    void FUN_00608f00(BGSSaveFormBuffer* apFile);
};

// Writes NPC data to the buffer, including face coordinates, hair, eyes, head parts, and selected flag state.
// @fnv 0x00608f00
void Shell_00608f00_NPC::FUN_00608f00(BGSSaveFormBuffer* apFile)
{
    reinterpret_cast<::FUN_005f1f30_shell *>((((Shell_00608f00_Base*)this)))->FUN_005f1f30((unsigned int)apFile);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Shell_00608f00_Flags &)(apFile->FUN_00428110()))->FUN_004280f0(0x200))
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50(&data, 0x1c, 0);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Shell_00608f00_Flags &)(apFile->FUN_00428110()))->FUN_004280f0(0x400))
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((Shell_00608f00_Buf*)apFile)))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pClass), 0);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Shell_00608f00_Flags &)(apFile->FUN_00428110()))->FUN_004280f0(0x2000000))
    {
        Shell_00608f00_Node* pRace = ((::Shell_00608f00_Node *)(reinterpret_cast<::Callees *>(((Shell_00608f00_Node*)static_cast<TESRaceForm *>(this)))->FUN_00726070()));
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((Shell_00608f00_Buf*)apFile)))->FUN_00865df0((::fnv_00865df0::TESForm *)(pRace), 0);
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((Shell_00608f00_Buf*)apFile)))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pAssignedRace), 0);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Shell_00608f00_Flags &)(apFile->FUN_00428110()))->FUN_004280f0(0x800))
    {
        bool a = false;
        FaceGenMatrix<float>(*pCoord)[2] = m_kFaceGenCoordinates;
        if (m_pOffsetFaceCoordinates)
        {
            pCoord = m_pOffsetFaceCoordinates;
            a = true;
        }
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50(&a, 1, 0);
        for (unsigned int i = 0; i < 2; i++)
        {
            for (unsigned int j = 0; j < 2; j++)
            {
                unsigned int uiRows = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(pCoord[i][j]))->FUN_009611e0()));
                unsigned int cols = reinterpret_cast<::BGSTerrainManager *>(&(pCoord[i][j]))->GetMinLevel();
                for (unsigned int k = 0; k < uiRows; k++)
                {
                    for (unsigned int l = 0; l < cols; l++)
                    {
                        float fValue = reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::Shell_00608f00_Row &)(((Shell_00608f00_Mat*)&pCoord[i][j])->FUN_0060b370(k)))->FUN_00629ab0(l);
                        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50(&fValue, 4, 0);
                    }
                }
            }
        }
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((Shell_00608f00_Buf*)apFile)))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pHair), 0);
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((Shell_00608f00_Buf*)apFile)))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pEyes), 0);
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50(&m_fHairLength, 4, 0);
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50(&iHairColor, 4, 0);
        {
            int iNumParts = 0;
            unsigned int uiElapsedMilliseconds = reinterpret_cast<::FUN_00865f20_shell *>((apFile))->FUN_00865f20();
            Shell_00608f00_Node* pIter = (Shell_00608f00_Node*)&m_kHeadPartList;
            while (pIter)
            {
                BGSHeadPart* pHeadPart =
                    *(BGSHeadPart**)pIter;
                if (pHeadPart)
                {
                    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((Shell_00608f00_Buf*)apFile)))->FUN_00865df0((::fnv_00865df0::TESForm *)(pHeadPart), 0);
                    iNumParts++;
                }
                pIter = ((::Shell_00608f00_Node *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
            }
            reinterpret_cast<::FUN_00865ff0_shell *>((apFile))->FUN_00865ff0(iNumParts, uiElapsedMilliseconds);
        }
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::Shell_00608f00_Flags &)(apFile->FUN_00428110()))->FUN_004280f0(0x1000000))
    {
        bool bFlag = reinterpret_cast<::TESActorBaseData *>((void *)(((Shell_00608f00_Flag*)static_cast<TESActorBaseData *>(this))))->GetFlag(1);
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50(&bFlag, 1, 0);
    }
}

// Furniture marker entry returned by BaseProcess::GetFurnitureMarkerData().
class FurnitureMark
{
  public:
    float fX, fY, fZ;
    unsigned short usHeading;
    unsigned char cMarkerType;
};

// Dialogue package (RTTI .?AUDialoguePackage@@); its topic lives at TESPackage::pTopic.
struct DialoguePackage : public TESPackage
{
};

// Actor queries the pack does not declare.
class ActorQueries : public Actor
{
  public:
};
class PlayerActivationQueries : public PlayerCharacter
{
  public:
};

unsigned char GetCalendarDay(Calendar* apCalendar);

// TESNPC::Activate (vtable slot 73).
class TESNPCActivate : public TESNPC
{
  public:
    bool FUN_00607990(TESObjectREFR* apTargetRef, TESObjectREFR* apActivatorRef, bool abIsItem,
                      TESBoundObject* apObjectToGet, int aiCount);
};

// Handles NPC activation by checking combat, health, and dialogue conditions, then opening menus or transferring items between actors.
// @fnv 0x00607990
bool TESNPCActivate::FUN_00607990(TESObjectREFR* apTargetRef, TESObjectREFR* apActivatorRef, bool abIsItem,
                                  TESBoundObject* apObjectToGet, int aiCount)
{
    Actor* pActivator = dynamic_cast<Actor*>(apActivatorRef);
    Actor* pTarget = dynamic_cast<Actor*>(apTargetRef);
    if (!pTarget || pTarget->GetIsDying())
        return false;

    BaseProcess* pProcess = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()));
    if (!pProcess)
        return false;
    if (pProcess && pProcess->GetCurrentTalkTarget() && !pTarget->HasHealth(false))
        return false;
    if (pProcess && pProcess->GetCurrentFadeState())
        return false;

    TESPackage* pActivatorPackage = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->GetOneTimePackage();
    TESPackage* pTargetCurrentPackage = pProcess->GetOneTimePackage();
    char szLine[300];

    if (pTarget == ::_g_thePlayer && ::_g_thePlayer->bPreventActivation)
    {
        if (pTarget->IsGuard() && reinterpret_cast<::ActorStandIn008a *>((pTarget))->FUN_008a61b0())
            reinterpret_cast<::FUN_00693d50_shell *>((pProcess))->FUN_00693d50((*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameTime() - 1.0);
        return false;
    }

    if (!pTarget->HasHealth(false) || reinterpret_cast<::FUN_004f8960_shell *>((pTarget))->FUN_004f8960() == 6)
    {
        if (((bool)(reinterpret_cast<::FUN_00437bd0_stub *>((pTarget))->FUN_00437bd0())) || pTarget->GetHasKnockedState() || reinterpret_cast<::FUN_004f8960_shell *>((pTarget))->FUN_004f8960() == 6)
        {
            sprintf(szLine, "%s %s", reinterpret_cast<::FUN_0055d520_shell *>((pTarget))->FUN_0055d520(), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingActivationText *>(&::g_011d210c))))->GetMenuTitle())));
            ::DispatchMessageToSink((std::intptr_t)(szLine), 0, (std::intptr_t)("Interfac\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds"), (std::intptr_t)(0), 2.0f,
                        false);
            return false;
        }
        else if (reinterpret_cast<::FleeActorEntry *>((static_cast<ActorQueries*>(pTarget)))->FUN_008a6650(false))
        {
            CombatController* m_pCombatController = pTarget->GetCombatController();
            if (!m_pCombatController || !reinterpret_cast<::Unk_0097fa10 *>((m_pCombatController))->FUN_0097fa10(::_g_thePlayer) ||
                reinterpret_cast<::FUN_00894d60_shell *>((static_cast<PlayerActivationQueries*>(::_g_thePlayer)))->FUN_00894d60())
            {
                sprintf(szLine, "%s %s", reinterpret_cast<::FUN_0055d520_shell *>((pTarget))->FUN_0055d520(), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingActivationText *>(&::g_011d2538))))->GetMenuTitle())));
                ::DispatchMessageToSink((std::intptr_t)(szLine), 0, (std::intptr_t)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"), (std::intptr_t)(0), 2.0f,
                            false);
                return false;
            }
        }
    }

    if (reinterpret_cast<::MiddleHighProcess *>((pTarget))->IsActorInCombat() && apActivatorRef == ::_g_thePlayer)
    {
        if (::FUN_00754d90(pTarget))
            ::FUN_00709470(8, (int)(apTargetRef), (int)(0), (int)(0), 0);
        return false;
    }

    if (pActivator)
    {
        TESPackage* pPackage = reinterpret_cast<::FUN_0041cb10_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((pActivator))->FUN_005d43c0()))))->FUN_0041cb10();
        if (pActivator != ::_g_thePlayer && pPackage && reinterpret_cast<struct ::FUN_0041ca90 *>((pPackage))->get() == 15)
        {
            ExtraDataList* pTargetExtra = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((pTarget))->FUN_005d43c0()));
            reinterpret_cast<::FUN_0041c930_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((pActivator))->FUN_005d43c0()))))->FUN_0041c930((::Package_0041c930 *)(pPackage), 4, (unsigned int)(((::Actor *)(reinterpret_cast<::FUN_0041cb70_shell *>((pTargetExtra))->FUN_0041cb70()))), true, true,
                                                           false);
            if (pPackage->IsMustReachLocation())
                pActivator->SetExtraRunOncePacks(pPackage, GetCalendarDay(&(*reinterpret_cast<::Calendar *>(&::g_011de7b8))));
            ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->OnPackageEnd(pActivator, pPackage);
            pTarget->MarkAsModified(0x80000000);
        }
        if (pActivator != ::_g_thePlayer && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture())))
            ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->SetProcessConditionMet(true);

        if (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((static_cast<ActorQueries*>(pTarget)))->FUN_00493bb0())) && pActivator == ::_g_thePlayer &&
            reinterpret_cast<::MiddleHighProcess *>((pTarget))->IsActorInCombat())
        {
            reinterpret_cast<::VATS *>(&((*reinterpret_cast<::ActivationMenuState *>(&::g_011f2250))))->FUN_009c8950(0, 0);
            ::FUN_00709470(4, (int)(pTarget), (int)(0), (int)(0), 1);
        }
        else if (pTarget && (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((static_cast<ActorQueries*>(pTarget)))->FUN_00493bb0())) || pTarget->GetHasKnockedState()) &&
                 (pActivator != ::_g_thePlayer || !pTarget->GetSitSleepState() || pTarget->GetSitSleepState() == 9 ||
                  pTarget->GetSitSleepState() == 4 ||
                  (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->GetFurnitureMarkerData() &&
                   ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->GetFurnitureMarkerData()->cMarkerType > 19)))
        {
            if (reinterpret_cast<::FUN_00608d80_shell *>((pTarget))->FUN_00608d80())
                return false;

            if (!pTarget->HasHealth(false))
            {
                int iAttackReason = 0;
                if (!reinterpret_cast<::FUN_00437bf0_shell *>((pTarget))->FUN_00437bf0() && !pTarget->GetIsParalyzed())
                {
                    if (pActivator != ::_g_thePlayer && reinterpret_cast<::HostActor *>((pActivator))->IsHostileTo((::HostActor *)(pTarget), 0, &iAttackReason, false))
                    {
                        if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->ShouldAttackTarget(pActivator, pTarget, false, true, 0, false,
                                                                         false, true, 0, false, false, true, 0))
                            return true;
                    }
                    else if (!pTarget->IsGuard() && reinterpret_cast<::HostActor *>((pTarget))->IsHostileTo((::HostActor *)(pActivator), 0, &iAttackReason, false) &&
                             !pActivator->IsSneaking())
                    {
                        if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->ShouldAttackTarget(pTarget, pActivator, true, true, 0, false, false,
                                                                      true, 0, false, false, true, 0))
                            return true;
                    }
                }

                if (pActivator == ::_g_thePlayer && pTarget->GetHasKnockedState() && reinterpret_cast<::FUN_0087f3d0_shell *>((pTarget))->FUN_0087f3d0())
                {
                    return false;
                }
                else if (pActivator == ::_g_thePlayer ||
                         (pTarget == ::_g_thePlayer && (reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0()->IsPackageBlockingGreeting() ||
                                                     !reinterpret_cast<struct ::FUN_0041ca90 *>((reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0()))->get() ||
                                                     reinterpret_cast<struct ::FUN_0041ca90 *>((reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0()))->get() == 9)))
                {
                    if (pActivator == ::_g_thePlayer &&
                        (pTarget->GetHasKnockedState() ||
                         (::_g_thePlayer->IsSneaking() && !reinterpret_cast<::MiddleHighProcess *>((pTarget))->IsActorInCombat())) &&
                        !reinterpret_cast<::FUN_008ace90_shell *>((pTarget))->FUN_008ace90())
                    {
                        if (!pTarget->GetHasKnockedState() && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->HasCaughtPlayerPickpocketing())
                        {
                            sprintf(szLine, "%s %s", reinterpret_cast<::FUN_0055d520_shell *>((pTarget))->FUN_0055d520(), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingActivationText *>(&::g_011d2394))))->GetMenuTitle())));
                            ::DispatchMessageToSink((std::intptr_t)(szLine), 0, (std::intptr_t)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"), (std::intptr_t)(0),
                                        2.0f, false);
                            return false;
                        }
                        else
                        {
                            ::FUN_00709470(1, (int)(apTargetRef), (int)(0), (int)(0), 2);
                        }
                    }
                    else
                    {
                        TESTopic* pTopic = 0;
                        if (pActivator == ::_g_thePlayer || ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->IsCurrentlyDetected())
                            pTopic = ((::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName(0, 0)));
                        DialogueItem* pDialogueItem = 0;
                        if (pTopic)
                        {
                            if (pActivator == ::_g_thePlayer)
                                pDialogueItem = reinterpret_cast<::FUN_0061b320_shell *>((pTopic))->FUN_0061b320((::TESObjectREFR *)(pTarget), (::TESObjectREFR *)(::_g_thePlayer), 0, 0, false);
                            else if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->IsCurrentlyDetected())
                                pDialogueItem = reinterpret_cast<::FUN_0061b320_shell *>((pTopic))->FUN_0061b320((::TESObjectREFR *)(pActivator), (::TESObjectREFR *)(::_g_thePlayer), 0, 0, false);
                        }
                        if (pDialogueItem && reinterpret_cast<::FUN_00619df0_shell *>((void *)(((::TESTopic *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pDialogueItem))->FUN_0084e3a0()))))->FUN_00619df0() &&
                            pDialogueItem->SelectDefaultResponseList() && !reinterpret_cast<::FUN_0083c7e0_shell *>((pDialogueItem))->FUN_0083c7e0())
                        {
                            if (pTarget->GetSitSleepState() == 9)
                            {
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->SetCombatState(true);
                                pTarget->InitGetUpPackage();
                                return true;
                            }
                            else if (pTarget == ::_g_thePlayer)
                            {
                                reinterpret_cast<::fnv_0057b7c0::Actor57 *>((pActivator))->StartDialog((::fnv_0057b7c0::Topic57 *)(pTopic), false, false);
                            }
                            else
                            {
                                reinterpret_cast<::fnv_0057b7c0::Actor57 *>((pTarget))->StartDialog((::fnv_0057b7c0::Topic57 *)(pTopic), false, false);
                            }
                        }
                        else
                        {
                            if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->GetFurnitureMarkerData() &&
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->GetFurnitureMarkerData()->cMarkerType > 19)
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->AddPostAnimAction(0x200);
                            if (!pTarget->GetSitSleepState())
                                pTarget->SetReferenceHeading(*pActivator->GetPos(), false);

                            TESTopic* pMenuTopic = 0;
                            TESObjectREFR* pDialogueReference = 0;
                            if (pActivator == ::_g_thePlayer)
                            {
                                if (!((bool)(reinterpret_cast<::TeleportableReference *>((pTarget))->GetTeleportDestinationForm())) && !reinterpret_cast<::fnv_008b3c30::FUN_008b3c30_shell *>((pTarget))->FUN_008b3c30())
                                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->StopActorMovement(pTarget);
                                reinterpret_cast<::fnv_008a8e50::ActorP_S *>((pActivator))->FUN_008a8e50();
                                reinterpret_cast<::fnv_008a8e50::ActorP_S *>((pTarget))->FUN_008a8e50();
                                DialoguePackage* pDialoguePackage =
                                    dynamic_cast<DialoguePackage*>(reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0());
                                if (pDialoguePackage)
                                    pMenuTopic = pDialoguePackage->pTopic;
                                pDialogueReference = apTargetRef;
                                if (pTarget->GetCurrentTarget() == ::_g_thePlayer && pTargetCurrentPackage &&
                                    !reinterpret_cast<struct ::FUN_0041ca90 *>((pTargetCurrentPackage))->get())
                                {
                                    if (((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::FUN_0041d8a0_shell *>((pTargetCurrentPackage))->FUN_0041d8a0())) &&
                                        !((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::FUN_0041d8a0_shell *>((pTargetCurrentPackage))->FUN_0041d8a0()))))->FUN_00726070())))
                                        pProcess->SetProcessTarget(pActivator, 2);
                                    else
                                        pProcess->SetProcessTarget(pTarget, 1);
                                }
                                ::FUN_00453a70()->SetAudioState(4);
                                pTarget->RemoveCastingArt();
                                if (pTarget->GetSitSleepState() != 9)
                                {
                                    TESObjectREFR* pMenuOwner = pActivator;
                                    if (pMenuOwner == ::_g_thePlayer)
                                        pMenuOwner = pTarget;
                                    reinterpret_cast<::VATS *>(&((*reinterpret_cast<::ActivationMenuState *>(&::g_011f2250))))->FUN_009c8950(0, 0);
                                    ::FUN_00709470(4, (int)(pMenuOwner), (int)(pMenuTopic), (int)(0), 1);
                                }
                                else
                                {
                                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->SetCombatState(true);
                                    pTarget->InitGetUpPackage();
                                }
                            }
                            else if (::fnv_00702640::FUN_00702640() != 0x3f1)
                            {
                                if (!((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((::_g_thePlayer))->GetBaseTexture()))->IsAimingAtActor(pActivator))
                                    return false;
                                ::FUN_00453a70()->SetAudioState(4);
                                reinterpret_cast<::fnv_008a8e50::ActorP_S *>((pActivator))->FUN_008a8e50();
                                reinterpret_cast<::fnv_008a8e50::ActorP_S *>((pTarget))->FUN_008a8e50();
                                pDialogueReference = pActivator;
                                if (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((static_cast<ActorQueries*>(pActivator)))->FUN_00493bb0())))
                                {
                                    DialoguePackage* pActivatorDialogue =
                                        dynamic_cast<DialoguePackage*>(reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0());
                                    if (pActivatorDialogue)
                                        pMenuTopic = pActivatorDialogue->pTopic;
                                }
                                if (((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::FUN_0041d8a0_shell *>((pActivatorPackage))->FUN_0041d8a0())) &&
                                    !((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::FUN_0041d8a0_shell *>((pActivatorPackage))->FUN_0041d8a0()))))->FUN_00726070())))
                                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->SetProcessTarget(pActivator, 2);
                                else
                                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->SetProcessTarget(pActivator, 1);
                                pTarget->RemoveCastingArt();
                                if (pTarget == ::_g_thePlayer)
                                    reinterpret_cast<::fnv_008a7a90::ActorAnimView *>((pTarget))->FUN_008a7a90();
                                else
                                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pTarget))->GetBaseTexture()))->AddPostAnimAction(0x400);
                                if (pActivator == ::_g_thePlayer)
                                    reinterpret_cast<::fnv_008a7a90::ActorAnimView *>((pActivator))->FUN_008a7a90();
                                else
                                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->AddPostAnimAction(0x400);
                                reinterpret_cast<::VATS *>(&((*reinterpret_cast<::ActivationMenuState *>(&::g_011f2250))))->FUN_009c8950(0, 0);
                                TESObjectREFR* m_pDialogueSpeaker = pActivator;
                                if (m_pDialogueSpeaker == ::_g_thePlayer)
                                    m_pDialogueSpeaker = pTarget;
                                ::FUN_00709470(4, (int)(m_pDialogueSpeaker), (int)(pMenuTopic), (int)(0), 1);
                            }
                        }
                        delete pDialogueItem;
                    }
                }
                else
                {
                    if (apObjectToGet)
                    {
                        TESNPC* pNPC = dynamic_cast<TESNPC*>(apObjectToGet);
                        if (!pNPC)
                        {
                            pTarget->RemoveItem(apObjectToGet, 0, aiCount, true, 0, pActivator, 0, 0, true, false);
                            reinterpret_cast<::Actor *>((pActivator))->FUN_008c00e0(pTarget, (int)(apObjectToGet), aiCount);
                            return true;
                        }
                    }
                    if (reinterpret_cast<struct ::FUN_0041ca90 *>((reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0()))->get() == 2)
                    {
                        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->SetProcessTarget(pActivator, 2);
                    }
                    else
                    {
                        if (reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0() && reinterpret_cast<struct ::FUN_0041ca90 *>((reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0()))->get() != 1)
                            ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->SetProcessTarget(pActivator, 1);
                        if (pTarget != ::_g_thePlayer)
                        {
                            if (pTarget != pActivator && reinterpret_cast<::FUN_009344a0_shell *>((pTarget))->FUN_009344a0() &&
                                reinterpret_cast<struct ::FUN_0041ca90 *>((reinterpret_cast<::FUN_009344a0_shell *>((pTarget))->FUN_009344a0()))->get() != 1 &&
                                reinterpret_cast<struct ::FUN_0041ca90 *>((reinterpret_cast<::FUN_009344a0_shell *>((pTarget))->FUN_009344a0()))->get() != 2)
                                pProcess->SetProcessTarget(pTarget, 1);
                            if (pTarget != pActivator && !pTarget->GetSitSleepState())
                            {
                                if (pActivator->IsCombatStateActive())
                                {
                                    TESPackage* pDialoguePkg = reinterpret_cast<::FUN_009344a0_shell *>((pActivator))->FUN_009344a0();
                                    if (!reinterpret_cast<::fnv_00672800::Proxy72800 *>((pDialoguePkg))->FUN_00672800() && !reinterpret_cast<::FUN_006727b0_shell *>((pDialoguePkg))->FUN_006727b0())
                                        pTarget->SetReferenceHeading(*pActivator->GetPos(), false);
                                }
                                else
                                {
                                    pTarget->SetReferenceHeading(*pActivator->GetPos(), false);
                                }
                            }
                            if (!pActivator->IsCombatStateActive() && pActivator->IsCharacter() && pTarget->IsCharacter())
                            {
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->SetProcessTarget(pActivator, 1);
                                if (pActivator->vfn_280(pTarget, 0, 0, 1, 0, 0, 0, 0, 0))
                                {
                                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActivator))->GetBaseTexture()))->SetProcessTarget(pActivator, 2);
                                    pProcess->SetProcessTarget(pTarget, 2);
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (pActivator == ::_g_thePlayer)
                {
                    ::FUN_00709470(1, (int)(apTargetRef), (int)(0), (int)(0), 1);
                }
                else if (apObjectToGet)
                {
                    TESNPC* pObjectNPC = dynamic_cast<TESNPC*>(apObjectToGet);
                    if (!pObjectNPC)
                        apTargetRef->RemoveItem(apObjectToGet, 0, aiCount, false, 0, pActivator, 0, 0, true, false);
                }
            }
        }
        else if (pTarget && pTarget->GetCombatController() && pActivator == ::_g_thePlayer &&
                 reinterpret_cast<::FUN_0047c850 *>((pTarget->GetCombatController()))->EvaluateCondition())
        {
            char szMessage[200];
            sprintf(szMessage, "%s %s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(this)->FUN_00408da0())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingActivationText *>(&::g_011cf594))))->GetMenuTitle())));
            ::DispatchMessageToSink((std::intptr_t)(szMessage), 0, (std::intptr_t)(0), (std::intptr_t)(0), 2.0f, false);
            return false;
        }
        return true;
    }
    return false;
}

class Helper009f8770
{
  public:
};

class FUN_00484d40_Host_ctx
{
  public:
    void FUN_00484d40(unsigned int* apFormID, int aiSize);
};

class FUN_004ac110_shell_ctx
{
  public:
    TESRace* FUN_004ac110();
};

class FUN_009611e0_shell_ctx
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

class FUN_004eaf60_shell_ctx
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

class NPCModelView_ctx
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

class MiddleHighProcess_ctx : public BaseProcess
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
            unsigned int uiNumRows = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell_ctx *>(&(m_kFaceGenCoordinates[i][j]))->FUN_009611e0()));
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
    if (((FUN_004ac110_shell_ctx*)this)->FUN_004ac110())
        bPrevHadRace = false;
    else
        ::FUN_005b5e40();
    unsigned int uiNewRace;
    ((FUN_00484d40_Host_ctx*)this)->FUN_00484d40(&uiNewRace, 4);
    TESRace* pRace = dynamic_cast<TESRace*>(FUN_004839c0(uiNewRace));
    if (uiNewRace && !pRace)
        ::FUN_005b5e40();
    if (((::TESRace *)(reinterpret_cast<::Callees *>((void *)this)->FUN_00726070())) != pRace)
        bChanged = true;
    reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(pRace));
    bool bNowHasRace = false;
    if (((FUN_004ac110_shell_ctx*)this)->FUN_004ac110())
        bNowHasRace = false;
    else
        ::FUN_005b5e40();
    unsigned int uiNewHairFormID;
    ((FUN_00484d40_Host_ctx*)this)->FUN_00484d40(&uiNewHairFormID, 4);
    TESHair* pReadHair = dynamic_cast<TESHair*>(FUN_004839c0(uiNewHairFormID));
    if (uiNewHairFormID && !pReadHair)
        ::FUN_005b5e40();
    if (m_pHair != pReadHair)
        bChanged = true;
    m_pHair = pReadHair;
    unsigned int uiEyes;
    ((FUN_00484d40_Host_ctx*)this)->FUN_00484d40(&uiEyes, 4);
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
                if (pFace && ((FUN_009611e0_shell_ctx*)pFace)->FUN_009611e0())
                {
                    ::FUN_00a6e8e0((::S_00a6e8e0_Object *)(pFace), (::S_00a6e8e0_Palette *)(pkManager));
                    ((NodeFace*)((FUN_009611e0_shell_ctx*)pFace)->FUN_009611e0())->InsertChild(pFace);
                }
                pFace = ((ActorFace*)apActor)->GetHeadRootNode(false);
                if (pFace && ((FUN_009611e0_shell_ctx*)pFace)->FUN_009611e0())
                {
                    ::FUN_00a6e8e0((::S_00a6e8e0_Object *)(pFace), (::S_00a6e8e0_Palette *)(pkManager));
                    ((NodeFace*)((FUN_009611e0_shell_ctx*)pFace)->FUN_009611e0())->InsertChild(pFace);
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
            bool bWasFirstPerson = ((FUN_004eaf60_shell_ctx*)::_g_thePlayer)->FUN_004eaf60();
            reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>((((PlayerFace*)::_g_thePlayer)))->FUN_00950110(false);
            if (pNode && bPrevHadRace != bNowHasRace)
            {
                pParent = (NiNode*)((FUN_009611e0_shell_ctx*)((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((apActor))->FUN_0043fcd0())))->FUN_009611e0();
                reinterpret_cast<::Ref3 *>((((FaceRefr*)apActor)))->FUN_005702e0((::Obj3 *)(::NiNode *)(0), true);
            }
            if (bNowHasRace)
                ((NPCModelView_ctx*)this)->kModel.SetModelFilePath(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d2b38))->GetMenuTitle())));
            else if (reinterpret_cast<::TESActorBase *>(this)->GetSex() == FEMALE)
                ((NPCModelView_ctx*)this)->kModel.SetModelFilePath(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d2718))->GetMenuTitle())));
            else
                ((NPCModelView_ctx*)this)->kModel.SetModelFilePath(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d3e44))->GetMenuTitle())));
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
                MiddleHighProcess_ctx* pProcess = dynamic_cast<MiddleHighProcess_ctx*>(((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture())));
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

// @fnv 0x006047c0
void TESNPC::FUN_006047c0(TESObjectREFR* a2, bool a3, bool a4, bool a5, bool a6)
{
    InventoryChanges* j;
    InventoryStackRecord* item;
    bool bAllowed;
    bAllowed = true;
    if (a6 == 0)
    {
        bAllowed = reinterpret_cast<::FUN_004623f0_shell *>((::g_BGSSaveLoadGame))->FUN_004623f0(false);
    }
    if (a2->IsActor())
    {
        reinterpret_cast<::BipedAnim *>((a2))->AttachFaceGenNode();
    }
    j = ::InventoryChanges::CreateForReference(a2);
    reinterpret_cast<::FUN_004bfe50_t *>((j))->RemoveWornItems(true, a2);
    Actor* pBiped;
    pBiped = (Actor*)a2;
    if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture())))
    {
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentAmmunition(NULL);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentShield(NULL);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentTorch(NULL);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture()))->SetCurrentArmor(NULL, NULL, false);
    }
    TESBipedModelForm* res = NULL;
    ExtraDataList* pExtra = NULL;
    for (int i = 0; i < 20; i++)
    {
        item = reinterpret_cast<::FUN_004c8220_shell *>((j))->FUN_004c8220(this, i, true);
        if (item)
        {
            bool val = true;
            TESBoundObject* p;
            p = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()));
            if ((!res || !res->HasBipedModel((::BIPED_OBJECT)i, false, NULL)) && !reinterpret_cast<::Thing575 *>((a2))->FUN_00575400((int)(p)))
            {
                if (((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(item)))))
                {
                    pExtra = ((((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(item)))))->m_item);
                }
                else
                {
                    pExtra = NULL;
                }
                if (i == 2)
                {
                    res = dynamic_cast<TESBipedModelForm*>(p);
                }
                else
                {
                    TESBipedModelForm* pInv;
                    pInv = ::TESBipedModelForm::GetFormAsBipedModel(p);
                    if (pInv->HasBipedModel((::BIPED_OBJECT)2, false, NULL))
                    {
                        val = false;
                    }
                }
                if (val)
                {
                    a2->EquipItem(p, 1, pExtra, false);
                }
            }
            delete item;
            item = NULL;
        }
    }
    if (a4 && !a2->HasHealth(false))
    {
        float cnt;
        cnt = 0.0f;
        InventoryStackRecord* pWeaponExtra;
        pWeaponExtra = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((j))->SelectBestWeapon((::ActorStand *)(::TESActorBase *)(this), &cnt, 6, true)));
        if (pWeaponExtra)
        {
            bool pItem = true;
            if (!reinterpret_cast<::Thing575 *>((a2))->FUN_00575400((int)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pWeaponExtra))->GetName())))))
            {
                ExtraDataList* fWeight;
                fWeight = NULL;
                if (((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(pWeaponExtra)))))
                {
                    fWeight = ((((::BSSimpleList< ::ExtraDataList *> *)(::FUN_00559450((int *)(pWeaponExtra)))))->m_item);
                    pItem = false;
                }
                else
                {
                    fWeight = NULL;
                }
                TESObjectREFR* bEquipWeapon;
                bEquipWeapon = a2;
                reinterpret_cast<::fnv_0088c830::ThisC *>((bEquipWeapon))->FUN_0088c830((::fnv_0088c830::FormC *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pWeaponExtra))->GetName()))), ((int)(reinterpret_cast<::Callees *>((pWeaponExtra))->FUN_00726070())), fWeight, true,
                                          false, true);
                if (pItem)
                {
                    delete pWeaponExtra;
                }
            }
            else if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)a2)))->GetBaseTexture())))
            {
                if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pWeaponExtra))->GetName())) != reinterpret_cast<::FUN_008a1710_shell *>((((Actor*)a2)))->FUN_008a1710())
                {
                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)a2)))->GetBaseTexture()))->SetCurrentArmor(pWeaponExtra, a2->GetNiNode(), false);
                }
            }
        }
    }
    if (a6 == 0)
    {
        reinterpret_cast<::FUN_004623f0_shell *>((::g_BGSSaveLoadGame))->FUN_004623f0(bAllowed);
    }
    if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pBiped))->GetBaseTexture())))
    {
        reinterpret_cast<::ActorSpellView *>((pBiped))->UpdateSpells(true);
    }
}

// Adjustor thunk for FUN_0060c440: "sub ecx, 0xdc; jmp FUN_00601370".
//
// This is the MSVC this-adjusting thunk that the compiler emits for a virtual
// function inherited from a secondary base: it converts the secondary base
// sub-object pointer (this + 0xdc) back into the derived object pointer
// (sub ecx, 0xdc) and tail-jumps to the final overrider.
//
// The subtracted offset is the size of the first base, so the first base is
// laid out as a vtable pointer plus 54 int members (4 + 54 * 4 = 0xdc bytes).
// Both bases declare the same virtual function, the derived class redeclares
// it and only defines its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0060c440();
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
};

struct SecondaryBase
{
    virtual void FUN_0060c440();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c440
    virtual void FUN_0060c440();
};

Derived::Derived()
{}

// FUN_0060c450 is a MSVC this-adjusting thunk (adjustor thunk).
//
// The class AdjustorThunkHolder inherits AdjustorSecondaryBase at offset
// 0x7c (the primary base is 0x7c bytes long), and overrides the virtual
// function FUN_0060c450 that AdjustorSecondaryBase declares.  For that
// override the compiler emits a thunk that moves `this` back to the
// secondary base sub-object and jumps to the implementation:
//
//     sub ecx, 0x7c
//     jmp AdjustorThunkHolder::FUN_0060c450
//
// The overriding implementation itself lives in another translation unit,
// so it is only declared here.

struct AdjustorPrimaryBase
{
    virtual void FUN_0060c450();
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
};

struct AdjustorSecondaryBase
{
    virtual void FUN_0060c450();
};

struct AdjustorThunkHolder : AdjustorPrimaryBase, AdjustorSecondaryBase
{
// @fnv 0x0060c450
    virtual void FUN_0060c450();
    AdjustorThunkHolder();
};

AdjustorThunkHolder::AdjustorThunkHolder()
{}

namespace fnv_0060c460 {
struct PrimaryBase
{
    virtual void FUN_0060c460();
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
};

struct SecondaryBase
{
    virtual void FUN_0060c460();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c460
    virtual void FUN_0060c460();
};

Derived::Derived()
{}
}

// namespace fnv_0060c460

namespace fnv_0060c470 {
// Adjustor (this-adjusting) thunk for FUN_0060c470:
//     sub ecx, 0x90 ; jmp FUN_00608e00
// MSVC emits such a thunk in the vftable of a class that inherits the same
// virtual from two bases: the thunk converts the secondary base sub-object
// pointer back to the primary base pointer by subtracting the size of the
// primary base (0x90 = 4 byte vptr + 35 int members) and tail jumps to the
// implementation.  Both bases declare the virtual, the derived class
// redeclares it and defines only its constructor, which makes the compiler
// emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0060c470();
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
};

struct SecondaryBase
{
    virtual void FUN_0060c470();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c470
    virtual void FUN_0060c470();
};

Derived::Derived()
{}
}

// namespace fnv_0060c470

// Adjustor thunk: sub ecx,0x90 ; jmp <base virtual>.
// The primary base occupies 0x90 bytes, so the secondary base sub-object starts
// at +0x90 and the compiler emits an adjustor thunk for the secondary base's
// virtual slot, moving 'this' back onto the secondary base before the jump.
struct AdjPrimaryBase
{
    virtual void FUN_0060c490();
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
};

struct AdjSecondaryBase
{
    virtual void FUN_0060c490();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x0060c490
    virtual void FUN_0060c490();
};

AdjDerived::AdjDerived()
{}

namespace fnv_0060c4a0 {
// Adjustor (this-adjusting) thunk for FUN_0060c4a0: "sub ecx, 0x7c; jmp FUN_00608e00".
// PrimaryBase is the first base (vptr + 30 int fields = 0x7c bytes); SecondaryBase
// declares the same virtual; Derived derives from both, redeclares the virtual and
// defines only its constructor, so the compiler emits the adjusting thunk.
struct PrimaryBase
{
    virtual void* FUN_0060c4a0(unsigned int flags);
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
};

struct SecondaryBase
{
    virtual void* FUN_0060c4a0(unsigned int flags);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c4a0
    virtual void* FUN_0060c4a0(unsigned int flags);
};

Derived::Derived()
{}
}

#include "generated/data/fallout_shared/tesnpc.inc"
#include "generated/data/fallout_shared/tesnpc_ctx_variant.inc"
