#pragma once

#include <new>
#include "fnv/decl/FUN_0056d300_S.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0056d000.h"
#include "bhkconvert_decls.h"
#pragma strict_gs_check(on)
// @fnv 0x0056df80
hkTransform& FromHK(hkTransform& out, const NiTransform& in)
{
    ::VisitAndFetchThree((::FetcherC *)(new ((void *)&out) ::Vec3()),
                       (::VisitorB *)&(in.rotation));
    hkVector4 position;
    new ((void *)(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&position))) ::Vec3();
    reinterpret_cast<::FUN_0056d300_S *>(&(out))->FUN_0056d300((const void *)&((*(::hkVector4 *)&(::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(position), (const ::fnv_004a3e00::NiPoint3 &)(in.position))))));
    return out;
}

#pragma strict_gs_check(on)
// @fnv 0x00458620
NiPoint3& SetNiPoint3FromHkVector4(NiPoint3& out, const hkVector4& in)
{
    VectorComponentValue x, y, z;
    out.x = FUN_004587d0(reinterpret_cast<::S004586d0_Obj *>((void *)&((*(::VectorComponentValue *)(reinterpret_cast<::Holder *>((void *)&(in))->FUN_00458700((::Holder *)&(x), 0)))))->FUN_004586d0());
    out.y = FUN_004587d0(reinterpret_cast<::S004586d0_Obj *>((void *)&((*(::VectorComponentValue *)(reinterpret_cast<::Holder *>((void *)&(in))->FUN_00458700((::Holder *)&(y), 1)))))->FUN_004586d0());
    out.z = FUN_004587d0(reinterpret_cast<::S004586d0_Obj *>((void *)&((*(::VectorComponentValue *)(reinterpret_cast<::Holder *>((void *)&(in))->FUN_00458700((::Holder *)&(z), 2)))))->FUN_004586d0());
    return out;
}
