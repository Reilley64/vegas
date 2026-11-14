// fallout_shared/containeritemextra.cpp: ContainerItemExtra, TESLeveledList (9 functions)

#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0046dce0_class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "containeritemextra_leveledlist.h"
#include "layout_support.h"
#include "TESForm.h"
#include "TESGlobal.h"

enum
{
    kContainerItemExtraChunk = 0x44454F43
};

// Raw image of the ownership chunk. Plain data so Load can fill it with
// GetChunkData; Endian is provided by the engine for byteswapped files.
struct ContainerItemExtraFileData
{
    TESForm* m_pForm;
    unsigned int m_cRank;
    float m_fHealth;

};

// members without the member functions matched in this unit.
class ContainerItemExtra
{
  public:
    TESForm* m_pForm;
    union
    {
        TESGlobal* m_pGlobal;
        int m_cRank;
        unsigned int m_uiRankFlags;
    };
    float m_fHealth;

    ContainerItemExtra();
    bool Load(TESFile* file);
    bool Compare(ContainerItemExtra* other);
    void Copy(ContainerItemExtra* other);
    bool IsDefault();
};

// Initializes the form pointer and union member to null and sets the float value to 1.0.
// @fnv 0x0040e690
ContainerItemExtra::ContainerItemExtra()
{
    m_pForm = 0;
    m_pGlobal = 0;
    m_fHealth = 1.0f;
}

// @fnv 0x0040e780
bool ContainerItemExtra::Load(TESFile* file)
{
    bool loaded = false;
    if (file)
    {
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == kContainerItemExtraChunk)
        {
            ContainerItemExtraFileData fileData;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&fileData), sizeof(fileData));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::Class005a6b10 *>(&(fileData))->FUN_005a6b10();
            m_pForm = fileData.m_pForm;
            m_uiRankFlags = fileData.m_cRank;
            m_fHealth = fileData.m_fHealth;
            loaded = true;
        }
    }
    return loaded;
}

// Returns true if other is null or if any of the three Id fields differ from other's; otherwise returns false.
// @fnv 0x0040e920
bool ContainerItemExtra::Compare(ContainerItemExtra* other)
{
    if (!other)
        return true;
    if (m_pForm != other->m_pForm)
        return true;
    if (m_pGlobal != other->m_pGlobal)
        return true;
    if (m_fHealth != other->m_fHealth)
        return true;
    return false;
}

// Copies the three fields from other into this object when other is non-null.
// @fnv 0x0040e980
void ContainerItemExtra::Copy(ContainerItemExtra* other)
{
    if (other)
    {
        m_pForm = other->m_pForm;
        m_pGlobal = other->m_pGlobal;
        m_fHealth = other->m_fHealth;
    }
}

// @fnv 0x0040e9c0
bool ContainerItemExtra::IsDefault()
{
    if (m_pForm)
        return false;
    if (m_fHealth != 1.0)
        return false;
    return true;
}

// @fnv 0x0042e680
void TESLeveledList::FUN_0042e680(unsigned char chance)
{
    m_pChanceGlobal = chance;
}

// Returns whether the absolute difference between aX and aY is less than afPrecision, or false if afPrecision is negative.
// @fnv 0x0040eb10
bool __cdecl FUN_0040eb10(float aX, float aY, float afPrecision)
{
    if (afPrecision < 0.0)
        return false;
    if (aX > aY)
        return aX - aY < afPrecision;
    else
        return aY - aX < afPrecision;
}

struct FUN_0040eb90_shell : public ContainerItemExtra
{
    void FUN_0040eb90(float);
};


// @fnv 0x0040eb90
void FUN_0040eb90_shell::FUN_0040eb90(float afHealthPerc)
{
    m_fHealth = FUN_00404010(0.0f, FUN_0040ebd0(1.0f, afHealthPerc));
}

struct Holder0040e9f0
{
    TESForm* m_pForm;
    int m_cRank;
    float m_fHealth;

    void* GetValueIfFormType42();
    void WriteToChunk();
};


// @fnv 0x0040e6c0
void Holder0040e9f0::WriteToChunk()
{
    if (reinterpret_cast<ContainerItemExtra*>(this)->IsDefault())
        return;

    void* m_pGlobal;
    ContainerItemExtraFileData fileData;

    if (this->m_pForm != 0)
    {
        fileData.m_pForm = reinterpret_cast<TESForm*>(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->m_pForm))->FUN_0084e3a0())));

        m_pGlobal = this->GetValueIfFormType42();
        if (m_pGlobal != 0)
            fileData.m_cRank = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(m_pGlobal)))->FUN_0084e3a0()));
        else
            fileData.m_cRank = this->m_cRank;
    }
    else
    {
        fileData.m_pForm = 0;
        fileData.m_cRank = 0;
    }

    fileData.m_fHealth = this->m_fHealth;

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>(&(fileData))->FUN_005a6b10();

    ::AppendChunk(kContainerItemExtraChunk, &fileData, 0xc);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>(&(fileData))->FUN_005a6b10();
}
