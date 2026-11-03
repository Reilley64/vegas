#pragma once

struct GskAgentInput;
struct WorldOperationEntry;
struct hkpCdBody;

class hkpBvTreeStreamAgent {
public:
    // 0x00d2df90
    void FUN_00d2df90(const ::hkpCdBody &, const ::hkpCdBody &, const ::GskAgentInput &, ::WorldOperationEntry &);
};
