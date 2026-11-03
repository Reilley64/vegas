#pragma once

class Actor;
class QueuedFile;
class TESObjectIMOD;
#include "../../layout_support.h"

class TESObjectWEAP {
public:
    // 0x004be380
    float GetWeightForForm(bool);
    // 0x0051e2a0
    int GetReloadAnim(bool);
    // 0x00521480
    void SetModItem(unsigned int, ::TESObjectIMOD *);
    // 0x00525510
    void QueueResourceLoad(int, ::QueuedFile *, bool);
    // 0x00525b20
    unsigned char GetDamageForActor(bool, bool, ::Actor *);
    // 0x00709430
    float FUN_00709430(bool);
    // 0x009b6600
    ::ActorValue__Index GetResistance();
};
