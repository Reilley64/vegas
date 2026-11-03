// Source layout: OSGlobals. PC corrections are in generate_headers.py.
#ifndef FNV_OSGLOBALS_H
#define FNV_OSGLOBALS_H

#include "fnv/decl/MagicCaster_shell.h"
#include "layout_support.h"
// Partial PC prefix through sound; sizeof checks this prefix, not the entire runtime allocation.
class OSGlobals
{
  public:
    unsigned char oneMore;         // +0x0
    unsigned char quitGame;        // +0x1
    unsigned char exitToMainMenu;  // +0x2
    unsigned char layoutPadding3;
    unsigned short layoutPadding4;
    bool isFlycam;  // +0x6
    unsigned char layoutPadding7;
    void* window;               // +0x8
    void* procInstance;         // +0xC
    unsigned int mainThreadID;  // +0x10
    void* mainThreadHandle;     // +0x14
    void* scrapHeapBuffer;      // +0x18
    unsigned int layoutPadding1C;
    OSInputGlobals* input;  // +0x20
    OSSoundGlobals* sound;  // +0x24
};
#endif
