// bgscamerapathmanager.cpp: CameraPathManager (8 functions)

#include "fnv/decl/CameraPath.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_004d6170_shell.h"
#include "fnv/decl/FUN_004f00e0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0058ce30_Class.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00600000.h"
#include "fnv/symbols_011e0000.h"
#include "CameraPathManager.h"
void* __cdecl operator new(unsigned int);

// Constructs a NiTPrimitiveArray<BGSCameraPath*> by forwarding maxSize and growBy to the NiTArray base constructor.
// @fnv 0x0058bc30
template <>
NiTPrimitiveArray<BGSCameraPath*>::NiTPrimitiveArray(unsigned int maxSize, unsigned int growBy)
    : NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >(maxSize, growBy)
{}

// @fnv 0x0058b850
void CameraPathManager::InitializeCameraPaths()
{
    if (!ms_pDefaultCameraPath)
    {
        ms_pDefaultCameraPath = dynamic_cast<BGSCameraPath*>(::FUN_004839c0(0x16));
        if (!ms_pDefaultCameraPath)
        {
            ms_pDefaultCameraPath = new BGSCameraPath;
            ms_pDefaultCameraPath->SetRefID(0x16, true);
            ms_pDefaultCameraPath->SetEditorID_AtRuntime("DefaultCameraPath");
            m_kCameraPathArray.SetFormAtIndex(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(m_kCameraPathArray))->FUN_0084e3a0())), ms_pDefaultCameraPath);
        }
    }
}

// @fnv 0x0058b960
BGSCameraPath* CameraPathManager::GetTextureResourcePath()
{
    return ms_pDefaultCameraPath;
}

// @fnv 0x0058b970
void CameraPathManager::UpdateCameraPaths()
{
    unsigned int size = reinterpret_cast<::FUN_00658930_class *>(&(m_kCameraPathList))->GetShortAtOffsetA();
    for (unsigned int i = 0; i < size; ++i)
    {
        BGSCameraPath* path = m_kCameraPathList.GetAt(i);
        if (path && !reinterpret_cast<::TESForm *>((void *)(path))->GetInitialized())
        {
            path->InitItem();
            if (path->HasMissingPathArray())
            {
                BGSCameraPath* empty = 0;
                reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kCameraPathList))->SetAt(i, (char *&)(empty));
            }
        }
        else
        {
            BGSCameraPath* empty = 0;
            reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kCameraPathList))->SetAt(i, (char *&)(empty));
        }
    }
    ::CompactArray((::NiTArray_CombatGroup *)&(m_kCameraPathList));
}

struct NiFormArray_008b2010
{
};
struct TESFile
{
};
struct FUN_0058b510_shell
{
};
struct FUN_0058b470_shell
{
    bool IsFlag80Set();
};
bool _ref_008256d0(const char* s);
struct FUN_0058bb50_shell : NiFormArray
{
    TESFile* FUN_0058bb50(unsigned int arg1, unsigned int arg2);
};
// @fnv 0x0058bb50
TESFile* FUN_0058bb50_shell::FUN_0058bb50(unsigned int arg1, unsigned int arg2)
{
    TESFile* pFile = 0;
    if (arg1)
    {
        unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(this)))->FUN_0084e3a0()));
        for (unsigned int i = 0; i < count; ++i)
        {
            TESForm* form = reinterpret_cast<::FUN_004d6170_shell *>((reinterpret_cast<NiFormArray_008b2010*>(this)))->FUN_004d6170(i);
            if (form)
                pFile = ((::TESFile *)(reinterpret_cast<::CameraPath *>((reinterpret_cast<FUN_0058b510_shell*>(form)))->FUN_0058b510(arg1, arg2)));
            if (pFile)
                break;
        }
    }
    if (pFile)
    {
        if (reinterpret_cast<FUN_0058b470_shell*>(pFile)->IsFlag80Set())
        {
            if (!_ref_008256d0(((const char *)(reinterpret_cast<::BGSCameraPath *>((pFile))->GetShotList()))))
                pFile = 0;
        }
    }
    return pFile;
}

extern int DAT_01032748;
struct ActorCombatGroup;
template <> struct NiTMallocInterface<ActorCombatGroup*>
{
};
struct FUN_0058bc00_obj
{
    void* vtbl;
    ActorCombatGroup** data;
};
// Sets the object's vtbl to DAT_01032748 and deallocates its data array via NiTMallocInterface.
// @fnv 0x0058bc00
void FUN_0058bc00(FUN_0058bc00_obj* self)
{
    self->vtbl = &DAT_01032748;
    ::FUN_004ede70(self->data);
}

struct Arr
{
    unsigned int* GetAt(int index);
};

struct GlobalObject_00869b10
{
};

struct FUN_00863db0_class
{
    void ClearItems();
};

struct FUN_0058ba40_shell : public CameraPathManager
{
    void DestroyCameraPaths();
};

// @fnv 0x0058ba40
void FUN_0058ba40_shell::DestroyCameraPaths()
{
    unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(this)))->FUN_0084e3a0()));
    for (unsigned int index = 0; index < count; ++index)
    {
        BGSCameraPath* path =
            dynamic_cast<BGSCameraPath*>(reinterpret_cast<::FUN_004d6170_shell *>((reinterpret_cast<NiFormArray_008b2010*>(this)))->FUN_004d6170(index));
        delete path;
    }

    unsigned int childCount = reinterpret_cast<::FUN_00658930_class *>((reinterpret_cast<Arr*>(&this->m_kCameraPathList)))->GetShortAtOffsetA();
    for (unsigned int childIndex = 0; childIndex < childCount; ++childIndex)
    {
        BGSCameraPath* childPath = reinterpret_cast<BGSCameraPath*>(
            *reinterpret_cast<Arr*>(&this->m_kCameraPathList)->GetAt(childIndex));
        delete childPath;
    }

    ::FUN_005e03d0((::NiTArray_Layout *)(reinterpret_cast<GlobalObject_00869b10*>(&this->m_kCameraPathList)));
    CameraPathManager::ms_pDefaultCameraPath = 0;
    reinterpret_cast<FUN_00863db0_class*>(this)->ClearItems();
}

struct SceneNode
{
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual int IsRootCandidate();
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
    SceneNode(unsigned short childCount);
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int size);
};


template <class T> struct NodePtr
{
    T* m_pObject;
    NodePtr<T>& operator=(T* object);
    operator T*() const;
};


struct FUN_0058ccf0_Class
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    NodePtr<SceneNode> node64;
    int unk68;
    int unk6C;
    NodePtr<SceneNode> node70;
    void SetSceneNode(SceneNode* node);
};

// @fnv 0x0058ccf0
void FUN_0058ccf0_Class::SetSceneNode(SceneNode* node)
{
    if (node == 0)
    {
        node64 = 0;
        node70 = 0;
        return;
    }
    if (reinterpret_cast<::FUN_0058ce30_Class *>((void *)this)->IsFlag2Set())
    {
        node64 = node;
    }
    else
    {
        node64 = new SceneNode(0);
        reinterpret_cast<::FUN_004f00e0_shell *>((((SceneNode*)node64)))->FUN_004f00e0(((void *)(::FUN_0045bb80((int)(node)))));
    }
    SceneNode* root = node;
    while (root != 0 && root->IsRootCandidate() == 0)
    {
        root = ((::SceneNode *)(reinterpret_cast<::FUN_009611e0_shell *>((root))->FUN_009611e0()));
    }
    if (root != 0)
    {
        node70 = root;
    }
    else
    {
        node70 = node;
    }
    DAT_011e07c3 = true;
}
