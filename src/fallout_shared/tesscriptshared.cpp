// fallout_shared/tesscriptshared.cpp: free functions (1 function)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "layout_support.h"

class ScriptLocalVariable
{
  public:
    unsigned int uiID;
    unsigned char layoutPadding4[4];
    double fValue;
    bool m_bIsString;
    unsigned char layoutPadding11[7];
    ScriptLocalVariable();
};

class ScriptVariableInfo
{
  public:
    ScriptLocalVariable data;
    BSStringT<char> m_kName;
    ScriptVariableInfo();
};

// @fnv 0x005e28b0
ScriptVariableInfo::ScriptVariableInfo()
{}
