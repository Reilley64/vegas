
// src/fallout_shared/bipedanim_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bipedanim.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/B4AEE60Owner.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSXFlags.h"
#include "fnv/decl/BipedAnimHelper.h"
#include "fnv/decl/BipedWeaponRemoval.h"
#include "fnv/decl/C4AEDE0Queue.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004700d0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004aaef0_shell.h"
#include "fnv/decl/FUN_004aaf10_shell.h"
#include "fnv/decl/FUN_004aaff0_S.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004ad010_shell.h"
#include "fnv/decl/FUN_004add70_shell.h"
#include "fnv/decl/FUN_004adda0_shell.h"
#include "fnv/decl/FUN_004adde0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004af860_shell.h"
#include "fnv/decl/FUN_004af880_shell.h"
#include "fnv/decl/FUN_004afa20_shell.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00572160_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_00950b30_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5be90_shell.h"
#include "fnv/decl/FUN_00a62660_cls.h"
#include "fnv/decl/FaceLoader.h"
#include "fnv/decl/Fake_FUN_004a2020.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/W_0043b4f0.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00567050__FUN_00567050_shell.h"
#include "fnv/decl/fnv_00571760__Actor.h"
#include "fnv/decl/fnv_006148f0__FUN_006148f0_shell.h"
#include "fnv/decl/fnv_006149b0__RaceTexture.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008b0b00__FUN_008b0b00_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00441000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ab000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00572000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e4000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "bipedanim_decls.h"

struct NiShader
{
};
struct Holder
{
    bool FUN_00a5ba40(NiTexture* pkTex);
    bool FUN_00a5bc40(const NiFixedString& kName, NiTexture* pkTex);
};
// @fnv 0x00a5bc40
bool Holder::FUN_00a5bc40(const NiFixedString& kName, NiTexture* pkTex)
{
    if ((int)kName.data == (*reinterpret_cast<int *>(&::DAT_0109b220)))
        return false;
    if (!pkTex)
        return false;
    if ((*(const ::NiFixedString *)&(reinterpret_cast<::FUN_00a62660_cls *>((void *)(((NiShader*)pkTex)))->FUN_00a62660())).data == (const char*)(*reinterpret_cast<int *>(&::DAT_0109b220)))
    {
        ::AssignFixedString((char *)(((NiAVObject*)pkTex)), (int)&(kName), {});
    }
    else
    {
        if (kName.data != (*(const ::NiFixedString *)&(reinterpret_cast<::FUN_00a62660_cls *>((void *)(((NiShader*)pkTex)))->FUN_00a62660())).data)
            return false;
    }
    return FUN_00a5ba40(pkTex);
}

struct FUN_00b553d0_PropertyLayout
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    NiPoint3 value;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int count;
};

struct FUN_00b553d0_NodeLayout
{
    unsigned int unk00;
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
    NiAVObject** children;
    unsigned short unkA4;
    unsigned short childCount;
};

// @fnv 0x00b553d0
void __cdecl FUN_00b553d0(NiGeometry* pObject, NiPoint3* pValue)
{
    if (pObject == 0)
        return;

    if (pObject->IsGeometry() != 0)
    {
        NiProperty* pFirst = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pObject))->FUN_00a59d30(2)));
        NiProperty* pSecond = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pObject))->FUN_00a59d30(3)));

        if (pFirst != 0 && pSecond != 0)
        {
            FUN_00b553d0_PropertyLayout* pFirstLayout = (FUN_00b553d0_PropertyLayout*)pFirst;
            FUN_00b553d0_PropertyLayout* pSecondLayout = (FUN_00b553d0_PropertyLayout*)pSecond;

            if ((pSecondLayout->unk20 & 0x20000000u) <= 0)
                return;

            pFirstLayout->value = *pValue;
            ++pFirstLayout->count;
        }
        return;
    }

    NiNode* pNode = pObject->IsSceneNode();
    if (pNode == 0)
        return;

    FUN_00b553d0_NodeLayout* pNodeLayout = (FUN_00b553d0_NodeLayout*)pNode;

    unsigned int count = pNodeLayout->childCount;
    for (unsigned int i = 0; i < count; ++i)
    {
        NiAVObject* pChild = pNodeLayout->children[i];
        if (pChild != 0)
            FUN_00b553d0((NiGeometry*)pChild, pValue);
    }
}

struct NiStub10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class NiController
{
  public:
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual NiStub10* GetTarget();
};

struct SceneNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    SceneNode* m_parent;
    NiController* m_controller;
    SceneNode* GetParent() const
    {
        return m_parent;
    }
};

class NiGlobalStringTable
{
  public:
    static char* AddString(const char* s);
};

struct BackpackName
{
    char* m_data;
    BackpackName(const char* s)
    {
        m_data = NiGlobalStringTable::AddString(s);
    }
    ~BackpackName();
};

struct AttachInfo
{
    void* m_data;
};

void FUN_00c88a40(void* a1, AttachInfo a2, SceneNode* obj, SceneNode* parent, bool a4);

static __forceinline SceneNode* FindAttachParent(SceneNode* obj, SceneNode* root)
{
    SceneNode* p = obj ? obj->GetParent() : 0;
    while (p)
    {
        NiController* c = p->m_controller;
        if (c && (!c->GetTarget() || p->m_controller->GetTarget()->unk10 != 0))
            break;
        if (p == root)
            break;
        p = p->GetParent();
    }
    if (p == root)
        return 0;
    return p;
}

// @fnv 0x00c89050
void __stdcall FUN_00c89050(void* a1, AttachInfo a2, SceneNode* root, bool a4)
{
    SceneNode* obj = ((::SceneNode *)(::FUN_00c4b310((::ObjQ *)(root), "Weapon", 0)));
    SceneNode* parent = FindAttachParent(obj, root);
    if (obj && parent)
        FUN_00c88a40(a1, a2, obj, parent, a4);

    static BackpackName kBackpack("Backpack");
    obj = ((::SceneNode *)(::FUN_00c4b470((::FUN_00c4b470_owner *)(root), (void **)(::BackpackName *)(&kBackpack), 0)));
    parent = FindAttachParent(obj, root);
    if (obj && parent)
        FUN_00c88a40(a1, a2, obj, parent, a4);
}
