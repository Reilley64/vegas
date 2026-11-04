
// NiRTTI: the Gamebryo runtime type descriptor.
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/NiCollisionObject.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_01267000.h"
#include "layout_support.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_0104d000.h"

class NiRTTI
{
  public:
    NiRTTI(const char* pcName, const NiRTTI* pkBaseRTTI);

    const char* GetName() const;
    const NiRTTI* GetBaseRTTI() const;

  protected:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};


// @fnv 0x00a7b610
NiRTTI::NiRTTI(const char* pcName, const NiRTTI* pkBaseRTTI)
{
    m_pcName = pcName;
    m_pBaseRTTI = pkBaseRTTI;
}

extern int DAT_010c4314;

// Calls Construct on pThis, installs the DAT_010c4314 vtable, zeroes field at offset 16, increments DAT_01267b60 and sets a ushort at offset 12 to 0x41.
// @fnv 0x00c6b910
void* FUN_00c6b910(void* apObject)
{
    reinterpret_cast<::NiCollisionObject *>((apObject))->Construct();
    *(int**)apObject = &DAT_010c4314;
    *((int*)apObject + 4) = 0;
    ++DAT_01267b60;
    *((unsigned short*)apObject + 6) = 0x41;
    return apObject;
}


struct RTTIEntry
{
    const void* name;
    const void* base;
    void FUN_0061bcf0();
};
// @fnv 0x0061bcf0
void RTTIEntry::FUN_0061bcf0()
{
    name = DAT_0104d448;
    ::FUN_004ede70((void *)(base));
}
#include "generated/data/gamebryo2.2/corelibs/nimain/nirtti.inc"
