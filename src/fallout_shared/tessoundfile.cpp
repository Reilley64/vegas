// src/fallout_shared/tessoundfile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tessoundfile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/symbols_00404000.h"
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
struct FNStub
{
};
struct TESSoundFile : public BaseFormComponent
{
    virtual ~TESSoundFile();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void SetName(const char* name);
    void FUN_0048cf00(BaseFormComponent* apCopyFC);
};
// Casts apCopyFC to TESSoundFile and, if successful, copies its full name via SetName.
// @fnv 0x0048cf00
void TESSoundFile::FUN_0048cf00(BaseFormComponent* apCopyFC)
{
    TESSoundFile* pcopy = dynamic_cast<TESSoundFile*>(apCopyFC);
    if (!pcopy)
        return;
    SetName(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)pcopy)))->FUN_00408da0())));
}

class TESModel
{
  public:
    unsigned int GetModelLength();
};
struct FUN_0048cf50_shell : public TESSoundFile
{
    bool FUN_0048cf50(BaseFormComponent* apCompareFC);
};
// @fnv 0x0048cf50
bool FUN_0048cf50_shell::FUN_0048cf50(BaseFormComponent* apCompareFC)
{
    TESSoundFile* pcompare = dynamic_cast<TESSoundFile*>(apCompareFC);
    if (!pcompare)
        return true;
    if (reinterpret_cast<TESModel*>(this)->GetModelLength() || reinterpret_cast<TESModel*>(pcompare)->GetModelLength())
    {
        if (reinterpret_cast<TESModel*>(this)->GetModelLength() !=
            reinterpret_cast<TESModel*>(pcompare)->GetModelLength())
            return true;
        else
        {
            if (::FUN_00404dc0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(this)))->FUN_00408da0())),
                         ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(pcompare)))->FUN_00408da0()))))
                return true;
        }
    }
    return false;
}
