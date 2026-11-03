// Source layout: NiFixedString. PC corrections are in generate_headers.py.
#ifndef FNV_NIFIXEDSTRING_H
#define FNV_NIFIXEDSTRING_H
#include "layout_support.h"
class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
    operator const char*() const;
public:
    ::NiFixedString &operator=(const char *);
};
#endif
