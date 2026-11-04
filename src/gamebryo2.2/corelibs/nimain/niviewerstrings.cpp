
// src/gamebryo2.2/corelibs/nimain/niviewerstrings.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niviewerstrings.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstring>
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00aa1000.h"
#include <cstdint>
#include "fnv/decl/FUN_00a5ea70_t.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01204000.h"
// Allocates len+5 bytes and formats "%s = %c" from str and c into the new buffer, returning it.
// @fnv 0x00a7d3d0
void* __cdecl FormatStringAssignment(const char* str, char cValue)
{
    size_t len = strlen(str);
    char* pcBuffer = static_cast<char*>(::FUN_00aa1070(len + 5));
    ::NiSprintf(pcBuffer, len + 5, "%s = %c", str, cValue);
    return pcBuffer;
}


// Allocates a buffer sized from strlen(name) plus 0xf and writes "%s = %d" with name and value into it, returning the buffer.
// @fnv 0x00a7d4d0
char* __cdecl FUN_00a7d4d0(const char* name, int value)
{
    size_t len = strlen(name);
    char* buf = static_cast<char*>(::FUN_00aa1070(len + 0xf));
    ::NiSprintf(buf, len + 0xf, "%s = %d", name, value);
    return buf;
}

namespace fnv_00a7d5e0 {

// Allocates a buffer and formats "name = value" (or "name = NULL" when value is null), returning the buffer.
// @fnv 0x00a7d5e0
char* FUN_00a7d5e0(char const* name, char const* value)
{
    if (value)
    {
        unsigned int len = strlen(name) + strlen(value) + 4;
        char* buf = static_cast<char*>(::FUN_00aa1070(len));
        ::NiSprintf(buf, len, "%s = %s", name, value);
        return buf;
    }
    else
    {
        unsigned int len = strlen(name) + 8;
        char* buf = static_cast<char*>(::FUN_00aa1070(len));
        ::NiSprintf(buf, len, "%s = NULL", name);
        return buf;
    }
}
}  // namespace fnv_00a7d5e0

// Allocates strlen(str)+9 bytes with NiMalloc and formats "--- %s ---" into it, returning the buffer.
// @fnv 0x00a7d330
char* FUN_00a7d330(const char* pcText)
{
    unsigned int size = strlen(pcText) + 9;
    char* buf = (char*)::FUN_00aa1070(size);
    ::NiSprintf(buf, size, "--- %s ---", pcText);
    return buf;
}

// Allocates a buffer sized to the name plus 9 and formats it as "name = true" or "name = false" depending on value, returning the buffer.
// @fnv 0x00a7d370
char* FUN_00a7d370(const char* name, bool value)
{
    int size = (int)strlen(name) + 9;
    char* buf = (char*)::FUN_00aa1070(size);
    if (value)
        ::NiSprintf(buf, size, "%s = true", name);
    else
        ::NiSprintf(buf, size, "%s = false", name);
    return buf;
}

// Formats str and value into a newly allocated buffer as "%s = %u" and returns it.
// @fnv 0x00a7d410
char* __cdecl FUN_00a7d410(const char* pcName, unsigned char value)
{
    int len = strlen(pcName);
    char* buf = (char*)::FUN_00aa1070(len + 7);
    ::NiSprintf(buf, len + 7, "%s = %u", pcName, value);
    return buf;
}

// Allocates a buffer sized to the string plus 10, formats "str = value" into it with _NiSprintf, and returns the buffer.
// @fnv 0x00a7d450
char* __cdecl FUN_00a7d450(const char* pcName, short value)
{
    unsigned int size = strlen(pcName) + 10;
    char* buf = (char*)::FUN_00aa1070(size);
    ::NiSprintf(buf, size, "%s = %hd", pcName, value);
    return buf;
}

// Allocates a buffer sized for name plus 9 bytes and writes "name = value" into it with the given unsigned short value, returning the buffer.
// @fnv 0x00a7d490
char* __cdecl FUN_00a7d490(const char* name, unsigned short value)
{
    int size = strlen(name) + 9;
    char* buf = (char*)::FUN_00aa1070(size);
    ::NiSprintf(buf, size, "%s = %hu", name, value);
    return buf;
}

// Allocates a buffer sized to the string length plus 14 and formats "%s = %u" from the string and unsigned value into it, returning the buffer.
// @fnv 0x00a7d510
char* __cdecl FUN_00a7d510(const char* a, unsigned int uiValue)
{
    unsigned int len = strlen(a) + 14;
    char* buf = (char*)::FUN_00aa1070(len);
    ::NiSprintf(buf, len, "%s = %u", a, uiValue);
    return buf;
}

// Allocates a buffer sized to str plus 20 bytes and writes "str = val" into it with %g formatting, returning the buffer.
// @fnv 0x00a7d550
char* __cdecl FUN_00a7d550(const char* str, float fValue)
{
    unsigned int size = strlen(str) + 20;
    char* buf = (char*)::FUN_00aa1070(size);
    ::NiSprintf(buf, size, "%s = %g", str, fValue);
    return buf;
}

// Allocates a buffer sized to the name plus 16 bytes and formats "name = pointer" into it, returning the buffer.
// @fnv 0x00a7d5a0
char* __cdecl FUN_00a7d5a0(const char* name, void* value)
{
    unsigned int len = strlen(name) + 16;
    char* buf = (char*)::FUN_00aa1070(len);
    ::NiSprintf(buf, len, "%s = %p", name, value);
    return buf;
}

struct ViewerStrings
{
    virtual ~ViewerStrings();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;
        unsigned short i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = 0;
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }
        char** pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = Alloc(m_usMaxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = 0;
        }
        else
        {
            m_pBase = 0;
        }
        Free(pSaveBase);
    }
    static char** Alloc(unsigned int n)
    {
        return (char**)::FUN_00aa1070(n * sizeof(char*));
    }
    static void Free(char** p)
    {
        ::FUN_00aa10f0(p);
    }
    void SetAt(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
    unsigned int Add(char* const& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

struct RTTI_Stub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};


struct NiFixedString
{
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

struct NamedObject
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    NiFixedString m_kName;
    const char* GetName() const
    {
        return m_kName;
    }
};

struct ListItem
{
    ListItem* m_pkNext;
    ListItem* m_pkPrev;
    NamedObject* m_element;
};

struct ObjList
{
    ListItem* m_pkHead;
    ListItem* m_pkTail;
    ListItem* GetHeadPos() const
    {
        return m_pkHead;
    }
    NamedObject* GetNext(ListItem*& kPos) const
    {
        NamedObject* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct EmitterBase
{
};

struct MeshEmitter : EmitterBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    ObjList m_kThirdFollowingStreamField;
    int unkb4;
    unsigned short unkb8;
    unsigned short m_usIndex;
    int unkbc;
    int unkc0;
    unsigned int m_uiMax;

    void FUN_00c5e9f0(ViewerStrings* pkStrings);
};

// @fnv 0x00c5e9f0
void MeshEmitter::FUN_00c5e9f0(ViewerStrings* pkStrings)
{
    reinterpret_cast<::FUN_00a5ea70_t *>(this)->FUN_00a5ea70((::StrArr *)(pkStrings));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d330((*reinterpret_cast<::RTTI_Stub *>(&::g_0120436c)).GetName())));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d510("Index", m_uiMax)));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d490("Max Emitter Objs", m_usIndex)));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d330("Emitter Objs")));
    ListItem* kPos = m_kThirdFollowingStreamField.GetHeadPos();
    while (kPos)
    {
        NamedObject* pkObj = m_kThirdFollowingStreamField.GetNext(kPos);
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d5a0(pkObj->GetName() ? pkObj->GetName() : "No Name", pkObj)));
    }
}
