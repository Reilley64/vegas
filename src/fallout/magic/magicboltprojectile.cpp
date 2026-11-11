
// src/fallout/magic/magicboltprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicboltprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/magic_projectile_fields.h"
#include "fnv/save_load_game_view.h"
#include <cstdint>
#include <new>
#include "fnv/decl/BSXFlags_shell.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/EffectBase.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004610f0_Class.h"
#include "fnv/decl/FUN_00484d20_Class.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f00e0_shell.h"
#include "fnv/decl/FUN_00507780.h"
#include "fnv/decl/FUN_005077a0_Class.h"
#include "fnv/decl/FUN_0056d230_Class.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005f9b10_class.h"
#include "fnv/decl/FUN_00689920_shell.h"
#include "fnv/decl/FUN_00803a50_shell.h"
#include "fnv/decl/FUN_00803a70_shell.h"
#include "fnv/decl/FUN_00803a90_shell.h"
#include "fnv/decl/FUN_00803b30_shell.h"
#include "fnv/decl/FUN_00803b50_shell.h"
#include "fnv/decl/FUN_00810f90_shell.h"
#include "fnv/decl/FUN_008126e0_shell.h"
#include "fnv/decl/FUN_00812870_t.h"
#include "fnv/decl/FUN_0081e8c0_shell.h"
#include "fnv/decl/FUN_0081e980_shell.h"
#include "fnv/decl/FUN_00821620_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008ce390_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59660_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/ImpactOwner.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/P142Caster.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/VectorSourceB00.h"
#include "fnv/decl/bhkCharacterListener.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_00570f70__Obj570.h"
#include "fnv/decl/fnv_00810ff0__Ths810.h"
#include "fnv/decl/fnv_0081ea40__MagicProjectile.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00932520__FUN_00932520_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00689000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_0080f000.h"
#include "fnv/symbols_00bc1000.h"
#include "fnv/symbols_00bc2000.h"
#include "fnv/symbols_00ee8000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_00811000.h"
#include "fnv/symbols_00bc0000.h"
#include <stdlib.h>
#include <math.h>
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_0081c4a0_cls.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/fnv_0080fb00__FUN_0080fb00_Class.h"
#include "fnv/decl/fnv_00813f30__Actor80F.h"
#include "fnv/decl/xActor_2.h"
struct RefH
{
};

struct FUN_00811930_shell : RefH
{
    bool IsNotDeleted() const;
};

// @fnv 0x00811930
bool FUN_00811930_shell::IsNotDeleted() const
{
    return !reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80();
}


// @fnv 0x00811e00
void FUN_00811e00(int value)
{
    DAT_011ae61c = value;
}

struct FUN_008133d0_shell
{
    void FUN_008133d0(int value);
    unsigned int pad00[0x2b];
    int unkac;
};

// @fnv 0x008133d0
void FUN_008133d0_shell::FUN_008133d0(int value)
{
    this->unkac = value;
}

struct FUN_00811950_shell
{
    void FUN_00811e10();
    void* DestroyIfFlagged(unsigned int flags);
};
struct FUN_0081e830_shell
{
    unsigned short GetSaveRecordSize(unsigned int flags);
};
struct TESSaveLoadGame
{
};
struct SinglyLinkedListNode
{
    SinglyLinkedListNode* pNext;
    unsigned int pad04[0x6];
    void* unk1c;
};
struct FUN_00814590_shell
{
    SinglyLinkedListNode* m_pListNode;
    unsigned short GetSaveSize(unsigned int flags);
    unsigned int pad04[0x2b];
    void* unkb0;
};
// @fnv 0x00814590
unsigned short FUN_00814590_shell::GetSaveSize(unsigned int flags)
{
    unsigned short size = 0;
    size += ((FUN_0081e830_shell*)this)->GetSaveRecordSize(flags);
    size += 4;
    size += 4;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x30)
    {
        size += 0xc;
        size += 0x10;
        size += 4;
    }
    size += 4;
    size += 2;
    SinglyLinkedListNode* bolt = *(SinglyLinkedListNode**)&this->unkb0;
    while (bolt)
    {
        size += 4;
        bolt = *(SinglyLinkedListNode**)&bolt->unk1c;
    }
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x71)
        size += 4;
    return size;
}

struct H006815c0
{
};
struct FUN_00814aa0
{
    H006815c0 m0;
    char pad0[11];
    H006815c0 m1;
    char pad1[19];
    intptr_t f20;
    FUN_00814aa0();
};
class Sub4_b4201
{
  public:
    unsigned int m_00;
    ~Sub4_b4201();
};

class Sub16_b4201
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~Sub16_b4201();
};

class FUN_008121a0_cls
{
  public:
    Sub4_b4201 m_00;
    Sub16_b4201 m_04;
    Sub4_b4201 m_14;
    Sub4_b4201 m_18;
    ~FUN_008121a0_cls();
};

// @fnv 0x008121a0
FUN_008121a0_cls::~FUN_008121a0_cls()
{}

struct NiPoint3
{
    float x, y, z;
public:
    float ComputeMagnitude() const;
};
struct Quat16
{
    float a, b, c, d;
    Quat16();
};
struct Node3D
{
};
struct PathReq
{
};
struct PathPtr
{
    operator PathReq*() const;
};
struct Form
{
};
struct NameStr
{
    operator const char*() const;
};
struct AreaBoltNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NameStr name;
    AreaBoltNode* next;
};
struct SaveGame
{
};
struct SaveBaseObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    PathPtr pathing;
    int unkAC;
    AreaBoltNode* m_pListNode;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    Form* pForm;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
};
struct ThisObj : SaveBaseObj
{
    virtual Node3D* GetNode3D();
    void SaveAreaBoltData(int arg);
};

// Saves the object's base data, position/rotation and smoothing when version >= 0x30, its form refID, and each linked bolt node's refID with a count.
// @fnv 0x00814670
void ThisObj::SaveAreaBoltData(int arg)
{
    reinterpret_cast<::FUN_0081e8c0_shell *>(this)->FUN_0081e8c0(arg);
    reinterpret_cast<::FUN_008579b0_shell *>((((SaveGame*)g_TESSaveLoadGame)))->FUN_008579b0(&unkAC, 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unk88, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x30)
    {
        NiPoint3 pos4 = reinterpret_cast<::NiAVObject *>((GetNode3D()))->FUN_0043c490();
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&pos4, 12);
        Quat16 rot;
        reinterpret_cast<::FUN_0056d230_Class *>((GetNode3D()))->FUN_0056d230((::FUN_00a6df40_Obj *)(::Quat16 *)(&rot));
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveGame*)g_TESSaveLoadGame)))->FUN_008579b0(&rot, 16);
        float smooth5 = 0.0f;
        if (pathing)
            smooth5 = reinterpret_cast<::PathingRequest *>((((PathReq*)pathing)))->GetSmoothingRandomness();
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&smooth5, 4);
    }
    unsigned int formIDA = 0;
    if (pForm)
        formIDA = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pForm))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&formIDA), 4);
    unsigned short count = 0;
    unsigned short* aPCount = ((unsigned short *)(reinterpret_cast<::SaveLoadGameView *>((((SaveGame*)g_TESSaveLoadGame)))->pBufferCursor));
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&count, 2);
    AreaBoltNode* node7 = m_pListNode;
    while (node7)
    {
        unsigned int boltID = 0;
        if ((const char*)node7->name)
        {
            Form* f5 = ((::Form *)(::FUN_0056f930((::NiAVObject *)(const char *)(node7->name))));
            if (f5)
                boltID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((f5))->FUN_0084e3a0()));
        }
        reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&boltID), 4);
        count++;
        node7 = node7->next;
    }
    *aPCount = count;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x71)
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unkD4, 4);
}

struct HUDNode;

struct HUDParent
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void InsertChild(HUDNode* apChild);
};

struct HUDNode
{
};

template <class T> struct HUDPointer
{
    T* m_pObject;

    ~HUDPointer();
    HUDPointer& operator=(T* apObject);
    operator T*() const;
};

struct HUDSoundHandle
{
    unsigned int uiID;
    unsigned int uiState;
    unsigned int uiFlags;

    ~HUDSoundHandle();
};

struct HUDEntry
{
    HUDPointer<HUDNode> m_pController;
    HUDPointer<HUDNode> m_pRootNode;
    int unk08;
    int unk0C;
    int unk10;
    HUDPointer<HUDNode> sp14;
    HUDPointer<HUDNode> sp18;
    HUDEntry* pNext;

    ~HUDEntry();
};

void __cdecl FUN_0080fc90(float afValue);

struct HUDSetting
{
};

struct HUDMagicTarget
{
    virtual void v00();
};

struct HUDPlayerBase
{
    virtual void v00();
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
};

struct HUDPlayer : HUDPlayerBase, HUDMagicTarget
{
};

struct HUDBaseA
{
    virtual ~HUDBaseA();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
};

struct HUDBaseB
{
    virtual void v00();
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
};

struct HUDBase : HUDBaseA, HUDBaseB
{
    ~HUDBase();
};

struct FUN_00811e10;

struct HUDList
{
};

struct HUDProcessLists
{
};


struct FUN_00811e10 : HUDBase
{
    HUDPointer<HUDNode> spA8;
    int unkAC;
    HUDEntry* pEntries;
    HUDPointer<HUDNode> spB4;
    HUDPointer<HUDNode> spB8;
    HUDPointer<HUDNode> spBC;
    HUDPointer<HUDNode> spC0;
    int unkC4;
    HUDSoundHandle kSound;

    virtual ~FUN_00811e10();
};
// Calls FUN_00811e10, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00811950
void* FUN_00811950_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00811e10 *>(this)->FUN_00811e10::~FUN_00811e10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00811e10
FUN_00811e10::~FUN_00811e10()
{
    if (((::HUDMagicTarget *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)) != (*reinterpret_cast<::HUDPlayer * *>(&::_g_thePlayer)))
        FUN_0080fc90(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::HUDSetting *>(&::originalRuntimeFloatSetting1188)))))));

    HUDList* pList = ((::HUDList *)(reinterpret_cast<::FUN_004610f0_Class *>(&((*reinterpret_cast<::HUDProcessLists *>(&::g_011e0e80))))->GetOffset70Ptr()));
    if (pList)
        reinterpret_cast<::ItemChangeListNode *>((pList))->FUN_00905330((::InventoryStackRecord *const &)((const ::FUN_00811e10 *const &)(this)));

    ::FUN_00bc1470((::Fn1470Owner *)(::HUDNode *)(spB4), (::Fn1470Result *)(::HUDNode *)(spA8));
    spA8 = 0;
    if (spB4)
    {
        HUDParent* pParent = ((::HUDParent *)(reinterpret_cast<::FUN_009611e0_shell *>((((HUDNode*)spB4)))->FUN_009611e0()));
        if (pParent)
            pParent->InsertChild(spB4);
    }
    spC0 = 0;
    spB4 = 0;
    spB8 = 0;
    spBC = 0;

    while (pEntries)
    {
        HUDEntry* pNext = pEntries->pNext;
        ::FUN_00bc1470((::Fn1470Owner *)(::HUDNode *)(pEntries->m_pRootNode), (::Fn1470Result *)(::HUDNode *)(pEntries->m_pController));
        pEntries->m_pController = 0;
        if (pEntries->m_pRootNode)
        {
            HUDParent* pEntryParent = ((::HUDParent *)(reinterpret_cast<::FUN_009611e0_shell *>((((HUDNode*)pEntries->m_pRootNode)))->FUN_009611e0()));
            if (pEntryParent)
                pEntryParent->InsertChild(pEntries->m_pRootNode);
        }
        pEntries->m_pRootNode = 0;
        pEntries->sp14 = 0;
        pEntries->sp18 = 0;
        delete pEntries;
        pEntries = pNext;
    }

    if (reinterpret_cast<::SoundPlaybackHandle *>(&(kSound))->IsValid())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(kSound))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&(kSound))->Release();
    }
}

struct BoltPoint
{
    float x, y, z;
};
struct BoltMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    BoltMatrix();
};
struct BoltColor
{
    float r, g, b, a;
    BoltColor(float, float, float, float);
};
void* FUN_00aa13e0(unsigned int);
void FUN_00aa13f0(void*);
struct BoltProperty
{
    int unk00, unk04, unk08, unk0c;
    BoltProperty();
};
struct BoltNode
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
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    BoltNode(int);
};
struct BoltFx
{
    void SetArg(BoltColor);
    void SetData(BoltColor);
};
struct BoltNodePtr
{
    BoltNode* ptr;
    void FUN_0066b0d0(BoltNode*);
};
struct BoltFxPtr
{
    BoltFx* ptr;
    void FUN_0066b0d0(BoltFx*);
};
struct BoltSetting
{
};
struct Bolt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const BoltPoint& Position();
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
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    BoltFxPtr effect;
    int unkac, unkb0;
    BoltNodePtr emitter;
    int unkb8, unkbc;
    BoltNodePtr root;
    void InitEffect();
};
struct AimPoint3
{
    float x;
    float y;
    float z;

    AimPoint3();
    AimPoint3 operator-(const AimPoint3& arOther) const;
};

struct AimMatrix3
{
    float m[9];

    AimMatrix3();
};

struct AimUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    int unk08;

    AimUpdateData(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};

struct AimNode
{
};

struct AimNodePtr
{
    AimNode* pObject;

    operator AimNode*() const;
};

struct AimSource
{
};

struct AimTarget
{
};

struct AimMagicTarget
{
    int unk00;
};

struct AimRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual bool IsActor();
};

struct AimActor : AimRef
{
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
};

struct AimSecondBase
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual AimSource* GetSource();
};

struct AimFullActor : AimActor, AimSecondBase
{
};

struct AimPlayer : AimFullActor
{
};

struct AimOwner
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual AimRef* GetRef();
};



struct AimProjectile
{
    int unk000;
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
    AimNodePtr m_pController;

    bool UpdateProjectileAimNode();
};

// Aligns the projectile's aim node to the source or target position and rotation, updates it, and returns false when a source, target and node exist.
// @fnv 0x00812890
bool AimProjectile::UpdateProjectileAimNode()
{
    AimOwner* pOwnerB = ((::AimOwner *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster));
    AimRef* pRef4 = pOwnerB ? pOwnerB->GetRef() : 0;
    AimFullActor* pActor2 = (pRef4 && pRef4->IsActor()) ? (AimFullActor*)pRef4 : 0;
    AimSource* pSource = pActor2 ? pActor2->GetSource() : 0;
    AimTarget* aPTarget = ((::AimTarget *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));

    if (pSource && aPTarget && (AimNode*)m_pController)
    {
        if (::GetField90Float((char *)this) < 0.5 && pActor2 == (*reinterpret_cast<::AimPlayer * *>(&::_g_thePlayer)) && !reinterpret_cast<::FUN_004eaf60_shell *>(((*reinterpret_cast<::AimPlayer * *>(&::_g_thePlayer))))->FUN_004eaf60())
        {
            AimPoint3 kPos = *((::AimPoint3 *)(::FUN_0045bb80((intptr_t)(pSource))));
            reinterpret_cast<::FUN_00440460_S *>((((AimNode*)m_pController)))->FUN_00440460((const ::V3 *)&(kPos));
        }
        if (::GetField90Float((char *)this) > ::_DAT_01012060)
        {
            AimPoint3 kNodePosB = *((::AimPoint3 *)(::FUN_0045bb80((intptr_t)(((AimNode*)m_pController)))));
            AimPoint3 kTargetPos3;
            reinterpret_cast<::VectorSourceB00 *>((aPTarget))->FUN_00812b00((void *)&(kTargetPos3));
            AimPoint3 kKDir = kTargetPos3 - kNodePosB;
            AimMatrix3 kRotate_2;
            float fZ8 = kKDir.z;
            kKDir.z = 0.0f;
            float aFLength = reinterpret_cast<::NiPoint3 *>(&(kKDir))->ComputeMagnitude();
            reinterpret_cast<::ThreeByThreeMatrix *>(&(kRotate_2))->FUN_00a59780(::FUN_004b5550(kKDir.x, kKDir.y), 0.0f, -::FUN_004b5550(fZ8, aFLength));
            reinterpret_cast<::FUN_0043fa80_s *>((((AimNode*)m_pController)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(kRotate_2));
        }
        AimUpdateData kDataX(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((AimNode*)m_pController)))->FUN_00a59c60((std::intptr_t)&(kDataX));
        return false;
    }
    return true;
}

struct Helper009f8770
{
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int*, int);
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
class NiQuaternion
{
  public:
    static const Quat16 IDENTITY;
};
class PlayerCharacter : public SaveBaseObj
{
  public:
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual NiPoint3* GetPosition();
};
struct LoadObject : ThisObj
{
    void LoadObjectData(int, int);
};
// @fnv 0x00814870
void LoadObject::LoadObjectData(int arg1, int arg2)
{
    v71();
    reinterpret_cast<::FUN_0081e980_shell *>(this)->FUN_0081e980(arg1, arg2);
    reinterpret_cast<FUN_008579e0_shell*>(g_TESSaveLoadGame)->FUN_008579e0(&unkAC, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<Helper009f8770*>(this)))->FUN_00484d00(&unk88, 4);
    FUN_00814aa0* formID = new FUN_00814aa0;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x30)
    {
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<Helper009f8770*>(this)))->FUN_00484d00(&formID->m0, 12);
        reinterpret_cast<FUN_008579e0_shell*>(g_TESSaveLoadGame)->FUN_008579e0(&formID->m1, 16);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<Helper009f8770*>(this)))->FUN_00484d00(reinterpret_cast<Quat16*>(&formID->m1) + 1, 4);
    }
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() < 0x30)
    {
        reinterpret_cast<NiPoint3&>(formID->m0) = *::_g_thePlayer->GetPosition();
        reinterpret_cast<Quat16&>(formID->m1) = NiQuaternion::IDENTITY;
    }
    unsigned int count;
    reinterpret_cast<FUN_00484d40_Host*>(this)->FUN_00484d40(&count, 4);
    pForm = reinterpret_cast<Form*>(count);
    unsigned short state;
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<Helper009f8770*>(this)))->FUN_00484d00(&state, 2);
    if (state)
    {
        formID->f20 = reinterpret_cast<intptr_t>(new unsigned int[state + 1]);
        *reinterpret_cast<unsigned int*>(formID->f20) = state;
        reinterpret_cast<FUN_00484d40_Host*>(this)->FUN_00484d40(reinterpret_cast<unsigned int*>(formID->f20) + 1,
                                                                 state * 4);
    }
    m_pListNode = reinterpret_cast<AreaBoltNode*>(formID);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x71)
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((reinterpret_cast<Helper009f8770*>(this)))->FUN_00484d00(&unkD4, 4);
}

class TESForm
{
  public:
    virtual void v00();
};
#include "fnv/native_fixed_string.h"
struct SceneNode
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual SceneNode* FindNode(const NiFixedString& name);
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual SceneNode* GetNode3D();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual const NiPoint3& GetPosition();
};
struct NodePointer
{
    SceneNode* value;
    operator SceneNode*() const;
    NodePointer& operator=(SceneNode*);
};
struct AudioPlaybackHandle
{
    unsigned int soundID;
    unsigned int state;
    unsigned int flags;
    ~AudioPlaybackHandle();
    AudioPlaybackHandle& operator=(const AudioPlaybackHandle&);
};
struct SoundForm
{
};
struct ProjectileEffect
{
};
struct ProjectileCell
{
};
struct AudioManager
{
    AudioPlaybackHandle FUN_00ad73b0(unsigned int id, unsigned int flags);
};
class MagicProjectile : public TESObjectREFR
{
  public:
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    NodePointer nodeB4;
    int unkB8;
    NodePointer spineNode;
    NodePointer soundNode;
    TESObjectREFR* sourceReference;
    AudioPlaybackHandle sound;
    ProjectileEffect* FUN_004fd400();
    void InitializeProjectile(int arg1, int arg2);
public:
    void FUN_0081e730();
};
// @fnv 0x00814ad0
void MagicProjectile::InitializeProjectile(int arg1, int arg2)
{
    reinterpret_cast<::fnv_0081ea40::MagicProjectile *>(this)->ResolveMagicReferences(arg1, arg2);
    uintptr_t referenceID = reinterpret_cast<uintptr_t>(sourceReference);
    if (referenceID)
    {
        sourceReference = dynamic_cast<TESObjectREFR*>(FUN_004839c0(referenceID));
        if (sourceReference)
        {
            SceneNode* node = sourceReference->GetNode3D();
            if (node)
            {
                spineNode = node->FindNode(NiFixedString("Bip01 Spine2"));
            }
        }
    }
    reinterpret_cast<::Bolt *>(this)->InitEffect();
    reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((std::intptr_t)(nodeB4.value));
    reinterpret_cast<::CellView *>((((::ProjectileCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(::TESObjectREFR *)(this), false);
    if (((::SoundForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(FUN_004fd400())))))
    {
        unsigned int soundID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SoundForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(FUN_004fd400()))))))->FUN_0084e3a0()));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->Release();
        if (GetNode3D())
        {
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::AudioPlaybackHandle &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::AudioPlaybackHandle &)(((::AudioManager *)(::FUN_00453a70()))->FUN_00ad73b0(soundID, 0x102))));
            NiPoint3 position = GetPosition();
            reinterpret_cast<::FUN_00ad8b60_h *>(&(sound))->FUN_00ad8b60(position.x, position.y, position.z);
            reinterpret_cast<::FUN_00ad8f20_shell *>(&(sound))->FUN_00ad8f20((::NiAVObject *)(::SceneNode *)(soundNode));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(true);
        }
    }
}

struct Vec3
{
    float x, y, z;
    float FUN_00457990();
public:
    Vec3();
};
// Calls _ref_006815c0 on m0 and m1 and sets f20 to 0.
// @fnv 0x00814aa0
FUN_00814aa0::FUN_00814aa0()
{
    f20 = 0;
}

struct OutHandle
{
    int value;
    OutHandle(const OutHandle&);
    int FUN_004a3a20();
};

struct GameObject
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void slot4();

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void slot8();

    virtual void slot9();

    virtual void slot10();

    virtual GameObject* child();

    virtual void slot12();

    virtual void slot13();

    virtual void slot14();

    virtual void slot15();

    virtual void slot16();

    virtual void slot17();

    virtual void slot18();

    virtual void slot19();

    virtual void slot20();

    virtual void slot21();

    virtual void slot22();

    virtual void slot23();

    virtual void slot24();

    virtual void slot25();

    virtual void slot26();

    virtual void slot27();

    virtual void slot28();

    virtual void slot29();

    virtual void slot30();

    virtual void slot31();

    virtual void slot32();

    virtual void slot33();

    virtual void slot34();

    virtual void slot35();

    virtual void slot36();

    virtual void slot37();

    virtual void slot38();

    virtual void slot39();

    virtual void slot40();

    virtual void slot41();

    virtual void slot42();

    virtual void slot43();

    virtual void slot44();

    virtual void slot45();

    virtual void slot46();

    virtual void slot47();

    virtual void slot48();

    virtual void slot49();

    virtual void slot50();

    virtual void slot51();

    virtual void slot52();

    virtual void slot53();

    virtual void slot54();

    virtual void slot55();

    virtual void slot56();

    virtual void slot57();

    virtual void slot58();

    virtual void slot59();

    virtual void slot60();

    virtual void slot61();

    virtual void slot62();

    virtual void slot63();

    virtual bool isSpecial();

    virtual void slot65();

    virtual void slot66();

    virtual void slot67();

    virtual void slot68();

    virtual void slot69();

    virtual void slot70();

    virtual void slot71();

    virtual void slot72();

    virtual void slot73();

    virtual void slot74();

    virtual void slot75();

    virtual void slot76();

    virtual void slot77();

    virtual void slot78();

    virtual void slot79();

    virtual void slot80();

    virtual void slot81();

    virtual void slot82();

    virtual void slot83();

    virtual void slot84();

    virtual void slot85();

    virtual void slot86();

    virtual void slot87();

    virtual void slot88();

    virtual void slot89();

    virtual void slot90();

    virtual void slot91();

    virtual void slot92();

    virtual void slot93();

    virtual void slot94();

    virtual void slot95();

    virtual void slot96();

    virtual void slot97();

    virtual void slot98();

    virtual void slot99();

    virtual void slot100();

    virtual void slot101();

    virtual void slot102();

    virtual void slot103();

    virtual void slot104();

    virtual void slot105();

    virtual void slot106();

    virtual void slot107();

    virtual void slot108();

    virtual void slot109();

    virtual void slot110();

    virtual void slot111();

    virtual void slot112();

    virtual void slot113();

    virtual void slot114();

    virtual void slot115();

    virtual intptr_t formID();

    virtual void slot117();

    virtual void slot118();

    virtual void slot119();

    virtual void slot120();

    virtual void slot121();

    virtual void slot122();

    virtual void slot123();

    virtual void slot124();

    virtual Vec3* position();

    virtual void slot126();

    virtual void slot127();

    virtual void slot128();

    virtual void slot129();

    virtual void slot130();

    virtual void slot131();

    virtual void slot132();

    virtual void slot133();

    virtual void slot134();

    virtual void slot135();

    virtual void slot136();

    virtual void slot137();

    virtual void slot138();

    virtual void slot139();

    virtual void slot140();

    virtual void slot141();

    virtual void slot142();

    virtual void slot143();

    virtual void slot144();

    virtual void slot145();

    virtual void slot146();

    virtual void slot147();

    virtual void slot148();

    virtual void slot149();

    virtual void slot150();

    virtual void slot151();

    virtual void slot152();

    virtual void slot153();

    virtual void slot154();

    virtual void slot155();

    virtual void slot156();

    virtual void slot157();

    virtual void slot158();

    virtual void slot159();

    virtual void slot160();

    virtual void slot161();

    virtual void slot162();

    virtual void slot163();

    virtual void slot164();

    virtual void slot165();

    virtual void slot166();

    virtual void slot167();

    virtual void slot168();

    virtual void slot169();

    virtual void slot170();

    virtual void slot171();

    virtual void slot172();

    virtual void slot173();

    virtual void slot174();

    virtual void slot175();

    virtual void slot176();

    virtual void slot177();

    virtual void slot178();

    virtual void slot179();

    virtual void slot180();

    virtual void slot181();

    virtual void slot182();

    virtual void slot183();

    virtual void slot184();

    virtual void slot185();

    virtual void slot186();

    virtual void slot187();

    virtual void slot188();

    virtual void slot189();

    virtual void slot190();

    virtual void slot191();

    virtual void slot192();

    virtual void slot193();

    virtual void visitReference(GameObject*, int);

    OutHandle FUN_00931ed0();

    OutHandle FUN_0043b4f0();


    int FUN_004a3a20();

    float FUN_00457990();




    void FUN_004f0160(void*);



};

class NiFixedString;
class NiTexture;
struct Holder
{
public:
    bool FUN_00a5bc40(const ::NiFixedString &, ::NiTexture *);
};
struct Vector
{
    float x, y, z, w;
};
struct Emitter
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    Vector* positions;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    float elapsed;
    int batch;
    int current;
    int emitted;
    int total;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    int count;
    unsigned int unk12c;
    float range;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    int stride;
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
    unsigned char active, state, flags, centered;
    void FUN_00bc2360();
};
// Creates root and emitter nodes at Position(), sets up an emitter property, applies a rotation matrix, and configures the spawned effect from settings.
// @fnv 0x00812220
void Bolt::InitEffect()
{
    root.FUN_0066b0d0(new BoltNode(0));
    reinterpret_cast<::FUN_004f00e0_shell *>((((::BoltNode *)(::FUN_00559450((int *)&(root))))))->FUN_004f00e0((void *)&(Position()));
    emitter.FUN_0066b0d0(new BoltNode(0));
    reinterpret_cast<::FUN_00440460_S *>((((::BoltNode *)(::FUN_00559450((int *)&(emitter))))))->FUN_00440460((const ::V3 *)&(Position()));
    BoltProperty* property = ((::BoltProperty *)(reinterpret_cast<::NiAVObject *>((((::BoltNode *)(::FUN_00559450((int *)&(emitter))))))->GetExtraData((*(const ::NiFixedString *)(((const char *)&(::FUN_00448a80())))))));
    if (!property)
    {
        property = new BoltProperty;
        reinterpret_cast<::Holder *>((((::BoltNode *)(::FUN_00559450((int *)&(emitter))))))->FUN_00a5bc40((*(const ::NiFixedString *)(((const char *)&(::FUN_00448a80())))), (::NiTexture *)(property));
    }
    reinterpret_cast<::BSXFlags_shell *>((property))->FUN_00519230(true, true);
    effect.FUN_0066b0d0(0);
    BoltPoint rotation = (*(const ::BoltPoint *)(reinterpret_cast<::TESRecipe *>(this)->GetData()));
    BoltMatrix matrix2;
    reinterpret_cast<::FUN_00a59660_cls *>(&(matrix2))->FUN_00a59660(rotation.z, rotation.x, rotation.y);
    reinterpret_cast<::FUN_0043fa80_s *>((((::BoltNode *)(::FUN_00559450((int *)&(emitter))))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(matrix2));
    effect.FUN_0066b0d0(((::BoltFx *)(::FUN_00bc18d0((::Obj_bc18d0 *)(::BoltNode *)(((::BoltNode *)(::FUN_00559450((int *)&(emitter)))))))));
    if (((::BoltFx *)(::FUN_00559450((int *)&(effect)))))
    {
        reinterpret_cast<::FUN_00803a70_shell *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->FUN_00803a70(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d186c)))))));
        reinterpret_cast<::FUN_00821620_Class *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->FUN_00821620(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1190)))))));
        reinterpret_cast<::FUN_00507780 *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->SetBoltsRadiusStrength(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1191)))))));
        reinterpret_cast<::FUN_005f9b10_class *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->SetBoltSmallWidth(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1192)))))));
        reinterpret_cast<::FUN_00803a90_shell *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->SetBoltGrowWidth(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d1b2c)))))));
        ((::BoltFx *)(::FUN_00559450((int *)&(effect))))->SetArg(
            BoltColor(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d1be0)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d1908)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d18f0)))))), 1.0f));
        ((::BoltFx *)(::FUN_00559450((int *)&(effect))))->SetData(
            BoltColor(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d1c4c)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1194)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d1cdc)))))), 1.0f));
        reinterpret_cast<::FUN_00803b30_shell *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->FUN_00803b30(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1195)))))));
        reinterpret_cast<::FUN_008126e0_shell *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->SetWhich(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d1800)))))));
        reinterpret_cast<::FUN_005077a0_Class *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->FUN_005077a0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1196)))))));
        reinterpret_cast<::FUN_00803b50_shell *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->FUN_00803b50(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::BoltSetting *>(&::g_011d17c4)))))));
        reinterpret_cast<::FUN_00803a50_shell *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->FUN_00803a50(true);
        reinterpret_cast<::Emitter *>((((::BoltFx *)(::FUN_00559450((int *)&(effect))))))->FUN_00bc2360();
    }
}

struct Pending
{


    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;

    float value1c;

    struct RefList* refs20;
};

struct RefList
{
    unsigned short count;
    unsigned short reserved;
    int entries[1];
};

struct LocalStore
{

    void* value;



};

struct Control
{

    void FUN_0070c440(LocalStore*);

};

struct Matrix
{

    float a, b, c, d, e, f, g, h, i;


};

struct Clock
{
};









struct Root : GameObject
{

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

    float f088;

    int unk08c;

    int unk090;

    int unk094;

    int unk098;

    int unk09c;

    int unk0a0;

    int unk0a4;

    Holder m0a8;

    int state0ac;

    Pending* active0b0;

    Holder m0b4;

    int unk0b8;

    Holder m0bc;





    void UpdatePending(int, int);
};

// Applies the pending entry to the active holders, updates the control and rotation, then visits its references and deletes it.
// @fnv 0x00814d40
void Root::UpdatePending(int arg1, int arg2)

{

    reinterpret_cast<::fnv_00932520::FUN_00932520_shell *>(this)->UpdateFlags(arg1, arg2);

    Control* a = ((::Control *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    LocalStore handle;

    if (a)
    {

        int selected;

        if (((::GameObject *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)) && ((::GameObject *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->child())
        {

            GameObject* special = ((::GameObject *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->child();

            GameObject* current = special->isSpecial() ? special : 0;

            if (current)
            {

                selected = ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::OutHandle &)(current->FUN_00931ed0()))->FUN_004a3a20()));
            }
            else
            {

                GameObject* form = ((::GameObject *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(special->formID()))));

                GameObject* item = form ? ((::GameObject *)(::fnv_006fa820::FUN_006fa820((const char *)(form)))) : 0;

                selected = item ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::OutHandle &)(item->FUN_0043b4f0()))->FUN_004a3a20())) : ((int)(::FUN_005dbe10()));
            }
        }
        else
        {

            GameObject* form = ((::GameObject *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(formID()))));

            GameObject* item = form ? ((::GameObject *)(::fnv_006fa820::FUN_006fa820((const char *)(form)))) : 0;

            selected = item ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::OutHandle &)(item->FUN_0043b4f0()))->FUN_004a3a20())) : ((int)(::FUN_005dbe10()));
        }

        a->FUN_0070c440(&handle);

        reinterpret_cast<::FUN_004a39f0_shell *>(&(handle))->FUN_004a39f0(7);

        reinterpret_cast<::FUN_0059ce80_shell *>(&(handle))->FUN_0059ce80(selected);

        reinterpret_cast<::fnv_00810ff0::Ths810 *>((a))->FUN_00810ff0((intptr_t)(handle.value));
    }

    GameObject* candidate = ((::GameObject *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)) ? ((::GameObject *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->child() : 0;

    if (candidate != (*reinterpret_cast<::GameObject * *>(&::_g_thePlayer)))
    {

        FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Clock *>(&::originalRuntimeFloatSetting1188)))))));
    }

    Pending* pending = active0b0;

    if (pending)
    {

        if (((::GameObject *)(::FUN_00559450((int *)&(m0b4)))))
        {

            reinterpret_cast<::FUN_00440460_S *>((((::GameObject *)(::FUN_00559450((int *)&(m0b4))))))->FUN_00440460((const ::V3 *)(pending));

            ((::GameObject *)(::FUN_00559450((int *)&(m0b4))))->FUN_004f0160(&pending->unk0c);

            bool force = state0ac != 0;

            if (((::GameObject *)(::FUN_00559450((int *)&(m0bc)))))
            {

                Vec3 position3d;

                reinterpret_cast<::FUN_00439ef0_class *>((((::GameObject *)(::FUN_0045bb80((intptr_t)(((::GameObject *)(::FUN_00559450((int *)&(m0bc))))))))))->FUN_00439ef0((::NiPoint3 *)(&position3d), *(const ::NiPoint3 *)(pending));

                ::DispatchFloatPair(((::GameObject *)(::FUN_00559450((int *)&(m0a8)))), pending->value1c, reinterpret_cast<::NiPoint3 *>(&(position3d))->ComputeMagnitude(), f088);

                Matrix rot;


                float angle = position3d.z;

                position3d.z = 0.0f;

                float azimuth = reinterpret_cast<::NiPoint3 *>(&(position3d))->ComputeMagnitude();

                reinterpret_cast<::ThreeByThreeMatrix *>(&(rot))->FUN_00a59780(FUN_004b5550(position3d.x, position3d.y), 0.0f, -FUN_004b5550(angle, azimuth));

                reinterpret_cast<::FUN_0043fa80_s *>((((::GameObject *)(::FUN_00559450((int *)&(m0b4))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rot)));
            }
            else
            {

                Vec3 position3d = *this->position();

                float direction = reinterpret_cast<::NiPoint3 *>((void *)&(const ::Vec3 &)(([&] { ::Vec3 difference; reinterpret_cast<::FUN_00439ef0_class *>((pending))->FUN_00439ef0((::NiPoint3 *)&difference, *(const ::NiPoint3 *)((::NiPoint3 *)(::Vec3 *)(&position3d))); return difference; }())))->ComputeMagnitude();

                ::DispatchFloatPair(((::GameObject *)(::FUN_00559450((int *)&(m0a8)))), pending->value1c, direction, f088);

                if (::FUN_00ee8990() || state0ac == 2)
                {

                    reinterpret_cast<::FUN_008133d0_shell *>(this)->FUN_008133d0(2);

                    LocalStore handle;

                    ((::Control *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&handle);

                    reinterpret_cast<::FUN_00810f90_shell *>(&(handle))->SetFlag4000(1);

                    reinterpret_cast<::fnv_00810ff0::Ths810 *>((((::Control *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00810ff0((intptr_t)(handle.value));
                }
            }
        }

        active0b0 = 0;

        if (pending->refs20)
        {

            unsigned short count = pending->refs20->count;

            for (unsigned int i = 0; i < count; ++i)
            {

                GameObject* ref;
                {
                    int id = pending->refs20->entries[i];
                    ref = ((::GameObject *)(::MagicTarget::GetMagicTargetByID(id)));
                }

                if (ref)
                    visitReference(ref, 0);
            }
        }

        delete pending;
    }
}

struct AEPoint3
{
    float x, y, z;
      // operator-
    float FUN_00457990() const;                           // Length
};

struct AEPointResult
{
    float a, b, c;
    const AEPoint3& FUN_004b4500();
};

class AENode
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual AENode* FindNode(const NiFixedString& kName);

      // world translate
    AEPointResult FUN_00461130(const AEPoint3& kPoint, int iIndex);
};

struct AENodePtr
{
    AENode* m_pObject;
    AENodePtr& FUN_0066b0d0(AENode* pkNode);  // operator=
};

class AEController
{
  public:
};

struct AEControllerPtr
{
    AEController* m_pObject;
      // operator T*
};

class AERefr
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();  // +0x100
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual AENode* GetNode3D();  // +0x1d0
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const AEPoint3& GetPosition();  // +0x1f4
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();  // +0x310
};

class AEActor : public AERefr
{
  public:
};

class AEPlayer : public AEActor
{
  public:
};


struct AEFlags
{
};

struct AEHandle
{
    void* m_pIntegerData;
};

class AEProcess
{
  public:
    char pad000[0x410];
    AEFlags m_kFlags;
    void FUN_0070c440(AEHandle* pkOut);
};

struct AEArea
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int GetValue();  // +0x14
};

struct AESound
{
};

class AEEffect
{
  public:
    char pad00[0x18];
    AEArea m_kArea;
};

struct AEEffectItem
{
};

struct AESetting
{
};

extern const AEPoint3 DAT_011a9478;

class AEExplosion
{
  public:
};

class AEIdle
{
  public:
};

class BSSoundHandleEx
{
  public:
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~BSSoundHandleEx();
};

struct BSAudio
{
  public:
    BSSoundHandleEx FUN_00ad73b0(unsigned int auiFormId, unsigned int uiFlags);
};

class AEProjectile : public AERefr
{
  public:
    char pad004[0x84];
    float m_f88;
    char pad08c[0x1c];
    AEControllerPtr m_spController;  // +0xa8
    char pad0ac[0x10];
    AENodePtr m_spSpine;  // +0xbc
    int unk0c0;
    AERefr* m_pkSource;  // +0xc4
    char pad0c8[0xc];
    float m_fd4;

      // GetParentCell
    AEEffect* FUN_004fd400();

    void Impact(AEPoint3 kPos, int iIndex, AERefr* pkTarget, bool bSilent);
};

// Handles projectile impact at kPos: updates source/target, controller distance, spawns explosion and area-effect idle, and plays impact sound unless silent.
// @fnv 0x008133f0
void AEProjectile::Impact(AEPoint3 kPos, int iIndex, AERefr* pkTarget, bool bSilent)
{
    AEActor* pkHitActor = (pkTarget && pkTarget->IsActor()) ? (AEActor*)pkTarget : 0;
    if (pkHitActor && reinterpret_cast<::FUN_008ace90_shell *>((pkHitActor))->FUN_008ace90())
        return;

    m_fd4 = reinterpret_cast<::FUN_00812870_t *>(this)->GetUnka4();
    if (((::AEProcess *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
    {
        if (((int)(reinterpret_cast<::bhkCharacterListener *>(&(((::AEProcess *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->m_kFlags))->FUN_00621270(0x8000))))
            v196();
        AEHandle kHandle;
        ((::AEProcess *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&kHandle);
        reinterpret_cast<::FUN_00810f90_shell *>(&(kHandle))->SetFlag4000(true);
        reinterpret_cast<::fnv_00810ff0::Ths810 *>((((::AEProcess *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00810ff0((intptr_t)(kHandle.m_pIntegerData));
    }
    reinterpret_cast<::FUN_008133d0_shell *>(this)->FUN_008133d0(1);

    AENode* pkNode = GetNode3D();
    if (pkNode)
        reinterpret_cast<::ImpactOwner *>(this)->FUN_0081f000((*(float *)&(const ::AEPoint3 &)(kPos)), (*(float *)&(const ::AEPoint3 &)(pkNode->FUN_00461130(DAT_011a9478, iIndex).FUN_004b4500())), {}, {}, {}, {}, {});

    if (pkTarget)
    {
        if (pkTarget != (*reinterpret_cast<::AEPlayer * *>(&::_g_thePlayer)) || reinterpret_cast<::FUN_004eaf60_shell *>(((*reinterpret_cast<::AEPlayer * *>(&::_g_thePlayer))))->FUN_004eaf60())
        {
            m_pkSource = pkTarget;
            AENode* pkTargetNode = m_pkSource->GetNode3D();
            if (pkTargetNode)
                m_spSpine.FUN_0066b0d0(pkTargetNode->FindNode(NiFixedString("Bip01 Spine2")));
        }
    }

    {
        AEPoint3 kWorldPos = (*(const ::AEPoint3 *)&(reinterpret_cast<::NiAVObject *>((GetNode3D()))->FUN_0043c490()));
        float fDist = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::AEPoint3 &)(([&] { ::AEPoint3 difference; reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kWorldPos))->FUN_00439ef0((::NiPoint3 *)&difference, *(const ::NiPoint3 *)((::NiPoint3 *)&(kPos))); return difference; }())))->ComputeMagnitude();
        ::DispatchFloatPair(((::AEController *)(::FUN_00559450((int *)&(m_spController)))), 0.01f, fDist, m_f88);
    }

    if (!bSilent)
        reinterpret_cast<::P142Caster *>(reinterpret_cast<::MagicProjectileFields *>(this)->caster)->ApplySpellEffects((::P142Spell *)(reinterpret_cast<::MagicProjectileFields *>(this)->spell), (std::intptr_t)(((void *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))), (*(const ::NiPoint3 *)&(const ::AEPoint3 &)(GetPosition())), (::P142Ref *)(this), (::P142Ref *)(pkTarget), 0, 1.0f, 1.0f);

    m_pkSource = 0;
    if (FUN_004fd400()->m_kArea.GetValue())
    {
        float fScale = reinterpret_cast<::FUN_00404420_shell *>((((::AEEffectItem *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()))))->FUN_00404420() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AESetting *>(&::originalRuntimeFloatSetting1137))))));
        if (fScale > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AESetting *>(&::originalRuntimeFloatSetting1138)))))))
            fScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AESetting *>(&::originalRuntimeFloatSetting1138))))));
        else if (fScale < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AESetting *>(&::originalRuntimeFloatSetting1139)))))))
            fScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AESetting *>(&::originalRuntimeFloatSetting1139))))));
        int iAreaType = FUN_004fd400()->m_kArea.GetValue();
        AEPoint3 akStart = GetNode3D() ? (*(::AEPointResult *)(::FUN_006a9540((char *)(GetNode3D())))).FUN_004b4500() : DAT_011a9478;
        AEIdle* pkAreaIdle = ((::AEIdle *)(::FUN_006890b0((::World *)(void *)(((void *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))), 5.0f, iAreaType, (*(::Vec3 *)&(const ::AEPoint3 &)(akStart)), (*(::Vec3 *)&(const ::AEPoint3 &)(kPos)), 1.0f, 7, 0)));
        reinterpret_cast<::FUN_00689920_shell *>((pkAreaIdle))->FUN_00689920("SpecialIdle_AreaEffect");
    }

    if (((::AESound *)(reinterpret_cast<::FUN_008ce390_shell *>((FUN_004fd400()))->FUN_008ce390())) && !bSilent)
    {
        unsigned int auiFormId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::AESound *)(reinterpret_cast<::FUN_008ce390_shell *>((FUN_004fd400()))->FUN_008ce390()))))->FUN_0084e3a0()));
        BSSoundHandleEx kSound = ::FUN_00453a70()->FUN_00ad73b0(auiFormId, 0x102);
        AEPoint3 kSoundLoc = GetPosition();
        reinterpret_cast<::FUN_00ad8b60_h *>(&(kSound))->FUN_00ad8b60(kSoundLoc.x, kSoundLoc.y, kSoundLoc.z);
        reinterpret_cast<::FUN_00ad8830_shell *>(&(kSound))->FUN_00ad8830(false);
    }
}

struct F139Node;
struct F139Ref;
struct F139Owner
{
    virtual void v0();
    virtual F139Ref* v1();
};
struct F139Node
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual F139Node* find(const NiFixedString&);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void attach(F139Node*, bool);
};
struct F139Ref
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual F139Node* node();
};
struct F139Vec
{
    float x, y, z;
};
struct F139Cell
{
};
struct F139Result
{
};
struct F139Color
{
    float r, g, b, a;
    F139Color(float, float, float, float);
};
struct F139Fx
{
    void SetArg(F139Color);
    void SetData(F139Color);
};
struct F139Setting
{
};
struct F139Ptr
{
    void* p;
    void FUN_0066b0d0(void*);
};
struct F139Entry
{
    F139Ptr fx, node;
    F139Vec pos;
    F139Ptr source, target;
    F139Entry* next;
    F139Entry();
};
struct F139NewNode : F139Node
{
    char data[0xa8];
    F139NewNode(int);
};
struct F139Arg
{
};
struct F139This
{
    char pad[0xb0];
    F139Entry* entries;
    char pad2[0x10];
    F139Ref* ref;
    void AttachEffectToSpine(F139Owner*, F139Arg*);
};
// @fnv 0x008139f0
void F139This::AttachEffectToSpine(F139Owner* owner, F139Arg* arg)
{
    if (arg && (((::F139Ref *)(reinterpret_cast<::FUN_0084e3a0_Class *>((arg))->FUN_0084e3a0())) != ((::F139Ref *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150())) || ref == owner->v1()))
        return;
    F139NewNode* s = new F139NewNode(0);
    F139Node* a = ((::F139Node *)(reinterpret_cast<::TESObjectCELL *>((((::F139Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->GetDynamicNode()));
    a->attach(s, true);
    F139Fx* h = ((::F139Fx *)(::FUN_00bc18d0((::Obj_bc18d0 *)(s))));
    if (h)
    {
        reinterpret_cast<::FUN_00803a70_shell *>((h))->FUN_00803a70(*((int *)&(::FUN_0043d4d0((int *)(((F139Setting*)&(*reinterpret_cast<char *>(&::g_011d1a48))))))));
        reinterpret_cast<::FUN_00821620_Class *>((h))->FUN_00821620(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting1197))))))));
        reinterpret_cast<::FUN_00507780 *>((h))->SetBoltsRadiusStrength(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting1198))))))));
        reinterpret_cast<::FUN_005f9b10_class *>((h))->SetBoltSmallWidth(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1192))))))));
        reinterpret_cast<::FUN_00803a90_shell *>((h))->SetBoltGrowWidth(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::g_011d1b2c))))))));
        h->SetArg(F139Color(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::g_011d1be0))))))),
                            *((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::g_011d1908))))))),
                            *((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::g_011d18f0))))))), 1.0f));
        h->SetData(F139Color(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::g_011d1c4c))))))),
                             *((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::originalRuntimeFloatSetting1194))))))),
                             *((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<::BoltSetting *>(&::g_011d1cdc))))))), 1.0f));
        reinterpret_cast<::FUN_00803b30_shell *>((h))->FUN_00803b30(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting1199))))))));
        reinterpret_cast<::FUN_008126e0_shell *>((h))->SetWhich(*((int *)&(::FUN_0043d4d0((int *)(((F139Setting*)&(*reinterpret_cast<char *>(&::g_011d1b50))))))));
        reinterpret_cast<::FUN_005077a0_Class *>((h))->FUN_005077a0(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting1200))))))));
        reinterpret_cast<::FUN_00803b50_shell *>((h))->FUN_00803b50(*((float *)&(::FUN_00403e20((float *)(((F139Setting*)&(*reinterpret_cast<char *>(&::g_011d1974))))))));
        reinterpret_cast<::FUN_00803a50_shell *>((h))->FUN_00803a50(false);
        reinterpret_cast<::Emitter *>((h))->FUN_00bc2360();
    }
    F139Vec i;
    reinterpret_cast<::VectorSourceB00 *>((((::F139Result *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_00812b00(&i);
    F139Node* p = 0;
    F139Node* f = ref ? ref->node() : 0;
    if (f)
        p = f->find(NiFixedString("Bip01 Spine2"));
    F139Node* eb = 0;
    f = owner->v1()->node();
    if (f)
    {
        eb = f->find(NiFixedString("Bip01 Spine2"));
        if (!eb)
            eb = f;
    }
    else
        return;
    F139Entry* cf = new F139Entry;
    cf->fx.FUN_0066b0d0(h);
    cf->node.FUN_0066b0d0(s);
    cf->source.FUN_0066b0d0(p);
    cf->target.FUN_0066b0d0(eb);
    cf->pos = i;
    cf->next = entries;
    reinterpret_cast<::EffectBase *>(this)->FUN_00812700(0.0f, (::EffectParams *)(cf));
    entries = cf;
}

struct FUN_00812170
{
    virtual ~FUN_00812170();
};
// @fnv 0x00812170
FUN_00812170::~FUN_00812170()
{}

double FUN_00ec9e10(double);
inline float rounded(float value)
{
    float result = (float)ceil(value);
    return result;
}
inline float randomRange(const float& range)
{
    float fraction = (float)(rand() / 32767.0);
    return (float)(range * fraction - range * 0.5);
}
// @fnv 0x00bc2360
void Emitter::FUN_00bc2360()
{
    int available = ((int)(::FUN_00bc0b40()));
    elapsed = 0.0f;
    active = false;
    if (available < count * stride)
    {
        float deficit = (float)(count * stride - available) / stride;
        float removed = rounded(deficit);
        count -= (int)removed;
    }
    batch = stride > 4 ? 4 : stride;
    total = count * stride;
    for (int i = 0; i < count; ++i)
    {
        if (centered)
        {
            positions[i].x = 0.0f;
            positions[i].y = 0.0f;
            positions[i].z = 0.0f;
        }
        else
        {
            positions[i].x = randomRange(range);
            positions[i].y = randomRange(range);
            positions[i].z = randomRange(range);
        }
    }
    current = 0;
    emitted = 0;
}


struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(float, float, float, float);
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
};
extern xFltSetting xg_11d1c28;
extern const float xg_107a8b0;
struct xIntSetting
{
};
struct xPtr
{
    xPtr(int);
    ~xPtr();
    void FUN_0066b0d0(void*);
    void* m_p;
};
int xFUN_0081e440(void*);
struct xNodeA
{
};
struct xPC
{
};
struct xAudio
{
    struct xSound FUN_00ad73b0(void*, unsigned int);
};
struct xRefList
{
    void FUN_005ae3d0(void* const&);
};
struct xDH
{
};
struct xRadius
{
};
struct xSndForm
{
};
struct xEffect
{
};
struct xCtl
{
};
struct xCell
{
};
struct xOwner
{
};
struct xA
{
    virtual void a0();
    virtual void FUN_00484b60(unsigned int);
    int m_iWordAt04, m_8, m_iThirdValue, m_10, m_14;
};
struct xB
{
    virtual void b0();
};
struct xBase : xA, xB
{
    xBase(intptr_t, int, int, int, xP3, xP3);
    ~xBase();
};
struct xActorV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void* FUN_2c();
};

struct xProj : xBase
{
    int m_pad1c[27];
    float m_88;
    int m_pad8c[7];
    xPtr m_a8;
    int m_ac;
    int m_b0;
    xPtr m_b4;
    xPtr m_b8;
    xPtr m_bc;
    xPtr m_c0;
    int m_c4;
    xSound m_c8;
    float m_d4;
    xProj(xActorV* apA, int b, int c, int d, xP3 kP1, xP3 kP2);
};
// @fnv 0x00811980
xProj::xProj(xActorV* apA, int b, int c, int d, xP3 kP1, xP3 kP2)
    : xBase((intptr_t)apA, b, c, d, kP1, kP2), m_a8(0), m_b4(0), m_b8(0), m_bc(0), m_c0(0)
{
    ::FUN_00811e00(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::xIntSetting *>(&::g_011d16ec)))))));
    reinterpret_cast<::FUN_008133d0_shell *>(this)->FUN_008133d0(0);
    m_88 = reinterpret_cast<::PathingRequest *>((((xRadius*)((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))->GetCenterRadius() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1140))))));
    m_b0 = 0;
    m_c4 = 0;
    m_d4 = 0.0f;
    if (apA->FUN_2c() == (*reinterpret_cast<void * *>(&::_g_thePlayer)) && ((::xNodeA *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::xPC * *>(&::_g_thePlayer))))->FUN_00950bb0(true))) &&
        !reinterpret_cast<::FUN_00456630_helper *>((((::xNodeA *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::xPC * *>(&::_g_thePlayer))))->FUN_00950bb0(true)))))->FUN_00456610())
    {
        xP3 POS = *((::xP3 *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
        POS.z = POS.z + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1193))))));
        reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)&(POS));
    }
    xPtr OLD(xFUN_0081e440(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))));
    OLD.FUN_0066b0d0(0);
    reinterpret_cast<::Bolt *>(this)->InitEffect();
    reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((std::intptr_t)(((void *)(::FUN_00559450((int *)&(m_b4))))));
    reinterpret_cast<::fnv_00813f30::Actor80F *>(this)->FUN_00813f30();
    xVec4 V(-xg_107a8b0, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((((::xCtl *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_0080fb00((intptr_t)(&V));
    reinterpret_cast<::CellView *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(void *)(this), false);
    reinterpret_cast<::FUN_008133d0_shell *>(this)->FUN_008133d0(0);
    if (((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))))
    {
        void* NAME = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))))))->FUN_0084e3a0()));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(m_c8))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>(&(m_c8))->Release();
        if (((void *)(::FUN_00559450((int *)&(m_c0)))))
        {
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::xSound &)(m_c8))->operator=((const ::SoundPlaybackHandle &)((const ::xSound &)(((::xAudio *)(::FUN_00453a70()))->FUN_00ad73b0(NAME, 0x102))));
            xP3 POS2 = *((::xP3 *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
            reinterpret_cast<::FUN_00ad8b60_h *>(&(m_c8))->FUN_00ad8b60(POS2.x, POS2.y, POS2.z);
            reinterpret_cast<::FUN_00ad8f20_shell *>(&(m_c8))->FUN_00ad8f20((::NiAVObject *)(void *)(((void *)(::FUN_00559450((int *)&(m_c0))))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(m_c8))->FUN_00ad8830(true);
        }
    }
    reinterpret_cast<::xActor *>(this)->FUN_0081eba0();
    void* SHOOTER = ((::xActorV *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster)) ? ((::xActorV *)(reinterpret_cast<::MagicProjectileFields *>(this)->caster))->FUN_2c() : 0;
    if (SHOOTER != (*reinterpret_cast<void * *>(&::_g_thePlayer)))
        ::FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1188)))))));
    else
    {
        xRefList* LIST = ((::xRefList *)(reinterpret_cast<::FUN_004610f0_Class *>(&((*reinterpret_cast<::xDH *>(&::g_011e0e80))))->GetOffset70Ptr()));
        if (LIST)
            LIST->FUN_005ae3d0(this);
    }
}
#include "generated/data/fallout/magic/magicboltprojectile.inc"
#include "generated/data/fallout/magic/magicboltprojectile_o2_variant_od_oy_noo2_variant.inc"
