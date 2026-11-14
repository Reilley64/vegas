#pragma once

struct BodyList;
struct BodyOut;
struct ControlData;
struct IntegerTriple;
struct Output;
struct TransformReferenceData;

// 0x00d6b4b0
void FUN_00d6b4b0(::BodyList *, ::BodyOut *);
// 0x00d6b8e0
void FUN_00d6b8e0(float, const ::TransformReferenceData &, const ::IntegerTriple &, const ::ControlData *, ::Output *);
