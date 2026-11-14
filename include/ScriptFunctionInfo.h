#ifndef FNV_SCRIPT_FUNCTION_H
#define FNV_SCRIPT_FUNCTION_H

#include "layout_support.h"
class ScriptFunctionInfo
{
  public:
    char* pFunctionName;          // +0x0
    char* m_pShortName;           // +0x4
    SCRIPT_OUTPUT m_eOutputType;  // +0x8
    char* m_pDescription;         // +0xC
    bool m_bRequiresReference;    // +0x10
    unsigned char layoutPadding11;
    unsigned short m_usParameterCount;          // +0x12
    ScriptParameter* pParameters;              // +0x14
    FNVScriptExecuteFunction m_pfnExecute;      // +0x18
    FNVScriptCompileFunction m_pfnCompile;      // +0x1C
    FNVScriptConditionFunction m_pfnCondition;  // +0x20
    bool m_bFunctionFlag;                       // +0x24
    bool m_bSetsExecutionFlag;                  // +0x25
    unsigned short layoutPadding26;
};
#endif
