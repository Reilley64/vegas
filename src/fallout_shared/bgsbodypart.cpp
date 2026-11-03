// fallout_shared/bgsbodypart.cpp: BGSBodyPart, BodyPartInfo, BGSTextureModel, SomeClass (15 functions)

#include <new>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00488f50_cls.h"
#include "fnv/decl/FUN_0051b950_shell.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_005e3fe0_class.h"
#include "fnv/decl/FUN_00994ef0_Class.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e4000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011f4000.h"
#include "bgsbodypart_decls.h"

// @fnv 0x005e3a00
void BodyPartInfo::Initialize()
{
    m_ucPartID = 5;
    m_fDamageMultiplier = 1.0f;
    m_cActorValue = -1;
    m_ucHealthPercent = 100;
    m_ucHitChance = 0;
    m_ucLimbReplacementType = 0;
    m_pExplosion = 0;
    m_pDebrisObject = 0;
    m_fExplosionChance = 0.0f;
    m_fDebrisScale = 1.0f;
    m_fValue4 = 1.0f;
    m_ucSeverable = 0;
    m_pRelatedObject1 = 0;
    m_pRelatedObject2 = 0;
    m_fValue3 = 1.0f;
    m_kPoint1 = ::NiPoint3::ZERO;
    m_kPoint2 = ::NiPoint3::ZERO;
    m_pRelatedObject3 = 0;
    m_pRelatedObject4 = 0;
    m_ucByte1 = 0;
    m_ucByte2 = 0;
}

// Queues the model and each present Data sub-object's queueable for loading at the given priority.
// @fnv 0x005e45e0
void BGSBodyPart::QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* queuedFile)
{
    if (m_kModel.GetModelLength())
        reinterpret_cast<::QueueModelHolder *>((g_modelLoader))->FUN_00443d30((int)(&m_kModel), priority, (int)(queuedFile), true, true, false, false);
    if (Data.m_pExplosion)
        ((Queueable18*)((char*)Data.m_pExplosion + 0x18))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pDebrisObject)
        ((Queueable18*)((char*)Data.m_pDebrisObject + 0x64))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject1)
        ((Queueable18*)((char*)Data.m_pRelatedObject1 + 0x18))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject2)
        ((Queueable18*)((char*)Data.m_pRelatedObject2 + 0x64))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject3)
        ((Queueable18*)((char*)Data.m_pRelatedObject3 + 0x18))->QueueResourceLoad(priority, queuedFile);
    if (Data.m_pRelatedObject4)
        ((Queueable18*)((char*)Data.m_pRelatedObject4 + 0x18))->QueueResourceLoad(priority, queuedFile);
}

// @fnv 0x005e3d80
void BGSBodyPart::InitItem(TESForm* form)
{
    if (!form || form->GetInitialized())
        return;
    unsigned int formID = (unsigned int)((DialogueItem*)this)->SelectDefaultResponseList();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        Data.m_pDebrisObject = dynamic_cast<BGSExplosion*>(::FUN_004839c0(formID));
    }
    formID = (unsigned int)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)this)))->GetBaseTexture()));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        Data.m_pExplosion = dynamic_cast<BGSDebris*>(::FUN_004839c0(formID));
    }
    formID = (unsigned int)((EffectSetting*)this)->GetCastSound();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        Data.m_pRelatedObject2 = dynamic_cast<BGSExplosion*>(::FUN_004839c0(formID));
    }
    formID = (unsigned int)((::TESEffectShader *)(reinterpret_cast<::TESPackage *>((((EffectSetting*)this)))->GetRefCount()));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        Data.m_pRelatedObject1 = dynamic_cast<BGSDebris*>(::FUN_004839c0(formID));
    }
    formID = (unsigned int)((::Tile *)(reinterpret_cast<::MagicProjectile *>((((InterfaceManager*)this)))->FUN_004fd400()));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        ((InterfaceManager*)this)
            ->FUN_00500a20((Tile*)dynamic_cast<BGSImpactDataSet*>(::FUN_004839c0(formID)));
    }
    formID = reinterpret_cast<::FUN_005e3fc0_shell *>(this)->Get();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        reinterpret_cast<::FUN_00994ef0_Class *>(this)->Set((int)(dynamic_cast<BGSImpactDataSet*>(::FUN_004839c0(formID))));
    }
}

// Reads BPTN/PNMA/BPNN/BPNT/BPNI/BPND/NAM1/NAM2-5 chunks from a TESFile into the body part's names, model, data and debris scale, defaulting zero scales to 0.1.
// @fnv 0x005e4100
bool BGSBodyPart::Load(TESFile* file)
{
    void* pChunkBuffer;
    {
        bool badScale;
        if (!file)
            return false;
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x4e545042)
        {
            char* partName = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(partName), 0);
            reinterpret_cast<::TextString *>(&(m_kPartName))->FUN_004037f0(partName, 0);
            if (!file->NextChunk())
                return false;
        }
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x4d414e50)
        {
            TESModel::LoadModelData((TESModel*)&m_kRagdollModel, file);
            if (!file->NextChunk())
                return false;
        }
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x4e4e5042)
            return false;
        pChunkBuffer = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkBuffer), 0);
        reinterpret_cast<::TextString *>(&(NodeName))->FUN_004037f0((char*)pChunkBuffer, 0);
        if (!file->NextChunk())
            return false;
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x544e5042)
            return false;
        pChunkBuffer = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkBuffer), 0);
        reinterpret_cast<::TextString *>(&(TargetName))->FUN_004037f0((char*)pChunkBuffer, 0);
        if (!file->NextChunk())
            return false;
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x494e5042)
        {
            pChunkBuffer = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkBuffer), 0);
            reinterpret_cast<::TextString *>(&(m_kVATSNodeName))->FUN_004037f0((char*)pChunkBuffer, 0);
            if (!file->NextChunk())
                return false;
        }
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x444e5042)
            return false;
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_005e3fe0_class *>(&(Data))->SwapEndianFields();
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), 0x54);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_005e3fe0_class *>(&(Data))->SwapEndianFields();
        badScale = false;
        if (Data.m_fValue4 == 0.0)
        {
            Data.m_fValue4 = 0.1f;
            badScale = true;
        }
        if (Data.m_fValue3 == 0.0)
        {
            Data.m_fValue3 = 0.1f;
            badScale = true;
        }
        if (Data.m_fDebrisScale == 0.0)
        {
            Data.m_fDebrisScale = 0.1f;
            badScale = true;
        }
        if (badScale)
            ::FUN_005b5e40();
        if (!file->NextChunk())
            return false;
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x314d414e)
            return false;
        if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
        {
            char* modelName = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelName), 0);
            m_kModel.vfn_18(modelName);
        }
        if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 3)
        {
            if (!file->NextChunk() || ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x324d414e)
                return reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 2;
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
            {
                char* modelName2 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelName2), 0);
            }
            if (!file->NextChunk() || ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x334d414e)
                return reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 2;
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
            {
                char* modelName3 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelName3), 0);
            }
        }
        if (!file->NextChunk() || ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x344d414e)
            return reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 2;
        if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
        {
            char* goreName = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(goreName), 0);
            reinterpret_cast<::TextString *>(&(m_kGoreName))->FUN_004037f0(goreName, 0);
        }
        if (!file->NextChunk() || ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x354d414e)
            return true;
        if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
            ::FUN_004893e0(&m_kModel, file);
        return true;
    }
}

extern int DAT_0104540c;

// @fnv 0x005e3be0
TESModel* FUN_005e3be0(TESModel* pThis)
{
    new ((void *)(pThis)) ::FUN_00488f50_cls();
    *(int**)pThis = &DAT_0104540c;
    return pThis;
}


// @fnv 0x005e3c00
void* FUN_005e3c00(char* pObject)
{
    new ((void *)(pObject + 0x2c)) ::Vec3();
    new ((void *)(pObject + 0x38)) ::Vec3();
    return pObject;
}

struct FUN_005e3d20_shell : public BGSBodyPart
{
    void FUN_005e3d20();
};
// Zeroes the 0x54-byte Data block, calls Data.Initialize(), then FUN_005e3d20().
// @fnv 0x005e3af0
BGSBodyPart::BGSBodyPart()
{
    memset(&Data, 0, 0x54);
    Data.Initialize();
    reinterpret_cast<::FUN_005e3d20_shell *>(this)->FUN_005e3d20();
}

struct VCall0
{
    virtual void v0();
};

// Calls v0 on two VCall0 objects referenced by the body part's fields.
// @fnv 0x005e3d20
void FUN_005e3d20_shell::FUN_005e3d20()
{
    reinterpret_cast<VCall0*>(&m_kModel)->v0();
    reinterpret_cast<VCall0*>(&m_kRagdollModel)->v0();
}

struct BGSTextureModel
{
    virtual ~BGSTextureModel();
    void* FUN_005e3c30(unsigned int);
};
// Runs the BGSTextureModel destructor and, when bit 0 of flags is set, frees the object with operator delete; returns this.
// @fnv 0x005e3c30
void* BGSTextureModel::FUN_005e3c30(unsigned int flags)
{
    reinterpret_cast<::FUN_0051b950_shell *>((this))->FUN_0051b950();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Inner005e3d50
{
    virtual void F0()
    {}
    virtual void F1()
    {}
    char pad[20];
};
struct Outer005e3d50
{
    char pad0[0x2c];
    Inner005e3d50 a;
    Inner005e3d50 b;
    void FUN_005e3d50();
};
// Calls the second virtual method on both inner objects a and b.
// @fnv 0x005e3d50
void Outer005e3d50::FUN_005e3d50()
{
    a.F1();
    b.F1();
}

struct FUN_005e3c60_psa
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ~FUN_005e3c60_psa();
};

class FUN_005e3c60_cls
{
  public:
    virtual ~FUN_005e3c60_cls();

    BSStringT<char> NodeName;
    BSStringT<char> TargetName;
    BSStringT<char> m_kVATSNodeName;
    BSStringT<char> m_kPartName;
    BSStringT<char> m_kGoreName;
    TESModel m_kModel;
    FUN_005e3c60_psa m_kRagdollModel;
};

// @fnv 0x005e3c60
FUN_005e3c60_cls::~FUN_005e3c60_cls()
{
    reinterpret_cast<::Outer005e3d50 *>(this)->FUN_005e3d50();
}

class PartList;
class PartNode
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual PartList* GetChildren();
    virtual void vfn10();
    virtual void vfn14();
    virtual void* GetTarget();
};

class PartList
{
  public:
    unsigned int CountItems();
};

class PartSink
{
  public:
    void AddEntry(unsigned int, int);
};


// Recursively walks a PartNode tree; for leaf nodes with a target, looks up a PartSink and adds two entries keyed by a1 and a1+0xc8.
// @fnv 0x005e4730
void AddNodeEntries(unsigned int a1, PartNode* pNode)
{
    if (pNode == 0)
    {
        return;
    }
    if (pNode->GetChildren())
    {
        PartList* list3 = pNode->GetChildren();
        unsigned int i;
        for (i = 0; i < list3->CountItems(); i++)
        {
            AddNodeEntries(a1, ((::PartNode *)(reinterpret_cast<::NiNode *>((list3))->GetAt(i))));
        }
    }
    else if (pNode->GetTarget())
    {
        void* target = pNode->GetTarget();
        void* base = ((void *)(::fnv_0043fad0::FUN_0043fad0((const char *)(target))));
        PartSink* sink2 = (PartSink*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f49d8))), (::NiObject *)(base))));
        if (sink2)
        {
            sink2->AddEntry((unsigned short)a1, 0);
            sink2->AddEntry(a1 + 0xc8, 1);
        }
    }
}

struct Entry_005e4810
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned short unk02;
};

struct SomeClass
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
    unsigned int unk34;
    Entry_005e4810* unk38;
    unsigned char unk3c;

    void SetEntryStateByKey(unsigned short param1, unsigned char param2);
};

// Clears unk3c, then for each of unk34 entries matching param1 sets unk00 to param2 and ORs every entry's unk00 into unk3c.
// @fnv 0x005e4810
void SomeClass::SetEntryStateByKey(unsigned short ausKey, unsigned char aucState)
{
    this->unk3c = 0;
    for (unsigned int i = 0; i < this->unk34; i++)
    {
        if (this->unk38[i].unk02 == ausKey)
        {
            this->unk38[i].unk00 = aucState;
        }
        this->unk3c = this->unk3c | this->unk38[i].unk00;
    }
}

namespace fnv_005e4890 {
class TreeNode;
class NodeList
{
  public:
    unsigned int FUN_0043b480();
};
class KeyName
{
  public:
};
class TreeNode
{
  public:
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual NodeList* GetChildren();
    virtual void unused4();
    virtual void unused5();
    virtual KeyName* GetKeyName();
};
class FoundResult
{
  public:
};
// Recurses into a tree node's children; for each leaf with a key name, looks up a result by name and applies key and key+200 to it.
// @fnv 0x005e4890
void __cdecl ApplyKeyToLeafNodes(unsigned int key, TreeNode* node)
{
    if (node == 0)
        return;
    if (node->GetChildren())
    {
        NodeList* children = node->GetChildren();
        for (unsigned int i = 0; i < children->FUN_0043b480(); ++i)
        {
            ApplyKeyToLeafNodes(key, ((::fnv_005e4890::TreeNode *)(reinterpret_cast<::NiNode *>((children))->GetAt(i))));
        }
    }
    else if (node->GetKeyName())
    {
        KeyName* pKeyName = node->GetKeyName();
        const char* pcText = ::fnv_0043fad0::FUN_0043fad0((const char *)(pKeyName));
        FoundResult* result = ((::fnv_005e4890::FoundResult *)(::FUN_00653270((const ::NiRTTI *)((*reinterpret_cast<char (*)[]>(&::g_011f49d8))), (::NiObject *)(pcText))));
        if (result != 0)
        {
            reinterpret_cast<::SomeClass *>((result))->SetEntryStateByKey(static_cast<unsigned short>(key), 1);
            reinterpret_cast<::SomeClass *>((result))->SetEntryStateByKey(key + 200, 0);
        }
    }
}
}  // namespace fnv_005e4890

void __cdecl FUN_005e3c60(void*);

struct FUN_005e50c0_shell
{
    virtual ~FUN_005e50c0_shell();
};

// Destructor that calls FUN_005e3c60 on this and then deallocates the object memory.
// @fnv 0x005e50c0
FUN_005e50c0_shell::~FUN_005e50c0_shell()
{
    FUN_005e3c60(this);
    if (1)
        ::FUN_00401030(this);
}
