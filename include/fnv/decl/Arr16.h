#pragma once

struct Elem16;
struct Entry16;

struct Arr16 {
public:
    // 0x00691b60
    unsigned int FUN_00691b60(::Elem16 *);
    // 0x006c8810
    unsigned int AppendValue(int);
    // 0x006dae00
    unsigned int FUN_006dae00(::Entry16 *);
    // 0x006f2d20
    unsigned int AppendElement(const ::Elem16 *);
};
