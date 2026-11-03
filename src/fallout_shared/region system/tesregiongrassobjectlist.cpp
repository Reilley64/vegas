
// src/fallout_shared/region system/tesregiongrassobjectlist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/region system/tesregiongrassobjectlist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00401000.h"
struct FUN_004f5df0_shell
{
    void __thiscall FUN_004f5e20();
    void* __thiscall Destroy(unsigned int flags);
};
struct ListX
{
    ~ListX();
};
struct FUN_004f5e20
{
    virtual ~FUN_004f5e20();
    ListX f4;
    void ClearList();
};
// @fnv 0x004f5df0
void* __thiscall FUN_004f5df0_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_004f5e20 *>(this)->FUN_004f5e20::~FUN_004f5e20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x004f5e20
FUN_004f5e20::~FUN_004f5e20()
{
    ClearList();
}

struct Actor
{
    void* p;
};

struct LH
{
    bool AddIfAbsent(Actor* item);
};

struct TESRegionGrassObject;
struct SoundListView
{
};
struct FUN_004f5ec0_shell
{
    unsigned int iCount;
    void AddGrassObject(TESRegionGrassObject* apObject);
};
// @fnv 0x004f5e80
bool LH::AddIfAbsent(Actor* apActor)
{
    if (!apActor || reinterpret_cast<::RefList *>((((LH*)((char*)this + 4))))->FUN_005f65d0((void **)&(apActor)))
        return false;
    reinterpret_cast<::FUN_004f5ec0_shell *>(this)->AddGrassObject((::TESRegionGrassObject *)(apActor));
    return true;
}
// Appends apObject to the list at offset 4 and increments the count at offset 0x10.
// @fnv 0x004f5ec0
void FUN_004f5ec0_shell::AddGrassObject(TESRegionGrassObject* apObject)
{
    reinterpret_cast<::Callees *>((reinterpret_cast<SoundListView*>(reinterpret_cast<char*>(this) + 4)))->FUN_00905820((void *)&(reinterpret_cast<char* const&>(apObject)));
    reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x10)[0]++;
}

struct FUN_004f16c0_src;

struct FUN_004f16c0_node
{
};

struct FUN_004f16c0_src
{
    int unk00;
    int unk04;
    FUN_004f16c0_node* m_08;
};

struct FUN_004f16c0_base
{
    int unk04;
    FUN_004f16c0_base(FUN_004f16c0_src* p);
    virtual ~FUN_004f16c0_base();
};

struct FUN_004f16c0 : FUN_004f16c0_base
{
    void* m_08;
    FUN_004f16c0(FUN_004f16c0_src* p);
    virtual ~FUN_004f16c0();
};

struct ListItemBase
{
    virtual void v0();
    virtual void v1();
    virtual int v2(int arg);
};

struct ListHeadStub
{
    void FUN_0063f7b0();
};

// @fnv 0x004f5ef0
void FUN_004f5e20::ClearList()
{
    ListItemBase* cur;
    ListItemBase* item;
    cur = *((::ListItemBase **)(new ((void *)(((ListHeadStub*)((char*)this + 4)))) ::Vec3()));
    while (cur != 0)
    {
        ((ListHeadStub*)((char*)this + 4))->FUN_0063f7b0();
        if (*((unsigned char*)this + 0xc) != 0)
        {
            ListItemBase* tmp;
            tmp = cur;
            item = tmp;
            (item != 0) ? item->v2(1) : 0;
        }
        cur = *((::ListItemBase **)(new ((void *)(((ListHeadStub*)((char*)this + 4)))) ::Vec3()));
    }
    *((unsigned int*)((char*)this + 0x10)) = 0;
}


struct FUN_004f5f80_obj
{
    virtual void unk00();
    virtual int unk04();
    virtual void unk08();
    virtual int unk0c();
};

struct ListNodeX
{
};

struct IntOpsX
{
};

struct FUN_004f5f80_cls
{
    FUN_004f5f80_obj* __thiscall FUN_004f5f80(int a1, int a2);
};

// Walks the list from this+4 and returns the first object whose unk04 equals a1 and whose unk0c matches a2 (or is null when a2 < 0).
// @fnv 0x004f5f80
FUN_004f5f80_obj* FUN_004f5f80_cls::FUN_004f5f80(int a1, int a2)
{
    ListNodeX* it9 = (char*)this != 0 ? (ListNodeX*)((char*)this + 4) : 0;
    FUN_004f5f80_obj* result = 0;
    FUN_004f5f80_obj* obj;
    while (it9 != 0 && *((void **)(new ((void *)(it9)) ::Vec3())) != 0)
    {
        obj = (FUN_004f5f80_obj*)*((void **)(new ((void *)(it9)) ::Vec3()));
        if (reinterpret_cast<::FUN_0084e3a0_Class *>((((IntOpsX*)(int)obj->unk04())))->FUN_0084e3a0() == a1 &&
            ((a2 >= 0 && obj->unk0c() != 0 && reinterpret_cast<::FUN_0084e3a0_Class *>((((IntOpsX*)(int)obj->unk0c())))->FUN_0084e3a0() == a2) ||
             (a2 < 0 && obj->unk0c() == 0)))
        {
            result = obj;
            break;
        }
        it9 = ((::ListNodeX *)(reinterpret_cast<::Callees *>((it9))->FUN_00726070()));
    }
    return result;
}

struct VItem
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Actor* v5(int arg);
};

struct VDel
{
    virtual void v0();
    virtual void v1();
    virtual ~VDel();
};

struct TargetList
{
    virtual ~TargetList();
    int unk04;
    int unk08;
    unsigned char unk0c;
    int unk10;
    TargetList(unsigned char flag);
};

struct Controller
{
    int unk00;
    ListNodeX list;
    int unk08;
    unsigned char unk0c;

    TargetList* CopyTargetList(TargetList* param_1);
};
// Initializes the base from p and stores the object returned by p->m_08->Make(0) in m_08.
// @fnv 0x004f16c0
FUN_004f16c0::FUN_004f16c0(FUN_004f16c0_src* apSource) : FUN_004f16c0_base(apSource)
{
    m_08 = ((void *)(reinterpret_cast<::Controller *>((apSource->m_08))->CopyTargetList((::TargetList *)(0))));
}

// @fnv 0x004f6060
TargetList* Controller::CopyTargetList(TargetList* apTargetList)
{
    ListNodeX* iter = this ? &list : 0;
    TargetList* result = apTargetList ? apTargetList : new TargetList(unk0c);
    Actor* actor2 = 0;

    while (iter != 0 && *((void **)(new ((void *)(iter)) ::Vec3())) != 0)
    {
        if (result->unk0c != 0)
        {
            actor2 = ((VItem*)*((void **)(new ((void *)(iter)) ::Vec3())))->v5(0);
            if (!((LH*)result)->AddIfAbsent(actor2))
            {
                delete (VDel*)actor2;
            }
        }
        else
        {
            ((LH*)result)->AddIfAbsent((Actor*)*((void **)(new ((void *)(iter)) ::Vec3())));
        }
        iter = ((::ListNodeX *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
    }
    return result;
}
