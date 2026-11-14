#pragma once

class Actor;
struct NiPoint3;
class TESObjectCELL;
class TESWorldSpace;
namespace fnv_009dbc90 { struct PathingRequest; }

// 0x009dbc90
namespace fnv_009dbc90 { void SetupPathingRequest(::Actor *, ::fnv_009dbc90::PathingRequest *, const ::NiPoint3 &, ::TESObjectCELL *, ::TESWorldSpace *, float, void *); }
