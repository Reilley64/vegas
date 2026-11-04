
#include "fnv/decl/FUN_00403ee0_shell.h"
class EffectItem
{
  public:
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;

    int GetAffectedActorValue();
};

int EffectItem::GetAffectedActorValue()
{
    return reinterpret_cast<::FUN_00403ee0_shell *>(this)->FUN_00403ee0() ? m_eAssociatedActorValue : -1;
}
