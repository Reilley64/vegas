// fallout_shared/package_decls.h: declares TESObjectREFR, MobileObject, PackageTargetRecord, DurationData, TESPackage and more

#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/fnv_0067fd40__FUN_0067fd40_shell.h"
class TESPatrolPackageData;
struct ExtraRadioData;
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
    void SetTargetObjectReference(::TESObjectREFR *);
};
class DurationData
{
  public:
    union
    {
        unsigned int time;
        struct
        {
            signed char cMonth, cDayOfWeek, cDate, cHour;
        };
    };
    unsigned int duration;
    DurationData();
    ~DurationData();
    void Copy(DurationData*);
public:
    int FUN_00678ca0();
};
class TESCombatStyle;
enum PACKAGE_PROCEDURE_TYPE;
enum PTYPE
{
    PT_DUMMY
};
class TESPackage
{
  public:
    virtual ~TESPackage();

    char base[20];
    unsigned int flags18, flags;
    unsigned char type;
    char pad21;
    unsigned short f22, f24;
    char pad26[2];
    TESPatrolPackageData* data;
    struct LocationDescriptor* pPackageLocation;
    PackageTargetRecord* pPackageTarget;
    unsigned int f34;
    DurationData schedule;
    char pad40[8];
    TESCombatStyle* pCombatStyle;
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
    void SetMustReachLocation(bool);
    void SetMustComplete(bool);
    void SetProcedureType(::PACKAGE_PROCEDURE_TYPE);
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
