
// src/fallout/magic/magicprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/native_fixed_string.h"
#include "fnv/magic_projectile_fields.h"
#include "fnv/active_effect_fields.h"
#include <new>
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0046a010_shell.h"
#include "fnv/decl/FUN_00818be0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00931ff0_shell.h"
#include "fnv/decl/FUN_00932070_MobileObject.h"
#include "fnv/decl/FUN_00932490_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0096d490_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FaderManager.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/MagicCaster.h"
#include "fnv/decl/MagicItem.h"
#include "fnv/decl/S86a0.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00405f30__EILStandIn.h"
#include "fnv/decl/fnv_004062a0__EffectItemList.h"
#include "fnv/decl/fnv_004064d0__EffectItemList.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004bc450__FUN_004bc450_S.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0085a3d0__TESSaveLoadGameStandIn.h"
#include "fnv/decl/fnv_009320e0__FUN_009320e0_class.h"
#include "fnv/decl/fnv_00c741e0__FUN_00c741e0.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00c56000.h"
#include "fnv/symbols_00c84000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include <cstddef>
#include "fnv/decl/C70CharacterController.h"
#include "fnv/decl/FUN_00407860_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00810510_Class.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_00810590_Class.h"
#include "fnv/decl/FUN_008105c0_Class.h"
#include "fnv/decl/FUN_008105e0_Class.h"
#include "fnv/decl/FUN_00810640_class.h"
#include "fnv/decl/FUN_00810660_Class.h"
#include "fnv/decl/FUN_008106b0_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/S005620e0_Object.h"
#include "fnv/decl/S_00c6d7a0_Obj.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_00810610__FUN_00810610_Class.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004ba000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_0057b000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01024000.h"
#include <xmmintrin.h>
struct FUN_0081aa80_shell
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    FUN_0081aa80_shell* FUN_0081aa80(void* a, void* b, void* c);
};

// Stores the three arguments into the object's fields and returns this.
// @fnv 0x0081aa80
FUN_0081aa80_shell* FUN_0081aa80_shell::FUN_0081aa80(void* pFirst, void* pSecond, void* pThird)
{
    m_kPointA = pFirst;
    m_kPointB = pSecond;
    m_iThirdValue = pThird;
    return this;
}

struct Call741e0
{
};
extern int DAT_010795b8;
extern int DAT_010795d4;
extern int DAT_010795e4;
struct FUN_00806eb0
{
    FUN_00806eb0(intptr_t a1, int a2);
    unsigned int pad00[0xf8];
    void* unk3e0;
    unsigned int pad3e4[0xb];
    void* unk410;
    unsigned int pad414[0x8f];
    int unk650;
};
// Calls FUN_00c741e0 with a1, installs three vtable pointers at offsets 0x0, 0x3E0 and 0x410, and stores a2 at offset 0x650.
// @fnv 0x00806eb0
FUN_00806eb0::FUN_00806eb0(intptr_t aiArg, int aiValue)
{
    new ((void *)(((Call741e0*)this))) ::fnv_00c741e0::FUN_00c741e0((::fnv_00c741e0::T741_Src *)(aiArg));
    *(void**)this = (void*)&DAT_010795e4;
    this->unk3e0 = (void*)&DAT_010795d4;
    this->unk410 = (void*)&DAT_010795b8;
    this->unk650 = aiValue;
}

struct TESSaveLoadGame
{
};

struct FUN_0081e830_shell
{
    unsigned short GetSaveRecordSize(unsigned int a);
};

// Computes a save record size: adds the result of FUN_00931ff0(a) plus 12, and 4 more each when the save version is at least 0x48 and 0x64.
// @fnv 0x0081e830
unsigned short FUN_0081e830_shell::GetSaveRecordSize(unsigned int a)
{
    unsigned short usSize = 0;
    usSize += (unsigned short)((unsigned int)(reinterpret_cast<::FUN_00931ff0_shell *>(this)->FUN_00931ff0(a)));
    usSize += 4;
    usSize += 4;
    usSize += 4;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x48)
        usSize += 4;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x64)
        usSize += 4;
    return usSize;
}

struct PC7d
{
};
struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(intptr_t, int);
};
struct FUN_00932070_shell
{
};
struct FUN_00818be0_shell
{
};
struct FUN_0040a1e0_shell
{
    unsigned int FUN_0040a1e0();
};
struct FUN_0081e8c0_shell : FUN_00932070_shell
{
    void FUN_0081e8c0(unsigned int aiFlags);
    char pad00[0x8c];
    unsigned int unk8c;
    unsigned int unk90;
    FUN_00818be0_shell* caster;
    FUN_0040a1e0_shell* spell;
    unsigned int pad9c[0x2];
    unsigned int unka4;
};
// @fnv 0x0081e8c0
void FUN_0081e8c0_shell::FUN_0081e8c0(unsigned int aiFlags)
{
    reinterpret_cast<::FUN_00932070_MobileObject *>(this)->SaveProcess(aiFlags);
    unsigned int icasterID =
        ((unsigned int)(reinterpret_cast<::FUN_00818be0_cls *>((caster))->FUN_00818be0()));
    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<intptr_t>(&icasterID), 4);
    unsigned int ispellID = spell->FUN_0040a1e0();
    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<intptr_t>(&ispellID), 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&unka4, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x48)
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&unk90, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x64)
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(&unk8c, 4);
}

struct STR00
{
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int*, int);
};
struct FUN_0081e980_shell
{
    void FUN_0081e980(uintptr_t, uintptr_t);
    unsigned int pad00[0x23];
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int pad9c[0x2];
    unsigned int unka4;
};
// @fnv 0x0081e980
void FUN_0081e980_shell::FUN_0081e980(uintptr_t a, uintptr_t b)
{
    reinterpret_cast<::fnv_009320e0::FUN_009320e0_class *>(this)->SetProcessLevel((void *)(a), (void *)(b));
    unsigned int icasterID;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&icasterID, 4);
    this->unk94 = icasterID;
    unsigned int ispellID;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&ispellID, 4);
    this->unk98 = ispellID;
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(&this->unka4, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x48)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(&this->unk90, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x64)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(&this->unk8c, 4);
}

struct Form
{
    virtual void FUN_00800000() = 0;
    virtual Form* FUN_00800004() = 0;
};

struct ArrSI
{
};

struct FUN_0081aa80
{
    Form* m_pForm;
    EffectItem* m_pEffect;
    FUN_0081aa80* m_pNext;

    FUN_0081aa80(Form* pForm, EffectItem* pEffect, FUN_0081aa80* pNext);
};

struct S3c60
{
    unsigned char m_auiShapeKeys[0xc8];
    FUN_0081aa80* m_pEntries;

    bool AddAudioFormEntry(Form* pForm, ArrSI* pAudio);
};


// @fnv 0x0081a960
bool S3c60::AddAudioFormEntry(Form* pForm, ArrSI* pAudio)
{
    if (!pForm || !pAudio)
        return false;

    if (reinterpret_cast<::ActiveEffectFields *>(pAudio)->spell != reinterpret_cast<::MagicProjectileFields *>(this)->spell)
        return true;

    Form* form = pForm->FUN_00800004();
    EffectItem* value = reinterpret_cast<::ActiveEffectFields *>(pAudio)->effect;

    FUN_0081aa80* node = m_pEntries;
    while (node)
    {
        if (node->m_pForm == form && node->m_pEffect == value)
            return false;
        node = node->m_pNext;
    }

    FUN_0081aa80* pNewEntry = new FUN_0081aa80(form, value, m_pEntries);
    m_pEntries = pNewEntry;
    return true;
}


struct Calendar;

struct NiAVObject
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual Calendar* v039(const NiFixedString&);
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058(NiAVObject*);
};

struct Calendar : public NiAVObject
{
};

struct MagicProjectile
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual void v039()
    {}
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058()
    {}
    virtual void v059()
    {}
    virtual void v060()
    {}
    virtual void v061()
    {}
    virtual void v062()
    {}
    virtual void v063()
    {}
    virtual void v064()
    {}
    virtual void v065()
    {}
    virtual void v066()
    {}
    virtual void v067()
    {}
    virtual void v068()
    {}
    virtual void v069()
    {}
    virtual void v070()
    {}
    virtual void v071()
    {}
    virtual void v072()
    {}
    virtual void v073()
    {}
    virtual void v074()
    {}
    virtual void v075()
    {}
    virtual void v076()
    {}
    virtual void v077()
    {}
    virtual void v078()
    {}
    virtual void v079()
    {}
    virtual void v080()
    {}
    virtual void v081()
    {}
    virtual void v082()
    {}
    virtual void v083()
    {}
    virtual void v084()
    {}
    virtual void v085()
    {}
    virtual void v086()
    {}
    virtual void v087()
    {}
    virtual void v088()
    {}
    virtual void v089()
    {}
    virtual void v090()
    {}
    virtual void v091()
    {}
    virtual void v092()
    {}
    virtual void v093()
    {}
    virtual void v094()
    {}
    virtual void v095()
    {}
    virtual void v096()
    {}
    virtual void v097()
    {}
    virtual void v098()
    {}
    virtual void v099()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114()
    {}
    virtual void v115()
    {}
    virtual NiAVObject* v116();

    void FUN_0081e730();
};

Calendar* NiAVObject::v039(const NiFixedString&)
{
    return 0;
}

void NiAVObject::v058(NiAVObject*)
{}

// Gets the "MagicAreaDisplay" child node and, if its GetDaysPassed() returns a node, passes the child to that node's v058.
// @fnv 0x0081e730
void MagicProjectile::FUN_0081e730()
{
    NiAVObject* pAreaDisplay = v116() ? v116()->v039(NiFixedString("MagicAreaDisplay")) : 0;

    if (pAreaDisplay)
    {
        if (((::Calendar *)(reinterpret_cast<::FUN_009611e0_shell *>((static_cast<Calendar*>(pAreaDisplay)))->FUN_009611e0())))
        {
            ((::Calendar *)(reinterpret_cast<::FUN_009611e0_shell *>((static_cast<Calendar*>(pAreaDisplay)))->FUN_009611e0()))->v058(pAreaDisplay);
        }
    }
}

namespace fnv_0081ea40 {
struct FUN_00932490_shell
{
};

struct MagicCaster
{
};

struct EffectItem
{
};

struct EffectItemList_shell
{
};

struct ES_0081c630
{
};

struct MI_0081c630
{
    ES_0081c630* GetEffectSettingForRange(int);
};

struct MagicItem
{
    unsigned char m_ucUnknownByte[0x0c];
    EffectItemList_shell m_effectItemList;

};

struct MobileObject
{
    unsigned int GetCurrentProcessLevel();
};

struct ActorDeletionQueue
{
    void FUN_0096d470(MobileObject*, int);
};

struct Host096d450
{
};

struct MagicProjectile;

struct SaveManager
{
};


struct MagicProjectile
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual void v039()
    {}
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058()
    {}
    virtual void v059()
    {}
    virtual void v060()
    {}
    virtual void v061()
    {}
    virtual void v062()
    {}
    virtual void v063()
    {}
    virtual void v064()
    {}
    virtual void v065()
    {}
    virtual void v066()
    {}
    virtual void v067()
    {}
    virtual void v068()
    {}
    virtual void v069()
    {}
    virtual void v070()
    {}
    virtual void v071()
    {}
    virtual void v072()
    {}
    virtual void v073()
    {}
    virtual void v074()
    {}
    virtual void v075()
    {}
    virtual void v076()
    {}
    virtual void v077()
    {}
    virtual void v078()
    {}
    virtual void v079()
    {}
    virtual void v080()
    {}
    virtual void v081()
    {}
    virtual void v082()
    {}
    virtual void v083()
    {}
    virtual void v084()
    {}
    virtual void v085()
    {}
    virtual void v086()
    {}
    virtual void v087()
    {}
    virtual void v088()
    {}
    virtual void v089()
    {}
    virtual void v090()
    {}
    virtual void v091()
    {}
    virtual void v092()
    {}
    virtual void v093()
    {}
    virtual void v094()
    {}
    virtual void v095()
    {}
    virtual void v096()
    {}
    virtual void v097()
    {}
    virtual void v098()
    {}
    virtual void v099()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114(int)
    {}

    unsigned char m_ucUnknownByte[0x90];
    MagicCaster* m_magicCaster;
    MagicItem* m_magicItem;
    EffectItem* m_effectItem;
    ES_0081c630* m_avEffect;

    void ResolveMagicReferences(unsigned int, unsigned int);
};

// @fnv 0x0081ea40
void MagicProjectile::ResolveMagicReferences(unsigned int aiFlags, unsigned int aiOldFlags)
{
    uintptr_t ispellID;
    uintptr_t icasterID;

    icasterID = reinterpret_cast<uintptr_t>(m_magicCaster);
    m_magicCaster = ((::fnv_0081ea40::MagicCaster *)(::MagicCaster::GetCasterByHandle(icasterID)));

    ispellID = reinterpret_cast<uintptr_t>(m_magicItem);
    m_magicItem = ((::fnv_0081ea40::MagicItem *)(::MagicItem::GetMagicItemByID(ispellID)));

    m_effectItem = ((::fnv_0081ea40::EffectItem *)(reinterpret_cast<::fnv_004064d0::EffectItemList *>(&(m_magicItem->m_effectItemList))->FindCostliestEffectItem(2, 0)));
    m_avEffect = reinterpret_cast<MI_0081c630*>(m_magicItem)->GetEffectSettingForRange(0);

    this->v114(0);

    reinterpret_cast<::FUN_00932490_shell *>((reinterpret_cast<FUN_00932490_shell*>(this)))->SetProcessFlags(aiFlags, aiOldFlags);

    reinterpret_cast<ActorDeletionQueue*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))
        ->FUN_0096d470(reinterpret_cast<MobileObject*>(this),
                       static_cast<int>(reinterpret_cast<MobileObject*>(this)->GetCurrentProcessLevel()));

    reinterpret_cast<::Host096d450 *>((reinterpret_cast<Host096d450*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096d450((::MobileObject *)(::fnv_0081ea40::MobileObject *)(reinterpret_cast<MobileObject*>(this)),
                       static_cast<int>(reinterpret_cast<MobileObject*>(this)->GetCurrentProcessLevel()), false, false,
                       (::MobileObject *)(::fnv_0081ea40::MobileObject *)(0));

    if (!m_magicCaster || !m_magicItem)
        reinterpret_cast<::fnv_0085a3d0::TESSaveLoadGameStandIn *>(((*reinterpret_cast<::fnv_0081ea40::SaveManager * *>(&::g_TESSaveLoadGame))))->AddFormToList((::TESForm *)(::fnv_0081ea40::MagicProjectile *)(this));
}
}  // namespace fnv_0081ea40

struct EventData
{
};
struct Event
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetType();
    int id;
    int state;
    EventData data;
};
struct Handler
{
    virtual void Handle4(void*, bool);
    virtual void Handle10(void*, bool);
    virtual void v2();
    virtual void v3();
    virtual void Handle1(void*, int, bool);
    virtual void v5();
    virtual void v6();
    virtual void HandleYes();
    virtual void HandleNo();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int HasError();
    virtual void v14();
    virtual void v15();
    virtual void SetEvent(Event*);
    virtual void v17();
    virtual void SetValue(int);
    bool FUN_00815480(Event*, intptr_t, bool);
};
extern char DAT_0107acc8[];
extern char DAT_0107acac[];
extern "C" void* __cdecl FUN_00ec43fb(Event*, int, const char*, const char*, int);
// Checks evt->data, dispatches by evt->GetType() to Handle4/Handle1/Handle10, else logs errors and calls SetEvent/SetValue then HandleYes or HandleNo.
// @fnv 0x00815480
bool Handler::FUN_00815480(Event* pEvent, intptr_t value, bool flag)
{
    if (reinterpret_cast<::fnv_004062a0::EffectItemList *>(&(pEvent->data))->HasDetrimentalEffect())
    {
        reinterpret_cast<::MagicCaster *>(this)->SetState((::MagicCaster__State)(5), (char *)(DAT_0107acc8));
        return false;
    }
    switch (pEvent->GetType())
    {
    case 4:
        Handle4(FUN_00ec43fb(pEvent, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183140)), DAT_01183060, 0), flag);
        return true;
        break;
    case 1:
        Handle1(FUN_00ec43fb(pEvent, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183140)), DAT_01183060, 0), value, flag);
        return true;
        break;
    case 10:
        Handle10(FUN_00ec43fb(pEvent, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183140)), DAT_01183060, 0), flag);
        return true;
    }
    if (HasError())
    {
        reinterpret_cast<::MagicCaster *>(this)->SetState((::MagicCaster__State)(6), (char *)(DAT_0107acac));
        return false;
    }
    SetEvent(pEvent);
    SetValue(value);
    if (reinterpret_cast<::fnv_00405f30::EILStandIn *>(&(pEvent->data))->HasNonDetrimentalEffect() && value)
    {
        HandleYes();
    }
    else
    {
        HandleNo();
    }
    return true;
}

struct HighProcess
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
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
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    HighProcess();
};
struct PrimaryRef
{
    virtual void v();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct SecondaryRef
{
    virtual void v();
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
    HighProcess* process;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
};
struct MobileObject : PrimaryRef, SecondaryRef
{
    MobileObject();
    ~MobileObject();
};
struct FUN_0081dbb0 : MobileObject
{
    float unk88, unk8c, unk90;
    int unk94, unk98, unk9c, unka0;
    FUN_0081dbb0();
};
// Initializes the object, zeroes its float and int fields, allocates a HighProcess, and calls FUN_00575690 with the result of FUN_007af430.
// @fnv 0x0081dbb0
FUN_0081dbb0::FUN_0081dbb0()
{
    reinterpret_cast<::FUN_0046a010_shell *>(this)->FUN_0046a010(true);
    unk90 = 0.0f;
    unk94 = 0;
    unk98 = 0;
    unk9c = 0;
    unka0 = 0;
    unk88 = 0.0f;
    unk8c = 0.0f;
    process = new HighProcess;
    reinterpret_cast<::Fn575690 *>(this)->FUN_00575690(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())));
}

struct MarkerErrorSub
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006(const char* name);
};

struct MarkerErrorObj
{
    unsigned char unk00[0x3c];
    MarkerErrorSub m_sub;
    unsigned char unk40[0xdc - 0x40];

    MarkerErrorObj();
};

struct MarkerErrorMgr
{
};

extern MarkerErrorObj* DAT_011dc774;

// Creates the marker_error.nif object on first call, registers it with DAT_011c3f2c, and returns the cached DAT_011dc774 instance.
// @fnv 0x0081e310
MarkerErrorObj* __cdecl GetMarkerErrorObj()
{
    if (DAT_011dc774 == 0)
    {
        MarkerErrorObj* pObj = new MarkerErrorObj();
        pObj->m_sub.v006("marker_error.nif");
        DAT_011dc774 = pObj;
        reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::MarkerErrorMgr * *>(&::g_dataHandler))))->AddFormToDataHandler((::TESForm *)(DAT_011dc774));
    }
    return DAT_011dc774;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float fX, float fY, float fZ);
public:
    static const ::NiPoint3 ZERO;
};
struct MADName
{
    char* m_kHandle;
    MADName(const char* pcString);
    ~MADName();
};
struct NiMemObject
{
};
struct FUN_00a75650 : NiMemObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48;
    FUN_00a75650();
};
struct MADNode;
struct MADObject
{
    virtual void v00(), v01(), v02();
    virtual MADNode* IsSceneNode();
    virtual void v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(),
        v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(),
        v34(), v35(), v36(), v37(), v38();
    virtual MADObject* GetObjectByName(const MADName& kName);
};
struct MADNode : MADObject
{
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v50(), v51(), v52(), v53(),
        v54();
    virtual void AttachChildInAvailableSlot(MADObject* pChild, bool abFirstAvailableSlot);
};
struct MADCount
{
};
struct MADSetting
{
};
struct MADHandle
{
    void* m_pObject;
    MADHandle& operator=(const MADHandle& kOther);
};
struct MagicAreaOwner
{
    virtual void v000(), v001(), v002(), v003(), v004(), v005(), v006(), v007(), v008(), v009();
    virtual void v010(), v011(), v012(), v013(), v014(), v015(), v016(), v017(), v018(), v019();
    virtual void v020(), v021(), v022(), v023(), v024(), v025(), v026(), v027(), v028(), v029();
    virtual void v030(), v031(), v032(), v033(), v034(), v035(), v036(), v037(), v038(), v039();
    virtual void v040(), v041(), v042(), v043(), v044(), v045(), v046(), v047(), v048(), v049();
    virtual void v050(), v051(), v052(), v053(), v054(), v055(), v056(), v057(), v058(), v059();
    virtual void v060(), v061(), v062(), v063(), v064(), v065(), v066(), v067(), v068(), v069();
    virtual void v070(), v071(), v072(), v073(), v074(), v075(), v076(), v077(), v078(), v079();
    virtual void v080(), v081(), v082(), v083(), v084(), v085(), v086(), v087(), v088(), v089();
    virtual void v090(), v091(), v092(), v093(), v094(), v095(), v096(), v097(), v098(), v099();
    virtual void v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109();
    virtual void v110(), v111(), v112(), v113(), v114(), v115();
    virtual MADObject* Get3D();
    MADHandle FUN_00931ed0();
    void CreateMagicAreaDisplay();
};
// Builds a sphere node named "MagicAreaDisplay" sized from the magic area count and setting, applies a material, and attaches it to the 3D root's node.
// @fnv 0x0081aab0
void MagicAreaOwner::CreateMagicAreaDisplay()
{
    MADObject* pRoot = Get3D();
    if (!pRoot || pRoot->GetObjectByName(MADName("MagicAreaDisplay")))
    {
        return;
    }
    MADNode* pNode2 = pRoot->IsSceneNode();
    if (pNode2)
    {
        float fRadius3 = reinterpret_cast<::FUN_00404420_shell *>((((::MADCount *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()))))->FUN_00404420() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MADSetting *>(&::originalRuntimeFloatSetting1112)))))) / reinterpret_cast<::FUN_009cdae0_shell *>((pRoot))->GetFloatAt64();
        MADObject* pDisplaySphere = ((::MADObject *)(::FUN_00c56680(fRadius3, 10, 10, (const ::Color4 *)(0))));
        ::AssignFixedString((char *)(pDisplaySphere), (intptr_t)&(const ::MADName &)(MADName("MagicAreaDisplay")), {});
        reinterpret_cast<::FUN_00440460_S *>((pDisplaySphere))->FUN_00440460((const ::V3 *)((*reinterpret_cast<const char (*)[]>((void *)&::NiPoint3::ZERO))));
        NiPoint3 kZero_(0.0f, 0.0f, 0.0f);
        ::GetLayerColor((uintptr_t)(FUN_00931ed0().m_pObject), (::NiColor &)(kZero_));
        FUN_00a75650* pMaterial = new FUN_00a75650;
        reinterpret_cast<::FUN_004534f0_shell *>((pMaterial))->FUN_004534f0((uintptr_t)((*reinterpret_cast<const float (*)[]>(&::DAT_011a9b7c))));
        reinterpret_cast<::FUN_004534f0_shell *>((pMaterial))->FUN_004534f0((uintptr_t)((*reinterpret_cast<const float (*)[]>(&::DAT_011a9b7c))));
        reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>((pMaterial))->FUN_004bc450((const ::fnv_004bc450::C3 *)&(kZero_));
        reinterpret_cast<::FUN_00439410_cls *>((pDisplaySphere))->FUN_00439410((::ArgObject *)(pMaterial));
        pNode2->AttachChildInAvailableSlot(pDisplaySphere, true);
        reinterpret_cast<::FUN_00a5a040_Class *>((pNode2))->FUN_00a5a040();
    }
}

struct ActorDeletionQueue
{
};

struct Interface
{
};

extern const double DAT_010290d0;

struct Class_0081df60
{
    virtual void vf_000();
    virtual void vf_001();
    virtual void vf_002();
    virtual void vf_003();
    virtual void vf_004();
    virtual void vf_005();
    virtual void vf_006();
    virtual void vf_007();
    virtual void vf_008();
    virtual void vf_009();
    virtual void vf_00a();
    virtual void vf_00b();
    virtual void vf_00c();
    virtual void vf_00d();
    virtual void vf_00e();
    virtual void vf_00f();
    virtual void vf_010();
    virtual void vf_011();
    virtual void vf_012();
    virtual void vf_013();
    virtual void vf_014();
    virtual void vf_015();
    virtual void vf_016();
    virtual void vf_017();
    virtual void vf_018();
    virtual void vf_019();
    virtual void vf_01a();
    virtual void vf_01b();
    virtual void vf_01c();
    virtual void vf_01d();
    virtual void vf_01e();
    virtual void vf_01f();
    virtual void vf_020();
    virtual void vf_021();
    virtual void vf_022();
    virtual void vf_023();
    virtual void vf_024();
    virtual void vf_025();
    virtual void vf_026();
    virtual void vf_027();
    virtual void vf_028();
    virtual void vf_029();
    virtual void vf_02a();
    virtual void vf_02b();
    virtual void vf_02c();
    virtual void vf_02d();
    virtual void vf_02e();
    virtual void vf_02f();
    virtual void vf_030();
    virtual void vf_031();
    virtual void vf_032();
    virtual void vf_033();
    virtual void vf_034();
    virtual void vf_035();
    virtual void vf_036();
    virtual void vf_037();
    virtual void vf_038();
    virtual void vf_039();
    virtual void vf_03a();
    virtual void vf_03b();
    virtual void vf_03c();
    virtual void vf_03d();
    virtual void vf_03e();
    virtual void vf_03f();
    virtual void vf_040();
    virtual void vf_041();
    virtual void vf_042();
    virtual void vf_043();
    virtual void vf_044();
    virtual void vf_045();
    virtual void vf_046();
    virtual void vf_047();
    virtual void vf_048();
    virtual void vf_049();
    virtual void vf_04a();
    virtual void vf_04b();
    virtual void vf_04c();
    virtual void vf_04d();
    virtual void vf_04e();
    virtual void vf_04f();
    virtual void vf_050();
    virtual void vf_051();
    virtual void vf_052();
    virtual void vf_053();
    virtual void vf_054();
    virtual void vf_055();
    virtual void vf_056();
    virtual void vf_057();
    virtual void vf_058();
    virtual void vf_059();
    virtual void vf_05a();
    virtual void vf_05b();
    virtual void vf_05c();
    virtual void vf_05d();
    virtual void vf_05e();
    virtual void vf_05f();
    virtual void vf_060();
    virtual void vf_061();
    virtual void vf_062();
    virtual void vf_063();
    virtual void vf_064();
    virtual void vf_065();
    virtual void vf_066();
    virtual void vf_067();
    virtual void vf_068();
    virtual void vf_069();
    virtual void vf_06a();
    virtual void vf_06b();
    virtual void vf_06c();
    virtual void vf_06d();
    virtual void vf_06e();
    virtual void vf_06f();
    virtual void vf_070();
    virtual void vf_071();
    virtual void vf_072();
    virtual void vf_073();
    virtual void vf_074();
    virtual void vf_075();
    virtual void vf_076();
    virtual void vf_077();
    virtual void vf_078();
    virtual void vf_079();
    virtual void vf_07a();
    virtual void vf_07b();
    virtual void vf_07c();
    virtual void vf_07d();
    virtual void vf_07e();
    virtual void vf_07f();
    virtual void vf_080();
    virtual void vf_081();
    virtual void vf_082();
    virtual void vf_083();
    virtual void vf_084();
    virtual void vf_085();
    virtual void vf_086();
    virtual void vf_087();
    virtual void vf_088();
    virtual void vf_089();
    virtual void vf_08a();
    virtual void vf_08b();
    virtual void vf_08c();
    virtual void vf_08d();
    virtual void vf_08e();
    virtual void vf_08f();
    virtual void vf_090();
    virtual void vf_091();
    virtual void vf_092();
    virtual void vf_093();
    virtual void vf_094();
    virtual void vf_095();
    virtual void vf_096();
    virtual void vf_097();
    virtual void vf_098();
    virtual void vf_099();
    virtual void vf_09a();
    virtual void vf_09b();
    virtual void vf_09c();
    virtual void vf_09d();
    virtual void vf_09e();
    virtual void vf_09f();
    virtual void vf_0a0();
    virtual void vf_0a1();
    virtual void vf_0a2();
    virtual void vf_0a3();
    virtual void vf_0a4();
    virtual void vf_0a5();
    virtual void vf_0a6();
    virtual void vf_0a7();
    virtual void vf_0a8();
    virtual void vf_0a9();
    virtual void vf_0aa();
    virtual void vf_0ab();
    virtual void vf_0ac();
    virtual void vf_0ad();
    virtual void vf_0ae();
    virtual void vf_0af();
    virtual void vf_0b0();
    virtual void vf_0b1();
    virtual void vf_0b2();
    virtual void vf_0b3();
    virtual void vf_0b4();
    virtual void vf_0b5();
    virtual void vf_0b6();
    virtual void vf_0b7();
    virtual void vf_0b8();
    virtual void vf_0b9();
    virtual void vf_0ba();
    virtual void vf_0bb();
    virtual void vf_0bc();
    virtual void vf_0bd();
    virtual void vf_2f8(float dt);

    char pad[0x90 - 4];
    float unk90;
    char pad2[0xa4 - 0x90 - 4];
    float unka4;

    void Update(int param_1);
};

// Computes clamped delta time from the global clock, accumulates it into unk90, and calls vf_2f8 when the interface check passes.
// @fnv 0x0081df60
void Class_0081df60::Update(int param_1)
{
    float dt3;
    float time = reinterpret_cast<::FUN_0096d490_shell *>(&((*reinterpret_cast<::ActorDeletionQueue *>(&::g_011e0e80))))->FUN_0096d490();
    dt3 = time - unka4;

    if (unka4 > time || unka4 < 0.0)
    {
        dt3 = 0.0f;
        if (time > 0.0 && time < 0.30000001192092896)
        {
            dt3 = time;
        }
    }

    unka4 = time;
    if (reinterpret_cast<::FaderManager *>((::DAT_011d8804))->GetFadeValue((::FADER_ENUM)(1)) > 0.0)
        return;
    unk90 += dt3;
    vf_2f8(dt3);
}

namespace fnv_0081e040 {
struct Vector3
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

struct GameTimerRecord
{
};

struct S86a0
{
};


struct Host096d450
{
};


// The caster's current spell, used when no spell is passed in.
struct CasterSpellView
{
    char pad00[0x14];
    void* pCurrentSpell;
};

struct FUN_0080f810
{
    unsigned char m_data[0xc4];

    FUN_0080f810(void* a, int b, GameTimerRecord* c, void* d, Vector3 e, Vector3 f, unsigned int g, unsigned int h);
};

struct FUN_00811980
{
    unsigned char m_data[0xd8];

    FUN_00811980(void* a, int b, GameTimerRecord* c, void* d, Vector3 e, Vector3 f);
};

struct FUN_00819360
{
    unsigned char m_data[0xd0];

    FUN_00819360(void* a, int b, GameTimerRecord* c, void* d, Vector3 e, Vector3 f, unsigned int g, unsigned int h);
};

struct FUN_00822920
{
    unsigned char m_data[0xa8];

    FUN_00822920(void* a, int b, GameTimerRecord* c, void* d, Vector3 e, Vector3 f);
};

FUN_0080f810::FUN_0080f810(void*, int, GameTimerRecord*, void*, Vector3, Vector3, unsigned int, unsigned int)
{}

FUN_00811980::FUN_00811980(void*, int, GameTimerRecord*, void*, Vector3, Vector3)
{}

FUN_00819360::FUN_00819360(void*, int, GameTimerRecord*, void*, Vector3, Vector3, unsigned int, unsigned int)
{}

FUN_00822920::FUN_00822920(void*, int, GameTimerRecord*, void*, Vector3, Vector3)
{}

// Constructs one of four class instances based on projectile->FUN_004086a0() and passes it to DAT_011e0e80.
// @fnv 0x0081e040
void __cdecl FUN_0081e040(void* a, unsigned int b, unsigned int c, int d, GameTimerRecord* timer, S86a0* projectile,
                          Vector3 first, Vector3 second)
{
    void* result = 0;
    void* currentTime;

    currentTime = projectile ? static_cast<void*>(projectile) : reinterpret_cast<CasterSpellView *>(timer)->pCurrentSpell;

    switch (reinterpret_cast<::S86a0 *>((projectile))->FUN_004086a0())
    {
    case 0:
        result = new FUN_0080f810(a, d, timer, currentTime, first, second, b, c);
        break;

    case 1:
        result = new FUN_00811980(a, d, timer, currentTime, first, second);
        break;

    case 3:
        result = new FUN_00819360(a, d, timer, currentTime, first, second, b, c);
        break;

    case 2:
        result = new FUN_00822920(a, d, timer, currentTime, first, second);
        break;
    }

    if (result)
        reinterpret_cast<::Host096d450 *>(&((*reinterpret_cast<::fnv_0081e040::Host096d450 *>(&::g_011e0e80))))->FUN_0096d450((::MobileObject *)(result), 0, 0, 0, (::MobileObject *)(void *)(0));
}
}  // namespace fnv_0081e040

class Point80F
{
  public:
    float x, y, z;
};

class Filter80F
{
  public:
    Filter80F();
    unsigned int m_uiBits;
};

class Node80F;

class WorldObject80F
{
  public:
    Filter80F GetFilter();
};

class CollisionObject80F
{
  public:
};

class Shape80F
{
  public:
    Shape80F(float fScale, int iType);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class World80F
{
  public:
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
    virtual void HandleNode(Node80F* pkNode, int iA, int iB, unsigned int uiFilterInfo, int iC);
};

class ControllerInfo80F
{
  public:
    ControllerInfo80F(int iType);
    ~ControllerInfo80F();
    __m128 m_q00;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
    __m128 m_qb0;
};

class Actor80F;

class Controller80F
{
  public:
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
    virtual void SetState(int iState);
    static void* operator new(std::size_t uiSize);
    static void operator delete(void* pvMem);
    Controller80F(ControllerInfo80F& kInfo, Actor80F* pkActor);
    World80F* GetWorld();
    Filter80F GetFilter();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
};

class ControllerPtr80F
{
  public:
    ControllerPtr80F(Controller80F* pkController);
    ControllerPtr80F(const ControllerPtr80F& kOther);
    ~ControllerPtr80F();
    Controller80F* m_pPointer;
};

class Process80F
{
  public:
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
    virtual void SetController(ControllerPtr80F spController);
};

class Middle80F
{
  public:
};

class Target80F
{
  public:
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
    virtual bool IsActor();
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
    virtual Node80F* Get3D();
    Filter80F GetFilter();
};

class Owner80F
{
  public:
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
    virtual Target80F* GetTarget();
};

class Actor80F
{
  public:
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
    virtual Node80F* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Point80F* GetPos();
    void FUN_0080feb0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    Process80F* m_pkProcess;
};

class Game80F
{
  public:
};


// @fnv 0x0080feb0
void Actor80F::FUN_0080feb0()
{
    if (!m_pkProcess || (reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60()))
        return;
    Controller80F* pkController = ((::Controller80F *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    Middle80F* pkMiddle = ((::Middle80F *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    World80F* pkWorld = pkMiddle ? ((::World80F *)(reinterpret_cast<::FUN_004543c0_cls *>((pkMiddle))->FUN_004543c0())) : 0;
    if (!pkController)
    {
        ControllerInfo80F kInfo(1);
        reinterpret_cast<::FUN_00810550_class *>(&(kInfo))->FUN_00810550(1.0f);
        reinterpret_cast<::FUN_008ac890_shell *>(&(kInfo))->SetWaterForm((::TESWaterForm *)(::Node80F *)(Get3D()));
        reinterpret_cast<::FUN_00810510_Class *>(&(kInfo))->FUN_00810510((*(const ::NiPoint3 *)(GetPos())));
        reinterpret_cast<::FUN_00857230_shell *>(&(kInfo))->SetSound((::TESSound *)(pkWorld));
        reinterpret_cast<::FUN_00407860_class *>(&(kInfo))->FUN_00407860(0.0f);
        reinterpret_cast<::FUN_008105c0_Class *>(&(kInfo))->SetPointer(new Shape80F(1.0f, 1));
        reinterpret_cast<::FUN_00810530_c *>(&(kInfo))->FUN_00810530(0);
        if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::Game80F * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
        {
            Target80F* pkTarget = 0;
            if (((::Owner80F *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)))
                pkTarget = ((::Owner80F *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->GetTarget();
            if (pkTarget)
            {
                if (pkTarget->IsActor())
                {
                    reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter80F &)(pkTarget->GetFilter()))->FUN_004a3a20());
                }
                else
                {
                    CollisionObject80F* pkCollision = ((::CollisionObject80F *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::Node80F *)(pkTarget->Get3D()))));
                    WorldObject80F* pkObject = pkCollision ? ((::WorldObject80F *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision)))) : 0;
                    reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, pkObject ? reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter80F &)(pkObject->GetFilter()))->FUN_004a3a20() : FUN_005dbe10());
                }
            }
            else
            {
                CollisionObject80F* pkCollision = ((::CollisionObject80F *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::Node80F *)(Get3D()))));
                WorldObject80F* pkObject = pkCollision ? ((::WorldObject80F *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision)))) : 0;
                reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, pkObject ? reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter80F &)(pkObject->GetFilter()))->FUN_004a3a20() : FUN_005dbe10());
            }
        }
        else
        {
            reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, 0);
        }
        reinterpret_cast<::FUN_00810570_shell *>(&(kInfo))->SetAssociatedActorValue(6);
        pkController = new Controller80F(kInfo, this);
        reinterpret_cast<::FUN_008106b0_Class *>((pkController))->FUN_008106b0(1.0f);
        reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((pkController))->FUN_00810610(((bool)(::FUN_00525420())));
        reinterpret_cast<::FUN_008105e0_Class *>((pkController))->FUN_008105e0(1);
        m_pkProcess->SetController(pkController);
        reinterpret_cast<::FUN_00810640_class *>((pkController))->FUN_00810640((intptr_t)(this));
    }
    if (pkController)
    {
        if (pkMiddle && pkWorld)
            ::FUN_0057b1d0((char *)(pkController), reinterpret_cast<::FUN_005471e0_shell *>((pkMiddle))->FUN_005471e0());
        else
            ::FUN_0057b1d0((char *)(pkController), ::DAT_01015f5c);
        World80F* pkOldWorld = pkController->GetWorld();
        reinterpret_cast<::C70CharacterController *>((pkController))->FUN_00c70c90((::WorldProxy *)(pkWorld));
        Node80F* pkNode = Get3D();
        Node80F* pkOldNode = ((::Node80F *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660()));
        bool bReset = true;
        if (pkOldNode != pkNode)
        {
            reinterpret_cast<::S_00c6d7a0_Obj *>((pkController))->FUN_00c6d7a0((intptr_t)(pkNode));
            if (pkWorld && ::FUN_004bae00((const char *)(pkWorld)))
            {
                pkController->SetState(0);
                ::CopyBlock48(((::Node80F *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660())), (const void *)(1));
            }
            ::FUN_00c6a350((::NiAVObject *)(pkNode), 4, 1, 0, 1);
            bReset = true;
        }
        Point80F kPos = *GetPos();
        if (pkOldWorld != pkWorld)
        {
            if (pkOldWorld)
                ::FUN_00c69ee0((::NiAVObject *)(pkNode), 1, 0);
            kPos.z += 8.0;
            bReset = true;
        }
        if (pkWorld)
        {
            reinterpret_cast<::S005620e0_Object *>((pkController))->FUN_005620e0((const ::S005620e0_Source *)&(kPos));
            if (bReset)
            {
                Filter80F kFilter = pkController->GetFilter();
                unsigned int uiFilterInfo = reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(kFilter))->FUN_004a3a20();
                pkWorld->HandleNode(pkNode, 1, 0, uiFilterInfo, 0);
            }
            else
            {
                ::FUN_00c69f50((::S_00c69f50_Obj *)(pkNode), 1, 0);
            }
        }
    }
}

namespace fnv_00813f30 {

class Point80F
{
  public:
    float x, y, z;
};

class Filter80F
{
  public:
    Filter80F();
    unsigned int m_uiBits;
};

class Node80F;

class WorldObject80F
{
  public:
    Filter80F GetFilter();
};

class CollisionObject80F
{
  public:
};

class Shape80F
{
  public:
    Shape80F(float fScale, int iType);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class World80F
{
  public:
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
    virtual void HandleNode(Node80F* pkNode, int iA, int iB, unsigned int uiFilterInfo, int iC);
};

class ControllerInfo80F
{
  public:
    ControllerInfo80F(int iType);
    ~ControllerInfo80F();
    __m128 m_q00;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
    __m128 m_qb0;
};

class Actor80F;

class Controller80F
{
  public:
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
    virtual void SetState(int iState);
    static void* operator new(std::size_t uiSize);
    static void operator delete(void* pvMem);
    Controller80F(ControllerInfo80F& kInfo, Actor80F* pkActor);
    World80F* GetWorld();
    Filter80F GetFilter();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
};

class ControllerPtr80F
{
  public:
    ControllerPtr80F(Controller80F* pkController);
    ControllerPtr80F(const ControllerPtr80F& kOther);
    ~ControllerPtr80F();
    Controller80F* m_pPointer;
};

class Process80F
{
  public:
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
    virtual void SetController(ControllerPtr80F spController);
};

class Middle80F
{
  public:
};

class Target80F
{
  public:
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
    virtual bool IsActor();
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
    virtual Node80F* Get3D();
    Filter80F GetFilter();
};

class Owner80F
{
  public:
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
    virtual Target80F* GetTarget();
};

class Actor80F
{
  public:
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
    virtual Node80F* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Point80F* GetPos();
    void FUN_00813f30();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
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
    Process80F* m_pkProcess;
};

class Game80F
{
  public:
};


// @fnv 0x00813f30
void Actor80F::FUN_00813f30()
{
    if (!m_pkProcess || (reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60()))
        return;
    Controller80F* pkController = ((::fnv_00813f30::Controller80F *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    Middle80F* pkMiddle = ((::fnv_00813f30::Middle80F *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    World80F* pkWorld = pkMiddle ? ((::fnv_00813f30::World80F *)(reinterpret_cast<::FUN_004543c0_cls *>((pkMiddle))->FUN_004543c0())) : 0;
    if (!pkController)
    {
        ControllerInfo80F kInfo(1);
        reinterpret_cast<::FUN_00810550_class *>(&(kInfo))->FUN_00810550(1.0f);
        reinterpret_cast<::FUN_008ac890_shell *>(&(kInfo))->SetWaterForm((::TESWaterForm *)(::fnv_00813f30::Node80F *)(Get3D()));
        reinterpret_cast<::FUN_00810510_Class *>(&(kInfo))->FUN_00810510((*(const ::NiPoint3 *)(GetPos())));
        reinterpret_cast<::FUN_00857230_shell *>(&(kInfo))->SetSound((::TESSound *)(pkWorld));
        reinterpret_cast<::FUN_00407860_class *>(&(kInfo))->FUN_00407860(0.0f);
        reinterpret_cast<::FUN_008105c0_Class *>(&(kInfo))->SetPointer(new Shape80F(1.0f, 1));
        reinterpret_cast<::FUN_00810530_c *>(&(kInfo))->FUN_00810530(0);
        if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::fnv_00813f30::Game80F * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
        {
            Target80F* pkTarget = 0;
            if (((::fnv_00813f30::Owner80F *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)))
                pkTarget = ((::fnv_00813f30::Owner80F *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->GetTarget();
            if (pkTarget)
            {
                if (pkTarget->IsActor())
                {
                    reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::fnv_00813f30::Filter80F &)(pkTarget->GetFilter()))->FUN_004a3a20());
                }
                else
                {
                    CollisionObject80F* pkCollision = ((::fnv_00813f30::CollisionObject80F *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::fnv_00813f30::Node80F *)(pkTarget->Get3D()))));
                    WorldObject80F* pkObject = pkCollision ? ((::fnv_00813f30::WorldObject80F *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision)))) : 0;
                    reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, pkObject ? reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::fnv_00813f30::Filter80F &)(pkObject->GetFilter()))->FUN_004a3a20() : ::FUN_005dbe10());
                }
            }
            else
            {
                CollisionObject80F* pkCollision = ((::fnv_00813f30::CollisionObject80F *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::fnv_00813f30::Node80F *)(Get3D()))));
                WorldObject80F* pkObject = pkCollision ? ((::fnv_00813f30::WorldObject80F *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision)))) : 0;
                reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, pkObject ? reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::fnv_00813f30::Filter80F &)(pkObject->GetFilter()))->FUN_004a3a20() : ::FUN_005dbe10());
            }
        }
        else
        {
            reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(7, 0);
        }
        reinterpret_cast<::FUN_00810570_shell *>(&(kInfo))->SetAssociatedActorValue(6);
        pkController = new Controller80F(kInfo, this);
        reinterpret_cast<::FUN_008106b0_Class *>((pkController))->FUN_008106b0(1.0f);
        reinterpret_cast<::FUN_008105e0_Class *>((pkController))->FUN_008105e0(1);
        reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((pkController))->FUN_00810610(((bool)(::FUN_00525420())));
        m_pkProcess->SetController(pkController);
        reinterpret_cast<::FUN_00810640_class *>((pkController))->FUN_00810640((intptr_t)(this));
    }
    if (pkController)
    {
        if (pkMiddle && pkWorld)
            ::FUN_0057b1d0((char *)(pkController), reinterpret_cast<::FUN_005471e0_shell *>((pkMiddle))->FUN_005471e0());
        else
            ::FUN_0057b1d0((char *)(pkController), ::DAT_01015f5c);
        World80F* pkOldWorld = pkController->GetWorld();
        reinterpret_cast<::C70CharacterController *>((pkController))->FUN_00c70c90((::WorldProxy *)(pkWorld));
        Node80F* pkNode = Get3D();
        Node80F* pkOldNode = ((::fnv_00813f30::Node80F *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660()));
        bool bReset = true;
        if (pkOldNode != pkNode)
        {
            reinterpret_cast<::S_00c6d7a0_Obj *>((pkController))->FUN_00c6d7a0((intptr_t)(pkNode));
            if (pkWorld && ::FUN_004bae00((const char *)(pkWorld)))
            {
                pkController->SetState(0);
                ::CopyBlock48(((::fnv_00813f30::Node80F *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660())), (const void *)(1));
            }
            ::FUN_00c6a350((::NiAVObject *)(pkNode), 4, 1, 0, 1);
            bReset = true;
        }
        Point80F kPos = *GetPos();
        if (pkOldWorld != pkWorld)
        {
            if (pkOldWorld)
                ::FUN_00c69ee0((::NiAVObject *)(pkNode), 1, 0);
            kPos.z += 8.0;
            bReset = true;
        }
        if (pkWorld)
        {
            reinterpret_cast<::S005620e0_Object *>((pkController))->FUN_005620e0((const ::S005620e0_Source *)&(kPos));
            if (bReset)
            {
                Filter80F kFilter = pkController->GetFilter();
                unsigned int uiFilterInfo = reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(kFilter))->FUN_004a3a20();
                pkWorld->HandleNode(pkNode, 1, 0, uiFilterInfo, 0);
            }
            else
            {
                ::FUN_00c69f50((::S_00c69f50_Obj *)(pkNode), 1, 0);
            }
        }
    }
}
}  // namespace fnv_00813f30

namespace fnv_00819ca0 {

struct Actor;
struct Visual;
struct Scene;
struct Resource;
struct Vector3
{
    float x, y, z;
};
struct Handle
{
    void* p;
};
struct NodeHandle
{
    Visual* p;
    NodeHandle(Visual*);
    NodeHandle(const NodeHandle&);
    ~NodeHandle();
};
struct __declspec(align(16)) FxState
{
    __m128 unk00;
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
    FxState(int);
    ~FxState();
};
struct ColorData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ColorData(float, int);
};
struct Resource
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool check();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void* GetUnderlyingObject();
    Handle* FUN_00931ed0(Handle*);
    Handle* FUN_0043b4f0(Handle*);
};
struct Scene
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual Resource* getTexture();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void apply(void*, int, int, int, int);
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void add(NodeHandle);
};
struct Visual
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void updateSwitch(int);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    Visual(FxState*, Actor*);
    static void* operator new(std::size_t);
    static void operator delete(void*);
    Scene* FUN_00621ad0();
    Handle FUN_0070c440();
};
struct Actor
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void* GetUnderlyingObject();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual Vector3* getPosition();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual float getIntensity();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void notifyChanged();
    int unk04;
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
    int unk60;
    int unk64;
    Scene* scene;
    void FUN_00819ca0();
};
struct RenderGlobals
{
};
// @fnv 0x00819ca0
void Actor::FUN_00819ca0()
{
    if (!scene || (reinterpret_cast<::FUN_0045cd60_shell *>((scene))->FUN_0045cd60()))
        return;
    Visual* active = ((::fnv_00819ca0::Visual *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    Scene* parent = ((::fnv_00819ca0::Scene *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    Scene* target = parent ? ((::fnv_00819ca0::Scene *)(reinterpret_cast<::FUN_004543c0_cls *>((parent))->FUN_004543c0())) : 0;
    if (!active)
    {
        FxState state(1);
        reinterpret_cast<::FUN_00810550_class *>(&(state))->FUN_00810550(getIntensity());
        reinterpret_cast<::FUN_008ac890_shell *>(&(state))->SetWaterForm((::TESWaterForm *)(void *)(GetUnderlyingObject()));
        reinterpret_cast<::FUN_00810510_Class *>(&(state))->FUN_00810510((*(const ::NiPoint3 *)(getPosition())));
        reinterpret_cast<::FUN_00857230_shell *>(&(state))->SetSound((::TESSound *)(target));
        reinterpret_cast<::FUN_00407860_class *>(&(state))->FUN_00407860(0.0f);
        reinterpret_cast<::FUN_008105c0_Class *>(&(state))->SetPointer(new ColorData(1.0f, 1));
        reinterpret_cast<::FUN_00810530_c *>(&(state))->FUN_00810530(0);
        Resource* texture = 0;
        if (((::fnv_00819ca0::Scene *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)))
        {
            Scene* sceneObject = ((::fnv_00819ca0::Scene *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster));
            texture = sceneObject->getTexture();
        }
        if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::fnv_00819ca0::RenderGlobals * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
        {
            if (texture)
            {
                if (texture->check())
                {
                    Handle temporary;
                    reinterpret_cast<::FUN_00810590_Class *>(&(state))->FUN_00810590(7, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((texture->FUN_00931ed0(&temporary)))->FUN_004a3a20())));
                }
                else
                {
                    Resource* base = ((::fnv_00819ca0::Resource *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(void *)(texture->GetUnderlyingObject()))));
                    Resource* material = base ? ((::fnv_00819ca0::Resource *)(::fnv_006fa820::FUN_006fa820((const char *)(base)))) : 0;
                    Handle temporary;
                    reinterpret_cast<::FUN_00810590_Class *>(&(state))->FUN_00810590(7,
                                       material ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((material->FUN_0043b4f0(&temporary)))->FUN_004a3a20())) : ((int)(::FUN_005dbe10())));
                }
            }
            else
            {
                Resource* base = ((::fnv_00819ca0::Resource *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(void *)(GetUnderlyingObject()))));
                Resource* material = base ? ((::fnv_00819ca0::Resource *)(::fnv_006fa820::FUN_006fa820((const char *)(base)))) : 0;
                Handle temporary;
                reinterpret_cast<::FUN_00810590_Class *>(&(state))->FUN_00810590(7, material ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((material->FUN_0043b4f0(&temporary)))->FUN_004a3a20())) : ((int)(::FUN_005dbe10())));
            }
        }
        else
            reinterpret_cast<::FUN_00810590_Class *>(&(state))->FUN_00810590(7, 0);
        reinterpret_cast<::FUN_00810570_shell *>(&(state))->SetAssociatedActorValue(6);
        active = new Visual(&state, this);
        reinterpret_cast<::FUN_008106b0_Class *>((active))->FUN_008106b0(1.0f);
        reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((active))->FUN_00810610(((bool)(::FUN_00525420())));
        reinterpret_cast<::FUN_008105e0_Class *>((active))->FUN_008105e0(1);
        scene->add(active);
        reinterpret_cast<::FUN_00810640_class *>((active))->FUN_00810640((intptr_t)(this));
    }
    if (active)
    {
        if (parent && target)
            ::FUN_0057b1d0((char *)(active), reinterpret_cast<::FUN_005471e0_shell *>((parent))->FUN_005471e0());
        else
            ::FUN_0057b1d0((char *)(active), ::DAT_01015f5c);
        Scene* initial = active->FUN_00621ad0();
        reinterpret_cast<::C70CharacterController *>((active))->FUN_00c70c90((::WorldProxy *)(target));
        void* expected = GetUnderlyingObject();
        void* actual = ((void *)(reinterpret_cast<::FUN_00810660_Class *>((active))->FUN_00810660()));
        bool dirty = true;
        if (actual != expected)
        {
            reinterpret_cast<::S_00c6d7a0_Obj *>((active))->FUN_00c6d7a0((intptr_t)(expected));
            if (target && ::FUN_004bae00((const char *)(target)))
            {
                active->updateSwitch(0);
                ::CopyBlock48(((void *)(reinterpret_cast<::FUN_00810660_Class *>((active))->FUN_00810660())), (const void *)(1));
                notifyChanged();
            }
            ::FUN_00c6a350((::NiAVObject *)(expected), 4, 1, 0, 1);
            dirty = true;
        }
        Vector3 position = *getPosition();
        if (initial != target)
        {
            if (initial)
                ::FUN_00c69ee0((::NiAVObject *)(expected), 1, 0);
            position.z += ::DAT_010240b0;
            dirty = true;
        }
        if (target)
        {
            reinterpret_cast<::S005620e0_Object *>((active))->FUN_005620e0((const ::S005620e0_Source *)(::fnv_00819ca0::Vector3 *)(&position));
            if (dirty)
            {
                Handle appearanceHandle = active->FUN_0070c440();
                int appearance = ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(appearanceHandle))->FUN_004a3a20()));
                target->apply(expected, 1, 0, appearance, 0);
            }
            else
                ::FUN_00c69f50((::S_00c69f50_Obj *)(expected), 1, 0);
        }
    }
}
}  // namespace fnv_00819ca0
#include "generated/data/fallout/magic/magicprojectile.inc"
