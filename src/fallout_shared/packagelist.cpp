// fallout_shared/packagelist.cpp: PackageList, TESAIForm (10 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ComparisonOwner.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_0041d8c0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00677760_shell.h"
#include "fnv/decl/FUN_00678cc0_shell.h"
#include "fnv/decl/FUN_00678ce0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/PackedByteIntRecord.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00422690__FUN_00422690_shell.h"
#include "fnv/decl/fnv_006777b0__FUN_006777b0_shell.h"
#include "fnv/decl/fnv_00678d40__FUN_00678d40_shell.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011de000.h"
#include "packagelist_decls.h"
template <class T> class BSSimpleList
{
  public:
    void RemoveAll();
    void AddHead(T&);
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void SetItem(T const& item);
    void Remove(T const& item);
    void RemoveHead();
    bool IsInList(T& item);
    void AddTail(T const& item);
    unsigned int ItemsInList();
};

class PackageList
{
  public:
    void Copy(const PackageList* src);
    void ClearPackageList();
    TESPackage* GetPackageForActor(Actor* actor);
    void CollectEligiblePackages(Actor*, BSSimpleList<TESPackage*>*, float, float);
    void InitItem(TESForm*);
    void AddPackage(TESPackage*);
};

class TESAIForm
{
  public:
    void CopyAIPackageList(const TESAIForm* src);
};

// @fnv 0x0067e400
void PackageList::ClearPackageList()
{
    reinterpret_cast<::FileMatchList *>((((::BSSimpleList< ::TESPackage *> *)(new ((void *)this) ::Vec3()))))->RemoveAll();
}

// Copies the package list from src into this form's package list.
// @fnv 0x0047f2d0
void TESAIForm::CopyAIPackageList(const TESAIForm* src)
{
    ((::PackageList *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()))->Copy(((const ::PackageList *)(reinterpret_cast<::BGSCameraPath *>((void *)(src))->GetConditions())));
}

// Scans the package list for a package whose conditions and schedule match the actor, logs the pick, updates extra data and process state, and returns it.
// @fnv 0x0067e780
TESPackage* PackageList::GetPackageForActor(Actor* actor)
{
    struct PackageSelection
    {
        TESPackage* package;
        DurationData* schedule;
        TESPackage* current;
        BSSimpleList<TESPackage*>* list;
    } selection;
    char message[300];
    selection.list = ((::BSSimpleList< ::TESPackage *> *)(new ((void *)this) ::Vec3()));
    selection.current = 0;
    if (actor)
        selection.current = reinterpret_cast<::FUN_009344a0_shell *>((actor))->FUN_009344a0();
    if (!selection.list->IsEmpty())
    {
        selection.package = 0;
        selection.schedule = 0;
        while (selection.list && (selection.package = ((::TESPackage *)(new ((void *)(selection.list)) ::Vec3()))))
        {
            if ((selection.package->vfn_138(actor) && !selection.package->IsFlag10000Set() &&
                 !selection.package->IsMustReachLocation()) ||
                (selection.package->IsMustReachLocation() &&
                 !reinterpret_cast<::FUN_0041d8c0_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))))->HasRunOncePackage(selection.package)))
            {
                selection.schedule = reinterpret_cast<::FUN_0041d8a0_shell *>((selection.package))->FUN_0041d8a0();
                if (selection.schedule)
                {
                    bool bCalendarMonth;
                    bool bDayOfMonth;
                    bool bDayOfWeek;
                    bDayOfWeek = false;
                    bDayOfMonth = false;
                    bCalendarMonth = false;
                    if (selection.schedule->FUN_0086a460() + ((int)(reinterpret_cast<::Callees *>((selection.schedule))->FUN_00726070())) > 24)
                    {
                        bDayOfWeek = reinterpret_cast<::fnv_00678d40::FUN_00678d40_shell *>((selection.package))->IsPackageScheduledForDay(true);
                        int yesterday = ((char)(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::Calendar *>(&::g_011de7b8))))->GetDayOfMonth())) - 1;
                        if (yesterday < 0)
                            yesterday = 30;
                        if (reinterpret_cast<::FUN_00678ce0_shell *>((selection.schedule))->FUN_00678ce0() == yesterday)
                            bDayOfMonth = true;
                        int lastMonth = (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetCurrentMonth() - 1;
                        if (lastMonth < 0)
                            lastMonth = 12;
                        if (selection.schedule->FUN_00678ca0() == lastMonth)
                            bCalendarMonth = true;
                    }
                    if ((selection.schedule->FUN_00678ca0() == -1 ||
                         selection.schedule->FUN_00678ca0() == (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetCurrentMonth() || bCalendarMonth) &&
                        (reinterpret_cast<::FUN_00678ce0_shell *>((selection.schedule))->FUN_00678ce0() == 0 ||
                         reinterpret_cast<::FUN_00678ce0_shell *>((selection.schedule))->FUN_00678ce0() == ((char)(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::Calendar *>(&::g_011de7b8))))->GetDayOfMonth())) || bDayOfMonth) &&
                        (reinterpret_cast<::FUN_00678cc0_shell *>((selection.schedule))->GetSecondByte() == -1 || reinterpret_cast<::fnv_00678d40::FUN_00678d40_shell *>((selection.package))->IsPackageScheduledForDay(false) ||
                         bDayOfWeek) &&
                        (selection.schedule->FUN_0086a460() == -1 ||
                         IsHourInRange(selection.schedule->FUN_0086a460(), ((int)(reinterpret_cast<::Callees *>((selection.schedule))->FUN_00726070())),
                                       (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameTime())))
                    {
                        struct PackageTargetState
                        {
                            PackageTargetRecord* packageTarget;
                            TESObjectREFR* reference;
                        } targetState;
                        targetState.reference = 0;
                        targetState.packageTarget = ((::PackageTargetRecord *)(reinterpret_cast<::Script *>((selection.package))->GetData()));
                        if (targetState.packageTarget)
                            targetState.reference = targetState.packageTarget->GetReferenceTarget();
                        if (((::PerkEntryConditionSet *)(reinterpret_cast<::PackedByteIntRecord *>((selection.package))->Endian()))->ContainsTrait(actor, targetState.reference))
                        {
                            if (((::Actor *)(::fnv_00703180::FUN_00703180())) == actor)
                            {
                                sprintf(
                                    message, "%s Picked Package %s (%s)", reinterpret_cast<::FUN_0055d520_shell *>((actor))->FUN_0055d520(),
                                    ((const char *)(::FUN_00464f30((int)(g_packageTypeNames[reinterpret_cast<struct ::FUN_0041ca90 *>((selection.package))->get()])))),
                                    ((const char *)(::FUN_00464f30((int)(selection.package->GetName())))));
                                ::FUN_00703c00(message, {});
                            }
                            if (reinterpret_cast<::FUN_009611e0_shell *>((selection.package))->FUN_009611e0() == -1)
                                reinterpret_cast<::fnv_006777b0::FUN_006777b0_shell *>((selection.package))->ComputePackageFlags(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80());
                            if (selection.current && selection.current != selection.package &&
                                reinterpret_cast<struct ::FUN_0041ca90 *>((selection.current))->get() == 1)
                            {
                                Actor* leader = dynamic_cast<Actor*>(((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetLowProcess40());
                                if (leader)
                                    reinterpret_cast<::fnv_00422690::FUN_00422690_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((leader))->FUN_005d43c0()))))->FUN_00422690((::fnv_00422690::Actor *)(actor));
                            }
                            if (selection.current && selection.current != selection.package)
                            {
                                ::FUN_005ac750(selection.current, ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0())), 0x800);
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->HandleOnPackageChange(actor, selection.current);
                                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->vfn_5a8(0);
                            }
                            if (selection.package && selection.package != selection.current)
                                ::FUN_005ac750(selection.package, ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0())), 0x200);
                            return selection.package;
                        }
                    }
                }
            }
            selection.list = ((::BSSimpleList< ::TESPackage *> *)(reinterpret_cast<::Callees *>((selection.list))->FUN_00726070()));
        }
    }
    return selection.current;
}

// Resolves each package form ID in the package list to a TESPackage, warning and removing entries that cannot be found.
// @fnv 0x0067e560
void PackageList::InitItem(TESForm* form)
{
    struct PackageResolutionCursor
    {
        BSSimpleList<TESPackage*>* list;
        BSSimpleList<TESPackage*>* previous;
        TESFile* file;
    } cursor;
    cursor.list = ((::BSSimpleList< ::TESPackage *> *)(new ((void *)this) ::Vec3()));
    cursor.previous = 0;
    cursor.file = form ? form->GetFile(-1) : 0;
    while (cursor.list && !cursor.list->IsEmpty())
    {
        struct PackageResolution
        {
            unsigned int formID;
            TESPackage* package;
        } packageEntry;
        packageEntry.formID = reinterpret_cast<unsigned int>(((::TESPackage *)(new ((void *)(cursor.list)) ::Vec3())));
        if (form)
            ::ResolveFormID((unsigned int *)&(packageEntry.formID), cursor.file);
        packageEntry.package = dynamic_cast<TESPackage*>(::FUN_004839c0(packageEntry.formID));
        if (!packageEntry.package)
        {
            BSStringT<char> debugName;
            if (form)
                form->GetDebugName(&debugName);
            else
                reinterpret_cast<::TextString *>(&(debugName))->FUN_004037f0("UNKNOWN form", 0);
            ::FUN_005b5e40();
            if (cursor.previous)
            {
                TESPackage* pMissingPackage = reinterpret_cast<TESPackage*>(packageEntry.formID);
                reinterpret_cast<::ItemChangeListNode *>((cursor.previous))->FUN_00905330((::InventoryStackRecord *const &)(pMissingPackage));
                cursor.list = ((::BSSimpleList< ::TESPackage *> *)(reinterpret_cast<::Callees *>((cursor.previous))->FUN_00726070()));
            }
            else
                cursor.list->RemoveHead();
        }
        else
        {
            cursor.list->SetItem(packageEntry.package);
            cursor.previous = cursor.list;
            cursor.list = ((::BSSimpleList< ::TESPackage *> *)(reinterpret_cast<::Callees *>((cursor.list))->FUN_00726070()));
        }
    }
}

// Checks whether the integer hour falls within the range from start to start+duration, handling wrap-around past 23.
// @fnv 0x0067e700
bool IsHourInRange(int start, int duration, float hour)
{
    struct TimeRange
    {
        int current;
        int wrapped;
        int end;
    } timeRange;
    timeRange.current = static_cast<int>(hour);
    timeRange.end = start + duration;
    timeRange.wrapped = 0;
    if (timeRange.current == start)
        return true;
    if (timeRange.end > 23)
    {
        timeRange.wrapped = timeRange.end - 24;
        if ((timeRange.current > start || timeRange.current < timeRange.wrapped) && timeRange.current < timeRange.end)
            return true;
    }
    else if (timeRange.current > start && timeRange.current < timeRange.end)
        return true;
    return false;
}

// @fnv 0x0067e440
void PackageList::Copy(const PackageList* src)
{
    struct CopyCursor
    {
        TESPackage* package;
        BSSimpleList<TESPackage*>* list;
    } cursor;
    ClearPackageList();
    cursor.list = ((::BSSimpleList< ::TESPackage *> *)(new ((void *)(src)) ::Vec3()));
    if (!cursor.list->IsEmpty())
    {
        while (cursor.list)
        {
            cursor.package = ((::TESPackage *)(new ((void *)(cursor.list)) ::Vec3()));
            AddPackage(cursor.package);
            cursor.list = ((::BSSimpleList< ::TESPackage *> *)(reinterpret_cast<::Callees *>((cursor.list))->FUN_00726070()));
        }
    }
}

// Appends the given TESPackage to the list returned by GetListOfPackages().
// @fnv 0x0067e420
void PackageList::AddPackage(TESPackage* package)
{
    reinterpret_cast<::Callees *>((((::BSSimpleList< ::TESPackage *> *)(new ((void *)this) ::Vec3()))))->FUN_00905820((void *)&(package));
}

struct FUN_0067efd0_shell : public TESPackage
{
    bool FUN_0067efd0();
};
// Scans packages over the coming days/hours, adds those whose schedule matches and are not current or already missed, then sorts the missed list by schedule.
// @fnv 0x0067ec40
void PackageList::CollectEligiblePackages(Actor* actor, BSSimpleList<TESPackage*>* pMissedList, float elapsed,
                                          float startHour)
{
    struct CalendarScan
    {
        float hour;
        int day;
        int currentMonth;
        int month;
        int year;
    } scan;
    struct MissedPackageContext
    {
        int today;
        TESPackage* current;
        BSSimpleList<TESPackage*>* cursor;
    } sortCtx;
    sortCtx.current = 0;
    scan.day = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->vfn_30();
    scan.month = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->vfn_34();
    scan.year = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->vfn_38();
    scan.hour = startHour;
    sortCtx.today = ((char)(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::Calendar *>(&::g_011de7b8))))->GetDayOfMonth()));
    scan.currentMonth = (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetCurrentMonth();
    while (scan.day)
    {
        BSSimpleList<TESPackage*>* pList = ((::BSSimpleList< ::TESPackage *> *)(new ((void *)this) ::Vec3()));
        if (actor)
            sortCtx.current = reinterpret_cast<::FUN_009344a0_shell *>((actor))->FUN_009344a0();
        if (!pList->IsEmpty())
        {
            TESPackage* pPackage = 0;
            DurationData* pSchedule = 0;
            while (pList && (pPackage = ((::TESPackage *)(new ((void *)(pList)) ::Vec3()))))
            {
                if (reinterpret_cast<::FUN_0067efd0_shell *>((pPackage))->FUN_0067efd0() && reinterpret_cast<::FUN_00677760_shell *>((pPackage))->FUN_00677760(actor))
                {
                    pSchedule = reinterpret_cast<::FUN_0041d8a0_shell *>((pPackage))->FUN_0041d8a0();
                    if (pSchedule && (pSchedule->FUN_00678ca0() == -1 || pSchedule->FUN_00678ca0() <= scan.month) &&
                        (reinterpret_cast<::FUN_00678ce0_shell *>((pSchedule))->FUN_00678ce0() == 0 || reinterpret_cast<::FUN_00678ce0_shell *>((pSchedule))->FUN_00678ce0() <= scan.day) &&
                        (reinterpret_cast<::FUN_00678cc0_shell *>((pSchedule))->GetSecondByte() == -1 ||
                         reinterpret_cast<::FUN_00678cc0_shell *>((pSchedule))->GetSecondByte() <= (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameDayOfWeek()) &&
                        (pSchedule->FUN_0086a460() == -1 || pSchedule->FUN_0086a460() < scan.hour) &&
                        pPackage != sortCtx.current && !reinterpret_cast<::RefList *>((pMissedList))->FUN_005f65d0((void **)&(pPackage)))
                    {
                        if (reinterpret_cast<::FUN_009611e0_shell *>((pPackage))->FUN_009611e0() == -1)
                            reinterpret_cast<::fnv_006777b0::FUN_006777b0_shell *>((pPackage))->ComputePackageFlags(reinterpret_cast<::FUN_00569b80_shell *>((actor))->FUN_00569b80());
                        reinterpret_cast<::Callees *>((pMissedList))->FUN_00905820((void *)&(pPackage));
                    }
                }
                pList = ((::BSSimpleList< ::TESPackage *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
            }
            scan.hour += 1.0;
            if (scan.hour > 23.0)
            {
                ++scan.day;
                scan.hour = 0;
                unsigned short usDaysInMonth = ((unsigned short)(::GetShortFromTable((signed char)scan.month)));
                if (scan.day > usDaysInMonth)
                {
                    scan.day -= usDaysInMonth;
                    ++scan.month;
                    if (scan.month >= 12)
                    {
                        scan.month -= 12;
                        ++scan.year;
                    }
                }
            }
            if (scan.day == sortCtx.today && scan.month == scan.currentMonth &&
                (int)scan.hour >= (int)(*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameTime())
                scan.day = 0;
        }
        else
            scan.day = 0;
    }
    sortCtx.cursor = pMissedList;
    BSSimpleList<TESPackage*>* pNext = 0;
    if (sortCtx.cursor)
    {
        unsigned int iCount = sortCtx.cursor->ItemsInList();
        bool bSwapped = true;
        while (iCount && bSwapped)
        {
            bSwapped = false;
            pNext = sortCtx.cursor;
            while (pNext)
            {
                TESPackage* pPackage1 = ((::TESPackage *)(new ((void *)(sortCtx.cursor)) ::Vec3()));
                TESPackage* pPackage2 = ((::TESPackage *)(new ((void *)(pNext)) ::Vec3()));
                if (reinterpret_cast<::ComparisonOwner *>((pPackage1))->CompareTo((::ComparisonEntry *)(::DurationData *)(reinterpret_cast<::FUN_0041d8a0_shell *>((pPackage2))->FUN_0041d8a0())) == 1)
                {
                    sortCtx.cursor->SetItem(pPackage2);
                    pNext->SetItem(pPackage1);
                    bSwapped = true;
                }
                pNext = ((::BSSimpleList< ::TESPackage *> *)(reinterpret_cast<::Callees *>((pNext))->FUN_00726070()));
            }
            sortCtx.cursor = ((::BSSimpleList< ::TESPackage *> *)(reinterpret_cast<::Callees *>((sortCtx.cursor))->FUN_00726070()));
            --iCount;
        }
    }
}

// @fnv 0x0067efd0
bool FUN_0067efd0_shell::FUN_0067efd0()
{
    return (*(unsigned int*)((char*)this + 0x1c) & 4) ? true : false;
}

class FUN_0067e4a0_cls
{
  public:
    bool FUN_008256d0();
    bool FUN_0067e4a0(FUN_0067e4a0_cls* other);
};

// Compares two lists element by element via FUN_006815c0 and FUN_00726070, returning true if they differ or one is exhausted first.
// @fnv 0x0067e4a0
bool FUN_0067e4a0_cls::FUN_0067e4a0(FUN_0067e4a0_cls* other)
{
    unsigned int q;
    unsigned int r;
    FUN_0067e4a0_cls* p;
    FUN_0067e4a0_cls* s;

    s = (FUN_0067e4a0_cls*)((unsigned int *)(new ((void *)this) ::Vec3()));
    p = (FUN_0067e4a0_cls*)((unsigned int *)(new ((void *)(other)) ::Vec3()));
    if (!s->FUN_008256d0())
    {
        while (s != 0 && *((unsigned int *)(new ((void *)(s)) ::Vec3())) != 0 && p != 0 && *((unsigned int *)(new ((void *)(p)) ::Vec3())) != 0)
        {
            r = *((unsigned int *)(new ((void *)(s)) ::Vec3()));
            q = *((unsigned int *)(new ((void *)(p)) ::Vec3()));
            if (r != q)
            {
                return true;
            }
            s = (FUN_0067e4a0_cls*)((int)(reinterpret_cast<::Callees *>((((DurationData*)s)))->FUN_00726070()));
            p = (FUN_0067e4a0_cls*)((int)(reinterpret_cast<::Callees *>((((DurationData*)p)))->FUN_00726070()));
        }
        if (s != 0 || p != 0)
        {
            return true;
        }
    }
    else
    {
        if (!p->FUN_008256d0())
        {
            return true;
        }
    }
    return false;
}
