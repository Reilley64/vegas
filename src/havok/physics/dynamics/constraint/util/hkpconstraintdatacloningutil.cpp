
// src/havok/physics/dynamics/constraint/util/hkpconstraintdatacloningutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/util/hkpconstraintdatacloningutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/FUN_00cb9090.h"
#include "fnv/decl/FUN_00cdf2f0.h"
#include "fnv/decl/FUN_00cdf6d0_t.h"
#include "fnv/decl/FUN_00cdf710.h"
#include "fnv/decl/FUN_00d4fe80.h"
#include "fnv/decl/FUN_00d85a20_Stub.h"
#include "fnv/decl/ObjD85.h"
#include "fnv/decl/S_00d85af0_Cls.h"
#include "fnv/decl/fnv_00d4df30__FUN_00d4df30.h"
#include "fnv/decl/fnv_00dee6f0__FUN_00dee6f0_class.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00d85000.h"
struct Allocator858
{
    virtual void v00();
    virtual void* Allocate(unsigned int uiSize);
};
struct Heap858
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator858* m_pHeapAllocator;

    void* Allocate(unsigned int uiSize)
    {
        return m_pHeapAllocator->Allocate(uiSize);
    }
};


struct Clonable858
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Clonable858* Clone();
};

struct Object858
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int GetType();
    unsigned short usSize;
    unsigned short usFlags;
    int iValue;
    int unk0c;
};

struct Payload858
{
};

struct Type7Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xe0 - 0x11];
    Clonable858* apkChildren[3];
};
struct Type6Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xac - 0x11];
    Clonable858* pkChild;
};
struct Type2Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xb0 - 0x11];
    Clonable858* pkChild;
};

struct Raw858
{
};

inline Raw858* Allocate858(unsigned int uiSize)
{
    Object858* pkObject = (Object858*)static_cast<Heap858*>(::FUN_00c85750())->Allocate(uiSize);
    pkObject->usSize = (unsigned short)uiSize;
    return (Raw858*)pkObject;
}

// Allocates a new object matching pkSource's type (7, 6 or 2), copies its payload and iValue, clones child pointers, and returns it or 0.
// @fnv 0x00d858f0
Object858* __cdecl FUN_00d858f0(Object858* pkSource)
{
    switch (pkSource->GetType())
    {
    case 7: {
        Type7Object858* pkResult = ((::Type7Object858 *)(new ((void *)(Allocate858(0x140))) ::FUN_00cdf2f0()));
        reinterpret_cast<::ObjD85 *>(&(pkResult->kPayload))->FUN_00d85ba0((*(const ::ObjD85 *)(&((Type7Object858*)pkSource)->kPayload)));
        pkResult->iValue = pkSource->iValue;
        Clonable858** ppkChildren = pkResult->apkChildren;
        for (int i = 0; i < 3; i++)
        {
            if (ppkChildren[i])
                ppkChildren[i] = ppkChildren[i]->Clone();
        }
        return pkResult;
    }
    case 6: {
        Type6Object858* pkResult = ((::Type6Object858 *)(new ((void *)(Allocate858(0xd0))) ::FUN_00d4fe80()));
        reinterpret_cast<::S_00d85af0_Cls *>(&(pkResult->kPayload))->AssignFrom((const ::S_00d85af0_Cls *)(const ::Payload858 *)(&((Type6Object858*)pkSource)->kPayload));
        pkResult->iValue = pkSource->iValue;
        Clonable858*& rpkChild = pkResult->pkChild;
        if (rpkChild)
            rpkChild = rpkChild->Clone();
        return pkResult;
    }
    case 2: {
        Type2Object858* pkResult = ((::Type2Object858 *)(new ((void *)(Allocate858(0xe0))) ::FUN_00cb9090()));
        reinterpret_cast<::FUN_00d85a20_Stub *>(&(pkResult->kPayload))->CopyStateFrom((int *)(&((Type2Object858*)pkSource)->kPayload));
        pkResult->iValue = pkSource->iValue;
        Clonable858*& rpkChild = pkResult->pkChild;
        if (rpkChild)
            rpkChild = rpkChild->Clone();
        return pkResult;
    }
    }
    return 0;
}

struct hkRefObj858
{
};
struct Heap858b
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator858* m_pHeapAllocator;
    Allocator858& heap()
    {
        return *m_pHeapAllocator;
    }
};
template <class T> __forceinline T* AllocA(unsigned int uiSize)
{
    Object858* p = (Object858*)((Heap858b*)static_cast<Heap858*>(::FUN_00c85750()))->heap().Allocate(uiSize);
    p->usSize = (unsigned short)uiSize;
    return (T*)p;
}
struct Node858 : Object858
{
    int unk10;
    int unk14;
    Object858* pkChild;
    float unk1c;
};
struct Breakable858 : Object858
{
    int unk10;
    int unk14;
    Object858* m_pConstraintData;
    int unk1c;
    float m_fBreakingStrength;
    unsigned char m_bRemoveWhenBroken;
    unsigned char m_bRevertBackVelocityOnBreak;
    Object858* GetBreakableObject() const
    {
        return m_pConstraintData;
    }
    float getThreshold() const
    {
        return m_fBreakingStrength;
    }
    void setThreshold(float t)
    {
        m_fBreakingStrength = t;
    }
    unsigned char getRemoveWhenBroken() const
    {
        return m_bRemoveWhenBroken;
    }
    void setRemoveWhenBroken(unsigned char b)
    {
        m_bRemoveWhenBroken = b;
    }
    unsigned char getRevertBackVelocityOnBreak() const
    {
        return m_bRevertBackVelocityOnBreak;
    }
    void setRevertBackVelocityOnBreak(unsigned char b)
    {
        m_bRevertBackVelocityOnBreak = b;
    }
};
struct Kind3Shape858
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual hkRefObj858* GetChildShape();
};
struct Kind3Result858
{
};
struct Raw858b
{
};

// Dispatches on pkSource->GetType() to clone the object, recursively cloning child nodes and copying breakable properties.
// @fnv 0x00d85700
Object858* __cdecl FUN_00d85700(Object858* pkSource)
{
    switch (pkSource->GetType())
    {
    case 0:
        return ((::Object858 *)(::FUN_00d85360((int)(pkSource))));
    case 1:
        return ((::Object858 *)(::fnv_00d853a0::FUN_00d853a0((int)(pkSource))));
    case 2:
        return ((::Object858 *)(::fnv_00d853f0::FUN_00d853f0((char *)(pkSource))));
    case 3: {
        Object858* pkResult = ((::Object858 *)(::fnv_00d85440::CloneShape((const ::fnv_00d85440::D85440Shape *)(pkSource))));
        Kind3Shape858* pkChild = (Kind3Shape858*)((Node858*)pkSource)->pkChild;
        hkRefObj858* pkShape = pkChild->GetChildShape();
        reinterpret_cast<::fnv_00dee6f0::FUN_00dee6f0_class *>((((Kind3Result858*)pkResult)))->FUN_00dee6f0((::fnv_00dee6f0::RefObj *)(pkChild));
        reinterpret_cast<::hkReferencedObjectC905 *>((pkShape))->FUN_00c905b0();
        return pkResult;
    }
    case 6:
        return ((::Object858 *)(::fnv_00d85490::CloneAllocatedObject((int *)(pkSource))));
    case 7:
        return ((::Object858 *)(::fnv_00d854e0::CloneStub((::fnv_00d854e0::Src_Stub *)(pkSource))));
    case 8:
        return ((::Object858 *)(::fnv_00d85530::FUN_00d85530((::fnv_00d85530::SpawnedSource *)(pkSource))));
    case 9:
        return ((::Object858 *)(::fnv_00d85570::CloneWithInit((int)(pkSource))));
    case 14:
        return ((::Object858 *)(::fnv_00d855c0::CloneDataBlock(pkSource)));
    case 15:
        return ((::Object858 *)(::fnv_00d85610::CloneWithCopiedPayload((int)(pkSource))));
    case 18:
        return ((::Object858 *)(::FUN_00d85660((const ::D85660Object *)(pkSource))));
    case 19:
        return ((::Object858 *)(::fnv_00d856b0::CloneWithAllocatedCopy((int)(pkSource))));
    case 12: {
        Breakable858* pkOld = (Breakable858*)pkSource;
        Object858* pkChild = FUN_00d85700(pkOld->GetBreakableObject());
        if (!pkChild)
            return 0;
        Breakable858* pkNew = ((::Breakable858 *)(new ((void *)(AllocA<Raw858b>(0x28))) ::fnv_00d4df30::FUN_00d4df30((::fnv_00d4df30::hkpConstraintDataD4D *)(pkChild))));
        reinterpret_cast<::hkReferencedObjectC905 *>((((hkRefObj858*)pkChild)))->FUN_00c905b0();
        pkNew->m_fBreakingStrength = pkOld->m_fBreakingStrength;
        pkNew->m_bRemoveWhenBroken = pkOld->m_bRemoveWhenBroken;
        pkNew->m_bRevertBackVelocityOnBreak = pkOld->m_bRevertBackVelocityOnBreak;
        pkNew->iValue = pkOld->iValue;
        return pkNew;
    }
    case 13: {
        Node858* pkNode = (Node858*)pkSource;
        Object858* pkChild = FUN_00d85700(((::Object858 *)(reinterpret_cast<::FUN_00cdf6d0_t *>((pkNode))->FUN_00cdf6d0())));
        if (!pkChild)
            return 0;
        Node858* pkClone = ((::Node858 *)(new ((void *)(AllocA<Raw858b>(0x20))) ::FUN_00cdf710((::hkReferencedObjectCDF7 *)(pkChild))));
        reinterpret_cast<::hkReferencedObjectC905 *>((((hkRefObj858*)pkChild)))->FUN_00c905b0();
        pkClone->unk1c = pkNode->unk1c;
        pkClone->iValue = pkNode->iValue;
        return pkClone;
    }
    }
    return 0;
}
