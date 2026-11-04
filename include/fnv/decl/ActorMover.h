#pragma once

class NiPoint3;

class ActorMover {
public:
    // 0x0059bb30
    unsigned int GetCurrentMoveModeType();
    // 0x008b3d10
    bool HasLookAtTarget();
    // 0x009dc590
    void UpdateMovement(float);
    // 0x009dcdb0
    bool HasActiveMovement();
    // 0x009dd0a0
    void StopMoving();
    // 0x009dd150
    void ClearMovementPath();
    // 0x009ddb50
    bool IsMovementActive();
    // 0x009de230
    void RunProcedure();
    // 0x009de270
    bool GetLookAtTargetPosition(::NiPoint3 &);
};
