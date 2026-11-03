// fallout/interface/menus/surgerymenu.cpp: SurgeryMenu, AnimOwner, MenuX, PainMenu and more (31 functions)

#include <new>
#include "fnv/decl/AnimationSequence.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/DecalAdd__DecalManager.h"
#include "fnv/decl/Dummy_00a239e0.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00493770_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004e7560_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_006ad180_Cls.h"
#include "fnv/decl/FUN_007151b0_shell.h"
#include "fnv/decl/FUN_00720010_shell.h"
#include "fnv/decl/FUN_0073b020_shell.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0088b740_shell.h"
#include "fnv/decl/FUN_0088c650_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a013d0_shell.h"
#include "fnv/decl/FUN_00a01440_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a23390_t.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/S004e88d0.h"
#include "fnv/decl/S148c0.h"
#include "fnv/decl/ScreenCamera.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_004937a0__FUN_004937a0_shell.h"
#include "fnv/decl/fnv_00495d00__FUN_00495d00_shell.h"
#include "fnv/decl/fnv_00495d20__FUN_00495d20_shell.h"
#include "fnv/decl/fnv_00576260__FUN_00576260_shell.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_007fd640__FUN_007fd640Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00950c20__FUN_00950c20_cls.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a328b0__SeqExt.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_anon_tile__NiPoint2_Sub.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005d9000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_007e1000.h"
#include "fnv/symbols_007e4000.h"
#include "fnv/symbols_007e5000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "surgerymenu_decls.h"
struct FUN_007e4fc0_shell
{
    int FUN_007e4fc0(int arg);
};

// @fnv 0x007e4fc0
int FUN_007e4fc0_shell::FUN_007e4fc0(int aiIndex)
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) + aiIndex * 0x14;
}

struct S
{
    virtual void a()
    {}
    virtual void b()
    {}
    virtual void c()
    {}
    virtual void d(int, int)
    {}
    bool HandleKey(int);
};
// Handles key codes 0x57/0x77 and 0x53/0x73 by calling d with 6 or 5 and returning true, otherwise returns false.
// @fnv 0x007e4260
bool S::HandleKey(int aiKey)
{
    if (aiKey == 0x57 || aiKey == 0x77)
    {
        this->d(6, 0);
        return true;
        goto L_retfalse;
    }
    if (aiKey == 0x53 || aiKey == 0x73)
    {
        d(5, 0);
        return true;
    }
L_retfalse:
    return false;
}

struct FUN_007e5540_shell
{
    int GetTierFromPercent(int);
};
// Maps a percentage to a tier: 0 for 100+, 1 for 75+, 2 for 50+, 3 for 25+, otherwise 4.
// @fnv 0x007e5540
int FUN_007e5540_shell::GetTierFromPercent(int aiPercent)
{
    if (aiPercent >= 100)
        return 0;
    else if (aiPercent >= 75)
        return 1;
    else if (aiPercent >= 50)
        return 2;
    else if (aiPercent >= 25)
        return 3;
    else
        return 4;
}

struct WoundFake
{
    int _00;
    int _04;
};
struct MenuFake
{
    char _pad[192];
    int _C0;
};
struct FakeList
{
    bool _ref_008256d0();
};
struct FUN_007e5720_struct
{
    WoundFake* FUN_007e5720();
};
// Walks the limb wound list and returns the first wound whose _04 matches the menu's _C0, or null if none is found.
// @fnv 0x007e5720
WoundFake* FUN_007e5720_struct::FUN_007e5720()
{
    FakeList* pWoundList = (FakeList*)&g_011dae48;
    while (pWoundList != 0 && !pWoundList->_ref_008256d0())
    {
        if ((*((::WoundFake **)(new ((void *)(pWoundList)) ::Vec3())))->_04 == ((MenuFake*)DAT_011dada4)->_C0)
            return *((::WoundFake **)(new ((void *)(pWoundList)) ::Vec3()));
        pWoundList = ((::FakeList *)(reinterpret_cast<::Callees *>((pWoundList))->FUN_00726070()));
    }
    return 0;
}

// Tests whether point lies inside the polygon by counting edge crossings of a horizontal ray and returns the inside flag.
// @fnv 0x007e5420
int PointInPolygon(double pgon[][2], int numverts, double point[2])
{
    int j, yflag0, yflag1, inside_flag;
    double tx, ty, *vtx0, *vtx1;

    tx = point[0];
    ty = point[1];

    vtx0 = pgon[numverts - 1];
    yflag0 = (vtx0[1] >= ty);
    vtx1 = pgon[0];

    inside_flag = 0;
    for (j = numverts + 1; --j;)
    {
        yflag1 = (vtx1[1] >= ty);
        if (yflag0 != yflag1)
        {
            if (((vtx1[1] - ty) * (vtx0[0] - vtx1[0]) >= (vtx1[0] - tx) * (vtx0[1] - vtx1[1])) == yflag1)
            {
                inside_flag = !inside_flag;
            }
        }
        yflag0 = yflag1;
        vtx0 = vtx1;
        vtx1 += 2;
    }
    return inside_flag;
}

struct GO
{
    operator unsigned int() const;
    void operator=(void*);
};

template <class T> struct NiPointer : public GO
{
    using GO::operator=;
};

struct NiAdditionalGeometryData
{
    static void* __cdecl GetShadowSceneNodeForIndex(int);
};

struct NiPoint3;
struct NiAVObject
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58(unsigned int)
    {}

public:
    ::NiPoint3 &FUN_0043c490();
};

struct NiNode : public NiAVObject
{
};

struct FUN_00b5ddb0_self : public NiAVObject
{
};

struct NiGeometry : public FUN_00b5ddb0_self
{
};

struct FUN_00950c20_self
{
};


NiPointer<NiNode> g_011dadb4;
NiPointer<NiNode> g_011dade8;
NiPointer<NiNode> g_011dae5c;
FUN_00950c20_self* _g_thePlayer;

// @fnv 0x007e5170
void FUN_007e5170()
{
    NiGeometry* pSourceGeometry = static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1));
    pSourceGeometry->v58(g_011dade8.operator unsigned int());

    NiGeometry* pScar2 = static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3));
    pScar2->v58(g_011dae5c.operator unsigned int());

    reinterpret_cast<::MultiBoundManagerB5D *>((static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->FUN_00b5d180();
    reinterpret_cast<::MultiBoundManagerB5D *>((static_cast<NiGeometry*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))))->FUN_00b5d180();

    reinterpret_cast<::fnv_00950c20::FUN_00950c20_cls *>((_g_thePlayer))->FUN_00950c20(0);

    reinterpret_cast<::ExtraOwnerB *>((reinterpret_cast<NiAVObject*>(g_011dae5c.operator unsigned int())))->FUN_00a5b230(FUN_005d9660());
    reinterpret_cast<::FUN_00a5a040_Class *>((reinterpret_cast<NiAVObject*>(g_011dae5c.operator unsigned int())))->FUN_00a5a040();

    g_011dadb4.operator=(static_cast<void*>(0));
    g_011dade8.operator=(static_cast<void*>(0));
    g_011dae5c.operator=(static_cast<void*>(0));
}


// If DAT_011dada4 is set and its byte at offset 0x90 is zero, calls FUN_00703080 with arg0 and arg1 divided by FUN_004dc1f0() and FUN_004dc200().
// @fnv 0x007e41f0
void __cdecl FUN_007e41f0(int arg0, int arg1)
{
    if (DAT_011dada4 != 0 && *((unsigned char*)DAT_011dada4 + 0x90) == 0)
    {
        ::fnv_00703080::FUN_00703080((float)((double)arg0 / (double)((int)(::FUN_004dc1f0()))), (float)((double)arg1 / (double)FUN_004dc200()));
    }
}

struct SurgeryRenderer
{
};
struct SurgeryContext
{
};
struct SurgeryObject
{
};
NiNode* __cdecl FUN_00450b80(int);
struct SurgeryInterface
{
};
struct SurgeryHolder
{
    NiNode* ptr;
    SurgeryHolder(NiNode*);
    ~SurgeryHolder();
    void FUN_0066b0d0(NiNode*);
};
struct SurgeryCull
{
};
// @fnv 0x007e47a0
void __cdecl UpdateSurgeryScene()
{
    if (!(unsigned)g_011dade8 || !(unsigned)g_011dae5c)
        return;
    reinterpret_cast<::S148c0 *>((((::SurgeryRenderer *)(::FUN_0043c4b0()))))->FUN_007148c0(0, 4);
    SurgeryObject* b = ((::SurgeryObject *)(::FUN_0045c670()));
    SurgeryContext* d = ((::SurgeryContext *)(reinterpret_cast<::MiddleLowProcess *>((b))->GetProcessInteger()));
    reinterpret_cast<::FUN_00c4f270_Class *>((d))->FUN_00c4f270(true);
    NiNode* c = (NiNode*)(unsigned)g_011dadb4;
    ::UpdateCameraFrustum((::NiCamera *)(c), 0.15f);
    NiNode* a = FUN_00450b80(1);
    SurgeryHolder e(((::NiNode *)(reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((((::SurgeryInterface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007fd640())));
    reinterpret_cast<::FUN_004a0fd0_shell *>((d))->FUN_004a0fd0(((::NiNode *)(::FUN_00559450((int *)&(e)))));
    ::FUN_00b6bee0(c, a, (::BSShaderAccumulator *)(d));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(c), (::BSShaderAccumulator *)(::NiNode *)(((::NiNode *)(::FUN_00559450((int *)&(e))))), 0);
    reinterpret_cast<::TaskQueueInterface *>((((SurgeryCull*)(unsigned)g_011dae5c)))->QueueActorDisarm(false);
    ::FUN_00b6bee0(c, FUN_00450b80(3), (::BSShaderAccumulator *)(d));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(c), (::BSShaderAccumulator *)(::NiNode *)(((::NiNode *)(::FUN_00559450((int *)&(e))))), 0);
    reinterpret_cast<::FUN_004a0fd0_shell *>((d))->FUN_004a0fd0(0);
    e.FUN_0066b0d0(0);
    reinterpret_cast<::FUN_00c4f2d0_class *>((d))->FUN_00c4f2d0();
}

struct FUN_00470470_Obj
{
};

struct Item_006815c0
{
    int unk00;
    FUN_00470470_Obj* pTarget;
};

struct FUN_007e5780_node : FUN_00470470_Obj
{
    bool FUN_008256d0();
    Item_006815c0** FUN_006815c0();
};

struct Player_a4
{
    virtual void v0();
    virtual void v4();
    virtual int v8();
};

struct Player_shell
{
    char pad[0xa4];
    Player_a4 sub;
};

struct Helper_011dada4
{
};

struct FUN_007e5780_shell
{
    FUN_007e5780_node* pNode;
    void* pArg4;
    int res08;
    bool b0C;
    void ProcessNodeChain();
};
// @fnv 0x007e5890
void SurgeryMenu::UpdatePerkEntries()
{
    if (DAT_011dada4)
    {
        BSSimpleList<BGSPerkEntry*>* limb = (BSSimpleList<BGSPerkEntry*>*)&g_011dae48;
        while (limb && !((BSSimpleList<const char*>*)limb)->IsEmpty())
        {
            reinterpret_cast<::FUN_007e5780_shell *>((((PerkEntryHandler*)((::BGSPerkEntry *)(new ((void *)(limb)) ::Vec3())))))->ProcessNodeChain();
            limb = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((limb))->FUN_00726070()));
        }
    }
}

// @fnv 0x007e5780
void FUN_007e5780_shell::ProcessNodeChain()
{
    b0C = true;
    FUN_007e5780_node* p = pNode;
    while (p && !p->FUN_008256d0())
    {
        reinterpret_cast<::FileMatchList *>(((*((::Item_006815c0 **)(new ((void *)(p)) ::Vec3())))->pTarget))->RemoveAll();
        p = ((::FUN_007e5780_node *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>((pNode))->RemoveAll();
    res08 = reinterpret_cast<::FUN_007e5540_shell *>((((Helper_011dada4*)DAT_011dada4)))->GetTierFromPercent(((Player_shell*)_g_thePlayer)->sub.v8());
}

struct NiFixedStringS
{
    NiFixedStringS(const char* s);
    ~NiFixedStringS();
    int str;
};
struct NiUpdateDataS
{
    NiUpdateDataS(float t, bool a, bool b);
    float time;
    bool b1;
    bool b2;
    int flags;
};
struct NiRTTIS
{
    int name;
    int base;
};
struct NiControllerSequenceS
{
    void Update(float t, bool b);
};
struct NiTimeControllerS
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
    virtual void Update(NiUpdateDataS& data);
};
struct NiControllerManagerS : NiTimeControllerS
{
};
struct NiNodeS
{
    void Update(NiUpdateDataS& data);
};
struct TimeGlobalS
{
};

struct AnimOwner
{
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
    int direction;
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
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    NiNodeS* node;
    int unkE4;
    int unkE8;
    float time;
    void UpdateAnimation();
};

// Advances time by the global delta, updates the direction-matched controller sequence, then updates the node with a zero-time update.
// @fnv 0x007e5a90
void AnimOwner::UpdateAnimation()
{
    NiTimeControllerS* ctrl = ((::NiTimeControllerS *)(::fnv_0043b230::FUN_0043b230((const char *)(node))));
    if (ctrl)
    {
        NiControllerManagerS* mgr = (NiControllerManagerS*)ctrl;
        NiControllerSequenceS* seq = 0;
        switch (direction)
        {
        case 1:
            seq = ((::NiControllerSequenceS *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((mgr))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedStringS &)(NiFixedStringS("Forward")))));
            break;
        case 2:
            seq = ((::NiControllerSequenceS *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((mgr))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedStringS &)(NiFixedStringS("Right")))));
            break;
        case 3:
            seq = ((::NiControllerSequenceS *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((mgr))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedStringS &)(NiFixedStringS("Left")))));
            break;
        }
        time += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal))))->GetStoredFloatValue();
        if (seq)
        {
            reinterpret_cast<::AnimationSequence *>((seq))->FUN_00a34ba0(time, true);
            for (; ctrl; ctrl = ((::NiTimeControllerS *)(::fnv_004a8a90::FUN_004a8a90((char *)(ctrl)))))
            {
                void* match = ((void *)(::FUN_00653270((const ::NiRTTI *)(const ::NiRTTIS *)(&(*reinterpret_cast<::NiRTTIS *>(&::g_011f36bc))), (::NiObject *)(ctrl))));
                if (match)
                {
                    NiUpdateDataS data(time, false, false);
                    ctrl->Update(data);
                    break;
                }
            }
        }
    }
    NiUpdateDataS updateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((node))->FUN_00a59c60((int)&(updateData));
}

class Tile
{
  public:
public:
    void Set(int, int);
};

int __cdecl FUN_007e1970();

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
};

struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char* name, unsigned int flags);
};

struct SndX
{
    int unk00;
    int unk04;
    int unk08;
};

struct SurgeryMenuType
{
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
    SndX sound94;
    SndX soundA0;
};

void __cdecl RefreshEntryByID(int);

class InterfaceManager
{
  public:
public:
    static float UpdateInterfaceState();
public:
    int FUN_00747d00();
};

// Closes the surgery menu: plays the UISurgeryExit sound, sets tile traits, stops and releases the menu's two sounds, and updates the parent tile.
// @fnv 0x007e1980
void CloseSurgeryMenu()
{
    Tile* pTile = ((::Tile *)(::FUN_00a09030(FUN_007e1970())));
    if (!pTile)
        return;

    if (DAT_011dada4)
    {
        BSSoundHandleEx sound7;
        reinterpret_cast<::SoundPlaybackHandle *>(&(sound7))->operator=((*(const ::SoundPlaybackHandle *)(&::FUN_00453a70()->GetSoundHandleByEditorID("UISurgeryExit", 0x121))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(sound7))->FUN_00ad8830(false);
        pTile->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((((SurgeryMenuType*)DAT_011dada4)))->FUN_00a1d910();
        FakeList* iter = (FakeList*)&g_011dae48;
        while (iter && !iter->_ref_008256d0())
        {
            RefreshEntryByID((*((::WoundFake **)(new ((void *)(iter)) ::Vec3())))->_04);
            iter = ((::FakeList *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        }
        ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((InterfaceManager*)((::SurgeryInterface *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60()))->Set(0xfa9, 0xff);
    }

    FUN_007e5170();
    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(((SurgeryMenuType*)DAT_011dada4)->sound94))->FUN_00ad88f0();
    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(((SurgeryMenuType*)DAT_011dada4)->soundA0))->FUN_00ad88f0();
    reinterpret_cast<::SoundPlaybackHandle *>(&(((SurgeryMenuType*)DAT_011dada4)->sound94))->Release();
    reinterpret_cast<::SoundPlaybackHandle *>(&(((SurgeryMenuType*)DAT_011dada4)->soundA0))->Release();
}

struct UiTile
{
};
struct InputX
{
};
struct OsX
{
};
extern OsX* g_osGlobals;
struct InterfaceX
{
    bool Mode();
};
bool IsMenu(int);
float ScaleByConstant(float);
float ScaleLimbWoundPercent(float);
struct ClockX
{
};
extern int DAT_011dad9c;
struct SoundX
{
    int id;
    int unk04;
    int unk08;
};
struct ActorValuesX
{
    virtual void v0();
    virtual void v4();
    virtual int Current(int);
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int Maximum(int);
};
struct PlayerX
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
    ActorValuesX values;
};
extern PlayerX* playerX;
struct MenuX
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
    UiTile* tile44;
    UiTile* tile48;
    int unk4c;
    int unk50;
    UiTile* tile54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    float value74;
    float value78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    char unk90;
    bool dragging;
    short unk92;
    SoundX sound94;
    SoundX sounda0;
    float valueac;
    unsigned int lastTime;

    void Active(bool);
    void Update();
    void FUN_007e23c0();
};
extern const char DAT_01077674[];
extern const char DAT_010776a8[];
extern const char DAT_010776b8[];
extern const char DAT_01077698[];
struct PainSound
{
    int id;
    int state;
    int flags;
    PainSound();
    ~PainSound();
};
struct PainAudio
{
    PainSound FUN_00ad7550(const char*, unsigned int);
};
struct PainTimer
{
};
struct PainValues
{
    virtual void v00();
    virtual void v04();
    virtual int get(int);
};
struct PainPlayer
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
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
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
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
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void hurt(int, int, int);
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
    PainValues values;
};
extern PainPlayer* g_thePlayer;
struct PainTile
{
};
float ScaleByConstant(float);
struct PainMenu
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
    PainTile* tile;
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
    float speed;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    float pain;
    unsigned int last;
    unsigned int lastHurt;
    int unkb8;
    int unkbc;
    int valueId;
    void FUN_007e28b0();
};
struct ScreenPoint
{
    float x, y;
    ScreenPoint();
};
struct Position3
{
    float x, y, z;
};
struct UpdateArgs
{
    float time;
    bool a, b;
    int flags;
    UpdateArgs(float, bool, bool);
};
struct WoundAnim
{
};
struct HitRef
{
    void** FUN_006815c0();
};
struct HitValue
{
};
struct WoundEntry
{
    WoundAnim* anim;
    HitRef* bHitDetected;
    float radius;
};
struct WoundNode
{
    WoundEntry** FUN_006815c0();
    bool FUN_008256d0();
    unsigned FUN_005ae380();
};
struct WoundData
{
    WoundNode* list;
    int index;
};
struct Projection
{
};
struct ProjectionPtr
{
    Projection* ptr;
    operator Projection*() const;
    Projection* operator->() const;
};

struct ClockValue
{
};

struct AudioHandle
{
    int id, a, b;
};
struct SceneNode
{
};
struct ScenePtr
{
    SceneNode* ptr;
    operator SceneNode*() const;
    SceneNode* operator->() const;
};
struct PlayerValues
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct PlayerView
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
    PlayerValues values;
};

float __cdecl FUN_00408840(float);
float __cdecl ApplyNoise(float);
extern int g_011dad9c;
struct SurgeryView
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
    ScreenPoint mouse;
    int unk7c, unk80, unk84;
    unsigned hitTime, lastTime;
    int unk90;
    AudioHandle idleSound, activeSound;
    float amount;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    ScenePtr nodes[8];
    int enabled;
    struct ValueOwner
    {
    };
    float UpdateWoundInteraction();
};

struct FaceCtrlS
{
    virtual void c00();
    virtual void c01();
    virtual void c02();
    virtual void c03();
    virtual void c04();
    virtual void c05();
    virtual void c06();
    virtual void c07();
    virtual void c08();
    virtual void c09();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual void c54();
    virtual void c55();
    virtual void c56();
    virtual void c57();
    virtual void c58();
    virtual void c59();
    virtual void c60();
    virtual void c61();
    virtual void c62();
    virtual void c63();
    virtual void c64();
    virtual void c65();
    virtual void c66();
    virtual void c67();
    virtual void c68();
    virtual void SetValue(int id, float value);
};
struct FaceNodeS
{
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18();
    virtual void n19();
    virtual void n20();
    virtual void n21();
    virtual void n22();
    virtual void n23();
    virtual void n24();
    virtual void n25();
    virtual void n26();
    virtual void n27();
    virtual void n28();
    virtual void n29();
    virtual void n30();
    virtual void n31();
    virtual void n32();
    virtual void n33();
    virtual void n34();
    virtual void n35();
    virtual void n36();
    virtual void n37();
    virtual void n38();
    virtual void n39();
    virtual void n40();
    virtual void n41();
    virtual void n42();
    virtual void n43();
    virtual void n44();
    virtual void n45();
    virtual void n46();
    virtual void n47();
    virtual void n48();
    virtual void n49();
    virtual void n50();
    virtual void n51();
    virtual void n52();
    virtual void n53();
    virtual void n54();
    virtual void n55();
    virtual void n56();
    virtual void n57();
    virtual void n58();
    virtual void n59();
    virtual void n60();
    virtual void n61();
    virtual void n62();
    virtual void n63();
    virtual FaceCtrlS* GetCtrl();
};
struct FaceRootS
{
    virtual void r00();
    virtual void r01();
    virtual void r02();
    virtual void r03();
    virtual void r04();
    virtual void r05();
    virtual void r06();
    virtual void r07();
    virtual void r08();
    virtual void r09();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual FaceNodeS* GetObjectByName(const NiFixedStringS& name);
};
struct TimeStubS
{
};
struct FaceOwnerS
{
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
    float fAC;
    void UpdateFaceGenNode();
};
// If g_011dae5c is set, sets face controller value 13 from fAC and updates the node with the current time.
// @fnv 0x007e3750
void FaceOwnerS::UpdateFaceGenNode()
{
    if (!g_011dae5c)
        return;
    FaceCtrlS* ctrl =
        ((FaceRootS*)(unsigned int)g_011dae5c)->GetObjectByName(NiFixedStringS("BSFaceGenNiNodeSkinned"))->GetCtrl();
    ctrl->SetValue(13, LinearInterpolate(0.0f, 1.0f, 0.0f, 100.0f, fAC));
    NiUpdateDataS data(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((TimeStubS*)&(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00() / 1000.0, true, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiNodeS*)(unsigned int)g_011dae5c)))->FUN_00a59c60((int)&(data));
}

class NiFixedString
{
  public:
    NiFixedString(const char* apString);
    ~NiFixedString();
    const char* m_kHandle;
};

class FUN_006815c0
{
  public:
    float x, y;
    FUN_006815c0();
};

struct FUN_007e4540_root
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void* v039(const NiFixedString& arName);
};

struct FUN_00a6fc50_cam
{
};

struct FUN_00747d00_im
{
};

extern const char DAT_01077774[];
extern const char DAT_01077768[];

struct FUN_007e4540_shell
{
    char pad[0xe0];
    FUN_007e4540_root* pRoot;
    bool FUN_007e4540();
};
// Updates the menu's top-menu flag, drag position, decay of valueac over time, sounds, and the value text from the player's actor value 16.
// @fnv 0x007e23c0
void MenuX::FUN_007e23c0()
{
    char text[256];
    if (!IsMenu(0x41e))
    {
        reinterpret_cast<::Tile *>((((::UiTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(FUN_00a01860("_IsTopMenu"), 0);
        return;
    }
    else
    {
        reinterpret_cast<::Tile *>((((::UiTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(FUN_00a01860("_IsTopMenu"), 1);
    }
    reinterpret_cast<::AnimOwner *>(this)->UpdateAnimation();
    bool idle3 = false;
    ::fnv_004b7210::FUN_004b7210();
    if (FUN_004b71d0())
    {
        if (::fnv_00717a40::FUN_00717a40(9, 1) == 2)
        {
            value74 = reinterpret_cast<::TileListBoxCalls *>((tile44))->GetFloat(0xfa1);
            value78 = reinterpret_cast<::TileListBoxCalls *>((tile44))->GetFloat(0xfa2);
        }
        if (::fnv_00717a40::FUN_00717a40(9, 1) == 0)
        {
            Active(true);
            reinterpret_cast<::PainMenu *>(this)->FUN_007e28b0();
        }
        else
            idle3 = true;
    }
    else
    {
        InputX* input = ((::InputX *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()));
        if (reinterpret_cast<::HotkeyWheelDisplay *>((input))->SetHotkeyItem(4, 1))
        {
            InterfaceX* manager3 = ((::InterfaceX *)(::fnv_004b7210::FUN_004b7210()));
            value74 = (float)reinterpret_cast<::InterfaceManager *>((manager3))->FUN_00747d00();
            value78 = (float)reinterpret_cast<::FUN_0073b020_shell *>((manager3))->FUN_0073b020();
        }
        bool hit = reinterpret_cast<::FUN_007e4540_shell *>(this)->FUN_007e4540();
        if (hit)
            reinterpret_cast<::Tile *>((((::UiTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::InterfaceX *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->Set(0xfa9, 0);
        else
            reinterpret_cast<::Tile *>((((::UiTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::InterfaceX *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->Set(0xfa9, 255);
        bool held4 = false;
        if ((reinterpret_cast<::HotkeyWheelDisplay *>((input))->SetHotkeyItem(4, 0) && dragging) || (reinterpret_cast<::HotkeyWheelDisplay *>((input))->SetHotkeyItem(4, 1) && hit))
        {
            held4 = true;
            dragging = true;
        }
        else
        {
            held4 = false;
            dragging = false;
        }
        if (held4)
        {
            Active(true);
            reinterpret_cast<::PainMenu *>(this)->FUN_007e28b0();
        }
        else
            idle3 = true;
    }
    if (idle3 == true)
    {
        float rate = ScaleByConstant(1.0f);
        valueac -= ((reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ClockX *>(&::g_timeGlobal))))->FUN_00825c00() - lastTime) / 1000.0) * rate;
        if (ScaleLimbWoundPercent(reinterpret_cast<::TileListBoxCalls *>((((::UiTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(DAT_011dad9c) / 100.0) * 100.0 > valueac)
            valueac = ScaleLimbWoundPercent(reinterpret_cast<::TileListBoxCalls *>((((::UiTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(DAT_011dad9c) / 100.0) * 100.0;
        lastTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ClockX *>(&::g_timeGlobal))))->FUN_00825c00();
        unk8c = lastTime;
        Active(false);
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(sound94))->IsPlaying())
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sound94))->FUN_00ad88f0();
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(sounda0))->IsPlaying())
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sounda0))->FUN_00ad88f0();
    }
    reinterpret_cast<::FaceOwnerS *>(this)->UpdateFaceGenNode();
    reinterpret_cast<::FUN_00a012d0_t *>((tile54))->FUN_00a012d0(0x1004, valueac / 100.0, true);
    ::FUN_00406d00(text, 256, "%i/%i", playerX->values.Current(16), playerX->values.Maximum(16));
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile48))->FUN_00a01350(FUN_00a01860("_Value"), (char *)(text), true);
}

// @fnv 0x007e4540
bool FUN_007e4540_shell::FUN_007e4540()
{
    ::fnv_004b7210::FUN_004b7210();
    if (FUN_004b71d0())
        return true;

    void* pNewObj = pRoot->v039(NiFixedString(DAT_01077774));
    void* pEdge8 = pRoot->v039(NiFixedString(DAT_01077768));
    int iX;
    int iY;
    int iRadiusTmp;
    if (pNewObj && pEdge8)
    {
        FUN_006815c0 kIntersectionOffset;
        FUN_006815c0 kTmpEdge;
        reinterpret_cast<::ScreenCamera *>((((FUN_00a6fc50_cam*)((::NiNode *)(::FUN_00559450((int *)(((SurgeryHolder*)&g_011dadb4))))))))->ProjectToScreen((*(const ::NiPoint3 *)(((void *)(::FUN_0045bb80((int)(pNewObj)))))), (*(float *)(&kIntersectionOffset.x)), (*(float *)(&kIntersectionOffset.y)), 1e-5f);
        reinterpret_cast<::ScreenCamera *>((((FUN_00a6fc50_cam*)((::NiNode *)(::FUN_00559450((int *)(((SurgeryHolder*)&g_011dadb4))))))))->ProjectToScreen((*(const ::NiPoint3 *)(((void *)(::FUN_0045bb80((int)(pEdge8)))))), (*(float *)(&kTmpEdge.x)), (*(float *)(&kTmpEdge.y)), 1e-5f);
        kIntersectionOffset.x *= ::InterfaceManager::UpdateInterfaceState();
        kIntersectionOffset.y = (1.0 - kIntersectionOffset.y) * FUN_00715da0();
        kTmpEdge.x *= ::InterfaceManager::UpdateInterfaceState();
        kTmpEdge.y = (1.0 - kTmpEdge.y) * FUN_00715da0();
        iX = kIntersectionOffset.x;
        iY = kIntersectionOffset.y;
        iRadiusTmp = reinterpret_cast<::FUN_00589850_Class *>((void *)&(const class ::FUN_006815c0 &)((*(class class ::FUN_006815c0 *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)&(kIntersectionOffset))->Subtract((::NiPoint2 *)&(kTmpEdge), *(const ::NiPoint2 *)nullptr)))))->FUN_00589850();
    }
    else
    {
        iX = 0x320;
        iY = 0x1db;
        iRadiusTmp = 0x145;
    }

    FUN_00747d00_im* pInterface6 = (FUN_00747d00_im*)((::SurgeryInterface *)(::fnv_004b7210::FUN_004b7210()));
    FUN_006815c0 kDeltaCur;
    kDeltaCur.x = reinterpret_cast<::InterfaceManager *>((pInterface6))->FUN_00747d00() - iX;
    kDeltaCur.y = reinterpret_cast<::FUN_0073b020_shell *>((pInterface6))->FUN_0073b020() - iY;
    return reinterpret_cast<::FUN_00589850_Class *>(&(kDeltaCur))->FUN_00589850() <= iRadiusTmp;
}

struct NiPoint3S;
struct NiPoint2S
{
    float x;
    float y;
    NiPoint2S();
    NiPoint2S operator-(const NiPoint2S& rhs) const;
};
struct MenuHolderS
{
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
    NiPoint2S cursor;
};
struct RefS
{
};
struct ProjNodeS
{
    RefS* item;
};
struct ProjListS
{
    bool IsEmpty();
};
struct ProjOwnerS
{
    int unk00;
    ProjListS* list;
};
struct CameraS
{
};

// Projects each item of both lists to screen space and compares their distance to the normalized cursor, returning 1, -1 or 0.
// @fnv 0x007e5250
int __cdecl CompareProjectedListsToCursor(ProjOwnerS* a, ProjOwnerS* pOwnerB)
{
    if (!DAT_011dada4)
        return 0;
    float fBestDist = 3.402823466e+38F;
    NiPoint2S screenPos;
    NiPoint2S cursor = ((MenuHolderS*)DAT_011dada4)->cursor;
    cursor.x = cursor.x / ::InterfaceManager::UpdateInterfaceState();
    cursor.y = cursor.y / ::FUN_00715da0();
    ProjListS* pNode = a->list;
    while (g_011dadb4 && pNode && !pNode->IsEmpty())
    {
        reinterpret_cast<::ScreenCamera *>((((CameraS*)(unsigned int)g_011dadb4)))->ProjectToScreen((*(const ::NiPoint3 *)(((::NiPoint3S *)(::FUN_0045bb80((int)(((::ProjNodeS *)(new ((void *)(pNode)) ::Vec3()))->item)))))), (*(float *)(&screenPos.x)), (*(float *)(&screenPos.y)), 1e-5f);
        screenPos.y = 1.0f - screenPos.y;
        if (reinterpret_cast<::FUN_00589850_Class *>((void *)&(const ::NiPoint2S &)((screenPos - cursor)))->FUN_00589850() < fBestDist)
            fBestDist = reinterpret_cast<::FUN_00589850_Class *>((void *)&(const ::NiPoint2S &)((screenPos - cursor)))->FUN_00589850();
        pNode = ((::ProjListS *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    pNode = pOwnerB->list;
    while (g_011dadb4 && pNode && !pNode->IsEmpty())
    {
        reinterpret_cast<::ScreenCamera *>((((CameraS*)(unsigned int)g_011dadb4)))->ProjectToScreen((*(const ::NiPoint3 *)(((::NiPoint3S *)(::FUN_0045bb80((int)(((::ProjNodeS *)(new ((void *)(pNode)) ::Vec3()))->item)))))), (*(float *)(&screenPos.x)), (*(float *)(&screenPos.y)), 1e-5f);
        screenPos.y = 1.0f - screenPos.y;
        if (reinterpret_cast<::FUN_00589850_Class *>((void *)&(const ::NiPoint2S &)((screenPos - cursor)))->FUN_00589850() < fBestDist)
            return 1;
        pNode = ((::ProjListS *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return -1;
}

// When the interface is up and menu 0x41e is not open, find the queued entry with this id and refresh it.

class E5810Entry
{
  public:
    int unk00;
    int m_iID;

};

class E5810Node
{
  public:
    bool IsEmpty();
};

extern void* g_pE5810Interface;
extern E5810Node g_kE5810Queue;

bool __cdecl E5810IsMenuOpen(int iMenuID);

// If the interface exists and menu 0x41e is closed, walks the queue and calls Refresh on the first entry whose m_iID equals the given ID.
// @fnv 0x007e5810
void RefreshEntryByID(int aiEntryID)
{
    if (g_pE5810Interface && !E5810IsMenuOpen(0x41e))
    {
        E5810Node* pkNode = &g_kE5810Queue;
        while (pkNode && !pkNode->IsEmpty())
        {
            if ((*((::E5810Entry **)(new ((void *)(pkNode)) ::Vec3())))->m_iID == aiEntryID)
            {
                reinterpret_cast<::FUN_007e5780_shell *>(((*((::E5810Entry **)(new ((void *)(pkNode)) ::Vec3())))))->ProcessNodeChain();
                break;
            }
            pkNode = ((::E5810Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        }
    }
}

struct LimbValueSource
{
};
struct LimbEntry
{
    LimbValueSource* source;
};
struct LimbListNode
{
    bool IsEmpty();
};
struct LimbWoundData
{
    LimbListNode* list;
};
struct TileS
{
};
namespace ActorValue {
enum Index
{
};
}

struct SurgeryLimbMenu
{
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    TileS* tile4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    TileS* tile70;
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
    int unkB4;
    int unkB8;
    int unkBC;
    ActorValue::Index avC0;

    float FUN_007e58e0();
};

// Sums limb source values and ranges over the wound list, clamps the total, and returns 1 minus the normalized total; sets tiles when no wound data exists.
// @fnv 0x007e58e0
float SurgeryLimbMenu::FUN_007e58e0()
{
    float total = 0;
    float range8 = 0;
    LimbWoundData* wound_ = ((::LimbWoundData *)(reinterpret_cast<::FUN_007e5720_struct *>(this)->FUN_007e5720()));
    if (!wound_)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((tile70))->FUN_00a012d0(FUN_00a01860("_Value"), 1.0f, true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile4C))->FUN_00a01350(0xfc4, (char *)(ActorValue::GetActorValueName(avC0)), true);
        return 0;
    }
    LimbListNode* node3 = wound_->list;
    while (node3 && !node3->IsEmpty())
    {
        LimbValueSource* src = ((::LimbEntry *)(new ((void *)(node3)) ::Vec3()))->source;
        total += reinterpret_cast<::FUN_00493770_shell *>((src))->FUN_00493770();
        range8 += reinterpret_cast<::FUN_00508100_shell *>((src))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((src))->FUN_00759450();
        node3 = ((::LimbListNode *)(reinterpret_cast<::Callees *>((node3))->FUN_00726070()));
    }
    if (total < ::_DAT_01012060)
        total = 0;
    total = total / range8;
    return 1.0 - total;
}

namespace fnv_007e5ee0 {
struct NodeV
{
    virtual void virt00();
    virtual void virt01();
    virtual void virt02();
    virtual void virt03();
    virtual void virt04();
    virtual void virt05();
    virtual void virt06();
    virtual void virt07();
    virtual void virt08();
    virtual void virt09();
    virtual void virt10();
    virtual void virt11();
    virtual void virt12();
    virtual void virt13();
    virtual void virt14();
    virtual void virt15();
    virtual void virt16();
    virtual void virt17();
    virtual void virt18();
    virtual void virt19();
    virtual void virt20();
    virtual void virt21();
    virtual void virt22();
    virtual void virt23();
    virtual void virt24();
    virtual void virt25();
    virtual void virt26();
    virtual void virt27();
    virtual void virt28();
    virtual void virt29();
    virtual void virt30();
    virtual void virt31();
    virtual void virt32();
    virtual void virt33();
    virtual void virt34();
    virtual void virt35();
    virtual void virt36();
    virtual void virt37();
    virtual void virt38();
    virtual void* virt39(void*);
    virtual void virt40();
    virtual void virt41();
    virtual void virt42();
    virtual void virt43();
    virtual void virt44();
    virtual void virt45();
    virtual void virt46();
    virtual void virt47();
    virtual void virt48();
    virtual void virt49();
    virtual void virt50();
    virtual void virt51();
    virtual void virt52();
    virtual void virt53();
    virtual void virt54();
    virtual void virt55(void*, int);
    virtual void virt56();
    virtual void virt57();
    virtual void virt58(void*);
};
struct PtrBox
{
    void* m_ptr;
};
struct DataF
{
    void* m_00[50];
    PtrBox m_aiIndexedValues[8];
    void* m_e8;
};
struct NiFixedString
{
    NiFixedString(const char*);
    ~NiFixedString();
    int m_str;
};
struct HostF
{
    int GetIndex(int);
    void FUN_007e5ee0(int a1, int a2);
};
// @fnv 0x007e5ee0
void HostF::FUN_007e5ee0(int a1, int a2)
{
    ((::fnv_007e5ee0::NodeV *)(::FUN_00559450((int *)(((PtrBox*)&g_011dade8)))))
        ->virt58(((::fnv_007e5ee0::NodeV *)(::FUN_00559450((int *)&(((DataF*)DAT_011dada4)->m_aiIndexedValues[GetIndex(a1)])))));
    ((::fnv_007e5ee0::NodeV *)(::FUN_00559450((int *)(((PtrBox*)&g_011dade8)))))
        ->virt55(((::fnv_007e5ee0::NodeV *)(::FUN_00559450((int *)&(((DataF*)DAT_011dada4)->m_aiIndexedValues[GetIndex(a2)])))), 1);
    ((DataF*)DAT_011dada4)->m_e8 = ((::fnv_007e5ee0::NodeV *)(::FUN_00559450((int *)(((PtrBox*)&g_011dade8)))))->virt39(&NiFixedString("ScarMesh"));
}
}  // namespace fnv_007e5ee0

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
public:
    static const ::NiPoint3 ZERO;
};
class TESForm
{
  public:
    virtual ~TESForm();
public:
    static ::TESForm *LookupFormByEditorID(const char *);
};
class BGSTextureSet : public TESForm
{
};
extern const char DAT_010777e0[], DAT_010777d0[];
struct SceneObject
{
};
struct PickRecord
{
};
class NiPoint3;
class NiPick
{
  public:
    unsigned int pickType, sortType, intersectType, coordinateType;
    unsigned char frontOnly, returnNormals, returnTextures, returnColors;
    void* root;
    unsigned int resultVtable, resultData, resultCapacity, resultSize, resultGrow, resultCount;
    unsigned char flags30, flags31, flags32, flags33;
    NiPick(int, int);
    ~NiPick();
    void FUN_00705fc0(void*);
public:
    bool PerformPick(const ::NiPoint3 &, const ::NiPoint3 &, bool);
};
struct RayCamera
{
};
struct CameraHolder
{
};
extern CameraHolder DAT_011dadb4;
struct SceneHolder
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    unsigned int unknownb4;
    unsigned int unknownb8;
    unsigned int unknownbc;
    unsigned int unknownc0;
    unsigned int unknownc4;
    unsigned int unknownc8;
    unsigned int unknowncc;
    unsigned int unknownd0;
    unsigned int unknownd4;
    unsigned int unknownd8;
    unsigned int unknowndc;
    unsigned int unknowne0;
    unsigned int unknowne4;
    void* scene;
};
struct DecalCell
{
};
extern DecalCell* DAT_011dea3c;
struct FUN_004a37b0
{
    NiPoint3 position, direction, unknown18;
    unsigned int unknown24;
    void* scene;
    unsigned int unknown2c;
    BGSTextureSet* texture;
    unsigned int unknown34;
    float width, height, depth, rotation;
    void* cell;
    unsigned int unknown4c, unknown50, unknown54;
    float angle;
    float unknown5c;
    NiPoint3 axis;
    unsigned int unknown6c;
    unsigned char unknown70, unknown71, unknown72, unknown73, unknown74, unknown75, unknown76, unknown77, unknown78,
        unknown79;
    FUN_004a37b0();
};
typedef struct FUN_004a37b0 DecalInfo;
struct DecalManager
{
};
extern DecalManager* __cdecl FUN_0049fef0();
struct SurgeryDecals
{
    void PlaceSurgeryDecal(float, float, bool);
};
// Raycasts from screen coordinates to find a scene position, then submits a decal with a texture chosen by good at that position.
// @fnv 0x007e5ff0
void SurgeryDecals::PlaceSurgeryDecal(float afScreenX, float afScreenY, bool good)
{
    NiPoint3 origin3, direction;
    float kScreenX = ((int)(::FUN_004dc1f0())) * afScreenX;
    float screenY_2 = FUN_004dc200() * afScreenY;
    reinterpret_cast<::CameraWindowRay *>((((::RayCamera *)(::FUN_00559450((int *)&(DAT_011dadb4))))))->MapScreenToRay((int)kScreenX, (int)screenY_2, (*(::NiPoint3 *)(&origin3)), (*(::NiPoint3 *)(&direction)), (const ::NiRenderTargetGroup *)(0));
    NiPoint3 position = ::NiPoint3::ZERO;
    NiPick pickVal(0, 8);
    reinterpret_cast<::FUN_00458b30_class *>(&(pickVal))->SetByteAtOffset17(0);
    pickVal.FUN_00705fc0(((SceneHolder*)DAT_011dada4)->scene);
    if (reinterpret_cast<::NiPick *>(&(pickVal))->PerformPick((*(const ::NiPoint3 *)(&origin3)), (*(const ::NiPoint3 *)(&direction)), 0))
    {
        unsigned int indexVal = 0;
        SceneObject* object = ((::SceneObject *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::PickRecord *)(reinterpret_cast<::BGSCameraPath *>(&(pickVal))->GetConditions()))))->FUN_00968670({})));
        if (object)
        {
            position = (*(::NiPoint3 *)(reinterpret_cast<::TESTopicInfoData *>((object))->GetLinkToList()));
            position.z += 10.0;
        }
    }
    BGSTextureSet* textureVal = 0;
    if (good)
        textureVal = dynamic_cast<BGSTextureSet*>(::TESForm::LookupFormByEditorID(DAT_010777e0));
    else
        textureVal = dynamic_cast<BGSTextureSet*>(::TESForm::LookupFormByEditorID(DAT_010777d0));
    DecalInfo infoB;
    infoB.position = position;
    infoB.direction = NiPoint3(0, 0, 1);
    infoB.scene = ((SceneHolder*)DAT_011dada4)->scene;
    infoB.rotation = ((float)(::FUN_004a4240()));
    infoB.texture = textureVal;
    infoB.unknown72 = 0;
    infoB.cell = ((void *)(reinterpret_cast<::LowProcess *>((DAT_011dea3c))->GetTarget()));
    infoB.width = 0.5f;
    infoB.height = 0.5f;
    infoB.depth = 20.0f;
    infoB.unknown5c = 0;
    infoB.axis = NiPoint3(1, 0, 0);
    infoB.angle = 75.0f;
    infoB.unknown74 = 1;
    infoB.unknown75 = 1;
    infoB.unknown77 = 0;
    reinterpret_cast<::DecalAdd::DecalManager *>((FUN_0049fef0()))->AddGeometryDecal((::DecalAdd::DecalRequest *)(::FUN_004a37b0 *)(&infoB), true, true);
}

struct NiPoint2
{
    float x, y;
    NiPoint2();
};
struct ScenePoint
{
    float x, y, z;
};
struct CursorNode
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
    virtual CursorNode* Find(const NiFixedString&);
    const ScenePoint& FUN_0045bb80();
};
struct CursorCamera
{
};
struct CursorTile
{
};
struct CursorMenu
{
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    CursorTile* tile;
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
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    CursorNode* node;
    void UpdateTilePositions(int x, int y);
};
// Finds CenterNode and FrameNode, projects them to screen space, clamps the cursor offset to a radius, and moves tiles 4001 and 4002 to the resulting positions.
// @fnv 0x007e42c0
void CursorMenu::UpdateTilePositions(int x, int y)
{
    CursorNode* radius = node->Find(NiFixedString("CenterNode"));
    CursorNode* center = node->Find(NiFixedString("FrameNode"));
    int edge, offset, originX;
    if (radius && center)
    {
        NiPoint2 centerPos;
        NiPoint2 edgePos;
        reinterpret_cast<::ScreenCamera *>((((::CursorCamera *)(::FUN_00559450((int *)(::GO *)(&g_011dadb4))))))->ProjectToScreen((const ::NiPoint3 &)(radius->FUN_0045bb80()), (*(float *)(&centerPos.x)), (*(float *)(&centerPos.y)), 0.00001f);
        reinterpret_cast<::ScreenCamera *>((((::CursorCamera *)(::FUN_00559450((int *)(::GO *)(&g_011dadb4))))))->ProjectToScreen((const ::NiPoint3 &)(center->FUN_0045bb80()), (*(float *)(&edgePos.x)), (*(float *)(&edgePos.y)), 0.00001f);
        centerPos.x *= ::InterfaceManager::UpdateInterfaceState();
        centerPos.y = (1.0 - centerPos.y) * FUN_00715da0();
        edgePos.x *= ::InterfaceManager::UpdateInterfaceState();
        edgePos.y = (1.0 - edgePos.y) * FUN_00715da0();
        edge = (int)centerPos.x;
        offset = (int)centerPos.y;
        originX = (int)reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::NiPoint2 &)((*(::NiPoint2 *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)&(centerPos))->Subtract((::NiPoint2 *)&(edgePos), *(const ::NiPoint2 *)nullptr)))))->FUN_00589850();
    }
    else
    {
        edge = 800;
        offset = 475;
        originX = 325;
    }
    NiPoint2 originY;
    originY.x = (float)(x - edge);
    originY.y = (float)(y - offset);
    if (reinterpret_cast<::FUN_00589850_Class *>((void *)&(originY))->FUN_00589850() > originX)
    {
        reinterpret_cast<::FUN_004e7560_shell *>(&(originY))->NormalizeXY();
        reinterpret_cast<::FUN_006ad180_Cls *>(&(originY))->Scale((float)originX);
    }
    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4001, edge + originY.x, true);
    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4002, offset + originY.y, true);
}

struct SeqHolder
{
};

struct WoundUpdater
{
    void UpdateWounds(float delta);
};

// @fnv 0x007e59f0
void WoundUpdater::UpdateWounds(float delta)
{
    WoundFake* pHead = ((FUN_007e5720_struct*)DAT_011dada4)->FUN_007e5720();
    FakeList* node2 = (FakeList*)pHead->_00;
    while (node2 != 0 && !node2->_ref_008256d0())
    {
        reinterpret_cast<::fnv_00a328b0::SeqExt *>((((SeqHolder*)(*((::WoundFake **)(new ((void *)(node2)) ::Vec3())))->_00)))->FUN_00a328b0(reinterpret_cast<::FUN_00508100_shell *>((((SeqHolder*)(*((::WoundFake **)(new ((void *)(node2)) ::Vec3())))->_00)))->FUN_00508100() * delta, true);
        node2 = ((::FakeList *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070()));
    }
    NiUpdateDataS data3(0.0f, true, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiNodeS*)((::NiNode *)(::FUN_00559450((int *)&(((SurgeryHolder&)g_011dade8))))))))->FUN_00a59c60((int)&(data3));
}


class DirectionSequence
{
  public:
};

class DirectionManager
{
  public:
      // FindSequenceByName
                                   // deactivate all
};

class DirectionRoot
{
  public:
      // GetController
};

struct DirectionSceneOwner
{
    char unk00[0xe0];
    DirectionRoot* m_pkTreeNode;  // +0xe0
};


class DirectionAnimator
{
  public:
    void SetDirection(int iDirection);

    char unk00[0x28];
    int m_iDirection;  // +0x28
    char unk2c[0xc0];
    float m_fDirectionBlend;  // +0xec
};

// @fnv 0x007e5c80
void DirectionAnimator::SetDirection(int iDirection)
{
    m_iDirection = iDirection;
    m_fDirectionBlend = 0.0f;
    DirectionManager* pkController =
        ((::DirectionManager *)(reinterpret_cast<::MyHost *>((static_cast<DirectionSceneOwner*>(DAT_011dada4)->m_pkTreeNode))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTIS *)(&(*reinterpret_cast<::NiRTTIS *>(&::g_011f36ac))))));
    if (pkController)
    {
        DirectionManager* pkManager = pkController;
        DirectionSequence* pkSequence2 = 0;
        switch (m_iDirection)
        {
        case 1:
            pkSequence2 = ((::DirectionSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pkManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Forward")))));
            break;
        case 2:
            pkSequence2 = ((::DirectionSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pkManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Right")))));
            break;
        case 3:
            pkSequence2 = ((::DirectionSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pkManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Left")))));
            break;
        }
        if (pkSequence2)
        {
            reinterpret_cast<::NiControllerManager *>((pkManager))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((pkManager))->ActivateControllerSequence((::NiControllerSequence *)(pkSequence2), 0, true, 1.0f, 0.0f, (::NiControllerSequence *)(::DirectionSequence *)(0));
            reinterpret_cast<::TaskQueueInterface *>((pkManager))->QueueReferenceStateTask(true);
            ::SetNegatedGlobal((void *)(pkSequence2));
        }
    }
    ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(static_cast<DirectionSceneOwner*>(DAT_011dada4)->m_pkTreeNode));
}

namespace LockpickResistance {

struct PickTile
{
};

struct PickInterface
{
};

struct PickPoint
{
    float x, y;
    PickPoint();
    PickPoint FUN_004a4f40(float afScale);
};

struct PickInput
{
};

struct PickGlobals
{
};

struct PickSetting
{
};

struct PickTimer
{
};

struct PickActorValues
{
    virtual void v00();
    virtual void v01();
    virtual int GetActorValue(int aiIndex);
};

struct PickPlayer
{
    char pad00[0xa4];
    PickActorValues kValues;
};

extern PickGlobals* DAT_011dea0c;
extern PickPlayer* DAT_011dea3c;
extern int DAT_011dad9c;

float __cdecl ApplyNoise(float afValue);
PickPoint __cdecl FUN_00532fd0(float afScale, const PickPoint& arPoint);

static const char s_szMinResistanceTime[] = "_MinResistanceTime";
static const char s_szMaxResistanceTime[] = "_MaxResistanceTime";
static const char s_szMinMagnitude[] = "_MinMagnitude";
static const char s_szMaxMagnitude[] = "_MaxMagnitude";
static const char s_szMinXBoxMag[] = "_MinXBoxMag";
static const char s_szMaxXBoxMag[] = "_MaxXBoxMag";
static const char s_szMouseMinPercent[] = "_MouseMinPercent";
static const char s_szMouseMaxPercent[] = "_MouseMaxPercent";

struct PickMenu
{
    char pad00[0x44];
    PickTile* pDial;
    char pad48[0x14];
    PickTile* kArgumentPosition;
    char pad60[0x14];
    PickPoint kCursorPos;
    PickPoint kIntersectionOffset;
    float fResistance;
    char pad88[8];
    bool bForcing;
    char pad91[0x1b];
    float fLockLevel;

    void UpdateLockpick(bool abForcing);
};

// Updates lockpick cursor position and resistance based on forcing state, input device, and interpolated magnitude and mouse percent values.
// @fnv 0x007e3890
void PickMenu::UpdateLockpick(bool abForcing)
{
    PickInterface* pInterfaceFinal = ((::LockpickResistance::PickInterface *)(::fnv_004b7210::FUN_004b7210()));
    static int iMinResistanceTime = ::FUN_00a00940(s_szMinResistanceTime, -1);
    static int iMaxResistanceTime = ::FUN_00a00940(s_szMaxResistanceTime, -1);
    static int iMinMagnitude = ::FUN_00a00940(s_szMinMagnitude, -1);
    static int iMaxMagnitude = ::FUN_00a00940(s_szMaxMagnitude, -1);
    static int iMinXBoxMag = ::FUN_00a00940(s_szMinXBoxMag, -1);
    static int iMaxXBoxMag = ::FUN_00a00940(s_szMaxXBoxMag, -1);
    static int iMouseMinPercent = ::FUN_00a00940(s_szMouseMinPercent, -1);
    static int iMouseMaxPercent = ::FUN_00a00940(s_szMouseMaxPercent, -1);
    float fMinResistance = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMinResistanceTime);
    float fMaxResistance = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMaxResistanceTime);
    float fMinMagnitude = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMinMagnitude);
    float fMaxMagnitude = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMaxMagnitude);
    float fSampleMinXBoxMag = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMinXBoxMag);
    float fMaxXBoxMagCount = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMaxXBoxMag);
    float fMouseMinLocal = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMouseMinPercent) / 100.0;
    float fMouseMax = reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(iMouseMaxPercent) / 100.0;
    if (abForcing)
    {
        bForcing = true;
        reinterpret_cast<::Tile *>((kArgumentPosition))->Set(0xfa3, 1);
        float fResistanceTimeLocal;
        float fMagnitudeVal;
        float fMouseNew;
        ::ComputeInjuryEffectScalars(&fResistanceTimeLocal, &fMagnitudeVal, &fMouseNew,
                                   reinterpret_cast<::TileListBoxCalls *>((((::LockpickResistance::PickTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(DAT_011dad9c) / 100.0, fLockLevel / 100.0,
                                   DAT_011dea3c->kValues.GetActorValue(0x25));
        fResistanceTimeLocal = ::LinearInterpolate(fMinResistance, fMaxResistance, 0.0f, 1.0f, fResistanceTimeLocal);
        float fShakeXVal = ApplyNoise(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::LockpickResistance::PickTimer *>(&::g_timeGlobal))))->FUN_00825c00() * 0.00025f);
        float fShakeY = ApplyNoise((reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::LockpickResistance::PickTimer *>(&::g_timeGlobal))))->FUN_00825c00() + 0x3039) * 0.00025f);
        fMagnitudeVal = ::LinearInterpolate(fMinMagnitude, fMaxMagnitude, 0.0f, 1.0f, fMagnitudeVal);
        fShakeXVal = ::LinearInterpolate(fShakeXVal >= 0.0 ? fMinMagnitude : -fMinMagnitude,
                                       fShakeXVal >= 0.0 ? fMaxMagnitude : -fMaxMagnitude, -0.5f, 0.5f, fShakeXVal) *
                     fMagnitudeVal;
        fShakeY = ::LinearInterpolate(fShakeY >= 0.0 ? fMinMagnitude : -fMinMagnitude,
                                    fShakeY >= 0.0 ? fMaxMagnitude : -fMaxMagnitude, -0.5f, 0.5f, fShakeY) *
                  fMagnitudeVal;
        fMouseNew = ::LinearInterpolate(fMouseMinLocal, fMouseMax, 0.0f, 1.0f, fMouseNew);
        if (1)
        {
            kIntersectionOffset.x = fShakeXVal;
            kIntersectionOffset.y = fShakeY;
        }
        reinterpret_cast<::S004e88d0 *>(&(kCursorPos))->Add((::S004e88d0 *)(&kIntersectionOffset));
        PickInput* pInputIn = ((::LockpickResistance::PickInput *)(reinterpret_cast<::FUN_00877720_shell *>((DAT_011dea0c))->FUN_00877720()));
        PickPoint kInput;
        if (((::LockpickResistance::PickInterface *)(::fnv_004b7210::FUN_004b7210()))->FUN_004b71d0())
        {
            int iStickX = reinterpret_cast<::FUN_00a23390_t *>((pInputIn))->GetAxisState(0, 7);
            int iStickYTmp = reinterpret_cast<::FUN_00a23390_t *>((pInputIn))->GetAxisState(0, 8);
            kInput.x = (int)(iStickX * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::LockpickResistance::PickSetting *>(&::g_011d8c5c)))))));
            kInput.y = (int)(-iStickYTmp * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::LockpickResistance::PickSetting *>(&::g_011d8c5c)))))));
            reinterpret_cast<::S004e88d0 *>(&(kCursorPos))->Add((::S004e88d0 *)(&kInput.FUN_004a4f40(::LinearInterpolate(0.25f, 0.5f, 0.0f, 1.0f, fMouseNew))));
        }
        else
        {
            kInput.x = reinterpret_cast<::Dummy_00a239e0 *>((pInputIn))->FUN_00a239e0(1);
            kInput.y = reinterpret_cast<::Dummy_00a239e0 *>((pInputIn))->FUN_00a239e0(2);
            reinterpret_cast<::S004e88d0 *>(&(kCursorPos))->Add((::S004e88d0 *)(&FUN_00532fd0(fMouseNew, kInput)));
        }
        fResistance = fMagnitudeVal * fMouseNew * reinterpret_cast<::FUN_00589850_Class *>(&(kInput))->FUN_00589850();
        if (fResistance > 10.0)
            fResistance = 10.0f;
        fResistance = fResistance / 5.0;
        reinterpret_cast<::CursorMenu *>(this)->UpdateTilePositions((int)kCursorPos.x, (int)kCursorPos.y);
        float fTimeSinceScaleStart = ::fnv_0070ecb0::GetRatio();
        reinterpret_cast<::FUN_007151b0_shell *>((pInterfaceFinal))->UpdateTilePosition(
            ((double)(reinterpret_cast<::FUN_00a013d0_shell *>((pDial))->GetTotalFloat())) /
            ((int)(::FUN_004dc1f0())) * fTimeSinceScaleStart, {});
    }
    else
    {
        bForcing = false;
        fResistance = 0.0f;
        reinterpret_cast<::Tile *>((kArgumentPosition))->Set(0xfa3, 0);
        if (((::LockpickResistance::PickInterface *)(::fnv_004b7210::FUN_004b7210()))->FUN_004b71d0())
        {
            PickInput* pPadIn = ((::LockpickResistance::PickInput *)(reinterpret_cast<::FUN_00877720_shell *>((DAT_011dea0c))->FUN_00877720()));
            int iPadX = reinterpret_cast<::FUN_00a23390_t *>((pPadIn))->GetAxisState(0, 7);
            int iPadY = reinterpret_cast<::FUN_00a23390_t *>((pPadIn))->GetAxisState(0, 8);
            iPadX = (int)(iPadX * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::LockpickResistance::PickSetting *>(&::g_011d8c5c)))))));
            iPadY = (int)(-iPadY * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::LockpickResistance::PickSetting *>(&::g_011d8c5c)))))));
            reinterpret_cast<::CursorMenu *>(this)->UpdateTilePositions((int)reinterpret_cast<::TileListBoxCalls *>((pDial))->GetFloat(0xfa1) + iPadX, (int)reinterpret_cast<::TileListBoxCalls *>((pDial))->GetFloat(0xfa2) + iPadY);
        }
        else
        {
            reinterpret_cast<::CursorMenu *>(this)->UpdateTilePositions(reinterpret_cast<::InterfaceManager *>((pInterfaceFinal))->FUN_00747d00(), reinterpret_cast<::FUN_0073b020_shell *>((pInterfaceFinal))->FUN_0073b020());
        }
    }
}

}

struct EventExtraNode
{
    void** FUN_006815c0();
};
struct EventEntry
{
    ~EventEntry();
};
struct EventTile
{
};
struct EventValues
{
    virtual void v0();
    virtual void v4();
    virtual int Current(int);
    virtual float Damage(int);
};
struct EventMagic
{
};
struct EventFormBase
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
};
struct EventForm : EventFormBase, EventMagic
{
};
struct EventTarget
{
};
struct EventPlayer
{
    virtual void pv000();
    virtual void pv004();
    virtual void pv008();
    virtual void pv00c();
    virtual void pv010();
    virtual void pv014();
    virtual void pv018();
    virtual void pv01c();
    virtual void pv020();
    virtual void pv024();
    virtual void pv028();
    virtual void pv02c();
    virtual void pv030();
    virtual void pv034();
    virtual void pv038();
    virtual void pv03c();
    virtual void pv040();
    virtual void pv044();
    virtual void pv048();
    virtual void pv04c();
    virtual void pv050();
    virtual void pv054();
    virtual void pv058();
    virtual void pv05c();
    virtual void pv060();
    virtual void pv064();
    virtual void pv068();
    virtual void pv06c();
    virtual void pv070();
    virtual void pv074();
    virtual void pv078();
    virtual void pv07c();
    virtual void pv080();
    virtual void pv084();
    virtual void pv088();
    virtual void pv08c();
    virtual void pv090();
    virtual void pv094();
    virtual void pv098();
    virtual void pv09c();
    virtual void pv0a0();
    virtual void pv0a4();
    virtual void pv0a8();
    virtual void pv0ac();
    virtual void pv0b0();
    virtual void pv0b4();
    virtual void pv0b8();
    virtual void pv0bc();
    virtual void pv0c0();
    virtual void pv0c4();
    virtual void pv0c8();
    virtual void pv0cc();
    virtual void pv0d0();
    virtual void pv0d4();
    virtual void pv0d8();
    virtual void pv0dc();
    virtual void pv0e0();
    virtual void pv0e4();
    virtual void pv0e8();
    virtual void pv0ec();
    virtual void pv0f0();
    virtual void pv0f4();
    virtual void pv0f8();
    virtual void pv0fc();
    virtual void pv100();
    virtual void pv104();
    virtual void pv108();
    virtual void pv10c();
    virtual void pv110();
    virtual void pv114();
    virtual void pv118();
    virtual void pv11c();
    virtual void pv120();
    virtual void pv124();
    virtual void pv128();
    virtual void pv12c();
    virtual void pv130();
    virtual void pv134();
    virtual void pv138();
    virtual void pv13c();
    virtual void pv140();
    virtual void pv144();
    virtual void pv148();
    virtual void pv14c();
    virtual void pv150();
    virtual void pv154();
    virtual void pv158();
    virtual void pv15c();
    virtual void pv160();
    virtual void pv164();
    virtual void pv168();
    virtual void pv16c();
    virtual void pv170();
    virtual void pv174();
    virtual void pv178();
    virtual void pv17c();
    virtual void pv180();
    virtual void pv184();
    virtual void pv188();
    virtual void pv18c();
    virtual void pv190();
    virtual void pv194();
    virtual void pv198();
    virtual void pv19c();
    virtual void pv1a0();
    virtual void pv1a4();
    virtual void pv1a8();
    virtual void pv1ac();
    virtual void pv1b0();
    virtual void pv1b4();
    virtual void pv1b8();
    virtual void pv1bc();
    virtual void pv1c0();
    virtual void pv1c4();
    virtual void pv1c8();
    virtual void pv1cc();
    virtual void pv1d0();
    virtual void pv1d4();
    virtual void pv1d8();
    virtual void pv1dc();
    virtual void pv1e0();
    virtual void pv1e4();
    virtual void pv1e8();
    virtual void pv1ec();
    virtual void pv1f0();
    virtual void pv1f4();
    virtual void pv1f8();
    virtual void pv1fc();
    virtual void pv200();
    virtual void pv204();
    virtual void pv208();
    virtual void pv20c();
    virtual void pv210();
    virtual void pv214();
    virtual void pv218();
    virtual void pv21c();
    virtual void pv220();
    virtual void pv224();
    virtual void pv228();
    virtual void pv22c();
    virtual void pv230();
    virtual void pv234();
    virtual void pv238();
    virtual void pv23c();
    virtual void pv240();
    virtual void pv244();
    virtual void pv248();
    virtual void pv24c();
    virtual void pv250();
    virtual void pv254();
    virtual void pv258();
    virtual void pv25c();
    virtual void pv260();
    virtual void pv264();
    virtual void pv268();
    virtual void pv26c();
    virtual void pv270();
    virtual void pv274();
    virtual void pv278();
    virtual void pv27c();
    virtual void pv280();
    virtual void pv284();
    virtual void pv288();
    virtual void pv28c();
    virtual void pv290();
    virtual void pv294();
    virtual void pv298();
    virtual void pv29c();
    virtual void pv2a0();
    virtual void pv2a4();
    virtual void pv2a8();
    virtual void pv2ac();
    virtual void pv2b0();
    virtual void pv2b4();
    virtual void pv2b8();
    virtual void pv2bc();
    virtual void pv2c0();
    virtual void pv2c4();
    virtual void pv2c8();
    virtual void pv2cc();
    virtual void pv2d0();
    virtual void pv2d4();
    virtual void pv2d8();
    virtual void pv2dc();
    virtual void pv2e0();
    virtual void pv2e4();
    virtual void pv2e8();
    virtual void pv2ec();
    virtual void pv2f0();
    virtual void pv2f4();
    virtual void pv2f8();
    virtual void pv2fc();
    virtual void pv300();
    virtual void pv304();
    virtual void pv308();
    virtual void pv30c();
    virtual void pv310();
    virtual void pv314();
    virtual void pv318();
    virtual void pv31c();
    virtual void pv320();
    virtual void pv324();
    virtual void pv328();
    virtual void pv32c();
    virtual void pv330();
    virtual void pv334();
    virtual void pv338();
    virtual void pv33c();
    virtual void pv340();
    virtual void pv344();
    virtual void pv348();
    virtual void pv34c();
    virtual void pv350();
    virtual void pv354();
    virtual void pv358();
    virtual void pv35c();
    virtual void pv360();
    virtual void pv364();
    virtual void pv368();
    virtual void pv36c();
    virtual void pv370();
    virtual void pv374();
    virtual void pv378();
    virtual void pv37c();
    virtual void pv380();
    virtual void pv384();
    virtual void pv388();
    virtual void pv38c();
    virtual void pv390();
    virtual void pv394();
    virtual void pv398();
    virtual void pv39c();
    virtual void pv3a0();
    virtual void pv3a4();
    virtual void pv3a8();
    virtual void Mod(int, float, int);
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
    EventTarget target;
    int unk98;
    int unk9c;
    int unka0;
    EventValues values;
};
struct EventScene
{
    void* ptr;
};
struct EventWounds
{
    int unk00, unk04, unk08;
    bool changed;
};
struct EventMenu
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
    EventTile* label;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    EventTile* gauge;
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
    float amount;
    int unkb0;
    int unkb4;
    int unkb8;
    EventEntry* entry;
    int limb;
    int unkc4;
    EventScene nodes[8];
    void OnButtonClick(int, int);
};
void __cdecl ComputeMedicineHealing(float&, float&, int, bool, float);

struct BoneText
{
    const char* FUN_0043b1b0() const;
};
struct BoneBlock
{
    BoneText& FUN_006815c0();
};
struct BoneAnim
{
};
struct BoneManager
{
};
struct BoneHost
{
};
struct BoneEntry;
struct BoneNode
{
    BoneEntry** FUN_006815c0();
    bool FUN_008256d0();
    void FUN_005ae3d0(BoneEntry*&);
};
struct FUN_0096a2d0
{
    void* item;
    void* next;
    FUN_0096a2d0();
    void FUN_005ae3d0(void* const&);
};
struct BoneEntry
{
    BoneAnim* anim;
    FUN_0096a2d0* objects;
    float radius;
};
struct BoneWound
{
    BoneNode* list;
    int limb;
    int bracket;
    unsigned char dirty;
};
struct BoneValues
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float Get(int);
};
struct BonePlayer
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
    BoneValues values;
};
struct BoneMenu
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int limb;
    int bracket;
    int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0;
    BoneManager* manager;
};
struct BoneWoundList
{
    void FUN_005ae3d0(BoneWound*&);
};
extern "C" int sprintf(char*, const char*, ...);
extern "C" int _strnicmp(const char*, const char*, unsigned);

// Updates bone wound animations on the host by matching bone names, computing a blend factor from the limb tier, and applying it to each wound entry.
// @fnv 0x007e4920
void __cdecl UpdateBoneWounds(BoneHost* host)
{
    if (!host)
        return;
    BoneManager* managerLocal3 = ((::BoneManager *)(reinterpret_cast<::MyHost *>((host))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTIS *)(&(*reinterpret_cast<::NiRTTIS *>(&::g_011f36ac))))));
    bool cachedX = true;
    if (managerLocal3)
    {
        ((BoneMenu*)DAT_011dada4)->manager = managerLocal3;
        BoneWound* previous_2 = ((::BoneWound *)(reinterpret_cast<::FUN_007e5720_struct *>((((BoneMenu*)DAT_011dada4)))->FUN_007e5720()));
        BoneWound* currentItem = 0;
        if (!previous_2)
        {
            cachedX = false;
            currentItem = new BoneWound;
            currentItem->limb = ((BoneMenu*)DAT_011dada4)->limb;
            currentItem->bracket =
                reinterpret_cast<::FUN_007e5540_shell *>((((BoneMenu*)DAT_011dada4)))->GetTierFromPercent((int)((BonePlayer*)DAT_011dea3c)->values.Get(currentItem->limb));
            currentItem->list = (BoneNode*)new FUN_0096a2d0;
            currentItem->dirty = 0;
            ((BoneWoundList&)g_011dae48).FUN_005ae3d0(currentItem);
        }
        else
            currentItem = previous_2;
        for (unsigned i = 0; i < reinterpret_cast<::fnv_00495d00::FUN_00495d00_shell *>((((BoneMenu*)DAT_011dada4)->manager))->FUN_00495d00(); i++)
        {
            BoneAnim* sequence5 = ((::BoneAnim *)(reinterpret_cast<::fnv_00495d20::FUN_00495d20_shell *>((((BoneMenu*)DAT_011dada4)->manager))->FUN_00495d20(i)));
            char nameSize5[32];
            sprintf(nameSize5, "Bone%s", (*(::BoneText *)(reinterpret_cast<::TESTopicInfoData *>((sequence5))->GetLinkToList())).FUN_0043b1b0());
            BoneEntry* entry24 = 0;
            if (!previous_2 || previous_2->dirty == 1)
            {
                entry24 = new BoneEntry;
                entry24->objects = new FUN_0096a2d0;
                entry24->anim = sequence5;
            }
            for (unsigned j = 0; j < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((sequence5))->FUN_0084e3a0())); j++)
            {
                BoneBlock* block = ((::BoneBlock *)(reinterpret_cast<::FUN_007e4fc0_shell *>((sequence5))->FUN_007e4fc0(j)));
                if (((int)(reinterpret_cast<::fnv_004937a0::FUN_004937a0_shell *>((sequence5))->FUN_004937a0(j))))
                {
                    if (_strnicmp(nameSize5, (*(::BoneText *)(new ((void *)(block)) ::Vec3())).FUN_0043b1b0(), 6))
                        reinterpret_cast<::Holder *>((sequence5))->FUN_00a32b80(j);
                    else if (!previous_2 || previous_2->dirty == 1)
                    {
                        entry24->objects->FUN_005ae3d0(
                            ((::FUN_007e4540_root *)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((sequence5))->FUN_005f5f80()))->v039((const NiFixedString&)(*(::BoneText *)(new ((void *)(block)) ::Vec3()))));
                    }
                }
            }
            NiPoint2S p;
            NiPoint2S pointB_;
            if (entry24)
                currentItem->list->FUN_005ae3d0(entry24);
        }
    }
    float blendA = 0.0f;
    ((BoneMenu*)DAT_011dada4)->bracket =
        reinterpret_cast<::FUN_007e5540_shell *>((((BoneMenu*)DAT_011dada4)))->GetTierFromPercent((int)((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb));
    switch (((BoneMenu*)DAT_011dada4)->bracket)
    {
    case 1:
        blendA = (25.0 - (((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb) - 75.0)) / 25.0;
        break;
    case 2:
        blendA =
            ((25.0 - (((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb) - 50.0)) + 25.0) / 50.0;
        break;
    case 3:
        blendA =
            ((25.0 - (((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb) - 25.0)) + 50.0) / 75.0;
        break;
    case 4:
        blendA = ((25.0 - ((BonePlayer*)DAT_011dea3c)->values.Get(((BoneMenu*)DAT_011dada4)->limb)) + 75.0) / 100.0;
        break;
    }
    BoneWound* wound9 = ((::BoneWound *)(reinterpret_cast<::FUN_007e5720_struct *>((((BoneMenu*)DAT_011dada4)))->FUN_007e5720()));
    if (wound9 && ((BoneMenu*)DAT_011dada4)->bracket)
    {
        BoneNode* node = wound9->list;
        while (node && !node->FUN_008256d0())
        {
            if (((void *)(reinterpret_cast<::LowProcess *>(((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->anim))->GetTarget())) == ((BoneMenu*)DAT_011dada4)->manager)
            {
                reinterpret_cast<::NiControllerManager *>((((BoneMenu*)DAT_011dada4)->manager))->ActivateControllerSequence((::NiControllerSequence *)((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->anim), 0, true, 1.0f, 0.0f, (::NiControllerSequence *)(void *)(0));
            }
            reinterpret_cast<::AnimationSequence *>(((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->anim))->FUN_00a34ba0(0.0f, true);
            if (!cachedX || wound9->dirty)
            {
                reinterpret_cast<::fnv_00a328b0::SeqExt *>(((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))
                    ->anim))->FUN_00a328b0(reinterpret_cast<::FUN_00508100_shell *>(((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->anim))->FUN_00508100() * blendA, true);
                (*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->radius = reinterpret_cast<::FUN_00508100_shell *>(((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->anim))->FUN_00508100() * blendA;
            }
            else
                reinterpret_cast<::fnv_00a328b0::SeqExt *>(((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->anim))->FUN_00a328b0((*((::BoneEntry **)(new ((void *)(node)) ::Vec3())))->radius, true);
            node = ((::BoneNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        wound9->dirty = 0;
    }
    NiUpdateDataS update2(0.0f, true, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((host))->FUN_00a59c60((int)&(update2));
}

class GlobalObject_0044f440
{
  public:
};
extern GlobalObject_0044f440 g_011dae28;
extern GlobalObject_0044f440 g_011dadf0;
extern GlobalObject_0044f440 g_011dadfc;
extern GlobalObject_0044f440 g_011dae6c;

struct BipAVObject
{
};

struct BipRoot
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual BipAVObject* v039(const NiFixedString& arName);
};

struct BipPointer
{
};
extern BipPointer DAT_011dae5c;

// Looks up the "Bip01" node, calls two methods with global float values and arguments, then updates the current root.
// @fnv 0x007e4fe0
void __cdecl FUN_007e4fe0(float a, float b, float c)
{
    if (((::BipRoot *)(::FUN_00559450((int *)&(DAT_011dae5c)))))
    {
        reinterpret_cast<::FUN_004bc1f0_S *>((((::BipRoot *)(::FUN_00559450((int *)&(DAT_011dae5c))))
            ->v039(NiFixedString("Bip01"))))->FUN_004bc1f0(-*((float *)&(::FUN_00403e20((float *)&(g_011dae6c)))), *((float *)&(::FUN_00403e20((float *)&(g_011dadf0)))) - b, *((float *)&(::FUN_00403e20((float *)&(g_011dae28)))) - a);
        reinterpret_cast<::FUN_00440490_shell *>((((::BipRoot *)(::FUN_00559450((int *)&(DAT_011dae5c))))->v039(NiFixedString("Bip01"))))->FUN_00440490(*((float *)&(::FUN_00403e20((float *)&(g_011dadfc)))) * (double)c);
        NiUpdateDataS kData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::BipRoot *)(::FUN_00559450((int *)&(DAT_011dae5c))))))->FUN_00a59c60((int)&(kData));
    }
}

struct LimbPercentageMenu : SurgeryLimbMenu
{
    unsigned int modeC4;
    int GetLimbPercentage();
};
// Advances pain over elapsed time, plays threshold sounds, updates the player's value and hurt state, and refreshes the tile text.
// @fnv 0x007e28b0
void PainMenu::FUN_007e28b0()
{
    float result = reinterpret_cast<::SurgeryView *>(this)->UpdateWoundInteraction();
    float value = ScaleByConstant(speed);
    float z = pain;
    pain += (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::PainTimer *>(&::g_timeGlobal))))->FUN_00825c00() - last) / 1000.0 * 30.0;
    if (pain > 100.0)
        pain = 100.0f;
    unsigned int total = GetRandomNumberInRange(0, 5);
    if (total == 1)
    {
        if (z < 60.0 && pain > 60.0)
        {
            PainSound painSound;
            reinterpret_cast<::SoundPlaybackHandle *>(&(painSound))->operator=((const ::SoundPlaybackHandle &)((const ::PainSound &)(((::PainAudio *)(::FUN_00453a70()))->FUN_00ad7550(DAT_010776b8, 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(painSound))->FUN_00ad8830(false);
        }
        else if (z < 85.0 && pain > 85.0)
        {
            PainSound painSound;
            reinterpret_cast<::SoundPlaybackHandle *>(&(painSound))->operator=((const ::SoundPlaybackHandle &)((const ::PainSound &)(((::PainAudio *)(::FUN_00453a70()))->FUN_00ad7550(DAT_010776a8, 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(painSound))->FUN_00ad8830(false);
        }
        else if (z < 100.0 && pain == 100.0)
        {
            PainSound painSound;
            reinterpret_cast<::SoundPlaybackHandle *>(&(painSound))->operator=((const ::SoundPlaybackHandle &)((const ::PainSound &)(((::PainAudio *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01077698, 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(painSound))->FUN_00ad8830(false);
        }
    }
    last = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::PainTimer *>(&::g_timeGlobal))))->FUN_00825c00();
    reinterpret_cast<::FUN_0088b740_shell *>((g_thePlayer))->FUN_0088b740(valueId, float(reinterpret_cast<::LimbPercentageMenu *>(this)->GetLimbPercentage() - g_thePlayer->values.get(valueId)));
    if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::PainTimer *>(&::g_timeGlobal))))->FUN_00825c00() - lastHurt >
        LinearInterpolate(LinearInterpolate(100.0f, 500.0f, 0.0f, 100.0f, float(g_thePlayer->values.get(37))), 1000.0f,
                          100.0f, 0.0f, pain))
    {
        g_thePlayer->hurt(16, -1, 0);
        lastHurt = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::PainTimer *>(&::g_timeGlobal))))->FUN_00825c00();
    }
    char time[256];
    FUN_00406d00(time, 256, DAT_01077674, g_thePlayer->values.get(37));
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(FUN_00a01860(::DAT_0106ed18), (char *)(time), true);
}

// Computes a limb percentage from a mode and fraction, updates two UI tiles, and returns the integer percentage.
// @fnv 0x007e5590
int LimbPercentageMenu::GetLimbPercentage()
{
    float fraction = 1.0f - FUN_007e58e0();
    float percentage = 0.0f;
    switch (((LimbPercentageMenu*)DAT_011dada4)->modeC4)
    {
    case 4:
        percentage = LinearInterpolate(100.0f, 0.0f, 0.0f, 1.0f, fraction);
        break;
    case 3:
        percentage = LinearInterpolate(100.0f, 25.0f, 0.0f, 1.0f, fraction);
        break;
    case 2:
        percentage = LinearInterpolate(100.0f, 50.0f, 0.0f, 1.0f, fraction);
        break;
    case 1:
        percentage = LinearInterpolate(100.0f, 75.0f, 0.0f, 1.0f, fraction);
        break;
    case 0:
        percentage = 100.0f;
        break;
    }
    int result2 = (int)percentage;
    reinterpret_cast<::FUN_00a012d0_t *>((tile70))->FUN_00a012d0(FUN_00a01860("_Value"), result2 / 100.0, true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile4C))->FUN_00a01350(0xfc4, (char *)(ActorValue::GetActorValueName(avC0)), true);
    return result2;
}

struct Thing
{
    int GetIndex(int value);
};
// Projects wound nodes to screen, tests the cursor against them, updates hit/idle sounds and wound radii, and returns 0 when hit or 100 otherwise.
// @fnv 0x007e2de0
float SurgeryView::UpdateWoundInteraction()
{
    WoundData* p = ((::WoundData *)(reinterpret_cast<::FUN_007e5720_struct *>(this)->FUN_007e5720()));
    if (!((ProjectionPtr&)g_011dadb4) || !p)
        return 0.0f;
    reinterpret_cast<::ItemChangeList *>((p->list))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(((int (&)(WoundEntry *, WoundEntry *))::CompareProjectedListsToCursor)));
    bool h = false;
    if (p->list->FUN_005ae380() > 1)
    {
        unsigned a = p->list->FUN_005ae380() * 2;
        ScreenPoint s;
        s = mouse;
        s.x /= ::InterfaceManager::UpdateInterfaceState();
        s.y /= FUN_00715da0();
        double f[2];
        WoundNode* i = p->list;
        while (i && !i->FUN_008256d0())
        {
            ScreenPoint q;
            ScreenPoint ba;
            reinterpret_cast<::ScreenCamera *>((((Projection*)((ProjectionPtr&)g_011dadb4))))->ProjectToScreen((*(const ::NiPoint3 *)(((void *)(::FUN_0045bb80((int)(((HitValue*)*((void **)(new ((void *)((*((::WoundEntry **)(new ((void *)(i)) ::Vec3())))->bHitDetected)) ::Vec3()))))))))),
                                  (*(float *)(&q.x)), (*(float *)(&q.y)), 0.00001f);
            reinterpret_cast<::ScreenCamera *>((((Projection*)((ProjectionPtr&)g_011dadb4))))->ProjectToScreen(
                    (*(const ::NiPoint3 *)(((void *)(::FUN_0045bb80((int)(((HitValue*)*((void **)(new ((void *)(((::HitRef *)(reinterpret_cast<::Callees *>(((*((::WoundEntry **)(new ((void *)(i)) ::Vec3())))->bHitDetected))->FUN_00726070())))) ::Vec3()))))))))),
                    (*(float *)(&ba.x)), (*(float *)(&ba.y)), 0.00001f);
            q.y = 1.0f - q.y;
            ba.y = 1.0f - ba.y;
            double b[24][2];
            b[0][0] = q.x;
            b[0][1] = q.y;
            b[1][0] = ba.x;
            b[1][1] = ba.y;
            f[0] = s.x;
            f[1] = s.y;
            if (((::WoundNode *)(reinterpret_cast<::Callees *>((i))->FUN_00726070())))
            {
                ScreenPoint k;
                ScreenPoint l;
                reinterpret_cast<::ScreenCamera *>((((Projection*)((ProjectionPtr&)g_011dadb4))))->ProjectToScreen((*(const ::NiPoint3 *)(((void *)(::FUN_0045bb80((int)(((HitValue*)*((void **)(new ((void *)((*((::WoundEntry **)(new ((void *)(((::WoundNode *)(reinterpret_cast<::Callees *>((i))->FUN_00726070())))) ::Vec3())))->bHitDetected)) ::Vec3()))))))))),
                                      (*(float *)(&k.x)), (*(float *)(&k.y)), 0.00001f);
                reinterpret_cast<::ScreenCamera *>((((Projection*)((ProjectionPtr&)g_011dadb4))))->ProjectToScreen(
                        (*(const ::NiPoint3 *)(((void *)(::FUN_0045bb80((int)(((HitValue*)*((void **)(new ((void *)(((::HitRef *)(reinterpret_cast<::Callees *>(((*((::WoundEntry **)(new ((void *)(((::WoundNode *)(reinterpret_cast<::Callees *>((i))->FUN_00726070())))) ::Vec3())))->bHitDetected))->FUN_00726070())))) ::Vec3()))))))))),
                        (*(float *)(&l.x)), (*(float *)(&l.y)), 0.00001f);
                k.y = 1.0f - k.y;
                l.y = 1.0f - l.y;
                b[2][0] = k.x;
                b[2][1] = k.y;
                b[3][0] = l.x;
                b[3][1] = l.y;
                if (PointInPolygon(b, 4, f))
                    h = true;
            }
            i = ((::WoundNode *)(reinterpret_cast<::Callees *>((i))->FUN_00726070()));
        }
        if (h && hitTime == 0)
            hitTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00();
        if (h)
        {
            if (!reinterpret_cast<::SoundPlaybackHandle *>(&(activeSound))->IsPlaying())
                reinterpret_cast<::FUN_00ad8830_shell *>(&(activeSound))->FUN_00ad8830(false);
            if (hitTime > 0)
            {
                if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00() - hitTime >
                    (unsigned)LinearInterpolate(500.0f, 0.0f, 0.0f, 100.0f,
                                                (float)((PlayerView*)_g_thePlayer)->values.Get(37)))
                {
                    WoundAnim* cf[2];
                    cf[0] = (*((::WoundEntry **)(new ((void *)(p->list)) ::Vec3())))->anim;
                    cf[1] = (*((::WoundEntry **)(new ((void *)(((::WoundNode *)(reinterpret_cast<::Callees *>((p->list))->FUN_00726070())))) ::Vec3())))->anim;
                    WoundEntry* j[2];
                    j[0] = *((::WoundEntry **)(new ((void *)(p->list)) ::Vec3()));
                    j[1] = *((::WoundEntry **)(new ((void *)(((::WoundNode *)(reinterpret_cast<::Callees *>((p->list))->FUN_00726070())))) ::Vec3()));
                    float eb[2];
                    eb[0] = reinterpret_cast<::BSFaceGenMorphData *>((cf[0]))->FUN_00508120();
                    eb[1] = reinterpret_cast<::BSFaceGenMorphData *>((cf[1]))->FUN_00508120();
                    if (lastTime == 0)
                        lastTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00();
                    else
                    {
                        eb[0] -= FUN_00408840(reinterpret_cast<::FUN_00508100_shell *>((cf[0]))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((cf[0]))->FUN_00759450()) * 0.014999999664723873 *
                                 ((reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00() - lastTime) / 33.0);
                        eb[1] -= FUN_00408840(reinterpret_cast<::FUN_00508100_shell *>((cf[1]))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((cf[1]))->FUN_00759450()) * 0.006000000052154064 *
                                 ((reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00() - lastTime) / 33.0);
                    }
                    for (int c = 0; c < 2; c++)
                    {
                        reinterpret_cast<::fnv_00a328b0::SeqExt *>((cf[c]))->FUN_00a328b0(eb[c], true);
                        j[c]->radius = eb[c];
                    }
                    UpdateArgs e(0.0f, true, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((((SceneNode*)((SurgeryView*)DAT_011dada4)->nodes[reinterpret_cast<::Thing *>(this)->GetIndex(p->index)])))->FUN_00a59c60((int)&(e));
                    if (((SurgeryView*)DAT_011dada4)->enabled && (eb[0] + eb[1]) / 2.0 < 0.10000000149011612)
                        reinterpret_cast<::SurgeryDecals *>(this)->PlaceSurgeryDecal((*(float *)&(const ::ScreenPoint &)(s)), true, {});
                }
            }
        }
        else
        {
            reinterpret_cast<::SurgeryDecals *>(this)->PlaceSurgeryDecal((*(float *)&(const ::ScreenPoint &)(s)), false, {});
            if (!reinterpret_cast<::SoundPlaybackHandle *>(&(idleSound))->IsPlaying())
                reinterpret_cast<::FUN_00ad8830_shell *>(&(idleSound))->FUN_00ad8830(false);
            if (reinterpret_cast<::SoundPlaybackHandle *>(&(activeSound))->IsPlaying())
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(activeSound))->FUN_00ad88f0();
            hitTime = 0;
        }
    }
    lastTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00();
    if (true)
    {
        float l, e, j;
        ComputeInjuryEffectScalars(&l, &e, &j, reinterpret_cast<::TileListBoxCalls *>((((::SurgeryView::ValueOwner *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(g_011dad9c) / 100.0f, amount / 100.0f,
                                   ((PlayerView*)_g_thePlayer)->values.Get(37));
        ScreenPoint c;
        c.x = ApplyNoise((float)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00() * 0.0002500000118743628));
        c.y = ApplyNoise((float)((reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((ClockValue&)(*reinterpret_cast<::TimeGlobalS *>(&::g_timeGlobal)))))->FUN_00825c00() + 12345) * 0.0002500000118743628));
        Position3 k = (*(::Position3 *)&(reinterpret_cast<::NiAVObject *>((((SceneNode*)nodes[reinterpret_cast<::Thing *>(this)->GetIndex(p->index)])))->FUN_0043c490()));
        reinterpret_cast<::FUN_004bc1f0_S *>((((SceneNode*)nodes[reinterpret_cast<::Thing *>(this)->GetIndex(p->index)])))->FUN_004bc1f0(c.x, c.y, 1.0f);
        UpdateArgs ba(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((SceneNode*)nodes[reinterpret_cast<::Thing *>(this)->GetIndex(p->index)])))->FUN_00a59c60((int)&(ba));
    }
    return h ? 0.0f : 100.0f;
}
// Handles surgery menu button presses to apply stimpak or morphine, cycle the selected limb, or heal the current limb.
// @fnv 0x007e1b10
void EventMenu::OnButtonClick(int button, int arg)
{
    static int stimpak = FUN_00a00940("_StimpacCount", -1);
    static int morphine = FUN_00a00940("_MorphineCount", -1);
    int event = reinterpret_cast<::FUN_00720010_shell *>(this)->FUN_00720010(button);
    {
        float benefit;
        {
            bool has;
            {
                float cost;
                {
                    float healing;
                    {
                        EventWounds* wounds;
                        switch (event)
                        {
                        case 1:
                            CloseSurgeryMenu();
                            break;
                        case 4:
                            if (((EventMenu*)DAT_011dada4)->entry &&
                                ((int)(reinterpret_cast<::Callees *>((((EventMenu*)DAT_011dada4)->entry))->FUN_00726070())) > 0)
                            {
                                reinterpret_cast<::FUN_00a012d0_t *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->FUN_00a012d0(stimpak, reinterpret_cast<::TileListBoxCalls *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(stimpak) - 1.0,
                                                             true);
                                reinterpret_cast<::FUN_0088c650_shell *>((((EventPlayer*)_g_thePlayer)))->FUN_0088c650(
                                        (::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((EventMenu*)DAT_011dada4)->entry))->GetName()))),
                                        ((int)(reinterpret_cast<::Callees *>((((EventMenu*)DAT_011dada4)->entry))->FUN_00726070())),
                                        (::ExtraDataList *)(void *)(((::EventExtraNode *)(::FUN_00559450((int *)(((EventMenu*)DAT_011dada4)->entry))))
                                            ? *(((void **)(new ((void *)(((::EventExtraNode *)(::FUN_00559450((int *)(((EventMenu*)DAT_011dada4)->entry)))))) ::Vec3())))
                                            : 0),
                                        false, false, true);
                            }
                            reinterpret_cast<::DirectionAnimator *>(this)->SetDirection(3);
                            break;
                        case 5:
                            if (reinterpret_cast<::TileListBoxCalls *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(morphine) > 0.0)
                            {
                                EventEntry* item = ((::EventEntry *)(reinterpret_cast<::fnv_00576260::FUN_00576260_shell *>((((EventPlayer*)_g_thePlayer)))->FUN_00576260((::fnv_00576260::TESBoundObject *)(::EventForm *)(((::EventForm *)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(4))))), 0)));
                                reinterpret_cast<::FUN_00a012d0_t *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->FUN_00a012d0(morphine, reinterpret_cast<::TileListBoxCalls *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(morphine) - 1.0,
                                                             true);
                                reinterpret_cast<::FUN_0088c650_shell *>((((EventPlayer*)_g_thePlayer)))->FUN_0088c650((::TESBoundObject *)(void *)(((::EventForm *)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(4))))), ((int)(reinterpret_cast<::Callees *>((item))->FUN_00726070())),
                                                   (::ExtraDataList *)(void *)(((::EventExtraNode *)(::FUN_00559450((int *)(item)))) ? *(((void **)(new ((void *)(((::EventExtraNode *)(::FUN_00559450((int *)(item)))))) ::Vec3()))) : 0),
                                                   false, false, true);
                                delete item;
                                amount -= 25.0;
                                if (reinterpret_cast<::TileListBoxCalls *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(DAT_011dad9c) >= 25.0)
                                    reinterpret_cast<::FUN_00a012d0_t *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->FUN_00a012d0(
                                        DAT_011dad9c, reinterpret_cast<::TileListBoxCalls *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(DAT_011dad9c) - 25.0, true);
                                else
                                    reinterpret_cast<::Tile *>((((::EventTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(DAT_011dad9c, 0);
                            }
                            reinterpret_cast<::DirectionAnimator *>(this)->SetDirection(2);
                            break;
                        case 14: {
                            int iOldLimb = limb;
                            switch (limb)
                            {
                            case 26:
                                limb = 27;
                                break;
                            case 27:
                                limb = 28;
                                break;
                            case 29:
                                limb = 30;
                                break;
                            case 28:
                                limb = 29;
                                break;
                            case 30:
                                limb = 25;
                                break;
                            case 25:
                            case -1:
                                limb = 26;
                                break;
                            }
                            amount = ScaleLimbWoundPercent(((EventPlayer*)_g_thePlayer)->values.Damage(limb));
                            reinterpret_cast<::FUN_00a012d0_t *>((gauge))->FUN_00a012d0(FUN_00a01860("_Value"),
                                                ((EventPlayer*)_g_thePlayer)->values.Damage(limb) / 100.0, true);
                            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((label))->FUN_00a01350(0xfc4, (char *)(ActorValue::GetActorValueName((ActorValue::Index)limb)), true);
                            reinterpret_cast<::fnv_007e5ee0::HostF *>(this)->FUN_007e5ee0(iOldLimb, limb);
                            ::UpdateBoneWounds((::BoneHost *)(void *)(((void *)(::FUN_00559450((int *)&(((EventMenu*)DAT_011dada4)->nodes[reinterpret_cast<::Thing *>(this)->GetIndex(limb)]))))));
                            break;
                        }
                        case 15: {
                            int old2 = limb;
                            switch (limb)
                            {
                            case 26:
                                limb = 25;
                                break;
                            case 27:
                                limb = 26;
                                break;
                            case 29:
                                limb = 28;
                                break;
                            case 28:
                                limb = 27;
                                break;
                            case 30:
                                limb = 29;
                                break;
                            case 25:
                            case -1:
                                limb = 30;
                                break;
                            }
                            amount = ScaleLimbWoundPercent(((EventPlayer*)_g_thePlayer)->values.Damage(limb));
                            reinterpret_cast<::FUN_00a012d0_t *>((gauge))->FUN_00a012d0(FUN_00a01860("_Value"),
                                                ((EventPlayer*)_g_thePlayer)->values.Damage(limb) / 100.0, true);
                            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((label))->FUN_00a01350(0xfc4, (char *)(ActorValue::GetActorValueName((ActorValue::Index)limb)), true);
                            reinterpret_cast<::fnv_007e5ee0::HostF *>(this)->FUN_007e5ee0(old2, limb);
                            ::UpdateBoneWounds((::BoneHost *)(void *)(((void *)(::FUN_00559450((int *)&(((EventMenu*)DAT_011dada4)->nodes[reinterpret_cast<::Thing *>(this)->GetIndex(limb)]))))));
                            break;
                        }
                        case 2: {
                            has = reinterpret_cast<::MagicTarget *>(&(((EventPlayer*)_g_thePlayer)->target))->HasSpell((::MagicItem *)(::EventMagic *)(((::EventForm *)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(4))))), true);

                            ComputeMedicineHealing(benefit, cost, ((EventPlayer*)_g_thePlayer)->values.Current(37), has,
                                                   ((EventPlayer*)_g_thePlayer)->values.Damage(limb));
                            healing = FUN_0040ebd0(reinterpret_cast<::SurgeryLimbMenu *>(this)->FUN_007e58e0() * 100.0 + benefit, 100.0f);
                            reinterpret_cast<::WoundUpdater *>(this)->UpdateWounds(1.0 - healing / 100.0);
                            reinterpret_cast<::FUN_0088b740_shell *>((((EventPlayer*)_g_thePlayer)))->FUN_0088b740(limb, (float)(reinterpret_cast<::LimbPercentageMenu *>(this)->GetLimbPercentage() -
                                                             ((EventPlayer*)_g_thePlayer)->values.Current(limb)));
                            ((EventPlayer*)_g_thePlayer)->Mod(16, -cost, 0);
                            wounds = ((::EventWounds *)(reinterpret_cast<::FUN_007e5720_struct *>((((EventMenu*)DAT_011dada4)))->FUN_007e5720()));
                            wounds->changed = true;
                            break;
                        }
                        }
                    }
                }
            }
        }
    }
}

// Maps specific input values to a small index range, returning 0 for unknown inputs.
// @fnv 0x007e5e30
int Thing::GetIndex(int value)
{
    switch (value)
    {
    case 0x1a:
        return 0;
    case 0x1b:
        return 1;
    case 0x1d:
        return 2;
    case 0x1c:
        return 3;
    case 0x1e:
        return 4;
    case 0x19:
        return 5;
    case -1:
        return 6;
    default:
        break;
    }
    return 0;
}
