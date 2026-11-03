// fallout_shared/tesparameters.cpp: ScriptFunctionData, TESConditionItem (5 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00594000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00682000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_01190000.h"
#include "tesparameters.h"
#include "TESForm.h"
#include "Script.h"

// @fnv 0x006814e0
bool TESConditionItem::GetValueIsGlobal() const
{
    if (kData.ucType & 4)
        return true;
    return false;
}

// Returns the parameter count of the script command for apData's function, or 0 if apData is null.
// @fnv 0x00682270
unsigned int ScriptFunctionData::GetParamCount(const FunctionData* apData)
{
    unsigned int count = 0;
    if (apData)
        count = g_scriptCommands[apData->usFunction].numParams;
    return count;
}

// Returns whether the given function parameter is a TESForm, checking the special function case and otherwise the command's parameter type table.
// @fnv 0x006822a0
bool ScriptFunctionData::IsParamTESForm(const FunctionData* apData, unsigned int auiParam)
{
    bool isTESForm = false;
    if (apData && apData->usFunction + 0x1000 == 0x1198)
        isTESForm = ::IsValidTypeValue((int)(apData), auiParam);
    else if (apData && auiParam < GetParamCount(apData))
        isTESForm = DAT_0118cdd5[g_scriptCommands[apData->usFunction].params[auiParam].typeID].isTESForm;
    return isTESForm;
}

class TESParametersScriptSlots
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* vfn_130();
};

// Resolves each parameter of a script function data block to a form or script variable, warning when a form or variable cannot be found.
// @fnv 0x00681fb0
void ScriptFunctionData::InitItem(TESForm* apForm, FunctionData* apData)
{
    if (apForm)
    {
        if (apData)
        {
            unsigned int paramCount = GetParamCount(apData);
            TESFile* file = apForm ? apForm->GetFile(-1) : 0;
            for (unsigned int uiIndex = 0; uiIndex < paramCount; ++uiIndex)
            {
                if (IsParamTESForm(apData, uiIndex))
                {
                    unsigned int formID = apData->uParam[uiIndex].m_uiFormID;
                    if (formID)
                    {
                        ::ResolveFormID((unsigned int *)&(formID), file);
                        apData->uParam[uiIndex].pPointer = ::FUN_004839c0(formID);
                        if (!apData->uParam[uiIndex].pPointer)
                        {
                            BSStringT<char> strFormName;
                            apForm->GetDebugName(&strFormName);
                            ::FUN_005b5e40();
                        }
                        else if ((*reinterpret_cast<ParamTypeMetadata (*)[]>(&::DAT_0118cdd0))[g_scriptCommands[apData->usFunction].params[uiIndex].typeID].type == 11)
                        {
                            apData->uParam[uiIndex].pPointer = __RTDynamicCast(
                                apData->uParam[uiIndex].pPointer, 0, (void*)&typeid(TESForm), (*reinterpret_cast<char (*)[]>(&::DAT_01183140)), 0);
                            if (!apData->uParam[uiIndex].pPointer)
                            {
                                BSStringT<char> strFormName;
                                apForm->GetDebugName(&strFormName);
                                ::FUN_005b5e40();
                            }
                        }
                    }
                }
                else if (::FUN_00682380((unsigned short *)(apData), uiIndex))
                {
                    if (uiIndex > 0)
                    {
                        Script* script = ::FUN_006823d0(uiIndex - 1, apData);
                        if (script && !reinterpret_cast<::FUN_005abed0_shell *>((script))->FUN_005abed0(apData->uParam[uiIndex].m_uiFormID))
                        {
                            BSStringT<char> strFormName;
                            apForm->GetDebugName(&strFormName);
                            ::FUN_005b5e40();
                        }
                    }
                }
            }
        }
    }
}

struct _ParamInfo
{
    const char* pTypeStr;
    unsigned int eType;
    unsigned int m_bIsOptional;
};

struct _CommandEntry
{
    char pad[0x14];
    _ParamInfo* pParameters;
    char pad2[0x10];
};


// Returns true when the parameter at aiParam of apFuncData has type 4 or 6, after bounds-checking against the function's parameter count.
// @fnv 0x00682320
bool __cdecl FUN_00682320(const FunctionData* apFuncData, unsigned int aiParam)
{
    bool bretval = false;
    if (apFuncData && aiParam < ScriptFunctionData::GetParamCount(apFuncData))
    {
        switch ((*reinterpret_cast<_CommandEntry (*)[]>(&::g_scriptCommands))[apFuncData->usFunction].pParameters[aiParam].eType)
        {
        case 4:
        case 6:
            bretval = true;
            break;
        }
    }
    return bretval;
}

#include "generated/data/fallout_shared/tesparameters.inc"
