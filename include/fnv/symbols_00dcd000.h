#pragma once

struct Block512;
struct CollisionRecordHeader;
struct DCD6A0Context;
struct DCD6A0Item;
struct DstBlock;
struct S00dcd720_Cb;
struct S00dcd720_Out;
struct S00dcd720_Src;
struct S_00dcda40_World;
struct S_00dcdd80_Listener;
struct SrcNode;
struct Struct0x20;
template <class> struct hkArray;

// 0x00dcd4d0
int FUN_00dcd4d0(void *);
// 0x00dcd550
int FUN_00dcd550(::CollisionRecordHeader *, char, ::DCD6A0Context **, int *, int *, void **, int);
// 0x00dcd6a0
int DispatchItemToAgent(int, ::DCD6A0Context **, void *, void *, ::DCD6A0Item *);
// 0x00dcd720
int FUN_00dcd720(::S00dcd720_Cb *, ::S00dcd720_Src *, int, ::S00dcd720_Out *);
// 0x00dcd950
int CopyAudioNodeTree(::SrcNode *, int, ::DstBlock *);
// 0x00dcda40
void ProcessCollisionRecords(void *, ::S_00dcda40_World *, ::S_00dcdd80_Listener *);
// 0x00dcde10
namespace fnv_00dcde10 { int DispatchInstruction(char *, int, void *, char **, unsigned char *); }
// 0x00dcdf70
int FUN_00dcdf70(const ::hkArray< ::Block512 *> &, void *, ::Struct0x20 *);
