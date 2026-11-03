
// src/effectsetting_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00407300: the skeleton of src/effectsetting.cpp
// with declarations corrected to what the original code does (effectsetting_decls.h: EffectSetting += void FUN_00407300();; effectsetting_decls.h: TESForm += void FUN_004855a0(); void FUN_00485680();; effectsetting_decls.h: TESFullName += void FUN_00487010();; effectsetting_decls.h: TESDescription += void FUN_00482cb0();; effectsetting_decls.h: TESIcon += void). Move the function to its real unit once
// that unit declares it this way.

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/EndianSwappableData.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00482cb0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FUN_008ce390_shell.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "effectsetting_decls_decl_effectsetting.h"

enum
{
    CHUNK_ICON = 0x4E4F4349,
    CHUNK_MODL = 0x4C444F4D,
    CHUNK_MODT = 0x54444F4D,
    CHUNK_DATA = 0x41544144,
    CHUNK_ESCE = 0x45435345
};

// @fnv 0x00407300
void EffectSetting::FUN_00407300()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(this)->FUN_00487010();
    reinterpret_cast<::FUN_00482cb0_shell *>(this)->FUN_00482cb0();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(this)->FUN_0048e370(CHUNK_ICON);
    reinterpret_cast<::FUN_004891d0_cls *>(this)->WriteToBuffer((char *)(CHUNK_MODL), (void *)(CHUNK_MODT));

    TESSound* pkCastSound = data.m_pCastSound;
    data.m_pCastSound = (TESSound*)(data.m_pCastSound ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.m_pCastSound))->FUN_0084e3a0())) : 0);
    TESSound* pkBoltSound = data.m_pBoltSound;
    data.m_pBoltSound = (TESSound*)(data.m_pBoltSound ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.m_pBoltSound))->FUN_0084e3a0())) : 0);
    TESSound* m_pContactSound = data.m_pContactSound;
    data.m_pContactSound = (TESSound*)(data.m_pContactSound ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.m_pContactSound))->FUN_0084e3a0())) : 0);
    TESSound* m_pAreaEffectSound = data.m_pAreaEffectSound;
    data.m_pAreaEffectSound = (TESSound*)(data.m_pAreaEffectSound ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.m_pAreaEffectSound))->FUN_0084e3a0())) : 0);
    TESEffectShader* pkEffectShaderSave = data.m_pEffectShader;
    data.m_pEffectShader = (TESEffectShader*)(data.m_pEffectShader ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.m_pEffectShader))->FUN_0084e3a0())) : 0);
    TESEffectShader* pkEnchantEffect = data.m_pEnchantEffectShader;
    data.m_pEnchantEffectShader =
        (TESEffectShader*)(data.m_pEnchantEffectShader ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.m_pEnchantEffectShader))->FUN_0084e3a0())) : 0);
    TESObjectLIGH* pkLight = data.apTargetLight;
    data.apTargetLight = (TESObjectLIGH*)(data.apTargetLight ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.apTargetLight))->FUN_0084e3a0())) : 0);
    TESForm* savedPAssociatedItemOriginal = data.m_pAssociatedForm;
    data.m_pAssociatedForm = (TESForm*)(data.m_pAssociatedForm ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(data.m_pAssociatedForm))->FUN_0084e3a0())) : 0);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::EndianSwappableData *>(&(data))->SwapEndianFields();
    ::AppendChunk(CHUNK_DATA, &data, sizeof(data));
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::EndianSwappableData *>(&(data))->SwapEndianFields();

    data.m_pCastSound = pkCastSound;
    data.m_pBoltSound = pkBoltSound;
    data.m_pContactSound = m_pContactSound;
    data.m_pAreaEffectSound = m_pAreaEffectSound;
    data.m_pEffectShader = pkEffectShaderSave;
    data.m_pEnchantEffectShader = pkEnchantEffect;
    data.apTargetLight = pkLight;
    data.m_pAssociatedForm = savedPAssociatedItemOriginal;

    EffectSetting* savedPkEffect;
    for (BSSimpleList<EffectSetting*>* pkIter = &counterEffects; pkIter && (savedPkEffect = ((::EffectSetting *)(new ((void *)(pkIter)) ::Vec3()))) != 0;
         pkIter = ((::BSSimpleList< ::EffectSetting *> *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070())))
        ::FUN_00485910(CHUNK_ESCE, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(savedPkEffect))->FUN_0084e3a0())));

    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}
