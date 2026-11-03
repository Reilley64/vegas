// fallout_shared/package_decls.h: declares TESObjectREFR, MobileObject, PackageTargetRecord, DurationData, TESPackage and more

#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/fnv_0067fd40__FUN_0067fd40_shell.h"
class TESPatrolPackageData;
class ExtraRadioData;
class TESObjectREFR
{
  public:
public:
    ::ExtraRadioData *GetExtraRadioData();
public:
    float GetBoundingRadius();
};
class MobileObject : public TESObjectREFR
{
public:
    void ProcessAnimation();
};
class TESForm;
enum PACKAGE_OBJECT_TYPE;
enum PACK_TARG_TYPE;
class PackageTargetRecord
{
  public:
    int GetTargetKind();
    TESObjectREFR* GetReferenceTarget();
    float FUN_0084d030();
public:
    ::TESForm *GetTargetForm();
public:
    ::PACKAGE_OBJECT_TYPE GetTargetObjectType();
public:
    void SetTargetKind(::PACK_TARG_TYPE);
public:
    void InitItem(::TESForm *);
};
class DurationData
{
  public:
    unsigned int time, duration;
    DurationData();
    ~DurationData();
    void Copy(DurationData*);
public:
    int FUN_00678ca0();
};
enum PTYPE
{
    PT_DUMMY
};
class TESPackage
{
  public:
    char base[24];
    unsigned int flags18, flags;
    unsigned char type;
    char pad21;
    unsigned short f22, f24;
    char pad26[2];
    TESPatrolPackageData* data;
    unsigned int f2c, f30, f34;
    DurationData schedule;
    char pad40[8];
    unsigned int f48;
    static float GetPackageDefaultFloat();
    bool IsMustReachLocation();
    bool UsesPackageAnimation();
    bool IsFlag10000Set();
    PTYPE GetPackType();
    const TESPatrolPackageData* GetPackagePatrolData();
    bool IsPackageBlockingGreeting();
    PackageTargetRecord* GetTarget();
    TESObjectREFR* GetResolvedTargetReference(MobileObject*);
    void CopyScheduleFrom(DurationData*);
    void ResetFormData();
    bool GetPackageSearchRadius(MobileObject*, float&);
    bool FUN_00673890();
    bool FUN_00674d20();
    bool FUN_00670ed0();
    bool IsFlag10Set();
    bool IsFlag80Set();
    bool FUN_00670f40();
    bool FUN_00670f60();
    bool IsMustComplete();
public:
    bool GetForceUnequipWeapon() const;
};
class ImageSpaceModifierInstanceDOF
{
  public:
    char pad[24];
    unsigned int flags;
    void FUN_005bbd60(bool);
};
extern float gPackageLocationRadius;
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
