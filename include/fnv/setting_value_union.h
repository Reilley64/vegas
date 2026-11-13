#ifndef FNV_SETTING_VALUE_UNION_H
#define FNV_SETTING_VALUE_UNION_H

// The value of a setting. SETTING_VALUE.h includes this header after
// layout_support.h; a unit that cannot include layout_support.h includes
// this one (VEGAS-111).
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
