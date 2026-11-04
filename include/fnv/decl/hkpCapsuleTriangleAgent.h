#pragma once

class hkpCdBody_S;
class hkpCdPointCollector;
struct CollisionAgentContext;

class hkpCapsuleTriangleAgent {
public:
    // 0x00d3a280
    static void FUN_00d3a280(const ::hkpCdBody_S &, const ::hkpCdBody_S &, const ::CollisionAgentContext &, ::hkpCdPointCollector &);
};
