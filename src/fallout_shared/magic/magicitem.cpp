// fallout_shared/magic/magicitem.cpp: MagicItem, MagicStatus, UnloadMagic, MagicLabel (18 functions)

#include <new>
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00403db0_shell.h"
#include "fnv/decl/FUN_00403f80_shell.h"
#include "fnv/decl/FUN_004086e0_shell.h"
#include "fnv/decl/FUN_004087e0_Shell.h"
#include "fnv/decl/FUN_00408a00_Struct.h"
#include "fnv/decl/FUN_0040c130_Class.h"
#include "fnv/decl/FUN_0043b410_class.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_004811e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0092c870_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Holder00408910.h"
#include "fnv/decl/NPCModelView.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Unk00408730.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00444f10__FUN_00444f10_shell.h"
#include "fnv/decl/fnv_00445370__FUN_00445370_cls.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004471c0__FUN_004471c0_shell.h"
#include "fnv/decl/fnv_00447330__FUN_00447330_shell.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_01202000.h"
#include "magicitem_decls.h"

// Looks up the TESForm for auiID and returns it cast to MagicItemForm or MagicItemObject, otherwise null.
// @fnv 0x0040a250
MagicItem* MagicItem::GetMagicItemByID(unsigned int auiID)
{
    MagicItemObject* pObject;
    TESForm* pForm;
    MagicItemForm* pFormItem;
    pForm = ::FUN_004839c0(auiID);
    if (pForm)
    {
        pFormItem = dynamic_cast<MagicItemForm*>(pForm);
        pObject = dynamic_cast<MagicItemObject*>(pForm);
        if (pFormItem)
            return pFormItem;
        if (pObject)
            return pObject;
    }
    return 0;
}

// Initializes every EffectItem in the list with apForm and counts how many are hostile, storing the count.
// @fnv 0x0040c030
void MagicItem::LoadEffectsFromForm(TESForm* apForm)
{
    EffectItemList* pIter = this;
    m_iEffectCount = 0;
    while (pIter)
    {
        if (EffectItem* pItem = ((::EffectItem *)(new ((void *)(pIter)) ::Vec3())))
        {
            reinterpret_cast<::FUN_00403db0_shell *>((pItem))->FUN_00403db0(apForm);
            if (pItem->IsHostile())
                m_iEffectCount++;
        }
        pIter = (EffectItemList*)((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
}

// @fnv 0x0040b470
bool MagicItem::IsLoaded()
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    if (pSelfEffectSetting && pSelfEffectSetting->GetModelLength() > 0 && !reinterpret_cast<::FUN_00408a00_Struct *>((pSelfEffectSetting))->IsPositive())
        return false;

    EffectItemList* pIter = this;
    if (!pIter->IsEmpty())
    {
        while (pIter)
        {
            EffectItem* pItem = ((::EffectItem *)(new ((void *)(pIter)) ::Vec3()));
            EffectSetting* pEffect = pItem ? ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pItem))->FUN_00825c00())) : 0;
            if (pEffect && ::IsArchetypeFlagSet((::EffectSetting *)(pEffect)) && !pEffect->HasEffectID())
                return false;
            pIter = (EffectItemList*)((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
    }
    return true;
}

// Scans the effect list for the best non-detrimental effect by range then cost and returns its EffectSetting, or null if none.
// @fnv 0x0040a300
EffectSetting* MagicItem::GetEffectSettingForRange(MagicSystem::Range aeRange)
{
    struct BestEffect
    {
        MagicSystem::Range range;
        EffectItem* item;
        int cost;
    } best;
    EffectItemList* pIter;
    best.item = 0;
    pIter = this;
    if (pIter->IsEmpty())
        return 0;
    best.cost = -1;
    best.range = aeRange;
    while (pIter)
    {
        struct CurrentEffect
        {
            EffectItem* item;
            int cost;
            MagicSystem::Range range;
        } current;
        current.item = ((::EffectItem *)(new ((void *)(pIter)) ::Vec3()));
        current.cost = static_cast<int>(reinterpret_cast<::FUN_00403f80_shell *>((current.item))->GetModifiedCost(0));
        current.range = current.item->GetRange();
        if (!current.item->IsDetrimental() &&
            (current.range > best.range || (current.range == best.range && current.cost > best.cost)))
        {
            best.item = current.item;
            best.cost = current.cost;
            best.range = current.item->GetRange();
        }
        pIter = (EffectItemList*)((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
    return best.item ? ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((best.item))->FUN_00825c00())) : 0;
}

// @fnv 0x0040b6b0
bool MagicItem::IsLoading()
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    {
        bool m_bHeaderParsed = true;
        if (pSelfEffectSetting && pSelfEffectSetting->GetModelLength() > 0 && !reinterpret_cast<::FUN_00408a00_Struct *>((pSelfEffectSetting))->IsPositive())
        {
            m_bHeaderParsed = false;
            if (!pSelfEffectSetting->HasNoAssociatedActorValue())
                return false;
        }
        EffectItemList* pIter = this;
        if (!pIter->IsEmpty())
        {
            while (pIter)
            {
                EffectItem* pItem = ((::EffectItem *)(new ((void *)(pIter)) ::Vec3()));
                EffectSetting* pEffect = pItem ? ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pItem))->FUN_00825c00())) : 0;
                if (pEffect && ::IsArchetypeFlagSet((::EffectSetting *)(pEffect)) && !pEffect->HasEffectID())
                {
                    m_bHeaderParsed = false;
                    if (!pEffect->UsesAssociatedActorValue())
                        return false;
                }
                pIter = (EffectItemList*)((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
            }
        }
        if (m_bHeaderParsed)
            return false;
        return true;
    }
}

// @fnv 0x0040a420
void MagicItem::Preload(bool immediate)
{
    EffectSetting* pSelfEffectSetting = GetEffectSettingForRange(MagicSystem::SELF);
    bool bProceed = false;
    bool bLoad = false;
    if (immediate || IsLoaded())
    {
        bProceed = true;
        bLoad = true;
    }
    else if (IsLoading())
    {
        bProceed = true;
        bLoad = false;
    }
    if (!bProceed)
    {
        reinterpret_cast<::fnv_00444f10::FUN_00444f10_shell *>((g_modelLoader))->FUN_00444f10((::fnv_00444f10::MagicItem *)(::MagicItem *)(this), (::fnv_00444f10::EffectSetting *)(pSelfEffectSetting), 0);
        return;
    }
    if (pSelfEffectSetting)
    {
        if (bLoad && pSelfEffectSetting->GetModelLength() > 0)
            reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(pSelfEffectSetting->GetModelFilePath()), 0, true, false, false, false);
        pSelfEffectSetting->FUN_004088c0();
    }
    EffectItemList* pIter = this;
    if (!pIter->IsEmpty())
    {
        while (pIter)
        {
            struct CurrentEffect
            {
                EffectItem* item;
                EffectSetting* effect;
            } current;
            current.item = ((::EffectItem *)(new ((void *)(pIter)) ::Vec3()));
            current.effect = ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((current.item))->FUN_00825c00()));
            if (::IsArchetypeFlagSet((::EffectSetting *)(current.effect)))
            {
                if (bLoad)
                {
                    TESForm* form = reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((current.effect))->FUN_005f5f80();
                    if (form && reinterpret_cast<::S3e60 *>((current.effect))->FUN_00403e60(0x10000))
                    {
                        TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(form);
                        if (weapon && weapon->model.GetModelLength() > 0)
                            reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(weapon->model.GetModelFilePath()), 0, true, false, false, false);
                    }
                    else if (form && reinterpret_cast<::S3e60 *>((current.effect))->FUN_00403e60(0x20000))
                    {
                        TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(form);
                        if (armor)
                        {
                            reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(reinterpret_cast<::FUN_004811e0_shell *>(&(armor->biped))->FUN_004811e0(0)), 0, true, false, false, false);
                            reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(reinterpret_cast<::FUN_004811e0_shell *>(&(armor->biped))->FUN_004811e0(1)), 0, true, false, false, false);
                        }
                    }
                    else if (form && reinterpret_cast<::S3e60 *>((current.effect))->FUN_00403e60(0x40000))
                    {
                        TESNPC* pNPC = dynamic_cast<TESNPC*>(form);
                        if (pNPC)
                        {
                            struct ModelFileIteration
                            {
                                BSSimpleList<const char*>* list;
                                BSSimpleList<const char*>* iter;
                            } modelFiles;
                            modelFiles.list = reinterpret_cast<::NPCModelView *>((pNPC))->CollectModelPaths(true, true);
                            modelFiles.iter = modelFiles.list;
                            while (modelFiles.iter && !modelFiles.iter->IsEmpty())
                            {
                                const char* filename = ((const char *)(new ((void *)(modelFiles.iter)) ::Vec3()));
                                reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(filename), 0, true, false, false, false);
                                modelFiles.iter = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(modelFiles.iter))->FUN_00726070()));
                            }
                            reinterpret_cast<::FileMatchList *>((void *)(modelFiles.list))->RemoveAll();
                            delete modelFiles.list;
                        }
                        TESCreature* creature = dynamic_cast<TESCreature*>(form);
                        if (creature)
                        {
                            reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(creature->model.GetModelFilePath()), 0, true, false, false, false);
                            struct ModelPaths
                            {
                                BSSimpleList<const char*>* node;
                                const char* base;
                                BSSimpleList<const char*>* files;
                                char* slash;
                                const char* filename;
                            } modelPaths;
                            modelPaths.filename = creature->model.GetModelFilePath();
                            modelPaths.files = ((::BSSimpleList<const char *> *)(reinterpret_cast<::BaseProcess *>(&(creature->modelList))->GetCurrentProcessData()));
                            char path[260];
                            TaskQueueInterface::CopyStringToBuffer(path, 260, modelPaths.filename);
                            modelPaths.slash = FUN_0040ab30(path, '\\');
                            modelPaths.node = modelPaths.files;
                            while (modelPaths.slash && modelPaths.node)
                            {
                                modelPaths.slash[1] = 0;
                                const char* name = ((const char *)(new ((void *)(modelPaths.node)) ::Vec3()));
                                if (name)
                                {
                                    strcat_s(path, 260, name);
                                    reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(path), 0, true, false, false, false);
                                }
                                modelPaths.node = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(modelPaths.node))->FUN_00726070()));
                            }
                            modelPaths.base = strrchr(modelPaths.filename, '\\');
                            if (modelPaths.base && !_strnicmp(modelPaths.base + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* files =
                                    ((::BSSimpleList<const char *> *)(reinterpret_cast<::fnv_00447330::FUN_00447330_shell *>((g_modelLoader))->FUN_00447330((char *)(modelPaths.filename), false, false, 0)));
                                BSSimpleList<const char*>* node = files;
                                while (node)
                                {
                                    const char* name = ((const char *)(new ((void *)(node)) ::Vec3()));
                                    if (name)
                                        reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>((g_modelLoader))->LoadKFModel((char *)(name));
                                    delete[] name;
                                    node = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(node))->FUN_00726070()));
                                }
                                reinterpret_cast<::FileMatchList *>((void *)(files))->RemoveAll();
                                delete files;
                            }
                            if (creature->animation.HasSpecialAnimations())
                            {
                                modelPaths.slash[1] = 0;
                                strcat_s(path, 260, "SpecialAnims");
                                strcat_s(path, 260, "\\");
                                modelPaths.slash = FUN_0040ab30(path, '\\');
                                BSSimpleList<const char*>* anim = ((::BSSimpleList<const char *> *)(reinterpret_cast<::BaseProcess *>(&(creature->animation))->GetCurrentProcessData()));
                                while (anim)
                                {
                                    modelPaths.slash[1] = 0;
                                    const char* name = ((const char *)(new ((void *)(anim)) ::Vec3()));
                                    if (name)
                                    {
                                        strcat_s(path, 260, name);
                                        reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>((g_modelLoader))->LoadKFModel((char *)(path));
                                    }
                                    anim = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(anim))->FUN_00726070()));
                                }
                            }
                        }
                    }
                }
                if (!current.effect->HasEffectID() && !current.effect->UsesAssociatedActorValue() &&
                    reinterpret_cast<::S3e60 *>((current.effect))->FUN_00403e60(0x40000))
                    FUN_0040ab50();
                reinterpret_cast<::FUN_004086e0_shell *>((current.effect))->UpdateCounter();
            }
            pIter = (EffectItemList*)((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
    }
}

// @fnv 0x0040ab30
char* FUN_0040ab30(char* pcString, int cChar)
{
    return (char*)strrchr((const char*)pcString, cChar);
}

struct FUN_0040c110_obj
{
    void FUN_0040c130();
};
void FUN_0040c130(void*);

struct FUN_0040c110_ptr
{
    struct Target
    {
        void Release();
    }* m_pObject;
};

void FUN_0040c130(FUN_0040c110_ptr::Target*);

// @fnv 0x0040c110
void FUN_0040c110(FUN_0040c110_ptr* _this)
{
    if (_this->m_pObject)
        reinterpret_cast<::FUN_0040c130_Class *>((_this->m_pObject))->FUN_0040c130();
}


// Returns pThis[1] when pThis is non-null, otherwise resets DAT_01202800 to 0 and returns it.
// @fnv 0x0043d4d0
int& FUN_0043d4d0(int* pThis)
{
    return pThis ? pThis[1] : (DAT_01202800 = 0, DAT_01202800);
}

struct FUN_004047f0_arg
{
    const BSStringT<char>* s;
};
void FUN_00403970(BSStringT<char>*);
// @fnv 0x004047f0
BSStringT<char>* AssignFromString(BSStringT<char>* this_ptr, FUN_004047f0_arg aStringArg)
{
    FUN_00403970(this_ptr);
    reinterpret_cast<::TextString *>((this_ptr))->FUN_004037f0(((const char *)(::FUN_00559450((int *)(aStringArg.s)))), 0);
    return this_ptr;
}

struct FUN_0040c0e0_arg
{
    const char* s;
};
void FUN_00403970(BSStringT<char>*);
// @fnv 0x0040c0e0
BSStringT<char>* FUN_0040c0e0(BSStringT<char>* this_ptr, FUN_0040c0e0_arg aCString)
{
    FUN_00403970(this_ptr);
    reinterpret_cast<::TextString *>((this_ptr))->FUN_004037f0(aCString.s, 0);
    return this_ptr;
}

extern int DAT_011c3438;

// @fnv 0x0040ab50
void FUN_0040ab50()
{
    DAT_011c3438 += 1;
}

struct FUN_0040ab70_shell : public MagicItem
{
    void PreloadModels();
};

void operator delete(void*);
const char* strrchr(const char*, int);

struct FUN_0040b800_shell
{
};

extern int DAT_011c3438;

// @fnv 0x0040bed0
void DecrementGlobalCounter()
{
    --DAT_011c3438;
}

struct EffectStatus : EffectSetting
{
};
struct MagicStatus : MagicItem
{
    EffectStatus* FUN_0040a300(int);
    bool FUN_0040b580();
};
// @fnv 0x0040b580
bool MagicStatus::FUN_0040b580()
{
    EffectStatus* current = FUN_0040a300(0);
    if (current && current->GetModelLength() > 0 && !reinterpret_cast<::FUN_00408a00_Struct *>((current))->IsPositive() && !reinterpret_cast<::EffectSetting *>((current))->HasNoAssociatedActorValue())
        return false;
    EffectItemList* primary = this;
    if (!primary->IsEmpty())
    {
        while (primary)
        {
            EffectItem* item = ((::EffectItem *)(new ((void *)(primary)) ::Vec3()));
            EffectSetting* setting = item ? ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((item))->FUN_00825c00())) : 0;
            if (setting && ::IsArchetypeFlagSet((::EffectSetting *)(setting)) && !reinterpret_cast<::EffectSetting *>((((EffectStatus*)setting)))->HasEffectID() &&
                !reinterpret_cast<::EffectSetting *>((((EffectStatus*)setting)))->UsesAssociatedActorValue())
                return false;
            primary = static_cast<EffectItemList*>(((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((primary))->FUN_00726070())));
        }
    }
    return true;
}

class TESSound
{
  public:
};

struct FUN_0040a1e0_shell : MagicItem
{
    int FUN_0040a1e0();
};

// Casts this MagicItem to MagicItemForm or MagicItemObject and calls TESSound::Deallocate on it, returning 0 if neither cast succeeds.
// @fnv 0x0040a1e0
int FUN_0040a1e0_shell::FUN_0040a1e0()
{
    MagicItemForm* form = dynamic_cast<MagicItemForm*>(static_cast<MagicItem*>(this));
    MagicItemObject* object = dynamic_cast<MagicItemObject*>(static_cast<MagicItem*>(this));
    if (form != 0)
        return reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESSound*>(form)))->FUN_0084e3a0();
    else if (object != 0)
        return reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESSound*>(object)))->FUN_0084e3a0();
    return 0;
}

struct UnloadEffect : EffectSetting
{
};
struct UnloadLoader : ModelLoader
{
};
struct UnloadMagic : MagicItem
{
    UnloadEffect* FUN_0040a300(int);
    void FUN_0040b800(bool);
};
// Preloads the magic item's effect models and, per effect, loads weapon, armor, NPC or creature models and animation files via g_modelLoader.
// @fnv 0x0040ab70
void FUN_0040ab70_shell::PreloadModels()
{
    EffectItemList* pCurrentElementNext;
    EffectSetting* pavEffectSetting = ((MagicItem*)this)->GetEffectSettingForRange(MagicSystem::SELF);

    if (!((MagicItem*)this)->IsLoading())
    {
        ((MagicItem*)this)->Preload(true);
        reinterpret_cast<::UnloadMagic *>((((FUN_0040b800_shell*)this)))->FUN_0040b800(true);
        return;
    }

    if (pavEffectSetting)
    {
        int icount = 0;
        if (pavEffectSetting->HasNoAssociatedActorValue())
            icount = pavEffectSetting->NormalizeEffectLoadedCount();
        if (pavEffectSetting->GetModelLength() > 0)
        {
            NiPointer<Model> spmodel(0);
            reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(pavEffectSetting->GetModelFilePath()), (void *)&(spmodel));
            if (spmodel)
                reinterpret_cast<::FUN_0043b410_class *>((((Model*)spmodel)))->AtomicAdd(icount);
        }
    }

    pCurrentElementNext = (MagicItem*)this;
    if (!pCurrentElementNext->IsEmpty())
    {
        while (pCurrentElementNext)
        {
            EffectItem* pitem = ((::EffectItem *)(new ((void *)(pCurrentElementNext)) ::Vec3()));
            EffectSetting* pes = ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pitem))->FUN_00825c00()));
            TESForm* pform = reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((pes))->FUN_005f5f80();
            int icount = 0;
            if (pes->UsesAssociatedActorValue())
                icount = reinterpret_cast<::FUN_004087e0_Shell *>((pes))->FUN_004087e0();
            if (icount)
            {
                if (pform && reinterpret_cast<::S3e60 *>((pes))->FUN_00403e60(0x10000))
                {
                    TESObjectWEAP* pweapon = dynamic_cast<TESObjectWEAP*>(pform);
                    if (pweapon && ((TESModel*)((char*)pweapon + 0x3c))->GetModelLength() > 0)
                    {
                        NiPointer<Model> spmodel(0);
                        reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(((TESModel*)((char*)pweapon + 0x3c))->GetModelFilePath()), (void *)&(spmodel));
                        if (spmodel)
                            reinterpret_cast<::FUN_0043b410_class *>((((Model*)spmodel)))->AtomicAdd(icount);
                    }
                }
                else if (pform && reinterpret_cast<::S3e60 *>((pes))->FUN_00403e60(0x20000))
                {
                    TESObjectARMO* parmor = dynamic_cast<TESObjectARMO*>(pform);
                    if (parmor)
                    {
                        NiPointer<Model> spmodel(0);
                        reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(reinterpret_cast<::FUN_004811e0_shell *>((((TESBipedModelForm*)((char*)parmor + 0x70))))->FUN_004811e0(0)),
                                                    (void *)&(spmodel));
                        if (spmodel)
                            reinterpret_cast<::FUN_0043b410_class *>((((Model*)spmodel)))->AtomicAdd(icount);
                        reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(reinterpret_cast<::FUN_004811e0_shell *>((((TESBipedModelForm*)((char*)parmor + 0x70))))->FUN_004811e0(1)),
                                                    (void *)&(spmodel));
                        if (spmodel)
                            reinterpret_cast<::FUN_0043b410_class *>((((Model*)spmodel)))->AtomicAdd(icount);
                    }
                }
                else if (pform && reinterpret_cast<::S3e60 *>((pes))->FUN_00403e60(0x40000))
                {
                    TESNPC* pnpc = dynamic_cast<TESNPC*>(pform);
                    if (pnpc)
                    {
                        BSSimpleList<const char*>* modelList = reinterpret_cast<::NPCModelView *>((pnpc))->CollectModelPaths(true, true);
                        BSSimpleList<const char*>* pCurrentElementNext = modelList;
                        while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
                        {
                            const char* pfilename = ((const char *)(new ((void *)(pCurrentElementNext)) ::Vec3()));
                            NiPointer<Model> spmodel(0);
                            reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(pfilename), (void *)&(spmodel));
                            if (spmodel)
                                reinterpret_cast<::FUN_0043b410_class *>((((Model*)spmodel)))->AtomicAdd(icount);
                            pCurrentElementNext = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(pCurrentElementNext))->FUN_00726070()));
                        }
                        reinterpret_cast<::FileMatchList *>((void *)(modelList))->RemoveAll();
                        delete modelList;
                    }
                    TESCreature* pcreature = dynamic_cast<TESCreature*>(pform);
                    if (pcreature)
                    {
                        NiPointer<Model> spmodel(0);
                        const char* plastBackSlash;
                        BSSimpleList<const char*>* pfilelist;
                        char* plastSlash;
                        const char* pfilename;
                        reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(((TESModel*)((char*)pcreature + 0xdc))->GetModelFilePath()),
                                                    (void *)&(spmodel));
                        if (spmodel)
                        {
                            char path[260];
                            BSSimpleList<const char*>* pcreatureFileList;
                            for (int i = 0; i < icount; i++)
                                reinterpret_cast<::FUN_0092c870_shell *>((((Model*)spmodel)))->FUN_0092c870();
                            pfilename = ((const char *)(::FUN_00559450((int *)(((Model*)spmodel)))));
                            pfilelist = ((::BSSimpleList<const char *> *)(reinterpret_cast<::BaseProcess *>((((TESModelList*)((char*)pcreature + 0x114))))->GetCurrentProcessData()));
                            TaskQueueInterface::CopyStringToBuffer(path, 260, pfilename);
                            plastSlash = FUN_0040ab30(path, '\\');
                            pcreatureFileList = pfilelist;
                            while (plastSlash && pcreatureFileList)
                            {
                                plastSlash[1] = 0;
                                const char* pitem = ((const char *)(new ((void *)(pcreatureFileList)) ::Vec3()));
                                if (pitem)
                                {
                                    strcat_s(path, 260, pitem);
                                    NiPointer<Model> spmodel(0);
                                    reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(path), (void *)&(spmodel));
                                    if (spmodel)
                                        reinterpret_cast<::FUN_0043b410_class *>((((Model*)spmodel)))->AtomicAdd(icount);
                                }
                                pcreatureFileList = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(pcreatureFileList))->FUN_00726070()));
                            }
                            plastBackSlash = strrchr(pfilename, '\\');
                            if (plastBackSlash && !_strnicmp(plastBackSlash + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* pkfList =
                                    ((::BSSimpleList<const char *> *)(reinterpret_cast<::fnv_00447330::FUN_00447330_shell *>((g_modelLoader))->FUN_00447330((char *)(pfilename), false, false, 0)));
                                {
                                    BSSimpleList<const char*>* pFilenameList = pkfList;
                                    while (pFilenameList)
                                    {
                                        const char* pitem = ((const char *)(new ((void *)(pFilenameList)) ::Vec3()));
                                        if (pitem)
                                        {
                                            for (int i = 0; i < icount; i++)
                                                reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>((g_modelLoader))->LoadKFModel((char *)(pitem));
                                        }
                                        delete pitem;
                                        pFilenameList = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(pFilenameList))->FUN_00726070()));
                                    }
                                }
                                reinterpret_cast<::FileMatchList *>((void *)(pkfList))->RemoveAll();
                                delete pkfList;
                            }
                            if (((TESAnimation*)((char*)pcreature + 0xc4))->HasSpecialAnimations())
                            {
                                plastSlash[1] = 0;
                                strcat_s(path, 260, "SpecialAnims");
                                strcat_s(path, 260, "\\");
                                plastSlash = FUN_0040ab30(path, '\\');
                                BSSimpleList<const char*>* pspecialList =
                                    ((::BSSimpleList<const char *> *)(reinterpret_cast<::BaseProcess *>((((TESAnimation*)((char*)pcreature + 0xc4))))->GetCurrentProcessData()));
                                while (pspecialList)
                                {
                                    plastSlash[1] = 0;
                                    const char* pitem = ((const char *)(new ((void *)(pspecialList)) ::Vec3()));
                                    if (pitem)
                                    {
                                        strcat_s(path, 260, pitem);
                                        for (int i = 0; i < icount; i++)
                                            reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>((g_modelLoader))->LoadKFModel((char *)(path));
                                    }
                                    pspecialList = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(pspecialList))->FUN_00726070()));
                                }
                            }
                        }
                    }
                }
            }
            pCurrentElementNext = static_cast<EffectItemList*>(((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070())));
        }
    }
}
// @fnv 0x0040b800
void UnloadMagic::FUN_0040b800(bool immediate)
{
    if (!reinterpret_cast<::MagicStatus *>(this)->FUN_0040b580())
        return;
    UnloadEffect* primary = FUN_0040a300(0);
    bool queued = false;
    if (reinterpret_cast<::MagicItem *>(this)->IsLoading())
        queued = true;
    if (primary && primary->GetModelLength())
    {
        if (!queued)
            reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(primary->GetModelFilePath()), immediate, true);
        reinterpret_cast<::Holder00408910 *>((primary))->StepTowardZero();
    }
    EffectItemList* effects = this;
    if (!effects->IsEmpty())
    {
        while (effects)
        {
            EffectItem* item = ((::EffectItem *)(new ((void *)(effects)) ::Vec3()));
            UnloadEffect* effect = (UnloadEffect*)((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((item))->FUN_00825c00()));
            if (::IsArchetypeFlagSet((::EffectSetting *)(effect)))
            {
                if (!queued)
                {
                    TESForm* associated = reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((effect))->FUN_005f5f80();
                    if (associated && reinterpret_cast<::S3e60 *>((effect))->FUN_00403e60(0x10000))
                    {
                        TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(associated);
                        if (weapon && weapon->model.GetModelLength() > 0)
                            reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(weapon->model.GetModelFilePath()), immediate, true);
                    }
                    else if (associated && reinterpret_cast<::S3e60 *>((effect))->FUN_00403e60(0x20000))
                    {
                        TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(associated);
                        if (armor)
                        {
                            reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(reinterpret_cast<::FUN_004811e0_shell *>(&(armor->biped))->FUN_004811e0(0)), immediate, true);
                            reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(reinterpret_cast<::FUN_004811e0_shell *>(&(armor->biped))->FUN_004811e0(1)), immediate, true);
                        }
                    }
                    else if (associated && reinterpret_cast<::S3e60 *>((effect))->FUN_00403e60(0x40000))
                    {
                        TESNPC* npc3 = dynamic_cast<TESNPC*>(associated);
                        if (npc3)
                        {
                            BSSimpleList<const char*>* models71 = reinterpret_cast<::NPCModelView *>((npc3))->CollectModelPaths(true, true);
                            BSSimpleList<const char*>* model15 = models71;
                            while (model15 && !model15->IsEmpty())
                            {
                                const char* path = ((const char *)(new ((void *)(model15)) ::Vec3()));
                                reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(path), immediate, true);
                                model15 = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(model15))->FUN_00726070()));
                            }
                            reinterpret_cast<::FileMatchList *>((void *)(models71))->RemoveAll();
                            delete models71;
                        }
                        TESCreature* creature11 = dynamic_cast<TESCreature*>(associated);
                        if (creature11)
                        {
                            reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(creature11->model.GetModelFilePath()), immediate, true);
                            const char* modelPath6 = creature11->model.GetModelFilePath();
                            BSSimpleList<const char*>* modelList6 = ((::BSSimpleList<const char *> *)(reinterpret_cast<::BaseProcess *>(&(creature11->modelList))->GetCurrentProcessData()));
                            BSSimpleList<const char*>* modelNode29;
                            const char* fileName12;
                            char buffer4[260];
                            ::TaskQueueInterface::CopyStringToBuffer(buffer4, 260, modelPath6);
                            char* separator10 = FUN_0040ab30(buffer4, '\\');
                            modelNode29 = modelList6;
                            while (separator10 && modelNode29)
                            {
                                separator10[1] = 0;
                                const char* path = ((const char *)(new ((void *)(modelNode29)) ::Vec3()));
                                if (path)
                                {
                                    strcat_s(buffer4, 260, path);
                                    reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(buffer4), immediate, true);
                                }
                                modelNode29 = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(modelNode29))->FUN_00726070()));
                            }
                            fileName12 = strrchr(modelPath6, '\\');
                            if (fileName12 && !_strnicmp(fileName12 + 1, "Skeleton", 8))
                            {
                                BSSimpleList<const char*>* files =
                                    ((::BSSimpleList<const char *> *)(reinterpret_cast<::fnv_00447330::FUN_00447330_shell *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00447330((char *)(modelPath6), false, false, 0)));
                                BSSimpleList<const char*>* file = files;
                                while (file)
                                {
                                    const char* path = ((const char *)(new ((void *)(file)) ::Vec3()));
                                    if (path)
                                        reinterpret_cast<::fnv_00445370::FUN_00445370_cls *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445370((unsigned int)(path), immediate);
                                    delete[] path;
                                    file = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(file))->FUN_00726070()));
                                }
                                reinterpret_cast<::FileMatchList *>((void *)(files))->RemoveAll();
                                delete files;
                            }
                            if (creature11->animation.HasSpecialAnimations())
                            {
                                separator10[1] = 0;
                                strcat_s(buffer4, 260, "SpecialAnims");
                                strcat_s(buffer4, 260, "\\");
                                separator10 = FUN_0040ab30(buffer4, '\\');
                                BSSimpleList<const char*>* animation = ((::BSSimpleList<const char *> *)(reinterpret_cast<::BaseProcess *>(&(creature11->animation))->GetCurrentProcessData()));
                                while (animation)
                                {
                                    separator10[1] = 0;
                                    const char* path = ((const char *)(new ((void *)(animation)) ::Vec3()));
                                    if (path)
                                    {
                                        strcat_s(buffer4, 260, path);
                                        reinterpret_cast<::fnv_00445370::FUN_00445370_cls *>(((*reinterpret_cast<::UnloadLoader * *>(&::g_modelLoader))))->FUN_00445370((unsigned int)(buffer4), immediate);
                                    }
                                    animation = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(animation))->FUN_00726070()));
                                }
                            }
                        }
                    }
                }
                reinterpret_cast<::Unk00408730 *>((effect))->ClampCounterTowardZero();
                if (!reinterpret_cast<::EffectSetting *>((effect))->HasEffectID() && !reinterpret_cast<::EffectSetting *>((effect))->UsesAssociatedActorValue() && reinterpret_cast<::S3e60 *>((effect))->FUN_00403e60(0x40000))
                    DecrementGlobalCounter();
            }
            effects = (EffectItemList*)((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((effects))->FUN_00726070()));
        }
    }
}

struct StringSetting
{
};
struct FUN_0040c0e0
{
    char* data;
    unsigned short length, capacity;
    FUN_0040c0e0(const char*);
    ~FUN_0040c0e0();
};
typedef struct FUN_0040c0e0 ReturnString;
struct MagicLabel
{
    ReturnString GetNameForType(unsigned int);
};
// Returns a string setting's value chosen by type, falling back to DAT_011c3474 for any other value.
// @fnv 0x0040bef0
ReturnString MagicLabel::GetNameForType(unsigned int type)
{
    switch (type)
    {
    case 1:
        return ReturnString(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c34c0))))->GetMenuTitle())));
    case 3:
        return ReturnString(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c348c))))->GetMenuTitle())));
    case 4:
        return ReturnString(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c34a0))))->GetMenuTitle())));
    case 2:
        return ReturnString(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c344c))))->GetMenuTitle())));
    case 5:
        return ReturnString(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c3458))))->GetMenuTitle())));
    case 6:
        return ReturnString(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c34d8))))->GetMenuTitle())));
    default:
        return ReturnString(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c3474))))->GetMenuTitle())));
    }
}
