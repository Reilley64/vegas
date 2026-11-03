
// src/speedtree/windinfo_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/windinfo.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/windinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/windinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00b3ed20_cls.h"
#include "fnv/decl/S_00b3ed80.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/decl/fnv_00b059e0__FUN_00b06090.h"
#include "fnv/symbols_01170000.h"
struct S00b408b0_Vec
{
    float x;
    float y;
    float z;
};

struct S00b408b0_Reader
{
    S00b408b0_Vec* GetVector3(S00b408b0_Vec* out);
};

struct S00b408b0_Str
{
    S00b408b0_Str(const char* s);
    ~S00b408b0_Str()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(1, 0);
    }
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
};

struct S00b408b0_Exc
{
    S00b408b0_Exc(S00b408b0_Str& s, int n);
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
};


struct S00b408b0_Big
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    int fd8;
    int fdc;
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    int ff8;
    int ffc;
    int f100;
};

inline void S00b408b0_Prep()
{
    S00b408b0_Big big;
    big.f38 = 0;
}

struct S00b408b0_Obj
{
    S00b408b0_Vec pos;
    S00b408b0_Vec rot;
    float scale;
    void FUN_00b408b0(S00b408b0_Reader* r);
};

// @fnv 0x00b408b0
void S00b408b0_Obj::FUN_00b408b0(S00b408b0_Reader* r)
{
    S00b408b0_Vec spare;
    S00b408b0_Vec a;
    S00b408b0_Vec b;
    S00b408b0_Vec d;
    S00b408b0_Vec c;
    S00b408b0_Vec e;
    S00b408b0_Prep();
    int tok = ((int)(reinterpret_cast<::S_00b3ed80 *>((r))->GetNextElement()));
    do
    {
        switch (tok)
        {
        case 5000:
            r->GetVector3(&a);
            break;
        case 5001:
            r->GetVector3(&b);
            break;
        case 5002:
            rot = *r->GetVector3(&c);
            break;
        case 5003:
            r->GetVector3(&d);
            break;
        case 5004:
            pos = *r->GetVector3(&e);
            break;
        case 5005:
            scale = reinterpret_cast<::FUN_00b3ed20_cls *>((r))->FUN_00b3ed20();
            break;
        case 5006:
            reinterpret_cast<::fnv_00b059e0::FUN_00b06090 *>((r))->FUN_00b06180();
            break;
        default: {
            S00b408b0_Str msg("malformed general wind information");
            S00b408b0_Exc ex(msg, 0);
            throw ex;
            break;
        }
        }
        tok = ((int)(reinterpret_cast<::S_00b3ed80 *>((r))->GetNextElement()));
    } while (tok != 1012);
}
