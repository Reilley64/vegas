
// src/havok/common/base/reflection/hkclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/ClassMember_d869.h"
#include "fnv/decl/D60590Object.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00d60830.h"
#include "fnv/decl/FUN_00d86930_StandIn.h"
#include "fnv/decl/FnvCpu_FUN_00d46ef0_CpuObject.h"
#include "fnv/decl/Struct_d86920.h"
#include "fnv/decl/TargetClass.h"
#include "fnv/decl/hkClassEnum.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d46000.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_00d86000.h"
#include "fnv/symbols_00e03000.h"
#include "havok/hkClass.h"

struct FUN_00d46f80_class
{
    void* FUN_00d46f80(int i) const;
};

// @fnv 0x00d46f80
void* FUN_00d46f80_class::FUN_00d46f80(int aiIndex) const
{
    return (void*)((const char*)*(const void**)(this + 0x18) + aiIndex * 24);
}

struct FUN_00d46cf0_obj
{
};

struct FUN_00d47260_cls
{
    char pad[0x24];
    FUN_00d46cf0_obj* m_pCustomAttributes;
    void* FUN_00d47260(const char* name) const;
};

struct FUN_00d472a0
{
    unsigned int m[11];
    FUN_00d472a0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f,
                 unsigned int g, unsigned int h, unsigned int i, unsigned int j, unsigned int k, unsigned int l,
                 unsigned int n);
};

// @fnv 0x00d472a0
FUN_00d472a0::FUN_00d472a0(unsigned int auiValue0, unsigned int auiValue1, unsigned int auiValue2,
                           unsigned int auiUnused, unsigned int auiValue3, unsigned int auiValue4,
                           unsigned int auiValue5, unsigned int auiValue6, unsigned int auiValue7,
                           unsigned int auiValue8, unsigned int auiValue9, unsigned int auiValue10,
                           unsigned int auiValue11)
{
    m[0] = auiValue0;
    m[1] = auiValue1;
    m[2] = auiValue2;
    m[3] = auiValue3;
    m[4] = auiValue4;
    m[5] = auiValue5;
    m[6] = auiValue6;
    m[7] = auiValue7;
    m[8] = auiValue8;
    m[9] = auiValue9;
    m[10] = auiValue10;
    m[11] = auiValue11;
}

struct FUN_00d46f00_s
{
    unsigned int m_uiCount;
    FUN_00d46f00_s* m_parent;
    unsigned int FUN_00d46f00() const;
};

// @fnv 0x00d46f00
unsigned int FUN_00d46f00_s::FUN_00d46f00() const
{
    FUN_00d46f00_s* cls = m_parent;
    unsigned int total = *(unsigned int*)((char*)this + 0x1c);
    while (cls)
    {
        total += *(unsigned int*)((char*)cls + 0x1c);
        cls = cls->m_parent;
    }
    return total;
}

struct TypeNode
{
    int FUN_00d46f70(void);
};
struct Container
{
    intptr_t FindMemberByName(const char* name) const;
};


int __cdecl FUN_00d46f20(void);

struct FUN_00d46f00_Class
{
};

struct FUN_00d46fe0_Class
{
    int* FUN_00d46f20(int i);
    int* FUN_00d46fe0(const int* name);
};

namespace fnv_00d47080 {

struct TypeNode
{
    int FUN_00d46f70(void) const;
};

struct Container
{
    int FUN_00d46f70(void) const;
    int FindIndexByName(const char* name);
};

// Scans entries by index, comparing each entry's name string to name, and returns the first matching index or -1.
// @fnv 0x00d47080
int Container::FindIndexByName(const char* name)
{
    int i = 0;
    if (FUN_00d46f70() > 0)
    {
        do
        {
            if (::fnv_00cb0fa0::FUN_00cb0fa0(*(const char**)reinterpret_cast<::FUN_00d46f80_class *>((void *)this)->FUN_00d46f80(i), name) == 0)
                return i;
            ++i;
        } while (i < FUN_00d46f70());
    }
    return -1;
}
}  // namespace fnv_00d47080

struct FUN_00d471a0_class
{
    char pad[0x20];
    int* m_iSlotIds;
    int FUN_00d471a0(int i) const;
};
// @fnv 0x00d471a0
int FUN_00d471a0_class::FUN_00d471a0(int aiIndex) const
{
    if (m_iSlotIds && m_iSlotIds[aiIndex] >= 0)
        return 1;
    return 0;
}

struct FUN_00d46fe0_result
{
    unsigned char pad[0x12];
    unsigned short m_bitOffset;
};

struct FUN_00d46fe0_class
{
};

struct FUN_00d87150_class
{
    int m_offset;
    FUN_00d46fe0_result* m_kMemberDescriptor;

    void InitBitOffset(intptr_t baseOffset, FUN_00d46fe0_class* cls, const char* name);
};

// Looks up name via cls, stores the result, and sets m_offset to baseOffset plus the result's m_bitOffset when found.
// @fnv 0x00d87150
void FUN_00d87150_class::InitBitOffset(intptr_t baseOffset, FUN_00d46fe0_class* apClass, const char* name)
{
    m_offset = 0;
    m_kMemberDescriptor = ((::FUN_00d46fe0_result *)(reinterpret_cast<::FUN_00d46fe0_Class *>((void *)(apClass))->FUN_00d46fe0((const int *)(name))));
    if (m_kMemberDescriptor)
        m_offset = baseOffset + m_kMemberDescriptor->m_bitOffset;
}

struct FUN_00d470e0_Class
{
    virtual void vf00();
    int unk04;
    int unk08;
    void FUN_00d470e0(int value);
};

// @fnv 0x00d470e0
void FUN_00d470e0_Class::FUN_00d470e0(int value)
{
    this->unk08 = value;
}

// 00d46d40: trivial getter returning the first dword of the object
// (m_name at offset 0 of the Havok class node).
struct FnvClassNameNode
{
    char* m_name;
    char* FUN_00d46d40() const;
};

// @fnv 0x00d46d40
char* FnvClassNameNode::FUN_00d46d40() const
{
    return m_name;
}

struct ReflectObj
{
    void* unk00;
    void* unk04;
    void* FUN_00d46d50();
};
// @fnv 0x00d46d50
void* ReflectObj::FUN_00d46d50()
{
    return unk04;
}

struct FUN_00d46f60_Class
{
    void* FUN_00d46f20(int a1);
    void* FUN_00d46f60(int a1);
};

// declared-members array (offset 0x1c inside hkClass).
struct FUN_00d46f70_cls
{
    char* m_name;
    hkClass* m_parent;
    hkInt32 m_iObjectSize;
    hkInt32 m_iNumImplementedInterfaces;
    hkSimpleArray<hkClassEnum> m_kDeclaredEnums;
    hkSimpleArray<hkClassMember> m_kDeclaredMembers;

    int FUN_00d46f70(void);
};
// Scans the container's members by index and returns the first whose name matches the given string, or 0 if none match.
// @fnv 0x00d46f90
intptr_t Container::FindMemberByName(const char* name) const
{
    Container* self = const_cast<Container*>(this);
    TypeNode* node = reinterpret_cast<TypeNode*>(self);
    int i = 0;
    if (reinterpret_cast<::FUN_00d46f70_cls *>((node))->FUN_00d46f70() > 0)
    {
        do
        {
            void* member = reinterpret_cast<::FUN_00d46f80_class *>((void *)(self))->FUN_00d46f80(i);
            const char* pcMemberName = *reinterpret_cast<const char**>(member);
            if (!::fnv_00cb0fa0::FUN_00cb0fa0(pcMemberName, name))
                return reinterpret_cast<intptr_t>(member);
            ++i;
        } while (i < reinterpret_cast<::FUN_00d46f70_cls *>((node))->FUN_00d46f70());
    }
    return 0;
}

// @fnv 0x00d46f70
int FUN_00d46f70_cls::FUN_00d46f70(void)
{
    return m_kDeclaredMembers.m_iElementCount;
}

struct FnvCpu_FUN_00d470d0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int FUN_00d470d0();
};
// @fnv 0x00d470d0
int FnvCpu_FUN_00d470d0_CpuObject::FUN_00d470d0()
{
    return value;
}

// FUN_00d47120: 4-byte inline getter, , reads this+0x2C.
// Neighbours use hkClass layout (m_parent@0x04, declaredMembers@0x18, defaults@0x20,
// sizeof == 0x30), so +0x2C is m_iDescribedVersion.

struct hkClassD47120 : hkClass
{
    int FUN_00d47120() const;
};

// @fnv 0x00d47120
int hkClassD47120::FUN_00d47120() const
{
    return m_iDescribedVersion;
}

enum hkResultD472
{
    HK_SUCCESS_D472 = 0,
    HK_FAILURE_D472 = 1
};

class hkStreamWriterD472
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int write(const void* buf, int nbytes);
};

struct hkItemD472
{
    int unk00[6];
};

class hkPackfileD472
{
  public:
    int unk00[6];
    hkItemD472* m_items;
    int unk1C;
    int* m_offsets;

    bool getName(int index, const char*& name) const
    {
        if (m_offsets)
        {
            int off = m_offsets[index];
            if (off >= 0)
            {
                name = (const char*)m_offsets + off;
                return true;
            }
        }
        return false;
    }
    hkResultD472 WriteItemName(int index, hkStreamWriterD472* writer);
};

// Looks up the item name at index and writes it to the stream writer, returning success or failure.
// @fnv 0x00d47210
hkResultD472 hkPackfileD472::WriteItemName(int index, hkStreamWriterD472* writer)
{
    const char* name;
    if (getName(index, name))
    {
        writer->write(name, reinterpret_cast<::ClassMember_d869 *>((void *)&(m_items[index]))->FUN_00d86980());
        return HK_SUCCESS_D472;
    }
    return HK_FAILURE_D472;
}

struct hkNamedEntryD473
{
    intptr_t m_name;
};

class hkEntryListD473
{
  public:

    hkNamedEntryD473* FUN_00d47300(intptr_t iName);
};

// Scans the entry list and returns the first entry whose m_name matches iName, or null if none matches.
// @fnv 0x00d47300
hkNamedEntryD473* hkEntryListD473::FUN_00d47300(intptr_t iName)
{
    for (int i = 0; i < reinterpret_cast<::FnvCpu_FUN_00d46ef0_CpuObject *>((void *)this)->FUN_00d46ef0(); i++)
    {
        hkNamedEntryD473* pkEntry = ((::hkNamedEntryD473 *)(::GetEntryAt((char *)this, i, {})));
        if (::fnv_00cb0fa0::FUN_00cb0fa0((const char *)(pkEntry->m_name), (const char *)(iName)) == 0)
            return pkEntry;
    }
    return 0;
}

struct SmallFlag
{
    unsigned char v;
    SmallFlag(bool flag) : v(flag ? 1 : 0)
    {}
    SmallFlag(const SmallFlag& rhs) : v(rhs.v)
    {}
};
struct Archive
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct EnumRec
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
};
struct Prop
{
    unsigned int unk00, unk04;
    unsigned short m_iElementCount;
};
struct ClassRec;
struct MemberRec
{
    const char* m_name;
    ClassRec* m_class;
    EnumRec* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    unsigned short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_pCustomAttributes;
};
struct ClassRec
{
    const char* m_name;
    ClassRec* m_parent;
    int m_iElementCount;
    int m_numInterfaces;
    EnumRec* m_pEnums;
    int m_numEnums;
    MemberRec* m_members;
    int m_numMembers;
    ClassRec* FUN_00d46d50() const;
    void WriteToStream(void* stream) const;
};
// @fnv 0x00d47490
void ClassRec::WriteToStream(void* stream) const
{
    Archive out;
    new ((void *)&(out)) ::FUN_00d60830((::hkReferencedObject *)(stream), (*(char *)&(const ::SmallFlag &)(SmallFlag(false))));
    reinterpret_cast<::hkOArchive_2 *>(&(out))->WriteInt(m_numInterfaces);
    for (int enumIndex = 0; enumIndex < m_numEnums; ++enumIndex)
    {
        reinterpret_cast<::hkClassEnum *>(&(m_pEnums[enumIndex]))->FUN_00db7600((::hkStreamWriter *)(stream));
    }
    reinterpret_cast<::hkOArchive_2 *>(&(out))->WriteInt(m_numEnums);
    for (int memberIndex = 0; memberIndex < m_numMembers; ++memberIndex)
    {
        const MemberRec& member = m_members[memberIndex];
        MemberRec info = member;
        if (info.m_type == 0x18 || info.m_type == 0x1f)
        {
            unsigned short typeWidth = ((::Prop *)(::FUN_00d868a0(info.m_eSubtype)))->m_iElementCount;
            info.m_flags ^= typeWidth * 8;
            info.m_eSubtype = 0;
        }
        unsigned short altType = 0;
        if (info.m_flags & 0x400)
        {
            info.m_flags ^= 0x400;
            if (info.m_eSubtype != 0)
                altType = info.m_eSubtype;
            info.m_eSubtype = info.m_type;
            info.m_type = 0x13;
        }
        if (info.m_class && member.m_type != 0x14 && member.m_eSubtype != 0x14)
        {
            ClassRec* parentClass = ((::ClassRec *)(reinterpret_cast<::Struct_d86920 *>((void *)&(member))->FUN_00d86920()));
            while (parentClass)
            {
                parentClass->WriteToStream(stream);
                parentClass = ((::ClassRec *)(reinterpret_cast<::ReflectObj *>((void *)(parentClass))->FUN_00d46d50()));
            }
        }
        if (info.m_pClassEnum)
            reinterpret_cast<::hkClassEnum *>((((::EnumRec *)(reinterpret_cast<::FUN_00d86930_StandIn *>((void *)&(member))->FUN_00d86930()))))->FUN_00db7600((::hkStreamWriter *)(stream));
        reinterpret_cast<::FUN_00d607b0_class *>(&(out))->FUN_00d607b0((intptr_t)(info.m_name));
        ::FUN_00d60900((char *)&(out));
        ::FUN_00d60900((char *)&(out));
        if (altType != 0)
            ::FUN_00d60900((char *)&(out));
        ::FUN_00d60900((char *)&(out));
        ::FUN_00d60900((char *)&(out));
    }
    reinterpret_cast<::hkOArchive_2 *>(&(out))->WriteInt(m_numMembers);
    reinterpret_cast<::D60590Object *>(&(out))->FUN_00d60590();
}

struct FUN_00db7870
{
    void* vfptr;
    int unk04;
    int unk08;
    FUN_00db7870(int);
};

struct FUN_00d47690_class
{
    FUN_00d47690_class* FUN_00d46d50() const;
    unsigned int ComputeSignature(int signatureFlags) const;
};

// Computes a CRC over this class and, unless SIGNATURE_LOCAL is set, over its parent chain, returning the CRC value.
// @fnv 0x00d47690
unsigned int FUN_00d47690_class::ComputeSignature(int signatureFlags) const
{
    FUN_00db7870 crc(0);
    bool recurse = !(signatureFlags & hkClass::SIGNATURE_LOCAL);
    for (const FUN_00d47690_class* c = this; c;)
    {
        reinterpret_cast<::ClassRec *>((void *)(c))->WriteToStream(&crc);
        if (!recurse)
        {
            break;
        }
        c = ((::FUN_00d47690_class *)(reinterpret_cast<::ReflectObj *>((void *)(c))->FUN_00d46d50()));
    }
    return ((unsigned int)(reinterpret_cast<::TargetClass *>(&(crc))->FUN_00db7860()));
}

struct hkTypeInfoD476
{
    int unk00;
    int unk04;
    short m_iElementCount;
};


struct hkVariantD476
{
    const void* m_type;
    int unk04;
    int unk08;
    int unk0C;
    char m_data[0x40];

    int SetData(const void* src, const void* type);
};

// Looks up the type info for type, and if its size is at most 0x40, stores type and copies that many bytes from src into m_data, returning 0; otherwise returns 1.
// @fnv 0x00d476e0
int hkVariantD476::SetData(const void* src, const void* type)
{
    hkTypeInfoD476* info = ((::hkTypeInfoD476 *)(::FUN_00d868a0((intptr_t)(type))));
    if ((unsigned short)info->m_iElementCount <= 0x40)
    {
        m_type = type;
        ::FUN_00cb1260(m_data, src, info->m_iElementCount);
        return 0;
    }
    return 1;
}

struct FUN_00d86b30_class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned int FUN_00d86b30();
};

// @fnv 0x00d86b30
unsigned int FUN_00d86b30_class::FUN_00d86b30()
{
    return unk0D;
}


struct EntryD46C
{
    const char* m_pcName;
    int m_uiFilterValue[2];
};

class FUN_00d46cf0_C
{
  public:
    EntryD46C* m_data;
    int m_iElementCount;

    void* FindEntry(const char* pcName);
};
// @fnv 0x00d47260
void* FUN_00d47260_cls::FUN_00d47260(const char* name) const
{
    if (m_pCustomAttributes)
        return reinterpret_cast<::FUN_00d46cf0_C *>((void *)(m_pCustomAttributes))->FindEntry(name);
    return 0;
}

// @fnv 0x00d46cf0
void* FUN_00d46cf0_C::FindEntry(const char* pcName)
{
    for (int i = 0; i < m_iElementCount; i++)
    {
        if (::fnv_00cb0fa0::FUN_00cb0fa0(m_data[i].m_pcName, pcName) == 0)
            return &m_data[i].m_uiFilterValue;
    }
    return 0;
}

struct HkMem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct HkClassNode
{
    int unk00;
    HkClassNode* m_parent;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    HkMem* m_members;
    int m_uiCount;
    int FUN_00d46f00();
    HkMem* FUN_00d46f20(int i);
};
// Scans entries by index and returns the first whose first field matches name via FUN_00cb0fa0, or 0 if none match.
// @fnv 0x00d46fe0
int* FUN_00d46fe0_Class::FUN_00d46fe0(const int* name)
{
    for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00d46f00_s *>(this)->FUN_00d46f00())); i++)
    {
        int* m = ((int *)(reinterpret_cast<::HkClassNode *>(this)->FUN_00d46f20(i)));
        if (::fnv_00cb0fa0::FUN_00cb0fa0((const char *)(m[0]), (const char *)((intptr_t)name)) == 0)
            return m;
    }
    return 0;
}
// @fnv 0x00d46f60
void* FUN_00d46f60_Class::FUN_00d46f60(int a1)
{
    return ((void *)(reinterpret_cast<::HkClassNode *>(this)->FUN_00d46f20(a1)));
}

__declspec(noinline) int HkClassNode::FUN_00d46f00()
{
    HkClassNode* p = m_parent;
    int total = m_uiCount;
    if (p != 0)
    {
        do
        {
            total += p->m_uiCount;
            p = p->m_parent;
        } while (p != 0);
    }
    return total;
}

// Resolves a global member index i by walking up the HkClassNode parent chain and returning the matching HkMem entry from m_members.
// @fnv 0x00d46f20
HkMem* HkClassNode::FUN_00d46f20(int aiIndex)
{
    HkClassNode* pNode = this;
    int iOffset = aiIndex - ((int)(reinterpret_cast<::FUN_00d46f00_s *>(this)->FUN_00d46f00()));
    if (this != 0)
    {
        do
        {
            iOffset += pNode->m_uiCount;
            if (iOffset >= 0)
                return pNode->m_members + iOffset;
            pNode = pNode->m_parent;
        } while (pNode != 0);
    }
    return this->m_members;
}


struct hkItemD470
{
    const char* m_name;
    int m_uiFilterValue;
};

class hkClassEnumD470
{
  public:
    const hkItemD470& FUN_00d46f20(int i) const;

    int FUN_00d47030(const char* name) const;
};

// Linearly searches the enum items for one whose m_name matches name and returns its index, or -1 if not found.
// @fnv 0x00d47030
int hkClassEnumD470::FUN_00d47030(const char* name) const
{
    for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00d46f00_s *>((void *)this)->FUN_00d46f00())); i++)
    {
        if (::fnv_00cb0fa0::FUN_00cb0fa0((*(const ::hkItemD470 *)(reinterpret_cast<::HkClassNode *>((void *)this)->FUN_00d46f20(i))).m_name, name) == 0)
            return i;
    }
    return -1;
}

struct ZN0d46d50
{
    void* unk00;
    ZN0d46d50* m_parent;
    int unk08;
    int unk0c;
};

static __declspec(noinline) ZN0d46d50* FUN_00d46d50(ZN0d46d50* node)
{
    return node->m_parent;
}

class ResultPtr
{
  public:
    char* p;
    ResultPtr(char* pp) : p(pp)
    {}
};

// Follows parent links, updating lastNode, then writes whether lastNode->unk0c is non-zero through out.p.
// @fnv 0x00d470f0
static __declspec(noinline) char* GetLastNodeFlag(ZN0d46d50* apStartNode, ZN0d46d50* lastNode, ResultPtr out)
{
    ZN0d46d50* next = FUN_00d46d50(apStartNode);
    while (next)
    {
        lastNode = next;
        apStartNode = next;
        next = FUN_00d46d50(apStartNode);
    }
    char* dst = out.p;
    *dst = (lastNode->unk0c != 0);
    return dst;
}

static volatile int g_pad;
static volatile char* g_charptr;
void ZNegotiate(ZN0d46d50* n)
{
    g_charptr = GetLastNodeFlag(n, n, ResultPtr((char*)&g_pad));
}

struct FUN_00d86980_class
{
};
struct FUN_00d471c0_target
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10(int a, int b);
};
struct FUN_00d47130_class
{
    int InvokeTarget(const char* name, FUN_00d471c0_target* target);
};
class hkpEntityListenerD87
{
  public:
    virtual ~hkpEntityListenerD87();
};

class hkpConstraintListenerD87
{
  public:
    virtual ~hkpConstraintListenerD87();
};

class hkpActionListenerD87
{
  public:
    virtual ~hkpActionListenerD87();
};

class hkpPhantomListenerD87
{
  public:
    virtual ~hkpPhantomListenerD87();
};

class hkReferencedObjectD87
{
  public:
    virtual ~hkReferencedObjectD87();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00def160 : public hkReferencedObjectD87,
                     public hkpEntityListenerD87,
                     public hkpConstraintListenerD87,
                     public hkpActionListenerD87,
                     public hkpPhantomListenerD87
{
  public:
    virtual ~FUN_00def160();

    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};

class hkpWorldPostSimulationListenerD87
{
  public:
    virtual ~hkpWorldPostSimulationListenerD87()
    {}
};

class FUN_00d87bf0 : public FUN_00def160, public hkpWorldPostSimulationListenerD87
{
  public:
    virtual ~FUN_00d87bf0();
};

// @fnv 0x00d87bf0
FUN_00d87bf0::~FUN_00d87bf0()
{}

struct MemberD4728
{
    int m_data;
};

class OwnerD4728
{
  public:
    MemberD4728* FUN_00d47280();

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
    MemberD4728 m_kMember;
};

// @fnv 0x00d47280
MemberD4728* OwnerD4728::FUN_00d47280()
{
    return &m_kMember;
}

struct S00d47350_Res
{
    int value;
};

struct S00d47350_Member
{
    const char* name;
    const void* classDescriptor;
    const void* enumDescriptor;
    unsigned char type;
};

struct Tv
{
    int type;
};
struct S00d47350_Out
{
    int type;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    union
    {
        void* data;
        int enumValue;
    };
    const void* descriptor;
};
struct Outs
{
    void** pobj;
    S00d47350_Member** pm;
};
struct Zt;
struct DataS
{
    void* p;
};
S00d47350_Res FUN_00d47130(Zt* self, DataS obj, Outs r);

// Uses the member returned by FUN_00d47130 to populate output according to the member's type.
// @fnv 0x00d47350
S00d47350_Res FUN_00d47350(Zt* self, int, void* data, S00d47350_Out* output)
{
    S00d47350_Member* holder;
    Outs r;
    r.pm = &holder;
    r.pobj = &data;
    DataS dsData;
    dsData.p = data;
    S00d47350_Res result = FUN_00d47130(self, dsData, r);
    if (result.value != 0)
        return result;
    S00d47350_Member* member = *(S00d47350_Member* volatile*)&holder;
    unsigned char type = member->type;
    if (type == 0x14)
    {
        const void* d = ((const void *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()));
        output->type = 0x14;
        output->data = data;
        output->descriptor = d;
        return result;
    }
    if (type == 0x18)
    {
        const void* descriptor = ((const void *)(reinterpret_cast<::FUN_00d86930_StandIn *>((member))->FUN_00d86930()));
        int enumValue = ::ReadSignedValueBySize((const void *)(member));
        output->enumValue = enumValue;
        output->descriptor = descriptor;
        output->type = 0x18;
        return result;
    }
    S00d47350_Res resFallback;
    Tv v;
    v.type = type;
    resFallback.value = reinterpret_cast<::hkVariantD476 *>((output))->SetData(data, (*(const void * *)&(const ::Tv &)(v)));
    return resFallback;
}

#include <string.h>
namespace fnv_00cb0fa0 {
// Returns the result of comparing two null-terminated strings using strcmp.
// @fnv 0x00cb0fa0
int __cdecl FUN_00cb0fa0(const char* pcA, const char* pcB)
{
    return strcmp(pcA, pcB);
}
}  // namespace fnv_00cb0fa0

struct LookupNode
{
    void* unk00;
    LookupNode* m_parent;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    HkMem* m_members;
    int m_uiCount;
    int* m_pDefaultObject;
    int FUN_00d46f00();
    int FUN_00d47130(intptr_t offset, char** value, HkMem** member);
};
// Looks up name via FUN_00d47130 and, on success, calls target->vf10 with the index and p->FUN_00d86980().
// @fnv 0x00d471c0
int FUN_00d47130_class::InvokeTarget(const char* name, FUN_00d471c0_target* target)
{
    int index;
    FUN_00d86980_class* p;
    int result = reinterpret_cast<::LookupNode *>(this)->FUN_00d47130((intptr_t)(name), (char **)(int *)(&index), (::HkMem **)(::FUN_00d86980_class **)(&p));
    if (result == 0)
        target->vf10(index, reinterpret_cast<::ClassMember_d869 *>((p))->FUN_00d86980());
    return result;
}
__declspec(noinline) int LookupNode::FUN_00d46f00()
{
    LookupNode* p = m_parent;
    int total = m_uiCount;
    if (p)
    {
        do
        {
            total += p->m_uiCount;
            p = p->m_parent;
        } while (p);
    }
    return total;
}
// Walks the parent chain to locate the node containing the offset, then resolves the member pointer and value from m_pDefaultObject.
// @fnv 0x00d47130
int LookupNode::FUN_00d47130(intptr_t offset, char** value, HkMem** member)
{
    LookupNode* node = this;
    offset -= ((int)(reinterpret_cast<::FUN_00d46f00_s *>((node))->FUN_00d46f00()));
    while (node != 0)
    {
        offset += node->m_uiCount;
        if (offset >= 0)
            break;
        node = node->m_parent;
    }
    if (node != 0)
    {
        if (node->m_pDefaultObject != 0)
        {
            int relative = node->m_pDefaultObject[offset];
            if (relative >= 0)
            {
                *value = reinterpret_cast<char*>(node->m_pDefaultObject) + relative;
                *member = node->m_members + offset;
                return 0;
            }
        }
    }
    return 1;
}

enum hkResultD473
{
    HK_SUCCESS = 0,
    HK_FAILURE = 1
};

class hkClassD473;
class hkClassEnumD473;

class hkClassMemberD473
{
  public:
    const char* m_name;
    const hkClassD473* m_class;
    const hkClassEnumD473* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_pCustomAttributes;

};

class hkDataValueD473
{
  public:
    int m_type;
    int unk04;
    int unk08;
    int unk0C;
    const void* m_uiFilterValue;
    const void* m_class;

    hkResultD473 SetData(const void* pvAddr, int iType);
};

class hkClassAccessorD473
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const hkClassMemberD473* m_members;
    int m_numMembers;
    const char* m_pData;

    hkResultD473 FUN_00d473f0(int iIndex, hkDataValueD473& kOut) const;
};

// Reads the value of the member at iIndex from m_pData into kOut, dispatching on the member's type for class, enum, or generic data.
// @fnv 0x00d473f0
hkResultD473 hkClassAccessorD473::FUN_00d473f0(int iIndex, hkDataValueD473& kOut) const
{
    if (m_pData)
    {
        int iOffset = ((const int*)m_pData)[iIndex];
        if (iOffset >= 0)
        {
            const void* pvAddr = m_pData + iOffset;
            const hkClassMemberD473& kMember = m_members[iIndex];
            hkResultD473 res = HK_SUCCESS;
            unsigned char ucType = kMember.m_type;

            if (ucType == 0x14)
            {
                const hkClassD473* pkClass = ((const ::hkClassD473 *)(reinterpret_cast<::Struct_d86920 *>((void *)&(kMember))->FUN_00d86920()));
                pvAddr = *(const void* const*)pvAddr;
                kOut.m_class = pkClass;
                kOut.m_uiFilterValue = pvAddr;
                kOut.m_type = 0x14;
            }
            else if (ucType == 0x18)
            {
                const hkClassEnumD473* pkEnum = ((const ::hkClassEnumD473 *)(reinterpret_cast<::FUN_00d86930_StandIn *>((void *)&(kMember))->FUN_00d86930()));
                intptr_t iValue = ::ReadSignedValueBySize((const void *)&(kMember));
                kOut.m_class = pkEnum;
                kOut.m_uiFilterValue = (const void*)iValue;
                kOut.m_type = 0x18;
            }
            else
            {
                int t = (int)kMember.m_type;
                res = kOut.SetData(pvAddr, t);
            }

            return res;
        }
    }

    return HK_FAILURE;
}

struct S_00e03240_Node;

struct S_00e03240_Holder
{
    S_00e03240_Node* FUN_00d46f20(int index);
};

struct S_00e03240_Node
{
    int unk00;
    int unk04;
    int unk08;
    char unk0c;

    int FUN_00d86940();
};

static __declspec(noinline) int FUN_00e03100(S_00e03240_Node* node)
{
    if (node->FUN_00d86940())
        return node->FUN_00d86940();
    return 1;
}

// @fnv 0x00e03240
int __cdecl FUN_00e03240(S_00e03240_Holder* holder, S_00e03240_Node* node, intptr_t value, intptr_t flags)
{
    int result = reinterpret_cast<::FUN_00d47130_class *>((holder))->InvokeTarget((const char *)(value), (::FUN_00d471c0_target *)(flags));

    if (node->unk0c != 0x19)
        return result;

    S_00e03240_Holder* childHolder = ((::S_00e03240_Holder *)(reinterpret_cast<::Struct_d86920 *>((node))->FUN_00d86920()));
    if (!childHolder)
        return result;

    int rounds = FUN_00e03100(node);
    if (rounds <= 0)
        return result;

    int outerCount = rounds;
    do
    {
        for (int index = 0; index < ((int)(reinterpret_cast<::FUN_00d46f00_s *>((childHolder))->FUN_00d46f00())); ++index)
        {
            S_00e03240_Node* child = ((::S_00e03240_Node *)(reinterpret_cast<::HkClassNode *>((childHolder))->FUN_00d46f20(index)));

            if (!FUN_00e03240(childHolder, child, index, flags))
                result = 0;
        }
    } while (--outerCount);

    return result;
}
