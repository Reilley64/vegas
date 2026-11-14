#pragma once

struct CdBody;
struct CollisionInput;
struct ConstraintOwner;

class ShapeCollectionAgent {
public:
    // 0x00d2f760
    void FUN_00d2f760(const ::CdBody &, const ::CdBody &, const ::CollisionInput &, ::ConstraintOwner &);
};
