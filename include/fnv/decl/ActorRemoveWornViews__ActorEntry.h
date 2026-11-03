#pragma once

class ExtraDataList;
class TESBoundObject;

namespace ActorRemoveWornViews {
struct ActorEntry {
public:
    // 0x0088e110
    bool FUN_0088e110(::TESBoundObject *, int, ::ExtraDataList *, bool, bool);
};
}
