
// src/fallout_shared/globalfunc_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy /GF (unit src/fallout_shared/globalfunc.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include <cstddef>
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00c86d20_Class.h"
#include "fnv/decl/FUN_00cbb1b0_Class.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/Wrapper86b80.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_004a2000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "globalfunc_decls.h"

class NiRTTI
{
  public:
    const char* name;
    const NiRTTI* parent;
};
struct MemoryContextScope
{
    int previous;
    __forceinline MemoryContextScope(int value)
    {
        previous = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = value;
    }
    __forceinline ~MemoryContextScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};
struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity, size, count, growBy;
};
struct __declspec(align(16)) SpringInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float pos[3];
    float unk1c;
    float vel[3];
    float unk2c;

    float damping, elasticity, maxForce, objectDamping;
};
struct MouseSpringDiagnostic
{
    void FUN_00c873d0(StrArr*);
};
static void AppendString(StrArr* strings, char*& value)
{
    unsigned int index = strings->size;
    if (index >= strings->capacity)
        reinterpret_cast<::ViewerStrings *>((strings))->SetSize(index + strings->growBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strings))->SetAt(index, value);
}
// @fnv 0x00c873d0
void MouseSpringDiagnostic::FUN_00c873d0(StrArr* strings)
{
    MemoryContextScope scope(16);
    char* str;
    reinterpret_cast<::Wrapper86b80 *>(this)->FUN_00c86b80((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(strings));
    str = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_0126812c)));
    AppendString(strings, str);
    SpringInfo info;
    info.unk00 = 0;
    info.unk04 = 0;
    for (int i = 0; i < 3; i++)
        info.pos[i] = 0;
    info.unk1c = 0;
    info.vel[0] = 0;
    info.vel[1] = 0;
    info.vel[2] = 0;
    info.unk2c = 0;
    info.damping = ::fnv_00c88020::DAT_01016248;
    info.elasticity = ::DAT_01017870;
    info.maxForce = ::DAT_0101b2d0;
    info.objectDamping = ::g_011cc6cc_arg1;
    reinterpret_cast<::FUN_00c86d20_Class *>(this)->FUN_00c86d20((::OutputData *)(::SpringInfo *)(&info));
    str = FUN_00a7d550("Damping", info.damping);
    AppendString(strings, str);
    str = FUN_00a7d550("Elasticity", info.elasticity);
    AppendString(strings, str);
    str = FUN_00a7d550("Object Damping", info.objectDamping);
    AppendString(strings, str);
    str = FUN_00a7d550("Max Force", info.maxForce);
    AppendString(strings, str);
}

#include <xmmintrin.h>

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};

struct hkMemoryAllocator
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pThreadAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pThreadAllocator;
    }
};
hkMemoryRouterStub* FUN_00c85750();

struct hkVector4
{
    __m128 m_vComponents;
    hkVector4()
    {}
    hkVector4(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct MouseSpringInfo
{
    int unk00;
    void* m_pkBody;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_fSpringDamping;
    float m_fSpringElasticity;
    float m_fMaxRelativeForce;
    float m_fObjectDamping;
};

struct MouseSpringAction
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;

    static void* operator new(std::size_t nbytes)
    {
        MouseSpringAction* p = (MouseSpringAction*)FUN_00c85750()->heap().allocateChunk(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, std::size_t nbytes);

    MouseSpringAction(const hkVector4& kPositionInRbLocal, const hkVector4& kMousePositionInWorld, float fSpringDamping,
                      float fSpringElasticity, float fObjectDamping, void* pkBody, int iUserData);

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

struct MouseSpringOwner
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void RegisterAction(struct MouseSpringAction* pkAction);
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void finish(struct MouseSpringInfo* pkInfo);
    void FUN_00c87260(MouseSpringInfo* pkInfo);
};

// @fnv 0x00c87260
void MouseSpringOwner::FUN_00c87260(MouseSpringInfo* pkInfo)
{
    MemContextGuard kGuard(0x10);
    MouseSpringAction* pkAction = new MouseSpringAction(
        hkVector4(pkInfo->m_f10, pkInfo->m_f14, pkInfo->m_f18, pkInfo->m_f1C),
        hkVector4(pkInfo->m_f20, pkInfo->m_f24, pkInfo->m_f28, pkInfo->m_f2C), pkInfo->m_fSpringDamping,
        pkInfo->m_fSpringElasticity, pkInfo->m_fObjectDamping, pkInfo->m_pkBody, 0);
    reinterpret_cast<::FUN_00cbb1b0_Class *>((pkAction))->FUN_00cbb1b0(pkInfo->m_fMaxRelativeForce);
    RegisterAction(pkAction);
    reinterpret_cast<::hkReferencedObjectC905 *>((pkAction))->FUN_00c905b0();
    finish(pkInfo);
}
