
// src/havok/common/base/reflection/registry/hkvtableclassregistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/registry/hkvtableclassregistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00cb0a60.h"
#include "fnv/decl/S_00d49350.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d48000.h"
#include "fnv/symbols_00dc0000.h"
#include "fnv/symbols_011b7000.h"
#include "fnv/symbols_01269000.h"
struct BoolResult
{
    char value;
    BoolResult()
    {}
};
struct IntResult
{
    int value;
    IntResult()
    {}
};
struct Object
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual BoolResult vf0c();
};
struct Buffer
{
    int value;
};
struct Manager
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual int vf10(int*);
};
IntResult FUN_00dcca60(Object*);
struct ParseState
{
    int status;
    Buffer buffer;
    int bits;
};
// Checks the object and parse state, returning 1 when the buffer comparison or manager check succeeds.
// @fnv 0x00d49240
int FUN_00d49240(Object* object)
{
    if (!object || !object->vf0c().value)
        return 0;
    if (FUN_00dcca60(object).value > 1)
        return 1;
    ParseState parseState;
    new ((void *)&(parseState.buffer)) struct ::FUN_00cb0a60();
    ::FUN_00d48af0(object, &parseState.status);
    if (parseState.status == 2)
    {
        if (::FUN_00cb1290((const unsigned char *)(void *)(&parseState.bits), (const unsigned char *)(const void *)(&DAT_011b7b88), 4) != 0)
            goto check3;
        if (reinterpret_cast<::S_00d49350 *>(&(parseState.buffer))->Equals((const char *)(((int)(::FUN_00dc0fb0())))) != 0)
        {
            ::FUN_00cb0c00((int)&(parseState.buffer));
            return 1;
        }
        goto manager;
    }
check3:
    if (parseState.status != 3)
        goto failure;
manager:
    if ((*reinterpret_cast<::Manager * *>(&::DAT_01269b74))->vf10(&parseState.status))
    {
        ::FUN_00cb0c00((int)&(parseState.buffer));
        return 1;
    }
failure:
    ::FUN_00cb0c00((int)&(parseState.buffer));
    return 0;
}
