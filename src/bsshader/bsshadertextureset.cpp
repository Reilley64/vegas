// bsshader/bsshadertextureset.cpp: BipedAnim, BSShaderTextureSet (8 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a5d2f0_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a64160_cls.h"
#include "fnv/decl/FUN_00a64ce0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "bsshadertextureset_types_BIPED_BONE.h"
#include "bsshadertextureset_types_BipedAnim.h"
#include "bsshadertextureset_types_NiTexture.h"
#include "bsshadertextureset_types_NiStream.h"
#include "bsshadertextureset_stream.h"
#include "bsshadertextureset_decls.h"
#include "bsshadertextureset_types_BSShaderManager.h"
#include "bsshadertextureset_types_BSShaderTextureSet.h"

// @fnv 0x004ab230
#pragma optimize("", off)
#pragma optimize("y", off)
NiNode* BipedAnim::GetBoneNode(BIPED_BONE boneIndex)
{
    return bone[boneIndex].pParent;
}
#pragma optimize("y", on)
#pragma optimize("", on)

// Looks up the texture name for a texture type, resolves it via BSShaderManager::GetTexture, and assigns it to textureOut with refcount handling.
// @fnv 0x00ba87f0
void BSShaderTextureSet::GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& textureOut)
{
    NiPointer<NiTexture> texture;
    const char* textureName = GetTexture(textureType);
    if (textureName)
        BSShaderManager::GetTexture(textureName, true, texture, true, textureType == BSShaderProperty::TEXTYPE_ENV);
    if (textureOut.m_pObject != texture.m_pObject)
    {
        NiTexture* previous = textureOut.m_pObject;
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        textureOut.m_pObject = texture.m_pObject;
        if (texture.m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&texture.m_pObject->m_uiRefCount));
    }
}

struct FUN_00ba88d0_shell : public BSShaderTextureSet
{
    void LoadTextureSet(NiStream*);
};

// @fnv 0x00ba88d0
void FUN_00ba88d0_shell::LoadTextureSet(NiStream* kStream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(*kStream));
    int count = 0;
    char* pcstring = 0;
    NiBinaryStream* pkStream = kStream->m_pUnderlyingStream;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiStreamFlags +=
            (pkStream->m_pfnRead)(
                pkStream, &count, 4, &uiBytesRead, 1);
    }
    for (int i = 0; i < count; ++i)
    {
        reinterpret_cast<::FUN_00a64ce0_shell *>((kStream))->FUN_00a64ce0((char **)&(pcstring));
        if (i >= 0)
        {
            reinterpret_cast<::TextString *>(&((&this->m_kTextureNames[0])[i]))->FUN_004037f0(pcstring, 0);
        }
        ::FUN_00aa10f0(pcstring);
        pcstring = 0;
    }
}

struct FUN_00ba89e0_shell : public BSShaderTextureSet
{
    void FUN_00ba89e0(int, char*);
};

// @fnv 0x00ba89e0
void FUN_00ba89e0_shell::FUN_00ba89e0(int aiType, char* apFilename)
{
    reinterpret_cast<::TextString *>(&((&this->m_kTextureNames[0])[aiType]))->FUN_004037f0(apFilename, 0);
}

// @fnv 0x00ba87e0
int FUN_00ba87e0(int* self, int unused, int index)
{
    return self[index * 2 + 2];
}

// @fnv 0x00a81fe0
void __cdecl FUN_00a81fe0(int a)
{
    reinterpret_cast<::FUN_00a5d2f0_class *>((a))->FUN_00a5d2f0({});
}


// @fnv 0x00a724d0
void FUN_00a724d0()
{
    ::FUN_00a89af0({});
}

template <class T> inline void NiStreamSaveBinaryBA89(NiBinaryStream* pkStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    pkStream->m_uiStreamFlags += pkStream->m_pfnWrite(pkStream, &value, sizeof(T), &uiSize, 1);
}

class BSShaderTextureSetBA89 : public BSShaderTextureSet
{
  public:
    void FUN_00ba8970(NiStream& stream);
};

// Links the object into the stream, writes the texture count 6, and writes each of the six m_kTextureNames strings to the stream.
// @fnv 0x00ba8970
void BSShaderTextureSetBA89::FUN_00ba8970(NiStream& stream)
{
    ::FUN_00a89af0((int)(((NiObjectCall*)this)));

    unsigned int uiTextureCount = 6;
    NiStreamSaveBinaryBA89(stream.m_pBackingStream, uiTextureCount);

    for (int i = 0; i < 6; i++)
        reinterpret_cast<::FUN_00a64160_cls *>(&(stream))->FUN_00a64160(m_kTextureNames[i].pString);
}
