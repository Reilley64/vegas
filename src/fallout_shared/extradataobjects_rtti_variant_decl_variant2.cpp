
// src/fallout_shared/extradataobjects_rtti_variant_decl_variant2.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00433db0: the skeleton of src/fallout_shared/extradataobjects_rtti_variant.cpp
// with declarations corrected to what the original code does (extradataobjects_private_packet_rtti_variant.h: class TESObjectREFR { public: virtual ~TESObje -> class TESObjectREFR : public TESForm { public:; extradataobjects_private_packet_rtti_variant.h: TESForm += TESFile* FUN_00484e60(int index);; extradataobjects_additions.h: ExtraDecalRefs += void FUN_004). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/extradataobjects_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR). The skeleton of src/fallout_shared/extradataobjects.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00403a00_class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0040f700_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00567e10__FUN_00567e10_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011de000.h"
#include "extradataobjects_private_packet_rtti_variant_decl_extradataobjects_rtti_variant2.h"
// @fnv 0x00877a30
template <> TESObjectREFR*& NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >::GetAt(unsigned int index)
{
    return data[index];
}
#include "extradataobjects_additions_decl_extradataobjects_rtti_variant2.h"
int LockExtraData::EnumToNumericValue(LOCK_LEVEL level)
{
    int value = 0;
    switch (level)
    {
    case LOCK_LEVEL_LL_VERYEASY:
        value = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011c3a4c))))))->i;
        break;
    case LOCK_LEVEL_LL_EASY:
        value = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011c3a30))))))->i;
        break;
    case LOCK_LEVEL_LL_AVERAGE:
        value = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011c3a00))))))->i;
        break;
    case LOCK_LEVEL_LL_HARD:
        value = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011c3ab0))))))->i;
        break;
    case LOCK_LEVEL_LL_VERYHARD:
        value = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011c399c))))))->i;
        break;
    case LOCK_LEVEL_LL_IMPOSSIBLE:
        value = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011c3a24))))))->i;
        break;
    }
    return value;
}
// Copies source into pString, reallocating when needed, and returns whether the resulting string is non-empty.
// @fnv 0x00438470
template <> bool BSStringT<char>::Set(const BSStringT<char>& source)
{
    unsigned int length = ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(source))->FUN_004048e0()));
    if (length <= GetMaxLength())
    {
        if (length)
            memcpy(pString, ((const char *)(::FUN_00559450((int *)&(source)))), length + 1);
        else
        {
            if (pString)
                delete[] pString;
            pString = 0;
            length = 0;
            reinterpret_cast<::FUN_00403a00_class *>(this)->FUN_00403a00(length);
        }
    }
    else
    {
        char* old = pString;
        pString = new char[length + 1];
        memcpy(pString, ((const char *)(::FUN_00559450((int *)&(source)))), length + 1);
        if (old)
            delete[] old;
        reinterpret_cast<::FUN_00403a00_class *>(this)->FUN_00403a00(length);
    }
    SetLength(length);
    return length != 0;
}


// Walks m_kDecalReferences, resolving each decal's m_pHitReference form ID against the given TESForm and removing entries that cannot be resolved.
// @fnv 0x00433db0
void ExtraDecalRefs::FUN_00433db0(TESForm* form)
{
    BSSimpleList<ReferenceIntersectionData*>* position = &m_kDecalReferences;
    BSSimpleList<ReferenceIntersectionData*>* previous = 0;
    while (position && !position->IsEmpty())
    {
        bool removed = false;
        ReferenceIntersectionData* decal = ((::ReferenceIntersectionData *)(new ((void *)(position)) ::Vec3()));
        unsigned int formID = reinterpret_cast<unsigned int>(decal->m_pHitReference);
        ResolveFormID(&formID, form->GetFile(-1));
        TESObjectREFR* resolvedB = dynamic_cast<TESObjectREFR*>(FUN_004839c0(formID));
        if (!resolvedB)
        {
            ::FUN_005b5e40();
            if (previous)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)(decal));
                position = ((::BSSimpleList< ::ReferenceIntersectionData *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            }
            else
            {
                position->RemoveHead();
            }
            delete decal;
            decal = 0;
            removed = true;
        }
        else
        {
            decal->m_pHitReference = resolvedB;
        }
        if (!removed)
        {
            previous = position;
            position = ((::BSSimpleList< ::ReferenceIntersectionData *> *)(reinterpret_cast<::Callees *>((position))->FUN_00726070()));
        }
    }
}
