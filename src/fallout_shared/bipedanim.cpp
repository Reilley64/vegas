// fallout_shared/bipedanim.cpp: BipedAnim, BipedAnimWeap, FaceLoader, BipedAnimHelper (75 functions)

#include <new>
#include <cstdint>
#include "runtime/crt.h"
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSXFlags.h"
#include "fnv/decl/BipedAB.h"
#include "fnv/decl/BipedWeaponRemoval.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004450c0_holder.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_00457ba0_class.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004700d0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004afb80_shell.h"
#include "fnv/decl/FUN_004afc20.h"
#include "fnv/decl/FUN_004b0260_shell.h"
#include "fnv/decl/FUN_004bd820_stand.h"
#include "fnv/decl/FUN_004f8a90_Class.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_00522df0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00572160_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008a16d0_shell.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_008b70d0_shell.h"
#include "fnv/decl/FUN_008bbc10_shell.h"
#include "fnv/decl/FUN_00950b30_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5be90_shell.h"
#include "fnv/decl/FUN_00a5bfa0_shell.h"
#include "fnv/decl/FUN_00b4dec0_shell.h"
#include "fnv/decl/Fake_FUN_004a2020.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/ObjPtrArray.h"
#include "fnv/decl/Pn4afe.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004994f0__FUN_004994f0_shell.h"
#include "fnv/decl/fnv_004afba0__FUN_004afba0_class.h"
#include "fnv/decl/fnv_00567050__FUN_00567050_shell.h"
#include "fnv/decl/fnv_00571760__Actor.h"
#include "fnv/decl/fnv_006148f0__FUN_006148f0_shell.h"
#include "fnv/decl/fnv_006149b0__RaceTexture.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087acb0__FUN_0087acb0_host.h"
#include "fnv/decl/fnv_008b0b00__FUN_008b0b00_cls.h"
#include "fnv/decl/fnv_008bb650__PlayerView.h"
#include "fnv/decl/reconstruct_c5a9d0__Array.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ab000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00572000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e4000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "bipedanim_decls.h"

// The supplied identity for this span differs from its PC receiver semantics.
// Removes the biped weapon and related weapon/quiver nodes from the reference's 3D, updating the actor's process and weapon model state.
// @fnv 0x00571b50
void BipedAnim::AttachFaceGenNode()
{
    if (!((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((TESObjectREFR*)this)))->FUN_0043fcd0())))
        return;
    BipedWeaponOwner pOwnerContext;
    {
        BipedEquippedWeapon weaponInfo;
        weaponInfo.weapon = 0;
        weaponInfo.changes = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((((TESObjectREFR*)this)))->FUN_005d43c0()))->GetContainerChangeData();
        if (weaponInfo.changes)
        {
            InventoryStackRecord* item = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((weaponInfo.changes))->FUN_004c8c10((*(int *)&(const ::BIPED_OBJECT &)(BIPED_WEAPON)), false)));
            if (item)
            {
                weaponInfo.weapon = (TESObjectWEAP*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()));
                delete item;
            }
        }

        if (((TESObjectREFR*)this) == ::_g_thePlayer)
        {
            if (reinterpret_cast<::FUN_008bbc10_shell *>((::_g_thePlayer))->FUN_008bbc10() && ::FUN_005721e0((const bool *)(::_g_thePlayer)))
                reinterpret_cast<::fnv_008bb650::PlayerView *>((::_g_thePlayer))->SetActiveState(false, false, false);
            pOwnerContext.biped = ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(true)));
        }
        else
        {
            pOwnerContext.biped = ((TESObjectREFR*)this)->GetBipedAnim();
        }
        pOwnerContext.actor = 0;
        if (((TESObjectREFR*)this)->IsActor())
            pOwnerContext.actor = (Actor*)((TESObjectREFR*)this);
        if (((TESObjectREFR*)this) == ::_g_thePlayer)
        {
            pOwnerContext.biped = ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(true)));
            reinterpret_cast<::VATS *>((((InventoryStackRecord*)&(*reinterpret_cast<::VATS *>(&::g_011f2250)))))->FUN_009c8950(false, true);
            if (pOwnerContext.biped)
                reinterpret_cast<::BipedWeaponRemoval *>((pOwnerContext.biped))->FUN_004ab5b0();
            pOwnerContext.biped = ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(false)));
            if (reinterpret_cast<::FUN_008bbc10_shell *>((::_g_thePlayer))->FUN_008bbc10())
                ::Interface::SetHUDVisible(false);
            ::FUN_00709ca0();
        }
        pOwnerContext.process = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwnerContext.actor))->GetBaseTexture()));
        if (pOwnerContext.biped)
        {
            ::FUN_00572220(true);
            reinterpret_cast<::BipedWeaponRemoval *>((pOwnerContext.biped))->FUN_004ab5b0();
            ::FUN_00572220(false);
        }
        else
        {
            bool m_bHeaderParsed = false;
            {
                NiNode* pWeaponNode;
                {
                    NiAVObject* pBackpack =
                        ::FUN_004aae30(((TESObjectREFR*)this)->GetNiNode_v(), (::NiFixedString *)("Backpack"));
                    if (pBackpack)
                        ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((pBackpack))->FUN_009611e0()))->RemoveObject(pBackpack);
                    pWeaponNode = 0;
                    {
                        NiNode* pNode = 0;
                        if (pOwnerContext.process)
                        {
                            pWeaponNode = pOwnerContext.process->GetWeaponNode(false);
                            m_bHeaderParsed = pWeaponNode && reinterpret_cast<::FUN_00453470_shell *>((pWeaponNode))->FUN_00453470();
                            if (!m_bHeaderParsed)
                            {
                                pWeaponNode = pOwnerContext.process->GetQuiverNode(false);
                                bool bow = false;
                                if (pWeaponNode)
                                {
                                    for (unsigned int i = 0; i < pWeaponNode->FUN_0043b480(); ++i)
                                    {
                                        NiAVObject* child = pWeaponNode->GetAt(i);
                                        if (child && BIPED_OBJECT_TEXT(child) &&
                                            !FUN_00408b20(BIPED_OBJECT_TEXT(child), "Bow"))
                                        {
                                            bow = true;
                                            break;
                                        }
                                    }
                                }
                                if (bow)
                                    m_bHeaderParsed = pWeaponNode && reinterpret_cast<::FUN_00453470_shell *>((pWeaponNode))->FUN_00453470();
                            }
                            if (!m_bHeaderParsed)
                            {
                                BipedWeaponSearch nodes;
                                {
                                    nodes.root = ((TESObjectREFR*)this)->GetNiNode_v();
                                    nodes.search = nodes.root;
                                    nodes.found = 0;
                                    if (nodes.root)
                                    {
                                        NiAVObject* object = ::FUN_004aae30(nodes.search, (::NiFixedString *)("Weapon"));
                                        nodes.found = (NiNode*)object;
                                        if (nodes.found)
                                        {
                                            m_bHeaderParsed = true;
                                            pWeaponNode = nodes.found;
                                        }
                                    }
                                }
                            }
                        }
                        if (weaponInfo.weapon)
                        {
                            TESModel* model = weaponInfo.weapon ? (TESModel*)((char*)weaponInfo.weapon + 0x3c) : 0;
                            if (model && m_bHeaderParsed)
                                reinterpret_cast<::FUN_0045a5e0_shell *>((g_modelLoader))->FUN_0045a5e0((char *)(model->GetModelFilePath()));
                        }
                    }
                }
            }
        }
        if (pOwnerContext.process)
        {
            NiNode* pWeaponNode = pOwnerContext.process->GetWeaponNode(false);
            if (pWeaponNode)
            {
                ::FUN_00b5b1c0((::ShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)), (int)(pWeaponNode), {});
                reinterpret_cast<::FUN_00572160_shell *>((pWeaponNode))->FUN_00572160();
            }
            if (((TESObjectREFR*)this)->IsCreature())
            {
                BipedWeaponSearch nodes;
                {
                    nodes.root = ((TESObjectREFR*)this)->GetNiNode_v();
                    nodes.search = nodes.root;
                    nodes.found = 0;
                    if (nodes.root)
                    {
                        NiAVObject* object = ::FUN_004aae30(nodes.search, (::NiFixedString *)("Weapon"));
                        nodes.found = (NiNode*)object;
                        if (nodes.found)
                        {
                            ::FUN_00b5b1c0((::ShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)), (int)(nodes.found), {});
                            reinterpret_cast<::FUN_00572160_shell *>((nodes.found))->FUN_00572160();
                        }
                    }
                }
            }
            pWeaponNode = pOwnerContext.process->GetQuiverNode(false);
            if (pWeaponNode)
            {
                bool bow = false;
                for (unsigned int i = 0; i < pWeaponNode->FUN_0043b480(); ++i)
                {
                    NiAVObject* child = pWeaponNode->GetAt(i);
                    if (child && BIPED_OBJECT_TEXT(child) && !FUN_00408b20(BIPED_OBJECT_TEXT(child), "Bow"))
                    {
                        bow = true;
                        break;
                    }
                }
                if (bow)
                {
                    ::FUN_00b5b1c0((::ShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)), (int)(pWeaponNode), {});
                    reinterpret_cast<::FUN_00572160_shell *>((pWeaponNode))->FUN_00572160();
                }
            }
        }
        if (pOwnerContext.actor)
        {
            BaseProcess* active = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwnerContext.actor))->GetBaseTexture()));
            if (!pOwnerContext.biped && active && !reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004226e0() && !reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition())
                reinterpret_cast<::fnv_008b0b00::FUN_008b0b00_cls *>((pOwnerContext.actor))->FUN_008b0b00(false);
            reinterpret_cast<::FUN_008b0bd0_shell *>((pOwnerContext.actor))->FUN_008b0bd0(((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((TESObjectREFR*)this)))->FUN_0043fcd0())));
            if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwnerContext.actor))->GetBaseTexture())))
            {
                BGSBipedModelList* models = BGSBipedModelList::GetBipedModelList(weaponInfo.weapon);
                if (models && ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)models)))->FUN_00726070())))
                    ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwnerContext.actor))->GetBaseTexture()))->SetWeaponModelChanged(true);
            }
        }
    }
}

// @fnv 0x004ad290
NiAVObject* BipedAnim::PrepareBipedModel(NiNode* model, BIPED_OBJECT slot, bool first, bool hair, BSFaceGenModel* face)
{
    NiAVObject* result = model;
    NiNode* multi = (NiNode*)((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f9140)), (::NiObject *)(::NiProperty *)((NiProperty*)model))));
    NiPointer<NiNode> temp(0);
    if (!result)
        return result;
    object[slot].bHasAnimation = ::FUN_004910d0(model);
    if (!root)
        return result;
    if (object[slot].bHasAnimation)
    {
        NiNode* pSource = model;
        NiPointer<NiNode> spAttach(0);
        NiAVObject* pFound = ::FUN_004aae30(root, (::NiFixedString *)("SkinAttachment"));
        if (pFound)
            spAttach = (NiNode*)pFound;
        else
            spAttach = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((root))->FUN_009611e0()));
        NiAVObject* pSkinned = 0;
        if (multi)
            for (unsigned int j = 0; j < multi->FUN_0043b480(); ++j)
            {
                NiNode* child = (NiNode*)multi->GetAt(j);
                pSkinned = AttachBipedModel(child, 0, slot, first, hair, face);
            }
        else
            pSkinned = AttachBipedModel(pSource, spAttach, slot, first, hair, face);
        result = pSkinned;
        if (result != model)
        {
            NiPointer<NiNode> release(model);
        }
    }
    else
        result = 0;
    return result;
}

// @fnv 0x004ab250
void BipedAnim::UpdateRaceSex(TESRace* race, SEX sex)
{
    if (!race)
        return;
    bool empty = true;
    int i;
    for (i = 0; i < 20; ++i)
        if (m_kPreviousObjects[i].pParent)
            empty = false;
    if (m_pActor && m_pActor->GetNiNode_v())
    {
        for (i = 0; i < 20; ++i)
        {
            if (empty)
                m_kPreviousObjects[i] = object[i];
            memset(&object[i], 0, 16);
        }
    }
    else
    {
        if (empty)
            memset(m_kPreviousObjects, 0, 320);
        memset(object, 0, 320);
    }
    for (i = 0; i < 3; ++i)
        if (DAT_01188be8[DAT_01188b88[i]] == -1 || (bone[DAT_01188be8[DAT_01188b88[i]]].cFlags & 1))
            SetBipedObject(race, race->GetBipedObjectModel(sex, (BIPED_OBJECT)DAT_01188b88[i]),
                           (BIPED_OBJECT)DAT_01188b88[i]);
}

// Determines the biped skin slot from the object's skin name prefix, warning on unrecognized names, or returns -1 if no shader property applies.
// @fnv 0x004af360
BIPED_OBJECT BipedAnim::GetBipedObjectFromShaderProperty(NiAVObject* object, BSShaderPPLightingProperty* property)
{
    if (!property)
        property = FindLightingShaderProperty(object);
    if (property && reinterpret_cast<::Fake_FUN_004a2020 *>((property))->GetFlag(10))
    {
        BipedSkinNameMatch skinMatch;
        skinMatch.name = (const char*)((BSFadeNode*)((TESTopicInfoData*)object)->GetLinkToList())->FUN_0043b1b0();
        skinMatch.slot = (BIPED_OBJECT)2;
        int i = 0;
        for (i = 0; i < 5; ++i)
            if (skinMatch.name && !fnv::crt::strnicmp(skinMatch.name, DAT_01188c38[i], ::FUN_0044a670(DAT_01188c38[i])))
                break;
        switch (i)
        {
        case 0:
        case 1:
        case 4:
            skinMatch.slot = (BIPED_OBJECT)2;
            break;
        case 2:
            skinMatch.slot = (BIPED_OBJECT)3;
            break;
        case 3:
            skinMatch.slot = (BIPED_OBJECT)4;
            break;
        default:
            ::FUN_005b5e40();
        }
        return skinMatch.slot;
    }
    return (BIPED_OBJECT)-1;
}

// Builds a Data\Meshes path from the model's path with the extension replaced by "1st.nif" and returns whether that file exists.
// @fnv 0x004af950
bool BipedAnim::IsModelPathMatch(TESModel* model, char* output)
{
    TaskQueueInterface::CopyStringToBuffer(output, 260, model->GetModelFilePath());
    char* extension = FUN_0040ab30(output, '.');
    if (extension)
    {
        *extension = 0;
        strcat_s(extension, 260 - (extension - output), "1st.nif");
        char path[260];
        ::FUN_00406d00(path, 260, "Data\\%s\\%s", kMeshesFolder, output);
        if (FileFinder::Exist(path, 0, 6, 1))
            return true;
    }
    return false;
}

// Returns the geometry's shader property if it is a BSShaderPPLightingProperty with a value between 8 and 12, otherwise null.
// @fnv 0x004af290
BSShaderPPLightingProperty* BipedAnim::FindLightingShaderProperty(NiAVObject* object)
{
    if (!object || !object->IsGeometry())
        return 0;
    NiTriBasedGeom* m_pShaderGeometry = (NiTriBasedGeom*)object;
    BipedRenderProperties renderProps;
    renderProps.alpha = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((m_pShaderGeometry))->FUN_00a59d30(FUN_004af350())));
    renderProps.material = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((m_pShaderGeometry))->FUN_00a59d30(FUN_004af340())));
    renderProps.shader = (BSShaderPPLightingProperty*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((m_pShaderGeometry))->FUN_00a59d30(3)));
    BSShaderPPLightingProperty* pLightingProp =
        (!renderProps.shader ? false
                             : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)renderProps.shader)))->GetMinLevel())) >= 8 &&
                                ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)renderProps.shader)))->GetMinLevel())) <= 12))
            ? renderProps.shader
            : 0;
    return pLightingProp;
}

// Returns true if the biped object's model exists and its FUN_004ae8f0 check succeeds.
// @fnv 0x004ae8a0
bool BipedAnim::IsSlotHidden(BIPED_OBJECT slot)
{
    TESModel* model = object[slot].m_pModel;
    return model && ((bool)(::FUN_004ae8f0((unsigned char *)(model))));
}

// @fnv 0x004af240
void BipedAnim::ApplyReferenceExtraData(NiNode* model, NiNode* clone, BIPED_OBJECT slot, TESObjectREFR* requester)
{
    NiExtraData* extra = model->GetExtraData(FUN_00448a80());
    if (extra)
    {
        NiExtraData* addon = extra;
        if (reinterpret_cast<::BSXFlags *>((addon))->GetAddon())
            ::fnv_00577e20::FUN_00577e20((::fnv_00577e20::TraversalNode *)(clone));
    }
}

// Returns true only if both INI boolean settings at g_011d5a10 and g_011d5a44 are enabled.
// @fnv 0x004abfa0
bool BipedAnim::CanLoadHiddenBipedObjects()
{
    return ((SettingT<INISettingCollection>*)&g_011d5a10)->Bool()->b &&
           ((SettingT<INISettingCollection>*)&g_011d5a44)->Bool()->b;
}

struct NiNode;
struct TESObjectREFR;
struct FUN_004aaca0_S
{
    FUN_004aaca0_S* Construct(int a, NiNode* n);
};
struct BipedAnimObject;
struct TESForm;
struct FUN_004aaff0_S
{
    void FUN_004aaff0(int a, bool b, TESForm* f);
};
// Calls ClearBipedObject with a pointer computed from this, a*16+0x2c, passing b and f.
// @fnv 0x004aaff0
void FUN_004aaff0_S::FUN_004aaff0(int aiIndex, bool abFlag, TESForm* apForm)
{
    reinterpret_cast<::BipedAnim *>(this)->ClearBipedObject((BipedAnimObject*)((char*)this + aiIndex * 16 + 0x2c), abFlag, apForm);
}


struct BipedAnim_Ext : public BipedAnim
{
};

struct TaskQueueInterface_Ext
{
};


// @fnv 0x004ab020
void BipedAnim::ClearBipedObject(BipedAnimObject* apObj, bool abClear, TESForm* aiClearValue)
{
    if (apObj->m_pSceneObject)
    {
        reinterpret_cast<::BipedAB *>((reinterpret_cast<BipedAnim_Ext*>(this)))->FUN_004ab130((::AVObjAB *)(apObj->m_pSceneObject));
        if (!::FUN_008c7aa0())
            ::FUN_004ab0c0((::Ref_cls *)(apObj->m_pSceneObject));
        else
            reinterpret_cast<::fnv_0087acb0::FUN_0087acb0_host *>((((::TaskQueueInterface_Ext *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087acb0((::fnv_0087acb0::G00559a40 *)(apObj->m_pSceneObject));
        reinterpret_cast<::FUN_0045a5e0_shell *>((g_modelLoader))->FUN_0045a5e0((char *)(apObj->m_pModel->GetModelFilePath()));
        apObj->m_pSceneObject = 0;
    }
    if (abClear)
    {
        apObj->pParent = 0;
        apObj->m_pModel = reinterpret_cast<TESModel*>(aiClearValue);
    }
}

// @fnv 0x004abf80
int FUN_004abf80(unsigned char* pThis)
{
    return pThis[0x14] & 0xe;
}

struct FUN_004ac110_shell : public TESNPC
{
    TESRace* FUN_004ac110();
};
// Queues the NPC's biped parts selected by flags and, if the race provides a modified model path, queues that model for loading.
// @fnv 0x004abfe0
void BipedAnim::QueueBipedObjectLoads(unsigned int flags, IO_TASK_PRIORITY priority, QueuedFile* parent)
{
    if (!flags)
        return;
    TESNPC* npc = (TESNPC*)dynamic_cast<TESFaction*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430())));
    if (npc)
    {
        if (flags & 2)
            LoadBipedObject(npc, (BIPED_OBJECT)2, priority, parent);
        if (flags & 4)
            LoadBipedObject(npc, (BIPED_OBJECT)4, priority, parent);
        if (flags & 8)
            LoadBipedObject(npc, (BIPED_OBJECT)3, priority, parent);
        char base[260], mod[260];
        ((TESRace*)((::TESHairRaceResult *)(reinterpret_cast<::FUN_004ac110_shell *>((((TESHairCanBeNPCData*)npc)))->FUN_004ac110())))->BuildBodyTexturePath(npc, base);
        if (reinterpret_cast<::fnv_006148f0::FUN_006148f0_shell *>((((TESRace*)((::TESHairRaceResult *)(reinterpret_cast<::FUN_004ac110_shell *>((((TESHairCanBeNPCData*)npc)))->FUN_004ac110())))))->BuildBodyModTexturePath(npc, base, mod))
            reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((g_modelLoader))->LoadTexture(mod, (*(void * *)&(priority)), parent);
    }
}
// If the NPC's race resolves a hair model path for the slot, queues that model and its _n variant with the model loader.
// @fnv 0x004ac130
void BipedAnim::LoadBipedObject(TESNPC* npc, BIPED_OBJECT slot, IO_TASK_PRIORITY priority, QueuedFile* parent)
{
    char base[260], mod[260];
    if (((TESRace*)((::TESHairRaceResult *)(reinterpret_cast<::FUN_004ac110_shell *>((((TESHairCanBeNPCData*)npc)))->FUN_004ac110())))->GetBipedObjectModelPath(npc, slot, base))
    {
        reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((g_modelLoader))->LoadTexture(base, (*(void * *)&(priority)), parent);
        BSShaderManager::BuildTexturePath(mod, base, "_n", true);
        if (mod[0])
            reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((g_modelLoader))->LoadTexture(mod, (*(void * *)&(priority)), parent);
    }
}

// @fnv 0x004ac110
TESRace* FUN_004ac110_shell::FUN_004ac110()
{
    return (TESRace*)((::BGSListForm *)(reinterpret_cast<::Callees *>((((BGSBipedModelList*)((char*)this + 0x10c))))->FUN_00726070()));
}

struct PA
{
    int z[4];
    PA(int);
};
struct PB
{
    int z[4];
    PB(int);
};
int FUN_004ad1b0();
char FUN_004ad1c0();
struct FUN_004ad0c0_S
{
    PA* a;
    PB* b;
    int c;
    char d;
    FUN_004ad0c0_S* Init(int x);
};
// Allocates a PA and a PB from x, stores results of FUN_004ad1b0 and FUN_004ad1c0, and returns this.
// @fnv 0x004ad0c0
FUN_004ad0c0_S* FUN_004ad0c0_S::Init(int aiValue)
{
    a = new PA(aiValue);
    b = new PB(aiValue);
    c = FUN_004ad1b0();
    d = FUN_004ad1c0();
    return this;
}

struct FUN_004ad1d0_Virt
{
    virtual ~FUN_004ad1d0_Virt();
};

struct FUN_004ad1d0_Obj
{
    FUN_004ad1d0_Virt* p0;
    FUN_004ad1d0_Virt* p4;
};

// Deletes the two objects pointed to by p0 and p4.
// @fnv 0x004ad1d0
void FUN_004ad1d0(FUN_004ad1d0_Obj* pThis)
{
    delete pThis->p0;
    delete pThis->p4;
}

struct FUN_004ad240_c
{
    char pad[0x10];
    float x;
    float y;
    float z;
    void SetScale(float afScale);
};

// Sets the x, y and z fields to the given scale value.
// @fnv 0x004ad240
void FUN_004ad240_c::SetScale(float afScale)
{
    z = afScale;
    y = afScale;
    x = afScale;
}

void FUN_004ad1d0(void*);

// @fnv 0x004ad270
void FUN_004ad270(void* p)
{
    FUN_004ad1d0(p);
}


// Copies count characters from src to dst via _fnv_CopyFilePath, passing count + 1 as the destination size.
// @fnv 0x004add50
void __cdecl FUN_004add50(char* dst, const char* src, unsigned int count)
{
    fnv::crt::strncpy_s(dst, count + 1, src, count);
}

struct FUN_004add70_shell : public NiNode
{
    void FUN_004add70();
};


// Calls FUN_004afc80 and TrimTrailingNullPointers on the sub-object at offset 0x9C of this node.
// @fnv 0x004add70
void FUN_004add70_shell::FUN_004add70()
{
    reinterpret_cast<::ObjPtrArray *>(&this->nodeFields[148])->FUN_004afc80();
    reinterpret_cast<::Pn4afe *>(&this->nodeFields[148])->TrimTrailingNullPointers();
}

struct FUN_004adda0_shell : public NiSkinInstance
{
    void SetBone(unsigned int, NiAVObject*);
};

// @fnv 0x004adda0
void FUN_004adda0_shell::SetBone(unsigned int uiIndex, NiAVObject* pkBone)
{
    (*(NiAVObject***)((char*)this + 0x14))[uiIndex] = pkBone;
}

struct DummyArr
{
    void FUN_00558dd0(int);
};

struct DummyThis
{
    char pad[0xc];
    DummyArr arr;
};

struct StackArg
{
    int val;
};

// @fnv 0x004addc0
void FUN_004addc0(DummyThis* this_ptr, StackArg aStackArg)
{
    this_ptr->arr.FUN_00558dd0(aStackArg.val);
}


// @fnv 0x004ade00
void __cdecl FUN_004ade00(int a1, int a2)
{
    ::FUN_00c4b470((::FUN_00c4b470_owner *)(a1), (void **)(a2), 1);
}


// @fnv 0x004ade20
void FUN_004ade20(void* pThis)
{
    reinterpret_cast<struct ::FUN_004afc20 *>((pThis))->Init();
}

struct FUN_004ae6a0_shell : public bhkWorldObject
{
    bhkShape* FUN_004ae6a0();
};


// @fnv 0x004ae6a0
bhkShape* FUN_004ae6a0_shell::FUN_004ae6a0()
{
    return ((::bhkShape *)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::GetStringCStr((::Dummy_004ae6c0 *)(void *)(this))))))));
}

struct Dummy_004ae6c0
{
    BSStringT<char>* FUN_004ae700();
};

// Calls FUN_004ae700 to get a BSStringT<char> and returns its character buffer, or null if the string pointer is null.
// @fnv 0x004ae6c0
const char* GetStringCStr(Dummy_004ae6c0* pThis)
{
    BSStringT<char>* str = pThis->FUN_004ae700();
    return str ? (const char*)*str : 0;
}

struct SrcList;
struct FormS
{
};
struct FUN_004ae700_S
{
    SrcList* FUN_004ae700();
};
// @fnv 0x004ae700
SrcList* FUN_004ae700_S::FUN_004ae700()
{
    SrcList* r = 0;
    FormS* f = ((::FormS *)(::FUN_004ae750((void *)this)));
    if (f)
    {
        ::FUN_00a29680();
        r = ((::SrcList *)(::FUN_00460140((int)(f))));
        ::FUN_00a29680();
    }
    return r;
}


// Returns the result of GetReferenceFlags on p when p is non-null, otherwise returns 0.
// @fnv 0x004ae750
intptr_t FUN_004ae750(void* p)
{
    return p ? ((int)(reinterpret_cast<::FUN_00620b80_shell *>((p))->GetReferenceFlags())) : 0;
}

// @fnv 0x004ae8f0
int FUN_004ae8f0(unsigned char* p)
{
    return p[0x14] & 1;
}

struct FUN_004af860_shell : public NiSourceTexture
{
    bool FUN_004af860();
};

// @fnv 0x004af860
bool FUN_004af860_shell::FUN_004af860()
{
    return (((char*)this)[0x43] & 0) != 0;
}

struct FUN_004af880_shell : public NiSourceTexture
{
    void FUN_004af880();
};

// @fnv 0x004af880
void FUN_004af880_shell::FUN_004af880()
{
    *((char*)this + 0x43) = *((char*)this + 0x43);
}

class BSFaceGenManager;
extern BSFaceGenManager* DAT_011d59e8;

// Returns the NiTexture stored at offset 0x11a0 of DAT_011d59e8, or a null NiPointer if DAT_011d59e8 is null.
// @fnv 0x004af8a0
NiTexture* __cdecl FUN_004af8a0()
{
    return DAT_011d59e8 ? *(const NiPointer<NiTexture>*)((const char*)DAT_011d59e8 + 0x11a0) : NiPointer<NiTexture>(0);
}

struct FUN_004afa20_shell : public BipedAnim
{
    TESModel* FUN_004afa20(int, char*);
};
// Assigns the biped model form or race to the matching biped slots, removing parts whose parent differs and optionally swapping in the 1st-person model.
// @fnv 0x004abad0
void BipedAnim::SetBipedObject(TESForm* form, TESModel* model, BIPED_OBJECT slot)
{
    TESBipedModelForm* pBipedModelForm = ::TESBipedModelForm::GetFormAsBipedModel(form);
    TESRace* pRace = dynamic_cast<TESRace*>(form);
    bool bUse1stPerson = false;
    char szFileName[260];
    unsigned int i;
    if (model && reinterpret_cast<::FUN_00950b30_Class *>((::_g_thePlayer))->FUN_00950b30(this))
        bUse1stPerson = IsModelPathMatch(model, szFileName);
    if (pBipedModelForm)
    {
        for (i = 0; i < 20; ++i)
            if (pBipedModelForm->HasBipedModel((BIPED_OBJECT)i, false, 0) && object[i].pParent != form)
            {
                if (object[i].pParent && dynamic_cast<TESRace*>(object[i].pParent))
                    reinterpret_cast<::FUN_004aaff0_S *>(this)->FUN_004aaff0((*(int *)&(const ::BIPED_OBJECT &)((BIPED_OBJECT)i)), true, 0);
                else
                    RemovePartsByParent(object[i].pParent);
            }
        for (i = 0; i < 20; ++i)
            if (pBipedModelForm->HasBipedModel((BIPED_OBJECT)i, true, 0))
            {
                if (bUse1stPerson)
                    model = reinterpret_cast<::FUN_004afa20_shell *>(this)->FUN_004afa20((*(int *)&(const ::BIPED_OBJECT &)((BIPED_OBJECT)i)), szFileName);
                object[i].pParent = form;
                object[i].m_pModel = model;
                break;
            }
    }
    else if (pRace)
    {
        reinterpret_cast<::FUN_004aaff0_S *>(this)->FUN_004aaff0((*(int *)&(slot)), true, 0);
        if (bUse1stPerson)
            model = reinterpret_cast<::FUN_004afa20_shell *>(this)->FUN_004afa20((*(int *)&(slot)), szFileName);
        object[slot].pParent = form;
        object[slot].m_pModel = model;
    }
}
// @fnv 0x004afa50
TESModel* BipedAnim::GetModelForSlot(BIPED_OBJECT slot, TESModel* model)
{
    char path[260];
    if (model == &DAT_011c5d10[slot])
        return model;
    if (IsModelPathMatch(model, path))
        return reinterpret_cast<::FUN_004afa20_shell *>(this)->FUN_004afa20((*(int *)&(slot)), path);
    return model;
}

struct TESFullNameSetFullNameAccess : public TESFullName
{
    void SetFullName(const char* name);
};

// @fnv 0x004afa20
TESModel* FUN_004afa20_shell::FUN_004afa20(int aeBipedObject, char* ap1stPersonFileName)
{
    reinterpret_cast<TESFullName*>(&DAT_011c5d10[aeBipedObject])
            ->*reinterpret_cast<void (TESFullName::*)(const char*)>(&TESFullNameSetFullNameAccess::SetFullName);
    reinterpret_cast<::TESFullName *>((reinterpret_cast<TESFullNameSetFullNameAccess*>(&DAT_011c5d10[aeBipedObject])))->SetFullName(ap1stPersonFileName);
    return &DAT_011c5d10[aeBipedObject];
}


struct BSStringT_layout
{
    char* m_data;
    unsigned short m_dataLen;
};

// If m_data is set, calls FUN_004afb00 on it with m_dataLen + 1 as the size.
// @fnv 0x004afad0
void FUN_004afad0(BSStringT_layout* thisPtr)
{
    if (thisPtr->m_data)
    {
        ::FUN_004afb00(thisPtr->m_data, thisPtr->m_dataLen + 1);
    }
}

struct S4411
{
    S4411* InitWithGlobal(int a, int b);
};
// Calls FUN_0043fd40 with the two arguments, stores the address of DAT_01016ca4 in the object's first field, and returns this.
// @fnv 0x004aff00
S4411* S4411::InitWithGlobal(int aiArg1, int aiArg2)
{
    new ((void *)this) ::FUN_004b0260_shell(aiArg1, aiArg2);
    *reinterpret_cast<int**>(this) = &::reconstruct_c5a9d0::Array::DAT_0101fbd4;
    return this;
}

struct Dummy_004f8a90
{
};

struct FUN_004f8a30_shell2
{
    int FUN_004f8a30(int arg1);
};

// Calls FUN_004f8a90 with arg1 and a local result, then returns that result.
// @fnv 0x004f8a30
int FUN_004f8a30_shell2::FUN_004f8a30(int arg1)
{
    int result = 0;
    reinterpret_cast<::FUN_004f8a90_Class *>((((Dummy_004f8a90*)this)))->FUN_004f8a90(arg1, (*(unsigned int *)(&result)));
    return result;
}

struct FUN_009cdae0_shell : public NiAVObject
{
    float GetFloatAt64();
};
// @fnv 0x004ae250
void BipedAnim::AttachFaceGenNode(NiNode* rootNode, NiNode* objectNode, NiNode* sourceNode, BipedAnim* biped,
                                  BIPED_OBJECT slot, BSFaceGenModel* face)
{
    BipedAttachmentTarget attachment;
    {
        attachment.metadata = 0;
        NiStringExtraData* pName = 0;
        {
            attachment.parent = 0;
            if (sourceNode)
                attachment.metadata = sourceNode->GetExtraData(FUN_004ae780());
            if (!attachment.metadata)
                attachment.metadata = objectNode->GetExtraData(FUN_004ae780());
            if (attachment.metadata)
            {
                pName = (NiStringExtraData*)((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4a38)), (::NiObject *)(::NiProperty *)((NiProperty*)attachment.metadata))));
                if (pName)
                {
                    NiAVObject* found = FUN_004ade00(rootNode, BIPED_EXTRA_STRING(pName));
                    attachment.parent = (NiNode*)found;
                    if (!attachment.parent)
                    {
                        TESObjectREFR* ref = ::FUN_0056f930(rootNode);
                        if (ref && ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) && ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->GetFormType() == 43)
                            HandleUnparentedObjectNode(objectNode);
                        else
                            Warning("MODELS: Could not find parent node '%s' for object '%s'.",
                                    BIPED_STRING_TEXT(BIPED_EXTRA_STRING(pName)), BIPED_OBJECT_TEXT(objectNode));
                    }
                }
                else
                    Warning("MODELS: Extra data 'Prn' on '%s' is not an NiStringExtraData.",
                            BIPED_OBJECT_TEXT(objectNode));
            }
            else
                Warning("MODELS: Could not find parent node extra data for '%s'.", BIPED_OBJECT_TEXT(objectNode));
            float fScale = 1.0f;
            if (attachment.parent)
            {
                fScale = reinterpret_cast<::FUN_009cdae0_shell *>((attachment.parent))->GetFloatAt64();
                attachment.parent->AddObject(objectNode, true);
                NiUpdateData UpdateData((float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00(), false, false);
                objectNode->UpdateDownwardPass(UpdateData, 0);
                ShadowSceneNode* shadowScene = ::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
                shadowScene->AddObject(objectNode);
                NiAVObject* scabbard = ::FUN_004aae30(objectNode, (::NiFixedString *)("Scb"));
                if (scabbard)
                {
                    attachment.parent->AddObject(scabbard, true);
                    ::SetCollisionRefFlag((::C6C0E0AVObject *)(attachment.parent), true);
                    reinterpret_cast<::FUN_00a5a040_Class *>((scabbard))->FUN_00a5a040();
                    reinterpret_cast<::FUN_004add70_shell *>((objectNode))->FUN_004add70();
                }
            }
            NiAVObject* pBackpackNode = ::FUN_004aae30(objectNode, (::NiFixedString *)("Backpack"));
            if (pBackpackNode)
            {
                if (rootNode == ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true))))
                    reinterpret_cast<::TaskQueueInterface *>((pBackpackNode))->QueueActorDisarm(true);
                else
                {
                    reinterpret_cast<::FUN_00440490_shell *>((pBackpackNode))->FUN_00440490(fScale);
                    attachment.metadata = pBackpackNode->GetExtraData(NiFixedString("UPB"));
                    if (attachment.metadata)
                    {
                        pName = (NiStringExtraData*)((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4a38)), (::NiObject *)(::NiProperty *)((NiProperty*)attachment.metadata))));
                        if (pName)
                        {
                            NiAVObject* found = FUN_004ade00(rootNode, BIPED_EXTRA_STRING(pName));
                            attachment.parent = (NiNode*)found;
                            if (attachment.parent)
                                attachment.parent->AddObject(pBackpackNode, true);
                        }
                    }
                }
            }
            if (biped && biped == ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(true))))
                ::FUN_00c6a2e0((::C6A2E0AVObject *)(objectNode), true, true);
            else
            {
                switch (slot)
                {
                case BIPED_WEAPON: {
                    bhkCollisionObject* pCollision = bhkCollisionObject::GetFromNiAVObject(objectNode);
                    if (pCollision)
                    {
                        bhkWorldObject* pBody = pCollision ? ((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(pCollision)))) : 0;
                        bhkShape* pShape = pBody ? reinterpret_cast<::FUN_004ae6a0_shell *>((pBody))->FUN_004ae6a0() : 0;
                        if (!pShape)
                            Warning("HAVOK: Weapon '%s' doesn't have a good Havok shape on it.",
                                    BIPED_OBJECT_TEXT(objectNode));
                        if (pBody && reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::bhkFilter &)(pBody->FUN_0043b4f0()))->FUN_0043b4d0() != 5)
                            Warning("MODELS: Weapon '%s' needs to have the layer defined as a WEAPON.",
                                    BIPED_OBJECT_TEXT(objectNode));
                    }
                    else
                        Warning("HAVOK: Weapon '%s' doesn't have any Havok data on it.", BIPED_OBJECT_TEXT(objectNode));
                    break;
                }
                }
                ::FUN_00c6a350((::NiAVObject *)(objectNode), 4, true, true, true);
            }
        }
    }
}

// @fnv 0x009cdae0
float FUN_009cdae0_shell::GetFloatAt64()
{
    return *(float*)((char*)this + 0x64);
}


// @fnv 0x004aae30
NiAVObject* __cdecl FUN_004aae30(NiAVObject* apObject, NiFixedString* a2)
{
    return ((::NiAVObject *)(::FUN_00c4b310((::ObjQ *)(apObject), (const char *)(a2), 1)));
}

extern NiFixedString* DAT_011c61e4;

// @fnv 0x004ab220
const NiFixedString& FUN_004ab220()
{
    return *DAT_011c61e4;
}

struct FUN_004ad030_shell
{
    int pad0[75];
    int flags;
    bool GetFlag();
};

// @fnv 0x004ad030
bool FUN_004ad030_shell::GetFlag()
{
    return (flags & 0x2000) ? true : false;
}

extern int DAT_011f4300;

// @fnv 0x004ad1b0
int __cdecl FUN_004ad1b0()
{
    return DAT_011f4300;
}

namespace fnv_004ad1c0 {
extern unsigned char DAT_011a94a8;

// @fnv 0x004ad1c0
unsigned char __cdecl FUN_004ad1c0()
{
    return DAT_011a94a8;
}
}  // namespace fnv_004ad1c0

extern NiFixedString* DAT_011c61e8;

// @fnv 0x004ae780
const NiFixedString& __cdecl FUN_004ae780()
{
    return *DAT_011c61e8;
}

// @fnv 0x004af340
int FUN_004af340()
{
    return 5;
}

// @fnv 0x004af350
unsigned int FUN_004af350()
{
    return 2;
}

struct FUN_004aae50_shell : BipedAnim
{
    void FUN_004aae50();
};

// @fnv 0x004aae50
void FUN_004aae50_shell::FUN_004aae50()
{
    CompleteModelLoadTask();
}

struct FUN_004afb80_struct
{
};

struct FUN_004aaef0_shell
{
    FUN_004afb80_struct* m_p;
    void CallContainedObject();
};

// @fnv 0x004aaef0
void FUN_004aaef0_shell::CallContainedObject()
{
    reinterpret_cast<::FUN_004afb80_shell *>((m_p))->LockAtOffset();
}

// Removes every biped part whose parent object is apForm, iterating over the 0x14 part slots.
// @fnv 0x004aaf90
void BipedAnim::RemovePartsByParent(TESForm* apForm)
{
    if (apForm == 0)
        return;
    for (int i = 0; i < 0x14; i++)
    {
        if (object[i].pParent == apForm)
            reinterpret_cast<::FUN_004aaff0_S *>(this)->FUN_004aaff0((*(int *)&(const ::BIPED_OBJECT &)((BIPED_OBJECT)i)), 1, 0);
    }
}

struct FUN_004ad010_shell
{
    bool IsFlag4Set();
};
// @fnv 0x004ad010
bool FUN_004ad010_shell::IsFlag4Set()
{
    return *(unsigned char*)(this + 0x100) & 4;
}

struct BSPackedTask
{
    int f0;
    int f1;
    int f2;
    char buf[20];
};
struct Host0087b360
{
    void FUN_0087b360(int a, int b);
};
// @fnv 0x0087b360
void Host0087b360::FUN_0087b360(int aiFirst, int aiSecond)
{
    BSPackedTask task;
    task.f0 = 0x15;
    task.f1 = aiFirst;
    task.f2 = aiSecond;
    reinterpret_cast<::TaskQueueInterface *>(this)->ProcessPackedTask(task);
}

struct FUN_004aaf10_shell
{
    void FUN_004aaf10();
};
// @fnv 0x004aae70
void BipedAnim::CompleteModelLoadTask()
{
    reinterpret_cast<::FUN_004aaef0_shell *>((g_modelLoader))->CallContainedObject();
    reinterpret_cast<::GlobalObject_0044fae0 *>((((ActorTaskManager*)&g_011c5cf0)))->FUN_004538a0(0);
    for (int i = 0; i < 20; ++i)
    {
        reinterpret_cast<::FUN_004aaff0_S *>(this)->FUN_004aaff0((*(int *)&(const ::BIPED_OBJECT &)((BIPED_OBJECT)i)), true, 0);
        ClearBipedObject(&m_kPreviousObjects[i], true, 0);
    }
    ((ActorTaskManager*)&g_011c5cf0)->WaitForTasksDuringRendering();
    reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
}

// @fnv 0x004aaf10
void FUN_004aaf10_shell::FUN_004aaf10()
{
    reinterpret_cast<::fnv_004afba0::FUN_004afba0_class *>((reinterpret_cast<FUN_004aaf10_shell*>(*reinterpret_cast<int*>(this))))->UnlockAtOffset();
}

struct FUN_004ab730_shell
{
    bool IsFlagSet();
};

// @fnv 0x004ab730
bool FUN_004ab730_shell::IsFlagSet()
{
    return reinterpret_cast<unsigned char*>(this)[0x100] & 0x10;
}

struct FUN_004aaf30_Entry
{
    void* ptr;
    int f04;
    int f08;
    int f0C;
};
struct FUN_004aaf30_Holder
{
    char pad[0x2C];
    FUN_004aaf30_Entry entries[20];
    void* FindEntry(void* p);
};
// Searches the 20 entries for one whose ptr equals p and returns a pointer to it, or null if p is null or no match is found.
// @fnv 0x004aaf30
void* FUN_004aaf30_Holder::FindEntry(void* apTarget)
{
    int i;
    if (apTarget == 0)
        return 0;
    for (i = 0; i < 20; ++i)
    {
        if (entries[i].ptr == apTarget)
            return &entries[i];
    }
    return 0;
}

struct FUN_004adde0_shell
{
    unsigned char pad[0xbc];
    NiPointer<NiNode> m_ptr;
    void FUN_004adde0(NiNode* apGO);
};

// @fnv 0x004adde0
void FUN_004adde0_shell::FUN_004adde0(NiNode* apGO)
{
    m_ptr = apGO;
}

extern const char* DAT_01188b98[];
struct FUN_004aeb20_holder : BipedAnim
{
    void AttachFaceGenModel(BSFaceGenModel* apfgModel, NiNode* apNode, BIPED_OBJECT aeBipedObject);
};
// @fnv 0x004aeb20
void FUN_004aeb20_holder::AttachFaceGenModel(BSFaceGenModel* apFaceGenModel, NiNode* apNode, BIPED_OBJECT aeBipedObject)
{
    NiNode* pcloneNode = 0;
    if (apFaceGenModel && apNode)
    {
        BIPED_BONE boneIndex = (BIPED_BONE)DAT_01188be8[aeBipedObject];
        bool b1st = false;
        if (m_pActor == _g_thePlayer && reinterpret_cast<::FUN_00950b30_Class *>((_g_thePlayer))->FUN_00950b30(this))
            b1st = true;
        pcloneNode = apNode;
        NiAVObject* ppartClone;
        bool bfirstPerson = false;
        bool bpipboy = object[6].pParent;
        if (m_pActor == _g_thePlayer && reinterpret_cast<::FUN_00950b30_Class *>((_g_thePlayer))->FUN_00950b30(this))
            bfirstPerson = true;
        ppartClone = PrepareBipedModel(pcloneNode, aeBipedObject, bfirstPerson, bpipboy, apFaceGenModel);
        if (!ppartClone)
        {
            ppartClone = pcloneNode;
            AttachFaceGenNode(root, pcloneNode, 0, this, aeBipedObject, apFaceGenModel);
        }
        if (ppartClone)
        {
            BSStringT<char> newName;
            ::FUN_00406f60((::FUN_00406f90_this *)&(newName), "%s %s (%08X)", DAT_01188b98[aeBipedObject], object[aeBipedObject].pParent->GetEditorID(),
                            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((object[aeBipedObject].pParent))->FUN_0084e3a0())));
            ::AssignFixedString((char *)(ppartClone), (int)&(const ::NiFixedString &)(NiFixedString(newName)), {});
            ApplyReferenceExtraData(apNode, pcloneNode, aeBipedObject, m_pActor);
            if (!object[aeBipedObject].bHasAnimation && ppartClone->IsSceneNode())
            {
                NiNode* pparent = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((ppartClone))->FUN_009611e0()));
                if (bone[boneIndex].pParent)
                    bone[boneIndex].pParent->AddObject(ppartClone, true);
                else if (((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((ppartClone))->FUN_009611e0())))
                    root->AddObject(ppartClone, true);
            }
            object[aeBipedObject].m_pSceneObject = ppartClone;
        }
    }
    if (m_pActor && ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((m_pActor))->FUN_0043fcd0())))
        reinterpret_cast<::FUN_00a5a040_Class *>((((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((m_pActor))->FUN_0043fcd0()))))->FUN_00a5a040();
}

struct TESObjectSTAT;
struct FUN_004ab500_shell : TESObjectWEAP
{
    TESObjectSTAT* GetModSlotStat(unsigned char iModSlots);
};
// Returns the TESObjectSTAT pointer stored at one of eight offsets selected by the low three bits of iModSlots.
// @fnv 0x004ab500
TESObjectSTAT* FUN_004ab500_shell::GetModSlotStat(unsigned char uiModSlotMask)
{
    if (uiModSlotMask & 1)
    {
        if (uiModSlotMask & 2)
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x26c);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x260);
            }
        }
        else
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x268);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x254);
            }
        }
    }
    else
    {
        if (uiModSlotMask & 2)
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x264);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x258);
            }
        }
        else
        {
            if (uiModSlotMask & 4)
            {
                return *(TESObjectSTAT**)((char*)this + 0x25c);
            }
            else
            {
                return *(TESObjectSTAT**)((char*)this + 0x250);
            }
        }
    }
}

struct FUN_004aad00_shell
{
    struct BoneEntry
    {
        unsigned char flag;
        unsigned char pad[3];
        NiAVObject* bone;
    };

    NiAVObject* root;
    BoneEntry bones[5];

    void InitBoneSlots(NiAVObject*);
};
// Zeroes the object's memory, stores a at offset 0x2b0, and if n is non-null calls InitBoneSlots(n); returns this.
// @fnv 0x004aaca0
FUN_004aaca0_S* FUN_004aaca0_S::Construct(int a, NiNode* pNode)
{
    memset(this, 0, 0x2b4);
    memset((char*)this + 0x16c, 0, 0x140);
    *(int*)((char*)this + 0x2b0) = a;
    if (pNode == 0)
    {
    }
    else
    {
        reinterpret_cast<::FUN_004aad00_shell *>(this)->InitBoneSlots((::NiAVObject *)(pNode));
    }
    return this;
}

struct GO
{
    unsigned int value;

    GO(int);
    operator unsigned int() const;
    ~GO();
};

extern const char* DAT_01188b74[5];

// Looks up the root "Bip01" and five named bones under pBone, storing each found bone and setting its flag, or warning when a bone is missing.
// @fnv 0x004aad00
void FUN_004aad00_shell::InitBoneSlots(NiAVObject* pBone)
{
    int i;

    root = ::FUN_004aae30(pBone, (::NiFixedString *)("Bip01"));

    for (i = 0; i < 5; ++i)
    {
        GO bone(reinterpret_cast<int>(::FUN_004aae30(pBone, (::NiFixedString *)(DAT_01188b74[i]))));

        if (bone.operator unsigned int() && reinterpret_cast<NiAVObject*>(bone.operator unsigned int())->IsSceneNode())
        {
            bones[i].flag |= 1;
            bones[i].bone = reinterpret_cast<NiAVObject*>(bone.operator unsigned int());
        }
        else
        {
            ::FUN_005b5e40();
        }
    }
}

struct StatFormPart
{
    virtual void vfn_0();
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
};
struct StaticObj : public StatFormPart, public TESModel
{
};

struct WeapAccess : public TESObjectWEAP
{
};

struct BipedAnimWeap : public BipedAnim
{
    void SetWeaponModel(TESObjectWEAP* apWeapon, unsigned char iModSlots);
};

// Removes the weapon biped part, resolves the weapon's mod/static TESModel, and stores the weapon and model into the BIPED_WEAPON slot.
// @fnv 0x004ab400
void BipedAnimWeap::SetWeaponModel(TESObjectWEAP* apWeapon, unsigned char iModSlots)
{
    if (!apWeapon || apWeapon->GetFormType() != 0x28 ||
        (apWeapon == object[BIPED_WEAPON].pParent && object[BIPED_WEAPON].m_pSceneObject))
        return;

    reinterpret_cast<::FUN_004aaff0_S *>(this)->FUN_004aaff0((*(int *)&(const ::BIPED_OBJECT &)(BIPED_WEAPON)), true, 0);
    TESModel* m_kModelObjectsItem = reinterpret_cast<::FUN_00522df0_shell *>((((WeapAccess*)apWeapon)))->GetModelForModFlags(iModSlots, true);
    if (this == ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(true))) || this == ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(false))))
    {
        StaticObj* pStaticModel = ((::StaticObj *)(reinterpret_cast<::MiddleHighProcess *>((((WeapAccess*)apWeapon)))->GetAnimationObject()));
        if (iModSlots && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apWeapon))->FUN_0084e3a0())) != 0x1735d4)
        {
            StaticObj* pModStaticModel = 0;
            pModStaticModel = ((::StaticObj *)(reinterpret_cast<::FUN_004ab500_shell *>((((WeapAccess*)apWeapon)))->GetModSlotStat(iModSlots)));
            if (pModStaticModel)
                pStaticModel = pModStaticModel;
        }
        if (pStaticModel)
            m_kModelObjectsItem = pStaticModel;
    }
    object[BIPED_WEAPON].pParent = apWeapon;
    object[BIPED_WEAPON].m_pModel = m_kModelObjectsItem;
}

struct NotificationProbe : NiAVObject
{
    virtual void UpdateAttach(NiAVObject*, int);
};
struct SkinDataProbe
{
};
struct SkinInstanceProbe : NiSkinInstance
{
};
struct SceneNodeProbe : NiNode
{
};
struct HandleVectorProbe
{
    void FUN_004afc50(const NiPointer<NiAVObject>&);
};
extern const char DAT_0101f8d8[];
extern const char DAT_0101f890[];
extern const char DAT_0101f840[];
extern const char DAT_0101f7c8[];

// @fnv 0x004ade40
void __cdecl FUN_004ade40(NiNode* source, NiAVObject* object, NiAVObject* notify, bool report)
{
    if (!object)
        return;

    NiNode* node = object->IsSceneNode();
    if (object->IsGeometry())
    {
        NiSkinInstance* geometry;
        NiTriBasedGeom* skin = static_cast<NiTriBasedGeom*>(object);
        geometry = ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skin))));
        if (geometry)
        {
            NiAVObject* boneCount;
            unsigned int replacement = ((unsigned int)(reinterpret_cast<::LowProcess *>((reinterpret_cast<SkinDataProbe*>(((::NiSkinData *)(reinterpret_cast<::TESRegionDataMap *>((geometry))->GetRegionMapName())))))->GetActiveCombatTarget()));
            NiAVObject** bones = ((::NiAVObject **)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((geometry))->FUN_00825c00()));
            for (unsigned int i = 0; i < replacement; ++i)
            {
                if (bones[i])
                {
                    boneCount = FUN_004ade00(source, (*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(bones[i]))->GetLinkToList())));
                    if (boneCount)
                    {
                        reinterpret_cast<::FUN_004adda0_shell *>((geometry))->SetBone(i, boneCount);
                    }
                    else
                    {
                        reinterpret_cast<::FUN_004adda0_shell *>((geometry))->SetBone(i, source);
                        if (report)
                        {
                            if (node && !fnv::crt::strnicmp((const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(object))->GetLinkToList())), (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(bones[i]))->GetLinkToList())),
                                                      (std::size_t)(std::uintptr_t)(((const char *)(::FUN_0044a670((const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(bones[i]))->GetLinkToList()))))))))
                            {
                                ::FUN_005b5e40();
                            }
                            else if (node && source)
                            {
                                ::FUN_005b5e40();
                            }
                            else
                            {
                                ::FUN_005b5e40();
                            }
                        }
                    }
                }
            }
            if (notify)
            {
                reinterpret_cast<::BGSQuestObjective *>((reinterpret_cast<SkinInstanceProbe*>(geometry)))->SetOwner((::TESQuest *)(notify));
                static_cast<NotificationProbe*>(notify)->UpdateAttach(object, 1);
            }
        }
    }
    bool printed = false;
    if (node)
    {
        reinterpret_cast<::FUN_004add70_shell *>((node))->FUN_004add70();
        GlobalObject_004aff00 children(0, 1);
        for (unsigned int j = 0; j < node->FUN_0043b480(); ++j)
        {
            NiAVObject* childNode = node->GetAt(j);
            NiNode* child = 0;
            if (childNode)
                child = childNode->IsSceneNode();
            else
                continue;
            if (::FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f9140)), (::NiAVObject *)(node)) && child)
            {
                FUN_004ade40(source, childNode, notify, true);
                continue;
            }
            if (!childNode->IsGeometry())
            {
                if (!printed && child && reinterpret_cast<::FUN_00453470_shell *>((reinterpret_cast<NiNode*>(childNode)))->FUN_00453470())
                {
                    ::FUN_005b5e40();
                    printed = true;
                }
                {
                    NiPointer<NiAVObject> item(childNode);
                    reinterpret_cast<HandleVectorProbe*>(&children)->FUN_004afc50(item);
                }
                node->RemoveObject(childNode);
                continue;
            }
            FUN_004ade40(source, childNode, notify, report);
        }
        reinterpret_cast<::FUN_004add70_shell *>((node))->FUN_004add70();
    }
}

class ATM
{
  public:
};
struct FaceLoader : BipedAnim
{
    BSFaceGenModel* FUN_004ae790(int slot);
};
// @fnv 0x004ae790
BSFaceGenModel* FaceLoader::FUN_004ae790(int slot)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>((((ATM*)&g_011c5cf0)))->FUN_004538a0(0);
    TESModel* model = object[slot].m_pModel;
    BSFaceGenModel* result = 0;
    if (model)
    {
        BSStringT<char> name;
        char path[260];
        ::TaskQueueInterface::CopyStringToBuffer(path, 260, "Meshes\\");
        strcat_s(path, 260, model->GetModelFilePath());
        result = ((::BSFaceGenModel *)(::GetOrCreateFaceGenModel((char *)(void *)(((void *)(::fnv_00653520::BuildEgmFilename((::fnv_00653520::StrMem *)(::BSStringT<char> *)(&name), path, -1)))), (char *)(0), (char *)(0), (char *)(0), 1, -1, 0)));
    }
    reinterpret_cast<::ActorTaskManager *>((((ATM*)&g_011c5cf0)))->WaitForTasksDuringRendering();
    return result;
}

struct C4AEDE0Object;

class C4AEDE0Ptr
{
  public:
    C4AEDE0Ptr(C4AEDE0Object* pkObject);
    ~C4AEDE0Ptr();

    C4AEDE0Object* m_pPointer;
};

class C4AEDE0Queue
{
  public:
    void QueueItem(int iA, int iB, int iC);
};

class B4AEE60Owner;

class B4AEE60Request
{
  public:
};

struct B4AEE60Slot
{
    int m_iHandle;
    int unk04;
    int unk08;
    int unk0C;
};

class B4AEE60ModelLoader
{
  public:
};


class B4AEE60Owner
{
  public:
    void RequestModelLoad(int iParamA, int iParamB, B4AEE60Request* pkRequest, int iSlot);

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
    B4AEE60Slot m_akSlots[4];
};
// Constructs a null C4AEDE0Ptr and passes it with iA, iB and iC to QueueFull.
// @fnv 0x004aede0
void C4AEDE0Queue::QueueItem(int iA, int iB, int iC)
{
    C4AEDE0Ptr spResult(0);
    reinterpret_cast<::B4AEE60Owner *>(this)->RequestModelLoad(iA, iB, (::B4AEE60Request *)&(spResult), iC);
}

// If the request has no result yet, starts a model load for the given slot when its handle is valid, otherwise completes the request with null.
// @fnv 0x004aee60
void B4AEE60Owner::RequestModelLoad(int iParamA, int iParamB, B4AEE60Request* pkRequest, int iSlot)
{
    if (((void *)(::FUN_00559450((int *)(pkRequest)))))
        return;

    if (m_akSlots[iSlot].m_iHandle != 0 && m_akSlots[iSlot].m_iHandle != -1)
        reinterpret_cast<::FUN_004450c0_holder *>(((*reinterpret_cast<::B4AEE60ModelLoader * *>(&::g_modelLoader))))->FUN_004450c0((::FUN_0043f010 *)(::B4AEE60Owner *)(this), (::QHelmetDest *)(pkRequest), iParamA, (::QueuedFile *)(iParamB), iSlot);
    else
        reinterpret_cast<::FUN_006f74f0_cls *>((pkRequest))->FUN_006f74f0((::ObjA *)(void *)(0));
}

struct ActorCalls
{
};
struct PlayerCalls
{
};
struct BGSLoadShell
{
};
struct AnimShell
{
};
struct FUN_004ab750_shell : BipedAnim
{
    void FUN_004ab750(TESObjectWEAP* apWeapon, unsigned char iModSlots);
};
// Rebuilds the weapon model for a weapon form, names it, and updates the actor's animation and weapon-drawn state.
// @fnv 0x004ab750
void FUN_004ab750_shell::FUN_004ab750(TESObjectWEAP* apWeapon, unsigned char iModSlots)
{
    if (!apWeapon || (int)apWeapon->GetFormType() != 0x28 ||
        (apWeapon == object[5].pParent && object[5].m_pSceneObject))
        return;
    {
        ((BipedAnimWeap*)this)->SetWeaponModel(apWeapon, iModSlots);
        int slot = 5;
        if (m_pActor == _g_thePlayer)
            object[5].m_pSceneObject =
                ::FUN_004aeed0(object[5].pParent, object[5].m_pModel, slot, m_pActor,
                             (::NiAVObject *)(::NiNode *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((_g_thePlayer))->FUN_00950bb0(reinterpret_cast<::FUN_00950b30_Class *>((((PlayerCalls*)_g_thePlayer)))->FUN_00950b30(this))))));
        else
            object[5].m_pSceneObject = ::FUN_004aeed0(object[5].pParent, object[5].m_pModel, slot, m_pActor, (::NiAVObject *)(::NiNode *)(0));
        if (!object[5].m_pSceneObject)
            return;
        {
            BSStringT<char> str;
            ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&str), "%s %s (%08X)", DAT_01188b98[5], object[5].pParent->GetEditorID(),
                         ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((object[5].pParent))->FUN_0084e3a0())));
            ::AssignFixedString((char *)(object[5].m_pSceneObject), (int)&(const ::NiFixedString &)(NiFixedString((const char*)str)), {});
            if (((FUN_004ab730_shell*)apWeapon)->IsFlagSet() && object[7].m_pSceneObject)
                reinterpret_cast<::TaskQueueInterface *>((object[7].m_pSceneObject))->QueueActorDisarm(true);
            if (m_pActor->IsActor())
            {
                TESObjectREFR* pActor = m_pActor;
                BaseProcess* pProc = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((ActorCalls*)pActor)))->GetBaseTexture()));
                if (pProc && !reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004226e0() && !reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition() &&
                    this != ((::BipedAnim *)(reinterpret_cast<::PlayerCharacter *>((((PlayerCalls*)_g_thePlayer)))->FUN_00950b00(true))))
                    reinterpret_cast<::fnv_008b0b00::FUN_008b0b00_cls *>((((ActorCalls*)pActor)))->FUN_008b0b00(true);
                if (pProc && !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::BGSLoadShell * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                {
                    Animation* anim = 0;
                    if (m_pActor == _g_thePlayer && this == ((::BipedAnim *)(reinterpret_cast<::PlayerCharacter *>((((PlayerCalls*)_g_thePlayer)))->FUN_00950b00(true))))
                        anim = _g_thePlayer->GetAnimation(true);
                    else
                        anim = reinterpret_cast<::FUN_008b70d0_shell *>((((ActorCalls*)pActor)))->FUN_008b70d0();
                    if (anim)
                        reinterpret_cast<::fnv_004994f0::FUN_004994f0_shell *>((((AnimShell*)anim)))->FUN_004994f0(4, false);
                    if (m_pActor == _g_thePlayer && this == ((::BipedAnim *)(reinterpret_cast<::PlayerCharacter *>((((PlayerCalls*)_g_thePlayer)))->FUN_00950b00(true))))
                        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((ActorCalls*)pActor)))->GetBaseTexture()))
                            ->UpdateWeaponDrawn(reinterpret_cast<::FUN_008a16d0_shell *>((((ActorCalls*)pActor)))->FUN_008a16d0(), this,
                                                _g_thePlayer->GetAnimation(true), pActor);
                    else
                        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((ActorCalls*)pActor)))->GetBaseTexture()))
                            ->UpdateWeaponDrawn(reinterpret_cast<::FUN_008a16d0_shell *>((((ActorCalls*)pActor)))->FUN_008a16d0(), this,
                                                reinterpret_cast<::FUN_008b70d0_shell *>((((ActorCalls*)pActor)))->FUN_008b70d0(), pActor);
                }
            }
        }
    }
}

struct BuildContext
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    BuildContext(float);
    ~BuildContext();
};
struct LoadedObject
{
};
struct ModelSource
{
};
struct ObjectPtr
{
    LoadedObject* value;
    ObjectPtr(int);
    ~ObjectPtr();
    void Assign(LoadedObject*);
};
struct Loader
{
};
struct Attachment
{
};
struct ParentObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual Attachment* GetAttachment();
};
struct FormObject
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
    virtual bool IsReady();
};
struct EquipSlot
{
    FormObject* form;
    ParentObject* parent;
    LoadedObject* object;
    int unk0C;
};
struct FUN_004ae910_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    EquipSlot slots[20];
    LoadedObject* LoadSlotObject(void*, ModelSource*, int);
};
// @fnv 0x004ae910
LoadedObject* FUN_004ae910_cls::LoadSlotObject(void* owner, ModelSource* source, int slot)
{
    if (slots[slot].object)
        return 0;
    if (owner && source)
    {
        int aId = DAT_01188be8[slot];
        BuildContext context(1.0f);
        ObjectPtr holder(0);
        LoadedObject* pTemp;
        if (::FUN_004b5bf0((::NiAVObject *)(source)))
        {
            holder.Assign(((::LoadedObject *)(reinterpret_cast<::FUN_00457ba0_class *>(((*reinterpret_cast<::Loader * *>(&::g_TES))))->FUN_00457ba0((::NiAVObject *)(source), (::CloningProcess *)(::BuildContext *)(&context)))));
            pTemp = ((::LoadedObject *)(::FUN_00559450((int *)&(holder))));
        }
        else
        {
            pTemp = ((::LoadedObject *)(reinterpret_cast<::A5D2C0Object *>((source))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&context)))));
        }
        LoadedObject* kObj = pTemp;
        int unused = 0;
        if (kObj)
        {
            if (::FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f9140)), (::NiAVObject *)(::NiNode *)((NiNode*)kObj)))
            {
                LoadedObject* pLoadedObject = kObj;
                reinterpret_cast<::FUN_00b4dec0_shell *>((pLoadedObject))->FUN_00b4dec0(7);
            }
            reinterpret_cast<::FUN_00440460_S *>((kObj))->FUN_00440460((const ::V3 *)(void *)(&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO))));
            reinterpret_cast<::FUN_0043fa80_s *>((kObj))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&DAT_011a9448)));
            if (slots[slot].parent)
            {
                Attachment* attachment = slots[slot].parent->GetAttachment();
                if (attachment)
                    reinterpret_cast<::TESModelTextureSwap *>((attachment))->ApplyTextureSwaps((::NiAVObject *)(kObj));
            }
            if (slots[slot].form && slots[slot].form->IsReady())
                ::UpdateObjectVisibility((::NiAVObject *)(kObj));
            return kObj;
        }
    }
    return 0;
}

struct CloneContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float x;
    float y;
    float z;
    CloneContext(float);
    ~CloneContext();
};
struct ObjectOps : NiAVObject
{
};
struct TesOps
{
};

NiAVObject* FUN_004aae30(NiAVObject*, NiFixedString*);
// @fnv 0x004aeed0
NiAVObject* __cdecl FUN_004aeed0(TESForm* form, TESModel* model, int slot, TESObjectREFR* ref, NiAVObject* root)
{
    if (!model || !ref)
        return 0;
    const char* pathB = model->GetModelFilePath();
    if (!pathB || !*pathB)
        return 0;
    NiAVObject* target4 = root;
    if (!target4)
        target4 = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((ref))->FUN_0043fcd0()));
    if (!target4)
        return 0;
    NiAVObject* parent5 = target4;
    NiAVObject* loaded6 = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(pathB), 3, true, false, false, false);
    CloneContext context4(1.0f);
    NiPointer<NiAVObject> copy3(0);
    NiAVObject* selected3;
    if (FUN_004b5bf0(loaded6))
    {
        copy3 = reinterpret_cast<::FUN_00457ba0_class *>((((TesOps*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00457ba0(loaded6, (::CloningProcess *)&(context4));
        selected3 = copy3;
    }
    else
        selected3 = ((::NiAVObject *)(reinterpret_cast<::A5D2C0Object *>((((ObjectOps*)loaded6)))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(context4))));
    NiAVObject* result5 = selected3;
    bool skinned2 = false;
    TESModelTextureSwap* swapTmp = model->GetAsModelTextureSwap();
    if (swapTmp)
        swapTmp->ApplyTextureSwaps(result5);
    if (form && form->Unk_2B())
        ::UpdateObjectVisibility(result5);
    ::BipedAnim::ApplyReferenceExtraData((::NiNode *)(loaded6), (::NiNode *)(result5), (::BIPED_OBJECT)(slot), ref);
    ::FUN_00578060((::NodeView *)(result5));
    NiPointer<NiExtraData> extra(result5->GetExtraData(FUN_004ab220()));
    reinterpret_cast<::FUN_00a5bfa0_shell *>((((ObjectOps*)result5)))->ClearExtraData();
    if (extra)
    {
        reinterpret_cast<::Holder *>((result5))->FUN_00a5bc40(FUN_004ab220(), (::NiTexture *)(::NiExtraData *)(extra));
        extra = 0;
    }
    if (result5)
    {
        if (::FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f9140)), result5))
        {
            NiAVObject* fade = result5;
            reinterpret_cast<::FUN_00b4dec0_shell *>((((ObjectOps*)fade)))->FUN_00b4dec0(7);
        }
        reinterpret_cast<::FUN_00440460_S *>((result5))->FUN_00440460((const ::V3 *)&(NiPoint3::ZERO));
        reinterpret_cast<::FUN_0043fa80_s *>((result5))->FUN_0043fa80(DAT_011a9448);
        if (::FUN_004910d0((::NiAVObject *)(::NiNode *)((NiNode*)result5)))
            skinned2 = true;
        if (skinned2)
            ::FUN_005b5e40();
        else
            ::BipedAnim::AttachFaceGenNode((::NiNode *)(parent5), (::NiNode *)(result5), (::NiNode *)(loaded6), (::BipedAnim *)(0), (::BIPED_OBJECT)(slot), (::BSFaceGenModel *)(0));
        if (!skinned2 && result5->IsSceneNode())
        {
            int count9 = reinterpret_cast<::FUN_009611e0_shell *>((((ObjectOps*)result5)))->FUN_009611e0();
            NiAVObject* attach7 = 0;
            if (!count9)
            {
                if (slot != -1 && DAT_01188be8[slot] != -1)
                {
                    NiAVObject* found5 = FUN_004aae30(parent5, (NiFixedString*)DAT_01188b74[DAT_01188be8[slot]]);
                    attach7 = found5;
                }
                if (attach7)
                    ((NiNode*)attach7)->AddObject(result5, true);
                else
                    ((NiNode*)parent5)->AddObject(result5, true);
            }
        }
        reinterpret_cast<::FUN_00a5a040_Class *>((((ObjectOps*)result5)))->FUN_00a5a040();
    }
    return result5;
}

class BipedAnimHelper : public BipedAnim
{
  public:
    void ApplySkinTextures(NiAVObject* apObject, bool abArg2);
};
// @fnv 0x004ad4a0
NiAVObject* BipedAnim::AttachBipedModel(NiNode* model, NiNode* parent, BIPED_OBJECT slot, bool firstPerson, bool hair,
                                        BSFaceGenModel* faceModel)
{
    NiAVObject* pResult;
    {
        BipedSkinAttachment attachment;
        attachment.face = 0;
        pResult = 0;
        attachment.attachNode = parent;
        NiPointer<NiAVObject> spDataCopy(0);
        reinterpret_cast<::FUN_004add70_shell *>((model))->FUN_004add70();
        attachment.face = faceModel;
        if (!attachment.face && IsSlotHidden(slot))
            attachment.face = reinterpret_cast<::FaceLoader *>(this)->FUN_004ae790((*(int *)&(slot)));
        reinterpret_cast<::FUN_00440460_S *>((model))->FUN_00440460((const ::V3 *)&(NiPoint3::ZERO));
        if (parent && model->FUN_0043b480() >= 2 && model->GetAt(1) && model->GetAt(1)->IsGeometry())
        {
            attachment.attachNode = new NiNode(0);
            parent->AddObject(attachment.attachNode, true);
            pResult = attachment.attachNode;
        }
        BipedSkinBoneMetadata metadata;
        metadata.extra = model->GetExtraData(FUN_004ab220());
        metadata.bones = metadata.extra;
        if (metadata.bones)
        {
            NiNode* boneNode = GetBoneNode(BIPED_BONE_WEAPON);
            if (boneNode)
                reinterpret_cast<::FUN_00a5be90_shell *>((boneNode))->DeleteExtraDataByKey(FUN_004ab220());
            reinterpret_cast<::Holder *>((boneNode))->FUN_00a5bc40(FUN_004ab220(), (::NiTexture *)(metadata.bones));
            for (unsigned int j = 0; j < model->FUN_0043b480(); ++j)
            {
                NiAVObject* child = model->GetAt(j);
                if (child->IsGeometry() && ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(child->IsGeometry())))))
                {
                    reinterpret_cast<::FUN_004700d0_class *>(&(metadata.bones->children))->FUN_004700d0((int *)&(const ::NiAVObject *const &)(model->GetAt(j)));
                }
            }
        }
        GlobalObject_004aff00 removed(0, 1);
        for (unsigned int i = 0; i < model->FUN_0043b480(); ++i)
        {
            BipedSkinnedChild skinned;
            skinned.child = model->GetAt(i);
            if (skinned.child && !skinned.child->IsGeometry())
            {
                ((BipedChildArray*)&removed)->Add(skinned.child);
                model->RemoveObject(skinned.child);
                continue;
            }
            if (firstPerson && BIPED_OBJECT_TEXT(skinned.child) &&
                !fnv::crt::strnicmp(BIPED_OBJECT_TEXT(skinned.child), DAT_01188b98[2], ::FUN_0044a670(DAT_01188b98[2])))
            {
                ((BipedChildArray*)&removed)->Add(skinned.child);
                model->RemoveObject(skinned.child);
                continue;
            }
            if (BIPED_OBJECT_TEXT(skinned.child))
            {
                BSStringT<char> name(BIPED_OBJECT_TEXT(skinned.child));
                ::FUN_004afad0((::BSStringT_layout *)&(name));
                char prefix[10];
                if (hair)
                {
                    FUN_004add50(prefix, name, 9);
                    prefix[9] = 0;
                    if (!FUN_00404dc0(prefix, "pipboyoff"))
                    {
                        ((BipedChildArray*)&removed)->Add(skinned.child);
                        model->RemoveObject(skinned.child);
                        continue;
                    }
                }
                else
                {
                    FUN_004add50(prefix, name, 8);
                    prefix[8] = 0;
                    if (!FUN_00404dc0(prefix, "pipboyon"))
                    {
                        ((BipedChildArray*)&removed)->Add(skinned.child);
                        model->RemoveObject(skinned.child);
                        continue;
                    }
                }
            }
            skinned.geom = (NiTriBasedGeom*)skinned.child;
            if (skinned.geom && ((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(skinned.geom)))) && ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skinned.geom)))) && attachment.face &&
                m_pActor && ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430())) && ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430()))->GetFormType() == FORM_NPC)
            {
                TESNPC* m_pActorBaseFormItem;
                m_pActorBaseFormItem = (TESNPC*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430()));
                FaceGenCoord coords[4];
                NiPointer<NiAVObject> copiedData(0);
                reinterpret_cast<::NiObjectD510 *>((((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(skinned.geom))))))->FUN_00a5d510((::NiPointerD510 &)(*(NiPointer<NiObject>*)&spDataCopy));
                copiedData = (NiAVObject*)spDataCopy;
                skinned.geom->ReplaceModelData((NiGeometryData*)(NiAVObject*)copiedData);
                if (((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skinned.geom)))) &&
                    ((NiSkinPartition*)((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((NiObjectNET*)((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skinned.geom)))))))))))
                {
                    reinterpret_cast<::NiObjectD510 *>((((NiSkinPartition*)((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((NiObjectNET*)((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skinned.geom))))))))))))->FUN_00a5d510((::NiPointerD510 &)(*(NiPointer<NiObject>*)&spDataCopy));
                    NiPointer<NiAVObject> partition((NiAVObject*)spDataCopy);
                    reinterpret_cast<::FUN_004adde0_shell *>((skinned.geom))->FUN_004adde0((::NiNode *)(::NiSkinInstance *)((NiSkinInstance*)((::NiObject *)(reinterpret_cast<::CloneSourceA5d6 *>((((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skinned.geom))))))->FUN_00a5d680()))));
                    ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skinned.geom))))->FUN_004addc0((NiSkinPartition*)(NiAVObject*)partition);
                }
                m_pActorBaseFormItem->GetFaceGenCoords((*(FaceGenMatrix<float> (*)(&)[2][2])&(coords)));
                if (((bool)(::FUN_0043faf0())))
                    reinterpret_cast<::FUN_0065a970_shell *>((attachment.face))->ApplyMorphs((::FaceGenCoordinate *)(FaceGenMatrix<float> (*)[4])(&coords), skinned.geom, false);
            }
            reinterpret_cast<::BipedAnimHelper *>(this)->ApplySkinTextures(skinned.geom, false);
            skinned.skin = ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(skinned.geom))));
            if (skinned.skin)
            {
                if (!pResult)
                    pResult = skinned.child;
                BipedSkinBoneBinding binding;
                binding.count = (unsigned int)((LowProcess*)((::NiSkinData *)(reinterpret_cast<::TESRegionDataMap *>((skinned.skin))->GetRegionMapName())))->GetActiveCombatTarget();
                binding.boneArray = (NiAVObject**)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((TimeGlobal*)skinned.skin)))->FUN_00825c00();
                for (unsigned int j = 0; j < binding.count; ++j)
                {
                    if (!BIPED_OBJECT_TEXT(binding.boneArray[j]))
                    {
                        Warning(
                            "MODELS: Bone %i for part '%s->%s' is unnamed.\r\nMake sure all the vertices are skinned to a named bone.",
                            j, ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((model))->FUN_009611e0())) ? BIPED_OBJECT_TEXT(model->GetParent()) : "NULL",
                            BIPED_OBJECT_TEXT(model));
                        continue;
                    }
                    binding.pBone = FUN_004ade00(root, BIPED_OBJECT_NAME(binding.boneArray[j]));
                    if (binding.pBone)
                        reinterpret_cast<::FUN_004adda0_shell *>((skinned.skin))->SetBone(j, binding.pBone);
                }
                if (attachment.attachNode)
                {
                    ((BGSQuestObjective*)skinned.skin)->SetOwner((TESQuest*)parent);
                    attachment.attachNode->AddObject(skinned.child, true);
                }
            }
        }
        reinterpret_cast<::FUN_004add70_shell *>((model))->FUN_004add70();
        return pResult;
    }
}

// Resolves the biped object's skin textures for the NPC and applies them to the shader property, warning if the race texture is missing.
// @fnv 0x004af490
void BipedAnimHelper::ApplySkinTextures(NiAVObject* apObject, bool abArg2)
{
    BSShaderPPLightingProperty* pLightingProp5 = FindLightingShaderProperty(apObject);
    if (!pLightingProp5)
        return;

    int bipedObject = GetBipedObjectFromShaderProperty(apObject, pLightingProp5);
    if (bipedObject == -1)
        return;

    FaceGenCoord coords3[4];

    TESNPC* pNPC = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430())));

    NiPointer<NiTexture> _ptrA(0);
    NiPointer<NiTexture> ptrB3(0);

    if (pNPC)
        pNPC->GetFaceGenCoords((*(FaceGenMatrix<float> (*)(&)[2][2])&(coords3)));

    bool bResultTmp = false;
    if (abArg2)
        bResultTmp = reinterpret_cast<::fnv_006149b0::RaceTexture *>((reinterpret_cast<::FUN_004ac110_shell *>((pNPC))->FUN_004ac110()))->ApplyBodyTexture((::fnv_006149b0::NiPointer< ::fnv_006149b0::NiSourceTexture> &)(_ptrA), (::fnv_006149b0::NiPointer< ::fnv_006149b0::NiTexture> &)(ptrB3), pNPC, (BIPED_OBJECT)bipedObject, true);
    else
        bResultTmp = reinterpret_cast<::fnv_006149b0::RaceTexture *>((reinterpret_cast<::FUN_004ac110_shell *>((pNPC))->FUN_004ac110()))->ApplyBodyTexture((::fnv_006149b0::NiPointer< ::fnv_006149b0::NiSourceTexture> &)(_ptrA), (::fnv_006149b0::NiPointer< ::fnv_006149b0::NiTexture> &)(ptrB3), pNPC, (BIPED_OBJECT)bipedObject, false);

    if (pNPC && !bResultTmp)
    {
        ::FUN_005b5e40();
    }
    else
    {
        pLightingProp5->SetTexture(0, _ptrA);

        NiSourceTexture* pSourceTex = (NiSourceTexture*)((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f444c)), (::NiObject *)(::NiProperty *)((NiProperty*)(NiTexture*)_ptrA))));
        const char* pFilename = 0;
        bool bUnknown9 = true;
        if (pSourceTex)
        {
            bUnknown9 = !reinterpret_cast<::FUN_004af860_shell *>((pSourceTex))->FUN_004af860();
            reinterpret_cast<::FUN_004af880_shell *>((pSourceTex))->FUN_004af880();
            pFilename = (*(const ::NiFixedString *)(::FUN_006a9540((char *)(pSourceTex))));
        }

        char buffer[260];
        ::BSShaderManager::BuildTexturePath(buffer, pFilename, "_n", true);
        if (buffer[0])
        {
            NiPointer<NiTexture> normalTexX(0);
            ::BSShaderManager::GetTexture(buffer, bUnknown9, normalTexX, true, false);
            if (normalTexX)
                pLightingProp5->SetNormalTexture(0, normalTexX);
        }

        pLightingProp5->SetTexture(1, ptrB3);
        pLightingProp5->SetNormalTexture(1, FUN_004af8a0());
        pLightingProp5->SetFlag(10, true);
    }
}

namespace fnv_004ad050 {
struct NiObjectCopyInfo
{
    int unk00, unk04, unk08, unk0c;
    NiObjectCopyInfo(unsigned int);
    ~NiObjectCopyInfo();
};
struct BaseS
{
    BaseS();
};
struct FUN_004ad240_c
{
};
struct FUN_004ad050 : NiObjectCopyInfo
{
    BaseS m10;
    FUN_004ad050(float f);
};
// Constructs a NiObjectCopyInfo with type 257 and sets its scale to f.
// @fnv 0x004ad050
FUN_004ad050::FUN_004ad050(float afScale) : NiObjectCopyInfo(257)
{
    reinterpret_cast<::FUN_004ad240_c *>((((FUN_004ad240_c*)this)))->SetScale(afScale);
}
}  // namespace fnv_004ad050

struct BipedLoadAccess : BipedAnim
{
    void UpdateBipedObjects(bool);
};
struct ActorLoadAccess : Actor
{
};
struct PlayerLoadAccess : PlayerCharacter
{
};
struct ItemLoadAccess : InventoryStackRecord
{
    bool FUN_004bd8d0(unsigned char, float&);
};
struct WeapLoadAccess : TESObjectWEAP
{
};

struct DataLoadAccess : NiGeometryData
{
};
struct CloneLoadAccess : NiNode
{
};
struct MatrixLoadAccess
{
    float entry[3][3];
    MatrixLoadAccess();
    void FUN_0043f850(float);
    MatrixLoadAccess operator*(const ThreeByThreeMatrix&) const;
};
struct TESLoadAccess : TES
{
};
struct ExtraLoadAccess : ExtraDataList
{
};
struct RefrLoadAccess : TESObjectREFR
{
};
struct NodeLoadAccess : NiNode
{
};
// Rebuilds the biped's 20 equipment slots by loading or reusing NIF models, applying textures and face-gen morphs, and attaching them to the actor's skeleton.
// @fnv 0x004ac1e0
void BipedLoadAccess::UpdateBipedObjects(bool force)
{
    bool hasHead = false;
    bool first = object[6].pParent;
    if (m_pActor == ::_g_thePlayer && reinterpret_cast<::FUN_00950b30_Class *>((::_g_thePlayer))->FUN_00950b30(this))
        hasHead = true;
    if (DAT_011c5cb4)
        ::FUN_006570e0((::QueryObject *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430()))));
    for (int slot = 0; slot < 20; slot++)
    {
        if (object[slot].m_pModel && object[slot].m_pModel == m_kPreviousObjects[slot].m_pModel &&
            object[slot].pParent == m_kPreviousObjects[slot].pParent && m_kPreviousObjects[slot].m_pSceneObject)
        {
            bool reload = false;
            object[slot] = m_kPreviousObjects[slot];
            memset(&m_kPreviousObjects[slot], 0, sizeof(BipedAnimObject));
            if (DAT_011c5cb4 && object[slot].m_pSceneObject)
            {
                NiNode* existing = object[slot].m_pSceneObject->IsSceneNode();
                if (existing)
                {
                    for (unsigned int child = 0; child < existing->FUN_0043b480(); child++)
                        reinterpret_cast<::BipedAnimHelper *>(this)->ApplySkinTextures(existing->GetAt(child), false);
                }
                else
                    reinterpret_cast<::BipedAnimHelper *>(this)->ApplySkinTextures(object[slot].m_pSceneObject, false);
            }
            if (slot == 7 && object[5].pParent && ((FUN_004ab730_shell*)object[5].pParent)->IsFlagSet() &&
                object[slot].m_pSceneObject)
                reinterpret_cast<::TaskQueueInterface *>((object[slot].m_pSceneObject))->QueueActorDisarm(true);
            if (!reload)
                continue;
        }
        else
        {
            if (m_kPreviousObjects[slot].m_pSceneObject)
                ClearBipedObject(&m_kPreviousObjects[slot], true, 0);
            else
                memset(&m_kPreviousObjects[slot], 0, sizeof(BipedAnimObject));
        }
        bool mods = false;
        unsigned char modScope = 0;
        if (slot == 5 && object[slot].pParent)
        {
            if (m_pActor == ::_g_thePlayer)
            {
                TESObjectWEAP* weapon = (TESObjectWEAP*)object[slot].pParent;
                ItemLoadAccess* pWeaponInfo = (ItemLoadAccess*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((::_g_thePlayer))->GetBaseTexture()))->GetWeaponInfo();
                modScope = reinterpret_cast<::FUN_004bd820_stand *>((pWeaponInfo))->FUN_004bd820();
                float info = 0.0f;
                mods = pWeaponInfo->FUN_004bd8d0(14, info);
                reinterpret_cast<::FUN_004ab750_shell *>(this)->FUN_004ab750(weapon, modScope);
                if (reinterpret_cast<::FUN_004ad010_shell *>((weapon))->IsFlag4Set() && this == ((::BipedAnim *)(reinterpret_cast<::PlayerCharacter *>((((PlayerLoadAccess*)::_g_thePlayer)))->FUN_00950b00(false))))
                {
                    if (!reinterpret_cast<::FUN_004ad030_shell *>((((WeapLoadAccess*)weapon)))->GetFlag() || mods)
                        ::FUN_00709c20((int)(((::TESModel *)(reinterpret_cast<::FUN_00504e60_shell *>((weapon))->FUN_00504e60()))));
                }
            }
            else
                reinterpret_cast<::fnv_00571760::Actor *>((((ActorLoadAccess*)m_pActor)))->FUN_00571760((::fnv_00571760::TESObjectWEAP *)(::TESObjectWEAP *)((TESObjectWEAP*)object[slot].pParent));
            continue;
        }
        if (object[slot].m_pModel && object[slot].m_pModel != (TESModel*)-1)
        {
            if (hasHead)
            {
                switch (slot)
                {
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    break;
                default:
                    continue;
                }
            }
            if (!force && IsSlotHidden((BIPED_OBJECT)slot) && m_pActor != ::_g_thePlayer && (*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011c5ef0)).Bool()->b &&
                ((bool)(::FUN_0043faf0())) && ::BipedAnim::CanLoadHiddenBipedObjects())
            {
                reinterpret_cast<::C4AEDE0Queue *>(this)->QueueItem((*(int *)&(const ::IO_TASK_PRIORITY &)(TASK_DEFAULT)), (int)(0), (*(int *)&(const ::BIPED_OBJECT &)((BIPED_OBJECT)slot)));
                continue;
            }
            if (!object[slot].m_pModel->GetModelLength())
                continue;
            int node = DAT_01188be8[slot];
            NiAVObject* result;
            NiNode* _clone = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(object[slot].m_pModel->GetModelFilePath()), 3, true, false,
                                                     IsSlotHidden((BIPED_OBJECT)slot), false);
            CloningProcess boneIndex(1.0f);
            NiPointer<NiNode> copy(0);
            NiObject* model;
            if (FUN_004b5bf0(_clone))
            {
                copy = ((::NiNode *)(reinterpret_cast<::FUN_00457ba0_class *>((((TESLoadAccess*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00457ba0((::NiAVObject *)(_clone), (::CloningProcess *)&(boneIndex))));
                model = copy;
            }
            else
                model = ((::NiObject *)(reinterpret_cast<::A5D2C0Object *>((((CloneLoadAccess*)_clone)))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(boneIndex))));
            NiNode* boneIndexd = model->IsSceneNode();
            result = 0;
            if (boneIndexd)
            {
                TESModelTextureSwap* fade = object[slot].m_pModel ? object[slot].m_pModel->GetAsModelTextureSwap() : 0;
                if (fade)
                    fade->ApplyTextureSwaps(boneIndexd);
                if (object[slot].pParent && object[slot].pParent->Unk_2B())
                    ::UpdateObjectVisibility((::NiAVObject *)(boneIndexd));
                BSFadeNode* swap = boneIndexd->IsFadeNode();
                if (swap)
                    reinterpret_cast<::FUN_00b4dec0_shell *>((((NodeLoadAccess*)swap)))->FUN_00b4dec0(7);
                reinterpret_cast<::FUN_00440460_S *>((boneIndexd))->FUN_00440460((const ::V3 *)&(NiPoint3::ZERO));
                reinterpret_cast<::FUN_0043fa80_s *>((boneIndexd))->FUN_0043fa80(DAT_011a9448);
                result = PrepareBipedModel(boneIndexd, (BIPED_OBJECT)slot, hasHead, first, 0);
                if (!result)
                {
                    result = boneIndexd;
                    if (this && IsSlotHidden((BIPED_OBJECT)slot))
                    {
                        BSFaceGenModel* face = reinterpret_cast<::FaceLoader *>(this)->FUN_004ae790((*(int *)&(const ::BIPED_OBJECT &)((BIPED_OBJECT)slot)));
                        if (face)
                        {
                            for (unsigned int index = 0; index < boneIndexd->FUN_0043b480(); index++)
                            {
                                NiAVObject* childNode = boneIndexd->GetAt(index);
                                NiTriBasedGeom* geometry = childNode->IsTriBasedGeom();
                                if (childNode && !geometry)
                                    ::FUN_005b5e40();
                                if (geometry && ((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry)))) && m_pActor &&
                                    ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430())) &&
                                    ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430()))->GetFormType() == FORM_NPC)
                                {
                                    TESNPC* newData = (TESNPC*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pActor))->FUN_007af430()));
                                    FaceGenCoord coords[4];
                                    NiPointer<NiGeometryData> data(0);
                                    NiPointer<NiGeometryData> npc(0);
                                    reinterpret_cast<::NiObjectD510 *>((((DataLoadAccess*)((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry)))))))->FUN_00a5d510((::NiPointerD510 &)(data));
                                    npc = (NiGeometryData*)data;
                                    geometry->ReplaceModelData(npc);
                                    newData->GetFaceGenCoords((*(FaceGenMatrix<float> (*)(&)[2][2])&(coords)));
                                    if (!((bool)(::FUN_0043faf0())) || reinterpret_cast<::FUN_0065a970_shell *>((face))->ApplyMorphs((::FaceGenCoordinate *)(FaceGenMatrix<float> (*)[4])(&coords), geometry, false))
                                    {
                                        ThreeByThreeMatrix rotation;
                                        rotation.SetYRotation(-1.57079637f);
                                        reinterpret_cast<::FUN_0043fa80_s *>((geometry))->FUN_0043fa80(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(const ::ThreeByThreeMatrix &)((*(::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(geometry))))))->operator+(rotation));
                                    }
                                }
                            }
                        }
                    }
                    AttachFaceGenNode(root, boneIndexd, 0, this, (BIPED_OBJECT)slot, 0);
                    if (!reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition() && slot == 5)
                    {
                        ActorLoadAccess* actor = (ActorLoadAccess*)m_pActor;
                        if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())))
                        {
                            if (m_pActor == ::_g_thePlayer && this == ((::BipedAnim *)(reinterpret_cast<::PlayerCharacter *>((((PlayerLoadAccess*)::_g_thePlayer)))->FUN_00950b00(true))))
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->UpdateWeaponDrawn(reinterpret_cast<::FUN_008a16d0_shell *>((actor))->FUN_008a16d0(), this,
                                                                       ::_g_thePlayer->GetAnimation(true), actor);
                            else
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->UpdateWeaponDrawn(reinterpret_cast<::FUN_008a16d0_shell *>((actor))->FUN_008a16d0(), this,
                                                                       reinterpret_cast<::FUN_008b70d0_shell *>((actor))->FUN_008b70d0(), actor);
                        }
                    }
                }
            }
            if (result)
            {
                BSStringT<char> name;
                ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&name), "%s %s (%08X)", DAT_01188b98[slot], object[slot].pParent->GetEditorID(),
                             ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((object[slot].pParent))->FUN_0084e3a0())));
                ::AssignFixedString((char *)(result), (int)&(const ::NiFixedString &)(NiFixedString(name)), {});
                ::BipedAnim::ApplyReferenceExtraData(_clone, boneIndexd, (BIPED_OBJECT)slot, m_pActor);
                if (!object[slot].bHasAnimation && result->IsSceneNode())
                {
                    NiNode* parent = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((result))->FUN_009611e0()));
                    if (node == -1)
                    {
                        ::FUN_005b5e40();
                        if (parent)
                            parent->RemoveObject(result);
                        else
                        {
                            NiPointer<NiAVObject> release(result);
                        }
                        result = 0;
                    }
                    else
                    {
                        if (bone[node].pParent)
                            bone[node].pParent->AddObject(result, true);
                        else if (((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((result))->FUN_009611e0())))
                            root->AddObject(result, true);
                    }
                }
                ExtraDismemberedLimbs* limbs = reinterpret_cast<::ExtraDataList *>((((::ExtraLoadAccess *)(reinterpret_cast<::FUN_005d43c0_ *>((((RefrLoadAccess*)m_pActor)))->FUN_005d43c0()))))->GetDismemberedLimbs();
                if (limbs)
                {
                    for (int limb = 0; limb < 15; limb++)
                        if (reinterpret_cast<::FUN_004303e0_Class *>((limbs))->IsBitSet(limb))
                            ::AddNodeEntries(limb, (::PartNode *)(result));
                }
                if (slot == 7 && object[5].pParent && ((FUN_004ab730_shell*)object[5].pParent)->IsFlagSet() && result)
                    reinterpret_cast<::TaskQueueInterface *>((result))->QueueActorDisarm(true);
                object[slot].m_pSceneObject = result;
            }
        }
    }
    reinterpret_cast<::FUN_00a5a040_Class *>((((CloneLoadAccess*)((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((m_pActor))->FUN_0043fcd0())))))->FUN_00a5a040();
}

#include "generated/data/fallout_shared/bipedanim.inc"
