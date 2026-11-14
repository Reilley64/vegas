#pragma once

class hkpCdBody_S;
class hkpCdPointCollector_S;
struct hkpCollisionInput_S;

class hkpGskBaseAgent_S {
public:
    // 0x00dac450
    static void FUN_00dac450(const ::hkpCdBody_S &, const ::hkpCdBody_S &, const ::hkpCollisionInput_S &, ::hkpCdPointCollector_S &);
};
