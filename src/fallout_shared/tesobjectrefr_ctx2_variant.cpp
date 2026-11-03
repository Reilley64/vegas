
// tesobjectrefr_ctx2_variant.cpp: context variant of src/fallout_shared/tesobjectrefr.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <malloc.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0040fae0_shell.h"
#include "fnv/decl/FUN_004121b0_shell.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_0041d460_shell.h"
#include "fnv/decl/FUN_0041fe90_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0055b9a0_class.h"
#include "fnv/decl/FUN_00572d50_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00693dc0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0056b0b0__FUN_0056b0b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/loader__List.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00575000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_0057a000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011f6000.h"
#include "tesobjectrefr_decls.h"
void* FUN_0056a8c0();

struct LoadFile
{
    bool ReadID(unsigned int*);
};
struct VecLoad
{
    float x, y, z;
};
struct TransformLoad
{
    VecLoad position, rotation;
    TransformLoad();
};
struct ScriptInfoLoad
{
    int unk00, unk04, unk08;
};
struct ScriptLoad
{
};
struct ExtraLoad
{
};
struct PatrolLoad
{
};
struct SaveLoadState
{
};

struct DataLoad
{
};

class TESForm
{
  public:
    virtual ~TESForm();
public:
    void SetInitializationState(bool);
};
class TESBoundObject : public TESForm
{
  public:
};
struct StringLoad
{
    char* text;
    unsigned short length, capacity;
    StringLoad();
    ~StringLoad();
    operator const char*() const;
};
struct RefLoad
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void Reset3D(int);
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void LoadBounds(LoadFile*);
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* EditorID();
    virtual void SetEditorID(char*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TESBoundObject* base;
    VecLoad rotation, position;
    unsigned int scale;
    int unk40;
    ExtraLoad extras;
    bool FUN_0055af90(LoadFile* file);
};
// @fnv 0x0055af90
bool RefLoad::FUN_0055af90(LoadFile* file)
{
    int chunkID = 0;
    TransformLoad initial4;
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(0);
    bool failed = false;
    bool hasBaseTmp = false;
    bool reuse = false;
    unsigned int baseIDA = 0;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(0);
    if (reinterpret_cast<::FUN_00440d80_shell *>(this)->FUN_00440d80())
    {
        void* cell = ((void *)(reinterpret_cast<::FUN_0041d460_shell *>(&(extras))->FUN_0041d460()));
        if (!(*reinterpret_cast<::SaveLoadState * *>(&::g_BGSSaveLoadGame)) || !reinterpret_cast<::FUN_004121b0_shell *>((((SaveLoadState*)(*reinterpret_cast<::SaveLoadState * *>(&::g_BGSSaveLoadGame)))))->FUN_004121b0())
            reinterpret_cast<::fnv_0056b0b0::FUN_0056b0b0_shell *>(this)->FUN_0056b0b0();
        reinterpret_cast<::FUN_0040fae0_shell *>(&(extras))->FUN_0040fae0(true);
        if (cell)
            reinterpret_cast<::FUN_0041d390_shell *>(&(extras))->FUN_0041d390((::TESObjectCELL *)(cell));
        return ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) != 0;
    }
    while (reuse || (chunkID = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()) != 0)
    {
        reuse = false;
        switch (chunkID)
        {
        case 0x44494445: {
            char* editor = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editor), 512);
            SetEditorID(editor);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x41505058:
        case 0x42475258:
        case 0x424c4758:
        case 0x424d4c58:
        case 0x434d4158:
        case 0x434f4c58:
        case 0x43524d58:
        case 0x44415258:
        case 0x44455358:
        case 0x44475258:
        case 0x444f4c58:
        case 0x444f5058:
        case 0x44504158:
        case 0x44524f58:
        case 0x44525058:
        case 0x44525358:
        case 0x45535558:
        case 0x46525358:
        case 0x47484358:
        case 0x47525458:
        case 0x49435058:
        case 0x494d4558:
        case 0x49525458:
        case 0x4b4e5258:
        case 0x4b524d41:
        case 0x4b524d4d:
        case 0x4b524d58:
        case 0x4c444558:
        case 0x4c455458:
        case 0x4c4f5358:
        case 0x4c535058:
        case 0x4c545058:
        case 0x4d414e52:
        case 0x4d434358:
        case 0x4d434c58:
        case 0x4d494358:
        case 0x4d495458:
        case 0x4d4c4358:
        case 0x4d525058:
        case 0x4d545258:
        case 0x4e535058:
        case 0x4e574f58:
        case 0x4e5a4558:
        case 0x4f424d58:
        case 0x4f445258:
        case 0x4f4d4358:
        case 0x4f4f5258:
        case 0x4f544158:
        case 0x50424d58:
        case 0x50434f58:
        case 0x50444e58:
        case 0x504c4358:
        case 0x504c4858:
        case 0x50534558:
        case 0x50564e58:
        case 0x52424d58:
        case 0x52434158:
        case 0x52434458:
        case 0x524b4c58:
        case 0x524c4358:
        case 0x524d5258:
        case 0x52504158:
        case 0x52575058:
        case 0x53414358:
        case 0x53424958:
        case 0x53445258:
        case 0x53524858:
        case 0x54434158:
        case 0x54454358:
        case 0x544c4858:
        case 0x544c5758:
        case 0x544d4158:
        case 0x544d4358:
        case 0x544e4358:
        case 0x54574358:
        case 0x57544c58:
            reinterpret_cast<::loader::List *>((((::ExtraLoad *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->LoadExtraData((::loader::File *)(file), this);
            break;
        case 0x4c435358:
            file->ReadID(&scale);
            break;
        case 0x454d414e: {
            hasBaseTmp = true;
            file->ReadID(&baseIDA);
            ::ResolveFormID(&baseIDA, (::TESFile *)(file));
            TESForm* form3 = ::FUN_004839c0(baseIDA);
            TESBoundObject* bound5 = dynamic_cast<TESBoundObject*>(form3);
            bool replace = true;
            if (base && reinterpret_cast<::FUN_004121b0_shell *>((((SaveLoadState*)(*reinterpret_cast<::SaveLoadState * *>(&::g_BGSSaveLoadGame)))))->FUN_004121b0() &&
                reinterpret_cast<::BSShaderRenderUtility *>((((DataLoad*)(*reinterpret_cast<::DataLoad * *>(&::g_dataHandler)))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((base))->FUN_0084e3a0()))))
                replace = false;
            if (replace)
            {
                base = bound5;
                if (!base)
                {
                    ::FUN_005b5e40();
                    failed = true;
                    hasBaseTmp = false;
                }
            }
            break;
        }
        case 0x524c4352:
            break;
        case 0x4d414e4f:
            reinterpret_cast<::FUN_00572d50_shell *>(this)->FUN_00572d50(8);
            break;
        case 0x41544144:
            if (!failed)
            {
                TransformLoad transform;
                Reset3D(0);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&transform), 24);
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_00693dc0_class *>(&(transform))->SwapEndian();
                position = transform.position;
                rotation = transform.rotation;
            }
            break;
        default:
            ::FUN_005b5e40();
            chunkID = 0x41544144;
        }
        if (!reinterpret_cast<::TESFile *>((file))->NextChunk())
            break;
    }
    PatrolLoad* patrolTmp = ((::PatrolLoad *)(reinterpret_cast<::FUN_0041fe90_shell *>((((::ExtraLoad *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041fe90()));
    if (patrolTmp)
    {
        ScriptLoad* script = ((::ScriptLoad *)(reinterpret_cast<::LowProcess *>((patrolTmp))->GetCurrentPackageData()));
        if (script && !((::ScriptInfoLoad *)(reinterpret_cast<::BGSCameraPath *>((script))->GetConditions()))->unk08 && ((int)(reinterpret_cast<::BGSMessageInitAccess *>((script))->GetIconFormID())) && !((unsigned char)(reinterpret_cast<::FUN_0055b9a0_class *>((script))->GetByteAtOffset42())))
        {
            StringLoad warning;
            ::FUN_00406f60((::FUN_00406f90_this *)(::StringLoad *)(&warning), "Patrol point event script for point %s has text but has not been compiled.",
                       EditorID());
            ::FUN_005b5e40();
        }
    }
    return base != 0;
}
