
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/Unk65.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/symbols_01017000.h"
struct FUN_0044a500_s
{
    int AssignSubstring(int, int, void*);
    FUN_0044a500_s* FUN_0044a500(int);
};
// @fnv 0x0044a500
FUN_0044a500_s* FUN_0044a500_s::FUN_0044a500(int a)
{
    reinterpret_cast<::Unk65 *>(this)->CallAndReturnSelf(a);
    reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(0, 0);
    AssignSubstring(a, 0, (*reinterpret_cast<void * *>(&::g_010173f0)));
    return this;
}

class FUN_00ec78e0
{
  public:
    FUN_00ec78e0();
    virtual ~FUN_00ec78e0();
    int unk04[2];
};

class FUN_0044a500
{
  public:
    FUN_0044a500(void* pArg);
    int unk00;
};

class FUN_0044a310 : public FUN_00ec78e0
{
  public:
    FUN_0044a500 m_kMember;

    FUN_0044a310(void* pArg);
    virtual ~FUN_0044a310();
};

// Initializes the m_kMember field with the provided pArg pointer.
// @fnv 0x0044a310
FUN_0044a310::FUN_0044a310(void* pArg) : m_kMember(pArg)
{}
