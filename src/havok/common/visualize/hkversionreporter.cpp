
// src/havok/common/visualize/hkversionreporter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkversionreporter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BufferOwner.h"
#include "fnv/decl/D60590Object.h"
#include "fnv/decl/FUN_00d605d0_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00dda690.h"
#include "fnv/decl/FUN_00dda6e0.h"
#include "fnv/decl/StringBuf.h"
#include "fnv/decl/hkOArchiveStandIn.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/symbols_00cb1000.h"
struct S_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};
struct S_Router
{
    int unk0;
    int unk4;
    int unk8;
    S_Alloc* m0c;
    S_Alloc* m10;
    S_Alloc& temp()
    {
        return *m0c;
    }
    S_Alloc& heap()
    {
        return *m10;
    }
};
S_Router* FUN_00c85750();

struct S_Arr
{
    char* data;
    int size;
    int cap;
    void clear(S_Alloc& a)
    {
        size = 0;
        if ((cap & 0x80000000) == 0)
            a.ReturnMemory(data, cap & 0x3fffffff);
        data = 0;
        cap = 0x80000000;
    }
};

struct S_Writer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
struct S_Out
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
};
struct S_Str : S_Arr
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
};
extern int DAT_011b5dc0;
extern int DAT_011b5dbc;

// Builds a string with the PC_32 value and "MSVC:1500", writes both into a stream, then writes the accumulated buffer to the named output and clears the buffers.
// @fnv 0x00d61290
int WriteCompilerInfo(const char* name)
{
    S_Arr buffer;
    buffer.data = 0;
    buffer.size = 0;
    buffer.cap = 0x80000000;
    S_Out outStream;
    new ((void *)&(outStream)) ::FUN_00dda690((int)(&buffer));
    reinterpret_cast<::FUN_00d605d0_class *>(&(outStream))->FUN_00d605d0(0x90);
    reinterpret_cast<::hkOArchive_2 *>(&(outStream))->WriteInt(DAT_011b5dc0);
    reinterpret_cast<::hkOArchive_2 *>(&(outStream))->WriteInt(DAT_011b5dbc);
    int n = ::fnv_00cb10d0::FUN_00cb10d0("PC_32");
    if (n > 0xffff)
        n = 0xffff;
    reinterpret_cast<::hkOArchiveStandIn *>(&(outStream))->WriteUInt16(n);
    reinterpret_cast<::FUN_00d607b0_class *>(&(outStream))->FUN_00d607b0((int)("PC_32"));
    S_Str versionStr;
    reinterpret_cast<::BufferOwner *>(&(versionStr))->InitBuffer();
    reinterpret_cast<::StringBuf *>((&versionStr))->FUN_00d61d00("%s:%i", "MSVC", 1500);
    int iVersionLen = versionStr.size - 1;
    if (iVersionLen > 0xffff)
        iVersionLen = 0xffff;
    reinterpret_cast<::hkOArchiveStandIn *>(&(outStream))->WriteUInt16(iVersionLen);
    reinterpret_cast<::FUN_00d607b0_class *>(&(outStream))->FUN_00d607b0((int)(versionStr.data));
    S_Out f;
    new ((void *)&(f)) ::FUN_00dda6e0((int)(name));
    reinterpret_cast<::hkOArchive_2 *>(&(f))->WriteInt(buffer.size);
    reinterpret_cast<::FUN_00d607b0_class *>(&(f))->FUN_00d607b0((int)(buffer.data));
    reinterpret_cast<::D60590Object *>(&(f))->FUN_00d60590();
    versionStr.clear(FUN_00c85750()->temp());
    reinterpret_cast<::D60590Object *>(&(outStream))->FUN_00d60590();
    buffer.clear(FUN_00c85750()->heap());
    return 0;
}

#include "generated/data/havok/common/visualize/hkversionreporter.inc"
