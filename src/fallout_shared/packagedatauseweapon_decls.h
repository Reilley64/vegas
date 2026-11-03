// fallout_shared/packagedatauseweapon_decls.h: declares TESObjectWEAP, TESObjectREFR, ExtraDataList, LocationDescriptor, PackageTargetRecord and more
#ifndef FNV_PACKAGEDATAUSEWEAPON_DECLS_H
#define FNV_PACKAGEDATAUSEWEAPON_DECLS_H


#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/DurationData.h"
#include "fnv/decl/FUN_00421b40_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_011ca000.h"
#include "TESForm.h"

class BSFileEntry;
class TESBoundObject;
class ExtraDataList;
class TESObjectWEAP : public TESForm
{
};

// API declarations only: these objects are neither allocated nor inspected here.
class TESObjectREFR
{
  public:
};

class ExtraDataList
{
  public:
};

class LocationDescriptor
{
  public:
    TESObjectREFR* GetLocationReference();
public:
    void Copy(::LocationDescriptor *, bool);
};

enum PACK_TARG_TYPE
{
    PACK_TARG_REFERENCE = 0
};

class PackageTargetRecord
{
  public:
    unsigned char m_uiTargetType;
    unsigned char layoutPadding1[3];
    union
    {
        TESObjectREFR* m_pWorldReferenceInfo;
        TESForm* pObject;
        TESForm* pTargetForm;
    };
    int iValue;
    float m_fTargetValue;

    PackageTargetRecord();
    void SetTargetKind(PACK_TARG_TYPE type);
    void SetTargetObjectReference(TESObjectREFR* reference);
    void InitItem(TESForm* item);
};

class TESPackageData
{
  public:
    void** m_ppVirtualMethodTable;
};

class TESUseWeaponPackageData : public TESPackageData
{
  public:
    PackageTargetRecord* m_pUseTarget;
    LocationDescriptor* m_pTargetLocation;
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    TESObjectWEAP* pWeapon;

    void InitItem(TESForm* item);
};

class ActorPackageData
{
  public:
    void** m_ppVirtualMethodTable;
};

class UseWeaponActorPackageData : public ActorPackageData
{
  public:
    TESObjectREFR* m_pUseTarget;
    void SetReferenceTarget(TESObjectREFR* reference);
};




#endif
