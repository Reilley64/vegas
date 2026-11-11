// Source layout: NiFixedString. PC corrections are in generate_headers.py.
#ifndef FNV_NIFIXEDSTRING_H
#define FNV_NIFIXEDSTRING_H
#include "layout_support.h"
// A unit that defines FNV_KEEPS_PLAIN_NIFIXEDSTRING before its includes keeps
// this plain layout view. Every other unit gets the shared declaration.
#ifdef FNV_KEEPS_PLAIN_NIFIXEDSTRING
class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
    operator const char*() const;
public:
    ::NiFixedString &operator=(const char *);
};
#else
#include "fnv/native_fixed_string.h"
#endif
#endif
