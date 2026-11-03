// tesregiondatasound_decls.h: declares TESFile, TESForm, BGSMusicType, RegionDataEntry, RegionSoundEntry and more
#ifndef TESREGIONDATASOUND_DECLS_H
#define TESREGIONDATASOUND_DECLS_H

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004615d0_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
class TESFile
{
  public:
    bool IsEndianConversionRequired();
};
class TESForm
{
  public:
    virtual void vfn_00();
};
class BGSMusicType : public TESForm
{
};
class RegionDataEntry
{
  public:
    unsigned int data;
    void Endian();
};
class RegionSoundEntry
{
  public:
    unsigned int sound, flags, chance;
    RegionSoundEntry();
    void Endian();
};
template <class T> class BSSimpleList
{
  public:
    T item;
    void* next;
    void AddTail(T const&);
};
class ScriptVariableInfo;
class ContainerItemExtraFileData
{
  public:
    void Endian();
};
class TESDataHandler
{
  public:
    unsigned int FUN_004615d0(unsigned int);
};
class TESRegionDataSound
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual BGSMusicType* GetMusicType();
    virtual void SetMusicType(BGSMusicType*);
    unsigned int pad4;
    RegionDataEntry Data;
    BSSimpleList<RegionSoundEntry*> Sounds;
    unsigned int incidental;
    BSSimpleList<unsigned int> Battle;
    bool LoadRegionSoundData(TESFile*);
};
#endif
