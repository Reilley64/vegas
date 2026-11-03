
#include <cstdint>
#include "fnv/decl/FGOwner.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_0064db50_class.h"
#include "fnv/decl/FUN_0065cc70_Holder.h"
#include "fnv/decl/FUN_0065cea0_class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/_Dummy_0044a170.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00604000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00aaf000.h"
#include "fnv/symbols_0109b000.h"
#include "nifixedstring_decls.h"

// @fnv 0x00a2e750
NiFixedString& NiFixedString::operator=(const char* pcString)
{
    char* oldHandle = m_kHandle;
    if (oldHandle != pcString)
    {
        m_kHandle = NiGlobalStringTable::AddString(pcString);
        if (oldHandle != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(oldHandle - 8));
    }
    return *this;
}

// These trace entries are unoptimized FaceGen consumers of this inline unit.
// Keep one /O2 unit policy and preserve their original source optimization scope.
#pragma optimize("", off)
#pragma auto_inline(off)
#pragma inline_depth(0)
#include "nifixedstring_facegen.h"

// @fnv 0x0065b410
bool BSFaceGenModel::ApplyTextureCoordinate(FaceGenCoordinates* coord, NiPointer<NiTexture>& texture, unsigned int uiLimit)
{
    // MSVC9 local allocation depends on these names and declaration scopes.
    unsigned int uiWidth; // EGT basis group selected for accumulation
    FaceGenColor kView; // zero fill color
    NiPointer<NiTexture> spTexture(0);
    FaceGenImageView pkImage; // output pixel view
    texture = ((::NiTexture *)(::GetFaceGenManagerValue()));
    if (!m_kTextureSlots)
        return false;
    if (!coord)
        coord = BSFaceGenManager::GetFaceGenCoordinates();
    if (!coord)
        return false;
    FUN_00652140();
    if (!::fnv_00652040::FUN_00652040((intptr_t)(this))) {
        if (!m_kTextureSlots->m_pTextureData) {
            if (!((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((m_kTextureSlots))->FUN_004048e0()))) {
                ::fnv_00652190::FUN_00652190();
                return false;
            }
            m_kTextureSlots->m_pTextureData = FUN_00659780(((const char *)(::FUN_00559450((int *)&(m_kTextureSlots->m_kEGTFileName)))));
        }
        if (!m_kTextureSlots->m_pTextureData) {
            ::fnv_00652190::FUN_00652190();
            return false;
        }
    }
    if (!m_kTextureSlots->m_pTextureData) {
        ::fnv_00652190::FUN_00652190();
        return false;
    }
    unsigned int kColor = 0; // texture width
    unsigned int uiHeight = 0;
    if (((unsigned int)(reinterpret_cast<::FUN_0065cea0_class *>(&(m_kTextureSlots->m_pTextureData->basis[0]))->FUN_0065cea0()))) {
        kColor = ((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[0]))->FUN_0065cec0(0)))->width;
        uiHeight = ((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[0]))->FUN_0065cec0(0)))->height;
    }
    if (!kColor || !uiHeight) {
        ::fnv_00652190::FUN_00652190();
        return false;
    }
    unsigned int uiBasis;
    for (uiBasis = 0; uiBasis < 2; ++uiBasis) {
        if (reinterpret_cast<uintptr_t>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(&coord->basis[uiBasis])))->FUN_009611e0()))) < ((unsigned int)(reinterpret_cast<::FUN_0065cea0_class *>(&(m_kTextureSlots->m_pTextureData->basis[uiBasis]))->FUN_0065cea0()))) {
            ::FUN_005b5e40();
            ::fnv_00652190::FUN_00652190();
            return false;
        }
    }
    kView.a = 0.0f;
    kView.b = kView.a;
    kView.g = kView.b;
    kView.r = kView.g;
    spTexture = reinterpret_cast<NiTexture*>(new FaceGenImage(0));
    reinterpret_cast<TESRecipe*>(static_cast<NiTexture*>(spTexture))->SetRequiredSkill((::ActorValue::Index)(kColor));
    reinterpret_cast<::FUN_0061cc40_shell *>((reinterpret_cast<TESRecipe*>(static_cast<NiTexture*>(spTexture))))->FUN_0061cc40(uiHeight);
    // These scalar accessors were linker-folded with the canonical TESRecipe
    // setters. Their established decorated bindings must be retained.
    FaceGenImage* uiOutHeight = ((::FaceGenImage *)(reinterpret_cast<::FGOwner *>((reinterpret_cast<FaceGenImage*>(static_cast<NiTexture*>(spTexture))))->GetOrConvertImage()));
    reinterpret_cast<::FUN_0064db50_class *>((uiOutHeight))->FUN_0064db50(kColor * uiHeight, (intptr_t)(&kView));
    unsigned int uiRenderPassIndex = kColor; // output width
    unsigned int piAccum = uiHeight; // output height
    int* uiOutWidth = new int[kColor * uiHeight * 3]; // RGB accumulation buffer
    memset(uiOutWidth, 0, sizeof(int) * kColor * uiHeight * 3);
    uiWidth = 0;
    unsigned int ItemUpdateArray;
    if (uiLimit) {
        ItemUpdateArray = uiLimit;
        if (ItemUpdateArray > ((unsigned int)(reinterpret_cast<::FUN_0065cea0_class *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cea0())))
            ItemUpdateArray = ((unsigned int)(reinterpret_cast<::FUN_0065cea0_class *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cea0()));
    } else {
        ItemUpdateArray = ((unsigned int)(reinterpret_cast<::FUN_0065cea0_class *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cea0()));
    }
    for (unsigned int mode = 0; mode < ItemUpdateArray; ++mode) {
        if (((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cec0(mode)))->width == uiRenderPassIndex) {}
        else ::ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 1162);
        if (((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cec0(mode)))->height == piAccum) {}
        else ::ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenModel.cpp", 1163);
        FaceGenModeParameters modeData;
        modeData.weight = static_cast<int>(*((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(coord->basis[uiWidth].FUN_0060b370(mode, 0)))->FUN_00629ab0({}))) * DAT_010231d8);
        if (!modeData.weight)
            continue;
        modeData.stride = ((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cec0(mode)))->width + ((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cec0(mode)))->rowPadding;
        for (unsigned int channel = 0; channel < 3; ++channel) {
            FaceGenChannelData channelData;
            channelData.scale = static_cast<int>(((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cec0(mode)))->scale * DAT_010231d8) * modeData.weight;
            channelData.row = ((const signed char *)(reinterpret_cast<::FUN_0065cc70_Holder *>(&(((::TextureRow *)(reinterpret_cast<::Holder *>(&(m_kTextureSlots->m_pTextureData->basis[uiWidth]))->FUN_0065cec0(mode)))->rows[channel]))->FUN_0065cc70(0)));
            for (unsigned int y = 0; y < piAccum; ++y) {
                for (unsigned int x = 0; x < uiRenderPassIndex; ++x)
                    uiOutWidth[(y * uiRenderPassIndex + x) * 3 + channel] += channelData.row[x] * channelData.scale;
                channelData.row += modeData.stride;
            }
        }
    }
    for (unsigned int channel = 0; channel < 3; ++channel) {
        FaceGenOutputData outputData;
        outputData.multiplier = DAT_01065b9c;
        pkImage = (*(::FaceGenImageView *)(reinterpret_cast<::_Dummy_0044a170 *>((uiOutHeight))->FUN_0044a170({})));
        outputData.output = pkImage.FUN_0064dbd0();
        for (unsigned int y = 0; y < piAccum; ++y) {
            for (unsigned int x = 0; x < uiRenderPassIndex; ++x)
                outputData.output[(y * uiRenderPassIndex + x) * 4 + channel] = uiOutWidth[(y * uiRenderPassIndex + x) * 3 + channel] * outputData.multiplier;
        }
    }
    delete[] uiOutWidth;
    texture = static_cast<NiTexture*>(spTexture)->FUN_0064ceb0(DAT_01065b98, 255.0f, 0.5f, &gNiPoint3StartupSrc);
    ::fnv_00652190::FUN_00652190();
    return true;
}

// @fnv 0x0065c3a0
void BSFaceGenModel::ClearTextureData()
{
    if (m_kTextureSlots && m_kTextureSlots->m_pTextureData) {
        delete m_kTextureSlots->m_pTextureData;
        m_kTextureSlots->m_pTextureData = 0;
    }
}

#pragma inline_depth(255)
#pragma auto_inline(on)
#pragma optimize("", on)
