
// tesscript_ctx_variant.cpp: context variant of src/fallout_shared/tesscript.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041c8d0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005a8e20_cls.h"
#include "fnv/decl/FUN_005a9140_shell.h"
#include "fnv/decl/FUN_005a9290_shell.h"
#include "fnv/decl/FUN_005a9460_This.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abe50_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005abf60_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005ae2e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_005e2730_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/ItemChangeShell.h"
#include "fnv/decl/Ref.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_005aa350__ClsX.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_006eae40__FUN_006eae40_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005aa000.h"
#include "fnv/symbols_005ab000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b1000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "tesscript_decls.h"

class ScriptLoader : public Script
{
  public:
    bool FUN_005ab9f0(TESFile* file);
};

// @fnv 0x005ab9f0
bool ScriptLoader::FUN_005ab9f0(TESFile* file)
{
    ScriptVariableInfo* chunk = 0;
    unsigned int reference;
    char* variable;
    int size;
    char* variableName;
    unsigned int unusedID;
    ScriptReferencedObject* referenceID;
    unsigned int editorID;
    if (file->GetTESForm() != ENUM_FORM_ID_SCPT_ID)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    while (size = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())
    {
        switch (size)
        {
        case 0x44494445:
            variable = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(variable), 0x200);
            SetEditorID_AtRuntime(variable);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x52484353:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kHeader), 0);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00414220_shell *>(&(m_kHeader))->FUN_00414220();
            break;
        case 0x44534c53:
            chunk = new ScriptVariableInfo;
            chunk->Load(file);
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()))))->FUN_00905820((void *)&(chunk));
            break;
        case 0x52564353:
            if (chunk)
            {
                variableName = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(variableName), 0x200);
                reinterpret_cast<::TextString *>(&(chunk->m_kName))->FUN_004037f0(variableName, 0);
            }
            break;
        case 0x41444353:
            reference = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            m_data = AllocateZeroed(1, reference);
            memset(m_data, 0, reference);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_data), 0);
            break;
        case 0x4f524353:
        case 0x56524353:
            referenceID = new ScriptReferencedObject;
            file->GetChunkData(&unusedID);
            if (size == 0x4f524353)
                referenceID->pForm = (TESForm*)unusedID;
            else
                referenceID->m_uiFormID = unusedID;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00905820((void *)&(referenceID));
            break;
        case 0x54584353:
            break;
        case 0x44484353:
            break;
        case 0x4d414e52:
            file->GetChunkData(&editorID);
        }
        if (!file->NextChunk())
            break;
    }
    if (!m_data)
        ::FUN_005b5e40();
    return true;
}
