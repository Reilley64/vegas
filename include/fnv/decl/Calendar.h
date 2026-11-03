#pragma once

enum CALENDAR_MONTH;
enum DAYS_OF_THE_WEEK;

class Calendar {
public:
    // 0x00450d80
    void ResetCachedValues();
    // 0x00867950
    float GetGameTimeScale();
    // 0x00867a40
    void Update(float);
    // 0x00867d20
    ::CALENDAR_MONTH GetCurrentMonth();
    // 0x00867d60
    int GetDayOfMonth();
    // 0x00867da0
    float GetGameTime();
    // 0x00867de0
    unsigned int GetGameDaysPassed();
    // 0x00867e30
    unsigned int GetGameHoursPassed();
    // 0x00867ef0
    ::DAYS_OF_THE_WEEK GetGameDayOfWeek();
    // 0x0086a460
    char GetGameHour();
};
