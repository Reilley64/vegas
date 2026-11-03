// fallout_shared/tesscriptcompiler.cpp: ScriptCompiler, BGSCameraPath, S7f, S5a and more (36 functions)

#include <new>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00461700_shell.h"
#include "fnv/decl/FUN_00565730_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/LineCompiler.h"
#include "fnv/decl/ScriptInitOwner.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_005673c0__XActor.h"
#include "fnv/decl/fnv_005ac6a0__FUN_005ac6a0.h"
#include "fnv/decl/p07__DelStandIn.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005aa000.h"
#include "fnv/symbols_005ab000.h"
#include "fnv/symbols_005ae000.h"
#include "fnv/symbols_005af000.h"
#include "fnv/symbols_005b1000.h"
#include "fnv/symbols_005b3000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01186000.h"
#include "fnv/symbols_0118e000.h"
#include "fnv/symbols_01190000.h"
#include "fnv/symbols_011c3000.h"
#include "tesscriptcompiler_packet_decls.h"
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/ExpressionConverter.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_011de000.h"
#include <ctype.h>
#include "fnv/decl/TESContainer.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s55d310__Owner.h"
#include "fnv/symbols_004d5000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/symbols_01197000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011ca000.h"
#include <stdlib.h>

// If DAT_011c40c8 is clear, sets it true, reads GetEditorID(), resets it, and returns the name's length or 0 when there is no name.
// @fnv 0x00474cb0
int BGSCameraPath::HasNameForWarning()
{
    if (DAT_011c40c8)
        return 0;
    DAT_011c40c8 = true;
    const char* name = GetEditorID();
    DAT_011c40c8 = false;
    return name ? ::FUN_0044a670(name) : 0;
}

// @fnv 0x005b1120
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output)
{
    ScriptFunctionInfo* result = 0;
    if (output >= 0x100 && output < 0x1cd)
        result = &DAT_0118e8e0[output - 0x100];
    else if (output >= 0x1000 && output < 0x1280)
        result = (ScriptFunctionInfo*)&g_scriptCommands[output - 0x1000];
    return result;
}

struct ScriptReferencedObject;
struct ScriptVariableData;
struct Script;
struct ScriptToken;
struct CStringArgument
{
    bool GetVariable(ScriptVariableData*);
    ScriptReferencedObject* GetReferencedForm(unsigned int);
    bool GetReferencedForm(ScriptVariableData*, bool, bool);
    bool IsPartialScript();
    void* GetReferencedObjectList();
    void* GetVariableList();
    void ClearAllScriptLines();
    void ClearAllReferenceObjects();
    void ClearAllVariables();
    void* __vecDelDtor(unsigned int);
    char* input;
    unsigned int m_uiInputOffset;
    int m_eCompilerIndex;
    char m_kScriptName[8];
    int m_eErrorCode;
    bool m_bIsPartialScript;
    char _pad_19[3];
    unsigned int m_uiLastLineNumber;
    char* pOutput;
    unsigned int m_uiOutputOffset;
    char header[20];
    char m_kVariableList[8];
    char m_kReferencedObjectList[8];
    Script* m_pCurrentScript;
    char m_kLineList[8];
public:
    bool FUN_005afad0(::ScriptToken *, bool, bool);
};
struct FUN_00613790_shell : public CStringArgument
{
    void* FUN_00613790();
};

// @fnv 0x00613790
void* FUN_00613790_shell::FUN_00613790()
{
    return &m_kLineList;
}

struct S7f
{
    char pad[0x2a];
    unsigned char v;
    void SetValue(unsigned char a);
};
// @fnv 0x007f7c90
void S7f::SetValue(unsigned char aucValue)
{
    v = aucValue;
}

// Returns 1 if the string is a valid integer (optional leading '-', then digits only), otherwise 0.
// @fnv 0x004b1230
int IsIntegerString(const char* pcString)
{
    char c = *pcString;
    pcString++;
    if ((c >= '0' && c <= '9') || c == '-')
    {
        if (*pcString == 0 && c == '-')
            return 0;
        c = *pcString;
        pcString++;
        while (c != 0)
        {
            if (c < '0' || c > '9')
                return 0;
            c = *pcString;
            pcString++;
        }
        return 1;
    }
    return 0;
}

struct Interface
{
};
extern int DAT_011908f0;
extern int DAT_01196d18;
struct S5a
{
    S5a* ValidateScriptNameTables();
};
// @fnv 0x005aea50
S5a* S5a::ValidateScriptNameTables()
{
    if (DAT_01196d18 != 0x1280)
        ::FUN_0040fbe0();
    if (DAT_011908f0 != 0x1cd)
        ::FUN_0040fbe0();
    return this;
}

struct ScriptVariableData
{
    char m_auiShapeKeys[0x200];
    unsigned int m_uiVariableID;
    char m_cTypeCode;
    unsigned int m_uiReferenceID;
    unsigned int m_uiFormID;
    void* pForm;
    ScriptVariableData* Reset();
};

// Clears the object's fields and zeroes its 0x200-byte buffer, then returns this.
// @fnv 0x005af310
ScriptVariableData* ScriptVariableData::Reset()
{
    m_uiVariableID = 0;
    m_uiFormID = 0;
    m_cTypeCode = 0;
    m_uiReferenceID = 0;
    pForm = 0;
    memset(this, 0, 0x200);
    return this;
}


// @fnv 0x005afe10
void __cdecl FUN_005afe10(int aiArg1, int aiArg2, int aiArg3)
{
    std::strtoul((const char *)(aiArg1), (char **)(aiArg2), aiArg3);
}

// Advances *apOffset past tab, space and comma characters in apExpLine, stopping at the first other character.
// @fnv 0x005b1b60
void __cdecl FUN_005b1b60(const char* apExpLine, int* apOffset)
{
    for (;;)
    {
        switch (apExpLine[*apOffset])
        {
        case 9:
        case 0x20:
        case 0x2c:
            ++*apOffset;
            break;
        default:
            return;
        }
    }
}


// Calls FUN_005b3cd0 with the first four arguments and zero for the last two.
// @fnv 0x005b3c70
int __cdecl FUN_005b3c70(unsigned short arg1, void* arg2, void* arg3, void* arg4)
{
    return ((int)(::FUN_005b3cd0(arg1, (::MessageParameter_5b3c *)(arg2), (::ScriptLineBuffer *)(arg3), (::CompileMessageContext_5b3c *)(arg4), 0, 0)));
}


// @fnv 0x005b3c40
int __cdecl FUN_005b3c40(unsigned short param1, void* param2, void* param3, void* param4)
{
    return ((int)(::FUN_005b3cd0(param1, (::MessageParameter_5b3c *)(param2), (::ScriptLineBuffer *)(param3), (::CompileMessageContext_5b3c *)(param4), 1, 0)));
}


// Calls FUN_005b3cd0 with the given arguments plus 0 and 1, returning its result.
// @fnv 0x005b3ca0
int __cdecl FUN_005b3ca0(unsigned short arg1, void* arg2, void* arg3, void* arg4)
{
    return ((int)(::FUN_005b3cd0(arg1, (::MessageParameter_5b3c *)(arg2), (::ScriptLineBuffer *)(arg3), (::CompileMessageContext_5b3c *)(arg4), 0, 1)));
}

struct List
{
    bool _ref_008256d0();
    void _ref_0063f7b0();
};
struct TESDataHandler
{
    void ClearHairList();
};
// @fnv 0x005ae670
void TESDataHandler::ClearHairList()
{
    List* pList = ((::List *)(reinterpret_cast<::FUN_00613790_shell *>(this)->FUN_00613790()));
    while (pList && !pList->_ref_008256d0())
    {
        void* item = ((void *)(new ((void *)(pList)) ::Vec3()));
        ::FUN_00401030(item);
        pList->_ref_0063f7b0();
    }
}

struct FUN_005af370_shell
{
    unsigned int m_uiValueBeforeData;
    char m_data[0x200];
    unsigned int uiSize;
    unsigned int uiElapsedMilliseconds;
    char m_auiShapeKeys[0x40c - 0x20c];
    unsigned int m_uiValueAfterSecondBuffer;
    char m_pAuxiliaryObject[8];
    unsigned int m_uiTrailingValue;
    FUN_005af370_shell();
};

// @fnv 0x005af370
FUN_005af370_shell::FUN_005af370_shell()
{
    m_uiValueBeforeData = 0;
    uiSize = 0;
    uiElapsedMilliseconds = 0;
    m_uiValueAfterSecondBuffer = 0;
    m_uiTrailingValue = 0;
    memset(m_data, 0, 0x200);
    memset((char*)&this->m_auiShapeKeys, 0, 0x200);
}

namespace fnv_005afeb0 {
struct TaskQueueInterface
{
};
struct TESForm
{
    static TESForm* __cdecl LookupFormByEditorID(const char*);
};
struct ScriptVariableData
{
    char pText[512];
    char pad[24];
};
// @fnv 0x005afeb0
bool __cdecl FUN_005afeb0(const char* apVarName)
{
    if (!apVarName || !apVarName[0])
        return false;
    TESForm* pform = TESForm::LookupFormByEditorID(apVarName);
    if (pform)
        return false;
    ScriptVariableData checkword;
    reinterpret_cast<::ScriptVariableData *>(&(checkword))->Reset();
    ::TaskQueueInterface::CopyStringToBuffer(checkword.pText, 512, apVarName);
    if (::ResolveScriptCommand((::ScriptWordView *)(checkword.pText)))
        return false;
    return true;
}
}  // namespace fnv_005afeb0

namespace fnv_005aedb0 {
template <class T> class BSSimpleList;
struct ScriptReferencedObject;
class ShellH;
class Script
{
  public:
    char* GetText();
};
class ScriptS
{
  public:
};
class XActor
{
  public:
};
class TESObjectREFR
{
  public:
};
class BSStr
{
  public:
};
class Str6a70
{
  public:
    char* pString;
    unsigned short usLen, usMax;
    Str6a70& operator=(const char*);
};
extern const char* DAT_0118ca7c[];
enum COMPILER_NAME
{
    COMPILER_NAME_0,
    COMPILER_NAME_1
};

struct FUN_005ae490;
struct FUN_005ae5c0;
template <class A, class B> class ScriptCompileDataT
{
  public:
    char* pText;
    unsigned int uiElapsedMilliseconds;
    COMPILER_NAME m_eCompilerIndex;
    Str6a70 m_pName;
    unsigned int unk14;
    bool bPartial;
    unsigned int unk1C[3];
    unsigned int kHeader[5];
    unsigned int unk3C[2];
    unsigned int kRefObjects[2];
    Script* pScript;
    unsigned int unk50;
    ScriptCompileDataT();
    ~ScriptCompileDataT();
};
typedef ScriptCompileDataT<FUN_005ae490, FUN_005ae5c0> CStringArgument;

class ScriptCompiler
{
  public:
    bool FUN_005aeb90(Script*, CStringArgument*);
    bool FUN_005aedb0(Script* apScript, TESObjectREFR* apOwnerObject, COMPILER_NAME index, bool abOnLoad);
};

// Builds compile data from the script and optional owner object, sets the compiler name, then calls FUN_005aeb90 to compile the script.
// @fnv 0x005aedb0
bool ScriptCompiler::FUN_005aedb0(Script* apScript, TESObjectREFR* apOwnerObject, COMPILER_NAME eCompilerName,
                                  bool abOnLoad)
{
    bool bResult;
    CStringArgument compileData;
    compileData.m_eCompilerIndex = eCompilerName;
    compileData.bPartial = true;
    if (apOwnerObject && ((::fnv_005aedb0::Script *)(reinterpret_cast<::fnv_005673c0::XActor *>((apOwnerObject))->FUN_005673c0())))
    {
        compileData.pScript = ((::fnv_005aedb0::Script *)(reinterpret_cast<::fnv_005673c0::XActor *>((apOwnerObject))->FUN_005673c0()));
        ::__memcpy(compileData.kHeader, ((void *)(reinterpret_cast<::BGSCameraPath *>((((ScriptS*)compileData.pScript)))->GetConditions())), 0x14);
        ::CopyListToTail(
            (BSSimpleList<ScriptReferencedObject*>*)((::fnv_005aedb0::ShellH *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(((XActor*)compileData.pScript)))->FUN_005d43c0())),
            (::SoundListView *)(::fnv_005aedb0::BSSimpleList< ::fnv_005aedb0::ScriptReferencedObject *> *)((BSSimpleList<ScriptReferencedObject*>*)compileData.kRefObjects));
    }
    else
    {
        compileData.pScript = apScript;
    }
    if (eCompilerName == 1 || !((BGSCameraPath*)compileData.pScript)->HasNameForWarning())
        compileData.m_pName = DAT_0118ca7c[compileData.m_eCompilerIndex];
    else
        reinterpret_cast<::TextString *>((((BSStr*)&compileData.m_pName)))->FUN_004037f0(((BGSCameraPath*)compileData.pScript)->GetEditorID(), 0);
    compileData.pText = ((char *)(reinterpret_cast<::BGSMessageInitAccess *>((apScript))->GetIconFormID()));
    bResult = FUN_005aeb90(apScript, &compileData);
    return bResult;
}
}  // namespace fnv_005aedb0

struct BSStr
{
    unsigned char _padding[8];
};

struct StrMem : BSStr
{
    StrMem();
    ~StrMem();

    int _field08;
    unsigned char _field0c;
    int _field10;
    char* _field14;
    int _field18;
    unsigned char _field1c[0x14];
};

struct SL
{
    SL();
    ~SL();
    unsigned char _padding[8];
};

extern char $SG3295[];
extern int _data_011c16bc;

struct FUN_005ae490
{
    unsigned char _padding0[4];
    int _field04;
    int _field08;
    StrMem _field0c;
    SL _field3c;
    SL _field44;
    int _field4c;
    SL _field50;

    FUN_005ae490();
};

// @fnv 0x005ae490
FUN_005ae490::FUN_005ae490()
{
    _field0c._field10 = 0;
    _field04 = 0;
    _field0c._field18 = 0;

    _field0c._field14 = ::AllocateZeroed(1, 0x4000);
    memset(_field0c._field14, 0, 4);
    memset(_field0c._field1c, 0, 0x14);
    memset(_field0c._field14, 0, 4);

    _field08 = 0;
    _field0c._field0c = 0;
    _field4c = 0;

    reinterpret_cast<::TextString *>(&(_field0c))->FUN_004037f0($SG3295, 0);

    _field0c._field08 = 0;
}

namespace fnv_005ae5c0 {
struct TESDataHandler
{
    unsigned char padding[0x0C];
};

struct BSS
{
    unsigned char padding[0x14];
    ~BSS();
};

struct ListX
{
    unsigned char padding[8];
    ~ListX();
};

void ClearList(void* ptr);
void FUN_005ae730(void* ptr);

struct FUN_005ae5c0 : public TESDataHandler, public BSS
{
    char* pOutput;
    unsigned char padding[0x18];
    ListX list1;
    ListX list2;
    unsigned int value;
    ListX list3;

    ~FUN_005ae5c0();
};

// Runs TESDataHandler cleanup, calls two helper teardown routines on this, then deallocates pOutput.
// @fnv 0x005ae5c0
FUN_005ae5c0::~FUN_005ae5c0()
{
    reinterpret_cast<::TESDataHandler *>(this)->ClearHairList();
    ClearList(this);
    FUN_005ae730(this);
    ::FUN_00401030(pOutput);
}
}  // namespace fnv_005ae5c0

struct ScriptLineBuffer
{
    unsigned int m_uiValueBeforeData;
    char cLine[0x200];
    unsigned int uiSize;
    unsigned int uiElapsedMilliseconds;
    char cOutput[0x200];
    unsigned int m_uiValueAfterSecondBuffer;
    int unk410;
    int unk414;
    unsigned int m_uiTrailingValue;
};

struct ScriptSource
{
    char* pInput;
    unsigned int m_uiInputOffset;
};


// Reads one line from the script source into the line buffer, skipping comments and leading whitespace and trimming trailing spaces and tabs.
// @fnv 0x005af3f0
int __cdecl ReadScriptLine(ScriptSource* apData, ScriptLineBuffer* apBuffer)
{
    char* pText5 = apData->pInput + apData->m_uiInputOffset;
    int _iOffset = 0;
    bool bSkip = true;
    unsigned char cChar;
    for (;;)
    {
        cChar = pText5[_iOffset++];
        switch ((char)cChar)
        {
        case ';':
            while (cChar && cChar != '\n')
            {
                cChar = pText5[_iOffset++];
            }
        case '\r':
            if (cChar && pText5[_iOffset] == '\n')
            {
                _iOffset++;
            }
        case 0:
            if (!bSkip)
            {
                while (apBuffer->uiSize &&
                       (apBuffer->cLine[apBuffer->uiSize - 1] == ' ' || apBuffer->cLine[apBuffer->uiSize - 1] == '\t'))
                {
                    apBuffer->uiSize--;
                    apBuffer->cLine[apBuffer->uiSize] = 0;
                }
                if (apBuffer->uiSize)
                {
                    apBuffer->cLine[apBuffer->uiSize] = 0;
                    return _iOffset;
                }
            }
            else if (!cChar)
            {
                return 0;
            }
            apBuffer->m_uiValueBeforeData++;
            apBuffer->uiSize = 0;
            memset(apBuffer->cLine, 0, 0x200);
            break;
        default:
            if (apBuffer->uiSize + 1 >= 0x200)
            {
                ::ReportScriptError((::CStringArgument *)(apData), "Max script line length (%d characters) exceeded.", 0x200);
                apBuffer->m_uiTrailingValue = 0x10;
                return 0;
            }
            if (isalnum(cChar) || cChar == '"')
            {
                bSkip = false;
            }
            if (!bSkip)
            {
                apBuffer->cLine[apBuffer->uiSize] = cChar;
                apBuffer->uiSize++;
            }
            break;
        }
    }
}

struct Node_5afe30
{
    bool _ref_008256d0();
};

struct Cls_5afe30
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
    unsigned int count2c;
    void* GetNodeValue(unsigned int idx);
};

// Returns the value stored in the idx-th node of the list, or null if idx is 0 or exceeds count2c.
// @fnv 0x005afe30
void* Cls_5afe30::GetNodeValue(unsigned int uiIndex)
{
    if (uiIndex == 0)
        return 0;
    if (uiIndex > count2c)
        return 0;
    unsigned int uiPos = 1;
    Node_5afe30* p = ((::Node_5afe30 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (p && !p->_ref_008256d0() && uiPos < uiIndex)
    {
        ++uiPos;
        p = ((::Node_5afe30 *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
    }
    return *((void **)(new ((void *)(p)) ::Vec3()));
}

struct ScriptCommandView
{
    const char* longName;
    const char* shortName;
    unsigned int opcode;
    const char* helpText;
    unsigned int m_uiParameterCount;
    void* parameters;
    void* execute;
    void* parse;
    void* evaluate;
    void* reserved;
};
struct ScriptWordView
{
    char text[0x200];
    unsigned int referencedObjectIndex;
    char variableType;
    unsigned int functionCode;
};
extern ScriptCommandView DAT_0118cb50[];

// Matches word->text against the long or short names of three command tables and, on a hit, stores 'X' in variableType and the command opcode in functionCode.
// @fnv 0x005b1910
bool __cdecl ResolveScriptCommand(ScriptWordView* word)
{
    int index;
    for (index = 0; index < 16; ++index)
    {
        if (FUN_00404dc0(DAT_0118cb50[index].longName, word->text) == 0 ||
            FUN_00404dc0(DAT_0118cb50[index].shortName, word->text) == 0)
        {
            word->variableType = 'X';
            word->functionCode = DAT_0118cb50[index].opcode;
            return true;
        }
    }
    for (index = 0; index < 640; ++index)
    {
        if (FUN_00404dc0(word->text, reinterpret_cast<ScriptCommandView*>(g_scriptCommands)[index].longName) == 0 ||
            FUN_00404dc0(word->text, reinterpret_cast<ScriptCommandView*>(g_scriptCommands)[index].shortName) == 0)
        {
            word->variableType = 'X';
            word->functionCode = reinterpret_cast<ScriptCommandView*>(g_scriptCommands)[index].opcode;
            return true;
        }
    }
    for (index = 0; index < 205; ++index)
    {
        if (FUN_00404dc0(word->text, reinterpret_cast<ScriptCommandView*>(DAT_0118e8e0)[index].longName) == 0 ||
            FUN_00404dc0(word->text, reinterpret_cast<ScriptCommandView*>(DAT_0118e8e0)[index].shortName) == 0)
        {
            word->variableType = 'X';
            word->functionCode = reinterpret_cast<ScriptCommandView*>(DAT_0118e8e0)[index].opcode;
            return true;
        }
    }
    return false;
}

// Scans text from start to the null terminator, counting '(' and ')', and returns whether the final depth is zero.
// @fnv 0x005b1a90
bool __cdecl FUN_005b1a90(const char* text, unsigned int start)
{
    int depth_ = 0;
    unsigned int i = start;
    while (text[i] != 0)
    {
        switch (text[i])
        {
        case '(':
            depth_++;
            break;
        case ')':
            depth_--;
            break;
        }
        i++;
    }
    if (depth_ != 0)
    {
        return false;
    }
    return true;
}

// Counts double-quote characters in str from offset onward and returns true only if there are at least two and the count is even.
// @fnv 0x005b1b00
bool __cdecl HasBalancedQuotes(const char* pcString, int offset)
{
    int quoteCount = 0;
    int i = offset;
    while (pcString[i])
    {
        switch (pcString[i])
        {
        case '"':
            quoteCount++;
            break;
        }
        i++;
    }
    if (quoteCount < 2 || (quoteCount & 1))
        return false;
    return true;
}

struct FUN_005ae730_shell
{
    void FUN_005ae730();
};
struct HairObject
{
};
// Walks the list from FUN_005a8080 and, while the list is non-null and its check fails, calls DestroyAndFree(1) on each item and advances with FUN_0063f7b0.
// @fnv 0x005ae730
void FUN_005ae730_shell::FUN_005ae730()
{
    List* list = ((::List *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    while (list && !list->_ref_008256d0())
    {
        HairObject* object;
        void* item = ((void *)(new ((void *)(list)) ::Vec3()));
        object = static_cast<HairObject*>(item);
        object ? reinterpret_cast<::p07::DelStandIn *>((object))->DestroyAndFree_0061cb30(1) : 0;
        list->_ref_0063f7b0();
    }
}

struct ScriptRefHolder;
struct TESForm;
struct TESObjectREFR;
struct Target;
struct ListNode;
struct Item;


struct Mgr
{
};

void* __cdecl FUN_00ec43fb(void* obj, int vfdelta, void* src, void* dst, int isRef);

struct TESForm
{
    int FUN_00401170();
};

struct TESObjectREFR
{
};

struct Target
{
};

struct ListNode
{
};

struct Buf
{
};

struct Item
{
    int value;
    char unk04[0x0c];
    unsigned char flag;
    char unk11[7];
    Buf m_18;
};

struct ScriptRefHolder
{
    char unk00[0x200];
    int m_200;
    signed char m_204;
    char unk205[7];
    int m_20c;
    TESForm* m_210;
};

struct CompilerCtx
{
    char unk00[0x4c];
    Target* m_4c;

    bool ResolveReference(ScriptRefHolder* p);
};

// Resolves p's form to a Target and fills m_204/m_20c, falling back to scanning list items and m_4c, returning whether a match was found.
// @fnv 0x005ae7a0
bool CompilerCtx::ResolveReference(ScriptRefHolder* apRef)
{
    ListNode* cur;
    int idx;
    TESObjectREFR* r2;
    Target* t5;
    Item* item;
    char cA;

    idx = ((int)(::FUN_0044a670((const char *)(apRef))));
    if (apRef->m_210 != 0)
    {
        t5 = 0;
        r2 = (TESObjectREFR*)FUN_00ec43fb(apRef->m_210, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), (*reinterpret_cast<char (*)[]>(&::DAT_011841cc)), 0);
        if (r2 != 0)
        {
            reinterpret_cast<::FUN_00565730_shell *>((r2))->FUN_00565730();
            t5 = ((::Target *)(reinterpret_cast<::fnv_005673c0::XActor *>((r2))->FUN_005673c0()));
        }
        else
        {
            if (apRef->m_210 != 0)
            {
                if (apRef->m_210->FUN_00401170() == 0x47)
                {
                    t5 = ((::Target *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(apRef->m_210))));
                }
            }
        }
        if (t5 == 0)
        {
            apRef->m_20c = 0;
            return false;
        }
        apRef->m_204 = ((bool)(reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((t5))->Method_005ac6a0((const char *)(apRef), (unsigned int *)(int *)(&apRef->m_20c))));
        if (apRef->m_204 == 0)
        {
            apRef->m_20c = 0;
            return false;
        }
        return true;
    }
    else
    {
        if (apRef->m_200 != 0)
        {
            apRef->m_20c = 0;
            apRef->m_204 = 0;
            return false;
        }
    }

    cur = ((::ListNode *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    apRef->m_20c = 0;
    while (cur != 0 && ((void *)(new ((void *)(cur)) ::Vec3())) != 0)
    {
        item = (Item*)((void *)(new ((void *)(cur)) ::Vec3()));
        if (fnv::crt::strnicmp(((char *)(::FUN_00559450((int *)&(item->m_18)))), (const char *)(apRef), idx) == 0)
        {
            cA = ((char *)(::FUN_00559450((int *)&(item->m_18))))[idx];
            if (std::isalnum(cA) == 0 && cA != '-' && cA != '_')
            {
                if (item->flag != 0)
                {
                    apRef->m_204 = 's';
                }
                else
                {
                    apRef->m_204 = 'f';
                }
                apRef->m_20c = item->value;
                return true;
            }
        }
        cur = ((::ListNode *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }

    if (m_4c != 0)
    {
        apRef->m_204 = ((bool)(reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((m_4c))->Method_005ac6a0((const char *)(apRef), (unsigned int *)(int *)(&apRef->m_20c))));
        if (apRef->m_204)
        {
            return true;
        }
    }

    if (((void *)(reinterpret_cast<::FUN_00461700_shell *>(((*reinterpret_cast<::Mgr * *>(&::g_dataHandler))))->FindFormByEditorID((const char *)(apRef)))) != 0)
    {
        if (reinterpret_cast<::CStringArgument *>(this)->FUN_005afad0((::ScriptToken *)(apRef), 0, 0))
        {
            apRef->m_20c = 0;
            apRef->m_204 = 'G';
            return true;
        }
    }
    apRef->m_20c = 0;
    apRef->m_204 = 0;
    return false;
}

struct StrBuf8
{
    StrBuf8();
    ~StrBuf8();
    char* GetText();
    int _field00;
    int _field04;
};

struct ScriptNameRef
{
};


// @fnv 0x005aea90
void __cdecl ReportScriptError(CStringArgument* self, const char* pcFormat, ...)
{
    void* args = (char*)&pcFormat + sizeof(pcFormat);
    char msg[0x108];
    ::FUN_00407000(msg, pcFormat, (char *)(args));
    args = 0;
    StrBuf8 strBuf;
    ::FUN_00406f60((::FUN_00406f90_this *)(::StrBuf8 *)(&strBuf), "SCRIPTS: Script '%s', line %d:\n%s", ((char *)(::FUN_00559450((int *)(((ScriptNameRef*)&self->m_kScriptName))))),
                 self->m_uiLastLineNumber, msg);
    if (self->m_eCompilerIndex == 1)
    {
        ::FUN_00703c00((const char *)(::FUN_00464f30((int)(((char *)(::FUN_00559450((int *)&(strBuf))))))), {});
    }
    else
    {
        ::FUN_005b5e40(::FUN_00464f30(strBuf))));
    }
}

static const char scriptNameError[] = "You need to start scripts with \"scriptname ScriptName\"";

struct ScriptHeaderView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int variableCount;
    unsigned char scriptType;
    unsigned char flags;
};
struct Script
{
};
struct ScriptCompiler
{
    bool FUN_005aeb90(Script* script, FUN_00613790_shell* data);
};
struct Word95
{
    char text[512];
    unsigned int reference;
    char kind;
    int code;
    int variable;
    void* form;
    Word95();
};
struct Line95
{
    unsigned int number;
    char input[512];
    unsigned int size;
    unsigned int cursor;
    char output[512];
    unsigned int outputSize;
    int code;
    unsigned int reference;
    int error;
    Line95();
};
struct Queue95
{
};
struct Name95
{
    int value;
    int length;
};
struct Compile95
{
    const char* input;
    unsigned int offset;
    int compiler;
    Name95 name;
    int error;
    int unk18;
    unsigned int line;
};
struct Parser95
{
    int ParseLine(Compile95*);
};
// @fnv 0x005aeed0
int Parser95::ParseLine(Compile95* pCompile)
{
    if (pCompile->offset >= std::strlen(pCompile->input))
        return 65535;
    Line95* line8 = new Line95;
    line8->number = pCompile->line + 1;
    int consumed38 = ::ReadScriptLine((::ScriptSource *)(pCompile), (::ScriptLineBuffer *)(line8));
    if (!consumed38)
    {
        pCompile->error = line8->error;
        delete line8;
        return 65535;
    }
    pCompile->offset += consumed38;
    Word95 word26;
    int parsed2 = ::FUN_005af5f0((::CompilerShell *)(pCompile), (::ScriptVariableData *)(::Word95 *)(&word26), (char *)(line8->input), (int *)(unsigned int *)(&line8->cursor), 1, 1);
    if (!parsed2)
    {
        ::ReportScriptError((::CStringArgument *)(pCompile), "Syntax Error\r\n%s\r\nCould not parse this line.", line8->input);
        delete line8;
        return 65535;
    }
    line8->reference = word26.reference;
    bool valid46 = word26.kind == 'X';
    if (valid46)
    {
        if (word26.code >= 256 && word26.code < 461 && pCompile->compiler != 1)
        {
            valid46 = false;
            ::ReportScriptError((::CStringArgument *)(pCompile), "Script command \"%s\" is a console-only command.", word26.text);
        }
    }
    else
    {
        ++pCompile->line;
        ::ReportScriptError((::CStringArgument *)(pCompile), "Script command \"%s\" not found.", word26.text);
        pCompile->error = 13;
    }
    if (valid46)
    {
        line8->code = word26.code;
        ::TaskQueueInterface::CopyStringToBuffer(line8->input, 512, line8->input + line8->cursor);
        line8->size -= line8->cursor;
        pCompile->line = line8->number;
        if (line8->code == 29)
        {
            unsigned int cursor33 = 0;
            Word95 name21;
            if (::FUN_005af5f0((::CompilerShell *)(pCompile), (::ScriptVariableData *)(::Word95 *)(&name21), (char *)(line8->input), (int *)(unsigned int *)(&cursor33), 0, 0))
                reinterpret_cast<::TextString *>(&(pCompile->name))->FUN_004037f0(name21.text, 0);
            else
            {
                ::ReportScriptError((::CStringArgument *)(pCompile), "Syntax Error.  Missing script name.");
                pCompile->error = 1;
                delete line8;
                return 65535;
            }
        }
        if ((line8->code == 22 || line8->code == 24) && !line8->input[0])
        {
            ::ReportScriptError((::CStringArgument *)(pCompile), "Syntax Error.  No condition specified for 'if' or 'elseif'.");
            pCompile->error = 6;
            delete line8;
            return 65535;
        }
        reinterpret_cast<::Callees *>((((::Queue95 *)(reinterpret_cast<::FUN_00613790_shell *>((pCompile))->FUN_00613790()))))->FUN_00905820(&line8);
        return line8->code;
    }
    else
    {
        delete line8;
        return 65535;
    }
}

struct LineListNode
{
    bool IsEmpty();
    ScriptLineBuffer*& Item();
};


struct ScriptBlockScanner
{
    int ScanBlockLines(CStringArgument* apData, unsigned int* apStartLine);
};

// Counts lines until the if/else/endif block starting after *apStartLine closes.
// @fnv 0x005b13e0
int ScriptBlockScanner::ScanBlockLines(CStringArgument* apData, unsigned int* apStartLine)
{
    int iCount8 = 0;
    int iDepthA = 0;
    int eType4;
    LineListNode* pNodeX;
    ScriptLineBuffer* pLine;
    int bFound = 0;

    pNodeX = (LineListNode*)reinterpret_cast<::FUN_00613790_shell *>((apData))->FUN_00613790();
    while (pNodeX && !pNodeX->IsEmpty() && !bFound)
    {
        pLine = ((::ScriptLineBuffer *)(new ((void *)(pNodeX)) ::Vec3()));
        if (pLine->m_uiValueBeforeData > *apStartLine)
        {
            eType4 = pLine->unk410;
            switch (eType4)
            {
            case 0xffff:
                ::ReportScriptError(apData, "Mismatched if/else/endif.");
                return -1;
            case 0x12:
            case 0x13:
            case 0x14:
                break;
            case 0x16:
                ++iCount8;
                ++iDepthA;
                if (iDepthA >= 10)
                {
                    ::ReportScriptError(apData, "Max nesting of %d exceeded.", 10);
                    return -1;
                }
                break;
            case 0x17:
            case 0x18:
                if (iDepthA == 0)
                    bFound = 1;
                else
                    ++iCount8;
                break;
            case 0x19:
                if (iDepthA == 0)
                {
                    bFound = 1;
                }
                else
                {
                    --iDepthA;
                    ++iCount8;
                }
                break;
            default:
                ++iCount8;
                break;
            }
        }
        pNodeX = ((::LineListNode *)(reinterpret_cast<::Callees *>((pNodeX))->FUN_00726070()));
    }

    if (!bFound)
    {
        ::ReportScriptError(apData, "Mismatched if/else/endif block starting on line %d.", *apStartLine);
        return -1;
    }
    return iCount8;
}

// CRT isalnum in the game image

typedef bool(__cdecl* ScriptParseFunctionB15)(unsigned short usParamCount, void* pParams,
                                              FUN_005af370_shell* pkLineBuffer, CStringArgument* pkData);

struct ScriptFunctionB15
{
    const char* pFunctionName;
    const char* m_pShortName;
    unsigned int m_eOutputType;
    const char* m_pDescription;
    bool m_bRequiresReference;
    unsigned short usParamCount;
    void* pParameters;
    void* m_pfnExecute;
    ScriptParseFunctionB15 m_pfnCompile;
};


struct FUN_005b1570_Class
{
    int CompileScriptLine(CStringArgument* pkData, unsigned int* puiLineNumber, char* pInput, char* pOutput);
};

// @fnv 0x005b1570
int FUN_005b1570_Class::CompileScriptLine(CStringArgument* pkData, unsigned int* puiLineNumber, char* pInput,
                                          char* pOutput)
{
    unsigned int uiIndex;
    unsigned int uiOutOffset;
    unsigned int uiLength;

    uiLength = ::FUN_0044a670(pInput);
    uiOutOffset = 0;
    for (uiIndex = 0; uiIndex < uiLength; uiIndex++)
    {
        if (std::isalpha(pInput[uiIndex]) || pInput[uiIndex] == '"')
        {
            ScriptVariableData kWord;
            kWord.Reset();
            if (!::FUN_005af5f0((::CompilerShell *)(pkData), &kWord, pInput, (int *)(unsigned int *)(&uiIndex), 1, 1))
                return 0;

            if (kWord.m_uiVariableID > 0)
            {
                if (kWord.m_cTypeCode == 'G')
                {
                    pOutput[uiOutOffset] = 'G';
                    uiOutOffset++;
                }
                else
                {
                    pOutput[uiOutOffset] = 'r';
                    uiOutOffset++;
                }
                *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiVariableID;
                uiOutOffset += 2;
            }

            if (kWord.m_uiFormID > 0)
            {
                pOutput[uiOutOffset] = kWord.m_cTypeCode;
                uiOutOffset++;
                *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiFormID;
                uiOutOffset += 2;
            }
            else if (kWord.m_cTypeCode == 'X')
            {
                pOutput[uiOutOffset] = 'X';
                uiOutOffset++;
                *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiReferenceID;
                uiOutOffset += 2;

                ScriptFunctionB15* pkFunction = ((::ScriptFunctionB15 *)(::GetFunctionByOpcode((::SCRIPT_OUTPUT)(kWord.m_uiReferenceID))));
                if (!pkFunction)
                {
                    ::ReportScriptError((::CStringArgument *)(::ScriptSource *)((ScriptSource*)pkData), "Syntax Error.  Undefined function '%s'.", &kWord);
                    return 0;
                }
                else if (pkFunction->m_bRequiresReference && *(bool*)&pkData->header[0x10] && kWord.m_uiVariableID == 0)
                {
                    ::ReportScriptError((::CStringArgument *)(::ScriptSource *)((ScriptSource*)pkData),
                                       "Reference function '%s' requires explicit reference in quest script.", &kWord);
                    return 0;
                }

                if (pkFunction->pParameters)
                {
                    void* pParams = pkFunction->pParameters;
                    ScriptParseFunctionB15 pfnCompile = pkFunction->m_pfnCompile;
                    unsigned short usParamCount = pkFunction->usParamCount;
                    FUN_005af370_shell kLineBuffer;
                    ::TaskQueueInterface::CopyStringToBuffer(kLineBuffer.m_data, 0x200, pInput + uiIndex);
                    kLineBuffer.m_uiValueAfterSecondBuffer = 0;
                    kLineBuffer.m_uiValueBeforeData = *puiLineNumber;
                    if (!pfnCompile(usParamCount, pParams, &kLineBuffer, pkData))
                        return 0;
                    *(unsigned short*)(pOutput + uiOutOffset) = kLineBuffer.m_uiValueAfterSecondBuffer;
                    uiOutOffset += 2;
                    __memcpy(pOutput + uiOutOffset, kLineBuffer.m_auiShapeKeys, kLineBuffer.m_uiValueAfterSecondBuffer);
                    uiOutOffset += kLineBuffer.m_uiValueAfterSecondBuffer;
                    uiIndex += kLineBuffer.uiElapsedMilliseconds;
                }
                else
                {
                    *(unsigned short*)(pOutput + uiOutOffset) = 0;
                    uiOutOffset += 2;
                }
            }
            else if (kWord.m_cTypeCode != 'G')
            {
                if (kWord.m_uiVariableID == 0 && pkData->FUN_005afad0((::ScriptToken *)(::ScriptVariableData *)(&kWord), false, false))
                {
                    pOutput[uiOutOffset] = 'Z';
                    uiOutOffset++;
                    *(unsigned short*)(pOutput + uiOutOffset) = kWord.m_uiVariableID;
                    uiOutOffset += 2;
                }
                else
                {
                    ::ReportScriptError((::CStringArgument *)(::ScriptSource *)((ScriptSource*)pkData), "Syntax Error.  Unknown command '%s'.", &kWord);
                    return 0;
                }
            }
        }

        if (uiIndex < uiLength)
        {
            pOutput[uiOutOffset] = pInput[uiIndex];
            uiOutOffset++;
        }
    }

    pOutput[uiOutOffset + 1] = 0;
    return uiOutOffset;
}

struct ScriptLineS
{
    unsigned int m_uiLineNumber;
    char padCur[0x40c];
    unsigned int m_uiType;
};
struct ScriptLineNode
{
};
bool FUN_008256d0(ScriptLineNode* pkNode);
struct ScriptBufferS
{
    char pad[0x1c];
    unsigned int m_uiCurrentLine;
};
struct FUN_005b1180_shell
{
    bool FUN_005b1180(ScriptBufferS* pkBuffer);
};
// @fnv 0x005aeb90
bool ScriptCompiler::FUN_005aeb90(Script* script, FUN_00613790_shell* pSource)
{
    if (!script || !pSource)
        return false;
    ((S7f*)script)->SetValue(0);
    Node_5afe30* buffer = 0;
    Node_5afe30* previous = 0;
    unsigned int opcode = 0xffff;
    ((ScriptHeaderView*)pSource->header)->scriptType = ((::ScriptHeaderView *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->scriptType;
    ((ScriptHeaderView*)pSource->header)->flags = ((::ScriptHeaderView *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->flags;
    ((ScriptHeaderView*)pSource->header)->variableCount = ((::ScriptHeaderView *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->variableCount;
    if (pSource->input)
    {
        do
        {
            opcode = ((unsigned int)(reinterpret_cast<::Parser95 *>(this)->ParseLine((::Compile95 *)(pSource))));
        } while (opcode != 0xffff);
        if (pSource->m_eErrorCode > 0)
            return false;
        pSource->m_uiLastLineNumber = 0;
        if (!pSource->m_bIsPartialScript)
        {
            buffer = (Node_5afe30*)pSource->FUN_00613790();
            if (!buffer || (buffer && buffer->_ref_008256d0()))
            {
                ::ReportScriptError((::CStringArgument *)(::ScriptSource *)((ScriptSource*)pSource), scriptNameError);
                return false;
            }
            ScriptLineBuffer* first = (ScriptLineBuffer*)*((void **)(new ((void *)(buffer)) ::Vec3()));
            opcode = first->unk410;
            if (opcode == 0xffff)
            {
                return false;
            }
            else if (opcode != 0x1d)
            {
                ::ReportScriptError((::CStringArgument *)(::ScriptSource *)((ScriptSource*)pSource), scriptNameError);
                return false;
            }
            if (!reinterpret_cast<::FUN_005b1180_shell *>(this)->FUN_005b1180((::ScriptBufferS *)(pSource)))
                return false;
        }
    }
    buffer = (Node_5afe30*)pSource->FUN_00613790();
    ScriptLineBuffer* currentLine = 0;
    while (buffer && !buffer->_ref_008256d0())
    {
        currentLine = (ScriptLineBuffer*)*((void **)(new ((void *)(buffer)) ::Vec3()));
        opcode = currentLine->unk410;
        pSource->m_uiLastLineNumber = currentLine->m_uiValueBeforeData;
        if (!reinterpret_cast<::LineCompiler *>(this)->FUN_005aff40((::CompileScript *)(script), (::CompileState *)(pSource), (::CompileLine *)(currentLine)))
            return false;
        previous = buffer;
        buffer = ((::Node_5afe30 *)(reinterpret_cast<::Callees *>((buffer))->FUN_00726070()));
    }
    ((ScriptHeaderView*)pSource->header)->unk08 = pSource->m_uiOutputOffset;
    if (!pSource->IsPartialScript())
        return false;
    reinterpret_cast<::ScriptInitOwner *>((script))->InitFromCompileData(pSource);
    ((S7f*)script)->SetValue(1);
    return true;
}
// @fnv 0x005b1180
bool FUN_005b1180_shell::FUN_005b1180(ScriptBufferS* pkBuffer)
{
    unsigned int uiType5;
    bool bInBlock = false;
    ScriptLineNode* pIterCur = ((::ScriptLineNode *)(reinterpret_cast<::FUN_00613790_shell *>((pkBuffer))->FUN_00613790()));
    while (pIterCur && !FUN_008256d0(pIterCur))
    {
        ScriptLineS* pkLine = ((::ScriptLineS *)(new ((void *)(pIterCur)) ::Vec3()));
        uiType5 = pkLine->m_uiType;
        switch (uiType5)
        {
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x1d:
        case 0x1f:
            break;
        case 0x10:
            if (bInBlock)
            {
                pkBuffer->m_uiCurrentLine = pkLine->m_uiLineNumber;
                ::ReportScriptError((::CStringArgument *)(pkBuffer), "Nested begin/end blocks are not allowed.");
                return false;
            }
            else
            {
                bInBlock = true;
            }
            break;
        case 0x11:
            if (!bInBlock)
            {
                pkBuffer->m_uiCurrentLine = pkLine->m_uiLineNumber;
                ::ReportScriptError((::CStringArgument *)(pkBuffer), "End without matching Begin.");
                return false;
            }
            else
            {
                bInBlock = false;
            }
            break;
        default:
            if (!bInBlock)
            {
                pkBuffer->m_uiCurrentLine = pkLine->m_uiLineNumber;
                ::ReportScriptError((::CStringArgument *)(pkBuffer), "All script commands must be inside a begin/end block.");
                return false;
            }
            break;
        }
        pIterCur = ((::ScriptLineNode *)(reinterpret_cast<::Callees *>((pIterCur))->FUN_00726070()));
    }
    return true;
}

namespace fnv_005b12c0 {
struct ScriptLine
{
    unsigned int m_uiValueBeforeData;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
};

struct LineNode
{
    bool FUN_008256d0();
};

struct CStringArgument
{
};


struct FUN_005b12c0_owner
{
    int CountLinesInBeginBlock(CStringArgument* apData, unsigned int* apLineNumber);
};

// @fnv 0x005b12c0
int FUN_005b12c0_owner::CountLinesInBeginBlock(CStringArgument* apData, unsigned int* apLineNumber)
{
    int count = 0;
    int type;
    int done = 0;
    LineNode* node5 = ((::fnv_005b12c0::LineNode *)(reinterpret_cast<::FUN_00613790_shell *>((apData))->FUN_00613790()));
    ScriptLine* line6;
    while (node5 && !node5->FUN_008256d0() && !done)
    {
        line6 = *((::fnv_005b12c0::ScriptLine **)(new ((void *)(node5)) ::Vec3()));
        if (line6->m_uiValueBeforeData > *apLineNumber)
        {
            type = line6->unk410;
            switch (type)
            {
            case 0xffff:
                ::ReportScriptError((::CStringArgument *)(apData), "Begin without matching end starting on line %d.", *apLineNumber);
                return -1;
            case 18:
            case 19:
            case 20:
                break;
            case 16:
                ::ReportScriptError((::CStringArgument *)(apData), "Nested begin/end blocks are not allowed.");
                return -1;
            case 17:
                done = 1;
                break;
            default:
                count++;
                break;
            }
        }
        node5 = ((::fnv_005b12c0::LineNode *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
    }
    if (!done)
    {
        ::ReportScriptError((::CStringArgument *)(apData), "Mismatched begin/end block starting on line %d.", *apLineNumber);
        return -1;
    }
    return count;
}
}  // namespace fnv_005b12c0

class Item5AE6C0
{
  public:
    ~Item5AE6C0();
    int unk00;
};
class List5AE6C0
{
  public:
    Item5AE6C0* m_item;
    List5AE6C0* m_pkNext;
    bool IsEmpty();
    void RemoveHead();
};
class Owner5AE6C0
{
  public:
    void ClearList();
};

// Deletes each head item, then removes that head, until the list is empty.
// @fnv 0x005ae6c0
void Owner5AE6C0::ClearList()
{
    List5AE6C0* pkList = ((::List5AE6C0 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (pkList && !pkList->IsEmpty())
    {
        delete ((::Item5AE6C0 *)(new ((void *)(pkList)) ::Vec3()));
        pkList->RemoveHead();
    }
}

void __cdecl ReportScriptError(CStringArgument* a, const char* fmt, ...);
extern "C" void* _FNV_DynamicCast(void* obj, int a, void* src, void* dst, int b);
struct ScriptFuncDef
{
    int field00;
    int field04;
    BGSCameraPath* pForm;
};
struct CompilerShell : public CStringArgument
{
};
// Parses a quoted string or identifier from apExpLine into apWord, resolving references or script commands when aAllowRef is set.
// @fnv 0x005af5f0
int __cdecl FUN_005af5f0(CompilerShell* aCompiler, ScriptVariableData* apWord, char* apExpLine, int* apOffset,
                         bool aAllowRef, bool aFlag5)
{
    FUN_005b1b60(apExpLine, apOffset);
    int len = 0;
    if (apExpLine[*apOffset] == '"')
    {
        if (!HasBalancedQuotes(apExpLine, *apOffset))
        {
            ReportScriptError((CStringArgument*)aCompiler, "Syntax Error.  Mismatched quotes.");
            return 0;
        }
        char* pEnd;
        char* pStart;
        pStart = strchr(apExpLine + *apOffset, '"');
        *pStart = ' ';
        pEnd = strchr(apExpLine + *apOffset, '"');
        *pEnd = 0;
        ::TaskQueueInterface::CopyStringToBuffer((char*)apWord, 0x200, pStart + 1);
        len = ::FUN_0044a670((const char*)apWord);
        *pStart = '"';
        *pEnd = '"';
        *apOffset = len + *apOffset + 2;
        if (apExpLine[*apOffset] == '.')
        {
            if (!aAllowRef)
            {
                ReportScriptError((CStringArgument*)aCompiler,
                                  "Syntax Error.  Reference not allowed in this context.");
                return 0;
            }
            if (apWord->m_uiVariableID > 0)
            {
                ReportScriptError((CStringArgument*)aCompiler, "Syntax Error.  Invalid reference syntax.");
                return 0;
            }
            *apOffset = *apOffset + 1;
            if (!reinterpret_cast<::CStringArgument *>((aCompiler))->FUN_005afad0((::ScriptToken *)(apWord), 0, aFlag5))
            {
                ReportScriptError((CStringArgument*)aCompiler, "Unknown object '%s'.", apWord);
                return 0;
            }
            return FUN_005af5f0(aCompiler, apWord, apExpLine, apOffset, true, aFlag5);
        }
        ((char*)apWord)[len] = 0;
    }
    if (len == 0)
    {
        while (isalnum(apExpLine[*apOffset]) || apExpLine[*apOffset] == '.' || apExpLine[*apOffset] == '-' ||
               apExpLine[*apOffset] == '_')
        {
            {
                ((char*)apWord)[len] = apExpLine[*apOffset];
                len = len + 1;
                *apOffset = *apOffset + 1;
                if (((char*)apWord)[len - 1] == '.')
                {
                    if (isalpha(((char*)apWord)[0]))
                    {
                        if (!aAllowRef)
                        {
                            ReportScriptError((CStringArgument*)aCompiler,
                                              "Syntax Error.  Reference not allowed in this context.");
                            return 0;
                        }
                        if (apWord->m_uiVariableID != 0)
                        {
                            ReportScriptError((CStringArgument*)aCompiler,
                                              "Syntax Error.  Invalid reference syntax.");
                            return 0;
                        }
                        ((char*)apWord)[len - 1] = 0;
                        if (!reinterpret_cast<::CStringArgument *>((aCompiler))->FUN_005afad0((::ScriptToken *)(apWord), 0, aFlag5))
                        {
                            ReportScriptError((CStringArgument*)aCompiler, "Unknown object '%s'.", apWord);
                            return 0;
                        }
                        return FUN_005af5f0(aCompiler, apWord, apExpLine, apOffset, true, aFlag5);
                    }
                }
                ((char*)apWord)[len] = 0;
            }
        }
    }
    if (aAllowRef)
    {
        if (apWord->m_uiVariableID > 0)
        {
            if (!reinterpret_cast<::CompilerCtx *>((aCompiler))->ResolveReference((::ScriptRefHolder *)(apWord)) && !((unsigned char)(::ResolveScriptCommand((::ScriptWordView *)(apWord)))))
            {
                ReportScriptError((CStringArgument*)aCompiler, "Unknown variable or function '%s'.", apWord);
                return 0;
            }
            ScriptFuncDef* pScriptFunction = ((::ScriptFuncDef *)(reinterpret_cast<::Cls_5afe30 *>((aCompiler))->GetNodeValue(apWord->m_uiVariableID)));
            void* castA;
            void* castB;
            castB = _FNV_DynamicCast(pScriptFunction->pForm, 0, &(*reinterpret_cast<char (*)[]>(&::DAT_01183028)), &(*reinterpret_cast<char (*)[]>(&::DAT_011841cc)), 0);
            castA = _FNV_DynamicCast(pScriptFunction->pForm, 0, &(*reinterpret_cast<char (*)[]>(&::DAT_01183028)), &DAT_01186500, 0);
            if (castB == 0 && castA == 0 && !aFlag5)
            {
                ReportScriptError(
                    (CStringArgument*)aCompiler,
                    "Syntax error.  Invalid reference '%s' (only quests and object references are allowed in this context).",
                    pScriptFunction->pForm->GetEditorID());
                return 0;
            }
            if (castA != 0)
            {
                if (apWord->m_cTypeCode == 'X')
                {
                    ReportScriptError((CStringArgument*)aCompiler,
                                      "Syntax error.  Functions may not be called on quests.");
                    return 0;
                }
            }
        }
        if (apWord->m_cTypeCode == 0 && !reinterpret_cast<::CompilerCtx *>((aCompiler))->ResolveReference((::ScriptRefHolder *)(apWord)))
        {
            ::ResolveScriptCommand((::ScriptWordView *)(apWord));
        }
    }
    return len;
}

namespace fnv_005afa50 {
struct FUN_005afa50_list
{
};

struct CStringArgument
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    FUN_005afa50_list m_kReferencedObjectList;
};

struct FUN_005afa50_shell : public CStringArgument
{
    bool FUN_005afa50();
};

struct FUN_005afa50_obj
{
    unsigned char _pad0[8];
    unsigned int m_08;
    unsigned int m_0c;
};


// Walks m_kReferencedObjectList and returns false, logging via FUN_005aea90, if any item has both m_08 and m_0c zero.
// @fnv 0x005afa50
bool FUN_005afa50_shell::FUN_005afa50()
{
    FUN_005afa50_list* list = &m_kReferencedObjectList;
    while (list != 0 && ((void *)(new ((void *)(list)) ::Vec3())) != 0)
    {
        FUN_005afa50_obj* item = (FUN_005afa50_obj*)((void *)(new ((void *)(list)) ::Vec3()));
        list = ((::fnv_005afa50::FUN_005afa50_list *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        if (item->m_08 == 0 && item->m_0c == 0)
        {
            ::ReportScriptError((::CStringArgument *)(void *)(this), "Unknown referenced object '%s'.", ((char *)(::FUN_00559450((int *)(item)))));
            return false;
        }
    }
    return true;
}
}  // namespace fnv_005afa50

#include <stdlib.h>
int __cdecl IsIntegerString(const char*);

namespace MsgCompileData {
extern "C" char DAT_01186130[];
}
struct MessageDescription_5b3c
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual char* GetText(void*, unsigned int);
};
class BGSMessage_5b3c : public TESForm
{
  public:
    unsigned int virtualTable00;
    int flags04, flags08, flags0c, flags10, flags14, flags18, flags1c, flags20;
    MessageDescription_5b3c description;
};
struct MessageParseWord_5b3c
{
    char text[0x200];
    unsigned int reference;
    char type;
    unsigned int function;
    unsigned int variable;
    TESForm* form;
};
struct MessageArrayWord_5b3c : MessageParseWord_5b3c
{
    MessageArrayWord_5b3c();
};
struct MessageParameter_5b3c
{
    char* name;
};
struct CompileMessageContext_5b3c
{
};

// Parses and compiles a MessageBox script line into binary output, handling literal text, parameters, variables, buttons, and duration.
// @fnv 0x005b3cd0
bool __cdecl FUN_005b3cd0(unsigned short opcode, MessageParameter_5b3c* apParameter, ScriptLineBuffer* line,
                          CompileMessageContext_5b3c* context, bool hasButtons, bool literal)
{
    int size;
    {
        MessageParseWord_5b3c message;
        {
            BGSMessage_5b3c* form;
            {
                unsigned short version;
                {
                    int count;
                    {
                        char* text;
                        {
                            char* output;
                            line->uiElapsedMilliseconds = 0;
                            version = 1;
                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = version;
                            line->m_uiValueAfterSecondBuffer += 2;
                            reinterpret_cast<::ScriptVariableData *>(&(message))->Reset();
                            form = 0;
                            size = 0;
                            if (literal)
                            {
                                size = ::FUN_005af5f0((::CompilerShell *)(context), (::ScriptVariableData *)(::MessageParseWord_5b3c *)(&message), line->cLine, (int *)(unsigned int *)(&line->uiElapsedMilliseconds), false,
                                                    false);
                                if (!size)
                                {
                                    ::ReportScriptError((::CStringArgument *)(context), "No message text.");
                                    return false;
                                }
                                *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] =
                                    (unsigned short)size;
                                line->m_uiValueAfterSecondBuffer += 2;
                                ::__memcpy(&line->cOutput[line->m_uiValueAfterSecondBuffer], &message, size);
                                line->m_uiValueAfterSecondBuffer += size;
                            }
                            else
                            {
                                MessageParseWord_5b3c word;
                                reinterpret_cast<::ScriptVariableData *>(&(word))->Reset();
                                size = ::FUN_005af5f0((::CompilerShell *)(context), (::ScriptVariableData *)(::MessageParseWord_5b3c *)(&word), line->cLine, (int *)(unsigned int *)(&line->uiElapsedMilliseconds), false,
                                                    false);
                                if (!size)
                                {
                                    ::ReportScriptError((::CStringArgument *)(context), "Missing parameter %s.\r\nCompiled script not saved!",
                                                 apParameter->name);
                                    return false;
                                }
                                if (word.reference > 0 || word.type)
                                {
                                    ::ReportScriptError((::CStringArgument *)(context),
                                                 "Parameter %s may not be a variable.\r\nCompiled script not saved!",
                                                 apParameter->name);
                                    return false;
                                }
                                if (!reinterpret_cast<::CStringArgument *>((context))->FUN_005afad0((::ScriptToken *)(::MessageParseWord_5b3c *)(&word), false, false) || word.reference == 0)
                                {
                                    ::ReportScriptError((::CStringArgument *)(context),
                                                 "Item '%s' not found for parameter %s.\r\nCompiled script not saved!",
                                                 &word, apParameter->name);
                                    return false;
                                }
                                form = static_cast<BGSMessage_5b3c*>(
                                    _FNV_DynamicCast(word.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), MsgCompileData::DAT_01186130, 0));
                                if (word.variable == 0 && form == 0)
                                {
                                    ::ReportScriptError((::CStringArgument *)(context),
                                                 "Invalid message '%s' for parameter %s.\r\nCompiled script not saved!",
                                                 &word, apParameter->name);
                                    return false;
                                }
                                char* output = line->cOutput;
                                output[line->m_uiValueAfterSecondBuffer] = 'r';
                                line->m_uiValueAfterSecondBuffer++;
                                *(unsigned short*)&output[line->m_uiValueAfterSecondBuffer] =
                                    (unsigned short)word.reference;
                                line->m_uiValueAfterSecondBuffer += 2;
                            }
                            text = 0;
                            if (literal)
                                text = message.text;
                            else
                                text = form ? form->description.GetText(0, 0x43534544) : 0;
                            count = 0;
                            while (text && *text)
                            {
                                if (*text == '%')
                                {
                                    if (text[1] == '%')
                                        text++;
                                    else
                                        count++;
                                }
                                text++;
                            }
                            if (count >= 10)
                            {
                                ::ReportScriptError((::CStringArgument *)(context), "Max variables of %d exceeded.", 10);
                                return false;
                            }
                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = (unsigned short)count;
                            line->m_uiValueAfterSecondBuffer += 2;
                            output = line->cOutput;
                            for (int i = 0; i < count; i++)
                            {
                                MessageParseWord_5b3c word;
                                reinterpret_cast<::ScriptVariableData *>(&(word))->Reset();
                                size = ::FUN_005af5f0((::CompilerShell *)(context), (::ScriptVariableData *)(::MessageParseWord_5b3c *)(&word), line->cLine, (int *)(unsigned int *)(&line->uiElapsedMilliseconds), true,
                                                    false);
                                if (!size)
                                {
                                    ::ReportScriptError((::CStringArgument *)(context),
                                                 "Too few variables in MessageBox parameters; expected %d, found %d.",
                                                 count, i);
                                    return false;
                                }
                                if (!word.type)
                                {
                                    ::ReportScriptError((::CStringArgument *)(context), "Unknown variable '%s' in MessageBox parameters.", &word);
                                    return false;
                                }
                                if (word.reference > 0)
                                {
                                    if (word.type == 'G')
                                    {
                                        output[line->m_uiValueAfterSecondBuffer] = 'G';
                                        line->m_uiValueAfterSecondBuffer++;
                                    }
                                    else
                                    {
                                        output[line->m_uiValueAfterSecondBuffer] = 'r';
                                        line->m_uiValueAfterSecondBuffer++;
                                    }
                                    *(unsigned short*)&output[line->m_uiValueAfterSecondBuffer] =
                                        (unsigned short)word.reference;
                                    line->m_uiValueAfterSecondBuffer += 2;
                                }
                                if (word.type != 'G')
                                {
                                    if (word.variable > 0)
                                    {
                                        output[line->m_uiValueAfterSecondBuffer] = word.type;
                                        line->m_uiValueAfterSecondBuffer++;
                                        *(unsigned short*)&output[line->m_uiValueAfterSecondBuffer] =
                                            (unsigned short)word.variable;
                                        line->m_uiValueAfterSecondBuffer += 2;
                                    }
                                    else
                                    {
                                        ::ReportScriptError(
                                            (::CStringArgument *)(context),
                                            "Unknown compiler error in MessageBoxCompile.  Failed to parse variable '%s'.",
                                            &word);
                                        return false;
                                    }
                                }
                            }
                            if (!literal)
                            {
                                if (hasButtons)
                                {
                                    int buttons = 0;
                                    {
                                        MessageArrayWord_5b3c words[10];
                                        do
                                        {
                                            size = ::FUN_005af5f0((::CompilerShell *)(context), (::ScriptVariableData *)(::MessageParseWord_5b3c *)(&words[buttons]), line->cLine,
                                                                (int *)(unsigned int *)(&line->uiElapsedMilliseconds), false, false);
                                            if (size > 0)
                                                buttons++;
                                        } while (size > 0 && buttons < 10);
                                        *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] =
                                            (unsigned short)buttons;
                                        line->m_uiValueAfterSecondBuffer += 2;
                                        for (int j = 0; j < buttons; j++)
                                        {
                                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = 1;
                                            line->m_uiValueAfterSecondBuffer += 2;
                                            size = FUN_0044a670(words[j].text);
                                            *(unsigned short*)&line->cOutput[line->m_uiValueAfterSecondBuffer] =
                                                (unsigned short)size;
                                            line->m_uiValueAfterSecondBuffer += 2;
                                            ::__memcpy(&line->cOutput[line->m_uiValueAfterSecondBuffer], &words[j],
                                                         size);
                                            line->m_uiValueAfterSecondBuffer += size;
                                        }
                                    }
                                }
                                else
                                {
                                    int duration = 0;
                                    MessageParseWord_5b3c word;
                                    reinterpret_cast<::ScriptVariableData *>(&(word))->Reset();
                                    size = ::FUN_005af5f0((::CompilerShell *)(context), (::ScriptVariableData *)(::MessageParseWord_5b3c *)(&word), line->cLine, (int *)(unsigned int *)(&line->uiElapsedMilliseconds),
                                                        false, false);
                                    if (size > 0)
                                    {
                                        if (!IsIntegerString(word.text))
                                        {
                                            ::ReportScriptError(
                                                (::CStringArgument *)(context),
                                                "Message time must be an integer.\r\nCompiled script not saved!");
                                            return false;
                                        }
                                        else
                                            duration = atol(word.text);
                                    }
                                    *(int*)&line->cOutput[line->m_uiValueAfterSecondBuffer] = duration;
                                    line->m_uiValueAfterSecondBuffer += 4;
                                }
                            }
                            return true;
                        }
                    }
                }
            }
        }
    }
}

class TESForm_ctx
{
  public:
    virtual ~TESForm_ctx();
    int FUN_00401170();
public:
    static ::TESForm_ctx *LookupFormByEditorID(const char *);
};

class TESObjectREFR_ctx : public TESForm_ctx
{
  public:
};

struct BSStringT_char
{
    char* data;
    unsigned short length, capacity;
};

class ScriptReferencedObject
{
  public:
    BSStringT_char name;
    TESForm_ctx* form;
    unsigned int variableID;
    ScriptReferencedObject();
    ~ScriptReferencedObject();
};

template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList* next;
    T& FUN_006815c0();
    BSSimpleList* FUN_00726070();
    void FUN_00905820(const T&);
};

struct ScriptInfo
{
    unsigned int variableCount, m_uiReferenceID, dataSize, lastID;
    unsigned short type;
    bool compiled;
    unsigned char unk13;
};

struct ScriptToken
{
    char name[0x200];
    unsigned int refIndex;
    unsigned char type;
    unsigned int opcode;
    unsigned int variableID;
    TESForm_ctx* form;
    unsigned int unk214, unk218, paramTextLen;
};

struct CStringArgument_ctx
{
    char* scriptText;
    unsigned int textOffset;
    int runtimeMode;
    BSStringT_char scriptName;
    unsigned int errorCode;
    bool partialScript;
    unsigned int curLineNumber;
    unsigned char* scriptData;
    unsigned int dataOffset;
    ScriptInfo info;
    BSSimpleList<void*> vars;
    BSSimpleList<ScriptReferencedObject*> refVars;
    void* currentScript;
    BSSimpleList<void*> lines;
    bool FUN_005afad0(ScriptToken*, bool, bool);
};

unsigned int FUN_005afe10(const char*, char**, int);

// @fnv 0x005afad0
bool CStringArgument_ctx::FUN_005afad0(ScriptToken* token, bool variable, bool allowUnknown)
{
    bool result = false;
    unsigned int index = 1;
    BSSimpleList<ScriptReferencedObject*>* entry = &refVars;
    while (entry && ((::ScriptReferencedObject *)(new ((void *)(entry)) ::Vec3())))
    {
        if (!reinterpret_cast<::B408A80String *>((void *)&(((::ScriptReferencedObject *)(new ((void *)(entry)) ::Vec3()))->name))->FUN_00408a80(token->name, true))
        {
            token->refIndex = index;
            token->form = ((::ScriptReferencedObject *)(new ((void *)(entry)) ::Vec3()))->form;
            if (variable)
                ((::ScriptReferencedObject *)(new ((void *)(entry)) ::Vec3()))->variableID = token->variableID;
            else
                token->variableID = ((::ScriptReferencedObject *)(new ((void *)(entry)) ::Vec3()))->variableID;
            result = true;
            break;
        }
        entry = ((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
        index++;
    }
    if (!result)
    {
        ScriptReferencedObject* reference = new ScriptReferencedObject;
        if (variable)
            result = true;
        else
        {
            if (!FUN_00404dc0(token->name, "Player"))
            {
                reference->form = (*reinterpret_cast<::TESForm_ctx * *>(&::_g_thePlayer));
                result = true;
            }
            if (!result)
            {
                reference->form = ::TESForm_ctx::LookupFormByEditorID(token->name);
                if (reference->form)
                {
                    if (reference->form->FUN_00401170() == 3)
                        reference->form = 0;
                    else
                        result = true;
                }
            }
            if (!result)
            {
                char* end = 0;
                unsigned int formID = FUN_005afe10(token->name, &end, 16);
                if (formID && end && !*end)
                {
                    reference->form = FUN_004839c0(formID);
                    if (reference->form)
                        result = true;
                }
            }
            if (result && runtimeMode != 1)
            {
                TESObjectREFR_ctx* refr = dynamic_cast<TESObjectREFR_ctx*>(reference->form);
                if (refr && !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((refr))->FUN_005653d0())
                {
                    ReportScriptError(this, "Non-persistent reference '%s' cannot be used in a script.", token->name);
                    result = false;
                }
            }
        }
        if (result || allowUnknown)
        {
            result = true;
            if (variable)
            {
                reference->form = 0;
                reference->variableID = token->variableID;
            }
            else
            {
                token->form = reference->form;
                reference->variableID = 0;
            }
            reinterpret_cast<::TextString *>(&(reference->name))->FUN_004037f0(token->name, 0);
            info.m_uiReferenceID++;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00905820((void *)&(reference));
            token->refIndex = info.m_uiReferenceID;
        }
        else
            delete reference;
    }
    return result;
}

extern const char missingSetExpression[];

struct CompileLine;

struct CompileState;

struct CompileWord
{
    char text[512];
    unsigned refIndex;
    char variableType;
    unsigned functionCode;
    unsigned variableID;
    void* form;
    CompileWord();
};

struct CompileString
{
    char* text;
    unsigned short length, capacity;
};

struct CompileVariable
{
    unsigned id;
    unsigned unk04, unk08, unk0c;
    bool integer;
    unsigned char unk11;
    unsigned short unk12;
    unsigned unk14;
    CompileString name;
    CompileVariable();
};

struct CompileVariables
{
};

struct CompileReference
{
    unsigned unk00, unk04;
    TESForm_ctx* form;
    unsigned variableID;
};

struct CompileScript
{
};

struct CompileState
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* output;
    unsigned outputSize;
    unsigned unk28, unk2c, unk30;
    unsigned variableCount;
    bool partial;
};

struct CompileLine
{
    unsigned lineNumber;
    char input[512];
    unsigned inputSize, inputOffset;
    char output[512];
    unsigned outputSize;
    int kind;
    unsigned refIndex;
    unsigned error;
    CompileLine();
};

typedef bool(__cdecl* CompileCallback)(unsigned short, void*, CompileLine*, CompileState*);

struct CompileCommand
{
    const char* name;
    const char* alias;
    unsigned short opcode, unk0a;
    unsigned unk0c;
    bool requiresReference;
    unsigned char unk11;
    unsigned short parameterCount;
    void* parameters;
    unsigned unk18;
    CompileCallback compile;
    unsigned unk20, unk24;
};

extern unsigned DAT_011cadbc;

int FUN_005af5f0(CompileState*, CompileWord*, char*, unsigned*, unsigned char, int);

bool FUN_005afeb0(const char*);

bool FUN_005b1a90(const char*, unsigned);

struct CompileOperand
{
    unsigned kind, unk04, unk08, unk0c;
};

struct CompileOperators
{
    unsigned values[64];
    int top;
};

struct CompileOperands
{
    CompileOperand values[32];
    int top;
};

struct CompileExpression
{
    int error;
    char output[1024];
    CompileOperators operators;
    CompileOperands operands;
    CompileExpression();
    ~CompileExpression();
};

struct LineCompiler_ctx
{
    bool FUN_005aff40(CompileScript*, CompileState*, CompileLine*);
};

// @fnv 0x005aff40
bool LineCompiler_ctx::FUN_005aff40(CompileScript* script, CompileState* compiler, CompileLine* line)
{
    CompileWord word6;

    unsigned offset_2 = 0;

    CompileExpression expression5;
    char* expressionCodeVal9;

    line->outputSize = 0;
    line->inputOffset = 0;

    switch (line->kind)
    {
    case 29:
        break;

    case 16:
        if (FUN_005af5f0(compiler, &word6, line->input, &line->inputOffset, 0, 0))
        {
            int i;
            bool found7 = false;

            for (i = 0; i < 38; ++i)
            {
                if (!FUN_00404dc0((*reinterpret_cast<CompileCommand (*)[]>(&::g_scriptBlocks))[i].name, word6.text) || !FUN_00404dc0((*reinterpret_cast<CompileCommand (*)[]>(&::g_scriptBlocks))[i].alias, word6.text))
                {
                    found7 = true;
                    break;
                }
            }
            if (found7)
            {
                *(unsigned short*)(line->output + line->outputSize) = (unsigned short)((*reinterpret_cast<CompileCommand (*)[]>(&::g_scriptBlocks))[i].opcode);
                line->outputSize += 2;

                int length = 0;
                length = reinterpret_cast<::fnv_005b12c0::FUN_005b12c0_owner *>(this)->CountLinesInBeginBlock((::fnv_005b12c0::CStringArgument_ctx *)(compiler), (unsigned int *)(line));

                if (length == -1)
                {
                    ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Mismatched begin/end block.");
                    return false;
                }
                *(unsigned*)(line->output + line->outputSize) = 0x55555555;

                DAT_011cadbc = compiler->outputSize + line->outputSize;

                line->outputSize += 4;

                CompileCommand* command = &(*reinterpret_cast<CompileCommand (*)[]>(&::g_scriptBlocks))[i];

                if (command)
                {
                    if (command->requiresReference && compiler->partial)
                    {
                        ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Invalid block type for quest script.");
                        return false;
                    }
                    if (command && command->parameters)
                    {
                        void* blockParameters0 = command->parameters;

                        CompileCallback blockCallback11 = command->compile;

                        unsigned short count = command->parameterCount;

                        CompileLine parametersLine;

                        ::TaskQueueInterface::CopyStringToBuffer(parametersLine.input, 512, line->input + line->inputOffset);

                        parametersLine.outputSize = 0;

                        parametersLine.lineNumber = line->lineNumber;

                        if (!blockCallback11(count, blockParameters0, &parametersLine, compiler))
                            return false;

                        ::__memcpy(line->output + line->outputSize, parametersLine.output, parametersLine.outputSize);

                        line->outputSize += parametersLine.outputSize;
                    }
                }
                if (DAT_011cadbc)
                {
                    *(unsigned*)(line->output + (DAT_011cadbc - compiler->outputSize)) =
                        compiler->outputSize + line->outputSize;
                }
            }
            else
            {
                ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Syntax Error.  Invalid block type in 'begin' command.");
                return false;
            }
        }
        else
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Syntax Error.  Missing block type in 'begin' command.");
            return false;
        }
        break;

    case 17:
        if (DAT_011cadbc)
        {
            unsigned start6 = *(unsigned*)(compiler->output + (DAT_011cadbc + 4));

            *(unsigned*)(compiler->output + (DAT_011cadbc + 4)) = compiler->outputSize - start6;
            DAT_011cadbc = 0;
        }
        else
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Syntax Error.  Failed to store the 'begin' 'end' jump block.");
            return false;
        }
    case 30:
        break;
    case 18:
    case 19:
    case 20:
    case 31:
        if (FUN_005af5f0(compiler, &word6, line->input, &line->inputOffset, 0, 0))
        {
            const char* variableName1 = word6.text;

            if (!FUN_005afeb0(variableName1))
            {
                ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Invalid variable name '%s'.\r\nCompiled script not saved!", variableName1);
                return false;
            }
            CompileVariable* variableInfo0 = new CompileVariable;

            variableInfo0->integer = (line->kind != 20 && line->kind != 31) ? 1 : 0;

            reinterpret_cast<::TextString *>(&(variableInfo0->name))->FUN_004037f0(variableName1, 0);

            if (((signed char)(reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((script))->Method_005ac6a0(((const char *)(::FUN_00559450((int *)&(variableInfo0->name)))), (unsigned int *)(variableInfo0)))))
            {
            }
            else
            {
                compiler->variableCount++;
                variableInfo0->id = compiler->variableCount;
            }
            reinterpret_cast<::Callees *>((((::CompileVariables *)(reinterpret_cast<struct ::FUN_005a8080 *>((compiler))->GetField()))))->FUN_00905820((void *)&(variableInfo0));

            if (line->kind == 31)
            {
                word6.variableID = variableInfo0->id;
                reinterpret_cast<::CStringArgument_ctx *>((compiler))->FUN_005afad0((::ScriptToken *)(::CompileWord *)(&word6), true, false);
            }
        }
        else
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Missing variable name in variable declaration.");
            return false;
        }
        break;

    case 21: {
        if (!FUN_005af5f0(compiler, &word6, line->input, &line->inputOffset, 1, 1))
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Missing variable name in set command.");
            return false;
        }
        if (!word6.variableType || word6.variableType == 'X')
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Unknown variable '%s'.", &word6);
            return false;
        }
        CompileWord setWord20;

        FUN_005af5f0(compiler, &setWord20, line->input, &line->inputOffset, 0, 0);

        if (tolower(setWord20.text[0]) != 't' || tolower(setWord20.text[1]) != 'o')
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Syntax Error.  Missing \"to\" in set command.");
            return false;
        }
        if (word6.refIndex > 0)
        {
            if (word6.variableType == 'G')
            {
                line->output[line->outputSize] = 'G';
                line->outputSize++;
            }
            else
            {
                line->output[line->outputSize] = 'r';
                line->outputSize++;
            }
            *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(word6.refIndex);
            line->outputSize += 2;
        }
        if (word6.variableID > 0)
        {
            line->output[line->outputSize] = word6.variableType;
            line->outputSize++;
            *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(word6.variableID);
            line->outputSize += 2;
        }
        if (!FUN_005b1a90(line->input, line->inputOffset))
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Syntax Error.  Mismatched parentheses in set command.");
            return false;
        }
        ::FUN_005b1b60(line->input, (int *)(unsigned int *)(&line->inputOffset));

        char setText20[512];
        ::FUN_00403d30(setText20, 0, 512);

        int setLength1 = 0;
        setLength1 = reinterpret_cast<::FUN_005b1570_Class *>(this)->CompileScriptLine((::CStringArgument_ctx *)(compiler), (unsigned int *)(line), (char *)(line->input + line->inputOffset), setText20);

        if (!setLength1)
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), missingSetExpression);
            return false;
        }
        expressionCodeVal9 = reinterpret_cast<::ExpressionConverter *>(&(expression5))->ConvertToPostfix(setText20, (unsigned int *)(int *)(&setLength1));

        if (::FUN_00559450((int *)&(expression5)))
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "InfixToPostfix Error.");
            return false;
        }
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(setLength1);
        line->outputSize += 2;

        ::__memcpy(line->output + line->outputSize, expressionCodeVal9, setLength1);
        line->outputSize += setLength1;
    }
    break;

    case 22:
    case 24: {
        offset_2 = 0;

        if (!FUN_005b1a90(line->input, offset_2))
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Mismatched parentheses.");
            return false;
        }
        ::FUN_005b1b60(line->input, (int *)(unsigned int *)(&offset_2));

        char branchText7[512];
        ::FUN_00403d30(branchText7, 0, 512);

        int branchLength10 = 0;
        branchLength10 = reinterpret_cast<::FUN_005b1570_Class *>(this)->CompileScriptLine((::CStringArgument_ctx *)(compiler), (unsigned int *)(line), (char *)(line->input + offset_2), branchText7);

        if (!branchLength10)
            return false;

        expressionCodeVal9 = reinterpret_cast<::ExpressionConverter *>(&(expression5))->ConvertToPostfix(branchText7, (unsigned int *)(int *)(&branchLength10));

        if (::FUN_00559450((int *)&(expression5)))
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), ::g_expressionErrorStrings[::FUN_00559450((int *)&(expression5))]);
            return false;
        }
        int branchJump11 = reinterpret_cast<::ScriptBlockScanner *>(this)->ScanBlockLines((::CStringArgument_ctx *)(compiler), (unsigned int *)(line));

        if (branchJump11 == -1)
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Mismatched if/then/else block.");
            return false;
        }
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(branchJump11);
        line->outputSize += 2;
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(branchLength10);
        line->outputSize += 2;

        ::__memcpy(line->output + line->outputSize, expressionCodeVal9, branchLength10);
        line->outputSize += branchLength10;
    }
    break;

    case 23: {
        int jump = 0;
        jump = reinterpret_cast<::ScriptBlockScanner *>(this)->ScanBlockLines((::CStringArgument_ctx *)(compiler), (unsigned int *)(line));

        if (jump == -1)
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Mismatched if/then/else block.");
            return false;
        }
        *(unsigned short*)(line->output + line->outputSize) = (unsigned short)(jump);
        line->outputSize += 2;
    }
    break;

    case 28:
        break;

    case 25:
        break;

    default: {
        CompileCommand* command = ((::CompileCommand *)(::GetFunctionByOpcode((::SCRIPT_OUTPUT)(line->kind))));

        if (!command)
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Unknown function code %d.", line->kind);
            return false;
        }
        if (command)
        {
            if (command->requiresReference && compiler->partial && !line->refIndex)
            {
                ::ReportScriptError((::CStringArgument_ctx *)(compiler), "Reference function requires explicit reference in quest script.");
                return false;
            }
            if (command->requiresReference && line->refIndex > 0)
            {
                CompileReference* ref2 = ((::CompileReference *)(reinterpret_cast<::Cls_5afe30 *>((compiler))->GetNodeValue(line->refIndex)));

                TESObjectREFR_ctx* object = dynamic_cast<TESObjectREFR_ctx*>(ref2->form);

                if (!object && !ref2->variableID)
                {
                    ::ReportScriptError(
                        (::CStringArgument_ctx *)(compiler),
                        "Syntax error.  Invalid reference '%s' (only object references and reference variables are allowed in this context).",
                        ((const char *)(::FUN_00559450((int *)(ref2)))));
                    return false;
                }
            }
            if (command->parameters)
            {
                void* commandParameters0 = command->parameters;

                CompileCallback commandCallback1 = command->compile;

                unsigned short commandCount3 = command->parameterCount;

                if (!commandCallback1(commandCount3, commandParameters0, line, compiler))
                    return false;
            }
        }
    }
    break;
    }
    switch (line->kind)
    {
    case 18:
    case 19:
    case 20:
    case 31:
        break;

    default:
        if (compiler->outputSize + line->outputSize + 10 >= 0x4000)
        {
            ::ReportScriptError((::CStringArgument_ctx *)(compiler), "MAX_SCRIPT_SIZE exceeded.\r\nCompiled script not saved!");
            return false;
        }
        if (line->refIndex > 0)
        {
            *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(28);
            compiler->outputSize += 2;
            *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(line->refIndex);
            compiler->outputSize += 2;
        }
        *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(line->kind);
        compiler->outputSize += 2;
        *(unsigned short*)(compiler->output + compiler->outputSize) = (unsigned short)(line->outputSize);
        compiler->outputSize += 2;

        ::__memcpy(compiler->output + compiler->outputSize, line->output, line->outputSize);
        compiler->outputSize += line->outputSize;
    }
    return true;
}

extern "C" void* _FNV_DynamicCast(void*, int, void*, void*, int);

struct EncodeFormView : TESForm
{

    virtual void slot00();

    virtual void slot04();

    virtual void slot08();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void slot40();

    virtual void slot44();

    virtual void slot48();

    virtual void slot4c();

    virtual void slot50();

    virtual void slot54();

    virtual void slot58();

    virtual void slot5c();

    virtual void slot60();

    virtual void slot64();

    virtual void slot68();

    virtual void slot6c();

    virtual void slot70();

    virtual void slot74();

    virtual void slot78();

    virtual void slot7c();

    virtual void slot80();

    virtual void slot84();

    virtual void slot88();

    virtual void slot8c();

    virtual void slot90();

    virtual void slot94();

    virtual void slot98();

    virtual void slot9c();

    virtual void slota0();

    virtual void slota4();

    virtual void slota8();

    virtual void slotac();

    virtual void slotb0();

    virtual void slotb4();

    virtual void slotb8();

    virtual void slotbc();

    virtual void slotc0();

    virtual void slotc4();

    virtual void slotc8();

    virtual void slotcc();

    virtual void slotd0();

    virtual void slotd4();

    virtual void slotd8();

    virtual void slotdc();

    virtual void slote0();

    virtual void slote4();

    virtual bool IsReference();

    virtual void slotec();

    virtual void slotf0();

    virtual void slotf4();

    virtual void slotf8();

    virtual void slotfc();

    virtual bool IsActor();
};

struct BGSNote;

struct BGSListForm;

struct EncodeReferenceView : EncodeFormView
{
};

struct BGSEncounterZone;

struct TESIdleForm;

struct EncodeCellView
{
};

struct TESObject;

struct EffectSetting;

struct TESActorBase;

struct TESPackage;

struct BGSPerk;

struct BGSMenuIcon;

struct TESCombatStyle;

struct TESObjectBOOK;

struct TESWorldSpace;

struct SpellItem;

struct MagicItem;

extern char DAT_0118a650[];

extern char DAT_011840dc[];

extern char DAT_01186a18[];

extern char DAT_011863d4[];

extern char DAT_011863f0[];

extern char DAT_0118640c[];

extern char DAT_01183128[];

extern char DAT_0118627c[];

struct EncodeWord
{
    char text[512];
    unsigned refIndex;
    char variableType;
    unsigned functionCode;
    unsigned variableID;
    TESForm* form;
    EncodeWord();
};

struct EncodeCompiler
{
};

struct EncodeParameter
{
    const char* name;
    unsigned type;
    bool optional;
};

struct EncodeKind
{
    const char* name;
    unsigned char kind;
    bool isReference;
    unsigned short reserved;
};

extern const char* DAT_01199e90;

struct EncodeAnimation
{
    const char* name;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

// @fnv 0x005b1ba0
bool __cdecl FUN_005b1ba0(unsigned short count, const EncodeParameter* parameters, ScriptLineBuffer* line,
                          EncodeCompiler* compiler)

{

    line->uiElapsedMilliseconds = 0;

    char* countDestinationTmp = &line->cOutput[line->m_uiValueAfterSecondBuffer];

    *(unsigned short*)countDestinationTmp = count;

    line->m_uiValueAfterSecondBuffer += 2;

    short index4;

    for (index4 = 0; index4 < count; ++index4)
    {

        unsigned char kindX = (*reinterpret_cast<EncodeKind (*)[]>(&::DAT_0118cdd0))[parameters[index4].type].kind;

        EncodeWord word7;

        int lengthVal = ::FUN_005af5f0((::CompilerShell *)(compiler), (::ScriptVariableData *)(::EncodeWord *)(&word7), line->cLine, (int *)(unsigned int *)(&line->uiElapsedMilliseconds), kindX, 0);

        if (!lengthVal)
        {

            if (!parameters[index4].optional)
            {
                ::ReportScriptError((::CStringArgument *)(compiler), "Missing parameter %s.\r\nCompiled script not saved!", parameters[index4].name);
                return false;
            }

            else
            {
                *(unsigned short*)countDestinationTmp = index4;
                return true;
            }
        }

        if (kindX == 0 && (word7.refIndex > 0 || word7.variableType != 0))
        {
            ::ReportScriptError((::CStringArgument *)(compiler), "Parameter %s may not be a variable.\r\nCompiled script not saved!",
                         parameters[index4].name);
            return false;
        }

        if ((*reinterpret_cast<EncodeKind (*)[]>(&::DAT_0118cdd0))[parameters[index4].type].isReference &&
            (!reinterpret_cast<::CStringArgument *>((compiler))->FUN_005afad0((::ScriptToken *)(::EncodeWord *)(&word7), false, false) || !word7.refIndex))
        {
            ::ReportScriptError((::CStringArgument *)(compiler), "Item '%s' not found for parameter %s.\r\nCompiled script not saved!", &word7,
                         parameters[index4].name);
            return false;
        }

        if ((*reinterpret_cast<EncodeKind (*)[]>(&::DAT_0118cdd0))[parameters[index4].type].isReference)
        {

            switch (parameters[index4].type)
            {

            case 3: {

                if (!word7.variableID && (!word7.form || !::TESContainer::IsValidContainerType(word7.form->FUN_00401170())))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid inventory object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 50: {

                if (!word7.variableID &&
                    (!word7.form || (!::TESContainer::IsValidContainerType(word7.form->FUN_00401170()) && word7.form->FUN_00401170() != 85)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid inventory object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 53: {

                if (!word7.variableID &&
                    (!word7.form || (!reinterpret_cast<EncodeFormView*>(word7.form)->IsReference() &&
                                     word7.form->FUN_00401170() != 85)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 4:
            case 6:
            case 24:
            case 26: {

                if (!word7.variableID)
                {
                    EncodeReferenceView* reference =
                        (EncodeReferenceView*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), (*reinterpret_cast<char (*)[]>(&::DAT_011841cc)), 0);

                    if (!reference)
                    {
                        ::ReportScriptError((::CStringArgument *)(compiler),
                                     "Invalid object reference '%s' for parameter %s.\r\nCompiled script not saved!",
                                     &word7, parameters[index4].name);
                        return false;
                    }

                    switch (parameters[index4].type)
                    {

                    case 26:
                        if (!((void *)(reinterpret_cast<::s55d310::Owner *>((reference))->FUN_0055d310())))
                        {
                            ::ReportScriptError(
                                (::CStringArgument *)(compiler),
                                "Invalid container reference '%s' for parameter %s.\r\nCompiled script not saved!",
                                &word7, parameters[index4].name);
                            return false;
                        }
                        break;

                    case 24:
                        if (((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) != (*reinterpret_cast<::TESForm * *>(&::DAT_011ca224)))
                        {
                            ::ReportScriptError((::CStringArgument *)(compiler),
                                         "Invalid map marker '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        break;

                    case 6:
                        if (!reference->IsActor())
                        {
                            ::ReportScriptError((::CStringArgument *)(compiler), "Invalid actor '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        break;
                    }
                }
            }
            break;

            case 7: {

                if (!word7.variableID &&
                    (!word7.form || (!(SpellItem*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_01183060, 0) &&
                                     !(TESObjectBOOK*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_0118a650, 0))))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid spell item '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 9: {

                EncodeCellView* object =
                    (EncodeCellView*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), (*reinterpret_cast<char (*)[]>(&::DAT_01183fb4)), 0);

                if (!word7.variableID && (!object || !reinterpret_cast<::TESObjectCELL *>((object))->IsCellInterior()))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid interior cell '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 47: {

                BGSEncounterZone* object =
                    (BGSEncounterZone*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_011840dc, 0);

                if (!word7.variableID && !object)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid encounter zone '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 48: {

                TESIdleForm* object = (TESIdleForm*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_01186a18, 0);

                if (!word7.variableID && !object)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid Idle form'%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 37: {

                BGSListForm* object = (BGSListForm*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_011863d4, 0);

                if (!word7.variableID && !object)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid form list '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 38: {

                BGSMenuIcon* object = (BGSMenuIcon*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_011863f0, 0);

                if (!word7.variableID && !object)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid menu icon '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 39: {

                BGSPerk* object = (BGSPerk*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_011861dc, 0);

                if (!word7.variableID && !object)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid perk '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 40: {

                BGSNote* object = (BGSNote*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_0118640c, 0);

                if (!word7.variableID && !object)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid note '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 27: {

                if (!word7.variableID &&
                    (!word7.form || !(TESWorldSpace*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_01183fd0, 0)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid worldspace '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 11: {

                if (!word7.variableID &&
                    (!word7.form || !(MagicItem*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), (*reinterpret_cast<char (*)[]>(&::DAT_01183140)), 0)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid magic item '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 31: {

                if (!word7.variableID &&
                    (!word7.form || !(EffectSetting*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_011837c4, 0)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid effect setting '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 12: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 13)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid sound '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 54: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 102)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid music type '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 13: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 69)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid topic '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 14: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 71)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid info '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 15: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 12)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid race '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 16: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 7)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid class '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 17: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 8)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid faction '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 62: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 104)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid reputation '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 65: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 113)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid challenge '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 63: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 109)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid casino '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 64: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 108)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid casino chip '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 66: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 116)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid caravan money '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 67: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 115)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid caravan card '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 68: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 117)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid caravan card '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 69: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 55)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid region '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 19: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 6)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid global '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 20: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 39 && word7.form->FUN_00401170() != 85)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid furniture object/list '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 21: {

                if (!word7.variableID &&
                    (!word7.form || !(TESObject*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_01183128, 0)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid object '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 25: {

                if (!word7.variableID &&
                    (!word7.form || !(TESActorBase*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), (*reinterpret_cast<char (*)[]>(&::DAT_011846e8)), 0)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid actor base '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 29: {

                if (!word7.variableID &&
                    (!word7.form || !(TESPackage*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), (*reinterpret_cast<char (*)[]>(&::DAT_011846a0)), 0)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid package '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 30: {

                if (!word7.variableID &&
                    (!word7.form || !(TESCombatStyle*)_FNV_DynamicCast(word7.form, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), DAT_0118627c, 0)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid combat style '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 33: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 53)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid weather '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 42: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 84)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid Imagespace Modifier '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 43: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 83)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid Imagespace '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 34: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 42)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid NPC '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 35: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 42 && word7.form->FUN_00401170() != 8)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid owner '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 36: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 79)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid Effect Shader '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 49: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 98)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid message '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 56: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 42 && word7.form->FUN_00401170() != 45)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid NPC or LeveledCharacter '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 57: {

                if (!word7.variableID &&
                    (!word7.form || (word7.form->FUN_00401170() != 43 && word7.form->FUN_00401170() != 44)))
                {
                    ::ReportScriptError(
                        (::CStringArgument *)(compiler),
                        "Invalid Creature or LeveledCreature '%s' for parameter %s.\r\nCompiled script not saved!",
                        &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 58: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 45)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid LeveledCharacter '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 59: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 44)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Invalid LeveledCreature '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            case 60: {

                if (!word7.variableID && (!word7.form || (word7.form->FUN_00401170() != 52)))
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid LeveledItem '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 61: {

                if (!word7.variableID && !word7.form)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid form '%s' for parameter %s.\r\nCompiled script not saved!", &word7,
                                 parameters[index4].name);
                    return false;
                }
            }
            break;

            default:
                ::FUN_005b5e40(
                    );
                return false;
            }

            char* output = line->cOutput;

            output[line->m_uiValueAfterSecondBuffer] = 'r';
            line->m_uiValueAfterSecondBuffer++;

            *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)word7.refIndex;

            line->m_uiValueAfterSecondBuffer += 2;
        }
        else
            switch (parameters[index4].type)
            {

            case 0:

                *(unsigned short*)(line->cOutput + line->m_uiValueAfterSecondBuffer) = (unsigned short)lengthVal;

                line->m_uiValueAfterSecondBuffer += 2;

                ::__memcpy(line->cOutput + line->m_uiValueAfterSecondBuffer, &word7, lengthVal);

                line->m_uiValueAfterSecondBuffer += lengthVal;

                break;

            case 1:
            case 2:
            case 23: {

                char* output = line->cOutput;

                if (word7.refIndex > 0)
                {

                    if (word7.variableType == 'G')
                    {
                        output[line->m_uiValueAfterSecondBuffer] = 'G';
                        line->m_uiValueAfterSecondBuffer++;
                    }
                    else
                    {
                        output[line->m_uiValueAfterSecondBuffer] = 'r';
                        line->m_uiValueAfterSecondBuffer++;
                    }

                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)word7.refIndex;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                if (word7.variableType != 'G')
                {

                    if (word7.variableID > 0)
                    {

                        output[line->m_uiValueAfterSecondBuffer] = word7.variableType;
                        line->m_uiValueAfterSecondBuffer++;

                        *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) =
                            (unsigned short)word7.variableID;
                        line->m_uiValueAfterSecondBuffer += 2;
                    }
                    else if (parameters[index4].type == 1 || parameters[index4].type == 23)
                    {

                        if (!::IsIntegerString(word7.text))
                        {
                            ::ReportScriptError((::CStringArgument *)(compiler),
                                         "Unknown variable '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        else
                        {

                            output[line->m_uiValueAfterSecondBuffer] = 'n';
                            line->m_uiValueAfterSecondBuffer++;

                            int value = atol(word7.text);

                            *(int*)(output + line->m_uiValueAfterSecondBuffer) = value;
                            line->m_uiValueAfterSecondBuffer += 4;
                        }
                    }
                    else
                    {

                        if (!::FUN_004b12d0((char *)(word7.text)))
                        {
                            ::ReportScriptError((::CStringArgument *)(compiler),
                                         "Unknown variable '%s' for parameter %s.\r\nCompiled script not saved!",
                                         &word7, parameters[index4].name);
                            return false;
                        }
                        else
                        {

                            output[line->m_uiValueAfterSecondBuffer] = 'z';
                            line->m_uiValueAfterSecondBuffer++;

                            double value = atof(word7.text);

                            *(double*)(output + line->m_uiValueAfterSecondBuffer) = value;
                            line->m_uiValueAfterSecondBuffer += 8;
                        }
                    }
                }
            }
            break;

            case 5: {

                int value = ::FindEntryIndexByName(word7.text);

                if (value != 77)
                {

                    char* output = line->cOutput;

                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }
                else
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid actor value '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 51: {

                short value = 0;

                for (value = 0; value < 5; ++value)
                {
                    if (!FUN_00404dc0(DAT_01186cf4[value], word7.text))
                        break;
                }

                if (value != 5)
                {
                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                else
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid alignment '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 55: {

                short value = 0;

                for (value = 0; value < 5; ++value)
                {
                    if (!FUN_00404dc0(DAT_0119bbb0[value], word7.text))
                        break;
                }

                if (value != 5)
                {
                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                else
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid CriticalStage '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 52: {

                short value = 0;

                for (value = 0; value < 14; ++value)
                {
                    if (!FUN_00404dc0(DAT_011869bc[value], word7.text))
                        break;
                }

                if (value != 14)
                {
                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }

                else
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid EquipType '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
            }
            break;

            case 41: {

                int value = ::FindMiscStatIndex(word7.text);

                if (value == 43)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Invalid misc stat '%s' for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }
                else
                {

                    char* output = line->cOutput;
                    *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                    line->m_uiValueAfterSecondBuffer += 2;
                }
            }
            break;

            case 28: {

                if (!::IsIntegerString(word7.text))
                {
                    ::ReportScriptError(
                        (::CStringArgument *)(compiler),
                        "Invalid crime type '%s' for parameter %s.  Crime type must be a numeric value from 0-%d.\r\nCompiled script not saved!",
                        &word7, parameters[index4].name, 4);
                    return false;
                }

                int value = atol(word7.text);

                if (value < 0 || value >= 5)
                {
                    ::ReportScriptError(
                        (::CStringArgument *)(compiler),
                        "Invalid crime type '%s' for parameter %s.  Crime type must be a numeric value from 0-%d.\r\nCompiled script not saved!",
                        &word7, parameters[index4].name, 4);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            case 8: {

                char axis4Probe2 = (char)toupper(word7.text[0]);

                if (axis4Probe2 != 'X' && axis4Probe2 != 'Y' && axis4Probe2 != 'Z')
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Axis (X,Y,Z) required for parameter %s.\r\nCompiled script not saved!",
                                 parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                output[line->m_uiValueAfterSecondBuffer] = axis4Probe2;
                line->m_uiValueAfterSecondBuffer++;
            }
            break;

            case 18: {

                int value = 2;

                if (!FUN_00404dc0(word7.text, (*reinterpret_cast<const char * *>((void *)&::DAT_01199e8c))))
                    value = 0;

                else if (!FUN_00404dc0(word7.text, DAT_01199e90))
                    value = 1;

                if (value == 2)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Sex (Male, Female) required for parameter %s.\r\nCompiled script not saved!",
                                 parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            case 10: {

                int value = 255;

                int jProbe3;

                for (jProbe3 = 0; jProbe3 < 245; ++jProbe3)
                {
                    if (!FUN_00404dc0(word7.text, (*reinterpret_cast<EncodeAnimation (*)[]>(&::DAT_011977d8))[jProbe3].name))
                    {
                        value = jProbe3;
                        break;
                    }
                }

                if (value == 255)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler),
                                 "Animation group \"%s\" not found for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            case 32: {

                unsigned char value = 0;

                for (int j = 0; j < 87; ++j)
                {
                    if (!FUN_00404dc0(word7.text, DAT_0118a2d8[j]))
                    {
                        value = DAT_0118a598[j];
                        break;
                    }
                }

                if (!value)
                {
                    ::ReportScriptError((::CStringArgument *)(compiler), "Form Type \"%s\" not found for parameter %s.\r\nCompiled script not saved!",
                                 &word7, parameters[index4].name);
                    return false;
                }

                char* output = line->cOutput;
                *(unsigned short*)(output + line->m_uiValueAfterSecondBuffer) = (unsigned short)value;
                line->m_uiValueAfterSecondBuffer += 2;
            }
            break;

            default:
                ::FUN_005b5e40();
                return false;
            }
    }

    if (line->uiElapsedMilliseconds < line->uiSize)
    {
        ::ReportScriptError((::CStringArgument *)(compiler), "Expected end of line.\r\nCompiled script not saved!", parameters[index4].name);
        return false;
    }

    return true;
}

#include "generated/data/fallout_shared/tesscriptcompiler.inc"
#include "generated/data/fallout_shared/tesscriptcompiler_ctx_variant.inc"
#include "generated/data/fallout_shared/tesscriptcompiler_rtti2_variant.inc"
