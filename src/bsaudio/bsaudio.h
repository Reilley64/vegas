#include "fnv/decl/fnv_00951a10__ThisCls.h"
#include "fnv/symbols_0093a000.h"
#include "bsaudio_player_decls.h"
// @fnv 0x0093a5f0
void PlayerCharacter::SetUnderAIControl(bool enabled)
{
    underAIControl = enabled;
    if (::FUN_0093a740((::FUN_0093a740_s *)this))
        vfn_258(false);
    else
        vfn_258(true);
}
// @fnv 0x00950290
void PlayerCharacter::UpdateCameraMode()
{
    bool changed = thirdPerson != previousThirdPerson;
    if (!changed)
        return;
    if (DAT_011e07dc > DAT_0101db88)
        return;
    previousThirdPerson = thirdPerson;
    if (!DAT_011e07b8 && firstPersonNode.operator->() && !previousThirdPerson)
        reinterpret_cast<::fnv_00951a10::ThisCls *>(this)->FUN_00951a10(!previousThirdPerson);
}
