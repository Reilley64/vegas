#pragma once

enum PTYPE;

struct ActorPackageData {
public:
    // 0x0067d920
    ActorPackageData();
    // 0x008c6ca0
    static ::ActorPackageData *CreatePackageData(::PTYPE);
};
