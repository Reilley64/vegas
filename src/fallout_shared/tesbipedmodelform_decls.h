// fallout_shared/tesbipedmodelform_decls.h: declares BGSListForm, BSFaceGenModelExtraData, NiNode, BipedAnim, ModelLoader
#ifndef FNV_TESBIPEDMODELFORM_DECLS_H
#define FNV_TESBIPEDMODELFORM_DECLS_H

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_0043f010.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_008bbc40_shell.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_011c3000.h"
class BSExtraData;
class InventoryChanges;
class TESBoundObject;
class TESObjectCELL;
class CellDataNode;
class ValidBip01Names;
class TESForm;
class TESModel;
class BSFaceGenModel;
class BGSListForm;
template <class T> class BSSimpleList;
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
class BGSListForm
{
  public:
    char _pdbpad_1[23];
    char ListOfForms_pad17_pad17_pad17[8];
    unsigned int m_uiFormCount;
};
class BSFaceGenModelExtraData
{
  public:
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    T* operator->() const;
};
class NiNode
{
  public:
};
class BipedAnim
{
  public:
    void SetBipedObject(TESForm*, TESModel*, BIPED_OBJECT);
};
class ModelLoader
{
  public:
};
#endif
