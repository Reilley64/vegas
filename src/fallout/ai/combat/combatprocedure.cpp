
// src/fallout/ai/combat/combatprocedure.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedure.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/Holder_009816d0.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00981570__FUN_00981570_shell.h"
#include "fnv/decl/fnv_00981660__CombatController.h"
#include "fnv/decl/fnv_00981690__CombatController.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_005b5000.h"
#include "CombatProcedure.h"

struct FUN_0097f450_shell
{
    void SetAttacker(unsigned char bAttacker);
};

// @fnv 0x0097f450
void FUN_0097f450_shell::SetAttacker(unsigned char bAttacker)
{
    *reinterpret_cast<unsigned char*>(this + 0x77) = bAttacker;
}

struct FUN_009ca6e0_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

void __cdecl FUN_009ca6c0_shell_member();

// Calls FUN_009ca6c0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009ca6e0
void* FUN_009ca6e0_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_009ca6c0_class *>(this)->FUN_009ca6c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_009d1b10_shell
{
    char _pad[0x158];
    float m_fTarget;  // +0x158
    float GetTarget();
};

// @fnv 0x009d1b10
float FUN_009d1b10_shell::GetTarget()
{
    return m_fTarget;
}

struct FUN_009d4f30_shell
{
    void SetByteAtOffset188ToFF();
    char pad00[0x188];
    unsigned char unk188;
};

// @fnv 0x009d4f30
void FUN_009d4f30_shell::SetByteAtOffset188ToFF()
{
    this->unk188 = 0xff;
}

struct FUN_00980070_shell
{
    unsigned int FUN_00980070();
    unsigned int pad00[0x3d];
    unsigned int unkf4;
};

// @fnv 0x00980070
unsigned int FUN_00980070_shell::FUN_00980070()
{
    return this->unkf4;
}

struct BGSSaveFormBuffer
{
};

struct FUN_00996ed0_shell
{
    void SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x00996ed0
void FUN_00996ed0_shell::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(this + 8, 4, 0);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct CombatController
{
public:
    void FUN_00981720(unsigned char);
};
struct CombatProcedureEx
{
    int _pad;
    CombatController* m_pCombatController;
    void SetLookAtPoint(const NiPoint3& arLookAtPoint, unsigned char acPriority);
};
// Passes the look-at point and priority to the combat controller, then applies the returned value via a second controller call.
// @fnv 0x00996e60
void CombatProcedureEx::SetLookAtPoint(const NiPoint3& arLookAtPoint, unsigned char acPriority)
{
    reinterpret_cast<::Holder_009816d0 *>((m_pCombatController))->FUN_009816d0(((int)(reinterpret_cast<::fnv_00981690::CombatController *>((m_pCombatController))->FUN_00981690((::fnv_00981690::CombatProcedure *)(void *)(this)))), *(const ::Pt_009816d0 *)nullptr, {});
}

namespace fnv_00996ea0 {
struct CombatController
{
};
struct MyProc
{
    int _pad;
    CombatController* pCtrl;
    void FUN_00996ea0();
};
// Calls FUN_00981690 on this, then passes the result to pCtrl->FUN_00981720.
// @fnv 0x00996ea0
void MyProc::FUN_00996ea0()
{
    reinterpret_cast<::CombatController *>((pCtrl))->FUN_00981720(((int)(reinterpret_cast<::fnv_00981690::CombatController *>((pCtrl))->FUN_00981690((::fnv_00981690::CombatProcedure *)(void *)(this)))));
}
}  // namespace fnv_00996ea0

struct BGSLoadFormBuffer
{
};

struct FUN_00996ef0_shell
{
    void FUN_00996ef0(BGSLoadFormBuffer* buffer);
};

// @fnv 0x00996ef0
void FUN_00996ef0_shell::FUN_00996ef0(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this + 8), 4);
}

struct Attacker_008b3a50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* f4();
};
struct CombatProcedure_008b3a50
{
    char _pad[0x190];
    Attacker_008b3a50* m_atk;
    void* FUN_008b3a50();
};
// Returns the result of calling f4 on the attacker object stored in m_atk.
// @fnv 0x008b3a50
void* CombatProcedure_008b3a50::FUN_008b3a50()
{
    return m_atk->f4();
}

struct AlchemyItem
{
    void* FUN_004030b0();
};

struct FUN_00996e00_shell
{
    char _pad[4];
    AlchemyItem* _m_04;  // +0x04
    void* FUN_00996e00();
};

// @fnv 0x00996e00
void* FUN_00996e00_shell::FUN_00996e00()
{
    return _m_04->FUN_004030b0();
}

namespace fnv_00996e20 {
struct CombatController
{
};

struct FUN_00996e20_shell
{
    char _pad[4];
    CombatController* m_pCombatController;  // +0x04
    void FUN_00996e20(int aiCombatMoveMode);
};

// @fnv 0x00996e20
void FUN_00996e20_shell::FUN_00996e20(int aiCombatMoveMode)
{
    reinterpret_cast<::fnv_00981570::FUN_00981570_shell *>((this->m_pCombatController))->FUN_00981570(aiCombatMoveMode);
}
}  // namespace fnv_00996e20

namespace fnv_00996e40 {
struct CombatController
{
};

struct FUN_00996e40_shell
{
    char _pad[4];
    CombatController* m_pCombatController;
    void FUN_00996e40();
};

// @fnv 0x00996e40
void FUN_00996e40_shell::FUN_00996e40()
{
    reinterpret_cast<::fnv_00981660::CombatController *>((m_pCombatController))->ResetCombatState();
}
}  // namespace fnv_00996e40

class TESObjectWEAP;
extern char DAT_0108ddac;
struct FUN_009d0890 : CombatProcedure
{
    FUN_009d0890();
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
};
struct FUN_009cc0c0 : CombatProcedure
{
    FUN_009cc0c0();
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
};
struct FUN_009cadf0 : CombatProcedure
{
    FUN_009cadf0();
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
};
struct FUN_009cbad0 : CombatProcedure
{
    FUN_009cbad0();
    int f10;
    int f14;
    int f18;
    int f1c;
};
struct FUN_009d5ad0 : CombatProcedure
{
    FUN_009d5ad0(int);
    int f10;
    int f14;
};
struct FUN_009da720 : CombatProcedure
{
    FUN_009da720(TESObjectWEAP*);
    int f10;
    int f14;
};
struct FUN_009d69f0 : CombatProcedure
{
    FUN_009d69f0(int, float, int);
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
};
struct FUN_009d2440 : CombatProcedure
{
    FUN_009d2440(int);
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
};
struct FUN_009ca5f0 : CombatProcedure
{
    FUN_009ca5f0(int, int);
    int f10;
    int f14;
    int f18;
};
struct FUN_009d6030 : CombatProcedure
{
    FUN_009d6030(void*, float, int, int);
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
};
struct FUN_009d8b60 : CombatProcedure
{
    FUN_009d8b60();
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
};
struct FUN_009daa10 : CombatProcedure
{
    FUN_009daa10(TESBoundObject*);
    int f10;
    int f14;
};
struct FUN_009d3a00 : CombatProcedure
{
    FUN_009d3a00();
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
};
// Returns a new CombatProcedure subclass for kind values 0 through 12; otherwise calls FUN_005b5e40 and returns null.
// @fnv 0x00996f10
CombatProcedure* __cdecl CreateCombatProcedure(int kind)
{
    switch (kind)
    {
    case 0:
        return new FUN_009d0890();
    case 1:
        return new FUN_009cc0c0();
    case 2:
        return new FUN_009cadf0();
    case 3:
        return new FUN_009cbad0();
    case 4:
        return new FUN_009d5ad0(0);
    case 5:
        return new FUN_009da720(0);
    case 6:
        return new FUN_009d69f0(0, 0.0f, 0);
    case 7:
        return new FUN_009d2440(0);
    case 8:
        return new FUN_009ca5f0(0, 0);
    case 9:
        return new FUN_009d6030(0, 0.0f, 0, 0);
    case 10:
        return new FUN_009d8b60();
    case 11:
        return new FUN_009daa10(0);
    case 12:
        return new FUN_009d3a00();
    default:
        ::FUN_005b5e40();
        return 0;
    }
}
