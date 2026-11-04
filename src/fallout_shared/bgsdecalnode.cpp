
// src/fallout_shared/bgsdecalnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsdecalnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv_result_slot.h"
#include <atomic>
#include <cstdint>
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004ee1e0.h"
#include "fnv/decl/FUN_004ee4b0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/S_00a59e00.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00a5e780__NodeStandIn.h"
#include "fnv/decl/fnv_00a5ed10__ChildNode.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00aa1000.h"

namespace fnv_00a5e780 {
// The detached child. Like NiPointer, its destructor releases the reference the call hands over.
struct RefPtr
{
    struct RefObject
    {
        virtual ~RefObject();
        virtual void DeleteThis();
        unsigned int m_uiRefCount;
    };
    RefObject* m_pObject = nullptr;
    ~RefPtr()
    {
        if (m_pObject && std::atomic_ref<unsigned int>(m_pObject->m_uiRefCount).fetch_sub(1) == 1)
            m_pObject->DeleteThis();
    }
};
}  // namespace fnv_00a5e780
typedef struct GlobalObject_00a7b610
{
    int data;
} GlobalObject_00a7b610;

GlobalObject_00a7b610 g_011c7d34;

struct FUN_004ee0d0_shell
{
    GlobalObject_00a7b610* GetGlobalObject();
};

// @fnv 0x004ee0d0
GlobalObject_00a7b610* FUN_004ee0d0_shell::GetGlobalObject()
{
    return &g_011c7d34;
}

struct BGSDecalNode
{
    BGSDecalNode();
    virtual ~BGSDecalNode();
    void* DestroyDecalNode(unsigned int);
};

// Calls FUN_004ee1e0 on this, frees the node with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004ee0e0
void* BGSDecalNode::DestroyDecalNode(unsigned int flags)
{
    reinterpret_cast<::FUN_004ee1e0 *>((this))->FUN_004ee1e0::~FUN_004ee1e0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xb4);
    return this;
}

namespace fnv_004ee4d0 {
struct NiAVObject;
struct NiNode
{
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
};
struct BGSDecalNode : NiNode
{
    virtual void FUN_004ee4d0(NiAVObject* apAVObj, bool abFirstAvailableSlot);
};

// @fnv 0x004ee4d0
void BGSDecalNode::FUN_004ee4d0(NiAVObject* apAVObj, bool abFirstAvailableSlot)
{
    reinterpret_cast<::fnv_00a5ed10::ChildNode *>(this)->FUN_00a5ed10((::fnv_00a5ed10::ChildObj *)(apAVObj), abFirstAvailableSlot);
}
}  // namespace fnv_004ee4d0

struct GO
{
    void* p;
    GO(std::intptr_t a);
    ~GO();
};
struct FUN_004ee5d0_shell
{
};
struct FUN_004ee560_shell
{
    void FUN_004ee560(std::intptr_t a);
};
struct PropHelper
{
};
struct EffectSetting
{
};
struct BSTempEffect
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
    virtual void* v38();
};
struct FUN_004ee450_shell
{
    void FUN_004ee450(BSTempEffect* apAVObj, bool abFirstAvailableSlot);
};
// @fnv 0x004ee450
void FUN_004ee450_shell::FUN_004ee450(BSTempEffect* apAVObj, bool abFlag)
{
    void* prop = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)apAVObj->v38())))->FUN_00a59d30(3)));
    if (prop != 0)
    {
        reinterpret_cast<::FUN_004ee4b0_shell *>((((EffectSetting*)prop)))->FUN_004ee4b0(1.0f);
    }
    reinterpret_cast<::fnv_00a5ed10::ChildNode *>(this)->FUN_00a5ed10((::fnv_00a5ed10::ChildObj *)(void *)(apAVObj->v38()), abFlag);
}

struct S1
{
};
struct S2
{
};
struct VirtParam
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
    virtual void* v38(void*);
};
struct TargetHost
{
    void CallVirtualAndForward(VirtParam*, void*);
};
struct BSSimpleList
{
};
struct DecalNode
{
    BSSimpleList* pList;
    void RemoveEffect(void* apEffect);
};
// @fnv 0x004ee560
void FUN_004ee560_shell::FUN_004ee560(std::intptr_t aiValue)
{
    GO g(0);
    reinterpret_cast<::TargetHost *>((((FUN_004ee5d0_shell*)this)))->CallVirtualAndForward((::VirtParam *)(aiValue), &g);
}
// Calls RemoveEffect with a, then calls FUN_00a5e780 with the result of a->v38(b).
// @fnv 0x004ee5d0
void TargetHost::CallVirtualAndForward(VirtParam* pVirtParam, void* b)
{
    reinterpret_cast<::DecalNode *>((((S1*)this)))->RemoveEffect(pVirtParam);
    reinterpret_cast<::fnv_00a5e780::NodeStandIn *>((((S2*)this)))->FUN_00a5e780((::fnv_00a5e780::RefObj *)(void *)(pVirtParam->v38(b)), ::ResultSlot<::fnv_00a5e780::RefPtr>());
}
// Removes the given effect from the list stored at offset 0xac of this node.
// @fnv 0x004ee4f0
void DecalNode::RemoveEffect(void* apEffect)
{
    GO tmp((std::intptr_t)apEffect);
    reinterpret_cast<::ListReader *>(((*(BSSimpleList**)((char*)this + 0xac))))->FUN_00631620((const ::NodeValue &)(tmp));
}

struct NiFixedString
{
};

struct NiAVObject
{
public:
    int IsVisualObject();
};

struct GlobalObject_004ee810
{
    int data[2];
    GlobalObject_004ee810();
};

struct FUN_004ee390_shell : NiAVObject
{
    unsigned char padding[0xac];
    GlobalObject_004ee810* pGlobalForm;
    unsigned char flag;

    void InitNameAndData();
};

NiFixedString const& FUN_004a2c60();
NiFixedString const& FUN_004ee440();

// Allocates a GlobalObject_004ee810 and sets the object's name from one of two fixed strings depending on flag.
// @fnv 0x004ee390
void FUN_004ee390_shell::InitNameAndData()
{
    pGlobalForm = new GlobalObject_004ee810;

    if (flag)
        ::AssignFixedString((char *)this, (std::intptr_t)&(FUN_004a2c60()), {});
    else
        ::AssignFixedString((char *)this, (std::intptr_t)&(FUN_004ee440()), {});
}

struct NiObject
{
};

struct CloningProcess
{
};

struct A51BF0Base : public NiObject
{
    char storage[0xb4];

};

struct FUN_004ee050 : public A51BF0Base
{
    FUN_004ee050();
};

struct FUN_004ee6f0_shell : public A51BF0Base
{
    NiObject* FUN_004ee6f0(CloningProcess& arCloneData);
};

extern int _data_011c16bc;

// Allocates and constructs a new FUN_004ee050 object and returns it as a NiObject pointer.
// @fnv 0x004ee6f0
NiObject* FUN_004ee6f0_shell::FUN_004ee6f0(CloningProcess& arCloneData)
{
    FUN_004ee050* pNewNode = new FUN_004ee050;
    return pNewNode;
}

struct Point3
{
    float x, y, z;
};
struct DecalBase
{
    DecalBase(int);
    virtual ~DecalBase();
};
struct Callback
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
    virtual void v55(void* object, int enabled);
};
struct FUN_004ee120;
struct EffectsList
{
    void FUN_005ae3d0(FUN_004ee120**);
};
extern EffectsList g_011c7d20;
struct FUN_004ee120 : DecalBase
{
    FUN_004ee120(Callback* callback, unsigned char flag);
    virtual ~FUN_004ee120();
};
// @fnv 0x004ee120
FUN_004ee120::FUN_004ee120(Callback* callback, unsigned char flag) : DecalBase(0)
{
    reinterpret_cast<unsigned char*>(this)[0xb0] = flag;
    reinterpret_cast<::FUN_004ee390_shell *>(this)->InitNameAndData();
    callback->v55(this, 1);

    Point3 vecOffset;
    new ((void *)&(vecOffset)) ::NiUpdateData(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((callback))->FUN_00a59c60((std::intptr_t)(&vecOffset));
    FUN_004ee120* pSelf = this;
    g_011c7d20.FUN_005ae3d0(&pSelf);
}

struct FUN_004ee610_view
{
};

struct FUN_004ee610_node
{
};

struct FUN_004ee610_cls
{
    unsigned char unk00[0xac];
    FUN_004ee610_node* m_ac;

    void FUN_004ee610(std::intptr_t a1);
};

// @fnv 0x004ee610
void FUN_004ee610_cls::FUN_004ee610(std::intptr_t a1)
{
    if (reinterpret_cast<::NiAVObject *>(this)->IsVisualObject())
    {
        FUN_004ee610_node* node = m_ac;
        while (node != 0 && !reinterpret_cast<::ObsList *>((node))->FUN_004a4460())
        {
            {
                GO local((std::intptr_t)((::BSTempEffect *)(::FUN_00559450((int *)(((::FUN_004ee610_view *)((void *)(node)))))))->v38());
                if (((::BSTempEffect *)(::FUN_00559450((int *)(reinterpret_cast<FUN_004ee610_view*>(&local))))))
                {
                    reinterpret_cast<::S_00a59e00 *>((reinterpret_cast<FUN_004ee610_view*>(((::BSTempEffect *)(::FUN_00559450((int *)(reinterpret_cast<FUN_004ee610_view*>(&local))))))))->FUN_00a59e00((::S_00a59e00_Arg *)(a1));
                }
                node = ((::FUN_004ee610_node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            }
        }
    }
}

struct DecalListNode
{
    void* vtable;
    DecalListNode* next;
    ~DecalListNode();
};
struct DecalListManager
{
    int unk00;
    DecalListNode* head;
    void FUN_006e5cc0(DecalListNode* node);
    void FUN_0066b0d0(int state);
    void PopHead();
};
// Removes the head node from the list, frees it, or calls FUN_0066b0d0(0) when the list is empty.
// @fnv 0x004ee8a0
void DecalListManager::PopHead()
{
    if (head != 0)
    {
        DecalListNode* node = head;
        head = node->next;
        FUN_006e5cc0(node);
        node->next = 0;
        delete node;
    }
    else
    {
        FUN_0066b0d0(0);
    }
}

namespace s4ee050 {

extern "C" const char DAT_01023734[];

class NodeBase
{
  public:
    NodeBase(unsigned short usChildren);
    ~NodeBase();

    const char* m_pVtbl;
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
    int unkb0;
};

struct NodeList
{
    void FUN_005ae3d0(NodeBase* const& pkNode);
};

extern NodeList DAT_011c7d20;

class TrackedNode : public NodeBase
{
  public:
    TrackedNode();

};

// @fnv 0x004ee050
TrackedNode::TrackedNode() : NodeBase(0)
{
    m_pVtbl = DAT_01023734;
    reinterpret_cast<::FUN_004ee390_shell *>(this)->InitNameAndData();
    DAT_011c7d20.FUN_005ae3d0(this);
}

}

#include "generated/data/fallout_shared/bgsdecalnode.inc"
