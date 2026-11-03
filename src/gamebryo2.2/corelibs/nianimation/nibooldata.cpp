// gamebryo2.2/corelibs/nianimation/nibooldata.cpp: NiBoolData, NiBoolDataSaver (7 functions)

#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "nibooldata_decls.h"

// @fnv 0x00a53a50
void NiBoolData::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream));
    AnimationKey::KeyType type = AnimationKey::STEPKEY;
    unsigned int numKeys;
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(numKeys));
    if (numKeys > 0)
    {
        if (stream.m_uiNifVersion >= 0x0a010068)
            ReadBinaryValue(stream, type);
        m_ucKeyDataSize = BooleanKey::GetKeySize(type);
        BooleanKey* keys = static_cast<BooleanKey*>(BooleanKey::GetLoadFunction(type)(stream, numKeys));
        BooleanKey::GetFillDerivedFunction(type)(keys, numKeys, m_ucKeyDataSize);
        SetColorKeys(keys, numKeys, type);
    }
}

// Replaces the stored key array: frees the old keys, then stores the new keys, count, key type and key size, or clears them when keys is null or numKeys is zero.
// @fnv 0x00a538b0
void NiBoolData::SetColorKeys(BooleanKey* keys, unsigned int numKeys, AnimationKey::KeyType eKeyType)
{
    if (m_pKeyArray)
        BooleanKey::GetDeleteFunction(m_eRequestType)(m_pKeyArray);
    if (keys && numKeys)
    {
        m_ucKeyDataSize = BooleanKey::GetKeySize(eKeyType);
        m_pKeyArray = keys;
        m_uiNumKeys = numKeys;
        m_eRequestType = eKeyType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = AnimationKey::NOINTERP;
        m_ucKeyDataSize = 0;
    }
}

struct StandIn_00a537a0
{
    int _pad[2];
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    unsigned int m_eRequestType;
    void FUN_00a537a0(float m_fStartTime, float m_fMaximumDistance);
};
// @fnv 0x00a537a0
void StandIn_00a537a0::FUN_00a537a0(float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = m_pKeyArray;
    ::UpdateSlotStates(5, m_eRequestType, (void **)&(pkKeys), (int *)&(m_uiNumKeys), m_fStartTime, m_fMaximumDistance);
    m_pKeyArray = pkKeys;
}

struct StrArr
{
    void* _pad00[2];
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned short _pad01;
    unsigned short m_uiGrowSize;

};

struct GlobalObjectO2_00a7b610
{
    void* pObject;
};



struct FUN_00a53ba0_shell
{
    void* _pad00[2];
    unsigned int m_uiNumKeys;

    void FUN_00a53ba0(StrArr*);
};

// @fnv 0x00a53ba0
void FUN_00a53ba0_shell::FUN_00a53ba0(StrArr* apViewerStrings)
{
    reinterpret_cast<::A5D6E0This *>((apViewerStrings))->AppendCameraPathEntries({});

    char* pString = static_cast<char*>(((void *)(::FUN_00a7d330((const char *)(::g_011f4054.pObject)))));
    unsigned int uiIndex = apViewerStrings->m_uiSize;
    unsigned int uiCapacity = apViewerStrings->m_uiCapacity;

    if (uiIndex >= uiCapacity)
        reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(apViewerStrings->m_uiGrowSize + uiIndex);

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apViewerStrings))->SetAt(uiIndex, pString);

    pString = FUN_00a7d510("m_uiNumKeys", m_uiNumKeys);
    uiIndex = apViewerStrings->m_uiSize;
    uiCapacity = apViewerStrings->m_uiCapacity;

    if (uiIndex >= uiCapacity)
        reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(apViewerStrings->m_uiGrowSize + uiIndex);

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apViewerStrings))->SetAt(uiIndex, pString);
}

typedef bool(__cdecl* FUN_00a53830_elemcmp)(void* a, void* b);
extern FUN_00a53830_elemcmp DAT_011f3b58[];

class FUN_00a53830_cls
{
  public:
    int unk00;
    int unk04;
    unsigned int m_uiCount;
    unsigned char* m_pData;
    unsigned int m_uiType;
    unsigned char m_ucStride;
    bool Equals(FUN_00a53830_cls* other);
};

// Compares this object with other via IsSameAs, count, type and stride, then element-wise using DAT_011f3b58[m_uiType]; returns true if all match.
// @fnv 0x00a53830
bool FUN_00a53830_cls::Equals(FUN_00a53830_cls* other)
{
    if (!reinterpret_cast<::A5d470Class *>(this)->IsSameAs((::A5d470Object *)(other)))
    {
        return false;
    }
    if (m_uiCount != other->m_uiCount)
    {
        return false;
    }
    if (m_uiType != other->m_uiType)
    {
        return false;
    }
    if (m_ucStride != other->m_ucStride)
    {
        return false;
    }
    FUN_00a53830_elemcmp pElemCmp = DAT_011f3b58[m_uiType];
    for (unsigned int uiIndex = 0; uiIndex < m_uiCount; ++uiIndex)
    {
        unsigned int off = (unsigned int)m_ucStride * uiIndex;
        unsigned char* pOtherData = other->m_pData + off;
        unsigned char* pThisData = m_pData + off;
        if (!pElemCmp(pThisData, pOtherData))
        {
            return false;
        }
    }
    return true;
}

typedef void(__cdecl* NiBoolSaveKeysFunction)(NiStream&, BooleanKey*, unsigned int);
struct NiBinaryWriter
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryWriter*, const void*, unsigned int, unsigned int*, unsigned int);
    template <class T> inline void BinaryWrite(const T& value)
    {
        unsigned int size = sizeof(T);
        m_uiStreamFlags += m_pfnWrite(this, &value, size, &size, 1);
    }
};
template <class T> inline void WriteValue(NiStream& stream, const T& value)
{
    reinterpret_cast<NiBinaryWriter*>(stream.m_pBackingStream)->BinaryWrite(value);
}
struct NiBoolDataSaver
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiNumKeys;
    BooleanKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SaveBoolData(NiStream&);
};
// @fnv 0x00a53b20
void NiBoolDataSaver::SaveBoolData(NiStream& stream)
{
    ::FUN_00a89af0((int)this);
    WriteValue(stream, m_uiNumKeys);
    if (m_uiNumKeys > 0)
    {
        WriteValue(stream, m_eRequestType);
        DAT_011f3ac8[m_eRequestType](stream, m_pKeyArray, m_uiNumKeys);
    }
}


struct FUN_00a53910_shell : NiBoolData
{
    void __thiscall FUN_00a53910(float startTime, float endTime, NiPointer<NiBoolData>& output);
};

// Clones this NiBoolData, processes its keys with the requested time range when present, and assigns the result to output.
// @fnv 0x00a53910
void FUN_00a53910_shell::FUN_00a53910(float startTime, float endTime, NiPointer<NiBoolData>& output)
{
    NiBoolData* original = 0;
    reinterpret_cast<::NiObjectD510 *>(this)->FUN_00a5d510((::NiPointerD510 &)(original));

    NiBoolData* copy = original;
    if (copy != 0)
        copy->IncRefCount();

    if (m_uiNumKeys > 0)
    {
        BooleanKey* keys = 0;
        unsigned int count = 0;
        ::FUN_00a3d630(5, (*(int *)&(m_eRequestType)), m_pKeyArray, m_uiNumKeys, startTime, endTime, (void **)(::BooleanKey **)(&keys), (int *)(unsigned int *)(&count));
        copy->SetColorKeys(keys, count, m_eRequestType);
    }

    NiBoolData* previous = output.m_pObject;
    if (previous != copy)
    {
        if (previous != 0)
            previous->DecRefCount();

        output.m_pObject = copy;
        if (copy != 0)
            copy->IncRefCount();
    }
    if (copy != 0)
        copy->DecRefCount();
    if (original != 0)
        original->DecRefCount();
}
