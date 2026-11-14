
// src/havok/common/serialize/util/hknativepackfileutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hknativepackfileutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "havok/NativePackfile.h"
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00d9ec10_cls.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00dc0000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010d6000.h"
#include "fnv/symbols_011b7000.h"
#include "fnv/symbols_01268000.h"
extern char DAT_010d6ab4[];
// @fnv 0x00dc0eb0
void* __cdecl FUN_00dc0eb0() { return DAT_010d6ab4; }

struct StructureLayoutRules
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};


struct hkPackfileHeader
{
    unsigned int m_magic0;
    unsigned int m_magic1;
    int m_uiUserTag;
    int m_iFileVersion;
    unsigned char m_layoutRules_0;
    unsigned char m_layoutRules_1;
    unsigned char m_layoutRules_2;
    unsigned char m_layoutRules_3;
    int m_iNumSections;
    int m_iContentsSectionIndex;
    int m_iContentsSectionOffset;
    int m_iContentsClassNameSectionIndex;
    int m_iContentsClassNameSectionOffset;
    unsigned char m_contentsVersion_0;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    int m_flags;
    int unk3c;

    hkPackfileHeader()
    {
        ::FUN_00cb1280(this, -1, sizeof(*this));
        m_magic0 = 0x57e0e057;
        m_magic1 = 0x10c0c010;
        m_contentsVersion_0 = 0;
    }
};

// @fnv 0x00dc0640
int __cdecl ValidatePackfileHeader(const hkPackfileHeader* header, const char** outError)
{
    if (!header)
    {
        if (outError)
            *outError = "Pointer is null";
        return 1;
    }

    hkPackfileHeader defaultHeader;
    if (header->m_magic0 != defaultHeader.m_magic0)
        goto bad_magic;
    if (header->m_magic1 != defaultHeader.m_magic1)
    {
    bad_magic:
        if (outError)
            *outError = "Missing packfile magic header. Is this from a binary file?";
        return 1;
    }

    const StructureLayoutRules& hostRules = (*reinterpret_cast<::StructureLayoutRules *>(&::DAT_011b7b88));
    if (header->m_layoutRules_0 != hostRules.m_ucBytesInPointer)
    {
        if (outError)
            *outError = "Trying to process a binary file with a different pointer size than this platform.";
        return 1;
    }
    if (header->m_layoutRules_1 != hostRules.m_bLittleEndian)
    {
        if (outError)
            *outError = "Trying to process a binary file with a different endian than this platform.";
        return 1;
    }
    if (header->m_layoutRules_2 != (*reinterpret_cast<::StructureLayoutRules *>(&::DAT_011b7b88)).m_bReusePaddingOptimization)
    {
        if (outError)
            *outError = "Trying to process a binary file with a different padding optimization than this platform.";
        return 1;
    }
    if (header->m_layoutRules_3 != (*reinterpret_cast<::StructureLayoutRules *>(&::DAT_011b7b88)).m_bEmptyBaseClassOptimization)
    {
        if (outError)
            *outError =
                "Trying to process a binary file with a different empty base class optimization than this platform.";
        return 1;
    }
    if (((uintptr_t)header & 3) != 0)
    {
        if (outError)
            *outError = "Packfile data source needs to be 4 byte aligned";
        return 1;
    }
    if (header->m_contentsVersion_0 == 0xff)
    {
        if (outError)
            *outError = "Packfile file format is too old";
        return 1;
    }
    if (::fnv_00cb0fa0::FUN_00cb0fa0((const char *)(const void *)(&header->m_contentsVersion_0), (const char *)(const void *)(FUN_00dc0fb0())) != 0)
    {
        if (outError)
            *outError = "Packfile contents are not up to date";
        return 1;
    }

    return 0;
}

struct Entry_dc07b0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct Table_dc07b0
{
    Entry_dc07b0* entries;
};

// @fnv 0x00dc07b0
static __declspec(noinline) int FUN_00dc07b0(Table_dc07b0* apTable, int aiIndex, int a, int b)
{
    if (apTable->entries[aiIndex].unk18 != 0)
    {
        return apTable->entries[aiIndex].unk14 + a + b;
    }
    return 0;
}

volatile int g_idx_dc07b0;
volatile int g_a_dc07b0;
volatile int g_b_dc07b0;
Table_dc07b0* volatile g_t_dc07b0;
volatile int g_out_dc07b0;

void CallTarget_dc07b0()
{
    g_out_dc07b0 = FUN_00dc07b0(g_t_dc07b0, g_idx_dc07b0, g_a_dc07b0, g_b_dc07b0);
}


#include "generated/data/havok/common/serialize/util/hknativepackfileutils.inc"
