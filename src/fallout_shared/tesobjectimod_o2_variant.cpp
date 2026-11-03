
// src/fallout_shared/tesobjectimod_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectimod.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0047a240_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_0048ea80_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00519e70.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0048e9b0__TESValueForm.h"
#include "fnv/decl/fnv_0048e9e0__TESValueForm.h"
#include "fnv/decl/fnv_0048ea10__TESValueForm.h"
#include "fnv/decl/fnv_0048ea40__TESValueForm.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00487000.h"
#include "tesobjectimod_decls.h"
class TESFormInitFlag : public TESObjectIMODVirtuals
{
  public:
};
enum ENUM_FORM_ID
{
    kIMOD = 0x67
};
class TESForm : public TESFormInitFlag
{
  private:
    unsigned char fields[0x14];

  public:
    void SetInitializationState(bool initialized);
public:
    bool GetInitialized() const;
public:
    void LoadGame(void *);
};
class TESBoundObject : public TESForm
{
  private:
    unsigned char fields[0x18];

  public:
    TESBoundObject();
    ~TESBoundObject();
};
class TESFullName : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESFullName();
    ~TESFullName();
};
class TESModel : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x14];

  public:
    static void LoadModelData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  private:
    unsigned char fields[0x08];

  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void InitItem(TESForm* form);
};
class TESTexture : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};
class TESScriptableForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESScriptableForm();
    void InitItem(TESForm* form);
};
class TESDescription : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESDescription();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class TESValueForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESValueForm();
    ~TESValueForm();
};
class TESWeightForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESWeightForm();
    ~TESWeightForm();
};
class BGSDestructibleObjectForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    void InitItem(TESForm* form);
};
class BGSMessageIcon : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x0c];

  public:
    BGSMessageIcon();
    ~BGSMessageIcon();
};
class BGSPickupPutdownSounds : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm* form);
};
class TESObjectIMOD : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESDescription,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
  public:
    TESObjectIMOD();
    bool Load(TESFile*);
    void InitItem();
};
struct FUN_0051a5d0_shell
{
    void __thiscall FUN_0051a5d0(unsigned int, unsigned int);
};
struct TESFormStub
{
};
struct TESValueFormStub
{
};
struct BGSLoadFormBuffer;
struct FUN_0051a630_shell : public TESObjectIMOD
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
struct TESFormLoadGame
{
};
struct TESValueFormLoadGame
{
};
struct FUN_00519e40_shell : public TESObjectIMOD
{
    void* __thiscall FUN_00519e40(unsigned int flags);
};
struct FUN_00519e70_stub
{
};
struct FUN_00484bf0
{
};
struct FUN_0048e9b0
{
};
struct FUN_0051a550_shell
{
    unsigned short __thiscall FUN_0051a550(unsigned int aiFlags);
};
struct FUN_0051b070_shell
{
};
struct FUN_0051a5a0_shell
{
    void __thiscall FUN_0051a5a0(unsigned int aiFlags);
};
struct BGSSaveFormBuffer;
struct FUN_00484d60_holder
{
};
struct FUN_0048ea40_holder
{
};
struct FUN_0051a600_shell
{
    void __thiscall FUN_0051a600(BGSSaveFormBuffer* buffer);
};
struct S_00477f20
{
};
struct S_00487010
{
};
struct S_0048a520
{
};
struct S_0048cca0
{
    void __thiscall FUN_0048cca0();
};
struct FUN_00482cb0_shell
{
    void __thiscall FUN_00482cb0();
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_00485e00_shell
{
    void __thiscall FUN_00485e00();
};
struct FUN_0047a240_holder
{
};
struct FUN_0047b560_holder
{
};
struct FUN_0048e370_holder
{
};
struct FUN_0051a420_shell : public TESObjectIMOD
{
    void FUN_0051a420();
};

struct B1
{
    virtual void FUN_0051a680(unsigned int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};

struct B2
{
    virtual void FUN_0051a680(unsigned int);
};

struct Derived : B1, B2
{
    Derived();
// @fnv 0x0051a680
    virtual void FUN_0051a680(unsigned int);
};

Derived::Derived()
{}
