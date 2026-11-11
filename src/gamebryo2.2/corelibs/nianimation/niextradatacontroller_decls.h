// gamebryo2.2/corelibs/nianimation/niextradatacontroller_decls.h: declares NiFixedString, NiStream, NiSingleInterpController, NiPSysModifierCtlr
#ifndef NIEXTRADATACONTROLLER_DECLS_H
#define NIEXTRADATACONTROLLER_DECLS_H

#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/native_fixed_string.h"
struct NiStream
{
  public:
    char padding[0xd8];
    unsigned int version;
};
struct CloningProcess;
class NiSingleInterpController
{
  public:
    virtual void Reserved();
    char padding[0x34];
    void LoadBinary(NiStream&);
public:
    void ProcessClone(::CloningProcess &);
};
class NiPSysModifierCtlr : public NiSingleInterpController
{
  public:
    NiFixedString m_kTargetModifierName;
    void* m_pkTargetModifier;
    virtual void LoadBinary(NiStream&);
};
#endif
