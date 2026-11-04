#pragma once
#include <cstdint>

class NiAnimTarget;
class NiStream;
class NiFixedString;
struct ActorCombatGroup;
struct FUN_00a57580_cls;
struct FUN_00a575b0_Object;
template <class, class> class NiTPrimitiveArray;
template <class, class> struct NiTArray;
template <class, class> struct NiTPrimitiveArray;
template <class> class NiTMallocInterface;
template <class> struct NiTMallocInterface;

// 0x00a57050
::NiAnimTarget *FUN_00a57050(intptr_t, int);
// 0x00a570b0
void FUN_00a570b0(::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *);
// 0x00a572a0
int *InitTimeController(int *);
// 0x00a574e0
char *SafeStrcat(char *, unsigned int, const char *);
// 0x00a57500
void FUN_00a57500(::NiFixedString *);
// 0x00a57580
int InvokeAndAccumulate(::FUN_00a57580_cls *, intptr_t);
// 0x00a575b0
void FUN_00a575b0(::FUN_00a575b0_Object *, intptr_t);
// 0x00a576c0
void FUN_00a576c0(::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *);
// 0x00a57c00
struct FUN_00a57c00_shell { void FUN_00a57c00(::NiStream &); };
// 0x00a57d10
void FUN_00a57d10(::NiTArray< ::ActorCombatGroup *, ::NiTMallocInterface< ::ActorCombatGroup *>> *);
