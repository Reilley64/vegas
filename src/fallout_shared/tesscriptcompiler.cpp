// fallout_shared/tesscriptcompiler.cpp: ScriptCompiler, BGSCameraPath, S7f, S5a and more (36 functions)

#include <new>
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

extern "C" void* __cdecl memset(void*, int, unsigned int);

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

void __cdecl FUN_00ec8d33(int a, int b, int c);

// @fnv 0x005afe10
void __cdecl FUN_005afe10(int aiArg1, int aiArg2, int aiArg3)
{
    FUN_00ec8d33(aiArg1, aiArg2, aiArg3);
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

void* __cdecl memset(void* dst, int c, unsigned int n);

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

void* __cdecl memset(void*, int, unsigned int);

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

extern "C" int __cdecl isalnum(int);
extern "C" void* __cdecl memset(void*, int, unsigned int);

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
int __cdecl FUN_00ec7ec0(char* s, ScriptRefHolder* p, int idx);
int __cdecl FUN_00ec89e9(int c);

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
        if (FUN_00ec7ec0(((char *)(::FUN_00559450((int *)&(item->m_18)))), apRef, idx) == 0)
        {
            cA = ((char *)(::FUN_00559450((int *)&(item->m_18))))[idx];
            if (FUN_00ec89e9(cA) == 0 && cA != '-' && cA != '_')
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
unsigned int __cdecl FUN_00ec6130(const char*);
struct Parser95
{
    int ParseLine(Compile95*);
};
// @fnv 0x005aeed0
int Parser95::ParseLine(Compile95* pCompile)
{
    if (pCompile->offset >= FUN_00ec6130(pCompile->input))
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
int __cdecl FUN_00ec86e1(int c);

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
        if (FUN_00ec86e1(pInput[uiIndex]) || pInput[uiIndex] == '"')
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
extern "C" char* strchr(char* s, int c);
extern "C" int isalnum(int c);
extern "C" int isalpha(int c);
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
