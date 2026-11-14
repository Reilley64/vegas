
// src/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// Returns the address of the global pointer g_011f3f28.
#include <cstring>
// @fnv 0x00a46b60
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a57850_shell.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b300_shell.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiTextKeyFnv.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/decl/FUN_00a57890_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00a46000.h"
void* __cdecl FUN_00a46b60()
{
    return &(*reinterpret_cast<void * *>(&::g_011f3f28));
}

class NiExtraData
{
public:
    void LoadBinary(::NiStream &);
};

struct BSFadeNode
{
};

extern void* DAT_0109827c;

// @fnv 0x00a46b70
void* __cdecl FUN_00a46b70()
{
    void* p = ::operator new(0x14);
    if (p)
    {
        reinterpret_cast<::ExtraDataObject *>((static_cast<NiExtraData*>(p)))->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_0109827c;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0xc) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x10) = 0;
        return p;
    }
    return 0;
}

struct NiMemObject
{
    char _pad_0[1];
};


struct NiTextKeyExtraData : NiMemObject
{
    unsigned int m_uiNumKeys;
    void* m_pKeys;
    void* FUN_00a46ed0(unsigned int flags);
};

struct NiStream;
struct FakeBase00
{
};
struct FakeKey00
{
};
// Calls the base loader on stream, then loads each of the 0xC-count keys at offset 0x10 from the stream, returning true on success.
// @fnv 0x00a46b10
bool LoadFromStream(NiTextKeyExtraData* _this, void* _edx, NiStream* stream)
{
    if (!reinterpret_cast<::MyOwner *>((((FakeBase00*)_this)))->FUN_00a7b290((*(::NiStream *)(stream))))
        return false;
    unsigned int uiI;
    for (uiI = 0; uiI < *(unsigned int*)((char*)_this + 0xC); ++uiI)
        reinterpret_cast<::FUN_00a57850_shell *>((((FakeKey00*)((char*)*(void**)((char*)_this + 0x10) + uiI * 8))))->FUN_00a57850((*(::NiStream *)(stream)));
    return true;
}

struct A46BB0Key
{
    float m_fTime;
    int m_iValue;
};

struct A46BB0Object
{
    int unk00;
    int unk04;
    int unk08;

};

struct A46BB0KeyData : A46BB0Object
{
    unsigned int m_uiNumKeys;
    A46BB0Key* m_pKeyArray;

    bool FUN_00a46bb0(A46BB0Object* pkObject);
};

// Checks that pkObject is non-null, base-equal, has the same key count, and that every key's time and value match; returns true if so.
// @fnv 0x00a46bb0
bool A46BB0KeyData::FUN_00a46bb0(A46BB0Object* pkObject)
{
    if (!pkObject)
        return false;
    if (!reinterpret_cast<::A5d470Class *>(this)->IsSameAs((::A5d470Object *)(pkObject)))
        return false;
    A46BB0KeyData* pkOther = (A46BB0KeyData*)pkObject;
    if (m_uiNumKeys != pkOther->m_uiNumKeys)
        return false;
    for (unsigned int i = 0; i < m_uiNumKeys; i++)
    {
        if (m_pKeyArray[i].m_fTime != pkOther->m_pKeyArray[i].m_fTime ||
            m_pKeyArray[i].m_iValue != pkOther->m_pKeyArray[i].m_iValue)
            return false;
    }
    return true;
}

struct FUN_00a57870_Class
{
    void ReleaseString();
};
struct MM
{
};
struct NiStringsExtraData
{
};
struct FUN_00a46d50_class
{
    void DestroyKeyList();
};
// @fnv 0x00a46ed0
void* NiTextKeyExtraData::FUN_00a46ed0(unsigned int flags)
{
    static_cast<::FUN_00a46d50_class *>(nullptr)->DestroyKeyList();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}
// @fnv 0x00a46d50
void FUN_00a46d50_class::DestroyKeyList()
{
    *(void**)this = &DAT_0109827c;
    void* keys = *(void**)((char*)this + 0x10);
    if (keys)
    {
        int count = ((int*)keys)[-1];
        char* current = (char*)keys + count * 8;
        --count;
        if (count >= 0)
        {
            do
            {
                current -= 8;
                ((FUN_00a57870_Class*)current)->ReleaseString();
                --count;
            } while (count >= 0);
        }
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060((char*)keys - 4);
    }
    reinterpret_cast<::FUN_00a7b300_shell *>((((NiStringsExtraData*)this)))->FUN_00a7b300();
}


struct FUN_00a46b50_cls
{
    int unk00;
    int m_i04;

    FUN_00a46b50_cls* FUN_00a46b50();
};

// @fnv 0x00a46b50
FUN_00a46b50_cls* FUN_00a46b50_cls::FUN_00a46b50()
{
    m_i04 = (*reinterpret_cast<int *>(&::DAT_0109b220));
    return this;
}

struct StrArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
    __forceinline unsigned int AddInline(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
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
        return uiIndex;
    }
};



struct TextKey
{
    float m_fTime;
    const char* m_kText;
    float GetTime() const
    {
        return m_fTime;
    }
    const char* GetText() const
    {
        return m_kText;
    }
};

struct ExtraDataBase
{
    void* m_vtbl;
    void* m_pcName;
    void* m_unk08;
};

struct TextKeyExtraData : ExtraDataBase
{
    unsigned int m_uiNumKeys;
    TextKey* m_pKeys;
    void WriteToStrings(StrArray* pkStrings);
};

// Appends the base strings, the key count, and one formatted "Time : Text" entry per text key to pkStrings.
// @fnv 0x00a46ef0
void TextKeyExtraData::WriteToStrings(StrArray* pkStrings)
{
    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(pkStrings));
    pkStrings->Add(FUN_00a7d330((const char*)(*reinterpret_cast<void * *>(&::g_011f3f28))));
    pkStrings->Add(FUN_00a7d510("m_uiNumKeys", m_uiNumKeys));

    for (unsigned int i = 0; i < m_uiNumKeys; i++)
    {
        char* pcTimeString = FUN_00a7d550("Time", m_pKeys[i].GetTime());
        char* pcTextString = ::fnv_00a7d5e0::FUN_00a7d5e0("Text", m_pKeys[i].GetText());
        unsigned int uiBufferSize = strlen(pcTimeString) + strlen(pcTextString) + 4;
        char* pcString = (char*)::FUN_00aa1070(uiBufferSize);
        NiSprintf(pcString, uiBufferSize, "%s : %s", pcTimeString, pcTextString);
        char* pcEntryString = ::fnv_00a7d5e0::FUN_00a7d5e0("TextKey", pcString);
        pkStrings->AddInline(pcEntryString);
        ::FUN_00aa10f0(pcTimeString);
        ::FUN_00aa10f0(pcTextString);
        ::FUN_00aa10f0(pcString);
    }
}

class NiPSysBaseA46
{
  public:
    NiPSysBaseA46() throw();
    virtual ~NiPSysBaseA46();


    int unk04, unk08;
};

class NiPSysDerivedA46 : public NiPSysBaseA46
{
  public:
    NiPSysDerivedA46() throw()
    {
        m_pkFirst = 0;
        m_pkSecond = 0;
    }
    virtual ~NiPSysDerivedA46();

    void* m_pkFirst;
    void* m_pkSecond;
};

class NiPSysOwnerA46
{
  public:
    NiPSysBaseA46* FUN_00a46da0(void* pvProcess);
};
struct CloningProcess;
struct NiRTTI;
struct A46FixedString
{
    const char* m_kHandle;
    ~A46FixedString();
};
struct A46TextKey
{
    float m_fTime;
    A46FixedString m_kText;

    A46TextKey();
    ~A46TextKey()
    {}
    const A46FixedString& GetText() const
    {
        return m_kText;
    }
};
struct A46ExtraData
{
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    void* m_pcName;
    void* m_unk08;
};
struct A46TextKeyExtraData : A46ExtraData
{
    unsigned int m_uiNumKeys;
    A46TextKey* m_pKeys;

    bool IsExactKindOf(const NiRTTI* pkRTTI) const
    {
        return GetRTTI() == pkRTTI;
    }
    void FUN_00a46c20(A46TextKeyExtraData* pkDest, CloningProcess* kCloning);
};

// @fnv 0x00a46da0
NiPSysBaseA46* NiPSysOwnerA46::FUN_00a46da0(void* pvProcess)
{
    NiPSysDerivedA46* pkClone = new NiPSysDerivedA46;
    reinterpret_cast<::A46TextKeyExtraData *>(this)->FUN_00a46c20((::A46TextKeyExtraData *)(pkClone), (::CloningProcess *)(pvProcess));
    return pkClone;
}

class S00a46cf0_BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int m_unk08;
    unsigned int(__cdecl* m_pfnRead)(S00a46cf0_BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

template <class T> inline void NiBinaryStreamLoad(S00a46cf0_BinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

class S00a46cf0_Stream
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    S00a46cf0_BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void ReadBinaryValue(S00a46cf0_Stream& kStream, T& value)
{
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &value, 1);
}

class S00a46cf0_Entry
{
  public:
      // ReadFromStream
    unsigned int unk00;
    unsigned int unk04;
};

class S00a46cf0_Base
{
  public:
      // FUN_00a7b2c0
    void* m_ppVirtualMethodTable;
    unsigned int unk04;
    unsigned int unk08;
};

class S00a46cf0_Object : public S00a46cf0_Base
{
  public:
    void FUN_00a46cf0(S00a46cf0_Stream& kStream);  // LoadBinary
    unsigned int m_uiCount;
    S00a46cf0_Entry* m_pEntries;
};

// Calls the base LoadBinary, reads m_uiCount from kStream, then loads each of the m_uiCount entries via their LoadBinary method.
// @fnv 0x00a46cf0
void S00a46cf0_Object::FUN_00a46cf0(S00a46cf0_Stream& kStream)
{
    reinterpret_cast<::FUN_00a7b2c0_shell *>(this)->FUN_00a7b2c0((::NiStream &)(kStream));
    ReadBinaryValue(kStream, m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
        reinterpret_cast<::NiTextKeyFnv *>(&(m_pEntries[i]))->ReadFromStream((::FNVStream &)(kStream));
}

void* __cdecl FUN_00a46b60();
struct NiStream;
bool LoadFromStream(NiTextKeyExtraData* _this, void* _edx, NiStream* stream);

struct MemoryManager
{
};





inline bool A46IsExactKindOf(const NiRTTI* pkRTTI, const A46ExtraData* pkObject)
{
    if (!pkObject)
        return false;
    return pkObject->GetRTTI() == pkRTTI;
}

// @fnv 0x00a46c20
void A46TextKeyExtraData::FUN_00a46c20(A46TextKeyExtraData* pkDest, CloningProcess* kCloning)
{
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(pkDest), kCloning);
    pkDest->m_uiNumKeys = m_uiNumKeys;
    if (m_uiNumKeys > 0 && A46IsExactKindOf((const NiRTTI*)&(*reinterpret_cast<void * *>(&::g_011f3f28)), this))
    {
        pkDest->m_pKeys = new A46TextKey[m_uiNumKeys];
        for (unsigned int i = 0; i < m_uiNumKeys; i++)
        {
            pkDest->m_pKeys[i].m_fTime = m_pKeys[i].m_fTime;
            reinterpret_cast<::FUN_00a57890_shell *>(&(pkDest->m_pKeys[i]))->AssignStringRef((const char **)&(m_pKeys[i].GetText()));
        }
    }
    else
    {
        pkDest->m_pKeys = 0;
    }
}
struct BsStream;

struct DynamicMemoryAllocator
{
};


#include "fnv/native_fixed_string.h"
struct TimedTextEntry
{
    float m_fTime;
    NiFixedString m_kText;
    TimedTextEntry() throw();
public:
    void LoadBinary(::NiStream &);
};

struct NiExtraDataBase
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct NiTextKeyExtraDataStub : NiExtraDataBase
{
    unsigned int m_uiNumKeys;
    TimedTextEntry* m_pKeys;
    void FUN_00a46e00(NiStream& stream);
};

struct BsStream
{
    unsigned int unk00;
    unsigned int m_uiPosition;
    unsigned int(__cdecl* m_pfnRead)(BsStream* pSelf, unsigned int* pCount, unsigned int uiSize, unsigned int* pSize,
                                     unsigned int uiFlags);
};

struct NiStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    BsStream* m_pDataStream;
};

// @fnv 0x00a46e00
void NiTextKeyExtraDataStub::FUN_00a46e00(NiStream& stream)
{
    reinterpret_cast<::NiExtraData *>(this)->LoadBinary(stream);

    BsStream* pStream = stream.m_pDataStream;
    unsigned int uiNumKeys;
    {
        unsigned int uiSize = 4;
        pStream->m_uiPosition += pStream->m_pfnRead(pStream, &uiNumKeys, 4, &uiSize, 1);
    }

    if (uiNumKeys > 0)
    {
        TimedTextEntry* keys = new TimedTextEntry[uiNumKeys];
        for (unsigned int i = 0; i < uiNumKeys; i++)
        {
            reinterpret_cast<::TimedTextEntry *>(&(keys[i]))->LoadBinary(stream);
        }
        m_uiNumKeys = uiNumKeys;
        m_pKeys = keys;
    }
}
