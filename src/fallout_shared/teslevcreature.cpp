// fallout_shared/teslevcreature.cpp: Entry, TESLevCreature (7 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Owner487a60.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TmpEndian.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "teslevcreature_decls.h"
// @fnv 0x0050af60
bool TESLevCreature::Load(TESFile* file)
{
    unsigned char type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (type != 44)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
        {
        case 0x44494445: {
            char* uiGlobalId = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(uiGlobalId), 512);
            SetEditorID(uiGlobalId);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4f4c564c:
        case 0x44454f43:
            switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
            {
            case 0x4f4c564c: {
                LeveledObject leveledEntry;
                memset(&leveledEntry, 0, 12);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&leveledEntry), 12);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::TmpEndian *>(&(leveledEntry))->SwapEndian();
                DAT_011c8eec =
                    (LeveledEntry*)((::LeveledObject *)(reinterpret_cast<::Owner487a60 *>(this)->InsertEntryByPriority(leveledEntry.level, leveledEntry.count, (int)(leveledEntry.form), (int)(0))));
                break;
            }
            case 0x44454f43:
                if (DAT_011c8eec)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    DAT_011c8eec->extra = extra;
                    DAT_011c8eec = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&chance), 0);
            FUN_0042e680(chance);
            break;
        }
        case 0x464c564c:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&flags), 0);
            break;
        case 0x474c564c: {
            unsigned int uiGlobalId = 0;
            file->GetChunkData(&uiGlobalId);
            global = (TESForm*)uiGlobalId;
            break;
        }
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            struct
            {
                unsigned int size;
                void* data;
            } chunk;
            chunk.size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            chunk.data = _alloca(chunk.size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(chunk.data), chunk.size);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(chunk.data, chunk.size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570());
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

struct B1_4fe : public TESForm
{
    B1_4fe();
    ~B1_4fe();
};
struct FUN_00487650
{
    FUN_00487650();
    ~FUN_00487650();
    virtual void vf();
    int v[6];
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    virtual void vf2();
    int w;
};
struct FUN_0050adf0 : public B1_4fe, public FUN_00487650, public B2_4fe
{
    FUN_0050adf0();
    ~FUN_0050adf0();
};
// @fnv 0x0050adf0
FUN_0050adf0::FUN_0050adf0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x2c);
    reinterpret_cast<::TESForm *>(this)->ClearData();
    SetInitializationState(true);
}

struct FUN_0050aea0_shell : public FUN_0050adf0
{
    void FUN_0050aed0();
    void* FUN_0050aea0(unsigned int flags);
};

struct Date
{
    ~Date();
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_00488400_shell
{
    void SaveLeveledList();
};
struct DoorPart3c
{
};

struct FUN_0050a8e0_shell
{
    void FUN_0050a8e0();
};

// Calls M and the Date destructor on the object at offset 0, then SaveLeveledList at 0x30, ProcessAndFreeData at 0x4c, and M at offset 0.
// @fnv 0x0050a8e0
void FUN_0050a8e0_shell::FUN_0050a8e0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)((char*)this + 0x00))))->FUN_004855a0();
    reinterpret_cast<::TESForm *>((((Date*)((char*)this + 0x00))))->ClearData();
    ((FUN_00488400_shell*)((char*)this + 0x30))->SaveLeveledList();
    reinterpret_cast<::FUN_0048a520_shell *>((((DoorPart3c*)((char*)this + 0x4c))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::Holder *>((((FUN_00485680*)((char*)this + 0x00))))->FUN_00485680();
}

// Destructor of a form component with three polymorphic bases; the bases clean up in reverse order.

class AED0Primary
{
  public:
    virtual ~AED0Primary();
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
};

class AED0Model
{
  public:
    virtual ~AED0Model();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class AED0TextureSwap
{
  public:
    virtual ~AED0TextureSwap();
};

class FUN_0050aed0 : public AED0Primary, public AED0Model, public AED0TextureSwap
{
  public:
    virtual ~FUN_0050aed0();
};
// Calls FUN_0050aed0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0050aea0
void* FUN_0050aea0_shell::FUN_0050aea0(unsigned int flags)
{
    reinterpret_cast<::FUN_0050aed0 *>(this)->FUN_0050aed0::~FUN_0050aed0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for a class combining AED0Primary, AED0Model and AED0TextureSwap; it performs no work.
// @fnv 0x0050aed0
FUN_0050aed0::~FUN_0050aed0()
{}

namespace LevCreatureCopyImplementation {

struct Entry : public TESLevCreature
{
    void FUN_0050b2e0(TESForm*);
};

// Casts source to TESLevCreature and, if valid, calls FUN_004851b0 to copy data from it.
// @fnv 0x0050b2e0
void Entry::FUN_0050b2e0(TESForm* source)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(source);
    if (!creature)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(source);
}

}

namespace LevCreatureComparisonImplementation {

struct Entry : public TESLevCreature
{
    bool FUN_0050b320(TESForm*);
};

// Returns true if the other form is not a TESLevCreature or if FUN_00485270(creature) is true, otherwise false.
// @fnv 0x0050b320
bool Entry::FUN_0050b320(TESForm* other)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(other);
    if (!creature)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(creature))
        return true;
    return false;
}

}

#include "generated/data/fallout_shared/teslevcreature.inc"
