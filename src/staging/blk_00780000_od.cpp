
// src/staging/blk_00780000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSSimpleArrayActor.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00438b90_class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004bddd0_shell.h"
#include "fnv/decl/FUN_00572160_shell.h"
#include "fnv/decl/FUN_0078b9b0_shell.h"
#include "fnv/decl/FUN_00821600_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_009a3910_cls.h"
#include "fnv/decl/FUN_009a3c50_cls.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/List7313.h"
#include "fnv/decl/LoadingMenu.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_007928e0__Menu109.h"
#include "fnv/decl/fnv_007945f0__SurgeryCameraMenu.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005cf000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_0078d000.h"
#include "fnv/symbols_00791000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "../../include/layout_support.h"

struct FUN_007832e0_class
{
    void FUN_007832e0(float a, float b);
};

// Stores two floats at offsets 9 and 10 of this object, then calls UpdateCurrentValueTile with 1.
// @fnv 0x007832e0
void FUN_007832e0_class::FUN_007832e0(float afFirst, float afSecond)
{
    ((float*)this)[9] = afFirst;
    ((float*)this)[10] = afSecond;
    reinterpret_cast<::List7313 *>(this)->UpdateCurrentValueTile(1);
}

struct FUN_00788330
{
    void* Alloc(int a);
};

// Allocates a block of a * 20 bytes via operator new and returns the pointer.
// @fnv 0x00788330
void* FUN_00788330::Alloc(int a)
{
    void* result = ::FUN_00401000(a * 20);
    return result;
}

struct BSSystemUtility
{
    void Update();
    static BSSystemUtility* ms_pSystemUtility;
};

// If the BSSystemUtility singleton exists, sets its byte at offset 0x4a to 1 and calls Update().
// @fnv 0x0078d050
void UpdateSystemUtility()
{
    if (BSSystemUtility::ms_pSystemUtility)
    {
        ((char*)BSSystemUtility::ms_pSystemUtility)[0x4a] = 1;
        BSSystemUtility::ms_pSystemUtility->Update();
    }
}

struct FUN_00792780_Class
{
    void SetByteAtOffset30(unsigned char param);
};

// @fnv 0x00792780
void FUN_00792780_Class::SetByteAtOffset30(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x30) = aucValue;
}

struct GlobalObject_00788300
{
    ~GlobalObject_00788300();
    void* Destroy(unsigned int flags);
};
// Runs the destructor and, when flags has bit 0 set, frees the object with operator delete; returns this.
// @fnv 0x00788360
void* GlobalObject_00788300::Destroy(unsigned int flags)
{
    reinterpret_cast<::BSSimpleArrayActor *>(this)->FUN_00788390();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0078d8d0_Class
{
    void* FUN_0078d8d0(unsigned int flags);
};


// Calls FUN_0078d8b0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0078d8d0
void* FUN_0078d8d0_Class::FUN_0078d8d0(unsigned int flags)
{
    ::FUN_0078d8b0((::GlobalObject_00869f00 *)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0078e090_class
{
    char FUN_0078e090();
};

// Checks the 16 int slots at offset 0x2c and returns 1 only if every one is non-zero, otherwise 0.
// @fnv 0x0078e090
char FUN_0078e090_class::FUN_0078e090()
{
    for (int i = 0; i < 16; ++i)
    {
        if (!(*(int*)((char*)this + 0x2c + i * 4)))
            return 0;
    }
    return 1;
}

extern "C" void __cdecl CreateLoveTesterMenu(int a);

// @fnv 0x007915e0
void __cdecl FUN_007915e0()
{
    CreateLoveTesterMenu(0x23);
}

struct NiAVObject;
struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int index);
};
struct PropHelper
{
};
struct TileShaderProperty
{
};
struct FUN_0078cf10_Class
{
    void SetAlphaRecursive(NiAVObject* object, float alpha);
};
// Recursively applies alpha to the object's children and, if the object has a shader property, sets its alpha.
// @fnv 0x0078cf10
void FUN_0078cf10_Class::SetAlphaRecursive(NiAVObject* object, float alpha)
{
    if (!object)
        return;
    NiNode* node = ((NiNode * (*)(void*))(*(void***)object)[3])(object);
    for (unsigned int i = 0; node && i < node->GetNumChildren(); ++i)
        SetAlphaRecursive(node->GetAt(i), alpha);
    if (((int(*)(void*))(*(void***)object)[6])(object))
    {
        TileShaderProperty* pShaderProp = (TileShaderProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)object)))->FUN_00a59d30(FUN_00438220())));
        if (pShaderProp)
            reinterpret_cast<::FUN_00821600_shell *>((pShaderProp))->FUN_00821600(alpha);
    }
}

struct S5460
{
    virtual void v0();
    virtual unsigned int v1(unsigned int a);
    unsigned int FUN_007881d0();
};
struct FUN_0098f040_shell
{
};
// If FUN_00438b90 succeeds, initializes or advances the id at offset 0xc, then increments the counter at offset 8 and returns its previous value.
// @fnv 0x007881d0
unsigned int S5460::FUN_007881d0()
{
    if (((bool)(reinterpret_cast<::FUN_00438b90_class *>(this)->FUN_00438b90())))
    {
        if (!*(unsigned int*)((char*)this + 0xc))
        {
            unsigned int id = 4;
            *(unsigned int*)((char*)this + 4) = v1(id);
            *(unsigned int*)((char*)this + 0xc) = id;
        }
        else
        {
            unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>(this)->FUN_009a3910()));
            reinterpret_cast<::FUN_009a3c50_cls *>((((FUN_0098f040_shell*)this)))->UpdateThreat(id, *(unsigned int*)((char*)this + 8));
            *(unsigned int*)((char*)this + 0xc) = id;
        }
    }
    *(unsigned int*)((char*)this + 8) += 1;
    return *(unsigned int*)((char*)this + 8) - 1;
}

struct FUN_007883b0
{
    virtual ~FUN_007883b0();
    virtual void* Write(unsigned int size);
    void RecordRequestedSize(unsigned int requested, unsigned int savedSize);
    void* iSize;
    unsigned int iPosition;
    unsigned int iDataLength;
};

struct GlobalObject_0045cfe0
{
};
struct Actor
{
};
struct ActorValueUtility
{
    static int ConvertActorValue(int);
};
struct Player
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float v3(int);
};

// Returns the player's progress fraction between the current and next level XP thresholds, warning if current XP is below the low threshold.
// @fnv 0x0078d5a0
float GetLevelProgress()
{
    if (reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_0087f9f0() >= *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011d0c60)))))))
        return 0.0f;

    int lowXP;
    int highXP;
    int level = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_0087f9f0();
    lowXP = ActorValueUtility::ConvertActorValue(level);
    highXP = ActorValueUtility::ConvertActorValue(level + 1);
    float currentXP = ((Player*)(char*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)) + 0xa4 / 4)->v3(0x18);
    if (currentXP < lowXP)
        ::FUN_005b5e40();
    return (currentXP - lowXP) / (highXP - lowXP);
}

struct ArrSI
{
};

struct FUN_004bddd0_t : public ArrSI
{
};

struct G2
{
    void AddHead(int* a);
};

struct InventoryMenu
{
    static InventoryMenu* ms_pInventoryMenu;
};

struct FUN_007832a0_class
{
    void __cdecl FUN_007832a0(FUN_004bddd0_t* a);
};

// @fnv 0x007832a0
void __cdecl FUN_007832a0_class::FUN_007832a0(FUN_004bddd0_t* a)
{
    if (a != 0 && reinterpret_cast<::FUN_004bddd0_shell *>((a))->FUN_004bddd0(false))
    {
        int flags = static_cast<int>(((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((a))->GetName())));
        reinterpret_cast<G2*>(reinterpret_cast<char*>(InventoryMenu::ms_pInventoryMenu) + 0x11c)->AddHead(&flags);
    }
}

struct NiAdditionalGeometryData
{
    static void* __cdecl GetShadowSceneNodeForIndex(int a);
};

struct ShadowSceneNode
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
    virtual void v58(unsigned int a);
};

struct GO
{
    operator unsigned int() const;
    void operator=(void* a);
};

struct FUN_00b5ddb0_self
{
};

struct NiNodeDetachHelper
{
};

struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};


struct FUN_0078e0f0 : Menu_007a8b10
{
    ~FUN_0078e0f0();
};

// @fnv 0x0078e0f0
FUN_0078e0f0::~FUN_0078e0f0()
{
    ((ShadowSceneNode*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))
        ->v58((*reinterpret_cast<::GO *>(&::g_011da24c)).operator unsigned int());

    reinterpret_cast<::FUN_00572160_shell *>((((NiNodeDetachHelper*)(NiNode*)(unsigned int)(*reinterpret_cast<::GO *>(&::g_011da24c)).operator unsigned int())))->FUN_00572160();

    (*reinterpret_cast<::GO *>(&::g_011da24c)).operator=(0);
    (*reinterpret_cast<::GO *>(&::g_011da224)).operator=(0);
    DAT_011da204 = 0;

    reinterpret_cast<::MultiBoundManagerB5D *>((((FUN_00b5ddb0_self*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->FUN_00b5d180();
}


struct Elem_788
{
    int m_unk00, m_unk04, m_unk08, m_unk0c, m_unk10;
    Elem_788();
};

struct Owner_788
{
    void ConstructElems(Elem_788* pData, unsigned int ItemUpdateArray);
};
// @fnv 0x007883b0
void FUN_007883b0::RecordRequestedSize(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::Owner_788 *>(this)->ConstructElems((::Elem_788 *)(iSize), savedSize);
        iPosition = savedSize;
    }
}

// @fnv 0x00788260
void Owner_788::ConstructElems(Elem_788* pData, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
    {
        new (&pData[i]) Elem_788;
    }
}

struct TileStub;

struct MenuStub
{
    virtual ~MenuStub();
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
    virtual int GetID();
};

struct LoveTesterMenu : MenuStub
{
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
};

struct TileStub
{
    virtual ~TileStub();
};

struct IMStub
{
};

struct NodePtr
{
    NodePtr& operator=(void* p);
};



// @fnv 0x00791740
int FUN_00791740()
{
    return 0x432;
}

class FUN_00791750_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_flags[8];
    bool HasAllFlagsSet(int* index);
};

// Sets *index to 0, scans the 8 m_flags entries and returns false on the first zero, otherwise true.
// @fnv 0x00791750
bool FUN_00791750_cls::HasAllFlagsSet(int* index)
{
    *index = 0;
    for (; *index < 8; (*index)++)
    {
        if (m_flags[*index] == 0)
        {
            return false;
        }
    }
    return true;
}

struct Menu
{
    Menu();
    virtual ~Menu();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
public:
    void SetMenuVisibility(bool);
};
// @fnv 0x007915f0
void __cdecl CreateLoveTesterMenu(int aiValue)
{
    TileStub* pTile = ((::TileStub *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::TileStub *)(reinterpret_cast<::InterfaceManager *>((((::IMStub *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00586150()))))->FUN_00a01b00((void *)("Data\\Menus\\CharGen\\love_tester_menu.xml"))));
    MenuStub* menu = ((::MenuStub *)(reinterpret_cast<::FUN_00a03c90_shell *>((pTile))->FUN_00a03c90()));
    if (menu && menu->GetID() == ::FUN_00791740())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((menu))->FUN_00a1dc70((::TileMenu *)(pTile), false);
        (*reinterpret_cast<::LoveTesterMenu * *>(&::DAT_011da2c8)) = (LoveTesterMenu*)menu;
        int missing;
        if (!reinterpret_cast<::FUN_00791750_cls *>(((*reinterpret_cast<::LoveTesterMenu * *>(&::DAT_011da2c8))))->HasAllFlagsSet(&missing))
        {
            ::FUN_005b5e40();
            delete pTile;
            ::fnv_007037e0::FUN_007037e0();
            return;
        }
        (*reinterpret_cast<::LoveTesterMenu * *>(&::DAT_011da2c8))->unk58 = aiValue;
        reinterpret_cast<::fnv_007928e0::Menu109 *>(((*reinterpret_cast<::LoveTesterMenu * *>(&::DAT_011da2c8))))->Init();
        (*reinterpret_cast<::NodePtr *>(&::g_011da2f4)) = ((void *)(reinterpret_cast<::fnv_007945f0::SurgeryCameraMenu *>(((*reinterpret_cast<::LoveTesterMenu * *>(&::DAT_011da2c8))))->CreateSurgeryCamera()));
        ::FUN_005cfcb0(true);
        reinterpret_cast<::Menu *>((menu))->SetMenuVisibility(false);
    }
    else if (menu && reinterpret_cast<::Callees *>((menu))->FUN_00726070())
    {
        delete menu;
    }
}
struct MemberList
{
    int a, b, c;
    MemberList();
    ~MemberList();
};
struct StringMember
{
    int a, b;
    StringMember();
    ~StringMember();
};
struct ViewParam
{
    float a, b, c, d;
    ViewParam(float, float, float, float);
};
struct ItemValue
{
};
struct ListMember
{
    ItemValue* item;
    ListMember* next;
    ListMember();
    ~ListMember();
};
struct SmallMember
{
    int a, b, c;
    SmallMember();
    ~SmallMember();
};
struct SmallMember_d00483710 : SmallMember
{
    SmallMember_d00483710()
    {}
    ~SmallMember_d00483710();
};
struct SmartMember
{
    void* ptr;
    SmartMember();
    ~SmartMember();
    SmartMember& operator=(void*);
};
struct Renderer
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
    virtual void GetView(ViewParam*);
};
struct FUN_00788440 : Menu
{
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
    MemberList list0, list1, list2, list3, list4;
    int indices[43];
    StringMember text;
    ViewParam view;
    ListMember items;
    ListMember* current;
    ItemValue* selected;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0;
    SmallMember_d00483710 small0, small1;
    SmartMember nodes[4];
    int unk21c;
    unsigned short unk220, unk222;
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
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    FUN_00788440();
    virtual ~FUN_00788440();
};
// Initializes the view, clears the node and index arrays, queries the renderer view, sets flags, and applies the first item's data.
// @fnv 0x00788440
FUN_00788440::FUN_00788440() : view(0.0f, 0.0f, 0.0f, 0.0f)
{
    ::FUN_00403d30(&unk028, 0, 0x98);
    unk1e4 = 0;
    unk1e0 = 0;
    unk222 = 0;
    unk220 = 0;
    unk5b8 = 0;
    unk21c = 0;
    for (int nodeIndex = 0; nodeIndex < 4; ++nodeIndex)
        nodes[nodeIndex] = 0;
    unk5bc = 0;
    unk1e8 = 0;
    for (int entryIndex = 0; entryIndex < 43; ++entryIndex)
        indices[entryIndex] = 43;
    ((::Renderer *)(::FUN_0043c4b0()))->GetView(&view);
    unk1f0 = 0;
    unk1ec = 0;
    current = &items;
    unk5b4 = 0;
    reinterpret_cast<::LoadingMenu *>(this)->SetFloatFlag(0, !DAT_011a0294);
    reinterpret_cast<::LoadingMenu *>(this)->SetFloatFlag(4, true);
    selected = *((::ItemValue **)(new ((void *)(current)) ::Vec3()));
    if (selected)
    {
        void* data = ((void *)(reinterpret_cast<::BGSCameraPath *>((selected))->GetPrevPath()));
        if (data)
            reinterpret_cast<::FUN_0078b9b0_shell *>(this)->FUN_0078b9b0(&static_cast<Menu*>(data)->unk18);
    }
}

// Whether the control is active on any of the four input devices (mouse/keyboard/gamepad order).

class C1540InputManager
{
  public:
};

class C1540OSGlobals
{
  public:
};

class C1540Menu
{
  public:
    bool FUN_00791540(int iControl);
};

// Returns true if the input manager reports control state for device 2, 3, 0 or 1 for the given control.
// @fnv 0x00791540
bool C1540Menu::FUN_00791540(int iControl)
{
    return reinterpret_cast<::HotkeyWheelDisplay *>((((::C1540InputManager *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::C1540OSGlobals * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(2, iControl) ||
           reinterpret_cast<::HotkeyWheelDisplay *>((((::C1540InputManager *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::C1540OSGlobals * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(3, iControl) ||
           reinterpret_cast<::HotkeyWheelDisplay *>((((::C1540InputManager *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::C1540OSGlobals * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(0, iControl) ||
           reinterpret_cast<::HotkeyWheelDisplay *>((((::C1540InputManager *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::C1540OSGlobals * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(1, iControl);
}

extern int(* DAT_00fdf1b0)(void*);

class CriticalSectionEntry
{
  public:
    void FUN_0078d1d0();
};

// @fnv 0x0078d1d0
void CriticalSectionEntry::FUN_0078d1d0()
{
    DAT_00fdf1b0(this);
}

#include "generated/data/staging/blk_00780000_od.inc"
