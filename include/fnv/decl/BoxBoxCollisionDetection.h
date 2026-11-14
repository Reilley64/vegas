#pragma once

struct BoxBoxEdgeContact;
struct hkBool;

struct BoxBoxCollisionDetection {
public:
    // 0x00db15a0
    ::hkBool TestEdgeEdgeContact(::BoxBoxEdgeContact *);
};
