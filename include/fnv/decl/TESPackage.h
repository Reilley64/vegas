#pragma once

class DurationData;
class MobileObject;
class Script;
class TESObjectREFR;
class TESPatrolPackageData;
enum PACKAGE_PROCEDURE_TYPE;

class TESPackage {
public:
    // 0x00407840
    unsigned int GetRefCount();
    // 0x00441b00
    bool GetForceUnequipWeapon() const;
    // 0x005394a0
    bool FUN_005394a0();
    // 0x00670ed0
    bool FUN_00670ed0();
    // 0x00670ef0
    bool IsFlag10Set();
    // 0x00670f10
    bool IsFlag80Set();
    // 0x00670f40
    bool FUN_00670f40();
    // 0x00670f60
    bool FUN_00670f60();
    // 0x00670f90
    bool IsMustReachLocation();
    // 0x006728a0
    bool GetPackageSearchRadius(::MobileObject *, float &);
    // 0x00672aa0
    void FUN_00672aa0(char);
    // 0x00672b70
    void SetPackageFlag(bool);
    // 0x00673180
    void CopyScheduleFrom(::DurationData *);
    // 0x00673890
    bool FUN_00673890();
    // 0x00674d20
    bool FUN_00674d20();
    // 0x00674d40
    bool IsMustComplete();
    // 0x00674e40
    bool IsFlag10000Set();
    // 0x00675920
    const ::TESPatrolPackageData *GetPackagePatrolData();
    // 0x006759e0
    ::TESObjectREFR *GetResolvedTargetReference(::MobileObject *);
    // 0x00678610
    bool IsPackageBlockingGreeting();
    // 0x006e25d0
    static float GetPackageDefaultFloat();
    // 0x00826b40
    void SetMustReachLocation(bool);
    // 0x00826b90
    void SetMustComplete(bool);
    // 0x00903cf0
    ::Script *GetNextScript();
    // 0x00984f60
    void SetProcedureType(::PACKAGE_PROCEDURE_TYPE);
};
