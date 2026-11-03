// src/fallout_shared/tesscriptcompiler_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tesscriptcompiler.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/CStringArgument.h"
#include "fnv/decl/TESContainer.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s55d310__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004d5000.h"
#include "fnv/symbols_005ae000.h"
#include "fnv/symbols_005af000.h"
#include "fnv/symbols_005b1000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01186000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_0118e000.h"
#include "fnv/symbols_01190000.h"
#include "fnv/symbols_01197000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011ca000.h"
#include "tesscriptcompiler_packet_decls.h"

#include <stdlib.h>
#include <ctype.h>

struct TESForm
{
    int FUN_00401170();
};

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

#include "generated/data/fallout_shared/tesscriptcompiler_rtti2_variant.inc"
