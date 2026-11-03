// gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp: NiPSysModifier, MyIsEqual, ParticleModifierBinary, ParticleModifier (8 functions)

#include <cstdint>
#include <windows.h>
#include <new>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a5d3a0.h"
#include "fnv/decl/FUN_00a5d430_Class.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0105a000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c0000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysmodifier_decls.h"

// @fnv 0x00C318B0
void NiPSysModifier::LoadBinary(NiStream& kStream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(kStream));
    if (kStream.m_uiNifVersion < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(m_kName));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kName));

    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &m_uiUpdateOrder);
    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    unsigned char ucActive;
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &ucActive);
    m_bModifierActive = ucActive != 0;
}

// @fnv 0x00C31780
void NiPSysModifier::CopyMemberData(NiPSysModifier* pkDest, CloningProcess& kCloning)
{
    reinterpret_cast<::FUN_00a5d450_class *>(this)->CreateVertexBufferSet((uintptr_t)(pkDest), (void *)&(kCloning));
    char* pcName = m_kName.m_kHandle;
    if (pkDest->m_kName.m_kHandle != pcName)
    {
        if (pcName != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle)
            InterlockedIncrement(reinterpret_cast<volatile long*>(pcName - 8));
        char* pcOldName = pkDest->m_kName.m_kHandle;
        if (pcOldName != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(pcOldName - 8));
        pkDest->m_kName.m_kHandle = pcName;
    }
    pkDest->m_uiUpdateOrder = m_uiUpdateOrder;
    pkDest->m_bModifierActive = m_bModifierActive;
}

// @fnv 0x00C317E0
void NiPSysModifier::ProcessClone(CloningProcess& kCloning)
{
    reinterpret_cast<::FUN_00a5d430_Class *>(this)->FUN_00a5d430((uintptr_t)&(kCloning));
    NiObject* pkClone = 0;
    NiPSysCloneMapGetAt(kCloning.m_pCloneMap, this, pkClone);
    NiPSysModifier* pkDest = static_cast<NiPSysModifier*>(pkClone);
    NiPSysCloneMapGetAt(kCloning.m_pCloneMap, reinterpret_cast<NiObject*>(m_pkTarget), pkClone);
    pkDest->m_pkTarget = reinterpret_cast<NiParticleSystem*>(pkClone);
}

// @fnv 0x00C31650
void NiPSysModifier::LinkObject(NiStream& kStream)
{
    ::FUN_00a89af0((intptr_t)this);
    kStream.GetLoadedObject();
}

struct NiPSysModifier_shell
{
    void FUN_00c31640(NiParticleSystem* pkTarget);
};

// @fnv 0x00c31640
void NiPSysModifier_shell::FUN_00c31640(NiParticleSystem* pkTarget)
{
    *reinterpret_cast<uintptr_t*>(reinterpret_cast<unsigned int*>(this) + 4) =
        reinterpret_cast<uintptr_t>(pkTarget);
}


// @fnv 0x00c31710
const char* const* __cdecl FUN_00c31710()
{
    return &(*reinterpret_cast<const char *const *>(&::g_012027d0));
}

struct MyIsEqual
{
    bool FUN_00c31830(NiObject* pkObject);
};
// Compares this object with a NiPSysModifier: checks IsSameAs, then fields at offsets 8, 0xc and 0x14 for equality.
// @fnv 0x00c31830
bool MyIsEqual::FUN_00c31830(NiObject* pkObject)
{
    NiPSysModifier* pkDest = (NiPSysModifier*)pkObject;
    if (reinterpret_cast<::A5d470Class *>((pkObject))->IsSameAs({}) && *(void**)((char*)this + 8) == *(void**)&pkDest->m_kName.m_kHandle &&
        *(unsigned int*)((char*)this + 0xc) == pkDest->m_uiUpdateOrder &&
        *(unsigned char*)((char*)this + 0x14) == *(unsigned char*)&pkDest->m_bModifierActive)
        return true;
    return false;
}

struct NiObjectBase
{
    bool RegisterStreamables(NiStream&);
};
struct StreamHack
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(void*);
};
struct X
{
    bool FUN_00c31670(NiStream&);
};
// Registers streamables via NiObjectBase::RegisterStreamables and, on success, calls vf8 on the stream with this+8.
// @fnv 0x00c31670
bool X::FUN_00c31670(NiStream& kStream)
{
    if (!((NiObjectBase*)this)->RegisterStreamables(kStream))
        return false;
    ((StreamHack*)&kStream)->vf8((char*)this + 8);
    return true;
}

struct OutputBinaryStream : NiBinaryStream
{
    __forceinline void WriteComponents(const void* data, unsigned int bytes, unsigned int* componentSizes,
                                       unsigned int componentCount)
    {
        unsigned int written = m_pfnWrite(this, data, bytes, componentSizes, componentCount);
        m_uiStreamFlags += written;
    }
};
struct OutputStream : NiStream
{
    OutputBinaryStream* m_pBackingStream;
};
struct LinkOutput
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void SaveObject(NiParticleSystem*);
};
struct BinaryObjectBase
{
    void* vtable;
    unsigned int referenceCount;
};
struct ParticleModifierBinary : BinaryObjectBase
{
    NiFixedString name;
    unsigned int order;
    NiParticleSystem* target;
    bool active;
    void FUN_00c31950(OutputStream&);
};
template <class T> __forceinline void PrimitiveWrite(OutputBinaryStream* stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream->WriteComponents(&value, sizeof(T), &size, 1);
}
__forceinline void BooleanWrite(OutputBinaryStream* stream, bool value)
{
    unsigned int size = 1;
    stream->WriteComponents(&value, 1, &size, 1);
}
// @fnv 0x00c31950
void ParticleModifierBinary::FUN_00c31950(OutputStream& stream)
{
    ::FUN_00a89af0((intptr_t)this);
    reinterpret_cast<::FUN_00a641f0_cls *>(&(stream))->WriteObjectLink((void *)&(name));
    PrimitiveWrite(stream.m_pBackingStream, order);
    reinterpret_cast<LinkOutput*>(&stream)->SaveObject(target);
    BooleanWrite(stream.m_pBackingStream, active);
}

extern "C" void(* DAT_00fdf1c0)(char*);
extern "C" void(* DAT_00fdf1c4)(char*);
struct ParticleModifier
{
    void* vtable;
    unsigned int referenceCount;
    char* name;
    unsigned int order;
    void* target;
    bool active;
    ParticleModifier* FUN_00c316a0(char* volatile* newName, unsigned int newOrder);
};
// @fnv 0x00c316a0
ParticleModifier* ParticleModifier::FUN_00c316a0(char* volatile* newName, unsigned int newOrder)
{
    new ((void *)this) struct ::FUN_00a5d3a0();
    vtable = &DAT_010c09cc;
    name = ::DAT_0109b220;
    order = newOrder;
    target = 0;
    active = true;
    char* pNewName = *newName;
    if (name != pNewName)
    {
        if (pNewName != ::DAT_0109b220)
            DAT_00fdf1c0(pNewName - 8);
        if (name != ::DAT_0109b220)
            DAT_00fdf1c4(name - 8);
        name = pNewName;
    }
    return this;
}

struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __forceinline void Add(char* pElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, pElement);
    }
};

struct FUN_00c319e0_cls : ParticleModifierBinary
{
    void FUN_00c319e0(StrArr* apViewerStrings);
};

// Appends the modifier's name, order and active flag as formatted strings to the given string array.
// @fnv 0x00c319e0
void FUN_00c319e0_cls::FUN_00c319e0(StrArr* apViewerStrings)
{
    reinterpret_cast<::A5D6E0This *>((apViewerStrings))->AppendCameraPathEntries({});
    apViewerStrings->Add(FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_012027d0))));
    const char* pcName = name.m_kHandle;
    apViewerStrings->Add(::fnv_00a7d5e0::FUN_00a7d5e0(g_011d4e34_arg1, pcName));
    apViewerStrings->Add(FUN_00a7d510("Order", order));
    apViewerStrings->Add(FUN_00a7d370("Active", active));
}


namespace c318 {
}

class NiFixedStringC318
{
  public:
    ~NiFixedStringC318()
    {
        if (m_kHandle != ::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

class FUN_00a5d3d0
{
  public:
    virtual ~FUN_00a5d3d0();
    long m_uiRefCount;
};

class NamedC318 : public FUN_00a5d3d0
{
  public:
    virtual ~NamedC318()
    {}


    NiFixedStringC318 m_kName;
    int unk0C[3];

    NamedC318* FUN_00c31870(unsigned int uiFlags);
};

// Releases the NamedC318 object, calling its destructor and freeing memory when uiFlags has bit 0 set, then returns this.
// @fnv 0x00c31870
NamedC318* NamedC318::FUN_00c31870(unsigned int uiFlags)
{
    this->NamedC318::~NamedC318();
    if (uiFlags & 1)
        ::operator delete(this, sizeof(NamedC318));
    return this;
}

#include "generated/data/gamebryo2.2/corelibs/niparticle/nipsysmodifier.inc"
