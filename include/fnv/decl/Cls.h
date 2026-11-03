#pragma once
#include "havok/hkUlong.h"

struct Elem;
struct Entry;
struct EntryListNode;
struct F8;
struct Flag;
struct Input;
struct ModelRef;
struct P1;
struct Renderer;

struct Cls {
public:
    // 0x00489670
    void LoadTextureArchiveEntries(::Elem *, unsigned int, ::ModelRef *, const char *);
    // 0x00529330
    void FUN_00529330();
    // 0x00626420
    void FUN_00626420(int);
    // 0x0082c810
    void ApplyEffect();
    // 0x00858af0
    void FUN_00858af0(::EntryListNode *, ::Entry *, bool);
    // 0x009670f0
    bool FUN_009670f0(int);
    // 0x00b306d0
    void FUN_00b306d0(unsigned short);
    // 0x00c7ba50
    void FUN_00c7ba50(void *, void *, bool *);
    // 0x00dbda50
    void FUN_00dbda50(void *, void *, void *);
    // 0x00de6730
    void FUN_00de6730(::Input *, ::Renderer *, hkUlong, int);
    // 0x00e5f070
    void FUN_00e5f070(::P1 *, unsigned char *, ::F8 *);
    // 0x00e65040
    void FUN_00e65040(::Flag, int);
};
