// src/fallout/ai/combat/combatstate_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/combat/combatstate.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_005dc960_shell.h"
#include "fnv/decl/FUN_0067fdb0_shell.h"
#include "fnv/decl/FUN_00844160_shell.h"
#include "fnv/decl/FUN_008be220_cls.h"
#include "fnv/decl/FUN_009a0510_shell.h"
#include "fnv/decl/FUN_009a2c60_Class.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_009a2d50__FUN_009a2d50_s.h"
#include "fnv/decl/fnv_009a2db0__FUN_009a2db0_shell.h"
#include "fnv/decl/fnv_009a2ea0__FUN_009a2ea0_struct.h"
#include "fnv/decl/fnv_009a3050__CombatSaveGameData.h"
#include "fnv/decl/fnv_009a31b0__Holder.h"
#include "fnv/decl/fnv_009a3480__S5460.h"
#include "fnv/decl/fnv_009a3610__FUN_009a3610_arr.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_00884000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_011d5000.h"
#include "combatstate_decls.h"

class TESForm
{
  public:
    virtual void FormSlot();
};
struct CombatAvoidanceSphere
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct CombatCoverPointData
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
};
class TESObjectWEAP : public TESForm
{
};

class BGSExplosion : public TESForm
{
};

class TESBoundObject : public TESForm
{
};


struct CombatLoadBuffer
{

    virtual unsigned char Version();




};

struct LoadStamp4
{
    unsigned int value;
};

struct LoadStamp8
{
    unsigned int low, high;
};

struct LoadCover : CombatCoverPointData
{

    LoadCover();
};

struct LoadLocation : CombatAvoidanceSphere
{
    LoadLocation();
};

struct LoadInfo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    LoadInfo();
};

struct LoadBoundPair
{
    int value;
    TESBoundObject* object;
    LoadBoundPair();
};

struct LoadArea
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
};

struct LoadA
{
};

struct LoadB
{
};

struct LoadWeaponArray
{
    int unk00;
    TESObjectWEAP** data;
    unsigned int count, capacity;
};

struct LoadArrayA
{
    int unk00;
    LoadA* data;
    unsigned int count, capacity;
};

struct LoadArrayB
{
    int unk00;
    LoadB* data;
    unsigned int count, capacity;
    LoadB* FUN_006dad90(unsigned int);
};



struct CombatLoadState
{

    unsigned char flags;

    unsigned char unk01;

    unsigned char unk02;

    unsigned char unk03;

    int state;

    int unk08;

    TESObjectWEAP* weapons[6];

    LoadWeaponArray otherWeapons;

    TESObjectWEAP* currentWeapon;

    float value38;

    float values3c[7];

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned char flag70;

    unsigned char flag71;

    unsigned char flag72;

    unsigned char flag73;

    unsigned char flag74;

    unsigned char flag75;

    unsigned char flag76;

    unsigned char flag77;

    BGSExplosion* explosion;

    unsigned int unk07c;

    unsigned int unk080;

    float position[3];

    unsigned int unk090;

    LoadStamp4 stamp094;

    LoadStamp4 stamp098;

    LoadStamp4 stamp09c;

    LoadStamp4 stamp0a0;

    LoadStamp4 stamp0a4;

    LoadStamp8 stamp0a8;

    LoadStamp8 stamp0b0;

    LoadStamp8 stamp0b8;

    LoadStamp4 stamp0c0;

    LoadInfo* info;

    unsigned char flagc8;

    unsigned char flagc9;

    unsigned char unkca;

    unsigned char unkcb;

    unsigned int unk0cc;

    unsigned int unk0d0;

    unsigned int unk0d4;

    unsigned char flagd8;

    unsigned char unkd9;

    unsigned char unkda;

    unsigned char unkdb;

    unsigned int unk0dc;

    LoadStamp4 stamp0e0;

    LoadCover* cover;

    LoadCover* alternateCover;

    LoadArea area1;

    LoadArea area2;

    LoadArrayA itemsA;

    LoadArrayB itemsB;

    LoadStamp4 stamp184;

    unsigned char flag188;

    unsigned char unk189;

    unsigned char unk18a;

    unsigned char unk18b;

    LoadLocation* location;

    LoadBoundPair* pairs[5];

    TESBoundObject* objects[2];

    LoadStamp8 objectStamps[2];

    unsigned int unk1bc;

    unsigned int unk1c0;

    unsigned int unk1c4;

    unsigned char flag1c8;

    unsigned char unk1c9;

    unsigned char unk1ca;

    unsigned char unk1cb;

    LoadStamp8 stamp1cc;

    LoadStamp8 stamp1d4;

    LoadStamp8 stamp1dc;

    LoadStamp8 stamp1e4;

    LoadStamp8 stamp1ec;

    LoadStamp8 stamp1f4;

    LoadStamp8 stamp1fc;

    LoadStamp8 stamp204;

    LoadStamp8 stamp20c;

    LoadStamp8 stamp214;

    LoadStamp8 stamp21c;

    unsigned int unk224;

    unsigned int unk228;


    void FUN_009a2040(CombatLoadBuffer*);
};

// @fnv 0x009a2040
void CombatLoadState::FUN_009a2040(CombatLoadBuffer* buffer)

{

    unsigned char presence;

    unsigned char pairPresence;

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flags), 1);

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&state), 4);

    if (state == -1)
        state = 0;

    for (unsigned int i = 0; i < 6; i++)
        weapons[i] = dynamic_cast<TESObjectWEAP*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

    {

        unsigned int weaponCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));

        reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(otherWeapons))->FUN_006f2290(weaponCount, true);

        for (unsigned int i = 0; i < weaponCount; i++)
        {

            TESObjectWEAP** item = ((::TESObjectWEAP **)(reinterpret_cast<::S3e60 *>(&(otherWeapons))->FUN_006a7ad0(i)));

            *item = dynamic_cast<TESObjectWEAP*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
        }

        currentWeapon = dynamic_cast<TESObjectWEAP*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&value38), 4);

        for (unsigned int i = 0; i < 7; i++)
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&values3c[i]), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk058), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk05c), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk064), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk068), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk06c), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag70), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag71), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag72), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag73), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag74), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag75), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag76), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag77), 1);

        explosion = dynamic_cast<BGSExplosion*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk07c), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk080), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&position), 12);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk090), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flagc8), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flagc9), 1);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk0cc), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk0d0), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk0d4), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk08), 4);

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flagd8), 1);

        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&unk0dc));

        reinterpret_cast<::CombatTargetTimestamp *>(&(stamp094))->LoadGame((::BGSLoadGameBuffer *)(buffer));

        reinterpret_cast<::CombatTargetTimestamp *>(&(stamp098))->LoadGame((::BGSLoadGameBuffer *)(buffer));

        reinterpret_cast<::CombatTargetTimestamp *>(&(stamp09c))->LoadGame((::BGSLoadGameBuffer *)(buffer));

        reinterpret_cast<::CombatTargetTimestamp *>(&(stamp0a0))->LoadGame((::BGSLoadGameBuffer *)(buffer));

        reinterpret_cast<::CombatTargetTimestamp *>(&(stamp0a4))->LoadGame((::BGSLoadGameBuffer *)(buffer));

        reinterpret_cast<::TimeoutTimer *>(&(stamp0a8))->LoadGame((::BGSLoadFormBuffer *)(buffer));

        reinterpret_cast<::TimeoutTimer *>(&(stamp0b0))->LoadGame((::BGSLoadFormBuffer *)(buffer));

        reinterpret_cast<::CombatTargetTimestamp *>(&(stamp0c0))->LoadGame((::BGSLoadGameBuffer *)(buffer));

        if (buffer->Version() >= 20)
        {
            reinterpret_cast<::TimeoutTimer *>(&(stamp0b8))->LoadGame((::BGSLoadFormBuffer *)(buffer));
            reinterpret_cast<::CombatTargetTimestamp *>(&(stamp0e0))->LoadGame((::BGSLoadGameBuffer *)(buffer));
        }

        presence = 0;

        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&presence), 1);

        if (presence & 1)
        {

            cover = new LoadCover;

            reinterpret_cast<::fnv_009a2ea0::FUN_009a2ea0_struct *>((cover))->FUN_009a2ea0((::fnv_009a2ea0::BGSLoadFormBuffer *)(buffer));

            if (reinterpret_cast<::FUN_005dc960_shell *>((cover))->FUN_005dc960())
            {
                reinterpret_cast<::FUN_0067fdb0_shell *>((cover))->FUN_0067fdb0(0);
                reinterpret_cast<::FUN_009a0510_shell *>(this)->FUN_009a0510((::StageHolder *)(cover));
            }
        }

        if (presence & 4)
        {

            alternateCover = new LoadCover;

            reinterpret_cast<::fnv_009a2ea0::FUN_009a2ea0_struct *>((alternateCover))->FUN_009a2ea0((::fnv_009a2ea0::BGSLoadFormBuffer *)(buffer));

            if (reinterpret_cast<::FUN_005dc960_shell *>((alternateCover))->FUN_005dc960())
            {
                reinterpret_cast<::FUN_0067fdb0_shell *>((alternateCover))->FUN_0067fdb0(0);
                reinterpret_cast<::FUN_009a0510_shell *>(this)->FUN_009a0510((::StageHolder *)(alternateCover));
            }
        }

        if (presence & 16)
        {
            location = new LoadLocation;
            reinterpret_cast<::FUN_009a2c60_Class *>((location))->LoadFormData(buffer);
        }

        if (presence & 32)
        {
            info = new LoadInfo;
            reinterpret_cast<::fnv_009a31b0::Holder *>((info))->FUN_009a31b0((::fnv_009a31b0::BGSLoadFormBuffer *)(buffer));
        }

        if (presence & 2)
            reinterpret_cast<::fnv_009a3050::CombatSaveGameData *>(&(area1))->FUN_009a3050((::fnv_009a3050::BGSLoadFormBuffer *)(buffer));

        if (presence & 8)
            reinterpret_cast<::fnv_009a3050::CombatSaveGameData *>(&(area2))->FUN_009a3050((::fnv_009a3050::BGSLoadFormBuffer *)(buffer));

        {

            unsigned int countA = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));

            reinterpret_cast<::fnv_009a3480::S5460 *>(&(itemsA))->FUN_009a3480(countA, true);

            for (unsigned int i = 0; i < countA; i++)
            {

                LoadA* item = ((::LoadA *)(reinterpret_cast<::FUN_00844160_shell *>(&(itemsA))->FUN_00844160(i)));

                reinterpret_cast<::fnv_009a2d50::FUN_009a2d50_s *>((item))->FUN_009a2d50((::fnv_009a2d50::BGSLoadFormBuffer *)(buffer));
            }

            {

                unsigned int countB = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));

                reinterpret_cast<::fnv_009a3610::FUN_009a3610_arr *>(&(itemsB))->FUN_009a3610(countB, true);

                for (unsigned int i = 0; i < countB; i++)
                {

                    LoadB* item = itemsB.FUN_006dad90(i);

                    reinterpret_cast<::fnv_009a2db0::FUN_009a2db0_shell *>((item))->FUN_009a2db0((::fnv_009a2db0::BGSLoadGameBuffer *)(buffer));
                }

                reinterpret_cast<::CombatTargetTimestamp *>(&(stamp184))->LoadGame((::BGSLoadGameBuffer *)(buffer));

                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag188), 1);

                pairPresence = 0;

                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pairPresence), 1);

                for (unsigned int i = 0; i < 5; i++)
                {

                    if (pairPresence & (1 << i))
                    {

                        pairs[i] = new LoadBoundPair;

                        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(pairs[i]));

                        pairs[i]->object = dynamic_cast<TESBoundObject*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                    }
                }

                for (unsigned int i = 0; i < 2; i++)
                {

                    objects[i] = dynamic_cast<TESBoundObject*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

                    reinterpret_cast<::TimeoutTimer *>(&(objectStamps[i]))->LoadGame((::BGSLoadFormBuffer *)(buffer));
                }

                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk1bc), 4);

                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&unk1c0));

                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag1c8), 1);

                if (buffer->Version() >= 15)
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk228), 4);

                reinterpret_cast<::TimeoutTimer *>(&(stamp1cc))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp1d4))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp1dc))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp1e4))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp1ec))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp1f4))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp1fc))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp20c))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp204))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp214))->LoadGame((::BGSLoadFormBuffer *)(buffer));

                reinterpret_cast<::TimeoutTimer *>(&(stamp21c))->LoadGame((::BGSLoadFormBuffer *)(buffer));
            }
        }
    }
}
