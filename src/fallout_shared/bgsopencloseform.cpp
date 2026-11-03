// fallout_shared/bgsopencloseform.cpp: BGSOpenCloseForm, AIThreadManager (8 functions)

#include <cstdint>
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
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00518080_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/fnv_0087b140__FUN_0087b140_Holder.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_011c4000.h"

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
                    reinterpret_cast<::FUN_00a59c60_cls *>((ref->GetNiNode_v()))->FUN_00a59c60((std::intptr_t)&(data));
                    controller->StopSequence(inactive, 0.0f);
                    reinterpret_cast<::fnv_00578a30::Thing *>((ref))->FUN_00578a30((std::intptr_t)((*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(active))->GetLinkToList())).m_kHandle));
                    ::FUN_00c6bd00((::TreeNode_cls *)(::NiNode *)(ref->GetNiNode_v()), true);
                }
                else
                {
                    controller->StopSequence(inactive, 0.0f);
                    controller->ActivateControllerSequence(active, 0, false, 1.0f, 0.0f, 0);
                    reinterpret_cast<::FUN_0098adb0_shell *>((active))->FUN_0098adb0(-DAT_0101ab70);
                    NiUpdateData data(reinterpret_cast<::FUN_00759450_shell *>((active))->FUN_00759450(), true, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((ref->GetNiNode_v()))->FUN_00a59c60((std::intptr_t)&(data));
                }
                result = true;
            }
        }
        else
        {
            if (open)
                reinterpret_cast<::fnv_00578a30::Thing *>((ref))->FUN_00578a30((std::intptr_t)(DAT_01011f30));
            else
                reinterpret_cast<::fnv_00578a30::Thing *>((ref))->FUN_00578a30((std::intptr_t)(g_011d22b0_arg1));
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

class ExtraDataList_r0047a560
{
  public:
};

class CtlV;

class NiAVObject;

class ModelOps;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class RefV
{
  public:
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void v048(unsigned int);
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual bool v100();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual ModelOps* v1d0();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual NiPoint3* v1f4();
};

class ModelOps
{
  public:
};

class MgrX
{
  public:
};

class SeqX
{
  public:
    void FUN_0098adb0(float);
};

class DoorX
{
  public:
};

class Door2
{
  public:
};

class SoundH
{
  public:
};

class BSAudio;

class BSAudioSoundHandle;

class BSAudioS_
{
  public:
};

class BSAudio2
{
  public:
};

class TaskQ2
{
  public:
};

class RefX
{
  public:
};

class OCF
{
  public:
    virtual void v0(TESObjectREFR*, TESObjectREFR*);
    virtual void v1(TESObjectREFR*, TESObjectREFR*);
    virtual bool v2();
};

class FUN_00572d50_shell_ctxr
{
  public:
    void FUN_00572d50(int);
};

class FUN_00572db0_shell_ctxr
{
  public:
    void FUN_00572db0(int);
};

struct TSETTING_VALUE
{
    unsigned char b;
};

class SettingX
{
  public:
    TSETTING_VALUE* Bool();
};

class BSAudioSoundHandle
{
  public:
    int m0;
    unsigned char m4;
    int m8;
    BSAudioSoundHandle();
    ~BSAudioSoundHandle();
};

NiFixedString& FUN_0047a500();

NiFixedString& FUN_0047a510();

// @fnv 0x0047a560
void FUN_0047a560(TESObjectREFR* apRefr, TESObjectREFR* apActor, BGSOpenCloseForm* apForm)
{
    if (!apRefr)
        return;
    bool bFlag = false;
    if (((RefV*)apRefr)->v1d0())
    {
        if (((::CtlV *)(::fnv_0043b230::FUN_0043b230((const char *)(((RefV*)apRefr)->v1d0())))))
        {
            CtlV* p3d = ((::CtlV *)(::fnv_0043b230::FUN_0043b230((const char *)(((RefV*)apRefr)->v1d0()))));
            NiAVObject* pAV = (NiAVObject*)((::SkyShaderProperty *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiProperty *)((NiProperty*)p3d))));
            if (pAV)
            {
                NiControllerSequence* pSeqA = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((((MgrX*)pAV)))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(FUN_0047a500()))));
                NiControllerSequence* pSeqB = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((((MgrX*)pAV)))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(FUN_0047a510()))));
                if (pSeqA && pSeqB)
                {
                    bFlag = true;
                    if (((int)(reinterpret_cast<::LowProcess *>((((SeqX*)pSeqA)))->GetActiveCombatTarget())) != 1 && ((int)(reinterpret_cast<::LowProcess *>((((SeqX*)pSeqB)))->GetActiveCombatTarget())) != 1)
                    {
                        NiControllerSequence* p2c;
                        SoundH* p28 = 0;
                        TESObjectDOOR* pPathNodeDoor = dynamic_cast<TESObjectDOOR*>(apForm);
                        if (!reinterpret_cast<::fnv_00572d30::FUN_00572d30_shell *>((apRefr))->FUN_00572d30((*(int *)&(const ::OBJECT_ACTION &)(ACTION_OPEN))))
                        {
                            if (pPathNodeDoor)
                                p28 = (SoundH*)((void *)(reinterpret_cast<::FUN_00407820_shell *>((((DoorX*)pPathNodeDoor)))->FUN_00407820()));
                            p2c = pSeqA;
                            ((FUN_00572d50_shell_ctxr*)apRefr)->FUN_00572d50(4);
                        }
                        else
                        {
                            if (pPathNodeDoor)
                                p28 = (SoundH*)reinterpret_cast<::TESPackage *>((((DoorX*)pPathNodeDoor)))->GetRefCount();
                            p2c = pSeqB;
                            ((FUN_00572db0_shell_ctxr*)apRefr)->FUN_00572db0(4);
                        }
                        if (!((SettingX*)&(*reinterpret_cast<::SettingX *>(&::g_011c4c64)))->Bool()->b && apActor && ((RefV*)apActor)->v100() &&
                            apActor != (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)) && ((RefV*)apRefr)->v1d0())
                        {
                            bool bSkip = true;
                            if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRefr))->FUN_007af430()))->GetFormType() == ENUM_FORM_ID_DOOR_ID)
                            {
                                TESBoundObject* pObj = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRefr))->FUN_007af430()));
                                if (reinterpret_cast<::FUN_00518080_shell *>((((Door2*)pObj)))->FUN_00518080())
                                    bSkip = false;
                            }
                            if (bSkip)
                            {
                                void* pNi = ((RefV*)apRefr)->v1d0();
                                if (FUN_008c7aa0())
                                {
                                    reinterpret_cast<::fnv_0087b140::FUN_0087b140_Holder *>((((TaskQ2*)TaskQueueInterface::GetSingleton())))->QueueTaskIfPresent((::fnv_0087b140::G00559a40 *)(pNi));
                                }
                                else
                                {
                                    ::FUN_00c6a270((std::intptr_t)((NiAVObject*)pNi), 1, 1, 0);
                                    ::FUN_00c69ee0((::NiAVObject *)(pNi), 1, 1);
                                }
                            }
                        }
                        reinterpret_cast<::TaskQueueInterface *>((((MgrX*)pAV)))->QueueReferenceStateTask(true);
                        reinterpret_cast<::NiControllerManager *>((((MgrX*)pAV)))->ActivateControllerSequence(p2c, 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                        reinterpret_cast<::FUN_0098adb0_shell *>((p2c))->FUN_0098adb0(-DAT_0101ab70);
                        if (p28)
                        {
                            BSAudioSoundHandle h;
                            if (apActor == (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))
                            {
                                auto kHandle = reinterpret_cast<::FUN_00ad73b0_t *>((((BSAudio2*)::FUN_00453a70())))->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p28))->FUN_0084e3a0())), {});
                                reinterpret_cast<::SoundPlaybackHandle *>(&(h))->operator=((*(const ::SoundPlaybackHandle *)(&kHandle)));
                            }
                            else
                            {
                                auto kHandle = reinterpret_cast<::FUN_00ad73b0_t *>((((BSAudio2*)::FUN_00453a70())))->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p28))->FUN_0084e3a0())), {});
                                reinterpret_cast<::SoundPlaybackHandle *>(&(h))->operator=((*(const ::SoundPlaybackHandle *)(&kHandle)));
                                NiPoint3 pt = *((RefV*)apRefr)->v1f4();
                                reinterpret_cast<::FUN_00ad8b60_h *>(&(h))->FUN_00ad8b60(pt.x, pt.y, pt.z);
                            }
                            reinterpret_cast<::FUN_00ad8830_shell *>(&(h))->FUN_00ad8830(false);
                        }
                        reinterpret_cast<::FUN_0041e690 *>((((ExtraDataList_r0047a560*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((apRefr))->FUN_005d43c0())))))->SetLinkedReference(apActor);
                        ((RefV*)apRefr)->v048(0x80000000u);
                        if (p2c == pSeqA && apActor == (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))
                        {
                            OCF* pOCF = ((::OCF *)(::GetOpenCloseForm((::TESForm *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRefr))->FUN_007af430()))))));
                            if (pOCF && pOCF->v2())
                                reinterpret_cast<::C47AAF0Player *>((((RefX*)(*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))))->SetQuickKeysEnabled(1);
                        }
                    }
                }
            }
        }
    }
    if (!bFlag)
    {
        bool bOpen = false;
        switch (BGSOpenCloseForm::GetOpenState(apRefr))
        {
        case BGSOpenCloseForm::OPEN:
        case BGSOpenCloseForm::OPENING:
            ((FUN_00572db0_shell_ctxr*)apRefr)->FUN_00572db0(4);
            break;
        default:
            bOpen = true;
            ((FUN_00572d50_shell_ctxr*)apRefr)->FUN_00572d50(4);
            break;
        }
        OCF* pOCF2 = ((::OCF *)(::GetOpenCloseForm((::TESForm *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRefr))->FUN_007af430()))))));
        if (pOCF2)
        {
            if (bOpen)
                pOCF2->v0(apRefr, apActor);
            else
                pOCF2->v1(apRefr, apActor);
        }
    }
}

#include "generated/data/fallout_shared/bgsopencloseform.inc"
