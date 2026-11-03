// gamebryo2.2/corelibs/nianimation/nitextkey.cpp: TimedTextEntry, NiTextKeyFnv (2 functions)

#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "nitextkey_decls.h"
// Reads m_fTime from the stream, then loads m_kText using the version-dependent string reader.
// @fnv 0x00a578d0
void TimedTextEntry::LoadBinary(NiStream& stream)
{
    NiBinaryStream* input = stream.m_pUnderlyingStream;
    input->Read(&m_fTime, 4);
    if (stream.m_uiNifVersion < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(stream))->FUN_00a64ea0((char **)&(m_kText));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(stream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(m_kText));
}

struct FNVBinaryInput
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiCurrentPos;
    unsigned int m_uiUnknown08;
    unsigned int(__cdecl* m_pfnRead)(FNVBinaryInput*, void*, unsigned int, unsigned int*, unsigned int);

    void Read(void* buffer, unsigned int size)
    {
        m_uiCurrentPos += m_pfnRead(this, buffer, size, &size, 1);
    }
};

struct FNVStream
{

    FNVBinaryInput* GetInput() const
    {
        return *reinterpret_cast<FNVBinaryInput* const*>(reinterpret_cast<const char*>(this) + 0x250);
    }
};

struct NiTextKeyFnv
{
    float m_fTime;
    NiFixedString m_kText;

    void ReadFromStream(FNVStream& stream);
};

// @fnv 0x00a57930
void NiTextKeyFnv::ReadFromStream(FNVStream& stream)
{
    stream.GetInput()->Read(&m_fTime, sizeof(m_fTime));
    reinterpret_cast<::FUN_00a641f0_cls *>(&(stream))->WriteObjectLink((void *)&(m_kText));
}
