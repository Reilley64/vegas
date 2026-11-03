// fallout_shared/bgsdebris.cpp: BGSDebris, MagicItemForm, BGSDebris_shell2, BGSDebris_cmp (19 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/C4442C0Queue.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00488fd0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00489940__FUN_00489940_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fa000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00689000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_011c3000.h"
#include "bgsdebris_decls.h"

// @fnv 0x00409140
BSSimpleList<DebrisModelEntry*>* BGSDebris::GetDataList()
{
    return &DataList;
}

// Reads a BGSDebris record from a TESFile, handling EDID, OBND, DATA and MODL chunks, and returns false if the form type is not 0x52.
// @fnv 0x004f9f10
bool BGSDebris::Load(TESFile* file)
{
    // Local identifiers preserve MSVC9 stack-slot ordering.
    unsigned char v0 = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (v0 != 0x52)
        return false;
    ClearData();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    DebrisModelEntry* v1 = 0;  // most recently loaded debris entry
    while (int v2 = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (v2)
        {
        case 0x44494445: {
            char* v3 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(v3), 512);
            SetEditorID_AtRuntime(v3);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144: {
            // v5: chunk size; v6: allocation; v4: parse cursor; v7: end.
            unsigned int v5 = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            unsigned char* v6 = new unsigned char[v5];
            unsigned char* v4 = v6;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(v4), v5);
            unsigned char* v7 = v4 + v5;
            if (v4 < v7)
            {
                // v10: chance; v9: model path; v8: flags.
                unsigned char v10 = *v4;
                v4++;
                const char* v9 = (const char*)v4;
                v4 += ::FUN_0044a670((const char*)v4) + 1;
                unsigned char v8 = 0;
                if (v4 < v7)
                {
                    v8 = *v4;
                    v4++;
                }
                v1 = AddDebrisModel(v10, v9, v8);
            }
            delete[] v6;
            break;
        }
        case 0x54444f4d:
            if (v1)
                reinterpret_cast<::fnv_00489940::FUN_00489940_shell *>(&(v1->model))->LoadChunkData((::fnv_00489940::TESFile *)(file), (::fnv_00489940::TESForm *)(::TESForm *)(this), (char *)(v1->path));
            else
            {
                ::FUN_005b5e40();
                FileEntryList v11;
                reinterpret_cast<::fnv_00489940::FUN_00489940_shell *>(&(v11))->LoadChunkData((::fnv_00489940::TESFile *)(file), (::fnv_00489940::TESForm *)(::TESForm *)(this), (char *)(DAT_01015890));
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

#include "bgsdebris_magic.h"
// Constructs a MagicItemForm object; the body is empty.
// @fnv 0x00409190
MagicItemForm::MagicItemForm()
{}

extern int DAT_01024970;

struct FUN_004f9d90_helper
{
    void* vftable;
    FUN_004f9d90_helper* ctor();
};

// @fnv 0x004f9d90
FUN_004f9d90_helper* FUN_004f9d90_helper::ctor()
{
    ::FUN_00402d30((int *)(reinterpret_cast<BaseFormComponent*>(this)));
    this->vftable = &DAT_01024970;
    return this;
}


struct S_004fa4b0
{
    char c;
    const char* s;
};

// Compares two entries by their char field, returning -1 or 1, and otherwise compares their string fields via FUN_00408b20.
// @fnv 0x004fa4b0
int __cdecl FUN_004fa4b0(const S_004fa4b0* apLeft, const S_004fa4b0* apRight)
{
    if (apLeft->c > apRight->c)
    {
        return -1;
    }
    else if (apLeft->c < apRight->c)
    {
        return 1;
    }
    else
    {
        return FUN_00408b20(apLeft->s, apRight->s);
    }
}

// Initializes the object: sets byte 0 to 10, byte 1 to 0, int at offset 4 to 0, constructs the object at offset 8, and returns pThis.
// @fnv 0x004fa5e0
void* FUN_004fa5e0(char* pObject)
{
    pObject[0] = 10;
    pObject[1] = 0;
    *reinterpret_cast<int*>(pObject + 4) = 0;
    reinterpret_cast<::FUN_00488fd0_shell *>((reinterpret_cast<FileEntryList*>(pObject + 8)))->FUN_00488fd0();
    return pObject;
}

struct DebrisData
{
    char c;
    char pad[3];
    const char* p;
};
struct DArg
{
    DebrisData* d;
};
struct AEList
{
};
unsigned int __cdecl BSStringLength(const char*);
// Checks that a.d, its flag, and its string are non-empty, then inserts a.d into the AEList at self+0x1c and returns true; otherwise returns false.
// @fnv 0x004fa610
bool InsertDebrisIfValid(char* self, DArg aDebrisArg)
{
    if (!aDebrisArg.d || !aDebrisArg.d->c || !aDebrisArg.d->p || !::FUN_0044a670(aDebrisArg.d->p))
        return false;
    reinterpret_cast<::FUN_00470440 *>((((AEList*)(self + 0x1c))))->FUN_007a7eb0((::BGSPerkEntry *)(aDebrisArg.d), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(((int (&)(DebrisData *, DebrisData *))::FUN_004fa4b0)));
    return true;
}

struct FUN_004fa670_shell : public DebrisModelEntry
{
    void FUN_004fa670(char*);
};
// @fnv 0x004fa500
DebrisModelEntry* BGSDebris::AddDebrisModel(char chance, const char* path, char flags)
{
    if (!path || !chance)
        return 0;
    unsigned int length = ::FUN_0044a670(path);
    if (length)
    {
        DebrisModelEntry* data = new DebrisModelEntry;
        data->chance = chance;
        reinterpret_cast<::FUN_004fa670_shell *>((data))->FUN_004fa670((char *)(path));
        data->flags = flags;
        ::InsertDebrisIfValid((char *)this, ::DArg{(DebrisData *)data});
        return data;
    }
    return 0;
}

template <class T> unsigned int __cdecl BSStringLength(T const*);

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};

// @fnv 0x004fa670
void FUN_004fa670_shell::FUN_004fa670(char* apFileName)
{
    if (this->path)
    {
        delete this->path;
    }
    this->path = 0;
    if (apFileName)
    {
        int iFilenameLen = ::FUN_0044a670(apFileName) + 1;
        this->path = new char[iFilenameLen];
        TaskQueueInterface::CopyStringToBuffer(this->path, iFilenameLen, apFileName);
    }
}

struct SL
{
    SL();
    ~SL();
};
class FUN_004f9cd0 : public TESForm, public BGSPreloadable
{
  public:
    SL DataList;
    FUN_004f9cd0();
    virtual ~FUN_004f9cd0();
};
// Sets the form type to 0x52 and clears the form data.
// @fnv 0x004f9cd0
FUN_004f9cd0::FUN_004f9cd0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x52))));
    TESForm::ClearData();
}

struct FUN_004fa950_shell
{
    int IsFlagSet();
};

// @fnv 0x004fa950
int FUN_004fa950_shell::IsFlagSet()
{
    return (*reinterpret_cast<signed char*>(this + 1) & 1);
}

struct S_004f9d60
{
    void FUN_004f9db0();
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_005e78f0_t
{
};

struct BGSDebris_shell : BGSDebris
{
    void CopyFromDebris(TESForm* source);
};

struct Vec3
{
    float x, y, z;
    Vec3();
};
// Iterates DataList, deallocating each entry's path and deleting the entry, then removes the head until the list is empty.
// @fnv 0x004f9e30
void BGSDebris::ClearData()
{
    BSSimpleList<DebrisModelEntry*>* list = &DataList;
    while (!DataList.IsEmpty())
    {
        DebrisModelEntry* data = (list->m_item);
        if (data)
        {
            char* path = data->path;
            ::FUN_00401030(path);
            delete data;
        }
        DataList.RemoveHead();
    }
}
// Iterates the debris data list and asks g_modelLoader to load each entry's non-empty path into its model with the given priority and file.
// @fnv 0x004fa970
void BGSDebris::Preload(int priority, void* file)
{
    BSSimpleList<DebrisModelEntry*>* list = GetDataList();
    while (list)
    {
        DebrisModelEntry* data = (list->m_item);
        if (data && data->path && ::FUN_0044a670(data->path))
            reinterpret_cast<::C4442C0Queue *>((g_modelLoader))->QueueFullWithNullResult((std::intptr_t)(data->path), (std::intptr_t)(&data->model), priority, (std::intptr_t)(file), 1, 1, 0, 0);
        list = ((::BSSimpleList< ::DebrisModelEntry *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
}
// @fnv 0x004fa2f0
void BGSDebris_shell::CopyFromDebris(TESForm* source)
{
    BGSDebris* debris2 = dynamic_cast<BGSDebris*>(source);
    if (!debris2)
        return;
    ClearData();
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(debris2);
    BSSimpleList<DebrisModelEntry*>* list = debris2->GetDataList();
    while (list)
    {
        DebrisModelEntry* data = (list->m_item);
        if (data)
            AddDebrisModel(data->chance, data->path, data->flags);
        list = ((::BSSimpleList< ::DebrisModelEntry *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
}
struct DNode
{
};
struct DItem
{
    char chance;
    char pad[3];
    void* model;
};
struct DList
{
};
void* __cdecl FUN_00aa13e0(unsigned int);
struct DebrisObj
{
    char b[0x24];
    DebrisObj(void* a1, float f, void* m, int z, Vec3* pos, Vec3* v1, Vec3* v2, Vec3* v3, float s, int z1, int z2);
};

struct DNode2
{
};
struct BGSDebris_shell2 : BGSDebris
{
    void FUN_004fa6f0(void* a1, Vec3* pos, unsigned int count, float scale);
};

// @fnv 0x004fa6f0
void BGSDebris_shell2::FUN_004fa6f0(void* a1, Vec3* apPosition, unsigned int count, float scale)
{
    if (!a1)
        return;
    unsigned int i8 = 0;
    DNode* node_ = ((::DNode *)(reinterpret_cast<::BGSDebris *>((((DList*)this)))->GetDataList()));
    while (node_)
    {
        DItem* d9 = (DItem*)*((void **)((void *)(node_)));
        if (d9 && d9->model && d9->chance)
        {
            unsigned int n = d9->chance * count / 100;
            if (n == 0 && i8 < count)
                n = 1;
            for (unsigned int j3 = 0; j3 < n; j3++)
            {
                Vec3 v4;
                v4.x = ::RandomFloat(DAT_01012054, 1.0f);
                v4.y = ::RandomFloat(DAT_01012054, 1.0f);
                v4.z = ::RandomFloat(DAT_01012054, 1.0f);
                reinterpret_cast<::FUN_004a0c10_s *>(&(v4))->FUN_004a0c10();
                if (((unsigned char)(reinterpret_cast<::FUN_004fa950_shell *>((d9))->IsFlagSet())))
                {
                    Vec3 dir = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
                    DebrisObj* o3 =
                        new DebrisObj(a1, ::DAT_010249d8, d9->model, 0, apPosition, &v4, &dir, &dir, scale, 0, 0);
                    (void)o3;
                }
                else
                {
                    ::FUN_006890b0((::World *)(a1), ::DAT_01017b78, (std::intptr_t)(d9->model), v4, *apPosition, (float)(scale * DAT_01020758), 7, 0);
                }
                i8++;
            }
        }
        node_ = ((::DNode *)(reinterpret_cast<::Callees *>((node_))->FUN_00726070()));
    }
}

struct DebrisModel4fa
{
};

struct DebrisEntry4fa
{
    char cChance;
    char cFlags;
    short sPad;
    char* pcPath;
    DebrisModel4fa kModel;
};


struct FUN_004fa1a0_shell
{
    void WriteDebrisEntries();
};

// @fnv 0x004fa1a0
void FUN_004fa1a0_shell::WriteDebrisEntries()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    DNode* pkNode = ((::DNode *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList()));
    while (pkNode)
    {
        DebrisEntry4fa* pkData = (DebrisEntry4fa*)*((void **)((void *)(pkNode)));
        if (pkData && pkData->pcPath && ::FUN_0044a670(pkData->pcPath))
        {
            unsigned int uiSize = ::FUN_0044a670(pkData->pcPath) + 3;
            char* pTmpcBuffer = new char[uiSize];
            char* pcCur = pTmpcBuffer;
            *pcCur = pkData->cChance;
            pcCur++;
            ::TaskQueueInterface::CopyStringToBuffer(pcCur, uiSize, pkData->pcPath);
            pcCur += ::FUN_0044a670(pkData->pcPath) + 1;
            *pcCur = pkData->cFlags;
            pcCur++;
            ::FUN_004856f0((void *)('ATAD'), pTmpcBuffer, (void *)(uiSize));
            delete pTmpcBuffer;
            reinterpret_cast<::FUN_008d0600_s *>(&(pkData->kModel))->FUN_008d0600('TDOM', (std::intptr_t)pkData->pcPath);
        }
        pkNode = ((::DNode *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}


struct DebrisListNode
{
    int GetCount();
};

struct BGSDebris_cmp : BGSDebris
{
    bool FUN_004fa390(TESForm* form);
};

// Compares this debris list against another BGSDebris's list, returning true if counts, entries, chance, path or flags differ.
// @fnv 0x004fa390
bool BGSDebris_cmp::FUN_004fa390(TESForm* form)
{
    BGSDebris_cmp* other7 = (BGSDebris_cmp*)dynamic_cast<BGSDebris*>(form);
    if (!other7)
        return true;
    DebrisListNode* otherIter2 = ((::DebrisListNode *)(reinterpret_cast<::BGSDebris *>((other7))->GetDataList()));
    if (otherIter2->GetCount() != ((DebrisListNode*)&DataList)->GetCount())
        return true;
    DebrisListNode* iter = (DebrisListNode*)&DataList;
    while (otherIter2)
    {
        DebrisModelEntry* srcData = *((::DebrisModelEntry **)((void *)(otherIter2)));
        DebrisModelEntry* dstData = *((::DebrisModelEntry **)((void *)(iter)));
        if ((!srcData && dstData) || (srcData && !dstData))
            return true;
        if (srcData && dstData)
        {
            if (srcData->chance != dstData->chance)
                return true;
            if (FUN_00408b20(srcData->path, dstData->path))
                return true;
            if (srcData->flags != dstData->flags)
                return true;
        }
        iter = ((::DebrisListNode *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        otherIter2 = ((::DebrisListNode *)(reinterpret_cast<::Callees *>((otherIter2))->FUN_00726070()));
    }
    return false;
}

struct FUN_004f9db0_Base : public TESForm
{
    virtual ~FUN_004f9db0_Base();
};

struct FUN_004f9db0 : public FUN_004f9db0_Base, public BGSPreloadable
{
    BSSimpleList<DebrisModelEntry*> DataList;
    virtual void ClearData();
    ~FUN_004f9db0();
};
// Calls FUN_004f9db0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004f9d60
void* S_004f9d60::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004f9db0 *>(this)->FUN_004f9db0::~FUN_004f9db0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004f9db0
FUN_004f9db0::~FUN_004f9db0()
{
    ClearData();
}
