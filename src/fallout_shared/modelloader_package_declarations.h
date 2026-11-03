// REVIEW-ONLY declaration closure. Requires selector_same_tu_types.h in existing modelloader.cpp.
// Complete xNVSE runtime data fields; public JG runtime virtual declarations.
#ifndef MODELLOADER_PACKAGE_GETTER_DECLARATIONS_H
#define MODELLOADER_PACKAGE_GETTER_DECLARATIONS_H

class Actor;
class TESPackageData;
class TESIdleForm;
class TESTopic;

class TESPackage : public TESForm
{
  public:
    virtual bool IsPackageValidForActor(Actor* apActor);
    virtual bool IsActorWithinPackageRadius(Actor* apActor, bool abIgnoreDistance, float afExtraRadius,
                                            bool abInFurniture);
    virtual bool IsActorNearOwnerPackageLocation(Actor* apMobileObject, Actor* apPackageowner, bool abIgnoreDistance,
                                                 float afExtraRadius, bool abInFurniture);
    virtual bool IsActorInPackageRadius(Actor* apActor, int aiExtraRadius);
    virtual bool IsActorNearPackageTarget(Actor* apActor, int aiExtraRadius);
    virtual unsigned short GetSaveSize();
    virtual unsigned short SaveGameTESAlt();
    virtual unsigned short LoadGameTESAlt();
    virtual void InitLoadGameTES();
    virtual bool IsPackageDoneForActor(Actor* apActor = 0);

    enum
    {
        kPackageFlag_WeaponsUnequipped = 1 << 21
    };
    struct PackageTime
    {
        unsigned char month;
        unsigned char weekDay;
        unsigned char date;
        unsigned char time;
        unsigned long duration;
    };
    union ObjectType
    {
        TESForm* form;
        TESObjectREFR* refr;
        unsigned long objectCode;
    };
    struct LocationData
    {
        unsigned char locationType;
        unsigned char pad[3];
        unsigned long radius;
        ObjectType object;
    };
    struct TargetData
    {
        unsigned char targetType;
        unsigned char pad[3];
        ObjectType target;
        unsigned long count;
        float unk0C;
    };
    struct PackageAction
    {
        TESIdleForm* idle;
        Script* script;
        TESTopic* topic;
        unsigned long type;
    };
    unsigned long procedureArrayIndex;
    unsigned long packageFlags;
    unsigned char type;
    unsigned char pad021[1];
    unsigned short behaviorFlags;
    unsigned long specificFlags;
    TESPackageData* packageData;
    LocationData* location;
    TargetData* target;
    unsigned long unk034;
    PackageTime time;
    unsigned long unk040;
    unsigned long unk044;
    unsigned long unk048;
    PackageAction onBeginAction;
    PackageAction onEndAction;
    PackageAction onChangeAction;
    unsigned long unk07C;
    bool GetForceUnequipWeapon() const;
};

#endif
