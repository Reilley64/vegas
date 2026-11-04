#pragma once

struct HitActor;
struct HitForm;

struct HitTrackerImpl {
public:
    // 0x006238b0
    void AddHitEntries(float, ::HitForm *, ::HitForm *, ::HitActor *, ::HitActor *);
};
