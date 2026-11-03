#pragma once

struct FetcherC;
struct NiTransform;
struct ReturnType;
struct VisitorB;
struct hkTransform;

// 0x0056d280
::ReturnType *FUN_0056d280(unsigned int);
// 0x0056d730
void FUN_0056d730(void *);
// 0x0056df80
::hkTransform &FromHK(::hkTransform &, const ::NiTransform &);
// 0x0056dff0
void *VisitAndFetchThree(::FetcherC *, ::VisitorB *);
