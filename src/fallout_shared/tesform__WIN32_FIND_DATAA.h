// Source layout: _WIN32_FIND_DATAA. PC corrections are in generate_headers.py.
#ifndef FNV_UNIT_TESFORM__WIN32_FIND_DATAA_H
#define FNV_UNIT_TESFORM__WIN32_FIND_DATAA_H
#include "tesform_layout_support.h"
#include "tesform__FILETIME.h"
class _WIN32_FIND_DATAA
{
  public:
    unsigned long dwFileAttributes;  // +0x0
    _FILETIME ftCreationTime;        // +0x4
    _FILETIME ftLastAccessTime;      // +0xC
    _FILETIME ftLastWriteTime;       // +0x14
    unsigned long nFileSizeHigh;     // +0x1C
    unsigned long nFileSizeLow;      // +0x20
    unsigned long dwReserved0;       // +0x24
    unsigned long dwReserved1;       // +0x28
    char cFileName[260];             // +0x2C
    char cAlternateFileName[14];     // +0x130
    unsigned char layoutPadding13E[2];
};
#endif
