// fallout/misc/garbagecollector_packet.h: declares GarbageCollector, ModelLoader, WaitableObject, NavMesh, GarbageCollectorDeleteA and more
#ifndef FNV_GARBAGECOLLECTOR_PACKET_H
#define FNV_GARBAGECOLLECTOR_PACKET_H

#include <windows.h>
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_004aaf10_shell.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_00878360_Class.h"
#include "fnv/decl/PtrArrayView.h"
#include "fnv/decl/_FUN_0052aa80_shell.h"
#include "fnv/decl/fnv_00564d80__ArrSI.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00869000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "layout_support.h"
class GarbageCollector
{
  public:
    static void Remove(TESObjectREFR* reference);
    static void QueryCurrentThread(bool);
    static void ClearTempEffects();
    static void Update();
};
class GlobalObject_00869db0
{
  public:
    unsigned int GetSize();
    void RemoveAll();
};
struct ModelLoader
{
  public:
    bool FUN_00868250();
};
extern GlobalObject_00869db0 g_011de828;
class WaitableObject
{
  public:
    void FUN_00401970();
};
class NavMesh
{
  public:
    char padding[28];
    WaitableObject debug;
};
struct GlobalObject_00869f00
{
  public:
    void** m_ppVirtualMethodTable;
    NavMesh** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int Add(NavMesh*&);
    unsigned int GetSize();
    NavMesh*& GetAt(unsigned int);
    void Clear(bool);
};
extern GlobalObject_00869f00 g_011de924, g_011de898;

class GarbageCollectorDeleteA
{
  public:
    ~GarbageCollectorDeleteA();
};
class GarbageCollectorDeleteB
{
  public:
    ~GarbageCollectorDeleteB();
};
class TESObjectREFR
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual ~TESObjectREFR();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool vfn_100();
};
class NiAVObject
{
  public:
    void RemoveGarbageMark();
};
class GarbageCollectorObjectPtr
{
  public:
    NiAVObject* object;
    NiAVObject* operator->() const;
    ~GarbageCollectorObjectPtr();
};
class GlobalObject_004aff00
{
  public:
    unsigned int GetSize();
    GarbageCollectorObjectPtr& GetAt(unsigned int);
    GarbageCollectorObjectPtr RemoveAt(unsigned int);
    void RemoveAll();
};
class GlobalObject_00869c60
{
  public:
    unsigned int GetSize();
    GarbageCollectorDeleteA*& GetAt(unsigned int);
    void RemoveAll();
};
class GlobalObject_00869b10
{
  public:
    unsigned int GetSize();
    GarbageCollectorDeleteB*& GetAt(unsigned int);
    void RemoveAll();
};
class NiTPrimitiveArray_unsigned_int_
{
  public:
    void RemoveAll();
};
extern GlobalObject_00869c60 g_011de808;
extern GlobalObject_00869b10 g_011de910, g_011de838;
extern GlobalObject_004aff00 g_011de888, g_011de848;
class GarbageCollectorUpdateState
{
  public:
};
#endif
