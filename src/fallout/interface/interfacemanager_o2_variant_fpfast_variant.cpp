
// src/fallout/interface/interfacemanager_o2_variant_fpfast_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /fp:fast (unit src/fallout/interface/interfacemanager_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/interfacemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/interfacemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_004a4020_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00a25560_Class.h"
#include "fnv/decl/MultiBoundOwner.h"
#include "fnv/decl/S00b5cd00_Owner.h"
#include "fnv/decl/S00b5eca0_Node.h"
#include "fnv/decl/SpawnedObject.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TextureOwner.h"
#include "fnv/decl/fnv_00b5d300__OwnerD.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_009f9000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00b5d000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "interfacemanager_packet.h"
extern "C" __declspec(dllimport) unsigned int __stdcall XInputGetState(unsigned int dwUserIndex, void* pState);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct NiBound
{
    float x, y, z;
    float radius;
};
struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (p)
                p->IncRefCount();
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};
struct Item : NiRefObject
{
    virtual void Unused2();
    virtual int IsVisibleThing();
    unsigned int u08, u0c, u10, u14, u18, u1c;
    NiBound* bound;
    unsigned int u24, u28, u2C, u30, u34, u38, u3C, u40;
    unsigned int u44, u48, u4C, u50, u54, u58, u5C, u60;
    unsigned int u64, u68, u6C, u70, u74, u78, u7C, u80;
    unsigned int u84, u88, u8C, u90, u94, u98, u9C, uA0;
    unsigned int uA4, uA8, uAC, uB0, uB4, uB8, uBC, uC0;
    unsigned int uC4, uC8, uCC, uD0, uD4, uD8, uDC, uE0;
    unsigned int uE4, uE8;
    bool flag_ec;
    unsigned int uF0, uF4, uF8;
    bool flag_fc;
    unsigned int u100, u104, u108;
    NiPointer<NiRefObject> field_10c;
};
template <class T> struct TListItem
{
    TListItem<T>* m_pkNext;
    TListItem<T>* m_pkPrev;
    T m_element;
};
template <class T> struct TPtrList
{
    TListItem<T>* m_pkHead;
    TListItem<T>* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((TListItem<T>*)pos)->m_element;
        pos = ((TListItem<T>*)pos)->m_pkNext;
        return e;
    }
    void RemoveAll();
};
struct BSTextureManager
{
};
struct Sub1e0
{
};
struct GlobalObject_0096a2d0
{
    void* owner;
    int count;
    void Unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
__forceinline NiBound* BoundOf(Item* i)
{
    NiBound* b = i->bound;
    return b ? b : &::g_defaultBound;
}
struct Owner
{
    unsigned int u0, u4, u8, uC, u10, u14, u18, u1C;
    unsigned int u20, u24, u28, u2C, u30, u34, u38, u3C;
    unsigned int u40, u44, u48, u4C, u50, u54, u58, u5C;
    unsigned int u60, u64, u68, u6C, u70, u74, u78, u7C;
    unsigned int u80, u84, u88, u8C, u90, u94, u98, u9C;
    unsigned int uA0, uA4, uA8, uAC, uB0, uB4, uB8, uBC;
    unsigned int uC0, uC4, uC8, uCC, uD0, uD4, uD8, uDC;
    unsigned int uE0;
    TPtrList<Item*> list0e4;
    TPtrList<Item*> list0f0;
    TPtrList<Item*> list0fc;
    TPtrList<Item*> list108;
    TPtrList<Item*> list114;
    unsigned int u120, u124, u128, u12C, u130, u134, u138, u13C;
    unsigned int u140, u144, u148, u14C, u150, u154, u158, u15C;
    unsigned int u160, u164, u168, u16C, u170, u174, u178, u17C;
    unsigned int u180, u184, u188, u18C, u190, u194, u198, u19C;
    unsigned int u1A0, u1A4, u1A8, u1AC, u1B0, u1B4, u1B8, u1BC;
    unsigned int u1C0, u1C4, u1C8, u1CC, u1D0, u1D4, u1D8, u1DC;
    Sub1e0* field_1e0;
    unsigned int u1E4, u1E8, u1EC, u1F0, u1F4, u1F8;
    bool flag_1fc;
    void FUN_00b5fd60();
};
// @fnv 0x00b5fd60
void Owner::FUN_00b5fd60()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::GlobalObject_0096a2d0 *>(&::fnv_00b5ddf0::DAT_011f9ea0))))->FUN_0040fbf0((char *)(0));
    void* pos = list0e4.GetHeadPos();
    while (pos)
    {
        Item* item = list0e4.GetNext(pos);
        if (item)
        {
            if (item->flag_ec)
                reinterpret_cast<::S00b5cd00_Owner *>(this)->FUN_00b5cd00((::S00b5cd00_Param *)(item));
            else
                reinterpret_cast<::S00b5eca0_Node *>(this)->FUN_00b5eca0((::ShadowSceneLight *)(item));
        }
    }
    pos = list0fc.GetHeadPos();
    while (pos)
    {
        Item* item = list0fc.GetNext(pos);
        if (item)
        {
            if (item->flag_fc)
                ::FUN_00b5d930((::OwnerD *)this, (int)(item), {});
            else
                reinterpret_cast<::fnv_00b5d300::OwnerD *>(this)->FUN_00b5d300((::fnv_00b5d300::LightD *)(item));
        }
    }
    pos = list0f0.GetHeadPos();
    while (pos)
    {
        Item* item = list0f0.GetNext(pos);
        if (item)
        {
            if (item->flag_ec)
            {
                NiPointer<Item> spItem = item;
                if (spItem)
                {
                    reinterpret_cast<::MultiBoundOwner *>((::DAT_011f91a8))->FUN_00b6d4c0((::BSMultiBound *)(::NiRefObject *)(spItem->field_10c));
                    spItem->field_10c = 0;
                    reinterpret_cast<::TextureOwner *>(this)->FUN_00b5ef90((const ::RefPtr_b9fcc0 &)(spItem));
                }
            }
            else
            {
                NiPointer<Item> spItem = item;
                reinterpret_cast<::TextureOwner *>(this)->FUN_00b5ef90((const ::RefPtr_b9fcc0 &)(spItem));
            }
        }
    }
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::GlobalObject_0096a2d0 *>(&::fnv_00b5ddf0::DAT_011f9ec0))))->FUN_0040fbf0((char *)(0));
    pos = list114.GetHeadPos();
    while (pos)
    {
        Item* item = list114.GetNext(pos);
        if (item)
        {
            if (item->IsVisibleThing() && BoundOf(item)->radius < DAT_010231d0)
                ::FUN_00b5dac0((::Obj5 *)(item), (::S5_C *)(::Owner *)(this), 1, true);
            else
                ::FUN_00b5dac0((::Obj5 *)(item), (::S5_C *)(::Owner *)(this), 1, false);
        }
    }
    pos = list108.GetHeadPos();
    while (pos)
    {
        Item* item = list108.GetNext(pos);
        if (item)
        {
            if (item->IsVisibleThing() && BoundOf(item)->radius < DAT_010231d0)
                ::FUN_00b5dac0((::Obj5 *)(item), (::S5_C *)(::Owner *)(this), 0, true);
            else
                ::FUN_00b5dac0((::Obj5 *)(item), (::S5_C *)(::Owner *)(this), 0, false);
        }
    }
    if (field_1e0)
        reinterpret_cast<::SpawnedObject *>((field_1e0))->FUN_00c5b8d0();
    list0e4.RemoveAll();
    list0f0.RemoveAll();
    list0fc.RemoveAll();
    list108.RemoveAll();
    list114.RemoveAll();
    flag_1fc = true;
    (*reinterpret_cast<::GlobalObject_0096a2d0 *>(&::fnv_00b5ddf0::DAT_011f9ec0)).Unlock();
    (*reinterpret_cast<::GlobalObject_0096a2d0 *>(&::fnv_00b5ddf0::DAT_011f9ea0)).Unlock();
}
