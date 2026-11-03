
// src/gamebryo2.2/corelibs/nimain/nitarray_h_unit_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitarray_h_unit.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "fnv/decl/C89AC0_Owner.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a5ed10__ChildArray.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00cd2fd0__Object.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00cf4000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "nitarray.inl"

struct StrArr
{
    unsigned char m_auiShapeKeys[8];
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_pAuxiliaryObject;
    unsigned short m_growth;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct FUN_00cc6540_Class
{
    unsigned char m_auiShapeKeys[4];
    void* m_pUserData;

    void FUN_00cc6540(StrArr* array);
};


namespace fnv_00cf46e0 {
struct StrArr
{
    unsigned char _pad[8];
    unsigned short m_008;
    unsigned short m_00a;
    unsigned short m_00c;
    unsigned short m_00e;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct GlobalObjectO2_00a7b610
{
    unsigned char _pad[0x2b4];
    unsigned int m_02b4;
};



struct TLSGuard
{
    unsigned int saved;

    TLSGuard() : saved((*reinterpret_cast<::fnv_00cf46e0::GlobalObjectO2_00a7b610 *>(&::g_tlsBlock)).m_02b4)
    {
        (*reinterpret_cast<::fnv_00cf46e0::GlobalObjectO2_00a7b610 *>(&::g_tlsBlock)).m_02b4 = 0x10;
    }

    ~TLSGuard()
    {
        (*reinterpret_cast<::fnv_00cf46e0::GlobalObjectO2_00a7b610 *>(&::g_tlsBlock)).m_02b4 = saved;
    }
};

// @fnv 0x00cf46e0
void FUN_00cf46e0(StrArr* array)
{
    TLSGuard guard;
    char* value = ::FUN_00a7d330((const char *)((*reinterpret_cast<::fnv_00cf46e0::GlobalObjectO2_00a7b610 * *>(&::g_01268740))));
    unsigned int index = array->m_00a;

    if (index >= array->m_008)
        reinterpret_cast<::ViewerStrings *>((array))->SetSize(static_cast<unsigned int>(index + array->m_00e));

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, value);
}
}  // namespace fnv_00cf46e0

struct CharPtrArr
{
    int unk00;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short unk0C;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    int FUN_00a5b4b0(char*& value);
};

// @fnv 0x00a5b4b0
int CharPtrArr::FUN_00a5b4b0(char*& value)
{
    if (value == 0)
        return -1;
    unsigned short i = 0;
    for (; i < m_usSize; i++)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = value;
            unk0C++;
            return i;
        }
    }
    unsigned int count = m_usSize;
    if (count >= m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>(this)->SetSize(m_usGrowBy + count);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(count, value);
    return count;
}


struct BC8AD40AllocTagScope
{
    int m_iSaved;

    BC8AD40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BC8AD40AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class BC8AD40StringArray
{
  public:
    virtual ~BC8AD40StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};



class FUN_00c8ad40_cls
{
  public:
    void FUN_00c8ad40(BC8AD40StringArray* pkArray);
};

// @fnv 0x00c8ad40
void FUN_00c8ad40_cls::FUN_00c8ad40(BC8AD40StringArray* pkArray)
{
    BC8AD40AllocTagScope kScope(0x10);
    ::FUN_00c87be0((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)this);
    char* pcName = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268198)));
    pkArray->Add(pcName);
}

namespace fnv_00cc31c0 {

class CC31C0MemContext
{
  public:
    CC31C0MemContext(int aiMemoryContext)
    {
        m_iPrevious = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~CC31C0MemContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iPrevious;
    }

    int m_iPrevious;
};


class CC31C0StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const char* const& pcValue);

    unsigned int Add(const char* const& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcValue));
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    const char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class CC31C0Object
{
  public:
    void FUN_00cc31c0(CC31C0StrArray* pkStrings);
};

// @fnv 0x00cc31c0
void CC31C0Object::FUN_00cc31c0(CC31C0StrArray* pkStrings)
{
    CC31C0MemContext kContext(0x10);
    reinterpret_cast<::FUN_00c8ad40_cls *>(this)->FUN_00c8ad40((::BC8AD40StringArray *)(pkStrings));
    pkStrings->Add(::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_012685b0))));
}
}  // namespace fnv_00cc31c0

struct ViewerObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void* GetType();
};
struct ViewerConstraint
{
    int unk00;
    ViewerObject* object;
    int priority;
    void* entityA;
    void* entityB;
    void FUN_00c8a560(BC8AD40StringArray* array);
};
// @fnv 0x00cc6540
void FUN_00cc6540_Class::FUN_00cc6540(StrArr* array)
{
    reinterpret_cast<::ViewerConstraint *>(this)->FUN_00c8a560((::BC8AD40StringArray *)(array));

    unsigned char* data = static_cast<unsigned char*>(m_pUserData);
    if (data)
    {
        char* value = FUN_00a7d550("ConeMinAngle", *reinterpret_cast<float*>(data + 0xa0));
        unsigned int index = array->m_uiItemCount;
        unsigned int size = array->m_iElementCount;
        if (index >= size)
            reinterpret_cast<::ViewerStrings *>((array))->SetSize(index + array->m_growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, value);

        value = FUN_00a7d550("PlaneMinAngle", *reinterpret_cast<float*>(data + 0xb0));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            reinterpret_cast<::ViewerStrings *>((array))->SetSize(index + array->m_growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, value);

        value = FUN_00a7d550("PlaneMaxAngle", *reinterpret_cast<float*>(data + 0xb4));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            reinterpret_cast<::ViewerStrings *>((array))->SetSize(index + array->m_growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, value);

        value = FUN_00a7d550("TwistMinAngle", *reinterpret_cast<float*>(data + 0x88));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            reinterpret_cast<::ViewerStrings *>((array))->SetSize(index + array->m_growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, value);

        value = FUN_00a7d550("TwistMaxAngle", *reinterpret_cast<float*>(data + 0x8c));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            reinterpret_cast<::ViewerStrings *>((array))->SetSize(index + array->m_growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, value);
    }
}
// @fnv 0x00c8a560
void ViewerConstraint::FUN_00c8a560(BC8AD40StringArray* array)
{
    BC8AD40AllocTagScope scope(16);
    char* text;
    char buffer[32];
    if (object)
    {
        text = ::fnv_00a7d5e0::FUN_00a7d5e0("Type", ::GetConstraintTypeName((int)(object->GetType())));
        array->Add(text);
    }
    ::FUN_00406d00(buffer, 32, "0x%8X", entityA);
    text = ::fnv_00a7d5e0::FUN_00a7d5e0("hkpEntityA", buffer);
    array->Add(text);
    ::FUN_00406d00(buffer, 32, "0x%8X", entityB);
    text = ::fnv_00a7d5e0::FUN_00a7d5e0("hkpEntityB", buffer);
    array->Add(text);
    text = FUN_00a7d4d0("ePriority", priority);
    array->Add(text);
}

// Appends this class name to the viewer strings after the base entries, under the Havok allocation tag.


struct BCC4740AllocTagScope
{
    int m_iSaved;

    BCC4740AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCC4740AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class BCC4740StringArray
{
  public:
    virtual ~BCC4740StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};



class CC4740Base
{
  public:
};

class CC4740Derived : public CC4740Base
{
  public:
    void FUN_00cc4740(BCC4740StringArray* pkArray);
};

// @fnv 0x00cc4740
void CC4740Derived::FUN_00cc4740(BCC4740StringArray* pkArray)
{
    BCC4740AllocTagScope kScope(0x10);
    reinterpret_cast<::FUN_00c8ad40_cls *>(this)->FUN_00c8ad40((::BC8AD40StringArray *)(pkArray));
    char* pcName = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_012685d4)));
    pkArray->Add(pcName);
}

struct CF4520AllocTagScope
{
    int saved;
    CF4520AllocTagScope(int tag)
    {
        saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = tag;
    }
    ~CF4520AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = saved;
    }
};
struct CF4520Array
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int Add(char* const& item)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, (char *&)(item));
        return index;
    }
};
// @fnv 0x00cf4520
void FUN_00cf4520(CF4520Array* array)
{
    CF4520AllocTagScope tag(16);
    char* element = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268738)));
    array->Add(element);
}

struct BCCCFD0AllocTagScope
{
    int m_iSaved;

    BCCCFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCCCFD0AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

class BCCCFD0StringArray
{
  public:
    virtual ~BCCCFD0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};


class CCCFD0Base
{
  public:
};

class CCCFD0Derived : public CCCFD0Base
{
  public:
    void FUN_00cccfd0(BCCCFD0StringArray* pkStrings);
};

// @fnv 0x00cccfd0
void CCCFD0Derived::FUN_00cccfd0(BCCCFD0StringArray* pkStrings)
{
    BCCCFD0AllocTagScope kScope(0x10);
    reinterpret_cast<::fnv_00cd2fd0::Object *>(this)->FUN_00cd2fd0((::fnv_00cd2fd0::StrArr *)(pkStrings));
    pkStrings->Add(FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_0126867c))));
}

extern "C" void _ReadWriteBarrier();
struct CAA010Inner
{
    virtual void OpA();
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void OpF();
    virtual void OpG();
    virtual void OpH();
    virtual void* GetHandle();
};

struct CAA010Shell
{
    virtual void Activate(int flag);
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void PassArray(struct CAA010Arr* array);
};

struct CAA010Data
{
    int unk00;
    int unk04;
    int unk08;
    CAA010Inner* m_obj;
    int unk10;
    int unk14;
    int unk18;
    float m_f;
};


struct CAA010TagScope
{
    int m_iSaved;
    CAA010TagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CAA010TagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

struct CAA010Arr
{
    int unk00;
    int unk04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    unsigned int SetAtGrow(unsigned int index, char* const& value)
    {
        if (index >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, (char*&)value);
        return index;
    }
};


struct CAA010This
{
    int unk00;
    void* m_pUserData;
    CAA010Inner* GetObj()
    {
        return m_pUserData ? ((CAA010Data*)m_pUserData)->m_obj : 0;
    }
    void FUN_00caa010(CAA010Arr* array);
};

// @fnv 0x00caa010
void CAA010This::FUN_00caa010(CAA010Arr* array)
{
    CAA010TagScope scope(16);
    reinterpret_cast<::ViewerConstraint *>(this)->FUN_00c8a560((::BC8AD40StringArray *)(array));
    array->SetAtGrow(array->m_usSize, FUN_00a7d550("Strength", m_pUserData ? ((CAA010Data*)m_pUserData)->m_f : 0.0f));
    CAA010Inner* inner = GetObj();
    _ReadWriteBarrier();
    if (inner)
    {
        CAA010Shell* shell = ((::CAA010Shell *)(::CreateSaver((unsigned int)(inner->GetHandle()))));
        if (shell)
        {
            reinterpret_cast<::C89AC0_Owner *>((shell))->SetChildObject((::C89AC0_Child *)(inner));
            shell->PassArray(array);
            shell->Activate(1);
            return;
        }
        return;
    }
}

// @fnv 0x00cf4300
void FUN_00cf4300(CF4520Array* pkArray)

{

    CF4520AllocTagScope scope(16);

    char* pcElement = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268730)));

    pkArray->Add(pcElement);
}
