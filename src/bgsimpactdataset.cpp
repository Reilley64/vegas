// bgsimpactdataset.cpp: BGSImpactDataSet, SomeClass, ImpactDataSetCopy, BGSImpactDataSet_Cmp and more (25 functions)

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0058f7f0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0058f000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_011c3000.h"
#include "bgsimpactdataset_decls.h"
// @fnv 0x0058e810
BGSImpactDataSet::BGSImpactDataSet()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x5f)));
    ResetFormData();
}

// @fnv 0x0058eb10
void BGSImpactDataSet::ResetFormData()
{
    memset(m_apImpactData, 0, sizeof(m_apImpactData));
}

#include "bgsimpactdataset_TESFile.h"
#include <malloc.h>
class DataHandler
{
  public:
};
class TESModel : public BaseFormComponent
{
  public:
    unsigned int GetModelLength() const;
};
class BGSTextureSet
{
  public:
    void LoadTextures(int priority, QueuedFile* file, bool noCache);
};
class BGSImpactData : public TESForm, public TESModel
{
  public:
    BGSTextureSet* GetDecalTextureSet() const;
};
struct ModelLoader
{
  public:
};
template <int N> struct EndianSizeTag
{
};

// Looks up the form with ref ID 0x276; if missing, creates a BGSImpactDataSet, sets its ref ID and editor ID, and adds it to the data handler.
// @fnv 0x0058ea10
void BGSImpactDataSet::CacheImpactDataSet()
{
    ms_pImpactDataSet = dynamic_cast<BGSImpactDataSet*>(::FUN_004839c0(0x276));
    if (!ms_pImpactDataSet)
    {
        ms_pImpactDataSet = new BGSImpactDataSet;
        ms_pImpactDataSet->SetRefID(0x276, true);
        ms_pImpactDataSet->SetEditorID_AtRuntime("DefaultImpactDataSet");
        reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->AddFormToDataHandler(ms_pImpactDataSet);
    }
}

// Validates the TESForm type is 0x5f, loads the record header, then reads EDID, OBND and DATA chunks until no chunk remains.
// @fnv 0x0058ec00
bool BGSImpactDataSet::Load(TESFile* file)
{
    if (file->GetTESForm() != 0x5f)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    unsigned int uiChunkID;
    while ((uiChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_apImpactData), sizeof(m_apImpactData));
            if (file->IsEndianConversionRequired())
            {
                for (int i = 0; i < 12; ++i)
                    ::FUN_00401080((int *)(float *)((float*)&m_apImpactData[i]));
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0058edd0
void BGSImpactDataSet::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    for (int i = 0; i < 12; ++i)
    {
        unsigned int formID = static_cast<unsigned int>(reinterpret_cast<std::uintptr_t>(m_apImpactData[i]));
        if (formID)
        {
            ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
            m_apImpactData[i] = dynamic_cast<BGSImpactData*>(::FUN_004839c0(formID));
            if (m_apImpactData[i])
            {
            }
            else
                ::FUN_005b5e40();
        }
    }
    SetInitializationState(true);
}

// @fnv 0x0058ef10
void BGSImpactDataSet::QueueResourceLoad(int priority, QueuedFile* pQueuedFile)
{
    for (int i = 0; i < 12; ++i)
    {
        BGSImpactData* data = GetImpactDataForMaterial(i);
        if (data)
        {
            if (data->GetModelLength())
                reinterpret_cast<::QueueModelHolder *>((g_modelLoader))->FUN_00443d30(reinterpret_cast<std::uintptr_t>(data), priority, reinterpret_cast<std::uintptr_t>(pQueuedFile), true, true, false, false);
            BGSTextureSet* textureSet = data->GetDecalTextureSet();
            if (textureSet)
                textureSet->LoadTextures(priority, pQueuedFile, false);
        }
    }
}

// Stores swap in DAT_011ca834, then for each of 10 indices passes the swap's alt footstep material name (or 0) to SetGlobalPointerAtOffset and calls FUN_00837500.
// @fnv 0x0058eeb0
void BGSImpactDataSet::RefreshImpactData(ImpactSwap* swap)
{
    DAT_011ca834 = swap;
    for (int i = 0; i < 10; ++i)
    {
        if (swap)
            ::fnv_008374e0::SetGlobalPointerAtOffset(i, ((const char *)(reinterpret_cast<::FUN_0058f7f0_Class *>((swap))->FUN_0058f7f0(i))));
        else
            ::fnv_008374e0::SetGlobalPointerAtOffset(i, 0);
    }
    FUN_00837500();
}

struct FUN_0040f2a0
{
    void* DeleteThis(unsigned int flags);
};
// Calls FUN_0058f010, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0040f2a0
void* FUN_0040f2a0::DeleteThis(unsigned int flags)
{
    ::FUN_0058f010((::FUN_0058f010_Item **)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0058e890
{
    void FUN_0058e8c0();
    void* DeleteThis(unsigned int flags);
};
struct Base5a
{
    virtual ~Base5a();
    char d[0x14];
};
struct Preload
{
    virtual void f();
};
struct FUN_0058e8c0 : Base5a, Preload
{
    ~FUN_0058e8c0();
};
// Calls the object's cleanup routine, frees the object when bit 0 of flags is set, and returns the object pointer.
// @fnv 0x0058e890
void* FUN_0058e890::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::FUN_0058e8c0 *>(this)->FUN_0058e8c0::~FUN_0058e8c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor for the Preload-derived object; empty body, only the base destructors run.
// @fnv 0x0058e8c0
FUN_0058e8c0::~FUN_0058e8c0()
{}

struct FUN_0058ed50 : BGSImpactDataSet
{
    void Save();
};
// @fnv 0x0058ed50
void FUN_0058ed50::Save()
{
    int iIndex;
    unsigned int auiFormIDs[12];
    reinterpret_cast<::fnv_004855a0::ArrSI *>(static_cast<TESForm*>(this))->FUN_004855a0();
    for (iIndex = 0; iIndex < 12; iIndex++)
    {
        if (m_apImpactData[iIndex])
            auiFormIDs[iIndex] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(m_apImpactData[iIndex])->FUN_0084e3a0()));
        else
            auiFormIDs[iIndex] = 0;
    }
    ::FUN_00485710((void *)(0x41544144), auiFormIDs, (void *)(12));
    reinterpret_cast<::Holder *>(static_cast<TESForm*>(this))->FUN_00485680();
}

struct FUN_0058efd0
{
    void* m_pData[12];
    unsigned char m_aucIMPFData[300];
    FUN_0058efd0();
};
// Zero-initializes the twelve map slots and the IMPF data of the object.
// @fnv 0x0058efd0
FUN_0058efd0::FUN_0058efd0()
{
    memset(m_pData, 0, sizeof(m_pData));
    memset(m_aucIMPFData, 0, sizeof(m_aucIMPFData));
}

struct FUN_0058f010_Item
{
    virtual ~FUN_0058f010_Item();
};
// Deletes each of the 12 item pointers in the array and sets them to null.
// @fnv 0x0058f010
void FUN_0058f010(FUN_0058f010_Item** apItems)
{
    for (int i = 0; i < 12; i++)
    {
        delete apItems[i];
        apItems[i] = 0;
    }
}

struct ContainerItemExtraFileData
{
};
struct ImpactDataSwapExtraData : ContainerItemExtraFileData
{
    unsigned int type;
    BGSImpactData* orig;
    BGSImpactData* repl;
};
struct MapX
{
};
struct FUN_0058f080
{
    MapX* m_pData[12];
    unsigned char m_aucIMPFData[300];
    void Save();
};
// @fnv 0x0058f080
void FUN_0058f080::Save()
{
    void* cur;
    int i;
    ImpactDataSwapExtraData data;
    for (i = 0; i < 12; i++)
    {
        if (m_pData[i])
        {
            cur = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((m_pData[i]))->GetFirstPos();
            while (cur)
            {
                data.type = i;
                reinterpret_cast<::C6b7f20_Map *>((m_pData[i]))->FUN_006b7f20((::C6b7f20_Node **)&(cur), (unsigned int *)&(data.orig), (void **)&(data.repl));
                if (data.orig)
                    data.orig = reinterpret_cast<BGSImpactData*>(static_cast<std::uintptr_t>(reinterpret_cast<::FUN_0084e3a0_Class *>((data.orig))->FUN_0084e3a0()));
                if (data.repl)
                    data.repl = reinterpret_cast<BGSImpactData*>(static_cast<std::uintptr_t>(reinterpret_cast<::FUN_0084e3a0_Class *>((data.repl))->FUN_0084e3a0()));
                if (((bool)(::FUN_00401500())))
                    reinterpret_cast<::Class005a6b10 *>(&(data))->FUN_005a6b10();
                ::AppendChunk(0x53504d49, &data, 12);
                if (((bool)(::FUN_00401500())))
                    reinterpret_cast<::Class005a6b10 *>(&(data))->FUN_005a6b10();
            }
        }
    }
    ::FUN_004856f0((void *)(0x46504d49), m_aucIMPFData, (void *)(300));
}

namespace fnv_0058f180 {
struct ContainerItemExtraFileData
{
};
struct ImpactDataSwapExtraData : ContainerItemExtraFileData
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct FUN_0058f740
{
    void Add(unsigned int, unsigned int, unsigned int);
};
struct FUN_0058f180
{
    void* m_pData[12];
    unsigned char m_aucIMPFData[300];
    void Load(TESFile* apFile);
};
// Reads an IMPS chunk into a ContainerItemExtraFileData, byte-swaps it, and adds its three values; an IMPF chunk is read directly into the IMPF data.
// @fnv 0x0058f180
void FUN_0058f180::Load(TESFile* apFile)
{
    ImpactDataSwapExtraData data;
    switch (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())))
    {
    case 0x53504d49:
        memset(&data, 0, 12);
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&data), 12);
        if (apFile->IsEndianConversionRequired())
            reinterpret_cast<::Class005a6b10 *>(&(data))->FUN_005a6b10();
        ((FUN_0058f740*)this)->Add(data.a, data.b, data.c);
        break;
    case 0x46504d49:
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(m_aucIMPFData), 300);
        break;
    }
}
}  // namespace fnv_0058f180

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct FUN_0058f6f0
{
    DummyPointerMap* m[1];
    BGSImpactData* Get(unsigned int idx, BGSImpactData* def);
};
// @fnv 0x0058e9d0
BGSImpactData* BGSImpactDataSet::GetImpactDataForMaterial(int material)
{
    if (DAT_011ca834)
        return reinterpret_cast<::FUN_0058f6f0 *>((DAT_011ca834))->Get(material, m_apImpactData[material]);
    return m_apImpactData[material];
}
// Looks up idx in the pointer map and returns the stored value for def, or def itself when the slot is null.
// @fnv 0x0058f6f0
BGSImpactData* FUN_0058f6f0::Get(unsigned int auiIndex, BGSImpactData* apDefault)
{
    BGSImpactData* result = 0;
    if (m[auiIndex])
        reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(m[auiIndex]))->FUN_00853130(reinterpret_cast<std::uintptr_t>(apDefault), (::fnv_00853130::CombatThreatRecord *&)(result));
    else
        result = apDefault;
    return result;
}

struct FUN_0058f820
{
    int m0, m1, m2, m3;
    FUN_0058f820(int);
    void SetAt(BGSImpactData*, BGSImpactData*);
};
struct FUN_0058f740
{
    FUN_0058f820* m_pData[12];
    void Add(unsigned int aeType, BGSImpactData* apOrig, BGSImpactData* apNew);
};
// If apOrig differs from apNew, lazily creates the slot for aeType and records the replacement via SetAt.
// @fnv 0x0058f740
void FUN_0058f740::Add(unsigned int aeType, BGSImpactData* apOrig, BGSImpactData* apNew)
{
    if (apOrig != apNew)
    {
        if (!m_pData[aeType])
            m_pData[aeType] = new FUN_0058f820(0x25);
        m_pData[aeType]->SetAt(apOrig, apNew);
    }
}

struct ShadowLightData
{
    static void SetTargetMaskForSelection(unsigned int, unsigned __int64);
};
struct FUN_006233c0
{
    void GetImpactDataForMaterial(int aeType);
};
// @fnv 0x006233c0
void FUN_006233c0::GetImpactDataForMaterial(int aeType)
{
    switch (aeType)
    {
    case 0: {
        unsigned __int64 a = 0x26636;
        ShadowLightData::SetTargetMaskForSelection(0x27, a);
        break;
    }
    case 1: {
        unsigned __int64 b = 0x20000100;
        ShadowLightData::SetTargetMaskForSelection(0x27, b);
        break;
    }
    }
}

struct NiTMap
{
};


struct FUN_0058f5c0_shell
{
    MapX* m_pData[12];
    unsigned char m_aucIMPFData[300];
    bool IsImpactSwapDifferent(ImpactSwap* apSwap);
};

// Compares 12 map entries and their impact data against apSwap, returning true if any entry, form ID, mapped data or trailing 0x12c bytes differ.
// @fnv 0x0058f5c0
bool FUN_0058f5c0_shell::IsImpactSwapDifferent(ImpactSwap* apSwap)
{
    int i;

    if (!apSwap)
        return true;
    FUN_0058f5c0_shell* other = reinterpret_cast<FUN_0058f5c0_shell*>(apSwap);

    for (i = 0; i < 12; ++i)
    {
        if (m_pData[i] && other->m_pData[i])
        {
            void* iter;

            if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(m_pData[i])))->FUN_0084e3a0())) !=
                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(other->m_pData[i])))->FUN_0084e3a0())))
                return true;

            iter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((m_pData[i]))->GetFirstPos();
            while (iter)
            {
                BGSImpactData* pnewdata;
                {
                    BGSImpactData* polddata;

                    pnewdata = 0;
                    polddata = 0;
                    reinterpret_cast<::C6b7f20_Map *>((reinterpret_cast<NiTMap*>(m_pData[i])))->FUN_006b7f20((::C6b7f20_Node **)&(iter), (unsigned int *)&(reinterpret_cast<unsigned int&>(pnewdata)), (void **)&(reinterpret_cast<void*&>(polddata)));

                    if (reinterpret_cast<::FUN_0058f6f0 *>((apSwap))->Get(i, pnewdata) != polddata)
                        return true;
                }
            }
        }
        else if (m_pData[i] || other->m_pData[i])
        {
            return true;
        }
    }

    if (std::memcmp(m_aucIMPFData, other->m_aucIMPFData, sizeof(m_aucIMPFData)) != 0)
        return true;

    return false;
}


struct RefObj
{
};

struct ImpactMap
{
    virtual ~ImpactMap();
};

struct SomeClass
{
    FUN_0058f820* m_pData[12];
    void RemapImpactData(TESForm* apForm);
};

struct Entry
{
    unsigned int unk00;
    BGSImpactData* oldImpact;
    BGSImpactData* newImpact;
};


// For each of the 12 maps, collects old/new impact pairs, resolves their form IDs against apForm's file, warns on missing impacts, and reinserts them.
// @fnv 0x0058f210
void SomeClass::RemapImpactData(TESForm* apForm)
{
    int i6;
    void* posVal;
    Entry* entries3;
    unsigned int j_;
    unsigned int count4;
    BGSImpactData* oldImpact6;
    BGSImpactData* newImpact;
    unsigned int oldFormID;
    unsigned int newFormID4;

    for (i6 = 0; i6 < 12; i6++)
    {
        if (m_pData[i6])
        {
            j_ = 0;
            count4 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((RefObj*)m_pData[i6])))->FUN_0084e3a0()));
            entries3 = new Entry[count4];
            posVal = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)m_pData[i6])))->GetFirstPos();
            while (posVal)
            {
                reinterpret_cast<::C6b7f20_Map *>((((MapX*)m_pData[i6])))->FUN_006b7f20((::C6b7f20_Node **)&(posVal), (unsigned int *)&(entries3[j_].oldImpact), (void **)&(entries3[j_].newImpact));
                j_++;
            }
            reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<unsigned int, unsigned int>*)m_pData[i6])))->FUN_00438af0();

            for (j_ = 0; j_ < count4; j_++)
            {
                oldImpact6 = 0;
                if (entries3[j_].oldImpact)
                {
                    oldFormID = static_cast<unsigned int>(reinterpret_cast<std::uintptr_t>(entries3[j_].oldImpact));
                    ResolveFormID(&oldFormID, apForm->GetFile(-1));
                    oldImpact6 = dynamic_cast<BGSImpactData*>(FUN_004839c0(oldFormID));
                    if (!oldImpact6)
                    {
                        ::FUN_005b5e40();
                    }
                }

                newImpact = 0;
                if (entries3[j_].newImpact)
                {
                    newFormID4 = static_cast<unsigned int>(reinterpret_cast<std::uintptr_t>(entries3[j_].newImpact));
                    ResolveFormID(&newFormID4, apForm->GetFile(-1));
                    newImpact = dynamic_cast<BGSImpactData*>(FUN_004839c0(newFormID4));
                    if (!newImpact)
                    {
                        ::FUN_005b5e40();
                    }
                }

                if (oldImpact6 || newImpact)
                {
                    m_pData[i6]->SetAt(oldImpact6, newImpact);
                }
            }

            delete[] entries3;

            if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((RefObj*)m_pData[i6])))->FUN_0084e3a0())) == 0)
            {
                delete ((ImpactMap*)m_pData[i6]);
                m_pData[i6] = 0;
            }
        }
    }
}

// Maps selected integer values to integers 0–9; returns 4 for all other values.
// @fnv 0x0058e8f0
int FUN_0058e8f0(int value)
{
    int result = 4;
    switch (value)
    {
    case 0:
    case 10:
    case 19:
        result = 0;
        break;
    case 2:
    case 18:
        result = 1;
        break;
    case 4:
        result = 2;
        break;
    case 3:
    case 24:
        result = 3;
        break;
    case 5:
    case 11:
    case 13:
    case 14:
    case 15:
    case 20:
    case 21:
    case 26:
    case 27:
        result = 4;
        break;
    case 16:
    case 17:
    case 22:
    case 23:
    case 25:
    case 28:
    case 29:
        result = 9;
        break;
    case 9:
    case 12:
    case 30:
    case 31:
        result = 5;
        break;
    case 6:
    case 7:
        result = 6;
        break;
    case 8:
        result = 8;
        break;
    case 1:
        result = 7;
        break;
    }
    return result;
}

#include <string.h>
struct S004851b0
{
};
struct ImpactDataSetCopy : BGSImpactDataSet
{
    void FUN_0058eb30(TESForm* apCopy);
};
// Copies impact data from apCopy into this ImpactDataSetCopy after casting it to BGSImpactDataSet.
// @fnv 0x0058eb30
void ImpactDataSetCopy::FUN_0058eb30(TESForm* apCopy)
{
    BGSImpactDataSet* pSource = dynamic_cast<BGSImpactDataSet*>(apCopy);
    if (!pSource)
        return;
    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<S004851b0*>(this)))->FUN_004851b0(pSource);
    memcpy(m_apImpactData, pSource->m_apImpactData, sizeof(m_apImpactData));
}

struct BGSImpactDataSet_Cmp
{
    bool FUN_0058eb90(TESForm* apCompare);
};
// Returns true if apCompare is not a BGSImpactDataSet, TESForm::Compare returns true, or the impact-data arrays differ.
// @fnv 0x0058eb90
bool BGSImpactDataSet_Cmp::FUN_0058eb90(TESForm* apCompare)
{
    BGSImpactDataSet* pcomp = dynamic_cast<BGSImpactDataSet*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((TESForm*)this)))->FUN_00485270(pcomp))
        return true;
    if (memcmp(((BGSImpactDataSet*)this)->m_apImpactData, pcomp->m_apImpactData, sizeof(pcomp->m_apImpactData)))
        return true;
    return false;
}

struct ImpactSwapMaps
{
    MapX* m_pData[12];
    unsigned char m_aucIMPFData[300];
    void FUN_0058f4c0(ImpactSwapMaps* apSwap);
};
// Deletes this object's 12 map entries, adds entries from apSwap's maps, then copies its IMPF data.
// @fnv 0x0058f4c0
void ImpactSwapMaps::FUN_0058f4c0(ImpactSwapMaps* apSwap)
{
    for (int i = 0; i < 12; i++)
    {
        delete (ImpactMap*)m_pData[i];
        m_pData[i] = 0;
    }
    for (int i = 0; i < 12; i++)
    {
        if (apSwap->m_pData[i])
        {
            void* iter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((apSwap->m_pData[i]))->GetFirstPos();
            while (iter)
            {
                BGSImpactData* pnewdata;
                BGSImpactData* polddata = 0;
                pnewdata = 0;
                reinterpret_cast<::C6b7f20_Map *>((apSwap->m_pData[i]))->FUN_006b7f20((::C6b7f20_Node **)&(iter), (unsigned int *)&(polddata), (void **)&(pnewdata));
                ((FUN_0058f740*)this)->Add(i, polddata, pnewdata);
            }
        }
    }
    memcpy(m_aucIMPFData, apSwap->m_aucIMPFData, sizeof(m_aucIMPFData));
}

#include "generated/data/bgsimpactdataset.inc"
