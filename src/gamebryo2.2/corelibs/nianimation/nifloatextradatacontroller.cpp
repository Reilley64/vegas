// gamebryo2.2/corelibs/nianimation/nifloatextradatacontroller.cpp: NiFloatExtraDataController (9 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a38e00.h"
#include "fnv/decl/FUN_00a3c500_shell.h"
#include "fnv/decl/FUN_00a57630.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/NiTimeControllerA362.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a57000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_01097000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f3000.h"
#include "nifloatextradatacontroller_decls.h"

// @fnv 0x00a41300
void NiFloatExtraDataController::Update(NiUpdateData& update)
{
    if (GetManagerControlled())
        m_fControllerTime = DAT_01096324;
    else if (reinterpret_cast<::NiTimeControllerA362 *>(this)->FUN_00a36250(update.GetTime()))
    {
        if (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->Unk_35())
            return;
    }

    float value;
    if (m_spControllerInterpolator.m_pObject &&
        m_spControllerInterpolator.m_pObject->Unk_27(m_fControllerTime, m_pkTarget, value))
    {
        if (m_pExtraData.m_pObject)
            static_cast<NiFloatExtraData*>(m_pExtraData.m_pObject)->m_fValue = value;
    }
}

class NiObject;
struct NiStream
{
public:
    ::NiObject *GetLoadedObject();
};

struct NiPSysModifierCtlr
{
    void LoadBinary(NiStream&);
};

// @fnv 0x00a4fbd0
void LoadBinaryWithVersionCheck(NiPSysModifierCtlr* pThis, int, NiStream& kStream)
{
    pThis->LoadBinary(kStream);
    if (*(unsigned int*)((char*)&kStream + 0xd8) < 0x0a010068)
    {
        reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    }
}

extern int DAT_0109aa14;

struct NiTimeController_Call
{
};

// @fnv 0x00a572a0
int* InitTimeController(int* pThis)
{
    new ((void *)(reinterpret_cast<NiTimeController_Call*>(pThis))) ::FUN_00a38e00();
    pThis[0] = reinterpret_cast<intptr_t>(&DAT_0109aa14);
    pThis[14] = (*reinterpret_cast<int *>(&::DAT_0109b220));
    pThis[15] = 0;
    return pThis;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};

// @fnv 0x00a41230
const GlobalObjectO2_00a7b610* __cdecl FUN_00a41230()
{
    return &::g_011f3e6c;
}

struct BSFadeNode
{
};
struct FUN_00a3c390 : BSFadeNode
{
    char pad[0x18];
    FUN_00a3c390(float v) throw();
};
struct FloatSrc
{
    char pad[0xc];
    float m_fFloatValue;
    float Get() const
    {
        float f = m_fFloatValue;
        return f;
    }
};

// Allocates a FUN_00a3c390 fade node constructed from the float value returned by the FloatSrc at self+0x3c.
// @fnv 0x00a41240
void* CreateFadeNodeFromFloatSource(void* self, int edx, unsigned short usIndex)
{
    return new FUN_00a3c390((*(FloatSrc**)((char*)self + 0x3c))->Get());
}

namespace fnv_00a41280 {
struct BSFadeNode
{
};
struct CopyHelper
{
    void CopyMemberData(CopyHelper* dest, void* process);
};

static void* Init(void* p)
{
    ::InitTimeController((int*)p);
    *(void**)p = &(*reinterpret_cast<void * *>(&::fnv_00a411f0::DAT_010975fc));
    return p;
}

// @fnv 0x00a41280
void* FUN_00a41280(CopyHelper* self, int edx, void* kCloning)
{
    void* pMemory = ::operator new(0x40);
    void* pkObject = pMemory ? Init(pMemory) : 0;
    self->CopyMemberData((CopyHelper*)pkObject, kCloning);
    return pkObject;
}
}  // namespace fnv_00a41280

namespace fnv_00a41380 {
struct GlobalObjectO2_00a7b610;
struct ActorCombatGroup;
struct ArrHelper
{
    void* vt;
    unsigned int refs;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short pad;
    unsigned short m_usGrowBy;
};
void FUN_00a57420(ArrHelper* a);

// @fnv 0x00a41380
void AppendGlobalObject(ArrHelper* pkStrings)
{
    FUN_00a57420(pkStrings);
    ActorCombatGroup* v = ((::fnv_00a41380::ActorCombatGroup *)(::FUN_00a7d330((const char *)((*reinterpret_cast<::fnv_00a41380::GlobalObjectO2_00a7b610 * *>(&::g_011f3e6c))))));
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiIndex + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiIndex, (char *&)(v));
}
}  // namespace fnv_00a41380

namespace fnv_00a4fc00 {
struct NiPSysModifierCtlr
{
    void LinkObject(NiStream& s);
};
struct BSFadeNode
{
};
struct NiColorData;
struct NiColorInterpolator : NiRefObject
{
    char pad[0x1c];
    NiColorInterpolator(NiColorData* pkColorData) throw();
};
struct StreamLink
{
};
struct StreamView
{
    char pad[0xd8];
    unsigned int m_uiNifVersion;
};

// @fnv 0x00a4fc00
void LinkColorInterpolator(NiPSysModifierCtlr* self, int edx, NiStream* kStream)
{
    reinterpret_cast<struct ::FUN_00a57630 *>((self))->LinkObject(*kStream);
    if (((StreamView*)kStream)->m_uiNifVersion < 0x0a010068)
    {
        NiColorData* pkColorData = (NiColorData*)reinterpret_cast<::NiStream *>((((StreamLink*)kStream)))->GetLoadedObject();
        NiColorInterpolator* p = new NiColorInterpolator(pkColorData);
        NiColorInterpolator** ppInterpolatorSlot = (NiColorInterpolator**)((char*)self + 0x34);
        if (*ppInterpolatorSlot != p)
        {
            if (*ppInterpolatorSlot)
                (*ppInterpolatorSlot)->DecRefCount();
            *ppInterpolatorSlot = p;
            if (p)
                p->IncRefCount();
        }
        (*(void(**)(NiColorInterpolator*))(*(char**)*ppInterpolatorSlot + 0xbc))(*ppInterpolatorSlot);
    }
}
}  // namespace fnv_00a4fc00

// NiFloatExtraDataController helper: push the controller's float extra-data value
// into the fade node that owns it (if the node is registered for this controller).
struct FadeNode
{
};


struct FUN_00a412d0_cls : public NiFloatExtraDataController
{
    void ApplyFadeValue(FadeNode* pFadeNode, int iIndex);
};

// Looks up the fade node for g_011f3738 and sets its value from this controller's float extra data.
// @fnv 0x00a412d0
void FUN_00a412d0_cls::ApplyFadeValue(FadeNode* pFadeNode, int iIndex)
{
    FadeNode* pTarget;
    if (pFadeNode == 0)
        pTarget = 0;
    else
        pTarget = ((::FadeNode *)(reinterpret_cast<::NiObject *>((pFadeNode))->DynamicCast((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f3738))))));

    NiFloatExtraData* pExtraData = static_cast<NiFloatExtraData*>(this->m_pExtraData.operator->());
    reinterpret_cast<::FUN_00a3c500_shell *>((pTarget))->SetFloatValue(pExtraData->m_fValue);
}
