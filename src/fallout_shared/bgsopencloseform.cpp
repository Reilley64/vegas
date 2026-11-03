// fallout_shared/bgsopencloseform.cpp: BGSOpenCloseForm, AIThreadManager (8 functions)

#include <cstring>
#include "fnv/decl/C47AAF0Player.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0041e660_class.h"
#include "fnv/decl/FUN_0041e690.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00572d50_shell.h"
#include "fnv/decl/FUN_00572db0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006c0f10_shell.h"
#include "fnv/decl/FUN_0087b540_Holder.h"
#include "fnv/decl/FUN_0087b600_Holder.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/Holder87b580.h"
#include "fnv/decl/ObstMgr0dc0.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/fnv_0041d490__FUN_0041d490_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_00572d30__FUN_00572d30_shell.h"
#include "fnv/decl/fnv_00578a30__Thing.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_0047b000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00c6b000.h"
#include "fnv/symbols_011d7000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "bgsopencloseform_packet_decls.h"

// @fnv 0x0047a490
bool BGSOpenCloseForm::HasOpenCloseComponent(TESForm* apForm)
{
    bool bResult = false;
    bool bIsActivatorForm = false;
    if (apForm)
    {
        switch (apForm->GetFormType())
        {
        case ENUM_FORM_ID_ACTI_ID:
        case ENUM_FORM_ID_TERM_ID:
        case ENUM_FORM_ID_CONT_ID:
        case ENUM_FORM_ID_DOOR_ID:
            bResult = true;
            break;
        case ENUM_FORM_ID_TACT_ID:
        case ENUM_FORM_ID_FLOR_ID:
        case ENUM_FORM_ID_FURN_ID:
            bIsActivatorForm = true;
            break;
        default:
            break;
        }
    }
    return bResult;
}

// @fnv 0x0047b250
BGSOpenCloseForm::OPEN_STATE BGSOpenCloseForm::GetOpenState(TESObjectREFR* ref)
{
    // Local names preserve MSVC9 stack allocation order.
    OPEN_STATE eState = CLOSED_UNKNOWN;
    if (ref && HasOpenCloseComponent(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))))
    {
        bool pManager = reinterpret_cast<::fnv_00572d30::FUN_00572d30_shell *>((ref))->FUN_00572d30((*(int *)&(const ::OBJECT_ACTION &)(ACTION_OPEN)));  // Saved open action flag.
        if (pManager)
            eState = OPEN;
        else
            eState = CLOSED;
        NiNode* pController = ref->GetNiNode_v();                                   // Reference scene node.
        NiTimeController* pNode = pController ? ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(pController)))) : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* bOpen = (NiControllerManager*)((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiProperty *)((NiProperty*)pNode))));
        if (bOpen)
        {
            NiControllerSequence* pOpenSequence = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((bOpen))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(*TESObjectDOOR::GetOpenSequenceName()))));
            NiControllerSequence* pCloseSequence =
                ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((bOpen))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(*NiControllerManager::FindSequenceByName()))));
            if (pOpenSequence && pCloseSequence)
            {
                if (((LowProcess*)pOpenSequence)->GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = OPENING;
                else if (((LowProcess*)pCloseSequence)->GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = CLOSING;
            }
        }
    }
    return eState;
}

struct FUN_00759450_shell : public NiControllerSequence
{
    float FUN_00759450();
};

// @fnv 0x00759450
float FUN_00759450_shell::FUN_00759450()
{
    return *(float*)((char*)this + 0x2c);
}

struct FUN_0098adb0_shell : public NiControllerSequence
{
    void FUN_0098adb0(float);
};
// @fnv 0x0047aec0
bool BGSOpenCloseForm::SetOpenState(TESObjectREFR* ref, bool open, bool immediate)
{
    bool result = false;
    if (ref && HasOpenCloseComponent(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))))
    {
        if (::FUN_008c7aa0() && ref != ((::TESObjectREFR *)(::FUN_0047b200())))
        {
            reinterpret_cast<::FUN_0087b600_Holder *>((TaskQueueInterface::GetSingleton()))->FUN_0087b600((int)(ref), open, immediate);
            return true;
        }
        if (open)
            reinterpret_cast<::FUN_00572d50_shell *>((ref))->FUN_00572d50((*(int *)&(const ::OBJECT_ACTION &)(ACTION_OPEN)));
        else
            reinterpret_cast<::FUN_00572db0_shell *>((ref))->FUN_00572db0((*(int *)&(const ::OBJECT_ACTION &)(ACTION_OPEN)));
        NiNode* node = ref->GetNiNode_v();
        NiTimeController* manager = node ? ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(node)))) : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* controller = (NiControllerManager*)((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiProperty *)((NiProperty*)manager))));
        if (controller)
        {
            NiControllerSequence* active = 0;
            NiControllerSequence* inactive = 0;
            NiControllerSequence* opening = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((controller))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(*TESObjectDOOR::GetOpenSequenceName()))));
            NiControllerSequence* closing = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((controller))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(*NiControllerManager::FindSequenceByName()))));
            if (opening && closing)
            {
                if (open)
                {
                    active = opening;
                    inactive = closing;
                }
                else
                {
                    active = closing;
                    inactive = opening;
                }
                reinterpret_cast<::TaskQueueInterface *>((controller))->QueueReferenceStateTask(true);
                if (immediate)
                {
                    reinterpret_cast<::fnv_0041d490::FUN_0041d490_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->UpdateRagDoll(0);
                    controller->StopSequence(active, 0.0f);
                    controller->ActivateControllerSequence(inactive, 0, false, 1.0f, 0.0f, 0);
                    reinterpret_cast<::FUN_0098adb0_shell *>((inactive))->FUN_0098adb0(-DAT_0101ab70);
                    NiUpdateData data(reinterpret_cast<::FUN_00759450_shell *>((inactive))->FUN_00759450(), true, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((ref->GetNiNode_v()))->FUN_00a59c60((int)&(data));
                    controller->StopSequence(inactive, 0.0f);
                    reinterpret_cast<::fnv_00578a30::Thing *>((ref))->FUN_00578a30((int)((*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(active))->GetLinkToList()))));
                    ::FUN_00c6bd00((::TreeNode_cls *)(::NiNode *)(ref->GetNiNode_v()), true);
                }
                else
                {
                    controller->StopSequence(inactive, 0.0f);
                    controller->ActivateControllerSequence(active, 0, false, 1.0f, 0.0f, 0);
                    reinterpret_cast<::FUN_0098adb0_shell *>((active))->FUN_0098adb0(-DAT_0101ab70);
                    NiUpdateData data(reinterpret_cast<::FUN_00759450_shell *>((active))->FUN_00759450(), true, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((ref->GetNiNode_v()))->FUN_00a59c60((int)&(data));
                }
                result = true;
            }
        }
        else
        {
            if (open)
                reinterpret_cast<::fnv_00578a30::Thing *>((ref))->FUN_00578a30((int)(DAT_01011f30));
            else
                reinterpret_cast<::fnv_00578a30::Thing *>((ref))->FUN_00578a30((int)(g_011d22b0_arg1));
        }
        if (immediate && *((ProcessLists*)&g_011d7188)->GetLifeStateControlFlag() &&
            ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->GetFormType() == ENUM_FORM_ID_DOOR_ID && ref->GetNiNode_v() &&
            !ref->GetExtraRadioData())
        {
            if (open)
                reinterpret_cast<::ObstMgr0dc0 *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0dc0(ref);
            else
                reinterpret_cast<::FUN_006c0f10_shell *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->UpdateDoorObstacle(ref);
        }
    }
    return result;
}

// @fnv 0x0098adb0
void FUN_0098adb0_shell::FUN_0098adb0(float afValue)
{
    *(float*)((char*)this + 0x48) = afValue;
}

extern NiFixedString* DAT_011c61c4;

// @fnv 0x005c1490
NiFixedString* __cdecl FUN_005c1490()
{
    return DAT_011c61c4;
}

class TESObjectACTI
{
};
class TESObjectCONT
{
};

// @fnv 0x0047a3a0
BGSOpenCloseForm* GetOpenCloseForm(TESForm* apForm)
{
    BGSOpenCloseForm* pOpenCloseForm = 0;

    if (apForm && BGSOpenCloseForm::HasOpenCloseComponent(apForm))
    {
        switch (apForm->GetFormType())
        {
        case 0x15:
        case 0x17: {
            TESObjectACTI* pObject = reinterpret_cast<TESObjectACTI*>(apForm);
            pOpenCloseForm = pObject ? reinterpret_cast<BGSOpenCloseForm*>(reinterpret_cast<char*>(pObject) + 0x70) : 0;
            break;
        }

        case 0x1c: {
            TESObjectDOOR* pObject = reinterpret_cast<TESObjectDOOR*>(apForm);
            pOpenCloseForm = pObject ? reinterpret_cast<BGSOpenCloseForm*>(reinterpret_cast<char*>(pObject) + 0x70) : 0;
            break;
        }

        case 0x1b: {
            TESObjectCONT* pObject = reinterpret_cast<TESObjectCONT*>(apForm);
            pOpenCloseForm = pObject ? reinterpret_cast<BGSOpenCloseForm*>(reinterpret_cast<char*>(pObject) + 0x84) : 0;
            break;
        }
        }
    }

    return pOpenCloseForm;
}

struct EventString
{
    operator const char*() const;
};
struct SequenceEvent
{
};
struct Ref;
struct EventExtra
{
};
struct BaseForm
{
    unsigned int FormType();
};
struct Ref
{
};
struct OpenCloseHandler
{
    virtual void Open(Ref*, Ref*);
    virtual void Close(Ref*, Ref*);
    virtual bool IsSpecial();
};
struct EventSetting
{
    unsigned char* Bool();
};
struct EventQueue
{
    void Open(Ref*);
    void Close(Ref*);
};
struct ObstacleManager
{
    void Open(Ref*);
    void Close(Ref*);
};
// @fnv 0x0047ac70
void __cdecl ProcessOpenCloseEvent(Ref* ref, SequenceEvent* sequence)
{
    bool handled = false;
    if (ref && sequence)
    {
        handled = ::FUN_0047ab40((::Ref_47ab40 *)(ref), (::NamedObject_47ab40 *)(sequence));
        if (!std::strcmp((*(::EventString *)(reinterpret_cast<::TESTopicInfoData *>((sequence))->GetLinkToList())), "Open"))
        {
            handled = true;
            ::FUN_005ac750((::TESForm *)(ref), (::ExtraDataList *)(::EventExtra *)(((::EventExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))), 0x10000);
            Ref* openTarget = ((::Ref *)(reinterpret_cast<::FUN_0041e660_class *>((((::EventExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041e660()));
            if (openTarget)
            {
                OpenCloseHandler* openHandler = ((::OpenCloseHandler *)(::GetOpenCloseForm((::TESForm *)(::BaseForm *)(((::BaseForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))))));
                if (openHandler)
                    openHandler->Open(ref, openTarget);
                reinterpret_cast<::FUN_0041e690 *>((((::EventExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->SetLinkedReference((::TESObjectREFR *)(::Ref *)(0));
                if (openTarget == (*reinterpret_cast<::Ref * *>(&::_g_thePlayer)) && openHandler && openHandler->IsSpecial())
                    reinterpret_cast<::C47AAF0Player *>(((*reinterpret_cast<::Ref * *>(&::_g_thePlayer))))->SetQuickKeysEnabled(false);
            }
            if (*(*reinterpret_cast<::EventSetting *>(&::g_011d7188)).Bool() && ((::BaseForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FormType() == 28)
            {
                if (::FUN_008c7aa0())
                    reinterpret_cast<::FUN_0087b540_Holder *>((((::EventQueue *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b540((int)(ref));
                else
                    reinterpret_cast<::ObstMgr0dc0 *>((((::ObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0dc0((::TESObjectREFR *)(ref));
            }
        }
        else if (!std::strcmp((*(::EventString *)(reinterpret_cast<::TESTopicInfoData *>((sequence))->GetLinkToList())), "Close"))
        {
            handled = true;
            ::FUN_005ac750((::TESForm *)(ref), (::ExtraDataList *)(::EventExtra *)(((::EventExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))), 0x20000);
            Ref* closeTarget = ((::Ref *)(reinterpret_cast<::FUN_0041e660_class *>((((::EventExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041e660()));
            if (closeTarget)
            {
                OpenCloseHandler* closeHandler = ((::OpenCloseHandler *)(::GetOpenCloseForm((::TESForm *)(::BaseForm *)(((::BaseForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))))));
                if (closeHandler)
                    closeHandler->Close(ref, closeTarget);
                reinterpret_cast<::FUN_0041e690 *>((((::EventExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->SetLinkedReference((::TESObjectREFR *)(::Ref *)(0));
            }
            if (*(*reinterpret_cast<::EventSetting *>(&::g_011d7188)).Bool() && ((::BaseForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FormType() == 28)
            {
                if (::FUN_008c7aa0())
                    reinterpret_cast<::Holder87b580 *>((((::EventQueue *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b580((int)(ref));
                else
                    reinterpret_cast<::FUN_006c0f10_shell *>((((::ObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->UpdateDoorObstacle((::TESObjectREFR *)(ref));
            }
        }
    }
}
