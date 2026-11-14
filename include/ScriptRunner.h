// Source layout: ScriptRunner. PC corrections are in generate_headers.py.
#ifndef FNV_SCRIPTRUNNER_H
#define FNV_SCRIPTRUNNER_H

#include "layout_support.h"
class ScriptRunner
{
  public:
    TESObjectREFR* m_pReference;          // +0x0
    TESObject* m_pScriptObject;           // +0x4
    ScriptLocals* m_pScriptLocals;        // +0x8
    TESTopicInfo* m_pTopicInfo;           // +0xC
    TESGlobal* m_pGlobal;                 // +0x10
    Script* m_pScript;                    // +0x14
    SCRIPT_ERROR m_eScriptError;          // +0x18
    EXPRESSION_ERROR m_eExpressionError;  // +0x1C
    int m_iIfStackDepth;                  // +0x20
    int m_aiIfStack[10];                  // +0x24
    int m_iBlockStackDepth;               // +0x4C
    int m_aiBlockOffsets[10];             // +0x50
    int m_aiBlockSizes[10];               // +0x78
    bool m_bScriptCompileFailed;          // +0xA0
    bool m_bExecutionFlagSet;             // +0xA1
    unsigned short layoutPaddingA2;
    bool ParseOutput(Script* script, SCRIPT_OUTPUT& output, unsigned int& offset, int& lineSize,
                     TESObjectREFR** reference, bool skipReference);
    void SetErrorMessage(Script* script, char* message, ...);
    bool ParseBlock(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                    const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber, bool skip,
                    bool skipBlock);
    void SetError(Script* script, SCRIPT_ERROR error);
};
#endif
