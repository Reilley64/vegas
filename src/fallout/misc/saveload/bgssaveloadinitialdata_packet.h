// Authored research header for fallout/misc/saveload/bgssaveloadinitialdata.cpp.
// only real member-function declarations were added (they do not affect layout).
// TESForm::GetFormType is absent from the canonical include/TESForm.h;
// (precedent: fallout_shared/bgsopencloseform.h).
// 0x0084e730 (called by DetermineInitialDataType) takes (formID, formType, flags)
// and returns INITIAL_DATA_TYPE values; it is declared here as the 3-argument
// 0x00406d90 is a float-to-int (fistp) helper used to derive cell coordinates;
// no canonical name is available yet, so it is declared as TruncateFloatToInt.
#ifndef FNV_SRC_BGSSAVELOADINITIALDATA_H
#define FNV_SRC_BGSSAVELOADINITIALDATA_H

#include <cstdint>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_0046a010_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0063ef00_Class.h"
#include "fnv/decl/FUN_0084a580_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/Holder0084.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00546b10__FUN_00546b10_class.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_0084a810__FUN_0084a810_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00562000.h"
#include "fnv/symbols_00573000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_0084f000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#define TESObjectCELL BGSSaveLoadPacketUnusedCell
#define TESDataHandler BGSSaveLoadPacketUnusedHandler
#include "layout_support.h"
#undef TESObjectCELL
#undef TESDataHandler
class TESObjectCELL;
struct BGSLoadFormBuffer;
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H
struct NiPoint3
{
  public:
    NiPoint3();
    float x, y, z;
};
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_INITIAL_DATA_TYPE_H
#define FNV_INITIAL_DATA_TYPE_H
#include "layout_support.h"
enum INITIAL_DATA_TYPE
{
    INITIAL_DATA_TYPE_INITIAL_DATA_NONE = 0,
    INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR = 1,
    INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT = 2,
    INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL = 3,
    INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION = 4,
    INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE = 5,
    INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE = 6,
    INITIAL_DATA_TYPE_INITIAL_DATA_TYPE_COUNT = 7
};
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSCHANGEFLAGS_H
#define FNV_BGSCHANGEFLAGS_H
#include "layout_support.h"
class FormChangeMask;
#pragma pack(push, 4)
class FormChangeMask
{
  public:
    int iFlags;  // +0x0, 4 bytes
};
#pragma pack(pop)
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_REFERENCEINITIALDATA_H
#define FNV_REFERENCEINITIALDATA_H
#include "layout_support.h"
#include "NiPoint3.h"
class ReferencePlacementData;
class ReferencePlacementData
{
  public:
    ReferencePlacementData();
    unsigned int m_uiLocationFormID;      // +0x0, 4 bytes
    unsigned int m_uiBaseFormID;          // +0x4, 4 bytes
    unsigned int m_uiOriginalBaseFormID;  // +0x8, 4 bytes
    int m_iCellX;                         // +0xC, 4 bytes
    int m_iCellY;                         // +0x10, 4 bytes
    NiPoint3 Location;                    // +0x14, 12 bytes
    NiPoint3 Angle;                       // +0x20, 12 bytes
    unsigned char m_ucFlags;              // +0x2C, 1 bytes
    bool GetCellAndWorld(TESObjectCELL*& apCell, TESWorldSpace*& apWorld);
};
// is already naturally aligned, so all offsets are unchanged, and only packing
#endif

class TESForm
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
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
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetName();
    ENUM_FORM_ID GetFormType() const;
};

class TESWorldSpace : public TESForm
{
  public:
    TESObjectCELL* GetCellAtGridPosition(int m_iGridPositionX, int m_iGridCoordinateY);
};

class BGSSaveLoadInitialDataPacket
{
  public:
    static INITIAL_DATA_TYPE LoadInitialDataForForm(BGSLoadFormBuffer*, TESForm*, FormChangeMask);
    static INITIAL_DATA_TYPE DetermineInitialDataType(TESForm* apForm, FormChangeMask eChangeFlags);
    static INITIAL_DATA_TYPE DetermineInitialDataType(unsigned int auiFormId, ENUM_FORM_ID m_eReferenceTypeInfo,
                                                      FormChangeMask eChangeFlags);
};


class TESBoundObject : public TESForm
{
};
class TESWorldSpace;
class TESObjectCELL : public TESForm
{
  public:
    bool IsCellInterior() const;
public:
    int GetCellGridX();
public:
    int GetCellGridY();
public:
    ::TESWorldSpace *GetParentWorldSpace();
};
class ExtraDataList
{
  public:
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc(int, int);
    virtual void* vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228(TESObjectCELL*);
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual bool vfn_290();
    void SetReferencePosition(NiPoint3);
};
class PlayerCharacter : public TESObjectREFR
{
};
struct BGSSaveLoadGame
{
  public:
};
struct BGSLoadFormBuffer
{
  public:
};
class RecipeCraftingInfo;
namespace ActorValue { enum Index; }
class TESRecipe
{
  public:
public:
    ::RecipeCraftingInfo *GetData();
public:
    void SetRequiredSkill(::ActorValue::Index);
};
class TES
{
  public:
};
class BGSPrimitive;
class TESDataHandler
{
  public:
};
extern const char DAT_0107f86c[];
extern const char DAT_0107f894[];
extern const char DAT_0107f8d0[];
extern const char DAT_0107f938[];
unsigned int LoadFormData(BGSLoadFormBuffer*, INITIAL_DATA_TYPE, void*);
struct CellDetachTimeData
{
    uintptr_t a, b, c, m_uiDetachTime;
};

#endif
