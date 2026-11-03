// fallout/ai/ailineartaskthread.cpp: AILinearTaskThread, Thr (3 functions)

#include <new>
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_008c7860_Class.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/QuantitySet.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_011c3000.h"
class GlobalObject_008c71b0
{
    int value;

  public:
    GlobalObject_008c71b0(int);
    GlobalObject_008c71b0(const GlobalObject_008c71b0&);
};
class hkMemoryAllocator
{
  public:
    virtual void vfn_0();
    virtual void* vfn_4(int);
};
class OSGlobals
{
  public:
};
enum MagicSystem__CastingType
{
    CastingType0
};
class TESEnchantableForm
{
  public:
};
class InterfaceManager
{
  public:
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
};
class hkMemorySystem
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c(void*, const char*, GlobalObject_008c71b0);
};
class PointerCallback
{
  public:
};
class TESDataHandler
{
  public:
    void BuildCompiledFileList();
};
class AILinearTaskThread
{
  public:
    char padding[0x50];
    char memoryRouter[0x24];
    void* memory;
    void StartTaskThread();
};
// @fnv 0x008c6ff0
void AILinearTaskThread::StartTaskThread()
{
    ((::hkMemorySystem *)(::FUN_00cbbfc0()))->vfn_c(memoryRouter, "AILinearTaskThread", GlobalObject_008c71b0(1));
    ::FUN_00cbb930(memoryRouter);
    reinterpret_cast<::FUN_0041fd00_shell *>((((TESEnchantableForm*)memoryRouter)))->FUN_0041fd00((*(int *)&(const ::MagicSystem__CastingType &)((MagicSystem__CastingType)((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((((OSGlobals*)memoryRouter)))->FUN_0044edb0())))));
    reinterpret_cast<::TESPackage *>((((InterfaceManager*)memoryRouter)))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((((OSGlobals*)memoryRouter)))->FUN_0044edb0()))));
    memory = ((hkMemoryAllocator*)((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((((OSGlobals*)memoryRouter)))->FUN_0044edb0())))->vfn_4(0x32000);
    reinterpret_cast<::QuantitySet *>((((hkMemorySystem*)&((::BGSPerkEntry *)(new ((void *)(((BSSimpleList<BGSPerkEntry*>*)memoryRouter))) ::Vec3())))))->FUN_008c70c0((unsigned int)(memory), 0x32000);
    (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->BuildCompiledFileList();
}

void __cdecl operator delete(void*);
struct FUN_008c7830
{
    FUN_008c7830* FUN_008c7830_(unsigned int aiFlags);
};
// Calls FUN_008c7860, frees this with operator delete when aiFlags has bit 0 set, and returns this.
// @fnv 0x008c7830
FUN_008c7830* FUN_008c7830::FUN_008c7830_(unsigned int aiFlags)
{
    reinterpret_cast<::FUN_008c7860_Class *>(this)->FUN_008c7860_Class::~FUN_008c7860_Class();
    if (aiFlags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Alloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8(void* p, int n);
};
struct Fin
{
};
struct Router
{
};
struct HkSys
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10(Router* r, GlobalObject_008c71b0 g);
};
void hkInit();
struct Thr
{
    char padding[0x50];
    Router memoryRouter;
    char pad2[0x20];
    void* memory;
    void InitMemory();
};
// @fnv 0x008c7110
void Thr::InitMemory()
{
    ((::Alloc *)(reinterpret_cast<::MagicCaster_shell *>(&(memoryRouter))->FUN_0044edb0()))->v8(memory, 0x32000);
    hkInit();
    ((::HkSys *)(::FUN_00cbbfc0()))->v10(&memoryRouter, GlobalObject_008c71b0(1));
    reinterpret_cast<::QuantitySet *>((((::Fin *)(new ((void *)&(memoryRouter)) ::Vec3()))))->FUN_008c70c0({}, {});
}
