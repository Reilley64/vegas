// gamebryo2.2/corelibs/niparticle/nipsysmodifierctlr.cpp: NiPSysModifierCtlr, NiPSysModifierCtlrRuntime, ModifierControllerStandin (9 functions)

#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FUN_00a38fe0_shell.h"
#include "fnv/decl/FUN_00a39030_cls.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a6d290.h"
#include "fnv/decl/Holder00a390a0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c1b0f0__FUN_00c1b0f0_cls.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c0000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysmodifierctlr_decls.h"

// @fnv 0x00c31340
void NiPSysModifierCtlr::ProcessClone(CloningProcess& aCloneProcess)
{
    NiSingleInterpController::ProcessClone(aCloneProcess);
    NiPSysModifierCtlr* clone = 0;
    reinterpret_cast<::A54440Hash *>((aCloneProcess.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)((const char*)this), (::A54440Manager **)&((ShaderBufferRecord*&)clone));
    NiPSysModifierCtlr* destination = clone;
    if (m_pkTarget && destination->m_pkTarget)
    {
        reinterpret_cast<::A54440Hash *>((aCloneProcess.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)((const char*)m_pkTargetModifier), (::A54440Manager **)&((ShaderBufferRecord*&)clone));
        destination->m_pkTargetModifier = clone;
    }
}

struct NiObjectNET
{
    virtual ~NiObjectNET();
};
struct NiTimeController
{
    virtual void SetTarget(NiObjectNET*);
};
struct NiParticleSystem
{
    void FindModifier();
};
struct NiPSysModifierCtlr_shell : public NiTimeController, public NiParticleSystem
{
    void FUN_00c31500(NiObjectNET* pkTarget);
};
// Clears the pointer at offset 0x3c, calls NiTimeController::SetTarget, and if the pointer at 0x2c is set, invokes the particle system method.
// @fnv 0x00c31500
void NiPSysModifierCtlr_shell::FUN_00c31500(NiObjectNET* pkTarget)
{
    *(void**)((char*)this + 0x3c) = 0;
    NiTimeController::SetTarget(pkTarget);
    if (*(void**)((char*)this + 0x2c))
        ((NiParticleSystem*)((char*)this + 0))->FindModifier();
}

struct NiStream
{
};

struct FUN_00a39010_shell
{
    void FUN_00a39010(NiStream&);
};

struct FUN_00a57130_shell
{
    void FUN_00a57130(NiStream&);
};

// @fnv 0x00a57130
void FUN_00a57130_shell::FUN_00a57130(NiStream& kStream)
{
    FUN_00a39010_shell* pBase = (FUN_00a39010_shell*)this;
    pBase->FUN_00a39010(kStream);
    reinterpret_cast<::FUN_00a641f0_cls *>(&(kStream))->WriteObjectLink((void *)((char const*)((char*)this + 0x38)));
}

struct S_00c313a0_Field
{
    virtual int v00() = 0;
    virtual int v01() = 0;
    virtual int v02() = 0;
    virtual int v03() = 0;
    virtual int v04() = 0;
    virtual int v05() = 0;
    virtual int v06() = 0;
    virtual int v07() = 0;
    virtual int v08() = 0;
    virtual int v09() = 0;
    virtual int v10() = 0;
    virtual int v11() = 0;
    virtual int v12() = 0;
    virtual int v13() = 0;
    virtual int v14() = 0;
    virtual int v15() = 0;
    virtual int v16() = 0;
    virtual int v17() = 0;
    virtual int v18() = 0;
    virtual int v19() = 0;
    virtual int v20() = 0;
    virtual int v21() = 0;
    virtual int v22() = 0;

    virtual bool FUN_00c313a0_Field_005c(S_00c313a0_Field*) = 0;
};

struct S_00c313a0
{
    virtual ~S_00c313a0()
    {}

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
    S_00c313a0_Field* unk3c;

    unsigned char IsEquivalentTo(S_00c313a0* other);
};

struct S_00a39030_Callee
{
};

// Compares this object with other via IsCompatibleWith, matching unk3c presence and contents, and returns whether unk38 is equal.
// @fnv 0x00c313a0
unsigned char S_00c313a0::IsEquivalentTo(S_00c313a0* other)
{
    if (!reinterpret_cast<::FUN_00a39030_cls *>((reinterpret_cast<S_00a39030_Callee*>(this)))->IsCompatibleWith((::NiSingleInterpController *)(other)))
        return 0;

    if (unk3c && !other->unk3c)
        return 0;

    if (!unk3c && other->unk3c)
        return 0;

    if (unk3c && other->unk3c)
    {
        if (!unk3c->FUN_00c313a0_Field_005c(other->unk3c))
            return 0;
    }

    return unk38 == other->unk38;
}

extern int(* DAT_00fdf1c4)(void* apMemory);

struct NiPSysModifierRef
{
    virtual void v00();
    virtual void Release();
    int m_iRefCount;
};

struct FUN_00c314a0_cls
{
    int m_vptr;
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
    NiPSysModifierRef* m_pModifier;
    char* m_kTargetModifierName;

    FUN_00c314a0_cls* Destroy(unsigned char acFlags);
};

// Frees the name buffer and modifier reference, calls FUN_00a6d290, and optionally deallocates the object when acFlags bit 0 is set.
// @fnv 0x00c314a0
FUN_00c314a0_cls* FUN_00c314a0_cls::Destroy(unsigned char acFlags)
{
    int(* pfnFree)(void*) = DAT_00fdf1c4;
    *(volatile int*)&m_vptr = (int)&(*reinterpret_cast<int *>(&::NiPSysModifierCtlr_vtable));
    char* pName = *(char* volatile*)&m_kTargetModifierName;
    if (pName != (char*)(*reinterpret_cast<int *>(&::DAT_0109b220)))
    {
        pfnFree(pName - 8);
    }
    NiPSysModifierRef* pModifier = m_pModifier;
    if (pModifier != 0)
    {
        if (pfnFree(&pModifier->m_iRefCount) == 0)
        {
            pModifier->Release();
        }
    }
    reinterpret_cast<struct ::FUN_00a6d290 *>(this)->FUN_00a6d290::~FUN_00a6d290();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x40);
    }
    return this;
}

namespace fnv_00c31530 {
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

struct NiParticleSystemRuntime
{
    virtual void DeleteThis();
    virtual void LoadBinary();
    virtual const NiRTTI* GetRTTI();
};

struct NiPSysModifierCtlrRuntime : NiPSysModifierCtlr
{
    bool IsTargetParticleSystem(NiParticleSystemRuntime* pkTarget);
};

// @fnv 0x00c31530
bool NiPSysModifierCtlrRuntime::IsTargetParticleSystem(NiParticleSystemRuntime* pkTarget)
{
    if (pkTarget != 0)
    {
        const NiRTTI* pkRTTI = pkTarget->GetRTTI();
        while (pkRTTI != 0)
        {
            if (pkRTTI == &(*reinterpret_cast<::fnv_00c31530::NiRTTI *>(&::g_012024e0)))
            {
                if (m_kTargetModifierName != (*reinterpret_cast<void * *>(&::DAT_0109b220)) && m_pkTarget != 0)
                {
                    if (reinterpret_cast<::fnv_00c1b0f0::FUN_00c1b0f0_cls *>((pkTarget))->FUN_00c1b0f0((unsigned int *)(&m_kTargetModifierName)))
                    {
                        return true;
                    }
                }
                return false;
            }
            pkRTTI = pkRTTI->m_pBaseRTTI;
        }
    }
    return false;
}
}  // namespace fnv_00c31530

struct NiStream;
struct ControllerStandin
{
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    void* target_2c;
};
struct ModifierControllerStandin : ControllerStandin
{
    void FUN_00c31590(NiStream& stream);
};
// @fnv 0x00c31590
void ModifierControllerStandin::FUN_00c31590(NiStream& stream)
{
    ::FUN_00a89af0((int)this);
    if (target_2c)
        reinterpret_cast<::NiParticleSystem *>(this)->FindModifier();
}

struct FUN_00c315b0_arr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_iCap;
    unsigned short m_iArrayLength;
    unsigned short unk0C;
    unsigned short m_iGrowBy;
};

struct FUN_00c315b0_cls
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
    void* m_pModifierName;
    void AppendModifierInfo(void* arg);
};


// @fnv 0x00c315b0
void FUN_00c315b0_cls::AppendModifierInfo(void* arg)
{
    FUN_00c315b0_arr* arr = (FUN_00c315b0_arr*)arg;
    reinterpret_cast<::Holder00a390a0 *>((arr))->FUN_00a390a0({});
    void* v1 = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_012027c8))))));
    unsigned int count = arr->m_iArrayLength;
    if (count >= arr->m_iCap)
    {
        arg = v1;
        reinterpret_cast<::ViewerStrings *>((arr))->SetSize(count + arr->m_iGrowBy);
    }
    else
    {
        arg = v1;
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((arr))->SetAt(count, (char *&)(arg));
    void* pModifierName = m_pModifierName;
    void* pNameString = ((void *)(::fnv_00a7d5e0::FUN_00a7d5e0("Modifier Name", (const char *)(pModifierName))));
    count = arr->m_iArrayLength;
    if (count >= arr->m_iCap)
    {
        arg = pNameString;
        reinterpret_cast<::ViewerStrings *>((arr))->SetSize(count + arr->m_iGrowBy);
    }
    else
    {
        arg = pNameString;
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((arr))->SetAt(count, (char *&)(arg));
}

struct BaseFake
{
};
struct FUN_00a57780_shell : BaseFake
{
    bool FUN_00a57780(NiStream&);
};
// @fnv 0x00a57780
bool FUN_00a57780_shell::FUN_00a57780(NiStream& stream)
{
    return reinterpret_cast<::FUN_00a38fe0_shell *>(this)->RegisterInterpolatorStreamables(stream);
}
