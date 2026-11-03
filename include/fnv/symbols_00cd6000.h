#pragma once

class ContactRecord;
class ContactVector;
struct Feature;
struct hkContactPoint;
struct hkVector4;

// 0x00cd6260
int FUN_00cd6260(const ::hkVector4 *, float, const ::hkVector4 *, float, float, ::hkContactPoint *);
// 0x00cd6520
void FUN_00cd6520(const ::ContactVector *, float, const ::ContactVector *, float, const float *, float, int, ::ContactRecord *, ::Feature *);
