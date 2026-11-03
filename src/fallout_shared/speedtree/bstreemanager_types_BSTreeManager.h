// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSTREEMANAGER_H
#define FNV_BSTREEMANAGER_H

#include "layout_support.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class NiCamera;
class BSTreeManager;
class BSTreeModel;
class BSXFlags;
class LockFreeMap_TESObjectREFR___BSTreeNode___;
class NiAlphaProperty;
class NiMaterialProperty;
class NiTexture;
class TESObjectTREE;
class BSTreeManager
{
  public:
    NiTPointerMap<TESObjectTREE*, NiPointer<BSTreeModel>*>* m_pLoadedModelMap;  // +0x0, 4 bytes
    NiPointer<NiTexture> m_pTreeTexture;                                        // +0x4, 4 bytes
    NiPointer<NiMaterialProperty> m_spMaterialProperty;                         // +0x8, 4 bytes
    NiPointer<NiAlphaProperty> m_pAlphaProperty;                                // +0xC, 4 bytes
    NiPointer<BSXFlags> m_pBSXFlags;                                            // +0x10, 4 bytes
    float m_fCurrentWeatherBlend;                                               // +0x14, 4 bytes
    bool m_bFirstOfFourFlags;                                                   // +0x18, 1 bytes
    bool m_bSecondOfFourFlags;                                                  // +0x19, 1 bytes
    bool ReferenceTreeManagerState;                                             // +0x1A, 1 bytes
    bool m_bFourthTreeManagerFlag;                                              // +0x1B, 1 bytes
    LockFreeMap_TESObjectREFR___BSTreeNode___* m_pTreeInstanceMap;              // +0x1C, 4 bytes
    BSTreeManager();
    static void Create(bool);
    static void UpdateTreeInstances();
    // BSTreeManager
    // void __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*()
    // BSTreeManager* __cdecl BSTreeManager::*(bool)
    // void __cdecl BSTreeManager::*(bool)
    // void __cdecl BSTreeManager::*()
    // NiPointer<BSTreeModel>* __cdecl BSTreeManager::*(TESObjectTREE*)
    // void __cdecl BSTreeManager::*(TESObjectTREE*, unsigned int, NiPointer<BSTreeModel>&)
    // void __cdecl BSTreeManager::*(bool)
    // bool __cdecl BSTreeManager::*(TESObjectREFR*)
    // BSTreeNode* __cdecl BSTreeManager::*(TESObjectREFR*, TESObjectTREE*)
    // void __cdecl BSTreeManager::*(NiCamera*, bool)
    // void __cdecl BSTreeManager::*()
    // bool __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*(bool)
    // NiTexture* __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*()
    // NiMaterialProperty* __cdecl BSTreeManager::*()
    // NiAlphaProperty* __cdecl BSTreeManager::*()
    // BSXFlags* __cdecl BSTreeManager::*()
    // bool __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*(bool)
    // void __cdecl BSTreeManager::*(NiCamera*)
    // NiCamera* __cdecl BSTreeManager::*()
    // bool __cdecl BSTreeManager::*()
    // bool __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*(bool)
    // bool __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*(bool)
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // unsigned int __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // float __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*(bool)
    // void __cdecl BSTreeManager::*(bool)
    // bool __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*()
    // void __cdecl BSTreeManager::*(TESObjectREFR*, BSTreeNode*)
    // void __cdecl BSTreeManager::*(TESObjectREFR*)
    // BSTreeManager& __cdecl BSTreeManager::*(const BSTreeManager&)
    // void* __cdecl BSTreeManager::*(unsigned int)
};
#endif
