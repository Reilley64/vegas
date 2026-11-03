// fallout_shared/globalfunc.cpp: BipedNodeNames, NiAVObject, ActorMover, PathingGraphNode and more (110 functions)

#include <cstdint>
#include <new>
#include <cmath>
#include "runtime/crt.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Cl537.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00448a60_struct.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_00495f30_shell.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a8030_shell.h"
#include "fnv/decl/FUN_004b9b20_class.h"
#include "fnv/decl/FUN_0056e900_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ba8ab0_shell.h"
#include "fnv/decl/FUN_00c86720.h"
#include "fnv/decl/FUN_00c86cb0.h"
#include "fnv/decl/FUN_00c877b0.h"
#include "fnv/decl/FUN_00c87970.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/HashTableBase.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/MouseSpringOwner.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SearchObject.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0098ddd0__FUN_0098ddd0_shell.h"
#include "fnv/decl/fnv_00b675c0__FUN_00b675c0_shell.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_004a2000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b4000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00824000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "globalfunc_decls.h"
#include <cstddef>
#include "fnv/decl/FUN_00c86d20_Class.h"
#include "fnv/decl/FUN_00cbb1b0_Class.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/Wrapper86b80.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01272000.h"
#include <xmmintrin.h>
#include <windows.h>
#include <cstring>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/BC87850RefObject.h"
#include "fnv/decl/BSRenderStateManager.h"
#include "fnv/decl/CC68B50Stack.h"
#include "fnv/decl/E7DE90Owner.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00ba87d0_Class.h"
#include "fnv/decl/FUN_00c67850_Class.h"
#include "fnv/decl/FUN_00c87600_Obj.h"
#include "fnv/decl/FUN_00c87650_t.h"
#include "fnv/decl/FUN_00c87670_Class.h"
#include "fnv/decl/FUN_00c879e0_Class.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/ProjectileListener.h"
#include "fnv/decl/S004b4db0_Quaternion.h"
#include "fnv/decl/S69580_World.h"
#include "fnv/decl/S_Owner.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/StageSet.h"
#include "fnv/decl/StateGroup.h"
#include "fnv/decl/This676.h"
#include "fnv/decl/XRenderer.h"
#include "fnv/decl/fnv_00c6aac0__FUN_00c6aac0_Owner.h"
#include "fnv/decl/fnv_00c87de0__bhkRefObject_Class.h"
#include "fnv/decl/hkpWorldC97.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00b97000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00cdd000.h"
#include "fnv/symbols_00e7e000.h"
#include "fnv/symbols_00ead000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S_00c6d840.h"
#include "fnv/decl/World6b3c0.h"
#include "fnv/decl/bhkUnaryActionS.h"
#include "fnv/decl/fnv_00524c40__TransHolder.h"
#include "fnv/symbols_00ba5000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c86000.h"

// @fnv 0x004b7920
void BipedNodeNames::InitializeMultiBounds()
{
    DAT_011c61a4 = new NiFixedString("Bip01");
    DAT_011c61a8 = new NiFixedString("Bip");
    DAT_011c61ac = new NiFixedString("Bip01 Head");
    DAT_011c61b0 = new NiFixedString("Bip01 Neck");
    DAT_011c61b4 = new NiFixedString("Bip01 Spine");
    DAT_011c61b8 = new NiFixedString("Bip01 Spine1");
    DAT_011c61bc = new NiFixedString("magicNode");
    DAT_011c61c0 = new NiFixedString("SpecialIdle_Cast");
    DAT_011c61c4 = new NiFixedString("SpecialIdle_AreaEffect");
    DAT_011c61c8 = new NiFixedString("AttachSound");
    DAT_011c61cc = new NiFixedString("Sound Marker");
    DAT_011c61d0 = new NiFixedString("Skinned Decal Node");
    DAT_011c61d4 = new NiFixedString("Decal Node");
    DAT_011c61d8 = new NiFixedString("ModelSwapNode");
    DAT_011c61dc = new NiFixedString("Open");
    DAT_011c61e0 = new NiFixedString("Close");
    DAT_011c61e4 = new NiFixedString("DVPG");
    DAT_011c61e8 = new NiFixedString("Prn");
    DAT_011c61ec = new NiFixedString("Weapon");
    DAT_011c61f0 = new NiFixedString("EditorMarker");
    DAT_011c61f4 = new NiFixedString("EditorMarker:0");
    DAT_011c61f8 = new NiFixedString("EditorMarker:1");
    DAT_011c61fc = new NiFixedString("EditorMarker:2");
    (*reinterpret_cast<::NiFixedString * *>(&::DAT_011c6200)) = new NiFixedString("ArrowQuiver");
    DAT_011c6204 = new NiFixedString("MarkerSource");
    DAT_011c6208 = new NiFixedString("MarkerTarget");
    DAT_011c620c = new NiFixedString("AttachLight");
    DAT_011c6210 = new NiFixedString("skin");
    DAT_011c6214 = new NiFixedString("FaceGenEars");
    DAT_011c6218 = new NiFixedString("Unequip");
    DAT_011c621c = new NiFixedString("LaserSight");
    DAT_011c6220 = new NiFixedString("AimSight");
    DAT_011c6224 = new NiFixedString("Grass");
    DAT_011c6228 = new NiFixedString("Decal");
    DAT_011c622c = new NiFixedString("Permanent Decal");
    DAT_011c6230 = new NiFixedString("grabLeft");
    DAT_011c6234 = new NiFixedString("grabRight");
    DAT_011c6238 = new NiFixedString("Arrow:0");
    DAT_011c623c = new NiFixedString("ArrowBone");
    DAT_011c6240 = new NiFixedString("BSFaceGenNiNodeBiped");
    DAT_011c6244 = new NiFixedString("BSFaceGenNiNodeSkinned");
    DAT_011c6248 = new NiFixedString("HeadAnims:0");
    DAT_011c624c = new NiFixedString("EntryPoint");
    DAT_011c6250 = new NiFixedString("Bip01 L UpperArm");
    DAT_011c6254 = new NiFixedString("Bip01 L Forearm");
    DAT_011c6258 = new NiFixedString("Bip01 R UpperArm");
    DAT_011c625c = new NiFixedString("Bip01 Yaw");
    DAT_011c6260 = new NiFixedString("Bip01 Pitch");
    DAT_011c6264 = new NiFixedString("Bip01 Looking");
    DAT_011c6268 = new NiFixedString("Talking");
    DAT_011c626c = new NiFixedString("Camera1st");
    DAT_011c6270 = new NiFixedString("Camera3rd");
    DAT_011c6274 = new NiFixedString("HeadMeshForExport_FaceGenAndMorphs:0");
    DAT_011c6278 = new NiFixedString("PinnedLimb");
}

// @fnv 0x004b7240
bool ConvertLocalizedString(const char* input, char* output, unsigned int capacity)
{
    if (!input || !output || !capacity)
        return false;
    const char* current;
    bool changed = false;
    output[0] = 0;
    unsigned int written = 0;
    int targetPlatform = FUN_004b71a0();
    LANGUAGE language = GetConfiguredLanguage();
    current = input;
    for (int i = 0; i < 4; ++i)
    {
        char separator = 0;
        const char* found = ::FUN_004b75a0(current, DAT_01189038[i]);
        while (found)
        {
            unsigned int tagLength = ::FUN_0044a670(DAT_01189038[i]);
            if (found[tagLength] == '\\' || found[tagLength] == '/')
            {
                separator = found[tagLength];
                break;
            }
            else
                found = ::FUN_004b75a0(found + tagLength, DAT_01189038[i]);
        }
        if (found)
        {
            unsigned int prefix = found - current;
            if (prefix)
            {
                memcpy_s(output + written, capacity - written, current, prefix);
                written += prefix;
                output[written] = 0;
            }
            strcat_s(output, capacity, DAT_01189038[targetPlatform]);
            written += strlen(DAT_01189038[targetPlatform]);
            output[written] = separator;
            ++written;
            output[written] = 0;
            found += strlen(DAT_01189038[i]);
            ++found;
            current = found;
            changed = true;
            break;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        char separator = 0;
        const char* found = ::FUN_004b75a0(current, DAT_01188f84[i]);
        while (found)
        {
            unsigned int tagLength = ::FUN_0044a670(DAT_01188f84[i]);
            if (found[tagLength] == '\\' || found[tagLength] == '/')
            {
                separator = found[tagLength];
                break;
            }
            else
                found = ::FUN_004b75a0(found + tagLength, DAT_01188f84[i]);
        }
        if (found)
        {
            unsigned int prefix = found - current;
            if (prefix)
            {
                memcpy_s(output + written, capacity - written, current, prefix);
                written += prefix;
                output[written] = 0;
            }
            strcat_s(output, capacity, DAT_01188f84[language]);
            written += strlen(DAT_01188f84[language]);
            output[written] = separator;
            ++written;
            output[written] = 0;
            found += strlen(DAT_01188f84[i]);
            ++found;
            current = found;
            changed = true;
            break;
        }
    }
    strcat_s(output, capacity, current);
    return changed;
}

// @fnv 0x004b7660
bool UpdateObjectVisibility(NiAVObject* object)
{
    bool changed = false;
    if (object)
    {
        NiProperty* property = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(3)));
        NiProperty* textures = (property == 0 ? 0
                                              : (((int)(reinterpret_cast<::BGSTerrainManager *>((reinterpret_cast<NiTimeController*>(property)))->GetMinLevel())) >= 8 &&
                                                 ((int)(reinterpret_cast<::BGSTerrainManager *>((reinterpret_cast<NiTimeController*>(property)))->GetMinLevel())) <= 12))
                                   ? property
                                   : 0;
        if (textures)
        {
            unsigned int count = textures->GetTextureCount();
            for (unsigned int i = 0; i < count; ++i)
            {
                for (int type = 0; type < 6; ++type)
                {
                    NiTexture* texture = textures->GetTexture(type, i);
                    if (texture && FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f444c)), reinterpret_cast<NiAVObject*>(texture)))
                    {
                        bool swapped;
                        NiTexture* source = texture;
                        NiFixedString path(source->GetPath());
                        {
                            char replacement[260];
                            replacement[0] = 0;
                            swapped = ConvertLocalizedString(
                                reinterpret_cast<const char*>(reinterpret_cast<BSFadeNode*>(&path)->FUN_0043b1b0()),
                                replacement, 260);
                            if (swapped && replacement[0])
                            {
                                NiPointer<NiTexture> newTexture(0);
                                reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_004568c0(replacement,
                                                          (::TexPtr< ::NiSourceTexture> &)(reinterpret_cast<NiPointer<NiSourceTexture>&>(newTexture)),
                                                          false, false);
                                if (newTexture)
                                {
                                    textures->SetTexture(type, i, static_cast<NiTexture*>(newTexture));
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        NiNode* node = object->GetAsNiNode();
        if (node)
        {
            unsigned int count = node->FUN_0043b480();
            for (unsigned int i = 0; i < count; ++i)
                if (UpdateObjectVisibility(node->GetAt(i)))
                    changed = true;
        }
    }
    return changed;
}

// @fnv 0x004b5d10
bool RemoveInvalidChildNodes(NiNode* apNode)
{
    bool removed = false;
    if (!apNode)
        return removed;
    if (!DAT_011c6328)
    {
        NiExtraData* pExtraData = apNode->GetExtraData(FUN_00448a80());
        if (pExtraData)
        {
            NiExtraData* flags = pExtraData;
            if (::FUN_004b5fa0((const ::BSXFlags *)(flags)))
            {
                DAT_011c6328 = apNode;
                NiTimeController* controller = ((::NiTimeController *)(reinterpret_cast<::MyHost *>((apNode))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac))))));
                {
                    NiControllerManager* controllerManager = reinterpret_cast<NiControllerManager*>(controller);
                    if (controllerManager)
                        DAT_011c6324 = ((::NiControllerManager *)(::fnv_00537bd0::GetStringAtOffset((const char *)(controllerManager))));
                }
            }
        }
    }
    if (!DAT_011c6328)
        return removed;
    if (reinterpret_cast<const char*>(
            reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(apNode)->GetLinkToList())
                ->FUN_0043b1b0()) &&
        !FUN_00404dc0(reinterpret_cast<const char*>(
                          reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(apNode)->GetLinkToList())
                              ->FUN_0043b1b0()),
                      "EditorMarker"))
    {
        if (DAT_011c6324)
        {
            DAT_011c6324->vfn_90(FUN_004b5f60(), 0);
            DAT_011c6324->vfn_90(FUN_004b5f70(), 0);
            DAT_011c6324->vfn_90(FUN_004b5f80(), 0);
            DAT_011c6324->vfn_90(FUN_004b5f90(), 0);
        }
        if (((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((apNode))->FUN_009611e0())))
            ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((apNode))->FUN_009611e0()))->RemoveObject(apNode);
        if (DAT_011c6328 == apNode)
        {
            DAT_011c6328 = 0;
            DAT_011c6324 = 0;
        }
        return true;
    }
    for (unsigned int i = 0; i < apNode->FUN_0043b480(); ++i)
    {
        NiAVObject* child = apNode->GetAt(i);
        if (child)
        {
            NiNode* node = child->GetAsNiNode();
            if (node)
            {
                removed = RemoveInvalidChildNodes(node);
                if (removed)
                {
                    if (DAT_011c6328 == apNode)
                    {
                        DAT_011c6328 = 0;
                        DAT_011c6324 = 0;
                    }
                    return removed;
                }
            }
        }
    }
    if (DAT_011c6328 == apNode)
    {
        DAT_011c6328 = 0;
        DAT_011c6324 = 0;
    }
    return removed;
}

// @fnv 0x004b5b20
bool HandleUnparentedObjectNode(NiNode* object)
{
    if (!object)
        return false;
    for (unsigned int i = 0; i < object->FUN_0043b480(); ++i)
    {
        NiAVObject* child = object->GetAt(i);
        if (child)
        {
            const char* name = reinterpret_cast<const char*>(
                reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(child)->GetLinkToList())
                    ->FUN_0043b1b0());
            if (name)
            {
                if (!FUN_00404dc0(name, "Scb"))
                {
                    object->RemoveNthObject(i);
                    return true;
                }
                else if (!fnv::crt::strnicmp(name, "FadeNode ", 9))
                    return HandleUnparentedObjectNode(child->GetAsNiNode());
            }
        }
    }
    return false;
}

// @fnv 0x004b6dc0
void SetObjectFormID(NiAVObject* object, unsigned int referenceID)
{
    if (!object)
        return;
    if (object->GetAsNiGeometry())
    {
        NiProperty* property = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(3)));
        NiProperty* lighting = ::FUN_004a2c20((::BGSTerrainManager *)(property)) ? property : 0;
        if (lighting)
            reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>((reinterpret_cast<EffectSetting*>(lighting)))->FUN_0057bd60((::fnv_0057bd60::MobileObject *)(::TESObjectLIGH *)(reinterpret_cast<TESObjectLIGH*>(referenceID)));
    }
    else
    {
        NiNode* node = object->GetAsNiNode();
        if (node)
            for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
                SetObjectFormID(node->GetAt(i), referenceID);
    }
}

// @fnv 0x004b5c80
bool IsObjectNetValid(NiObjectNET* object)
{
    if (!object)
        return false;
    if (FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_012024e0)), reinterpret_cast<NiAVObject*>(object)))
        return true;
    NiNode* node = object->GetAsNiNode();
    if (node)
        for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
        {
            NiAVObject* child = node->GetAt(i);
            if (IsObjectNetValid(child))
                return true;
        }
    return false;
}

// Computes an angle from vector.x and vector.y using logf of their ratio, adding pi when y is negative and using pi/2 or 3pi/2 when y is zero.
// @fnv 0x004b1550
float GetAngleFromVector(const NiPoint3& vector)
{
    float angle = 0.0f;
    if (vector.y != 0.0)
    {
        float ratio = vector.x / vector.y;
        angle = logf(ratio);
        if (vector.y < 0.0)
            angle += 3.1415927410125732;
    }
    else
    {
        if (vector.x > 0.0)
            angle = 1.5707963705062866f;
        else
            angle = 4.71238899230957f;
    }
    return angle;
}

// Traverses the NiAVObject tree with filter flags set from the skip arguments and returns the accumulated collision object count.
// @fnv 0x004b66d0
int CountCollisionObjects(NiAVObject* object, bool skipPhantoms, bool skipBlendObjects, bool skipUnknown)
{
    CollisionObjectCountContext context;
    context.uiTraversalFlags = 0x12;
    context.bRecurse = true;
    context.iCount = 0;
    context.uiFilterFlags = 0;
    if (skipPhantoms)
        context.uiFilterFlags |= 1;
    if (skipBlendObjects)
        context.uiFilterFlags |= 2;
    if (skipUnknown)
        context.uiFilterFlags |= 4;
    ::FUN_00c68900((::S_00c68900_Node *)(object), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(&context), (void (*)(void *, S_00c68900_Context *))(((void (&)(NiCollisionObject *, CollisionObjectCountContext *))::FUN_004b6740)));
    return context.iCount;
}

// Returns true when m_spWorldBound is set and its FUN_0084d030 result is non-zero.
// @fnv 0x004b2960
int NiAVObject::IsVisualObject()
{
    return m_spWorldBound && reinterpret_cast<::Twin_0084d030 *>((m_spWorldBound))->GetStoredFloatValue() != 0.0;
}

// If a look-at target exists, copies the stored look-at point into point and returns true; otherwise returns false.
// @fnv 0x009de270
bool ActorMover::GetLookAtTargetPosition(NiPoint3& point)
{
    if (HasLookAtTarget())
    {
        point = m_kLookAtTargetPosition;
        return true;
    }
    return false;
}

// @fnv 0x006ca0c0
bool PathingGraphNode::IsTransitionNode()
{
    return (iFlags & 4) == 4;
}

// @fnv 0x004b7220
LANGUAGE GetConfiguredLanguage()
{
    LANGUAGE language = static_cast<LANGUAGE>(BSSysInfoSystemUtility::GetRandomGenerator());
    return language;
}

// @fnv 0x00430830
RecipeCraftingInfo* TESRecipe::GetData()
{
    return &data;
}

// @fnv 0x00605d20
bool IsSettingEnabled()
{
    return (*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011d5a30)).Bool()->b;
}

// @fnv 0x00888960
bool bhkWorld::QPickCountOverride()
{
    return DAT_012677a3;
}


// @fnv 0x004b1460
float FUN_004b1460(float _X)
{
    return static_cast<float>(std::atan(_X));
}


// @fnv 0x004b1520
float __cdecl FUN_004b1520(float _X, float _Y)
{
    return (float)std::fmod((double)_X, (double)_Y);
}

class NiPick
{
  public:
    bool PerformPick(const NiPoint3&, const NiPoint3&, bool);
public:
    void FUN_00705fc0(void *);
};

class FOPipboyManager
{
  public:
};


// @fnv 0x004b2780
bool __cdecl FUN_004b2780(NiPick* pPicker, intptr_t p2, intptr_t p3, float p4, intptr_t p5, bool p6)
{
    bool bResult = false;
    if (pPicker != 0 && p5 != 0 && p4 != 0.0)
    {
        if (p6)
        {
            reinterpret_cast<::NiPick *>((((FOPipboyManager*)pPicker)))->FUN_00705fc0(0);
            pPicker->PerformPick(::NiPoint3::ZERO, ::NiPoint3::ZERO, false);
        }
        bResult = ::fnv_004b2800::PickObjectsInRadius((::fnv_004b2800::NiPick *)(pPicker), (*(const ::NiPoint3 *)(p2)), (*(const ::NiPoint3 *)(p3)), p4, (::NiAVObject *)(p5));
    }
    return bResult;
}

// Maps value from the range [y1,y2] onto [x1,x2] by linear interpolation and returns the result.
// @fnv 0x004b3ab0
float LinearInterpolate(float x1, float x2, float y1, float y2, float value)
{
    return x1 + (value - y1) / (y2 - y1) * (x2 - x1);
}

struct FourByFourMatrix
{
    float _11;
    float _12;
    float _13;
    float _14;
    float _21;
    float _22;
    float _23;
    float _24;
    float _31;
    float _32;
    float _33;
    float _34;
    float _41;
    float _42;
    float _43;
    float _44;
};
struct SwizzledMatrix : public FourByFourMatrix
{
    void SetUnswizzled(float*, float*, float);
    void SetUnswizzled(float*);
    void SwizzleFrom(void*);
    void SwizzleFrom4X3(void*);
    void SwizzleTo(SwizzledMatrix*);
    void SwizzleTo4X3(SwizzledMatrix*);
    void SwizzleTo4X4(SwizzledMatrix*);
    void TransposeTo(SwizzledMatrix*);
    void Set(void*);
};
struct FourComponentNumericValue
{
    char u[16];
};
struct FUN_004b4500_shell : public SwizzledMatrix
{
    void FUN_004b4500(SwizzledMatrix*);
};

struct NiPoint3b : public NiPoint3
{
    NiPoint3b(float, float, float);
};
struct M_004b4500 : public SwizzledMatrix
{
    NiPoint3b FUN_004b4500(const NiPoint3* v);
};
// Multiplies the 3x3 part of this matrix by vector v and returns the resulting NiPoint3.
// @fnv 0x004b4500
NiPoint3b M_004b4500::FUN_004b4500(const NiPoint3* apVector)
{
    return NiPoint3b(reinterpret_cast<float*>(this)[0] * reinterpret_cast<const float*>(apVector)[0] +
                         this->_12 * (*reinterpret_cast<const float*>((void *)&apVector->y)) +
                         this->_13 * (*reinterpret_cast<const float*>((void *)&apVector->z)),
                     this->_14 * reinterpret_cast<const float*>(apVector)[0] +
                         this->_21 * (*reinterpret_cast<const float*>((void *)&apVector->y)) +
                         this->_22 * (*reinterpret_cast<const float*>((void *)&apVector->z)),
                     this->_23 * reinterpret_cast<const float*>(apVector)[0] +
                         this->_24 * (*reinterpret_cast<const float*>((void *)&apVector->y)) +
                         this->_31 * (*reinterpret_cast<const float*>((void *)&apVector->z)));
}

struct NiFrustumPlanes
{
    void Set(void*, void*);
    void Set(void*);
    void* GetPlane(unsigned int);
    void SetWaterColorParameter(unsigned int, void*);
    bool IsPlaneActive(unsigned int);
    bool IsAnyPlaneActive();
    bool AreAllPlanesActive();
    void EnablePlane(unsigned int);
    void DisablePlane(unsigned int);
    void EnableAllPlanes();
    void DisableAllPlanes();
    unsigned int GetActivePlaneState();
    void SetActivePlaneState(unsigned int);
    char m_akPlanes[96];
    unsigned int m_uiActivePlaneMask;
};
struct FUN_004b4cf0_shell : public NiFrustumPlanes
{
    void* FUN_004b4cf0(unsigned int);
};

// @fnv 0x004b4cf0
void* FUN_004b4cf0_shell::FUN_004b4cf0(unsigned int ePlane)
{
    return reinterpret_cast<char*>(this) + (ePlane * 16);
}

struct hkQuaternion;
struct hkVector4;
struct FourDimensionalVector
{
    hkQuaternion* ToHK(hkQuaternion*);
    hkVector4* ToHK(hkVector4*);
    void set(float, float, float, float);
    void setZero4();
    void setAll3(float);
    void mul4(float);
    FourDimensionalVector* NI2HKNS(void*);
    FourDimensionalVector* FromHK(void*);
    float fX;
    float fY;
    float fZ;
    float fW;
};
struct FUN_004b4e50_shell : public FourDimensionalVector
{
    FourDimensionalVector* SetFromScaledVector3(void*);
};

extern float runtimeInitializationFloat2127;

// @fnv 0x004b4e50
FourDimensionalVector* FUN_004b4e50_shell::SetFromScaledVector3(void* arSrc)
{
    fX = runtimeInitializationFloat2127 * ((const float*)arSrc)[0];
    fY = runtimeInitializationFloat2127 * ((const float*)arSrc)[1];
    fZ = runtimeInitializationFloat2127 * ((const float*)arSrc)[2];
    fW = 0.0f;
    return this;
}

template <class T> class BSSimpleList;
class BGSRagdoll;

class TESDataHandler
{
  public:
};

int FUN_004b4f20(void* pThis);

// @fnv 0x004b4f00
int FUN_004b4f00(TESDataHandler* apDataHandler)
{
    return FUN_004b4f20(((::BSSimpleList< ::BGSRagdoll *> *)(reinterpret_cast<::FUN_009d9f40_Class *>((apDataHandler))->FUN_009d9f40())));
}

namespace fnv_004b4ff0 {
struct hkQuaternion;
struct hkVector4;
struct FourDimensionalVector
{
    hkQuaternion* ToHK(hkQuaternion*);
    hkVector4* ToHK(hkVector4*);
    void set(float, float, float, float);
    void setZero4();
    void setAll3(float);
    void mul4(float);
    FourDimensionalVector* NI2HKNS(void*);
    FourDimensionalVector* FromHK(void*);
    float fX;
    float fY;
    float fZ;
    float fW;
};
struct FUN_004b4ff0_shell : public FourDimensionalVector
{
    void FUN_004b4ff0(float, float, float, float);
};

// @fnv 0x004b4ff0
void FUN_004b4ff0_shell::FUN_004b4ff0(float afX, float afY, float afZ, float afW)
{
    fX = afX;
    fY = afY;
    fZ = afZ;
    fW = afW;
}
}  // namespace fnv_004b4ff0

struct PhysicsSimulationContext;
struct hkMatrix3;
struct hkMotionState;
struct hkMultiThreadCheck;
struct hkReferencedObject;
struct hkStatisticsCollector;
struct hkTransform;
struct hkVector4;
struct hkaiObjectData;
struct hkdBreakableBody;
struct hkpAction;
struct hkpBreakableBody;
struct hkpCollidable;
struct hkpConstraintInstance;
struct hkpContactListener;
struct hkpDynamicsContactMgr;
struct hkpEntity;
struct hkpEntityActivationListener;
struct hkpEntityListener;
struct hkpLinkedCollidable;
struct hkpMaterial;
struct hkpMaxSizeMotion;
struct hkpMotion;
struct hkpRigidBody;
struct WorldPhysicsSettings;
struct hkpSimulationIsland;
struct hkpWorld;
struct blob1
{
    char b[1];
};
struct blob8
{
    char b[8];
};

float FUN_004b4ea0(hkpRigidBody*);

// @fnv 0x004b5400
float FUN_004b5400(void* pThis)
{
    hkpRigidBody* pb = ((::hkpRigidBody *)(::FUN_004ae750(pThis)));
    return pb ? FUN_004b4ea0(pb) : 0.0f;
}


struct NiPoint3_sub : public NiPoint3
{
    NiPoint3 operator-(const NiPoint3& pt) const;
};

// @fnv 0x004b5440
bool __cdecl FUN_004b5440(const NiPoint3& aPt1, const NiPoint3& aPt2, float afCompLength)
{
    return ((bool)(::FUN_004b5470((::TESCombatStyle *)&(const ::NiPoint3 &)(((const NiPoint3_sub&)aPt1) - aPt2), afCompLength)));
}

float __cdecl FUN_004b5530(float);

// @fnv 0x004b5510
float __cdecl FUN_004b5510(float _X)
{
    return FUN_004b5530(_X);
}


// @fnv 0x004b5530
float FUN_004b5530(float value)
{
    return static_cast<float>(std::asin(value));
}

float __cdecl FUN_004b5590(float, float);

// @fnv 0x004b5570
float __cdecl FUN_004b5570(float _Y, float _X)
{
    return FUN_004b5590(_Y, _X);
}


// Returns the result of FUN_004b59c0 when FUN_004b5980 reports 2 for collidable, otherwise returns 0.
// @fnv 0x004b5950
void* __cdecl FUN_004b5950(const void* collidable)
{
    if (::FUN_004b5980((std::intptr_t)(collidable)) == 2)
    {
        return (void *)::FUN_004b59c0((const char *)(collidable));
    }
    return 0;
}

// @fnv 0x004b59d0
const void* FUN_004b59d0(const char* apBase)
{
    return apBase + apBase[0x10];
}


// Returns the result of FUN_004b59c0 when FUN_004b5980 reports 1 for collidable, otherwise returns 0.
// @fnv 0x004b59f0
void* __cdecl FUN_004b59f0(const void* collidable)
{
    if (::FUN_004b5980((std::intptr_t)(collidable)) == 1)
    {
        return (void *)::FUN_004b59c0((const char *)(collidable));
    }
    return 0;
}

class NiShader
{
  public:
    static NiAVObject* __cdecl DynamicCast(NiAVObject*);
};


// @fnv 0x004b5ad0
void* __cdecl FUN_004b5ad0(NiAVObject* apPhantom)
{
    NiAVObject* pc = NiShader::DynamicCast(apPhantom);
    return ((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const char *const *>(&::g_01268168))), (::NiObject *)(pc))));
}

class BSXFlags
{
  public:
};

// @fnv 0x004b5fa0
bool FUN_004b5fa0(const BSXFlags* pThis)
{
    return reinterpret_cast<::FUN_00448a60_struct *>((void *)(pThis))->GetMaskedValue(0x20) != 0;
}

struct NiPlane_004b6100
{
};
struct B_004b6100
{
    float cx, cy, cz, radius;
    int ClassifySphereAgainstPlane(NiPlane_004b6100* m_kFogPlane);
};
struct NiPoint3_ext : NiPoint3
{
};

struct FUN_004b6160_class
{
    NiPoint3_ext normal;
    float d;
    float EvaluatePlane(const NiPoint3& pt) const;
};
// Computes the plane distance to this sphere and returns 2 if fully behind, 1 if fully in front, or 0 if straddling.
// @fnv 0x004b6100
int B_004b6100::ClassifySphereAgainstPlane(NiPlane_004b6100* m_kFogPlane)
{
    float fDistance = reinterpret_cast<::FUN_004b6160_class *>((m_kFogPlane))->EvaluatePlane((*(const ::NiPoint3 *)(this)));
    if (fDistance <= -radius)
        return 2;
    else if (fDistance >= radius)
        return 1;
    else
        return 0;
}

struct FUN_004b6190_shell : public NiPoint3
{
    float DotProduct(void*);
};
// @fnv 0x004b6160
float FUN_004b6160_class::EvaluatePlane(const NiPoint3& aPoint) const
{
    return reinterpret_cast<::FUN_004b6190_shell *>((void *)&(normal))->DotProduct((void *)&(aPoint)) - d;
}

// Returns the dot product of this NiPoint3 with the NiPoint3 pointed to by pt.
// @fnv 0x004b6190
float FUN_004b6190_shell::DotProduct(void* apPoint)
{
    return x * static_cast<const NiPoint3*>(apPoint)->x + y * static_cast<const NiPoint3*>(apPoint)->y +
           z * static_cast<const NiPoint3*>(apPoint)->z;
}


class TESObjectREFR
{
  public:
};

// Skips incrementing the counter at data+0xc when the object matches the RTTI checks or is an Arrow; otherwise increments it.
// @fnv 0x004b6740
void __cdecl FUN_004b6740(NiAVObject* apObject, char* data)
{
    if ((*(unsigned int*)(data + 0x18) & 1) && FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_0126817c)), apObject))
        return;
    if ((*(unsigned int*)(data + 0x18) & 2) &&
        FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f9140)), (NiAVObject*)((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR*)apObject)))->GetName()))))
        return;
    if ((*(unsigned int*)(data + 0x18) & 2) && ((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR*)apObject)))->GetName())) &&
        ((BSFadeNode*)((TESTopicInfoData*)((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR*)apObject)))->GetName())))->GetLinkToList())
            ->FUN_0043b1b0() &&
        !FUN_00408b20(
            (const char*)((BSFadeNode*)((TESTopicInfoData*)((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR*)apObject)))->GetName())))->GetLinkToList())
                ->FUN_0043b1b0(),
            "Arrow"))
        return;
    *(int*)(data + 0xc) += 1;
}

template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x004b6e70
const char* GetStringAtOffset13C(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x13c);
}

bool __cdecl FUN_004b71d0(void);

// Returns 1 if FUN_004b71d0() returns true, otherwise returns 0.
// @fnv 0x004b71a0
int FUN_004b71a0()
{
    int result = 0;
    if (FUN_004b71d0())
        result = 1;
    return result;
}

class MobileObject
{
  public:
    bool GetCharControllerFlag() const;
};


// Returns true when DAT_011d8a84 is set and, after calling FUN_004b7210, g_011d8c4c reports its char controller flag.
// @fnv 0x004b71d0
bool __cdecl FUN_004b71d0()
{
    return DAT_011d8a84 && (((void *)(::fnv_004b7210::FUN_004b7210())), (*reinterpret_cast<::MobileObject *>(&::g_011d8c4c)).GetCharControllerFlag());
}

struct FUN_0063f790_shell : public NiBound
{
    void FUN_0063f790(float);
};

// @fnv 0x0063f790
void FUN_0063f790_shell::FUN_0063f790(float afRadius)
{
    *(float*)((char*)this + 0xc) = afRadius;
}


struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float fX, float fY, float fZ);
    NiPoint3Ex operator+(const NiPoint3Ex& pt) const;
    NiPoint3Ex operator-(const NiPoint3& pt) const;
};

// @fnv 0x004b1e80
bool FUN_004b1e80(const tagRECT* aTestRect, const NiPoint3* aStartPt, const NiPoint3* aEndPt,
                  NiPoint3* aOutputIntersectPt)
{
    bool bIntersect = false;

    if (aTestRect->left >= aTestRect->right)
        return false;
    if (aTestRect->bottom >= aTestRect->top)
        return false;
    if (aStartPt->x < aTestRect->left && aEndPt->x < aTestRect->left)
        return false;
    if (aStartPt->y < aTestRect->bottom && aEndPt->y < aTestRect->bottom)
        return false;
    if (aStartPt->x > aTestRect->right && aEndPt->x > aTestRect->right)
        return false;
    if (aStartPt->y > aTestRect->top && aEndPt->y > aTestRect->top)
        return false;
    if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right && aStartPt->y > aTestRect->bottom &&
        aStartPt->y < aTestRect->top && aEndPt->x > aTestRect->left && aEndPt->x < aTestRect->right &&
        aEndPt->y > aTestRect->bottom && aEndPt->y < aTestRect->top)
        return false;

    if (aEndPt->x == aStartPt->x || aEndPt->y == aStartPt->y)
    {
        if (aEndPt->x == aStartPt->x && aEndPt->y == aStartPt->y)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left && aStartPt->y <= aTestRect->top &&
                aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                *aOutputIntersectPt = *aStartPt;
            }
        }
        else if (aEndPt->x == aStartPt->x)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left)
            {
                bIntersect = true;
                if (aStartPt->y > aEndPt->y)
                    *aOutputIntersectPt = NiPoint3Ex(aStartPt->x, aTestRect->top, 0.0f);
                else
                    *aOutputIntersectPt = NiPoint3Ex(aStartPt->x, aTestRect->bottom, 0.0f);
            }
        }
        else if (aEndPt->y == aStartPt->y)
        {
            if (aStartPt->y <= aTestRect->top && aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                if (aStartPt->x > aEndPt->x)
                    *aOutputIntersectPt = NiPoint3Ex(aTestRect->right, aStartPt->y, 0.0f);
                else
                    *aOutputIntersectPt = NiPoint3Ex(aTestRect->left, aStartPt->y, 0.0f);
            }
        }
    }
    else
    {
        int intersectsFound = 0;
        NiPoint3Ex intersect1(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        NiPoint3Ex intersect2(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        float slope = (aEndPt->y - aStartPt->y) / (aEndPt->x - aStartPt->x);
        float intercept = aEndPt->y - aEndPt->x * slope;

        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->left * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(aTestRect->left, YatBorder, 0.0f);
                else
                    intersect2 = NiPoint3Ex(aTestRect->left, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->top - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(XatBorder, aTestRect->top, 0.0f);
                else
                    intersect2 = NiPoint3Ex(XatBorder, aTestRect->top, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->right * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(aTestRect->right, YatBorder, 0.0f);
                else
                    intersect2 = NiPoint3Ex(aTestRect->right, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->bottom - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(XatBorder, aTestRect->bottom, 0.0f);
                else
                    intersect2 = NiPoint3Ex(XatBorder, aTestRect->bottom, 0.0f);
                intersectsFound++;
            }
        }

        if (intersectsFound)
        {
            bIntersect = true;
            if (intersectsFound == 2)
            {
                if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right &&
                    aStartPt->y > aTestRect->bottom && aStartPt->y < aTestRect->top)
                {
                    NiPoint3Ex linevect = (const NiPoint3Ex&)*aEndPt - *aStartPt;
                    NiPoint3Ex intersect1vect = intersect1 - *aStartPt;
                    linevect.z = 0.0f;
                    intersect1vect.z = 0.0f;
                    reinterpret_cast<::FUN_004a0c10_s *>(&(linevect))->FUN_004a0c10();
                    reinterpret_cast<::FUN_004a0c10_s *>(&(intersect1vect))->FUN_004a0c10();
                    if (reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3Ex &)((linevect + intersect1vect)))->ComputeMagnitude() > 1.0)
                        *aOutputIntersectPt = intersect1;
                    else
                        *aOutputIntersectPt = intersect2;
                }
                else if (reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3Ex &)((intersect1 - *aStartPt)))->ComputeMagnitude() < reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3Ex &)((intersect2 - *aStartPt)))->ComputeMagnitude())
                {
                    *aOutputIntersectPt = intersect1;
                }
                else
                {
                    *aOutputIntersectPt = intersect2;
                }
            }
            else
            {
                *aOutputIntersectPt = intersect1;
            }
        }
    }
    return bIntersect;
}

struct bhkRefObject
{
};

extern unsigned char DAT_0102023c;

struct FUN_004b5120 : bhkRefObject
{
    void* vtbl;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    int m_pad3;
    FUN_004b5120();
};

// Calls Initialize, installs the vtable pointer at offset 0 and zeroes the int at offset 0xc.
// @fnv 0x004b5120
FUN_004b5120::FUN_004b5120()
{
    reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
    *reinterpret_cast<void**>(this) = &DAT_0102023c;
    this->m_pad3 = 0;
}

struct FUN_004b51a0_shell
{
    void* FUN_004b51a0(unsigned int flags);
};

struct FUN_00c87970_shell
{
};


// @fnv 0x004b51a0
void* FUN_004b51a0_shell::FUN_004b51a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00c87970 *>((((FUN_00c87970_shell*)this)))->FUN_00c87970::~FUN_00c87970();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}


struct FUN_004b51d0_shell
{
    const char* const* GetRTTI();
};

// @fnv 0x004b51d0
const char* const* FUN_004b51d0_shell::GetRTTI()
{
    return &(*reinterpret_cast<const char *const *>(&::g_0126811c));
}


struct FUN_004b5210_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x004b5210
const NiRTTI* FUN_004b5210_shell::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_0126812c));
}

// @fnv 0x004b59a0
int GetCharAtOffset4(int param_1)
{
    return (int)*(char*)(param_1 + 4);
}

// @fnv 0x004b5f60
const NiFixedString& FUN_004b5f60()
{
    return *DAT_011c61f0;
}

// @fnv 0x004b5f70
const NiFixedString& FUN_004b5f70()
{
    return *DAT_011c61f4;
}

// @fnv 0x004b5f80
const NiFixedString& FUN_004b5f80()
{
    return *DAT_011c61f8;
}

// @fnv 0x004b5f90
const NiFixedString& FUN_004b5f90()
{
    return *DAT_011c61fc;
}

struct bhkWorldObject;
class NiAVObject;
struct bhkCollisionObject
{
public:
    static ::bhkCollisionObject *GetFromNiAVObject(::NiAVObject *);
};

// Gets the collision object's world object and, if it exists and GetReferenceFlags returns nonzero, increments the fourth int of arg.
// @fnv 0x004b6b20
void __cdecl FUN_004b6b20(bhkCollisionObject* apCollisionObject, void* apData)
{
    bhkWorldObject* result = ((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(apCollisionObject))));
    if (result && ((int)(reinterpret_cast<::FUN_00620b80_shell *>((result))->GetReferenceFlags())))
        ((int*)apData)[3]++;
}

namespace fnv_004b6bc0 {
struct bhkWorldObject;
struct bhkCollisionObject
{
};


// @fnv 0x004b6bc0
void FUN_004b6bc0(bhkCollisionObject* apCollisionObject, void* dest)
{
    bhkWorldObject* w = ((::fnv_004b6bc0::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(apCollisionObject))));
    if (w)
    {
        int r = ((int)(reinterpret_cast<::FUN_00620b80_shell *>((w))->GetReferenceFlags()));
        if (r)
        {
            if (r == ((int*)dest)[4])
            {
                ((int*)dest)[5] = ((int*)dest)[3];
            }
            ((int*)dest)[3] = ((int*)dest)[3] + 1;
        }
    }
}
}  // namespace fnv_004b6bc0

namespace fnv_004b6c70 {
struct bhkCollisionObject
{
};


// @fnv 0x004b6c70
void __cdecl FUN_004b6c70(bhkCollisionObject* apCollisionObject, int* arg2)
{
    int* obj = ((int *)(::fnv_006fa820::FUN_006fa820((const char *)(apCollisionObject))));
    if (obj)
    {
        int result = ((int)(reinterpret_cast<::FUN_00620b80_shell *>((obj))->GetReferenceFlags()));
        if (result)
        {
            if (arg2[3] == arg2[5])
            {
                arg2[4] = result;
            }
            arg2[3] = arg2[3] + 1;
        }
    }
    arg2[3] = arg2[3] + 1;
}
}  // namespace fnv_004b6c70

namespace fnv_004b7210 {
struct UIRoot;

// @fnv 0x004b7210
UIRoot* FUN_004b7210()
{
    return (*reinterpret_cast<::fnv_004b7210::UIRoot * *>(&::DAT_011d8a80));
}
}  // namespace fnv_004b7210

namespace fnv_004b50f0 {
struct FUN_004b5120
{
    FUN_004b5120();
};


struct FUN_004b50f0 : FUN_004b5120
{
    int* m_p;
    FUN_004b50f0();
};

FUN_004b5120::FUN_004b5120()
{}

// Sets m_p to the address of DAT_0102016c and increments DAT_01268154.
// @fnv 0x004b50f0
FUN_004b50f0::FUN_004b50f0()
{
    m_p = &::DAT_0102016c;
    ++::DAT_01268154;
}
}  // namespace fnv_004b50f0


struct FUN_004b5150_shell
{
    char const* const* FUN_004b5150();
};

// @fnv 0x004b5150
char const* const* FUN_004b5150_shell::FUN_004b5150()
{
    return &(*reinterpret_cast<const char *const *>(&::g_01268134));
}

struct bhkSerializable
{
    void* FUN_004b5160(unsigned int flags);
};


// Calls Destroy on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004b5160
void* bhkSerializable::FUN_004b5160(unsigned int flags)
{
    reinterpret_cast<::FUN_00c877b0 *>((this))->FUN_00c877b0::~FUN_00c877b0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}


struct FUN_004b5190_shell
{
    const char* const* FUN_004b5190();
};

// @fnv 0x004b5190
const char* const* FUN_004b5190_shell::FUN_004b5190()
{
    return &(*reinterpret_cast<const char *const *>(&::g_01268158));
}

struct bhkUnaryAction
{
public:
    void Set(float, float, float, float);
};

struct FUN_004b51e0_shell : bhkUnaryAction
{
    void* FUN_004b51e0(unsigned int flags);
};

// @fnv 0x004b51e0
void* FUN_004b51e0_shell::FUN_004b51e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00c86720 *>((this))->FUN_00c86720::~FUN_00c86720();
    if (flags & 1)
        ::FUN_00aa1460(this, 16);
    return this;
}

int GetCharAtOffset4(int);

// @fnv 0x004b5980
int FUN_004b5980(intptr_t param_1)
{
    return GetCharAtOffset4(param_1 + 0x14);
}

void const* FUN_004b59d0(char const*);

// @fnv 0x004b59c0
void const* __cdecl FUN_004b59c0(char const* arg)
{
    return FUN_004b59d0(arg);
}

namespace fnv_004b4d10 {
struct bhkUnaryAction
{
    void Set(float, float, float, float);
};
struct UnaryActionSettings
{
    float f00;
    float f04;
    float f08;
    float f0C;
    bhkUnaryAction* ApplyToAction(bhkUnaryAction*);
};
// Calls Set on the given bhkUnaryAction with this object's four floats and returns the action.
// @fnv 0x004b4d10
bhkUnaryAction* UnaryActionSettings::ApplyToAction(bhkUnaryAction* apAction)
{
    reinterpret_cast<::bhkUnaryAction *>((apAction))->Set(f00, f04, f08, f0C);
    return apAction;
}
}  // namespace fnv_004b4d10

namespace fnv_004b4ec0 {
struct BSSimpleList_Ragdoll;
struct FUN_004b4ee0_shell
{
    void FUN_004b4ee0();
};
struct TESDataHandler
{
};
struct FUN_004b4ec0_shell
{
    void FUN_004b4ec0();
};
// @fnv 0x004b4ec0
void FUN_004b4ec0_shell::FUN_004b4ec0()
{
    ((FUN_004b4ee0_shell*)((::fnv_004b4ec0::BSSimpleList_Ragdoll *)(reinterpret_cast<::FUN_009d9f40_Class *>((((TESDataHandler*)this)))->FUN_009d9f40())))->FUN_004b4ee0();
}
}  // namespace fnv_004b4ec0

extern "C" void __cdecl _ref_006815c0();
struct FUN_004b4f20_shell
{
    void FUN_004b4f20();
};
// @fnv 0x004b4f20
void FUN_004b4f20_shell::FUN_004b4f20()
{
    ((void(*)(void*))_ref_006815c0)((char*)this + 0x10);
}

struct Base537
{
    char _d[0x10];
};
struct Mem4fa0
{
    char _d[0x10];
};
struct FUN_004b4f40 : Base537
{
    Mem4fa0 m10;
    Mem4fa0 m20;
    float f30;
    float f34;
    float f38;
    float f3c;
    FUN_004b4f40();
};
struct FUN_004b4fa0_shell
{
    void* FUN_004b4fa0();
};
// Calls base and member initializers, then sets f30 to 0.5, f34 to 0.3, f38 to DAT_0101b2d0 and f3c to g_011cc6cc_arg1.
// @fnv 0x004b4f40
FUN_004b4f40::FUN_004b4f40()
{
    reinterpret_cast<::Cl537 *>(this)->FUN_00537bb0();
    reinterpret_cast<::FUN_004b4fa0_shell *>(&(m10))->FUN_004b4fa0();
    reinterpret_cast<::FUN_004b4fa0_shell *>(&(m20))->FUN_004b4fa0();
    f30 = 0.5f;
    f34 = 0.3f;
    f38 = DAT_0101b2d0;
    f3c = g_011cc6cc_arg1;
}


struct S_004b4fc0
{
    void FUN_004b4fc0();
};
// @fnv 0x004b4fa0
void* FUN_004b4fa0_shell::FUN_004b4fa0()
{
    reinterpret_cast<::S_004b4fc0 *>((this))->FUN_004b4fc0();
    return this;
}
// Calls FUN_004b4ff0 with four zero float arguments.
// @fnv 0x004b4fc0
void S_004b4fc0::FUN_004b4fc0()
{
    reinterpret_cast<::fnv_004b4ff0::FUN_004b4ff0_shell *>(this)->FUN_004b4ff0(0.0f, 0.0f, 0.0f, 0.0f);
}

struct Fake004b50c0
{
    void FUN_004b50f0();
    Fake004b50c0* FUN_004b50c0();
};
// @fnv 0x004b50c0
Fake004b50c0* Fake004b50c0::FUN_004b50c0()
{
    new ((void *)this) ::fnv_004b50f0::FUN_004b50f0();
    *(int*)this = (int)&DAT_0102009c;
    DAT_01268118++;
    return this;
}

struct bhkMouseSpringAction
{
    void* FUN_004b5230(unsigned int);
};
// Calls FUN_00c86cb0, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004b5230
void* bhkMouseSpringAction::FUN_004b5230(unsigned int flags)
{
    reinterpret_cast<::FUN_00c86cb0 *>((this))->FUN_00c86cb0::~FUN_00c86cb0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}

namespace fnv_004b5260 {
struct bhkCollisionObject
{
};
// @fnv 0x004b5260
NiAVObject* FUN_004b5260(NiAVObject* object)
{
    NiAVObject* result = 0;
    if (object)
    {
        result = ((::NiAVObject *)(::bhkCollisionObject::GetFromNiAVObject(object)));
        if (!result)
        {
            NiNode* node = object->GetAsNiNode();
            if (node)
            {
                unsigned int count = node->FUN_0043b480();
                for (unsigned int i = 0; i < count; ++i)
                {
                    result = FUN_004b5260(node->GetAt(i));
                    if (result)
                        break;
                }
            }
        }
    }
    return result;
}
}  // namespace fnv_004b5260

struct TESCombatStyle
{
    float UpdateCombatStyle();
};
// @fnv 0x004b5470
int FUN_004b5470(TESCombatStyle* apCombatStyle, float afValue)
{
    float f1;
    float f2;
    f1 = apCombatStyle->UpdateCombatStyle();
    f2 = afValue * afValue;
    if (f1 < f2)
        return -1;
    else
    {
        if (f1 > f2)
            return 1;
    }
    return 0;
}

extern float runtimeInitializationFloat825;
float __cdecl FUN_004b5510(float);
// @fnv 0x004b54c0
float __cdecl FUN_004b54c0(float afValue)
{
    if (afValue > -1.0)
    {
        if (afValue < 1.0)
        {
            return FUN_004b5510(afValue);
        }
        else
        {
            return runtimeInitializationFloat825;
        }
    }
    else
    {
        return -runtimeInitializationFloat825;
    }
}

struct GlobalObjectO2_00a7b610
{
};
// Returns true if object or any descendant NiNode child has a controller matching g_011f3728; recurses through children.
// @fnv 0x004b5bf0
bool FUN_004b5bf0(NiAVObject* object)
{
    if (!object)
        return false;
    if (((::NiTimeController *)(reinterpret_cast<::MyHost *>((object))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)(reinterpret_cast<const NiRTTI*>(&::g_011f3728))))))
        return true;
    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
        {
            NiAVObject* child = node->GetAt(i);
            if (FUN_004b5bf0(child))
                return true;
        }
    }
    return false;
}

class NiCamera;
struct FUN_0043d450_Owner
{
    NiBound* FUN_0043d450();
};
bool __cdecl IsBoundVisible(NiBound*, NiCamera*);
// Returns false if apObject is null, otherwise tests the object's bound against apCamera via IsBoundVisible.
// @fnv 0x004b5fc0
bool __cdecl FUN_004b5fc0(NiAVObject* apObject, NiCamera* apCamera)
{
    if (apObject)
    {
        return IsBoundVisible(((FUN_0043d450_Owner*)apObject)->FUN_0043d450(), apCamera);
        goto done;
    }
    return false;
done:;
}

namespace CollisionObjectCount {
struct IntegerAndByteRecord
{
    int _00;
    unsigned char _04;
    int _08;
    int _0C;
    int _10;
    int _14;
    int _18;
};
}
// @fnv 0x004b6ae0
int FUN_004b6ae0(NiAVObject* apRoot)
{
    CollisionObjectCount::IntegerAndByteRecord recData;
    recData._08 = 18;
    recData._04 = 1;
    recData._0C = 0;
    ::FUN_00c68900((::S_00c68900_Node *)(apRoot), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(reinterpret_cast<CollisionObjectCountContext*>(&recData)), (void (*)(void *, S_00c68900_Context *))(((void (&)(NiCollisionObject *, CollisionObjectCountContext *))::FUN_004b6b20)));
    return recData._0C;
}

namespace fnv_004b6c20 {
struct hkpWorldObject;
namespace CollisionObjectCount {
struct IntegerAndByteRecord
{
    int _0;
    bool _4;
    char _5;
    char _6;
    char _7;
    int _8;
    int _12;
    hkpWorldObject* _16;
    int _20;
    int _24;
};
}
// @fnv 0x004b6c20
hkpWorldObject* FindCollisionObjectByIndex(NiAVObject* apRoot, int aiIndex)
{
    CollisionObjectCount::IntegerAndByteRecord recData;
    recData._8 = 0x12;
    recData._4 = 1;
    recData._12 = 0;
    recData._16 = 0;
    recData._20 = aiIndex;
    ::FUN_00c68900((::S_00c68900_Node *)(apRoot), (::S_00c68900_Context *)(::CollisionObjectCountContext *)((CollisionObjectCountContext*)&recData), (void (*)(void *, S_00c68900_Context *))(((void (&)(NiCollisionObject *, CollisionObjectCountContext *))::fnv_004b6c70::FUN_004b6c70)));
    return recData._16;
}
}  // namespace fnv_004b6c20

struct S004e88d0
{
    float m0;
    float m4;
    S004e88d0& Add(S004e88d0*);
};
// Adds the two floats of p into this object's m0 and m4 and returns *this.
// @fnv 0x004e88d0
S004e88d0& S004e88d0::Add(S004e88d0* apOther)
{
    m0 += apOther->m0;
    m4 += apOther->m4;
    return *this;
}

struct Flt
{
    operator unsigned int() const;
};

struct FUN_004b70d0_shell
{
    char pad[0x3c];
    Flt m_flt;
    unsigned int FUN_004b70d0();
};

// @fnv 0x004b70d0
unsigned int FUN_004b70d0_shell::FUN_004b70d0()
{
    return m_flt.operator unsigned int();
}

struct Sub004B
{
    char pad[16];
};
struct Sub0056
{
    char pad[16];
};
struct Owner0066d650
{
    Sub0056 f0;
    Sub004B f10;
    Sub004B f20;
    Owner0066d650* Reset();
};
// @fnv 0x0066d650
Owner0066d650* Owner0066d650::Reset()
{
    reinterpret_cast<::FUN_0056e900_shell *>(&(f0))->FUN_0056e8d0();
    reinterpret_cast<::FUN_004b4fa0_shell *>(&(f10))->FUN_004b4fa0();
    reinterpret_cast<::FUN_004b4fa0_shell *>(&(f20))->FUN_004b4fa0();
    reinterpret_cast<::fnv_004b4ff0::FUN_004b4ff0_shell *>(&(f20))->FUN_004b4ff0(1.0f, 0.0f, 0.0f, 0.0f);
    return this;
}

namespace fnv_004b2800 {
struct NiPick
{
};
struct FUN_00456630_helper
{
};
struct FUN_0043d450_Owner
{
    NiBound* FUN_0043d450();
};
struct Pt
{
    float x, y, z;
};
struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex operator-(const NiPoint3&) const;
};
struct FUN_004b2800_Bound
{
    float x, y, z, r;
};

// @fnv 0x004b2800
bool PickObjectsInRadius(NiPick* pick, const NiPoint3& origin, const NiPoint3& dir, float radius, NiAVObject* object)
{
    bool result = false;
    if (pick && object && (!((bool)(::GetByteAtOffset17((const char*)pick))) || !reinterpret_cast<::FUN_00456630_helper *>((((FUN_00456630_helper*)object)))->FUN_00456610()))
    {
        if (!object->IsVisualObject())
            return false;
        FUN_004b2800_Bound kBound = *(FUN_004b2800_Bound*)((FUN_0043d450_Owner*)object)->FUN_0043d450();
        NiPoint3Ex kDiff = *((::fnv_004b2800::NiPoint3Ex *)((void *)(&kBound))) - origin;
        if (reinterpret_cast<::NiPoint3 *>((void *)(((Pt*)&kDiff)))->ComputeMagnitude() < reinterpret_cast<::Twin_0084d030 *>((((NiBound*)&kBound)))->GetStoredFloatValue() + radius)
        {
            NiNode* node = object->GetAsNiNode();
            if (node)
            {
                int count = node->FUN_0043b480();
                for (int i = 0; i < count; i++)
                {
                    NiAVObject* child = node->GetAt(i);
                    if (PickObjectsInRadius(pick, origin, dir, radius, child))
                        result = true;
                }
            }
            else
            {
                reinterpret_cast<::NiPick *>((pick))->FUN_00705fc0(object);
                if (reinterpret_cast<::NiPick *>((pick))->PerformPick(origin, dir, true))
                    result = true;
            }
        }
    }
    return result;
}
}  // namespace fnv_004b2800

struct BSShaderAccumulator;
struct BSShaderTextureSet;
struct BSTextureSet;
struct NiAdditionalGeometryData;
struct CloningProcess;
struct NiGeometry;
struct NiObject;
struct NiStream;
struct NiTriBasedGeom;
struct ShadowSceneLight;
struct blob16
{
    char b[16];
};
struct NiShadeProperty : public NiProperty
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(NiShadeProperty*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void GetViewerStrings(void*);
    void SetField(unsigned short, unsigned short, unsigned short);
    unsigned short GetField(unsigned short, unsigned short);
    void SetBit(bool, unsigned short);
    bool GetBit(unsigned short);
    void SetSmooth(bool);
    bool GetSmooth();
    bool IsEqualFast(void*);
    virtual int Type();
    static int GetType();
    static NiShadeProperty* GetDefault();
    static void InitializePoint3();
    static void ShutdownPoint3();
    int GetShaderPropertyType();
    void __local_vftable_ctor_closure();
    char _pad_4[20];
    unsigned short m_uiObjectFlags;
    char _pad_1a[2];
    int m_iShaderType;
};
struct BSShaderProperty : public NiShadeProperty
{
    virtual void __vslot_0();
    virtual void CopyTo(BSShaderProperty*);
    virtual void CopyToMembers(BSShaderProperty*);
    virtual bool SetupGeometry(NiGeometry*);
    virtual void* CreateRenderPasses(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual unsigned short GetNumberofPasses(NiGeometry*);
    virtual void* GetSIBlockRenderPasses();
    virtual void* GetRenderDepthPass(NiGeometry*);
    virtual BSShaderProperty* ClarifyShader(NiGeometry*, bool, bool);
    virtual NiTexture* GetBaseTexture();
    virtual void* GetWaterFogPassList(NiGeometry*);
    virtual void GetTextureUse(int*, void*);
    virtual void PrecacheTextures();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSShaderProperty*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void PostLinkObject(NiStream*);
    void* QRenderPasses();
    void CheckCreateRenderPassArray(int);
    void CheckCreateDepthMapRenderPassArray(int);
    void CheckCreateLocalMapRenderPassArray(int);
    void CheckCreateSIBlockRenderPassArray(int);
    void CheckCreateConstAlphaRenderPassArray(int);
    void CheckCreateWaterFogRenderPassArray(int);
    void CheckSilhouetteRenderPassArray(int);
    void SetLastRenderPassState(int);
    bool CompareFlags(BSShaderProperty*);
    bool GetFlag(unsigned int);
    void SetFlag(unsigned int, bool);
    float GetAlpha();
    float GetFadeAlpha();
    void SetFadeAlpha(float);
    void FreeRenderPasses();
    void ClearRenderPasses();
    void SetObjectType(unsigned int);
    unsigned int GetObjectType();
    int QShader();
    void SetShader(int);
    float QEnvmapScale();
    void SetEnvmapScale(float);
    static void ToggleMotionBlurRecurse(NiAVObject*);
    static void SetMotionBlurRecurse(NiAVObject*, bool);
    static void SetFlagRecurse(NiAVObject*, int, bool);
    bool Get1stPerson();
    void Set1stPerson(bool);
    float GetDepthBias();
    void SetDepthBias(float);
    static void ResetDebugStats();
    static void GetDebugStats(unsigned int*);
    void SetMotionBlurred(bool);
    float GetCameraDistance();
    static void ClearRenderPassGarbage();
    void __local_vftable_ctor_closure();
    char ulFlags[8];
    float fAlpha;
    float fFadeAlpha;
    float m_fAmbientReflectionScale;
    float m_fSpecularExponent;
    int iLastRenderPassState;
    void* pRenderPassList;
    void* m_pRenderPassArray1;
    void* m_pRenderPassArray2;
    void* m_pRenderPassArray3;
    void* m_pRenderPassArray4;
    void* m_pRenderPassArray5;
    void* m_pRenderPassArray6;
    int m_iRenderPassCount;
    float fDepthBias;
    float m_fValueAfterDepthBias;
    float m_fEnvironmentMapScale;
};
struct BSShaderLightingProperty : public BSShaderProperty
{
    virtual void __vslot_0();
    virtual void CopyTo(BSShaderLightingProperty*);
    virtual void CopyToMembers(BSShaderLightingProperty*);
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSShaderLightingProperty*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    bool CopyLightingDataTo(ShadowSceneLight*, NiBound*, void**);
    void ResortLights(NiBound*);
    bool AreLightsSorted(NiBound*);
    ShadowSceneLight* GetFirstAttachedLight(void**);
    ShadowSceneLight* GetFirstActiveLight(void**);
    ShadowSceneLight* GetFirstActiveNonShadowLight(void**);
    ShadowSceneLight* GetNextLight(void**);
    ShadowSceneLight* GetNextAttachedLight(void**);
    ShadowSceneLight* GetNextVisibleNonShadowLight(void**);
    void AttachLight(ShadowSceneLight*, NiBound*);
    void RemoveLight(ShadowSceneLight*);
    unsigned short GetNumberofLights();
    unsigned short GetNumberOfActiveLights();
    unsigned short GetNumberofActiveNonShadowLights();
    static void SetShaderConstant(int, struct blob16);
    static void SetLight(unsigned int, ShadowSceneLight*, float);
    static void SetLight1x2x(unsigned int, ShadowSceneLight*, float);
    static void SetPointLight3x(unsigned int, ShadowSceneLight*, float);
    static void SetSpotLight3x(unsigned int, ShadowSceneLight*, float);
    static void ResetLights(int);
    void SetForcedDarkness(float);
    float GetForcedDarkness();
    void SetReferenceID(unsigned int);
    unsigned int GetReferenceID();
    void FenceAllLights();
    void ClearLights(NiTriBasedGeom*);
    void SetLightListChanged(bool);
    void __local_vftable_ctor_closure();
    char m_kShadowSceneLights[12];
    float m_fForcedDarkness;
    unsigned int m_uiLightCount;
    bool m_bHasForcedDarkness;
    char _pad_7d[3];
    void* m_pLightData;
};
struct BSShaderPPLightingProperty : public BSShaderLightingProperty
{
    virtual void __vslot_0();
    virtual void CopyTo(BSShaderPPLightingProperty*);
    virtual void CopyToMembers(BSShaderPPLightingProperty*);
    virtual NiAdditionalGeometryData* CreateRendererSpecificProperty(NiGeometry*);
    virtual int GetClampD3D();
    virtual void SetClampD3D(int);
    virtual int GetClampNI();
    virtual void SetClampNI(int);
    virtual unsigned short GetTextureCount();
    virtual unsigned short QLandscapeTextureCount();
    virtual void SetTexture(int, unsigned int, NiTexture*);
    virtual NiTexture* GetTexture(int, unsigned int);
    virtual void SetRectangleBounds(BSShaderTextureSet*);
    virtual void SetDiffuseTexture(unsigned int, NiTexture*);
    virtual void SetNormalTexture(unsigned int, NiTexture*);
    virtual void SetSpecularTexture(unsigned int, NiTexture*);
    virtual void SetGlowTexture(unsigned int, NiTexture*);
    virtual void SetFlagsFromTextures();
    virtual float GetSpecularLODFade();
    virtual float GetEnvMapLODFade();
    virtual void GetRenderPasses_1x(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual void GetRenderPasses_2x(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSShaderPPLightingProperty*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void PostLinkObject(NiStream*);
    virtual bool SetupGeometry(NiGeometry*);
    virtual void* CreateRenderPasses(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual unsigned short GetNumberofPasses(NiGeometry*);
    virtual void* GetRenderDepthPass(NiGeometry*);
    virtual NiTexture* GetBaseTexture();
    NiTexture* GetDiffuseTextureIndex(unsigned int);
    NiTexture* GetNormalMapTexture(unsigned int);
    NiTexture* GetSpecularTexture(unsigned int);
    NiTexture* GetGlowTexture(unsigned int);
    void* GetExtraDataPointers();
    NiPoint3* GetTangentExtraData();
    NiPoint3* GetBinormalExtraData();
    void StoreExtraDataPointers(void*);
    void StoreTextureSplatVertexDataPointers(float*);
    static bool GetForceNoProjectedShadowTexture();
    static void SetForceNoProjectedShadowTexture(bool);
    void SetLandscapeSpecularExponents(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char,
                                       unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    void SetForLandscapeTextures();
    void SetLandscapeTextureSet(unsigned int, BSTextureSet*);
    NiTexture* GetLandscapeTexture(unsigned short);
    bool GetTextureSpecular(int);
    float GetTextureSpecularExponent(int);
    void SetTextureEffectData(void*);
    void* GetTextureEffectData();
    static void UpdateRefractionRecurse(NiAVObject*, bool, float, bool, float, bool);
    static bool HasRefractionRecurse(NiAVObject*);
    float GetRefractionPower();
    void SetRefractionPower(float);
    int GetRefractionFirePeriod();
    void SetRefractionFirePeriod(int);
    float GetParallaxOccMaxPasses();
    void SetParallaxOccMaxPasses(float);
    float GetParallaxOccScale();
    void SetParallaxOccScale(float);
    bool QRemappableTextures();
    void SetTextureSet(BSTextureSet*);
    void CopyTextureSet(BSTextureSet*);
    void LoadTextureSet(char*, BSTextureSet*);
    void EnsureNormalMap();
    virtual BSShaderProperty* ClarifyShader(NiGeometry*, bool, bool);
    virtual void* GetWaterFogPassList(NiGeometry*);
    virtual void GetTextureUse(int*, void*);
    float GetTerrainTexOffsetX();
    float GetTerrainTexOffsetY();
    float GetTerrainTexFade();
    float GetTerrainDetailTexScale();
    void SetTerrainTexParams(float, float, float);
    void SetTerrainDetailTexScale(float);
    virtual void PrecacheTextures();
    void* AddZOnlyPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddZOnlyTextureEffectPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void AddConstAlphaPass_1x(NiGeometry*, bool, bool);
    void* AddAmbientPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool);
    void* AddAmbDiffTexPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool,
                               bool, bool, bool);
    void* AddAmbDiffDirAndPtPass_1x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*,
                                    bool, bool);
    void* AddDiffusePass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool);
    void* AddAmbientDiffuseTexturePass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool,
                                          bool, bool, bool, bool);
    void* AddSpecularPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                             bool);
    void* AddEnvmapPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddFogPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool, bool);
    void AddLandscapePasses_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool);
    void* AddTextureEffectPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddTextureEffectPass_2x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddRenderNormalsPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddRenderNormalsClearPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddVelocityPass_2x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddSelfIllumAlphaPass(NiGeometry*, unsigned short*, bool, bool, bool);
    void* AddSelfIllumAlphaBlockPass(NiGeometry*, unsigned short*, bool, bool);
    void* AddAmbDiff2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                             bool, bool, bool, bool, bool, bool);
    void* AddAmbDiff3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                             bool, bool*, bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool,
                               bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTex2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                                bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecularPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool,
                                       bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecular2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*,
                                        bool, bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecular10Pass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool,
                                         bool, bool);
    void* AddDiffusePt2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                               bool, bool, bool, bool);
    void* AddDiffusePt3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                               bool, bool*, bool, bool, bool, bool, bool);
    void* AddTexturePass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                            bool, bool, bool);
    void* AddSpecularPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                             bool);
    void* AddSpecularPt2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                                bool, bool, bool);
    void* AddSpecularPt3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                                bool, bool*, bool, bool, bool, bool);
    void* AddEnvmapPass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool,
                           bool);
    void AddLandscapePasses_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool);
    void AddDepthMapPass_2x(NiGeometry*, bool, bool, BSShaderAccumulator*);
    void AddLocalMapPass_2x(NiGeometry*, bool, bool);
    void AddSilhouettePass_2x(NiGeometry*, bool);
    void __local_vftable_ctor_closure();
    float m_fEmissiveMultiple;
    float m_fSpecularScale;
    char m_kEmissiveColor[16];
    char m_kSpecularColor[16];
    char m_spTextureSet[4];
    unsigned short m_usTextureFlags;
    char _pad_b2[2];
    char m_ppTextureSlots[28];
    unsigned char* m_pTextureFlags;
    unsigned short m_usTextureIndex;
    char _pad_d6[2];
    bool* m_pbTextureHasAlpha;
    char m_spTangentSpaceData[4];
    float* m_pfTextureSpecularExponents;
    int m_eClampMode;
    char spTexEffectData[4];
    float m_fValueBeforeTextureCount;
    int m_iTextureCount;
    float m_fFirstFloatAfterTextureCount;
    float m_fSecondFloatAfterTextureCount;
    float m_fThirdFloatAfterTextureCount;
    float m_fFourthFloatAfterTextureCount;
    float m_fFifthFloatAfterTextureCount;
    float m_fSixthFloatAfterTextureCount;
    void* m_pRenderPassEntry;
};

struct NiNode_00558310
{
};
struct VObj_004b5710
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* IsSceneNode();
};
// Scans the node's children in reverse for a BSShaderPPLightingProperty, returning it if found, otherwise falling back to FindAcceptedForm.
// @fnv 0x004b5710
BSShaderPPLightingProperty* __cdecl FindPPLightingProperty(NiNode* apNode)
{
    if (!apNode->FUN_0043b480())
        return 0;
    unsigned int n = apNode->FUN_0043b480() - 1;
    while (true)
    {
        NiAVObject* pobj = apNode->GetAt(n);
        if (pobj)
        {
            NiNode* pnode = ((VObj_004b5710*)pobj)->IsSceneNode();
            if (pnode)
            {
                NiAVObject* pchild = ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((((NiNode_00558310*)pnode)))->FUN_0045bc00(0)));
                if (pchild)
                {
                    NiShadeProperty* pproperty = (NiShadeProperty*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pchild))->FUN_00a59d30(FUN_00438220())));
                    if (pproperty)
                    {
                        BSShaderPPLightingProperty* plightingProperty =
                            (BSShaderPPLightingProperty*)((pproperty == 0
                                                               ? 0
                                                               : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)pproperty)))->GetMinLevel())) >= 8 &&
                                                                  ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)pproperty)))->GetMinLevel())) <= 12))
                                                              ? pproperty
                                                              : 0);
                        if (plightingProperty)
                            return plightingProperty;
                    }
                }
            }
        }
        if (n == 0)
            break;
        n--;
    }
    return ((::BSShaderPPLightingProperty *)(::FindAcceptedForm((::FNVNode *)(apNode))));
}


// @fnv 0x004b15e0
float __cdecl FUN_004b15e0(float startAngle, float targetAngle, float* pfOutDir)
{
    float angleDelta = targetAngle - startAngle;
    *pfOutDir = 0.0f;
    if (angleDelta != ::_DAT_01012060)
    {
        *pfOutDir = 1.0f;
        if (angleDelta < ::_DAT_01012060)
        {
            if (angleDelta > DAT_0101ff58)
                *pfOutDir = -1.0f;
            else
                angleDelta += 6.2831855f;
        }
        else if (angleDelta > (double)3.1415927f)
        {
            *pfOutDir = -1.0f;
            angleDelta = 6.2831855f - angleDelta;
        }
    }
    return angleDelta;
}

struct Model
{
};
struct CtlV
{
    CtlV* GetNext();
};
struct FUN_00621b20_Class
{
    void FUN_00621b20(float);
    CtlV* GetNext();
};
// @fnv 0x004b70f0
void FUN_004b70f0(NiNode* apNode, float afPhase)
{
    if (!apNode)
        return;
    NiTimeController* pcont = (NiTimeController*)((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(((Model*)apNode)))));
    while (pcont)
    {
        ((FUN_00621b20_Class*)pcont)->FUN_00621b20(afPhase);
        pcont = (NiTimeController*)((::CtlV *)(::fnv_004a8a90::FUN_004a8a90((char *)(((FUN_00621b20_Class*)pcont)))));
    }
    unsigned int n = 0;
    for (; n < apNode->FUN_0043b480(); ++n)
    {
        NiAVObject* pobj = apNode->GetAt(n);
        if (pobj && FUN_0043b300(&(*reinterpret_cast<const ::NiRTTI *>(&::g_011f4428)), pobj))
            FUN_004b70f0((NiNode*)pobj, afPhase);
    }
}

struct NiCamera;
struct NiBoundStandIn
{
    float m_afRadius;
    float m_acCenter[3];
    NiBoundStandIn();
};
struct FUN_0098ddd0_shell
{
};
struct PackageTargetRecord
{
};
// @fnv 0x004b61d0
bool FUN_004b61d0(NiPoint3 location, NiCamera* camera, float radius)
{
    if (!camera)
        return false;
    NiBoundStandIn sphere;
    reinterpret_cast<::fnv_0098ddd0::FUN_0098ddd0_shell *>((((FUN_0098ddd0_shell*)&sphere)))->FUN_0098ddd0((void *)&(location));
    reinterpret_cast<::FUN_0063f790_shell *>((((PackageTargetRecord*)&sphere)))->FUN_0063f790(radius);
    return ::IsBoundVisible((::NiBound *)(::NiBoundStandIn *)(&sphere), camera);
}

struct _UseSaveGameBlocks;
_UseSaveGameBlocks* _UseSaveGameBlocks(const char* const*, void*);
struct PropHelper
{
};
void FUN_004b6630(NiAVObject*);
// @fnv 0x004b6630
void FUN_004b6630(NiAVObject* object)
{
    PropHelper* result = (PropHelper*)((struct _UseSaveGameBlocks *)(::FUN_00653270((const ::NiRTTI *)(const char *const *)(&(*reinterpret_cast<const char *const *>(&::g_011fa010))), (::NiObject *)(void *)(((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(3)))))));
    if (result)
        reinterpret_cast<::fnv_00b675c0::FUN_00b675c0_shell *>((result))->AssignRefObj((::fnv_00b675c0::RefObj *)(0));
    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        unsigned int i = 0;
        for (; i < node->FUN_0043b480(); ++i)
        {
            if (node->GetAt(i))
                FUN_004b6630(node->GetAt(i));
        }
    }
}

namespace fnv_004b4ea0 {
struct hkpMotion
{
};

typedef hkpMotion BSSimpleList_Ragdoll;

class TESDataHandler
{
  public:
    float FUN_004b4ea0();
};

// @fnv 0x004b4ea0
float TESDataHandler::FUN_004b4ea0()
{
    return reinterpret_cast<::MotionMassView *>((((::fnv_004b4ea0::hkpMotion *)(reinterpret_cast<::FUN_009d9f40_Class *>(this)->FUN_009d9f40()))))->FUN_00c86430();
}
}  // namespace fnv_004b4ea0

struct FUN_004b5020_shell
{
    int vftable;
    FUN_004b5020_shell* FUN_004b5020();
};

// @fnv 0x004b5020
FUN_004b5020_shell* FUN_004b5020_shell::FUN_004b5020()
{
    vftable = 0;
    return this;
}

namespace fnv_004b68a0 {


struct ArrSI
{
};

struct FUN_004b68a0_data
{
    void* field_00;
    void* field_04;
    void* field_08;
    int field_0c;
    ArrSI* field_10;
    int field_14;
    unsigned int field_18;
};

// Checks RTTI and fade-node conditions on object, resets field_14 when object matches field_10, then increments field_0c.
// @fnv 0x004b68a0
void FUN_004b68a0(ArrSI* object, FUN_004b68a0_data* data)
{
    if ((data->field_18 & 1) && FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_0126817c)), reinterpret_cast<NiAVObject*>(object)))
        return;

    if ((data->field_18 & 2) &&
        FUN_0043b300(reinterpret_cast<const NiRTTI*>(&(*reinterpret_cast<const void *const *>(&::g_011f9140))), reinterpret_cast<NiAVObject*>(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((object))->GetName())))))
        return;

    if ((data->field_18 & 2) && ((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((object))->GetName())) &&
        reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((object))->GetName())))->GetLinkToList())
            ->FUN_0043b1b0())
    {
        if (!::FUN_00408b20(reinterpret_cast<char const*>(
                              reinterpret_cast<BSFadeNode*>(
                                  reinterpret_cast<TESTopicInfoData*>(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((object))->GetName())))->GetLinkToList())
                                  ->FUN_0043b1b0()),
                          "Arrow"))
            return;
    }

    if (object == data->field_10)
        data->field_14 = data->field_0c;

    data->field_0c++;
}
}  // namespace fnv_004b68a0

struct ArrSI
{
};

struct FUN_004b6a00_data
{
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    NiAVObject* field_10;
    int field_14;
    unsigned int field_18;
};

extern const char $SG20273[];


// Checks object against data flags and RTTI, stores it in field_10 when field_0c equals field_14, then increments field_0c.
// @fnv 0x004b6a00
void __cdecl ProcessObjectMatch(NiAVObject* object, FUN_004b6a00_data* data)
{
    if (data->field_18 & 1)
    {
        if (FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_0126817c)), object))
            return;
    }

    if (data->field_18 & 2)
    {
        if (FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f9140)), reinterpret_cast<NiAVObject*>(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(object)))->GetName())))))
            return;
    }

    if (data->field_18 & 2)
    {
        if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(object)))->GetName())))
        {
            if (reinterpret_cast<BSFadeNode*>(
                    reinterpret_cast<TESTopicInfoData*>(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(object)))->GetName())))
                        ->GetLinkToList())
                    ->FUN_0043b1b0())
            {
                if (!FUN_00408b20(static_cast<char const*>(
                                      reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(
                                                                        ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(object)))->GetName())))
                                                                        ->GetLinkToList())
                                          ->FUN_0043b1b0()),
                                  $SG20273))
                    return;
            }
        }
    }

    if (data->field_0c == data->field_14)
        data->field_10 = object;

    data->field_0c++;
}

namespace fnv_004b6e90 {
class NiObject
{
};

struct A51BF0Base : NiObject
{
};

struct BSShaderLightingProperty : A51BF0Base
{
    unsigned char m_data[128];
    BSShaderLightingProperty();
};

struct NiAVObject_Attach
{
};

void AttachLightingPropertyRecursive(NiAVObject* object);

// Recursively attaches a new BSShaderLightingProperty to geometry objects lacking property 3, descending through NiNode children.
// @fnv 0x004b6e90
void AttachLightingPropertyRecursive(NiAVObject* object)
{
    if (object->GetAsNiGeometry() && !((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(3))))
    {
        BSShaderLightingProperty* lightingProperty = new BSShaderLightingProperty();
        reinterpret_cast<::FUN_00439410_cls *>((((NiAVObject_Attach*)object)))->FUN_00439410((::ArgObject *)(lightingProperty));
    }

    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        for (unsigned int index = 0; index < node->FUN_0043b480(); ++index)
        {
            NiAVObject* child = node->GetAt(index);
            if (child)
                AttachLightingPropertyRecursive(child);
        }
    }
}
}  // namespace fnv_004b6e90

struct NiAVObject_004b5b00
{
    char unk00[0x34];
    void* m_pExtraDataArray;

    void* GetExtraDataAt(unsigned short index);
};

// @fnv 0x004b5b00
void* NiAVObject_004b5b00::GetExtraDataAt(unsigned short index)
{
    return reinterpret_cast<char*>(m_pExtraDataArray) + index * 0x30;
}

class NiRTTI;

struct FixedStr6220
{
    char* m_kHandle;
    operator const char*() const;
};

class NiObj6220;
class NiObj6220
{
  public:
};

struct AnimEntry6220
{
    int unk00;
    int unk04;
};
struct AnimData6220
{
};
struct Seq6220
{
    AnimData6220* GetData();
};
struct Mgr6220
{
};

template <class T> unsigned int BSStringLength(const T*);

// Looks up the named sequence on obj's controller manager and returns the value of the first entry whose name starts with prefix, else 0.
// @fnv 0x004b6220
float GetAnimValueByPrefix(NiObj6220* obj, const char* name, const char* prefix)
{
    if (!obj)
        return 0.0f;
    Mgr6220* mgr = (Mgr6220*)((::NiObj6220 *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiObj6220 *)(((::NiObj6220 *)(::fnv_0043b230::FUN_0043b230((const char *)(obj))))))));
    if (mgr)
    {
        Seq6220* seq3 = ((::Seq6220 *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((mgr))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString(name)))));
        if (seq3)
        {
            AnimData6220* data8 = seq3->GetData();
            unsigned int aCount;
            AnimEntry6220* entries3 = ((::AnimEntry6220 *)(reinterpret_cast<::FUN_00495f30_shell *>((data8))->FUN_00495f30((int *)(unsigned int *)(&aCount))));
            unsigned int len = ::FUN_0044a670(prefix);
            if (len > 0)
            {
                for (unsigned int i4 = 0; i4 < aCount; i4++)
                {
                    const char* s4 = *((::FixedStr6220 *)(reinterpret_cast<::BaseProcess *>(&(entries3[i4]))->GetCurrentProcessData()));
                    if (s4 && !fnv::crt::strnicmp(s4, prefix, len))
                        return reinterpret_cast<::CombatTargetTimestamp *>(&(entries3[i4]))->FUN_006a7f50();
                }
            }
        }
    }
    return 0.0f;
}

struct S_004b6810_Filter
{
    int m_00;
    bool m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
};

typedef int(__cdecl* PFN_004b68a0)(S_004b6810_Filter*);

// Builds a filter struct from the flags and a2, runs FUN_00c68900 over a1, and returns the filter's m_14 result or -1.
// @fnv 0x004b6810
int __cdecl FilterByFlags(void* a1, int iValue, bool abSkipPhantoms, bool abSkipBlend, bool abSkipUnknown)
{
    S_004b6810_Filter kFilter;
    kFilter.m_08 = 0x12;
    kFilter.m_04 = true;
    kFilter.m_0c = 0;
    kFilter.m_10 = iValue;
    kFilter.m_14 = -1;
    kFilter.m_18 = 0;
    if (abSkipPhantoms)
        kFilter.m_18 |= 1;
    if (abSkipBlend)
        kFilter.m_18 |= 2;
    if (abSkipUnknown)
        kFilter.m_18 |= 4;
    ::FUN_00c68900((::S_00c68900_Node *)(a1), (::S_00c68900_Context *)(::S_004b6810_Filter *)(&kFilter), (void (*)(void *, S_00c68900_Context *))(((int (&)(S_004b6810_Filter *))::fnv_004b68a0::FUN_004b68a0)));
    return (kFilter.m_14 != -1) ? kFilter.m_14 : -1;
}


struct FUN_004b6980_Context
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    void* pUserData;
    int iCount;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};

// Builds a traversal context from the three flags, runs FUN_00c68900 over object with ProcessObjectMatch, and returns the accumulated count.
// @fnv 0x004b6980
int __cdecl FUN_004b6980(NiAVObject* object, void* auxiliaryData, bool flag1, bool flag2, bool flag3)
{
    FUN_004b6980_Context context;

    context.uiTraversalFlags = 0x12;
    context.bRecurse = true;
    context.pUserData = 0;
    context.iCount = 0;
    context.pAuxiliaryData = auxiliaryData;
    context.uiFilterFlags = 0;

    if (flag1)
    {
        context.uiFilterFlags |= 1;
    }
    if (flag2)
    {
        context.uiFilterFlags |= 2;
    }
    if (flag3)
    {
        context.uiFilterFlags |= 4;
    }

    ::FUN_00c68900((::S_00c68900_Node *)(object), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(reinterpret_cast<CollisionObjectCountContext*>(&context)), (void (*)(void *, S_00c68900_Context *))(((void (&)(NiCollisionObject *, CollisionObjectCountContext *))::ProcessObjectMatch)));

    return context.iCount;
}


// Traverses pkRoot with a context that counts collision objects and returns the auxiliary result, or -1 when it is unset.
// @fnv 0x004b6b60
int FUN_004b6b60(NiAVObject* pkRoot, void* pvUserData)
{
    CollisionObjectCountContext kContext;
    kContext.uiTraversalFlags = 0x12;
    kContext.bRecurse = true;
    kContext.iCount = 0;
    kContext.pUserData = pvUserData;
    kContext.pAuxiliaryData = reinterpret_cast<void*>(-1);
    ::FUN_00c68900((::S_00c68900_Node *)(pkRoot), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(&kContext), (void (*)(void *, S_00c68900_Context *))(((void (&)(NiCollisionObject *, CollisionObjectCountContext *))::fnv_004b6bc0::FUN_004b6bc0)));
    return (int)(std::uintptr_t)(kContext.pAuxiliaryData) != -1 ? reinterpret_cast<int>(kContext.pAuxiliaryData) : -1;
}

class FUN_004b6ce0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual FUN_004b6ce0_cls* vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void* vfn_1c();
    unsigned int FUN_0043b480();
};

class FUN_004b6ce0_gl
{
  public:
};

// @fnv 0x004b6ce0
void FUN_004b6ce0(FUN_004b6ce0_cls* p)
{
    FUN_004b6ce0_cls* RunFourthVirtual;
    FUN_004b6ce0_cls* x8;
    void* y;
    bool flag4;
    FUN_004b6ce0_cls* c;
    unsigned int i2;

    if (p == 0)
        return;
    if (p->vfn_1c() != 0)
    {
        x8 = p;
        RunFourthVirtual = ((::FUN_004b6ce0_cls *)(reinterpret_cast<::FUN_00a59d30_C *>((x8))->FUN_00a59d30(3)));
        if (RunFourthVirtual != 0)
        {
            y = ::FUN_004a2c20((::BGSTerrainManager *)(RunFourthVirtual)) ? RunFourthVirtual : 0;
            if (y != 0)
            {
                flag4 = false;
                if (((int)(reinterpret_cast<::BGSTerrainManager *>((RunFourthVirtual))->GetMinLevel())) == 3)
                    flag4 = true;
                reinterpret_cast<::FUN_004534f0_shell *>(&((*reinterpret_cast<::FUN_004b6ce0_gl *>(&::g_011e0e80))))->FUN_004534f0((std::uintptr_t)(y));
                if (flag4)
                    return;
            }
        }
    }
    else
    {
        c = p->vfn_c();
        if (c != 0)
        {
            for (i2 = 0; i2 < c->FUN_0043b480(); i2++)
                FUN_004b6ce0(((::FUN_004b6ce0_cls *)(reinterpret_cast<::NiNode *>((c))->GetAt(i2))));
        }
    }
}

struct LightingProp80
{
    LightingProp80();
    void SetShaderFlag(unsigned int, bool);
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
};

struct AVObjectEx : public NiAVObject
{
};


// Adds a LightingProp80 with shader flag 0x30 to a geometry lacking property 3, or recurses into a visual node's children.
// @fnv 0x004b6f90
void __cdecl EnsureLightingProperty(AVObjectEx* apObject)
{
    if (apObject->GetAsNiGeometry() && !((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((apObject))->FUN_00a59d30(3))))
    {
        LightingProp80* pProp = new LightingProp80;
        pProp->SetShaderFlag(0x30, true);
        reinterpret_cast<::FUN_00439410_cls *>((apObject))->FUN_00439410((::ArgObject *)(pProp));
        reinterpret_cast<::FUN_00a5a040_Class *>((apObject))->FUN_00a5a040();
        ::BSShaderManager::UpdateObjectTypeRecurse(apObject, 0, 0);
    }
    else
    {
        NiNode* pNode = apObject->GetAsNiNode();
        if (pNode && pNode->IsVisualObject())
        {
            for (unsigned int i = 0; i < pNode->FUN_0043b480(); i++)
            {
                NiAVObject* pChild = pNode->GetAt(i);
                if (pChild)
                    EnsureLightingProperty((AVObjectEx*)pChild);
            }
        }
    }
}

// Deletes each of the global objects pointed to by DAT_011c61a4 through DAT_011c6278.
// @fnv 0x004b8cf0
void __cdecl FUN_004b8cf0()
{
    delete DAT_011c61a4;
    delete DAT_011c61a8;
    delete DAT_011c61ac;
    delete DAT_011c61b0;
    delete DAT_011c61bc;
    delete DAT_011c61c0;
    delete DAT_011c61c4;
    delete DAT_011c61c8;
    delete DAT_011c61cc;
    delete DAT_011c61d0;
    delete DAT_011c61d4;
    delete DAT_011c61d8;
    delete DAT_011c61dc;
    delete DAT_011c61e0;
    delete DAT_011c61e4;
    delete DAT_011c61e8;
    delete DAT_011c61ec;
    delete DAT_011c61f0;
    delete DAT_011c61f4;
    delete DAT_011c61f8;
    delete DAT_011c61fc;
    delete (*reinterpret_cast<::NiFixedString * *>(&::DAT_011c6200));
    delete DAT_011c6204;
    delete DAT_011c6208;
    delete DAT_011c620c;
    delete DAT_011c6210;
    delete DAT_011c6214;
    delete DAT_011c6218;
    delete DAT_011c621c;
    delete DAT_011c6220;
    delete DAT_011c6224;
    delete DAT_011c6228;
    delete DAT_011c622c;
    delete DAT_011c6230;
    delete DAT_011c6234;
    delete DAT_011c6238;
    delete DAT_011c623c;
    delete DAT_011c6240;
    delete DAT_011c6244;
    delete DAT_011c6248;
    delete DAT_011c624c;
    delete DAT_011c6250;
    delete DAT_011c6254;
    delete DAT_011c6258;
    delete DAT_011c625c;
    delete DAT_011c6260;
    delete DAT_011c6264;
    delete DAT_011c6268;
    delete DAT_011c626c;
    delete DAT_011c6270;
    delete DAT_011c6274;
    delete DAT_011c6278;
}

// Maps an input byte to a fixed index via a switch, returning -1 for unmapped values.
// @fnv 0x004b1680
int MapByteToIndex(unsigned char a)
{
    switch (a)
    {
    case 21:
        return 0;
    case 24:
        return 1;
    case 25:
        return 2;
    case 27:
        return 3;
    case 28:
        return 4;
    case 29:
        return 5;
    case 30:
        return 6;
    case 31:
        return 7;
    case 50:
        return 66;
    case 46:
        return 20;
    case 32:
        return 8;
    case 33:
        return 72;
    case 34:
        return 43;
    case 35:
        return 45;
    case 36:
        return 9;
    case 37:
        return 10;
    case 40:
        return 11;
    case 41:
        return 21;
    case 42:
        return 12;
    case 43:
        return 13;
    case 44:
        return 14;
    case 45:
        return 15;
    case 20:
        return 16;
    case 19:
        return 17;
    case 47:
        return 18;
    case 52:
        return 19;
    case 18:
        return 25;
    case 91:
        return 46;
    case 13:
        return 24;
    case 39:
        return 23;
    case 38:
        return 22;
    case 74:
        return 26;
    case 75:
        return 27;
    case 76:
        return 28;
    case 77:
        return 29;
    case 78:
        return 30;
    case 48:
        return 31;
    case 79:
        return 32;
    case 51:
        return 33;
    case 81:
        return 35;
    case 22:
        return 34;
    case 23:
        return 44;
    case 4:
        return 36;
    case 82:
        return 37;
    case 5:
        return 38;
    case 85:
        return 39;
    case 86:
        return 40;
    case 87:
        return 41;
    case 97:
        return 64;
    case 88:
        return 42;
    case 94:
        return 47;
    case 95:
        return 48;
    case 71:
        return 49;
    case 73:
        return 50;
    case 93:
        return 51;
    case 7:
        return 52;
    case 12:
        return 53;
    case 11:
        return 54;
    case 9:
        return 55;
    case 8:
        return 56;
    case 49:
        return 57;
    case 53:
        return 58;
    case 54:
        return 59;
    case 14:
        return 67;
    case 102:
        return 71;
    case 16:
        return 70;
    case 103:
        return 73;
    case 104:
        return 74;
    case 106:
        return 75;
    case 107:
        return 76;
    case 114:
        return 83;
    case 108:
        return 77;
    case 109:
        return 78;
    case 110:
        return 79;
    case 111:
        return 80;
    case 112:
        return 81;
    case 113:
        return 82;
    case 115:
        return 84;
    case 116:
        return 85;
    case 117:
        return 86;
    default:
        return -1;
    }
}

struct FormName
{
    const char* name;
    int unk04;
    int unk08;
};
extern const char* DAT_01188f98;
extern const char* DAT_01188f9c;
extern const char* DAT_01188fa0;
extern const char* DAT_01188fa4;
extern const char* DAT_01188fa8;
extern const char* DAT_01188fac;
extern const char* DAT_01188fb0;
extern const char* DAT_01188fb4;
extern const char* DAT_01188fb8;
extern const char* DAT_01188fbc;
extern const char* DAT_01188fc0;
extern const char* DAT_01188fc4;
extern const char* DAT_01188fc8;
extern const char* DAT_01188fcc;
extern const char* DAT_01188fd0;
extern const char* DAT_01188fd4;
extern const char* DAT_01188fd8;
extern const char* DAT_01188fdc;
extern const char* DAT_01188fe0;
extern const char* DAT_01188fe4;
extern const char* DAT_01188fe8;
extern const char* DAT_01188fec;
extern const char* DAT_01188ff0;
extern const char* DAT_01188ff4;
extern const char* DAT_01188ff8;
extern const char* DAT_01188ffc;
extern const char* DAT_01189000;
extern const char* DAT_01189004;
extern const char* DAT_01189008;
extern const char* DAT_0118900c;
extern const char* DAT_01189010;
extern const char* DAT_01189014;
extern const char* DAT_01189018;
extern const char* DAT_0118901c;
extern const char* DAT_01189020;
extern const char* DAT_01189024;
extern const char* DAT_01189028;
extern const char* DAT_0118902c;
extern const char* DAT_01189030;
extern const char* DAT_01189034;

// Returns the type name string for a form type code, looking it up in typeNames, then a switch table, then FNV_FormTypeNames, warning on invalid codes.
// @fnv 0x004b1b60
const char* __cdecl FUN_004b1b60(unsigned char type)
{
    int index = ::MapByteToIndex(type);
    if (index >= 0)
        return ::DAT_0118a2d8[index];
    switch (type)
    {
    case 12:
        return DAT_01188f98;
    case 7:
        return DAT_01188f9c;
    case 17:
        return DAT_01188fa0;
    case 69:
        return DAT_01188fa4;
    case 57:
        return DAT_01188fa8;
    case 8:
        return DAT_01188fac;
    case 13:
        return DAT_01188fb0;
    case 6:
        return DAT_01188fb4;
    case 55:
        return DAT_01188fb8;
    case 3:
        return DAT_01188fbc;
    case 16:
        return DAT_01188fc0;
    case 65:
        return DAT_01188fc4;
    case 54:
        return DAT_01188fc8;
    case 53:
        return DAT_01188fcc;
    case 15:
        return DAT_01188fd0;
    case 71:
        return DAT_01188fd4;
    case 9:
        return DAT_01188fd8;
    case 10:
        return DAT_01188fdc;
    case 11:
        return DAT_01188fe0;
    case 58:
        return DAT_01188fe4;
    case 72:
        return DAT_01188fe8;
    case 73:
        return DAT_01188fec;
    case 49:
        return DAT_01188ff0;
    case 83:
        return DAT_01188ff4;
    case 84:
        return DAT_01188ff8;
    case 14:
        return DAT_01188ffc;
    case 102:
        return DAT_01189000;
    case 104:
        return DAT_01189004;
    case 106:
        return DAT_01189008;
    case 107:
        return DAT_0118900c;
    case 108:
        return DAT_01189010;
    case 109:
        return DAT_01189014;
    case 110:
        return DAT_01189018;
    case 111:
        return DAT_0118901c;
    case 112:
        return DAT_01189020;
    case 113:
        return DAT_01189024;
    case 114:
        return DAT_01189028;
    case 115:
        return DAT_0118902c;
    case 116:
        return DAT_01189030;
    case 117:
        return DAT_01189034;
    default:
        if (type >= 121)
        {
            ::FUN_005b5e40();
            type = 0;
        }
        return (*reinterpret_cast<FormName (*)[]>((void *)&::FNV_FormTypeNames))[type].name;
    }
}

namespace stand {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
}
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor();
};
struct NiLines : NiAVObject
{
    NiLines(unsigned short, stand::NiPoint3*, RgbaColor*, void*, void*, void*, bool*);
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
};
// Builds a 4-vertex square NiLines from four corner points at +/-extent, fills all vertex colors with color, and optionally attaches a LightingProp80.
// @fnv 0x004b3b90
NiLines* __cdecl CreateSquareLines(float extent, const RgbaColor& color, bool addLighting)
{
    stand::NiPoint3* pVertices = new stand::NiPoint3[4];
    RgbaColor* pColors = new RgbaColor[4];
    bool* pEnabled = new bool[4];
    pVertices[0] = stand::NiPoint3(-extent, -extent, 0.0f);
    pVertices[1] = stand::NiPoint3(-extent, extent, 0.0f);
    pVertices[2] = stand::NiPoint3(extent, extent, 0.0f);
    pVertices[3] = stand::NiPoint3(extent, -extent, 0.0f);
    for (int i = 0; i < 4; ++i)
    {
        pColors[i] = color;
        pEnabled[i] = true;
    }
    NiLines* lines = new NiLines(4, pVertices, pColors, 0, 0, 0, pEnabled);
    if (addLighting)
    {
        LightingProp80* property = new LightingProp80;
        reinterpret_cast<::FUN_00439410_cls *>((lines))->FUN_00439410((::ArgObject *)(property));
        ::BSShaderManager::UpdateObjectTypeRecurse((NiAVObject*)lines, 0, 0);
    }
    return lines;
}

struct AuxPoint
{
    float x, y;
    AuxPoint();
};
struct Point
{
    float x, y, z;
    Point();
    Point operator-(const Point&) const;
    Point& operator+=(const Point&);
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix();
    Matrix operator*(const Matrix&) const;
    Point FUN_004b4500(const Point*);
};
struct Transform : Matrix
{
    Point translation;
    float scale;
    Transform();
    Transform& Relative(Transform&, const Transform&);
};
struct GeometryData
{
};
struct Geometry
{
    Transform& FUN_00461130();
};
struct Entry
{
    unsigned int first, second;
    float bestDistance10;
};
struct PairMap
{
    int unk00, unk04, unk08, unk0c;
    PairMap(int);
    ~PairMap();
    void SetOrInsert(unsigned int, Entry);
};
Point FUN_004a3760(float, const Point&);
extern Geometry* DAT_011c6320;
// @fnv 0x004b3e60
bool __cdecl MatchGeometryVertices(Geometry* source, Geometry* target, float threshold, float unused, bool adjust)
{
    PairMap map30(37);
    Matrix rotation4;
    Transform aTransform;
    AuxPoint point12;
    bool bChangedB = false;
    if (!source || !target || source == target)
        return false;
    Point* sourceVertices7 = ((::Point *)(reinterpret_cast<::FUN_0049ec60 *>((source))->GetNext()));
    Point* sourceNormals2 = ((::Point *)(reinterpret_cast<::FUN_004a8030_shell *>((source))->FUN_004a8030()));
    unsigned int uiCountX = reinterpret_cast<::FUN_00456650_shell *>((source))->FUN_00456650();
    if (!sourceVertices7 || !sourceNormals2 || !uiCountX)
        return false;
    Point* targetVertices5 = ((::Point *)(reinterpret_cast<::FUN_0049ec60 *>((target))->GetNext()));
    Point* targetNormals2 = ((::Point *)(reinterpret_cast<::FUN_004a8030_shell *>((target))->FUN_004a8030()));
    unsigned int uiCountVal = reinterpret_cast<::FUN_00456650_shell *>((target))->FUN_00456650();
    if (!targetVertices5 || !targetNormals2 || !uiCountVal)
        return false;
    Point* sourcePositions = ((::Point *)(::CreateElementArray((::FUN_004b4910_Source *)(source))));
    if (!sourcePositions)
        return false;
    Point* targetVertices = ((::Point *)(::CreateElementArray((::FUN_004b4910_Source *)(target))));
    if (!targetVertices)
    {
        delete sourcePositions;
        return false;
    }
    reinterpret_cast<::NiTransform *>(&(target->FUN_00461130()))->CalculateInverse((::NiTransform &)(aTransform));
    rotation4 = (*(::Matrix *)(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(target->FUN_00461130()))->FUN_004b45b0({}))) * source->FUN_00461130();
    unsigned int best4;
    float bestDist3;
    float bestDistance10;
    float minimumVal = 3.402823466e+38F;
    for (unsigned int outer = 0; outer < uiCountVal; outer++)
    {
        best4 = uiCountX;
        bestDist3 = threshold >= 0.0 ? threshold : 3.402823466e+38F;
        for (unsigned int inner = 0; inner < uiCountX; inner++)
        {
            bestDistance10 = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::Point &)((targetVertices[outer] - sourcePositions[inner])))->ComputeMagnitude();
            if (bestDistance10 < bestDist3)
            {
                best4 = inner;
                bestDist3 = bestDistance10;
            }
            if (bestDistance10 < minimumVal)
                minimumVal = bestDistance10;
        }
        if (best4 < uiCountX)
        {
            Entry entry20;
            entry20.first = outer;
            entry20.second = uiCountVal;
            entry20.bestDistance10 = bestDist3;
            Entry existing;
            if (reinterpret_cast<::FUN_004b9b20_class *>(&(map30))->FUN_004b9b20(best4, (::FUN_004b9b20_result *)&(existing)))
            {
                if (FUN_0040eb10(entry20.bestDistance10, existing.bestDistance10, 0.001F))
                {
                    entry20.second = existing.first;
                    map30.SetOrInsert(best4, entry20);
                }
                else if (entry20.bestDistance10 < existing.bestDistance10)
                    map30.SetOrInsert(best4, entry20);
            }
            else
                map30.SetOrInsert(best4, entry20);
        }
    }
    {
        void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(map30))->GetFirstPos();
        unsigned int iCount = 0;
        unsigned int aHKey;
        Entry existing;
        while (position)
        {
            iCount++;
            reinterpret_cast<::HashTableBase *>(&(map30))->GetNextEntry((::DataBufferInfo **)&(position), (int *)&(aHKey), (::TableValue *)&(existing));
            targetNormals2[existing.first] = rotation4.FUN_004b4500(&sourceNormals2[aHKey]);
            reinterpret_cast<::FUN_004a0c10_s *>(&(targetNormals2[existing.first]))->FUN_004a0c10();
            if (existing.second < uiCountVal)
            {
                targetNormals2[existing.second] = targetNormals2[existing.first];
                iCount++;
            }
            if (adjust)
            {
                if (DAT_011c6320 != source)
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Point &)(sourceVertices7[aHKey]))->FUN_0063c8a0((void *)&(const ::Point &)(FUN_004a3760(10.0F, sourceNormals2[aHKey])));
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Point &)(targetVertices5[existing.first]))->FUN_0063c8a0((void *)&(const ::Point &)(FUN_004a3760(10.0F, targetNormals2[existing.first])));
                if (existing.second < uiCountVal)
                    targetVertices5[existing.second] = targetVertices5[existing.first];
            }
            bChangedB = true;
        }
    }
    if (bChangedB)
    {
        if (adjust)
            reinterpret_cast<::NiGeometryData *>((((::GeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(source))))))->SetDirtyFlags(3);
        reinterpret_cast<::NiGeometryData *>((((::GeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(target))))))->SetDirtyFlags(3);
    }
    if (sourcePositions)
        delete sourcePositions;
    if (targetVertices)
        delete targetVertices;
    DAT_011c6320 = source;
    return bChangedB;
}

struct FUN_004b4ee0_sub
{
};

struct FUN_004b4ee0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_004b4ee0_sub unk10;
    void FUN_004b4ee0();
};

// @fnv 0x004b4ee0
void FUN_004b4ee0_cls::FUN_004b4ee0()
{
    reinterpret_cast<::TESTopicInfo *>((((FUN_004b4ee0_sub*)((void *)((void *)&(unk10))))))->GetAddTopicList();
}

struct S4b52f0_List
{
    unsigned int FUN_0043b480();
};
struct S4b52f0_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual S4b52f0_List* vfn_0c();
};
struct S4b52f0_Ref
{
};

// Recursively picks, among an object's list children and its ref target, the one with the greatest FUN_004b5400 value; returns 0 for a null object.
// @fnv 0x004b52f0
void* __cdecl FUN_004b52f0(void* object)
{
    void* bestX;
    S4b52f0_List* list6;
    S4b52f0_Ref* ref;
    void* other;
    unsigned int count7;
    unsigned int i4;
    void* child2;
    if (object != 0)
    {
        bestX = 0;
        list6 = ((S4b52f0_Obj*)object)->vfn_0c();
        if (list6 != 0)
        {
            count7 = list6->FUN_0043b480();
            for (i4 = 0; i4 < count7; i4++)
            {
                child2 = FUN_004b52f0(((void *)(reinterpret_cast<::NiNode *>((list6))->GetAt(i4))));
                if (child2 != 0)
                {
                    if (bestX == 0 || FUN_004b5400(bestX) < FUN_004b5400(child2))
                        bestX = child2;
                }
            }
        }
        ref = ((::S4b52f0_Ref *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(object))));
        other = ref ? ((void *)(::fnv_006fa820::FUN_006fa820((const char *)(ref)))) : 0;
        if (bestX != 0 && (other == 0 || FUN_004b5400(other) < FUN_004b5400(bestX)))
        {
            return bestX;
        }
        else
        {
            return other;
        }
    }
    else
    {
        return 0;
    }
}

class NiCamera;

struct NiPlaneS
{
    float m_kNormalX;
    float m_kNormalY;
    float m_kNormalZ;
    float m_fPlaneConstant;
};

struct NiBoundS
{
    float m_fCenterX;
    float m_fCenterY;
    float m_fCenterZ;
    float m_fBoundRadius;
};

struct NiFrustumPlanesS : public NiFrustumPlanes
{
    NiFrustumPlanesS();
};

struct TimeGlobalS
{
};


static NiCamera* s_pkLastCamera;
static unsigned int s_uiLastFrame;

// @fnv 0x004b5ff0
bool __cdecl IsBoundVisible(NiBound* pkBound, NiCamera* pkCamera)
{
    if (!pkCamera)
        return false;

    static NiFrustumPlanesS g_kFrustumPlanes;

    if (s_pkLastCamera != pkCamera || s_uiLastFrame != reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal))))->FUN_00825c00())
    {
        reinterpret_cast<::SearchObject *>(&(g_kFrustumPlanes))->FUN_00a755d0((std::uintptr_t)(pkCamera));
        s_uiLastFrame = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal))))->FUN_00825c00();
        s_pkLastCamera = pkCamera;
    }

    for (unsigned int i = 0; i < 6; i++)
    {
        NiPlaneS m_kFogPlane = *((::NiPlaneS *)(reinterpret_cast<::FUN_004b4cf0_shell *>(&(g_kFrustumPlanes))->FUN_004b4cf0(i)));
        if (reinterpret_cast<::B_004b6100 *>((((NiBoundS*)pkBound)))->ClassifySphereAgainstPlane((::NiPlane_004b6100 *)(::NiPlaneS *)(&m_kFogPlane)) == 2)
            return false;
    }
    return true;
}

struct ImageSpaceEffectParam
{
    float x, y, z, w;
    ImageSpaceEffectParam(float, float, float, float);
};
class NiMemObject
{
  public:
};
class FUN_00b668b0 : public NiMemObject
{
  public:
    FUN_00b668b0();
    unsigned int vtable;
    unsigned int referenceCount;
    unsigned int flags;
    ImageSpaceEffectParam color0;
    ImageSpaceEffectParam color1;
    ImageSpaceEffectParam color2;
    ImageSpaceEffectParam color3;
    ImageSpaceEffectParam color4;
    unsigned int mode0, mode1, mode2, mode3, mode4, mode5;
};
template <> class NiPointer<FUN_00b668b0>
{
  public:
    FUN_00b668b0* m_pObject;
    NiPointer(FUN_00b668b0*);
    ~NiPointer();
    NiPointer& operator=(FUN_00b668b0*);
    operator FUN_00b668b0*() const;
};
struct Property6360
{
};
// @fnv 0x004b6360
void FUN_004b6360(NiAVObject* object, const NiPoint3* color, FUN_00b668b0* property)
{
    NiPointer<FUN_00b668b0> shared(property);
    if (!property)
    {
        shared = new FUN_00b668b0;
        property = shared;
        ((FUN_00b668b0*)shared)->color2 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color3 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color0 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color1 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->mode0 = 9;
        ((FUN_00b668b0*)shared)->mode1 = 10;
        ((FUN_00b668b0*)shared)->mode2 = 1;
        ((FUN_00b668b0*)shared)->mode3 = 4;
    }
    Property6360* material = ((::Property6360 *)(::FUN_00653270(&(*reinterpret_cast<const ::NiRTTI *>(&::g_011fa010)), (::NiObject *)(::NiProperty *)(((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(3)))))));
    if (material)
        reinterpret_cast<::fnv_00b675c0::FUN_00b675c0_shell *>((material))->AssignRefObj((::fnv_00b675c0::RefObj *)(::FUN_00b668b0 *)(shared));
    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
        {
            if (node->GetAt(i))
                FUN_004b6360(node->GetAt(i), color, property);
        }
    }
}

class FUN_004b50c0
{
  public:
    FUN_004b50c0();
    virtual ~FUN_004b50c0();
};

class FUN_004b5040 : public FUN_004b50c0
{
  public:
    FUN_004b5040(unsigned int value);
    virtual ~FUN_004b5040();
};

extern int DAT_01268124;

// Calls FUN_00c87260 with value and increments the global counter DAT_01268124.
// @fnv 0x004b5040
FUN_004b5040::FUN_004b5040(unsigned int value)
{
    reinterpret_cast<::MouseSpringOwner *>(this)->FUN_00c87260((::MouseSpringInfo *)(value));
    ++DAT_01268124;
}

class NiRTTI
{
  public:
    const char* name;
    const NiRTTI* parent;
};

struct MemoryContextScope
{
    int previous;
    __forceinline MemoryContextScope(int value)
    {
        previous = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = value;
    }
    __forceinline ~MemoryContextScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity, size, count, growBy;
};

struct __declspec(align(16)) SpringInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float pos[3];
    float unk1c;
    float vel[3];
    float unk2c;

    float damping, elasticity, maxForce, objectDamping;
};

struct MouseSpringDiagnostic
{
    void FUN_00c873d0(StrArr*);
};

static void AppendString(StrArr* strings, char*& value)
{
    unsigned int index = strings->size;
    if (index >= strings->capacity)
        reinterpret_cast<::ViewerStrings *>((strings))->SetSize(index + strings->growBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strings))->SetAt(index, value);
}

// @fnv 0x00c873d0
void MouseSpringDiagnostic::FUN_00c873d0(StrArr* strings)
{
    MemoryContextScope scope(16);
    char* str;
    reinterpret_cast<::Wrapper86b80 *>(this)->FUN_00c86b80((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(strings));
    str = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_0126812c)));
    AppendString(strings, str);
    SpringInfo info;
    info.unk00 = 0;
    info.unk04 = 0;
    for (int i = 0; i < 3; i++)
        info.pos[i] = 0;
    info.unk1c = 0;
    info.vel[0] = 0;
    info.vel[1] = 0;
    info.vel[2] = 0;
    info.unk2c = 0;
    info.damping = ::fnv_00c88020::DAT_01016248;
    info.elasticity = ::DAT_01017870;
    info.maxForce = ::DAT_0101b2d0;
    info.objectDamping = ::g_011cc6cc_arg1;
    reinterpret_cast<::FUN_00c86d20_Class *>(this)->FUN_00c86d20((::OutputData *)(::SpringInfo *)(&info));
    str = FUN_00a7d550("Damping", info.damping);
    AppendString(strings, str);
    str = FUN_00a7d550("Elasticity", info.elasticity);
    AppendString(strings, str);
    str = FUN_00a7d550("Object Damping", info.objectDamping);
    AppendString(strings, str);
    str = FUN_00a7d550("Max Force", info.maxForce);
    AppendString(strings, str);
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

struct hkMemoryAllocator
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pThreadAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pThreadAllocator;
    }
};


struct hkVector4
{
    __m128 m_vComponents;
    hkVector4()
    {}
    hkVector4(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct MouseSpringInfo
{
    int unk00;
    void* m_pkBody;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_fSpringDamping;
    float m_fSpringElasticity;
    float m_fMaxRelativeForce;
    float m_fObjectDamping;
};

struct MouseSpringAction
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;

    static void* operator new(std::size_t nbytes)
    {
        MouseSpringAction* p = (MouseSpringAction*)((hkMemoryRouterStub*)FUN_00c85750())->heap().allocateChunk(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, std::size_t nbytes);

    MouseSpringAction(const hkVector4& kPositionInRbLocal, const hkVector4& kMousePositionInWorld, float fSpringDamping,
                      float fSpringElasticity, float fObjectDamping, void* pkBody, int iUserData);

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
};

struct MouseSpringOwner_o2_nood
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void RegisterAction(struct MouseSpringAction* pkAction);
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void finish(struct MouseSpringInfo* pkInfo);
    void FUN_00c87260(MouseSpringInfo* pkInfo);
};

// @fnv 0x00c87260
void MouseSpringOwner_o2_nood::FUN_00c87260(MouseSpringInfo* pkInfo)
{
    MemContextGuard kGuard(0x10);
    MouseSpringAction* pkAction = new MouseSpringAction(
        hkVector4(pkInfo->m_f10, pkInfo->m_f14, pkInfo->m_f18, pkInfo->m_f1C),
        hkVector4(pkInfo->m_f20, pkInfo->m_f24, pkInfo->m_f28, pkInfo->m_f2C), pkInfo->m_fSpringDamping,
        pkInfo->m_fSpringElasticity, pkInfo->m_fObjectDamping, pkInfo->m_pkBody, 0);
    reinterpret_cast<::FUN_00cbb1b0_Class *>((pkAction))->FUN_00cbb1b0(pkInfo->m_fMaxRelativeForce);
    RegisterAction(pkAction);
    reinterpret_cast<::hkReferencedObjectC905 *>((pkAction))->FUN_00c905b0();
    finish(pkInfo);
}

struct BeamStage
{
};

struct NiD3DPass
{
    bool ApplyRenderStateChanges(bool);
public:
    void DestroyPass();
};

struct InBa
{
    char _0[0x1c];
    int f1c;
    char _1[0xF8];
    int f118;
};

struct OutBa
{
    char _0[0xc];
    InBa* fC;
};

// @fnv 0x00ba6240
void FUN_00ba6240(OutBa* a1)
{
    InBa* p = a1->fC;
    int cond = 0;
    if (p)
        cond = (p->f1c == 0x11);
    InBa* q = cond ? p : 0;
    if (!q)
        return;
    int b = DAT_0126f74c;
    int e = *(int*)(b + 0x24);
    int v = q->f118;
    BeamStage* s = *(BeamStage**)e;
    *(int*)((char*)s + 8) = v;
    reinterpret_cast<::E7DE90Owner *>((s))->ApplyPairToState(3);
    ((NiD3DPass*)s)->ApplyRenderStateChanges(false);
}

class NiObject;

struct NiStream
{
    NiObject* GetLoadedObject();
};

struct S86870
{
    virtual void d00() = 0;
    virtual void d01() = 0;
    virtual void d02() = 0;
    virtual void d03() = 0;
    virtual void d04() = 0;
    virtual void d05() = 0;
    virtual void d06() = 0;
    virtual void d07() = 0;
    virtual void d08() = 0;
    virtual void d09() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void d35() = 0;
    virtual void d36() = 0;
    virtual void d37() = 0;
    virtual void d38() = 0;
    virtual void d39() = 0;
    virtual void d40() = 0;
    virtual void d41() = 0;
    virtual void d42() = 0;
    virtual void d43() = 0;
    virtual void d44() = 0;
    virtual void* GetLink(char* p) = 0;
    void FUN_00c86870(NiStream* s);
};

// @fnv 0x00c86870
void S86870::FUN_00c86870(NiStream* s)
{
    char tmp;
    void* p = GetLink(&tmp);
    NiObject* o = s->GetLoadedObject();
    if (o)
        *(int*)((char*)p + 4) = *(int*)((char*)o + 8);
    reinterpret_cast<::FUN_00c87670_Class *>(this)->FUN_00c87670((*(::NiStream *)(s)));
}

template <class T> struct NiTMallocInterface
{
};

template <class T, class A> struct NiTPrimitiveArray
{
    char _0[8];
    unsigned short m_8;
    unsigned short m_kOutgoingTangent;
    unsigned short m_C;
    unsigned short m_E;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};

void FUN_00c878c0(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);

// @fnv 0x00c87be0
void FUN_00c87be0(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >* p)
{
    FUN_00c878c0(p);
    char* v = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_01268158)));
    unsigned int idx = p->m_kOutgoingTangent;
    if (idx >= p->m_8)
    {
        reinterpret_cast<::ViewerStrings *>((p))->SetSize(p->m_E + idx);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((p))->SetAt(idx, v);
}

namespace fnv_00c86790 {
struct NiStream
{
};
struct RetVal
{
    int a;
    int b;
};
struct Holder
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
    virtual RetVal* MyVirt(int*);
    void FUN_00c86790(NiStream*);
};
// @fnv 0x00c86790
void Holder::FUN_00c86790(NiStream* stream)
{
    reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
    reinterpret_cast<::FUN_00c87650_t *>(this)->LoadBinary((*(::NiStream *)(stream)));
    int tmp;
    RetVal* p = MyVirt(&tmp);
    p->b = 0;
}
}

// namespace fnv_00c86790

struct ArmTarget_S
{
    float fA;
    float fB;
    bool bActive;
};

struct ArmIKData_S
{
    char pad00[0x10];
    int iState;
    ArmTarget_S xTarget;
    char pad[0x30 - 0x20];
};

struct ArmBones_S
{
    unsigned short sUpper;
    unsigned short sFore;
    unsigned short sHand;
    bool IsValid() const
    {
        return sUpper != 0xffff && sFore != 0xffff && sHand != 0xffff;
    }
};

struct SkelHolder_S
{
    char pad[0xc];
    void* pSkeleton;
};

struct FUN_00c75460_S
{
    char pad000[0x42];
    bool bEnabled;
    char pad043[0x1a0 - 0x43];
    ArmIKData_S xArms[2];
    char pad200[0x10];
    ArmBones_S xLeft;
    ArmBones_S xRight;
    char pad21c[0x2a4 - 0x21c];
    SkelHolder_S* pHolder;
    bool FUN_00c75460();
};

// @fnv 0x00c75460
bool FUN_00c75460_S::FUN_00c75460()
{
    bool bResult = bEnabled;
    if (bResult)
    {
        void* pSkeleton = pHolder->pSkeleton;
        if (pSkeleton)
        {
            xLeft.sUpper = ::FindIndexByKey((::S_00cdd390_Table *)(pSkeleton), "Bip01 L UpperArm", (int (*)(const void *, const void *))(0));
            xLeft.sFore = ::FindIndexByKey((::S_00cdd390_Table *)(pSkeleton), "Bip01 L ForeArm", (int (*)(const void *, const void *))(0));
            xLeft.sHand = ::FindIndexByKey((::S_00cdd390_Table *)(pSkeleton), "Bip01 L Hand", (int (*)(const void *, const void *))(0));
            xRight.sUpper = ::FindIndexByKey((::S_00cdd390_Table *)(pSkeleton), "Bip01 R UpperArm", (int (*)(const void *, const void *))(0));
            xRight.sFore = ::FindIndexByKey((::S_00cdd390_Table *)(pSkeleton), "Bip01 R ForeArm", (int (*)(const void *, const void *))(0));
            xRight.sHand = ::FindIndexByKey((::S_00cdd390_Table *)(pSkeleton), "Bip01 R Hand", (int (*)(const void *, const void *))(0));
            if (!xLeft.IsValid())
                bResult = false;
            if (!xRight.IsValid())
                bResult = false;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        xArms[i].iState = 0;
        xArms[i].xTarget.fA = 0.0f;
        xArms[i].xTarget.fB = 0.0f;
        xArms[i].xTarget.bActive = false;
    }
    return bResult;
}

// @fnv 0x00ba5de0
void FUN_00ba5de0(OutBa* a1, int unused)
{
    InBa* p = a1->fC;
    int c = 0;
    if (p != 0)
    {
        c = (p->f1c == 0x11);
    }
    unsigned int mask = (c != 0) ? 0xffffffffu : 0u;
    InBa* sel = (InBa*)(mask & (unsigned int)(std::uintptr_t)p);
    int arr[8];
    arr[0] = 7;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 6;
    arr[7] = 0;
    int idx = *(int*)((char*)sel + 0x114);
    FUN_00b97e80(arr[idx - 1], 0);
}

struct CallTarget_00ba5320
{
    int FUN_00ba5320();
};

struct SearchObject_o2
{
    int FUN_00ba5ed0(unsigned int arg0);
};

// @fnv 0x00ba5ed0
int SearchObject_o2::FUN_00ba5ed0(unsigned int arg0)
{
    unsigned int callResult0 = (unsigned int)((CallTarget_00ba5320*)this)->FUN_00ba5320();
    return (int)callResult0;
}

struct S_00c85ef0_Pair
{
    int first;
    int second;
    S_00c85ef0_Pair()
    {}
};

struct S_00c85ef0_Map
{
    S_00c85ef0_Pair FindEntry(int key, int def);
};

struct S_00c85ef0_Ret
{
    __int64 v;
    S_00c85ef0_Ret(__int64 x) : v(x)
    {}
};

// @fnv 0x00c85ef0
S_00c85ef0_Ret FUN_00c85ef0(S_00c85ef0_Map* map, int key)
{
    int r = 0;
    if (map)
        r = map->FindEntry(key, 0).first;
    return S_00c85ef0_Ret(r);
}

class FUN_00c86720_base
{
  public:
    virtual void unk00();
    ~FUN_00c86720_base();
    int unk04;
};

class FUN_00c86720_o2 : public FUN_00c86720_base
{
  public:
    virtual ~FUN_00c86720_o2();
    void unk08();
};

// @fnv 0x00c86720
FUN_00c86720_o2::~FUN_00c86720_o2()
{
    reinterpret_cast<::ProjectileListener *>((this))->FUN_00c876a0();
    DAT_01268118--;
}

struct FUN_00c867d0_out
{
    void* unk00;
    void* unk04;
};

struct FUN_00c867d0_inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;
    void* unk18;
};

class FUN_00c867d0_cls
{
  public:
    void* unk00;
    void* unk04;
    FUN_00c867d0_inner* unk08;
    void FUN_00c867d0(FUN_00c867d0_out* out);
};

// @fnv 0x00c867d0
void FUN_00c867d0_cls::FUN_00c867d0(FUN_00c867d0_out* out)
{
    reinterpret_cast<::FUN_00c879e0_Class *>((this))->FUN_00c879e0((unsigned int *)(out));

    void* value;
    if (this != 0 && this->unk08 != 0)
        value = this->unk08->unk18;
    else
        value = 0;

    out->unk04 = value;
}

struct NiTStringPointerMap_00e93020
{
};

struct FUN_00c86800_Link
{
    int unk00;
    void* m04;
};

struct FUN_00c86800_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* key0C;
};

struct FUN_00c86800_Target
{
    int unk00;
    int unk04;
    void* m08;
};

struct FUN_00c86800_Table
{
    NiTStringPointerMap_00e93020* map;
};

struct FUN_00c86800_Class : S86870
{
    void FUN_00c86800(std::intptr_t a1, FUN_00c86800_Table* a2);
};

// @fnv 0x00c86800
void FUN_00c86800_Class::FUN_00c86800(std::intptr_t a1, FUN_00c86800_Table* a2)
{
    char key;
    FUN_00c86800_Link* link = (FUN_00c86800_Link*)GetLink(&key);
    FUN_00c86800_Node* node = (FUN_00c86800_Node*)link->m04;
    void* keyValue = node ? node->key0C : 0;
    FUN_00c86800_Table* table = a2;
    link->m04 = 0;
    if (keyValue != 0)
    {
        if (reinterpret_cast<::A54440Hash *>((void *)(table->map))->FUN_00a53c30((::A54440Manager *)(keyValue), (::A54440Manager **)&((void*&)a2)))
        {
            FUN_00c86800_Target* target = (FUN_00c86800_Target*)a2;
            link->m04 = target ? target->m08 : 0;
        }
    }
    reinterpret_cast<::FUN_00c87600_Obj *>(this)->FUN_00c87600((void *)(a1), table);
}

struct FUN_00c868f0_inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_18;
};

class FUN_00c868f0_cls
{
  public:
    int unk00;
    int unk04;
    FUN_00c868f0_inner* m_08;
    unsigned char FUN_00c868f0(FUN_00c868f0_cls* other);
};

// @fnv 0x00c868f0
unsigned char FUN_00c868f0_cls::FUN_00c868f0(FUN_00c868f0_cls* other)
{
    unsigned char result = reinterpret_cast<::FUN_00ba87d0_Class *>((this))->FUN_00ba87d0((::NiObj_s *)(other));
    if (result)
    {
        FUN_00c868f0_inner* l = 0;
        if (this != 0)
        {
            l = this->m_08;
        }
        void* left = l != 0 ? l->m_18 : 0;
        FUN_00c868f0_inner* r = 0;
        if (other != 0)
        {
            r = other->m_08;
        }
        void* right = r != 0 ? r->m_18 : 0;
        result = left == right;
    }
    return result;
}

inline unsigned int& currentAllocationMode()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&(*reinterpret_cast<unsigned int *>(&::g_tlsBlock))) + 0x2b4);
}

class ScopedAllocationMode
{
    unsigned int previous;

  public:
    ScopedAllocationMode() : previous(currentAllocationMode())
    {
        currentAllocationMode() = 16;
    }
    ~ScopedAllocationMode()
    {
        currentAllocationMode() = previous;
    }
};

class ObjectCandidate
{
  public:
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
    virtual int QueryValue();
    virtual void slot38();
    virtual void slot39();
    virtual void Reset();
    int unk04;
    int activeObject;
    bool FUN_00c86ab0(class Item* item);
};

class Item
{
  public:
    int unk00;
    int unk04;
    int matchingValue;
};

struct HeapContextGuard
{
    int saved;
    HeapContextGuard(int ctx)
    {
        saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = ctx;
    }
    ~HeapContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = saved;
    }
};

typedef NiTPrimitiveArray<char*, NiTMallocInterface<char*> > StringArray;

inline void AddString(StringArray* arr, char*& s)
{
    unsigned int idx = arr->m_kOutgoingTangent;
    if (idx >= arr->m_8)
        reinterpret_cast<::ViewerStrings *>((arr))->SetSize(arr->m_E + idx);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((arr))->SetAt(idx, s);
}

struct HkObject86b80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_pHkObject;
};

struct Wrapper86b80_o2
{
    int unk00;
    int unk04;
    HkObject86b80* m_pObject;

    void FUN_00c86b80(StringArray* arr);
};

// @fnv 0x00c86b80
void Wrapper86b80_o2::FUN_00c86b80(StringArray* arr)
{
    HeapContextGuard guard(0x10);
    ::FUN_00c87be0((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)this);
    char* s = ::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_0126811c)));
    AddString(arr, s);
    void* p;
    if (this && m_pObject)
        p = m_pObject->m_pHkObject;
    else
        p = 0;
    char buf[0x20];
    ::FUN_00406d00(buf, 0x20, "0x%08X", p);
    s = ::fnv_00a7d5e0::FUN_00a7d5e0("hkpRigidBody", buf);
    AddString(arr, s);
}

class FUN_00c86cb0_base
{
  public:
    virtual void unk00();
    ~FUN_00c86cb0_base();
    int unk04;
};

class FUN_00c86cb0_o2 : public FUN_00c86cb0_base
{
  public:
    virtual ~FUN_00c86cb0_o2();
    void unk08();
};

// @fnv 0x00c86cb0
FUN_00c86cb0_o2::~FUN_00c86cb0_o2()
{
    reinterpret_cast<::ProjectileListener *>((this))->FUN_00c876a0();
    DAT_01268124--;
}

struct FourFloatVector
{
    float x, y, z, w;
};

struct InnerData
{
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FourFloatVector q20;
    FourFloatVector q30;
    float x40, y44, z48, w4c;
};

struct OutputData
{
    unsigned int unk00, unk04, unk08, unk0c;
    FourFloatVector a10;
    FourFloatVector b20;
    float x30, y34, z38, w3c;
};

struct FUN_00c86d20_Class_o2
{
    int unk00, unk04;
    InnerData* inner;
    void FUN_00c86d20(OutputData* dest);
};

// @fnv 0x00c86d20
void FUN_00c86d20_Class_o2::FUN_00c86d20(OutputData* dest)
{
    reinterpret_cast<::FUN_00c867d0_cls *>((dest))->FUN_00c867d0({});
    dest->x30 = (this && inner) ? inner->x40 : 0.0f;
    dest->y34 = (this && inner) ? inner->y44 : 0.0f;
    dest->w3c = (this && inner) ? inner->w4c : 0.0f;
    if (this)
    {
        InnerData* current = inner;
        if (current)
        {
            reinterpret_cast<::S004b4db0_Quaternion *>(&(dest->a10))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(&current->q20)));
            reinterpret_cast<::S004b4db0_Quaternion *>(&(dest->b20))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(&current->q30)));
            dest->z38 = current->z48;
            return;
        }
    }
    dest->a10.x = 0.0f;
    dest->a10.y = 0.0f;
    dest->a10.z = 0.0f;
    dest->a10.w = 0.0f;
    dest->b20.x = 0.0f;
    dest->b20.y = 0.0f;
    dest->b20.z = 0.0f;
    dest->b20.w = 0.0f;
    dest->z38 = 0.0f;
}

struct FUN_00c871c0_tls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};

struct FUN_00c871c0_pool
{
};

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = (*reinterpret_cast<::FUN_00c871c0_tls *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::FUN_00c871c0_tls *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        (*reinterpret_cast<::FUN_00c871c0_tls *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

class FUN_00c871c0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    char* m_0c;
    void FUN_00c871c0(bool flag);
};

// @fnv 0x00c871c0
void FUN_00c871c0_cls::FUN_00c871c0(bool flag)
{
    TlsFlagGuard guard;
    if (flag)
    {
        char* p = m_0c;
        if (p != 0)
        {
            unsigned char len = (unsigned char)p[-1];
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00c871c0_pool *>(&::g_memoryManager))))->FUN_00aa4060((void *)((std::intptr_t)(p - len)));
        }
        m_0c = 0;
    }
}

struct BC878C0AllocTagScope
{
    int m_iSaved;

    BC878C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BC878C0AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class BC878C0StringArray
{
  public:
    virtual ~BC878C0StringArray();

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class FUN_00c878c0_cls
{
  public:
    void FUN_00c878c0(BC878C0StringArray* pkArray);
};

// @fnv 0x00c878c0
void FUN_00c878c0_cls::FUN_00c878c0(BC878C0StringArray* pkArray)
{
    BC878C0AllocTagScope kScope(0x10);
    reinterpret_cast<::fnv_00c87de0::bhkRefObject_Class *>(this)->AddDebugStrings((::ViewerStrings *)(pkArray));
    char* pcName = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268134)));
    pkArray->Add(pcName);
}

struct FUN_00c877b0_o2
{
    virtual ~FUN_00c877b0_o2();
};

struct FUN_00c87970_o2 : FUN_00c877b0_o2
{
    virtual ~FUN_00c87970_o2();
};

// @fnv 0x00c87970
FUN_00c87970_o2::~FUN_00c87970_o2()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_01268154;
}

// FUN_00ead0d0 - walks a singly linked list and returns the first node whose
// flag field is set (0 if the list ends or the head pointer is null).
// The original was written as a tail-recursive helper; MSVC's tail-call
// optimisation turns it into the loop that is actually emitted here.
struct FadeNodeEntry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FadeNodeEntry* m_pNext;  // +0x18
    int m_iFlag;             // +0x1c
};

// @fnv 0x00ead0d0
FadeNodeEntry* FUN_00ead0d0(FadeNodeEntry* pHead)
{
    if (pHead == 0)
    {
        return 0;
    }

    FadeNodeEntry* pNode = pHead->m_pNext;
    if (pNode == 0)
    {
        return 0;
    }

    if (pNode->m_iFlag != 0)
    {
        return pNode;
    }

    return FUN_00ead0d0(pNode);
}

struct InBaFull
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int f1c;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104;
    int f108;
    int f10C;
};

int __cdecl GetTableValue(int);

// @fnv 0x00ba5e60
void FUN_00ba5e60(OutBa* a1)
{
    InBaFull* p = reinterpret_cast<InBaFull*>(a1->fC);
    int bMatch = 0;
    if (p != 0)
    {
        bMatch = (p->f1c == 0x11);
    }
    InBaFull* q = bMatch ? p : 0;
    ::BSRenderStateManager::SetDepthBufferEnabled(1, (::BSRENDERSTATE_LOCK)(0));
    if (q != 0)
    {
        AddToTwoCounters(GetTableValue(q->f108), GetTableValue(q->f10C), 0);
    }
    else
    {
        AddToTwoCounters(6, 7, 0);
    }
}

struct C69EE0Properties
{
    int unk;
    int unkCur;
    int unkValue;
    unsigned int m_uiValue1;
};

static inline unsigned int C69EE0IsEnabled(NiAVObject* pkObject)
{
    C69EE0Properties* pkProps = ((::C69EE0Properties *)(::GetExtraDataChecked((::NiAVObjectX *)(pkObject))));
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}

extern void (*DAT_011afe8c)(NiCollisionObject*, CollisionObjectCountContext*);

// @fnv 0x00c69ee0
bool FUN_00c69ee0(NiAVObject* pkObject, bool bRecurse, bool bForce)
{
    bool bResult = false;
    if (pkObject && (bForce || C69EE0IsEnabled(pkObject)))
    {
        bResult = bForce;
        CollisionObjectCountContext kContext;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 1;
        if (DAT_011afe8c)
            ::FUN_00c68900((::S_00c68900_Node *)(pkObject), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(&kContext), (void (*)(void *, S_00c68900_Context *))(DAT_011afe8c));
    }
    return bResult;
}

struct StageReturn
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_uiRefCount;
    void Release()
    {
        if (--m_uiRefCount == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>(this)->FUN_00e7ecd0();
    }
};

struct StageReturnPtr
{
    StageReturn* m_pStage;
    StageReturnPtr() : m_pStage(0)
    {}
    ~StageReturnPtr()
    {
        if (m_pStage)
        {
            m_pStage->Release();
        }
    }
    operator StageReturn*&()
    {
        return m_pStage;
    }
    operator StageReturn*() const
    {
        return m_pStage;
    }
};

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

class NiD3DPixelShader : public NiRefObject
{
};

class NiD3DVertexShader : public NiRefObject
{
};

template <class T> class NiD3DPointer
{
  public:
    T* m_pObject;
    NiD3DPointer(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiD3DPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiD3DPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiD3DPointer& operator=(const NiD3DPointer& r)
    {
        return *this = r.m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct D3DRenderStateGroup
{
    void SetRenderState(unsigned int uiState, unsigned int uiValue, bool bSave);
public:
    static ::D3DRenderStateGroup *GetCurrentRenderStateGroup();
};

struct NiD3DPass_Standin : NiD3DPass
{
    virtual ~NiD3DPass_Standin();
    int unk04, unk08, unk0C, unk10;
    unsigned int m_uiStageMask;
    unsigned int m_uiNumberOfStages;
    int unk1C, unk20, unk24, unk28, unk2C;
    D3DRenderStateGroup* m_spRenderStateGroup;
    int unk34, unk38, unk3C, unk40;
    NiD3DPointer<NiD3DVertexShader> m_spVertexShaderObject;
    int unk48, unk4C, unk50, unk54, unk58;
    NiD3DPointer<NiD3DPixelShader> m_spPixelShaderObject;
    int unk60;
    int m_uiRefCount;

    unsigned int GetStageCount() const
    {
        return m_uiNumberOfStages;
    }


    void SetRenderState(unsigned int uiState, unsigned int uiValue, bool bSave)
    {
        if (!m_spRenderStateGroup)
        {
            m_spRenderStateGroup = ::D3DRenderStateGroup::GetCurrentRenderStateGroup();
        }
        reinterpret_cast<::StateGroup *>((m_spRenderStateGroup))->SetNodeValue(uiState, uiValue, bSave);
    }
};

struct NiD3DPassPtr
{
    NiD3DPass_Standin* m_pObject;
    NiD3DPassPtr() : m_pObject(0)
    {}
    ~NiD3DPassPtr()
    {
        if (m_pObject)
        {
            if (--m_pObject->m_uiRefCount == 0)
            {
                reinterpret_cast<::NiD3DPass *>((m_pObject))->DestroyPass();
            }
        }
    }
    NiD3DPassPtr& operator=(const NiD3DPassPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
            {
                if (--m_pObject->m_uiRefCount == 0)
                {
                    reinterpret_cast<::NiD3DPass *>((m_pObject))->DestroyPass();
                }
            }
            m_pObject = ptr.m_pObject;
            if (m_pObject)
            {
                ++m_pObject->m_uiRefCount;
            }
        }
        return *this;
    }
    operator NiD3DPass_Standin*() const
    {
        return m_pObject;
    }
    NiD3DPass_Standin* operator->() const
    {
        return m_pObject;
    }
};

class BeamPassShader
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70;
    NiD3DPassPtr m_spPass0;
    NiD3DPassPtr m_spPass1;
    NiD3DPointer<NiD3DPixelShader> m_spPixelShaderObject;
    NiD3DPointer<NiD3DVertexShader> m_spVertexShaderObject;

    void FUN_00ba59e0();
};

// @fnv 0x00ba59e0
void BeamPassShader::FUN_00ba59e0()
{
    NiD3DPassPtr spRenderPass;
    StageReturnPtr spStage;

    spRenderPass = m_spPass0;
    if (spRenderPass->GetStageCount() < 1)
    {
        AssignStageFromPool(spStage);
        ::ConfigureBeamStage((::BeamStage *)(StageReturn*)(spStage), 0, 1, 2, 1);
        reinterpret_cast<::StageSet *>(((spRenderPass).operator->()))->FUN_00e802b0(spRenderPass->m_uiStageMask, (::Stage321 *)(StageReturn*)(spStage));
    }
    spRenderPass->m_spPixelShaderObject = m_spPixelShaderObject;
    spRenderPass->m_spVertexShaderObject = m_spVertexShaderObject;
    spRenderPass->SetRenderState(0xa8, 0xf, true);
    spRenderPass->SetRenderState(0x1b, 1, true);
    spRenderPass->SetRenderState(0x13, 5, true);
    spRenderPass->SetRenderState(0x14, 6, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(0x34, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 0, true);

    spRenderPass = m_spPass1;
    if (spRenderPass->GetStageCount() < 1)
    {
        AssignStageFromPool(spStage);
        ::ConfigureBeamStage((::BeamStage *)(StageReturn*)(spStage), 0, 1, 2, 1);
        reinterpret_cast<::StageSet *>(((spRenderPass).operator->()))->FUN_00e802b0(spRenderPass->m_uiStageMask, (::Stage321 *)(StageReturn*)(spStage));
    }
    spRenderPass->m_spPixelShaderObject = m_spPixelShaderObject;
    spRenderPass->m_spVertexShaderObject = m_spVertexShaderObject;
    spRenderPass->SetRenderState(0xa8, 0xf, true);
    spRenderPass->SetRenderState(0x1b, 1, true);
    spRenderPass->SetRenderState(0x13, 5, true);
    spRenderPass->SetRenderState(0x14, 6, true);
    spRenderPass->SetRenderState(0xf, 0, true);
    spRenderPass->SetRenderState(0x34, 0, true);
    spRenderPass->SetRenderState(7, 1, true);
    spRenderPass->SetRenderState(0x17, 4, true);
    spRenderPass->SetRenderState(0xe, 0, true);
}

struct Vec3_o2
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float coord[3];
    };
};

struct Vec4
{
    float x, y, z, w;
};

struct Transform_o2
{
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Vec3_o2 unk24;
    float unk30;
    Vec3_o2* FUN_00524c40(Vec3_o2*, const Vec3_o2*);
};

struct Update
{
};

struct Shader
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
    virtual void apply(void*, void*, int, int, int, void*, int, Transform_o2*, void*, int, int);
};

struct Source
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
    void* unk60;
    int unk64;
    int unk68;
    bool unk6c;
    int unk70;
    int unk74;
    int unk78;
    float unk7c;
    int unk80;
    float unk84;
    int unk88;
    float unk8c;
    Vec3_o2 unk90;
    Vec3_o2 unk9c;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Vec3_o2 unkb8;
    Vec4 unkc4;
    Vec4 unkd4;
    Vec4 unke4;
    Vec4 unkf4;
    float unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    float unk130;
    float unk134;
    float unk138;
    Vec3_o2 unk13c;
    float unk148;
};

struct Arg
{
    int unk00;
    int unk04;
    int unk08;
    Source* unk0c;
};

struct Extra
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
};

struct Geom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
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
    Transform_o2 unk68;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Extra* unkb8;
    int unkbc;
};

struct Manager
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
    void* unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* unk5c;
};

struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Update* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Shader* unk30;
    Shader* unk34;
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
    void* unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    float unk84;
    float unk88;
    float unk8c;
    float unk90;
    Vec3_o2 unk94;
    int unka0;
    Vec4 unka4;
    Vec3_o2 unkb4;
    float unkc0;
    float unkc4;
    float unkc8;
    int unkcc;
    int unkd0;
    Vec3_o2 unkd4;
    Vec3_o2 unke0;
    Vec3_o2 unkec;
    float unkf8;
    Vec4 unkfc;
    Vec4 unk10c;
    Vec4 unk11c;
    void FUN_00ba5ee0(Arg*);
};

inline int isSource(Source* p)
{
    if (!p)
        return false;
    return p->unk1c == 17;
}

// @fnv 0x00ba5ee0
void Obj::FUN_00ba5ee0(Arg* arg)
{
    Geom* geom = *(*reinterpret_cast<::Geom ** *>(&::DAT_011f91e0));
    reinterpret_cast<::XRenderer *>((unk18))->FUN_00e6fbb0((*(const ::XTransform *)(&geom->unk68)), 0);
    Source* raw = arg->unk0c;
    Source* source = isSource(raw) ? raw : 0;
    if (source)
    {
        unk84 = source->unk104;
        unk88 = source->unk7c;
        unk8c = source->unk84;
        unk90 = source->unk8c;
        unkd4 = source->unk90;
        unke0 = source->unk9c;
        Vec3_o2 point = source->unk13c;
        if (!source->unk6c)
        {
            Transform_o2 transform;
            reinterpret_cast<::NiTransform *>(&(geom->unk68))->CalculateInverse((*(::NiTransform *)(&transform)));
            Vec3_o2 result;
            Vec3_o2* __restrict moved = transform.FUN_00524c40(&result, &point);
            point = *moved;
        }
        unkec.x = point.x;
        unkec.y = point.y;
        unkec.z = point.z;
        unkf8 = source->unk148;
        unkfc = source->unkc4;
        unk10c = source->unkd4;
        unk11c = source->unke4;
        unk94.x = source->unkb8.x;
        unk94.y = source->unkb8.y;
        unk94.z = source->unkb8.z;
        unka4.x = source->unkf4.x;
        unka4.y = source->unkf4.y;
        unka4.z = source->unkf4.z;
        unka4.w = source->unkf4.w;
        if (source->unk6c)
        {
            unkb4.x = geom->unk68.unk24.x;
            unkb4.y = geom->unk68.unk24.y;
            unkb4.z = geom->unk68.unk24.z;
        }
        else
        {
            unkb4.z = unkb4.y = unkb4.x = 0.0f;
        }
        unkc0 = source->unk130;
        unkc4 = 1.0f / source->unk134;
        unkc8 = 1.0f / source->unk138;
        if (!DAT_012003ec)
            DAT_012003ec = DAT_011f91c0 >= 2 ? 78 : 26;
        std::memmove(unk70, source->unk60, DAT_012003ec * 48);
    }
    void* data = geom->unk20 ? geom->unk20 : &(*reinterpret_cast<int *>(&::g_defaultBound));
    int extra = geom->unkb8->unk34;
    int other = geom->unkbc;
    if (unk30)
    {
        void* resource = ((Manager*)DAT_0126f74c)->unk44;
        if (resource)
            unk30->apply(resource, geom, other, 0, extra, arg, 0, &geom->unk68, data, 0, 1);
    }
    if (unk34)
    {
        void* resource = ((Manager*)DAT_0126f74c)->unk5c;
        if (resource)
            unk34->apply(resource, geom, other, 0, extra, arg, 0, &geom->unk68, data, 0, 1);
    }
}

struct C868_L3
{
    int unk00, unk04, unk08;
    void* m_0c;
};

struct C868_L2
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    C868_L3* m_18;
};

struct C868_Iface
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
    virtual void vfn_30(void* p);
};

extern "C" void _ReadWriteBarrier(void);

class FUN_00c868b0_cls
{
  public:
    int unk00, unk04;
    C868_L2* m_08;
    void FUN_00c868b0(C868_Iface* a1);
};

// @fnv 0x00c868b0
void FUN_00c868b0_cls::FUN_00c868b0(C868_Iface* a1)
{
    C868_L3* l3;
    if (this != 0 && m_08 != 0)
        l3 = m_08->m_18;
    else
        l3 = 0;
    _ReadWriteBarrier();

    void* z;
    if (l3 != 0)
        z = l3->m_0c;
    else
        z = 0;

    a1->vfn_30(z);
    reinterpret_cast<::BC87850RefObject *>((this))->SaveSerializeData((*(::BC87850Stream *)(a1)));
}

extern int DAT_0101ffcc;

class bhkRefObject_o2
{
  public:
};

class TESObjectDoorController
{
  public:
};

class RefObjC86D : public TESObjectDoorController
{
  public:
    int* m_vptr;
    int unk04;
    int unk08;
    int unk0C;

    __forceinline RefObjC86D()
    {
        reinterpret_cast<::FUN_00c87c30_t *>((((bhkRefObject_o2*)this)))->FUN_00c87c30();
        m_vptr = &DAT_0102016c;
        unk0C = 0;
        DAT_01268154++;
        m_vptr = &DAT_0102009c;
        DAT_01268118++;
        m_vptr = &DAT_0101ffcc;
        DAT_01268124++;
    }
};

// @fnv 0x00c86de0
RefObjC86D* __cdecl FUN_00c86de0()
{
    return new RefObjC86D;
}

void* __cdecl FUN_00aa13e0(unsigned int bytes);

extern int DAT_0101ffcc;

class AllocatedNode
{
  public:
    int* vtable;
    int unk04;
    int unk08;
    int unk0c;


    AllocatedNode()
    {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        vtable = &DAT_0102016c;
        unk0c = 0;
        ++DAT_01268154;
        vtable = &DAT_0102009c;
        ++DAT_01268118;
        vtable = &DAT_0101ffcc;
        ++DAT_01268124;
    }
};

class FUN_00c87010_cls : public FUN_00c86800_Class
{
  public:
    AllocatedNode* FUN_00c87010(FUN_00c86800_Table* p);
};

// @fnv 0x00c87010
AllocatedNode* FUN_00c87010_cls::FUN_00c87010(FUN_00c86800_Table* p)
{
    ScopedAllocationMode mode;
    FUN_00c876f0();
    AllocatedNode* node = new AllocatedNode();
    FUN_00c86800((std::intptr_t)node, p);
    FUN_00c87700();
    return node;
}

struct hkBoolS
{
    char m_cBooleanValue;
    hkBoolS(bool b)
    {
        m_cBooleanValue = b;
    }
};

struct hkOstreamS
{
    int unk00;
    int unk04;
    int unk08;
    hkOstreamS(char* buf, int size, hkBoolS isString);
    ~hkOstreamS();
    hkOstreamS& operator<<(const char* s);
};

struct hkErrorS
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int message(int type, int id, const char* desc, const char* file, int line);
};

struct hkpActionS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int m_pEntity;
};

struct hkpWorldS
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
    virtual unsigned int IsLocked();
    virtual void v38();
    virtual void AddActionPre(hkpActionS* a);
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
    virtual void AddActionPost(hkpActionS* a);
    int unk04;
    int unk08;
    int unk0c;
    unsigned char m_flags;
};

struct hkWorldHolderS
{
    int unk00;
    int unk04;
    int unk08;
    hkpWorldS* m_pOwningWorld;
};

struct bhkWorldRefS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkWorldHolderS* m_pHkObject;
};

struct bhkUnaryActionS_o2
{
    int unk00;
    int unk04;
    bhkWorldRefS* m_pWorld;
    void FUN_00c86940(hkpActionS* action);
};

// @fnv 0x00c86940
void bhkUnaryActionS_o2::FUN_00c86940(hkpActionS* action)
{
    TlsFlagGuard mode;
    hkWorldHolderS* holder = this && m_pWorld ? m_pWorld->m_pHkObject : 0;
    _ReadWriteBarrier();
    if (holder)
    {
        hkpWorldS* world = holder->m_pOwningWorld;
        if (world)
        {
            unsigned int locked = world->IsLocked();
            if (!locked && action->m_pEntity <= locked)
            {
                world->AddActionPre(action);
                if (!(world->m_flags & 0x30))
                {
                    {
                        char buf[512];
                        hkOstreamS ostr(buf, sizeof(buf), true);
                        reinterpret_cast<::SinkOwner *>((void *)&(const ::hkOstreamS &)(ostr))->FUN_00cc01c0("A unary action is being added to the world before its target entities.\n");
                        (*reinterpret_cast<::hkErrorS * *>(&::DAT_01268360))->message(
                            1, 0x234f24fc, buf, "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkUnaryAction.cpp",
                            200);
                    }
                    world->AddActionPost(action);
                }
            }
        }
    }
}

inline unsigned int GetMemContext7100()
{
    return ::currentAllocationContext;
}

inline void SetMemContext7100(unsigned int m_uiGeometryShaderFlags)
{
    ::currentAllocationContext = m_uiGeometryShaderFlags;
}

class AutoMemContext7100
{
  public:
    AutoMemContext7100(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContext7100();
        SetMemContext7100(m_uiGeometryShaderFlags);
    }
    ~AutoMemContext7100()
    {
        SetMemContext7100(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

struct MemoryManager7100
{
    void* Allocate(unsigned int uiSize);
};

class __declspec(align(16)) Aligned7100
{
  public:
    static void* operator new(std::size_t uiSize)
    {
        unsigned char* pucMem = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MemoryManager7100 *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize + 0x10);
        unsigned char ucOffset = (unsigned char)(0x10 - ((unsigned int)(std::uintptr_t)pucMem & 0xf));
        pucMem += ucOffset;
        pucMem[-1] = ucOffset;
        return pucMem;
    }
    Aligned7100() throw();
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
};

class Owner7100
{
  public:
    Aligned7100* FUN_00c87100(bool* pbCreated);

    int unk00;
    int unk04;
    int m_iActive;
    Aligned7100* m_pPointer;
};

// @fnv 0x00c87100
Aligned7100* Owner7100::FUN_00c87100(bool* pbCreated)
{
    AutoMemContext7100 kContext(0x10);
    bool bCreate = m_pPointer == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        m_pPointer = new Aligned7100;
        if (m_iActive)
            reinterpret_cast<::FUN_00c86d20_Class_o2 *>(this)->FUN_00c86d20((::OutputData *)(m_pPointer));
    }
    return m_pPointer;
}

struct TlsBlock_t
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
    unsigned int m_2b4;
};

struct TlsGuard_t
{
    unsigned int m_saved;
    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct S00c87a70_Obj : ObjectCandidate
{
    bool FUN_00c87a70(Item* arg);
};

struct PhysWorld_c87b
{
};

struct World_c87b
{
    // the Havok world pointer lives at +0x350 of the (large) world object
    PhysWorld_c87b* GetPhysWorld() const
    {
        return *(PhysWorld_c87b* const*)((const char*)this + 0x350);
    }
};

class EntityOwner_c87b
{
  public:
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
    virtual World_c87b* GetWorld();
    int unk04;
    void* m_pkEntity;

    PhysWorld_c87b* GetPhysWorld()
    {
        World_c87b* pkWorld = GetWorld();
        return pkWorld ? pkWorld->GetPhysWorld() : 0;
    }
    bool FUN_00c87b40();
};

// @fnv 0x00c87b40
bool EntityOwner_c87b::FUN_00c87b40()
{
    HeapContextGuard kContext(0x10);
    bool bResult = false;
    PhysWorld_c87b* pkPhysWorld = GetPhysWorld();
    if (pkPhysWorld)
        bResult = reinterpret_cast<::S69580_World *>((pkPhysWorld))->AddItem((::S69580_Item *)(m_pkEntity));
    return bResult;
}

struct RefCounted6b3c0
{
    virtual void slot0();
    virtual void DeleteThis();
    LONG m_iObjectReferenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
};

struct RefPtr6b3c0
{
    RefCounted6b3c0* m_p;
    RefPtr6b3c0(RefCounted6b3c0* p)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    RefPtr6b3c0(const RefPtr6b3c0& other)
    {
        m_p = other.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    __declspec(noinline) RefPtr6b3c0& operator=(const RefPtr6b3c0& other)
    {
        if (m_p != other.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = other.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
    __forceinline ~RefPtr6b3c0()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    operator RefCounted6b3c0*() const
    {
        return m_p;
    }
};

struct Entry6b3c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    RefCounted6b3c0* unk10;
      // 0xc90510
};

struct Target6b3c0
{
    void Add(Entry6b3c0* entry);  // 0xc97370
};

struct MemoryManager6b3c0
{
    void* Allocate(unsigned int size);  // 0xaa3e40
};

extern MemoryManager6b3c0 g_memoryManager6b3c0;

struct Node6b3c0
{
    RefPtr6b3c0 m_ptr;
    Node6b3c0* m_next;
    Node6b3c0(const RefPtr6b3c0& ptr) : m_ptr(ptr), m_next(0)
    {}
    static void* operator new(std::size_t size)
    {
        return g_memoryManager6b3c0.Allocate(size);
    }
};

struct RefSet6b3c0
{
    RefPtr6b3c0 m_pTileTemplate;
    Node6b3c0* m_saved;
    void Insert(const RefPtr6b3c0& ref);  // 0xc68b50
};

class World6b3c0_o2
{
  public:
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
    virtual Target6b3c0* GetTarget();  // +0x94
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int* unk2C;
    unsigned int unk30;
    int unk34;
    int unk38;
    Entry6b3c0** pending3C;
    unsigned int pendingCount40;
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
    RefSet6b3c0 refs90;

      // 0xc674d0
                                    // 0xc676e0
                                    // 0xc6aac0
                                    // 0xc67850
    void FUN_00c6b3c0(Entry6b3c0* entry);
};

// @fnv 0x00c86ab0
bool ObjectCandidate::FUN_00c86ab0(Item* item)
{
    ScopedAllocationMode guard;
    int current = this ? activeObject : 0;
    bool result = false;
    if (current != 0)
    {
        if (item)
        {
            if (QueryValue() != item->matchingValue)
            {
                Reset();
                reinterpret_cast<::bhkUnaryActionS_o2 *>(this)->FUN_00c86940((::hkpActionS *)(item));
                reinterpret_cast<::World6b3c0_o2 *>((item))->FUN_00c6b3c0((::Entry6b3c0 *)(current));
                result = true;
            }
        }
        else
        {
            Reset();
        }
    }
    return result;
}

// @fnv 0x00c87a70
bool S00c87a70_Obj::FUN_00c87a70(Item* arg)
{
    TlsGuard_t guard;
    int active = this ? activeObject : 0;
    bool result = false;
    if (active != 0)
    {
        if (arg != 0)
        {
            int v = QueryValue();
            if (v != arg->matchingValue)
            {
                Reset();
                reinterpret_cast<::World6b3c0_o2 *>((arg))->FUN_00c6b3c0((::Entry6b3c0 *)(active));
                result = true;
            }
        }
        else
        {
            Reset();
        }
    }
    return result;
}

// Defined here (as in the original unit) so the compiler sees Insert never modifies its argument.
void RefSet6b3c0::Insert(const RefPtr6b3c0& ref)
{
    if (ref.m_p == 0)
        return;
    if (m_pTileTemplate.m_p != 0)
    {
        Node6b3c0* node = new Node6b3c0(m_pTileTemplate);
        node->m_next = m_saved;
        m_saved = node;
    }
    m_pTileTemplate = ref;
}

// @fnv 0x00c6b3c0
void World6b3c0_o2::FUN_00c6b3c0(Entry6b3c0* entry)
{
    TlsFlagGuard guard;
    if (this != 0)
    {
        Target6b3c0* target = GetTarget();
        if (target != 0)
        {
            if (unk18 > 0)
            {
                if (pendingCount40 >= 100)
                {
                    if (unk30 > 0 && !(*reinterpret_cast<bool *>(&::DAT_012677a2)))
                    {
                        if (unk30 >= 3000)
                            unk30 = 3000;
                        unsigned int total = unk30;
                        unsigned int count = DAT_011afe80;
                        if (total < count)
                            count = total;
                        unsigned int rest = total - count;
                        reinterpret_cast<::S_Owner *>(this)->FUN_00c674d0((::S_Item **)(int *)(unk2C + rest), count);
                        unk30 = rest;
                        (*reinterpret_cast<bool *>(&::DAT_012677a2)) = true;
                    }
                    reinterpret_cast<::This676 *>(this)->ClearIndexedValues();
                    reinterpret_cast<::fnv_00c6aac0::FUN_00c6aac0_Owner *>(this)->FUN_00c6aac0();
                    reinterpret_cast<::FUN_00c67850_Class *>(this)->ProcessConstraints();
                }
                reinterpret_cast<::FUN_00c90510_class *>((entry))->FUN_00c90510();
                pending3C[pendingCount40] = entry;
                pendingCount40++;
            }
            else
            {
                reinterpret_cast<::hkpWorldC97 *>((target))->FUN_00c97370((::hkpActionC97 *)(entry));
            }
            if (entry != 0)
            {
                RefCounted6b3c0* obj = entry->unk10;
                if (obj != 0)
                {
                    RefPtr6b3c0 sp(obj);
                    reinterpret_cast<::CC68B50Stack *>(&(refs90))->Push((const ::CC68B50Pointer &)(sp));
                }
            }
        }
    }
}

inline void Swap86(unsigned long* p)
{
    *p = _byteswap_ulong(*p);
}

struct NiStream86
{
    char _pad[0x1e5];
    unsigned char m_bSameEndian;
};

struct Block86
{
    int m_00, m_04, m_08, m_0c;
    unsigned long m_aulData[12];
};

struct FUN_00c86790_t
{
};

class FUN_00c86e80_t
{
  public:
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
    virtual Block86* GetBlock(int* piSize);
    void FUN_00c86e80(NiStream86* pkStream);
};

// @fnv 0x00c86e80
void FUN_00c86e80_t::FUN_00c86e80(NiStream86* pkStream)
{
    reinterpret_cast<::fnv_00c86790::Holder *>((((FUN_00c86790_t*)this)))->FUN_00c86790((::fnv_00c86790::NiStream *)(pkStream));
    if (pkStream->m_bSameEndian == 1)
        return;
    int iSize;
    Block86* pkBlock = GetBlock(&iSize);
    Swap86(&pkBlock->m_aulData[0]);
    Swap86(&pkBlock->m_aulData[1]);
    Swap86(&pkBlock->m_aulData[2]);
    Swap86(&pkBlock->m_aulData[3]);
    Swap86(&pkBlock->m_aulData[4]);
    Swap86(&pkBlock->m_aulData[5]);
    Swap86(&pkBlock->m_aulData[6]);
    Swap86(&pkBlock->m_aulData[7]);
    Swap86(&pkBlock->m_aulData[8]);
    Swap86(&pkBlock->m_aulData[9]);
    Swap86(&pkBlock->m_aulData[10]);
    Swap86(&pkBlock->m_aulData[11]);
}

struct FUN_00c86f10_arg
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
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
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
    unsigned char m_1e4;
};

class FUN_00c86f10_cls
{
  public:
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void FUN_00c86f10(FUN_00c86f10_arg* a1);
};

// @fnv 0x00c86f10
void FUN_00c86f10_cls::FUN_00c86f10(FUN_00c86f10_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = vGet((unsigned char*)&tmp + 3);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
        p[14] = _byteswap_ulong(p[14]);
        p[15] = _byteswap_ulong(p[15]);
    }
    reinterpret_cast<::FUN_00c868b0_cls *>(this)->FUN_00c868b0((::C868_Iface *)(a1));
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
        p[14] = _byteswap_ulong(p[14]);
        p[15] = _byteswap_ulong(p[15]);
    }
}

void FUN_00ba6240(OutBa* a1);

void FUN_00ba5de0(OutBa* a1, int unused);

struct CallTarget_00ba5320_o2_od_oy_noo2
{
};

struct SearchObject_o2_od_oy_noo2
{
    int FUN_00ba5ed0(unsigned int arg0);
};

struct S_00c85ef0_Map_o2_od_oy_noo2
{
};

class FUN_00c86720_o2_od_oy_noo2 : public FUN_00c86720_base
{
  public:
    virtual ~FUN_00c86720_o2_od_oy_noo2();
    void unk08();
};

struct Wrapper86b80_o2_od_oy_noo2
{
    int unk00;
    int unk04;
    HkObject86b80* m_pObject;

    void FUN_00c86b80(StringArray* arr);
};

class FUN_00c86cb0_o2_od_oy_noo2 : public FUN_00c86cb0_base
{
  public:
    virtual ~FUN_00c86cb0_o2_od_oy_noo2();
    void unk08();
};

struct FUN_00c86d20_Class_o2_od_oy_noo2
{
    int unk00, unk04;
    InnerData* inner;
    void FUN_00c86d20(OutputData* dest);
};

struct FUN_00c877b0_o2_od_oy_noo2
{
    virtual ~FUN_00c877b0_o2_od_oy_noo2();
};

struct FUN_00c87970_o2_od_oy_noo2 : FUN_00c877b0_o2_od_oy_noo2
{
    virtual ~FUN_00c87970_o2_od_oy_noo2();
};

void FUN_00ba5e60(OutBa* a1);

void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);

struct Vec3_o2_od_oy_noo2
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float coord[3];
    };
};

struct Transform_o2_od_oy_noo2
{
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Vec3_o2_od_oy_noo2 unk24;
    float unk30;
};

struct Shader_o2_od_oy_noo2
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
    virtual void apply(void*, void*, int, int, int, void*, int, Transform_o2_od_oy_noo2*, void*, int, int);
};

struct Source_o2_od_oy_noo2
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
    void* unk60;
    int unk64;
    int unk68;
    bool unk6c;
    int unk70;
    int unk74;
    int unk78;
    float unk7c;
    int unk80;
    float unk84;
    int unk88;
    float unk8c;
    Vec3_o2_od_oy_noo2 unk90;
    Vec3_o2_od_oy_noo2 unk9c;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Vec3_o2_od_oy_noo2 unkb8;
    Vec4 unkc4;
    Vec4 unkd4;
    Vec4 unke4;
    Vec4 unkf4;
    float unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    float unk130;
    float unk134;
    float unk138;
    Vec3_o2_od_oy_noo2 unk13c;
    float unk148;
};

struct Arg_o2_od_oy_noo2
{
    int unk00;
    int unk04;
    int unk08;
    Source_o2_od_oy_noo2* unk0c;
};

struct Geom_o2_od_oy_noo2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* unk20;
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
    Transform_o2_od_oy_noo2 unk68;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Extra* unkb8;
    int unkbc;
};

struct Obj_o2_od_oy_noo2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Update* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Shader_o2_od_oy_noo2* unk30;
    Shader_o2_od_oy_noo2* unk34;
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
    void* unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    float unk84;
    float unk88;
    float unk8c;
    float unk90;
    Vec3_o2_od_oy_noo2 unk94;
    int unka0;
    Vec4 unka4;
    Vec3_o2_od_oy_noo2 unkb4;
    float unkc0;
    float unkc4;
    float unkc8;
    int unkcc;
    int unkd0;
    Vec3_o2_od_oy_noo2 unkd4;
    Vec3_o2_od_oy_noo2 unke0;
    Vec3_o2_od_oy_noo2 unkec;
    float unkf8;
    Vec4 unkfc;
    Vec4 unk10c;
    Vec4 unk11c;
    void FUN_00ba5ee0(Arg_o2_od_oy_noo2*);
};

inline int isSource(Source_o2_od_oy_noo2* p)
{
    if (!p)
        return false;
    return p->unk1c == 17;
}

class bhkRefObject_o2_od_oy_noo2
{
  public:
};

class RefObjC86D_o2_od_oy_noo2 : public TESObjectDoorController
{
  public:
    int* m_vptr;
    int unk04;
    int unk08;
    int unk0C;

    __forceinline RefObjC86D_o2_od_oy_noo2()
    {
        reinterpret_cast<::FUN_00c87c30_t *>((((bhkRefObject_o2_od_oy_noo2*)this)))->FUN_00c87c30();
        m_vptr = &DAT_0102016c;
        unk0C = 0;
        DAT_01268154++;
        m_vptr = &DAT_0102009c;
        DAT_01268118++;
        m_vptr = &DAT_0101ffcc;
        DAT_01268124++;
    }
};

class S004b4db0_SimdReal
{
  public:
    operator float() const;  // FUN_004586d0
    __m128 m_vValue;
};

class S004b4db0_Vector4
{
  public:
      // FUN_00458700
    __m128 m_vComponents;
};

class S004b4db0_Quaternion_o2_od_oy_noo2
{
  public:
    S004b4db0_Quaternion_o2_od_oy_noo2& FUN_004b4db0(const S004b4db0_Vector4& v);
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};

// @fnv 0x004b4db0
S004b4db0_Quaternion_o2_od_oy_noo2& S004b4db0_Quaternion_o2_od_oy_noo2::FUN_004b4db0(const S004b4db0_Vector4& v)
{
    S004b4db0_SimdReal kComponent;
    reinterpret_cast<::Holder *>((void *)&(v))->FUN_00458700((::Holder *)&kComponent, 0);
    m_fVectorY = reinterpret_cast<::S004586d0_Obj *>(&kComponent)->FUN_004586d0();
    reinterpret_cast<::Holder *>((void *)&(v))->FUN_00458700((::Holder *)&kComponent, 1);
    m_fVectorZ = reinterpret_cast<::S004586d0_Obj *>(&kComponent)->FUN_004586d0();
    reinterpret_cast<::Holder *>((void *)&(v))->FUN_00458700((::Holder *)&kComponent, 2);
    m_fScalarPart = reinterpret_cast<::S004586d0_Obj *>(&kComponent)->FUN_004586d0();
    reinterpret_cast<::Holder *>((void *)&(v))->FUN_00458700((::Holder *)&kComponent, 3);
    m_fVectorX = reinterpret_cast<::S004586d0_Obj *>(&kComponent)->FUN_004586d0();
    return *this;
}

#include "generated/data/fallout_shared/globalfunc.inc"
#include "generated/data/fallout_shared/globalfunc_o2_variant.inc"
