#pragma once

class CollisionAgentContext;
class hkpCdBody;
class hkpCdBodyPairCollector;

struct SphereDispatch {
public:
    // 0x00d44900
    void ProcessSpheres(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdBodyPairCollector &);
};
