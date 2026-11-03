
// bgsentrypointfunction_ctx_variant.cpp: context variant of src/fallout_shared/bgsentrypointfunction.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "BGSEntryPointFunction.h"

extern "C" void* __cdecl memset(void* dest, int c, size_t count);

class TESFile;
class ScriptVariableInfo
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    BSStringT<char> name;

    ScriptVariableInfo();
public:
    void Load(::TESFile *);
};

extern ScriptVariableInfo* DAT_011cb0fc;

class FUN_005e2a20_shell
{
  public:
};

class FUN_00500910
{
  public:
    BSStringT<char> name;
    unsigned int formID;
    unsigned int variableOrIndex;

    FUN_00500910();
};

class ScriptHeader
{
  public:
};

class FUN_005d43e0_shell
{
  public:
    void* FUN_005d43e0();
};

class FUN_005d43c0_
{
  public:
    void* FUN_005d43c0();
};

class FUN_005aae70_shell
{
  public:
    void FUN_005aae70(unsigned int, char*);
};

class FUN_00472840_impl
{
  public:
    bool ReadChunkData(unsigned short*);
};

class FUN_005e6c60_shell
{
  public:
public:
    void FUN_005e6c60(const char *);
};

class Script : public TESForm
{
  public:
};

class ActivateChoice : public BGSEntryPointFunctionDataActivateChoice
{
  public:
    bool FUN_005e6ee0(TESFile* file);
};

// @fnv 0x005e6ee0
bool ActivateChoice::FUN_005e6ee0(TESFile* file)
{
    void* scvrBuf3;
    unsigned int scdaSize4;
    void* scdaData;
    unsigned int scroRefID2;
    FUN_00500910* scroObjVal;
    unsigned int scrvRefID3;
    FUN_00500910* _scrvObj;
    void* epf2BufTmp;

    switch (static_cast<int>(((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))))
    {
    case 0x44534c53:  // 'SLSD'
    case 0x52564353:  // 'SCVR'
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x44534c53)
        {
            DAT_011cb0fc = new ScriptVariableInfo();
            reinterpret_cast<::ScriptVariableInfo *>((reinterpret_cast<FUN_005e2a20_shell*>(DAT_011cb0fc)))->Load(file);
            reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Actor*>*>(reinterpret_cast<FUN_005d43e0_shell*>(formStorage)->FUN_005d43e0())))->FUN_00905820((void *)&(reinterpret_cast<Actor*&>(DAT_011cb0fc)));
        }
        else if (DAT_011cb0fc)
        {
            scvrBuf3 = _alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(scvrBuf3), 0x200);
            reinterpret_cast<::TextString *>(&(DAT_011cb0fc->name))->FUN_004037f0(reinterpret_cast<const char*>(scvrBuf3), 0);
        }
        break;

    case 0x52484353:  // 'SCHR'
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(((::ScriptHeader *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<Script*>(formStorage)))->GetConditions()))), 0);
        if (file->IsEndianConversionRequired())
        {
            reinterpret_cast<::FUN_00414220_shell *>((((::ScriptHeader *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<Script*>(formStorage)))->GetConditions()))))->FUN_00414220();
        }
        break;

    case 0x41444353:  // 'SCDA'
        scdaSize4 = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
        scdaData = _alloca(scdaSize4);
        memset(scdaData, 0, scdaSize4);
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(scdaData), 0);
        reinterpret_cast<FUN_005aae70_shell*>(formStorage)->FUN_005aae70(scdaSize4, reinterpret_cast<char*>(scdaData));
        break;

    case 0x4f524353:  // 'SCRO'
        scroObjVal = new FUN_00500910();
        file->GetChunkData(&scroRefID2);
        scroObjVal->formID = scroRefID2;
        reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Actor*>*>(reinterpret_cast<FUN_005d43c0_*>(formStorage)->FUN_005d43c0())))->FUN_00905820((void *)&(reinterpret_cast<Actor*&>(scroObjVal)));
        break;

    case 0x56524353:  // 'SCRV'
        _scrvObj = new FUN_00500910();
        file->GetChunkData(&scrvRefID3);
        _scrvObj->variableOrIndex = scrvRefID3;
        reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<Actor*>*>(reinterpret_cast<FUN_005d43c0_*>(formStorage)->FUN_005d43c0())))->FUN_00905820((void *)&(reinterpret_cast<Actor*&>(_scrvObj)));
        break;

    case 0x32465045:  // 'EPF2'
        epf2BufTmp = _alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(epf2BufTmp), 0);
        reinterpret_cast<FUN_005e6c60_shell*>(this)->FUN_005e6c60((const char *)(epf2BufTmp));
        break;

    case 0x33465045:  // 'EPF3'
        reinterpret_cast<FUN_00472840_impl*>(file)->ReadChunkData(&flags);
        break;

    default:
        break;
    }

    return true;
}
