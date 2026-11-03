#pragma once

struct ExtraEmittanceSource;
struct ExtraLevCreaModifier;
struct ExtraXTarget;

// 0x00435040
::ExtraLevCreaModifier *ExtraLevCreaModifierCtor(::ExtraLevCreaModifier *);
// 0x00435370
::ExtraXTarget *ConstructExtraXTarget(::ExtraXTarget *);
// 0x00435440
::ExtraEmittanceSource *InitExtraEmittanceSource(::ExtraEmittanceSource *);
// 0x00435dd0
float FUN_00435dd0();
