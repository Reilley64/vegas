#pragma once

#include "havok/InlineStorageString.h"

struct SStringPtr;

namespace fnv_00dcc8e0
{
// Reader I/O boundary used by the retained token parsing caller.
struct TokenStream
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual int v04(char* buffer, int count) = 0;
    virtual void v05(int count) = 0;
    virtual void v06() = 0;
    virtual void v07(int count) = 0;
    virtual void v08() = 0;
};

struct TokenReader
{
    int unk00;
    int unk04;
    TokenStream* m_08;
    TokenReader* ReadToken(InlineStorageString* owner);
    TokenReader* ReadString(SStringPtr* target);
};
}
