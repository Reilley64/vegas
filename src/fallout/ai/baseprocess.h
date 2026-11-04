#include "fnv/decl/FUN_0049bb50_shell.h"
#include "baseprocess_packet.h"

static const int kCalculateMoveModeValue1 = 257;

#ifdef FNV_BASEPROCESS_H_UNIT
// @fnv 0x008d0540
int BaseProcess::GetAttackChance(Actor* argument0, float argument1, float argument2, float argument3, bool argument4,
                                 bool argument5)
{
    return kCalculateMoveModeValue1;
}

// @fnv 0x008d03a0
void BaseProcess::StopPackage()
{
    m_kProcessData.Clear();
}

// @fnv 0x00859670
TESPackage* BaseProcess::GetOneTimePackage()
{
    return GetStablePackage();
}

// @fnv 0x008d0450
int BaseProcess::GetPackageInfoValue()
{
    return Unk_8F();
}

// @fnv 0x008d0400
void BaseProcess::SetPackageExecutionState(int amount)
{
    reinterpret_cast<::FUN_0049bb50_shell *>(&(m_kProcessData))->AddToOffset(amount);
}

// @fnv 0x008d0470
void BaseProcess::SetAnimationState(int index)
{
    Unk_8E(index);
}
#endif  // FNV_BASEPROCESS_H_UNIT
