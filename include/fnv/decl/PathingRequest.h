#pragma once

struct BGSLoadFormBuffer;
struct PathingLocation;
enum PATHING_REQUEST_TYPE;
template <class, unsigned int> class BSSimpleArray;

struct PathingRequest {
public:
    // 0x0051b840
    void SetActorRadius(float);
    // 0x0051b860
    float GetSmoothingRandomness();
    // 0x0051b8e0
    float GetGoalZDelta();
    // 0x006a78f0
    float GetTargetRadius();
    // 0x006d1bc0
    void SetDestination(::PathingLocation *);
    // 0x006d3b00
    void SetCenterRadius(float);
    // 0x006d61e0
    void SetAvoidNodeArray(::BSSimpleArray<void *, 1024> *);
    // 0x006e2420
    PathingRequest();
    // 0x006e2750
    void CopyTo(::PathingRequest *);
    // 0x006e2f80
    static ::PathingRequest *CreateRequestForType(::PATHING_REQUEST_TYPE);
    // 0x006e34f0
    void LoadGame(::BGSLoadFormBuffer *);
    // 0x009a7c40
    float GetActorRadius();
    // 0x009b0bd0
    float GetCenterRadius();
};
