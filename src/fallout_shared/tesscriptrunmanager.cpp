// fallout_shared/tesscriptrunmanager.cpp: ScriptRunner, ScriptExecutor (11 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0046dce0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005a9290_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_0061af10_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Runner.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFaction_RankDataView.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b1000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e2000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_0118e000.h"
#include "tesscriptrunmanager_layout.h"
#include "tesscriptrunmanager_form.h"
#include "Script.h"
#include "ScriptReferencedObject.h"
#include "ScriptFunctionInfo.h"
#include "TESObjectREFR.h"
#include "original_script.h"
#include "game_constants.h"
#include "ScriptHeaderData.h"
#include "ScriptLocals.h"
#include "ExpressionEvaluator.h"
#include "TESQuest.h"
#include "TESGlobal.h"
#include <new>
#include "tesscriptrunmanager_decls.h"
extern void DebugLog(const char* format, ...);

// Reads the output opcode, optional reference ID and line size from the script data at offset, resolving the reference and reporting an error if it is unknown.
// @fnv 0x005e13a0
bool ScriptRunner::ParseOutput(Script* script, SCRIPT_OUTPUT& output, unsigned int& offset, int& lineSize,
                               TESObjectREFR** ppReference, bool skipReference)
{
    lineSize = 0;
    output = static_cast<SCRIPT_OUTPUT>(*reinterpret_cast<short*>(script->GetData() + offset));
    offset += 2;
    if (output == SCRIPT_OUTPUT_FLOW_REFERENCE_FUNCTION)
    {
        bool isVariable = false;
        unsigned int referenceID = *reinterpret_cast<short*>(script->GetData() + offset);
        offset += 2;
        if (!skipReference)
        {
            ScriptReferencedObject* object = reinterpret_cast<::fnv_005ac4f0::FUN_005ac4f0_shell *>((script))->GetNthRefByIndex(referenceID, m_pScriptLocals);
            if (object)
            {
                isVariable = object->m_uiFormID > 0;
                if (object->pForm)
                {
                    *ppReference = dynamic_cast<TESObjectREFR*>(object->pForm);
                }
            }
        }
        output = static_cast<SCRIPT_OUTPUT>(*reinterpret_cast<short*>(script->GetData() + offset));
        offset += 2;
        if (!skipReference && !*ppReference && !isVariable)
        {
            ScriptFunctionInfo* function = GetFunctionByOpcode(output);
            if (function)
            {
                ::LogScriptCompileError((::ScriptRunner *)this, script,
                                "Unknown reference object for function '%s'.  Execution of script '%s' stopped.",
                                function->pFunctionName, script->GetName());
            }
            else
            {
                ::LogScriptCompileError((::ScriptRunner *)this, script, "Unknown reference object.  Execution of script '%s' stopped.",
                                script->GetName());
            }
            return false;
        }
    }
    else
    {
        *ppReference = 0;
    }
    lineSize = *reinterpret_cast<short*>(script->GetData() + offset);
    offset += 2;
    return true;
}

// Returns a pointer to the function-local static instance of the class.
// @fnv 0x005e24d0
ScriptExecutor* ScriptExecutor::Instance()
{
    static ScriptExecutor manager;
    return &manager;
}

// Acquires the script run lock, runs the script through a shared or temporary ScriptRunner, then releases the lock and returns the result.
// @fnv 0x005e2590
bool ScriptExecutor::Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target,
                         bool arg5, bool arg6, bool arg7, float arg8)
{
    bool result = false;
    if (InitScriptRunLock(&g_scriptRunLock) == 1)
    {
        if (!m_pReusableScriptRunner)
            m_pReusableScriptRunner = new ScriptRunner;
        m_pActiveScriptRunner = m_pReusableScriptRunner;
        result = reinterpret_cast<::Runner *>((m_pReusableScriptRunner))->RunScript((::A8 *)(script), reference, (::SLoc *)(locals), (int)(target), arg5, arg6, arg7, arg8);
        m_pActiveScriptRunner = 0;
    }
    else
    {
        ScriptRunner* runner = new ScriptRunner;
        ScriptRunner* previousRunner = m_pActiveScriptRunner;
        m_pActiveScriptRunner = runner;
        result = reinterpret_cast<::Runner *>((runner))->RunScript((::A8 *)(script), reference, (::SLoc *)(locals), (int)(target), arg5, arg6, arg7, arg8);
        m_pActiveScriptRunner = previousRunner;
        delete runner;
    }
    ::WaitForSingleObjectEx((long *)(void *)(&g_scriptRunLock));
    return result;
}

void* __cdecl memset(void*, int, unsigned int);

// Zeroes out all fields of the object pointed to by pThis and returns pThis.
// @fnv 0x005e0c60
void* __fastcall FUN_005e0c60(char* pThis)
{
    *(int*)(pThis + 0x20) = 0;
    *(int*)(pThis + 0x4c) = 0;
    *(int*)(pThis + 0x18) = 0;
    *(int*)(pThis + 0x1c) = 0;
    memset(pThis + 0x24, 0, 0x28);
    memset(pThis + 0x50, 0, 0x28);
    memset(pThis + 0x78, 0, 0x28);
    *(int*)(pThis + 0x00) = 0;
    *(int*)(pThis + 0x04) = 0;
    *(int*)(pThis + 0x08) = 0;
    *(int*)(pThis + 0x0c) = 0;
    *(int*)(pThis + 0x10) = 0;
    *(int*)(pThis + 0x14) = 0;
    *(char*)(pThis + 0xa0) = 0;
    *(char*)(pThis + 0xa1) = 0;
    return pThis;
}

struct TLSData_005e23f0
{
    char pad[0x268];
    bool bVal;
};

static __declspec(thread) TLSData_005e23f0 s_tlsData_005e23f0;

// @fnv 0x005e23f0
bool __cdecl GetThreadLocalValue()
{
    return s_tlsData_005e23f0.bVal;
}


// Formats a message into a local buffer, logs it via DebugLog or Warning, then zeroes the script header size and flags the runner as failed.
// @fnv 0x005e2410
void LogScriptCompileError(ScriptRunner* scriptRunner, Script* apScript, char* apFormat, ...)
{
    char buffer[260];
    char* varArgs;

    varArgs = (char*)(&apFormat + 1);
    FUN_00407000(buffer, apFormat, varArgs);
    varArgs = 0;

    if (::GetThreadLocalValue())
    {
        ::FUN_00703c00(((const char *)(::FUN_00464f30((int)(buffer)))), {});
    }
    else
    {
        ::FUN_005b5e40(::FUN_00464f30(buffer));
    }

    ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((apScript))->GetConditions()))->dataSize = 0;
    scriptRunner->m_bScriptCompileFailed = true;
}

struct FUN_005e24b0_shell
{
    char pad[0x18];
    void* m_18;
    void SetPointer(void* a, void* b);
};
// Executes one script command at the given offset, handling BEGIN blocks, SET, IF/ELSEIF/ELSE/ENDIF and function calls, updating blockSize and lineOffset.
// @fnv 0x005e1550
bool ScriptRunner::ParseBlock(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                              const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber,
                              bool skip, bool skipBlock)
{
    unsigned int offset = inputOffset;
    const char* data = script->GetData();
    if (output == SCRIPT_OUTPUT_FLOW_BEGIN)
    {
        int blockID = *reinterpret_cast<const short*>(data + offset);
        offset += 2;
        if (blockID < 0 || blockID >= kScriptBlockCount)
        {
            ::FUN_005b5e40();
            return false;
        }
        int skipSize = *reinterpret_cast<const int*>(data + offset);
        offset += 4;
        const ScriptParameter* blockParams = g_scriptBlocks[blockID].pParameters;
        FNVScriptExecuteFunction blockExecute = g_scriptBlocks[blockID].m_pfnExecute;
        if (skip)
        {
            if (blockParams && blockSize)
                ::FUN_005accb0((const ::ExtractParameter *)(blockParams), data, &offset, reference, m_pReference, (::ExtractScript *)(script), m_pScriptLocals);
        }
        else
        {
            if (g_scriptBlocks[blockID].m_bRequiresReference && !reference)
            {
                ::FUN_005b5e40();
                return false;
            }
            double result;
            if (!blockExecute ||
                !blockExecute(blockParams, data, reference, m_pReference, script, m_pScriptLocals, result, offset))
            {
                ::FUN_005b5e40();
                return false;
            }
            if (!result || skipBlock)
                blockSize += skipSize;
        }
    }
    else if (!skipBlock)
    {
        const ScriptFunctionInfo* function;
        switch (output)
        {
        case SCRIPT_OUTPUT_FLOW_SCRIPTNAME:
            break;
        case SCRIPT_OUTPUT_FLOW_BEGIN:
            break;
        case SCRIPT_OUTPUT_FLOW_END:
            break;
        case SCRIPT_OUTPUT_FLOW_SET: {
            char varType = data[offset];
            offset++;
            short variableID = 0;
            ScriptLocals* currentPScriptVariables = m_pScriptLocals;
            ScriptReferencedObject* referencedObject = 0;
            switch (varType)
            {
            case kScriptGlobalVariable:
            case kScriptReferenceVariable: {
                short referenceID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
                if (varType == kScriptReferenceVariable)
                {
                    varType = data[offset];
                    offset++;
                }
                referencedObject = reinterpret_cast<::fnv_005ac4f0::FUN_005ac4f0_shell *>((script))->GetNthRefByIndex(referenceID, m_pScriptLocals);
                if (!skip)
                {
                    if (varType != kScriptReferenceVariable && referencedObject && referencedObject->pForm)
                    {
                        TESObjectREFR* object = dynamic_cast<TESObjectREFR*>(referencedObject->pForm);
                        if (object)
                            currentPScriptVariables = reinterpret_cast<::FUN_005673e0_shell *>((object))->FUN_005673e0();
                        else
                        {
                            TESQuest* quest = dynamic_cast<TESQuest*>(referencedObject->pForm);
                            if (quest)
                                currentPScriptVariables = quest->GetScriptLocalData();
                        }
                        if (!currentPScriptVariables)
                        {
                            ::FUN_005b5e40();
                            return false;
                        }
                    }
                    else
                    {
                        ::FUN_005b5e40();
                        return false;
                    }
                }
            }
            break;
            }
            switch (varType)
            {
            case kScriptGlobalVariable:
                break;
            default: {
                variableID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
            }
            break;
            }
            short expressionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator variableExpression;
            double expressionValue = variableExpression.Eval(data + offset, reference, m_pReference, script,
                                                             m_pScriptLocals, expressionSize, skip);
            offset += expressionSize;
            if (variableExpression.ExpressionError())
            {
                ::FUN_005b5e40();
                ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->dataSize = 0;
                return false;
            }
            if (!skip)
            {
                if (varType == kScriptGlobalVariable)
                {
                    if (referencedObject && referencedObject->pForm)
                    {
                        if (!skip)
                        {
                            reinterpret_cast<::FUN_0046dce0_class *>((static_cast<TESGlobal*>(referencedObject->pForm)))->FUN_0046dce0(static_cast<float>(expressionValue));
                            if (::GetThreadLocalValue())
                                DebugLog("set global >> %0.2f", static_cast<float>(expressionValue));
                        }
                    }
                    else
                    {
                        ::FUN_005b5e40();
                        return false;
                    }
                }
                else
                {
                    if (currentPScriptVariables)
                    {
                        switch (varType)
                        {
                        case kScriptLongVariable:
                        case kScriptShortVariable:
                            reinterpret_cast<::FUN_005a9290_shell *>((currentPScriptVariables))->SetScriptVariable(variableID, static_cast<int>(expressionValue));
                            if (::GetThreadLocalValue())
                                ::FUN_00703c00("set %s >> %i",
                                         reinterpret_cast<::FUN_005abed0_shell *>((currentPScriptVariables->m_pOwnerScript))->FUN_005abed0(variableID));
                            break;
                        case kScriptFloatVariable:
                            reinterpret_cast<::FUN_005a9290_shell *>((currentPScriptVariables))->SetScriptVariable(variableID, expressionValue);
                            if (::GetThreadLocalValue())
                                ::FUN_00703c00("set %s >> %.2f",
                                         reinterpret_cast<::FUN_005abed0_shell *>((currentPScriptVariables->m_pOwnerScript))->FUN_005abed0(variableID));
                            break;
                        }
                        if ((referencedObject && referencedObject->pForm) || reference)
                        {
                            TESObjectREFR* changedReference = 0;
                            if (referencedObject)
                            {
                                if (referencedObject->pForm && referencedObject->pForm->GetIsReference())
                                    changedReference = static_cast<TESObjectREFR*>(referencedObject->pForm);
                            }
                            else
                                changedReference = reference;
                            if (changedReference && !reinterpret_cast<::FUN_004077c0_shell *>((void *)(changedReference))->FUN_004077c0())
                            {
                                if (!((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((changedReference))->GetTarget())) ||
                                    !::FUN_00450ff0((void *)(((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((changedReference))->GetTarget())))))
                                    changedReference->MarkAsModified(TESObjectREFR::CHANGE_SCRIPT_VARIABLES);
                            }
                        }
                    }
                    else
                    {
                        ::FUN_005b5e40();
                        return false;
                    }
                }
            }
            break;
        }
        case SCRIPT_OUTPUT_FLOW_IF:
            if (m_aiIfStack[m_iIfStackDepth])
                m_iIfStackDepth++;
            m_aiIfStack[m_iIfStackDepth] = kScriptIfActiveFlag;
        case SCRIPT_OUTPUT_FLOW_ELSEIF: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            short conditionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator condition;
            if (skip)
            {
                condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize, skip);
                m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
            }
            else
            {
                if (!(m_aiIfStack[m_iIfStackDepth] & kScriptIfConditionPassedFlag) &&
                    condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize,
                                   skip))
                    m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
                else
                    lineOffset += skipCount;
            }
            if (condition.ExpressionError())
            {
                reinterpret_cast<::FUN_005e24b0_shell *>(this)->SetPointer(script, (*(void * *)&(const ::SCRIPT_ERROR &)(SCRIPT_ERROR_ERROR_SCRIPT_EXPRESSION)));
                ::FUN_005b5e40();
                ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->dataSize = 0;
                m_eExpressionError = condition.ExpressionError();
                return false;
            }
            offset += conditionSize;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ELSE: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            if (!(m_aiIfStack[m_iIfStackDepth] & kScriptIfConditionPassedFlag))
                m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
            else if (!skip)
                lineOffset += skipCount;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ENDIF:
            m_aiIfStack[m_iIfStackDepth] = 0;
            if (m_iIfStackDepth)
                m_iIfStackDepth--;
            break;
        case SCRIPT_OUTPUT_FLOW_REFERENCE_FUNCTION:
            break;
        case SCRIPT_OUTPUT_FLOW_RETURN:
            if (skip)
                break;
        default: {
            function = GetFunctionByOpcode(output);
            if (!function)
            {
                BSStringT<char> message;
                ::FUN_00406f60((::FUN_00406f90_this *)&(message), "SCRIPTS: Unable to find function definition for command %d in script '%s'.", output,
                                script->GetName());
                if (::GetThreadLocalValue())
                    ::FUN_00703c00(((const char *)(::FUN_00464f30((int)(((const char *)(::FUN_00559450((int *)&(message)))))))), {});
                else
                    ::FUN_005b5e40(::FUN_00464f30(message))));
                return false;
            }
            else
            {
                const ScriptParameter* blockParams = function->pParameters;
                if (function->m_bRequiresReference && !reference && !skip)
                {
                    BSStringT<char> message;
                    ::FUN_00406f60((::FUN_00406f90_this *)&(message), "SCRIPTS: Script '%s', line %d: Function '%s' requires a reference.",
                                    script->GetName(), lineNumber, function->pFunctionName);
                    if (::GetThreadLocalValue())
                        ::FUN_00703c00(((const char *)(::FUN_00464f30((int)(((const char *)(::FUN_00559450((int *)&(message)))))))), {});
                    else
                        ::FUN_005b5e40(::FUN_00464f30(message))));
                    return false;
                }
                if (skip)
                {
                    if (blockParams && blockSize)
                    {
                        ::FUN_005accb0((const ::ExtractParameter *)(blockParams), data, &offset, reference, m_pReference, (::ExtractScript *)(script), m_pScriptLocals);
                        switch (output)
                        {
                        case SCRIPT_OUTPUT_FUNCTION_MESSAGE: {
                            short valueCount = *reinterpret_cast<const short*>(data + offset);
                            offset += 2;
                            for (short valueIndex = 0; valueIndex < valueCount; valueIndex++)
                            {
                                double expressionValue;
                                Script::GetValue(expressionValue, data, offset, reference, m_pReference, script,
                                                 m_pScriptLocals, true);
                            }
                            offset += 4;
                            break;
                        }
                        }
                    }
                }
                else
                {
                    FNVScriptExecuteFunction blockExecute = function->m_pfnExecute;
                    if (function->m_bSetsExecutionFlag)
                        m_bExecutionFlagSet = true;
                    double result;
                    if (!blockExecute || !blockExecute(blockParams, data, reference, m_pReference, script,
                                                       m_pScriptLocals, result, offset))
                    {
                        ::FUN_005b5e40();
                        return false;
                    }
                }
            }
        }
        }
    }
    return true;
}

// @fnv 0x005e24b0
void FUN_005e24b0_shell::SetPointer(void* a, void* apValue)
{
    m_18 = apValue;
}


struct FUN_005e2550_shell
{
    void* m_00;
    void* m_04;
    void Release();
};

// Deallocates m_00 via _Deallocate and nulls m_00 and m_04.
// @fnv 0x005e2550
void FUN_005e2550_shell::Release()
{
    void* tmp;
    if (m_00)
    {
        tmp = m_00;
        ::FUN_00401030(tmp);
        m_00 = 0;
    }
    m_04 = 0;
}

struct FUN_005e2730_shell : public ScriptExecutor
{
    bool FUN_005e2730(Script*, TESObjectREFR*, ScriptLocals*);
};

struct FUN_005e2850_class
{
    bool FUN_005e2850();
};
struct FUN_005e1160_shell
{
    void RunScript(Script*, TESObjectREFR*, ScriptLocals*);
};

// Creates a ScriptRunner if needed, then calls RunScript on either it or a temporary runner.
// @fnv 0x005e2730
bool FUN_005e2730_shell::FUN_005e2730(Script* apScript, TESObjectREFR* apOwnerObject, ScriptLocals* apOwnerVars)
{
    if (!*(ScriptRunner**)this)
        *(ScriptRunner**)this = new ScriptRunner;
    if (((FUN_005e2850_class*)*(ScriptRunner**)this)->FUN_005e2850())
    {
        ScriptRunner* pTempScriptRunner = new ScriptRunner;
        ((FUN_005e1160_shell*)pTempScriptRunner)->RunScript(apScript, apOwnerObject, apOwnerVars);
        delete pTempScriptRunner;
    }
    else
    {
        ((FUN_005e1160_shell*)*(ScriptRunner**)this)->RunScript(apScript, apOwnerObject, apOwnerVars);
    }
    return true;
}

namespace fnv_005e1160 {
class TESObjectREFR
{
  public:
    virtual void Set3D(NiNode* niNode, bool unloadArt);
    void Get3D(NiNode* niNode, bool unloadArt);
};

class ScriptRunner
{
  public:
    TESObjectREFR* m_pReference;
    TESObject* m_pScriptObject;
    ScriptLocals* m_pScriptLocals;
    TESTopicInfo* m_pTopicInfo;
    TESGlobal* m_pGlobal;
    Script* m_pScript;
    SCRIPT_ERROR m_eScriptError;
    EXPRESSION_ERROR m_eExpressionError;
    int m_iIfStackDepth;
    int m_aiIfStack[10];
    int m_iBlockStackDepth;
    int m_aiBlockOffsets[10];
    int m_aiBlockSizes[10];
    bool m_bScriptCompileFailed;
    bool m_bExecutionFlagSet;

    ScriptRunner();
    void SetErrorMessage(Script* script, char* message, ...);
    void SetError(Script* script, SCRIPT_ERROR error);
    bool RunScript(Script* script, TESObjectREFR* reference, ScriptLocals* locals);
    bool Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target, bool arg5,
             bool arg6, bool arg7, float arg8);
};

// Parses script output blocks, updates m_pScriptObject and m_pScriptLocals, and returns true after the loop.
// @fnv 0x005e1160
bool ScriptRunner::RunScript(Script* script, TESObjectREFR* reference, ScriptLocals* locals)
{
    if (!script || !script->GetInitialized())
        return false;
    if (m_pScript)
    {
        ::FUN_005b5e40();
        return false;
    }
    m_pScript = script;
    ExpressionEvaluator j;
    SCRIPT_OUTPUT k = (SCRIPT_OUTPUT)0xffff;
    unsigned int c = 0;
    if (reference)
        m_pScriptObject = ((::TESObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
    else
        m_pScriptObject = 0;
    m_pScriptLocals = locals;
    int q = 0;
    TESObjectREFR* b = 0;
    unsigned int f = 0;
    bool l = false;
    unsigned int e = 0;
    while (c < ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->dataSize)
    {
        e += 1;
        m_pGlobal = 0;
        q = 0;
        if (!reinterpret_cast<::ScriptRunner *>(this)->ParseOutput(script, k, c, q, (::TESObjectREFR **)(::fnv_005e1160::TESObjectREFR **)(&b), f != 0))
        {
            ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->dataSize = 0;
            break;
        }
        if (f != 0)
        {
            f -= 1;
        }
        else
        {
            if (!b)
                b = reference;
            if (!reinterpret_cast<::ScriptRunner *>(this)->ParseBlock(script, k, (::TESObjectREFR *)(b), q, c, f, e, false, true))
            {
                l = true;
                break;
            }
        }
        c += q;
    }
    m_pScript = 0;
    return true;
}
}  // namespace fnv_005e1160
