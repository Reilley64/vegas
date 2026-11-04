#pragma once

struct EdgeArray;
struct hkBoolCF74;
struct hkEntryCF74;
struct hkPairCF74;

// 0x00cf7130
void FUN_00cf7130(::EdgeArray *, ::EdgeArray *);
// 0x00cf74b0
int FUN_00cf74b0(const ::hkEntryCF74 &, const ::hkEntryCF74 &);
// 0x00cf74e0
::hkBoolCF74 LessThanPairPriority(const ::hkPairCF74 &, const ::hkPairCF74 &);
