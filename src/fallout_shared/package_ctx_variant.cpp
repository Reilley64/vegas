
// package_ctx_variant.cpp: context variant of src/fallout_shared/package.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSIdleCollection.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00672dd0_shell.h"
#include "fnv/decl/FUN_00672fc0_shell.h"
#include "fnv/decl/FUN_00674d70_shell.h"
#include "fnv/decl/FUN_0067f140_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/PackageEventActionData.h"
#include "fnv/decl/PackedByteIntRecord.h"
#include "fnv/decl/PerkEntryConditionSet.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/fnv_00671d30__FUN_00671d30_shell.h"
#include "fnv/decl/fnv_0067fd40__FUN_0067fd40_shell.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "package_decls.h"

class PackageInit;
class FUN_00670b30
{
  public:
    ~FUN_00670b30();
};
class FUN_0067f030 : public FUN_00670b30
{
  public:
    unsigned int type, value;
    float radius;
    FUN_0067f030();
    ~FUN_0067f030();
};
class FUN_0067ff70
{
  public:
    unsigned int type, target, count, unknown;
    FUN_0067ff70();
    ~FUN_0067ff70();
};
struct ConditionInit
{
};
struct IdleInit
{
};
struct ProcedureInit
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct PackageDataInit
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Init(PackageInit*);
    unsigned char unk04, flag05;
};
class TESFile;
class TESForm
{
  public:
    virtual void unused();
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
public:
    ::TESFile *GetFile(int);
};
class TESCombatStyle : public TESForm
{
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern int DAT_0118627c;
class PackageInit
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetDebugName();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int flags18, packageFlags;
    unsigned char type, unk21;
    unsigned short unk22;
    unsigned int unk24;
    PackageDataInit* data;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    ProcedureInit begin, end, change;
    unsigned int FUN_006733e0();
    void FUN_00674930();
};
// @fnv 0x00674930
void PackageInit::FUN_00674930()
{
    if (reinterpret_cast<::TESForm *>(this)->GetInitialized())
        return;
    int warningsA = FUN_0046e8a0();
    if (((struct ::FUN_0067f030 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
        reinterpret_cast<::LocationDescriptor *>((((struct ::FUN_0067f030 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((struct ::FUN_0067f030 *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0())))
        reinterpret_cast<::LocationDescriptor *>((((struct ::FUN_0067f030 *)(reinterpret_cast<::FUN_00672dd0_shell *>(this)->FUN_00672dd0()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData())))
        reinterpret_cast<::PackageTargetRecord *>((((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((::ConditionInit *)(reinterpret_cast<::PackedByteIntRecord *>(this)->Endian())))
        reinterpret_cast<::PerkEntryConditionSet *>((((::ConditionInit *)(reinterpret_cast<::PackedByteIntRecord *>(this)->Endian()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (((::IdleInit *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())))
        reinterpret_cast<::BGSIdleCollection *>((((::IdleInit *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (data)
        data->Init(this);
    unsigned int kCombatStyle = FUN_006733e0();
    if (kCombatStyle)
    {
        ::ResolveFormID(&kCombatStyle, (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>(this)->GetFile(-1)))));
        reinterpret_cast<::ValueModifierEffect *>(this)->SetActorValue((::ActorValue::Index)(dynamic_cast<TESCombatStyle*>(FUN_004839c0(kCombatStyle))));
        if (!FUN_006733e0())
            ::FUN_005b5e40();
    }
    reinterpret_cast<::FUN_0041fd00_shell *>(&(begin))->FUN_0041fd00(0);
    reinterpret_cast<::FUN_0041fd00_shell *>(&(end))->FUN_0041fd00(1);
    reinterpret_cast<::FUN_0041fd00_shell *>(&(change))->FUN_0041fd00(2);
    reinterpret_cast<::PackageEventActionData *>(&(begin))->InitItem((::TESForm *)(::PackageInit *)(this));
    reinterpret_cast<::PackageEventActionData *>(&(end))->InitItem((::TESForm *)(::PackageInit *)(this));
    reinterpret_cast<::PackageEventActionData *>(&(change))->InitItem((::TESForm *)(::PackageInit *)(this));
    if (warningsA != FUN_0046e8a0())
    {
        ::FUN_005b5e40(
            );
        packageFlags |= 0x8000;
    }
    switch (reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get())
    {
    case 9:
        if (reinterpret_cast<::TESPackage *>(this)->FUN_00674d20())
            reinterpret_cast<::FUN_0067f140_shell *>((((struct ::FUN_0067f030 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->FUN_0067f140(6);
        break;
    case 14:
        if (reinterpret_cast<::TESPackage *>(this)->FUN_00674d20())
        {
            if (!((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData())))
                reinterpret_cast<::FUN_00672fc0_shell *>(this)->FUN_00672fc0((::PackageTargetRecord *)(class ::FUN_0067ff70 *)(new FUN_0067ff70));
            reinterpret_cast<::PackageTargetRecord *>((((class ::FUN_0067ff70 *)(reinterpret_cast<::Script *>(this)->GetData()))))->SetTargetKind((::PACK_TARG_TYPE)(3));
        }
        break;
    case 13: {
        PackageDataInit* packageData_2 = data;
        if (packageData_2->flag05)
            reinterpret_cast<::FUN_0067f140_shell *>((((struct ::FUN_0067f030 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->FUN_0067f140(6);
        if (!((struct ::FUN_0067f030 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())))
        {
            FUN_0067f030* location = new FUN_0067f030;
            reinterpret_cast<::FUN_0067f140_shell *>((location))->FUN_0067f140(6);
            reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>(this)->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(location));
            delete static_cast<FUN_00670b30*>(location);
        }
        break;
    }
    case 12:
        if (reinterpret_cast<::TESPackage *>(this)->FUN_00673890())
            reinterpret_cast<::FUN_0067f140_shell *>((((struct ::FUN_0067f030 *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))))->FUN_0067f140(6);
        break;
    }
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
}
