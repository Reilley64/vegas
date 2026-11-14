// fallout_shared/tesparameters.h: declares ConditionItemData, TESConditionItem, ParamInfo, CommandInfo, ParamTypeInfo and more
#ifndef FNV_TESPARAMETERS_LOCAL_H
#define FNV_TESPARAMETERS_LOCAL_H

// Community-derived names, not canonical. Declarations represent PC layout.
#include "fnv/symbols_00594000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00682000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_01190000.h"
class TESGlobal;
class TESObjectREFR;
class TESForm;
class TESFile;
class Script;
class TESQuest;
struct ScriptReferencedObject;
struct ScriptVariableInfo;
struct ScriptLocals;
struct FunctionData
{
    union Parameter
    {
        float fValue;
        unsigned int m_uiFormID;
        void* pPointer;
    };
    unsigned short usFunction;
    Parameter uParam[2];
};
struct ConditionItemData
{
    signed char ucType;
    union Comparison
    {
        float fValue;
        TESGlobal* pGlobalForm;
    } uComparisonValue;
    FunctionData kFunctionData;
    unsigned int eRunOn;
    TESObjectREFR* m_pWorldReferenceInfo;
};
class TESConditionItem
{
  public:
    ConditionItemData kData;
    TESConditionItem* pNext;
    bool GetValueIsGlobal() const;
};
struct ParamInfo
{
    const char* typeStr;
    unsigned int typeID;
    unsigned int isOptional;
};
struct CommandInfo
{
    const char* longName;
    const char* shortName;
    unsigned int opcode;
    const char* helpText;
    unsigned short needsParent;
    unsigned short numParams;
    ParamInfo* params;
    void* execute;
    void* parse;
    void* eval;
    unsigned int flags;
};
struct ParamTypeInfo
{
    bool isTESForm;
    unsigned char pad[7];
};
extern ParamTypeInfo DAT_0118cdd5[];
struct ParamTypeMetadata
{
    unsigned int type;
    unsigned char pad[4];
};
extern const char DAT_01069608[];
extern const char DAT_010695a8[];
extern const char DAT_01069540[];
extern "C" void* __cdecl __RTDynamicCast(void* source, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
// Public community name, declared as the original PC command table.
class ScriptFunctionData
{
  public:
    static unsigned int GetParamCount(const FunctionData* apData);
    static bool IsParamTESForm(const FunctionData* apData, unsigned int auiParam);
    static void InitItem(TESForm* apForm, FunctionData* apData);
};
#endif
