// fallout/ai/followerbarks.cpp: BarkPlaybackEntry (2 functions)

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FNVWipScreenManager.h"
#include "fnv/decl/FUN_008d6000_Class.h"
#include "fnv/decl/HealthCond5e30.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_011e0000.h"
#include "followerbarks_decls.h"
// @fnv 0x008d5bc0
void BarkPlaybackEntry::UpdateBarks()
{
    BSSimpleList<BGSPerkEntry*>* now;
    unsigned int bark = ((unsigned int)(::FUN_00457fe0()));
    bool remove;
    BarkPlaybackEntry* node;
    now = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&g_011e0098);
    while (now)
    {
        node = reinterpret_cast<BarkPlaybackEntry*>(((::BGSPerkEntry *)(new ((void *)(now)) ::Vec3())));
        remove = false;
        if (node && node->actor && node->startTime <= bark)
        {
            if (reinterpret_cast<::HealthCond5e30 *>((node))->IsHealthConditionMet() && reinterpret_cast<::MiddleHighProcess *>((node->actor))->IsActorInCombat())
            {
                reinterpret_cast<::FUN_008d6000_Class *>((node))->InitTiming((unsigned int)(node->actor), (unsigned int)(node->topic));
                reinterpret_cast<::FNVWipScreenManager *>((node))->FUN_008d6050();
            }
            else
            {
                if (node->endTime <= bark)
                    remove = true;
                else if (!reinterpret_cast<::MiddleHighProcess *>((node->actor))->IsActorInCombat())
                    remove = true;
            }
        }
        if (remove)
        {
            delete node;
            reinterpret_cast<BSSimpleList<const char*>*>(now)->RemoveHead();
        }
        else
            now = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((now))->FUN_00726070()));
    }
}

class TESForm
{
  public:
    virtual ~TESForm();
public:
    static ::TESForm *LookupFormByEditorID(const char *);
};
class TESTopic : public TESForm
{
};

// Returns the TESTopic form mapped to kind, or null when no form is returned.
// @fnv 0x008d5910
TESTopic* __cdecl FUN_008d5910(unsigned int kind)
{
    switch (kind)
    {
    case 3:
        return 0;
        break;
    case 11:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("Wake"));
        break;
    case 0:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("KOed"));
        break;
    case 1:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("KnockedBack"));
        break;
    case 7:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("NoAmmo"));
        break;
    case 8:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("WeaponBroke"));
        break;
    case 5:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("HealthQuarter"));
        break;
    case 4:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("HealthHalf"));
        break;
    case 2:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("Crippled"));
        break;
    case 9:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("WeaponIneffective"));
        break;
    case 10:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("UsedDoctorBag"));
        break;
    case 6:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("Crippled"));
        break;
    case 12:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("FollowersStealthing"));
        break;
    case 13:
        return dynamic_cast<TESTopic*>(::TESForm::LookupFormByEditorID("Regenerating"));
    }
    return 0;
}
