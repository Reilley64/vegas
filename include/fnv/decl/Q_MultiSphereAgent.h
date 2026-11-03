#pragma once

class CollisionAgentContext;
class hkpCdBody;
class hkpCdPointCollector;

class Q_MultiSphereAgent {
public:
    // 0x00d446f0
    void FUN_00d446f0(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdPointCollector &, ::hkpCdPointCollector *);
};
