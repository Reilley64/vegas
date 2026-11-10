// fallout/ai/combat/combatworldstate.cpp: CombatWorldStateListNode, CombatStateArray, WorldStateManager (8 functions)

#include "fnv/combat_state_fields.h"
#include "fnv/combat_controller_fields.h"
#include <cstdint>
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatControllerStub.h"
#include "fnv/decl/CombatWeapon.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00516bf0_shell.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_00644790_class.h"
#include "fnv/decl/FUN_00662a80_shell.h"
#include "fnv/decl/FUN_00666f00_shell.h"
#include "fnv/decl/FUN_00893590_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008b3c90_class.h"
#include "fnv/decl/FUN_008d8160_Class.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_0097d110_shell.h"
#include "fnv/decl/FUN_0097e310_shell.h"
#include "fnv/decl/FUN_0097ef30_shell.h"
#include "fnv/decl/FUN_0097fae0_cls.h"
#include "fnv/decl/FUN_0097fd40_shell.h"
#include "fnv/decl/FUN_0098a310_shell.h"
#include "fnv/decl/FUN_009a0240_shell.h"
#include "fnv/decl/FUN_009a1380_cls.h"
#include "fnv/decl/FUN_009aa470_Class.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0097c150__CombatActionStandIn.h"
#include "fnv/decl/fnv_0097cfc0__CombatActionStandIn.h"
#include "fnv/decl/fnv_0097ee90__DummyInner.h"
#include "fnv/decl/fnv_00998980__FUN_00998980_shell.h"
#include "fnv/decl/fnv_009a02a0__FUN_009a02a0_struct.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_008b3000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_0097b000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_0108c000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011f1000.h"
#include "layout_support.h"

class UnsignedIdHandle;

// offset 0, no vtable; GetNext returns the following list node.
class CombatWorldStateListNode : public BSSimpleList<UnsignedIdHandle*>
{
  public:
    CombatWorldStateListNode* GetNext();
};

// @fnv 0x0062d990
CombatWorldStateListNode* CombatWorldStateListNode::GetNext()
{
    return static_cast<CombatWorldStateListNode*>(((::BSSimpleList< ::UnsignedIdHandle *> *)(reinterpret_cast<::Callees *>(this)->FUN_00726070())));
}

struct FUN_009aad60_shell
{
    CombatWorldStateListNode* FUN_009aad60(int index);
};
// @fnv 0x009aad60
CombatWorldStateListNode* FUN_009aad60_shell::FUN_009aad60(int index)
{
    return (CombatWorldStateListNode*)((char*)this + index * 8 + 0x1ac);
}

class CombatAction;
// @fnv 0x009957f0
BSSimpleList<CombatAction*>* FUN_009957f0(int index)
{
    return DAT_011f13d0[index];
}

struct FUN_009aad00Class
{
    void FUN_009aad00(int index, intptr_t value);
};
// @fnv 0x009aad00
void FUN_009aad00Class::FUN_009aad00(int index, intptr_t value)
{
    ((int*)this)[index] = value;
}

struct FUN_009aad40_shell
{
    bool IsFlagSet();
    char pad00[0x73];
    char unk73;
};
// @fnv 0x009aad40
bool FUN_009aad40_shell::IsFlagSet()
{
    return this->unk73 != 0;
}

struct CombatStateArray
{
    char _00[0x50];
    char _50[0x0C];
    void CopyFrom(CombatStateArray* apWorldStateArray);
};
// Copies 0x50 bytes from apWorldStateArray into this, then 0xC bytes into this+0x50 from apWorldStateArray+0x50.
// @fnv 0x009aad80
void CombatStateArray::CopyFrom(CombatStateArray* apWorldStateArray)
{
    __memcpy(this, apWorldStateArray, 0x50);
    __memcpy((char*)&this->_50, (char*)&apWorldStateArray->_50, 0xC);
}

struct FUN_009aad20_shell
{
    char gap[0x3FFF8];
    CombatWorldStateListNode* items[1];
    void SetItem(int index, CombatWorldStateListNode* value);
};
// @fnv 0x009aad20
void FUN_009aad20_shell::SetItem(int index, CombatWorldStateListNode* value)
{
    items[index] = value;
}

namespace fnv_009aa4e0 {
struct Vec
{
    float x, y, z;
    Vec();
    Vec operator-(const Vec&) const;
};
struct Pos
{
    float x, y, z, w;
    Pos();
    double FUN_00527a40(const Pos&);
};
struct RefType
{
    unsigned char type, disabled;
};
struct Entry
{
    intptr_t value;
    unsigned int bit;
};
struct Weapon
{
};
struct Stamp
{
    float time;
};
struct Form
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
    virtual int Type();
};
struct BasePart
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual bool Valid();
};
struct ActorBase
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    BasePart part;
};
struct Process
{
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
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual bool Ready();
};
class Actor
{
};
struct Caster
{
};
struct State
{
    RefType* FUN_007058c0();
    int GetAt(unsigned int);
};
struct Context
{
};
struct FloatSetting
{
};
struct IntSetting
{
};
struct WorldStateManager
{
    void UpdateWorldState(Context* context);
};
// @fnv 0x009aa4e0
void WorldStateManager::UpdateWorldState(Context* context)
{
    reinterpret_cast<::FUN_009aa470_Class *>(this)->FUN_009aa4b0();
    reinterpret_cast<::CombatControllerStub *>((context))->ValidateCurrentWeapon();
    State* stateB = ((::fnv_009aa4e0::State *)(reinterpret_cast<CombatControllerFields*>((context))->pCombatState));
    Actor* actor15 = ((::fnv_009aa4e0::Actor *)(reinterpret_cast<CombatControllerFields*>(context)->pActor));
    Actor* target9 = ((::fnv_009aa4e0::Actor *)(reinterpret_cast<::AlchemyItem *>((context))->FUN_004030b0()));
    Pos position6 = (*(::fnv_009aa4e0::Pos *)(reinterpret_cast<::FUN_00575650_Class *>((actor15))->FUN_00575650({})));
    Pos targetPositions5;
    if (target9)
        targetPositions5 = (*(::fnv_009aa4e0::Pos *)(reinterpret_cast<::FUN_00575650_Class *>((target9))->FUN_00575650({})));
    Caster* local4 = ((::fnv_009aa4e0::Caster *)(reinterpret_cast<::EffectSetting *>((context))->GetCastSound()));
    unsigned int q = 0;
    Form* bolt9 = ((::fnv_009aa4e0::Form *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(context))));
    Form* localX = ((::fnv_009aa4e0::Form *)(reinterpret_cast<::EffectSetting *>((context))->GetHitSound()));
    Entry* entry7 = ((::fnv_009aa4e0::Entry *)(reinterpret_cast<CombatStateFields*>(stateB)->pUnknownE4));
    if (entry7 && !reinterpret_cast<::FUN_009373f0_shell *>((entry7))->FUN_009373f0())
    {
        if (localX && localX->Type() == 7)
        {
            if (!reinterpret_cast<::FUN_0097e310_shell *>((localX))->IsField8One())
                q |= 1 << entry7->bit;
        }
        else
        {
            Vec point4;
            ::fnv_009a9370::FUN_009a9370((::fnv_009a9370::CombatController *)(context), (::fnv_009a9370::CombatCoverPointData *)(entry7), (::fnv_009a9370::NiPoint3 *)(::fnv_009aa4e0::Vec *)(&point4), (::fnv_009a9370::NiPoint3 *)(0));
            Vec delta = point4 - *((::fnv_009aa4e0::Vec *)(((::Vec3 *)(void *)&(position6))));
            delta.z *= 0.10000000149011612;
            if (reinterpret_cast<::TESCombatStyle *>((void *)&(delta))->UpdateCombatStyle() < 1024.0)
                q |= 1 << entry7->bit;
        }
    }
    if (bolt9 && !reinterpret_cast<::FUN_0097e310_shell *>((bolt9))->IsField8One() && bolt9->Type() == 8)
    {
        Form* boltTarget = bolt9;
        if (((void *)(reinterpret_cast<::MagicCaster_shell *>((boltTarget))->FUN_0044edb0())))
        {
            for (unsigned int index = 0; index < 5; ++index)
            {
                Entry* candidate = ((::fnv_009aa4e0::Entry *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>((stateB))->GetActionAtIndex(index)));
                if (candidate && (void*)candidate->value == ((void *)(reinterpret_cast<::MagicCaster_shell *>((boltTarget))->FUN_0044edb0())))
                    q |= 1 << (index + 17);
            }
        }
    }
    if (target9 && targetPositions5.FUN_00527a40(position6) < ::DAT_0108cb08 && !reinterpret_cast<::FUN_0097fd40_shell *>((stateB))->FUN_0097fd40() &&
        reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>((stateB))->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&targetPositions5)), 1, 0))
        q |= 2;
    q |= 128;
    q |= 256;
    q |= 512;
    q |= 65536;
    RefType* refrA = stateB->FUN_007058c0();
    if (refrA && !refrA->disabled)
    {
        switch (refrA->type)
        {
        case 0:
            q &= ~128u;
            break;
        case 1:
            q &= ~256u;
            break;
        case 2:
            q &= ~512u;
            break;
        case 3:
            q &= ~65536u;
            break;
        default:
            ::FUN_005b5e40();
            break;
        }
    }
    if (reinterpret_cast<::FUN_00662a80_shell *>((stateB))->FUN_00662a80() == 2)
        q |= 4096;
    if (localX && localX->Type() == 9 && !reinterpret_cast<::FUN_0097e310_shell *>((localX))->IsField8One() && !reinterpret_cast<::FUN_00666f00_shell *>((localX))->FUN_00666f00())
        q |= 1024;
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(1, q);
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(2, ~q);
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(14, reinterpret_cast<::FUN_00644790_class *>((stateB))->FUN_00644790() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009aa4e0::FloatSetting *>(&::originalRuntimeFloatSetting481)))))) ? 1 : 0);
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(8, (bool)(((void *)(reinterpret_cast<::FUN_00407820_shell *>((stateB))->FUN_00407820())) != 0));
    if (target9)
    {
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(4, reinterpret_cast<::fnv_0097ee90::DummyInner *>((stateB))->FUN_0097ee90());
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(5, reinterpret_cast<::fnv_00998980::FUN_00998980_shell *>((stateB))->FUN_00998980() && !::fnv_008b3c10::FUN_008b3c10((::fnv_008b3c10::CombatState *)(stateB)) ? 1 : 0);
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(6, ((unsigned char)(reinterpret_cast<::FUN_008b3c90_class *>((stateB))->GetByteAtOffset114())));
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(7, ::fnv_008b3c10::FUN_008b3c10((::fnv_008b3c10::CombatState *)(stateB)));
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(3, reinterpret_cast<::FUN_00435e00_t *>((void *)&(const ::fnv_009aa4e0::Stamp &)((*(::fnv_009aa4e0::Stamp *)(reinterpret_cast<::FUN_0097fae0_cls *>((stateB))->GetValue94({})))))->FUN_00435e00() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009aa4e0::FloatSetting *>(&::originalRuntimeFloatSetting413)))))) ? 1 : 0);
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(9, reinterpret_cast<::FUN_009aad40_shell *>((stateB))->IsFlagSet());
    }
    else
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(3, 1);
    Weapon* weapon0 = ((::fnv_009aa4e0::Weapon *)(reinterpret_cast<::FUN_008a1710_shell *>((actor15))->FUN_008a1710()));
    intptr_t weapon4 = weapon0 ? reinterpret_cast<::CombatWeapon *>((weapon0))->FUN_00522c80() : 6;
    if (weapon0 && weapon0 != ((::fnv_009aa4e0::Weapon *)(reinterpret_cast<::fnv_0097c150::CombatActionStandIn *>((stateB))->FUN_0097c150(weapon4))))
        weapon4 = 7;
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(11, weapon4);
    reinterpret_cast<::FUN_009aad20_shell *>(this)->SetItem(-65512, (::CombatWorldStateListNode *)(weapon4));
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(10, ((::fnv_009aa4e0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor15))->GetBaseTexture()))->Ready() ? weapon4 : 7);
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(12, ::GetField38((char *)(stateB)));
    for (uintptr_t first = 0; first < 5; ++first)
    {
        if (((::fnv_009aa4e0::Entry *)(reinterpret_cast<::fnv_0097cfc0::CombatActionStandIn *>((stateB))->GetActionAtIndex(first))))
        {
            reinterpret_cast<::FUN_009aad20_shell *>(this)->SetItem(-65514, (::CombatWorldStateListNode *)(first + 17));
            break;
        }
    }
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(13, ((intptr_t)(reinterpret_cast<::FUN_008d8160_Class *>((stateB))->GetField1BC())));
    for (uintptr_t second = 0; second < 2; ++second)
    {
        if (reinterpret_cast<::FUN_0097d110_shell *>((stateB))->GetAt(second) && reinterpret_cast<::TimeoutTimer *>((((::fnv_009aa4e0::State *)(reinterpret_cast<::FUN_009aad60_shell *>((stateB))->FUN_009aad60(second)))))->CheckTimer())
        {
            bool usable = false;
            switch (second + 17)
            {
            case 17:
                if (reinterpret_cast<::FUN_00893590_shell *>((actor15))->GetHealthFraction() * 100.0 < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_009aa4e0::IntSetting *>(&::g_011ce0b4)))))))
                    usable = true;
                break;
            case 18:
                usable = true;
                break;
            }
            if (usable)
            {
                reinterpret_cast<::FUN_009aad20_shell *>(this)->SetItem(-65513, (::CombatWorldStateListNode *)(second + 17));
                break;
            }
        }
    }
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(15, ((bool)(reinterpret_cast<::FUN_009a1380_cls *>((stateB))->FUN_009a1380())));
    void* magicTarget3 = ((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((local4))->FUN_0045cd60()));
    if (magicTarget3)
        reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(19, reinterpret_cast<::FUN_0098a310_shell *>((local4))->GetFieldOrZero((intptr_t)(actor15)));
    intptr_t flags28 = ((intptr_t)(reinterpret_cast<::FUN_00516bf0_shell *>((stateB))->FUN_00516bf0()));
    if (reinterpret_cast<::FUN_0097ef30_shell *>((local4))->FUN_0097ef30())
        flags28 |= 65536;
    if (((bool)(reinterpret_cast<::FUN_009a0240_shell *>((context))->GetFixedNormals())))
        flags28 |= 131072;
    if (!target9 || !((::fnv_009aa4e0::ActorBase *)(reinterpret_cast<::Actor *>((target9))->GetActorBase()))->part.Valid())
        flags28 |= 262144;
    reinterpret_cast<::FUN_009aad00Class *>(this)->FUN_009aad00(18, flags28);
}
}  // namespace fnv_009aa4e0
