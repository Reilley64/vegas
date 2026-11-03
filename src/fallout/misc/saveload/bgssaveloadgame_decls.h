// fallout/misc/saveload/bgssaveloadgame_decls.h: declares FormChangeMask, Actor, TESDataHandlerSaveLoad, FormChangeRecord, BGSSaveLoadChangesMap and more
#ifndef BGSSAVELOADGAME_DECLS_H
#define BGSSAVELOADGAME_DECLS_H

// TESForm (all PC virtuals) comes from the canonical TESForm.h; TESDataHandler, TESObjectCELL and the NiTPointerMap
// template come from the canonical layout_support.h.
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00570f00__FUN_00570f00_shell.h"
#include "fnv/decl/fnv_00893340__FUN_00893340_shell.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_011c3000.h"
#include "layout_support.h"
#include "TESForm.h"
class BaseProcess;
class TESFile;
class BGSReconstructFormsInFileMap;
class TESObjectREFR;
class FormChangeMask
{
  public:
    unsigned int flags;
public:
    static ::FormChangeMask HasFormChanged(::FormChangeMask, ::FormChangeMask, int, bool);
};
class TESActorBase;
class Actor
{
  public:
public:
    ::TESActorBase *GetActorBase();
};
// TESDataHandler members the canonical (API-only) layout_support.h class does not declare yet; called through a cast
// of g_dataHandler (same address).
class TESDataHandlerSaveLoad
{
  public:
};
class FormChangeRecord
{
  public:
    FormChangeMask flags;
    FormChangeMask savedFlags;
};
class FormChangeMask;
class BGSSaveLoadChangesMap
{
  public:
    bool ContainsChangeFlags(unsigned int, FormChangeMask);
    void AddFormChangeFlags(unsigned int, FormChangeMask);
    bool ClearChangeFlags(unsigned int, FormChangeMask);
    bool HasFormChanges(unsigned int);
    FormChangeRecord* FUN_009a4250(unsigned int);
public:
    void ApplyFormQuantityChange(unsigned int, ::FormChangeMask);
};
// The canonical NiTPointerMap template has no RemoveAll; the <unsigned int, unsigned int> instance used here declares it.
template <> class NiTPointerMap<unsigned int, unsigned int>
{
  public:
    void RemoveAll();
};
class BGSReconstructFormsInAllFilesMap
{
  public:
    BGSReconstructFormsInAllFilesMap();
    virtual ~BGSReconstructFormsInAllFilesMap();
    unsigned int data[12];
    void BuildMap();
    void* GetFirstPos();
    TESForm* FUN_00849ca0(unsigned int);
public:
    void Clear();
};
class BGSSaveLoadReferencesMap
{
  public:
    void LoadCellReferences(TESObjectCELL*, BGSReconstructFormsInAllFilesMap*);
public:
    void Clear();
};
class BGSSaveLoadGame
{
  public:
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    unsigned int unused[3];
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    unsigned char pad14[0x248 - 0x14];
    unsigned char m_ucSaveLoadState;
    unsigned char GetLoadState();
    bool ContainsReference(unsigned int);
    bool HasFormChangeFlags(TESForm*, FormChangeMask);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, FormChangeMask);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, FormChangeMask, bool);
    void HasFormChanges(TESForm*);
    void ClearFormChanges();
    void LoadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
};
#endif
