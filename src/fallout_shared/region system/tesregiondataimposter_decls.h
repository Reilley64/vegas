// fallout_shared/region system/tesregiondataimposter_decls.h: declares TESRegionDataImposter, TESFile, TESForm, TESObjectREFR
#ifndef FNV_TESREGIONDATAIMPOSTER_DECLS_H
#define FNV_TESREGIONDATAIMPOSTER_DECLS_H


#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
class TESFile;
class TESForm;
class TESObjectREFR;
class TESTopic;
class TESGrass;
class QuantityData;

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    bool AddHead(T& item);
    void AddTail(T& item);
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void SetItem(const T& item);
    void RemoveHead();
};

template <> class BSSimpleList<TESGrass*>
{
  public:
};

template <> class BSSimpleList<QuantityData*>
{
  public:
};

class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};

#pragma pack(push, 4)
class TESRegionDataImposter
{
  public:
    unsigned char baseStorage[8];
    BSSimpleList<TESObjectREFR*> m_kImposterList;

    bool AddImposter(TESObjectREFR* ref);
    bool ReadRegionData(TESFile* file);
    void InitItem(TESForm* form);
};
#pragma pack(pop)

class TESFile
{
  public:
    bool IsEndianConversionRequired();
};

class TESForm
{
  public:
    virtual ~TESForm();
    TESFile* GetFile(int index);
};
class TESObjectREFR : public TESForm
{
};

template <int N> struct EndianSizeTag
{
};
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* data);

#endif
