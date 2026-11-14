// fallout_shared/modelloader_added_types.h: declares BSXFlags, DFALL_NiTMapItem_unsigned_int_Actor_____, NiTMap_unsigned_int_Actor___, BGSSaveLoadGame
#ifndef FNV_MODELLOADER_ADDED_TYPES_H
#define FNV_MODELLOADER_ADDED_TYPES_H

#include <stddef.h>

// API-only declaration: no object construction, storage, casts or virtual calls.
// Public address/name evidence identifies both const members.
class BSXFlags
{
  public:
    unsigned int GetFlags(unsigned int flags) const;
    bool GetAddon() const;
};

// No container constructors, destructors or operations are defined or called.
class BGSSaveLoadChangesMap;
class FormIDConverter;
class BGSSaveLoadReferencesMap;
class LoadGameSubBufferQueue;
class SaveLoadChangeHistory;
class BGSReconstructFormsInAllFilesMap;
struct BGSLoadFormBuffer;
class Actor;
class NiTMap_unsigned_int_unsigned_int_;

template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};

template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};

class DFALL_NiTMapItem_unsigned_int_Actor_____
{
};
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor_____AntiBloatAllocator
    : public DFALL_NiTMapItem_unsigned_int_Actor_____
{
  public:
    unsigned int m_uiCount;
};
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<unsigned int, Actor*>** m_ppkHashTable;
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor_____AntiBloatAllocator m_kItemCount;
};
class NiTMap_unsigned_int_Actor___ : public NiTMapBase_DFALL_NiTMapItem_unsigned_int_Actor______unsigned_int_Actor___
{
};

class FormChangeMask;
class TESForm;
struct BGSSaveLoadGame
{
  public:
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    NiTMap_unsigned_int_unsigned_int_* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    BSSimpleArray<BGSLoadFormBuffer*, 1024> LoadFormBufferArray;
    NiTMap_unsigned_int_Actor___ m_acTextBuffer;
    unsigned char m_acFirstTextBuffer[255];
    unsigned char m_acSecondTextBuffer[255];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    bool GetInitingForms() const;
public:
    bool HasFormChangeFlags(::TESForm *, ::FormChangeMask);
};
// Full supplied real-field/dependency assertions retained. Natural alignment replaces synthetic padding arrays.
typedef BSSimpleArray<BGSLoadFormBuffer*, 1024> ModelLoaderFormBufferArray;

#endif
