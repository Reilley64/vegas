// Source layout: SETTING_VALUE. PC corrections are in generate_headers.py.
#ifndef FNV_SETTING_VALUE_H
#define FNV_SETTING_VALUE_H
#include "layout_support.h"
union SETTING_VALUE
{
  public:
    const char* str;  // +0x0
    int i;            // +0x0
    unsigned int u;   // +0x0
    float f;          // +0x0
    bool b;           // +0x0
    char c;           // +0x0
    unsigned char h;  // +0x0
};
#endif
