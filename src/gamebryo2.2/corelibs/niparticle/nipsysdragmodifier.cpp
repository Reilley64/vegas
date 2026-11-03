// gamebryo2.2/corelibs/niparticle/nipsysdragmodifier.cpp: NiPSysDragModifier, NiPSysDragShell (7 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c319e0_cls.h"
#include "fnv/decl/MyIsEqual.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/ParticleModifierBinary.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01062000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysdragmodifier_decls.h"

// @fnv 0x00C2C450
void NiPSysDragModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    reinterpret_cast<NiColor*>(&m_kDragDirection)->LoadBinary(kStream);
    ReadBinaryValue(kStream, m_fDragStrength);
    ReadBinaryValue(kStream, m_fFirstLightParameter);
    ReadBinaryValue(kStream, m_fSecondLightParameter);
}

struct BSFadeNode
{
};

void* FUN_00c2c030(void*);

// @fnv 0x00c2c080
void* __cdecl FUN_00c2c080()
{
    void* p = ::operator new(0x34);
    if (p)
        return FUN_00c2c030(p);
    return 0;
}

struct GlobalObjectO2_00a7b610;
// @fnv 0x00c2c0a0
void* __cdecl FUN_00c2c0a0()
{
    return &::g_01202768;
}

namespace fnv_00c2c0b0 {
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
struct FUN_00c2c0b0_shell : public NiPSysDragModifier
{
    NiObject* CloneDragModifier(CloningProcess*);
};

struct BSFadeNode
{
};
struct DragCtorStub
{
    DragCtorStub* FUN_00c2c030();
};
struct CopyStub
{
};
struct DragData
{
    char pad[0x1c];
    int a;
    int b;
    int c;
    float d;
    float e;
    float f;
};
// @fnv 0x00c2c0b0
NiObject* FUN_00c2c0b0_shell::CloneDragModifier(CloningProcess* kCloning)
{
    DragCtorStub* pAlloc = (DragCtorStub*)::operator new(0x34);
    DragData* pkObject = pAlloc ? (DragData*)pAlloc->FUN_00c2c030() : 0;
    reinterpret_cast<::NiPSysModifier *>((((CopyStub*)this)))->CopyMemberData((NiPSysModifier*)pkObject, (::CloningProcess &)(*kCloning));
    DragData* pSource = (DragData*)this;
    pkObject->a = pSource->a;
    pkObject->b = pSource->b;
    pkObject->c = pSource->c;
    pkObject->d = pSource->d;
    pkObject->e = pSource->e;
    pkObject->f = pSource->f;
    return (NiObject*)pkObject;
}
}  // namespace fnv_00c2c0b0

static const float s_fInfinity = 3.402823466e+38F;

struct NiPSysModifierStub
{
    virtual void Unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;

    NiPSysModifierStub();
};

struct FUN_00c2c030 : NiPSysModifierStub
{
    virtual void Unk00();

    void* m_pParent;
    NiPoint3 m_kDragDirection;
    float m_fDragStrength;
    float m_fFirstLightParameter;
    float m_fSecondLightParameter;

    FUN_00c2c030();
};

// Initializes the modifier stub fields: null pointer, unit vector, 0.05, and two infinity values.
// @fnv 0x00c2c030
FUN_00c2c030::FUN_00c2c030()
    : m_pParent(0), m_kDragDirection((*reinterpret_cast<const ::NiPoint3 *>(&::DAT_011a946c))), m_fDragStrength(0.05f), m_fFirstLightParameter(s_fInfinity),
      m_fSecondLightParameter(s_fInfinity)
{}

struct DragBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(DragBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct DragStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    DragBinaryStreamView* m_pUnderlyingStream;
};

struct NiPSysModifierStand
{
    void* vtable;
    char unk04[0x14];
};

struct NiPoint3Stand
{
    float x;
    float y;
    float z;
};

struct FUN_00c2c4f0_cls : NiPSysDragModifier
{
    void FUN_00c2c4f0(NiStream& stream);
};

// @fnv 0x00c2c4f0
void FUN_00c2c4f0_cls::FUN_00c2c4f0(NiStream& stream)
{
    reinterpret_cast<::ParticleModifierBinary *>((reinterpret_cast<NiPSysModifierStand*>(this)))->FUN_00c31950((::OutputStream &)(stream));
    void** vt = *reinterpret_cast<void***>(&stream);
    reinterpret_cast<void(*)(NiStream*, NiAVObject*)>(vt[12])(&stream, m_pParent);
    reinterpret_cast<::NiColor *>((reinterpret_cast<NiPoint3Stand*>(&m_kDragDirection)))->SaveBinary(stream);
    DragStreamView* s = reinterpret_cast<DragStreamView*>(&stream);
    s->m_pUnderlyingStream->Load(&m_fDragStrength);
    s->m_pUnderlyingStream->Load(&m_fFirstLightParameter);
    s->m_pUnderlyingStream->Load(&m_fSecondLightParameter);
}

struct S_00c2c590_Poly
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual bool unk5C(S_00c2c590_Poly* other);
};
struct S_00c2c590_Vec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct S_00c2c590_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct S_00c2c590 : S_00c2c590_Base
{
    S_00c2c590_Poly* unk18;
    int unk1C;
    int unk20;
    int unk24;
    float unk28;
    float unk2C;
    float unk30;
    bool FUN_00c2c590(S_00c2c590* other);
};
// Compares this object with other: base comparison, unk18 pointer presence and unk5C match, then unk1C vector and unk28/unk2C/unk30 floats.
// @fnv 0x00c2c590
bool S_00c2c590::FUN_00c2c590(S_00c2c590* other)
{
    if (reinterpret_cast<::MyIsEqual *>(this)->FUN_00c31830((::NiObject *)(other)))
    {
        if (unk18 && !other->unk18)
            return false;
        if (!unk18 && other->unk18)
            return false;
        if (unk18 && other->unk18 && !unk18->unk5C(other->unk18))
            return false;
        if (!reinterpret_cast<::NiPlane *>((((S_00c2c590_Vec*)&other->unk1C)))->operator==((*(const ::NiPlane *)((S_00c2c590_Vec*)&unk1C))) && other->unk28 == unk28 &&
            other->unk2C == unk2C && other->unk30 == unk30)
            return true;
    }
    return false;
}

// Reconstructed NiPSysDragModifier binary-loading routine.
struct DragObject
{
    void* unk00;
    void* unk04;
    const char* objectName;
};
struct Point3Serializer
{
    float x, y, z;
};
struct StreamArray
{
    void** vtable;
    void* elements;
    unsigned short capacity;
    unsigned short size;
    unsigned short activeSize;
    unsigned short growBy;
    __forceinline void Append(void* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + growBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, (*(char * *)(&value)));
    }
};
struct NiPSysDragShell : NiPSysModifier
{
    DragObject* dragObject;
    Point3Serializer dragAxis;
    float percentage;
    float range;
    float falloff;
    void FUN_00c2c620(NiStream& stream);
};
extern char DAT_010bff18;
extern char DAT_010bff0c;
extern char DAT_010bff00;
extern char DAT_010bfef0;
// Saves the modifier via NiPSysModifier::SaveBinary, then appends the drag object name, drag axis, percentage, range and falloff to the stream array.
// @fnv 0x00c2c620
void NiPSysDragShell::FUN_00c2c620(NiStream& stream)
{
    reinterpret_cast<::FUN_00c319e0_cls *>(this)->FUN_00c319e0((::StrArr *)&(stream));
    StreamArray& array = *reinterpret_cast<StreamArray*>(&stream);
    array.Append(((void *)(::FUN_00a7d330((const char *)(*reinterpret_cast<void**>(&::g_01202768))))));
    const char* name = dragObject ? dragObject->objectName : &(*reinterpret_cast<char *>((void *)&::g_011d1f8c_arg1));
    array.Append(((void *)(::fnv_00a7d5e0::FUN_00a7d5e0((const char *)(const void *)(&DAT_010bff18), (const char *)(name)))));
    array.Append(((void *)(reinterpret_cast<::NiPoint3 *>(&(dragAxis))->FUN_00a59af0((const char *)(const void *)(&DAT_010bff0c)))));
    array.Append(((void *)(::FUN_00a7d550((const char *)(const void *)(&DAT_010bff00), percentage))));
    array.Append(((void *)(::FUN_00a7d550((const char *)(const void *)(&(*reinterpret_cast<char *>((void *)&::g_011d3348_arg1))), range))));
    array.Append(((void *)(::FUN_00a7d550((const char *)(const void *)(&DAT_010bfef0), falloff))));
}

#include "generated/data/gamebryo2.2/corelibs/niparticle/nipsysdragmodifier.inc"
