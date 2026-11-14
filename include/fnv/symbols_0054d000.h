#pragma once

class TESObjectCELL;
struct PortalVisitCell;
struct PortalVisitPoint;
struct PortalVisitRef;

// 0x0054d4b0
bool FUN_0054d4b0(::PortalVisitCell *, const ::PortalVisitPoint &, float, const ::PortalVisitPoint &, float, bool (*)(PortalVisitRef *, void *), void *);
// 0x0054de40
void *FUN_0054de40(::TESObjectCELL *);
