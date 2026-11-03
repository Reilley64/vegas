// fallout/misc/saveload/bgssaveloadformidmap.cpp: FormIDConverter (10 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0044f3b0_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0044e000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "FormIDConverter.h"

// @fnv 0x00846b60
FormIDConverter::FormIDConverter(unsigned int uiHashSize)
    : m_kSourceToTargetFormIDMap(uiHashSize), m_kTargetToSourceFormIDMap(uiHashSize)
{
    m_uiFormIDCount = 0;
    RegisterFormID(0);
}

// Destructor that clears the two member containers via RemoveAll.
// @fnv 0x00846be0
FormIDConverter::~FormIDConverter()
{
    reinterpret_cast<::FUN_00438af0_Class *>(&(m_kSourceToTargetFormIDMap))->FUN_00438af0();
    reinterpret_cast<::FUN_00438af0_Class *>(&(m_kTargetToSourceFormIDMap))->FUN_00438af0();
}

// @fnv 0x00846c50
void FormIDConverter::Clear()
{
    reinterpret_cast<::FUN_00438af0_Class *>(&(m_kSourceToTargetFormIDMap))->FUN_00438af0();
    reinterpret_cast<::FUN_00438af0_Class *>(&(m_kTargetToSourceFormIDMap))->FUN_00438af0();
    m_uiFormIDCount = 0;
    RegisterFormID(0);
}

// @fnv 0x00846c90
unsigned int FormIDConverter::RegisterFormID(unsigned int formID)
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(formID))
        return formID;

    unsigned int index = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(m_kSourceToTargetFormIDMap))->FUN_00853130(formID, (::fnv_00853130::CombatThreatRecord *&)(index)))
        return index;

    index = m_uiFormIDCount++;
    reinterpret_cast<::FUN_00844700_Class *>(&(m_kSourceToTargetFormIDMap))->FUN_00844700(formID, index);
    reinterpret_cast<::FUN_00844700_Class *>(&(m_kTargetToSourceFormIDMap))->FUN_00844700(index, formID);
    return index;
}

struct BSFile;
struct SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
    unsigned int Write(void*, unsigned int);
    bool Open();
    unsigned int GetFilePosition();
    unsigned int GetFileSize();
    void SetFilePosition(int);
    void SeekCurrent(int);
    char* GetFileName();
    static SaveLoadFile* CreateFileA(char*, bool, unsigned int);
    void SetSaveFileName(char*);
    char* GetSaveFileName();
    BSFile* QFile();
    unsigned int GetSimulatedFileSize();
    void* __vecDelDtor(unsigned int);
    char m_cFileName[260];
    BSFile* pFile;
    unsigned int m_uiBufferSize;
    unsigned int m_uiFilePosition;
};
typedef char _sizecheck_BGSSaveLoadFile[sizeof(SaveLoadFile) == 272 ? 1 : -1];
struct FUN_00846e70_shell : public FormIDConverter
{
    void LoadFormIDMap(SaveLoadFile*);
};

struct DummyPointerMap
{
};
struct FUN_00846d80_cls
{
    unsigned int RemapFormID(unsigned int);
};
// Clears the map, reads a count and that many form IDs from the file, converts each and stores both directions in the two maps.
// @fnv 0x00846e70
void FUN_00846e70_shell::LoadFormIDMap(SaveLoadFile* apFile)
{
    Clear();
    unsigned int icount = 0;
    ::ReadFileIntoBuffer(apFile, &icount, 4);
    for (unsigned int i = 0; i < icount; i++)
    {
        unsigned int iformID = 0;
        ::ReadFileIntoBuffer(apFile, &iformID, 4);
        unsigned int uiConvertedFormID = ((FUN_00846d80_cls*)this)->RemapFormID(iformID);
        if (uiConvertedFormID)
            reinterpret_cast<::FUN_00844700_Class *>((((DummyPointerMap*)this)))->FUN_00844700(uiConvertedFormID, m_uiFormIDCount);
        reinterpret_cast<::FUN_00844700_Class *>((((DummyPointerMap*)&m_kTargetToSourceFormIDMap)))->FUN_00844700(m_uiFormIDCount, uiConvertedFormID);
        m_uiFormIDCount++;
    }
}

struct FUN_00846de0_cls
{
    unsigned char __thiscall GetByteAtOffset(unsigned char param_1);
};

// @fnv 0x00846de0
unsigned char __thiscall FUN_00846de0_cls::GetByteAtOffset(unsigned char param_1)
{
    return ((unsigned char*)this)[param_1 + 0x44];
}

// Remaps a form ID's mod index through g_BGSSaveLoadGame; returns the original ID if the index is 0xFF, or 0 if the remap fails.
// @fnv 0x00846d80
unsigned int FUN_00846d80_cls::RemapFormID(unsigned int formID)
{
    unsigned char modIndex = (unsigned char)(formID >> 24);
    if (modIndex == 0xFF)
        return formID;
    {
        unsigned char newModIndex = (*reinterpret_cast<::FUN_00846de0_cls * *>(&::g_BGSSaveLoadGame))->GetByteAtOffset(modIndex);
        if (newModIndex != 0xFF)
            return (formID & 0xFFFFFF) | (newModIndex << 24);
        return 0;
    }
}

struct FormIDConverter;
struct FUN_00846d20_shell : public FormIDConverter
{
    unsigned int FUN_00846d20(unsigned int formID);
};
// @fnv 0x00846d20
unsigned int FUN_00846d20_shell::FUN_00846d20(unsigned int formID)
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(formID))
        return formID;
    unsigned int result = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x10))))->FUN_00853130(formID, (::fnv_00853130::CombatThreatRecord *&)(result)))
        return result;
    return 0;
}

struct SlotItem
{
    unsigned int m_uKey;
    void* m_pInventoryEntryData;
};

struct CleanupItem
{
};


class FUN_0044ee40_cls
{
  public:
    unsigned int unk00;
    void* m_pTailObj;
    SlotItem* m_pSlots;
    void ClearSlots();
};

// Frees each slot's item, frees the slot array, then clears the tail object.
// @fnv 0x0044ee40
void FUN_0044ee40_cls::ClearSlots()
{
    for (unsigned int u = 0; u < ((unsigned int)(::FUN_00559450((int *)this))); u++)
    {
        void* pItem = m_pSlots[u].m_pInventoryEntryData;
        void* RunFourthVirtual = pItem;
        RunFourthVirtual != 0 ? ((unsigned int)(reinterpret_cast<::FUN_0044f3b0_Class *>((((CleanupItem*)RunFourthVirtual)))->FUN_0044f3b0(1))) : 0;
    }
    {
        SlotItem* a = m_pSlots;
        ::FUN_00401030(a);
    }
    ::FUN_0044e360((unsigned long)(m_pTailObj));
}

namespace fnv_00846e00 {
struct BSFile;
struct SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
    unsigned int Write(void*, unsigned int);
    bool Open();
    unsigned int GetFilePosition();
    unsigned int GetFileSize();
    void SetFilePosition(int);
    void SeekCurrent(int);
    char* GetFileName();
    static SaveLoadFile* CreateFileA(char*, bool, unsigned int);
    void SetSaveFileName(char*);
    char* GetSaveFileName();
    BSFile* QFile();
    unsigned int GetSimulatedFileSize();
    void* __vecDelDtor(unsigned int);
    char m_cFileName[260];
    BSFile* pFile;
    unsigned int m_uiBufferSize;
    unsigned int m_uiFilePosition;
};
typedef char _sizecheck_BGSSaveLoadFile[sizeof(SaveLoadFile) == 272 ? 1 : -1];

struct FUN_00846d20_shell : public FormIDConverter
{
};

struct FUN_00846e00_cls : public FormIDConverter
{
    void FUN_00846e00(SaveLoadFile* file);
};

// Passes the count minus one and each converted index value to FUN_00845d20 with file and size 4.
// @fnv 0x00846e00
void FUN_00846e00_cls::FUN_00846e00(SaveLoadFile* file)
{
    unsigned int count = this->m_uiFormIDCount - 1;
    ::ForwardToShell((::FUN_00846330_shell *)(file), (int)(&count), 4);
    for (unsigned int i = 1; i < this->m_uiFormIDCount; i++)
    {
        unsigned int id = reinterpret_cast<::FUN_00846d20_shell *>((((FUN_00846d20_shell*)this)))->FUN_00846d20(i);
        ::ForwardToShell((::FUN_00846330_shell *)(file), (int)(&id), 4);
    }
}
}  // namespace fnv_00846e00
