#pragma once

class hkpCdBody;
class hkpCdPointCollector;
struct CollisionAgentContext;

class hkpCapsuleCapsuleAgent {
public:
    // 0x00d3bd80
    static void FUN_00d3bd80(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdPointCollector &);
};
