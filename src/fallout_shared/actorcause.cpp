// fallout_shared/actorcause.cpp: ActorCause (5 functions)

#include <new>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/E640Cls.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0044bbc0_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/S_0066e2b0_Class.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_011d6000.h"
#include "actorcause.h"

// @fnv 0x0066e910
void ActorCause::ClearActorCauseList(BGSLoadGameBuffer* buffer)
{
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::BSSimpleList< ::ActorCause *> *>(&::g_011d6124))))->RemoveAll();
}

struct FUN_0047d3d0_shell : public ActorCause
{
    unsigned short FUN_0047d3d0();
};

// @fnv 0x0047d3d0
unsigned short FUN_0047d3d0_shell::FUN_0047d3d0()
{
    return *(unsigned short*)((char*)this + 0x18);
}

struct AC_0042f730
{
};
struct Holder0042f780
{
    AC_0042f730* m_pObject;
    Holder0042f780* FUN_0042f780(AC_0042f730* pObject);
};
// @fnv 0x0042f780
Holder0042f780* Holder0042f780::FUN_0042f780(AC_0042f730* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            reinterpret_cast<::S_0066e2b0_Class *>((m_pObject))->FUN_0066e2b0();
        m_pObject = pObject;
        if (m_pObject)
            reinterpret_cast<::FUN_0044bbc0_Class *>((m_pObject))->FUN_0044bbc0();
    }
    return this;
}

struct FUN_0066e010_cls;
struct VirtObjPlaceholder;

struct Pair12
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

class CauseRef
{
  public:
};

struct VirtObjPlaceholder
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
    virtual int v61(CauseRef* apRef);
};


struct FUN_0066e010_cls
{
    CauseRef* m_00;
    int m_04;
    Pair12 m_08;
    unsigned int m_14;
    int m_18;

    FUN_0066e010_cls* FUN_0066e010(CauseRef* arg);
};

// @fnv 0x0066e010
FUN_0066e010_cls* FUN_0066e010_cls::FUN_0066e010(CauseRef* apCauseRef)
{
    new ((void *)&(m_08)) ::Vec3();
    m_00 = apCauseRef;
    Pair12* src2 = (m_00 != 0) ? ((::Pair12 *)(reinterpret_cast<::TESTopicInfo *>((m_00))->GetAddTopicList())) : &(*reinterpret_cast<::Pair12 *>((void *)&::NiPoint3::ZERO));
    m_08 = *src2;
    m_04 = 0;
    VirtObjPlaceholder* v = (m_00 != 0) ? ((::VirtObjPlaceholder *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apCauseRef))->GetBaseTexture())) : 0;
    if (v != 0)
    {
        m_04 = v->v61(m_00);
    }
    m_18 = 0;
    m_14 = (*reinterpret_cast<unsigned int *>(&::DAT_011d60cc));
    (*reinterpret_cast<unsigned int *>(&::DAT_011d60cc)) = (*reinterpret_cast<unsigned int *>(&::DAT_011d60cc)) + 1;
    FUN_0066e010_cls* self = this;
    (*reinterpret_cast<::BSSimpleList< ::FUN_0066e010_cls *> *>(&::g_011d6124)).AddHead(self);
    return this;
}

class B66E810Item
{
  public:
    ~B66E810Item();


    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_iFadeIndex;
};

class B66E810Node
{
  public:
    bool IsEmpty();
    void RemoveHead();
};


// Walks g_kB66E810List, updating items with a positive count and deleting/removing items whose count is zero or that are null.
// @fnv 0x0066e810
void __cdecl UpdateOrRemoveItems(int iArg)
{
    B66E810Node* pkNode = &(*reinterpret_cast<::B66E810Node *>(&::g_011d6124));
    B66E810Node* pkPrev = 0;
    while (pkNode && !pkNode->IsEmpty())
    {
        B66E810Item* pkItem = *((::B66E810Item **)(new ((void *)(pkNode)) ::Vec3()));
        bool bRemove = false;
        if (pkItem)
        {
            if (reinterpret_cast<::FUN_0047d3d0_shell *>((pkItem))->FUN_0047d3d0() > 0)
            {
                reinterpret_cast<::E640Cls *>((pkItem))->FUN_0066e640((::SaveBufCls *)(iArg));
            }
            else
            {
                pkItem->m_iFadeIndex = -1;
                delete pkItem;
                bRemove = true;
            }
        }
        else
        {
            bRemove = true;
        }
        if (bRemove)
        {
            if (pkPrev)
            {
                reinterpret_cast<::ItemChangeListNode *>((pkPrev))->FUN_00905330((*(::InventoryStackRecord *const *)(((::B66E810Item **)(new ((void *)(pkNode)) ::Vec3())))));
                pkNode = ((::B66E810Node *)(reinterpret_cast<::Callees *>((pkPrev))->FUN_00726070()));
            }
            else
            {
                pkNode->RemoveHead();
            }
        }
        else
        {
            pkPrev = pkNode;
            pkNode = ((::B66E810Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        }
    }
}
