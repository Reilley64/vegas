#pragma once

// The fields of a package's schedule (DurationData in TESPackage), for units whose stand-ins declare no fields. The
// list getter folded into 0x00726070 (BSSimpleList::GetNext) reads `iDuration` when called on a schedule.
struct PackageScheduleFields
{
    char cMonth;
    char cDayOfWeek;
    char cDate;
    char cTime;
    int iDuration;
};
