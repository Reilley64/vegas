#pragma once

class hkpCdBody;
struct GskAgentInput;
struct WorldOperationEntry;

class hkpPredGskfAgent {
public:
    // 0x00d42020
    void FUN_00d42020(const ::hkpCdBody &, const ::hkpCdBody &, const ::GskAgentInput &, ::WorldOperationEntry &);
};
