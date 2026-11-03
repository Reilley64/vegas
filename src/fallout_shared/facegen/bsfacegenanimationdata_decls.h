
#include "fnv/decl/FUN_00a6e1f0_shell.h"
#include "fnv/decl/KFShell.h"
#include "fnv/decl/Sd4e0.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01064000.h"
extern const double DAT_01064f58;
class NiQuaternion
{
  public:
    float q[4];
    bool operator!=(const NiQuaternion&) const;
    static const NiQuaternion IDENTITY;
};
class RotationValues
{
  public:
};
enum BS_FACEGEN_MORPH_TYPE
{
    PHONEME = 0,
    EXPRESSION = 1,
    MODIFIER = 2,
    CUSTOM = 3
};
template <class T> class NiTPointerList
{
  public:
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};
struct NiPoint3
{
    float x;
    float y;
    float z;
    bool FUN_004390c0(const ::NiPoint3&);
    static const ::NiPoint3 ZERO;
};
class RecursiveSpinLock
{
  public:
    volatile unsigned int ownerThread;
    volatile unsigned int lockCount;
    void FUN_0040fba0();
};
class BSFaceGenKeyframe
{
  public:
    virtual ~BSFaceGenKeyframe();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10(float);
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20(bool);
    virtual void vfn_24();
    virtual void vfn_28();
    virtual bool vfn_2c(BSFaceGenKeyframe*);
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    int type;
    float time;
    bool SetTime(float);
};
class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
  public:
    float* quantities;
    unsigned count;
    BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE, unsigned);
    virtual ~BSFaceGenKeyframeMultiple();
    bool FUN_0064a4d0(unsigned, float);
};

class BSFaceGenAnimationData
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4(float, bool, bool, bool, bool, bool);
    virtual void vfn_b8(float, bool, bool, bool, bool, bool);
    virtual void vfn_bc(float, bool, bool, bool, bool);
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8(BS_FACEGEN_MORPH_TYPE, float, bool);
    virtual void vfn_fc();
    virtual void vfn_100(bool, bool, bool, bool);
    virtual void vfn_104(bool, bool, bool, bool);
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    unsigned int refCount;
    const char* name;
    BSFaceGenKeyframeMultiple* target;
    BSFaceGenKeyframeMultiple expressionKeyframe;
    BSFaceGenKeyframeMultiple expressionBase;
    BSFaceGenKeyframeMultiple modifierBase;
    BSFaceGenKeyframeMultiple phonemeBase;
    BSFaceGenKeyframeMultiple customBase;
    BSFaceGenKeyframeMultiple expressionValues;
    NiTPointerList<BSFaceGenKeyframe*> modifierKeyframes;
    BSFaceGenKeyframeMultiple modifierKeyframe;
    BSFaceGenKeyframeMultiple modifierValues;
    NiTPointerList<BSFaceGenKeyframe*> phonemeKeyframes;
    BSFaceGenKeyframeMultiple phonemeKeyframe;
    BSFaceGenKeyframeMultiple phonemeValues;
    NiTPointerList<BSFaceGenKeyframe*> customKeyframes;
    BSFaceGenKeyframeMultiple customKeyframe;
    BSFaceGenKeyframeMultiple customValues;
    NiPoint3 unk124;
    float unk130;
    float unk134;
    float unk138;
    float unk13c;
    float eyeHeading;
    float eyePitch;
    int unk148;
    bool unk14c, unk14d, unk14e, unk14f;
    float unk150[9];
    int unk174;
    float unk178;
    float unk17c;
    int unk180;
    int unk184;
    bool unk188;
    bool changed, p18a, dirty, p18c, p18d, dead;
    bool unk18f;
    bool unk190;
    bool unk191, unk192, unk193;
    float unk194;
    int unk198;
    int unk19c;
    RecursiveSpinLock lock;
    char pad1a8[0x18];
    void AddModifierKeyframe(float*, float);
    void AddKeyframe(BS_FACEGEN_MORPH_TYPE, float, bool);
    void InsertPhonemeKeyframe(float*, float);
    void SetExpressionWeight(int, float);
    bool CalculateRotationQuaternion(NiQuaternion&);
    void FadeOutMorphs(float, bool, bool, bool, bool);
    void ClearTransitionTarget();
    void SetMorphFlags(bool, bool, bool, bool);
    void SetStateFlags(bool, bool);
};
