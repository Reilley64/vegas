
// src/fallout_shared/bgsheadpart_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsheadpart.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/TESModel.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c1000.h"
extern "C" void ref_008256d0();
extern "C" void ref_00ec43fb();
extern "C" void ref_0063f7b0();
extern "C" void ref_00726c60();
extern "C" void ref_00ec5ec0();
extern "C" void ref_00ec408c();
extern "C" unsigned char data_011863b8[];
extern "C" unsigned char data_010465ec[];
enum ENUM_FORM_ID
{
    kBGSHeadPart = 9
};
class TESFile;
class TESFile;
class TESForm
{
  public:
    TESForm();
    virtual ~TESForm()
    {}

  private:
    unsigned char formData[20];
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
public:
    ::TESFile *GetFile(int);
};
class TESFullName
{
  public:
    TESFullName();
    virtual ~TESFullName()
    {}

  private:
    unsigned char nameData[8];
};
class TESForm;
class TESModelTextureSwap
{
  public:
    TESModelTextureSwap();
    virtual ~TESModelTextureSwap()
    {}

  private:
    unsigned char modelData[28];
public:
    void InitItem(::TESForm *);
};
class BGSHeadPart;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    ~BSSimpleList()
    {}

  private:
    T* item;
    BSSimpleList<T>* next;
};
class BGSHeadPart : public TESForm, public TESFullName, public TESModelTextureSwap
{
  public:
    BGSHeadPart();
    void ResetFormData();
    virtual void InitItem();
    virtual bool Load(TESFile*);
    unsigned char cFlags;
    unsigned char padding[3];
    BSSimpleList<BGSHeadPart*> m_kExtraParts;
public:
    void AddExtraPart(::BGSHeadPart *);
};

// sub ecx,0x24; jmp target == MSVC adjustor thunk: Derived overrides a virtual that both of its
// bases declare, so the second base's vtable gets a thunk that moves `this` back by the size of
// the first base (vptr + 8 ints = 0x24).
struct PrimaryBase
{
    virtual void FUN_005e7a80();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct SecondaryBase
{
    virtual void FUN_005e7a80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005e7a80
    virtual void FUN_005e7a80();
};

Derived::Derived()
{}
