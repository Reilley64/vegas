// fallout_shared/modelloader.cpp: DelStandIn, QueuedTreeModel, ModelLoader, QueuedHelmet and more (493 functions)

#include <cstdint>
#include <windows.h>
#include <new>
#include <cstdio>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/Actor.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AmmoInventory.h"
#include "fnv/decl/AttachmentHandler.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BGSTextureSet.h"
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/BipedAnim.h"
#include "fnv/decl/BoundObjectModelLookup.h"
#include "fnv/decl/C4442C0Queue.h"
#include "fnv/decl/C665b80.h"
#include "fnv/decl/C665be0_shell.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cell548.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/CreatureEquipment.h"
#include "fnv/decl/CreatureHost_5fa0a0.h"
#include "fnv/decl/Dummy_0056c7d0.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/F4F20Queue.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408790_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040ab70_shell.h"
#include "fnv/decl/FUN_0040c130_Class.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0041b6b0_shell.h"
#include "fnv/decl/FUN_0041f050_shell.h"
#include "fnv/decl/FUN_0041fbe0_shell.h"
#include "fnv/decl/FUN_00422940_shell.h"
#include "fnv/decl/FUN_00422ac0_shell.h"
#include "fnv/decl/FUN_0043b260_Class.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_0043b750.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_0043fab0_class.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004409e0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004410d0_Class.h"
#include "fnv/decl/FUN_00444020_Class.h"
#include "fnv/decl/FUN_0044b1f0_class.h"
#include "fnv/decl/FUN_0044b8d0_Class.h"
#include "fnv/decl/FUN_0044c270.h"
#include "fnv/decl/FUN_0044c920.h"
#include "fnv/decl/FUN_0044cb70_Holder.h"
#include "fnv/decl/FUN_0044cbb0_class.h"
#include "fnv/decl/FUN_0044e010_class.h"
#include "fnv/decl/FUN_0044f200_Class.h"
#include "fnv/decl/FUN_00452370_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_0045baf0_This.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00461090_shell.h"
#include "fnv/decl/FUN_0046fdd0_Class.h"
#include "fnv/decl/FUN_00477780_shell.h"
#include "fnv/decl/FUN_004778a0_cls.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00481150_shell.h"
#include "fnv/decl/FUN_00496cd0_cls.h"
#include "fnv/decl/FUN_004a0e50_Class.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004ae910_cls.h"
#include "fnv/decl/FUN_004aeb20_holder.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_004fbf00_shell.h"
#include "fnv/decl/FUN_00564e60_shell.h"
#include "fnv/decl/FUN_00564f00_shell.h"
#include "fnv/decl/FUN_005651e0_shell.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/FUN_00568480_cls.h"
#include "fnv/decl/FUN_0056c880_S.h"
#include "fnv/decl/FUN_00570ec0.h"
#include "fnv/decl/FUN_00572350_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_005f26c0_cls.h"
#include "fnv/decl/FUN_006055f0_shell.h"
#include "fnv/decl/FUN_00633c90.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_0065ded0_Class.h"
#include "fnv/decl/FUN_0065dfd0_class.h"
#include "fnv/decl/FUN_0065e000_class.h"
#include "fnv/decl/FUN_0065f240.h"
#include "fnv/decl/FUN_0065f2b0_class.h"
#include "fnv/decl/FUN_006ebde0_shell.h"
#include "fnv/decl/FUN_006ec9b0_Class.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_00906570_Class.h"
#include "fnv/decl/FUN_0092b7f0_Class.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00936ef0_Class.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009749b0_shell.h"
#include "fnv/decl/FUN_009c9e90_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a35910_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a61a60_cls.h"
#include "fnv/decl/FUN_00b4dec0_shell.h"
#include "fnv/decl/FUN_00c33280_Class.h"
#include "fnv/decl/FUN_00c3c620.h"
#include "fnv/decl/FUN_00c3cee0_shell.h"
#include "fnv/decl/FUN_00c3d440_cls.h"
#include "fnv/decl/FUN_00c3df40_Class.h"
#include "fnv/decl/FUN_00c3fca0_Class.h"
#include "fnv/decl/FUN_00ca20e0_Class.h"
#include "fnv/decl/FaceGenPaletteEntry.h"
#include "fnv/decl/FaceLoader.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Holder4523e0.h"
#include "fnv/decl/IdleAnimationManager.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/KFModelLookup.h"
#include "fnv/decl/LockFreeQueue.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/Map62d0.h"
#include "fnv/decl/MultiBoundManagerB5E.h"
#include "fnv/decl/NPCModelView.h"
#include "fnv/decl/NamedObjectLoader.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/NiPointer_KFModel.h"
#include "fnv/decl/NiPointer_LoadedFile.h"
#include "fnv/decl/NiStream2.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/Object.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/decl/Own60.h"
#include "fnv/decl/QRequest.h"
#include "fnv/decl/Queue44c640.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/Ref563530.h"
#include "fnv/decl/RefObj.h"
#include "fnv/decl/RefrStub.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_00447040.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/S_00c6d7a0_Obj.h"
#include "fnv/decl/S_447010.h"
#include "fnv/decl/SubBufferSaveShell.h"
#include "fnv/decl/TES.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESNPC.h"
#include "fnv/decl/TESNPC_Sub.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESRace.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TSHashTable.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskThreadResume.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TextureFileEntrySetter.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/TreeManager.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Twin_00c3cf40.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004a4c50__FUN_004a4c50_Class.h"
#include "fnv/decl/fnv_004f0640__NiInterpController.h"
#include "fnv/decl/fnv_0051cba0__TreeBillboardBuilder.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_0056fcb0__XObj.h"
#include "fnv/decl/fnv_00570f00__FUN_00570f00_shell.h"
#include "fnv/decl/fnv_00570f70__Obj570.h"
#include "fnv/decl/fnv_00571080__FUN_00571080_shell.h"
#include "fnv/decl/fnv_0057a3c0__FUN_0057a3c0_shell.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_006148f0__FUN_006148f0_shell.h"
#include "fnv/decl/fnv_0065f550__FUN_0065f550_Class.h"
#include "fnv/decl/fnv_006c0c30__Mgr006c0c30.h"
#include "fnv/decl/fnv_006c1cb0__Call_006c0c80.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087ac60__FUN_0087AC60_Holder.h"
#include "fnv/decl/fnv_008a1760__FUN_008a1760_shell.h"
#include "fnv/decl/fnv_008b7360__FUN_008b7360_Class.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00adb690__FUN_00adb690_cls.h"
#include "fnv/decl/fnv_00c3cb70__IOTask.h"
#include "fnv/decl/fnv_00c3cf60__FUN_00c3cf60_shell.h"
#include "fnv/decl/s44b130__Lock.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0040b000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00440000.h"
#include "fnv/symbols_00441000.h"
#include "fnv/symbols_00442000.h"
#include "fnv/symbols_00443000.h"
#include "fnv/symbols_00444000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_0044c000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_0044e000.h"
#include "fnv/symbols_0044f000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00475000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004ee000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00570000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d9000.h"
#include "fnv/symbols_00650000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00868000.h"
#include "fnv/symbols_008b7000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_008cd000.h"
#include "fnv/symbols_009ee000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa4000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00af3000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_00b59000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_00c6b000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01185000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/symbols_01197000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01272000.h"
#include "modelloader_verified_packet.h"

// @fnv 0x00441800
void QueuedCharacter::Attach()
{
    QueuedReference::Attach();
}

// @fnv 0x00441c30
void QueuedPlayer::Attach()
{
    QueuedCharacter::Attach();
}

// Returns the archive's file index plus 4 when the queued texture's archive is found, otherwise 0.
// @fnv 0x0043bfe0
unsigned char QueuedTexture::GetFileIndex()
{
    if (((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
    {
        Archive* archive = ((::Archive *)(::FindArchiveByKey((const ::FileNameHash *)(::BSFileEntry *)(((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))), (*(unsigned int *)&(const ::ARCHIVE_TYPE &)(static_cast<ARCHIVE_TYPE>(2))))));
        if (archive)
            return ::FUN_0043c030((const char *)(archive)) + 4;
    }
    return 0;
}

// Returns the archive's file index plus 4 when the archive is found, otherwise returns 1.
// @fnv 0x006fc440
unsigned char BGSTerrainChunkLoadTask::GetFileIndex()
{
    if (((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
    {
        Archive* archive = ((::Archive *)(::FindArchiveByKey((const ::FileNameHash *)(::BSFileEntry *)(((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))), (*(unsigned int *)&(const ::ARCHIVE_TYPE &)(static_cast<ARCHIVE_TYPE>(1))))));
        if (archive)
            return ::FUN_0043c030((const char *)(archive)) + 4;
    }
    return 1;
}

// @fnv 0x00446500
void ModelLoader::QueueFileList(BSSimpleList<const char*>* pFileList, IO_TASK_PRIORITY priority, QueuedFile* queuedFile,
                                const char* prefix)
{
    BSSimpleList<const char*>* current = pFileList;
    while (current)
    {
        const char* fileName = ((const char *)(new ((void *)(current)) ::Vec3()));
        if (fileName)
        {
            QueueKFListLocals locals;
            locals.pathToQueue = fileName;
            if (prefix)
            {
                TaskQueueInterface::CopyStringToBuffer(locals.path, sizeof(locals.path), prefix);
                strcat_s(locals.path, sizeof(locals.path), fileName);
                locals.pathToQueue = locals.path;
            }
            EnqueueFile(locals.pathToQueue, priority, queuedFile);
            locals.deletePointer = const_cast<char*>(fileName);
            ::FUN_00401030(locals.deletePointer);
            current->RemoveHead();
        }
        else
        {
            current = reinterpret_cast<BSSimpleList<const char*>*>(
                ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(current)))->FUN_00726070())));
        }
    }
}

// Clears node, then deletes the owned data pointer and leaves owned unchanged.
// @fnv 0x0043ab70
Model::~Model()
{
    node = 0;
    void* pOwnedData = owned;
    ::FUN_00401030(pOwnedData);
}

// @fnv 0x0043ca10
void QueuedModel::GenerateKey()
{
    reinterpret_cast<::FUN_00c3d440_cls *>(this)->FUN_00c3d440();
}

// Calls virtual method vfn_48 on DAT_01202d98, passing this.
// @fnv 0x00441e10
void QueuedKF::DispatchToManager()
{
    ::DAT_01202d98->vfn_48(this);
}

// @fnv 0x0043ec20
void QueuedHead::DispatchToManager()
{
    ::QueueFaceGenAssets((::TESActorBase *)(*reinterpret_cast<TESNPC**>(reinterpret_cast<char*>(this) + 0x28)),
                                         (*(int *)&(const ::IO_TASK_PRIORITY &)(FUN_0043cc60())), this);
    vfn_28();
}

// Retrieves the spell list from the TESSpellList at offset 0x34 and passes it to vfn_30.
// @fnv 0x0043cb10
void QueuedModel::DispatchToManager()
{
    BSSimpleList<InventoryStackRecord*>* list = 0;
    if (*reinterpret_cast<TESSpellList**>(reinterpret_cast<char*>(this) + 0x34))
        list = ((::BSSimpleList< ::InventoryStackRecord *> *)(::GetOffsetC((int)((*reinterpret_cast<TESSpellList**>(reinterpret_cast<char*>(this) + 0x34))))));
    vfn_30(list);
}

// @fnv 0x0043c4b0
NiRenderer* FUN_0043c4b0()
{
    return NiRenderer::ms_pRenderer;
}

// @fnv 0x00448a80
const NiFixedString& FUN_00448a80()
{
    return *DAT_01202ddc;
}

// @fnv 0x0043c490
NiPoint3& NiAVObject::FUN_0043c490()
{
    return *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x58);
}

// @fnv 0x0043c470
int NiAVObject::FUN_0043c470()
{
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3);
}

// @fnv 0x00441b80
void QueuedReference::FUN_00441b80()
{
    FUN_004414f0();
}

// @fnv 0x004431d0
void ModelLoader::FUN_004431d0()
{
    ::FUN_00449940((void **)this);
}

// @fnv 0x00443220
void ModelLoader::FUN_00443220()
{
    ::FUN_004499a0((int **)this);
}

// @fnv 0x004491f0
NiNode* NiAVObject::GetParentNode()
{
    return ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0()));
}

// @fnv 0x0043cca0
unsigned char IOTask::GetPriorityFromKey(__int64& key)
{
    return static_cast<unsigned char>(key >> 16);
}

// @fnv 0x00444d20
bool BGSSaveLoadGame::GetInitingForms() const
{
    return (m_uiInitializationFlags & 8) ? true : false;
}

// Returns the TESBipedModelForm for an ARMO, ARMA or CLOT form, or null for other or null forms.
// @fnv 0x00480db0
TESBipedModelForm* TESBipedModelForm::GetFormAsBipedModel(const TESForm* form)
{
    TESBipedModelForm* biped = 0;
    if (form)
    {
        switch (form->GetFormType())
        {
        case ENUM_FORM_ID_ARMO_ID: {
            TESObjectARMO* armor = static_cast<TESObjectARMO*>(const_cast<TESForm*>(form));
            biped = armor ? &armor->bipedModel : 0;
            break;
        }
        case ENUM_FORM_ID_ARMA_ID: {
            TESObjectARMA* addon = static_cast<TESObjectARMA*>(const_cast<TESForm*>(form));
            biped = addon ? &addon->bipedModelForm : 0;
            break;
        }
        case ENUM_FORM_ID_CLOT_ID: {
            TESObjectCLOT* clothing = static_cast<TESObjectCLOT*>(const_cast<TESForm*>(form));
            biped = clothing ? &clothing->bipedModel : 0;
            break;
        }
        }
    }
    return biped;
}

// @fnv 0x00448bf0
bool BGSAddonNode::IsMasterParticleSystem() const
{
    // Character-type inspection of the real one-byte bitfield object.
    return (*reinterpret_cast<const unsigned char*>(&kData.m_ucEntryType) & _AddonNodeFlags::IS_MASTER_PARTICLE_SYSTEM)
               ? true
               : false;
}

// @fnv 0x00441b00
bool TESPackage::GetForceUnequipWeapon() const
{
    return (packageFlags & kPackageFlag_WeaponsUnequipped) ? true : false;
}

// @fnv 0x00446390
WEAPON_TYPE TESObjectWEAP::GetWeaponType() const
{
    return static_cast<WEAPON_TYPE>(static_cast<signed char>(eWeaponType));
}

// @fnv 0x00442a80
void TESObjectACTI::SetActivateSound(TESSound* sound)
{
    activationSound = sound;
}

template <typename T> class BSStringT
{
  public:
    bool Set(const char*, unsigned int);
};


struct FUN_00406f90_this : public BSStringT<char>
{
    int FUN_00406f90(const char* fmt, char* args);
};

// Formats fmt with args into a 1024-byte buffer via FUN_00407000, stores the result in the string, and returns the formatting result.
// @fnv 0x00406f90
int FUN_00406f90_this::FUN_00406f90(const char* pcFormat, char* args)
{
    int res = 0;
    char buf[1024];

    res = FUN_00407000(buf, pcFormat, args);
    reinterpret_cast<::TextString *>(this)->FUN_004037f0(buf, 0);
    return res;
}

struct FUN_0043acb0_shell : public Model
{
    void ReleaseScriptRunLock();
};

void __cdecl FinishScriptRunLock(void*);

// If the reference count at offset 8 is positive, calls FinishScriptRunLock with that field's address.
// @fnv 0x0043acb0
void FUN_0043acb0_shell::ReleaseScriptRunLock()
{
    if (*(int*)((char*)this + 8) > 0)
        ::WaitForSingleObjectEx((long *)(void *)((char*)&this->prefix[4]));
}

namespace fnv_0043b1b0 {
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
struct FUN_0043b1b0_shell : public NiFixedString
{
    void FUN_0043b1b0();
};

void __cdecl FUN_0043b1d0(void*);

// @fnv 0x0043b1b0
void FUN_0043b1b0_shell::FUN_0043b1b0()
{
    FUN_0043b1d0(this);
}
}  // namespace fnv_0043b1b0


// @fnv 0x0043b1e0
int GetRefAt21C(const char* pThis)
{
    return reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(pThis + 0x21c))->FUN_0084e3a0();
}

struct BSStringT_char
{
    operator const char*() const;
};
struct BSSimpleArray_uint_1024
{
    BSStringT_char& GetAt(unsigned int);
};
struct MLx
{
    char pad[0x8];
    char unk08;
    char pad09[0x213];
    BSSimpleArray_uint_1024 arr;
    const char* GetStringAt(unsigned int i);
};
// Returns the string stored at index i in the arr array.
// @fnv 0x0043b200
const char* MLx::GetStringAt(unsigned int auiIndex)
{
    return arr.GetAt(auiIndex);
}

namespace fnv_0043b230 {
template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x0043b230
const char* FUN_0043b230(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x0c);
}
}  // namespace fnv_0043b230

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
struct FUN_0043b4d0_shell : public CFilter
{
    int FUN_0043b4d0();
};

// @fnv 0x0043b4d0
int FUN_0043b4d0_shell::FUN_0043b4d0()
{
    return iFilter & 0x7f;
}

struct FormChangeMask
{
    int v;
    FormChangeMask(int);
};
struct Col_0043b4f0
{
    int FUN_0043b540();
};
struct W_0043b4f0
{
    FormChangeMask FUN_0043b4f0();
};
// @fnv 0x0043b4f0
FormChangeMask W_0043b4f0::FUN_0043b4f0()
{
    Col_0043b4f0* pc = ((::Col_0043b4f0 *)(reinterpret_cast<::FUN_0043b560_shell *>(this)->GetSourceFilesFromObject()));
    return FormChangeMask(pc ? pc->FUN_0043b540() : 0);
}

struct hkpTypedBroadPhaseHandle
{
};

// @fnv 0x0043b540
unsigned int FUN_0043b540(char* pThis)
{
    return ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((hkpTypedBroadPhaseHandle*)(pThis + 0x14))))->GetName()));
}

struct BSFile;
struct NiMemObject
{
    char _pad_0[1];
};
struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
struct FUN_0043bb80_shell : public LoadedFile
{
    void DestroyLoadedFile();
};

struct BSFile
{
    virtual ~BSFile();
};

struct _ModelLoaderStub00448370
{
};

struct _LogStub0043bd00
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(int, const char*, int, int, int);
};

bool __cdecl IsHeapLoggerPresent();
_LogStub0043bd00* __cdecl FUN_0043bd00();

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0043be10
int FUN_0043be10(char* pThis)
{
    return InitScriptRunLock(pThis + 0x10);
}

struct GO
{
    GO(int);
    ~GO();
    int v;
};
struct QBase
{
    QBase(int);
    virtual ~QBase();
    char pad[0x2c];
};
struct FUN_0043bef0 : QBase
{
    GO g;
    char flag;
    FUN_0043bef0(NiNode* n, int a);
    virtual ~FUN_0043bef0();
};
// @fnv 0x0043bef0
FUN_0043bef0::FUN_0043bef0(NiNode* apNode, int aiArg) : QBase(aiArg), g(0)
{
    flag = 0;
    ((NiPointer<NiNode>*)&g)->operator=(apNode);
    ::SetFieldCToFive((char *)this);
}

struct IOV_0043c050
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
    virtual void Slot(void*);
};
struct ML_0043c050
{
    bool InsertQueuedTexture(BSFileEntry*, void*);
};
struct Q_0043c050 : public QueuedTexture
{
    void FUN_0043c100(bool);
    void FUN_0043c050();
};
struct FUN_0043c100_shell : public QueuedTexture
{
    void FUN_0043c100(bool);
};


// Forwards abValue and the object's field at offset 0x34 to FUN_0044aea0.
// @fnv 0x0043c100
void FUN_0043c100_shell::FUN_0043c100(bool abValue)
{
    ::FUN_0044aea0(abValue, (unsigned char *)(void *)(reinterpret_cast<char*>(this) + 0x34));
}

struct FUN_0043c130_shell : public ModelLoader
{
    bool IsLoadTexturesDegraded();
};

struct TLSData
{
    char _pad[0x25c];
    bool bLoadTexturesDegraded;
};

__declspec(thread) TLSData g_tlsData;

// Returns the thread-local flag that indicates whether textures are being loaded in degraded mode.
// @fnv 0x0043c130
bool FUN_0043c130_shell::IsLoadTexturesDegraded()
{
    return (*reinterpret_cast<::TLSData *>(&::g_tlsBlock)).bLoadTexturesDegraded;
}

struct FUN_0043c3d0_shell : public QueuedTexture
{
    bool FUN_0043c3d0();
};


// @fnv 0x0043c3d0
bool FUN_0043c3d0_shell::FUN_0043c3d0()
{
    return ((bool)(::fnv_0044ae50::FUN_0044ae50(*(unsigned char*)((char*)this + 0x34))));
}

struct _TLS_0043c3f0
{
    char _pad[0x29c];
    unsigned int val;
};

// @fnv 0x0043c3f0
void __cdecl FUN_0043c3f0(unsigned int aiLoadMethod)
{
    (*reinterpret_cast<::_TLS_0043c3f0 *>(&::g_tlsBlock)).val = aiLoadMethod;
}

// @fnv 0x0043c410
int FUN_0043c410()
{
    static __declspec(thread) int tls_data[0x29c / 4 + 1];
    return tls_data[0x29c / 4];
}

class BSFileEntryMap
{
  public:
    void FUN_0043c4f0(NiNode*, NiPointer<NiNode>&);
};
BSFileEntryMap* DAT_011f4468;

// @fnv 0x0043c4c0
void GetNodePointer(NiNode* apNode, NiPointer<NiNode>& apNodePtr)
{
    apNodePtr = 0;
    DAT_011f4468->FUN_0043c4f0(apNode, apNodePtr);
}


struct FUN_0043c4f0_shell
{
    void FUN_0043c4f0(int a1, int a2);
};

// Computes a value from a1 via FUN_0043c530, then calls GetByKey with that value, a1 and a2.
// @fnv 0x0043c4f0
void FUN_0043c4f0_shell::FUN_0043c4f0(int a1, int aiArg)
{
    int v = ((int)(::FUN_0043c530(a1)));
    reinterpret_cast<::FUN_00a61a60_cls *>(this)->GetByKey(v, a1, (*(::NiRefObject * *)(aiArg)));
}

// @fnv 0x0043c530
unsigned int __cdecl FUN_0043c530(unsigned int uiValue)
{
    return (uiValue >> 4) % 1001;
}

struct FUN_0043c610_shell : public QueuedFile
{
    void RunVirtualMethod28();
};

// @fnv 0x0043c610
void FUN_0043c610_shell::RunVirtualMethod28()
{
    (*(void(**)(QueuedFile*))(*(int*)this + 0x28))(this);
}

struct FUN_0043c630_shell : public QueuedTexture
{
    bool FUN_0043c630();
};


// @fnv 0x0043c630
bool FUN_0043c630_shell::FUN_0043c630()
{
    return ((bool)(::fnv_0044ae90::FUN_0044ae90(*((unsigned char*)this + 0x34))));
}


struct FUN_0043c7a0_arg
{
    unsigned char val;
};

// Passes arg.val and the address pThis+0x3c to SetFlagBit0.
// @fnv 0x0043c7a0
void FUN_0043c7a0(char* pThis, FUN_0043c7a0_arg aByteArg)
{
    ::SetFlagBit0(aByteArg.val, (unsigned char *)(void *)(pThis + 0x3c));
}


struct FUN_0043c7d0_shell
{
    void FUN_0043c7d0(unsigned char param_1);
};

// @fnv 0x0043c7d0
void FUN_0043c7d0_shell::FUN_0043c7d0(unsigned char aByte)
{
    ::FUN_0044ae60(aByte, (unsigned char *)(void *)((char*)this + 0x3c));
}

void FUN_0044b160(void*);
void FUN_00c3cea0(void*);

struct _Base_00441d20
{
    char _pad[0x30];
    ~_Base_00441d20()
    {
        FUN_00c3cea0(this);
    }
};

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        FUN_0044b160(this);
    }
};

struct FUN_0043c830 : _Base_00441d20
{
    _Mem_00441d20 m;
    int b;
    ~FUN_0043c830();
};

// Destructor for FUN_0043c830; destroys its _Mem_00441d20 member and _Base_00441d20 base.
// @fnv 0x0043c830
FUN_0043c830::~FUN_0043c830()
{}

struct FUN_0043caa0_shell : public QueuedFile
{
    bool FUN_0043caa0();
};
// @fnv 0x0043e770
void QueuedAnimIdle::OnChildCompletion()
{
    if (::FUN_00449110((int *)this) && reinterpret_cast<::FUN_0043caa0_shell *>(this)->FUN_0043caa0())
        reinterpret_cast<::IOManager *>(this)->SubmitTask();
}
// @fnv 0x0043ec60
void QueuedHead::OnChildCompletion()
{
    if (reinterpret_cast<::FUN_0043caa0_shell *>(this)->FUN_0043caa0())
    {
        if (::IsFieldCZero((::Dummy_0069b080 *)(reinterpret_cast<NiTPointerMap<unsigned int, SoundPlaybackHandle*>*>(this))))
            ::DAT_01202d98->vfn_48(this);
        else
            reinterpret_cast<::ObjectC3 *>(this)->NotifyParents();
    }
}


// @fnv 0x0043caa0
bool FUN_0043caa0_shell::FUN_0043caa0()
{
    return *(void**)((char*)this + 0x20)
               ? ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((*(void**)((char*)this + 0x20)))->GetName())) == ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((*(void**)((char*)this + 0x20)))->FUN_0044edb0()))
               : true;
}

struct FUN_0043caf0_shell : public QueuedModel
{
    bool FUN_0043caf0();
};
// @fnv 0x0043ca30
void QueuedModel::OnChildCompletion()
{
    if (!reinterpret_cast<::FUN_0043caf0_shell *>(this)->FUN_0043caf0())
        reinterpret_cast<::ObjectC3 *>(this)->NotifyParents();
    else if (reinterpret_cast<::FUN_0043caa0_shell *>(this)->FUN_0043caa0())
    {
        if (::IsFieldCZero((::Dummy_0069b080 *)(reinterpret_cast<NiTPointerMap<unsigned int, SoundPlaybackHandle*>*>(this))))
            ::DAT_01202d98->vfn_48(this);
        else
            reinterpret_cast<::ObjectC3 *>(this)->NotifyParents();
    }
}


// @fnv 0x0043caf0
bool FUN_0043caf0_shell::FUN_0043caf0()
{
    return ((bool)(::fnv_0044ae90::FUN_0044ae90(*((unsigned char*)this + 0x3c))));
}

struct FUN_0043cc60_shell : public IOTask
{
    int FUN_0043cc60();
};


struct FUN_0043cc80_shell : public IOTask
{
    unsigned char FUN_0043cc80();
};
// @fnv 0x0043cc60
int FUN_0043cc60_shell::FUN_0043cc60()
{
    return reinterpret_cast<::FUN_0043cc80_shell *>((this))->FUN_0043cc80();
}

// @fnv 0x0043cc80
unsigned char FUN_0043cc80_shell::FUN_0043cc80()
{
    return GetPriorityFromKey(*(__int64*)((char*)this + 0x10));
}

struct FUN_0043ccc0_shell : public QueuedModel
{
    void FUN_0043ccc0(bool);
};


// Passes abValue and the address of the object's 0x3c offset to FUN_0044aea0.
// @fnv 0x0043ccc0
void FUN_0043ccc0_shell::FUN_0043ccc0(bool abValue)
{
    ::FUN_0044aea0(abValue, (unsigned char *)(void *)((char*)this + 0x3c));
}

struct FUN_0043cf40_shell : public QueuedModel
{
    bool FUN_0043cf40();
};


// @fnv 0x0043cf40
bool FUN_0043cf40_shell::FUN_0043cf40()
{
    return ((bool)(::fnv_0044ae10::FUN_0044ae10(*((unsigned char*)this + 0x3c))));
}

struct FUN_0043cf60_shell : public QueuedModel
{
    void FUN_0043cf60(bool);
};


// @fnv 0x0043cf60
void FUN_0043cf60_shell::FUN_0043cf60(bool abValue)
{
    ::SetFlag8(abValue, (unsigned char *)(void *)((char*)this + 0x3c));
}

struct FUN_0043cf90_shell : public QueuedModel
{
    bool FUN_0043cf90();
};


// @fnv 0x0043cf90
bool FUN_0043cf90_shell::FUN_0043cf90()
{
    return ((bool)(::fnv_0044af60::FUN_0044af60(*((unsigned char*)this + 0x3c))));
}

struct FUN_0043cfb0_shell : public QueuedModel
{
    bool FUN_0043cfb0();
};


// @fnv 0x0043cfb0
bool FUN_0043cfb0_shell::FUN_0043cfb0()
{
    return ((bool)(::fnv_0044afa0::FUN_0044afa0(*((unsigned char*)this + 0x3c))));
}

struct FUN_0043d490_shell : public QueuedModel
{
    bool FUN_0043d490();
};


// @fnv 0x0043d490
bool FUN_0043d490_shell::FUN_0043d490()
{
    return ((bool)(::fnv_0044ae50::FUN_0044ae50(*((unsigned char*)this + 0x3c))));
}

struct FUN_0043d4b0_shell : public QueuedModel
{
    bool FUN_0043d4b0();
};


// @fnv 0x0043d4b0
bool FUN_0043d4b0_shell::FUN_0043d4b0()
{
    return ((bool)(::fnv_0044af20::FUN_0044af20(*((unsigned char*)this + 0x3c))));
}

struct FUN_0043dbb0_shell : public IOTask
{
    void SetRequestParams(char, unsigned int, unsigned char, unsigned short);
};

// Packs file index, offset, priority and counter into a 64-bit value stored at offset 0x10 of this object.
// @fnv 0x0043dbb0
void FUN_0043dbb0_shell::SetRequestParams(char acFileIndex, unsigned int aiOffset, unsigned char acPriority,
                                          unsigned short asCounter)
{
    *reinterpret_cast<__int64*>(reinterpret_cast<char*>(this) + 0x10) =
        (static_cast<__int64>(acFileIndex) << 56) | (static_cast<unsigned __int64>(aiOffset) << 24) |
        (static_cast<__int64>(acPriority) << 16) | static_cast<__int64>(asCounter);
}

namespace fnv_0043dc10 {
struct FUN_0043dc10_shell : public IOTask
{
    unsigned short FUN_0043dc10();
};

unsigned short __cdecl InitScriptRunLock(void*);

// @fnv 0x0043dc10
unsigned short FUN_0043dc10_shell::FUN_0043dc10()
{
    return InitScriptRunLock(&DAT_01202d9c);
}
}  // namespace fnv_0043dc10

struct FUN_0043dc30_shell : public IOTask
{
    unsigned int InitScriptRunLockTask();
};

extern int DAT_01202da0;
int __cdecl InitScriptRunLock(void*);

// @fnv 0x0043dc30
unsigned int FUN_0043dc30_shell::InitScriptRunLockTask()
{
    return InitScriptRunLock(&DAT_01202da0);
}

struct EffectSetting;
struct MagicItem;
struct QueuedMagicItem : public QueuedFile
{
    virtual void __vslot_0();
    virtual void DispatchToManager();
    virtual void OnChildCompletion();
    char _pad_4[36];
    MagicItem* pMagicItem;
    EffectSetting* m_pEffectSetting;
};
struct FUN_0043e080_shell : public QueuedMagicItem
{
    void ProcessQueuedMagicItem();
};


struct FUN_0043e080_vdtor
{
    virtual ~FUN_0043e080_vdtor();
};

// @fnv 0x0043e080
void FUN_0043e080_shell::ProcessQueuedMagicItem()
{
    if (::FUN_00449110((int *)(reinterpret_cast<IOTask*>(this))) && reinterpret_cast<::FUN_0043caa0_shell *>((reinterpret_cast<IOTask*>(this)))->FUN_0043caa0())
    {
        reinterpret_cast<::FUN_0040ab70_shell *>((pMagicItem))->PreloadModels();
        if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((this))->GetName())) == 0)
        {
            delete reinterpret_cast<FUN_0043e080_vdtor*>(this);
        }
    }
}

namespace fnv_0043e1b0 {
void FUN_0044b160(void*);
void FUN_00c3cea0(void*);

struct _Base_00441d20
{
    char _pad[0x30];
    ~_Base_00441d20()
    {
        FUN_00c3cea0(this);
    }
};

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        FUN_0044b160(this);
    }
};

struct FUN_0043e1b0 : _Base_00441d20
{
    _Mem_00441d20 m;
    int b;
    ~FUN_0043e1b0();
};

// @fnv 0x0043e1b0
FUN_0043e1b0::~FUN_0043e1b0()
{}
}  // namespace fnv_0043e1b0

struct FUN_0043e480_shell : public QueuedKF
{
    void FUN_0043e480(bool);
};


// @fnv 0x0043e480
void FUN_0043e480_shell::FUN_0043e480(bool abValue)
{
    ::SetFlagBit0(abValue, (unsigned char *)(void *)((char*)this + 0x34));
}

namespace fnv_0043e4b0 {
struct KFModelLookup
{
    KFModel* Lookup(const char*);
};
struct Tile
{
    Tile* GetParent() const;
};
template <class T> struct BSStringT
{
    operator const T*() const;
};
struct LoaderStandIn : KFModelLookup
{
};
struct QK_0043e4b0 : Tile
{
    char pad[0x30];
    BSStringT<char> name;
    unsigned char FUN_0043e530();
    void FUN_0043e4b0();
};
// @fnv 0x0043e4b0
void QK_0043e4b0::FUN_0043e4b0()
{
    if (name && !FUN_0043e530() &&
        !((unsigned char)(reinterpret_cast<::S_00447040 *>((reinterpret_cast<LoaderStandIn*>(g_modelLoader)))->CallVirtWithLocal((int)(((::fnv_0043e4b0::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)this)->FUN_0045cd60()))), (int)(name)))))
    {
        reinterpret_cast<::NiPointer_KFModel *>((reinterpret_cast<NiPointer<KFModel>*>(&name)))->FUN_0044b070=(
            reinterpret_cast<::KFModelLookup *>((reinterpret_cast<LoaderStandIn*>(g_modelLoader)))->Lookup(reinterpret_cast<const char*>(((::fnv_0043e4b0::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)this)->FUN_0045cd60())))));
    }
    reinterpret_cast<::FUN_0043c610_shell *>(this)->RunVirtualMethod28();
}
}  // namespace fnv_0043e4b0

struct FUN_0043e530_shell : public QueuedTexture
{
    bool FUN_0043e530();
};


// @fnv 0x0043e530
bool FUN_0043e530_shell::FUN_0043e530()
{
    return ((bool)(::fnv_0044ae10::FUN_0044ae10(*((unsigned char*)this + 0x34))));
}

struct TESObjectANIO;
struct FUN_0043e750_shell : public AnimIdle
{
    TESObjectANIO* GetObjectANIO(int);
};

// @fnv 0x0043e750
TESObjectANIO* FUN_0043e750_shell::GetObjectANIO(int aiIndex)
{
    return ((TESObjectANIO**)((char*)this + 0x1c))[aiIndex];
}

struct FUN_0043e810_shell : public ModelLoader
{
    void DispatchAnimIdle(AnimIdle*);
};
// @fnv 0x0043e7b0
void QueuedAnimIdle::ProcessLoadedAnimIdle()
{
    if (reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x30)->operator QueuedFile*() &&
        !::FUN_00449130((int *)this))
        reinterpret_cast<::FUN_00496cd0_cls *>((reinterpret_cast<AnimIdle*>(
            reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x3c)->operator QueuedFile*())))->InitFromModel((::KFModelX *)(::KFModel *)(reinterpret_cast<KFModel*>(
                reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x30)
                    ->
                    operator QueuedFile*())));
    reinterpret_cast<::FUN_0043e810_shell *>((g_modelLoader))->DispatchAnimIdle(
        (::AnimIdle *)(::QueuedFile *)(reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0x3c)->operator QueuedFile*()));
}

struct Vtbl0043e810
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(AnimIdle*);
};

// Forwards apAnimIdle to the virtual v5 method of the object stored at this+0x10.
// @fnv 0x0043e810
void FUN_0043e810_shell::DispatchAnimIdle(AnimIdle* apAnimIdle)
{
    (*reinterpret_cast<Vtbl0043e810**>(reinterpret_cast<char*>(this) + 0x10))->v5(apAnimIdle);
}

namespace fnv_0043fad0 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x0043fad0
const char* FUN_0043fad0(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0xbc);
}
}  // namespace fnv_0043fad0

struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};

// @fnv 0x0043faf0
unsigned char FUN_0043faf0()
{
    return *(*reinterpret_cast<::ProcessLists *>(&::g_011d5a44)).GetLifeStateControlFlag();
}

struct FUN_00440490_shell : public NiAVObject
{
    void FUN_00440490(float);
};


// Stores the result of FUN_00408820(fScale) into the float at offset 0x64 of this object.
// @fnv 0x00440490
void FUN_00440490_shell::FUN_00440490(float fScale)
{
    *(float*)((char*)this + 0x64) = ((float)(::FUN_00408820(fScale)));
}

struct FUN_004405b0_S
{
    void FUN_004405b0(unsigned char p);
};
struct QR2;
struct BCT
{
    void FUN_00442580(QR2*);
};
struct FUN_004408d0_S
{
    char pad[0x28];
    BCT* t;
    void ForwardToBCT(QR2* q);
};
// @fnv 0x004408d0
void FUN_004408d0_S::ForwardToBCT(QR2* q)
{
    t->FUN_00442580(q);
}

void __cdecl FinishScriptRunLock(void*);

// @fnv 0x00440a10
void FinishScriptRunLockAndReset(char* pThis)
{
    ::WaitForSingleObjectEx((long *)(void *)(pThis + 0xa4));
    if (*reinterpret_cast<int*>(pThis + 0xa4) < 0)
        *reinterpret_cast<int*>(pThis + 0xa4) = 0;
}

void __cdecl FinishScriptRunLock(void*);

// Calls FinishScriptRunLock on pThis+0xa0, then clamps the int at pThis+0xa0 to 0 if it is negative.
// @fnv 0x00440a50
void FinishScriptRun(char* pThis)
{
    ::WaitForSingleObjectEx((long *)(void *)(pThis + 0xa0));
    if (*(int*)(pThis + 0xa0) < 0)
    {
        *(int*)(pThis + 0xa0) = 0;
    }
}

extern int DAT_01016ca4;
struct S4411
{
    void FUN_0043fd40(int, int);
    S4411* FUN_004411d0(int a, int b);
};
__declspec(thread) char _tls_pad_00441290[0x25c];
__declspec(thread) bool _tls_var_00441290;

struct _FUN_00441290_shell
{
    bool SetTlsFlag(bool bVal);
};

// Stores bVal into the thread-local flag and returns its previous value.
// @fnv 0x00441290
bool _FUN_00441290_shell::SetTlsFlag(bool abValue)
{
    bool bOld = _tls_var_00441290;
    _tls_var_00441290 = abValue;
    return bOld;
}

extern int DAT_01016cec;

struct FUN_004411d0
{
    FUN_004411d0(int, int);
    ~FUN_004411d0();
};

struct GlobalObject_00528cb0
{
    int m_val;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};

struct FUN_00441440 : public FUN_004411d0
{
    void* vftable;
    char pad[0x3c];
    GlobalObject_00528cb0 m_40;
    GlobalObject_00528cb0 m_44;

    FUN_00441440(int a, int b);
};

// Constructs the object: calls the base constructor, sets the vftable to DAT_01016cec, and initializes m_40 and m_44 to 0.
// @fnv 0x00441440
FUN_00441440::FUN_00441440(int a, int b) : FUN_004411d0(a, b), vftable(&DAT_01016cec), m_40(0), m_44(0)
{}

extern __declspec(thread) void* DAT_00441780_260;

// Stores apRef and ap3D into the thread-local pointers DAT_00441780_264 and DAT_00441780_260.
// @fnv 0x00441780
void __cdecl FUN_00441780(void* apRef, void* ap3D)
{
    (*reinterpret_cast<void * *>(&::DAT_tls_0264)) = apRef;
    DAT_00441780_260 = ap3D;
}

struct _TLS_Pad_004417c0
{
    char pad[0x260];
    int v260;
    int v264;
};

__declspec(thread) _TLS_Pad_004417c0 tls_004417c0;

// Clears the two int fields at offsets 0x260 and 0x264 in the thread-local block.
// @fnv 0x004417c0
void FUN_004417c0()
{
    (*reinterpret_cast<::_TLS_Pad_004417c0 *>(&::g_tlsBlock)).v264 = 0;
    (*reinterpret_cast<::_TLS_Pad_004417c0 *>(&::g_tlsBlock)).v260 = 0;
}

enum MEM_CONTEXT
{
};
struct LightTarget;
struct VATS
{
    LightTarget* FUN_005d8710(void);
};

struct AutoMemContext_1
{
    AutoMemContext_1(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext_1(void);
    int a;
};

struct TESAttackDamageForm_1
{
    virtual void Free(void);
};

void AttachHeadAndFaceParts(void* pThis);

// Frees the object under a memory context, then calls AttachHeadAndFaceParts if FUN_005d8710 returns null.
// @fnv 0x00441820
void FUN_00441820(char* apObject)
{
    AutoMemContext_1 tempMemContext(*(MEM_CONTEXT*)(apObject + 0x18), true,
                                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8ff);
    reinterpret_cast<::TESForm *>((((TESAttackDamageForm_1*)apObject)))->ClearData();
    if (!((VATS*)apObject)->FUN_005d8710())
    {
        AttachHeadAndFaceParts(apObject);
    }
}

namespace fnv_004418b0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnimObject;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFaceGenModel;
struct BSShaderPPLightingProperty;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiPoint3;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESIdleForm;
struct TESNPC;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectLIGH;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_004418b0_shell : public QueuedCharacter
{
    void AttachHeadAndFaceParts();
};

struct Biped;

template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

struct TESObjectREFR_Helper
{
};

struct HeadPart_Helper
{
    void Attach(TESObjectREFR* pRefr, Biped* pBiped);
};

struct FacePart_Helper
{
    void Attach();
};

void FUN_0043ed90(const char* pHead, int unused, TESObjectREFR* pRefr, Biped* pBiped);
void ApplyQueuedModels(const char* pFace);

// @fnv 0x004418b0
void FUN_004418b0_shell::AttachHeadAndFaceParts()
{
    TESObjectREFR* pcharacter = *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0x28);
    Biped* pbiped = ((::fnv_004418b0::Biped *)(::FUN_005d9f90((char *)(reinterpret_cast<TESObjectREFR_Helper*>(pcharacter)))));

    if (static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x40)))
    {
        reinterpret_cast<HeadPart_Helper*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x40))))
            ->Attach(*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0x28), pbiped);
    }

    if (static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x44)))
    {
        reinterpret_cast<FacePart_Helper*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x44))))
            ->Attach();
    }
}
}  // namespace fnv_004418b0

extern int DAT_01016d7c;
struct PlayerCharacter;
struct S1b20
{
    void FUN_00441440(PlayerCharacter*, int);
    S1b20* InitWithPlayer(int a);
};
// Calls FUN_00441440 with pPlayer and a, sets the first field of this to point at DAT_01016d7c, and returns this.
// @fnv 0x00441b20
S1b20* S1b20::InitWithPlayer(int a)
{
    new ((void *)this) ::FUN_00441440((int)(::_g_thePlayer), a);
    *reinterpret_cast<int**>(this) = &DAT_01016d7c;
    return this;
}

namespace fnv_00441d20 {
void FUN_0044b160(void*);
void FUN_00c3cea0(void*);

struct _Base_00441d20
{
    char _pad[0x30];
    ~_Base_00441d20()
    {
        FUN_00c3cea0(this);
    }
};

struct _Mem_00441d20
{
    int a;
    ~_Mem_00441d20()
    {
        FUN_0044b160(this);
    }
};

struct FUN_00441d20 : _Base_00441d20
{
    _Mem_00441d20 m;
    int b;
    ~FUN_00441d20();
};

// Destructor: destroys the embedded member and then the base subobject.
// @fnv 0x00441d20
FUN_00441d20::~FUN_00441d20()
{}
}  // namespace fnv_00441d20

struct BSSemaphore_
{
    void Wait();
};

// @fnv 0x004424c0
void FUN_004424c0(char* this_ptr)
{
    ((BSSemaphore_*)(this_ptr + 0xc))->Wait();
}

struct FUN_00442510_Cl
{
    char pad[0x18];
    CountingSemaphore sem;
    void Wait();
};

// @fnv 0x00442510
void FUN_00442510(FUN_00442510_Cl* pThis)
{
    reinterpret_cast<void (CountingSemaphore::*)()>(&FUN_00442510_Cl::Wait);
    ((FUN_00442510_Cl*)((char*)pThis + 0x18))->Wait();
}

// @fnv 0x00442530
void SignalAtOffset18(char* this_ptr)
{
    ((CountingSemaphore*)(this_ptr + 0x18))->Signal();
}

struct FUN_00442550_shell : public CountingSemaphore
{
    int ReleaseAndInitScriptRunLock();
};
// If the NiPointer<QueuedFile> at offset 0xC is null, calls Signal on the object at that offset.
// @fnv 0x00442600
void ModelLoader::ProcessQueuedFile()
{
    if (!reinterpret_cast<NiPointer<QueuedFile>*>(reinterpret_cast<char*>(this) + 0xC)->operator QueuedFile*())
        reinterpret_cast<::FUN_00442550_shell *>((reinterpret_cast<CountingSemaphore*>(reinterpret_cast<char*>(this) + 0xC)))->ReleaseAndInitScriptRunLock();
}

int __cdecl InitScriptRunLock(void*);

// Releases the semaphore stored at this+4 by one count, then calls InitScriptRunLock with this and returns its result.
// @fnv 0x00442550
int FUN_00442550_shell::ReleaseAndInitScriptRunLock()
{
    ReleaseSemaphore(*(void**)((char*)this + 4), 1, 0);
    return InitScriptRunLock(this);
}

namespace fnv_00442580 {
struct GlobalObject_00528cb0
{
    int v;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};
struct Sub
{
};
struct ML2
{
    char pad[0x38];
    Sub* p;
    void FUN_00442580(int a);
};
// @fnv 0x00442580
void ML2::FUN_00442580(int a)
{
    {
        GlobalObject_00528cb0 g(a);
        ::FUN_00449240((::LockedReceiver *)(p), (::ReceiverArgument)(&g));
    }
    reinterpret_cast<::ModelLoader *>(this)->ProcessQueuedFile();
}
}  // namespace fnv_00442580

struct FUN_00443190_shell : public Model
{
    int GetCombinedValue();
};

// @fnv 0x00443190
int FUN_00443190_shell::GetCombinedValue()
{
    return *(int*)((char*)this + 4) + *(int*)((char*)this + 8);
}

// @fnv 0x004431b0
int FUN_004431b0(int* p)
{
    return p[3] + p[4];
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x00444cc0
void InitScriptRunLockForObject(char* pThis)
{
    ::FUN_0040b460((unsigned int *)(void *)(pThis + 0xa4));
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x00444ce0
void FUN_00444ce0(char* pThis)
{
    ::FUN_0040b460((unsigned int *)(void *)(pThis + 0xa0));
}

struct FUN_00444ed0_shell : public TESObjectREFR
{
    bool FUN_00444ed0();
};

struct TESFile
{
    const char* GetName();
};

// Reads a TESObject pointer from the file name and, if non-null, calls its virtual function at offset 0x154, returning the result or false.
// @fnv 0x00444ed0
bool FUN_00444ed0_shell::FUN_00444ed0()
{
    TESObject* pObject = *reinterpret_cast<TESObject* const*>(((const char *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<TESFile*>(this)))->GetShotList())));
    return pObject ? (reinterpret_cast<bool(**)(TESObject*)>(*reinterpret_cast<void***>(pObject))[0x154 / 4])(
                         pObject)
                   : false;
}

struct FUN_00445300_shell : public ModelLoader
{
    void FUN_00445300(char*, bool, unsigned int);
};

struct ModelStub
{
};
struct LoaderStub
{
    void FUN_00448920(ModelStub*, const char*);
};
struct ModelMapStub
{
    virtual void a();
    virtual void b();
    virtual bool Lookup(const char*, ModelStub**);
};
struct ModelMapHolder
{
    ModelMapStub* m_pLoadedModelMap;
};

struct FUN_00447190_dummy
{
    void FUN_00447190(unsigned char arg1);
};

// Calls FUN_0044af70 with arg1 and a pointer to this object at offset 0x3c.
// @fnv 0x00447190
void FUN_00447190_dummy::FUN_00447190(unsigned char aByte)
{
    ::FUN_0044af70(aByte, (unsigned char *)(void *)((char*)this + 0x3c));
}

struct FUN_004472a0_shell : public ModelLoader
{
    bool FUN_004472a0(char*, void*);
};

struct VHelper
{
    virtual ~VHelper()
    {}
    virtual void _v1()
    {}
    virtual bool Get(char*, void**)
    {
        return 0;
    }
};

struct ModelLoaderAccess
{
    VHelper* m_pLoadedModelMap;
};

struct SetterHelper
{
};

struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiCamera;
struct NiColor;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESClimate;
struct TESFile;
struct TESGlobal;
struct TESImageSpace;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
struct FUN_00447950_shell : public ModelLoader
{
    bool FUN_00447950(TESObjectCELL*);
};

class Tile;
class InterfaceManager
{
  public:
};

// Returns true if apCell is non-null and its InterfaceManager FUN_004fd400 result is greater than zero.
// @fnv 0x00447950
bool FUN_00447950_shell::FUN_00447950(TESObjectCELL* apCell)
{
    if (apCell && reinterpret_cast<int>(((::Tile *)(reinterpret_cast<::MagicProjectile *>((reinterpret_cast<InterfaceManager*>(apCell)))->FUN_004fd400()))) > 0)
        return true;
    return false;
}

namespace fnv_00448920 {
struct FUN_00448920_shell : public ModelLoader
{
    void FUN_00448920(Model*, char*);
};



struct ModelDeleteStub
{
    void* FUN_004431f0(unsigned int);
};

struct ModelMapStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Remove(char*);
};

struct BGSSaveLoadGameAccess : public BGSSaveLoadGame
{
};

// @fnv 0x00448920
void FUN_00448920_shell::FUN_00448920(Model* apModel, char* apModelFileName)
{
    if (reinterpret_cast<::FUN_00443190_shell *>((apModel))->GetCombinedValue() == 0)
    {
        bool bremoveFromMap = true;
        if (::g_BGSSaveLoadGame && reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((((BGSSaveLoadGameAccess*)::g_BGSSaveLoadGame)))->FUN_0042ce10())
        {
            bremoveFromMap = false;
            *((bool*)((char*)this + 0x2c)) = true;
        }
        if (bremoveFromMap)
        {
            (*(ModelMapStub**)this)->Remove(apModelFileName);
            ModelDeleteStub* tmp1 = (ModelDeleteStub*)apModel;
            ModelDeleteStub* tmp2 = tmp1;
            tmp2 ? tmp2->FUN_004431f0(1) : 0;
        }
    }
}
}  // namespace fnv_00448920

struct FUN_00448a60_struct
{
    unsigned int pad[3];
    unsigned int val;
    unsigned int GetMaskedValue(unsigned int mask);
};
// @fnv 0x00448a40
bool BSXFlags::GetAddon() const
{
    return reinterpret_cast<::FUN_00448a60_struct *>((void *)this)->GetMaskedValue(0x10) != 0;
}

// @fnv 0x00448a60
unsigned int FUN_00448a60_struct::GetMaskedValue(unsigned int mask)
{
    return val & mask;
}

// @fnv 0x00448de0
bool IsNotStateSix(int param_1)
{
    return *(int*)(param_1 + 0x68) != 6;
}

// Sets both 64-bit elements of the given array to zero and returns the array pointer.
// @fnv 0x00448e00
__int64* ClearPair(__int64* param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    return param_1;
}


struct FUN_00448e30_this
{
    __int64 a;
    __int64 b;
    void init(float f);
};

// Stores the result of FUN_00aa4d80 in a and f multiplied by DAT_011ac39c in b.
// @fnv 0x00448e30
void FUN_00448e30_this::init(float afValue)
{
    a = ((long long)(::FUN_00aa4d80()));
    b = (__int64)(afValue * DAT_011ac39c);
}


// @fnv 0x00448e70
bool FUN_00448e70(__int64* pThis)
{
    return (((long long)(::FUN_00aa4d80())) - pThis[0]) > pThis[1];
}

namespace fnv_00448f50 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
struct FUN_00448f50_shell : public ModelLoader
{
    void ForwardToVTableSlot(BSFileEntry*);
};

struct _DummyVTable_00448f50
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(BSFileEntry*);
};

// Calls the virtual method at vtable slot 5 on the object stored at this+0x20, passing apFileEntry.
// @fnv 0x00448f50
void FUN_00448f50_shell::ForwardToVTableSlot(BSFileEntry* apFileEntry)
{
    (*reinterpret_cast<_DummyVTable_00448f50**>(reinterpret_cast<char*>(this) + 0x20))->v5(apFileEntry);
}
}  // namespace fnv_00448f50

// @fnv 0x00449050
int __cdecl FUN_00449050(int aeIOFileIndex)
{
    switch (aeIOFileIndex)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    default:
        return 8;
    }
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x00449090
void* FUN_00449090(void* apObject)
{
    *((void**)apObject) = &DAT_01017138;
    *((int*)((char*)apObject + 8)) = 0;
    *((int*)((char*)apObject + 0xc)) = 0;
    *((__int64*)((char*)apObject + 0x10)) = 0;
    ::FUN_0040b460((unsigned int *)(void *)(&DAT_011c3b38));
    return apObject;
}

// @fnv 0x00449110
bool FUN_00449110(int* piValues)
{
    return piValues[3] >= 4;
}

// @fnv 0x00449130
bool FUN_00449130(int* pThis)
{
    return pThis[3] == 6;
}

// @fnv 0x00449150
void SetFieldCToFive(char* pObject)
{
    *reinterpret_cast<int*>(pObject + 0xc) = 5;
}


struct FUN_00449190_cls
{
    bool SetState(int eCurrentState, int eNewState);
};

// Calls FUN_004491c0 with a pointer to this object's field at offset 0xc, passing the new state and current state.
// @fnv 0x00449190
bool FUN_00449190_cls::SetState(int eCurrentState, int eNewState)
{
    return ::FUN_004491c0((volatile long *)(void *)((char*)this + 0xc), eNewState, eCurrentState);
}

int __cdecl FUN_0043b460(long volatile*, long, long);

class Interface
{
  public:
};

// @fnv 0x004491c0
bool __cdecl FUN_004491c0(long volatile* pVolatile, long param_2, long param_3)
{
    bool res = FUN_0043b460(pVolatile, param_3, param_2) == param_3;
    ::FUN_0040fbe0();
    return res;
}

struct E_00449210
{
};
struct C_00449210
{
    virtual void v0();
    virtual void v1();
    E_00449210** arr;
    void FUN_00449210(int idx, int val);
};
// Calls FUN_00449240 on the element at idx with val, then calls v1().
// @fnv 0x00449210
void C_00449210::FUN_00449210(int aiIndex, int val)
{
    ::FUN_00449240((::LockedReceiver *)(arr[aiIndex]), (::ReceiverArgument)(val));
    v1();
}

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
struct R449
{
};
struct Q449
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449* FUN_00449f80(void*);
    bool FUN_00449280(void*);
};
extern int DAT_0101732c;

struct FUN_004492c0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004492c0_shell* FUN_004492c0(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004492c0
FUN_004492c0_shell* FUN_004492c0_shell::FUN_004492c0(int a, int b, int c)
{
    FUN_0044c270(a, b, c);
    vtbl = (int)&DAT_0101732c;
    return this;
}

struct FUN_00449500_shell
{
    void FUN_00449500(const char* param_1, char** param_2);
};

// @fnv 0x00449500
void FUN_00449500_shell::FUN_00449500(const char* param_1, char** param_2)
{
    TaskQueueInterface::CopyStringToBuffer(*param_2, 0x100, param_1);
}

namespace fnv_00449530 {
struct RecursiveSpinLock
{
};
struct R530
{
    bool InvokeWithArgs();
};
struct FUN_00449530_S
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R530* FUN_00449f80(int, int);
    bool FUN_00449530(int a, int b);
};
// @fnv 0x00449530
bool FUN_00449530_S::FUN_00449530(int a, int b)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool r = FUN_00449f80(a, b)->InvokeWithArgs();
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return r;
}
}  // namespace fnv_00449530

namespace fnv_00449580 {
struct RecursiveSpinLock
{
};
struct R449b
{
    bool FUN_0044a130();
};
struct Q449b
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449b* FUN_00449f80(void*, void*, bool);
    bool FUN_00449580(void*, void*, bool);
};
// @fnv 0x00449580
bool Q449b::FUN_00449580(void* a, void* b, bool c)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool bResult = FUN_00449f80(a, b, c)->FUN_0044a130();
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return bResult;
}
}  // namespace fnv_00449580

namespace fnv_004495d0 {
struct RecursiveSpinLock
{
};
struct R449
{
    bool Pop();
};
struct Q449
{
    char pad[0x20];
    RecursiveSpinLock lock;
    R449* FUN_00449f80(void*);
    bool FUN_004495d0(void*);
};
// @fnv 0x004495d0
bool Q449::FUN_004495d0(void* arData)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool bResult = FUN_00449f80(arData)->Pop();
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return bResult;
}
}  // namespace fnv_004495d0

void FUN_0044a040(void*);

// @fnv 0x00449680
void FUN_00449680(void* p)
{
    FUN_0044a040(p);
}

namespace fnv_004496a0 {
extern int DAT_0101732c;

struct FUN_004496a0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004496a0_shell* FUN_004496a0(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004496a0
FUN_004496a0_shell* FUN_004496a0_shell::FUN_004496a0(int a, int b, int c)
{
    FUN_0044c270(a, b, c);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_004496a0


struct FUN_004496d0_shell
{
    bool IsGreaterOrEqual(const char* a, const char* b);
};

// Returns whether the result of FUN_00ec6da0(a, b) is greater than or equal to zero.
// @fnv 0x004496d0
bool FUN_004496d0_shell::IsGreaterOrEqual(const char* pcLeft, const char* pcRight)
{
    return std::strcmp(pcLeft, pcRight) >= 0;
}

namespace fnv_004497c0 {
extern int DAT_0101732c;

struct FUN_004497c0_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_004497c0_shell* FUN_004497c0(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x004497c0
FUN_004497c0_shell* FUN_004497c0_shell::FUN_004497c0(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_004497c0


struct FUN_00449880_Class
{
    bool FUN_00449880(const char* a, const char* b);
};

// Returns true when the comparison of the two strings via FUN_00ec6da0 yields zero.
// @fnv 0x00449880
bool FUN_00449880_Class::FUN_00449880(const char* pcStringA, const char* pcStringB)
{
    return std::strcmp(pcStringA, pcStringB) == 0;
}

extern int DAT_01017288;

// @fnv 0x004498e0
void* FUN_004498e0(void* apObject)
{
    reinterpret_cast<::FUN_0044cb70_Holder *>((apObject))->FUN_0044cb70();
    *reinterpret_cast<void**>(apObject) = &DAT_01017288;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(apObject) + 8) =
        reinterpret_cast<void*>(reinterpret_cast<char*>(apObject) + 0x10);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(apObject) + 0x10) = 0;
    return apObject;
}

extern int DAT_01017294;

// @fnv 0x00449940
void FUN_00449940(void** apOut)
{
    *apOut = &DAT_01017294;
}

extern int DAT_010172a0;

// @fnv 0x00449960
void* FUN_00449960(char* pThis)
{
    new ((void *)(pThis)) ::FUN_0044cbb0_class();
    *reinterpret_cast<int**>(pThis) = &DAT_010172a0;
    *reinterpret_cast<char**>(pThis + 8) = pThis + 0x10;
    pThis[0x10] = 0;
    return pThis;
}

extern int DAT_010172ac;

// @fnv 0x004499a0
void FUN_004499a0(int** ppTarget)
{
    *ppTarget = &DAT_010172ac;
}

extern int DAT_010172b8;

// @fnv 0x004499c0
void FUN_004499c0(void* pThis)
{
    *(int**)pThis = &DAT_010172b8;
}

extern int DAT_010172c4;

// @fnv 0x004499e0
void FUN_004499e0(void* pThis)
{
    *(int**)pThis = &DAT_010172c4;
}

extern int DAT_010172d0;

// @fnv 0x00449a00
void FUN_00449a00(int** appTarget)
{
    *appTarget = &DAT_010172d0;
}

namespace fnv_00449f50 {
extern int DAT_0101732c;

struct FUN_00449f50_shell
{
    int vtbl;
    void FUN_0044c270(int a, int b, int c);
    FUN_00449f50_shell* FUN_00449f50(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x00449f50
FUN_00449f50_shell* FUN_00449f50_shell::FUN_00449f50(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_00449f50

void FUN_0044d5c0(int pThis, int edx, void* pArg);

// @fnv 0x00449f80
void FUN_00449f80(int* pThis)
{
    reinterpret_cast<void(*)(int, void*)>(&FUN_0044d5c0)(pThis[5], pThis);
}

namespace fnv_00449fa0 {
extern int DAT_0101732c;

struct FUN_00449fa0_shell
{
    int vtbl;
    FUN_00449fa0_shell* ConstructWithVtbl(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x00449fa0
FUN_00449fa0_shell* FUN_00449fa0_shell::ConstructWithVtbl(int aiArg1, int aiArg2, int aiArg3)
{
    new ((void *)this) ::FUN_0044c270(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_00449fa0

namespace fnv_0044a100 {
extern int DAT_0101732c;

struct FUN_0044a100_shell
{
    int vtbl;
    FUN_0044a100_shell* FUN_0044a100(int a, int b, int c);
};

// Calls FUN_0044c270 with the three arguments, sets vtbl to &DAT_0101732c, and returns this.
// @fnv 0x0044a100
FUN_0044a100_shell* FUN_0044a100_shell::FUN_0044a100(int aiArg1, int aiArg2, int aiArg3)
{
    new ((void *)this) ::FUN_0044c920(aiArg1, aiArg2, aiArg3);
    vtbl = (int)&DAT_0101732c;
    return this;
}
}  // namespace fnv_0044a100

struct V130
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
    virtual int v9(int, int, int, unsigned char);
};
struct S130
{
    V130* p;
    void FUN_0044a130(int a, int b, unsigned char c);
};
// Calls the virtual method v9 on p with a, a, b and c, then passes the result to InsertOrReplaceNode.
// @fnv 0x0044a130
void S130::FUN_0044a130(int a, int aiArg, unsigned char c)
{
    reinterpret_cast<::Object *>(this)->InsertOrReplaceNode(p->v9(a, a, aiArg, c), {}, {}, {});
}

struct _Out_0044a170
{
};

struct _Dummy_0044a170
{
    int a, b, c, d;
    _Out_0044a170* FUN_0044a170(_Out_0044a170* out);
};

// @fnv 0x0044a170
_Out_0044a170* _Dummy_0044a170::FUN_0044a170(_Out_0044a170* out)
{
    reinterpret_cast<::FUN_0065e000_class *>((out))->FUN_0065e000(this->d, (int)(this));
    return out;
}

class MiddleHighProcess
{
  public:
    NiAVObject* GetAnimationObject();
};


// @fnv 0x0044adf0
void __cdecl FUN_0044adf0(MiddleHighProcess* pProcess, intptr_t a2)
{
    ::CallWithScaledArg((::FUN_0044e120_Cls *)(::NiAVObject *)(pProcess->GetAnimationObject()), a2, 1);
}

struct WaitableObject
{
    void FUN_0040c130();
public:
    void FUN_00401970();
};
struct NP_0044aed0
{
    WaitableObject* m_pObject;
    NP_0044aed0& FUN_0044aed0(WaitableObject* pObject);
};
// Clears output, asks the loader for the model named by filename, and stores it in output if found; returns whether it succeeded.
// @fnv 0x004472a0
bool FUN_004472a0_shell::FUN_004472a0(char* filename, void* output)
{
    reinterpret_cast<::NP_0044aed0 *>((((SetterHelper*)output)))->FUN_0044aed0((::WaitableObject *)(void *)(0));
    void* pmodel = 0;
    if (((ModelLoaderAccess*)this)->m_pLoadedModelMap->Get(filename, &pmodel))
    {
        reinterpret_cast<::NP_0044aed0 *>((((SetterHelper*)output)))->FUN_0044aed0((::WaitableObject *)(pmodel));
        return true;
    }
    return false;
}
// @fnv 0x0044aed0
NP_0044aed0& NP_0044aed0::FUN_0044aed0(WaitableObject* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            reinterpret_cast<::FUN_0040c130_Class *>((m_pObject))->FUN_0040c130();
        m_pObject = pObject;
        if (m_pObject)
            reinterpret_cast<::FUN_0040f6e0_class *>((m_pObject))->FUN_0040f6e0();
    }
    return *this;
}

namespace fnv_0044b010 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
struct FUN_0044b010_shell : public KFModel
{
    void FUN_0044b010();
};


// @fnv 0x0044b010
void FUN_0044b010_shell::FUN_0044b010()
{
    ::FUN_0040b460((unsigned int *)(void *)(&pListSequence));
}
}  // namespace fnv_0044b010

namespace fnv_0044b050 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
struct FUN_0044b050_shell : public KFModel
{
    void FUN_0044b050();
};

void __cdecl FinishScriptRunLock(void*);

// @fnv 0x0044b050
void FUN_0044b050_shell::FUN_0044b050()
{
    ::WaitForSingleObjectEx((long *)(void *)(&this->pListSequence));
}
}  // namespace fnv_0044b050

struct FUN_0044b0c0_holder
{
    LoadedFile* m_pObject;
    FUN_0044b0c0_holder* SetObject(LoadedFile* pObject);
};

// Stores pObject in m_pObject and increments its reference count when non-null, then returns this.
// @fnv 0x0044b0c0
FUN_0044b0c0_holder* FUN_0044b0c0_holder::SetObject(LoadedFile* pObject)
{
    m_pObject = pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
    return this;
}

namespace fnv_0044b0f0 {
struct BSFile;
struct NiMemObject
{
    char _pad_0[1];
};
struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
struct FUN_0044b0f0_shell : public LoadedFile
{
    void FUN_0044b0f0();
};

struct RecursiveLock
{
    void Leave();
};

// @fnv 0x0044b0f0
void FUN_0044b0f0_shell::FUN_0044b0f0()
{
    while (!reinterpret_cast<::s44b130::Lock *>((&(*reinterpret_cast<::fnv_0044b0f0::RecursiveLock *>(&::g_011c3b6c))))->FUN_0044b130())
    {
    }
    ::FUN_0040b460((unsigned int *)(void *)(this));
    reinterpret_cast<::S_0082f1f0_Lock *>(&((*reinterpret_cast<::fnv_0044b0f0::RecursiveLock *>(&::g_011c3b6c))))->FUN_0082f1f0();
}
}  // namespace fnv_0044b0f0

struct FUN_0044b160_obj
{
    void FUN_0040c130();
};
void FUN_0040c130(void*);

struct FUN_0044b160_ptr
{
    struct Target
    {
        void Release();
    }* m_pObject;
};

void FUN_0040c130(FUN_0044b160_ptr::Target*);

// @fnv 0x0044b160
void FUN_0044b160(FUN_0044b160_ptr* _this)
{
    if (_this->m_pObject)
        FUN_0040c130(_this->m_pObject);
}

namespace fnv_0044b180 {
struct BSFile;
struct NiMemObject
{
    char _pad_0[1];
};
struct LoadedFile : public NiMemObject
{
    void DecRefCount();
    void IncRefCount();
    BSFile* GetFile();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    char* pFileName;
    BSFile* pFile;
    bool m_bFirstFlag;
    bool m_bFileFlagAtOffsetD;
    char _pad_e[2];
};
struct FUN_0044b180_shell : public LoadedFile
{
    void FUN_0044b180();
};

struct GlobalObject_0044fae0
{
    void Leave();
};
void __cdecl FinishScriptRunLock(void*);
struct Del44b
{
};
// @fnv 0x0044b180
void FUN_0044b180_shell::FUN_0044b180()
{
    while (!reinterpret_cast<::s44b130::Lock *>(&((*reinterpret_cast<::fnv_0044b180::GlobalObject_0044fae0 *>(&::g_011c3b6c))))->FUN_0044b130())
    {
    }
    ::WaitForSingleObjectEx((long *)(void *)(this));
    reinterpret_cast<::S_0082f1f0_Lock *>(&((*reinterpret_cast<::fnv_0044b180::GlobalObject_0044fae0 *>(&::g_011c3b6c))))->FUN_0082f1f0();
    if (*(int*)this == 0)
    {
        struct D
        {
            Del44b* doomed;
            Del44b* object;
        } d;
        d.doomed = (Del44b*)this;
        d.object = d.doomed;
        d.object ? ((int)(reinterpret_cast<::FUN_0044b1f0_class *>((d.object))->FUN_0044b1f0(1))) : 0;
    }
}
}  // namespace fnv_0044b180

void FUN_0044b2e0(void* pThis);

// @fnv 0x0044b2c0
void FUN_0044b2c0(void** pThis)
{
    if (*pThis)
    {
        FUN_0044b2e0(*pThis);
    }
}

void FUN_0044dd60(void* pThis);

// @fnv 0x0044cbf0
void FUN_0044cbf0(void** apObject)
{
    if (*apObject)
    {
        FUN_0044dd60(*apObject);
    }
}

namespace fnv_0044dd60 {
int __cdecl FinishScriptRunLock(void*);

struct VirtualDeletable
{
    virtual ~VirtualDeletable();
};

// Calls FinishScriptRunLock on the object at offset 8 and deletes the object if the returned count is zero.
// @fnv 0x0044dd60
void FUN_0044dd60(VirtualDeletable* apObject)
{
    int count = ((int)(::WaitForSingleObjectEx((long *)(void *)((char*)apObject + 8))));
    if (count == 0)
    {
        delete apObject;
    }
}
}  // namespace fnv_0044dd60

// @fnv 0x0044faa0
void* FUN_0044faa0(char* this_ptr)
{
    return this_ptr + 0x10C;
}

struct RefT
{
};
struct FUN_0044fac0_S
{
    void FUN_0044fac0(RefT* p);
};
// @fnv 0x0044fac0
void FUN_0044fac0_S::FUN_0044fac0(RefT* apRef)
{
    reinterpret_cast<::Callees *>((apRef))->FUN_00726070();
}


// @fnv 0x0044fae0
void* FUN_0044fae0(void* apCriticalSection)
{
    InitializeCriticalSection(apCriticalSection);
    return apCriticalSection;
}

namespace fnv_0045bad0 {
struct NiMemObject
{
    char _pad_0[1];
};
struct NiRTTI
{
    char* GetName();
    void* GetBaseRTTI();
    char* m_pcName;
    void* m_pBaseRTTI;
};

class NiObject;
struct FUN_0045baf0_helper
{
};

// @fnv 0x0045bad0
bool __cdecl FUN_0045bad0(const NiRTTI* pkRTTI, const NiObject* pkObject)
{
    if (!pkObject)
        return false;
    return reinterpret_cast<::FUN_0045baf0_This *>((void *)(((const FUN_0045baf0_helper*)pkObject)))->IsEqual((int)(pkRTTI));
}
}  // namespace fnv_0045bad0

struct Item
{
};
struct LNode
{
    Item** _ref_006815c0();
};
class BGSAddonNode;
struct TESDataHandler
{
    Item* FindNthMatchingItem(void* a, int n);
public:
    ::BGSAddonNode *GetAddonNodeByIndex(unsigned int);
};
// Walks the TESObjectANIO list and returns the item matching a, skipping the first n matches; returns 0 if none found.
// @fnv 0x0046fd50
Item* TESDataHandler::FindNthMatchingItem(void* a, int aiSkipCount)
{
    Item* item = 0;
    LNode* node = ((::LNode *)(reinterpret_cast<::FUN_00461090_shell *>(this)->FUN_00461090()));
    while (node && (item = *((::Item **)(new ((void *)(node)) ::Vec3()))))
    {
        if (((bool)(reinterpret_cast<::FUN_0046fdd0_Class *>((item))->IsFieldEqual((int)(a)))))
        {
            if (aiSkipCount == 0)
                return item;
            else
                aiSkipCount = aiSkipCount - 1;
        }
        node = ((::LNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return 0;
}

struct S_004a0e10
{
    char pad[0x208];
    unsigned char f208;
    bool FUN_004a0e10(int a, unsigned char b);
};
// Returns false if FUN_004a0e50 fails; otherwise returns whether f208 equals b.
// @fnv 0x004a0e10
bool S_004a0e10::FUN_004a0e10(int aiUnused, unsigned char b)
{
    if (!reinterpret_cast<::FUN_004a0e50_Class *>(this)->FUN_004a0e50())
        return false;
    if (f208 == b)
        return true;
    return false;
}

namespace fnv_004a8a90 {
template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x004a8a90
const char* FUN_004a8a90(char* apObject)
{
    return *(const BSStringT<char>*)(apObject + 0x30);
}
}  // namespace fnv_004a8a90

struct AC_0042f730
{
};
struct S_0042f730
{
    AC_0042f730* m_pObject;
    S_0042f730* FUN_00528cb0(AC_0042f730* pObject);
};
namespace fnv_00537bd0 {
template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x00537bd0
const char* GetStringAtOffset(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x78);
}
}  // namespace fnv_00537bd0

namespace fnv_005495f0 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x005495f0
const char* FUN_005495f0(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0xb8);
}
}  // namespace fnv_005495f0

// @fnv 0x00559450
int FUN_00559450(int* pThis)
{
    return *pThis;
}

struct FUN_005d8710_shell : public QueuedReference
{
    NiAVObject* FUN_005d8710();
};

// @fnv 0x005d8710
NiAVObject* FUN_005d8710_shell::FUN_005d8710()
{
    return *(NiPointer<NiAVObject>*)((char*)this + 0x34);
}

namespace fnv_0062a100 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
struct FUN_0062a100_shell : public BSFileEntry
{
    unsigned int GetSizeMasked();
};

// @fnv 0x0062a100
unsigned int FUN_0062a100_shell::GetSizeMasked()
{
    return iSize & 0x3fffffff;
}
}  // namespace fnv_0062a100

struct NiRTTI_b;
struct NiObject_b
{
    virtual void v0();
    virtual void v1();
    virtual NiRTTI_b* GetRTTI();
    bool FUN_006532c0(const NiRTTI_b* pkRTTI);
};
// Walks the RTTI chain from GetRTTI() and returns true if pkRTTI is found, otherwise false.
// @fnv 0x006532c0
bool NiObject_b::FUN_006532c0(const NiRTTI_b* pkRTTI)
{
    const NiRTTI_b* pkThis = GetRTTI();
    while (pkThis)
    {
        if (pkThis == pkRTTI)
            return true;
        pkThis = ((::NiRTTI_b *)(reinterpret_cast<::Callees *>((const_cast<NiRTTI_b*>(pkThis)))->FUN_00726070()));
    }
    return false;
}

namespace fnv_006838b0 {
struct NiCollisionObject;
struct NiMemObject
{
    char _pad_0[1];
};
struct FUN_006838b0_shell : public NiAVObject
{
    NiCollisionObject* FUN_006838b0();
};

template <typename T> struct BSStringT
{
    operator const T*() const;
};

// @fnv 0x006838b0
NiCollisionObject* FUN_006838b0_shell::FUN_006838b0()
{
    return (NiCollisionObject*)((const BSStringT<char>*)((const char*)this + 0x1c))->operator const char*();
}
}  // namespace fnv_006838b0

struct Dummy_0069b080
{
    int pad0;
    int pad1;
    int pad2;
    int field_c;
    bool IsFieldCZero();
};

// @fnv 0x0069b080
bool IsFieldCZero(Dummy_0069b080* pThis)
{
    return pThis->field_c == 0;
}

namespace fnv_006fa820 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x006fa820
const char* FUN_006fa820(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x10);
}
}  // namespace fnv_006fa820

struct QH_0092c820
{
    void FUN_0044dd60();
    void FUN_0092c870();
};
struct NP_0092c820
{
    QH_0092c820* m_pObject;
    NP_0092c820& FUN_0092c820(const NP_0092c820& ptr);
};
struct FUN_0092c870_shell : public Model
{
    void FUN_0092c870();
};
// Stores pObject in m_pObject and, if it is non-null, calls FUN_0044bbc0 on it; returns this.
// @fnv 0x00528cb0
S_0042f730* S_0042f730::FUN_00528cb0(AC_0042f730* pObject)
{
    m_pObject = pObject;
    if (m_pObject)
        reinterpret_cast<::FUN_0092c870_shell *>((m_pObject))->FUN_0092c870();
    return this;
}
// @fnv 0x0092c820
NP_0092c820& NP_0092c820::FUN_0092c820(const NP_0092c820& aOther)
{
    if (m_pObject != aOther.m_pObject)
    {
        if (m_pObject)
            m_pObject->FUN_0044dd60();
        m_pObject = aOther.m_pObject;
        if (m_pObject)
            reinterpret_cast<::FUN_0092c870_shell *>((m_pObject))->FUN_0092c870();
    }
    return *this;
}

int __cdecl InitScriptRunLock(void*);

// @fnv 0x0092c870
void FUN_0092c870_shell::FUN_0092c870()
{
    ::FUN_0040b460((unsigned int *)(void *)((char*)&this->prefix[4]));
}

struct BSAudioManager
{
};
struct FUN_00ad8570_S
{
    void FUN_00ad8570(int a, float b, int c);
};
// @fnv 0x00ad8570
void FUN_00ad8570_S::FUN_00ad8570(int a, float b, int c)
{
    reinterpret_cast<::fnv_00adb690::FUN_00adb690_cls *>((((::BSAudioManager *)(::FUN_00ad9060()))))->FUN_00adb690((::fnv_00adb690::NiRefObject_audio *)(a), b, c);
}


// @fnv 0x00af3bd0
int FUN_00af3bd0(int param1, int param2)
{
    char buf1[0x108];
    char buf2[0x108];
    ::FUN_00af4070((char *)(buf2), (const char *)(param1));
    ::FUN_00af4070((char *)(buf1), (const char *)(param2));
    return ::WildcardMatch((const char *)(buf2), (const char *)(buf1)) == 1;
}


// @fnv 0x00c3f8a0
long FUN_00c3f8a0(char* pObject)
{
    return InterlockedDecrement((volatile long*)(pObject + 0x18));
}

namespace fnv_0043c550 {
struct FUN_0043c550_shell : public QueuedTexture
{
    void ApplyQueuedTexture();
};

struct Tile
{
    Tile* GetParent() const;
};
struct BSStringT
{
    operator const char*() const;
};
struct TextureFileEntrySetter
{
};
struct H0 : public LocationDescriptor
{
    bool FUN_0043c630();
    void FUN_0043c100(int);
};
struct HM
{
};
// @fnv 0x0043c550
void FUN_0043c550_shell::ApplyQueuedTexture()
{
    if (!reinterpret_cast<::FUN_0043e530_shell *>((((H0*)this)))->FUN_0043e530() && (const char*)(*(BSStringT*)((char*)this + 0x30)))
    {
        if (((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>((((H0*)this)))->GetIconFormID())))
            ::TextureFileEntrySetter::SetTexture((::NiTexture *)((const char*)(*(BSStringT*)((char*)this + 0x30))),
                                               ((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>((((H0*)this)))->GetIconFormID())));
        else if (((::fnv_0043c550::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((void *)(((Tile*)this)))->FUN_0045cd60())))
            ::TextureFileEntrySetter::SetTexture((::NiTexture *)((const char*)(*(BSStringT*)((char*)this + 0x30))), 0);
    }
    if (((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>((((H0*)this)))->GetIconFormID())) && reinterpret_cast<::FUN_0043c630_shell *>((((H0*)this)))->FUN_0043c630())
    {
        reinterpret_cast<::FUN_0043c100_shell *>((((H0*)this)))->FUN_0043c100(0);
        reinterpret_cast<::fnv_00448f50::FUN_00448f50_shell *>((((HM*)g_modelLoader)))->ForwardToVTableSlot((::fnv_00448f50::BSFileEntry *)(::BSFileEntry *)(((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>((((H0*)this)))->GetIconFormID()))));
    }
    reinterpret_cast<::FUN_0043c610_shell *>((((H0*)this)))->RunVirtualMethod28();
}
}  // namespace fnv_0043c550

struct UW
{
    unsigned int v;
};
struct BW
{
    bool v;
};
// Sets or clears bit f.v in the bit array at self+0x20 and resets the value at self+0x38 when the bit changes.
// @fnv 0x00441130
void FUN_00441130(char* self, UW auiFlag, BW abSet)
{
    unsigned int uiindex = auiFlag.v >> 5;
    unsigned int uibit = auiFlag.v % 32;
    unsigned int uimask = 1 << uibit;
    if (abSet.v)
    {
        if (!(((unsigned int*)(self + 0x20))[uiindex] & uimask))
            *(unsigned int*)(self + 0x38) = 0;
        ((unsigned int*)(self + 0x20))[uiindex] |= uimask;
    }
    else
    {
        if (((unsigned int*)(self + 0x20))[uiindex] & uimask)
            *(unsigned int*)(self + 0x38) = 0;
        ((unsigned int*)(self + 0x20))[uiindex] &= ~uimask;
    }
}

struct Struct_008b7b70;
struct PC7d;
struct A9
{
};
struct Hx
{
    void FUN_0043fed0();
};
struct MLa
{
};
// @fnv 0x00441200
void FUN_00441200(char* self)
{
    void** a = *(void***)(self + 0x28);
    bool b;
    ((void(*)(void*))(*(void***)a)[0x260 / 4])(a);
    b = reinterpret_cast<::FUN_0043c130_shell *>((((MLa*)g_modelLoader)))->IsLoadTexturesDegraded();
    if ((void*)a != (*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)) && !reinterpret_cast<::FUN_00936ef0_Class *>((((A9*)a)))->FUN_00936ef0())
        reinterpret_cast<::_FUN_00441290_shell *>((((MLa*)g_modelLoader)))->SetTlsFlag(true);
    if (FUN_008b7b70((Struct_008b7b70*)a))
        reinterpret_cast<::fnv_008b7360::FUN_008b7360_Class *>((((A9*)a)))->FUN_008b7360(1, (int)(self));
    ((Hx*)self)->FUN_0043fed0();
    reinterpret_cast<::_FUN_00441290_shell *>((((MLa*)g_modelLoader)))->SetTlsFlag(b);
}

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043be30(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x0043be30
void* DelStandIn::FUN_0043be30(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct NP
{
    ~NP();
};
namespace p07 {
struct _Base_00441d20
{
    virtual ~_Base_00441d20();
    char pad[0x2c];
};
struct FUN_0043bf80 : _Base_00441d20
{
    NP np;
    virtual ~FUN_0043bf80();
};
// Destructor for the object; destroys the embedded NP member and the base subobject.
// @fnv 0x0043bf80
FUN_0043bf80::~FUN_0043bf80()
{}
}

namespace fnv_0043c800 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_0043c800(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0043c800
void* DelStandIn::FUN_0043c800(unsigned int flags)
{
    reinterpret_cast<::FUN_0043c830 *>((((DtorStandIn*)this)))->FUN_0043c830::~FUN_0043c830();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_0043c800

namespace fnv_0043d090 {
struct NP
{
    void* m_pObject;
    ~NP();
};
struct _NiStreamDtorAlias
{
    char pad[0x5c4];
    virtual ~_NiStreamDtorAlias();
};
namespace FUN_0043d090 {
struct BSStream : public _NiStreamDtorAlias
{
    NP pSceneObject;
    virtual ~BSStream();
    void DestroyObject();
};
}

// Destructor that calls DestroyObject before destroying the stream object.
// @fnv 0x0043d090
FUN_0043d090::BSStream::~BSStream()
{
    DestroyObject();
}
}  // namespace fnv_0043d090

namespace fnv_0043e180 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_0043e180(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0043e180
void* DelStandIn::FUN_0043e180(unsigned int flags)
{
    reinterpret_cast<::fnv_0043e1b0::FUN_0043e1b0 *>((((DtorStandIn*)this)))->fnv_0043e1b0::FUN_0043e1b0::~FUN_0043e1b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_0043e180

namespace fnv_0043e600 {
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0043e600(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0043e600
void* DelStandIn::FUN_0043e600(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_0043e600

namespace fnv_0043e630 {
struct NP
{
    ~NP();
};
namespace p07 {
struct FUN_0043e1b0
{
    char pad[0x3c];
    ~FUN_0043e1b0();
};
struct FUN_0043e630 : FUN_0043e1b0
{
    NP np;
    ~FUN_0043e630();
};
// @fnv 0x0043e630
FUN_0043e630::~FUN_0043e630()
{}
}
}  // namespace fnv_0043e630

namespace fnv_0043eb80 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_0043eb80(unsigned int flags);
};
// Calls the destructor on this, then frees this when bit 0 of flags is set, and returns this.
// @fnv 0x0043eb80
void* DelStandIn::FUN_0043eb80(unsigned int flags)
{
    reinterpret_cast<::FaceGenPaletteEntry *>((((DtorStandIn*)this)))->FaceGenPaletteEntry::~FaceGenPaletteEntry();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_0043eb80

namespace fnv_004414c0 {
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_004414c0(unsigned int flags);
};
// Calls the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x004414c0
void* DelStandIn::FUN_004414c0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_004414c0

namespace fnv_004414f0 {
struct GlobalObject_00528cb0
{
    ~GlobalObject_00528cb0();
    void* p;
};
struct FUN_00440eb0
{
    ~FUN_00440eb0();
    char pad[0x40];
};
struct FUN_004414f0 : public FUN_00440eb0
{
    GlobalObject_00528cb0 a;
    GlobalObject_00528cb0 b;
    ~FUN_004414f0();
};

// @fnv 0x004414f0
FUN_004414f0::~FUN_004414f0()
{}
}  // namespace fnv_004414f0

namespace fnv_00441b50 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_00441b50(unsigned int flags);
};
// Runs the destructor on this object, then frees it via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00441b50
void* DelStandIn::FUN_00441b50(unsigned int flags)
{
    reinterpret_cast<::QueuedReference *>((((DtorStandIn*)this)))->FUN_00441b80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_00441b50

namespace fnv_00442010 {
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00442010(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00442010
void* DelStandIn::FUN_00442010(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_00442010

namespace fnv_00442040 {
struct NiPtrNode_S
{
    ~NiPtrNode_S();
    void* m_pObject;
};
struct FUN_0044b2c0
{
    ~FUN_0044b2c0();
    void* p;
};
struct FUN_00441d20
{
    ~FUN_00441d20();
    char pad[0x38];
};
struct FUN_00442040 : public FUN_00441d20
{
    NiPtrNode_S a;
    FUN_0044b2c0 b;
    ~FUN_00442040();
};

// Destructor for the object; the compiler-generated member destructors run for the embedded NiPtrNode_S and FUN_0044b2c0 members.
// @fnv 0x00442040
FUN_00442040::~FUN_00442040()
{}
}  // namespace fnv_00442040

namespace fnv_004431f0 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_004431f0(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns the object pointer.
// @fnv 0x004431f0
void* DelStandIn::FUN_004431f0(unsigned int flags)
{
    reinterpret_cast<::Model *>((((DtorStandIn*)this)))->Model::~Model();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_004431f0

namespace fnv_00443240 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_00443240(unsigned int flags);
};
// Runs the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00443240
void* DelStandIn::FUN_00443240(unsigned int flags)
{
    reinterpret_cast<::FUN_0043b750 *>((((DtorStandIn*)this)))->FUN_0043b750::~FUN_0043b750();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_00443240

struct FUN_00449fd0
{
    FUN_00449fd0();
    ~FUN_00449fd0();
    char pad[0x18];
};
struct FUN_00449610 : public FUN_00449fd0
{
    void* p18;
    void* p1c;
    FUN_00449610();
};

namespace fnv_00449fd0 {
struct _ref_006815c0
{
    void* p;
    _ref_006815c0();
    _ref_006815c0(const _ref_006815c0&);
};
struct FUN_0065d3a0
{
    void* data[4];
    FUN_0065d3a0(_ref_006815c0 arg);
    ~FUN_0065d3a0();
};
struct FUN_00449fd0 : public FUN_0065d3a0
{
    FUN_00449fd0();
    void FUN_0044a240(int);
};

// Constructs the base with a default reference and initializes the object by calling FUN_0044a240 with 0.
// @fnv 0x00449fd0
FUN_00449fd0::FUN_00449fd0() : FUN_0065d3a0(_ref_006815c0())
{
    FUN_0044a240(0);
}
}  // namespace fnv_00449fd0

struct ConstIterStandIn
{
    int a;
    int b;
};
struct FaceGenImageView : ConstIterStandIn
{
};
struct FaceGenImage
{
};
struct VecStandIn
{
    void FUN_0044a0a0();
};
struct PairStandIn
{
    int first;
    int second;
};
int __cdecl FUN_0044d600(int, int, int);
struct ModelLoaderStandIn
{
    char pad[0x10];
    int field10;
    PairStandIn FUN_0044a1a0(int, int, int, int);
};
// Initializes p18 and p1c to null, then calls FUN_0044a0a0.
// @fnv 0x00449610
FUN_00449610::FUN_00449610()
{
    p18 = 0;
    p1c = 0;
    reinterpret_cast<::VecStandIn *>(this)->FUN_0044a0a0();
}
// Calls FUN_0044a1a0 with the results of _Doraise and CallWithSelf, discarding the returned iterator.
// @fnv 0x0044a0a0
void VecStandIn::FUN_0044a0a0()
{
    reinterpret_cast<::ModelLoaderStandIn *>(this)->FUN_0044a1a0((*(int *)&(const ::ConstIterStandIn &)((*(::FaceGenImageView *)(reinterpret_cast<::_Dummy_0044a170 *>((((FaceGenImage*)this)))->FUN_0044a170({}))))), (*(int *)&(const ::ConstIterStandIn &)((*(::FaceGenImageView *)(reinterpret_cast<::fnv_0065f550::FUN_0065f550_Class *>(this)->CallWithSelf({}))))), {}, {});
}
// @fnv 0x0044a1a0
PairStandIn ModelLoaderStandIn::FUN_0044a1a0(int aiFirstA, int aiFirstB, int aiSecondA, int aiSecondB)
{
    PairStandIn r1 = (*(::PairStandIn *)(reinterpret_cast<::FUN_0065ded0_Class *>(this)->FUN_0065ded0((::_Out_0044a170 *)(aiFirstA), aiFirstB, {})));
    PairStandIn r2 = (*(::PairStandIn *)(reinterpret_cast<::FUN_0065ded0_Class *>(this)->FUN_0065ded0((::_Out_0044a170 *)(aiSecondA), aiSecondB, {})));
    if (reinterpret_cast<::FUN_0065dfd0_class *>(&(r1))->FUN_0065dfd0((int)&(r2)))
    {
        int tmp = FUN_0044d600(r2.second, field10, r1.second);
        reinterpret_cast<::FUN_0065f2b0_class *>(this)->FUN_0065f2b0(tmp, field10);
        field10 = tmp;
    }
    return r1;
}

namespace fnv_0043abf0 {
void* __cdecl operator new(unsigned int);

struct GO
{
    GO(int);
    ~GO();
};

struct NP_0081c630 : GO
{
    NP_0081c630(int x) : GO(x)
    {}
    NP_0081c630& operator=(void*);
};

struct FUN_0043abf0
{
    char* m_str;
    int m_iWordAt04;
    int m_8;
    NP_0081c630 m_ptr;

    FUN_0043abf0(const char* apStr, void* apPtr);
};

// @fnv 0x0043abf0
FUN_0043abf0::FUN_0043abf0(const char* apStr, void* apPtr) : m_ptr(0)
{
    unsigned int len = ::FUN_0044a670(apStr) + 1;
    m_str = new char[len];
    TaskQueueInterface::CopyStringToBuffer(m_str, len, apStr);
    m_ptr = apPtr;
    m_iWordAt04 = 0;
    m_8 = 0;
}
}  // namespace fnv_0043abf0

namespace fnv_0043baf0 {
void* __cdecl operator new(unsigned int);
struct FUN_0043baf0;
struct ModelLoaderStandIn
{
    bool DispatchVirtualCall(char*, FUN_0043baf0*);
};
struct FUN_0043baf0
{
    int field0;
    char* pName;
    int arg;
    char flag;
    char flag2;
    FUN_0043baf0(const char*, int);
};
// @fnv 0x0043baf0
FUN_0043baf0::FUN_0043baf0(const char* name, int aiArg)
{
    unsigned int len;
    char* buf;
    arg = aiArg;
    len = ::FUN_0044a670(name) + 1;
    buf = (char*)operator new(len);
    pName = buf;
    TaskQueueInterface::CopyStringToBuffer(pName, len, name);
    flag = ((ModelLoaderStandIn*)g_modelLoader)->DispatchVirtualCall(pName, this);
    flag2 = 0;
    field0 = 0;
}
}  // namespace fnv_0043baf0

namespace fnv_0043bd10 {
struct FUN_0063fa10
{
};
struct QBase
{
    QBase(int);
    virtual ~QBase();
    char pad[0x2c];
};
struct GO
{
    GO(int);
    ~GO();
    char pad[4];
};
struct FUN_0043bd10 : public QBase
{
    GO go;
    bool flag;
    FUN_0043bd10(const char* apFileName, int aePriority);
    virtual ~FUN_0043bd10();
};
// @fnv 0x0043bd10
FUN_0043bd10::FUN_0043bd10(const char* apFileName, int aePriority) : QBase(aePriority), go(0)
{
    char szStandardPath[260];
    flag = false;
    ::CleanPath(apFileName, szStandardPath, 260);
    reinterpret_cast<::FUN_00c3cee0_shell *>((((FUN_0063fa10*)this)))->FUN_00c3cee0((char *)(szStandardPath));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>((((FUN_0063fa10*)this)))->LookupFileEntryByArchive(1);
}
}  // namespace fnv_0043bd10

namespace fnv_0043be60 {
struct GeometryRelatedType;
struct Twin_00c3cf40
{
};
struct QBase
{
    char pad[0x2c];
    QBase(int);
    ~QBase();
    virtual void vf();
};
struct GO
{
    int p;
    GO(int);
    ~GO();
};
struct FUN_0043be60 : public QBase
{
    GO go;
    char flag;
    FUN_0043be60(GeometryRelatedType*, int);
};
// @fnv 0x0043be60
FUN_0043be60::FUN_0043be60(GeometryRelatedType* shader, int arg) : QBase(arg), go(0)
{
    flag = 0;
    reinterpret_cast<::Twin_00c3cf40 *>((((Twin_00c3cf40*)this)))->SetD3DPixelShader((*(::GeometryRelatedType *const *)&(shader)));
}
}  // namespace fnv_0043be60

namespace fnv_0043c6e0 {
extern int DAT_01016890;

struct QBase
{
    QBase(int);
    virtual ~QBase();
};

struct GO
{
    GO(int);
    ~GO();
};

struct FUN_0063fa10
{
};

struct FUN_0043c7d0_shell
{
};

struct FUN_0043c7a0_arg
{
    unsigned char b;
};


struct FUN_0043c6e0 : QBase
{
    char pad[0x30 - sizeof(QBase)];
    GO m_go;
    int m_34;
    int m_38;
    char m_3c;
    float m_40;

    FUN_0043c6e0(const char* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5);
    virtual ~FUN_0043c6e0();
};

// @fnv 0x0043c6e0
FUN_0043c6e0::FUN_0043c6e0(const char* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5) : QBase(a2), m_go(0)
{
    m_34 = 0;
    m_38 = a3;
    m_3c = 0;
    reinterpret_cast<::FUN_00c3cee0_shell *>((((FUN_0063fa10*)this)))->FUN_00c3cee0((char *)(a1));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>((((FUN_0063fa10*)this)))->LookupFileEntryByArchive(0);
    ::FUN_0043c7a0((char*)this, (*(::FUN_0043c7a0_arg *)&(const ::fnv_0043c6e0::FUN_0043c7a0_arg &)(a4)));
    reinterpret_cast<::FUN_0043c7d0_shell *>((((FUN_0043c7d0_shell*)this)))->FUN_0043c7d0(a5);
    m_40 = 0.0f;
}
}  // namespace fnv_0043c6e0

namespace fnv_0043c890 {
extern int DAT_01016890;

struct QBase
{
    QBase(int);
    virtual ~QBase();
};

struct GO
{
    GO(int);
    ~GO();
};

struct FUN_0063fa10
{
};

struct FUN_0043c7d0_shell
{
};

struct FUN_0043c7a0_arg
{
    unsigned char b;
};


struct QueuedModelParam
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual const char* vfn5();
};

struct FUN_0043c890 : QBase
{
    char pad[0x30 - sizeof(QBase)];
    GO m_go;
    QueuedModelParam* m_34;
    int m_38;
    char m_3c;
    float m_40;

    FUN_0043c890(QueuedModelParam* a1, int a2, int a3, FUN_0043c7a0_arg a4, unsigned char a5);
    virtual ~FUN_0043c890();
};

// @fnv 0x0043c890
FUN_0043c890::FUN_0043c890(QueuedModelParam* apModelParam, int aiBaseArg, int a3, FUN_0043c7a0_arg aByteArg,
                           unsigned char a5)
    : QBase(aiBaseArg), m_go(0)
{
    m_34 = apModelParam;
    m_38 = a3;
    m_3c = 0;
    reinterpret_cast<::FUN_00c3cee0_shell *>((((FUN_0063fa10*)this)))->FUN_00c3cee0((char *)(apModelParam->vfn5()));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>((((FUN_0063fa10*)this)))->LookupFileEntryByArchive(0);
    ::FUN_0043c7a0((char*)this, (*(::FUN_0043c7a0_arg *)&(const ::fnv_0043c890::FUN_0043c7a0_arg &)(aByteArg)));
    reinterpret_cast<::FUN_0043c7d0_shell *>((((FUN_0043c7d0_shell*)this)))->FUN_0043c7d0(a5);
    m_40 = 0.0f;
}
}  // namespace fnv_0043c890

namespace fnv_0043e0f0 {
extern int _data_011c16bc;
struct QBase
{
    virtual void vf();
    ~QBase();
    int base[11];
    QBase(int);
};
struct FUN_0044afe0
{
    int v;
    FUN_0044afe0(int);
    ~FUN_0044afe0();
};
struct FUN_0063fa10
{
};

struct FUN_0043e0f0 : public QBase
{
    FUN_0044afe0 m;
    bool flag;
    FUN_0043e0f0(const char* apFileName, int aePriority);
};

// @fnv 0x0043e0f0
FUN_0043e0f0::FUN_0043e0f0(const char* apFileName, int aePriority) : QBase(aePriority), m(0)
{
    flag = false;
    reinterpret_cast<::FUN_00c3cee0_shell *>((((FUN_0063fa10*)this)))->FUN_00c3cee0((char *)(apFileName));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>((((FUN_0063fa10*)this)))->LookupFileEntryByArchive(0);
}
}  // namespace fnv_0043e0f0

namespace fnv_0043e210 {
extern int _data_011c16bc;
struct QBase
{
    virtual void vf();
    ~QBase();
    int base[11];
    QBase(int);
};
struct FUN_0044afe0
{
    int v;
    FUN_0044afe0(int);
    ~FUN_0044afe0();
};

struct FUN_0043e210 : public QBase
{
    FUN_0044afe0 m;
    bool flag;
    FUN_0043e210(KFModel* apKF, int aePriority);
};

// Initializes the base with aePriority, clears m and flag, stores apKF into m, then calls SetFieldCToFive on this.
// @fnv 0x0043e210
FUN_0043e210::FUN_0043e210(KFModel* apKF, int aePriority) : QBase(aePriority), m(0)
{
    flag = false;
    reinterpret_cast<::NiPointer_KFModel *>((((NiPointer<KFModel>*)&m)))->FUN_0044b070=(apKF);
    ::SetFieldCToFive((char*)this);
}
}  // namespace fnv_0043e210

namespace fnv_0043eaf0 {
struct QueuedFileBase
{
    char pad[0x24];
    QueuedFileBase(int);
    ~QueuedFileBase();
    virtual void vf();
};
struct GO
{
    int p;
    GO(int);
    ~GO();
};
struct FUN_0043eaf0 : public QueuedFileBase
{
    int owner;
    GO spA;
    GO spB;
    FUN_0043eaf0(int, int);
};
// Constructs a QueuedFileBase from b, stores a in owner, and default-constructs spA and spB with 0.
// @fnv 0x0043eaf0
FUN_0043eaf0::FUN_0043eaf0(int aiOwner, int aiBaseArg) : QueuedFileBase(aiBaseArg), owner(aiOwner), spA(0), spB(0)
{}
}  // namespace fnv_0043eaf0

namespace fnv_0043ecb0 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct IncompleteStruct;
struct ReactionInfo;
struct CloningProcess;
struct NiCullingProcess;
struct NiObject;
struct NiUpdateData;
struct TESDescription;
struct TESFile;
struct blob48
{
    char b[48];
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct FUN_0043ecb0_shell : public QueuedHead
{
    void FUN_0043ecb0();
};

struct MemCtx
{
    MemCtx(int, bool, const char*, int);
    ~MemCtx();
    int pad[1];
};
struct TESNPC
{
};
struct TESRace
{
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
    int p;
};
struct HeadLayout
{
    char pad[0x28];
    TESNPC* npc;
    NP_0081c630 skinned;
    NP_0081c630 biped;
};
// @fnv 0x0043ecb0
void FUN_0043ecb0_shell::FUN_0043ecb0()
{
    ::FUN_00652140();
    MemCtx tempMemContext(0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x5f9);
    unsigned int pbipedNode3;
    unsigned int pskinnedNode;
    pskinnedNode = 0;
    pbipedNode3 = 0;
    reinterpret_cast<::TESNPC *>((((HeadLayout*)this)->npc))->GetFaceGenNodes((*(::BSFaceGenNiNode * *)(&pskinnedNode)), (*(::BSFaceGenNiNode * *)(&pbipedNode3)));
    ((HeadLayout*)this)->skinned = (void*)pskinnedNode;
    ((HeadLayout*)this)->biped = (void*)pbipedNode3;
    if (reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(((HeadLayout*)this)->npc))->FUN_0084e3a0() == 7)
    {
        TESRace* prace = (TESRace*)reinterpret_cast<::Callees *>(((char*)((HeadLayout*)this)->npc + 0x10c))->FUN_00726070();
        reinterpret_cast<::TESRace *>((prace))->ClearFaceGenUndo();
    }
    ::fnv_00652190::FUN_00652190();
}
}  // namespace fnv_0043ecb0

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct FUN_00441ba0_shell : public QueuedPlayer
{
    void FUN_00441ba0();
};

struct PC7d
{
    void LoadIdleAnimations(IO_TASK_PRIORITY, FUN_00441ba0_shell*);
};
extern int _data_011c16bc;
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct Q441560
{
    void LoadBipedModel();
};

// @fnv 0x00441ba0
void FUN_00441ba0_shell::FUN_00441ba0()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x94e);
    (*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))->LoadIdleAnimations(((IOTask*)this)->FUN_0043cc60(), this);
    ((Q441560*)this)->LoadBipedModel();
}

namespace fnv_00441d80 {
extern int _data_011c16bc;
struct QBase
{
    virtual void vf();
    ~QBase();
    int base[11];
    QBase(int);
};

struct FUN_00441d80 : public QBase
{
    NiPointer<LoadedFile> m_pLoadedFile;
    int m_iLoadPriority;
    FUN_00441d80(LoadedFile* apFile, int aePriority);
};

// @fnv 0x00441d80
FUN_00441d80::FUN_00441d80(LoadedFile* apFile, int aePriority) : QBase(aePriority), m_pLoadedFile(0)
{
    m_iLoadPriority = 3;
    reinterpret_cast<::NiPointer_LoadedFile *>((void *)&(const ::NiPointer< ::LoadedFile> &)(m_pLoadedFile))->FUN_0044b220(apFile);
    ::SetFieldCToFive((char*)this);
}
}  // namespace fnv_00441d80

namespace fnv_00441f80 {
struct QueuedFileLoadBase
{
    char pad[0x34];
    QueuedFileLoadBase(int, int, int);
    ~QueuedFileLoadBase();
    virtual void vf();
};
struct GO
{
    int p;
    GO(int);
    ~GO();
};
struct MeshPtr
{
    int p;
    MeshPtr(int);
};
struct FUN_00441f80 : public QueuedFileLoadBase
{
    GO m_kObject;
    MeshPtr m_pMesh;
    FUN_00441f80(int, int, int);
};
// Constructs a QueuedFileLoadBase with the given arguments and initialises its two member objects to zero.
// @fnv 0x00441f80
FUN_00441f80::FUN_00441f80(int a, int b, int c) : QueuedFileLoadBase(a, b, c), m_kObject(0), m_pMesh(0)
{}
}  // namespace fnv_00441f80

extern int DAT_01016e50;

void* __cdecl operator new(unsigned int);

template <typename T> struct LockFreeQueue
{
    char pad[0x40];
    LockFreeQueue(unsigned int, unsigned int);
};

struct BSTaskManagerThread
{
    BSTaskManagerThread(unsigned int, const char*);
    virtual ~BSTaskManagerThread();
};

struct FUN_004421d0 : BSTaskManagerThread
{
    char pad[0x30 - sizeof(BSTaskManagerThread)];
    char m_30;
    int m_34;
    LockFreeQueue<NiPointer<QueuedReference> >* m_pQueue;

    FUN_004421d0(unsigned int aiMaxThreads);
    virtual ~FUN_004421d0();
};

// Constructs a BackgroundCloneThread task manager thread, initializing its state and allocating a lock-free queue sized by aiMaxThreads.
// @fnv 0x004421d0
FUN_004421d0::FUN_004421d0(unsigned int aiMaxThreads) : BSTaskManagerThread(3, "BackgroundCloneThread")
{
    m_34 = 0;
    m_30 = 0;
    m_pQueue = new LockFreeQueue<NiPointer<QueuedReference> >(aiMaxThreads, 8);
}

extern int _data_011c16bc;
struct QueueObj
{
    int state;
    QueueObj(int);
    ~QueueObj();
};
struct QueueModelHolder
{
    void FUN_00443dc0(int, QueueObj*, int, int, int, bool, bool, bool, float);
    void FUN_00443d30(int apModel, int a, int b, int c, bool d, bool e, bool f);
};

// Constructs a QueueObj with state 0 and forwards it with the model and flags to FUN_00443dc0 using a zero float.
// @fnv 0x00443d30
void QueueModelHolder::FUN_00443d30(int apModel, int aiArg1, int aiArg2, int aiArg3, bool abFlag1, bool abFlag2,
                                    bool abFlag3)
{
    QueueObj spqueuedModel(0);
    FUN_00443dc0(apModel, &spqueuedModel, aiArg1, aiArg2, aiArg3, abFlag1, abFlag2, abFlag3, 0.0f);
}

namespace fnv_00444f10 {
struct MagicItem;
struct TESEffectShader;
struct TESFile;
struct TESObjectLIGH;
struct TESSound;
struct blob8
{
    char b[8];
};
struct TESDescription : public BaseFormComponent
{
    virtual char* GetDescription(TESForm*, int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    static void LoadDescriptionAtOffset(TESDescription*, int);
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetDescriptionLength(TESForm*);
    unsigned int GetDescriptionLength();
    static char* GetDescription(TESForm*);
    unsigned long GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned long);
    void LoadDescriptionForForm(TESForm*, int);
    void UnLoadDescription();
    void SetDescription(char*);
    unsigned long m_uiDescriptionFileOffset;
};
struct EffectSetting : public TESForm, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
    virtual void __vslot_10();
    virtual void Save();
    virtual bool Load(TESFile*);
    virtual void InitItem();
    virtual void Copy(TESForm*);
    virtual bool Compare(TESForm*);
    bool IsFlagSet(int);
    bool IsFlagSetAll(unsigned int);
    bool IsFlagSetAny(unsigned int);
    void SetFlag(int, bool);
    void Disable();
    void Enable();
    bool IsDisabled();
    int IsRangeAll();
    int GetRangeFlags();
    bool ShouldNegateMagnitude(int);
    bool IsAssociatedFormUsed();
    bool IsAssociatedActorValueUsed();
    bool IsAssociatedActorValueFixed();
    bool IsScriptEffect();
    int GetProjectileType();
    void SetProjectileType(int);
    struct blob8 GetEffectName();
    void UpdateEffectName(char*);
    float GetBaseCost();
    void SetBaseCost(float);
    TESForm* GetAssociatedForm();
    void SetAssociatedForm(TESForm*);
    int GetAssociatedActorValue();
    void SetAssociatedActorValue(int);
    int GetEffectID();
    void SetAssociatedSkill(int);
    void* GetCounterEffects();
    int GetNumCounterEffects();
    void SetCounterEffects(void*);
    int GetResistanceVariable();
    void SetResistanceVariable(int);
    static EffectSetting* CreateFilter();
    bool FilterCompare(EffectSetting*, bool, unsigned int);
    TESSound* GetCastSound();
    void SetCastSound(TESSound*);
    TESSound* GetBoltSound();
    void SetBoltSound(TESSound*);
    TESSound* GetHitSound();
    void SetHitSound(TESSound*);
    TESSound* GetAreaSound();
    void SetAreaSound(TESSound*);
    TESObjectLIGH* GetLight();
    void SetLight(TESObjectLIGH*);
    TESEffectShader* GetEffectShader();
    void SetEffectShader(TESEffectShader*);
    TESEffectShader* GetEnchantEffectShader();
    void SetEnchantEffectShader(TESEffectShader*);
    void SetProjectileSpeed(float);
    float GetProjectileSpeed();
    void SetConstantEffectEnchantmentFactor(float);
    float GetConstantEffectEnchantmentFactor();
    void SetConstantEffectBarterFactor(float);
    float GetConstantEffectBarterFactor();
    int GetEffectArchetype();
    void SetEffectArchetype(int);
    virtual char* GetObjectDisplayName();
    bool HasEffectID();
    bool UsesAssociatedActorValue();
    int IncAssociatedItemLoadedCount();
    int DecAssociatedItemLoadedCount();
    int QueueAssociatedItem();
    int QueueAssociatedItemFinished();
    bool IsModelLoaded();
    bool HasNoAssociatedActorValue();
    int IncEffectLoadedCount();
    int DecEffectLoadedCount();
    int QueueEffect();
    int QueueEffectFinished();
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    void SetNumCounterEffects(short);
    void __local_vftable_ctor_closure();
    int* m_pEffectSettingCallback;
    void* m_pPredicateData;
    char data[72];
    char counterEffects[8];
    int m_iActorValue;
    int m_iEffectID;
};
struct FUN_00444f10_shell : public ModelLoader
{
    void FUN_00444f10(MagicItem*, EffectSetting*, int);
};

class QueuedMagicItem
{
  public:
    QueuedMagicItem(MagicItem*, EffectSetting*, IO_TASK_PRIORITY);
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void DispatchToManager();
    char data[0x2c];
};
struct GlobalObject_00528cb0Ptr
{
    GlobalObject_00528cb0Ptr(QueuedMagicItem*);
    ~GlobalObject_00528cb0Ptr();
    operator QueuedMagicItem*() const;
    QueuedMagicItem* p;
};

// @fnv 0x00444f10
void FUN_00444f10_shell::FUN_00444f10(MagicItem* apMagicItem, EffectSetting* apAVEffectSetting, int aePriority)
{
    if (!apMagicItem || !apAVEffectSetting)
        return;
    GlobalObject_00528cb0Ptr spqueuedMagicItem(
        new QueuedMagicItem(apMagicItem, apAVEffectSetting, (IO_TASK_PRIORITY)aePriority));
    ((QueuedMagicItem*)spqueuedMagicItem)->DispatchToManager();
}
}  // namespace fnv_00444f10

struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct InventoryChanges;
struct MagicItemForm;
struct PackageList;
struct TESActorBase;
struct TESAmmo;
struct TESFaction;
struct TESFile;
struct TESLevItem;
struct TESNPC;
struct TESRace;
struct TESActorBaseData : public BaseFormComponent
{
    virtual void CopyFromTemplateForm(TESActorBase*);
    virtual bool GetVATSmeleeDisabled();
    virtual bool GetNoVATSranged();
    virtual bool GetCanBePickpocketed();
    virtual bool GetIsGhost();
    virtual bool GetIsInvulnerable();
    virtual bool GetNoKnockdowns();
    virtual bool GetCanBeAllRaces();
    virtual bool GetNoHeadTracking();
    virtual bool GetNoPersuasion();
    virtual bool GetNoLeftArm();
    virtual bool GetNoRightArm();
    virtual bool GetNoHead();
    virtual bool GetNoShadow();
    virtual bool GetNoBloodSpray();
    virtual void SetNoBloodSpray(bool);
    virtual bool GetNoBloodDecal();
    virtual void SetNoBloodDecal(bool);
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool);
    void SetTemplateUseFlag(int, bool);
    bool GetTemplateUseFlag(int);
    TESForm* QTemplateForm();
    void SetTemplateForm(TESForm*);
    unsigned short QTemplateUseFlags();
    void SetTemplateUseFlags(unsigned short);
    bool GetUsesLeveledTemplate();
    bool IsTemplateLeveled();
    void SetTemplateReference(TESObjectREFR*);
    static TESActorBase* GetTemplateForActorBase(TESActorBase*, TESActorBase*);
    static bool HasCircularTemplateHierarchy(TESActorBase*);
    static bool IsActorBaseInTemplateHierarchy(TESActorBase*, TESActorBase*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short*);
    int* GetFlags();
    void SetFlags(int);
    bool GetFlagBit(int);
    void UpdateFlagBit(int, bool, bool);
    bool IsEssentialActor();
    void SetEssential(bool);
    bool GetRespawn();
    void SetRespawn(bool);
    bool GetRunsInLow();
    void UpdateRunsInLow(bool, bool);
    bool GetKnockedDowns();
    void SetKnockedDowns(bool);
    bool GetNotPushable();
    void SetNotPushable(bool);
    bool GetNoRotatingToHeadtrack();
    void SetNoRotatingToHeadtrack(bool);
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool);
    bool GetSummonable();
    void SetSummonable(bool);
    bool GetNoRumors();
    void SetNoRumors(bool);
    void SetNoVATSMelee(bool);
    void SetAllowPCDialogue(bool);
    void SetAllowPickPocket(bool);
    void SetIsGhost(bool);
    void SetInvulnerable(bool);
    void SetCantOpenDoors(bool);
    void SetCanBeAllRaces(bool);
    void SetAutoCalcServiceFlags(bool);
    unsigned short GetLevelExact();
    unsigned short GetLevel();
    void SetLevel(unsigned short);
    unsigned short GetCalcLevelMin();
    void SetCalcLevelMin(unsigned short);
    unsigned short GetCalcLevelMax();
    void SetCalcLevelMax(unsigned short);
    unsigned short GetBaseDisposition();
    void SetBaseDisposition(unsigned short);
    TESLevItem* GetDeathItem();
    void SetDeathItem(TESLevItem*);
    void SetFatigue(unsigned short);
    static int ConvertToInteger(float);
    static char* GetActorDisplayName(Actor*);
    void SetKarmaValue(float);
    void ModKarma(float);
    unsigned short GetBarterGold();
    void SetBarterGold(unsigned short);
    int GetFactionReaction(TESActorBase*, int*);
    int GetFactionRank(TESFaction*, bool);
    void SetFactionRank(TESFaction*, char);
    void ModFactionRank(TESFaction*, char, bool);
    bool GetGhostFlag();
    bool CanBeDetected();
    void* GetFactionList();
    unsigned short GetSpeedMult();
    void SetSpeedMult(unsigned short);
    void SetVoiceType(BGSVoiceType*);
    void AddFormChange(int);
    void RemoveFormChange(int);
    void AddFormChangeFlags(int);
    void ClearChangeFlags(int);
    int GetChangeFlags();
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void SetPCFactionFlags(int);
    bool HasFaction(TESFaction*);
    void RemoveAllFactions();
    void CopyFactionList(TESActorBaseData*);
    void* __vecDelDtor(unsigned int);
    char actorData[24];
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    char m_pVoiceType[8];
};
struct TESContainer : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void ClearObjects();
    InventoryItemEntry* AddObject(ContainerChanges*);
    InventoryItemEntry* AddObject(TESObject*, int, ContainerItemExtra*);
    void AddDuplicateObject(InventoryItemEntry*);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry*);
    void ReplaceObject(TESObject*, TESObject*);
    bool HasObjectOfType(TESObject*);
    float GetContainerWeight(bool);
    int GetObjectCount(TESObject*);
    char Compare(InventoryItemEntry*, InventoryItemEntry*);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char);
    static bool IsValidContainerObject(TESObject*);
    void MergeContainer(TESContainer*);
    void MultiplyContainerCounts(int);
    void SetClothingModifier(float);
    void AddContentsFromReference(TESObjectREFR*, bool);
    void AddInventoryChangesToContainer(int, InventoryChanges*);
    TESAmmo* GetBestAmmoForActor(TESActorBase*);
    TESObjectWEAP* GetBestWeapon(TESActorBase*);
    TESObjectARMO* FindBestArmor(TESActorBase*, int);
    TESObjectCLOT* GetBestClothing(TESActorBase*, int);
    TESBoundObject* GetInventoryEntryData(int);
    void* GetObjectList();
    void* GetObjectListEnd();
    void* __vecDelDtor(unsigned int);
    char objectList[8];
};
struct BGSTouchSpellForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static MagicItemForm* GetFormTouchSpell(TESForm*);
    MagicItemForm* GetFormTouchSpell();
    void SetFormTouchSpell(MagicItemForm*);
    static unsigned short GetFormTouchSpellAnimation(TESForm*);
    unsigned short GetFormTouchSpellAnimation();
    void SetFormTouchSpellAnimation(unsigned short);
    MagicItemForm* m_pMagicItem;
    unsigned short m_usTouchSpellType;
    char _pad_a[2];
};
struct TESAIForm : public BaseFormComponent
{
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void CopyAISettings(TESAIForm*);
    void CopyAIPackageList(TESAIForm*);
    unsigned char GetAggression();
    void SetAggression(unsigned char, bool);
    unsigned char GetAssistance();
    void SetAssistance(unsigned char);
    static float GetConfidenceLevel(unsigned char);
    float GetConfidenceLevel();
    unsigned char GetConfidence();
    void SetConfidence(unsigned char, bool);
    unsigned char GetEnergy();
    void SetEnergy(unsigned char, bool);
    unsigned char GetResponsibility();
    void SetResponsibility(unsigned char, bool);
    unsigned char GetMood();
    void SetAIMood(unsigned char);
    unsigned int GetServiceFlags();
    void SetServiceFlags(unsigned int, bool);
    bool GetOffersService(unsigned int);
    void SetOffersService(unsigned int, bool);
    int GetTrainingSkill();
    void SetTrainingSkill(int);
    unsigned char GetTrainingSkillLevel();
    void SetTrainingSkillLevel(unsigned char);
    void SetAIData(PackedRecordData*);
    bool IsObjectUsable(TESObject*);
    bool HasAnAggroRadius();
    void SetHasAggroRadius(bool);
    unsigned int GetAggroRadius();
    void SetAggroRadius(unsigned int);
    bool HasPackage(TESPackage*);
    void AddPackage(TESPackage*);
    bool MovePackage(TESPackage*, bool);
    void InsertPackageAt(TESPackage*, TESPackage*, bool);
    void DeletePackage(TESPackage*);
    static TESPackage* GetCurrentPackage(Actor*);
    static void FindAvailablePackages(Actor*, void*, float, float);
    void AddFormChange(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    PackageList* GetPackageList();
    void* __vecDelDtor(unsigned int);
    char m_kAIData[20];
    char m_kPackageList[8];
};
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Save(void*);
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
struct TESAnimation : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    bool IsKFFileInList(char*);
    void AddKFFile(char*);
    bool HasSpecialAnimations();
    void* GetKFFileList();
    void Save(int);
    void LoadAnimationChunk(TESAnimation*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void* __vecDelDtor(unsigned int);
    char m_kKFFileList[8];
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct TESRaceForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESRace* GetFormRace(TESForm*);
    TESRace* GetFormRace();
    static char* GetFormRaceEditorID(TESForm*);
    char* GetFormRaceEditorID();
    void SetFormRace(TESRace*);
    TESRace* m_pRace;
};
struct FUN_00444fe0_shell : public ModelLoader
{
    void FUN_00444fe0(TESNPC*, void*, int, QueuedFile*);
};

struct QHeadLocal
{
    QHeadLocal(TESNPC*, int);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    int pad[13];
};
struct QHeadPtr
{
    QHeadPtr(QHeadLocal*);
    ~QHeadPtr();
    operator QHeadLocal*() const;
    int p;
};
struct QHeadPtrDest
{
};
// Creates a QHeadLocal for apNPC at aePriority, sets its parent to apParent, runs its vfn_20, and assigns it into aspQueuedHead.
// @fnv 0x00444fe0
void FUN_00444fe0_shell::FUN_00444fe0(TESNPC* apNPC, void* aspQueuedHead, int aePriority, QueuedFile* apParent)
{
    QHeadPtr spqueuedHead(new QHeadLocal(apNPC, aePriority));
    reinterpret_cast<::QueuedFile *>((((QHeadLocal*)spqueuedHead)))->SetParent(apParent);
    ((QHeadLocal*)spqueuedHead)->vfn_20();
    reinterpret_cast<::NP_0092c820 *>((((QHeadPtrDest*)aspQueuedHead)))->FUN_0092c820((const ::NP_0092c820 &)(spqueuedHead));
}

void* __cdecl operator new(unsigned int);
struct QIdle
{
    QIdle(void*, int, void*, void*);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    int pad[15];
};
struct QIdlePtr
{
    QIdlePtr(QIdle*);
    ~QIdlePtr();
    operator QIdle*() const;
    QIdlePtr& operator=(QIdle*);
    int p;
};
struct IdleMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(void*, QIdlePtr*, int);
};
struct FUN_00445200_holder : public ModelLoader
{
    void* a;
    void* b;
    void* c;
    void* d;
    IdleMap* m_pQueuedAnimIdleMap;
    void* InsertIdle(void* apIdle, void* apKey, int aePriority, void* apParent);
};
// Allocates a QIdle from the given arguments, inserts it into the idle map by key, and calls its virtual slot 20 on success.
// @fnv 0x00445200
void* FUN_00445200_holder::InsertIdle(void* apIdle, void* apKey, int aePriority, void* apParent)
{
    QIdlePtr spqueuedIdle(new QIdle(apIdle, aePriority, apKey, apParent));
    if (m_pQueuedAnimIdleMap->Insert(apKey, &spqueuedIdle, 0))
        ((QIdle*)spqueuedIdle)->vfn_20();
    else
        reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::QIdlePtr &)(spqueuedIdle))->FUN_006f74f0((::ObjA *)(::QIdle *)(0));
    return 0;
}

namespace fnv_004471c0 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
struct FUN_004471c0_shell : public ModelLoader
{
    KFModel* LoadKFModel(char*);
};

struct QueuedChildren
{
    void AddFinishedChild();
};
struct Flt
{
    operator unsigned int() const;
    int pad[3];
};
struct QueuedKFLocal
{
    QueuedKFLocal(const char*, int);
    ~QueuedKFLocal();
    void FUN_0043e2a0();
    int pad[12];
};
struct KFMap
{
    virtual void Slot0();
    virtual void Slot1();
    virtual bool Get(const char*, KFModel**);
};
// @fnv 0x004471c0
KFModel* FUN_004471c0_shell::LoadKFModel(char* apFilename)
{
    Flt autoEvent3;
    KFModel* pkfModel2 = 0;
    if (!((KFMap**)this)[1]->Get(apFilename, &pkfModel2))
    {
        QueuedKFLocal queuedKF(apFilename, 0);
        queuedKF.FUN_0043e2a0();
        reinterpret_cast<::fnv_0043e4b0::QK_0043e4b0 *>(&(queuedKF))->FUN_0043e4b0();
        pkfModel2 = (KFModel*)(unsigned int)autoEvent3;
    }
    else
    {
        if (!::FUN_004431b0((int *)(pkfModel2)))
            ::FUN_005b5e40();
    }
    if (pkfModel2)
        ((QueuedChildren*)pkfModel2)->AddFinishedChild();
    return pkfModel2;
}
}  // namespace fnv_004471c0

struct FUN_00447850_shell : public ModelLoader
{
    void* FUN_00447850(void*, void*);
};

void* __cdecl operator new(unsigned int);
struct StrList
{
    StrList();
    void AddHead(char**);
    const char** FUN_006815c0();
    int pad[2];
};
// @fnv 0x00447850
void* FUN_00447850_shell::FUN_00447850(void* apList, void* apDestList)
{
    StrList* pList = (StrList*)apList;
    StrList* pBaseList = (StrList*)apDestList;
    if (!pBaseList)
        pBaseList = new StrList;
    while (pList)
    {
        const char* pfilename = *((const char **)(new ((void *)(pList)) ::Vec3()));
        int ifilenameLen = ::FUN_0044a670(pfilename) + 1;
        char* ptmpFilename = new char[ifilenameLen];
        TaskQueueInterface::CopyStringToBuffer(ptmpFilename, ifilenameLen, pfilename);
        pBaseList->AddHead(&ptmpFilename);
        pList = ((::StrList *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
    }
    return pBaseList;
}

namespace fnv_00448c10 {
struct Flt
{
    operator unsigned int() const;
};
struct GlobalObject_00528cb0 : public Flt
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    void* pObj;
};
struct Q449
{
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release();
};

// Iterates the container at self+0x1c via FUN_00449280, calling Release on each object until the iterator is empty, then returns true.
// @fnv 0x00448c10
bool ReleaseAllObjects(char* self)
{
    GlobalObject_00528cb0 iter(0);
    reinterpret_cast<::Q449 *>((((Q449*)*(void**)(self + 0x1c))))->FUN_00449280(&iter);
    while (iter)
    {
        ((Obj*)(unsigned int)iter)->Release();
        reinterpret_cast<::Q449 *>((((Q449*)*(void**)(self + 0x1c))))->FUN_00449280(&iter);
    }
    return true;
}
}  // namespace fnv_00448c10

namespace fnv_00448ed0 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
struct FUN_00448ed0_shell : public ModelLoader
{
    bool InsertQueuedTexture(BSFileEntry*, QueuedTexture*);
};

struct GlobalObject_00528cb0
{
    int value;
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
};
struct QueuedTextureMapStandIn
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(BSFileEntry*, GlobalObject_00528cb0*, int);
};
// Wraps apQueuedTexture in a GlobalObject_00528cb0 and inserts apFileEntry with it into the map at this+0x20, returning the insert result.
// @fnv 0x00448ed0
bool FUN_00448ed0_shell::InsertQueuedTexture(BSFileEntry* apFileEntry, QueuedTexture* apQueuedTexture)
{
    bool bresult;
    {
        GlobalObject_00528cb0 obj((int)apQueuedTexture);
        bresult = (*(QueuedTextureMapStandIn**)((char*)this + 0x20))->Insert(apFileEntry, &obj, 0);
    }
    return bresult;
}
}  // namespace fnv_00448ed0

namespace fnv_00448f80 {
struct Flt
{
    operator unsigned int() const;
};
struct GlobalObject_00528cb0 : public Flt
{
    GlobalObject_00528cb0(int);
    ~GlobalObject_00528cb0();
    void* pObj;
};
struct Target
{
    virtual void v0();
    virtual void v1();
    virtual bool Test(void*, void*);
};
struct Holder
{
    unsigned int FUN_00448f80(void* arg);
    char pad[0x20];
    Target* pTarget;
};

// @fnv 0x00448f80
unsigned int Holder::FUN_00448f80(void* arg)
{
    GlobalObject_00528cb0 iter(0);
    if (pTarget->Test(arg, &iter))
    {
        return iter;
    }
    return 0;
}
}  // namespace fnv_00448f80

struct VecAllocBase
{
    int* FUN_0044abd0(unsigned int);
};
struct VecAlloc
{
    char pad[0xc];
    int* pBegin;
    int* pCur;
    int* pEnd;
    unsigned int FUN_0044a2c0();
    bool FUN_0044a240(unsigned int);
};
// Resets the vector to empty, then allocates space for n elements if n is nonzero and the capacity allows; returns true on success.
// @fnv 0x0044a240
bool VecAlloc::FUN_0044a240(unsigned int n)
{
    pBegin = 0;
    pCur = 0;
    pEnd = 0;
    if (n == 0)
    {
        return false;
    }
    else
    {
        if (FUN_0044a2c0() < n)
        {
            ::fnv_0065f640::ThrowVectorTooLong();
        }
        else
        {
            pBegin = ((VecAllocBase*)((char*)this + 8))->FUN_0044abd0(n);
            pCur = pBegin;
            pEnd = pBegin + n;
        }
    }
    return true;
}

namespace fnv_006502f0 {
struct NP
{
    NP(int);
    ~NP();
    void* pData;
};
struct Flt
{
    operator unsigned int() const;
};
struct Helper62d0
{
    Helper62d0& operator=(void*);
};
struct Map62d0
{
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int GetFlags();
};
struct FlagSink
{
    void FUN_0044b300(unsigned int);
};
struct GetAtArgs
{
    const char* apcKey;
    Helper62d0* aspModel;
    FlagSink* out;
};

// Looks up args.apcKey in the map at self+4, stores the found entry's model pointer and passes its flags to args.out, returning whether the lookup succeeded.
// @fnv 0x006502f0
bool LookupModelAndGetFlags(Map62d0* self, GetAtArgs aLookupArgs)
{
    ::FUN_00652140();
    NP entry(0);
    bool bFound = false;
    if (reinterpret_cast<::Map62d0 *>((((Map62d0*)((char*)self + 4))))->FUN_006c62d0((unsigned int)aLookupArgs.apcKey, (void **)&(entry)))
    {
        *aLookupArgs.aspModel = (void*)((unsigned int)*(Flt*)&entry + 8);
        aLookupArgs.out->FUN_0044b300(
            ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_Helper*)(unsigned int)*(Flt*)aLookupArgs.aspModel)))->GetName())));
        bFound = true;
    }
    ::fnv_00652190::FUN_00652190();
    return bFound;
}
}  // namespace fnv_006502f0

// @fnv 0x0043b1d0
int __cdecl FUN_0043b1d0(int* param_1)
{
    return *param_1;
}

struct AbstractHeapLogger;

// @fnv 0x0043bce0
bool IsHeapLoggerPresent()
{
    return DAT_011f6388 != 0;
}

namespace fnv_0043bd00 {
struct AbstractHeapLogger;

// @fnv 0x0043bd00
AbstractHeapLogger* FUN_0043bd00()
{
    return (*reinterpret_cast<::fnv_0043bd00::AbstractHeapLogger * *>(&::DAT_011f6388));
}
}  // namespace fnv_0043bd00

void _Deallocate(void*);

struct FUN_0051d400_shell
{
    void FUN_0051d400();
    void* DeleteIfFlagged(unsigned int flags);
};

// @fnv 0x0043d640
void* FUN_0051d400_shell::DeleteIfFlagged(unsigned int flags)
{
    FUN_0051d400();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct QueuedTreeBillboard : IOTask
{
    void ApplyQueuedTexture();
    void QueueForPostProcess();
};

void QueuedTreeBillboard::ApplyQueuedTexture()
{}

// @fnv 0x0043d670
void QueuedTreeBillboard::QueueForPostProcess()
{
    reinterpret_cast<::fnv_0043c550::FUN_0043c550_shell *>(this)->ApplyQueuedTexture();
    reinterpret_cast<::IOManager *>(this)->SubmitTask();
}

namespace fnv_0043d820 {
struct QueuedTreeBillboard
{
    virtual ~QueuedTreeBillboard();
    bool FUN_0043d820(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x0043d820
bool QueuedTreeBillboard::FUN_0043d820(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>(this)->FUN_00c3d0e0(apDescription, aiBufferSize, "Tree Billboard");
}
}  // namespace fnv_0043d820

struct FaceGenPaletteBase
{
    ~FaceGenPaletteBase();
    void FUN_0043dc50();
};

// @fnv 0x0043dc50
void FaceGenPaletteBase::FUN_0043dc50()
{
    reinterpret_cast<::FUN_00c3c620 *>(this)->FUN_00c3c620::~FUN_00c3c620();
}

struct QueuedHelmet
{
    void FUN_0043eff0();
    void ApplyQueuedModels();
};

// @fnv 0x0043eff0
void QueuedHelmet::FUN_0043eff0()
{
    ApplyQueuedModels();
}

struct FUN_0043f010
{
    char m_auiShapeKeys[0x2b0];
    NiRenderer* m_field;
    NiRenderer* Get();
};

// @fnv 0x0043f010
NiRenderer* FUN_0043f010::Get()
{
    return m_field;
}

namespace fnv_0043f1f0 {
extern "C"
{
}

struct FUN_0043f1f0_class
{
    void FUN_0043f1f0(unsigned char arg);
};

// @fnv 0x0043f1f0
void FUN_0043f1f0_class::FUN_0043f1f0(unsigned char arg)
{
    ::SetFlagBit0(arg, (unsigned char *)(void *)((void*)((char*)this + 0x120)));
}
}  // namespace fnv_0043f1f0

struct AttachDistant3DTask
{
    virtual ~AttachDistant3DTask()
    {}
    void* FUN_00440680(unsigned int flags);
    void FUN_004406b0();
};
void __cdecl _Deallocate(void*);

struct FUN_00441980_Class
{
    void FUN_00440eb0();
    void FUN_00441980();
};

struct BackgroundCloneThread
{
    void FUN_004422c0();
    void* FUN_00442290(unsigned int flags);
};

struct FUN_00442630Class
{
    char m_auiShapeKeys[0x30];
    char m_flag;
    void FUN_00442630();
};
// @fnv 0x00442630
void FUN_00442630Class::FUN_00442630()
{
    m_flag = 1;
}

struct QueuedReplacementKFList : IOTask
{
    void FUN_00446a40();
};

// @fnv 0x00446a40
void QueuedReplacementKFList::FUN_00446a40()
{
    reinterpret_cast<::ObjectC3 *>(this)->NotifyParents();
}

struct FUN_00449170_Class
{
    void FUN_00449170();
};

// @fnv 0x00449170
void FUN_00449170_Class::FUN_00449170()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xC) = 6;
}

struct FUN_00449a20_cls
{
    void FUN_004490e0();
    void* FUN_00449a20(unsigned int flags);
};

void _Deallocate(void* p);

// Calls FUN_004490e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00449a20
void* FUN_00449a20_cls::FUN_00449a20(unsigned int flags)
{
    FUN_004490e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl _Deallocate(void*);
void FUN_004499c0(void*);

struct FUN_00449ba0Class
{
    void* FUN_00449ba0(unsigned int flags);
};

// @fnv 0x00449ba0
void* FUN_00449ba0Class::FUN_00449ba0(unsigned int flags)
{
    FUN_004499c0(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_004499e0(void*);
void __cdecl _Deallocate(void*);

struct FUN_00449bd0_Class
{
    void* FUN_00449bd0(unsigned int flags);
};

// Calls FUN_004499e0 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00449bd0
void* FUN_00449bd0_Class::FUN_00449bd0(unsigned int flags)
{
    FUN_004499e0(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_00449a00(int**);
void __cdecl _Deallocate(void*);

struct FUN_00449c00_class
{
    void* FUN_00449c00(unsigned int flags);
};

// @fnv 0x00449c00
void* FUN_00449c00_class::FUN_00449c00(unsigned int flags)
{
    FUN_00449a00((int**)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

struct FUN_00449d40_class
{
    void FUN_00449d60();
    void FUN_00449d40();
};

NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

struct FUN_00449ea0_cls
{
    void FUN_00449ec0();
    void FUN_00449ea0();
};

// @fnv 0x00449ea0
void FUN_00449ea0_cls::FUN_00449ea0()
{
    FUN_00449ec0();
}

extern unsigned char DAT_01202df0;

// @fnv 0x0044ada0
void FUN_0044ada0(unsigned char value)
{
    DAT_01202df0 = value;
}

namespace fnv_0044ae10 {
// @fnv 0x0044ae10
unsigned char FUN_0044ae10(unsigned char a)
{
    return (a & 1) != 0;
}
}  // namespace fnv_0044ae10

// Sets or clears bit 0 of the byte pointed to by p according to flag.
// @fnv 0x0044ae20
void SetFlagBit0(bool abSet, unsigned char* p)
{
    if (abSet)
        *p |= 1;
    else
        *p &= 0xfffffffe;
}

namespace fnv_0044ae50 {
// @fnv 0x0044ae50
unsigned char __cdecl FUN_0044ae50(unsigned char a)
{
    return (a & 2) != 0;
}
}  // namespace fnv_0044ae50

// @fnv 0x0044ae60
void FUN_0044ae60(bool bSet, unsigned char* pFlags)
{
    if (bSet)
        *pFlags |= 2;
    else
        *pFlags &= 0xfffffffd;
}

namespace fnv_0044ae90 {
// @fnv 0x0044ae90
char FUN_0044ae90(unsigned char param_1)
{
    return (param_1 & 4) != 0;
}
}  // namespace fnv_0044ae90

// @fnv 0x0044aea0
void FUN_0044aea0(bool abSet, unsigned char* flags)
{
    if (abSet)
        *flags = *flags | 4;
    else
        *flags = *flags & 0xfffffffb;
}

namespace fnv_0044af20 {
// @fnv 0x0044af20
char FUN_0044af20(unsigned char a)
{
    return (a & 8) != 0;
}
}  // namespace fnv_0044af20

// Sets or clears bit 3 (0x8) in the byte pointed to by param2 according to param1.
// @fnv 0x0044af30
void SetFlag8(unsigned char param1, unsigned char* param2)
{
    if (param1)
        *param2 |= 8;
    else
        *param2 &= 0xfffffff7;
}

namespace fnv_0044af60 {
// @fnv 0x0044af60
char FUN_0044af60(unsigned char a)
{
    return (a & 0x10) != 0;
}
}  // namespace fnv_0044af60

// Sets or clears bit 0x10 in the byte pointed to by pByte according to bFlag.
// @fnv 0x0044af70
void FUN_0044af70(bool bFlag, unsigned char* pByte)
{
    if (bFlag)
        *pByte = *pByte | 0x10;
    else
        *pByte = *pByte & 0xFFFFFFEF;
}

// Sets or clears bit 0x20 in the byte pointed to by param2 according to param1.
// @fnv 0x0044afb0
void SetFlag20(unsigned char abSet, unsigned char* pFlags)
{
    if (abSet)
        *pFlags |= 0x20;
    else
        *pFlags &= 0xFFFFFFDF;
}

namespace fnv_0044b030 {
struct KFModel
{
    KFModel* vtable;
    void FUN_0044b030();
};

// @fnv 0x0044b030
void KFModel::FUN_0044b030()
{
    if (vtable)
        reinterpret_cast<::fnv_0044b050::FUN_0044b050_shell *>((vtable))->FUN_0044b050();
}
}  // namespace fnv_0044b030

int __cdecl InitScriptRunLock(void*);

struct FUN_0044b2a0_Class
{
    void FUN_0044b2a0();
};

// @fnv 0x0044b2a0
void FUN_0044b2a0_Class::FUN_0044b2a0()
{
    ::FUN_0040b460((unsigned int *)(void *)((char*)this + 0x20));
}

void __cdecl FinishScriptRunLock(void*);

struct FUN_0044b2e0
{
    void Method(void);
};

// @fnv 0x0044b2e0
void FUN_0044b2e0::Method(void)
{
    ::WaitForSingleObjectEx((long *)(void *)((char*)this + 0x20));
}

// @fnv 0x0044dff0
bool FUN_0044dff0(int* piValue)
{
    return (*piValue & 1) ? true : false;
}

extern unsigned char DAT_011dea2a;

// @fnv 0x00525420
unsigned char FUN_00525420()
{
    return DAT_011dea2a;
}

int __cdecl FUN_0043b460(long volatile*, long, long);
struct FUN_0043b410_class
{
    void AtomicAdd(int a);
};
// @fnv 0x00445300
void FUN_00445300_shell::FUN_00445300(char* apModelFileName, bool abDeleteIfUnreferenced, unsigned int aiNumDecrements)
{
    ModelStub* pmodel = 0;
    if (((ModelMapHolder*)this)->m_pLoadedModelMap->Lookup(apModelFileName, &pmodel))
    {
        if (aiNumDecrements == 1)
            reinterpret_cast<::FUN_0043acb0_shell *>((pmodel))->ReleaseScriptRunLock();
        else
            reinterpret_cast<::FUN_0043b410_class *>((pmodel))->AtomicAdd(-(short)aiNumDecrements);
        if (abDeleteIfUnreferenced)
            ((LoaderStub*)this)->FUN_00448920(pmodel, apModelFileName);
    }
}
// Atomically adds a to the pointer stored at this+8, retrying with FUN_0040fca0(0) until the compare-and-swap succeeds.
// @fnv 0x0043b410
void FUN_0043b410_class::AtomicAdd(int aiDelta)
{
    long volatile* p = *(long volatile**)((char*)this + 8);
    while (FUN_0043b460((long volatile*)((char*)this + 8), (long)p, (long)p + aiDelta) != (long)p)
    {
        FUN_0040fca0(0);
        p = *(long volatile**)((char*)this + 8);
    }
}

struct FUN_0043c3b0_This
{
    int FUN_0043c3b0();
};

// @fnv 0x0043c3b0
int FUN_0043c3b0_This::FUN_0043c3b0()
{
    return ((int*)this)[3] & 0x7fffffff;
}

namespace fnv_0043d580 {
struct QueuedTreeBillboard
{
    void FUN_0043d5b0();
    void* FUN_0043d580(unsigned int flags);
};

// Calls FUN_0043d5b0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0043d580
void* QueuedTreeBillboard::FUN_0043d580(unsigned int flags)
{
    FUN_0043d5b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0043d580

struct QueuedTreeModel
{
    bool GetTreeModelDescription(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x0043db00
bool QueuedTreeModel::GetTreeModelDescription(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>(this)->FUN_00c3d0e0(apDescription, aiBufferSize, "tree model");
}

class Flt
{
  public:
    operator unsigned int();
};

class IOTask;

class QueuedReplacementKF
{
  public:
    void FUN_0043e940();
};

namespace fnv_0043ea00 {
struct FUN_00c3d0e0_stub
{
};

struct QueuedReplacementKF
{
    bool FUN_0043ea00(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x0043ea00
bool QueuedReplacementKF::FUN_0043ea00(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>((((FUN_00c3d0e0_stub*)this)))->FUN_00c3d0e0(apDescription, aiBufferSize, "Replacement KF");
}
}  // namespace fnv_0043ea00

struct FUN_00440640_shell
{
    void FUN_00440640();
    void* FUN_00440610(unsigned int flags);
};

void _Deallocate(void*);

// Calls FUN_00440640, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00440610
void* FUN_00440640_shell::FUN_00440610(unsigned int flags)
{
    FUN_00440640();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00440e30_This
{
    NiNode* FUN_00440e30();
};


// @fnv 0x00440e30
NiNode* FUN_00440e30_This::FUN_00440e30()
{
    return *(NiNode**)(::FNV_FormTypeNames + (*(unsigned char*)((char*)this + 4)) * 0xc);
}

namespace fnv_00440e80 {
struct FUN_00441980_Class
{
    void FUN_00440eb0(void);
    void* FUN_00440e80(unsigned int flags);
};
void _Deallocate(void* p);
// Calls FUN_00440eb0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00440e80
void* FUN_00441980_Class::FUN_00440e80(unsigned int flags)
{
    FUN_00440eb0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00440e80

namespace fnv_00441950 {
struct FUN_00441980_Class
{
    void FUN_00441980(void);
    void* FUN_00441950(unsigned int flags);
};

void FUN_00441980_Class::FUN_00441980(void)
{}

extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00441980, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00441950
void* FUN_00441980_Class::FUN_00441950(unsigned int flags)
{
    reinterpret_cast<::FUN_00441980_Class *>(this)->FUN_00441980();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00441950

void __cdecl SetFlag20(unsigned char, unsigned char*);

struct FUN_00443ff0Class
{
    void FUN_00443ff0(unsigned char arg);
};

// Calls SetFlag20 with arg and the byte pointer at offset 0x3c of this object.
// @fnv 0x00443ff0
void FUN_00443ff0Class::FUN_00443ff0(unsigned char aucValue)
{
    SetFlag20(aucValue, (unsigned char*)this + 0x3c);
}

namespace fnv_00446a10 {
struct FaceGenPaletteBase
{
    void* FUN_00446a10(unsigned int flags);
};

void _Deallocate(void* p);

// Calls FUN_0043dc50, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00446a10
void* FaceGenPaletteBase::FUN_00446a10(unsigned int flags)
{
    reinterpret_cast<::FaceGenPaletteBase *>(this)->FUN_0043dc50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00446a10

struct FUN_00449920Class
{
    void FUN_00449920();
};

// @fnv 0x00449920
void FUN_00449920Class::FUN_00449920()
{
    ((char*)this)[0x10] = 0;
}

NiRenderer* FUN_0043c4b0();
const NiFixedString& FUN_00448a80();

extern void _Deallocate(void*);

struct FUN_00449a50_StandIn
{
    void* FUN_00449a50(unsigned int flags);
};

namespace fnv_00449a80 {
struct FUN_00449d40_class
{
    void* FUN_00449a80(unsigned int flags);
};
void _Deallocate(void*);

// Calls FUN_00449d40, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449a80
void* FUN_00449d40_class::FUN_00449a80(unsigned int flags)
{
    reinterpret_cast<::FUN_00449d40_class *>(this)->FUN_00449d40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00449a80

namespace fnv_00449ae0 {
extern void* __cdecl _Deallocate(void*);

struct FUN_00449ae0_Class
{
    void* DestroyModelLoader(unsigned int flags);
};

// @fnv 0x00449ae0
void* FUN_00449ae0_Class::DestroyModelLoader(unsigned int flags)
{
    ((ModelLoader*)this)->FUN_004431d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00449ae0

void FUN_00449940(void**);

struct FUN_00449b10_Class
{
    void* FUN_00449b10(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x00449b10
void* FUN_00449b10_Class::FUN_00449b10(unsigned int flags)
{
    FUN_00449940((void**)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00449c50_class
{
    int FUN_00449c50();
};

struct FUN_00449c30_class : FUN_00449c50_class
{
    int CallBaseMethod();
};
// Calls CallBaseMethod, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449a50
void* FUN_00449a50_StandIn::FUN_00449a50(unsigned int flags)
{
    reinterpret_cast<::FUN_00449c30_class *>(this)->CallBaseMethod();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00449f20 {
struct FUN_00449ea0_cls
{
    void FUN_00449ec0();
    void* FUN_00449f20(unsigned int flags);
};

extern "C" void* __cdecl _Deallocate(void*);

// @fnv 0x00449f20
void* FUN_00449ea0_cls::FUN_00449f20(unsigned int flags)
{
    FUN_00449ea0_cls::FUN_00449ec0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00449f20

namespace fnv_0044afa0 {
// @fnv 0x0044afa0
char FUN_0044afa0(unsigned char param_1)
{
    return (param_1 & 0x20) != 0;
}
}  // namespace fnv_0044afa0

namespace fnv_0044b270 {
struct FUN_0044b2a0_Class
{
};

class FUN_0044b270_Class
{
  public:
    FUN_0044b2a0_Class* m_pData;
    FUN_0044b270_Class* FUN_0044b270(FUN_0044b2a0_Class* a);
};

// Stores the given object in m_pData and, if it is non-null, calls its FUN_0044b2a0 method; returns this.
// @fnv 0x0044b270
FUN_0044b270_Class* FUN_0044b270_Class::FUN_0044b270(FUN_0044b2a0_Class* apData)
{
    m_pData = apData;
    if (m_pData != 0)
    {
        reinterpret_cast<::FUN_0044b2a0_Class *>((m_pData))->FUN_0044b2a0();
    }
    return this;
}
}  // namespace fnv_0044b270

extern int DAT_010172b8;

struct FUN_0044cc10
{
    int* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    char m_iThirdValue;
    FUN_0044cc10();
};

// @fnv 0x0044cc10
FUN_0044cc10::FUN_0044cc10()
{
    m_iWordAt00 = &DAT_010172b8;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

// @fnv 0x0044dec0
int ClearLowBit(int* piValue)
{
    return *piValue & 0xfffffffe;
}

struct FUN_0044df00Class
{
    void ClearLowBit();
    void FUN_0044df00();
};

// @fnv 0x0044df00
void FUN_0044df00Class::FUN_0044df00()
{
    ClearLowBit();
}

struct FUN_0043c0d0_class
{
    void ForwardByteToMember(unsigned char);
};
// @fnv 0x0043c050
void Q_0043c050::FUN_0043c050()
{
    if (((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
    {
        bool bresult = reinterpret_cast<ML_0043c050*>(g_modelLoader)->InsertQueuedTexture(((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())), this);
        reinterpret_cast<::FUN_0043c100_shell *>(this)->FUN_0043c100(bresult);
    }
    if (reinterpret_cast<::FUN_0043c130_shell *>((reinterpret_cast<ML_0043c050*>(g_modelLoader)))->IsLoadTexturesDegraded())
        reinterpret_cast<::FUN_0043c0d0_class *>(this)->ForwardByteToMember(true);
    reinterpret_cast<IOV_0043c050*>(::DAT_01202d98)->Slot(this);
}
// Passes a to FUN_0044ae60 together with the pointer at this+0x34.
// @fnv 0x0043c0d0
void FUN_0043c0d0_class::ForwardByteToMember(unsigned char aByte)
{
    ::FUN_0044ae60(aByte, (unsigned char *)(void *)(reinterpret_cast<char*>(this) + 0x34));
}

namespace fnv_0043c6b0 {
struct QueuedTreeModel
{
    bool FUN_0043c6b0(char* apDescription, unsigned int aiBufferSize);
};
// @fnv 0x0043c6b0
bool QueuedTreeModel::FUN_0043c6b0(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>(this)->FUN_00c3d0e0(apDescription, aiBufferSize, "texture");
}
}  // namespace fnv_0043c6b0

namespace fnv_0043c960 {
struct SetterHelper
{
};

struct GO : SetterHelper
{
    GO(int);
    ~GO();
};

struct QBase
{
    virtual ~QBase();
    char pad[0x2c];
    QBase(int);
};


struct FUN_0043c960 : QBase
{
    GO m_go;
    int m_field34;
    int m_field38;
    char m_field3c;
    float m_field40;

    FUN_0043c960(void* param1, int param2);
    virtual ~FUN_0043c960();
};

// @fnv 0x0043c960
FUN_0043c960::FUN_0043c960(void* param1, int param2) : QBase(param2), m_go(0), m_field34(0), m_field38(0), m_field3c(0)
{
    reinterpret_cast<::NP_0044aed0 *>(&(m_go))->FUN_0044aed0((::WaitableObject *)(param1));
    ::SetFieldCToFive((char*)this);
    m_field40 = 0.0f;
}
}  // namespace fnv_0043c960

namespace fnv_0043d510 {
struct QueuedTreeModel
{
    bool FUN_0043d510(char*, unsigned int);
};

// @fnv 0x0043d510
bool QueuedTreeModel::FUN_0043d510(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>(this)->FUN_00c3d0e0(apDescription, aiBufferSize, "model");
}
}  // namespace fnv_0043d510

namespace fnv_0043e550 {
struct QueuedTreeModel
{
    bool FUN_0043e550(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x0043e550
bool QueuedTreeModel::FUN_0043e550(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>(this)->FUN_00c3d0e0(apDescription, aiBufferSize, "KF");
}
}  // namespace fnv_0043e550

namespace fnv_0043e880 {
struct QueuedTreeModel
{
};

struct FUN_0043e880_Class
{
    bool FUN_0043e880(char* apDescription, unsigned int aiBufferSize);
};

// Forwards the description and buffer size to FUN_00c3d0e0 with the "AnimIdle" tag and returns its result.
// @fnv 0x0043e880
bool FUN_0043e880_Class::FUN_0043e880(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>((reinterpret_cast<QueuedTreeModel*>(this)))->FUN_00c3d0e0(apDescription, aiBufferSize, "AnimIdle");
}
}  // namespace fnv_0043e880

struct FUN_0043e920_class
{
    void FUN_0043e1b0();
    void FUN_0043e920();
};

// @fnv 0x0043e920
void FUN_0043e920_class::FUN_0043e920()
{
    reinterpret_cast<::fnv_0043e1b0::FUN_0043e1b0 *>(this)->fnv_0043e1b0::FUN_0043e1b0::~FUN_0043e1b0();
}

struct FUN_0043e990_Class
{
    void IncrementCounter();
};
// @fnv 0x0043e940
void QueuedReplacementKF::FUN_0043e940()
{
    reinterpret_cast<::fnv_0043e4b0::QK_0043e4b0 *>(this)->FUN_0043e4b0();
    if (((Flt*)((char*)this + 0x30))->operator unsigned int())
    {
        if (!::FUN_00449130((int *)this))
        {
            if (*(QueuedReplacementKF**)((char*)this + 0x3c))
            {
                reinterpret_cast<::FUN_0043e990_Class *>(((*(QueuedReplacementKF**)((char*)this + 0x3c))))->IncrementCounter();
            }
            reinterpret_cast<::IOManager *>((((IOTask*)this)))->SubmitTask();
        }
    }
}

// @fnv 0x0043e990
void FUN_0043e990_Class::IncrementCounter()
{
    *(int*)((char*)this + 0x2c) = *(int*)((char*)this + 0x2c) + 1;
}

namespace fnv_0043fc10 {
struct QueuedHelmet
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    bool FormatQueuedHelmetDescription(char* apDescription, unsigned int aiBufferSize);
};


// Writes a formatted "Queued helmet for biped anim %08X" string using m_28 into apDescription and returns true.
// @fnv 0x0043fc10
bool QueuedHelmet::FormatQueuedHelmetDescription(char* apDescription, unsigned int aiBufferSize)
{
    ::FUN_00406d00(apDescription, aiBufferSize, "Queued helmet for biped anim %08X", m_28);
    return true;
}
}  // namespace fnv_0043fc10

namespace fnv_00440e50 {
extern int DAT_01016c5c;
struct S4411
{
    void FUN_0043fd40(int a, int b);
    void* InitWithGlobal(int a, int b);
};
// Calls FUN_0043fd40 with the two arguments, stores the address of DAT_01016c5c at the start of this, and returns this.
// @fnv 0x00440e50
void* S4411::InitWithGlobal(int aiArg1, int aiArg2)
{
    FUN_0043fd40(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &DAT_01016c5c;
    return this;
}
}  // namespace fnv_00440e50

struct FUN_00440eb0_class
{
    void FUN_00440eb0();
};
// @fnv 0x00441980
void FUN_00441980_Class::FUN_00441980()
{
    reinterpret_cast<::FUN_00440eb0_class *>(this)->FUN_00440eb0();
}

namespace fnv_00441920 {
extern int DAT_01016d34;
struct FUN_004411d0
{
    int* m_vft;
    int m_kPointA;
    int m_kPointB;
    FUN_004411d0(int a, int b);
};
struct FUN_00441920 : FUN_004411d0
{
    FUN_00441920(int a, int b);
};
// Constructs the object by forwarding a and b to the base constructor and setting m_vft to DAT_01016d34.
// @fnv 0x00441920
FUN_00441920::FUN_00441920(int a, int b) : FUN_004411d0(a, b)
{
    m_vft = &DAT_01016d34;
}
}  // namespace fnv_00441920

namespace fnv_00441c50 {
struct BSFile;
struct BSFileEntry;
struct LoadedFile;
struct QueuedFileEntry : public QueuedFile
{
    virtual void __vslot_0();
    virtual unsigned char GetFileIndex();
    virtual void GenerateKey();
    char* GetFileName();
    void SetFileName(char*);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry*);
    void LookupFileEntry(int);
    BSFile* GetFile(int, int);
    void GetLookupFileName(int, char*);
    bool GetDescription(char*, unsigned int, char*);
    char _pad_4[36];
    char* pFileName;
    BSFileEntry* m_pFileEntry;
};
struct QueuedFileLoad : public QueuedFileEntry
{
    virtual void __vslot_0();
    virtual void DispatchToManager();
    virtual void Run();
    virtual void Finish();
    LoadedFile* GetLoadedFile();
    virtual unsigned char GetFileIndex();
    char m_pLoadedFile[4];
    int m_iLoadPriority;
};

extern int DAT_01016dc4;
struct QBase
{
    char pad[48];
    QBase(int);
    ~QBase();
};
struct FUN_0063fa10
{
};
template <> class NiPointer<LoadedFile>
{
  public:
    NiPointer(LoadedFile*);
    ~NiPointer();
    void* p;
};
struct FUN_00441c50 : QBase
{
    NiPointer<LoadedFile> sp;
    int m_iLoadPriority;
    FUN_00441c50(char const*, int, int);
};
// @fnv 0x00441c50
FUN_00441c50::FUN_00441c50(char const* a, int b, int c)
    : QBase(b), sp(((*(void**)this = (void*)&DAT_01016dc4), (LoadedFile*)0)), m_iLoadPriority(c)
{
    reinterpret_cast<::FUN_00c3cee0_shell *>((((FUN_0063fa10*)this)))->FUN_00c3cee0((char *)(a));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>((((FUN_0063fa10*)this)))->LookupFileEntryByArchive(::FUN_00449050(m_iLoadPriority));
}
}  // namespace fnv_00441c50

namespace fnv_00442130 {
struct FUN_00441d80
{
    FUN_00441d80(int, int);
    ~FUN_00441d80();
    virtual void vfunc();
    char pad[0x34];
};

struct GO
{
    int pad;
    GO(int);
    ~GO();
    GO& operator=(void*);
};

struct FUN_0044b270
{
    FUN_0044b270(int);
    ~FUN_0044b270();
    void FUN_0044b300(void*);
};

struct FUN_00442130 : FUN_00441d80
{
    GO m_model;
    FUN_0044b270 m_meshData;

    FUN_00442130(void* apModel, void* apMeshData);
    virtual ~FUN_00442130();
};

// Constructs the object with base parameters 0 and 5, assigns apModel to m_model and passes apMeshData to m_meshData.FUN_0044b300.
// @fnv 0x00442130
FUN_00442130::FUN_00442130(void* apModel, void* apMeshData) : FUN_00441d80(0, 5), m_model(0), m_meshData(0)
{
    m_model = apModel;
    m_meshData.FUN_0044b300(apMeshData);
}
}  // namespace fnv_00442130

struct FUN_00444d00_Class
{
    bool FUN_00444d00(int mask);
};

// @fnv 0x00444d00
bool FUN_00444d00_Class::FUN_00444d00(int mask)
{
    return (*(int*)((char*)this + 0xC8) & mask) ? true : false;
}

namespace fnv_00446f70 {
struct FUN_00442510_Cl
{
};

struct FUN_00446f70_Cl : ModelLoader
{
    void FUN_00446f70();
};

// @fnv 0x00446f70
void FUN_00446f70_Cl::FUN_00446f70()
{
    ProcessQueuedFile();
    ::FUN_00442510((::FUN_00442510_Cl *)(((FUN_00442510_Cl*)this)));
}
}  // namespace fnv_00446f70

void SignalAtOffset18(char*);

struct FUN_00446ff0 : ModelLoader
{
    void FUN_00446ff0_();
};

// @fnv 0x00446ff0
void FUN_00446ff0::FUN_00446ff0_()
{
    ProcessQueuedFile();
    SignalAtOffset18(reinterpret_cast<char*>(this));
}

struct FUN_00448a20_class
{
    int a;
    int b;
    int c;
    bool FUN_00448a20() const;
};
// @fnv 0x00448a20
bool FUN_00448a20_class::FUN_00448a20() const
{
    return (c & 0x80) ? true : false;
}

namespace fnv_00449030 {
struct FUN_00442630Class
{
};

struct FUN_00449030Class
{
    char pad[0x28];
    FUN_00442630Class* m_p;
    void CallMemberFunction(void);
};

// @fnv 0x00449030
void FUN_00449030Class::CallMemberFunction(void)
{
    reinterpret_cast<::FUN_00442630Class *>((m_p))->FUN_00442630();
}
}  // namespace fnv_00449030

namespace fnv_004490e0 {
int __cdecl FinishScriptRunLock(void*);

struct FUN_004490e0_Class
{
    void* m_p;
    void FUN_004490e0();
};

// Points m_p at DAT_01017138 and calls FinishScriptRunLock on DAT_011c3b38.
// @fnv 0x004490e0
void FUN_004490e0_Class::FUN_004490e0()
{
    m_p = &::DAT_01017138;
    ::WaitForSingleObjectEx((long *)(void *)(&::DAT_011c3b38));
}
}  // namespace fnv_004490e0

struct FUN_0044ee20_class
{
    int GetElementAddress(int index);
};

// @fnv 0x0044ee20
int FUN_0044ee20_class::GetElementAddress(int index)
{
    return *(int*)((char*)this + 0xc) + index * 4;
}

struct FUN_00905330
{
    void Remove(void*);
};
struct FUN_0044f870
{
    void FUN_0044f870_0044f870(void* ap);
};
// @fnv 0x0044f870
void FUN_0044f870::FUN_0044f870_0044f870(void* ap)
{
    reinterpret_cast<::ItemChangeListNode *>((((FUN_00905330*)((char*)this + 0x10c))))->FUN_00905330((*(::InventoryStackRecord *const *)(&ap)));
}

struct FUN_006ecba0_class
{
    void* m_p;
    void* FUN_006ecba0(bool b, void* p);
};

// Stores p in m_p, calls FUN_0044e010 with b, and returns this.
// @fnv 0x006ecba0
void* FUN_006ecba0_class::FUN_006ecba0(bool abFlag, void* apValue)
{
    m_p = apValue;
    reinterpret_cast<::FUN_0044e010_class *>(this)->FUN_0044e010(abFlag);
    return this;
}

namespace fnv_0043b640 {
struct GO
{
    GO(int);
    ~GO();
    void operator=(void*);
    void* m_pObject;
};
struct Flt
{
    operator unsigned int();
};

struct FUN_0043b640
{
    char* pFilename;
    GO pListSequence;
    GO m_spAnimGroup;
    int BackgroundTask;
    int m_iActualRefCount;
    FUN_0043b640(const char* apFilename, void* apStream);
};

// @fnv 0x0043b640
FUN_0043b640::FUN_0043b640(const char* apFilename, void* apStream)
    : pListSequence(0), m_spAnimGroup(0), BackgroundTask(0), m_iActualRefCount(0)
{
    m_spAnimGroup = 0;
    unsigned int uiLength = ::FUN_0044a670(apFilename);
    pFilename = new char[uiLength + 1];
    TaskQueueInterface::CopyStringToBuffer(pFilename, uiLength + 1, apFilename);
    ::AssignNewObjectFromValue((int)(apStream), 0, (::GO *)(::fnv_0043b640::GO *)(&pListSequence));
    if (*(Flt*)&pListSequence)
    {
        reinterpret_cast<::NamedObjectLoader *>(this)->FUN_0043b7e0(apFilename);
    }
    else
    {
        ::FUN_005b5e40();
    }
}
}  // namespace fnv_0043b640

namespace fnv_0043cb50 {
struct BGSTextureSet;
struct FileFormCollection;
struct TESFile;
struct FileEntryList
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Copy(FileEntryList*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
struct DistantTreeTextureInfo
{
    BGSTextureSet* m_pTextureSet;
    int m_iTextureSetIndex;
    char m_cTexturePath[128];
};
struct FUN_0043cb50_shell : public QueuedModel
{
    void QueueTextureFiles(FileEntryList*);
};

struct FUN_00978890_m
{
};
struct Loader_S
{
    void QueueTextureFile(BSFileEntry*, int, QueuedFile*);
};
struct BGSTextureSet
{
};
struct SwapNode_0043cb50
{
    DistantTreeTextureInfo** _ref_006815c0();
};
struct ScriptS
{
};
struct ModelV_0043cb50
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual ScriptS* GetTextureSwap();
};
struct FUN_0043ccc0_shell
{
};

// @fnv 0x0043cb50
void FUN_0043cb50_shell::QueueTextureFiles(FileEntryList* apTextureList)
{
    if (apTextureList)
    {
        unsigned int itextureCount = ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((((FUN_00978890_m*)apTextureList)))->FUN_009373f0()));
        if (itextureCount)
        {
            BSFileEntry** papFileEntries = ((::fnv_0043cb50::BSFileEntry **)(reinterpret_cast<::Callees *>((((FUN_00978890_m*)apTextureList)))->FUN_00726070()));
            for (unsigned int i = 0; i < itextureCount; i++)
            {
                if (papFileEntries[i])
                    ((Loader_S*)g_modelLoader)->QueueTextureFile(papFileEntries[i], FUN_0043cc60(), this);
            }
        }
    }
    if (*(ModelV_0043cb50**)((char*)this + 0x34))
    {
        ScriptS* ptextureSwap = (*(ModelV_0043cb50**)((char*)this + 0x34))->GetTextureSwap();
        if (ptextureSwap)
        {
            SwapNode_0043cb50* pSwapNode = ((::fnv_0043cb50::SwapNode_0043cb50 *)(reinterpret_cast<::BGSCameraPath *>((ptextureSwap))->GetConditions()));
            while (pSwapNode)
            {
                DistantTreeTextureInfo* pswap = *((::fnv_0043cb50::DistantTreeTextureInfo **)(new ((void *)(pSwapNode)) ::Vec3()));
                if (pswap && pswap->m_pTextureSet)
                    reinterpret_cast<::BGSTextureSet *>((pswap->m_pTextureSet))->LoadTextures(FUN_0043cc60(), this, false);
                pSwapNode = ((::fnv_0043cb50::SwapNode_0043cb50 *)(reinterpret_cast<::Callees *>((pSwapNode))->FUN_00726070()));
            }
        }
    }
    reinterpret_cast<::FUN_0043ccc0_shell *>((((FUN_0043ccc0_shell*)this)))->FUN_0043ccc0(true);
    vfn_28();
}
}  // namespace fnv_0043cb50

namespace fnv_0043e2a0 {
struct BSFile;
struct NiBinaryStream;
struct NiFile;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiObjectNET;
struct NiPoint2;
struct NiPoint3;
struct NiSearchPath;
struct NiTexture;
struct NiThread;
struct SaveContentDescriptor;
struct _iobuf;
struct blob16
{
    char b[16];
};
struct blob308
{
    char b[308];
};
struct FUN_0043e2a0_shell : public QueuedKF
{
    void FUN_0043e2a0();
};

struct AutoMemHelper
{
    int iSaved;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct Proc_S
{
};
struct Flt
{
    operator unsigned int();
};
struct KFModelLookup
{
    KFModel* Lookup(const char*);
};
struct FUN_0043e480_shell
{
};
struct FUN_00c3cff0_t
{
    BSFile* FUN_00c3cff0(int, int);
};
struct BSStream
{
    BSStream();
    virtual ~BSStream();
    unsigned int data[0x171];
    char name[8];
};
struct NiStream
{
    bool FUN_00c3a8a0(const char*, BSFile*);
};
struct FUN_0043b640
{
    char data[0x14];
    FUN_0043b640(void*, BSStream*);
};

// Looks up a KFModel by name; if not found, opens the file and loads it into a new KFModel, warning on failure.
// @fnv 0x0043e2a0
void FUN_0043e2a0_shell::FUN_0043e2a0()
{
    AutoMemHelper tempMemContext(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                                 0x529);
    reinterpret_cast<::NiPointer_KFModel *>((void *)&(const ::NiPointer< ::KFModel> &)(*(NiPointer<KFModel>*)((char*)this + 0x30)))->FUN_0044b070(reinterpret_cast<::KFModelLookup *>((((KFModelLookup*)g_modelLoader)))->Lookup((const char*)((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)this)))->FUN_0045cd60()))));
    if (*(Flt*)((char*)this + 0x30))
    {
        reinterpret_cast<::FUN_0043e480_shell *>((((FUN_0043e480_shell*)this)))->FUN_0043e480(true);
        return;
    }
    BSFile* pfile = ((FUN_00c3cff0_t*)this)->FUN_00c3cff0(0, 1);
    BSStream kstream;
    if (pfile && ((NiStream*)&kstream)->FUN_00c3a8a0((const char*)((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)this)))->FUN_0045cd60())), pfile))
        reinterpret_cast<::NiPointer_KFModel *>((void *)&(const ::NiPointer< ::KFModel> &)(*(NiPointer<KFModel>*)((char*)this + 0x30)))->FUN_0044b070((KFModel*)new FUN_0043b640(((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)this)))->FUN_0045cd60())), &kstream));
    else
        ::FUN_005b5e40();
}
}  // namespace fnv_0043e2a0

struct Inner5
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Holder14
{
    char _pad[0x14];
    Inner5* p;
    void ForwardToInner(int);
};
// Calls f5 on the Inner5 object stored in p, passing a through.
// @fnv 0x0043ea90
void Holder14::ForwardToInner(int aiValue)
{
    p->f5(aiValue);
}

struct VirtObj0043fb50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Standin0043fb50
{
    char _pad[0x18];
    VirtObj0043fb50* m_18;
    void DispatchToVirtual(int);
};
// Forwards the integer argument to the virtual method f5 of the object stored at m_18.
// @fnv 0x0043fb50
void Standin0043fb50::DispatchToVirtual(int aiValue)
{
    m_18->f5(aiValue);
}

namespace fnv_0043fed0 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct ReferenceIntersectionData
{
    void Endian();
    TESObjectREFR* m_pHitReference;
    char Intersect[12];
    char Normal[12];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct FUN_0043fed0_shell : public QueuedReference
{
    void FUN_0043fed0();
};

struct RefV
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
    virtual int v116();
};
struct QRV
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
};
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct DecalList
{
    bool FUN_008256d0();
    ReferenceIntersectionData** FUN_006815c0();
};
struct FUN_0041f050_shell
{
};
struct FUN_00475120_shell
{
    int GetFormType();
};
struct ScriptS
{
};
struct BGSTextureSet
{
};
struct FUN_0043cc80_shell
{
};
struct Dummy_0069b080;
bool IsFieldCZero(Dummy_0069b080*);

// @fnv 0x0043fed0
void FUN_0043fed0_shell::FUN_0043fed0()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x72a);
    DecalList* pdecallist;
    if ((*(RefV**)((char*)this + 0x28)) && reinterpret_cast<::FUN_00564e60_shell *>(((*(RefV**)((char*)this + 0x28))))->FUN_00564e60() &&
        !(*(RefV**)((char*)this + 0x28))->v116())
        ((QRV*)this)->v12();
    if ((*(RefV**)((char*)this + 0x28)))
    {
        pdecallist = ((::fnv_0043fed0::DecalList *)(reinterpret_cast<::FUN_0041f050_shell *>((((FUN_0041f050_shell*)reinterpret_cast<::FUN_005d43c0_ *>(((*(RefV**)((char*)this + 0x28))))->FUN_005d43c0())))->FUN_0041f050()));
        while (pdecallist && !pdecallist->FUN_008256d0())
        {
            ReferenceIntersectionData* pdata = *((::fnv_0043fed0::ReferenceIntersectionData **)(new ((void *)(pdecallist)) ::Vec3()));
            pdecallist = ((::fnv_0043fed0::DecalList *)(reinterpret_cast<::Callees *>((pdecallist))->FUN_00726070()));
            if (pdata->m_pHitReference && ((::fnv_0043fed0::FUN_00475120_shell *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((ScriptS*)pdata->m_pHitReference)))->FUN_007af430()))->GetFormType() == 4)
            {
                BGSTextureSet* ptexset = (BGSTextureSet*)((::fnv_0043fed0::FUN_00475120_shell *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((ScriptS*)pdata->m_pHitReference)))->FUN_007af430()));
                reinterpret_cast<::BGSTextureSet *>((ptexset))->LoadTextures(reinterpret_cast<::FUN_0043cc80_shell *>((((FUN_0043cc80_shell*)this)))->FUN_0043cc80(), (::QueuedFile *)(void *)(this), false);
            }
        }
    }
    ((QRV*)this)->v11();
    if (::IsFieldCZero((::Dummy_0069b080 *)(::fnv_0043fed0::Dummy_0069b080 *)((Dummy_0069b080*)this)))
        ::SetFieldCToFive((char*)this);
    ((QRV*)this)->v10();
}
}  // namespace fnv_0043fed0

namespace fnv_00440050 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct FUN_00440050_shell : public QueuedReference
{
    void FUN_00440050();
};

class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
    int iOld;
};

struct Flt
{
    operator unsigned int();
};

struct TESModelV
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual char* GetModelFileName();
};

struct FUN_00571630_shell
{
};
struct FUN_007af430_shell
{
};
struct FUN_00444dc0_shell
{
    void QueueModelForObject(void*, void*, int, void*, void*);
};
struct FUN_004472a0_shell
{
};
struct FUN_00477640_shell
{
};

// Loads the model via g_modelLoader, resolves the model file name, and runs the destructor task if present.
// @fnv 0x00440050
void FUN_00440050_shell::FUN_00440050()
{
    TESModelV* ptesModel;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x752);
    void* pobj = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((FUN_007af430_shell*)*(void**)((char*)this + 0x28))))->FUN_007af430()));
    ptesModel = ((::fnv_00440050::TESModelV *)(reinterpret_cast<::TESObjectREFR *>((((FUN_00571630_shell*)*(void**)((char*)this + 0x28))))->GetTESModel()));
    if (!ptesModel || !*ptesModel->GetModelFileName())
        return;
    ((FUN_00444dc0_shell*)g_modelLoader)
        ->QueueModelForObject(pobj, (char*)this + 0x2c, ((IOTask*)this)->FUN_0043cc60(), this,
                              *(void**)((char*)this + 0x28));
    if (!*(Flt*)((char*)this + 0x2c))
        reinterpret_cast<::FUN_004472a0_shell *>((((FUN_004472a0_shell*)g_modelLoader)))->FUN_004472a0(ptesModel->GetModelFileName(), (char*)this + 0x30);
    FUN_00477640_shell* pdestruct = ((::fnv_00440050::FUN_00477640_shell *)(::FUN_00475400(pobj)));
    if (pdestruct)
        reinterpret_cast<::BGSDestructibleObjectForm *>((pdestruct))->QueueResourceLoad((::TESBoundObject *)(pobj), (::IO_TASK_PRIORITY)(((IOTask*)this)->FUN_0043cc60()), (::QueuedFile *)(void *)(this));
}
}  // namespace fnv_00440050

struct IOManagerHack
{
};
struct IOTaskHack
{
    void FUN_00440660(int a1);
};
// Forwards this task and a1 to the IOManager at DAT_01202d98 via FUN_00c3df40.
// @fnv 0x00440660
void IOTaskHack::FUN_00440660(int a1)
{
    reinterpret_cast<::FUN_00c3df40_Class *>((((IOManagerHack*)::DAT_01202d98)))->FUN_00c3df40((::FUN_00c3df40_Param1 *)(void *)(this), a1);
}

namespace fnv_00440780 {
struct FUN_00440780_shell : public QueuedReference
{
    void FUN_00440780();
};

struct TESObjectCELL;
struct TES
{
};
struct Flt
{
    operator unsigned int();
};
struct CtlV
{
};
struct SetterHelper
{
};
struct ActorS
{
};
struct NiAVObject;
struct RefA
{
};
struct FUN_004408d0_S
{
};
struct VRef_00440780
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual bool v136();
    virtual bool v137();
};
// @fnv 0x00440780
void FUN_00440780_shell::FUN_00440780()
{
    if (::FUN_00449110((int*)this) && reinterpret_cast<::FUN_0043caa0_shell *>((((IOTask*)this)))->FUN_0043caa0() && !::FUN_00449130((int*)this))
    {
        if (*(Flt*)((char*)this + 0x2c) && !*(Flt*)((char*)this + 0x30))
            reinterpret_cast<::NP_0044aed0 *>((((SetterHelper*)((char*)this + 0x30))))->FUN_0044aed0((::WaitableObject *)(void *)(((::fnv_00440780::CtlV *)(::fnv_004a8a90::FUN_004a8a90((char *)(((CtlV*)(unsigned int)*(Flt*)((char*)this + 0x2c))))))));
        bool bbackgroundClone = false;
        if (*(Flt*)((char*)this + 0x30) && *(TESObjectREFR**)((char*)this + 0x28) != (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)) &&
            reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_00440780::TES * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(::fnv_00440780::TESObjectCELL *)(((::fnv_00440780::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((((ActorS*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget()))), false) &&
            reinterpret_cast<::TES *>(((*reinterpret_cast<::fnv_00440780::TES * *>(&::g_TES))))->IsRefUsable(*(TESObjectREFR**)((char*)this + 0x28)) &&
            !((::fnv_00440780::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((RefA*)*(TESObjectREFR**)((char*)this + 0x28))))->FUN_0043fcd0())))
            bbackgroundClone = true;
        if ((*(VRef_00440780**)((char*)this + 0x28))->v137() || (*(VRef_00440780**)((char*)this + 0x28))->v136())
            bbackgroundClone = false;
        if (bbackgroundClone)
            reinterpret_cast<::FUN_004408d0_S *>((((FUN_004408d0_S*)g_modelLoader)))->ForwardToBCT((::QR2 *)(void *)(this));
        else
            reinterpret_cast<::IOManager *>((((IOTask*)this)))->SubmitTask();
    }
}
}  // namespace fnv_00440780

namespace fnv_00440a90 {
struct FUN_00440a90_shell : public QueuedReference
{
    bool FUN_00440a90();
};

class TESObjectCELL;
class NiAVObject;
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct TES
{
};
struct ActorS
{
};
struct RefA
{
};
struct SeqObj
{
};
struct Flt
{
    operator unsigned int();
};
struct GO
{
    void* p;
    void operator=(void*);
};
struct VRef
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
    virtual void* Get3DObject(bool);
};
struct QRView
{
    char pad[0x18];
    int iMemCtx;
    char pad2[0xc];
    TESObjectREFR* pRef;
    char pad3[8];
    GO spClone;
};
// @fnv 0x00440a90
bool FUN_00440a90_shell::FUN_00440a90()
{
    bool bresult = false;
    AutoMemHelper tempMemContext(((QRView*)this)->iMemCtx, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x7ea);
    if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_00440a90::TES * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(::fnv_00440a90::TESObjectCELL *)(((::fnv_00440a90::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((((ActorS*)((QRView*)this)->pRef)))->GetTarget()))), false))
    {
        if (reinterpret_cast<::TES *>(((*reinterpret_cast<::fnv_00440a90::TES * *>(&::g_TES))))->IsRefUsable(((QRView*)this)->pRef))
        {
            if (!((::fnv_00440a90::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((RefA*)((QRView*)this)->pRef)))->FUN_0043fcd0())))
            {
                ((QRView*)this)->spClone = ((VRef*)((QRView*)this)->pRef)->Get3DObject(true);
                if (*(Flt*)&((QRView*)this)->spClone)
                    reinterpret_cast<::WaitableObject *>((((SeqObj*)(unsigned int)*(Flt*)&((QRView*)this)->spClone)))->FUN_00401970();
            }
        }
        bresult = true;
    }
    return bresult;
}
}  // namespace fnv_00440a90

namespace fnv_00440ba0 {
struct FUN_00440ba0_shell : public QueuedReference
{
    void FUN_00440ba0();
};

struct AutoMemHelper
{
    int m;
    AutoMemHelper(int id, bool b, const char* file, int line);
    ~AutoMemHelper();
};
struct RefH
{
};
struct TESObjectCELL
{
};
struct BSOcclusionPlane
{
};
struct TES
{
};
struct Flt
{
    operator unsigned int();
};
class BSFaceGenModel;
class BSFaceGenModelExtraData
{
  public:
    BSFaceGenModel* GetModelFilePath();
};
struct FUN_004409e0_shell
{
};
struct FUN_00572350_shell
{
};

// Processes a queued reference: skips deleted/disabled refs, updates the model loader and cell reference lock, then releases the cell lock.
// @fnv 0x00440ba0
void FUN_00440ba0_shell::FUN_00440ba0()
{
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x804);
    if (::FUN_00449130((int*)this))
        return;
    bool bdisabled = false;
    bdisabled = reinterpret_cast<::TESForm *>((((RefH*)*(TESObjectREFR**)((char*)this + 0x28))))->GetDisabled() ||
                reinterpret_cast<::FUN_00440d80_shell *>((void *)(((RefH*)*(TESObjectREFR**)((char*)this + 0x28))))->FUN_00440d80();
    if (((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget())))
        reinterpret_cast<::TESObjectCELL *>((((TESObjectCELL*)((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget())))))->CellRefLockEnter();
    if (!bdisabled &&
        reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_00440ba0::TES * *>(&::g_TES))))->IsCellBuffered(
            (::TESObjectCELL *)(::fnv_00440ba0::TESObjectCELL *)((TESObjectCELL*)((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget()))), false))
    {
        if ((unsigned int)*(Flt*)((char*)this + 0x30))
            g_modelLoader->UpdateReferenceNode(
                *(TESObjectREFR**)((char*)this + 0x28),
                (NiNode*)((BSFaceGenModelExtraData*)(unsigned int)*(Flt*)((char*)this + 0x30))->GetModelFilePath());
        reinterpret_cast<::AttachmentHandler *>(((*reinterpret_cast<::fnv_00440ba0::TES * *>(&::g_TES))))->FUN_00451ef0(
            (::AttachRef *)(*(TESObjectREFR**)((char*)this + 0x28)),
            (::AttachCell *)(::fnv_00440ba0::TESObjectCELL *)((TESObjectCELL*)((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget()))), (::AttachRef *)(void *)(this), false);
    }
    reinterpret_cast<::FUN_004409e0_shell *>((((FUN_004409e0_shell*)g_modelLoader)))->FUN_004409e0(*(TESObjectREFR**)((char*)this + 0x28));
    if (((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget())))
    {
        ::FinishScriptRunLockAndReset(
            (char*)((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget())));
        if (reinterpret_cast<::FUN_00572350_shell *>((((FUN_00572350_shell*)*(TESObjectREFR**)((char*)this + 0x28))))->FUN_00572350())
            ::FinishScriptRun((char*)((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget())));
        ::FUN_00541ae0((char *)(((TESObjectCELL*)((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)*(TESObjectREFR**)((char*)this + 0x28))))->GetTarget())))));
    }
}
}  // namespace fnv_00440ba0

namespace fnv_004412e0 {
struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct TESObjectREFR_GetFlags_Helper
{
};
struct FUN_006a7ad0_shell
{
};
struct DismembermentPart
{
    int unk0;
    BSSimpleArray<unsigned int, 1024> parts;
};
struct ExtraDismemberedLimbs
{
    char pad[0x20];
    BSSimpleArray<unsigned int, 1024> limbs;
    DismembermentPart* GetInfoAt(unsigned int);
};
struct ExtraDataList
{
};
struct Actor
{
};
struct QueuedActor;
struct FUN_00444d40_shell
{
    void FUN_00444d40(unsigned int, IO_TASK_PRIORITY, QueuedActor*, Actor*);
};
struct QueuedActor
{
    void QueueDismemberedLimbLoads();
};

// Queues model-loader tasks for each dismembered limb part of the actor's extra data, then calls FUN_00440050.
// @fnv 0x004412e0
void QueuedActor::QueueDismemberedLimbLoads()
{
    ExtraDismemberedLimbs* pextraLimbs;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8a2);
    Actor* pactor = *(Actor**)((char*)this + 0x28);
    reinterpret_cast<::Actor *>((pactor))->AddDefaultSpells();
    pextraLimbs = ((::fnv_004412e0::ExtraDismemberedLimbs *)(reinterpret_cast<::ExtraDataList *>((((::fnv_004412e0::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(((TESObjectREFR*)pactor))->FUN_005d43c0()))))->GetDismemberedLimbs()));
    if (pextraLimbs)
    {
        IO_TASK_PRIORITY epriority = ((IOTask*)this)->FUN_0043cc60();
        for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_Helper*)&pextraLimbs->limbs)))->GetName())); i++)
        {
            DismembermentPart* pdismemberedLimb = pextraLimbs->GetInfoAt(i);
            for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_Helper*)&pdismemberedLimb->parts)))->GetName()));
                 j++)
            {
                unsigned int uiBoundObject = ((unsigned int)(reinterpret_cast<::S3e60 *>((((FUN_006a7ad0_shell*)&pdismemberedLimb->parts)))->FUN_006a7ad0(j)));
                ((FUN_00444d40_shell*)g_modelLoader)
                    ->FUN_00444d40(uiBoundObject, epriority, this, *(Actor**)((char*)this + 0x28));
            }
        }
    }
    reinterpret_cast<::fnv_00440050::FUN_00440050_shell *>(this)->FUN_00440050();
}
}  // namespace fnv_004412e0

namespace fnv_00441560 {
struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnimObject;
struct BSFaceGenModel;
struct BSShaderPPLightingProperty;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct InventoryChanges;
struct MagicItemForm;
struct PackageList;
struct TESActorBase;
struct TESAmmo;
struct TESFaction;
struct TESFile;
struct TESLevItem;
struct TESNPC;
struct TESObjectLIGH;
struct TESRace;
struct BipedAnim
{
    void InitRoot(NiNode*);
    NiNode* GetRoot();
    void RemoveClothingAndArmor();
    void CompleteModelLoadTask();
    static void SetNodeTranslation(NiAVObject*);
    void RemovePart(TESForm*);
    void RemovePart(int, bool, int);
    void RemovePart(BipedAnimObject*, bool, int);
    void RecursivelyRemoveAllDecalPlacementVectorDataFromWeaponBone(NiAVObject*);
    NiNode* GetBoneNode(int);
    TESForm* GetParent(int);
    TESForm* FindPart(NiAVObject*);
    bool FindObject(TESForm*);
    BipedAnimObject* FindBipObject(TESForm*);
    BipedAnimObject* GetBipObject(int);
    void UpdateRaceSex(TESRace*, int);
    void SetBipedObject(TESForm*, TESModel*, int);
    void SetBipedVisibility(bool);
    void ProcessQueuedHelmet(int, void*, QueuedFile*);
    void QueueBipedObjectLoads(unsigned int, int, QueuedFile*);
    void LoadBipedObject(TESNPC*, int, int, QueuedFile*);
    BipedAnimObject* QBufferedObjects();
    void AddBipedWeapon(TESObjectWEAP*, unsigned char);
    void UpdateBipedWeapon(TESObjectWEAP*, unsigned char);
    void RemoveBipedWeapon();
    TESObjectWEAP* GetBipedWeapon();
    void AddWeaponOffset(float);
    static void RecursiveWeaponOffset(NiNode*, float);
    void SetBipedAmmo(TESAmmo*);
    void AttachBipedAmmo(TESAmmo*);
    void RemoveBipedAmmo();
    void AttachBipedShield(TESObjectARMO*);
    void RemoveBipedShield();
    void AttachBipedRing(TESObjectCLOT*, bool);
    void RemoveBipedRing(bool);
    void AttachBipedAmulet(TESObjectCLOT*);
    void RemoveBipedAmulet();
    void SetBipedTorch(TESObjectLIGH*);
    void AttachBipedTorch(TESObjectLIGH*);
    void RemoveBipedTorch();
    TESObjectLIGH* GetBipedTorch();
    NiNode* GetBipedTorchClone();
    BSFaceGenModel* GetFaceGenModelForSlot(int);
    void CanLoadHiddenBipedObjects(int, QueuedFile*, void*, int);
    void CanLoadHiddenBipedObjects(int, QueuedFile*, int);
    NiNode* GetFaceGenNode(BSFaceGenModel*, NiNode*, int);
    void SetFaceGenNode(BSFaceGenModel*, NiNode*, int);
    static void AttachObjectToNode(NiNode*, NiAVObject*, NiNode*, bool);
    static void AttachFaceGenNode(NiNode*, NiNode*, NiNode*, BipedAnim*, int, BSFaceGenModel*);
    static NiAVObject* LoadFormModel(TESForm*, TESModel*, int, TESObjectREFR*, NiAVObject*);
    static void ApplyReferenceExtraData(NiNode*, NiNode*, int, TESObjectREFR*);
    TESObjectREFR* GetRequester();
    bool IsSlotHidden(int);
    static BSShaderPPLightingProperty* FindLightingShaderProperty(NiAVObject*);
    static int GetBipedObjectFromShaderProperty(NiAVObject*, BSShaderPPLightingProperty*);
    static unsigned int GetSkinModelFlags(NiAVObject*);
    NiAVObject* PrepareBipedModel(NiNode*, int, bool, bool, BSFaceGenModel*);
    NiAVObject* AttachBipedModel(NiNode*, NiNode*, int, bool, bool, BSFaceGenModel*);
    void UpdateSkinInstance(NiAVObject*, bool);
    bool GetSlotHidden(int);
    bool IsModelPathMatch(TESModel*, char*);
    TESModel* Store1stPersonModel(int, char*);
    TESModel* GetModelForSlot(int, TESModel*);
    void* __vecDelDtor(unsigned int);
    NiNode* root;
    char bone[40];
    char object[320];
    char m_kPreviousObjects[320];
    float m_fFadeAlpha;
    TESObjectREFR* m_pActor;
};
struct TESActorBaseData : public BaseFormComponent
{
    virtual void CopyFromTemplateForm(TESActorBase*);
    virtual bool GetVATSmeleeDisabled();
    virtual bool GetNoVATSranged();
    virtual bool GetCanBePickpocketed();
    virtual bool GetIsGhost();
    virtual bool GetIsInvulnerable();
    virtual bool GetNoKnockdowns();
    virtual bool GetCanBeAllRaces();
    virtual bool GetNoHeadTracking();
    virtual bool GetNoPersuasion();
    virtual bool GetNoLeftArm();
    virtual bool GetNoRightArm();
    virtual bool GetNoHead();
    virtual bool GetNoShadow();
    virtual bool GetNoBloodSpray();
    virtual void SetNoBloodSpray(bool);
    virtual bool GetNoBloodDecal();
    virtual void SetNoBloodDecal(bool);
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool);
    void SetTemplateUseFlag(int, bool);
    bool GetTemplateUseFlag(int);
    TESForm* QTemplateForm();
    void SetTemplateForm(TESForm*);
    unsigned short QTemplateUseFlags();
    void SetTemplateUseFlags(unsigned short);
    bool GetUsesLeveledTemplate();
    bool IsTemplateLeveled();
    void SetTemplateReference(TESObjectREFR*);
    static TESActorBase* GetTemplateForActorBase(TESActorBase*, TESActorBase*);
    static bool HasCircularTemplateHierarchy(TESActorBase*);
    static bool IsActorBaseInTemplateHierarchy(TESActorBase*, TESActorBase*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short*);
    int* GetFlags();
    void SetFlags(int);
    bool GetFlagBit(int);
    void UpdateFlagBit(int, bool, bool);
    bool IsEssentialActor();
    void SetEssential(bool);
    bool GetRespawn();
    void SetRespawn(bool);
    bool GetRunsInLow();
    void UpdateRunsInLow(bool, bool);
    bool GetKnockedDowns();
    void SetKnockedDowns(bool);
    bool GetNotPushable();
    void SetNotPushable(bool);
    bool GetNoRotatingToHeadtrack();
    void SetNoRotatingToHeadtrack(bool);
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool);
    bool GetSummonable();
    void SetSummonable(bool);
    bool GetNoRumors();
    void SetNoRumors(bool);
    void SetNoVATSMelee(bool);
    void SetAllowPCDialogue(bool);
    void SetAllowPickPocket(bool);
    void SetIsGhost(bool);
    void SetInvulnerable(bool);
    void SetCantOpenDoors(bool);
    void SetCanBeAllRaces(bool);
    void SetAutoCalcServiceFlags(bool);
    unsigned short GetLevelExact();
    unsigned short GetLevel();
    void SetLevel(unsigned short);
    unsigned short GetCalcLevelMin();
    void SetCalcLevelMin(unsigned short);
    unsigned short GetCalcLevelMax();
    void SetCalcLevelMax(unsigned short);
    unsigned short GetBaseDisposition();
    void SetBaseDisposition(unsigned short);
    TESLevItem* GetDeathItem();
    void SetDeathItem(TESLevItem*);
    void SetFatigue(unsigned short);
    static int ConvertToInteger(float);
    static char* GetActorDisplayName(Actor*);
    void SetKarmaValue(float);
    void ModKarma(float);
    unsigned short GetBarterGold();
    void SetBarterGold(unsigned short);
    int GetFactionReaction(TESActorBase*, int*);
    int GetFactionRank(TESFaction*, bool);
    void SetFactionRank(TESFaction*, char);
    void ModFactionRank(TESFaction*, char, bool);
    bool GetGhostFlag();
    bool CanBeDetected();
    void* GetFactionList();
    unsigned short GetSpeedMult();
    void SetSpeedMult(unsigned short);
    void SetVoiceType(BGSVoiceType*);
    void AddFormChange(int);
    void RemoveFormChange(int);
    void AddFormChangeFlags(int);
    void ClearChangeFlags(int);
    int GetChangeFlags();
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void SetPCFactionFlags(int);
    bool HasFaction(TESFaction*);
    void RemoveAllFactions();
    void CopyFactionList(TESActorBaseData*);
    void* __vecDelDtor(unsigned int);
    char actorData[24];
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    char m_pVoiceType[8];
};
struct TESContainer : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void ClearObjects();
    InventoryItemEntry* AddObject(ContainerChanges*);
    InventoryItemEntry* AddObject(TESObject*, int, ContainerItemExtra*);
    void AddDuplicateObject(InventoryItemEntry*);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry*);
    void ReplaceObject(TESObject*, TESObject*);
    bool HasObjectOfType(TESObject*);
    float GetContainerWeight(bool);
    int GetObjectCount(TESObject*);
    char Compare(InventoryItemEntry*, InventoryItemEntry*);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char);
    static bool IsValidContainerObject(TESObject*);
    void MergeContainer(TESContainer*);
    void MultiplyContainerCounts(int);
    void SetClothingModifier(float);
    void AddContentsFromReference(TESObjectREFR*, bool);
    void AddInventoryChangesToContainer(int, InventoryChanges*);
    TESAmmo* GetBestAmmoForActor(TESActorBase*);
    TESObjectWEAP* GetBestWeapon(TESActorBase*);
    TESObjectARMO* FindBestArmor(TESActorBase*, int);
    TESObjectCLOT* GetBestClothing(TESActorBase*, int);
    TESBoundObject* GetInventoryEntryData(int);
    void* GetObjectList();
    void* GetObjectListEnd();
    void* __vecDelDtor(unsigned int);
    char objectList[8];
};
struct BGSTouchSpellForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static MagicItemForm* GetFormTouchSpell(TESForm*);
    MagicItemForm* GetFormTouchSpell();
    void SetFormTouchSpell(MagicItemForm*);
    static unsigned short GetFormTouchSpellAnimation(TESForm*);
    unsigned short GetFormTouchSpellAnimation();
    void SetFormTouchSpellAnimation(unsigned short);
    MagicItemForm* m_pMagicItem;
    unsigned short m_usTouchSpellType;
    char _pad_a[2];
};
struct TESAIForm : public BaseFormComponent
{
    virtual unsigned short GetSaveSize(unsigned int);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void CopyAISettings(TESAIForm*);
    void CopyAIPackageList(TESAIForm*);
    unsigned char GetAggression();
    void SetAggression(unsigned char, bool);
    unsigned char GetAssistance();
    void SetAssistance(unsigned char);
    static float GetConfidenceLevel(unsigned char);
    float GetConfidenceLevel();
    unsigned char GetConfidence();
    void SetConfidence(unsigned char, bool);
    unsigned char GetEnergy();
    void SetEnergy(unsigned char, bool);
    unsigned char GetResponsibility();
    void SetResponsibility(unsigned char, bool);
    unsigned char GetMood();
    void SetAIMood(unsigned char);
    unsigned int GetServiceFlags();
    void SetServiceFlags(unsigned int, bool);
    bool GetOffersService(unsigned int);
    void SetOffersService(unsigned int, bool);
    int GetTrainingSkill();
    void SetTrainingSkill(int);
    unsigned char GetTrainingSkillLevel();
    void SetTrainingSkillLevel(unsigned char);
    void SetAIData(PackedRecordData*);
    bool IsObjectUsable(TESObject*);
    bool HasAnAggroRadius();
    void SetHasAggroRadius(bool);
    unsigned int GetAggroRadius();
    void SetAggroRadius(unsigned int);
    bool HasPackage(TESPackage*);
    void AddPackage(TESPackage*);
    bool MovePackage(TESPackage*, bool);
    void InsertPackageAt(TESPackage*, TESPackage*, bool);
    void DeletePackage(TESPackage*);
    static TESPackage* GetCurrentPackage(Actor*);
    static void FindAvailablePackages(Actor*, void*, float, float);
    void AddFormChange(int);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    PackageList* GetPackageList();
    void* __vecDelDtor(unsigned int);
    char m_kAIData[20];
    char m_kPackageList[8];
};
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Save(void*);
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
struct TESAnimation : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    bool IsKFFileInList(char*);
    void AddKFFile(char*);
    bool HasSpecialAnimations();
    void* GetKFFileList();
    void Save(int);
    void LoadAnimationChunk(TESAnimation*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void* __vecDelDtor(unsigned int);
    char m_kKFFileList[8];
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct TESRaceForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESRace* GetFormRace(TESForm*);
    TESRace* GetFormRace();
    static char* GetFormRaceEditorID(TESForm*);
    char* GetFormRaceEditorID();
    void SetFormRace(TESRace*);
    TESRace* m_pRace;
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct FUN_00441560_shell : public QueuedCharacter
{
    void LoadBipedModel();
};

struct AutoMemHelper
{
    int iData;
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};
struct TESNPC
{
};
struct TESModel;
struct N_008c48d0
{
};
struct FUN_006055f0_shell
{
};
struct FUN_004abd30_shell
{
};
struct FUN_00444fe0_shell
{
};
struct FUN_00445a10_shell
{
    void QueueModelAnimations(TESModel*, int, void*, TESObjectREFR*, int, int);
};
struct FUN_004412e0_shell
{
};
struct RefVtbl
{

    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual BipedAnim* GetBipedAnim();
};

// Loads the queued character's biped anim and NPC model via the model loader, then finishes the task.
// @fnv 0x00441560
void FUN_00441560_shell::LoadBipedModel()
{
    BipedAnim* pbipedAnim;
    TESNPC* pnpc;
    TESModel* pmodel;
    AutoMemHelper tempMemContext(*(int*)((char*)this + 0x18), true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8ca);
    pnpc = (TESNPC*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*(N_008c48d0**)((char*)this + 0x28))))->FUN_007af430()));
    pbipedAnim = (*(RefVtbl**)((char*)this + 0x28))->GetBipedAnim();
    if (!pbipedAnim)
    {
        pbipedAnim = ((::fnv_00441560::BipedAnim *)(reinterpret_cast<::FUN_006055f0_shell *>((((FUN_006055f0_shell*)pnpc)))->GetOrCreateBipedAnim(*(TESObjectREFR**)((char*)this + 0x28))));
    }
    if (pbipedAnim)
    {
        reinterpret_cast<::TESNPC *>((pnpc))->RebuildHeadModel(*(TESObjectREFR**)((char*)this + 0x28), (::BipedAnim *)(pbipedAnim), 0);
        reinterpret_cast<::BipedAnim *>((((FUN_004abd30_shell*)pbipedAnim)))->FUN_004abd30((::IO_TASK_PRIORITY)(((IOTask*)this)->FUN_0043cc60()), (*(::NiPointer< ::QueuedHelmet> *)((char*)this + 0x44)), (::QueuedFile *)(void *)(this));
        reinterpret_cast<::FUN_00444fe0_shell *>((((FUN_00444fe0_shell*)g_modelLoader)))->FUN_00444fe0((::TESNPC *)(pnpc), (char*)this + 0x40, ((IOTask*)this)->FUN_0043cc60(), (QueuedFile*)this);
    }
    pmodel = pnpc ? (TESModel*)((char*)pnpc + 0xdc) : 0;
    ((FUN_00445a10_shell*)g_modelLoader)
        ->QueueModelAnimations(pmodel, ((IOTask*)this)->FUN_0043cc60(), this, *(TESObjectREFR**)((char*)this + 0x28), 0,
                               0);
    reinterpret_cast<::fnv_004412e0::QueuedActor *>((((FUN_004412e0_shell*)this)))->QueueDismemberedLimbLoads();
}
}  // namespace fnv_00441560

namespace fnv_00441e40 {
struct BSFile;
struct BSFileEntry;
struct LoadedFile;
struct NiBinaryStream;
struct NiFile;
struct SaveContentDescriptor;
struct _iobuf;
struct blob16
{
    char b[16];
};
struct blob308
{
    char b[308];
};
struct QueuedFileEntry : public QueuedFile
{
    virtual void __vslot_0();
    virtual unsigned char GetFileIndex();
    virtual void GenerateKey();
    char* GetFileName();
    void SetFileName(char*);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry*);
    void LookupFileEntry(int);
    BSFile* GetFile(int, int);
    void GetLookupFileName(int, char*);
    bool GetDescription(char*, unsigned int, char*);
    char _pad_4[0x14];
    int unk18;
    char pad1c[0xc];
    char* pFileName;
    BSFileEntry* m_pFileEntry;
};
struct QueuedFileLoad : public QueuedFileEntry
{
    virtual void __vslot_0();
    virtual void DispatchToManager();
    virtual void Run();
    virtual void Finish();
    LoadedFile* GetLoadedFile();
    virtual unsigned char GetFileIndex();
    char m_pLoadedFile[4];
    int m_iLoadPriority;
};
struct QueuedFaceGenFile : public QueuedFileLoad
{
    virtual void __vslot_0();
    char m_kObject[4];
    char m_pMesh[4];
};
struct FUN_00441e40_shell : public QueuedFileLoad
{
    void FUN_00441e40();
};

struct AutoMemHelper
{
    int iSaved;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct Proc_S
{
};
struct Flt
{
    operator unsigned int();
};
struct FUN_004483a0_t
{
    LoadedFile* GetHolderValue(void*);
};
struct FUN_00c3cff0_t
{
    BSFile* FUN_00c3cff0(int, int);
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_0043baf0 : BSFadeNode
{
    char data[0x10];
    FUN_0043baf0(void*, BSFile*);
};

// Loads the next queued file via the model loader; if none, opens the file by index and creates a FUN_0043baf0, otherwise warns.
// @fnv 0x00441e40
void FUN_00441e40_shell::FUN_00441e40()
{
    BSFile* pfile;
    AutoMemHelper tempMemContext(this->unk18, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x976);
    reinterpret_cast<::NiPointer_LoadedFile *>((void *)&(const ::NiPointer< ::fnv_00441e40::LoadedFile> &)(*(NiPointer<LoadedFile>*)m_pLoadedFile))->FUN_0044b220((::LoadedFile *)(::fnv_00441e40::LoadedFile *)(((FUN_004483a0_t*)g_modelLoader)->GetHolderValue(((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)this)))->FUN_0045cd60())))));
    if (*(Flt*)m_pLoadedFile)
        return;
    pfile = ((FUN_00c3cff0_t*)this)->FUN_00c3cff0(::FUN_00449050(m_iLoadPriority), 0xffff);
    if (pfile)
        reinterpret_cast<::NiPointer_LoadedFile *>((void *)&(const ::NiPointer< ::fnv_00441e40::LoadedFile> &)(*(NiPointer<LoadedFile>*)m_pLoadedFile))->FUN_0044b220((::LoadedFile *)(::fnv_00441e40::LoadedFile *)((LoadedFile*)new FUN_0043baf0(((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)this)))->FUN_0045cd60())), pfile)));
    else
        ::FUN_005b5e40();
}
}  // namespace fnv_00441e40

namespace fnv_00442350 {
int __cdecl FinishScriptRunLock(void*);
struct Interface
{
};
struct FUN_00442510_Cl;
struct FUN_00449190_cls
{
};
struct QHeadPtr
{
    void* p;
    QHeadPtr(int);
    ~QHeadPtr();
};
struct Q449
{
};
struct Flt
{
    operator unsigned int();
};
struct VTask
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
    virtual bool NeedsPostProcess();
};
struct BackgroundCloneThread
{
    char pad[0x30];
    bool m_bThirdThreadFlag;
    char pad2[7];
    Q449* m_pCloneQueue;
    void RunBackgroundClone();
};
// @fnv 0x00442350
void BackgroundCloneThread::RunBackgroundClone()
{
    while (m_bThirdThreadFlag != true)
    {
        ::FUN_004424c0((char*)this);
        ::FUN_0040b460((unsigned int *)(void *)((char*)this + 0x34));
        QHeadPtr spqueuedReference(0);
        reinterpret_cast<::Q449 *>((m_pCloneQueue))->FUN_00449280(&spqueuedReference);
        if (*(Flt*)&spqueuedReference)
        {
            while (*(Flt*)&spqueuedReference)
            {
                ::FUN_00442510((::FUN_00442510_Cl *)(::fnv_00442350::FUN_00442510_Cl *)((FUN_00442510_Cl*)this));
                ::FUN_0040fbe0();
                QueuedReference* pqueuedRef = (QueuedReference*)(unsigned int)*(Flt*)&spqueuedReference;
                int estate = reinterpret_cast<::FUN_0084e3a0_Class *>((pqueuedRef))->FUN_0084e3a0();
                if (!::FUN_00449130((int*)pqueuedRef) && reinterpret_cast<::FUN_00449190_cls *>((((FUN_00449190_cls*)pqueuedRef)))->SetState(estate, 3))
                {
                    if (((VTask*)pqueuedRef)->NeedsPostProcess())
                        reinterpret_cast<::IOManager *>((((IOTask*)pqueuedRef)))->SubmitTask();
                    reinterpret_cast<::FUN_00449190_cls *>((((FUN_00449190_cls*)pqueuedRef)))->SetState(3, 5);
                }
                reinterpret_cast<::Q449 *>((m_pCloneQueue))->FUN_00449280(&spqueuedReference);
                ::FUN_0040fbe0();
                ::SignalAtOffset18((char*)this);
            }
        }
        else
        {
            ::FUN_00442510((::FUN_00442510_Cl *)(::fnv_00442350::FUN_00442510_Cl *)((FUN_00442510_Cl*)this));
            ::SignalAtOffset18((char*)this);
        }
        ::WaitForSingleObjectEx((long *)(void *)((char*)this + 0x34));
    }
}
}  // namespace fnv_00442350

namespace fnv_00443540 {
struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
struct BSFileEntry : public FileNameHash
{
    unsigned int Size();
    unsigned int Offset();
    void SetOffset(unsigned int);
    void SetSize(unsigned int);
    bool GetSecondaryArchiveFlag();
    bool GetCheckedFileFlag();
    bool GetCompressionFlag();
    void SetSecondaryArchiveFlag(bool);
    void SetCheckedFileFlag(bool);
    void SetCompressionFlag(bool);
    void Endian();
    void SetFileDataOffset(unsigned int);
    unsigned int iSize;
    unsigned int iOffset;
};
struct FUN_00443540_shell : public ModelLoader
{
    bool FUN_00443540(BSFileEntry*, int, QueuedFile*);
};

struct QHeadPtr
{
    ~QHeadPtr();
    void* m_pObject;
};
struct Flt : QHeadPtr
{
    operator unsigned int();
};
struct QueueObj : Flt
{
    QueueObj(int);
};
struct S_00448f80
{
};
struct S_0084e3a0
{
};
struct FUN_00449190_cls
{
};
struct FUN_0043c3d0_shell
{
};
struct MLa
{
};
struct Q_0043c050
{
};
struct S_00c3c7e0
{
};
struct S_0044adb0
{
    void FUN_0044adb0();
};
struct V_00443540
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetPriority(int);
};

// @fnv 0x00443540
bool FUN_00443540_shell::FUN_00443540(BSFileEntry* apTextureFileEntry, int aePriority, QueuedFile* apParent)
{
    QueueObj spexistingQueuedTexture(((int)(reinterpret_cast<::fnv_00448f80::Holder *>((((S_00448f80*)this)))->FUN_00448f80(apTextureFileEntry))));
    if (spexistingQueuedTexture)
    {
        int estate = reinterpret_cast<::FUN_0084e3a0_Class *>((((S_0084e3a0*)(unsigned int)spexistingQueuedTexture)))->FUN_0084e3a0();
        if (estate < 3 && reinterpret_cast<::FUN_00449190_cls *>((((FUN_00449190_cls*)(unsigned int)spexistingQueuedTexture)))->SetState(estate, 2))
        {
            if (reinterpret_cast<::FUN_0043c3d0_shell *>((((FUN_0043c3d0_shell*)(unsigned int)spexistingQueuedTexture)))->FUN_0043c3d0() &&
                !reinterpret_cast<::FUN_0043c130_shell *>((((MLa*)this)))->IsLoadTexturesDegraded())
                reinterpret_cast<::FUN_0043c0d0_class *>((((Q_0043c050*)(unsigned int)spexistingQueuedTexture)))->ForwardByteToMember(false);
            if (apParent)
                reinterpret_cast<::IOTask *>((((S_00c3c7e0*)(unsigned int)spexistingQueuedTexture)))->FUN_00c3c7e0((::RefObj *)(apParent));
            if (reinterpret_cast<::FUN_00449190_cls *>((((FUN_00449190_cls*)(unsigned int)spexistingQueuedTexture)))->SetState(2, estate))
            {
                if (((IOTask*)(unsigned int)spexistingQueuedTexture)->FUN_0043cc60() > aePriority)
                    ((V_00443540*)(unsigned int)spexistingQueuedTexture)->SetPriority(aePriority);
                else
                    ((S_0044adb0*)::DAT_01202d98)->FUN_0044adb0();
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_00443540

namespace fnv_004446a0 {
struct NiControllerSequence;
struct TESAnimGroup;
struct KFModel
{
    void InitSequence(char*);
    char* GetFileName();
    NiControllerSequence* GetControllerSequence();
    void AssignSequence(NiControllerSequence*);
    TESAnimGroup* GetAnimGroup();
    int GetRefCount();
    int GetActualRefCount();
    int GetManualRefCount();
    void DecRefCount();
    void IncRefCount();
    void DecManualRefCount();
    void IncManualRefCount();
    void SetManualRefCount(int);
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiObjectRefCount;
    unsigned int m_uiManualRefCount;
    char* pFilename;
    char pListSequence[4];
    char m_spAnimGroup[4];
    int BackgroundTask;
    int m_iActualRefCount;
};
struct FUN_004446a0_shell : public ModelLoader
{
    bool QueueKFModelLoad(char*, int, QueuedFile*);
};

struct Flt
{
    operator unsigned int();
};
struct QHeadLocal
{
};
namespace FUN_00528cb0 {
struct FUN_0044cbf0
{
    void* p;
    FUN_0044cbf0(void*);
    ~FUN_0044cbf0();
};
}
struct FUN_0043e210
{
    unsigned int pad[14];
    FUN_0043e210(KFModel*, int);
};
struct FUN_0043e0f0
{
    unsigned int pad[14];
    FUN_0043e0f0(char*, int);
};
struct KFMapStand
{
    virtual void v0();
    virtual void v1();
    virtual bool Get(char*, KFModel**);
};
// @fnv 0x004446a0
bool FUN_004446a0_shell::QueueKFModelLoad(char* apKFFileName, int aePriority, QueuedFile* apParent)
{
    KFModel* pkfModel = 0;
    if (((KFMapStand**)this)[1]->Get(apKFFileName, &pkfModel))
    {
        if (apParent)
        {
            FUN_00528cb0::FUN_0044cbf0 spqueuedKF(new FUN_0043e210(pkfModel, aePriority));
            reinterpret_cast<::QueuedFile *>((((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedKF)))->SetParent(apParent);
            ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedKF)->vfn_28();
            return true;
        }
        return false;
    }
    FUN_00528cb0::FUN_0044cbf0 spqueuedKF(new FUN_0043e0f0(apKFFileName, aePriority));
    reinterpret_cast<::QueuedFile *>((((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedKF)))->SetParent(apParent);
    ((QueuedFile*)(unsigned int)*(Flt*)&spqueuedKF)->vfn_20();
    return true;
}
}  // namespace fnv_004446a0

namespace fnv_00444dc0 {
struct TESObject;
struct TES
{
};
struct QHeadPtr
{
    void* p;
    ~QHeadPtr();
};
struct QueueObj : QHeadPtr
{
    QueueObj(int);
};
struct QHeadPtrDest
{
};
struct QueueModelHolder
{
    void FUN_00443dc0(int, QueueObj*, int, int, int, bool, bool, bool, float);
};
struct FUN_00444dc0_ref
{
};
struct FUN_00444dc0_t
{
    void QueueModelForObject(TESObject* apObject, QHeadPtrDest* apDest, int a3, int a4, FUN_00444dc0_ref* apRef);
};
// Computes a handle and LOD for apObject, queues a model load with fade distance, and assigns the queued handle to apDest.
// @fnv 0x00444dc0
void FUN_00444dc0_t::QueueModelForObject(TESObject* apObject, QHeadPtrDest* apDest, int a3, int a4,
                                         FUN_00444dc0_ref* apRef)
{
    int iHandle = ((int)(reinterpret_cast<::BoundObjectModelLookup *>(this)->FUN_00446a60((::TESForm *)(apObject), (::TESObjectREFR *)(apRef))));
    int iLOD = ::FUN_0045c6b0((::TESForm_0045c6b0 *)(apObject));
    if (apRef && (reinterpret_cast<::FUN_00564e60_shell *>((apRef))->FUN_00564e60() || reinterpret_cast<::FUN_00444ed0_shell *>((apRef))->FUN_00444ed0()))
        iLOD = 6;
    QueueObj kQueued(0);
    float fFadeDist = 0.0f;
    if (apRef && reinterpret_cast<::FUN_00564f00_shell *>((apRef))->FUN_00564f00())
        fFadeDist = 3.402823466e+38F;
    ((QueueModelHolder*)g_modelLoader)->FUN_00443dc0(iHandle, &kQueued, a3, a4, iLOD, true, false, false, fFadeDist);
    reinterpret_cast<::NP_0092c820 *>((apDest))->FUN_0092c820((const ::NP_0092c820 &)(kQueued));
}
}  // namespace fnv_00444dc0

namespace fnv_00447080 {
struct FUN_00447080_shell : public ModelLoader
{
    NiNode* FUN_00447080(char*, int, bool, bool, bool, bool);
};

struct Flt
{
    operator unsigned int();
};
namespace FUN_0043c6e0 {
struct FUN_0043c830
{
    unsigned int pad[0xc];
    Flt model;
    unsigned int pad2[5];
    FUN_0043c830(char*, int, int, bool, int);
    ~FUN_0043c830();
};
}
struct FUN_00443ff0Class
{
};
struct FUN_00447190_dummy
{
};
struct FUN_0043ccf0_s
{
    void FUN_0043ccf0();
};
struct FUN_0043d180_s
{
    void FUN_0043d180();
};
struct FUN_00443190_s
{
};
struct ObjA
{
    void FUN_0092c870();
};
struct FUN_0043b230_s
{
    NiNode* FUN_0043b230();
};
struct ModelMapStand
{
    virtual void v0();
    virtual void v1();
    virtual bool Get(char*, Model**);
};
// @fnv 0x00447080
NiNode* FUN_00447080_shell::FUN_00447080(char* apFilename, int aeLODFadeMult, bool abPrepareObject,
                                         bool abSuppressWarning, bool abFaceGenModel, bool abDontIncrementRefCount)
{
    Model* pmodel = 0;
    if (!(*(ModelMapStand**)this)->Get(apFilename, &pmodel))
    {
        FUN_0043c6e0::FUN_0043c830 queuedModel(apFilename, 0, aeLODFadeMult, abPrepareObject, 0);
        reinterpret_cast<::FUN_00443ff0Class *>((reinterpret_cast<FUN_00443ff0Class*>(&queuedModel)))->FUN_00443ff0(abFaceGenModel);
        reinterpret_cast<::FUN_00447190_dummy *>((reinterpret_cast<FUN_00447190_dummy*>(&queuedModel)))->FUN_00447190(1);
        reinterpret_cast<FUN_0043ccf0_s*>(&queuedModel)->FUN_0043ccf0();
        reinterpret_cast<FUN_0043d180_s*>(&queuedModel)->FUN_0043d180();
        pmodel = (Model*)(unsigned int)queuedModel.model;
    }
    else if (!reinterpret_cast<::FUN_00443190_shell *>((reinterpret_cast<FUN_00443190_s*>(pmodel)))->GetCombinedValue())
    {
        ::FUN_005b5e40();
    }
    if (pmodel)
    {
        if (!abDontIncrementRefCount)
            reinterpret_cast<::FUN_0092c870_shell *>((reinterpret_cast<ObjA*>(pmodel)))->FUN_0092c870();
        return reinterpret_cast<FUN_0043b230_s*>(pmodel)->FUN_0043b230();
    }
    return 0;
}
}  // namespace fnv_00447080

namespace fnv_00447a40 {
struct FUN_00447a40_shell : public ModelLoader
{
    void FUN_00447a40(char*, int, QueuedFile*, int);
};

struct LoadedFile;
template <> class NiPointer<LoadedFile>
{
  public:
    NiPointer(LoadedFile* pObject);
    LoadedFile* m_pObject;
};
struct FUN_0044b160 : public NiPointer<LoadedFile>
{
    FUN_0044b160(LoadedFile* pObject) : NiPointer<LoadedFile>(pObject)
    {}
    ~FUN_0044b160();
};
struct QueueObj
{
    QueueObj(int);
    void* m_pObject;
};
struct QHeadPtr : public QueueObj
{
    QHeadPtr(int pObject) : QueueObj(pObject)
    {}
    ~QHeadPtr();
};
struct Flt
{
    operator unsigned int();
};
struct QHeadLocal
{
};
struct FUN_004483a0_S
{
    LoadedFile* GetHolderValue(const char*);
};
struct FUN_004420b0
{
    FUN_004420b0(unsigned int, int);
    char pad[0x40];
};
struct FUN_00441f80
{
    FUN_00441f80(const char*, int, int);
    char pad[0x40];
};

// Loads the file via GetHolderValue; if loaded, queues a FUN_004420b0 task with the parent, otherwise queues a FUN_00441f80 task and sets its parent.
// @fnv 0x00447a40
void FUN_00447a40_shell::FUN_00447a40(char* apFileName, int aePriority, QueuedFile* apParent, int aeFileIndex)
{
    FUN_0044b160 m_pLoadedFile(((FUN_004483a0_S*)this)->GetHolderValue(apFileName));
    if (*(Flt*)&m_pLoadedFile)
    {
        if (apParent)
        {
            QHeadPtr spqueuedFaceGenFile((int)new FUN_004420b0(*(Flt*)&m_pLoadedFile, aePriority));
            reinterpret_cast<::QueuedFile *>((((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)))->SetParent(apParent);
            ((IOTask*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->vfn_28();
        }
        return;
    }
    QHeadPtr spqueuedFaceGenFile((int)new FUN_00441f80(apFileName, aePriority, aeFileIndex));
    reinterpret_cast<::QueuedFile *>((((QHeadLocal*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)))->SetParent(apParent);
    ((IOTask*)(unsigned int)*(Flt*)&spqueuedFaceGenFile)->vfn_20();
}
}  // namespace fnv_00447a40

struct Virt00448370
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};
struct Stand00448370
{
    char _pad[0x24];
    Virt00448370* field24;
    void FUN_00448370(int);
};
// @fnv 0x0043bb80
void FUN_0043bb80_shell::DestroyLoadedFile()
{
    if (!m_bFileFlagAtOffsetD && m_bFirstFlag)
    {
        ::FUN_005b5e40();
    }
    if (m_bFirstFlag)
    {
        reinterpret_cast<::Stand00448370 *>((reinterpret_cast<_ModelLoaderStub00448370*>(g_modelLoader)))->FUN_00448370((int)(pFileName));
    }
    if (*reinterpret_cast<int*>(this) != 0)
    {
        char szMessage[260];
        std::sprintf(szMessage, "%s ref object at mem %i being destroyed with %i references\r\n", pFileName, this,
                 *reinterpret_cast<int*>(this));
        if (IsHeapLoggerPresent())
        {
            FUN_0043bd00()->vfn_14(4, szMessage, 0, 0, 0);
        }
    }
    delete pFileName;
    delete pFile;
}
// Calls the virtual method f5 on field24, passing a through.
// @fnv 0x00448370
void Stand00448370::FUN_00448370(int aiValue)
{
    field24->f5(aiValue);
}

namespace fnv_00448cc0 {
struct GlobalObject_00448e00
{
    GlobalObject_00448e00();
    __int64 iStart;
    __int64 iEnd;
};
struct FUN_00448e30_this
{
    void init(float);
};
struct FUN_004499c0
{
    ~FUN_004499c0();
    void* p0;
    void* p1;
    void* p2;
    void* p3;
};
struct FUN_0044cc10 : public FUN_004499c0
{
    FUN_0044cc10();
};
struct FUN_006ebde0_shell
{
};
struct QHeadPtr
{
    ~QHeadPtr();
    void* p;
};
struct QueueObj : public QHeadPtr
{
    QueueObj(int);
};
struct Flt
{
    operator unsigned int();
};
struct QueuedTask_00448cc0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Run();
};
struct Queue_00448cc0
{
};
struct ModelLoaderStand_00448cc0
{
    char pad[0xc];
    Queue_00448cc0* m_pPrimaryTaskProcessor;
    bool ProcessQueuedTasks();
};

// Initializes a timer, then repeatedly dequeues tasks and runs them until the queue is empty or the timer expires; returns whether the queue is empty.
// @fnv 0x00448cc0
bool ModelLoaderStand_00448cc0::ProcessQueuedTasks()
{
    GlobalObject_00448e00 kTimer;
    if (::IsNotStateSix((int)::DAT_01202d98))
        reinterpret_cast<::FUN_00448e30_this *>((((FUN_00448e30_this*)&kTimer)))->init(::DAT_01017130);
    else
        reinterpret_cast<::FUN_00448e30_this *>((((FUN_00448e30_this*)&kTimer)))->init(5.0f);
    {
        FUN_0044cc10 kTaskList;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>((((FUN_006ebde0_shell*)&kTaskList)))->FUN_006ebde0() && !::FUN_00448e70((__int64*)&kTimer))
        {
            int iCount = 0;
            QueueObj kTask(0);
            if (reinterpret_cast<::FUN_0044b8d0_Class *>((m_pPrimaryTaskProcessor))->ProcessIteration((::Iteration *)(::fnv_00448cc0::FUN_0044cc10 *)(&kTaskList), (unsigned int *)(int *)(&iCount), (unsigned int)(&kTask), true))
                ((QueuedTask_00448cc0*)(unsigned int)*(Flt*)&kTask)->Run();
        }
        return reinterpret_cast<::FUN_006ebde0_shell *>((((FUN_006ebde0_shell*)&kTaskList)))->FUN_006ebde0();
    }
}
}  // namespace fnv_00448cc0

namespace fnv_0044afe0 {
struct KFModel
{
};
struct S0044afe0
{
    KFModel* p;
    S0044afe0* FUN_0044afe0(KFModel* a);
};
// Stores the given KFModel pointer in p and, if it is non-null, calls its FUN_0044b010 method; returns this.
// @fnv 0x0044afe0
S0044afe0* S0044afe0::FUN_0044afe0(KFModel* apModel)
{
    p = apModel;
    if (p != 0)
        reinterpret_cast<::fnv_0044b010::FUN_0044b010_shell *>((p))->FUN_0044b010();
    return this;
}
}  // namespace fnv_0044afe0

namespace fnv_00528ce0 {
int ClearLowBit(int*);
struct FUN_0044df00Class
{
    char* FUN_0044df00();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_006ecba0_class
{
    void* FUN_006ecba0(bool, void*);
    int iValue;
};
struct V40
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0a();
    virtual void f0b();
    virtual void f0c();
    virtual void f0d();
    virtual void f0e();
    virtual void f0f();
    virtual void f10();
};
struct FUN_00528ce0_shell
{
    V40* pObject;
    bool FUN_00528ce0(void* apA, void* apB);
    bool ProcessNode(void* apA, void* apB);
    void FUN_005292a0(int);
    void FUN_00529000();
};

// @fnv 0x00528ce0
bool FUN_00528ce0_shell::FUN_00528ce0(void* apA, void* apB)
{
    bool bResult = false;
    while (1)
    {
        FUN_006ecba0_class kCur;
        if (!ProcessNode(apA, apB))
        {
            bResult = false;
            break;
        }
        {
            FUN_006ecba0_class kOld;
            FUN_006ecba0_class kNew;
            reinterpret_cast<::FUN_006ecba0_class *>(&(kOld))->FUN_006ecba0(false, (void*)ClearLowBit((int*)((char*)this + 0x18)));
            reinterpret_cast<::FUN_006ecba0_class *>(&(kNew))->FUN_006ecba0(true, (void*)ClearLowBit((int*)((char*)this + 0x18)));
            if (!::FUN_004491c0((volatile long *)(void *)(((FUN_0044df00Class*)((char*)this + 0x14))->FUN_0044df00() + 8),
                              (unsigned int)*(Flt*)&kNew, (unsigned int)*(Flt*)&kOld))
                continue;
            reinterpret_cast<::FUN_006ecba0_class *>(&(kCur))->FUN_006ecba0(false, (void*)ClearLowBit((int*)((char*)this + 0x14)));
            if (::FUN_004491c0((volatile long *)(*(void**)((char*)this + 0x10)), (unsigned int)*(Flt*)&kOld, (unsigned int)*(Flt*)&kCur))
                FUN_005292a0(ClearLowBit((int*)((char*)this + 0x14)));
            else
                ProcessNode(apA, apB);
            pObject->f10();
            bResult = true;
            break;
        }
    }
    FUN_00529000();
    return bResult;
}
}  // namespace fnv_00528ce0

namespace fnv_00443270 {
struct FUN_006ebde0_shell
{
};
struct FUN_00443190_shell
{
};
struct GridArray
{
};
struct BSAudio
{
};
struct Flt
{
    operator unsigned int();
};
template <class T> struct BSStringT
{
    T* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(char const*, ...);
};
struct FUN_004431d0
{
    char m_buf[0x10c];
    ~FUN_004431d0();
};
struct FUN_004498e0 : FUN_004431d0
{
    FUN_004498e0();
};
struct FUN_00443220
{
    char m_buf[0x110];
    ~FUN_00443220();
};
struct FUN_00449960 : FUN_00443220
{
    FUN_00449960();
};
struct Map_443270
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
    virtual int GetCount();
};
struct File_443270
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
    virtual void WriteString(BSStringT<char>*, int);
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void Write(const char*, unsigned int);
};
struct FUN_00443270_shell
{
    Map_443270* m_pModels;
    Map_443270* m_pAnims;
    void FUN_00443270(File_443270* pFile, bool bAll);
};
// Iterates the model and animation maps, formats each entry's counts into a line, logs it via _FNV_Warning and optionally writes it to pFile.
// @fnv 0x00443270
void FUN_00443270_shell::FUN_00443270(File_443270* pFile, bool bAll)
{
    if (m_pModels->GetCount())
    {
        FUN_004498e0 kIter;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>((((FUN_006ebde0_shell*)&kIter)))->FUN_006ebde0())
        {
            const char* pKey = 0;
            void* pVal = 0;
            if (reinterpret_cast<::Queue44c640 *>((m_pModels))->TryGetNextEntry((::QueueIter44c640 *)(void *)(&kIter), (void **)(&pKey), (int)(&pVal), 1))
            {
                if (reinterpret_cast<::FUN_00443190_shell *>((((FUN_00443190_shell*)pVal)))->GetCombinedValue() > 0 || bAll)
                {
                    char acBuf[1024];
                    ::FUN_00406d00(acBuf, 1024, "MODELS:\t%3d\t%3d\t%3d\t%s\r\n",
                               reinterpret_cast<::FUN_00443190_shell *>((((FUN_00443190_shell*)pVal)))->GetCombinedValue(), ((int)(reinterpret_cast<::Callees *>((void *)(((GridArray*)pVal)))->FUN_00726070())),
                               ((int)(reinterpret_cast<::Twin_0044ddc0 *>((void *)(((GridArray*)pVal)))->GetName())), pKey);
                    ::FUN_005b5e40();
                    if (pFile)
                        pFile->Write(acBuf, std::strlen(acBuf) + 1);
                }
            }
        }
    }
    if (m_pAnims->GetCount())
    {
        FUN_00449960 kIter2;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>((((FUN_006ebde0_shell*)&kIter2)))->FUN_006ebde0())
        {
            const char* pKey2 = 0;
            void* pVal2 = 0;
            if (reinterpret_cast<::Queue44c640 *>((m_pAnims))->TryGetNextEntry((::QueueIter44c640 *)(void *)(&kIter2), (void **)(&pKey2), (int)(&pVal2), 1))
            {
                if (::FUN_004431b0((int*)pVal2) > 0)
                {
                    BSStringT<char> kStr;
                    ::FUN_00406f60((::FUN_00406f90_this *)&(kStr), "ANIMATION:\t%3d\t%3d\t%3d\t%s\r\n", ::FUN_004431b0((int*)pVal2), reinterpret_cast<::FUN_0084e3a0_Class *>((pVal2))->FUN_0084e3a0(),
                                 ((void *)(reinterpret_cast<::MagicCaster_shell *>((((BSAudio*)pVal2)))->FUN_0044edb0())), pKey2);
                    ::FUN_005b5e40();
                    if (pFile)
                        pFile->WriteString(&kStr, 1);
                }
            }
        }
    }
}
}  // namespace fnv_00443270

struct NiFile;
struct FileFinder
{
    static NiFile* GetFile(char const*, int, unsigned int, unsigned int);
};
struct FUN_00c3d090_shell2
{
    void FUN_00c3d090(int, char*);
};
struct FUN_00c3cff0_shell
{
    NiFile* FUN_00c3cff0(int, int);
};
// @fnv 0x00c3cff0
NiFile* FUN_00c3cff0_shell::FUN_00c3cff0(int aeArchiveTypeIndex, int aeArchiveType)
{
    NiFile* pFile = 0;
    if (*(int*)((char*)this + 0x2c))
    {
        pFile = ((::NiFile *)(::fnv_00af6340::FUN_00af6340(aeArchiveTypeIndex, (::fnv_00af6340::BSFileEntry *)(*(int*)((char*)this + 0x2c)), -1, 0)));
    }
    if (*(int*)((char*)this + 0x28) && !pFile)
    {
        char plookupFileName[260];
        ((FUN_00c3d090_shell2*)this)->FUN_00c3d090(aeArchiveTypeIndex, plookupFileName);
        pFile = FileFinder::GetFile(plookupFileName, 0, -1, aeArchiveType);
    }
    return pFile;
}

namespace fnv_0043c650 {
struct FUN_006fbcd0_shell
{
    void FUN_00c3cb70(int, int);
};
struct FUN_0043c630_shell
{
    bool FUN_0043c630();
};
struct Q_0043c050
{
    void FUN_0043c100(bool);
};
struct ModelLoader_00448f50
{
};

struct QueuedTexture_0043c650
{
    void FUN_00c3cb70(int, int);
    bool FUN_0043c630();
    void FUN_0043c100(bool);
    void FUN_0043c650(int aePreviousState, void* apTaskOwner);
};

// @fnv 0x0043c650
void QueuedTexture_0043c650::FUN_0043c650(int aePreviousState, void* apTaskOwner)
{
    reinterpret_cast<::fnv_00c3cb70::IOTask *>(this)->FUN_00c3cb70(aePreviousState, (::fnv_00c3cb70::RefObj *)((int)apTaskOwner));
    if (((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
    {
        if (reinterpret_cast<::FUN_0043c630_shell *>(this)->FUN_0043c630())
        {
            reinterpret_cast<::FUN_0043c100_shell *>(this)->FUN_0043c100(false);
            reinterpret_cast<::fnv_00448f50::FUN_00448f50_shell *>((((ModelLoader_00448f50*)g_modelLoader)))->ForwardToVTableSlot((::fnv_00448f50::BSFileEntry *)(::BSFileEntry *)(((::BSFileEntry *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))));
        }
    }
}
}  // namespace fnv_0043c650

struct FUN_00449130_s
{
};
struct Flt_s
{
    operator unsigned int();
};
struct FUN_0043ea30_s
{
    void FUN_0043ea30();
};
struct FUN_00490fa0_s
{
};
struct FUN_0043e9b0_s
{
    void FUN_0043e9b0();
};
namespace fnv_0043ea30 {
struct Holder14
{
};
struct FUN_0043ea30_shell : IOTask
{
    void FUN_0043ea30();
};
// @fnv 0x0043ea30
void FUN_0043ea30_shell::FUN_0043ea30()
{
    ((int*)this)[12]++;
    if (::FUN_00449110((int *)this) && reinterpret_cast<::FUN_0043caa0_shell *>(this)->FUN_0043caa0() && ((int*)this)[11] == ((int*)this)[12])
        reinterpret_cast<::Holder14 *>((((Holder14*)g_modelLoader)))->ForwardToInner(((int*)this)[10]);
}
}  // namespace fnv_0043ea30

namespace fnv_0043f240 {
struct BSFaceGenModel;
struct BipedAnim
{
    bool IsSlotHidden(int);
    BSFaceGenModel* GetFaceGenModelForSlot(int);
};
struct GO
{
    void operator=(void*);
};
struct QueuedHelmet
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    BipedAnim* pExistingBipedAnim;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    GO m_kQueuedModels[80];
    void UpdateFaceGenModels();
};
// @fnv 0x0043f240
void QueuedHelmet::UpdateFaceGenModels()
{
    for (int i = 0; i < 20; i++)
    {
        if (reinterpret_cast<::BipedAnim *>((pExistingBipedAnim))->IsSlotHidden((::BIPED_OBJECT)(i)) && !::FUN_00449130((int*)this))
            *(GO*)((char*)&this->m_kQueuedModels + i * 4) = (void*)((::fnv_0043f240::BSFaceGenModel *)(reinterpret_cast<::FaceLoader *>((pExistingBipedAnim))->FUN_004ae790(i)));
    }
}
}  // namespace fnv_0043f240

namespace fnv_00440710 {
extern int _data_011c16bc;
struct QueueObj
{
    int x;
    QueueObj(int);
    ~QueueObj();
};
struct E_00449210
{
};
struct FUN_00440710_t
{
    int p0, p1, p2, p3, p4, p5, p6;
    E_00449210* q;
    void DispatchToQueue(int a);
};
// Constructs a QueueObj from a and passes its address to q->FUN_00449240.
// @fnv 0x00440710
void FUN_00440710_t::DispatchToQueue(int aiValue)
{
    QueueObj o(aiValue);
    ::FUN_00449240((::LockedReceiver *)(q), (::ReceiverArgument)(&o));
}
}  // namespace fnv_00440710

struct Loader_S
{
public:
    void UpdateLoadingStatus();
};
// @fnv 0x00446e30
void ModelLoader::UpdateLoadingStatusCallback()
{
    reinterpret_cast<::Loader_S *>((g_modelLoader))->UpdateLoadingStatus();
}
// Calls ReleaseAllObjects and ProcessQueuedTasks on g_modelLoader and returns 1 only if both return nonzero.
// @fnv 0x00446e40
char FUN_00446e40()
{
    unsigned char a = 1;
    unsigned char b = 1;
    a = ((unsigned char)(::fnv_00448c10::ReleaseAllObjects((char *)(((Loader_S*)g_modelLoader)))));
    b = ((unsigned char)(reinterpret_cast<::fnv_00448cc0::ModelLoaderStand_00448cc0 *>((((Loader_S*)g_modelLoader)))->ProcessQueuedTasks()));
    return (a && b) ? 1 : 0;
}

struct S_0044dbc0
{
    virtual ~S_0044dbc0();
};
struct FUN_00449c50 : S_0044dbc0
{
    void FUN_0044c480(int);
    virtual ~FUN_00449c50();
};
// @fnv 0x00449c30
int FUN_00449c30_class::CallBaseMethod()
{
    return reinterpret_cast<::FUN_00449c50 *>(this)->FUN_00449c50::~FUN_00449c50();
}
// Destructor that calls FUN_0044c480 with argument 1.
// @fnv 0x00449c50
FUN_00449c50::~FUN_00449c50()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(1);
}

struct TESObjectREFR_GetFlags_Helper
{
};

struct FUN_00449cb0_Helper
{
    unsigned int ComputeNameHash(char* name);
};

// Hashes the null-terminated name with a 33x multiplier and returns the hash modulo the object's flags value.
// @fnv 0x00449cb0
unsigned int FUN_00449cb0_Helper::ComputeNameHash(char* name)
{
    unsigned int hash = 0;
    while (*name)
    {
        hash = hash * 32 + hash + (signed char)*name;
        name++;
    }
    return hash % ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_Helper*)((TESObjectREFR*)this))))->GetName()));
}

struct FUN_0044c480
{
    virtual ~FUN_0044c480();
};

struct FUN_00449d60 : FUN_0044c480
{
    virtual ~FUN_00449d60();
};
// @fnv 0x00449d40
void FUN_00449d40_class::FUN_00449d40()
{
    reinterpret_cast<::FUN_00449d60 *>(this)->FUN_00449d60::~FUN_00449d60();
}

// Destructor that calls FUN_0044c3f0 with 1.
// @fnv 0x00449d60
FUN_00449d60::~FUN_00449d60()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(1);
}

namespace fnv_00449ec0 {
extern int DAT_0101737c;
struct FUN_0044c480
{
    virtual ~FUN_0044c480();
};
struct FUN_00449ec0 : FUN_0044c480
{
    virtual ~FUN_00449ec0();
};
// Destructor that calls M(true) on the base class.
// @fnv 0x00449ec0
FUN_00449ec0::~FUN_00449ec0()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(true);
}
}  // namespace fnv_00449ec0

namespace fnv_0044b300 {
struct FUN_0044b2a0_Class
{
};
void FUN_0044b2e0(void*);
struct FUN_0044b300_Class
{
    FUN_0044b2a0_Class* m_pObject;
    FUN_0044b300_Class* FUN_0044b300(FUN_0044b2a0_Class* value);
};
// @fnv 0x0044b300
FUN_0044b300_Class* FUN_0044b300_Class::FUN_0044b300(FUN_0044b2a0_Class* apObject)
{
    if (m_pObject != apObject)
    {
        if (m_pObject)
            reinterpret_cast<struct ::FUN_0044b2e0 *>((m_pObject))->Method();
        m_pObject = apObject;
        if (m_pObject)
            reinterpret_cast<::FUN_0044b2a0_Class *>((m_pObject))->FUN_0044b2a0();
    }
    return this;
}
}  // namespace fnv_0044b300

namespace fnv_005292a0 {
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};
struct TESRaceForm
{
};
struct BSAudio
{
};
struct DeletedNodeScanner
{
    void ScanForDeletedNodes();
};
struct FUN_005292a0 : public BSAudio
{
    unsigned int f0, f4, f8, fc, f10, f14, f18, f1c;
    unsigned int f20;
    void SetRace(unsigned int race);
};
// @fnv 0x005292a0
void FUN_005292a0::SetRace(unsigned int race)
{
    reinterpret_cast<::FUN_006f74f0_cls *>((((QIdlePtr*)(race + 4))))->FUN_006f74f0=((::ObjA *)(void *)(0));
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)race)))->Initialize((::CombatController *)(f1c));
    f1c = race;
    f20++;
    if (f20 == ((int)(reinterpret_cast<::MagicCaster_shell *>((((BSAudio*)*(unsigned int*)this)))->FUN_0044edb0())))
        ((DeletedNodeScanner*)this)->ScanForDeletedNodes();
}
}  // namespace fnv_005292a0

namespace fnv_00666510 {
struct BSAudio
{
};
struct TESRaceForm
{
};
struct FUN_0044f200_Class
{
};
struct FUN_00666510_Class
{
    void AddRace(TESRaceForm* pRace);
};
// @fnv 0x00666510
void FUN_00666510_Class::AddRace(TESRaceForm* pRace)
{
    *(unsigned int*)((char*)pRace + 4) = 0;
    reinterpret_cast<::CombatProcedure *>((pRace))->Initialize((::CombatController *)(*(unsigned int*)((char*)this + 0x1c)));
    *(TESRaceForm**)((char*)this + 0x1c) = pRace;
    *(unsigned int*)((char*)this + 0x20) += 1;
    if (*(unsigned int*)((char*)this + 0x20) == ((int)(reinterpret_cast<::MagicCaster_shell *>(((*(BSAudio**)((char*)this))))->FUN_0044edb0())))
        reinterpret_cast<::FUN_0044f200_Class *>((((FUN_0044f200_Class*)this)))->FilterListByQueueData();
}
}  // namespace fnv_00666510

namespace fnv_009052e0 {
struct KFModel
{
};
struct KFModelPtr
{
    KFModel* p;
    KFModel* FUN_009052e0(const KFModelPtr& other);
};
// @fnv 0x009052e0
KFModel* KFModelPtr::FUN_009052e0(const KFModelPtr& other)
{
    if (p != other.p)
    {
        if (p)
            reinterpret_cast<::fnv_0044b050::FUN_0044b050_shell *>((p))->FUN_0044b050();
        p = other.p;
        if (p)
            reinterpret_cast<::fnv_0044b010::FUN_0044b010_shell *>((p))->FUN_0044b010();
    }
    return (KFModel*)this;
}
}  // namespace fnv_009052e0

struct NiFile
{
    static NiFile* __cdecl GetFile(const char*, int, unsigned int);
    virtual ~NiFile();
};

class NiBinaryStream;
struct NiStream
{
    bool Save(NiFile* apFile);
public:
    bool Load(::NiBinaryStream *);
public:
    bool Save(::NiBinaryStream *);
};

struct FUN_00c3a950 : NiStream
{
    bool SaveFile(const char* apPath);
};

// Opens the file at apPath with NiFile::GetFile, saves the stream to it, deletes the file object and returns whether the save succeeded.
// @fnv 0x00c3a950
bool FUN_00c3a950::SaveFile(const char* apPath)
{
    NiFile* pFile = NiFile::GetFile(apPath, 1, 0x2800);
    bool bResult = false;
    if (pFile)
    {
        bResult = reinterpret_cast<::NiStream *>(this)->Save((::NiBinaryStream *)(pFile));
        delete pFile;
    }
    return bResult;
}

class BSStream
{
  public:
    ~BSStream();
    void* FUN_0043d150(unsigned int flags);
};

void __cdecl _Deallocate(void*);

BSStream::~BSStream()
{}

// Destroys the BSStream, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0043d150
void* BSStream::FUN_0043d150(unsigned int flags)
{
    reinterpret_cast<::fnv_0043d090::FUN_0043d090::BSStream *>((this))->fnv_0043d090::FUN_0043d090::BSStream::~BSStream();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0043d8c0 {
struct QueuedTreeModel
{
    void FUN_0043d8f0();
    void* FUN_0043d8c0(unsigned int flags);
};

void _Deallocate(void*);

// @fnv 0x0043d8c0
void* QueuedTreeModel::FUN_0043d8c0(unsigned int flags)
{
    this->FUN_0043d8f0();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}
}  // namespace fnv_0043d8c0

namespace fnv_0043d910 {
struct FNStub
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual char* vfn_18();
};

struct TESObjectTREE
{
    unsigned char padding[0x48];
    FNStub stub;
};

struct QueuedTreeModel : QueuedModel
{
    unsigned char padding[0x44];
    TESObjectREFR* pRef;
    TESObjectTREE* pTree;

    void QueueTreeModelLoad();
};

struct ModelLoaderQueueTexture : ModelLoader
{
    void QueueModelFilePath(const char*, int, QueuedFile*);
};


// @fnv 0x0043d910
void QueuedTreeModel::QueueTreeModelLoad()
{
    if (((char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTree->stub))->FUN_00408da0()))[0] != 0)
    {
        char pfilename[260];

        TaskQueueInterface::CopyStringToBuffer(pfilename, 0x104, pTree->stub.vfn_18());

        strcat_s(pfilename, 0x104, ((char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTree->stub))->FUN_00408da0())));

        {
            char pbasefilename[260];

            ::CleanPath(pfilename, pbasefilename, 0x104);

            reinterpret_cast<ModelLoaderQueueTexture*>(g_modelLoader)
                ->QueueModelFilePath(pbasefilename, this->FUN_0043cc60(), static_cast<QueuedFile*>(this));
        }
    }

    this->DispatchToManager();
}
}  // namespace fnv_0043d910

namespace fnv_0043da00 {
struct I2_665b80
{
};

typedef I2_665b80 BSTreeNode;

struct C665b80
{
};

struct BSTreeManager : public C665b80
{
};

struct AutoMemHelper
{
    int m_data;

    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};

typedef AutoMemHelper AutoMemContext;

struct QueuedTreeModel
{
    unsigned char padding[0x48];
    int pRef;
    int pTree;

    void FUN_0043da00();
};

BSTreeManager* DAT_011d5c48;

// Looks up a BSTreeNode by pRef and pTree via DAT_011d5c48 and passes it to FUN_00665b80 with pRef, inside an AutoMemContext scope.
// @fnv 0x0043da00
void QueuedTreeModel::FUN_0043da00()
{
    BSTreeNode* ptreeNode;
    AutoMemContext tempMemContext(0x1e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                                  0x476);

    ptreeNode = ((::fnv_0043da00::I2_665b80 *)(reinterpret_cast<::TreeManager *>((DAT_011d5c48))->CreateTreeInstance((::TreeReference *)(pRef), (::TESObjectTREE *)(pTree))));
    reinterpret_cast<::C665b80 *>((DAT_011d5c48))->FUN_00665b80(pRef, (::I2_665b80 *)(ptreeNode));
}
}  // namespace fnv_0043da00

namespace fnv_0043e8f0 {
void __cdecl _Deallocate(void* ptr);

class FUN_0043e920_class
{
  public:
    void FUN_0043e920();
    void* FUN_0043e8f0(unsigned int flags);
};

void FUN_0043e920_class::FUN_0043e920()
{}

// Calls FUN_0043e920, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0043e8f0
void* FUN_0043e920_class::FUN_0043e8f0(unsigned int flags)
{
    reinterpret_cast<::FUN_0043e920_class *>(this)->FUN_0043e920();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0043e8f0

struct FNStub
{
};


struct QueuedHeadStandIn
{
    bool GetQueuedHeadDescription(char* apDescription, unsigned int aiBufferSize);
};

// Formats "Queued head for NPC %s" into apDescription using the full name of the object at this+0x28, and returns true.
// @fnv 0x0043eed0
bool QueuedHeadStandIn::GetQueuedHeadDescription(char* apDescription, unsigned int aiBufferSize)
{
    ::FUN_00406d00(apDescription, aiBufferSize, "Queued head for NPC %s",
               ((char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(
                                             *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x28)) +
                                         0xd0)))->FUN_00408da0())));
    return true;
}

namespace fnv_0043f030 {
struct QueuedHelmet
{
    void FUN_0043f080();
    void* FUN_0043f030(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// @fnv 0x0043f030
void* QueuedHelmet::FUN_0043f030(unsigned int flags)
{
    FUN_0043f080();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}
}  // namespace fnv_0043f030

namespace fnv_0043f2b0 {
class GO
{
  public:
    operator unsigned int() const;
};

class FUN_0043c610_shell
{
  public:
};


class QueuedHelmet
{
  public:
    void FUN_0043f2b0();
};

// If the object at offset 0x1c is zero and FUN_00449130 returns false, adds this to the post-process queue, then calls RunVirtualMethod28.
// @fnv 0x0043f2b0
void QueuedHelmet::FUN_0043f2b0()
{
    if (!reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x1c)->operator unsigned int() &&
        !::FUN_00449130(reinterpret_cast<int*>(this)))
    {
        reinterpret_cast<::IOManager *>((reinterpret_cast<IOTask*>(this)))->SubmitTask();
    }

    reinterpret_cast<::FUN_0043c610_shell *>((reinterpret_cast<FUN_0043c610_shell*>(this)))->RunVirtualMethod28();
}
}  // namespace fnv_0043f2b0

namespace fnv_0043fb80 {
struct BSFaceGenModel
{
    int unused;
};

struct GO
{
    void* p;
    operator unsigned int() const;
};

enum BIPED_OBJECT
{
    BIPED_OBJECT_VALUE
};

struct FUN_004aeb20_holder
{
};

struct BipedAnim : public FUN_004aeb20_holder
{
};

struct Standin0043fb50
{
};

struct QueuedHelmet
{
    unsigned char unused[0x28];
    BipedAnim* pExistingBipedAnim;
    unsigned char unused2[0x50];
    GO m_kQueuedModels[20];
    GO m_kQueuedModelsSecondary[20];
    int pRef;

    void ApplyQueuedModels();
};

// @fnv 0x0043fb80
void QueuedHelmet::ApplyQueuedModels()
{
    int n;
    for (n = 0; n < 0x14; ++n)
    {
        if (m_kQueuedModelsSecondary[n].operator unsigned int() != 0)
        {
            reinterpret_cast<::FUN_004aeb20_holder *>((pExistingBipedAnim))->AttachFaceGenModel(
                (::BSFaceGenModel *)(::fnv_0043fb80::BSFaceGenModel *)(reinterpret_cast<BSFaceGenModel*>(m_kQueuedModels[n].operator unsigned int())),
                reinterpret_cast<NiNode*>(m_kQueuedModelsSecondary[n].operator unsigned int()),
                (*(::BIPED_OBJECT *)&(const ::fnv_0043fb80::BIPED_OBJECT &)(static_cast<BIPED_OBJECT>(n))));
        }
    }

    reinterpret_cast<::Standin0043fb50 *>((reinterpret_cast<Standin0043fb50*>(g_modelLoader)))->DispatchToVirtual(pRef);
}
}  // namespace fnv_0043fb80

namespace fnv_0043fe10 {
void _Deallocate(void*);

struct FUN_00440eb0_class
{
    void FUN_0043fe40(void);
    void* FUN_0043fe10(unsigned int flags);
};

// @fnv 0x0043fe10
void* FUN_00440eb0_class::FUN_0043fe10(unsigned int flags)
{
    FUN_0043fe40();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}
}  // namespace fnv_0043fe10

void __cdecl _Deallocate(void*);

struct QueuedFileLoad
{
    void FUN_00441d20();
    void* FUN_00441cf0(unsigned int flags);
};

// @fnv 0x00441cf0
void* QueuedFileLoad::FUN_00441cf0(unsigned int flags)
{
    reinterpret_cast<::fnv_00441d20::FUN_00441d20 *>(this)->fnv_00441d20::FUN_00441d20::~FUN_00441d20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00446990 {
struct TESObjectREFR_GetFlags_Helper
{
};

struct FUN_00446990_StandIn
{
    unsigned int m_iFadeNodeMode[8];
    TESObjectREFR* m_pObject;

    unsigned int GetObjectFlags();
};

// Returns the flags of m_pObject via CallGetFlags, or 0 when m_pObject is null.
// @fnv 0x00446990
unsigned int FUN_00446990_StandIn::GetObjectFlags()
{
    return m_pObject ? ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<TESObjectREFR_GetFlags_Helper*>(m_pObject)))->GetName())) : 0;
}
}  // namespace fnv_00446990

namespace fnv_00449ab0 {
struct FUN_00449ea0_cls
{
    void* FUN_00449ab0(unsigned int flags);
};

void _Deallocate(void* p);

// @fnv 0x00449ab0
void* FUN_00449ea0_cls::FUN_00449ab0(unsigned int flags)
{
    reinterpret_cast<::FUN_00449ea0_cls *>(this)->FUN_00449ea0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00449ab0

void FUN_004499a0(int**);
void __cdecl _Deallocate(void*);

struct FUN_00449b70_Class
{
    void* FUN_00449b70(unsigned int flags);
};

// @fnv 0x00449b70
void* FUN_00449b70_Class::FUN_00449b70(unsigned int flags)
{
    FUN_004499a0((int**)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00449d10 {
struct FUN_00449c50
{
    virtual ~FUN_00449c50();
    FUN_00449c50* FUN_00449d10(unsigned int flags);
};

void _Deallocate(void* ptr);

FUN_00449c50::~FUN_00449c50()
{}

// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x00449d10
FUN_00449c50* FUN_00449c50::FUN_00449d10(unsigned int flags)
{
    reinterpret_cast<::FUN_00449c50 *>(this)->FUN_00449c50::~FUN_00449c50();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}
}  // namespace fnv_00449d10

namespace fnv_00449e70 {
struct FUN_00449d60
{
    virtual ~FUN_00449d60();
    void* FUN_00449e70(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00449e70
void* FUN_00449d60::FUN_00449e70(unsigned int flags)
{
    reinterpret_cast<::FUN_00449d60 *>((this))->FUN_00449d60::~FUN_00449d60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00449e70

struct FUN_0044adb0_class
{
    unsigned char pad[0x4c];
    unsigned int count;
    ModelLoader** entries;

    void FUN_0044adb0();
};

// @fnv 0x0044adb0
void FUN_0044adb0_class::FUN_0044adb0()
{
    for (unsigned int i = 0; i < count; ++i)
    {
        entries[i]->ProcessQueuedFile();
    }
}

struct FUN_0044b4b0_Class
{
    void FUN_0044b4b0(void);
};

extern void __cdecl _Deallocate(void*);

struct InterfacedClass
{
    void FUN_0044b4b0(void);
    void* FUN_0044b4d0(unsigned int flags);
};

// @fnv 0x0044b4d0
void* InterfacedClass::FUN_0044b4d0(unsigned int flags)
{
    ((FUN_0044b4b0_Class*)this)->FUN_0044b4b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00906320 {
class RecursiveSpinLock
{
  public:
};

class QHeadPtr
{
  public:
    ~QHeadPtr();
};

class FUN_009066d0_Class
{
  public:
    bool FUN_009066d0();
};

struct FUN_00906320_Class
{
    unsigned char _padding[0x20];
    RecursiveSpinLock _spinLock;

    FUN_009066d0_Class* FUN_00449f80(int*, QHeadPtr*);
    bool FUN_00906320(int*, QHeadPtr);
};

// Locks the spin lock, calls FUN_009066d0 on the object returned by FUN_00449f80, unlocks, and returns the result.
// @fnv 0x00906320
bool FUN_00906320_Class::FUN_00906320(int* a, QHeadPtr q)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(_spinLock))->FUN_0040fbf0((char *)(0));
    bool result = FUN_00449f80(a, &q)->FUN_009066d0();
    reinterpret_cast<::RecursiveSpinLock *>(&(_spinLock))->FUN_0040fba0();
    return result;
}
}  // namespace fnv_00906320

struct FUN_009157c0
{
    void Method(void);
};

void _Deallocate(void* p);

struct FUN_00915790
{
    void* DeleteThis(unsigned int flags);
};

// Calls Method on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00915790
void* FUN_00915790::DeleteThis(unsigned int flags)
{
    ((FUN_009157c0*)this)->Method();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00449dc0 {
class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();

  private:
    void* member;
};


struct FUN_00449dc0_Class
{
    char* FUN_00449dc0(char const*);
};

// @fnv 0x00449dc0
char* FUN_00449dc0_Class::FUN_00449dc0(char const* apString)
{
    AutoMemHelper helper(6, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h", 0x1d7);

    unsigned int length = ::FUN_0044a670(apString) + 1;
    char* result2 = new char[length];

    TaskQueueInterface::CopyStringToBuffer(result2, length, apString);
    return result2;
}
}  // namespace fnv_00449dc0

namespace fnv_009066d0 {
struct FUN_0044df00Class
{
    int FUN_0044df00();
};

struct FUN_006ecba0_class
{
    int value;
    void* FUN_006ecba0(bool, void*);
};

struct GO : public FUN_006ecba0_class
{
    operator unsigned int();
};

struct FUN_00529000_Class
{
    void FUN_00529000();
};

int ClearLowBit(int*);

struct FUN_009066d0_Class : public FUN_00529000_Class
{
    char pad[0x0F];
    void* member10;
    FUN_0044df00Class member14;
    int* member18;

    bool FUN_009066d0(int, int);
    bool FUN_00906820(int, int);
    void FUN_005292a0(int);
};

// @fnv 0x009066d0
bool FUN_009066d0_Class::FUN_009066d0(int arg1, int arg2)
{
    bool result = false;

    while (true)
    {
        if (!FUN_00906820(arg1, arg2))
        {
            result = false;
            break;
        }

        GO go3;
        GO go2;
        GO go1;

        reinterpret_cast<::FUN_006ecba0_class *>(&(go3))->FUN_006ecba0(false, (void*)ClearLowBit((int*)&member18));
        reinterpret_cast<::FUN_006ecba0_class *>(&(go2))->FUN_006ecba0(true, (void*)ClearLowBit((int*)&member18));

        if (!::FUN_004491c0((volatile long *)(void *)((void*)(member14.FUN_0044df00() + 8)), go2.operator unsigned int(),
                          go3.operator unsigned int()))
        {
            continue;
        }

        reinterpret_cast<::FUN_006ecba0_class *>(&(go1))->FUN_006ecba0(false, (void*)ClearLowBit((int*)&member14));

        if (::FUN_004491c0((volatile long *)(member10), go3.operator unsigned int(), go1.operator unsigned int()))
        {
            reinterpret_cast<::fnv_005292a0::FUN_005292a0 *>(this)->SetRace(ClearLowBit((int*)&member14));
        }
        else
        {
            FUN_00906820(arg1, arg2);
        }

        result = true;
        break;
    }

    FUN_00529000();
    return result;
}
}  // namespace fnv_009066d0

class B43D100Object
{
  public:
    virtual ~B43D100Object();
};

class B43D100Owner
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
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    B43D100Object* m_pPointer;

    void DestroyObject();
};

// Deletes the owned B43D100Object and clears the pointer to null.
// @fnv 0x0043d100
void B43D100Owner::DestroyObject()
{
    delete m_pPointer;
    m_pPointer = 0;
}

// Constructor-like thiscall with 3 stack args: calls a base routine with two
// args, stores the class vtable pointer, stores the third arg at +0x38, returns this.

extern char DAT_0101698c[];

struct FUN_0043bd10_base
{
    void FUN_0043bd10(int a1, int a2);
};

struct FUN_0043d540_cls : FUN_0043bd10_base
{
    void* m_pVTable;
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
    int m_iValue38;

    FUN_0043d540_cls* FUN_0043d540(int a1, int a2, int a3);
};

// Calls the base constructor with a1 and a2, sets the vtable pointer to DAT_0101698c, stores a3 in m_iValue38, and returns this.
// @fnv 0x0043d540
FUN_0043d540_cls* FUN_0043d540_cls::FUN_0043d540(int a1, int a2, int aiValue)
{
    new ((void *)this) ::fnv_0043bd10::FUN_0043bd10((const char *)(a1), a2);
    m_pVTable = (void*)DAT_0101698c;
    m_iValue38 = aiValue;
    return this;
}

class Sub_0043d5b0
{
  public:
    unsigned int m_00;
    int Release(unsigned int flags);
};

class Base_0043d5b0
{
  public:
    virtual ~Base_0043d5b0();
};

class FUN_0043d5b0_cls : public Base_0043d5b0
{
  public:
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
    Sub_0043d5b0* m_38;
    virtual ~FUN_0043d5b0_cls();
};

// Destructor that releases the Sub_0043d5b0 stored in m_38 with flag 1 if it is non-null.
// @fnv 0x0043d5b0
FUN_0043d5b0_cls::~FUN_0043d5b0_cls()
{
    Sub_0043d5b0* copy;
    Sub_0043d5b0* tmp;
    copy = m_38;
    tmp = copy;
    tmp != 0 ? ((int)(reinterpret_cast<::FUN_0051d400_shell *>((tmp))->DeleteIfFlagged(1))) : 0;
}

class Obj43D730
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void Update();

    void FUN_0043d730();
};

// @fnv 0x0043d730
void Obj43D730::FUN_0043d730()
{
    Update();
}

// Create a temporary object from the owner, run the batch with it described by a stack packet,
// then delete the object.

class D750Object
{
  public:
    virtual ~D750Object();
};

class D750Owner
{
  public:
    D750Object* Create(int iFlags);
};

struct D750Packet
{
    int m_iFlags;
    D750Object* m_pPointer;
    void* m_pkTarget;
    D750Packet();
};

struct D750Data
{
    D750Owner* m_pkOwnerManager;
    void* m_pvArg1;
    void* m_pvArg2;
    void* m_pvArg3;
    unsigned short m_usElementCount;
    void* m_pvArg5;
    void* m_pvArg6;
};


class D750Batch
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
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    D750Data* m_pUserData;

    void CreateAndProcessObject();
};

// @fnv 0x0043d750
void D750Batch::CreateAndProcessObject()
{
    D750Object* pkObject = ((::D750Object *)(reinterpret_cast<::fnv_0051cba0::TreeBillboardBuilder *>((m_pUserData->m_pkOwnerManager))->CreateBillboardSceneObject(1)));
    if (pkObject)
    {
        D750Packet kPacket;
        kPacket.m_pkTarget = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pUserData->m_pkOwnerManager))->FUN_0084e3a0()));
        kPacket.m_pPointer = pkObject;
        kPacket.m_iFlags = 0;
        ::FUN_00b59ae0(m_pUserData->m_pvArg1, (unsigned int)(m_pUserData->m_pvArg2), (::Obj3 *)(m_pUserData->m_pvArg3), (::ObjA4 *)(::D750Packet *)(&kPacket), (::Vec3 *)(m_pUserData->m_pvArg5),
                    (float *)(m_pUserData->m_pvArg6), m_pUserData->m_usElementCount);
        delete kPacket.m_pPointer;
    }
}

extern int DAT_010169d4;

class FUN_0043d850_cls
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
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
    unsigned int m_48;
    void* m_4c;

    void FUN_0043c890(void* tmp, unsigned int a3, unsigned int a4, int one, int zero);
    FUN_0043d850_cls* FUN_0043d850(unsigned int a1, void* a2, unsigned int a3, unsigned int a4);
};

// @fnv 0x0043d850
FUN_0043d850_cls* FUN_0043d850_cls::FUN_0043d850(unsigned int a1, void* a2, unsigned int auiArg3, unsigned int auiArg4)
{
    new ((void *)this) ::fnv_0043c890::FUN_0043c890((::fnv_0043c890::QueuedModelParam *)(void *)((a2 != 0) ? (void*)((char*)a2 + 0x30) : 0), auiArg3, auiArg4, (::fnv_0043c890::FUN_0043c7a0_arg)(1), 0);
    m_ppVirtualMethodTable = (void*)&DAT_010169d4;
    m_48 = a1;
    m_4c = a2;
    m_18 = 0x1e;
    return this;
}

// UpdateStateAndNotify : save-game state update helper.
//
// The object keeps a pointer to the pending change record at +0x48.
// The method first hands the two arguments to the internal state updater
// and then, once the update counter reaches 4, notifies the global
// listener (DAT_011d5c48) about the pending record.

class SaveGameChange;  // opaque record type

class SaveGameListener
{
  public:
    void Notify(SaveGameChange* pChange);
};

// Global listener instance (defined elsewhere in the game).

struct FUN_0043dac0_cls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    SaveGameChange* m_48;


    void UpdateStateAndNotify(int aIndex, int aFlags);
};

// Calls UpdateState with aIndex and aFlags, then notifies DAT_011d5c48 with m_48 when aIndex is at least 4.
// @fnv 0x0043dac0
void FUN_0043dac0_cls::UpdateStateAndNotify(int aIndex, int aFlags)
{
    reinterpret_cast<::fnv_00c3cb70::IOTask *>(this)->FUN_00c3cb70(aIndex, (::fnv_00c3cb70::RefObj *)(aFlags));

    if (aIndex >= 4)
    {
        reinterpret_cast<::C665be0_shell *>(((*reinterpret_cast<::SaveGameListener * *>(&::fnv_0043da00::DAT_011d5c48))))->FUN_00665be0((int)(m_48));
    }
}

class B43E8B0Base
{
  public:
    B43E8B0Base(int iArg1, int iArg2);
    virtual ~B43E8B0Base();

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
};

class FUN_0043e8b0_cls : public B43E8B0Base
{
  public:
    FUN_0043e8b0_cls(int iArg1, int iArg2, int iValue38, int iValue3C);
    virtual ~FUN_0043e8b0_cls();

    int m_iValue38;
    int m_iValue3C;
};

// Base constructor runs with iArg1 and iArg2, then stores iValue38 and iValue3C into m_iValue38 and m_iValue3C.
// @fnv 0x0043e8b0
FUN_0043e8b0_cls::FUN_0043e8b0_cls(int iArg1, int iArg2, int iValue38, int iValue3C) : B43E8B0Base(iArg1, iArg2)
{
    m_iValue38 = iValue38;
    m_iValue3C = iValue3C;
}

struct SaveLoadBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;

    SaveLoadBase(unsigned int flags);
    virtual ~SaveLoadBase();
};

struct SaveLoadTarget
{
};

struct SaveLoadElemA
{
    int unk00;

    SaveLoadElemA();
    ~SaveLoadElemA();
};

struct SaveLoadElemB
{
    int unk00;

    SaveLoadElemB();
    ~SaveLoadElemB();
};

class FUN_0043ef10 : public SaveLoadBase
{
  public:
    SaveLoadTarget* m_pFlagTarget;
    SaveLoadElemA m_arrA[20];
    SaveLoadElemB m_arrB[20];
    SaveLoadElemB m_arrC[20];
    unsigned int m_11c;
    unsigned char m_120;

    FUN_0043ef10(SaveLoadTarget* target, unsigned int flags, unsigned int unused);
    virtual ~FUN_0043ef10();
};

// Initializes the base with flags, stores the target pointer, clears m_120, and sets m_11c to the target's Compute() result.
// @fnv 0x0043ef10
FUN_0043ef10::FUN_0043ef10(SaveLoadTarget* target, unsigned int flags, unsigned int unused)
    : SaveLoadBase(flags), m_pFlagTarget(target)
{
    m_120 = 0;
    m_11c = ((unsigned int)(reinterpret_cast<::FUN_0043f010 *>((m_pFlagTarget))->Get()));
}

struct SpawnedCallee
{
    void FUN_00528cb0(void* pObject);
};

struct FUN_0043f060_cls : public SpawnedCallee
{
    void FUN_0043f060();
};

// @fnv 0x0043f060
void FUN_0043f060_cls::FUN_0043f060()
{
    reinterpret_cast<::S_0042f730 *>(this)->FUN_00528cb0((::AC_0042f730 *)(void *)(0));
}

class FUN_0043f220_cls
{
  public:
    int unk00;
    void* GetEntryAt(int a1);
};

// @fnv 0x0043f220
void* FUN_0043f220_cls::GetEntryAt(int aiIndex)
{
    return (char*)this + aiIndex * 16 + 0x2c;
}

namespace fnv_0043fb10 {
struct VirtObj0043fb50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};

struct Standin0043fb50
{
    char _pad[0x18];
    VirtObj0043fb50* m_18;
};

struct Host0043fb10
{
    char _pad[0x11c];
    Standin0043fb50* m_11c;
    void FUN_00c3cb70(int, int);
    void CallWithArgsAndForwardMember(int a, int b);
};


// Calls FUN_00c3cb70 with a and b, then calls DispatchToVirtual on g_11c3b3c passing m_11c.
// @fnv 0x0043fb10
void Host0043fb10::CallWithArgsAndForwardMember(int aiArg1, int aiArg2)
{
    reinterpret_cast<::fnv_00c3cb70::IOTask *>(this)->FUN_00c3cb70(aiArg1, (::fnv_00c3cb70::RefObj *)(aiArg2));
    reinterpret_cast<::Standin0043fb50 *>(((*reinterpret_cast<::fnv_0043fb10::Standin0043fb50 * *>(&::g_modelLoader))))->DispatchToVirtual((int)m_11c);
}
}  // namespace fnv_0043fb10

struct SpawnedBase
{
    virtual ~SpawnedBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    SpawnedBase(int a1);
};

struct SubObjA
{
    int unk00;
    SubObjA(int v);
    ~SubObjA();
};

struct SubObjB
{
    int unk00;
    SubObjB(int v);
    ~SubObjB();
};

struct FUN_0043fd40 : SpawnedBase
{
    int m_28;
    SubObjA m_2c;
    SubObjB m_30;
    SubObjB m_34;
    SubObjA m_38;

    FUN_0043fd40(int a1, int a2);
    virtual ~FUN_0043fd40();
};
// Calls FUN_0043fd40 with the two arguments, sets the object's first field to point at DAT_01016ca4, and returns this.
// @fnv 0x004411d0
S4411* S4411::FUN_004411d0(int aiArg1, int aiArg2)
{
    new ((void *)this) ::FUN_0043fd40(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &DAT_01016ca4;
    return this;
}

// Constructs a SpawnedBase-derived object, storing a1 in m_28 and initializing the four sub-objects to 0.
// @fnv 0x0043fd40
FUN_0043fd40::FUN_0043fd40(int a1, int a2) : SpawnedBase(a2), m_28(a1), m_2c(0), m_30(0), m_34(0), m_38(0)
{}

class Base_b4619
{
  public:
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
    ~Base_b4619();
};

class Sub4_b4619
{
  public:
    unsigned int m_00;
    ~Sub4_b4619();
};

class SubB_b4619
{
  public:
    unsigned int m_00;
    ~SubB_b4619();
};

class SubC_b4619
{
  public:
    unsigned int m_00;
    ~SubC_b4619();
};

class FUN_0043fe40_cls : public Base_b4619
{
  public:
    Sub4_b4619 m_2c;
    SubB_b4619 m_30;
    SubC_b4619 m_34;
    Sub4_b4619 m_38;
    ~FUN_0043fe40_cls();
};
// @fnv 0x00440eb0
void FUN_00440eb0_class::FUN_00440eb0()
{
    reinterpret_cast<::FUN_0043fe40_cls *>(this)->FUN_0043fe40_cls::~FUN_0043fe40_cls();
}

// Destructor for FUN_0043fe40_cls; destroys its Base_b4619 base and the Sub4_b4619, SubB_b4619 and SubC_b4619 members.
// @fnv 0x0043fe40
FUN_0043fe40_cls::~FUN_0043fe40_cls()
{}

struct NiObjectStub;
struct NiNodeStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int IsVisible();
};
struct NiObjectStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiNodeStub* IsSceneNode();
};
struct MdlStub
{
    NiObjectStub* GetObject3D();
};
template <class T> struct NiPtr
{
    T* m_pObject;
    NiPtr(T* p);
    ~NiPtr();
    operator T*() const;
    T* operator->() const;
};
struct ModelLoaderStub
{
};

struct ModelSourceStub
{
};

struct AttachTaskStub
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
    virtual void Attach(NiNodeStub*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    ModelSourceStub* pSource;
    void AttachModelFromSource();
};

// @fnv 0x00440190
void AttachTaskStub::AttachModelFromSource()
{
    NiNodeStub* pNode = 0;
    char acPath[264];
    ::FUN_00489190(acPath, (::TESForm *)(((const char *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pSource))->FUN_007af430()))));
    NiPtr<MdlStub> spLoaded(0);
    reinterpret_cast<::FUN_004472a0_shell *>((((ModelLoaderStub*)g_modelLoader)))->FUN_004472a0(acPath, (void *)&(spLoaded));
    if (spLoaded && spLoaded->GetObject3D())
    {
        NiObjectStub* pClonedObject = ((::NiObjectStub *)(reinterpret_cast<::CloneSourceA5d6 *>((spLoaded->GetObject3D()))->FUN_00a5d680()));
        if (pClonedObject)
        {
            pNode = pClonedObject->IsSceneNode();
            if (!pNode)
            {
                (NiPtr<NiObjectStub>(pClonedObject));
            }
            else if (pNode->IsVisible())
            {
                reinterpret_cast<::FUN_00b4dec0_shell *>((pNode))->FUN_00b4dec0(6);
            }
        }
    }
    if (pNode)
    {
        Attach(pNode);
    }
}

enum B4404C0Priority
{
    B4404C0_PRIORITY_CRITICAL = 0
};

class B4404C0Task
{
  public:
    B4404C0Task(B4404C0Priority ePriority);
    virtual ~B4404C0Task();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct B4404C0Handle
{
    int m_iValue;

    void Set(int iValue);
};

class FUN_004404c0 : public B4404C0Task
{
  public:
    void* m_pvTarget;
    B4404C0Handle m_kHandle;

    FUN_004404c0(void* pvTarget, int iHandle);
    virtual ~FUN_004404c0();
};

// Constructs a critical-priority task storing the target pointer and setting the handle to the given value.
// @fnv 0x004404c0
FUN_004404c0::FUN_004404c0(void* pvTarget, int iHandle) : B4404C0Task(B4404C0_PRIORITY_CRITICAL)
{
    m_pvTarget = pvTarget;
    new ((void *)&(m_kHandle)) ::FUN_00633c90((::G00559a40 *)(iHandle));
}

struct PriorityKey
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned __int64 key;
    void FUN_004405d0(unsigned char priority);
};
// @fnv 0x004405b0
void FUN_004405b0_S::FUN_004405b0(unsigned char p)
{
    reinterpret_cast<::PriorityKey *>(this)->FUN_004405d0(p);
}

// Replaces the priority byte stored in bits 16-23 of key, preserving all other bits.
// @fnv 0x004405d0
void PriorityKey::FUN_004405d0(unsigned char priority)
{
    key = (key & 0xffffffffff00ffffui64) + ((__int64)priority << 16);
}

class SaveBase_b3799
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    ~SaveBase_b3799();
};

class SaveSub_b3799
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ~SaveSub_b3799();
};

class FUN_004406b0 : public SaveBase_b3799
{
  public:
    SaveSub_b3799 m_1c;
    ~FUN_004406b0();
};
// Calls FUN_004406b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00440680
void* AttachDistant3DTask::FUN_00440680(unsigned int flags)
{
    reinterpret_cast<::FUN_004406b0 *>(this)->FUN_004406b0::~FUN_004406b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004406b0
FUN_004406b0::~FUN_004406b0()
{}


class B40DC0Base
{
  public:
};

class B40DC0Ref
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
    virtual const char* GetEditorID();

};

class B40DC0Task
{
  public:
    bool FormatQueuedRefDescription(char* pcBuffer, unsigned int uiSize);

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
    B40DC0Ref* m_pkRef;
};

// If the task is not complete, formats the queued ref's editor ID, form ID and base object type name into pcBuffer and returns true; otherwise returns false.
// @fnv 0x00440dc0
bool B40DC0Task::FormatQueuedRefDescription(char* pcBuffer, unsigned int uiSize)
{
    if (::FUN_00449130((int *)this))
        return false;
    ::FUN_00406d00(pcBuffer, uiSize, "Queued ref '%s' (%08X) of type %s", m_pkRef->GetEditorID(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pkRef))->FUN_0084e3a0())),
               ((const char *)(reinterpret_cast<::FUN_00440e30_This *>((((::B40DC0Base *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pkRef))->FUN_007af430()))))->FUN_00440e30())));
    return true;
}

struct Node1;
struct Node2;
struct Node3;
struct Node4;
struct Node5;
struct Node0
{
};
struct Node1
{
};
struct Node2
{
};
struct Node3
{
};
struct Node4
{
    void FUN_00a67050(int);
};
struct Node5
{
};
struct Owner
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34(Node2*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Node0* unk28;
    void FUN_00440fd0();
};
// @fnv 0x00440fd0
void Owner::FUN_00440fd0()
{
    Node1* node1 = ((::Node1 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((unk28))->FUN_007af430()));
    Node2* node2 = ((::Node2 *)(reinterpret_cast<::fnv_0051cba0::TreeBillboardBuilder *>((node1))->CreateBillboardSceneObject(0)));
    if (node2)
    {
        Node3* node3 = ((::Node3 *)(reinterpret_cast<::NiNode *>((node2))->GetAt(0)));
        Node4* status = ((::Node4 *)(::fnv_005495f0::FUN_005495f0((const char *)(node3))));
        status->FUN_00a67050(0x4000);
        reinterpret_cast<::FUN_004410d0_Class *>((status))->SetByteAtOffset38(0x11);
        reinterpret_cast<::NiGeometryData *>((status))->SetCompressFlags(1);
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(node3), 0, 0);
        Node5* action = (((::Node5 *)(reinterpret_cast<::FUN_00a59d30_C *>((node3))->FUN_00a59d30(3))) == 0 ? false : ((int)(reinterpret_cast<::BGSTerrainManager *>((((::Node5 *)(reinterpret_cast<::FUN_00a59d30_C *>((node3))->FUN_00a59d30(3)))))->GetMinLevel())) == 0xb)
                            ? ((::Node5 *)(reinterpret_cast<::FUN_00a59d30_C *>((node3))->FUN_00a59d30(3)))
                            : 0;
        if (action)
        {
            ::FUN_00441130((char *)(action), (::UW)(13), (::BW)(1));
            ::FUN_00441130((char *)(action), (::UW)(22), (::BW)(1));
        }
        vfn_34(node2);
    }
}

namespace fnv_004420b0 {
struct SpawnedBase
{
    virtual ~SpawnedBase();
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

    SpawnedBase(int a1, int a2);
};

struct SubObjA
{
    int unk00;
    SubObjA(int v);
    ~SubObjA();
};

struct SubObjB
{
    int unk00;
    SubObjB(int v);
    ~SubObjB();
};

struct FUN_004420b0 : SpawnedBase
{
    SubObjA m_kPointA;
    SubObjB m_kPointB;

    FUN_004420b0(int a1, int a2);
    virtual ~FUN_004420b0();
};

// @fnv 0x004420b0
FUN_004420b0::FUN_004420b0(int a1, int a2) : SpawnedBase(a1, a2), m_kPointA(0), m_kPointB(0)
{}
}  // namespace fnv_004420b0

class C4422C0Object
{
  public:
    virtual ~C4422C0Object();
};

class C4422C0Base
{
  public:
    virtual ~C4422C0Base();

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
};

class FUN_004422c0 : public C4422C0Base
{
  public:
    virtual ~FUN_004422c0();

    C4422C0Object* m_pPointer;
};
// Calls FUN_004422c0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00442290
void* BackgroundCloneThread::FUN_00442290(unsigned int flags)
{
    reinterpret_cast<::FUN_004422c0 *>((this))->FUN_004422c0::~FUN_004422c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004422c0
FUN_004422c0::~FUN_004422c0()
{
    delete m_pPointer;
}

struct FUN_00444540_Scope
{
    unsigned int m_00;
    FUN_00444540_Scope(int mode);
    ~FUN_00444540_Scope();
};

class FUN_00444540_cls
{
  public:
    unsigned int m_00;
    void DispatchWithScope(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e);
};

struct S_004445c0_Obj
{
    S_004445c0_Obj(int a, int b, int c, int d);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
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
};
struct S_004445c0_Ptr
{
    S_004445c0_Obj* m_pObject;
    S_004445c0_Ptr(S_004445c0_Obj* p);
    ~S_004445c0_Ptr();
    S_004445c0_Obj* operator->() const;
};
struct S_004445c0_Dest
{
};
struct S_004445c0_This
{
    void FUN_004445c0(int a1, int a2, S_004445c0_Dest* a3, int a4, int a5, int a6);
};
// Creates a scope object with mode 0 and forwards all arguments to Dispatch.
// @fnv 0x00444540
void FUN_00444540_cls::DispatchWithScope(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e)
{
    FUN_00444540_Scope scope(0);
    reinterpret_cast<::S_004445c0_This *>(this)->FUN_004445c0(a, b, (::S_004445c0_Dest *)&(scope), c, d, e);
}
// Allocates an object from the given arguments, calls FUN_00443aa0 and v8 on it, then passes it to FUN_0092c820 on the destination.
// @fnv 0x004445c0
void S_004445c0_This::FUN_004445c0(int aiArg1, int aiArg2, S_004445c0_Dest* pDest, int aiArg4, int aiArg5, int aiArg6)
{
    S_004445c0_Ptr sp(new S_004445c0_Obj(aiArg1, aiArg2, aiArg4, aiArg6));
    reinterpret_cast<::QueuedFile *>(((sp).operator->()))->SetParent((::QueuedFile *)(aiArg5));
    sp->v8();
    reinterpret_cast<::NP_0092c820 *>((pDest))->FUN_0092c820((const ::NP_0092c820 &)(sp));
}

struct MemCtx
{
    int m;
    MemCtx(int a, int b, const char* file, int line);
    ~MemCtx();
};
struct Obj3D
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void SetX(int);  // 0x1c
    virtual void Y();        // 0x20
};
struct RefPtr
{
    void* m;
    RefPtr(void*);
    ~RefPtr();
};
struct Base3D
{
    int FUN_00401170();
};
struct Proc
{
};
struct Ref
{
    char pad[0x224];
};
struct RefV
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void w77();
    virtual void w78();
    virtual void w79();
    virtual void w80();
    virtual void w81();
    virtual void w82();
    virtual void w83();
    virtual void w84();
    virtual void w85();
    virtual void w86();
    virtual void w87();
    virtual void w88();
    virtual void w89();
    virtual void w90();
    virtual void w91();
    virtual void w92();
    virtual void w93();
    virtual void w94();
    virtual void w95();
    virtual void w96();
    virtual void w97();
    virtual void w98();
    virtual void w99();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void w107();
    virtual void w108();
    virtual void w109();
    virtual void w110();
    virtual void w111();
    virtual void w112();
    virtual void w113();
    virtual void w114();
    virtual void w115();
    virtual void w116();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual void w125();
    virtual void w126();
    virtual void w127();
    virtual void w128();
    virtual void w129();
    virtual void w130();
    virtual void w131();
    virtual void w132();
    virtual void w133();
    virtual void w134();
    virtual void w135();
    virtual void w136();
    virtual bool IsX();
};
struct Queue
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(Ref*, RefPtr*);  // 0x8
    virtual void v3();
    virtual bool Add(Ref*, RefPtr*, bool);  // 0x10
};
struct Mgr
{
};
struct G1
{
};
struct TaskA
{
    char d[72];
    TaskA(int);
    void* operator new(unsigned int);
};
struct TaskB
{
    char d[64];
    TaskB(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskC
{
    char d[72];
    TaskC(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskD
{
    char d[64];
    TaskD(Ref*, int);
    void* operator new(unsigned int);
};
struct TaskE
{
    char d[64];
    TaskE(Ref*, int);
    void* operator new(unsigned int);
};

int FUN_0040fc90();

struct ML
{
    int unk0, unk4;
    Queue* q8;
    Queue* qc;
    void FUN_00444850(Ref* ref, int a2, bool a3);
};

// Checks manager and ref state, updates or creates a queued load task for ref, then adds it to q8 and optionally qc.
// @fnv 0x00444850
void ML::FUN_00444850(Ref* ref, int aiValue, bool a3)
{
    if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::Mgr * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() && !reinterpret_cast<::BGSSaveLoadGame *>(((*reinterpret_cast<::Mgr * *>(&::g_BGSSaveLoadGame))))->GetInitingForms())
        return;
    if (((::Base3D *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FUN_00401170() == 0xd)
        return;
    if (((RefV*)ref)->IsX())
    {
        Ref* r = ref;
        if (reinterpret_cast<::FUN_00444d00_Class *>((r))->FUN_00444d00(2))
            return;
    }
    RefPtr p(0);
    if (q8->Lookup(ref, &p))
    {
        int v = reinterpret_cast<::FUN_0043cc60_shell *>((((::Obj3D *)(::FUN_00559450((int *)&(p))))))->FUN_0043cc60();
        if (v != aiValue)
            ((::Obj3D *)(::FUN_00559450((int *)&(p))))->SetX(aiValue);
        return;
    }
    MemCtx memCtx(0x31, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc4e);
    if (ref == (*reinterpret_cast<::Ref * *>(&::_g_thePlayer)))
    {
        MemCtx c2(0x34, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc53);
        reinterpret_cast<::FUN_006f74f0_cls *>(&(p))->FUN_006f74f0((::ObjA *)(void *)(new TaskA(aiValue)));
    }
    else
    {
        switch (((::Base3D *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FUN_00401170())
        {
        case 0x25: {
            reinterpret_cast<::FUN_006f74f0_cls *>(&(p))->FUN_006f74f0((::ObjA *)(void *)(new TaskB(ref, aiValue)));
            break;
        }
        case 0x2a: {
            MemCtx memCtx3(0x32, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc6b);
            reinterpret_cast<::FUN_006f74f0_cls *>(&(p))->FUN_006f74f0((::ObjA *)(void *)(new TaskC(ref, aiValue)));
            break;
        }
        case 0x2b: {
            MemCtx memCtx4(0x32, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xc72);
            reinterpret_cast<::FUN_006f74f0_cls *>(&(p))->FUN_006f74f0((::ObjA *)(void *)(new TaskD(ref, aiValue)));
            break;
        }
        default: {
            reinterpret_cast<::FUN_006f74f0_cls *>(&(p))->FUN_006f74f0((::ObjA *)(void *)(new TaskE(ref, aiValue)));
            break;
        }
        }
    }
    if (q8->Add(ref, &p, false))
    {
        bool b = false;
        if (a3 && FUN_0040fc90() == ((int)(reinterpret_cast<::MagicCaster_shell *>(((*reinterpret_cast<::G1 * *>(&::g_osGlobals))))->FUN_0044edb0())) && !FUN_00702360())
            b = true;
        if (b)
            qc->Add(ref, &p, true);
        else
            ((::Obj3D *)(::FUN_00559450((int *)&(p))))->Y();
        if (((::Proc *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())))
        {
            ::InitScriptRunLockForObject((char *)(((::Proc *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()))));
            if (reinterpret_cast<::FUN_00572350_shell *>((ref))->FUN_00572350())
                ::FUN_00444ce0((char *)(((::Proc *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()))));
        }
    }
    else
    {
        reinterpret_cast<::FUN_006f74f0_cls *>(&(p))->FUN_006f74f0((::ObjA *)(void *)(0));
    }
}

namespace fnv_00445370 {
class TargetObj
{
  public:
    virtual void v00();
    virtual void v04();
    virtual bool v08(unsigned int a, TargetObj** out);
    virtual void v0c();
    virtual void v10();
    virtual void v14(unsigned int a);
    void FinishScriptRunLockIfActive();
};


class FUN_00445370_cls
{
  public:
    void* m_00;
    TargetObj* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    unsigned char m_2c;
    void FUN_00445370(uintptr_t a1, bool flag);
};

// @fnv 0x00445370
void FUN_00445370_cls::FUN_00445370(uintptr_t a1, bool flag)
{
    TargetObj* p = 0;
    if (this->m_04->v08(a1, &p))
    {
        p->FinishScriptRunLockIfActive();
        if ((*reinterpret_cast<::fnv_00445370::TargetObj * *>(&::g_BGSSaveLoadGame)) != 0 && reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00445370::TargetObj * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
        {
            flag = false;
            this->m_2c = 1;
        }
        if (flag)
        {
            if (::FUN_004431b0((int *)(p)) == 0)
            {
                this->m_04->v14(a1);
                TargetObj* a = p;
                TargetObj* aQ = a;
                (aQ != 0) ? ((int)(reinterpret_cast<::fnv_00443240::p07::DelStandIn *>((aQ))->FUN_00443240(1))) : 0;
            }
        }
    }
}
}  // namespace fnv_00445370

struct AC_0042f730;

class SaveTmp_b9539
{
  public:
    AC_0042f730* m_pObject;
    SaveTmp_b9539(AC_0042f730* pObject);
    ~SaveTmp_b9539();
    int Get(int n);
};

struct IOCall_b9539
{
};

class SaveCaller_b9539
{
  public:
    virtual void v0();
    virtual void v1();
    virtual bool v2(int a, SaveTmp_b9539* pTmp);
};

class SaveOwner_b9539
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    SaveCaller_b9539* m_10;
    void FUN_004454d0(int a);
};

class B445670Cell;

class B445670Ref
{
  public:
};

class B445670Cell
{
  public:
};

class B445670Iterator
{
  public:
    B445670Iterator();
    ~B445670Iterator();

    int m_iIndex;
    int m_iArrayLength;
    int m_iBucket;
    void* m_pvCurrent;
};

class B445670Handle
{
  public:
    B445670Handle(void* pvObject);
    ~B445670Handle();

    void* m_pvObject;
};

class B445670Table
{
  public:
};

class B445670Loader
{
  public:
    void FUN_00445570(B445670Ref* pkRef);
    void FUN_00445670(B445670Cell* pkCell);

    int unk00;
    int unk04;
    B445670Table* m_pkTable;
};

// Iterates the table and calls FUN_00445570 on each ref whose parent cell is pkCell, after checking the cell has loaded data.
// @fnv 0x00445670
void B445670Loader::FUN_00445670(B445670Cell* pkCell)
{
    if (!pkCell || !((void *)(reinterpret_cast<::FUN_005e3fc0_shell *>((pkCell))->Get())))
        return;

    B445670Iterator kIter;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(kIter))->FUN_006ebde0())
    {
        B445670Ref* pkRef = 0;
        B445670Handle kHandle2(0);
        if (reinterpret_cast<::FUN_00906570_Class *>((m_pkTable))->AdvanceRequest((::Request9065 *)(::B445670Iterator *)(&kIter), (void **)(::B445670Ref **)(&pkRef), &kHandle2, 1))
        {
            if (((::B445670Cell *)(reinterpret_cast<::LowProcess *>((pkRef))->GetTarget())) == pkCell)
                FUN_00445570(pkRef);
        }
    }
}


struct CreatureData114
{
};

class TESCreature : public TESModel
{
  public:
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
    CreatureData114 data114;
};

struct ItemEntry
{
    ~ItemEntry();
    int unk00;
};

class TESObjectREFR;
struct InventoryChanges
{
public:
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
};

struct ModelLoaderHelper445
{
    void FUN_004457d0(TESModel* model, int a, int b, void* ref);
};

int strcat_s(char* dst, unsigned int size, const char* src);

struct KFQueueOwner
{
};

struct ModelLoaderKFList : public ModelLoader
{
    void QueueKFPathsFromList(BSSimpleList<const char*>* list, KFQueueOwner* owner, int priority, void* queued,
                              const char* prefix);
};

struct IndexedValueTable
{
    unsigned int count;
    unsigned int* values;
    unsigned int GetValueAt(unsigned int index);
};
// Walks a list of names, optionally prefixes each into a path buffer, and queues each KF path either via owner tasks or directly.
// @fnv 0x004463b0
void ModelLoaderKFList::QueueKFPathsFromList(BSSimpleList<const char*>* apNames, KFQueueOwner* owner, int priority,
                                             void* queued, const char* prefix)
{
    BSSimpleList<const char*>* iter = apNames;
    int index = 0;
    while (iter)
    {
        const char* name = ((const char *)(new ((void *)(iter)) ::Vec3()));
        if (name)
        {
            char path[260];
            if (prefix)
            {
                ::TaskQueueInterface::CopyStringToBuffer(path, 260, prefix);
                strcat_s(path, 260, name);
                name = path;
            }
            if (owner)
            {
                reinterpret_cast<::C4442C0Queue *>(this)->QueueFullWithNullResult((int)(name), (int)(((void *)(reinterpret_cast<::IndexedValueTable *>((owner))->GetValueAt(index)))), priority, (int)(queued), 0, 1, 0, 0);
            }
            else
            {
                reinterpret_cast<::QueueHelper *>(this)->FUN_00444040((int)(name), priority, (int)(queued), 0, 1, 0, 0);
            }
        }
        index++;
        iter = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(iter))->FUN_00726070()));
    }
}

// Returns values[index] when index is below count, otherwise returns 0.
// @fnv 0x004464c0
unsigned int IndexedValueTable::GetValueAt(unsigned int index)
{
    return index < count ? values[index] : 0;
}

class FUN_004469c0_base
{
  public:
    FUN_004469c0_base(unsigned int);
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    unsigned int unk04[9];
};

class FUN_004469c0 : public FUN_004469c0_base
{
  public:
    FUN_004469c0(unsigned int a, unsigned int b);
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
};

// Constructs the object, forwarding b to the base constructor and initializing m_28 with a while zeroing m_2c and m_30.
// @fnv 0x004469c0
FUN_004469c0::FUN_004469c0(unsigned int auiValue, unsigned int auiBaseArg) : FUN_004469c0_base(auiBaseArg)
{
    m_28 = auiValue;
    m_2c = 0;
    m_30 = 0;
}

class FUN_00448330_Target
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual unsigned char vfn_10(unsigned int a1, unsigned int* pa2, bool flag);
};

class FUN_00448330_cls
{
  public:
    unsigned int unk00[9];
    FUN_00448330_Target* m_pFlagTarget;
    unsigned char DispatchVirtualCall(unsigned int a1, unsigned int a2);
};

// @fnv 0x00448330
unsigned char FUN_00448330_cls::DispatchVirtualCall(unsigned int auiArg, unsigned int a2)
{
    unsigned char r = m_pFlagTarget->vfn_10(auiArg, &a2, false);
    return r;
}

class FUN_004483a0_holder
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual bool vfn_08(unsigned int arg, unsigned int* out);
};

class FUN_004483a0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    FUN_004483a0_holder* m_pHolder;
    unsigned int GetHolderValue(unsigned int arg);
};

// Calls m_pHolder->vfn_08 with arg and an output slot, returning the output value if it succeeds, otherwise 0.
// @fnv 0x004483a0
unsigned int FUN_004483a0_cls::GetHolderValue(unsigned int arg)
{
    unsigned int out = 0;
    if (m_pHolder->vfn_08(arg, &out))
    {
        return out;
    }
    return 0;
}

struct B449Entry
{
};

class B449Map
{
  public:
    B449Entry* FUN_00449f80(void* pKey, int iIndex);
    bool FUN_004498b0(void* pKey, int iIndex);
};

void FUN_0044ada0(unsigned char value);

struct QueuedTask
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Run(int eState, int arg);
    int unk04;
    int unk08;
    int eState;
    void FUN_0092c870();
    void FUN_0044dd60();
};

struct TaskProcessor
{
    void FUN_0044ac40(QueuedTask* pTask, int arg);
};
// @fnv 0x004454d0
void SaveOwner_b9539::FUN_004454d0(int a)
{
    SaveTmp_b9539 tmp(0);
    if (this->m_10->v2(a, &tmp))
    {
        reinterpret_cast<::TaskProcessor *>((reinterpret_cast<IOCall_b9539*>(::DAT_01202d98)))->FUN_0044ac40((::QueuedTask *)(::FUN_00559450((int *)&(tmp))), {});
    }
}

// @fnv 0x0044ac40
void TaskProcessor::FUN_0044ac40(QueuedTask* pTask, int arg)
{
    FUN_0044ada0(0);
    while (true)
    {
        int eState = pTask->eState;
        switch (eState)
        {
        case 0:
            if (reinterpret_cast<::FUN_00449190_cls *>((pTask))->SetState(eState, 6))
            {
                pTask->Run(eState, arg);
                return;
            }
            break;
        case 1:
            if (reinterpret_cast<::FUN_00449190_cls *>((pTask))->SetState(eState, 6))
            {
                reinterpret_cast<::FUN_0092c870_shell *>((pTask))->FUN_0092c870();
                reinterpret_cast<::FUN_00c3fca0_Class *>(this)->FUN_0044e050((::InputValues *)(pTask));
                pTask->Run(eState, arg);
                pTask->FUN_0044dd60();
                return;
            }
            break;
        case 2:
            while (pTask->eState == 3)
            {
                FUN_0040fca0(0);
            }
            break;
        case 3:
            while (pTask->eState == 3)
            {
                FUN_0040fca0(0);
            }
            break;
        case 4:
            while (pTask->eState == 4)
            {
                FUN_0040fca0(0);
            }
            break;
        case 5:
            if (reinterpret_cast<::FUN_00449190_cls *>((pTask))->SetState(eState, 6))
            {
                pTask->Run(eState, arg);
                return;
            }
            break;
            return;
        default:
            return;
        }
    }
}

struct Entry44
{
    int unk00;
    int unk04;
    long unk08;
};

struct Slot44
{
    int m_val;
    int GetHead();
    Entry44* GetEntry();
};

struct TP44
{
    int m_p;
    TP44(bool b, int p);
    operator long() const;
};

bool __cdecl FUN_004491c0(long volatile* param_1, long param_2, long param_3);

struct Obj44
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    long volatile* unk10;
    Slot44 unk14;
    Slot44 unk18;
    void Finish(int p);
    void Release();
    bool TryInsertAndFinish(int a, int b);
};

class FUN_0044df40_PtrHolder
{
  public:
    unsigned int m_00;
    FUN_0044df40_PtrHolder(unsigned int init);
    ~FUN_0044df40_PtrHolder();
};

class FUN_0044df40_Plain
{
  public:
    FUN_0044df40_Plain();
};

class FUN_0044df40_cls
{
  public:
    unsigned int m_00;
    FUN_0044df40_PtrHolder m_04;
    FUN_0044df40_Plain m_08;
    FUN_0044df40_cls(unsigned int a1, const void* a2);
};

// @fnv 0x0044df40
FUN_0044df40_cls::FUN_0044df40_cls(unsigned int uiValue, const void* pPointer) : m_04(0), m_08()
{
    m_00 = uiValue;
    reinterpret_cast<::NP_0092c820 *>(&(m_04))->FUN_0092c820((*(const ::NP_0092c820 *)(pPointer)));
}

class LoaderNode;
class LoaderEntryA;
class LoaderEntryB;



class LoaderEntryA
{
  public:
};

class LoaderEntryB
{
  public:
};

class LoaderNode
{
  public:
};

class FUN_004f05c0_cls
{
  public:
    LoaderNode* First();
    void ApplyFlagsToEntries(unsigned int flags);
};

// Iterates the node list from First(), looks up two entries per node via FUN_00653270 and calls Method(flags) on each non-null entry.
// @fnv 0x004f05c0
void FUN_004f05c0_cls::ApplyFlagsToEntries(unsigned int flags)
{
    for (LoaderNode* node = First(); node != 0; node = ((::LoaderNode *)(::fnv_004a8a90::FUN_004a8a90((char *)(node)))))
    {
        LoaderEntryA* a = (LoaderEntryA*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<unsigned char *>(&::g_011f36bc))), (::NiObject *)(node))));
        LoaderEntryB* b = (LoaderEntryB*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<unsigned char *>(&::g_011f36e4))), (::NiObject *)(node))));
        if (a != 0)
        {
            reinterpret_cast<::fnv_004f0640::NiInterpController *>((a))->FUN_004f0640((::fnv_004f0640::NiAVObject *)(flags));
        }
        if (b != 0)
        {
            reinterpret_cast<::FUN_00a35910_shell *>((b))->FUN_004f06d0((::NiAVObject *)(flags));
        }
    }
}

class QueueCursor
{
  public:
    QueueCursor();
    ~QueueCursor();
    void* m_pCurrent;
};

class QueueSlot
{
  public:
    QueueSlot(int flag);
    ~QueueSlot();
    void* m_pInventoryEntryData;
};

class QueueSubmitter
{
  public:
};

class FUN_00527fc0_cls
{
  public:
    void SubmitQueuedItems();
};

// Iterates the cursor until it reaches the end, calling Step on each slot and submitting the taken item through the submitter at DAT_01202d98 when Step succeeds.
// @fnv 0x00527fc0
void FUN_00527fc0_cls::SubmitQueuedItems()
{
    unsigned int pad[3];
    {
        QueueCursor cursor;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(cursor))->FUN_006ebde0())
        {
            int index = 0;
            QueueSlot slot7(0);
            if (reinterpret_cast<::FUN_00906570_Class *>((this))->AdvanceRequest((::Request9065 *)(::QueueCursor *)(&cursor), (void **)(int *)(&index), &slot7, 1))
            {
                reinterpret_cast<::TaskProcessor *>((reinterpret_cast<QueueSubmitter*>(::DAT_01202d98)))->FUN_0044ac40((::QueuedTask *)(void *)(((void *)(::FUN_00559450((int *)&(slot7))))), {});
            }
        }
    }
}

class AC_00528080_obj;


class SaveLoadCallLocal
{
  public:
    AC_00528080_obj* m_pObject;
    SaveLoadCallLocal(AC_00528080_obj* pObject);
    ~SaveLoadCallLocal();
};

class SaveLoadCallerShell
{
  public:
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int handle, SaveLoadCallLocal* pLocal);
    bool CallSaveLoadWithHandle(unsigned short a, unsigned short b);
};

// Computes a handle from two 16-bit values, wraps a null object in a local, and passes both to the virtual v2 call.
// @fnv 0x00528080
bool SaveLoadCallerShell::CallSaveLoadWithHandle(unsigned short ausValue1, unsigned short ausValue2)
{
    unsigned int handle = ((unsigned int)(::PackShortPair(ausValue1, ausValue2)));
    SaveLoadCallLocal local(0);
    return this->v2(handle, &local);
}

class FUN_00529000_cls
{
  public:
    void* unk00;
    unsigned int* m_04;
    unsigned int* m_08;
    unsigned int* m_0C;
    void FUN_00529000();
};

// Sets the three unsigned int values pointed to by m_04, m_08 and m_0C to zero.
// @fnv 0x00529000
void FUN_00529000_cls::FUN_00529000()
{
    *m_04 = 0;
    *m_08 = 0;
    *m_0C = 0;
}

struct Z_00626c50
{
};

struct Y_00626c50
{
    void FUN_00626cb0();
};

struct Mgr_00626c50
{
    unsigned int unk00;
    unsigned int unk04;
};

struct Local_00626c50
{
    unsigned int v;
};

struct FUN_00626c50_cls
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    Mgr_00626c50 m_3a0;
    unsigned int m_3a8;
    void FUN_00626c50(unsigned int a1);
};

// Stores a1 in m_3a8, passes it to local.FUN_0059ce80, and calls FUN_0043b4f0/FUN_00626cb0 on objects obtained from m_3a0.FUN_00559450.
// @fnv 0x00626c50
void FUN_00626c50_cls::FUN_00626c50(unsigned int auiValue)
{
    Local_00626c50 local;
    reinterpret_cast<::W_0043b4f0 *>((reinterpret_cast<Z_00626c50*>(((void *)(::FUN_00559450((int *)&(m_3a0)))))))->FUN_0043b4f0();
    reinterpret_cast<::FUN_0059ce80_shell *>(&(local))->FUN_0059ce80(auiValue);
    m_3a8 = auiValue;
    reinterpret_cast<Y_00626c50*>(((void *)(::FUN_00559450((int *)&(m_3a0)))))->FUN_00626cb0();
}

class C1C50Filter
{
  public:
    C1C50Filter();

    void SetLayer(unsigned int uiLayer);

    unsigned int m_uiFilterInfo;
};

class C1C50HkObject
{
  public:
    C1C50Filter GetFilter();
    void SetFilter(C1C50Filter kFilter);
};

class C1C50WorldObject
{
  public:
    void FUN_00631c50(unsigned int uiLayer);

    int unk00;
    int unk04;
    unsigned int m_uiLayer;
};

// Sets the layer on the filter obtained from GetHkObject, stores it in m_uiLayer, and writes the filter back.
// @fnv 0x00631c50
void C1C50WorldObject::FUN_00631c50(unsigned int uiLayer)
{
    C1C50Filter kFilter = ((::C1C50HkObject *)(::FUN_00559450((int *)this)))->GetFilter();
    reinterpret_cast<::FUN_0059ce80_shell *>(&(kFilter))->FUN_0059ce80(uiLayer);
    m_uiLayer = uiLayer;
    ((::C1C50HkObject *)(::FUN_00559450((int *)this)))->SetFilter(kFilter);
}

struct QueryResult
{
};
struct QueryObject
{
};
// @fnv 0x006570e0
void __cdecl FUN_006570e0(QueryObject* apQueryObject)
{
    char firstPath[264];
    char secondPath[264];
    reinterpret_cast<::TESRace *>((((::QueryResult *)(reinterpret_cast<::FUN_004ac110_shell *>((apQueryObject))->FUN_004ac110()))))->BuildBodyTexturePath({}, {});
    reinterpret_cast<::fnv_006148f0::FUN_006148f0_shell *>((((::QueryResult *)(reinterpret_cast<::FUN_004ac110_shell *>((apQueryObject))->FUN_004ac110()))))->BuildBodyModTexturePath({}, {}, {});
    ::FUN_00a61fb0(firstPath);
}

struct SyncNode
{
    int unk00;
    int unk04;
    int state;
};
struct NodeLink
{
    SyncNode* value;
    SyncNode* ClearLowBit();
    SyncNode* FUN_0044df00();
};
struct StateValue
{
    int value;
    void FUN_006ecba0(bool, SyncNode*);
};
struct Controller
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void Update();
};
struct Worker
{
    Controller* controller;
    int unk04;
    int unk08;
    int unk0c;
    int* state;
    NodeLink current;
    NodeLink pending;
    bool ProcessNodeChain(int, int);
    bool AdvanceState(int, int);
};
// Loops while ProcessNodeChain holds, compares pending/current state values via FUN_004491c0, updates the controller and returns whether a step succeeded.
// @fnv 0x00666080
bool Worker::AdvanceState(int aiArg1, int aiArg2)
{
    bool result = false;
    while (true)
    {
        if (!ProcessNodeChain(aiArg1, aiArg2))
        {
            result = false;
            break;
        }
        StateValue after;
        reinterpret_cast<::FUN_006ecba0_class *>(&(after))->FUN_006ecba0(false, pending.ClearLowBit());
        StateValue now;
        reinterpret_cast<::FUN_006ecba0_class *>(&(now))->FUN_006ecba0(true, pending.ClearLowBit());
        if (!::FUN_004491c0((volatile long *)(int *)(&current.FUN_0044df00()->state), ::FUN_00559450((int *)&(now)), ::FUN_00559450((int *)&(after))))
            continue;
        StateValue before;
        reinterpret_cast<::FUN_006ecba0_class *>(&(before))->FUN_006ecba0(false, current.ClearLowBit());
        if (::FUN_004491c0((volatile long *)(state), ::FUN_00559450((int *)&(after)), ::FUN_00559450((int *)&(before))))
            reinterpret_cast<::fnv_00666510::FUN_00666510_Class *>(this)->AddRace((::fnv_00666510::TESRaceForm *)(::SyncNode *)(current.ClearLowBit()));
        else
            ProcessNodeChain(aiArg1, aiArg2);
        controller->Update();
        result = true;
        break;
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return result;
}

struct FUN_006ec830_target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int Call(int a, int b, int c);
};

struct FUN_006ec830_cls
{
    FUN_006ec830_target* m_00;
    int InvokeWithArgs(int a1, int a2);
};
// Looks up the entry for pKey and iIndex and returns the result of its InvokeWithArgs check.
// @fnv 0x004498b0
bool B449Map::FUN_004498b0(void* pKey, int iIndex)
{
    bool bResult = ((bool)(reinterpret_cast<::FUN_006ec830_cls *>((FUN_00449f80(pKey, iIndex)))->InvokeWithArgs({}, {})));
    return bResult;
}

// Calls the virtual Call method on m_00 with a1 twice and a2, then passes the result to FUN_006ec9b0 and returns it.
// @fnv 0x006ec830
int FUN_006ec830_cls::InvokeWithArgs(int aiArg1, int aiArg2)
{
    return ((int)(reinterpret_cast<::FUN_006ec9b0_Class *>(this)->FUN_006ec9b0(m_00->Call(aiArg1, aiArg1, aiArg2), {}, {})));
}

namespace fnv_00906af0 {
struct QH_0092c820
{
    void FUN_0044dd60();
    void FUN_0092c870();
};
struct NP_0092c820
{
    QH_0092c820* m_pObject;
};


struct IntegerMapEntry
{
    int key;
    NP_0092c820 value;
    bool IsOccupied();
};

struct TaggedEntry
{
    int m_bits;
    int GetPixelBitData();
    IntegerMapEntry* GetEntry();
};

struct EntryRef
{
    int m_uiFilterValue;
    int Get() const;
};

struct LocalRef
{
    void* m_p;
    void* Init(bool b, void* p);
    int Get() const;
};

struct QueueOwner
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
    virtual void Process(int key, int arg);
    TaggedEntry* Lookup(int index);
};

struct QueueWalker
{
    QueueOwner* m_pOwnerObject;
    int unk04;
    int* m_out;
    int unk0c;
    TaggedEntry* m_ref;
    TaggedEntry m_entry;
    void Finish();
    bool ProcessEntry(int index, int arg, NP_0092c820* dest);
};

// @fnv 0x00906af0
bool QueueWalker::ProcessEntry(int index, int arg, NP_0092c820* dest)
{
    bool result = false;
    while (1)
    {
        LocalRef local;
        TaggedEntry* entry = ((::fnv_00906af0::TaggedEntry *)(reinterpret_cast<::FUN_0044ee20_class *>((m_pOwnerObject))->GetElementAddress(index)));
        m_ref = entry;
        m_entry = *m_ref;
        *m_out = m_entry.GetPixelBitData();
        ::FUN_0040fbe0();
        reinterpret_cast<::FUN_006ecba0_class *>(&(local))->FUN_006ecba0(false, (void*)m_entry.GetPixelBitData());
        if (::FUN_00559450((int *)(m_ref)) != ::FUN_00559450((int *)&(local)))
            continue;
        if (!m_entry.GetPixelBitData())
        {
            result = false;
            break;
        }
        m_pOwnerObject->Process(m_entry.GetEntry()->key, arg);
        reinterpret_cast<::NP_0092c820 *>((dest))->FUN_0092c820((const ::NP_0092c820 &)(m_entry.GetEntry()->value));
        result = true;
        ::FUN_0040fbe0();
        if (m_entry.GetEntry()->IsOccupied())
            continue;
        break;
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return result;
}
}  // namespace fnv_00906af0

extern "C" int __cdecl FUN_00aa1a20(unsigned int, unsigned int, unsigned int);

class SpawnedObject
{
  public:
    virtual int vfn_00(int);
};

class FUN_00c3a8a0_cls
{
  public:
    void** m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    bool FUN_00c3a8a0(unsigned int, unsigned int);
};

// @fnv 0x00c3a8a0
bool FUN_00c3a8a0_cls::FUN_00c3a8a0(unsigned int a1, unsigned int a2)
{
    if (a2 == 0)
    {
        a2 = FUN_00aa1a20(a1, 0, 0x2800);
    }
    bool result = false;
    if (a2 != 0)
    {
        void* e = &m_e0;
        fnv::crt::strcpy_s((char *)(e), 0x104, (const char *)(a1));
        ::NormalizePathSeparators((char *)(void *)(&m_e0));
        result = reinterpret_cast<::NiStream *>(this)->Load((::NiBinaryStream *)(a2));
        SpawnedObject* p1 = (SpawnedObject*)a2;
        SpawnedObject* p2 = p1;
        (p2 != 0) ? p2->vfn_00(1) : 0;
    }
    return result;
}

// FUN_0043ace0 worker2 a2run3 A1: NiSortAdjustNode drop m_a8 (pack NiMemObject is 1B, +4 align -> 42 fields = 0xac alloc like ORIG)
struct MLx;
int GetRefAt21C(const char*);
void* FUN_0043b1b0(void*);
void* FUN_0043b230(void*);
void __cdecl FUN_0043b2b0(bool);
unsigned int __cdecl FUN_0043b290();
void* __cdecl FUN_0043b2a0();
unsigned int __cdecl FUN_00702440();
void* __cdecl FUN_0043b250();
extern char DAT_0101667c[];
extern char DAT_0101666c[];
extern char DAT_01016618[];
extern char DAT_010165c8[];

struct SubRef
{
    void FUN_0066b0d0(void*);
};
struct SortObj
{
    SortObj* FUN_00a5ecb0(unsigned int);
};
class NiSortAdjustNode : public NiMemObject
{
  public:
    NiSortAdjustNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
};
struct PropObj
{
};
struct Cls260
{
};
struct ElemV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual int v0c();
    virtual void d04();
    virtual void d05();
    virtual int v18();
};
struct Arg1V
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual bool v60(const char*, int);
};
struct BigV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void vF8(int, void*);
};
struct CtrlV
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void v90(void*, int);
};
struct MLx;
struct ThisS
{
    char* m_buf;
    int m_04;
    int m_08;
    SubRef m_sub;
    void FUN_0043ace0(const char* a0, MLx* a1, unsigned char a2, unsigned char a3);
};
// @fnv 0x0043aaf0
Model::Model(const char* fileName, BSStream* stream, bool firstFlag, bool secondFlag) : node(0)
{
    node = 0;
    reinterpret_cast<::ThisS *>(this)->FUN_0043ace0(fileName, (::MLx *)(stream), firstFlag, secondFlag);
}

// Copies a0 into m_buf, builds m_sub from a1's elements (wrapping in a NiSortAdjustNode when needed), and applies property/control updates.
// @fnv 0x0043ace0
void ThisS::FUN_0043ace0(const char* apName, MLx* apSource, unsigned char a2, unsigned char a3)
{
    bool q;
    {
        unsigned long count;
        {
            ElemV* elem;
            {
                void* x1;
                {
                    int iDynIndex;
                    {
                        int iElemIndex;
                        {
                            ElemV* pForm;
                            {
                                bool flagB;
                                {
                                    void* tmp;
                                    {
                                        void* z;
                                        {
                                            void* ctrlObj;
                                            {
                                                void* prop;
                                                {
                                                    void* pPropA;
                                                    {
                                                        void* pPropB;
                                                        {
                                                            bool flagC;
                                                            {
                                                                char* c;
                                                                {
                                                                    m_04 = 0;
                                                                    m_08 = 0;
                                                                    count = ((int)(::FUN_0044a670(apName))) + 1;
                                                                    c = (char*)FUN_00401000(count);
                                                                    m_buf = c;
                                                                    ::TaskQueueInterface::CopyStringToBuffer(m_buf, count, apName);
                                                                    if (GetRefAt21C((const char*)apSource) == 0)
                                                                    {
                                                                        reinterpret_cast<::NiStream2 *>((apSource))->FUN_00c3b370();
                                                                        if (!((Arg1V*)apSource)->v60(DAT_0101667c, 0))
                                                                        {
                                                                            m_buf = 0;
                                                                            return;
                                                                        }
                                                                    }
                                                                    elem = (ElemV*)apSource->GetStringAt(0);
                                                                    q = false;
                                                                    if (elem != 0 && elem->v0c() != 0)
                                                                    {
                                                                        x1 = FUN_0043b1b0(((void *)(reinterpret_cast<::TESTopicInfoData *>((elem))->GetLinkToList())));
                                                                        if (x1 != 0 &&
                                                                            ((bool)(::FUN_00af3bd0((int)x1, (int)(DAT_0101666c)))))
                                                                        {
                                                                            m_sub.FUN_0066b0d0(
                                                                                (SortObj*)new NiSortAdjustNode(0));
                                                                            ((BigV*)FUN_00559450((int*)&m_sub))
                                                                                ->vF8(0, elem);
                                                                        }
                                                                        else
                                                                        {
                                                                            m_sub.FUN_0066b0d0(elem);
                                                                        }
                                                                        q = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        iDynIndex = 0;
                                                                        for (iElemIndex = 0;
                                                                             iElemIndex < (unsigned int)GetRefAt21C(
                                                                                              (const char*)apSource);
                                                                             ++iElemIndex)
                                                                        {
                                                                            elem = (ElemV*)apSource->GetStringAt(
                                                                                iElemIndex);
                                                                            if (elem != 0)
                                                                            {
                                                                                if (elem->v0c() != 0 ||
                                                                                    elem->v18() != 0)
                                                                                {
                                                                                    pForm = elem;
                                                                                    if (FUN_00559450((int*)&m_sub) == 0)
                                                                                    {
                                                                                        m_sub.FUN_0066b0d0(
                                                                                            (SortObj*)new NiSortAdjustNode(
                                                                                                0));
                                                                                    }
                                                                                    ((BigV*)FUN_00559450((int*)&m_sub))
                                                                                        ->vF8(iDynIndex++, pForm);
                                                                                    q = true;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    if (q)
                                                                    {
                                                                        ::RemoveInvalidChildNodes((::NiNode *)(void *)((void*)FUN_00559450((int*)&m_sub)));
                                                                        if ((*reinterpret_cast<unsigned char *>(&::fnv_008d66b0::DAT_01185520)))
                                                                        {
                                                                            z = FUN_0043b230(
                                                                                (void*)FUN_00559450((int*)&m_sub));
                                                                            ctrlObj = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f36ac))), (::NiObject *)(z))));
                                                                            if (ctrlObj != 0)
                                                                            {
                                                                                prop = ((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(ctrlObj))));
                                                                                if (prop != 0)
                                                                                {
                                                                                    if (FUN_0043b1b0(((void *)(reinterpret_cast<::TESTopicInfoData *>(((void*)FUN_00559450(
                                                                                                (int*)&m_sub)))->GetLinkToList()))) != 0)
                                                                                    {
                                                                                        ((CtrlV*)prop)
                                                                                            ->v90(
                                                                                                ((void *)(reinterpret_cast<::TESTopicInfoData *>(((void*)FUN_00559450(
                                                                                                        (int*)&m_sub)))->GetLinkToList())),
                                                                                                0);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                        flagB = false;
                                                                        FUN_0043b2b0(true);
                                                                        tmp = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropObj*)FUN_00559450((int*)&m_sub))))->FUN_00a59d30(FUN_0043b290())));
                                                                        if (tmp != 0)
                                                                        {
                                                                            pPropA = tmp;
                                                                            if (reinterpret_cast<::FUN_0043b260_Class *>((((Cls260*)pPropA)))->FUN_0043b260((
                                                                                        unsigned short*)FUN_0043b2a0()))
                                                                            {
                                                                                reinterpret_cast<::ExtraOwnerB *>((((PropObj*)FUN_00559450((int*)&m_sub))))->FUN_00a5b230(FUN_0043b290());
                                                                                flagB = true;
                                                                            }
                                                                        }
                                                                        tmp = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropObj*)FUN_00559450((int*)&m_sub))))->FUN_00a59d30(FUN_00702440())));
                                                                        if (0 != tmp)
                                                                        {
                                                                            pPropB = tmp;
                                                                            if (reinterpret_cast<::FUN_0043b260_Class *>((((Cls260*)pPropB)))->FUN_0043b260((
                                                                                        unsigned short*)FUN_0043b250()))
                                                                            {
                                                                                reinterpret_cast<::ExtraOwnerB *>((((PropObj*)FUN_00559450((int*)&m_sub))))->FUN_00a5b230(FUN_00702440());
                                                                                flagB = true;
                                                                            }
                                                                        }
                                                                        if (flagB)
                                                                        {
                                                                            if (apSource->unk08)
                                                                            {
                                                                                ::FUN_005b5e40();
                                                                            }
                                                                            else
                                                                            {
                                                                                ::FUN_005b5e40();
                                                                            }
                                                                        }
                                                                        FUN_0043b2b0(false);
                                                                        if (a2)
                                                                        {
                                                                            flagC = false;
                                                                            if (a3 || ::FUN_004b5bf0((::NiAVObject *)(void *)((void*)FUN_00559450(
                                                                                          (int*)&m_sub))))
                                                                            {
                                                                                flagC = true;
                                                                            }
                                                                            ::BSShaderManager::UpdateObjectTypeRecurse(
                                                                                (::NiAVObject *)(void *)((void*)FUN_00559450((int*)&m_sub)), a3,
                                                                                flagC);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern int DAT_010169d4;

struct FUN_0043d8f0_Class : public FUN_0043c830
{
    void FUN_0043d8f0();
};

// @fnv 0x0043d8f0
void FUN_0043d8f0_Class::FUN_0043d8f0()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010169d4);
    this->FUN_0043c830::~FUN_0043c830();
}

namespace ModelResources {
struct Main;
struct Form;
struct Entry;
struct Model
{
    unsigned int value;
    unsigned int FUN_0048cee0();
};
struct Prefix18
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
};
struct Source : Prefix18, Model
{
};
struct Link
{
    unsigned int value;
    bool FUN_008256d0();
    Entry** FUN_006815c0();
};
struct Prefix4
{
    unsigned int value;
};
struct Iterator : Prefix4, Link
{
};
struct PrefixC
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};
struct ListOwner : PrefixC, Iterator
{
};
struct List
{
    ~List();
};
struct Form
{
    int FUN_00401170();
};
struct WeaponPrefix : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
};
struct Weapon : WeaponPrefix, Model
{
};
struct ModelPair
{
};
struct Armor : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    ModelPair models;
};
struct Misc : Form
{
};
struct CreaturePrefix : Form
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
};
struct Creature : CreaturePrefix, Model
{
};
struct Reference
{
};
struct Entry
{
};
struct Manager
{
    void QueueModelAnimations(Model*, void*, Main*, int, int, int);
};
struct Main
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void Complete();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    ListOwner* owner;
    Source* source;
    void UpdateModels();
};
// Loads the source model if needed, then walks the owner's entries and dispatches weapon, armor, misc and creature models to the manager before completing.
// @fnv 0x0043dc70
void Main::UpdateModels()
{
    bool loaded = false;
    if (source->FUN_0048cee0() > 0 && !reinterpret_cast<::EffectSetting *>((source))->HasNoAssociatedActorValue())
    {
        reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelResources::Manager * *>(&::g_modelLoader))))->FUN_00443d30((int)(static_cast<Model*>(source)), (int)(((void *)(reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60()))), (int)(this), (int)(0), 1, 0, 0);
        loaded = true;
    }
    reinterpret_cast<::EffectSetting *>((source))->QueueAssociatedItem();
    Iterator* iterator = static_cast<Iterator*>(owner);
    if (!iterator->FUN_008256d0())
        while (iterator)
        {
            Entry* entry = *((::ModelResources::Entry **)(new ((void *)(iterator)) ::Vec3()));
            Reference* reference = ((::ModelResources::Reference *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((entry))->FUN_00825c00()));
            if (::IsArchetypeFlagSet((::EffectSetting *)(reference)) && (!loaded || !reinterpret_cast<::EffectSetting *>((reference))->UsesAssociatedActorValue()))
            {
                Form* form = ((::ModelResources::Form *)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((reference))->FUN_005f5f80()));
                if (form)
                {
                    if (reinterpret_cast<::S3e60 *>((reference))->FUN_00403e60(0x10000))
                    {
                        if (form->FUN_00401170() == 40)
                        {
                            Weapon* weapon = (Weapon*)form;
                            if (weapon->FUN_0048cee0() > 0)
                                reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelResources::Manager * *>(&::g_modelLoader))))->FUN_00443d30((int)(static_cast<Model*>(weapon)), (int)(((void *)(reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60()))), (int)(this),
                                                           (int)(((void *)(::FUN_0045c6b0((::TESForm_0045c6b0 *)(weapon))))), 1, 0, 0);
                        }
                    }
                    else if (reinterpret_cast<::S3e60 *>((reference))->FUN_00403e60(0x20000))
                    {
                        if (form->FUN_00401170() == 24)
                        {
                            Armor* armor = (Armor*)form;
                            reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelResources::Manager * *>(&::g_modelLoader))))->FUN_00443d30((int)(((::ModelResources::Model *)(reinterpret_cast<::FUN_00481150_shell *>(&(armor->models))->GetBipedModel((::SEX)(0))))), (int)(((void *)(reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60()))), (int)(this),
                                                       (int)(((void *)(::FUN_0045c6b0((::TESForm_0045c6b0 *)(armor))))), 1, 0, 0);
                            reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelResources::Manager * *>(&::g_modelLoader))))->FUN_00443d30((int)(((::ModelResources::Model *)(reinterpret_cast<::FUN_00481150_shell *>(&(armor->models))->GetBipedModel((::SEX)(1))))), (int)(((void *)(reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60()))), (int)(this),
                                                       (int)(((void *)(::FUN_0045c6b0((::TESForm_0045c6b0 *)(armor))))), 1, 0, 0);
                        }
                    }
                    else if (reinterpret_cast<::S3e60 *>((reference))->FUN_00403e60(0x40000))
                    {
                        if (form->FUN_00401170() == 42)
                        {
                            Misc* miscSlot0 = (Misc*)form;
                            List* listSlot0 = ((::ModelResources::List *)(reinterpret_cast<::NPCModelView *>((miscSlot0))->CollectModelPaths(1, 1)));
                            reinterpret_cast<::ModelLoaderKFList *>(((*reinterpret_cast<::ModelResources::Manager * *>(&::g_modelLoader))))->QueueKFPathsFromList((::BSSimpleList<const char *> *)(listSlot0), (::KFQueueOwner *)(0), (int)(((void *)(reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60()))), this, (const char *)(0));
                            reinterpret_cast<::FileMatchList *>((listSlot0))->RemoveAll();
                            delete listSlot0;
                        }
                        else if (form->FUN_00401170() == 43)
                        {
                            Creature* creature = (Creature*)form;
                            (*reinterpret_cast<::ModelResources::Manager * *>(&::g_modelLoader))->QueueModelAnimations(static_cast<Model*>(creature), ((void *)(reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60())), this, 0,
                                                               1, 1);
                            reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelResources::Manager * *>(&::g_modelLoader))))->FUN_00443d30((int)(static_cast<Model*>(creature)), (int)(((void *)(reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60()))), (int)(this),
                                                       (int)(((void *)(::FUN_0045c6b0((::TESForm_0045c6b0 *)(creature))))), 1, 0, 0);
                        }
                    }
                }
                if (!reinterpret_cast<::EffectSetting *>((reference))->HasEffectID() && !reinterpret_cast<::EffectSetting *>((reference))->UsesAssociatedActorValue() && reinterpret_cast<::S3e60 *>((reference))->FUN_00403e60(0x40000))
                    ::FUN_0040ab50();
                reinterpret_cast<::FUN_00408790_shell *>((reference))->FUN_00408790();
            }
            iterator = static_cast<Iterator*>(((::ModelResources::Link *)(reinterpret_cast<::Callees *>((iterator))->FUN_00726070())));
        }
    ::SetFieldCToFive((char *)this);
    Complete();
}
}

class ModelBase43E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class Model43E
{
  public:
    int m_iLoaded;
};

class AnimObject43E : public ModelBase43E, public Model43E
{
};

class AnimData43E
{
  public:
};

class Handle43E
{
  public:
    AnimData43E* Get() const;

    AnimData43E* m_pPointer;
};

class Task43E;

class ModelLoader43E
{
  public:
};


class Task43E
{
  public:
    void Finish();
    void LoadModelsAndFinish();

    void* m_ppVirtualMethodTable;
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
    Handle43E m_kData;
};

// @fnv 0x0043e690
void Task43E::LoadModelsAndFinish()
{
    if (((::AnimData43E *)(::FUN_00559450((int *)&(m_kData)))))
    {
        for (int i = 0; i < 2; i++)
        {
            if (((::AnimObject43E *)(reinterpret_cast<::FUN_0043e750_shell *>((((::AnimData43E *)(::FUN_00559450((int *)&(m_kData))))))->GetObjectANIO(i))))
                reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelLoader43E * *>(&::g_modelLoader))))->FUN_00443d30((int)(((::AnimObject43E *)(reinterpret_cast<::FUN_0043e750_shell *>((((::AnimData43E *)(::FUN_00559450((int *)&(m_kData))))))->GetObjectANIO(i)))), reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60(), (int)(this), 2,
                                                        true, 0, 0);
        }
    }
    reinterpret_cast<::QueuedKF *>(this)->DispatchToManager();
}

struct FUN_0043e840_shell : public ModelLoader
{
    void FUN_00c3cb70(int, int);
    void FUN_0043e840(int param_2, int param_3);
};
// Calls FUN_00c3cb70 with the two arguments, then passes the queued file at this+0x3c to g_modelLoader->DispatchAnimIdle.
// @fnv 0x0043e840
void FUN_0043e840_shell::FUN_0043e840(int aiArg1, int aiArg2)
{
    reinterpret_cast<::fnv_00c3cb70::IOTask *>(this)->FUN_00c3cb70(aiArg1, (::fnv_00c3cb70::RefObj *)(aiArg2));
    reinterpret_cast<::FUN_0043e810_shell *>((g_modelLoader))->DispatchAnimIdle((::AnimIdle *)(::QueuedFile *)((QueuedFile*)FUN_00559450((int*)((char*)this + 0x3c))));
}

struct FUN_0043eac0_class
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

    void FUN_00c3cb70(int param_1, int param_2);
    void ForwardToHolder(int param_1, int param_2);
};


// Calls FUN_00c3cb70 with the two arguments, then calls ForwardToInner on DAT_011c3b3c passing unk28.
// @fnv 0x0043eac0
void FUN_0043eac0_class::ForwardToHolder(int param_1, int param_2)
{
    reinterpret_cast<::fnv_00c3cb70::IOTask *>(this)->FUN_00c3cb70(param_1, (::fnv_00c3cb70::RefObj *)(param_2));
    (*reinterpret_cast<::Holder14 * *>(&::g_modelLoader))->ForwardToInner(unk28);
}

namespace fnv_0043ed90 {
struct RefActor;
struct LoadedNode
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
    RefActor* owner;
};
struct NodePointer
{
    LoadedNode* node;
};
struct AnimationManager
{
};
struct RefActor
{
};
struct AttachTask
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
    NodePointer first;
    NodePointer second;
    void FUN_0043ed90(RefActor* actor, int arg);
};
// @fnv 0x0043ed90
void AttachTask::FUN_0043ed90(RefActor* actor, int arg)
{
    AutoMemContext_1 manager((MEM_CONTEXT)0x37, true,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x613);
    AnimationManager* scope = ((::fnv_0043ed90::AnimationManager *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430()));
    reinterpret_cast<::TESNPC_Sub *>((scope))->AttachHeadModels((::TESObjectREFR *)(actor), (::BipedAnim *)(arg), (::BSFaceGenNiNode *)(::fnv_0043ed90::LoadedNode *)(((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(first))))), (::BSFaceGenNiNode *)(::fnv_0043ed90::LoadedNode *)(((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(second))))));
    if (actor != (*reinterpret_cast<::fnv_0043ed90::RefActor * *>(&::_g_thePlayer)))
    {
        ::SetObjectFormID((::NiAVObject *)(::fnv_0043ed90::LoadedNode *)(((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(first))))), (unsigned int)(((const char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((actor))->FUN_0084e3a0()))));
        if (((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(second)))))
            ::SetObjectFormID((::NiAVObject *)(::fnv_0043ed90::LoadedNode *)(((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(second))))), (unsigned int)(((const char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((actor))->FUN_0084e3a0()))));
    }
    if (((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(second)))))
        ((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(second))))->owner = actor;
    if (((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(first)))))
        ((::fnv_0043ed90::LoadedNode *)(::FUN_00559450((int *)&(first))))->owner = actor;
}
}  // namespace fnv_0043ed90

struct SaveItem
{
    unsigned int unk00;
    unsigned int m_04;
};

struct SaveSub
{
};

struct SaveHolder
{
};


class FUN_0043f120_cls
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    SaveSub* m_28;
    unsigned int m_2c[20];
    void FUN_0043f120();
};

struct FnvSceneNode
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual int vfn18();
    FnvSceneNode* FUN_004a8a90();
    FnvSceneNode* FUN_0043b230();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4c();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5c();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6c();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7c();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8c();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9c();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual void vfnD0();
    virtual void vfnD4();
    virtual void vfnD8();
    virtual void vfnDC();
    virtual void vfnE0();
    virtual void vfnE4(void*);
    FnvSceneNode* FUN_006a9540(void*, void*);
    void FUN_00603ad0(void*);
};
struct FnvRenderSelector
{
    int FUN_00401170();
    void FUN_00603ad0(void*);
};
struct FnvMaster
{
    FnvRenderSelector* FUN_0043f010();
    FnvSceneNode* FUN_004a8a90();
};
struct FnvRefPtr
{
    FnvSceneNode* value;
    void FUN_0066b0d0(FnvSceneNode*);
    void FUN_0066b0d0(FnvSceneNode*, FnvSceneNode*, FnvSceneNode*, int);
};
struct FnvList
{
    unsigned int FUN_0043b480();
};
struct FnvLink
{
    FnvSceneNode* FUN_0043b230();
};
struct FnvGuard
{
    int lock;
    FnvGuard(int, bool, const char*, int);
    ~FnvGuard();
};
struct FnvHandle
{
    FnvSceneNode* object;
    FnvHandle(FnvSceneNode*);
    ~FnvHandle();
    void FUN_0066b0d0(FnvSceneNode*);
};
struct FnvVec3
{
    float x, y, z;
    void FUN_006815c0();
    void FUN_0043f850(float);
};
struct FnvMatrix3
{
    float row0x, row0y, row0z, row1x, row1y, row1z, row2x, row2y, row2z;
    void FUN_006815c0();
    void FUN_0043f850(float);
};
struct FnvEntry
{
    unsigned int field00, field04, field08, field0c, field10, field14, field18, field1c;
    FnvEntry();
    ~FnvEntry();
};
struct FnvGeometry
{
    FnvGeometry* FUN_006a9540(FnvMatrix3*, FnvMatrix3*);
    FnvGeometry* FUN_0043f8d0();
};
extern "C" const char DAT_01016840[];

extern "C" void __cdecl FUN_00ec782f(FnvEntry*, unsigned, unsigned, void*, void*);
extern "C" void __cdecl FUN_00ec5fce(FnvEntry*, unsigned, unsigned, void*);

struct FnvQueueManager
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48(void*);
};

struct FnvRoot
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FnvMaster* master28;
    FnvRefPtr references[20];
    FnvRefPtr attachments[20];
    FnvRefPtr children[20];
    int p11c;
    bool IsFieldCZero();
    void FUN_0043f2f0();
};

// @fnv 0x0043f2f0
void FnvRoot::FUN_0043f2f0()
{
    if (!reinterpret_cast<::FUN_0043fab0_class *>(this)->FUN_0043fab0())
    {
        reinterpret_cast<::ObjectC3 *>(this)->NotifyParents();
        return;
    }
    if (reinterpret_cast<::FUN_0043caa0_shell *>(this)->FUN_0043caa0() && ::IsFieldCZero((::Dummy_0069b080 *)this))
    {
        ::DAT_01202d98->vfn_48((IOTask*)this);
        return;
    }

    FnvGuard fileAccess(0x32, true, DAT_01016840, 0x690);
    {
        FnvHandle current(0);
        if (::FUN_00449110((int *)this) && reinterpret_cast<::FUN_0043caa0_shell *>(this)->FUN_0043caa0() && !::FUN_00449130((int *)this) && (void*)p11c != (*reinterpret_cast<::Ref * *>(&::_g_thePlayer)))
        {
            for (int index = 0; index < 20; ++index)
            {
                if (((::FnvSceneNode *)(::FUN_00559450((int *)&(references[index])))) && ((::FnvSceneNode *)(::fnv_004a8a90::FUN_004a8a90((char *)(((::FnvSceneNode *)(::FUN_00559450((int *)&(references[index])))))))) &&
                    ((::FnvSceneNode *)(::fnv_004a8a90::FUN_004a8a90((char *)(((::FnvSceneNode *)(::FUN_00559450((int *)&(references[index]))))))))->FUN_0043b230())
                {
                    children[index].FUN_0066b0d0(((::FnvSceneNode *)(reinterpret_cast<::FUN_004ae910_cls *>((master28))->LoadSlotObject({}, {}, {}))), ((::FnvSceneNode *)(::FUN_00559450((int *)&(attachments[index])))),
                                                 ((::FnvSceneNode *)(::fnv_004a8a90::FUN_004a8a90((char *)(((::FnvSceneNode *)(::FUN_00559450((int *)&(references[index]))))))))->FUN_0043b230(),
                                                 index);
                    if (((::FnvSceneNode *)(::FUN_00559450((int *)&(children[index])))))
                    {
                        bool found = false;
                        for (unsigned int i = 0; i < ((FnvList*)((::FnvSceneNode *)(::FUN_00559450((int *)&(children[index])))))->FUN_0043b480(); ++i)
                        {
                            FnvSceneNode* linkedNode;
                            {
                                FnvSceneNode* node = ((::FnvSceneNode *)(reinterpret_cast<::NiNode *>((((FnvList*)((::FnvSceneNode *)(::FUN_00559450((int *)&(children[index])))))))->GetAt(i)));
                                if (!node || !node->vfn18())
                                    continue;
                                {
                                    FnvSceneNode* selectedNode = node;
                                    linkedNode = ((::FnvSceneNode *)(::fnv_0043fad0::FUN_0043fad0((const char *)(selectedNode))));
                                    if (linkedNode)
                                    {
                                        found = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (!found)
                        {
                            FnvSceneNode* fallback = ((::FnvSceneNode *)(::FUN_00559450((int *)&(attachments[index]))))
                                                         ? ((::FnvSceneNode *)(::FUN_00559450((int *)&(attachments[index]))))
                                                         : ((::FnvSceneNode *)(reinterpret_cast<::FaceLoader *>((master28))->FUN_004ae790(index)));
                            if (fallback)
                            {
                                for (unsigned int j = 0; j < ((FnvList*)((::FnvSceneNode *)(::FUN_00559450((int *)&(children[index])))))->FUN_0043b480();
                                     ++j)
                                {
                                    FnvSceneNode* node = ((::FnvSceneNode *)(reinterpret_cast<::NiNode *>((((FnvList*)((::FnvSceneNode *)(::FUN_00559450((int *)&(children[index])))))))->GetAt(j)));
                                    {
                                        FnvSceneNode* geometry = node;
                                        if (geometry && ((::FnvSceneNode *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry)))) && ((::FnvRenderSelector *)(reinterpret_cast<::FUN_0043f010 *>((master28))->Get())) &&
                                            ((::FnvRenderSelector *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::FnvRenderSelector *)(reinterpret_cast<::FUN_0043f010 *>((master28))->Get()))))->FUN_007af430())) &&
                                            ((::FnvRenderSelector *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::FnvRenderSelector *)(reinterpret_cast<::FUN_0043f010 *>((master28))->Get()))))->FUN_007af430()))->FUN_00401170() == 42)
                                        {
                                            FnvRenderSelector* a = ((::FnvRenderSelector *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::FnvRenderSelector *)(reinterpret_cast<::FUN_0043f010 *>((master28))->Get()))))->FUN_007af430()));
                                            FnvEntry p[4];   // Resource entries for the selected geometry.
                                            FnvHandle h(0);  // Retains the active scene object.
                                            reinterpret_cast<::NiObjectD510 *>((((::FnvSceneNode *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry))))))->FUN_00a5d510(*(::NiPointerD510 *)nullptr);
                                            h.FUN_0066b0d0(((::FnvSceneNode *)(::FUN_00559450((int *)&(current)))));
                                            geometry->vfnE4(((::FnvSceneNode *)(::FUN_00559450((int *)&(h)))));
                                            a->FUN_00603ad0(p);
                                            if (!FUN_0043faf0() || reinterpret_cast<::FUN_0065a970_shell *>((fallback))->ApplyMorphs((::FaceGenCoordinate *)(p), (::NiTriBasedGeom *)(geometry), 0))
                                            {
                                                FnvMatrix3 matForward;
                                                new ((void *)&(matForward)) ::Vec3();
                                                reinterpret_cast<::ThreeByThreeMatrix *>(&(matForward))->SetYRotation(::DAT_01016b78);
                                                FnvMatrix3 matTransform;
                                                reinterpret_cast<::FUN_0043fa80_s *>((geometry))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(((::FnvGeometry *)(::FUN_006a9540((char *)(((FnvGeometry*)geometry)))))
                                                                           ->FUN_0043f8d0())));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        reinterpret_cast<::ObjectC3 *>(this)->NotifyParents();
    }
}

struct V3;
struct M3
{
    float m[3][3];
    M3();
};
struct AttachNode
{
};
struct ActorV_S
{
};
class BSOcclusionPlane
{
  public:
};
struct AttachRef
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual const V3* GetPos();
};
struct OSGlobals;
unsigned int gm_GetCurrentThreadId();
struct AttachTES
{
};
struct AttachLoader
{
};
struct FUN_00440310_shell : QueuedReference
{
    char pad00[0x28];
    AttachRef* m_pkRef;
    char pad2c[0xc];
    NiPointer<QueuedFile> m_spTask;
    void FUN_00440310(AttachNode* pkNode);
};
// @fnv 0x00440310
void FUN_00440310_shell::FUN_00440310(AttachNode* pkNode)
{
    reinterpret_cast<::FUN_00440460_S *>((pkNode))->FUN_00440460(m_pkRef->GetPos());
    reinterpret_cast<::FUN_0043fa80_s *>((pkNode))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((const ::M3 &)(::FUN_0056fa00((char *)(m_pkRef)))));
    reinterpret_cast<::FUN_00440490_shell *>((pkNode))->FUN_00440490(reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((ActorV_S*)m_pkRef)))->FUN_00567400());
    if (((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((::g_osGlobals))->FUN_0044edb0())) == gm_GetCurrentThreadId())
    {
        reinterpret_cast<::fnv_00570f70::Obj570 *>((m_pkRef))->FUN_00570f70((int)(pkNode));
        reinterpret_cast<::AttachmentHandler *>((((AttachTES*)g_TES)))->FUN_00451ef0(m_pkRef, (::AttachCell *)(((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)m_pkRef)))->GetTarget()))), (::AttachRef *)(0), 0);
        reinterpret_cast<::FUN_00565210_shell *>((m_pkRef))->FUN_00565210(true);
    }
    else
    {
        reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::NiPointer< ::QueuedFile> &)(m_spTask))->FUN_006f74f0((::ObjA *)(::QueuedFile *)((QueuedFile*)new FUN_004404c0(m_pkRef, (int)pkNode)));
        reinterpret_cast<::fnv_00440710::FUN_00440710_t *>((((AttachLoader*)g_modelLoader)))->DispatchToQueue((int)(m_spTask));
    }
}

namespace fnv_004408f0 {
class SLNode;
class SLObj28
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
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc(int, int);
    SLNode* Get();
};

class SLNode
{
  public:
    void Callee3(int);
};

class SLHelper
{
  public:
};


class FUN_004408f0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    SLObj28* m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    void FUN_004408f0(int a1, int a2);
};

// @fnv 0x004408f0
void FUN_004408f0_cls::FUN_004408f0(int a1, int a2)
{
    if (FUN_00559450((int*)&m_38) != 0)
    {
        reinterpret_cast<::FUN_00449170_Class *>((((SLHelper*)FUN_00559450((int*)&m_38))))->FUN_00449170();
    }
    reinterpret_cast<::fnv_00c3cb70::IOTask *>(this)->FUN_00c3cb70(a1, (::fnv_00c3cb70::RefObj *)(a2));
    if (FUN_00559450((int*)&m_34) != 0)
    {
        reinterpret_cast<::fnv_00571080::FUN_00571080_shell *>((m_28))->FUN_00571080((::fnv_00571080::NiAVObject *)(FUN_00559450((int*)&m_34)));
        ((SLNode*)&m_34)->Callee3(0);
        m_28->v1cc(0, 0);
    }
    reinterpret_cast<::FUN_004409e0_shell *>(((*reinterpret_cast<::fnv_004408f0::SLHelper * *>(&::g_modelLoader))))->FUN_004409e0((::TESObjectREFR *)(m_28));
    if (((::fnv_004408f0::SLNode *)(reinterpret_cast<::LowProcess *>((m_28))->GetTarget())) != 0)
    {
        FinishScriptRunLockAndReset((char*)((::fnv_004408f0::SLNode *)(reinterpret_cast<::LowProcess *>((m_28))->GetTarget())));
        if (((unsigned char)(reinterpret_cast<::FUN_00572350_shell *>((m_28))->FUN_00572350())))
        {
            FinishScriptRun((char*)((::fnv_004408f0::SLNode *)(reinterpret_cast<::LowProcess *>((m_28))->GetTarget())));
        }
    }
}
}  // namespace fnv_004408f0

class B440ED0Form;

class B440ED0Reference
{
  public:
};


class B440ED0Task;

class B440ED0ModelLoader
{
  public:
};


class B440ED0Task
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_iMemContext;
    int unk1C;
    int unk20;
    int unk24;
    B440ED0Reference* m_pkReference;

    void FUN_00440ed0();
};

// Resolves the task's reference to a form, derives a load type from it, and submits the reference to the model loader with the task's priority.
// @fnv 0x00440ed0
void B440ED0Task::FUN_00440ed0()
{
    AutoMemHelper kMemHelper8(m_iMemContext, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x847);
    B440ED0Form* pkObject = ((::B440ED0Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pkReference))->FUN_007af430()));
    B440ED0Form* pkForm = pkObject;
    int iType = ::FUN_0045c6b0((::TESForm_0045c6b0 *)(pkObject));
    if (m_pkReference && reinterpret_cast<::FUN_00564e60_shell *>((m_pkReference))->FUN_00564e60())
        iType = 6;
    if (m_pkReference && reinterpret_cast<::FUN_00564f00_shell *>((m_pkReference))->FUN_00564f00())
        iType = 10;
    reinterpret_cast<::FUN_00444540_cls *>(((*reinterpret_cast<::B440ED0ModelLoader * *>(&::g_modelLoader))))->DispatchWithScope((unsigned int)(m_pkReference), (unsigned int)(pkForm), reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60(), (unsigned int)(this), iType);
}

class B441420Info;

class B441420Array
{
  public:
    B441420Info*& GetAt(int iIndex);
};

class B441420Owner
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
    B441420Array m_kInfos;

    B441420Info* GetInfoAt(int iIndex);
};

// @fnv 0x00441420
B441420Info* B441420Owner::GetInfoAt(int iIndex)
{
    return ((::B441420Info *)(reinterpret_cast<::S3e60 *>(&(m_kInfos))->FUN_006a7ad0(iIndex)));
}

struct MLPackage
{
};

struct MLActor
{
    MLPackage* GetCurrentPackage();
};

struct MLCellBase
{
    int unk00;
};

struct MLAttachTarget
{
    int unk00;
};

struct MLParentCell : MLCellBase
{
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
};

struct MLParentCellEx : MLParentCell, MLAttachTarget
{
};

struct MLLoadTask;

struct MLModelLoader
{
};


struct MLLoadTask
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MEM_CONTEXT eMemContext;
    int unk1C;
    int unk20;
    int unk24;
    MLActor* pActor;

    void ProcessLoadTask();
};

struct Cls492c0
{
    Cls492c0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls496a0
{
    Cls496a0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4b750
{
    Cls4b750(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4ba10
{
    Cls4ba10(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4bbe0
{
    Cls4bbe0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4be80
{
    Cls4be80(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4b500
{
    Cls4b500(int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls4c760
{
    Cls4c760(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct Cls497c0
{
    Cls497c0(int, int, int);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
};
struct ShellTask28
{
};
struct IOShell442650
{
};
void FUN_00446ea0();
void FUN_00446f00();
struct Mgr442650
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    FUN_004421d0* m_28;
    char m_2c;
    Mgr442650* FUN_00442650();
};
// @fnv 0x00442650
Mgr442650* Mgr442650::FUN_00442650()
{
    m_00 = new Cls492c0(10, 1009, 12);
    m_04 = new Cls496a0(10, 1009, 12);
    m_08 = new Cls4b750(10, 5039, 12);
    m_0c = new Cls4b750(10, 5039, 12);
    m_10 = new Cls4ba10(10, 251, 12);
    m_14 = new Cls4bbe0(10, 251, 12);
    m_18 = new Cls4be80(10, 251, 12);
    m_1c = new Cls4b500(10, 8);
    m_20 = new Cls4c760(10, 1009, 12);
    m_24 = new Cls497c0(10, 1009, 12);
    m_28 = new FUN_004421d0(10);
    reinterpret_cast<::TaskThreadResume *>((((ShellTask28*)m_28)))->FUN_00c42f50();
    m_2c = 0;
    if (::DAT_01202d98)
    {
        reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>((((IOShell442650*)::DAT_01202d98)))->FUN_0057bd60((::fnv_0057bd60::MobileObject *)(void *)((void*)::ModelLoader::UpdateLoadingStatusCallback));
        reinterpret_cast<::TESObjectACTI *>((((IOShell442650*)::DAT_01202d98)))->SetLoopingSound((::TESSound *)(void *)((void*)FUN_00446e40));
        reinterpret_cast<::TESObjectACTI *>((((IOShell442650*)::DAT_01202d98)))->SetActivateSound((::TESSound *)(void *)((void*)FUN_00446ea0));
        reinterpret_cast<::FUN_004fbf00_shell *>((((IOShell442650*)::DAT_01202d98)))->FUN_004fbf00((::TESSound *)(void *)((void*)FUN_00446f00));
        reinterpret_cast<::EffectSetting *>((((IOShell442650*)::DAT_01202d98)))->SetEnchantEffectShader((::TESEffectShader *)(void *)((void*)::fnv_00446f10::FUN_00446f10));
        reinterpret_cast<::FUN_008ac890_shell *>((((IOShell442650*)::DAT_01202d98)))->SetWaterForm((::TESWaterForm *)(void *)((void*)::fnv_00446f90::FUN_00446f90));
    }
    return this;
}

struct QEntry444;

struct QTask444
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void Queue8();
    virtual void v009();
    virtual void QueueA();
};

struct FUN_0043c960
{
    char pad[0x48];
    FUN_0043c960(QEntry444* pkEntry, int iPriority);
};

struct FUN_0043c6e0
{
    char pad[0x48];
    FUN_0043c6e0(int iKey, int iPriority, int iExtra, bool bFlagA, bool bFlagB);
};

struct QPtr444
{
};

struct QOut444
{
};

struct QEntry444
{
    void FUN_0092c870();
};

struct QMap444
{
    virtual void v0();
    virtual void v1();
    virtual bool GetAt(int iKey, QEntry444** ppkEntry);
};

struct FUN_004440d0_shell
{
    QMap444* m_pTaskMap;

    void QueueTaskByKey(int iKey, QOut444& kOut, int iPriority, QueuedFile* pkParent, int iExtra, bool bFlagA,
                        bool bFlagB, bool bFlagC);
};

// @fnv 0x004440d0
void FUN_004440d0_shell::QueueTaskByKey(int iKey, QOut444& kOut, int iPriority, QueuedFile* pkParent, int iExtra,
                                        bool bFlagA, bool bFlagB, bool bFlagC)
{
    QEntry444* pkEntry = 0;
    if (m_pTaskMap->GetAt(iKey, &pkEntry))
    {
        if (bFlagB)
            reinterpret_cast<::FUN_0092c870_shell *>((pkEntry))->FUN_0092c870();
        if (pkParent)
        {
            GlobalObject_00528cb0 kTask((int)new FUN_0043c960(pkEntry, iPriority));
            reinterpret_cast<::QueuedFile *>((((::QTask444 *)(::FUN_00559450((int *)(((QPtr444*)&kTask)))))))->SetParent(pkParent);
            ((::QTask444 *)(::FUN_00559450((int *)(((QPtr444*)&kTask)))))->QueueA();
            reinterpret_cast<::NP_0092c820 *>(&(kOut))->FUN_0092c820((const ::NP_0092c820 &)(kTask));
            return;
        }
        reinterpret_cast<::FUN_006f74f0_cls *>(&(kOut))->FUN_006f74f0((::ObjA *)(::QueuedFile *)(0));
        return;
    }
    GlobalObject_00528cb0 kNewTask((int)new FUN_0043c6e0(iKey, iPriority, iExtra, bFlagA, bFlagB));
    reinterpret_cast<::FUN_00443ff0Class *>((((::QTask444 *)(::FUN_00559450((int *)(((QPtr444*)&kNewTask)))))))->FUN_00443ff0(bFlagC);
    reinterpret_cast<::QueuedFile *>((((::QTask444 *)(::FUN_00559450((int *)(((QPtr444*)&kNewTask)))))))->SetParent(pkParent);
    ((::QTask444 *)(::FUN_00559450((int *)(((QPtr444*)&kNewTask)))))->Queue8();
    reinterpret_cast<::NP_0092c820 *>(&(kOut))->FUN_0092c820((const ::NP_0092c820 &)(kNewTask));
}

namespace fnv_00444350 {
struct QFile444
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
    virtual void Start();
    virtual void v11();
    virtual void SetPriority(int);
    void SetFlag(bool);
};
struct QHead444 : public QFile444
{
    QHead444(void* apKey, int aePriority, void* apNPC, bool abA, bool abB);
    QHead444(void* apEntry, int aePriority);
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
};
struct QPtr444
{
    QPtr444(QHead444*);
    ~QPtr444();
    operator QHead444*() const;
    QHead444* operator->() const;
    QPtr444& operator=(const QPtr444&);
    QPtr444& operator=(QHead444*);
    int p;
};
struct QEntry444
{
};
struct QMap444
{
    virtual void v0();
    virtual void v1();
    virtual bool GetAt(void* apKey, QEntry444** appOut);
};
struct HeadLoader444
{
    QMap444* pMap;
    void FUN_00444350(void* apKey, int aiArg2, QPtr444* apOut, int aePriority, QFile444* apParent, void* apNPC,
                      bool abA, bool abB, bool abFlag);
};

// @fnv 0x00444350
void HeadLoader444::FUN_00444350(void* apKey, int aiArg2, QPtr444* apOut, int aePriority, QFile444* apParent,
                                 void* apNPC, bool abA, bool abB, bool abFlag)
{
    QEntry444* pEntry = 0;
    if (pMap->GetAt(apKey, &pEntry))
    {
        if (abB)
            reinterpret_cast<::FUN_0092c870_shell *>((pEntry))->FUN_0092c870();
        if (apParent)
        {
            QPtr444 spHead(new QHead444(pEntry, aePriority));
            reinterpret_cast<::QueuedFile *>(((spHead).operator->()))->SetParent((::QueuedFile *)(apParent));
            spHead->Start();
            reinterpret_cast<::NP_0092c820 *>((void *)&(const ::fnv_00444350::QPtr444 &)(*apOut))->FUN_0092c820((const ::NP_0092c820 &)(spHead));
            return;
        }
        reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::fnv_00444350::QPtr444 &)(*apOut))->FUN_006f74f0((::ObjA *)(::fnv_00444350::QHead444 *)(0));
        return;
    }
    QPtr444 spNew(new QHead444(apKey, aePriority, apNPC, abA, abB));
    reinterpret_cast<::FUN_00443ff0Class *>(((spNew).operator->()))->FUN_00443ff0(abFlag);
    reinterpret_cast<::QueuedFile *>(((spNew).operator->()))->SetParent((::QueuedFile *)(apParent));
    spNew->SetPriority(aiArg2);
    reinterpret_cast<::NP_0092c820 *>((void *)&(const ::fnv_00444350::QPtr444 &)(*apOut))->FUN_0092c820((const ::NP_0092c820 &)(spNew));
}
}  // namespace fnv_00444350

struct S_00444d40_Class
{

    void FUN_00444d40(int param1, int param2, int param3, int param4);
};
// @fnv 0x004457d0
void ModelLoaderHelper445::FUN_004457d0(TESModel* model, int aiArg1, int aiArg2, void* ref)
{
    TESCreature* creature = dynamic_cast<TESCreature*>(model);
    char path[0x104];
    if (creature)
    {
        int node = ((int)(reinterpret_cast<::BaseProcess *>(&(creature->data114))->GetCurrentProcessData()));
        ::TaskQueueInterface::CopyStringToBuffer(path, 0x104, model->GetModelPath());
        char* slash = FUN_0040ab30(path, '\\');
        if (slash)
        {
            slash[1] = 0;
        }
        reinterpret_cast<::ModelLoaderKFList *>(this)->QueueKFPathsFromList((::BSSimpleList<const char *> *)(node), (::KFQueueOwner *)(::GetOffsetC((int)&(creature->data114))), aiArg1, (void *)(aiArg2), path);
        if (ref)
        {
            InventoryChanges* changes = ::InventoryChanges::CreateForReference((::TESObjectREFR *)(ref));
            int count;
            ItemEntry* entry = ((::ItemEntry *)(reinterpret_cast<::Target *>((changes))->SelectBestWeapon((::ActorStand *)(creature), (float *)(int *)(&count), 6, 0)));
            if (entry)
            {
                reinterpret_cast<::S_00444d40_Class *>(this)->FUN_00444d40(((int)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())), {}, {}, {});
                delete entry;
            }
            entry = ((::ItemEntry *)(reinterpret_cast<::AmmoInventory *>((changes))->FindBestAmmoChange((::AmmoScorer *)(creature), 0)));
            if (entry)
            {
                reinterpret_cast<::S_00444d40_Class *>(this)->FUN_00444d40(((int)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())), {}, {}, {});
                delete entry;
            }
        }
    }
}

// @fnv 0x00444d40
void S_00444d40_Class::FUN_00444d40(int param1, int param2, int param3, int param4)
{
    GlobalObject_00528cb0 local(0);

    reinterpret_cast<::fnv_00444dc0::FUN_00444dc0_t *>(this)->QueueModelForObject((::fnv_00444dc0::TESObject *)(param1), (::fnv_00444dc0::QHeadPtrDest *)(::GlobalObject_00528cb0 *)(&local), param2, param3, (::fnv_00444dc0::FUN_00444dc0_ref *)(param4));
}

struct QueuedHelmetLocal;

struct QHelmetPtr
{
    void* p;
    QHelmetPtr(QueuedHelmetLocal* = 0);
    ~QHelmetPtr();
    QueuedHelmetLocal* operator->() const;
    QHelmetPtr& operator=(QueuedHelmetLocal*);
};

struct QueuedHelmetLocal
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void vfn_20();
    QueuedHelmetLocal(FUN_0043f010* a1, int a2, int a3);
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
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
};

struct QHelmetQueue
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(NiRenderer* ref, QHelmetPtr* ptr);
    virtual void v3();
    virtual bool Add(NiRenderer* ref, QHelmetPtr* ptr, bool flag);
};

struct QHelmetDest
{
};

struct FUN_004450c0_holder : public ModelLoader
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    QHelmetQueue* m_pPrimaryTaskProcessor;

    void FUN_004450c0(FUN_0043f010* a1, QHelmetDest* a2, int a3, QueuedFile* a4, int a5);
};

// Looks up a queued helmet for a1's renderer, creates and adds one if missing, then assigns it to a2.
// @fnv 0x004450c0
void FUN_004450c0_holder::FUN_004450c0(FUN_0043f010* a1, QHelmetDest* a2, int a3, QueuedFile* a4, int a5)
{
    QHelmetPtr ptr(0);
    if (!this->m_pPrimaryTaskProcessor->Lookup(a1->Get(), &ptr))
    {
        reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::QHelmetPtr &)(ptr))->FUN_006f74f0((::ObjA *)(::QueuedHelmetLocal *)(new QueuedHelmetLocal(a1, a3, a5)));
        if (this->m_pPrimaryTaskProcessor->Add(a1->Get(), &ptr, false))
        {
            reinterpret_cast<::QueuedFile *>(((ptr).operator->()))->SetParent(a4);
            ptr->vfn_20();
        }
        else
        {
            reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::QHelmetPtr &)(ptr))->FUN_006f74f0((::ObjA *)(::QueuedHelmetLocal *)(0));
        }
    }
    reinterpret_cast<::NP_0092c820 *>((a2))->FUN_0092c820((const ::NP_0092c820 &)(ptr));
}

struct FUN_00445430_obj
{
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int a1, void* pGuard);
};

struct LoadScopeGuard : public S_0042f730
{
    LoadScopeGuard(AC_0042f730* p)
    {
        FUN_00528cb0(p);
    }
    ~LoadScopeGuard();
};

struct FUN_00445430_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00445430_obj* m_14;
    void FUN_00445430(unsigned int a1);
};

struct FUN_0044ac40_s
{
};

LoadScopeGuard::~LoadScopeGuard()
{
    FUN_0044cbf0((void**)this);
}

// @fnv 0x00445430
void FUN_00445430_cls::FUN_00445430(unsigned int a1)
{
    LoadScopeGuard guard(0);
    if (m_14->v2(a1, &guard))
    {
        reinterpret_cast<::TaskProcessor *>((((FUN_0044ac40_s*)::DAT_01202d98)))->FUN_0044ac40((::QueuedTask *)(::FUN_00559450((int *)&(guard))), {});
    }
}

namespace fnv_00445570 {
struct FUN_00445570_obj
{
    virtual void v0();
    virtual void v1();
    virtual bool v2(unsigned int a1, void* pGuard);
};

struct FUN_00445570_obj2
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned int a1);
};

struct LoadScopeGuard : public S_0042f730
{
    LoadScopeGuard(AC_0042f730* p)
    {
        FUN_00528cb0(p);
    }
    ~LoadScopeGuard();
};

struct FUN_00445570_cls
{
    int unk00;
    int unk04;
    FUN_00445570_obj* m_08;
    FUN_00445570_obj2* m_0c;
    int unk10;
    int unk14;
    FUN_00445570_obj* m_18;
    void FUN_00445570(unsigned int a1);
};

struct FUN_0044ac40_s
{
};

LoadScopeGuard::~LoadScopeGuard()
{
    FUN_0044cbf0((void**)this);
}

// @fnv 0x00445570
void FUN_00445570_cls::FUN_00445570(unsigned int a1)
{
    LoadScopeGuard guardA(0);
    if (m_08->v2(a1, &guardA))
    {
        reinterpret_cast<::TaskProcessor *>((((FUN_0044ac40_s*)::DAT_01202d98)))->FUN_0044ac40((::QueuedTask *)(::FUN_00559450((int *)&(guardA))), {});
        m_0c->v5(a1);
    }
    LoadScopeGuard guardB(0);
    if (m_18->v2(a1, &guardB))
    {
        reinterpret_cast<::TaskProcessor *>((((FUN_0044ac40_s*)::DAT_01202d98)))->FUN_0044ac40((::QueuedTask *)(::FUN_00559450((int *)&(guardB))), {});
    }
}
}  // namespace fnv_00445570

int strcat_s(char*, unsigned int, const char*);
int _strnicmp(const char*, const char*, unsigned int);
struct AnimList
{
    char* item;
    AnimList* next;
    AnimList();
    ~AnimList();
    void AddHead(char*&);
};
struct AnimNode
{
};
struct Weapon445
{
    int GetType();
};
struct Actor445
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual bool IsChild(int);
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual bool IsCharacter();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual bool IsSpecial(int);
    int GetSex();
};
struct AnimManager445
{
    void* Load(char*, int, AnimList*);
};
struct GlobalLoader445
{
};

struct AnimLoader445
{
    AnimList* MakeList(char*, char*, int);
    AnimList* MakeRaceList(char*, int, int, void*);
    void QueueModelAnimations(TESModel*, int, int, Actor445*, bool, bool);
};
// @fnv 0x004419a0
void MLLoadTask::ProcessLoadTask()
{
    AutoMemContext_1 kMemContext5(eMemContext, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x925);
    MLParentCellEx* pCell4 = (MLParentCellEx*)((::MLParentCell *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pActor))->FUN_007af430()));
    MLActor* pTaskActor = pActor;
    bool bUnequipB = true;
    MLPackage* pPackage9 = ((::MLPackage *)(reinterpret_cast<::FUN_009344a0_shell *>((pTaskActor))->FUN_009344a0()));
    if (pPackage9 && reinterpret_cast<::TESPackage *>((pPackage9))->GetForceUnequipWeapon())
        bUnequipB = false;

    bool m_bHeaderParsed = reinterpret_cast<::TESActorBase *>((pCell4))->ShouldUseDefaultAppearance((::TESObjectREFR *)(pActor));
    if (!m_bHeaderParsed)
        reinterpret_cast<::CreatureHost_5fa0a0 *>((pCell4))->FUN_005fa0a0((::TESObjectREFR *)(pActor));
    else
        reinterpret_cast<::CreatureEquipment *>((pCell4))->FUN_005f9e00((::TESObjectREFR *)(pActor), true, bUnequipB, false);

    MLAttachTarget* pTarget5 = pCell4;
    reinterpret_cast<::AnimLoader445 *>(((*reinterpret_cast<::MLModelLoader * *>(&::g_modelLoader))))->QueueModelAnimations((::TESModel *)(pTarget5), reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60(), (int)(this), (::Actor445 *)(pActor), true, false);
    reinterpret_cast<::ModelLoaderHelper445 *>(((*reinterpret_cast<::MLModelLoader * *>(&::g_modelLoader))))->FUN_004457d0((::TESModel *)(pTarget5), reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60(), (int)(this), pActor);
    reinterpret_cast<::fnv_004412e0::QueuedActor *>(this)->QueueDismemberedLimbLoads();
}
// @fnv 0x00445a10
void AnimLoader445::QueueModelAnimations(TESModel* model, int priority, int queued, Actor445* actor, bool useSkeleton,
                                         bool forceSkeleton)
{
    char idleSlash[260];
    ::TaskQueueInterface::CopyStringToBuffer(idleSlash, 260, model->GetModelPath());
    {
        Actor445* actorCast;
        char* skeletonSlash = FUN_0040ab30(idleSlash, 92);
        if (actor && actor->IsSpecial(1))
        {
            if (skeletonSlash && !_strnicmp(skeletonSlash + 1, "Skeleton", 8))
            {
                char a[260];
                ::TaskQueueInterface::CopyStringToBuffer(a, 260, "Data\\");
                if (_strnicmp(idleSlash, "Meshes\\", 7))
                    strcat_s(a, 260, "Meshes\\");
                strcat_s(a, 260, idleSlash);
                char* extraList;
                extraList = FUN_0040ab30(a, 92);
                ::TaskQueueInterface::CopyStringToBuffer(extraList, 260 - (extraList - a), "\\MTIdle.KF");
                AnimList* i;
                i = MakeList(a, idleSlash, 0);
                reinterpret_cast<::ModelLoader *>(this)->QueueFileList((::BSSimpleList<const char *> *)(i), (::IO_TASK_PRIORITY)(priority), (::QueuedFile *)(queued), 0);
                delete i;
                actorCast = actor->IsActor() ? actor : 0;
                if (actorCast && ((::Weapon445 *)(reinterpret_cast<::FUN_008a1710_shell *>((actorCast))->FUN_008a1710())))
                {
                    const char* p;
                    p = DAT_011977a4[::DAT_0118a838[((::Weapon445 *)(reinterpret_cast<::FUN_008a1710_shell *>((actorCast))->FUN_008a1710()))->GetType()]];
                    if (p && *p)
                    {
                        std::sprintf(extraList, "\\%sHolster.KF", p);
                        i = MakeList(a, idleSlash, 0);
                        reinterpret_cast<::ModelLoader *>(this)->QueueFileList((::BSSimpleList<const char *> *)(i), (::IO_TASK_PRIORITY)(priority), (::QueuedFile *)(queued), 0);
                        delete i;
                        std::sprintf(extraList, "\\PA%sHolster.KF", p);
                        i = MakeList(a, idleSlash, 0);
                        reinterpret_cast<::ModelLoader *>(this)->QueueFileList((::BSSimpleList<const char *> *)(i), (::IO_TASK_PRIORITY)(priority), (::QueuedFile *)(queued), 0);
                        delete i;
                    }
                }
                ::TaskQueueInterface::CopyStringToBuffer(extraList, 260 - (extraList - a), "\\Death.KF");
                i = MakeList(a, idleSlash, 0);
                reinterpret_cast<::ModelLoader *>(this)->QueueFileList((::BSSimpleList<const char *> *)(i), (::IO_TASK_PRIORITY)(priority), (::QueuedFile *)(queued), 0);
                delete i;
            }
        }
        else
        {
            char* weaponName;
            TESAnimation* n;
            weaponName = FUN_0040ab30(idleSlash, 92);
            const int loadFlags = 0;
            if (((weaponName && !_strnicmp(1 + weaponName, "Skeleton", 8)) || forceSkeleton) && useSkeleton)
            {
                void* raceContext;
                raceContext = 0;
                if (actor && actor->IsActor())
                {
                    Actor445* filename = actor;
                    raceContext = ((void *)(reinterpret_cast<::fnv_008a1760::FUN_008a1760_shell *>((filename))->FUN_008a1760()));
                }
                AnimList* skeletonAnimations;
                skeletonAnimations = MakeRaceList(idleSlash, 1, 1, raceContext);
                reinterpret_cast<::ModelLoader *>(this)->QueueFileList((::BSSimpleList<const char *> *)(skeletonAnimations), (::IO_TASK_PRIORITY)(priority), (::QueuedFile *)(queued), 0);
                delete skeletonAnimations;
            }
            else if (actor->IsCharacter())
            {
                char b[260];
                ::TaskQueueInterface::CopyStringToBuffer(b, 260, idleSlash);
                char* directorySlash;
                directorySlash = FUN_0040ab30(b, 92);
                if (actor->IsChild(1))
                    ::TaskQueueInterface::CopyStringToBuffer(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Child\\IdleAnims");
                else if (actor->GetSex() == 1)
                    ::TaskQueueInterface::CopyStringToBuffer(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Female\\IdleAnims");
                else
                    ::TaskQueueInterface::CopyStringToBuffer(directorySlash, 260 - (directorySlash - b) - 1, "\\Locomotion\\Male\\IdleAnims");
                AnimList* idleAnimations;
                idleAnimations = new AnimList;
                reinterpret_cast<::FUN_00447850_shell *>((((GlobalLoader445*)g_modelLoader)))->FUN_00447850(((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::AnimManager445 * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(b, (::ANIM_GROUP_WEAPON_ENUM)(loadFlags)))), {});
                reinterpret_cast<::ModelLoader *>(this)->QueueFileList((::BSSimpleList<const char *> *)(idleAnimations), (::IO_TASK_PRIORITY)(priority), (::QueuedFile *)(queued), 0);
                delete idleAnimations;
            }
            n = dynamic_cast<TESAnimation*>(model);
            if (n && n->HasSpecialAnimations())
            {
                AnimList* pObj;
                pObj = new AnimList;
                AnimNode* race;
                race = (AnimNode*)((void *)(reinterpret_cast<::BaseProcess *>((n))->GetCurrentProcessData()));
                while (race)
                {
                    unsigned long ptr;
                    const char* animationFile;
                    animationFile = ((char *)(new ((void *)(race)) ::Vec3()));
                    ptr = ::FUN_0044a670(animationFile) + 1;
                    char* copy;
                    copy = new char[ptr];
                    ::TaskQueueInterface::CopyStringToBuffer(copy, ptr, animationFile);
                    pObj->AddHead(copy);
                    race = ((::AnimNode *)(reinterpret_cast<::Callees *>((race))->FUN_00726070()));
                }
                char prefix[260];
                ::TaskQueueInterface::CopyStringToBuffer(prefix, 260, model->GetModelPath());
                char* idx;
                idx = FUN_0040ab30(prefix, 92);
                if (idx)
                    ::TaskQueueInterface::CopyStringToBuffer(idx, 260 - (idx - prefix), "\\SpecialAnims\\");
                reinterpret_cast<::ModelLoader *>(this)->QueueFileList((::BSSimpleList<const char *> *)(pObj), (::IO_TASK_PRIORITY)(priority), (::QueuedFile *)(queued), prefix);
                delete pObj;
            }
        }
    }
}

namespace P516 {
struct Task
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Queue();
    virtual void v24();
    virtual void Finish();
};
struct Group : Task
{
    Group(void*, int);
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
};
struct File : Task
{
    File(const char*, int, void*, Task*);
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
};
struct Ptr
{
    Task* p;
    Ptr(Task*);
    ~Ptr();
    Task* Get();
    void Set(Task*);
};
struct Paths
{
    const char** FUN_006815c0();
    void FUN_0063f7b0();
};
struct Owner
{
    void FUN_00490fa0(Task*);
};
struct FileMap
{
    virtual void v0();
    virtual void v4();
    virtual bool Lookup(const char*, Task**);
};
struct GroupMap
{
    virtual void v0();
    virtual void v4();
    virtual bool Lookup(Owner*, Ptr*);
    virtual void vc();
    virtual void Insert(Owner*, Ptr*, int);
};
struct Loader
{
    int unk00;
    FileMap* files;
    int unk08;
    int unk0c;
    int unk10;
    GroupMap* groups;
    void LoadFiles(Paths*, Owner*, int, Task*, const char*);
};
// @fnv 0x004465f0
void Loader::LoadFiles(Paths* apPaths, Owner* owner, int priority, Task* parent, const char* prefix)
{
    if (!apPaths || !owner)
        return;
    Paths* node = apPaths;
    if (node && *((const char **)(new ((void *)(node)) ::Vec3())))
    {
        AutoMemContext_1 memory((MEM_CONTEXT)0x33, true,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0xe9f);
        Ptr group(0);
        while (node)
        {
            const char* entry = *((const char **)(new ((void *)(node)) ::Vec3()));
            if (entry)
            {
                const char* h = entry;
                char p[260];
                if (prefix)
                {
                    ::TaskQueueInterface::CopyStringToBuffer(p, 260, prefix);
                    strcat_s(p, 260, entry);
                    h = p;
                }
                Task* a = 0;
                if (files->Lookup(h, &a))
                    owner->FUN_00490fa0(a);
                else
                {
                    if (!((::P516::Task *)(::FUN_00559450((int *)&(group)))) && !groups->Lookup(owner, &group))
                    {
                        reinterpret_cast<::FUN_006f74f0_cls *>(&(group))->FUN_006f74f0((::ObjA *)(::P516::Task *)(new Group(owner, priority)));
                    }
                    Ptr i(new File(h, priority, owner, ((::P516::Task *)(::FUN_00559450((int *)&(group))))));
                    reinterpret_cast<::QueuedFile *>((((::P516::Task *)(::FUN_00559450((int *)&(i))))))->SetParent((::QueuedFile *)(::P516::Task *)(((::P516::Task *)(::FUN_00559450((int *)&(group))))));
                    ((::P516::Task *)(::FUN_00559450((int *)&(i))))->Queue();
                }
                delete entry;
                node->FUN_0063f7b0();
            }
            else
                node = ((::P516::Paths *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        if (((::P516::Task *)(::FUN_00559450((int *)&(group)))) && reinterpret_cast<::fnv_00446990::FUN_00446990_StandIn *>((((::P516::Task *)(::FUN_00559450((int *)&(group))))))->GetObjectFlags() > 0)
        {
            reinterpret_cast<::QueuedFile *>((((::P516::Task *)(::FUN_00559450((int *)&(group))))))->SetParent((::QueuedFile *)(parent));
            groups->Insert(owner, &group, 1);
            ::SetFieldCToFive((char *)(((::P516::Task *)(::FUN_00559450((int *)&(group))))));
            ((::P516::Task *)(::FUN_00559450((int *)&(group))))->Finish();
        }
        else
            reinterpret_cast<::FUN_006f74f0_cls *>(&(group))->FUN_006f74f0((::ObjA *)(::P516::Task *)(0));
    }
}
}

namespace fnv_00447330 {
struct FUN_00447300_shell : public ModelLoader
{
};
struct KFGlobal447330
{
};
struct KFList447330
{
    ~KFList447330();
    bool _ref_008256d0();
    char** _ref_006815c0();
    void _ref_0063f7b0();
};
void __cdecl _Deallocate(void*);

struct FUN_00447330_shell : public ModelLoader
{
    void* FUN_00447330(char* arg0, bool arg1, bool arg2, int arg3);
};

// @fnv 0x00447330
void* FUN_00447330_shell::FUN_00447330(char* apPath, bool abLoadLocomotion, bool arg2, int aiIndex)
{
    AutoMemHelper helper2(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp",
                          0x108e);
    void* retVal_2;
    char buf6[260];
    char* p;
    void* res3;
    if ((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0)) != 0 && ((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(apPath, (::ANIM_GROUP_WEAPON_ENUM)(0)))) != 0)
    {
        retVal_2 = 0;
        if (aiIndex == 12)
        {
            int i5;
            for (i5 = 0; (unsigned int)i5 < 12; i5++)
            {
                if (retVal_2 != 0)
                {
                    ((FUN_00447850_shell*)this)->FUN_00447850(((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(apPath, (::ANIM_GROUP_WEAPON_ENUM)(i5)))), retVal_2);
                }
                else
                {
                    retVal_2 = ((FUN_00447850_shell*)this)->FUN_00447850(((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(apPath, (::ANIM_GROUP_WEAPON_ENUM)(i5)))), 0);
                }
            }
        }
        else if (aiIndex != 0 && arg2)
        {
            retVal_2 = ((FUN_00447850_shell*)this)->FUN_00447850(((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(apPath, (::ANIM_GROUP_WEAPON_ENUM)(0)))), 0);
            ((FUN_00447850_shell*)this)->FUN_00447850(((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(apPath, (::ANIM_GROUP_WEAPON_ENUM)(aiIndex)))), retVal_2);
        }
        else
        {
            retVal_2 = ((FUN_00447850_shell*)this)->FUN_00447850(((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(apPath, (::ANIM_GROUP_WEAPON_ENUM)(aiIndex)))), 0);
        }
        return retVal_2;
    }
    ::TaskQueueInterface::CopyStringToBuffer(buf6, 260, "Data\\Meshes\\");
    strcat_s(buf6, 260, apPath);
    p = ::FUN_0040ab30(buf6, '\\');
    if (p == 0)
    {
        return 0;
    }
    ::TaskQueueInterface::CopyStringToBuffer(p, 260 - (p - buf6), "\\*.KF");
    res3 = ((void *)(reinterpret_cast<::AnimLoader445 *>((((FUN_00447300_shell*)this)))->MakeList(buf6, apPath, (int)(0))));
    if (abLoadLocomotion && ::FUN_0044a670(apPath))
    {
        char buf3[260];
        char* pA;
        KFList447330* res4;
        ::TaskQueueInterface::CopyStringToBuffer(buf3, 260, apPath);
        pA = ::FUN_0040ab30(buf3, '\\');
        if (pA != 0)
        {
            *pA = 0;
            strcat_s(pA, 260 - (pA - buf3), "\\Locomotion\\");
            ::TaskQueueInterface::CopyStringToBuffer(p, 260 - (p - buf6), "\\Locomotion\\*.KF");
            if (res3 == 0)
            {
                res3 = ((void *)(reinterpret_cast<::AnimLoader445 *>((((FUN_00447300_shell*)this)))->MakeList(buf6, buf3, (int)(0))));
            }
            else
            {
                reinterpret_cast<::AnimLoader445 *>((((FUN_00447300_shell*)this)))->MakeList(buf6, buf3, (int)(res3));
            }
            strcat_s(pA, 260 - (pA - buf3), "Hurt\\");
            strcat_s(pA, 260 - (pA - buf3), "IdleAnims");
            ::TaskQueueInterface::CopyStringToBuffer(p, 260 - (p - buf6), "\\Locomotion\\Hurt\\*.KF");
            res4 = (KFList447330*)((void *)(reinterpret_cast<::AnimLoader445 *>((((FUN_00447300_shell*)this)))->MakeList(buf6, buf3, (int)(0))));
            if (res4 != 0)
            {
                reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->ClearIdleData(buf3, (::BSSimpleList<const char *> *)(res4), 1);
                while (!res4->_ref_008256d0())
                {
                    char* head = *((char **)(new ((void *)(res4)) ::Vec3()));
                    delete head;
                    res4->_ref_0063f7b0();
                }
                delete res4;
            }
        }
    }
    reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::fnv_00447330::KFGlobal447330 * *>(&::DAT_011cb6a0))))->ClearIdleData(apPath, (::BSSimpleList<const char *> *)(res3), 0);
    return res3;
}
}  // namespace fnv_00447330

struct MeshSource
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual const char* Path();
};
struct CacheNode
{
};
struct CacheData
{
    int unk00;
    int unk04;
    int ready;
};
struct NodeHandle
{
    CacheNode* value;
    NodeHandle(CacheNode*);
    ~NodeHandle();
    operator CacheNode*() const;
};
struct DataHandle
{
    CacheData* value;
    DataHandle(CacheData*);
    ~DataHandle();
    operator CacheData*() const;
    CacheData* operator->() const;
};
struct MeshName
{
    char* data;
    short length;
    short capacity;
    MeshName();
    ~MeshName();
    operator const char*() const;
};
struct MeshCache
{
};
struct MeshTask
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void Queue();
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
    MeshTask(CacheNode*, CacheData*);
};
struct TaskHandle
{
    MeshTask* value;
    TaskHandle(MeshTask*);
    ~TaskHandle();
    operator MeshTask*() const;
    MeshTask* operator->() const;
};
int FUN_00406d50(char*, unsigned int, const char*);
void* operator new(unsigned int);
struct MeshLoader
{
    void LoadMesh(MeshSource*, int, void*, int);
};
// @fnv 0x0043f120
void FUN_0043f120_cls::FUN_0043f120()
{
    for (int i = 0; i < 20; i++)
    {
        if (reinterpret_cast<::BipedAnim *>((m_28))->IsSlotHidden((::BIPED_OBJECT)(i)))
        {
            unsigned int v = ((::SaveItem *)(reinterpret_cast<::FUN_0043f220_cls *>((m_28))->GetEntryAt(i)))->m_04;
            (*reinterpret_cast<::QueueModelHolder * *>(&::g_modelLoader))->FUN_00443dc0(v, (QueueObj*)&m_2c[i], reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60(), (int)this, 3, true, true, true, 0.0f);
            reinterpret_cast<::MeshLoader *>((reinterpret_cast<SaveHolder*>((*reinterpret_cast<::QueueModelHolder * *>(&::g_modelLoader)))))->LoadMesh((::MeshSource *)(v), reinterpret_cast<::FUN_0043cc60_shell *>(this)->FUN_0043cc60(), (void *)((int)this), -1);
        }
    }
    reinterpret_cast<::fnv_0043f1f0::FUN_0043f1f0_class *>(this)->FUN_0043f1f0(1);
    vfn_28();
}
// Builds a Meshes\ path from source->Path(), looks up cached mesh data for each variant and queues a MeshTask, otherwise loads it via FUN_00447a40.
// @fnv 0x00447bf0
void MeshLoader::LoadMesh(MeshSource* source, int priority, void* parent, int kind)
{
    NodeHandle node2(0);
    DataHandle data7(0);
    char path2[260];
    ::TaskQueueInterface::CopyStringToBuffer(path2, 260, "Meshes\\");
    FUN_00406d50(path2, 260, source->Path());
    if (kind == 9)
    {
        for (int index = 0; index < 2; index++)
        {
            MeshName name;
            ::fnv_00653520::BuildEgmFilename((::fnv_00653520::StrMem *)(::MeshName *)(&name), path2, index);
            if (((::MeshCache *)(::BSFaceGenManager::GetModelMap())) && ::fnv_006502f0::LookupModelAndGetFlags((::fnv_006502f0::Map62d0 *)(((::MeshCache *)(::BSFaceGenManager::GetModelMap()))), (::fnv_006502f0::GetAtArgs)(name)) && node2 && data7 &&
                ((CacheData*)data7)->ready)
            {
                if (parent)
                {
                    TaskHandle task(new MeshTask(node2, data7));
                    reinterpret_cast<::QueuedFile *>((((MeshTask*)task)))->SetParent((::QueuedFile *)(parent));
                    ((MeshTask*)task)->Queue();
                }
                continue;
            }
            reinterpret_cast<::fnv_00447a40::FUN_00447a40_shell *>(this)->FUN_00447a40((char *)(name), priority, (::QueuedFile *)(parent), 1);
        }
    }
    else
    {
        MeshName other5;
        ::fnv_00653520::BuildEgmFilename((::fnv_00653520::StrMem *)(::MeshName *)(&other5), path2, -1);
        if (((::MeshCache *)(::BSFaceGenManager::GetModelMap())) && ::fnv_006502f0::LookupModelAndGetFlags((::fnv_006502f0::Map62d0 *)(((::MeshCache *)(::BSFaceGenManager::GetModelMap()))), (::fnv_006502f0::GetAtArgs)(other5)) && node2 && data7 &&
            ((CacheData*)data7)->ready)
        {
            if (parent)
            {
                TaskHandle taskOther4(new MeshTask(node2, data7));
                reinterpret_cast<::QueuedFile *>((((MeshTask*)taskOther4)))->SetParent((::QueuedFile *)(parent));
                ((MeshTask*)taskOther4)->Queue();
            }
            return;
        }
        reinterpret_cast<::fnv_00447a40::FUN_00447a40_shell *>(this)->FUN_00447a40((char *)(other5), priority, (::QueuedFile *)(parent), 1);
    }
}

struct RecursiveModelNode;
struct RecursiveModelChild
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual RecursiveModelNode* GetNode();
};
struct RecursiveModelNode
{
    unsigned int GetChildCount();
};
struct ModelPathComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* GetPath();
};
struct ModelForm
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    ModelPathComponent model;
};
struct ModelFormLookup
{
};
bool __cdecl FUN_0043b300(const void* type, const RecursiveModelNode* node);

struct RecursiveModelLoader
{
    ModelMapStub* models;
    ModelStub* Load(const char* path, bool a, bool b, int c, int d, int e);
    void LoadModelTree(RecursiveModelNode* node);
};
// @fnv 0x004489b0
void ModelLoader::UpdateReferenceNode(TESObjectREFR* reference, NiNode* node)
{
    if (node)
    {
        NiExtraData* extra = node->GetExtraData(FUN_00448a80());
        if (extra && reference)
        {
            NiExtraData* addon = extra;
            if (reinterpret_cast<::BSXFlags *>((addon))->GetAddon() && !reinterpret_cast<::FUN_00448a20_class *>((reference))->FUN_00448a20())
                reinterpret_cast<::RecursiveModelLoader *>(this)->LoadModelTree((::RecursiveModelNode *)(node));
        }
    }
}

// Recursively loads models for a node and its children: looks up the node's form, loads its model path if missing, then recurses into child nodes.
// @fnv 0x00448a90
void RecursiveModelLoader::LoadModelTree(RecursiveModelNode* node)
{
    if (!node)
        return;
    if (FUN_0043b300(&(*reinterpret_cast<int *>(&::g_01202de8)), node))
    {
        RecursiveModelNode* object = node;
        ModelForm* form = ((::ModelForm *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::ModelFormLookup * *>(&::g_dataHandler))))->GetAddonNodeByIndex(((unsigned int)(::FUN_009ee040((char *)(object)))))));
        if (form && !reinterpret_cast<::BGSAddonNode *>((form))->IsMasterParticleSystem())
        {
            ModelStub* model = 0;
            if (!models->Lookup(form->model.GetPath(), &model))
            {
                if (((::ModelStub *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(this)->FUN_00447080((char *)(form->model.GetPath()), false, true, 0, 0, 0))))
                {
                    if (models->Lookup(form->model.GetPath(), &model))
                        reinterpret_cast<::FUN_0043acb0_shell *>((model))->ReleaseScriptRunLock();
                }
            }
        }
    }
    for (unsigned int index = 0; index < node->GetChildCount(); ++index)
    {
        RecursiveModelChild* child = ((::RecursiveModelChild *)(reinterpret_cast<::NiNode *>((node))->GetAt(index)));
        if (child)
        {
            RecursiveModelNode* nested = child->GetNode();
            if (nested)
                LoadModelTree(nested);
        }
    }
}

struct R449_b
{
};

struct Q449_b
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RecursiveSpinLock lock;
    R449_b* FUN_00449f80(void* a1, int* a2);
    bool FUN_00449700(void* a1, int a2);
};

// Locks the lock, calls FUN_00449f80 with a1 and a2, invokes TryInsertAndFinish on the result, unlocks, and returns that bool.
// @fnv 0x00449700
bool Q449_b::FUN_00449700(void* a1, int iValue)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool res = reinterpret_cast<::Obj44 *>((FUN_00449f80(a1, &iValue)))->TryInsertAndFinish({}, {});
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return res;
}

class C44D510Object;

class C44D510Pointer
{
  public:
    C44D510Pointer& operator=(const C44D510Pointer& kOther);

    C44D510Object* m_pPointer;
};

class C44D510Entry
{
  public:
    bool IsPendingRemoval();

    int unk00;
    C44D510Pointer m_spValue;
};

class C44D510Iterator
{
  public:
    C44D510Entry* Get();
};


class C44D510Cache
{
  public:

    bool LookupAndUnlock(unsigned int uiKey, unsigned int uiHash, C44D510Pointer& spResult);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C44D510Iterator m_kIterator;
};

struct Traversal : Worker
{
    bool FindKeyInTraversal(int index, const int* key);
};
// Loops calling TryInsert, compares entries via FUN_004491c0, calls Finish or TryInsert again, then Release and returns whether it succeeded.
// @fnv 0x0044d3f0
bool Obj44::TryInsertAndFinish(int aiFirst, int aiSecond)
{
    bool result2 = false;
    while (1)
    {
        if (!reinterpret_cast<::Traversal *>(this)->FindKeyInTraversal(aiFirst, (const int *)(aiSecond)))
        {
            result2 = false;
            break;
        }
        TP44 first2(false, unk18.GetHead());
        TP44 second(true, unk18.GetHead());
        if (!FUN_004491c0(&unk14.GetEntry()->unk08, second, first2))
            continue;
        TP44 third(false, unk14.GetHead());
        if (FUN_004491c0(unk10, first2, third))
            reinterpret_cast<::fnv_00666510::FUN_00666510_Class *>(this)->AddRace((::fnv_00666510::TESRaceForm *)(unk14.GetHead()));
        else
            reinterpret_cast<::Traversal *>(this)->FindKeyInTraversal(aiFirst, (const int *)(aiSecond));
        result2 = true;
        break;
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return result2;
}
// Walks the traversal's linked nodes, syncing state, and returns true when a node's observed value equals *key.
// @fnv 0x0044e820
bool Traversal::FindKeyInTraversal(int index, const int* key)
{
    int* head = reinterpret_cast<int*>(reinterpret_cast<FUN_0044ee20_class*>(controller)->GetElementAddress(index));
    while (true)
    {
        bool initial = false;
        state = head;
        current = *reinterpret_cast<NodeLink*>(state);
        *reinterpret_cast<SyncNode**>(unk08) = current.ClearLowBit();
        FUN_0040fbe0();
        StateValue retry;
        reinterpret_cast<::FUN_006ecba0_class *>(&(retry))->FUN_006ecba0(false, current.ClearLowBit());
        if (FUN_00559450(state) != ::FUN_00559450((int *)&(retry)))
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *reinterpret_cast<NodeLink*>(&current.FUN_0044df00()->state);
            *reinterpret_cast<SyncNode**>(unk04) = pending.ClearLowBit();
            FUN_0040fbe0();
            if (FUN_00559450(reinterpret_cast<int*>(&pending)) != FUN_00559450(&current.FUN_0044df00()->state))
            {
                initial = true;
                break;
            }
            int observed = current.ClearLowBit()->unk04;
            StateValue value;
            reinterpret_cast<::FUN_006ecba0_class *>(&(value))->FUN_006ecba0(false, current.ClearLowBit());
            if (FUN_00559450(state) != ::FUN_00559450((int *)&(value)))
            {
                initial = true;
                break;
            }
            if (!FUN_0044dff0(reinterpret_cast<int*>(&pending)))
            {
                if (observed == *key)
                    return true;
                state = &current.FUN_0044df00()->state;
                *reinterpret_cast<SyncNode**>(unk0c) = current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                StateValue next;
                reinterpret_cast<::FUN_006ecba0_class *>(&(next))->FUN_006ecba0(false, pending.ClearLowBit());
                if (::FUN_004491c0((volatile long *)(state), ::FUN_00559450((int *)&(next)), ::FUN_00559450((int *)&(value))))
                {
                    reinterpret_cast<::fnv_00666510::FUN_00666510_Class *>(this)->AddRace((::fnv_00666510::TESRaceForm *)(::SyncNode *)(current.ClearLowBit()));
                }
                else
                {
                    initial = true;
                    break;
                }
            }
            current = pending;
            *reinterpret_cast<SyncNode**>(unk08) = pending.ClearLowBit();
            FUN_0040fbe0();
        }
        if (initial)
            continue;
    }
}

class B44F890Setting
{
  public:
};

class B44F890Node
{
  public:
};

class B44F890Collection
{
  public:
    B44F890Node* GetNextNode(B44F890Node* pkNode);
    int FUN_0044f890(int iArg);
};

// @fnv 0x0044f890
int B44F890Collection::FUN_0044f890(int iArg)
{
    AutoMemHelper kMemHelper(9, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\Setting.h", 0x326);
    B44F890Node* pkNode = ((::B44F890Node *)(::FUN_0044faa0((char *)this)));
    int iCount = 0;
    while (pkNode)
    {
        reinterpret_cast<::FUN_00c33280_Class *>(((*((::B44F890Setting **)(new ((void *)(pkNode)) ::Vec3())))))->FUN_00c33280((::NiTPrimitiveArray_unsigned_int_ *)(iArg));
        pkNode = GetNextNode(pkNode);
        iCount++;
    }
    return iCount;
}

struct FUN_00490fa0_lk
{
    FUN_00490fa0_lk(int v);
    ~FUN_00490fa0_lk();
    int v;
};

struct FUN_00490fa0_src
{
};

struct FUN_00490fa0_dst
{
};

class FUN_00490fa0_cls
{
  public:
    void FUN_00490fa0(FUN_00490fa0_src* p);
};
// @fnv 0x0043e9b0
void FUN_0043e9b0_s::FUN_0043e9b0()
{
    if (!::FUN_00449130((int *)(((FUN_00449130_s*)this))))
    {
        reinterpret_cast<::FUN_00490fa0_cls *>((((FUN_00490fa0_s*)*(void**)((char*)this + 0x38))))->FUN_00490fa0((::FUN_00490fa0_src *)((unsigned int)*(Flt_s*)((char*)this + 0x30)));
        if (*(void**)((char*)this + 0x3c))
            ((FUN_0043ea30_s*)*(void**)((char*)this + 0x3c))->FUN_0043ea30();
    }
}

// @fnv 0x00490fa0
void FUN_00490fa0_cls::FUN_00490fa0(FUN_00490fa0_src* pSource)
{
    FUN_00490fa0_lk lk(((int)(reinterpret_cast<::TESRegionDataMap *>((pSource))->GetRegionMapName())));
    if (FUN_00559450((int*)&lk) == 0)
        return;
    FUN_0043be10((char*)pSource);
    FUN_0043be10((char*)pSource);
    reinterpret_cast<::Callees *>((reinterpret_cast<FUN_00490fa0_dst*>((char*)this + 0x104)))->FUN_00905820(&pSource);
}

struct SearchController
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual bool Accept(int, int);
    virtual bool Finish(int, int);
};
struct SearchWorker
{
    SearchController* controller;
    SyncNode** pendingGuard;
    SyncNode** currentGuard;
    SyncNode** removedGuard;
    int* state;
    NodeLink current;
    NodeLink pending;
    void FUN_005292a0(SyncNode*);
    bool ProcessNode(int key, int output);
};
// Finds the entry for uiKey/uiHash, copies its value into spResult, yields, and unlocks; returns false if the entry is pending removal.
// @fnv 0x0044d510
bool C44D510Cache::LookupAndUnlock(unsigned int uiKey, unsigned int uiHash, C44D510Pointer& spResult)
{
    bool bFound = reinterpret_cast<::SearchWorker *>(this)->ProcessNode(uiKey, uiHash);
    if (bFound)
    {
        reinterpret_cast<::NP_0092c820 *>((void *)&(const ::C44D510Pointer &)(spResult))->FUN_0092c820((const ::NP_0092c820 &)(m_kIterator.Get()->m_spValue));
        ::FUN_0040fbe0();
        if (m_kIterator.Get()->IsPendingRemoval())
            bFound = false;
    }
    reinterpret_cast<::FUN_00529000_cls *>(this)->FUN_00529000();
    return bFound;
}
// Walks the node chain from controller->GetElementAddress(key), validating links and calling controller->Accept/Finish or FUN_005292a0 on each node.
// @fnv 0x00529030
bool SearchWorker::ProcessNode(int key, int output)
{
    int* head = (int*)reinterpret_cast<::FUN_0044ee20_class *>((controller))->GetElementAddress(key);
    while (true)
    {
        bool p = false;
        state = head;
        current = *(NodeLink*)state;
        *currentGuard = current.ClearLowBit();
        FUN_0040fbe0();
        StateValue j;
        reinterpret_cast<::FUN_006ecba0_class *>(&(j))->FUN_006ecba0(false, current.ClearLowBit());
        if (FUN_00559450(state) != ::FUN_00559450((int *)&(j)))
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *(NodeLink*)&current.FUN_0044df00()->state;
            *pendingGuard = pending.ClearLowBit();
            FUN_0040fbe0();
            if (FUN_00559450((int*)&pending) != FUN_00559450(&current.FUN_0044df00()->state))
            {
                p = true;
                break;
            }
            int e = current.ClearLowBit()->unk00;
            StateValue h;
            reinterpret_cast<::FUN_006ecba0_class *>(&(h))->FUN_006ecba0(false, current.ClearLowBit());
            if (FUN_00559450(state) != ::FUN_00559450((int *)&(h)))
            {
                p = true;
                break;
            }
            if (!FUN_0044dff0((int*)&pending))
            {
                if (controller->Accept(e, output))
                    return controller->Finish(e, output);
                state = &current.FUN_0044df00()->state;
                *removedGuard = current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                StateValue desired;
                reinterpret_cast<::FUN_006ecba0_class *>(&(desired))->FUN_006ecba0(false, pending.ClearLowBit());
                if (::FUN_004491c0((volatile long *)(state), ::FUN_00559450((int *)&(desired)), ::FUN_00559450((int *)&(h))))
                    reinterpret_cast<::fnv_005292a0::FUN_005292a0 *>(this)->SetRace((unsigned int)(current.ClearLowBit()));
                else
                {
                    p = true;
                    break;
                }
            }
            current = pending;
            *currentGuard = pending.ClearLowBit();
            FUN_0040fbe0();
        }
        if (p)
            continue;
    }
}

struct Form3;
struct Cell3;
struct Render3;
struct Other3;
struct Position3;
struct Radio3;
struct Ref3;
struct Obj3;
struct Proc3;
struct Vec3s
{
    float x, y, z;
};
struct Mat3s
{
    float a, b, c, d, e, f, g, h, i;
    Mat3s();
};
struct Fixed3
{
    operator const char*() const;
};
struct Ptr3
{
    Obj3* p;
    Ptr3(Obj3*);
    ~Ptr3();
    operator Obj3*() const;
    Ptr3& operator=(Obj3*);
};
struct Text3
{
    char* p;
    Text3();
    operator char*() const;
};
struct Flags3
{
    int bits;
    Flags3(int);
    Flags3(const Flags3&);
};
struct Extra3
{
};
struct Prim3
{
    void Clear();
};
struct Update3
{
    float time;
    bool a, b;
    int flags;
    Update3(float, bool, bool);
};
struct Obj3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual Obj3* AsNode();
    virtual Obj3* AsOther();
    Fixed3& GetName();
    bool Cleanup();
    void Clear();
    void Update(Update3&);
};
struct Proc3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual void unused15c();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual void unused1d0();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void unused1f0();
    virtual void unused1f4();
    virtual void unused1f8();
    virtual void unused1fc();
    virtual void unused200();
    virtual void unused204();
    virtual void unused208();
    virtual void unused20c();
    virtual void unused210();
    virtual void unused214();
    virtual void unused218();
    virtual void unused21c();
    virtual void unused220();
    virtual void unused224();
    virtual void unused228();
    virtual void unused22c();
    virtual void unused230();
    virtual void unused234();
    virtual void unused238();
    virtual void unused23c();
    virtual void unused240();
    virtual void unused244();
    virtual void unused248();
    virtual void unused24c();
    virtual void unused250();
    virtual void unused254();
    virtual void unused258();
    virtual void unused25c();
    virtual void unused260();
    virtual void unused264();
    virtual void unused268();
    virtual void unused26c();
    virtual void unused270();
    virtual void unused274();
    virtual void unused278();
    virtual void unused27c();
    virtual void unused280();
    virtual void unused284();
    virtual void unused288();
    virtual void unused28c();
    virtual void unused290();
    virtual void unused294();
    virtual void unused298();
    virtual void unused29c();
    virtual void unused2a0();
    virtual void unused2a4();
    virtual void unused2a8();
    virtual void unused2ac();
    virtual void unused2b0();
    virtual void unused2b4();
    virtual void unused2b8();
    virtual void unused2bc();
    virtual void unused2c0();
    virtual void unused2c4();
    virtual void unused2c8();
    virtual void unused2cc();
    virtual void unused2d0();
    virtual void unused2d4();
    virtual void unused2d8();
    virtual void unused2dc();
    virtual void unused2e0();
    virtual void unused2e4();
    virtual void unused2e8();
    virtual void unused2ec();
    virtual void unused2f0();
    virtual void unused2f4();
    virtual void unused2f8();
    virtual void unused2fc();
    virtual void unused300();
    virtual void unused304();
    virtual void unused308();
    virtual void unused30c();
    virtual void unused310();
    virtual void unused314();
    virtual void unused318();
    virtual void unused31c();
    virtual void unused320();
    virtual void unused324();
    virtual void unused328();
    virtual void unused32c();
    virtual void unused330();
    virtual void unused334();
    virtual void unused338();
    virtual void unused33c();
    virtual void unused340();
    virtual void unused344();
    virtual void unused348();
    virtual void unused34c();
    virtual void unused350();
    virtual void unused354();
    virtual void unused358();
    virtual void unused35c();
    virtual void unused360();
    virtual void unused364();
    virtual void unused368();
    virtual void unused36c();
    virtual void unused370();
    virtual void unused374();
    virtual void unused378();
    virtual void unused37c();
    virtual void unused380();
    virtual void unused384();
    virtual void unused388();
    virtual void unused38c();
    virtual void unused390();
    virtual void unused394();
    virtual void unused398();
    virtual void unused39c();
    virtual void unused3a0();
    virtual void unused3a4();
    virtual void unused3a8();
    virtual void unused3ac();
    virtual void unused3b0();
    virtual void unused3b4();
    virtual void unused3b8();
    virtual void unused3bc();
    virtual void unused3c0();
    virtual void unused3c4();
    virtual void unused3c8();
    virtual void unused3cc();
    virtual void unused3d0();
    virtual void unused3d4();
    virtual void unused3d8();
    virtual void unused3dc();
    virtual void unused3e0();
    virtual void unused3e4();
    virtual void unused3e8();
    virtual void unused3ec();
    virtual void unused3f0();
    virtual void unused3f4();
    virtual void unused3f8();
    virtual void unused3fc();
    virtual void unused400();
    virtual void unused404();
    virtual void unused408();
    virtual void unused40c();
    virtual void unused410();
    virtual void unused414();
    virtual void unused418();
    virtual void unused41c();
    virtual void unused420();
    virtual void unused424();
    virtual void unused428();
    virtual void unused42c();
    virtual void unused430();
    virtual void unused434();
    virtual void unused438();
    virtual void unused43c();
    virtual void unused440();
    virtual void unused444();
    virtual void unused448();
    virtual void unused44c();
    virtual void unused450();
    virtual void unused454();
    virtual void unused458();
    virtual void unused45c();
    virtual void unused460();
    virtual void unused464();
    virtual void unused468();
    virtual void unused46c();
    virtual void unused470();
    virtual void unused474();
    virtual void unused478();
    virtual void unused47c();
    virtual void unused480();
    virtual void unused484();
    virtual void unused488();
    virtual void unused48c();
    virtual void unused490();
    virtual void unused494();
    virtual void unused498();
    virtual void unused49c();
    virtual void unused4a0();
    virtual void unused4a4();
    virtual void unused4a8();
    virtual void unused4ac();
    virtual void unused4b0();
    virtual void unused4b4();
    virtual void unused4b8();
    virtual void unused4bc();
    virtual void unused4c0();
    virtual void unused4c4();
    virtual void unused4c8();
    virtual void unused4cc();
    virtual void unused4d0();
    virtual void unused4d4();
    virtual void unused4d8();
    virtual void unused4dc();
    virtual void unused4e0();
    virtual void unused4e4();
    virtual void unused4e8();
    virtual void unused4ec();
    virtual void unused4f0();
    virtual void unused4f4();
    virtual void unused4f8();
    virtual void ClearE(int);
    virtual void unused500();
    virtual void unused504();
    virtual void unused508();
    virtual void unused50c();
    virtual void unused510();
    virtual void unused514();
    virtual void unused518();
    virtual void unused51c();
    virtual void unused520();
    virtual void unused524();
    virtual void unused528();
    virtual void unused52c();
    virtual void unused530();
    virtual void unused534();
    virtual void unused538();
    virtual void unused53c();
    virtual void unused540();
    virtual void unused544();
    virtual void unused548();
    virtual void unused54c();
    virtual void unused550();
    virtual void unused554();
    virtual void unused558();
    virtual void unused55c();
    virtual void unused560();
    virtual void unused564();
    virtual void unused568();
    virtual void unused56c();
    virtual void unused570();
    virtual void unused574();
    virtual void unused578();
    virtual void unused57c();
    virtual void unused580();
    virtual void unused584();
    virtual void unused588();
    virtual void unused58c();
    virtual void unused590();
    virtual void unused594();
    virtual void unused598();
    virtual void unused59c();
    virtual void unused5a0();
    virtual void unused5a4();
    virtual void unused5a8();
    virtual void unused5ac();
    virtual void unused5b0();
    virtual void unused5b4();
    virtual void unused5b8();
    virtual void unused5bc();
    virtual void unused5c0();
    virtual void unused5c4();
    virtual void unused5c8();
    virtual void unused5cc();
    virtual void unused5d0();
    virtual void unused5d4();
    virtual void unused5d8();
    virtual void unused5dc();
    virtual void unused5e0();
    virtual void unused5e4();
    virtual void unused5e8();
    virtual void unused5ec();
    virtual void unused5f0();
    virtual void ClearD(int);
    virtual void unused5f8();
    virtual void unused5fc();
    virtual void unused600();
    virtual void unused604();
    virtual void unused608();
    virtual void unused60c();
    virtual void unused610();
    virtual void unused614();
    virtual void unused618();
    virtual void unused61c();
    virtual void unused620();
    virtual void unused624();
    virtual void unused628();
    virtual void unused62c();
    virtual void unused630();
    virtual void unused634();
    virtual void unused638();
    virtual void unused63c();
    virtual void unused640();
    virtual void unused644();
    virtual void unused648();
    virtual void unused64c();
    virtual void unused650();
    virtual void unused654();
    virtual void unused658();
    virtual void unused65c();
    virtual void unused660();
    virtual void unused664();
    virtual void unused668();
    virtual void unused66c();
    virtual void unused670();
    virtual void unused674();
    virtual void unused678();
    virtual void unused67c();
    virtual void unused680();
    virtual void unused684();
    virtual void unused688();
    virtual void unused68c();
    virtual void unused690();
    virtual void unused694();
    virtual void unused698();
    virtual void unused69c();
    virtual void unused6a0();
    virtual void unused6a4();
    virtual void unused6a8();
    virtual void unused6ac();
    virtual void unused6b0();
    virtual void unused6b4();
    virtual void unused6b8();
    virtual void unused6bc();
    virtual void unused6c0();
    virtual void unused6c4();
    virtual void unused6c8();
    virtual void unused6cc();
    virtual void unused6d0();
    virtual void unused6d4();
    virtual void unused6d8();
    virtual void unused6dc();
    virtual void unused6e0();
    virtual void unused6e4();
    virtual void unused6e8();
    virtual void unused6ec();
    virtual void unused6f0();
    virtual void unused6f4();
    virtual void unused6f8();
    virtual void unused6fc();
    virtual void unused700();
    virtual void unused704();
    virtual void unused708();
    virtual void unused70c();
    virtual void unused710();
    virtual void unused714();
    virtual void unused718();
    virtual void unused71c();
    virtual void unused720();
    virtual void unused724();
    virtual void unused728();
    virtual void unused72c();
    virtual void unused730();
    virtual void unused734();
    virtual void unused738();
    virtual void unused73c();
    virtual void unused740();
    virtual void unused744();
    virtual void unused748();
    virtual void unused74c();
    virtual void unused750();
    virtual void unused754();
    virtual void unused758();
    virtual void unused75c();
    virtual void unused760();
    virtual void unused764();
    virtual void unused768();
    virtual void unused76c();
    virtual void unused770();
    virtual void unused774();
    virtual void unused778();
    virtual void unused77c();
    virtual void unused780();
    virtual void unused784();
    virtual void unused788();
    virtual void unused78c();
    virtual void unused790();
    virtual void ClearB(int);
    virtual void unused798();
    virtual void ClearA(int);
    virtual void unused7a0();
    virtual void ClearC(int);
};
struct Parent3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void Attach(Obj3*, bool);
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void Detach(Obj3*);
};
struct Delete3
{
    virtual ~Delete3();
};
struct Ref3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void Mark(int);
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual bool IsSpecial();
    virtual bool IsActor();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual bool IsObstacle();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual Obj3* SoundObject();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void ClearSlot(int);
    virtual void unused1f4();
    virtual void unused1f8();
    virtual void unused1fc();
    virtual void unused200();
    virtual void unused204();
    virtual void unused208();
    virtual void unused20c();
    virtual void unused210();
    virtual void unused214();
    virtual void unused218();
    virtual void unused21c();
    virtual void unused220();
    virtual bool HasSound();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    Form3* base;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    Cell3* cell;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    Render3* render;
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
    Delete3* owned;
    Other3* other;
    void FUN_005702e0(Obj3*, bool);
    Proc3* Process();
    int ProcessLevel();
    void ClearX(int);
    void SetFlag(unsigned int, bool);
};
struct Form3
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void Notify(Ref3*);
    int Type();
};
struct Cell3
{
};
struct Render3
{
    int a, b, c, d, e;
    Ptr3 object;
};
struct Other3
{
    void Clear(int);
};
struct Position3
{
    int a, b, c, d;
    Vec3s position;
};
struct Radio3
{
    void Clear(int);
};
struct Loader3
{
    void Remove(Ref3*);
};
struct Queue3
{
    void Detach(Obj3*);
};
struct Scene3
{
};
struct World3
{
    void Remove(Ref3*);
};
struct Vats3
{
    void Remove(Ref3*);
};
struct Save3
{
};
struct Load3
{
};
struct Audio3
{
    void Remove(Obj3*, float, bool);
};
struct Nav3
{
    void Add(Ref3*);
    void Remove(Ref3*);
    void Update(Ref3*);
};
struct BaseState3
{
};

void baseNotify3(Form3*, Ref3*);
// Swaps the reference's 3D object for replacement, detaching and cleaning up the old one and attaching the new one with its saved transform.
// @fnv 0x005702e0
void Ref3::FUN_005702e0(Obj3* replacement, bool warn)
{
    if (((::Obj3 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) == replacement)
    {
        if (!replacement)
        {
            reinterpret_cast<::fnv_00445570::FUN_00445570_cls *>((((Loader3*)g_modelLoader)))->FUN_00445570((unsigned int)(this));
            reinterpret_cast<::RefObj *>(this)->FUN_00579ac0(false);
        }
        return;
    }
    if (((::Obj3 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) && !((::Obj3 *)(reinterpret_cast<::FUN_009611e0_shell *>((((::Obj3 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))))->FUN_009611e0())))
        reinterpret_cast<::fnv_00445570::FUN_00445570_cls *>((((Loader3*)g_modelLoader)))->FUN_00445570((unsigned int)(this));
    if (render && (Obj3*)render->object && !replacement && IsActor() && ((::Proc3 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())) && ProcessLevel() <= 1)
    {
        if (warn)
            ::FUN_005b5e40();
        Proc3* process = ((::Proc3 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()));
        process->ClearA(0);
        process->ClearB(0);
        process->ClearC(0);
        reinterpret_cast<::FUN_0092b7f0_Class *>((process))->ClearState();
    }
    if (render)
        render->b = 0;
    Prim3* c = (Prim3*)((void *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::Extra3 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041fbe0()));
    if (!replacement && c)
        reinterpret_cast<::fnv_004a4c50::FUN_004a4c50_Class *>((c))->ClearSlots();
    if (!replacement)
        reinterpret_cast<::fnv_0056fcb0::XObj *>(this)->FUN_0056fcb0();
    Vec3s e = ((::Position3 *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList()))->position;
    Mat3s rotation4;
    float scale4 = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>(this)->FUN_00567400();
    Parent3* parentTmp = 0;
    Ref3* actor17 = 0;
    if (IsActor())
        actor17 = this;
    if (((::Obj3 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) && replacement && base && base->Type() == 0x25)
        return;
    if (reinterpret_cast<::FUN_00452370_shell *>(this)->FUN_00452370() && reinterpret_cast<::FUN_0041b6b0_shell *>((((::Extra3 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041b6b0() != 0.0)
    {
        if (((::Obj3 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) && !replacement)
            reinterpret_cast<::FUN_004778a0_cls *>((((::BaseState3 *)(::FUN_00475400(((::Form3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())))))))->ReleaseScriptRunLock();
        else if (replacement && !((::Obj3 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())))
            reinterpret_cast<::FUN_00477780_shell *>((((::BaseState3 *)(::FUN_00475400(((::Form3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())))))))->FUN_00477780((::TESBoundObject *)(::Form3 *)(((::Form3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))));
    }
    Ptr3 oldVar(((::Obj3 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())));
    if ((Obj3*)oldVar)
    {
        parentTmp = (Parent3*)((::Obj3 *)(reinterpret_cast<::FUN_009611e0_shell *>((((Obj3*)oldVar)))->FUN_009611e0()));
        if (parentTmp)
        {
            if (!(reinterpret_cast<::FUN_004077c0_shell *>(this)->FUN_004077c0() && base && base->Type() == 0x25))
            {
                if (FUN_008c7aa0())
                    reinterpret_cast<::fnv_0087ac60::FUN_0087AC60_Holder *>((((::Queue3 *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087ac60((::fnv_0087ac60::G00559a40 *)(::Obj3 *)(oldVar));
                else
                    parentTmp->Detach(oldVar);
            }
            e = (*(::Vec3s *)&(reinterpret_cast<::NiAVObject *>((((Obj3*)oldVar)))->FUN_0043c490()));
            rotation4 = (*(::Mat3s *)(::FUN_006a9540((char *)(((Obj3*)oldVar)))));
            scale4 = reinterpret_cast<::FUN_009cdae0_shell *>((((Obj3*)oldVar)))->GetFloatAt64();
        }
        ::FUN_00b5b1c0((::ShadowSceneNode *)(((::Scene3 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))), (int)(oldVar), {});
        if (IsSpecial())
            reinterpret_cast<::MultiBoundManagerB5E *>((((::Scene3 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->RemoveBoundByOwner(oldVar);
        if (!replacement)
        {
            bool cleaned = false;
            Obj3* otherObj = ((Obj3*)oldVar)->AsOther();
            if (otherObj)
            {
                reinterpret_cast<::Dummy_0056c7d0 *>((otherObj))->FUN_0056c7d0(0);
                cleaned = otherObj->Cleanup();
            }
            if (reinterpret_cast<::FUN_00456630_helper *>((((Obj3*)oldVar)))->FUN_00570ea0())
                ::fnv_00578250::FUN_00578250((::fnv_00578250::NiAVObject *)(::Obj3 *)(((Obj3*)oldVar)->AsNode()));
            reinterpret_cast<::FUN_00568480_cls *>(this)->FUN_00568480();
            reinterpret_cast<::FUN_009c9e90_shell *>(&((*reinterpret_cast<::Vats3 *>(&::g_011f2250))))->RemoveCommandsForTarget((::TESObjectREFR *)(::Ref3 *)(this));
            if (!reinterpret_cast<::FUN_00440d80_shell *>(this)->FUN_00440d80() && reinterpret_cast<::fnv_00570f00::FUN_00570f00_shell *>(((*reinterpret_cast<::Save3 * *>(&::g_BGSSaveLoadGame))))->FUN_00570f00())
            {
                if (reinterpret_cast<::BGSSaveLoadGame *>(((*reinterpret_cast<::Save3 * *>(&::g_BGSSaveLoadGame))))->HasFormChangeFlags((::TESForm *)(::Ref3 *)(this), (*(::FormChangeMask *)&(const ::Flags3 &)(Flags3(4)))))
                {
                    Text3 data;
                    reinterpret_cast<::SubBufferSaveShell *>(&(data))->FUN_00865020((::TESForm *)(::Ref3 *)(this));
                    reinterpret_cast<::FUN_00422ac0_shell *>((((::Extra3 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00422ac0(data);
                }
                if (reinterpret_cast<::BGSSaveLoadGame *>(((*reinterpret_cast<::Save3 * *>(&::g_BGSSaveLoadGame))))->HasFormChangeFlags((::TESForm *)(::Ref3 *)(this), (*(::FormChangeMask *)&(const ::Flags3 &)(Flags3(0x10000000)))))
                {
                    bool save = false;
                    if (!IsActor())
                        save = reinterpret_cast<::Ref563530 *>(this)->FUN_00563530();
                    if (save)
                    {
                        Text3 data;
                        reinterpret_cast<::F4F20Queue *>(&(data))->QueueResponseForRef((::F4F20Ref *)(::Ref3 *)(this));
                        reinterpret_cast<::FUN_00422940_shell *>((((::Extra3 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00422940(data);
                    }
                    else
                        Mark(0x10000000);
                }
            }
            ClearX(0);
            reinterpret_cast<::RefrStub *>(this)->FUN_00572e50((::FormStub *)(0));
            if (actor17)
            {
                reinterpret_cast<::BipedAnim *>(this)->AttachFaceGenNode();
                reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(0);
                reinterpret_cast<::TESForm *>(this)->ClearData();
                reinterpret_cast<::TESForm *>(this)->ClearData();
            }
            ClearSlot(0);
            bool collision9 = ::FUN_005784b0((::NiNode *)(::Obj3 *)(((Obj3*)oldVar)->AsNode()));
            reinterpret_cast<::FUN_0056c880_S *>(this)->FUN_0056c880(2, collision9);
            if (collision9)
                ::fnv_00578300::FUN_00578300((::NiNode *)(::Obj3 *)(oldVar));
            if (actor17)
            {
                Ref3* ref = this;
                if (ref)
                {
                    Other3* physics = ((::Other3 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((ref))->FUN_009306d0()));
                    if (physics)
                        reinterpret_cast<::S_00c6d7a0_Obj *>((physics))->FUN_00c6d7a0(0);
                    if (((::Proc3 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((ref))->GetBaseTexture())))
                        ((::Proc3 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((ref))->GetBaseTexture()))->ClearD(0);
                }
                if (actor17->owned)
                {
                    delete actor17->owned;
                    actor17->owned = 0;
                }
                if (actor17->other)
                    reinterpret_cast<::FUN_00ca20e0_Class *>((actor17->other))->ClearAndFreeEntries();
            }
            if (cleaned || HasSound() || IsSpecial())
                reinterpret_cast<::FUN_00ad8570_S *>((((::Audio3 *)(::FUN_00453a70()))))->FUN_00ad8570((int)(SoundObject()), 0.0f, false);
            reinterpret_cast<::fnv_0057a3c0::FUN_0057a3c0_shell *>(this)->FUN_0057a3c0(true);
        }
        if (!cell || !((bool)(reinterpret_cast<::FUN_00570ec0 *>((cell))->Get())))
        {
            reinterpret_cast<::FUN_009749b0_shell *>(&((*reinterpret_cast<::World3 *>(&::g_011e0e80))))->FUN_009749b0((int)(this));
            if (FUN_00570f60() > 0)
                ::FUN_008cddd0((::MobileObject *)(::Ref3 *)(this), true);
        }
        if (actor17 && actor17 != (*reinterpret_cast<::Ref3 * *>(&::_g_thePlayer)))
        {
            Proc3* process = ((::Proc3 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor17))->GetBaseTexture()));
            if (process && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((process))->FUN_0045cd60())) <= 1)
            {
                Proc3* high = process;
                high->ClearE(0);
            }
            ::FUN_00868660((::NiAVObject *)(::Obj3 *)(oldVar));
        }
        else
            ::FUN_00c45830((::MyRef *)(::Obj3 *)(oldVar));
        bool flag = reinterpret_cast<::Holder4523e0 *>(this)->FUN_004523e0(4);
        oldVar = 0;
        reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((int)(0));
        if (!replacement && base)
        {
            if (!reinterpret_cast<::FUN_005651e0_shell *>(this)->FUN_005651e0())
            {
                if (!flag)
                    base->Notify(this);
            }
            else
                reinterpret_cast<::fnv_00445570::FUN_00445570_cls *>((((Loader3*)g_modelLoader)))->FUN_00445570((unsigned int)(this));
        }
    }
    else if (!replacement)
        reinterpret_cast<::fnv_00445570::FUN_00445570_cls *>((((Loader3*)g_modelLoader)))->FUN_00445570((unsigned int)(this));
    if (!replacement)
        reinterpret_cast<::RefObj *>(this)->FUN_00579ac0(false);
    reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((int)(replacement));
    if (replacement && parentTmp)
    {
        reinterpret_cast<::FUN_00440460_S *>((replacement))->FUN_00440460((const ::V3 *)&(e));
        reinterpret_cast<::FUN_0043fa80_s *>((replacement))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation4)));
        reinterpret_cast<::FUN_00440490_shell *>((replacement))->FUN_00440490(scale4);
        parentTmp->Attach(replacement, true);
        ::FUN_00c6bd00((::TreeNode_cls *)(replacement), true);
        reinterpret_cast<::FUN_00a5a040_Class *>((replacement))->FUN_00a5a040();
        Update3 update(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((replacement))->FUN_00a59c60((int)&(update));
    }
    if (replacement && base && base->Type() != 0x25)
        reinterpret_cast<::Dummy_0056c7d0 *>((replacement))->FUN_0056c7d0(this);
    if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::Load3 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && !replacement && ((::Radio3 *)(reinterpret_cast<::TESObjectREFR *>(this)->GetExtraRadioData())) && ((::Radio3 *)(reinterpret_cast<::TeleportableReference *>((((::Radio3 *)(reinterpret_cast<::TESObjectREFR *>(this)->GetExtraRadioData()))))->FUN_0043a2b0())))
        reinterpret_cast<::Cell548 *>((((::Radio3 *)(reinterpret_cast<::TeleportableReference *>((((::Radio3 *)(reinterpret_cast<::TESObjectREFR *>(this)->GetExtraRadioData()))))->FUN_0043a2b0()))))->FUN_00551480(0);
    if (IsObstacle())
    {
        if (replacement)
            reinterpret_cast<::fnv_006c0c30::Mgr006c0c30 *>((((::Nav3 *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0c30((::fnv_006c0c30::Actor *)(::Ref3 *)(this));
        else
            reinterpret_cast<::fnv_006c1cb0::Call_006c0c80 *>((((::Nav3 *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0c80((::fnv_006c1cb0::TESObjectREFR *)(::Ref3 *)(this));
    }
    if (!replacement && ((::Form3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) && ((::Form3 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->Type() == 0x1c)
        reinterpret_cast<::Own60 *>((((::Nav3 *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c1060((::s60::Ref *)(::Ref3 *)(this));
}

struct ControllerV
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual bool Call34(int, int);
    virtual bool Call38(int, int);
};

// @fnv 0x006662a0
bool Worker::ProcessNodeChain(int a1, int a2)
{
    int head7;
    bool flag_;
    StateValue svA2;
    StateValue svB;
    int nodeVal;
    StateValue svC2;
    head7 = ((FUN_0044ee20_class*)controller)->GetElementAddress(a1);
    while (1)
    {
        flag_ = 0;
        state = (int*)head7;
        current = *(NodeLink*)state;
        *(int*)unk08 = (int)current.ClearLowBit();
        FUN_0040fbe0();
        reinterpret_cast<::FUN_006ecba0_class *>(&(svA2))->FUN_006ecba0(0, current.ClearLowBit());
        if (::FUN_00559450((int *)(((StateValue*)state))) != ::FUN_00559450((int *)&(svA2)))
            continue;
        while (1)
        {
            if (!current.ClearLowBit())
                return false;
            pending = *(NodeLink*)&current.FUN_0044df00()->state;
            *(int*)unk04 = (int)pending.ClearLowBit();
            FUN_0040fbe0();
            if (::FUN_00559450((int *)(((StateValue*)&pending))) !=
                ::FUN_00559450((int *)(((StateValue*)&current.FUN_0044df00()->state))))
            {
                flag_ = 1;
                break;
            }
            nodeVal = *(int*)current.ClearLowBit();
            reinterpret_cast<::FUN_006ecba0_class *>(&(svB))->FUN_006ecba0(0, current.ClearLowBit());
            if (::FUN_00559450((int *)(((StateValue*)state))) != ::FUN_00559450((int *)&(svB)))
            {
                flag_ = 1;
                break;
            }
            if (!FUN_0044dff0((int*)&pending))
            {
                if (((ControllerV*)controller)->Call34(nodeVal, a2))
                    return ((ControllerV*)controller)->Call38(nodeVal, a2);
                state = &current.FUN_0044df00()->state;
                *(int*)unk0c = (int)current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                reinterpret_cast<::FUN_006ecba0_class *>(&(svC2))->FUN_006ecba0(0, pending.ClearLowBit());
                if (::FUN_004491c0((volatile long *)(state), ::FUN_00559450((int *)&(svC2)), ::FUN_00559450((int *)&(svB))))
                {
                    reinterpret_cast<::fnv_00666510::FUN_00666510_Class *>(this)->AddRace((::fnv_00666510::TESRaceForm *)(::SyncNode *)(current.ClearLowBit()));
                }
                else
                {
                    flag_ = 1;
                    break;
                }
            }
            current = pending;
            *(int*)unk08 = (int)pending.ClearLowBit();
            FUN_0040fbe0();
        }
        if (flag_)
            continue;
    }
}

struct MatchNode;
struct FUN_006ecba0
{
    MatchNode* value;
    MatchNode* ClearLowBit();
    MatchNode* FUN_0044df00();
    bool FUN_0044dff0();
    FUN_006ecba0(bool, MatchNode*);
};
struct FUN_0044e370
{
    void* value;
    FUN_0044e370(void*);
    ~FUN_0044e370();
};
struct MatchNode
{
    MatchNode* value;
    void* payload;
    FUN_006ecba0 next;
};
struct MatchMap
{
};
struct MatchOwner
{
    MatchMap* map;
    MatchNode** hazardNext;
    MatchNode** hazardCurrent;
    MatchNode** hazardRemoved;
    FUN_006ecba0* cursor;
    FUN_006ecba0 current;
    FUN_006ecba0 next;
    void FUN_005292a0(MatchNode*);
    bool FUN_00906820(unsigned int key, void* output);
};
// @fnv 0x00906820
bool MatchOwner::FUN_00906820(unsigned int key, void* output)
{
    FUN_006ecba0* bucket = ((::FUN_006ecba0 *)(reinterpret_cast<::FUN_0044ee20_class *>((map))->GetElementAddress(key)));
    while (true)
    {
        bool first = false;
        cursor = bucket;
        current = *cursor;
        *hazardCurrent = current.ClearLowBit();
        FUN_0040fbe0();
        FUN_006ecba0 retry(false, current.ClearLowBit());
        if (((unsigned int)(::FUN_00559450((int *)(cursor)))) != ((unsigned int)(::FUN_00559450((int *)&(retry)))))
            continue;
        while (true)
        {
            if (!current.ClearLowBit())
                return false;
            next = current.FUN_0044df00()->next;
            *hazardNext = next.ClearLowBit();
            FUN_0040fbe0();
            if (((unsigned int)(::FUN_00559450((int *)&(next)))) != ((unsigned int)(::FUN_00559450((int *)&(current.FUN_0044df00()->next)))))
            {
                first = true;
                break;
            }
            FUN_0044e370 observed(&current.ClearLowBit()->payload);
            FUN_006ecba0 ref(false, current.ClearLowBit());
            if (((unsigned int)(::FUN_00559450((int *)(cursor)))) != ((unsigned int)(::FUN_00559450((int *)&(ref)))))
            {
                first = true;
                break;
            }
            if (!next.FUN_0044dff0())
            {
                if (reinterpret_cast<::FUN_004b0460_class *>(&(observed))->FUN_004b0460((const void **)(output)))
                    return true;
                cursor = &current.FUN_0044df00()->next;
                *hazardRemoved = current.ClearLowBit();
                FUN_0040fbe0();
            }
            else
            {
                FUN_006ecba0 replacement(false, next.ClearLowBit());
                if (::FUN_004491c0((volatile long *)(cursor), ((unsigned int)(::FUN_00559450((int *)&(replacement)))), ((unsigned int)(::FUN_00559450((int *)&(ref))))))
                {
                    reinterpret_cast<::fnv_005292a0::FUN_005292a0 *>(this)->SetRace((unsigned int)(current.ClearLowBit()));
                }
                else
                {
                    first = true;
                    break;
                }
            }
            current = next;
            *hazardCurrent = next.ClearLowBit();
            FUN_0040fbe0();
        }
        if (first)
            continue;
    }
}


struct FUN_00ae78e0_Class
{
    struct SUB
    {
        long unk30;
        void* unk34;
    };
    char pad0[0x30];
    SUB sub;
    char pad38[0x10];
    unsigned char unk48;
    void ReleaseSemaphoreAndIncrement();
};

// If unk48 is set, releases one count on the semaphore at sub.unk34 and increments sub.unk30.
// @fnv 0x00ae78e0
void FUN_00ae78e0_Class::ReleaseSemaphoreAndIncrement()
{
    if (unk48 != 0)
    {
        SUB* v = &sub;
        ReleaseSemaphore(v->unk34, 1, 0);
        InterlockedIncrement(&v->unk30);
    }
}

namespace fnv_0043fc40 {
class NiAVObject;
struct FUN_0043fcd0_t
{
};
class BSOcclusionPlane
{
  public:
};
template <class C> class BSStringT
{
  public:
    operator const C*() const;
};
template <> class NiPointer<NiNode*>
{
  public:
    NiPointer<NiNode>& operator=(NiNode*);
};
class FUN_00565210_shell
{
  public:
};
struct FUN_00570f70_t
{
};
struct FUN_00451ef0_t
{
};

class FUN_0043fc40_t
{
  public:
    char _pad[0x18];
    TESObjectREFR* m_pReference;
    BSStringT<char> m_kName;
    void FUN_0043fc40();
};

// @fnv 0x0043fc40
void FUN_0043fc40_t::FUN_0043fc40()
{
    if (!::FUN_00449130((int*)this) && m_pReference && !((::fnv_0043fc40::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((FUN_0043fcd0_t*)m_pReference)))->FUN_0043fcd0())))
    {
        reinterpret_cast<::fnv_00570f70::Obj570 *>((((FUN_00570f70_t*)m_pReference)))->FUN_00570f70((int)(m_kName));
        reinterpret_cast<::AttachmentHandler *>((((FUN_00451ef0_t*)::g_TES)))->FUN_00451ef0((::AttachRef *)(m_pReference), (::AttachCell *)(((int)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)m_pReference)))->GetTarget()))), (::AttachRef *)(0), 0);
        reinterpret_cast<::FUN_00565210_shell *>((((FUN_00565210_shell*)m_pReference)))->FUN_00565210(true);
    }
    else
    {
        *(NiPointer<NiNode*>*)&m_kName = 0;
    }
}
}  // namespace fnv_0043fc40

// DestroyAllStreams
struct MyAVObject : NiAVObject
{
};

struct ModelEntry
{
    int unk04;
    int unk08;
    ~ModelEntry();
};

struct KFModelEntry
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    MyAVObject* GetNode();
    ~KFModelEntry();
};

__declspec(align(4)) struct IterA
{
    int f00, f01, f02, f03, f04, f05, f06, f07, f08, f09;
    int f10, f11, f12, f13, f14, f15, f16, f17, f18, f19;
    int f20, f21, f22, f23, f24, f25, f26, f27, f28, f29;
    int f30, f31, f32, f33, f34, f35, f36, f37, f38, f39;
    int f40, f41, f42, f43, f44, f45, f46, f47, f48, f49;
    int f50, f51, f52, f53, f54, f55, f56, f57, f58, f59;
    int f60, f61, f62, f63, f64, f65, f66, f67, f68;
    IterA();
    ~IterA();
};

__declspec(align(4)) struct IterB
{
    void* vtable;
    int unk04;
    char* pathPtr;
    int unk0c;
    char path[260];
    IterB();
    ~IterB();
};

struct StreamObj
{
    virtual ~StreamObj();
    virtual void reservedA();
    virtual void reservedB();
    virtual void reservedC();
    virtual void reservedD();
    virtual void* processEntry(int);
    virtual void reservedE();
    virtual void reservedF();
    virtual void reservedG();
    virtual void reservedH();
    virtual void reservedI();
    virtual void reservedJ();
    virtual void reservedK();
    virtual void reservedL();
    virtual void reservedM();
    virtual void reservedN();
    virtual void reservedO();
    virtual int queryGate();
};

extern const char DAT_01016ea0[];
extern const char DAT_01016e70[];

struct Self
{
    StreamObj* m_00;
    StreamObj* m_04;
    StreamObj* m_08;
    StreamObj* m_0c;
    StreamObj* m_10;
    StreamObj* m_14;
    StreamObj* m_18;
    StreamObj* m_1c;
    StreamObj* m_20;
    StreamObj* m_24;
    StreamObj* m_28;
    void DestroyAllStreams();
};

// Clears both stream tables, warns about leftover entries, then deletes all stream objects held by the Self.
// @fnv 0x00442aa0
void Self::DestroyAllStreams()
{
    reinterpret_cast<::fnv_00443270::FUN_00443270_shell *>(this)->FUN_00443270((::fnv_00443270::File_443270 *)(0), 0);
    if (m_00->queryGate())
    {
        unsigned int a_count = 0;
        IterA m_iter;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(m_iter))->FUN_006ebde0())
        {
            int o = 0;
            ModelEntry* e = 0;
            if (reinterpret_cast<::Queue44c640 *>((m_00))->TryGetNextEntry((::QueueIter44c640 *)(void *)(&m_iter), (void **)(int *)(&o), (int)(&e), 1))
            {
                if (reinterpret_cast<::FUN_00443190_shell *>((e))->GetCombinedValue() > 0)
                    a_count++;
                delete e;
            }
        }
        if (a_count > 0)
            ::FUN_005b5e40();
    }

    IterB iterB;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(iterB))->FUN_006ebde0())
    {
        int c = 0;
        KFModelEntry* t = 0;
        if (reinterpret_cast<::Queue44c640 *>((m_04))->TryGetNextEntry((::QueueIter44c640 *)(void *)(&iterB), (void **)(int *)(&c), (int)(&t), 1) && t)
        {
            if (!((::MyAVObject *)(reinterpret_cast<::TESRegionDataMap *>((t))->GetRegionMapName())) || reinterpret_cast<::FUN_005f26c0_cls *>((((::MyAVObject *)(reinterpret_cast<::TESRegionDataMap *>((t))->GetRegionMapName()))))->FUN_005f26c0())
            {
                m_04->processEntry(c);
                delete t;
            }
        }
    }

    if (m_04->queryGate())
    {
        unsigned int countC = 0;
        IterB iterC;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(iterC))->FUN_006ebde0())
        {
            int c1 = 0;
            KFModelEntry* c2 = 0;
            if (reinterpret_cast<::Queue44c640 *>((m_04))->TryGetNextEntry((::QueueIter44c640 *)(void *)(&iterC), (void **)(int *)(&c1), (int)(&c2), 1))
            {
                if (::FUN_004431b0((int *)(c2)) > 0)
                    countC++;
                delete c2;
            }
        }
        if (countC > 0)
            ::FUN_005b5e40();
    }

    delete m_00;
    delete m_04;
    delete m_1c;
    delete m_18;
    delete m_14;
    delete m_10;
    delete m_08;
    delete m_0c;
    delete m_28;
    delete m_20;
    delete m_24;
}

namespace fnv_0043d180 {
extern "C" char DAT_01016840;
struct Guard43
{
    int x;
    Guard43(int, bool, char*, int);
    ~Guard43();
};
struct Update43
{
    int data[3];
};
struct Bound43
{
};
struct Fade43
{
};
struct Obj43
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Fade43* v4();
};
struct Model43
{
    void FUN_0092c870();
    Obj43* FUN_0043b230();
};
struct Ptr43
{
};
struct SettingI43
{
};
struct SettingF43
{
};
struct Vec43
{
    float x, y, z;
};
Vec43* __cdecl FUN_0056fc30(Vec43*, Obj43*);
struct Loader43
{
};
struct C43
{
    char pad[24];
    int field18;
    char pad1[20];
    Ptr43 ptr;
    int field34;
    int field38;
    void FUN_0043d180();
};
// Updates the fade node of the model's object: recomputes range from settings and radius, applies fade and field38, and reloads the model if needed.
// @fnv 0x0043d180
void C43::FUN_0043d180()
{
    Guard43 guard(field18, true, &DAT_01016840, 997);
    if (((::fnv_0043d180::Model43 *)(::FUN_00559450((int *)&(ptr)))))
    {
        if (reinterpret_cast<::FUN_0043d490_shell *>(this)->FUN_0043d490())
            reinterpret_cast<::FUN_0092c870_shell *>((((::fnv_0043d180::Model43 *)(::FUN_00559450((int *)&(ptr))))))->FUN_0092c870();
        if (!reinterpret_cast<::FUN_0043d4b0_shell *>(this)->FUN_0043d4b0() && ((::fnv_0043d180::Model43 *)(::FUN_00559450((int *)&(ptr))))->FUN_0043b230())
        {
            Fade43* node2 = ((::fnv_0043d180::Model43 *)(::FUN_00559450((int *)&(ptr))))->FUN_0043b230()->v4();
            if (node2)
            {
                Update43 update4;
                new ((void *)&(update4)) ::NiUpdateData(0.0f, false, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((node2))->FUN_00a59c60((int)&(update4));
                float radius = reinterpret_cast<::Twin_0084d030 *>(&((*(::fnv_0043d180::Bound43 *)(reinterpret_cast<::FUN_0043d450_Owner *>((node2))->FUN_0043d450()))))->GetStoredFloatValue();
                Vec43 vec3;
                if (radius < 0.0010000000474974513)
                    radius = FUN_0056fc30(&vec3, ((::fnv_0043d180::Model43 *)(::FUN_00559450((int *)&(ptr))))->FUN_0043b230())->z * 0.5;
                float maximum = 3.402823466e+38f;
                maximum = (*((unsigned int *)&(::FUN_0043d4d0((int *)(((SettingI43*)&(*reinterpret_cast<char *>(&::g_011c63cc))))))) << 12) * 0.5 - (radius + 2048.0);
                float scaled5 = radius * *((float *)&(::FUN_00403e20((float *)(((SettingF43*)&(*reinterpret_cast<char *>(&::g_011c3be4)))))));
                float range = radius != 0.0 && scaled5 < maximum ? scaled5 : maximum;
                if (reinterpret_cast<::FUN_00792760_shell *>(this)->FUN_00792760() != 0.0)
                    range = reinterpret_cast<::FUN_00792760_shell *>(this)->FUN_00792760();
                reinterpret_cast<::BSFadeNode *>((node2))->SetRange(range * *((float *)&(::FUN_00403e20((float *)(((SettingF43*)&(*reinterpret_cast<char *>(&::g_011c3bb8))))))), range);
                reinterpret_cast<::FUN_00b4dec0_shell *>((node2))->FUN_00b4dec0(field38);
            }
            if (!reinterpret_cast<::S_447010 *>(((*(Loader43**)&(*reinterpret_cast<char *>(&::g_modelLoader)))))->CallFoo(((int)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())), (int)(((::fnv_0043d180::Model43 *)(::FUN_00559450((int *)&(ptr)))))))
                reinterpret_cast<::FUN_004472a0_shell *>(((*(Loader43**)&(*reinterpret_cast<char *>(&::g_modelLoader)))))->FUN_004472a0((char *)(((int)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60()))), (void *)&(ptr));
        }
    }
    reinterpret_cast<::FUN_0043c610_shell *>(this)->RunVirtualMethod28();
}
}  // namespace fnv_0043d180

class NodePointer
{
    NiNode* node;

  public:
    NodePointer(NiNode*);
    operator NiNode*() const;
    ~NodePointer();
};
class TextureTask : public IOTask
{
  public:
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
    NiNode* model;
    bool loaded;
    TextureTask(BSFileEntry*, int);
    TextureTask(NiNode*, int);
};
class TextureTaskPointer
{
    TextureTask* task;

  public:
    TextureTaskPointer(TextureTask*);
    ~TextureTaskPointer();
    TextureTask* operator->() const;
};
class TextureNodeInfo
{
  public:
};
void* __cdecl operator new(unsigned int);
class TextureLoader
{
  public:
    bool QueueTextureLoad(BSFileEntry*, int, QueuedFile*);
};
namespace fnv_00443dc0 {
class QHeadLocal
{
  public:
};

class QNewFile;

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    NiPtr(T* p);
    operator T*() const;
    NiPtr<T>& operator=(T* p);
    ~NiPtr();
};

class QueueObj
{
  public:
    virtual void d0();
    virtual void d4();
    virtual void d8();
    virtual void dc();
    virtual void d10();
    virtual void* d14(QHeadLocal** out);
};

class QHolderObj
{
  public:
    virtual void h0();
    virtual void h4();
    virtual bool h8(void* arg);
};

class QNewFile
{
  public:
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
    QNewFile(QHeadLocal* p, int a);
    QNewFile(void* p, int a, int b, bool c, bool d);
    char pad[0x44];
};

class QueueModelHolder
{
  public:
    QHolderObj* m_pHolder;
    void FUN_00443dc0(int a1, QueueObj* a2, int a3, int a4, int a5, bool a6, bool a7, bool a8, float a9);
};

// @fnv 0x00443dc0
void QueueModelHolder::FUN_00443dc0(int pQueueObj, QueueObj* a2, int a3, int pParent, int a5, bool bFlag1, bool bFlag2,
                                    bool bFlag3, float fValue)
{
    QHeadLocal* pHead = 0;
    if (m_pHolder->h8(((QueueObj*)pQueueObj)->d14(&pHead)))
    {
        if (bFlag2)
        {
            reinterpret_cast<::FUN_0092c870_shell *>((pHead))->FUN_0092c870();
        }
        if (pParent)
        {
            NiPtr<QNewFile> sp(new QNewFile(pHead, a3));
            reinterpret_cast<::FUN_00444020_Class *>((((QNewFile*)sp)))->FUN_00444020(fValue);
            reinterpret_cast<::QueuedFile *>((((QNewFile*)sp)))->SetParent((::QueuedFile *)(::fnv_00443dc0::QNewFile *)((QNewFile*)pParent));
            ((QNewFile*)sp)->v28();
            reinterpret_cast<::NP_0092c820 *>((a2))->FUN_0092c820((const ::NP_0092c820 &)(sp));
            return;
        }
        reinterpret_cast<::FUN_006f74f0_cls *>((a2))->FUN_006f74f0((::ObjA *)(::fnv_00443dc0::QNewFile *)(0));
        return;
    }
    NiPtr<QNewFile> sp(new QNewFile((void*)pQueueObj, a3, a5, bFlag1, bFlag2));
    reinterpret_cast<::FUN_00444020_Class *>((((QNewFile*)sp)))->FUN_00444020(fValue);
    reinterpret_cast<::QueuedFile *>((((QNewFile*)sp)))->SetParent((::QueuedFile *)(::fnv_00443dc0::QNewFile *)((QNewFile*)pParent));
    reinterpret_cast<::FUN_00443ff0Class *>((((QNewFile*)sp)))->FUN_00443ff0(bFlag3);
    ((QNewFile*)sp)->v20();
    reinterpret_cast<::NP_0092c820 *>((a2))->FUN_0092c820((const ::NP_0092c820 &)(sp));
}
}  // namespace fnv_00443dc0

namespace fnv_00448080 {
struct Task448
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    Task448(void*, void*);
    char data[60];
};
struct Ref448
{
    void* p;
    Ref448(int);
    ~Ref448();
};
struct RefB448
{
    void* p;
    RefB448(int);
    ~RefB448();
};
struct String448
{
    void* p;
    int n;
    String448();
    ~String448();
};
struct Head448
{
    void* p;
    Head448(Task448*);
    ~Head448();
};
struct Manager448
{
};
int FUN_00406d50(char*, unsigned int, const char*);
struct Owner448
{
    void LoadTaskFromPath(Task448*, int, void*, int);
};
// @fnv 0x00448080
void Owner448::LoadTaskFromPath(Task448* pTask, int x, void* parent, int unused)
{
    Ref448 a(0);
    RefB448 b(0);
    char pathX[260];
    ::TaskQueueInterface::CopyStringToBuffer(pathX, 260, &DAT_01016fac);
    FUN_00406d50(pathX, 260, pTask->v5());
    String448 s3;
    ::fnv_00653520::BuildEgmFilename((::fnv_00653520::StrMem *)(::fnv_00448080::String448 *)(&s3), pathX, -1);
    if (((::fnv_00448080::Manager448 *)(::BSFaceGenManager::GetModelMap())) && ::fnv_006502f0::LookupModelAndGetFlags((::fnv_006502f0::Map62d0 *)(((::fnv_00448080::Manager448 *)(::BSFaceGenManager::GetModelMap()))), (::fnv_006502f0::GetAtArgs)(((void *)(::FUN_00559450((int *)&(s3)))))) && ((void *)(::FUN_00559450((int *)&(a)))) &&
        ((void *)(::FUN_00559450((int *)&(b)))))
    {
        if (parent)
        {
            Head448 h3(new Task448(((void *)(::FUN_00559450((int *)&(a)))), ((void *)(::FUN_00559450((int *)&(b))))));
            reinterpret_cast<::QueuedFile *>((((::fnv_00448080::Task448 *)(::FUN_00559450((int *)&(h3))))))->SetParent((::QueuedFile *)(parent));
            ((::fnv_00448080::Task448 *)(::FUN_00559450((int *)&(h3))))->v10();
        }
        return;
    }
    String448 t2;
    ::fnv_006536d0::BuildTriPathAndSet((::fnv_006536d0::StrMem *)(::fnv_00448080::String448 *)(&t2), pathX, -1);
    reinterpret_cast<::fnv_00447a40::FUN_00447a40_shell *>(this)->FUN_00447a40((char *)(void *)(((void *)(::FUN_00559450((int *)&(t2))))), x, (::QueuedFile *)(parent), 1);
}
}  // namespace fnv_00448080

namespace fnv_00448620 {
struct FUN_0045585e0_t;
struct FUN_004498e0_t;
struct FUN_00449960_t;

struct FUN_00443190_t
{
    ~FUN_00443190_t();
};
struct FUN_004431b0_t
{
    ~FUN_004431b0_t();
};
struct FUN_0045585e0_t
{
    int GetType();
};

struct FUN_0044c640_host
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
};

struct FUN_0042ce10_t
{
};

struct FUN_004498e0_t
{
    FUN_004498e0_t();
    ~FUN_004498e0_t();
    char pad[0x10c];
};

struct FUN_00449960_t
{
    FUN_00449960_t();
    ~FUN_00449960_t();
    char pad[0x110];
};


struct FUN_00448620_cls
{
    FUN_0044c640_host* p0;
    FUN_0044c640_host* p4;
    char pad[0x24];
    bool b2c;
    void FUN_00448620(bool);
};

// @fnv 0x00448620
void FUN_00448620_cls::FUN_00448620(bool b)
{
    if (!b && (*reinterpret_cast<::fnv_00448620::FUN_0042ce10_t * *>(&::g_BGSSaveLoadGame)) != 0 && reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00448620::FUN_0042ce10_t * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
    {
        b2c = true;
        return;
    }
    if (p0 != 0)
    {
        FUN_004498e0_t entryA;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(entryA))->FUN_006ebde0())
        {
            FUN_00443190_t* v12c = 0;
            int v128 = 0;
            if (reinterpret_cast<::Queue44c640 *>((p0))->TryGetNextEntry((::QueueIter44c640 *)(::fnv_00448620::FUN_004498e0_t *)(&entryA), (void **)(int *)(&v128), (int)(&v12c), 1) && v12c != 0 && !reinterpret_cast<::FUN_00443190_shell *>((v12c))->GetCombinedValue())
            {
                p0->v5(v128);
                delete v12c;
            }
        }
    }
    if (p4 != 0)
    {
        FUN_00449960_t entryB;
        while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(entryB))->FUN_006ebde0())
        {
            FUN_004431b0_t* pEntryB = 0;
            int iIndexB = 0;
            if (reinterpret_cast<::Queue44c640 *>((p4))->TryGetNextEntry((::QueueIter44c640 *)(::fnv_00448620::FUN_00449960_t *)(&entryB), (void **)(int *)(&iIndexB), (int)(&pEntryB), 1) && pEntryB != 0 && !::FUN_004431b0((int *)(pEntryB)))
            {
                bool bRemovable = true;
                if (((::fnv_00448620::FUN_0045585e0_t *)(reinterpret_cast<::TESRegionDataMap *>((pEntryB))->GetRegionMapName())) != 0 && ((::fnv_00448620::FUN_0045585e0_t *)(reinterpret_cast<::TESRegionDataMap *>((pEntryB))->GetRegionMapName()))->GetType() >= 0x5c &&
                    ((::fnv_00448620::FUN_0045585e0_t *)(reinterpret_cast<::TESRegionDataMap *>((pEntryB))->GetRegionMapName()))->GetType() < 0x66)
                    bRemovable = false;
                if (bRemovable)
                {
                    p4->v5(iIndexB);
                    delete pEntryB;
                }
            }
        }
    }
    b2c = false;
}
}  // namespace fnv_00448620

namespace fnv_004436c0 {
struct NiObjQ
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
    int FUN_0043c430();
};
struct SPBaseQ
{
    NiObjQ* m_p;
};
struct FUN_00633c90 : SPBaseQ
{
    FUN_00633c90(NiObjQ* p);
    ~FUN_00633c90();
};
struct FUN_00528cb0 : SPBaseQ
{
    FUN_00528cb0(NiObjQ* p);
    ~FUN_00528cb0();
};
struct FUN_0043bef0 : NiObjQ
{
    char pad[0x34];
    FUN_0043bef0(NiObjQ* p, void* q);
};
struct FUN_0043be60 : NiObjQ
{
    char pad[0x34];
    FUN_0043be60(void* p, void* q);
};
struct FUN_0043bd10 : NiObjQ
{
    char pad[0x34];
    FUN_0043bd10(const char* p, void* q);
};
struct FUN_006815c0
{
    int m0, m4;
    FUN_006815c0();
};
class FUN_004436c0_Class
{
  public:
    bool LoadTexture(const char* pcName, void* p2, void* p3);
};
// Looks up pcName, then either configures a found object or searches archives and constructs another object.
// @fnv 0x004436c0
bool FUN_004436c0_Class::LoadTexture(const char* pcName, void* p2, void* p3)
{
    FUN_00633c90 spA5(0);
    ::FindTextureByPath(pcName, (::NiTexture **)(::fnv_004436c0::FUN_00633c90 *)(&spA5));
    if (((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spA5)))))
    {
        bool bSkip = false;
        if (((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spA5))))->FUN_0043c430() == 3 && !reinterpret_cast<::FUN_0043c130_shell *>(this)->IsLoadTexturesDegraded())
            bSkip = true;
        if (!bSkip)
        {
            if (p3)
            {
                FUN_00528cb0 spB4(new FUN_0043bef0(((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spA5)))), p2));
                reinterpret_cast<::QueuedFile *>((((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spB4))))))->SetParent((::QueuedFile *)(p3));
                ((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spB4))))->v28();
                return true;
            }
            return false;
        }
    }
    char acPath7[0x104];
    ::CleanPath(pcName, acPath7, 0x104);
    FUN_006815c0 kA;
    FUN_006815c0 kB;
    ::HashPathComponents(acPath7, (::FileNameHash *)(::fnv_004436c0::FUN_006815c0 *)(&kA), (::FileNameHash *)(::fnv_004436c0::FUN_006815c0 *)(&kB));
    void* pRes_ = ((void *)(::fnv_00af6540::FindFileEntryInArchives(1, (*(::fnv_00af6540::FileNameHash *)(&kA)), (*(::fnv_00af6540::FileNameHash *)(&kB)), acPath7)));
    if (pRes_ && reinterpret_cast<::fnv_00443540::FUN_00443540_shell *>(this)->FUN_00443540((::fnv_00443540::BSFileEntry *)(pRes_), (int)(p2), (::QueuedFile *)(p3)))
        return true;
    FUN_00528cb0 spC4(0);
    if (pRes_)
    {
        reinterpret_cast<::FUN_006f74f0_cls *>(&(spC4))->FUN_006f74f0((::ObjA *)(::fnv_004436c0::NiObjQ *)(new FUN_0043be60(pRes_, p2)));
        reinterpret_cast<::FUN_00c3cee0_shell *>((((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spC4))))))->FUN_00c3cee0(acPath7);
    }
    else
    {
        reinterpret_cast<::FUN_006f74f0_cls *>(&(spC4))->FUN_006f74f0((::ObjA *)(::fnv_004436c0::NiObjQ *)(new FUN_0043bd10(pcName, p2)));
    }
    reinterpret_cast<::QueuedFile *>((((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spC4))))))->SetParent((::QueuedFile *)(p3));
    ((::fnv_004436c0::NiObjQ *)(::FUN_00559450((int *)&(spC4))))->v20();
    return true;
}
}  // namespace fnv_004436c0

namespace fnv_00447980 {
struct QIdle
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Run();
};
class QIdlePtr
{
  public:
    QIdlePtr(QIdle* p);
    ~QIdlePtr();
    operator QIdle*() const;
    QIdle* m_p;
};
class FUN_0043d540 : public QIdle
{
  public:
    FUN_0043d540(int a, int b, int c);
    void* operator new(unsigned int);
    unsigned int unk[15];
};
class OwnerX
{
  public:
    void RunIdleTask(int a, int c);
};
// Creates a FUN_0043d540 idle task with the given parameters and immediately runs it via QIdle::Run.
// @fnv 0x00447980
void OwnerX::RunIdleTask(int aiParam1, int aiParam3)
{
    QIdlePtr spIdle(new FUN_0043d540(aiParam1, 4, aiParam3));
    ((QIdle*)spIdle)->Run();
}
}  // namespace fnv_00447980

namespace fnv_004492f0 {
enum MEM_CONTEXT
{
    MC_6 = 6
};
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
    int iData;
};
template <class T> unsigned int BSStringLength(const T* p);
extern "C" int __cdecl tolower(int);
class StrMapX
{
  public:
    char* GetLowercaseKey(const char* pKey);
};
// Allocates and returns a lowercase copy of pKey while an AutoMemContext is active.
// @fnv 0x004492f0
char* StrMapX::GetLowercaseKey(const char* pKey)
{
    AutoMemContext kContext(MC_6, true, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h",
                            0x1fd);
    char* pCopy = new char[::FUN_0044a670(pKey) + 1];
    char* pDst = pCopy;
    while (*pKey)
    {
        *pDst++ = tolower(*pKey++);
    }
    *pDst = 0;
    return pCopy;
}
}  // namespace fnv_004492f0

struct NodeX;
struct PtrX
{
};
struct NodeX
{
    NodeX* m_pkNext;
    PtrX m_kData;
};
struct ListX
{
    virtual void v0(), v4(), v8();
    virtual void Vc();
    NodeX* m_pkHead;
    NodeX* m_pkTail;
};
struct QueueX
{
    ListX* m_pkList;
    NodeX** m_ppkHazard0;
    NodeX** m_ppkHazard1;
    bool Pop(PtrX& kOut);
};
// Locks the object, calls Pop on the result of FUN_00449f80(arData), unlocks, and returns that bool.
// @fnv 0x00449280
bool Q449::FUN_00449280(void* arData)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool bResult = reinterpret_cast<::QueueX *>((FUN_00449f80(arData)))->Pop(*(::PtrX *)nullptr);
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return bResult;
}
// Atomically removes the head node from the lock-free list, copies its data into kOut, and returns false when the queue is empty.
// @fnv 0x0044cec0
bool QueueX::Pop(PtrX& kOut)
{
    NodeX* volatile pkHead = 0;
    while (true)
    {
        pkHead = m_pkList->m_pkHead;
        *m_ppkHazard0 = pkHead;
        if (pkHead != m_pkList->m_pkHead)
            continue;
        NodeX* pkTail = m_pkList->m_pkTail;
        NodeX* volatile pkNext = pkHead->m_pkNext;
        *m_ppkHazard1 = pkNext;
        if (pkHead != m_pkList->m_pkHead)
            continue;
        if (!pkNext)
        {
            *m_ppkHazard0 = 0;
            reinterpret_cast<::FUN_006f74f0_cls *>(&(kOut))->FUN_006f74f0((::ObjA *)(void *)(0));
            return false;
        }
        if (pkHead == pkTail)
        {
            ::FUN_004491c0((volatile long *)(::NodeX **)(&m_pkList->m_pkTail), (long)(pkNext), (long)(pkTail));
            continue;
        }
        reinterpret_cast<::NP_0092c820 *>(&(kOut))->FUN_0092c820((*(const ::NP_0092c820 *)(&pkNext->m_kData)));
        if (::FUN_004491c0((volatile long *)(::NodeX **)(&m_pkList->m_pkHead), (long)(pkNext), (long)(pkHead)))
        {
            m_pkList->Vc();
            reinterpret_cast<::FUN_006f74f0_cls *>(&(pkNext->m_kData))->FUN_006f74f0((::ObjA *)(void *)(0));
            break;
        }
    }
    *m_ppkHazard0 = 0;
    *m_ppkHazard1 = 0;
    reinterpret_cast<::S *>(this)->FUN_0044e4f0(pkHead);
    return true;
}

struct Item44F950;
struct Node44F950
{
    Item44F950* m_item;
    Node44F950* m_pkNext;
};
class Owner44F950
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual bool CheckItem(Item44F950* pkItem);
    bool BaseCheck();
    Node44F950* GetNext(Node44F950* pkNode);
    bool CheckAllItems();
};

// Returns true if BaseCheck passes and every item in the linked list of nodes passes CheckItem.
// @fnv 0x0044f950
bool Owner44F950::CheckAllItems()
{
    bool bResult = BaseCheck();
    if (bResult)
    {
        Node44F950* pkNode = ((::Node44F950 *)(::FUN_0044faa0((char *)this)));
        while (pkNode)
        {
            bResult &= CheckItem(((::Item44F950 *)(new ((void *)(pkNode)) ::Vec3())));
            pkNode = GetNext(pkNode);
        }
    }
    return bResult;
}

class QIdle;

class QIdleRef
{
  public:
    QIdle* m_pObject;
    QIdleRef(QIdle* object);
    ~QIdleRef();
};

class QIdleBase
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    char pad[0x34];
    QIdleBase(void* first, int second);
    ~QIdleBase();
};

struct FUN_0043e580 : QIdleBase
{
    virtual void v00();
    virtual void v04();
    void* m_38;
    QIdleRef m_3c;

    FUN_0043e580(void* first, int second, QIdle* third, void* fourth);
};

// Initializes QIdleBase from first and second, then m_38 from fourth and m_3c from third.
// @fnv 0x0043e580
FUN_0043e580::FUN_0043e580(void* apBase, int second, QIdle* apIdle, void* fourth)
    : QIdleBase(apBase, second), m_38(fourth), m_3c(apIdle)
{}

class BaseTaskMgr
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
    int unk20;
    int unk24;
    int unk28;
    ~BaseTaskMgr();
};

struct ElemA
{
    int unk00;
    ~ElemA();
};

struct ElemB
{
    int unk00;
    ~ElemB();
};

class LoaderMgr : public BaseTaskMgr
{
  public:
    ElemA unk2C[20];
    ElemB unk7C[20];
    ElemB unkCC[20];
    ~LoaderMgr();
};

// @fnv 0x0043f080
LoaderMgr::~LoaderMgr()
{}

namespace fnv_00440640 {
struct FUN_00449a20_cls
{
    void FUN_004490e0();
    void FUN_00440640();
};

void FUN_00449a20_cls::FUN_004490e0()
{}

// @fnv 0x00440640
void FUN_00449a20_cls::FUN_00440640()
{
    reinterpret_cast<::fnv_004490e0::FUN_004490e0_Class *>(this)->FUN_004490e0();
}
}  // namespace fnv_00440640

#include <ctype.h>
struct LockFreeCaseInsensitiveStringMap_t
{
    void FUN_004493d0(const char* apKey, void* apValue);
};
// Lowercases apKey into acLowerKey and calls FUN_00449530 with the lowercased key and apValue.
// @fnv 0x004493d0
void LockFreeCaseInsensitiveStringMap_t::FUN_004493d0(const char* apKey, void* apValue)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    reinterpret_cast<::fnv_00449530::FUN_00449530_S *>(this)->FUN_00449530((int)(acLowerKey), (int)(apValue));
}

namespace fnv_00449460 {
struct LockFreeCaseInsensitiveStringMap_t
{
    void FUN_00449460(const char* apKey, void* apValue, bool abFlag);
};
// Lowercases apKey into a 1000-byte buffer and forwards it with apValue and abFlag to FUN_00449580.
// @fnv 0x00449460
void LockFreeCaseInsensitiveStringMap_t::FUN_00449460(const char* apKey, void* apValue, bool abFlag)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    reinterpret_cast<::fnv_00449580::Q449b *>(this)->FUN_00449580((void *)(acLowerKey), apValue, abFlag);
}
}  // namespace fnv_00449460

namespace fnv_00449750 {
struct LockFreeCaseInsensitiveStringMap_t
{
    unsigned int GetBucketIndex(const char* apKey);
};
// Computes a case-insensitive hash of apKey and returns it modulo the table size from FUN_0044ddc0.
// @fnv 0x00449750
unsigned int LockFreeCaseInsensitiveStringMap_t::GetBucketIndex(const char* apKey)
{
    unsigned int uiHash = 0;
    while (*apKey)
    {
        uiHash = (uiHash << 5) + uiHash + tolower(*apKey++);
    }
    return uiHash % ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
}
}  // namespace fnv_00449750

namespace fnv_004497f0 {
struct LockFreeCaseInsensitiveStringMap_t
{
    void FUN_004497f0(const char* apKey);
};
// Lowercases apKey into acLowerKey and calls FUN_004495d0 with the lowercased key.
// @fnv 0x004497f0
void LockFreeCaseInsensitiveStringMap_t::FUN_004497f0(const char* apKey)
{
    char acLowerKey[1000];
    char* pDest = acLowerKey;
    while (*apKey)
    {
        *pDest++ = tolower(*apKey++);
    }
    *pDest = 0;
    reinterpret_cast<::fnv_004495d0::Q449 *>(this)->FUN_004495d0((void *)(acLowerKey));
}
}  // namespace fnv_004497f0

namespace reference_queue_types {
namespace FUN_00528cb0 {
struct FUN_0044cbf0
{
    void* p;
    FUN_0044cbf0(void*);
    ~FUN_0044cbf0();
};
}
}

struct FUN_00445750_map
{
    virtual void v0();
    virtual void v1();
    virtual bool Lookup(void* r, reference_queue_types::FUN_00528cb0::FUN_0044cbf0* out);
};

struct FUN_00445750_arg
{
    void* r;
};

// @fnv 0x00445750
// @fnv 0x00445750
bool FUN_00445750(char* this_ptr, FUN_00445750_arg a)
{
    reference_queue_types::FUN_00528cb0::FUN_0044cbf0 g(0);
    return (*(FUN_00445750_map**)(this_ptr + 8))->Lookup(a.r, &g);
}

// HighProcess_MLd model-file loader
extern "C" int DAT_011f94c0;
extern "C" const char DAT_01016840[];
extern "C" const char DAT_010168c4[];
extern "C" const char DAT_010168ec[];
extern "C" const char DAT_010168f4[];

class AutoMemHelper_MLd
{
  public:
    void* m_buffer;
    AutoMemHelper_MLd(int, bool, const char*, int);
    ~AutoMemHelper_MLd();
};

class NiPointerShell_MLd
{
  public:
};

class NiStream_MLd
{
  public:
};

struct Blob16
{
    int a, b, c, d;
};
struct Blob64
{
    Blob16 a, b, c, d;
};
struct Blob256
{
    Blob64 a, b, c, d;
};
struct Blob1024
{
    Blob256 a, b, c, d;
};
struct Blob1488
{
    Blob1024 a;
    Blob256 b;
    Blob64 c, d, e;
    Blob16 f;
};

class BSStream_MLd
{
  public:
    BSStream_MLd();
    virtual ~BSStream_MLd();
    char pad[0x5c8];
};

class HighProcess_MLd
{
  public:
};

class SetterHelper_MLd
{
  public:
};

class ModelLoaderX
{
  public:
};

class FUN_0043ccf0_shell
{
  public:
    void FUN_0043ccf0();
    char m_uiStandInValue[0x18];
    int m_field18;
    char m_iValueAfterStandIn[0x14];
    int m_model30;
};

// Loads the named model, checks the pointer at offset 0x30, then tries stream loading and may assign a new Model.
// @fnv 0x0043ccf0
void FUN_0043ccf0_shell::FUN_0043ccf0()
{
    AutoMemHelper_MLd mem5(m_field18, 1, DAT_01016840, 0x3b8);

    if (::FUN_0044a670((const char*)((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess_MLd*)this)))->FUN_0045cd60()))) > 0)
    {
        reinterpret_cast<::FUN_004472a0_shell *>(((*reinterpret_cast<::ModelLoaderX * *>(&::g_modelLoader))))->FUN_004472a0((char *)((const char*)((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess_MLd*)this)))->FUN_0045cd60()))),
                                  (void *)&(*(NiPointer<Model>*)&m_model30));
        if (((unsigned int)(::FUN_00559450((int *)(((NiPointerShell_MLd*)&this->m_model30))))) != 0)
        {
            ((FUN_0043cf60_shell*)this)->FUN_0043cf60(true);
            return;
        }

        void* pFile5 = ((FUN_00c3cff0_shell*)this)->FUN_00c3cff0(0, true);
        BSStream_MLd stream;

        DAT_011f94c0 = ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess_MLd*)this)))->FUN_0045cd60()));

        if ((pFile5 != 0 && reinterpret_cast<::FUN_00c3a8a0_cls *>((((NiStream_MLd*)&stream)))->FUN_00c3a8a0((unsigned int)((const char*)((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess_MLd*)this)))->FUN_0045cd60()))), (unsigned int)(pFile5))) ||
            ((FUN_0043cf90_shell*)this)->FUN_0043cf90())
        {
            reinterpret_cast<::NP_0044aed0 *>((((SetterHelper_MLd*)&this->m_model30)))->FUN_0044aed0((::WaitableObject *)(void *)(new Model((const char*)((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess_MLd*)this)))->FUN_0045cd60())), (BSStream*)&stream,
                                         ((FUN_0043cf40_shell*)this)->FUN_0043cf40(),
                                         ((FUN_0043cfb0_shell*)this)->FUN_0043cfb0())));
        }
        else
        {
            ::FUN_005b5e40();
        }

        DAT_011f94c0 = 0;
    }
}

__if_not_exists(WaitForSingleObject)
{
}

__if_not_exists(FinishScriptRunLock)
{
    void FinishScriptRunLock(void*);
}

class SemaphoreFields
{
  public:
    void* unk00;
    void* m_pSemaphore;
};

struct SemaphoreWaitReceiver
{
    void FUN_004424e0();
};

// Blocks indefinitely on m_pSemaphore via WaitForSingleObject, then releases the script run lock with FinishScriptRunLock.
// @fnv 0x004424e0
void SemaphoreWaitReceiver::FUN_004424e0()
{
    WaitForSingleObject(((SemaphoreFields*)this)->m_pSemaphore, 0xffffffffUL);
    ::WaitForSingleObjectEx((long *)(void *)(this));
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};

class FUN_00c3b970_cls
{
  public:
    NiRefObject* m_pReferencedObject;

    FUN_00c3b970_cls& FUN_00c3b970(NiRefObject* obj);
};

// Swaps the referenced object, releasing the old reference and acquiring a new one when the pointer changes.
// @fnv 0x00c3b970
FUN_00c3b970_cls& FUN_00c3b970_cls::FUN_00c3b970(NiRefObject* apRefObject)
{
    NiRefObject* pOldRefObject;
    NiRefObject* pNewRefObject;
    if (m_pReferencedObject != apRefObject)
    {
        if (m_pReferencedObject != 0)
        {
            pOldRefObject = m_pReferencedObject;
            if (InterlockedDecrement((volatile long*)&pOldRefObject->m_uiRefCount) == 0)
            {
                pOldRefObject->DeleteThis();
            }
        }
        m_pReferencedObject = apRefObject;
        if (m_pReferencedObject != 0)
        {
            pNewRefObject = m_pReferencedObject;
            InterlockedIncrement((long*)&pNewRefObject->m_uiRefCount);
        }
    }
    return *this;
}

struct NiPoint3
{

  public:
};


struct ParentByteQuery : NiAVObject
{

    int FUN_0043c430();
};
// Loads the file's node; if it is a usable model it queues a TextureTask for the node, otherwise falls back to FUN_00443540 or queues a TextureTask for the file.
// @fnv 0x00443af0
bool TextureLoader::QueueTextureLoad(BSFileEntry* file, int priority, QueuedFile* parent)
{
    NodePointer node(0);
    ::GetNodePointer((::NiNode *)(file), (::NiPointer< ::NiNode> &)(node));
    if ((NiNode*)node)
    {
        bool skip = false;
        if (reinterpret_cast<::ParentByteQuery *>((((TextureNodeInfo*)(NiNode*)node)))->FUN_0043c430() == 3 && !reinterpret_cast<::FUN_0043c130_shell *>(this)->IsLoadTexturesDegraded())
            skip = true;
        if (!skip)
        {
            if (parent)
            {
                TextureTaskPointer request(new TextureTask((NiNode*)node, priority));
                reinterpret_cast<::QueuedFile *>(((request).operator->()))->SetParent(parent);
                request->vfn_28();
                return true;
            }
            return false;
        }
    }
    if (reinterpret_cast<::fnv_00443540::FUN_00443540_shell *>(this)->FUN_00443540((::fnv_00443540::BSFileEntry *)(file), priority, parent))
        return true;
    TextureTaskPointer request(new TextureTask(file, priority));
    reinterpret_cast<::QueuedFile *>(((request).operator->()))->SetParent(parent);
    request->vfn_20();
    return true;
}

// Returns FUN_0043c470() on the parent returned by FUN_0059bb30, or 0 if no parent exists.
// @fnv 0x0043c430
int ParentByteQuery::FUN_0043c430()

{

    return ((::NiNode *)(reinterpret_cast<::ActorMover *>((this))->GetCurrentMoveModeType())) ? reinterpret_cast<::NiAVObject *>(&(((::NiNode *)(reinterpret_cast<::ActorMover *>((this))->GetCurrentMoveModeType()))->FUN_0043c490()))->FUN_0043c470() : 0;
}

struct CharacterClone : public QueuedCharacter
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int m_uiMemoryContext;
    int unk1c, unk20, unk24;
    void* cloneTarget;
    bool FUN_004416c0();
};

namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}
struct CloneObjectAccessor
{
};
void AttachHeadAndFaceParts(void*);
struct Helper_00440a90
{
};
void __cdecl FUN_00441780(void*, void*);
void __cdecl FUN_004417c0();

// Creates an AutoMemContext, checks a helper and clone accessor, then calls FUN_00441780, FUN_004418b0 and FUN_004417c0 when both checks pass.
// @fnv 0x004416c0
bool CharacterClone::FUN_004416c0()
{
    lc1::AutoMemContext tempMemContext(
        m_uiMemoryContext, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ModelLoader.cpp", 0x8e4);
    bool bresult = reinterpret_cast<::fnv_00440a90::FUN_00440a90_shell *>((((Helper_00440a90*)this)))->FUN_00440a90();
    if (bresult && ((void *)(reinterpret_cast<::FUN_005d8710_shell *>((((CloneObjectAccessor*)this)))->FUN_005d8710())))
    {
        FUN_00441780(cloneTarget, ((void *)(reinterpret_cast<::FUN_005d8710_shell *>((((CloneObjectAccessor*)this)))->FUN_005d8710())));
        reinterpret_cast<::fnv_004418b0::FUN_004418b0_shell *>((this))->AttachHeadAndFaceParts();
        FUN_004417c0();
    }
    return bresult;
}

struct LockedResult
{
};

struct ReceiverLock
{
    unsigned int ownerThread;
    unsigned int lockCount;
};

struct LockedReceiver
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    ReceiverLock lock;
    LockedResult* FUN_00449f80(void*);
};

struct ReceiverArgument
{
    void* value;
};

// Locks the receiver, calls FUN_0044cd40 on the result of FUN_00449f80 with argument.value, then unlocks the receiver.
// @fnv 0x00449240
void FUN_00449240(LockedReceiver* receiver, ReceiverArgument argument)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(receiver->lock))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::LockFreeQueue *>((receiver->FUN_00449f80(argument.value)))->Enqueue(*(const ::QHeadPtr *)nullptr);
    reinterpret_cast<::RecursiveSpinLock *>(&(receiver->lock))->FUN_0040fba0();
}

void _Deallocate(void*);

struct ModelLoaderDeleteEntry449 : public ModelLoader
{
    void* FUN_00449b40(unsigned int flags);
};

// Calls FUN_00443220, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00449b40
void* ModelLoaderDeleteEntry449::FUN_00449b40(unsigned int flags)
{
    this->FUN_00443220();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
    unsigned int state;
};
struct CleanupReceiver
{
};
struct FUN_0044a040 : public FUN_0065cfb0
{
    ~FUN_0044a040();
};
// Calls FUN_0065f240 on the current object.
// @fnv 0x0044a040
FUN_0044a040::~FUN_0044a040()
{
    reinterpret_cast<::FUN_0065f240 *>((((CleanupReceiver*)this)))->Clear();
}

#include "generated/data/fallout_shared/modelloader.inc"
