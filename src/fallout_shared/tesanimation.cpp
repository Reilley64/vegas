// fallout_shared/tesanimation.cpp: TESAnimation, ActorValueOwner (10 functions)

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00402d50.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "tesanimation_decls.h"
#include "BaseFormComponent.h"

// @fnv 0x0047f9f0
TESAnimation::~TESAnimation()
{
    ClearComponent();
}

// Removes and deletes every filename string from the animation list until it is empty.
// @fnv 0x0047fa50
void TESAnimation::ClearComponent()
{
    while (!m_kKFFileList.IsEmpty())
    {
        const char* filename = ((const char *)(new ((void *)&(m_kKFFileList)) ::Vec3()));
        m_kKFFileList.RemoveHead();
        delete const_cast<char*>(filename);
    }
}

// @fnv 0x0047fd90
bool TESAnimation::HasSpecialAnimations()
{
    if (m_kKFFileList.IsEmpty())
    {
        return false;
    }
    return true;
}

// @fnv 0x005f78e0
ActorValueOwner::ActorValueOwner()
{}

struct BFC_s
{
    BFC_s();
    virtual void f();
};
struct BSSpinLock_s
{
    BSSpinLock_s();
};
struct FUN_0047f9c0 : public BFC_s
{
    BSSpinLock_s lock;
    virtual void g();
    FUN_0047f9c0();
};
// Empty constructor for the BFC_s-derived class.
// @fnv 0x0047f9c0
FUN_0047f9c0::FUN_0047f9c0()
{}

struct ListNodeStub
{
    bool _ref_008256d0();
};
struct FUN_0047fcb0_cls
{
    int pad;
    ListNodeStub list;
    bool ContainsName(const char* apName);
};
// @fnv 0x0047fcb0
bool FUN_0047fcb0_cls::ContainsName(const char* apName)
{
    if (list._ref_008256d0())
        return false;
    ListNodeStub* pNode = &list;
    while (pNode)
    {
        const char* pcName = *((const char **)(new ((void *)(pNode)) ::Vec3()));
        if (!::FUN_00404dc0(pcName, apName))
            return true;
        pNode = ((::ListNodeStub *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return false;
}

void* __cdecl operator new(unsigned int);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_0047fcb0_stub
{
};
struct FUN_0047fd20_cls
{
    int pad;
    SoundListView list;
    void AddPathToList(const char* apPath);
};
// @fnv 0x0047faa0
void TESAnimation::LoadComponent(TESForm* form, TESFile* file)
{
    if (!file || !form)
        return;
    unsigned int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()));
    switch (chunk)
    {
    case 0x5a46464b: {
        char* pCurrent;
        char* pData = new char[reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()];
        pCurrent = pData;
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pData), 0);
        while (*pCurrent)
        {
            reinterpret_cast<::FUN_0047fd20_cls *>(this)->AddPathToList(pCurrent);
            pCurrent = pCurrent + ::FUN_0044a670(pCurrent) + 1;
        }
        delete[] pData;
    }
    break;
    }
}
// If the path is not already present, allocates a copy of it, copies the string into it and appends it to the list.
// @fnv 0x0047fd20
void FUN_0047fd20_cls::AddPathToList(const char* apPath)
{
    char* pcPathCopy;
    if (!reinterpret_cast<::FUN_0047fcb0_cls *>((((FUN_0047fcb0_stub*)this)))->ContainsName(apPath))
    {
        unsigned int uiSize = ::FUN_0044a670(apPath) + 1;
        pcPathCopy = new char[uiSize];
        TaskQueueInterface::CopyStringToBuffer(pcPathCopy, uiSize, apPath);
        reinterpret_cast<::Callees *>(&(list))->FUN_00905820((void *)&(pcPathCopy));
    }
}

struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
struct TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESForm;
struct TESHealthForm;
struct TESLevItem;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_0047fb50_shell : public TESAnimation
{
    void FUN_0047fb50(BaseFormComponent*);
};

// Casts apCopyFC to TESAnimation, frees this component, then copies each filename from the source's file list via AddPathToList.
// @fnv 0x0047fb50
void FUN_0047fb50_shell::FUN_0047fb50(BaseFormComponent* apCopyFC)
{
    TESAnimation* pcopy = dynamic_cast<TESAnimation*>(apCopyFC);
    if (pcopy == 0)
        return;
    reinterpret_cast<::FUN_00402d50 *>((((BaseFormComponent*)this)))->FUN_00402d50::~FUN_00402d50();
    BSSimpleList<const char*>* pkfFileList = &pcopy->m_kKFFileList;
    while (pkfFileList != 0)
    {
        const char* pkfFilename = ((const char *)(new ((void *)(pkfFileList)) ::Vec3()));
        if (pkfFilename != 0)
            reinterpret_cast<::FUN_0047fd20_cls *>(this)->AddPathToList(pkfFilename);
        pkfFileList = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(pkfFileList))->FUN_00726070()));
    }
}


struct ListStepStub
{
};

struct ListStepStub2
{
};

struct FUN_0047fbd0_cls : public TESAnimation
{
    bool IsAnimationDifferent(BaseFormComponent* component);
};

// @fnv 0x0047fbd0
bool FUN_0047fbd0_cls::IsAnimationDifferent(BaseFormComponent* component)
{
    const char* x;
    const char* y;
    TESAnimation* other_2 = dynamic_cast<TESAnimation*>(component);
    if (other_2 == 0)
    {
        return true;
    }
    BSSimpleList<const char*>* a = &this->m_kKFFileList;
    BSSimpleList<const char*>* b8 = &other_2->m_kKFFileList;
    while (a != 0 && b8 != 0)
    {
        x = ((const char *)(new ((void *)(a)) ::Vec3()));
        y = ((const char *)(new ((void *)(b8)) ::Vec3()));
        if ((x == 0 && y != 0) || (x != 0 && y == 0))
        {
            return true;
        }
        else
        {
            if (x != 0 && y != 0)
            {
                if (::FUN_00404dc0(x, y) != 0)
                {
                    return true;
                }
            }
        }
        a = (BSSimpleList<const char*>*)((::ListStepStub *)(reinterpret_cast<::Callees *>((((ListStepStub*)a)))->FUN_00726070()));
        b8 = (BSSimpleList<const char*>*)((::ListStepStub2 *)(reinterpret_cast<::Callees *>((((ListStepStub2*)b8)))->FUN_00726070()));
    }
    if (a != 0 || b8 != 0)
    {
        return true;
    }
    return false;
}
