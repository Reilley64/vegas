// src/speedtree/branchinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/branchinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/decl/B13970Self.h"
#include "fnv/decl/ClsB3FCF0.h"
#include "fnv/decl/FUN_00b15170.h"
#include "fnv/decl/FUN_00b3ed20_cls.h"
#include "fnv/decl/FUN_00b3fdd0_class.h"
#include "fnv/decl/FUN_00b3ff20_Class.h"
#include "fnv/decl/FUN_00b40000_class.h"
#include "fnv/decl/OwnerB3ff90.h"
#include "fnv/decl/S_00b3ed80.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/decl/fnv_00b3fd60__set00b3fd60__SxOwner.h"
#include "fnv/decl/fnv_00b3fe40__set00b3fe40__SxOwner.h"
#include "fnv/decl/fnv_00b3feb0__set00b3feb0__SxOwner.h"
#include "fnv/decl/setb3f__SxOwner.h"
struct S_00b3f310_Item
{
    int unk00;
    int unk04;
    int unk08;
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
    S_00b3f310_Item();
};

struct FUN_00b3f310
{
    int unk00;
    int unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    float unk20;
    float unk24;
    int unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    int unk50;
    S_00b3f310_Item* unk54;
    S_00b3f310_Item* unk58;
    int unk5c;
    S_00b3f310_Item* unk60;
    S_00b3f310_Item* unk64;
    S_00b3f310_Item* unk68;
    S_00b3f310_Item* unk6c;
    int unk70;
    FUN_00b3f310();
};

// Initialises the object's fields to default values and allocates six S_00b3f310_Item instances into the pointer fields.
// @fnv 0x00b3f310
FUN_00b3f310::FUN_00b3f310()
{
    unk00 = 6;
    unk04 = 3;
    unk08 = DAT_01017870;
    unk0c = 1.0f;
    unk10 = DAT_01017870;
    unk14 = 1.0f;
    unk18 = 1.0f;
    unk1c = 1;
    unk1d = 0;
    unk1e = 0;
    unk20 = 0.0f;
    unk24 = 1.0f;
    unk28 = 0;
    unk2c = 1.0f;
    unk30 = DAT_01018f5c;
    unk34 = DAT_01017b78;
    unk38 = 1.0f;
    unk3c = ::fnv_00c88020::DAT_01016248;
    unk40 = DAT_0101622c;
    unk44 = DAT_01017870;
    unk48 = DAT_0101e2bc;
    unk4c = 1.0f;
    unk50 = 0;
    unk54 = 0;
    unk58 = 0;
    unk5c = 0;
    unk60 = 0;
    unk64 = 0;
    unk68 = 0;
    unk6c = 0;
    unk70 = 0;
    unk58 = new S_00b3f310_Item;
    unk54 = new S_00b3f310_Item;
    unk64 = new S_00b3f310_Item;
    unk6c = new S_00b3f310_Item;
    unk68 = new S_00b3f310_Item;
    unk60 = new S_00b3f310_Item;
}

struct S_00b3f310_Item_WithDtor : S_00b3f310_Item
{
    ~S_00b3f310_Item_WithDtor();
};

struct FUN_00b3f310_Host : FUN_00b3f310
{
    void FUN_00b3f620();
};

// @fnv 0x00b3f620
void FUN_00b3f310_Host::FUN_00b3f620()
{
    delete (S_00b3f310_Item_WithDtor*)unk58;
    delete (S_00b3f310_Item_WithDtor*)unk5c;
    delete (S_00b3f310_Item_WithDtor*)unk54;
    delete (S_00b3f310_Item_WithDtor*)unk50;
    delete (S_00b3f310_Item_WithDtor*)unk6c;
    delete (S_00b3f310_Item_WithDtor*)unk64;
    delete (S_00b3f310_Item_WithDtor*)unk68;
    delete (S_00b3f310_Item_WithDtor*)unk60;
    delete (S_00b3f310_Item_WithDtor*)unk70;

    unk58 = 0;
    unk5c = 0;
    unk54 = 0;
    unk50 = 0;
    unk6c = 0;
    unk64 = 0;
    unk68 = 0;
    unk60 = 0;
    unk70 = 0;
}

struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
};

struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};

struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};

struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
};

struct Parser
{
    unsigned uiPos;
    ByteVec kData;
};

inline void DeadTop()
{
    int aiD[135];
    aiD[94] = 0;
}

struct BranchQ
{
    int iA;
    int iB;
    float afF[5];
    bool bA;
    bool bB;
    char acPad[0x56];
    BranchQ();
};

// @fnv 0x00b3f8e0
BranchQ* FUN_00b3f8e0(Parser* p)
{
    DeadTop();
    BranchQ* pBranch = new BranchQ;
    int iToken = ((int)(reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement()));
    if (iToken != 0x3f8)
        throw FUN_00b09480("malformed branch data", false);
    iToken = ((int)(reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement()));
    do
    {
        switch (iToken)
        {
        case 0x1770:
            reinterpret_cast<::setb3f::SxOwner *>((pBranch))->FUN_00b3fc80((::setb3f::SxObj *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1771:
            reinterpret_cast<::ClsB3FCF0 *>((pBranch))->FUN_00b3fcf0((::SubObj_b3f *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1772:
            reinterpret_cast<::fnv_00b3fd60::set00b3fd60::SxOwner *>((pBranch))->FUN_00b3fd60((::fnv_00b3fd60::set00b3fd60::SxObj *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1773:
            reinterpret_cast<::FUN_00b3fdd0_class *>((pBranch))->FUN_00b3fdd0((::FUN_00b37880_class *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1781:
            reinterpret_cast<::FUN_00b40000_class *>((pBranch))->FUN_00b40000((::Sub_b40000 *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1774:
            reinterpret_cast<::fnv_00b3fe40::set00b3fe40::SxOwner *>((pBranch))->FUN_00b3fe40((::fnv_00b3fe40::set00b3fe40::SxObj *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1775:
            reinterpret_cast<::fnv_00b3feb0::set00b3feb0::SxOwner *>((pBranch))->FUN_00b3feb0((::fnv_00b3feb0::set00b3feb0::SxObj *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1776:
            reinterpret_cast<::FUN_00b3ff20_Class *>((pBranch))->FUN_00b3ff20((::FUN_00b37880 *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1777:
            reinterpret_cast<::OwnerB3ff90 *>((pBranch))->FUN_00b3ff90((::FUN_00b37880_class *)(((int)(reinterpret_cast<::B13970Self *>((p))->FUN_00b13970()))));
            break;
        case 0x1778:
            pBranch->iA = ((int)(reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement()));
            break;
        case 0x1779:
            pBranch->iB = ((int)(reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement()));
            break;
        case 0x177a:
            pBranch->afF[0] = reinterpret_cast<::FUN_00b3ed20_cls *>((p))->FUN_00b3ed20();
            break;
        case 0x177b:
            pBranch->afF[1] = reinterpret_cast<::FUN_00b3ed20_cls *>((p))->FUN_00b3ed20();
            break;
        case 0x177c:
            pBranch->afF[2] = reinterpret_cast<::FUN_00b3ed20_cls *>((p))->FUN_00b3ed20();
            break;
        case 0x177d:
            pBranch->afF[3] = reinterpret_cast<::FUN_00b3ed20_cls *>((p))->FUN_00b3ed20();
            break;
        case 0x177e:
            pBranch->afF[4] = reinterpret_cast<::FUN_00b3ed20_cls *>((p))->FUN_00b3ed20();
            break;
        case 0x177f:
            pBranch->bA = ((unsigned char)(reinterpret_cast<::FUN_00b15170 *>(&(p->kData))->GetElement(p->uiPos++))) != 0;
            break;
        case 0x1780:
            pBranch->bB = ((unsigned char)(reinterpret_cast<::FUN_00b15170 *>(&(p->kData))->GetElement(p->uiPos++))) != 0;
            break;
        default:
            throw FUN_00b09480("malformed general branch information", false);
        }
        iToken = ((int)(reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement()));
    } while (iToken != 0x3f9);
    return pBranch;
}
