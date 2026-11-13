#pragma once

class Setting;

// 0x0043d4d0
int &FUN_0043d4d0(Setting *);
// The value 4 bytes into the setting, where the 32-bit layout has it. No
// object defines this form; calls whose argument is not shown to be a
// setting of the shared class stay on it (VEGAS-111). Do not define it,
// alias it or add calls to it; a call moves to the form above when its
// argument is shown to be a shared-class setting. It is removed with the last
// tabled call.
int &FUN_0043d4d0(int *);
