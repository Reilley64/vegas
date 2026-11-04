#pragma once

class DCEEntryInit;
struct Arg0;
struct Cfg;
struct Ctx;
struct FUN_00d4dfc0_class;
struct FUN_00dced30_cls;
struct JOut;
struct ListOwner;
struct NodeDce;
struct P5;
struct Resolver;
struct S_00dcee80_Info;
struct S_00dcee80_QueryIn;
struct S_00dcee80_QueryOut;
struct Src;
struct Visitor;

// 0x00dce180
int FUN_00dce180(::Arg0 *, ::NodeDce *, ::NodeDce *, ::NodeDce *, void *, ::P5 *);
// 0x00dce7b0
void RunWithLocalContext(::Resolver *, ::ListOwner *, ::Ctx *);
// 0x00dce930
extern "C" ::DCEEntryInit *FUN_00dce930(void *, void *);
// 0x00dcea10
void FUN_00dcea10(::Resolver *, ::ListOwner *, ::Ctx *, ::Visitor *);
// 0x00dced30
void FUN_00dced30(::FUN_00dced30_cls *);
// 0x00dced50
void FUN_00dced50(::FUN_00d4dfc0_class *, unsigned int);
// 0x00dced70
const void *FUN_00dced70();
// 0x00dcee70
void FUN_00dcee70();
// 0x00dcee80
void FUN_00dcee80(const ::S_00dcee80_Info &, const ::S_00dcee80_QueryIn &, ::S_00dcee80_QueryOut &);
// 0x00dcefb0
void FUN_00dcefb0(::Src *, ::Cfg *, ::JOut **);
