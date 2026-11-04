// fallout_shared/tesland_decls.h: declares TESPackage
enum PACKAGE_PROCEDURE_TYPE;
class TESPackage
{
  public:
    char prefix[0x1c];
    unsigned int flags;
    bool FUN_005394a0();
public:
    void SetProcedureType(::PACKAGE_PROCEDURE_TYPE);
};
