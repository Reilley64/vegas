#ifndef FNV_MOBILEOBJECT_UNIT_H
#define FNV_MOBILEOBJECT_UNIT_H

#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "mobileobject_decls.h"
#include "mobileobject_topicinfo.h"

#ifdef FNV_MOBILEOBJECT_H_UNIT
// @fnv 0x008ae4c0
NiPoint3* MobileObject::GetPos() const
{
    if (!reinterpret_cast<::FUN_005a2030_shell *>((void *)this)->FUN_005a2030())
        return reinterpret_cast<NiPoint3*>(
            reinterpret_cast<TESTopicInfo*>(const_cast<MobileObject*>(this))->GetAddTopicList());
    if (reinterpret_cast<::FUN_0057b0a0_shell *>((void *)this)->FUN_0057b0a0() == DAT_010241b0)
        return reinterpret_cast<NiPoint3*>(
            reinterpret_cast<TESTopicInfo*>(const_cast<MobileObject*>(this))->GetAddTopicList());
    ++DAT_011df880;
    if (DAT_011df880 >= 5)
        DAT_011df880 = 0;
    DAT_011df7a0[DAT_011df880] = *reinterpret_cast<NiPoint3*>(
        reinterpret_cast<TESTopicInfo*>(const_cast<MobileObject*>(this))->GetAddTopicList());
    TESObjectCELL* cell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((const_cast<MobileObject*>(this)))->GetTarget()));
    if (cell && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(reinterpret_cast<MobileObjectCellAccess*>(cell)))->FUN_004518e0())
    {
        MobileObjectWaterPositionHeight heights;
        heights.waterHeight = reinterpret_cast<::FUN_0057b0a0_shell *>((void *)this)->FUN_0057b0a0() - DAT_01020998;
        heights.heightOffset = reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)this)->GetActorHeight() * DAT_0101de30;
        if (heights.waterHeight > DAT_011df7a0[DAT_011df880].z + heights.heightOffset)
            DAT_011df7a0[DAT_011df880].z += heights.heightOffset;
        else
            DAT_011df7a0[DAT_011df880].z = heights.waterHeight;
    }
    return &DAT_011df7a0[DAT_011df880];
}
// The original linker folded the position-address accessor with this getter.
// Use the decorated name already bound by canonical source.
// @fnv 0x00436aa0
BSSimpleList<TESTopic*>* TESTopicInfo::GetAddTopicList()
{
    return &m_kAddTopicList;
}
#endif  // FNV_MOBILEOBJECT_H_UNIT
#endif
