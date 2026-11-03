// Source layout: BaseExtraList. PC corrections are in generate_headers.py.
#ifndef FNV_BASEEXTRALIST_H
#define FNV_BASEEXTRALIST_H
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "layout_support.h"
class BaseExtraList
{
  public:
    void** m_ppVirtualMethodTable;           // +0x0
    BSExtraData* pHead;        // +0x4
    unsigned char iFlags[21];  // +0x8
    unsigned char layoutPadding1D;
    unsigned short layoutPadding1E;
    BSExtraData* AddExtra(BSExtraData* extra);
};
#endif
