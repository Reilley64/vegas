
// src/fallout_shared/havok/bgsacousticspacelistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/bgsacousticspacelistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_0061f870_shell.h"
#include "fnv/decl/FUN_0061f890_shell.h"
#include "fnv/decl/FUN_00620300_cls.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_011de000.h"
struct BGSAcousticSpaceListener
{
    void* Destroy(unsigned int flags);
};


struct Flt
{
    operator unsigned int() const;
};

struct FUN_0061f6c0_shell
{
    char pad[0xdec];
    Flt flt;
    std::uintptr_t FUN_0061f6c0();
};

// @fnv 0x0061f6c0
std::uintptr_t FUN_0061f6c0_shell::FUN_0061f6c0()
{
    return flt;
}

struct BGSAcousticSpace;
struct TESObjectREFR
{
};
class BGSAcousticSpace;
struct SoundPlaybackManager
{
    static void __cdecl ResetAcousticSpace(BGSAcousticSpace*);
public:
    static void SetAcousticSpace(::BGSAcousticSpace *);
};
struct NiTMap
{
};
struct MyMap
{
};
struct MapX
{
};
struct FUN_0061f8e0_shell
{
    void FUN_0061f8e0(bool abDoRemoval);
};
// @fnv 0x0061f8e0
void FUN_0061f8e0_shell::FUN_0061f8e0(bool abDoRemoval)
{
    void* pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)this + 0x18))))->GetFirstPos();
    while (pos2)
    {
        std::uintptr_t key;
        void* value2;
        reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)((char*)this + 0x18))))->FUN_006b7f20((::C6b7f20_Node **)&(pos2), (unsigned int *)&(key), (void **)&(value2));
        SoundPlaybackManager::ResetAcousticSpace(((::BGSAcousticSpace *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObjectREFR*)key)))->FUN_007af430())));
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)((char*)this + 0x18))))->FUN_00438af0();
}

struct PlayerCharacter
{
};
struct W_0043b4f0
{
};
struct TESObjectREFR;
struct RootContactPoint
{
    unsigned int pad0[8];
    void* m_20;
    unsigned int pad1[9];
    void* m_48;
};
struct BGSAcousticSpaceListenerX
{
    bool CheckAcousticSpaceListener(RootContactPoint*);
    unsigned char pad[0x14];
    unsigned char m_ucState;
};
// @fnv 0x0061f7b0
bool BGSAcousticSpaceListenerX::CheckAcousticSpaceListener(RootContactPoint* pPoint)
{
    TESObjectREFR* apTestRef = 0;
    if (reinterpret_cast<::FUN_004eaf60_shell *>((::_g_thePlayer))->FUN_004eaf60())
    {
        if (pPoint->m_48 == reinterpret_cast<::FUN_0043b560_shell *>((reinterpret_cast<W_0043b4f0*>(reinterpret_cast<::FUN_0061f6c0_shell *>((reinterpret_cast<PlayerCharacter*>(::_g_thePlayer)))->FUN_0061f6c0())))->GetSourceFilesFromObject())
            apTestRef = FUN_0062b4e0(pPoint->m_20);
    }
    else
    {
        TESObjectREFR* pAcousticSpaceLeft = FUN_0062b4e0(pPoint->m_48);
        if (pAcousticSpaceLeft == reinterpret_cast<TESObjectREFR*>(::_g_thePlayer))
            apTestRef = FUN_0062b4e0(pPoint->m_20);
    }
    if (apTestRef)
    {
        if (m_ucState)
            reinterpret_cast<::FUN_0061f870_shell *>(this)->SetCopyMapEntry((std::uintptr_t)(apTestRef));
        else
            SoundPlaybackManager::ResetAcousticSpace(((::BGSAcousticSpace *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apTestRef))->FUN_007af430())));
    }
    return false;
}

namespace fnv_0061f940 {
struct MapH
{
};
struct SetAtHelper
{
};
struct BGSAcousticSpaceListenerX
{
    void UpdateAcousticSpaceRefCounts(float afTime);
};
// @fnv 0x0061f940
void BGSAcousticSpaceListenerX::UpdateAcousticSpaceRefCounts(float afTime)
{
    void* iter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)this + 0x18))))->GetFirstPos();
    while (iter)
    {
        unsigned int icount;
        unsigned int key;
        reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)((char*)this + 0x18))))->FUN_006b7f20((::C6b7f20_Node **)&(iter), (unsigned int *)&(key), (void **)&((void*&)icount));
        reinterpret_cast<::FUN_00844700_Class *>((((SetAtHelper*)((char*)this + 0x18))))->FUN_00844700(key, --icount);
    }
    bool bloop = true;
    while (bloop)
    {
        bloop = false;
        void* iter2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)this + 0x18))))->GetFirstPos();
        while (iter2)
        {
            unsigned int icount;
            std::uintptr_t key;
            reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)((char*)this + 0x18))))->FUN_006b7f20((::C6b7f20_Node **)&(iter2), (unsigned int *)&(key), (void **)&((void*&)icount));
            if (icount == 0)
            {
                reinterpret_cast<::NiTMap_S *>((((MapH*)((char*)this + 0x18))))->RemoveKey(key);
                SoundPlaybackManager::ResetAcousticSpace(((::BGSAcousticSpace *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObjectREFR*)key)))->FUN_007af430())));
                bloop = true;
                break;
            }
        }
    }
}
}  // namespace fnv_0061f940

struct PC_00605d70
{
};
struct TgtOps
{
};
struct FUN_0061f630_shell
{
    void CheckPlayerReference(TESObjectREFR* apEntity);
};
// @fnv 0x0061f630
void FUN_0061f630_shell::CheckPlayerReference(TESObjectREFR* apEntity)
{
    if (!::_g_thePlayer)
        return;
    if (reinterpret_cast<::FUN_004eaf60_shell *>((((PC_00605d70*)::_g_thePlayer)))->FUN_004eaf60())
    {
        if (((void *)(::FUN_00460140((std::intptr_t)(((TgtOps*)apEntity))))) ==
            (void*)((std::uintptr_t)(reinterpret_cast<::FUN_0043b560_shell *>((((W_0043b4f0*)(reinterpret_cast<::FUN_0061f6c0_shell *>((::_g_thePlayer))->FUN_0061f6c0()))))->GetSourceFilesFromObject())))
            SoundPlaybackManager::ResetAcousticSpace(0);
    }
    else
    {
        TESObjectREFR* apTestRef = FUN_0062b4e0(((void *)(::FUN_00460140((std::intptr_t)(((TgtOps*)apEntity))))));
        if (apTestRef == (TESObjectREFR*)::_g_thePlayer)
            SoundPlaybackManager::ResetAcousticSpace(0);
    }
}

struct FUN_0082eae0_shell
{
};

struct FNV_GetObjectReference_shell
{
};

struct FUN_0061f6e0_shell
{
    unsigned char pad[0x14];
    bool m_ucState;
    bool CheckAcousticSpaceEntered(RootContactPoint*);
};

// @fnv 0x0061f6e0
bool FUN_0061f6e0_shell::CheckAcousticSpaceEntered(RootContactPoint* pPoint)
{
    TESObjectREFR* pAcousticSpaceRef = 0;

    if (reinterpret_cast<::FUN_004eaf60_shell *>((::_g_thePlayer))->FUN_004eaf60())
    {
        if (pPoint->m_48 == reinterpret_cast<::FUN_0043b560_shell *>((reinterpret_cast<W_0043b4f0*>(reinterpret_cast<::FUN_0061f6c0_shell *>((::_g_thePlayer))->FUN_0061f6c0())))->GetSourceFilesFromObject())
        {
            pAcousticSpaceRef = FUN_0062b4e0(pPoint->m_20);
        }
    }
    else
    {
        TESObjectREFR* apTestRef = FUN_0062b4e0(pPoint->m_48);
        if (apTestRef == reinterpret_cast<TESObjectREFR*>(::_g_thePlayer))
        {
            pAcousticSpaceRef = FUN_0062b4e0(pPoint->m_20);
        }
    }

    if (pAcousticSpaceRef)
    {
        if (!m_ucState || !reinterpret_cast<::FUN_0061f890_shell *>(this)->FUN_0061f890((::NiAVObject *)(pAcousticSpaceRef), false))
        {
            ::SoundPlaybackManager::SetAcousticSpace(
                ((::BGSAcousticSpace *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<FNV_GetObjectReference_shell*>(pAcousticSpaceRef)))->FUN_007af430())));
        }
        return true;
    }

    return false;
}

struct FUN_0061f5d0_sub
{
    ~FUN_0061f5d0_sub();
};

struct FUN_0061f5d0_base
{
    virtual ~FUN_0061f5d0_base();
};

struct FUN_0061f5d0_cls : FUN_0061f5d0_base
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_0061f5d0_sub m_18;
    virtual ~FUN_0061f5d0_cls();
};
// Calls FUN_0061f5d0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0061f5a0
void* BGSAcousticSpaceListener::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_0061f5d0_cls *>(this)->FUN_0061f5d0_cls::~FUN_0061f5d0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor of the class; the body is empty, so the compiler-generated member destructors run.
// @fnv 0x0061f5d0
FUN_0061f5d0_cls::~FUN_0061f5d0_cls()
{}

struct S_00620260_A
{
    virtual void vfn_00();
};
struct S_00620260_B
{
};
struct S_00620260_T : S_00620260_A, S_00620260_B
{
};
struct S_00620260_C
{
    virtual void vfn_00();
    virtual S_00620260_T* vfn_04(int a, void* b);
    S_00620260_T* cur;
    S_00620260_T* FUN_00620260(int a, void* b);
};
// @fnv 0x00620260
S_00620260_T* S_00620260_C::FUN_00620260(int a, void* b)
{
    S_00620260_T* r = cur ? ((::S_00620260_T *)(reinterpret_cast<::FUN_00620300_cls *>((cur))->FindDerivedByKey(b))) : 0;
    if (!r)
    {
        r = vfn_04(a, b);
        reinterpret_cast<::CombatProcedure *>((r))->Initialize((::CombatController *)(cur));
        cur = r;
    }
    return r;
}

#include "generated/data/fallout_shared/havok/bgsacousticspacelistener.inc"
