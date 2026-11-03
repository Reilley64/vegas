// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPSYSEMITTERCTLR_H
#define FNV_NIPSYSEMITTERCTLR_H

#include "fnv/decl/FUN_00a57630.h"
#include "fnv/decl/S_00a53280_Foo.h"
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
#include "NiObjectNET.h"
#include "layout_support.h"
class NiInterpController;
class NiInterpolator;
class NiFloatData;
class CloningProcess;
class NiStream;
class NiPSysEmitterCtlr;
class NiPSysModifier;
class NiPSysModifierCtlr;
class NiSingleInterpController;
class NiTPrimitiveSet_float_;
class NiTSet_float_NiTMallocInterface_float___;
class NiTimeController : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned short m_uiObjectFlags;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    float m_fFrequency;                              // +0xC, 4 bytes
    float m_fPhase;                                  // +0x10, 4 bytes
    float m_fLoKeyTime;                              // +0x14, 4 bytes
    float m_fHiKeyTime;                              // +0x18, 4 bytes
    float m_fStartTime;                              // +0x1C, 4 bytes
    float m_fLastTime;                               // +0x20, 4 bytes
    float m_fWeightAdjustedLastTime;                 // +0x24, 4 bytes
    float m_fControllerTime;                         // +0x28, 4 bytes
    NiObjectNET* m_pkTarget;                         // +0x2C, 4 bytes
    NiPointer<NiTimeController> m_spNextController;  // +0x30, 4 bytes
    // const NiRTTI* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*, CloningProcess&)
    // void __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiObject*)
    // void __cdecl NiTimeController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiTimeController::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiTimeController::*(unsigned short, unsigned short)
    // void __cdecl NiTimeController::*(bool, unsigned short)
    // bool __cdecl NiTimeController::*(unsigned short)
    // NiTimeController
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::AnimType)
    // NiTimeController::AnimType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::CycleType)
    // NiTimeController::CycleType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // NiObjectNET* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiObjectNET*)
    // unsigned int __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // NiTimeController* __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // bool __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(CloningProcess&)
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // NiTimeController& __cdecl NiTimeController::*(const NiTimeController&)
    // void __cdecl NiTimeController::*()
};
class NiInterpController : public NiTimeController
{
  public:
    // base NiTimeController at +0x0, size 52
    // const NiRTTI* __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(NiInterpController*, CloningProcess&)
    // void __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiObject*)
    // void __cdecl NiInterpController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiInterpController::*(NiUpdateData&)
    // bool __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(bool)
    // NiInterpController
    // void __cdecl NiInterpController::*()
    // NiInterpController& __cdecl NiInterpController::*(const NiInterpController&)
    // void __cdecl NiInterpController::*()
public:
    static const unsigned short INVALID_INDEX;
};
class NiSingleInterpController : public NiInterpController
{
  public:
    // base NiInterpController at +0x0, size 52
    NiPointer<NiInterpolator> m_spControllerInterpolator;  // +0x34, 4 bytes
    // const NiRTTI* __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(NiSingleInterpController*, CloningProcess&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiObject*)
    // void __cdecl NiSingleInterpController::*(NiTPrimitiveArray<char *>*)
    // unsigned short __cdecl NiSingleInterpController::*()
    // const char* __cdecl NiSingleInterpController::*(unsigned short)
    // unsigned short __cdecl NiSingleInterpController::*(const char*)
    // unsigned short __cdecl NiSingleInterpController::*(const NiFixedString&)
    // NiInterpolator* __cdecl NiSingleInterpController::*(unsigned short)
    // void __cdecl NiSingleInterpController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(float, float)
    // void __cdecl NiSingleInterpController::*(CloningProcess&)
    // NiSingleInterpController
    // bool __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*()
    // NiSingleInterpController& __cdecl NiSingleInterpController::*(const NiSingleInterpController&)
    // void __cdecl NiSingleInterpController::*()
};
class NiPSysModifierCtlr : public NiSingleInterpController
{
  public:
    // base NiSingleInterpController at +0x0, size 56
    NiFixedString m_kTargetModifierName;  // +0x38, 4 bytes
    NiPSysModifier* m_pkTargetModifier;   // +0x3C, 4 bytes
    void LoadBinary(NiStream& stream);
    void ProcessClone(CloningProcess& process);
    void CopyMemberData(NiPSysModifierCtlr* destination, CloningProcess& process);
    // const NiRTTI* __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(NiPSysModifierCtlr*, CloningProcess&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // bool __cdecl NiPSysModifierCtlr::*(NiStream&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // bool __cdecl NiPSysModifierCtlr::*(NiObject*)
    // void __cdecl NiPSysModifierCtlr::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(NiObjectNET*)
    // const NiFixedString& __cdecl NiPSysModifierCtlr::*()
    // NiPSysModifier* __cdecl NiPSysModifierCtlr::*()
    // const char* __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(CloningProcess&)
    // void __cdecl NiPSysModifierCtlr::*(NiStream&)
    // NiPSysModifierCtlr
    // bool __cdecl NiPSysModifierCtlr::*(NiObjectNET*)
    // void __cdecl NiPSysModifierCtlr::*()
    // void __cdecl NiPSysModifierCtlr::*(const NiFixedString&)
    // NiPSysModifierCtlr& __cdecl NiPSysModifierCtlr::*(const NiPSysModifierCtlr&)
    // void __cdecl NiPSysModifierCtlr::*()
};
class NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
  public:
    NiPSysModifierBoolCtlr() throw();
};

class NiInterpolator : public NiObject
{
  public:
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3C();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual NiObject* Clone(CloningProcess& process);
    virtual void vfn_4C();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5C();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void ProcessClone(CloningProcess& process);
};

class NiFloatInterpolator : public NiInterpolator
{
  public:
    NiFloatInterpolator(NiFloatData* data) throw();
    void SetAnimationKeys(void* keys, unsigned int count, unsigned int keyType);
};

class NiBoolInterpolator : public NiInterpolator
{
  public:
    NiBoolInterpolator(void* data) throw();
};

class NiBoolInterpController : public NiInterpolator
{
  public:
};

class NiTSet_float_NiTMallocInterface_float___
{
  public:
    float* m_pBase;                      // +0x0, 4 bytes
    unsigned int m_uiElementCount;       // +0x4, 4 bytes
    unsigned int m_uiAllocatedCapacity;  // +0x8, 4 bytes
    // NiTSet<float,NiTMallocInterface<float> >
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // unsigned int __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // float* __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // GetAt
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
    // bool __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // bool __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int, const float&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // Realloc
    // int __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const float&)
    // NiTSet<float,NiTMallocInterface<float> >& __cdecl NiTSet<float,NiTMallocInterface<float> >::*(const NiTSet<float,NiTMallocInterface<float> >&)
    // void __cdecl NiTSet<float,NiTMallocInterface<float> >::*()
    // void* __cdecl NiTSet<float,NiTMallocInterface<float> >::*(unsigned int)
};
class NiTPrimitiveSet_float_ : public NiTSet_float_NiTMallocInterface_float___
{
  public:
    // base NiTSet<float,NiTMallocInterface<float> > at +0x0, size 12
    // NiTPrimitiveSet<float>
    // void __cdecl NiTPrimitiveSet<float>::*()
    // NiTPrimitiveSet<float>& __cdecl NiTPrimitiveSet<float>::*(const NiTPrimitiveSet<float>&)
    // void __cdecl NiTPrimitiveSet<float>::*()
    // void* __cdecl NiTPrimitiveSet<float>::*(unsigned int)
};
class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
  public:
    static void* operator new(unsigned int size);
    // base NiPSysModifierCtlr at +0x0, size 64
    NiPointer<NiInterpolator> m_spVisibilityInterpolator;  // +0x40, 4 bytes
    NiInterpolator* m_pEmitterActiveInterpolator;          // +0x44, 4 bytes
    float m_fScaledLastTime;                               // +0x48, 4 bytes
    bool m_bIsInitialized;                                 // +0x4C, 1 bytes
    unsigned char layoutPadding4D[3];
    NiTPrimitiveSet_float_ m_kBirthRateKeys;  // +0x50, 12 bytes
    void LoadBinary(NiStream& stream);
    void LinkObject(NiStream& stream);
    void ProcessClone(CloningProcess& process);
    void CopyMemberData(NiPSysEmitterCtlr* destination, CloningProcess& process);
    NiObject* MakeClone(CloningProcess& process);
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3C();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4C();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5C();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6C();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7C();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8C();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9C();
    virtual void vfn_A0();
    virtual void vfn_A4();
    virtual void vfn_A8();
    virtual void vfn_AC();
    virtual void vfn_B0();
    virtual void vfn_B4();
    virtual void vfn_B8();
    virtual void vfn_BC();
    virtual void vfn_C0();
    virtual void vfn_C4();
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned int index);
    // const NiRTTI* __cdecl NiPSysEmitterCtlr::*()
    // NiObject* __cdecl NiPSysEmitterCtlr::*(CloningProcess&)
    // void __cdecl NiPSysEmitterCtlr::*(NiPSysEmitterCtlr*, CloningProcess&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // bool __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // void __cdecl NiPSysEmitterCtlr::*(NiStream&)
    // bool __cdecl NiPSysEmitterCtlr::*(NiObject*)
    // NiObject* __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiTPrimitiveArray<char *>*)
    // NiPSysEmitterCtlr
    // void __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiUpdateData&)
    // NiFloatInterpolator* __cdecl NiPSysEmitterCtlr::*()
    // NiBoolInterpolator* __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(NiFloatInterpolator*)
    // void __cdecl NiPSysEmitterCtlr::*(NiBoolInterpolator*)
    // void __cdecl NiPSysEmitterCtlr::*(float, float)
    // void __cdecl NiPSysEmitterCtlr::*()
    // unsigned short __cdecl NiPSysEmitterCtlr::*()
    // const char* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // unsigned short __cdecl NiPSysEmitterCtlr::*(const char*)
    // NiInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // void __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // NiInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // void __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiPSysEmitterCtlr::*(unsigned short, bool, bool, float, unsigned char)
    // void __cdecl NiPSysEmitterCtlr::*(CloningProcess&)
    // unsigned short __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(unsigned short)
    // bool __cdecl NiPSysEmitterCtlr::*(NiInterpolator*, unsigned short)
    // bool __cdecl NiPSysEmitterCtlr::*(NiObjectNET*)
    // bool __cdecl NiPSysEmitterCtlr::*()
    // void __cdecl NiPSysEmitterCtlr::*(float, float, float, float, float, float)
    // void __cdecl NiPSysEmitterCtlr::*()
    // NiPSysEmitterCtlr& __cdecl NiPSysEmitterCtlr::*(const NiPSysEmitterCtlr&)
    // void __cdecl NiPSysEmitterCtlr::*()
};
#endif
