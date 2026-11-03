// gamebryo2.2/corelibs/niparticle/nipsysmodifierfloatctlr_decls.h: declares NiMemObject, NiObject, NiStream, NiFloatInterpolator, NiPSysModifierCtlr and more
#ifndef NIPSYSMODIFIERFLOATCTLR_DECLS_H
#define NIPSYSMODIFIERFLOATCTLR_DECLS_H

#include "fnv/decl/FUN_00a57630.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};
class NiRTTI;
class NiObject
{
  public:
    virtual void vfn_0();
    virtual void DeleteThis();
    long refs;
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
class NiFloatData;
class NiStream
{
  public:
    unsigned char pad[0xd8];
    unsigned int version;
    NiObject* GetLoadedObject();
};
class NiFloatInterpolator : public NiObject, public NiMemObject
{
  public:
    unsigned char pad[16];
    NiFloatInterpolator(NiFloatData*) throw();
};
class NiPSysModifierCtlr
{
  public:
    unsigned char pad[0x34];
    NiObject* interpolator;
};
class NiPSysModifierFloatCtlr : public NiPSysModifierCtlr
{
  public:
    void LinkObject(NiStream&);
};
#endif
