#pragma once

class CollisionAgentContext;
class hkpCdBody;
class hkpCdBodyPairCollector;

class hkpMultiSphereAgent {
public:
    // 0x00d444f0
    void GetPenetrations(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdBodyPairCollector &);
};
