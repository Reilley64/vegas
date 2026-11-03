#pragma once

namespace PackageMovement { struct Actor; }

namespace PackageMovement {
struct Process {
public:
    // 0x008e7c70
    void ProcessActorMovement(::PackageMovement::Actor *);
};
}
