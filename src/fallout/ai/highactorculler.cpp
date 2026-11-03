// fallout/ai/highactorculler.cpp: HighActorCuller (1 function)

#include <cstdint>
#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00819a50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_009d9f20__FUN_009d9f20_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_011de000.h"
#include "highactorculler_decls.h"

// @fnv 0x008d6d40
void HighActorCuller::Operate(MobileObject* mobile)
{
    NiAVObject* object = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((mobile))->FUN_0043fcd0()));
    if (object)
    {
        m_kFadeNodeCuller.Process(object);
        BSFadeNode* fade = object->GetFadeNode();
        if (fade && !fade->FUN_00552470())
        {
            NiBound bound = (*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(fade))->FUN_0043d450()));
            m_spMultiBoundSphere->SetGridPosition((*(const ::NiPoint3 *)(((::Vec3 *)(void *)&(bound)))));
            reinterpret_cast<::FUN_00819a50_shell *>(((m_spMultiBoundSphere).operator->()))->FUN_00819a50(reinterpret_cast<::Twin_0084d030 *>((void *)&(bound))->GetStoredFloatValue());
            BSPortalGraph* graph = 0;
            if (((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetPrevPath())))
                graph = ((::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((static_cast<HighActorCullerCell*>(((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetPrevPath())))))->FUN_009d9f20()));
            else if (((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetHitSound())))
                graph = ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetHitSound()))->FUN_006698d0();
            if (graph)
            {
                NiTPointerList<BSOcclusionPlane*>& occluders = (*(::NiTPointerList< ::BSOcclusionPlane *> *)(reinterpret_cast<::TESTopicInfoData *>((graph))->GetLinkToList()));
                void* position = ((void *)(::FUN_00559450((int *)&(occluders))));
                while (position)
                {
                    BSOcclusionPlane* plane = ((::BSOcclusionPlane *)(reinterpret_cast<::ListStandIn *>(&(occluders))->FUN_0057cbe0((int **)&(position))));
                    if (plane && ((intptr_t)(reinterpret_cast<::LowProcess *>((void *)(plane))->GetTarget())) == 1)
                    {
                        if (!m_pMultiBoundNode->CheckProcStateAndPlane(((const ::NiCamera *)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)&(m_kFadeNodeCuller))->FUN_0084e3a0()))->FUN_0045bb80(),
                                                                       m_kFadeNodeCuller, plane))
                            reinterpret_cast<::TaskQueueInterface *>((fade))->SetTaskFlag_008d6f10(true);
                    }
                }
            }
        }
    }
}
